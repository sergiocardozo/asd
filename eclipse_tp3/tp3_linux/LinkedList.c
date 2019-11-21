/*
 * LinkedList.c
 *
 *  Created on: 18 nov. 2019
 *      Author: sergio
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

//lista enlazada, estructuras anidadas enlzadas simples
//pelement puntero a la estructura
//un nodo es un elemento nodo
static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;// puntero a la linkedlist

    this = (LinkedList*)malloc(sizeof(LinkedList));//asigno espacio en la memoria utilizando malloc

    if(this != NULL)//verifico si es distinto de null para indicar si se asigno espacio en la memoria
    {
    	this->size = 0; // inicializo el tamaño de la lista en 0
    	this->pFirstNode = NULL; //inicializo el primer nodo vacio
    }

    return this;//devuelve la LinkedList con el size inicializado 0 y el primer nodo en NULL
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	int returnAux = -1;

    if(this != NULL)//verifico que la lista no este vacia
    {
    	returnAux = this->size; //le asigno al retorno la cantidad de elementos de la lista
    }
    return returnAux;//retorna -1 si el puntero a la lista es NULL
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i;
	Node* pNode = NULL; //variable de retorno inicializado en null o vacio

	if(this != NULL)//verifico que la lista tenga elementos
	{
		if(nodeIndex >= 0 && nodeIndex < this->size)//verifico si el indice es mayor o igual a 0 y si el indice es menor al largo de la lista
		{
			pNode = this->pFirstNode; // le asigno al nodo el primer nodo
									//en caso de que el nodo sea 0 retorna el primer nodo
			for(i = 0; i< nodeIndex; i++)//recorre hasta que encuentra el indice buscado
			{
				pNode = pNode->pNextNode;//a pNode le asigno la direccion del proximo nodo o entidad
			}
		}
	}
	return pNode; //
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode = malloc(sizeof(Node));//creo espacio en memoria para un nuevo nodo
    Node* pActualNode = NULL; //inicializo el nodo actual en NULL o vacio

    newNode->pElement = pElement; //al nuevo nodo le asigno los campos
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	if(nodeIndex == 0) //verifico el primer nodo de la lista si es el primero
    	{
    		newNode->pNextNode = this->pFirstNode;//
    		this->pFirstNode = newNode;//agrega el primer nodo
    		this->size ++;//agranda la lista en 1
    		returnAux = 0;
    	}
    	else
    	{
    		pActualNode = getNode(this,nodeIndex - 1); //obtengo el nodo anterior y se lo asigna al nodo actual
    		newNode->pNextNode = pActualNode->pNextNode; //la direccion del siguiente nodo es el nodo actual
    		pActualNode->pNextNode = newNode; //guarda el nuevo nodo
    		this->size++;//y aumenta el tamaño de la lista en 1
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)//verifico que la lista no este vacia
    {
    	returnAux = addNode(this,this->size,pElement); //retorno el nodo con el elemento a ser agregado a la lista
    }
    return returnAux;//retorna -1 si el puntero a la lista es NULL
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;

    if(this != NULL)//verifico que la lista no este vacia
    {
    	if(index >= 0 && index < ll_len(this))//verifico que la posicion sea mayor o igual a 0 y menor al largo de la lista
    	{
    		pNode = getNode(this,index);//le asigno un nodo de la lista
    		returnAux = pNode->pElement; //retorna el elemento al que apunta el nodo
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode;

    if(this != NULL && index >= 0 && index < ll_len(this))//
    {
    	pNewNode = getNode(this,index); //a pNewnodo le asigno un nodo de la lista pasandole por parametro la lista y la ubicacion
    	if(pNewNode != NULL)//verifico si ese nodo es distinto de null
    	{
    		pNewNode->pElement = pElement;//al elemento al que apunta ese nodo le asigno el nuevo elemento
    		returnAux = 0;//retorno correcto
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index)
{
    int returnAux = -1; //Variable de retorno
    Node* pNodeA = NULL;
    Node* pNodeB = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this) > 0)//verifico que la lista sea distinta de null, que el indice se mayor o igual a 0
    {														//que el indice sea menor al largo de la lista y la lista sea mayor a 0
        if(index !=0 && index != (ll_len(this)))//si el indice es distinto de 0 y distinto al largo de la lista
        {
            pNodeB = getNode(this, (index-1));//guardo el nodo anterior en el puntero al nodoB
            pNodeA = getNode(this, index);//guardo en el nodo A la ubicacion del nodo que quiero borrar
            pNodeB -> pNextNode = pNodeA -> pNextNode;//guardo la direccion del siguiente nodo que tenia en el nodo que queria borrar 
            free(pNodeA);//libero espacio de la memoria del nodo borrado
        }
        else
        {
            if (index == 0)//si el indice es igual a 0
            {
                pNodeA = getNode(this, index); //guardo en el nodoA la ubicacion del nodo que quiero borrar
                this -> pFirstNode = pNodeA -> pNextNode;//le asigno al primer nodo de la lista el nodo siguiente 
                free(pNodeA);//libero espacio de la memoria del nodo borrado
            }
            else
            {
                if (index!=0 && index == (ll_len(this)))//si la ubicacion es distinta de 0 y la ubicacion es igual al largo de la lista 
                {
                    free(pNodeA);//libero espacio de la memoria 
                }
            }
        }
        this->size--; //decremento el largo de la lista en 1 
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len;

    len = ll_len(this); // le asignno a len el largo de la lista

    if(this != NULL)//verifico si la lista tiene elementos
    {
    	for(i=len;i>=0;i++) //recorro el largo de la lista
    	{
    		ll_remove(this, i-1);// elimino todos los elementos de la lista, le paso como parametro la lista y la ubicacion menos 1
    	}
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)//verifico si la lista tiene elementos
    {
    	ll_clear(this);//elimino todos los elementos de la lista
    	free(this);//libero espacio de la memoria eliminando la lista
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1; 
    Node* pNode = NULL; //inicializo el puntero al campo nodo en null o vacio
    int i; // variable de control
    int len; 

    len = ll_len(this); // le asigno a la variable len el largo de la lista
    if(this != NULL)//verifico si la lista esta vacia
    {
    	for(i=0;i<len;i++)//recorro el largo del la lista
    	{
    		pNode = getNode(this,i);// le asigno al nodo el lugar que ocupa en la lista
    		if(pNode->pElement == pElement)//verifico si el elemento al que apunta el nodo es igual al elemento pasado como parametro
    		{
    			returnAux = i;//retorna la posicion en la lista
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL )//verifico si la lista contiene elementos
    {
    	if(ll_len(this) > 0)//verifico si el largo de la lista es mayor a 0
    	{
    		returnAux = 0;//retorno 0 si la lista NO esta vacia
    	}
    	else // si no
    	{
    		returnAux = 1; //retorno 1 si la lista esta vacia
    	}
    }
    return returnAux; // retorna menos 1 si el puntero a la lista es null o vacio
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))//verifico que la lista contenga elementos, si el indice es mayor o igual a 0
    {														// y que la ubicacion sea menor o igual al largo de la lista
    	returnAux = addNode(this,index,pElement);//retorna el nuevo nodo en la lista con sus campos y la ubicacion en la que se va a encontrar
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;//retorno inicializado en NULL
    if(this != NULL && index >= 0 && index <= ll_len(this))//verifica que la lista contenga elementos y que la ubicacion sea mayor o igual a 0
    {													//y que la ubicacion se encuentre en el largo de la lista
    	returnAux = ll_get(this,index); //le asigno al retorno la ubicacion de un nodo en la lista
    	if(returnAux != NULL)//verifico que el valor que retorna tenga elementos que no este vacia
    	{
    		ll_remove(this,index); //si tiene elementos elimina la ubicacion del campo en la lista
    	}
    }
    return returnAux;//retorna error si el puntero a la lista es igual a NULL
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;//inicializo el puntero al campo nodo en NULL o vacio
    int i;//variable de control

    if(this != NULL)//verifico que la lista contenga elementos
    {
    	returnAux = 0;//retorno 0 si no contiene elementos
    	for(i=0;i<ll_len(this);i++)//recorro el largo de la lista para buscar una posicion
    	{
    		pNode = getNode(this,i);//le asigno al puntero al campo la ubicacion del nodo en la lista
    		if(pNode->pElement == pElement)//verifico que el puntero al campo nodo apunte al mismo nodo que el que se paso por parametro
    		{
    			returnAux = 1;//retorno 1 si la lista contiene el elemento
    			break;//salgo del for rompiendolo cuando encuentre la condicion que busca
    		}
    	}
    }
    return returnAux;//retorna -1 el puntero a la lista es NULL
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;//variable de control
    void* pElement; //puntero a pElement 

    if(this != NULL && this2 != NULL)//verifico si tanto la lista 1 como la lista 2 contienen elementos
    {
    	returnAux = 1;//retorno 1 si los elementos de la lista2 estan contenidos en la lista 1
    	for(i=0;i<ll_len(this2);i++)//recorro el largo de la lista 2
    	{
    		pElement = ll_get(this2,i); //le asigno al elemento la ubicacion de un elemento en la lista dos
    		if(!ll_contains(this,pElement))//si la lista 1 no contiene elementos
    		{
    			returnAux = 0;//los elementos de la lista dos no estan contenidos en la lista uno
    		}
    	}
    }
    return returnAux;//retorno -1 si el puntero a la lista es igual a NULL o vacia
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL; // puntero a la linkedlist inicializado en NULL o vacio
    void* pElement; 
    int i;

    if(this != NULL && from >= 0 && to <= this->size)//verifico que la lista no este vacia, que el indice desde el cual se copian los elementos
    {											//sea mayor o igual a 0 y que el indice hasta el cual se copian los elementos en la nueva lista
    											//sea menor o igual al largo al que apunta la lista	
    	cloneArray = ll_newLinkedList();//le asigno a cloneArray una nueva linkedList en memoria de manera dinamica
    	for(i=from;i<to;i++)//recorre la nueva lista desde y hasta la ubicacion indicada
    	{
    		pElement = ll_get(this,i); // le asigno a pElement la ubicacion de los elementos en la lista
    		ll_add(cloneArray,pElement);//y agrego a la nueva lista los elementos indicados 
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;//puntero a la nueva lista

    if(this != NULL)//verifico que la lista no este vacia
    {
    	cloneArray = ll_subList(this,0,ll_len(this));//le asigno a la nueva lista los elementos guardados 
    }												//desde 0 hasta el largo de la lista
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux =-1;

	void* pElement1;
    void* pElement2;
    void* pElementAux;
    int i;
    int flagSwap;
    int len;

    if(this != NULL && ll_len(this) > 0 && pFunc != NULL && (order ==0 || order == 1))//verifico la lista distinta de null,que el len sea mayor a 0
    {														//si la funcion criterio es distinto de null y si el orden es 0(desc) o 1(asc)
    	len = ll_len(this);//le asigno a len el largo de la lista
    	if(len > 0)//verifico si la lista es mayor a 0
    	{
    		do//metodo de burbujeo para el swap
    		{
    			flagSwap = 0;//inicializo la bandera en 0
    			for(i=0;i<len-1;i++)//recorro las ubicacion de la lista
    			{
    				pElement1 = ll_get(this,i); // le asigno al primer elemento la ubicacion que ocupa en la lista
    				pElement2 = ll_get(this,i+1);//le asigno al segundo elemento la ubicacion de un nodo incrementadolo en 1

    				if((pFunc(pElement1,pElement2) < 0 && order == 0) ||//verifico que los parametros que le paso a la funcion criterio es verdadero y si el tipo de orden es 0(descendente)
    					(pFunc(pElement1,pElement2) > 0 && order == 1))//verifico que los parametros que le paso a la funcion criterio es verdadero y si el tipo de orden es 0(ascendente)
    				{
    					pElementAux = pElement1;//swap
    					ll_set(this,i,pElement2);
    					ll_set(this,i+1,pElementAux);
    					flagSwap = 1;//pongo la bandera en 1 cuando este todo ordenado
    				}
    				returnAux = 0; // si hay elementos para seguir ordenando
    			}
    		}while(flagSwap);//deja de swapear cuando la bandera este en 0 osea que no hay elementos por ordenar
    	}
    }
    return returnAux;
}

/** \brief Mapea los elementos de la lista utilizando la funcion recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux =-1;
	int i; //variable control
	if(this!=NULL && pFunc!=NULL) //si la lista contiene elementos y si la funcion criterio no es ta vacia
	{
		returnAux = 0;
		for(i=0; i<this->size; i++)//recorro el largo al que apunta la lista
		{
			pFunc(ll_get(this,i));//funcion criterio que devuelve la posicion que tiene un nodo en la lista
		}
	}
    return returnAux;

}

/** \brief Crea y retorna una nueva lista con los elementos indicados por el filtro
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* cloneArray = NULL;
    int i;
    Node* pNode;
    if(this!=NULL && pFunc!=NULL)
    {
    	cloneArray = ll_newLinkedList();
    	pNode = this->pFirstNode;
		for(i=0;i<this->size;i++)
		{
			if(pFunc(pNode->pElement))
			{
				ll_add(cloneArray,pNode->pElement);
			}
			//if(pNode!=NULL)
				pNode = pNode->pNextNode;
		}
    }

    return cloneArray;
}


/** \brief Retorna la lista con los elementos indicados por el filtro
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
int ll_reduce(LinkedList* this, int (*pFunc)(void*))
{
	int retorno = -1;
	int i;
    if(this!=NULL && pFunc!=NULL)
    {
    	retorno = 0;
		for(i=this->size-1;i>=0;i--)
		{
			if(!pFunc(ll_get(this, i)))
			{
				ll_remove(this,i);
			}
		}
    }

    return retorno;
}

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

    printf("/****************************************************\
\nMenu:\
\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\
\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\
\n\n3. Alta de empleado\
\n4. Modificar datos de empleado\
\n5. Baja de empleado\
\n6. Listar empleados\
\n7. Ordenar empleados\
\n\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\
\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\
\n\n10. Salir\
\n*****************************************************/");
     utn_getUnsignedInt("\nSeleccione opcion: ","Opcion invalida",1,sizeof(int),1,10,3,&option);
        switch(option)
        {
            case 1:
            	printf("\nCargando lista %d\n",controller_loadFromText("data.csv",listaEmpleados));
                break;
            case 2:
            	printf("\nCargando lista binaria %d\n",controller_loadFromBinary("data.bin", listaEmpleados));
            	break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                printf("%d elementos guardados\n",controller_saveAsText("datasave.csv",listaEmpleados));
                break;
            case 9:
                printf("%d elementos guardados\n",controller_saveAsBinary("datasave.bin",listaEmpleados));
                break;
            case 10:
            	printf("\nSaliendo del programa");
            	break;
            default:
            	printf("\nOpcion invalida ingrece una opcion del 1 al 10 ");
        }
    }while(option != 10);
    return 0;
}

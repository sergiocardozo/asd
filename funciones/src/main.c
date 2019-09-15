/*
 * main.c
 *
 *  Created on: 14 sep. 2019
 *      Author: Vivis
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define QTY_EMPLEADOS 1000

void inicializarArrayInt(int array[], int cantidad, int valor);
int buscarPrimerOcurrencia(int array[], int cantidad, int valor);

int main(){
	int id[QTY_EMPLEADOS];
	char name[QTY_EMPLEADOS][51];
	char lastName[QTY_EMPLEADOS][51];
	float salary[QTY_EMPLEADOS];
	int sector[QTY_EMPLEADOS];
	int idEmpty[QTY_EMPLEADOS];
	int opcion = 0;

	int indiceEmpty;

	inicializarArrayInt(id,QTY_EMPLEADOS,-1);
	do
	{
		opcion = getInt("\n\n\n1 - ALTAS.\n2 - MODIFICAR.\n3 - BAJAS. \n4 INFORMES. \n5 - SALIR.");

		switch(opcion)
		{
		case 1:
			indiceEmpty = buscarPrimerOcurrencia(id,QTY_EMPLEADOS,-1);
			if(indiceEmpty == -1)
			{
				printf("\n No hay lugares libres.\n");
				break;
			}
		}
	}while(opcion!=5);

	return 0;
}

void inicializarArrayInt(int array[], int cantidad, int valor)
{
	int i;
	for(i=0;i<cantidad;i++){
		array[i] = valor;
	}
}

int buscarPrimerOcurrencia(int array[], int cantidad, int valor)
{
	int i;
	for(i=0;i<cantidad;i++)
	{
		if(array[i] == valor)
		{
			return i;
		}
	}
return -1;
}

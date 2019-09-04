/*
 ============================================================================
 Name        : Trabajopractico1.c
 Author      : Cardozo Sergio
 Version     :
 Copyright   : GLP
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define FUNCIONES_H_
int main()
{
float numero1;
float numero2;
int opciones;
float suma;
float resta;
float division;
float multiplicacion;
int factorialA;
int factorialB;

	do {
		printf("\n");
		printf("		MENU DE OPCIONES\n"		);
		printf("\n");
		printf("1- Ingrese el 1er operando: \n");
		printf("2- Ingrese el 2do operando: \n");
		printf("3- Calcular todas las operaciones \n");
		printf("4- Informe de los resultados: \n");
		printf("5- Salir. \n");
		printf("\n");
		printf("Primer numero ingresado: %.2f\n", numero1);
		printf("Segundo numero ingresado: %.2f\n", numero2);
		printf("\n");
		printf("Elija una opcion: \n");
		scanf("%d",&opciones);
			switch (opciones) {
			case 1:
			numero1 = getNumber("Ingresar primer operando: ");
			break;
			case 2:
			numero2 = getNumber("Ingresar segundo operando: ");
			break;
			case 3:
			suma = getSum(numero1,numero2);
			resta = getSubtraction(numero1,numero2);
			multiplicacion = getMultiply(numero1,numero2);
			division = getDivide(numero1,numero2);
			factorialA = getFactorial(numero1);
			factorialB = getFactorial(numero2);
			printf("\n Se resolvieron todas las operaciones.\n");
			break;
			case 4:
			printf("El resultado de A+B es: %.2f",suma);
			printf("\nEl resultado de A-B es: %.2f",resta);
				if(numero2==0)
				{
				printf("\nNo se puede dividir por 0");
				}
				else
				{
				printf("\nEl resultado de A/B es: %.2f",division);
				}
				printf("\nEl resultado de A*B es: %.2f",multiplicacion);
				if(numero1<0)
				{
				printf("\nNo se puede sacar el factorial de un numero negativo.\n");
				}
				else{
				printf("\nEl numero !A es: %d",factorialA);
				}
				if(numero2<0){
				printf("\nNo se puede sacar el factorial de un numero negativo.\n");
				}
				else
				{
				printf("\nEl numero !B es: %d\n",factorialB);
				}
			break;
			case 5:
			printf("Saliendo de la calculadora.");
			break;
			default:
			printf("\nLa opcion ingresada no es correcta.\n");
			break;
			}
	}
	while (opciones != 5);
return 0;

}

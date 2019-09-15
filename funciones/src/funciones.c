/*
 ============================================================================
 Name        : funciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getInt(char mensaje[]){
	int auxiliar;
	printf("%s",mensaje);
	scanf("%d" ,&auxiliar);

return auxiliar;
}

float getFloat(char mensaje[]){
	float auxiliar;
	printf("%s",mensaje);
	scanf("%f" ,&auxiliar);

return auxiliar;
}

char getChar(char mensaje[]){
	char auxiliar;
	printf("%s",mensaje);
	fflush(stdin); // standar input
	scanf("%c" ,&auxiliar);
	return auxiliar;
}

int esNumerica(char str[]){
	int i=0;
	while(str[i] != '\0'){
		if(str[i] < '\0' || str[i] > '9' ){
			return 0;
			i++;
		}
	}
return 1;
}

int esSoloLetras(char str[]){
	int i=0;
	while(str[i] != '\0'){
		if((str[i] != ' ')&&(str[i] < 'a' || str[i] > 'z')&&(str[i] < 'A' || str[i] > 'Z')){
			return 0;
			i++;
		}
	}
	return 1;
}

int esAlphaNumerico(char str[]){
	int i=0;
	while(str[i] != '\0'){
		if((str[i] != ' ')&&(str[i] < 'a' || str[i] > 'z')&&(str[i] < 'A' || str[i] > 'Z')&&(str[i] < '0' || str[i] > '9')){
			return 0;
			i++;
		}
	}
	return 1;
}

void getString(char mensaje[], char input[] )
{
	printf(mensaje);
	scanf("%s", input);
}

int getStringLetras(char mensaje[], char input[])
{
	int auxiliar[256];
	getString(mensaje,auxiliar);
	if(esSoloLetras(auxiliar)){
		strcpy(input,auxiliar);
		return 1;
	}
return 0;
}

int getStringNumeros(char mensaje[], char input[])
{
	int auxiliar[256];
	getString(mensaje,auxiliar);
	if(esNumerica(auxiliar)){
		strcpy(input,auxiliar);
		return 1;
	}
return 0;
}


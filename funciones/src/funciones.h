/*
 * funciones.h
 *
 *  Created on: 14 sep. 2019
 *      Author: Vivis
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

int esNumerica(char str[]);
int esSoloLetras(char str[]);
int esAlphaNumerico(char str[]);

void getString(char mensaje[], char input[] );
int getStringLetras(char mensaje[], char input[]);
int getStringNumeros(char mensaje[], char input[]);



#endif /* FUNCIONES_H_ */

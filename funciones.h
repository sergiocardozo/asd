#define FUNCIONES_H_INCLUDED

/** \brief Funcion que devuelve la suma entre dos numeros
 *
 * \param Pide el primer sumando
 * \param Pide el segundo sumando
 * \return Devuelve la suma entre los dos numeros ingresados
 *
 */
float getSum (float, float);
/** \brief Funcion que devuelve el resto entre dos numeros
 *
 * \param Pide el minuendo
 * \param Pide el sustraendo
 * \return Devuelve el resto entre los dos numeros ingresados
 *
 */
float getSubtraction (float, float);
/** \brief Funcion que devuelve el producto entre dos numeros
 *
 * \param Pide el primer factor
 * \param Pide el segundo factor
 * \return Devuelve el producto entre los dos factores
 *
 */
float getMultiply (float, float);
/** \brief Funcion que devuelve el cociente entre dos numeros
 *
 * \param Pide el dividendo
 * \param Pide el divisor
 * \return Devuelve el cociente entre los dos numeros ingresados
 *
 */
float getDivide (float, float);
/** \brief Funcion que devuelve el factorial de una variable numerica
 *
 * \param numero int Pide el valor numerico entero
 * \return int Devuelve el factorial del numero que se ingreso
 *
 */
int getFactorial (int);
/** \brief Pide un numero al usuario y devuelve el resultado
 *
 * \param mensaje[] char El mensaje que se le mostrara al usuario
 * \return float El numero ingresado por el usuario
 *
 */
float getNumber(char mensaje[]);

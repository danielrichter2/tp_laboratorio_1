/*
 * masFunciones.h
 *
 *  Created on: 14 may. 2022
 *      Author: richter
 */

#ifndef MASFUNCIONES_H_
#define MASFUNCIONES_H_

/// @brief Le pide al usuario que ingrese el codigo del vuelo
///
/// @param codigoDeVuelo puntero
/// @param mensaje

void pedirCodigoDeVuelo(char codigoDeVuelo[10], char* mensaje);

/// @brief pide al usuario un dato a traves de string y cambia el ultimo bit de '\n' a '\0'
///
/// @param cadena puntero
/// @param len tamaño del string
/// @return devuelve -1 si hubo un error - 0 si no lo hay

int myGets(char* cadena, int len);

/// @brief transforma el string obtenido de esNumerica y myGets a un entero
///
/// @param pResultado puntero
/// @return devuelve -1 si hubo un error en esta funcion o en alguna de las anteriores - 0 si no lo hay

int getInt(int* pResultado);

/// @brief recorre el string para verificar que todos sus digitos sean numericos
///
/// @param cadena puntero
/// @return devuelve -1 si hubo un error o si se encontro algun digito que no es numerico y 0 si no lo hay

int esNumerica(char* cadena);

/// @brief pide al usuario que ingrese un entero usando getInt, verifica que este dentro de los parametros establecidos
/// 	   y duevle el entero generado
///
/// @param pResultado puntero
/// @param mensaje mensaje que se imprime para pedir el dato al usuario
/// @param mensajeError mensaje que se imprime si no se ingresa un entero
/// @param minimo parametro que delimita el numero minimo a ingresar
/// @param maximo parametro que delimita el numero maximo a ingresar
/// @return devuelve -1 si hubo un error - 0 si no lo hay

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo);

/// @brief transforma el string obtenido de esNumerica y myGets a un flotante
///
/// @param pResultado pResultado puntero
/// @return devuelve -1 si hubo un error en esta funcion o en alguna de las anteriores - 0 si no lo hay

int getFloat(float *pResultado);

/// @brief pide al usuario que ingrese un flotante usando getFloat, verifica que este dentro de los parametros establecidos
/// 	   y duevle el flotante generado
///
/// @param pResultado puntero
/// @param mensaje mensaje que se imprime para pedir el dato al usuario
/// @param mensajeError mensaje que se imprime si no se ingresa un flotante
/// @param minimo parametro que delimita el numero minimo a ingresar
/// @param maximo parametro que delimita el numero maximo a ingresar
/// @return devuelve -1 si hubo un error - 0 si no lo hay

int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo);

/// @brief pide al usuario que ingrese un nombre, verifica que no se hayan ingresados caracteres
/// 	   que no sean letras y devuelve el nombre generado
///
/// @param cadena puntero
/// @param mensaje mensaje que se imprime para pedirle al usuario que ingrese el dato
/// @param mensajeError mensaje que se imprime si hay caracteres que no son letras
/// @return devuelve -1 si hubo un error - 0 si no lo hay

int utn_getName(char* cadena, char* mensaje, char* mensajeError);

/// @brief transforma toda la cadena a minuscula y solo pasa a mayuscula la inicial de cada nombre ingresado
///
/// @param cadena puntero por el cual devuelve la cadena con las mayusculas corregidas

void corregirMayus(char* cadena);

#endif /* MASFUNCIONES_H_ */

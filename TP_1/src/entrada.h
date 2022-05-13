/*
 * entrada.h
 *
 *  Created on: 16 abr. 2022
 *      Author: richter
 */

#ifndef ENTRADA_H_
#define ENTRADA_H_

int ingresarNumero(int* pNumero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int ingresarFlotante(float* pNumero, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

#endif /* ENTRADA_H_ */

/*
 * funciones.h
 *
 *  Created on: 16 abr. 2022
 *      Author: richter
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
//si la funcion ingresarNumero devuelve 0, se podra cargar correctamente,si no marcara error
void cargarKm();
//si la carga de km fue correcta, pide los precios
void cargarPrecioVueloLa();
void cargarPrecioVueloAe();
//si se realizan las cargas previas se realizaran los calculos
void calcularCostosTotales();
//si se realizaron los calculos, muestra los resultados, si no imprime un mensaje pidiendo que se ingresen los precios
void mostrarDatos();

void cargaForzada();

#endif /* FUNCIONES_H_ */

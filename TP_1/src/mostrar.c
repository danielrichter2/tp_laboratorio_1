/*
 * mostrar.c
 *
 *  Created on: 16 abr. 2022
 *      Author: richter
 */

#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"

void mostrarKm(int* km){
	printf("\n\nKm ingresados: %d",*km);
}

void mostrarPreAe(float* precioAe, float* precioDebAe, float* precioCreAe, float* precioBitAe, float* precioUAe){
	printf("\n\nPrecio Aerolineas: $%.2f",*precioAe);
	printf("\nPrecio con tarjeta de debito : $%.2f", *precioDebAe);
	printf("\nPrecio con tarjeta de credito : $%.2f", *precioCreAe);
	printf("\nPrecio pagando con bitcoin : $%.2f", *precioBitAe);
	printf("\nMostrar precio unitario : $%.2f", *precioUAe);
}

void mostrarPreLa(float* precioLa, float* precioDebLa, float* precioCreLa, float* precioBitLa, float* precioULa){
	printf("\n\nPrecio Aerolineas: $%.2f", *precioLa);
	printf("\nPrecio con tarjeta de debito : $%.2f", *precioDebLa);
	printf("\nPrecio con tarjeta de credito : $%.2f", *precioCreLa);
	printf("\nPrecio pagando con bitcoin : $%.2f", *precioBitLa);
	printf("\nMostrar precio unitario : $%.2f", *precioULa);
}

void mostrarDif(float* diferenciaVuelos){
	printf("\n\nLa diferencia de precios es: %.2f",*diferenciaVuelos);
}

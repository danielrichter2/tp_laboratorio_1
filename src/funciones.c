/*
 * funciones.c
 *
 *  Created on: 16 abr. 2022
 *      Author: richter
 */


#include "entrada.h"
#include <stdio.h>
#include <stdlib.h>
#include "mostrar.h"


int km;
float precioLa=0;
float precioDebLa=0;
float precioCreLa=0;
float precioBitLa=0;
float precioULa=0;

float precioAe=0;
float precioDebAe=0;
float precioCreAe=0;
float precioBitAe=0;
float precioUAe=0;
float diferenciaVuelos=0;
float bitcoin = 4606954.55;


int cargaKm = -1;
int cargaVueloAe = -1;
int cargaVueloLa = -1;
int calculosRealizado = -1;
int respuesta;

void cargarKm() {

	respuesta = ingresarNumero(&km, "Ingrese los km ", "Error, Datos invalidos\n", 1,1000000, 2);
	if (respuesta == 0) {
		printf("\nKm cargados\n");
		cargaKm = 0;
	} else {
		printf("No se pudo cargar los km");
	}
}

void cargarPrecioVueloAe() {
	int respuesta1;
	if(cargaKm==0){
		respuesta1 = ingresarFlotante(&precioAe, "Ingrese el precio del vuelo por Aerolineas ", "Error, Datos invalidos\n", 1, 1000000, 2);
			if (respuesta1 == 0) {
				printf("\nPrecio guardado correctamente\n");
				cargaVueloAe = 0;
			} else {
				printf("Error, ingrese los datos nuevamente");
			}
	}else{
		printf("\nError, Debe cargar los km primero");
	}
}

void cargarPrecioVueloLa() {
	int respuesta2;
	if(cargaKm==0){
		respuesta2 = ingresarFlotante(&precioLa, "Ingrese el precio del vuelo por Latam ","Error, Datos invalidos\n", 1, 1000000, 2);
			if (respuesta2 == 0) {
				printf("Precio guardado correctamente\n");
				cargaVueloLa = 0;
			} else {
				printf("Error, ingrese los datos nuevamente");
			}
	}else{
		printf("\nError, Debe cargar los km primero");
	}
}

void calcularCostosTotales(){
	if(cargaKm==0 && cargaVueloAe==0 && cargaVueloLa==0){
		//calculo vuelo Latam
		precioDebLa= precioLa - (precioLa * 0.1);
		precioCreLa = precioLa+ (precioLa * 0.2);
		precioBitLa =  (precioLa *100) / bitcoin;
		precioULa = precioLa / km;

		//calculo vuelo Latam
		precioDebAe= precioAe - (precioAe * 0.1);
		precioCreAe = precioAe+ (precioAe * 0.2);
		precioBitAe =  (precioAe *100) / bitcoin;
		precioUAe = precioAe / km;

		//calculo diferencia
		if(precioAe>= precioLa){
			diferenciaVuelos = precioAe - precioLa;
		}
		else{
			diferenciaVuelos = precioLa - precioAe;
		}

		calculosRealizado=0;
		printf("\nOperaciones realizadas\n");
	}

	else{
		printf("Debe realizar los pasos anteriores a esta opcion\n");
	}
}

void mostrarDatos(){
	if(calculosRealizado==0){
		mostrarKm(&km);
		mostrarPreAe(&precioAe, &precioDebAe, &precioCreAe, &precioBitAe, &precioUAe);
		mostrarPreLa(&precioLa, &precioDebLa, &precioCreLa, &precioBitLa, &precioULa);
		mostrarDif(&diferenciaVuelos);
	}else{
		printf("\nDebe hacer los calculos previos\n");

	}
}


void cargaForzada(){
	km= 7090;
	precioAe= 162965;
	precioLa= 159339;

	cargaKm=0;
	cargaVueloAe=0;
	cargaVueloLa=0;

	calcularCostosTotales();
	mostrarDatos();
}

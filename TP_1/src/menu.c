/*
 * menu.c
 *
 *  Created on: 16 abr. 2022
 *      Author: richter
 */


#include "entrada.h"
#include "funciones.h"
#include "mostrar.h"

#include <stdio.h>
#include <stdlib.h>

void opcionesMenu(){

	int opcion;
	int numero;
	do {
			numero =ingresarNumero(&opcion,"\nSeleccione una opcion:\n1-IngresarKm\n"
					"2-Ingresar Precios de vuelos\n"
					"3-Calcular costos\n"
					"4-InformarResultados\n"
					"5-Carga forzada de datos\n"
					"6-Salir ","Opcion invalida\n", 1, 6, 2);

			if (!numero) {
				switch (opcion) {

					case 1:
						cargarKm();

							break;

					case 2:
						cargarPrecioVueloLa();
						cargarPrecioVueloAe();
							break;

					case 3:
							calcularCostosTotales();
							break;

					case 4:
							mostrarDatos();
							break;

					case 5:
							cargaForzada();
							break;
				}
			}

		} while (opcion != 6);
}

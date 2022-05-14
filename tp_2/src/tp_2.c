/*
 ============================================================================
 Name        : tp_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
 * Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
no puede tener más de 2000 pasajeros.
El sistema deberá tener el siguiente menú de opciones:
 *	1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
 *	número de Id. El resto de los campos se le pedirá al usuario.
 *
 *	2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
 *	o Precio o Tipo de pasajero o Código de vuelo
 *	3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
 *	4. INFORMAR:
 * 	1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
 * 	2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
 *	promedio.
 *	3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
 *	1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
 *	Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
 *	carga de algún pasajero.
 *	2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "masFunciones.h"

#define MAX_PASAJEROS 2000


int main(void) {

	setbuf(stdout, NULL);

	int opcionMenuPrincipal;
	int opcionMenuModificar;
	int opcionMenuInformar;

	int opcionModificarId;
	int modificarInd;
	int opcionBajaId;
	int bajaInd;

	int id = 0;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoDeVuelo[10];
	int tipoDePasajero;
	float precioTotal;
	float precioPromedio;
	int cantPasajeroPorEncimaDelPromedio;
	int estadoDelVuelo;

	Passenger listaDePasajeros[MAX_PASAJEROS];
	StatusFlightAndTypePassenger estadoDelVueloYTipoPasajero[3];



	if(initPassengers(listaDePasajeros, MAX_PASAJEROS) != 0)
	{
		printf("\nError al inicializar la estructura Passenger.\n");
	}

	if(initStatusFlightAndTypePassenger(estadoDelVueloYTipoPasajero, 3) != 0)
	{
		printf("\nError al inicializar la estructura StatusFlightAndTypePassenger.\n");
	}

	do{
		printf("\nMenu principal: \n"
				"1- ALTA de pasajero.\n"
				"2- MODIFICAR pasajero.\n"
				"3- BAJA de pasajero.\n"
				"4- INFORMAR.\n"
				"5- Carga Forzada.\n"
				"6- Salir.\n"
				"Elija una opción: ");
		fflush(stdin);
		scanf("%d",&opcionMenuPrincipal);

		switch(opcionMenuPrincipal)
		{
			case 1:
				id++;
				utn_getName(nombre, "Ingrese el nombre del pasajero: ", "Error, ingrese el nombre correctamente.\n");
				utn_getName(apellido, "Ingrese el apellido del pasajero: ", "Error, ingrese el apellido correctamente.\n");
				utn_getFloat(&precio, "Ingrese el precio del vuelo: ", "Error, ingrese un dato valido.\n", 1, 999999999999999);
				utn_getNumero(&tipoDePasajero, "Ingrese 1 si es Primera Clase, 2 si es Clase Económica, 3 si es Clase Turista: ",
						"Error. Ingrese una opción valida.\n", 1, 3);
				pedirCodigoDeVuelo(codigoDeVuelo, "Ingrese el codigo de vuelo: ");
				utn_getNumero(&estadoDelVuelo, "Ingrese 1 si el vuelo esta Activo, 2 si esta Inactivo, 3 si esta Demorado: ",
						"Error. Ingrese una opción valida.\n",1,3);
				if(addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  nombre, apellido, precio, tipoDePasajero, codigoDeVuelo, estadoDelVuelo) == 0)
				{
					printf("\nSe ha agregado un pasajero con exito.\n");
				}
				else
				{
					printf("\nHubo un error al intentar agregar al pasajero.\n");
				}
				break;
			case 2:
				do{
					printf("\nMenu modificaciones de datos del pasajero:\n"
							"1- Nombre.\n"
							"2- Apellido.\n"
							"3- Precio.\n"
							"4- Tipo de pasajero.\n"
							"5- Código de vuelo.\n"
							"6- Volver al menú principal.\n"
							"Elija una opción: ");
					fflush(stdin);
					scanf("%d", &opcionMenuModificar);
					switch(opcionMenuModificar)
					{
						case 1:
						case 2:
						case 3:
						case 4:
						case 5:
							printf("Indique el ID del pasajero que desea modificar: ");
							fflush(stdin);
							scanf("%d", &opcionModificarId);
							modificarInd = findPassengerById(listaDePasajeros, MAX_PASAJEROS, opcionModificarId);
							if (modificarInd > -1)
							{
								if(modifyPassenger(listaDePasajeros, MAX_PASAJEROS, modificarInd, opcionMenuModificar) == 0)
								{
									printf("\nSe ha modificado al pasajero con exito.\n");
								}
								else
								{
									printf("\nHubo un error al intentar modificar al pasajero.\n");
								}
							}
							else
							{
								printf("\nEl ID es incorrecto.\n");
							}
							break;
						case 6:
							printf("\nVolviendo al menú principal.\n");
							break;
						default:
							printf("\nElija una opción valida.\n");
					}
				}while(opcionMenuModificar != 6);
				break;
			case 3:
				printf("Ingrese el ID del pasajero que desea dar de baja: ");
				fflush(stdin);
				scanf("%d", &opcionBajaId);
				bajaInd = findPassengerById(listaDePasajeros, MAX_PASAJEROS, opcionBajaId);
				if (bajaInd > -1)
				{
					if(removePassenger(listaDePasajeros, MAX_PASAJEROS, bajaInd) == 0)
					{
						printf("\nSe ha dado de baja con exito al pasajero.\n");
					}
					else
					{
						printf("\nHubo un error.\n");
					}
				}
				else
				{
					printf("\nEl ID ingresado es incorrecto.\n\n");
				}
				break;
			case 4:
				do{
					printf("\nMenú para informar pasajeros:\n"
							"1- Listado de pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n"
							"2- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
							"3- Listado de los pasajeros por Código de vuelo y estados de vuelos 'ACTIVO'\n"
							"4- Volver al menú principal\n"
							"Elija una opción: ");
					fflush(stdin);
					scanf("%d",&opcionMenuInformar);
					switch(opcionMenuInformar)
					{
					case 1:
						if(sortPassengersByLastName(listaDePasajeros, MAX_PASAJEROS, 1) == 0)
						{
							if(printPassenger(listaDePasajeros, estadoDelVueloYTipoPasajero ,MAX_PASAJEROS, 3) != 0)
							{
								printf("\nLa lista de pasajeros esta vacia.\n");
							}
						}
						else
						{
							printf("\nHa ocurrido un error al intentar ordenar los pasajero por apellido.\n");
						}
						break;
					case 2:
						if(averagePassenger(listaDePasajeros,MAX_PASAJEROS , &precioTotal, &precioPromedio) == 0)
						{
							cantPasajeroPorEncimaDelPromedio = aboveAveragePassenger(listaDePasajeros, MAX_PASAJEROS, precioPromedio);
							printf("\nEl precio total de todos los vuelos fue de $%.2f.\nEn promedio cada pasajero pagó $%.2f."
								"\nEn total hay %d pasajeros que paga por encima del promedio.\n", precioTotal, precioPromedio, cantPasajeroPorEncimaDelPromedio);
						}
						else
						{
							printf("\nHubo un error al intentar conseguir los calculos.\n");
						}
						break;
					case 3:
						if(sortPassengersByCode(listaDePasajeros, MAX_PASAJEROS, 1) == 0)
						{
							if(printPassenger(listaDePasajeros, estadoDelVueloYTipoPasajero ,MAX_PASAJEROS, 3) != 0)
							{
								printf("\nLa lista de pasajeros esta vacia.\n");
							}
						}
						else
						{
							printf("\nHubo un error al intentar ordenar los pasajeros por codigo de vuelo.\n");
						}
						break;
					case 4:
						printf("\nVolviendo al menú principal.\n");
						break;
					default:
						printf("\nElija una opción valida.\n");
					}
				}while(opcionMenuInformar != 4);
				break;
			case 5:
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id, "Juan", "Quiroz", 12321.43, 2, "A-0001", 1);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Lionel", "Guzman", 20232.05, 2, "A-1343", 3);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Jorge", "Burruchaga", 89750.90, 2, "B-2300", 2);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Lorenzo", "Barone", 89264.17, 1, "C-2123", 1);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Joaquin", "Manis", 31112.21, 1, "B-1002", 1);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Leonardo", "Tecce", 31521.29, 1, "D-1923", 3);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Valentina", "Podriani", 10192.20, 3, "M-2311", 2);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Guido", "Gil", 12657, 3, "T-2110", 2);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Maria", "Perez", 23843, 2, "J-1102", 3);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Carlos", "Bustamante", 33654.13, 3, "A-1485", 1);
				printf("\nSe han cargado con exito todos los usuarios de la carga forzada.\n");
				break;
			case 6:
				printf("\nCerrando sistema.\n");
				break;
			default:
				printf("\nElija una opción valida.\n");
		}

	}while(opcionMenuPrincipal != 6);

	return 0;
}

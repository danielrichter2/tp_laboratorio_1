/*
 * masFunciones.c
 *
 *  Created on: 14 may. 2022
 *      Author: richter
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "masFunciones.h"
#define LIBRE 0
#define OCUPADO 1

void pedirCodigoDeVuelo(char codigoDeVuelo[10], char* mensaje)
{
	printf(mensaje);
	fflush(stdin);
	gets(codigoDeVuelo);
}

int myGets(char *cadena, int len)
{
	int retorno = -1;
	if (cadena != NULL && len > 0 && fgets(cadena, len, stdin) == cadena)
	{
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n')
		{
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int getInt(int *pResultado)
{
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int esNumerica(char *cadena)
{
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0)
	{
		while (cadena[i] != '\0')
		{
			if (isalpha(cadena[i]) != 0)
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo)
{
	int bufferInt;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0)
		{
			if (bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int getFloat(float *pResultado)
{
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo)
{
	float bufferFloat;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 0)
		{
			if (bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int utn_getName(char* cadena, char* mensaje, char* mensajeError)
{
	int retorno = 1;

	while(retorno != 0)
	{
		printf(mensaje);
		fflush(stdin);
		gets(cadena);
		for (int i = 0; i < strlen(cadena); i++)
		{
			if(isalpha(cadena[i]) == 0 && isspace(cadena[i]) == 0 && cadena[i] != 'ñ')
			{
				retorno = 1;
				printf(mensajeError);
				break;
			}
			retorno = 0;
		}
	}

	corregirMayus(cadena);

	return retorno;
}

void corregirMayus(char* cadena)
{
	strlwr(cadena);

	cadena[0] = toupper(cadena[0]);

	for(int i = 0; i < strlen(cadena); i++)
	{
		if (cadena[i] == ' ')
		{
			cadena[i + 1] = toupper(cadena[i + 1]);
		}
	}
}

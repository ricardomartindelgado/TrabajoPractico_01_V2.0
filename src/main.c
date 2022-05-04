/*
 ============================================================================
 Name        : TrabajoPractico_01_V2.0.c
 Author      : Martin Delgado
 Version     : 2.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_input.h"
#include "utn_operaciones.h"
#include "utn_agencia.h"

#define TRUE 0
#define FALSE 1

int main(void) {

	setbuf(stdout, NULL); //Windows
	//system("title Agencia de Viajes"); //Windows Console

	//	NOTA: PARA CONSIDERAR ..
	//	INICIALIZAR VARIABLES CON -1 ME DA MAS CONTROL EN EL DEBUG
	// 	ESTA BUENO PERO SOLO PUEDO HACERLO PORQUE OPERO CON VALORES POSITIVOS
	//	PENSAR A FUTURO CUANDO OPERE CON EL RANGO COMPLETO DE LA VARIABLE

	int opcion;
	float kilometros = -1;

	float precioAerolinasUsuario = -1;
	float precioAerolinasUnitario = -1;
	float precioAerolinasDebito = -1;
	float precioAerolinasCredito = -1;
	float precioAerolinasBitcoin = -1;

	float precioLatamUsaurio = -1;
	float precioLatamUnitario = -1;
	float precioLatamDebito = -1;
	float precioLatamCredito = -1;
	float precioLatamBitcoin = -1;

	float diferenciaDePrecio;

	int kilometrosRetornoValido =-1;
	int precioAerolinasRetornoValido=-1;
	int precioLatamRetornoValido =-1;
	int calcularTodoOK = FALSE;


	do {
		agencia_imprimirMenuOpcionesSeis(kilometros, precioAerolinasUsuario, precioLatamUsaurio);

		//REINTENTO SETEO EN 0 PORQUE EL DO-WHILE YA ME DA ESTE SERVICIO
		//SI NO VALIDO OPCION Y NO LA INICIALIZE PUEDE VENIR CARGADA CON BASURA
		if (!utn_getInt(&opcion, "\tIngrese una opcion ", " >> Opcion Invalida", 1, 6, 0))
		{
			switch (opcion)
			{
				case 1: // INGRESAR KILOMETROS
					kilometrosRetornoValido = utn_getFloat(&kilometros, "\nIngrese kilometros: ", "Numero invalido", 1, KILOMETROS_MAX, 2);
					break;


				case 2: // INGRESAR PRECIO DE VUELOS
					precioAerolinasRetornoValido = utn_getFloat(&precioAerolinasUsuario, "\nIngrese precio Aerolinas: ", "Numero invalido", 1, PRECIO_MAX, 2);
					precioLatamRetornoValido = utn_getFloat(&precioLatamUsaurio, "\nIngrese precio Latam: ", "Numero invalido", 1, PRECIO_MAX, 2);
					break;


				case 3: // CALCULAR SOLO SI TENGO DATOS CARGADOS
					if ( !kilometrosRetornoValido && !precioAerolinasRetornoValido && !precioLatamRetornoValido)
					{
						if (   ! agencia_calcularTodo(kilometros, precioAerolinasUsuario, &precioAerolinasDebito, &precioAerolinasCredito, &precioAerolinasBitcoin, &precioAerolinasUnitario)
							&& ! agencia_calcularTodo(kilometros, precioLatamUsaurio, &precioLatamDebito, &precioLatamCredito, &precioLatamBitcoin, &precioLatamUnitario)  )
						{
							utn_restarValorAbsoluto(&diferenciaDePrecio, precioAerolinasUnitario, precioLatamUnitario);
							calcularTodoOK = TRUE;
							printf("\n\tSe pudo calcular todo\n");
						}
					}
					else
					{
						calcularTodoOK = FALSE;
						printf("\n\tNo se puede calcular porque faltan ingresar datos\n");
					}
					break;


				case 4: // INFORMAR SOLO SI TENGO DATOS CALCULADOS
					if (!calcularTodoOK)
					{
						agencia_imprimirInforme("AEROLINAS ", precioAerolinasUsuario, precioAerolinasDebito, precioAerolinasCredito, precioAerolinasBitcoin, precioAerolinasUnitario);
						agencia_imprimirInforme("LATAM ", precioLatamUsaurio, precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioLatamUnitario);
						printf("\n\tLa diferencia de precio es: $%.2f\n\n", diferenciaDePrecio);
						calcularTodoOK = FALSE;
					}
					else
					{
						printf("\n\tNo se puede informar porque no se calcularon los datos\n");
					}
					break;


				case 5: // CARGA FORZADA DE DATOS

					// CARGA DATOS
					kilometros = 7090;
					precioAerolinasUsuario = 162965;
					precioLatamUsaurio = 159339;


					// CALCULAR TODOS LOS COSTOS
					agencia_calcularTodo(kilometros, precioAerolinasUsuario, &precioAerolinasDebito, &precioAerolinasCredito, &precioAerolinasBitcoin, &precioAerolinasUnitario);
					agencia_calcularTodo(kilometros, precioLatamUsaurio, &precioLatamDebito, &precioLatamCredito, &precioLatamBitcoin, &precioLatamUnitario);
					utn_restarValorAbsoluto(&diferenciaDePrecio, precioAerolinasUnitario, precioLatamUnitario);


					// 	INFORMAR
					agencia_imprimirInforme("AEROLINAS ", precioAerolinasUsuario, precioAerolinasDebito, precioAerolinasCredito, precioAerolinasBitcoin, precioAerolinasUnitario);
					agencia_imprimirInforme("LATAM ", precioLatamUsaurio, precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioLatamUnitario);
					printf("\n\tLa diferencia de precio es: $%.2f\n", diferenciaDePrecio);


					//  RESETEAR
					kilometrosRetornoValido =-1;
					precioAerolinasRetornoValido=-1;
					precioLatamRetornoValido =-1;
					calcularTodoOK = FALSE;


					break;
			}
		}
		//system("cls"); //Windows Console
	} while (opcion != 6);


	return EXIT_SUCCESS;
}

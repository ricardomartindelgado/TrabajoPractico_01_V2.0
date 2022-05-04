/*
 * utn_agencia.c
 *
 *  	Created on: XX abr. 2022
 *      Author: Martin Delgado
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_input.h"
#include "utn_operaciones.h"
#include "utn_agencia.h"


void agencia_imprimirMenuOpcionesSeis(float kilometros, float precioAerolinas, float precioLatam)
{
	printf("\n\tOpcion 1: Ingresar Kilometros         (KM = %.2f)", kilometros);
	printf("\n\tOpcion 2: Ingresar Precios de Vuelos  (Aerolíneas = $%.2f, Latam = $%.2f)", precioAerolinas, precioLatam);
	printf("\n\tOpcion 3: Calcular todos los costos");
	printf("\n\tOpcion 4: Informar");
	printf("\n\tOpcion 5: Carga forzada de datos");
	printf("\n\tOpcion 6: Salir\n\n");
}


void agencia_imprimirInforme(char* nombre, float precioUnitario, float debito, float credito, float bitcoin, float unitario)
{
	printf("\n\t   Precio %s: %.2f", nombre, precioUnitario);
	printf("\n\tA) Precio con tarjeta de debito: $%.2f", debito);
	printf("\n\tB) Precio con tarjeta de credito: $%.2f", credito);
	printf("\n\tC) Precio pagando con bitcoin: $%.4f BTC", bitcoin);
	printf("\n\tD) Precio unitario: $%.2f", unitario);
	printf("\n");
}



int agencia_calcularTodo(float kilometros, float precioUsuario, float* precioDebito, float* precioCredito, float* precioBitcoin, float* precioUnitario)
{
	int retorno = -1;

	if (   ! utn_calcularReglaDeTres(DEBITO_DESCUENTO_MAX, precioUsuario, 100 - DEBITO_DESCUENTO, precioDebito)
		&& ! utn_calcularReglaDeTres(CREDITO_INTERES_MAX, precioUsuario, 100 + CREDITO_INTERES, precioCredito)
		&& ! utn_calcularReglaDeTres(PESOSBITCOIN, BITCOIN, precioUsuario, precioBitcoin)
		&& ! utn_calcularReglaDeTres(kilometros, precioUsuario, 1, precioUnitario)  )
	{
		retorno = 0;
	}
	return retorno;
}


//	NOTA: PARA CONSIDERAR
//	Q: 	ES NECESARIO CREAR UNA FUNCION PARA CADA CALCULAR TENIENDO
//		EN CUENTA QUE LA FUNCIONALIDAD POR DENTRO ES LA MIMA?
//	A: 	NO. PERO ES CIERTO QUE HARIA MAS FACIL LEER EL CODIGO. SI?
//
//	agencia_calcularDebito(nParametros);
//	calcularCredito(nParametros);
//	calcularBitcoin(nParametros);
//	calcularPrecioPorKM(nParametros);



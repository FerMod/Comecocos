/*-------------------------------------
teclado.c
-------------------------------------*/

// añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "sprites.h"


//Esta funcion tiene que devolver el valor de la tecla pulsada
int  TeclaPulsada() 
{
	//devuelve el valor asociado a la tecla pulsada: A=0;B=1;Select=2;Start=3;Der=4;Izq=5;
	//Arriba=6;Abajo=7;R=8;L=9;
	// -1 en otros casos

if((TECLAS_DAT & 0x1)==0){return A;}
if((TECLAS_DAT & 0x2)==0){return B;}
if((TECLAS_DAT & 0x3)==0){return SELECT;}
if((TECLAS_DAT & 0x4)==0){return START;}
if((TECLAS_DAT & 0x5)==0){return IZDA;}
if((TECLAS_DAT & 0x6)==0){return DCHA;}
if((TECLAS_DAT & 0x7)==0){return ARRIBA;}
if((TECLAS_DAT & 0x8)==0){return ABAJO;}
if((TECLAS_DAT & 0x9)==0){return R;}
if((TECLAS_DAT & 0xA)==0){return L;}
return -1;
	
}

void HabilitarIntTec()		//Habilitar interrupciones del teclado
{
	//Para ello primero se deshabilitan todas las interrupciones
	//Escribir un 1 en el bit correspondiente al teclado del REG_IE
	//Para acabar, se habilitan todas las interrupciones

	
}


void DeshabilitarIntTec()	//Deshabilitar interrupciones del teclado
{
//Para ello primero se deshabilitan todas las interrupciones
//Escribir un 0 en el bit correspondiente al teclado del REG_IE
//Para acabar, se habilitan todas las interrupciones

		
}


//Rutina de atencion a la interrupcion del teclado
void IntTec()
{
	
		
		
}
		

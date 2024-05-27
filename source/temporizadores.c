/*temporizadores.c*/
// añadir los includes que sean necesarios
#include "defines.h"
#include "sprites.h"
#include <nds.h>
#include <stdio.h>


void HabilitarIntTemp()		//Habilita las interrupciones del temporizador
{
	//Para ello primero se deshabilitan todas las interrupciones
	//Escribir un 1 en el bit correspondiente al temporizador del REG_IE
	//Para acabar, se habilitan todas las interrupciones


}		


void DeshabilitarIntTemp()		//Deshabilita las interrupciones del temporizador
{
	//Para ello primero se deshabilitan todas las interrupciones
	//Escribir un 0 en el bit correspondiente al remporizador del REG_IE
	//Para acabar, se habilitan todas las interrupciones



}


//Rutina de atención a la interrupción del temporizador
void IntTemp()
{





}


	
	


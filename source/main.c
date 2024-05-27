/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fondos.h"
#include "sprites.h"
#include "defines.h"
#include "rutservs.h"
#include "teclado.h"
#include "temporizadores.h"

//---------------------------------------------------------------------------------
// variables globales


int main() {

	/* Definir variables */	
	touchPosition pos_pantalla;

	/*  Poner en marcha el motor gráfico 2D. */
    	powerOn(POWER_ALL_2D);

	/*
     	*  Establecer la pantalla inferior como principal, inicializar el sistema gráfico
     	*  y configurar el sistema de fondos.
     	*/
    	lcdMainOnBottom();
    	initVideo();
    	initFondos();

    	/* Mostrar fondos en pantalla. */
    	SetFondo();
	//mostrarFondoSub();

	/* Inicializar memoria de sprites y guardar en ella los sprites */
	initSpriteMem();
	guardarSpritesEnMemoria();

	/* Establecer las paletas para los sprites */
	establecerPaletaPrincipal();
	establecerPaletaSecundaria();

	/* Para poder imprimir en pantalla (hacer trazas) hay que descomentar esta línea */
	consoleDemoInit();
	/* Una vez descomentada, no se verán los gráficos de la pantalla superior. */	
// ...


while(true){
int tecla;
tecla=TeclaPulsada();
iprintf("\x1b[3;7H Tecla pulsada: %d ", tecla);

}


}


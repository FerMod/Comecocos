/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sprites.h"
#include "defines.h"

u16* gfxKoko;
u16* gfxFruta;
u16* gfxFantasma;


/* Inicializar la memoria de Sprites. */
void initSpriteMem() {

	//int i;
	oamInit(&oamMain, SpriteMapping_1D_32, false);
	oamInit(&oamSub, SpriteMapping_1D_32, false);

	gfxKoko= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxFruta= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxFantasma= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	

/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla principal. El 0 es transparente y los no definidos son negros.
 */
}
void establecerPaletaPrincipal() {

	SPRITE_PALETTE[1] = RGB15(31,0,0); // los pixels a 1 se mostrarán rojos
//	SPRITE_PALETTE[1] = RGB15(40,4,220); // los pixels a 1 se mostrarán azul
	SPRITE_PALETTE[5] = RGB15(0,31,0); // los pixels a 1 se mostrarán verdes 
	SPRITE_PALETTE[3] = RGB15(255,255,255); // los pixels a 2 se mostrarán blanco (Fantasma)
	SPRITE_PALETTE[4] = RGB15(0,31,0); // los pixels a 4 se mostrarán verdes
	SPRITE_PALETTE[2] = RGB15(31,31,0); // los pixels a 2 se mostrarán amarillo claro(Koko)
}

/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla secundaria. El 0 es transparente y los no definidos son negros.
 */
void establecerPaletaSecundaria() {

	SPRITE_PALETTE_SUB[1] = RGB15(0,31,0); // los pixels a 1 se mostrarán verdes
}

/* Dibujado de un Sprite de 16x16 pixels */
/* Debido al funcionamiento de los bancos de memoria, las primeras cuatro filas 
 * forman el cuadrante superior izquiero, las siguientes, el cuadrante superior 
 * derecho, las siguientes el cuadrante inferior izquierdo y las últimas cuatro
 * filas, el cuadrante inferior derecho, como se muestra al lado.
 */
u8 Fantasma[256] = 
{
	0,0,0,0,0,3,3,3,0,0,0,3,3,3,3,3,	//	0,0,0,0,0,3,3,3, 3,3,3,0,0,0,0,0,
	0,0,3,3,3,3,3,3,0,3,0,0,0,3,3,3,	//	0,0,0,3,3,3,3,3, 3,3,3,3,3,0,0,0,
	0,5,5,5,0,0,3,3,0,5,5,5,0,0,3,3,	//	0,0,3,3,3,3,3,3, 3,3,3,3,3,3,0,0,
	0,5,5,5,0,0,3,3,3,0,0,0,0,3,3,3,	//	0,3,0,0,0,3,3,3, 0,0,0,0,3,3,3,0,

	3,3,3,0,0,0,0,0,3,3,3,3,3,0,0,0,	//	0,5,5,5,0,0,3,3, 5,5,5,0,0,3,3,0,
	3,3,3,3,3,3,0,0,0,0,0,0,3,3,3,0,	//	0,5,5,5,0,0,3,3, 5,5,5,0,0,3,3,0,
	5,5,5,0,0,3,3,0,5,5,5,0,0,3,3,0,	//	0,5,5,5,0,0,3,3, 5,5,5,0,0,3,3,0,
	5,5,5,0,0,3,3,0,0,0,0,0,3,3,3,3,	//	3,0,0,0,0,3,3,3, 0,0,0,0,3,3,3,3,

	3,3,0,0,0,3,3,3,3,3,3,3,3,3,3,3,	//	3,3,0,0,0,3,3,3, 3,0,0,0,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,	//	3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,	//	3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,
	3,3,0,3,3,3,0,0,3,0,0,0,3,3,0,0,	//	3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,

	3,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,	//	3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,	//	3,3,3,3,3,3,3,3, 3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,	//	3,3,0,3,3,3,0,0, 0,3,3,3,0,0,3,3,
	0,3,3,3,0,0,3,3,0,3,3,0,0,0,0,3,	//	3,0,0,0,3,3,0,0, 0,3,3,0,0,0,0,3,
};
u8 Koko[256]=
{
	0,0,0,0,0,0,2,2,0,0,0,0,0,2,2,2,	//	0,0,0,0,0,0,2,2, 2,2,2,2,2,2,2,0,
	0,0,0,0,2,2,2,2,0,0,0,2,2,2,2,2,	//	0,0,0,0,0,2,2,2, 2,2,2,2,2,2,2,2,
	0,0,2,2,2,2,2,2,0,0,2,2,2,2,2,2,	//	0,0,0,0,2,2,2,2, 2,2,2,2,2,2,2,2,
	0,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,	//	0,0,0,2,2,2,2,2, 2,0,0,0,2,2,2,2,
	
	2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,	//	0,0,2,2,2,2,2,2, 2,0,0,0,2,2,2,2,
	2,2,2,2,2,2,2,2,2,0,0,0,2,2,2,2,	//	0,0,2,2,2,2,2,2, 2,0,0,0,2,2,2,2,
	2,0,0,0,2,2,2,2,2,0,0,0,2,2,2,2,	//	0,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,	//	0,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,0,
	
	2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,	//	2,2,2,2,2,2,2,2, 2,2,2,2,2,2,0,0,
	0,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,	//	0,2,2,2,2,2,2,2, 2,2,2,2,2,0,0,0,
	0,0,0,2,2,2,2,2,0,0,0,0,2,2,2,2,	//	0,2,2,2,2,2,2,2, 2,2,2,2,0,0,0,0,
	0,0,0,0,0,2,2,2,0,0,0,0,0,0,2,2,	//	0,0,2,2,2,2,2,2, 2,2,2,2,2,2,0,0,
	
	2,2,2,2,2,2,0,0,2,2,2,2,2,0,0,0,	//	0,0,0,2,2,2,2,2, 2,2,2,2,2,2,2,0,
	2,2,2,2,0,0,0,0,2,2,2,2,2,2,0,0,	//	0,0,0,0,2,2,2,2, 2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,	//	0,0,0,0,0,2,2,2, 2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,	//	0,0,0,0,0,0,2,2, 2,2,2,2,2,2,2,0,
};

u8 Fruta[256] = 
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,	//	0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,4,0,0,0,0,0,4,4,4,	//	0,0,0,0,0,0,0,4, 0,0,0,0,0,0,0,0,
	0,0,0,4,4,4,4,4,0,0,1,1,4,1,4,1,	//	0,0,0,0,0,0,0,4, 0,0,0,0,0,0,0,0,
	0,1,1,1,1,1,1,1,0,1,1,3,1,1,1,1,	//	0,0,0,0,0,4,4,4, 4,4,0,0,0,0,0,0,

	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,	//	0,0,0,4,4,4,4,4, 4,4,4,4,0,0,0,0,
	0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,	//	0,0,1,1,4,1,4,1, 4,1,4,1,1,0,0,0,
	4,4,4,4,0,0,0,0,4,1,4,1,1,0,0,0,	//	0,1,1,1,1,1,1,1, 1,1,1,1,1,1,0,0,
	1,1,1,1,1,1,0,0,1,1,3,1,1,1,0,0,	//	0,1,1,3,1,1,1,1, 1,1,3,1,1,1,0,0,

	0,1,1,1,1,3,1,1,0,1,1,1,1,1,1,1,	//	0,1,1,1,1,3,1,1, 1,1,1,1,1,1,0,0,
	0,0,1,1,3,1,1,1,0,0,1,1,1,1,1,1,	//	0,1,1,1,1,1,1,1, 1,1,1,3,1,1,0,0,
	0,0,0,1,1,1,1,1,0,0,0,0,1,1,3,1,	//	0,0,1,1,3,1,1,1, 3,1,1,1,1,0,0,0,
	0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,	//	0,0,1,1,1,1,1,1, 1,1,1,1,1,0,0,0,

	1,1,1,1,1,1,0,0,1,1,1,3,1,1,0,0,	//	0,0,0,1,1,1,1,1, 1,1,1,1,0,0,0,0,
	3,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,	//	0,0,0,0,1,1,3,1, 1,1,1,0,0,0,0,0,
	1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,	//	0,0,0,0,0,1,1,1, 1,1,0,0,0,0,0,0,
	1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,	//	0,0,0,0,0,0,1,1, 1,0,0,0,0,0,0,0,
};

void BorrarFruta(int indice, int x, int y)
{

			oamSet(&oamMain, //main graphics engine context
			indice,           //oam index (0 to 127)  
			x, y,   //x and y pixle location of the sprite
			0,                    //priority, lower renders last (on top)
			0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
			SpriteSize_16x16,     
			SpriteColorFormat_256Color, 
			gfxFruta,//+16*16/2,                  //pointer to the loaded graphics
			-1,                  //sprite rotation data  
			false,               //double the size when rotating?
			true,			//hide the sprite?
			false, false, //vflip, hflip
			false	//apply mosaic
			); 
oamUpdate(&oamMain); 

}

void MostrarFruta (int indice, int x, int y)
{
 
			oamSet(&oamMain, //main graphics engine context
			indice,          //oam index (0 to 127)  
			x, y,   //x and y pixle location of the sprite
			0,                    //priority, lower renders last (on top)
			0,		 //this is the palette index if multiple palettes or the alpha value if bmp sprite	
			SpriteSize_16x16,     
			SpriteColorFormat_256Color, 
			gfxFruta,//+16*16/2,                  //pointer to the loaded graphics
			-1,                  //sprite rotation data  
			false,               //double the size when rotating?
			false,			//hide the sprite?
			false, false, //vflip, hflip
			false	//apply mosaic
			); 

	oamUpdate(&oamMain);  
}
void BorrarFantasma(int x, int y)
{

			oamSet(&oamMain, //main graphics engine context
			126,           //oam index (0 to 127)  
			x, y,   //x and y pixle location of the sprite
			0,                    //priority, lower renders last (on top)
			0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
			SpriteSize_16x16,     
			SpriteColorFormat_256Color, 
			gfxFantasma,//+16*16/2,                  //pointer to the loaded graphics
			-1,                  //sprite rotation data  
			false,               //double the size when rotating?
			true,			//hide the sprite?
			false, false, //vflip, hflip
			false	//apply mosaic
			); 
oamUpdate(&oamMain); 

}

void MostrarFantasma (int x, int y)
{
 
			oamSet(&oamMain, //main graphics engine context
			126,          //oam index (0 to 127)  
			x, y,   //x and y pixle location of the sprite
			0,                    //priority, lower renders last (on top)
			0,		 //this is the palette index if multiple palettes or the alpha value if bmp sprite	
			SpriteSize_16x16,     
			SpriteColorFormat_256Color, 
			gfxFantasma,//+16*16/2,                  //pointer to the loaded graphics
			-1,                  //sprite rotation data  
			false,               //double the size when rotating?
			false,			//hide the sprite?
			false, false, //vflip, hflip
			false	//apply mosaic
			); 

	oamUpdate(&oamMain);  
}

void MostrarKoko (int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		127,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxKoko,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		);   
oamUpdate(&oamMain); 
}
void BorrarKoko(int x, int y)
{

			oamSet(&oamMain, //main graphics engine context
			127,           //oam index (0 to 127)
			x, y,   //x and y pixle location of the sprite
			0,                    //priority, lower renders last (on top)
			0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
			SpriteSize_16x16,
			SpriteColorFormat_256Color,
			gfxKoko,//+16*16/2,                  //pointer to the loaded graphics
			-1,                  //sprite rotation data
			false,               //double the size when rotating?
			true,			//hide the sprite?
			false, false, //vflip, hflip
			false	//apply mosaic
			);
oamUpdate(&oamMain);

}


/* Para cada Sprite que se quiera llevar a pantalla hay que hacer una de estas funciones. */

void guardarSpritesEnMemoria(){ 
	int i;

		for(i = 0; i < 16 * 16 / 2; i++) //muestra un cuadrado en la memoria de la pantalla principal
		{				
				gfxFruta[i] = Fruta[i*2] | (Fruta[(i*2)+1]<<8);
				gfxFantasma[i] = Fantasma[i*2] | (Fantasma[(i*2)+1]<<8);	
				gfxKoko[i] = Koko[i*2] | (Koko[(i*2)+1]<<8);	
		}
}





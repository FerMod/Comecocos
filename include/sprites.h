extern u16* gfxKoko;
extern u16* gfxFruta;
extern u16* gfxFantasma;

/* Inicializar la memoria de Sprites. */
extern void initSpriteMem();

/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla principal. El 0 es transparente y los no definidos son negros.
 */
extern void establecerPaletaPrincipal();

/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla secundaria. El 0 es transparente y los no definidos son negros.
 */
extern void establecerPaletaSecundaria();

/* Para guardar los sprites en memoria y luego poder usarlos.*/

extern void guardarSpritesEnMemoria();
extern void MostrarFruta(int indice, int x, int y);
extern void BorrarFruta(int indice, int x, int y);

extern void MostrarFantasma(int x, int y);
extern void BorrarFantasma(int x, int y);

extern void MostrarKoko (int x, int y);
extern void BorrarKoko (int x, int y);






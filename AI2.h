/**
* @file AI2.h
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define width 1366
#define height 768

/**
* @struct Circle
* @brief struct for Circle
*/
typedef struct 
{
  int x ;
  int y ;
  float rayon ;

}Circle;

/**
* @struct Objet
* @brief struct for Objet
*/
typedef struct 
{

  SDL_Surface *img ;
  SDL_Rect pos ;
  Circle c ;
  SDL_Rect pos_text ;
  
}Objet ;

void initialiser (Objet *perso, Objet tab [])  ;
void setup (SDL_Surface *screen,Objet *perso,Objet tab []) ;
void calculer_centre_rayon (Objet *perso,Objet tab []) ;
float calculer_distance (Objet *perso,Objet tab []) ;
int verif_collision ( Objet *perso,Objet tab [],float D1 ) ;
void deplacement_objet(Objet *objet,int *running) ;
void annimation_feu(SDL_Surface *screen , Objet tab [],float *frame) ;

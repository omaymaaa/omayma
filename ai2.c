/**
* @file AI2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "AI2.h"
/**
* @brief To initialiser.
* @param perso
* @param objet
* @return Nothing
*/
void initialiser (Objet *perso, Objet tab []) 
{
  int i ; 
  char image [20] ;
  for (i=0;i<4;i++)
  {
   sprintf(image,"cc%d.png",i)  ;
   tab[i].img=IMG_Load(image) ;
   tab[i].pos.x=600 ;
   tab[i].pos.y=50 ;

   perso->img=IMG_Load("1.png") ;
   perso->pos.x=100 ;
   perso->pos.y=50 ;
   
  }

}
/**
* @brief To setup .
* @param screen
* @param perso
* @param objet
* @return Nothing
*/
void setup (SDL_Surface *screen,Objet *perso,Objet tab [])
{
 SDL_WM_SetCaption("AI2 || OUMAIMA ", NULL);
 SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
 SDL_BlitSurface(perso->img,NULL,screen,&(perso->pos)) ;
 SDL_BlitSurface(tab[0].img,NULL,screen,&(tab[0].pos)) ;
 SDL_Flip(screen) ;

}

/**
* @brief To calculer centre rayon .
* @param perso
* @param objet
* @return Nothing
*/
void calculer_centre_rayon (Objet *perso,Objet tab [])
{

 perso->c.x=perso->pos.x+ (perso->img->w)/2 ;
 perso->c.y=perso->pos.y+ (perso->img->h)/2 ;
 perso->c.rayon=sqrt( pow( (perso->img->w)/2 , 2) + pow( (perso->img->h)/2 , 2) ) ;
 /*  pour le circle inscrit :
 if(width<height)
 {
 perso->c.rayon= (perso->img->w)/2 ;
 tab [0]->c.rayon= (tab [0]->img->w)/2 ;
 }
 else 
 {
 perso->c.rayon= (perso->img->h)/2 ;
 tab [0]->c.rayon= (tab [0]->img->h)/2 ;
 } */
 tab[0].c.x=tab [0].pos.x+ (tab [0].img->w)/2 ;
 tab[0].c.y=tab [0].pos.y+ (tab [0].img->h)/2 ;
 tab[0].c.rayon=sqrt( pow( (tab [0].img->w)/2 , 2) + pow( (tab [0].img->h)/2 , 2) ) ;

}

/**
* @brief To calculer distance .
* @param perso
* @param objet
* @return float.
*/
float calculer_distance (Objet *perso,Objet tab []) 
{
  float D ;

  D=sqrt( pow( (perso->c.x) - (tab [0].c.x) ,2 ) + pow ( (perso->c.y) - (tab [0].c.y) , 2  ) ) ;

  return D ;

}

/**
* @brief To verif collision .
* @param perso
* @param objet
* @param D1
* @return integer
*/
int verif_collision ( Objet *perso,Objet tab [],float D1 )
{
  float D2 ;
  int collision=0 ;

  D2=perso->c.rayon + tab [0].c.rayon ;

  if(D1<=(D2-180) )
    collision= 1 ;
  
  return collision ;
}

/**
* @brief To deplacement.
* @param objet
* @param running
* @return Nothing.
*/
void deplacement_objet(Objet *objet,int *running)
  {
    SDL_Event event ;


  
   SDL_PollEvent(&event);
      switch(event.type)
        {
          case SDL_QUIT:
                *running=0;
          break;
          case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                  case SDLK_DOWN:
                      objet->pos.y+=2;
                  break;
                  case SDLK_UP:
                      objet->pos.y-=2;
                  break;
                  case SDLK_RIGHT:
                      objet->pos.x+=4;
                  break;
                  case SDLK_LEFT:
                      objet->pos.x-=4;
                  break;
                }
        }
    }
    
/**
* @brief To animation feu.
* @param screen
* @param objet
* @param frame
* @return Nothing.
*/
void annimation_feu(SDL_Surface *screen , Objet tab [],float *frame)
{
  
  SDL_BlitSurface(tab[(int)*frame].img,NULL,screen,&(tab[(int)*frame].pos)) ;
  
  if(*frame<=4)
   (*frame)+=0.03 ;
  else 
  (*frame)=1 ;

}

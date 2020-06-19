/**
* @file main.c
* @brief Testing Program
* @author Oumaima
* @version 0.1
* @date Jun 1, 2020
*
* Testing program for AI2
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "AI2.h"

int main()
{
  SDL_Surface *screen=NULL ;
  int running=1,collision,i,temp_prec,temp_actu,test,animation=0 ;
  float D,frame=0 ;


  Objet perso,zombie,tab[4] ;

   SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    
    initialiser (&perso,tab)  ;
    setup (screen,&perso,tab) ;
    
    SDL_EnableKeyRepeat(10, 10);

    while(running){
     deplacement_objet(&perso,&running) ;
     calculer_centre_rayon (&perso,tab) ;
     D=calculer_distance (&perso,tab) ;
     collision=verif_collision (&perso,tab,D ) ;
     if(collision && animation!=1)
     {
      animation=1 ; 

     }
          else if (animation!=1 && collision!=1)
     {
       SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
       SDL_BlitSurface(tab[0].img,NULL,screen,&(tab[0].pos)) ;
       SDL_BlitSurface(perso.img,NULL,screen,&(perso.pos)) ;
       SDL_Flip(screen) ;
     }
          if(animation)
     {
       SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
       annimation_feu(screen ,tab,&frame) ;
       SDL_BlitSurface(perso.img,NULL,screen,&(perso.pos)) ;
       SDL_Flip(screen) ;    
     }
     


   
     


    }
    


    

    return EXIT_SUCCESS;
}


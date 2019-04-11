#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "functions.h"

#define LARGEURECRAN 640
#define HAUTEURECRAN 480
#define TITREECRAN "Ma fenetre SDL"


int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    char fichierSprite[] = "tana.png";
    int nbLigne=1;
    int nbColonne=18;
    int tempsAnimation =100;
    SDL_Rect position = {0,0};
    SDL_Rect * tabSpriteBonhomme = NULL;

    int continuer = 1;
    int i=0;
    SDL_Event event;

    ecran = initEcran(TITREECRAN,LARGEURECRAN , HAUTEURECRAN);
    tabSpriteBonhomme = decoupeSprite(fichierSprite, nbLigne, nbColonne);

blitSpriteSurSurface(ecran,fichierSprite,position,&tabSpriteBonhomme[0]);
  
  while(continuer)
    {
	backgroundColorSurface(ecran, 0, 0, 0);	

blitSpriteSurSurface(ecran,fichierSprite,position,&tabSpriteBonhomme[0]);		
  
        SDL_PollEvent(&event);
	deplacement(&position,event,30, 30, tabSpriteBonhomme, ecran,fichierSprite,nbLigne, nbColonne,tempsAnimation);
        continuer = attendreAvantDeQuitter(event.type);
        
	SDL_Flip(ecran);
	
	
      
        
    }
    SDL_Quit();
    return 0;
}

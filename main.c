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
    SDL_Surface *image; 
  SDL_Surface *image1; 
    SDL_Rect positionecran;
    char fichierSpriteL[] = "tana.png";
    char fichierSpriteR[] = "tana2.png";
    int nbLigne=1;
    int nbColonne=18;
    int tempsAnimation =100;
    SDL_Rect position = {50,250};
    SDL_Rect * tabSpriteBonhommeL = NULL;
    SDL_Rect * tabSpriteBonhommeR = NULL;

    int continuer = 1;
    int i=0;
    SDL_Event event;

    ecran = initEcran(TITREECRAN,LARGEURECRAN , HAUTEURECRAN);
    tabSpriteBonhommeL = decoupeSprite(fichierSpriteL, nbLigne, nbColonne);
    tabSpriteBonhommeR = decoupeSprite(fichierSpriteR, nbLigne, nbColonne);

	image=SDL_LoadBMP("background.bmp");
image1=IMG_Load("image1.png");
SDL_Rect pos_bird;
pos_bird.x=0;
pos_bird.y=200;
	if (image==NULL)
			{
			printf("Unable to load bitmap:%s\n",SDL_GetError());
			return 1;
			}

	positionecran.x=0;
	positionecran.y=0;
	positionecran.w=image->w;
	positionecran.h=image->h;


int vitesse=0, mvt=0;
int l=0,r=0;
  while(continuer)
    {

SDL_BlitSurface(image,NULL,ecran,&positionecran);

if (mvt ==0) blitSpriteSurSurface(ecran,fichierSpriteL,position,&tabSpriteBonhommeL[0]);
		
  
        SDL_PollEvent(&event);

if (pos_bird.x<=0) {r=1; l=0;}
if (pos_bird.x >=500 ) {l=1; r=0;}
if (r==1 && l==0) pos_bird.x+=1;
if(r==0 && l==1) pos_bird.x-=1;

SDL_BlitSurface (image1,NULL,ecran,&pos_bird);

	deplacement(&position,event,&vitesse, 30, tabSpriteBonhommeL,tabSpriteBonhommeR, ecran,fichierSpriteL,fichierSpriteR,nbLigne, nbColonne,tempsAnimation, &mvt);
        continuer = attendreAvantDeQuitter(event.type);
        
	SDL_Flip(ecran);
	
	
      
        
    }
    SDL_Quit();
    return 0;
}


#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "functions.h"


SDL_Surface * initEcran(char * titre, int largeur, int hauteur)
{
    SDL_Surface *ecran = NULL;
    SDL_Init(SDL_INIT_VIDEO);

    
    ecran = SDL_SetVideoMode(largeur, hauteur, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption(titre, NULL);

    return ecran;
}

int attendreAvantDeQuitter(Uint8 typeEvenement)
{
    int continuer = 1 ;
    switch(typeEvenement)
    {
        case SDL_QUIT:
            continuer = 0;break;
        default : break;
    }
    return continuer;
}

void backgroundColorSurface(SDL_Surface * surface, Uint8 rouge, Uint8 vert, Uint8 bleu)
{
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, rouge, vert, bleu));
}

int verifEtatToucheClavier()
{
    Uint8 *keystates = SDL_GetKeyState(NULL);

    if( keystates[SDLK_UP] )
        return SDLK_UP;

    if( keystates[ SDLK_DOWN ] )
        return SDLK_DOWN;

    if( keystates[ SDLK_LEFT ] )
         return SDLK_LEFT;

    if( keystates[ SDLK_RIGHT ] )
        return SDLK_RIGHT;

    return RIEN;
}

void blitImageSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect *position)
{
    SDL_Surface* loadedImage = NULL;
    loadedImage = IMG_Load(fileImage);
    position->h = loadedImage->h;
    position->w = loadedImage->w;
    SDL_BlitSurface(loadedImage, NULL, surfaceBlit, position);
    SDL_FreeSurface(loadedImage);
}

SDL_Rect * decoupeSprite(char * fileSprite, int nbCaseLigne, int nbCaseCol)
{
    SDL_Surface * feuilleDeSprite = NULL;
    SDL_Rect * tabSprite;
    SDL_Rect coupe;
    int i,j;
    int nbCase=0;

    tabSprite = malloc((nbCaseCol*nbCaseLigne)*sizeof(SDL_Rect));
    feuilleDeSprite = IMG_Load(fileSprite);
    coupe.h = feuilleDeSprite->h/nbCaseLigne;
    coupe.w =feuilleDeSprite->w/nbCaseCol;

    for(i=0; i < nbCaseLigne; i++)
    {
        coupe.y = coupe.h*i;
        for(j=0;j<nbCaseCol; j++)
        {
            coupe.x = coupe.w*j;
            tabSprite[nbCase] = coupe;
            nbCase++;
        }
    }
    SDL_FreeSurface(feuilleDeSprite);
    return tabSprite;
}

void blitSpriteSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect position, SDL_Rect * clip)
{
    SDL_Surface* loadedImage = NULL;
    loadedImage = IMG_Load(fileImage);
    SDL_BlitSurface(loadedImage, clip, surfaceBlit, &position);
    SDL_FreeSurface(loadedImage);
}

Mix_Music* jouerSon(char *fichierSon)
{
    Mix_Music *music = NULL;
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096);

    music = Mix_LoadMUS(fichierSon);
    Mix_PlayMusic( music, -1 );

    return music;
}

void attendreTemps(int millisecondes)
{
    int startTicks = SDL_GetTicks();

    while((SDL_GetTicks() - startTicks) < millisecondes)
    {
        SDL_Delay(1);
    }
}

void deplacement(SDL_Rect * pos, SDL_Event event, int vitesse_x, int vitesse_y, SDL_Rect * clip, SDL_Surface *ecran, char * fichierSprite, int nbLigne, int nbColonne, int tempsAnimation)
{
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP: if(pos->y>0){ pos->y -= vitesse_y / 2;} break;
            case SDLK_DOWN: if(pos->y<340){ pos->y += vitesse_y / 2;} break;
            case SDLK_LEFT: pos->x -= vitesse_x / 2;if(pos->x<0) pos->x=-10;
				
				animerSprite(clip, ecran, fichierSprite, *pos, nbLigne, nbColonne, tempsAnimation); 
	 			break;
            case SDLK_RIGHT: pos->x += vitesse_x / 2;if(pos->x>540) pos->x=540;
				
				animerSprite(clip, ecran,fichierSprite, *pos, nbLigne, nbColonne, tempsAnimation); 		
				break;
            default: break;
        }
    }
}


void animerSprite(SDL_Rect * clip, SDL_Surface * surfaceBlit, char * fichierSprite, SDL_Rect position, int nbLigne, int nbColonne, int tempsAnimation)
{
    static int i = 0;
    blitSpriteSurSurface(surfaceBlit, fichierSprite, position, &clip[i]);
    i++;
    if(i==(nbLigne*nbColonne))
        i=0;
    attendreTemps(tempsAnimation);
}

 


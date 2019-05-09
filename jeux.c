#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_image.h> 
#define SCREEN_W 800
#define SCREEN_H 400

int main()
{
    Mix_Music *musique; 
    int continuer = 1; 
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *perso = NULL; 

    SDL_Event event; 

    SDL_Rect positionperso; 
    SDL_Rect positionFond; 
    SDL_Rect camera;
    camera.x=0;
    camera.y=0;
    camera.h=SCREEN_H;
    camera.w=SCREEN_W;

    positionFond.x = 0; 
    positionFond.y = 0; 

    positionperso.x = 0; 
    positionperso.y = 55; 

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO); 

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) == -1) 
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
        exit(EXIT_FAILURE); 
    }

    SDL_WM_SetCaption("mohamed belaid", NULL);
   
    ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    if (ecran == NULL) 
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf ("%s",Mix_GetError());
    }

    Mix_VolumeMusic(MIX_MAX_VOLUME / 1); 
    musique =Mix_LoadMUS("music.mp3");
    Mix_PlayMusic(musique,-1);

    perso = IMG_Load("detective.png");
    SDL_SetColorKey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format, 255, 255, 255));


    imageDeFond = IMG_Load("back.png"); 
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    SDL_BlitSurface(perso, NULL, ecran, &positionperso);
    SDL_Flip(ecran);
    SDL_EnableKeyRepeat(100,100); 

    while(continuer) 
    {
       

        SDL_WaitEvent(&event); 
        switch(event.type)
        {
        case SDL_QUIT: 
            continuer = 0; 
            break;

        case SDL_KEYDOWN: 
            switch(event.key.keysym.sym)
            {

            case SDLK_ESCAPE: 
                continuer = 0;
                break;

            case SDLK_LEFT: // Flèche gauche

                positionperso.x -= 20; 
                camera.x -= 20;

                if(positionperso.x<0) 
                {
                    positionperso.x=0;
                    camera.x=0;
                }
                break;

            case SDLK_RIGHT: // Flèche droite

                positionperso.x += 20; 
                 camera.x += 20;
                if(positionperso.x>1600)
                {
                    positionperso.x=1600;
                    camera.x=1600;
                }
                break;

            case SDLK_DOWN: // Flèche bas

                positionperso.y += 20; 
                if(positionperso.y>255)
                {
                    positionperso.y=255;
                }
                break;

            case SDLK_UP: // Flèche haut

                positionperso.y -= 20; 
                if(positionperso.y<205)
                {
                    positionperso.y=205;
                }
                break;
}
break;



            case SDL_MOUSEBUTTONDOWN:

                if(event.button.button==SDL_BUTTON_LEFT)
                {
                    positionperso.x -= 20;      
                    camera.x -= 20;   
                if(positionperso.x<0) // fixation de la Position 
                {
                    positionperso.x=0;
                    camera.x=0;
                }  
             
                }
                if(event.button.button==SDL_BUTTON_RIGHT)
                {
                    positionperso.x += 20;
                    camera.x += 20;
                if(positionperso.x>1600)// fixation de la Position
                {
                    positionperso.x=1600;
                    camera.x=1600;
                }

                }
                break;  

            }


            if(camera.x>1600-800)
            {
             camera.x=800; 
             positionperso.x=800-72;
            }

            SDL_BlitSurface(imageDeFond, &camera, ecran, &positionFond); 

                 
            SDL_BlitSurface(perso, NULL, ecran, &positionperso); 


            SDL_Flip(ecran);   

        }
    
    SDL_FreeSurface(imageDeFond); 
    SDL_FreeSurface(perso); 
    Mix_FreeMusic(musique); 
    Mix_CloseAudio(); 
    SDL_Quit(); 
    return EXIT_SUCCESS; 
}





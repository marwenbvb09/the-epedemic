#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>/* Notre bibliotheque principale */
#include <SDL/SDL_mixer.h> /* Inclusion du header de SDL_mixer (pour les fichier audio) */
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (pourafficherles images) */
#define SCREEN_W 800
#define SCREEN_H 400

int main()
{
    Mix_Music *musique; //creation pointeur
    int continuer = 1; /* Notre booléen pour la boucle */
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *perso = NULL; // Le pointeur qui va stocker la surface de l'écran

    SDL_Event event; /* La variable contenant l'événement */

    SDL_Rect positionperso; // il définit une zone rectangulaire de pixels pour le perso
    SDL_Rect positionFond; // il définit une zone rectangulaire de pixels pour le background
    SDL_Rect camera;
    camera.x=0;
    camera.y=0;
    camera.h=SCREEN_H;
    camera.w=SCREEN_W;

    positionFond.x = 0; // Les coordonnées de la background pour le x
    positionFond.y = 0; // Les coordonnées de la background pour le y

    positionperso.x = 0; // Les coordonnées de la personnage pour le x
    positionperso.y = 255; // Les coordonnées de la personnage pour le y

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO); // Chargement de la vidéo et de l'audio renvoie -1 en cas d'erreur et 0 si tout s'est bien passé

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) == -1) // Démarrage de la SDL. Si erreur :
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }

    SDL_WM_SetCaption("Yassin_Daboussi", NULL);
    //SDL_HWSURFACE les données seront chargées dans la mémoire vidéo et SDL_RESIZABLE pour Redimensionner la fenêtre
    ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_RESIZABLE);
    if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)//Initialisation de l'API Mixer
    {
        printf ("%s",Mix_GetError());
    }

    Mix_VolumeMusic(MIX_MAX_VOLUME / 1); //Mettre le volume à 1 Pour la moitié remplacer Par 2
    musique =Mix_LoadMUS("music.mp3");//chargement de la musique
    Mix_PlayMusic(musique,-1);//(lancer la music)&jouer infiniment la musique

    perso = IMG_Load("detective.png");/* Chargement d'une image Png dans une surface */
    SDL_SetColorKey(perso, SDL_SRCCOLORKEY, SDL_MapRGB(perso->format, 255, 255, 255));/* On rend le blanc derrière perso transparent : */


    imageDeFond = SDL_LoadBMP("background.bmp"); /* Chargement d'une image Bitmap dans une surface */
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);/* coller background dans l'écran */

    SDL_BlitSurface(perso, NULL, ecran, &positionperso);/* coller perso dans l'écran */
    SDL_Flip(ecran); /* On met à jour l'affichage : */

    SDL_EnableKeyRepeat(100,100); /*Activation de la répétition des touches  100 ms */

    while(continuer)  /* TANT QUE la variable ne vaut pas 0 */
    {
        /* Traitement des événements */

        SDL_WaitEvent(&event); /* Récupération de l'événement dans event */
        switch(event.type) /* Test du type d'événement */
        {
        case SDL_QUIT: /* Si c'est un événement de type "Quitter" */
            continuer = 0; /* On met le booléen à 0, donc la boucle va s'arrêter */
            break;

        case SDL_KEYDOWN: //quand une touche du clavier est enfoncée
            switch(event.key.keysym.sym)
            {

            case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                continuer = 0;
                break;

            case SDLK_LEFT: // Flèche gauche

                positionperso.x -= 20; //ywa5er par 20 pixel
                camera.x -= 20;

                if(positionperso.x<0) // fixation de la Position 
                {
                    positionperso.x=0;
                    camera.x=0;
                }
                break;

            case SDLK_RIGHT: // Flèche droite

                positionperso.x += 20; //y9adem par 20 pixel
                 camera.x += 20;
                if(positionperso.x>1600)// fixation de la Position
                {
                    positionperso.x=1600;
                    camera.x=1600;
                }
                break;

            case SDLK_DOWN: // Flèche bas

                positionperso.y += 20; //yahbet par 20 pixel
                if(positionperso.y>255)// fixation de la Position
                {
                    positionperso.y=255;
                }
                break;

            case SDLK_UP: // Flèche haut

                positionperso.y -= 20; //yatle3 par 20 pixel
                if(positionperso.y<205)// fixation de la Position
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

            SDL_BlitSurface(imageDeFond, &camera, ecran, &positionFond);/* coller background dans l'écran */

                 
            SDL_BlitSurface(perso, NULL, ecran, &positionperso); /* On place perso à sa nouvelle position */


            SDL_Flip(ecran);   /* On met à jour l'affichage : */

        }
    
    SDL_FreeSurface(imageDeFond); //libération de la mémoire
    SDL_FreeSurface(perso); //libération de la mémoire
    Mix_FreeMusic(musique); //liberation de la musique
    Mix_CloseAudio(); //fermeture de l'API(on libere le materiel)
    SDL_Quit(); // Arrêt de la SDL (libération de la mémoire).

    return EXIT_SUCCESS; //Fermeture du programme
}





#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#define RIEN 0

int attendreAvantDeQuitter(Uint8 typeEvenement);
SDL_Surface * initEcran(char * titre, int largeur, int hauteur);
void backgroundColorSurface(SDL_Surface * surface, Uint8 rouge, Uint8 vert, Uint8 bleu);

int verifEtatToucheClavier();
void blitImageSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect *position);
SDL_Rect * decoupeSprite(char * fileSprite, int nbCaseLigne,int nbCaseCol);
void blitSpriteSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect position, SDL_Rect * clip);
Mix_Music* jouerSon(char *fichierSon);
void attendreTemps(int millisecondes);
void deplacement(SDL_Rect * pos, SDL_Event event, int vitesse_x, int vitesse_y, SDL_Rect * clip, SDL_Surface *ecran, char * fichierSprite, int nbLigne, int nbColonne, int tempsAnimation);
int testCollision(SDL_Rect obj1, SDL_Rect obj2, int * typeCollision);
void deplacementAutorise(int typeCol, SDL_Rect * pos1, SDL_Event event, int vit_x, int vit_y);
void animerSprite(SDL_Rect * clip, SDL_Surface * surfaceBlit, char * fichierSprite, SDL_Rect position, int nbLigne, int nbColonne, int tempsAnimation);
#endif // FUNCTIONS_H


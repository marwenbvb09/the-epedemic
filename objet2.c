
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include <time.h>

void background(SDL_Surface *image, SDL_Surface *screen, SDL_Rect positionecran, SDL_Surface *button, SDL_Event event);
int main(int argc, char *argv[])
{

SDL_Surface *screen;
SDL_Surface *image;
SDL_Event event;
SDL_Rect positionecran;
SDL_Surface *coeur;
SDL_Surface *coeur1;
SDL_Surface *coeur2;
SDL_Surface *score;
SDL_Surface *enemy2;
SDL_Surface *coins;

SDL_Rect PositionEnemy2;
SDL_Rect PositionCoeur;
SDL_Rect PositionScore;
SDL_Rect PositionCoeur1;
SDL_Rect PositionCoeur2;
SDL_Rect PositionCoins;
if (SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(600,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


if (screen==NULL)
{
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
}


image = IMG_Load("ynaan.jpg");
if (image==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;
}

coeur=IMG_Load("coeur.png");
coeur1=IMG_Load("coeur.png");
coeur2=IMG_Load("coeur.png");
if (coeur==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;
}



coins=IMG_Load("coins.png");


enemy2 = IMG_Load("enemy2.png");
if (enemy2==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;
}

score=IMG_Load("0.png");

PositionEnemy2.x = 20;
PositionEnemy2.y = 225;

PositionCoeur.x = 550;
PositionCoeur.y = 31;
PositionCoins.x = 550;
PositionCoins.y = 78;
positionecran.x = 0;
positionecran.y = 0;
positionecran.w = image->w;
positionecran.h = image->h;

PositionCoeur1.x = 500;
PositionCoeur1.y = 31;
PositionCoeur2.x = 450;
PositionCoeur2.y = 31;

PositionScore.x = 535;
PositionScore.y = 85;

int done=1;
while (done)
{

SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_BlitSurface(enemy2,NULL,screen,&PositionEnemy2);
SDL_BlitSurface(coeur,NULL,screen,&PositionCoeur);
SDL_BlitSurface(coeur1,NULL,screen,&PositionCoeur1);
SDL_BlitSurface(coeur2,NULL,screen,&PositionCoeur2);



SDL_BlitSurface(coins,NULL,screen,&PositionCoins);

SDL_BlitSurface(score,NULL,screen,&PositionScore);




SDL_Flip(screen);
while (SDL_PollEvent(&event))
{
switch (event.type)
{

 case SDL_QUIT:
done=0;
break;
case SDL_MOUSEBUTTONDOWN:
{
    switch (event.button.button)
    {
case SDL_BUTTON_LEFT:
PositionEnemy2.x -=50;

if(PositionEnemy2.x<0) 
{
  PositionEnemy2.x=0;
  
}
break;

case SDL_BUTTON_RIGHT:
PositionEnemy2.x +=50;

if(PositionEnemy2.x>1200) 
{
  PositionEnemy2.x=1200;
  
}
}
}
case SDL_KEYDOWN:
{

switch(event.key.keysym.sym)
{
case  SDLK_ESCAPE:
done = 1;
break;
case SDLK_LEFT:
PositionEnemy2.x -= 15;
PositionEnemy2.x -=15;

if(PositionEnemy2.x<0) 
{
  PositionEnemy2.x=0;
 
}
break;
case SDLK_RIGHT:
PositionEnemy2.x += 15;
PositionEnemy2.x +=15;

if(PositionEnemy2.x>1200) 
{
  PositionEnemy2.x=1200;

}
break;
case SDLK_UP:
PositionEnemy2.y -=35;
PositionEnemy2.x +=35;
break;
case SDLK_DOWN:
PositionEnemy2.y += 15;
}
}
break;
case SDL_KEYUP:
{
switch(event.key.keysym.sym)
{


case SDLK_UP:

if (PositionEnemy2.y < 220)
PositionEnemy2.y += 35;


break;
case SDLK_DOWN:
if (PositionEnemy2.y > 220)
PositionEnemy2.y -= 15;

}
}
}
}
}


SDL_FreeSurface(image);
SDL_FreeSurface(coeur);
SDL_FreeSurface(coeur1);
SDL_FreeSurface(coeur2);

SDL_FreeSurface(coins);


SDL_FreeSurface(enemy2);

return 0;
}



#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include <time.h>
void die();
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
SDL_Surface *pomme;

SDL_Surface *score;
SDL_Surface *enemy2;

SDL_Surface *coins;

SDL_Surface *coins5;
SDL_Surface *coins1;
SDL_Surface *trap;
SDL_Surface *trap1;
SDL_Surface *trap2;
SDL_Surface *trap3;

int a=200;
int b=300;
int c=420;
int d=450;
int x=500;
int y=600;
int n=120;
int z=150;
int e=30;
int f=100;
int g=250;
int h=300;
int i=300;
int j=350;
int w=350;
int m=400;
SDL_Rect PositionEnemy2;
SDL_Rect PositionCoeur;
SDL_Rect PositionScore;
SDL_Rect PositionCoeur1;
SDL_Rect PositionCoeur2;
SDL_Rect PositionPomme;
SDL_Rect Ptrap;
SDL_Rect Ptrap1;
SDL_Rect Ptrap2;
SDL_Rect Ptrap3;

SDL_Rect PositionCoins5;
SDL_Rect PositionCoins1;
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

pomme=IMG_Load("pomme.png");
if (pomme==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;
}

coins=IMG_Load("coins.png");
coins5=IMG_Load("coins.png");
coins1=IMG_Load("coins.png");

if (coins==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;
}
trap = IMG_Load("trap.png");
trap1 = IMG_Load("trap.png");
trap2 = IMG_Load("trap.png");
trap3 = IMG_Load("trap.png");



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
PositionPomme.x = 237;
PositionPomme.y = 300;
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




PositionCoins5.x = c;
PositionCoins5.y = 300;

PositionCoins1.x = n;
PositionCoins1.y = 300;

Ptrap.x=e;
Ptrap.y=300;

Ptrap1.x=g;
Ptrap1.y=300;


Ptrap2.x=i;
Ptrap2.y=300;

Ptrap3.x=w;
Ptrap3.y= 300;




int done=1;
while (done)
{

SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_BlitSurface(enemy2,NULL,screen,&PositionEnemy2);
SDL_BlitSurface(coeur,NULL,screen,&PositionCoeur);
SDL_BlitSurface(coeur1,NULL,screen,&PositionCoeur1);
SDL_BlitSurface(coeur2,NULL,screen,&PositionCoeur2);
SDL_BlitSurface(trap,NULL,screen,&Ptrap);
SDL_BlitSurface(trap1,NULL,screen,&Ptrap1);
SDL_BlitSurface(trap2,NULL,screen,&Ptrap2);
SDL_BlitSurface(trap3,NULL,screen,&Ptrap3);
if ((PositionEnemy2.x>e)&&(PositionEnemy2.x<f))
{
coeur2=NULL;
trap=IMG_Load("cls.png");
}
if ((PositionEnemy2.x>g)&&(PositionEnemy2.x<h))
{
coeur1=NULL;
trap1=IMG_Load("cls.png");
}
if ((PositionEnemy2.x>i)&&(PositionEnemy2.x<j))
{
coeur=NULL;
trap2=IMG_Load("cls.png");
}
if ((PositionEnemy2.x>w)&&(PositionEnemy2.x<m))
{
coeur2=NULL;
trap3=IMG_Load("cls.png");
}
if((coeur2==NULL)&&(coeur1==NULL)&&(coeur==NULL))
{
die();
}
if((PositionEnemy2.x>a)&&(PositionEnemy2.x<b))
{
coeur2=IMG_Load("coeur.png");
pomme=NULL;
}

SDL_BlitSurface(pomme,NULL,screen,&PositionPomme);
SDL_BlitSurface(coins,NULL,screen,&PositionCoins);
SDL_BlitSurface(coins1,NULL,screen,&PositionCoins1);
SDL_BlitSurface(coins5,NULL,screen,&PositionCoins5);
SDL_BlitSurface(score,NULL,screen,&PositionScore);
 if ((PositionEnemy2.x>c)&&(PositionEnemy2.x<d))
{
score=IMG_Load("2.png");
coins5=NULL;
}
 if ((PositionEnemy2.x>n)&&(PositionEnemy2.x<z))
{
score=IMG_Load("1.png");
coins1=NULL;
}




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
SDL_FreeSurface(pomme);
SDL_FreeSurface(coins);

SDL_FreeSurface(coins5);
SDL_FreeSurface(coins1);
SDL_FreeSurface(enemy2);
SDL_FreeSurface(trap);
SDL_FreeSurface(trap1);
SDL_FreeSurface(trap2);
SDL_FreeSurface(trap3);
return 0;
}
void die()
{
SDL_Surface *gover;
SDL_Surface *screen;
SDL_Rect over;

screen = SDL_SetVideoMode(640,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
over.x=0;
over.y=0;

SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
SDL_Flip(screen);
gover=IMG_Load("fff.png");

SDL_BlitSurface(gover,NULL,screen,&over);
SDL_Flip(screen);
SDL_Delay(3000);
return;
}


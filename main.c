#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include <time.h> 
#include <unistd.h>
#include "fonction.h"

void generatialea(int *a)
{srand(time(NULL));
*a=1+rand()%4;
}

void enigme4(SDL_Surface *screen,int *rep,int a)
{
  
SDL_Surface *enigme = NULL;
 
if(a==1)
{
 enigme = IMG_Load("enigme4.jpg");
}
else if(a==2)
{enigme = IMG_Load("enigme2.png");
}
else if(a==3)
{enigme = IMG_Load("enigme3.png");
}
else
{enigme = IMG_Load("enigme1.png");}


SDL_Rect p_enigme4;

p_enigme4.x = 0;
p_enigme4.y = 0;



SDL_Event event4;
int conti = 1;

while(conti)
{
SDL_BlitSurface(enigme,NULL,screen,&p_enigme4);
SDL_Flip(screen);
SDL_WaitEvent(&event4);

switch(event4.type)
{


case SDL_MOUSEBUTTONUP:
if(event4.button.button==SDL_BUTTON_LEFT)
{
if(a==1){
if(event4.button.x>380 && event4.button.x<579 && event4.button.y>355 && event4.button.y<399 )
{
*rep=1;
conti=0;
}
else
{
*rep=0;
conti=0;
}
}
else if(a==2){
if(event4.button.x>0 && event4.button.x<191 && event4.button.y>323 && event4.button.y<425 )
{
*rep=1;
conti=0;
}
else
{
*rep=0;
conti=0;
}
}
else if(a==3){
if(event4.button.x>0 && event4.button.x<203 && event4.button.y>395 && event4.button.y<458 )
{
*rep=1;
conti=0;
}
else
{
*rep=0;
conti=0;
}
}
else if(a==4){
if(event4.button.x>243 && event4.button.x<398 && event4.button.y>312 && event4.button.y<387 )
{
*rep=1;
conti=0;
}
else
{
*rep=0;
conti=0;
}
}

}
break;



}
}
}
void gamover(SDL_Surface *screen)
{SDL_Rect over;
over.x=0;
over.y=0;
SDL_Surface *gover;
gover=IMG_Load("gover.png");
SDL_BlitSurface(gover,NULL,screen,&over);

SDL_Flip(screen);

SDL_Delay(3000);
}

int main(void)
{
int a,rep=-1;
SDL_Surface *enigme;
SDL_Surface *screen;
SDL_Init(SDL_INIT_VIDEO);
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{printf("unable to set video mode SDL : %s\n",SDL_GetError());
return 1;
}

     
    screen = SDL_SetVideoMode(640,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (!screen){
printf("unable to set 600x400 video: %s\n",SDL_GetError());
                                         return (-1);
              }

SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
  SDL_Flip(screen);
    




generatialea(&a);

enigme4(screen,&rep,a);
if(rep==0)
{
gamover(screen);

}

return 0;
}


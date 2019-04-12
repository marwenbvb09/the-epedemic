#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include "SDL/SDL_mixer.h"
#include <time.h>



void background(SDL_Surface *image, SDL_Surface *screen, SDL_Rect positionecran, SDL_Surface *button, SDL_Event event);

void Options(SDL_Surface *button, SDL_Event event, SDL_Surface *button2, SDL_Rect posbut, SDL_Rect posbut2, SDL_Surface *screen, SDL_Surface *image, SDL_Rect positionecran);



int main(int argc, char *argv[])
{
SDL_Surface *screen;
SDL_Surface *image;
SDL_Surface *button;
SDL_Surface *Button;
SDL_Surface *button1;
SDL_Surface *button2;
SDL_Surface *Button2;
SDL_Surface *text;
SDL_Surface *text1;
SDL_Surface *text2;
SDL_Surface *logo;
SDL_Rect positionecran;
SDL_Rect posbut;
SDL_Rect posbut1;
SDL_Rect posbut2;
SDL_Rect postext;
SDL_Rect postext1;
SDL_Rect postext2;
SDL_Rect poslogo;
SDL_Event event;

int n=1;
int a=0;
int v=0;
char pause;

if (SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(1275,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


if (screen==NULL)
{
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
}



image = IMG_Load("mountain.jpg");
if (image==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;
}

logo = IMG_Load("logo.png");
if(logo==NULL)
{
printf("unable to load bitmap: %s\n",IMG_GetError());
return 1;
}

button = IMG_Load("button.png");
if (button==NULL)
{
printf("Unable to load button: %s\n",IMG_GetError());
return 1;
}


button1 = IMG_Load("button.png");
if (button1==NULL)
{
printf("Unable to load button1: %s\n",IMG_GetError());
return 1;
}

button2 = IMG_Load("button.png");
if (button2==NULL)
{
printf("Unable to load detective: %s\n",IMG_GetError());
return 1;
}

text = IMG_Load("PLAY.png");
if (text==NULL)
{
printf("Unable to load text: %s\n",IMG_GetError());
return 1;
}

text1 = IMG_Load("SETTINGS.png");
if (text1==NULL)
{
printf("Unable to load text1: %s\n",IMG_GetError());
return 1;
}

text2 = IMG_Load("EXIT.png");
if (text2==NULL)
{
printf("Unable to load text2: %s\n",IMG_GetError());
return 1;
}


postext.x = 660;
postext.y = 250;
postext1.x = 625;
postext1.y = 325;
postext2.x = 665;
postext2.y = 400;

poslogo.x=450;
poslogo.y=0;

posbut.x = 600;
posbut.y = 400;
posbut1.x = 600;
posbut1.y = 325;
posbut2.x = 600;
posbut2.y = 250;
Uint32 colorkey = SDL_MapRGB(button->format, 0xFF, 0xFF , 0xFF);
SDL_SetColorKey(button,SDL_SRCCOLORKEY, colorkey);



positionecran.x = 0;
positionecran.y = 0;
positionecran.w = image->w;
positionecran.h = image->h;



if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}

Mix_Music *music;
music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-1);


int done=1;
while (done)
{

SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_BlitSurface(button,NULL,screen,&posbut);
SDL_BlitSurface(button1,NULL,screen,&posbut1);
SDL_BlitSurface(button2,NULL,screen,&posbut2);
SDL_BlitSurface(text,NULL,screen,&postext);
SDL_BlitSurface(text1,NULL,screen,&postext1);
SDL_BlitSurface(text2,NULL,screen,&postext2);
SDL_BlitSurface(logo,NULL,screen,&poslogo);


SDL_Flip(screen);

while (SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_QUIT:
done=0;
case SDL_MOUSEMOTION:
            {
		  if((event.motion.x > 600) && (event.motion.x <800) &&(event.motion.y >250) && (event.motion.y <350)&&(a==0))
	          { 
                    button2 =IMG_Load("cbutt1.png");
                    button1 = IMG_Load("button.png");
                    button1 = IMG_Load("button.png");
                  }
                 else if((event.motion.x > 600) && (event.motion.x <800) &&(event.motion.y >325) && (event.motion.y <425) && (a==0))
                  { 
                   button1 = IMG_Load("cbutt1.png");
                   button2 =IMG_Load("button.png");
                   button = IMG_Load("button.png");
                  }
                  else if((event.motion.x > 600) && (event.motion.x <800) &&(event.motion.y >400) && (event.motion.y <500)&&(a==0))
                  {
                   button1 = IMG_Load("button.png");
                   button2 =IMG_Load("button.png");
                   button = IMG_Load("cbutt1.png");
                  }
                  else if((a==0))
                  { 
                    button2 =IMG_Load("button.png");
                    button1 = IMG_Load("button.png");
                    button1 = IMG_Load("button.png");
                  }
}
break;
case SDL_MOUSEBUTTONUP:
	   {
	if(event.button.button == SDL_BUTTON_LEFT)
		{
                     if((event.motion.x > 600) && (event.motion.x <800) &&(event.motion.y >250) && (event.motion.y <350) && (v==0))
	             {
                       image = IMG_Load("ynaan.jpg");
                       button=NULL;
                       button1=NULL;
                       button2=NULL;
                       text=NULL;
                       text1=NULL;
                       text2=NULL;
                       logo=NULL;
                       a=1;
                       background(image, screen, positionecran, button, event);
                     }

                     if((event.motion.x > 600) && (event.motion.x <800) &&(event.motion.y >325) && (event.motion.y <425))
	             { 
                       image = IMG_Load("mountain.jpg");
                       text=NULL;
                       text1=NULL;
                       text2=NULL;
                       button1=NULL;
                       a=1;
                       v=1;
                       Options(button, event, button2, posbut,posbut2, screen,image, positionecran);
                       
                     }
                     else if((event.motion.x > 600) && (event.motion.x <800) &&(event.motion.y >400) && (event.motion.y <500)&&(a==0))
                  {
                  return 0;
                  }
}
}
}
}
}



Mix_FreeMusic(music);
SDL_FreeSurface(image);
SDL_FreeSurface(button);
SDL_FreeSurface(button1);
SDL_FreeSurface(button2);
SDL_FreeSurface(text);
SDL_FreeSurface(text1);
SDL_FreeSurface(text2);
SDL_FreeSurface(logo);
pause = getchar();

return 0;
}




void background(SDL_Surface *image, SDL_Surface *screen, SDL_Rect positionecran, SDL_Surface *button, SDL_Event event)
{
SDL_Surface *enemy2;
SDL_Rect PositionEnemy2;

int r;
int x=300;
int y=500;
int diff = y-x;

srand(time(NULL));

r=rand()%(diff+1)+x;

screen=SDL_SetVideoMode(600,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

enemy2 = IMG_Load("enemy2.png");



PositionEnemy2.x = r;
PositionEnemy2.y = 225;
positionecran.x = 0;
positionecran.y = 0;
positionecran.w = image->w;
positionecran.h = image->h;

SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_BlitSurface(enemy2,NULL,screen,&PositionEnemy2);
SDL_Flip(screen);

int done=1;
while (done)
{



while (SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_QUIT:
done=0;
break;

}
}
}

SDL_FreeSurface(image);
SDL_FreeSurface(enemy2);


}








void Options(SDL_Surface *button, SDL_Event event, SDL_Surface *button2, SDL_Rect posbut2, SDL_Rect posbut, SDL_Surface *screen, SDL_Surface *image,SDL_Rect positionecran)
{

SDL_Surface *text;
SDL_Surface *text1;
SDL_Rect postext;
SDL_Rect postext1;
int s=0;
int p=0;

screen=SDL_SetVideoMode(1275,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

text = IMG_Load("Volume.png");
text1 = IMG_Load("diff.png");

int done=1;
while (done)
{
postext.x = 660;
postext.y = 250;
postext1.x = 665;
postext1.y = 400;

positionecran.x = 0;
positionecran.y = 0;
positionecran.w = image->w;
positionecran.h = image->h;

SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_BlitSurface(button,NULL,screen,&posbut);
SDL_BlitSurface(button2,NULL,screen,&posbut2);
SDL_BlitSurface(text,NULL,screen,&postext);
SDL_BlitSurface(text1,NULL,screen,&postext1);
SDL_Flip(screen);



while (SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_QUIT:
done=0;
case SDL_MOUSEMOTION:
            {
		  if((event.motion.x > 600) && (event.motion.x <800) &&(event.motion.y >250) && (event.motion.y <350)&&(s==0))
	          { 
                    button2 =IMG_Load("button.png");
                    button = IMG_Load("cbutt1.png");
                  }
                  else if((event.motion.x > 600) && (event.motion.x <800) &&(event.motion.y >400) && (event.motion.y <500)&&(s==0))
                  {
                   button2 =IMG_Load("cbutt1.png");
                   button = IMG_Load("button.png");
                  }
                  else if((s==0))
                  { 
                    button2 =IMG_Load("button.png");
                    button = IMG_Load("button.png");
                  }
}
break;
case SDL_MOUSEBUTTONUP:
	   {
	if(event.button.button == SDL_BUTTON_LEFT)
		{
                     if((event.motion.x > 600) && (event.motion.x <800) &&(event.motion.y >250) && (event.motion.y <350) && (p==0))
	             {
                       return;
                     }

                    /* if((event.motion.x > 600) && (event.motion.x <800) &&(event.motion.y >325) && (event.motion.y <425))
	             { 
                       s=1;
                       p=1;
                     }*/
}
}
}
}

}
SDL_FreeSurface(button);
SDL_FreeSurface(button2);
SDL_FreeSurface(text);
SDL_FreeSurface(text1);

}








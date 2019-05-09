#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include "SDL/SDL_mixer.h"
#include <time.h>
#define SCREEN_W 600
#define SCREEN_H 400



void background(SDL_Surface *image, SDL_Surface *screen, SDL_Rect positionecran, SDL_Surface *button, SDL_Event event);

void Options(SDL_Surface *button, SDL_Event event, SDL_Surface *button2, SDL_Rect posbut, SDL_Rect posbut2, SDL_Surface *screen, SDL_Surface *image, SDL_Rect positionecran,Mix_Music *music);

void enigme();


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
SDL_Surface *arrow;
SDL_Rect positionecran;
SDL_Rect posbut;
SDL_Rect posbut1;
SDL_Rect posbut2;
SDL_Rect postext;
SDL_Rect postext1;
SDL_Rect postext2;
SDL_Rect poslogo;
SDL_Rect posarrow;
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
screen=SDL_SetVideoMode(1275,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);


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

arrow=IMG_Load("arrow.png");


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
posarrow.x = 550;
posarrow.y=250;
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
SDL_BlitSurface(arrow,NULL,screen,&posarrow);


SDL_Flip(screen);

while (SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_QUIT:
done=0;
case SDL_KEYDOWN:
{

switch(event.key.keysym.sym)
{
case SDLK_DOWN:
posarrow.y += 75;
if(posarrow.y>400)
{
posarrow.y = 400;
}
break;
case SDLK_UP:
posarrow.y -= 75;
if(posarrow.y<250)
{
posarrow.y = 250;
}
break;
case SDLK_KP_ENTER:
if(posarrow.y==250)
{
background(image, screen, positionecran, button, event);
}
if(posarrow.y==325)
{
Options(button, event, button2, posbut,posbut2, screen,image, positionecran, music);
}
if(posarrow.y==400)
{
return 0;
}
break;
}
}
break;
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
                       Options(button, event, button2, posbut,posbut2, screen,image, positionecran,music);
                       
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
SDL_FreeSurface(arrow);
pause = getchar();

return 0;
}




void background(SDL_Surface *image, SDL_Surface *screen, SDL_Rect positionecran, SDL_Surface *button, SDL_Event event)
{
SDL_Surface *coeur;
SDL_Surface *coeur1;
SDL_Surface *coeur2;
SDL_Surface *pomme;

SDL_Surface *score;
SDL_Surface *enemy2;

SDL_Surface *coins;

SDL_Surface *coins5;

SDL_Surface *box;


int a=200;
int b=300;
int c=400;
int d=450;
int x=500;
int y=600;
SDL_Rect PositionEnemy2;
SDL_Rect PositionCoeur;
SDL_Rect PositionScore;
SDL_Rect PositionCoeur1;
SDL_Rect PositionCoeur2;
SDL_Rect PositionPomme;
SDL_Rect camera;
SDL_Rect Pbox;



SDL_Rect PositionCoins5;
SDL_Rect PositionCoins;
if (SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL: %s\n",SDL_GetError());
}
screen=SDL_SetVideoMode(SCREEN_W,SCREEN_H,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


if (screen==NULL)
{
printf("Unable to set video mode: %s\n",SDL_GetError());

}


image = IMG_Load("ynaan.jpg");
if (image==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());

}

coeur=IMG_Load("coeur.png");
coeur1=IMG_Load("coeur.png");
coeur2=NULL;
if (coeur==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());

}

pomme=IMG_Load("pomme.png");
if (pomme==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());

}

coins=IMG_Load("coins.png");

coins5=IMG_Load("coins.png");

if (coins==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());

}




enemy2 = IMG_Load("enemy2.png");
if (enemy2==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());

}

score=IMG_Load("0.png");

box=IMG_Load("torch.png");

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


camera.x=0;
camera.y=0;
camera.h=SCREEN_H;
camera.w=SCREEN_W;

PositionCoins5.x = c;
PositionCoins5.y = 300;

Pbox.x = 550;
Pbox.y = 250;




int done=1;
while (done)
{
SDL_BlitSurface(image,&camera,screen,&positionecran);
SDL_BlitSurface(enemy2,NULL,screen,&PositionEnemy2);
SDL_BlitSurface(coeur,NULL,screen,&PositionCoeur);
SDL_BlitSurface(coeur1,NULL,screen,&PositionCoeur1);
SDL_BlitSurface(coeur2,NULL,screen,&PositionCoeur2);
SDL_BlitSurface(box,NULL,screen,&Pbox);
if((PositionEnemy2.x>a)&&(PositionEnemy2.x<b))
{
coeur2=IMG_Load("coeur.png");
pomme=NULL;
}
if(PositionEnemy2.x==500)
{
enigme();
return;
}
SDL_BlitSurface(pomme,NULL,screen,&PositionPomme);
SDL_BlitSurface(coins,NULL,screen,&PositionCoins);

SDL_BlitSurface(coins5,NULL,screen,&PositionCoins5);
SDL_BlitSurface(score,NULL,screen,&PositionScore);
 if ((PositionEnemy2.x>c)&&(PositionEnemy2.x<d))
{
score=IMG_Load("1.png");
coins5=NULL;
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
camera.x -= 50;
if(PositionEnemy2.x<0) 
{
  PositionEnemy2.x=0;
  camera.x=0;
}
break;

case SDL_BUTTON_RIGHT:
PositionEnemy2.x +=50;
camera.x += 50;
if(PositionEnemy2.x>1200) 
{
  PositionEnemy2.x=1200;
  camera.x=1200;
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
camera.x -= 15;
if(PositionEnemy2.x<0) 
{
  PositionEnemy2.x=0;
  camera.x=0;
}
break;
case SDLK_RIGHT:
PositionEnemy2.x += 15;
PositionEnemy2.x +=15;
camera.x += 15;
if(PositionEnemy2.x>1200) 
{
  PositionEnemy2.x=1200;
  camera.x=1200;
}
break;
case SDLK_UP:
PositionEnemy2.y -= 35;
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

if(camera.x>1200-600)
{
camera.x=600; 
PositionEnemy2.x=600-72;
}


SDL_FreeSurface(image);
SDL_FreeSurface(coeur);
SDL_FreeSurface(coeur1);
SDL_FreeSurface(coeur2);
SDL_FreeSurface(pomme);
SDL_FreeSurface(coins);

SDL_FreeSurface(coins5);
SDL_FreeSurface(enemy2);
SDL_FreeSurface(box);

}













void Options(SDL_Surface *button, SDL_Event event, SDL_Surface *button2, SDL_Rect posbut2, SDL_Rect posbut, SDL_Surface *screen, SDL_Surface *image,SDL_Rect positionecran,Mix_Music *music)
{

SDL_Surface *text;
SDL_Surface *text1;
SDL_Surface *arrow;
SDL_Rect postext;
SDL_Rect postext1;
SDL_Rect posarrow;
int s=0;
int p=0;

screen=SDL_SetVideoMode(1275,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

text = IMG_Load("mute.png");
text1 = IMG_Load("PLAY.png");
arrow=IMG_Load("arrow.png");

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
posarrow.x = 550;
posarrow.y=250;

SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_BlitSurface(button,NULL,screen,&posbut);
SDL_BlitSurface(button2,NULL,screen,&posbut2);
SDL_BlitSurface(text,NULL,screen,&postext);
SDL_BlitSurface(text1,NULL,screen,&postext1);
SDL_BlitSurface(arrow,NULL,screen,&posarrow);
SDL_Flip(screen);



while (SDL_PollEvent(&event))
{
switch (event.type)
{
case SDL_QUIT:
done=0;
case SDL_KEYDOWN:
{
switch(event.key.keysym.sym)
{
case SDLK_DOWN:
posarrow.y += 75;
if(posarrow.y>400)
{
posarrow.y = 400;
}
break;
case SDLK_UP:
posarrow.y -= 75;
if(posarrow.y<250)
{
posarrow.y = 250;
}
break;
case SDLK_KP_ENTER:
if(posarrow.y==250)
{
music=Mix_LoadMUS("nothing.mp3");
Mix_PlayMusic(music,-1);
}
if(posarrow.y==400)
{
background(image, screen, positionecran, button, event);
}
break;
}
}
break;
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
                       music=Mix_LoadMUS("nothing.mp3");
                       Mix_PlayMusic(music,-1);
                     }

                     if((event.motion.x > 600) && (event.motion.x <800) &&(event.motion.y >325) && (event.motion.y <425))
	             {
                       background(image, screen, positionecran, button, event);
                     }
}
}
}
}

}
SDL_FreeSurface(button);
SDL_FreeSurface(button2);
SDL_FreeSurface(text);
SDL_FreeSurface(text1);
SDL_FreeSurface(arrow);


}


void enigme()
{
int a;
int rep=-1;

srand(time(NULL));
a=1+rand()%4;

SDL_Surface *screen;
SDL_Surface *enigme = NULL;
SDL_Rect p_enigme4;
SDL_Rect over;
over.x=0;
over.y=0;
SDL_Surface *gover;
gover=IMG_Load("gover.png");
SDL_Init(SDL_INIT_VIDEO);

screen = SDL_SetVideoMode(640,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

p_enigme4.x = 0;
p_enigme4.y = 0;

SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));
SDL_Flip(screen);

if(a==1)
{
 enigme = IMG_Load("enigme4.jpg");
}
else if(a==2)
{
enigme = IMG_Load("enigme2.png");
}
else if(a==3)
{
enigme = IMG_Load("enigme3.png");
}
else
{
enigme = IMG_Load("enigme1.png");
}

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
rep=1;
return;
}
else
{
rep=0;
SDL_BlitSurface(gover,NULL,screen,&over);
SDL_Flip(screen);
SDL_Delay(3000);
return;
}
}
else if(a==2){
if(event4.button.x>0 && event4.button.x<191 && event4.button.y>323 && event4.button.y<425 )
{
rep=1;
return;
}
else
{
rep=0;
SDL_BlitSurface(gover,NULL,screen,&over);
SDL_Flip(screen);
SDL_Delay(3000);
return;
}
}
else if(a==3){
if(event4.button.x>0 && event4.button.x<203 && event4.button.y>395 && event4.button.y<458 )
{
rep=1;
return;

}
else
{
rep=0;
SDL_BlitSurface(gover,NULL,screen,&over);
SDL_Flip(screen);
SDL_Delay(3000);
return;

}
}
else if(a==4){
if(event4.button.x>243 && event4.button.x<398 && event4.button.y>312 && event4.button.y<387 )
{
rep=1;
return;

}
else
{
rep=0;
SDL_BlitSurface(gover,NULL,screen,&over);
SDL_Flip(screen);
SDL_Delay(3000);
return;

}
}

}
break;

}

}
return ;
}


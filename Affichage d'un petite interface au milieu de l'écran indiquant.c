#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <string.h>
#ifdef WIN32
#pragma comment(lib,"sdl.lib")
#pragma comment(lib,"sdlmain.lib")
#endif

#define STAT_SOL 0
#define STAT_AIR 1

typedef struct
{
	int status;
	float x,y;
	float vx,vy;
} Sprite;

float carree(float x)
{
	return x*x;
}
int trigooo(SDL_Rect pA,SDL_Surface *A,SDL_Rect pB,SDL_Surface *B)
{
	float AB,MA,MB;
	MA = A->h/2;
	MB = B->h/2;
	AB = sqrt(carree(pA.x+(A->w/2) - (pB.x+(B->w/2))) + carree(pA.y+(A->h/2) - (pB.y+(B->h/2))));
	if (AB <= (MA+MB))
		return 1;
	else 
		return 0;
}
void animennemie(int *m,SDL_Surface**enx,SDL_Surface* en1,SDL_Surface* en2,SDL_Surface* en3)
{
if((*m)%9==0)
{

*enx=en1;


}
else if((*m)%9==3)
{
*enx=en2;

}
else if((*m)%9==6)
{
*enx=en3;

}
(*m)++;
}

void InitSprite(Sprite* Sp)
{
	Sp->x = 100.0f+640;
	Sp->y = 400.0f;
	Sp->status = STAT_SOL;
	Sp->vx = Sp->vy = 0.0f;
}
int collision(SDL_Rect r1,SDL_Surface *ppx,SDL_Rect r2,SDL_Surface *ob)
{
if(r1.y >= r2.y + ob->h)
return 0;
if(r1.x >= r2.x + ob->w)
return 0;
if(r1.y + ppx->h <= r2.y)
return 0;
if(r1.x + ppx->w <= r2.x)
return 0;
return 1;
}


void Render(Sprite* Sp,SDL_Surface* screen,SDL_Surface *ppx,SDL_Rect camera,SDL_Surface *image,SDL_Rect ob_pos,SDL_Surface *ob,SDL_Rect *R,SDL_Rect en_pos,SDL_Surface *enx,SDL_Rect coin1_pos,SDL_Rect coin2_pos,SDL_Rect coin3_pos,SDL_Rect coin4_pos,SDL_Rect coin5_pos,SDL_Surface *coin1,SDL_Surface *coin2,SDL_Surface *coin3,SDL_Surface *coin4,SDL_Surface *coin5,SDL_Surface *text,SDL_Rect texpos)
{
	
	R->x = (Sint16)Sp->x;
	R->y = (Sint16)Sp->y+50;
	
	
	SDL_BlitSurface(image,&camera,screen,NULL);
	SDL_BlitSurface(ppx,NULL,screen,R);
	SDL_BlitSurface(ob,NULL,screen,&ob_pos);
	SDL_BlitSurface(enx,NULL,screen,&en_pos);
	SDL_BlitSurface(coin1,NULL,screen,&coin1_pos);
	SDL_BlitSurface(coin2,NULL,screen,&coin2_pos);
	SDL_BlitSurface(coin3,NULL,screen,&coin3_pos);
	SDL_BlitSurface(coin4,NULL,screen,&coin4_pos);
	SDL_BlitSurface(coin5,NULL,screen,&coin5_pos);	
	SDL_BlitSurface(text,NULL,screen,&texpos);
}

void Saute(Sprite* Sp,float impulsion)
{
	Sp->vy = -impulsion-2;
	Sp->status = STAT_AIR;
}

void ControleSol(Sprite* Sp)
{
	if (Sp->y>250.0f)
	{
		Sp->y = 250.0f;
		if (Sp->vy>0)
			Sp->vy = 0.0f;
		Sp->status = STAT_SOL;
	}
}

void Gravite(Sprite* Sp,float factgravite,float factsautmaintenu,Uint8* keys)
 {
	if (Sp->status == STAT_AIR && keys[SDLK_SPACE])
		factgravite/=factsautmaintenu;
	Sp->vy += factgravite;
}

void Evolue(Sprite* Sp,Uint8* keys,int *i,SDL_Surface **ppx,SDL_Surface *pp,SDL_Surface*pp2,SDL_Surface*pp3,SDL_Surface*pp4,SDL_Surface*pp5,SDL_Surface*pp6,SDL_Rect *camera,SDL_Rect *ob_pos,SDL_Surface *ob,SDL_Rect R,int *n,int ep,SDL_Rect *coin1_pos,SDL_Rect *coin2_pos,SDL_Rect *coin3_pos,SDL_Rect *coin4_pos,SDL_Rect *coin5_pos)
{
	float lateralspeed = 0.5f;
	float airlateralspeedfacteur = 1.0f;
	float maxhspeed = 3.0f;
	float adherance = 1.5f;
	float impulsion = 6.0f;
	float factgravite = 0.5f;
	float factsautmaintenu = 3.0f;
	int o;
	int speed;
// controle lateral
	if (Sp->status == STAT_AIR) // (*2)
		lateralspeed*= airlateralspeedfacteur;
	if (keys[SDLK_LEFT]) // (*1)
		Sp->vx-=lateralspeed;
	if (keys[SDLK_RIGHT])
		{
		if((*i)%24==0)
		{

		*ppx=pp;


		}
		else if((*i)%24==4)
		{
		*ppx=pp2;


		}
		else if((*i)%24==8)
		{
		*ppx=pp3;


		}
		else if((*i)%24==12)
		{
		*ppx=pp4;


		}
		else if((*i)%24==16)
		{
		*ppx=pp5;


		}
		else if((*i)%24==20)
		{
		*ppx=pp6;


		}

		(*i)++;
		Sp->vx+=lateralspeed;
		
		ob_pos->x-=4;
		coin1_pos->x-=4;
		coin2_pos->x-=4;
		coin3_pos->x-=4;
		coin4_pos->x-=4;
		coin5_pos->x-=4;
		if(ep==1)
		(*n)+=2;
		if(collision(R,*ppx,*ob_pos,ob)==0  )
		camera->x +=Sp->vx;
		
		}
	if (Sp->status == STAT_SOL && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) // (*3)
		Sp->vx/=adherance;
// limite vitesse
	if (Sp->vx>maxhspeed) // (*4)
		Sp->vx = maxhspeed;
	if (Sp->vx<-maxhspeed)
		Sp->vx = -maxhspeed;
// saut
		
	if (keys[SDLK_SPACE] && Sp->status == STAT_SOL)

		Saute(Sp,impulsion);
	Gravite(Sp,factgravite,factsautmaintenu,keys);
	ControleSol(Sp);
// application du vecteur à la position.
		
	o=camera->x;
	/*if(collision(R,*ppx,*ob_pos,ob)==0  )
	camera->x +=Sp->vx;*/
	
	/*if(collision(R,*ppx,*ob_pos,ob)==1 && Sp->status==STAT_SOL)
	{camera->x=o-4;
	ob_pos->x=220;
	
	}*/
	
	if(collision(R,*ppx,*ob_pos,ob)==0 && Sp->status==STAT_AIR )
		Sp->y +=Sp->vy;
	if(collision(R,*ppx,*ob_pos,ob)==1 && Sp->status==STAT_SOL  )
	{camera->x=o-4;
	ob_pos->x=220;
	
	}
	/*if(collision(R,*ppx,*ob_pos,ob))
	camera->x -=Sp->vx;*/
	
	
		
}

int main(int argc,char** argv)
{
	SDL_Surface* screen,*ppx,*pp,*pp2,*pp3,*pp4,*pp5,*pp6,*image,*ob,*en1,*en2,*en3,*en1m,*en2m,*en3m,*coin1,*coin2,*coin3,*coin4,*coin5;
	int numkeys;
	Uint8 * keys;
	SDL_Surface *enx,*map;
	int i=0,k=0,j=0,ep=0,n=0,m=0,taw=0,s=0,vie=3,akahawa=0,cont=1;
	Sprite S;
	SDL_Surface *vie1,*vie2,*vie3;
	Uint32 timer,elapsed;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	map=IMG_Load("map.png");
	pp=IMG_Load("pos1.png");
	pp2=IMG_Load("pos2.png");
	pp3=IMG_Load("pos3.png");
	pp4=IMG_Load("pos4.png");
	pp5=IMG_Load("pos5.png");
	pp6=IMG_Load("pos6.png");
	image=IMG_Load("backiy.png");
	ob=IMG_Load("1erob.png");
	en1=IMG_Load("1.png");
	en2=IMG_Load("2.png");
	en3=IMG_Load("3.png");
	en1m=IMG_Load("c.png");
	en2m=IMG_Load("b.png");
	en3m=IMG_Load("a.png");
	coin1=IMG_Load("coin.png");
	coin2=IMG_Load("coin.png");
	coin3=IMG_Load("coin.png");
	coin4=IMG_Load("coin.png");
	coin5=IMG_Load("coin.png");
	vie1=IMG_Load("1c.png");
	vie2=IMG_Load("2c.png");
	vie3=IMG_Load("3c.png");
	ppx=pp;	
	SDL_Rect camera,R;
	camera.x=0;
	camera.y=0;
	camera.w=640;
	camera.h=480;
	SDL_Rect vie_pos;
	vie_pos.x=0;
	vie_pos.y=0;
	SDL_Rect ob_pos;
	ob_pos.x=600;
	ob_pos.y=350;
	SDL_Rect coin1_pos;
	coin1_pos.x=3000;
	coin1_pos.y=320;
	SDL_Rect coin2_pos;
	coin2_pos.x=3100;
	coin2_pos.y=320;
	SDL_Rect coin3_pos;
	coin3_pos.x=3200;
	coin3_pos.y=320;
	SDL_Rect coin4_pos;
	coin4_pos.x=3300;
	coin4_pos.y=320;
	SDL_Rect coin5_pos;
	coin5_pos.x=3400;
	coin5_pos.y=320;
	SDL_Rect r1;
	r1.x=300;
	r1.y=300;
	SDL_Rect r2;
	r2.x=300;
	r2.y=300;
	r2.h=10;
	r2.w=10;
	SDL_Rect en_pos;
	en_pos.x=1500;
	en_pos.y=270;
	//creer une police
	TTF_Font *font;
	font=TTF_OpenFont("test.ttf",22);
	SDL_Color fontb={0,0,0};
	//creer une police
	char score[20];
	sprintf(score,"%d",s);	
	SDL_Surface *texte1;
	texte1=TTF_RenderText_Solid(font,score,fontb);
	SDL_Rect texpos;
	texpos.x=80;
	texpos.y=80;
	//TTF_Font *font2;
	/*font2=TTF_OpenFont("test.ttf",100);
	SDL_Color fontc={0,255,0};
		SDL_Surface *texte2;
	texte2=TTF_RenderText_Solid(font2,"gameover",fontc);
	SDL_Rect gover;
	gover.x=100;
	gover.y=200;*/
	screen=SDL_SetVideoMode(640,480,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
	InitSprite(&S);
	
	do 
	{
			if(vie==0)
			{
				cont=0;
				}		
		if(trigooo(R,ppx,coin1_pos,coin1))
		{coin1_pos.x+=800;s++;}
		if(trigooo(R,ppx,coin2_pos,coin2))
		{coin2_pos.x+=800;s++;}
		if(trigooo(R,ppx,coin3_pos,coin3))
		{coin3_pos.x+=800;s++;}
		if(trigooo(R,ppx,coin4_pos,coin4))
		{coin4_pos.x+=800;s++;}
		if(trigooo(R,ppx,coin5_pos,coin5))
		{coin5_pos.x+=800;s++;}

		
	if(j==0)
	{

	en_pos.x -=4;
	if(en_pos.x < 600-n && taw==0)
	{
	animennemie(&m,&enx,en1,en2,en3);
	k++;
	ep=1;
	}
	if(k > 100)
	{en_pos.x +=8;
	animennemie(&m,&enx,en1m,en2m,en3m);
	taw=1;
	if(en_pos.x > 600-n)
	{j=0;
	k=0;
	taw=0;
	akahawa=0;
	}

	}


	}
	if(en_pos.x < 0)
		{en_pos.x+=3000;
		j=0;
		n=0;
		taw=0;
		ep=0;
		}
		timer = SDL_GetTicks();
		
		sprintf(score,"%d",s);
		texte1=TTF_RenderText_Solid(font,score,fontb);		
		SDL_FillRect(screen,NULL,0);
					
		if(collision(R,ppx,en_pos,enx) && akahawa==0)
		{vie--;
		akahawa=1;
				
			}
		SDL_PumpEvents();
		keys = SDL_GetKeyState(&numkeys);
		Evolue(&S,keys,&i,&ppx,pp,pp2,pp3,pp4,pp5,pp6,&camera,&ob_pos,ob,R,&n
,ep,&coin1_pos,&coin2_pos,&coin3_pos,&coin4_pos,&coin5_pos);
		Render(&S,screen,ppx,camera,image,ob_pos,ob,&R,en_pos,enx,coin1_pos,coin2_pos,coin3_pos,coin4_pos,coin5_pos,coin1,coin2,coin3,coin4,coin5,texte1,texpos);
		SDL_BlitSurface(map,NULL,screen,&r1);
		r2.x=(camera.x/100)+300;
		SDL_FillRect(screen,&r2,SDL_MapRGB(screen->format,0,255,0));		
		if(vie==3)
		SDL_BlitSurface(vie3,NULL,screen,&vie_pos);
		if(vie==2)
		SDL_BlitSurface(vie2,NULL,screen,&vie_pos);	
		if(vie==1)
		SDL_BlitSurface(vie1,NULL,screen,&vie_pos);	
		SDL_Flip(screen);
		elapsed = SDL_GetTicks() - timer;
		if (elapsed<20)
		SDL_Delay(20-elapsed);
	} while (!keys[SDLK_ESCAPE] && cont==1);
	TTF_Quit();	
	SDL_Quit();
	return 0;
}

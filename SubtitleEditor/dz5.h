/*This file defines data structures and functions that are used in the project. */

#include <stdlib.h>
#include <stdio.h>

#ifndef _dz5_h_
#define _dz5_h_

//#ifdef NTSC
#define FPS_NUM 23.976
//#endif
#ifdef PAL
#define FPS_NUM 25
#endif

#define MAX_LEN 200
typedef struct{
	unsigned int milisec;
	unsigned int sec;
	unsigned int min;
	unsigned int h;
	double vremeR;
}Time;

typedef struct {
	Time app;
	Time rem;
	char text[MAX_LEN];
}Info;

typedef struct Titl{
	Info *info;
	struct Titl *sled;
	struct Titl *pred;
}titl;

typedef struct List{
	titl *prvi;
	titl *posl;
	titl *tek;
}list;

#endif

void load(list *lst, FILE *dat);
void addNew(char *text, char*line,list *lst);
Info convertTime(char *vreme);
void process(list *lst, char *arg);
void delList(list *lst);



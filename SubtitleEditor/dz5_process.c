#include "dz5.h"
#include <stdlib.h>

void process(list *lst, char *arg){
	double pomeraj = atof(arg);double brojA;
	lst->tek = lst->prvi;
	while (lst->tek){
		brojA = (double)lst->tek->info->app.milisec/1000;
		brojA = lst->tek->info->app.sec + brojA +pomeraj;
		brojA = 60*lst->tek->info->app.min + brojA;
		brojA = 60*60*lst->tek->info->app.h + brojA;
		lst->tek->info->app.vremeR = brojA *FPS_NUM;

		brojA = (double)lst->tek->info->rem.milisec / 1000;
		brojA = lst->tek->info->rem.sec + brojA+pomeraj;
		brojA = 60 * lst->tek->info->rem.min + brojA;
		brojA = 60 * 60 * lst->tek->info->rem.h + brojA;
		lst->tek->info->rem.vremeR = brojA* FPS_NUM;


		lst->tek = lst->tek->sled;
	}
}

void delList(list *lst){
	lst->tek = lst->prvi;
	while (lst->tek){
		lst->prvi = lst->tek;
		lst->tek = lst->tek->sled;
		free(lst->prvi);
	}
	lst->prvi = lst->posl = NULL;
}
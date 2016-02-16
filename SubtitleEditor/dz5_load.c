#include <stdio.h>
#include "dz5.h"
#include <stdlib.h>
#include <string.h>

Info convertTime(char *vreme){
	Info vreme1;
	int i,j = 0; char broj[5];
	for (i = 0; i < 2; i++,j++){
		broj[i] = vreme[j];
	}
	broj[i++] = '\0';
	j++;
	vreme1.app.h = atoi(broj);

	for (i = 0; i < 2; i++, j++){
		broj[i] = vreme[j];
	}
	broj[i++] = '\0';
	j++;
	vreme1.app.min = atoi(broj);

	for (i = 0; i < 2; i++, j++){
		broj[i] = vreme[j];
	}
	broj[i++] = '\0';
	j++;
	vreme1.app.sec = atoi(broj);

	for (i = 0; i < 3; i++, j++){
		broj[i] = vreme[j];
	}
	broj[i++] = '\0';
	j++;
	vreme1.app.milisec = atoi(broj);
	j += 4;

	for (i = 0; i < 2; i++, j++){
		broj[i] = vreme[j];
	}
	broj[i++] = '\0';
	j++;
	vreme1.rem.h = atoi(broj);

	for (i = 0; i < 2; i++, j++){
		broj[i] = vreme[j];
	}
	broj[i++] = '\0';
	j++;
	vreme1.rem.min = atoi(broj);

	for (i = 0; i < 2; i++, j++){
		broj[i] = vreme[j];
	}
	broj[i++] = '\0';
	j++;
	vreme1.rem.sec = atoi(broj);

	for (i = 0; i < 3; i++, j++){
		broj[i] = vreme[j];
	}
	broj[i++] = '\0';
	j++;
	vreme1.rem.milisec = atoi(broj);

	return vreme1;
}

void addNew(char *text, char *vreme,list *lst){
	Info vreme1;
	titl *new = calloc(1,sizeof(titl));
	new->info = malloc(sizeof(Info));
	strcpy(new->info->text, text);
	vreme1 = convertTime(vreme);
	new->info->app = vreme1.app;
	new->info->rem = vreme1.rem;
	new->pred = lst->posl;
	new->sled = NULL;
	if (lst->prvi == NULL) lst->prvi = new;
	else lst->posl->sled = new;
	lst->posl = new;

}
/*This funtcion loads subtitle and save it to the linked list*/

void load(list *lst,FILE *dat){
	char line[50]; int counter=0; char text[MAX_LEN], vreme[40];
	while (fgets(line, 50, dat)){
		if (strcmp(line, "\n") == 0) {
			counter = 0;
			addNew(text, vreme, lst);
			continue; 
		}
		if (counter == 1){
			strcpy(vreme, line);
		}
		else if (counter ==2 )
		{
			strcpy(text, line);
		}
		else if (counter > 2){
			strcat(text, line);
		}
		counter++;
	}
}
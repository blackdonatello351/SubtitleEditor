
#include <stdio.h>
#include "dz5.h"
#include <stdlib.h>
#include <math.h>


/*This funtcion will save subtitle as *.sub or *.txt (MicroDVD) */
void save(list *lst, FILE *output){
	lst->tek = lst->prvi; char c; int i; long int broj;
	while (lst->tek){
		
		fputc('{', output);
		broj = (long int)round(lst->tek->info->app.vremeR);
		fprintf(output, "%d", broj);
		fputc('}', output);
		fputc('{', output);
		broj = (long int)round(lst->tek->info->rem.vremeR);
		fprintf(output, "%d", broj);
		fputc('}', output);
		i = 0;
		while ((c=lst->tek->info->text[i] )!='\0'){
			if ((c == '\n') && (lst->tek->info->text[i + 1] != '\0')){
				fputc('|', output);
			}
			else if (c != '\n'){
				fputc(c, output);
			}
			else fputc('\n',output);
			i++;

		}
		lst->tek = lst->tek->sled;
	}

	fclose(output);
}
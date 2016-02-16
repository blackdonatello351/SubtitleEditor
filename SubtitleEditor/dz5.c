/*This program gets as input from command line arguments : [name of the input subtitle *.srt] [name of output subtitle *.sub or *.txt] [move in seconds(+/-)]*/

#include "dz5.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(int argc, char *argv[]){
	
	time_t pIntTime = time(NULL);
	struct tm* currentLocalTime = localtime(&pIntTime);
	char* dateTimeString = calloc(101, sizeof(char));
	if (currentLocalTime && dateTimeString)
		strftime(dateTimeString, 100, "%H:%M:%S", currentLocalTime);
	
	printf("%s", dateTimeString);
	

	clock_t t1 = clock();

	list lst; lst.prvi = lst.posl = lst.tek = NULL;
	FILE *input, *output;
	if ((input = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "%s:greska u otvaranju datoteke %s", argv[0], argv[1]);
		exit(1);
	}
	load(&lst, input);
	process(&lst, argv[3]);

	if ((input = fopen(argv[2], "w")) == NULL){
		fprintf(stderr, "%s:greska u otvaranju datoteke %s", argv[0], argv[1]);
		exit(1);
	}
	save(&lst, input);
	delList(&lst);
	clock_t t2 = clock();
	printf("\nVreme izvrsavanja programa je : %10.6lf\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

	pIntTime = time(NULL);
	currentLocalTime = localtime(&pIntTime);
	strftime(dateTimeString, 100, "%H:%M:%S", currentLocalTime);
	printf("%s\n", dateTimeString);
	free(dateTimeString);


	system("pause");
}
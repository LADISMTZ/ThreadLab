#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int array[5]={0};


void*consumidor() {
	int notFound = 1;
	int i = 0;
	while (notFound) {
		if (array[i]!=0) {
			if (i==4) {
				printf("El valor colocado en la ultima posicion es: %d\n", array[i]);
				array[i] = 0;
				notFound = 0;
			} //end if
			else {
				printf("El valor colocado en la posicion %d es %d\n", i, array[i]);
				array[i] = 0;
			} //end else
		} //end if
		
		if (i==4) {
			i=0;
		} //end if
		else {
			i++;
		} //end else
		
	} //end while
	pthread_exit(NULL);
} //end consumidor

void productor () {
	int Buffer;
 	for (int i=0; i<5;i++) {
 		sleep(1);
 		printf("Escribe el numero que se colocara en el arreglo: \n");
    	scanf("%d",&Buffer);
    	array[i] = Buffer;
    } //end for
} //end productor


int main () {
	pthread_t hiloA;
	int A = pthread_create(&hiloA,NULL,consumidor,NULL);
    productor();
    pthread_join(hiloA, NULL);
    printf("Hemos terminado");
    return 0;
} //end main

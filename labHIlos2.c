#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int arreglo[12];
int subarregloA[4];
int subarregloB[4];
int subarregloC[4];
int foundFlag;
int num;


void*encontrarA () {
	for(int i = 0; i<4;i++) {
		if (subarregloA[i]==num) {
			foundFlag = 1;
			pthread_exit(NULL);
		} //end if
	} //end for
	pthread_exit(NULL);
} //end encontrarA

void*encontrarB () {
	for(int i = 0; i<4;i++) {
		if (subarregloB[i]==num) {
			foundFlag = 1;
			pthread_exit(NULL);
		} //end if
	} //end for
	pthread_exit(NULL);
} //end encontrarB

void*encontrarC () {
	for(int i = 0; i<4;i++) {
		if (subarregloC[i]==num) {
			foundFlag = 1;
			pthread_exit(NULL);
		} //end if
	} //end for
	pthread_exit(NULL);
} //end encontrarC

int main () {

	int A,B,C;
	pthread_t hiloA,hiloB,hiloC;
	

	for (int i = 0; i<12; i++) {
		arreglo[i]=i;
	} //end for
	for (int i = 0; i<4; i++) {
		subarregloA[i]=arreglo[i];
		subarregloB[i]=arreglo[i+4];
		subarregloC[i]=arreglo[i+8];
	} //end for
	
	printf("Escribe el numero que deseas buscar en el arreglo: ");
	scanf("%d", &num);
	

	A = pthread_create(&hiloA,NULL,encontrarA,NULL);

    	B = pthread_create(&hiloB,NULL,encontrarB,NULL);

    	C = pthread_create(&hiloC,NULL,encontrarC,NULL);

    pthread_join(hiloA, NULL);
    pthread_join(hiloB, NULL);
    pthread_join(hiloC, NULL);
    

    if (foundFlag) {
    	printf("Un hilo encontro el numero");
    } //end if
    else {
    	printf("Ningun hilo encontro el numero");
    } //end else
    
	return 0;
} //end main

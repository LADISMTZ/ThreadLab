#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int r1, r2, r3;

//multiplicacion dividida por hilos
void *multiplicacion1() {
	r1 = (1*2*3);
} 
void *multiplicacion2 () {
	r2 = (4*5*6);
} 

void *multiplicacion3 () {
	r3 = (7*8*9);
} 

int main () {

	pthread_t hiloA, hiloB, hiloC;
	
			
	int state = pthread_create(&hiloA,NULL, multiplicacion1, NULL);
	pthread_join(hiloA, NULL);
	

	
	state = pthread_create(&hiloB,NULL, multiplicacion2, NULL);
	pthread_join(hiloB, NULL);
	
	state = pthread_create(&hiloC,NULL, multiplicacion3, NULL);
	pthread_join(hiloC, NULL);
	

	printf("El resultado del factorial de 9 es: %d\n", r1*r2*r3);
	
	return 0;

} //end main

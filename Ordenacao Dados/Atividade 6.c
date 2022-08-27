#include <stdio.h>
#include <locale.h>
#define TAM 1000

void leCP (int vetor[]) {
	FILE* arq;
	arq = fopen ("ED_Aula13b_Ordenacao_ArquivoCp.TXT", "r");

	int i = 0;

	while (!feof(arq)) {
		fscanf(arq, "%i\n"arq, %vetor[i]);
		i++;
	}
	fclose(arq);
}

void imprimirVetor (int vetor[]) {
	int i;
	
	for (i=0; i < TAM; i++){
		printf("%i", vetor[i]);
	}
}

void main () {
	
	int valores[TAM];
	
	
	
	
}

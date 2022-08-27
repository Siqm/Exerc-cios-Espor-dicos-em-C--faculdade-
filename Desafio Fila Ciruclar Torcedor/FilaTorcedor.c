/* Desenvolver Fila Dinâmica contendo 02 ponteiros, sendo o de Início que será
responsável pela remoção dos elementos, e o de Final que será responsável pelo
controle de inserção de novos elementos, e todos os métodos deverão considerar
da melhor forma ambos ponteiros. 

A fila deverá controlar a entrada de torcedores em um jogo de futebol, deverá
ser armazenada as seguintes informações de cada torcedor: Código ingresso; 
Idade; Valor; Número da cadeira.

FILA TORCEDORES
1. Adicionar torcedor fila (enfileirar)
2. Permitir entrada torcedor (desenfileirar)
3. Contar número de torcedores aguardando entrada (contar elementos fila)
4. Exibir informações torcedores fila
5. Exibir torcedor mais novo e mais velho da fila
6. Somar valor ingressos torcedores fila
*/

#include <locale.h>
#include <stdio.h>

typedef struct Torcedor {
	int codIngresso;
	int idade;
	float valor;
	int numeroCadeira;
	struct Torcedor *proximo;
}Torcedor;

typedef struct Fila {
	Torcedor *inicio;
	Torcedor *fim;
	float valorTotal;
	int contaTorcedor;
} Fila ;

void criaFila (Fila *f1) {
	f1->inicio = NULL;
	f1->fim = NULL;
	f1->valorTotal = 0;
	f1->contaTorcedor = 0;
}

Torcedor *criaTorcedor () {
	Torcedor *ptr = (Torcedor*) malloc(sizeof(Torcedor));
	
	if(ptr == NULL) {
		printf("Erro de alocação! \n\n");
		return;
	} else {
		printf("Insira o codigo do ingresso: ");
		scanf("%i", &ptr->codIngresso);
		printf("Insira a idade: ");
		scanf("%i", &ptr->idade);
		printf("Insira o valor do ingresso: R$");
		scanf("%f", &ptr->valor);
		printf("Insira o numero da cadeira: ");
		scanf("%i", &ptr->numeroCadeira);
		ptr->proximo = NULL;
		return ptr;
	}
}

int isEmpty (Fila *f) {
	
	if (f->inicio == NULL) {
		return 1;
	}
	return 0;
}

void somaValores (Fila *f, Torcedor *t) {
	f->valorTotal += t->valor;
}

void subtraiValores (Fila *f, Torcedor *t) {
	f->valorTotal -= t->valor;
}

void enqueue (Fila *f) {
	
	Torcedor *ptr = criaTorcedor();
	
	if (isEmpty(f)) {
		f->inicio = ptr;
	} else {
		f->fim->proximo = ptr;
	}
	f->fim = ptr;
	f->contaTorcedor++;
	somaValores(f, ptr);
	printf("\n");
}

void dequeue (Fila *f) {
	if (isEmpty(f)) {
		printf("Fila vazia! \n\n");
		return;
	} else {
		Torcedor *ptr = f->inicio;
		f->inicio = f->inicio->proximo;
		printf("Permitindo entrada! \n");
		printf("Codigo do ingresso: %i \n", ptr->codIngresso);
		printf("Valor do ingresso: %f \n", ptr->valor);
		printf("Número da cadeira: %i \n", ptr->numeroCadeira);
		printf("Idade do torcedor: %i \n", ptr->idade);
		printf("Torcedor desenfileirado! \n");
		f->contaTorcedor--;
		printf("Número de torcedores restantes na fila: %i \n\n", f->contaTorcedor);
		subtraiValores(f, ptr);
		free(ptr);
		if (isEmpty(f)) {
			f->fim = NULL;
			f->inicio = NULL;
		}
	}
}

void printAll (Fila *f) {
	Torcedor *ptr = f->inicio;
	 
	 if (isEmpty(f)) {
		printf("Fila vazia! \n\n");
	 } else {
		printf("Quantidade de torcedores na fila: %i \n\n", f->contaTorcedor);
		while (ptr != NULL) {
	 		printf("Código ingresso: %i \n", ptr->codIngresso);
	 		printf("Valor ingresso: %2f \n", ptr->valor);
	 		printf("Idade: %i \n", ptr->idade);
	 		printf("Número da cadeira: %i \n", ptr->numeroCadeira);
	 		ptr = ptr->proximo;
	 		printf("\n");
		}
		printf("\n");
	 }
}

void idadesExtremas (Fila *f) {
	Torcedor *novo = f->inicio;
	Torcedor *maior = novo;
	Torcedor *menor = novo;
	while (novo != NULL) {
		if (maior->idade > novo->idade) {
			maior = novo;
		}
		if (menor->idade < novo->idade) {
			menor = novo;
		}
		novo = novo->proximo;
	}
	printf("Torcedor mais velho: %i\n", maior->idade);
	printf("Torcedor mais novo: %i\n\n", menor->idade);
}

void main (int argc, char *argv) {
	setlocale(LC_ALL,"");
	Fila *f1 = (Fila*) malloc(sizeof(Fila));
	int opcao = 0;
	
	if (f1 == NULL) {
		printf("Erro de alocação da Fila \n");
	} else {
		criaFila(f1);
		while (opcao != 9) {
			printf(":: Fila Torcedores :: \n");
			printf("1. Adicionar        \n");
			printf("2. Permitir entrada     \n");
			printf("3. Contar torcedores enfileirados        \n");
			printf("4. Imprimir torcedores \n");
			printf("5. Exibir mais novo e mais velho \n");
			printf("6. Somar valores de ingresso \n");
			printf("9. Sair \n");
			printf("Digite a opcao desejada: ");
			scanf("%d", &opcao);
			printf("\n");
			
			switch(opcao) {
				case 1:
					enqueue(f1);
				break;
				
				case 2:
					dequeue(f1);
				break;
				
				case 3:
					printf("O número de torcedores é de: %i \n\n", f1->contaTorcedor);
				break;
				
				case 4:
					printAll(f1);
				break;
				
				case 5:
					idadesExtremas(f1);
				break;
				
				case 6:
					printf("O total dos ingressos é de R$%.2f \n\n", f1->valorTotal);
				break;
			}
		}
	}
}

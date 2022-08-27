/* ORIENTAÇÕES

Cada aluno deverá implementar a Fila Dinâmica abaixo, a implementação deverá respeitar o prazo,
o código fonte deverá ser postado em sua integralidade e deverá conter: a) Filas dinâmicas; 
b) Utilização de Ponteiros; c) TDE; d) TDA; e) Controle de Fila Vazia.
FILA ALUNOS
O programa deverá controlar a fila de atendimento de alunos em uma escola, deverá armazenar as
seguintes informações de cada aluno: RA, NOME, MENSALIDADE, IDADE.
FILA ALUNOS
1. Adicionar 
2. Atender
3. Imprimir Todos
4. Número Alunos
5. Localizar (RA). */
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
	int ra;
	int idade;
	float mensalidade;
	char nome[20];
	struct Aluno *proximo;
}Aluno;

typedef struct Fila {
	Aluno *inicio;
	Aluno *fim;
	int contaAlunos;
}Fila;

void iniciaFila (Fila *f) {
	f->inicio = NULL;
	f->fim = NULL;
	f->contaAlunos = 0;
}

Aluno *criarAluno () {
	Aluno *ptr = (Aluno*) malloc(sizeof(Aluno));

	if (ptr == NULL) {
		printf("Erro de alocação \n\n");
		return;
	} else {
		printf("Insira o RA: ");
		scanf("%i", &ptr->ra);
		printf("Insira a idade do aluno: ");
		scanf("%i", &ptr->idade);
		printf("Insira o valor da mensalidade: ");
		scanf("%f", &ptr->mensalidade);
		getchar();
		printf("Insira o nome: ");
		gets(ptr->nome);
		ptr->proximo = NULL;
		printf("\n");
		return ptr;
	}
}

int isEmpty (Fila *f) { 
	
	if (f->inicio == NULL) {
		return 1; // sim == true
	}
	return 0; ; // não == false
}

void enqueue (Fila *f) {
	Aluno *ptr = criarAluno();
	
	if (ptr == NULL) {
		printf("Erro de alocação \n\n");
		return;
	} else  {
		if (isEmpty(f)) {
		f->inicio = ptr;
		} else { 
			f->fim->proximo = ptr;
		}
		f->fim = ptr;
	}
	f->contaAlunos++;
}

void dequeue (Fila *f) {
	if(isEmpty(f)) {
		printf("Fila vazia! \n\n");
		return;
	} else {
		Aluno *ptr = f->inicio;
		f->inicio = f->inicio->proximo;
		
		printf("Atendendo aluno: ");
		puts(ptr->nome);
		printf("RA: %i \n", ptr->ra);
		printf("Mensalidade: %.2f \n", ptr->mensalidade);
		printf("Idade: %i \n\n", ptr->idade);
		free(ptr);
		
		if (isEmpty(f)) {
			f->fim = NULL;
		}
		f->contaAlunos--;
	}
}

void printAll (Fila *f) {
	Aluno *ptr = f->inicio;
	 
	 if (isEmpty(f)) {
		printf("Fila vazia! \n\n");
	 } else {
		printf("Quantidade de alunos na fila: %i \n\n", f->contaAlunos);
		while (ptr != NULL) {
	 		printf("RA: %i \n", ptr->ra);
	 		printf("Nome: ");
	 		puts(ptr->nome);
	 		printf("Idade: %i \n", ptr->idade);
	 		printf("Mensalidade: %.2f \n", ptr->mensalidade);
	 		ptr = ptr->proximo;
		}
		printf("\n");
	 }
}

void searchRA(Fila *f) {
	int buscaRA, condition = 1;
	
	if(isEmpty(f)) {
		printf("Fila vazia! \n\n");
	} else {
		while (condition) {
			Aluno *ptr = f->inicio;
			printf("Insira o RA que deseja buscar: ");
			scanf("%i", &buscaRA);
			while(ptr != NULL) {
				if (buscaRA == ptr->ra) {
					printf("RA encontrado! \n");
					printf("RA: %i \n", ptr->ra);
	 				printf("Nome: ");
	 				puts(ptr->nome);
	 				printf("Idade: %i \n", ptr->idade);
	 				printf("Mensalidade: %.2f \n\n", ptr->mensalidade);
	 				condition = 0;
				}
				ptr = ptr->proximo;
			}
			if (condition) {
				printf("RA Não encontrado! \n\n");
			}
		}
	}
}

void main () {
	setlocale(LC_ALL,"");
	Fila *f1 = (Fila*) malloc(sizeof(Fila));
	int opcao = 0;
	
	if (f1 == NULL) {
		printf("Erro de alocação da pilha \n");
	} else {
		iniciaFila(f1);
		while (opcao != 9) {
			printf(":: PILHA Alunos :: \n");
			printf("1. Adicionar        \n");
			printf("2. Atender     \n");
			printf("3. Imprimir        \n");
			printf("4. Numero de alunos \n");
			printf("5. Localizar RA \n");
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
					printAll(f1);
				break;
				
				case 4:
					printf("O número de alunos é de: %i \n\n", f1->contaAlunos);
				break;
				
				case 5:
					searchRA(f1);
				break;
			}
		}
		
	}
}

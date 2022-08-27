//C. FILAS
//Implemente um programa que seja capaz de organizar o atendimento até 100 alunos em uma secretaria,
// cada aluno que chega deverá informar seu RA, NOME, CURSO, ASSUNTO (MATRICULA, FINANCEIRO, PROTOCOLO)
// e então entrar na fila. O programa deverá conter as seguintes opções:  
//1. Adicionar 
//2. Atender
//3. Imprimir fila
//4. Número alunos por assunto
//5. Assunto com maior número alunos

#include <stdio.h>
#include <locale.h>
#include <string.h>
#define size 10

struct aluno {
	int ra;
	char nome[35];
	char curso[25];
	char problema[11];
};

struct aluno filaAlunos[size];
int front = -1, rear = -1, elementsQueue = 0;

void startVector (struct aluno *vetor) {
	int i;
	for (i = 0; i < size; i++) {
		strcpy(vetor[i].nome, "NULL");
	}
}

int isEmpty (int elementsInQueue) {
	if (elementsInQueue == 0) {
		return 1;
	} else {
		return 0;
	}
}

int isFull (int elementsInQueue) {
	if (elementsInQueue == size) {
		return 1;
	} else {
		return 0;
	}
}

void reallocateIndex (int *index) {
	if (*index == size - 1) {
		*index = 0;
	} else {
		*index += 1;
	}
}

void registraNome (int index) {
	printf("Insira seu nome: ");
	gets(filaAlunos[index].nome);
}

void registraRA(int index, struct aluno *vetor) {
	
	printf("Insira seu RA: ");
	scanf("%i", &vetor[index].ra);
	getchar();
}

void registraCurso(int index, struct aluno *vetor) {
	
	printf("Insira seu curso: ");
	gets(vetor[index].curso);
}

void registraAssunto (int index, struct aluno *vetor) {
	
	int assunto, decisao = 0;
	
	while (decisao == 0) {
		printf("Selecione o assunto para qual deseja atendimento \n");
		printf("1 - Matrícula \n");
		printf("2 - Financeiro \n");
		printf("3 - Protocolo \n");
		printf("Opção escolhida: ");
		scanf("%i", &assunto);
		
		if (assunto == 1) {
			strcpy(vetor[index].problema, "Matrícula");
			decisao = 1;
		} else if (assunto == 2) {
			strcpy(vetor[index].problema, "Financeiro");
			decisao = 1;
		} else if (assunto == 3) {
			strcpy(vetor[index].problema, "Protocolo");
			decisao = 1;
		} else {
			printf("Opção inválida \n");
		}
	}
}

void enqueue (struct aluno *vetor) {
	if(isFull(elementsQueue)) {
		printf("Fila com capacidade máxima de alunos! \n");
	} else {
		if (isEmpty(elementsQueue)) {
			front = 0;
			rear = 0;
		} else {
			reallocateIndex(&rear);
		}
		elementsQueue += 1;
		 
		registraNome(rear);
		
		registraRA(rear, filaAlunos);
		
		registraCurso(rear, filaAlunos);
		
		registraAssunto(rear, filaAlunos);
	}
}


void dequeue (struct aluno *vetor) {
	
	if (isEmpty(elementsQueue)) {
		printf("Nenhum aluno restante para atender! \n");
	} else {
		
		printf("Aluno %i entrando em atendimento e sendo removido da fila \n", front);
		reallocateIndex(&front);
		
		reallocateIndex(&front);
		elementsQueue -= 1;
		
		printf("Total de elementos na fila agora: %i \n", elementsQueue);
		
		if (isEmpty(elementsQueue)) {
			front = -1;
			rear = -1;
		}
	}
}

void printQueue (struct aluno *vetor) {
	int i, index = front;
	
	if (isEmpty(elementsQueue)) {
		printf("Fila Vázia! \n");
	} else {
		for (i = 0; i < elementsQueue; i++) {
			
			printf("%i° Aluno da fila \n", index);
			
			printf("RA: %i \n", vetor[index].ra);
			
			printf("Nome: ");
			puts(vetor[index].nome);
			
			printf("Curso: ");
			puts(vetor[index].curso);
			
			printf("Assunto: ");
			puts(vetor[index].problema);
			
			reallocateIndex(&index);
		}
	}
}

void contaAssuntos (struct aluno *vetor) {
	int contador[3], i, index = front;
	
	for (i = 0; i < 3; i++) {
		contador[i] = 0;
	}
	
	for (i = 0; i < elementsQueue; i++) {
		if (strcmp(vetor[index].problema, "Protocolo") == 0) {
			
			contador[0] += 1;
		} else if (strcmp(vetor[index].problema, "Matrícula") == 0) {
			
			contador[1] += 1;
		} else {
			
			contador[2] += 1;
		}
		reallocateIndex(&index);
	}
	printf("Existem %i alunos para falar sobre Protocolo \n", contador[0]);
	printf("Existem %i alunos para falar sobre Matrícula \n", contador[1]);
	printf("Existem %i alunos para falar sobre Financeiro \n", contador[2]);	
}

void assuntoMaisFrequente(struct aluno *vetor) {
	int contador[3], i, index = front, compare = 0;
	
	for (i = 0; i < 3; i++) {
		contador[i] = 0;
	}
	
	for (i = 0; i < elementsQueue; i++) {
		if (strcmp(vetor[index].problema, "Protocolo") == 0) {
			
			contador[0] += 1;
		} else if (strcmp(vetor[index].problema, "Matrícula") == 0) {
			
			contador[1] += 1;
		} else {
			
			contador[2] += 1;
		}
		reallocateIndex(&index);
	}
	
	for (i = 0; i < 3; i++) {
		if (compare < contador[i]) {
			compare = contador [i];
			index = i;
			}
	}

	if (index == 0) {
		printf("O assunto com o maior número de alunos é Protocolo \n");
	} else if (index == 1) {
		printf("O assunto com o maior número de alunos é Matrícula \n");
	} else {
		printf("O assunto com o maior número de alunos é Financeiro \n");
	}
} 

void main (int argc, char *argv) {
	setlocale(LC_ALL,"");
	
	int opcao = 0;
	
	while (opcao != 9) {
		printf("\t * MENU *\n");
		printf("1: Adicionar aluno \n");
		printf("2: Atender \n");
		printf("3: Imprimir \n");
		printf("4: Número de alunos por assunto \n");
		printf("5: Assunto com maior número alunos \n");
		printf("9: Sair do programa \n");
		printf("Opção escolhida: ");
		scanf("%i", &opcao);
		getchar();
		printf("\n");
		
		switch (opcao) {
			case 1:
				enqueue(filaAlunos);
			break;
			
			case 2:
				dequeue(filaAlunos);
			break;
			
			case 3:
				printQueue(filaAlunos);
			break;
			
			case 4:
				contaAssuntos(filaAlunos);
			break;
			
			case 5:
				assuntoMaisFrequente(filaAlunos);
			break;
		}
	}
}

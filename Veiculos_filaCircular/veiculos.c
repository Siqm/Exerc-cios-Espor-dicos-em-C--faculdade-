#include <stdio.h>
#include <string.h>
#include <locale.h>
#define size 5

struct veiculo {
	float preco;
	char modelo[15];
	char placa [8];
};

struct veiculo carros[size];
int beg = -1, end = -1, numeroValoresFila = 0;

void iniciaVetor () {
	int i;
	for (i = 0; i < size; i++) {
		strcpy(carros[i].placa, "NULL");
		carros[i].preco = 0.0;
	}
}

void placa () {
	char placa[8];
	int i, t = 0;
	
	while (t == 0) {
		printf("Insira a placa do ve�culo: ");
		gets(placa);
		int resp;
		
		for (i = 0; i < size; i++) {
			resp = strcmp(placa, carros[i].placa);
			if (resp == 0) {
				break;
			}
		}
		
		if (resp == 0) {
			printf("A placa j� existe dentro do vetor \n");		
		} else {
			strcpy(carros[end].placa, placa);
			t=1;
		}
	}
}

void enfileirar () {
//	 Primeiro If Confirma se a Fila est� cheia ou n�o:
	if (numeroValoresFila == size) {
		printf("Fila Cheia \n");
	} else { // Se n�o estiver Cheia ent�o:
//		Segundo If checa se a fila est� vazia, se esiver
//		end e beg valer�o -1 e ser�o acrescidos para 0
//		que indicara que a fila iniciou
		if (beg == -1) {
			beg = 0;
			end = 0;
		} else if (end == (size - 1)) { // Este if checa se 
//		O end est� no final da fila, se estiver ele voltar�
//		para o inicio da fila (end = 0). LEMBRANDO:
//		O PRIMEIRO if determina se a fila est� cheia ou n�o,
//		deixando o restante do m�todo livre de verifica��o.
			end = 0;
		} else { // Se este else acontecer, signifca que o
//			O final est� no meio da fila e pode ser acrescido
			end += 1;
		}
		
//		Sempre � importante acrescer a variavel que controla
//		a quantidade de valores dentro do vetor
		numeroValoresFila += 1;
		
//		Metodo respons�vel por ler a placa e COMPARAR com outras
//		posi��es de "placa" de dentro do vetor
		placa();
		
		printf("Insira o modelo do ve�culo: ");
		gets(carros[end].modelo);
		
		printf("Insira o pre�o do ve�culo: ");
		scanf("%f", &carros[end].preco);
		getchar();				
	}
}

void desenfileirar () {
	if (numeroValoresFila == 0) {
		printf("Fila vazia, nada a remover \n");
	} else {
//		Se o inicio da fila estiver na ultima posi��o ent�o:
//		Inicio volta para posi��o 0
		if (beg == (size - 1)) {
			strcpy(carros[beg].placa, "NULL");
			carros[beg].preco = 0.0;
			beg = 0;
		} else { // Qualquer outro lugar da fila, apenas acresce em 1
			strcpy(carros[beg].placa, "NULL");
			carros[beg].preco = 0.0;
			beg += 1;
		}
		numeroValoresFila -= 1;
		
		if (numeroValoresFila == 0) {
			beg = -1;
			end = -1;
		}
		printf("Valor desenfileirado \n");
	}
}

void maiorValor() {
	int i, pos;
	float maior = -1;
	
	for (i = 0; i < size; i++) {
		if (carros[i].preco > maior) {
			maior = carros[i].preco;
			pos = i;
		}
	}
	printf("O maior valor do vetor pertence a posi��o %i e � de R$ %.2f \n", pos, maior);
}

void soma () {
	int i;
	float total;
	
	for (i = 0; i < size; i++) { 
		total += carros[i].preco;
	}
	printf("O valor total � de R$%.2f", total);
}

void imprimir () {
	
	if (numeroValoresFila == 0) {
		printf("Fila vazia \n");
	} else {
		int i, p = beg;
		
		for (i = 0; i < numeroValoresFila; i++) {
		printf("Ve�culo da posi��o %i \n", p);
		
		printf("Placa: ");
		puts(carros[p].placa);
		
		printf("Modelo: ");
		puts(carros[p].modelo);
		
		printf("Pre�o: R$%.2f \n\n", carros[p].preco);
		
		if (p == (size -1)) {
			p = 0;
		} else {
			p += 1;
		}
	}
	}
}

void pesquisaPlaca() {
	char placa[8];
	int i;
	
	printf("Insira a placa que deseja procurar: ");
	gets(placa);
	
	for (i = 0; i < size; i++) {
		if (strcmp(placa, carros[i].placa) == 0) {
			printf("Placa encontrada na posi��o: %i \n", i);
		}
	}
}

void main (int argc, char *argv[]) {
	setlocale(LC_ALL,"");
	
	int opcao = 0;
	
	iniciaVetor();
	
	while (opcao != 9) {
		printf("\t ** MENU **\n");
		printf("1: Enfileirar \n");
		printf("2: Desenfileirar \n");
		printf("3: Imprimir \n");
		printf("4: Pesquisar maior valor \n");
		printf("5: Somar todos os valores \n");
		printf("6: Pesquisar placa \n");
		printf("9: Sair do programa \n");
		printf("Op��o escolhida: ");
		scanf("%i", &opcao);
		getchar();
		printf("\n");
		
		switch (opcao) {
			case 1:
				enfileirar();
			break;
			
			case 2:
				desenfileirar();
			break;
			
			case 3:
				imprimir();
			break;
			
			case 4:
				maiorValor();
			break;
			
			case 5:
				soma();
			break;
			
			case 6:
				pesquisaPlaca();
			break;
		}
		printf("\n");
	}
}

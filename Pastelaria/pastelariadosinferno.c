#include <stdio.h>
#include <locale.h>
#define size 10

struct Pedido{
	int numero;
	int tamanho;
	int quantidade;
	float valorTotal;
};


struct Pedido vetor[size];

void inicializaVetor(struct Pedido *vetor) {
	int i;

	for (i = 0; i < size; i++) {
		vetor[i].numero = 0;
	}
}

int posicaoVazia (struct Pedido *vetor) {
	int i = 0;
	for (i = 0; i < size; i++) {
		if (vetor[i].numero == 0) { // posição vai de 0 a 9
			return i;
		}
	}
	return -1;
}

float calculaTotal (struct Pedido *vetor, int nPedido) {
	
//	Se o Tamanho for pequeno retorna o preço do correspondente
	if (vetor[nPedido].tamanho == 1) {
		return vetor[nPedido].quantidade * 3.5;
	}
	
// 	Se o Tamanho for medio retorna o preço do correspondente
	if (vetor[nPedido].tamanho == 2) {
		return vetor[nPedido].quantidade * 4.5;
	}
	
// Se o Tamanho for grande retorna o preço do correspondente
	if (vetor[nPedido].tamanho == 3) {
		return vetor[nPedido].quantidade * 5.5;
	}
}

//	Método responsável por gerenciar o número do pedido e criar um novo pedido caso haja espaço no vetor
//	Se não houver, o resultado será Vetor Cheio	
void criaPedido (struct Pedido *vetor, int *nPedido) {
	
	int i = posicaoVazia(vetor);

	if (i == -1) {
		printf("Vetor cheio");
	} else {
		*nPedido += 1;
		vetor[i].numero = *nPedido;
		printf("\nCriando pedido de numero %i\n", *nPedido);
		
		printf("Insira a quantidade de pastéis do pedido: ");
		scanf("%i", &vetor[i].quantidade);
		
		printf("\nTamanhos disponíveis \n");
		printf("1 - Tamanho pequeno \n");
		printf("2 - Tamanho médio \n");
		printf("3 - Tamanho grande \n");
		printf("Insira o tamanho dos pastéis: ");
		scanf("%i", &vetor[i].tamanho);
		
		vetor[i].valorTotal = calculaTotal(vetor, i);
	}
}

void imprimeVetor (struct Pedido *vetor) {
	int i;
	
	for (i = 0; i < size; i++) {
		if (vetor[i].numero != 0) {
			printf("Pedido Nº %i, Quantidade: %i, Tamannho: %i, Total do pedido: R$%.2f \n",
			 vetor[i].numero, vetor[i].quantidade, vetor[i].tamanho, vetor[i].valorTotal);
		} 
	}
	printf("\n");
}

void contaPedido (struct Pedido *vetor) {
	int i, conta = 0;
	
	for (i = 0; i < size; i++) {
		if (vetor[i].numero != 0) {
			conta += 1;
		}
	}
	printf("O total de pedidos é de %i \n", conta);
}

void pagamento (struct Pedido *vetor) {
	int selecao, i, verdadeiro = 0;
	
	printf("Insira o número do pedido que deseja marcar como pago: ");
	scanf("%i", &selecao);
	
	for(i = 0; i < size; i++) {
		if (vetor[i].numero == selecao) {
			printf("Apagando pedido numero %i", vetor[i].numero);
			vetor[i].numero = 0;
			verdadeiro = 1;
		} 
	}
	if (verdadeiro == 0) {
		printf("\nPedido não encontrado \n");
	}
}

int main (int argv, char *argc) {
	setlocale (LC_ALL,"");
		
	int nPedido = 0, opcao;
	int *numeroPedido = &nPedido;
	
	inicializaVetor(vetor);
	
	while (opcao != 9) {
		printf("\t * MENU *\n");
		printf("1: Adicionar pedido \n");
		printf("2: Imprimir pedidos \n");
		printf("3: Conta pedidos com pagamento pendente \n");
		printf("4: Marcar pedido como pago \n");
		printf("9: Sair do programa \n");
		printf("Opção escolhida: ");
		scanf("%i", &opcao);
		printf("\n");
		
		switch (opcao) {
			case 1:
				criaPedido (vetor, numeroPedido);
			break;
			
			case 2:
				imprimeVetor(vetor);
			break;
			
			case 3:
				contaPedido(vetor);
			break;
			
			case 4:
				pagamento(vetor);
			break;
		}
	}
	

}

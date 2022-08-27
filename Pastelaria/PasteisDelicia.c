typedef struct {
	int numero;
	int tamanho;
	int quantidade;
	
} pedido;

int size = 10;
pedido lista[size];


void iniciaVetor(pedido *vetor) {
	int i;
	for (i = 0; i < size; i++) {
		vetor[i].numero = 0;
	}
}

int posicaoVazia(pedido *vetor) {
	for (i = 0; i < size; i++) {
		if (vetor[i].numero == 0) {
			return i;
		} else {
			printf("Vetor Cheio");
		}
	}
}

void novoPedido(pedido *vetor, int *nPedido) {
	
	int i = posicaoVazia(vetor);
	*nPedido += 1;
	vetor[i].numero = *nPedido;
	
	printf("Insira a quantidade de pastéis do pedido: ");
	scanf("%i", &vetor[i].quantidade);
	
	printf("Insira o tamanho do pastel \n");
	printf("1 - Pequeno \n");
	printf("2 - Médio \n");
	printf("3 - Grande \n");
	printf("Tamanho escolhido: ");
	scanf("%i", &vetor[i].tamanho);
}

void imprimePedidos (pedido *vetor) {
	int i;
	
	printf("Pedidos a pagar \n");
	for (i = 0; i < size; i++) {
		printf("Pedido nº%i", vetor[i].numero);
	}
}

void contaPedidos (pedido *vetor) {
	
	int contador, i;
	
	for (i =0; i < size; i++) {
		if (vetor[i].numero != 0) {
			contador +=1;
		}
	}
	printf("A quantidade de pedidos a poagar é de %i", contador);
}

void pagamento (pedido *vetor) {
	int consulta;
	
	printf("Insira o número do pedido: ");
	scanf("%i", &consulta);
	
	for (i = 0; i < size; i++) {
		if (vetor[i].numero == consulta) {
			printf("Quantidade de pasteis: %i \n", vetor[i].quantidade);
			printf("Tamanho dos pastéis: %i \n", vetor[i].tamanho);
			
			if (vetor[i].tamanho == 1) {	
			}
		}
	}
}

void main (int argc, char *argv) {
	int pequeno = 3.5;
	int medio = 4.5;
	int grande = 5.5;
	int numeroPedido = 0;
	
	
	novoPedido(lista, &numeroPedido);
}
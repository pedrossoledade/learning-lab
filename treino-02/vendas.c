#include <stdio.h>
#include <stdlib.h>

#ifdef LINUX
#define CLEAR "clear"
#define PAUSE "read -p \"Pressione enter para continuar...\""
#else
#define CLEAR "cls"
#define PAUSE "pause"
#endif


typedef struct {
    char nome[20];
    float preco;
    int estoque;
} Produto;


void inserirDinheiro(float *saldo) {
    float notas[] = { 2.0f, 5.0f, 10.0f, 20.0f, 50.0f, 100.0f };
    int notas_qtd = sizeof(notas) / sizeof(float);

    printf("Saldo: R$%.2f\n", *saldo);
    for(int i = 0; i < notas_qtd; i++) {
        printf("%d. R$%.2f\n", i+1, notas[i]);
    }
    printf("Escolha uma nota para inserir (0 para sair): ");

    int escolha;
    scanf("%d", &escolha);
    if(escolha == 0) {
        return;
    } else if (escolha >= 1 && escolha <= notas_qtd) {
        *saldo += notas[escolha - 1];
    } else {
        printf("Opção Inválida!\n");
    }

}


void exibirProdutos(Produto *maquina[], int tamanho, float saldo) {
    system(CLEAR);
    printf("********** Máquina de Vendas **********\n");
    printf("Saldo: R$%.2f\n", saldo);
    printf("Produtos disponíveis:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("%d. %s\t- R$%.2f (Em estoque: %d)\n",
       i + 1, maquina[i]->nome, maquina[i]->preco, maquina[i]->estoque );
    }
    
    printf("0. Sair\n");

}

void vender(Produto* produto, float* saldo, int* quantidade) {
    produto->estoque = produto->estoque - *quantidade;
    *saldo -= produto->preco * *quantidade;
}


int main() {
    Produto itens[] = {
        { "Refrigerante", 6.0, 10 },
        { "Chocolate", 4.0, 20 },
        { "Salgadinho", 5.0, 15 },
        { "Suco", 6.0, 12 }
    };
    
    const int PRODUTOS_QTD = sizeof(itens) / sizeof(Produto);
    Produto *maquina[PRODUTOS_QTD];
    for(int i = 0; i < PRODUTOS_QTD; i++) {
        maquina[i] = &itens[i];
    }
    // printf("Tamanho da lista: %d\n", PRODUTOS_QTD);

    float saldo = 0.0f;
    int opcao = -1;
    int quantidade = -1;
    while(opcao != 0) {
        system(CLEAR);
        inserirDinheiro(&saldo);
        // printf("Saldo: R$%.2f\n", saldo);
        exibirProdutos(maquina, PRODUTOS_QTD, saldo);
        printf("\nEscolha o número do produto: ");
        scanf("%d", &opcao);

        if (opcao == 0)
            break;
            else if (opcao >= 1 && opcao <= PRODUTOS_QTD) {
                Produto* p = maquina[opcao - 1];
                if (p->estoque <= 0) {
                    printf("Produto fora de estoque!\n");
                } else if (saldo < p->preco) {
                    printf("Saldo insuficiente!\n");
                } else {
                    printf("\nEscolha a quantidade do produto: ");
                    scanf("%d", &quantidade);
                    vender(p, &saldo, &quantidade);
                    printf("Você comprou: %d %s(s)\n", quantidade, p->nome);
                }
                system(PAUSE);
            }
    
    }
    system(CLEAR);
    printf("Compra bem sucedida!\nPrograma encerrado!\n\n");

    return 0;
}

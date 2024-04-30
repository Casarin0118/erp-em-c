#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definir uma estrutura para os produtos
typedef struct {
    char nome[50];
    int quantidade;
} Produto;

// Variáveis globais
Produto estoque[100]; // Capacidade máxima de 100 produtos
int numProdutos = 0; // Número atual de produtos no estoque

// Função para adicionar um novo produto ao estoque
void adicionarProduto() {
    if (numProdutos >= 100) {
        printf("O estoque está cheio!\n");
        return;
    }

    printf("Digite o nome do produto: ");
    scanf("%s", estoque[numProdutos].nome);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &estoque[numProdutos].quantidade);

    numProdutos++;
    printf("Produto adicionado com sucesso!\n");
}

// Função para exibir todos os produtos no estoque
void exibirEstoque() {
    if (numProdutos == 0) {
        printf("O estoque está vazio!\n");
        return;
    }else
    {
         printf("Produtos no estoque:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("%s - Quantidade: %d\n", estoque[i].nome, estoque[i].quantidade);
    }
    }
    

   
}

// Função para atualizar a quantidade de um produto no estoque
void atualizarQuantidade() {
    char nome[50];
    int novaQuantidade;

    printf("Digite o nome do produto que deseja atualizar: ");
    scanf("%s", nome);

    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(estoque[i].nome, nome) == 0) {
            printf("Digite a nova quantidade do produto: ");
            scanf("%d", &novaQuantidade);
            estoque[i].quantidade = novaQuantidade;
            printf("Quantidade do produto atualizada com sucesso!\n");
            return;
        }
    }

    printf("Produto nao encontrado no estoque!\n");
}

// Função para remover um produto do estoque
void removerProduto() {
    char nome[50];

    printf("Digite o nome do produto que deseja remover: ");
    scanf("%s", nome);

    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(estoque[i].nome, nome) == 0) {
            // Move o último produto para a posição do produto a ser removido
            estoque[i] = estoque[numProdutos - 1];
            numProdutos--;
            printf("Produto removido com sucesso!\n");
            return;
        }
    }

    printf("Produto nao encontrado no estoque!\n");
}

int main() {
    int escolha;

    while (1) {
        printf("\n======= MENU =======\n");
        printf("1. Adicionar produto\n");
        printf("2. Exibir estoque\n");
        printf("3. Atualizar quantidade\n");
        printf("4. Remover produto\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                exibirEstoque();
                break;
            case 3:
                atualizarQuantidade();
                break;
            case 4:
                removerProduto();
                break;
            case 5:
                printf("Saindo do sistema.\n");
                exit(0);
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}
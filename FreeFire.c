// Nível Novato - Começo //

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definindo o tamanho máximo da mochila (Lista Estática)
#define MAX_ITENS 10

// 1. Definição da Struct Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Protótipos das funções obrigatórias
void inserirItem(Item mochila[], int *total);
void listarItens(Item mochila[], int total);
void buscarItem(Item mochila[], int total);
void removerItem(Item mochila[], int *total);

// --- FUNÇÃO PRINCIPAL ---
int main() {
    Item mochila[MAX_ITENS]; // O vetor estático (a mochila)
    int total_itens = 0;     // Contador de quantos itens existem na mochila
    int opcao;

    // Game Loop - Menu de interações
    do {
        printf("\n=== MOCHILA DE SOBREVIVENCIA ===\n");
        printf("1. Inserir Item\n");
        printf("2. Listar Itens\n");
        printf("3. Buscar Item\n");
        printf("4. Remover Item\n");
        printf("0. Sair do Jogo\n");
        printf("Escolha uma acao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserirItem(mochila, &total_itens);
                break;
            case 2:
                listarItens(mochila, total_itens);
                break;
            case 3:
                buscarItem(mochila, total_itens);
                break;
            case 4:
                removerItem(mochila, &total_itens);
                break;
            case 0:
                printf("\nSaindo do inventario. Sobreviva a ilha!\n");
                break;
            default:
                printf("\nAcao invalida! Escolha uma opcao do menu.\n");
        }
    } while(opcao != 0);

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

// Função para cadastrar um novo item na mochila
void inserirItem(Item mochila[], int *total) {
    // Verifica se a mochila já está cheia
    if (*total >= MAX_ITENS) {
        printf("\n[ALERTA] Mochila cheia! Nao e possivel carregar mais itens.\n");
        return;
    }

    printf("\n--- NOVO LOOT ---\n");
    // O índice [*total] para salvar na próxima posição vazia do vetor
    printf("Nome do item: ");
    scanf(" %[^\n]", mochila[*total].nome);

    printf("Tipo (ex: Arma, Cura, Municao): ");
    scanf(" %[^\n]", mochila[*total].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);

    // Incrementa o contador de itens
    (*total)++;
    printf("[SUCESSO] Item guardado na mochila!\n");
    
    // Chamada automática para listar a mochila após a inserção (Requisito da Faculdade)
    listarItens(mochila, *total);
}

// Função para exibir todos os itens guardados
void listarItens(Item mochila[], int total) {
    if (total == 0) {
        printf("\n[STATUS] Sua mochila esta vazia.\n");
        return;
    }

    printf("\n--- INVENTARIO ATUAL (%d/10) ---\n", total);
    // Laço de repetição para percorrer o vetor até o limite de itens cadastrados
    for (int i = 0; i < total; i++) {
        printf("[%d] %s | Tipo: %s | Qtd: %d\n", i+1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Função de Busca Sequencial
void buscarItem(Item mochila[], int total) {
    char nomeBusca[30];
    printf("\n--- BUSCAR ITEM ---\n");
    printf("Digite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nomeBusca);

    // 1. Laço para percorrer a mochila
    for (int i = 0; i < total; i++) {
        // 2. Compara o nome da gaveta com o nome digitado
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\n[ENCONTRADO] %s | Tipo: %s | Qtd: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return; // Encerra a função assim que encontrar
        }
    }
    
    // 3. Se o laço inteiro rodou e não achou, cai aqui
    printf("\n[SISTEMA] O item '%s' nao esta na mochila.\n", nomeBusca);
}

// Função de Remoção com deslocamento
void removerItem(Item mochila[], int *total) {
    char nomeRemover[30];
    int indice = -1; // Variável para guardar a posição do item (-1 significa que não achou)
    
    printf("\n--- DESCARTAR ITEM ---\n");
    printf("Digite o nome do item que deseja jogar fora: ");
    scanf(" %[^\n]", nomeRemover);

    // 1. Busca sequencial para descobrir em qual gaveta (índice) o item está
    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            indice = i; // Achou, Salva o índice.
            break;      // Para a busca imediatamente.
        }
    }

    // 2. Se achou o item (índice mudou de -1)
    if (indice != -1) {
        // Cria um laço começando da gaveta que queremos apagar até a penúltima ocupada
        for (int i = indice; i < (*total) - 1; i++) {
            // Copia o item da frente para a gaveta atual (Esmaga o item antigo)
            mochila[i] = mochila[i+1];
        }
        
        // 3. Diminui o total de itens
        (*total)--;
        printf("\n[SUCESSO] O item '%s' foi descartado!\n", nomeRemover);
        
        // Chamada automática para listar a mochila após deletar (Requisito da Faculdade)
        listarItens(mochila, *total);
    } else {
        printf("\n[SISTEMA] O item '%s' nao foi encontrado para remocao.\n", nomeRemover);
    }
}
// Nível Novato - Fim //
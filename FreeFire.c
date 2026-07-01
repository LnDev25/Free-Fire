// Nível Novato/Aventureiro/ - Começo //

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

// Caixa da Lista Encadeada
typedef struct No {
    Item dados ;
    struct No* proximo ;
} No;

// Protótipos das funções obrigatórias
void inserirItemVetor(Item mochila[], int *total);
void listarItensVetor(Item mochila[], int total);
void buscarItemVetor(Item mochila[], int total);
void removerItemVetor(Item mochila[], int *total);

// Protótipos das funções da Lista Encadeada
void inserirItemLista(No **inicio);
void listarItensLista(No *inicio);
void buscarItemLista(No *inicio);
void removerItemLista(No **inicio);

// --- FUNÇÃO PRINCIPAL ---
int main() {
    int tipo_mochila;
    int opcao;

    // Variáveis do Vetor
    Item mochilaVetor[MAX_ITENS]; 
    int total_itens = 0;    

    // Variáveis da Lista Encadeada (Iniciando vazia)
    No* mochilaLista = NULL;

    printf("\n=== BATTLE ROYALE: ESCOLHA SEU EQUIPAMENTO ===\n");
    printf("1. Mochila Rigida (Vetor - Limite 10 itens)\n");
    printf("2. Mochila Expansivel (Lista Encadeada - Ilimitada)\n");
    printf("Escolha sua estrategia: ");
    scanf("%d", &tipo_mochila);

    if (tipo_mochila == 1) {
        
        // Game Loop - Menu de interações DO VETOR
        do {
            printf("\n=== MOCHILA DE SOBREVIVENCIA (VETOR) ===\n");
            printf("1. Inserir Item\n");
            printf("2. Listar Itens\n");
            printf("3. Buscar Item\n");
            printf("4. Remover Item\n");
            printf("0. Sair do Jogo\n");
            printf("Escolha uma acao: ");
            scanf("%d", &opcao);

            switch(opcao) {
                case 1: inserirItemVetor(mochilaVetor, &total_itens); break;
                case 2: listarItensVetor(mochilaVetor, total_itens); break;
                case 3: buscarItemVetor(mochilaVetor, total_itens); break;
                case 4: removerItemVetor(mochilaVetor, &total_itens); break;
                case 0: printf("\nSaindo do inventario. Sobreviva a ilha!\n"); break;
                default: printf("\nAcao invalida! Escolha uma opcao do menu.\n");
            }   

        } while(opcao != 0);

} else if (tipo_mochila == 2) {
        
        // Game Loop - Menu de interações DA LISTA ENCADEADA
        do {
            printf("\n=== MOCHILA EXPANSIVEL (LISTA) ===\n");
            printf("1. Inserir Item\n");
            printf("2. Listar Itens\n");
            printf("3. Buscar Item\n");
            printf("4. Remover Item\n");
            printf("0. Sair do Jogo\n");
            printf("Escolha uma acao: ");
            scanf("%d", &opcao);

            switch(opcao) {
                case 1: inserirItemLista(&mochilaLista); break; // Passa o endereço (ponteiro duplo)
                case 2: listarItensLista(mochilaLista); break;  // Passa o ponteiro simples
                case 3: buscarItemLista(mochilaLista); break;   // Passa o ponteiro simples
                case 4: removerItemLista(&mochilaLista); break; // Passa o endereço (ponteiro duplo)
                case 0: printf("\nSaindo do inventario. Sobreviva a ilha!\n"); break;
                default: printf("\nAcao invalida! Escolha uma opcao do menu.\n");
            }   

        } while(opcao != 0);

    } else {

        printf("Equipamento invalido");

    }

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

// VETOR
// Função para cadastrar um novo item na mochila
void inserirItemVetor(Item mochila[], int *total) {
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
    listarItensVetor(mochila, *total);
}

// Função para exibir todos os itens guardados
void listarItensVetor(Item mochila[], int total) {
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
void buscarItemVetor(Item mochila[], int total) {
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
void removerItemVetor(Item mochila[], int *total) {
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
        listarItensVetor(mochila, *total);
    } else {
        printf("\n[SISTEMA] O item '%s' nao foi encontrado para remocao.\n", nomeRemover);
    }
}

// LISTA
// Função de Listar
void listarItensLista(No *inicio) {
    No* atual = inicio;
    if (inicio == NULL) {
        printf ("\n[SISTEMA] Não ha loot Disponível.\n"); 
        return;
    } else {
        while (atual != NULL)
        {
            printf("Item: %s | Tipo: %s | Qtd: %d\n", atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
            atual = atual->proximo;
        }   
    }
}

// Função de Buscar
void buscarItemLista (No *inicio) {
    
    char nomeBusca[30] ;
    printf("\n Qual Item você quer buscar?\n");
    scanf(" %[^\n]", nomeBusca) ;

    No* atual = inicio;
    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nomeBusca) == 0) {
            printf("\n[ENCONTRADO] O item '%s'\n", nomeBusca);
            return ;
        } else {
            atual = atual -> proximo;
        }

    }
    printf("\n[SISTEMA] O item '%s' nao foi encontrado na busca.\n", nomeBusca);
}

// Funcão de Inserir
void inserirItemLista(No **inicio) {
    No* novoNo = (No*) malloc(sizeof(No)) ;

    printf("\nQual o nome do Item que deseja inserir?\n") ;
    scanf(" %[^\n]", novoNo->dados.nome) ;

    printf("\nQual o tipo do Item que deseja inserir?\n") ;
    scanf(" %[^\n]", novoNo->dados.tipo) ;

    printf("\nQual a quantidade do Item que deseja inserir?\n") ;
    scanf("%d", &novoNo->dados.quantidade) ;

    novoNo->proximo = *inicio;
    *inicio = novoNo;

    printf(" [SUCESSO] Item Guardado na mochila") ;
    listarItensLista(*inicio);
}

// Função Remover
void removerItemLista(No **inicio) {

    char nomeRemover[30];
    printf("Digite o nome do item que deseja jogar fora: ");
    scanf(" %[^\n]", nomeRemover);

    No* atual = *inicio;
    No* anterior = NULL;

    while (atual != NULL && strcmp(atual->dados.nome, nomeRemover) != 0) {
        anterior = atual ;
        atual = atual -> proximo ;
    }

    if (atual == NULL) {
        printf("\n[SISTEMA] Item nao encontrado!\n");
        return;
    }

    // A cirurgia segura:
    if (anterior == NULL) {
        // Cenário A: O item era o primeiro da fila
        *inicio = atual->proximo; 
    } else {
        // Cenário B: O item estava no meio ou no final
        anterior->proximo = atual->proximo; 
    }

    free(atual);
    printf("\n[SUCESSO] Item descartado!\n");
    listarItensLista(*inicio);
}

// Nível Novato/Aventureiro/ - Fim //
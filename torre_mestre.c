// Nível Mestre - Começo //

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Struct da torre
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

// Funções 
void mostrarComponentes(Componente torre [], int total);
void cadastrarComponente(Componente torre[], int *total);
void bubbleSortNome(Componente torre[], int total);
void selectionSortPrioridade(Componente torre[], int total);
void insertionSortTipo(Componente torre[], int total);
void medirTempo(void (*algoritmo)(Componente[], int), Componente vetor[], int tamanho);

// A Main
int main () {

    int total_itens = 0;
    int opcao;

    Componente torre[20]; 
    
    // Menu de interações 
    do {

        printf("\n=== TORRE MESTRE ===\n");
        printf("1. Cadastrar Componentes\n");
        printf("2. Listar Componentes\n");
        printf("3. Ordenar por Nome (Bubble Sort)\n");
        printf("4. Ordenar por Prioridade (Selection Sort)\n");
        printf("5. Ordenar por Tipo (Insertion Sort)\n");
        printf("6. Buscar Componente-Chave (Busca Binaria)\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {

            case 1: cadastrarComponente(torre, &total_itens); break ;
            case 2: mostrarComponentes(torre, total_itens); break ;

            case 3:
                   medirTempo(bubbleSortNome, torre, total_itens); 
                   mostrarComponentes(torre, total_itens);
                   break;

            case 4: 
                    selectionSortPrioridade(torre, total_itens); 
                    mostrarComponentes(torre, total_itens);
                    break;

            case 5: 
                    insertionSortTipo(torre, total_itens); 
                    mostrarComponentes(torre, total_itens);
                    break;

            case 6: 
                    buscaBinariaPorNome(torre, total_itens); 
                    break;

            case 0: printf("\nSaindo da torre. Sobreviva a ilha!\n"); break;
            default: printf("\nAcao invalida! Escolha uma opcao do menu.\n");

        }

    } while (opcao != 0) ;

   return 0 ;

}

// Função de cadastro
void cadastrarComponente(Componente torre[], int *total) {

    // Capturando com fgets
    printf("Nome do componente: ");
    fgets(torre[*total].nome, 30, stdin);
    torre[*total].nome[strcspn(torre[*total].nome, "\n")] = '\0'; // Limpa o Enter

    printf("Tipo do componente: ");
    fgets(torre[*total].tipo, 20, stdin);
    torre[*total].tipo[strcspn(torre[*total].tipo, "\n")] = '\0'; 

    printf("Qual a prioridade do componente: ");
    scanf("%d", &torre[*total].prioridade);
    getchar();
   
    (*total)++;

}

// Função de exibir
void mostrarComponentes(Componente torre[], int total) {

    if (total == 0) {
        printf ("\n Nenhum componente encontrado\n") ;
    } else {
        for (int i = 0; i < total; i++)
        printf("[%d] %s | Tipo: %s | Prioridade: %d\n", i+1, torre[i].nome, torre[i].tipo, torre[i].prioridade);
    }
}

// Bubble Sort (Ordem Alfabética)
void bubbleSortNome(Componente torre[], int total) {
    int comparacoes = 0;

    // Laço de fora (quantas passadas)
    for (int i = 0; i < total - 1; i++) {
        // Laço de dentro (compara vizinhos)
        for (int j = 0; j < total - i - 1; j++) {
            
            comparacoes++; // Conta que vai fazer uma comparação
            
            // Se o vizinho atual for maior que o da frente (alfabeticamente)
            if (strcmp(torre[j].nome, torre[j+1].nome) > 0) {
                // A grande troca (Swap)
                Componente temp = torre[j];
                torre[j] = torre[j+1];
                torre[j+1] = temp;
            }
        }
    }
    
    // Mostra o relatório final
    printf("\n[SISTEMA] Bubble Sort concluido! Comparacoes realizadas por Nome %d\n", comparacoes);
}

// A Engenharia do Selection Sort (Por Prioridade)
void selectionSortPrioridade(Componente torre[], int total) {
    int comparacoes = 0;

    for (int i = 0; i < total - 1; i++) {
        int indice_menor = i;
        for (int j = i + 1; j < total; j++) {
            comparacoes++ ;
            if (torre[j].prioridade < torre [indice_menor].prioridade) {
                indice_menor = j;
            }
        }

        if (indice_menor != i) {
        Componente temp = torre[i];
        torre[i] = torre[indice_menor];
        torre[indice_menor] = temp;
        }
    }
    printf("\n[SISTEMA] Selection Sort concluido! Comparacao Realizada por Prioridade: %d\n", comparacoes);
}

// Algoritmo: Insertion Sort (Por Tipo)
void insertionSortTipo(Componente torre[], int total) {
    int comparacoes = 0;
    
    for (int i = 1; i < total; i++) {
        Componente chave = torre[i];
        int j = i - 1;
        while (j >= 0) {
            comparacoes++ ;

            if (strcmp(torre[j].tipo, chave.tipo) > 0) {
                torre[ j + 1] = torre [j];
                j--;
            } else {
                break;
            }
        }
        torre[j + 1] = chave;
    }
    printf("\n[SISTEMA] Insertion Sort concluido! Comparacao Realizada por Tipo: %d\n", comparacoes);
}

// Algoritmo: Busca Binária (Requer ordenação prévia por Nome)
void buscaBinariaPorNome(Componente torre[], int total) {
    char nomeBusca[30];
    printf("\nDigite o nome do componente chave: ");
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; // Limpa o Enter

    int inicio = 0;
    int fim = total - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        int comparacao = strcmp(torre[meio].nome, nomeBusca);

        if (comparacao == 0) {
            printf("\n[ENCONTRADO] %s | Tipo: %s | Prioridade: %d\n", torre[meio].nome, torre[meio].tipo, torre[meio].prioridade);
            return; // Aborta e sai da função
        } else if (comparacao < 0) {
            inicio = meio + 1; // Pula pra direita
        } else {
            fim = meio - 1; // Pula pra esquerda
        }
    }
    printf("\n[SISTEMA] Componente-chave '%s' nao encontrado!\n", nomeBusca);
}

// Medidor de Desempenho
void medirTempo(void (*algoritmo)(Componente[], int), Componente vetor[], int tamanho) {
    clock_t inicio = clock(); // Dispara o cronômetro
    
    algoritmo(vetor, tamanho); // Roda o algoritmo escolhido
    
    clock_t fim = clock(); // Para o cronômetro
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    printf("[DESEMPENHO] Tempo de execucao: %f segundos\n", tempo_gasto);
}
// Nível Mestre - Fim //
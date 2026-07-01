README
🔫🎒 Desafio Código da Ilha – Edição Free Fire
Bem-vindo ao Desafio Código da Ilha – Edição Free Fire!
Neste desafio, você irá simular o gerenciamento de um inventário de sobrevivência em uma ilha misteriosa, utilizando a linguagem C.

A empresa MateCheck encarregou você de desenvolver o sistema de mochila virtual que ajudará os sobreviventes a se prepararem para escapar da ilha.
O desafio é dividido em três níveis: Novato, Aventureiro e Mestre, cada um com mais complexidade e poder.

🎮 Nível Novato: Inventário Básico
🚩 Objetivo
Criar um programa em C com as seguintes funcionalidades:

Adicionar itens à mochila (nome, tipo e quantidade)
Remover itens pelo nome
Listar os itens cadastrados
⚙️ Funcionalidades
Utilização de struct para representar cada item
Vetor estático com capacidade para até 10 itens
Leitura e escrita via terminal (scanf, printf)
Menu interativo com switch e do-while
🧠 Simplicidade
Sem ordenações, buscas especializadas ou uso de ponteiros
Ideal para praticar manipulação básica de estruturas e arrays
📥 Entrada
O usuário escolhe ações no menu e preenche os dados dos itens conforme solicitado.

📤 Saída
O programa exibe os dados organizados em formato de tabela, com nome, tipo e quantidade.

🛡️ Nível Aventureiro: Mochila com Busca
🆕 Diferenças em relação ao Nível Novato
Implementação de busca sequencial por nome
Novidade no menu: opção de "Buscar item por nome"
Exibição detalhada do item encontrado
⚙️ Funcionalidades
O usuário pode procurar qualquer item já inserido
Se encontrado, o programa exibe seus atributos
Caso contrário, exibe mensagem de erro amigável
💡 Conceitos Adicionados
Busca sequencial
Comparação de strings (strcmp)
Controle com flag para indicar se item foi encontrado
📥 Entrada
O usuário digita o nome do item que deseja buscar.

📤 Saída
Detalhes completos do item (nome, tipo, quantidade)
Ou uma mensagem de erro, se não for encontrado
🧠 Nível Mestre: Ordenação e Busca Binária
🆕 Diferenças em relação ao Nível Aventureiro
Adição do campo prioridade aos itens (valores de 1 a 5)
Possibilidade de ordenar a mochila por nome, tipo ou prioridade
Implementação da busca binária por nome com verificação de ordenação
⚙️ Funcionalidades
Menu de ordenação: o jogador escolhe o critério desejado
Contador de comparações na ordenação para análise de desempenho
Busca binária com validação de pré-requisito (lista deve estar ordenada por nome)
💡 Conceitos Adicionados
Enumeração (enum) para critérios de ordenação
Ordenação com Insertion Sort
Busca binária (binary search)
Uso de bool para controle de estado
Análise de desempenho com contador de comparações
📥 Entrada
O usuário:

Adiciona itens com prioridade
Ordena os itens
Realiza busca binária pelo nome do item
📤 Saída
Mochila ordenada com base no critério escolhido
Exibição dos dados do item buscado ou mensagem de erro
Quantidade de comparações realizadas durante a ordenação
🏁 Conclusão
Ao completar qualquer nível do Desafio Código da Ilha – Edição Free Fire, você terá avançado significativamente na programação em C, desenvolvendo habilidades práticas de:

Manipulação de estruturas e arrays
Criação de menus interativos
Implementação de buscas e ordenações
Pensamento modular e boas práticas de software
Cada nível representa uma missão rumo à sobrevivência total.
Escolha seu nível, prepare sua mochila... e boa sorte na ilha! 🏝️💼🔍

Equipe de Ensino – MateCheck

----------------------------------------------------------------------------------------------------------

Nível Novato CHECK 1.0

# 🎒 Inventário de Sobrevivência: Ilha TechNova (Nível Novato)

Este projeto é a primeira fase do desenvolvimento de um sistema de inventário para um jogo de sobrevivência no estilo *Battle Royale*. O sistema foi projetado para gerenciar os *loots* coletados pelo jogador durante a partida, utilizando os conceitos fundamentais da linguagem C.

## 🎯 Objetivo do Nível
Implementar uma **Lista Linear Estática** utilizando arrays e `structs` para representar a mochila inicial do jogador, com um limite fixo de espaços e manipulação direta de memória.

## 🛠️ Funcionalidades Desenvolvidas
* **Inserção de Itens:** Cadastro de *loot* com nome, tipo (ex: Arma, Cura, Munição) e quantidade, respeitando o limite máximo de 10 posições.
* **Listagem Automática:** Exibição em tempo real do conteúdo da mochila, formatada para fácil visualização pelo jogador após cada ação de entrada ou saída.
* **Busca Sequencial:** Varredura completa do array para localizar itens específicos utilizando comparação de strings (`strcmp`).
* **Remoção com Deslocamento:** Exclusão de itens do inventário reorganizando a memória sequencialmente (sobrescrevendo o espaço vazio com os itens seguintes) para manter a integridade da lista.

## 💻 Tecnologias e Estruturas
* **Linguagem:** C
* **Estrutura de Dados:** Array Estático (`Item mochila[MAX_ITENS]`)
* **Tipos de Dados:** `structs` e ponteiros (`*total`) para passagem de parâmetros por referência.
* **Ambiente:** GitHub Codespaces / GCC Compiler

## 🚀 Como Executar

1. Compile o código-fonte utilizando o GCC:
   ```bash
   gcc inventario.c -o inventario

   -------------------------------------------------------------------------------------------------------

Nível Aventureiro 2.0

# 🎒 Inventário de Sobrevivência: Ilha TechNova (Nível Aventureiro)

Nesta segunda fase do desenvolvimento do sistema de inventário, o projeto evolui para testar os limites do gerenciamento de memória em C. O objetivo deste nível é colocar duas estruturas de dados lado a lado e analisar suas diferenças de implementação e flexibilidade.

## 🎯 Objetivo do Nível
Implementar e comparar paralelamente um sistema de inventário utilizando **Vetores (Lista Linear Estática)** e **Listas Encadeadas (Lista Linear Dinâmica)**, permitindo ao jogador escolher sua estratégia no início da partida.

## 🛠️ O Confronto de Estruturas

### 1. Mochila Rígida (Vetor)
* **Característica:** Memória alocada estaticamente (`Item mochila[10]`).
* **Vantagem:** Navegação rápida e direta (acesso por índice).
* **Desvantagem:** Tamanho fixo (limite de 10 itens). Se a mochila encher, não é possível pegar mais *loot*. Ocupa memória mesmo se estiver vazia.

### 2. Mochila Expansível (Lista Encadeada)
* **Característica:** Memória alocada dinamicamente (`malloc`). 
* **Vantagem:** Tamanho ilimitado. A mochila cresce sob demanda, alocando memória apenas quando um novo item é encontrado, e liberando (`free`) quando é descartado.
* **Desvantagem:** Navegação sequencial obrigatória via ponteiros (`->proximo`), o que pode ser mais lento para buscas em inventários colossais.

## 🚀 Como Executar

1. Compile o código-fonte utilizando o GCC:
   ```bash
   gcc inventario_aventureiro.c -o inventario_v2

   ------------------------------------------------------------------------------------------------------------------------------------------------

   
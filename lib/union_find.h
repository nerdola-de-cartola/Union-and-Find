#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   struct Node *left;
   struct Node *right;
   int height;

   double valor;
   
   struct Node *representante;
   struct Node *proximo;
} Node;

/**
 * @brief Cria um conjunto contendo somente o valor x
 * 
 * @param x Valor para criação e representação do conjunto
 * @return Conjunto que contém o valor x
 */
Node Make_Set(double x);

/**
 * @brief Exibe na saída padrão o conjunto que contém x
 * 
 * @param x Ponteiro que aponta para um elemento do conjunto a ser exibido
 */
void Show_Set(double x);

/**
 * @brief Exibe na saída padrão o conjunto i
 * 
 * @param i Índice do conjunto
 */
void Show_SetI(int i);

/**
 * @brief Libera a memoria do conjunto que contém x
 * 
 * @param x Ponteiro que aponta para um elemento do conjunto que será removido
 */
void Destroy_set(double x);

/**
 * @brief Libera a memoria do conjunto i
 * 
 * @param i Índice do conjunto a ser liberado
 */
void Destroy_setI(int i);

/**
 * @brief Faz a união do conjunto que contém x com
 * o conjunto que contém y
 * 
 * @param x Ponteiro que aponta para x
 * @param y Ponteiro que aponta para y
 */
void Union(double x, double y);

/**
 * @brief Faz a união do conjunto i com
 * o conjunto j
 * 
 * @param x Índice do conjunto
 * @param y Índice do conjunto
 */
void UnionI(int i, int j);

/**
 * @brief Encontra o conjunto que contém x se existir
 * 
 * @param x Ponteiro para o elemento que se deseja encontrar
 * @return Ponteiro que aponta para o conjunto
 * que contém x ou NULL,
 */
Node *Find_set(double x);

/**
 * @brief Devolve o tamanho do conjunto que contém x
 * 
 * @param x Ponteiro para um elemento do conjunto
 * @return int 
 */
int Size_set(double x);

/**
 * @brief Devolve o tamanho do conjunto i
 * 
 * @param i Índice do conjunto
 * @return int 
 */
int Size_setI(int i);



/********************************************************

                    AVL TREE CODE

********************************************************/
/**
 * @brief Cria uma árvore vazia
 * 
 * @return Ponteiro para a raiz
 */
Node *createTree();

/**
 * @brief Cria o nó de uma árvore
 * 
 * @param valor, dados a serem inseridos 
 * @return Retorna a nova raiz
 */
Node *createNode(int valor);

/**
 * @brief Quantidade de nós em uma árvore, tempo O(log(N)
 * 
 * @param root Ponteiro para a raiz
 * @return Retorna a quantidade de nós inseridos
 */
int sizeTree(Node *root);

/**
 * @brief Insere um novo dado em uma árvore
 * 
 * @param root raiz da árvore a ser inserida
 * @param newvalor novo dado
 * @return Retorna a raiz da nova árvore
 */
void insert(Node **root, int newvalor);

/**
 * @brief Insere um novo dado em uma árvore
 * 
 * @param root raiz da árvore a ser inserida
 * @param newNode novo nó
 * @return Retorna a raiz da nova árvore
 */
Node *insertNode(Node *root, Node *newNode);

/**
 * @brief Verifica se um valor existe ou não
 * em uma árvore
 * 
 * @param root Ponteiro para a raiz 
 * @param valor valor a ser encontrado 
 * @return Um ponteiro para o nó, ou NULL
 * caso o nó não exist
 */
Node *searchTree(Node *root, int valor);

/**
 * @brief Retorna a altura de um nó na árvore
 * 
 * @param root Ponteiro para o nó desejado
 * @return Altura do nó
 */
int height(Node *root);

/**
 * @brief
 * 
 * @param x 
 * @param y 
 * @return Retorna o máximo entre x e y
 */
int max(int x, int y);

/**
 * @brief Encontra o fator de balanceamento de um nó
 * 
 * @param root Ponteiro para o nó
 * @return Retorna o fator de balanceamento
 */
int getBalance(Node *root);

/**
 * @brief Imprime a árvore em prefix
 * 
 * @param root Ponteiro para a raiz da árvore
 */
void prefix(Node *root);


/**
 * @brief Imprime a árvore em infix
 * 
 * @param root Ponteiro para a raiz da árvore
 */
void infix(Node *root);

/**
 * @brief Imprime a árvore em postfix
 * 
 * @param root Ponteiro para a raiz da árvore
 */
void postfix(Node *root);

/**
 * @brief Imprime os nós da árvore com 
 * sua altura e fator de balanceamento
 * 
 * @param root Ponteiro para a raiz da árvore
 * @param repeater Controla a quantidade de traços a serem impressos
 */
void printTree(Node *root, int repeater);

/**
 * @brief Executa left rotation em um nó
 * da árvore
 * 
 * @param root Nó desejado 
 * @return Ponteiro para a nova raiz
 */
Node *rotateL(Node *root);

/**
 * @brief Executa left rotation em um nó
 * da árvore
 * 
 * @param root Nó desejado 
 * @return Ponteiro para a nova raiz
 */
Node *rotateR(Node *root);

/**
 * @brief Cria uma nova árvore que é a 
 * união das outras duas
 * 
 * @param root1 Ponteiro para a raiz da árvore
 * @param root2 Ponteiro para a raiz da árvore
 * @return Ponteiro para a raiz da  nova árvore
 */
Node *merge(Node *root1, Node *root2);

/**
 * @brief Remove um nó da árvore
 * 
 * @param root Ponteiro para a raiz da árvore
 * @param key Valor a ser removido
 * @return Retorna a nova raiz da árvore
 */
Node *removeNode(Node * root, int key);

/**
 * @brief Libera completamente a memoria de uma árvore
 * 
 * @param node Ponteiro para a raiz da árvore
 * @return Ponteiro para NULL
 */
Node *destroyTree(Node * node);

/**
 * @brief Retorna o filho mínimo de uma árvore
 * 
 * @param node Ponteiro para o nó desejado
 * @return Retorna um ponteiro para o ní mínimo
 */
Node *min(Node * node);

/**
 * @brief Deleta um nó de uma árvore
 * 
 * @param root Ponteiro para a raiz da árvore
 * @param key Valor a ser removido
 */
void delete(Node **root, int key);

/**
 * @brief Apaga a árvore completamente
 * 
 * @param root Ponteiro para a raiz da árvore
 */
void destroy(Node **root);


/**
 * @brief Imprime os nós da árvore da 
 * esquerda para a direita e de cima
 * para baixo
 * 
 * @param root Ponteiro para a raiz da árvore
 */
void BFS(Node *root);

/**
 * @brief Encontra a altura absoluta de um nó na árvore
 * 
 * @param root Ponteiro para a raiz da árvore
 * @return Retorna a altura absoluta
 */
int absoluteHeight(Node *root);


/**
 * @brief Imprime um nível da árvore da esquerda para a direita
 * 
 * @param root Ponteiro para a raiz da árvore
 * @param level Nível desejado 
 */
void processLevel(Node *root, int level);

#endif
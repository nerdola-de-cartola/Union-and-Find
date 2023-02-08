#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

extern Node * Tree;

/**
 * @brief Cria um conjunto contendo somente o valor x
 * 
 * @param x Valor para criação e representação do conjunto
 * @return Conjunto que contém o valor x
 */
Node * Make_Set(double x);

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
void Show_SetI(Node * x);

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
void Destroy_setI(Node * x);

/**
 * @brief Faz a união do conjunto que contém x com
 * o conjunto que contém y
 * 
 * @param x Ponteiro que aponta para x
 * @param y Ponteiro que aponta para y
 */
int Union(double x, double y);

/**
 * @brief Faz a união do conjunto i com
 * o conjunto j
 * 
 * @param x Índice do conjunto
 * @param y Índice do conjunto
 */
void UnionI(Node * i, Node * j);

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
int Size_setI(Node * x);



#endif
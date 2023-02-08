#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

/**
 * @brief Encerra o programa
 * 
 */
void SAIR();

/**
 * @brief Rotina para criar novo conjunto
 * 
 */
void CRIAR();

/**
 * @brief Rotina para unir conjuntos
 * 
 */
void UNIR();

/**
 * @brief Rotina para encontrar conjuntos
 * 
 */
void ENCONTRAR();

/**
 * @brief Rotina para exibir conjuntos
 * 
 */
void EXIBIR();


/**
 * @brief Rotina para o usuário verificar o tamanho dos conjuntos
 * 
 */
void TAMANHO();

/**
 * @brief Rotina para o usuário destruir conjuntos
 * 
 */
void DESTRUIR();

/**
 * @brief Rotina para facilitar o tratamento de erros
 * 
 * @param error_message Mensagem a ser impressa na saída padrão
 */
void erro(char *error_message);

/**
 * @brief Rotina que imprime o menu para o usuário
 * 
 */
void printMenu();

/**
 * @brief Inicializa o vetor global de conjuntos
 * 
 */
void Init_Sets();

/**
 * @brief Verifica se o index é valido para acessar um conjunto
 * 
 * @param index 
 * @return true se é valido
 * @return false se é inválido
 */
bool checkIndex(int index);

/**
 * @brief Retorna o index do vetor CONJUNTOS que contém x como representante
 * 
 * @param x 
 * @return int index do vetor CONJUNTOS
 * @return ou -1 caso x não seja encontrado
 */
int findIndex(Node *x);

#endif
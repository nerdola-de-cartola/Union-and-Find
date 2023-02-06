#include "union_find.h"

Node *Tree = NULL;

Node *Make_Set(double x){
    insert(&Tree, x);

    return Find_set(x);
}

void Union(double x, double y){
    Node *tmp1 = Find_set(x);
    Node *tmp2 = Find_set(y);

    while(tmp1->proximo != NULL){
        tmp1 = tmp1->proximo;
    }

    tmp1->proximo = tmp2;

    while(tmp2 != NULL){
        tmp2->representante = tmp1->representante;
    }
}

void UnionI(Node *x, Node *y){
    while(x->proximo != NULL){
        x = x->proximo;
    }

    x->proximo = y;

    while(y != NULL){
        y->representante = x->representante;
    }
}

void Destroy_set(double x){
    Node *tmp1 = Find_set(x);
    Node *tmp2;

    while(tmp1->proximo != NULL){
        tmp2 = tmp1;
        while(tmp2->proximo != NULL){
            tmp2 = tmp2->proximo;
        }
        removeNode(Tree, tmp2->valor);
    }
    removeNode(Tree, tmp1->valor);
}

void Destroy_setI(Node * x){
    Node * tmp = NULL;

    while(x->proximo != NULL){
        tmp = x;
        while(tmp->proximo != NULL){
            tmp = tmp->proximo;
        }
        removeNode(Tree, tmp->valor);
    }
    removeNode(Tree, x->valor);
}


int Size_set(double x){
    Node *tmp = (Node*) malloc(sizeof(Node));
    int size = 0;
    tmp = Find_set(x);
    
    if(tmp != NULL) {
        while(tmp->proximo != NULL) {
            size++;
            tmp = tmp->proximo;
        }
    }
    else return 0;

    free(tmp);
    return size;
}

Node * Find_set(double x){
    Node *tmp = searchTree(Tree, x);
    
    return tmp->representante;
}
/*
TODO
int Size_setI(Node * i){

}
*/

void Show_Set(double x) {
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp = Find_set(x);
    
    if(tmp == NULL) printf("Conjunto nao existe\n");
    else {
        while(tmp->proximo != NULL) {
            printf("%lf ", tmp->valor);
            tmp = tmp->proximo;
        }
        printf("\n");
    }
    free(tmp);
}


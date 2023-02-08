#include "union_find.h"

Node *Tree = NULL;

Node *Make_Set(double x){
    insert(&Tree, x);

    return Find_set(x);
}

void Show_Set(double x) {
    Node *tmp = Find_set(x);
    
    Show_SetI(tmp);
}

void Show_SetI(Node *x) {
    while(x != NULL) {
        printf("%lf ", x->valor);
        x = x->proximo;
    }
    printf("\n");    
}

void Destroy_set(double x){
    Node *tmp1 = Find_set(x);

    Destroy_setI(tmp1);
}

void Destroy_setI(Node * x){
    Node * tmp = NULL;

    if(x == NULL)
        return;

    while(x->proximo != NULL){
        tmp = x;

        while(tmp->proximo->proximo != NULL && tmp->proximo != NULL){
            tmp = tmp->proximo;
        }
        
        delete(&Tree, tmp->proximo->valor);
        tmp->proximo = NULL;

    }

    delete(&Tree, x->valor);
}

int Union(double x, double y){
    Node *tmp1 = Find_set(x);
    Node *tmp2 = Find_set(y);

    if(tmp1 == NULL)
        return -1;
    
    if(tmp2 == NULL)
        return -2;

    UnionI(tmp1, tmp2);

    return 0;
}

void UnionI(Node *x, Node *y){
    if(x != NULL || y != NULL){


        while(x->proximo != NULL){
            x = x->proximo;
        }

        x->proximo = y;

        while(y != NULL){
            y->representante = x->representante;

            y = y->proximo;
        }
    }
}

Node * Find_set(double x){
    Node *tmp = searchTree(Tree, x);
    
    if(tmp == NULL)
        return NULL;

    return tmp->representante;
}

int Size_set(double x){
    Node *tmp = Find_set(x);
    
    return Size_setI(tmp);
}

int Size_setI(Node * x){
    int size = 0;
        
    while(x != NULL) {
        size++;
        x = x->proximo;
    }

    return size;
}

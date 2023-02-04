#include "union_find.h"

Node * createTree() {
    return NULL;
}

Node *createNode(double valor){
    Node *node = (Node *) malloc(sizeof(Node));

    node->valor = valor;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;

    node->representante = &node;
    node->proximo = NULL;   

    return node;
}

int sizeTree(Node *root) {
    int size = 0;

    if(root == NULL) return 0;

    if(root->left != NULL) size += sizeTree(root->left);
    if(root->right != NULL) size += sizeTree(root->right);

    return size + 1;
}

void insert(Node **root, double valor) {
    *root = insertNode((*root), createNode(valor));
}

Node *insertNode(Node *root, Node *newNode){
    int rootBalance;

    if(root == NULL){
        root = newNode;
        return root;
    }
    if(newNode->valor < root->valor){
        root->left = insertNode(root->left, newNode);
    }
    else{
        if(newNode->valor > root->valor){
            root->right = insertNode(root->right, newNode);
        }
        else return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    rootBalance = getBalance(root);

    if(rootBalance > 1 && newNode->valor < root->left->valor){ //RR rotation
        return rotateR(root);
    }
    if(rootBalance < -1 && newNode->valor > root->right->valor){ //LL rotation
        return rotateL(root);
    }
    if(rootBalance > 1 && newNode->valor > root->left->valor){ //LR rotation
        root->left = rotateL(root->left);
        return rotateR(root);
    }
    if(rootBalance < -1 && newNode->valor < root->right->valor){ //RL rotation
        root->right = rotateR(root->right);
        return rotateL(root);
    }

    return root;
}

int height(Node *root){
    if(root != NULL){
        return root->height;
    }

    return 0;
}

Node *searchTree(Node *root, double valor) {
    if(root == NULL) return NULL;

    if(root->valor == valor) return root;

    if(valor < root->valor)
        return searchTree(root->left, valor);

    return searchTree(root->right, valor);
}

int max(int x, int y){
    return (x > y) ? x : y;
}

int getBalance(Node *root){
    if(root != NULL){
        return height(root->left) - height(root->right);
    }

    return 0;
}

void prefix(Node *root){
    if(root != NULL){
        printf("%d ", root->valor);
        prefix(root->left);
        prefix(root->right);
    }
}

void infix(Node *root){
    if(root != NULL){
        infix(root->left);
        printf("%d ", root->valor);
        infix(root->right);
    }
}

void postfix(Node *root){
    if(root != NULL){
        postfix(root->left);
        postfix(root->right);
        printf("%d ", root->valor);
    }
}

void printTree(Node *root, int repeater){
    if(root != NULL){
        if(root->left != NULL) printTree(root->left, repeater + 2);

        for(int i = 0; i < repeater; ++i) {
            printf("-");
        }

        printf(">");
        printf(  "{ valor : %d, Height : %d, Balance Factor : %d }\n", root->valor, root->height, getBalance(root) );

        if(root->right != NULL) printTree(root->right, repeater + 2);
    }
    else printf("ARVORE VAZIA\n");
}

Node *min(Node * node) {
    Node * atual = node;
    while(atual->left != NULL) atual = atual->left;
    return atual;
}


Node *rotateL(Node *root){

    Node *newRoot = root->right;
    Node *temp = newRoot->left;

    newRoot->left = root;
    root->right = temp;

    root->height = 1 + max(height(root->left), height(root->right));
    newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

    return newRoot;
}

Node *rotateR(Node *root){

    Node *newRoot = root->left;
    Node *temp = newRoot->right;

    newRoot->right = root;
    root->left = temp;

    root->height = 1 + max(height(root->left), height(root->right));
    newRoot->height = 1 + max(height(newRoot->left), height(newRoot->right));

    return newRoot;
}

Node *removeNode(Node *root, int key) {
    if(root == NULL) return root;


    if(key < root->valor)
        root->left = removeNode(root->left, key);
    else if(key > root->valor)
        root->right = removeNode(root->right, key);
    else {
        if( (root->left == NULL) || (root->right == NULL)) {
            Node *temp = ((root->left != NULL) ? root->left : root->right);

            if(temp == NULL) {
                temp = root;
                root = NULL;
            }
            else *root = *temp;

            free(temp);
        }
        else {
            Node * temp = min(root->right);

            root->valor = temp->valor;

            root->right = removeNode(root->right, temp->valor);
        }
    }

    if(root == NULL) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if(balance > 1 && getBalance(root->left) >= 0)
        return rotateR(root);

    if(balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateL(root->left);
        return rotateR(root);
    }

    if(balance < -1 && getBalance(root->right) <= 0)
        return rotateL(root);

    if(balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateR(root->right);
        return rotateL(root);
    }

    return root;
}

Node *destroyTree(Node * node) {
    if(node->left != NULL)  {
        node->left = destroyTree(node->left);
    }

    if(node->right != NULL)  {
        node->right = destroyTree(node->right);
    }

    free(node);
    return NULL;
}

void destroy(Node **root) {
    *root = destroyTree(*root);
}

void delete(Node **root, int key) {
    *root = removeNode(*root, key);
}

void treeToArr(Node *root, int *arr, int *pos) {
    if(root == NULL) return;

    arr[*pos] = root->valor;
    (*pos)++;

    treeToArr(root->left, arr, pos);
    treeToArr(root->right, arr, pos);
}

Node *merge(Node *root1, Node *root2) {
    int size_t1 = sizeTree(root1);
    int size_t2 = sizeTree(root2);

    int *arr1 = (int *) malloc(size_t1 * sizeof(int));
    int *arr2 = (int *) malloc(size_t2 * sizeof(int));
    int pos = 0;

    if(arr1 == NULL || arr2 == NULL) {
        printf("Falha na alocação de memoria\n");
        exit(1);
    }

    treeToArr(root1, arr1, &pos);
    pos = 0;
    treeToArr(root2, arr2, &pos);

    int i;
    Node *root3 = createTree();

    for(i = 0; i < size_t1; i++) {
        insert(&root3, arr1[i]);
    }

    for(i = 0; i < size_t2; i++) {
        insert(&root3, arr2[i]);
    }

    free(arr1);
    free(arr2);

    return root3;
}


void processLevel(Node *root, int level) {
    if(root != NULL) {
        if(level == 0) {
            printf("%d ", root->valor);
        } else {
            if(level > 0) {
                processLevel(root->left, level - 1);
                processLevel(root->right, level - 1);
            }
        }
    }
}

int absoluteHeight(Node *root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;

    int hl = absoluteHeight(root->left);
    int hr = absoluteHeight(root->right);

    return  hl > hr ? hl + 1 : hr + 1;
}

void BFS(Node *root) {
    int level, height;

    height = absoluteHeight(root);

    for(level = 0; level < height; level++) {
        printf("Nível %d: ", level);
        processLevel(root, level);
        printf("\n");
    }
}

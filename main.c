#include "lib/union_find.h"
#include "lib/avl.h"
#include "main.h"

Node *CONJUNTOS[MAX_SIZE];
int OPTION;

int main(void) {

   Init_Sets();

   while(true) {

      printMenu();
      scanf("%d", &OPTION);

      switch (OPTION) {
         case 0:
            SAIR();
            break;

         case 1:
            CRIAR();
            break;

         case 2:
            UNIR();
            break;

         case 3:
            ENCONTRAR();
            break;

         case 4:
            EXIBIR();
            break;
         
         case 5:
            TAMANHO();
            break;

         case 6:
            DESTRUIR();
            break;
         
         default:
            erro("Opção inválida");
            break;
      }
   }

   return 0;
}

void SAIR() {

   destroy(&Tree);

   exit(0);
}

void CRIAR() {

   int index;
   double valor;

   while(true) {
      printf("Digite o código do conjunto desejado, entre 0 e 100\n");
      scanf("%d", &index);

      if(!checkIndex(index)) {
         printf("Código inválido\n");
         continue;
      }

      if(CONJUNTOS[index] != NULL) {
         printf("Esse conjunto já está sendo utilizado, por favor escolha outro código\n");
         continue;
      }

      break;
   }

   printf("Digite o valor que deseja inserir nesse conjunto\n");
   scanf("%lf", &valor);

   CONJUNTOS[index] = Make_Set(valor);

}

void UNIR() {

   int type = 0, error_code;
   int i, j;
   double x, y;
   int index_to_erase;

   printf(
      "Como você deseja unir conjuntos?\n"\
      "0 - Voltar\n"\
      "1 - Unir por índice\n"\
      "2 - Unir por valor\n"
   );

   scanf("%d", &type);

   switch (type) {
      case 0:
         return;

      case 1:
         while (true) {

            printf("Insira o Índice do primeiro conjunto: ");
            scanf("%d", &i);
            printf("Insira o Índice do segundo conjunto: ");
            scanf("%d", &j);

            if(checkIndex(i) && checkIndex(j)) {
               break;
            }

            printf("Índice inválido\n");
            
         }
         
         UnionI(CONJUNTOS[i], CONJUNTOS[j]);

         CONJUNTOS[j] = NULL;

         printf("A união dos conjuntos agora está no índice: %d\n", i);

         break;

      case 2:
         
         while (true) {

            printf("Insira o primeiro valor: ");
            scanf("%lf", &x);
            printf("Insira o segundo valor: ");
            scanf("%lf", &y);

            index_to_erase = findIndex(Find_set(y));

            error_code = Union(x, y);
            
            if(error_code == -1) {
               printf("O primeiro valor não existe em nenhum conjunto, tente novamente\n");
            }

            if(error_code == -2) {
               printf("O segundo valor não existe em nenhum conjunto, tente novamente\n");
            }
            
            break;
         }

         CONJUNTOS[index_to_erase] = NULL;

         i = findIndex(Find_set(x));

         printf("A união dos conjuntos agora está no índice: %d\n", i);

         break;
      
      default:
         erro("Tipo de união inválida");
         break;
   }
}

void ENCONTRAR() {
   double x;
   int i;

   printf("Insira o valor que deseja encontrar: ");
   scanf("%lf", &x);
   
   i = findIndex(Find_set(x));

   if(i == -1){
      printf("Conjunto não existe!\n");
      return;
   }
   
   printf("O valor %lf esta no conjunto de índice: %d\n", x, i);
}

void EXIBIR() {
   
   int type = 0;
   int index;
   double value;

   printf(
      "Como você deseja exibir um conjunto?\n"\
      "0 - Voltar\n"\
      "1 - Exibir por índice\n"\
      "2 - Exibir por valor\n"
   );

   scanf("%d", &type);

   switch (type) {
      case 0:
         return;

      case 1:
         printf("Digite o índice do conjunto que deseja exibir: \n");
         scanf("%d", &index);

         Show_SetI(CONJUNTOS[index]);
         break;

      case 2:
         printf("Digite o valor no conjunto que deseja exibir: \n");
         scanf("%lf", &value);

         Show_Set(value);
         break;
      
      default:
         erro("Tipo de exibição inválida");
         break;
   }
}

void TAMANHO() {

   int type = 0;
   int index;
   double value;

   printf(
      "Como você deseja verificar o tamanho de um conjunto?\n"\
      "0 - Voltar\n"\
      "1 - Verificar tamanho por índice\n"\
      "2 - Verificar tamanho por valor\n"
   );

   scanf("%d", &type);

   switch (type) {
      case 0:
         return;

      case 1:
         printf("Digite o índice do conjunto que deseja obter o tamanho: \n");
         scanf("%d", &index);

         printf("Size: %d\n", Size_setI(CONJUNTOS[index]));
         break;

      case 2:
         printf("Digite o valor no conjunto que deseja obter o tamanho: \n");
         scanf("%lf", &value);

         printf("Size: %d\n", Size_set(value));
         break;
      
      default:
         erro("Tipo de união inválida");
         break;
   }

}

void DESTRUIR() {

   int type = 0;
   int index;
   double value;
   int index_to_erase;

   printf(
      "Como você deseja destruir um conjunto\n"\
      "0 - Voltar\n"\
      "1 - Destruir por índice\n"\
      "2 - Destruir por valor\n"
   );

   scanf("%d", &type);

   switch (type) {
      case 0:
         return;

      case 1:
         printf("Digite o índice do conjunto que deseja destruir: \n");
         scanf("%d", &index);

         Destroy_setI(CONJUNTOS[index]);
         CONJUNTOS[index] = NULL;
         break;

      case 2:
         printf("Digite o valor no conjunto que deseja destruir: \n");
         scanf("%lf", &value);

         index_to_erase = findIndex(Find_set(value));
         Destroy_set(value);

         CONJUNTOS[index_to_erase] = NULL;
         break;
      
      default:
         erro("Tipo de destruição inválida");
         break;
   }

}

void erro(char *error_message) {
   printf("Erro: %s\n", error_message);
}

void printMenu() {

   printf(
      "---------------MENU---------------\n"\
      "--------ESCOLHA SUA OPÇÃO----------\n"\
      "0 - SAIR\n"\
      "1 - CRIAR NOVO CONJUNTO\n"\
      "2 - UNIR CONJUNTOS\n"\
      "3 - ENCONTRAR CONJUNTO\n"\
      "4 - EXIBIR CONJUNTO\n"\
      "5 - TAMANHO DO CONJUNTO\n"\
      "6 - DESTRUIR CONJUNTO\n"
   );

}

void Init_Sets() {
   int i;

   for(i = 0; i < MAX_SIZE; i++)
      CONJUNTOS[i] = NULL;
   
}

bool checkIndex(int index) {
   if(index < 0 || index >= MAX_SIZE) return false;
   return true;
}

int findIndex(Node *x) {

   int i;

   if(x == NULL)
      return -1;

   for(i = 0; i < MAX_SIZE; i++) {

      if(CONJUNTOS[i] == x->representante)
         return i;

   }

   return -1;

}
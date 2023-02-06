#include "lib/union_find.h"
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

   /*TODO
   Liberar a memoria do programa
   */

   exit(0);
}

void CRIAR() {

}

void UNIR() {

   int type = 0;

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
         /* code */
         break;

      case 2:
         /* code */
         break;
      
      default:
         erro("Tipo de união inválida");
         break;
   }
}

void ENCONTRAR() {
   
}

void EXIBIR() {

   int type = 0;

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
         /* code */
         break;

      case 2:
         /* code */
         break;
      
      default:
         erro("Tipo de exibição inválida");
         break;
   }
}

void TAMANHO() {

   int type = 0;

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
         /* code */
         break;

      case 2:
         /* code */
         break;
      
      default:
         erro("Tipo de união inválida");
         break;
   }

}

void DESTRUIR() {

   int type = 0;

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
         /* code */
         break;

      case 2:
         /* code */
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
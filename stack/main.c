#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

//========================================================

struct stack{
    int data;
    int count;
    struct stack *next;
};
typedef struct stack stack;

int maxstack = 10;

void pushstack(stack **top);
void popstack(stack **top);
void stacktop(stack *top);
void emptystack(stack *top);
void fullstack(stack *top);
void stackcount(stack *top);
void destroystack(stack **top);

//========================================================

int main(void)
{
  stack *top;
  int pilih;

  top = NULL;
    
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. push \n");
     printf("2. pop \n");
     printf("3. top (cek top stack)\n");
     printf("4. empty stack (cek stack kosong/tidak)\n");
     printf("5. full stack (cek satck penuh/tidak)\n");
     printf("6. jumlah stack\n");
     printf("7. destroy stack (hapus seluruh data stack)\n");
     printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
     fflush(stdin);
     scanf(" %d", &pilih);
      if (pilih == 1)
          pushstack(&top);
      else if (pilih == 2)
          popstack(&top);
      else if (pilih == 3)
          stacktop(top);
      else if (pilih == 4)
          emptystack(top);
      else if (pilih == 5)
          fullstack(top);
      else if (pilih == 6)
          stackcount(top);
      else if (pilih == 7)
          destroystack(&top);

  } while (pilih != 0);

  return 0;
}
//========================================================
void pushstack(stack **top){
  int bil;
  stack *pNew;

  system("cls");
  stackcount(*top);
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  if(*top != NULL && (*top)->count >= maxstack){
    printf("Stack sudah penuh");
    getch();
    return;
  }

  pNew = (stack *)malloc(sizeof(stack));

  if (pNew != NULL){
      pNew->data = bil;
      pNew -> next = *top;
      if (*top == NULL)
          pNew->count = 1;
      else
          pNew->count = (*top)->count + 1;
          *top = pNew;
          
          printf("Bilangan %d ditambahkan\n", bil);
      
  }
  else{
      printf("Alokasi memori gagal");
      getch();
      return;
  }
}

//========================================================
void popstack(stack **top) {
    stack *temp;

     if (*top == NULL) {
        printf("List kosong, tidak ada data yang dihapus.\n");
        getch();
        return;
    }
     else{
         temp = *top;
         *top = (*top)->next;
         if (*top != NULL) {
             (*top)->count = temp->count - 1;
         }
         printf("Bilangan %d berhasil dihapus dari stack.\n", temp->data);
         free(temp);
         getch();
     }
    
}
//========================================================
void stacktop(stack *top) {

    system("cls");
    if (top == NULL) {
        printf("Stack kosong.\n");
        getch();
    } else {
        printf("Data paling atas adalah %d\n", top->data);
        getch();
    }
}
//========================================================
void emptystack(stack *top) {
    if (top == NULL) {
        printf("Stack kosong.\n");
        getch();
    } else {
        printf("Stack terisi.\n");
        getch();
    }
}

//========================================================
void fullstack(stack *top) {
    if (top->count >= maxstack) {
        printf("Stack sudah penuh.\n");
    } else {
        printf("Stack masih tersedia.\n");
    }
    getch();
}
//========================================================
void stackcount(stack *top) {
    if (top == NULL) {
        printf("Stack terisi: 0\n");
        getch();
    }
    else{
        printf("Stack terisi: %d\n", top->count);
        getch();
    }
}
//========================================================
void destroystack(stack **top){
    stack *temp;
    if(*top == NULL){
        printf("Stack kosong, tidak ada yang dihapus.\n");
        getch();
        return;
    }
    while (*top != NULL) {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
    printf("Stack telah dikosongkan");
    getch();
}


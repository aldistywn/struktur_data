#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node{
    int data;
    struct node *right;
    struct node *left;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void hitungData(node *head);
void penjumlahanData (node *head);

//========================================================

int main(void)
{
  node *head;
  int pilih;

  head = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data di awal\n");
     printf("2. tambah data di tengah list\n");
      printf("3. tambahkan data di akhir list\n");
      printf("4. hapus data di awal list\n");
      printf("5. hapus data di tengah list\n");
      printf("6. hapus data di akhir list\n");
      printf("7. cari data dalam list\n");
      printf("8. informasi jumlah data dalam list\n");
      printf("9. Penjumlahan seluruh nilai data dalam list\n");
     printf("10. cetak isi list\n");
     printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
     fflush(stdin);
     scanf("%d", &pilih);
     if (pilih == 1)
             tambahAwal(&head);
     else if (pilih == 2)
            tambahData(&head);
     else if (pilih == 3)
            tambahAkhir(&head);
     else if (pilih == 4)
            hapusAwal(&head);
     else if (pilih == 5)
            hapusTengah(&head);
     else if (pilih == 6)
            hapusAkhir(&head);
     else if (pilih == 7)
            cariData(head);
     else if (pilih == 8)
            hitungData(head);
     else if (pilih == 9)
            penjumlahanData(head);
     else if (pilih == 10){
             tranverse(head);
         getch();
     }
  } while (pilih != 0);

  return 0;
}

//========================================================

/*node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/

//========================================================

void tambahAwal(node **head){
  int bil;
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
          pNew->data = bil;
          pNew->right = *head;
          if (*head != NULL) {
              (*head)->left = pNew;
          }
          pNew->left = NULL;
          *head = pNew;
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void tambahData(node **head){
    int pos, bil;
    node *pNew, *pCur;
    
    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    
    pCur = *head;
    
    while (pCur != NULL && pCur -> data != pos) {
        pCur = pCur -> right;
    }
    
    
    pNew = (node *)malloc(sizeof(node));
    
    if (pCur == NULL){
        printf("\nnode tidak ditemukan");
        getch();
    }
    else if (pNew == NULL){
        printf("\nalokasi memeori gagal");
        getch();
    }
    else{
        if (pCur -> right == NULL){
            //jika yg ditambah di note terakhir, maka tambah akhir
            pNew -> data = bil;
            pNew -> left = pCur;
            pNew -> right = pCur -> right;
            pCur -> right = pNew;
        }else{
            //tambah tengah
            pNew -> data = bil;
            pNew -> left = pCur;
            pNew -> right = pCur -> right;
            pCur -> right -> left = pNew;
            pCur -> right  = pNew;
        }
    }
}
//========================================================

void tranverse(node *head){
   //traverse a linked list
    node *pWalker;

   system("cls");
    pWalker = head;
    printf("NULL <-");
    while (pWalker != NULL){
        printf(" %d\t", pWalker -> data);
        if (pWalker -> right != NULL) {
            printf("<->");
        }
        pWalker = pWalker -> right;
    }
   printf("-> NULL");
}

//========================================================

void tambahAkhir(node **head){
    int bil;
    node *pNew, *pCur;
    
    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    scanf("%d", &bil);
    
    
    pCur = *head;
    while (pCur -> right != NULL){
        pCur = pCur -> right;
    }
    
    pNew = (struct node *) malloc(sizeof(node));
    
    if (pNew == NULL){
        printf("\nAlokasi memeori gagal");
        getch();
    }
    else{
        pNew -> data = bil;
        pNew -> left = pCur;
        pNew -> right = pCur -> right;
        pCur -> right  = pNew;
        
    }
}

//========================================================
void hapusAwal(node **head) {
    node *pCur;
    
    system("cls");
    if (*head != NULL) {
        pCur = *head;
        *head = pCur -> right;
        pCur ->right -> left = NULL;
        free(pCur);


        printf("Node pertama berhasil dihapus.\n");
        getch();
    }
    else{
        printf("Tidak ada data yang akan dihapus.\n");
        getch();
        return;
    }
}

//========================================================
void hapusTengah(node **head) {
    int bil;
    node *pCur;

    system("cls");
    tranverse(*head);
    fflush(stdin);
    printf("\nMasukkan nilai node yang ingin dihapus: ");
    scanf("%d", &bil);


    pCur = *head;
    while (pCur && pCur->data != bil) {
        pCur = pCur->right;
    }

    if (pCur == NULL) {
        printf("Node dengan nilai %d tidak ditemukan.\n", bil);
        getch();
        return;
    }
    else {
        if (pCur -> right == NULL) {
            pCur -> left -> right = NULL;
        }else if (pCur -> left == NULL){
            //deletion is on the first node of the list
            *head = pCur -> right;
            pCur -> right -> left = NULL;
        } else{
            //deleting a node other than the first node of the list
            if (pCur->left) {
                    pCur->left->right = pCur->right;
                }
        }
        free(pCur);
        printf("Node dengan nilai %d berhasil dihapus.\n", bil);
        getch();
    }
    
}
        

//========================================================
void hapusAkhir(node **head) {
    node *pCur;

    system("cls");
    if (*head == NULL) {
        printf("Tidak ada data yang akan dihapus.\n");
        getch();
        return;
    }
    pCur = *head;
    while (pCur -> right != NULL){
        pCur = pCur -> right;
    }

    if (pCur == *head) {
        printf("Ini adalah node pertama.\n");
        getch();
        return;
    } else {
        pCur -> left -> right = NULL;
        printf("Node terakhir berhasil dihapus.\n");
        getch();
    }
    free(pCur);
    printf("Node terakhir berhasil dihapus.\n");
    getch();
}

//========================================================
void cariData(node *head) {
    int target;
        node *pWalker;

        system("cls");
        printf("Masukkan data yang ingin dicari: ");
        scanf("%d", &target);

        pWalker = head;
        // Cari node dengan nilai tertentu
        while (pWalker != NULL) {
            if (pWalker->data == target) {
                printf("Data ditemukan: %d\n", pWalker->data);
                getch();
                return;
            }
            pWalker = pWalker->right;
        }

        // Jika data tidak ditemukan
        printf("Data tidak ditemukan!\n");
}

//========================================================
void hitungData(node *head) {
    int count = 0;
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur -> right;
    }
        system("cls");
        printf("Jumlah total data dalam linked list adalah: %d\n", count);
        getch();
}

//========================================================
void penjumlahanData(node *head) {
    int total = 0;
    node *pCur = head;

    while (pCur != NULL) {
        total += pCur -> data;
        pCur = pCur -> right;
    }
    system("cls");
    printf("\nJumlah total nilai data dalam list adalah: %d\n", total);
    getch();
}




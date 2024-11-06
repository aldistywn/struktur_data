#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

//========================================================

struct node{
    int data;
    struct node *next;
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

  if (pNew != NULL){
        pNew -> data = bil;
      pNew -> next = NULL;
      //add before first logical node or to an empty list
      pNew -> next = *head;
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
    pCur = pCur -> next;
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
     pNew -> data = bil;
     pNew -> next = NULL;
     pNew -> next = pCur -> next;
     pCur -> next = pNew;
  }
}

//========================================================

void tranverse(node *head){
   //traverse a linked list
    node *pWalker;

   system("cls");
    pWalker = head;
    while (pWalker != NULL){
       printf("%d\t", pWalker -> data);
       pWalker = pWalker -> next;
      printf(" -> ");
    }
   printf("NULL");
}

//========================================================

void tambahAkhir(node **head){
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    pCur = *head;
    while (pCur -> next != NULL){
        pCur = pCur -> next;
    }

    if (pNew == NULL){
        printf("\nAlokasi memeori gagal");
        getch();
    }
    else{
        pNew -> data = bil;
        pNew -> next = NULL;
        pCur -> next = pNew;
    }
}

//========================================================
void hapusAwal(node **head) {
    node *pCur;

    system("cls");
    if (*head != NULL) {
        pCur = *head;
        *head = pCur -> next;
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
    node *pCur, *pPre;

    system("cls");
    tranverse(*head);
    fflush(stdin);
    printf("\nMasukkan nilai node yang ingin dihapus: ");
    scanf("%d", &bil);


    pCur = *head;
    pPre = NULL;
    while (pCur != NULL && pCur -> data != bil) {
        pPre = pCur;
        pCur = pCur -> next;
    }

    if (pCur == NULL) {
        printf("Node dengan nilai %d tidak ditemukan.\n", bil);
        getch();
        return;
    }
    else if (pPre == NULL) {
        printf("Ini adalah node pertama.\n");
        getch();
        return;
    }
    else {
        pPre -> next = pCur -> next;
        free(pCur);
        printf("Node dengan nilai %d berhasil dihapus.\n", bil);
        getch();
    }

}

//========================================================
void hapusAkhir(node **head) {
    node *pCur, *pPre;

    system("cls");
    if (*head == NULL) {
        printf("Tidak ada data yang akan dihapus.\n");
        getch();
        return;
    }
    pCur = *head;
    pPre = NULL;
    while (pCur -> next != NULL){
        pPre = pCur;
        pCur = pCur -> next;
    }

    if (pPre == NULL) {
        printf("Ini adalah node pertama.\n");
        getch();
        return;
    } else {
        free(pCur);
        pPre -> next = NULL;
        printf("Node terakhir berhasil dihapus.\n");
        getch();
    }
}

//========================================================
void cariData(node *head) {
    int bil;
    node *pCur;
    int urutan = 1;

    system("cls");
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &bil);

    if (head == NULL) {
        printf("Tidak ada data yang akan dihapus.\n");
        getch();
        return;
    }

    pCur = head;
    while (pCur != NULL && pCur -> data != bil) {
        urutan++;
        pCur = pCur -> next;
    }
    if (pCur == NULL) {
        printf("Node dengan nilai %d tidak ditemukan.\n", bil);
        getch();

    }
    else{
        printf("Node dengan nilai %d berada pada node %d.\n", bil, urutan);
        getch();
        return;
    }
}

//========================================================
void hitungData(node *head) {
    int count = 0;
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur -> next;
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
        pCur = pCur -> next;
    }
    system("cls");
    printf("\nJumlah total nilai data dalam list adalah: %d\n", total);
    getch();
}




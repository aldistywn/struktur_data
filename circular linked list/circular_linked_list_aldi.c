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
void tambahAwal(node **pList);
void tambahData(node **pList);
void tranverse(node *pList);
void hapusAwal(node **pList);
void hapusTengah(node **pList);
void cariData(node *pList);
void hitungData(node *pList);
void penjumlahanData (node *pList);

//========================================================

int main(void)
{
  node *pList;
  int pilih;

  pList = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data di awal\n");
     printf("2. tambah data di tengah pList\n");
      printf("3. hapus data di awal pList\n");
      printf("4. hapus data di tengah pList\n");
      printf("5. cari data dalam pList\n");
      printf("6. informasi jumlah data dalam pList\n");
      printf("7. Penjumlahan seluruh nilai data dalam pList\n");
     printf("8. cetak isi pList\n");
     printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
     fflush(stdin);
     scanf("%d", &pilih);
     if (pilih == 1)
             tambahAwal(&pList);
     else if (pilih == 2)
            tambahData(&pList);
     else if (pilih == 3)
            hapusAwal(&pList);
     else if (pilih == 4)
            hapusTengah(&pList);
     else if (pilih == 5)
            cariData(pList);
     else if (pilih == 6)
            hitungData(pList);
     else if (pilih == 7)
            penjumlahanData(pList);
     else if (pilih == 8){
             tranverse(pList);
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

//===========================================================
void tambahAwal(node **pList) {
    int bil;
    node *pNew, *pPre;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        //menambhakan node ke list kosong
        if (*pList == NULL) {
            pNew->next = pNew;
            *pList = pNew;
        }
        //menyisipkan node sebelum pList
        else{
            pPre = *pList;
            while (pPre->next != *pList) {
                pPre = pPre->next;
            }
            pNew->next = *pList;
            *pList = pNew;
            pPre->next = *pList;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//===========================================================
void tambahData(node **pList) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*pList);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *pList;
    do {
        if (pCur->data == pos) break;
        pCur = pCur->next;
    } while (pCur != *pList);

    pNew = (node *)malloc(sizeof(node));
    
    if (pCur->data != pos) {
        printf("\nNode tidak ditemukan");
        getch();
    } else if (pNew == NULL) {
            printf("\nAlokasi memori gagal");
            getch();
        } else {
            pNew->data = bil;
            pNew->next = pCur->next;
            pCur->next = pNew;
        }
    
}

//========================================================

void tranverse(node *pList) {
    node *pWalker;

    system("cls");
    if (pList == NULL) {
        printf("pList kosong.\n");
        return;
    }

    pWalker = pList;
    printf("%d -> ", pWalker->data);

    pWalker = pWalker->next;
    while (pWalker != pList) {
        printf("%d\t", pWalker->data);
        pWalker = pWalker -> next;
        printf("-> ");
    }


    printf("%d\n", pList->data);
}


//========================================================
void hapusAwal(node **pList) {
    node *pCur, *pPre;
    
    pPre = *pList;
    
    if ((*pList)->next == *pList) {
        free(*pList);
        *pList = NULL;
    } else {
        while (pPre->next != *pList) {
            pPre = pPre->next;
        }
        pCur = *pList;
        *pList = (*pList)->next;
        pPre->next = *pList;
        free(pCur);
    }
    printf("Node di awal berhasil dihapus.\n");
    getch();
}
//========================================================
void hapusTengah(node **pList) {
    int bil;
    node *pCur, *pPre;
    
    
    system("cls");
    tranverse(*pList);
    printf("\nMasukkan data yang ingin dihapus: ");
    fflush(stdin);
    scanf("%d", &bil);

    
    pCur = *pList;
    pPre = NULL;
    do {
        if (pCur->data == bil) break;
        pPre = pCur;
        pCur = pCur->next;
    } while (pCur != *pList);
    

    if (pCur->data != bil) {
        printf("Data tidak ditemukan.");
        getch();
        return;
    }
    if (pCur == *pList && pCur->next == *pList) {
        free(*pList);
        *pList = NULL;
    } else {
        pPre->next = pCur->next;
        free(pCur);
        printf("Node di tengah berhasil dihapus.\n");
        getch();
        }
        
}
//========================================================
void cariData(node *pList) {
    int bil;
    node *pCur = pList;

    system("cls");
    printf("\nMasukkan data yang dicari: ");
    fflush(stdin);
    scanf("%d", &bil);
    
    if (pList == NULL) {
        printf("Data kosong.");
        getch();
        return;
    }

    do {
        if (pCur->data == bil) {
            printf("Data %d ditemukan.\n", bil);
            getch();
            return;
        }
        pCur = pCur->next;
    } while (pCur != pList);

    printf("Data tidak ditemukan.\n");
    getch();
}

//========================================================
void hitungData(node *pList) {
    int count = 0;
    node *pCur = pList;

    do {
        count++;
        pCur = pCur->next;
    } while (pCur != pList);

    printf("Jumlah data dalam list: %d\n", count);
    getch();
}

//========================================================
void penjumlahanData(node *pList) {
    int sum = 0;
    node *pCur = pList;

    do {
        sum += pCur->data;
        pCur = pCur->next;
    } while (pCur != pList);

    printf("Perjumlah total dari semua data: %d\n", sum);
    getch();
}




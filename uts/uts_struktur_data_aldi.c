#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *data;
    char gender;
    struct node *next;
};
typedef struct node node;

int count = 0;

void tambahAwal(node **pList);
void tambahData(node **pList);
void tranverse(node *pList);
void tranverseByGender(node *pList, char gender);
void hapusTengah(node **pList);

int main(void) {
    node *pList;
    int pilih;

    pList = NULL;
    do {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Tambah nama di awal\n");
        printf("2. Tambah nama di tengah lingkaran\n");
        printf("3. Hapus nama di tengah lingkaran\n");
        printf("4. Cetak semua isi lingkaran\n");
        printf("5. Cetak nama berdasarkan jenis kelamin (L/P)\n");
        printf("MASUKKAN PILIHAN (tekan 0 untuk keluar): ");
        fflush(stdin);
        scanf("%d", &pilih);
        if (pilih == 1)
            tambahAwal(&pList);
        else if (pilih == 2)
            tambahData(&pList);
        else if (pilih == 3)
            hapusTengah(&pList);
        else if (pilih == 4) {
            tranverse(pList);
            getch();
        } else if (pilih == 5) {
            char gender;
            printf("Masukkan jenis kelamin (L/P): ");
            fflush(stdin);
            scanf(" %c", &gender);
            tranverseByGender(pList, gender);
            getch();
        }
    } while (pilih != 0);

    return 0;
}

//========================================================
void tambahAwal(node **pList) {
    if (count >= 20) {
        printf("Jumlah maksimum node (20) telah tercapai.\n");
        getch();
        return;
    }

    char temp[100];
    char gender;
    node *pNew, *pPre;

    system("cls");
    printf("Masukkan nama: ");
    fflush(stdin);
    scanf("%s", temp);
    printf("Masukkan jenis kelamin (L/P): ");
    fflush(stdin);
    scanf(" %c", &gender);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = (char *)malloc(strlen(temp) + 1);
        strcpy(pNew->data, temp);
        pNew->gender = gender;

        if (*pList == NULL) {
            pNew->next = pNew;
            *pList = pNew;
        } else {
            pPre = *pList;
            while (pPre->next != *pList) {
                pPre = pPre->next;
            }
            pNew->next = *pList;
            *pList = pNew;
            pPre->next = *pList;
        }

        // Cek apakah nama Cindy bersebelahan dengan gender L (Laki-laki)
        if (strcmp(pNew->data, "Cindy") == 0) {
            // Cek node sebelum dan sesudah Cindy
            node *pPrev = *pList;
            while (pPrev->next != pNew) {
                pPrev = pPrev->next;
            }
            node *pNext = pNew->next;

            if ((pPrev->gender == 'L') || (pNext->gender == 'L')) {
                printf("Nama 'Cindy' tidak boleh bersebelahan dengan laki-laki!\n");
                free(pNew->data);
                free(pNew);
                *pList = pPrev->next;
                getch();
                return;
            }
        }

        count++;
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================
void tambahData(node **pList) {
    if (count >= 20) {
        printf("Jumlah maksimum node (20) telah tercapai.\n");
        getch();
        return;
    }

    char pos[100], bil[100], gender;
    node *pNew, *pCur;

    system("cls");
    tranverse(*pList);
    printf("\nPosisi penyisipan nama baru setelah nama: ");
    fflush(stdin);
    scanf("%s", pos);
    printf("\nNama: ");
    fflush(stdin);
    scanf("%s", bil);
    printf("Masukkan jenis kelamin (L/P): ");
    fflush(stdin);
    scanf(" %c", &gender);

    pCur = *pList;
    do {
        if (strcmp(pCur->data, pos) == 0) break;
        pCur = pCur->next;
    } while (pCur != *pList);

    pNew = (node *)malloc(sizeof(node));

    if (strcmp(pCur->data, pos) != 0) {
        printf("\nNama tidak ditemukan");
        getch();
    } else if (pNew == NULL) {
        printf("\nAlokasi memori gagal");
        getch();
    } else {
        pNew->data = (char *)malloc(strlen(bil) + 1);
        strcpy(pNew->data, bil);
        pNew->gender = gender;
        pNew->next = pCur->next;
        pCur->next = pNew;

        // Cek apakah nama Cindy bersebelahan dengan gender L (Laki-laki)
        if (strcmp(pNew->data, "Cindy") == 0) {
            // Cek node sebelum dan sesudah Cindy
            node *pPrev = *pList;
            while (pPrev->next != pNew) {
                pPrev = pPrev->next;
            }
            node *pNext = pNew->next;

            if ((pPrev->gender == 'L') || (pNext->gender == 'L')) {
                printf("Nama 'Cindy' tidak boleh bersebelahan dengan laki-laki!\n");
                free(pNew->data);
                free(pNew);
                pCur->next = pNew->next;  // Kembalikan kondisi awal
                getch();
                return;
            }
        }

        count++;
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
    printf("%s (%c) -> ", pWalker->data, pWalker->gender);

    pWalker = pWalker->next;
    while (pWalker != pList) {
        printf("%s (%c)\t", pWalker->data, pWalker->gender);
        pWalker = pWalker->next;
        printf("-> ");
    }

    printf("%s (%c)\n", pList->data, pList->gender);
}

//========================================================
void tranverseByGender(node *pList, char gender) {
    node *pWalker;
    int found = 0;

    system("cls");
    if (pList == NULL) {
        printf("pList kosong.\n");
        return;
    }

    pWalker = pList;
    if (pWalker->gender == gender) {
        printf("%s -> ", pWalker->data);
        found = 1;
    }

    pWalker = pWalker->next;
    while (pWalker != pList) {
        if (pWalker->gender == gender) {
            printf("%s\t", pWalker->data);
            printf("-> ");
            found = 1;
        }
        pWalker = pWalker->next;
    }
}

//========================================================
void hapusTengah(node **pList) {
    char bil[100];
    node *pCur, *pPre;

    system("cls");
    tranverse(*pList);
    printf("\nMasukkan nama yang ingin dihapus: ");
    fflush(stdin);
    scanf("%s", bil);

    pCur = *pList;
    pPre = NULL;
    do {
        if (strcmp(pCur->data, bil) == 0) break;
        pPre = pCur;
        pCur = pCur->next;
    } while (pCur != *pList);

    if (strcmp(pCur->data, bil) != 0) {
        printf("Data tidak ditemukan.");
        getch();
        return;
    }
    if (pCur == *pList && pCur->next == *pList) {
        free(pCur->data);
        free(*pList);
        *pList = NULL;
    } else {
        pPre->next = pCur->next;
        free(pCur->data);
        free(pCur);
    }
    count--;
    printf("Nama di tengah berhasil dihapus.\n");
    getch();
}

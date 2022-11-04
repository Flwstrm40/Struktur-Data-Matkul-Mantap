/* Program   : main.c */
/* Deskripsi : file DRIVER modul listlinear*/
/* NIM/Nama  : 24060121130073/Muhammad Naufal Arkan*/
/* Tanggal   : 28-10-2022*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
/*Kamus*/
    List L;
    List L1;
    List L2;
    List L3;
    List L4;
    int X;
    address P,E,R,G;
    address Q,H,T;
/*Algoritma*/
    P = Alokasi(5);
    Q = Alokasi(9);
    R = Alokasi(1);
    E = Alokasi(10);
    G = Alokasi(12);
    H = Alokasi(15);
    T = Alokasi(72);
    printf("Alokasi P = %d\n",info(P));
    printf("Alokasi Q = %d\n",info(Q));
    printf("Alokasi R = %d\n",info(R));
    printf("Alokasi E = %d\n",info(E));
    printf("Alokasi G = %d\n",info(G));
    printf("Alokasi H = %d\n",info(H));
    printf("Alokasi T = %d\n",info(T));
    printf("===================================CreateList===================================\n");
    CreateList(&L);
    CreateList(&L2);
    printf("\n===================================InsVFirst===================================\n");
    printf("Apakah list kosong: %d\n",ListEmpty(L));
    InsertFirst(&L, P);
    PrintInfo(L);
    InsertAfter(&L, Q, P);
    PrintInfo(L);
    InsertAfter(&L, R, Q);
    PrintInfo(L);
    InsertAfter(&L, E, R);
    PrintInfo(L);
    InsertLast(&L, G);
    PrintInfo(L);
    DelFirst(&L, &P);
    printf("Nilai yang dihapus: %d\n",info(P));
    PrintInfo(L);
    DelAfter(&L, &R, Q);
    printf("Nilai yang dihapus: %d\n",info(R));
    PrintInfo(L);
    DelLast(&L, &G);
    printf("Nilai yang dihapus: %d\n",info(G));
    PrintInfo(L);
    InsVFirst(&L, 87);
    PrintInfo(L);
    InsVAfter(&L, 21, Q);
    PrintInfo(L);
    InsVLast(&L, 12);
    PrintInfo(L);

    DelVFirst(&L, &X);
    printf("Nilai yang dihapus: %d\n", X);
    PrintInfo(L);
    DelVLast(&L, &X);
    printf("Nilai yang dihapus: %d\n", X);
    PrintInfo(L);
    InsertFirst(&L, H);
    PrintInfo(L);
    DelVAfter(&L, &X, H);
    printf("Nilai yang dihapus: %d\n", X);
    PrintInfo(L);

    printf("\n--------------------------------\n");
    AdrLast(&L, &P, &Q);
    printf("Alamat Last: %p\n", Q);
    printf("Nilai Alamat Last: %d\n", info(Q));
    printf("Alamat sebelum Last: %p\n", P);
    printf("Nilai Alamat sebelum Last: %d\n", info(P));
    printf("--------------------------------\n");


    printf("\n===================================NbElmt===================================\n");
    printf("Jumlah elemen: %d\n", NbElmt(L));
    printf("\n==============================================================================\n");


    return 0;
}

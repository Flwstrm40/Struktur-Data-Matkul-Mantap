/* Program   : list.c */
/* Deskripsi : file BODY modul listlinear*/
/* NIM/Nama  : 24060121130073/Muhammad Naufal Arkan*/
/* Tanggal   : 28-10-2022*/
/***********************************/

#ifndef list_C
#define list_C
#include <stdio.h>
#include "list.h"
#include "boolean.h"

address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
 dan misalnya menghasilkan P, maka
 Info(P) = X, Next(P) = Nil
 Jika alokasi gagal, mengirimkan Nil */
/*Kamus Lokal*/
    address P;
/*Algoritma*/
    P=(address)malloc(sizeof(ElmtList));
    if(P!=Nil){
        info(P)=X;
        next(P)=Nil;
    }
    return P;
}
void Dealokasi (address *P){
/* I.S. : P terdefinisi
 F.S. : P dikembalikan ke sistem
 Melakukan dealokasi/pengembalian address P */
/*Kamus Lokal*/
/*Algoritma*/
    free(*P);
}
void PrintInfo (List L){
/* I.S. : List mungkin kosong
 F.S. : Jika list tidak kosong, semua info yg disimpan pada elemen
 list diprint
 Jika list kosong, hanya menuliskan "list kosong" */
/*Kamus Lokal*/
    address P;

/*Algoritma*/
    if(ListEmpty(L)){
        printf("\nList Kosong\n");
    }
    else{
        P=First(L);
        do{
            printf("%d ",info(P));
            P=next(P);
        }while(P!=Nil); /* while(P!=First(L)) untuk circular*/
        printf("\n");
    }
}

void CreateList (List *L){
/* I.S. : sembarang
 F.S. : Terbentuk list kosong */
 /*Kamus Lokal*/

 /*Algoritma*/
    First(*L) = Nil;
}

/* ----- Test List Kosong ----- */
boolean ListEmpty (List L){
/* Mengirim true jika list kosong */
/*Kamus Lokal*/

/*Algoritma*/
    return First(L) == Nil;
}

void InsertFirst (List *L, address P){
/* I.S. : Sembarang, P sudah dialokasi
 F.S. : Menambahkan elemen ber-address P sebagai elemen pertama
*/
/*Kamus Lokal*/

/*Algoritma*/
    next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec){
/* I.S. : Prec pastilah elemen list dan bukan elemen terakhir,
 P sudah dialokasi
 F.S. : Insert P sebagai elemen sesudah elemen beralamat Prec */
/*Kamus Lokal*/

/*Algoritma*/
    next(P) = next(Prec);
    next(Prec) = P;
}

void InsertLast (List *L, address P){
/* I.S. : Sembarang, P sudah dialokasi
 F.S. : P ditambahkan sebagai elemen terakhir yang baru */
/*Kamus Lokal*/
    address Last;
/*Algoritma*/
    if (First(*L) == Nil){
        InsertFirst(L, P);
    }
    else{
        Last = First(*L);
        while(next(Last)!= Nil){
            Last = next(Last);
        }
        InsertAfter(L, P, Last);
    }
}

/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P){
/* I.S. : List tidak kosong
 F.S. : P adalah alamat elemen pertama list sebelum penghapusan
 Elemen list berkurang satu (mungkin menjadi kosong)
 First element yang baru adalah suksesor elemen pertama yang
 lama */
 /*Kamus Lokal*/
 /*Algoritma*/
    P = First(*L);
    First(*L) = next(First(*L));
}

void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. : List tidak kosong. Prec adalah anggota list L.
 F.S. : Menghapus Next(Prec) :
 Pdel adalah alamat elemen list yang dihapus*/
/*Kamus Lokal*/
/*Algoritma*/
    (*Pdel) = next(Prec);
    next(Prec) = next(next(Prec));
    next(*Pdel) = Nil;
}

void DelLast (List *L, address *P){
/* I.S. : List tidak kosong
 F.S. : P adalah alamat elemen terakhir list sebelum penghapusan
 Elemen list berkurang satu (mungkin menjadi kosong)
 Last element baru adalah predesesor elemen pertama yang
 lama, jika ada */
/*Kamus Lokal*/
    address Last, PrecLast;
/*Algoritma*/
    Last = First(*L);
    PrecLast = Nil;
    while(next(Last)!=Nil){
        PrecLast = Last;
        Last = next(Last);
    }
    (*P) = Last;
    if(PrecLast == Nil){
        First(*L) = Nil;
    }
    else{
        next(PrecLast) = Nil;
    }
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
void InsVFirst (List *L, infotype X){
/* I.S. : L mungkin kosong
 F.S. : X ditambahkan sebagai elemen pertama L
 Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen
 pertama dengan nilai X jika alokasi berhasil.
 Jika alokasi gagal, maka I.S.= F.S. */
/*Kamus Lokal*/
    address P;
/*Algoritma*/
    P = Alokasi(X);
    if(P!=Nil){
        next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVAfter (List *L, infotype X, address Prec){
/* I.S. : L mungkin kosong
 F.S. : X ditambahkan sebagai elemen setelah Prec
 Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list
 setelah Prec yaitu
 jika alokasi berhasil, elemen setelah Prec yang baru
bernilai X
 Jika alokasi gagal, maka I.S.= F.S. */
/*Kamus Lokal*/
    address P;

/*Algoritma*/
    P = Alokasi(X);
    if(P!=Nil){
        InsertAfter(L,P,Prec);
    }
}

void InsVLast (List *L, infotype X){
/* I.S. : L mungkin kosong
 F.S. : X ditambahkan sebagai elemen terakhir L
 Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list
 di akhir yaitu
 jika alokasi berhasil, elemen terakhir yang baru bernilai
X
 Jika alokasi gagal, maka I.S.= F.S. */
/*Kamus Lokal*/
    address P;
/*Algoritma*/
    P = Alokasi(X);
    if(P!=Nil){
        InsertLast(L,P);
    }
}

void AdrLast(List *L, address *Prec, address *Last){
/*mencari alamat elemen terakhir dan sebelumnya*/
/*Kamus Lokal*/
/*Algoritma*/
    (*Last) = First(*L);
    (*Prec) = Nil;
    while(next(*Last)!=Nil){
        (*Prec) = (*Last);
        (*Last) = next(*Last);
    }
}

/* Penghapusan ELemen */
void DelVFirst (List *L, infotype *X){
/* I.S. : List L tidak kosong
 F.S. : Elemen pertama list dihapus den nilai info disimpan pada X
 dan alamat elemen pertama di-dealokasi */
/*Kamus Lokal*/
    address P;
/*Algoritma*/
    P = First(*L);
    (*X) = info(P);
    First(*L) = next(First(*L));
    next(P) = Nil;
    Dealokasi(P);
}

void DelVLast (List *L, infotype *X){
/* I.S. : List L tidak kosong
 F.S. : Elemen terakhir list dihapus : nilai info disimpan pada
X
 dan alamat elemen terakhir di-dealokasi */
/*Kamus Lokal*/
    address P;
/*Algoritma*/
    DelLast(L,&P);
    (*X) = info(P);
    Dealokasi(P);
}

void DelVAfter (List *L, infotype *X, address Prec){
/* I.S. : List L tidak kosong
 F.S. : Elemen list setelah Prec dihapus : nilai info disimpan
pada X
 dan alamat elemen setelah Prec di-dealokasi */
/* Proses Semua Elemen List */
/*Kamus Lokal*/
    address P;
/*Algoritma*/
    DelAfter(L,&P,Prec);
    (*X) = info(P);
    Dealokasi(P);
}

int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
/*Kamus Lokal*/
    int banyak;
    address P;
/*Algoritma*/
    banyak = 0;
    P = First(L);
    while(P!=Nil){
        banyak = banyak + 1;
        P = next(P);
    }
    return banyak;
}

#endif // list_C

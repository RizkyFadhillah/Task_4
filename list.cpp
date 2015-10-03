#include "list.h"

using namespace std;

void createList(List &L)
{
    First(L) = NULL;
}

address alokasi(infotype x)
{
    address P = new elemenList;
    Info(P) = x;
    Next(P) = NULL;
    return P;
}

void dealokasi(address &P)
{
    delete P;
}

//procedure insert first by M. Ricky J
void insertFirst(List &L, address P){
    if (First(L) == NULL){
        First(L) = P;
        Next(P) = First(L);
        Prev(P) = First(L);
        Last(L) = First(L);
    }
    else
    {
        Next(P) = First(L);
        Prev(P) = Last(L);
        Next(Last(L)) = P;
        Prev(First(L)) = P;
        First(L) = P;
    }
}

//procedure Insert last by M. Ricky J
void insertLast(List &L, address P){
    if (First(L) == NULL){
        First(L) = P;
        Next(P) = First(L);
        Prev(P) = First(L);
        Last(L) = First(L);
    }
    else{
        Next(P) = First(L);
        Prev(P) = Last(L);
        Next(Last(L)) = P;
        Prev(First(L)) = P;
        Last(L) = P;
    }
}

//Procedure Insert after by M. Ricky J
void insertAfter(List &L, address P, address Prec){
    if (First(L) == NULL){
        insertFirst(L,P);
    }
    else if (Last(L) == Prec){
        Next(P) = First(L);
        Next(Prec) = P;
        Prev(P) = Prec;
        Prev(First(L)) = P;
        Last(L) = P;
    }
    else{
        Next(P) = Next(Prec);
        Next(Prec) = P;
        Prev(Next(P)) = P;
        Prev(P) = Prec;
    }
}
// procedure DeleteFirst by Rizky Fadhillah
void deleteFirst(list *L,address *P)
{
    *P=first(*L);
    if(*P==NULL)
    {
        cout<<"Data Kosong"<<endl;
    }
    else
    {
        first(*L)=next(first(*L));
        next(*P)=NULL;
        prev(first(*L))=NULL;
        next(*P)=NULL;
        cout<<"TIDAK ADA LAGU "<<info(*P).judul<<endl;
    }
}
// procedure DeleteLast by Rizky Fadhillah
void deleteLast(list *L,address *P)
{
    if((*L).first==NULL)
    {
        cout<<"Data Kosong"<<endl;
    }
    else if(next((*L).first)==NULL)
    {
        *P=(*L).first;
        (*L).first=NULL;
        (*L).last=NULL;
        cout<<"TIDAK ADA LAGU "<<info(*P).judul<<endl;
    }
    else
    {
    *P=(*L).last;
    (*L).last=prev((*L).last);
    prev(*P)=NULL;
    next((*L).last)=NULL;
    cout<<"Tidak Ada Lagu "<<info(*P).judul<<endl;
}}

void deleteAfter(List &L, address &P, address &Prec)
{
    P = Next(Prec);
    Next(Prec) = Next(P);
    Next(P) = NULL;
}

address findElm(List L, infotype x){
    address Q = First(L);
    while(Q != NULL){
        if(Info(Q).ID == x.ID){
            return Q;
        }
        Q = Next(Q);
    }
    return NULL;
}

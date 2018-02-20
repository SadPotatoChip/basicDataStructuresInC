#include <stdio.h>
#include <stdlib.h>
#include "../liste/liste.h"

typedef struct hash_tabela_l_
{
       cvor **tabela;
       int broj_polja;
       int (*f)(int);
}hash_tabela_l;

typedef struct hash_tabela_lin_
{
        int *tabela;
        signed char *flags;
        int broj_polja;
        int (*f)(int);
}hash_tabela_lin;

typedef struct hash_tabela_dh_
{
        int *tabela;
        signed char *flags;
        int broj_polja;
        int (*f)(int);
        int (*g)(int);
}hash_tabela_dh;

hash_tabela_l* kreiraj_hash_l(int, int (*f)(int));//kapacitet tabele, hash funkcija
cvor* pretrazi_hash_l(hash_tabela_l*, int);
void dodaj_hash_l(hash_tabela_l*, int);
void obrisi_hash_l(hash_tabela_l*, int);
void oslobodi_hash_l(hash_tabela_l*);
void ispisi_hash_tabelu(hash_tabela_l*);
hash_tabela_l* niz_u_hash_tabela_l(int*, int, int, int (*f)(int));//niz, dimenzija niza, kapacitet tabele, hash funkcija

hash_tabela_lin* kreiraj_hash_lin(int, int (*f)(int));//kapacitet tabele, hash funkcija
int pretrazi_hash_lin(hash_tabela_lin*, int);
void dodaj_hash_lin(hash_tabela_lin*, int);
void obrisi_hash_lin(hash_tabela_lin*, int);
void oslobodi_hash_lin(hash_tabela_lin*);
void ispisi_hash_tabelu_lin(hash_tabela_lin*);
hash_tabela_lin* niz_u_hash_tabela_lin(int*, int, int, int (*f)(int));//niz, dimenzija niza, kapacitet tabele, hash funkcija

hash_tabela_dh* kreiraj_hash_dh(int, int (*f)(int), int (*g)(int));//kapacitet tabele, hash funkcija
int pretrazi_hash_dh(hash_tabela_dh*, int);
void dodaj_hash_dh(hash_tabela_dh*, int);
void obrisi_hash_dh(hash_tabela_dh*, int);
void oslobodi_hash_dh(hash_tabela_dh*);
void ispisi_hash_tabelu_dh(hash_tabela_dh*);
hash_tabela_dh* niz_u_hash_tabela_dh(int*, int, int, int (*f)(int), int (*g)(int));//niz, dimenzija niza, kapacitet tabele, hash funkcija

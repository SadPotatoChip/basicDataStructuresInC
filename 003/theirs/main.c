#include "hash_table.h"

int hash_funkcija(int kljuc)
{
    return kljuc % 11;
}

int hash_funkcija1(int kljuc)
{
    return 1 + kljuc % 10;
}

int main()
{
    hash_tabela_dh *h;
    int niz[] = {22, 1, 13, 11, 24, 33, 18, 42, 31};
    h = niz_u_hash_tabela_dh(niz, 9, 11, &hash_funkcija, &hash_funkcija1);
    ispisi_hash_tabelu_dh(h);
    obrisi_hash_dh(h, 11);
    dodaj_hash_dh(h, 3);
    dodaj_hash_dh(h, 4);
    dodaj_hash_dh(h, 5);
    dodaj_hash_dh(h, 6);
    ispisi_hash_tabelu_dh(h);
    oslobodi_hash_dh(h);
    return 0;
}

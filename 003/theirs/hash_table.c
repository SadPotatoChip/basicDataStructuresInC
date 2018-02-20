#include "hash_table.h"

hash_tabela_l* kreiraj_hash_l(int len, int (*f)(int))
{
               int i;
               hash_tabela_l *tmp = (hash_tabela_l*) malloc(sizeof (hash_tabela_l));
               if(tmp == NULL)
               {
                      printf("Greska prilikom kreiranja hash tabele!\n");
                      exit(EXIT_FAILURE);
               }
               tmp->tabela = (cvor**) calloc(len, sizeof (cvor*));
               if(tmp->tabela == NULL)
               {
                      printf("Greska prilikom kreiranja hash tabele!\n");
                      exit(EXIT_FAILURE);
               }
               tmp->f = f;
               tmp->broj_polja = len;
               return tmp;
}

void oslobodi_hash_l(hash_tabela_l *h)
{
     int i;
     for(i = 0; i < h->broj_polja; i++)
     h->tabela[i] = oslobodi_listu(h->tabela[i]);
     free(h->tabela);
     free(h);
}

void dodaj_hash_l(hash_tabela_l* h, int broj)
{
     int adresa = h->f(broj);
     if(pronadji_element(h->tabela[adresa], broj) == NULL)
                                            h->tabela[adresa] = dodaj_na_pocetak(h->tabela[adresa], broj);
}

void obrisi_hash_l(hash_tabela_l *h, int broj)
{
     int adresa = h->f(broj);
     h->tabela[adresa] = izbaci_element(h->tabela[adresa], broj);
}

cvor* pretrazi_hash_l(hash_tabela_l *h, int broj)
{
      int adresa = h->f(broj);
      return pronadji_element(h->tabela[adresa], broj);
}

void ispisi_hash_tabelu(hash_tabela_l *h)
{
         int i;
         for(i = 0; i < h->broj_polja; i++)
         {
               printf("Vrsta %d: ", i);
               ispisi_listu(h->tabela[i]);
               printf("\n");
         }
}

hash_tabela_l* niz_u_hash_tabela_l(int *a, int n, int kapacitet, int (*f)(int))
{
                             int i;
                             hash_tabela_l *tmp = kreiraj_hash_l(kapacitet, f);
                             for(i = 0; i < n;i++)
                             dodaj_hash_l(tmp, a[i]);
                             return tmp;
}

hash_tabela_lin* kreiraj_hash_lin(int dim, int (*f)(int))
{
                 hash_tabela_lin *h = (hash_tabela_lin*) malloc(sizeof (hash_tabela_lin));
                 h->tabela = (int*) malloc(dim * sizeof (int));
                 if(h->tabela == NULL)
                 {
                              printf("Problem prilikom kreiranja hash tabele!\n");
                              exit(EXIT_FAILURE);
                 }
                 h->flags = (signed char*) calloc(dim, sizeof (signed char));
                 if(h->flags == NULL)
                 {
                             printf("Problem prilikom kreiranja hash tabele!\n");
                             exit(EXIT_FAILURE);
                 }
                 h->f = f;
                 h->broj_polja = dim;
                 return h;
}

int pretrazi_hash_lin(hash_tabela_lin *h, int br)
{
      int adresa = h->f(br), tmp;
      if(h->tabela[adresa] == br && h->flags[adresa] == 1)
      return adresa;
      tmp = adresa;
      while((tmp = (tmp + 1)) % h->broj_polja != adresa)
      {
                 if(h->tabela[tmp] == br && h->flags[tmp] == 1)
                 return tmp;
                 if(h->flags[tmp] == 0)
                 break;
      }
      return -1;
}

void dodaj_hash_lin(hash_tabela_lin *h, int br)
{
     int adresa = h->f(br), tmp;
     if(pretrazi_hash_lin(h, br) != -1)
     {
                             printf("Vrednost se vec nalazi u tabeli!\n");
                             return;
     }
     if(h->flags[adresa] != 1)
      {
                         h->tabela[adresa] = br;
                         h->flags[adresa] = 1;
                         return;
      }
      tmp = adresa;
      while((tmp = (tmp + 1) % h->broj_polja) != adresa)
      {
                 if(h->flags[tmp] != 1)
                 {
                                  h->tabela[tmp] = br;
                                  h->flags[tmp] = 1;
                                  return;
                 }
      }
      printf("Upozorenje: Hash tabela je puna!\n");
}

void obrisi_hash_lin(hash_tabela_lin *h, int br)
{
     int adresa = pretrazi_hash_lin(h, br);
     if(adresa != -1)
     h->flags[adresa] = -1;
}

void oslobodi_hash_lin(hash_tabela_lin *h)
{
     free(h->tabela);
     free(h->flags);
     free(h);
}

void ispisi_hash_tabelu_lin(hash_tabela_lin *h)
{
     int i;
     for(i = 0; i < h->broj_polja; i++)
     {
           if(h->flags[i] == 1)
           printf("Vrsta %d: %d\n", i, h->tabela[i]);
           else
           printf("Vrsta %d: -\n", i);
     }
}

hash_tabela_lin* niz_u_hash_tabela_lin(int *niz, int dim, int kap, int (*f)(int))
{
                 int i;
                 hash_tabela_lin *h = kreiraj_hash_lin(kap, f);
                 for(i = 0; i < dim; i++)
                       dodaj_hash_lin(h, niz[i]);
                 return h;
}

hash_tabela_dh* kreiraj_hash_dh(int dim, int (*f)(int), int (*g)(int))
{
                 hash_tabela_dh *h = (hash_tabela_dh*) malloc(sizeof (hash_tabela_dh));
                 h->tabela = (int*) malloc(dim * sizeof (int));
                 if(h->tabela == NULL)
                 {
                              printf("Problem prilikom kreiranja hash tabele!\n");
                              exit(EXIT_FAILURE);
                 }
                 h->flags = (signed char*) calloc(dim, sizeof (signed char));
                 if(h->flags == NULL)
                 {
                             printf("Problem prilikom kreiranja hash tabele!\n");
                             exit(EXIT_FAILURE);
                 }
                 h->f = f;
                 h->g = g;
                 h->broj_polja = dim;
                 return h;
}

int pretrazi_hash_dh(hash_tabela_dh *h, int br)
{
      int adresa = h->f(br), tmp;
      if(h->tabela[adresa] == br && h->flags[adresa] == 1)
      return adresa;
      tmp = adresa;
      while((tmp = (tmp + h->g(br))) % h->broj_polja != adresa)
      {
                 if(h->tabela[tmp] == br && h->flags[tmp] == 1)
                 return tmp;
                 if(h->flags[tmp] == 0)
                 break;
      }
      return -1;
}

void dodaj_hash_dh(hash_tabela_dh *h, int br)
{
     int adresa = h->f(br), tmp;
     if(pretrazi_hash_dh(h, br) != -1)
     {
                             printf("Vrednost se vec nalazi u tabeli!\n");
                             return;
     }
     if(h->flags[adresa] != 1)
      {
                         h->tabela[adresa] = br;
                         h->flags[adresa] = 1;
                         return;
      }
      tmp = adresa;
      while((tmp = (tmp + h->g(br)) % h->broj_polja) != adresa)
      {
                 if(h->flags[tmp] != 1)
                 {
                                  h->tabela[tmp] = br;
                                  h->flags[tmp] = 1;
                                  return;
                 }
      }
      printf("Upozorenje: Hash tabela je puna!\n");
}

void obrisi_hash_dh(hash_tabela_dh *h, int br)
{
     int adresa = pretrazi_hash_dh(h, br);
     if(adresa != -1)
     h->flags[adresa] = -1;
}

void oslobodi_hash_dh(hash_tabela_dh *h)
{
     free(h->tabela);
     free(h->flags);
     free(h);
}

void ispisi_hash_tabelu_dh(hash_tabela_dh *h)
{
     int i;
     for(i = 0; i < h->broj_polja; i++)
     {
           if(h->flags[i] == 1)
           printf("Vrsta %d: %d\n", i, h->tabela[i]);
           else
           printf("Vrsta %d: -\n", i);
     }
}

hash_tabela_dh* niz_u_hash_tabela_dh(int *niz, int dim, int kap, int (*f)(int), int (*g)(int))
{
     int i;
     hash_tabela_dh *h = kreiraj_hash_dh(kap, f, g);
     for(i = 0; i < dim; i++)
           dodaj_hash_dh(h, niz[i]);
     return h;
}

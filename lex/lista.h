typedef struct node_t{
	int val;
	struct node_t next;
	struct node_t prev;
}node;
void Stampaj(Lista* l);
void Dodaj(Lista** lp, int b);
void ObrisiListu(Lista** lp);
void ObrisiElement(Lista** lp, int e);
int BrojElemenata(Lista* l);

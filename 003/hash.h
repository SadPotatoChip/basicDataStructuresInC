typedef struct hash_t{
	int *values;
	signed char *flags;
	int lenght;
	int (*f)(int);
	int (*g)(int);	
}hashTable;
hashTable* makeHashTable(int size, int (*f)(int), int (*g)(int));
void addValueToHashTable(hashTable *ht, int val);
int getValueAdress(hashTable *ht, int val);
void printHashTable(hashTable *ht);

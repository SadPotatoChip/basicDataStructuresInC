typedef struct hash_t{
	int *values;
	signed char *flags;
	int lenght;
	int (*f)(int);
	int (*g)(int);	
}hashTable;
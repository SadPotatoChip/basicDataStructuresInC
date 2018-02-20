#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#define HASHSIZE1 50

int f(int n){
	return n%37;
}

int f1(int n){
	return (1+n)%13;
}

int main(){
	hashTable *ht=makeHashTable(HASHSIZE1,*f,*f1);
	addValueToHashTable(ht, 5);
	addValueToHashTable(ht, 557);
	addValueToHashTable(ht, 65);
	addValueToHashTable(ht, 1);
	addValueToHashTable(ht, 76);
	printHashTable(ht);
	printf("%d\n", getValueAdress(ht,65));
	
	return 0;
}
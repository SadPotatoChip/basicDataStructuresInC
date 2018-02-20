#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hash.h"

 
hashTable* makeHashTable(int size, int (*f)(int), int (*g)(int)){
	hashTable *tmp=malloc(sizeof(hashTable));
	assert(tmp!=NULL);
	tmp->lenght=size;
	tmp->values=malloc(sizeof(int)*size);
	assert(tmp->values!=NULL);
	tmp->flags=malloc(sizeof(unsigned char)*size);
	assert(tmp->flags!=NULL);
	tmp->f=f;
	tmp->g=g;		
	return tmp;
}

void addValueToHashTable(hashTable *ht, int val){
	int adress=ht->f(val);
	
	if(ht->flags[adress]==0){
		ht->flags[adress]=1;
		ht->values[adress]=val;
		return;
	}
	int tmp = adress;
	while((tmp = (tmp + 1) % ht->lenght) != adress){
		if(ht->flags[tmp] != 1){
			ht->values[tmp] = val;
            ht->flags[tmp] = 1;
			return;
		}
	}
}

int getValueAdress(hashTable *ht, int val){
	int adress=ht->f(val);
	
	if(ht->flags[adress]==1 && ht->values[adress]==val){
		return adress;
	}
	int tmp = adress;
	while((tmp = (tmp + 1)) % ht->lenght != adress)
	{
		if(ht->values[tmp] == val && ht->flags[tmp] == 1)
			return tmp;
		if(ht->flags[tmp] == 0)
			break;
	}
	return -1;
	
}

void printHashTable(hashTable *ht){
	printf("[ ");
	int i;
	for(int i=0; i<ht->lenght;i++){
		if(ht->flags[i]==1){
			printf("(%d->%d) ",i,ht->values[i]);
		}
	}
	
	printf("]\n");
}
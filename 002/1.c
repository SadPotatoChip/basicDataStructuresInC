#include <stdio.h>
#include <stdlib.h>
#include "treez.h"


int main(int argc, char** argv){
	node *t=malloc(sizeof(node));
	t->val=1;
	node *t1=malloc(sizeof(node));
	t1->val=2;
	node *t2=malloc(sizeof(node));
	t2->val=3;
	node *t3=malloc(sizeof(node));
	t3->val=4;
	node *t4=malloc(sizeof(node));
	t4->val=5;
	t->left=t1;
	t->right=t2;
	t1->left=t3;
	t3->right=t4;
	
	
	
	bfs(t);
	
	
	return 0;
}

/*			1
 *		/   	\
 * 		2		3
 *	/
 * 4
 * 	\
 * 	5
 * 
 * 
 * 
 * 
 * 
 */
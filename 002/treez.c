#include <stdio.h>
#include <stdlib.h>
#include "treez.h"

void getNodeVal(node* x){
	printf("%d\n",x->val);
}

void dfs(node* head){
	getNodeVal(head);
	if(head->left)
		dfs(head->left);
	if(head->right)
		dfs(head->right);	
}

void bfs(node* head){
	node *q;
	enqueue(q,head);
	_bfs(head, q);
}

void _bfs(node* head, node* q){	
	dequeue(&q);
	if(head->left)
		enqueue(q, head->left);
	if(head->right)
		enqueue(q, head->right);
}



void enqueue(node* q, node* new){
	if(q){
		while(q->right){
			q=q->right;
		}
		q->right=new;	
	}else{		
		q=new;
		q->right=NULL;
	}
}

node* dequeue(node** q){
	printf("q=%d\n",(*q)->val);
	node* tmp=*q;
	if(*q!=NULL)
		*q=(*q)->right;

	return tmp;	
}
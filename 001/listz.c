#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "listz.h"

int printList(node *head);


int getNodeVal(node target){
	return target.val;
}

node newNodeV(int val){
	node *n=malloc(sizeof(node));
	n->val=val;
	n->next=NULL;
	return *n;	
}

node newNode(int val,node *next){
	node *n=malloc(sizeof(node));
	n->val=val;
	n->next=next;
	return *n;	
}

node newNodeP(int val,node *next,node *prev){
	node *n=malloc(sizeof(node));
	n->val=val;
	n->next=next;
	n->prev=prev;
	prev->next=n;
	return *n;	
}

node* addNode(node *head, int val){
		node *new = malloc(sizeof(node));
		new->val=val;
		
		if(head==NULL){
			head=new;
			return head;
		}
		
		node *current=head;
		int i=0;
		while(current->next!=NULL){
			current=current->next;
			i++;
			
		}
		current->next=new;
		return head;
			
	
}

node* addNodeFromNode(node *head, node *new){
		
		if(head==NULL){
			head=new;
			return head;
		}
		
		node *current=head;
		int i=0;
		while(current->next!=NULL){
			current=current->next;
			i++;
			
		}
		current->next=new;
		return head;
			
	
}

node* addNodeToStart(node *head, int val){
	node *new = malloc(sizeof(node));
	new->val=val;
			
	if(head==NULL){
		head=new;
		return new;
	}
	new->next=head;
	
	return new;
	
}

node listFromNumbers(node *head, int n, ...){
	va_list valist;
	va_start(valist,n);
	
	node tmp;
	int i=0;

	
	for (i = 0; i < n; i++) {
		addNode(head,va_arg(valist, int));
	}
	return *head;
	
}

node flipList(node **head){
	node *previous=NULL,*next,*current;	
	current=*head;
	if(current==NULL || current->next==NULL)
		return *current;
	
	while(current->next){
		next=current->next;
		current->next=previous;
		previous=current;
		current=next;
	}
	current->next=previous;
	*head=current;
	return *current;
	
}


int printList(node *head){
	if(head==NULL){
		printf("empty list\n");
		return -1;
	}
	
	int i=0;
	while(head){
		printf("(%d: %d), ",i,head->val);
		head=head->next;
		i++;
	}
	printf("\n");
	return i;
}

int freeList(node *head){
	while(head!=NULL){
		node *next=head->next;
		free(head);
		head=next;
	}
	return 1;
}
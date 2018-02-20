#include <stdio.h>
#include <stdlib.h>
#include "listz.h"
#include "treez.h"
#include "stackqueue.h"

void push(stack *s, int val){
	s->top=addNodeToStart(s->top,val);
}

node* pop(stack *s){
	node *tmp=s->top;
	if(tmp!=NULL)
		s->top=s->top->next;
	return tmp;	
}


void enqueue(queue *q, int val){
	q->start=addNode(q->start,val);
}

void enqueueFromNode(queue *q, node* x){
	q->start=addNodeFromNode(q->start,x);
}

node* dequeue(queue *q){
	node *tmp=q->start;
	if(tmp!=NULL)
		q->start=q->start->next;
	return tmp;	
}
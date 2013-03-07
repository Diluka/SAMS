#include<cstdlib>
#include"storage.h"
#include<fstream>

STUDENT* create(STUDENT_INFO &info){
	STUDENT *ps;
	ps=(STUDENT*)malloc(sizeof(STUDENT));
	if(ps!=NULL){
		ps->info=info;
		ps->next=NULL;
		ps->prev=NULL;
	}
	else
	{
		//TODO Not Enough Memery!!
	}
}

bool insert(STUDENT **ps,STUDENT *s){
	STUDENT *curr;

	while ((curr=*ps)!=NULL)
	{
		ps=&curr->next;
	}

	if(s==NULL)return false;
	curr->next=s;
	s->next=*ps;
	(*ps)->prev=s;
	s->prev=curr;

	return true;
}

void freelist(STUDENT *head){
	if(head=NULL){
		//TODO Empty!
		return;
	}

	STUDENT *ptr=head;
	STUDENT *curr;

	while (ptr->next!=NULL)
	{
		curr=ptr;
		ptr=ptr->next;
		free(curr);
	}
	free(ptr);
}

void print(STUDENT *head){
	if(head=NULL){
		//TODO Empty!
		return;
	}

	while (head->next!=NULL)
	{
		head=head->next;
		//TODO print
	}
}

void erase(STUDENT *ptr){
	if(ptr=NULL)return;
	
	(ptr->prev)->next=(ptr->next);
	(ptr->next)->prev=(ptr->prev);
	free(ptr);
}

STUDENT* search(STUDENT *head,int id){
	if(head==NULL)return NULL;

	while (head!=NULL)
	{
		if(head->info.sid==id)return head;
		head=head->next;
	}

	return NULL;
}
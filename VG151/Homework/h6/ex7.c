#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

node_t *Initialize(char ch) {
//	fprintf(stderr,"1 ");
	node_t *head;
    head = (node_t *) calloc(1, sizeof(node_t));
    if (head == NULL) {
        fprintf(stderr, "Failed to assign memory!\n");
        exit(-1);
    }
    head->next = NULL;
    head->ch = ch;
//    fprintf(stderr,"-1 ");
    return head;
}

void PrintList(node_t *head) {
//	fprintf(stderr," 2 %p ",(void*)head);
    node_t *temp = head;
	printf("***Print Linked List***\n");
    while (temp != NULL) {
        printf("%c ", temp->ch);
        temp = temp->next;
    }
    printf("\n****Print Finished****\n\n");
//    fprintf(stderr,"-2 ");
}

void FreeList(node_t **head) {
//	fprintf(stderr,"%p\n",(void*)*head);
    node_t *tmp = NULL;
    node_t *pHead = *head;
	*head=NULL;
	while (pHead->next != NULL) {
        tmp = pHead;
        pHead = pHead->next;
        free(tmp); tmp=NULL;
//		fprintf(stderr,"%p\n",(void*)pHead);
	}
    free(pHead); pHead=NULL;
//	fprintf(stderr,"%p\n",(void*)pHead);
//	fprintf(stderr,"%p\n",(void*)*head);
//	fprintf(stderr,"-3 ");
}

bool IsEmptyList(node_t *head) {
//	fprintf(stderr,"4 ");
//	fprintf(stderr,"-4 ");
    return (head==NULL);
}

void InsertFirstList(node_t **head, char insert_char) {
//	fprintf(stderr,"5 ");
    if (IsEmptyList(*head)){
	    *head=(node_t*)calloc(1,sizeof(node_t));
	    (*head)->next=NULL; (*head)->ch=insert_char;
		return;
    }
	node_t *tmp=*head;
	node_t *nw=(node_t*)calloc(1,sizeof(node_t));
	*head=nw;
	nw->next=tmp; nw->ch=insert_char;
//	fprintf(stderr,"-5 ");
}

void InsertLastList(node_t **head, char insert_char) {
//	fprintf(stderr,"6 ");
	if (IsEmptyList(*head)){
		*head=(node_t*)calloc(1,sizeof(node_t));
		(*head)->next=NULL; (*head)->ch=insert_char;
		return;
	}
    node_t *tmp=*head;
	while (tmp->next!=NULL) tmp=tmp->next;
	node_t *nw=(node_t*)calloc(1,sizeof(node_t));
	tmp->next=nw; 
	nw->next=NULL; nw->ch=insert_char;
//	fprintf(stderr,"-6 ");
}

void DeleteFirstList(node_t **head) {
//	fprintf(stderr,"7 ");
    if (IsEmptyList(*head)) return;
	node_t *tmp=*head;
	node_t *nhead=tmp->next;
	*head=nhead;
	free(tmp); tmp=NULL;
//	fprintf(stderr,"-7 ");
}

void DeleteLastList(node_t **head) {
//	fprintf(stderr,"8 ");
    if (IsEmptyList(*head)) return;
	node_t *tmp=*head;
	node_t *lst=NULL;
	while (tmp->next!=NULL){
		lst=tmp;
		tmp=tmp->next;
	}
	if (lst!=NULL) lst->next=NULL; 
	free(tmp); tmp=NULL;
	if (lst==NULL) *head=NULL;
//	fprintf(stderr,"-8 ");
}

int SizeList(node_t *head) {
//	fprintf(stderr,"9 ");
    int cnt=1;
	if (IsEmptyList(head)) return 0;
	node_t *tmp=head;
	while (tmp->next!=NULL) tmp=tmp->next,cnt++;
//	fprintf(stderr,"-9 ");
	return cnt;
}

int SearchList(node_t **head, char target) {
//	fprintf(stderr,"10 ");
    int cnt=0;
	if (IsEmptyList(*head)) return 0;
	node_t *tmp=*head;
	while (tmp->next!=NULL){
		if (tmp->ch==target) cnt++;
		tmp=tmp->next;
	}
	if (tmp->ch==target) cnt++;
//	fprintf(stderr,"-10 ");
	return cnt;
}

void SplitList(node_t **head, node_t **tail, int pos) {
//	fprintf(stderr,"11 ");
	if (IsEmptyList(*head)) return;
	node_t *tmp=*head;
	int cnt=0;
	while (tmp!=NULL&&cnt<pos-1) cnt++,tmp=tmp->next;
	if (cnt==pos-1&&tmp!=NULL){
		*tail=tmp->next;
		tmp->next=NULL;
	}
	else *tail=NULL;
//	fprintf(stderr,"-11 %p %p ",(void*)*head,(void*)*tail);
}

void MergeList(node_t **head1, node_t **head2) {
//	fprintf(stderr,"12 ");
    if (IsEmptyList(*head1)){
		*head1=*head2; *head2=NULL;
		return;
	}
	node_t *tmp=*head1;
	while (tmp->next!=NULL) tmp=tmp->next;
	tmp->next=*head2; *head2=NULL;
//	fprintf(stderr,"-12 ");
}

#ifndef JOJ
int main(){
	node_t **list=(node_t**)calloc(10,sizeof(node_t*));
	list[0]=Initialize('a');
	PrintList(list[0]);
	InsertFirstList(list,'b');
	PrintList(list[0]);
	DeleteLastList(list);
	PrintList(list[0]);
	return 0;
}
#endif

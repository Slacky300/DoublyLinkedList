#include <stdio.h>
#include <stdlib.h>

struct node{

    int data;
    struct node *prev,*next;

}*head = NULL;

struct node *addAtEnd(struct node *head,int value){

    struct node *temp,*p;
    p = head;
    temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    if(p==NULL){
        temp->prev = NULL;
        head = temp;
        temp->next = NULL;
    }else{
        while(p!=NULL){
            p=p->next;
        }
        p->next = temp;
        temp->prev = p;

        temp->next = NULL;


    }

    return head;


}

void display(struct node *head){

    struct node *p;
    p = head;
    if(p==NULL){
        printf("Linked list is empty\n");
    }else{

        while(p!=NULL){
            printf("%d\t",p->data);
            p = p->next;
        }

    }

}

struct node *createList(struct node *head){


    int i,limit,hold;
    printf("Enter the no. of nodes you want to enter\n");
    scanf("%d",&limit);
    for(int i = 0;i<limit;i++){
        printf("Enter the value to add: ");
        scanf("%d",&hold);
        head = addAtEnd(head,hold);
    }

    return head;

}

struct node *addAtBeg(struct node *head,int value){

        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data= value;
        temp->prev = NULL;
        temp->next = head->next;
        temp = head;
        return head;

}

void main(){

    head = createList(head);
    display(head);


}

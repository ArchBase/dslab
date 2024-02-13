#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front=NULL, *rear=NULL;

void enqueue(int data){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next=NULL;
    if(front==NULL){// First case
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    struct node *temp;
    temp = front;
    if(front == NULL){
        printf("queue empty");
    }
    else{
        printf("Deleted: %d", front->data);
        if(front->next == NULL){
            front=NULL;
            free(temp);
        }
        else{
            front = front->next;
            free(temp);
        }
    }
}

void display(){
    struct node *current;
    current = front;
    if(front == NULL){
        printf("Queue empty");
    }
    else{
        printf("Queue is: ");
        do{
            printf(" %d", current->data);
            if(current->next!=NULL){
                current = current->next;
            }
            else{
                break;
            }
        }while(1);
    }
}


void main(){
    int choice;
    printf("\n\ndisp --> 1\nenqu --> 2\ndequ --> 3\n");
    while(1){
        printf("\nEnter option: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                display();
                break;
            case 2:
                printf("item?: ");
                scanf("%d", &choice);
                enqueue(choice);
                break;
            case 3:
                dequeue();
                break;
        }
    }
}



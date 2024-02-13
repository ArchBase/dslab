#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;
void insert_begning(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if(start == NULL){
        newNode->next = NULL;
        start = newNode;
        return;
    }
    newNode->next = start;
    start = newNode;
}
void insert_end(int data){
    struct node *current = start;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    newNode->next = NULL;
}
void insert_pos(int data, int pos){
    int i=0;
    struct node *current=start;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if(pos == 0){// insert begning
        insert_begning(data);
        return;
    }
    while(i < pos){
        if(current->next == NULL){
            printf("invalid position");
            return;
        }
        current = current->next;
        i++;
    }
    newNode->next = current->next;
    current->next = newNode;
    return;
}

void delete_begning(){
    struct node *temp;
    if(start == NULL){
        printf("list empty.");
        return;
    }
    printf("Deleted: %d", start->data);
    temp = start;
    start = start->next;
    free(temp);
}

void delete_end(){
    struct node *current=start;
    if(start == NULL){
        printf("list empty.");
        return;
    }
    while((current->next)->next != NULL){
        current = current->next;
    }
    printf("Deleted: %d", current->next->data);
    free(current->next);
    current->next = NULL;
}

void delete_pos(int pos){
    int i=0;
    struct node *current = start, *temp;
    while(i < pos){
        current = current->next;
        if(current->next->next == NULL){
            delete_end();
            return;
        }
        i++;
    }
    temp = current->next;
    current->next = current->next->next;
    printf("Deleted: %d", temp->data);
    free(temp);
}

void display(){
    struct node *current=start;
    if(start == NULL){
        printf("list empty");
        return;
    }
    printf("list is:");
    do{
        printf(" -> %d", current->data);
        if(current->next == NULL){
            break;
        }
        current = current->next;
    }while(1);
}

void main(){
    int choice, pos;
    printf("\n\nins b --> 1\nins e --> 2\nins p --> 3\ndel b --> 4\ndel e --> 5\ndel p --> 6\ndiply --> 7\n");
    while(1){
        printf("\n\nEnter your option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("item? : ");
            scanf("%d", &choice);
            insert_begning(choice);
            break;
        
        case 2:
            printf("item? : ");
            scanf("%d", &choice);
            insert_end(choice);
            break;
        
        case 3:
            printf("item ? : ");
            scanf("%d", &choice);
            printf("pos ? : ");
            scanf("%d", &pos);
            insert_pos(choice, pos);
            break;
        case 4:
            delete_begning();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            printf("pos ? : ");
            scanf("%d", &pos);
            delete_pos(pos);
            break;
        case 7:
            display();
            break;
        }
    }
}




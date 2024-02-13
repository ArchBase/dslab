#include <stdio.h>

#define MAXSIZE 10

struct queue{
    struct{
        int priority;
        int item;
    }elements[MAXSIZE];
};

struct queue q;
int front=-1, rear=-1;

void shift(){
    int i;
    for(i=1; i<MAXSIZE; i++){
        q.elements[i-1].priority = q.elements[i].priority;
        q.elements[i-1].item = q.elements[i].item;
    }
    rear--;
    front--;
}
void sort(){
    printf("Sorting");
    int i, j, temp;
    for(i=0; i<MAXSIZE-1; i++){
        for(j=0; j<MAXSIZE-i-1; j++){
            if(q.elements[j].priority < q.elements[j+1].priority){
                temp = q.elements[j].priority;
                q.elements[j].priority = q.elements[j+1].priority;
                q.elements[j+1].priority = temp;

                temp = q.elements[j].item;
                q.elements[j].item = q.elements[j+1].item;
                q.elements[j+1].item = temp;
            }
        }
    }
}


void enqueue(int item, int priority){
    if(rear == MAXSIZE-1){
        printf("Queue full");
    }
    else if(front==-1){
        front=0;
        rear=0;
        q.elements[rear].priority = priority;
        q.elements[rear].item = item;
        //sort();
    }
    else{
        rear++;
        //printf("Prio: %d", priority);
        q.elements[rear].priority = priority;
        q.elements[rear].item = item;
        sort();
    }
}

void dequeue(){
    if(front == -1){
        printf("Queue empty");
    }
    else{
        printf("Deleted item: %d, prio: %d", q.elements[front].item, q.elements[front].priority);
        front++;
        shift();
    }
}

void display(){
    int i;
    printf("Queue is: (item - prio)\n");
    for(i=0; i<=MAXSIZE; i++){
        printf("%d %d\n", q.elements[i].item, q.elements[i].priority);
    }
}


void main(){
    int c, i, p;

    // Initialization
    for(i=0; i<=MAXSIZE; i++){
        q.elements[i].priority = -1;
    }

    printf("\n\ndis --> 1\nins --> 2\ndel --> 3\n");
    while(1){
        printf("\nEnter choice: ");
        scanf("%d", &c);
        switch(c){
            case 1: display();
                    break;
            case 2: printf("Enter (item prio): ");
                    scanf("%d %d", &i, &p);
                    enqueue(i, p);
                    break;
            case 3: dequeue();
                    break;

        }
    }
    
}


#include <stdio.h>

#define MAXSIZE 5

int q[MAXSIZE], front=-1, rear=-1;

void enqueue_rear(int item){
    if(rear == MAXSIZE-1){
        printf("Can't insert at rear.");
    }
    else if(front==-1){
        front=0;
        rear=0;
        q[rear] = item;
    }
    else{
        rear++;
        q[rear] = item;
    }
}

void enqueue_front(int item){
    if(front == -1 || front == 0){
        printf("Can't insert at front.");
        return;
    }
    else{
        front--;
        q[front] = item;
    }    
}

int dequeue_front(){
    int deleted;
    if(front == -1){
        printf("Can't delete from front.");
        return -1;
    }
    else{
        deleted = q[front];
        q[front] = NULL;
        front++;
        return deleted;
    }
}

int dequeue_rear(){
    int deleted;
    if(rear == -1){
        printf("Can't delete from rear.");
        return -1;
    }
    else{
        deleted = q[rear];
        rear--;
        return deleted;
    }
}

void display(){
    int i;
    printf("Queue is:");
    for(i=0; i<=MAXSIZE; i++){
        printf(" %d", q[i]);
    }
}

void main(){
    int c;
    printf("\n\nins r --> 1\nins f --> 2\ndel f --> 3\ndel r --> 4\ndiply --> 5");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &c);
        switch(c){
            case 1: printf("item? : ");
                    scanf("%d", &c);
                    enqueue_rear(c);
                    break;
            case 2: printf("item? : ");
                    scanf("%d", &c);
                    enqueue_front(c);
                    break;
            case 3: printf("Deleted %d", dequeue_front());
                    break;
            case 4: printf("Deleted %d", dequeue_rear());
                    break;
            case 5: display();
                    break;
        }
    }
}

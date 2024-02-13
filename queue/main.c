#include <stdio.h>

#define MAXSIZE 4


int q[100], front=-1, rear=-1;

void enqueue(int item){
    if(front == (rear + 1) % MAXSIZE){
        printf("Queue full");
    }
    else if(front == -1){
        front=0;
        rear=0;
        q[front] = item;
    }
    
    else{
        rear = (rear + 1) % MAXSIZE;
        q[rear] = item;
    }
}

int dequeue(){
    int deleted;
    if(front == -1){
        printf("Queue empty");
        return -1;
    }
    else{
        deleted = q[front];
        front = (front + 1) % MAXSIZE;
        if(front == rear){
            front = -1;
        }
        return deleted;
    }
}

void display(){
    int i;
    printf("\nQueue: ");
    if(front < rear){
        for (i = front; i <= rear; i++){
            printf("%d ", q[i]);
        }
    }
    else if(rear < front){
        for(i=front; i<MAXSIZE; i++){
            printf("%d ", q[i]);
        }
        for(i=0; i<=rear; i++){
            printf("%d ", q[i]);
        }
    }

    
}

void main(){
    int c=0;
    printf("\n\ndis --> 1\nins --> 2\ndel --> 3\nexit --> 9\n\n");
    while (c != 9){
        printf("\n\nEnter option: ");
        scanf("%d", &c);

        switch (c){
            case 1: display();
                break;
            case 2: printf("item? : ");
                    scanf("%d", &c);
                    enqueue(c);
                break;
            case 3: printf("Deleted : %d", dequeue());
                break;

            default:
                break;
        }


    }
    
    

}



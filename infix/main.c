#include <stdio.h>
#define MAX 100

int top=-1, postifix_index=-1;
char stack[MAX], infix[MAX], postfix[MAX];

int get_priority(char operator){
    switch(operator){
        case '+':
        case '-':
            return(1);
        case '/':
        case '*':
            return(2);
        default:
            return(0);
    }
}



void append(char item){
    postifix_index++;
    postfix[postifix_index] = item;
}

void push(char item){
    //printf("Pushing");
    top++;
    stack[top] = item;
}

int isEmpty(){
    if(top > -1){// not empty
        return 1;
    }
    else{
        return 0;
    }
}

char pop(){
    if(top == -1){
        return '\0';
    }
    char popped;
    popped = stack[top];
    top--;
    return popped;
}

void convert_to_post(){
    int j;
    char symbol;
    for (int i = 0; infix[i] != '\0'; i++){
        switch(infix[i]){
            case '(':
                push(infix[i]);
                break;
            case ')':
                do{
                    symbol = pop();
                    if(symbol != '('){
                        append(symbol);
                    }else{
                        break;
                    }
                }while(1);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while(isEmpty() && ((get_priority(stack[top]) >= get_priority(infix[i])))){
                    //printf("hai");
                    append(pop());
                }
                push(infix[i]);
                break;
            default:
                append(infix[i]);
                   
        }
    }
    while(isEmpty()){
        append(pop());
    }
}


void main(){
    int i;
    printf("Enter infix: ");
    scanf("%s", infix);
    convert_to_post();
    printf("postfix: ");
    for(i=0; postfix[i] != '\0'; i++){
        printf("%c", postfix[i]);
    }
}







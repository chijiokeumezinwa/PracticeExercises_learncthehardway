#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100;

struct stackNode{
    int data;
    struct stackNode *next;
};

struct stack{
    int items[MAX_SIZE];
    struct stackNode *top;
};

struct stackNode *createStack(){
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->top = -1;
    return s;
}

void push(struct stack *s, int data){
    if(isFull(s)){
        printf("Stack is full. Cannot push item.\n");
        return -1;
    }
    s->items[++stack->top] = data;
}

int pop(struct stack *s){
    if(isEmpty(stack)){
        printf("Stack is empty. Cannot peak. \n");
        return -1;
    }
    return stack->items[stack->top--];
}

int top(struct stack *s){
    if(s->top == NULL){
        printf("Stack is empty. \n");
        return -1;
    }
    return s->items[stack->top];
}

int isEmpty(struct stack *s){
    return s->top == -1;
}

int isFull(struct stack *s){
    return s->top == MAX_SIZE - 1;
}

int size(struct stack *s){
    return s->top + 1;
}

void clear(struct stack *s){
    while(!isEmpty(s)){
        pop(s);
    }
}

void display(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents: ");
    for(int i = 0; i <= stack->top; i++){
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}
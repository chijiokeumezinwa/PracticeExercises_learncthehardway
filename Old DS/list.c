#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

struct node *createNode(int value){
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

//display
void printList(struct node *p){
    printf("\n[");

    //start from beginning
    while(p != NULL){
        printf(" %d ", p->data);
        p = p->next;
    }
    printf("]");
}

//insertatbeginning
//passing pointer to pointer parameter allows the changing of 
//the head pointer directly instead of returning the new one
void insertatbegin(struct node **head, int value){
    //allocate memory to node
   struct node *newNode = createNode(value);
   newNode->next = *head; 
    //move head to new node
    (*head) = newNode;
}

void insertafter(struct Node * prev_node, int data){
    //check to see if prev_node is null
    if(prev_node == NULL){
        printf("The given previous node cannot be null");
        return;
    }

    struct node *newNode = createNode(value);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertatend(struct node** head, int value){
    struct node *newNode = createNode(value);
    
    if(*head == NULL){
        *head= newNode;
        return;
    }

    struct node *current=*head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}

void deletenode(struct node** head_ref, int key){
    struct node *temp = *head_ref, *prev;

    if(temp != NULL &&
        temp->data == key){
            *head_ref = temp->next;
            free(temp);
            return;
        }
    //find key to be deleted
    while(temp != NULL &&
        temp->data != key){
            prev = temp;
            temp = temp->next;
        }
} 
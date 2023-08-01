#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

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
void insertatbegin(struct node **head_ref, int data){
    //allocate memory to node
    struct node * new_node = (struct node*) malloc(sizeof(struct node));

    //insert the data
    new_node->data = new_data;
    new_node->next =(*head_ref);

    //move head to new node
    (*head_ref) = new_node;
}

void insertafter(struct Node * prev_node, int data){
    if(prev_node == NULL){
        printf("The given previous node cannot be null");
        return;
    }

    struct node * new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertatend(struct node** head_ref, int data){
    struct node *new_node =(struct node*) malloc(sizeof(struct node));
    stuct node *last=*head_ref;

    new_node->data = data;
    new_node->next =NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
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
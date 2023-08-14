#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *createNode(int data){
    struct node *newNode = (struct node*) malloc(sizeof(struct node));

    if(newNode == NULL){
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

//display
void displayList(struct node *head){
    printf("\n[");
    struct node* p = head;
    //start from beginning
    while(p != NULL){
        printf(" %d ", p->data);
        p = p->next;
    }
    printf("]\n");
}

void reverseDisplay(struct Node* head) {
    if (head == NULL)
        return;
    
    reverseDisplay(head->next); // Recursively call for the next node
    
    printf("%d -> ", head->data); // Display the current node's data
}

struct Node* search(struct Node* head, int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current; // Return the node with the value
        }
        current = current->next; // Move to the next node
    }
    return NULL; // Value not found in the list
}

int getLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

int countOccurrences(struct Node* head, int value) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            count++;
        }
        current = current->next;
    }
    return count;
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

void deleteNode(struct Node** head, int value) {
    if (*head == NULL)
        return;

    struct Node* temp = *head;
    if (temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node* prev;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL)
        return;

    struct Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node* prev;
    for (int i = 0; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct Node* mergedList = NULL;
    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = mergeLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeLists(list1, list2->next);
    }

    return mergedList;
}

struct Node* concatenateLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL)
        return list2;

    struct Node* current = list1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = list2;

    return list1;
}


struct Node* mergeSort(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* middle = getMiddle(head);
    struct Node* nextOfMiddle = middle->next;
    middle->next = NULL;

    struct Node* left = mergeSort(head);
    struct Node* right = mergeSort(nextOfMiddle);

    return merge(left, right);
}

struct Node* getMiddle(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

struct Node* merge(struct Node* list1, struct Node* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct Node* result = NULL;
    if (list1->data <= list2->data) {
        result = list1;
        result->next = merge(list1->next, list2);
    } else {
        result = list2;
        result->next = merge(list1, list2->next);
    }

    return result;
}

void freeList(struct Node** head) {
    struct Node* current = *head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

int main() {
    struct Node* head = NULL;

    insertatbegin(&head, 10);
    insertatend(&head, 20);
    insertatend(&head, 30);
    insertatbegin(&head, 5);

    displayList(head);

    deleteNode(&head, 20);

    displayList(head);

    freeList(&head);

    return 0;
}

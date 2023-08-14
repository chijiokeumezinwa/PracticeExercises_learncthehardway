#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct treeNode{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *createNode(int data){
    struct treeNode *newNode = (struct treeNode*) malloc(sizeof(struct treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//write function to insert nodes into the binary tree while maintaining the binary search property
void *insert(struct treeNode **root, int data){
    if(*root == NULL){
        *root= createNode(data);
        return;
    }

    if(data < (*root)->data){
        insert(&(*root)->left,data);
    }
    else{
        insert(&(*root)->right, data);
    }

}

int search(struct treeNode *root, int key){
    if(root == NULL){
        return 0;
    }

    if(root->data == key){
        return 1;
    }
    else if(target < root->data){
        return search(root->left, target);
    }
    else{
        return search(root->right, target);
    }
}

void inorderTraversal(struct treeNode *root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct treeNode *root){
    if(root != NULL){
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct treeNode *root){
    if(root != NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    struct treeNode *root = NULL;

    root = insert(&root, 50);
    root = insert(&root, 30);
    root = insert(&root, 70);
    root = insert(&root, 20);
    root = insert(&root, 40);
    root = insert(&root, 60);
    root = insert(&root, 80);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
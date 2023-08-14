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

int getHeight(struct treeNode *root){
    if(root == NULL){
        return -1;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight:rightHeight);
}

int getDepth(struct treeNode *root, int key, int depth){
    if(root == NULL){
        return -1;
    }

    if(root->data == key){
        return depth;
    }

    int leftDepth = getDepth(root->left, key, depth + 1);
    if(leftDepth != -1){
        return leftDepth;
    }
    return getDepth(root->right, key, depth + 1);
}

int countNodes(struct treeNode *root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

struct treeNode *findMin(struct treeNode *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct treeNode *findMax(struct treeNode *root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct treeNode *deleteNode(struct treeNode *root, int data){
    if(root == NULL){
        return root;
    }

    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else{
        //node with only a right child
        if(root->left == NULL){
            struct treeNode *temp = root->right;
            free(root);
            return temp;
        }
        //node with only a left child
        else if(root->right == NULL){
            struct treeNode *temp = root->left;
            free(root);
            return temp;
        }

        //node with two children, get the inorder successor or smallest in right subtree
        struct treeNode *temp = findMin(root->right);

        //copy the inorder successor's data to root node
        root->data= temp->data;

        //delete in order successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
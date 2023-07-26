#include<stdio.h>
long addTwoNumbers(long *, long*);


int main(int argc, char *argv[]){
    long firstnum, secondnum, sum;
    printf("\n\n Pointer: Add two numbers using call by reference");
    printf("------------------------------------\n");

    printf("Input the first number: ");
    scanf("%ld",&firstnum);
    printf("Input the second number: ");
    scanf("%ld", &secondnum);
    sum = addTwoNumbers(&firstnum, &secondnum);
    
    
    int arr1[25], i , n;
    printf("\n\nPointer: Store and retrieve elements from an array:\n");
    printf("------------------------------------\n");
    printf("Input the number of elements to store in the array:");
    scanf("%d",&n);
    printf("Input %d number of elements in the array: \n",n);

    for(i=0;i<n;i++){
        printf("element - %d: ",i);
        scanf("%d",arr1+i);
    }
    printf("The elements you entered are: \n");
    for(i = 0; i<n; i++){
        printf("element - %d: %d \n",i,*(arr1+i));
    }

    char str1[50];
    char revstr[50];

    char *stptr=str1;
    char *rvptr = revstr;
    return 0;
}

long addTwoNumbers(long *n1, long *n2){
    long sum;
    sum= *n1 + *n2;
    return sum;
}
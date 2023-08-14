#include <stdio.h>
#include <stdlib.h>

struct maxHeap{
    int *arr;
    int size;
    int capacity;
};

struct minHeap{
    int *arr;
    int size;
    int capacity;
};

struct maxHeap *createMaxHeap(int capacity){
    struct maxHeap *heap = (struct maxHeap*) malloc(sizeof(struct maxHeap));
    if(heap == NULL){
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    heap->capacity = capacity;
    heap->size =0;
    heap->arr = (int *) malloc(capacity * sizeof(int));

    if(heap->arr == NULL){
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return heap;
}

struct minHeap *createMinHeap(int capacity){
    struct minHeap *heap = (struct minHeap*) malloc(sizeof(struct minHeap));
    if(heap == NULL){
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    heap->capacity = capacity;
    heap->size =0;
    heap->arr = (int *) malloc(capacity * sizeof(int));

    if(heap->arr == NULL){
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return heap;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to heapify (max heapify) a subtree rooted at index i
void maxHeapify(struct maxHeap *heap, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < heap->size && heap->arr[left] > heap->arr[largest]){
        largest = left;
    }

    if(right < heap->size && heap->arr[right] > heap->arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(&heap->arr[i], &heap->arr[largest]);
        maxHeapify(heap, largest);
    }
}

void minHeapify(struct minHeap *heap, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < heap->size && heap->arr[left] < heap->arr[smallest]){
        smallest = left;
    }

    if(right < heap->size && heap->arr[right] < heap->arr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(&heap->arr[i], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

void insertMax(struct maxHeap *heap, int data){
    if(heap->size == heap->capacity){
        perror("Heap is full");
        return;
    }

    int i = heap->size;
    heap->arr[i] = data;
    heap->size++;

    while(i > 0 && heap->arr[(i - 1) / 2] < heap->arr[i]){
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insertMin(struct minHeap *heap, int data){
    if(heap->size == heap->capacity){
        perror("Heap is full");
        return;
    }

    int i = heap->size;
    heap->arr[i] = data;
    heap->size++;

    while(i > 0 && heap->arr[(i - 1) / 2] > heap->arr[i]){
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(struct maxHeap *heap){
    if(heap->size == 0){
        perror("Heap is empty");
        exit(EXIT_FAILURE);
    }

    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    maxHeapify(heap,0);
    return max;
}

int extractMin(struct minHeap *heap){
    if(heap->size == 0){
        perror("Heap is empty");
        exit(EXIT_FAILURE);
    }

    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    minHeapify(heap,0);
    return min;
}

void display(struct minHeap *heap){
    for(int i = 0; i < heap->size; i++){
        printf("%d ", heap->arr[i]);
    }
    printf("\n")l;
}

void freeHeap(struct minHeap* heap){
    free(heap->arr);
    free(heap);
}
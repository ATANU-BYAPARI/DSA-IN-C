//implementation of linear queue, enqueue, dequeue, isFull, isEmpty
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct queue{
    int size;
    int front; 
    int rear;
    int *arr;
};
//isFull function
int isFull(struct queue* q){
if(q->rear>=q->size-1){
    return 1;
}
else{
    return 0;
}
}
//isEmpty function
int isEmpty(struct queue *q){
if(q->rear==q->front){
    return 1;
}
else{
    return 0;
}
}
//dequeue function
int dequeue(struct queue *q){
if(isEmpty(q)){
    printf("The queue is empty!\n");
    return INT_MIN;
}
else{
    q->front++;
    return q->arr[q->front];
}
}
//enqueue function
void enqueue(struct queue *q,int val){
if(isFull(q)){
printf("The queue is full!\n");
}
else{
q->rear++;
q->arr[q->rear]=val;
}
}
//print_queue element function
void print_queue(struct queue* q){
    if(isEmpty(q)){
        printf("No elements are present in the queue!\n");
    }
    else{
        int idx_var=q->front+1;
        while(idx_var<=q->rear){
            printf("Element: %d\n",q->arr[idx_var]);
            idx_var++;
        }
    }
}
//main function
int main(){
    struct queue q;
    q.size=100;
    q.front=q.rear=-1;
    q.arr=(int*)malloc(q.size*(sizeof(int)));

    //enqueue
    enqueue(&q,5);
    enqueue(&q,8);
    enqueue(&q,9);
    enqueue(&q,76);
    enqueue(&q,79);
    enqueue(&q,71);

    //print the elements in the queue
    printf("Elements currently present inside the queue are: \n");
    print_queue(&q);
    //dequeue
    int removed=dequeue(&q);
    printf("The removed element is: %d\n",removed);

    free(q.arr);
    return 0;
}
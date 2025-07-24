// circular increment i=(i+1)%size_of_array
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int front;
    int rear;
    int *array;
    int size;
};
// is Full function
int isFull(struct queue *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// is Empty function
int isEmpty(struct queue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// peek function
void peek(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is empty!\n");
        return;
    }
    else
    {
        int store = q->front;
        while (store != q->rear)
        {
            store = (store + 1) % q->size;
            printf("Data: %d\n", q->array[store]);
        }
        return;
    }
}
// enqueue function
void enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("The queue is full!\n");
        return;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->array[q->rear] = data;
        return;
    }
}
// dequeue function
void dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue has no element!\n");
        return;
    }
    else
    {
        q->front = ((q->front) + 1) % q->size;
        printf("The removed element from queue is: %d\n", q->array[q->front]);
        return;
    }
}
int main()
{
    int size;
    printf("Enter your queue size: ");
    scanf("%d", &size);
    struct queue q;
    q.front = -1;
    q.rear = -1;
    q.size = size+1;

    q.array = (int *)malloc(q.size * sizeof(int));
    // below all cases are designed assuming the queue size is 3
    enqueue(&q, 10);
    enqueue(&q, 20);
    dequeue(&q); // removes 10
    dequeue(&q); // removes 20, queue empty now

    dequeue(&q); // again, dequeue on empty queue
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50); // should be full now
    enqueue(&q, 60); // should print "The queue is full!"
    peek(&q);
    free(q.array);
}
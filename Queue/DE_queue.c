// DE queue, double ended queue: both insertion and deletion can be done from both end i.e. front and rear end
//   restricted input DE queue: Elements can't be added from front end
//   restricted output DE queue: Elements can't be deleted from rear end
// In circular queue if queue size is n then we can add only n-1 elements in it : *me
#include <stdio.h>
#include <stdlib.h>
struct DE_queue
{
    int size;
    int *array;
    int front;
    int rear;
};
int isEmpty(struct DE_queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void peek(struct DE_queue *q)
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
            printf("data: %d\n", q->array[store]);
            store = (store + 1) % q->size;
        }
        return;
    }
}
int isFull(struct DE_queue *q)
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
void enqueue_rear(struct DE_queue *q, int data)
{
    if (isFull(q))
    {
        printf("The queue is full!\n");
        return;
    }
    else
    {
        q->array[q->rear] = data;
        q->rear = (q->rear + 1) % q->size;
        return;
    }
}
void enqueue_front(struct DE_queue *q, int data)
{
    if (isFull(q))
    {
        printf("The queue is full!\n");
        return;
    }
    else
    {
        q->front = (q->front - 1 + q->size) % q->size;
        q->array[q->front] = data;
        return;
    }
}
void dequeue_front(struct DE_queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is Empty!\n");
        return;
    }
    else
    {
        printf("Data removed from front end is: %d\n", q->array[q->front]);
        q->front = (q->front + 1) % q->size;
        return;
    }
}
void dequeue_rear(struct DE_queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is Empty!\n");
        return;
    }
    else
    {
        q->rear = (q->rear - 1 + q->size) % q->size;
        printf("Data removed from rear end is: %d\n", q->array[q->rear]);
        return;
    }
}
int main()
{
    int size;
    printf("Enter the size of queue: \n");
    scanf("%d", &size);
    // just checking... user entered a positive and valid size of queue
    if (size <= 0)
    {
        printf("Invalid queue size!\n");
        exit(1);
    }

    struct DE_queue q;
    q.front = q.rear = 0; // we can initialize it with -1, i tried it too... but it is much complexer implementation, so, follow the trend and initialize it with 0
    q.size = size + 1;
    q.array = (int *)malloc(q.size * sizeof(int)); // *me: so i allocated +1 size of actual size

    enqueue_rear(&q, 9);

    enqueue_front(&q, 0);

    enqueue_front(&q, 8);

    enqueue_front(&q, 7);

    enqueue_rear(&q, 1);

    enqueue_rear(&q, 2);

    enqueue_rear(&q, 3);

    dequeue_front(&q);

    dequeue_rear(&q);

    dequeue_rear(&q);

    dequeue_rear(&q);

    dequeue_front(&q);

    dequeue_front(&q);

    peek(&q);

    free(q.array);
    return 0;
}
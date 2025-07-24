#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int data;
    struct queue *next;
};
int isEmpty(struct queue *head)
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void peek(struct queue *head)
{
    struct queue *new = head;
    while (new != NULL)
    {
        printf("data: %d\n", new->data);
        new = new->next;
    }
}
struct queue *enqueue(struct queue *head, int data)
{
    struct queue *store = head;
    struct queue *new = (struct queue *)malloc(sizeof(struct queue));
    new->data = data;
    new->next = store;
    return new;
}
struct queue* dequeue(struct queue *head)
{
    if (isEmpty(head))
    {
        printf("The queue is Empty!\n");
        return NULL;
    }
    if (head->next == NULL)
    {
        printf("Removed data: %d\n", head->data);
        free(head);
        return NULL;
    }
    else
    {
        struct queue *store = head;
        while (store->next->next != NULL)
        {
            store = store->next;
        }
        printf("Removed data: %d\n", store->next->data);
        free(store->next);
        store->next = NULL;
        return head;
    }
}
int main()
{
    struct queue *s = NULL;

    //adding elements in queue
    s = enqueue(s, 8);
    s = enqueue(s, 9);
    s = enqueue(s, 0);
    s = enqueue(s, 1);
    s = enqueue(s, 2);
    s = enqueue(s, 3);

    // removing elements from queue
    s = dequeue(s);
    s = dequeue(s);
    s = dequeue(s);
    peek(s);
}
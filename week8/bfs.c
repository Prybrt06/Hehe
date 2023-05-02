#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
} Queue;

struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity - 1;
    queue->array = (int *)malloc(
        queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

int rear(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

int main()
{
    int arr[8][8];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            arr[i][j] = 0;
        }
    }

    Queue *q = createQueue(1000);

    arr[1][2] = 8;
    arr[1][3] = 1;
    arr[2][3] = 2;
    arr[3][4] = 3;
    arr[2][4] = 4;
    arr[2][5] = 6;
    arr[2][6] = 10;
    arr[4][6] = 8;
    arr[5][6] = 7;
    arr[7][6] = 6;

    enqueue(q, 1);

    int visited[8];

    for (int i = 0; i < 8; i++)
    {
        visited[i] = 0;
    }

    int ans[8];
    int j = 0;

    while (!isEmpty(q))
    {
        int f = front(q);

        for (int i = 1; i < 8; i++)
        {
            if (arr[f][i] == 0)
            {
                continue;
            }

            else
            {
                if (visited[i] == 0)
                {
                    enqueue(q, i);
                    visited[i] = 1;
                }
            }
        }

        visited[f] = 1;
        ans[j++] = f;
        dequeue(q);
    }

    for (int i = 0; i < 8; i++)
    {
        if (ans[i] == 0)
            continue;

        if (ans[i] == 1)
        {
            printf("c ");
        }

        else if (ans[i] == 2)
        {
            printf("a ");
        }

        else if (ans[i] == 3)
        {
            printf("b ");
        }

        else if (ans[i] == 4)
        {
            printf("d ");
        }

        else if (ans[i] == 5)
        {
            printf("e ");
        }

        else if (ans[i] == 6)
        {
            printf("f ");
        }

        else
        {
            printf("g ");
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	int *arr;
	int front, count;
	int size;
} Queue;

Queue *newQueue()
{
	Queue *q = (Queue *)malloc(sizeof(Queue));
	q->front = q->count = 0;
	q->size = 2;
	q->arr = (int *)malloc(sizeof(int) * q->size);
	return q;
}

void resize(Queue *q)
{
	int *tmp = q->arr, s1 = q->size;
	q->size = q->count * 2 + 1;
	q->arr = (int *)malloc(sizeof(int) * q->size);
	for (int i = 0; i < q->count; i++)
	{
		q->arr[i] = tmp[(q->front + i) % s1];
	}
	free(tmp);
	q->front = 0;
}

int isEmpty(Queue *q)
{
	return q->count == 0;
}

void enqueue(Queue *q, int data)
{
	if (q->count >= q->size)
		resize(q);
	q->arr[(q->front + q->count++) % q->size] = data;
}

int dequeue(Queue *q)
{
	if (isEmpty(q))
		return -1;
	if (q->count <= q->size / 4)
		resize(q);
	int ret = q->arr[q->front++ % q->size];
	q->count--;
	return ret;
}

int main()
{
	Queue *q = newQueue();

	int arr[15] = {0}, i = 0;
	enqueue(q, 1);
	enqueue(q, 2);
	arr[i++] = dequeue(q);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);
	enqueue(q, 6);
	enqueue(q, 7);
	enqueue(q, 8);
	enqueue(q, 9);
	enqueue(q, 10);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);
	arr[i++] = dequeue(q);

	for (int j = 0; j < 15; j++)
	{
		printf("%d\n", arr[j]);
	}

	free(q);
}

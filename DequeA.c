#include <stdio.h>
#include <stdlib.h>

typedef struct Deque
{
	int *arr;
	int front, count;
	int size;
} Deque;

int modulo(int n, int m)
{
	int r = n % m;
	if (r < 0)
		r += m;
	return r;
}

Deque *newDeque()
{
	Deque *d = (Deque *)malloc(sizeof(Deque));

	d->size = 2;
	d->count = d->front = 0;
	d->arr = (int *)malloc(sizeof(int) * d->size);

	return d;
}

void resize(Deque *d)
{
	int *tmp = d->arr, s1 = d->size;
	d->size = d->count * 2 + 1;
	d->arr = (int *)malloc(sizeof(int) * d->size);
	for (int i = 0; i < d->count; i++)
	{
		d->arr[i] = tmp[modulo(d->front + i, s1)];
	}
	free(tmp);
	d->front = 0;
}

int isEmpty(Deque *d)
{
	return d->count == 0;
}

void addFirst(Deque *d, int data)
{
	if (d->count >= d->size)
		resize(d);
	d->arr[modulo(--d->front, d->size)] = data;
	d->count++;
}

void addLast(Deque *d, int data)
{
	if (d->count >= d->size)
		resize(d);
	d->arr[(d->front + d->count++) % d->size] = data;
}

int removeFirst(Deque *d)
{
	if (isEmpty(d))
	{
		return -1;
	}

	if (d->count <= d->size / 4)
		resize(d);

	int ret = d->arr[d->front++ % d->size];
	d->count--;
	return ret;
}

int removeLast(Deque *d)
{
	if (isEmpty(d))
	{
		return -1;
	}

	if (d->count <= d->size / 4)
		resize(d);
	int ret = d->arr[(d->front + --d->count) % d->size];
	return ret;
}

int main()
{
	Deque *d = newDeque();

	int arr[10] = {0}, i = 0;

	addFirst(d, 1);
	addFirst(d, 2);
	addFirst(d, 3);
	addFirst(d, 4);
	addLast(d, 5);
	addLast(d, 6);
	addLast(d, 7);
	addLast(d, 8);
	addLast(d, 9);
	addLast(d, 10);

	arr[i++] = removeLast(d);
	arr[i++] = removeFirst(d);
	arr[i++] = removeLast(d);
	arr[i++] = removeFirst(d);
	arr[i++] = removeLast(d);
	arr[i++] = removeFirst(d);
	arr[i++] = removeLast(d);
	arr[i++] = removeFirst(d);
	arr[i++] = removeLast(d);
	arr[i++] = removeFirst(d);

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
}
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Enqueue an element in the queue
 * @param q       pointer to the queue
 * @param element pointer to the element to enqueue
 */
void enqueue (Queue* q, void* element)
{
	QueueElement *queueEl = (QueueElement *) malloc(sizeof(QueueElement));
	queueEl->item = element;
	queueEl->next = NULL;
	if (q->tail == NULL)
	{
		q->tail = queueEl;
		q->head = queueEl;
	}
	else
	{
		q->tail->next = queueEl;
		q->tail = queueEl;
	}
}

/**
 * Dequeue an element, i.e. remove and return the head of the queue
 * @param q pointer to the queue
 */
void* dequeue (Queue* q)
{
	if (q->head == NULL)
	{
		return NULL;
	}
	else
	{
		QueueElement* element = q->head;
		q->head = element->next;
		return element->item;
	}
}

int main(int argc, char const *argv[])
{
	Queue q;
	char string1[50] = "(char*) malloc(5*sizeof(char));";
	char string2[90] = "(char*) malloc(10*sizeof(char))";
	char test[50] = "blop";
	// printf("%s\n", test);
	enqueue(&q, (void*) string1);
	enqueue(&q, (void*) string2);
	enqueue(&q, (void*)test);
	printf("%s\n", (char*) dequeue(&q));
	printf("%s\n", (char*) dequeue(&q));
	printf("%s\n", (char*) dequeue(&q));
	// char* blop = (char*) dequeue(&q);
	return 0;
}

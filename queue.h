typedef struct queue_element
{
	void* item;
	queue_element* next;
} QueueElement;

typedef struct {
	QueueElement* head;
	QueueElement* tail;
} Queue;

void enqueue (Queue* q, void* element);

void* dequeue (Queue* q);
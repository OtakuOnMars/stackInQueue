#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/queue.h>

typedef struct q_item {
	int value;
	TAILQ_ENTRY(q_item) entries;
	TAILQ_HEAD(, q_item) head;
} q_item;


void enqueue(int value, q_item *q) {
	q_item *item;
	item = malloc(sizeof(q_item));
	item->value = value;
	printf("Queued value : %d\n", item->value);
	TAILQ_INSERT_HEAD(&q->head, item, entries);
	printf("inster to head for stack\n");
}

void dequeue(q_item *q) {
	q_item *remove_item;
	remove_item = TAILQ_FIRST(&q->head);
	printf("stack value : %d\n", remove_item->value);
	TAILQ_REMOVE(&q->head, remove_item, entries);
	free(remove_item);
}

int main (int argc, const char *argv[]) {
	q_item q;
	TAILQ_INIT(&q.head);

	enqueue(1, &q);
	enqueue(2, &q);	
	enqueue(3, &q);
	enqueue(4, &q);

	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	printf("test in main for queue\n");
	return 0;
}

#ifndef __LinkedList__
#define __LinkedList__
#endif

#ifdef DEBUG
#define dprint(x) (fprintf(stderr, "DEBUG: %s",x))
#else
#define dprint(x)
#endif

typedef void *value;

typedef struct node{
	value *x;
	struct node *next;
	struct node *prev;
} Node;

typedef struct {
	struct node *first;
	struct node *last;
	int length;
} LinkedList;

LinkedList *newList();

void push(LinkedList *list, value *val);
Node *pop(LinkedList *list);

void queue(LinkedList *list, value *val);
Node *dequeue(LinkedList *list);

int removeElement(LinkedList *list, Node *node);

int quickRemoveElement(LinkedList *list, Node *node);

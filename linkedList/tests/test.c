#include "../linkedList.h"
#include <assert.h>
#include <stdio.h>

int testCreate(){
	LinkedList *list = newList();
	assert(list->first == NULL);
	assert(list->last == NULL);
	assert(list->length == 0);
	return 1;
}

int testPush(LinkedList *list){
	int len = list->length;
	int a = 5;
	int x = 5;
	push(list, &a);
	assert(list->length == len + 1);
	assert(list->first->x == &a);
	assert((int)*list->first->x == a);
	push(list, &x);
	assert(list->first->next->prev == list->first);
	return 1;
}

int testQueue(LinkedList *list){
	int len = list->length;
	int a = 1;
	int x = 5;
	queue(list, &a);
	assert(list->length = len + 1);
	assert(list->last->x == &a);
	assert((int)*list->last->x == a);
	push(list, &x);
	assert(list->last->prev->next = list->last);
	return 1;
}

int testPopNonEmpty(LinkedList *list){
	int len = list->length;
	Node *first = list->first;
	Node *n = pop(list);
	assert(list->length == len - 1);
	assert(first == n);
	assert(list->first != first);
	assert(list->first->prev == NULL);
	return 1;
}

int testPopEmpty(){
	LinkedList *list = newList();
	Node *n = pop(list);
	assert(list->length == 0);
	assert(n==NULL);
	return 1;
}

int testDequeueNonEmpty(LinkedList *list){
	int len = list->length;
	Node *first = list->first;
	Node *n = dequeue(list);
	assert(list->length == len - 1);
	assert(first == n);
	assert(list->first != first);
	assert(list->first->prev == NULL);
	return 1;
}

int testDequeueEmpty(){
	LinkedList *list = newList();
	Node *n = dequeue(list);
	assert(list->length == 0);
	assert(n==NULL);
	return 1;
}

int testAddMany(LinkedList *list){
	int len = list->length;
	for(int i=0; i<10000; i++){
		push(list, &i);
	}
	assert(list->length = len + 10000);
	return 1;
}

testIterateThrough(LinkedList *list){
	int len = list->length;
	Node *current = list->first;
	int i = 0;
	while(current != NULL){
		i++;
		current = current->next;
	}
	assert(len == i);
	return 1;
} 

int testRemove(LinkedList *list){
	int a = 1;
	int b = 2;
	int c  = 3;
	push(list,&a);
	Node *na = list->first;
	push(list,&b);
	Node *nb = list->first;
	push(list,&c);
	Node *nc = list->first;

	int len = list->length;
	removeElement(list, nb);
	assert(list->length == len - 1);
	assert(na->prev == nc);
	assert(nc->next == na);
	int res = removeElement(list, nb); //remove element not in list should not do anything and return 0
	assert(res == 0);
	assert(list->length == len - 1);
	assert(na->prev == nc);
	assert(nc->next == na);

	return 1;
}


int testRemoveAll(LinkedList *list){
	while(removeElement(list,list->first)){
		//just remove and don't do anything
	}
	assert(list->length == 0);
	assert(list->first == NULL);
	assert(list->last == NULL);
	return 1;
}

int main(){
	assert(testCreate());
	LinkedList *list = newList();
	assert(testPush(list));
	assert(testQueue(list));
	assert(testPopNonEmpty(list));
	assert(testPopEmpty());
	assert(testDequeueNonEmpty(list));
	assert(testDequeueEmpty());
	assert(testAddMany(list));
	assert(testIterateThrough(list));
	assert(testRemove(list));
	assert(testRemoveAll(list));
	printf("all tests passed");
}

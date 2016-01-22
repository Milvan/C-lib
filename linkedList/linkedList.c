#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void addToEmpty(LinkedList *list, Node *newNode){
	list->first = newNode;
	list->last = newNode;
}

Node *createNode(value *val){
	Node *newNode = malloc(sizeof(Node));
	newNode->x = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void removeFirst(LinkedList *list){
	Node *n = list->first;
	if(list->length == 1){
		list->first = NULL;
		list->last = NULL;
	} else if(list->length == 2){
		list->first = list->last;
		list->last->prev = NULL;
	}else{
		list->first = list->first->next;
		list->first->prev = NULL;
	}
	list->length--;
	free(n);
}

void removeLast(LinkedList *list){
	Node *n = list->last;
	if(list->length == 1){
		list->first = NULL;
		list->last = NULL;
	} else if(list->length == 2){
		list->last = list->first;
		list->first->next = NULL;
	}else{
		list->last = list->last->prev;
		list->last->next = NULL;
	}
	list->length--;
	free(n);
}

/* Checks if node is first or last element and 
 * removes it if it is.
 * list must be a non-empty list
 */
int firstOrLastRemove(LinkedList *list, Node *node){
	if(list->first == node){
		removeFirst(list);
		return 1;
	}else if(list->last == node){
		removeLast(list);
		return 1;
	}
	return 0;
}

void push(LinkedList *list, value *val){
	Node *newNode = createNode(val);

	if(list->length){
		list->first->prev = newNode;
		newNode->next = list->first;
		list->first = newNode;
	}else{
		addToEmpty(list, newNode);
	}
	list->length++;
}

void queue(LinkedList *list, value *val){
	Node *newNode = createNode(val);
	if(list->length){
		list->last->next = newNode;
		newNode->prev = list->last;
		list->last = newNode;
	}else{
		addToEmpty(list,newNode);
	}
	list->length++;
}

Node *pop(LinkedList *list){
	Node *n = list->first;
	removeFirst(list);
	return n;
}

Node *dequeue(LinkedList *list){
	Node *n = list->first;
	removeLast(list);
	return n;
}

/* Safely removes node from the specified list in O(n) time.
 * returns 0 if element was not int list
 * returns 1 if element was in list and now removed
 */
int removeElement(LinkedList *list, Node *node){
	if(list->length){
		Node *current = list->first;
		while(current){
			if(current==node){
				return quickRemoveElement(list,node);
			}
			current = current->next;	
		}
		return 0;
	}
	return 0;
}

/*
 * Use this function if you're sure that the node is in the list.
 * This just changes the pointers of node and maintains the properties of the list in O(1)
 * returns 0 if list is empty, otherwise 1.
 */
int quickRemoveElement(LinkedList *list, Node *node){
	if(list->length){
		if(list->first==node){
			removeFirst(list);
		}else if(list->last == node){
			removeLast(list);
		}else{
			node->prev->next = node->next;
			node->next->prev = node->prev;
			list->length--;
		}
		return 1;
	}
	return 0;
}

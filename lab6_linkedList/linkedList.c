#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define VALUESIZE 100
#define SWAP(a,b) a^=b;b^=a;a^=b;

typedef struct LinkedListItem{
	int id, value;
	struct LinkedListItem * nextItem;
}ListItem;

typedef void (*NodeFunction)(ListItem *);

void* getLastItem();
void* getPreviousNode(ListItem * targetNode);
void* addListItem(ListItem * node);
void* pushItem();
void listAppend(int count);
void listDisplay();
void forEach(NodeFunction forNode);
void displayNode(ListItem * node);
void swapNodes(ListItem * node1, ListItem * node2);
void swapMinMax();

int idCounter = 0;
ListItem * head;

int main(){	//	main. Even in Africa it's main
	srand(time(NULL));
	head = (ListItem *)malloc(sizeof(ListItem));
	head->nextItem = NULL;
	head->id = idCounter++;
	head->value = rand() % VALUESIZE;
	//====================	initialized, ready to roll
	listAppend(9);
	listDisplay();
	printf("Swapping minimal and maximal nodes by Value\n\r");
	swapMinMax();
	listDisplay();
	return 0;
}

void* getLastItem(){	//	iterate through array to find last item
	ListItem * currentItem = head;
	while (currentItem->nextItem != NULL){
		 currentItem = currentItem->nextItem;
	}
	return currentItem;
}

void* getPreviousNode(ListItem * targetNode){
	if (targetNode == head)
	{
		return NULL;
	}
	ListItem * currentItem = head;
	while(currentItem->nextItem != targetNode){
		currentItem = currentItem->nextItem;
	}
	return currentItem;
}

void* addListItem(ListItem * node){	//	Adding to the Linked List
	ListItem * newNode = (ListItem*)malloc(sizeof(ListItem));
	newNode->nextItem = node->nextItem;
	node->nextItem = newNode;
	newNode->id = idCounter++;
	newNode->value = rand() % VALUESIZE;
	return newNode;
}

void* pushItem(){
	ListItem * newNode = (ListItem*)malloc(sizeof(ListItem));
	newNode->nextItem = head;
	newNode->id = idCounter++;
	newNode->value = rand() % VALUESIZE;
	head = newNode;
	return newNode;
}

void listAppend(int count){	//	adding specified amount of new items to end of the list
	ListItem * currentItem;
	for (int i = 0; i <= count; i++){
		currentItem = (ListItem *)getLastItem(head);
		addListItem(currentItem);
	}
	return;
}

void forEach(NodeFunction forNode){
	ListItem * currentItem = head;
	while(currentItem != NULL){
		forNode(currentItem);
		currentItem = currentItem->nextItem;
	}
}

void listDisplay(){
	forEach(displayNode);
}

void displayNode(ListItem * node){
	printf("%d\t%d\n\r",node->id, node->value);
	return;
}

void swapNodes(ListItem * node1, ListItem * node2){
	ListItem * tmp = getPreviousNode(node1),* new1,* new2;
	if (tmp == NULL){
		new1 = (ListItem *) pushItem();
	}else{
		new1 = (ListItem *) addListItem(tmp);
	}
	new1->value = node2->value; new1->nextItem = node1->nextItem;

	tmp = getPreviousNode(node2);
	if (tmp == NULL){
		new2 = (ListItem *) pushItem();
	}else{
		new2 = (ListItem *) addListItem(tmp);
	}
	new2->value = node1->value; new2->nextItem = node2->nextItem;
	free(node1); free(node2);
	return;
}

void swapMinMax(){
	ListItem * currentItem = head->nextItem, * minItem = head, * maxItem = head;
	while(currentItem != NULL){
		if (currentItem->value < minItem->value){minItem = currentItem;}
		if (currentItem->value > maxItem->value){maxItem = currentItem;}
		currentItem = currentItem->nextItem;
	}
	printf("Swapped nodes with ID's %d and %d\n\r", minItem->id, maxItem->id);
	swapNodes(minItem, maxItem);
	return;
}

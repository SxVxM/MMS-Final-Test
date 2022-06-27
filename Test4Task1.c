//Test 4 Task 1 by Stefan Markovski

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define COUNT 10

typedef struct node {
    int data;
    struct node* next;
} node_t;

int minPrice(node_t *start)
{
	int min = start->data;
	while(start!=NULL)
	{
		if(start->data < min){
            min = start->data;
        }
		start=start->next;
	}
	return min;
}

void listFree(node_t** list){
    node_t *current = *list, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

void push(node_t** list, int data){
    node_t* n = malloc(sizeof(node_t));
    n->data = data;
    n->next = *list;
    *list = n;
}

void print(node_t* llist){
    while (llist){
        printf("%d\n", llist->data);
        llist = llist->next;
    }
    putchar('\n');
}

typedef struct Items{
    char desc[20];
    int num;
    double weight;
    double price;
} Items;

double totalItemsWeight(node_t* items){
    double sum = 0;
    node_t* temp = items;
    while(temp != NULL){
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}
void printItems(Items i){
    printf("Description: %25s ", i.desc);
    printf("Number: %d ", i.num);
    printf("Weight: %4lf ", i.weight);
    printf("Price: %4.2lf\n", i.price);
}

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

char* randomName(char* name){
    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = randint(5, 10);
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }
    name[index] = '\0';
    return name;
}

int compareDescASC(const void* i1, const void* i2){
    Items* item1 = (Items*)i1;
    Items* item2 = (Items*)i2;
    return strcmp(item1->desc, item2->desc);
}

int main(){
    srand(time(NULL));
    Items items[COUNT]; 
    node_t* head1 = NULL;
    node_t* head2 = NULL;
    for(int i = 0; i < COUNT; i++){
        randomName(items[i].desc);
        items[i].num = randint(100, 300);
        items[i].weight = randReal(0.10, 100.00);
        items[i].price = randReal(1.0, 1500.0);
    }

    qsort(items, COUNT, sizeof(items[0]), compareDescASC);
    printf("List of items: \n\n");
    for(int i = 0; i < COUNT; i++){
        printItems(items[i]);
        push(&head1, items[i].weight);
        push(&head2, items[i].price);
    }
    printf("\nTotal weight: %.2lf\n", totalItemsWeight(head1));
    printf("\nMin price: %d\n", minPrice(head2));
    listFree(&head1);
    return 0;
}

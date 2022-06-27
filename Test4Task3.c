#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

void push(node_t** list, int data){
    node_t* n = malloc(sizeof(node_t));
    n->data = data;
    n->next = *list;
    *list = n;
}
void print(node_t* llist){
    while (llist){
        printf("%d ", llist->data);
        llist = llist->next;
    }
    putchar('\n');
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
int randint(int min, int max){
    return min + rand() % (max - min + 1);
}
void *routine(void* arg){
    sleep(1);
}
int main(int argc, char **argv){
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    if(N <= 0 || M <= 0){
        fprintf(stderr, "Invalid number!\n");
        return EXIT_FAILURE;
    }else{
        node_t* head = NULL;
        srand(time(NULL));
        pthread_t pth[N];

        for (int i = 0; i < N; i++){
            if(pthread_create(&pth[i], NULL, routine, NULL)){
                perror("create");
                exit(EXIT_FAILURE);
            }
        }
        for (int i = 0; i < N; i++){
            if(pthread_join(pth[i], NULL)){
                perror("join");
                exit(EXIT_FAILURE);
            }
        }
        for(int i = 0; i < N; i++){
            for(int i = 0; i < M; i++){
                push(&head, randint(-99, 99));
            }   
            printf("ROW %d: ", i+1);
            print(head);
            listFree(&head);
        }
        return EXIT_SUCCESS;
    }
}
/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

void printElement(int *elem) {
    printf("%d ", *elem);
}

void forEachElement(Stack *list, void (*func)(int *elem)){
    StackNode *temp = list -> _top;
    
    func(&(temp->data)); //func the first node
    while(temp->next != NULL){
        temp = temp->next;
        func(&(temp->data));
    }

}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;

    // PENTING! Jangan lupa diinisialisasi
    stack_init(&myStack);

    int T, P;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%d", &P);
        int *Q = (int*) malloc(sizeof(int) * P);
        for(int j=0; j<P; j++){
            scanf("%d", Q+j);
        }
        for(int j=0; j<P; j++){
            if(Q[j] <= stack_top(&myStack) || stack_isEmpty(&myStack)){
                stack_push(&myStack, Q[j]);
            } else{
                while(Q[j]>stack_top(&myStack) && myStack._top!=NULL){
                    stack_pop(&myStack);
                }
                stack_push(&myStack, Q[j]);
            }
        }
        int size = myStack._size, arr[myStack._size];
        for(int i = size-1; i>=0; i--){
            arr[i]=myStack._top->data;
            stack_pop(&myStack);
        }
        printf("Susunan blok yang disusun Nadut dan Cayo adalah : ");
        for(int i = 0; i<size; i++){
            printf("%d", arr[i]);
            if(i<size-1){
                printf(" ");
            }
        }
        //forEachElement(&myStack, printElement);
        printf("\n");
    }
    // Operasi pada stack

    puts("");
    return 0;
}
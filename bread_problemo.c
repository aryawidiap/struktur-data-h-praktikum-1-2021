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

void stack_initialise(Stack *stack, int size){
    for(int i=size; i>=1; i--){
        stack_push(stack, i);
    }
}

void moveStack(Stack *_destination, Stack *_source){
    if(!stack_isEmpty(_source)){
        stack_push(_destination, stack_top(_source));
        stack_pop(_source);
        return;
    }
    
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack Ray, Kakak;
    int N, T, Ai, Bi;
    // PENTING! Jangan lupa diinisialisasi
    stack_init(&Ray);
    stack_init(&Kakak);

    // Operasi pada stack
    /* Get input : 
        Jumlah Roti (N) -> banyak anggota stack
        Jumlah ibu dapat memindah roti/iterasi (T)
    */
    scanf("%d", &N);
    if(N==0){
        printf("Ray SangaT MaraH!\n");
        return 0;
    }
    scanf("%d", &T);
    stack_initialise(&Ray, N);
    for(int i=0; i < T; i++){
        scanf("%d", &Ai);
        if(Ai==1){
            scanf("%d", &Bi);
            //printf("Ai: %d; Bi: %d\n", Ai, Bi);
            for(int j=0; j<Bi; j++){
                moveStack(&Kakak, &Ray);
            }
        } else if(Ai==2){
            scanf("%d", &Bi);
            //printf("Ai: %d; Bi: %d\n", Ai, Bi);
            for(int j=0; j<Bi; j++){
                moveStack(&Ray, &Kakak);
            }
        } else {
            printf("TumpukAnnya saLah! :(\n");
            return 0;
        }
    }

    // cetak isi stack
    /*if(stack_size(&Ray)==0 || stack_size(&Kakak)==0){
        printf("Ray SangaT MaraH!\n");
    } else*/ if(stack_size(&Ray) > stack_size(&Kakak)){
        int dif=stack_size(&Ray)-stack_size(&Kakak), small=stack_size(&Kakak);
        for(int i=0; i<small; i++){ //print out the smaller stack
            printf("%d %d\n", stack_top(&Ray), stack_top(&Kakak));
            stack_pop(&Ray); stack_pop(&Kakak);
        }
        printf("%d :(\n", stack_top(&Ray));
        stack_pop(&Ray);
        for(int i=0; i<dif-1; i++){
            printf("%d\n", stack_top(&Ray));
            stack_pop(&Ray);
        }
    } else if (stack_size(&Kakak) > stack_size(&Ray)){
        int dif=stack_size(&Kakak)-stack_size(&Ray), small=stack_size(&Ray);
        for(int i=0; i<small; i++){ //print out the smaller stack
            printf("%d %d\n", stack_top(&Ray), stack_top(&Kakak));
            stack_pop(&Kakak); stack_pop(&Ray);
        }
        printf("- %d\n", stack_top(&Kakak));
        stack_pop(&Kakak);
        for(int i=0; i<dif-1; i++){
            printf(" %d\n", stack_top(&Kakak));
            stack_pop(&Kakak);
        }
    } else {
        int size=stack_size(&Ray);
        for(int i=0; i<size; i++){ //print out the smaller stack
            printf("%d %d\n", stack_top(&Ray), stack_top(&Kakak));
            stack_pop(&Kakak); stack_pop(&Ray);
        }
    }
    puts("");
    return 0;
}
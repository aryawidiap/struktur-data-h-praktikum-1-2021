/**
 * Implementasi ADT PriorityQueue menggunakan Linked List
 * [default: minimum priority]
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
#include <string.h>
#define MAX_LEN 15

/* Struktur Node */

typedef struct pqueueNode_t {
    char data[101];
    int loc, soal;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int soal, char value[101]);
void pqueue_pop(PriorityQueue *pqueue);
char*pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void moveEachElement(PriorityQueue *list, char cmd[5]){
    PQueueNode *temp = list->_top;
    
    if(strcmp(cmd, "DOWN")==0){
        (temp->loc)++; //func the first node
        while(temp->next != NULL){
            temp = temp->next;
            (temp->loc)++;
        }    
    } else if(strcmp(cmd, "UP")==0){ //func the first node
        //printf("MEMINDAHKAN KE ATAS\n");
        (temp->loc)--;
        //printf("LOKASI: %d; BUKU: %s\n", temp->loc, temp->data);
        while(temp->next != NULL){
            temp = temp->next;
            (temp->loc)--;
             //printf("LOKASI: %d; BUKU: %s\n", temp->loc, temp->data);
        }    
    }
    

}

void pqueue_push(PriorityQueue *pqueue, int soal, char value[101]) //int value to char value
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode =
        (PQueueNode*) malloc (sizeof(PQueueNode));
    strcpy(newNode->data, value);//from int assignment to strcpy
    newNode->soal = soal;
    newNode->next = NULL;
    newNode->loc = 0;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }
    moveEachElement(pqueue, "DOWN");
    if (soal <= pqueue->_top->soal ) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && 
                soal >= temp->next->soal)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        if(pqueue->_top->loc==0){
            moveEachElement(pqueue, "UP");
        }
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

char* pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

/*void switchLoc(PriorityQueue *pqueue){
    PQueueNode *temp = pqueue->_top;
    int loc = temp->loc;
    temp->loc = 0;
    while(temp->next != NULL){
        temp = temp->next;
        if(temp->loc < loc){
            temp->loc++;
        }
    }
}*/
void printElement(PQueueNode *elem) {
    printf("%s ", elem->data);
    printf("%d", elem->loc);
    if(elem->next != NULL){
        printf("\n");
    }
}

void forEachElement(PriorityQueue *list, void (*func)(PQueueNode *elem)){
    PQueueNode *temp = list->_top;
    
    func(temp); //func the first node
    while(temp->next != NULL){
        temp = temp->next;
        func(temp);
    }

}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    PriorityQueue buku; //pake priority queue!
    pqueue_init(&buku);
    int tc, cmd;
    char mapel[MAX_LEN+1];
    scanf("%d", &tc);
    // Operasi pada stack
    for(int i=0; i<tc; i++){
        scanf("%d", &cmd); //prioritynya banyak soal (min priority)
        if(cmd!=-1){
            scanf("%s", mapel);
            pqueue_push(&buku, cmd, mapel);
        } else{
            printf("%d ", buku._top->loc); //simpen lokasi di stack di variabel loc
            printf("%s\n", pqueue_top(&buku));
            int tumpuk = buku._top->loc;
            PQueueNode *prev = buku._top, *nex = buku._top->next, *temp = NULL;
            while(nex!=NULL){
                if(tumpuk == 0){
                    break;
                }
                if(nex->loc < tumpuk){ //menghapuskan node-node yg ada di "atas" node dengan prioritas tertinggi
                    temp = nex;
                    nex = nex->next;
                    prev->next = nex;
                    free(temp);
                } else {
                    nex->loc -= (tumpuk+1); //"menaikkan" node-node yg ada di "bawah" node utama
                    prev=nex;
                    nex=nex->next;
                }
            }
            pqueue_pop(&buku);
        }
    }

    //puts("");
    return 0;
}
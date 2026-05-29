#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct Node
{
    uint32_t value;
    struct Node *next;
} Node;

Node *createNode(uint32_t value){
    Node *node = malloc(sizeof(Node));

    if (node == NULL){
        return NULL;
    }

    node->value = value;
    node->next = NULL;

    return node;
}

Node *getLastNode(Node *first){

    Node *result = first;

    while (result->next != NULL)
    {
        result = result->next;
    }

    return result;
}

void appendNode(Node *list, uint32_t value){
    Node *last = getLastNode(list);
    last->next = createNode(value);
}

void printList(Node *list){
    Node *node = list;

    do
    {
        printf("%d ", node->value);
        node = node->next;
    } while (node != NULL);
}

int main(){
    Node myList = *createNode(1);
    for (uint32_t i = 2; i < 10; i++)
    {
        appendNode(&myList, i);
    }

    printList(&myList);
    

}
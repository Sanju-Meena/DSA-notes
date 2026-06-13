#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}node;

typedef struct Queue {
    struct Node *front, *rear;
}queue;

queue* createQueue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->rear = NULL;
    q->front = NULL;
    return q;
}

void push(queue* q, int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;
    printf("Pushed %d to queue\n", value);

    if (q->rear == NULL) {
        q->rear = temp;
        q->front = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int pop(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    node* temp = q->front;
    int popvalue = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp); 
    return popvalue;
}

void display(queue* q) {
    if (q->front == NULL){
        printf("Queue is empty.\n");
        return;
    }
    node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    queue* q = createQueue();
    push(q, 100);
    push(q, 200);
    push(q, 300);
    display(q);

    int pi = pop(q);
    display(q);
    push(q, 400);
    display(q);
    pop(q);  

    free(q); 
    return 0;
}
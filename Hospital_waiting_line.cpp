#include <stdio.h>
#define MAX_QUEUE_SIZE;
typedef struct {
    int id;
    char name[30];
}Patient;
Patient queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;


void addPatient(Patient item) {
    if(*rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    queue[++*rear] = item;
    printf("Patient %s join to the queue.\n", item.name);
}

void callNextPatient() {
    Patient item;
    if(front == rear){
        printf("Queue is empty!\n");
        return;
    }
    item = queue[++front];
    printf("Calling patient %d : %s.\n", item.id, item.name);
}
void displayQueue(void) {
    int i;

    if(front == rear) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (i = front + 1; i <= rear; i++) {
        printf("%d", queue[i].id);
    }
    printf("\n");
}
int main(){
    Patient p1 = {101, "Anna"};
    
    return 0;
}
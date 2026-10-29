#include <stdio.h>
#define MAX_QUEUE_SIZE 100
typedef struct {
    int id;
    char name[30];
}Patient;
Patient queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;


void addPatient(Patient item) {
    if(rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    queue[++rear] = item;
    printf("Patient %s join to the queue.\n", item.name);
}

void callNextPatient() {
    Patient item;
    if(rear == front){
        printf("Queue is empty!\n");
        return;
    }
    item = queue[++front];
    printf("Calling patient %d : %s.\n", item.id, item.name);
}
void displayQueue(void) {

    if(front == rear) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: \n");
    for (int i = front + 1; i <= rear; i++) {
        printf("ID: %d, Name : %s \n", queue[i].id, queue[i].name);
    }
}
int main(){
    Patient p1 = {101, "Anna"};
    Patient p2 = {102, "Brian"};
    Patient p3 = {103, "Cathy"};
    addPatient(p1);
    addPatient(p2);
    addPatient(p3);
    displayQueue();
    callNextPatient();
    callNextPatient();
    callNextPatient();
    return 0;
}
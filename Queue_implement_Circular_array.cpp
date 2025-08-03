// Circular array implementation of queue
#include <iostream>
#define MAX_SIZE 10
using namespace std;

struct queue{
    int front = 0;
    int rear = MAX_SIZE - 1;
    int data[MAX_SIZE];
};

bool isfull(const queue &q){
    return(q.rear == ((q.front - 2)%MAX_SIZE + MAX_SIZE)%MAX_SIZE);
}

bool isempty(const queue &q){
    return(q.rear == ((q.front - 1)%MAX_SIZE + MAX_SIZE)%MAX_SIZE);
}

void enqueue(queue &q, int i){
    if (isfull(q)){
        cout << "[ERROR] Queue overflow, cannot add more elements." << endl;
        exit(1);
    }
    q.rear = (q.rear == MAX_SIZE - 1)? 0 : (q.rear + 1);
    q.data[q.rear] = i; 
}

int length(const queue &q){
    if (isempty(q)){
        return(0);
    }
    else{
        return(((q.rear - q.front)%MAX_SIZE + MAX_SIZE)%MAX_SIZE + 1);
    }
}

int dequeue(queue &q){
    if (isempty(q)){
        cout << "[ERROR] Queue is empty, no element available to extract." << endl;
        exit(1);
    }
    int f_Val = q.data[q.front];
    q.front = (q.front == MAX_SIZE - 1)? 0 : (q.front + 1);
    //q.front = ((q.front + 1)%MAX_SIZE + MAX_SIZE)%MAX_SIZE;
    return(f_Val);
}

int main() {
    queue q;
    cout << isfull(q) << isempty(q) << endl;
    enqueue(q, 2);enqueue(q, 3);enqueue(q, 4);enqueue(q, 5);
    cout << dequeue(q) << dequeue(q) << dequeue(q) << endl;
    cout << q.front << " and rear : " << q.rear << endl;
    enqueue(q, 6);enqueue(q, 7);enqueue(q, 8);enqueue(q, 9);
    ;enqueue(q, 81);
    cout << q.front << " and rear : " << q.rear;
    return 0;
}
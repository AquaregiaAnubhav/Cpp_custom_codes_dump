// Fixed front index array implementation of queue
#include <iostream>
#define MAX_SIZE 10
using namespace std;

struct queue{
    const int front = 0;
    int rear = -1;
    int data[MAX_SIZE];
};

bool isfull(const queue &q){
    return(q.rear == MAX_SIZE - 1);
}

bool isempty(const queue &q){
    return(q.rear == -1);
}

void enqueue(queue &q, int i){
    if (isfull(q)){
        cout << "[ERROR] Queue overflow, cannot add more elements." << endl;
        exit(1);
    }
    q.data[++q.rear] = i; 
}

int length(const queue &q){
    return(q.rear + 1);
}

int dequeue(queue &q){
    if (isempty(q)){
        cout << "[ERROR] Queue is empty, no element available to extract." << endl;
        exit(1);
    }
    int front_val = q.data[q.front];
    for (int i = 0; i < q.rear; i++){
        q.data[i] = q.data[i+1];
    }
    q.rear--;
    return(front_val);
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
#include <iostream>
using namespace std;

typedef int ElemType;

// 逻辑上是环形

struct SeqQueue
{
    ElemType *data;
    int front;
    int rear;
    int maxsize;
};

void InitQueue(SeqQueue *sq, int InitMaxSize = 10)
{
    sq->data = new ElemType[InitMaxSize];
    sq->front = 0;
    sq->rear = 0;
    sq->maxsize = InitMaxSize;
}

bool QueueEmpty(SeqQueue *sq)
{
    if (sq->front == sq->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool QueueFull(SeqQueue *sq)
{
    if (sq->rear + 1 % sq->maxsize == sq->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool EnQueue(SeqQueue *sq, ElemType x)
{
    if (QueueFull(sq))
    {
        return false;
    }
    sq->data[sq->rear] = x;
    sq->rear = sq->rear + 1 % sq->maxsize;
    return true;
}

bool DeQueue(SeqQueue *sq, ElemType &x)
{
    if (QueueEmpty(sq))
    {
        return false;
    }
    x = sq->data[sq->front];
    sq->front = sq->front + 1 % sq->maxsize;
    return true;
}

bool GetFront(SeqQueue *sq, ElemType &x)
{
    if (QueueEmpty(sq))
    {
        return false;
    }
    x = sq->data[sq->front];
    return true;
}

void PrintQueue(SeqQueue* sq){
    if(QueueEmpty(sq)){
        return;
    }
    for(int i = sq->front; i != sq->rear; i = (i + 1) % sq->maxsize){
        cout << sq->data[i] << " ";
    }
    cout << endl;
}

void ClearQueue(SeqQueue* sq){
    sq->front = sq->rear = 0;
}


int main()
{
    SeqQueue *sq = new SeqQueue;
    InitQueue(sq, 6);

    EnQueue(sq, 10);
    EnQueue(sq, 20);
    EnQueue(sq, 30);
    EnQueue(sq, 40);
    PrintQueue(sq);

    ElemType x;
    DeQueue(sq, x);
    cout << x << endl;
    PrintQueue(sq);

    GetFront(sq, x);
    cout << x << endl;
    PrintQueue(sq);

    ClearQueue(sq);
    cout << QueueEmpty(sq) << endl;

    delete sq->data;
    delete sq;

    return 0;
}
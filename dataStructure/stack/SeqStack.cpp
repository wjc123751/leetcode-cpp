#include <iostream>
#include <vector>
using namespace std;

typedef int ElemType;

struct SeqStack
{
    ElemType *data;
    int top;
    int maxsize;
};

void InitStack(SeqStack *st, int initMaxSize = 10)
{
    st->data = new ElemType[initMaxSize];
    st->top = -1;
    st->maxsize = initMaxSize;
}

bool StackEmpty(SeqStack *st)
{
    if (st->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool StackFull(SeqStack *st)
{
    if (st->top == st->maxsize - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Push(SeqStack *st, ElemType x)
{
    if (StackFull(st))
    {
        return false;
    }
    st->top++;
    st->data[st->top] = x;
    return true;
}

bool Pop(SeqStack *st, ElemType &x)
{
    if (StackEmpty(st))
    {
        return false;
    }
    x = st->data[st->top];
    st->top--;
    return true;
}

bool GetTop(SeqStack* st, ElemType &x){
    if(StackEmpty(st)){
        return false;
    }
    x = st->data[st->top];
    return true;
}

void PrintStack(SeqStack* st){
    if(StackEmpty(st)){
        return;
    }
    for(int i = 0;i <= st->top; ++i){
        cout << st->data[i] << " ";
    }
    cout << endl;
}

void ClearStack(SeqStack* st){
    st->top = -1;
}

int main()
{
    SeqStack *st = new SeqStack;
    InitStack(st, 4);

    Push(st, 10);
    Push(st, 20);
    Push(st, 30);
    Push(st, 40);
    PrintStack(st);

    ElemType x;
    Pop(st, x);
    cout << x << endl;
    PrintStack(st);

    GetTop(st, x);
    cout << x << endl;
    PrintStack(st);

    ClearStack(st);
    cout << StackEmpty(st) << endl;
    PrintStack(st);

    delete st->data;
    delete st;

    return 0;
}
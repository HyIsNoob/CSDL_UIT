#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* next;
};
struct QUEUE {
    NODE* Front;
    NODE* Back;
};
NODE* CreateNode(int x) {
    NODE* p = new NODE;
    p->info = x;
    p->next = NULL;
    return p;
}

void createEmptyQueue(QUEUE& q) {
    q.Front = NULL;
    q.Back = NULL;
}
void enqueue(QUEUE& q, NODE* p) {
    if (q.Front == NULL)
    {
        q.Front = p;
        q.Back = p;
    }
    else {
        q.Back->next = p;
        q.Back = p;
    }
}
int dequeue(QUEUE& q, int& x) {
    if (q.Front == NULL)
        return -1;
    x = q.Front->info;
    NODE* p = q.Front;
    q.Front = q.Front->next;
    if (q.Front == NULL)
        q.Back = NULL;
    delete p;
    return 0;
}
int Front(QUEUE q)
{
    return q.Front->info;
}
int Back(QUEUE q)
{
    return q.Back->info;
}
void createQueue(QUEUE& q) {
    createEmptyQueue(q);
    int x;
    cin >> x;
    while (x != -1) {
        enqueue(q, CreateNode(x));
        cin >> x;
    }
}
void PrintQueue(QUEUE q)
{
    for (NODE* i = q.Front; i != NULL; i = i->next)
        cout << i->info << " ";
}

int main() {
    QUEUE q;
    createQueue(q);
    PrintQueue(q);
    return 0;
}

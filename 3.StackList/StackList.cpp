#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* next;
};
struct STACK {
    NODE* head;
    NODE* tail;
};
NODE* CreateNode(int x) {
    NODE* p = new NODE;
    p->info = x;
    p->next = NULL;
    return p;
}

void createEmptyStack(STACK& s) {
    s.head = NULL;
    s.tail = NULL;
}
void Push(STACK& s, NODE* p) {
    if (s.head == NULL)
    {
        s.head = p;
        s.tail = p;
    }
    else {
        p->next = s.head;
        s.head = p;
    }
}
int Pop(STACK& s, int& x) {
    if (s.head == NULL)
        return -1;
    x = s.head->info;
    NODE* p = s.head;
    s.head = s.head->next;
    if (s.head == NULL)
        s.tail = NULL;
    delete p;
    return 0;
}
int Top(STACK s)
{
    return s.head->info;
}
void createStack(STACK& s) {
    createEmptyStack(s);
    int x;
    cin >> x;
    while (x != -1) {
        Push(s, CreateNode(x));
        cin >> x;
    }
}
void PrintStack(STACK s)
{
    for (NODE* i = s.head; i != NULL; i = i->next)
        cout << i->info << " ";
}

int main() {
    STACK s;
    createStack(s);
    PrintStack(s);
    return 0;
}

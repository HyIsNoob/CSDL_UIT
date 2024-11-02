#include <iostream>
using namespace std;
#define MAX 100
struct STACK {
    int a[MAX];
    int t;
};
void CreateEmptyStack(STACK& s) {
    s.t = -1;
}
bool isEmpty(STACK s) { //STACKcó rỗng hay không
    if (s.t == -1)
        return 1;
    return 0;
}
bool isFull(STACK s) { //Kiểm tra STACKcó đầy hay không
    if (s.t >= MAX)
        return 1;
    return 0;
}
bool Push(STACK& s, int x) {
    if (isFull(s) == 0)
    {
        s.a[++s.t] = x;
        return 1;
    }
    return 0;
}
int Pop(STACK& s, int& x) {
    if (isEmpty(s) == 0)
    {
        x = s.a[s.t--];
        return 1;
    }
    return 0;
}

void createStack(STACK& s) {
    CreateEmptyStack(s);
    int x;
    cin >> x;
    while (x != -1) {
        Push(s, x);
        cin >> x;
    }
}
void PrintStack(STACK s)
{
    for (int i = 0; i <= s.t; i++)
        cout << s.a[i] << " ";
}

int main() {
    STACK q;
    createStack(q);
    PrintStack(q);
    return 0;
}

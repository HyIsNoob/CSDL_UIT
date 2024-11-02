#include <iostream>
using namespace std;
#define MAX 100

struct QUEUE {
    int a[MAX];
    int Front;
    int Rear;
};
void createEmptyQueue(QUEUE& q) {
    q.Front = -1;
    q.Rear = -1;
}

bool isEmpty(QUEUE q)
{
    if (q.Front == -1)
        return 1;
    return 0;
}
bool isFull(QUEUE q)
{
    if (q.Rear - q.Front + 1 == MAX)
        return 1;
    return 0;
}

void EnQueue(QUEUE& q, int x) {
    int f, r;
    if (isFull(q))
        cout << "queue day roi khong the them vao duoc nua";
    else
    {
        if (q.Front == -1)
        {
            q.Front = 0;
            q.Rear = -1;
        }
        if (q.Rear == MAX - 1) {
            f = q.Front;
            r = q.Rear;
            for (int i = f; i <= r; i++)
                q.a[i - f] = q.a[i];
            q.Front = 0;
            q.Rear = r - f;
        }
        q.Rear++;
        q.a[q.Rear] = x;
    }
}

bool DeQueue(QUEUE& q, int& x) {
    if (isEmpty(q) == 0)
    {
        x = q.a[q.Front];
        q.Front++;
        if (q.Front > q.Rear)
        {
            q.Front = -1;
            q.Rear = -1;
        }
        return 1;
    }
    printf("Queue rong");
    return 0;
}


void createQueue(QUEUE& q) {
    createEmptyQueue(q);
    int x;
    cin >> x;
    while (x != -1) {
        EnQueue(q, x);
        cin >> x;
    }
}
void PrintQueue(QUEUE q)
{
    for (int i = q.Front; i <= q.Rear; i++)
        cout << q.a[i] << " ";
}

int main() {
    QUEUE q;
    createQueue(q);
    PrintQueue(q);
    return 0;
}

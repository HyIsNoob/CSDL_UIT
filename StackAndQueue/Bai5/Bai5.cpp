#include <iostream>
using namespace std;

struct NODE {
	char info;
	NODE* pNext;
};
struct queue {
	NODE* front;
	NODE* back;
};
NODE* CreatNode(int x) {
	NODE* p = new NODE;
	p->info = x;
	p->pNext = NULL;
	return p;


}
#include <string>
#include <algorithm> 
void createEmptyQueue(queue& q) {
	q.front = NULL;
	q.back = NULL;
}
void enqueue(queue& q, NODE* p) {
	if (q.front == NULL)
	{
		q.front = p;
		q.back = p;
	}
	else {
		q.back->pNext = p;
		q.back = p;
	}
}
int dequeue(queue& q, char& x) {
	if (q.front == NULL)
		return -1;
	x = q.front->info;
	NODE* p = q.front;
	q.front = q.front->pNext;
	if (q.front == NULL)
		q.back = NULL;
	delete p;
	return 0;
}

string trimString(const std::string& str) {
	if (str.empty()) {
		return str;
	}
	size_t start = str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos) {
		return "";
	}
	size_t end = str.find_last_not_of(" \t\r\n");
	if (end == std::string::npos) {
		return "";
	}
	return str.substr(start, end - start + 1);
}

void createQueue(queue& q) {
	createEmptyQueue(q);
	int dem = 0;
	string str1;
	getline(cin, str1);
	string str = trimString(str1);
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	char a[1000];
	if (str[str.length()] == '\b') {
		for (int i = 0; i < str.length() - 1; i++)
			a[dem++] = str[i];
	}
	else {
		for (int i = 0; i < str.length(); i++)
			a[dem++] = str[i];
	}
	char b[1000];
	int k = 0;
	if (dem != 0) {
		for (int i = 0; i < dem / 2; i++)
			enqueue(q, CreatNode(a[i]));
		if (dem % 2 == 0) {
			for (int i = dem - 1; i >= dem / 2; i--)
				dequeue(q, b[k++]);
		}
		else {
			for (int i = dem - 1; i >= dem / 2 + 1; i--)
				dequeue(q, b[k++]);
		}
		bool flag = true;
		int temp = dem - 1;
		int temp1 = temp;
		for (int i = 0; i < dem / 2; i++)
			if (a[temp--] != b[i])
				flag = false;
		if (flag == false)
			cout << "False";
		else
			cout << "True";
	}
	else
		cout << "True";
}


int main() {
	queue q;
	createQueue(q);
	return 0;
}

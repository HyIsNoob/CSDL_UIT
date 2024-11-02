#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define MAX 300

struct STACK {
	string a[MAX];
	int t;
};
void CreateEmptyStack(STACK& s) {
	s.t = -1;
}
bool isEmpty(STACK s) {
	if (s.t == -1)
		return 1;
	return 0;
}
bool isFull(STACK s) {
	if (s.t >= MAX)
		return 1;
	return 0;
}
bool Push(STACK& s, string x) {
	if (isFull(s) == 0)
	{
		s.a[++s.t] = x;
		return 1;
	}
	return 0;
}
int Pop(STACK& s, string& x) {
	if (isEmpty(s) == 0)
	{
		x = s.a[s.t--];
		return 1;
	}
	return 0;
}

void createStack(STACK& s, string x) {
	CreateEmptyStack(s);
	Push(s, x);
}
void PrintStack(STACK s)
{
	for (int i = 0; i <= s.t; i++)
		cout << s.a[i] << " ";
}

void StringReverse(string& s) {
	STACK wordStack;
	CreateEmptyStack(wordStack);
	string word = "";
	for (char c : s) {
		if (c == ' ') {
			Push(wordStack, word);
			word = "";
		}
		else
			word += c;
	}
	Push(wordStack, word);
	s = "";
	while (!isEmpty(wordStack)) {
		string poppedWord;
		Pop(wordStack, poppedWord);
		s += poppedWord;
		if (!isEmpty(wordStack)) {
			s += " ";
		}
	}
}

int main() {
	string s;

	getline(std::cin, s);

	if (s.empty() == true)
		cout << "Chuoi rong." << endl;
	else {
		StringReverse(s);
		cout << s << endl;

	}

	return 0;
}

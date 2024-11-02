
#include <iostream>
#include <iomanip>
using namespace std;

struct NODE_CHAR {
	char info;
	NODE_CHAR* pNext;
};

struct stack {
	NODE_CHAR* top;
};
NODE_CHAR* CreateNode(float x) {
	NODE_CHAR* p = new NODE_CHAR;
	p->info = x;
	p->pNext = NULL;
	return p;
}



NODE_CHAR* CreateNode(char x) {
	NODE_CHAR* p = new NODE_CHAR;
	p->info = x;
	p->pNext = NULL;
	return p;
}
NODE_CHAR* input_infix() {
	NODE_CHAR* temp;
	NODE_CHAR* tempp;
	char temp1, temp2;
	cin >> temp1;
	cin >> temp2;
	temp = CreateNode(temp1);
	tempp = CreateNode(temp2);
	temp->pNext = tempp;
	return temp;
}

int DoUuTien(char s) {
	switch (s) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':

		return 4;
	default:
		return -1;
	}
}

NODE_CHAR* infix_to_postfix(NODE_CHAR* infix) {
	return infix;
}

void out(NODE_CHAR* postfix) {
	NODE_CHAR* temp;
	temp = postfix->pNext;
	char op1 = postfix->info;
	char op2 = temp->info;
	int precedence_op1 = DoUuTien(op1);
	int precedence_op2 = DoUuTien(op2);
	if (precedence_op1 == precedence_op2) {
		cout << op1 << " = " << op2 << endl;
	}
	else if (precedence_op1 > precedence_op2) {
		cout << op1 << " > " << op2 << endl;
	}
	else {
		cout << op1 << " < " << op2 << endl;
	}
}



int main() {
	NODE_CHAR* infix = NULL;
	NODE_CHAR* postfix;

	infix = input_infix();

	postfix = infix_to_postfix(infix);
	out(postfix);
	return 0;
}

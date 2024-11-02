#include <iostream>
using namespace std;

#define MAXTABLESIZE 10000

struct NODE {
	int key;
};
typedef NODE HASHTABLE[MAXTABLESIZE];

int TableSize;
int M;

int HF(int key) {
	return key % M;
}
int HF_LinearProbing(int key, int i) {
	return (HF(key) + i) % TableSize;
}

#define EMPTY -1

void Insert(HASHTABLE& ht, int key) {
	int i = 0;
	int j;
	do {
		j = HF_LinearProbing(key, i);
		if (ht[j].key == EMPTY) {
			ht[j].key = key;
			return;
		}
		else {
			i++;
		}
	} while (i != TableSize);
	cout << "Hash table is full. Cannot insert key " << key << endl;
}

void CreateHashTable(HASHTABLE& ht, int& m) {
	int n;
	cin >> n;
	cin >> m;
	M = m;
	TableSize = m;
	for (int i = 0; i < TableSize; i++) {
		ht[i].key = EMPTY;
	}

	for (int i = 0; i < n; i++) {
		int key;
		cin >> key;
		Insert(ht, key);
	}
}

void Traverse(HASHTABLE ht, int n) {
	for (int i = 0; i < n; i++) {
		if (ht[i].key != EMPTY) {
			cout << i << " --> " << ht[i].key << endl;
		}
		else {
			cout << i << " --> " << EMPTY << endl;
		}
	}
}


int main() {
	HASHTABLE H;
	int CurrentSize;

	CreateHashTable(H, CurrentSize);
	Traverse(H, CurrentSize);

	return 0;
}

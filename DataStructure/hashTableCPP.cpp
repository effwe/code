#include <iostream>

using namespace std;


class HashTable {
public:
  HashTable(int size) {
    table = new int[size];
    table_size = size;
    for (int i = 0; i < size; i++) {
      table[i] = -1;
    }
  }

  void insert(int key) {
    int hashCode = hash(key);
    table[hashCode] = key;
  }

  bool find(int key) {
    int hashCode = hash(key);
    return table[hashCode] != -1 && table[hashCode] == key;
  }

  int hash(int key) {
    return key % table_size;
  }

  int* table;
  int table_size;
};

int main() {
  HashTable hashTable(9);
  hashTable.insert(10);
  hashTable.insert(7);
  hashTable.insert(13);
  hashTable.insert(38);

  for (int i = 0; i < 9; i++) {
    if (hashTable.table[i] != -1) {
      cout << hashTable.table[i] << " ";
    } else {
      cout << "NULL ";
    }
  }

  cout << endl;
  cout << hashTable.find(29) << endl;
  cout << hashTable.find(13) << endl;
}
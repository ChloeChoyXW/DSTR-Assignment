#include "university.h"

int main() {
	UniList university = UniList("University List");
	university.readFromFile();
	university.displayList();
	cout << string(22, '=')<< "Sorted List" << string(22, '=') << endl;
	university.insertionSortUniDoublyLinkedList('a');
	university.displayList();
	return 0;
}
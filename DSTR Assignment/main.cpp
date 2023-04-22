#include <iostream>
#include "a.h"

int main() {
	head = NULL;
	InsertItemIntoSortedList("EMP005", "Jack", 1234);
	InsertItemIntoSortedList("EMP003", "Jasmine", 4321);
	InsertItemIntoSortedList("EMP002", "Jupiter", 1248);
	InsertItemIntoSortedList("EMP006", "James", 4345);
	InsertItemIntoSortedList("EMP004", "Jolly", 1474);

	cout << string(55, '*') << endl;
	cout << "Sorted List as below: " << endl;
	cout << string(55, '*') << endl;
	displayEmployeeInformation();
	return 0;
}
#include <string>
#include <iostream>
#include <stdio.h>
#include "university.h"
#include "registeredUsers.h"
#include "userFavUni.h"
#include "admin.h"

using namespace std;

int main() {
	
	UniList uniList = UniList("used for normal users");
	uniList.readFromFileDoubly();
	uniList.insertionSortUniDoublyLinkedList(2);
	cout << string(60, '+') << endl;
	uniList.uniQuickSort(2);

	//auto start = std::chrono::high_resolution_clock::now();
	//auto end = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	//std::cout << "Execution time: " << duration << " milliseconds" << std::endl;

	return 0;
}

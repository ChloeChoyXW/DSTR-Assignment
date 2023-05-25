#include "userFavUni.h"
#include <cmath>
#include <sstream>

using namespace std;

userFavUniList::userFavUniList(string userFavUniListName) : userFavUniListName(userFavUniListName) {};

userFavUni* userFavUniList::createNewNode(string userID, string uniName)
{
	userFavUni* newnode = new userFavUni;
	newnode->userID = userID;
	newnode->uniName = uniName;
	newnode->nextAdd = NULL;
	newnode->prevAdd = NULL;
	return newnode;
}

void userFavUniList::insertToFrontOfUserFavUniList(string userID, string uniName)
{
	userFavUni* newnode = createNewNode(userID, uniName);

	if (head == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		newnode->nextAdd = head;
		head->prevAdd = newnode;
		head = newnode;
	}
}

void userFavUniList::insertToEndOfUserFavUniList(string userID, string uniName)
{
	userFavUni* newnode = createNewNode(userID, uniName);

	if (head == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		newnode->prevAdd = tail;
		tail->nextAdd = newnode;
		tail = newnode;
	}
}

void userFavUniList::deleteFromUserFavUniList(string uniName)
{
	if (head == NULL)
		return;
	if (head->uniName == uniName)
	{
		userFavUni* current = head;
		head = head->nextAdd;
		cout << "Deleted Favourite University:  " << current->uniName << endl;
		delete current;
	}
	else if (tail->uniName == uniName)
	{
		userFavUni* current = tail;
		tail = tail->prevAdd;
		if (tail == NULL)
			head = NULL;
		else
			tail->nextAdd = NULL;
		cout << "Deleted Favourite University: " << current->uniName << endl;
		delete current;
	}
	else
	{
		userFavUni* prev = head->prevAdd;
		userFavUni* current = head;
		bool found = false;
		while (current != NULL)
		{
			if (current->uniName == uniName)
			{
				found = true;
				prev->nextAdd = current->nextAdd;
				cout << "Deleted Favourite University: " << current->uniName << endl;
				delete current;
				return;
			}
			prev = current;
			current = current->nextAdd;
		}
		if (!found)
			cout << uniName << " is not found in the list!" << endl;
	}
}
//=====================================INSERTION SORT============================================

void sortedInsert(userFavUni** head, userFavUni* newNode) {
	userFavUni* current;
	if (*head == NULL) {
		//std::cout << "The favorite university list is empty." << std::endl;
		*head = newNode;
		
		return;
	}
	else if ((*head)->uniName >= newNode->uniName) {
		newNode->nextAdd = *head; 
		newNode->nextAdd->prevAdd = newNode;
		*head = newNode;
	}
	else {
		current = *head;
		while (current->nextAdd != NULL &&	current->nextAdd->uniName < newNode->uniName)
			current = current->nextAdd;
		newNode->nextAdd = current->nextAdd;

		// if the new node is not inserted at the end of the list
		if (current->nextAdd != NULL)
			newNode->nextAdd->prevAdd = newNode;

		current->nextAdd = newNode;
		newNode->prevAdd = current;
	}
}


//void userFavUniList::insertionSort() {
//	userFavUni* sorted = NULL;
//	userFavUni* current = head;
//	while (current != NULL) {
//
//		// Store next for next iteration
//		userFavUni* next = current->nextAdd;
//
//		// removing all the links so as to create 'current' as a new node for insertion
//		current->prevAdd = current->nextAdd = NULL;
//
//		// insert current in 'sorted' doubly linked list
//		sortedInsert(&sorted, current);
//
//		// Update current
//		current = next;
//	}
//
//	// Update head_ref to point to sorted doubly linked list
//	head = sorted;
//
//}

void userFavUniList::insertionSort() {
	if (head == nullptr) {
		std::cout << "The favorite university list is empty." << std::endl;
		return;
	}
	userFavUni* current = head->nextAdd;
	while (current != nullptr) {
		std::string key = current->uniName;
		userFavUni* prevAdd = current->prevAdd;
		while (prevAdd != nullptr && prevAdd->uniName > key) {
			prevAdd->nextAdd->uniName = prevAdd->uniName;
			prevAdd = prevAdd->prevAdd;
		}
		if (prevAdd == nullptr) {
			head->uniName = key;
		}
		else {
			prevAdd->nextAdd->uniName = key;
		}
		current = current->nextAdd;
	}
	std::cout << "The favorite university list has been sorted in alphabetical order." << std::endl;
}


//=====================================JUMP SEARCH============================================

int userFavUniList::size() {
	int count = 0;
	userFavUni* current = head;
	while (current != NULL) {
		count++;
		current = current->nextAdd;
	}
	return count;
}

int userFavUniList::getPosition(userFavUni* node) {
	int position = 0;
	userFavUni* current = head;

	while (current != nullptr) {
		if (current == node) {
			return position;
		}
		current = current->nextAdd;
		position++;
	}

	// Node not found, return an invalid position
	return -1;
}

int userFavUniList::JumpSearchFavUni(const std::string& uniName) {


	if (head == nullptr) {
		std::cout << "The favorite university list is empty." << std::endl;
		return -1;  // List is empty
	}

	int listSize = size();
	int blockSize = static_cast<int>(std::sqrt(listSize));

	userFavUni* current = head;
	userFavUni* prev = nullptr;
	// Finding the block where the target element belongs
	while (current && current->uniName < uniName) {
		prev = current;
		for (int i = 0; current && i < blockSize; ++i) {
			current = current->nextAdd;
		}
	}

	// Linear search within the block
	while (current && current->uniName <= uniName) {
		if (current->uniName == uniName) {
			std::cout << "The university '" << uniName << "' is found in the favorite list." << std::endl;
			return getPosition(current);
		}
		current = current->nextAdd;
	}

	std::cout << "The university '" << uniName << "' is not found in the favorite list." << std::endl;
	return -1;  // Target element not found
}


void userFavUniList::sortUserFavUniList(string sortCondition)
{

}



void userFavUniList::displayUserFavUniList()
{
	userFavUni* current = head;

	while (current != NULL)
	{
		cout << "\n" << "User ID:  " << current->userID << endl;
		cout << "Favourite University:  " << current->uniName << "\n" << endl;
		cout << string(55, '=') <<  endl;

		current = current->nextAdd;
	}
	cout << "List ended here." <<  endl;
}

//userFavUni* userFavUniList::MiddleBinarySearch(userFavUni* start, userFavUni* last, string uniName)
//{
//	if (start == nullptr || last == nullptr)
//		return nullptr;
//
//	while (start != last)
//	{
//		userFavUni* mid = start;
//		int count = 0;
//		while (mid != last)
//		{
//			mid = mid->nextAdd;
//			count++;
//		}
//		mid = start;
//		for (int i = 0; i < count / 2; i++)
//			mid = mid->nextAdd;
//
//		if (mid->uniName == uniName)
//			return mid;
//		else if (mid->uniName < uniName)
//			start = mid->nextAdd;
//		else
//			last = mid->prevAdd;
//	}
//
//	return nullptr;
//}
//
//
//void userFavUniList::BinarySearchFavUni(string uniName)
//{
//	userFavUni* result = MiddleBinarySearch(head, tail, uniName);
//
//	if (result != nullptr)
//		cout << "Found: " << result->uniName << endl;
//	else
//		cout << "Not found: " << uniName << endl;
//}

void userFavUniList::readFavUniFile()
{
	string filename = "favuni.csv";
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "File " << filename << "unable to found!" << endl;
		return;
	}

	string line;
	while (getline(file, line))
	{
		stringstream d(line);
		string userID, uniName;
		getline(d, userID, ',');
		getline(d, uniName, ',');
		insertToEndOfUserFavUniList(userID, uniName);
	}

	file.close();
}

void userFavUniList::writeFavUniFile()
{
	ofstream file("favuni.csv");
	if (!file)
	{
		cout << "File unable to open!" << endl;
		return;
	}

	userFavUni* current = head;
	while (current != nullptr)
	{
		file << current->userID << ',' << current->uniName << "\n";
		current = current->nextAdd;
	}
	file.close();
}


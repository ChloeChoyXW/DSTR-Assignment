#include "admin.h"

using namespace std;

adminList::adminList(string adminListname) : adminListName(adminListName) {};
//create an empty new node
admin* adminList::createNewNode(int adminID, string name, string pw, string phoneNum, string email) {
	
	admin* newnode = new admin;

	newnode-> adminID = adminID;
	newnode -> name = name;
	newnode -> pw = pw;
	newnode -> phoneNum = phoneNum;
	newnode -> email = email;
	newnode->nextAdd = NULL;
	newnode->prevAdd = NULL;

	return newnode;

}

void adminList::insertToEndOfAdminList(int adminID, string name, string pw, string phoneNum, string email) {
	
	admin* newnode = createNewNode(adminID, name, pw, phoneNum, email);

	if (head == NULL)
	{
		newnode->nextAdd = NULL;
		tail = newnode;
	}
	else
	{
		newnode->nextAdd = head;
		head->prevAdd = newnode;
	}
	head = newnode;

}


//void adminList::deleteFromAdminList(int adminID)
//{
//	if (head == NULL)
//		return;
//	if (head->adminID == adminID)
//	{
//		admin* current = head;
//		head = head->nextAdd;
//		cout << "Deleted: Admin ID of " << current->adminID << endl;
//		delete current;
//	}
//	else if (tail->adminID == adminID)
//	{
//		admin* current = tail;
//		tail = tail->prevAdd;
//		if (tail == NULL)
//			head = NULL;
//		else
//			tail->nextAdd = NULL;
//		cout << "Deleted: Admin ID of " << current->adminID << endl;
//		delete current;
//	}
//	else
//	{
//		admin* prev = head->prevAdd;
//		admin* current = head;
//		bool found = false;
//		while (current != NULL)
//		{
//			if (current->adminID == adminID)
//			{
//				found = true;
//				prev->nextAdd = current->nextAdd;
//				cout << "Deleted: Registered User ID of " << current->adminID << endl;
//				delete current;
//				return;
//			}
//			prev = current;
//			current = current->nextAdd;
//		}
//		if(!found)
//			cout << adminID << " is not in the list!" << endl;
//	}
//}
//
////======================================================================================================
////Linear search
//
//void adminList::linearsearchAndModifyAdminDetails(int choice, int adminID)
//{
//	if (head == NULL)
//		return;
//
//	admin* current = head;
//	while (current != NULL)
//		{
//		if (current->adminID == adminID)
//		{
//			switch (choice)
//			{
//			case 1:
//			{
//				cout << "Please enter name: ";
//				cin >> current->name;
//				return;
//			}
//			case 2:
//			{
//				cout << "Please enter password: ";
//				cin >> current->pw;
//				return;
//			}
//			case 3:
//			{
//				cout << "Please enter phone number: ";
//				cin >> current->phoneNum;
//				return;
//			}
//			case 4:
//			{
//				cout << "Please enter email: ";
//				cin >> current->email;
//				return;
//			}
//			}
//		}
//		current = current->nextAdd;
//		}
//}
//
//void adminList::linearsearchAndDisplayAdminDetails(int choice)
//{
//	if (head == NULL)
//		return;
//	bool found = false;
//	admin* current = head;
//	int adminID;
//	string name;
//	switch (choice)
//	{
//	case 1:
//		cout << "Enter Admin ID: ";
//		cin >> adminID;
//		while (current != NULL)
//		{
//			if (current-> adminID == adminID)
//			{
//				found = true;
//				cout << "Admin ID:  " << current->adminID << endl;
//				cout << "Name:  " << current->name << endl;
//				cout << "Password:  " << current->pw << endl;
//				cout << "Phone No.:  " << current->phoneNum << endl;
//				cout << "Email:  " << current->email << endl;
//				cout << string(55, '=') << endl;
//				return;
//			}
//			current = current->nextAdd;
//		}
//		if (!found)
//			cout << "User not found" << endl;
//		break;
//	case 2:
//		cout << "Enter User Name: ";
//		cin >> name;
//		while (current != NULL)
//		{
//			if (current->name == name)
//			{
//				found = true;
//				cout << "User ID:  " << current->adminID << endl;
//				cout << "Name:  " << current->name << endl;
//				cout << "Password:  " << current->pw << endl;
//				cout << "Phone No.:  " << current->phoneNum << endl;
//				cout << "Email:  " << current->email << endl;
//				cout << string(55, '=') << endl;
//				return;
//			}
//			current = current->nextAdd;
//		}
//		if (!found)
//			cout << "User not found" << endl;
//		break;
//	}
//}
//
////======================================================================================================
//// function to insert a new node in sorted way in a sorted doubly linked list
//void sortedInsert(admin** head, admin* newNode, int sortCondition)
//{
//	admin* current;
//
//	switch (sortCondition) {
//	case 1:
//		
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)->adminID >= newNode-> adminID) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd->adminID < newNode->adminID)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//
//		break;
//
//	case 2:
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)-> name >= newNode-> name) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd-> name < newNode-> name)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//		break;
//
//	case 3:
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)-> email >= newNode-> email) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd-> email < newNode-> email)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//		break;
//
//}
//}
//
//void adminList::insertionSortAdminDoublyLinkedList(int sortCondition) {
//	//	/*1 = adminID
//	//	2 = name,
//	//	3 = pw,
//	//	4 = phoneNum
//	//	5 = email
//
//	//insertionSort(&head, sortCondition);
//	// Initialize 'sorted' - a sorted doubly linked list
//	admin* sorted = NULL;
//
//	// Traverse the given doubly linked list and
//	// insert every node to 'sorted'
//	admin* current = head;
//	while (current != NULL) {
//
//		// Store next for next iteration
//		admin* next = current->nextAdd;
//
//		// removing all the links so as to create 'current'
//		// as a new node for insertion
//		current->prevAdd = current->nextAdd = NULL;
//
//		// insert current in 'sorted' doubly linked list
//		sortedInsert(&sorted, current, sortCondition);
//
//		// Update current
//		current = next;
//	}
//
//	// Update head_ref to point to sorted doubly linked list
//	head = sorted;
//
//
//}
//
////======================================================================================================
////Quick Sort Algorithm
////From https://www.geeksforgeeks.org/quicksort-for-linked-list/
//
///* A utility function to swap two elements */
//void adminswap ( string* a, string* b )
//{ string t = *a; *a = *b; *b = t; }
//
//void adminswap ( int* a, int* b )
//{ int t = *a; *a = *b; *b = t; }
//
//void adminswapping(admin* i, admin* j){
//	adminswap(&(i->adminID), &(j->adminID));
//	adminswap(&(i->name), &(j->name));
//	adminswap(&(i->pw), &(j->pw));
//	adminswap(&(i->phoneNum), &(j->phoneNum));
//	adminswap(&(i->email), &(j->email));
//}
//
//// A utility function to find
//// last node of linked list
//admin *lastNode(admin *end)
//{
//	while (end && end->nextAdd)
//		end = end->nextAdd;
//	return end;
//}
//
///* Considers last element as pivot,
//places the pivot element at its
//correct position in sorted array,
//and places all smaller (smaller than
//pivot) to left of pivot and all greater
//elements to right of pivot */
//admin* partition(admin *l, admin *h)
//{
//	// set pivot as h element
//	string x = h->name;
//
//	// similar to i = l-1 for array implementation
//	admin *i = l->prevAdd;
//
//	// Similar to "for (int j = l; j <= h- 1; j++)"
//	for (admin* j = l; j != h; j = j->nextAdd)
//	{
//		if (j->name <= x)
//		{
//			// Similar to i++ for array
//			i = (i == NULL)? l : i->nextAdd;
//
//			adminswapping(i, j);
//		}
//	}
//	i = (i == NULL)? l : i->nextAdd; // Similar to i++
//	adminswapping(i, h);
//	return i;
//}
//
///* A recursive implementation
//of quicksort for linked list */
//void _quickSort(admin* l, admin *h)
//{
//	if (h != NULL && l != h && l != h->nextAdd)
//	{
//		admin *p = partition(l, h);
//		_quickSort(l, p->prevAdd);
//		_quickSort(p->nextAdd, h);
//	}
//}
//
//// The main function to sort a linked list.
//// It mainly calls _quickSort()
//void adminList::adminQuickSort()
//{
//	admin* current = head;
//	// Find last node
//	admin *h = lastNode(current);
//
//	// Call the recursive QuickSort
//	_quickSort(current, h);
//}
//
//
////======================================================================================================
////Displaying the list
//
//void adminList::displayList() {
//	admin* current = head;
//	//check if is last node, else print
//	while (current != NULL) {
//		cout << "Admin ID: " << current->adminID << endl;
//		cout << "Admin Name: " << current->name << endl;
//		cout << "Admin Password: " << current->pw << endl;
//		cout << "Admin phone number: " << current->phoneNum << endl;
//		cout << "Admin email: " << current->email << endl;
//		cout << string(55, '=') << endl;
//
//		//move to next address
//		current = current->nextAdd;
//	}
//	cout << "List ended here."<<endl;
//}
//
////======================================================================================================
////Reading from file
//
//void adminList::readAdminFile()
//{
//	string filename = "admin.csv";
//	ifstream file(filename);
//
//	if (!file.is_open())
//	{
//		cout << "File " << filename << "unable to found!" << endl;
//	}
//
//	string line;
//	while (getline(file, line))
//	{
//		stringstream b(line);  // used for breaking words
//		//adminID and phoneNum changed into string to read file
//        string adminIDStr, phoneNumStr;
//        string name, pw, email;
//        getline(b, adminIDStr, ',');
//        getline(b, name, ',');
//        getline(b, pw, ',');
//        getline(b, phoneNumStr, ',');
//        getline(b, email, ',');
//
//		if (adminIDStr == "AdminID") {
//			continue;
//		}
//		if (adminIDStr == "") {
//			break;
//		}
//
//        // Convert adminIDStr and phoneNumStr to integers to insert into the list
//        int adminID = stoi(adminIDStr);
//        int phoneNum = stoi(phoneNumStr);
//
//		insertToEndOfAdminList(adminID, name, pw, phoneNum, email);
//	}
//
//	file.close();
//}
//#include "admin.h"
//#include <sstream>
//#include <cmath>
//
//
////======================================================================================================
////Creating a new node
//
//adminList::adminList(string adminListname) : adminListName(adminListName) {};
////create an empty new node
//admin* adminList::createNewNode(int adminID, string name, string pw, int phoneNum, string email) {
//	
//	admin* newnode = new admin;
//
//	newnode-> adminID = adminID;
//	newnode -> name = name;
//	newnode -> pw = pw;
//	newnode -> phoneNum = phoneNum;
//	newnode -> email = email;
//	newnode->nextAdd = NULL;
//	newnode->prevAdd = NULL;
//
//	return newnode;
//
//}
//
////======================================================================================================
////Inserting into list
//
//void adminList::insertToEndOfAdminList(int adminID, string name, string pw, int phoneNum, string email) {
//	
//	admin* newnode = createNewNode(adminID, name, pw, phoneNum, email);
//
//	if (head == NULL) {
//		head = tail = newnode;
//	}
//	else {
//		newnode->prevAdd = tail;
//		tail->nextAdd = newnode;
//		tail = newnode;
//	}
//
//}
//
//void adminList::insertToFrontOfAdminList(int adminID, string name, string pw, int phoneNum, string email)
//{
//	admin* newnode = createNewNode(adminID, name, pw, phoneNum, email);
//
//	if (head == NULL)
//	{
//		head = tail = newnode;
//	}
//	else
//	{
//		newnode->nextAdd = head;
//		head->prevAdd = newnode;
//		head = newnode;
//	}
//}
//
////======================================================================================================
////Deleting from list
//
//void adminList::deleteFromAdminList(int adminID)
//{
//	if (head == NULL)
//		return;
//	if (head->adminID == adminID)
//	{
//		admin* current = head;
//		head = head->nextAdd;
//		cout << "Deleted: Admin ID of " << current->adminID << endl;
//		delete current;
//	}
//	else if (tail->adminID == adminID)
//	{
//		admin* current = tail;
//		tail = tail->prevAdd;
//		if (tail == NULL)
//			head = NULL;
//		else
//			tail->nextAdd = NULL;
//		cout << "Deleted: Admin ID of " << current->adminID << endl;
//		delete current;
//	}
//	else
//	{
//		admin* prev = head->prevAdd;
//		admin* current = head;
//		bool found = false;
//		while (current != NULL)
//		{
//			if (current->adminID == adminID)
//			{
//				found = true;
//				prev->nextAdd = current->nextAdd;
//				cout << "Deleted: Registered User ID of " << current->adminID << endl;
//				delete current;
//				return;
//			}
//			prev = current;
//			current = current->nextAdd;
//		}
//		if(!found)
//			cout << adminID << " is not in the list!" << endl;
//	}
//}

//======================================================================================================
//Linear search

void adminList::linearsearchAndModifyAdminDetails(int adminID)
{
	if (head == NULL)
		return;

	admin* current = head;
	while (current != NULL)
	{
		if (current->adminID == adminID)
		{
			cout << "Please enter name: ";
			cin >> current->name;
			return;
		}
		current = current->nextAdd;
	}
}

void adminList::linearsearchAndDisplayAdminDetails(int choice)
{
	if (head == NULL)
		return;
	bool found = false;
	admin* current = head;
	int adminID;
	string name;
	switch (choice)
	{
	case 1:
		cout << "Enter Admin ID: ";
		cin >> adminID;
		while (current != NULL)
		{
			if (current-> adminID == adminID)
			{
				found = true;
				cout << "Admin ID:  " << current->adminID << endl;
				cout << "Name:  " << current->name << endl;
				cout << "Password:  " << current->pw << endl;
				cout << "Phone No.:  " << current->phoneNum << endl;
				cout << "Email:  " << current->email << endl;
				cout << string(55, '=') << endl;
				return;
			}
			current = current->nextAdd;
		}
		if (!found)
			cout << "User not found" << endl;
		break;
	case 2:
		cout << "Enter User Name: ";
		cin >> name;
		while (current != NULL)
		{
			if (current->name == name)
			{
				found = true;
				cout << "User ID:  " << current->adminID << endl;
				cout << "Name:  " << current->name << endl;
				cout << "Password:  " << current->pw << endl;
				cout << "Phone No.:  " << current->phoneNum << endl;
				cout << "Email:  " << current->email << endl;
				cout << string(55, '=') << endl;
				return;
			}
			current = current->nextAdd;
		}
		if (!found)
			cout << "User not found" << endl;
		break;
	}
}

//======================================================================================================
//Jump search

int adminList::Adminsize() {
	int count = 0;
	admin* current = head;
	while (current != NULL) {
		count++;
		current = current->nextAdd;
	}
	return count;
}

int adminList::AdmingetPosition(admin* node) {
	int position = 0;
	admin* current = head;

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

//int adminList::JumpSearchAdmin(const std::string& name) {
//
//
//	if (head == nullptr) {
//		std::cout << "The admin list is empty." << std::endl;
//		return -1;  // List is empty
//	}
//
//	int listSize = Adminsize();
//	int blockSize = static_cast<int>(std::sqrt(listSize));
//
//	admin* current = head;
//	admin* prev = nullptr;
//	// Finding the block where the target element belongs
//	while (current && current->name < name) {
//		prev = current;
//		for (int i = 0; current && i < blockSize; ++i) {
//			current = current->nextAdd;
//		}
//	}
//
//	// Linear search within the block
//	while (current && current->name <= name) {
//		if (current->name == name) {
//			std::cout << "The admin '" << name << "' is found in the favorite list." << std::endl;
//			return AdmingetPosition(current);
//		}
//		current = current->nextAdd;
//	}
//
//	std::cout << "The admin '" << name << "' is not found in the favorite list." << std::endl;
//	return -1;  // Target element not found
//}



//======================================================================================================
//Insert a new node in sorted way in a sorted doubly linked list
void sortedInsert(admin** head, admin* newNode, int sortCondition)
{
	admin* current;

	switch (sortCondition) {
	case 1:
		
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->adminID >= newNode-> adminID) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->adminID < newNode->adminID)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}

		break;

	case 2:
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)-> name >= newNode-> name) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd-> name < newNode-> name)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;

	case 3:
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)-> email >= newNode-> email) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd-> email < newNode-> email)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;

}
}

//======================================================================================================
//Insertion sort

void adminList::insertionSortAdminDoublyLinkedList(int sortCondition) {
	//	/*1 = adminID
	//	2 = name,
	//	3 = pw,
	//	4 = phoneNum
	//	5 = email

	//insertionSort(&head, sortCondition);
	// Initialize 'sorted' - a sorted doubly linked list
	admin* sorted = NULL;

	// Traverse the given doubly linked list and
	// insert every node to 'sorted'
	admin* current = head;
	while (current != NULL) {

		// Store next for next iteration
		admin* next = current->nextAdd;

		// removing all the links so as to create 'current'
		// as a new node for insertion
		current->prevAdd = current->nextAdd = NULL;

		// insert current in 'sorted' doubly linked list
		sortedInsert(&sorted, current, sortCondition);

		// Update current
		current = next;
	}

	// Update head_ref to point to sorted doubly linked list
	head = sorted;


}

//======================================================================================================
//Quick Sort
//From https://www.geeksforgeeks.org/quicksort-for-linked-list/

/* A utility function to swap two elements */
void adminswap ( string* a, string* b )
{ string t = *a; *a = *b; *b = t; }

void adminswap ( int* a, int* b )
{ int t = *a; *a = *b; *b = t; }

void adminswapping(admin* i, admin* j){
	adminswap(&(i->adminID), &(j->adminID));
	adminswap(&(i->name), &(j->name));
	adminswap(&(i->pw), &(j->pw));
	adminswap(&(i->phoneNum), &(j->phoneNum));
	adminswap(&(i->email), &(j->email));
}

// A utility function to find
// last node of linked list
admin *lastNode(admin *end)
{
	while (end && end->nextAdd)
		end = end->nextAdd;
	return end;
}

/* Considers last element as pivot,
places the pivot element at its
correct position in sorted array,
and places all smaller (smaller than
pivot) to left of pivot and all greater
elements to right of pivot */
admin* partition(admin *l, admin *h)
{
	// set pivot as h element
	string x = h->name;

	// similar to i = l-1 for array implementation
	admin *i = l->prevAdd;

	// Similar to "for (int j = l; j <= h- 1; j++)"
	for (admin* j = l; j != h; j = j->nextAdd)
	{
		if (j->name <= x)
		{
			// Similar to i++ for array
			i = (i == NULL)? l : i->nextAdd;

			adminswapping(i, j);
		}
	}
	i = (i == NULL)? l : i->nextAdd; // Similar to i++
	adminswapping(i, h);
	return i;
}

/* A recursive implementation
of quicksort for linked list */
void _quickSort(admin* l, admin *h)
{
	if (h != NULL && l != h && l != h->nextAdd)
	{
		admin *p = partition(l, h);
		_quickSort(l, p->prevAdd);
		_quickSort(p->nextAdd, h);
	}
}

// The main function to sort a linked list.
// It mainly calls _quickSort()
void adminList::adminQuickSort()
{
	admin* current = head;
	// Find last node
	admin *h = lastNode(current);

	// Call the recursive QuickSort
	_quickSort(current, h);
}


//======================================================================================================
//Displaying the list

void adminList::displayList() {
	admin* current = head;
	//check if is last node, else print
	while (current != NULL) {
		cout << "Admin ID: " << current->adminID << endl;
		cout << "Admin Name: " << current->name << endl;
		cout << "Admin Password: " << current->pw << endl;
		cout << "Admin phone number: " << current->phoneNum << endl;
		cout << "Admin email: " << current->email << endl;
		cout << string(55, '=') << endl;

		//move to next address
		current = current->nextAdd;
	}
	cout << "List ended here."<<endl;
}

//======================================================================================================
//Reading from file

void adminList::readAdminFile()
{
	string filename = "admin.csv";
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "File " << filename << "unable to found!" << endl;
	}

	string line;
	while (getline(file, line))
	{
		stringstream b(line);  // used for breaking words
		//adminID and phoneNum changed into string to read file
        string adminIDStr, phoneNumStr;
        string name, pw, email;
        getline(b, adminIDStr, ',');
        getline(b, name, ',');
        getline(b, pw, ',');
        getline(b, phoneNumStr, ',');
        getline(b, email, ',');

		if (adminIDStr == "AdminID") {
			continue;
		}
		if (adminIDStr == "") {
			break;
		}

        // Convert adminIDStr and phoneNumStr to integers to insert into the list
        int adminID = stoi(adminIDStr);
        int phoneNum = stoi(phoneNumStr);

		insertToEndOfAdminList(adminID, name, pw, phoneNum, email);
	}

	file.close();
}

//======================================================================================================
//Writing to file

void adminList::writeAdminFile()
{
	admin* current = head;
	ofstream file("admin.csv");
	if (!file)
	{
		cout << "File unable to open!" << endl;
	}

	while (current != nullptr)
	{
		file << current->adminID << ',' << current->name << ',' << current->pw << ',' << current->phoneNum << ',' << current->email << "\n";
		current = current->nextAdd;
	}
	file.close();
}

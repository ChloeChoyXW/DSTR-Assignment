//#include "admin.h"
//#include <sstream>
//
//using namespace std;
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
//
//	return newnode;
//
//}
//
//admin* adminList::createNewNode(int adminID, string name, string pw, int phoneNum, string email)
//{
//	admin* newnode = new admin;
//	newnode->adminID = adminID;
//	newnode->name = name;
//	newnode -> pw = pw;
//	newnode -> phoneNum = phoneNum;
//	newnode -> email = email;
//	return newnode; 
//}
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
//void adminList::linearsearchAndModifyAdminDetails(int adminID)
//{
//	if (head == NULL)
//		return;
//
//	admin* current = head;
//	while (current != NULL)
//	{
//		if (current->adminID == adminID)
//		{
//			cout << "Please enter name: ";
//			cin >> current->name;
//			return;
//		}
//		current = current->nextAdd;
//	}
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
//// function to insert a new node in sorted way in
//// a sorted doubly linked list
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
//
////======================================================================================================
////Quick Sort Algorithm
////From https://www.geeksforgeeks.org/quicksort-for-linked-list/
//
///* A utility function to swap two elements */
//void swap ( int* a, int* b )
//{ int t = *a; *a = *b; *b = t; }
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
//	int x = h->adminID;
//
//	// similar to i = l-1 for array implementation
//	admin *i = l->prevAdd;
//
//	// Similar to "for (int j = l; j <= h- 1; j++)"
//	for (admin *j = l; j != h; j = j->nextAdd)
//	{
//		if (j->adminID <= x)
//		{
//			// Similar to i++ for array
//			i = (i == NULL)? l : i->nextAdd;
//
//			swap(&(i->adminID), &(j->adminID));
//		}
//	}
//	i = (i == NULL)? l : i->nextAdd; // Similar to i++
//	swap(&(i->adminID), &(h->adminID));
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
//void adminQuickSort(admin *head)
//{
//	// Find last node
//	admin *h = lastNode(head);
//
//	// Call the recursive QuickSort
//	_quickSort(head, h);
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
//        // Convert adminIDStr and phoneNumStr to integers to insert into the list
//        int adminID = std::stoi(adminIDStr);
//        int phoneNum = std::stoi(phoneNumStr);
//
//		insertToEndOfAdminList(adminID, name, pw, phoneNum, email);
//	}
//
//	file.close();
//}

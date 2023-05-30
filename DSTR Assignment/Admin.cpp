#include "admin.h"

adminList::adminList(string adminListName) : adminListName(adminListName) {};
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



////======================================================================================================
////Linear search

void adminList::linearsearchAndModifyAdminDetails(int choice, int adminID)
{
	if (head == NULL)
		return;

	admin* current = head;
	while (current != NULL)
	{
		if (current->adminID == adminID)
		{
			switch (choice)
			{
			case 1:
			{
				cout << "Please enter name: ";
				cin.ignore();
				getline(cin, current->name);
				return;
			}
			case 2:
			{
				cout << "Please enter password: ";
				cin.ignore();
				getline(cin, current->pw);
				return;
			}
			case 3:
			{
				cout << "Please enter phone number: ";
				cin.ignore();
				getline(cin, current->phoneNum);
				return;
			}
			case 4:
			{
				cout << "Please enter email: ";
				cin.ignore();
				getline(cin, current->email);
				return;
			}
			}
		}
		current = current->nextAdd;
	}
}


////======================================================================================================
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

////======================================================================================================
////Insertion sort
//
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


////======================================================================================================
////Displaying the list
//
void adminList::displayList() {
	admin* current = head;
	//check if is last node, else print
	while (current != NULL) {
		string adminID = to_string(current->adminID);
		cout << "Admin ID: " << adminID << endl;
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

////======================================================================================================
////Reading from file

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
        string adminID, phoneNum;
        string name, pw, email;
        getline(b, adminID, ',');
        getline(b, name, ',');
        getline(b, pw, ',');
        getline(b, phoneNum, ',');
        getline(b, email, ',');

		if (adminID == "AdminID") {
			continue;
		}
		if (adminID == "") {
			break;
		}

		int adID = stoi(adminID);

		insertToEndOfAdminList(adID, name, pw, phoneNum, email);
	}

	file.close();
}

////======================================================================================================
////Writing to file

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
		string adminID = to_string(current->adminID);
		file << adminID << ',' << current->name << ',' << current->pw << ',' << current->phoneNum << ',' << current->email << "\n";
		current = current->nextAdd;
	}
	file.close();
}

int adminList::adminLogin() {

	if (head == NULL) {
		return NULL;
	}
	bool found = false;
	admin* current = head;
	string userID, name, email, pw;

	//for user login purpo
	cout << "Enter Email: ";
	cin >> email;
	cout << "Enter Password: ";
	cin >> pw;
	while (current != NULL)
	{
		if (current->email == email && current->pw == pw)
		{
			found = true;
			return current->adminID;
		}
		current = current->nextAdd;
	}
	if (!found) {
		return -1;
	}
}

int adminList::generateID() {
	
	insertionSortAdminDoublyLinkedList(1);

	if (head == NULL)
		return 1;

	admin* current = head;

	while (current->nextAdd != NULL)
		current = current->nextAdd;

	int lastID = current->adminID;
	int newID = lastID + 1;

	return newID;
}


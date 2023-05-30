#include "registeredUsers.h"


regUsersList::regUsersList(string regUsersListName) : regUsersListName(regUsersListName) {};

regUsers* regUsersList::createNewNode(int userID, string name, string pw, string phoneNum, string email)
{
	regUsers* newnode = new regUsers;
	newnode->userID = userID;
	newnode->name = name;
	newnode->phoneNum = phoneNum;
	newnode->email = email;
	newnode->pw = pw;
	newnode->nextAdd = NULL;
	newnode->prevAdd = NULL;
	return newnode;
}

void regUsersList::insertToEndOfRegUsersList(int userID, string name, string pw, string phoneNum, string email)
{
	regUsers* newnode = createNewNode(userID, name, pw, phoneNum, email);

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

void regUsersList::deleteFromRegUsersList(int userID)
{
	if (head == NULL)
		return;
	if (head->userID == userID)
	{
		regUsers* current = head;
		head = head->nextAdd;
		cout << "Deleted: Registered User ID of " << current->userID << endl;
		delete current;
	}
	else if (tail->userID == userID)
	{
		regUsers* current = tail;
		tail = tail->prevAdd;
		if (tail == NULL)
			head = NULL;
		else
			tail->nextAdd = NULL;
		cout << "Deleted: Registered User ID of " << current->userID << endl;
		delete current;
	}
	else
	{
		regUsers* prev = head->prevAdd;
		regUsers* current = head;
		bool found = false;
		while (current != NULL)
		{
			if (current->userID == userID)
			{
				found = true;
				prev->nextAdd = current->nextAdd;
				cout << "Deleted: Registered User ID of " << current->userID << endl;
				delete current;
				return;
			}
			prev = current;
			current = current->nextAdd;
		}
		if(!found)
			cout << userID << " is not in the list!" << endl;
	}
}

void regUsersList::linearsearchAndModifyRegistUsersDetails(int choice)
{
	string userName;
	int userID,  ans;
	if (head == NULL)
		return;

	regUsers* current = head;

	if (choice == 1) {
		cout << "Please Enter User ID: ";
		cin >> userID;
		while (current != NULL)
		{
			if (current->userID == userID)
			{
				while (true) {
					cout << "\nModify:\n1.Name\n2.Password\n3.Phone Number\n4.Email\n5. Exit\nChoice: ";
					cin >> ans;
					switch (ans)
					{
					case 1:
					{
						cout << "Please enter name: ";
						cin.ignore();
						getline(cin, current->name);
						cin.clear();
						break;
					}
					case 2:
					{
						cout << "Please enter password: ";
						cin >> current->pw;
						break;
					}
					case 3:
					{
						cout << "Please enter phone number: ";
						cin >> current->phoneNum;
						break;
					}
					case 4:
					{
						cout << "Please enter email: ";
						cin >> current->email;
						break;
					}
					case 5:
						return;
					}
				}
			}
			current = current->nextAdd;
		}
		cout << "User ID not found.\n" << endl;
		return;
	}
	else
	{
		cout << "Please Enter User Name: ";
		cin.ignore();
		getline(cin, userName);
		while (current != NULL)
		{
			if (current->name == userName)
			{
				while (true) {
					cout << "\nModify:\n1.Name\n2.Password\n3.Phone Number\n4.Email\n5. Exit\nChoice: ";
					cin >> ans;
					switch (ans)
					{
					case 1:
					{
						cout << "Please enter name: ";
						cin.ignore();
						getline(cin, current->name);
						cin.clear();
						break;
					}
					case 2:
					{
						cout << "Please enter password: ";
						cin >> current->pw;
						break;
					}
					case 3:
					{
						cout << "Please enter phone number: ";
						cin >> current->phoneNum;
						break;
					}
					case 4:
					{
						cout << "Please enter email: ";
						cin >> current->email;
						break;
					}
					case 5:
						return;
					}
				}
			}
			current = current->nextAdd;
		}
		cout << "User name not found.\n" << endl;
		return;
	}
}

void regUsersList::linearsearchAndDisplayRegistUsersDetails(int choice)
{
	if (head == NULL)
		return;
	bool found = false;
	regUsers* current = head;
	string name, userid;
	int userID;
	switch (choice)
	{
	case 1:
		cout << "Enter User ID: ";
		cin >> userID;
		while (current != NULL)
		{
			if (current->userID == userID)
			{
				found = true;
				userid = to_string(current->userID);
				cout << "User ID:  " << userid << endl;
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
				userid = to_string(current->userID);
				cout << "User ID:  " << userid << endl;
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


//string regUsersList::login() {
//
//	if (head == NULL) {
//		return NULL;
//	}
//	bool found = false;
//	regUsers* current = head;
//	string userID, name, email, pw;
//
//	//for user login purpo
//	cout << "Enter Email: ";
//	cin >> email;
//	cout << "Enter Password: ";
//	cin >> pw;
//	while (current != NULL)
//	{
//		if (current->email == email && current->pw == pw)
//		{
//			found = true;
//			return current->userID;
//		}
//		current = current->nextAdd;
//	}
//	if (!found){
//		return "User not found";
//	}
//}

void sortedInsert(regUsers** head, regUsers* newNode)
{
	regUsers* current;

		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->userID >= newNode->userID) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->userID < newNode->userID)
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
}

void regUsersList::insertionSortUsersDoublyLinkedList() {

	//insertionSort(&head, sortCondition);
	// Initialize 'sorted' - a sorted doubly linked list
	regUsers* sorted = NULL;

	// Traverse the given doubly linked list and
	// insert every node to 'sorted'
	regUsers* current = head;
	while (current != NULL) {

		// Store next for next iteration
		regUsers* next = current->nextAdd;

		// removing all the links so as to create 'current'
		// as a new node for insertion
		current->prevAdd = current->nextAdd = NULL;

		// insert current in 'sorted' doubly linked list
		sortedInsert(&sorted, current);

		// Update current
		current = next;
	}

	// Update head_ref to point to sorted doubly linked list
	head = sorted;


}


void regUsersList::displayRegUsersList()
{
	regUsers* current = head;

	while (current != NULL)
	{
		string userid;
		userid = to_string(current->userID);
		cout << "User ID:  " << userid << endl;
		cout << "Name:  " << current->name << endl;
		cout << "Password:  " << current->pw << endl;
		cout << "Phone No.:  " << current->phoneNum << endl;
		cout << "Email:  " << current->email << endl;
		cout << string(55, '=') << endl;

		current = current->nextAdd;
	}
	cout << "List ended here." << endl;
}


void regUsersList::readRegUsersFile()
{
	string filename = "regusers.csv";
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "File " << filename << "unable to found!" << endl;
	}

	string line;
	while (getline(file, line))
	{
		stringstream b(line);  //used for breaking words
		string userID, name, pw, phoneNum, email;
		getline(b, userID, ',');
		getline(b, name, ',');
		getline(b, pw, ',');
		getline(b, phoneNum, ',');
		getline(b, email, ',');

		int userid = stoi(userID);
		insertToEndOfRegUsersList(userid, name, pw, phoneNum, email);
	}
	file.close();
}

void regUsersList::writeRegUsersFile()
{
	regUsers* current = head;
	ofstream file("regusers.csv");
	if (!file)
	{
		cout << "File unable to open!" << endl;
	}

	while (current != nullptr)
	{
		string userid = to_string(current->userID);
		file << userid << ',' << current->name << ',' << current->pw << ',' << current->phoneNum << ',' << current->email << "\n";
		current = current->nextAdd;
	}
	file.close();
}

void regUsersList::compareAndDeleteUsers(const int* removedUserIDs, int removedCount)
{
	regUsers* current = head;
	regUsers* previous = nullptr;

	while (current != nullptr) {
		bool found = false;
		for (int i = 0; i < removedCount; ++i) {
			if (current->userID == removedUserIDs[i]) {
				found = true;
				break;
			}
		}

		if (found) {
			// Node's user ID is in the removedUserIDs array, delete the node
			regUsers* temp = current;
			if (previous == nullptr) {
				head = current->nextAdd;
				current = head;
			}
			else {
				previous->nextAdd = current->nextAdd;
				current = current->nextAdd;
			}
			delete temp;
		}
		else {
			previous = current;
			current = current->nextAdd;
		}
	}
}

int regUsersList::generateUserID() {

	insertionSortUsersDoublyLinkedList();

	if (head == NULL)
		return 1;

	regUsers* current = head;

	while (current->nextAdd != NULL)
		current = current->nextAdd;

	int lastID = current->userID;
	int newID = lastID + 1;

	return newID;
}






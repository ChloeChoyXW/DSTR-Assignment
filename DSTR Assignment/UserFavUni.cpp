#include "userFavUni.h"
#include <cmath>
#include <sstream>

using namespace std;

userFavUniList::userFavUniList(string userFavUniListName) : userFavUniListName(userFavUniListName) {};

userFavUni* userFavUniList::createNewNode(int userID, string uniName)
{
	userFavUni* newnode = new userFavUni;
	newnode->userID = userID;
	newnode->uniName = uniName;
	newnode->nextAdd = NULL;
	newnode->prevAdd = NULL;
	return newnode;
}

void userFavUniList::insertToFrontOfUserFavUniList(int userID, string uniName)
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

void userFavUniList::insertToEndOfUserFavUniList(int userID, string uniName)
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

////=====================================LINEAR SEARCH============================================

void userFavUniList::LinearSearchandDisplay(int choice) //1.User 2.Admin
{
	if (head == NULL)
		return;
	bool found = false;
	userFavUni* current = head;
	string userID, uniName;

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
				cout << "User ID:  " << current->userID << endl;
				cout << "Favourite University:\n ";
				userFavUni* user = current;
				while (user != NULL && user->userID == userID)
				{
					cout << user->uniName << endl;
					user = user->nextAdd;
				}
				cout << string(55, '=') << endl;
				
			}
			current = current->nextAdd;
		}
		if (!found)
			cout << "User not found" << endl;
		break;
	case 2:
		cout << "Enter University Name: ";
		getline(cin, uniName);
		while (current != NULL)
		{
			if (current->uniName == uniName)
			{
				found = true;
				cout << "User ID:  " << current->userID << endl;
				cout << "Favourite University:  " << current->uniName << endl;
				cout << string(55, '=') << endl;
				
			}
			current = current->nextAdd;
		}
		if (!found)
			cout << "University not found" << endl;
		break;
	}
}

void sortedInsert(userFavUni** head, userFavUni* newNode) {
	userFavUni* current;

		if (*head == NULL) {
			*head = newNode;
		}

		else if ((*head)->uniName >= newNode->uniName) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			while (current->nextAdd != NULL &&
				current->nextAdd->uniName < newNode->uniName)
				current = current->nextAdd;

			newNode->nextAdd = current->nextAdd;

			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
}


void userFavUniList::sortUserFavUniList() {
	// Initialize a sorted doubly linked list
	userFavUni* sorted = NULL;

	// Traverse the given doubly linked list and insert every node to sorted doubly linked list
	userFavUni* current = head;
	while (current != NULL) {

		// Store next for next iteration
		userFavUni* next = current->nextAdd;

		// removing all the links so as to create 'current' as a new node for insertion
		current->prevAdd = current->nextAdd = NULL;


		// insert current in 'sorted' doubly linked list
		sortedInsert(&sorted, current);

		// Update current
		current = next;
	}

	// Update head_ref to point to sorted doubly linked list
	head = sorted;
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
		insertToEndOfUserFavUniList(stoi(userID), uniName);

		int count = 0;
		if (count == 0)
		{
			count += 1;
			continue;
		}
		else if (userID == "")
		{
			break;
		}
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

void userFavUniList::generateReport()
{
	userFavUni* current = head;
	userFavUni* runner;

	std::string distinctUniversities[10];
	int counts[10] = { 0 };

	int distinctCount = 0;

	while (current != nullptr && distinctCount < 10) {
		string universityName = current->uniName;
		bool isDistinct = true;

		// Check if the university is already counted
		for (int i = 0; i < distinctCount; i++) {
			if (distinctUniversities[i] == universityName) {
				isDistinct = false;
				break;
			}
		}

		if (isDistinct) {
			int appearanceCount = 0;
			runner = head;

			while (runner != nullptr) {
				if (runner->uniName == universityName) {
					appearanceCount++;
				}

				runner = runner->nextAdd;
			}

			// Insert the new distinct university and count in the correct position
			int insertIndex = distinctCount;
			while (insertIndex > 0 && appearanceCount > counts[insertIndex - 1]) {
				distinctUniversities[insertIndex] = distinctUniversities[insertIndex - 1];
				counts[insertIndex] = counts[insertIndex - 1];
				insertIndex--;
			}

			distinctUniversities[insertIndex] = universityName;
			counts[insertIndex] = appearanceCount;

			distinctCount++;
		}

		current = current->nextAdd;
	}

	for (int i = 0; i < distinctCount; i++) {
		cout << "Top " << i+1 << " : " << distinctUniversities[i] << std::endl;
	}
}

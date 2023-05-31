#include "userFavUni.h"
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

////=====================================LINEAR SEARCH============================================

void userFavUniList::LinearSearchandDisplay(int userID)
{
	if (head == NULL)
		return;
	userFavUni* current = head;

	while (current != NULL)
	{
		if (current->userID == userID)
		{
			cout << "\nFavourite University:\n ";
			cout << current->uniName << endl;
			cout << string(55, '=') << endl;
		}
		current = current->nextAdd;
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
		cout << "Top " << i+1 << " : " << distinctUniversities[i] << endl << endl;
	}
}

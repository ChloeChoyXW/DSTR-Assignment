#include "registeredUsers.h"


regUsersList::regUsersList(string regUsersListName) : regUsersListName(regUsersListName) {};

regUsers* regUsersList::createNewNode(string userID, string name, string pw, string phoneNum, string email)
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

regUsers* regUsersList::createNewNode(string userID, tm loginTime)
{
	regUsers* newnode = new regUsers;
	newnode->userID = userID;
	newnode->loginTime = loginTime;
	return newnode; 
}

void regUsersList::insertToEndOfRegUsersList(string userID, string name, string pw, string phoneNum, string email)
{
	regUsers* newnode = createNewNode(userID, name, pw, phoneNum, email);

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

void regUsersList::insertToFrontOfRegUsersLoginList(string userID, tm loginTime)
{
	regUsers* newnode = createNewNode(userID, loginTime);

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

void regUsersList::deleteFromRegUsersList(string userID)
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

void regUsersList::linearsearchAndModifyRegistUsersDetails(string userID)
{
	if (head == NULL)
		return;

	regUsers* current = head;
	while (current != NULL)
	{
		if (current->userID == userID)
		{
			cout << "Please enter name: ";
			cin >> current->name;
			return;
		}
		current = current->nextAdd;
	}
}

void regUsersList::linearsearchAndDisplayRegistUsersDetails(int choice)
{
	if (head == NULL)
		return;
	bool found = false;
	regUsers* current = head;
	string userID, name;
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
				cout << "User ID:  " << current->userID << endl;
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

void regUsersList::sortRegUsersList(string sortCondition)
{

}


void regUsersList::displayRegUsersList()
{
	regUsers* current = head;

	while (current != NULL)
	{
		cout << "User ID:  " << current->userID << endl;
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
	head = NULL;
	string userID, name, pw, phoneNum, email;

	ifstream file("regusers.csv");

	while (file.good())
	{
		getline(file, userID, ',');
		getline(file, name, ',');
		getline(file, pw, ',');
		getline(file, phoneNum, ',');
		getline(file, email, ',');
		insertToEndOfRegUsersList(userID, name, pw, phoneNum, email);
	}

	file.close();

	//insertToEndOfRegUsersList("1", "John", "930213", "0123232", "joqdion@gmail.com");
	//insertToEndOfRegUsersList("2", "Jennie", "930213", "0123232", "4298402n@gmail.com");
	//insertToEndOfRegUsersList("3", "Jack", "930213", "0123232", "jfwfwfon@gmail.com");
}

void regUsersList::writeRegUsersFile()
{
	ofstream file("regusers.csv");
}
﻿#include "registeredUsers.h"


regUsersList::regUsersList(string regUsersListName) : regUsersListName(regUsersListName) {};

//for time & date/////////////////////////////////////////////
string getCurrentDate()
{
	time_t Date;
	struct tm DateInfo;
	char buffer[80];
	time(&Date);
	localtime_s(&DateInfo, &Date);
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", &DateInfo);
	string currentDate(buffer);
	return currentDate;
}

string getCurrentTime()
{
	time_t Time;
	struct tm timeInfo;
	char buffer[80];
	time(&Time);
	localtime_s(&timeInfo, &Time);
	strftime(buffer, sizeof(buffer), "%H:%M:%S", &timeInfo);
	string currentTime(buffer);
	return currentTime;
}

tm stringToTm(string dateTime, int x)
{
	tm timeStruct{};
	istringstream iss(dateTime);
	if (x == 1)
	{
		iss >> get_time(&timeStruct, "%Y-%m-%d");
	}
	else
	{
		iss >> get_time(&timeStruct, "%H:%M:%S");
	}
	return timeStruct;
}


string tmDateToString(const tm& date)
{
	stringstream ss;
	string format;

	format = "%Y-%m-%d";

	char buffer[80];
	std::strftime(buffer, sizeof(buffer), format.c_str(), &date);
	ss << buffer;

	return ss.str();
}

string tmTimeToString(const tm& time)
{
	stringstream ss;
	string format;

	format = "%H:%M:%S";

	char buffer[80];
	std::strftime(buffer, sizeof(buffer), format.c_str(), &time);
	ss << buffer;

	return ss.str();
}

///////////////////////////////////////////////////////////////////

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

regUsers* regUsersList::createNewNode(string userID, tm loginDate, tm loginTime)
{
	regUsers* newnode = new regUsers;
	newnode->userID = userID;
	newnode->loginDate = loginDate;
	newnode->loginTime = loginTime;
	return newnode; 
}

void regUsersList::insertToEndOfRegUsersList(string userID, string name, string pw, string phoneNum, string email)
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

void regUsersList::insertToFrontOfRegUsersLoginList(string userID, tm loginDate, tm loginTime)
{
	regUsers* newnode = createNewNode(userID, loginDate, loginTime);

	if (head == NULL)
	{
		//head = tail = newnode;
		newnode->nextAdd = NULL;
	}
	else
	{
		newnode->nextAdd = head;
		head->prevAdd = newnode;
	}
	head = newnode;
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

void regUsersList::linearsearchAndModifyRegistUsersDetails(int choice)
{
	string userID, userName;
	int ans;
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
		insertToEndOfRegUsersList(userID, name, pw, phoneNum, email);
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
		file << current->userID << ',' << current->name << ',' << current->pw << ',' << current->phoneNum << ',' << current->email << "\n";
		current = current->nextAdd;
	}
	file.close();
}

void regUsersList::readUsersLogFile()
{
	string filename = "UsersLog.csv";
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "File " << filename << "unable to found!" << endl;
	}

	string line;
	while (getline(file, line))
	{
		stringstream b(line);  //used for breaking words
		string userID, loginDate, loginTime;
		getline(b, userID, ',');
		getline(b, loginDate, ',');
		getline(b, loginTime, ',');

		tm date = stringToTm(loginDate, 1);
		tm time = stringToTm(loginTime, 2);
		insertToFrontOfRegUsersLoginList(userID, date, time);
	}
}


void regUsersList::writeUsersLogFile()
{
	regUsers* current = head;
	ofstream file("UsersLog.csv");
	if (!file)
	{
		cout << "File unable to open!" << endl;
	}

	while (current != nullptr)
	{
		string date = tmDateToString(current->loginDate);
		string time = tmTimeToString(current->loginTime);
		file << current->userID << ',' << date << ',' << time << "\n";
		current = current->nextAdd;
	}
	file.close();
}

void regUsersList::displayUsersLog()
{
	regUsers* current = head;

	while (current != NULL)
	{
		string date = tmDateToString(current->loginDate);
		string time = tmTimeToString(current->loginTime);
		cout << "User ID:  " << current->userID << endl;
		cout << "Review Date:  " << date << endl;
		cout << "Review Time:  " << time << endl;
		cout << string(55, '=') << endl;

		current = current->nextAdd;
	}
	cout << "List ended here." << endl;
}

bool checkInactive(tm date)
{
	string currentDate = getCurrentDate();
	tm cDate = stringToTm(currentDate,1);

	time_t nowDate = mktime(&cDate);
	time_t loginDate = mktime(&date);

	double difference = difftime(nowDate, loginDate);

	return (difference <= 30);
}

void deleteLoginNode(regUsers* removeNode)
{

	if (removeNode == NULL)  //node is empty
		return;

	if (removeNode->prevAdd != NULL)  //node is the head 
		removeNode->prevAdd->nextAdd = removeNode->nextAdd;
	
	if (removeNode->nextAdd != NULL)
		removeNode->nextAdd->prevAdd = removeNode->prevAdd;

	delete removeNode;
}

void regUsersList::removeInactiveUsers()
{
	readUsersLogFile();

	regUsers* current = head;
	regUsers* nextNode = NULL;

	
	while (current != NULL)
	{
		nextNode = current->nextAdd;
		bool status = checkInactive(current->loginDate);
		if (!status)
		{
			cout << "Delete User" << current->userID << endl;
			deleteLoginNode(current);
		}
		current = nextNode;
	}
	cout << "Delete Complete!\n" << endl;
}


void regUsersList::userLoginlog(string userID)  
{
	string currentDate = getCurrentDate();
	string currentTime = getCurrentTime();
	tm date = stringToTm(currentDate, 1);
	tm time = stringToTm(currentTime, 2);
	insertToFrontOfRegUsersLoginList(userID, date, time);
}



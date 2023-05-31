#include"usersloginrecord.h"


loginRecordList::loginRecordList(string loginRecordListName) : loginRecordListName(loginRecordListName) {};

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

loginRecord* loginRecordList::createNewNode(int userID, tm loginDate, tm loginTime)
{
	loginRecord* newnode = new loginRecord;
	newnode->userID = userID;
	newnode->loginDate = loginDate;
	newnode->loginTime = loginTime;
	return newnode;
}

void loginRecordList::insertToFrontOfRegUsersLoginList(int userID, tm loginDate, tm loginTime)
{
	loginRecord* newnode = createNewNode(userID, loginDate, loginTime);

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

void loginRecordList::readUsersLogFile()
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
		int userid = stoi(userID);
		insertToFrontOfRegUsersLoginList(userid, date, time);
	}
}

void loginRecordList::writeUsersLogFile()
{
	loginRecord* current = head;
	ofstream file("UsersLog.csv");
	if (!file)
	{
		cout << "File unable to open!" << endl;
	}

	while (current != nullptr)
	{
		string date = tmDateToString(current->loginDate);
		string time = tmTimeToString(current->loginTime);
		string userid = to_string(current->userID);
		file << userid << ',' << date << ',' << time << "\n";
		current = current->nextAdd;
	}
	file.close();
}

void loginRecordList::displayUsersLog()
{
	loginRecord* current = head;

	while (current != NULL)
	{
		string date = tmDateToString(current->loginDate);
		string time = tmTimeToString(current->loginTime);
		string userid = to_string(current->userID);
		cout << "User ID:  " << userid << endl;
		cout << "Review Date:  " << date << endl;
		cout << "Review Time:  " << time << endl;
		cout << string(55, '=') << endl;

		current = current->nextAdd;
	}
	cout << "List ended here." << endl;
}

void loginRecordList::deleteLoginNode(loginRecord* nodeToDelete)
{
	if (nodeToDelete == head)
	{
		head = head->nextAdd;
		delete nodeToDelete;
	}
	else
	{
		loginRecord* current = head;
		loginRecord* previous = NULL;
		while (current != NULL && current != nodeToDelete)
		{
			previous = current;
			current = current->nextAdd;
		}
		if (current == NULL)
		{
			cout << "Node not found." << endl;
			return;
		}
		if (previous != NULL) // Check if previous is not NULL
		{
			previous->nextAdd = current->nextAdd;
		}
		delete current;
	}
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

void loginRecordList::deleteLoginNode(loginRecord* nodeToDelete)
{
	if (nodeToDelete == head)
	{
		head = head->nextAdd;
		delete nodeToDelete;
	}
	else
	{
		loginRecord* current = head;
		loginRecord* previous = NULL;
		while (current != NULL && current != nodeToDelete)
		{
			previous = current;
			current = current->nextAdd;
		}
		if (current == NULL)
		{
			cout << "Node not found." << endl;
			return;
		}
		if (previous != NULL) // Check if previous is not NULL
		{
			previous->nextAdd = current->nextAdd;
		}
		delete current;
	}
}

int* loginRecordList::removeInactiveUsers(int& removedCount) {
	int size = 10; // Initial size of the array
	int* userRemove = new int[size];
	removedCount = 0;
	int currentSize = size;

	loginRecord* current = head;
	loginRecord* nextNode = NULL;

	if (head == NULL) {
		cout << "User list is empty." << endl;
		return userRemove;
	}

	while (current != NULL) {
		nextNode = current->nextAdd;
		bool status = checkInactive(current->loginDate);
		if (!status) {
			string userid = to_string(current->userID);
			cout << "Delete User " << userid << endl;

			if (removedCount == currentSize) {
				// Array is full, resize it
				currentSize *= 2;
				int* newRemovedUser = new int[currentSize];
				for (int i = 0; i < removedCount; ++i) {
					newRemovedUser[i] = userRemove[i];
				}
				delete[] userRemove;
				userRemove = newRemovedUser;
			}

			// Add the new removed user ID to the array
			userRemove[removedCount] = current->userID;
			++removedCount;

			deleteLoginNode(current);
		}
		current = nextNode;
	}

	cout << "Delete Complete!\n" << endl;

	return userRemove;
}

void loginRecordList::userLoginlog(int userID)
{
	string currentDate = getCurrentDate();
	string currentTime = getCurrentTime();
	tm date = stringToTm(currentDate, 1);
	tm time = stringToTm(currentTime, 2);

	loginRecord* current = head;
	while (current != NULL)
	{
		if (current->userID == userID)
		{
			current->loginDate = date;
			current->loginTime = time;
			return;
		}
		current = current->nextAdd;
	}
	insertToFrontOfRegUsersLoginList(userID, date, time);
}

#include"userUniReview.h"

userUniReviewList::userUniReviewList(string regUsersListName) : userUniReviewListName(userUniReviewListName) {};

//for time & date/////////////////////////////////////////////
string getReviewCurrentDate()
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

string getReviewCurrentTime()
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

tm stringReviewToTm(string dateTime, int x)
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


string tmRDateToString(const tm& date)
{
	stringstream ss;
	string format;

	format = "%Y-%m-%d";

	char bufferR[80];
	std::strftime(bufferR, sizeof(bufferR), format.c_str(), &date);
	ss << bufferR;

	return ss.str();
}

string tmRTimeToString(const tm& time)
{
	stringstream ss;
	string format;

	format = "%H:%M:%S";

	char bufferR[80];
	std::strftime(bufferR, sizeof(bufferR), format.c_str(), &time);
	ss << bufferR;

	return ss.str();
}
///////////////////////////////////////////////////////////////////

userUniReview* userUniReviewList::createNewNode(string userID, string uniName,  string userReview, tm reviewDate, tm reviewTime, string adminReply)
{
	userUniReview* newnode = new userUniReview;
	newnode->userID = userID;
	newnode->uniName = uniName;
	newnode->userReview = userReview;
	newnode->reviewDate = reviewDate;
	newnode->reviewTime = reviewTime;
	newnode->adminReply = adminReply;
	newnode->nextAdd = NULL;
	newnode->prevAdd = NULL;
	return newnode;
}

void userUniReviewList::insertToEndOfUserUniReviewList(string userID, string uniName, string userReview, tm reviewDate, tm reviewTime, string adminReply)
{
	 userUniReview* newnode = createNewNode(userID, uniName, userReview, reviewDate, reviewTime, adminReply);

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

void userUniReviewList::deleteFromUserUniReviewList(string userID, string uniName)
{
	if (head == NULL)
		return;

	if (head->userID == userID && head->uniName == uniName)
	{
		userUniReview* current = head;
		head = head->nextAdd;
		cout << "Deleted: Registered User ID of " << current->userID << endl;
		delete current;
	}
	else if (tail->userID == userID && tail->uniName == uniName)
	{
		userUniReview* current = tail;
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
		userUniReview* prev = head->prevAdd;
		userUniReview* current = head;
		bool found = false;
		while (current != NULL)
		{
			if (current->userID == userID && current->uniName == uniName)
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
		if (!found)
			cout << userID << " is not in the list!" << endl;
	}
}

void userUniReviewList::sortUserUniReviewList(string sortCondition)
{

}

void userUniReviewList::searchAndModifyUserUniReviewList(string userID, string uniName)
{
	if (head == NULL)
		return;

	userUniReview* current = head;
	while (current != NULL)
	{
		if (current->userID == userID)
		{
			cout << "Please your feedback: ";
			cin >> current->adminReply;
			return;
		}
		current = current->nextAdd;
	}
}

void userUniReviewList::searchAndDisplayUserUniReviewList(int choice)
{
	if (head == NULL)
		return;
	bool found = false;
	userUniReview* current = head;
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
				string date = tmRDateToString(current->reviewDate);
				string time = tmRTimeToString(current->reviewTime);
				cout << "User ID:  " << current->userID << endl;
				cout << "University Name:  " << current->uniName << endl;
				cout << "User Review:  " << current->userReview << endl;
				cout << "Review Date:  " << date << endl;
				cout << "Review Time:  " << time << endl;
				cout << "Admin Reply:  " << current->adminReply << endl;
				cout << string(55, '=') << endl;
				return;
			}
			current = current->nextAdd;
		}
		if (!found)
			cout << "User not found" << endl;
		break;
	case 2:
		cout << "Enter University Name: ";
		cin >> name;
		while (current != NULL)
		{
			if (current->uniName == name)
			{
				string date = tmRDateToString(current->reviewDate);
				string time = tmRTimeToString(current->reviewTime);
				cout << "User ID:  " << current->userID << endl;
				cout << "University Name:  " << current->uniName << endl;
				cout << "User Review:  " << current->userReview << endl;
				cout << "Review Date:  " << date << endl;
				cout << "Review Time:  " << time << endl;
				cout << "Admin Reply:  " << current->adminReply << endl;
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

void userUniReviewList::displayUserUniReviewList()
{
	userUniReview* current = head;

	while (current != NULL)
	{
		string date = tmRDateToString(current->reviewDate);
		string time = tmRTimeToString(current->reviewTime);
		cout << "User ID:  " << current->userID << endl;
		cout << "University Name:  " << current->uniName << endl;
		cout << "User Review:  " << current->userReview << endl;
		cout << "Review Timw:  " << date << endl;
		cout << "Review Timw:  " << time << endl;
		cout << "Admin Reply:  " << current->adminReply << endl;
		cout << string(55, '=') << endl;

		current = current->nextAdd;
	}
	cout << "List ended here.\n" << endl;
}

void displaySingleReview(userUniReview* node)
{
	userUniReview* current = node;
	string date = tmRDateToString(current->reviewDate);
	string time = tmRTimeToString(current->reviewTime);
	cout << "User ID:  " << current->userID << endl;
	cout << "University Name:  " << current->uniName << endl;
	cout << "User Review:  " << current->userReview << endl;
	cout << "Review Timw:  " << date << endl;
	cout << "Review Timw:  " << time << endl;
	cout << "Admin Reply:  " << current->adminReply << endl;
	cout << string(55, '=') << endl;
}

void userUniReviewList::moveForthBackReviewList()
{
	readUserUniReviewFile();
	userUniReview* current = head;

	const int KEY_LEFT = 75;
	const int KEY_RIGHT = 77;
	const int KEY_EXIT = 27;

	displaySingleReview(current);

	char key = 0; 

	while (current != nullptr && key != KEY_EXIT )
	{
		cout << "Use left and right arrow to move back and forth\n\n";
		int key = _getch();

		if (key == 0 || key == 224) {
			key = _getch();

			if (key == KEY_LEFT)
			{
				if (current->prevAdd != nullptr) {
					current = current->prevAdd;
					displaySingleReview(current);
				}
				else
					cout << "No more prevous review." << endl;
			}
			else if (key == KEY_RIGHT)
			{
				if (current->nextAdd != nullptr) {
					current = current->nextAdd;
					displaySingleReview(current);
				}
				else
					cout << "No more next review." << endl;
			}
		}
	}
}

void userUniReviewList::readUserUniReviewFile()
{
	string filename = "userUniReview.csv";
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "File " << filename << "unable to found!" << endl;
	}

	string line;
	while (getline(file, line))
	{
		stringstream b(line);  //used for breaking words
		string userID, uniName, userReview, reviewDate, reviewTime, adminReply;
		getline(b, userID, ',');
		getline(b, uniName, ',');
		getline(b, userReview, ',');
		getline(b, reviewDate, ',');
		getline(b, reviewTime, ',');
		getline(b, adminReply, ',');

		tm date = stringReviewToTm(reviewDate, 1);
		tm time = stringReviewToTm(reviewTime, 2);
		insertToEndOfUserUniReviewList(userID, uniName, userReview, date, time, adminReply);
	}

	file.close();
}

void userUniReviewList::writeUserUniReviewFile()
{
	userUniReview* current = head;
	ofstream file("userUniReview.csv");
	if (!file)
	{
		cout << "File unable to open!" << endl;
	}

	while (current != nullptr)
	{
		string date = tmRDateToString(current->reviewDate);
		string time = tmRTimeToString(current->reviewTime);

		file << current->userID << ',' << current->uniName << ',' << current->userReview << ',' << date << ',' << time << ',' << current->adminReply << "\n";
		current = current->nextAdd;
	}
	file.close();
}

void userUniReviewList::writeUniReview(string userID, string uniName)
{
	string review;
	cout << "Please write you review: ";       
	cin.ignore();
	getline(cin, review);
	cout << review;


	string currentDate = getReviewCurrentDate();
	string currentTime = getReviewCurrentTime();
	tm date = stringReviewToTm(currentDate, 1);
	tm time = stringReviewToTm(currentTime, 2);
	insertToEndOfUserUniReviewList(userID, uniName, review, date, time, "");
}


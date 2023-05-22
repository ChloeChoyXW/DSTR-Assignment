#include"userUniReview.h"

userUniReviewList::userUniReviewList(string regUsersListName) : userUniReviewListName(userUniReviewListName) {};

userUniReview* userUniReviewList::createNewNode(string userID, string uniName, string userReview, tm reviewTime, string adminReply)
{
	userUniReview* newnode = new userUniReview;
	newnode->userID = userID;
	newnode->uniName = uniName;
	newnode->userReview = userReview;
	newnode->reviewTime = reviewTime;
	newnode->adminReply = adminReply;
	newnode->nextAdd = NULL;
	newnode->prevAdd = NULL;
	return newnode;
}

void userUniReviewList::insertToEndOfUserUniReviewList(string userID, string uniName, string userReview, tm reviewTime, string adminReply)
{
	 userUniReview* newnode = createNewNode(userID, uniName, userReview, reviewTime, adminReply);

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
				tm timeStruct{};
				char buffer[9];
				strftime(buffer, sizeof(buffer), "%H:%M:%S", &current->reviewTime);
				string time(buffer);
				cout << "User ID:  " << current->userID << endl;
				cout << "University Name:  " << current->uniName << endl;
				cout << "User Review:  " << current->userReview << endl;
				cout << "Review Timw:  " << time << endl;
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
				found = true;
				tm timeStruct{};
				char buffer[9];
				strftime(buffer, sizeof(buffer), "%H:%M:%S", &current->reviewTime);
				string time(buffer);
				cout << "User ID:  " << current->userID << endl;
				cout << "University Name:  " << current->uniName << endl;
				cout << "User Review:  " << current->userReview << endl;
				cout << "Review Timw:  " << time << endl;
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
		tm timeStruct{};
		char buffer[9];
		strftime(buffer, sizeof(buffer), "%H:%M:%S", &current->reviewTime);
		string time(buffer);
		cout << "User ID:  " << current->userID << endl;
		cout << "University Name:  " << current->uniName << endl;
		cout << "User Review:  " << current->userReview << endl;
		cout << "Review Timw:  " << time << endl;
		cout << "Admin Reply:  " << current->adminReply << endl;
		cout << string(55, '=') << endl;

		current = current->nextAdd;
	}
	cout << "List ended here." << endl;
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
		string userID, uniName, userReview, reviewTime, adminReply;
		getline(b, userID, ',');
		getline(b, uniName, ',');
		getline(b, userReview, ',');
		getline(b, reviewTime, ',');
		getline(b, adminReply, ',');

		tm timeStruct{};
		istringstream iss(reviewTime);
		iss >> get_time(&timeStruct, "%H:%M:%S");
		insertToEndOfUserUniReviewList(userID, uniName, userReview, timeStruct, adminReply);
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
		tm timeStruct{};
		char buffer[9];
		strftime(buffer, sizeof(buffer), "%H:%M:%S", &current->reviewTime);
		string time(buffer);
		file << current->userID << ',' << current->uniName << ',' << current->userReview << ',' << time << ',' << current->adminReply << "\n";
		current = current->nextAdd;
	}
	file.close();
}
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

userUniReview* userUniReviewList::createNewNode(int userID, string uniName,  string userReview, tm reviewDate, tm reviewTime, string adminReply, tm replyDate, tm replyTime)
{
	userUniReview* newnode = new userUniReview;
	newnode->userID = userID;
	newnode->uniName = uniName;
	newnode->userReview = userReview;
	newnode->reviewDate = reviewDate;
	newnode->reviewTime = reviewTime;
	newnode->adminReply = adminReply;
	newnode->replyDate = replyDate;
	newnode->replyTime = replyTime;
	newnode->nextAdd = NULL;
	newnode->prevAdd = NULL;
	return newnode;
}

void userUniReviewList::insertToEndOfUserUniReviewList(int userID, string uniName, string userReview, tm reviewDate, tm reviewTime, string adminReply, tm replyDate, tm replyTime)
{
	 userUniReview* newnode = createNewNode(userID, uniName, userReview, reviewDate, reviewTime, adminReply, replyDate, replyTime);

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

void userUniReviewList::deleteFromUserUniReviewList(int userID, string uniName)
{
	if (head == NULL)
		return;

	if (head->userID == userID && head->uniName == uniName)
	{
		userUniReview* current = head;
		head = head->nextAdd;
		string userid = to_string(current->userID);
		cout << "Deleted: Registered User ID of " << userid << endl;
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
		string userid = to_string(current->userID);
		cout << "Deleted: Registered User ID of " << userid << endl;
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
				string userid = to_string(current->userID);
				cout << "Deleted: Registered User ID of " << userid << endl;
				delete current;
				return;
			}
			prev = current;
			current = current->nextAdd;
		}
		if (!found)
			cout << to_string(userID) << " is not in the list!" << endl;
	}
}

int compareDates(const struct tm& date1, const struct tm& date2) {
	if (date1.tm_year < date2.tm_year)
		return -1;
	else if (date1.tm_year > date2.tm_year)
		return 1;

	if (date1.tm_mon < date2.tm_mon)
		return -1;
	else if (date1.tm_mon > date2.tm_mon)
		return 1;

	if (date1.tm_mday < date2.tm_mday)
		return -1;
	else if (date1.tm_mday > date2.tm_mday)
		return 1;

	return 0;
}

void sortedInsert(userUniReview** head, userUniReview* newNode) {
	userUniReview* current;

	if (*head == NULL) {
		*head = newNode;
	}
	else if (compareDates((*head)->reviewDate, newNode->reviewDate) <= 0) {
		newNode->nextAdd = *head;
		newNode->nextAdd->prevAdd = newNode;
		*head = newNode;
	}
	else {
		current = *head;

		while (current->nextAdd != NULL && compareDates(current->nextAdd->reviewDate, newNode->reviewDate) > 0)
			current = current->nextAdd;

		newNode->nextAdd = current->nextAdd;

		if (current->nextAdd != NULL)
			newNode->nextAdd->prevAdd = newNode;

		current->nextAdd = newNode;
		newNode->prevAdd = current;
	}
}

void userUniReviewList::sortReviewDateList() {
	// Initialize a sorted doubly linked list
	userUniReview* sorted = NULL;

	// Traverse the given doubly linked list and insert every node to sorted doubly linked list
	userUniReview* current = head;
	while (current != NULL) {

		// Store next for next iteration
		userUniReview* next = current->nextAdd;

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


void userUniReviewList::searchAndAdminReplyUniReviewList(int userID, string uniName)
{
	bool found = false;

	userUniReview* current = head;

	if (head == NULL)
		return;

	while (current != NULL)
	{
		if (current->userID == userID && current->uniName == uniName)
		{
			found = true;
			cout << "Please your feedback: ";
			getline(cin, current->adminReply);
			cin.ignore();
			string currentDate = getReviewCurrentDate();
			string currentTime = getReviewCurrentTime();
			tm dateAdmin = stringReviewToTm(currentDate, 1);
			tm timeAdmin = stringReviewToTm(currentTime, 2);
			current->replyDate = dateAdmin;
			current->replyTime = timeAdmin;
			return;
		}
		current = current->nextAdd;
	}
	if (!found) {
		cout << "Record Not Found!\n\n";
		return;
	}
}

void userUniReviewList::searchAndDisplayUserUniReviewList(string uniname)
{
	if (head == NULL)
		return;
	bool found = false;
	userUniReview* current = head;
	string userID, name;
	while (current != NULL) {
		tm emptyDate = {};
		tm emptyTime = {};

		bool replyEmpty = (current->replyDate.tm_year == emptyDate.tm_year &&
			current->replyDate.tm_mon == emptyDate.tm_mon &&
			current->replyDate.tm_mday == emptyDate.tm_mday &&
			current->replyTime.tm_hour == emptyTime.tm_hour &&
			current->replyTime.tm_min == emptyTime.tm_min &&
			current->replyTime.tm_sec == emptyTime.tm_sec);

		if (!replyEmpty) {
			string date = tmRDateToString(current->reviewDate);
			string time = tmRTimeToString(current->reviewTime);
			string dateAdmin = tmRDateToString(current->replyDate);
			string timeAdmin = tmRTimeToString(current->replyTime);
			string userid = to_string(current->userID);
			cout << "User ID:  " << userid << endl;
			cout << "University Name:  " << current->uniName << endl;
			cout << "User Review:  " << current->userReview << endl;
			cout << "Review Timw:  " << date << endl;
			cout << "Review Timw:  " << time << endl;
			cout << "Admin Reply:  " << current->adminReply << endl;
			cout << "Reply Date:  " << dateAdmin << endl;
			cout << "Reply Time:  " << timeAdmin << endl;
		}
		else {
			string date = tmRDateToString(current->reviewDate);
			string time = tmRTimeToString(current->reviewTime);
			string userid = to_string(current->userID);
			cout << "User ID:  " << userid << endl;
			cout << "University Name:  " << current->uniName << endl;
			cout << "User Review:  " << current->userReview << endl;
			cout << "Review Timw:  " << date << endl;
			cout << "Review Timw:  " << time << endl;
			cout << "Admin Reply:  " << current->adminReply << endl;
			cout << "Reply Date:  " << "" << endl;
			cout << "Reply Time:  " << "" << endl;
		}
		current = current->nextAdd;
	}
		if (!found)
			cout << "User not found" << endl;
}

void userUniReviewList::displayUserUniReviewList()
{
	userUniReview* current = head;

	while (current != NULL)
	{
		tm emptyDate = {};
		tm emptyTime = {};

		bool replyEmpty = (current->replyDate.tm_year == emptyDate.tm_year &&
			current->replyDate.tm_mon == emptyDate.tm_mon &&
			current->replyDate.tm_mday == emptyDate.tm_mday &&
			current->replyTime.tm_hour == emptyTime.tm_hour &&
			current->replyTime.tm_min == emptyTime.tm_min &&
			current->replyTime.tm_sec == emptyTime.tm_sec);

		if (!replyEmpty) {
			string date = tmRDateToString(current->reviewDate);
			string time = tmRTimeToString(current->reviewTime);
			string dateAdmin = tmRDateToString(current->replyDate);
			string timeAdmin = tmRTimeToString(current->replyTime);
			string userid = to_string(current->userID);
			cout << "User ID:  " << userid << endl;
			cout << "University Name:  " << current->uniName << endl;
			cout << "User Review:  " << current->userReview << endl;
			cout << "Review Timw:  " << date << endl;
			cout << "Review Timw:  " << time << endl;
			cout << "Admin Reply:  " << current->adminReply << endl;
			cout << "Reply Date:  " << dateAdmin << endl;
			cout << "Reply Time:  " << timeAdmin << endl;
		}
		else {
			string date = tmRDateToString(current->reviewDate);
			string time = tmRTimeToString(current->reviewTime);
			string userid = to_string(current->userID);
			cout << "User ID:  " << userid << endl;
			cout << "University Name:  " << current->uniName << endl;
			cout << "User Review:  " << current->userReview << endl;
			cout << "Review Timw:  " << date << endl;
			cout << "Review Timw:  " << time << endl;
			cout << "Admin Reply:  " << current->adminReply << endl;
			cout << "Reply Date:  " << "" << endl;
			cout << "Reply Time:  " << "" << endl;
		}

		cout << string(55, '=') << endl;

		current = current->nextAdd;
	}
	cout << "List ended here.\n" << endl;
}

void userUniReviewList::displayNoReplyReviewList()
{
	userUniReview* current = head;

	while (current != NULL)
	{
		tm emptyDate = {};
		tm emptyTime = {};

		bool replyEmpty = (current->replyDate.tm_year == emptyDate.tm_year &&
			current->replyDate.tm_mon == emptyDate.tm_mon &&
			current->replyDate.tm_mday == emptyDate.tm_mday &&
			current->replyTime.tm_hour == emptyTime.tm_hour &&
			current->replyTime.tm_min == emptyTime.tm_min &&
			current->replyTime.tm_sec == emptyTime.tm_sec);

		if (!replyEmpty) {
			current = current->nextAdd;
		}
		else {
			string date = tmRDateToString(current->reviewDate);
			string time = tmRTimeToString(current->reviewTime);
			string userid = to_string(current->userID);
			cout << "User ID:  " << userid << endl;
			cout << "University Name:  " << current->uniName << endl;
			cout << "User Review:  " << current->userReview << endl;
			cout << "Review Timw:  " << date << endl;
			cout << "Review Timw:  " << time << endl;
			cout << "Admin Reply:  " << current->adminReply << endl;
			cout << "Reply Date:  " << "" << endl;
			cout << "Reply Time:  " << "" << endl;
		}

		cout << string(55, '=') << endl;

		current = current->nextAdd;
	}
	cout << "List ended here.\n" << endl;
}

void displaySingleReview(userUniReview* node)
{
	if (node == NULL) {
		cout << "Empty review" << endl;
		cout << string(55, '=') << endl;
		return;
	}

	userUniReview* current = node;
	tm emptyDate = {};
	tm emptyTime = {};

	bool replyEmpty = (current->replyDate.tm_year == emptyDate.tm_year &&
		current->replyDate.tm_mon == emptyDate.tm_mon &&
		current->replyDate.tm_mday == emptyDate.tm_mday &&
		current->replyTime.tm_hour == emptyTime.tm_hour &&
		current->replyTime.tm_min == emptyTime.tm_min &&
		current->replyTime.tm_sec == emptyTime.tm_sec);

	if (!replyEmpty) {
		string date = tmRDateToString(current->reviewDate);
		string time = tmRTimeToString(current->reviewTime);
		string dateAdmin = tmRDateToString(current->replyDate);
		string timeAdmin = tmRTimeToString(current->replyTime);
		string userid = to_string(current->userID);
		cout << "User ID:  " << userid << endl;
		cout << "University Name:  " << current->uniName << endl;
		cout << "User Review:  " << current->userReview << endl;
		cout << "Review Timw:  " << date << endl;
		cout << "Review Timw:  " << time << endl;
		cout << "Admin Reply:  " << current->adminReply << endl;
		cout << "Reply Date:  " << dateAdmin << endl;
		cout << "Reply Time:  " << timeAdmin << endl;
	}
	else {
		string date = tmRDateToString(current->reviewDate);
		string time = tmRTimeToString(current->reviewTime);
		string userid = to_string(current->userID);
		cout << "User ID:  " << userid << endl;
		cout << "University Name:  " << current->uniName << endl;
		cout << "User Review:  " << current->userReview << endl;
		cout << "Review Timw:  " << date << endl;
		cout << "Review Timw:  " << time << endl;
		cout << "Admin Reply:  " << current->adminReply << endl;
		cout << "Reply Date:  " << "" << endl;
		cout << "Reply Time:  " << "" << endl;
	}

	cout << string(55, '=') << endl;
}


void userUniReviewList::moveForthBackReviewList()
{
	userUniReview* current = head;

	const int KEY_LEFT = 75;
	const int KEY_RIGHT = 77;
	const int KEY_EXIT = 13;

	displaySingleReview(current);

	char key = 0; 

	while (current != nullptr)
	{
		cout << "Use left and right arrow to move back and forth (Press ENTER to exit)\n\n";
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
		else if (key == KEY_EXIT)
			break;
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
		string userID, uniName, userReview, reviewDate, reviewTime, adminFeedback, replyDate, replyTime;
		getline(b, userID, ',');
		getline(b, uniName, ',');
		getline(b, userReview, ',');
		getline(b, reviewDate, ',');
		getline(b, reviewTime, ',');
		getline(b, adminFeedback, ',');
		getline(b, replyDate, ',');
		getline(b, replyTime, ',');
		
		int userid;
		string adminReply;
		tm date, time, dateAdmin, timeAdmin;
		if (userID.empty())
			return;

		if (replyDate.empty() && replyTime.empty())
		{
			date = stringReviewToTm(reviewDate, 1);
			time = stringReviewToTm(reviewTime, 2);
			dateAdmin = {};
			timeAdmin = {};
			userid = stoi(userID);
			adminReply = "";
		}
		else
		{
			date = stringReviewToTm(reviewDate, 1);
			time = stringReviewToTm(reviewTime, 2);
			dateAdmin = stringReviewToTm(replyDate, 1);
			timeAdmin = stringReviewToTm(replyTime, 2);
			userid = stoi(userID);
			adminReply = adminFeedback;
		}
	
		insertToEndOfUserUniReviewList(userid, uniName, userReview, date, time, adminReply, dateAdmin, timeAdmin);
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
		string  userid, date, time, dateAdmin, timeAdmin;
		tm emptyDate = {};
		tm emptyTime = {};

		bool replyEmpty = (current->replyDate.tm_year == emptyDate.tm_year &&
			current->replyDate.tm_mon == emptyDate.tm_mon &&
			current->replyDate.tm_mday == emptyDate.tm_mday &&
			current->replyTime.tm_hour == emptyTime.tm_hour &&
			current->replyTime.tm_min == emptyTime.tm_min &&
			current->replyTime.tm_sec == emptyTime.tm_sec);

		if (!replyEmpty) {
			date = tmRDateToString(current->reviewDate);
			time = tmRTimeToString(current->reviewTime);
			dateAdmin = tmRDateToString(current->replyDate);
			timeAdmin = tmRTimeToString(current->replyTime);
			userid = to_string(current->userID);
		}
		else {
			date = tmRDateToString(current->reviewDate);
			time = tmRTimeToString(current->reviewTime);
			dateAdmin = "";
			timeAdmin = "";
			userid = to_string(current->userID);
		}

		file << userid << ',' << current->uniName << ',' << current->userReview << ',' << date << ',' << time << ',' << current->adminReply << ',' << dateAdmin << ',' << timeAdmin << "\n";
		current = current->nextAdd;
	}
	file.close();
}

void userUniReviewList::writeUniReview(int userID, string uniName)
{
	string review;
	cout << "Please write you review: ";       
	cin.ignore();
	getline(cin, review);
	cout << review;

	tm emptyDate = {};
	tm emptyTime = {};
	string currentDate = getReviewCurrentDate();
	string currentTime = getReviewCurrentTime();
	tm date = stringReviewToTm(currentDate, 1);
	tm time = stringReviewToTm(currentTime, 2);

	insertToEndOfUserUniReviewList(userID, uniName, review, date, time, "", emptyDate, emptyTime);
}

void userUniReviewList::displayNoReplyUniReviewList()
{

	if (head == NULL)
		return;


	userUniReview* current = head;
	string userID, name;
	while (current != NULL) {
		tm emptyDate = {};
		tm emptyTime = {};

		bool replyEmpty = (current->replyDate.tm_year == emptyDate.tm_year &&
			current->replyDate.tm_mon == emptyDate.tm_mon &&
			current->replyDate.tm_mday == emptyDate.tm_mday &&
			current->replyTime.tm_hour == emptyTime.tm_hour &&
			current->replyTime.tm_min == emptyTime.tm_min &&
			current->replyTime.tm_sec == emptyTime.tm_sec);

		if (!replyEmpty) {
			string date = tmRDateToString(current->reviewDate);
			string time = tmRTimeToString(current->reviewTime);
			string dateAdmin = tmRDateToString(current->replyDate);
			string timeAdmin = tmRTimeToString(current->replyTime);
			string userid = to_string(current->userID);
			cout << "User ID:  " << userid << endl;
			cout << "University Name:  " << current->uniName << endl;
			cout << "User Review:  " << current->userReview << endl;
			cout << "Review Timw:  " << date << endl;
			cout << "Review Timw:  " << time << endl;
			cout << "Admin Reply:  " << current->adminReply << endl;
			cout << "Reply Date:  " << dateAdmin << endl;
			cout << "Reply Time:  " << timeAdmin << endl;
		}
		current = current->nextAdd;
	}
}

void userUniReviewList::displayRepliedreview(int userID)
{
	sortReviewDateList();

	if (head == NULL)
		return;


	userUniReview* current = head;
	string name;
	while (current != NULL) {
		tm emptyDate = {};
		tm emptyTime = {};

		bool replyEmpty = (current->replyDate.tm_year == emptyDate.tm_year &&
			current->replyDate.tm_mon == emptyDate.tm_mon &&
			current->replyDate.tm_mday == emptyDate.tm_mday &&
			current->replyTime.tm_hour == emptyTime.tm_hour &&
			current->replyTime.tm_min == emptyTime.tm_min &&
			current->replyTime.tm_sec == emptyTime.tm_sec);

		if (!replyEmpty && current->userID == userID) {
			string date = tmRDateToString(current->reviewDate);
			string time = tmRTimeToString(current->reviewTime);
			string dateAdmin = tmRDateToString(current->replyDate);
			string timeAdmin = tmRTimeToString(current->replyTime);
			string userid = to_string(current->userID);
			cout << "User ID:  " << userid << endl;
			cout << "University Name:  " << current->uniName << endl;
			cout << "User Review:  " << current->userReview << endl;
			cout << "Review Timw:  " << date << endl;
			cout << "Review Timw:  " << time << endl;
			cout << "Admin Reply:  " << current->adminReply << endl;
			cout << "Reply Date:  " << dateAdmin << endl;
			cout << "Reply Time:  " << timeAdmin << endl;
		}
		current = current->nextAdd;
	}
}



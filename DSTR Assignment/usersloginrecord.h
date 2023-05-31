#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <string>
#include <chrono>
using namespace std;

struct loginRecord {
	int userID;
	tm loginDate;
	tm loginTime;
	loginRecord* nextAdd;
	loginRecord* prevAdd;
};

class loginRecordList {
	loginRecord* head = NULL;
	loginRecord* tail = NULL;
	string loginRecordListName = "";

public:
	loginRecordList(string loginRecordListName);

	loginRecord* createNewNode(int userID, tm loginDate, tm loginTime);

	void insertToFrontOfRegUsersLoginList(int userID, tm loginDate, tm loginTime);

	void readUsersLogFile();

	void writeUsersLogFile();

	void displayUsersLog();

	int* removeInactiveUsers(int& removedCount);

	void userLoginlog(int userID); //used to stored users' login date and time
};
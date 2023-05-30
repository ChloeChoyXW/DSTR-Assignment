#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <string>
#include <chrono>
using namespace std;

struct regUsers {
	int userID;
	string name;
	string phoneNum;
	string email;
	string pw;
	regUsers* nextAdd;
	regUsers* prevAdd;
};

class regUsersList {
	regUsers* head = NULL;
	regUsers* tail = NULL;
	string regUsersListName = "";

public:
	//constructor
	regUsersList(string regUsersListName);

	regUsers* createNewNode(int userID, string name, string pw, string phoneNum, string email);

	void insertToEndOfRegUsersList(int userID, string name, string pw, string phoneNum, string email);

	void deleteFromRegUsersList(int userID);

	void linearsearchAndModifyRegistUsersDetails(int choice);

	void linearsearchAndDisplayRegistUsersDetails(int choice);

	void sortRegUsersList(string sortCondition);

	void displayRegUsersList();

	void readRegUsersFile();

	void writeRegUsersFile();

	//string login();

	void compareAndDeleteUsers(const int* removedUserIDs, int removedCount);
};
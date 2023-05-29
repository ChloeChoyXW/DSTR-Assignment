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
	tm loginDate;
	tm loginTime;
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

	regUsers* createNewNode(int userID, tm loginDate, tm loginTime);

	void insertToEndOfRegUsersList(int userID, string name, string pw, string phoneNum, string email);

	void insertToFrontOfRegUsersLoginList(int userID, tm loginDate, tm loginTime);

	void deleteFromRegUsersList(int userID);

	void linearsearchAndModifyRegistUsersDetails(int choice);

	void linearsearchAndDisplayRegistUsersDetails(int choice);

	void sortRegUsersList(string sortCondition);

	void displayRegUsersList();

	void readRegUsersFile();

	void writeRegUsersFile();

	void readUsersLogFile();

	void writeUsersLogFile();

	//string login();

	void displayUsersLog();

	void deleteLoginNode(regUsers* nodeToDelete);

	void removeInactiveUsers();

	void userLoginlog(int userID);  //used to stored users' login date and time

};
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

struct regUsers {
	string userID;
	string name;
	string phoneNum;
	string email;
	string pw;
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

	regUsers* createNewNode(string userID, string name, string pw, string phoneNum, string email);

	regUsers* createNewNode(string userID, tm loginTime);

	void insertToEndOfRegUsersList(string userID, string name, string pw, string phoneNum, string email);

	void insertToFrontOfRegUsersLoginList(string userID, tm loginTime);

	void deleteFromRegUsersList(string userID);
	
	void linearsearchAndModifyRegistUsersDetails(string userID);

	void linearsearchAndDisplayRegistUsersDetails(int choice);

	void sortRegUsersList(string sortCondition);

	void displayRegUsersList();

	void readRegUsersFile();

	void writeRegUsersFile();

	void writeUsersLogFile();

};
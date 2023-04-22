#include <iostream>
using namespace std;

struct regUsers {
	string userID;
	string name;
	int phoneNum;
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

	regUsers* createNewNode(string userID, string name, string pw, int phoneNum, string email);

	regUsers* createNewNode(string userID, tm loginTime);

	void insertToFrontOfRegUsersList(string userID, string name, string pw, int phoneNum, string email);

	void insertToFrontOfRegUsersList(string userID, tm loginTime);

	void deleteFromRegUsersList(string userID);
	
	void searchAndModifyRegistUsersDetails(string userID);

	void sortRegUsersList(string sortCondition);

	void displayRegUsersList();

};
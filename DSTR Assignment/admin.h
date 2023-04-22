#include <iostream>
using namespace std;

struct admin {
	string adminID;
	string name;
	string pw;
	int phoneNum;
	string email;
	admin* nextAdd;
	admin* prevAdd;
};

class adminList {
	admin* head = NULL;
	admin* tail = NULL;
	string adminListName = "";

public:
	//constructor
	adminList(string adminListName);

	admin* createNewNode(string adminID, string name, int phoneNum, string email);

	void insertToEndOfAdminList(string adminID, string name, int phoneNum, string email);

	void searchAdmin(string adminID);
};

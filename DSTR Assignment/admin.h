#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct admin {
	int adminID;
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

	admin* createNewNode(int adminID, string name, int phoneNum, string email);

	void insertToEndOfAdminList(int adminID, string name, int phoneNum, string email);

	void searchAdmin(int adminID);

	void readAdminFile();

	void adminQuickSort();

	void displayList();

	void deleteFromAdminList(string userID);
};

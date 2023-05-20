#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct admin {
	string adminID;
	string name;
	string pw;
	string phoneNum;
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

	admin* createNewNode(string adminID, string name, string pw, string phoneNum, string email);

	void insertToEndOfAdminList(string adminID, string name, string pw, string phoneNum, string email);

	void insertToFrontOfAdminList(string adminID, string name, string pw, string phoneNum, string email);

	void searchAdmin(string adminID);

	void readAdminFile();

	void adminQuickSort();

	void displayList();

	void deleteFromAdminList(string adminID);

	void linearsearchAndModifyAdminDetails(string adminID);

	void linearsearchAndDisplayAdminDetails(string choice);
};

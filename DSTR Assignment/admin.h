#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

struct admin {
	int adminID;
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

	admin* createNewNode(int adminID, string name, string pw, string phoneNum, string email);

	void insertToEndOfAdminList(int adminID, string name, string pw, string phoneNum, string email);

	void readAdminFile();

	void displayList();

	void linearsearchAndModifyAdminDetails(int choice, int adminID);

	void insertionSortAdminDoublyLinkedList(int sortCondition);

	void writeAdminFile();

	int adminLogin();

	int generateID();


};

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct userFavUni {
	int userID;
	string uniName;
	userFavUni* nextAdd;
	userFavUni* prevAdd;
};


class userFavUniList {
	userFavUni* head = NULL;
	userFavUni* tail = NULL;
	string userFavUniListName = "";

public:
	//constructor
	userFavUniList(string userFavUniListName);

	userFavUni* createNewNode(int userID, string uniName);

	void insertToFrontOfUserFavUniList(int userID, string uniName);

	void insertToEndOfUserFavUniList(int userID, string uniName);

	void LinearSearchandDisplay(int choice);

	void deleteFromUserFavUniList(string uniName);

	void sortUserFavUniList();

	void displayUserFavUniList();

	void readFavUniFile();

	void writeFavUniFile();

	void generateReport();
};

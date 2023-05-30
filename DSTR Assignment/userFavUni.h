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

	//void deleteFromUserFavUniList(string uniName);

	//void insertionSort();

	//int size();

	//int getPosition(userFavUni* node);

	//int JumpSearchFavUni(const std::string& uniName);
	
	/*userFavUni* MiddleBinarySearch(userFavUni* start, userFavUni* last, string uniName);

	void BinarySearchFavUni(string uniName);*/

	void sortUserFavUniList();

	void displayUserFavUniList();

	void readFavUniFile();

	void writeFavUniFile();

	void generateReport();

};

//
//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//struct userFavUni {
//	string userID;
//	string uniName;
//	userFavUni* nextAdd;
//	userFavUni* prevAdd;
//};
//
//
//class userFavUniList {
//	userFavUni* head = NULL;
//	userFavUni* tail = NULL;
//	string userFavUniListName = "";
//
//public:
//	//constructor
//	userFavUniList(string userFavUniListName);
//
//	userFavUni* createNewNode(string userID, string uniName);
//
//	void insertToFrontOfUserFavUniList(string userID, string uniName);
//
//	void insertToEndOfUserFavUniList(string userID, string uniName);
//
//	void deleteFromUserFavUniList(string uniName);
//
//	void insertionSort();
//
//	int size();
//
//	int getPosition(userFavUni* node);
//
//	int JumpSearchFavUni(const std::string& uniName);
//	
//	/*userFavUni* MiddleBinarySearch(userFavUni* start, userFavUni* last, string uniName);
//
//	void BinarySearchFavUni(string uniName);*/
//
//	void sortUserFavUniList(string sortCondition);
//
//	void displayUserFavUniList();
//
//	void readFavUniFile();
//
//	void writeFavUniFile();
//
//};

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct userFavUni {
	string userID;
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

	userFavUni* createNewNode(string userID, string uniName);

	void insertToFrontOfUserFavUniList(string userID, string uniName);

	void insertToEndOfUserFavUniList(string userID, string uniName);

	void deleteFromUserFavUniList(string uniName);

	void insertionSort();

	void FavUniQuickSort();

	int size();

	int getPosition(userFavUni* node);

	//int JumpSearchFavUni(const std::string& uniName);
	

	void BinarySearchFavUni(string userID, string uniName, int usertype);

	void sortUserFavUniList(string sortCondition);

	void displayUserFavUniList();

	void readFavUniFile();

	void writeFavUniFile();

};

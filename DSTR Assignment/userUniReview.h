#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

struct userUniReview {
	string userID;
	string uniName;
	string userReview;
	string adminReply;
	tm reviewTime;
	userUniReview* nextAdd;
	userUniReview* prevAdd;
};

class userUniReviewList {
	userUniReview* head = NULL;
	userUniReview* tail = NULL;
	string userUniReviewListName = "";

public:
	//constructor
	userUniReviewList(string userUniReviewListName);

	userUniReview* createNewNode(string userID, string uniName, string userReview, tm reviewTime, string adminReply);

	void insertToEndOfUserUniReviewList(string userID, string uniName, string userReview, tm reviewTime, string adminReply);

	void deleteFromUserUniReviewList(string userID, string uniName);

	void sortUserUniReviewList(string sortCondition);

	void searchAndModifyUserUniReviewList(string userID, string uniName);

	void searchAndDisplayUserUniReviewList(int choice);

	void displayUserUniReviewList();

	void readUserUniReviewFile();

	void writeUserUniReviewFile();
};

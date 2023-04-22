#pragma once

#include <iostream>
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

	userUniReview* createNewNode(string userID, string uniName, tm reviewTime, string adminReply);

	void insertToEndOfUserUniReviewList(string userID, string uniName, tm reviewTime, string adminReply);

	void deleteFromUserUniReviewList(string userTD, string uniName);

	void sortUserUniReviewList(string sortCondition);

	void searchAndModifyUserUniReviewList(string userID, string uniName);

	void displayUserUniReviewList();
};

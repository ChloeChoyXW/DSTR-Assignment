#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <conio.h>

using namespace std;

struct userUniReview {
	int userID;
	string uniName;
	string userReview;
	string adminReply;
	tm reviewDate;
	tm reviewTime;
	tm replyDate;
	tm replyTime;
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

	userUniReview* createNewNode(int userID, string uniName, string userReview, tm reviewDate, tm reviewTime, string adminReply, tm replyDate, tm replyTime);

	void insertToEndOfUserUniReviewList(int userID, string uniName, string userReview, tm reviewDate, tm reviewTime, string adminReply, tm replyDate, tm replyTime);

	void deleteFromUserUniReviewList(int userID, string uniName);

	void sortReviewDateList();

	void searchAndAdminReplyUniReviewList(int userID, string uniName);

	void searchAndDisplayUserUniReviewList(string uniname);

	void displayUserUniReviewList();

	void displayNoReplyReviewList();

	void moveForthBackReviewList();

	void readUserUniReviewFile();

	void writeUserUniReviewFile();

	void writeUniReview(int userID, string uniName);    //user write review 

	void displayNoReplyUniReviewList();

};

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <conio.h>

using namespace std;

struct userUniReview {
	string userID;
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

	userUniReview* createNewNode(string userID, string uniName, string userReview, tm reviewDate, tm reviewTime, string adminReply, tm replyDate, tm replyTime);

	void insertToEndOfUserUniReviewList(string userID, string uniName, string userReview, tm reviewDate, tm reviewTime, string adminReply, tm replyDate, tm replyTime);

	void deleteFromUserUniReviewList(string userID, string uniName);

	void sortReviewDateList();

	void searchAndAdminReplyUniReviewList(string userID, string uniName);

	void searchAndDisplayUserUniReviewList(string uniname);

	void displayUserUniReviewList();

	void displayNoReplyReviewList();

	void moveForthBackReviewList();

	void readUserUniReviewFile();

	void writeUserUniReviewFile();

	void writeUniReview(string userID, string uniName);    //user write review 

};

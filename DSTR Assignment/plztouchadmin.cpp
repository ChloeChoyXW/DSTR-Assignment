////3.1 Login and logout.
////3.2 Display all registered users’ details.
////3.3 Modify a user detail.
////3.4 Delete user accounts based on inactivity status.
////3.5 Move back and forth between the feedback of registered users according to the latest
////date.
////3.6 Reply to the registered user’s feedback.
////3.7 Based on the list of all customers' favorite universities, summarize the top 10 
////universities most preferred by parents in Malaysia and generate a report.
//
////if got time can add search :)
////search review
//
//#include <string>
//#include <iostream>
//#include <stdio.h>
//#include "university.h"
//#include "registeredUsers.h"
//#include "userFavUni.h"
//#include "admin.h"
//#include "userUniReview.h"
//
//using namespace std;
//
//int main() {
//	int ans, searchBy;
//	char option;
//	regUsersList regUsers = regUsersList("Registered Users");
//	userUniReviewList  userReview = userUniReviewList("Users' Review");
//	userFavUniList favUni = userFavUniList("Uni  Fav List");
//	//adminList adList = adminList("Admin List");
//
//	regUsers.readRegUsersFile();
//	userReview.readUserUniReviewFile();
//	favUni.readFavUniFile();
//	//adList.readAdminFile();
//
//	while (true) {
//		cout << "---ADMIN MENU---" << endl;
//		cout << "1. DISPLAY USERS' DETAILS\n2. MODIFY USER DETAIL\n3. DELETE INACTIVE USERS\n4. VIEW FEEBACKS\n5. REPLY FEEDBACKS\n6. GENERATE REPORT\n7. EDIT PROFILE\n";
//		cout << "Enter your choice: ";
//		cin >> ans;
//		if (cin.fail() || ans <= 0 || ans > 6) {
//			cout << "Invalid Input! Please try again~\n\n";
//			cin.clear();
//			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		}
//		switch (ans) 
//		{
//		case 1:      //can give options to display all or search if got time
//		{
//			cout << endl;
//			cout << string(55, '=') << endl;
//			regUsers.displayRegUsersList();
//			cout << endl;
//			break;
//		}
//		case 2:
//		{
//			while (true) {
//				cout << "\nSearch by:\n1. User ID\t2.User Name\nEnter your selection: ";
//				cin >> searchBy;
//				if (cin.fail() || searchBy < 0 || searchBy > 2)
//				{
//					cout << "Invalid Input! Please try again~\n\n";
//					cin.clear();
//					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//				}
//				else {
//					regUsers.linearsearchAndModifyRegistUsersDetails(searchBy);
//					break;
//				}
//			}
//			break;
//		}
//		case 3:
//		{
//			cout << "\nAre you certain about your intention to delete users (y/n): ";
//			cin >> option;
//			if (option == 'y')
//			{
//				regUsers.removeInactiveUsers();
//				break;
//			}
//			else
//				break;
//		}
//		case 4:    
//		{
//			cout << endl << string(55, '=') << endl;
//			userReview.sortReviewDateList();
//			userReview.moveForthBackReviewList();
//			break;
//		}
//		case 5:  //add sort
//		{
//			string uniname, userid;
//			userReview.displayNoReplyReviewList();
//			cout << "\n\nEnter University name: ";
//			cin.ignore();
//			getline(cin, uniname);
//			
//			userReview.searchAndDisplayUserUniReviewList(uniname);
//			cout << "Enter User ID: ";
//			getline(cin, userid);
//			userReview.searchAndAdminReplyUniReviewList(userid, uniname);
//			break;
//		}
//		case 6:
//		{
//			favUni.generateReport();
//		}
//		case 7:
//		{
//			//adList.insertToEndOfAdminList(1, "Peter Pan", "123", "0129390234", "hsdhqoj@gamil.com");
//			//adList.insertToEndOfAdminList(1, "Wendy Hi", "145", "0129390234", "fwefdhqoj@gamil.com");
//			//adList.insertToEndOfAdminList(1, "Pirate YB", "1342", "0129390234", "wehfiewhfoj@gamil.com");
//			//adList.writeAdminFile();
//		}
//		}
//	}
//
//
//
//	return 0;
//
//}

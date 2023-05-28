//3.1 Login and logout.
//3.2 Display all registered users’ details.
//3.3 Modify a user detail.
//3.4 Delete user accounts based on inactivity status.
//3.5 Move back and forth between the feedback of registered users according to the latest
//date.
//3.6 Reply to the registered user’s feedback.
//3.7 Based on the list of all customers' favorite universities, summarize the top 10 
//universities most preferred by parents in Malaysia and generate a report.

//if got time can add search :)
//modify admin profile

#include <string>
#include <iostream>
#include <stdio.h>
#include "university.h"
#include "registeredUsers.h"
#include "userFavUni.h"
#include "admin.h"
#include "userUniReview.h"

using namespace std;

//int main() {
//	int ans, searchBy;
//	char option;
//	regUsersList regUsers = regUsersList("Registered Users");
//	userUniReviewList  userReview = userUniReviewList("Users' Review");
//	while (true) {
//		cout << "---ADMIN MENU---" << endl;
//		cout << "1. DISPLAY USERS' DETAILS\n2. MODIFY USER DETAIL\n3. DELETE INACTIVE USERS\n4. VIEW FEEBACKS\n5. REPLY FEEDBACKS\n6. GENERATE REPORT\n";
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
//			regUsers.readRegUsersFile();
//			regUsers.displayRegUsersList();
//			cout << endl;
//			break;
//		}
//		case 2:
//		{
//			cout << "\nSearch by:\n1. User ID\t2.User Name\nEnter your selection: ";
//			cin >> searchBy;
//			regUsers.linearsearchAndModifyRegistUsersDetails(searchBy);
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
//		case 4:    //here also can add search
//		{
//			userReview.readUserUniReviewFile();
//			cout << string(55, '=') << endl;
//			userReview.displayUserUniReviewList();
//			break;
//		}
//		case 5:
//		{
//
//		}
//		}
//	}
//
//
//
//	return 0;
//
//}

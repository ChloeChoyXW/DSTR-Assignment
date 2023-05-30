#include <string>
#include <iostream>
#include <stdio.h>
#include "university.h"
#include "registeredUsers.h"
#include "userFavUni.h"
#include "userUniReview.h"
#include "admin.h"
#include "usersloginrecord.h"

using namespace std;



int main() {
	int identity;
	int id = 0; //global id
	
	regUsersList regUsers = regUsersList("Registered Users");
	userUniReviewList  userReview = userUniReviewList("Users' Review");
	userFavUniList favUni = userFavUniList("Uni  Fav List");
	adminList adMin = adminList("Admin List");
	loginRecordList logRec = loginRecordList("Users Login Record");
	UniList Uni = UniList("Universities: ");

	while(true) {

		adMin.readAdminFile();
		regUsers.readRegUsersFile();
		logRec.readUsersLogFile();
		userReview.readUserUniReviewFile();
		favUni.readFavUniFile();
		Uni.readFromFileDoubly();
		Uni.readFromFileArray();

		cout << "TOP UNIVERSITY RECOMMENDATION SYSTEM FOR SECONDARY SCHOOL STUDENTS\n";
		cout << string(59, '=') << endl;
		cout << "1. Normal Users\n2. Registered Users\n3. MoHE Admin\n";
		cout << "Identity: ";
		cin >> identity;
		if (cin.fail() || identity <= 0 || identity > 3) {
			cout << "Invalid Input! Please try again~\n\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		cout << endl;
	switch (identity)
	{
	case 1:  //normal users
	{
		int ans, searchBy;
		char option;
		while (true) {
			cout << "---USER MENU---" << endl;
			cout << "1. DISPLAY UNIVERSITY DETAILS\n2. VIEW UNIVERSITY DETAILS IN ASCENDING ORDER\n3. SEARCH UNIVERSITY BY NAME\n4. REGISTER AS CUSTOMER\n5. EXIT";
			cout << "Enter your choice: ";
			cin >> ans;
			if (cin.fail() || ans <= 0 || ans > 4) {
				cout << "Invalid Input! Please try again~\n\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			switch (ans)
			{
			case 1:
			{
				cout << endl;
				cout << string(55, '=') << endl;
				Uni.displayListDoubly();
				cout << endl;
				break;
			}
			case 2:
			{
				cout << endl;
				cout << string(55, '=') << endl;
				Uni.insertionSortUniDoublyLinkedList(2);
				void displayListDoubly();
				break;
			}
			case 3:
			{
				cout << endl;
				cout << string(55, '=') << endl;
				Uni.linearSearchUniAndDisplayDoubly(2);
				break;
			}
			case 4:
			{
				regUsers.readRegUsersFile();
				cout << endl << string(55, '=') << endl;
				cout << "REGISTER AS CUSTOMER: " << endl;

				string name, pw, phoneNum, email;
				int userID;

				userID = regUsers.generateUserID();

				cin.ignore(); 

				cout << "Enter Name: ";
				getline(cin, name);

				cout << "Enter Password: ";
				getline(cin, pw);

				cout << "Enter Phone Number: ";
				getline(cin, phoneNum);

				cout << "Enter Email: ";
				getline(cin, email);

				regUsers.insertToEndOfRegUsersList(userID, name, pw, phoneNum, email);

				cout << endl << string(55, '=') << endl;
				cout << "CUSTOMER REGISTERED" << endl;

				break;
			}
			}
		}
	}
	case 2:  //registered users
	{
		userReview.displayRepliedreview(3);
	}
	case 3:  //admin
	{
		int newAdmin;
		bool correctInput = false;
		while (true) {
			cout << "\n1. LOGIN\n2. REGISTER\n";
			cout << "CHOICE: ";
			cin >> newAdmin;
			if (!(cin.fail() || newAdmin <= 0 || newAdmin > 2)) {
				break;
			}
			else {
				cout << "Invalid Input! Please try again~\n\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		if (newAdmin == 1)
		{
			id = adMin.adminLogin();
			if (id == -1)
			{
				cout << "Admin Not Found\n" << endl;
				break;
			}
		}
		else
		{
			cout << endl;
			cout << "--REGISTRATION--\n";
			id = adMin.generateID();
			string name, pw, phone, email;
			cout << "Name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Password: ";
			getline(cin, pw);
			cout << "Phone Number: ";
			getline(cin, phone);
			cout << "Email: ";
			getline(cin, email);
			adMin.insertToEndOfAdminList(id, name, pw, phone, email);
		}
		cout << endl;
		int ans, searchBy;
		char option;
		while (true) {
			cout << "---ADMIN MENU---" << endl;
			cout << "1. DISPLAY USERS' DETAILS\n2. MODIFY USER DETAIL\n3. DELETE INACTIVE USERS\n4. VIEW FEEBACKS\n5. REPLY FEEDBACKS\n6. GENERATE REPORT\n7. EDIT PROFILE\n8. LOGOUT\n";
			cout << "Enter your choice: ";
			cin >> ans;
			if (cin.fail() || ans <= 0 || ans > 8) {
				cout << "Invalid Input! Please try again~\n\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			switch (ans)
			{
			case 1:      //can give options to display all or search if got time
			{
				cout << endl;
				cout << string(55, '=') << endl;
				regUsers.displayRegUsersList();
				cout << endl;
				break;
			}
			case 2:
			{
				while (true) {
					cout << "\nSearch by:\n1. User ID\t2.User Name\nEnter your selection: ";
					cin >> searchBy;
					if (cin.fail() || searchBy < 0 || searchBy > 2)
					{
						cout << "Invalid Input! Please try again~\n\n";
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					else {
						regUsers.linearsearchAndModifyRegistUsersDetails(searchBy);
						break;
					}
				}
				break;
			}
			case 3:
			{
				cout << "\nAre you certain about your intention to delete users (y/n): ";
				cin >> option;
				if (option == 'y')
				{
					int removeCount = 0;
					int* userIDremoved = logRec.removeInactiveUsers(removeCount);
					regUsers.compareAndDeleteUsers(userIDremoved, removeCount);
					break;
				}
				else
					break;
			}
			case 4:
			{
				cout << endl << string(55, '=') << endl;
				userReview.sortReviewDateList(1);
				userReview.moveForthBackReviewList();
				break;
			}
			case 5: 
			{
				string uniname, userid;
				userReview.displayNoReplyReviewList();
				cout << "\n\nEnter University name: ";
				cin.ignore();
				getline(cin, uniname);

				userReview.searchAndDisplayUserUniReviewList(uniname);
				cout << "Enter User ID: ";
				getline(cin, userid);
				int userID = stoi(userid);
				userReview.searchAndAdminReplyUniReviewList(userID, uniname);
				break;
			}
			case 6:
			{
				favUni.generateReport();
				break;
			}
			case 7:
			{
				int ans;
				cout << "\nModify:\n1. Name\n2. Password\n3. Phone Number\n4. Email\n5. Exit\n";
				cout << "Choice: ";
				cin >> ans;
				if (ans == 5) {
					cout << endl;
					break;
				}
				else {
					adMin.linearsearchAndModifyAdminDetails(ans, id);
					break;
				}
			}
			}
		if(ans == 8) 
			{
				adMin.writeAdminFile();
				regUsers.writeRegUsersFile();
				logRec.writeUsersLogFile();
				userReview.writeUserUniReviewFile();
				cout << endl << endl;
				break;
			}
		}
	}
		}
	}


	return 0;
}

//auto start = std::chrono::high_resolution_clock::now();
//auto end = std::chrono::high_resolution_clock::now();
//auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
//std::cout << "Execution time: " << duration << " milliseconds" << std::endl;
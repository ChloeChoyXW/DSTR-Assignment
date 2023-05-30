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
	UniList UniDoubly = UniList("Universities");
	UniList UniArray = UniList("Universities");
	UniDoubly.readFromFileDoubly();
	UniArray.readFromFileArray();
	regUsersList regUsers = regUsersList("Registered Users");
	userUniReviewList  userReview = userUniReviewList("Users' Review");
	userFavUniList favUni = userFavUniList("Uni  Fav List");
	adminList admin = adminList("Admin List");
	admin.readAdminFile();
	loginRecordList logRec = loginRecordList("Users Login Record");
	//	

//
//

	while(true) {
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
		int userID = -1;
			int ans, searchBy;
			char option;
		
			while (true) {
				cout << "---------USER MENU---------" << endl;
				cout << "1. Display University Details\n2. View University Details In Ascending Order\n3. Search University By Name\n4. Register As Customer\n5. Back\n";
				cout << "Enter your choice: ";
				cin >> ans;
				if (cin.fail() || ans <= 0 || ans > 4) {
					cout << "Invalid Input! Please try again~\n\n";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				switch (ans)
				{
				case 1: {
					cout << endl;
					cout << string(55, '=') << endl;
					UniDoubly.displayListDoubly();
					cout << endl;
					break;
				}
				case 2: {
					cout << endl;
					cout << string(55, '=') << endl;
					UniDoubly.insertionSortUniDoublyLinkedList(2);
					UniDoubly.displayListDoubly();
					break;
				}
				case 3: {
					string cond;
					string instName;
					while (cond!="n") {
						cout << "Enter Institution Name: ";
						getline(cin, instName);
						UniArray.linearSearchUniAndDisplayArray(instName);
						cout << endl;
						cout << string(55, '=') << endl;
						cout << endl<< "Do you want to continue to search? (Any key to continue, n to exit): ";
						cin >> cond;
						if (cond == "n") {
							break;
						}
					}
					break;
				}
		
				case 4:
				{
					string cond;
					while (cond != "y") {
						try {
							cin.ignore();
							cout << endl << string(55, '=') << endl;
							cout << "REGISTER AS CUSTOMER: " << endl;

							string userID, name, pw, phoneNum, email;

							

							cout << "Enter Name: ";
							getline(cin, name);

							cout << "Enter Password: ";
							getline(cin, pw);

							cout << "Enter Phone Number: ";
							getline(cin, phoneNum);

							cout << "Enter Email: ";
							getline(cin, email);

							cout << endl << "Are you sure with these details? (Enter y to confirm, n to enter again): " << endl;
							cout << "Name: " << name << endl;
							cout << "Password: " << pw << endl;
							cout << "Phone Number: " << phoneNum << endl;
							cout << "Email: " << email << endl;
							cout << endl<< "Enter: ";
							cin >> cond;

							if (cond == "y") {
								regUsers.insertToEndOfRegUsersList(stoi(userID), name, pw, phoneNum, email);

								cout << endl << string(55, '=') << endl;
								cout << "CUSTOMER REGISTERED" << endl;
								break;
							}
						}
						catch (...) {
							cout<< endl << "There is an error occured! Please ensure you entered valid details!" << endl;
							cond = "n";
						}

							
					}	
				}
		
				}
			}
	}
	case 2:  //registered users
	{

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
			id = admin.adminLogin();
			if (id == -1)
			{
				cout << "Admin Not Found\n" << endl;
				break;
			}
		}
		else
		{
			cout << endl;
			id = admin.generateID();
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
			admin.insertToEndOfAdminList(id, name, pw, phone, email);
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
				userReview.sortReviewDateList();
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
					admin.linearsearchAndModifyAdminDetails(ans, id);
					break;
				}
			}
			}
		if(ans == 8) 
			{
				admin.writeAdminFile();
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
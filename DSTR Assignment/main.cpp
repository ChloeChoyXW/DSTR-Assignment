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
	int id = 1; //global id
	UniList UniDoubly = UniList("Universities");
	UniList UniArray = UniList("Universities");
	UniDoubly.readFromFileDoubly();
	UniArray.readFromFileArray();
	regUsersList regUsers = regUsersList("Registered Users");
	regUsers.readRegUsersFile();
	userUniReviewList  userReview = userUniReviewList("Users' Review");
	userReview.readUserUniReviewFile();
	userFavUniList favUni = userFavUniList("Uni  Fav List");
	favUni.readFavUniFile();
	adminList admin = adminList("Admin List");
	admin.readAdminFile();
	loginRecordList logRec = loginRecordList("Users Login Record");
	logRec.readUsersLogFile();



	while(true) {
		cout << endl<< "TOP UNIVERSITY RECOMMENDATION SYSTEM FOR SECONDARY SCHOOL STUDENTS\n";
		cout << string(64, '=') << endl;
		cout << "1. Normal Users\n2. Registered Users\n3. MoHE Admin\n4. Exit\n";
		cout << "Enter:  ";
		cin >> identity;
		if (cin.fail() || identity <= 0 || identity > 4) {
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
			bool cont = true;
		
			while (cont==true) {
				cout << "---------USER MENU---------" << endl;
				cout << "1. Display University Details\n2. View University Details In Ascending Order\n3. Search University By Name\n4. Register As Customer\n5. Exit\n";
				cout << "Enter your choice: ";
				cin >> ans;
				if (cin.fail() || ans <= 0 || ans > 5) {
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
					int sortAlgo;
					cin.ignore();
					cout << "Choose search algorithm: 1.Insertion Sort 2.Quick Sort: ";
					cin >> sortAlgo;
					if (sortAlgo == 1) {
						cout << endl << "Insertion Sort: " << endl;
						UniDoubly.insertionSortUniDoublyLinkedList(2);
						UniDoubly.displayListDoubly();
					}
					else {
						cout << endl << "Quick Sort: " << endl;
						UniDoubly.uniQuickSort(2);
						UniDoubly.displayListDoubly();
					}
					cout << endl;
					cout << string(55, '=') << endl;
					
					break;
				}
				case 3: {
					string cond,instName;
					int searchAlgo;
					while (cond!="n") {
						cin.ignore();
						cout << "Choose search algorithm: 1.Linear Search 2.Binary Search: ";
						cin >> searchAlgo;
						cin.clear();
						cin.ignore();
						cout << "Enter Institution Name: ";
						getline(cin, instName);
						if (searchAlgo == 1) {
							cout << endl << "Linear search: " << endl;
							UniArray.linearSearchUniAndDisplayArray(instName);					
						}
						else {
							cout << endl << "Binary search: " << endl;
							UniArray.binarySearchUniAndDisplayArray(instName);
						}
						
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

							string name, pw, phoneNum, email;

							int userID = regUsers.generateUserID();

							cout << "Enter Name: ";
							getline(cin, name);

							cout << "Enter Password: ";
							getline(cin, pw);

							cout << "Enter Phone Number: ";
							getline(cin, phoneNum);

							cout << "Enter Email: ";
							getline(cin, email);

							cout << endl<< endl << "Are you sure with these details? (Enter y to confirm, n to enter again): " << endl;
							cout << "Name: " << name << endl;
							cout << "Password: " << pw << endl;
							cout << "Phone Number: " << phoneNum << endl;
							cout << "Email: " << email << endl;
							cout << endl<< "Enter: ";
							cin >> cond;

							if (cond == "y") {
								regUsers.insertToEndOfRegUsersList(userID, name, pw, phoneNum, email);
								regUsers.writeRegUsersFile();
								cout << endl << "CUSTOMER REGISTERED" << endl;
								cout << endl << string(55, '=') << endl;
								break;
							}
						}
						catch (...) {
							cout<< endl << "There is an error occured! Please ensure you entered valid details!" << endl;
							cond = "n";
						}

							
					}	
				}
				case 5: {
					cont = false;
				}
		
				}
			}
			break;
	}
//=================registered users=======================
	case 2: 
	{
		int choice, regUsersFuncChoice;
		string loggedIn = "n";
		string contPrint="y";
		bool cont = true;
		while (cont==true) {
			cout << "\n1. REG USER LOGIN\n2. REGISTER\n3. EXIT"<<endl;
			cout << "CHOICE: ";
			cin >> choice;
			if (!(cin.fail() || choice <= 0 || choice > 3)) {
				if (choice == 1) {
					while (cont == true) {
						string email, pw;
						cout << "LOGIN (n to exit)" << endl;
						cin.ignore();
						cout << "Enter email: ";
						getline(cin, email);
						if (email == "n") {
							break;
						}
						cout << "Enter pw: ";
						getline(cin, pw);
						if (pw == "n") {
							break;
						}
						id = regUsers.login(email, pw);
						if (id == NULL) {
							cout << "Invalid login credentials! Please try again." << endl;
						}
						else {
							cout << endl << "Successfully logged in! Welcome back." << endl;
							loggedIn = "y";
							logRec.userLoginlog(id);
							break;
						}
					}
				}
				if (choice == 2) {
					while (cont == true) {
						string cond;
						try {
							cin.ignore();
							cout << endl << string(55, '=') << endl;
							cout << "REGISTER AS CUSTOMER: " << endl;

							string name, pw, phoneNum, email;

							int userID = regUsers.generateUserID();

							cout << "Enter Name: ";
							getline(cin, name);

							cout << "Enter Password: ";
							getline(cin, pw);

							cout << "Enter Phone Number: ";
							getline(cin, phoneNum);

							cout << "Enter Email: ";
							getline(cin, email);

							cout << endl << endl << "Are you sure with these details? (Enter y to confirm, n to enter again): " << endl;
							cout << "Name: " << name << endl;
							cout << "Password: " << pw << endl;
							cout << "Phone Number: " << phoneNum << endl;
							cout << "Email: " << email << endl;
							cout << endl << "Enter: ";
							cin >> cond;

							if (cond == "y") {
								regUsers.insertToEndOfRegUsersList(userID, name, pw, phoneNum, email);

								cout << endl << "CUSTOMER REGISTERED" << endl;
								cout << endl << string(55, '=') << endl;
								
								break;
							}
						}
						catch (...) {
							cout << endl << "There is an error occured! Please ensure you entered valid details!" << endl;
							cont = true;
						}
					}

				}
				if (choice == 3) {
					cont=false;
				}
				break;
			}
			else {
				cout << "Invalid Input! Please try again~\n\n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

		}

		while (contPrint=="y"&&loggedIn=="y") {
			cout << endl << "---REGISTERED USER MENU---" << endl;
			cout << "1. VIEW UNIVERSITIES\n2. SEARCH UNIVERSITIES\n3. SAVE FAVOURITE UNIVERSITIES\n4. SEND FEEDBACKS ON UNIVERSITY\n5. READ FEEDBACK REPLIES\n6. VIEW REVIEW\n7. LOGOUT\n";
			cout << "Enter your choice: ";
			cin >> regUsersFuncChoice;
			switch (regUsersFuncChoice) {
			case 1: {
				while (true) {
					
					cout <<endl<<  "Enter the sort condition by number: " << endl << "1.Location Code  2.Institution Name  3.Academic Rank  4.Employer Reputation Rank  5.Faculty/Student Ratio Rank" << endl
						<< "6.Citation Per Faculty Rank  7.International Faculty Ratio Rank  8.International Student Ratio Rank" << endl 
						<< "9.Interational Research Natwork Rank  10.Employment Outcome Rank  11.University Rank  12.Exit" << endl;
					int sortNum;
					cout << "Enter choice: ";
					cin >> sortNum;
					cin.clear();
					if (sortNum == 12) {
						break;
					}
					if (sortNum < 1 || sortNum>12 || cin.fail()) {
						cout << "Please enter a valid input!";
						continue;
					}
					UniDoubly.insertionSortUniDoublyLinkedList(sortNum);
					UniDoubly.displayListDoubly();
				}
				break;
			}
			case 2: {
				while (true) {
					cin.ignore();
					string strparameter="";
					int parameter1=0, parameter2=0;
					cout << "Enter the search condition by number: " << endl << "1.Location Code  2.Institution Name  3.Academic Rank  4.Employer Reputation Rank  5.Faculty/Student Ratio Rank" << endl
						<< "6.Citation Per Faculty Rank  7.International Faculty Ratio Rank  8.International Student Ratio Rank" << endl 
						<< "9.Interational Research Natwork Rank  10.Employment Outcome Rank  11.University Rank  12.Exit" << endl;
					int searchNum;
					cout << "Enter choice: ";
					cin >> searchNum;
					cin.clear();
					if (searchNum < 1 || searchNum>12 || cin.fail()) {
						cout << "Please enter a valid input!"<<endl;
						continue;
					}
					if (searchNum == 1 || searchNum == 2) {
						cin.ignore();
						cout << "Enter parameter: ";
						cin.clear();

						getline(cin,strparameter);
						UniDoubly.linearSearchUniAndDisplayDoubly(searchNum, strparameter, parameter1, parameter2);
					}
					else if (searchNum == 12) {
						break;
					}
					else {
						cin.ignore();
						cout << "Enter min rank: ";
						cin >> parameter1;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cout << "Enter max rank: ";
						cin >> parameter2;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						UniDoubly.linearSearchUniAndDisplayDoubly(searchNum, strparameter, parameter1, parameter2);
					}
					

					cout << "Do you want to continue? (Any key to continue, n to exit): ";
					string cont;
					cin >> cont;
					if (cont == "n") {
						break;
					}
					
				}
				break;

			}
			case 3: {
				while (true) {
					cin.ignore();
					string found;
					string option;
					string favUniName;
					cout << "Enter Favourite University Name: ";
					getline(cin, favUniName);
					cin.clear();
					found = UniDoubly.linearSearchDoubly(favUniName);
							
					if (found == "y") {
						favUni.insertToEndOfUserFavUniList(id, favUniName);
						favUni.LinearSearchandDisplay(id);
						cout << "University added! Do you want to continue? (Any key to continue, n to exit): ";
						cin >> option;
						if (option == "n") {
							break;
						}
					}
					else {
						cout << "University is not available! Please enter existing university name in the list!"<<endl;
					}

				}
				break;
			}
			case 4: {
				string uniName;
				string found;

				while (found != "y") {
					cin.ignore();
					cout << "Enter University Name (n to exit): ";
					getline(cin, uniName);

					if (uniName == "n") {
						break;
					}
				
					found = UniDoubly.linearSearchDoubly(uniName);
						
					if (found == "y") {
						userReview.writeUniReview(id, uniName);
						cout << "Review added.\n";
						break;
					}
					else {
						cout << "University is not available! Please enter existing university name in the list!"<<endl;
						found = "n";
					}
				}
				break;
			}
			case 5: {
				userReview.displayRepliedreview(id);
				break;
			}
			case 6:
			{
				string exit;
				cout << endl;
				userReview.displayUserUniReviewList();
				cout << "Enter n to exit: ";
				cin >> exit;
				if (exit == "n")
				{
					break;
				}
			}
			case 7: {
				regUsers.writeRegUsersFile();
				favUni.writeFavUniFile();
				userReview.writeUserUniReviewFile();
				logRec.writeUsersLogFile();
				id = 0;
				contPrint = "n";

			}
			
			}
		}
		break;

	}
	case 3:  //==================admin===================================
	{
		int newAdmin;
		bool correctInput = false, cont=true;

		while (cont ==true) {
			cout << "\n1. ADMIN LOGIN\n2. REGISTER\n3. EXIT\n";
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
		else if(newAdmin == 2)
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
		else {
			cont = false;
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
		break;
	}
	case 4: {
		exit(0);
	}
		}
	}


	return 0;
}
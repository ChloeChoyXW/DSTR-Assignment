//Display all the universities' information from the dataset
//Sort university information in ascending order by university name
//Search individual university name
//Register as customer of the education exhibition

//#include <string>
//#include <iostream>
//#include <stdio.h>
//#include "university.h"
//#include "registeredUsers.h"
//#include "admin.h"
//
//
//int main() {
//	int userID = -1;
//	int ans, searchBy;
//	char option;
//
//	UniList Uni = UniList("Universities: ");
//	Uni.readFromFileDoubly();
//    Uni.readFromFileArray();

	/*while (true) {
		cout << "---USER MENU---" << endl;
		cout << "1. DISPLAY UNIVERSITY DETAILS\n2. VIEW UNIVERSITY DETAILS IN ASCENDING ORDER\n3. SEARCH UNIVERSITY BY NAME\n4. REGISTER AS CUSTOMER\n";
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

            string userID, name, pw, phoneNum, email;

            cout << "Enter User ID: " << endl;
            getline(cin, userID);

            cout << "Enter Name: " << endl;;
            getline(cin, name);

            cout << "Enter Password: " << endl;;
            getline(cin, pw);

            cout << "Enter Phone Number: " << endl;;
            getline(cin, phoneNum);

            cout << "Enter Email: " << endl;;
            getline(cin, email);

			int userid = stoi(userID);
            regUsers.insertToEndOfRegUsersList(userid, name, pw, phoneNum, email);

            cout << endl << string(55, '=') << endl;
            cout << "CUSTOMER REGISTERED" << endl;
                    
			break;
		}
		
		}
	}*/



//	Uni.readFromFileArray();
//	regUsersList regUsers = regUsersList("Registered Users: ");
//	regUsers.readRegUsersFile();
//	adminList admin = adminList("Admin: ");
//	admin.readAdminFile();
//
//
//
//	while (true) {
//		cout << "---USER MENU---" << endl;
//		cout << "1. DISPLAY UNIVERSITY DETAILS\n2. VIEW UNIVERSITY DETAILS IN ASCENDING ORDER\n3. SEARCH UNIVERSITY BY NAME\n4. LOGIN\n5. REGISTER AS CUSTOMER\n";
//		cout << "Enter your choice: ";
//		cin >> ans;
//		if (cin.fail() || ans <= 0 || ans > 4) {
//			cout << "Invalid Input! Please try again~\n\n";
//			cin.clear();
//			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		}
//		switch (ans)
//		{
//		case 1: {
//			cout << endl;
//			cout << string(55, '=') << endl;
//			Uni.displayListDoubly();
//			cout << endl;
//			break;
//		}
//		case 2: {
//			cout << endl;
//			cout << string(55, '=') << endl;
//			Uni.insertionSortUniDoublyLinkedList(2);
//			Uni.displayListDoubly();
//			break;
//		}
//		case 3: {
//			cout << endl;
//			cout << string(55, '=') << endl;
//			Uni.linearSearchUniAndDisplayDoubly(2);
//			break;
//		}
//		
//		case 4: {
//			bool userlogin = false;
//			int loginUser;
//			string email, pw;
//			cout << endl;
//			cout << string(55, '=') << endl;
//			cout << "LOGIN\n1.USER  2.ADMIN" << endl;
//			cout << "Enter: ";
//			cin >> loginUser;
//			if (loginUser == 1) {
//				cout << "Enter Email: ";
//				cin >> email;
//				cout << "Enter Password: ";
//				cin >> pw;
//
//				while (userID == -1) {
//					cout << "sdfasdda" << endl;
//					//userID = regUsers.login(email, pw);
//					if (userID != NULL) {
//						userlogin = true;
//						break;
//					}
//					else {
//						cout << "No user found! Please try again!" << endl;
//						cout << "Enter Email: ";
//						cin >> email;
//						cout << email << endl;
//						cout << "Enter Password: ";
//						cin >> pw;
//						cout << pw << endl;
//						/*userID = regUsers.login(email, pw);*/
//
//					}
//				}
//			}
//			else {
//				while (userID == -1) {
//					cout << "sdfasdda" << endl;
//					userID = admin.adminLogin();
//					if (userID != -1) {
//						userlogin = true;
//						break;
//					}
//					else {
//						cout << "No user found! Please try again!" << endl;
//						cout << "Enter Email: ";
//						cin >> email;
//						cout << email << endl;
//						cout << "Enter Password: ";
//						cin >> pw;
//						cout << pw << endl;
//					}
//				}
//			}
//
//			break;
//		}
//
//		case 5:
//		{
//			cout << endl << string(55, '=') << endl;
//			cout << "REGISTER AS CUSTOMER: " << endl;
//
//			string userID, name, pw, phoneNum, email;
//
//			cout << "Enter User ID: " << endl;
//			getline(cin, userID);
//
//			cout << "Enter Name: " << endl;;
//			getline(cin, name);
//
//			cout << "Enter Password: " << endl;;
//			getline(cin, pw);
//
//			cout << "Enter Phone Number: " << endl;;
//			getline(cin, phoneNum);
//
//			cout << "Enter Email: " << endl;;
//			getline(cin, email);
//
//			regUsers.insertToEndOfRegUsersList(stoi(userID), name, pw, phoneNum, email);
//
//			cout << endl << string(55, '=') << endl;
//			cout << "CUSTOMER REGISTERED" << endl;
//
//			break;
//		}
//
//		}
//	}
//	return 0;
//}
//

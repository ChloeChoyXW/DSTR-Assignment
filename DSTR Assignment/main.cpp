#include <string>
#include <iostream>
#include <stdio.h>
#include "university.h"
#include "registeredUsers.h"
#include "userFavUni.h"
#include "admin.h"

using namespace std;

int main() {
	//UniList university = UniList("University List");
	//university.readFromFile();
	////university.displayList();
	////cout << string(22, '=')<< "Sorted List" << string(22, '=') << endl;
	////university.insertionSortUniDoublyLinkedList(2);
	//university.uniQuickSort(3);
	//university.displayList();
	//university.displayList();
	//string ans;
	//regUsersList regUser = regUsersList("Registered Users List");
	//regUser.readRegUsersFile();
	//regUser.displayRegUsersList();
	//regUser.insertToEndOfRegUsersList("6", "lisa", "abc", "0012391", "demkwomdo@iqdon");
	//cout << "-------------------------------------------------\n";
	//regUser.writeRegUsersFile();
	//regUser.readRegUsersFile();
	//regUser.displayRegUsersList();
	////cout << "1. User ID" << endl << "2. User Name";
	////getline(cin, ans);
	////regUser.linearsearchAndDisplayRegistUsersDetails(stoi(ans));
	//
	//adminList admin = adminList("Admin");
	//admin.readAdminFile();
	//admin.displayList();
	//admin.adminQuickSort();
	//admin.displayList();
	// 
	//userFavUniList favUni = userFavUniList("Favourite University List");
	//auto start = std::chrono::high_resolution_clock::now();

	//favUni.readFavUniFile();
	////favUni.displayUserFavUniList();
	////char str[20];
	//string ans;
	//cout << "Press 1 as User, Press 2 as Admin: ";
	//getline(cin, ans);
	////fgets(str, 20, stdin);


	////cin.clear();
	////cin.ignore();
	//
	////favUni.insertToFrontOfUserFavUniList("13","National University of Singapore (NUS)");
	////favUni.insertToEndOfUserFavUniList("18", "Tsinghua University");
	////favUni.insertionSort();
	////favUni.FavUniQuickSort();
	////std::cout << "After sorting:" << std::endl;
	//favUni.LinearSearchandDisplay(stoi(ans));
	////favUni.JumpSearchFavUni(uniName);
	////favUni.BinarySearchFavUni("6", uniName,2);
	////favUni.displayUserFavUniList();
	////favUni.writeFavUniFile();

	//
	//auto end = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	//std::cout << "Execution time: " << duration << " milliseconds" << std::endl;



	regUsersList regUser = regUsersList("Registered Users List");
	//regUser.userLoginlog("1");
	//regUser.userLoginlog("2");
	//regUser.userLoginlog("3");
	//regUser.userLoginlog("4");
	//regUser.userLoginlog("5");
	//regUser.userLoginlog("6");
	//regUser.writeUsersLogFile();
	regUser.removeInactiveUsers();
	//regUser.readUsersLogFile();
	regUser.displayUsersLog();

	return 0;
}

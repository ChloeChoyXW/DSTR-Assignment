#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include "university.h"
#include "registeredUsers.h"
#include "userFavUni.h"
#include "admin.h"
#include "dateTime.h"

using namespace std;

int main() {
	//UniList university = UniList("University List");
	//university.readFromFile();
	////university.displayList();
	////cout << string(22, '=')<< "Sorted List" << string(22, '=') << endl;
	////university.insertionSortUniDoublyLinkedList(2);
	//university.uniQuickSort(3);
	//university.displayList();
	////university.displayList();
	//
	////adminList admin = adminList("Admin");
	////admin.readAdminFile();
	////admin.displayList();
	////admin.adminQuickSort();
	////admin.displayList();
	//userFavUniList favUni = userFavUniList("Favourite University List");
	//favUni.readFavUniFile();
	////favUni.displayUserFavUniList();

	///*adminList admin = adminList("Admin");
	//admin.readAdminFile();
	//admin.displayList();
	//admin.adminQuickSort();
	//admin.displayList();*/
	//
	////favUni.insertToFrontOfUserFavUniList();
	////favUni.insertToEndOfUserFavUniList();
	//string uniName;
	//cout << "Enter the university name to search: ";
	//cin >> uniName;
	////

	//favUni.JumpSearchFavUni(uniName);
	////favUni.writeFavUniFile();
	//favUni.readFavUniFile();
	////favUni.displayUserFavUniList();


	regUsersList regUsers = regUsersList("User Login");
	//string currentDate = getCurrentDate();
	//string currentTime = getCurrentTime();
	//tm date = stringToTm(currentDate, 1);
	//tm time = stringToTm(currentTime, 2);
	//regUsers.insertToFrontOfRegUsersLoginList("1", date, time);
	//regUsers.writeUsersLogFile();

	regUsers.readRegUsersFile();



	//istringstream iss(currentDate);
	//istringstream iss2(currentTime);
	//tm dateTm = {};
	//tm timeTm = {};

	//iss >> std::get_time(&dateTm, "%Y-%m-%d");
	//iss2 >> std::get_time(&timeTm, "%H:%M:%S");
	//regUsers.insertToFrontOfRegUsersLoginList("1", dateTm, );
	//regUsers.writeUsersLogFile();

	//regUsers.readUsersLogFile();
	//regUsers.displayUsersLog();
	

	

	return 0;
}

#include <string>
#include <iostream>
#include "university.h"
#include "registeredUsers.h"
#include "userFavUni.h"
#include "admin.h"

using namespace std;

int main() {
	//UniList university = UniList("University List");
	//university.readFromFile();
	//university.displayList();
	//cout << string(22, '=')<< "Sorted List" << string(22, '=') << endl;
	//university.insertionSortUniDoublyLinkedList('a');
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
	//adminList admin = adminList("Admin");
	//admin.readAdminFile();
	//admin.displayList();
	//admin.adminQuickSort();
	//admin.displayList();
	//userFavUniList favUni = userFavUniList("Favourite University List");
	//favUni.readFavUniFile();
	//favUni.displayUserFavUniList();
	//

	favUni.JumpSearchFavUni(uniName);
	//favUni.writeFavUniFile();
	favUni.readFavUniFile();
	//favUni.displayUserFavUniList();

	return 0;
}

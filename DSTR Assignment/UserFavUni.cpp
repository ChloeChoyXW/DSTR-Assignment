//#include "userFavUni.h"
//#include <cmath>
//#include <sstream>
//
//using namespace std;
//userFavUniList::userFavUniList(string userFavUniListName) : userFavUniListName(userFavUniListName), head(NULL) {}
//
//userFavUniList::userFavUniList(string userFavUniListName) : userFavUniListName(userFavUniListName) {};
//
//userFavUni* userFavUniList::createNewNode(string userID, string uniName)
//{
//	userFavUni* newnode = new userFavUni;
//	newnode->userID = userID;
//	newnode->uniName = uniName;
//	newnode->nextAdd = NULL;
//	newnode->prevAdd = NULL;
//	return newnode;
//}
//
//void userFavUniList::insertToFrontOfUserFavUniList(string userID, string uniName)
//{
//	userFavUni* newnode = createNewNode(userID, uniName);
//
//	if (head == NULL)
//	{
//		head = tail = newnode;
//	}
//	else
//	{
//		newnode->nextAdd = head;
//		head->prevAdd = newnode;
//		head = newnode;
//	}
//}
//
//void userFavUniList::insertToEndOfUserFavUniList(string userID, string uniName)
//{
//	userFavUni* newnode = createNewNode(userID, uniName);
//
//	if (head == NULL)
//	{
//		head = tail = newnode;
//	}
//	else
//	{
//		newnode->prevAdd = tail;
//		tail->nextAdd = newnode;
//		tail = newnode;
//	}
//}
//
//void userFavUniList::deleteFromUserFavUniList(string uniName)
//{
//	if (head == NULL)
//		return;
//	if (head->uniName == uniName)
//	{
//		userFavUni* current = head;
//		head = head->nextAdd;
//		cout << "Deleted Favourite University:  " << current->uniName << endl;
//		delete current;
//	}
//	else if (tail->uniName == uniName)
//	{
//		userFavUni* current = tail;
//		tail = tail->prevAdd;
//		if (tail == NULL)
//			head = NULL;
//		else
//			tail->nextAdd = NULL;
//		cout << "Deleted Favourite University: " << current->uniName << endl;
//		delete current;
//	}
//	else
//	{
//		userFavUni* prev = head->prevAdd;
//		userFavUni* current = head;
//		bool found = false;
//		while (current != NULL)
//		{
//			if (current->uniName == uniName)
//			{
//				found = true;
//				prev->nextAdd = current->nextAdd;
//				cout << "Deleted Favourite University: " << current->uniName << endl;
//				delete current;
//				return;
//			}
//			prev = current;
//			current = current->nextAdd;
//		}
//		if (!found)
//			cout << uniName << " is not found in the list!" << endl;
//	}
//}
//
//int userFavUniList::JumpSearchFavUni(const std::string& uniName) {
//	if (head == NULL) {
//		cout << "The favorite university list is empty." << endl;
//		return -1;  // Target element not found
//	}
//	userFavUni* current = head;
//
//
//	// Finding the block size to be jumped
//	int step = 0;
//	while (step * step < 2)
//		step++;
//
//	// Finding the block where the target element belongs
//	int prev = 0;
//	//userFavUni* current = head;
//	while (current && current->uniName.compare(uniName) < 0) {
//		prev++;
//		current = current->nextAdd;
//		if (prev * step >= 2)
//			return -1;  // Target element not found
//	}
//
//	// Linear search within the block
//	for (int i = 0; i < step; i++) {
//		if (current && current->uniName == uniName) {
//			std::cout << "The university '" << uniName << "' is found in the favorite list." << std::endl;
//			return i;  // Target element found
//		}
//		if (current)
//			current = current->nextAdd;
//	}
//
//	std::cout << "The university '" << uniName << "' is not found in the favorite list." << std::endl;
//	return -1;  // Target element not found
//}
//
//int userFavUniList::size() {
//	int count = 0;
//	userFavUni* current = head;
//	while (current != NULL) {
//		count++;
//		current = current->nextAdd;
//	}
//	return count;
//}
//
//void userFavUniList::JumpSearchFavUni(string uniName)
//{
//	if (head == nullptr) {
//			std::cout << "The favorite university list is empty." << std::endl;
//			return -1;  // List is empty
//	}
//
//	int listSize = size();
//	int blockSize = static_cast<int>(std::sqrt(listSize));
//
//	userFavUni* current = head;
//	userFavUni* prev = nullptr;
//		// Finding the block where the target element belongs
//	while (current && current->uniName < uniName) {
//		prev = current;
//		for (int i = 0; current && i < blockSize; ++i) {
//			current = current->nextAdd;
//		}
//	}
//
//	// Linear search within the block
//	while (current && current->uniName <= uniName) {
//		if (current->uniName == uniName) {
//			std::cout << "The university '" << uniName << "' is found in the favorite list." << std::endl;
//			return getPosition(current);
//		}
//		current = current->nextAdd;
//	}
//
//	std::cout << "The university '" << uniName << "' is not found in the favorite list." << std::endl;
//	return -1;  // Target element not found
//}
//
//
//
//int userFavUniList::JumpSearchFavUni(const std::string& uniName) {
//	if (head == nullptr) {
//		std::cout << "The favorite university list is empty." << std::endl;
//		return -1;  // List is empty
//	}
//
//	int listSize = size();
//	int blockSize = static_cast<int>(std::sqrt(listSize));
//
//	userFavUni* current = head;
//	userFavUni* prev = nullptr;
//	 Finding the block where the target element belongs
//	while (current && current->uniName < uniName) {
//		prev = current;
//		for (int i = 0; current && i < blockSize; ++i) {
//			current = current->nextAdd;
//		}
//	}
//
//	 Linear search within the block
//	while (current && current->uniName <= uniName) {
//		if (current->uniName == uniName) {
//			std::cout << "The university '" << uniName << "' is found in the favorite list." << std::endl;
//			return getPosition(current);
//		}
//		current = current->nextAdd;
//	}
//
//	std::cout << "The university '" << uniName << "' is not found in the favorite list." << std::endl;
//	return -1;  // Target element not found
//}
//
//
//int userFavUniList::JumpSearchFavUni(const std::string& uniName) {
//	if (head == nullptr) {
//		std::cout << "The favorite university list is empty." << std::endl;
//		return -1;  // List is empty
//	}
//
//	int listSize = size();
//	int blockSize = static_cast<int>(std::sqrt(listSize));
//
//	userFavUni* current = head;
//	userFavUni* prev = nullptr;
//
//	// Finding the block where the target element belongs
//	while (current && current->uniName < uniName) {
//		prev = current;
//		for (int i = 0; current && i < blockSize; ++i) {
//			current = current->nextAdd;
//		}
//	}
//
//	// Linear search within the block
//	while (current && current->uniName <= uniName) {
//		if (current->uniName == uniName) {
//			std::cout << "The university '" << uniName << "' is found in the favorite list." << std::endl;
//			return getPosition(current);
//		}
//		current = current->nextAdd;
//	}
//
//	std::cout << "The university '" << uniName << "' is not found in the favorite list." << std::endl;
//	return -1;  // Target element not found
//}
//
//void userFavUniList::sortUserFavUniList(string sortCondition)
//{
//
//}
//
//
//
//void userFavUniList::displayUserFavUniList()
//{
//	userFavUni* current = head;
//
//	while (current != NULL)
//	{
//		cout << "\n" << "User ID:  " << current->userID << endl;
//		cout << "Favourite University:  " << current->uniName << "\n" << endl;
//		cout << string(55, '=') <<  endl;
//
//		current = current->nextAdd;
//	}
//	cout << "List ended here." <<  endl;
//}
//
//
//void userFavUniList::readFavUniFile()
//{
//	string filename = "favuni.csv";
//	ifstream file(filename);
//
//	if (!file.is_open())
//	{
//		cout << "File " << filename << "unable to found!" << endl;
//		return;
//	}
//
//	string line;
//	while (getline(file, line))
//	{
//		stringstream d(line);
//		string userID, uniName;
//		getline(d, userID, ',');
//		getline(d, uniName, ',');
//		insertToEndOfUserFavUniList(userID, uniName);
//	}
//
//	file.close();
//}
//
//void userFavUniList::writeFavUniFile()
//{
//	ofstream file("favuni.csv");
//	if (!file)
//	{
//		cout << "File unable to open!" << endl;
//		return;
//	}
//
//	userFavUni* current = head;
//	while (current != nullptr)
//	{
//		file << current->userID << ',' << current->uniName << "\n";
//		current = current->nextAdd;
//	}
//	file.close();
//}
//

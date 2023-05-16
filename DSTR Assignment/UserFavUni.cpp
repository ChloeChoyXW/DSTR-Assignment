#include <userFavUni.h>
#include <fstream>

userFavUniList::userFavUniList(string userFavUniListName) : userFavUniListName(userFavUniListName) {};


userFavUni* userFavUniList::createNewNode(string userID, string uniName)
{
	userFavUni* newnode = new userFavUni;
	newnode->userID = userID;
	newnode->uniName = uniName;
	newnode->nextAdd = NULL;
	newnode->prevAdd = NULL;
	return newnode;
}

void userFavUniList::userFavUniList(string userID, string uniName)
{
	userFavUni* newnode = createNewNode(userID, uniName);

	if (head == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		newnode->prevAdd = tail;
		tail->nextAdd = newnode;
		tail = newnode;
	}
}

void userFavUniList::insertToEndOfUserFavUniList(string userID, string uniName)
{
	userFavUni* newnode = createNewNode(userID, uniName);

	if (head == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		newnode->prevAdd = tail;
		tail->nextAdd = newnode;
		tail = newnode;
	}
}

void userFavUniList::deleteFromUserFavUniList(string uniName)
{
	if (head == NULL)
		return;
	if (head->uniName == uniName)
	{
		userFavUni* current = head;
		head = head->nextAdd;
		cout << "Deleted Favourite University:  " << current->uniName << endl;
		delete current;
	}
	else if (tail->uniName == uniName)
	{
		userFavUni* current = tail;
		tail = tail->prevAdd;
		if (tail == NULL)
			head = NULL;
		else
			tail->nextAdd = NULL;
		cout << "Deleted Favourite University: " << current->uniName << endl;
		delete current;
	}
	else
	{
		userFavUni* prev = head->prevAdd;
		userFavUni* current = head;
		bool found = false;
		while (current != NULL)
		{
			if (current->uniName == uniName)
			{
				found = true;
				prev->nextAdd = current->nextAdd;
				cout << "Deleted Favourite University: " << current->uniName << endl;
				delete current;
				return;
			}
			prev = current;
			current = current->nextAdd;
		}
		if (!found)
			cout << uniName << " is not found in the list!" << endl;
	}
}

int userFavUniList::JumpSearchFavUni(userFavUni* head, string uniName)
{
	// Finding the block size to be jumped
	int step = 0;
	while (step * step < n)
		step++;

	// Finding the block where the target element belongs
	int prev = 0;
	userFavUni* current = head;
	while (current && current->uniName < target) {
		prev++;
		current = current->nextAdd;
		if (prev * step >= n)
			return -1;  // Target element not found
	}

	// Linear search within the block
	for (int i = 0; i < step; i++) {
		if (current && current->uniName == target)
			return i;  // Target element found
		current = current->nextAdd;
	}
	return -1;  // Target element not found
	cout << "The university is not in the favourite list." << endl;
}


//void userFavUniList::sortUserFavUniList(string sortCondition)();
//void sortedInsert(Uni** head, Uni* newNode, int sortCondition)
//{
//	userFavUni* current;
//
//	switch (sortCondition) {
//	case 1:
//
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)->rank >= newNode->rank) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd->rank < newNode->rank)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//
//		break;
//
//	case 2:
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)->instName >= newNode->instName) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd->instName < newNode->instName)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//		break;
//
//	case 3:
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)->location >= newNode->location) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd->location < newNode->location)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//		break;
//
//	case 4:
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)->academicRank >= newNode->academicRank) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd->academicRank < newNode->academicRank)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//		break;
//
//	case 5:
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)->employerRepRank >= newNode->employerRepRank) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd->employerRepRank < newNode->employerRepRank)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//		break;
//
//	case 6:
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)->facultyStuRIRank >= newNode->facultyStuRIRank) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd->facultyStuRIRank < newNode->facultyStuRIRank)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//		break;
//
//	case 7:
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)->citePerFacultyRank >= newNode->citePerFacultyRank) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd->citePerFacultyRank < newNode->citePerFacultyRank)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//		break;
//
//	case 8:
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)->intFacultyRIRank >= newNode->intFacultyRIRank) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd->intFacultyRIRank < newNode->intFacultyRIRank)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//		break;
//
//	case 9:
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)->intStuRIRank >= newNode->intStuRIRank) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd->intStuRIRank < newNode->intStuRIRank)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//		break;
//
//	case 10:
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)->intResearchNetRank >= newNode->intResearchNetRank) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd->intResearchNetRank < newNode->intResearchNetRank)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//		break;
//
//	case 11:
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)->employOutcomeRank >= newNode->employOutcomeRank) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd->employOutcomeRank < newNode->employOutcomeRank)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//		break;
//
//	case 12:
//		// if list is empty
//		if (*head == NULL) {
//			*head = newNode;
//		}
//		// if the node is to be inserted at the beginning
//		// of the doubly linked list
//		else if ((*head)->scoreScale >= newNode->scoreScale) {
//			newNode->nextAdd = *head;
//			newNode->nextAdd->prevAdd = newNode;
//			*head = newNode;
//		}
//
//		else {
//			current = *head;
//
//			// locate the node after which the new node
//			// is to be inserted
//			while (current->nextAdd != NULL &&
//				current->nextAdd->scoreScale < newNode->scoreScale)
//				current = current->nextAdd;
//
//			/*Make the appropriate links */
//
//			newNode->nextAdd = current->nextAdd;
//
//			// if the new node is not inserted
//			// at the end of the list
//			if (current->nextAdd != NULL)
//				newNode->nextAdd->prevAdd = newNode;
//
//			current->nextAdd = newNode;
//			newNode->prevAdd = current;
//		}
//		break;
//	}
//
//}

void userFavUniList::displayUserFavUniList()
{
	userFavUni* current = head;

	while (current != NULL)
	{
		cout << "Favourite University:  " << current->uniName << endl;
		cout << string(55, '=') << endl;

		current = current->nextAdd;
	}
	cout << "List ended here." << endl;
}

void userFavUniList::readFavUniFile()
{
	head = NULL;
	string userID, uniName;

	ifstream file("favuni.csv");

	while (file.good())
	{
		getline(file, userID, ',');
		getline(file, uniName, ',');
		insertToEndOfUserFavUniList(userID, uniName);
	}

	file.close();
}

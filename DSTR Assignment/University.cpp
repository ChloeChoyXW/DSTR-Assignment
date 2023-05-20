#include "university.h"
#include <fstream>
#include <sstream>


using namespace  std;


UniList::UniList(string uniListname) : uniListName(uniListName) {};
//create an empty new node
Uni* UniList::createNewNode(int rank, string instName, string locationCode, string location, float academicScore, int academicRank,
	float employerRepScore, int employerRepRank, float facultyStuRIScore, int facultyStuRIRank, float citePerFacultyScore,
	int citePerFacultyRank, float intFacultyRIScore, int intFacultyRIRank, float intStuRIScore, int intStuRIRank,
	float intResearchNetScore, int intResearchNetRank, float employOutcomeScore, int employOutcomeRank, float scoreScale) {


	Uni* newnode = new Uni;

	newnode->rank = rank;
	newnode->instName = instName;
	newnode->locationCode = locationCode;
	newnode->location = location;
	newnode->academicScore = academicScore;
	newnode->academicRank = academicRank;
	newnode->employerRepScore = employerRepScore;
	newnode->employerRepRank = employerRepRank;
	newnode->facultyStuRIScore = facultyStuRIScore;
	newnode->facultyStuRIRank = facultyStuRIRank;
	newnode->citePerFacultyScore = citePerFacultyScore;
	newnode->citePerFacultyRank = citePerFacultyRank;
	newnode->intFacultyRIScore = facultyStuRIScore;
	newnode->intFacultyRIRank = intFacultyRIRank;
	newnode->intStuRIScore = intStuRIScore;
	newnode->intStuRIRank = intStuRIRank;
	newnode->intResearchNetScore = intResearchNetScore;
	newnode->intResearchNetRank = intResearchNetRank;
	newnode->employOutcomeScore = employOutcomeScore;
	newnode->employOutcomeRank = employOutcomeRank;
	newnode->scoreScale = scoreScale;
	newnode->nextAdd = NULL;
	newnode->prevAdd = NULL;

	return newnode;

}

void UniList::insertToEndOfUniLinkedList(int rank, string instName, string locationCode, string location, float academicScore, int academicRank,
	float employerRepScore, int employerRepRank, float facultyStuRIScore, int facultyStuRIRank, float citePerFacultyScore,
	int citePerFacultyRank, float intFacultyRIScore, int intFacultyRIRank, float intStuRIScore, int intStuRIRank,
	float intResearchNetScore, int intResearchNetRank, float employOutcomeScore, int employOutcomeRank, float scoreScale) {

	Uni* newnode = createNewNode(rank, instName, locationCode, location, academicScore, academicRank,
		employerRepScore, employerRepRank, facultyStuRIScore, facultyStuRIRank, citePerFacultyScore,
		citePerFacultyRank, intFacultyRIScore, intFacultyRIRank, intStuRIScore, intStuRIRank,
		intResearchNetScore, intResearchNetRank, employOutcomeScore, employOutcomeRank, scoreScale);

	if (head == NULL) {
		head = tail = newnode;
	}
	else {
		newnode->prevAdd = tail;
		tail->nextAdd = newnode;
		tail = newnode;
	}

}

void UniList::readFromFile() {
	head = NULL; //this list is empty now
	int count = 0;

	string rank, instName, locationCode, location, academicScore, academicRank, employerRepScore, employerRepRank,
		facultyStuRIScore, facultyStuRIRank, citePerFacultyScore, citePerFacultyRank, intFacultyRIScore, intFacultyRIRank,
		intStuRIScore, intStuRIRank, intResearchNetScore, intResearchNetRank, employOutcomeScore, employOutcomeRank, scoreScale;

	ifstream file("2023_QS_World_University_Rankings.csv");
	string line;

	//getline(file, line)
	while (file.good())
	{
		stringstream ss(line);
		getline(file, rank, ',');
		getline(file, instName, ',');
		getline(file, locationCode, ',');
		getline(file, location, ',');
		getline(file, academicScore, ',');
		getline(file, academicRank, ',');
		getline(file, employerRepScore, ',');
		getline(file, employerRepRank, ',');
		getline(file, facultyStuRIScore, ',');
		getline(file, facultyStuRIRank, ',');
		getline(file, citePerFacultyScore, ',');
		getline(file, citePerFacultyRank, ',');
		getline(file, intFacultyRIScore, ',');
		getline(file, intFacultyRIRank, ',');
		getline(file, intStuRIScore, ',');
		getline(file, intStuRIRank, ',');
		getline(file, intResearchNetScore, ',');
		getline(file, intResearchNetRank, ',');
		getline(file, employOutcomeScore, ',');
		getline(file, employOutcomeRank, ',');
		getline(file, scoreScale);

		if (count == 0)
		{
			count += 1;
			continue;
		}
		else if (rank == "")
		{
			break;
		}

		try {
			insertToEndOfUniLinkedList(stoi(rank), instName, locationCode, location, stof(academicScore), stoi(academicRank), stof(employerRepScore),
				stoi(employerRepRank), stof(facultyStuRIScore), stoi(facultyStuRIRank), stof(citePerFacultyScore), stoi(citePerFacultyRank),
				stof(intFacultyRIScore), stoi(intFacultyRIRank), stof(intStuRIScore), stoi(intStuRIRank), stof(intResearchNetScore),
				stoi(intResearchNetRank), stof(employOutcomeScore), stoi(employOutcomeRank), stof(scoreScale));

			/*insertToEndOfUniLinkedList(rank, instName, locationCode, location, academicScore, academicRank, employerRepScore,
				employerRepRank, facultyStuRIScore, facultyStuRIRank, citePerFacultyScore, citePerFacultyRank,
				intFacultyRIScore, intFacultyRIRank, intStuRIScore, intStuRIRank, intResearchNetScore,
				intResearchNetRank, employOutcomeScore, employOutcomeRank, scoreScale);*/
			

		}
		catch (exception e) {
			cout << "Error occured. Please try again later." << endl;
		}

	}
	
}

void UniList::searchUni(string searchCondition) {

}

void UniList::insertUniArray() {

}

//======================================================================================================
// function to insert a new node in sorted way in
// a sorted doubly linked list
void sortedInsert(Uni** head, Uni* newNode, int sortCondition)
{
	Uni* current;

	switch (sortCondition) {
	case 1:

		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->rank >= newNode->rank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->rank < newNode->rank)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}

		break;

	case 2:
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->instName >= newNode->instName) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->instName < newNode->instName)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;

	case 3:
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->location >= newNode->location) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->location < newNode->location)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;

	case 4:
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->academicRank >= newNode->academicRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->academicRank < newNode->academicRank)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;

	case 5:
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->employerRepRank >= newNode->employerRepRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->employerRepRank < newNode->employerRepRank)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;

	case 6:
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->facultyStuRIRank >= newNode->facultyStuRIRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->facultyStuRIRank < newNode->facultyStuRIRank)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;

	case 7:
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->citePerFacultyRank >= newNode->citePerFacultyRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->citePerFacultyRank < newNode->citePerFacultyRank)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;

	case 8:
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->intFacultyRIRank >= newNode->intFacultyRIRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->intFacultyRIRank < newNode->intFacultyRIRank)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;

	case 9:
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->intStuRIRank >= newNode->intStuRIRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->intStuRIRank < newNode->intStuRIRank)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;

	case 10:
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->intResearchNetRank >= newNode->intResearchNetRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->intResearchNetRank < newNode->intResearchNetRank)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;

	case 11:
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->employOutcomeRank >= newNode->employOutcomeRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->employOutcomeRank < newNode->employOutcomeRank)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;

	case 12:
		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning
		// of the doubly linked list
		else if ((*head)->scoreScale >= newNode->scoreScale) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node
			// is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->scoreScale < newNode->scoreScale)
				current = current->nextAdd;

			/*Make the appropriate links */

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted
			// at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;
	}

}

void UniList::insertionSortUniDoublyLinkedList(int sortCondition) {
	//	/*1 = rank
	//	2 = instName,
	//	3 = location,
	//	4 = academicRank
	//	5 = employerRepRank
	//	6 = facultyStuRIRank
	//	7 = citePerFacultyRank
	//	8 = intFacultyRIRank
	//	9 = intStuRIRank
	//	10 = intResearchNetRank
	//	11 = employOutcomeRank
	//	12 = scoreScale*/
	// 
		//insertionSort(&head, sortCondition);
		// Initialize 'sorted' - a sorted doubly linked list
	Uni* sorted = NULL;

	// Traverse the given doubly linked list and
	// insert every node to 'sorted'
	Uni* current = head;
	while (current != NULL) {

		// Store next for next iteration
		Uni* next = current->nextAdd;

		// removing all the links so as to create 'current'
		// as a new node for insertion
		current->prevAdd = current->nextAdd = NULL;

		// insert current in 'sorted' doubly linked list
		sortedInsert(&sorted, current, sortCondition);

		// Update current
		current = next;
	}

	// Update head_ref to point to sorted doubly linked list
	head = sorted;


}



void UniList::displayList() {
	Uni* current = head;
	bool  contPrint = true;
	string cont = "y";
	//check if is last node, else print
	while (contPrint = true && current != NULL) {
		for (int i = 0; i < 50; i++) {
			cout << endl << "University Name: " << current->instName << endl;
			cout << "Rank: " << current->rank << endl;
			cout << "Location Code: " << current->locationCode << endl;
			cout << "Location: " << current->location << endl;
			cout << "Academic Score " << current->academicScore << endl;
			cout << "Academic Rank: " << current->academicRank << endl;
			cout << "Employer Reputation Score: " << current->employerRepScore << endl;
			cout << "Employer Reputation Rank: " << current->employerRepRank << endl;
			cout << "Faculty/Student Ratio Score: " << current->facultyStuRIScore << endl;
			cout << "Faculty/Student Ratio Rank: " << current->facultyStuRIRank << endl;
			cout << "Citations Per Faculty Score: " << current->citePerFacultyScore << endl;
			cout << "Citations Per Faculty Rank: " << current->citePerFacultyRank << endl;
			cout << "International Faculty Ratio Score: " << current->intFacultyRIScore << endl;
			cout << "International Faculty Ratio Rank: " << current->intFacultyRIRank << endl;
			cout << "International Student Ratio Score: " << current->intStuRIScore << endl;
			cout << "International Student Ratio Rank: " << current->intStuRIRank << endl;
			cout << "International Research Network Score: " << current->intResearchNetScore << endl;
			cout << "International Research Network Rank: " << current->intResearchNetRank << endl;
			cout << "Employment Outcome Score: " << current->employOutcomeScore << endl;
			cout << "Employment Outcome Rank: " << current->employOutcomeRank << endl;
			cout << "Score Scale: " << current->scoreScale << endl;
			//cout << string(55, '=') << endl;
			// 
			//move to next address
			current = current->nextAdd;
		}
		cout << "Do you want to continue printing? (Any key to continue, n to exit):" << endl;
		cin >> cont;
		//while(cont != "n" || cont != "y") {
		//	cout << "Please enter a valid response!" << endl;
		//	cout << "Do you want to continue printing? (y/n):" << endl;
		//	cin.clear();
		//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//	cin >> cont;
		//}

		if (cont == "n") {
			break;
		}	
	}
	cout << "List ended here." << endl;
}
#include "university.h"


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

	string rank, instName, locationCode, location, academicScore, academicRank, employerRepScore, employerRepRank,
		facultyStuRIScore, facultyStuRIRank, citePerFacultyScore, citePerFacultyRank, intFacultyRIScore, intFacultyRIRank,
		intStuRIScore, intStuRIRank, intResearchNetScore, intResearchNetRank, employOutcomeScore, employOutcomeRank, scoreScale;

	/*ifstream file("2023_QS_World_University_Rankings.csv");

	while (file.good())
	{
		getline(file, rank, ',');
		getline(file, instName, ',');
		getline(file, locationCode, ',');
		getline(file, location);
		getline(file, academicScore, ',');
		getline(file, academicRank, ',');
		getline(file, employerRepScore);
		getline(file, employerRepRank, ',');
		getline(file, facultyStuRIScore, ',');
		getline(file, facultyStuRIRank);
		getline(file, citePerFacultyScore, ',');
		getline(file, citePerFacultyRank, ',');
		getline(file, intFacultyRIScore);
		getline(file, intFacultyRIRank, ',');
		getline(file, intStuRIScore, ',');
		getline(file, intStuRIRank);
		getline(file, intResearchNetScore, ',');
		getline(file, intResearchNetRank);
		getline(file, employOutcomeScore, ',');
		getline(file, employOutcomeRank);
		getline(file, scoreScale, ',');*/

		/*if (rank == "Rank")
		{
			continue;
		}
		else if (rank == "")
		{
			break;
		}*/
		
		//try {
			/*insertToEndOfUniLinkedList(stoi(rank), instName, locationCode, location, stof(academicScore), stoi(academicRank), stof(employerRepScore),
				stoi(employerRepRank), stof(facultyStuRIScore), stoi(facultyStuRIRank), stof(citePerFacultyScore), stoi(citePerFacultyRank),
				stof(intFacultyRIScore), stoi(intFacultyRIRank), stof(intStuRIScore), stoi(intStuRIRank), stof(intResearchNetScore),
				stoi(intResearchNetRank), stof(employOutcomeScore), stoi(employOutcomeRank), stof(scoreScale));*/
			insertToEndOfUniLinkedList(3, "instName", "locationCode", "location", 1, 1, 1,	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1,1, 1);
			insertToEndOfUniLinkedList(2, "instName", "locationCode", "location", 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);
			insertToEndOfUniLinkedList(1, "instName", "locationCode", "location", 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3);
			insertToEndOfUniLinkedList(4, "instName", "locationCode", "location", 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
			insertToEndOfUniLinkedList(5, "instName", "locationCode", "location", 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);

		/*}
		catch(exception e){
			cout << "Error occured. Please try again later." << endl;
		}*/
		
	//}
}

void UniList::searchUni(string searchCondition) {

}

void UniList::insertUniArray() {

}

void UniList::insertionSortUniDoublyLinkedList(int sortCondition) {
	/*1 = rank
	2 = instName,
	3 = location,
	4 = academicRank
	5 = employerRepRank
	6 = facultyStuRIRank
	7 = citePerFacultyRank
	8 = intFacultyRIRank
	9 = intStuRIRank
	10 = intResearchNetRank
	11 = employOutcomeRank
	12 = scoreScale*/

	//Uni* current = head;

	//while (current != NULL) { //when the list is not empty
	//	Uni* temp;
	//	switch (sortCondition)
	//	{
	//	case 1:
	//		if (current->rank < current->nextAdd->rank) {
	//			current = current->nextAdd;
	//		}
	//		else {
	//			temp = current;
	//			current->prevAdd->nextAdd = current->nextAdd;
	//			current->nextAdd->prevAdd = current->prevAdd;
	//		}
	//		break;
	//	}
	//}
	Uni* marker;
	Uni* now;

	for (marker = head->nextAdd; marker != NULL; marker = marker->nextAdd)
	{
		int temp = marker->rank;
		cout << temp << endl;
		now = marker;

		// this line throws the exception: read access violation.
		// current->prev was nullptr.                                       
		while (now->prevAdd != NULL && now->prevAdd->rank >= temp)
		{
			now->rank = now->prevAdd->rank;
			now = now->prevAdd;
		}
		now->rank = temp;
	}

}

void UniList::displayList() {
	Uni* current = head;
	//check if is last node, else print
	while (current != NULL) {
		cout << "University Name: " << current->instName << endl;
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
		cout << string(55, '=') << endl;



		//move to next address
		current = current->nextAdd;
	}
	cout << "List ended here."<<endl;
}
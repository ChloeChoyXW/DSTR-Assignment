#include "university.h"
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

UniList::UniList(string uniListName) : uniListName(uniListName) {};


//=====================Read From Excel and Insert to Doubly Linked List=================
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


void UniList::readFromFileDoubly() {
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
			

		}
		catch (exception e) {
			cout << "Error occured. Please try again later." << endl;
		}

	}
	
}


//=======================Read From Excel and Insert to Array===========================
void UniList::insertUniArray(int loopNum, struct Uni array[], int rank, string instName, string locationCode, string location, float academicScore, int academicRank,
	float employerRepScore, int employerRepRank, float facultyStuRIScore, int facultyStuRIRank, float citePerFacultyScore,
	int citePerFacultyRank, float intFacultyRIScore, int intFacultyRIRank, float intStuRIScore, int intStuRIRank,
	float intResearchNetScore, int intResearchNetRank, float employOutcomeScore, int employOutcomeRank, float scoreScale){
	array[loopNum].rank = rank;
	array[loopNum].instName = instName;
	array[loopNum].locationCode = locationCode;
	array[loopNum].location = location;
	array[loopNum].academicScore = academicScore;
	array[loopNum].academicRank = academicRank;
	array[loopNum].employerRepScore = employerRepScore;
	array[loopNum].employerRepRank = employerRepRank;
	array[loopNum].facultyStuRIScore = facultyStuRIScore;
	array[loopNum].facultyStuRIRank = facultyStuRIRank;
	array[loopNum].citePerFacultyScore = citePerFacultyScore;
	array[loopNum].citePerFacultyRank = citePerFacultyRank;
	array[loopNum].intFacultyRIScore = intFacultyRIScore;
	array[loopNum].intFacultyRIRank = intFacultyRIRank;
	array[loopNum].intStuRIScore = intStuRIScore;
	array[loopNum].intStuRIRank = intStuRIRank;
	array[loopNum].intResearchNetScore = intResearchNetScore;
	array[loopNum].intResearchNetRank = intResearchNetRank;
	array[loopNum].employOutcomeScore = employOutcomeScore;
	array[loopNum].employOutcomeRank = employOutcomeRank;
	array[loopNum].scoreScale = scoreScale;
}

void UniList::readFromFileArray() {
	int count = 0;
	int loopNum = 0;

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
			insertUniArray(loopNum, uniArray, stoi(rank), instName, locationCode, location, stof(academicScore), stoi(academicRank), stof(employerRepScore),
				stoi(employerRepRank), stof(facultyStuRIScore), stoi(facultyStuRIRank), stof(citePerFacultyScore), stoi(citePerFacultyRank),
				stof(intFacultyRIScore), stoi(intFacultyRIRank), stof(intStuRIScore), stoi(intStuRIRank), stof(intResearchNetScore),
				stoi(intResearchNetRank), stof(employOutcomeScore), stoi(employOutcomeRank), stof(scoreScale));

			loopNum += 1;
		}
		catch (exception e) {
			cout << "Error occured. Please try again later." << endl;
		}

	}

}


//====linear Search Doubly Inst Name without print
string UniList::linearSearchDoubly(string instName) {

	if (head == NULL) {
		cout << "Nothing in the list!";
	}
	bool found = false;
	string available;
	Uni* current = head;

	while (current != NULL) {
		if (current->instName == instName) {
			return "y";
		}
		current = current->nextAdd;
	}

	return "n";

}

//============Linear Search Doubly Linked List=================================
void UniList::linearSearchUniAndDisplayDoubly(int searchCondition, string strparameter, int intparameter1, int intparameter2) {

	if (head == NULL) {
		return;
	}
	bool found = false;
	Uni* current = head;

	switch (searchCondition)
	{
	case 1:
		while (current != NULL) {
			if (current->locationCode == strparameter) {
				found = true;

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
				cout << string(55, '=') << endl;
			}
			current = current->nextAdd;

		}
		if (!found)
			cout << "No university is found in " << strparameter << "!" << endl;
		break;
	case 2:
		while (current != NULL) {
			if (current->instName == strparameter) {
				found = true;
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
				cout << string(55, '=') << endl;
			}
			current = current->nextAdd;
		}
		if (!found)
			cout << "No university is found!" << endl;
		break;

	case 3:
		cin.ignore(10000, '\n');
		while (current != NULL) {
			if (intparameter1 <= current->academicRank && current->academicRank <= intparameter2) {
				found = true;
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
				cout << string(55, '=') << endl;
			}
			current = current->nextAdd;
		}
		if (!found)
			cout << "No university is found!" << endl;
		break;

	case 4:
		while (current != NULL) {
			if (intparameter1 <= current->employerRepRank && current->employerRepRank <= intparameter2) {
				found = true;
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
				cout << string(55, '=') << endl;
			}
			current = current->nextAdd;
		}
		if (!found)
			cout << "No university is found!" << endl;
		break;

	case 5:
		while (current != NULL) {
			if (intparameter1 <= current->facultyStuRIRank && current->facultyStuRIRank <= intparameter2) {
				found = true;
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
				cout << string(55, '=') << endl;
			}
			current = current->nextAdd;
		}
		if (!found)
			cout << "No university is found!" << endl;
		break;

	case 6:
		while (current != NULL) {
			if (intparameter1 <= current->citePerFacultyRank && current->citePerFacultyRank <= intparameter2) {
				found = true;
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
				cout << string(55, '=') << endl;
			}
			current = current->nextAdd;
		}
		if (!found)
			cout << "No university is found!" << endl;
		break;

	case 7:
		while (current != NULL) {
			if (intparameter1 <= current->intFacultyRIRank && current->intFacultyRIRank <= intparameter2) {
				found = true;
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
				cout << string(55, '=') << endl;
			}
			current = current->nextAdd;
		}
		if (!found)
			cout << "No university is found!" << endl;
		break;

	case 8:
		while (current != NULL) {
			if (intparameter1 <= current->intStuRIRank && current->intStuRIRank <= intparameter2) {
				found = true;
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
				cout << string(55, '=') << endl;
			}
			current = current->nextAdd;
		}
		if (!found)
			cout << "No university is found!" << endl;
		break;

	case 9:
		while (current != NULL) {
			if (intparameter1 <= current->intResearchNetRank && current->intResearchNetRank <= intparameter2) {
				found = true;
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
				cout << string(55, '=') << endl;
			}
			current = current->nextAdd;
		}
		if (!found)
			cout << "No university is found!" << endl;
		break;

	case 10:
		while (current != NULL) {
			if (intparameter1 <= current->employOutcomeRank && current->employOutcomeRank <= intparameter2) {
				found = true;
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
				cout << string(55, '=') << endl;
			}
			current = current->nextAdd;
		}
		if (!found) {
			cout << "No university is found!" << endl;
		}
		break;

	case 11:
		while (current != NULL) {
			if (intparameter1 <= current->rank && current->rank <= intparameter2) {
				found = true;
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
				cout << string(55, '=') << endl;
			}
			current = current->nextAdd;
		}
		if (!found) {
			cout << "No university is found!" << endl;
		}
		break;
	}
}



//=============================Linear Search Array===================================================================
//from: https://www.geeksforgeeks.org/linear-search/
void UniList::linearSearchUniAndDisplayArray(string instName) {
	bool found = false;
	for (int i = 0; i < 1423; i++) {
		if (uniArray[i].instName == instName) {
			found = true;
			cout << endl << "University Name: " << uniArray[i].instName << endl;
			cout << "Rank: " << uniArray[i].rank << endl;
			cout << "Location Code: " << uniArray[i].locationCode << endl;
			cout << "Location: " << uniArray[i].location << endl;
			cout << "Academic Score " << uniArray[i].academicScore << endl;
			cout << "Academic Rank: " << uniArray[i].academicRank << endl;
			cout << "Employer Reputation Score: " << uniArray[i].employerRepScore << endl;
			cout << "Employer Reputation Rank: " << uniArray[i].employerRepRank << endl;
			cout << "Faculty/Student Ratio Score: " << uniArray[i].facultyStuRIScore << endl;
			cout << "Faculty/Student Ratio Rank: " << uniArray[i].facultyStuRIRank << endl;
			cout << "Citations Per Faculty Score: " << uniArray[i].citePerFacultyScore << endl;
			cout << "Citations Per Faculty Rank: " << uniArray[i].citePerFacultyRank << endl;
			cout << "International Faculty Ratio Score: " << uniArray[i].intFacultyRIScore << endl;
			cout << "International Faculty Ratio Rank: " << uniArray[i].intFacultyRIRank << endl;
			cout << "International Student Ratio Score: " << uniArray[i].intStuRIScore << endl;
			cout << "International Student Ratio Rank: " << uniArray[i].intStuRIRank << endl;
			cout << "International Research Network Score: " << uniArray[i].intResearchNetScore << endl;
			cout << "International Research Network Rank: " << uniArray[i].intResearchNetRank << endl;
			cout << "Employment Outcome Score: " << uniArray[i].employOutcomeScore << endl;
			cout << "Employment Outcome Rank: " << uniArray[i].employOutcomeRank << endl;
			cout << "Score Scale: " << uniArray[i].scoreScale << endl;
			cout << string(55, '=') << endl;
		}
	}
	if (!found)
		cout << "No university is found!" << endl;
}


//=============================Binary Search Array===================================================================
//from https://www.geeksforgeeks.org/insertion-sort/ & https://www.geeksforgeeks.org/binary-search-a-string/
void insertionSortArray(struct Uni uniArray[]){
	int i, j;
	int rank;
	string instName;
	string locationCode;
	string location;
	float academicScore;
	int academicRank;
	float employerRepScore;
	int employerRepRank;
	float facultyStuRIScore;
	int facultyStuRIRank;
	float citePerFacultyScore;
	int citePerFacultyRank;
	float intFacultyRIScore;
	int intFacultyRIRank;
	float intStuRIScore;
	int intStuRIRank;
	float intResearchNetScore;
	int intResearchNetRank;
	float employOutcomeScore;
	int employOutcomeRank;
	float scoreScale;
	for (i = 1; i < 1422; i++) {
		rank = uniArray[i].rank;
		instName = uniArray[i].instName;
		locationCode = uniArray[i].locationCode;
		location = uniArray[i].location;
		academicScore = uniArray[i].academicScore;
		academicRank = uniArray[i].academicRank;
		employerRepScore = uniArray[i].employerRepScore;
		employerRepRank = uniArray[i].employerRepRank;
		facultyStuRIScore = uniArray[i].intFacultyRIScore;
		facultyStuRIRank = uniArray[i].facultyStuRIRank;
		citePerFacultyScore = uniArray[i].citePerFacultyScore;
		citePerFacultyRank = uniArray[i].citePerFacultyRank;
		intFacultyRIScore = uniArray[i].intFacultyRIScore;
		intFacultyRIRank = uniArray[i].intFacultyRIRank;
		intStuRIScore = uniArray[i].intStuRIScore;
		intStuRIRank = uniArray[i].intStuRIRank;
		intResearchNetScore = uniArray[i].intResearchNetScore;
		intResearchNetRank = uniArray[i].intResearchNetRank;
		employOutcomeScore = uniArray[i].employOutcomeScore;
		employOutcomeRank = uniArray[i].employOutcomeRank;
		scoreScale = uniArray[i].scoreScale;

		j = i - 1;

		// Move elements of arr[0..i-1], 
		// that are greater than key, to one
		// position ahead of their
		// current position
		while (j >= 0 && uniArray[j].instName > instName)
		{
			uniArray[j + 1] = uniArray[j];
			
			j = j - 1;
		}
		
		uniArray[j + 1].rank = rank;
		uniArray[j + 1].instName = instName;
		uniArray[j + 1].locationCode = locationCode;
		uniArray[j + 1].location = location;
		uniArray[j + 1].academicScore = academicScore;
		uniArray[j + 1].academicRank = academicRank;
		uniArray[j + 1].employerRepScore = employerRepScore;
		uniArray[j + 1].employerRepRank = employerRepRank;
		uniArray[j + 1].facultyStuRIScore =intFacultyRIScore;
		uniArray[j + 1].facultyStuRIRank = facultyStuRIRank;
		uniArray[j + 1].citePerFacultyScore = citePerFacultyScore;
		uniArray[j + 1].citePerFacultyRank = citePerFacultyRank;
		uniArray[j + 1].intFacultyRIScore = intFacultyRIScore;
		uniArray[j + 1].intFacultyRIRank = intFacultyRIRank;
		uniArray[j + 1].intStuRIScore = intStuRIScore;
		uniArray[j + 1].intStuRIRank = intStuRIRank;
		uniArray[j + 1].intResearchNetScore = intResearchNetScore;
		uniArray[j + 1].intResearchNetRank = intResearchNetRank;
		uniArray[j + 1].employOutcomeScore = employOutcomeScore;
		uniArray[j + 1].employOutcomeRank = employOutcomeRank;
		uniArray[j + 1].scoreScale = scoreScale;
	}

}

void UniList::binarySearchUniAndDisplayArray(){
	insertionSortArray(uniArray);
	int r = 1422 - 1;
	int l = 0;
	string x;
	int y;
	cout << "Enter Institution Name: ";
	getline(cin, x);
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		int res = -1000;   //some random value assigned because if res is already 0 then
		//it will always return 0    
		if (x == (uniArray[mid].instName)) {
			res = 0;	
		}

		// Check if x is present at mid
		if (res == 0) {
			cout << endl << "University Name: " << uniArray[mid].instName << endl;
			cout << "Rank: " << uniArray[mid].rank << endl;
			cout << "Location Code: " << uniArray[mid].locationCode << endl;
			cout << "Location: " << uniArray[mid].location << endl;
			cout << "Academic Score " << uniArray[mid].academicScore << endl;
			cout << "Academic Rank: " << uniArray[mid].academicRank << endl;
			cout << "Employer Reputation Score: " << uniArray[mid].employerRepScore << endl;
			cout << "Employer Reputation Rank: " << uniArray[mid].employerRepRank << endl;
			cout << "Faculty/Student Ratio Score: " << uniArray[mid].facultyStuRIScore << endl;
			cout << "Faculty/Student Ratio Rank: " << uniArray[mid].facultyStuRIRank << endl;
			cout << "Citations Per Faculty Score: " << uniArray[mid].citePerFacultyScore << endl;
			cout << "Citations Per Faculty Rank: " << uniArray[mid].citePerFacultyRank << endl;
			cout << "International Faculty Ratio Score: " << uniArray[mid].intFacultyRIScore << endl;
			cout << "International Faculty Ratio Rank: " << uniArray[mid].intFacultyRIRank << endl;
			cout << "International Student Ratio Score: " << uniArray[mid].intStuRIScore << endl;
			cout << "International Student Ratio Rank: " << uniArray[mid].intStuRIRank << endl;
			cout << "International Research Network Score: " << uniArray[mid].intResearchNetScore << endl;
			cout << "International Research Network Rank: " << uniArray[mid].intResearchNetRank << endl;
			cout << "Employment Outcome Score: " << uniArray[mid].employOutcomeScore << endl;
			cout << "Employment Outcome Rank: " << uniArray[mid].employOutcomeRank << endl;
			cout << "Score Scale: " << uniArray[mid].scoreScale << endl;
			cout << string(55, '=') << endl;
		}

		// If x greater, ignore left half
		if (x > (uniArray[mid].instName)) {
			l = mid + 1;
		}

		// If x is smaller, ignore right half
		else {
			r = mid - 1;
		}
	}

}



//============================Insertion Sort Doubly Linked List====================
// function to insert a new node in sorted way in a sorted doubly linked list
void sortedInsert(Uni** head, Uni* newNode, int sortCondition){
	Uni* current;

	switch (sortCondition) {
	//	1 = rank
	case 1:

		// if list is empty
		if (*head == NULL) {
			*head = newNode;
		}
		// if the node is to be inserted at the beginning of the doubly linked list
		else if ((*head)->rank >= newNode->rank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			// locate the node after which the new node is to be inserted
			while (current->nextAdd != NULL &&
				current->nextAdd->rank < newNode->rank)
				current = current->nextAdd;

			newNode->nextAdd = current->nextAdd;

			// if the new node is not inserted at the end of the list
			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}

		break;

	//	2 = instName,
	case 2:
		if (*head == NULL) {
			*head = newNode;
		}

		else if ((*head)->instName >= newNode->instName) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			while (current->nextAdd != NULL &&
				current->nextAdd->instName < newNode->instName)
				current = current->nextAdd;

			newNode->nextAdd = current->nextAdd;

			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;
		
	//	3 = location,
	case 3:
		if (*head == NULL) {
			*head = newNode;
		}

		else if ((*head)->location >= newNode->location) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			while (current->nextAdd != NULL &&
				current->nextAdd->location < newNode->location)
				current = current->nextAdd;

			newNode->nextAdd = current->nextAdd;

			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;
		
	//	4 = academicRank
	case 4:

		if (*head == NULL) {
			*head = newNode;
		}

		else if ((*head)->academicRank >= newNode->academicRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			while (current->nextAdd != NULL &&
				current->nextAdd->academicRank < newNode->academicRank)
				current = current->nextAdd;

			newNode->nextAdd = current->nextAdd;

			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;
		
	//	5 = employerRepRank
	case 5:

		if (*head == NULL) {
			*head = newNode;
		}

		else if ((*head)->employerRepRank >= newNode->employerRepRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			while (current->nextAdd != NULL &&
				current->nextAdd->employerRepRank < newNode->employerRepRank)
				current = current->nextAdd;

			newNode->nextAdd = current->nextAdd;

			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;
		
	//	6 = facultyStuRIRank
	case 6:

		if (*head == NULL) {
			*head = newNode;
		}

		else if ((*head)->facultyStuRIRank >= newNode->facultyStuRIRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			while (current->nextAdd != NULL &&
				current->nextAdd->facultyStuRIRank < newNode->facultyStuRIRank)
				current = current->nextAdd;

			newNode->nextAdd = current->nextAdd;

			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;
		
	//	7 = citePerFacultyRank
	case 7:

		if (*head == NULL) {
			*head = newNode;
		}

		else if ((*head)->citePerFacultyRank >= newNode->citePerFacultyRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			while (current->nextAdd != NULL &&
				current->nextAdd->citePerFacultyRank < newNode->citePerFacultyRank)
				current = current->nextAdd;


			newNode->nextAdd = current->nextAdd;

			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;
		
	//	8 = intFacultyRIRank
	case 8:

		if (*head == NULL) {
			*head = newNode;
		}

		else if ((*head)->intFacultyRIRank >= newNode->intFacultyRIRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			while (current->nextAdd != NULL &&
				current->nextAdd->intFacultyRIRank < newNode->intFacultyRIRank)
				current = current->nextAdd;

			newNode->nextAdd = current->nextAdd;

			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;
		
	//	9 = intStuRIRank
	case 9:

		if (*head == NULL) {
			*head = newNode;
		}

		else if ((*head)->intStuRIRank >= newNode->intStuRIRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			while (current->nextAdd != NULL &&
				current->nextAdd->intStuRIRank < newNode->intStuRIRank)
				current = current->nextAdd;


			newNode->nextAdd = current->nextAdd;

			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;

		
	//	10 = intResearchNetRank
	case 10:
		if (*head == NULL) {
			*head = newNode;
		}

		else if ((*head)->intResearchNetRank >= newNode->intResearchNetRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			while (current->nextAdd != NULL &&
				current->nextAdd->intResearchNetRank < newNode->intResearchNetRank)
				current = current->nextAdd;

			newNode->nextAdd = current->nextAdd;

			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;
 
	//	11 = employOutcomeRank
	case 11:
		if (*head == NULL) {
			*head = newNode;
		}

		else if ((*head)->employOutcomeRank >= newNode->employOutcomeRank) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			while (current->nextAdd != NULL &&
				current->nextAdd->employOutcomeRank < newNode->employOutcomeRank)
				current = current->nextAdd;

			newNode->nextAdd = current->nextAdd;

			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;
		
	//	12 = scoreScale
	case 12:
		if (*head == NULL) {
			*head = newNode;
		}
		else if ((*head)->scoreScale >= newNode->scoreScale) {
			newNode->nextAdd = *head;
			newNode->nextAdd->prevAdd = newNode;
			*head = newNode;
		}

		else {
			current = *head;

			while (current->nextAdd != NULL &&
				current->nextAdd->scoreScale < newNode->scoreScale)
				current = current->nextAdd;


			newNode->nextAdd = current->nextAdd;

			if (current->nextAdd != NULL)
				newNode->nextAdd->prevAdd = newNode;

			current->nextAdd = newNode;
			newNode->prevAdd = current;
		}
		break;
	}

}

void UniList::insertionSortUniDoublyLinkedList(int sortCondition) { 
		// Initialize a sorted doubly linked list
	Uni* sorted = NULL;

	// Traverse the given doubly linked list and insert every node to sorted doubly linked list
	Uni* current = head;
	while (current != NULL) {

		// Store next for next iteration
		Uni* next = current->nextAdd;

		// removing all the links so as to create 'current' as a new node for insertion
		current->prevAdd = current->nextAdd = NULL;

		
		// insert current in 'sorted' doubly linked list
		sortedInsert(&sorted, current, sortCondition);

		// Update current
		current = next;
	}

	// Update head_ref to point to sorted doubly linked list
	head = sorted;
	
}


//=======================Quick sort============================================
//From https://www.geeksforgeeks.org/quicksort-for-linked-list/

/* A utility function to swap two elements */
void uniSwap(string* a, string* b)
{
	string t = *a; *a = *b; *b = t;
}

void uniSwap(int* a, int* b)
{
	int t = *a; *a = *b; *b = t;
}

void uniSwap(float* a, float* b)
{
	float t = *a; *a = *b; *b = t;
}

// A utility function to find
// last node of linked list
Uni* lastNode(Uni* end)
{
	while (end && end->nextAdd)
		end = end->nextAdd;
	return end;
}

void swappingValue(Uni* i, Uni* j) {
	uniSwap(&(i->rank), &(j->rank));
	uniSwap(&(i->instName), &(j->instName));
	uniSwap(&(i->locationCode), &(j->locationCode));
	uniSwap(&(i->location), &(j->location));
	uniSwap(&(i->academicScore), &(j->academicScore));
	uniSwap(&(i->academicRank), &(j->academicRank));
	uniSwap(&(i->employerRepScore), &(j->employerRepScore));
	uniSwap(&(i->employerRepRank), &(j->employerRepRank));
	uniSwap(&(i->facultyStuRIScore), &(j->facultyStuRIScore));
	uniSwap(&(i->facultyStuRIRank), &(j->facultyStuRIRank));
	uniSwap(&(i->citePerFacultyScore), &(j->citePerFacultyScore));
	uniSwap(&(i->citePerFacultyRank), &(j->citePerFacultyRank));
	uniSwap(&(i->intFacultyRIScore), &(j->intFacultyRIScore));
	uniSwap(&(i->intFacultyRIRank), &(j->intFacultyRIRank));
	uniSwap(&(i->intStuRIScore), &(j->intStuRIScore));
	uniSwap(&(i->intStuRIRank), &(j->intStuRIRank));
	uniSwap(&(i->intResearchNetScore), &(j->intResearchNetScore));
	uniSwap(&(i->intResearchNetRank), &(j->intResearchNetRank));
	uniSwap(&(i->employOutcomeScore), &(j->employOutcomeScore));
	uniSwap(&(i->employOutcomeRank), &(j->employOutcomeRank));
	uniSwap(&(i->scoreScale), &(j->scoreScale));
}

/* Considers last element as pivot,
places the pivot element at its
correct position in sorted array,
and places all smaller (smaller than
pivot) to left of pivot and all greater
elements to right of pivot */
Uni* partition(Uni* l, Uni* h, int searchCondition){
	Uni* i = l->prevAdd;
	string y;
	int x;
	//	1 = rank
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
	//	12 = scoreScale
	switch (searchCondition) {
	case 1:
		// set pivot as h element
		x = h->rank;

		// Similar to "for (int j = l; j <= h- 1; j++)"
		for (Uni* j = l; j != h; j = j->nextAdd)
		{
			if (j->rank <= x)
			{
				// Similar to i++ for array
				i = (i == NULL) ? l : i->nextAdd;
				swappingValue(i, j);
			}
		}
		i = (i == NULL) ? l : i->nextAdd; // Similar to i++
		swappingValue(i, h);
		return i;

	case 2:
		y = h->instName;
		for (Uni* j = l; j != h; j = j->nextAdd)
		{
			if (j->instName <= y)
			{
				// Similar to i++ for array
				i = (i == NULL) ? l : i->nextAdd;
				swappingValue(i, j);
			}
		}
		i = (i == NULL) ? l : i->nextAdd; // Similar to i++
		swappingValue(i, h);
		return i;

	case 3:
		y = h->location;
		for (Uni* j = l; j != h; j = j->nextAdd)
		{
			if (j->location <= y)
			{
				// Similar to i++ for array
				i = (i == NULL) ? l : i->nextAdd;
				swappingValue(i, j);
			}
		}
		i = (i == NULL) ? l : i->nextAdd; // Similar to i++
		swappingValue(i, h);
		return i;

	case 4:
		x = h->academicRank;
		for (Uni* j = l; j != h; j = j->nextAdd)
		{
			if (j->academicRank <= x)
			{
				// Similar to i++ for array
				i = (i == NULL) ? l : i->nextAdd;
				swappingValue(i, j);
			}
		}
		i = (i == NULL) ? l : i->nextAdd; // Similar to i++
		swappingValue(i, h);
		return i;

	case 5:
		x = h->employerRepRank;
		for (Uni* j = l; j != h; j = j->nextAdd)
		{
			if (j->employerRepRank <= x)
			{
				// Similar to i++ for array
				i = (i == NULL) ? l : i->nextAdd;
				swappingValue(i, j);
			}
		}
		i = (i == NULL) ? l : i->nextAdd; // Similar to i++
		swappingValue(i, h);
		return i;

	case 6:
		x = h->facultyStuRIRank;
		for (Uni* j = l; j != h; j = j->nextAdd)
		{
			if (j->facultyStuRIRank <= x)
			{
				// Similar to i++ for array
				i = (i == NULL) ? l : i->nextAdd;
				swappingValue(i, j);
			}
		}
		i = (i == NULL) ? l : i->nextAdd; // Similar to i++
		swappingValue(i, h);
		return i;

	case 7:
		x = h->citePerFacultyRank;
		for (Uni* j = l; j != h; j = j->nextAdd)
		{
			if (j->citePerFacultyRank <= x)
			{
				// Similar to i++ for array
				i = (i == NULL) ? l : i->nextAdd;
				swappingValue(i, j);
			}
		}
		i = (i == NULL) ? l : i->nextAdd; // Similar to i++
		swappingValue(i, h);
		return i;

	case 8:
		x = h->intFacultyRIRank;
		for (Uni* j = l; j != h; j = j->nextAdd)
		{
			if (j->intFacultyRIRank <= x)
			{
				// Similar to i++ for array
				i = (i == NULL) ? l : i->nextAdd;
				swappingValue(i, j);
			}
		}
		i = (i == NULL) ? l : i->nextAdd; // Similar to i++
		swappingValue(i, h);
		return i;

	case 9:
		x = h->intStuRIRank;
		for (Uni* j = l; j != h; j = j->nextAdd)
		{
			if (j->intStuRIRank <= x)
			{
				// Similar to i++ for array
				i = (i == NULL) ? l : i->nextAdd;
				swappingValue(i, j);
			}
		}
		i = (i == NULL) ? l : i->nextAdd; // Similar to i++
		swappingValue(i, h);
		return i;

	case 10:
		x = h->intResearchNetRank;
		for (Uni* j = l; j != h; j = j->nextAdd)
		{
			if (j->intResearchNetRank <= x)
			{
				// Similar to i++ for array
				i = (i == NULL) ? l : i->nextAdd;
				swappingValue(i, j);
			}
		}
		i = (i == NULL) ? l : i->nextAdd; // Similar to i++
		swappingValue(i, h);
		return i;

	case 11:
		x = h->employOutcomeRank;
		for (Uni* j = l; j != h; j = j->nextAdd)
		{
			if (j->employOutcomeRank <= x)
			{
				// Similar to i++ for array
				i = (i == NULL) ? l : i->nextAdd;
				swappingValue(i, j);
			}
		}
		i = (i == NULL) ? l : i->nextAdd; // Similar to i++
		swappingValue(i, h);
		return i;

	case 12:
		x = h->scoreScale;
		for (Uni* j = l; j != h; j = j->nextAdd)
		{
			if (j->scoreScale <= x)
			{
				// Similar to i++ for array
				i = (i == NULL) ? l : i->nextAdd;
				swappingValue(i, j);
			}
		}
		i = (i == NULL) ? l : i->nextAdd; // Similar to i++
		swappingValue(i, h);
		return i;
	}	
	
}

/* A recursive implementation
of quicksort for linked list */
void _quickSort(Uni* l, Uni* h, int searchCondition)
{
	if (h != NULL && l != h && l != h->nextAdd)
	{
		Uni* p = partition(l, h, searchCondition);
		_quickSort(l, p->prevAdd, searchCondition);
		_quickSort(p->nextAdd, h, searchCondition);
	}
}

// The main function to sort a linked list.
// It mainly calls _quickSort()
void UniList::uniQuickSort(int searchCondition)
{
	Uni* current = head;
	// Find last node
	Uni* h = lastNode(current);

	auto start = chrono::high_resolution_clock::now();
	// Call the recursive QuickSort
	_quickSort(current, h, searchCondition);
}
//=====================================================================================================


//Display Uni List
void UniList::displayListDoubly() {
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
			cout << string(55, '=') << endl;
			
			//move to next address
			current = current->nextAdd;
		}
		cout << "Do you want to continue printing? (Any key to continue, n to exit):" << endl;
		cin >> cont;


		if (cont == "n") {
			break;
		}	
	}
	cout << "List ended here." << endl;
}

void UniList::displayListArray() {
	string cont;
	int k = 49;
	int i = 0;
	//for (int i = 0; i < 1422; i++) {
		while(i<1423) {
			cout << endl << "University Name: " << uniArray[i].instName << endl;
			cout << "Rank: " << uniArray[i].rank << endl;
			cout << "Location Code: " << uniArray[i].locationCode << endl;
			cout << "Location: " << uniArray[i].location << endl;
			cout << "Academic Score " << uniArray[i].academicScore << endl;
			cout << "Academic Rank: " << uniArray[i].academicRank << endl;
			cout << "Employer Reputation Score: " << uniArray[i].employerRepScore << endl;
			cout << "Employer Reputation Rank: " << uniArray[i].employerRepRank << endl;
			cout << "Faculty/Student Ratio Score: " << uniArray[i].facultyStuRIScore << endl;
			cout << "Faculty/Student Ratio Rank: " << uniArray[i].facultyStuRIRank << endl;
			cout << "Citations Per Faculty Score: " << uniArray[i].citePerFacultyScore << endl;
			cout << "Citations Per Faculty Rank: " << uniArray[i].citePerFacultyRank << endl;
			cout << "International Faculty Ratio Score: " << uniArray[i].intFacultyRIScore << endl;
			cout << "International Faculty Ratio Rank: " << uniArray[i].intFacultyRIRank << endl;
			cout << "International Student Ratio Score: " << uniArray[i].intStuRIScore << endl;
			cout << "International Student Ratio Rank: " << uniArray[i].intStuRIRank << endl;
			cout << "International Research Network Score: " << uniArray[i].intResearchNetScore << endl;
			cout << "International Research Network Rank: " << uniArray[i].intResearchNetRank << endl;
			cout << "Employment Outcome Score: " << uniArray[i].employOutcomeScore << endl;
			cout << "Employment Outcome Rank: " << uniArray[i].employOutcomeRank << endl;
			cout << "Score Scale: " << uniArray[i].scoreScale << endl;
			cout << string(55, '=') << endl;

			if (i == k) {
				cout << "Do you want to continue printing? (Any key to continue, n to exit):" << endl;
				cin >> cont;

				if (cont == "n") {
					break;
				}
				k = k + 50;				
			}
			i += 1;
			
		}

}
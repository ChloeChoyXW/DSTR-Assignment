#pragma once

#include <iostream>
using namespace std;

struct Uni {
	int rank;
	string instName;
	string locationCode;
	string location;
	int academicScore;
	int academicRank;
	int employerRepScore;
	int employerRepRank;
	int facultyStuRIScore;
	int facultyStuRIRank;
	int citePerFacultyScore;
	int citePerFacultyRank;
	int intFacultyRIScore;
	int intFacultyRIRank;
	int intStuRIScore;
	int intStuRIRank;
	int intResearchNetScore;
	int intResearchNetRank;
	int employOutcomeScore;
	int employOutcomeRank;
	int scoreScale;
	string uniReview;
	Uni* nextAdd;
	Uni* prevAdd;
};

class UniList {
	struct Uni unilist[1442];
	Uni* head = NULL;
	Uni* tail = NULL;
	string uniListName = "";


public:
	//constructor for doubly linked list
	UniList(string uniListname);

	Uni* createNewNode(int rank, string instName, string locationCode, string location, int academicScore, int academicRank,
		int employerRepScore, int employerRepRank, int acultyStuRIScore, int facultyStuRIRank, int citePerFacultyScore,
		int citePerFacultyRank, int intFacultyRIScore, int intFacultyRIRank, int intStuRIScore, int intStuRIRank,
		int intResearchNetScore, int intResearchNetRank, int employOutcomeScore, int employOutcomeRank, int scoreScale);

	void insertToEndOfUniLinkedList(int rank, string instName, string locationCode, string location, int academicScore, int academicRank,
		int employerRepScore, int employerRepRank, int acultyStuRIScore, int facultyStuRIRank, int citePerFacultyScore,
		int citePerFacultyRank, int intFacultyRIScore, int intFacultyRIRank, int intStuRIScore, int intStuRIRank,
		int intResearchNetScore, int intResearchNetRank, int employOutcomeScore, int employOutcomeRank, int scoreScale);

	void searchUni(string searchCondition);

	void insertUniArray();

	void sortUni(string sortCondition);

	void displayList();
};

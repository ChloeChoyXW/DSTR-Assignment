#include <iostream>
#include <string>

using namespace std;

struct Uni {
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
	Uni* nextAdd;
	Uni* prevAdd;
};

class UniList {
	struct Uni uniArray[1422];
	Uni* head = NULL;
	Uni* tail = NULL;
	string uniListName;


public:
	//constructor for doubly linked list
	UniList(string uniListname);

	Uni* createNewNode(int rank, string instName, string locationCode, string location, float academicScore, int academicRank,
		float employerRepScore, int employerRepRank, float facultyStuRIScore, int facultyStuRIRank, float citePerFacultyScore,
		int citePerFacultyRank, float intFacultyRIScore, int intFacultyRIRank, float intStuRIScore, int intStuRIRank,
		float intResearchNetScore, int intResearchNetRank, float employOutcomeScore, int employOutcomeRank, float scoreScale);

	void insertToEndOfUniLinkedList(int rank, string instName, string locationCode, string location, float academicScore, int academicRank,
		float employerRepScore, int employerRepRank, float acultyStuRIScore, int facultyStuRIRank, float citePerFacultyScore,
		int citePerFacultyRank, float intFacultyRIScore, int intFacultyRIRank, float intStuRIScore, int intStuRIRank,
		float intResearchNetScore, int intResearchNetRank, float employOutcomeScore, int employOutcomeRank, float scoreScale);

	void readFromFileDoubly();

	void insertUniArray(int loopNum, struct Uni array[], int rank, string instName, string locationCode, string location, float academicScore, int academicRank,
		float employerRepScore, int employerRepRank, float facultyStuRIScore, int facultyStuRIRank, float citePerFacultyScore,
		int citePerFacultyRank, float intFacultyRIScore, int intFacultyRIRank, float intStuRIScore, int intStuRIRank,
		float intResearchNetScore, int intResearchNetRank, float employOutcomeScore, int employOutcomeRank, float scoreScale);

	void readFromFileArray();

	void linearSearchUniAndDisplayDoubly(int searchCondition);

	string linearSearchDoubly(string instName);

	void linearSearchUniAndDisplayArray(string instName);

	void binarySearchUniAndDisplayArray();

	void uniQuickSort(int searchCondition);

	void insertionSortUniDoublyLinkedList(int sortCondition);

	void displayListDoubly();

	void displayListArray();
};

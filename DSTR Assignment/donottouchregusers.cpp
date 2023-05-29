#include <string>
#include <iostream>
#include <chrono>
#include "university.h"
#include "registeredUsers.h"
#include "userFavUni.h"
#include "admin.h"

using namespace std;
//Registered Users(Customer)
//2.1 Login and logout. /
//2.2 Sort university information in descending order based on academic reputation score, faculty / student ratio score and employer reputation score. /
//2.3 Search universities details based on customer decision.
//2.4 Save their favorite universities.
//2.5 Send feedback to MoHE for further information about the University.
//2.6 Read the feedback reply from the MoHE based on latest date.

int main() {
	regUsersList regUser = regUsersList("Registered Users List");
	regUser.readRegUsersFile();
	UniList universityDoubly = UniList("University List");
	universityDoubly.readFromFileDoubly();

	//=====sort and print==================================
	/*cout << "Enter the sorting condition for university information by number :"<<endl<<"1.University Rank  2.Institution Name  3.Location  4.Academic Rank  5.Employer Reputation Rank" << endl
		<< "6.Faculty/Student Ratio Rank  7.Citation Per Faculty Rank  8.International Faculty Ratio Rank" << endl
		<< "9.International Student Ratio Rank  10.Interational Research Natwork Rank  11.Employment Outcome Rank  12.Score Scale" << endl;*/
	/*int sortNum;
	cout << "Enter: ";
	cin >> sortNum; 
	universityDoubly.insertionSortUniDoublyLinkedList(sortNum);
	universityDoubly.displayListDoubly();*/
	//====================================================

	//===============login and return userID==============
	/*string userID =  regUser.login();
	cout << userID;*/
	//====================================================

	//============search by condition and print===========
	cout << "Enter the search condition by number: " << endl << "1.Location Code  2.Institution Name  3.Academic Rank  4.Employer Reputation Rank  5.Faculty/Student Ratio Rank" << endl
		<< "6.Citation Per Faculty Rank  7.International Faculty Ratio Rank  8.International Student Ratio Rank" << endl 
		<< "9.Interational Research Natwork Rank  10.Employment Outcome Rank  11.University Rank" << endl;
	int searchNum;
	cout << "Enter: ";
	cin >> searchNum;

	universityDoubly.linearSearchUniAndDisplayDoubly(searchNum);

	universityDoubly.displayListDoubly();

	//====================================================
	
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

	return 0;
}
//#include "example.h"
//#include <iostream>
//
//using namespace std;
//
//EmployeeList::EmployeeList()
//{
//    head = nullptr;
//}
//
//EmployeeList::~EmployeeList()
//{
//    EmployeeNode* current = head;
//    while (current != nullptr)
//    {
//        EmployeeNode* temp = current;
//        current = current->NextAdd;
//        delete temp;
//    }
//}
//
//EmployeeNode* EmployeeList::createNewNode(string EmpID, string EmpName, double EmpSal)
//{
//    EmployeeNode* newnode = new EmployeeNode;
//    newnode->EmpID = EmpID;
//    newnode->EmpName = EmpName;
//    newnode->EmpSal = EmpSal;
//    newnode->NextAdd = nullptr;
//
//    return newnode;
//}
//
//void EmployeeList::InsertItemIntoSortedList(string EmpID, string EmpName, double EmpSal)
//{
//    EmployeeNode* newnode = createNewNode(EmpID, EmpName, EmpSal);
//
//    if (head == nullptr)
//    {
//        head = newnode;
//    }
//    else if (EmpID <= head->EmpID)
//    {
//        newnode->NextAdd = head;
//        head = newnode;
//    }
//    else
//    {
//        EmployeeNode* current = head->NextAdd;
//        EmployeeNode* prev = head;
//
//        while (current != nullptr)
//        {
//            if (EmpID <= current->EmpID)
//            {
//                break;
//            }
//            prev = current;
//            current = current->NextAdd;
//        }
//        prev->NextAdd = newnode;
//        newnode->NextAdd = current;
//    }
//}
//
//void EmployeeList::RemoveItemFromList(string EmpID)
//{
//    if (head == nullptr)
//    {
//        cout << "List is empty." << endl;
//        return;
//    }
//    else if (head->EmpID == EmpID)
//    {
//        EmployeeNode* temp = head;
//        head = head->NextAdd;
//        delete temp;
//        return;
//    }
//    else
//    {
//        EmployeeNode* current = head->NextAdd;
//        EmployeeNode* prev = head;
//
//        while (current != nullptr)
//        {
//            if (current->EmpID == EmpID)
//            {
//                prev->NextAdd = current->NextAdd;
//                delete current;
//                return;
//            }
//            prev = current;
//            current = current->NextAdd;
//        }
//        cout << "Employee ID not found in the list." << endl;
//    }
//}
//
//void EmployeeList::DisplayEmployeeInformation()
//{
//    EmployeeNode* current = head;
//
//    while (current != nullptr)
//    {
//        cout << "Employee ID: " << current->EmpID << endl;
//        cout << "Employee Name: " << current->EmpName << endl;
//        cout << "Employee Salary: " << current->EmpSal << endl;
//    }
//}
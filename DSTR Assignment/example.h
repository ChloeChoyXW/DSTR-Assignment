#include <string>

struct EmployeeNode
{
    std::string EmpID;
    std::string EmpName;
    double EmpSal;
    EmployeeNode* NextAdd;
};

class EmployeeList
{
public:
    EmployeeList();
    ~EmployeeList();

    void InsertItemIntoSortedList(std::string EmpID, std::string EmpName, double EmpSal);
    void RemoveItemFromList(std::string EmpID);
    void DisplayEmployeeInformation();

private:
    EmployeeNode* createNewNode(std::string EmpID, std::string EmpName, double EmpSal);

    EmployeeNode* head;
};



#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee
{
public:
    int id;
    string name, department, leaveStatus;
    float basic, bonus, deduction, workingHours;

    Employee()
    {
        id = 0;
        name = "";
        department = "";
        basic = bonus = deduction = workingHours = 0;
        leaveStatus = "Not Recorded";
    }

    // Employee Management: Update basic salary only
    void updateEmployee()
    {
        cout << "\nEmployee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Current Basic Salary: " << basic << endl;

        cout << "Enter New Basic Salary: ";
        cin >> basic;

        cout << "\nBasic salary updated successfully!\n";
        cout << "Employee record has not been deleted.\n";
    }

    // Attendance Management
    void attendanceManagement()
    {
        cout << "\nEnter Working Hours: ";
        cin >> workingHours;

        cin.ignore(10000, '\n');
        cout << "Enter Leave Status: ";
        getline(cin, leaveStatus);

        cout << "\nAttendance recorded successfully!\n";
    }

    // Salary Management
    float calculateGrossSalary()
    {
        return basic + bonus;
    }

    float calculateNetSalary()
    {
        return calculateGrossSalary() - deduction;
    }

    void salaryManagement()
    {
        cout << "\n========== SALARY DETAILS ==========\n";
        cout << "Employee ID  : " << id << endl;
        cout << "Name         : " << name << endl;
        cout << "Basic Salary : " << basic << endl;
        cout << "Bonus        : " << bonus << endl;
        cout << "Deduction    : " << deduction << endl;
        cout << "Gross Salary : " << calculateGrossSalary() << endl;
        cout << "Net Salary   : " << calculateNetSalary() << endl;
    }

    // Payroll Processing
    void processPayroll()
    {
        cout << "\n========== PAYROLL PROCESSING ==========\n";
        cout << "Employee ID  : " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Department   : " << department << endl;
        cout << "Gross Salary : " << calculateGrossSalary() << endl;
        cout << "Net Salary   : " << calculateNetSalary() << endl;
        cout << "\nPayroll processed successfully!\n";
    }

    // Salary Slip
    void generateSalarySlip()
    {
        cout << "\n========== SALARY SLIP ==========\n";
        cout << "Employee ID  : " << id << endl;
        cout << "Name         : " << name << endl;
        cout << "Department   : " << department << endl;
        cout << "Basic Salary : " << basic << endl;
        cout << "Bonus        : " << bonus << endl;
        cout << "Deduction    : " << deduction << endl;
        cout << "Gross Salary : " << calculateGrossSalary() << endl;
        cout << "Net Salary   : " << calculateNetSalary() << endl;
        cout << "=================================\n";
    }

    // Report Generation
    void generateReport()
    {
        cout << "\n========== PAYROLL REPORT ==========\n";
        cout << "Employee ID   : " << id << endl;
        cout << "Name          : " << name << endl;
        cout << "Department    : " << department << endl;
        cout << "Working Hours : " << workingHours << endl;
        cout << "Leave Status  : " << leaveStatus << endl;
        cout << "Basic Salary  : " << basic << endl;
        cout << "Bonus         : " << bonus << endl;
        cout << "Deduction     : " << deduction << endl;
        cout << "Gross Salary  : " << calculateGrossSalary() << endl;
        cout << "Net Salary    : " << calculateNetSalary() << endl;
        cout << "====================================\n";
    }
};

int main()
{
    const int MAX_EMPLOYEES = 100;
    Employee employees[MAX_EMPLOYEES];

    int employeeCount = 0;
    int choice, searchID;

    do
    {
        cout << "\n\n====================================\n";
        cout << "      EMPLOYEE PAYROLL SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Basic Salary\n";
        cout << "5. Delete Employee\n";
        cout << "6. Attendance Management\n";
        cout << "7. Salary Management\n";
        cout << "8. Payroll Processing\n";
        cout << "9. Generate Salary Slip\n";
        cout << "10. Generate Payroll Report\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // 1. Add Employee
        if (choice == 1)
        {
            if (employeeCount >= MAX_EMPLOYEES)
            {
                cout << "\nEmployee storage is full!\n";
                continue;
            }

            cout << "Enter Employee ID: ";
            cin >> searchID;

            bool duplicate = false;

            for (int i = 0; i < employeeCount; i++)
            {
                if (employees[i].id == searchID)
                {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate)
            {
                cout << "\nEmployee ID already exists!\n";
                continue;
            }

            Employee &emp = employees[employeeCount];
            emp.id = searchID;

            cin.ignore(10000, '\n');

            cout << "Enter Employee Name: ";
            getline(cin, emp.name);

            cout << "Enter Department: ";
            getline(cin, emp.department);

            cout << "Enter Basic Salary: ";
            cin >> emp.basic;

            cout << "Enter Bonus: ";
            cin >> emp.bonus;

            cout << "Enter Deduction: ";
            cin >> emp.deduction;

            employeeCount++;
            cout << "\nEmployee added successfully!\n";
        }

        // 2. Display All Employees
        else if (choice == 2)
        {
            if (employeeCount == 0)
            {
                cout << "\nNo employee records found.\n";
            }
            else
            {
                cout << "\n========== ALL EMPLOYEES ==========\n";

                cout << left
                     << setw(10) << "ID"
                     << setw(22) << "Name"
                     << setw(20) << "Department"
                     << setw(15) << "Net Salary" << endl;

                for (int i = 0; i < employeeCount; i++)
                {
                    cout << left
                         << setw(10) << employees[i].id
                         << setw(22) << employees[i].name
                         << setw(20) << employees[i].department
                         << setw(15) << fixed << setprecision(2)
                         << employees[i].calculateNetSalary()
                         << endl;
                }
            }
        }

        // Options 3 to 10 require an existing employee
        else if (choice >= 3 && choice <= 10)
        {
            if (employeeCount == 0)
            {
                cout << "\nNo employee records found.\n";
                continue;
            }

            cout << "Enter Employee ID: ";
            cin >> searchID;

            int index = -1;

            for (int i = 0; i < employeeCount; i++)
            {
                if (employees[i].id == searchID)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                cout << "\nEmployee not found!\n";
                continue;
            }

            switch (choice)
            {
                // 3. Search Employee
                case 3:
                    cout << "\nEmployee ID   : " << employees[index].id << endl;
                    cout << "Name          : " << employees[index].name << endl;
                    cout << "Department    : " << employees[index].department << endl;
                    cout << "Basic Salary  : " << employees[index].basic << endl;
                    cout << "Bonus         : " << employees[index].bonus << endl;
                    cout << "Deduction     : " << employees[index].deduction << endl;
                    cout << "Gross Salary  : "
                         << employees[index].calculateGrossSalary() << endl;
                    cout << "Net Salary    : "
                         << employees[index].calculateNetSalary() << endl;
                    cout << "Working Hours : " << employees[index].workingHours << endl;
                    cout << "Leave Status  : " << employees[index].leaveStatus << endl;
                    break;

                // 4. Update Basic Salary
                case 4:
                    employees[index].updateEmployee();
                    break;

                // 5. Delete Employee
                case 5:
                    for (int j = index; j < employeeCount - 1; j++)
                    {
                        employees[j] = employees[j + 1];
                    }

                    employeeCount--;
                    cout << "\nEmployee deleted successfully!\n";
                    break;

                // 6. Attendance Management
                case 6:
                    employees[index].attendanceManagement();
                    break;

                // 7. Salary Management
                case 7:
                    employees[index].salaryManagement();
                    break;

                // 8. Payroll Processing
                case 8:
                    employees[index].processPayroll();
                    break;

                // 9. Salary Slip
                case 9:
                    employees[index].generateSalarySlip();
                    break;

                // 10. Payroll Report
                case 10:
                    employees[index].generateReport();
                    break;
            }
        }

        // 11. Exit
        else if (choice == 11)
        {
            cout << "\nThank you for using Employee Payroll System!\n";
        }
        else
        {
            cout << "\nInvalid choice! Enter a number from 1 to 11.\n";
        }

    } while (choice != 11);

    return 0;
}

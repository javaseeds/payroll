/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * PayrollClient.cpp
 */

#include "PayrollEngine.h"


int main()
{
	/* Note: I borrowed the employee names from Microsoft's sample Access database, Northwind */
	PayrollEngine payroll = PayrollEngine("Acme Inc.");
    std::list<Employee> testEmployees;

	/* Test Case #1 - employee entering daily hours */
	std::cout << " --- Test case #1 - Employee logs daily hours ---" << std::endl;
	testEmployees.insert(testEmployees.begin(), 
		Employee("Anna", "Bedecs", "111-22-3333", 12.0f, 0.15f, ASSOCIATE, "HOURLY", "Michael Entin"));
	payroll.initialize(testEmployees);
	payroll.addHours("111-22-3333", 8.0f, Date(5, 6, 2013));

	Employee checkEmployee = testEmployees.front();
	std::cout << "Hours worked: " << checkEmployee.getTimeCard().getDailyReport(Date(5, 6, 2013)).getDailyHours() << std::endl;
	std::cout << std::endl << std::endl;

	/* Test Case #2 - employee entering hours */
	std::cout << " --- Test case #2 - Employee enters sales data (will use same employee as Test Case #1) ---" << std::endl;
	payroll.addSales("111-22-3333", 125.0f, Date(5, 6, 2013));
	checkEmployee = testEmployees.front();
	std::cout << "Daily sales: $" << checkEmployee.getTimeCard().getSales(Date(5, 6, 2013)).getSaleAmount();
	std::cout << std::endl << std::endl;

	/* Test Case #3 - Supervisor approves OT (will need to add to the testEmployees list) */
	std::cout << " --- Test case #3 - Supervisor approves SALARIED employee's overtime ---" << std::endl;
	testEmployees.insert(testEmployees.begin(), 
		Employee("Francisco", "Perez-Olaeta", "666-77-8888", 15.5f, 0.25f, ASSOCIATE, "SALARIED", "Michael Entin"));
	testEmployees.insert(testEmployees.begin(), 
		Employee("Michael", "Entin", "234-56-7890", 35.0f, 0.35f, SUPERVISOR, "SALARIED", "Ming-Yang Xie"));
	payroll.initialize(testEmployees);
	payroll.addHours("666-77-8888", 8.0f, Date(5, 6, 2013));
	payroll.addHours("666-77-8888", 9.0f, Date(5, 7, 2013));
	payroll.addHours("666-77-8888", 9.0f, Date(5, 8, 2013));

	payroll.supervisorApproveOT("234-56-7890", "666-77-8888", Date(5, 7, 2013));
	checkEmployee = payroll.getEmployee("666-77-8888");
	std::cout << "Is employee " << checkEmployee.getFirstName() << " " << checkEmployee.getLastName() << '(' <<
		checkEmployee.getSSN() << ") a SALARIED employee? " <<  (checkEmployee.displayEmployeeType() == "SALARIED" ? "YES" : "NO");

	std::cout << "Was OT approved for 5-7-2013? " << checkEmployee.getTimeCard().getDailyReport(Date(5, 7, 2013)).isOTapproved();
	std::cout << "Was OT approved for 5-8-2013? " << checkEmployee.getTimeCard().getDailyReport(Date(5, 8, 2013)).isOTapproved();
	

	return 0;
}


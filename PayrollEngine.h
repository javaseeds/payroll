/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * PayrollEngine.h
 */

#ifndef PAYROLLENGINE_H
#define PAYROLLENGINE_H

#include <iostream>
#include <string>
#include <list>
#include "Employee.h"

class PayrollEngine
{
private:
	std::list<Employee> employees;
	std::string companyName;
public:
	PayrollEngine();
	PayrollEngine(std::string);
	~PayrollEngine();

	void initialize(std::list<Employee>);
	bool LogOn(std::string ssn);
	void addHours(std::string ssn, float hoursWorked, Date dateWorked);
	void addSales(std::string ssn, float saleAmount, Date saleDate);
	Employee getEmployee(std::string ssn);

	void runPayroll();
	void createEmployee(std::string firstName, std::string lastName, std::string SSN, float basePay,
		  float commission, EmployeeType employeeType, std::string payType, std::string supervisor);

	void supervisorApproveOT(std::string, std::string, Date);
	int getNumberOfEmployees();
	std::string getCompanyName();
};

#endif

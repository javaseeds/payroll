/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * Employee.h
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "PayType.h"
#include "TimeCard.h"

enum EmployeeType{ASSOCIATE, SUPERVISOR, ADMINISTRATOR};

class Employee
{
private:
	std::string lastName;
	std::string firstName;
	std::string ssn;
	float basePay;
	float commission;
	std::string supervisorName;
	EmployeeType empType;
	PayType *payType;
	TimeCard *timeCard;
public:
	Employee();
	Employee(std::string firstName, std::string lastName, std::string SSN, float basePay,
		float commission, EmployeeType empType, std::string payType, std::string supervisorName);
	void addEmployee(std::string firstName, std::string lastName, std::string SSN, float basePay,
		float commission, EmployeeType empType, std::string payType, std::string supervisorName);
	void removeEmployee(std::string);
	void updateEmployee(std::string);
	void displayEmployee();
	float getPayTotal();
	void calculateBasePay();

	void addHours(float hoursWorked, Date dateWorked);
	void addSales(float saleAmount, Date saleDate);
	void approveOT(Date dateToApprove);

	/* set up accessors and mutators */
	void setFirstName(std::string firstName);
	std::string getFirstName();
	void setLastName(std::string lastName);
	std::string getLastName();

	void setSSN(std::string ssn);
	std::string getSSN();
	void setSupervisorName(std::string supervisorName);
	std::string getSupervisorName();
	
	void setBasePay(float basePay);
	float getBasePay();
	void setCommission(float commission);
	float getCommission();

	void setEmployeeType(EmployeeType);
	EmployeeType getEmployeeType();
	std::string displayEmployeeType();

	void setTimeCard(TimeCard *timeCard);
	TimeCard getTimeCard();
};

#endif

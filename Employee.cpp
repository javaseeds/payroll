/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * Employee.cpp
 */

#include <string>
#include "Employee.h"
#include "HourlyType.h"
#include "SalariedType.h"
#include "TimeCard.h"

/* default Employee constructor (doesn't do anything) */
Employee::Employee() { }

Employee::Employee(std::string firstName, std::string lastName, std::string SSN, float basePay,
			  float commission, EmployeeType employeeType, std::string payType, std::string supervisor) 
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->ssn = SSN;
	this->basePay = basePay;
	this->commission = commission;
	this->empType = employeeType;
	this->supervisorName = supervisor;

	if(payType == "HOURLY")
	{
		this->payType = new HourlyType(basePay);
	}
	else if(payType == "SALARIED")
	{
		this->payType = new SalariedType(basePay);
	}

	/* set up the time card */
	this->timeCard = new TimeCard(this->ssn, this->payType);
}

void Employee::addEmployee(std::string firstName, std::string lastName, std::string SSN, float basePay,
				  float commission, EmployeeType employeeType, std::string payType, std::string supervisor)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->ssn = SSN;
	this->basePay = basePay;
	this->commission = commission;
	this->empType = employeeType;
	this->supervisorName = supervisor;

	if(payType == "HOURLY")
	{
		this->payType = new HourlyType(basePay);
	}
	else if(payType == "SALARIED")
	{
		this->payType = new SalariedType(basePay);
	}

	/* set up the time card */
	this->timeCard = new TimeCard(this->ssn, this->payType);
}

float Employee::getPayTotal()
{
	return this->timeCard->dailyReportPayTotal() + this->timeCard->salesCommissionTotal(this->commission);
}

void Employee::addHours(float hoursWorked, Date dateWorked)
{
	this->timeCard->addDailyReport(hoursWorked, dateWorked);
}

void Employee::addSales(float saleAmount, Date saleDate)
{
	this->timeCard->addSale(saleAmount, saleDate);
}

void Employee::displayEmployee()
{
	std::cout << "Name: " << getFirstName() << " " << getLastName() << std::endl;
	std::cout << "SSN: " << getSSN() << std::endl;
	std::cout << "Supervisor Name: " << getSupervisorName() << std::endl;
	std::cout << "Base Pay: " << getBasePay() << ",  Commission Rate: " << getCommission() << std::endl;
	std::cout << "Employee Type: " << displayEmployeeType() << std::endl;
	std::cout << "Pay Type: " << this->payType->getPayTypeName() << std::endl;
}

/* next line was "code" added by my 3 year old daughter :)
BNBNBfvccfdf65j5utty5y77
*/

void Employee::approveOT(Date dateToApprove)
{
	getTimeCard().approveOT(dateToApprove);
}

/* accessors and mutators */
std::string Employee::getFirstName()
{
	return firstName;
}

void Employee::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

std::string Employee::getLastName()
{
	return lastName;
}

void Employee::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

std::string Employee::getSSN()
{
	return ssn;
}

void Employee::setSSN(std::string ssn)
{
	this->ssn = ssn;
}

std::string Employee::getSupervisorName()
{
	return supervisorName;
}

void Employee::setSupervisorName(std::string supervisorName)
{
	this->supervisorName = supervisorName;
}

float Employee::getBasePay()
{
	return basePay;
}

void Employee::setBasePay(float basePay)
{
	this->basePay = basePay;
}

float Employee::getCommission()
{
	return commission;
}

void Employee::setCommission(float commission)
{
	this->commission = commission;
}

void Employee::setEmployeeType(EmployeeType empType)
{
	this->empType = empType;
}

EmployeeType Employee::getEmployeeType()
{
	return empType;
}

std::string Employee::displayEmployeeType()
{
	switch(empType)
	{
	case 0:
	default:
		return "ASSOCIATE";
	case 1:
		return "SUPERVISOR";
	case 2:
		return "ADMINISTRATOR";
	}
}

TimeCard Employee::getTimeCard()
{
	return *timeCard;
}

void Employee::setTimeCard(TimeCard *timeCard)
{
	this->timeCard = timeCard;
}

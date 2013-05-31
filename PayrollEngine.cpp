/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * PayrollEngine.cpp
 */

#include "PayrollEngine.h"

/* default constructor */
PayrollEngine::PayrollEngine() {}

PayrollEngine::PayrollEngine(std::string companyName)
{
	this->companyName = companyName;
}

/* default destructor */
PayrollEngine::~PayrollEngine() {}

void PayrollEngine::initialize(std::list<Employee> employees)
{
	this->employees = employees;
}

/* Employee needs to already exist */
bool PayrollEngine::LogOn(std::string ssn)
{
	bool logOnValid = false;

	std::list<Employee>::iterator empIt = employees.begin();
	while(empIt != employees.end())
	{
		if(empIt->getSSN() == ssn)
		{
			logOnValid = true;
			break;  // found valid entry, can bail now
		}
	}

	return logOnValid;
}

void PayrollEngine::createEmployee(std::string firstName, std::string lastName, std::string SSN, float basePay,
		  float commission, EmployeeType employeeType, std::string payType, std::string supervisor)
{
	std::cout << "Adding new employee: " << firstName << " " << lastName << std::endl;

	employees.insert(employees.begin(), Employee(firstName, lastName, SSN, basePay, commission, employeeType, payType, supervisor));
}

void PayrollEngine::supervisorApproveOT(std::string superSSN, std::string directReportSSN, Date dateToApprove)
{
	Employee super;
	std::string superName;
	Employee directReport;

	std::list<Employee>::iterator empIt = employees.begin();
	while(empIt != employees.end())
	{
		if(empIt->getSSN() == superSSN)
		{
			super = *empIt;
			break;
		}
		++empIt;
	}

	superName = super.getFirstName() + " " + super.getLastName();

	empIt = employees.begin();
	while(empIt != employees.end())
	{
		/* will check that direct report's supervisor is same as Employee record */
		if(empIt->getSSN() == directReportSSN && empIt->getSupervisorName() == superName)
		{
			directReport = *empIt;
			break;
		}

		++empIt;
	}
	directReport.approveOT(dateToApprove);
}

void PayrollEngine::addHours(std::string ssn, float hoursWorked, Date dateWorked)
{
	std::list<Employee>::iterator empIt = employees.begin();
	while(empIt != employees.end())
	{
		if(empIt->getSSN() == ssn)
		{
			empIt->addHours(hoursWorked, dateWorked);
			std::cout << " employee: " << empIt->getLastName() << ", " << empIt->getFirstName() << '(' << 
				empIt->displayEmployeeType() << "), adding " << hoursWorked << " hours for " << dateWorked.display() << std::endl;

			/* Once this is done, can bail from this loop */
			break;
		}

		++empIt;
	}
}

void PayrollEngine::addSales(std::string ssn, float saleAmount, Date saleDate)
{
	std::list<Employee>::iterator empIt = employees.begin();
	while(empIt != employees.end())
	{
		if(empIt->getSSN() == ssn)
		{
			empIt->addSales(saleAmount, saleDate);
			std::cout << " employee: " << empIt->getLastName() << ", " << empIt->getFirstName() << '(' << 
				empIt->displayEmployeeType() << "), adding $" << saleAmount << " in sales for " << saleDate.display() << std::endl;

			/* Once this is done, can bail from this loop */
			break;
		}

		++empIt;
	}
}

Employee PayrollEngine::getEmployee(std::string ssn)
{
	Employee employee;
	std::list<Employee>::iterator empIt = employees.begin();
	while(empIt != employees.end())
	{
		if(empIt->getSSN() == ssn)
		{
			employee = *empIt;
			break;
		}

		++empIt;
	}
	
	return employee;
}

int PayrollEngine::getNumberOfEmployees()
{
	return employees.size();
}

std::string PayrollEngine::getCompanyName()
{
	return companyName;
}

void PayrollEngine::runPayroll()
{
	std::list<Employee>::iterator empIt = employees.begin();
	while(empIt != employees.end())
	{
		std::cout << empIt->getLastName() << ", " << empIt->getFirstName() << " paycheck: " << 
			empIt->getPayTotal() << std::endl << std::endl;

		++empIt;
	}
}


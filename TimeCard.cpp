/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * TimeCard.cpp
 */

#include <iostream>
#include "TimeCard.h"

/* default TimeCard constructor */
TimeCard::TimeCard() { }

TimeCard::TimeCard(std::string ssn, PayType *payType)
{
	this->ssn = ssn;
	this->payType;
}

TimeCard::~TimeCard()
{
	if(dailyReports.size() > 0)
	{
		dailyReports.clear();
	}

	if(sales.size() > 0)
	{
		sales.clear();
	}
}

void TimeCard::getEmployeeTimeCard() {}

void TimeCard::addDailyReport(float hoursWorked, Date dateWorked)
{
	dailyReports.insert(dailyReports.begin(), DailyReport(hoursWorked, dateWorked));
}

void TimeCard::addSale(float saleAmount, Date saleDate)
{
	sales.insert(sales.begin(), Sales(saleAmount, saleDate));
}

float TimeCard::salesCommissionTotal(float commission)
{
	float commissionTotal = 0.0f;

	std::list<Sales>::iterator salesIt = sales.begin();
	while(salesIt != sales.end())
	{
		commissionTotal += salesIt->getSaleAmount() * commission;

		/* go to next list item, if exists */
		++salesIt;
	}

	std::cout << " commission is " << commissionTotal << std::endl;

	return commissionTotal;
}

float TimeCard::dailyReportPayTotal()
{
	float payTotal = 0.0f;
	float dayHours = 0.0f;
	float dayTotal = 0.0f;

	/* loop through the daily report of what date worked and how many hours */
	std::list<DailyReport>::iterator dailyReportIt = dailyReports.begin();
	while(dailyReportIt != dailyReports.end())
	{
		/* load in daily report hours logged by employee */
		dayHours = dailyReportIt->getDailyHours();

		if(this->payType->getPayTypeName() == "SALARIED")
		{
			/* salaried get full days regardless of 8 hours worked */
			dayTotal = this->payType->getBasePay() * 8.0f;

			/* salaried will get overtime for hours over 8 if approved - ignored if fails expression */
			if(dayHours > 8.0f && dailyReportIt->isOTapproved())
			{
				dayTotal += (dayHours - 8.0f) * this->payType->getOverTimeRate(); 
			}
		}
		else if(this->payType->getPayTypeName() == "HOURLY")
		{
			/* extra calculation if hourly has more than 8.0, otherwise, straight base pay * hours worked */
			if(dayHours > 8.0f)
			{
				dayTotal = this->payType->getBasePay() * 8.0f;
				dayTotal += (dayHours - 8.0f) * this->payType->getOverTimeRate(); 
			}
			else
			{
				dayTotal = this->payType->getBasePay() * dayHours;
			}
		}

		std::cout << " worked " << dayHours << " hours on " << dailyReportIt->getDateWorked().display() 
			<< ", for a daily pay total of: " << dayTotal << std::endl;

		/* sum together all the days pay in total */
		payTotal += dayTotal;

		/* go to next list item, if exists */
		++dailyReportIt;
	}

	return payTotal;
}

void TimeCard::approveOT(Date date)
{
	/* only SALARIED employee's need to have their overtime approved */
	if(this->payType->getPayTypeName() == "SALARIED")
	{
		std::list<DailyReport>::iterator dailyReportIt = dailyReports.begin();
		while(dailyReportIt != dailyReports.end())
		{
			if(dailyReportIt->getDateWorked() == date)
			{
				std::cout << "Setting OT approval for employee: " << ssn << ", on date: " << date.display();
				dailyReportIt->approveOT();

				// once found, we need to bail
				break;
			}

			++dailyReportIt;
		}
	}
	else
	{
		std::cout << "No need to approve an HOURLY direct report, they have automatic approval" << std::endl;
	}
}

DailyReport TimeCard::getDailyReport(Date date)
{
	DailyReport dailyReport;

	/* loop through the daily report of what date worked and how many hours */
	std::list<DailyReport>::iterator dailyReportIt = dailyReports.begin();
	while(dailyReportIt != dailyReports.end())
	{
		if(dailyReportIt->getDateWorked() == date)
		{
			dailyReport = *dailyReportIt;
			break;
		}
	}

	return dailyReport;
}

Sales TimeCard::getSales(Date date)
{
	Sales sale;

	/* loop through the daily report of what date worked and how many hours */
	std::list<Sales>::iterator saleIt = sales.begin();
	while(saleIt != sales.end())
	{
		if(saleIt->getSaleDate() == date)
		{
			sale = *saleIt;
			break;
		}
	}

	return sale;
}

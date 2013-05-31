/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * TimeCard.h
 */

#ifndef TIMECARD_H
#define TIMECARD_H

#include <iostream>
#include <string>
#include <list>
#include "DailyReport.h"
#include "Sales.h"
#include "PayType.h"

class TimeCard
{
private:
	std::list<DailyReport> dailyReports;
	std::list<Sales> sales;
	std::string ssn;
	PayType *payType;
public:
	TimeCard();
	TimeCard(std::string ssn, PayType *payType);
	~TimeCard();
	void getEmployeeTimeCard(); // do I need?
	float dailyReportPayTotal();
	float salesCommissionTotal(float commission);
	void approveOT(Date dateToApprove);

	void addDailyReport(float dailyHours, Date dateWorked);
	void addSale(float saleAmount, Date saleDate);

	DailyReport getDailyReport(Date date);
	Sales getSales(Date date);
};

#endif

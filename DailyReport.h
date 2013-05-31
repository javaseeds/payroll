/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * DailyReport.h
 */

#ifndef DAILYREPORT_H
#define DAILYREPORT_H

#include<string>
#include "Date.h"

class DailyReport
{
private:
	float dailyHours;
	Date dateWorked;
	bool otApproved;
public:
	DailyReport();
	DailyReport(float, Date);
	~DailyReport();
	void approveOT();
	bool isOTapproved();

	/* accessors and mutators */
	float getDailyHours();
	void setDailyHours(float dailyHours);

	Date getDateWorked();
	void setDateWorked(Date dateWorked);
};

#endif

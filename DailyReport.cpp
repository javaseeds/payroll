/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * DailyReport.cpp
 */

#include <iostream>
#include "DailyReport.h"

/* default constructor  */
DailyReport::DailyReport() { }

DailyReport::DailyReport(float dailyHours, Date dateWorked)
{
	this->dailyHours = dailyHours;
	this->dateWorked = dateWorked;
}

/* default destructor */
DailyReport::~DailyReport() { }

void DailyReport::approveOT()
{
	otApproved = true;
}

bool DailyReport::isOTapproved()
{
	return this->otApproved;
}

/* accessors and mutators */
float DailyReport::getDailyHours()
{
	return this->dailyHours;
}

void DailyReport::setDailyHours(float dailyHours)
{
	this->dailyHours = dailyHours;
}

Date DailyReport::getDateWorked()
{
	return dateWorked;
}

void DailyReport::setDateWorked(Date dateWorked)
{
	this->dateWorked = dateWorked;
}
/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * Sales.cpp
 */

#include "Sales.h"

/* default constructor */
Sales::Sales() {}

/* default destructor */
Sales::~Sales() {}

Sales::Sales(float saleAmount, Date saleDate)
{
	this->saleAmount = saleAmount;
	this->saleDate = saleDate;
}

/* accessors and mutators */
void Sales::setSaleAmount(float saleAmount)
{
	this->saleAmount = saleAmount;
}

float Sales::getSaleAmount()
{
	return saleAmount;
}


void Sales::setSaleDate(Date saleDate)
{
	this->saleDate = saleDate;
}

Date Sales::getSaleDate()
{
	return saleDate;
}


/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * Sales.h
 */

#ifndef SALES_H
#define SALES_H

#include<iostream>
#include<string>

#include "Date.h"

class Sales
{
private:
	float saleAmount;
	Date saleDate;
public:
	Sales();
	Sales(float, Date);
	~Sales();

	/* accessors and destructors */
	float getSaleAmount();
	void setSaleAmount(float saleAmount);
	Date getSaleDate();
	void setSaleDate(Date saleDate);
};

#endif

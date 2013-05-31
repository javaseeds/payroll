/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * PayType.h
 */

#ifndef PAYTYPE_H
#define PAYTYPE_H

#include <iostream>
#include <string>

class PayType
{
private:
	float basePay;
	float overTimeRate;
	std::string payTypeName;
public:
	virtual float getBasePay() = 0;
	virtual float getOverTimeRate() = 0;
	virtual std::string getPayTypeName() = 0;
	virtual ~PayType();
};

#endif

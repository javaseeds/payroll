/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * SalariedType.h
 */

#include "PayType.h"

#ifndef SALARIEDTYPE_H
#define SALARIEDTYPE_H

class SalariedType : public PayType
{
private:
	float basePay;
	float overTimeRate;
	std::string payTypeName;
public:
	SalariedType();
	SalariedType(float);
	float getBasePay();
	float getOverTimeRate();
	std::string getPayTypeName();
};

#endif

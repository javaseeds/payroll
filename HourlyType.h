/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * HourlyType.h
 */

#ifndef HOURLYTYPE_H
#define HOURLYTYPE_H

#include "PayType.h"

class HourlyType : public PayType
{
private:
	float basePay;
	float overTimeRate;
	std::string payTypeName;
public:
	HourlyType();
	HourlyType(float);
	float getBasePay();
	float getOverTimeRate();
	std::string getPayTypeName();
};

#endif

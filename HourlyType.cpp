/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * HourlyType.cpp
 */

#include "HourlyType.h"

/* default constructor */
HourlyType :: HourlyType()
{
	basePay = 10.0;
	overTimeRate = 1.5;
}

/* constructor to include basePay attribute */
HourlyType :: HourlyType(float basePay)
{
	this -> basePay = basePay;
	overTimeRate = 1.5;
}

float HourlyType :: getBasePay()
{
	return basePay;
}

float HourlyType :: getOverTimeRate()
{
	return overTimeRate;
}

std::string HourlyType::getPayTypeName()
{
	return payTypeName;
}
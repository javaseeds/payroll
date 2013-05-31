/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * SalariedType.cpp
 */

#include "SalariedType.h"

/* default constructor */
SalariedType :: SalariedType()
{
	basePay = 10.0;
	overTimeRate = 1.25;
	payTypeName = "SALARIED";
}

/* constructor to include basePay attribute */
SalariedType::SalariedType(float basePay)
{
	this->basePay = basePay;
	overTimeRate = 1.25;
	payTypeName = "SALARIED";
}

float SalariedType::getBasePay()
{
	return basePay;
}

float SalariedType::getOverTimeRate()
{
	return overTimeRate;
}

std::string SalariedType::getPayTypeName()
{
	return payTypeName;
}
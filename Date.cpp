/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * Date.cpp
 * This is a utility class to make managing Dates easier.  I found this from
 * A Complete Guide to Programming in C++
 * Author(s): Peter Prinz, Ulla Prinz
 * http://www.jblearning.com/catalog/9780763718176/
 * which can be view on Google Books 
 * http://bit.ly/11ONORG
 * 
 * I did make a few slight modifications 
 * 1) added an overloaded equivalence (==) operator
 * 2) display returns a string
 * Used with permission
 */
#pragma warning (disable : 4996)
#include <iostream>
#include <ctime>
#include "Date.h"

Date::Date()
{
	init(1, 1, 2013);
}

Date::Date(int m, int d, int y)
{
	init(m, d, y);
}

void Date::init()
{
	struct tm *ptr;
	time_t sec;
	time(&sec);
	ptr = localtime(&sec);
//  
	month = (short) ptr->tm_mon + 1;
	day   = (short) ptr->tm_mday;
	year  = (short) ptr->tm_year + 1900;
}

void Date::init(int m, int d, int y)
{
	month = (short) m;
	day   = (short) d;
	year  = (short) y;
}

/* One of the methods I slightly modified - is better to have a return object of string */
std::string Date::display()
{
	std::stringstream ss;
	ss << month << '-' << day << '-' << year;

	return ss.str();
}

/* added an equivalence overload, useful in Date comparisons */
bool operator== (Date &d1, Date &d2)
{
    return (d1.month == d2.month) &&
		   (d1.day == d2.day) &&
		   (d1.year == d2.year);
}
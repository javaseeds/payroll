/**
 * Comp Sci 308 Object-Oriented Programming
 * Dr. Bond
 * Project #2: Acme, Inc Payroll System - due May 8, 2013
 * Michael Shane Funk
 * msfh2d@mail.mst.edu
 *
 * Date.h
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

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <sstream>

class Date
{
private:
	short month, day, year;
public:
	Date();
	Date(int, int, int);
	void init();
	void init(int, int, int);
	std::string display();

	friend bool operator== (Date &d1, Date &d2);
};

#endif
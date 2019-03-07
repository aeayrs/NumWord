/*
 * NumWord.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: anea
 */

#include "NumWord.h"
#include <string>
#include <iostream>

const std::string _singles[10] = {"", "one", "two", "three", "four", "five",
								 "six", "seven", "eight", "nine"};
const std::string _teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
							   "fifteen", "sixteen", "seventeen", "eighteen",
							   "nineteen"};
const std::string _tens[10] = {"zero", "ten", "twenty", "thirty", "forty",
							  "fifty", "sixty", "seventy", "eighty", "ninety"};

void _getValueRemainder(const uint64_t number, const uint64_t divisor,
					   uint64_t *value, uint64_t *remainder) {
	*value = number / divisor;
	*remainder = number % divisor;
}

std::string _numberToWord(uint64_t number) {
	std::string numstring = "";
	uint64_t value;
	uint64_t remainder;

	if (number == 0) {
		numstring = "zero";
	}
	else if (number >= 1000000000000000000L) {
		// out of range
		numstring = "out of range";
	}
	else if (number >= 1000000000000000L) {
		// quadrillions
		_getValueRemainder(number, 1000000000000000L, &value, &remainder);
		numstring += _numberToWord(value) + " quadrillion";
		if (remainder > 0) numstring += " " + _numberToWord(remainder);
	}
	else if (number >= 1000000000000L) {
		// trillions
		_getValueRemainder(number, 1000000000000L, &value, &remainder);
		numstring += _numberToWord(value) + " trillion";
		if (remainder > 0) numstring += " " + _numberToWord(remainder);
	}
	else if (number >= 1000000000L) {
		// billions
		_getValueRemainder(number, 1000000000L, &value, &remainder);
		numstring += _numberToWord(value) + " billion";
		if (remainder > 0) numstring += " " + _numberToWord(remainder);
	}
	else if (number >= 1000000L) {
		// millions
		_getValueRemainder(number, 1000000L, &value, &remainder);
		numstring += _numberToWord(value) + " million";
		if (remainder > 0) numstring += " " + _numberToWord(remainder);
	}
	else if (number >= 1000L) {
		// thousands
		_getValueRemainder(number, 1000L, &value, &remainder);
		numstring += _numberToWord(value) + " thousand";
		if (remainder > 0) numstring += " " + _numberToWord(remainder);
	}
	else if (number >= 100L) {
		// hundreds
		_getValueRemainder(number, 100L, &value, &remainder);
		numstring += _numberToWord(value) + " hundred";
		if (remainder > 0) numstring += " " + _numberToWord(remainder);
	}
	else if (number % 10 == 0) {
		// tens
		numstring += _tens[number/10];
	}
	else if (number >= 20L) {
		// less than one hundred
		_getValueRemainder(number, 10L, &value, &remainder);
		numstring += _numberToWord(value*10L) + "-" + _numberToWord(remainder);
	}
	else if (number > 10L) {
		// teens
		numstring = _teens[ number - 10L ];
	}
	else {
		// singles
		numstring = _singles [ number ];
	}
	return numstring;
}

std::string NumWord::getValue() {
	std::string test_numword = _numberToWord(n);
	return test_numword;
}

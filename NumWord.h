/*
 * NumWord.h
 *
 *  Created on: Mar 6, 2019
 *      Author: anea
 */

#ifndef NUMWORD_H_
#define NUMWORD_H_
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <string>

using namespace std;

class NumWord {
	uint64_t n;
public:
	NumWord():n(0){};
	NumWord(uint64_t value):n(value){};
	virtual ~NumWord(){};
	std::string getValue();
};

#endif /* NUMWORD_H_ */

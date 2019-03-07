/*
 * NumWordTest.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: anea
 */
#include <string>
#include <gtest/gtest.h>
#include "NumWord.h"

void testIterate(std::map<uint64_t, std::string> expectedData) {
	for (std::map<uint64_t,std::string>::iterator it=expectedData.begin(); it!=expectedData.end(); ++it) {
		NumWord nw(it->first);
		std::string expectedValue = it->second;
		std::string actualValue = nw.getValue();
		EXPECT_EQ(expectedValue, actualValue);
	}
};

class NumWordTest : public ::testing::Test {
protected:
	std::map<uint64_t, std::string> expectedData;
};

TEST_F(NumWordTest, CanShowLessThanTen) {
	expectedData[0] = "zero";
	expectedData[1] = "one";
	expectedData[2] = "two";
	expectedData[3] = "three";
	expectedData[4] = "four";
	expectedData[5] = "five";
	expectedData[6] = "six";
	expectedData[7] = "seven";
	expectedData[8] = "eight";
	expectedData[9] = "nine";
	testIterate(expectedData);
};

TEST_F(NumWordTest, CanShowTeens) {
	expectedData[11] = "eleven";
	expectedData[12] = "twelve";
	expectedData[13] = "thirteen";
	expectedData[14] = "fourteen";
	expectedData[15] = "fifteen";
	expectedData[16] = "sixteen";
	expectedData[17] = "seventeen";
	expectedData[18] = "eighteen";
	expectedData[19] = "nineteen";
	testIterate(expectedData);
};

TEST_F(NumWordTest, CanShowDivisibleByHundred) {
	expectedData[100] = "one hundred";
	expectedData[200] = "two hundred";
	expectedData[300] = "three hundred";
	expectedData[400] = "four hundred";
	expectedData[500] = "five hundred";
	expectedData[600] = "six hundred";
	expectedData[700] = "seven hundred";
	expectedData[800] = "eight hundred";
	expectedData[900] = "nine hundred";
	testIterate(expectedData);
}

TEST_F(NumWordTest, CanShowDivisibleByThousand) {
	expectedData[1000] = "one thousand";
	expectedData[10000] = "ten thousand";
	expectedData[100000] = "one hundred thousand";
	testIterate(expectedData);
};

TEST_F(NumWordTest, CanShowLessThanQuadrillion) {
	expectedData[0] = "zero";
	expectedData[1] = "one";
	expectedData[4] = "four";
	expectedData[10] = "ten";
	expectedData[15] = "fifteen";
	expectedData[20] = "twenty";
	expectedData[29] = "twenty-nine";
	expectedData[42] = "forty-two";
	expectedData[99] = "ninety-nine";
	expectedData[115] = "one hundred fifteen";
	expectedData[193] = "one hundred ninety-three";
	expectedData[345] = "three hundred forty-five";
	expectedData[790] = "seven hundred ninety";
	expectedData[999] = "nine hundred ninety-nine";
	expectedData[1492] = "one thousand four hundred ninety-two";
	expectedData[10001] = "ten thousand one";
	expectedData[10010] = "ten thousand ten";
	expectedData[10012] = "ten thousand twelve";
	expectedData[10100] = "ten thousand one hundred";
	expectedData[11000] = "eleven thousand";
	expectedData[100073] = "one hundred thousand seventy-three";
	expectedData[1000001] = "one million one";
	expectedData[2000012] = "two million twelve";
	expectedData[34000436] = "thirty-four million four hundred thirty-six";
	expectedData[12012012] = "twelve million twelve thousand twelve";
	expectedData[999999999] = "nine hundred ninety-nine million nine hundred ninety-nine thousand nine hundred ninety-nine";
	expectedData[1000000001] = "one billion one";
	expectedData[999999999999] = "nine hundred ninety-nine billion nine hundred ninety-nine million nine hundred ninety-nine thousand nine hundred ninety-nine";
	expectedData[1000000000001] = "one trillion one";
	expectedData[999999999999999] = "nine hundred ninety-nine trillion nine hundred ninety-nine billion nine hundred ninety-nine million nine hundred ninety-nine thousand nine hundred ninety-nine";
	testIterate(expectedData);
};

TEST_F(NumWordTest, CanShowDivisibleByMillion) {
	expectedData[1000000] = "one million";
	expectedData[7000000] = "seven million";
	expectedData[10000000] = "ten million";
	expectedData[74000000] = "seventy-four million";
	expectedData[100000000] = "one hundred million";
	expectedData[240000000] = "two hundred forty million";
	expectedData[675000000] = "six hundred seventy-five million";
	expectedData[999000000] = "nine hundred ninety-nine million";
	expectedData[999999000000] = "nine hundred ninety-nine billion nine hundred ninety-nine million";
	expectedData[999999999000000] = "nine hundred ninety-nine trillion nine hundred ninety-nine billion nine hundred ninety-nine million";
	testIterate(expectedData);
};
TEST_F(NumWordTest, CanShowDivisibleByBillion) {
	expectedData[1000000000L] = "one billion";
	expectedData[7000000000L] = "seven billion";
	expectedData[10000000000L] = "ten billion";
	expectedData[74000000000L] = "seventy-four billion";
	expectedData[100000000000L] = "one hundred billion";
	expectedData[240000000000L] = "two hundred forty billion";
	expectedData[675000000000L] = "six hundred seventy-five billion";
	expectedData[999000000000L] = "nine hundred ninety-nine billion";
	expectedData[999999000000000L] = "nine hundred ninety-nine trillion nine hundred ninety-nine billion";
	testIterate(expectedData);
};
TEST_F(NumWordTest, CanShowDivisibleByTrillion) {
	expectedData[1000000000000L] = "one trillion";
	expectedData[7000000000000L] = "seven trillion";
	expectedData[10000000000000L] = "ten trillion";
	expectedData[74000000000000L] = "seventy-four trillion";
	expectedData[100000000000000L] = "one hundred trillion";
	expectedData[240000000000000L] = "two hundred forty trillion";
	expectedData[675000000000000L] = "six hundred seventy-five trillion";
	expectedData[999000000000000L] = "nine hundred ninety-nine trillion";
	testIterate(expectedData);
};

TEST_F(NumWordTest, CanShowDivisibleByQuadrillion) {
	expectedData[1000000000000000L] = "one quadrillion";
	expectedData[7000000000000000L] = "seven quadrillion";
	expectedData[10000000000000000L] = "ten quadrillion";
	expectedData[74000000000000000L] = "seventy-four quadrillion";
	expectedData[100000000000000000L] = "one hundred quadrillion";
	expectedData[240000000000000000L] = "two hundred forty quadrillion";
	expectedData[675000000000000000L] = "six hundred seventy-five quadrillion";
	expectedData[999000000000000000L] = "nine hundred ninety-nine quadrillion";
	testIterate(expectedData);
};

TEST_F(NumWordTest, CanShowMaxNumber) {
	expectedData[0] = "zero";
	expectedData[1] = "one";
	expectedData[999999999999999999L] = "nine hundred ninety-nine quadrillion nine hundred ninety-nine trillion nine hundred ninety-nine billion nine hundred ninety-nine million nine hundred ninety-nine thousand nine hundred ninety-nine";
	expectedData[1000000000000000000L] = "out of range";
	testIterate(expectedData);
}

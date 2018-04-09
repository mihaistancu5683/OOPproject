#include "stdafx.h"
#include "Fraction.h"
#include <iostream>
#include <complex>
#include <gtest/gtest.h>

using std::complex;
using namespace std::complex_literals;

template <class T>
Fraction<T>::Fraction() //no arguments constructor
{
}

template <class T>
Fraction<T>::Fraction(T numerator) //one argument construtor
{
	_numerator = numerator;
}

template <class T>
Fraction<T>::Fraction(T numerator, T denominator) //two arguments constructor
{
	_numerator = numerator;
	_denominator = denominator;
}

template <class T>
Fraction<T>::~Fraction() //destructor
{
}

template <class T>
bool operator == (Fraction<T> & lhs, Fraction<T> & rhs) // == operator
{
	if (abs(lhs._numerator * rhs._denominator -
		lhs._denominator * rhs._numerator) < 0.000001)
		return true;
	else 
		return false;
}

template <class T>
Fraction<T>* operator + (Fraction<T> & lhs, Fraction<T> & rhs) // + operator
{
	T numerator1 = lhs._numerator;
	T denominator1 = lhs._denominator;
	T numerator2 = rhs._numerator;
	T denominator2 = rhs._denominator;
	T denominatorR = denominator1 * denominator2;
	T numeratorR = numerator1 * denominator2 + numerator2 * denominator1;
	return new Fraction<T>(numeratorR, denominatorR);
}

TEST(Creation, NoArgumentsConstructorInt) {
	EXPECT_NO_THROW({
		Fraction<int> *noArgumentsInt = new Fraction<int>();
		//EXPECT_EQ(noArgumentsInt->_numerator, 1);
		//EXPECT_EQ(noArgumentsInt->_denominator, 1);
		delete noArgumentsInt;
	});
}

TEST(Creation, NoArgumentsConstructorComplex) {
	EXPECT_NO_THROW({
		Fraction<std::complex<double>> *noArgumentsComplex = new Fraction<std::complex<double>>();
		//EXPECT_EQ(noArgumentsComplex->_numerator, 1. + 0i);
		//EXPECT_EQ(noArgumentsComplex->_denominator, 1. + 0i);
		delete noArgumentsComplex;
	});
}

TEST(Creation, OneArgumentConstructorInt) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		Fraction<int> *oneArgumentInt = new Fraction<int>(integerNumerator);
		EXPECT_EQ(oneArgumentInt->_numerator, integerNumerator);
		//EXPECT_EQ(oneArgumentInt->_denominator, 1);
		delete oneArgumentInt;
	});
}

TEST(Creation, OneArgumentConstructorComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator = 1. + 2i;
		Fraction<std::complex<double>> *oneArgumentComplex = new Fraction<std::complex<double>>(complexNumerator);
		EXPECT_EQ(oneArgumentComplex->_numerator, complexNumerator);
		//EXPECT_EQ(oneArgumentComplex->_denominator, 1. + 0i);
		delete oneArgumentComplex;
	});
}

TEST(Creation, TwoArgumentsConstructorInt) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		int integerDenominator = -21;
		Fraction<int> *twoArgumentsInt = new Fraction<int>(integerNumerator, integerDenominator);
		EXPECT_EQ(twoArgumentsInt->_numerator, integerNumerator);
		EXPECT_EQ(twoArgumentsInt->_denominator, integerDenominator);
		delete twoArgumentsInt;
	});
}

TEST(Creation, TwoArgumentsConstructorComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator = 1. + 2i;
		std::complex<double> complexDenominator = 2. + 3i;
		Fraction<std::complex<double>> *twoArgumentsComplex = new Fraction<std::complex<double>>(complexNumerator, complexDenominator);
		EXPECT_EQ(twoArgumentsComplex->_numerator, complexNumerator);
		EXPECT_EQ(twoArgumentsComplex->_denominator, complexDenominator);
		delete twoArgumentsComplex;
	});
}

TEST(Operator, IntEqualEqualInt) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		int integerNumerator3 = 5;
		int integerDenominator3 = 3;
		Fraction<int> *first = new Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> *second = new Fraction<int>(integerNumerator2, integerDenominator2);
		Fraction<int> *third = new Fraction<int>(integerNumerator3, integerDenominator3);
		EXPECT_TRUE(*first == *third);
		EXPECT_FALSE(*first == *second);
		EXPECT_FALSE(*second == *third);
		delete first;
		delete second;
		delete third;
	});
}

TEST(Operator, ComplexEqualEqualComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> complexNumerator2 = 3. + 4i;
		std::complex<double> complexDenominator2 = 4. + 5i;
		std::complex<double> complexNumerator3 = 1. + 2i;
		std::complex<double> complexDenominator3 = 2. + 3i;
		Fraction<complex<double>> *first = new Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> *second = new Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		Fraction<complex<double>> *third = new Fraction<complex<double>>(complexNumerator3, complexDenominator3);
		EXPECT_TRUE(*first == *third);
		EXPECT_FALSE(*first == *second);
		EXPECT_FALSE(*second == *third);
		delete first;
		delete second;
		delete third;
	});
}

TEST(Operator, IntPlusInt) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		Fraction<int> *first = new Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> *second = new Fraction<int>(integerNumerator2, integerDenominator2);
		Fraction<int> *result = *first + *second;
		EXPECT_EQ(result->_numerator, 23);
		EXPECT_EQ(result->_denominator, 21);
		delete first;
		delete second;
		delete result;
	});
}

TEST(Operator, ComplexPlusComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> complexNumerator2 = 3. + 4i;
		std::complex<double> complexDenominator2 = 4. + 5i;
		std::complex<double> referenceNumerator = -12. + 30i;
		std::complex<double> referenceDenominator = -7. + 22i;
		Fraction<complex<double>> *first = new Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> *second = new Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		Fraction<complex<double>> *reference = new Fraction<complex<double>>(referenceNumerator, referenceDenominator);
		Fraction<complex<double>> *result = *first + *second;
		EXPECT_EQ(result->_numerator, reference->_numerator);
		EXPECT_EQ(result->_denominator, reference->_denominator);
		delete first;
		delete second;
		delete reference;
		delete result;
	});
}

int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
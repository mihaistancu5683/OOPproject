#include "stdafx.h"
#include "Fraction.h"
#include <iostream>
#include <gtest/gtest.h>

template <class T>
Fraction<T>::Fraction() //no arguments constructor
{
}

template <class T>
Fraction<T>::Fraction(T numerator) //one argument 
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

TEST(Creation, NoArgumentsConstructorInt) {
	EXPECT_NO_THROW({
		Fraction<int> *noArgumentsInt = new Fraction<int>();
		delete noArgumentsInt;
	});
}

TEST(Creation, NoArgumentsConstructorInt2) {
	EXPECT_EQ(1,2);
}

//TEST(Creation, NoArgumentsConstructorComplex) {
//	EXPECT_NO_THROW({
//		Fraction<std::complex<double>> *noArgumentsComplex = new Fraction<std::complex<double>>();
//		delete noArgumentsComplex;
//	});
//}

int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
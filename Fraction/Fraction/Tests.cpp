#include "stdafx.h"
#include "Fraction.h"
#include <iostream>
#include <complex>
#include <gtest/gtest.h>

using std::complex;
using namespace std::complex_literals;

TEST(Creation, NoArgumentsConstructorInt) {
	EXPECT_NO_THROW({
		Fraction<int> noArgumentsInt;
	});
}

TEST(Creation, NoArgumentsConstructorComplex) {
	EXPECT_NO_THROW({
		Fraction<std::complex<double>> noArgumentsComplex;
	});
}

TEST(Creation, OneArgumentConstructorInt) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		Fraction<int> oneArgumentInt = Fraction<int>(integerNumerator);
		EXPECT_EQ(oneArgumentInt.GetNumerator(), integerNumerator);
		EXPECT_EQ(oneArgumentInt.GetDenominator(), 1);
	});
}

TEST(Creation, OneArgumentConstructorComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator = 1. + 2i;
		Fraction<std::complex<double>> oneArgumentComplex = Fraction<std::complex<double>>(complexNumerator);
		EXPECT_EQ(oneArgumentComplex.GetNumerator(), complexNumerator);
		EXPECT_EQ(oneArgumentComplex.GetDenominator(), 1. + 0i);
	});
}

TEST(Creation, TwoArgumentsConstructorInt) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		int integerDenominator = -21;
		Fraction<int> twoArgumentsInt = Fraction<int>(integerNumerator, integerDenominator);
		EXPECT_EQ(twoArgumentsInt.GetNumerator(), integerNumerator);
		EXPECT_EQ(twoArgumentsInt.GetDenominator(), integerDenominator);
	});
}

TEST(Creation, TwoArgumentsConstructorComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator = 1. + 2i;
		std::complex<double> complexDenominator = 2. + 3i;
		Fraction<std::complex<double>> twoArgumentsComplex = Fraction<std::complex<double>>(complexNumerator, complexDenominator);
		EXPECT_EQ(twoArgumentsComplex.GetNumerator(), complexNumerator);
		EXPECT_EQ(twoArgumentsComplex.GetDenominator(), complexDenominator);
	});
}

TEST(Creation, CopyConstructorInt) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		int integerDenominator = -21;
		Fraction<int> fraction1 = Fraction<int>(integerNumerator, integerDenominator);
		Fraction<int> fraction2 = Fraction<int>(fraction1);
		EXPECT_EQ(fraction2.GetNumerator(), integerNumerator);
		EXPECT_EQ(fraction2.GetDenominator(), integerDenominator);
	});
}

TEST(Operator, IntEqualInt) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> second = Fraction<int>(integerNumerator2, integerDenominator2);
		first = second;
		EXPECT_EQ(first.GetNumerator(), integerNumerator2);
		EXPECT_EQ(first.GetDenominator(), integerDenominator2);
	});
}

TEST(Operator, ComplexEqualComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> complexNumerator2 = 3. + 4i;
		std::complex<double> complexDenominator2 = 4. + 5i;
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> second = Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		first = second;
		EXPECT_EQ(first.GetNumerator(), complexNumerator2);
		EXPECT_EQ(first.GetDenominator(), complexDenominator2);
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
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> second = Fraction<int>(integerNumerator2, integerDenominator2);
		Fraction<int> third = Fraction<int>(integerNumerator3, integerDenominator3);
		EXPECT_TRUE(first == third);
		EXPECT_FALSE(first == second);
		EXPECT_FALSE(second == third);
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
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> second = Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		Fraction<complex<double>> third = Fraction<complex<double>>(complexNumerator3, complexDenominator3);
		EXPECT_TRUE(first == third);
		EXPECT_FALSE(first == second);
		EXPECT_FALSE(second == third);
	});
}

TEST(Operator, IntFractionPlusIntFraction) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> second = Fraction<int>(integerNumerator2, integerDenominator2);
		Fraction<int> result = first + second;
		EXPECT_EQ(result.GetNumerator(), 23);
		EXPECT_EQ(result.GetDenominator(), 21);
	});
}

TEST(Operator, ComplexFractionPlusComplexFraction) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> complexNumerator2 = 3. + 4i;
		std::complex<double> complexDenominator2 = 4. + 5i;
		std::complex<double> referenceNumerator = -12. + 30i;
		std::complex<double> referenceDenominator = -7. + 22i;
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> second = Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		Fraction<complex<double>> reference = Fraction<complex<double>>(referenceNumerator, referenceDenominator);
		Fraction<complex<double>> result = first + second;
		EXPECT_EQ(result.GetNumerator(), reference.GetNumerator());
		EXPECT_EQ(result.GetDenominator(), reference.GetDenominator());
	});
}

TEST(Operator, ComplexIntFractionPlusIntFraction) {
	EXPECT_NO_THROW({
		std::complex<int> complexNumerator1(1,2);//1 + 2i;
		std::complex<int> complexDenominator1(2, 3);// = 2 + 3i;
		std::complex<int> complexNumerator2(3, 4);// = 3 + 4i;
		std::complex<int> complexDenominator2(4, 5);// = 4 + 5i;
		std::complex<int> referenceNumerator(-12, 30);// = -12 + 30i;
		std::complex<int> referenceDenominator(-7, 22);// = -7 + 22i;
		Fraction<complex<int>> first = Fraction<complex<int>>(complexNumerator1, complexDenominator1);
		Fraction<complex<int>> second = Fraction<complex<int>>(complexNumerator2, complexDenominator2);
		Fraction<complex<int>> reference = Fraction<complex<int>>(referenceNumerator, referenceDenominator);
		Fraction<complex<int>> result = first + second;
		EXPECT_EQ(result.GetNumerator(), reference.GetNumerator());
		EXPECT_EQ(result.GetDenominator(), reference.GetDenominator());
	});
}

TEST(Operator, IntFractionPlusInt) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		int integerDenominator = -3;
		Fraction<int> fraction = Fraction<int>(integerNumerator, integerDenominator);
		Fraction<int> result = fraction + 3;
		EXPECT_EQ(result.GetNumerator(), -14);
		EXPECT_EQ(result.GetDenominator(), -3);
	});
}

TEST(Operator, PlusIntFraction) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		int integerDenominator = -3;
		Fraction<int> fraction = Fraction<int>(integerNumerator, integerDenominator);
		Fraction<int> result = + fraction;
		EXPECT_EQ(result.GetNumerator(), -5);
		EXPECT_EQ(result.GetDenominator(), -3);
	});
}

TEST(Operator, IntFractionPlusPlus) {
	EXPECT_NO_THROW({
		int integerNumerator1 = 2;
		int integerDenominator1 = -3;
		int resultNumerator2 = 1;
		int resultDenominator2 = 3;
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> result = Fraction<int>(resultNumerator2, resultDenominator2);
		first++;
		EXPECT_TRUE(first == result);
	});
}

TEST(Operator, ComplexFractionPlusPlus) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> resultNumerator = 3. + 5i;
		std::complex<double> resultDenominator = 2. + 3i;
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> result = Fraction<complex<double>>(resultNumerator, resultDenominator);
		first++;
		EXPECT_TRUE(first == result);
	});
}

TEST(Operator, IntFractionMinusIntFraction) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> second = Fraction<int>(integerNumerator2, integerDenominator2);
		Fraction<int> result = first - second;
		EXPECT_EQ(result.GetNumerator(), 47);
		EXPECT_EQ(result.GetDenominator(), 21);
	});
}

TEST(Operator, ComplexFractionMinusComplexFraction) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> complexNumerator2 = 3. + 4i;
		std::complex<double> complexDenominator2 = 4. + 5i;
		std::complex<double> referenceNumerator = 0. - 4i;
		std::complex<double> referenceDenominator = -7. + 22i;
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> second = Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		Fraction<complex<double>> reference = Fraction<complex<double>>(referenceNumerator, referenceDenominator);
		Fraction<complex<double>> result = first - second;
		EXPECT_EQ(result.GetNumerator(), reference.GetNumerator());
		EXPECT_EQ(result.GetDenominator(), reference.GetDenominator());
	});
}

TEST(Operator, IntFractionMinusInt) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		int integerDenominator = -3;
		Fraction<int> fraction = Fraction<int>(integerNumerator, integerDenominator);
		Fraction<int> result = fraction - 3;
		EXPECT_EQ(result.GetNumerator(), 4);
		EXPECT_EQ(result.GetDenominator(), -3);
	});
}

TEST(Operator, MinusIntFraction) {
	EXPECT_NO_THROW({
		int integerNumerator = -5;
		int integerDenominator = -3;
		Fraction<int> fraction = Fraction<int>(integerNumerator, integerDenominator);
		Fraction<int> result = -fraction;
		EXPECT_EQ(result.GetNumerator(), 5);
		EXPECT_EQ(result.GetDenominator(), -3);
	});
}

TEST(Operator, IntFractionMinusMinus) {
	EXPECT_NO_THROW({
		int integerNumerator1 = 1;
		int integerDenominator1 = 3;
		int resultNumerator2 = 2;
		int resultDenominator2 = -3;
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> result = Fraction<int>(resultNumerator2, resultDenominator2);
		first--;
		EXPECT_TRUE(first == result);
	});
}

TEST(Operator, ComplexFractionMinusMinus) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 3. + 5i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> resultNumerator = 1. + 2i;
		std::complex<double> resultDenominator = 2. + 3i;
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> result = Fraction<complex<double>>(resultNumerator, resultDenominator);
		first--;
		EXPECT_TRUE(first == result);
	});
}

TEST(Operator, IntMultipliedByInt) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> second = Fraction<int>(integerNumerator2, integerDenominator2);
		Fraction<int> result = first * second;
		EXPECT_EQ(result.GetNumerator(), -20);
		EXPECT_EQ(result.GetDenominator(), 21);
	});
}

TEST(Operator, ComplexMultipliedByComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> complexNumerator2 = 3. + 4i;
		std::complex<double> complexDenominator2 = 4. + 5i;
		std::complex<double> referenceNumerator = -5. + 10i;
		std::complex<double> referenceDenominator = -7. + 22i;
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> second = Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		Fraction<complex<double>> reference = Fraction<complex<double>>(referenceNumerator, referenceDenominator);
		Fraction<complex<double>> result = first * second;
		EXPECT_EQ(result.GetNumerator(), reference.GetNumerator());
		EXPECT_EQ(result.GetDenominator(), reference.GetDenominator());
	});
}

TEST(Operator, IntDividedByInt) {
	EXPECT_NO_THROW({
		int integerNumerator1 = -5;
		int integerDenominator1 = -3;
		int integerNumerator2 = 4;
		int integerDenominator2 = -7;
		Fraction<int> first = Fraction<int>(integerNumerator1, integerDenominator1);
		Fraction<int> second = Fraction<int>(integerNumerator2, integerDenominator2);
		Fraction<int> result = first / second;
		EXPECT_EQ(result.GetNumerator(), 21);
		EXPECT_EQ(result.GetDenominator(), -20);
	});
}

TEST(Operator, ComplexDividedByComplex) {
	EXPECT_NO_THROW({
		std::complex<double> complexNumerator1 = 1. + 2i;
		std::complex<double> complexDenominator1 = 2. + 3i;
		std::complex<double> complexNumerator2 = 3. + 4i;
		std::complex<double> complexDenominator2 = 4. + 5i;
		std::complex<double> referenceNumerator = -7. + 22i;
		std::complex<double> referenceDenominator =  -5. + 10i;
		Fraction<complex<double>> first = Fraction<complex<double>>(complexNumerator1, complexDenominator1);
		Fraction<complex<double>> second = Fraction<complex<double>>(complexNumerator2, complexDenominator2);
		Fraction<complex<double>> reference = Fraction<complex<double>>(referenceNumerator, referenceDenominator);
		Fraction<complex<double>> result = first / second;
		EXPECT_EQ(result.GetNumerator(), reference.GetNumerator());
		EXPECT_EQ(result.GetDenominator(), reference.GetDenominator());
	});
}

int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
#include "stdafx.h"
#include "Fraction.h"
#include <iostream>

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

int main(int argc, char ** argv)
{
	return 0;
}
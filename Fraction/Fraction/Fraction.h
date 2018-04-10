template <typename T>
class Fraction {

public:

	Fraction(); // no argumens constructor
	Fraction(T numerator, T denominator = (T)1); //two arguments constructor
	~Fraction(); //destructor

	T _numerator;
	T _denominator;

};

template <class T>
Fraction<T>::Fraction() //no arguments constructor
{
}

template <class T> //one argument construtor, denominator is 1 if not present
Fraction<T>::Fraction(T numerator, T denominator) 
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
Fraction<T> operator + (Fraction<T> & lhs, Fraction<T> & rhs) // + operator
{
	T numerator1 = lhs._numerator;
	T denominator1 = lhs._denominator;
	T numerator2 = rhs._numerator;
	T denominator2 = rhs._denominator;
	T denominatorR = denominator1 * denominator2;
	T numeratorR = numerator1 * denominator2 + numerator2 * denominator1;
	return Fraction<T>(numeratorR, denominatorR);
}

template <class T>
Fraction<T> operator - (Fraction<T> & lhs, Fraction<T> & rhs) // - operator
{
	T numerator1 = lhs._numerator;
	T denominator1 = lhs._denominator;
	T numerator2 = rhs._numerator;
	T denominator2 = rhs._denominator;
	T denominatorR = denominator1 * denominator2;
	T numeratorR = numerator1 * denominator2 - numerator2 * denominator1;
	return Fraction<T>(numeratorR, denominatorR);
}

template <class T>
Fraction<T> operator * (Fraction<T> & lhs, Fraction<T> & rhs) // * operator
{
	T numerator1 = lhs._numerator;
	T denominator1 = lhs._denominator;
	T numerator2 = rhs._numerator;
	T denominator2 = rhs._denominator;
	T numeratorR = numerator1 * numerator2;
	T denominatorR = denominator1 * denominator2;
	return Fraction<T>(numeratorR, denominatorR);
}

template <class T>
Fraction<T> operator / (Fraction<T> & lhs, Fraction<T> & rhs) // / operator
{
	T numerator1 = lhs._numerator;
	T denominator1 = lhs._denominator;
	T numerator2 = rhs._numerator;
	T denominator2 = rhs._denominator;
	T numeratorR = denominator1 * denominator2;
	T denominatorR = numerator1 * numerator2;
	return Fraction<T>(numeratorR, denominatorR);
}



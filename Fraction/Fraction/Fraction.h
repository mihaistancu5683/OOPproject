template <typename T>
class Fraction {

public:

	Fraction(); // no argumens constructor
	Fraction(T numerator, T denominator = (T)1); //two arguments constructor
	~Fraction(); //destructor

	bool operator == (Fraction<T>);

	Fraction<T> operator + (Fraction<T>);
	Fraction<T> operator - (Fraction<T>);
	Fraction<T> operator * (Fraction<T>);
	Fraction<T> operator / (Fraction<T>);

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
bool Fraction<T>::operator == (Fraction<T> fraction) // == operator
{
	if (abs(this->_numerator * fraction._denominator -
		    this->_denominator * fraction._numerator) < 0.000001)
		return true;
	else
		return false;
}

template <class T>
Fraction<T> Fraction<T>::operator + (Fraction<T> fraction) // + operator
{
	T numerator1 = this->_numerator;
	T denominator1 = this->_denominator;
	T numerator2 = fraction._numerator;
	T denominator2 = fraction._denominator;
	T denominatorR = denominator1 * denominator2;
	T numeratorR = numerator1 * denominator2 + numerator2 * denominator1;
	return Fraction<T>(numeratorR, denominatorR);
}

template <class T>
Fraction<T> Fraction<T>::operator - (Fraction<T> fraction) // - operator
{
	T numerator1 = this->_numerator;
	T denominator1 = this->_denominator;
	T numerator2 = fraction._numerator;
	T denominator2 = fraction._denominator;
	T denominatorR = denominator1 * denominator2;
	T numeratorR = numerator1 * denominator2 - numerator2 * denominator1;
	return Fraction<T>(numeratorR, denominatorR);
}

template <class T>
Fraction<T> Fraction<T>::operator * (Fraction<T> fraction) // * operator
{
	T numerator1 = this->_numerator;
	T denominator1 = this->_denominator;
	T numerator2 = fraction._numerator;
	T denominator2 = fraction._denominator;
	T numeratorR = numerator1 * numerator2;
	T denominatorR = denominator1 * denominator2;
	return Fraction<T>(numeratorR, denominatorR);
}

template <class T>
Fraction<T> Fraction<T>::operator / (Fraction<T> fraction) // / operator
{
	T numerator1 = this->_numerator;
	T denominator1 = this->_denominator;
	T numerator2 = fraction._numerator;
	T denominator2 = fraction._denominator;
	T numeratorR = denominator1 * denominator2;
	T denominatorR = numerator1 * numerator2;
	return Fraction<T>(numeratorR, denominatorR);
}



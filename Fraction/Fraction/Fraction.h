template <typename T>
class Fraction {

private:

	T _numerator;
	T _denominator;

public:

	Fraction(); // no argumens constructor
	Fraction(T numerator, T denominator = (T)1); //two arguments constructor
	~Fraction(); //destructor

	T GetNumerator(); //getters
	T GetDenominator();
	void SetNumerator(T); //setters
	void SetDenominator(T);

	bool operator == (Fraction<T>);

	Fraction<T> operator + (Fraction<T>);
	Fraction<T> operator ++ (int);
	Fraction<T> operator - (Fraction<T>);
	Fraction<T> operator -- (int);
	Fraction<T> operator * (Fraction<T>);
	Fraction<T> operator / (Fraction<T>);

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
T Fraction<T>::GetNumerator() {
	return _numerator;
}

template <class T>
T Fraction<T>::GetDenominator() {
	return _denominator;
}

template <class T>
void Fraction<T>::SetNumerator(T input) {
	this->_numerator = input;
}

template <class T>
void Fraction<T>::SetDenominator(T input) {
	this->_denominator = input;
}

template <class T>
bool Fraction<T>::operator == (Fraction<T> fraction) // == operator
{
	if (abs(this->GetNumerator() * fraction.GetDenominator() -
		    this->GetDenominator() * fraction.GetNumerator()) < 0.000001)
		return true;
	else
		return false;
}

template <class T>
Fraction<T> Fraction<T>::operator + (Fraction<T> fraction) // + operator
{
	T numerator1 = this->GetNumerator();
	T denominator1 = this->GetDenominator();
	T numerator2 = fraction._numerator;
	T denominator2 = fraction._denominator;
	T denominatorR = denominator1 * denominator2;
	T numeratorR = numerator1 * denominator2 + numerator2 * denominator1;
	return Fraction<T>(numeratorR, denominatorR);
}

template <class T>
Fraction<T> Fraction<T>::operator ++ (int) // ++ operator
{
	Fraction<T> temp = *this;
	this->SetNumerator((this->GetNumerator()) + (this->GetDenominator()));
	return *this;
}

template <class T>
Fraction<T> Fraction<T>::operator - (Fraction<T> fraction) // - operator
{
	T numerator1 = this->GetNumerator();
	T denominator1 = this->GetDenominator();
	T numerator2 = fraction._numerator;
	T denominator2 = fraction._denominator;
	T denominatorR = denominator1 * denominator2;
	T numeratorR = numerator1 * denominator2 - numerator2 * denominator1;
	return Fraction<T>(numeratorR, denominatorR);
}

template <class T>
Fraction<T> Fraction<T>::operator -- (int) // -- operator
{
	Fraction<T> temp = *this;
	this->SetNumerator((this->GetNumerator()) - (this->GetDenominator()));
	return *this;
}

template <class T>
Fraction<T> Fraction<T>::operator * (Fraction<T> fraction) // * operator
{
	T numerator1 = this->GetNumerator();
	T denominator1 = this->GetDenominator();
	T numerator2 = fraction._numerator;
	T denominator2 = fraction._denominator;
	T numeratorR = numerator1 * numerator2;
	T denominatorR = denominator1 * denominator2;
	return Fraction<T>(numeratorR, denominatorR);
}

template <class T>
Fraction<T> Fraction<T>::operator / (Fraction<T> fraction) // / operator
{
	T numerator1 = this->GetNumerator();
	T denominator1 = this->GetDenominator();
	T numerator2 = fraction.GetNumerator();
	T denominator2 = fraction.GetDenominator();
	T numeratorR = denominator1 * denominator2;
	T denominatorR = numerator1 * numerator2;
	return Fraction<T>(numeratorR, denominatorR);
}



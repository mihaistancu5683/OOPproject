template <typename T>
class Fraction {

private:

	T _numerator;
	T _denominator;

public:

	Fraction(); // no argumens constructor
	Fraction(T numerator); //one argument constructor
	Fraction(T numerator, T denominator); //two arguments constructor
	~Fraction(); //destructor

};
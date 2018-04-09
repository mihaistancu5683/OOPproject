template <typename T>
class Fraction {

public:

	Fraction(); // no argumens constructor
	Fraction(T numerator); //one argument constructor
	Fraction(T numerator, T denominator); //two arguments constructor
	~Fraction(); //destructor

	T _numerator;
	T _denominator;
};
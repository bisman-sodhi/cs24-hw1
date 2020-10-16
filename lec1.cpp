//lecture 1
#include <iostream>
using namespace std;

//writin structs
// a + i*b
// a is real and b imag
//C++ classes - structs + member functions + information hiding
//Everything is public in struct and available in main

/*
struct Complex
{
    double real;
    double imag;
}
*/

// Special memeber functions of every class - The Big Four
// 1. Constructor: Routine for initialization an object.
//                 Called right AFTER we create a new object
// Complex c1; The constructor is called. Initialize the member variables
// Complex *p = new Complex;
// 2. Destructor: Called right BEFORE an object is going to be deleted
// 3. Copy Constructor: Initialize a new object using an existing object.
//                      passing parameter to functions
// 4. Copy Assignment: 
// Complex c1, c2; 
// c1 = c2; This is a function call, calling the copy assignment function
class Complex
{
    public: // everything below this line is accessible outside class

        //member functions
        //define functions outside the class though

        //anybody who wants to use type Complex has to go through
        //the function below
        //they can't just access real and imag

        //getters (accessors) : return value of member variables

        double getReal() const;         //getting value of mem variable
                                        //not changing it

        double getImaginary() const;    // add consts to make sure
                                        //value don't change.
                                        //changing gives compiler error
        void print() const;
        Complex getConjugate() const;



        //setters (mutators)
        void setReal(double a);
        void setImaginary(double b);
        // conjugate of a+ ib is a - ib
        void conjugate(); //apply the conjugate operation


    private:
        //member varaibles
        double real;
        double imag;
};

// c1 and c2 are on the stack
void Complex::print() const
{
    // :: scope operator, Complex class's print function
    if (imag > 0)
    {
        cout <<real << " + " << imag << "*i"<< endl;

    }
    else
    {
        cout << real << " - " << -imag << "*i" << endl;
    }
}

void Complex::setReal(double a)
{
    real = a;
}

void Complex::setImaginary(double b)
{
    imag = b;
}

//a + i*b -> a - i*b
void Complex::conjugate()
{
    imag = -imag;
}

int main()
{
    int x;
    //two ways to initial it
    Complex c1;     // 2 + 3i c1 = {2,3} initialization list  only works
                    //for structs not classes
    Complex c2;     // 5 + 4i //c2.real = 5; c2.imag = 4;

    //using funciton via setter

    c1.setReal(2);
    c1.setImaginary(3);
    c2.print();
    c1.conjugate();
    c1.print();

    return 0;
}

//g++ -c -> object file: machine code version of lec1
//linking stage: combines all object files into an executables
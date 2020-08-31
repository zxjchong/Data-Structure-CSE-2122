/*
File name: hw3_new
Created by: xiaojie chong
Created on: 09/30/2019
Synopsis: The program creates a poly class and has different basic function of operating the class.
*/

#include <cmath>
#include <iostream>

using namespace std;

// Default size of our dynamic coefficient array
const int DEFAULTPOLY = 10;    


// Do NOT modify the class header.
class Poly
{
private:
  
    // Data members
    int arraySize;    // size of array
    int *coeff;       // dynamic array

public:

    // Default Class constructor
    // Allocate an array of DEFAULTPOLY elements and initialize it to the constant 0
    // post: Class object is initialized to degree-0 polynomial of 0  
    Poly();

  
    // Non-default (alternate) Class constructor
    // Allocate an array of 'size' elements and initializes it to the constant 0
    // post: Class object is initialized to degree-0 polynomial of 0  
    Poly(int size);

  
    // Copy constructor
    // Construct a new Poly that is a copy of an existing Poly
    // post: Class object is initialized to be a copy of the argument Poly
    Poly(const Poly& aPoly);

  
    // Destructor
    // Destroy a poly object by freeing the dynamically allocated array
    ~Poly();

  
    // Assignment operator
    // Assign 'aPoly' Poly object to 'this' Poly object
    // Note: This function is provided, please do not modify it
    const Poly& operator=(const Poly& aPoly);

    
    // grow
    // This method will allow us to increase the size of the dynamically allocated
    // array by allocating a new array of the desired size, copying the data from
    // the old array to the new array, and then releasing the old array.
    // If the newSize is less than or equal to the current size, then no actions 
    // are taken.
    // Note: the maximum degree of a polynomial is one less than the size of the 
    // array. The parameter newSize represents the size of the array.
    void grow(int newSize);

    
    // degree
    // Finds the degree of a polynomial (the highest power with a non-zero
    // coefficient)
    // pre: Class object exists
    // post: Returns the degree of the polynomial object.
    int degree() const;

    
    // setCoeff
    // Sets a term, value*x^i, in a polynomial, growing the array if necessary.
    // pre: Class object has been initialized. i is a non-negative integer.
    // post: In the polynomial, the term with power i has coefficient
    //       value. The polynomical was grown if required.
    void setCoeff(int value, int i);

    
    // getCoeff
    // Finds the coefficient of the x^i term in poly
    // pre: Class object has been initialized. i is a non-negative integer.
    // post: Returns the value of the coefficient of the term with power i
    // note: If the object does not contain a term with power i (e.g., 
    //       i>=arraySize), a coefficient value of zero is returned.
    int getCoeff(int i) const;


    // negate
    // Negate a polynomial
    // pre: The class object has been initialized.
    // post: The polynomial has been changed to represent its
    //       multiplication by -1.
    void negate();

     
    // addition operator
    // Add two polynomials together and return a new polynomial that is the result
    // pre: Both class objects have been initialized
    // post: The sum of two polynomials is stored in a new polynomial which is returned.
    //       The parameter polynomials are not changed.
    friend Poly operator+(const Poly& aPoly, const Poly& bPoly);

    
    // subtraction operator
    // Subtracts one polynomial from another and return a new polynomial that is the result
    // pre: Both class objects have been initialized
    // post: The difference of two polynomials is stored in a new polynomial which is returned.
    //       The parameter polynomials are not changed.
    friend Poly operator-(const Poly& aPoly, const Poly& bPoly);

    
    // equality operator
    // Compare two polynomials and return true if they are the same, false otherwise
    // pre: Both class objects have been initialized
    // post: A boolean value indicating whether two polynomials are the same is returned.
    //       The parameter polynomials are not changed.
    friend bool operator==(const Poly& aPoly, const Poly& bPoly);
    

    // insertion operator for output
    // Print polynomials
    // pre: The class object has been initialized
    // post: several values representing the polynomial are inserted into the output stream
    friend ostream& operator<<(ostream& out, const Poly &aPoly);

};



int main(){
    
    Poly poly1, poly2;
    int numCoeff, coeffValue, coeffDegree, x;

    // prompt user for the number of coefficients
    cout << "How many coefficients for polynomial 1?" << endl;
    cin >> numCoeff;
    for (int i=0; i<numCoeff; ++i){
        cout << "Coefficient " << i+1 << " for polynomial 1:";
        cin >> coeffValue >> coeffDegree;
        poly1.setCoeff(coeffValue, coeffDegree);
    }

    cout << endl << "How many coefficients for polynomial 2?" << endl;
    cin >> numCoeff;
    for (int i=0; i<numCoeff; ++i){
        cout << "Coefficient " << i+1 << " for polynomial 2:";
        cin >> coeffValue >> coeffDegree;
        poly2.setCoeff(coeffValue, coeffDegree);
    }

    // Sample test cases for degree() and operator<<
    cout << endl << "Polynomial 1 = " << poly1 << endl;
    cout << "Polynomial 1 has degree " << poly1.degree() << endl;
    cout << "Polynomial 2 = " << poly2 << endl;
    cout << "Polynomial 2 has degree " << poly2.degree() << endl;

    // Sample test cases for operator+ and operator-
    cout << endl << "Polynomial 1 + Polynomial 2 = " << poly1 + poly2 << endl;
    cout << "Polynomial 1 - Polynomial 2 = " << poly1 - poly2 << endl << endl;

    // Sample test cases for operator==
    if (poly1==poly2)
        cout << "Two polynomials are the same." << endl;
    else
        cout << "Two polynomials are different." << endl;

    // Try more test cases to test your class thoroughly


    
    return 0;
}

// Do not modify this function
const Poly& Poly::operator= (const Poly& aPoly){

    if (this == &aPoly)
        return *this;

    if (coeff)
        delete [] coeff;
    
    arraySize = aPoly.arraySize;
    coeff = new int[arraySize];
    for (int i=0; i<arraySize; ++i){
        coeff[i] = aPoly.getCoeff(i);
    }

    return *this;
}

/* your code here */
Poly::Poly():arraySize(DEFAULTPOLY){
	coeff = new int[DEFAULTPOLY]();
}

Poly::Poly(int size):arraySize(size){
	coeff = new int[size+1]();
}

Poly::Poly(const Poly& aPoly):arraySize(aPoly.arraySize){
	coeff = new int[aPoly.arraySize+1]();                      //create one with the same size and same coeffs
    for (int i=0; i<aPoly.arraySize; ++i){
        coeff[i] = aPoly.getCoeff(i);
    }
}

Poly::~Poly(){
    delete[] coeff;
}



void Poly::grow(int newSize){
    if (arraySize >= newSize){
    }
    else{
        int *coeff_2;
        coeff_2 = new int[newSize]();
        for (int i=0; i<arraySize; ++i){
            coeff_2[i] = coeff[i];
        }
        arraySize = newSize;
        // delete [] coeff;     // use a new coeff to store the coeff from the original one
        coeff = coeff_2;
        // delete [] coeff_2;
    }
}    

 
int Poly::degree() const{
    for (int i=arraySize-1; i>=0; --i){
        if(coeff[i]!=0){            //return the degree
            return i;
        }
    }
    return 0;
}        


void Poly::setCoeff(int value, int i){      // set the coeff of degree i and if the array is smaller than grow it
	if(i+1>arraySize){
        (*this).grow(i+1);
    }
    coeff[i] = value;
}            


int Poly::getCoeff(int i) const{
    if(i>=arraySize) return 0;
    else return coeff[i];       // return certain coeff
}         


void Poly::negate(){
    for (int i=0; i<arraySize; ++i){        //nega the coeff
        coeff[i] = -1*coeff[i];
    }
} 

Poly operator+(const Poly& aPoly, const Poly& bPoly){
    Poly temp;
    if(aPoly.arraySize >= bPoly.arraySize){
        Poly temp(aPoly);
    }
    else Poly temp(bPoly);
    // cout<<"temp.arrsize"<<temp.arraySize<<endl;
    for (int i=0; i<temp.arraySize; ++i){
        temp.coeff[i] = aPoly.getCoeff(i)+bPoly.getCoeff(i);    //first create a temp poly and add coeff
    }
    return temp;
}


Poly operator-(const Poly& aPoly, const Poly& bPoly){
    Poly temp;
    if(aPoly.arraySize >= bPoly.arraySize){
        Poly temp(aPoly);
    }
    else Poly temp(bPoly);
    for (int i=0; i<temp.arraySize; ++i){
        temp.coeff[i] = aPoly.getCoeff(i)-bPoly.getCoeff(i);        //minus the coeff one by one
    }
    return temp;
} 


bool operator==(const Poly& aPoly, const Poly& bPoly){
    if(aPoly.arraySize != bPoly.arraySize){     //check whether two poly have the same size
        return false;
    }
    else{
        for (int i=0; i<aPoly.arraySize; ++i){
            if(aPoly.getCoeff(i)-bPoly.getCoeff(i)!=0){         // check coeff one by one
                return false;
            }
        }
        return true;
    }
}     

ostream& operator<<(ostream& out, const Poly &aPoly){
    // cout<<"begin to output"<<endl;
    if(aPoly.degree() == 0){
        out << aPoly.getCoeff(0);           //this function  is use to output the poly
    }
    else{
        // out << "degree" <<aPoly.degree();
        out << aPoly.getCoeff(aPoly.degree()) << 'x' << '^' << aPoly.degree();
        for (int i=aPoly.degree()-1; i>=0; --i){
            // cout<<endl<<"##i: "<<i<<endl;
            if(aPoly.getCoeff(i)!=0 ){
                if(i!=0) out << '+' << aPoly.getCoeff(i) << 'x' << '^' << i ;           // special case when the poly end with degree 0
                else out << '+' << aPoly.getCoeff(i);
            }
        }
    }
    cout<<" ";

}

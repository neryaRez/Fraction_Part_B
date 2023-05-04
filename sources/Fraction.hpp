#pragma once

#include <iostream>
#include <cstdbool>
#include <cmath>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;
// using namespace ariel;

namespace ariel{

    class Fraction
    {
    private:
        int numerator;
        int denominator;

        int gcd(int num, int denom) const;
        int digits_after_point(float fl1) const;
        void init_and_reduce(int num, int denom);

    public:

        Fraction(int num, int denom);
        Fraction (float fl1);
        Fraction();
        // Operator +///

        Fraction operator+(const Fraction& other) const;

        Fraction operator+(float fl1) const;
       
        friend Fraction operator+(float fl1, const Fraction& other);

        ///Operator - ///
        
        Fraction operator-(const Fraction& other) const;

        Fraction operator-(float fl1) const;

        friend Fraction operator-(float fl1, const Fraction& other);

        ///Operator *    ///

        Fraction operator*(const Fraction& other) const;

        Fraction operator*(float fl1) const;

        friend Fraction operator*(float fl1, const Fraction& other);

        ///Operator /    ///

        Fraction operator/(const Fraction& other) const;

        Fraction operator/(float fl1) const;

        friend Fraction operator/(float fl1, const Fraction& other);

        /// Operators ++ && --///

        Fraction operator++ (int);

        Fraction& operator++();

        Fraction operator-- (int);

        Fraction& operator--();   

        /// IO Operators //////

        friend ostream& operator<<(ostream& out_s, const Fraction& frac); 

        friend istream& operator>>(istream& input_s, Fraction& frac);

        /// Comparison Operators ////

        /////Operator == /////

        bool operator == (const Fraction& other) const;
    
        bool operator == (float fl1) const;

        friend bool operator == (float fl1, const Fraction& other);        

        //// Operator > //////

        bool operator > (const Fraction& other) const;
    
        bool operator > (float fl1) const;

        friend bool operator > (float fl1, const Fraction& other);

        ///// Operator < ////////

        bool operator < (const Fraction& other) const;
    
        bool operator < (float fl1) const;

        friend bool operator < (float fl1, const Fraction& other); 

        ///// Operator >= ////

        bool operator >= (const Fraction& other) const;
    
        bool operator >= (float fl1) const;

        friend bool operator >= (float fl1, const Fraction& other); 

        ///// Operator <= ///////////

        bool operator <= (const Fraction& other) const;
    
        bool operator <= (float fl1) const;

        friend bool operator <= (float fl1, const Fraction& other); 

        int getNumerator();

        int getDenominator();

        
    };
    #define int_max  numeric_limits<int>::max()
    #define int_min  numeric_limits<int>::min()    

}
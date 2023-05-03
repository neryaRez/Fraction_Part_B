#include "Fraction.hpp"

using namespace std;
using namespace ariel;

namespace ariel{

    Fraction::Fraction(int num, int denom)
    {
        init_and_reduce(num,denom);

    }

    Fraction::Fraction (float fl1){

    int decimal = digits_after_point(fl1); 
    if (decimal > 3) fl1 = floor(fl1*1000)/1000;

    float new_numerator = fl1 * pow(10, decimal);

    int num = (int) new_numerator;
    int denom = pow(10, decimal);

    init_and_reduce(num, denom);
    
    }

    Fraction::Fraction(){
        this->numerator = 1;
        this->denominator = 1;
    }

    void Fraction::init_and_reduce(int num, int denom){
        if(denom == 0) throw invalid_argument("divide by zero is illegal");

        else if(denom < 0){
            numerator = num * -1;
            denominator = denom * -1;
        }
        else
        {
           numerator = num;
           denominator = denom; 
        }
        int gc = gcd(numerator, denominator);
        numerator /= gc;
        denominator /= gc;
    }

    //private - support functions:

    int Fraction::gcd(int num, int denom) const{

    num = abs(num);
    denom = abs(denom);
    if(denom==0) return num;

    return gcd(denom, num%denom);

    }

    int Fraction::digits_after_point(float fli) const{ 
    
    string s = to_string(fli);
    bool zeros = true;
    int dig_num = 0;

    for (size_t i = s.length()-1; i > 0; i--)
    {
        if (s[i] == '.') break;
        else if (s[i] != '0') zeros = false;
        if(!zeros)dig_num++;
    }
    return dig_num;
    }

    Fraction Fraction::operator+(const Fraction& other) const{

    int lcm = (this->denominator * other.denominator)/ gcd(this-> denominator, other.denominator);  
    int new_numerator = this->numerator *(lcm/this->denominator) + other.numerator*(lcm/other.denominator);
    return Fraction(new_numerator, lcm);

    }

    Fraction Fraction::operator+(float fl1) const{

        Fraction add(fl1);
        Fraction result = *this + add;
        return result;
    }

    Fraction operator+(float fl1, const Fraction& other){
        
        Fraction add(fl1);
        return add + other;
    }

    //Operators - Operator - ///

    Fraction Fraction::operator-(const Fraction& other) const{

    int lcm = (this->denominator * other.denominator)/ gcd(this-> denominator, other.denominator);  
    int new_numerator = this->numerator *(lcm/this->denominator) - other.numerator*(lcm/other.denominator);
    return Fraction(new_numerator, lcm);

    }

    Fraction Fraction::operator-(float fl1) const{

        Fraction sub(fl1);
        Fraction result = *this - sub;
        return result;
    }

    Fraction operator-(float fl1, const Fraction& other){

        Fraction sub(fl1);
        return sub - other;
    }

    //Operators - Operator * ///
    Fraction Fraction::operator*(const Fraction& other) const{

       return Fraction(this->numerator*other.numerator, this->denominator*other.denominator);

    }

    Fraction Fraction::operator*(float fl1) const{

        Fraction mul(fl1);
        Fraction result = *this * mul;
        return result;
    }

    Fraction operator*(float fl1, const Fraction& other){

        return Fraction(fl1) * other;
    }

    //Operators - Operator / ///

    Fraction Fraction::operator/(const Fraction& other) const{

       if(other.numerator == 0) throw runtime_error("divide by zero is illegal\n");
       Fraction div(other.denominator, other.numerator);

       return *this * div;

    }

     Fraction Fraction::operator/(float fl1) const{

        Fraction div(fl1);
        Fraction result = *this / div;
        return result;
    }

    Fraction operator/(float fl1, const Fraction& other){

        return Fraction(fl1) / other;
    }

    // Operators ++ && -- //////

    Fraction Fraction::operator++(int){

        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& Fraction::operator++(){

        numerator += denominator;
        return *this;
    }

     Fraction Fraction::operator--(int){
        Fraction temp = *this;
        --(*this);
        return temp;
    }

     Fraction& Fraction::operator--(){

        numerator -= denominator;
        return *this;
    }

    ///IO Operators ////

    ostream& operator<<(ostream& out_s, const Fraction& frac) {

    out_s << frac.numerator << "/" << frac.denominator;
    return out_s;

    }

    istream& operator>>(istream& input_s, Fraction& frac) {
    
    int num, denom;
    if (!(input_s >> num >> denom)) throw runtime_error("few arguments has been provided\n");
    if (denom == 0) {
        throw runtime_error("divide by zero is illegal\n");
    }

    frac.init_and_reduce(num, denom);
    
    return input_s;

    }

    //// Comparison Operators ////////

      /////Operator == /////

    bool Fraction::operator == (const Fraction& other) const{

        int gc = gcd(other.numerator, other.denominator);

        return this->numerator == (other.numerator/gc) && this->denominator ==(other.denominator/gc);
    }
    
    bool Fraction::operator == (float fl1) const{

        return *this == Fraction(fl1);

    }

    bool operator == (float fl1, const Fraction& other){

        return Fraction(fl1) == other ;

    } 

    //// Operator > //////

    bool Fraction::operator > (const Fraction& other) const{

        int lcm = (this->denominator * other.denominator)/gcd(this->denominator, other.denominator);
        int num_this = this->numerator *(lcm/this->denominator);
        int num_other = other.numerator *(lcm/other.denominator);

        return num_this > num_other ; 
    }
    
    bool Fraction::operator > (float fl1) const{

        return *this > Fraction(fl1);

    }

    bool operator > (float fl1, const Fraction& other){

        return Fraction(fl1) > other;

    }

    ///// Operator < ////////

    bool Fraction::operator < (const Fraction& other) const{

        int lcm = (this->denominator * other.denominator)/gcd(this->denominator, other.denominator);
        int num_this = this->numerator *(lcm/this->denominator);
        int num_other = other.numerator *(lcm/other.denominator);

        return num_this < num_other ; 

    }
    
    bool Fraction::operator < (float fl1) const{

        return *this < Fraction(fl1);
    }

    bool operator < (float fl1, const Fraction& other){

        return Fraction(fl1) < other;
    }

    ///// Operator >= ////

    bool Fraction::operator >= (const Fraction& other) const{

        return *this > other || *this == other ;
    }
    
    bool Fraction::operator >= (float fl1) const{

        return *this >= Fraction(fl1);

    }

    bool operator >= (float fl1, const Fraction& other){

        return Fraction(fl1) >= other ;

    }

     ///// Operator <= ////

    bool Fraction::operator <= (const Fraction& other) const{

        return *this < other || *this == other ;
    }
    
    bool Fraction::operator <= (float fl1) const{

        return *this <= Fraction(fl1);

    }

    bool operator <= (float fl1, const Fraction& other){

        return Fraction(fl1) <= other ;

    }
   
    int Fraction::getNumerator(){
        return this->numerator;
    }

    int Fraction::getDenominator(){
        return this->denominator;
    }
}
#ifndef COURSE_WORK1_2_COMPLEX_STRING_H
#define COURSE_WORK1_2_COMPLEX_STRING_H

#include "Base_String.h"

class Complex_String:public Base_String {
protected:
    double real;
    double imaginary;

    void make_number();
public:
    Complex_String(int = 0);
    Complex_String(const char *);
    Complex_String(const Complex_String &);
    ~Complex_String();

    Complex_String &operator=(const Complex_String &);
    friend Complex_String operator-(const Complex_String &, const Complex_String &);
    friend bool operator== (Complex_String const &, Complex_String const &);
};


#endif //COURSE_WORK1_2_COMPLEX_STRING_H

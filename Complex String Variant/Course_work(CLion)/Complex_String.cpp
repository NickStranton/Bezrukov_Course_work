#include "Complex_String.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

Complex_String::Complex_String(int string_length) : Base_String(string_length){ }

Complex_String::Complex_String(const char *c_string) : Base_String(c_string) {
    int separator_index = 0;
    for (int position = 0; position < string_length; position++) {
        if (char_pointer[position] == 'i') {
            separator_index = position;
            cout << "Separator is found on " << position << "!" << endl;
            return;
        }
    }
    if (separator_index > 0) {
        real = stoi(string(c_string).substr(0, string_length - 1 - separator_index));
        imaginary = stoi(string(c_string).substr(separator_index + 1));
    }
}

Complex_String::Complex_String(const Complex_String & from) : Base_String(from) {}

Complex_String::~Complex_String() = default;

void Complex_String::make_number() {
    string number = to_string(real) + 'i' + to_string(imaginary);
    string_length = number.size() + 1;
    char_pointer = (char*)number.c_str();
}

Complex_String &Complex_String::operator=(const Complex_String &S) {
    if (&S != this) {
        delete[] char_pointer;
        string_length = strlen(S.char_pointer);
        char_pointer = new char[string_length + 1];
        strcpy_s(char_pointer, string_length + 1, S.char_pointer);
    }
    cout << "Complex::operator = " << endl;
    return *this;
}

Complex_String operator-(const Complex_String & A, const Complex_String & B) {
    //Вообще понятия не имею как эта штука работает
    char* iB = strstr(B.char_pointer, "i");
    int d = atoi(iB + 1);
    char *bsub = new char[iB - B.char_pointer + 1];
    memcpy_s(bsub, iB - B.char_pointer + 1, B.char_pointer, iB - B.char_pointer);
    bsub[iB - B.char_pointer] = '\0';
    int c = atoi(bsub);
    delete[] bsub;

    char* iA = strstr(A.char_pointer, "i");
    int b = atoi(iA + 1);
    char *asub = new char[iA - A.char_pointer + 1];
    memcpy_s(asub, iA - A.char_pointer + 1, A.char_pointer, iA - A.char_pointer);
    asub[iA - A.char_pointer] = '\0';
    int a = atoi(asub);
    delete[] asub;

    char* endA = new char[A.string_length];
    _itoa_s((a - c), endA, A.string_length, 10);
    char* endB = new char[A.string_length];
    _itoa_s((b - d), endB, A.string_length, 10);

    char* end = new char[strlen(endA) + strlen(endB) + 2];
    memcpy_s(end, strlen(end), endA, strlen(endA));
    memcpy_s(end + strlen(endA), strlen(end), "i", 1);
    memcpy_s(end + strlen(endA) + 1, strlen(end), endB, strlen(endB));
    end[strlen(endA) + strlen(endB) + 1] = '\0';
    delete[] endA;
    delete[] endB;
    cout << "Complex operator - " << endl;
    return Complex_String(end);
}

bool operator==(const Complex_String &cmpstr1, const Complex_String &cmpstr2) {
    cout << "Complex :operator ==" << endl;
    if ((cmpstr1.char_pointer[0] == '+' && cmpstr2.char_pointer[0] == '-') || (cmpstr1.char_pointer[0] == '-' && cmpstr2.char_pointer[0] == '+'))
        return false;

    if (cmpstr1.char_pointer[0] == '+' && cmpstr2.char_pointer[0] != '+' && cmpstr2.char_pointer[0] != '-') {
        if (cmpstr1.string_length != (cmpstr2.string_length + 1))
            return false;
        for (int i = 0; i < cmpstr1.string_length; i++) {
            if (cmpstr1.char_pointer[i + 1] != cmpstr2.char_pointer[i])
                return false;
        }
        return true;
    }
    if (cmpstr1.char_pointer[0] != '+' && cmpstr2.char_pointer[0] == '+' && cmpstr1.char_pointer[0] != '-') {
        if ((cmpstr1.string_length + 1) != cmpstr2.string_length)
            return false;
        for (int i = 0; i < cmpstr2.string_length; i++) {
            if (cmpstr1.char_pointer[i] != cmpstr2.char_pointer[i + 1])
                return false;
        }
        return true;
    }
    if (cmpstr1.char_pointer[0] == '-' && cmpstr2.char_pointer[0] == '-') {
        if (cmpstr1.string_length != cmpstr2.string_length)
            return false;
        for (int i = 0; i < cmpstr1.string_length; i++) {
            if (cmpstr1.char_pointer[i] != cmpstr2.char_pointer[i])
                return false;
        }
        return true;
    }

    if (cmpstr1.string_length != cmpstr2.string_length) {
        return false;
    }
    else if (cmpstr1.string_length == cmpstr2.string_length) {
        for (int i = 0; i < cmpstr1.string_length; i++) {
            if (cmpstr1.char_pointer[i] != cmpstr2.char_pointer[i])
                return false;
        }
        return true;
    }
    else {
        return false;
    }

}






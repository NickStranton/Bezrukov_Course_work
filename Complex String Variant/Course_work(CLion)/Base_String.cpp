//
// Created by Paul on 15/04/2020.
//

#include "Base_String.h"
#include <string.h>
#include <iostream>

using namespace std;

Base_String::Base_String(int value) {
    string_length = value;
    char_pointer = new char[string_length + 1];

    if(value == 0) char_pointer[0] = '\0';
    cout << "Base_String(int) done!" << endl;
}

Base_String::Base_String(char ch) {
    string_length = 1;
    char_pointer = new char[string_length + 1];

    char_pointer[0] = ch;
    char_pointer[1] = '\0';
    cout << "Base_Strng(char) done!" << endl;
}

Base_String::Base_String(const char * S) {
    string_length = strlen(S);
    char_pointer = new char[string_length + 1];
    strcpy_s(char_pointer, string_length + 1, S);
    cout << "Base_String(const char*) done!" << endl;
}

Base_String::Base_String(const Base_String &object) {
    string_length = strlen(object.char_pointer);
    char_pointer = new char[object.string_length + 1];
    strcpy_s(char_pointer, object.string_length + 1, object.char_pointer);
    cout << "Base_String(const Base_String&) done!" << endl;
}
 Base_String::~Base_String() {
    if(char_pointer) delete[] char_pointer;
    cout << "~Base_String done!" << endl;
}

int Base_String::get_length() const {
    return string_length;
}

char* Base_String::get_value() const {
    return char_pointer;
}

void Base_String::Show() {
    cout << "Char pointer = " << get_value() << endl;
    cout << "String length = " << get_length() << endl;
    cout << "Showed all!" << endl << endl;
}


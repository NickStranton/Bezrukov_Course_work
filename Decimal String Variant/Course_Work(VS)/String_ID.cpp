#define _CRT_SECURE_NO_WARNINGS
#include "String_ID.h"
#include <string.h>
#include <iostream>


using namespace std;

String_ID::String_ID(int value) :Base_String(value) {
	string_length = 0;
	char_pointer = new char[1];
	*char_pointer = 0;
	cout << "StringID(int val)" << endl;
}


String_ID::String_ID(char ch) : Base_String(ch) {
	if ((char_pointer[0] >= 'a' && char_pointer[0] <= 'z') || (char_pointer[0] >= 'A' && char_pointer[0] <= 'Z') || (char_pointer[0] == '_')) {
		cout << "StringID(char ch)" << endl;
	}
	else {
		if (char_pointer) delete[] char_pointer;
		string_length = 0;
		char_pointer = new char[string_length + 1];
		char_pointer[0] = '\0';
		cout << "Bad symbol!" << "char_pointer = " << char_pointer << endl;
	}
}

String_ID::String_ID(const char* S) : Base_String(S) {
	for (int i = 0; char_pointer[i] != '\0'; i++) {
		if ((char_pointer[i] >= 'a' && char_pointer[i] <= 'z') || (char_pointer[i] >= 'A' && char_pointer[i] <= 'Z') || (char_pointer[i] == '_')) {

		}
		else {
			if (char_pointer) delete[] char_pointer;
			string_length = 0;
			char_pointer = new char[string_length + 1];
			char_pointer[0] = '\0';
			cout << "Bad symbol position: " << i << endl;
			return;
		}
	}
}

String_ID::String_ID(const String_ID &from) : Base_String(from) {  }

String_ID::~String_ID() {
	cout << "~String_ID()" << endl;
}

String_ID & String_ID :: operator = (const String_ID &S) {
	if (&S != this) {
		delete[] char_pointer;
		string_length = strlen(S.char_pointer);
		char_pointer = new char[string_length + 1];
		strcpy_s(char_pointer, string_length + 1, S.char_pointer);
	}
	cout << "String_ID::operator = (const String_ID &S)" << endl;
	return*this;
}

char &String_ID::operator [] (int index) {
	if ((index >= 0) && (index < string_length)) {
		return char_pointer[index];
	}
	cout << "Operator [] done!" << endl;
	return char_pointer[0];
}

String_ID String_ID::operator+(const String_ID&s) const { //21.04
	String_ID result;
	delete[] result.char_pointer;
	result.string_length = string_length + s.string_length;
	result.char_pointer = new char[result.string_length + 1];
	strcpy(result.char_pointer, char_pointer);
	strcat(result.char_pointer + string_length, s.char_pointer);
	cout << "Operator + done!" << endl;
	return result;
}

String_ID String_ID::operator+(const char * s) const {//21.04
	String_ID result;
	delete[] result.char_pointer;
	result.string_length = string_length + strlen(s);
	result.char_pointer = new char[result.string_length + 1];
	strcpy(result.char_pointer, char_pointer);
	strcat(result.char_pointer + string_length, s);
	cout << "Operator + done!" << endl;
	return result;
}

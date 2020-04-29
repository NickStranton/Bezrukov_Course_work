#include "String_ID.h"
#include <cstring>
#include <iostream>

using namespace std;

String_ID::String_ID(int value) :Base_String(value) {
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

String_ID::String_ID(const String_ID& from) : Base_String(from) { }

String_ID::~String_ID() {
	cout << "~String_ID()" << endl;
}

String_ID& String_ID::operator=(const String_ID& S) {
	if (&S != this) {
		delete[] char_pointer;
		string_length = strlen(S.char_pointer);
		char_pointer = new char[string_length + 1];
		strcpy_s(char_pointer, string_length + 1, S.char_pointer);
	}
	cout << "String_ID::operator = (const String_ID &S)" << endl;
	return*this;
}

String_ID operator-(const String_ID& right, const String_ID& left) {
	int i = right.string_length;
	char k;
	char z;

	while (i > -1) {
		i--;
		for (int j = 0; j < left.string_length; j++) {
			if (right.char_pointer[i] == left.char_pointer[j] && i != right.string_length - 1) {
				z = right.char_pointer[i];
				for (int c = i; c < right.string_length; c++) {
					k = right.char_pointer[c];
					right.char_pointer[c] = right.char_pointer[c + 1];
					right.char_pointer[c + 1] = k;
				}
				right.char_pointer[right.string_length - 1] = '\0';
				i = right.string_length;
			};
			if (right.char_pointer[i] == left.char_pointer[j] && i == right.string_length - 1) {
				right.char_pointer[i] = '\0';
				i = right.string_length;
			}
		}
	}
	cout << "String_ID::operator-(const String_ID &S) done!" << endl;
	return right.char_pointer;

}

bool operator == (String_ID const& a, String_ID const& b) {
	if (a.string_length != b.string_length)
		return false;
	for (int i = 0; i < a.string_length; i++) {
		if (a.char_pointer[i] != b.char_pointer[i])
			return false;
	}
	return true;
}
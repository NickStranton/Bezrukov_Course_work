#pragma once
#include "Base_String.h"

class String_ID :public Base_String {
public:

	String_ID(int = 0);
	String_ID(char);
	String_ID(const char*);
	String_ID(const String_ID&);
	~String_ID();


	String_ID &operator = (const String_ID&);

	char &operator[] (int);
	String_ID operator+(const String_ID&s) const ;
	String_ID operator+(const char * s) const;
};


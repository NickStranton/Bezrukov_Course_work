#pragma once
#include "Base_String.h"

class DecimalString : public Base_String
{
	char sign = 0;
	int number=0;
public:
	DecimalString( int = 0);
	DecimalString(char);
	DecimalString(const char*);
	DecimalString(const DecimalString&);
	~DecimalString();

	DecimalString& operator=(const DecimalString&);
	friend DecimalString operator+(const DecimalString&,const DecimalString&);

	char GetSign();
	virtual void Show();
	char* GetStr(void) const { return char_pointer; };
};


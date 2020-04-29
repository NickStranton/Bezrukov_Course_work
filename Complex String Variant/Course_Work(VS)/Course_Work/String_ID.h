#ifndef COURSE_WORK1_2_STRING_ID_H
#define COURSE_WORK1_2_STRING_ID_H

#include "Base_String.h"

class String_ID :public Base_String {
public:
	String_ID(int = 0);
	String_ID(char);
	String_ID(const char*);
	String_ID(const String_ID&);
	~String_ID();
	String_ID& operator = (const String_ID&);
	friend String_ID operator- (const String_ID&, const String_ID&);
	friend bool operator== (String_ID const&, String_ID const&);
};


#endif //COURSE_WORK1_2_STRING_ID_H


#pragma once

class Base_String {
protected:
	int string_length;
	char* char_pointer;

public:
	Base_String(int = 0);
	Base_String(char);
	Base_String(const char*);
	Base_String(const Base_String&);
	~Base_String();

	int get_length() const;
	char* get_value() const;

	void Show(void);
	virtual void Clear();
};

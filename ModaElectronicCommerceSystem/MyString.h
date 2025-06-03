#pragma once
#include <iostream>
#include "Constants.h"
using namespace Constants;

class MyString
{
	char* data = nullptr;
	size_t size = 0;
	size_t capacity = INITIAL_CAPACITY;

	void free();
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void resize(size_t newCapacity);

public:
	MyString();
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;

	MyString(const char* str);

	size_t getSize() const;
	size_t getCapacity() const;

	const char* c_str() const;

	char& operator[](unsigned index);
	const char& operator[](unsigned indexs) const;

	MyString& operator+=(const MyString& other);

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::ostream& operator<<(std::ostream& os, const MyString& str);
	friend std::istream& operator>>(std::istream& is, MyString& str);

	MyString substr(unsigned begin, unsigned howMany);
};

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
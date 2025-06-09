#include "MyString.h"
#include <utility>
#include <stdexcept>
#pragma warning (disable : 4996)

void MyString::free()
{
	delete[] data;

	data = nullptr;
	size = 0;
	capacity = 0;
}

void MyString::copyFrom(const MyString& other)
{
	capacity = other.capacity;
	size = other.size;

	data = new char[capacity + 1] {};
	strcpy(data, other.data);
}

void MyString::moveFrom(MyString&& other)
{
	capacity = other.capacity;
	size = other.size;
	data = other.data;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

void MyString::resize(size_t newCapacity)
{
	char* newData = new char[newCapacity + 1] {};
	capacity = newCapacity;
	strcpy(newData, data);
	delete[] data;
	data = newData;
}

MyString::MyString() 
{
	data = new char[capacity + 1] {};
	size = 0;
	capacity = 0;
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

MyString::~MyString()
{
	free();
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString::MyString(const char* str)
{
	if (!str)
	{
		str = "";
	}

	size = strlen(str);
	
	if (size >= capacity)
	{
		resize(size*2);
	}

	data = new char[capacity + 1] {};
	strcpy(data, str);
}

size_t MyString::getSize() const
{
	return size;
}

size_t MyString::getCapacity() const
{
	return capacity;
}

const char* MyString::c_str() const
{
	return data;
}

char& MyString::operator[](unsigned index)
{
	if (index >= size)
	{
		throw std::out_of_range("Index out of bounds!");
	}

	return data[index];
}

const char& MyString::operator[](unsigned index) const
{
	if (index >= size)
	{
		throw std::out_of_range("Index out of bounds!");
	}

	return data[index];
}

MyString& MyString::operator+=(const MyString& other)
{
	size_t newSize = size + other.size;
	if (newSize > capacity)
	{
		resize(newSize * 2);
	}

	strncat(data, other.data, other.size);
	size += other.size;

	return *this;
}

MyString MyString::substr(unsigned begin, unsigned howMany)
{
	if (begin + howMany > size)
	{
		throw std::out_of_range("Invalid parameters!");
	}

	MyString res;
	res.capacity = capacity;
	res.data = new char[capacity + 1] {};
	strncat(res.data, data + begin, howMany);
	res.size = howMany;

	return res;
}

bool MyString::isEmpty() const
{
	return size == 0;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString res(lhs);
	res += rhs;

	return res;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.data;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024]{};
	is >> buff;

	size_t buffStringSize = strlen(buff);
	if (buffStringSize >= str.capacity)
		str.resize(buffStringSize);

	strcpy(str.data, buff);
	str.size = buffStringSize;

	return is;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return !(lhs == rhs);
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
#include "String.h"
#include <iostream>
#include <memory>
#include <algorithm>
#include <utility>
#include <cstring>
#include <initializer_list>

String::String(const char *cstr)
{
	auto data = copyStr(cstr, cstr + strlen(cstr));
	elements = data.first;
	first_new = cap = data.second;
}

String::String(const String &str)
{
//	std::cout << "copy: ";
//	for(auto i = str.begin(); i < str.end(); ++i)
//		std::cout << *i << " ";
//	std::cout << std::endl;
	auto data = copyStr(str.begin(), str.end());
	elements = data.first;
	first_new = cap = data.second;
}

String &String::operator=(const String &str)
{
	if(&str != this)
	{
		free();
		auto data = copyStr(str.begin(), str.end());
		elements = data.first;
		first_new = cap = data.second;
	}
	return *this;
}

void String::push_back(const char c)
{
	checkCapacity();
	alloc.construct(first_new++, c);
}

void String::free()
{
	if(elements != nullptr)
	{
		std::for_each(elements, first_new, [this](char &c){alloc.destroy(&c);});
		alloc.deallocate(elements, capacity());
	}
}

void String::reallocate()
{
	size_t newSize = capacity() > 0? capacity() * 2: 1;
	auto newHead = alloc.allocate(newSize);
	auto cursor = newHead;
	std::for_each(elements, first_new, [this, &cursor](char &c){alloc.construct(cursor++, std::move(c));});
	size_t len = size();
	free();
	first_new = newHead + len;
	cap = newHead + newSize;
	elements = newHead;
}

std::pair<char *, char *> String::copyStr(const char *left, const char *right)
{
	auto newHead = alloc.allocate(right - left);
	return {newHead, std::uninitialized_copy(left, right, newHead)};
}

std::ostream& operator<<(std::ostream &out, const String &str)
{
//	std::cout << "<<" << std::endl;
	char *ptr = str.elements;
	while(ptr != str.first_new)
		out << *(ptr++);// << " ";
	return out;
}

std::istream& operator>>(std::istream &in, String &str)
{
	String temp;
	char c;
	while(in >> std::noskipws >> c)
	{
		if(c == ' ' || c == '\n')
			break;
		temp.push_back(c);
	}
	if(in || in.eof())
		str = temp;
	return in;
}

bool operator==(const String &a, const String &b)
{
	if(a.size() != b.size())
		return false;
	auto i = a.begin();
	auto j = b.begin();
	while(i != a.end())
	{
		if(*i != *j)
			return false;
		++i; ++j;
	}
	return true;
}

bool operator!=(const String &a, const String &b)
{
	return !(a == b);
}

String &String::operator=(std::initializer_list<char> cl)
{
	//auto data = copyStr(&(*cl.begin()), &(*cl.end()));
	auto data = copyStr(cl.begin(), cl.end());
	free();
	elements = data.first;
	first_new = cap = data.second;
	return *this;
}

String::String(std::initializer_list<char> cl)
{
	auto data = copyStr(cl.begin(), cl.end());
	elements = data.first;
	first_new = cap = data.second;
}

char &String::operator[](const size_t n)
{
	return *(elements + n);
}

const char &String::operator[](const size_t n) const
{
	return *(elements + n);
}

String &String::operator+=(const String &str)
{
	for(auto i = str.begin(); i != str.end(); ++i)
		push_back(*i);
	return *this;
}

String operator+(const String &left, const String &right)
{
	String temp(left);
	temp += right;
	return temp;
}







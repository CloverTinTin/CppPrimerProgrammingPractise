#include "String.h"
#include <iostream>
#include <memory>
#include <algorithm>
#include <utility>
#include <cstring>

String::String(char *cstr)
{
	auto data = copyStr(cstr, cstr + strlen(cstr));
	elements = data.first;
	first_new = cap = data.second;
}

String::String(const String &str)
{
	auto data = copyStr(str.begin(), str.end());
	elements = data.first;
	first_new = cap = data.second;
}

String &String::operator=(const String &str)
{
	free();
	auto data = copyStr(str.begin(), str.end());
	elements = data.first;
	first_new = cap = data.second;
	return *this;
}

void String::push_back(char c)
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
}

std::pair<char *, char *> String::copyStr(char *left, char *right)
{
	auto newHead = alloc.allocate(right - left);
	return {newHead, std::uninitialized_copy(left, right, newHead)};
}




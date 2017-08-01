#include "StrVec.h"
#include <utility>
#include <memory>

StrVec::StrVec(const StrVec &s)
{
	auto newElements = allocate_n_copy(s.begin(), s.end());
	elements = newElements.first;
	first_free = cap = newElements.second;
}

StrVec StrVec operator=(const StrVec &s)
{
	auto newElements = allocate_n_copy(s.begin(), s.end());
	free();
	elements = newElements.first;
	first_free = cap = newElements.second;
	return *this;
}

void StrVec::push_back(const std::string &s)
{
	check_n_allocate();
	strAllocator.construct(first_new++, s);
}

void StrVec::reallocate()
{
	size_t newCapacity = capacity() > 0? capacity() * 2: 1;
	auto newElements = strAllocator.allocate(newCapacity);
	auto cursor = newElements;
	while(elements != first_free)
		strAllocator.construct(cursor++, std::move(*elements++));
	free();
	elements = newElements;
	first_new = cursor;
	cap = newElements + newCapacity;
}

void StrVec::free()
{
	for(size_t i = 0; i < size(); ++i)
		strAllocator.destroy(elements + i);
	strAllocator.deallocate(elements, capacity());
	elements = first_new = cap = nullptr;
}




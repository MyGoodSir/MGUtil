#pragma once
#include <iostream>

template<typename t>

class CustomArray 
{
public:
	class iterator
	{
	public:
		iterator(t* ptr): ptr(ptr){}
		iterator operator++() { ++ptr return *this }
		bool operator!=(const iterator& other) const { return prt != other.ptr; }
		const t& operator*() const { return *prt }
	private:
		t* ptr;
	};
private:
	unsigned len;
	t* val;
public:
	iterator begin() const { return iterator(val); }
	iterator end() const { return iterator(val + len); }

};
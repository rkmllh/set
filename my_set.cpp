#include "my_set.h"
#include <string.h>

#define memzero(base,size)	\
	memset(base, 0, size)

my_set::my_set(int sz)
{
	if (sz <= 0)
		throw my_under_range{};

	this->m_capacity = sz;
	this->m_cardinality = 0;
	this->m_size = sz / (sizeof(int) * 8) + 1;
	this->m_vct = new int[this->m_size];

	if (this->m_vct == nullptr)
		throw my_bad_alloc {};

	this->init();
}

bool my_set::m_get(int pos)
{
	if (pos < 0 || pos > this->m_capacity)
		throw my_out_of_range{};

	//Get index into vector
	int index = (pos / (sizeof(int) * 8));

	//Get bit into a single cell
	int bit = ((this->m_vct[index] >> (pos % (sizeof(int) * 8))) & 1);

	return bit;
}

bool my_set::m_add(int value)
{
	bool bit = this->m_get(value);
	if (bit == false)
	{
		this->m_set(value, true);
		bit = true;
		++this->m_cardinality;
	}

	return bit;
}

bool my_set::m_remove(int value)
{
	bool bit = this->m_get(value);
	if (bit == true)
	{
		this->m_set(value, false);
		bit = false;
		--this->m_cardinality;
	}

	return bit;
}

bool my_set::m_set(int value, bool bit)
{
	int& pos = value;

	if (pos < 0 || pos > this->m_capacity)
		throw my_out_of_range{};

	//Get index into vector
	int index = (pos / (sizeof(int) * 8));

	//Set bit
	if (bit == true)
		this->m_vct[index] = (1 << (pos % (sizeof(int) * 8))) | this->m_vct[index];
	else 	//Unset bit
		this->m_vct[index] = ~(1 << (pos % (sizeof(int) * 8))) & this->m_vct[index];

	return bit;
}

void my_set::init()
{
	memzero(this->m_vct, sizeof(int) * this->m_size);
}

my_set::~my_set()
{
	if (this->m_vct != nullptr)
	{
		delete[] this->m_vct;
		this->m_vct = nullptr;
	}
}
#pragma once
#include <exception>

struct my_bad_alloc : std::exception
{
	const char* what() { return "bad_alloc"; }
};

struct my_under_range : std::exception
{
	const char* what() { return "under_range"; }
};

struct my_out_of_range : std::exception
{
	const char* what() { return "out_of_range"; }
};

class my_set
{

public:
	my_set() : m_vct{ nullptr }, m_size{ 0 }, m_capacity{ 0 }, m_cardinality{ 0 } {}
	my_set(int sz);

	//Getters
	virtual bool m_get(int pos);
	virtual int m_get_capacity()       const noexcept { return this->m_capacity; }
	virtual int m_get_size()           const noexcept { return this->m_size; }
	virtual int m_get_cardinality()    const noexcept { return this->m_cardinality; }

	//Setters
	virtual bool m_add(int value);
	virtual bool m_remove(int value);

	virtual ~my_set();

	//Add your interface

protected:
	virtual void init();
	virtual bool m_set(int value, bool bit);

private:
	int m_cardinality;      //Current cardinality of container
	int m_capacity;		    //Capacity of container
	int m_size;				//Size of container
	int* m_vct;				//Container of integers
};
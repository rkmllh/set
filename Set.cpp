#include <iostream>
#include "my_set.h"

using std::cerr;
using std::cout;
using std::endl;

int main(int argc, char** argv)
{
	try
	{
		constexpr auto n_items = 50;
		//Create a set of capacity == 50, |s| == 0
		my_set s(n_items);

		s.m_add(12);
		s.m_add(15);
		s.m_add(33);
		s.m_add(17);
		s.m_add(11);
		s.m_add(3);

		//Try to remove same number
		s.m_remove(15);
		s.m_remove(15);
		s.m_remove(15);

		for (auto i = 0; i <= n_items; ++i)
			std::cout << "Number " << i << " is present:\t" << std::boolalpha << s.m_get(i) << endl;

		std::cout << "Deleting all items but 33..." << endl << endl;

		s.m_remove(12);
		s.m_remove(17);
		s.m_remove(11);
		s.m_remove(3);

		for (int i = 0; i <= n_items; ++i)
			std::cout << "Number " << i << " is present:\t" << std::boolalpha << s.m_get(i) << endl;

	}
	catch (...)
	{
		//Take your action
		cerr << "some_exception!" << endl;
	}
}
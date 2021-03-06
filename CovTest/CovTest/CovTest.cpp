// CovTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <initializer_list>
#include <algorithm>
#include <iostream>

template<class T>
class Image
{
	T *ptr;
	int width;
	int height;
public:
	Image(std::initializer_list<std::initializer_list<T>> list)
	{
		height = list.size();
		width = list.begin()->size();
		ptr = new T[width * height];
		auto tmp_ptr = ptr;
		for (auto& row : list)
		{
			for (auto& el : row)
			{
				*tmp_ptr = el;
				++tmp_ptr;
			}
		}
	}

	T at(int x, int y)
	{
		return *(ptr + y * width + x);
	}
};

int main()
{
	Image<short> image { { -1, -1, -1 },{ -1, 8, -1 },{ -1, -1, -1 } };
	std::cout << image.at(0,1);
    return 0;
}


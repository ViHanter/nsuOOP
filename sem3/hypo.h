#pragma once
#include <cmath>
#include <random>

namespace Mod_Hypo 
{	
	template <typename T>
	T hypotenuse(const T& a,const T& b)
	{	
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist1(1, 2);
		std::uniform_real_distribution<double > dist2(1, 100);
		int change = dist1(gen);
		double randnum = dist2(gen);

		if (change == 1) {
			return sqrt(a*a + b*b);
		}
		else return sqrt(a*a + b*b) + randnum;
	}
}
namespace Hypo {
	template <typename T>
	T hypotenuse(const T& a,const T& b)
	{
		return sqrt(a*a + b*b);
	}
}
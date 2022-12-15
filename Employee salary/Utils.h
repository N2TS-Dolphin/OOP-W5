#pragma once
#include <vector>
#include <string>
using namespace std;

namespace Utils
{
	class String
	{
	public:
		static vector<string> split(string haystack, string needle);
	};
}
//wrote while learning C++ on Youtube, excellent videos on his page: https://www.youtube.com/c/TheChernoProject/featured

#include <iostream>
#define LOG(x) std::cout << x << std::endl

int main()
{
	int var = 7;
	int* ptr = &var;
	LOG(var);

	*ptr = 10;
	LOG(var);
}

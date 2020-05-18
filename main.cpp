#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <list>
#include <deque>
#include <time.h>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <ctime>
#include <random>
#include "mano vector.h"

int main()
{
	std::ofstream RZ("Rezultatai.txt");
	int cap = 0, sz = 10000000;
	auto begin = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();
	for (int y = 0; y < 1; y++)
	{
		sz *= 10;
		RZ << sz << "Irasu" << std::endl;
		begin = std::chrono::high_resolution_clock::now();
		std::vector<int> v1;
		for (int i = 1; i <= sz; ++i)
		{
			v1.push_back(i);
		}
		end = std::chrono::high_resolution_clock::now();
		RZ << "Irasyti duomenis i std::vector uztruko " << std::endl;
		RZ << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosekundziu" << std::endl;
		v1.clear();
		begin = std::chrono::high_resolution_clock::now();
		vector<int> v2;
		for (int i = 1; i <= sz; ++i)
		{
			v2.push_back(i);
		}
		end = std::chrono::high_resolution_clock::now();
		RZ << "Irasyti duomenis i mano vector uztruko " << std::endl;
		RZ << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosekundziu" << std::endl;
		v2.clear();
	}
	return 0;
}

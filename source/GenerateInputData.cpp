#include <iostream>
#include <fstream>
#include "DataGenerator.h"

int generate(int x) {

	int inputSize[] = {10000, 30000, 50000, 100000, 300000, 500000};
	int n = inputSize[x];
	int* a = new int[n];

	std::string *s = new std::string[4];
	s[0] = "sample_inputs/randomized_data/randomized_data_" + std::to_string(n) + ".txt";
	s[1] = "sample_inputs/sorted_data/sorted_data_" + std::to_string(n) + ".txt";
	s[2] = "sample_inputs/reversed_sorted_data/reversed_sorted_data_" + std::to_string(n) + ".txt";
	s[3] = "sample_inputs/nearly_sorted_data/nearly_sorted_data_" + std::to_string(n) + ".txt";

	std::ofstream* fo = new std::ofstream[4];
	for(int i = 0; i < 4; i++) fo[i].open(s[i]);

	for (int i = 0; i < 4; i++)
	{
		GenerateData(a, n, i);

		for (int j = 0; j < n; j++) 
		{
			fo[i] << a[j] << " ";
		}
	}

	delete[] a;

	for (int i = 0; i < 4; i++) {
		fo[i].close();
	}

	delete[] fo;

	return 0;
}
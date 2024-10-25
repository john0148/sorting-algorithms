#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <assert.h>
#include "BasicSort.h"
#include "AdvancedSort.h"
#include "NoComparisonSort.h"
#include "FlashSort.h"
#include "CommandProcess.h"


std::string sort_names[] = 
    {
        "Selection sort", "Insertion sort", "Bubble sort",
        "Shaker sort", "Shell sort",
        "Heap sort", "Merge sort", "Quick sort",
        "Counting sort", "Radix sort", "Flash sort"
    };

std::string data_order[] =
    {
        "randomized data",
        "sorted data",
        "reversed sorted data",
        "nearly sorted data"
    };

void testAlgorithm(int i) {
    std::string output_file = "output/output " + sort_names[i] + ".csv";
    std::ofstream myFile(output_file);
    myFile << "Data size" << "," << "Name algorithm" << "," << "Data order" << "," << "Running time" << "," << "Comparisions" << "\n";
    

    std::ifstream* fi = new std::ifstream[4];
    std::ofstream* fo = new std::ofstream[4];

    int inputSize[] = {10000, 30000, 50000, 100000, 300000, 500000};
    for(int _size = 0; _size < 6; ++_size){
        std::cout << "Part " << _size << "\n";
        // iterate through inputSize[]
        int n = inputSize[_size];

        std::string *s = new std::string[4];

        s[0] = "sample_inputs/randomized_data/randomized_data_" + std::to_string(n) + ".txt";
        s[1] = "sample_inputs/sorted_data/sorted_data_" + std::to_string(n) + ".txt";
        s[2] = "sample_inputs/reversed_sorted_data/reversed_sorted_data_" + std::to_string(n) + ".txt";
        s[3] = "sample_inputs/nearly_sorted_data/nearly_sorted_data_" + std::to_string(n) + ".txt";

        for (int j = 0; j < 4; j++)
        {
            fi[j].open(s[j]);
            if (!fi[j].is_open())
            {
                std::cerr << "Failed to open file: " << s[j] << std::endl;
                assert(false);
            }
        }

        int* a = new int[n];

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < n; k++)
            {
                fi[j] >> a[k];
            }

            double timeUsed = timeCounting(a, n, i);
            
            for (int k = 0; k < n; k++)
            {
                fo[j] << a[k] << " ";
            }

            fi[j].clear();
            fi[j].seekg(0, std::ios::beg);

            for (int k = 0; k < n; k++){
                fi[j] >> a[k];
            }
            long long cmp = comparisonCounting(a, n, i);

            myFile << n << "," << sort_names[i] << ","  << data_order[j] << "," << timeUsed << "," << cmp << "\n";
        }

        delete[] a;

        for (int j = 0; j < 4; j++) {
            fi[j].close();
        }

        delete[] s;        

    }
    delete[] fi;
    delete[] fo;
    myFile.close();
}

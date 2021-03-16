// Assignment 01.03.2021
// CS310 Data Structures and Algorithms
// Flavjo Xhelollari

#include<iostream>
#include<vector>
#include<chrono>
#include<random>
#include<fstream>


using namespace std;

const unsigned MAX_RANDOM_VALUE = 1000000;

void shellsort(vector<unsigned>& array, int type);


int main(int argc, char *argv[])
{	
	// Declaring the vector which will hold the values
	vector <unsigned> vector;
	
	// Getting mode type (1 or 2) 
	int mode = atoi(argv[1]);
	
	// Getting type of gaps (1, 2 or 3)
	int type = atoi(argv[3]);
	
	// Getting the size of the array
	size_t size_of_array = size_t(atoi(argv[2]));
	
	// Proceeding with mode type 1
	if(mode == 1)
	{
		default_random_engine get_next_value
	    	    (static_cast <unsigned>
	     	     (chrono::system_clock::now().time_since_epoch().count()));

	 	 uniform_int_distribution<unsigned> rng(0, MAX_RANDOM_VALUE);
		
		 for (size_t i = 0; i < size_of_array; i++)
		{
			unsigned random_value = rng(get_next_value);

			vector.push_back(random_value);

		}
		
		cout << endl;
		cerr << size_of_array << " " << endl;
		cout << endl;

		shellsort(vector, type);
		
		

	}
	
	else if (mode == 2)	
	{	
		ifstream fileB;
		string type_gap = string(argv[2]);
		fileB.open(type_gap);	

		//Read dat file and store it's info in a vector.
		unsigned current_number = 0;

		while(fileB >> current_number)
		{
			
			vector.push_back(current_number);
		}
		
		shellsort(vector, type);
	}

	for (auto value : vector) 
		{
	   	   cout << value << " ";
	
		}
	
	cout << endl;
	cerr << size_of_array << " ";
	return 0;
}

// Modified version of the original shellsort algorithm.
// Added int mode as a parameter.
// For different modes, uses different gaps.

void shellsort(vector<unsigned>& array, int mode)
{
	unsigned count = 0;	
	size_t n = array.size();
	count += 1;

	//Gap sequence for type 1 : 5, 3, 1 (as given by the instructor)
	//Gap sequence for type 2 : Hibbard's Sequence following the formula
	//2^k−1 thus we have: 7, 3, 1
	//Gap sequence for type 3 : Sedgewick's Sequence following the formula
	//4^k + 3*2^(k-1) + 1 thus we have : 23, 8, 1

	vector<size_t> gaps;
	count += 1;

	if(mode == 1)
	{
		gaps.push_back(5);
		gaps.push_back(3);
		gaps.push_back(1);
	}
	else if (mode == 2)
	{
		gaps.push_back(7);
		gaps.push_back(3);
		gaps.push_back(1);
	}
	else if (mode == 3) 
	{
		gaps.push_back(23);
		gaps.push_back(8);
		gaps.push_back(1);
	}
	
	count += 3; //Either of them will run
	
	for (auto gap : gaps)
	{
		count += 1;
		for (size_t i = gap; i < n; i++)
		{	
			count += 2;
			unsigned temp = array.at(i);
			size_t j = i;
			count += 2; 
			while (j >= gap && temp < array.at(j - gap))
			{
				count+= 2;
				array.at(j) = array.at(j - gap);
				j -= gap;
				count += 2;
			}
			count += 1;
			array.at(j) = temp;
			}
	}
	cerr << count;
}



/** Flavjo Xhelollari
 *  CS310
 *  Assignment 3
 *  31/01/2021
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std;

const unsigned MAX_RANDOM_VALUE = 1000000;

/** This function's purpose is to sort a vector
 *  which is passed as a parameter.
 */

void foo(vector <int>& array);

int main(int argc, char *argv[])
{
	vector <int> vector;

	int vector_counter_int = atoi(argv[1]);
	// Type cast to size_t as index

	default_random_engine get_next_value
	    (static_cast <unsigned>
	     (chrono::system_clock::now().time_since_epoch().count()));
	  uniform_int_distribution<int> rng(-MAX_RANDOM_VALUE, MAX_RANDOM_VALUE);

	for (size_t v_element = 0; v_element < vector_counter_int; v_element++)
	{
		int random_value = rng(get_next_value);

		cout << random_value << " ";

		vector.push_back(random_value);

	}

	cout << endl;
	cerr << vector_counter_int << " ";
	foo(vector);
	return 0;
}

void foo(vector<int>& array)
{
	uint64_t counter = 0; // created counter
	size_t size = array.size();
	counter++; // one assignment operator

	for ( size_t select_indx = 0; select_indx < size - 1; select_indx++)
	{
		counter += 2; // head of the for loop
		int smallest_value = array.at(select_indx);
		size_t smallest_indx = select_indx;
		counter++;
		counter++;

		for (size_t compare_indx = select_indx + 1; compare_indx < size; compare_indx++)
		{
			counter += 2; // header of inner for loop

			counter ++; // if header

			if (array.at(compare_indx) < smallest_value)
			{
				counter++;
				counter++;
				// two assignment operators

				smallest_value = array.at(compare_indx);
				smallest_indx = compare_indx;
			}
		}

		counter++; // if the inner loop is false
		counter += 2; // swap function has 2 ops per run
		swap(array.at(smallest_indx), array.at(select_indx));
		}
		counter++; // when outer loop terminates.

		cerr << counter << endl;
}


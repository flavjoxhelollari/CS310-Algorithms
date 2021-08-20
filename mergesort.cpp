#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> a, vector<int> b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}

std::vector<int> mergesort(vector<int> a, vector<int> b)
{
	merge(a, b);
	vector<int> c;
	for(size_t i = 0; i < a.size(); i++)
	{
		if(a[i] <= b[i])
		{
			c[i] = a[i];

		}
		else
		{
			c[i] = b[i];
		}

	}
	for (auto x : c)
			 cout << x << " ";

	return c;
};

int main()
{
	std::vector<int> a{1,2,3};
	std::vector<int> b{0,9,6};
	mergesort(a,b);
}

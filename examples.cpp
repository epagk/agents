#include <iostream>
#include <vector>
#include <array>
#include <bits/stdc++.h> 
using namespace std;

vector< vector<int> > create_CS()
{
	vector< vector<int> > CS;

	vector<int> v1;
	vector<int> v2{4,5,6};
	vector<int> v3{7,8,9};
	vector<int> v4{0,3,6};

	v1.push_back(1); v1.push_back(2); v1.push_back(3); 

	CS = {v1, v2, v3, v4 };
	
	return CS;
} 

int main ()
{
	// int members = 5;

	// vector< vector<int> > CS;

	// CS = create_CS();
 // 	// int num = CS.size();
 // 	int num = 50;
 // 	int num_coals = num / members;

 // 	if( num % members == 0)
 // 	{
 // 		cout << "Total number of coalitions is " << num_coals << endl;
 // 	}
 // 	else
 // 	{
 // 		cout << "Total number of coalitions is " << num_coals + 1 << endl;
 // 	}
	


	return 0;
}
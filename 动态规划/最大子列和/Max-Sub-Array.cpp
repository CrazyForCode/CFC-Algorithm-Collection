#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, temp, current, max;
	cin>>n>>max;
	current = max;

	for (int i = 1; i < n; ++i)
	{
		cin>>temp;
		if (current < 0)
			current = temp;
		else 
			current+=temp;
		if (current > max)
			max = current;
	}
	cout<<max;

	return 0;
}
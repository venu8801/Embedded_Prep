// program to find average of the given inputs 
#include <iostream>
int main()
{
	int val, count = 0;
	int sum = 0;
	float average = 0.0;

	while(std::cin  >> val) //takes input till the type of input is not an int type
	{
		sum += val;
		count++;
	}
	std::cout << "average: " << sum/count << "\n";
	return 0;
}

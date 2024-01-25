/* cpp is a type safe language */
#include <iostream>
int main()
{
	int val; //local variable
	
	std::cin >> val;  // istream >> int 
			  // this automatically expects int from istream
	std::cout << val;
	return 0;
}

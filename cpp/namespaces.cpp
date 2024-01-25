/* program to understand name spaces in cpp */

#include <iostream>
int mul(int a, int b);
namespace venu
{
    int add(int a, int b)
    {

        return a + b;
    }

    int count = 100;
    std::string name = "venus_namespace";
    int mul(int a,int b);
}

namespace gopal
{

    float add(float a, float b)
    {
        return a + b;
    }

    std::string name = "venus_float_namespace";
}
using namespace gopal; //using directive allows usage of all identifiers inside this namespace

using venu::add; //using onlyadd function from venu namespace
// using Declaration allows us to use only add function from that namespace

int sub(int a,int b)
{
    return a-b;
}

int main()
{
    std::cout << venu::add(3,2); //the add function is defined under name space venu to invoke it we use ::
    std::cout << "count: " << venu::count << std::endl;
    std::cout << "mul: "<< venu::mul(3,2) << std::endl;
  //  std::cout << venu::name << std::endl;
    //std::cout << gopal::name;
    std::cout << mul(3,2);
    std::cout << name;
    return 0;
}
int mul(int a, int b)
{

    return a * b;
}
#include <iostream>
#include "myheader.h"

bool Student::__init__db(int age, string name)
{
    if(name.length() < 1)
        return false;
    name = name;
    age = age;
    return true;
}

int main()
{
    Student s1;
    s1.__init__db(23, "VenuGopal");
    cin >> s1.roll;
    cout << s1.roll;

    cout << "sizeof class s1: " << sizeof(Student);
    s1.__init__db(24,"hello");

}
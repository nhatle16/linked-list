#include <iostream>
using namespace std;

enum numbers {first = 1, second = 2, third = 7, fourth , fifth};
int main()
{
numbers num;
num = third;
cout << "Numbers: " << num + 2 << " ";
return 0;
}
/*
https://www.geeksforgeeks.org/for-every-set-bit-of-a-number-toggle-bits-of-other/
*/

#include <iostream>

using namespace std;

void togglebit(int X, int Y)
{
    X |= (1 << (Y-1));
    cout<<(X)<<endl;
}

int main() {
	togglebit(5,2);
	togglebit(3,1);
	return 0;
}

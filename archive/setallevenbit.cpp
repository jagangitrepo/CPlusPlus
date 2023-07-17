#include <iostream>

using namespace std;

void showbits(int n)
{
    for(int i=(sizeof(int)*8)-1; i>=0; i--)
    {
        cout<<((n&(1<<i))?"1":"0")<< " ";
    }
    cout<<endl;
}

void toggleevenbit(int n)
{
    for(int i=1; i<(sizeof(int)); i+=2)
    {
        n ^= (1 << i);
    }
    cout<<n<<endl;
    showbits(n);
}

int main() {
	toggleevenbit(20);
	toggleevenbit(30);
	return 0;
}


/*
Output:
30
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 0 
20
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 
*/

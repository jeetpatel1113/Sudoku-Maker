#include <iostream>
using namespace std;
int lb2(int x)
{
    int result = 0;
    while (x>1)
    {
        x/=2;
        result++;
    }
    return result;
}

int main()
{
    cout << lb2(8) << endl;
    cout << lb2(16) << endl;
    cout << lb2(1023) << endl;
    return 0;
}
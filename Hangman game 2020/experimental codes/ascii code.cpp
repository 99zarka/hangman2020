#include <iostream>
using namespace std;

int main()
{
    for(int i=0;i<300;i++)
    {
        cout<<"ascii code number "<<i<<": "<<(char)i<<endl;
        cout<<(char)i<<(char)i<<endl;
        cout<<(char)i<<(char)i<<endl<<endl;
    }
    return 0;
}


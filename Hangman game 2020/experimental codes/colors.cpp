#include <iostream>
#include <windows.h>

using namespace std;



void color(int y);


int main()
{
    for(int i=0;i<300;i++)
    {
        color(7);
        cout<<"color number "<<i<<" is: ";
        color(i);
        cout<<"shit shat shot"<<endl<<endl;
    }
    color(7);
    system("pause");
    return 0;
}

 void color(int y)
 {
   HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(out, y);
 }

#include <iostream>
#include <string>
#include <stdlib.h> //rand() and srand() functions to get a random number
#include <ctime>
#include <fstream>

using namespace std;

int main()
{

    ifstream in;
    string array[200];
    int i=0;

    in.open("Animals & countries.txt");

    while(in)
    {
       getline(in,array[i]);
       i++;
    }
    in.close();
    for(i=0;i<60;i++)cout<<array[i]<<endl;
    return 0;
}

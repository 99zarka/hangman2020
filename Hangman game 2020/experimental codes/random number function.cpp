#include <stdlib.h>
#include <ctime>
#include <iostream>
using namespace std;

unsigned int get_random_num(int minimum=0, int maximum=INT_MAX-1)
{
maximum++; //so the maximum value would be included
time_t nTime;
static bool first=1; //the value of "first" doesn't change or reset when the function is called again.
if(first)srand((unsigned) time(&nTime)); //prevents the code from reseeding. reseeding make the random function less reliable.
first=0;
return minimum + (rand() % (maximum-minimum));
}

int main ()
{
    for(int i =0;i<500;i++)cout<<get_random_num(0,1000)<<endl;

return(0);
}

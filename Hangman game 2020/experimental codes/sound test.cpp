#include <iostream>
#include <string>
#include <stdlib.h> //rand() and srand() functions to get a random number
#include <ctime>
#include <cmath>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

int main()
{


    string a1="Alarm01.wav";

PlaySound(TEXT("Lose.wav"), NULL, SND_FILENAME | SND_ASYNC);
Sleep(1000);
PlaySound(TEXT("Alarm01.wav"), NULL, SND_FILENAME | SND_ASYNC);


    int test = 0;

    cin>>test;
    PlaySound(NULL, 0, 0); //The following example stops playback of a sound that is playing asynchronously:
    cin>>test;

//https://docs.microsoft.com/en-us/previous-versions//dd743680(v=vs.85)?redirectedfrom=MSDN
//http://www.cplusplus.com/forum/beginner/70856/

/*
You enter:
-lwinmm

in compiler options -> "add these commands to the linker command line"
*/

return 0;
}


#include <iostream>
#include <string>
#include <stdlib.h> //rand() and srand() functions to get a random number
#include <ctime> //important to get a random number, because we use time as a seed
#include <fstream>


using namespace std;

//________________________________FUNCTIONS PROTOTYPE_______________________________________________________________________

void import_from_file(string array[],char file[]);
unsigned int get_random_num(int minimum, int maximum);
int getindex(char t);
int num_of_guessed_chars(bool a[],int a_size);
char hint_func(string selected_word, bool did_you_guess_it[]);

int choose_difficulty();
char input_alphabitical_char(bool is_this_letter_used[]);

void print_word(string selected_word,bool did_you_guess_it[]);
void intro();
int main()
//===========================================================================================================================
{
    intro();
    bool newgame=1;
while(newgame)
{
//________________________________DECLARATIONS & GAME INITIALIZATION_______________________________________________________________________

    int difficulty=choose_difficulty();
    int lives=10-2*difficulty;  //a mathematical equation that calculates lives according to difficulty
    //according to difficulty, easy= 8, normal= 6, hard= 4 lives
    int set_start=20*difficulty-20; //a mathematical equation that determines the start of the set of the words you have chosen
    //according to difficulty, the words are divided into 1-20 easy, 20-40 normal, 40-60 hard
    int HINTS=4-difficulty; //a mathematical equation that determines the numbers of hints depending on the difficulty the player has used;

    string words[200];
    import_from_file(words,"Animals & countries.txt");
    string selected_word=words[get_random_num(set_start,set_start+19)];
    for(int i=0;i<selected_word.size();i++)selected_word[i]=toupper(selected_word[i]);//converts the whole word to uppercase form

    bool did_you_guess_it[100]={0}, is_this_letter_used[26]={0};
    for(int i=0;i<selected_word.size();i++)if(selected_word[i]==' ')did_you_guess_it[i]=1; //The spaces are given to the player, guessing them isn't needed

    char current_char;
    int previous_counter=0,current_counter=1;
    bool you_win=0, on=1;
//________________________________GAMEPLAY________________________________________________________________________
    while(on)
    {
        print_word(selected_word,did_you_guess_it);
        if(current_counter==previous_counter)cout<<"\n\nyou guessed wrong.";
        cout<<"\n\nyou have "<<lives<<" lives left. Remember, you still have "<<HINTS<<" hints, enter '1' to use them or '0' to surrender\n";
        previous_counter=num_of_guessed_chars(did_you_guess_it,selected_word.size()); //counts how many characters are guessed right before giving input.
        current_char=input_alphabitical_char(is_this_letter_used);

        while(current_char=='1') //Hint escape code
        {
            if(HINTS>0)
            {
                HINTS--;
                current_char=hint_func(selected_word,did_you_guess_it);
            }
            else
            {
                cout<<"\nYou ran out of hints\n";
                current_char=input_alphabitical_char(is_this_letter_used);
            }
        }
        if(current_char=='0'){lives=0;break;} //escape code to exit the game
        is_this_letter_used[getindex(current_char)]=1; //Mark the current character as used, so you won't be able to enter it again.
        for(int i=0;i<selected_word.size();i++)if(current_char==selected_word[i])did_you_guess_it[i]=1; //Mark the letter as guessed, so the letter will be printed.
        current_counter=num_of_guessed_chars(did_you_guess_it,selected_word.size()); //counts how many characters are guessed right after giving input
        if(current_counter==previous_counter)lives--;
        if(lives==0)on=0;
        if(current_counter==selected_word.size())
        {
            on=0;
            you_win=1;
        }

    }
//________________________________GAME OVER (POST-GAME)________________________________________________________________________

    for(int i=0;i<selected_word.size();i++)did_you_guess_it[i]=1; //we well mark all letters as guessed, so the loser will be able to see the word
    print_word(selected_word,did_you_guess_it);
    if(you_win){cout<<"\n\n\tYOU WIN\n";}
    else {cout<<"\n\n\tYOU LOSE\n";}

    string str99;
    cout<<"\n\nif you want to start a new game, enter 'N'\n";
    cin>>str99;
    str99[0]=toupper(str99[0]);
    newgame=0;
    if(str99=="N"){newgame=1;}
}
    return 0;
}
//==============================================================================================
//________________________________PROCESSING FUNCTIONS__________________________________________
void import_from_file(string array[],char file[])
{
    int i=0;
    ifstream in;
    in.open(file);
    while(in)getline(in,array[i++]);
    in.close();
}

unsigned int get_random_num(int minimum, int maximum)
{
maximum++; //so the maximum value would be included
time_t nTime;
static bool first=1; //the value of "first" doesn't change or reset when the function is called again.
if(first)srand((unsigned) time(&nTime)); //prevents the code from reseeding. reseeding make the random function less reliable.
first=0;
return minimum + (rand() % (maximum-minimum));
}

int getindex(char t)
{
    t=toupper(t);
    int u=t-65;
    return u;
}
int num_of_guessed_chars(bool a[],int a_size)
{
    int counter=0;
    for(int i=0;i<a_size;i++)if(a[i])counter++;
    return counter;
}

char hint_func(string selected_word, bool did_you_guess_it[])
{
    int hint;
    while(1)
    {
        hint=get_random_num(0,selected_word.size()-1);
        if(!did_you_guess_it[hint])break;
    }
    return selected_word[hint];
}
//________________________________INPUT FUNCTIONS__________________________________________

int choose_difficulty()
{
    cout<<"\nChoose the game difficulty\nKeep in mind:\n";
    cout<<"\t\t - Hard: means even lives and really short hard words\n";
    cout<<"\n\nHow difficult would you like the game?\n"<<endl;
    cout<<"\t1- Easy   = 8 lives  + 3 hints (enter 1)\n";
    cout<<"\t2- Normal = 6 lives  + 2 hints (enter 2)\n";
    cout<<"\t3- Hard   = 4 lives  + 1 hint  (enter 3)\n";
    cout<<"\nEnter your choice: ";
    short int dif;
    cin>>dif;
    while (dif>3||dif<1||!cin)
    {
        cin.clear();
        cin.ignore();
        cout<<"enter 1, 2 or 3 only";
        cout<<"\nEnter your choice: ";
        cin>>dif;
    }
    return dif;
}

char input_alphabitical_char(bool is_this_letter_used[])
{
    cout<<"\nEnter a character: ";
    string str;
    cin>>str;
    if(str=="0")return '0';
    if(str=="1")return '1';
    while(str.size()!=1 || !isalpha(str[0]) || is_this_letter_used[getindex(str[0])])
    {
        if(str.size()!=1)cout<<"\nYou have entered more than a letter, please enter only one English letter.\n";
        else if(!isalpha(str[0]))cout<<"\nYou have entered an invalid value, please enter only one English letter.\n";
        else if(is_this_letter_used[getindex(str[0])])cout<<"\nYou have used this letter before, try again.\n";
        cout<<"\nEnter a character: ";
        cin>>str;
        if(str=="0")return '0';
        if(str=="1")return '1';
    }
    str[0]=toupper(str[0]);
    return str[0];
}
//________________________________ARTISTIC STUFF__________________________________________

void print_word(string selected_word,bool did_you_guess_it[])
{
    cout<<"\t\t\t\t";
    for(int i=0;i<selected_word.size();i++)
    {
        if(did_you_guess_it[i])cout<<selected_word[i]<<" ";
        else cout<<"_ ";
    }
}
void intro()
{
string rules[100];
import_from_file(rules,"rules.txt");
cout<<"How to play?"<<endl<<endl;
for(int i=0;i<15;i++)cout<<"\t"<<rules[i]<<endl;
}

#include <iostream>
#include <string>


using namespace std;


int getindex(char t)
{
    int u=t-65;
    return u;
}

int num_of_guessed_chars(bool a[],int a_size)
{
    int counter=0;
    for(int i=0;i<a_size;i++)if(a[i])counter++;
    return counter;
}
int main()
{

    string selected_word="SOUDI ARABIA";
    bool did_you_guess_it[100]={0};
    for(int i=0;i<selected_word.size();i++)if(selected_word[i]==' ')did_you_guess_it[i]=1; //The spaces are given to the player
    bool is_this_letter_used[26]={0};
    char current_char;

    while(1)
    {
        for(int i=0;i<selected_word.size();i++)
        {
            cout<<did_you_guess_it[i]<<" ";
        }
        cout<<"="<<num_of_guessed_chars(did_you_guess_it,selected_word.size());

        cout<<endl;

        for(int i=0;i<selected_word.size();i++)
        {
            if(did_you_guess_it[i])cout<<selected_word[i]<<" ";
            else cout<<"_ ";
        }

        cout<<endl<<endl<<endl;

        for(int i=0;i<26;i++)
        {
            cout<<(char)('A'+i)<<" ";
        }
        cout<<endl;
        for(int i=0;i<26;i++)
        {
            cout<<is_this_letter_used[i]<<" ";
        }
        cout<<endl<<"______________________________________________________________";
        cout<<"\n\nenter a character: ";
        cin>>current_char;
        current_char=toupper(current_char);
        if(is_this_letter_used[getindex(current_char)])
        {
            cout<<"You have used this character before, enter a new letter"<<endl;
            continue;
        }
        is_this_letter_used[getindex(current_char)]=1;

        for(int i=0;i<selected_word.size();i++)if(current_char==selected_word[i])did_you_guess_it[i]=1;

    }


    return 0;
}

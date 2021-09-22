#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

void printwithdelay(string str);                   //printing string with delay between letters delay(100 ms).
void printwithdelay1(string str);                   //printing string with delay between letters delay(100 ms).
int select_lvl();                                  // use to set difficulty level takes input from user and returns to main
int no_of_chances(int lvl);                         //depending on level it sets guess count
void initial_view();                                // shows game Name and all parameters of game
void play(int choice);                              //game is played here

void printwithdelay(string str)
{
    for(auto i: str)
    {
        cout<<i;
        Sleep(100);
    }

    cout<<endl;
}

void printwithdelay1(string str)
{
    for(auto i: str)
    {
        cout<<i;
        Sleep(10);
    }
}

int select_lvl()
{
    static int lvl;

    cout<<"          ";
    printwithdelay("Select '1' for Hard level ( Here You Will Get Three Chances to Guess a Number )");
    cout<<endl;
    Sleep(200);

    cout<<"          ";
    printwithdelay("Select '2' for Medium level ( Here You Will Get Five Chances to Guess a Number )");
    cout<<endl;
    Sleep(200);

    cout<<"          ";
    printwithdelay("Select '3' for Easy level ( Here You Will Get Seven Chances to Guess a Number )");
    cout<<endl;
    Sleep(600);

    cout<<" Your Choice is  :- ";
    cin>>lvl;
    cout<<endl;

    if(lvl!=1 && lvl!=2 && lvl!=3)
    {
        char default_ch;
        cout<<"               You have selected wrong choice if You Want Play again Press 'Y' "<<endl<<endl;
        cout<<" Your Character Choice is  :- ";
        cin>>default_ch;
        cout<<endl;
        if(default_ch=='Y')
            lvl=select_lvl();
        else
            return -1;
    }
    return lvl;
}

int no_of_chances(int lvl)
{
    int chance;
    switch(lvl)
    {
        case 1 :chance=3;
        break;

        case 2 :chance=5;
        break;

        case 3: chance=7;
        break;
    }
    return chance;
}

void initial_view()
{
    static int repeat=0;
    if(repeat==0)
    {
        repeat++;
        cout<<"                                         ";
        printwithdelay("Welcome To Number Guessing Game");
        cout<<endl;
        Sleep(1200);
    }

    cout<<"          ";
    printwithdelay("Choose difficulty Level");
    cout<<endl;
    Sleep(1200);

}

void play(int chance)
{
    int mn=1,mx=100;

    int computer_guess,user_guess,guess_count=0;
    srand(0);
    computer_guess=mn+rand()%(mx-mn+1);                                         //generate random number using rand() function

    cout<<"                         ";
    cout<<" You Have To Guess a number between "<<mn<<" and "<<mx<<" in "<<chance<<" guesses "<<endl;

    while(chance>0)
    {
        cout<<" Enter Your guess "<<endl;
        cout<<" Your guess is :- ";
        cin>>user_guess;
        guess_count++;

        if(computer_guess==user_guess)
        {
            cout<<endl<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            printwithdelay1(" Congratulations 'YOU WIN' the game in ");
            cout<<guess_count<<" guesses "<<endl;
            return ;
        }
        else if(computer_guess>user_guess)
        {
            cout<<" you guess small Number "<<endl;
        }
        else
        {
            cout<<" you guess big Number "<<endl;
        }
        chance--;
    }
    cout<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    printwithdelay1("Sorry 'YOU LOSE', Answer is ");
    cout<<computer_guess<<endl;
    cout<<"                         Better Luck Next Time"<<endl;

    return;
}

int main()
{
    system("Color 0A");
    char play_ch;

    do
    {
        initial_view();
        int lvl;
        lvl=select_lvl();

        if(lvl==-1)
            return 0;

        cout<<endl;

        int chance=no_of_chances(lvl);

        play(chance);

        cout<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
        Sleep(2500);
        cout << "\033[2J\033[1;1H";                     //it clears screen

        cout<<" Do You Want To Play Again Press 'Y' else Press Any Key "<<endl;
        cout<<"                ";
        cin>>play_ch;

        cout << "\033[2J\033[1;1H";

    }while(play_ch=='Y');

    return 0;
}

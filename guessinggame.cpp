
Evelyne Mwende <evelynemwende8@gmail.com>
Mon, Jul 22, 2019, 11:54 AM
to Mwendekamau04

#include <iostream>
#include <time.h>
#include<cstdlib>
#include<fstream>

using namespace std;
    string name;
    int mistakes = 0;
    int correctguesses=0;
    int prevnum = 3;
    int nextnum;
    char choice;
    int random= rand();


 void user()
{
cout<<"What is your name ?"<<endl;
cin>>name;

}
void intro()
{
    cout << "Welcome to the number guessing game. Each time a random number will be generated from 0-20." << endl<<endl;
    cout << "The aim of the game is to guess whether the next number will be higher or lower. " << endl<<endl;
    cout << "You can make no more than 3 mistakes before you lose." << endl << endl;
    cout << "The fisrt number is 3. Will the next number higher(write H-uppercase) or lower(write L-uppercase) ?" <<endl<<endl;
}

void code()
{


    do
    {
        srand ( time(NULL) );
        do
            nextnum = rand() % 21;
        while (nextnum == prevnum);

        cout<<"KEY IN CHOICE";
        cin >> choice;

        if (choice == 'H')
        {
            if (prevnum < nextnum)
            {
                cout << "Correct ! The new number is " << nextnum << endl;
                correctguesses++;
            }
            else if (prevnum > nextnum)
            {
                cout << "Wrong!! The new number is " << nextnum << endl;
                mistakes++;
            }
        }

        if (choice == 'L')
        {
            if (prevnum > nextnum)
            {
                cout << "Correct ! The new number is " << nextnum << endl;
                correctguesses++;
            }
            else if (prevnum < nextnum)
            {
                cout << "Wrong, you made a mistake ! The new number is " << nextnum << endl;
                mistakes++;
            }
        }


    }
    while(mistakes < 3);

    cout << "You made 3 mistakes ! Game over!!!!!!" << endl;
    cout << "You had " << correctguesses << " correct guesses before you lost" << endl;
}
void scoresheet()
{

    ofstream save("scoreshee.xls" , ios::app);
    save<<name<<"\t"<<correctguesses<<endl;
    save.close();

}

void retrieve()
{
ifstream read("scoreshee.xls");
cout<<"Name\tCorrectguesses"<<endl;
while(read>>name>>correctguesses)
cout<<name<<"\t"<<correctguesses<<endl;
read.close();
}
int main()
{

user();
intro();
code();
scoresheet();
retrieve();

    return 0;
}

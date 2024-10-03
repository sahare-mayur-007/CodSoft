#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    srand(time(0));
    int numberToGuess = rand() % 100 + 1; //Random number guessing from 1-100
    int guess;

    cout << "Guess the number (between 1 and 100):" << endl;

    while (true) 
    {
        cin >> guess;

        if (guess < numberToGuess) 
        {
            cout << "Too low! Try again." << std::endl;
        } 
        else if (guess > numberToGuess) 
        {
            cout << "Too high! Try again." << std::endl;
        } 
        else 
        {
            cout << "Congratulations! You guessed the number." << endl;
            break;
        }
    }

    return 0;
}

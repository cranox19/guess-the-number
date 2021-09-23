// GuessTheNumberProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Included Libraries
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    //-----------------------------------------------------------------
    // Print to the console to set up the game
    //-----------------------------------------------------------------

    std::cout << "Guess The Number Game \n";
    std::cout << "By Ethan Paterson \n";
    std::cout << "\n";
    std::cout << "Try to guess the random number in the fewest guesses. \n";
    std::cout << "\n";

    //-----------------------------------------------------------------
    // Restarting the game
    //-----------------------------------------------------------------

    // Declare and initialise the variables
    std::string restartResponse = "yes";

    // Play the game again if the correct response is entered
    while (restartResponse == "yes")
    {

        //-----------------------------------------------------------------
        // Generate a random number between 1 and x
        //-----------------------------------------------------------------

        // Initialise the seed random function
        srand(time(NULL));

        // Declare and initialise the variables
        int numberRange = 0;

        // Set the range of values to the player's input
        std::cout << "What would you like the maximum value to be? \n";
        std::cin >> numberRange;

        // Generate a random number within the given range
        int randomNumber = std::rand() % numberRange;

        //-----------------------------------------------------------------
        // Code for the guessing section
        //-----------------------------------------------------------------

        // Declare and initialise the variables
        int guess = 0;
        int attempts = 0;
        int attemptsRemaining = 5;

        // Loop until the player has guessed correctly
        while (guess != randomNumber)
        {
            if (attempts < 5)
            {
                std::cout << "Please guess a number between 1 and " << numberRange << ". You have " << attemptsRemaining << " attempts remaining \n";

                std::cin >> guess;

                std::cout << "\n";

                // Increase attempts by 1
                attempts++;

                // Decrease attemptsRemaining by 1
                attemptsRemaining--;

                // If the player is correct
                if (guess == randomNumber)
                {
                    std::cout << "You have guessed correctly! \n";
                    std::cout << "\n";

                    std::cout << "You guessed correctly in " << attempts << " attempts. \n";
                    std::cout << "\n";

                    std::cout << "Would you like to play again? Please enter - yes - to restart. \n";
                    std::cout << "\n";

                    std::cin >> restartResponse;
                }
                // If the player is incorrect
                else
                {
                    std::cout << "You have guessed incorrectly! \n";
                    std::cout << "\n";

                    //--attemptsRemaining;

                    // If the guess was too high
                    if (guess > randomNumber)
                    {
                        std::cout << "Your guess was too high \n";
                    }
                    // If the guess was too low
                    else
                    {
                        std::cout << "Your guess was too low \n";
                    }
                }
            }
            else
            {
                std::cout << "You have run out of guesses. \n";
                std::cout << "\n";

                std::cout << "Would you like to play again? Please enter - yes - to restart. \n";
                std::cout << "\n";

                std::cin >> restartResponse;
            }
        }
    }

    // End the game
    return 0;
}


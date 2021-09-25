#include <iostream>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <vector>
#include  <string>

using namespace std;

int main()
{

	const int wrong_guess = 10;

	//creating a vector of string with the name secrets.
	vector<string>secrets;
	//assigning all the 10 words into the vector via the push back method
	secrets.push_back("UAT");
	secrets.push_back("Germany");
	secrets.push_back("CIA");
	secrets.push_back("NSA");
	secrets.push_back("SECURITY");
	secrets.push_back("PROGRAM");
	secrets.push_back("CHASE");
	secrets.push_back("KEY");
	secrets.push_back("WORD");
	secrets.push_back("SIMULATION");


	string userName;//Show recruit the letters he or she has guessed
	char again = 'y';//play again


	cout << "Login: ";
	//assigning the user input to username
	cin >> userName;
	cout << "Welcome Recruit " << userName << "to your training exercise!" << endl;
	cout << "Your Job is it to decode words correctly! Try your best!" << endl << endl;


	do {
		for (int i = 1; i < 4; i++)
		{
			cout << userName << " Get ready for round#: " << i << endl;// Display the simulation # is staring to the recruit. 

			//Increment the number of simulations ran counter
			srand(static_cast<unsigned int>(time(0)));//seeding the random function
			random_shuffle(secrets.begin(), secrets.end()); //shuffeling the vector secrets

			const string THE_WORD = secrets[0];//word to guess
			int wrong = 0;//number of incorrect guesses
			string alreadyGuess(THE_WORD.size(), '_');//word guessed so far
			string used = ""; // letters already used


			//while loop that contains the main game
			while ((wrong < wrong_guess) && (alreadyGuess != THE_WORD))
			{
				cout << userName << " You have " << (wrong_guess - wrong) << " guesses left!" << endl;
				cout << "You have used the following letters: " << used << endl;
				cout << "Current Word: " << alreadyGuess << endl;

				//empty char Variable
				char guess;
				cout << "Enter Guess: ";
				//assigning user input to char variable
				cin >> guess;
				//changing the input to upperCase to make it easier to find the words
				guess = toupper(guess);

				//Shows already guessed letters
				while (used.find(guess) != string::npos)
				{
					cout << userName << " you have already guessed that!!!! " << guess << endl;
					cout << "Enter your guess Again: ";
					cin >> guess;
					guess = toupper(guess);
					system("CLS");
				}

				used += guess;
				//if statement checks if the guess is equal to the letter of the word selected
				if (THE_WORD.find(guess) != string::npos)
				{
					cout << "Your guess is correct:  " << guess << " is in the word.\n";
					for (int i = 0; i < THE_WORD.length(); ++i)
					{

						if (THE_WORD[i] == guess)
						{
							//Displays already guess letters
							alreadyGuess[i] = guess;
						}
					}
				}
				else
				{
					cout << "sorry, " << guess << " is not right.\n";
					++wrong;
				}
			}
			//Removes a point
			if (wrong == wrong_guess)
			{

				cout << "Wrong Guess!" << endl;

			}
			else {

				cout << "Correct guess!" << endl;
			}


			//Displays the correct word at the end.
			cout << "The word was " << THE_WORD << endl;
			//Basic system pause to pause the program.
			system("pause");

		}
		//Game Loop
		cout << "Would you like to play again (y/n)?" << endl;
		//Assigning user input to again variable.
		cin >> again;
		//while loop comes true if the user inputs y 
	} while (again == 'y');
	//Thanks the player for playing if the user does not want to play again.
	cout << "Thank you for playing" << endl;
	system("pause");
	return 0;
}
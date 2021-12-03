#include <vector>
#include <string>
#include <iostream>



bool restart_game = true;

class Game
{
	std::vector<std::string> words{
		"bird",
		"parrot",
		"chicken",
		"crow",
		"pigeon",
		"turkey",
		"duck",
		"goose",
		"ostrich",
		"animal",
		"cow",
		"bull",
		"horse",
		"pig",
		"wolf",
		"rat",
		"cat",
		"tiger",
		"lion",
		"zebra",
		"elephant",
		"panda",
		"monkey",
		"bear",
		"fox",
		"raccoon",
		"lizard",
		"snake",
		"dragon",
		"axolotl",
		"snail",
		"insect",
		"beetle",
		"bee",
		"fish",
		"shark",
		"whale",
		"bass",
		"crab",
		"shrimp"
	};
	std::string game_word, temp, letter_temp;
	char letter;
	bool is_right = false, game_win = false;
	int game_counter = 6;

public:

	Game()
	{
	}

	void start()
	{
		bool game_start = true;
		int random = rand() % 40;
		game_word = words[random];
		letter_temp += '&';


		temp.resize(game_word.size());
		for (int i = 0; i < temp.size(); i++)
		{
			temp[i] = '_';
		}

		while (!game_win && !game_counter == 0)
		{
			for (int i = 0; game_word[i]; i++)
			{
				if (letter == game_word[i] || letter == game_word[i] + 32) 
				{
					temp[i] = game_word[i];
					is_right = true;
				}
			}
			if (game_word == temp)
			{
				game_win = true;
				break;
			}
			system("cls");
			std::cout << "Welcome to game! \nWord - ";

			for (int i = 0; i < temp.size(); i++)
			{
				std::cout << temp[i] << " ";
			}


			if (!game_start)
			{

				for (int i = 1; i <= letter_temp.size(); i++)
				{
					if (letter == letter_temp[i])
					{
						std::cout << "\nU find this letter already!\n";
						is_right = false;
						break;

					}
					else
					{

						if (i == letter_temp.size()) 
						{

							if (is_right)
							{
								std::cout << "\nThat`s correct!\n";
								letter_temp += letter;
								letter_temp += (letter - 32);
								is_right = false;
								break;
							}
							else
							{
								std::cout << "\nIncorecct:c\n";
								game_counter--;
								std::cout << "U have " << game_counter << " attempts\n";
								break;

							}
						}
					}

				}
				if (game_counter == 0)
					break;
			}

			std::cout << "\nGuess the letter:";
			std::cin >> letter;

			game_start = false; 
		}


		if (game_win)
		{
			system("cls");
			std::cout << "Word - ";
			for (int i = 0; i < temp.size(); i++) 
			{
				std::cout << temp[i] << " ";
			}

			std::cout << "\nWin!\n";
		}
		else
		{
			system("cls");
			std::cout << "Word - ";
			for (int i = 0; i < game_word.size(); i++)
			{
				std::cout << game_word[i] << " ";
			}

			std::cout << "\nLose!\n";
		}

		char restart;

		std::cout << "Want more?(Y/N)";

		std::cin >> restart;
		if (restart == 'N' || restart == 'n') { restart_game = false; }
	}

};


int main()
{
	srand(time(0));

	do
	{
		Game s;
		s.start();
	} while (restart_game);

	return 0;

}
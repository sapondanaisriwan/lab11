#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string cardNames[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
int cardScores[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

int drawCard(void)
{
	return rand() % 13 + 1;
}

int calScore(int x, int y, int z)
{
	if (x >= 11)
	{
		x = 10;
	}
	if (y >= 11)
	{
		y = 10;
	}
	if (z >= 11)
	{
		z = 10;
	}

	return (x + y + z) % 10;
}

int findYugiAction(int s)
{
	if (s == 9)
		return 2; // Yugi will definitely stay (2) when current score (s) is equal to 9
	else if (s < 6)
		return 1; // Yugi will definitely draw (1) when current score (s) is less than 6
	else
	{
		int randNum = rand() % 100 + 1;
		if (randNum <= 69)
			return 1;
	}
	return 2;
}

void checkWinner(int p, int y)
{
	string result = "";
	if (p > y)
	{
		result = "|         Player wins!!!        |";
	}
	else if (y > p)
	{
		result = "|          Yugi wins!!!         |";
	}
	else
	{
		result = "|             Draw!!!           |"; // when p is equal to y
	}

	cout << "\n---------------------------------\n";
	cout << result; // when p is equal to y
	cout << "\n---------------------------------\n";
}

int main()
{
	srand(time(0)); // This line of code is not completed. Fill the correct input of srand();

	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0}; // This line of code is not completed. You need to initialize value of yugiCards[].

	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0], playerCards[1], playerCards[2]);
	cout << "Your score: " << playerScore << "\n";

	while (true)
	{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
		if (playerAction == 1)
			break;
		else if (playerAction == 2)
			break;
	}
	if (playerAction == 1)
	{
		// The following lines of code are not completed. Please correct it.
		playerCards[2] = drawCard();
		playerScore = calScore(playerCards[0], playerCards[1], playerCards[2]);
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " << cardNames[playerCards[2]] << "\n";
		cout << "Your new score: " << playerScore << "\n";
	}
	cout << "------------ Turn end -------------------\n\n";

	// The following lines of code for Yugi's turn are not completed. Please correct it.
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(yugiCards[0], yugiCards[1], yugiCards[2]);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if (yugiAction == 1)
	{
		cout << "Yugi draws the 3rd card!!!\n";
		yugiCards[2] = drawCard();
		yugiScore = calScore(yugiCards[0], yugiCards[1], yugiCards[2]);
		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]] << "\n";
		cout << "Yugi's new score: " << yugiScore << "\n";
	}
	cout << "------------ Turn end -------------------\n";

	checkWinner(playerScore, yugiScore);
}

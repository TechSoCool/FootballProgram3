// Name: Sterling Gerard
// Objective: Write a program that declares a struct to store the data of a football
// player (player's name, player's position, number of touchdowns
// number of catches, number of passing yards, number of receiving yards,
// and the number of rushing yards). 
// March 13, 2022
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int row = 10;
ifstream inputFile;
// create a struct of football player
struct footPlayerInformation
{
	string name,
		position;
	int touchdown,
		catches;
	double passingYards,
		receivingYards,
		rushingYards;
};

void displayData(footPlayerInformation playerStats[row]);
void menu(footPlayerInformation playerStats[row]);

// read Data of football Player Information
void readData(footPlayerInformation playerStats[row])
{
	inputFile.open("footballplayerInfo.txt");
	for (int r = 0; r < row; r++)
	{
		inputFile >> playerStats[r].name;
		inputFile >> playerStats[r].position;
		inputFile >> playerStats[r].touchdown;
		inputFile >> playerStats[r].catches;
		inputFile >> playerStats[r].passingYards;
		inputFile >> playerStats[r].receivingYards;
		inputFile >> playerStats[r].rushingYards;

	}
}

// display Data of football Information
void displayData(footPlayerInformation playerStats[row])
{
	cout << setw(5) << "Name" << setw(8) << "Pos" << setw(9) << "TD" << setw(11) << "Passing Yards" << setw(19) << "Receiving Yards" << setw(14) << "Rushing Yards" << endl;
	for (int r = 0; r < row; r++)
	{
		cout << playerStats[r].name << setw(8) << playerStats[r].position << setw(10) << playerStats[r].touchdown
			<< setw(10) << playerStats[r].receivingYards << setw(13) << playerStats[r].rushingYards << endl;
	}
	cout << "\n\n";
	menu(playerStats);
}

// search for football player Information 
void searchForPlayer(footPlayerInformation playerStats[row])
{
	string InputName;
	cout << "Enter  the name of the player your searching for to see their stats: " << endl;
	cin >> InputName;
	bool found = false; // flag to indicate if the value was found 
	int index = 0; // used as a subscript to search array
	int position = -1; // To record position of search value 

	while (index < row && !found)// while to test the see if the condition is true the proceed with the following steps
	{
		if (playerStats[index].name == InputName) // If the value in found
		{
			found = true; // Set the flag 
			position = index; // Record the value's subscript
		}
		index++; // Go to the max element 
	}
	if (position != -1)
	{
		cout << "\n" << InputName << " is located in Index number " << position << endl;
		cout << "\nHere are " << InputName << "is stats: " << endl;
		cout << setw(5) << "Name" << setw(8) << "Pos" << setw(9) << "TD" << setw(12) << "Catches" << setw(11) << "Passing Yards" << setw(10) << "Rushing Yards" << endl;
		cout << playerStats[position].name << setw(6) << playerStats[position].position << setw(10) << playerStats[position].touchdown
			<< setw(10) << playerStats[position].catches << setw(10) << playerStats[position].passingYards
			<< setw(10) << playerStats[position].receivingYards << setw(13) << playerStats[position].rushingYards << endl;
	}
	else
	{
		cout << InputName << " is not found in the array " << endl;
	}
	cout << "\n\n";
	menu(playerStats);
}

// update the football player Information
void updatePlayerInfo(footPlayerInformation playerStats[row])
{
	string InputName;
	cout << "Which player stats would you like to update? \n ";
	cin >> InputName;
	int position = -1;
	string PlayerInfoChange;


	for (int r = 0; r < row; r++)
	{
		if (playerStats[r].name == InputName)
			cout << "\n" << InputName << "is stats: \n" << endl;
		cout << setw(5) << "Name" << setw(8) << "Pos" << setw(9) << "Touchdowns" << setw(12) << "Catches" << setw(11) << "Passing Yards" << setw(10) << "Receiving Yards" << setw(14) << "Rushing Yards" << endl;
		cout << playerStats[r].name << setw(6) << playerStats[r].position << setw(10) << playerStats[r].touchdown
			<< setw(10) << playerStats[r].catches << setw(10) << playerStats[r].passingYards
			<< setw(10) << playerStats[r].receivingYards << setw(13) << playerStats[r].rushingYards << endl;
		cout << "\nWhich Player Information would like to change?" << endl;
		cout << "Enter either 'Name', 'Position', 'Touchdowns', 'Catches', 'Passing Yards', 'Receiving Yards', 'Rushing Yards' " << endl;
		cin >> InputName;
		//Name
		if (InputName == "Name")
		{
			cout << "Enter the New Name " << endl;
			cin >> playerStats[r].name;
		}
		//Position
		if (InputName == "Position")
		{
			cout << "Enter the Name for the new Position " << endl;
			cin >> playerStats[r].position;
		}
		//Touchdown
		if (InputName == "TouchDowns")
		{
			cout << "Enter the new number of Touchdowns" << endl;
			cin >> playerStats[r].touchdown;
		}
		//Catches
		if (InputName == "Catches")
		{
			cout << "Enter the new number of Catches" << endl;
			cin >> playerStats[r].catches;
		}
		//Passing Yards
		if (InputName == "Passing Yards")
		{
			cout << "Enter the new number of passing yards" << endl;
			cin >> playerStats[r].passingYards;
		}
		//Receiving Yards
		if (InputName == "Receiving Yards")
		{
			cout << "Enter the new amount of receiving yards" << endl;
			cin >> playerStats[r].receivingYards;
		}
		//Rushing Yards
		if (InputName == "Rushing Yards")
		{
			cout << "Enter the new amount of rushing yards" << endl;
			cin >> playerStats[r].rushingYards;
		}
		cout << "\n";
		menu(playerStats);
	}
}


void quit(footPlayerInformation playerStats[row])
{
	char userChoice;
	ofstream OutputFile;
	cout << "Would you like to save any updates? Either 'Y' for Yes, or 'N' for No." << endl;
	cin >> userChoice;
	if (userChoice == 'Y' || userChoice == 'y')
	{
		cout << "Updated information is now being saved to UpdatePlayerInformation.txt";

		OutputFile.open("UpdatePlayerInformation.txt");
		OutputFile << setw(5) << "Name" << setw(8) << "Position" << setw(9) << "Touchdowns" << setw(12) << "Catches" << setw(11) << "Passing yards" << setw(10) << "Receiving Yards" << setw(14) << "Rushing Yards" << endl;
		for (int r = 0; r < row; r++)
		{
			OutputFile << playerStats[r].name << setw(6) << playerStats[r].position << setw(10) << playerStats[r].touchdown
				<< setw(10) << playerStats[r].catches << setw(10) << playerStats[r].passingYards
				<< setw(10) << playerStats[r].receivingYards << setw(13) << playerStats[r].rushingYards << endl;
		}
	}
	else if (userChoice == 'N' || userChoice == 'n')
	{
		cout << "Updated the CHanges will be saved\n";
	}
	else
	{
		cout << "Enter either 'Y' for Yes, or 'N' for No. \n" << endl;
		cin >> userChoice;
	}
}	

// choosing different menu options 1-4
void menu(footPlayerInformation playerStats[row])
{
	int choice = 0;
	while (choice == 0)
	{
		cout << "+++++++++++++Main Menu++++++++++\n";
		cout << "1 | look up specific player info\n";
		cout << "2 | Update the player information\n";
		cout << "3 | Display all 10 players Information\n";
		cout << "4 | Quit\n";
		cout << "+++++++++++++++++++++++++++++++++++\n";
		cin >> choice;
	}
	if (choice == 1)
	{
		searchForPlayer(playerStats);
	}
	else if (choice == 2)
	{
		updatePlayerInfo(playerStats);
	}
	else if (choice == 3)
	{
		displayData(playerStats);
	}
	else
	{
		cout << "Please enter a number 1-4\n";
		cin >> choice;
	}
}
//++++++++++++++Main Program++++++++++++++++
int main()
{

	footPlayerInformation playerStats[row];
	readData(playerStats);
	menu(playerStats);


	return 0;
	system("pause");
} 
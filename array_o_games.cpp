//my array of games

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    //Create array and add 4 games
    const int MAX_GAMES = 10;
    string GAMES_LIST[MAX_GAMES] = {"Shadow of War ", "Far Cry 3 ", "Mass Effect 2 ", "Assassins Creed 3 "};
    int numGames = 4;
   
    //random game of the day

    srand(static_cast<unsigned int>(time(0)));
    int choice1 = rand() % numGames;
    cout << "\nHave you played " << GAMES_LIST[choice1] << "?\n";

  

//for loop to look for Half-Life 2
cout << "Search for a game.\n";
string search = "Half-Life 2";
cout << "Searching for Half-Life 2.\n";
for (int i = 0; i < numGames; i++) {
    if (GAMES_LIST[i] == search) {
        cout << search << " is in the list.\n";
        break;
    }
    else {
       cout << search << " is not in the list.\n";
       break;
    }
}

//Ask player about a video game to add to the list.

cout << "Would you like to add a game to the list?(y/n)\n";
char choice;
cin >> choice;
if (choice == 'y'){
    
    cout << "Enter the name of your game: \n";
    string entry;
    cin >> entry;
    
    if (numGames <= MAX_GAMES){
    GAMES_LIST[numGames++] = entry;
    cout << "Your game has been added.\n";
    }
    
    else {
        cout << "\nI'm sorry. The list is full.\n";
    }
}
else {
    cout << "\nok.\n";

    
    }
}

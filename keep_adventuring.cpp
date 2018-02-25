//Matt Drummond
//Go on another adventure!

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;

void story();
char askYesNo(string question);
int rollDie(int min, int max);
void ending();
void adventure();

int health = 50;
int totalTreasure;

int main() {
srand(static_cast<unsigned int>(time(0)));

story();

do {
    cout << "Your health is " << health << endl;
    cout << "You currently have " << totalTreasure << " gold pieces.\n"; 

    char answer = askYesNo("Do you want to keep adventuring?");

    if (answer == 'y') {
        cout << "You head into the forest\n";
        adventure();
    }
    
    else if (answer == 'n')  {
    break; 
    }
    else {
        cout << "That is not a valid answer.\n";
    }
    
    

} while (health > 0);

if (health == 0) {
         cout << "\nSadly you've perished in the forest, old Chap!\n";
    }
ending();

return 0;
}

void story() {
cout << "You open your eyes." << endl;
cout << "You're on a deserted island." << endl;
cout << "All you can see is a forest, further inland, and the sea for miles to come.\n\n"; //start the story
}

inline char askYesNo(string question) {
    char answer;
    cout << question;
    cout << "\n(y/n)";
    cin >> answer;
    return answer;
}

inline int rollDie(int min, int max) {
    int num = rand() % max + min;
    return num;
}
 
void ending() {
    cout << "\nYou earned " << totalTreasure << " gold pieces" << endl;
    cout << "\nThanks for playing!";
    }
void adventure() {
    int block = rollDie(1,5);
    int attack = rollDie(6,10);
    int addTreasure = rollDie(1,20);

    this_thread::sleep_for(chrono::milliseconds(700));

    if (attack > block) {
        health -= (attack - block);
        cout << "\n\nYou've taken damage!\n\n";
        if (health < 0) {
            health = 0;
        }

    }    
    else if (attack < block) {
        cout << "\n\nYou've defeated the enemy, and collected the treasure.\n\n";
        totalTreasure += addTreasure;
    }
}
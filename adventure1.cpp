//A superb fighting adventure complete with an imagination engine!
//By Matt Drummond

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>   //for sleep()
#include <thread>   // for sleep()
using namespace std;

int main()
{
    int health = 10, attack, block, i; //initialize variables
    i = 0;

    cout <<"Do you want to see the numbers?(y/n)\n";
    char choice;
    cin >> choice;

    if (choice == 'y')
        {
            cout << "h = health. a = attack. b = block.\n";
        }
    do //start the loop
    {
        srand(static_cast<unsigned int>(time(0)));//seed random number generator
               
        i++;
        attack = rand() % 4 + 1;
        block = rand() % 4 + 1;

       this_thread::sleep_for(chrono::milliseconds(500));
        
        //debug mode
        if (choice == 'y') {
            cout << "h = " << health << " a = " << attack << " b = " << block << " i = " << i << endl;
        }

        if (attack > block)  {
            health -= (attack - block);
            if (health < 0) {
                health = 0;
            }
        }
        

        else if (attack < block) {
            cout << "You have blocked successfully!\n";
        }

        cout << "\nYou have " << health << " health remaining\n\n";

        

    } while (health > 0 && i < rand() % 100 + 1);//to keep the number of rounds to 10 or less
    if (health > 0)
    {
        cout << "Congratulations! You have saved the castle!\n";
    switch (health)
        {
        case 1,2,3:
            cout << "\nThat was close! You should probably go see a doctor.";
            break;
        default:
            cout << "You soundly defeated the horde!";
        }        
    }

    
    else{
        cout << "\nOh dear! You're dead. And they kidnapped the princess.";
    }
    return 0;
}

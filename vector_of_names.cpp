//A user works with vector
//Matt Drummond


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

int main() {
    vector<string> names;
    //give user choice to add, change, remove, list a name or quit
    vector<string>::iterator changeIter;
    vector<string>::const_iterator readIter;
    names.push_back("Matt");
    names.push_back("Theodor");
    names.push_back("Aragorn");
    names.push_back("Robert");
    names.push_back("Constantine");

    cout << "Welcome to the name generator!\n";
    do {
        
        //give options
        cout << "\nYou have the following options: \nadd(a)\nchange(c)\nremove(r)\nlist(l)\nquit(q)" << endl;
        
        cout << "\nThe current list of names is: " << endl;
        for (readIter = names.begin(); readIter != names.end(); ++readIter) {
            cout << *readIter << endl;
        }
        
        cout << "\nWhat do you want to do?\n";
        char choice;
        cin >> choice;
        choice = tolower(choice);
        if (choice == 'a') {
            cout << "What name do you want to add?\n";
            string newName;
            cin >> newName;
            names.push_back(newName);
        }
        else if (choice == 'c') {
            for (readIter = names.begin(); readIter != names.end(); ++readIter) {
                cout << *readIter << endl;
            }
           
            cout << "\nWhat name do you want to change?\n";
            string changeName;
            cin >> changeName;
            changeIter = find(names.begin(),names.end(),changeName);
                       
            
            if (changeIter != names.end()) {
                
                names.erase(changeIter);
                cout << "\nThat name has been found. What do you want to change it to?\n" << endl;
                string diffName;
                cin >> diffName;
                names.insert(names.begin(),diffName);                
            }
            else {
                cout << "That name is not in the list.\n";
            }
        }   
        else if (choice == 'r'){
            cout << "What name do you want to remove?\n" << endl;
            
            string delName;
            cin >> delName;
                    
            changeIter = find(names.begin(),names.end(), delName);
            if (changeIter != names.end()) {
                names.erase(changeIter);
            }
            else {
                cout << "That name is not in the list." << endl;
            }
        }

        else if (choice == 'l') {
            continue;
        }         
        
        else if (choice == 'q') {
            break;
        }
        else  {
            cout << "That is not an option." << endl;
        }
    } while (true);
    return 0;
}
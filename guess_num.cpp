#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
using namespace std;

void printSlow( const string& text) {
    for(char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
}

int main() {

    printSlow("Hello!");
    printSlow("Welcome to Number guessing game!");

    this_thread::sleep_for(chrono::seconds(1));

    printSlow("Ready?");

    cout << "Y/N\n";

    string answer;
    cin >> answer;

    if(answer == "n" or answer == "N") {   
        printSlow("Bye-e!");
        this_thread::sleep_for(chrono::seconds(1));
        }
    while(true) {
        printSlow("Hmm...");
        this_thread::sleep_for(chrono::seconds(1));
        printSlow("What the minimum? ");

        int min_num;
        cin >> min_num;

        this_thread::sleep_for(chrono::seconds(2));

        printSlow("Okay! What the maximum? ");
            
        int max_num;
        cin >> max_num;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(min_num, max_num);
        int num = dist(gen);

        this_thread::sleep_for(chrono::seconds(1));

        printSlow("Kk ^^");
        printSlow("Guess the number!");

        int guess;
        cin >> guess;

        while(true) {
            if(guess < num) {
                printSlow("Too low!");
                cin >> guess;
            }else
            if(guess > num) {
                printSlow("Too high!");
                cin >> guess;
            }else
            if(guess == num) {
                printSlow("U beat me!");
                this_thread::sleep_for(chrono::seconds(1));
                break;
            }
        }    
    printSlow("Wanna another one? (Y/N)");
    cin >> answer;
    if(answer == "y" or answer == "Y") {
        printSlow("Yay! ^^");
    }
    else {
        printSlow("Bye-e!");
        break;
    }

        
    }

    return 0;
}

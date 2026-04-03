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
    printSlow("Ready?");

    char answer;
    

    while(true) {
        printSlow("Y/N");
        cin >> answer;

        if(answer == 'n' || answer == 'N') {   
            printSlow("Bye-e!");
            this_thread::sleep_for(chrono::seconds(1));
            return 0;
        }
        else if (answer == 'y' || answer == 'Y') {
            printSlow("Hmm...");
            this_thread::sleep_for(chrono::seconds(1));
            break;
        }
        else{
            printSlow("try again");
        }
    }
    bool game = true;

    while(game) {
    
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
    printSlow("Wanna another one? ");
    
    while(true) {
        printSlow("Y/N");
        cin >> answer;

        if(answer == 'y' || answer == 'Y') {
            break;
        }else
        if(answer == 'n' || answer == 'N') {
            printSlow("Kk^^ Bye-e!");
            return 0;
        }
        else {
            printSlow("Try again!");
        }
    }

    }
    return 0;
}

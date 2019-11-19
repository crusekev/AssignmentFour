//
//  main.cpp
//  AssignmentFour
//
//  Created by Kevin Cruse on 11/17/19.
//  Copyright © 2019 Kevin Cruse. All rights reserved.
//
/*
This program is a word guessing game. It prompts the player for input to guess a random word
 letter by letter. The player has 6 missed attempts or they will lose. If you guess
 the word, you win.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

/*
 The inFile function reads in the words.txt file and stores the strings into a string array called array.
 Next, it checks for the file
 Finally, it generates a random string from the string array.
 */

std::string inFile() {
    std::ifstream inFile;
    inFile.open("words.txt");
    srand(time(NULL)); // seeding random number with time
    std::string array[29];
    
    for(int i = 0; i < 29; i++)
        inFile >> array[i];
    
    if(!inFile) {
        std::cout << "Could not find file\n";
        exit(1);
    }
    
    inFile.close();
    
    return array[rand() % 29];
}

//std::string asterisk(int size, std::string string2) {
//
//    for(int i = 0; i < size; i++) {
//        string2.push_back('*');
//    }
//
//    return string2;
//}

int main() {
    std::string word; // string array will be stored here
    std::string string2; // variable for asterisk string
    char guessedLetter; // users guessed letter is stored here
    int guesses = 0; // variable for counting the number of guesses
    word = inFile(); // calling the inFile function
    //std::cout << word << std::endl; // used for debugging
    int size = word.size();
    
    // appends asterisks (*) to string2
    for(int i = 0; i < size; i++) {
        string2.push_back('*');
    }
    
    std::cout << string2 << std::endl;// prints out asterisk string
    int miss = 6; // maximum number of missed guesses
    
    // main while
    while(miss <= 6) {
        std::cout << "Enter a letter: "; // prompt player for input
        std::cin >> guessedLetter;
        std::vector <int> savedIndex; // used a vector so i didn't need a specific size
        
        // reveals the players guessed character if its correct
        for(int i = 0; i < size; i++) {
            if(word[i] == guessedLetter) {
                savedIndex.push_back(i);
                std::cout << "Letter " << guessedLetter << " is present in the word\n";
            }
            
        }
        
        for(int i = 0; i < savedIndex.size(); i++) {
            int index = savedIndex[i];
            string2[index] = guessedLetter;
        }
        
        std::cout << "Number of misses remaining: " << miss << std::endl; // displays number of remaining misses
        
        //if the players misses more than 6 times, you will lose
        if(miss <= 6 && savedIndex.size() == 0) {
            miss--; // decrement misses
            if(miss < 1) {
                std::cout << "You lost the game\n"; // loss message
                break;
            }
        }
        
        guesses++; // increments players number of guesses
        std::cout << string2 << std::endl; // outputs the asterisk string
        if(word == string2) {
            std::cout << "You won the game\n";
            std::cout << "The hidden word was: " << word << std::endl;
            std::cout << "Number of guesses: " << guesses << std::endl;
            return 1;
        }
        
    }
    
    return 0;
}

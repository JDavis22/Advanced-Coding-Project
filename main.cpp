// use \\n to print \n

#include <iostream>
#include <string>

using namespace std;

string animals[5] = {"pigs", "dogs", "cows", "ducks", "geese"};

string choice;

bool isInAnimals = false;

string cont;

int animalsLength = *(&animals + 1) - animals;

class animals {
public:
    void animalSounds(string animal, string sound);
};

void animals::animalSounds(string animal = "Animals", string sound = "") {
    cout << animal << " make " << sound << " sounds!" << endl;
}

class pigs : public animals {
public:
    const string animal = "Pigs";
    const string sound = "'oink oink'";
};

class dogs : public animals {
public:
    const string animal = "Dogs";
    const string sound = "'bow wow'";
};

class cows : public animals {
public:
    const string animal = "Cows";
    const string sound = "'moooooooo'";
};

class ducks : public animals {
public:
    const string animal = "Ducks";
    const string sound = "'quack quack'";
};

class geese : public animals {
public:
    const string animal = "Geese";
    const string sound = "'HONK'";
};

pigs pig;

dogs dog;

cows cow;

ducks duck;

geese goose;

void listAnimals() {
    for(int i=0; i < animalsLength; i++) {
        if(i==0) {
            cout << "The animals we can tell you about are " << animals[i] << ", ";
        } else if(i == animalsLength - 1) {
            cout << "and " << animals[i] << "." << endl;
        } else {
            cout << animals[i] << ", ";
        }
    }
}

void isNotInAnimals() {
    cout << "That is not a valid input. Please try again." <<endl;

    listAnimals();

    cout << "This is case-sensitive, so no capitals or punctuation, okay? Type it exactly how you see it." << endl;
    cout << "What would you like to hear about first? ";
    cin >> choice;
}

void checkIfIsInAnimals() {
    while(isInAnimals == false) {
        for (int i = 0; i < animalsLength; i++) {
            if(animals[i] == choice) {
                isInAnimals = true;
                break;
            }
        }
        if(isInAnimals == false) {
            isNotInAnimals();
        }
    }
}

void result() {
    if(choice == "pigs") {
        pig.animalSounds(pig.animal, pig.sound);
        isInAnimals = false;
    } else if(choice == "dogs") {
        dog.animalSounds(dog.animal, dog.sound);
        isInAnimals = false;
    } else if(choice == "cows") {
        cow.animalSounds(cow.animal, cow.sound);
        isInAnimals = false;
    } else if(choice == "ducks") {
        duck.animalSounds(duck.animal, duck.sound);
        isInAnimals = false;
    } else if(choice == "geese") {
        goose.animalSounds(goose.animal, goose.sound);
        cout << "*The goose steals your computer and drags it into the lake*";
        isInAnimals = false;
    }
}

void wantedAnimal() {
    listAnimals();

    cout << "We can tell you about them one at a time." << endl;
    cout << "This is case-sensitive, so no capitals or punctuation, okay? Type it exactly how you see it." << endl;
    cout << "What would you like to hear about first? ";
    cin >> choice;

    checkIfIsInAnimals();
    result();

    cout << "Would you like to hear about another animal?\nType 'yes' if so. Remember, no capitals or punctuation! ";
    cin >> cont;
}

int main()
{
    cout << "This is a simple C++ program that tells you what sound animals make."<< endl;

    do {
        wantedAnimal();
    } while(cont == "yes");

    return 0;
}

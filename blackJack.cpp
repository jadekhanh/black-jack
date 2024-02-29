#include <iostream>
using namespace std;
#include <time.h>

int total=0;
string allowed_chars="KJQA";

// total_checker: a function that checks if total is less than 21 or not and return the value accordingly
int total_checker(int a, int b) {
    total = total + a + b;
    if (total == 21) {
        cout<<"Total: "<<total<<endl;
        cout << "WON BLACKJACK";
        return 21;
    }
    else if (total > 21) {
        cout<<"Total: "<<total<<endl;
        cout << "FAILED BLACKJACK";
        return -1;
    }
    return total;
}

// blackJack with 2 integers
int blackJack(int a, int b) {
    //Error Message:
    if (a>10 || a<2 || b>10 || b<2) {
        cout<<"ERROR";
        exit(0);
    }
    return total_checker((int) a, (int) b);
}

// blackJack with 2 letters
int blackJack(char a, char b) {
    //Error Message:
    if ( !(allowed_chars.find(a) < allowed_chars.length()) || !(allowed_chars.find(b) < allowed_chars.length())) {
        cout<<"ERROR";
        exit(0);
    }
    int int_a, int_b;
    if (a=='A') {
        int_a = 11;
    }
    else if (a=='J'|| a=='Q'|| a=='K') {
        int_a = 10;
    }
    if (b=='A') {
        int_b = 11;
    }
    else if (b=='J'|| b=='Q'|| b=='K') {
        int_b = 10;
    }
    return total_checker((int) int_a, (int) int_b);
}

// blackJack with 1 letter and 1 number
int blackJack(char a, int b) {
    // Error Message:
    if ( !(allowed_chars.find(a) < allowed_chars.length()) || b < 2 || b > 10 ) {
        cout<<"ERROR";
        exit(0);
    }
    int int_a;
    if (a=='A') {
        int_a = 11;
    }
    else if (a=='J'|| a=='Q'|| a=='K') {
        int_a = 10;
    }
    return total_checker((int) int_a , (int) b);
}

// blackJack with 1 number and 1 letter
int blackJack(int a, char b) {
    // Error Message:
    if ( !(allowed_chars.find(b) < allowed_chars.length()) || a < 2 || a > 10 ) {
        cout<<"ERROR";
        exit(0);
    }
    int int_b;
    if (b=='A') {
        int_b = 11;
    }
    else if (b=='J'|| b=='Q'|| b=='K') {
        int_b = 10;
    }
    return total_checker((int) a , (int) int_b);
}

// blackJack with 1 integer
int blackJack(int a) {
    // Error Message:
    if ( a < 2 || a > 10 ) {
        cout<<"ERROR";
        exit(0);
    }
    return total_checker((int) a , (int) 0);
}

// blackJack with 1 letter
int blackJack(char a) {
    // Error Message: 
    if ( !(allowed_chars.find(a) < allowed_chars.length()) ) {
        cout<<"ERROR";
        exit(0);
    }
    int int_a;
    if (a=='A') {
        int_a = 11;
    }
    else if (a=='J'|| a=='Q'|| a=='K') {
        int_a = 10;
    }
    return total_checker((int) int_a , (int) 0);
}

int main() {
    int c;
    char char_a, char_b, char_c;
    cout<<"Welcome to EC327 BlackJack"<<endl;

    // draw 2 cards a and b
    srand(time(NULL));
    int a = rand() % 13 + 2;   
    int b = rand() % 13 + 2;

    // if a or b are within the range of 11 to 14, then convert them to A, J, Q, K
    if (a==11) {
        char_a='A';
    }
    else if (a==12) {
        char_a='J';
    }
    else if (a==13) {
        char_a='Q';
    }
    else if (a==14) {
        char_a='K';
    }
    if (b==11) {
        char_b='A';
    }
    else if (b==12) {
        char_b='J';
    }
    else if (b==13) {
        char_b='Q';
    }
    else if (b==14) {
        char_b='K';
    }

    // call different functions blackJack depends on a and b
    int result = 0;
    if (a>=11 && b>=11) {
        result = blackJack((char) char_a, (char) char_b);
    }
    else if (a>=11 && b<11) {
        result = blackJack((char) char_a, (int) b);
    }
    else if (a<11 && b>=11) {
        result = blackJack((int) a, (char) char_b);
    }
    else if (a<11 && b<11) {
        result = blackJack((int) a, (int) b);
    }
    
    if (result == -1 || result == 21) {
        return 0;
    }

    // draw again
    cout<<"Total: "<<total<<endl;
    cout<<"Draw Again (y/n) ";
    char answer;
    cin>>answer;
    
    // if answer is 'n'
    if (answer=='n') {
        cout<<"Total: "<<total<<endl;
        cout<<"YOU QUIT WITH "<<total;
    }

    // if answer is not 'n' or 'y'
    else if ((answer!='n') && (answer!='y')) {
        cout<<"Total: "<<total<<endl;
        cout<<"ERROR OCCURED";
    }

    // if answer is 'y'
    while (answer=='y') {
        // single draws of card c
        c = rand() % 13 + 2;

        if (c==11) {
            char_c='A';
            result = blackJack((char) char_c);
        }
        else if (c==12) {
            char_c='J';
            result = blackJack((char) char_c);
        }
        else if (c==13) {
            char_c='Q';
            result = blackJack((char) char_c);
        }
        else if (c==14) {
            char_c='K';
            result = blackJack((char) char_c);
        }
        else {
            result = blackJack((int) c);
        }
        if (result == -1 || result == 21) {
            break;
        }
        cout<<"Total: "<<total<<endl;
        cout<<"Draw Again (y/n) ";
        cin>>answer;
        if (answer=='n') {
            cout<<"Total: "<<total<<endl;
            cout<<"YOU QUIT WITH "<<total;
            exit(0);
        }
    }
    return 0;
}

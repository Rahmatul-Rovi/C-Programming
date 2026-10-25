
#include <iostream>
#include <string>
using namespace std;

int main() {
    string questions[5] = {
        "Which language is used for web styling?",
        "What is 10 + 20?",
        "Which symbol is used for comparison?",
        "Which loop runs at least once?",
        "What is the index of the first array element?"
    };

    string options[5][4] = {
        {"1. HTML", "2. CSS", "3. C++", "4. SQL"},
        {"1. 10", "2. 20", "3. 30", "4. 40"},
        {"1. =", "2. ==", "3. +", "4. %"},
        {"1. for", "2. while", "3. do-while", "4. None"},
        {"1. 0", "2. 1", "3. -1", "4. 2"}
    };

    int answers[5] = {2, 3, 2, 3, 1};
    int choice;
    int score = 0;

    cout << "===== WELCOME TO QUIZ GAME =====\n";

    for (int i = 0; i < 5; i++) {
        cout << "\nQuestion " << i + 1 << ": ";
        cout << questions[i] << endl;

        for (int j = 0; j < 4; j++) {
            cout << options[i][j] << endl;
        }

        cout << "Enter your answer (1-4): ";
        cin >> choice;

        if (choice == answers[i]) {
            cout << "Correct answer!\n";
            score += 10;
        }
        else {
            cout << "Wrong answer!\n";
            cout << "Correct option: " << answers[i] << endl;
        }
    }

    cout << "\n===== QUIZ RESULT =====\n";
    cout << "Total Questions: 5\n";
    cout << "Correct Marks: " << score << "/50\n";

    if (score >= 40) {
        cout << "Excellent performance!\n";
    }
    else if (score >= 30) {
        cout << "Good performance!\n";
    }
    else if (score >= 20) {
        cout << "Keep practicing!\n";
    }
    else {
        cout << "Practice more and try again!\n";
    }

    return 0;
}


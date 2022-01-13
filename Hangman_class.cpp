#include<iostream>
#include <string>
#include <vector>
using namespace std;

///
///my code
///

class Hangman {
private:
    int score;
    vector<string> words = { "grape", "lemon", "mango" };
    vector<string> setting = { "_____", "_____", "_____" };
    char userinput;
    int life = 7;

public:
    void play();
    bool find_word(string word, char a, int n);
    bool is_right(string w1, string w2);
    void draw_life(int life);
    int score = 0;
};

void Hangman::draw_life(int life) {
    if (life <= 7)   cout << "  O  " << endl;
    if (life <= 6)   cout << "  |  " << endl;
    if (life <= 5)   cout << "/ |";
    if (life <= 4)   cout << " \\ " << endl;
    if (life <= 3)   cout << "  |  " << endl;
    if (life <= 2)   cout << "/ |";
    if (life <= 1)   cout << " \\ " << endl;
}

bool Hangman::is_right(string word1, string word2) {
    return (word1 == word2);
}

void Hangman::play() {

    for (int i = 0; i < words.size(); i++) {
        cout << "문제 " << i + 1 << endl;

        while (life > 0) {
            cout << setting[i];
            cout << "\n\n알파벳을 입력하세요 : ";
            cin >> userinput;

            if (!find_word(words[i], userinput, i)) {
                draw_life(life);
                life--;
                cout << "\nleft life" << life << endl;
            }
            else {
                if (is_right(words[i], setting[i])) break;
            }
        }

        if (life == 0) {
            cout << "Game Over" << endl;
        }
        else {
            cout << "Answer: " << setting[i] << endl;
            score += 10;
        }
        life = 7;
    }
    cout << "Score" << score << endl;
}

bool Hangman::find_word(string word, char a, int n) {
    bool flag = false;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == a) {
            setting[n][i] = a;
            flag = true;
        }
    }
    return flag;
}


int main() {
    Hangman hman;
    hman.play();

    return 0;
}

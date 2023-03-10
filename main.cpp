#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string transform_word(string word) {
    // Перенести последнюю букву в начало слова
    char last_letter = word[word.size() - 1];
    word = last_letter + word.substr(0, word.size() - 1);

    // Удалить повторные вхождения каждой буквы
    unordered_set<char> unique_letters;
    string new_word = "";
    for (char letter : word) {
        if (unique_letters.find(letter) == unique_letters.end()) {
            new_word += letter;
            unique_letters.insert(letter);
        }
    }
    return new_word;
}

int main() {
    // Ввести предложение
    string sentence;
    getline(cin, sentence);

    // Разделить предложение на слова и преобразовать каждое слово
    string word;
    for (int i = 0; i < sentence.size(); i++) {
        if (sentence[i] == ',' || sentence[i] == ' ') {
            cout << transform_word(word) << " ";
            word = "";
        } else {
            word += sentence[i];
        }
    }
    cout << transform_word(word) << endl;

    return 0;

}


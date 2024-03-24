#include <iostream>
#include <string>
using namespace std;
// Функция поиска подстроки
void createTable(string& pattern, int d[]) {

    // Длина паттерна
    int Len = pattern.length();

    // Инициализация таблицы со смещениями по умолчанию
    for (int i = 0; i < 256; i++) {
        d[i] = Len;
    }

    // Заполнение таблицы смещений для символов из образа
    for (int i = 0; i < Len - 1; i++) {
        d[(unsigned char)pattern[i]] = Len - i - 1;
    }
}
void boyerMoore(string& text, string& pattern) {

    // Длина паттерна
    int patLen = pattern.length();
    // Длина текста
    int txtLen = text.length();

    // Таблица смещений для символов
    int d[256];
    // Создание таблицы смещений
    createTable(pattern, d);

    // Флажок для проверки, найдено ли вхождение
    bool f = 0;

    // Поиск подстроки
    for (int i = patLen - 1; i < txtLen; i += d[(unsigned char)text[i]]) {

        // Сравнение символов паттерна с конца
        int k = 0;
        while (k < patLen && pattern[patLen - 1 - k] == text[i - k]) {
            k++;
        }

        // Если образ найден, выводим индекс
        if (k == patLen) {
            cout << "Образ найден по индексу " << i - patLen + 1 << endl;
            f = 1;
        }
    }

    // Подстрока не найдена
    if (!f) {
        cout << "Образ не найден в строке" << endl;
    }
}

// Функция создания таблицы смещений


int main() {
    system("chcp 1251>nul");
    string a, b;
    cout << "Строка ";
    getline(cin, a);
    cout << "Образ";
    getline(cin, b);
    boyerMoore(a, b);
}
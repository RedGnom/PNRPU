#include <iostream>
#include <ctime>
#define _USE_MATH_DEFINES 
#include <sstream>
#include <math.h>
using namespace std;

const int M = 5;
const double A = M_PI_4;
int collisionCounter = 0;

struct Node {
    string key = "";
    string value = "";
    bool deleted = false;
};

struct HashTable {
    Node table[M];

    HashTable() {
        for (int i = 0; i < M; ++i)
            table[i].key = "";
    }
};

double mod1(double k) {
    int intPart = static_cast<int>(k);
    return k - intPart;
}

int gethash(double k) {
    return static_cast<int>(M * mod1(k) * A);
}

int gethash(string line) {
    int n = 0;
    for (int i = 0; i < line.size(); i++) {
        n += static_cast<int>(pow(line[i], 2) * M_2_SQRTPI + abs(line[i]) * M_SQRT1_2);
    }
    return gethash(abs(n));
}

void add(HashTable& table, string key, string elem) {
    int hash = gethash(key);
    for (int i = 0; i < M; ++i) {
        int idx = (hash + i) % M;
        if (table.table[idx].key == "" || table.table[idx].deleted) {
            table.table[idx].key = key;
            table.table[idx].value = elem;
            table.table[idx].deleted = false;
            
            return;
        }
        collisionCounter++;
    }
    throw runtime_error("Hash table is full");
}

bool removeByKey(HashTable& table, string key) {
    int hash = gethash(key);
    for (int i = 0; i < M; ++i) {
        int idx = (hash + i) % M;
        if (table.table[idx].key == key && !table.table[idx].deleted) {
            table.table[idx].deleted = true;
            return true;
        }
        if (table.table[idx].key == "") {
            return false;
        }
    }
    return false;
}

Node* get(HashTable& table, string key) {
    int hash = gethash(key);
    for (int i = 0; i < M; ++i) {
        int idx = (hash + i) % M;
        if (table.table[idx].key == key && !table.table[idx].deleted) {
            return &table.table[idx];
        }
        if (table.table[idx].key == "") {
            return nullptr;
        }
    }
    return nullptr;
}

void print(HashTable& table) {
    for (int i = 0; i < M; i++) {
        if (table.table[i].key != "" && !table.table[i].deleted) {
            cout << "[" << table.table[i].key << " : " << table.table[i].value << "]\n";
        }
    }
}


string surnames[] = {
    "Ivanov", "Kozlov", "Novikov", "Morozov", "Petrov",
    " Lebedev", "Soloviev", "Vasiliev", "Zaitsev", "Pavlov",
    "Volkov", "Golubev", "Ignatov", "Bogdanov", "Borobyev",
    "Fyodorov", "Mikhaylov", "Beleyev", "Tarasov", "Belov",
    "Zhukov", "Orlov", "Kiselev", "Makarov", "Andreyev"
};

string names[] = {
    "Alexander", "Sergey", "Andrey", "Dmitriy", "Aleksey",
    "Mikhail", "Nikolay", "Evgeniy", "Oleg", "Vladimir",
    "Nikita", "Yuriy", "Ivan", "Konstantin", "Stanislav",
    "Valentin", "Valeriy", "Oleg", "Konstantin", "Stanislav",
    "Roman", "Igor", "Gennadiy", "Vyacheslav", "David",
    "Nikita", "Artem", "Timur", "Ruslan", "Semyon"
};

string patronymics[] = {
    "Ivanovich", "Sergeevich", "Andreyevich", "Dmitriyevich", "Alekseyevich",
    "Ivanovich", "Nikolayevich", "Mikhaylovich", "Olegovich", "Petrovich",
    "Anatolyevich", "Vladimirovich", "Yegorovich", "Viktorovich", "Fyodorovich",
    "Konstantinovich", "Arkadyevich", "Ermolaevich", "Vasilievich", "Timofeevich",
    "Igorevich", "Valeryevich", "Stanislavovich", "Romanovich", "Gennadiyevich",
    "Pavlovich", "Vyacheslavovich", "Evgenyevich", "Davidovich", "Grigoryevich"
};

string generateFullName() {
    return surnames[rand() % 30] + " " + names[rand() % 30] + " " + patronymics[rand() % 30];
}

string correctStr(int n, int length) {
    string strn = to_string(n);
    while (strn.size() < length) {
        strn = '0' + strn;
    }
    while (strn.size() > length) {
        strn.erase(0, 1);
    }
    return strn;
}

string generateBirthday() {
    return correctStr(rand() % 28 + 1, 2) + "." + correctStr(rand() % 12 + 1, 2) + "." + to_string(rand() % 74 + 1950);
}

string generatePassportNum() {
    return correctStr(rand() % 1000000 + 100, 6) + " " + correctStr((rand() % 1000000 / 100 * 10 + rand()), 6);
}

int main() {
    srand(time(NULL));
    HashTable myTable;

    for (int i = 0; i < M; i++) {
        string birthDay = generateBirthday();
        string newHuman = generateFullName() + " | " + birthDay + " | " + generatePassportNum();
        add(myTable, birthDay, newHuman);
    }

    cout << "\nHash table created:\n" << endl;
    print(myTable);
    cout << endl;

    int existingInd = rand() % M;
    while (myTable.table[existingInd].key == "" || myTable.table[existingInd].deleted) {
        existingInd = rand() % M;
    }

    string keyToRemove = myTable.table[existingInd].key;

    cout << "Delete by key " << keyToRemove << ": ";

    if (removeByKey(myTable, keyToRemove)) {
        cout << "\nElement with key '" << keyToRemove << "' successfully deleted\n" << endl;
    }
    else {
        cout << "\nElement with key '" << keyToRemove << "'" << " not found\n" << endl;
    }

    print(myTable);

    existingInd = rand() % M;
    while (myTable.table[existingInd].key == "" || myTable.table[existingInd].deleted) {
        existingInd = rand() % M;
    }

    string keyToGet = myTable.table[existingInd].key;
    cout << "\nGetting an element by key \"" << keyToGet << "\":" << endl;
    Node* node = get(myTable, keyToGet);
    if (node != nullptr) {
        cout << "Item found: " << node->value << endl;
    }
    else {
        cout << "Element with value " << keyToGet << " not found." << endl;
    }
    cout << "Number of collisions: " << collisionCounter << endl << endl;
    return 0;
}

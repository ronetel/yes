#include <iostream>
#include <windows.h>
#include <string>

using namespace std; 
typedef bool (*prikol)(const char*, const char*);

int main() {
    setlocale(LC_ALL, "Rus");

    HINSTANCE lib;
    prikol address;

    string input;
    string findChar;

    cout << "Введите слово/фразу: ";
    getline(cin, input);

    cout << "Введите буковки для поиска: ";
    getline(cin, findChar);

       lib = LoadLibrary(TEXT("SearchLIB.dll"));
    if (lib != NULL) {
        address = (prikol)GetProcAddress(lib, "prikol");

        if (address != NULL) {
            bool found = address(input.c_str(), findChar.c_str());

            if (found) {
                cout << "Все символы найдены." << endl;
            }
            else {
                cout << "Не все символы найдены." << endl;
            }
        }
        else {
            cerr << "Функция не найдена." << endl;
        }
        FreeLibrary(lib);
    }
    else {
        cerr << "DLL не была загружена." << endl;
    }

    return 0;
}
#include <iostream>
#include <Windows.h>

using namespace std;

int mystrlen(const char* str) 
{
    int length = 0;
    while (*str != '\0') 
    {
        ++length;
        ++str;
    }
    return length;
}

char* mystrcpy(char* str1, const char* str2) 
{
    char* original = str1;
    while ((*str1++ = *str2++) != '\0');
    return original;
}

char* mystrcat(char* str1, const char* str2) 
{
    char* original = str1;
    while (*str1 != '\0') 
    {
        ++str1;
    }
    while ((*str1++ = *str2++) != '\0');
    return original;
}

char* mystrchr(char* str, char s) 
{
    while (*str != '\0') 
    {
        if (*str == s) 
        {
            return str;
        }
        ++str;
    }
    return nullptr;
}

char* mystrstr(char* str1, char* str2) 
{
    while (*str1 != '\0') 
    {
        char* start = str1;
        char* substring = str2;

        while (*substring != '\0' && *str1 == *substring) 
        {
            ++str1;
            ++substring;
        }

        if (*substring == '\0')
        {
            return start;
        }

        str1 = start + 1;
    }
    return nullptr;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char s1[100], s2[100];
    cout << "Введіть перший рядок: ";
    cin.getline(s1, sizeof(s1));
    cout << "Введіть другий рядок: ";
    cin.getline(s2, sizeof(s2));
    cout << "Довжина рядка s1: " << mystrlen(s1) << endl;
    char buffer[200];
    mystrcpy(buffer, s1);
    cout << "Скопійований рядок: " << buffer << endl;
    mystrcat(buffer, s2);
    cout << "Об'єднаний рядок: " << buffer << endl;
    char searchChar;
    cout << "Введіть символ для пошуку: ";
    cin >> searchChar;
    char* charPtr = mystrchr(buffer, searchChar);
    if (charPtr != nullptr) 
    {
        cout << "Знайдено символ '" << searchChar << "' на позиції: " << charPtr - buffer << endl;
    }
    else 
    {
        cout << "Символ '" << searchChar << "' не знайдено." << endl;
    }
    char substring[100];
    cout << "Введіть підрядок для пошуку: ";
    cin.ignore();
    cin.getline(substring, sizeof(substring));
    char* substrPtr = mystrstr(buffer, substring);
    if (substrPtr != nullptr) 
    {
        cout << "Знайдено підрядок '" << substring << "' на позиції: " << substrPtr - buffer << endl;
    }
    else 
    {
        cout << "Підрядок '" << substring << "' не знайдено." << endl;
    }
    return 0;
}

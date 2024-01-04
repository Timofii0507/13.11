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

int mystrcmp(const char* str1, const char* str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return (*str1 > *str2) ? 1 : -1;
        }
        ++str1;
        ++str2;
    }
    return 0;
}

int StringToNumber(char* str)
{
    int result = 0;
    while (*str != '\0')
    {
        result = result * 10 + (*str - '0');
        ++str;
    }
    return result;
}

char* NumberToString(int number)
{
    int temp = number;
    int length = 1;
    while (temp /= 10)
        ++length;
    char* str = new char[length + 1];
    str[length] = '\0';
    while (length-- > 0)
    {
        str[length] = '0' + (number % 10);
        number /= 10;
    }
    return str;
}

char* Uppercase(char* str1)
{
    char* original = str1;
    while (*str1 != '\0')
    {
        *str1 = toupper(*str1);
        ++str1;
    }
    return original;
}

char* Lowercase(char* str1)
{
    char* original = str1;
    while (*str1 != '\0')
    {
        *str1 = tolower(*str1);
        ++str1;
    }
    return original;
}

char* mystrrev(char* str)
{
    int length = mystrlen(str);
    for (int i = 0; i < length / 2; ++i)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return str;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char s1[100], s2[100];
    cout << "������ ������ �����: ";
    cin.getline(s1, sizeof(s1));
    cout << "������ ������ �����: ";
    cin.getline(s2, sizeof(s2));
    cout << "������� ����� s1: " << mystrlen(s1) << endl;
    char buffer[200];
    mystrcpy(buffer, s1);
    cout << "����������� �����: " << buffer << endl;
    mystrcat(buffer, s2);
    cout << "��'������� �����: " << buffer << endl;
    char searchChar;
    cout << "������ ������ ��� ������: ";
    cin >> searchChar;
    char* charPtr = mystrchr(buffer, searchChar);
    if (charPtr != nullptr)
    {
        cout << "�������� ������ '" << searchChar << "' �� �������: " << charPtr - buffer << endl;
    }
    else
    {
        cout << "������ '" << searchChar << "' �� ��������." << endl;
    }
    char substring[100];
    cout << "������ ������� ��� ������: ";
    cin.ignore();
    cin.getline(substring, sizeof(substring));
    char* substrPtr = mystrstr(buffer, substring);
    if (substrPtr != nullptr)
    {
        cout << "�������� ������� '" << substring << "' �� �������: " << substrPtr - buffer << endl;
    }
    else
    {
        cout << "ϳ������ '" << substring << "' �� ��������." << endl;
    }
    cout << "��������� ��������� ����� s1 � s2: " << mystrcmp(s1, s2) << endl;
    char numStr[] = "12345";
    int num = StringToNumber(numStr);
    cout << "����� � �����: " << num << endl;
    char* strNum = NumberToString(num);
    cout << "����� � �����: " << strNum << endl;
    delete[] strNum;
    Uppercase(s1);
    cout << "����� s1 � ��������� ������: " << s1 << endl;
    Lowercase(s2);
    cout << "����� s2 � �������� ������: " << s2 << endl;
    mystrrev(buffer);
    cout << "������ ����� buffer: " << buffer << endl;
    return 0;
}

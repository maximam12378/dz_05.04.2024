#pragma once
#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

class MyString
{



    char* str;
    int size;
public:
    static int counter;

    MyString() // конструктор за замовчуванням (створює рядок довжиною 80символів + \0)
    {

        counter++;
        size = 80;
        str = new char[size + 1];
        str[size] = '\0';
    }

    MyString(int n) //конструктор з переданою довжиною рядка
    {
        size = n;
        str = new char[size + 1];
        str[size] = '\0';
    }

    MyString(int n, char* string[]) //конструктор з переданими параметрами(довшина рядку, вказівник на рядок)
    {
        size = n;
        str = new char[size + 1];
        str[size] = '\0';
        strcpy_s(str, size + 1, *string);
    }

    MyString(int n, char string[]) //конструктор з переданими параметрами(довшина рядку, рядок)
    {
        size = n;
        str = new char[size + 1];
        str[size] = '\0';
        strcpy_s(str, size + 1, string);
    }

    MyString(char* string[]) //конструктор з переданим вказівником на рядок
    {
        size = strlen(*string);
        str = new char[size + 1];
        str[size] = '\0';
        strcpy_s(str, size + 1, *string);
    }

    MyString(char string[]) //конструктор з переданим рядком
    {
        size = strlen(string);
        str = new char[size + 1];
        str[size] = '\0';
        strcpy_s(str, size + 1, string);
    }
    void show_str() // метод для друкування рядку
    {
        cout << str;
    }

    void input_str() // метод для введення рядку з консолі
    {
        size = this->size;
        cin.getline(str, size + 1);
    }

    void MyStrcpy(MyString& obj) //конструктор копіювання рядку
    {
        int size_obj = obj.get_size();
        if (this->size < size_obj) // якщо довжина копіюємого рядку більша за дефолтну довжину(80), то створити новий масив з довжиною копіюємого рядка
        {
            this->size = size_obj;
            this->str = new char[size + 1];
            this->str[size] = '\0';
            strcpy_s(str, size + 1, obj.get_str());
        }
        else
        {
            this->str = new char[size + 1];
            this->str[size] = '\0';
            strcpy_s(str, size + 1, obj.get_str());
        }
    }


    int MyChr()
    {
        char c;
        cout << "Введіть символ для пошуку: ";
        cin >> c;
        // перевірка кожного символу в рядку
        for (int i = 0; i < this->size; i++) {
            if (this->str[i] == c) {
                return i; // символ знайдено
            }
        }

        cout << "Символ не знайдено!";
        return -1;

    }

    int MyChr(char c)
    {

        // перевірка кожного символу в рядку
        for (int i = 0; i < this->size; i++) {
            if (this->str[i] == c) {
                return i; // символ знайдено
            }
        }

        cout << "Символ не знайдено!";
        return -1;

    }

    int MyChr(char* ch)
    {
        char c = *ch;
        // перевірка кожного символу в рядку
        for (int i = 0; i < this->size; i++) {
            if (this->str[i] == c) {
                return i; // символ знайдено
            }
        }

        cout << "Символ не знайдено!";
        return -1;
    }

    int MyStrlen()
    {
        return strlen(str);
    }

    void MyStrCat(MyString& obj) // объединение строк
    {
        const int N = MyStrlen() + obj.MyStrlen();
        char* result = new char[N + 1];

        int i = 0, j = 0, k = 0;

        while (this->str[i] != '\0')
        {
            result[k++] = str[i++];
        }

        int len = obj.MyStrlen();
        char* obj_str = obj.get_str();

        while (obj_str[j] != '\0')
        {
            result[k++] = obj_str[j++];
        }
        result[k] = '\0';

        this->str = new char[strlen(result) + 1];
        this->str[size] = '\0';
        strcpy_s(str, strlen(result) + 1, result);
    }


    void MyDelChr(char c) // видаляє вказаний символ
    {
        int i = MyChr(c);

        while (this->str[i] != '\0')
        {
            str[i++] = str[i + 1];
        }

    }


    int MyStrCmp(MyString& obj) // сравнение строк 
    {
        if (this->MyStrlen() < obj.MyStrlen())
            return -1;
        else if (this->MyStrlen() > obj.MyStrlen())
            return 1;
        else
            return 0;

    }



    int get_size() // геттер довжени рядка
    {
        return this->size;
    }

    char* get_str() //геттер вказіника на рядок
    {
        return this->str;
    }


    ~MyString() //диструктор
    {
        delete[] str;
    }
};
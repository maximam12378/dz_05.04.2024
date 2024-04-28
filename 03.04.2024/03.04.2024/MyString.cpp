#include <iostream>
#include <string>
#include <locale.h>
#include "MyString.h"
using namespace std;

void gap(int x = 1)
{
    while (x != 0)
    {
        cout << endl;
        x--;
    }
        
}

int main()
{
    
    //char* test = new char[N + 1];
    //char test[] = "new char[N+1]";
    ////cin.getline(test, strlen(test));
    //MyString str1(test);
    //gap(2);
    //str1.show_str();

    //gap(2);

    //MyString str2;
    //str2.MyStrcpy(str1);
    //cout << str2.get_size() << endl;
    //str2.show_str();

    //gap(2);


    //cout << str2.MyChr();
    //gap(2);
    //cout << str2.MyStrlen();

    MyString::counter = 0;

    char test1[] = "11110";
    char test2[] = "221223";
    MyString str1(test1);
    MyString str2(test2);

    


}
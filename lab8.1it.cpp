#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>

using namespace std;

int CountPairs(char* str)
{
    if (strlen(str) < 3)
        return 0;
    int count = 0;
    for (int i = 0; str[i + 1] != 0; i++) 
    {
        if ((str[i] == 'a' && str[i + 1] == 'a') ||
            (str[i] == 'b' && str[i + 1] == 'b') ||
            (str[i] == 'c' && str[i + 1] == 'c'))
        {
            count++;
        }
    }
    return count;
}

char* ChangePairs(char* str) 
{
    size_t len = strlen(str);
    if (len < 3)
        return str;

    char* tmp = new char[len * 3 / 2.0 + 1.0]; 
    char* t = tmp;
    tmp[0] = '\0';
    size_t i = 0;

    while (i < len) 
    {
        if ((str[i] == 'a' && str[i + 1] == 'a') ||
            (str[i] == 'b' && str[i + 1] == 'b') ||
            (str[i] == 'c' && str[i + 1] == 'c'))
        {
            strcat(t, "***");
            t += 3;
            i += 2;
        }
        else 
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    *t++ = str[i++]; 
    *t = '\0';
    strcpy(str, tmp); 
    return tmp;
}
    
int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contains " << CountPairs(str) << " pairs of 'aa', 'bb', or 'cc'" << endl;
    char* destin = new char[151];
    destin = ChangePairs(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << destin << endl;


    return 0;
}

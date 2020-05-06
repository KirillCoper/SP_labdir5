#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

using namespace std;

static string str;

void* finder(void* arg)
{
    string s;
    string* s1 = (string*)arg;
    cout << *s1 << endl;
    cout << str << endl;
    s = *s1;
    if (s.find(str) < 1000) {
        cout << "Naideno v pozicii " << s.find(str) << endl;
    }
    else
    {
        cout << "Ne naideno" << endl;
    }
    return 0;
}
int main()
{
    int ch = 0;
    string s;
    string mas_string[7];
    pthread_t mas_str[7];
    ifstream file("/TEXT");
    while (getline(file, s))
    {
        mas_string[ch] = s;
        cout << mas_string[ch] << endl;
        ch++;
    }
    file.close();
    cout << "Vvedite slovo ili fragment" << endl;
    cin >> str;
    for (int i = 0; i < 7; i++)
    {
        pthread_create(&mas_str[i], NULL, finder, (void*)&mas_string[i]);
        sleep(2);
    }
    return 0;
}
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string s = "12:33";
    istringstream iss(s);
    
    do
    {
        string subs;
        iss >> subs;
        cout << "Substring: " << subs << endl;
    } while (iss);
}


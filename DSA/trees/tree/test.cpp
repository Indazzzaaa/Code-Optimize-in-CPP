#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{

    stringstream ss, ss2, ss3;
    ss << "Hello";
    ss << "World";
    ss << 23;
    ss << 'c';

    ss2 << 22;

    ss3 << "10, 20, 30, #, #, #, #";
    string s;
    getline(ss3, s, ',');
    cout << stoi(s) << endl;
    getline(ss3, s, ',');
    cout << stoi(s) << endl;
    /* for (int i = 0; i < 5; i++)
    {

        auto out = getline(ss3, s, ',');
        cout << out << endl;
    } */
    /*   cout << ss.str() << endl;
      cout << stoi(ss2.str()) << endl;
      cout << stof("22.33") << endl; */
    return 0;
}

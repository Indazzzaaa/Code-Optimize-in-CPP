#include "lcs.h"

int main(int argc, char const *argv[])
{
    string s1 = "axxxxxxxxxc";
    string s2 = "a2222xxxxc";
    cout << "Result : " << LCS::space_optimize(s1, s2, s1.length(), s2.length()) << endl;

    cout << "Test Finished ";
    return 0;
}

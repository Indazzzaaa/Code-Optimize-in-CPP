#include "ed.hpp"

void test1()
{
    string s1 = "CAT";
    string s2 = "CUT";
    cout << " [Test_1] Result is : " << EditDistance::solvRec(s1, s2, s1.length(), s2.length()) << endl;
    cout << " [Test_1_DP] Result is : " << EditDistance::solveDP(s1, s2, s1.length(), s2.length()) << endl;
}

void test2()
{
    string s1 = "GEEK";
    string s2 = "GEEKS";
    cout << " [Test_2] Result is : " << EditDistance::solvRec(s1, s2, s1.length(), s2.length()) << endl;
    cout << " [Test_2_DP] Result is : " << EditDistance::solveDP(s1, s2, s1.length(), s2.length()) << endl;
}

void test3()
{
    string s1 = "saturday";
    string s2 = "sunday";
    cout << " [Test_3] Result is : " << EditDistance::solvRec(s1, s2, s1.length(), s2.length()) << endl;
    cout << " [Test_3_DP] Result is : " << EditDistance::solveDP(s1, s2, s1.length(), s2.length()) << endl;
}

int main(int argc, char const *argv[])
{

    test1();
    test2();
    test3();

    cout << "Execution Completed!!";
    return 0;
}

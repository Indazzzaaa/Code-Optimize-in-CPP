#include "n_sum_ways.h"

int main(int argc, char const *argv[])
{
    cout << "Result : " << N_Sum::rec(3) << endl;
    cout << "Result : " << N_Sum::dp_tabulation(3) << endl;

    cout << "Test Ended " << endl;
    return 0;
}

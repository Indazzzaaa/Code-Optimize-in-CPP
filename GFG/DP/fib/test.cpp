#include "fib.h"
#include <chrono>

int main(int argc, char const *argv[])
{
    cout << "Testing : Started " << endl;
    cout << "Size of :" << sizeof(long long) << endl;

    // Record the start time
    auto startTime = std::chrono::high_resolution_clock::now();

    // * =========================================================================================

    // int result = Fibo::fibRec(40);
    long long n = 50'000'100;
    Fibo fib = Fibo(n);
    long long result = fib.fibTabulation(n);

    // * =========================================================================================
    // Record the end time
    auto endTime = std::chrono::high_resolution_clock::now();

    cout << "Ans  : " << result << endl;
    // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    std::cout << "Time taken by the algorithm: " << duration.count() << " ms" << std::endl;

    cout << "Testing : Ended " << endl;

    return 0;
}

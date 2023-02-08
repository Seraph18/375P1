#include <iostream>
#include <vector>
using namespace std;

struct equation
{
    int firstNumber;
    int secondNumber;
    int totalNumber;
};

vector<equation>
solve(int *arr, int size)
{
    vector<equation> solutions;
    for (int i = 2; i < size; ++i)
    {
        // Set value to look for
        int currentValue = arr[i];
        for (int j = i - 1; j >= 0; --j) // get first number to test against
        {
            int firstNumber = arr[j];
            for (int n = j - 1; n >= 0; --n) // second number to test
            {
                int secondNumber = arr[n];
                if ((firstNumber + secondNumber) == currentValue)
                {
                    equation currentEquation;
                    currentEquation.firstNumber = firstNumber;
                    currentEquation.secondNumber = secondNumber;
                    currentEquation.totalNumber = currentValue;
                    solutions.push_back(currentEquation);
                    n = -1;
                    j = -1;
                }
            }
        }
    }
    return solutions;
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 4, 10, 11, 13, 18, 18, 19, 20, 22, 23, 27, 35, 38, 40, 55, 67, 99, 198, 487};
    int size = sizeof(arr) / sizeof(int);
    vector<equation> solution = solve(arr, size);
    while (!solution.empty())
    {
        cout << solution.at(solution.size() - 1).firstNumber << " ";
        cout << solution.at(solution.size() - 1).secondNumber << " ";
        cout << solution.at(solution.size() - 1).totalNumber << endl;

        solution.pop_back();
    }
    return 0;
}
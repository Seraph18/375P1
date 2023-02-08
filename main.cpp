#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(int *arr)
{
    vector<int> solutions;
    for (int i = 2; i < sizeof(arr); ++i)
    {
        //Set value to look for
        int currentValue = arr[i];
        for (int j = i; j >= 0; --j)// get first number to test against
        {
            int firstNumber = arr[j];
            for (int n = j - 1; n >= 0; --n) // second number to test
            {
                int secondNumber = arr[n];
                if((firstNumber + secondNumber)==currentValue){
                    solutions.push_back(currentValue);
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
    int arr[] = {3, 4, 5, 6, 7, 8, 9};
    vector<int> solution = solve(arr);
    while(!solution.empty()){
        cout << solution.at(solution.size()-1) << endl;
        solution.pop_back();
    }
    return 0;
}
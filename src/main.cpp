#include <iostream>
#include "solution/solution.hpp"
using namespace std;

int main(int argc, char* argv[]){

    vector<int> nums { 2, 3, 4, 5, 7 };
    solution* obj = new solution(nums);
    obj->shuffle();

    for(const auto& num : nums)
        cout << num << endl;

    return 0;
}
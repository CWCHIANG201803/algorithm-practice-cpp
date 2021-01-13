#include <iostream>
#include "../solution/solution.hpp"
using namespace std;


int main(int argc, char* argv[]){

    solution* obj = new solution();
    vector<int> nums = {2,3,4,5};
    vector<int> res = obj->twoSum(nums, 7);
    
    for(auto num : res){
        cout << num << endl;
    }

    return 0;
}
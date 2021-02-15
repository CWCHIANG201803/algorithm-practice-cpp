#include <iostream>
#include "../solution/solution.hpp"
#include "utility/inputProcessUtility.hpp"
using namespace std;


int main(int argc, char* argv[]){
    string input = "[1,2,3,4]";


    vector<int> res = buildOneDimensionalArray<int>(input);
    
    

    return 0;
}
#include <iostream>
#include "../solution/solution.hpp"
#include "utility/inputProcessUtility.hpp"
using namespace std;


int main(int argc, char* argv[]){

    inputProcessUtility utility;

    string input = "[1,2,3,4]";
    auto result = utility.convertToInt(utility.buildOneDimensionalArray(input));

    

    return 0;
}
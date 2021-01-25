
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class inputProcessUtility {
public:
    vector<string> buildOneDimensionalArray(string input);
    vector<vector<string>> buildTwoDimensionalArray(string input);
    vector<vector<int>> convertToInt(vector<vector<string>> input);
    vector<int> convertToInt(vector<string> input);
    string serializeToString(vector<vector<int>> input);
    string serializeToString(vector<vector<string>> input);
    string serializeToString(vector<int> input);
    string serializeToString(vector<string> input);

};
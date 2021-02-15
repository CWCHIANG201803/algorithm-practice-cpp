#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

template<typename T>
vector<T> buildOneDimensionalArray(string input){
    if(input.empty())
        return {};
    string str = input.substr(1, input.size()-2);
    istringstream iss(str);
    string val;

    vector<T> res;
    while(std::getline(iss, val, ',')){
      if constexpr (std::is_same_v<T, char>){
          res.push_back(val.front());
      }else if constexpr (std::is_same_v<T, int>){
          res.push_back(stoi(val));
      }else if constexpr (std::is_same_v<T, string>){
          res.push_back(val);
      }
    }
    return res;
}

template<typename T>
vector<vector<T>> buildTwoDimensionalArray(string input){
     string str = input.substr(1,input.length()-2);
    if(str.empty())
        return {};
    
    vector<string> tokens;
    stringstream ss;
    int i = 0;
    while(i < str.size()){
        if(str[i]=='['){
            int j = i;
            while(str[j]!=']')
                ss << str[j++];
            ss << str[j];
            i = j+1;
        }
        if(i < str.size() && str[i++]==','){  // "," at outer loop
            tokens.push_back(ss.str());
            ss.str("");
        }
    }

    tokens.push_back(ss.str());
    vector<vector<T>> res;
    for(const auto& token : tokens)
        res.push_back(buildOneDimensionalArray<T>(token));
    
    return res;
}

template<typename T>
string serializeToString(vector<vector<T>> input){
    stringstream out;
    string token_outside = "";
    out << "[";
    for(int i = 0 ; i < input.size(); ++i){    
        out << token_outside << "[";
        string token_inside = "";
        for(int j = 0 ; j < input[i].size(); ++j){
            out << token_inside << input[i][j];
            token_inside = ",";
        }
        out << "]";
        token_outside = ",";
    }
    out << "]";

    return out.str();
}

template<typename T>
string serializeToString(vector<T> input){
    stringstream out;
    string token_inside = "";
    out << "[";
    for(int i = 0 ; i < input.size(); ++i){    
        out << token_inside << input[i];
        token_inside = ",";
    }
    out << "]";

    return out.str();
}

template<typename T>
void display(vector<vector<T>> input){
    for(vector<T> row : input){
        display<T>(row);
        cout << endl;
    }
}

template<typename T>
void display(vector<T> input){
    for(auto element : input){
        cout << element << " ";
    }
}
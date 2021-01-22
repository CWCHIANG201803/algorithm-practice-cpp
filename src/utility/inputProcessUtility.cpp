
#include "inputProcessUtility.hpp"

vector<string> inputProcessUtility::buildOneDimensionalArray(string input){
    if(input.empty())
        return {};
    string str = input.substr(1, input.size()-2);
    istringstream iss(str);
    string val;

    vector<string> res;
    while(std::getline(iss, val, ','))
        res.push_back(val);

    return res;
}

vector<vector<string>> inputProcessUtility::buildTwoDimensionalArray(string input){
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
            ss = {};
        }
    }
    tokens.push_back(ss.str());
    vector<vector<string>> res;
    for(const auto& token : tokens)
        res.push_back(buildOneDimensionalArray(token));
    
    return res;
}

vector<vector<int>> inputProcessUtility::convertToInt(vector<vector<string>> input){
    int m = input.size();
    vector<vector<int>> res;
    for(int i = 0 ; i < m ; ++i){
        int n = input[i].size();
        vector<int> row(n, 0);
        try{
            for(int j = 0 ; j < n ; ++j)
                row[j] = stoi(input[i][j]);
            res.push_back(row);
        }catch(const exception& ex){
            cerr << "error occurred!" << endl;
            cerr << ex.what() << endl;
        }
    }
    
    return res;
}

vector<int> inputProcessUtility::convertToInt(vector<string> input){
    if(input.empty())
        return {};
    
    int m = input.size();
    vector<int> res(m, 0);

    for(int i = 0 ; i < m ; ++i){  
        try {
            res[i] = stoi(input[i]);            
        } catch(const exception& ex){
            cerr << "error occurred!" << endl;
            cerr << ex.what() << endl;
        }
    }
    
    return res;
}

string inputProcessUtility::serializeToString(vector<vector<int>> input){
    stringstream out;
    string token_outside = "";
    out << "[";
    for(int i = 0 ; i < input.size(); ++i){    
        out << token_outside << "[";
        string token_inside = "";
        for(int j = 0 ; j < input[i].size(); ++j){
            out << token_inside << to_string(input[i][j]);
            token_inside = ",";
        }
        out << "]";
        token_outside = ",";
    }
    out << "]";

    return out.str();
}

string inputProcessUtility::serializeToString(vector<int> input){
    stringstream out;
    string token_inside = "";
    out << "[";
    for(int i = 0 ; i < input.size(); ++i){    
        out << token_inside << to_string(input[i]);
        token_inside = ",";
    }
    out << "]";

    return out.str();
}
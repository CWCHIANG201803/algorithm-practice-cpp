#include <vector>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

class WordDistance {
public:
    WordDistance(vector<string>& words);
    int shortest(string word1, string word2);
};
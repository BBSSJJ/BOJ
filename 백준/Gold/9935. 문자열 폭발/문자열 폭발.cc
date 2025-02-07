#include <iostream>
#include <vector>
#include <string>

using namespace std;

string sentence, pattern;
vector<char> v;

int main()
{
    cin >> sentence;
    cin >> pattern;
    int sentence_length = sentence.length();
    int pattern_length = pattern.length();

    for(int i = 0; i < sentence_length; i++){
        v.push_back(sentence[i]);
        int m = v.size() - 1;
        if(v.size() < pattern_length)
            continue;
        for(int j = 0; j < pattern_length; j++){
            if(v[m - j] != pattern[pattern_length - 1 - j]){
                break;
            }
            if(j == pattern_length - 1){
                for(int k = 0; k < pattern_length; k++){
                    v.pop_back();
                }
            }
        }
    }
    if (v.empty())
    {
        cout << "FRULA" << endl;
    }
    else
    {
        int vsize = v.size();
        for (int l = 0; l < vsize; l++)
        {
            cout << v[l];
        }
    }
}
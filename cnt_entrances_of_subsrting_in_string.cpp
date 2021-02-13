#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> piFun(string str)
{
    // creating vector of pi-functions for all chars in summary
    vector <int> pi (str.size(), 0);

    // calculating pi-functions for each char in summary
    for (int i = 1; i < str.size(); i++)
    {
        int k = pi[i-1];
        
        while (k > 0 && str[i] != str[k])
        {
            k = pi[k-1];
        }

        if (str[i] == str[k])
        {
            k++;
        }
        
        pi[i] = k;
    }
    return pi;
}

int KMP(string str, string substr)
{
    // merging str and substr
    string summary = substr + "#" + str;
    int substr_size = substr.size();

    // creating vector of pi-functions for all chars in summary
    vector <int> pi = piFun(summary);

    // counting entrances of substr in str
    int cnt_entrances = 0;

    for (auto now : pi)
    {
        cnt_entrances += (now == substr_size);
    }
    return cnt_entrances;
}

int main()
{
    string str;
    string substr;
    getline(cin, str);
    getline(cin, substr);

    cout << KMP(str, substr);

    return 0;
}

// abacaba
// accabacbabcabacabaabacaaba
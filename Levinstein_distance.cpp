#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findLevinstainLength(string a, string b)
{
    vector < vector <int> > L (a.size() + 1, vector <int> (b.size() + 1));

    for (int i = 0; i <= a.size(); i++)
    {
        L[i][0] = i;
    }
    for (int i = 0; i <= b.size(); i++)
    {
        L[0][i] = i;
    }

    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i-1] == b[j-1]) // super lucky
            {
                L[i][j] = L[i-1][j-1];
            }
            else
            {
                L[i][j] = min(min(L[i-1][j], L[i][j-1]), L[i-1][j-1]) + 1;
            }
        }
    } 
    return L[a.size()][b.size()];
}

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);

    cout << findLevinstainLength(a, b);

    return 0;
}
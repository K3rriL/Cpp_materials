#include <iostream>
#include <vector>

using namespace std;

int num_of_items, max_capacity;

vector <int> weight;
vector <int> val;
vector < vector <int> > dp;

void input()
{
    cout << "\nEnter number of items and maximal backpack's capacity:\n";
    cin >> num_of_items >> max_capacity;

    weight = vector <int> (num_of_items);
    val = vector <int> (num_of_items);
    dp = vector < vector <int> > (num_of_items+1, vector <int>(max_capacity+1));

    for (int i = 0; i < num_of_items; i++)
    {
        cin >> weight[i] >> val[i];
    }
}

void output()
    {
        cout << "\nMaximal sum value of all items is:\n";
    cout << dp[num_of_items][max_capacity] << endl;
}

int main()
{
    input();

    for (int i = 0; i <= max_capacity; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= num_of_items; i++)
    {
        for (int j = 0; j <= max_capacity; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (j >= weight[i-1])
            {
                dp[i][j] = max(dp[i][j], dp[i][j - weight[i-1]] + val[i-1]);
            }
        }
    }

    output();
    return 0;
}
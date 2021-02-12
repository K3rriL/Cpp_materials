#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>

// using separate names of std lib instead of the whole lib
using std::cin;
using std::cout;
using std::vector;
using std::list;
using std::string;
using std::iterator;
using std::endl;
using std::getline;

void vectorExample()
{
    // vector initialization
    vector <string> words;
    string word;

    // input
    getline(cin, word);
    while (word != "")
    {
        words.push_back(word);
        getline(cin, word);
    }

    // printing
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << "\n";
    }
    cout << endl;
}

void listExample()
{
    // list initialization
    list <string> words;
    string word;

    // input
    getline(cin, word);
    while (word != "")
    {
        words.push_back(word);
        getline(cin, word);
    }

    // 1st variant of addressing to list's elements:
    for (list <string>::iterator it = words.begin(); it != words.end(); it++)
    {
        // printing the denamed iterator (as pointer):
        cout << *it << "\t";  
    }
    cout << endl;

    // 2nd variant of addressing to list's elements:
    for (auto word : words)
    {
        // printing automatically denamed iterator:
        cout << word << "\t";  
    }
    cout << endl;

}

int main()
{
    vectorExample();
    listExample();
    return 0;
}
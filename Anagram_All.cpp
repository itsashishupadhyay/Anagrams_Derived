#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> Ana_Words;
vector<string> vectorNew;

void Anagram(string input, string const &file);
// vector<vector<string>> Ana_Words;

int main(int argc, char *argv[])
{

    if (argc != 2) // argc should be 2 for correct execution
        // We print argv[0] assuming it is the program name
        cout << "usage: " << argv[0] << " <filename>\n";
    else
    {
        // We assume argv[1] is a filename to open
        string file = argv[1];
        ifstream the_file(argv[1]);
        // Always check to see if file opening succeeded
        if (!the_file.is_open())
            cout << "Could not open file\n";
        else
        {
            string x;
            // the_file.get ( x ) returns false if the end of the file
            //  is reached or an error occurs
            while (getline(the_file, x))
            {
                if (x.size() == 4)
                {
                    // cout << x << endl;
                }
            }
        }
        string Ipstr;
        cout << "Please enter Starting 3 letters:  \n";
        getline(cin, Ipstr);
        if (Ipstr.size() == 3)
        {
            cout << " input str is " << Ipstr << endl;
            cout << "string accepted looking for anagrams: ";
            vectorNew.push_back(Ipstr);
            Anagram(Ipstr, file);
        }
        else
        {
            cout << "you didn't entered 3 letters, please restart" << endl;
        }
    }
    cout << "code Exit " << endl;
}

void Anagram(string input, string const &file)
{
    string x, x_sort;
    ifstream the_file(file);

    // Always check to see if file opening succeeded
    // cout << "the input file recieved is " << input << endl;
    if (!the_file.is_open())
        cout << "Could not open file\n";
    else
    {
        // int Position=0;

        while (getline(the_file, x))
        {
            if (x.size() == input.size() + 1)
            {
                // cout << x << endl;
                x_sort = x;
                // input_sort=input;

                // sort(x_sort.begin(), x_sort.end());
                // sort(input_sort.begin(), input_sort.end());

                int i = 0, count = 0;

                while (i < input.size())
                {
                    // cout << input.at(i) << endl;

                    size_t found = x_sort.find(input.at(i));
                    if (found != string::npos)
                    {
                        x_sort.erase(found, 1);
                        count++;
                        // cout << count << endl;
                    }
                    i++;
                }
                if (count == input.size())
                {
                    int pos = 0;
                    pos = x.size() - 4;
                    Ana_Words.erase(Ana_Words.begin() + pos, Ana_Words.end());
                    Ana_Words.push_back(x);

                    Anagram(x, file);
                }
            }
        }
    }
    if (vectorNew != Ana_Words)
    {
        for (auto i = Ana_Words.begin(); i != Ana_Words.end(); ++i)
        {
            if (i == Ana_Words.end() - 1)
            {
                cout << *i;
            }
            else
            {
                cout << *i << "---->";
                
            }
        }
        cout << endl;
        vectorNew.clear();
        vectorNew = Ana_Words;
    }
}
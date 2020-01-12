#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> Ana_Words;               //Global variable declared so that functions could update them dynamically,
                                        //i wanred to keep the code short and avoid classes
vector<string> vectorNew;
vector<string> LongChain;

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
            cout << "string accepted looking for anagrams: "<<endl;
            vectorNew.push_back(Ipstr);                             // Smallest Length word as input
            LongChain.push_back(Ipstr);
            Anagram(Ipstr, file);
        }
        else
        {
            cout << "you didn't entered 3 letters, please restart" << endl; // end programme if >3 words detected
        }
    }
    string lastword = "";
    string Currentword = "";
    for (auto i = LongChain.begin(); i != LongChain.end(); ++i) // look at the ANAgram Function below first
    {
        Currentword = *i;

        if (lastword.size() >= Currentword.size())
        {
            cout <<"Chain's Word Length: "<< lastword.size();      //Long chain contains the final longest chain
            cout << endl;
        }

        if (i == LongChain.end() - 1)
        {
            cout << *i;
            lastword = *i;
        }
        else
        {
            cout << *i << "---->";
            lastword = *i;
        }
    }
    cout<< endl;
    cout << "*********FINISHED********** " << endl;
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

                    size_t found = x_sort.find(input.at(i)); // sorting so as to maintain that repetatiive leters are treated differently
                    if (found != string::npos)
                    {
                        x_sort.erase(found, 1);         // remove the found position so that repeting letter can be treated uniquely
                        count++;
                        // cout << count << endl;
                    }
                    i++;
                }
                if (count == input.size())
                {
                    int pos = 0;
                    pos = x.size() - 4;                                         // ipstr +1 is the length of first word find so kinda start of the array
                    Ana_Words.erase(Ana_Words.begin() + pos, Ana_Words.end());
                    Ana_Words.push_back(x);

                    Anagram(x, file); // recalling function for consicutive found anagrams
                }
            }
        }
    }
    if (vectorNew != Ana_Words)
    {
        // for (auto i = Ana_Words.begin(); i != Ana_Words.end(); ++i)
        // {
        //     if (i == Ana_Words.end() - 1)
        //     {
        //         cout << *i;
        //     }
        //     else
        //     {
        //         cout << *i << "---->";
        //     }
        // }
        // cout << endl;
        vectorNew.clear();
        vectorNew = Ana_Words;

        if (Ana_Words.back().size() == LongChain.back().size())  // long chain getting the largest chain or chains
        {
            LongChain.insert(LongChain.end(), Ana_Words.begin(), Ana_Words.end()); 
        }
        else if (Ana_Words.back().size() > LongChain.back().size())
        {
            LongChain.clear();
            LongChain = Ana_Words;
        }
    }
}
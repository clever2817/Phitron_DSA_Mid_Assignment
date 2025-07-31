#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<string> l;

    string str;

    while(true)
    {
        cin >> str;

        if(str == "end")
        {
            break;
        }

        l.push_back(str);
    }

    int q;

    cin >> q;

    string command;

    auto curr_address = l.begin();

    while(q--)
    {
        cin >> command;

        if(command == "visit")
        {
            string address;

            cin >> address;

            auto find_address = find(l.begin(), l.end(), address);

            if(find_address != l.end())
            {
                cout << *find_address << "\n";

                curr_address = find_address;
            }

            else
            {
                cout << "Not Available\n";
            }
        }

        else if(command == "next")
        {
            auto next_address = next(curr_address);

            if(next_address == l.end())
            {
                cout << "Not Available\n";
            }

            else
            {
                cout << *next_address << "\n";

                curr_address = next_address;
            }
        }

        else if(command == "prev")
        {
            auto prev_address = prev(curr_address);

            if(curr_address == l.begin())
            {
                cout << "Not Available\n";
            }

            else
            {
                cout << *prev_address << "\n";

                curr_address = prev_address;
            }
        }
    }

    return 0;
}

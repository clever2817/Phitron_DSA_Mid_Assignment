#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;

    int q;

    cin >> q;

    while(q--)
    {
        int x,v;

        cin >> x >> v;

        if(x == 0)
        {
            l.push_front(v);

            cout << "L -> ";

            for(auto val : l)
            {
                cout << val << " ";
            }

            cout << "\n";

            list<int> l2(l);

            l2.reverse();

            cout << "R -> ";

            for(auto val : l2)
            {
                cout << val << " ";
            }

            cout << "\n";
        }

        else if(x == 1)
        {
            l.push_back(v);

            cout << "L -> ";

            for(auto val : l)
            {
                cout << val << " ";
            }

            cout << "\n";

            list<int> l2(l);

            l2.reverse();

            cout << "R -> ";

            for(auto val : l2)
            {
                cout << val << " ";
            }

            cout << "\n";
        }

        else if(x == 2)
        {
            if(v < 0 || v >= l.size())
            {
                cout << "L -> ";

                for(auto val : l)
                {
                    cout << val << " ";
                }

                cout << "\n";

                list<int> l2(l);

                l2.reverse();

                cout << "R -> ";

                for(auto val : l2)
                {
                    cout << val << " ";
                }

                cout << "\n";

            }

            else
            {
                auto it = next(l.begin(), v);

                l.erase(it);

                cout << "L -> ";

                for(auto val : l)
                {
                    cout << val << " ";
                }

                cout << "\n";

                list<int> l2(l);

                l2.reverse();

                cout << "R -> ";

                for(auto val : l2)
                {
                    cout << val << " ";
                }

                cout << "\n";
            }
        }
    }

    return 0;
}

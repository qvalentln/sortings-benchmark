#include <bits/stdc++.h>

using namespace std;

void custom_sort(vector <int> &a)
{
    int ind=0;
    while(ind<(int)a.size())
    {
        if(ind==0)
        {
            ind++;
        }
        else if(a[ind-1]>a[ind])
        {
            swap(a[ind-1],a[ind]);
            ind--;
        }
        else
        {
            ind++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a) {
    std::cin >> x;
    }

    custom_sort(a);

    assert(std::ranges::is_sorted(a));

    return 0;
}

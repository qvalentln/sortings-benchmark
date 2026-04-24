#include <bits/stdc++.h>

using namespace std;

void custom_sort(vector <int> &a)
{
    bool ter=false;
    while(!ter)
    {
        ter=true;
        for(int i=0; i+1<a.size(); i++)
        {
            if(a[i]>a[i+1])
            {
                ter=false;
                swap(a[i],a[i+1]);
            }
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

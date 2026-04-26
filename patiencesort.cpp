#include <bits/stdc++.h>

using namespace std;

void custom_sort(vector<int>& a){
    int n=a.size();

    vector <int> b,as;
    vector <int> pred(n);

    for(int i=0; i<n; i++)
    {
        int st=0,dr=(int)b.size()-1,mij,p=-1;
        while(st<=dr)
        {
            mij=(st+dr)/2;

            if(a[b[mij]]>=a[i])
            {
                p=mij;
                dr=mij-1;
            }
            else
            {
                st=mij+1;
            }
        }

        if(p==-1)
        {
            b.push_back(i);
            pred[i]=-1;
        }
        else
        {
            pred[i]=b[p];
            b[p]=i;
        }
    }

    priority_queue <pair <int,int>> pq;

    for(int p:b)
        pq.push(make_pair(-a[p],p));

    while(!pq.empty())
    {
        pair <int,int> aux=pq.top();
        pq.pop();

        int i=aux.second;
        as.push_back(a[i]);

        if(pred[i]>=0)
            pq.push(make_pair(-a[pred[i]],pred[i]));
    }

    a=as;

    return;
}

int main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

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

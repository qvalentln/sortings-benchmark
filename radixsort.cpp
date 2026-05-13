#include<iostream>
#include<cassert>
#include<vector>
#include<ranges>
#include<algorithm>
#include<climits> //INT_MAX





//Sort a non-negative vector
void helper(std::vector<int>& v, int exp) {
        int n = v.size();

        std::vector<int> sorted(n);
        int cnt[10] = {};

        for(int i = 0; i < n; ++i) {
                int digit = (v[i] / exp) % 10;
                cnt[digit]++;
        }

        for(int i = 1;i < 10; ++i) {
                cnt[i] += cnt[i-1];
        }

        for(int i = n - 1; i >= 0; --i) {
                int digit = (v[i] / exp) % 10;
                sorted[cnt[digit] - 1] = v[i];
                cnt[digit]--;
        }

        for(int i = 0; i < n; ++i) v[i] = sorted[i];
}



void start_radix(std::vector<int>& v){
        
        int mx = -INT_MAX;
        
        int n = v.size();
        for(int i = 0; i < n; ++i) {
                mx = std::max(mx, v[i]);
        }

        for(long long exp = 1; mx / exp != 0; exp*=10) {
                helper(v,exp);
        }
        
}


void custom_sort(std::vector<int>& v){
        int n = v.size();
        std::vector<int> neg,pos;
        for(int i = 0; i < n; ++i) {
                if(v[i] < 0)neg.push_back(-v[i]);
                else pos.push_back(v[i]);
        }

        start_radix(pos);
        start_radix(neg);

        int idx = 0;
        for(int i = neg.size() - 1; i >= 0; --i) {
                v[idx++]=-neg[i];
        }
        for(int i = 0; i < pos.size(); ++i) {
                v[idx++] = pos[i];
        }
}

//cod template
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

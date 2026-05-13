#include<iostream>
#include<cassert>
#include<vector>
#include<ranges>
#include<algorithm>

//insertion sort
void custom_sort(std::vector<int>& v){
        int n = v.size();

        for(int i = 1; i < n; ++i){
                int tmp = v[i];
                int j = i - 1;

                while(j >= 0 && v[j] > tmp) {
                        v[j + 1] = v[j];
                        j--; 
                }
                v[j + 1] = tmp;
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

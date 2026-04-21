#include<iostream>
#include<cassert>
#include<vector>
#include<ranges>
#include<algorithm>

//insertion sort
void custom_sort(std::vector<int>& v){
        for(size_t i = 1; i < v.size(); ++i){
                size_t j = i;
                while(j > 0 && v[j - 1] > v[j]){
                        std::swap(v[j - 1], v[j]);
                        j--;
                }
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

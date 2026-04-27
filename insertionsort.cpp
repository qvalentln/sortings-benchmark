#include<iostream>
#include<cassert>
#include<vector>
#include<ranges>
#include<algorithm>

//insertion sort
void custom_sort(std::vector<int>& v, int st, int dr){
        for(size_t i = st + 1; i < dr; ++i){
                int tmp = v[i];
                size_t j = i - 1;

                while(j >= st && v[j] > tmp) {
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

        custom_sort(a, 0, n - 1);

        assert(std::ranges::is_sorted(a));

        for(int x : a){
                std::cout<<x<<' ';
        }
        return 0;

}

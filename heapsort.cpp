#include<iostream>
#include<cassert>
#include<vector>
#include<ranges>
#include<algorithm>




void siftDown(std::vector<int>& a, int root, int st, int end);


//heap sort
void custom_sort(std::vector<int>& v, int st, int dr){
        size_t n = dr - st + 1;
        
        for (int i = st + (n / 2) - 1; i >= st; --i) {
                siftDown(v,i,st,dr);
        }

        int curr_end = dr;
        while(curr_end > st) {
                std::swap(v[st], v[curr_end]);

                curr_end--;

                siftDown(v,st,st,curr_end);
        }

}

//parent(i) = (i - 1) / 2
//leftnode(i) = 2 * i + 1;
//rightnode(i) = 2 * i + 2;

void siftDown(std::vector<int>& a, int root, int st, int end) {
        while(true){
                int left = st + 2 * (root - st) + 1;
                int right = st + 2 * (root - st) + 2;
                int iswap = root;

                if(left <= dr && a[left] > a[iswap]){
                        iswap = left;

                }
                if(iswap == root) break;
                swap(a[root], a[iswap]);
                root=iswap;
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

        custom_sort(a,0,n-1);

        assert(std::ranges::is_sorted(a));

        for(int x : a){
                std::cout<<x<<" ";
        }
        return 0;

}

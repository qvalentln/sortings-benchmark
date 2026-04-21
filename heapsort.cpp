#include<iostream>
#include<cassert>
#include<vector>
#include<ranges>
#include<algorithm>


void heapify(std::vector<int>& a);

void siftDown(std::vector<int>& a, int root, int end);


//heap sort
void custom_sort(std::vector<int>& v){
        size_t n = v.size();
        
        heapify(v);
        int end = n;
        while(end > 1) {
                end--;
                std::swap(v[end], v[0]);
                siftDown(v, 0, end);
        }

}

//parent(i) = (i - 1) / 2
//leftnode(i) = 2 * i + 1;
//rightnode(i) = 2 * i + 2;

void heapify(std::vector<int>& a) {
        size_t n = a.size();
        //start = parent(i - 1) - 1
        int start = (n - 2) / 2 + 1;

        while(start > 0) {
                //last non-heap node
                siftDown(a, start, n);
                start--;
        }
}

void siftDown(std::vector<int>& a, int root, int end){
        while(2 * root + 1 < end) {
                int child = 2 * root + 1;
                if(child + 1 < end && a[child] < a[child + 1]) {
                        child++;
                }
                if(a[root] < a[child]) {
                        std::swap(a[root], a[child]);
                        root = child;
                }
                else {
                        return;
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

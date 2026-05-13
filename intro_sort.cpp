#include <fstream>
#include <chrono>

#include <vector>
#include <cmath>
#include <iostream>
#include <cassert>

#include <algorithm> 
#include <ranges>
void insertion_sort(std::vector<int>& v, int st, int dr){
        for(int i = st + 1; i <= dr; ++i){
                int tmp = v[i];
                int j = i - 1;
 
                while(j >= st && v[j] > tmp) {
                        v[j + 1] = v[j];
                        j--; 
                }
                v[j + 1] = tmp;
        }
}

void siftDown(std::vector<int>& a, int root, int st, int end);

void heap_sort(std::vector<int>& v, int st, int dr){
    size_t n = dr - st + 1;
    
    for (int i = st + (n / 2) - 1; i >= st; i--)
        siftDown(v, i, st, dr);

    int curr_end = dr;
    while(curr_end > st) {
        std::swap(v[st], v[curr_end]);

        curr_end--;

        siftDown(v,st,st,curr_end);
    }

}

void siftDown(std::vector<int>& a, int root, int st, int end) {
        while(true){
                int left = st + 2 * (root - st) + 1;
                int right = st + 2 * (root - st) + 2;
                int iswap = root;

                if(left <= end && a[left] > a[iswap]){
                        iswap = left;

                }

                if(right <= end && a[right] > a[iswap]){
                        iswap = right;

                }
                if(iswap == root) break;
                std::swap(a[root], a[iswap]);
                root=iswap;
        }

}


int pivot(std::vector<int> &a,int st,int dr) {  	
    int pivot = a[(st + dr) / 2];
    int i = st - 1;
    int j = dr + 1;

    while (true) {
        do { i++; } while (a[i] < pivot);
        do { j--; } while (a[j] > pivot);

        if (i >= j)
            return j;

        std::swap(a[i], a[j]);
    }
}

void intro_sort_helper(std::vector<int>& a,int st,int dr,int maxdepth){
    int n=dr-st+1;
    if(n<17){
        insertion_sort(a,st,dr);
        return;
    }else if(maxdepth == 0){
        heap_sort(a,st,dr);
        return;
    }else{
        if (st >= dr) return;
        int pivot_idx=pivot(a,st,dr);

        if (pivot_idx <= st) pivot_idx = st;
        if (pivot_idx >= dr) pivot_idx = dr - 1;

        intro_sort_helper(a,st,pivot_idx,maxdepth-1);
        intro_sort_helper(a,pivot_idx+1,dr,maxdepth-1);
    }
}

void intro_sort(std::vector<int>& a,int st,int dr){
    int maxdepth = 2 * static_cast<int>(std::log2(dr-st+1));
    intro_sort_helper(a,st,dr,maxdepth);
}



int main() {
    std::ifstream file("teste.txt");

    std::ios::sync_with_stdio(false);
    file.tie(nullptr);

    int n;
    file >> n;
    std::vector<int> a(n);
    for (int& x : a) {
        file >> x;
    }
    void(*custom_sort)(std::vector<int>&,int,int);
    custom_sort=intro_sort;

    auto start = std::chrono::high_resolution_clock::now();

    custom_sort(a,0,a.size()-1);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    assert(std::ranges::is_sorted(a));
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}

#include <fstream>
#include <chrono>

#include <vector>
#include <cmath>
#include <iostream>
#include <cassert>

#include <algorithm> 
#include <ranges>

#include <random>

inline void swap(int &a,int &b){
    int aux=a;
    a=b;
    b=aux;
}
int pivot(std::vector<int>& a, int st, int dr) {
    int mid= (st+dr)/2;
    int pivot=a[mid];

    int i = st - 1;
    int j = dr + 1;

    while (true) {
        do { i++; } while (a[i] < pivot);
        do { j--; } while (a[j] > pivot);

        if (i >= j) return j;
        swap(a[i], a[j]);
    }
}

void quick_sort(std::vector<int>& a,int st,int dr){
    if (st >= dr) return;
    int pivot_idx=pivot(a,st,dr);
    bool first_half_priority=(pivot_idx-st)>(dr-pivot_idx);
    first_half_priority?quick_sort(a,st,pivot_idx):quick_sort(a,pivot_idx+1,dr);
    (!first_half_priority)?quick_sort(a,st,pivot_idx):quick_sort(a,pivot_idx+1,dr);
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
    custom_sort=quick_sort;

    auto start = std::chrono::high_resolution_clock::now();

    custom_sort(a,0,a.size()-1);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    assert(std::ranges::is_sorted(a));
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}

#include <fstream>
#include <chrono>

#include <vector>
#include <cmath>
#include <iostream>
#include <cassert>

#include <algorithm> 
#include <ranges>


void merge(std::vector<int>& a,int st,int mid,int dr,std::vector<int> &temp){

    int i=st;
    int j=mid+1;
    int k=st;
    int n=dr-st+1;
    while(i <= mid && j <= dr){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    while(i <= mid){
        temp[k++] = a[i++];
    }while(j <= dr){
        temp[k++] = a[j++];
    }
    for(int i=st;i<=dr;i++){
        a[i]=temp[i];
    }
}
void merge_sort_helper(std::vector<int>& a,int st,int dr,std::vector<int> &temp){
    if(st>=dr){
        return;
    }
    int mid=(st+dr)/2;
    merge_sort_helper(a,st,mid,temp);
    merge_sort_helper(a,mid+1,dr,temp);
    merge(a,st,mid,dr,temp);
}

void merge_sort(std::vector<int>& a,int st,int dr){
    static std::vector<int>temp;
    temp.resize(a.size());
    merge_sort_helper(a,st,dr,temp);
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
    custom_sort=merge_sort;

    auto start = std::chrono::high_resolution_clock::now();

    custom_sort(a,0,a.size()-1);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    assert(std::ranges::is_sorted(a));
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}


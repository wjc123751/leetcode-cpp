// 时间复杂度O(n)
// 数组有序无序都可以
#include <iostream>
#include <vector>
using namespace std;

int SeqSearch(vector<int> arr, int target){
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int SeqSearchSentry(vector<int> arr, int target){
    arr[0] = target;
    int i = arr.size() - 1;
    while (arr[i] != target)
    {
        --i;
    }
    if(i == 0){
        return -1;
    }
    else{
        return i;
    }
}

int main(){
    vector<int> a = {5, 2, 9, 1, 7, 3};
    int target = 0;
    int pos = SeqSearch(a, target);
    pos = SeqSearchSentry(a, target);
    
    return 0;
}
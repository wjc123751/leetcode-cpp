// 平均时间复杂度O(根号n)
// 块间有序 块间二分，块内顺序
#include <iostream>
#include <vector>
using namespace std;

int BlockSearch(vector<int> arr, vector<int> blockMax, vector<int> startIdx, int target){
    int blockNum = blockMax.size();
    int i;
    int l = 0;
    int r = blockNum - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(blockMax[mid] >= target){
            i = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    int begin = startIdx[i];
    int end;
    if(i == blockNum -1){
        end = arr.size() - 1;
    }
    else{
        startIdx[i + 1] - 1;
    }
    for(int j = begin; j <= end; ++j){
        if(arr[j] == target){
            return j;
        }
    }
    return -1;
}

int main()
{
    // 原数组：分3块
    // 第0块：0~2    最大值22
    // 第1块：3~5    最大值48
    // 第2块：6~8    最大值96
    vector<int> arr = {12, 5, 22, 31, 18, 48, 65, 77, 96};
    vector<int> blockMax = {22, 48, 96};
    vector<int> startIdx = {0, 3, 6};

    int pos = BlockSearch(arr, blockMax, startIdx, 48);
    if (pos != -1)
        printf("找到，下标：%d\n", pos);
    else
        printf("未找到\n");

    return 0;
}
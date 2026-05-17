#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int quick_select(vector<int> &nums, int l, int r, int k){
//         if (l == r){
//             return nums[k];
//         }
//         int pivot = nums[(l+r-1) / 2];
//         int i = l, j = r;
//         while(i < j){
//             while (nums[i] < pivot){
//                 i++;
//             }
//             while (nums[i] > pivot){
//                 j--;
//             }
//             if (i < j){
//                 swap(nums[i],nums[j]);
//             }
//         }
//         if (k <= j){
//             return quick_select(nums,l,j,k);
//         }
//         else{
//             return quick_select(nums,j+1,r,k);
//         }

//     }

//     int findKthLargest(vector<int>& nums, int k) {
//         int n = nums.size();
//         return quick_select(nums,0,n-1,n-k);
//     }
// };


int quick_select(vector<int> &nums, int l, int r, int k){
    if (l == r){
        return nums[l]; 
    }

    int pivot = nums[l + (r- l) /2];
    int i = l - 1;
    int j = r + 1;

    while(i < j){
        do i++; while (nums[i] < pivot);
        do j--; while (nums[j] > pivot);

        if (i < j){
            swap(nums[i], nums[j]);
        }
    }

    if (k <= j){
        return quick_select(nums, l, j, k);
    }
    else{
        return quick_select(nums, j+1, r, k);
    }
}
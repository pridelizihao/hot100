#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;


// void quick_sort(vector<int> & nums,int l,int r){
//     if (l >= r){
//         return;
//     }
//     else{
//         int pivot = nums[l+(r-l)/2];
//         int i = l - 1;
//         int j = r + 1;
//         while(true){
//             do{++i; } while (nums[i] < pivot);
//             do{--j; } while (nums[j] > pivot);
//             if (i >= j) break;
//             swap(nums[i], nums[j]); 
//         }
//         quick_sort(nums,l,j);
//         quick_sort(nums,j+1,r);
//     }
// }


//  快排的板子，可以记住
// void quick_sort(vector<int> &nums,int l,int r){
//     if (l >= r){
//         return;
//     }
//     int pivot = nums[l+(r-l)/2];
//     int i = l - 1;
//     int j = r + 1;
//     while(i < j){
//         do{ i++; } while ( nums[i] < pivot );
//         do{ j--; } while ( nums[j] > pivot );
//         if (i < j){ swap(nums[i],nums[j]);}
//     }

//     quick_sort(nums,l,j);
//     quick_sort(nums,j+1,r);
// }


int main(){
    vector<int> nums;
    cout << "请输入数组元素，以空格分隔，输入-1结束：" << endl;
    
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    while (ss >> num ) {
        nums.push_back(num);
    }

    // quick_sort(nums, 0, nums.size() - 1);
    sort(nums.begin(), nums.end());
    cout << "排序后：" << endl;
    for (int x : nums) cout << x << " ";
    cout << endl;
    return 0;

}
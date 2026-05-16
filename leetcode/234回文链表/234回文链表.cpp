#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// 纯暴力解法，把链表转化为数组，然后判断数组是否是回文串
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int> vals;
//         while(head != nullptr){
//             vals.push_back(head->val);
//             head = head->next;
//         }
//         for(int i = 0, j = (int)vals.size() - 1; i<j; i++, j--){
//             if (vals[i] != vals[j]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };



//也可以使用快慢指针+翻转链表
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *p = slow, *q = nullptr;
        while(p != nullptr){
            ListNode *n = p->next;
            p->next = q;
            q = p;
            p = n;
        }

        p = head;
        while(q != nullptr){
            if (q->val != p->val){
                return false;
            }
            p = p->next;
            q = q->next;
        }

        return true;
    }
};
/**
 * 40. 最小的k个数
 * https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
 */

#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if(k == 0 || arr.size() == 0){
            return res;
        }
        priority_queue<int> qu;
        for(int i = 0; i < k; ++i){
            qu.push(arr[i]);
        }
        int len = arr.size();
        for(int i = k; i < len; ++i){
            if(qu.top() > arr[i]){
                qu.pop();
                qu.push(arr[i]);
            }
        }
        for(int i = 0; i < k; ++i){
            res.emplace_back(qu.top());
            qu.pop();
        }
        return res;
    }
};

class Solution {
private:
    int partition(vector<int>& arr, int l, int r){
        int pivor = arr[r];
        int i = l - 1;
        for(int j = l; j < r; ++j){
            if(arr[j] <= pivor){
                swap(arr[++i], arr[j]);
            }
        }
        swap(arr[++i], arr[r]);
        return i;
    }

    void quickSort(vector<int>& arr, int l, int r, int k){
        int pivorIndex = partition(arr, l, r);
        int num = pivorIndex - l + 1;
        if(num == k){
            return;
        }else if(num > k){
            quickSort(arr, l, pivorIndex - 1, k);
        }else{
            quickSort(arr, pivorIndex + 1, r, k - num);
        }
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if(k == 0 || arr.size() == 0){
            return res;
        }
        quickSort(arr, 0, arr.size() - 1, k);
        for(int i = 0; i < k; ++i){
            res.emplace_back(arr[i]);
        }
        return res;
    }
};
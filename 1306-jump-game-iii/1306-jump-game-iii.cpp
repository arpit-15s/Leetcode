class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if(start >= n || start < 0 || arr[start] == -1) return false;
        if(arr[start] == 0) return true;
        int temp = arr[start];
        arr[start] = -1;
        return canReach(arr, start + temp) | canReach(arr, start - temp);
    }
};
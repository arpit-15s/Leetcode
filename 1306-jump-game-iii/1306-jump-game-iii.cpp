class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0) return true;
        int n = arr.size();
        vector<bool> flag(n, false);
        queue<int> q;
        q.push(start);
        flag[start] = true;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            int right = top + arr[top];
            int left = top - arr[top];
            if(right < n && flag[right] == false){
                if(arr[right] == 0) return true;
                q.push(right);
                flag[right] = true;
            }
            if(left >= 0 && flag[left] == false){
                if(arr[left] == 0) return true;
                q.push(left);
                flag[left] = true;
            }
        }
        return false;
    }
};
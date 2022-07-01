class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b){
            return a[1] > b[1];
        });
        int count = 0;
        int res = 0;
        for(int i = 0; i < n; i++){
            
            if(count == truckSize) return res;
            if(boxTypes[i][0] > (truckSize - count)){
                res += ((truckSize - count) * boxTypes[i][1]);
                count = truckSize;
            }
            else{
                res += (boxTypes[i][0] * boxTypes[i][1]);
                count += boxTypes[i][0];
            }
            // cout << count << " " << res << endl;
        }
        // for(vector<int> i: boxTypes){
        //     for(int j: i)
        //         cout << j << " ";
        //     cout << endl;
        // } 
        return res;
    }
};
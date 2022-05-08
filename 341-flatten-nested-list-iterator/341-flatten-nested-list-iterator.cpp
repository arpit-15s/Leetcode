/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> flatList;
    int i = 0;
public:
    
    void helper(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i = 0; i < n; i++){
            if(nestedList[i].isInteger()){
                flatList.push_back(nestedList[i].getInteger());
            }
            else{
                helper(nestedList[i].getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    
    int next() {
        if(i < flatList.size()){
            i++;
            return flatList[i - 1];
        }
        return -1;
    }
    
    bool hasNext() {
        return i < flatList.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
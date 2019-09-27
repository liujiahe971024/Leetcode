/*
Jiahe Liu
liujiahe971024@gmail.com
09/26/2019

1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>m;
        int first = 0;
        int second = 0;
        vector<int> s;
        for(int i = 0; i < nums.size(); i++){
            m.insert(make_pair(nums[i], i));
        }
        while(true){
            int tar = target - nums[first];
            if(m.find(tar) != m.end() && m.find(tar)->second != first){
                second = m.find(tar)->second;
                break;
            }
            first++;
        }
        s.push_back(first);
        s.push_back(second);
        return s;
    }
};
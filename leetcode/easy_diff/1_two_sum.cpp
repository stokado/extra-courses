// Problem

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

#include <iostream>
#include <vector>

#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums.size(); j++){
                if (j != i && nums[i] + nums[j] == target){
                    answer.push_back(i);
                    answer.push_back(j);
                }
            }
        }
        return answer;
}

int main(){
    vector <int> nums {2, 7, 11, 15};
    int target = 9;
    vector <int> answer = twoSum(nums, target);
    for (const auto& item : answer){
        cout << item << ' ';
    }   
    return 0;
}
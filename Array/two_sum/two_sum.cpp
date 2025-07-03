#include <vector>
#include <iostream>
using namespace std;
//1. Two sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0 ; i<nums.size()-1 ; i++){
            for(int j=i+1 ; j<nums.size() ; j++){
                if(nums[i] + nums[j] == target) return {i,j} ;
            }
        }
        return {};
    }
};

//the time complexity is O(ij)

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}
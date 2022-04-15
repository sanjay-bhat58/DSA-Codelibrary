class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int arr_size = nums.size();
        k = k % arr_size;;
        vector<int> temp(nums);
        for(int i=0;i<arr_size;i++)
            nums[i] = temp[(arr_size-k+i)%arr_size];
    }
};
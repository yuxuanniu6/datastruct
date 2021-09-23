class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 如果目标值存在返回下标，否则返回 -1
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        // write code here
        int index = -1;
        int end = nums.size() - 1;
        int begin = 0;
        int mid = 0;
        while(begin <= end)
        {
            mid = begin + (end - begin) / 2;
            if(nums[mid] > target)
                end = mid - 1;
            else if(nums[mid] < target)
                begin = mid + 1;
            else
            {
                while(mid != 0 && nums[mid - 1] == nums[mid])//多个相同数目情况，回退索引，取最小的
                    mid--;
                return mid;
            }
        }
        return index;
    }
};
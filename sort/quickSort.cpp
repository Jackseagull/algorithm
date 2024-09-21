#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int left, int right)
{
    int pivot = nums[right];//取最右端为枢轴元素
    int i = left - 1;//当前枢轴元素的下标
    for(int j = left; j<right; j++)
    {
        //关键步骤，当当前元素小于枢轴元素时，交换元素并且枢轴下标加1，当当前元素大于等于枢轴元素时，不作交换
        if(nums[j] < pivot)
        {
            i++;//i指向上一个小于枢轴元素的下标，因此需要加1
            swap(nums[i], nums[j]);//将比枢轴元素小的数交换至下标为i的位置
        }
    }
    swap(nums[right], nums[i+1]);//将基准元素放在枢轴下标，加1是因为i是上一个小于枢轴元素下标，i+1是当前枢轴位置
    return i+1;//返回枢轴元素下标

}

void quickSort(vector<int>& nums, int left, int right)
{
    if(left < right)
    {
        int partitionIndex = partition(nums,left, right);
        quickSort(nums,left, partitionIndex-1);//枢轴元素左区间
        quickSort(nums,partitionIndex+1, right);//枢轴元素右区间
    }
}

int main() {
    std::vector<int> nums = {10,9,8,7,6,5,4,3,2,1};
    quickSort(nums, 0, nums.size()-1);

    for (int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}

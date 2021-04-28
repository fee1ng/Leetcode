class Solution {
public:
    //局部有序后的第一个无序数字
    //如果数组根本不旋转，则返回第一个数字
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        if (n == 0)
            return -1;
        for (int i = 0;i < n - 1;i++)
        {
            if (numbers[i] > numbers[i + 1])
                return numbers[i + 1];
        }
        return numbers[0];
    }
};

class Solution {
public:
    //二分法
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int low = 0, high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (numbers[mid] < numbers[high])
            {
                high = mid;
            }
            else if (numbers[mid] > numbers[high])
            {
                low = mid + 1;
            }
            else
                high -= 1;
        }
        return numbers[low];
    }

};
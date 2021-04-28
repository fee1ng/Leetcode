class Solution {
public:
    //�ֲ������ĵ�һ����������
    //��������������ת���򷵻ص�һ������
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
    //���ַ�
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
class Solution {
public:
	//二分归并，统计归并中的逆序数字
	//v[j]<v[i],则共有逆序对mid-i+1对
	//A-B   C-D
	//i     j
	//若C<D，由于A-B是有序的，则由C产生的逆序对数为在A-B中尚未被遍历到的数字和
	//考虑mid=j-1，且i为当前遍历的A-B序列中的数字，所以求和时为mid-i+1
	//重点:写一个归并排序
	int count = 0;
	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		vector<int> temp(n);
		MergeSort(0, n - 1, nums, temp);
		return count;
	}
	void Merge(int left, int mid, int right, vector<int>& v, vector<int>& res)
	{
		int i = left;
		int j = mid + 1;
		int k = 0;
		while (i <= mid && j <= right)
		{
			if (v[i] <= v[j])
			{
				res[k++] = v[i];
				i++;
			}
			else
			{
				res[k++] = v[j];
				count += mid + 1 - i;
				j++;
			}
		}
		while (i <= mid)
		{
			res[k++] = v[i];
			i++;
		}
		while (j <= right)
		{
			res[k++] = v[j];
			//count+=mid+1-i;
			j++;
		}
		k = 0;
		// 将合并序列复制到原始序列中
		while (left <= right)
		{
			v[left++] = res[k++];
		}
	}
	void MergeSort(int left, int right, vector<int>& v, vector<int>& temp)
	{
		if (left < right)
		{
			int mid = (left + right) / 2;
			MergeSort(left, mid, v, temp);
			MergeSort(mid + 1, right, v, temp);
			Merge(left, mid, right, v, temp);
		}
	}
};
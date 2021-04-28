class Solution {
public:
	//���ֹ鲢��ͳ�ƹ鲢�е���������
	//v[j]<v[i],���������mid-i+1��
	//A-B   C-D
	//i     j
	//��C<D������A-B������ģ�����C�������������Ϊ��A-B����δ�������������ֺ�
	//����mid=j-1����iΪ��ǰ������A-B�����е����֣��������ʱΪmid-i+1
	//�ص�:дһ���鲢����
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
		// ���ϲ����и��Ƶ�ԭʼ������
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
//结伴作业 快排 李奕辰 2016011331 黄可钊 2016011332 
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int suiji(int left, int right)
{
	srand((unsigned int)time(NULL)); /// 设置随机序列的种子
	return (unsigned int)rand() % (right - left + 1) + left;//返回在一个大于等于left小于等于right的值 
}
void qsort(int *array, int left, int right)//模拟机器人拍序 
{
	if (right - left == 1 && array[left] > array[right]) swap(array[left], array[right]);//若只有两个数，则直接判断大小和位置 
	if (right - left <= 1) return;
	int z = left, y = right, k = suiji(left,right);
	int m = array[k];
	int flag = 0;
	do
	{
		while ((z <= y) && (array[z] <= m))
		{
			if (z <= k) ++z;
			else
			{
				array[k] = array[z];
				++k;
				++z;
				flag = 1;
			}
		}
		int zm = array[z];
		while ((z <= y)&&(array[y] >= m))
		{
			if (y >= k) --y;
			else
			{
				array[k] = array[y];
				--k;
				--y;
				flag = 2;
			}
		}
		if (z <= y)
		{
			if (flag == 2)
			{
				array[z] = array[y];
				array[k] = zm;
				if (z < y)
				{
					--k;
					--y;
				}
			}
			else if (flag == 0)
			{
				array[z] = array[y];
				array[y] = zm;
			}
			else if (flag == 1)
			{
				array[k] = array[y];
				array[y] = zm;
				if (z < y)
				{
					++k;
					++z;
				}
			}
		}
	} while (z < y);
	array[k] = m;
	qsort(array, left, k - 1);
	qsort(array, k + 1, right);
}
void print(int *array, int num)//输出已经拍序数组 
{
	for (int i = 0; i < num; ++i)
		cout << array[i] << ' ';
}
int main()
{
	int e[100];//随机一个数组，测试快速拍序 
	for (int i = 0; i <= 99; ++i)
	{
		e[i] = (unsigned int)rand();
	}
	qsort(e,0,99);
	print(e,100);
	return 0; 
}

//�����ҵ ���� ���ȳ� 2016011331 �ƿ��� 2016011332 
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int suiji(int left, int right)
{
	srand((unsigned int)time(NULL)); /// ����������е�����
	return (unsigned int)rand() % (right - left + 1) + left;//������һ�����ڵ���leftС�ڵ���right��ֵ 
}
void qsort(int *array, int left, int right)//ģ����������� 
{
	if (right - left == 1 && array[left] > array[right]) swap(array[left], array[right]);//��ֻ������������ֱ���жϴ�С��λ�� 
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
void print(int *array, int num)//����Ѿ��������� 
{
	for (int i = 0; i < num; ++i)
		cout << array[i] << ' ';
}
int main()
{
	int e[100];//���һ�����飬���Կ������� 
	for (int i = 0; i <= 99; ++i)
	{
		e[i] = (unsigned int)rand();
	}
	qsort(e,0,99);
	print(e,100);
	return 0; 
}

#define _CRT_SECURE_NO_WARNINGS 1 
#include"Sort.h"
#include"stack.h"
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
// 插入排序
void InsertSort(int* a, int n)
{
	// 注意循环次数 n-1   前i-1个数
	for (int i = 0; i < n - 1; i++)
	{
		int end = i; // 前i-1个数已经排好
		int tmp = a[end + 1]; //保存第i个数,gap = 1直接插入排序
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;//-1 回退
			}
			else
				break;
		}
		a[end + 1] = tmp; //如果交换了，就将空出来的位置给新插入的数
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	//以gap个单位排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//3步比2步快一点
		//gap = gap / 2;
		// 次数也换位n-gap
		for (int i = 0; i < n - gap; i++)
		{
			int end = i; // 前i-1个数已经排好
			int tmp = a[end + gap]; //保存第i个数,gap = 1直接插入排序
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;//-1 回退
				}
				else
					break;
			}
			a[end + gap] = tmp; //如果交换了，就将空出来的位置给新插入的数
		}
	}
}
void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
				maxi = i;
			if (a[i] < a[mini])
				mini = i;
		}
		Swap(&a[mini], &a[begin]); // 将最小值放前面
		if (begin == maxi)
			maxi = mini;
		Swap(&a[maxi], &a[end]); // 将最大值放后面
		++begin;
		--end;
	}
}
// 堆排序
void AdjustDwon(int* a, int n, int root)
{
	int child = 2 * root + 1;
	while (child < n)
	{
		//判断右孩子
		if (child + 1 < n && a[child] < a[child + 1])
		{
			++child;
		}
		// 升序建大堆，找到比父结点大的交换，继续找左右孩子
		if (a[child] > a[root])
		{
			Swap(&a[child], &a[root]);
			root = child;
			child = 2 * root + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//次数，只用找n-1-1 / 2次，左右孩子其中一个大小即可
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1; //向下调整 将第一个结点与最后一个结点置换
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);//堆删除的思想来做
		--end;
	}
}
// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = n; i > 0; --i)
	{
		int exchange = 0; // 判断是否有序
		for (int j = 1; j < i; j++)
		{
			if (a[j - 1] > a[j])
			{
				Swap(&a[j - 1], &a[j]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}
//三数取中
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[right] > a[left])
			return left;
		else
			return right;
	}
}
// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	//有序的话，时间复杂度是o(n^2)，效率比较低，所以需要进行三数取中
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);//将中位数放到left位置上
	int keyi = left;
	while (left < right)
	{
		//往左走找小的
		while (left < right && a[right] >= a[keyi])
			--right;
		//往右走找大的
		while (left < right && a[left] <= a[keyi])
			++left;
		//找到交换
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]); // 相遇还要交换一次
	return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]); // 三数取中进行交换
	int key = a[left]; //key值
	int hole = left; //坑位
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[hole] = a[right]; //将值换到坑位处
		hole = right; //坑位索引替换
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole; //取的坑位返回
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int keyi = left;
	int prev = left;
	int cur = prev + 1; // 思想，cur在前找大于key的，prev++，在交换prev跟cur的值
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev <= cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	//if (left < right)
	//{
	//	int keyi = PartSort1(a, left, right);// 找到中间索引
	//	QuickSort(a, left, keyi - 1); //递归整理左边
	//	QuickSort(a, keyi + 1, right); // 递归整理右边
	//}
	//if (left < right)
	//{
	//	int keyi = PartSort2(a, left, right);// 找到中间索引
	//	QuickSort(a, left, keyi - 1); //递归整理左边
	//	QuickSort(a, keyi + 1, right); // 递归整理右边
	//}
	if (left < right)
	{
		int keyi = PartSort3(a, left, right);// 找到中间索引
		QuickSort(a, left, keyi - 1); //递归整理左边
		QuickSort(a, keyi + 1, right); // 递归整理右边
	}
}
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	Stack s;
	StackInit(&s);
	StackPush(&s, right);// 右先压栈，左在压栈
	StackPush(&s, left);
	while (!StackEmpty(&s))
	{
		int begin = StackTop(&s);
		StackPop(&s);
		int end = StackTop(&s);
		StackPop(&s);
		int keyi = PartSort1(a, begin, end);
		if (keyi + 1 < end)
		{
			StackPush(&s, end); // 分成 begin -- keyi-1   keyi+1 -- end 
			StackPush(&s, keyi + 1);
		}
		if (keyi - 1 > begin)
		{
			StackPush(&s, keyi - 1);
			StackPush(&s, begin);
		}
	}
	StackDestroy(&s);// 不用记得销毁栈
}
// 归并排序递归实现
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return; //区间变为 11就停止递归
	int mid = left + (right - left) / 2; // 中间区间
	_MergeSort(a, left, mid, tmp); // 前区间，递归分成多个小区间
	_MergeSort(a, mid + 1, right, tmp); // 后区间
	// 区间索引范围
	int begin1 = left, end1 = mid; // 前区间索引
	int begin2 = mid + 1, end2 = right; // 后区间索引
	int index = left; //索引用来排序
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[index] = a[begin1];//新数组tmp装排好序的值
			index++;
			begin1++;
		}
		else
		{
			tmp[index] = a[begin2];
			index++;
			begin2++;
		}

	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//第一次调用函数的区间是 0 -- n-1  不是  0 -- n 注意
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i]; //拷贝给原数组
	}
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
void _MergeSortNonR(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	// 区间索引范围
	int begin1 = left, end1 = mid; // 前区间索引
	int begin2 = mid + 1, end2 = right; // 后区间索引
	int index = left; //索引用来排序
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[index] = a[begin1];//新数组tmp装排好序的值
			index++;
			begin1++;
		}
		else
		{
			tmp[index] = a[begin2];
			index++;
			begin2++;
		}

	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//第一次调用函数的区间是 0 -- n-1  不是  0 -- n 注意
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i]; //拷贝给原数组
	}
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n); //临时数组
	assert(tmp != NULL);
	int gap = 1; //区间范围控制
	while (gap < n)
	{
		for (int i = 0; i < n; i += gap)
		{
			int left = i, right = 2 * gap + i - 1;//左右范围控制
			// 注意，需要检查right的范围
			if (right >= n)
				right = n - 1;//范围最多到 n - 1
			_MergeSort(a, left, right, tmp);
		}
		gap *= 2;
	}
	free(tmp); //释放开辟的动态空间
}
// 计数排序
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] < min)
			min = a[i]; // 统计最小值到最大值的范围,开辟range个空间，避免浪费
		if (a[i] > max)
			max = a[i];
	}
	int range = max - min + 1; //开辟的空间个数
	//int* count = malloc(sizeof(int) * range);
	int* count = calloc(range, sizeof(int)); //最好用calloc，自动初始化为0
	assert(count != NULL);
	for (int i = 0; i < n; i++) 
	{
		count[a[i] - min]++;// 统计元素出现的次数
	}
	int i = 0;
	// 将出现的元素依次装入数组中
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}
	free(count); //记得释放开辟的空间
}
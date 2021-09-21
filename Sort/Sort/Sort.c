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
// ��������
void InsertSort(int* a, int n)
{
	// ע��ѭ������ n-1   ǰi-1����
	for (int i = 0; i < n - 1; i++)
	{
		int end = i; // ǰi-1�����Ѿ��ź�
		int tmp = a[end + 1]; //�����i����,gap = 1ֱ�Ӳ�������
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;//-1 ����
			}
			else
				break;
		}
		a[end + 1] = tmp; //��������ˣ��ͽ��ճ�����λ�ø��²������
	}
}

// ϣ������
void ShellSort(int* a, int n)
{
	//��gap����λ����
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//3����2����һ��
		//gap = gap / 2;
		// ����Ҳ��λn-gap
		for (int i = 0; i < n - gap; i++)
		{
			int end = i; // ǰi-1�����Ѿ��ź�
			int tmp = a[end + gap]; //�����i����,gap = 1ֱ�Ӳ�������
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;//-1 ����
				}
				else
					break;
			}
			a[end + gap] = tmp; //��������ˣ��ͽ��ճ�����λ�ø��²������
		}
	}
}
void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
// ѡ������
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
		Swap(&a[mini], &a[begin]); // ����Сֵ��ǰ��
		if (begin == maxi)
			maxi = mini;
		Swap(&a[maxi], &a[end]); // �����ֵ�ź���
		++begin;
		--end;
	}
}
// ������
void AdjustDwon(int* a, int n, int root)
{
	int child = 2 * root + 1;
	while (child < n)
	{
		//�ж��Һ���
		if (child + 1 < n && a[child] < a[child + 1])
		{
			++child;
		}
		// ���򽨴�ѣ��ҵ��ȸ�����Ľ��������������Һ���
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
	//������ֻ����n-1-1 / 2�Σ����Һ�������һ����С����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1; //���µ��� ����һ����������һ������û�
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);//��ɾ����˼������
		--end;
	}
}
// ð������
void BubbleSort(int* a, int n)
{
	for (int i = n; i > 0; --i)
	{
		int exchange = 0; // �ж��Ƿ�����
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
//����ȡ��
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
// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right)
{
	//����Ļ���ʱ�临�Ӷ���o(n^2)��Ч�ʱȽϵͣ�������Ҫ��������ȡ��
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);//����λ���ŵ�leftλ����
	int keyi = left;
	while (left < right)
	{
		//��������С��
		while (left < right && a[right] >= a[keyi])
			--right;
		//�������Ҵ��
		while (left < right && a[left] <= a[keyi])
			++left;
		//�ҵ�����
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]); // ������Ҫ����һ��
	return left;
}
// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]); // ����ȡ�н��н���
	int key = a[left]; //keyֵ
	int hole = left; //��λ
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[hole] = a[right]; //��ֵ������λ��
		hole = right; //��λ�����滻
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole; //ȡ�Ŀ�λ����
}
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int keyi = left;
	int prev = left;
	int cur = prev + 1; // ˼�룬cur��ǰ�Ҵ���key�ģ�prev++���ڽ���prev��cur��ֵ
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
	//	int keyi = PartSort1(a, left, right);// �ҵ��м�����
	//	QuickSort(a, left, keyi - 1); //�ݹ��������
	//	QuickSort(a, keyi + 1, right); // �ݹ������ұ�
	//}
	//if (left < right)
	//{
	//	int keyi = PartSort2(a, left, right);// �ҵ��м�����
	//	QuickSort(a, left, keyi - 1); //�ݹ��������
	//	QuickSort(a, keyi + 1, right); // �ݹ������ұ�
	//}
	if (left < right)
	{
		int keyi = PartSort3(a, left, right);// �ҵ��м�����
		QuickSort(a, left, keyi - 1); //�ݹ��������
		QuickSort(a, keyi + 1, right); // �ݹ������ұ�
	}
}
// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right)
{
	Stack s;
	StackInit(&s);
	StackPush(&s, right);// ����ѹջ������ѹջ
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
			StackPush(&s, end); // �ֳ� begin -- keyi-1   keyi+1 -- end 
			StackPush(&s, keyi + 1);
		}
		if (keyi - 1 > begin)
		{
			StackPush(&s, keyi - 1);
			StackPush(&s, begin);
		}
	}
	StackDestroy(&s);// ���üǵ�����ջ
}
// �鲢����ݹ�ʵ��
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return; //�����Ϊ 11��ֹͣ�ݹ�
	int mid = left + (right - left) / 2; // �м�����
	_MergeSort(a, left, mid, tmp); // ǰ���䣬�ݹ�ֳɶ��С����
	_MergeSort(a, mid + 1, right, tmp); // ������
	// ����������Χ
	int begin1 = left, end1 = mid; // ǰ��������
	int begin2 = mid + 1, end2 = right; // ����������
	int index = left; //������������
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[index] = a[begin1];//������tmpװ�ź����ֵ
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
	//��һ�ε��ú����������� 0 -- n-1  ����  0 -- n ע��
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i]; //������ԭ����
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
	// ����������Χ
	int begin1 = left, end1 = mid; // ǰ��������
	int begin2 = mid + 1, end2 = right; // ����������
	int index = left; //������������
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[index] = a[begin1];//������tmpװ�ź����ֵ
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
	//��һ�ε��ú����������� 0 -- n-1  ����  0 -- n ע��
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i]; //������ԭ����
	}
}
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n); //��ʱ����
	assert(tmp != NULL);
	int gap = 1; //���䷶Χ����
	while (gap < n)
	{
		for (int i = 0; i < n; i += gap)
		{
			int left = i, right = 2 * gap + i - 1;//���ҷ�Χ����
			// ע�⣬��Ҫ���right�ķ�Χ
			if (right >= n)
				right = n - 1;//��Χ��ൽ n - 1
			_MergeSort(a, left, right, tmp);
		}
		gap *= 2;
	}
	free(tmp); //�ͷſ��ٵĶ�̬�ռ�
}
// ��������
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] < min)
			min = a[i]; // ͳ����Сֵ�����ֵ�ķ�Χ,����range���ռ䣬�����˷�
		if (a[i] > max)
			max = a[i];
	}
	int range = max - min + 1; //���ٵĿռ����
	//int* count = malloc(sizeof(int) * range);
	int* count = calloc(range, sizeof(int)); //�����calloc���Զ���ʼ��Ϊ0
	assert(count != NULL);
	for (int i = 0; i < n; i++) 
	{
		count[a[i] - min]++;// ͳ��Ԫ�س��ֵĴ���
	}
	int i = 0;
	// �����ֵ�Ԫ������װ��������
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
	}
	free(count); //�ǵ��ͷſ��ٵĿռ�
}
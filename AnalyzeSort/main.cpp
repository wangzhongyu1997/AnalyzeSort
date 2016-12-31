#include<iostream>
#include<Windows.h>
#include<fstream>
#include<ctime>
int Lenth =0;
long compares = 0, moves = 0;
struct AnalyzeResult
{
	clock_t time;
	int compares;
	int move;
};

void swap(int &a,int &b);
void getRands(int *a);
void set(int *a);
void  copyArr(int *dis,const int*from);

void BubelSort(int *a);
void SelectSort(int *a);
void InsertSortDirectly(int *a);
void QuickSort(int *a, int low, int high);
int Part_of_Quick(int *a, int low, int high);
void ShellSort(int *a);
void Part_of_Shell(int *a, int n);
void HeapSort(int *a);
void HeapAdjusst(int *a, int ad_from, int limit);
void display(int *a);
void out_data(int *a,std::fstream& out);

int main()
{
	std::fstream out;
	out.open("out.txt", std::ios::out);
	int LenthArr[ ] = { 10,100,500,1000 ,10000 };
	clock_t time1, time2;
	
	AnalyzeResult result_Bu[5];
	AnalyzeResult result_Se[5];
	AnalyzeResult result_In[5];
	AnalyzeResult result_Qu[5];
	AnalyzeResult result_Sh[5];
	AnalyzeResult result_He[5];

	for (int i = 0; i < 5; i++)
	{
		Lenth = LenthArr[i];
		std::cout << "分配空间..."<<std::endl;
		int *to_BubelSort = new int[Lenth];
		int *to_SelectSort = new int[Lenth];
		int *to_InsertSortDirectly = new int[Lenth];
		int *to_QuickSort = new int[Lenth];
		int *to_ShellSort = new int[Lenth];
		int *to_HeapSort = new int[Lenth];
		int *Arrs[6] = { to_BubelSort ,to_SelectSort ,to_InsertSortDirectly ,to_QuickSort ,to_ShellSort ,to_HeapSort };
		std::cout << "分配随机数..." << std::endl;
	
		Sleep(500);
		getRands(to_BubelSort);
		out_data(to_BubelSort, out);//写进文本

		std::cout << "复制数据" << std::endl;

		for (int j = 1; j < 6; j++)
		{
			copyArr(Arrs[j], to_BubelSort);
		}

		compares = moves = 0;
		time1 = clock();
		BubelSort(to_BubelSort);
		time2 = clock();
		result_Bu[i].time = time2 - time1;
		result_Bu[i].compares = compares;
		result_Bu[i].move = moves;
		std::cout << "排序并分析结果\n\n";
		//display(to_BubelSort);

		compares = moves = 0;
		time1 = clock();
		QuickSort(to_QuickSort,0,Lenth-1);
		time2 = clock();
		result_Qu[i].time = time2 - time1;
		result_Qu[i].compares = compares;
		result_Qu[i].move = moves;

		compares = moves = 0;
		time1 = clock();
		SelectSort(to_SelectSort);
		time2 = clock();
		result_Se[i].time = time2 - time1;
		result_Se[i].compares = compares;
		result_Se[i].move = moves;

		compares = moves = 0;
		time1 = clock();
		HeapSort(to_HeapSort);
		time2 = clock();
		result_He[i].time = time2 - time1;
		result_He[i].compares = compares;
		result_He[i].move = moves;

		compares = moves = 0;
		time1 = clock();
		InsertSortDirectly(to_InsertSortDirectly);
		time2 = clock();
		result_In[i].time = time2 - time1;
		result_In[i].compares = compares;
		result_In[i].move = moves;

		compares = moves = 0;
		time1 = clock();
		ShellSort(to_ShellSort);
		time2 = clock();
		result_Sh[i].time = time2 - time1;
		result_Sh[i].compares = compares;
		result_Sh[i].move = moves;

		for (int i = 0; i < 6; i++)
			delete[] Arrs[i];
	}

	out.close();


	std::cout << "评估结果：第一行是数据规模,之后\n是时间(cpu时钟数).比较次数.移动次数\n";
	std::cout << "\t";
	for (int i = 0; i < 5; i++)
		std::cout << LenthArr[i] << '\t';
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout <<"冒泡";
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_Bu[i].time;
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_Bu[i].compares;
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_Bu[i].move;
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout <<"快排";
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_Qu[i].time;
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_Qu[i].compares;
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_Qu[i].move;
	}
	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << "选择";
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_Se[i].time;
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_Se[i].compares;
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_Se[i].move;
	}
	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << "堆排";
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_He[i].time;
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_He[i].compares;
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_He[i].move;
	}
	std::cout << std::endl;
	std::cout << std::endl;




	std::cout << "直插";
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_In[i].time;
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_In[i].compares;
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_In[i].move;
	}
	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << "希尔";
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_Sh[i].time;
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_Sh[i].compares;
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << '\t' << result_Sh[i].move;
	}
	std::cout << std::endl;
	std::cout << std::endl;


	return 0;

}

void BubelSort(int *a)
{
	bool flag = 1;
	for (int i = 0; i < Lenth; i++)
	{
		flag = 0;
		for (int j = 0; j < Lenth - i - 1; j++)
		{
			compares++;
			if (a[j] > a[j + 1])
			{
				flag = 1;
				swap(a[j], a[j + 1]);
			}
		}
		if (flag == 0)
			return;
	}
}
void SelectSort(int * a)
{
	for (int i = 0; i < Lenth - 1; i++)
	{
		int indexM = i;
		for (int j = i; j < Lenth; j++)
		{
			compares++;
			if (a[indexM] > a[j])
				indexM = j;
		}

		if (indexM != i)
		{
			swap(a[indexM], a[i]);
		}
	}
}
void InsertSortDirectly(int * a)
{
	int now;
	for (int i = 1; i < Lenth; i++)
	{
		now = a[i];//伪哨
		compares++;
		if (a[i] < a[i - 1])
		{
			int j = i-1;
			for (; j >= 0; j--)
			{            
				compares++;
				if (now < a[j])
					a[j + 1] = a[j];
				else
					break;
			}
			a[j+1] = now;
			moves++;
		}
	}
}
void QuickSort(int * a, int low, int high)
{
	if (low < high)
	{
		int mid_index = Part_of_Quick(a, low, high);//mid_index若是区间极值
		QuickSort(a, low, mid_index - 1);
		QuickSort(a, mid_index + 1, high);
	}
}


int Part_of_Quick(int * a, int low, int high)
{/*
 *low是从第0个开始的（从枢轴开始）  // 如果枢轴的选取方式改变，PS:如果跳过枢轴，那么就不能利用这一个特点，同时，跳过枢轴会增加递归深度（作业中偶然发现）
 *交换都是low和high交换，所以枢轴一定会保留在low或high中
 *这就给课本上“最后才把枢轴填上”提供了条件
 */
	int axisData = a[low];
	while (low<high)
	{
		/*for (; a[high] >= axisData&&low < high; high--);  //此处的<仅仅是为了控制等于
		a[low] = a[high];//>=隐含了一步low++放在了下一行（否则就死循环了,另外，减少了一次交换）；high处被赋值后相当于变为空，下一步的增减操作只能是对low并对high处赋值
		for (; a[low] <= axisData&&low<high; low++);
		a[high] = a[low];*/  //如果不是取的a[low]为枢轴，上述算法会出现错误如：45 29 65 50 40 42 90在以 40为枢轴时
		//改一种写法：这种方法比上一种多了一步交换
		for (; a[high] > axisData&&low != high; high--)
			compares++;

		a[low] = a[high];
		moves++;
		low++;
		for (; a[low] < axisData&&low != high; low++)
			compares++;

		a[high] = a[low];
		moves++;
		high--;
	}
	a[low] = axisData;
	moves++;
	return low;
}

void ShellSort(int * a)
{
	int dd[3] = { 5,3,1 };
	for (int i = 0; i < 3; i++)
		Part_of_Shell(a, dd[i]);
}

void Part_of_Shell(int * a, int n)//一趟希尔排序
{
	/*int now;
	for(int i=0;i<n;i++)//控制每个分量的起始点
		for (int j = i+n ; j < Lenth; j += n)//控制当前分量的当前访问点
		{
			now = a[j];
			int k;
			for (k = j - n; k >= i; k-=n)//从当前访问点往前遍历以寻找插入位置
			{
				if (now < a[k])
					a[k + n] = a[k];
				else
					break;
			}
			a[k + n] = now;
		};*/

	for (int i = n; i < Lenth; i++)
	{
		compares++;
		if (a[i] < a[i - n])//这一句话可以不写，但是那样的话使程序更费力
		{
			int now = a[i];
			int j;
			for ( j= i - n; j >= 0; j -= n)
			{
				compares++;
				if (now < a[j])
				{
					a[j + n] = a[j];
					moves++;
				}
				else
					break;
			}
			a[j + n] = now;
			moves++;
		}
	}
}

void HeapSort(int * a)
{
	int n = Lenth - 1;
	for (int i = Lenth / 2 - 1; i >= 0; i--)
		HeapAdjusst(a, i, n);

	for (int i = n; i >0; i--)
	{
		swap(a[0], a[i]);
		HeapAdjusst(a, 0, i-1);
	}
}
void HeapAdjusst(int * a, int ad_from, int limit)
{
	int temp = a[ad_from];
	for (int j = 2 * ad_from+1; j <= limit;)//注意，我的数组是从0开始的
	{
		compares++;
		if (j + 1<= limit && a[j +1] > a[j])
			j++;
		compares++;
		if (temp > a[j])//不可能出现上层是堆而下层不是堆的情况，因为建堆是从下往上调整的；
			break;		//注意从来没有用 a[ad_from]来比较,因为没有写"a[j] = temp;"     
		//（这一步赋值被放在了最后的第"a[ad_from] = temp;"，函数从第"a[ad_from] = a[j];"就注定从第二次循环开始a[ad_from]相当于值为空）

		a[ad_from] = a[j];/*-=-==-=-=-=-=-=-=-=-=注意 这三行=-=-=-=-=-=-=-=-=-=-=-=-=-*/
		moves++;
		//a[j] = temp;/*-=-==-=-=-=-=-=-=-=-=注意 这三行=-=-=-=-=-=-=-=-=-=-=-=-=-*/
		ad_from = j;
		j = j * 2+1;
	}
	a[ad_from] = temp;/*-=-==-=-=-=-=-=-=-=-=注意 这三行=-=-=-=-=-=-=-=-=-=-=-=-=-*/
	moves++;
}
void display(int *a)
{
	for (int i = 0; i < Lenth; i++)
		std::cout << a[i] << '\t';
	std::cout<<std::endl;
}
void out_data(int * a, std::fstream & out)
{
	out << "测试数据：" <<std::endl;
	for (int i = 0; i < Lenth; i++)
		out << a[i] << '\t';
	out <<std::endl<< std::endl;
}
void swap(int & a, int & b)
{
	int t = a;
	a = b;
	b = t;
	moves += 3;
}
void getRands(int *a)
{
	srand(unsigned(clock()));
	for (int i = 0; i < Lenth; i++)
	{
		a[i] = rand()%10000;
		//std::cout << a[i]<<'\t';
	}
}

void  copyArr(int *dis,const int*from)
{
	for (int i = 0; i < Lenth; i++)
	{
		dis[i] = from[i];
	}
}
void set(int *a)
{
	for (int i = 0; i < Lenth; i++)
	{
		std::cin >> a[i];
	}
}
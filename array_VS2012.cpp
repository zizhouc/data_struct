#include "stdafx.h"

typedef struct
{
	int * pBase;  //存储的是数组首元素的地址
	int len;	  //数组所能容纳的最大元素的个数
	int cnt;      //当前数组有效元素的个数
}Arr;

void init_arr(Arr *,int);
bool append(Arr *,int);      //追加
bool insert_arr(Arr *,int ,int );  //插入
bool delete_arr(Arr *,int ,int *);
int  get();
bool is_empty(Arr *);
bool is_full();
void sort_arr(Arr *);
void show_arr(Arr *);
void inversion_arr(Arr *);
void show_status_arr(Arr *);
void sort1_arr(Arr * pArr);

int main(void)
{

Arr arr;
int val;
init_arr(&arr,6);
printf("初始化完毕！\n");

printf("现在数组的状态是：\n");
show_status_arr(&arr);
show_arr(&arr);
printf("\n");

append(&arr,1);    
append(&arr,-43);
append(&arr,3);
append(&arr,-499);
append(&arr,5);
printf("追加完毕！\n");
printf("\n");

printf("现在数组的状态是：\n");
show_status_arr(&arr);
show_arr(&arr);
printf("\n");

inversion_arr(&arr);
printf("现在数组的状态是：\n");
show_status_arr(&arr);
show_arr(&arr);
printf("\n");

sort_arr(&arr);
printf("现在数组的状态是：\n");
show_status_arr(&arr);
show_arr(&arr);
printf("\n");

sort1_arr(&arr);
printf("现在数组的状态是：\n");
show_status_arr(&arr);
show_arr(&arr);
printf("\n");

getchar();
return 0;
}

void init_arr(Arr * pArr,int length)
{
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if(NULL == pArr->pBase)
		{
			printf("动态内存分配失败！\n");
			exit(-1);
	
		}
	else
		{
			pArr->len = length;
			pArr->cnt = 0;
			*(pArr->pBase+0) = 1;
			*(pArr->pBase+1) = 2;
		}
}

bool is_empty(Arr *pArr)
{

	if(pArr->cnt == 0)
		return true;
	else
		return false;

}

void show_arr(Arr * pArr)
{

	if(is_empty(pArr))
		{
			printf("数组内容为空！\n");

		}
	else
		{printf("数组内容为：\n");
			for(int i = 0;i<pArr->cnt;++i)
			{
			
				printf("%d\t",*(pArr->pBase+i));
				printf("\n");

			}
		}
}

bool is_full(Arr *pArr)
{
	if(pArr->len == pArr->cnt)
		return true;
	else
		return false;

}

bool append(Arr *pArr,int val)//追加
{
	if(is_full(pArr))
		return false;

	//不满时追加
	pArr->pBase[(pArr->cnt)++] = val;
	
	return true;
}

void show_status_arr(Arr *pArr)
{
	printf("数组的长度是%d\n",pArr->len);
	printf("数组的有效元素的个数是%d\n",pArr->cnt);
}

bool insert_arr(Arr *pArr,int pos,int val)
{
	if(is_full(pArr))	//如果满了就不能插入
		return false;
	if(pos<1 || pos>pArr->len+1)   //如果要插入的位置小于1，大于最大长度+1
		return false;
	for(int i = pArr->cnt-1;i>=pos-1;--i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = val;
	pArr->cnt += 1;
	return 0;
}

bool delete_arr(Arr * pArr,int pos,int * pVal)
{
	if(is_empty(pArr))	//如果满了就不能插入
		return false;
	if(pos<1 || pos>pArr->cnt)   //如果要插入的位置小于1，大于最大长度+1
		return false;
	*pVal = pArr->pBase[pos-1];
	for(int i=pos;i<pArr->cnt;i++)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	
	}
	pArr->cnt--;

	return true;
}

void inversion_arr(Arr * pArr)
{
int i = 0;
int j = pArr->cnt-1;
int t = 0;
while(i < j) 
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
}

void sort_arr(Arr * pArr)
{
	int i = 0;
	int j = 0;
	int t = 0;
	for(j = 0;j< pArr->cnt-1;j++)
	{
		for(i=0;i<pArr->cnt-j-1;i++)
		{
			if((pArr->pBase[i]) > (pArr->pBase[i+1]))
				{
				t = pArr->pBase[i];
					pArr->pBase[i] = pArr->pBase[i+1];
					pArr->pBase[i+1] = t;

				}
		}	
		}
	}
//下面是自己写的冒泡排序
void sort1_arr(Arr * pArr)
{
	int i = 0;
	int j = 0;
	int t = 0;
	for(j = 0;j<pArr->cnt-1;j++)
	{
		for(i=j+1;i<pArr->cnt;i++)
		{
			if((pArr->pBase[j]) > (pArr->pBase[i]))
			{
				t = *(pArr->pBase+j);
					*(pArr->pBase+j) = *(pArr->pBase+i);
					*(pArr->pBase+i) = t;
			}

		}
	}	
}
	



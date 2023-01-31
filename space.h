#pragma once
/*
* 文件名：space.h
* 文件版本:v1.0
* 编写者：mydream8
* 编写日期：2023.1.24
* 完成日期：
* 文件说明：负责生成棋盘的函数，宏,处理内部棋盘和某些棋盘的全局类型定义
* 编写工具：Visual Studio 2022
* 此程序为开源程序
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define ROW 10 //行
#define LINE 10 //列-建议等于或小于10，否则打印出来非常难看

typedef  const int rowType;//保证行统一按const int处理
typedef const int lineType;//保证列统一按const int处理

typedef short int mineBoxIn;
//作为一个格子的类型

//生成雷
//void makeMine(unsigned int num, int row, int line)
//{
//
//}


//生成雷
//static void makeMine(unsigned int num,mineBoxIn space[ROW][LINE])
//{
//	//mineBoxIn* addMine=(void*)malloc((size_t)num*sizeof(mineBoxIn*));//保存每个雷的位置
//	//if (!addMine)//保证动态内存分配正确
//	//{
//	//	puts("程序错误!");
//	//	assert(addMine);
//	//}
//	//for (int i = 0; i < num; i++)//初始化
//	//{
//	//	addMine[i] = NULL;
//	//}
//
//	if (num == 0)
//	{
//		return;
//	}
//	else if (num >= ROW * LINE)
//	{
//		puts("传参错误，函数makeMine，参数num");
//		assert(0);
//	}
//
//	while (1)
//	{
//		srand((unsigned int)time(NULL));//对一列进行种子生成
//		int mineYAxis = (rand()%LINE);
//		srand((unsigned int)time(NULL));//对一行进行种子生成
//		int mineXAxis = (rand()%ROW);
//		if (space[mineXAxis][mineYAxis] != MINE)//判断这个地方是否已生成雷
//		{
//			space[mineXAxis][mineYAxis] = MINE;
//			break;
//		}
//		else
//		{
//			continue;
//		}
//	}
//	
//	makeMine(num - 1, space);
//}
//
////生成雷旁边的数字格子
//static void makeNum(mineBoxIn space[ROW][LINE])
//{
//
//	//两个for找雷
//	for (int i = 0; i < ROW; i++)//从第0行开始检查
//	{
//		for (int j = 0; j < LINE; j++)//从第0列开始检查
//		{
//			if (space[i][j] == MINE)//如果找到了就进行操作
//			{
//				if (i == 0)//把上面两个角在这里处理
//				{
//					space[i + 1][j] += 1;
//					if (0 != j)//不是左上角
//					{
//						//对左边进行操作
//						space[i][j - 1] += 1;
//						space[i + 1][j - 1] += 1;
//						
//					}
//					if (LINE != j)//不是右上角
//					{
//						//对右边进行操作
//						space[i][j + 1] += 1;
//						space[i + 1][j + 1] += 1;
//					}
//					/*continue;*/
//				}
//				else if (ROW == i)//下边一排格子，下面两个角在这里处理
//				{
//					space[i - 1][j] += 1;
//					if (0 != j)//不是左下角
//					{
//						space[i][j - 1]++;
//						space[i - 1][j - 1]++;
//					}
//					else if (LINE != j)//不是右下角
//					{
//						space[i][j + 1]++;
//						space[i - 1][j - 1]++;
//					}
//				}
//				else if (0 == j)//左边那一排
//				{
//					space[i - 1][j]++;
//					space[i - 1][j + 1]++;
//					space[i][j + 1]++;
//					space[i + 1][j + 1]++;
//					space[i + 1][j]++;
//				}
//				else if (LINE == j)//右边那一排
//				{
//					space[i - 1][j]++;
//					space[i - 1][j - 1]++;
//					space[i][j - 1]++;
//					space[i + 1][j - 1]++;
//					space[i + 1][j]++;
//				}
//				else//中间
//				{
//					//如诗般优雅的代码:)
//					space[i - 1][j]++;//上面
//					space[i - 1][j - 1]++;//左上角
//					space[i][j - 1]++;//左边
//					space[i + 1][j - 1]++;//左下角
//					space[i + 1][j]++;//下面
//					space[i - 1][j + 1]++;//右上角
//					space[i][j + 1]++;//右边
//					space[i + 1][j + 1]++;//右下角
//				}
//			}
//		}
//	}
//}

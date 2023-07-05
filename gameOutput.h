#pragma once

#include <stdio.h>
#include "space.h"
#include <stdbool.h>
#include "info.h"

/*
* 文件名：gameInputOutput.h
* 文件版本:v1.0
* 编写者：mydream8
* 编写日期：2023.1.24
* 完成日期：2023.1.31
* 文件说明：负责游戏输出的函数，宏,处理外部棋盘,原来打算包含游戏输入函数，但最后觉得单独放在gameInput.h里
* 编写工具：Visual Studio 2022
* 此程序为开源程序
*/

//外部棋盘类型
typedef short outMineBox;
//下划线数量
#define INPUT_UNDERLINE 3
//外部棋盘格子状态
typedef enum outBoxStatus
{
	nothing = 0,
	opener,
	flag,
	qus
}outBoxStatus;

//打印棋盘
#if 0==OTHER_CONPILER



//对格子的判断
static void isBoxNum(mineBoxIn spaceIn[ROW][LINE], outMineBox spaceOut[ROW][LINE], rowType row, lineType line)
{
	if (opener == spaceOut[row][line])//判断这个位置是否已经打开
	{
		if (!spaceIn[row][line])//空格子
		{
			printf_s(" ");
		}
		else if (-1 != spaceIn[row][line])//数字格子
		{
			printf_s("%d", spaceIn[row][line]);
		}
		else//雷
		{
			printf_s("*");
		}
	}
	else if (flag == spaceOut[row][line])//旗子
	{
		printf_s("!");
	}
	else if (qus == spaceOut[row][line])//问号格子
	{
		printf_s("?");
	}
	else//没有操作过的格子
	{
		printf("#");
	}
}

//打印格子
static void printMineBox(mineBoxIn spaceIn[ROW][LINE], outMineBox spaceOut[ROW][LINE],rowType row,lineType line)
{
	for (int i = 0; i < row;i++)
	{
		
		for (int j = 0; j < line; j++)
		{
			printf_s("|");
			isBoxNum(spaceIn, spaceOut, i, j);
		}
		printf_s("|%d",i+1);
		printf_s("\n");
	}
}
//打印玩家看到的棋盘-外部棋盘flase为没开，ture为开
void putSpaceOut(mineBoxIn spaceIn[ROW][LINE], outMineBox spaceOut[ROW][LINE],rowType row,lineType line)
{
	for (int i = 1; i <= line; i++)//打印棋盘上方的标尺
	{
		printf_s(" %d", i);
	}
	printf_s("\n");
	printMineBox(spaceIn, spaceOut, row, line);
}
#elif 1 == OTHER_CONPILER
#define printf_s printf
//对格子的判断
static void isBoxNum(mineBoxIn spaceIn[ROW][LINE], outMineBox spaceOut[ROW][LINE], rowType row, lineType line)
{
	if (1 == spaceOut[row][line])//判断这个位置是否已经打开
	{
		if (!spaceIn[row][line])//空格子
		{
			printf_s(" ");
		}
		else if (-1 != spaceIn[row][line])//数字格子
		{
			printf_s("%d", spaceIn[row][line]);
		}
		else//雷
		{
			printf_s("*");
		}
	}
	else if (2 == spaceOut[row][line])//旗子
	{
		printf_s("!");
	}
	else if (3 == spaceOut[row][line])//问号格子
	{
		printf_s("?");
	}
	else//没有操作过的格子
	{
		printf("#");
	}
}

//打印格子
static void printMineBox(mineBoxIn spaceIn[ROW][LINE], outMineBox spaceOut[ROW][LINE], rowType row, lineType line)
{
	for (int i = 0; i < row; i++)
	{

		for (int j = 0; j < line; j++)
		{
			printf_s("|");
			isBoxNum(spaceIn, spaceOut, i, j);
		}
		printf_s("|%d", i + 1);
		printf_s("\n");
	}
}
//打印玩家看到的棋盘-外部棋盘flase为没开，ture为开
void putSpaceOut(mineBoxIn spaceIn[ROW][LINE], outMineBox spaceOut[ROW][LINE], rowType row, lineType line)
{
	for (int i = 1; i <= line; i++)//打印棋盘上方的标尺
	{
		printf_s("%d", i);
	}
	printf_s("\n");
	printMineBox(spaceIn, spaceOut, row, line);
}
#undef printf_s

#else
#error OTHER_CONPILER常量值异常
#endif


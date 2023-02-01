#pragma once
#include <stdio.h>
#include "info.h"
#include <assert.h>
#include "space.h"
#include "gameOutput.h"

/*
* 文件名:gameInput.h
* 编写者：mydream8
* 创建时间：2023.2.1
* 完成时间:
* 文件描述：负责游戏输入的函数，自定义数据类型
* 功能过程描述：打印操作提示=》van家输入=》写入外部棋盘
* 编写工具：Visual Studio 2022
* 此程序为开源程序
*/

//输入类型
typedef enum inputKind
{
	open=1,
	makeFlag,
	ask
}inputKind;

//坐标类型
typedef int rowAxis;
typedef int lineAxis;

#if 0==OTHER_CONPILER
#define printf printf
#define scanf scanf_s
//打印提示信息
static void printCue(const char* cue)
{
	printf_s(cue);
}

//打印下划线和提示符
static void printUnder(const int lineNum)
{
	printf_s(">");
	int i = 0;//循环记数
	for (; i < lineNum; i++)
	{
		printf_s("_");
	}
	while (i--)
	{
		printf_s("\b");
	}
}

//输入信息
static void inputInfo(lineAxis* line, rowAxis* row, inputKind* kind,rowType rowLong,lineType lineLong,const char* cue,const int lineNum)
{
	assert(line && row && kind);//保证不为空指针
	short errorNum = 0;
	do
	{
		if (errorNum)
		{
			printf_s("输入错误\n");
		}
		printCue(cue);
		printUnder(lineNum);
		scanf_s("%d%*c%d%*c%d", line, row, kind);//先列后行后操作
		assert(EOF != getchar());
	} while (++errorNum,!*line||!*row||*line>lineLong||*row>rowLong||*kind<open||*kind>qus);
}

//写入外部棋盘-不知加上const修饰是否可行
static void writeOutSpace(outMineBox outSpace[ROW][LINE],const lineAxis line,const rowAxis row,const inputKind kind)
{
	switch (kind)
	{
	case open:
		outSpace[row-1][line-1] = opener;
		break;
	case makeFlag:
		outSpace[row-1][line-1] = flag;
		break;
	case ask:
		outSpace[row-1][line-1] = qus;
		break;
	}
}

//输入处理
outMineBox* playerInput(outMineBox outSpace[ROW][LINE], const char* cue, const int lineNum,rowType rowLong, lineType lineLong)
{
	lineAxis line = 0;
	rowAxis row = 0;
	inputKind kind = 0;
	inputInfo(&line, &row, &kind, rowLong,lineLong, cue, lineNum);
	writeOutSpace(outSpace, line, row, kind);
	return &outSpace[row][line];
}
#undef printf
#undef scanf

#elif 1==OTHER_CONPILER
#define printf_s printf
#define scanf_s scanf

#undef printf_s
#undef scanf

#else 
#error OTHER_CONPILER常量值异常
#endif
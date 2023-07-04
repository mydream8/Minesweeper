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
//作为一个内部棋盘格子的类型

mineBoxIn* makeSpaceIn(rowType row, lineType line)
{
	mineBoxIn* pSpaceIn = (mineBoxIn*)calloc(row * line, sizeof(mineBoxIn));
	assert(pSpaceIn);
	return pSpaceIn;
}
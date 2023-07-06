#pragma once

/*
* 文件名：isWinner.h
* 文件版本:v1.0
* 编写者：mydream8
* 编写日期：2023.1.24
* 完成日期：
* 文件说明：负责游戏对是否踩中雷的判断，生成点击格子附近的数字格子，无雷无数字的格子
* 编写工具：Visual Studio 2022
* 此程序为开源程序
*/

#include "space.h"
#include "gameOutput.h"
#include "mine.h"
//#include <string.h>

typedef enum winOrLose
{
	lose = -1,
	draw,//平局
	win
}winOrLose;

winOrLose isWin(mineBoxIn spaceIn[ROW][LINE], outMineBox spaceOut[ROW][LINE], rowType rowLong, lineType lineLong)
{
	winOrLose loseOrWin = draw;
	size_t catchNotMineNum = 0;//扫清的雷
	for (size_t i = 0; i < rowLong; i++)
	{
		for (size_t j = 0; j < lineLong; j++)//遍历两个棋盘
		{
			if (spaceOut[i][j]==opener)
			{
				if (MINE == spaceIn[i][j])
				{
					loseOrWin = lose;
				}
				else
				{
					catchNotMineNum++;
				}
			}
		}
	}
	if ((rowLong*lineLong-MINE_NUM) == catchNotMineNum)
	{
		loseOrWin = win;
	}
	return loseOrWin;
}

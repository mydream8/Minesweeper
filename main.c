﻿#include "space.h"
#include "isWinner.h"
#include "mine.h"
#include "gameOutput.h"
#include "gameInput.h"
#include "isWinner.h"



int main(void)
{
	////输入测试
	//mineBoxIn space[ROW][LINE] = { {0,8} };
	//outMineBox outSpace[ROW][LINE] = { {0,0} };
	//lineAxis line = 2;
	//rowAxis row = 0;
	//inputKind kind = 0;
	//playerInput(outSpace, "what", 10, ROW, LINE);
	//putSpaceOut(space, outSpace, ROW, LINE);

	//打印测试
	/*outMineBox out [ROW][LINE] = { {0,1,2,3} };
	mineBoxIn in [ROW][LINE] = { {0,7} };
	putSpaceOut(in, out, ROW, LINE);*/

	//生成雷的测试
	//mineBoxIn spaceIn[ROW][LINE] = { 0 };
	//makeMine(0, ROW, LINE, spaceIn, MINE_NUM);
	//for (int i = 0; i < ROW; i++)
	//{
	//	for (int j = 0; j < LINE;j++)
	//	{
	//		if (MINE == spaceIn[i][j])
	//			printf("* ");
	//		else
	//			printf("%d ", spaceIn[i][j]);
	//	}
	//	printf("\n");
	//}
	////问题-不能对最后一行进行周围格子修改

	//输赢检测函数的检测
	mineBoxIn spaceIn[ROW][LINE] = { {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} };
	outMineBox outSpace[ROW][LINE] = { {0,0} };
	for (int i = 1; i < ROW; i++)
	{
		for (int j = 0; j < LINE; j++)
		{
			outSpace[i][j] = opener;
		}
	}
	putSpaceOut(spaceIn, outSpace, ROW, LINE);
	winOrLose loseOrWin=isWin(spaceIn, outSpace, ROW, LINE);
	if (loseOrWin == lose)
	{
		printf("lose");
	}
	else if (loseOrWin == draw)
	{
		printf("draw");
	}
	else if (loseOrWin == win)
	{
		printf("win");
	}

	return 0;
}
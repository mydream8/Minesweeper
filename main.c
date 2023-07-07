#include "space.h"
#include "isWinner.h"
#include "mine.h"
#include "gameOutput.h"
#include "gameInput.h"
#include "isWinner.h"
#include <assert.h>

#if RUN_ON_WINDOWS
#include <Windows.h>
#include <string.h>
#endif // RUN_ON_WINDOWS


void startAgain(void)
{
	if (RUN_ON_WINDOWS)
	{
		char programDir[30] = "start ";
		strcat(programDir, PROGRAM_NAME);
		system(programDir);
	}
	exit(0);
}


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

	////输赢检测函数的检测
	//mineBoxIn spaceIn[ROW][LINE] = { {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} };
	//outMineBox outSpace[ROW][LINE] = { {0,0} };
	//for (int i = 1; i < ROW; i++)
	//{
	//	for (int j = 0; j < LINE; j++)
	//	{
	//		outSpace[i][j] = opener;
	//	}
	//}
	//putSpaceOut(spaceIn, outSpace, ROW, LINE);
	//winOrLose loseOrWin=isWin(spaceIn, outSpace, ROW, LINE);
	//if (loseOrWin == lose)
	//{
	//	printf("lose");
	//}
	//else if (loseOrWin == draw)
	//{
	//	printf("draw");
	//}
	//else if (loseOrWin == win)
	//{
	//	printf("win");
	//}

	//开始了！将各个功能搭配到一起

	mineBoxIn(*pSpaceIn)[ROW][LINE] = makeSpaceIn(ROW, LINE);//使用时记得解引用
	outMineBox(*pSpaceOut)[ROW][LINE] = makeSpaceOut(ROW, LINE);//使用时记得解引用
	putSpaceOut(*pSpaceIn, *pSpaceOut, ROW, LINE);
	axis firstOpen = playerInput(*pSpaceOut, "请输入 列,行，操作（1=打开，2=插旗，3=问号", 8, ROW, LINE);
	makeMine(firstOpen, ROW, LINE, *pSpaceIn, MINE_NUM);
	winOrLose loseOrWin = draw;
	while (1)
	{
		putSpaceOut(*pSpaceIn, *pSpaceOut, ROW, LINE);
		playerInput(*pSpaceOut, "列，行，操作", 8, ROW, LINE);
		loseOrWin = isWin(*pSpaceIn, *pSpaceOut, ROW, LINE);
		if (win == loseOrWin)
		{
			puts("胜利");
			break;
		}
		else if (lose == loseOrWin)
		{
			puts("失败");
			break;
		}
	}
	size_t choice = 0;
	puts("想重新玩一把吗？");
	printf("1重新打开，0退出>_\b");
	scanf("%zd", &choice);
	assert(getchar());
	if (choice)
	{
		startAgain();
	}
	return 0;
}
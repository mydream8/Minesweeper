#pragma once
#define MINE -1 //在数组中雷的数值
#define MINE_NUM 10
/*
* 文件名：mine.h
* 文件版本:v1.0
* 编写者：mydream8
* 编写日期：2023.1.24
* 完成日期：
* 文件说明：负责游戏生成雷的函数，宏
* 编写工具：Visual Studio 2022
* 此程序为开源程序
*/

//void makeMine(rowAxis firstBoxRow, lineAxis firstBoxLine, rowType row, lineType line, mineBoxIn spaceIn[ROW][LINE], int mineMum)
//{
//
//}
////生成雷

static void changeToMine(mineBoxIn spaceIn[ROW][LINE], axis mineAxis)
{
	spaceIn[0][mineAxis] = MINE;
}
//将该格设置为雷数

static int boolChangeBox(mineBoxIn* const pchangeBox, const mineBoxIn* firstBox, const mineBoxIn* lastBox)
{
	if (*pchangeBox != MINE && pchangeBox >= firstBox && pchangeBox <= lastBox)
	{
		(*pchangeBox)++;
		return 1;//修改有效
	}
	return 0;//修改无效
}
//具体格子的修改

static void changeAroundBoxIn(mineBoxIn spaceIn[ROW][LINE], axis mineAxis, rowType row,lineType line)
{

	//mineBoxIn* pchangeBox = NULL;
	//if (spaceIn[0][mineAxis - 1] != MINE && (&spaceIn[0][mineAxis - 1]) >= (spaceIn[0]))
	//{
	//	spaceIn[0][mineAxis - 1]++;
	//}
	//pchangeBox = &spaceIn[0][mineAxis + 1];
	 const mineBoxIn* lastBox = &spaceIn[row - 1][line - 1];
	 int mineInFirstLine = 0;
	 int mineInLastLine = 0;
	//boolChangeBox(&spaceIn[0][mineAxis - 1], spaceIn[0], lastBox);//左边
	//boolChangeBox(&spaceIn[0][mineAxis + 1], spaceIn[0], lastBox);//右边
	//boolChangeBox(&spaceIn[-1][mineAxis], spaceIn[0], lastBox);//上面
	//boolChangeBox(&spaceIn[-1][mineAxis - 1], spaceIn[0], lastBox);//雷的左上
	//boolChangeBox(&spaceIn[-1][mineAxis + 1], spaceIn[0], lastBox);//雷的右上
	//boolChangeBox(&spaceIn[1][mineAxis], spaceIn[0], lastBox);//下面
	//boolChangeBox(&spaceIn[1][mineAxis - 1], spaceIn[0], lastBox);//雷的左下
	//boolChangeBox(&spaceIn[1][mineAxis + 1], spaceIn[0], lastBox);//雷的右下
	 for (int i = 0; i < row; i++)
	 {
		 if (&spaceIn[0][mineAxis] == spaceIn[i])
		 {
			 mineInFirstLine = 1;
		 }
		 if (&spaceIn[0][mineAxis] == &spaceIn[i][line - 1])
		 {
			 mineInLastLine = 1;
		 }
	 }

	 if (!mineInFirstLine)//左边
	 {
		 boolChangeBox(&spaceIn[0][mineAxis - 1], spaceIn[0], lastBox);//左边
		 boolChangeBox(&spaceIn[-1][mineAxis - 1], spaceIn[0], lastBox);//雷的左上
		 boolChangeBox(&spaceIn[1][mineAxis - 1], spaceIn[0], lastBox);//雷的左下
	 }
	 if(!mineInLastLine)
	 {
		 boolChangeBox(&spaceIn[0][mineAxis + 1], spaceIn[0], lastBox);//右边
		 boolChangeBox(&spaceIn[-1][mineAxis + 1], spaceIn[0], lastBox);//雷的右上
		 boolChangeBox(&spaceIn[1][mineAxis + 1], spaceIn[0], lastBox);//雷的右下
	 }

	 boolChangeBox(&spaceIn[-1][mineAxis], spaceIn[0], lastBox);//上面
	 boolChangeBox(&spaceIn[1][mineAxis], spaceIn[0], lastBox);//下面
}
//修改雷旁边的格子-旁边是否雷、首尾、角落

//void makeMine(rowAxis firstBoxRow, lineAxis firstBoxLine, rowType row, lineType line, mineBoxIn spaceIn[ROW][LINE], const int mineMum)
//{
//	srand(time(NULL) % (row * line));
//	mineBoxIn mineAxis = rand();
//	mineAxis--;//余数不会有0 需要减一
//}
////生成雷-遇到玄学错误

void makeMine(axis firstBoxAxis,rowType row,lineType line,mineBoxIn spaceIn[ROW][LINE],const int mineNum)
{
	srand((unsigned)time(NULL));
	axis mineAxis = 0;
	//mineAxis--;//余数不会有0 需要减一
	for (size_t i = 0; i < mineNum; i++)
	{
		mineAxis = rand()%(row*line);
		mineAxis--;
		if ((&spaceIn[0][mineAxis] != &spaceIn[0][firstBoxAxis]) && (spaceIn[0][mineAxis] != MINE))
		{
			//既不与第一个按下的格子重复 也不与之前生成的雷重复
			spaceIn[0][mineAxis] = MINE;
			changeAroundBoxIn(spaceIn, mineAxis, row,line);
		}
		else
		{
			//再来一次
			i--;
			continue;
		}
	}
}
//生成雷
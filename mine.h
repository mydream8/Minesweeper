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

//static void changeToMine(mineBoxIn spaceIn[ROW][LINE], mineBoxIn mineAxis)
//{
//	spaceIn[0][mineAxis - 1] = MINE;
//}
////将该格设置为雷数
//
//static int boolChangeBox(mineBoxIn* const pchangeBox, const mineBoxIn* firstBox, const mineBoxIn* lastBox)
//{
//	if (*pchangeBox != MINE && pchangeBox >= firstBox && pchangeBox <= lastBox)
//	{
//		(*pchangeBox)++;
//		return 1;//修改有效
//	}
//	return 0;//修改无效
//}
////具体格子的修改
//
//static void changeAroundBoxIn(mineBoxIn spaceIn[ROW][LINE], mineBoxIn mineAxis, rowType row)
//{
//
//	//mineBoxIn* pchangeBox = NULL;
//	//if (spaceIn[0][mineAxis - 1] != MINE && (&spaceIn[0][mineAxis - 1]) >= (spaceIn[0]))
//	//{
//	//	spaceIn[0][mineAxis - 1]++;
//	//}
//	//pchangeBox = &spaceIn[0][mineAxis + 1];
//	boolChangeBox(&spaceIn[0][mineAxis - 1], spaceIn[0], spaceIn[row - 1]);//左边
//	boolChangeBox(&spaceIn[0][mineAxis + 1], spaceIn[0], spaceIn[row - 1]);//右边
//	boolChangeBox(&spaceIn[-1][mineAxis], spaceIn[0], spaceIn[row - 1]);//上面
//	boolChangeBox(&spaceIn[-1][mineAxis - 1], spaceIn[0], spaceIn[row - 1]);//雷的左上
//}
////修改雷旁边的格子-旁边是否雷、首尾、角落
//
////void makeMine(rowAxis firstBoxRow, lineAxis firstBoxLine, rowType row, lineType line, mineBoxIn spaceIn[ROW][LINE], const int mineMum)
////{
////	srand(time(NULL) % (row * line));
////	mineBoxIn mineAxis = rand();
////	mineAxis--;//余数不会有0 需要减一
////}
//////生成雷
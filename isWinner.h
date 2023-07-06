#pragma once

/*
* �ļ�����isWinner.h
* �ļ��汾:v1.0
* ��д�ߣ�mydream8
* ��д���ڣ�2023.1.24
* ������ڣ�
* �ļ�˵����������Ϸ���Ƿ�����׵��жϣ����ɵ�����Ӹ��������ָ��ӣ����������ֵĸ���
* ��д���ߣ�Visual Studio 2022
* �˳���Ϊ��Դ����
*/

#include "space.h"
#include "gameOutput.h"
#include "mine.h"
//#include <string.h>

typedef enum winOrLose
{
	lose = -1,
	draw,//ƽ��
	win
}winOrLose;

winOrLose isWin(mineBoxIn spaceIn[ROW][LINE], outMineBox spaceOut[ROW][LINE], rowType rowLong, lineType lineLong)
{
	winOrLose loseOrWin = draw;
	size_t catchNotMineNum = 0;//ɨ�����
	for (size_t i = 0; i < rowLong; i++)
	{
		for (size_t j = 0; j < lineLong; j++)//������������
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

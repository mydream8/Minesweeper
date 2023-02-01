#pragma once

#include <stdio.h>
#include "space.h"
#include <stdbool.h>
#include "info.h"

/*
* �ļ�����gameInputOutput.h
* �ļ��汾:v1.0
* ��д�ߣ�mydream8
* ��д���ڣ�2023.1.24
* ������ڣ�2023.1.31
* �ļ�˵����������Ϸ����ĺ�������,�����ⲿ����,ԭ�����������Ϸ���뺯�����������õ�������gameInput.h��
* ��д���ߣ�Visual Studio 2022
* �˳���Ϊ��Դ����
*/

//�ⲿ��������
typedef short outMineBox;
//�»�������
#define INPUT_UNDERLINE 3
//�ⲿ���̸���״̬
typedef enum outBoxStatus
{
	nothing = 0,
	opener,
	flag,
	qus
}outBoxStatus;

//��ӡ����
#if 0==OTHER_CONPILER



//�Ը��ӵ��ж�
static void isBoxNum(mineBoxIn spaceIn[ROW][LINE], outMineBox spaceOut[ROW][LINE], rowType row, lineType line)
{
	if (opener == spaceOut[row][line])//�ж����λ���Ƿ��Ѿ���
	{
		if (!spaceIn[row][line])//�ո���
		{
			printf_s(" ");
		}
		else if (-1 != spaceIn[row][line])//���ָ���
		{
			printf_s("%d", spaceIn[row][line]);
		}
		else//��
		{
			printf_s("*");
		}
	}
	else if (flag == spaceOut[row][line])//����
	{
		printf_s("!");
	}
	else if (qus == spaceOut[row][line])//�ʺŸ���
	{
		printf_s("?");
	}
	else//û�в������ĸ���
	{
		printf("#");
	}
}

//��ӡ����
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
//��ӡ��ҿ���������-�ⲿ����flaseΪû����tureΪ��
void putSpaceOut(mineBoxIn spaceIn[ROW][LINE], outMineBox spaceOut[ROW][LINE],rowType row,lineType line)
{
	for (int i = 1; i <= line; i++)//��ӡ�����Ϸ��ı��
	{
		printf_s(" %d", i);
	}
	printf_s("\n");
	printMineBox(spaceIn, spaceOut, row, line);
}
#elif 1 == OTHER_CONPILER
#define printf_s printf
//�Ը��ӵ��ж�
static void isBoxNum(mineBoxIn spaceIn[ROW][LINE], outMineBox spaceOut[ROW][LINE], rowType row, lineType line)
{
	if (1 == spaceOut[row][line])//�ж����λ���Ƿ��Ѿ���
	{
		if (!spaceIn[row][line])//�ո���
		{
			printf_s(" ");
		}
		else if (-1 != spaceIn[row][line])//���ָ���
		{
			printf_s("%d", spaceIn[row][line]);
		}
		else//��
		{
			printf_s("*");
		}
	}
	else if (2 == spaceOut[row][line])//����
	{
		printf_s("!");
	}
	else if (3 == spaceOut[row][line])//�ʺŸ���
	{
		printf_s("?");
	}
	else//û�в������ĸ���
	{
		printf("#");
	}
}

//��ӡ����
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
//��ӡ��ҿ���������-�ⲿ����flaseΪû����tureΪ��
void putSpaceOut(mineBoxIn spaceIn[ROW][LINE], outMineBox spaceOut[ROW][LINE], rowType row, lineType line)
{
	for (int i = 1; i <= line; i++)//��ӡ�����Ϸ��ı��
	{
		printf_s("%d", i);
	}
	printf_s("\n");
	printMineBox(spaceIn, spaceOut, row, line);
}
#undef printf_s

#else
#error OTHER_CONPILER����ֵ�쳣
#endif


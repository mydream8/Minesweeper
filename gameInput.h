#pragma once
#include <stdio.h>
#include "info.h"
#include <assert.h>
#include "space.h"
#include "gameOutput.h"

/*
* �ļ���:gameInput.h
* ��д�ߣ�mydream8
* ����ʱ�䣺2023.2.1
* ���ʱ��:
* �ļ�������������Ϸ����ĺ������Զ�����������
* ���ܹ�����������ӡ������ʾ=��van������=��д���ⲿ����
* ��д���ߣ�Visual Studio 2022
* �˳���Ϊ��Դ����
*/

//��������
typedef enum inputKind
{
	open=1,
	//��һ��
	makeFlag,
	//����
	ask
	//���ʺ�
}inputKind;

//��������
typedef int rowAxis;
typedef int lineAxis;

#if 0==OTHER_CONPILER
#define printf printf
#define scanf scanf_s
//��ӡ��ʾ��Ϣ
static void printCue(const char* cue)
{
	printf_s(cue);
}

//��ӡ�»��ߺ���ʾ��
static void printUnder(const int lineNum)
{
	printf_s(">");
	int i = 0;//ѭ������
	for (; i < lineNum; i++)
	{
		printf_s("_");
	}
	while (i--)
	{
		printf_s("\b");
	}
}

//������Ϣ
static void inputInfo(lineAxis* line, rowAxis* row, inputKind* kind,rowType rowLong,lineType lineLong,const char* cue,const int lineNum)
{
	assert(line && row && kind);//��֤��Ϊ��ָ��
	short errorNum = 0;
	do
	{
		if (errorNum)
		{
			printf_s("�������\n");
		}
		printCue(cue);
		printUnder(lineNum);
		scanf_s("%d%*c%d%*c%d", line, row, kind);//���к��к����
		assert(EOF != getchar());
	} while (++errorNum,!*line||!*row||*line>lineLong||*row>rowLong||*kind<open||*kind>qus);
}

//д���ⲿ����-��֪����const�����Ƿ����
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

//���봦��
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
#error OTHER_CONPILER����ֵ�쳣
#endif
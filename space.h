#pragma once
/*
* �ļ�����space.h
* �ļ��汾:v1.0
* ��д�ߣ�mydream8
* ��д���ڣ�2023.1.24
* ������ڣ�
* �ļ�˵���������������̵ĺ�������,�����ڲ����̺�ĳЩ���̵�ȫ�����Ͷ���
* ��д���ߣ�Visual Studio 2022
* �˳���Ϊ��Դ����
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define ROW 10 //��
#define LINE 10 //��-������ڻ�С��10�������ӡ�����ǳ��ѿ�

typedef  const int rowType;//��֤��ͳһ��const int����
typedef const int lineType;//��֤��ͳһ��const int����

typedef short int mineBoxIn;
//��Ϊһ���ڲ����̸��ӵ�����

mineBoxIn* makeSpaceIn(rowType row, lineType line)
{
	mineBoxIn* pSpaceIn = (mineBoxIn*)calloc(row * line, sizeof(mineBoxIn));
	assert(pSpaceIn);
	return pSpaceIn;
}
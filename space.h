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
//��Ϊһ�����ӵ�����

//������
//void makeMine(unsigned int num, int row, int line)
//{
//
//}


//������
//static void makeMine(unsigned int num,mineBoxIn space[ROW][LINE])
//{
//	//mineBoxIn* addMine=(void*)malloc((size_t)num*sizeof(mineBoxIn*));//����ÿ���׵�λ��
//	//if (!addMine)//��֤��̬�ڴ������ȷ
//	//{
//	//	puts("�������!");
//	//	assert(addMine);
//	//}
//	//for (int i = 0; i < num; i++)//��ʼ��
//	//{
//	//	addMine[i] = NULL;
//	//}
//
//	if (num == 0)
//	{
//		return;
//	}
//	else if (num >= ROW * LINE)
//	{
//		puts("���δ��󣬺���makeMine������num");
//		assert(0);
//	}
//
//	while (1)
//	{
//		srand((unsigned int)time(NULL));//��һ�н�����������
//		int mineYAxis = (rand()%LINE);
//		srand((unsigned int)time(NULL));//��һ�н�����������
//		int mineXAxis = (rand()%ROW);
//		if (space[mineXAxis][mineYAxis] != MINE)//�ж�����ط��Ƿ���������
//		{
//			space[mineXAxis][mineYAxis] = MINE;
//			break;
//		}
//		else
//		{
//			continue;
//		}
//	}
//	
//	makeMine(num - 1, space);
//}
//
////�������Աߵ����ָ���
//static void makeNum(mineBoxIn space[ROW][LINE])
//{
//
//	//����for����
//	for (int i = 0; i < ROW; i++)//�ӵ�0�п�ʼ���
//	{
//		for (int j = 0; j < LINE; j++)//�ӵ�0�п�ʼ���
//		{
//			if (space[i][j] == MINE)//����ҵ��˾ͽ��в���
//			{
//				if (i == 0)//�����������������ﴦ��
//				{
//					space[i + 1][j] += 1;
//					if (0 != j)//�������Ͻ�
//					{
//						//����߽��в���
//						space[i][j - 1] += 1;
//						space[i + 1][j - 1] += 1;
//						
//					}
//					if (LINE != j)//�������Ͻ�
//					{
//						//���ұ߽��в���
//						space[i][j + 1] += 1;
//						space[i + 1][j + 1] += 1;
//					}
//					/*continue;*/
//				}
//				else if (ROW == i)//�±�һ�Ÿ��ӣ����������������ﴦ��
//				{
//					space[i - 1][j] += 1;
//					if (0 != j)//�������½�
//					{
//						space[i][j - 1]++;
//						space[i - 1][j - 1]++;
//					}
//					else if (LINE != j)//�������½�
//					{
//						space[i][j + 1]++;
//						space[i - 1][j - 1]++;
//					}
//				}
//				else if (0 == j)//�����һ��
//				{
//					space[i - 1][j]++;
//					space[i - 1][j + 1]++;
//					space[i][j + 1]++;
//					space[i + 1][j + 1]++;
//					space[i + 1][j]++;
//				}
//				else if (LINE == j)//�ұ���һ��
//				{
//					space[i - 1][j]++;
//					space[i - 1][j - 1]++;
//					space[i][j - 1]++;
//					space[i + 1][j - 1]++;
//					space[i + 1][j]++;
//				}
//				else//�м�
//				{
//					//��ʫ�����ŵĴ���:)
//					space[i - 1][j]++;//����
//					space[i - 1][j - 1]++;//���Ͻ�
//					space[i][j - 1]++;//���
//					space[i + 1][j - 1]++;//���½�
//					space[i + 1][j]++;//����
//					space[i - 1][j + 1]++;//���Ͻ�
//					space[i][j + 1]++;//�ұ�
//					space[i + 1][j + 1]++;//���½�
//				}
//			}
//		}
//	}
//}

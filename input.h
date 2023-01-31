#pragma once
#include <stdio.h>
#include <assert.h>

#define POINT_OUT_INFO "请输入"

#define OTHER_CONPILER 0


//输入
#if OTHER_CONPILER == 0
#define scanf scanf_s
#define printf printf_s
static void intInput(int* information)
{
	scanf_s("%d", information);
	assert(EOF!=getchar());
}

static void strInput(char* str, unsigned int num)
{
	scanf_s("%s", str, num);
	assert(-1 != getchar());
}
//打印应提示信息:
static void printSoInput(char* str)
{
	printf_s("%s%s\n", POINT_OUT_INFO, str);
}

//打印下划线
static void printUnderline(unsigned short num)
{
	printf_s(">");
	for (unsigned short i = 0; i < num; i++)
	{
		printf_s("_");
	}
	for (unsigned short i = 0; i < num; i++)
	{
		printf_s("\b");
	}
}
//输入+打印提示信息+下划线-字符串版
void inputStrInformation(char* information, unsigned int num, char* printInformation, unsigned short underline)
{
	printSoInput(printInformation);
	printUnderline(underline);
	strInput(information, num);
}
#undef scanf
#undef printf
#elif OTHER_CONPILER == 1

#define scanf_s scanf
#define printf_s printf

//打印应提示信息:
static void printSoInput(char* str)
{
	printf_s("%s%s\n", POINT_OUT_INFO, str);
}

//打印下划线
static void printUnderline(unsigned short num)
{
	printf_s(">");
	for (unsigned short i = 0; i < num; i++)
	{
		printf_s("_");
	}
	for (unsigned short i = 0; i < num; i++)
	{
		printf_s("\b");
	}
}

static void intInput(int* information)
{
	scanf("%d", information);
	assert(-1 != getchar());
}

static void strInput(char* str)
{
	scanf("%s", str);
	assert(-1 != getchar());
}
//输入+打印提示信息+下划线-字符串版
void inputStrInformation(char* information, char* printInformation, unsigned short underline)
{
	printSoInput(printInformation);
	printUnderline(underline);
	strInput(information);
}
#undef scanf_s 
#undef printf_s
#else

#error OTHER_CONPILER常量值异常

#endif


//输入+打印提示信息+下划线

//整型版
void inputIntInformation(int* information, char* printInformation, unsigned short underline)
{
	printSoInput(printInformation);
	printUnderline(underline);
	intInput(information);
}




#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "List.h"
#include "Test.h"

typedef struct
{
	unsigned int id;
	char name[20];
	int age;
	double score;
	List list;        //在你的结构体任意位置包含一个List成员变量，变量名可随意指定
}Student, *PStudent;

void StudentPrint(const PStudent pStu)
{
	printf("%u %s %d %lf\n", pStu->id, pStu->name, pStu->age, pStu->score);
}

int StudentCmpByScore(const PStudent p1, const PStudent p2)
{
	return p1->score > p2->score;
}

int IsAge20(const PStudent pStu)
{
	return pStu->age == 20;
}

int IsId1001(const PStudent pStu)
{
	return pStu->id == 1001;
}

int main()
{
	//测试通用链表
	Test();

	/*
		通用链表的使用示例
		学生信息展示
	*/

	Student head;

	//创建链表
	ListCreate(&head, list);

	int n;
	printf("请输入学生人数：");
	scanf("%d", &n);

	/*
		输入内容：
		1001 XiaoMing 19 95
		1002 XiaoHong 19 80
		1003 XiaoHua 20 85
		1004 XiaoJun 19 55
		1005 ZhangSan 20 60
	*/
	printf("\n请依次输入所有学生的学号、姓名、年龄和分数：\n");
	Student data;
	for (int i = 0; i < n; ++i)
	{
		scanf("%u %s %d %lf", &data.id, data.name, &data.age, &data.score);
		//追加节点
		ListAppend(&head, list, &data);
	}

	//输出所有学生信息
	printf("\n所有学生信息如下：\n");
	ListTraverse(&head, list, StudentPrint);

	//对链表排序
	printf("\n按照成绩降序排序：\n");
	ListSort(&head, list, StudentCmpByScore);
	ListTraverse(&head, list, StudentPrint);

	//查找所有年龄为20岁的学生
	int cnt = ListNodeCount(&head, list, IsAge20);
	PStudent pRes = (PStudent)malloc(sizeof(Student) * cnt);
	ListSearch(&head, list, IsAge20, pRes);
	printf("\n所有年龄等于20岁的学生：\n");
	for (int i = 0; i < cnt; ++i)
	{
		StudentPrint(pRes + i);
	}
	free(pRes);

	//删除学号为1001的学生
	cnt = ListNodeCount(&head, list, IsId1001);
	pRes = (PStudent)malloc(sizeof(Student) * cnt);
	ListDelete(&head, list, IsId1001, pRes);
	printf("\n删除学号为1001的学生：\n");
	ListTraverse(&head, list, StudentPrint);
	printf("\n删除学生的信息：\n");
	for (int i = 0; i < cnt; ++i)
	{
		StudentPrint(pRes + i);
	}
	free(pRes);

	printf("\n");
	return 0;
}

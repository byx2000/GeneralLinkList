#include <stdio.h>
#include <assert.h>
#include "List.h"

typedef struct
{
	int id;
	int age;
	Node list;
}Student, *PStudent;

void StudentInit(const PStudent pStu, int id, int age)
{
	pStu->id = id;
	pStu->age = age;
}

void ShowStudentInfo(const PStudent pStu)
{
	printf("%d %d\n", pStu->id, pStu->age);
}

void ShowAllStudentsInfo(const PStudent pHead)
{
	printf("all students info:\n");
	ListTraverse(pHead, list, ShowStudentInfo);
	printf("\n");
}

int StudentEqual(const PStudent p1, const PStudent p2)
{
	return (p1->id == p2->id) && (p1->age == p2->age);
}

int TargetIdExist1(const PStudent pStu)
{
	return pStu->id == 1002;
}

int TargetIdExist2(const PStudent pStu)
{
	return pStu->id == 1005;
}

int TargetIdExist3(const PStudent pStu)
{
	return pStu->id == 1001;
}

int TargetIdNotExist(const PStudent pStu)
{
	return pStu->id == 1020;
}

int StudentLessthan(const PStudent p1, const PStudent p2)
{
	return p1->id < p2->id;
}

int StudentBiggerthan(const PStudent p1, const PStudent p2)
{
	return p1->id > p2->id;
}

int main()
{
	freopen("out.txt", "w", stdout);

	//初始化学生数据
	Student head, data1, data2, data3, data4, data5, data6, data7, data8, res;
	StudentInit(&data1, 1003, 17);
	StudentInit(&data2, 1002, 18);
	StudentInit(&data3, 1005, 20);
	StudentInit(&data4, 1001, 18);
	StudentInit(&data5, 1004, 20);
	StudentInit(&data6, 1010, 15);
	StudentInit(&data7, 1011, 20);
	StudentInit(&data8, 1008, 16);

	//创建链表
	ListCreate(&head, list);

	ShowAllStudentsInfo(&head);

	assert(head.list.pNext == NULL);
	assert(ListLength(&head, list) == 0);
	assert(!ListSearch(&head, list, TargetIdExist1, &res));
	assert(!ListSearch(&head, list, TargetIdExist1, NULL));
	assert(!ListSearch(&head, list, TargetIdNotExist, &res));
	assert(!ListSearch(&head, list, TargetIdNotExist, NULL));
	assert(!ListSearchIndexOf(&head, list, 0, &res));
	assert(!ListSearchIndexOf(&head, list, -2, &res));
	assert(!ListSearchIndexOf(&head, list, 3, &res));

	//追加节点
	ListAppend(&head, list, &data1);
	ListAppend(&head, list, &data2);
	ListAppend(&head, list, &data3);
	ListAppend(&head, list, &data4);
	ListAppend(&head, list, &data5);

	ShowAllStudentsInfo(&head);

	assert(ListLength(&head, list) == 5);

	assert(ListSearch(&head, list, TargetIdExist1, NULL));
	assert(ListSearch(&head, list, TargetIdExist1, &res));
	assert(StudentEqual(&data2, &res));

	assert(!ListSearch(&head, list, TargetIdNotExist, NULL));
	assert(!ListSearch(&head, list, TargetIdNotExist, &res));
	assert(!ListSearchIndexOf(&head, list, -2, &res));
	assert(!ListSearchIndexOf(&head, list, 100, &res));

	assert(!ListSearchIndexOf(&head, list, -1, &res));
	assert(ListSearchIndexOf(&head, list, 0, &res));
	assert(StudentEqual(&data1, &res));
	assert(ListSearchIndexOf(&head, list, 1, &res));
	assert(StudentEqual(&data2, &res));
	assert(ListSearchIndexOf(&head, list, 2, &res));
	assert(StudentEqual(&data3, &res));
	assert(ListSearchIndexOf(&head, list, 3, &res));
	assert(StudentEqual(&data4, &res));
	assert(ListSearchIndexOf(&head, list, 4, &res));
	assert(StudentEqual(&data5, &res));
	assert(!ListSearchIndexOf(&head, list, 5, &res));

	assert(ListLength(&head, list) == 5);

	//升序排序
	ListSort(&head, list, StudentLessthan);

	ShowAllStudentsInfo(&head);

	assert(ListLength(&head, list) == 5);
	assert(!ListSearchIndexOf(&head, list, -1, &res));
	assert(ListSearchIndexOf(&head, list, 0, &res));
	assert(StudentEqual(&data4, &res));
	assert(ListSearchIndexOf(&head, list, 1, &res));
	assert(StudentEqual(&data2, &res));
	assert(ListSearchIndexOf(&head, list, 2, &res));
	assert(StudentEqual(&data1, &res));
	assert(ListSearchIndexOf(&head, list, 3, &res));
	assert(StudentEqual(&data5, &res));
	assert(ListSearchIndexOf(&head, list, 4, &res));
	assert(StudentEqual(&data3, &res));
	assert(!ListSearchIndexOf(&head, list, 5, &res));
	assert(ListLength(&head, list) == 5);

	//降序排序
	ListSort(&head, list, StudentBiggerthan);

	ShowAllStudentsInfo(&head);

	assert(ListLength(&head, list) == 5);
	assert(!ListSearchIndexOf(&head, list, -1, &res));
	assert(ListSearchIndexOf(&head, list, 0, &res));
	assert(StudentEqual(&data3, &res));
	assert(ListSearchIndexOf(&head, list, 1, &res));
	assert(StudentEqual(&data5, &res));
	assert(ListSearchIndexOf(&head, list, 2, &res));
	assert(StudentEqual(&data1, &res));
	assert(ListSearchIndexOf(&head, list, 3, &res));
	assert(StudentEqual(&data2, &res));
	assert(ListSearchIndexOf(&head, list, 4, &res));
	assert(StudentEqual(&data4, &res));
	assert(!ListSearchIndexOf(&head, list, 5, &res));
	assert(ListLength(&head, list) == 5);

	//删除节点
	assert(!ListDelete(&head, list, TargetIdNotExist, &res));
	assert(ListLength(&head, list) == 5);
	assert(!ListDelete(&head, list, TargetIdNotExist, NULL));
	assert(ListLength(&head, list) == 5);

	ShowAllStudentsInfo(&head);

	assert(ListDelete(&head, list, TargetIdExist1, &res));
	assert(StudentEqual(&data2, &res));
	assert(ListLength(&head, list) == 4);
	assert(!ListSearchIndexOf(&head, list, -1, &res));
	assert(ListSearchIndexOf(&head, list, 0, &res));
	assert(StudentEqual(&data3, &res));
	assert(ListSearchIndexOf(&head, list, 1, &res));
	assert(StudentEqual(&data5, &res));
	assert(ListSearchIndexOf(&head, list, 2, &res));
	assert(StudentEqual(&data1, &res));
	assert(ListSearchIndexOf(&head, list, 3, &res));
	assert(StudentEqual(&data4, &res));
	assert(!ListSearchIndexOf(&head, list, 4, &res));
	assert(ListLength(&head, list) == 4);

	ShowAllStudentsInfo(&head);

	assert(ListDelete(&head, list, TargetIdExist2, &res));
	assert(StudentEqual(&data3, &res));
	assert(ListLength(&head, list) == 3);
	assert(!ListSearchIndexOf(&head, list, -1, &res));
	assert(ListSearchIndexOf(&head, list, 0, &res));
	assert(StudentEqual(&data5, &res));
	assert(ListSearchIndexOf(&head, list, 1, &res));
	assert(StudentEqual(&data1, &res));
	assert(ListSearchIndexOf(&head, list, 2, &res));
	assert(StudentEqual(&data4, &res));
	assert(!ListSearchIndexOf(&head, list, 3, &res));
	assert(ListLength(&head, list) == 3);

	ShowAllStudentsInfo(&head);

	assert(ListDelete(&head, list, TargetIdExist3, &res));
	assert(StudentEqual(&data4, &res));
	assert(ListLength(&head, list) == 2);
	assert(!ListSearchIndexOf(&head, list, -1, &res));
	assert(ListSearchIndexOf(&head, list, 0, &res));
	assert(StudentEqual(&data5, &res));
	assert(ListSearchIndexOf(&head, list, 1, &res));
	assert(StudentEqual(&data1, &res));
	assert(!ListSearchIndexOf(&head, list, 2, &res));
	assert(ListLength(&head, list) == 2);

	ShowAllStudentsInfo(&head);

	//追加节点
	ListAppend(&head, list, &data3);
	ListAppend(&head, list, &data2);
	ListAppend(&head, list, &data4);

	ShowAllStudentsInfo(&head);

	assert(!ListSearchIndexOf(&head, list, -1, &res));
	assert(ListSearchIndexOf(&head, list, 0, &res));
	assert(StudentEqual(&data5, &res));
	assert(ListSearchIndexOf(&head, list, 1, &res));
	assert(StudentEqual(&data1, &res));
	assert(ListSearchIndexOf(&head, list, 2, &res));
	assert(StudentEqual(&data3, &res));
	assert(ListSearchIndexOf(&head, list, 3, &res));
	assert(StudentEqual(&data2, &res));
	assert(ListSearchIndexOf(&head, list, 4, &res));
	assert(StudentEqual(&data4, &res));
	assert(!ListSearchIndexOf(&head, list, 5, &res));

	//插入节点
	assert(!ListInsert(&head, list, -1, &data6));
	assert(!ListInsert(&head, list, 6, &data6));
	assert(!ListInsert(&head, list, 10, &data6));

	assert(ListInsert(&head, list, 0, &data6));
	assert(ListLength(&head, list) == 6);
	assert(!ListSearchIndexOf(&head, list, -1, &res));
	assert(ListSearchIndexOf(&head, list, 0, &res));
	assert(StudentEqual(&data6, &res));
	assert(ListSearchIndexOf(&head, list, 1, &res));
	assert(StudentEqual(&data5, &res));
	assert(ListSearchIndexOf(&head, list, 2, &res));
	assert(StudentEqual(&data1, &res));
	assert(ListSearchIndexOf(&head, list, 3, &res));
	assert(StudentEqual(&data3, &res));
	assert(ListSearchIndexOf(&head, list, 4, &res));
	assert(StudentEqual(&data2, &res));
	assert(ListSearchIndexOf(&head, list, 5, &res));
	assert(StudentEqual(&data4, &res));
	assert(!ListSearchIndexOf(&head, list, 6, &res));
	ShowAllStudentsInfo(&head);

	assert(ListInsert(&head, list, 6, &data7));
	assert(ListLength(&head, list) == 7);
	assert(!ListSearchIndexOf(&head, list, -1, &res));
	assert(ListSearchIndexOf(&head, list, 0, &res));
	assert(StudentEqual(&data6, &res));
	assert(ListSearchIndexOf(&head, list, 1, &res));
	assert(StudentEqual(&data5, &res));
	assert(ListSearchIndexOf(&head, list, 2, &res));
	assert(StudentEqual(&data1, &res));
	assert(ListSearchIndexOf(&head, list, 3, &res));
	assert(StudentEqual(&data3, &res));
	assert(ListSearchIndexOf(&head, list, 4, &res));
	assert(StudentEqual(&data2, &res));
	assert(ListSearchIndexOf(&head, list, 5, &res));
	assert(StudentEqual(&data4, &res));
	assert(ListSearchIndexOf(&head, list, 6, &res));
	assert(StudentEqual(&data7, &res));
	assert(!ListSearchIndexOf(&head, list, 7, &res));
	ShowAllStudentsInfo(&head);

	assert(ListInsert(&head, list, 3, &data8));
	assert(ListLength(&head, list) == 8);
	assert(!ListSearchIndexOf(&head, list, -1, &res));
	assert(ListSearchIndexOf(&head, list, 0, &res));
	assert(StudentEqual(&data6, &res));
	assert(ListSearchIndexOf(&head, list, 1, &res));
	assert(StudentEqual(&data5, &res));
	assert(ListSearchIndexOf(&head, list, 2, &res));
	assert(StudentEqual(&data1, &res));
	assert(ListSearchIndexOf(&head, list, 3, &res));
	assert(StudentEqual(&data8, &res));
	assert(ListSearchIndexOf(&head, list, 4, &res));
	assert(StudentEqual(&data3, &res));
	assert(ListSearchIndexOf(&head, list, 5, &res));
	assert(StudentEqual(&data2, &res));
	assert(ListSearchIndexOf(&head, list, 6, &res));
	assert(StudentEqual(&data4, &res));
	assert(ListSearchIndexOf(&head, list, 7, &res));
	assert(StudentEqual(&data7, &res));
	assert(!ListSearchIndexOf(&head, list, 8, &res));
	ShowAllStudentsInfo(&head);

	//删除节点
	assert(!ListDeleteIndexOf(&head, list, -1, NULL));
	assert(!ListDeleteIndexOf(&head, list, -1, &res));
	assert(!ListDeleteIndexOf(&head, list, 8, NULL));
	assert(!ListDeleteIndexOf(&head, list, 8, &res));

	ShowAllStudentsInfo(&head);

	assert(ListDeleteIndexOf(&head, list, 0, &res));
	ShowStudentInfo(&res);
	assert(StudentEqual(&res, &data6));
	assert(ListLength(&head, list) == 7);
	ShowAllStudentsInfo(&head);

	assert(ListDeleteIndexOf(&head, list, 6, &res));
	assert(StudentEqual(&res, &data7));
	assert(ListLength(&head, list) == 6);
	ShowAllStudentsInfo(&head);

	assert(ListDeleteIndexOf(&head, list, 3, NULL));
	assert(ListLength(&head, list) == 5);
	ShowAllStudentsInfo(&head);

	assert(!ListSearchIndexOf(&head, list, -1, &res));
	assert(ListSearchIndexOf(&head, list, 0, &res));
	assert(StudentEqual(&data5, &res));
	assert(ListSearchIndexOf(&head, list, 1, &res));
	assert(StudentEqual(&data1, &res));
	assert(ListSearchIndexOf(&head, list, 2, &res));
	assert(StudentEqual(&data8, &res));
	assert(ListSearchIndexOf(&head, list, 3, &res));
	assert(StudentEqual(&data2, &res));
	assert(ListSearchIndexOf(&head, list, 4, &res));
	assert(StudentEqual(&data4, &res));
	assert(!ListSearchIndexOf(&head, list, 5, &res));
	assert(!ListSearchIndexOf(&head, list, 6, &res));

	//链表排序
	ListSort(&head, list, StudentLessthan);

	assert(!ListSearchIndexOf(&head, list, -1, &res));
	assert(ListSearchIndexOf(&head, list, 0, &res));
	assert(StudentEqual(&data4, &res));
	assert(ListSearchIndexOf(&head, list, 1, &res));
	assert(StudentEqual(&data2, &res));
	assert(ListSearchIndexOf(&head, list, 2, &res));
	assert(StudentEqual(&data1, &res));
	assert(ListSearchIndexOf(&head, list, 3, &res));
	assert(StudentEqual(&data5, &res));
	assert(ListSearchIndexOf(&head, list, 4, &res));
	assert(StudentEqual(&data8, &res));
	assert(!ListSearchIndexOf(&head, list, 5, &res));
	assert(!ListSearchIndexOf(&head, list, 6, &res));

	ShowAllStudentsInfo(&head);

	ListSort(&head, list, StudentBiggerthan);

	assert(!ListSearchIndexOf(&head, list, -1, &res));
	assert(ListSearchIndexOf(&head, list, 0, &res));
	assert(StudentEqual(&data8, &res));
	assert(ListSearchIndexOf(&head, list, 1, &res));
	assert(StudentEqual(&data5, &res));
	assert(ListSearchIndexOf(&head, list, 2, &res));
	assert(StudentEqual(&data1, &res));
	assert(ListSearchIndexOf(&head, list, 3, &res));
	assert(StudentEqual(&data2, &res));
	assert(ListSearchIndexOf(&head, list, 4, &res));
	assert(StudentEqual(&data4, &res));
	assert(!ListSearchIndexOf(&head, list, 5, &res));
	assert(!ListSearchIndexOf(&head, list, 6, &res));

	ShowAllStudentsInfo(&head);

	//销毁链表
	ListDestroy(&head, list);
	assert(head.list.pNext == NULL);
	assert(ListLength(&head, list) == 0);

	ShowAllStudentsInfo(&head);

	return 0;
}

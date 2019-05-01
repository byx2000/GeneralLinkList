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
	List list;        //����Ľṹ������λ�ð���һ��List��Ա������������������ָ��
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
	//����ͨ������
	Test();

	/*
		ͨ�������ʹ��ʾ��
		ѧ����Ϣչʾ
	*/

	Student head;

	//��������
	ListCreate(&head, list);

	int n;
	printf("������ѧ��������");
	scanf("%d", &n);

	/*
		�������ݣ�
		1001 XiaoMing 19 95
		1002 XiaoHong 19 80
		1003 XiaoHua 20 85
		1004 XiaoJun 19 55
		1005 ZhangSan 20 60
	*/
	printf("\n��������������ѧ����ѧ�š�����������ͷ�����\n");
	Student data;
	for (int i = 0; i < n; ++i)
	{
		scanf("%u %s %d %lf", &data.id, data.name, &data.age, &data.score);
		//׷�ӽڵ�
		ListAppend(&head, list, &data);
	}

	//�������ѧ����Ϣ
	printf("\n����ѧ����Ϣ���£�\n");
	ListTraverse(&head, list, StudentPrint);

	//����������
	printf("\n���ճɼ���������\n");
	ListSort(&head, list, StudentCmpByScore);
	ListTraverse(&head, list, StudentPrint);

	//������������Ϊ20���ѧ��
	int cnt = ListNodeCount(&head, list, IsAge20);
	PStudent pRes = (PStudent)malloc(sizeof(Student) * cnt);
	ListSearch(&head, list, IsAge20, pRes);
	printf("\n�����������20���ѧ����\n");
	for (int i = 0; i < cnt; ++i)
	{
		StudentPrint(pRes + i);
	}
	free(pRes);

	//ɾ��ѧ��Ϊ1001��ѧ��
	cnt = ListNodeCount(&head, list, IsId1001);
	pRes = (PStudent)malloc(sizeof(Student) * cnt);
	ListDelete(&head, list, IsId1001, pRes);
	printf("\nɾ��ѧ��Ϊ1001��ѧ����\n");
	ListTraverse(&head, list, StudentPrint);
	printf("\nɾ��ѧ������Ϣ��\n");
	for (int i = 0; i < cnt; ++i)
	{
		StudentPrint(pRes + i);
	}
	free(pRes);

	printf("\n");
	return 0;
}

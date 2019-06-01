/*
	ͨ������
*/

#pragma once

/*����ڵ�ṹ�� ֻ����ָ����*/
typedef struct Node
{
	struct Node* pNext;
}Node, *PNode;

typedef Node List;
typedef PNode PList;

/*���庯��ָ�����*/
typedef void(*Proc)(const void*);
typedef void(*Update)(void*);
typedef int(*IsTarget)(const void*);
typedef int(*LessThan)(const void*, const void*);
typedef int(*Equal)(const void*, const void*);
typedef int(*BiggerThan)(const void*, const void*);

/*��ȡ�ṹ���Ա�ĵ�ַ*/
#define MemberAddr(pStruct, member) (&(pStruct)->member)

/*��ȡ�ṹ���С*/
#define StructSize(pStruct) (sizeof(*(pStruct)))

/*��ȡ�ṹ���Աƫ����*/
#define StructMemberOffset(pStruct, member) ((int)MemberAddr((pStruct), member) - (int)(pStruct))

/*����ӿ�*/

/*
	��������
	pStructHead: ��Ϊͷ�ڵ�Ľṹ���ַ
	listMember: �����Ա����
*/
#define ListCreate(pStructHead, listMember) \
    _ListCreate( \
    MemberAddr((pStructHead), listMember))

/*
	׷�ӽڵ�
	pStructHead: ��Ϊͷ�ڵ�Ľṹ���ַ
	listMember: �����Ա����
	pData: Ҫ׷�ӵ����ݵ�ַ
*/
#define ListAppend(pStructHead, listMember, pData) \
    _ListAppend(\
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    (pData), \
    StructSize(pStructHead))

/*
	��ȡ������
	pStructHead: ��Ϊͷ�ڵ�Ľṹ���ַ
	listMember: �����Ա����
*/
#define ListLength(pStructHead, listMember) \
    _ListLength(\
    MemberAddr((pStructHead), listMember))

/*
	��������
	pStructHead: ��Ϊͷ�ڵ�Ľṹ���ַ
	listMember: �����Ա����
	op: ��ÿ���ڵ���в����ĺ���ָ��
*/
#define ListTraverse(pStructHead, listMember, op) \
    _ListTraverse(\
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    (Proc)(op))

/*
	��������
	pStructHead: ��Ϊͷ�ڵ�Ľṹ���ַ
	listMember: �����Ա����
*/
#define ListDestroy(pStructHead, listMember) \
    _ListDestroy(\
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember))

/*
	�������������Ľڵ��Ƿ����
	pStructHead: ��Ϊͷ�ڵ�Ľṹ���ַ
	listMember: �����Ա����
	isTarget: �ж��Ƿ���Ŀ��ڵ�ĺ���ָ��
	pRes: ���յ�һ���ҵ��Ľڵ�����ݣ�ΪNULL��ʾ�����ս��
	����ֵ: 1��ʾ���ڣ�0��ʾ������
*/
#define ListNodeExist(pStructHead, listMember, isTarget, pRes) \
    _ListNodeExist(\
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (IsTarget)(isTarget), \
    (pRes))

/*
	��ȡ���������Ľڵ�ĸ���
	pStructHead: ��Ϊͷ�ڵ�Ľṹ���ַ
	listMember: �����Ա����
	isTarget: �ж��Ƿ���Ŀ��ڵ�ĺ���ָ��
	����ֵ��Ŀ��ڵ�ĸ���
*/
#define ListNodeCount(pStructHead, listMember, isTarget) \
	_ListNodeCount( \
	MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
	(IsTarget)(isTarget))

/*
	�����������������Ľڵ�
	pStructHead: ��Ϊͷ�ڵ�Ľṹ���ַ
	listMember: �����Ա����
	isTarget: �ж��Ƿ���Ŀ��ڵ�ĺ���ָ��
	pRes: �����������������Ľڵ�����
	����ֵ: ���������Ľڵ�ĸ���
*/
#define ListSearch(pStructHead, listMember, isTarget, pRes) \
	_ListSearch( \
	MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
	StructSize(pStructHead), \
	(IsTarget)(isTarget), \
    (pRes))

/*
	ɾ�����������Ľڵ�
	pStructHead: ��Ϊͷ�ڵ�Ľṹ���ַ
	listMember: �����Ա����
	isTarget: �ж��Ƿ���Ŀ��ڵ�ĺ���ָ��
	pRes: �洢ɾ���ڵ����ݵ�ָ�룬ΪNULL��ʾ�����ս��
	����ֵ: ɾ���ڵ�ĸ���
*/
#define ListDelete(pStructHead, listMember, isTarget, pRes) \
    _ListDelete( \
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (IsTarget)(isTarget), \
    (pRes))

/*
	������������
	pStructHead: ��Ϊͷ�ڵ�Ľṹ���ַ
	listMember: �����Ա����
	lessthan: �ж������ڵ�����С�ڹ�ϵ�ĺ���ָ��
*/
#define ListSort(pStructHead, listMember, lessthan) \
    _ListSort( \
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (LessThan)(lessthan))

/*
	��ȡָ���±�Ľڵ�
	pStructHead: ��Ϊͷ�ڵ�Ľṹ���ַ
	listMember: �����Ա����
	index: �ڵ���±�
	pRes: �洢���ҽ����ָ�룬ΪNULL��ʾ�����ս��
	����ֵ: 1��ʾ���ҳɹ���0��ʾ����ʧ��
*/
#define ListIndexOf(pStructHead, listMember, index, pRes) \
    _ListIndexOf( \
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (int)(index), \
    (void*)(pRes))

/*
	��ĳ�ڵ�ǰ����ڵ�
	pStructHead: ��Ϊͷ�ڵ�Ľṹ���ַ
	listMember: �����Ա����
	index: �ڵ�index���ڵ�ǰ����ڵ㣬��������½ڵ���±�Ϊindex
	pData: Ҫ����Ľڵ�����ָ��
	����ֵ: 1��ʾ����ɹ���0��ʾ����ʧ��
*/
#define ListInsert(pStructHead, listMember, index, pData) \
	_ListInsert( \
	MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (int)(index), \
    (void*)(pData))

/*
	ɾ��ָ���±�Ľڵ�
	pStructHead: ��Ϊͷ�ڵ�Ľṹ���ַ
	listMember: �����Ա����
	index: Ҫɾ���Ľڵ��±�
	pRes: �洢ɾ���ڵ����ݵ�ָ�룬ΪNULL��ʾ�����ս��
	����ֵ: 1��ʾɾ���ɹ���0��ʾɾ��ʧ��
*/
#define ListDeleteIndexOf(pStructHead, listMember, index, pRes) \
	_ListDeleteIndexOf( \
	MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (int)(index), \
    (void*)(pRes))

/*�ڲ�����*/
void _SwapData(void* pData1, void* pData2, int dataSize, int offset);
void _ListCreate(PNode pHead);
void _ListAppend(PNode pHead, int offset, void* pData, int dataSize);
int  _ListLength(const PNode pHead);
void _ListTraverse(const PNode pHead, int offset, Proc op);
void _ListDestroy(PNode pHead, int offset);
int  _ListNodeExist(const PNode pHead, int offset, int dataSize, IsTarget isTarget, void* pRes);
int  _ListNodeCount(const PNode pHead, int offset, IsTarget isTarget);
int  _ListSearch(const PNode pHead, int offset, int dataSize, IsTarget isTarget, void* pRes);
int  _ListIndexOf(const PNode pHead, int offset, int dataSize, int index, void* pRes);
int  _ListDelete(PNode pHead, int offset, int dataSize, IsTarget isTarget, void* pRes);
int  _ListDeleteIndexOf(PNode pHead, int offset, int dataSize, int index, void* pRes);
void _ListSort(const PNode pHead, int offset, int dataSize, LessThan lessthan);
int  _ListInsert(PNode pHead, int offset, int dataSize, int index, const void* pData);

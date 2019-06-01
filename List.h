/*
	通用链表
*/

#pragma once

/*链表节点结构体 只包含指针域*/
typedef struct Node
{
	struct Node* pNext;
}Node, *PNode;

typedef Node List;
typedef PNode PList;

/*定义函数指针别名*/
typedef void(*Proc)(const void*);
typedef void(*Update)(void*);
typedef int(*IsTarget)(const void*);
typedef int(*LessThan)(const void*, const void*);
typedef int(*Equal)(const void*, const void*);
typedef int(*BiggerThan)(const void*, const void*);

/*获取结构体成员的地址*/
#define MemberAddr(pStruct, member) (&(pStruct)->member)

/*获取结构体大小*/
#define StructSize(pStruct) (sizeof(*(pStruct)))

/*获取结构体成员偏移量*/
#define StructMemberOffset(pStruct, member) ((int)MemberAddr((pStruct), member) - (int)(pStruct))

/*对外接口*/

/*
	创建链表
	pStructHead: 作为头节点的结构体地址
	listMember: 链表成员名称
*/
#define ListCreate(pStructHead, listMember) \
    _ListCreate( \
    MemberAddr((pStructHead), listMember))

/*
	追加节点
	pStructHead: 作为头节点的结构体地址
	listMember: 链表成员名称
	pData: 要追加的数据地址
*/
#define ListAppend(pStructHead, listMember, pData) \
    _ListAppend(\
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    (pData), \
    StructSize(pStructHead))

/*
	获取链表长度
	pStructHead: 作为头节点的结构体地址
	listMember: 链表成员名称
*/
#define ListLength(pStructHead, listMember) \
    _ListLength(\
    MemberAddr((pStructHead), listMember))

/*
	遍历链表
	pStructHead: 作为头节点的结构体地址
	listMember: 链表成员名称
	op: 对每个节点进行操作的函数指针
*/
#define ListTraverse(pStructHead, listMember, op) \
    _ListTraverse(\
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    (Proc)(op))

/*
	销毁链表
	pStructHead: 作为头节点的结构体地址
	listMember: 链表成员名称
*/
#define ListDestroy(pStructHead, listMember) \
    _ListDestroy(\
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember))

/*
	查找满足条件的节点是否存在
	pStructHead: 作为头节点的结构体地址
	listMember: 链表成员名称
	isTarget: 判断是否是目标节点的函数指针
	pRes: 接收第一次找到的节点的数据，为NULL表示不接收结果
	返回值: 1表示存在，0表示不存在
*/
#define ListNodeExist(pStructHead, listMember, isTarget, pRes) \
    _ListNodeExist(\
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (IsTarget)(isTarget), \
    (pRes))

/*
	获取满足条件的节点的个数
	pStructHead: 作为头节点的结构体地址
	listMember: 链表成员名称
	isTarget: 判断是否是目标节点的函数指针
	返回值：目标节点的个数
*/
#define ListNodeCount(pStructHead, listMember, isTarget) \
	_ListNodeCount( \
	MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
	(IsTarget)(isTarget))

/*
	搜索所有满足条件的节点
	pStructHead: 作为头节点的结构体地址
	listMember: 链表成员名称
	isTarget: 判断是否是目标节点的函数指针
	pRes: 接收所有满足条件的节点数据
	返回值: 满足条件的节点的个数
*/
#define ListSearch(pStructHead, listMember, isTarget, pRes) \
	_ListSearch( \
	MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
	StructSize(pStructHead), \
	(IsTarget)(isTarget), \
    (pRes))

/*
	删除满足条件的节点
	pStructHead: 作为头节点的结构体地址
	listMember: 链表成员名称
	isTarget: 判断是否是目标节点的函数指针
	pRes: 存储删除节点数据的指针，为NULL表示不接收结果
	返回值: 删除节点的个数
*/
#define ListDelete(pStructHead, listMember, isTarget, pRes) \
    _ListDelete( \
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (IsTarget)(isTarget), \
    (pRes))

/*
	链表升序排序
	pStructHead: 作为头节点的结构体地址
	listMember: 链表成员名称
	lessthan: 判断两个节点数据小于关系的函数指针
*/
#define ListSort(pStructHead, listMember, lessthan) \
    _ListSort( \
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (LessThan)(lessthan))

/*
	获取指定下标的节点
	pStructHead: 作为头节点的结构体地址
	listMember: 链表成员名称
	index: 节点的下标
	pRes: 存储查找结果的指针，为NULL表示不接收结果
	返回值: 1表示查找成功，0表示查找失败
*/
#define ListIndexOf(pStructHead, listMember, index, pRes) \
    _ListIndexOf( \
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (int)(index), \
    (void*)(pRes))

/*
	在某节点前插入节点
	pStructHead: 作为头节点的结构体地址
	listMember: 链表成员名称
	index: 在第index个节点前插入节点，即插入后新节点的下标为index
	pData: 要插入的节点数据指针
	返回值: 1表示插入成功，0表示插入失败
*/
#define ListInsert(pStructHead, listMember, index, pData) \
	_ListInsert( \
	MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (int)(index), \
    (void*)(pData))

/*
	删除指定下标的节点
	pStructHead: 作为头节点的结构体地址
	listMember: 链表成员名称
	index: 要删除的节点下标
	pRes: 存储删除节点数据的指针，为NULL表示不接收结果
	返回值: 1表示删除成功，0表示删除失败
*/
#define ListDeleteIndexOf(pStructHead, listMember, index, pRes) \
	_ListDeleteIndexOf( \
	MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (int)(index), \
    (void*)(pRes))

/*内部函数*/
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

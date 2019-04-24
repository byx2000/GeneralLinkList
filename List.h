/*
	通用链表
*/

#pragma once

#define MemberAddr(pStruct, member) (&(pStruct)->member)
#define StructSize(pStruct) (sizeof(*(pStruct)))
#define StructMemberOffset(pStruct, member) ((int)MemberAddr((pStruct), member) - (int)(pStruct))

typedef struct Node
{
	struct Node* pNext;
}Node, *PNode;

typedef void(*Proc)(const void*);
typedef int(*IsTarget)(const void*);
typedef int(*LessThan)(const void*, const void*);
typedef int(*Equal)(const void*, const void*);
typedef int(*BiggerThan)(const void*, const void*);

void _SwapData(void* pData1, void* pData2, int dataSize, int offset);
void _ListCreate(PNode pHead, int offset);
void _ListAppend(PNode pHead, int offset, void* pData, int dataSize);
int  _ListLength(const PNode pHead);
void _ListTraverse(const PNode pHead, int offset, Proc op);
void _ListDestroy(PNode pHead, int offset);
int  _ListSearch(const PNode pHead, int offset, int dataSize, IsTarget isTarget, void* pRes);
int  _ListSearchIndexOf(const PNode pHead, int offset, int dataSize, int index, void* pRes);
int  _ListDelete(PNode pHead, int offset, int dataSize, IsTarget isTarget, void* pRes);
int  _ListDeleteIndexOf(PNode pHead, int offset, int dataSize, int index, void* pRes);
void _ListSort(const PNode pHead, int offset, int dataSize, LessThan lessthan);
int  _ListInsert(PNode pHead, int offset, int dataSize, int index, const void* pData); //在第index个节点之前插入，即插入后该节点的下标为index

#define ListCreate(pStructHead, listMember) \
    _ListCreate( \
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember))

#define ListAppend(pStructHead, listMember, pData) \
    _ListAppend(\
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    (pData), \
    StructSize(pStructHead))

#define ListLength(pStructHead, listMember) \
    _ListLength(\
    MemberAddr((pStructHead), listMember))

#define ListTraverse(pStructHead, listMember, op) \
    _ListTraverse(\
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    (Proc)(op))

#define ListDestroy(pStructHead, listMember) \
    _ListDestroy(\
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember))

#define ListSearch(pStructHead, listMember, isTarget, pRes) \
    _ListSearch(\
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (IsTarget)(isTarget), \
    (pRes))

#define ListDelete(pStructHead, listMember, isTarget, pRes) \
    _ListDelete(\
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (IsTarget)(isTarget), \
    (pRes))

#define ListSort(pStructHead, listMember, lessthan) \
    _ListSort( \
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (LessThan)(lessthan))

#define ListSearchIndexOf(pStructHead, listMember, index, pRes) \
    _ListSearchIndexOf( \
    MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (int)(index), \
    (void*)(pRes))

#define ListInsert(pStructHead, listMember, index, pData) \
	_ListInsert( \
	MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (int)(index), \
    (void*)(pData))

#define ListDeleteIndexOf(pStructHead, listMember, index, pRes) \
	_ListDeleteIndexOf( \
	MemberAddr((pStructHead), listMember), \
    StructMemberOffset((pStructHead), listMember), \
    StructSize(pStructHead), \
    (int)(index), \
    (void*)(pRes))


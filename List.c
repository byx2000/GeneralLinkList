#include "List.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>

void _SwapData(void* pData1, void* pData2, int dataSize, int offset)
{
	int size1 = offset, size2 = dataSize - offset - sizeof(Node);
	if (size1 != 0)
	{
		void* pt1 = malloc(size1);
		memcpy(pt1, pData1, size1);
		memcpy(pData1, pData2, size1);
		memcpy(pData2, pt1, size1);
		free(pt1);
	}
	if (size2 != 0)
	{
		void* pt2 = malloc(size2);
		memcpy(pt2, (void*)((int)pData1 + offset + sizeof(Node)), size2);
		memcpy((void*)((int)pData1 + offset + sizeof(Node)), (void*)((int)pData2 + offset + sizeof(Node)), size2);
		memcpy((void*)((int)pData2 + offset + sizeof(Node)), pt2, size2);
		free(pt2);
	}
}

void _ListCreate(PNode pHead)
{
	pHead->pNext = NULL;
}

void _ListAppend(PNode pHead, int offset, void* pData, int dataSize)
{
	PNode p = pHead;
	while (p->pNext != NULL)
	{
		p = p->pNext;
	}
	void* pNew = malloc(dataSize);
	memcpy(pNew, pData, dataSize);
	((PNode)((int)pNew + offset))->pNext = NULL;
	p->pNext = ((PNode)((int)pNew + offset));
}

int  _ListLength(const PNode pHead)
{
	PNode p = pHead->pNext;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->pNext;
	}
	return len;
}

void _ListTraverse(const PNode pHead, int offset, Proc op)
{
	PNode p = pHead->pNext;
	while (p != NULL)
	{
		op((void*)((int)p - offset));
		p = p->pNext;
	}
}

void _ListDestroy(PNode pHead, int offset)
{
	PNode p = pHead->pNext;
	while (p != NULL)
	{
		PNode t = p;
		p = p->pNext;
		free((void*)((int)t - offset));
	}
	pHead->pNext = NULL;
}

int  _ListNodeExist(const PNode pHead, int offset, int dataSize, IsTarget isTarget, void* pRes)
{
	PNode p = pHead->pNext;
	while (p != NULL)
	{
		void* pData = (void*)((int)p - offset);
		if (isTarget(pData))
		{
			if (pRes != NULL)
			{
				memcpy(pRes, pData, dataSize);
			}
			return 1;
		}
		p = p->pNext;
	}
	return 0;
}

int _ListNodeCount(const PNode pHead, int offset, IsTarget isTarget)
{
	PNode p = pHead->pNext;
	int cnt = 0;
	while (p != NULL)
	{
		void* pData = (void*)((int)p - offset);
		if (isTarget(pData))
		{
			cnt++;
		}
		p = p->pNext;
	}
	return cnt;
}

int _ListSearch(const PNode pHead, int offset, int dataSize, IsTarget isTarget, void * pRes)
{
	PNode p = pHead->pNext;
	int cnt = 0;
	while (p != NULL)
	{
		void* pData = (void*)((int)p - offset);
		if (isTarget(pData))
		{
			cnt++;
			if (pRes != NULL)
			{
				memcpy(pRes, pData, dataSize);
				pRes = (void*)((int)pRes + dataSize);
			}
		}
		p = p->pNext;
	}
	return cnt;
}

int  _ListIndexOf(const PNode pHead, int offset, int dataSize, int index, void* pRes)
{
	if (index < 0)
	{
		return 0;
	}

	PNode p = pHead->pNext;
	while (index--)
	{
		if (p != NULL)
		{
			p = p->pNext;
		}
		else
		{
			return 0;
		}
	}

	if (p == NULL)
	{
		return 0;
	}

	if (pRes != NULL)
	{
		void* pData = (void*)((int)p - offset);
		memcpy(pRes, pData, dataSize);
	}

	return 1;
}

int  _ListDelete(PNode pHead, int offset, int dataSize, IsTarget isTarget, void* pRes)
{
	PNode p1 = pHead, p2 = pHead->pNext;
	int cnt = 0;
	while (p2 != NULL)
	{
		void* pData = (void*)((int)p2 - offset);
		if (isTarget(pData))
		{
			cnt++;
			if (pRes != NULL)
			{
				memcpy(pRes, pData, dataSize);
				pRes = (void*)((int)pRes + dataSize);
			}
			p1->pNext = p2->pNext;
			p2 = p1->pNext;
			free(pData);
			continue;
		}
		p1 = p2;
		p2 = p2->pNext;
	}
	return cnt;
}

int  _ListDeleteIndexOf(PNode pHead, int offset, int dataSize, int index, void* pRes)
{
	if (index < 0)
	{
		return 0;
	}

	PNode p = pHead;
	while (index--)
	{
		if (p != NULL)
		{
			p = p->pNext;
		}
		else
		{
			return 0;
		}
	}

	if (p->pNext == NULL)
	{
		return 0;
	}

	if (pRes != NULL)
	{
		void* pData = (void*)((int)(p->pNext) - offset);
		memcpy(pRes, pData, dataSize);
	}

	PNode t = p->pNext;
	p->pNext = p->pNext->pNext;
	free((void*)((int)t - offset));

	return 1;
}

void _ListSort(const PNode pHead, int offset, int dataSize, LessThan lessthan)
{
	PNode p1 = pHead->pNext;
	while (p1 != NULL)
	{
		PNode p2 = p1->pNext;
		while (p2 != NULL)
		{
			void* pData1 = (void*)((int)p1 - offset);
			void* pData2 = (void*)((int)p2 - offset);
			if (lessthan(pData2, pData1))
			{
				_SwapData(pData1, pData2, dataSize, offset);
			}
			p2 = p2->pNext;
		}
		p1 = p1->pNext;
	}
}

int  _ListInsert(PNode pHead, int offset, int dataSize, int index, const void* pData)
{
	if (index < 0)
	{
		return 0;
	}

	PNode p = pHead;
	while (index--)
	{
		if (p != NULL)
		{
			p = p->pNext;
		}
		else
		{
			return 0;
		}
	}

	if (p == NULL)
	{
		return 0;
	}

	void* pNew = malloc(dataSize);
	memcpy(pNew, pData, dataSize);
	((PNode)((int)pNew + offset))->pNext = p->pNext;
	p->pNext = ((PNode)((int)pNew + offset));

	return 1;
}

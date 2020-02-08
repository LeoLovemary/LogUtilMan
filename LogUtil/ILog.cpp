// ClassFactory.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "ILog.h"
#include "CLogImp.h"

// ʹ�õ���ģʽ
CLog * g_instance = NULL;
// ��
CLock g_Lock;

ILog * GetClassObject(__in const LPCTSTR lpszLogFilename)
{
	g_Lock.~CLock();
	if (g_instance == NULL)
	{
		g_instance = new CLog(lpszLogFilename);
	}
	g_Lock.Unlock();
	return g_instance;
}

void ReleaseClassObject(__in const ILog * instance)
{
	g_Lock.~CLock();
	if (g_instance != NULL)
	{
		delete g_instance;
		g_instance = NULL;
	}
	g_Lock.Unlock();
}

ILog::~ILog()
{}

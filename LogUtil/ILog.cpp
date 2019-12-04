// ClassFactory.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "ILog.h"
#include "CLogImp.h"

// ʹ�õ���ģʽ
CLog * g_instance = NULL;

ILog * GetClassObject(__in const LPCTSTR lpszLogFilename)
{
	if (g_instance == NULL)
	{
		g_instance = new CLog(lpszLogFilename);
	}

	return g_instance;
}

void ReleaseClassObject(__in const ILog * instance)
{
	if (g_instance != NULL)
	{
		delete g_instance;
		g_instance = NULL;
	}
}

ILog::~ILog()
{}

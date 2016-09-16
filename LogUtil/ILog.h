#pragma once

#include <Windows.h>
#include <tchar.h>
#include <strsafe.h>

#ifndef LOGUTIL_EXPORTS
# define DLL_API __declspec (dllimport)
#else
# define DLL_API __declspec (dllexport)
#endif

/*
 * ��־��
 * �Ѿ���ȷ��ʹ�ù���
 *    1������printf�������﷨�ṩ����
 *    2����־�����ٶȺ�Ҫд����������йأ��������ر��ʱ��������΢���ӳ�
 *    3��info��error��debug��warning�ĸ��������־����������᷵���Ѿ�������ϵĴ�����־��Ϣ�ĳ��ȣ�����ʧ�ܷ���0
 * �첽д�룬֧�ָ߲����������������£�
 * +--------------+------------+------------------+--------------------+
 * |  �����߳���  |  ����־��  |  ���������ʱ��  |   ����������ʱ��   |
 * |--------------+------------+------------------+--------------------+
 * |      50      |    15W     |      0.312s      |      1.529s        |
 * +--------------+------------+------------------+--------------------+
 * |     500      |    50W     |      1.029s      |      5.086s        |
 * +--------------+------------+------------------+--------------------+
 * |    1000      |   100W     |      2.012s      |     10.124s        |
 * +--------------+------------+------------------+--------------------+
 */
class DLL_API ILog
{
public:
	virtual ~ILog() = 0;
	virtual size_t info(__in_opt const TCHAR *fmt, ...) = 0;
	virtual size_t error(__in_opt const TCHAR *fmt, ...) = 0;
	virtual size_t debug(__in_opt const TCHAR *fmt, ...) = 0;
	virtual size_t warning(__in_opt const TCHAR *fmt, ...) = 0;
};

extern "C" {
	DLL_API ILog * GetClassObject(__in const LPCTSTR lpszLogFilename);
	DLL_API void ReleaseClassObject(__in const ILog * instance);
}
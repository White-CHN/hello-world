
// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef _SECURE_ATL
    #define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
    #define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#include "targetver.h"
#include "resource.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

// �ر� MFC ��ĳЩ�����������ɷ��ĺ��Եľ�����Ϣ������
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ


#include <afxdisp.h>        // MFC �Զ�����



#ifndef _AFX_NO_OLE_SUPPORT
    #include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
    #include <afxcmn.h>             // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // �������Ϳؼ����� MFC ֧��




#include "..\..\DuiLib\DuiLib.h"

using namespace DuiLib;

#ifdef _WIN64
    #ifdef _DEBUG
        #ifdef _UNICODE
            #pragma comment(lib, "..\\..\\Lib\\DuiLibx64_d.lib")
        #else
            #pragma comment(lib, "..\\..\\Lib\\DuiLibx64A_d.lib")
        #endif
    #else
        #ifdef _UNICODE
            #pragma comment(lib, "..\\..\\Lib\\DuiLibx64.lib")
        #else
            #pragma comment(lib, "..\\..\\Lib\\DuiLibx64A.lib")
        #endif
    #endif
#else
    #ifdef _DEBUG
        #ifdef _UNICODE
            #pragma comment(lib, "..\\..\\Lib\\DuiLib_d.lib")
        #else
            #pragma comment(lib, "..\\..\\Lib\\DuiLibA_d.lib")
        #endif
    #else
        #ifdef _UNICODE
            #pragma comment(lib, "..\\..\\Lib\\DuiLib.lib")
        #else
            #pragma comment(lib, "..\\..\\Lib\\DuiLibA.lib")
        #endif
    #endif
#endif

#import "../../bin/msado15.dll" rename("EOF", "EndOfFile")
using namespace ADODB;

#ifdef _UNICODE
    #if defined _M_IX86
        #pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
    #elif defined _M_X64
        #pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
    #else
        #pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
    #endif
#endif


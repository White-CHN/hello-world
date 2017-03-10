
// DKPManagement.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "DKPManagement.h"
#include "DKPManageFrame.h"

#ifdef _DEBUG
    #define new DEBUG_NEW
#endif


// CDKPManagementApp

BEGIN_MESSAGE_MAP(CDKPManagementApp, CWinApp)
    ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CDKPManagementApp ����

CDKPManagementApp::CDKPManagementApp()
{
    // ֧����������������
    m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

    // TODO: �ڴ˴����ӹ�����룬
    // ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CDKPManagementApp ����

CDKPManagementApp theApp;


// CDKPManagementApp ��ʼ��

BOOL CDKPManagementApp::InitInstance()
{
    // ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
    // ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
    //����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof(InitCtrls);
    // ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
    // �����ؼ��ࡣ
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);

    CWinApp::InitInstance();


    AfxEnableControlContainer();

    // ���� shell ���������Է��Ի������
    // �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
    CShellManager* pShellManager = new CShellManager;

    // ��׼��ʼ��
    // ���δʹ����Щ���ܲ�ϣ����С
    // ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
    // ����Ҫ���ض���ʼ������
    // �������ڴ洢���õ�ע�����
    // TODO: Ӧ�ʵ��޸ĸ��ַ�����
    // �����޸�Ϊ��˾����֯��
    SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

    // ȫ�ֳ�ʼ��
    CDuiPaintManager::Initialize(m_hInstance);
    // ��Դ����
    CDuiPaintManager::SetResourceType(DUILIB_FILE);
    // ��Դ·��
    CDuiString strResourcePath = CDuiPaintManager::GetInstancePath();
    strResourcePath += _T("DKPManagement\\");
    CDuiPaintManager::SetResourcePath(strResourcePath.GetData());

    // ����������
    CDKPManageFrame* pFrame = new CDKPManageFrame;
    pFrame->Create(NULL, _T("Aion DKP Management System"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
    pFrame->CenterWindow();
    m_pMainWnd = CWnd::FromHandle(*pFrame);
    // ��Ϣѭ��
    CDuiPaintManager::MessageLoop();

    CDuiPaintManager::Uninitialize();

    // ɾ�����洴���� shell ��������
    if(pShellManager != NULL)
    {
        delete pShellManager;
    }

    // ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
    //  ����������Ӧ�ó������Ϣ�á�
    return FALSE;
}

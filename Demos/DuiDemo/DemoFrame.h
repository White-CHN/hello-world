#pragma once

#include "ControlsName.h"
using namespace ControlAttributes;

class CDemoFrame
    : public CDuiDlgImplBase
    , public CWebBrowserEventHandler
{
    DUI_DECLARE_MESSAGE_MAP()
public:
    CDemoFrame(void);
    virtual ~CDemoFrame(void);
public:
    void InitWindow() OVERRIDE;
    CDuiString GetSkinFile() OVERRIDE;
    LPCTSTR GetWindowClassName() const OVERRIDE;

    LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) OVERRIDE;

    CDuiControl* CreateControl(LPCTSTR pstrClass) OVERRIDE;

    LPCTSTR QueryControlText(LPCTSTR lpstrId, LPCTSTR lpstrType) OVERRIDE;

    void OnClick(TNotifyUI& msg);
    void OnWindowInit(TNotifyUI& msg);
    void OnValueChanged(TNotifyUI& msg);
    void OnValueChangedMove(TNotifyUI& msg);
    void OnItemSelect(TNotifyUI& msg);
    void OnSelectChanged(TNotifyUI& msg);
    void OnColorChanged(TNotifyUI& msg);
    void OnShowActiveX(TNotifyUI& msg);
    LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) OVERRIDE;

    // WebBrowser
    HRESULT STDMETHODCALLTYPE UpdateUI(CDuiWebBrowser* pWeb) OVERRIDE;
    HRESULT STDMETHODCALLTYPE GetHostInfo(CDuiWebBrowser* pWeb, DOCHOSTUIINFO __RPC_FAR* pInfo) OVERRIDE;
    HRESULT STDMETHODCALLTYPE ShowContextMenu(CDuiWebBrowser* pWeb, DWORD dwID, POINT __RPC_FAR* ppt, IUnknown __RPC_FAR* pcmdtReserved, IDispatch __RPC_FAR* pdispReserved) OVERRIDE;

private:
    BOOL bEnglish;
    BOOL m_bIsSplit;
    CDuiAnimationTabLayout* m_pTabSwitch;
    CDuiSlider* m_pSlider;
    CDuiProgress* m_pProgress;
    CDuiMenuWnd* m_pMenu;
    CDuiCombo* m_pComboControlNames;
    CDuiList* m_pListControl;
    CDuiEdit* m_pEditXML;
    CDuiIcon m_Icon;
    CControlsName m_ControlsName;
};


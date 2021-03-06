#include "StdAfx.h"
#include "DuiScrollBar.h"


namespace DuiLib
{
    IMPLEMENT_DUICONTROL(CDuiScrollBar)

    CDuiScrollBar::CDuiScrollBar(void)
        : m_bHorizontal(FALSE)
        , m_bShowButton1(TRUE)
        , m_bShowButton2(TRUE)
        , m_nScrollPos(0)
        , m_nRange(100)
        , m_nLineSize(8)
        , m_nLastScrollOffset(0)
        , m_nScrollRepeatDelay(0)
        , m_nLastScrollPos(0)
        , m_uThumbState(0)
        , m_uButton1State(0)
        , m_uButton2State(0)
        , m_pOwner(NULL)
    {
        SetFixedWidth(DEFAULT_SCROLLBAR_SIZE);
    }


    CDuiScrollBar::~CDuiScrollBar(void)
    {
    }

    CDuiString CDuiScrollBar::GetClass() const
    {
        return DUI_CTR_SCROLLBAR;
    }

    LPVOID CDuiScrollBar::GetInterface(CDuiString strName)
    {
        if(strName == DUI_CTR_SCROLLBAR)
        {
            return static_cast<CDuiScrollBar*>(this);
        }
        return CDuiControl::GetInterface(strName);
    }

    void CDuiScrollBar::SetOwner(CDuiContainer* pOwner)
    {
        m_pOwner = pOwner;
    }

    void CDuiScrollBar::SetHorizontal(BOOL bHorizontal /*= TRUE*/)
    {
        if(m_bHorizontal == bHorizontal)
        {
            return;
        }

        m_bHorizontal = bHorizontal;
        if(m_bHorizontal)
        {
            if(GetFixedHeight() == 0)
            {
                SetFixedWidth(0);
                SetFixedHeight(DEFAULT_SCROLLBAR_SIZE);
            }
        }
        else
        {
            if(GetFixedWidth() == 0)
            {
                SetFixedWidth(DEFAULT_SCROLLBAR_SIZE);
                SetFixedHeight(0);
            }
        }

        if(m_pOwner != NULL)
        {
            m_pOwner->NeedUpdate();
        }
        else
        {
            NeedParentUpdate();
        }
    }

    int CDuiScrollBar::GetScrollPos() const
    {
        return m_nScrollPos;
    }

    void CDuiScrollBar::SetScrollPos(int nPos)
    {
        if(m_nScrollPos == nPos)
        {
            return;
        }

        m_nScrollPos = nPos;
        if(m_nScrollPos < 0)
        {
            m_nScrollPos = 0;
        }
        if(m_nScrollPos > m_nRange)
        {
            m_nScrollPos = m_nRange;
        }
        SetPos(GetPos());
    }

    void CDuiScrollBar::SetScrollRange(int nRange)
    {
        if(m_nRange == nRange)
        {
            return;
        }

        m_nRange = nRange;
        if(m_nRange < 0)
        {
            m_nRange = 0;
        }
        if(m_nScrollPos > m_nRange)
        {
            m_nScrollPos = m_nRange;
        }
        SetPos(GetPos());
    }

    int CDuiScrollBar::GetScrollRange() const
    {
        return m_nRange;
    }

    int CDuiScrollBar::GetLineSize() const
    {
        return m_nLineSize;
    }

    void CDuiScrollBar::SetLineSize(int nSize)
    {
        m_nLineSize = nSize;
    }

    void CDuiScrollBar::SetShowButton1(BOOL bShow)
    {
        if(m_bShowButton1 == bShow)
        {
            return;
        }
        m_bShowButton1 = bShow;
        SetPos(GetPos());
    }

    void CDuiScrollBar::SetButton1NormalImage(LPCTSTR pStrImage)
    {
        if(m_sButton1NormalImage == pStrImage)
        {
            return;
        }
        m_sButton1NormalImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetButton1HotImage(LPCTSTR pStrImage)
    {
        if(m_sButton1HotImage == pStrImage)
        {
            return;
        }
        m_sButton1HotImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetButton1PushedImage(LPCTSTR pStrImage)
    {
        if(m_sButton1PushedImage == pStrImage)
        {
            return;
        }
        m_sButton1PushedImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetButton1DisabledImage(LPCTSTR pStrImage)
    {
        if(m_sButton1DisabledImage == pStrImage)
        {
            return;
        }
        m_sButton1DisabledImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetShowButton2(BOOL bShow)
    {
        if(m_bShowButton2 == bShow)
        {
            return;
        }
        m_bShowButton2 = bShow;
        SetPos(GetPos());
    }

    void CDuiScrollBar::SetButton2NormalImage(LPCTSTR pStrImage)
    {
        if(m_sButton2NormalImage == pStrImage)
        {
            return;
        }
        m_sButton2NormalImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetButton2HotImage(LPCTSTR pStrImage)
    {
        if(m_sButton2HotImage == pStrImage)
        {
            return;
        }
        m_sButton2HotImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetButton2PushedImage(LPCTSTR pStrImage)
    {
        if(m_sButton2PushedImage == pStrImage)
        {
            return;
        }
        m_sButton2PushedImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetButton2DisabledImage(LPCTSTR pStrImage)
    {
        if(m_sButton2DisabledImage == pStrImage)
        {
            return;
        }
        m_sButton2DisabledImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetThumbNormalImage(LPCTSTR pStrImage)
    {
        if(m_sThumbNormalImage == pStrImage)
        {
            return;
        }
        m_sThumbNormalImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetThumbHotImage(LPCTSTR pStrImage)
    {
        if(m_sThumbHotImage == pStrImage)
        {
            return;
        }
        m_sThumbHotImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetThumbPushedImage(LPCTSTR pStrImage)
    {
        if(m_sThumbPushedImage == pStrImage)
        {
            return;
        }
        m_sThumbPushedImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetThumbDisabledImage(LPCTSTR pStrImage)
    {
        if(m_sThumbDisabledImage == pStrImage)
        {
            return;
        }
        m_sThumbDisabledImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetRailNormalImage(LPCTSTR pStrImage)
    {
        if(m_sRailNormalImage == pStrImage)
        {
            return;
        }
        m_sRailNormalImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetRailHotImage(LPCTSTR pStrImage)
    {
        if(m_sRailHotImage == pStrImage)
        {
            return;
        }
        m_sRailHotImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetRailPushedImage(LPCTSTR pStrImage)
    {
        if(m_sRailPushedImage == pStrImage)
        {
            return;
        }
        m_sRailPushedImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::SetRailDisabledImage(LPCTSTR pStrImage)
    {
        if(m_sRailDisabledImage == pStrImage)
        {
            return;
        }
        m_sRailDisabledImage = pStrImage;
        Invalidate();
    }

    LPCTSTR CDuiScrollBar::GetBkNormalImage()
    {
        return m_sBkNormalImage;
    }

    void CDuiScrollBar::SetBkNormalImage(LPCTSTR pStrImage)
    {
        if(m_sBkNormalImage == pStrImage)
        {
            return;
        }
        m_sBkNormalImage = pStrImage;
        Invalidate();
    }

    LPCTSTR CDuiScrollBar::GetBkHotImage()
    {
        return m_sBkHotImage;
    }

    void CDuiScrollBar::SetBkHotImage(LPCTSTR pStrImage)
    {
        if(m_sBkHotImage == pStrImage)
        {
            return;
        }
        m_sBkHotImage = pStrImage;
        Invalidate();
    }

    LPCTSTR CDuiScrollBar::GetBkPushedImage()
    {
        return m_sBkPushedImage;
    }

    void CDuiScrollBar::SetBkPushedImage(LPCTSTR pStrImage)
    {
        if(m_sBkPushedImage == pStrImage)
        {
            return;
        }
        m_sBkPushedImage = pStrImage;
        Invalidate();
    }

    LPCTSTR CDuiScrollBar::GetBkDisabledImage()
    {
        return m_sBkDisabledImage;
    }

    void CDuiScrollBar::SetBkDisabledImage(LPCTSTR pStrImage)
    {
        if(m_sBkDisabledImage == pStrImage)
        {
            return;
        }
        m_sBkDisabledImage = pStrImage;
        Invalidate();
    }

    void CDuiScrollBar::PaintBk(HDC hDC)
    {
        if(!IsEnabled())
        {
            m_uThumbState |= UISTATE_DISABLED;
        }
        else
        {
            m_uThumbState &= ~ UISTATE_DISABLED;
        }
        if((m_uThumbState & UISTATE_DISABLED) != 0)
        {
            if(!m_sBkDisabledImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sBkDisabledImage))
                {

                }
                else
                {
                    return;
                }
            }
        }
        else if((m_uThumbState & UISTATE_PUSHED) != 0)
        {
            if(!m_sBkPushedImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sBkPushedImage))
                {

                }
                else
                {
                    return;
                }
            }
        }
        else if((m_uThumbState & UISTATE_HOT) != 0)
        {
            if(!m_sBkHotImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sBkHotImage))
                {

                }
                else
                {
                    return;
                }
            }
        }

        if(!m_sBkNormalImage.IsEmpty())
        {
            if(!DrawImage(hDC, (LPCTSTR)m_sBkNormalImage))
            {

            }
            else
            {
                return;
            }
        }
    }

    void CDuiScrollBar::PaintButton1(HDC hDC)
    {
        if(!m_bShowButton1)
        {
            return;
        }

        if(!IsEnabled())
        {
            m_uButton1State |= UISTATE_DISABLED;
        }
        else
        {
            m_uButton1State &= ~ UISTATE_DISABLED;
        }
        int d1 = MulDiv(m_rcButton1.left - GetPos().left, 100, GetManager()->GetDPIObj()->GetScale());
        int d2 = MulDiv(m_rcButton1.top - GetPos().top, 100, GetManager()->GetDPIObj()->GetScale());
        int d3 = MulDiv(m_rcButton1.right - GetPos().left, 100, GetManager()->GetDPIObj()->GetScale());
        int d4 = MulDiv(m_rcButton1.bottom - GetPos().top, 100, GetManager()->GetDPIObj()->GetScale());
        m_sImageModify.Empty();
        m_sImageModify.SmallFormat(_T("dest='%d,%d,%d,%d'"), d1, d2, d3, d4);

        if((m_uButton1State & UISTATE_DISABLED) != 0)
        {
            if(!m_sButton1DisabledImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sButton1DisabledImage, (LPCTSTR)m_sImageModify))
                {

                }
                else
                {
                    return;
                }
            }
        }
        else if((m_uButton1State & UISTATE_PUSHED) != 0)
        {
            if(!m_sButton1PushedImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sButton1PushedImage, (LPCTSTR)m_sImageModify))
                {

                }
                else
                {
                    return;
                }
            }
        }
        else if((m_uButton1State & UISTATE_HOT) != 0)
        {
            if(!m_sButton1HotImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sButton1HotImage, (LPCTSTR)m_sImageModify))
                {

                }
                else
                {
                    return;
                }
            }
        }

        if(!m_sButton1NormalImage.IsEmpty())
        {
            if(!DrawImage(hDC, (LPCTSTR)m_sButton1NormalImage, (LPCTSTR)m_sImageModify))
            {

            }
            else
            {
                return;
            }
        }

        DWORD dwBorderColor = 0xFF85E4FF;
        int nBorderSize = 2;
        CRenderEngine::DrawRect(hDC, m_rcButton1, nBorderSize, dwBorderColor);
    }

    void CDuiScrollBar::PaintButton2(HDC hDC)
    {
        if(!m_bShowButton2)
        {
            return;
        }

        if(!IsEnabled())
        {
            m_uButton2State |= UISTATE_DISABLED;
        }
        else
        {
            m_uButton2State &= ~ UISTATE_DISABLED;
        }
        int d1 = MulDiv(m_rcButton2.left - GetPos().left, 100, GetManager()->GetDPIObj()->GetScale());
        int d2 = MulDiv(m_rcButton2.top - GetPos().top, 100, GetManager()->GetDPIObj()->GetScale());
        int d3 = MulDiv(m_rcButton2.right - GetPos().left, 100, GetManager()->GetDPIObj()->GetScale());
        int d4 = MulDiv(m_rcButton2.bottom - GetPos().top, 100, GetManager()->GetDPIObj()->GetScale());
        m_sImageModify.Empty();
        m_sImageModify.SmallFormat(_T("dest='%d,%d,%d,%d'"), d1 , d2 , d3 , d4);

        if((m_uButton2State & UISTATE_DISABLED) != 0)
        {
            if(!m_sButton2DisabledImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sButton2DisabledImage, (LPCTSTR)m_sImageModify))
                {

                }
                else
                {
                    return;
                }
            }
        }
        else if((m_uButton2State & UISTATE_PUSHED) != 0)
        {
            if(!m_sButton2PushedImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sButton2PushedImage, (LPCTSTR)m_sImageModify))
                {

                }
                else
                {
                    return;
                }
            }
        }
        else if((m_uButton2State & UISTATE_HOT) != 0)
        {
            if(!m_sButton2HotImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sButton2HotImage, (LPCTSTR)m_sImageModify))
                {

                }
                else
                {
                    return;
                }
            }
        }

        if(!m_sButton2NormalImage.IsEmpty())
        {
            if(!DrawImage(hDC, (LPCTSTR)m_sButton2NormalImage, (LPCTSTR)m_sImageModify)) {}
            else
            {
                return;
            }
        }

        DWORD dwBorderColor = 0xFF85E4FF;
        int nBorderSize = 2;
        CRenderEngine::DrawRect(hDC, m_rcButton2, nBorderSize, dwBorderColor);
    }

    void CDuiScrollBar::PaintThumb(HDC hDC)
    {
        if(m_rcThumb.left == 0 && m_rcThumb.top == 0 && m_rcThumb.right == 0 && m_rcThumb.bottom == 0)
        {
            return;
        }
        if(!IsEnabled())
        {
            m_uThumbState |= UISTATE_DISABLED;
        }
        else
        {
            m_uThumbState &= ~ UISTATE_DISABLED;
        }
        int d1 = MulDiv(m_rcThumb.left - GetPos().left, 100, GetManager()->GetDPIObj()->GetScale());
        int d2 = MulDiv(m_rcThumb.top - GetPos().top, 100, GetManager()->GetDPIObj()->GetScale());
        int d3 = MulDiv(m_rcThumb.right - GetPos().left, 100, GetManager()->GetDPIObj()->GetScale());
        int d4 = MulDiv(m_rcThumb.bottom - GetPos().top, 100, GetManager()->GetDPIObj()->GetScale());
        m_sImageModify.Empty();
        m_sImageModify.SmallFormat(_T("dest='%d,%d,%d,%d'"), d1, d2, d3, d4);

        if((m_uThumbState & UISTATE_DISABLED) != 0)
        {
            if(!m_sThumbDisabledImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sThumbDisabledImage, (LPCTSTR)m_sImageModify)) {}
                else
                {
                    return;
                }
            }
        }
        else if((m_uThumbState & UISTATE_PUSHED) != 0)
        {
            if(!m_sThumbPushedImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sThumbPushedImage, (LPCTSTR)m_sImageModify)) {}
                else
                {
                    return;
                }
            }
        }
        else if((m_uThumbState & UISTATE_HOT) != 0)
        {
            if(!m_sThumbHotImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sThumbHotImage, (LPCTSTR)m_sImageModify)) {}
                else
                {
                    return;
                }
            }
        }

        if(!m_sThumbNormalImage.IsEmpty())
        {
            if(!DrawImage(hDC, (LPCTSTR)m_sThumbNormalImage, (LPCTSTR)m_sImageModify)) {}
            else
            {
                return;
            }
        }

        DWORD dwBorderColor = 0xFF85E4FF;
        int nBorderSize = 2;
        CRenderEngine::DrawRect(hDC, m_rcThumb, nBorderSize, dwBorderColor);
    }

    void CDuiScrollBar::PaintRail(HDC hDC)
    {
        if(m_rcThumb.left == 0 && m_rcThumb.top == 0 && m_rcThumb.right == 0 && m_rcThumb.bottom == 0)
        {
            return;
        }
        if(!IsEnabled())
        {
            m_uThumbState |= UISTATE_DISABLED;
        }
        else
        {
            m_uThumbState &= ~ UISTATE_DISABLED;
        }

        m_sImageModify.Empty();
        if(!m_bHorizontal)
        {
            int d1 = MulDiv(m_rcThumb.left - GetPos().left, 100, GetManager()->GetDPIObj()->GetScale());
            int d2 = MulDiv((m_rcThumb.top + m_rcThumb.bottom) / 2 - GetPos().top - GetFixedWidth() / 2, 100, GetManager()->GetDPIObj()->GetScale());
            int d3 = MulDiv(m_rcThumb.right - GetPos().left, 100, GetManager()->GetDPIObj()->GetScale());
            int d4 = MulDiv((m_rcThumb.top + m_rcThumb.bottom) / 2 - GetPos().top + GetFixedWidth() - GetFixedWidth() / 2, 100, GetManager()->GetDPIObj()->GetScale());
            m_sImageModify.SmallFormat(_T("dest='%d,%d,%d,%d'"), d1, d2, d3, d4);
        }
        else
        {
            int d1 = MulDiv((m_rcThumb.left + m_rcThumb.right) / 2 - GetPos().left - GetFixedHeight() / 2, 100, GetManager()->GetDPIObj()->GetScale());
            int d2 = MulDiv(m_rcThumb.top - GetPos().top, 100, GetManager()->GetDPIObj()->GetScale());
            int d3 = MulDiv((m_rcThumb.left + m_rcThumb.right) / 2 - GetPos().left + GetFixedHeight() - GetFixedHeight() / 2, 100, GetManager()->GetDPIObj()->GetScale());
            int d4 = MulDiv(m_rcThumb.bottom - GetPos().top, 100, GetManager()->GetDPIObj()->GetScale());
            m_sImageModify.SmallFormat(_T("dest='%d,%d,%d,%d'"), d1, d2, d3, d4);
        }

        if((m_uThumbState & UISTATE_DISABLED) != 0)
        {
            if(!m_sRailDisabledImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sRailDisabledImage, (LPCTSTR)m_sImageModify)) {}
                else
                {
                    return;
                }
            }
        }
        else if((m_uThumbState & UISTATE_PUSHED) != 0)
        {
            if(!m_sRailPushedImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sRailPushedImage, (LPCTSTR)m_sImageModify)) {}
                else
                {
                    return;
                }
            }
        }
        else if((m_uThumbState & UISTATE_HOT) != 0)
        {
            if(!m_sRailHotImage.IsEmpty())
            {
                if(!DrawImage(hDC, (LPCTSTR)m_sRailHotImage, (LPCTSTR)m_sImageModify)) {}
                else
                {
                    return;
                }
            }
        }

        if(!m_sRailNormalImage.IsEmpty())
        {
            if(!DrawImage(hDC, (LPCTSTR)m_sRailNormalImage, (LPCTSTR)m_sImageModify)) {}
            else
            {
                return;
            }
        }
    }

    void CDuiScrollBar::SetPos(RECT rc, BOOL bNeedInvalidate /*= TRUE*/)
    {
        CDuiControl::SetPos(rc, bNeedInvalidate);
        rc = GetPos();

        if(m_bHorizontal)
        {
            int cx = rc.right - rc.left;
            if(m_bShowButton1)
            {
                cx -= GetFixedHeight();
            }
            if(m_bShowButton2)
            {
                cx -= GetFixedHeight();
            }
            if(cx > GetFixedHeight())
            {
                m_rcButton1.left = rc.left;
                m_rcButton1.top = rc.top;
                if(m_bShowButton1)
                {
                    m_rcButton1.right = rc.left + GetFixedHeight();
                    m_rcButton1.bottom = rc.top + GetFixedHeight();
                }
                else
                {
                    m_rcButton1.right = m_rcButton1.left;
                    m_rcButton1.bottom = m_rcButton1.top;
                }

                m_rcButton2.top = rc.top;
                m_rcButton2.right = rc.right;
                if(m_bShowButton2)
                {
                    m_rcButton2.left = rc.right - GetFixedHeight();
                    m_rcButton2.bottom = rc.top + GetFixedHeight();
                }
                else
                {
                    m_rcButton2.left = m_rcButton2.right;
                    m_rcButton2.bottom = m_rcButton2.top;
                }

                m_rcThumb.top = rc.top;
                m_rcThumb.bottom = rc.top + GetFixedHeight();
                if(m_nRange > 0)
                {
                    int cxThumb = cx * (rc.right - rc.left) / (m_nRange + rc.right - rc.left);
                    if(cxThumb < GetFixedHeight())
                    {
                        cxThumb = GetFixedHeight();
                    }

                    m_rcThumb.left = m_nScrollPos * (cx - cxThumb) / m_nRange + m_rcButton1.right;
                    m_rcThumb.right = m_rcThumb.left + cxThumb;
                    if(m_rcThumb.right > m_rcButton2.left)
                    {
                        m_rcThumb.left = m_rcButton2.left - cxThumb;
                        m_rcThumb.right = m_rcButton2.left;
                    }
                }
                else
                {
                    m_rcThumb.left = m_rcButton1.right;
                    m_rcThumb.right = m_rcButton2.left;
                }
            }
            else
            {
                int cxButton = (rc.right - rc.left) / 2;
                if(cxButton > GetFixedHeight())
                {
                    cxButton = GetFixedHeight();
                }
                m_rcButton1.left = rc.left;
                m_rcButton1.top = rc.top;
                if(m_bShowButton1)
                {
                    m_rcButton1.right = rc.left + cxButton;
                    m_rcButton1.bottom = rc.top + GetFixedHeight();
                }
                else
                {
                    m_rcButton1.right = m_rcButton1.left;
                    m_rcButton1.bottom = m_rcButton1.top;
                }

                m_rcButton2.top = rc.top;
                m_rcButton2.right = rc.right;
                if(m_bShowButton2)
                {
                    m_rcButton2.left = rc.right - cxButton;
                    m_rcButton2.bottom = rc.top + GetFixedHeight();
                }
                else
                {
                    m_rcButton2.left = m_rcButton2.right;
                    m_rcButton2.bottom = m_rcButton2.top;
                }
                m_rcThumb.Empty();
            }
        }
        else
        {
            int cy = rc.bottom - rc.top;
            if(m_bShowButton1)
            {
                cy -= GetFixedWidth();
            }
            if(m_bShowButton2)
            {
                cy -= GetFixedWidth();
            }
            if(cy > GetFixedWidth())
            {
                m_rcButton1.left = rc.left;
                m_rcButton1.top = rc.top;
                if(m_bShowButton1)
                {
                    m_rcButton1.right = rc.left + GetFixedWidth();
                    m_rcButton1.bottom = rc.top + GetFixedWidth();
                }
                else
                {
                    m_rcButton1.right = m_rcButton1.left;
                    m_rcButton1.bottom = m_rcButton1.top;
                }

                m_rcButton2.left = rc.left;
                m_rcButton2.bottom = rc.bottom;
                if(m_bShowButton2)
                {
                    m_rcButton2.top = rc.bottom - GetFixedWidth();
                    m_rcButton2.right = rc.left + GetFixedWidth();
                }
                else
                {
                    m_rcButton2.top = m_rcButton2.bottom;
                    m_rcButton2.right = m_rcButton2.left;
                }

                m_rcThumb.left = rc.left;
                m_rcThumb.right = rc.left + GetFixedWidth();
                if(m_nRange > 0)
                {
                    int cyThumb = cy * (rc.bottom - rc.top) / (m_nRange + rc.bottom - rc.top);
                    if(cyThumb < GetFixedWidth())
                    {
                        cyThumb = GetFixedWidth();
                    }

                    m_rcThumb.top = m_nScrollPos * (cy - cyThumb) / m_nRange + m_rcButton1.bottom;
                    m_rcThumb.bottom = m_rcThumb.top + cyThumb;
                    if(m_rcThumb.bottom > m_rcButton2.top)
                    {
                        m_rcThumb.top = m_rcButton2.top - cyThumb;
                        m_rcThumb.bottom = m_rcButton2.top;
                    }
                }
                else
                {
                    m_rcThumb.top = m_rcButton1.bottom;
                    m_rcThumb.bottom = m_rcButton2.top;
                }
            }
            else
            {
                int cyButton = (rc.bottom - rc.top) / 2;
                if(cyButton > GetFixedWidth())
                {
                    cyButton = GetFixedWidth();
                }
                m_rcButton1.left = rc.left;
                m_rcButton1.top = rc.top;
                if(m_bShowButton1)
                {
                    m_rcButton1.right = rc.left + GetFixedWidth();
                    m_rcButton1.bottom = rc.top + cyButton;
                }
                else
                {
                    m_rcButton1.right = m_rcButton1.left;
                    m_rcButton1.bottom = m_rcButton1.top;
                }

                m_rcButton2.left = rc.left;
                m_rcButton2.bottom = rc.bottom;
                if(m_bShowButton2)
                {
                    m_rcButton2.top = rc.bottom - cyButton;
                    m_rcButton2.right = rc.left + GetFixedWidth();
                }
                else
                {
                    m_rcButton2.top = m_rcButton2.bottom;
                    m_rcButton2.right = m_rcButton2.left;
                }
                m_rcThumb.Empty();
            }
        }
    }

    void CDuiScrollBar::DoPaint(HDC hDC, const RECT& rcPaint)
    {
        if(!::IntersectRect(&GetPaintRect(), &rcPaint, &GetPos()))
        {
            return;
        }
        CDuiControl::DoPaint(hDC, rcPaint);
        PaintBk(hDC);
        PaintButton1(hDC);
        PaintButton2(hDC);
        PaintThumb(hDC);
        PaintRail(hDC);
    }

    void CDuiScrollBar::SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue)
    {
        if(_tcsicmp(pstrName, _T("button1normalimage")) == 0)
        {
            SetButton1NormalImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("button1hotimage")) == 0)
        {
            SetButton1HotImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("button1pushedimage")) == 0)
        {
            SetButton1PushedImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("button1disabledimage")) == 0)
        {
            SetButton1DisabledImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("button2normalimage")) == 0)
        {
            SetButton2NormalImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("button2hotimage")) == 0)
        {
            SetButton2HotImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("button2pushedimage")) == 0)
        {
            SetButton2PushedImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("button2disabledimage")) == 0)
        {
            SetButton2DisabledImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("thumbnormalimage")) == 0)
        {
            SetThumbNormalImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("thumbhotimage")) == 0)
        {
            SetThumbHotImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("thumbpushedimage")) == 0)
        {
            SetThumbPushedImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("thumbdisabledimage")) == 0)
        {
            SetThumbDisabledImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("railnormalimage")) == 0)
        {
            SetRailNormalImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("railhotimage")) == 0)
        {
            SetRailHotImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("railpushedimage")) == 0)
        {
            SetRailPushedImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("raildisabledimage")) == 0)
        {
            SetRailDisabledImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("bknormalimage")) == 0)
        {
            SetBkNormalImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("bkhotimage")) == 0)
        {
            SetBkHotImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("bkpushedimage")) == 0)
        {
            SetBkPushedImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("bkdisabledimage")) == 0)
        {
            SetBkDisabledImage(pstrValue);
        }
        else if(_tcsicmp(pstrName, _T("hor")) == 0)
        {
            SetHorizontal(_tcsicmp(pstrValue, _T("true")) == 0);
        }
        else if(_tcsicmp(pstrName, _T("linesize")) == 0)
        {
            SetLineSize(_ttoi(pstrValue));
        }
        else if(_tcsicmp(pstrName, _T("range")) == 0)
        {
            SetScrollRange(_ttoi(pstrValue));
        }
        else if(_tcsicmp(pstrName, _T("value")) == 0)
        {
            SetScrollPos(_ttoi(pstrValue));
        }
        else if(_tcsicmp(pstrName, _T("showbutton1")) == 0)
        {
            SetShowButton1(_tcsicmp(pstrValue, _T("true")) == 0);
        }
        else if(_tcsicmp(pstrName, _T("showbutton2")) == 0)
        {
            SetShowButton2(_tcsicmp(pstrValue, _T("true")) == 0);
        }
        else
        {
            CDuiControl::SetAttribute(pstrName, pstrValue);
        }
    }

    void CDuiScrollBar::DoEvent(CDuiEvent& event)
    {
        if(!IsMouseEnabled() && event.Type > DUIEVENT__MOUSEBEGIN && event.Type < DUIEVENT__MOUSEEND)
        {
            if(m_pOwner != NULL)
            {
                m_pOwner->DoEvent(event);
            }
            else
            {
                CDuiControl::DoEvent(event);
            }
            return;
        }

        if(event.Type == DUIEVENT_SETFOCUS)
        {
            return;
        }
        if(event.Type == DUIEVENT_KILLFOCUS)
        {
            return;
        }
        if(event.Type == DUIEVENT_BUTTONDOWN || event.Type == DUIEVENT_DBLCLICK)
        {
            if(!IsEnabled())
            {
                return;
            }

            m_nLastScrollOffset = 0;
            m_nScrollRepeatDelay = 0;
            SetTimer(TIMER_ID_SCROLLBAR, 50U);

            if(::PtInRect(&m_rcButton1, event.ptMouse))
            {
                m_uButton1State |= UISTATE_PUSHED;
                if(!m_bHorizontal)
                {
                    if(m_pOwner != NULL)
                    {
                        m_pOwner->LineUp();
                    }
                    else
                    {
                        SetScrollPos(m_nScrollPos - m_nLineSize);
                    }
                }
                else
                {
                    if(m_pOwner != NULL)
                    {
                        m_pOwner->LineLeft();
                    }
                    else
                    {
                        SetScrollPos(m_nScrollPos - m_nLineSize);
                    }
                }
            }
            else if(::PtInRect(&m_rcButton2, event.ptMouse))
            {
                m_uButton2State |= UISTATE_PUSHED;
                if(!m_bHorizontal)
                {
                    if(m_pOwner != NULL)
                    {
                        m_pOwner->LineDown();
                    }
                    else
                    {
                        SetScrollPos(m_nScrollPos + m_nLineSize);
                    }
                }
                else
                {
                    if(m_pOwner != NULL)
                    {
                        m_pOwner->LineRight();
                    }
                    else
                    {
                        SetScrollPos(m_nScrollPos + m_nLineSize);
                    }
                }
            }
            else if(::PtInRect(&m_rcThumb, event.ptMouse))
            {
                m_uThumbState |= UISTATE_CAPTURED | UISTATE_PUSHED;
                m_ptLastMouse = event.ptMouse;
                m_nLastScrollPos = m_nScrollPos;
            }
            else
            {
                if(!m_bHorizontal)
                {
                    if(event.ptMouse.y < m_rcThumb.top)
                    {
                        if(m_pOwner != NULL)
                        {
                            m_pOwner->PageUp();
                        }
                        else
                        {
                            SetScrollPos(m_nScrollPos + GetPos().top - GetPos().bottom);
                        }
                    }
                    else if(event.ptMouse.y > m_rcThumb.bottom)
                    {
                        if(m_pOwner != NULL)
                        {
                            m_pOwner->PageDown();
                        }
                        else
                        {
                            SetScrollPos(m_nScrollPos - GetPos().top + GetPos().bottom);
                        }
                    }
                }
                else
                {
                    if(event.ptMouse.x < m_rcThumb.left)
                    {
                        if(m_pOwner != NULL)
                        {
                            m_pOwner->PageLeft();
                        }
                        else
                        {
                            SetScrollPos(m_nScrollPos + GetPos().left - GetPos().right);
                        }
                    }
                    else if(event.ptMouse.x > m_rcThumb.right)
                    {
                        if(m_pOwner != NULL)
                        {
                            m_pOwner->PageRight();
                        }
                        else
                        {
                            SetScrollPos(m_nScrollPos - GetPos().left + GetPos().right);
                        }
                    }
                }
            }
            if(GetManager() != NULL && m_pOwner == NULL)
            {
                GetManager()->SendNotify(this, DUI_MSGTYPE_SCROLL);
            }
            return;
        }
        if(event.Type == DUIEVENT_BUTTONUP)
        {
            m_nScrollRepeatDelay = 0;
            m_nLastScrollOffset = 0;
            KillTimer(TIMER_ID_SCROLLBAR);

            if((m_uThumbState & UISTATE_CAPTURED) != 0)
            {
                m_uThumbState &= ~(UISTATE_CAPTURED | UISTATE_PUSHED);
                Invalidate();
            }
            else if((m_uButton1State & UISTATE_PUSHED) != 0)
            {
                m_uButton1State &= ~UISTATE_PUSHED;
                Invalidate();
            }
            else if((m_uButton2State & UISTATE_PUSHED) != 0)
            {
                m_uButton2State &= ~UISTATE_PUSHED;
                Invalidate();
            }
            return;
        }
        if(event.Type == DUIEVENT_MOUSEMOVE)
        {
            if((m_uThumbState & UISTATE_CAPTURED) != 0)
            {
                if(!m_bHorizontal)
                {
                    int vRange = GetPos().bottom - GetPos().top - m_rcThumb.bottom + m_rcThumb.top - 2 * GetFixedWidth();
                    if(vRange != 0)
                    {
                        m_nLastScrollOffset = (event.ptMouse.y - m_ptLastMouse.y) * m_nRange / vRange;
                    }
                }
                else
                {
                    int hRange = GetPos().right - GetPos().left - m_rcThumb.right + m_rcThumb.left - 2 * GetFixedHeight();
                    if(hRange != 0)
                    {
                        m_nLastScrollOffset = (event.ptMouse.x - m_ptLastMouse.x) * m_nRange / hRange;
                    }
                }
            }
            else
            {
                if((m_uThumbState & UISTATE_HOT) != 0)
                {
                    if(!::PtInRect(&m_rcThumb, event.ptMouse))
                    {
                        m_uThumbState &= ~UISTATE_HOT;
                        Invalidate();
                    }
                }
                else
                {
                    if(!IsEnabled())
                    {
                        return;
                    }
                    if(::PtInRect(&m_rcThumb, event.ptMouse))
                    {
                        m_uThumbState |= UISTATE_HOT;
                        Invalidate();
                    }
                }
            }
            return;
        }
        if(event.Type == DUIEVENT_CONTEXTMENU)
        {
            return;
        }
        if(event.Type == DUIEVENT_TIMER && event.wParam == TIMER_ID_SCROLLBAR)
        {
            ++m_nScrollRepeatDelay;
            if((m_uThumbState & UISTATE_CAPTURED) != 0)
            {
                if(!m_bHorizontal)
                {
                    if(m_pOwner != NULL) m_pOwner->SetScrollPos(CDuiSize(m_pOwner->GetScrollPos().cx, \
                                m_nLastScrollPos + m_nLastScrollOffset));
                    else
                    {
                        SetScrollPos(m_nLastScrollPos + m_nLastScrollOffset);
                    }
                }
                else
                {
                    if(m_pOwner != NULL) m_pOwner->SetScrollPos(CDuiSize(m_nLastScrollPos + m_nLastScrollOffset, \
                                m_pOwner->GetScrollPos().cy));
                    else
                    {
                        SetScrollPos(m_nLastScrollPos + m_nLastScrollOffset);
                    }
                }
                Invalidate();
            }
            else if((m_uButton1State & UISTATE_PUSHED) != 0)
            {
                if(m_nScrollRepeatDelay <= 5)
                {
                    return;
                }
                if(!m_bHorizontal)
                {
                    if(m_pOwner != NULL)
                    {
                        m_pOwner->LineUp();
                    }
                    else
                    {
                        SetScrollPos(m_nScrollPos - m_nLineSize);
                    }
                }
                else
                {
                    if(m_pOwner != NULL)
                    {
                        m_pOwner->LineLeft();
                    }
                    else
                    {
                        SetScrollPos(m_nScrollPos - m_nLineSize);
                    }
                }
            }
            else if((m_uButton2State & UISTATE_PUSHED) != 0)
            {
                if(m_nScrollRepeatDelay <= 5)
                {
                    return;
                }
                if(!m_bHorizontal)
                {
                    if(m_pOwner != NULL)
                    {
                        m_pOwner->LineDown();
                    }
                    else
                    {
                        SetScrollPos(m_nScrollPos + m_nLineSize);
                    }
                }
                else
                {
                    if(m_pOwner != NULL)
                    {
                        m_pOwner->LineRight();
                    }
                    else
                    {
                        SetScrollPos(m_nScrollPos + m_nLineSize);
                    }
                }
            }
            else
            {
                if(m_nScrollRepeatDelay <= 5)
                {
                    return;
                }
                POINT pt = { 0 };
                ::GetCursorPos(&pt);
                ::ScreenToClient(GetManager()->GetPaintWindow(), &pt);
                if(!m_bHorizontal)
                {
                    if(pt.y < m_rcThumb.top)
                    {
                        if(m_pOwner != NULL)
                        {
                            m_pOwner->PageUp();
                        }
                        else
                        {
                            SetScrollPos(m_nScrollPos + GetPos().top - GetPos().bottom);
                        }
                    }
                    else if(pt.y > m_rcThumb.bottom)
                    {
                        if(m_pOwner != NULL)
                        {
                            m_pOwner->PageDown();
                        }
                        else
                        {
                            SetScrollPos(m_nScrollPos - GetPos().top + GetPos().bottom);
                        }
                    }
                }
                else
                {
                    if(pt.x < m_rcThumb.left)
                    {
                        if(m_pOwner != NULL)
                        {
                            m_pOwner->PageLeft();
                        }
                        else
                        {
                            SetScrollPos(m_nScrollPos + GetPos().left - GetPos().right);
                        }
                    }
                    else if(pt.x > m_rcThumb.right)
                    {
                        if(m_pOwner != NULL)
                        {
                            m_pOwner->PageRight();
                        }
                        else
                        {
                            SetScrollPos(m_nScrollPos - GetPos().left + GetPos().right);
                        }
                    }
                }
            }
            if(GetManager() != NULL && m_pOwner == NULL)
            {
                GetManager()->SendNotify(this, DUI_MSGTYPE_SCROLL);
            }
            return;
        }
        if(event.Type == DUIEVENT_MOUSEENTER)
        {
            if(IsEnabled())
            {
                m_uButton1State |= UISTATE_HOT;
                m_uButton2State |= UISTATE_HOT;
                if(::PtInRect(&m_rcThumb, event.ptMouse))
                {
                    m_uThumbState |= UISTATE_HOT;
                }
                Invalidate();
            }
            return;
        }
        if(event.Type == DUIEVENT_MOUSELEAVE)
        {
            if(IsEnabled())
            {
                m_uButton1State &= ~UISTATE_HOT;
                m_uButton2State &= ~UISTATE_HOT;
                m_uThumbState &= ~UISTATE_HOT;
                Invalidate();
            }
            return;
        }

        if(m_pOwner != NULL)
        {
            m_pOwner->DoEvent(event);
        }
        else
        {
            CDuiControl::DoEvent(event);
        }
    }

}

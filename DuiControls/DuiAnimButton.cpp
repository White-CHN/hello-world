#include "StdAfx.h"
#include "DuiAnimButton.h"

IMPLEMENT_DUICONTROL(CDuiAnimButton)


CDuiAnimButton::CDuiAnimButton(void)
#pragma warning(disable: 4355)
    : IAnimation(this)
#pragma warning(default: 4355)
    , m_nFramePosition(0)
    , m_nEllapse(ANIMATION_ELLAPSE)
{

}


CDuiAnimButton::~CDuiAnimButton(void)
{
}

CDuiString CDuiAnimButton::GetClass() const
{
    return DUI_CTR_ANIMBUTTON;
}

LPVOID CDuiAnimButton::GetInterface(LPCTSTR pstrName)
{
    if(_tcsicmp(pstrName, DUI_CTR_ANIMBUTTON) == 0)
    {
        return static_cast<CDuiAnimButton*>(this);
    }
    return CDuiButton::GetInterface(pstrName);
}

int CDuiAnimButton::GetEllapse() const
{
    return m_nEllapse;
}

void CDuiAnimButton::SetEllapse(int nEllapse)
{
    m_nEllapse = nEllapse;
}

BOOL CDuiAnimButton::AddImage(CDuiString strImage)
{
    BOOL bRet = FALSE;
    for(vector<CDuiString>::iterator it = m_vtImages.begin(); it != m_vtImages.end(); it++)
    {
        if(*it == strImage)
        {
            return bRet;
        }
    }
    m_vtImages.push_back(strImage);
    return TRUE;
}

void CDuiAnimButton::SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue)
{
    if(_tcscmp(pstrName, _T("ellapse")) == 0)
    {
        m_nEllapse = _ttoi(pstrValue);
    }
    else if(_tcscmp(pstrName, _T("animimage")) == 0)
    {
        AddImage(pstrValue);
    }
    else
    {
        CDuiButton::SetAttribute(pstrName, pstrValue);
    }
}

void CDuiAnimButton::OnAnimationStep(int nTotalFrame, int nCurFrame, int nAnimationID)
{
    if(nCurFrame >= nTotalFrame)
    {
        return;
    }
    if(nAnimationID == TIMER_ID_ANIMBUTTON_IN)
    {
        m_nFramePosition++;
        if(m_nFramePosition >= nTotalFrame)
        {
            m_nFramePosition = nTotalFrame - 1;
        }
    }
    else if(nAnimationID == TIMER_ID_ANIMBUTTON_OUT)
    {
        m_nFramePosition--;
        if(m_nFramePosition < 0)
        {
            m_nFramePosition = 0;
        }
    }
    Invalidate();
}

void CDuiAnimButton::DoPaint(HDC hDC, const RECT& rcPaint)
{
    if(!::IntersectRect(&GetPaintRect(), &rcPaint, &GetPos()))
    {
        return;
    }
    CDuiButton::DoPaint(hDC, rcPaint);
    if(m_nFramePosition >= 0 && m_nFramePosition < (int)m_vtImages.size())
    {
        DrawImage(hDC, (LPCTSTR)m_vtImages[m_nFramePosition]);
    }
}

void CDuiAnimButton::DoEvent(TEventUI& event)
{
    if(event.Type == UIEVENT_MOUSEENTER && !IsAnimationRunning(TIMER_ID_ANIMBUTTON_IN))
    {
        StopAnimation(TIMER_ID_ANIMBUTTON_OUT);
        StartAnimation(m_nEllapse, m_vtImages.size(), TIMER_ID_ANIMBUTTON_IN);
        Invalidate();
        return;
    }
    if(event.Type == UIEVENT_MOUSELEAVE && !IsAnimationRunning(TIMER_ID_ANIMBUTTON_OUT))
    {
        StopAnimation(TIMER_ID_ANIMBUTTON_IN);
        StartAnimation(m_nEllapse, m_vtImages.size(), TIMER_ID_ANIMBUTTON_OUT);
        Invalidate();
        return;
    }
    if(event.Type ==  UIEVENT_BUTTONUP)
    {
        StopAnimation(TIMER_ID_ANIMBUTTON_OUT);
        StartAnimation(m_nEllapse, m_vtImages.size(), TIMER_ID_ANIMBUTTON_IN);
        Invalidate();
    }
    if(event.Type == UIEVENT_BUTTONDOWN)
    {
        StopAnimation(TIMER_ID_ANIMBUTTON_IN);
        StartAnimation(m_nEllapse, m_vtImages.size(), TIMER_ID_ANIMBUTTON_OUT);
        Invalidate();
    }
    if(event.Type == UIEVENT_TIMER)
    {
        OnAnimationElapse((int)event.wParam);
    }
    CDuiButton::DoEvent(event);
}
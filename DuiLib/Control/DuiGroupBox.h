#pragma once
namespace DuiLib
{
#define  GROUPBOX_TEXT_OFFSET		20		//定义GroupBox中的Text相对于左边的偏移

    class DUILIB_API CDuiGroupBox
        : public CDuiVerticalLayout
    {
        DECLARE_DUICONTROL(CDuiGroupBox)
    public:
        CDuiGroupBox(void);
        virtual ~CDuiGroupBox(void);
    public:
        CDuiString GetClass() const OVERRIDE;
        LPVOID GetInterface(CDuiString strName) OVERRIDE;

        DWORD GetTextColor() const;
        void SetTextColor(DWORD dwTextColor);

        DWORD GetDisabledTextColor() const;
        void SetDisabledTextColor(DWORD dwTextColor);

        int GetFont() const;
        void SetFont(int index);

        void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue) OVERRIDE;

        void PaintText(HDC hDC) OVERRIDE;
        void PaintBorder(HDC hDC) OVERRIDE;
    private:
        SIZE CalcrectSize(SIZE szAvailable);
    private:
        int m_iFont;
        DWORD m_dwTextColor;
        DWORD m_dwDisabledTextColor;
        UINT m_uTextStyle;
    };

}
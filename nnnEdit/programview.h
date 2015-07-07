//
// programview.h
//

#if !defined __TINYAN_NNNEDIT_PROGRAMVIEW__
#define __TINYAN_NNNEDIT_PROGRAMVIEW__

#include "scrollview.h"

#include "resource.h"

class CMyButton;

class CProgramView : public CMyScrollView
{
public:
	CProgramView(CMyDocument* pDocument, HWND clientHWND, HINSTANCE hinstance);
	~CProgramView();
	void End(void);

	LRESULT ViewWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
private:
	CMyButton* m_buttonEdit;
};


#endif
/*_*/


#pragma once

//
// commonTitle.h
//

#if !defined __BARA_TITLE__
#define __BARA_TITLE__

#include "..\..\SystemNNN\nnnLib\commonGeneral.h"
#include "..\..\SystemNNN\nnnLib\commonTitle.h"

class CGameCallBack;

//class CMenuButtonSetup;
//class CMenuButtonGroup;
//class CAutoSelectControl;
class CMyMessage;
class CGame;

class CTitle : public CCommonTitle
{
public:
	CTitle(CGame* lpGame);
	virtual ~CTitle();
	virtual void End(void);

	virtual int Init(void) override;
	virtual int Calcu(void) override;
	virtual int Print(void) override;


	virtual void ReCreateExitScreen(void) override;
	//	virtual void CreateStartScreen(void);

	//	virtual void FinalExitRoutine(void);
	//virtual int EndMode(void);

	//	void OnScreenModeChanged(void);
	//void SetMode(int md = 0, BOOL onlyFlag = FALSE);

protected:

	/*
	virtual void BeforeInit(void) {}
	virtual void AfterInit(void) {}
	virtual void BeforeCalcu(void) {}
	virtual void AfterCalcu(void) {}
	virtual void BeforePrint(void) {}
	virtual void AfterPrint(void) {}
	*/


	CMyMessage* m_message;
private:
	CGame* m_game2;
};



#endif
/*_*/



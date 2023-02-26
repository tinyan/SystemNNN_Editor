#pragma once

//
// commonTitle.h
//

#if !defined __BARA_SELECTCGCHARA__
#define __BARA_SELECTCGCHATA__

#include "..\..\SystemNNN\nnnLib\commonGeneral.h"
#include "..\..\SystemNNN\nnnLib\commonSelectCGChara.h"

class CGameCallBack;

//class CMenuButtonSetup;
//class CMenuButtonGroup;
//class CAutoSelectControl;
class CMyMessage;
class CGame;

class CSelectCGChara : public CCommonSelectCGChara
{
public:
	CSelectCGChara(CGame* lpGame);
	virtual ~CSelectCGChara();
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




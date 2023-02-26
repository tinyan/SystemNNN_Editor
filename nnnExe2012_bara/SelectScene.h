#pragma once

//
// commonTitle.h
//

#if !defined __BARA_SELECTSCENE__
#define __BARA_SELECTSCENE__

#include "..\..\SystemNNN\nnnLib\commonGeneral.h"
#include "..\..\SystemNNN\nnnLib\commonSelectScene.h"

class CGameCallBack;

//class CMenuButtonSetup;
//class CMenuButtonGroup;
//class CAutoSelectControl;
class CMyMessage;
class CGame;

class CSelectScene : public CCommonSelectScene
{
public:
	CSelectScene(CGame* lpGame);
	virtual ~CSelectScene();
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

	int m_nowSelectNumber;
	int m_maeSelectNumber;
	int m_selectedNumber;
	int m_startupWait;

	int GetOnScene(int mouseX, int mouseY);

private:
	CGame* m_game2;
};



#endif
/*_*/



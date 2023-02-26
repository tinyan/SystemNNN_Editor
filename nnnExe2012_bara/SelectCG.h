#pragma once

//
// commonTitle.h
//

#if !defined __BARA_SELECTCG__
#define __BARA_SELECTCG__

#include "..\..\SystemNNN\nnnLib\commonGeneral.h"
#include "..\..\SystemNNN\nnnLib\commonSelectCG.h"

class CGameCallBack;
class CCGDataControl;

//class CMenuButtonSetup;
//class CMenuButtonGroup;
//class CAutoSelectControl;
class CMyMessage;
class CGame;

class CSelectCG : public CCommonSelectCG
{
public:
	CSelectCG(CGame* lpGame);
	virtual ~CSelectCG();
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

	int m_printX;
	int m_printY;
	int m_nextX;
	int m_nextY;
	int m_sizeX;
	int m_sizeY;
	int m_page;

	int m_cgKosuu;
	int m_playerNumber;

	int GetOnCG(int mouseX, int mouseY);

	CCGDataControl* m_cgDataControl;

private:
	CGame* m_game2;
};



#endif
/*_*/




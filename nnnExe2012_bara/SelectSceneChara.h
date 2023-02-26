#pragma once

//
// commonTitle.h
//

#if !defined __BARA_SELECTSCENECHARA__
#define __BARA_SELECTSCENECHARA__

#include "..\..\SystemNNN\nnnLib\commonGeneral.h"
#include "..\..\SystemNNN\nnnLib\commonSelectSceneChara.h"

class CGameCallBack;

//class CMenuButtonSetup;
//class CMenuButtonGroup;
//class CAutoSelectControl;
class CMyMessage;
class CGame;

class CSelectSceneChara : public CCommonSelectSceneChara
{
public:
	CSelectSceneChara(CGame* lpGame);
	virtual ~CSelectSceneChara();
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
	
	static int m_placeToKumiTable[7][6];
	static int m_pianoTable[7][6];

protected:

	/*
	virtual void BeforeInit(void) {}
	virtual void AfterInit(void) {}
	virtual void BeforeCalcu(void) {}
	virtual void AfterCalcu(void) {}
	virtual void BeforePrint(void) {}
	virtual void AfterPrint(void) {}
	*/

	int GetOnButton(int mouseX, int mouseY);
	POINT GetButtonZahyo(int placeX, int placeY);

	CMyMessage* m_message;
private:
	CGame* m_game2;

	int m_nowSelectNumber;
	int m_maeSelectNumber;
	int m_selectedNumber;
	int m_startupWait;
	int m_buttonSizeX;
	int m_buttonSizeY;



};



#endif
/*_*/



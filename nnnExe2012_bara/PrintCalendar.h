#pragma once
//
// commonTitle.h
//

#if !defined __NNNLIB_PRINTCALENDAR__
#define __NNNLIB_PRINTCALENDAR__

class CGameCallBack;

//class CMyButtonGroup;

class CMenuButtonSetup;
class CMenuButtonGroup;
class CAutoSelectControl;
class CMyMessage;
class CGame;

class CPrintCalendar : public CCommonGeneral
{
public:
	CPrintCalendar(CGameCallBack* lpGame);
	virtual ~CPrintCalendar();
	virtual void End(void);

	virtual int Init(void) override;
	virtual int Calcu(void) override;
	virtual int Print(void) override;


//	virtual void ReCreateExitScreen(void);
//	virtual void CreateStartScreen(void);

//	virtual void FinalExitRoutine(void);
//	virtual int EndMode(void);

//	void OnScreenModeChanged(void);


	static int m_countTable[];

	static char m_haikeiFileName[][64];
	static char m_hourName[][8];

	static int m_hourPrintZahyoTable[];
private:
	int m_subMode;
	int m_count;

	int m_haikeiVarNumber;
	int m_cuppleVarNumber;
	int m_hourVarNumber;


	POINT GetHourPrintZahyo(int hour);
	SIZE GetHourSize(int hour);

protected:



	/*
	virtual void BeforeInit(void) {}
	virtual void AfterInit(void) {}
	virtual void BeforeCalcu(void) {}
	virtual void AfterCalcu(void) {}
	virtual void BeforePrint(void) {}
	virtual void AfterPrint(void) {}
	*/

	//	int m_addButtonKosuu;
	//	int m_addModeKosuu;
	//	int* m_addButtonVarNumber;
	//	int m_addModeVarNumber;
	//	int* m_addButtonExeType;
	//	int m_addButtonReturnVarNumber;

	//	int m_useSpecialButtonFlag;

	//	int* m_printZahyoX;
	//	int* m_printZahyoY;

//	CMenuButtonSetup* m_menuButtonSetup;

	CMyMessage* m_message;
	CGame* m_game2;

};



#endif
/*_*/


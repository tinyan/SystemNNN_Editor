#pragma once


//
//
//

#if !defined __NNNEXE_GAME__
#define __NNNEXE_GAME__


//#include "..\nnnLib\gameCallBack.h"

class CCommonSystemFile;
class CNameList;

//class CMakeParty;
//class CPartyStatusList;
//class CSelectMagicMenu;
//class CUtil;

//class CCharaStart;
//class CHouseLevel;

//class CCharaNumber;
//class CGameMouse;

//class CModePlate;

//class CKatakana;

//class CAreaHaveHouse;

//class COkimonoList;
//class CMoveMaskTable;

//class CHouseToSerial;

//class CEventList;

//class CDungeonAreaList;

//class CGameItem;
//class CHaveItem;

//class CCharaStatus;
//class CCastleLevel;

class CGameCallBack;

class CGame : public CGameCallBack
{
public:
	CGame(HWND hwnd, HINSTANCE hinstance, CCommonSystemFile* lpSystemFile, int windowSizeX, int windowSizeY, int bpp);
	~CGame();
	void End(void);


//
	void ReceiveUserCommand(int cmd, int paraKosuu, int* paraPtr);
	void ReceiveUserFunction(int cmd, int paraKosuu, int* paraPtr);
	void UserCommandCallBack(void);

	/////////////////////////////////////////////Ç±ÇÃÇ÷ÇÒÇ…ïKóvÇ»ä÷êîÇí«â¡

	//åpè≥
	void GetExtDataForSave(LPVOID ptr,int extNumber = 0);
	void SetExtDataByLoad(LPVOID ptr,int extNumber = 0);

	void Create(void);


	LPSTR GetCharaName(int n);
	LPSTR NumberToKanji(int d);
	int GetDayMonth(void);

	static char m_charaName[][16];
	static char m_statusName[10][16];

	static char m_placeAppearList[][32];
	static char m_placeButtonList[][32];
	static char m_photoList[2][3][12][32];

	static char m_pianoFileName[][8];

	static int m_resizeTable[];
	static char m_resizeFileTable[][16];

	static char m_suujiMes[];

	static int m_daysOfMonth[13];
	static int m_saijitsu[];
	static int m_weekStart[13];

	static int m_cgKosuu[];
private:
	char m_numberKanji[64];


private:
	void CreateAllClass(void);
//	void AfterInitNewGame(int uraMode = 0, BOOL demoFlag = FALSE);

	BOOL CheckDebugOk(void);

	int	m_printDateCommand;
	int	m_kumiawaseCommand;
	int	m_ryojyokuCommand;
	int	m_endingKumiawaseCommand;
	int	m_kekkaCommand;

//	int m_kumiCommand;
//	/int m_kekkaCommand;
//	int m_printdateCommand;
//	int m_staffrollCommand;
//	int m_kumi2Command;
//	int m_kumi3Command;
};





#endif
/*_*/


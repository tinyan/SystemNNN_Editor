#pragma once

//
// commonTitle.h
//

#if !defined __NNNLIB_KUMIAWASE__
#define __NNNLIB_KUMIAWASE__

class CGameCallBack;

//class CMyButtonGroup;

class CMenuButtonSetup;
class CMenuButtonGroup;
class CAutoSelectControl;
class CMyMessage;
class CGame;

class CGradColor;

#define AREA_KOSUU_MAX 6
#define MAINCHARA_KOSUU_MAX 12
#define SUBCHARA_KOSUU_MAX 18
#define SPECIALCHARA_KOSUU_MAX 2

#define KUMIAWASE_KOSUU_MAX 4


class CKumiawase : public CCommonGeneral
{
public:
	CKumiawase(CGameCallBack* lpGame);
	virtual ~CKumiawase();
	virtual void End(void);

	virtual int Init(void) override;
	virtual int Calcu(void) override;
	virtual int Print(void) override;


	virtual void ReCreateExitScreen(void);
	//	virtual void CreateStartScreen(void);

	//	virtual void FinalExitRoutine(void);
	//virtual int EndMode(void);

	//	void OnScreenModeChanged(void);
	void SetMode(int md = 0, BOOL onlyFlag = FALSE);

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



	static int m_cardPrintZahyoTable[];
	static int m_hourPrintZahyoTable[];
	static char m_hourName[][8];
	static char m_backFileName[][32];





















	static char m_areaName[][32];
	static char m_mainCharaName[][32];
	static char m_subCharaName[][32];
	static char m_specialCharaName[][32];

	static char m_areaFileName[][32];
	static char m_mainCharaFileName[][32];
	static char m_subCharaFileName[][32];

	static char m_iconFileName[][32];

	static char m_bangouName[][32];
	static int m_areaPrintTable[];

	static int m_kekkaCountTable[][5];



private:
	int m_cardSizeX;
	int m_cardSizeY;

	int m_upperCardPrintDeltaX;
	int m_upperCardPrintDeltaY;

	int m_gazeWakuPrintDeltaX;
	int m_gazeWakuPrintDeltaY;

	int m_gazeWakuSizeX;
	int m_gazeWakuSizeY;

	int m_gazeBarPrintDeltaX;
	int m_gazeBarPrintDeltaY;

	int m_gazeBarSizeX;
	int m_gazeBarSizeY;

	int m_needPointPrintDeltaX;
	int m_needPointPrintDeltaY;
	int m_needPointSizeX;
	int m_needPointSizeY;

	int m_petalKosuu;
	int m_petalSizeX;
	int m_petalSizeY;
	int m_petalShurui;

	int m_needPointAnime[8][10];
	int m_needPointAnimeSpeed[8][10];

	int m_okButtonAnime;
	int m_okButtonAnime2;
	int m_okButtonAnimeAmari;
	int m_okButtonAnimeCount;
	int m_choAnimeDiv;

	int m_month;
	int m_date;
	int m_hour;

	int m_mode;

	int m_deltaSemePoint;

	int m_hourVarNumber;
	int m_kasaneOkVarNumber[8][8];
	int m_semePointVarNumber[8][8];
	int m_charaAppearVarNumber[7 + 1];
	int m_charaRyojokuFlagVarNumber[7 + 1];
	int m_semeFukaVarNumber[7 + 1];
	int m_ukeFukaVarNumber[7 + 1];
	int m_ryojokuTaishoVarNumber[7 + 1];
	int m_endingKasaneOkVarNumber[7 + 1][7 + 1];
	int m_ryojokugawaFlagVarNumber[7 + 1];

	//	int m_cardWorkFrom[7+1];
	//	int m_cardWorkTo[7+1];

	int m_cardWork[7 + 1];

	int m_workVarNumber[20 + 1];

	int m_cardPrintWork[8][2];
	int m_cardPrintColorWork[8][2];
	int m_cardPrintPointWork[8][2];

	//	int m_kumiawase[KUMIAWASE_KOSUU_MAX][2];
	//	int m_kumiawaseUsePoint[KUMIAWASE_KOSUU_MAX][2];

	//	int m_cardMaePointFrom[7+1];
	//	int m_cardMaePointTo[7+1];

	CPicture* m_cardPic[7][3];

	CPicture* m_kagePic[5];
	CPicture* m_petalPic;

	CPicture* m_karaGazePic;
	CPicture* m_gazeWakuPic;
	CPicture* m_semeGazeBarPic;
	CPicture* m_ukeGazeBarPic;

	CPicture* m_needPointPic;

	CPicture* m_monthPic;
	CPicture* m_datePic;
	CPicture* m_hourPic;

	CPicture* m_okPic1;
	CPicture* m_okPic2;



	POINT GetCardBaseZahyo(int n);
	POINT GetUpperCaedDelta(void);
	SIZE GetCardSize(void);

	int GetKageType(int n, int k);
	POINT GetKageDelta(int type);
	SIZE GetKageSize(int type);

	POINT GetGazeWakuPrintDelta(void);
	SIZE GetGazeWakuSize(void);
	POINT GetGazeBarPrintDelta(void);
	SIZE GetGazeBarSize(void);

	POINT GetNeedPointPrintDelta(void);
	SIZE GetNeedPointSize(void);

	POINT GetHourPrintZahyo(int hour);
	SIZE GetHourSize(int hour);

	POINT GetOkButtonZahyo(void);
	SIZE GetOkButtonSize(void);

	void PutCardOnly(int n, int type, POINT pt, int col = 0);
	void PutCardOnly(int n, int type, int x, int y, int col = 0);

	void PutCardKage(int place);

	void PutGazeOnly(POINT cardPoint, int type, int gaze, int col = 0);
	void PutGazeOnly(int cardX, int cardY, int type, int gaze, int col = 0);

	void PutNeedPointOnly(int place, int point, int col = 0);

	void InitNeedPointAnime(void);
	void CalcuNeedPointAnime(void);

	void CalcuOkButtonAnime(void);

	void PrintMonth(void);
	void PrintDate(void);
	void PrintHour(void);

	void PutOkButton(int type, int anime, int anime2 = -1, int percent = 100, int col = 0);



	BOOL CheckOnOkArea(int mouseX, int mouseY);


	void TaihiKumiawaseMode(int subMode);
	void FuqueKumiawase(void);
	void TaihiKumiawase(void);



	void SetVarData(int varNumber, int data);
	int GetVarData(int varNumber);


	//	int FuqueKumiawaseCharaFrom(int n);
	//	int FuqueKumiawaseCharaTo(int n);
	//	int FuqueKumiawasePointFrom(int n);
	//	int FuqueKumiawasePointTo(int n);
	//	void TaihiKumiawase(int n,int from, int to,int fromPoint, int toPoint);


	int FuqueKumiawaseKosuu(void);
	void TaihiKumiawaseKosuu(int kosuu);


	BOOL CheckExistChara(int n);
	BOOL CheckAiseru(int from, int to);
	BOOL CheckRyojokuFlag(int n);
	BOOL CheckSemeOk(int from);
	BOOL CheckUkeOk(int to);
	BOOL CheckRyojokugawa(int from);
	BOOL CheckRyojokuTaisho(int to);
	BOOL CheckEndingKasaneOk(int from, int to);
	BOOL CheckEndingCatchOk(int from);


	BOOL CheckCatchOk(int place, BOOL upperFlag = FALSE);
	BOOL CheckExistCard(int place, BOOL upperFlag = FALSE);
	int GetCardNumber(int place, BOOL upperFlag = FALSE);

	int GetSemePoint(int from, int to);
	int GetNeedPoint(int from, int to);
	BOOL CheckKasaneOkByFlag(int from, int to);
	BOOL CheckKasaneOkByPoint(int from, int to);

	void SetCardToWork(int place, int card, BOOL upperFlag = FALSE);
	void SetOldPointToWork(int place, int point, BOOL upperFlag = FALSE);

	int GetFromCard(int place);
	int GetToCard(int place);
	int GetFromOldPoint(int place);
	int GetToOldPoint(int place);



	BOOL CheckOnPlace(int place, BOOL upperFlag, int mouseX, int mouseY);

	int GetOnPlace(int mouseX, int mouseY, BOOL upperFlag = FALSE);


	void PutCard(int n, int type, POINT pt, int md);

	void RestoreSemePoint(int place);
	void ChangeSemePoint(int place);
	void SetSemePoint(int fromCard, int toCard, int fromPoint, int toPoint = -1);







	int m_areaKosuu;
	int m_mainCharaKosuu;
	int m_subCharaKosuu;
	int m_specialCharaKosuu;
	int m_kumiawaseKosuu;

	int m_nokoriDateVarNumber;
	int m_shihairyokuVarNumber;
	int m_shihairyokuMaeVarNumber;
	int m_jinbutsuHasseiVarNumber;
	int m_jinbutsuTsuikaVarNumber;
	int m_henkaCard1to2VarNumber;
	int m_henkaCard2to3VarNumber;

	int m_semeDeltaPointVarNumber;

	int m_jinbutsuHasseiNumber;
	int m_jinbutsuTsuikaNumber;
	int m_henkaCard1to2Number;
	int m_henkaCard2to3Number;


	int m_shuffleVarNumber;

	int m_kumiawaseVarNumber[KUMIAWASE_KOSUU_MAX];

	int m_areaVarNumber[AREA_KOSUU_MAX];
	int m_mainCharaVarNumber[MAINCHARA_KOSUU_MAX];
	int m_subCharaVarNumber[SUBCHARA_KOSUU_MAX];
	int m_specialCharaVarNumber[SPECIALCHARA_KOSUU_MAX];


	int m_areaPatternVarNumber[AREA_KOSUU_MAX];
	int m_areaHyojiStatusVarNumber[AREA_KOSUU_MAX];

	int m_mainCharaHyojiStatusVarNumber[MAINCHARA_KOSUU_MAX];
	int m_subCharaHyojiStatusVarNumber[SUBCHARA_KOSUU_MAX];

	int m_mainCharaDarakudoVarNumber[MAINCHARA_KOSUU_MAX];
	int m_mainCharaNeedShihaidoVarNumber[MAINCHARA_KOSUU_MAX];
	int m_mainCharaDarakudoMaeVarNumber[MAINCHARA_KOSUU_MAX];

	int m_specialCharaNeedShihaidoVarNumber[SPECIALCHARA_KOSUU_MAX];
	int m_specialCharaNeedMana[SPECIALCHARA_KOSUU_MAX];



	int m_mainDaraku[MAINCHARA_KOSUU_MAX];
	//	int m_subDaraku[SUBCHARA_KOSUU_MAX];
	int m_mainDarakuMae[MAINCHARA_KOSUU_MAX];
	//	int m_subDarakuMae[SUBCHARA_KOSUU_MAX];

	int m_mainCharaNeedMana[MAINCHARA_KOSUU_MAX];

	int m_cardPrintX[AREA_KOSUU_MAX];
	int m_cardPrintY[AREA_KOSUU_MAX];

	int m_specialPrintX;
	int m_specialPrintY;

	int m_specialSizeX;
	int m_specialSizeY;

	int m_specialCharaSizeX;
	int m_specialCharaSizeY;

	int m_specialPrintDeltaX[SPECIALCHARA_KOSUU_MAX];
	int m_specialPrintDeltaY[SPECIALCHARA_KOSUU_MAX];

	int m_areaPrintDeltaX;
	int m_areaPrintDeltaY;

	int m_mainCharaPrintDeltaX[2];
	int m_mainCharaPrintDeltaY[2];

	int m_subCharaPrintDeltaX[2][3];
	int m_subCharaPrintDeltaY[2][3];

	int m_kakuteiCharaPrintX;
	int m_kakuteiCharaPrintY;
	int m_kakuteiCharaSizeX;
	int m_kakuteiCharaSizeY;



	//	int m_cardSizeX;
	//	int m_cardSizeY;

	int m_areaSizeX;
	int m_areaSizeY;

	int m_mainCharaSizeX;
	int m_mainCharaSizeY;

	int m_subCharaSizeX;
	int m_subCharaSizeY;

	int m_cursorPrintDeltaX;
	int m_cursorPrintDeltaY;
	int m_cursorSizeX;
	int m_cursorSizeY;
	int m_hotPointX;
	int m_hotPointY;


	int m_candleAreaPrintX;
	int m_candleAreaPrintY;
	int m_candleAreaSizeX;
	int m_candleAreaSizeY;









	void PutCandle(int n, int md, int anime, int anime2);

	void SetCandle(int n, int md, int anime = 0, int waitCount = 0, int nextMode = 0);

	void CalcuCandleAnime(void);


	//	BOOL CheckOverrapCardAndCursor(int n, int x, int y);
	//	BOOL CheckOverrapSpecialAndCursor(int x, int y);

	//	BOOL m_specialPrintFlag;
	//	BOOL m_cardPrintFlag[8];

	int m_candleCount[10];
	int m_candleMode[10];
	int m_candleAnime[10];
	int m_candleWait[10];
	int m_candleNextMode[10];

	int m_candleFireCount[10];
	int m_candleFireAnime[10];


	int CalcuKumiawase(void);
	int CalcuKekka(void);
	int PrintKumiawaseMode(void);
	int PrintKekkaMode(void);

	int m_areaHyojiType[AREA_KOSUU_MAX];
	int m_areaStatus[AREA_KOSUU_MAX];

	CPicture* m_candleBasePic;
	CPicture* m_candleNormalPic;
	CPicture* m_candleDarkPic;
	CPicture* m_candleSmokePic;
	CPicture* m_candleFirePic;
	CPicture* m_candleLightPic;

	CPicture* m_openedBookPic;
	CPicture* m_closedBookPic;
	CPicture* m_openingBookPic;
	CPicture* m_animeBookPic;
	CPicture* m_bookBackPic;

	int m_catchCard;
	int m_catchFrom;

	BOOL m_dragFlag;
	BOOL m_clickFlag;
	BOOL m_ketteiMode;
	int m_ketteiCount;

	BOOL CheckOnOk(int x, int y);
	BOOL CheckOnOpenBook(int x, int y);
	BOOL CheckOnCloseBook(int x, int y);


	BOOL CheckInArea(int x, int y, POINT pt, SIZE sz);

	void EraseCardWork(int place, BOOL upperFlag = FALSE);
	void ReCalcuCardOkWork(void);



	int m_power;
	//	int m_kumiawase[KUMIAWASE_KOSUU_MAX];


	int m_maeMouseX;
	int m_maeMouseY;
	int m_nowMouseX;
	int m_nowMouseY;


	int GetOnOkChara(int x, int y);

	int m_dmyCount;
	int m_mouseStartZahyoX;
	int m_mouseStartZahyoY;
	int m_dragCheckCount;

	int m_useMana;
	//	int m_useMana2;

	void AddMana(int mana);
	void SubMana(int mana);

	void DmyCandle(void);



	int m_kekkaCount;
	int m_lightMarkerNumber;


	void CheckBookOpen(int mouseX, int mouseY);
	void BookOpen(void);
	void BookClose(void);

	BOOL m_bookOpenFlag;

	int m_bookAnime;
	int m_bookAnimeCount;

	void BookAnime(void);

	int m_ketteiLastWait0;
	int m_ketteiLastWait;

	CGradColor* m_gradColor;

	BOOL CheckChangeGaze(void);

	BOOL CheckCatchCard(int place, BOOL upperFlag = FALSE);

	BOOL CheckHaveKumiawase(void);


	int m_hanaKosuu;
	POINT m_hanaZahyo[400];
	int m_hanaSpeedX[400];
	int m_hanaSpeedY[400];
	int m_hanaCount[400];
	void SetNewHana(int n);
	void CalcuHana(void);
	void PrintHana(void);

	int m_hanaPercent;
	int m_hanaSpeed;

	int m_onCard;
	int m_onCard2;
	int m_lightCount;
	int m_lighting;
	int m_lightCount2;
	int m_lighting2;

	CGame* m_game2;

};



#endif
/*_*/


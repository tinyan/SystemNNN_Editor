//
// kumiawase.cpp
//



#include <windows.h>
#include <stdio.h>

#include "..\..\SystemNNN\nyanLib\INCLUDE\allGeo.h"
#include "..\..\SystemNNN\nyanLib\INCLUDE\allGraphics.h"

#include "..\..\SystemNNN\nyanLib\include\commonMacro.h"
#include "..\..\SystemNNN\nyanLib\include\areaControl.h"
#include "..\..\SystemNNN\nyanLib\include\myGraphics.h"
#include "..\..\SystemNNN\nyanLib\include\picture.h"

#include "..\..\SystemNNN\nnnUtilLib\myMouseStatus.h"
#include "..\..\SystemNNN\nnnUtilLib\inputStatus.h"
#include "..\..\SystemNNN\nnnUtilLib\nnnButtonStatus.h"

#include "..\..\SystemNNN\nnnUtilLib\menuButtonGroup.h"
#include "..\..\SystemNNN\nnnUtilLib\menuButtonSetup.h"

#include "..\..\SystemNNN\nnnUtilLib\commonButton.h"
#include "..\..\SystemNNN\nnnUtilLib\autoSelectControl.h"
#include "..\..\SystemNNN\nnnUtilLib\myMessage.h"

#include "..\..\SystemNNN\nnnUtilLib\commonGameVersion.h"
#include "..\..\SystemNNN\nnnLib\commonMode.h"
#include "..\..\SystemNNN\nnnLib\commonSystemSoundName.h"
#include "..\..\SystemNNN\nnnLib\commonSystemParamName.h"

#include "..\..\systemNNN\nnnUtilLib\superButtonPicture.h"


#include "..\..\SystemNNN\nnnLib\gameCallBack.h"

#include "..\..\SystemNNN\nnnLib\commonGeneral.h"
#include "mode.h"
#include "game.h"
#include "kumiawase.h"



#define CARDCOLOR_NORMAL 0
#define CARDCOLOR_GREY 1
#define CARDCOLOR_RED 2
#define CARDCOLOR_LIGHT 3
#define CARDCOLOR_DARK 4
#define CARDCOLOR_TRANS 5
#define CARDCOLOR_TRANS2 6
#define CARDCOLOR_LIGHT2 7

#define OKCOLOR_NORMAL 0
#define OKCOLOR_GREY 1


#define GAZETYPE_NO 0
#define GAZETYPE_SEME 1
#define GAZETYPE_UKE 2


#define SYSTEMSOUND_OK (0)
#define SYSTEMSOUND_CANCEL (1)
#define SYSTEMSOUND_PAGE (2)
#define SYSTEMSOUND_CARDGET (3)
#define SYSTEMSOUND_CARDRISE (4)

#define SYSTEMSOUND_CARDCANCEL (5)
//???????????????????



#define SYSTEMSOUND_CARDALLOK	(6)
#define SYSTEMSOUND_CARDAPPEAR	(7)
#define SYSTEMSOUND_BAR		(8)
#define SYSTEMSOUND_CARDCHANGE	(9)


int CKumiawase::m_cardPrintZahyoTable[] =
{
	477,46,//要 = 1;
	349,222,//幹彦 = 2;
	477,398,//あずさ = 3;
	220,46,//抱月 = 4;
	220,398,//真弓 = 5;
	601,222,//光伸 = 6;
	96,222,//憲実 = 7;
};


int CKumiawase::m_hourPrintZahyoTable[] =
{
	0,0,
	0,0,	127,33,	133,92,	90,133,	66,67,

};

char CKumiawase::m_hourName[][8] =
{
	"","早朝","朝","昼","夕","夜"
};

char CKumiawase::m_backFileName[][32] =
{
	"メイン",
	"組み合わせ２背景",
	"組み合わせ３背景",
};


//
// ワーク
//	1:mode
//	2-9:くみあわせワークたいひ from to fromPoint toPoint	それぞれ8bit
//	10:power
//
//
//





char CKumiawase::m_bangouName[][32] =
{
	"０","１","２","３","４","５","６","７","８","９"
};



/*

int CKumiawase::m_kekkaCountTable[][5]=
{
	31,	8,20,31, 31,	//発生	(のびる、はっせい、まち)
	21,	12,21,21, 21,	//追加	(発生 まち)
	28,	10,20,28, 28,	//ゲージまち、のび、まち
	20,	5,15,20, 20,	//まち、変化、待ち
	20,	5,15,20, 20,	//まち、変化、待ち
};


char CKumiawase::m_areaName[][32]=
{
	"一年生","二年生","三年生","体育系","文科系","職員",
};


char CKumiawase::m_mainCharaName[][32]=
{
	"三人組","小泉","倉田","ゆかり","清水","さやか","大野","モモコ","明日花","麻里江","ゆきえ","柚香",
};



char CKumiawase::m_subCharaName[][32]=
{
	"渡辺","真由美","逸見","化学教師","高見沢","ダミー０６","浩子","船木","ダミー０９",
	"規子","みちる","水泳部長","美代子","大林","ダミー１５","杉本","手塚","ダミー１８",
};

char CKumiawase::m_specialCharaName[][32]=
{
	"学園長","Ｋ",
};

*/


/*
char CKumiawase::m_areaFileName[][32]=
{
	"ta1年生エリア","ta２年生エリア","ta３年生エリア","ta体育系エリア","ta文化系エリア","ta教職員系エリア",
};

char CKumiawase::m_mainCharaFileName[][32]=
{
	"ta３人組","ta小泉春樹","ta倉田真","ta高見沢ゆかり","ta清水浩実","ta有川さやか",
	"ta大野武士","ta須田モモコ","ta野村明日花","ta村瀬麻里","ta関ゆきえ","ta山形柚香",
};

char CKumiawase::m_subCharaFileName[][32]=
{
	"ta一年エリアサブ１",
	"ta一年エリアサブ２",
	"ta一年エリアサブ３",

	"ta２年エリアサブ１",
	"ta２年エリアサブ２",
	"ta２年エリアサブ３",

	"ta３年エリアサブ１",
	"ta３年エリアサブ２",
	"ta３年エリアサブ３",

	"ta体育エリアサブ１",
	"ta体育エリアサブ２",
	"ta体育エリアサブ３",

	"ta文化エリアサブ１",
	"ta文化エリアサブ２",
	"ta文化エリアサブ３",

	"ta職員エリアサブ１",
	"ta職員エリアサブ２",
	"ta職員エリアサブ３",
};

char CKumiawase::m_iconFileName[][32]=
{
	"３人組","小泉春樹","倉田真","高見沢ゆかり","清水浩実","有川さやか",
	"大野武士","須田モモコ","野村明日花","村瀬麻里","関ゆきえ","山形柚香",
};

int CKumiawase::m_areaPrintTable[]=
{
	233,266,
	405,323,
	438,65,
	609,105,
	204,9,
	33,154,
};

*/

#define MYCOLOR_NORMAL 0
#define MYCOLOR_GREY 1
#define MYCOLOR_RED 2
#define MYCOLOR_ADD 3
#define MYCOLOR_TRANS 4



CKumiawase::CKumiawase(CGameCallBack* lpGame) : CCommonGeneral(lpGame)
{
	SetClassNumber(BARA_KUMIAWASE_MODE);
	//	m_classNumber = TITLE_MODE;
	LoadSetupFile("printcalendar", 64);

	m_game2 = dynamic_cast<CGame*>(lpGame);

	//	m_basicButtonKosuu = 5;
	//	GetInitGameParam(&m_basicButtonKosuu, "basicButtonNumber");
	//	m_menuButtonSetup = new CMenuButtonSetup(m_setup, m_basicButtonKosuu);

	m_message = new CMyMessage(m_game->GetMyFont());

	GetInitGameString(&m_filenameBG, "filenameBG");

	GetBackExecSetup();
	GetAllPrintSetup();

	GetDisableQuickButtonSetup();
	GetDisableFreeButtonSetup();


	//	m_filenameBG = m_defaultBGFileName;
	//	GetInitGameString(&m_filenameBG, "filenameBG");

	//	m_scriptEndIsModeEnd = 0;
	//	GetInitGameParam(&m_scriptEndIsModeEnd, "scriptEndIsModeEnd");


	//	m_restartNextMode = NOTHING_MODE;
	//	GetModeNumberBySetup("restartNextMode", &m_restartNextMode);


	m_modeBGMNumber = 1;
	m_modeBGMMustRestartFlag = 1;
	//	m_newGameFlag = FALSE;


	GetBGMSetup();
	GetFadeInOutSetup();
	GetEnterExitVoiceFileName();


	///////////////////////
	int i, j;

	m_mode = 0;

	m_kumiawaseKosuu = 4;

	m_hanaKosuu = 40;

	m_choAnimeDiv = 20;

	m_cardSizeX = 108;
	m_cardSizeY = 155;


	m_upperCardPrintDeltaX = 46;
	m_upperCardPrintDeltaY = -16;



	m_gazeWakuPrintDeltaX = 2;
	m_gazeWakuPrintDeltaY = 135;

	m_gazeWakuSizeX = 104;
	m_gazeWakuSizeY = 19;

	m_gazeBarPrintDeltaX = 8;
	m_gazeBarPrintDeltaY = 7;

	m_gazeBarSizeX = 88;
	m_gazeBarSizeY = 4;


	m_petalSizeX = 16;
	m_petalSizeY = 16;
	m_petalShurui = 4;
	m_petalKosuu = 50;

	m_needPointPrintDeltaX = 0;
	m_needPointPrintDeltaY = 0;
	m_needPointSizeX = 16;
	m_needPointSizeY = 16;


	m_hanaPercent = 50;
	m_hanaSpeed = 100;

	m_month = 5;
	m_date = 14;
	m_hour = 1;

	m_okButtonAnime = 0;
	m_okButtonAnimeCount = 0;

	m_lightCount = 0;
	m_lighting = 30;
	m_lightCount2 = 0;
	m_lighting2 = 64;

	m_hourVarNumber = m_game->GetVarNumber("時間帯");


	for (j = 0; j < 7; j++)
	{
		for (i = 0; i < 3; i++)
		{
			m_cardPic[j][i] = new CPicture();
		}
	}

	for (i = 0; i < 5; i++)
	{
		//		m_kagePic[i] = new CPicture();
	}

	m_monthPic = new CPicture();
	m_datePic = new CPicture();
	m_hourPic = new CPicture();


	m_kagePic[0] = m_game->GetSystemPicture("カード影右");
	m_kagePic[1] = m_game->GetSystemPicture("カード影左");
	m_kagePic[2] = m_game->GetSystemPicture("カード影中央");
	m_kagePic[3] = m_game->GetSystemPicture("カード影下");
	m_kagePic[4] = m_game->GetSystemPicture("カード影下");

	m_karaGazePic = m_game->GetSystemPicture("空ゲージ");
	m_gazeWakuPic = m_game->GetSystemPicture("攻受ベース");
	m_semeGazeBarPic = m_game->GetSystemPicture("攻ゲージ");
	m_ukeGazeBarPic = m_game->GetSystemPicture("受ゲージ");

	m_needPointPic = m_game->GetSystemPicture("消費ポイント");



	m_candleAreaPrintX = 27;
	m_candleAreaPrintY = 426;

	m_candleAreaSizeX = 28 * 9 + 66 + 22;
	m_candleAreaSizeY = 62;


	m_candleBasePic = m_game->GetSystemPicture("taろうそく");
	m_candleNormalPic = m_game->GetSystemPicture("taろうそく燃え");
	m_candleDarkPic = m_game->GetSystemPicture("taろうそく消えるまで");
	m_candleSmokePic = m_game->GetSystemPicture("taろうそく煙");
	m_candleFirePic = m_game->GetSystemPicture("taろうそく炎");
	m_candleLightPic = m_game->GetSystemPicture("taろうそく燃え始め");

	m_petalPic = m_game->GetSystemPicture("petal1");

	m_okPic1 = m_game->GetSystemPicture("ta蝶実行ボタン");
	m_okPic2 = m_game->GetSystemPicture("ta蝶実行ＯＮボタン");

	for (i = 0; i < 10; i++)
	{
		SetCandle(i, 0);
	}



	m_semeDeltaPointVarNumber = m_game->GetVarNumber("攻め変動数値");


	for (i = 1; i <= 20; i++)
	{
		char name[64];
		sprintf_s(name, 64,"ワーク%s%s", m_bangouName[i / 10], m_bangouName[i % 10]);
		m_workVarNumber[i] = m_game->GetVarNumber(name);
	}

	m_kumiawaseVarNumber[0] = m_game->GetVarNumber("陵辱組み合わせ番号");
	for (i = 0; i < 3; i++)
	{
		char name[64];
		sprintf_s(name,64, "カード組み合わせ番号%s", m_bangouName[i + 1]);
		m_kumiawaseVarNumber[i + 1] = m_game->GetVarNumber(name);
	}


	for (j = 1; j <= 7; j++)
	{
		LPSTR fromName = m_game2->GetCharaName(j);

		for (i = 1; i <= 7; i++)
		{
			m_kasaneOkVarNumber[j][i] = -1;

			if (i != j)
			{
				LPSTR toName = m_game2->GetCharaName(i);
				char name[128];
				sprintf_s(name, 128,"%sｘ%s愛せる", fromName, toName);
				int varNumber = m_game->GetVarNumber(name);
				if (varNumber != -1)
				{
					m_kasaneOkVarNumber[j][i] = varNumber;
				}
			}
		}
	}


	for (j = 1; j <= 7; j++)
	{
		LPSTR fromName = m_game2->GetCharaName(j);

		for (i = 1; i <= 7; i++)
		{
			m_semePointVarNumber[j][i] = 0;

			//			if ((i == j) || ((j == 2) && (i != 1)) || (i == 2))
			if (i == j)
			{
			}
			else
			{
				LPSTR toName = m_game2->GetCharaName(i);
				char name[128];
				sprintf_s(name, 128,"%sｘ%s攻めポイント", fromName, toName);
				int varNumber = m_game2->GetVarNumber(name);
				if (varNumber != -1)
				{
					m_semePointVarNumber[j][i] = varNumber;
				}
			}
		}
	}


	for (j = 1; j <= 7; j++)
	{
		LPSTR fromName = m_game2->GetCharaName(j);
		char name[128];


		m_charaAppearVarNumber[j] = 0;
		sprintf_s(name, 128,"%s登場", fromName);
		int varNumber = m_game->GetVarNumber(name);
		if (varNumber != -1)
		{
			m_charaAppearVarNumber[j] = varNumber;
		}

		m_charaRyojokuFlagVarNumber[j] = 0;
		sprintf_s(name, 128,"%s陵辱フラグ", fromName);
		varNumber = m_game->GetVarNumber(name);
		if (varNumber != -1)
		{
			m_charaRyojokuFlagVarNumber[j] = varNumber;
		}


		m_semeFukaVarNumber[j] = 0;
		sprintf_s(name, 128,"%s攻め不可", fromName);
		varNumber = m_game->GetVarNumber(name);
		if (varNumber != -1)
		{
			m_semeFukaVarNumber[j] = varNumber;
		}

		m_ukeFukaVarNumber[j] = 0;
		sprintf_s(name, 128,"%s受け不可", fromName);
		varNumber = m_game->GetVarNumber(name);
		if (varNumber != -1)
		{
			m_ukeFukaVarNumber[j] = varNumber;
		}

		m_ryojokuTaishoVarNumber[j] = 0;
		sprintf_s(name,128, "%s陵辱対象", fromName);
		varNumber = m_game->GetVarNumber(name);
		if (varNumber != -1)
		{
			m_ryojokuTaishoVarNumber[j] = varNumber;
		}

		m_ryojokugawaFlagVarNumber[j] = 0;
		sprintf_s(name,128, "%s陵辱側", fromName);
		varNumber = m_game->GetVarNumber(name);
		if (varNumber != -1)
		{
			m_ryojokugawaFlagVarNumber[j] = varNumber;
		}
	}



	for (j = 1; j <= 7; j++)
	{
		LPSTR fromName = m_game2->GetCharaName(j);

		for (i = 1; i <= 7; i++)
		{
			m_endingKasaneOkVarNumber[j][i] = 0;

			if (i != j)
			{
				LPSTR toName = m_game2->GetCharaName(i);
				char name[128];
				sprintf_s(name, 128,"%sｘ%sＥＤ", fromName, toName);
				int varNumber = m_game->GetVarNumber(name);
				if (varNumber != -1)
				{
					m_endingKasaneOkVarNumber[j][i] = varNumber;
				}
			}
		}
	}

}


CKumiawase::~CKumiawase()
{
	End();
}


void CKumiawase::End(void)
{
	ENDDELETECLASS(m_message);

	int i, j;

	for (j = 0; j < 7; j++)
	{
		for (i = 0; i < 3; i++)
		{
			ENDDELETECLASS(m_cardPic[j][i]);
		}
	}

	ENDDELETECLASS(m_monthPic);
	ENDDELETECLASS(m_datePic);
	ENDDELETECLASS(m_hourPic);

}

int CKumiawase::Init(void)
{

	//	m_game->SetupNameDefault();
	//	m_game->ClearBackLog();
	//	m_game->SetLayerOff();

	//@@	m_game->StopScriptSoundAndVoice();

	if (m_backScriptFlag == FALSE)
	{
		char filename[256];
		wsprintf(filename, "sys\\%s", m_filenameBG);
		m_commonBG->LoadDWQ(filename);
	}


	//	m_game->StopVoice();

	m_game->InitOptionButton();

	//////////////////////
	int i, j;

	m_hanaPercent = 50;
	m_hanaSpeed = 100;

	FuqueKumiawase();

	char filename[256];
	sprintf_s(filename, 256,"sys\\%s", m_backFileName[m_mode]);
	m_commonBG->LoadDWQ(filename);

	int daymonth = m_game2->GetDayMonth();
	m_month = daymonth / 100;
	m_date = daymonth % 100;

	m_hour = GetVarData(m_hourVarNumber);

	m_deltaSemePoint = GetVarData(m_semeDeltaPointVarNumber);



	m_bookOpenFlag = FALSE;
	m_bookAnime = 1;
	m_bookAnimeCount = 0;


	m_ketteiMode = FALSE;
	m_ketteiCount = 1;
	m_dragFlag = FALSE;
	m_catchCard = -1;

	m_dmyCount = 10;

	//	m_commonBG->LoadDWQ("sys\\メイン");
	//	m_commonParts->LoadDWQ("sys\\temptation");


	for (j = 0; j < 8; j++)
	{
		//		m_cardWork[j] = 0;

		if ((j >= 1) && (j <= 7))
		{
			if (CheckExistChara(j))
			{
				//				m_cardWork[j] = (j << 16);
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		//		m_kumiawase[i][0] = 0;
		//		m_kumiawase[i][1] = 0;

		//		m_kumiawaseUsePoint[i][0] = 0;
		//		m_kumiawaseUsePoint[i][1] = 0;
	}

	for (i = 0; i < m_kumiawaseKosuu; i++)
	{
		//もどす
//		m_kumiawase[i][0] = FuqueKumiawaseCharaFrom(i);
//		int to = FuqueKumiawaseCharaFrom(i);

	}











	//	FuqueKumiawaseVar();







	//	m_jinbutsuHasseiNumber = m_game->GetVarData(m_jinbutsuHasseiVarNumber);
	//	m_jinbutsuTsuikaNumber = m_game->GetVarData(m_jinbutsuTsuikaVarNumber);
	//	m_henkaCard1to2Number = m_game->GetVarData(m_henkaCard1to2VarNumber);
	//	m_henkaCard2to3Number = m_game->GetVarData(m_henkaCard2to3VarNumber);



		//dummy

	for (j = 0; j < 7; j++)
	{
		LPSTR charaName = m_game2->GetCharaName(j + 1);

		//char filename[256];

		sprintf_s(filename, 256,"sys\\ta%s普通待", charaName);
		m_cardPic[j][0]->LoadDWQ(filename);

		if (CheckRyojokuFlag(j + 1) == FALSE)
			//		if ((rand() & 1) == 0)
		{
			sprintf_s(filename, 256,"sys\\ta%s純愛普通攻", charaName);
		}
		else
		{
			sprintf_s(filename, 256,"sys\\ta%s凌辱攻", charaName);
		}

		m_cardPic[j][1]->LoadDWQ(filename);

		sprintf_s(filename, 256,"sys\\ta%s共通受", charaName);
		m_cardPic[j][2]->LoadDWQ(filename);
	}




	//	char filename[256];

	LPSTR suujiMes = m_game2->NumberToKanji(m_month);
	sprintf_s(filename, 256,"sys\\ta%s月", suujiMes);
	m_monthPic->LoadDWQ(filename);

	//	suujiMes = m_game->NumberToKanji(m_date);
	sprintf_s(filename, 256,"sys\\ta%d", m_date);
	m_datePic->LoadDWQ(filename);

	if ((m_hour >= 2) && (m_hour <= 5))
	{
		sprintf_s(filename, 256,"sys\\ta%s", m_hourName[m_hour]);
		m_hourPic->LoadDWQ(filename);
	}




	for (i = 0; i < 10; i++) SetCandle(i, 0);
	//	m_power = m_game->GetVarData(m_shihairyokuVarNumber);
	//m_power = 3 + (rand() % 7);
	//m_power = 2;

	///	m_power = 10;

	for (i = 0; i < m_power; i++)
	{
		SetCandle(i, 0, 0, i * 10 + 1, 4);
		//SetCandle(i,1,0,i*10+1,2);
	}

	InitNeedPointAnime();


	for (i = 0; i < m_hanaKosuu; i++)
	{
		SetNewHana(i);
	}

	return -1;
}


int CKumiawase::Calcu(void)
{
	int i;

	CalcuCandleAnime();
	CalcuNeedPointAnime();
	CalcuHana();


	POINT pt = m_mouseStatus->GetZahyo();
	int mouseX = pt.x;
	int mouseY = pt.y;

	m_maeMouseX = m_nowMouseX;
	m_maeMouseY = m_nowMouseY;
	m_nowMouseX = mouseX;
	m_nowMouseY = mouseY;

	//	m_markerX = mouseX + m_hotPointX;
	//	m_markerY = mouseY + m_hotPointY;





	if (m_ketteiMode)
	{
		m_ketteiCount--;
		if (CheckClick() || CheckClick(TRUE))
		{
			m_ketteiCount = 0;
		}

		if (m_ketteiCount <= 0)
		{
			int wNum = 1;					//通常(3つまで)
			if (m_mode == 1) wNum = 0;		//陵辱(1つのみ)

			for (i = 1; i < 8; i++)
			{
				if (CheckExistCard(i))
				{
					if (CheckExistCard(i, TRUE))
					{
						//組み合わせをセット
						int from = GetFromCard(i);
						int to = GetToCard(i);

						if (from > to)
						{
							int dd = from;
							from = to;
							to = dd;
						}

						SetVarData(m_kumiawaseVarNumber[wNum], from * 10 + to);
						wNum++;
					}
				}
			}


			//shuffle???
			if (m_game->GetVarData(m_shuffleVarNumber))
				//			if (1)
			{
				/////				Shuffle(kosuu);
			}





			//			int d = ((rand() % 12)+1) * 100 + (rand() % 2)*10 + 80;
			//			m_game->SetVarData(m_kumiawaseVarNumber[0],d);

			//			mana set


			m_game->SetYoyaku();
		}
		return -1;
	}






	m_onCard = -1;
	m_onCard2 = -1;



	if (m_catchCard == -1)
	{


		
		int rt = m_game->CalcuOptionButton();

		if (rt != NNNBUTTON_NOTHING)
		{
			int nm = ProcessCommonButton(rt);

			if (nm == 0)
			{
				TaihiKumiawase();
				return ReturnFadeOut(m_game->ChangeToSystemMode(SYSTEMMENU_MODE, BARA_KUMIAWASE_MODE));
			}
		}


		if (rt == NNNBUTTON_NOTHING)
		{
			int nextMode = m_game->ProcessGameKey(BARA_KUMIAWASE_MODE);
			if (nextMode != -1)
			{
				if (nextMode == SYSTEMMENU_MODE)
				{
					TaihiKumiawase();
					m_game->SetCommonBackMode(SYSTEMMENU_MODE, BARA_KUMIAWASE_MODE);
					m_game2->MakeMiniCG();
					m_game2->SetSaveMode(BARA_KUMIAWASE_MODE);
					return ReturnFadeOut(m_game->ChangeToSystemMode(SYSTEMMENU_MODE, BARA_KUMIAWASE_MODE));
				}
				if (nextMode == CONFIG_MODE)
				{
					TaihiKumiawase();
					m_game->SetCommonBackMode(CONFIG_MODE, BARA_KUMIAWASE_MODE);
					return ReturnFadeOut(m_game->ChangeToSystemMode(CONFIG_MODE, BARA_KUMIAWASE_MODE));
				}

				if (nextMode == BACKLOG_MODE)
				{
					TaihiKumiawase();
					m_game->SetCommonBackMode(BACKLOG_MODE, BARA_KUMIAWASE_MODE);
					return ReturnFadeOut(m_game->ChangeToSystemMode(BACKLOG_MODE, BARA_KUMIAWASE_MODE));
				}

				if (nextMode == LOAD_MODE)
				{
					TaihiKumiawase();
					m_game->SetCommonBackMode(LOAD_MODE, BARA_KUMIAWASE_MODE);
					return ReturnFadeOut(m_game->ChangeToSystemMode(LOAD_MODE, BARA_KUMIAWASE_MODE));
				}

				if (nextMode == SAVE_MODE)
				{
					TaihiKumiawase();
					m_game2->MakeMiniCG();
					m_game->SetCommonBackMode(SAVE_MODE, BARA_KUMIAWASE_MODE);
					return ReturnFadeOut(m_game->ChangeToSystemMode(SAVE_MODE, BARA_KUMIAWASE_MODE));
				}
			}




	/*
			int nm = ProcessCommonButton(rt);

			if (nm == 0)
			{
				TaihiKumiawase();
				m_game2->MakeMiniCG();
				m_game2->SetSaveMode(BARA_KUMIAWASE_MODE);
				return ReturnFadeOut(m_game->ChangeToSystemMode(SYSTEMMENU_MODE, BARA_KUMIAWASE_MODE));
			}

			if (nm == 1)
			{
				TaihiKumiawase();
				m_game->SetCommonBackMode(CONFIG_MODE, BARA_KUMIAWASE_MODE);
				return ReturnFadeOut(m_game->ChangeToSystemMode(CONFIG_MODE, BARA_KUMIAWASE_MODE));
			}

			if (nm == 2)
			{
				TaihiKumiawase();
				m_game->SetCommonBackMode(BACKLOG_MODE, BARA_KUMIAWASE_MODE);
				return ReturnFadeOut(m_game->ChangeToSystemMode(BACKLOG_MODE, BARA_KUMIAWASE_MODE));
			}

			if (nm == 3)
			{
				TaihiKumiawase();
				m_game2->MakeMiniCG();
				m_game->SetCommonBackMode(SAVE_MODE, BARA_KUMIAWASE_MODE);
				return ReturnFadeOut(m_game->ChangeToSystemMode(SAVE_MODE, BARA_KUMIAWASE_MODE));
			}

			if (nm == 4)
			{
				TaihiKumiawase();
				m_game->SetCommonBackMode(LOAD_MODE, BARA_KUMIAWASE_MODE);
				return ReturnFadeOut(m_game->ChangeToSystemMode(LOAD_MODE, BARA_KUMIAWASE_MODE));
			}

			if (nm == 5)//auto
			{
				int autoMode = m_game->GetSystemParam(NNNPARAM_AUTOMODE);
				m_game->SetSystemParam(NNNPARAM_AUTOMODE, 1 - autoMode);
			}
			if (nm == 6)//skip
			{
				m_game->SetMessageSkipFlag();
				m_game->InitFreeButton(NNN_FREEBUTTON_SKIP);

			}
//			if (nm == 7)//windowoff
//			{
//				if (CheckWindowOnOffEnable())
//				{
//					WindowOn(0);
//					m_game->SetSystemParam(NNNPARAM_AUTOMODE, 0);
//					CAreaControl::SetNextAllPrint();
//				}
//			}
*/


		//	int st = CCommonButton::GetButtonStatus(rt);
	//		if (st == NNNBUTTON_STARTCLICK) return -1;
//			if (st == NNNBUTTON_CLICKING) return -1;
		}

		

		

		//option
		/*
		if (m_game2->CheckOnOption(mouseX, mouseY))
		{
			if (CheckClick())
			{
				TaihiKumiawase();

				m_game2->SetSaveMode(BARA_KUMIAWASE_MODE);
				m_game2->MakeMiniCG();

				m_game->SetCommonBackMode(SAVE_MODE, BARA_KUMIAWASE_MODE);
				m_game->SetCommonBackMode(LOAD_MODE, BARA_KUMIAWASE_MODE);
				m_game->SetCommonBackMode(CONFIG_MODE, BARA_KUMIAWASE_MODE);
				m_game->SetCommonBackMode(SYSTEMMENU_MODE, BARA_KUMIAWASE_MODE);

//				m_game2->SetSaveBackMode(KUMIAWASE_MODE);//
//				m_game2->SetLoadBackMode(KUMIAWASE_MODE);
//				m_game2->SetConfigBackMode(KUMIAWASE_MODE);
//				m_game2->SetOptionBackMode(KUMIAWASE_MODE);

				m_game2->PlaySystemSound(SYSTEMSOUND_OK);
				return SYSTEMMENU_MODE;
			}
		}
		//keyboard shortcut

		if (m_game->CheckClickKey(LOAD_KEY))
		{
			m_game2->PlaySystemSound(SYSTEMSOUND_OK);
			TaihiKumiawase();
			m_game2->SetLoadBackMode(KUMIAWASE_MODE);
			return LOAD_MODE;
		}

		if (m_game2->CheckClickKey(SAVE_KEY))
		{
			m_game2->PlaySystemSound(SYSTEMSOUND_OK);
			TaihiKumiawase();
			m_game2->SetSaveMode(KUMIAWASE_MODE);
			m_game2->MakeMiniCG();
			m_game2->SetSaveBackMode(KUMIAWASE_MODE);
			return SAVE_MODE;
		}

		if (m_game->CheckClickKey(CONFIG_KEY))
		{
			m_game2->PlaySystemSound(SYSTEMSOUND_OK);
			TaihiKumiawase();
			m_game2->SetConfigBackMode(KUMIAWASE_MODE);
			return CONFIG_MODE;
		}

		if (m_game2->CheckClickKey(SYSTEMMENU_KEY) || m_game2->CheckClickKey(OPTIONMENU_KEY))
		{
			m_game2->PlaySystemSound(SYSTEMSOUND_OK);
			TaihiKumiawase();
			m_game2->SetSaveMode(KUMIAWASE_MODE);
			m_game2->MakeMiniCG();
			m_game2->SetSaveBackMode(KUMIAWASE_MODE);
			m_game2->SetLoadBackMode(KUMIAWASE_MODE);
			m_game2->SetConfigBackMode(KUMIAWASE_MODE);
			m_game2->SetOptionBackMode(KUMIAWASE_MODE);
			return OPTIONMENU_MODE;
		}
		*/



		CheckBookOpen(mouseX, mouseY);


		for (i = 1; i <= 7; i++)
		{
			if (CheckExistCard(i))
			{
				BOOL upperFlag = CheckExistCard(i, TRUE);
				if (CheckOnPlace(i, upperFlag, m_nowMouseX, m_nowMouseY))
				{
					if (upperFlag == FALSE)
					{
						if (CheckCatchOk(i, upperFlag))
						{
							m_onCard = i;
						}
					}
					else
					{
						m_onCard = i;
					}
				}
			}
		}



		if (CheckClick())
		{
			if (CheckOnOk(mouseX, mouseY))
			{
				if (m_mode == 1)
				{
					//1つ以上くみあわせあるか
					if (CheckHaveKumiawase() == FALSE) return -1;
				}


				m_game->PlaySystemSound(SYSTEMSOUND_CARDALLOK);
				m_ketteiCount = m_ketteiLastWait;
				CAreaControl::SetNextAllPrint();

				m_bookAnime = 1;
				m_bookAnimeCount = 0;
				Print();
				m_commonBG->GetScreen();

				m_ketteiMode = TRUE;

				return -1;
			}

			for (i = 1; i <= 7; i++)
			{
				if (CheckExistCard(i))
				{
					BOOL upperFlag = CheckExistCard(i, TRUE);
					if (CheckOnPlace(i, upperFlag, m_nowMouseX, m_nowMouseY))
					{
						if (CheckCatchOk(i, upperFlag))
						{
							m_catchFrom = i;
							m_catchCard = GetCardNumber(i, upperFlag);


							//攻めポイントもどす。つかったpower返却
							if (upperFlag)
							{
								RestoreSemePoint(i);
								int card = GetCardNumber(i);
								int needPower = GetNeedPoint(m_catchCard, card);
								AddMana(needPower);
							}


							EraseCardWork(m_catchFrom, upperFlag);

							ReCalcuCardOkWork();

							break;
						}
					}
				}
			}
		}





		if (CheckClick(TRUE))
		{
			for (i = 1; i <= 7; i++)
			{
				if (CheckExistCard(i))
				{
					if (CheckExistCard(i, TRUE))
					{
						BOOL flg = FALSE;

						if (CheckOnPlace(i, FALSE, m_nowMouseX, m_nowMouseY)) flg = TRUE;
						if (flg == FALSE)
						{
							if (CheckExistCard(i, TRUE))
							{
								if (CheckOnPlace(i, TRUE, m_nowMouseX, m_nowMouseY)) flg = TRUE;
							}
						}

						if (flg)
						{
							//カードをもどす。ポイントをもどす。攻めポイントをもどす

							m_game->PlaySystemSound(SYSTEMSOUND_CARDCANCEL);

							int fromCard = GetCardNumber(i, TRUE);
							int toCard = GetCardNumber(i);
							RestoreSemePoint(i);

							int needPower = GetNeedPoint(fromCard, toCard);
							AddMana(needPower);

							EraseCardWork(i, TRUE);
							SetCardToWork(fromCard, fromCard);

							ReCalcuCardOkWork();

							break;
						}
					}
				}
			}
		}


		if (m_catchCard != -1)
		{
			m_game2->PlaySystemSound(SYSTEMSOUND_CARDGET);

			m_dragFlag = FALSE;
			m_clickFlag = FALSE;
			m_dragCheckCount = 4;
			m_mouseStartZahyoX = m_nowMouseX;
			m_mouseStartZahyoY = m_nowMouseY;

			//				BookClose();
			m_bookOpenFlag = FALSE;
			m_bookAnime = 1;
			m_bookAnimeCount = 0;
		}
	}
	else
	{
		//		m_game->MyMouseOff();




		for (i = 1; i <= 7; i++)
		{
			if (CheckExistCard(i))
			{
				BOOL upperFlag = CheckExistCard(i, TRUE);
				if (CheckOnPlace(i, upperFlag, m_nowMouseX, m_nowMouseY))
				{
					if (CheckExistCard(i, TRUE) == FALSE)
					{
						int fromCard = m_catchCard;
						int toCard = GetCardNumber(i);
						if (CheckKasaneOkByFlag(fromCard, toCard))
						{
							if (CheckKasaneOkByPoint(fromCard, toCard))
							{
								m_onCard2 = i;
							}
						}
					}
				}
			}
		}



		m_dragCheckCount--;
		if (m_dragCheckCount < 0) m_dragCheckCount = 0;



		if (CheckClick(TRUE))
		{
			if (0)
				//			if (m_catchCard != m_catchFrom)
			{
				int fromCard = m_catchCard;
				int toCard = GetCardNumber(m_catchFrom);
				int needPoint = GetNeedPoint(fromCard, toCard);
				SubMana(needPoint);

				SetCardToWork(m_catchFrom, m_catchCard, TRUE);
				ChangeSemePoint(m_catchFrom);
			}
			else
			{
				//				SetCardToWork(m_catchFrom,m_catchCard);
				SetCardToWork(m_catchCard, m_catchCard);
			}


			//				AddMana(m_useMana);
			//				m_useMana = 0;
			m_game->PlaySystemSound(SYSTEMSOUND_CARDCANCEL);

			m_dragFlag = FALSE;
			m_catchCard = -1;

			ReCalcuCardOkWork();

			//			CAreaControl::SetNextAllPrint();
			//			TaihiKumiawaseVar();
		}
		else
		{
			//change to drag mode??
			if ((m_dragFlag == FALSE) && (m_clickFlag == FALSE))
			{
				if (m_mouseStatus->GetTrig(0) == FALSE)
				{
					if (m_dragCheckCount > 0)
					{
						m_clickFlag = TRUE;
					}
					else
					{
						int dx = m_nowMouseX - m_mouseStartZahyoX;
						int dy = m_nowMouseY - m_mouseStartZahyoY;

						if ((dx >= -6) && (dx < 6) && (dy >= -6) && (dy < 6))
						{
							m_clickFlag = TRUE;
						}
						else
						{
							m_dragFlag = TRUE;
						}
					}
				}
			}

			BOOL b = FALSE;
			if (CheckClick()) b = TRUE;
			if (m_dragFlag)
			{
				if (m_mouseStatus->GetTrig(0) == FALSE)
				{
					b = TRUE;
				}
			}


			if (b)
			{
				int place = GetOnPlace(m_nowMouseX, m_nowMouseY);
				if (place != -1)
				{
					//もとのうえか??
					if (place == m_catchCard)
					{
						m_game->PlaySystemSound(SYSTEMSOUND_CARDCANCEL);

						SetCardToWork(place, m_catchCard);

						m_dragFlag = FALSE;
						m_catchCard = -1;

						ReCalcuCardOkWork();

						//						CAreaControl::SetNextAllPrint();
						//						TaihiKumiawaseVar();
					}
					else
					{
						BOOL bb = FALSE;

						if (CheckExistCard(place))
						{
							if (CheckExistCard(place, TRUE) == FALSE)
							{
								int fromCard = m_catchCard;
								int toCard = GetCardNumber(place);
								if (CheckKasaneOkByFlag(fromCard, toCard))
								{
									if (CheckKasaneOkByPoint(fromCard, toCard))
									{
										//カードおく処理

										m_game->PlaySystemSound(SYSTEMSOUND_CARDRISE);

										int needPoint = GetNeedPoint(fromCard, toCard);
										SubMana(needPoint);

										SetCardToWork(place, m_catchCard, TRUE);
										ChangeSemePoint(place);

										m_catchCard = -1;
										ReCalcuCardOkWork();
										bb = TRUE;

									}
								}
							}
						}

						if (bb == FALSE)
						{
							m_clickFlag = TRUE;
							m_dragFlag = FALSE;
						}
					}
				}
				else
				{
					m_clickFlag = TRUE;
					m_dragFlag = FALSE;
				}
			}
		}
	}

	return -1;
}


int CKumiawase::Print(void)
{
	PrintBackScriptOrBG();
	CAreaControl::SetNextAllPrint();

//	BOOL b = CAreaControl::CheckAllPrintMode();

	CAllGraphics::FillScreen();
	BOOL b = CAreaControl::CheckAllPrintMode();

	//m_message->PrintMessage(300, 300, "くみあわせがめん");

	return PrintKumiawaseMode();

	return -1;
}


int CKumiawase::PrintKumiawaseMode(void)
{

	int i, j;
	CAreaControl::SetNextAllPrint();

	if (m_ketteiMode)
	{
		CAreaControl::SetNextAllPrint();
	}

	BOOL b = CAreaControl::CheckAllPrintMode();

//	m_game->SetOption();

	m_commonBG->Put(0, 0, FALSE);

	PrintMonth();
	PrintDate();
	PrintHour();

	m_lightCount++;
	m_lightCount %= 20;
	if (m_lightCount < 10)
	{
		m_lighting = m_lightCount * 3;
	}
	else
	{
		m_lighting = (20 - m_lightCount) * 3;
	}

	m_lightCount2++;
	m_lightCount2 %= 16;

	if (m_lightCount2 < 8)
	{
		m_lighting2 = m_lightCount2 * 8;
	}
	else
	{
		m_lighting2 = (16 - m_lightCount2) * 8;
	}


	for (j = 0; j < 8; j++)
	{
		for (i = 0; i < 2; i++)
		{
			m_cardPrintWork[j][i] = -1;
			m_cardPrintPointWork[j][i] = 0;
		}
	}

	if (m_catchCard == -1)
	{
		for (j = 1; j <= 7; j++)
		{
			int card = GetCardNumber(j);
			if (card >= 1)
			{
				int card2 = GetCardNumber(j, TRUE);
				if (card2 >= 1)
				{
					m_cardPrintWork[j][0] = 0;
					m_cardPrintWork[j][1] = 0;

					m_cardPrintColorWork[j][0] = CARDCOLOR_NORMAL;

					if (j != m_onCard)
					{
						m_cardPrintColorWork[j][1] = CARDCOLOR_NORMAL;
					}
					else
					{
						m_cardPrintColorWork[j][1] = CARDCOLOR_LIGHT;
					}
				}
				else
				{
					m_cardPrintWork[j][0] = 0;

					//					if (CheckCatchCard(j))
					if (CheckCatchOk(j, FALSE))
					{
						m_cardPrintColorWork[j][0] = CARDCOLOR_NORMAL;
						if (m_onCard == j)
						{
							m_cardPrintColorWork[j][0] = CARDCOLOR_LIGHT;
						}
					}
					else
					{
						m_cardPrintColorWork[j][0] = CARDCOLOR_GREY;
					}
				}
			}
		}
	}
	else
	{
		for (j = 1; j <= 7; j++)
		{
			if (m_catchCard == j)
			{
				m_cardPrintWork[j][0] = 0;
				m_cardPrintColorWork[j][0] = CARDCOLOR_TRANS2;
			}
			else
			{
				int card = GetCardNumber(j);
				if (card > 0)
				{
					int card2 = GetCardNumber(j, TRUE);
					if (card2 < 1)
					{
						//のせられるかどうか
						m_cardPrintWork[j][0] = 0;

						if (CheckKasaneOkByFlag(m_catchCard, card))
						{
							m_cardPrintPointWork[j][0] = GetNeedPoint(m_catchCard, card);

							if (CheckKasaneOkByPoint(m_catchCard, card))
							{
								if (j != m_onCard2)
								{
									m_cardPrintColorWork[j][0] = CARDCOLOR_NORMAL;
								}
								else
								{
									m_cardPrintColorWork[j][0] = CARDCOLOR_LIGHT2;
								}
							}
							else
							{
								m_cardPrintColorWork[j][0] = CARDCOLOR_RED;
							}
						}
						else
						{
							m_cardPrintColorWork[j][0] = CARDCOLOR_GREY;
						}
					}
					else
					{
						m_cardPrintWork[j][0] = 0;
						m_cardPrintWork[j][1] = 0;

						m_cardPrintColorWork[j][0] = CARDCOLOR_NORMAL;
						m_cardPrintColorWork[j][1] = CARDCOLOR_NORMAL;
					}
				}
			}
		}
	}










	/*
		for (i=1;i<=7;i++)
		{
			POINT pt = GetCardBaseZahyo(i);
	//		SIZE sz = GetCardSize();

			PutCardKage(i);


			PutCardOnly(i,1,pt,i % 6);



			PutGazeOnly(pt,GAZETYPE_SEME + (i % 2),10 + 8 * i);

			PutNeedPointOnly(i,i);
		}
	*/



	//ろうそく
	for (i = 0; i < 10; i++)
	{
		PutCandle(i, m_candleMode[i], m_candleAnime[i], m_candleFireAnime[i]);	//dummy
	}


	for (j = 1; j <= 7; j++)
	{


		int md = m_cardPrintWork[j][0];
		if (md != -1)
		{
			int card = GetCardNumber(j);
			if (m_catchCard == j)
			{
				card = m_catchCard;
			}
			else
			{
				//かげ
				PutCardKage(j);
			}

			int col = m_cardPrintColorWork[j][0];
			POINT pt = GetCardBaseZahyo(j);


			PutCard(card, md, pt, col);

			int needPoint = m_cardPrintPointWork[j][0];
			if (needPoint > 0)
			{
				PutNeedPointOnly(j, needPoint);
			}


			if (m_catchCard != -1)
			{
				if (m_catchCard != j)
				{
					int card2 = GetCardNumber(j, TRUE);
					if (card2 < 1)
					{
						int ukePoint = GetSemePoint(card, m_catchCard);
						PutGazeOnly(pt, GAZETYPE_UKE, ukePoint);
					}
				}
			}




			int md2 = m_cardPrintWork[j][1];
			if (md2 != -1)
			{
				int card2 = GetCardNumber(j, TRUE);
				int col2 = m_cardPrintColorWork[j][1];
				POINT pt2 = GetUpperCaedDelta();
				pt.x += pt2.x;
				pt.y += pt2.y;

				PutCard(card2, md, pt, col2);
			}
		}
	}







	if (m_catchCard != -1)
	{
		SIZE sz = GetCardSize();
		int sizeX = sz.cx;
		int sizeY = sz.cy;

		int putX = m_nowMouseX - sizeX / 2;
		int putY = m_nowMouseY - sizeY / 2;

		m_cardPic[m_catchCard - 1][1]->TransLucentBlt2(putX, putY, 0, 0, sizeX, sizeY, 70);



		int place = GetOnPlace(m_nowMouseX, m_nowMouseY);
		if (place != -1)
		{
			if (place != m_catchCard)
			{
				int card = GetCardNumber(place);
				if (card > 0)
				{
					int card2 = GetCardNumber(place, TRUE);
					if (card2 < 1)
					{
						if (CheckKasaneOkByFlag(m_catchCard, card))
						{
							//ポイントはチェックしない
							POINT pt;
							pt.x = putX;
							pt.y = putY;

							int semePoint = GetSemePoint(m_catchCard, card);
							PutGazeOnly(pt, GAZETYPE_SEME, semePoint);
						}
					}
				}
			}
		}
	}


	BOOL b1 = TRUE;
	if (m_mode == 1)
	{
		if (CheckHaveKumiawase() == FALSE) b1 = FALSE;
	}
	if (m_catchCard != -1) b1 = FALSE;



	if (b1)
	{
		CalcuOkButtonAnime();
		int anime = m_okButtonAnime2;

		if (CheckOnOk(m_nowMouseX, m_nowMouseY) == FALSE)
		{
			int ps = ((m_choAnimeDiv - m_okButtonAnimeAmari) * 100) / m_choAnimeDiv;
			PutOkButton(0, m_okButtonAnime, m_okButtonAnime2, ps);
		}
		else
		{
			int ps = ((m_choAnimeDiv - m_okButtonAnimeAmari) * 100) / m_choAnimeDiv;
			PutOkButton(1, m_okButtonAnime, m_okButtonAnime2, ps, MYCOLOR_NORMAL);
		}
	}
	else
	{
		int ps = ((m_choAnimeDiv - m_okButtonAnimeAmari) * 100) / m_choAnimeDiv;
		PutOkButton(0, m_okButtonAnime, m_okButtonAnime2, ps, MYCOLOR_GREY);
		//		PutOkButton(0,0,1,100,MYCOLOR_GREY);
	}



	PrintHana();

	m_game->PrintOptionButtonYoyaku();


	return -1;
	/*
		if (m_ketteiMode)
		{
			int col = ((m_ketteiLastWait-m_ketteiCount) * 255) / m_ketteiLastWait0;
			if (col>255) col = 255;
			if (col<0) col = 0;

			col *= -1;

			m_commonBG->ColorAddBlt(0,0,0,0,800,600,FALSE,col,col,col);

			int ps = ((m_ketteiLastWait-m_ketteiCount) * 100) / m_ketteiLastWait0;
			if (ps<0) ps = 0;
			if (ps>100) ps = 100;
			m_commonParts->TransLucentBlt2(69,195,0,0,640,112,ps);


			return -1;
		}

		m_game->SetCalendarFlag();

		if (m_catchCard == -1)
		{
			m_game->SetOption();
		}

		BookAnime();

		int cursorX1 = m_maeMouseX;
		int cursorY1 = m_maeMouseY;
		int cursorX2 = m_nowMouseX;
		int cursorY2 = m_nowMouseY;


		for (i=0;i<m_areaKosuu;i++)
		{
			m_cardPrintFlag[i] = FALSE;
			if (b) m_cardPrintFlag[i] = TRUE;

			if (CheckOverrapCardAndCursor(i,cursorX1,cursorY1)) m_cardPrintFlag[i] = TRUE;
			if (CheckOverrapCardAndCursor(i,cursorX2,cursorY2)) m_cardPrintFlag[i] = TRUE;
		}

		m_specialPrintFlag = FALSE;
		if (b) m_specialPrintFlag = TRUE;
		if (CheckOverrapSpecialAndCursor(cursorX1,cursorY1)) m_specialPrintFlag = TRUE;
		if (CheckOverrapSpecialAndCursor(cursorX2,cursorY2)) m_specialPrintFlag = TRUE;

		//erase
		if (b)
		{
			m_commonBG->Put(0,0,FALSE);
		}
		else
		{
			for (i=0;i<m_areaKosuu;i++)
			{
				if (m_cardPrintFlag[i])
				{
					EraseCardArea(i);
					AddUpdateCardArea(i);
				}
			}

			if (m_specialPrintFlag)
			{
				EraseSpecialArea();
				AddUpdateSpecialArea();
			}

			EraseCursorArea(cursorX1,cursorY1);
			AddUpdateCursorArea(cursorX1,cursorY1);

			if ((cursorX1 != cursorX2) || (cursorY1 != cursorY2))
			{
				EraseCursorArea(cursorX2,cursorY2);
				AddUpdateCursorArea(cursorX2,cursorY2);
			}


			//ろうそく
			EraseCandleArea();
			AddUpdateCandleArea();


			//決定ボタン
			EraseOkArea();
			AddUpdateOkArea();
		}


		for (i=0;i<m_areaKosuu;i++)
		{
			if (m_cardPrintFlag[i])
			{
				PutCard(i);
			}
		}

		if (m_specialPrintFlag)
		{
			PutSpecial();
			if (m_catchCard != -1)
			{
				for (i=0;i<2;i++)
				{
					if (CheckOnSpecialChara(i,m_markerX,m_markerY))
					{
						if ((m_specialCharaColorMode[i] == MYCOLOR_NORMAL) || (m_specialCharaColorMode[i] == MYCOLOR_ADD))
						{
							PutSpecialWaku(i);
						}
					}
				}
			}
		}

	//	PutCursor(cursorX2,cursorY2);

		//ろうそく
		if (m_mode == 0)
		{
			for (i=0;i<10;i++)
			{
				PutCandle(i,m_candleMode[i],m_candleAnime[i],m_candleFireAnime[i]);	//dummy
			}
		}


		//決定ボタン
		if (m_mode == 0)
		{
			if (m_catchCard == -1)
			{
				if (m_bookOpenFlag == FALSE)
				{
					if (m_bookAnime == 0)
					{
						int sizeX = 104;
						int sizeY = 88;
						int srcX = (2-(m_bookAnimeCount) / 2) * sizeX;
						int srcY = 0;

						m_openingBookPic->Blt(680,497,srcX,srcY,sizeX,sizeY,TRUE);
					}
					else
					{
						m_gradColor->CalcuGrad();

						int colR = m_gradColor->GetGradR();
						int colG = m_gradColor->GetGradG();
						int colB = m_gradColor->GetGradB();

						m_bookBackPic->ColorBlt(724,501,0,0,64,88,TRUE,colR,colG,colB);
						m_closedBookPic->Put(724,501,TRUE);
					}
				}
				else
				{
					if (m_bookAnime == 0)
					{
						int sizeX = 104;
						int sizeY = 88;
						int srcX = (m_bookAnimeCount / 2) * sizeX;
						int srcY = 0;
						m_openingBookPic->Blt(680,497,srcX,srcY,sizeX,sizeY,TRUE);
					}
					else
					{
						int sizeX = 104;
						int sizeY = 88;
						int srcX = (m_bookAnimeCount / 2) * sizeX;
						int srcY = 0;
						m_animeBookPic->Blt(680,497,srcX,srcY,sizeX,sizeY,TRUE);
					}
				}

		//		m_openedBookPic->Put(675,503,TRUE);
			}
		}

	//	m_openedBookPic = m_game->GetSystemPicture("ta本");
	//	m_closedBookPic = m_game->GetSystemPicture("ta本待機");
	//	m_openingBookPic = m_game->GetSystemPicture("ta本アニメ１");
	//	m_animeBookPic = m_game->GetSystemPicture("ta本アニメ２");


		if (m_catchCard != -1)
		{
			PutCursor(m_catchCard,m_nowMouseX,m_nowMouseY);
		}

	//	m_menu->Print(b);
	*/
	return -1;
}

//
//
//人物発生表示=1;
//人物追加表示=2;
//堕落バー表示=3;
//１→２変化表示=4;
//２→３変化表示=5;
//
//
//
//


//人物発生		1-12
//　（人物発生表示プログラムで発生する人物を特定するために使用）
//人物追加		1-12 21-38
//　（人物追加表示プログラムで発生する人物を特定するために使用）
//１→２変化カード	1-12
//　（１→２変化表示プログラムで発生する人物を特定するために使用）
//２→３変化カード	1-12
//　（２→３変化表示プログラムで発生する人物を特定するために使用）



void CKumiawase::SetMode(int md, BOOL onlyFlag)
{
	m_mode = md;
	//	TaihiKumiawase();


	if (onlyFlag) return;

	int i;

	m_power = 10;
	for (i = 0; i < 8; i++)
	{
		m_cardWork[i] = 0;
	}

	for (i = 0; i < 4; i++)
	{
		SetVarData(m_kumiawaseVarNumber[i], 0);
	}



	for (int j = 0; j < 8; j++)
	{
		m_cardWork[j] = 0;

		if ((j >= 1) && (j <= 7))
		{
			if (CheckExistChara(j))
			{
				m_cardWork[j] = (j << 16);
			}
		}
	}



	TaihiKumiawase();
}



/*
void CKumiawase::EraseCardArea(int n)
{
	int putX = m_cardPrintX[n];
	int putY = m_cardPrintY[n];
	int sizeX = m_cardSizeX;
	int sizeY = m_cardSizeY;

	m_commonBG->Blt(putX,putY,putX,putY,sizeX,sizeY,FALSE);
}

void CKumiawase::EraseSpecialArea(void)
{
	int putX = m_specialPrintX;
	int putY = m_specialPrintY;
	int sizeX = m_specialSizeX;
	int sizeY = m_specialSizeY;

	m_commonBG->Blt(putX,putY,putX,putY,sizeX,sizeY,FALSE);
}

void CKumiawase::EraseCursorArea(int x, int y)
{
	int putX = x + m_cursorPrintDeltaX;
	int putY = y + m_cursorPrintDeltaY;
	int sizeX = m_cursorSizeX;
	int sizeY = m_cursorSizeY;

	m_commonBG->Blt(putX,putY,putX,putY,sizeX,sizeY,FALSE);
}

void CKumiawase::EraseCandleArea(void)
{
	int putX = m_candleAreaPrintX;
	int putY = m_candleAreaPrintY;
	int sizeX = m_candleAreaSizeX;
	int sizeY = m_candleAreaSizeY;

	m_commonBG->Blt(putX,putY,putX,putY,sizeX,sizeY,FALSE);
}

void CKumiawase::EraseOkArea(void)
{
	int putX = 675;
	int putY = 497;
	int sizeX = 125;
	int sizeY = 103;

	m_commonBG->Blt(putX,putY,putX,putY,sizeX,sizeY,FALSE);
}

void CKumiawase::AddUpdateCardArea(int n)
{
	int putX = m_cardPrintX[n];
	int putY = m_cardPrintY[n];
	int sizeX = m_cardSizeX;
	int sizeY = m_cardSizeY;

	CAreaControl::AddArea(putX,putY,sizeX,sizeY);
}

void CKumiawase::AddUpdateSpecialArea(void)
{
	int putX = m_specialPrintX;
	int putY = m_specialPrintY;
	int sizeX = m_specialSizeX;
	int sizeY = m_specialSizeY;

	CAreaControl::AddArea(putX,putY,sizeX,sizeY);
}


void CKumiawase::AddUpdateCursorArea(int x, int y)
{
	int putX = x + m_cursorPrintDeltaX;
	int putY = y + m_cursorPrintDeltaY;
	int sizeX = m_cursorSizeX;
	int sizeY = m_cursorSizeY;

	CAreaControl::AddArea(putX,putY,sizeX,sizeY);
}


void CKumiawase::AddUpdateCandleArea(void)
{
	int putX = m_candleAreaPrintX;
	int putY = m_candleAreaPrintY;
	int sizeX = m_candleAreaSizeX;
	int sizeY = m_candleAreaSizeY;

	CAreaControl::AddArea(putX,putY,sizeX,sizeY);
}


void CKumiawase::AddUpdateOkArea(void)
{
	int putX = 675;
	int putY = 497;
	int sizeX = 125;
	int sizeY = 103;

	CAreaControl::AddArea(putX,putY,sizeX,sizeY);
}


BOOL CKumiawase::CheckOverrapCardAndCursor(int n, int x, int y)
{
	int x1 = m_cardPrintX[n];
	int y1 = m_cardPrintY[n];
	int sx1 = m_cardSizeX;
	int sy1 = m_cardSizeY;

	int x2 = x + m_cursorPrintDeltaX;
	int y2 = y + m_cursorPrintDeltaY;
	int sx2 = m_cursorSizeX;
	int sy2 = m_cursorSizeY;

	RECT rc1;
	RECT rc2;
	RECT rc;


	SetRect(&rc1,x1,y1,x1+sx1,y1+sy1);
	SetRect(&rc2,x2,y2,x2+sx2,y2+sy2);

	if (IntersectRect(&rc,&rc1,&rc2)) return TRUE;

	return FALSE;
}



BOOL CKumiawase::CheckOverrapSpecialAndCursor(int x, int y)
{
	int x1 = m_specialPrintX;
	int y1 = m_specialPrintY;
	int sx1 = m_specialSizeX;
	int sy1 = m_specialSizeY;

	int x2 = x + m_cursorPrintDeltaX;
	int y2 = y + m_cursorPrintDeltaY;
	int sx2 = m_cursorSizeX;
	int sy2 = m_cursorSizeY;

	RECT rc1;
	RECT rc2;
	RECT rc;

	SetRect(&rc1,x1,y1,x1+sx1,y1+sy1);
	SetRect(&rc2,x2,y2,x2+sx2,y2+sy2);

	if (IntersectRect(&rc,&rc1,&rc2)) return TRUE;

	return FALSE;
}


void CKumiawase::PutCard(int n)
{
//	PutCardOnly(n);
	PutCardMarker(n);
	if (m_catchCard != -1) PutWaku(n);
}
*/


/*
void CKumiawase::PutCardOnly(int n)
{
	int i;

	int st = m_areaStatus[n];

	int waku = 0;
	int ps = 40;
	int colR = 0;
	int colG = 38;
	int colB = 255;
	int wakuSizeY = 250;

	if (st == 0)
	{
	}
	else
	{
		wakuSizeY = 220;
	}

	if (st>=11)
	{
		waku = 1;
		colR = 255;
		colG = 0;
		colB = 21;
	}
	else
	{
		//サブキャラがいないとき、わくを、ちぢめるか？

	}

	int x = m_cardPrintX[n];
	int y = m_cardPrintY[n];
	int sizeX = 160;
	int sizeY = 8;

//	m_cardUpperPic[waku]->TransLucentBlt2(x,y,0,0,sizeX,sizeY,ps);
//	m_cardLowerPic[waku]->TransLucentBlt2(x,y+wakuSizeY-sizeY,0,0,sizeX,sizeY,ps);

//	CPicture::TransBox(x,y+sizeY,sizeX,wakuSizeY-sizeY*2,colR,colG,colB,ps);


	int sizePercent = 100;
	int transPercent = 50;

	if (st>=1) sizePercent = 82;
	if (st == 0)
	{
		if (CheckAreaHaveChara(n) == 0)
		{
			sizePercent = 0;
		}
	}

	PutCardWaku(n,st,transPercent,sizePercent);


	//あかわく
	if (st == 0)
	{
	}

	if (CheckAreaHaveChara(n)>0)
	{
		PutSubCharaWaku(n,st,st);
	}

	//サブキャラわく
	x = m_cardPrintX[n] + 7;
	y = m_cardPrintY[n] + 221;
	if (st != 0)
	{
		y = m_cardPrintY[n] + 191;
	}
//	m_subCharaWakuPic->TransLucentBlt2(x,y,0,0,146,23,50);





	PutAreaTag(n,m_areaColorMode[n]);

	if (st == 0)
	{

		for (i=0;i<2;i++)
		{
			int k = n * 2 + i;
			if (m_mainCharaPrintFlag[k])
			{
				PutMainChara(k,m_mainCharaColorMode[k],50);
			}
		}

		int nz = m_areaHyojiType[n];
		for (i=0;i<nz;i++)
		{
			int k = n * 3 + i;
			if (m_subCharaPrintFlag[k])
			{
				PutSubChara(k,m_subCharaColorMode[k],50);
			}
		}
	}
	else
	{
		PutKakuteiChara(n,m_kakuteiCharaColorMode[n],50);

	}
}
*/

/*
void CKumiawase::PutCardMarker(int n)
{
	int st = m_areaStatus[n];


	//marker
	if (st == 0)
	{
		int marker = GetOtherOnArea(n);
		if (marker != -1)
		{
			int md = -1;
			if (marker == m_lightMarkerNumber) md = MYCOLOR_ADD;
			PutOnAreaMarker(marker ,n, md );
		}


		for (int i=0;i<2;i++)
		{
			int ch = n * 2 + i;
			marker = GetOtherOnMain(ch);
			if (marker != -1)
			{
				int md = -1;
				if (marker == m_lightMarkerNumber) md = MYCOLOR_ADD;
				PutOnMainMarker(marker,ch,md);
			}
		}

		int nz = m_areaHyojiType[n];

		for (i=0;i<nz;i++)
		{
			int ch = n * 3 + i;
			marker = GetOtherOnSub(ch);
			if (marker != -1)
			{
				int md = -1;
				if (marker == m_lightMarkerNumber) md = MYCOLOR_ADD;
				PutOnSubMarker(marker,ch, md );
			}
		}
	}
	else
	{
		int marker = GetOtherOnKakutei(n);
		if (marker != -1)
		{
			int md = -1;
			if (marker == m_lightMarkerNumber) md = MYCOLOR_ADD;
			PutOnKakuteiMarker(marker, n, md);
		}
	}

}



void CKumiawase::PutSpecial(void)
{
	//waku

	int x = m_specialPrintX;
	int y = m_specialPrintY;

	int sizeX = m_specialSizeX;
	int sizeY = 8;
	int wakuSizeY = m_specialSizeY;

	int colR = 255;
	int colG = 0;
	int colB = 63;
	int ps = 50;

	m_specialCardUpperPic->TransLucentBlt2(x,y,0,0,sizeX,sizeY,ps);
	m_specialCardLowerPic->TransLucentBlt2(x,y+wakuSizeY-sizeY,0,0,sizeX,sizeY,ps);

	CPicture::TransBox(x,y+sizeY,sizeX,wakuSizeY-sizeY*2,colR,colG,colB,ps);

	//chara

	for (int i=0;i<m_specialCharaKosuu;i++)
	{
		PutSpecialChara(i);
		//marker

		int marker = GetOtherOnSpecial(i);

		if (marker != -1)
		{
			int md = -1;
			if (marker == m_lightMarkerNumber) md = MYCOLOR_ADD;
			PutOnSpecialMarker(marker ,i, md );
		}

	}
}



void CKumiawase::PutCursor(int n, int x, int y)
{
	if ((n<0) || (n>=m_kumiawaseKosuu)) return;

	int putX = x + m_cursorPrintDeltaX;
	int putY = y + m_cursorPrintDeltaY;
	int sizeX = m_cursorSizeX;
	int sizeY = m_cursorSizeY;

	m_cursorPic[n]->Blt(putX,putY,0,0,sizeX,sizeY,TRUE);
}


void CKumiawase::PutAreaTag(int n, int md)
{
	if (md == -1) md = m_areaColorMode[n];

	int x = m_cardPrintX[n] + m_areaPrintDeltaX;
	int y = m_cardPrintY[n] + m_areaPrintDeltaY;

	int sizeX = m_areaSizeX;
	int sizeY = m_areaSizeY;

	PutModePic(m_areaPic[n],md,x,y,sizeX,sizeY);
}



void CKumiawase::PutMainChara(int n,int md,int transPercent,BOOL notPrintBarFlag)
{
	if (md == -1) md = m_mainCharaColorMode[n];



	int cd = n / 2;
	int n2 = n % 2;

//	POINT pt = GetMainCharaZahyo(n);

	int x = m_cardPrintX[cd] + m_mainCharaPrintDeltaX[n2];
	int y = m_cardPrintY[cd] + m_mainCharaPrintDeltaY[n2];

	int sizeX = m_mainCharaSizeX;
	int sizeY = m_mainCharaSizeY;

	PutModePic(m_mainCharaPic[n],md,x,y,sizeX,sizeY,transPercent);

	if (notPrintBarFlag == FALSE)
	{
		//mana suuji
		int mana = m_mainCharaNeedMana[n];
		if ((mana>=0) && (mana<=2))
		{
			m_manaSuujiPic[mana]->Blt(x+56,y+4,0,0,18,20,TRUE);
		}

		int gaze = m_mainDaraku[n];
		POINT pt2 = GetMainCharaGazeZahyo(n);

		PutBar(0,pt2,gaze);
	}



}




void CKumiawase::PutSubChara(int n,int md,int transPercent)
{
	if (md == -1) md = m_subCharaColorMode[n];

	POINT pt = GetSubCharaZahyo(n);
	SIZE sz = GetSubCharaSize();
	PutModePic(m_subCharaPic[n],md,pt,sz,transPercent);


	int mana = 1;
	int x = pt.x;
	int y = pt.y;


	if ((mana>=0) && (mana<=2))
	{
		m_manaSuujiPic[mana]->Blt(x+sz.cx - 18, y+sz.cy - 20 ,0,0,18,20,TRUE);
	}

}



void CKumiawase::PutKakuteiChara(int n,int md,int transPercent)
{
	if (md == -1) md = m_kakuteiCharaColorMode[n];

	POINT pt = GetKakuteiCharaZahyo(n);
	SIZE sz = GetKakuteiCharaSize();
	PutModePic(m_kakuteiPic[n],md,pt,sz,transPercent);


	int nn = n * 2 + ((m_areaStatus[n] % 10) - 1);

	//mana suuji
	int mana = m_mainCharaNeedMana[nn];
	if ((mana>=0) && (mana<=2))
	{
		m_manaSuujiPic[mana]->Blt(pt.x+105,pt.y+122,0,0,18,20,TRUE);
	}


	//bar
	POINT pt2 = GetKakuteiCharaGazeZahyo(n);

	int gaze = m_mainDaraku[nn] - 100;
	PutBar(1,pt2,gaze);
}


void CKumiawase::PutSpecialChara(int n,int md,int transPercent)
{
	POINT pt = GetSpecialCharaZahyo(n);
	SIZE sz = GetSpecialCharaSize();
	PutModePic(m_specialCharaPic[n],m_specialCharaColorMode[n],pt,sz);


	//mana suuji
	int mana = m_specialCharaNeedMana[n];
	if ((mana>=0) && (mana<=2))
	{
		m_manaSuujiPic[mana]->Blt(pt.x+56,pt.y+4,0,0,18,20,TRUE);
	}

}



void CKumiawase::PutOnMainMarker(int n, int k, int md)
{
	if (md == -1) md = GetMarkerPrintMode();

	POINT pt = GetMainMarkerZahyo(k);
	SIZE sz = GetMarkerSize();
	PutModePic(m_markerPic[n],md,pt,sz);
}


void CKumiawase::PutOnSubMarker(int n, int k, int md)
{
	if (md == -1) md = GetMarkerPrintMode();

	POINT pt = GetSubMarkerZahyo(k);
	SIZE sz = GetMarkerSize();
	PutModePic(m_markerPic[n],md,pt,sz);
}

void CKumiawase::PutOnAreaMarker(int n, int k, int md)
{
	if (md == -1) md = GetMarkerPrintMode();

	POINT pt = GetAreaMarkerZahyo(k);
	SIZE sz = GetMarkerSize();
	PutModePic(m_markerPic[n],md,pt,sz);
}

void CKumiawase::PutOnKakuteiMarker(int n, int k, int md)
{
	if (md == -1) md = GetMarkerPrintMode();

	POINT pt = GetKakuteiMarkerZahyo(k);
	SIZE sz = GetMarkerSize();
	PutModePic(m_markerPic[n],md,pt,sz);
}

void CKumiawase::PutOnSpecialMarker(int n, int k, int md)
{
	if (md == -1) md = GetMarkerPrintMode();

	POINT pt = GetSpecialMarkerZahyo(k);
	SIZE sz = GetMarkerSize();
	PutModePic(m_markerPic[n],md,pt,sz);
}


int CKumiawase::GetMarkerPrintMode(void)
{
	if (m_catchCard == -1) return MYCOLOR_NORMAL;

	return MYCOLOR_GREY;
}



*/







void CKumiawase::PutCandle(int n, int md, int anime, int anime2)
{
	int baseX = m_candleAreaPrintX;
	int baseY = m_candleAreaPrintY;

	baseX += (n % 5) * 27;
	baseY += (n / 5) * 60;

	int candleX = baseX + 2;
	int candleY = baseY + 10;

	int fireX = baseX + 0;
	int fireY = baseY + 0;

	int smokeX = baseX + 12;
	int smokeY = baseY + 5;

	if (md == 0)
	{
		m_candleBasePic->Blt(candleX, candleY, 0, 0, 32, 52, TRUE);
	}
	else if (md == 1)
	{
		int sizeX0 = 32;
		int sizeY0 = 32;
		int aaa = anime2;
		if (aaa == 3) aaa = 1;
		int srcX0 = sizeX0 * aaa;
		int srcY0 = 0;

		//		m_candleFirePic->Blt(fireX,fireY,srcX,srcY,sizeX,sizeY,TRUE);
		//		m_candleFirePic->TransLucentBlt2(fireX,fireY,srcX,srcY,sizeX,sizeY,40);

		int sizeX = 32;
		int sizeY = 52;
		int srcX = sizeX * anime;
		int srcY = 0;

		m_candleNormalPic->Blt(candleX, candleY, srcX, srcY, sizeX, sizeY, TRUE);

		m_candleFirePic->TransLucentBlt2(fireX, fireY, srcX0, srcY0, sizeX0, sizeY0, 40);

	}
	else if (md == 2)
	{
		int sizeX = 32;
		int sizeY = 52;
		int srcX = sizeX * anime;
		int srcY = 0;

		m_candleDarkPic->Blt(candleX, candleY, srcX, srcY, sizeX, sizeY, TRUE);

	}
	else if (md == 3)
	{
		m_candleBasePic->Blt(candleX, candleY, 0, 0, 32, 52, TRUE);


		int sizeX = 66;
		int sizeY = 20;
		int srcX = sizeX * anime;
		int srcY = 0;

		m_candleSmokePic->Blt(smokeX, smokeY, srcX, srcY, sizeX, sizeY, TRUE);
	}
	else if (md == 4)
	{
		int sizeX = 32;
		int sizeY = 52;
		int srcX = sizeX * anime;
		int srcY = 0;

		m_candleLightPic->Blt(candleX, candleY, srcX, srcY, sizeX, sizeY, TRUE);

	}

}



void CKumiawase::SetCandle(int n, int md, int anime, int waitCount, int nextMode)
{
	m_candleMode[n] = md;
	m_candleCount[n] = 0;
	m_candleAnime[n] = anime;
	m_candleWait[n] = waitCount;
	m_candleNextMode[n] = nextMode;
	m_candleFireCount[n] = 0;
	m_candleFireAnime[n] = 0;
}



//
// 0:きえてる
// 1:ついてる
// 2:きえる(5pt)	-> 3
// 3:きえる(2pt)	-> 0
// 4:つく			3pt	-> 1
//


void CKumiawase::CalcuCandleAnime(void)
{
	for (int i = 0; i < 10; i++)
	{
		int count = m_candleCount[i];
		int waitCount = m_candleWait[i];

		if (waitCount > 0)
		{
			waitCount--;
			if (waitCount <= 0)
			{
				waitCount = 0;
				m_candleMode[i] = m_candleNextMode[i];
				m_candleCount[i] = 0;
				m_candleAnime[i] = 0;
			}
			m_candleWait[i] = waitCount;
		}


		int md = m_candleMode[i];
		int anime = m_candleAnime[i];

		if (md == 0)
		{
			//nothing
		}
		else if (md == 1)
		{
			count++;
			if ((rand() % 100) < 75) count += 1;
			if (count >= 2)
			{
				count = 0;
				anime++;
				if (anime >= 3)
				{
					anime = 0;
				}
				m_candleAnime[i] = anime;
			}
			m_candleCount[i] = count;

			int count2 = m_candleFireCount[i];
			int anime2 = m_candleFireAnime[i];
			count2++;
			if ((rand() % 100) < 30) count2 += 2;
			if (count2 >= 3)
			{
				count2 = 0;
				anime2++;
				if (anime2 >= 4)
				{
					anime2 = 0;
				}
				m_candleFireAnime[i] = anime2;
			}
			m_candleFireCount[i] = count2;
		}
		else if (md == 2)
		{
			count++;
			m_candleCount[i] = count;

			if (count >= 2)
			{
				count = 0;
				m_candleCount[i] = count;

				anime++;
				m_candleAnime[i] = anime;

				if (anime >= 5)
				{
					SetCandle(i, 3);
				}
			}
		}
		else if (md == 3)
		{
			count++;
			m_candleCount[i] = count;

			if (count >= 2)
			{
				count = 0;
				m_candleCount[i] = count;

				anime++;
				m_candleAnime[i] = anime;

				if (anime >= 5)
				{
					SetCandle(i, 0);
				}
			}
		}
		else if (md == 4)
		{
			count++;
			m_candleCount[i] = count;

			if (count >= 2)
			{
				count = 0;
				m_candleCount[i] = count;

				anime++;
				m_candleAnime[i] = anime;

				if (anime >= 3)
				{
					SetCandle(i, 1);
				}
			}
		}
	}
}







void CKumiawase::AddMana(int mana)
{
	m_power += mana;
	if (m_power >= 10) m_power = 10;
	if (m_power < 0) m_power = 0;

	//	m_game->SetVarData(m_shihairyokuVarNumber,m_power);

	DmyCandle();
}

void CKumiawase::SubMana(int mana)
{
	m_power -= mana;
	if (m_power >= 10) m_power = 10;
	if (m_power < 0) m_power = 0;

	//	m_game->SetVarData(m_shihairyokuVarNumber,m_power);

	DmyCandle();
}



void CKumiawase::DmyCandle(void)
{
	int i;

	int light = 0;
	for (i = 0; i < 10; i++)
	{
		int md = m_candleMode[i];
		if ((md == 0) || (md == 2) || (md == 3)) break;
		light++;
	}

	for (i = 0; i < light; i++) SetCandle(i, 1);
	for (i = light; i < 10; i++) SetCandle(i, 0);

	if (light < m_power)
	{
		int wait = 1;
		for (i = light; i < m_power; i++)
		{
			SetCandle(i, 0, 0, wait, 4);
			wait += 10;
		}
	}
	else if (light > m_power)
	{
		int wait = 1;
		for (i = light - 1; i >= m_power; i--)
		{
			SetCandle(i, 1, 0, wait, 2);
			wait += 10;
		}
	}
}

/*
void CKumiawase::Shuffle(int kosuu)
{
	if (kosuu<2) return;
	int tmp[8];
	int i;

	for (i=0;i<kosuu;i++)
	{
		tmp[i] = m_game->GetVarData(m_kumiawaseVarNumber[i]);
	}

	//shuffle main
	int kaisuu = kosuu + (rand() % 2);
	for (i=0;i<kaisuu;i++)
	{
		int n1 = (i % kosuu);
		int n2 = n1 + (rand() % (kosuu-1)) + 1;
		n2 %= kosuu;

		int d = tmp[n1];
		tmp[n1] = tmp[n2];
		tmp[n2] = d;
	}


	for (i=0;i<kosuu;i++)
	{
		m_game->SetVarData(m_kumiawaseVarNumber[i],tmp[i]);
	}

}
*/





void CKumiawase::BookOpen(void)
{
	m_bookOpenFlag = TRUE;
	m_bookAnime = 0;
	m_bookAnimeCount = 0;
}

void CKumiawase::BookClose(void)
{
	m_bookOpenFlag = FALSE;
	m_bookAnime = 0;
	m_bookAnimeCount = 0;
}


void CKumiawase::CheckBookOpen(int mouseX, int mouseY)
{
	if (m_bookOpenFlag)
	{
		//check close
		if (CheckOnOpenBook(mouseX, mouseY) == FALSE)
		{
			BookClose();
		}
	}
	else
	{
		//check open
		if (CheckOnCloseBook(mouseX, mouseY))
		{
			BookOpen();
		}
	}
}


BOOL CKumiawase::CheckOnOpenBook(int x, int y)
{
	if ((x >= 675) && (x <= 799) && (y >= 503) && (y <= 599)) return TRUE;
	return FALSE;
}

BOOL CKumiawase::CheckOnCloseBook(int x, int y)
{
	if ((x >= 721) && (x <= 799) && (y >= 503) && (y <= 599)) return TRUE;
	return FALSE;
}


void CKumiawase::BookAnime(void)
{
	if (m_bookOpenFlag == FALSE)
	{
		if (m_bookAnime == 0)
		{
			m_bookAnimeCount++;
			if (m_bookAnimeCount >= 3 * 2)
			{
				m_bookAnime = 1;
			}
		}
	}
	else
	{
		if (m_bookAnime == 0)
		{
			m_bookAnimeCount++;
			if (m_bookAnimeCount >= 3 * 2)
			{
				m_bookAnime = 1;
			}
		}
		else
		{
			m_bookAnimeCount++;
			m_bookAnimeCount %= (5 * 2);
		}
	}
}


BOOL CKumiawase::CheckChangeGaze(void)
{
	for (int i = 0; i < 12; i++)
	{
		if (m_mainDaraku[i] != m_mainDarakuMae[i]) return TRUE;
	}

	return FALSE;
}











////////////////////////////////////

POINT CKumiawase::GetCardBaseZahyo(int n)
{
	POINT pt;
	pt.x = 0;
	pt.y = 0;

	if ((n >= 1) && (n <= 7))
	{
		pt.x = m_cardPrintZahyoTable[(n - 1) * 2];
		pt.y = m_cardPrintZahyoTable[(n - 1) * 2 + 1];
	}

	return pt;
}


POINT CKumiawase::GetUpperCaedDelta(void)
{
	POINT pt;

	pt.x = m_upperCardPrintDeltaX;
	pt.y = m_upperCardPrintDeltaY;

	return pt;
}


int CKumiawase::GetKageType(int n, int k)
{
	if ((n == 4) || (n == 5) || (n == 7))
	{
		if (k == 0) return 1;
		return 4;
	}
	else if ((n == 1) || (n == 3) || (n == 6))
	{
		if (k == 0) return 2;
		return 5;
	}
	else
	{
		if (k == 0) return 3;
	}

	return 0;
}




POINT CKumiawase::GetKageDelta(int type)
{
	POINT pt;
	pt.x = 0;
	pt.y = 0;

	if (type == 1)	//right
	{
		pt.x = 204 - 96;
		pt.y = 232 - 222;
	}
	else if (type == 2)	//left
	{
		pt.x = 591 - 601;
		pt.y = 232 - 222;
	}
	else if (type == 3)	//bottom
	{
		pt.x = 349 - 349;
		pt.y = 377 - 222;
	}
	else if (type == 4)	//bottom right
	{
		pt.x = 106 - 96;
		pt.y = 377 - 222;
	}
	else if (type == 5)	//bottom left
	{
		pt.x = 591 - 601;
		pt.y = 377 - 222;
	}

	return pt;
}


SIZE CKumiawase::GetCardSize(void)
{
	SIZE sz;

	sz.cx = m_cardSizeX;
	sz.cy = m_cardSizeY;

	return sz;
}


SIZE CKumiawase::GetKageSize(int type)
{
	SIZE sz;
	sz.cx = 0;
	sz.cy = 0;

	if ((type == 1) || (type == 2))
	{
		sz.cx = 10;
		sz.cy = 155;
	}
	else if (type == 3)
	{
		sz.cx = 108;
		sz.cy = 10;
	}
	else if ((type == 4) || (type == 5))
	{
		sz.cx = 108;
		sz.cy = 10;
	}
	return sz;
}




int CKumiawase::GetSemePoint(int from, int to)
{
	int varNumber = m_semePointVarNumber[from][to];
	if (varNumber == -1) return 0;	//error!!!

	return m_game->GetVarData(varNumber);
}



int CKumiawase::GetNeedPoint(int from, int to)
{
	if (m_mode != 0) return 0;

	int pt = GetSemePoint(from, to);

	int d = (pt - 1) / 11;
	d += 1;

	if (d < 1) d = 1;
	if (d > 9) d = 9;
	d = 10 - d;

	return d;
}

BOOL CKumiawase::CheckKasaneOkByPoint(int from, int to)
{
	int pt = GetNeedPoint(from, to);

	if (pt > m_power) return FALSE;

	return TRUE;
}


BOOL CKumiawase::CheckKasaneOkByFlag(int from, int to)
{
	int varNumber;

	if (m_mode == 0)
	{
		int varNumber = m_kasaneOkVarNumber[from][to];
		if (varNumber == -1) return FALSE;
		if (GetVarData(varNumber) == 0) return FALSE;
	}


	if ((m_mode == 0) || (m_mode == 1))
	{
		varNumber = m_semeFukaVarNumber[from];					//用心のため
		if (varNumber == -1) return FALSE;
		if (GetVarData(varNumber) != 0) return FALSE;

		varNumber = m_ukeFukaVarNumber[to];
		if (varNumber == -1) return FALSE;
		if (GetVarData(varNumber) != 0) return FALSE;
	}

	if (m_mode == 1)
	{
		//		varNumber = m_ryojokuTaishoVarNumber[to];
		//		if (varNumber == -1) return FALSE;
		//		if (GetVarData(varNumber) == 0) return FALSE;


		int varNumber1 = m_ryojokugawaFlagVarNumber[from];
		BOOL b1 = (BOOL)(GetVarData(varNumber1));

		int varNumber2 = m_ryojokugawaFlagVarNumber[to];
		BOOL b2 = (BOOL)(GetVarData(varNumber2));

		int varNumber3 = m_ryojokuTaishoVarNumber[from];
		BOOL b3 = (BOOL)(GetVarData(varNumber3));

		int varNumber4 = m_ryojokuTaishoVarNumber[to];
		BOOL b4 = (BOOL)(GetVarData(varNumber4));


		if ((b1 == FALSE) && (b3 == FALSE)) return FALSE;
		if ((b2 == FALSE) && (b4 == FALSE)) return FALSE;

		if (b1 && b2) return FALSE;
		if (b3 && b4) return FALSE;


		////		if ((b1 == FALSE) && (b2 == FALSE)) return FALSE;
	}

	if (m_mode == 2)
	{
		if (CheckEndingKasaneOk(from, to) == FALSE) return FALSE;

		//		varNumber = m_endingKasaneOkVarNumber[from][to];
		//		if (varNumber == -1) return FALSE;
		//		if (GetVarData(varNumber) == 0) return FALSE;
	}

	return TRUE;
}


void CKumiawase::PutCardOnly(int n, int type, POINT pt, int col)
{
	PutCardOnly(n, type, pt.x, pt.y, col);
}

void CKumiawase::PutCardOnly(int n, int type, int x, int y, int col)
{
	n -= 1;
	if (n < 0) return;	//
//	type -= 1;
//	if (type >= 2) type -= 1;

	CPicture* lpPic = m_cardPic[n][type];
	if (lpPic == NULL) return;

	SIZE sz = GetCardSize();
	int sizeX = sz.cx;
	int sizeY = sz.cy;

	if (col == CARDCOLOR_NORMAL)
	{
		lpPic->Blt(x, y, 0, 0, sizeX, sizeY, TRUE);
	}
	else if (col == CARDCOLOR_GREY)
	{
		lpPic->GreyBlt(x, y, 0, 0, sizeX, sizeY, TRUE);
	}
	else if (col == CARDCOLOR_RED)
	{
		lpPic->RedBlt(x, y, 0, 0, sizeX, sizeY, TRUE);
	}
	else if (col == CARDCOLOR_LIGHT)
	{
		lpPic->ColorAddBlt(x, y, 0, 0, sizeX, sizeY, TRUE, m_lighting, m_lighting, m_lighting);
	}
	else if (col == CARDCOLOR_DARK)
	{
		lpPic->ColorAddBlt(x, y, 0, 0, sizeX, sizeY, TRUE, -64, -64, -64);
		//		lpPic->DarkBlt(x,y,0,0,sizeX,sizeY,TRUE);
	}
	else if (col == CARDCOLOR_TRANS)
	{
		lpPic->TransLucentBlt2(x, y, 0, 0, sizeX, sizeY, 50);
	}
	else if (col == CARDCOLOR_TRANS2)
	{
		lpPic->TransLucentBlt2(x, y, 0, 0, sizeX, sizeY, 30);
	}
	else if (col == CARDCOLOR_LIGHT2)
	{
		lpPic->ColorAddBlt(x, y, 0, 0, sizeX, sizeY, TRUE, m_lighting2, m_lighting2, m_lighting2);
	}
}

void CKumiawase::PutCardKage(int place)
{
	POINT pt = GetCardBaseZahyo(place);

	for (int i = 0; i < 2; i++)
	{
		int type = GetKageType(place, i);
		if (type != 0)
		{
			POINT pt2 = GetKageDelta(type);
			int putX = pt.x + pt2.x;
			int putY = pt.y + pt2.y;

			SIZE sz = GetKageSize(type);

			m_kagePic[type - 1]->Blt(putX, putY, 0, 0, sz.cx, sz.cy, TRUE);
		}
	}
}


POINT CKumiawase::GetGazeWakuPrintDelta(void)
{
	POINT pt;

	pt.x = m_gazeWakuPrintDeltaX;
	pt.y = m_gazeWakuPrintDeltaY;

	return pt;
}


SIZE CKumiawase::GetGazeWakuSize(void)
{
	SIZE sz;

	sz.cx = m_gazeWakuSizeX;
	sz.cy = m_gazeWakuSizeY;

	return sz;
}

POINT CKumiawase::GetGazeBarPrintDelta(void)
{
	POINT pt;

	pt.x = m_gazeBarPrintDeltaX;
	pt.y = m_gazeBarPrintDeltaY;

	return pt;
}

SIZE CKumiawase::GetGazeBarSize(void)
{
	SIZE sz;

	sz.cx = m_gazeBarSizeX;
	sz.cy = m_gazeBarSizeY;

	return sz;
}


void CKumiawase::PutGazeOnly(POINT cardPoint, int type, int gaze, int col)
{
	PutGazeOnly(cardPoint.x, cardPoint.y, type, gaze, col);
}

void CKumiawase::PutGazeOnly(int cardX, int cardY, int type, int gaze, int col)
{
	POINT pt0 = GetGazeWakuPrintDelta();

	int x = cardX + pt0.x;
	int y = cardY + pt0.y;

	if (type == GAZETYPE_NO)
	{
		SIZE sz = GetGazeWakuSize();

		m_karaGazePic->Blt(x, y, 0, 0, sz.cx, sz.cy, TRUE);
		return;
	}

	if ((type == GAZETYPE_SEME) || (type == GAZETYPE_UKE))
	{
		SIZE sz = GetGazeWakuSize();
		m_gazeWakuPic->Blt(x, y, 0, 0, sz.cx, sz.cy, TRUE);

		SIZE sz2 = GetGazeBarSize();
		POINT pt2 = GetGazeBarPrintDelta();


		if (gaze <= 1) gaze = 0;
		if (gaze >= 99) gaze = 100;
		int sizeX = (gaze * sz2.cx) / 100;
		int sizeY = sz2.cy;

		if (sizeX == 0) return;

		int putX = x + pt2.x;
		int putY = y + pt2.y;


		if (type == GAZETYPE_SEME)
		{
			m_semeGazeBarPic->Blt(putX, putY, 0, 0, sizeX, sizeY, FALSE);
		}
		else
		{
			int deltaX = sz2.cx - sizeX;
			putX += deltaX;
			m_ukeGazeBarPic->Blt(putX, putY, deltaX, 0, sizeX, sizeY, FALSE);
		}
	}
}


POINT CKumiawase::GetNeedPointPrintDelta(void)
{
	POINT pt;

	pt.x = m_needPointPrintDeltaX;
	pt.y = m_needPointPrintDeltaY;

	return pt;
}

SIZE CKumiawase::GetNeedPointSize(void)
{
	SIZE sz;

	sz.cx = m_needPointSizeX;
	sz.cy = m_needPointSizeY;

	return sz;
}




void CKumiawase::PutNeedPointOnly(int place, int point, int col)
{
	POINT pt = GetCardBaseZahyo(place);
	POINT pt0 = GetNeedPointPrintDelta();

	int x = pt.x + pt0.x;
	int y = pt.y + pt0.y;

	SIZE sz = GetNeedPointSize();

	int sizeX = sz.cx;
	int sizeY = sz.cy;

	for (int i = 0; i < point; i++)
	{
		int putX = x + (i % 5) * 16;
		int putY = y + (i / 5) * 16;
		int srcX = sizeX * (m_needPointAnime[place][i] / 100);
		int srcY = 0;
		m_needPointPic->Blt(putX, putY, srcX, srcY, sizeX, sizeY, TRUE);
	}
}


void CKumiawase::InitNeedPointAnime(void)
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			m_needPointAnime[j][i] = rand() % 400;
			m_needPointAnimeSpeed[j][i] = (rand() % 30) + 120;
		}
	}
}

void CKumiawase::CalcuNeedPointAnime(void)
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			m_needPointAnime[j][i] += m_needPointAnimeSpeed[j][i];
			if (m_needPointAnime[j][i] >= 400)
			{
				m_needPointAnime[j][i] %= 400;
				if ((rand() % 100) < 10)
				{
					m_needPointAnimeSpeed[j][i] = (rand() % 120) + 40;
				}
			}
		}
	}
}


void CKumiawase::PrintMonth(void)
{
	m_monthPic->Blt(5, 5, 0, 0, 33, 46, TRUE);
}


void CKumiawase::PrintDate(void)
{
	m_datePic->Blt(66, 67, 0, 0, 48, 54, TRUE);
}

void CKumiawase::PrintHour(void)
{
	if ((m_hour >= 2) && (m_hour <= 5))
	{
		POINT pt = GetHourPrintZahyo(m_hour);
		SIZE sz = GetHourSize(m_hour);
		m_hourPic->Blt(pt.x, pt.y, 0, 0, sz.cx, sz.cy, TRUE);
	}
}


POINT CKumiawase::GetHourPrintZahyo(int hour)
{
	POINT pt;

	pt.x = m_hourPrintZahyoTable[hour * 2];
	pt.y = m_hourPrintZahyoTable[hour * 2 + 1];

	return pt;
}


SIZE CKumiawase::GetHourSize(int hour)
{
	SIZE sz;
	sz.cx = 0;
	sz.cy = 0;

	if ((hour == 1) || (hour == 2) || (hour == 3))
	{
		sz.cx = 52;
		sz.cy = 52;
	}

	if (hour == 4)
	{
		sz.cx = 48;
		sz.cy = 54;
	}
	return sz;
}


BOOL CKumiawase::CheckOnOkArea(int mouseX, int mouseY)
{
	POINT pt = GetOkButtonZahyo();
	SIZE sz = GetOkButtonSize();

	int x = mouseX - pt.x;
	int y = mouseY - pt.y;

	if ((x < 0) || (x >= sz.cx) || (y < 0) || (y >= sz.cy)) return FALSE;

	//shape check?

	return TRUE;
}

POINT CKumiawase::GetOkButtonZahyo(void)
{
	POINT pt;

	pt.x = 700;
	pt.y = 480;

	return pt;
}


SIZE CKumiawase::GetOkButtonSize(void)
{
	SIZE sz;

	sz.cx = 100;
	sz.cy = 120;

	return sz;
}


void CKumiawase::PutOkButton(int type, int anime, int anime2, int ps, int col)
{
	if (anime2 == -1) anime2 = anime;

	CPicture* lpPic = m_okPic1;
	if (type == 1) lpPic = m_okPic2;

	POINT pt = GetOkButtonZahyo();
	SIZE sz = GetOkButtonSize();

	int putX = pt.x;
	int putY = pt.y;
	int sizeX = sz.cx;
	int sizeY = sz.cy;
	int srcX = anime * sizeX;
	int srcY = 0;

	int srcX2 = anime2 * sizeX;
	int srcY2 = 0;

	int ps1 = ps;
	int ps2 = 100 - ps1;


	if (col == OKCOLOR_NORMAL)
	{
		if (ps1 == 100)
		{
			lpPic->Blt(putX, putY, srcX, srcY, sizeX, sizeY, TRUE);
		}
		else if (ps1 > 0)
		{
			lpPic->TransLucentBlt2(putX, putY, srcX, srcY, sizeX, sizeY, ps1);
		}

		if (ps2 == 100)
		{
			lpPic->TransLucentBlt2(putX, putY, srcX, srcY, sizeX, sizeY, TRUE);
		}
		else if (ps2 > 0)
		{
			lpPic->TransLucentBlt2(putX, putY, srcX2, srcY2, sizeX, sizeY, ps2);
		}
	}
	else if (col == OKCOLOR_GREY)
	{
		lpPic->GreyBlt(putX, putY, srcX, srcY, sizeX, sizeY, TRUE);
	}
}


void CKumiawase::CalcuOkButtonAnime(void)
{

	int dvdv = m_choAnimeDiv;
	m_okButtonAnimeCount += 1;
	m_okButtonAnimeCount %= (6 * dvdv);

	m_okButtonAnimeAmari = m_okButtonAnimeCount % m_choAnimeDiv;
	int anime = m_okButtonAnimeCount / dvdv;
	int anime2 = anime + 1;
	anime2 %= 6;

	if (anime >= 4) anime = 6 - anime;
	if (anime2 >= 4) anime2 = 6 - anime2;

	m_okButtonAnime = anime;
	m_okButtonAnime2 = anime2;
}

void CKumiawase::SetVarData(int varNumber, int data)
{
	if ((varNumber < 0) || (varNumber >= 2200)) return;
	m_game->SetVarData(varNumber, data);
}

int CKumiawase::GetVarData(int varNumber)
{
	if ((varNumber < 0) || (varNumber >= 2200)) return 0;

	return m_game->GetVarData(varNumber);
}


//void CKumiawase::TaihiKumiawaseMode(int mode)
//{
	//m_mode = mode;
	//int varNumber = m_workVarNumber[0];
	//SetVarData(varNumber,mode);
//}


void CKumiawase::FuqueKumiawase(void)
{
	m_mode = GetVarData(m_workVarNumber[1]);

	for (int i = 0; i < 8; i++)
	{
		m_cardWork[i] = GetVarData(m_workVarNumber[2 + i]);
	}

	m_power = GetVarData(m_workVarNumber[10]);
}



void CKumiawase::TaihiKumiawase(void)
{
	SetVarData(m_workVarNumber[1], m_mode);

	for (int i = 0; i < 8; i++)
	{
		SetVarData(m_workVarNumber[2 + i], m_cardWork[i]);
	}

	SetVarData(m_workVarNumber[10], m_power);
}








/*
int CKumiawase::FuqueKumiawaseCharaFrom(int n)
{
	int varNumber = m_workVarNumber[n] + 2;
	int dt = GetVarData(varNumber);
	return (dt >> 24) & 0xff;
}

int CKumiawase::FuqueKumiawaseCharaTo(int n)
{
	int varNumber = m_workVarNumber[n] + 2;
	int dt = GetVarData(varNumber);
	return (dt >> 16) & 0xff;
}

int CKumiawase::FuqueKumiawasePointFrom(int n)
{
	int varNumber = m_workVarNumber[n] + 2;
	int dt = GetVarData(varNumber);
	return (dt >> 8) & 0xff;
}

int CKumiawase::FuqueKumiawasePointTo(int n)
{
	int varNumber = m_workVarNumber[n] + 2;
	int dt = GetVarData(varNumber);
	return (dt)  & 0xff;
}
*/


/*
void CKumiawase::TaihiKumiawase(int n, int from, int to, int fromPoint, int toPoint)
{
	int dt = (from << 24) | (to << 16) | (fromPoint << 8) | toPoint;
	int varNumber = m_workVarNumber[n] + 2;
	SetVarData(varNumber,dt);
}
*/

int CKumiawase::FuqueKumiawaseKosuu(void)
{
	int varNumber = m_workVarNumber[5];
	if (varNumber <= 0) return 0;

	int dt = GetVarData(varNumber);
	m_kumiawaseKosuu = dt;

	return m_kumiawaseKosuu;
}


void CKumiawase::TaihiKumiawaseKosuu(int kosuu)
{
	int varNumber = m_workVarNumber[5];
	SetVarData(varNumber, kosuu);
}



BOOL CKumiawase::CheckExistChara(int n)
{
	if ((n < 1) || (n > 7)) return FALSE;

	int varNumber = m_charaAppearVarNumber[n];
	if (varNumber <= 0) return FALSE;

	if (m_game->GetVarData(varNumber) != 0) return TRUE;

	return FALSE;
}


BOOL CKumiawase::CheckAiseru(int from, int to)
{
	if ((from < 1) || (from > 7)) return FALSE;
	if ((to < 1) || (to > 7)) return FALSE;

	int varNumber = m_kasaneOkVarNumber[from][to];
	if (varNumber <= 0) return FALSE;

	if (m_game->GetVarData(varNumber) != 0) return TRUE;

	return FALSE;
}


BOOL CKumiawase::CheckRyojokuFlag(int n)
{
	if ((n < 1) || (n > 7)) return FALSE;

	int varNumber = m_charaRyojokuFlagVarNumber[n];
	if (varNumber <= 0) return FALSE;

	if (m_game->GetVarData(varNumber) != 0) return TRUE;

	return FALSE;
}


BOOL CKumiawase::CheckSemeOk(int from)
{
	if ((from < 1) || (from > 7)) return FALSE;

	int varNumber = m_semeFukaVarNumber[from];
	if (varNumber <= 0) return FALSE;

	if (m_mode != 2)
	{
		if (m_game->GetVarData(varNumber) != 0) return FALSE;
	}

	return TRUE;
}


BOOL CKumiawase::CheckUkeOk(int to)
{
	if ((to < 1) || (to > 7)) return FALSE;

	int varNumber = m_ukeFukaVarNumber[to];
	if (varNumber <= 0) return FALSE;

	if (m_mode != 2)
	{
		if (m_game->GetVarData(varNumber) != 0) return FALSE;
	}

	return TRUE;
}


BOOL CKumiawase::CheckRyojokuTaisho(int to)
{
	if ((to < 1) || (to > 7)) return FALSE;

	int varNumber = m_ryojokuTaishoVarNumber[to];
	if (varNumber <= 0) return FALSE;

	if (m_game->GetVarData(varNumber) != 0) return TRUE;

	return FALSE;
}


BOOL CKumiawase::CheckRyojokugawa(int from)
{
	if ((from < 1) || (from > 7)) return FALSE;

	int varNumber = m_ryojokugawaFlagVarNumber[from];
	if (varNumber <= 0) return FALSE;

	if (m_game->GetVarData(varNumber) == 0) return FALSE;

	return TRUE;
}



BOOL CKumiawase::CheckEndingCatchOk(int from)
{
	if ((from < 1) || (from > 7)) return FALSE;
	for (int to = 1; to <= 7; to++)
	{
		if (from != to)
		{
			if (CheckEndingKasaneOk(from, to))  return TRUE;
		}
	}

	return FALSE;
}



BOOL CKumiawase::CheckEndingKasaneOk(int from, int to)
{
	if ((from < 1) || (from > 7)) return FALSE;
	if ((to < 1) || (to > 7)) return FALSE;

	int varNumber = m_endingKasaneOkVarNumber[from][to];
	if (varNumber <= 0) return FALSE;

	if (m_game->GetVarData(varNumber) != 0) return TRUE;

	return FALSE;
}


BOOL CKumiawase::CheckCatchOk(int place, BOOL upperFlag)
{
	if (m_catchCard != -1) return FALSE;
	if (CheckExistCard(place, upperFlag) == FALSE) return FALSE;


	int card = GetCardNumber(place, upperFlag);
	if (card == -1) return FALSE;

	if (CheckExistChara(card) == FALSE) return FALSE;

	if (upperFlag == FALSE)
	{
		if ((m_mode == 0) || (m_mode == 1))
		{
			int card2 = GetCardNumber(place, TRUE);
			if (card2 > 0) return FALSE;

			if (CheckSemeOk(card) == FALSE) return FALSE;

			if (m_mode == 1)
			{
				if ((CheckRyojokugawa(card) == FALSE) && (CheckRyojokuTaisho(card) == FALSE)) return FALSE;
			}

			return TRUE;
		}


		if (m_mode == 2)
		{
			if (CheckEndingCatchOk(card) == FALSE) return FALSE;

			return TRUE;
		}
	}
	else
	{
		return TRUE;
	}

	return FALSE;
}



int CKumiawase::GetCardNumber(int place, BOOL upperFlag)
{
	if ((place >= 1) && (place <= 7))
	{
		if (upperFlag == FALSE)
		{
			return (m_cardWork[place] >> 16) & 0xff;
		}
		else
		{
			return (m_cardWork[place] >> 24) & 0xff;
		}
	}

	return 0;
}


BOOL CKumiawase::CheckExistCard(int place, BOOL upperFlag)
{
	if ((place >= 1) && (place <= 7))
	{
		int card = GetCardNumber(place, upperFlag);
		if (card > 0) return TRUE;
	}

	return FALSE;
}


int CKumiawase::GetFromCard(int place)
{
	int card = (m_cardWork[place] >> 24) & 0xff;
	return card;
}

int CKumiawase::GetToCard(int place)
{
	int card = (m_cardWork[place] >> 16) & 0xff;
	return card;
}

int CKumiawase::GetFromOldPoint(int place)
{
	int point = (m_cardWork[place] >> 8) & 0xff;
	return point;
}

int CKumiawase::GetToOldPoint(int place)
{
	int point = (m_cardWork[place]) & 0xff;
	return point;
}




BOOL CKumiawase::CheckOnPlace(int place, BOOL upperFlag, int mouseX, int mouseY)
{
	POINT pt = GetCardBaseZahyo(place);
	SIZE sz = GetCardSize();
	if (upperFlag)
	{
		POINT pt2 = GetUpperCaedDelta();
		pt.x += pt2.x;
		pt.y += pt2.y;
	}

	int x = mouseX - pt.x;
	int y = mouseY - pt.y;

	if ((x >= 0) && (x < sz.cx) && (y >= 0) && (y < sz.cy)) return TRUE;

	return FALSE;
}


void CKumiawase::EraseCardWork(int place, BOOL upperFlag)
{
	int d = m_cardWork[place];
	if (upperFlag)
	{
		d &= 0x00ffffff;
	}
	else
	{
		d &= 0x0ff00ffff;
	}

	m_cardWork[place] = d;
}


void CKumiawase::ReCalcuCardOkWork(void)
{
}


int CKumiawase::GetOnPlace(int mouseX, int mouseY, BOOL upperFlag)
{
	for (int i = 1; i <= 7; i++)
	{
		if (CheckOnPlace(i, upperFlag, mouseX, mouseY)) return i;
	}

	return FALSE;

}


void CKumiawase::SetCardToWork(int place, int card, BOOL upperFlag)
{
	int d = m_cardWork[place];
	if (upperFlag)
	{
		d &= 0x00ffffff;
		d |= (card << 24);
	}
	else
	{
		d &= 0x0ff00ffff;
		d |= (card << 16);
	}

	m_cardWork[place] = d;
}


void CKumiawase::SetOldPointToWork(int place, int point, BOOL upperFlag)
{
	int d = m_cardWork[place];
	if (upperFlag)
	{
		d &= 0x0ffff00ff;
		d |= (point << 8);
	}
	else
	{
		d &= 0x0ffffff00;
		d |= (point);
	}

	m_cardWork[place] = d;
}





BOOL CKumiawase::CheckOnOk(int x, int y)
{
	POINT pt = GetOkButtonZahyo();
	SIZE sz = GetOkButtonSize();

	int sizeX = sz.cx;
	int sizeY = sz.cy;
	int checkX = pt.x;
	int checkY = pt.y;


	x -= checkX;
	y -= checkY;

	if ((x >= 0) && (x < sizeX) && (y >= 0) && (y < sizeY))
	{
		return TRUE;
	}
	return FALSE;
}


void CKumiawase::PutCard(int n, int type, POINT pt, int md)
{
	PutCardOnly(n, type, pt, md);

}


BOOL CKumiawase::CheckCatchCard(int place, BOOL upperFlag)
{
	int card = GetCardNumber(place);
	if (card < 1) return FALSE;

	if (upperFlag == FALSE)
	{
		//攻め不可チェック
		if ((m_mode == 0) || (m_mode == 1))
		{
			if (CheckSemeOk(card) == FALSE) return FALSE;
		}

		return TRUE;
	}

	int card2 = GetCardNumber(place, TRUE);
	if (card2 < 1) return FALSE;

	return TRUE;
}


void CKumiawase::RestoreSemePoint(int place)
{
	int oldSemePoint = GetFromOldPoint(place);
	int oldUkePoint = GetToOldPoint(place);

	SetOldPointToWork(place, oldSemePoint, TRUE);
	SetOldPointToWork(place, oldUkePoint);

	int fromCard = GetCardNumber(place, TRUE);
	int toCard = GetCardNumber(place);

	SetSemePoint(fromCard, toCard, oldSemePoint);
}

void CKumiawase::ChangeSemePoint(int place)
{
	if (m_mode == 2) return;

	int fromCard = GetCardNumber(place, TRUE);
	int toCard = GetCardNumber(place);

	int semePoint = GetSemePoint(fromCard, toCard);
	int ukePoint = GetSemePoint(toCard, fromCard);

	SetOldPointToWork(place, semePoint, TRUE);
	SetOldPointToWork(place, ukePoint);

	if (semePoint < 99)
	{
		semePoint += m_deltaSemePoint;
		ukePoint -= m_deltaSemePoint;
		if (semePoint > 99) semePoint = 99;
		if (ukePoint < 1) ukePoint = 1;

		SetSemePoint(fromCard, toCard, semePoint);
	}
}


void CKumiawase::SetSemePoint(int fromCard, int toCard, int fromPoint, int toPoint)
{
	if (toPoint == -1) toPoint = 100 - fromPoint;


	int varNumber = m_semePointVarNumber[fromCard][toCard];
	SetVarData(varNumber, fromPoint);

	int varNumber2 = m_semePointVarNumber[toCard][fromCard];
	SetVarData(varNumber2, toPoint);
}


BOOL CKumiawase::CheckHaveKumiawase(void)
{
	for (int i = 1; i <= 7; i++)
	{
		if (CheckExistCard(i))
		{
			if (CheckExistCard(i, TRUE)) return TRUE;
		}
	}

	return FALSE;
}



void CKumiawase::SetNewHana(int n)
{
	if ((rand() % 100) < 50)
	{
		m_hanaZahyo[n].x = (rand() % 100000);
		m_hanaZahyo[n].y = -10000 + (rand() % 10000);
	}
	else
	{
		m_hanaZahyo[n].x = 80000 + (rand() % 5000);
		m_hanaZahyo[n].y = -20000 + (rand() % 40000) * 2;
	}

	m_hanaSpeedX[n] = -((rand() % 2000) + 500);
	m_hanaSpeedY[n] = ((rand() % 1000) + 300);
	m_hanaCount[n] = (rand() % 20) + 5;
}


void CKumiawase::CalcuHana(void)
{
	if (m_catchCard == -1)
	{
		m_hanaPercent++;
		if (m_hanaPercent > 70) m_hanaPercent = 70;
		m_hanaSpeed += 10;
		if (m_hanaSpeed > 100) m_hanaSpeed = 100;
	}
	else
	{
		m_hanaPercent--;
		if (m_hanaPercent < 30) m_hanaPercent = 30;
		m_hanaSpeed -= 3;
		if (m_hanaSpeed < -25) m_hanaSpeed = -25;
	}

	for (int i = 0; i < m_hanaKosuu; i++)
	{
		m_hanaCount[i]--;
		if (m_hanaCount <= 0)
		{
			//change speed
			m_hanaCount[i] = (rand() % 20) + 5;

			int speedX = m_hanaSpeedX[i];
			int speedY = m_hanaSpeedY[i];
			speedX += (rand() % 500);
			speedX -= 200;
			speedY += (rand() % 300);
			speedY -= 100;

			if (speedX > -500) speedX = -500;
			if (speedX < -2500) speedX = -2500;

			if (speedY < 300) speedY = 300;
			if (speedY > 1300) speedY = 1300;

			m_hanaSpeedX[i] = speedX;
			m_hanaSpeedY[i] = speedY;
		}


		int x = m_hanaZahyo[i].x;
		int y = m_hanaZahyo[i].y;


		if (m_hanaSpeed == 100)
		{
			x += m_hanaSpeedX[i];
			y += m_hanaSpeedY[i];
		}
		else
		{
			x += (m_hanaSpeedX[i] * m_hanaSpeed) / 100;
			y += m_hanaSpeedY[i];
		}

		//		if (m_catchCard == -1)
		//		{
		//			x += m_hanaSpeedX[i];
		//			y += m_hanaSpeedY[i];
		//		}
		//		else
		//		{
		//			x -= m_hanaSpeedX[i] / 2;
		//			y += m_hanaSpeedY[i]    ;
		//		}

		m_hanaZahyo[i].x = x;
		m_hanaZahyo[i].y = y;

		if ((x < -3200) || (x > 100000) || (y > 60000))
		{
			SetNewHana(i);
		}
	}
}


void CKumiawase::PrintHana(void)
{
	int sizeX = 16;
	int sizeY = 16;

	int ps = 70;
	if (m_catchCard != -1) ps = 30;

	ps = m_hanaPercent;

	for (int i = 0; i < m_hanaKosuu; i++)
	{
		int x = m_hanaZahyo[i].x / 100;
		int y = m_hanaZahyo[i].y / 100;
		if ((x >= -32) && (x < 800) && (y >= -32) && (y < 600))
		{
			int srcX = sizeX * (i & 3);
			m_petalPic->TransLucentBlt2(x, y, srcX, 0, sizeX, sizeY, ps);
		}
	}
}


void CKumiawase::ReCreateExitScreen(void)
{
	Print();
}

/*_*/


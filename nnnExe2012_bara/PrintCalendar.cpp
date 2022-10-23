//
// printcalendar.cpp
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
#include "printCalendar.h"



int CPrintCalendar::m_countTable[] = { 20,25,10 };

char CPrintCalendar::m_haikeiFileName[][64] =
{
	"sys\\ÉJÉåÉìÉ_Å[îwåi",
	"sys\\ëgÇ›çáÇÌÇπï\é¶îwåi",
	"sys\\ì¡ï ÉCÉxÉìÉgîwåi",
};

int CPrintCalendar::m_hourPrintZahyoTable[] =
{
	0,0,
	0,0,	127,33,	133,92,	90,133,	31,125,

};

char CPrintCalendar::m_hourName[][8] =
{
	"","ëÅí©","í©","íã","ó[","ñÈ"
};



CPrintCalendar::CPrintCalendar(CGameCallBack* lpGame) : CCommonGeneral(lpGame)
{
	SetClassNumber(BARA_PRINTCALENDAR_MODE);
	//	m_classNumber = TITLE_MODE;
	LoadSetupFile("printcalendar", 64);

//	m_basicButtonKosuu = 5;
//	GetInitGameParam(&m_basicButtonKosuu, "basicButtonNumber");
//	m_menuButtonSetup = new CMenuButtonSetup(m_setup, m_basicButtonKosuu);

	GetBackExecSetup();
	GetAllPrintSetup();

	m_message = new CMyMessage(m_game->GetMyFont());
	m_game2 = dynamic_cast<CGame*>(lpGame);

	GetInitGameString(&m_filenameBG, "filenameBG");

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


	//	m_subMode = 0;
	m_count = 1;

	m_haikeiVarNumber = m_game->GetVarNumber("îwåiî‘çÜ");
	m_cuppleVarNumber = m_game->GetVarNumber("ÉJÉbÉvÉäÉìÉOè–âÓî‘çÜ");
	m_hourVarNumber = m_game->GetVarNumber("éûä‘ë—");

}


CPrintCalendar::~CPrintCalendar()
{
	End();
}


void CPrintCalendar::End(void)
{
	ENDDELETECLASS(m_message);
}

int CPrintCalendar::Init(void)
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




	///////////////////////
	m_subMode = 0;
	m_count = m_countTable[m_subMode];


	int haikei = m_game->GetVarData(m_haikeiVarNumber);



	if ((haikei >= 0) && (haikei <= 2))
	{
		m_commonBG->LoadDWQ(m_haikeiFileName[haikei]);
	}
	else
	{
		CAllGraphics::FillScreen(0, 0, 0);
//		CPicture::FillScreen(0, 0, 0);
		m_commonBG->ReSize(800, 600);
	}

	m_commonBG->Blt(0, 0, 0, 0, 800, 600, FALSE);

	if ((haikei == 1) || (haikei == 2))
	{
		int cp = m_game->GetVarData(m_cuppleVarNumber);

		if ((cp == 12) || (cp == 21)) cp = 0;			//ì¡ó·èàóù

		int left = cp / 10;
		int right = cp % 10;


		char filename[256];

		if (left > 0)
		{
			LPSTR charaName = m_game2->GetCharaName(left);
			if (charaName != NULL)
			{
				sprintf_s(filename, 256,"sys\\ta%sïÅí ë“", charaName);
				m_commonParts->LoadDWQ(filename);
				m_commonParts->Blt(400 - 100 - 108, 300 - 155 / 2, 0, 0, 108, 155, TRUE);
			}
		}

		if (right > 0)
		{
			LPSTR charaName = m_game2->GetCharaName(right);
			if (charaName != NULL)
			{
				sprintf_s(filename, 256,"sys\\ta%sïÅí ë“", charaName);
				m_commonParts->LoadDWQ(filename);
				m_commonParts->Blt(400 + 100, 300 - 155 / 2, 0, 0, 108, 155, TRUE);
			}
		}
	}


	int daymonth = m_game2->GetDayMonth();
	int month = daymonth / 100;
	int date = daymonth % 100;

	int hour = m_game2->GetVarData(m_hourVarNumber);



	char filename[256];

	LPSTR suujiMes = m_game2->NumberToKanji(month);
	sprintf_s(filename, 256,"sys\\ta%såé", suujiMes);
	if ((month >= 5) && (month <= 7))
	{
		m_commonParts->LoadDWQ(filename);
		m_commonParts->Blt(5, 5, 0, 0, 33, 46, TRUE);

		//	suujiMes = m_game->NumberToKanji(m_date);
		sprintf_s(filename, 256,"sys\\ta%d", date);
		m_commonParts->LoadDWQ(filename);
		m_commonParts->Blt(66, 67, 0, 0, 48, 54, TRUE);

	}


	if ((hour >= 2) && (hour <= 5))
	{
		sprintf_s(filename, 256,"sys\\ta%s", m_hourName[hour]);
		m_commonParts->LoadDWQ(filename);

		POINT pt = GetHourPrintZahyo(hour);
		SIZE sz = GetHourSize(hour);
		m_commonParts->Blt(pt.x, pt.y, 0, 0, sz.cx, sz.cy, TRUE);

	}

	m_commonBG->GetScreen(0, 0, 800, 600);

//	m_game->StopVoice();

	return -1;
}


int CPrintCalendar::Calcu(void)
{

	if (CheckClick())
	{
		m_subMode = 2;
		m_count = 1;
	}

	if (m_game->CheckMessageSkipFlag())
	{
		m_count = 1;
	}

	m_count--;
	if (m_count <= 0)
	{
		CAreaControl::SetNextAllPrint();
		if (m_subMode >= 2)
		{
			m_game->SetYoyaku();
			return -1;
		}
		m_subMode++;
		m_count = m_countTable[m_subMode];
	}
	return -1;

	return -1;
}


int CPrintCalendar::Print(void)
{
	PrintBackScriptOrBG();
	CAreaControl::SetNextAllPrint();

	CAllGraphics::FillScreen();
//	BOOL b = CAreaControl::CheckAllPrintMode();

	m_message->PrintMessage(300, 300, "ÉJÉåÉìÉ_Å[ï\é¶");


	////
	if ((m_subMode == 0) || (m_subMode == 2))
	{
		CAreaControl::SetNextAllPrint();
	}


	BOOL b = CAreaControl::CheckAllPrintMode();

	if (b == FALSE) return -1;

	int ps = 100;

	if (m_subMode == 0)
	{
		int dv = m_countTable[0];
		if (dv < 1) dv = 1;
		ps = ((dv - m_count) * 100) / dv;
		//		CAreaControl::SetNextAllPrint();
	}

	if (m_subMode == 2)
	{
		int dv = m_countTable[m_subMode];
		if (dv < 1) dv = 1;
		ps = (m_count * 100) / dv;
		//		CAreaControl::SetNextAllPrint();
	}

	if (ps < 0) ps = 0;
	if (ps > 100) ps = 100;


	if (ps == 0)
	{
//		CPicture::FillScreen(0, 0, 0);
		CAllGraphics::FillScreen(0, 0, 0);

		CAreaControl::SetNextAllPrint();
		return -1;
	}

	if (ps == 100)
	{
		m_commonBG->Blt(0, 0, 0, 0, 800, 600, FALSE);
		return -1;
	}

//	CPicture::FillScreen(0, 0, 0);
	CAllGraphics::FillScreen(0, 0, 0);

	m_commonBG->TransLucentBlt(0, 0, 0, 0, 800, 600, ps);

	return -1;

	return -1;
}


POINT CPrintCalendar::GetHourPrintZahyo(int hour)
{
	POINT pt;

	pt.x = m_hourPrintZahyoTable[hour * 2];
	pt.y = m_hourPrintZahyoTable[hour * 2 + 1];

	return pt;
}


SIZE CPrintCalendar::GetHourSize(int hour)
{
	SIZE sz;
	sz.cx = 0;
	sz.cy = 0;

	if ((hour == 2) || (hour == 3) || (hour == 4))
	{
		sz.cx = 52;
		sz.cy = 52;
	}

	if (hour == 5)
	{
		sz.cx = 48;
		sz.cy = 54;
	}
	return sz;
}

/*_*/


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

#include "..\..\SystemNNN\nnnUtilLib\cgDataControl.h"

#include "..\..\SystemNNN\nnnLib\gameCallBack.h"

#include "..\..\SystemNNN\nnnLib\commonGeneral.h"
#include "mode.h"
#include "game.h"
#include "title.h"


CTitle::CTitle(CGame* lpGame) : CCommonTitle(lpGame)
{
	m_game2 = lpGame;
	m_message = m_game2->GetMyMessage();

	m_miniGameOkFlag = false;
}

CTitle::~CTitle()
{

}

void CTitle::End(void)
{
	CCommonTitle::End();
}

int CTitle::Init(void)
{
	int rt = CCommonTitle::Init();

	m_miniGameOkFlag = CheckMiniGameOk();

	return rt;
}
int CTitle::Calcu(void)
{
	int rt = CCommonTitle::Calcu();

	POINT pt = m_game->GetMouseStatus()->GetZahyo();

	int mouseType = 0;
	if (CheckOnMiniGameAreaAll(pt.x,pt.y))
	{

		if (m_miniGameOkFlag)
		{
			mouseType = 1;
		}
	}
	m_game->SetSpecialMouseType(mouseType);



	return rt;
}
int CTitle::Print(void)
{
	int rt = CCommonTitle::Print();

	//m_message->PrintMessage(300, 300, "BARA TITLE");


	return rt;
}


void CTitle::ReCreateExitScreen(void)
{
	CCommonTitle::ReCreateExitScreen();
}


BOOL CTitle::CheckOnMiniGameAreaAll(int x, int y)
{
	if (CheckOnMiniGameArea(x, y, 0)) return TRUE;
	if (CheckOnMiniGameArea(x, y, 1)) return TRUE;
	if (CheckOnMiniGameArea(x, y, 2)) return TRUE;

	return FALSE;
}

BOOL CTitle::CheckOnMiniGameArea(int x, int y, int area)
{
	int sizeX = 10;
	int sizeY = 10;

	if (area == 0)
	{
		x -= (441 - 5);
		y -= (437 - 23);
		sizeX = 24;
		sizeY = 24;
	}
	else if (area == 1)
	{
		x -= 326;
		y -= 272;
		sizeX = 26;
		sizeY = 8;
	}
	else
	{
		x -= 526;
		y -= 233;
		sizeX = 14;
		sizeY = 20;
	}

	if ((x >= 0) && (y >= 0) && (x < sizeX) && (y < sizeY)) return TRUE;

	return FALSE;
}

BOOL CTitle::CheckMiniGameOk(void)
{
	CCGDataControl* cgDataControl = m_game->GetCGDataControl();

	for (int j = 0; j < 7; j++)
	{
		int kosuu = cgDataControl->GetCGKosuu(j);

		BOOL b = FALSE;

		for (int i = 0; i < kosuu; i++)
		{
			if (cgDataControl->CheckGetCG(j, i))
			{
				b = TRUE;
				break;
			}
		}

		if (b == FALSE) return FALSE;
	}

	return TRUE;
}

/*_*/

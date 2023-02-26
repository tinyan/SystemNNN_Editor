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
#include "SelectSceneChara.h"


int CSelectSceneChara::m_placeToKumiTable[7][6] =
{
	{-1,1,2,3,4,5},
	{1,-1,6,7,8,9},
	{2,6,-1,10,11,12},
	{3,7,10,-1,13,14},
	{4,8,11,13,-1,15},
	{5,9,12,14,15,-1},
	{0,-1,-1,-1,-1,-1},
};

int CSelectSceneChara::m_pianoTable[7][6] =
{
	{-1, 0, 1, 2, 3, 4},
	{ 0,-1, 5, 6, 7, 8},
	{ 1, 5,-1, 9,10,11},
	{ 2, 6, 9,-1,12,13},
	{ 3, 7,10,12,-1,14},
	{ 4, 8,11,13,14,-1},
	{15,-1,-1,-1,-1,-1},
};

CSelectSceneChara::CSelectSceneChara(CGame* lpGame) : CCommonSelectSceneChara(lpGame)
{
	m_game2 = lpGame;
	m_message = m_game2->GetMyMessage();
	m_buttonSizeX = 81;
	m_buttonSizeY = 47;

}

CSelectSceneChara::~CSelectSceneChara()
{

}

void CSelectSceneChara::End(void)
{
	CCommonSelectSceneChara::End();
}

int CSelectSceneChara::Init(void)
{
	m_nowSelectNumber = -1;
	m_maeSelectNumber = -1;
	m_selectedNumber = -1;
	m_startupWait = 3;

	int rt = CCommonSelectSceneChara::Init();


	return rt;
}
int CSelectSceneChara::Calcu(void)
{
	int rt = CCommonSelectSceneChara::Calcu();

	POINT pt = m_mouseStatus->GetZahyo();
	int mouseX = pt.x;
	int mouseY = pt.y;

	m_maeSelectNumber = m_nowSelectNumber;
	m_nowSelectNumber = GetOnButton(mouseX, mouseY);

	if (m_startupWait > 0)
	{
		m_startupWait--;
	}
	else
	{
		if ((m_nowSelectNumber != m_maeSelectNumber) && (m_nowSelectNumber != -1))
		{
			int yy = m_nowSelectNumber / 6;
			int xx = m_nowSelectNumber % 6;
			if ((xx >= 0) && (xx < 6) && (yy >= 0) && (yy < 7))
			{
				int piano = m_pianoTable[yy][xx];
				if (piano != -1)
				{
					m_game->PlaySystemPiano(piano);
				}
			}
		}
	}


	return rt;
}
int CSelectSceneChara::Print(void)
{
	int rt = CCommonSelectSceneChara::Print();

	//m_message->PrintMessage(300, 300, "BARA SELECTSCENECHARA");


	return rt;
}


void CSelectSceneChara::ReCreateExitScreen(void)
{
	CCommonSelectSceneChara::ReCreateExitScreen();
}


int CSelectSceneChara::GetOnButton(int mouseX, int mouseY)
{
	POINT pt = GetButtonZahyo(0, 0);

	int x = mouseX - pt.x;
	int y = mouseY - pt.y;
	if ((x < 0) || (y < 0)) return -1;

	int placeX = x / m_buttonSizeX;
	int placeY = y / m_buttonSizeY;

	if ((placeX >= 6) || (placeY >= 7)) return -1;
	int kumi = m_placeToKumiTable[placeY][placeX];
	if (kumi == -1) return -1;

	return placeX + placeY * 6;
}

POINT CSelectSceneChara::GetButtonZahyo(int placeX, int placeY)
{
	POINT pt;

	pt.x = 193 + placeX * m_buttonSizeX;
	pt.y = 132 + placeY * m_buttonSizeY;

	return pt;
}

/*_*/

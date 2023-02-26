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
#include "SelectScene.h"


CSelectScene::CSelectScene(CGame* lpGame) : CCommonSelectScene(lpGame)
{
	m_game2 = lpGame;
	m_message = m_game2->GetMyMessage();

}

CSelectScene::~CSelectScene()
{

}

void CSelectScene::End(void)
{
	CCommonSelectScene::End();
}

int CSelectScene::Init(void)
{
	int rt = CCommonSelectScene::Init();

	m_nowSelectNumber = -1;
	m_maeSelectNumber = -1;
	m_selectedNumber = -1;
	m_startupWait = 3;

	return rt;
}
int CSelectScene::Calcu(void)
{
	int rt = CCommonSelectScene::Calcu();

	POINT pt = m_mouseStatus->GetZahyo();
	int mouseX = pt.x;
	int mouseY = pt.y;

	m_maeSelectNumber = m_nowSelectNumber;
	m_nowSelectNumber = GetOnScene(mouseX, mouseY);

	if (m_startupWait > 0)
	{
		m_startupWait--;
	}
	else
	{
		if ((m_nowSelectNumber != m_maeSelectNumber) && (m_nowSelectNumber != -1))
		{
			m_game->PlaySystemPiano(m_nowSelectNumber);
		}
	}

	return rt;
}
int CSelectScene::Print(void)
{
	int rt = CCommonSelectScene::Print();

	//m_message->PrintMessage(300, 300, "BARA SELECTSCENE");


	return rt;
}

int CSelectScene::GetOnScene(int mouseX, int mouseY)
{
	int x = mouseX - m_printX;
	int y = mouseY - m_printY;

	if ((x < 0) || (x >= m_nextX * 4)) return -1;
	if ((y < 0) || (y >= m_nextY * 3)) return -1;

	int ax = x % m_nextX;
	int ay = y % m_nextY;
	if (ax >= m_sizeX) return -1;
	if (ay >= m_sizeY) return -1;

	int d = x / m_nextX;
	d += ((y / m_nextY) * 4);
	int scene = d + m_page * 12;

	if ((scene < 0) || (scene >= m_sceneKosuu)) return -1;
	if (m_sceneFlag[scene]) return d;

	return -1;
}


void CSelectScene::ReCreateExitScreen(void)
{
	CCommonSelectScene::ReCreateExitScreen();
}


/*_*/

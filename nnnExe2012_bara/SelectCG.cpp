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
#include "..\..\systemNNN\nnnUtilLib\cgDataControl.h"


#include "..\..\SystemNNN\nnnLib\gameCallBack.h"

#include "..\..\SystemNNN\nnnLib\commonGeneral.h"
#include "mode.h"
#include "game.h"
#include "SelectCG.h"


CSelectCG::CSelectCG(CGame* lpGame) : CCommonSelectCG(lpGame)
{
	m_game2 = lpGame;
	m_message = m_game2->GetMyMessage();
	m_printX = 85;
	m_printY = 113;
	m_nextX = 251 - 85;
	m_nextY = 237 - 113;
	m_sizeX = 133;
	m_sizeY = 100;

	m_cgDataControl = m_game->GetCGDataControl();
}

CSelectCG::~CSelectCG()
{

}

void CSelectCG::End(void)
{
	CCommonSelectCG::End();
}

int CSelectCG::Init(void)
{
	int rt = CCommonSelectCG::Init();

	m_startupWait = 3;
	m_nowSelectNumber = -1;
	m_maeSelectNumber = -1;
	m_selectedNumber = -1;

//	m_playerNumber = m_game->GetCGCharaNumber();
//	m_cgKosuu = m_game->GetCGKosuu(m_playerNumber);
	m_playerNumber = m_cgDataControl->GetCGCharaNumber();
	m_cgKosuu = m_cgDataControl->GetCGKosuu(m_playerNumber);

	return rt;
}
int CSelectCG::Calcu(void)
{
	int rt = CCommonSelectCG::Calcu();

	POINT pt = m_mouseStatus->GetZahyo();
	int mouseX = pt.x;
	int mouseY = pt.y;

	m_maeSelectNumber = m_nowSelectNumber;
	m_nowSelectNumber = GetOnCG(mouseX, mouseY);

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
int CSelectCG::Print(void)
{
	int rt = CCommonSelectCG::Print();

	//m_message->PrintMessage(300, 300, "BARA SELECTCG");


	return rt;
}


int CSelectCG::GetOnCG(int mouseX, int mouseY)
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
	int cg = d + m_page * 12;

	if ((cg < 0) || (cg >= m_cgKosuu)) return -1;
	if (m_cgDataControl->CheckGetCG(m_playerNumber, cg)) return d;

	return -1;
}


void CSelectCG::ReCreateExitScreen(void)
{
	CCommonSelectCG::ReCreateExitScreen();
}





/*_*/

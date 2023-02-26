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
#include "SelectCGChara.h"


CSelectCGChara::CSelectCGChara(CGame* lpGame) : CCommonSelectCGChara(lpGame)
{
	m_game2 = lpGame;
	m_message = m_game2->GetMyMessage();

}

CSelectCGChara::~CSelectCGChara()
{

}

void CSelectCGChara::End(void)
{
	CCommonSelectCGChara::End();
}

int CSelectCGChara::Init(void)
{
	int rt = CCommonSelectCGChara::Init();

	return rt;
}
int CSelectCGChara::Calcu(void)
{
	int rt = CCommonSelectCGChara::Calcu();

	return rt;
}
int CSelectCGChara::Print(void)
{
	int rt = CCommonSelectCGChara::Print();

	//m_message->PrintMessage(300, 300, "BARA SELECTCGCHARA");


	return rt;
}


void CSelectCGChara::ReCreateExitScreen(void)
{
	CCommonSelectCGChara::ReCreateExitScreen();
}


/*_*/

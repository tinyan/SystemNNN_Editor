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
#include "title.h"


CTitle::CTitle(CGame* lpGame) : CCommonTitle(lpGame)
{
	m_game2 = lpGame;
	m_message = m_game2->GetMyMessage();

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

	return rt;
}
int CTitle::Calcu(void)
{
	int rt = CCommonTitle::Calcu();

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


/*_*/

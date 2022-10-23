//
// game.cpp
//


#include <windows.h>
#include <stdio.h>

#include "..\..\systemNNN\nyanLib\include\commonMacro.h"
#include "..\..\systemNNN\nnnUtilLib\scriptcommand.h"
#include "..\..\systemNNN\nnnUtilLib\commonGameVersion.h"
#include "..\..\systemNNN\nnnUtilLib\nameList.h"
//#include "..\nnnUtilLib\varNumber.h"
//#include "..\nnnUtilLib\myKeyStatus.h"
//#include "..\nnnUtilLib\inputStatus.h"
//#include "..\nnnUtilLib\gameMouse.h"
//#include "..\nnnUtilLib\messageCursor.h"
//#include "..\nnnUtilLib\sceneOptionButton.h"
//#include "..\nnnUtilLib\waveMusic.h"
#include "..\..\systemNNN\nnnUtilLib\commonSystemFile.h"



#include "..\..\systemNNN\nnnLib\commonMode.h"
//#include "..\nnnLib\execScript.h"
#include "..\..\systemNNN\nnnLib\commonGeneral.h"
//#include "..\nnnLib\commonSelectPlace.h"
//#include "..\nnnLib\commonSelectHeroin.h"
//#include "..\nnnLib\commonPrintCalendar.h"
//#include "..\nnnLib\commonPrintMovie.h"
#include "..\..\systemNNN\nnnLib\gameCallBack.h"


#include "PrintCalendar.h"
#include "Kumiawase.h"









#include "mode.h"

#include "game.h"

/*
int CGame::m_daysOfMonth[13]=
{
	0,	31,29,31,30,31,30,31,31,30,31,30,31,
};
*/



char CGame::m_suujiMes[] = "�O�P�Q�R�S�T�U�V�W�X";


int CGame::m_daysOfMonth[13] =
{
	0,	31,29,31,30,31,30,31,31,30,31,30,31,
};

int CGame::m_weekStart[13] =
{
	0,	3,6,6,2,4,0,2,5,1,3,6,2,	//1930
//	0,	6,2,3,6,1,4,6,2,5,0,3,5,	//2000
//	0,	1,4,4,0,2,5,0,3,6,1,4,6,	//2001

};

int CGame::m_cgKosuu[] =
{
	10,20,25,30,35,40,45,50,55,60,
	10,20,25,30,35,40,45,50,55,60,
};

char CGame::m_pianoFileName[20][8] =
{
	"o4c","o4d","o4e","o4f","o4g",
	"o4a","o4b","o5c","o5d","o5e",
	//	"o5e","o5d","o5c","o4b","o4a",
		"o5f","o5g","o5a","o5b","o6c",
		"o6d","o6e","o6f","o6g","o6a",
		//	"o6a","o6g","o6f","o6e","o6d",
};




char CGame::m_resizeFileTable[][16] =
{
	"bg\\bgd01",
	"bg\\bgd03",
	"sys\\name1",
	"sys\\name_bt",

	"",
	"ta\\ta�X�^�b�t2",
	"ta\\ta��",
	"ta\\tad08",

	"",
	"",
	"",
	"ta\\tadh1",

	"ta\\tadh2",
	"ta\\tadh3",
	"",
	"",
};


int CGame::m_resizeTable[] =
{
	800,600,	//dummy
	800,600,	//
	32,32,	//
	32,32,	//
	800,600,	//
	800,600,	//
	800,600,	//
	800,600,	//
	32,32,	//
	32,32,	//
	32,32,	//
	32,32,	//
	32,32,	//
	32,32,	//
	32,32,	//
	32,32,	//

};


char CGame::m_charaName[][16] =
{
	"�Ȃ�",
	"�v",
	"���F",
	"������",
	"����",
	"�^�|",
	"���L",
	"����",
};


/*
CGame::WAVEADJUST CGame::m_waveAdjustData[]=
{
#include "adjwave.txt"
};
*/


char CGame::m_placeAppearList[][32] =
{
	"",
	"�`�o��","��l�������̏h�o��","�l�ӓo��","�_�Гo��","���̒��S�n�o��","�C�̎���o��","���W���o��","�R���o��","���C�ݓo��","�R�G�q�̔��o��",
	//	"�����̉Ɠo��","����o��","⹕a�@�o��","�͌��o��","����̉Ɠo��","�I���̉Ɠo��","�s�X�o��","�����o��","����o��","�Ŏ�̉Ɠo��",
};

char CGame::m_placeButtonList[][32] =
{
	"",
	"�`�{�^��","��l�������̏h�{�^��","�l�Ӄ{�^��","�_�Ѓ{�^��","���̒��S�n�{�^��","�C�̎���{�^��","���W���{�^��","�R���{�^��","���C�݃{�^��","�R�G�q�̔��{�^��",
	//	"�����̉ƃ{�^��","����{�^��","⹕a�@�{�^��","�͌��{�^��","����̉ƃ{�^��","�I���̉ƃ{�^��","�s�X�{�^��","�����{�^��","����{�^��","�Ŏ�̉ƃ{�^��",

};

char CGame::m_photoList[2][3][12][32] =
{
	{
		{
			"",
			//			"�݂̂�ʐ^�ԍ��P","�݂̂�ʐ^�ԍ��Q","�݂̂�ʐ^�ԍ��R","�݂̂�ʐ^�ԍ��S","�݂̂�ʐ^�ԍ��T","�݂̂�ʐ^�ԍ��U","�݂̂�ʐ^�ԍ��V","�݂̂�ʐ^�ԍ��W","�݂̂�ʐ^�ԍ��X","�݂̂�ʐ^�ԍ��P�O","�݂̂�ʐ^�ԍ��P�P","�݂̂�ʐ^�ԍ��P�Q",
					},
					{
						"",
						//			"����ʐ^�ԍ��P","����ʐ^�ԍ��Q","����ʐ^�ԍ��R","����ʐ^�ԍ��S","����ʐ^�ԍ��T","����ʐ^�ԍ��U","����ʐ^�ԍ��V","����ʐ^�ԍ��W","����ʐ^�ԍ��X","����ʐ^�ԍ��P�O","����ʐ^�ԍ��P�P","����ʐ^�ԍ��P�Q",
								},
								{
									"",
									//			"�I���ʐ^�ԍ��P","�I���ʐ^�ԍ��Q","�I���ʐ^�ԍ��R","�I���ʐ^�ԍ��S","�I���ʐ^�ԍ��T","�I���ʐ^�ԍ��U","�I���ʐ^�ԍ��V","�I���ʐ^�ԍ��W","�I���ʐ^�ԍ��X","�I���ʐ^�ԍ��P�O","�I���ʐ^�ԍ��P�P","�I���ʐ^�ԍ��P�Q",
											},
										},
										{
											{
												"",
												//			"����ʐ^�ԍ��P","����ʐ^�ԍ��Q","����ʐ^�ԍ��R","����ʐ^�ԍ��S","����ʐ^�ԍ��T","����ʐ^�ԍ��U","����ʐ^�ԍ��V","����ʐ^�ԍ��W","����ʐ^�ԍ��X","����ʐ^�ԍ��P�O","����ʐ^�ԍ��P�P","����ʐ^�ԍ��P�Q",
														},
														{
															"",
															//			"����ʐ^�ԍ��P�R","����ʐ^�ԍ��P�S","����ʐ^�ԍ��P�T","����ʐ^�ԍ��P�U","����ʐ^�ԍ��P�V","����ʐ^�ԍ��P�W","����ʐ^�ԍ��P�X","����ʐ^�ԍ��Q�O","����ʐ^�ԍ��Q�P","����ʐ^�ԍ��Q�Q","����ʐ^�ԍ��Q�R","����ʐ^�ԍ��Q�S",
																	},
																	{
																		"",
																		//			"����ʐ^�ԍ��Q�T","����ʐ^�ԍ��Q�U","����ʐ^�ԍ��Q�V","����ʐ^�ԍ��Q�W","����ʐ^�ԍ��Q�X","����ʐ^�ԍ��R�O","����ʐ^�ԍ��R�P","����ʐ^�ԍ��R�Q","����ʐ^�ԍ��R�R","����ʐ^�ԍ��R�S","����ʐ^�ԍ��R�T","����ʐ^�ԍ��R�U",
																				},
																			},
};


int CGame::m_saijitsu[] =
{
	1,1,
	1,10,
	2,11,
	3,20,
	4,29,
	5,3,
	5,4,
	5,5,
	7,20,
	9,15,
	9,23,
	10,9,
	11,3,
	11,23,
	12,23,

	- 1,-1,
};












CGame::CGame(HWND hwnd, HINSTANCE hinstance, CCommonSystemFile* lpSystemFile, int windowSizeX, int windowSizeY, int bpp) : CGameCallBack(hwnd, hinstance, lpSystemFile, windowSizeX, windowSizeY, bpp)
{


}




void CGame::Create(void)
{
	if (CheckDebugOk()) SetDebugFlag();

	CreateAllClass();

	m_printDateCommand = m_commandList->SearchName("printdate") / 2;
	m_kumiawaseCommand = m_commandList->SearchName("kumi") / 2;
	m_ryojyokuCommand = m_commandList->SearchName("kumi2") / 2;
	m_endingKumiawaseCommand = m_commandList->SearchName("kumi3") / 2;
	m_kekkaCommand = m_commandList->SearchName("kekka") / 2;

	SetOption(FALSE);
	StartInitialMessage();
}








CGame::~CGame()
{
	End();
}

void CGame::End(void)
{
}












///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CGame::CreateAllClass(void)
{
	CGameCallBack::CreateAllClass(CCommonGameVersion::CheckTaikenOrNetVersion());

	//create original class

	/*
	CreateCommonClass(NOTHING_MODE);
	CreateCommonClass(LOGO_MODE);
	CreateCommonClass(TITLE_MODE);
	CreateCommonClass(OPENING_MODE);
	CreateCommonClass(CONFIG_MODE);
	CreateCommonClass(PRINTMESSAGE_MODE);
	CreateCommonClass(SELECTPLACE_MODE);
	CreateCommonClass(SELECTPLACE2_MODE);
	CreateCommonClass(SELECTOBJECT_MODE);
	CreateCommonClass(PRINTACHIEVEMENT_MODE);
	CreateCommonClass(PRINTTERM_MODE);
	CreateCommonClass(PRINTSTATUS_MODE);
	CreateCommonClass(LISTENVOICE_MODE);
	CreateCommonClass(KANJIINPUT_MODE);
	CreateCommonClass(PRINTITEM_MODE);
	CreateCommonClass(SHOP_MODE);
	CreateCommonClass(BACKLOG_MODE);
	CreateCommonClass(PRINTOVERRAP_MODE);
	CreateCommonClass(SELECTMESSAGE_MODE);
	CreateCommonClass(SYSTEMMENU_MODE);

	CreateCommonClass(CODECERROR_MODE);
	CreateCommonClass(PRINTMOVIE_MODE);

	CreateCommonClass(SELECTHEROIN_MODE);
	CreateCommonClass(PRINTCALENDAR_MODE);

	CreateCommonClass(PRINTMOVIE_MODE);
	CreateCommonClass(NAMEINPUT_MODE);
	CreateCommonClass(MYPRINTRESULT_MODE);
	CreateCommonClass(SELECTCHART_MODE);
	CreateCommonClass(SELECTZUKAN_MODE);
	CreateCommonClass(CARDSYSTEM_MODE);

	

	
	
	if (CCommonGameVersion::CheckTaikenOrNetVersion() == FALSE)
	{
		CreateCommonClass(OMAKE_MODE);
		CreateCommonClass(SELECTCGCHARA_MODE);
		CreateCommonClass(SELECTCG_MODE);
		CreateCommonClass(SELECTSCENECHARA_MODE);
		CreateCommonClass(SELECTSCENE_MODE);
		CreateCommonClass(LISTENBGM_MODE);
		CreateCommonClass(PRINTCG_MODE);
//		CreateCommonClass(LOAD_MODE);
//		CreateCommonClass(SAVE_MODE);
	}

	CreateCommonClass(LOAD_MODE);
	CreateCommonClass(SAVE_MODE);

	CreateCommonClass(MINIGAME_MODE);
	*/


	m_general[BARA_PRINTCALENDAR_MODE] = new CPrintCalendar(this);
	m_general[BARA_KUMIAWASE_MODE] = new CKumiawase(this);
}



/*
kumi, �g�ݍ��킹
kekka, ���ʕ\��
printdate, �c������\��
staffroll, �X�^�b�t���[��
kumi2, �ːJ�p�g�ݍ��킹
kumi3, �G���f�B���O�p�g�ݍ��킹
*/





void CGame::ReceiveUserCommand(int cmd, int paraKosuu, int* paraPtr)
{
	m_skipNextCommandFlag = FALSE;
	m_userCommand = cmd;
	GetUserPara(paraKosuu, paraPtr);

	int aaa = 0;
	aaa++;

	/*
	if (m_userCommand == m_kumiawaseCommand)
	{
		CKumiawase* kumi = (CKumiawase*)m_general[BARA_KUMIAWASE_MODE];
//		kumi->SetMode(0);
		SetReturnCode(BARA_KUMIAWASE_MODE);
	}

	if (m_userCommand == m_ryojyokuCommand)
	{
		CKumiawase* kumi = (CKumiawase*)m_general[BARA_KUMIAWASE_MODE];
//		kumi->SetMode(1);
		SetReturnCode(BARA_KUMIAWASE_MODE);
	}

	if (m_userCommand == m_endingKumiawaseCommand)
	{
		CKumiawase* kumi = (CKumiawase*)m_general[BARA_KUMIAWASE_MODE];
//		kumi->SetMode(2);
		SetReturnCode(BARA_KUMIAWASE_MODE);
	}

	if (m_userCommand == m_printDateCommand)
	{
		//				CKumiawase* kumi = (CKumiawase*)m_general[KUMIAWASE_MODE];
		//				int kekka = GetUserParaData(0);
		//				kumi->SetMode(kekka);
		//				m_returnCode = KUMIAWASE_MODE;
		SetReturnCode(BARA_PRINTCALENDAR_MODE);
	}
	*/

	if (m_userCommand == 1)
	{

	}
	else if (m_userCommand == 2)
	{

	}

//	if (m_userCommand == m_selectHeroinCommandNumber)
//	{
//		CSelectHeroin* selectHeroin = (CSelectHeroin*)m_general[SELECTHEROIN_MODE];
//		selectHeroin->StartSelectHeroin();
//		SetReturnCode(SELECTHEROIN_MODE);
//	}


}




void CGame::ReceiveUserFunction(int cmd, int paraKosuu, int* paraPtr)
{
	/*
	m_userFunction = cmd;
	GetUserPara(paraKosuu, paraPtr);

	if (m_userFunction == m_adjustDateFunction)
	{
		if (m_dayMonthVar != -1)
		{
			int d = GetVarData(m_dayMonthVar);
////			d = AdjustDate(d);
			SetVarData(m_dayMonthVar,d);
		}
	}

	*/



}









/*
int CGame::AdjustDate(int daymonth)
{
	int month = daymonth / 100;
	int day = daymonth % 100;

	if (day > m_daysOfMonth[month])
	{
		day -= m_daysOfMonth[month];
		month++;
	}
	@
	return month * 100 + day;
}
*/







void CGame::UserCommandCallBack(void)
{
	m_yoyakuExecFlag = FALSE;


	if (m_userCommand == m_kumiawaseCommand)
	{
		CKumiawase* kumi = (CKumiawase*)m_general[BARA_KUMIAWASE_MODE];
		kumi->SetMode(0);
		SetReturnCode(BARA_KUMIAWASE_MODE);
	}

	if (m_userCommand == m_ryojyokuCommand)
	{
		CKumiawase* kumi = (CKumiawase*)m_general[BARA_KUMIAWASE_MODE];
		kumi->SetMode(1);
		SetReturnCode(BARA_KUMIAWASE_MODE);
	}

	if (m_userCommand == m_endingKumiawaseCommand)
	{
		CKumiawase* kumi = (CKumiawase*)m_general[BARA_KUMIAWASE_MODE];
		kumi->SetMode(2);
		SetReturnCode(BARA_KUMIAWASE_MODE);
	}

	if (m_userCommand == m_printDateCommand)
	{
		//				CKumiawase* kumi = (CKumiawase*)m_general[KUMIAWASE_MODE];
		//				int kekka = GetUserParaData(0);
		//				kumi->SetMode(kekka);
		//				m_returnCode = KUMIAWASE_MODE;
		SetReturnCode(BARA_PRINTCALENDAR_MODE);
	}

//	if (m_userCommand == m_selectPlaceCommandNumber)
//	{
//		CCommonSelectPlace* selectPlace = (CCommonSelectPlace*)(m_general[SELECTPLACE_MODE]);
//
//		SetReturnCode(SELECTPLACE_MODE);
//	}

}





BOOL CGame::CheckDebugOk(void)
{
	FILE* file00 = NULL;

	fopen_s(&file00,"debug.txt","rb");
	if (file00 != NULL)
	{
		fclose(file00);
		return TRUE;
	}
	return FALSE;
}



void CGame::GetExtDataForSave(LPVOID ptr,int extNumber)
{
}

void CGame::SetExtDataByLoad(LPVOID ptr,int extNumber)
{
}



/////////////////////bara
LPSTR CGame::GetCharaName(int n)
{
	return m_charaName[n];
	//	return NULL;
}


LPSTR CGame::NumberToKanji(int d)
{
	int d0 = d;
	int keta = 1;
	int dv = 1;

	for (int i = 0; i < 8; i++)
	{
		if (d0 >= 10)
		{
			d0 /= 10;
			dv *= 10;
			keta++;
		}
		else
		{
			break;
		}

	}


	for (int i = 0; i < keta; i++)
	{
		int ch = d / dv;
		d -= ch * dv;
		dv /= 10;

		memcpy(&m_numberKanji[i * 2], m_suujiMes + ch * 2, 2);

		//		m_numberKanji[i*2] = '�O' + ch;
	}

	m_numberKanji[keta * 2] = 0;
	m_numberKanji[keta * 2 + 1] = 0;

	return m_numberKanji;
}

int CGame::GetDayMonth(void)
{
	if (m_dayMonthVar == -1) return 101;	//error

	return GetVarData(m_dayMonthVar);
}

/*_*/




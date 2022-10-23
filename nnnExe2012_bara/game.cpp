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



char CGame::m_suujiMes[] = "０１２３４５６７８９";


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
	"ta\\taスタッフ2",
	"ta\\ta剣",
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
	"なし",
	"要",
	"幹彦",
	"あずさ",
	"抱月",
	"真弓",
	"光伸",
	"憲実",
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
	"港登場","主人公たちの宿登場","浜辺登場","神社登場","村の中心地登場","海の自宅登場","旧集落登場","山頂登場","裏海岸登場","由季子の畑登場",
	//	"自分の家登場","裏庭登場","篁病院登場","河原登場","さらの家登場","悠理の家登場","市街登場","教室登場","屋上登場","最首の家登場",
};

char CGame::m_placeButtonList[][32] =
{
	"",
	"港ボタン","主人公たちの宿ボタン","浜辺ボタン","神社ボタン","村の中心地ボタン","海の自宅ボタン","旧集落ボタン","山頂ボタン","裏海岸ボタン","由季子の畑ボタン",
	//	"自分の家ボタン","裏庭ボタン","篁病院ボタン","河原ボタン","さらの家ボタン","悠理の家ボタン","市街ボタン","教室ボタン","屋上ボタン","最首の家ボタン",

};

char CGame::m_photoList[2][3][12][32] =
{
	{
		{
			"",
			//			"みのり写真番号１","みのり写真番号２","みのり写真番号３","みのり写真番号４","みのり写真番号５","みのり写真番号６","みのり写真番号７","みのり写真番号８","みのり写真番号９","みのり写真番号１０","みのり写真番号１１","みのり写真番号１２",
					},
					{
						"",
						//			"さら写真番号１","さら写真番号２","さら写真番号３","さら写真番号４","さら写真番号５","さら写真番号６","さら写真番号７","さら写真番号８","さら写真番号９","さら写真番号１０","さら写真番号１１","さら写真番号１２",
								},
								{
									"",
									//			"悠理写真番号１","悠理写真番号２","悠理写真番号３","悠理写真番号４","悠理写真番号５","悠理写真番号６","悠理写真番号７","悠理写真番号８","悠理写真番号９","悠理写真番号１０","悠理写真番号１１","悠理写真番号１２",
											},
										},
										{
											{
												"",
												//			"美夜写真番号１","美夜写真番号２","美夜写真番号３","美夜写真番号４","美夜写真番号５","美夜写真番号６","美夜写真番号７","美夜写真番号８","美夜写真番号９","美夜写真番号１０","美夜写真番号１１","美夜写真番号１２",
														},
														{
															"",
															//			"美夜写真番号１３","美夜写真番号１４","美夜写真番号１５","美夜写真番号１６","美夜写真番号１７","美夜写真番号１８","美夜写真番号１９","美夜写真番号２０","美夜写真番号２１","美夜写真番号２２","美夜写真番号２３","美夜写真番号２４",
																	},
																	{
																		"",
																		//			"美夜写真番号２５","美夜写真番号２６","美夜写真番号２７","美夜写真番号２８","美夜写真番号２９","美夜写真番号３０","美夜写真番号３１","美夜写真番号３２","美夜写真番号３３","美夜写真番号３４","美夜写真番号３５","美夜写真番号３６",
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
kumi, 組み合わせ
kekka, 結果表示
printdate, 残り日数表示
staffroll, スタッフロール
kumi2, 陵辱用組み合わせ
kumi3, エンディング用組み合わせ
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

		//		m_numberKanji[i*2] = '０' + ch;
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




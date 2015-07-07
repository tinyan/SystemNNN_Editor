#include <windows.h>
#include <stdio.h>

#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nnnUtilLib\nameList.h"

#include "rubimaker.h"


#define RUBI_START ( (('［' >> 8) & 0xff) | (('［' << 8) & 0x0ff00) )
#define RUBI_END ( (('］' >> 8) & 0xff) | (('］' << 8) & 0x0ff00) )
#define NUMBER_ZERO ( (('０' >> 8) & 0xff) | (('０' << 8) & 0x0ff00) )


char CRubiMaker::m_suujiMessage[][4] = 
{
	"０","１","２","３","４","５","６","７","８","９"
};



CRubiMaker::CRubiMaker(BOOL createFlag)
{
	m_list = NULL;
	m_loadFlag = FALSE;
	m_loadErrorFlag = FALSE;
	m_rubiKosuu = 0;
	m_kanjiLengthTable = NULL;


	if (createFlag)
	{
		Load();
	}

	m_makedBuffer = new char[1024];

}

CRubiMaker::~CRubiMaker()
{
	End();
}


void CRubiMaker::End(void)
{
	DELETEARRAY(m_makedBuffer);
	DELETEARRAY(m_kanjiLengthTable);
	ENDDELETECLASS(m_list);
}


void CRubiMaker::Load(void)
{
	if (m_loadFlag) return;
	if (m_loadErrorFlag) return;

	m_list = new CNameList();
	if (m_list->LoadFile("nnndir\\rubi.txt"))
	{
		m_loadFlag = TRUE;
	}
	else
	{
		MessageBox(NULL,"ERROR","",MB_ICONEXCLAMATION | MB_OK);
		m_loadErrorFlag = TRUE;
	}

	if (m_loadFlag)
	{
		CreateTable();
	}
}


void CRubiMaker::CreateTable(void)
{
	m_rubiKosuu = m_list->GetNameKosuu() / 2;
	m_kanjiLengthTable = new int[m_rubiKosuu];

	for (int i=0;i<m_rubiKosuu;i++)
	{
		m_kanjiLengthTable[i] = strlen(m_list->GetName(i*2));
	}
}

LPSTR CRubiMaker::RubiConvert(LPSTR mes)
{
	int mesLen = strlen(mes);

	if (m_loadFlag == FALSE)
	{
		int ln = mesLen;
		if (ln > 1022) ln = 1022;
		memcpy(m_makedBuffer,mes,ln);
		m_makedBuffer[ln] = 0;
		m_makedBuffer[ln+1] = 0;
		return m_makedBuffer;
	}

	int usedFlag[256];
	//first clear
	for (int i=0;i<256;i++)
	{
		usedFlag[i] = 0;
	}

	//set org use
	int k = 0;
	int kanjiLen = 0;

	BOOL errorFlag = FALSE;

	while (k<mesLen)
	{
		char c = *(mes+k);
		
		if (c == '#')
		{
			k++;

			short* ptr = (short*)(mes+k);
			short kanji = *ptr;
			
			if (kanji == RUBI_START)
			{
				k += 2;
				ptr++;

				short numKanji = *ptr;
				k += 2;
				ptr++;

				int numkanjirev = ((numKanji>>8)& 0xff) | ((numKanji<<8) & 0xff00);
				int nn = numkanjirev - '０';
				if ((nn >= 1) && (nn<= 9))
				{
					int pp = kanjiLen - nn;
					if (pp<0)
					{
						PrintRubiError("元のメッセージのルビ表記に問題があります(ルビ対象文字がたりません)",mes);
						errorFlag = TRUE;
						break;
					}

					for (int p=0;p<nn;p++)
					{
						usedFlag[pp+p] = 1;
					}

				}
				else
				{
					PrintRubiError("元のメッセージのルビ表記に問題があります",mes);
					errorFlag = TRUE;
					break;
				}

				//skip to last
				BOOL tojiFlag = FALSE;

				while (k<mesLen)
				{
					short chk = *ptr;
					ptr++;
					k += 2;
					if (chk == RUBI_END)
					{
						tojiFlag = TRUE;
						break;
					}
				}
				if (tojiFlag == FALSE)
				{
					PrintRubiError("元のメッセージのルビ表記に問題があります(ルビが閉じられていません)",mes);
					errorFlag = TRUE;
					break;
				}
			}
			else
			{
				k += 2;
				kanjiLen++;
			}

			if (errorFlag) break;

		}
		else
		{
			k += 2;
			kanjiLen++;
		}
	}

	if (errorFlag)
	{
		int ln = mesLen;
		if (ln > 1022) ln = 1022;
		memcpy(m_makedBuffer,mes,ln);
		m_makedBuffer[ln] = 0;
		m_makedBuffer[ln+1] = 0;
		return m_makedBuffer;
	}



	k=0;
	kanjiLen = 0;
	int makedLen = 0;

	char checkMes[1024];

	while (k<mesLen)
	{
		char c = *(mes+k);
		
		if (c == '#')
		{
			m_makedBuffer[makedLen] = c;
			k++;
			makedLen++;

			short* ptr = (short*)(mes+k);
			short kanji = *ptr;
			
			if (kanji == RUBI_START)
			{
				memcpy(&m_makedBuffer[makedLen],mes+k,2);
				k += 2;
//				kanjiLen++;
				makedLen+=2;
				ptr++;

				while (k<mesLen)
				{
					short chk = *ptr;
					ptr++;
					memcpy(&m_makedBuffer[makedLen],mes+k,2);
					k += 2;
//					kanjiLen++;
					makedLen+=2;

					if (chk == RUBI_END)
					{
						break;
					}
				}
			}
			else
			{
				memcpy(&m_makedBuffer[makedLen],mes+k,2);
				k += 2;
				kanjiLen++;
				makedLen+=2;
			}
		}
		else
		{
			if (usedFlag[kanjiLen])
			{
				memcpy(&m_makedBuffer[makedLen],mes+k,2);
				k += 2;
				kanjiLen++;
				makedLen+=2;
			}
			else
			{
				int found = -1;
				for (int i=0;i<m_rubiKosuu;i++)
				{
					int rubiSrcLength = m_kanjiLengthTable[i];
					
					if ((k+rubiSrcLength) <= mesLen)
					{
						LPSTR rubiSrcMes = m_list->GetName(i*2);

						memcpy(checkMes,mes+k,rubiSrcLength);
						checkMes[rubiSrcLength] = 0;
						checkMes[rubiSrcLength+1] = 0;
						if (strcmp(checkMes,rubiSrcMes) == 0)
						{
							found = i;
							break;
						}
					}
				}
				if (found == -1)
				{
					memcpy(&m_makedBuffer[makedLen],mes+k,2);
					k += 2;
					kanjiLen++;
					makedLen+=2;
				}
				else
				{
					int rubiSrcLen = m_kanjiLengthTable[found];
					LPSTR rubiSrcMes = m_list->GetName(found*2+1);

					memcpy(&m_makedBuffer[makedLen],mes+k,rubiSrcLen);
					kanjiLen += rubiSrcLen / 2;
					k += rubiSrcLen;
					makedLen += rubiSrcLen;

					if ((*rubiSrcMes) != '*')
					{
						m_makedBuffer[makedLen] = '#';
						makedLen++;

						memcpy(&m_makedBuffer[makedLen],"［",2);
						makedLen+=2;

						memcpy(&m_makedBuffer[makedLen],m_suujiMessage[rubiSrcLen/2],2);
						makedLen+=2;

						int ll = strlen(rubiSrcMes);
						memcpy(&m_makedBuffer[makedLen],rubiSrcMes,ll);
						makedLen += ll;

						memcpy(&m_makedBuffer[makedLen],"］",2);
						makedLen+=2;
					}
				}
			}
		}
	}


/*
#if defined _DEBUG
	char debugMes[129];
	for (int i=0;i<128;i++)
	{
		if (usedFlag[i])
		{
			debugMes[i] = 'x';
		}
		else
		{
			debugMes[i] = '.';
		}
	}
	debugMes[128] = 0;
	OutputDebugString("\nmess:");
	OutputDebugString(mes);
	OutputDebugString("\nused:");
	OutputDebugString(debugMes);
	OutputDebugString("\n");
#endif
*/



	m_makedBuffer[makedLen] = 0;
	m_makedBuffer[makedLen+1] = 0;

	return m_makedBuffer;
}


void CRubiMaker::PrintRubiError(LPSTR typeMes,LPSTR orgMes)
{
	char mes[1024];
	wsprintf(mes,"%s\n\n%s",typeMes,orgMes);
	MessageBox(NULL,"ERROR",mes,MB_ICONEXCLAMATION | MB_OK);
}

/*_*/


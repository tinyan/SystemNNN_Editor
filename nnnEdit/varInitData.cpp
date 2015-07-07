//
// varInitData.cpp
//


#include <windows.h>
#include <stdio.h>


#include "..\..\systemNNN\nyanLib\include\commonmacro.h"
#include "..\..\systemNNN\nnnUtilLib\nameList.h"

#include "varInitData.h"



CVarInitData::CVarInitData()
{
	m_list = new CNameList();
	for (int i=0;i<1000;i++)
	{
		m_data[i] = 0;
	}
	m_editFlag = FALSE;
}

CVarInitData::~CVarInitData()
{
	End();
}

void CVarInitData::End(void)
{
	ENDDELETECLASS(m_list);
}

int CVarInitData::GetData(int n)
{
	if ((n>=0) && (n<1000))
	{
		return m_data[n];
	}
	return 0;//error!
}

void CVarInitData::SetData(int n,int d)
{
	if ((n>=0) && (n<1000))
	{
		m_data[n] = d;
		m_editFlag = TRUE;
	}
}


BOOL CVarInitData::Load(LPSTR filename)
{
	if (m_list->LoadFile(filename,FALSE,TRUE))
	{
		int kosuu = m_list->GetNameKosuu();
		if (kosuu>1000) kosuu = 1000;
		for (int i=0;i<kosuu;i++)
		{
			m_data[i] = atoi(m_list->GetName(i));
		}
		m_editFlag = FALSE;
		return TRUE;
	}

	m_editFlag = TRUE;
	return FALSE;
}



BOOL CVarInitData::Save(LPSTR filename)
{
	FILE* file = NULL;
	fopen_s(&file,filename,"wb");
	if (file == NULL)
	{
		MessageBox(NULL,"open error 変数初期値ファイル","Error",MB_OK | MB_ICONEXCLAMATION);
		//error
		return FALSE;
	}

	for (int j=0;j<200;j++)
	{
		char mes[1024];
		wsprintf(mes,"%d,%d,%d,%d,%d\x00d\x00a",m_data[j*5+0],m_data[j*5+1],m_data[j*5+2],m_data[j*5+3],m_data[j*5+4]);
		int ln = strlen(mes);
		fwrite(mes,sizeof(char),ln,file);
	}

	fclose(file);
	m_editFlag = FALSE;
	return TRUE;
}





/*_*/



#include "Diagram.h"


static CString Int2Str(int iNum);


CDiagram::CDiagram(int iNumOfColumns,...)
{
    m_iNumOfColumns  = iNumOfColumns;
    m_pColumnTitles  = new CString[m_iNumOfColumns];
    m_pRowDelimiters = new CString[m_iNumOfColumns];

    int* pColumnTitles = (int*)&iNumOfColumns+1;
    for (int i=0; i<m_iNumOfColumns; i++)
        m_pColumnTitles[i] = CString((char*)pColumnTitles[i]);

    for (int i=0; i<m_iNumOfColumns; i++)
    {
        m_pRowDelimiters[i] = CString("|");
        for (int j=0; j<i; j++)
        {
            for (int k=0; k<=m_pColumnTitles[j].GetLength(); k++)
                m_pRowDelimiters[i] += CString(" ");
            m_pRowDelimiters[i] += CString(" |");
        }
        for (int j=i; j<m_iNumOfColumns; j++)
        {
            for (int k=0; k<=m_pColumnTitles[j].GetLength(); k++)
                m_pRowDelimiters[i] += CString("-");
            m_pRowDelimiters[i] += CString("-|");
        }
        m_pRowDelimiters[i] += CString("\n");
    }

    m_cPresentation = m_pRowDelimiters[0] + CString("|");
    for (int i=0; i<m_iNumOfColumns; i++)
    {
        m_cPresentation += CString(" ") + m_pColumnTitles[i] + CString(" |");
    }
    m_cPresentation += CString("\n");
}


CDiagram::~CDiagram()
{
    delete[] m_pColumnTitles;
    delete[] m_pRowDelimiters;
}


void CDiagram::AddRow(int iNumOfValues,...)
{
    int  iNumOfSkipColumns = m_iNumOfColumns-iNumOfValues;
    int* pValuePerColumn   = (int*)&iNumOfValues+1;

    m_cPresentation += m_pRowDelimiters[iNumOfSkipColumns] + CString("|");
    for (int i=0; i<m_iNumOfColumns; i++)
    {
        CString cValue;
        if (i >= iNumOfSkipColumns)
            cValue = Int2Str(pValuePerColumn[i-iNumOfSkipColumns]);
        int iValueLength = cValue.GetLength();
        int iTitleLength = m_pColumnTitles[i].GetLength();
        while (iValueLength++ <= iTitleLength)
            cValue = CString(" ") + cValue;
        m_cPresentation += cValue + CString(" |");
    }
    m_cPresentation += CString("\n");
}


void CDiagram::Close()
{
    m_cPresentation += m_pRowDelimiters[0];
}


CDiagram::operator const char*() const
{
    return m_cPresentation;
}


static CString Int2Str(int iNum)
{
    if (iNum == 0)
        return CString("0");
    if (iNum < 0)
        return CString("-")+Int2Str(-iNum);

    CString cString;
    char aString[] = {0,0};
    for (int iTmp=iNum; iTmp>0; iTmp/=10)
    {
        aString[0] = '0'+(iTmp%10);
        cString = CString(aString)+cString;
    }
    return cString;
}

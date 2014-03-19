#include "String.h"
#include <string.h>


CString::CString(const char* pString)
{
    Init(pString);
}


CString::CString(const CString& cString)
{
    Init(cString.m_pBuffer);
}


CString::~CString()
{
    Free();
}


int CString::GetLength() const
{
    return m_iLength;
}


CString::operator const char*() const
{
    return m_pBuffer;
}


CString& CString::operator=(const CString& cString)
{
    if (this != &cString)
    {
        Free();
        Init(cString.m_pBuffer);
    }
    return *this;
}


CString& CString::operator+=(const CString& cString)
{
    if (m_iLength == 0)
    {
        Init(cString.m_pBuffer);
    }
    else if (cString.m_iLength > 0)
    {
        char* pBuffer = new char[m_iLength+cString.m_iLength+1];
        strcpy(pBuffer,m_pBuffer);
        strcat(pBuffer,cString.m_pBuffer);
        delete[] m_pBuffer;
        m_iLength += cString.m_iLength;
        m_pBuffer  = pBuffer;
    }
    return *this;
}


CString operator+(const CString& cString1,const CString& cString2)
{
    CString cString = cString1;
    cString += cString2;
    return cString;
}


void CString::Init(const char* pString)
{
    if (pString == 0)
    {
        m_iLength = 0;
        m_pBuffer = 0;
    }
    else
    {
        m_iLength = strlen(pString);
        m_pBuffer = new char[m_iLength+1];
        strcpy(m_pBuffer,pString);
    }
}


void CString::Free()
{
    if (m_iLength > 0)
    {
        m_iLength = 0;
        delete[] m_pBuffer;
    }
}

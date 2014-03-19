#ifndef DIAGRAM_H
#define DIAGRAM_H


#include "String.h"


//////////////////////////////////////////////////////////////////////////
//                                                                      //
// CLASS NAME:  CDiagram                                                //
//                                                                      //
// DESCRIPTION: Provide an API for building text-tables.                //
//                                                                      //
// REMARKS:     No build-time or run-time dependencies.                 //
//                                                                      //
// AUTHOR:      Barakman (barakman@yahoo.com)                           //
//                                                                      //
//////////////////////////////////////////////////////////////////////////


class CDiagram
{
public:
    CDiagram(int iNumOfColumns,...); //char* pTitle1,char* pTitle2,...,char* pTitleN
    virtual ~CDiagram();
public:
    void AddRow(int iNumOfValues,...); //int iValueK+1,int iValueK+2,...,int iValueN
    void Close();
public:
    operator const char*() const;
private:
    int      m_iNumOfColumns;
    CString* m_pColumnTitles;
private:
    CString* m_pRowDelimiters;
    CString  m_cPresentation;
};


#endif /* DIAGRAM_H */

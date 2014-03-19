#ifndef STRING_H
#define STRING_H


class CString
{
public:
    CString(const char* pString=0);
    CString(const CString& cString);
    virtual ~CString();
public:
    virtual int GetLength() const;
    virtual operator const char*() const;
public:
    virtual CString& operator =(const CString& cString);
    virtual CString& operator+=(const CString& cString);
    friend  CString  operator+ (const CString& cString1,const CString& cStrin2);
protected:
    virtual void Init(const char* pString);
    virtual void Free();
protected:
    int   m_iLength;
    char* m_pBuffer;
};


#endif /* STRING_H */

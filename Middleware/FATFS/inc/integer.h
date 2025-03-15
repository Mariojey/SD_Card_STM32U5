#ifndef _FF_INTEGER
#define _FF_INTEGER

#ifdef _WIN32

#include <windows.h>
#include <tchar.h>
typedef unsigned __int64 QWORD;

#else

//16-bit or 32-bit type
typedef int	INT;

typedef unsigned int UINT;

//8-bit
typedef unsigned char BYTE;


//16 - bit
typedef short SHORT;

typedef unsigned short WORD;

typedef unsigned short WCHAR;


//32-bit
typedef long LONG;

typedef unsigned long DWORD;

//64-bit
typedef unsigned long long QWORD;

#endif

#endif

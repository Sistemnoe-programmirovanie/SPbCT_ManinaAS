#pragma once
#include <Windows.h>
#if defined(UTILITY_3_0_EXPORTS) 

#define LIBSPEC _declspec(dllexport)

#elif defined(__cplusplus)

#define LIBSPEC extern "C" _declspec(dllimport)

#else

#define LIBSPEC _declspec(dllimport)

#endif


#define EMPTY _T("") 

#define YES _T("g") 

#define NO _T("h") 

#define CR 0x0D 

#define LF 0x0A

#define TSIZE sizeof(TCHAR)

/* Часто используемые функции. */

LIBSPEC BOOL ConsolePrompt(LPCTSTR, LPTSTR, DWORD, BOOL);

LIBSPEC BOOL PrintStrings(HANDLE, ...);

LIBSPEC BOOL PrintMsg(HANDLE, LPCTSTR);

LIBSPEC VOID ReportError(LPCTSTR, DWORD, BOOL);

LIBSPEC VOID ReportException(LPCTSTR, DWORD);

LIBSPEC DWORD Options(int, LPCTSTR*, LPCTSTR, ...);

LIBSPEC LPTSTR SkipArg(LPCTSTR);

LIBSPEC VOID GetArgs(LPCTSTR, int*, LPTSTR*);

/* Предельные значения и константы. */

#define TYPE_FILE 1 

#define TYPE_DIR 2

#define TYPE_DOT 3

#define MAX_OPTIONS 20 

#define MAX_ARG 1000  

#define MAX_COMMAND_LINE MAX_PATH+50 //размер командной строки





/* Набор функций для работы с обобщенными строками в стиле string.h. Создавались по мере необходимости – первоначально была только одна функция! Реализация взята из [27]. */

//LIBSPEC LPCTSTR wmemchr(LPCTSTR, TCHAR, DWORD);


#ifdef _UNICODE /* Это объявление уже должно было быть добавлено. */

#define _ebchr wcsrchr

#else

#define _tstrrchr strrchr

#endif


#ifdef _UNICODE 

#define _astchr waschr

#else

#define _astchr aschr

#endif


/* Функции безопасности. */

LPSECURITY_ATTRIBUTES InitializeUnixSA(DWORD, LPTSTR, LPTSTR, LPDWORD, LPHANDLE);

LPSECURITY_ATTRIBUTES InitializeAccessOnlySA(DWORD, LPTSTR, LPTSTR, LPDWORD, LPHANDLE);

DWORD ReadFilePermissions(LPTSTR, LPTSTR, LPTSTR);

BOOL ChangeFilePermissions(DWORD, LPTSTR, LPDWORD, LPDWORD);


/* Константы, которые требуются для функций безопасности. */

#define LUSIZE 1024

#define ACCT_NAME_SIZE LUSIZE
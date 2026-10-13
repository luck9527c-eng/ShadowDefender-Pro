// ===== sub_180001000 @ 0x180001000 size=0xb3 =====
int sub_180001000()
{
  signed int LastError; // eax
  bool v1; // sf

  CriticalSection.DebugInfo = nullptr;
  *(_QWORD *)&CriticalSection.LockCount = 0;
  CriticalSection.OwningThread = nullptr;
  CriticalSection.LockSemaphore = nullptr;
  CriticalSection.SpinCount = 0;
  dword_18002A200 = 0;
  qword_18002A208 = (__int64)&_ImageBase;
  qword_18002A210 = (__int64)&off_180027470;
  qword_18002A218 = (__int64)&unk_180027478;
  if ( InitializeCriticalSectionAndSpinCount(&CriticalSection, 0) )
    goto LABEL_6;
  LastError = GetLastError();
  v1 = LastError < 0;
  if ( LastError > 0 )
    v1 = true;
  if ( !v1 )
  {
LABEL_6:
    dword_18002A200 = 72;
    return atexit(sub_180019C50);
  }
  else
  {
    byte_18002A178 = 1;
    return atexit(sub_180019C50);
  }
}


// ===== sub_1800010C0 @ 0x1800010c0 size=0xf2 =====
int sub_1800010C0()
{
  signed int LastError; // eax
  bool v1; // sf
  unsigned __int64 v2; // rbx
  unsigned __int64 i; // rcx

  stru_18002A1B8.DebugInfo = nullptr;
  *(_QWORD *)&stru_18002A1B8.LockCount = 0;
  stru_18002A1B8.OwningThread = nullptr;
  stru_18002A1B8.LockSemaphore = nullptr;
  stru_18002A1B8.SpinCount = 0;
  qword_18002A1A8 = 0;
  qword_18002A1B0 = 0;
  qword_18002A148 = (__int64)&qword_18002A1A0;
  qword_18002A1E0 = 0;
  if ( InitializeCriticalSectionAndSpinCount(&stru_18002A1B8, 0) )
    goto LABEL_6;
  LastError = GetLastError();
  v1 = LastError < 0;
  if ( LastError > 0 )
    v1 = true;
  if ( !v1 )
LABEL_6:
    LODWORD(qword_18002A1A8) = 56;
  else
    byte_18002A178 = 1;
  __wind
  {
    xmmword_18002A1E8 = xmmword_18001B758;
  }
  __unwind
  {
    sub_1800063D0(&qword_18002A1A0);
  }
  __wind
  {
    v2 = qword_18002A210;
    for ( i = qword_18002A218; v2 < i; v2 += 8LL )
    {
      if ( *(_QWORD *)v2 != 0 )
      {
        LOBYTE(i) = 1;
        (*(void (__fastcall **)(unsigned __int64))(*(_QWORD *)v2 + 56LL))(i);
        i = qword_18002A218;
      }
    }
  }
  __unwind
  {
    sub_180006340(&qword_18002A1A0);
  }
  __wind
  {
    qword_18002A1A0 = (__int64)&CShellExtModule::`vftable';
  }
  __unwind
  {
    sub_1800062E0(&qword_18002A1A0);
  }
  return atexit(sub_180019CE0);
}


// ===== sub_1800011B4 @ 0x1800011b4 size=0x20 =====
int sub_1800011B4()
{
  sub_1800073F8(&unk_18002A250);
  return atexit(sub_180019D30);
}


// ===== sub_1800011E0 @ 0x1800011e0 size=0x14 =====
__int64 sub_1800011E0()
{
  __int64 result; // rax

  result = sub_180008AB0();
  dword_18002A8B0 = result;
  return result;
}


// ===== sub_180001200 @ 0x180001200 size=0x9 =====
__int64 __fastcall sub_180001200(__int64 a1)
{
  return sub_180002020(a1 - 8);
}


// ===== sub_18000120C @ 0x18000120c size=0x9 =====
__int64 __fastcall sub_18000120C(__int64 a1)
{
  return sub_180001FB0(a1 - 8);
}


// ===== sub_180001218 @ 0x180001218 size=0x9 =====
__int64 __fastcall sub_180001218(__int64 a1)
{
  return sub_180001FC0(a1 - 8);
}


// ===== sub_180001224 @ 0x180001224 size=0x9 =====
__int64 __fastcall sub_180001224(__int64 a1)
{
  return sub_180002020(a1 - 16);
}


// ===== sub_180001230 @ 0x180001230 size=0x9 =====
__int64 __fastcall sub_180001230(__int64 a1)
{
  return sub_180001FB0(a1 - 16);
}


// ===== sub_18000123C @ 0x18000123c size=0x9 =====
__int64 __fastcall sub_18000123C(__int64 a1)
{
  return sub_180001FC0(a1 - 16);
}


// ===== sub_180001250 @ 0x180001250 size=0x54 =====
__int64 __fastcall sub_180001250(__int64 a1, __int64 a2, _DWORD *a3, _QWORD *a4)
{
  if ( a4 == nullptr )
    return 2147500035LL;
  *a4 = 0;
  if ( a2 != 0 && (*a3 != 0 || a3[1] != 0 || a3[2] != 192 || a3[3] != 1174405120) )
    return 2147746064LL;
  else
    return (*(__int64 (__fastcall **)(__int64, _DWORD *, _QWORD *))(a1 + 64))(a2, a3, a4);
}


// ===== sub_1800012B0 @ 0x1800012b0 size=0x26 =====
__int64 __fastcall sub_1800012B0(__int64 a1, int a2)
{
  __int64 v2; // rax

  v2 = *(_QWORD *)qword_18002A148;
  if ( a2 != 0 )
    (*(void (**)(void))(v2 + 8))();
  else
    (*(void (**)(void))(v2 + 16))();
  return 0;
}


// ===== sub_1800012E0 @ 0x1800012e0 size=0x6c =====
char *__fastcall sub_1800012E0(char *Block, char a2)
{
  struct _RTL_CRITICAL_SECTION *v4; // rcx

  *(_QWORD *)Block = &ATL::CComClassFactory::`vftable';
  v4 = (struct _RTL_CRITICAL_SECTION *)(Block + 16);
  if ( LOBYTE(v4[1].DebugInfo) != 0 )
  {
    LOBYTE(v4[1].DebugInfo) = 0;
    DeleteCriticalSection(v4);
  }
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(Block);
  return Block;
}


// ===== sub_180001350 @ 0x180001350 size=0x6 =====
__int64 sub_180001350()
{
  return 2147500033LL;
}


// ===== ?raw_length@charNode@@UEBAHXZ @ 0x180001360 size=0x6 =====
__int64 __fastcall charNode::raw_length(charNode *this)
{
  return 1;
}


// ===== sub_180001370 @ 0x180001370 size=0x3 =====
__int64 sub_180001370()
{
  return 0;
}


// ===== sub_180001380 @ 0x180001380 size=0x46 =====
__int64 __fastcall sub_180001380(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // eax
  unsigned int v4; // ecx
  __int64 v6; // [rsp+48h] [rbp+10h] BYREF

  if ( a2 == 0 || a3 == 0 )
    return 2147942487LL;
  v6 = 0;
  __wind
  {
    v3 = sub_1800026E0(a1 + 8);
    v4 = -2147024882;
    if ( v3 != 0 )
      v4 = 0;
  }
  __unwind
  {
    sub_180002290(&v6);
  }
  return v4;
}


// ===== sub_1800013D0 @ 0x1800013d0 size=0x9 =====
__int64 __fastcall sub_1800013D0(__int64 a1)
{
  return sub_180002FF0(a1 + 8);
}


// ===== sub_1800013E0 @ 0x1800013e0 size=0x34 =====
void *__fastcall sub_1800013E0(void *Block, char a2)
{
  sub_180002640();
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(Block);
  return Block;
}


// ===== sub_180001420 @ 0x180001420 size=0x16 =====
__int64 __fastcall sub_180001420(unsigned int a1)
{
  return sub_1800052F0(qword_18002A148, 102, a1);
}


// ===== sub_180001440 @ 0x180001440 size=0x29b =====
__int64 __fastcall sub_180001440(__int64 a1, __int64 a2, __int64 a3)
{
  HDROP v4; // rax
  HDROP v5; // r12
  UINT FileW; // r13d
  UINT i; // esi
  UINT v8; // ebx
  wchar_t *v9; // rdi
  __int64 v10; // r8
  __int64 v11; // rbx
  __int64 *v12; // rdi
  __int64 v13; // rax
  __int64 v14; // rdx
  void *v15; // rcx
  STGMEDIUM v17; // [rsp+20h] [rbp-49h] BYREF
  __int16 v18; // [rsp+38h] [rbp-31h] BYREF
  __int64 v19; // [rsp+40h] [rbp-29h]
  int v20; // [rsp+48h] [rbp-21h]
  int v21; // [rsp+4Ch] [rbp-1Dh]
  int v22; // [rsp+50h] [rbp-19h]
  __int64 v23; // [rsp+58h] [rbp-11h]
  _QWORD v24[2]; // [rsp+60h] [rbp-9h] BYREF
  __int64 v25; // [rsp+70h] [rbp+7h]
  unsigned __int64 v26; // [rsp+78h] [rbp+Fh]

  v23 = -2;
  v18 = 15;
  v19 = 0;
  v20 = 1;
  v21 = -1;
  v22 = 1;
  v17.tymed = 1;
  v17.hBitmap = nullptr;
  v17.pUnkForRelease = nullptr;
  if ( (*(int (__fastcall **)(__int64, __int16 *, STGMEDIUM *))(*(_QWORD *)a3 + 24LL))(a3, &v18, &v17) < 0 )
    return 2147942487LL;
  v4 = (HDROP)GlobalLock(v17.hBitmap);
  v5 = v4;
  if ( v4 == nullptr )
    return 2147942487LL;
  FileW = DragQueryFileW(v4, 0xFFFFFFFF, nullptr, 0);
  if ( FileW - 1 > 0x63 )
  {
    GlobalUnlock(v17.hBitmap);
    ReleaseStgMedium(&v17);
    return 2147942487LL;
  }
  sub_1800058D0(a1 + 24);
  for ( i = 0; i < FileW; ++i )
  {
    v8 = DragQueryFileW(v5, i, nullptr, 0);
    v9 = (wchar_t *)operator new(saturated_mul(v8 + 8, 2u));
    if ( DragQueryFileW(v5, i, v9, v8 + 1) != 0 )
    {
      if ( (GetFileAttributesW(v9) & 0x10) != 0 )
        wcscat_s(v9, v8 + 8, L"\\*.*");
      v25 = 0;
      v26 = 7;
      LOWORD(v24[0]) = 0;
      v10 = -1;
      do
        ++v10;
      while ( v9[v10] != 0 );
      sub_180005740(v24, v9);
      __wind
      {
        v11 = *(_QWORD *)(a1 + 24);
        v12 = *(__int64 **)(v11 + 8);
        v13 = sub_1800020D0(a1 + 24, v11, v12, v24);
        v14 = *(_QWORD *)(a1 + 32);
        if ( v14 == 0x555555555555554LL )
          sub_180007690("list<T> too long");
        *(_QWORD *)(a1 + 32) = v14 + 1;
        *(_QWORD *)(v11 + 8) = v13;
        *v12 = v13;
      }
      __unwind
      {
        sub_1800023E0(v24);
      }
      if ( v26 >= 8 )
      {
        v15 = (void *)v24[0];
        if ( 2 * v26 + 2 >= 0x1000 )
        {
          v15 = *(void **)(v24[0] - 8LL);
          if ( (unsigned __int64)(v24[0] - (_QWORD)v15 - 8LL) > 0x1F )
            invalid_parameter_noinfo_noreturn();
        }
        j_j_j__free_base(v15);
      }
      v25 = 0;
      v26 = 7;
      LOWORD(v24[0]) = 0;
    }
  }
  GlobalUnlock(v17.hBitmap);
  ReleaseStgMedium(&v17);
  return 0;
}


// ===== sub_1800016E0 @ 0x1800016e0 size=0x1f3 =====
__int64 __fastcall sub_1800016E0(__int64 a1, __int64 a2, char a3, __int64 a4, LPWSTR lpString1, int iMaxLength)
{
  const CHAR *v7; // rbx
  __int64 v9; // rax
  int v10; // edx
  unsigned __int64 v11; // rax
  __int64 v12; // rcx
  unsigned __int64 v13; // rcx
  void *v14; // rsp
  void *v15; // rsp
  DWORD *p_pcbData; // rdi
  __int64 v17; // [rsp+0h] [rbp-40h] BYREF
  DWORD pcbData; // [rsp+40h] [rbp+0h] BYREF
  DWORD pdwType[3]; // [rsp+44h] [rbp+4h] BYREF
  WCHAR Filename[264]; // [rsp+50h] [rbp+10h] BYREF
  WCHAR ReturnedString[2048]; // [rsp+260h] [rbp+220h] BYREF

  if ( (a3 & 5) == 0 )
    return 2147942487LL;
  pcbData = 520;
  v7 = nullptr;
  if ( SHGetValueW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Shadow Defender", L"Path", pdwType, Filename, &pcbData) != 0 )
  {
    GetModuleFileNameW(nullptr, Filename, 0x104u);
    *wcsrchr(Filename, 0x5Cu) = 0;
  }
  wcscat_s(Filename, 0x104u, L"\\res.ini");
  GetPrivateProfileStringW(L"common", L"1015", &Default, ReturnedString, 0x1000u, Filename);
  if ( (a3 & 4) != 0 )
  {
    lstrcpynW(lpString1, ReturnedString, iMaxLength);
    return 0;
  }
  else
  {
    v9 = -1;
    do
      ++v9;
    while ( ReturnedString[v9] != 0 );
    v10 = v9 + 1;
    if ( (int)v9 + 1 <= 0x3FFFFFFF )
    {
      v11 = 2LL * (int)v9 + 2;
      v12 = v11 + 15;
      if ( v11 + 15 < v11 )
        v12 = 0xFFFFFFFFFFFFFF0LL;
      v13 = v12 & 0xFFFFFFFFFFFFFFF0uLL;
      v14 = alloca(v13);
      v15 = alloca(v13);
      p_pcbData = &pcbData;
      if ( &v17 != (__int64 *)-64LL )
      {
        LOBYTE(pcbData) = 0;
        if ( WideCharToMultiByte(3u, 0, ReturnedString, -1, (LPSTR)&pcbData, 2 * v10, nullptr, nullptr) == 0 )
          p_pcbData = nullptr;
        v7 = (const CHAR *)p_pcbData;
      }
    }
    lstrcpynA((LPSTR)lpString1, v7, iMaxLength);
    return 0;
  }
}


// ===== sub_1800018E0 @ 0x1800018e0 size=0x1b2 =====
__int64 __fastcall sub_1800018E0(__int64 a1, __int64 a2)
{
  _QWORD *v4; // r8
  int v5; // ebx
  _QWORD *i; // rax
  _QWORD *v7; // rdx
  __int64 v8; // rcx
  wchar_t *v9; // rax
  unsigned __int64 v10; // rsi
  wchar_t *v11; // rax
  wchar_t *v12; // rdi
  _QWORD *v13; // rcx
  _QWORD *v14; // rbx
  const wchar_t *v15; // r8
  WCHAR Filename[264]; // [rsp+30h] [rbp-228h] BYREF

  if ( *(_WORD *)(a2 + 18) != 0 || *(_WORD *)(a2 + 16) != 0 )
    return 2147942487LL;
  v4 = *(_QWORD **)(a1 + 16);
  v5 = 0;
  for ( i = (_QWORD *)*v4; i != v4; v5 += v8 + 1 )
  {
    v7 = i + 2;
    if ( i[5] >= 8u )
      v7 = (_QWORD *)*v7;
    v8 = -1;
    do
      ++v8;
    while ( *((_WORD *)v7 + v8) != 0 );
    i = (_QWORD *)*i;
  }
  GetModuleFileNameW(hModule, Filename, 0x104u);
  v9 = wcsrchr(Filename, 0x5Cu);
  if ( v9 != nullptr )
  {
    v9[1] = 0;
    wcscat_s(Filename, 0x104u, L"Commit.exe");
    v10 = v5 + 10LL;
    v11 = (wchar_t *)operator new(saturated_mul(v10, 2u));
    v12 = v11;
    if ( v11 != nullptr )
    {
      *v11 = 0;
      v13 = *(_QWORD **)(a1 + 16);
      v14 = (_QWORD *)*v13;
      if ( (_QWORD *)*v13 != v13 )
      {
        do
        {
          v15 = (const wchar_t *)(v14 + 2);
          if ( v14[5] >= 8u )
            v15 = *(const wchar_t **)v15;
          wcscat_s(v12, v10, v15);
          wcscat_s(v12, v10, L"|");
          v14 = (_QWORD *)*v14;
        }
        while ( v14 != *(_QWORD **)(a1 + 16) );
      }
      ShellExecuteW(nullptr, L"open", Filename, v12, nullptr, 5);
      j_j_j__free_base(v12);
    }
  }
  return 0;
}


// ===== sub_180001AA0 @ 0x180001aa0 size=0x247 =====
__int64 __fastcall sub_180001AA0(__int64 a1, HMENU a2, UINT a3, unsigned int a4, int a5, char a6)
{
  UINT_PTR v7; // r15
  _QWORD *v10; // r10
  int v11; // edi
  _QWORD *i; // rax
  _QWORD *v13; // rcx
  char v14; // r8
  unsigned __int16 v15; // bx
  HBITMAP v17; // r9
  DWORD pcbData; // [rsp+30h] [rbp-1488h] BYREF
  DWORD pdwType; // [rsp+34h] [rbp-1484h] BYREF
  _BYTE v20[4]; // [rsp+38h] [rbp-1480h] BYREF
  int v21; // [rsp+3Ch] [rbp-147Ch]
  WCHAR Filename[264]; // [rsp+50h] [rbp-1468h] BYREF
  WCHAR FileName[264]; // [rsp+260h] [rbp-1258h] BYREF
  WCHAR ReturnedString[2048]; // [rsp+470h] [rbp-1048h] BYREF

  v7 = a4;
  if ( (a6 & 1) != 0 )
    return 0;
  pcbData = 520;
  if ( SHGetValueW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Shadow Defender", L"Path", &pdwType, Filename, &pcbData) != 0 )
  {
    GetModuleFileNameW(hInst, Filename, 0x104u);
    *wcsrchr(Filename, 0x5Cu) = 0;
  }
  swprintf(FileName, 0x104u, L"%s\\user.dat", Filename);
  if ( GetPrivateProfileIntW(L"common", L"shellext", 1, FileName) == 0 )
    return 0;
  v10 = *(_QWORD **)(a1 + 16);
  v11 = 0;
  for ( i = (_QWORD *)*v10; i != v10; v11 |= 1 << (v14 - 67) )
  {
    v13 = i + 2;
    if ( i[5] >= 8u )
      v13 = (_QWORD *)*v13;
    i = (_QWORD *)*i;
    v14 = *(_WORD *)v13 - 32;
    if ( (unsigned __int16)(*(_WORD *)v13 - 97) > 0x19u )
      v14 = *(_WORD *)v13;
  }
  v15 = 67;
  while ( !_bittest(&v11, (unsigned __int8)(v15 - 67)) || (unsigned int)sub_180008D00(v15, v20) == 0 || v21 != 1 )
  {
    if ( ++v15 > 0x5Au )
      return 0;
  }
  swprintf(FileName, 0x104u, L"%s\\res.ini", Filename);
  GetPrivateProfileStringW(L"common", L"1014", &Default, ReturnedString, 0x1000u, FileName);
  InsertMenuW(a2, a3, 0x400u, v7, ReturnedString);
  v17 = *(HBITMAP *)(a1 + 1104);
  if ( v17 != nullptr )
    SetMenuItemBitmaps(a2, a3, 0x404u, v17, nullptr);
  return 1;
}


// ===== sub_180001CF0 @ 0x180001cf0 size=0x16d =====
__int64 __fastcall sub_180001CF0(__int64 a1, __int64 a2, _QWORD *a3)
{
  _QWORD *v3; // r14
  __int64 v4; // r12
  __int64 v5; // r15
  unsigned int v7; // edi
  _DWORD *v8; // rax
  _DWORD *v9; // rbx
  signed int v10; // edi
  signed int LastError; // eax
  int v12; // eax
  _DWORD *v13; // [rsp+20h] [rbp-58h]

  v3 = a3;
  v4 = a2;
  v5 = a1;
  if ( a3 == nullptr )
    return 2147500035LL;
  *a3 = 0;
  v7 = -2147024882;
  try
  {
    v8 = operator new(0x48u, (const struct std::nothrow_t *)&unk_18002A2B4);
    v9 = v8;
    __wind
    {
      if ( v8 != nullptr )
      {
        v8[2] = 0;
        *((_QWORD *)v8 + 2) = 0;
        *((_QWORD *)v8 + 3) = 0;
        *((_QWORD *)v8 + 4) = 0;
        *((_QWORD *)v8 + 5) = 0;
        *((_QWORD *)v8 + 6) = 0;
        *((_BYTE *)v8 + 56) = 0;
        __wind
        {
          *(_QWORD *)v8 = &ATL::CComClassFactory::`vftable';
        }
        __unwind
        {
          sub_1800022F0(v8 + 2);
        }
        __wind
        {
          *(_QWORD *)v8 = &ATL::CComObjectCached<ATL::CComClassFactory>::`vftable';
        }
        __unwind
        {
          sub_1800024B0(v8);
        }
      }
      else
      {
        v9 = nullptr;
      }
    }
    __unwind
    {
      j_j_j__free_base(v8);
    }
    v13 = v9;
  }
  catch ( ... )
  {
    v3 = a3;
    v4 = a2;
    v5 = a1;
    v7 = -2147024882;
    v9 = v13;
  }
  if ( v9 != nullptr )
  {
    *((_QWORD *)v9 + 8) = v5;
    v10 = 0;
    if ( !InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(v9 + 4), 0) )
    {
      LastError = GetLastError();
      v10 = LastError;
      if ( LastError > 0 )
        v10 = (unsigned __int16)LastError | 0x80070000;
    }
    if ( v10 >= 0 )
      *((_BYTE *)v9 + 56) = 1;
    v12 = 0;
    if ( v10 < 0 )
      v12 = v10;
    v7 = 0;
    if ( v12 < 0 )
      v7 = v12;
    if ( v7 != 0 || (v7 = (**(__int64 (__fastcall ***)(_DWORD *, __int64, _QWORD *))v9)(v9, v4, v3)) != 0 )
      (*(void (__fastcall **)(_DWORD *, __int64))(*(_QWORD *)v9 + 40LL))(v9, 1);
  }
  return v7;
}


// ===== sub_180001E60 @ 0x180001e60 size=0x21 =====
__int64 __fastcall sub_180001E60(__int64 a1, __int64 a2, _QWORD *a3)
{
  if ( a1 == 0 )
    return sub_1800030A0();
  if ( a3 == nullptr )
    return 2147500035LL;
  *a3 = 0;
  return 2147746064LL;
}


// ===== sub_180001E90 @ 0x180001e90 size=0x2c =====
__int64 __fastcall sub_180001E90(__int64 a1)
{
  unsigned __int32 v1; // ebx

  v1 = _InterlockedIncrement((volatile signed __int32 *)(a1 + 8));
  if ( v1 == 2 )
    (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_18002A148 + 8LL))(qword_18002A148);
  return v1;
}


// ===== sub_180001EC0 @ 0x180001ec0 size=0x46 =====
__int64 __fastcall sub_180001EC0(volatile signed __int32 *a1)
{
  unsigned __int32 v1; // ebx

  v1 = _InterlockedDecrement(a1 + 2);
  if ( v1 != 0 )
  {
    if ( v1 == 1 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_18002A148 + 16LL))(qword_18002A148);
  }
  else if ( a1 != nullptr )
  {
    (*(void (__fastcall **)(volatile signed __int32 *, __int64))(*(_QWORD *)a1 + 40LL))(a1, 1);
    return 0;
  }
  return v1;
}


// ===== sub_180001F10 @ 0x180001f10 size=0x12 =====
__int64 __fastcall sub_180001F10(__int64 a1, __int64 a2, __int64 a3)
{
  return sub_180003370(a1, &off_18001A548, a2, a3);
}


// ===== sub_180001F30 @ 0x180001f30 size=0x7c =====
_DWORD *__fastcall sub_180001F30(_DWORD *Block, char a2)
{
  char *v4; // rax

  *(_QWORD *)Block = &ATL::CComObjectCached<ATL::CComClassFactory>::`vftable';
  __wind
  {
    v4 = (char *)(Block + 2);
    Block[2] = -1073741823;
  }
  __unwind
  {
    sub_1800024B0(Block);
  }
  *(_QWORD *)Block = &ATL::CComClassFactory::`vftable';
  if ( v4[48] != 0 )
  {
    v4[48] = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(v4 + 8));
  }
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(Block);
  return Block;
}


// ===== sub_180001FB0 @ 0x180001fb0 size=0x9 =====
__int64 __fastcall sub_180001FB0(__int64 a1)
{
  __int64 result; // rax

  result = (unsigned int)(*(_DWORD *)(a1 + 24) + 1);
  *(_DWORD *)(a1 + 24) = result;
  return result;
}


// ===== sub_180001FC0 @ 0x180001fc0 size=0x5d =====
__int64 __fastcall sub_180001FC0(_DWORD *a1)
{
  bool v2; // zf
  unsigned int v3; // edi
  __int64 v5; // [rsp+28h] [rbp-10h] BYREF

  v2 = a1[6]-- == 1;
  v3 = a1[6];
  if ( v2 )
  {
    (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_18002A148 + 8LL))(qword_18002A148);
    __wind
    {
      if ( a1 != nullptr )
        (*(void (__fastcall **)(_DWORD *, __int64))(*(_QWORD *)a1 + 24LL))(a1, 1);
    }
    __unwind
    {
      sub_1800026C0(&v5);
    }
    (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_18002A148 + 16LL))(qword_18002A148);
  }
  return v3;
}


// ===== sub_180002020 @ 0x180002020 size=0x12 =====
__int64 __fastcall sub_180002020(__int64 a1, __int64 a2, __int64 a3)
{
  return sub_180003370(a1, &off_18001AAE0, a2, a3);
}


// ===== unknown_libname_20 @ 0x180002040 size=0x7c =====
// Microsoft VisualC v14 64bit runtime
_QWORD *__fastcall unknown_libname_20(_QWORD *Block, char a2)
{
  *Block = &ATL::CComObject<CContextMenuExt>::`vftable';
  Block[1] = &ATL::CComObject<CContextMenuExt>::`vftable';
  Block[2] = &ATL::CComObject<CContextMenuExt>::`vftable';
  __wind
  {
    *((_DWORD *)Block + 6) = -1073741823;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_18002A148 + 16LL))(qword_18002A148);
  }
  __unwind
  {
    sub_180002520(Block);
  }
  sub_180002520(Block);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(Block);
  return Block;
}


// ===== _guard_check_icall_nop @ 0x1800020c0 size=0x3 =====
void guard_check_icall_nop()
{
  ;
}


// ===== sub_1800020D0 @ 0x1800020d0 size=0x4e =====
__int64 __fastcall sub_1800020D0(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // rax

  result = sub_1800056D0();
  try
  {
    *(_QWORD *)(result + 32) = 0;
    *(_QWORD *)(result + 40) = 0;
    *(_OWORD *)(result + 16) = *(_OWORD *)a4;
    *(_OWORD *)(result + 32) = *(_OWORD *)(a4 + 16);
    *(_QWORD *)(a4 + 16) = 0;
    *(_QWORD *)(a4 + 24) = 7;
    *(_WORD *)a4 = 0;
  }
  catch ( ... )
  {
    sub_180005950(a1, result, 1);
    throw;
  }
  return result;
}


// ===== sub_180002120 @ 0x180002120 size=0x155 =====
__int64 __fastcall sub_180002120(__int64 a1)
{
  void *v2; // rax
  __int64 v3; // rax
  HICON ImageW; // rbx
  void *v6; // [rsp+30h] [rbp-158h]
  struct _OSVERSIONINFOW VersionInformation; // [rsp+50h] [rbp-138h] BYREF

  *(_DWORD *)(a1 + 24) = 0;
  *(_QWORD *)(a1 + 32) = 0;
  *(_QWORD *)(a1 + 40) = 0;
  *(_QWORD *)(a1 + 32) = sub_1800056D0(a1 + 32, 0, 0);
  __wind
  {
    *(_WORD *)(a1 + 48) = 0;
    *(_WORD *)(a1 + 588) = 0;
    *(_QWORD *)(a1 + 1112) = 0;
    *(_QWORD *)(a1 + 1120) = 0;
    VersionInformation.dwOSVersionInfoSize = 276;
    GetVersionExW(&VersionInformation);
    if ( VersionInformation.dwMajorVersion > 5 )
    {
      v2 = operator new(0x10u);
      v6 = v2;
      __wind
      {
        if ( v2 != nullptr )
          v3 = sub_180005B10(v2);
        else
          v3 = 0;
      }
      __unwind
      {
        j_j_j__free_base(v6);
      }
      *(_QWORD *)(a1 + 1112) = v3;
      ImageW = (HICON)LoadImageW(hInst, (LPCWSTR)0xD1, 1u, 16, 16, 0);
      *(_QWORD *)(a1 + 1120) = sub_180005E90(*(_QWORD *)(a1 + 1112), ImageW);
      DestroyIcon(ImageW);
    }
  }
  __unwind
  {
    sub_180002450(a1 + 32);
  }
  __wind
  {
    *(_QWORD *)a1 = &ATL::CComObject<CContextMenuExt>::`vftable';
    *(_QWORD *)(a1 + 8) = &ATL::CComObject<CContextMenuExt>::`vftable';
    *(_QWORD *)(a1 + 16) = &ATL::CComObject<CContextMenuExt>::`vftable';
    (*(void (__fastcall **)(__int64))(*(_QWORD *)qword_18002A148 + 8LL))(qword_18002A148);
  }
  __unwind
  {
    sub_180002520(a1);
  }
  return a1;
}


// ===== sub_180002280 @ 0x180002280 size=0x6 =====
_DWORD *__fastcall sub_180002280(_DWORD *a1, int a2)
{
  *a1 = a2;
  return a1;
}


// ===== sub_180002290 @ 0x180002290 size=0x3b =====
void __fastcall sub_180002290(_QWORD **a1)
{
  _QWORD *v2; // rcx

  while ( *a1 != nullptr )
  {
    v2 = *a1;
    *a1 = (_QWORD *)**a1;
    j__free_base(v2);
  }
}


// ===== sub_1800022D0 @ 0x1800022d0 size=0x1e =====
void __fastcall sub_1800022D0(void **a1)
{
  j_j_j__free_base(*a1);
  *a1 = nullptr;
}


// ===== sub_1800022F0 @ 0x1800022f0 size=0x31 =====
void __fastcall sub_1800022F0(__int64 a1)
{
  __int64 v1; // rcx

  v1 = a1 + 8;
  if ( *(_BYTE *)(v1 + 40) != 0 )
  {
    *(_BYTE *)(v1 + 40) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)v1);
  }
}


// ===== sub_180002330 @ 0x180002330 size=0x4b =====
void __fastcall sub_180002330(__int64 a1)
{
  void *v2; // rcx
  void *v3; // rcx

  v2 = *(void **)a1;
  if ( v2 != nullptr )
  {
    j__free_base(v2);
    *(_QWORD *)a1 = 0;
  }
  v3 = *(void **)(a1 + 8);
  if ( v3 != nullptr )
  {
    j__free_base(v3);
    *(_QWORD *)(a1 + 8) = 0;
  }
  *(_DWORD *)(a1 + 16) = 0;
}


// ===== sub_180002390 @ 0x180002390 size=0x1e =====
void __fastcall sub_180002390(void **a1)
{
  j_j_j__free_base(*a1);
}


// ===== sub_1800023B0 @ 0x1800023b0 size=0x23 =====
void __fastcall sub_1800023B0(void **a1)
{
  j_j_j__free_base(*a1);
}


// ===== sub_1800023E0 @ 0x1800023e0 size=0x6b =====
__int64 __fastcall sub_1800023E0(__int64 a1)
{
  unsigned __int64 v2; // rdx
  _QWORD *v3; // rcx

  v2 = *(_QWORD *)(a1 + 24);
  if ( v2 >= 8 )
  {
    v3 = *(_QWORD **)a1;
    if ( 2 * v2 + 2 >= 0x1000 )
    {
      if ( (unsigned __int64)v3 - *(v3 - 1) - 8 > 0x1F )
        invalid_parameter_noinfo_noreturn();
      v3 = (_QWORD *)*(v3 - 1);
    }
    j_j_j__free_base(v3);
  }
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 24) = 7;
  *(_WORD *)a1 = 0;
  return 0;
}


// ===== sub_180002450 @ 0x180002450 size=0x2e =====
void __fastcall sub_180002450(void **a1)
{
  __wind
  {
    sub_1800058D0(a1);
  }
  __unwind
  {
    sub_1800023B0(a1);
  }
  j_j_j__free_base(*a1);
}


// ===== sub_180002480 @ 0x180002480 size=0x28 =====
void __fastcall sub_180002480(__int64 a1)
{
  if ( *(_BYTE *)(a1 + 40) != 0 )
  {
    *(_BYTE *)(a1 + 40) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)a1);
  }
}


// ===== sub_1800024B0 @ 0x1800024b0 size=0x44 =====
void __fastcall sub_1800024B0(_QWORD *a1)
{
  _QWORD *v1; // rcx

  *a1 = &ATL::CComClassFactory::`vftable';
  v1 = a1 + 2;
  if ( *((_BYTE *)v1 + 40) != 0 )
  {
    *((_BYTE *)v1 + 40) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)v1);
  }
}


// ===== sub_180002520 @ 0x180002520 size=0x67 =====
void __fastcall sub_180002520(__int64 a1)
{
  void *v2; // rdi
  void **v3; // rbx

  __wind
  {
    v2 = *(void **)(a1 + 1112);
    if ( v2 != nullptr )
    {
      sub_180005BB0(*(_QWORD *)(a1 + 1112));
      j_j_j__free_base(v2);
    }
  }
  __unwind
  {
    sub_180002450((void **)(a1 + 32));
  }
  v3 = (void **)(a1 + 32);
  __wind
  {
    sub_1800058D0(v3);
  }
  __unwind
  {
    sub_1800023B0(v3);
  }
  j_j_j__free_base(*v3);
}


// ===== sub_180002590 @ 0x180002590 size=0x55 =====
void __fastcall sub_180002590(__int64 a1)
{
  void *v2; // rcx

  __wind
  {
    sub_180002FF0(a1);
  }
  __unwind
  {
    sub_180002330(a1);
  }
  if ( *(_QWORD *)a1 != 0 )
  {
    j__free_base(*(void **)a1);
    *(_QWORD *)a1 = 0;
  }
  v2 = *(void **)(a1 + 8);
  if ( v2 != nullptr )
  {
    j__free_base(v2);
    *(_QWORD *)(a1 + 8) = 0;
  }
  *(_DWORD *)(a1 + 16) = 0;
}


// ===== sub_1800025F0 @ 0x1800025f0 size=0x1d =====
void __fastcall sub_1800025F0(__int64 a1)
{
  CoTaskMemFree(*(LPVOID *)(a1 + 8));
}


// ===== sub_180002610 @ 0x180002610 size=0x30 =====
__int64 __fastcall sub_180002610(__int64 a1)
{
  HKEY v2; // rcx
  __int64 result; // rax

  v2 = *(HKEY *)a1;
  if ( v2 != nullptr )
  {
    RegCloseKey(v2);
    result = 0;
    *(_QWORD *)a1 = 0;
  }
  else
  {
    result = 0;
  }
  *(_DWORD *)(a1 + 8) = 0;
  return result;
}


// ===== sub_180002640 @ 0x180002640 size=0x71 =====
void __fastcall sub_180002640(_QWORD *a1)
{
  __int64 v1; // rbx
  void *v2; // rcx

  *a1 = &ATL::CRegObject::`vftable';
  __wind
  {
    v1 = (__int64)(a1 + 1);
    sub_180002FF0(a1 + 1);
  }
  __unwind
  {
    sub_180002590((__int64)(a1 + 1));
  }
  __wind
  {
    sub_180002FF0(v1);
  }
  __unwind
  {
    sub_180002330(v1);
  }
  if ( *(_QWORD *)v1 != 0 )
  {
    j__free_base(*(void **)v1);
    *(_QWORD *)v1 = 0;
  }
  v2 = *(void **)(v1 + 8);
  if ( v2 != nullptr )
  {
    j__free_base(v2);
    *(_QWORD *)(v1 + 8) = 0;
  }
  *(_DWORD *)(v1 + 16) = 0;
}


// ===== sub_1800026C0 @ 0x1800026c0 size=0x20 =====
__int64 sub_1800026C0()
{
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)qword_18002A148 + 16LL))(qword_18002A148);
}


// ===== sub_1800026E0 @ 0x1800026e0 size=0x1d3 =====
__int64 __fastcall sub_1800026E0(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // rax
  unsigned __int64 v7; // r12
  unsigned __int64 v8; // rax
  void *v9; // rax
  void *v10; // rdi
  __int64 v11; // rcx
  unsigned __int64 v12; // r15
  unsigned __int64 v13; // rax
  void *v14; // rax
  void *v15; // rbx
  void *v16; // rax
  void *v17; // rax
  __int64 v18; // rdx
  bool v19; // zf
  _QWORD *v20; // rcx
  __int64 v21; // rcx
  bool v22; // zf
  _QWORD *v23; // rcx
  unsigned int v24; // esi
  void *v26; // [rsp+20h] [rbp-58h] BYREF
  __int64 v27; // [rsp+28h] [rbp-50h]
  _QWORD *v28; // [rsp+30h] [rbp-48h]
  void *v29; // [rsp+98h] [rbp+20h] BYREF

  v27 = -2;
  if ( a2 == 0 || a3 == 0 )
    return 0;
  v6 = -1;
  do
    ++v6;
  while ( *(_WORD *)(a2 + 2 * v6) != 0 );
  v7 = 2 * v6 + 2;
  v8 = 2 * v7;
  if ( !is_mul_ok(v7, 2u) )
    v8 = -1;
  v9 = operator new(v8, (const struct std::nothrow_t *)&unk_18002A2B4);
  v10 = v9;
  v26 = nullptr;
  __wind
  {
    v26 = v9;
    v11 = -1;
    do
      ++v11;
    while ( *(_WORD *)(a3 + 2 * v11) != 0 );
    v12 = 2LL * ((int)v11 + 1);
    v13 = 4LL * ((int)v11 + 1);
    if ( !is_mul_ok(v12, 2u) )
      v13 = -1;
    v14 = operator new(v13, (const struct std::nothrow_t *)&unk_18002A2B4);
    v15 = v14;
    v29 = nullptr;
    __wind
    {
      v29 = v14;
      if ( v10 != nullptr
        && v14 != nullptr
        && (sub_1800059A0(v10, v7, a2, v7, v26, v27),
            sub_1800059A0(v15, v12, a3, v12, v26, v27),
            (v16 = j__recalloc_base(*(void **)a1, *(_DWORD *)(a1 + 16) + 1, 8u)) != nullptr)
        && (*(_QWORD *)a1 = v16, (v17 = j__recalloc_base(*(void **)(a1 + 8), *(_DWORD *)(a1 + 16) + 1, 8u)) != nullptr) )
      {
        *(_QWORD *)(a1 + 8) = v17;
        v18 = 8LL * *(int *)(a1 + 16);
        v19 = v18 + *(_QWORD *)a1 == 0;
        v20 = (_QWORD *)(v18 + *(_QWORD *)a1);
        v28 = v20;
        __wind
        {
          if ( !v19 )
            *v20 = v10;
        }
        __unwind
        {
        }
        v21 = *(_QWORD *)(a1 + 8);
        v22 = v18 + v21 == 0;
        v23 = (_QWORD *)(v18 + v21);
        v28 = v23;
        __wind
        {
          if ( !v22 )
            *v23 = v15;
        }
        __unwind
        {
        }
        ++*(_DWORD *)(a1 + 16);
        v10 = nullptr;
        v26 = nullptr;
        v15 = nullptr;
        v29 = nullptr;
        v24 = 1;
      }
      else
      {
        v24 = 0;
      }
    }
    __unwind
    {
      sub_1800022D0(&v29);
    }
    j_j_j__free_base(v15);
    v29 = nullptr;
  }
  __unwind
  {
    sub_1800022D0(&v26);
  }
  j_j_j__free_base(v10);
  v26 = nullptr;
  return v24;
}


// ===== sub_1800028C0 @ 0x1800028c0 size=0x5a7 =====
HRESULT __fastcall sub_1800028C0(LPCWSTR *a1, HKEY *a2, const WCHAR *a3, __int64 a4)
{
  const WCHAR *v4; // r13
  HKEY *v5; // r12
  LPCWSTR *v6; // r15
  HRESULT result; // eax
  int v8; // ebx
  WCHAR v9; // ax
  __int64 v10; // rax
  int v11; // eax
  int v12; // r14d
  BYTE *v13; // rdi
  WCHAR *i; // rbx
  const WCHAR *v15; // rax
  unsigned int v16; // ebx
  DWORD cbData; // r9d
  BYTE *v18; // r8
  __int64 v19; // rcx
  __int64 v20; // rcx
  int v21; // eax
  __int64 v22; // rbx
  int v23; // eax
  unsigned __int64 v24; // rdi
  unsigned __int64 v25; // rcx
  int v26; // r9d
  __int64 v27; // r8
  WCHAR v28; // dx
  char v29; // dl
  __int64 v30; // rsi
  ULONG pulOut; // [rsp+30h] [rbp-2198h] BYREF
  BYTE Data[8]; // [rsp+38h] [rbp-2190h] BYREF
  const WCHAR *v33; // [rsp+40h] [rbp-2188h] BYREF
  LPCWSTR *v34; // [rsp+48h] [rbp-2180h]
  HKEY *v35; // [rsp+50h] [rbp-2178h]
  __int64 v36; // [rsp+58h] [rbp-2170h]
  __int64 v37; // [rsp+60h] [rbp-2168h]
  BYTE *lpData; // [rsp+70h] [rbp-2158h] BYREF
  _BYTE v39[264]; // [rsp+78h] [rbp-2150h] BYREF
  WCHAR String1[4096]; // [rsp+180h] [rbp-2048h] BYREF

  v37 = -2;
  v4 = a3;
  v5 = a2;
  v6 = a1;
  v34 = a1;
  v35 = a2;
  v33 = a3;
  v36 = a4;
  result = sub_1800034B0(a1, String1);
  if ( result >= 0 )
  {
    if ( lstrcmpiW(String1, &String2) != 0 )
    {
      if ( lstrcmpiW(String1, &word_18001A610) != 0 )
      {
        if ( lstrcmpiW(String1, &word_18001A614) != 0 )
        {
          if ( lstrcmpiW(String1, &word_18001A618) != 0 )
            return -2147352567;
          v8 = 17;
        }
        else
        {
          v8 = 19;
        }
      }
      else
      {
        v8 = 16392;
      }
    }
    else
    {
      v8 = 8;
    }
    while ( 1 )
    {
      v9 = **v6;
      if ( v9 < 9u || v9 > 0xAu && v9 != 13 && v9 != 32 )
        break;
      *v6 = CharNextW(*v6);
    }
    result = sub_1800034B0(v6, String1);
    if ( result >= 0 )
    {
      if ( v8 == 8 )
      {
        v30 = -1;
        do
          ++v30;
        while ( String1[v30] != 0 );
        v16 = RegSetValueExW(*v5, v4, 0, 1u, (const BYTE *)String1, 2 * v30 + 2);
        v12 = 0;
LABEL_74:
        if ( v16 != 0 )
          return sub_180002FB0(v16);
        v21 = sub_1800034B0(v6, v36);
        if ( v21 < 0 )
          return v21;
        return v12;
      }
      if ( v8 == 17 )
      {
        v22 = -1;
        do
          ++v22;
        while ( String1[v22] != 0 );
        *(_DWORD *)Data = v22;
        if ( (v22 & 1) == 0 )
        {
          v23 = (int)v22 / 2;
          v24 = (int)v22 / 2;
          pulOut = (int)v22 / 2;
          v12 = 0;
          lpData = nullptr;
          __eh34_enter_wind_state(-1, 4);
          try
          {
            v25 = v23;
            if ( v23 != 0 )
            {
              if ( 0xFFFFFFFFFFFFFFFFuLL / v24 == 0 )
                sub_180002FC0(2147942934LL, 0xFFFFFFFFFFFFFFFFuLL % v24);
            }
            else
            {
              v25 = 0;
            }
            if ( v25 <= 0x100 )
              lpData = v39;
            else
              sub_180002E70(&lpData, v25);
          }
          catch ( ... )
          {
            v12 = 0;
            LODWORD(v22) = *(_DWORD *)Data;
            LODWORD(v24) = pulOut;
            v6 = v34;
            v5 = v35;
            v4 = v33;
          }
          if ( lpData != nullptr )
          {
            sub_180009D50(lpData, 0, (int)v24);
            if ( __eh34_unwind(4) )
            {
unwind_state_4:
              sub_180002380(&lpData);
              __eh34_propagate_exception_into_caller(4, -1);
            }
            __eh34_exit_wind_state(4, -1);
            v26 = 0;
            if ( (int)v22 > 0 )
            {
              v27 = 0;
              do
              {
                v28 = String1[v27];
                __eh34_enter_wind_state(-1, 0);
                switch ( v28 )
                {
                  case '0':
                  case '1':
                  case '2':
                  case '3':
                  case '4':
                  case '5':
                  case '6':
                  case '7':
                  case '8':
                  case '9':
                    if ( __eh34_unwind(0) )
                      goto unwind_state_0;
                    __eh34_exit_wind_state(0, -1);
                    __eh34_enter_wind_state(-1, 4);
                    v29 = v28 - 48;
                    if ( __eh34_unwind(4) )
                      goto unwind_state_4;
                    __eh34_exit_wind_state(4, -1);
                    break;
                  case 'A':
                  case 'B':
                  case 'C':
                  case 'D':
                  case 'E':
                  case 'F':
                    if ( __eh34_unwind(0) )
                      goto unwind_state_0;
                    __eh34_exit_wind_state(0, -1);
                    v29 = v28 - 55;
                    break;
                  case 'a':
                  case 'b':
                  case 'c':
                  case 'd':
                  case 'e':
                  case 'f':
                    if ( __eh34_unwind(0) )
                      goto unwind_state_0;
                    __eh34_exit_wind_state(0, -1);
                    v29 = v28 - 87;
                    break;
                  default:
                    if ( __eh34_unwind(0) )
                    {
unwind_state_0:
                      sub_180002380(&lpData);
                      __eh34_propagate_exception_into_caller(0, -1);
                    }
                    __eh34_exit_wind_state(0, -1);
                    v29 = 0;
                    break;
                }
                lpData[v26 / 2] |= v29 << (4 - 4 * (v26 & 1));
                ++v26;
                ++v27;
              }
              while ( v27 < (int)v22 );
            }
            v16 = RegSetValueExW(*v5, v4, 0, 3u, lpData, v24);
            if ( lpData == v39 )
              goto LABEL_74;
LABEL_43:
            sub_1800032F0(&lpData);
            goto LABEL_74;
          }
          if ( __eh34_unwind(4) )
            goto unwind_state_4;
          __eh34_exit_wind_state(4, -1);
          if ( lpData != v39 )
            sub_1800032F0(&lpData);
        }
        return -2147467259;
      }
      if ( v8 != 19 )
      {
        v10 = -1;
        do
          ++v10;
        while ( String1[v10] != 0 );
        v11 = v10 + 2;
        v12 = 0;
        lpData = nullptr;
        __eh34_enter_wind_state(-1, 0);
        try
        {
          if ( v11 == 0 )
            goto LABEL_26;
          if ( 0xFFFFFFFFFFFFFFFFuLL / v11 < 2 )
            sub_180002FC0(2147942934LL, 0xFFFFFFFFFFFFFFFFuLL % v11);
          if ( (unsigned __int64)(2LL * v11) > 0x100 )
            sub_180002E70(&lpData, 2LL * v11);
          else
LABEL_26:
            lpData = v39;
        }
        catch ( ... )
        {
          v12 = 0;
          v6 = v34;
          v5 = v35;
          v4 = v33;
        }
        v13 = lpData;
        if ( lpData != nullptr )
        {
          for ( i = String1; *i != 0; v13 += 2 )
          {
            v15 = CharNextW(i);
            if ( *i == 92 && *v15 == 48 )
            {
              *(_WORD *)v13 = 0;
              i = CharNextW(v15);
            }
            else
            {
              *(_WORD *)v13 = *i++;
            }
          }
          *(_DWORD *)v13 = 0;
          if ( lpData != nullptr )
          {
            cbData = 0;
            v18 = lpData;
            do
            {
              v19 = -1;
              do
                ++v19;
              while ( *(_WORD *)&v18[2 * v19] != 0 );
              v20 = (unsigned int)(v19 + 1);
              v18 += 2 * v20;
              cbData += 2 * v20;
            }
            while ( (_DWORD)v20 != 1 );
            v16 = RegSetValueExW(*v5, v4, 0, 7u, lpData, cbData);
          }
          else
          {
            v16 = 13;
          }
        }
        else
        {
          v16 = 14;
        }
        if ( __eh34_unwind(0) )
          goto unwind_state_0;
        __eh34_exit_wind_state(0, -1);
        if ( lpData == v39 )
          goto LABEL_74;
        goto LABEL_43;
      }
      v12 = 0;
      v33 = nullptr;
      __eh34_enter_wind_state(-1, 3);
      result = VarUI4FromStr(String1, 0, 0, &pulOut);
      if ( result >= 0 )
      {
        *(_DWORD *)Data = pulOut;
        v16 = RegSetValueExW(*v5, v4, 0, 4u, Data, 4u);
        if ( __eh34_unwind(3) )
          goto unwind_state_3;
        __eh34_exit_wind_state(3, -1);
        goto LABEL_74;
      }
      if ( __eh34_unwind(3) )
      {
unwind_state_3:
        sub_180002290((_QWORD **)&v33);
        __eh34_propagate_exception_into_caller(3, -1);
      }
      __eh34_exit_wind_state(3, -1);
    }
  }
  return result;
}


// ===== sub_1800028C0 @ 0x1800028c0 size=0x5a7 =====
HRESULT __fastcall sub_1800028C0(LPCWSTR *a1, HKEY *a2, const WCHAR *a3, __int64 a4)
{
  const WCHAR *v4; // r13
  HKEY *v5; // r12
  LPCWSTR *v6; // r15
  HRESULT result; // eax
  int v8; // ebx
  WCHAR v9; // ax
  __int64 v10; // rax
  int v11; // eax
  int v12; // r14d
  BYTE *v13; // rdi
  WCHAR *i; // rbx
  const WCHAR *v15; // rax
  unsigned int v16; // ebx
  DWORD cbData; // r9d
  BYTE *v18; // r8
  __int64 v19; // rcx
  __int64 v20; // rcx
  int v21; // eax
  __int64 v22; // rbx
  int v23; // eax
  unsigned __int64 v24; // rdi
  unsigned __int64 v25; // rcx
  int v26; // r9d
  __int64 v27; // r8
  WCHAR v28; // dx
  char v29; // dl
  __int64 v30; // rsi
  ULONG pulOut; // [rsp+30h] [rbp-2198h] BYREF
  BYTE Data[8]; // [rsp+38h] [rbp-2190h] BYREF
  const WCHAR *v33; // [rsp+40h] [rbp-2188h] BYREF
  LPCWSTR *v34; // [rsp+48h] [rbp-2180h]
  HKEY *v35; // [rsp+50h] [rbp-2178h]
  __int64 v36; // [rsp+58h] [rbp-2170h]
  __int64 v37; // [rsp+60h] [rbp-2168h]
  BYTE *lpData; // [rsp+70h] [rbp-2158h] BYREF
  _BYTE v39[264]; // [rsp+78h] [rbp-2150h] BYREF
  WCHAR String1[4096]; // [rsp+180h] [rbp-2048h] BYREF

  v37 = -2;
  v4 = a3;
  v5 = a2;
  v6 = a1;
  v34 = a1;
  v35 = a2;
  v33 = a3;
  v36 = a4;
  result = sub_1800034B0(a1, String1);
  if ( result >= 0 )
  {
    if ( lstrcmpiW(String1, &String2) != 0 )
    {
      if ( lstrcmpiW(String1, &word_18001A610) != 0 )
      {
        if ( lstrcmpiW(String1, &word_18001A614) != 0 )
        {
          if ( lstrcmpiW(String1, &word_18001A618) != 0 )
            return -2147352567;
          v8 = 17;
        }
        else
        {
          v8 = 19;
        }
      }
      else
      {
        v8 = 16392;
      }
    }
    else
    {
      v8 = 8;
    }
    while ( 1 )
    {
      v9 = **v6;
      if ( v9 < 9u || v9 > 0xAu && v9 != 13 && v9 != 32 )
        break;
      *v6 = CharNextW(*v6);
    }
    result = sub_1800034B0(v6, String1);
    if ( result >= 0 )
    {
      if ( v8 == 8 )
      {
        v30 = -1;
        do
          ++v30;
        while ( String1[v30] != 0 );
        v16 = RegSetValueExW(*v5, v4, 0, 1u, (const BYTE *)String1, 2 * v30 + 2);
        v12 = 0;
LABEL_74:
        if ( v16 != 0 )
          return sub_180002FB0(v16);
        v21 = sub_1800034B0(v6, v36);
        if ( v21 < 0 )
          return v21;
        return v12;
      }
      if ( v8 == 17 )
      {
        v22 = -1;
        do
          ++v22;
        while ( String1[v22] != 0 );
        *(_DWORD *)Data = v22;
        if ( (v22 & 1) == 0 )
        {
          v23 = (int)v22 / 2;
          v24 = (int)v22 / 2;
          pulOut = (int)v22 / 2;
          v12 = 0;
          lpData = nullptr;
          __eh34_enter_wind_state(-1, 4);
          try
          {
            v25 = v23;
            if ( v23 != 0 )
            {
              if ( 0xFFFFFFFFFFFFFFFFuLL / v24 == 0 )
                sub_180002FC0(2147942934LL, 0xFFFFFFFFFFFFFFFFuLL % v24);
            }
            else
            {
              v25 = 0;
            }
            if ( v25 <= 0x100 )
              lpData = v39;
            else
              sub_180002E70(&lpData, v25);
          }
          catch ( ... )
          {
            v12 = 0;
            LODWORD(v22) = *(_DWORD *)Data;
            LODWORD(v24) = pulOut;
            v6 = v34;
            v5 = v35;
            v4 = v33;
          }
          if ( lpData != nullptr )
          {
            sub_180009D50(lpData, 0, (int)v24);
            if ( __eh34_unwind(4) )
            {
unwind_state_4:
              sub_180002380(&lpData);
              __eh34_propagate_exception_into_caller(4, -1);
            }
            __eh34_exit_wind_state(4, -1);
            v26 = 0;
            if ( (int)v22 > 0 )
            {
              v27 = 0;
              do
              {
                v28 = String1[v27];
                __eh34_enter_wind_state(-1, 0);
                switch ( v28 )
                {
                  case '0':
                  case '1':
                  case '2':
                  case '3':
                  case '4':
                  case '5':
                  case '6':
                  case '7':
                  case '8':
                  case '9':
                    if ( __eh34_unwind(0) )
                      goto unwind_state_0;
                    __eh34_exit_wind_state(0, -1);
                    __eh34_enter_wind_state(-1, 4);
                    v29 = v28 - 48;
                    if ( __eh34_unwind(4) )
                      goto unwind_state_4;
                    __eh34_exit_wind_state(4, -1);
                    break;
                  case 'A':
                  case 'B':
                  case 'C':
                  case 'D':
                  case 'E':
                  case 'F':
                    if ( __eh34_unwind(0) )
                      goto unwind_state_0;
                    __eh34_exit_wind_state(0, -1);
                    v29 = v28 - 55;
                    break;
                  case 'a':
                  case 'b':
                  case 'c':
                  case 'd':
                  case 'e':
                  case 'f':
                    if ( __eh34_unwind(0) )
                      goto unwind_state_0;
                    __eh34_exit_wind_state(0, -1);
                    v29 = v28 - 87;
                    break;
                  default:
                    if ( __eh34_unwind(0) )
                    {
unwind_state_0:
                      sub_180002380(&lpData);
                      __eh34_propagate_exception_into_caller(0, -1);
                    }
                    __eh34_exit_wind_state(0, -1);
                    v29 = 0;
                    break;
                }
                lpData[v26 / 2] |= v29 << (4 - 4 * (v26 & 1));
                ++v26;
                ++v27;
              }
              while ( v27 < (int)v22 );
            }
            v16 = RegSetValueExW(*v5, v4, 0, 3u, lpData, v24);
            if ( lpData == v39 )
              goto LABEL_74;
LABEL_43:
            sub_1800032F0(&lpData);
            goto LABEL_74;
          }
          if ( __eh34_unwind(4) )
            goto unwind_state_4;
          __eh34_exit_wind_state(4, -1);
          if ( lpData != v39 )
            sub_1800032F0(&lpData);
        }
        return -2147467259;
      }
      if ( v8 != 19 )
      {
        v10 = -1;
        do
          ++v10;
        while ( String1[v10] != 0 );
        v11 = v10 + 2;
        v12 = 0;
        lpData = nullptr;
        __eh34_enter_wind_state(-1, 0);
        try
        {
          if ( v11 == 0 )
            goto LABEL_26;
          if ( 0xFFFFFFFFFFFFFFFFuLL / v11 < 2 )
            sub_180002FC0(2147942934LL, 0xFFFFFFFFFFFFFFFFuLL % v11);
          if ( (unsigned __int64)(2LL * v11) > 0x100 )
            sub_180002E70(&lpData, 2LL * v11);
          else
LABEL_26:
            lpData = v39;
        }
        catch ( ... )
        {
          v12 = 0;
          v6 = v34;
          v5 = v35;
          v4 = v33;
        }
        v13 = lpData;
        if ( lpData != nullptr )
        {
          for ( i = String1; *i != 0; v13 += 2 )
          {
            v15 = CharNextW(i);
            if ( *i == 92 && *v15 == 48 )
            {
              *(_WORD *)v13 = 0;
              i = CharNextW(v15);
            }
            else
            {
              *(_WORD *)v13 = *i++;
            }
          }
          *(_DWORD *)v13 = 0;
          if ( lpData != nullptr )
          {
            cbData = 0;
            v18 = lpData;
            do
            {
              v19 = -1;
              do
                ++v19;
              while ( *(_WORD *)&v18[2 * v19] != 0 );
              v20 = (unsigned int)(v19 + 1);
              v18 += 2 * v20;
              cbData += 2 * v20;
            }
            while ( (_DWORD)v20 != 1 );
            v16 = RegSetValueExW(*v5, v4, 0, 7u, lpData, cbData);
          }
          else
          {
            v16 = 13;
          }
        }
        else
        {
          v16 = 14;
        }
        if ( __eh34_unwind(0) )
          goto unwind_state_0;
        __eh34_exit_wind_state(0, -1);
        if ( lpData == v39 )
          goto LABEL_74;
        goto LABEL_43;
      }
      v12 = 0;
      v33 = nullptr;
      __eh34_enter_wind_state(-1, 3);
      result = VarUI4FromStr(String1, 0, 0, &pulOut);
      if ( result >= 0 )
      {
        *(_DWORD *)Data = pulOut;
        v16 = RegSetValueExW(*v5, v4, 0, 4u, Data, 4u);
        if ( __eh34_unwind(3) )
          goto unwind_state_3;
        __eh34_exit_wind_state(3, -1);
        goto LABEL_74;
      }
      if ( __eh34_unwind(3) )
      {
unwind_state_3:
        sub_180002290((_QWORD **)&v33);
        __eh34_propagate_exception_into_caller(3, -1);
      }
      __eh34_exit_wind_state(3, -1);
    }
  }
  return result;
}


// ===== sub_180002E70 @ 0x180002e70 size=0x2a =====
void *__fastcall sub_180002E70(_QWORD *a1, size_t a2)
{
  void *result; // rax
  __int64 v4; // rdx

  result = j__malloc_base(a2);
  if ( result == nullptr )
    sub_180002FC0(2147942414LL, v4);
  *a1 = result;
  return result;
}


// ===== sub_180002EA0 @ 0x180002ea0 (no pseudocode) =====

// ===== sub_180002F90 @ 0x180002f90 size=0x1b =====
signed int sub_180002F90()
{
  signed int result; // eax

  result = GetLastError();
  if ( result > 0 )
    return (unsigned __int16)result | 0x80070000;
  return result;
}


// ===== sub_180002FB0 @ 0x180002fb0 size=0x10 =====
__int64 __fastcall sub_180002FB0(int a1)
{
  if ( a1 > 0 )
    return (unsigned __int16)a1 | 0x80070000;
  else
    return (unsigned int)a1;
}


// ===== sub_180002FC0 @ 0x180002fc0 size=0x22 =====
void __fastcall __noreturn sub_180002FC0(int a1)
{
  int pExceptionObject; // [rsp+38h] [rbp+10h] BYREF

  sub_180002280(&pExceptionObject, a1);
  throw (ATL::CAtlException *)&pExceptionObject;
}


// ===== sub_180002FF0 @ 0x180002ff0 size=0xa7 =====
__int64 __fastcall sub_180002FF0(__int64 a1)
{
  int v1; // eax
  int v2; // edi
  __int64 v4; // rsi
  void *v5; // rcx

  v1 = *(_DWORD *)(a1 + 16);
  v2 = 0;
  if ( v1 > 0 )
  {
    v4 = 0;
    do
    {
      if ( v4 < 0 || v2 >= v1 || (j_j_j__free_base(*(void **)(v4 + *(_QWORD *)a1)), v2 >= *(_DWORD *)(a1 + 16)) )
      {
        sub_1800056C0(3221225612LL, 1);
        JUMPOUT(0x180003096LL);
      }
      j_j_j__free_base(*(void **)(*(_QWORD *)(a1 + 8) + v4));
      v1 = *(_DWORD *)(a1 + 16);
      ++v2;
      v4 += 8;
    }
    while ( v2 < v1 );
  }
  if ( *(_QWORD *)a1 != 0 )
  {
    j__free_base(*(void **)a1);
    *(_QWORD *)a1 = 0;
  }
  v5 = *(void **)(a1 + 8);
  if ( v5 != nullptr )
  {
    j__free_base(v5);
    *(_QWORD *)(a1 + 8) = 0;
  }
  *(_DWORD *)(a1 + 16) = 0;
  return 0;
}


// ===== sub_1800030A0 @ 0x1800030a0 size=0xd8 =====
__int64 __fastcall sub_1800030A0(__int64 a1, __int64 a2, _QWORD *a3)
{
  _QWORD *v3; // rdi
  __int64 v4; // r14
  _DWORD *v6; // rbx
  unsigned int v7; // esi
  void *v8; // rax
  _DWORD *v9; // [rsp+20h] [rbp-48h]
  void *v10; // [rsp+30h] [rbp-38h]

  v3 = a3;
  v4 = a2;
  if ( a3 == nullptr )
    return 2147500035LL;
  v6 = nullptr;
  *a3 = 0;
  v7 = -2147024882;
  try
  {
    v8 = operator new(0x468u, (const struct std::nothrow_t *)&unk_18002A2B4);
    v10 = v8;
    __wind
    {
      if ( v8 != nullptr )
        v6 = (_DWORD *)sub_180002120((__int64)v8);
    }
    __unwind
    {
      j_j_j__free_base(v10);
    }
    v9 = v6;
  }
  catch ( ... )
  {
    v3 = a3;
    v4 = a2;
    v7 = -2147024882;
    v6 = v9;
  }
  if ( v6 != nullptr )
  {
    v6[6] = v6[6];
    v7 = (**(__int64 (__fastcall ***)(_DWORD *, __int64, _QWORD *))v6)(v6, v4, v3);
    if ( v7 != 0 )
      (*(void (__fastcall **)(_DWORD *, __int64))(*(_QWORD *)v6 + 24LL))(v6, 1);
  }
  return v7;
}


// ===== sub_180003180 @ 0x180003180 size=0x12f =====
LSTATUS __fastcall sub_180003180(__int64 a1, const WCHAR *a2)
{
  __int64 v2; // rdi
  const WCHAR *v3; // rsi
  HKEY v5; // rbx
  HMODULE ModuleHandleW; // rax
  LSTATUS (__stdcall *RegDeleteKeyTransactedW)(HKEY, LPCWSTR, REGSAM, DWORD, HANDLE, PVOID); // rax
  HKEY v9; // rcx
  HMODULE v10; // rax
  LSTATUS (__stdcall *RegDeleteKeyExW)(HKEY, LPCWSTR, REGSAM, DWORD); // rax

  v2 = *(_QWORD *)(a1 + 16);
  v3 = a2;
  if ( v2 != 0 )
  {
    v5 = *(HKEY *)a1;
    if ( *(_QWORD *)v2 != 0 )
    {
      ModuleHandleW = GetModuleHandleW(L"Advapi32.dll");
      if ( ModuleHandleW != nullptr )
      {
        RegDeleteKeyTransactedW = (LSTATUS (__stdcall *)(HKEY, LPCWSTR, REGSAM, DWORD, HANDLE, PVOID))GetProcAddress(ModuleHandleW, "RegDeleteKeyTransactedW");
        if ( RegDeleteKeyTransactedW != nullptr )
          return ((__int64 (__fastcall *)(HKEY, const WCHAR *, _QWORD, _QWORD, _QWORD, _QWORD))RegDeleteKeyTransactedW)(
                   v5,
                   v3,
                   0,
                   0,
                   *(_QWORD *)v2,
                   0);
      }
    }
    else if ( *(_DWORD *)(v2 + 8) != 0 )
    {
      v9 = *(HKEY *)a1;
      return RegDeleteKeyW(v9, a2);
    }
    return 1;
  }
  if ( byte_18002A158 != 0 )
  {
    RegDeleteKeyExW = (LSTATUS (__stdcall *)(HKEY, LPCWSTR, REGSAM, DWORD))qword_18002A150;
  }
  else
  {
    v10 = GetModuleHandleW(L"Advapi32.dll");
    if ( v10 != nullptr )
    {
      RegDeleteKeyExW = (LSTATUS (__stdcall *)(HKEY, LPCWSTR, REGSAM, DWORD))GetProcAddress(v10, "RegDeleteKeyExW");
      qword_18002A150 = (__int64)RegDeleteKeyExW;
    }
    else
    {
      RegDeleteKeyExW = (LSTATUS (__stdcall *)(HKEY, LPCWSTR, REGSAM, DWORD))qword_18002A150;
    }
    byte_18002A158 = 1;
  }
  v9 = *(HKEY *)a1;
  a2 = v3;
  if ( RegDeleteKeyExW == nullptr )
    return RegDeleteKeyW(v9, a2);
  return ((__int64 (__fastcall *)(HKEY, const WCHAR *, _QWORD, _QWORD))RegDeleteKeyExW)(
           v9,
           v3,
           *(unsigned int *)(a1 + 8),
           0);
}


// ===== sub_1800032B0 @ 0x1800032b0 size=0x31 =====
_BOOL8 __fastcall sub_1800032B0(const WCHAR **a1)
{
  const WCHAR *v1; // rcx

  v1 = *a1;
  return *v1 == 39 && *CharNextW(v1) != 39;
}


// ===== sub_1800032F0 @ 0x1800032f0 size=0x8 =====
void __fastcall sub_1800032F0(void **a1)
{
  j__free_base(*a1);
}


// ===== sub_180003300 @ 0x180003300 size=0x64 =====
__int64 __fastcall sub_180003300(__int64 a1, HKEY a2)
{
  unsigned int v2; // ebx
  DWORD v4; // [rsp+80h] [rbp+18h] BYREF

  v2 = 0;
  v4 = 0;
  if ( RegQueryInfoKeyW(
         a2,
         nullptr,
         nullptr,
         nullptr,
         &v4,
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         nullptr) != 0 )
    return 0;
  LOBYTE(v2) = v4 != 0;
  return v2;
}


// ===== sub_180003370 @ 0x180003370 size=0x13d =====
__int64 __fastcall sub_180003370(__int64 a1, __int64 a2, _DWORD *a3, _QWORD *a4)
{
  __int64 result; // rax
  __int64 v8; // rbx
  _QWORD *v9; // rdi
  _DWORD *v10; // rbx
  __int64 v11; // rbx

  if ( a1 == 0 || a2 == 0 )
    return 2147942487LL;
  if ( a4 == nullptr )
    return 2147500035LL;
  if ( *a3 == 0 && a3[1] == 0 && a3[2] == 192 && a3[3] == 1174405120 )
  {
    v8 = a1 + *(_QWORD *)(a2 + 8);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 8LL))(v8);
    *a4 = v8;
    return 0;
  }
  v9 = (_QWORD *)(a2 + 16);
  if ( *(_QWORD *)(a2 + 16) == 0 )
  {
LABEL_21:
    result = 2147500034LL;
LABEL_22:
    *a4 = 0;
    return result;
  }
  while ( 1 )
  {
    v10 = (_DWORD *)*(v9 - 2);
    if ( v10 == nullptr || *v10 == *a3 && v10[1] == a3[1] && v10[2] == a3[2] && v10[3] == a3[3] )
    {
      if ( *v9 == 1 )
        break;
      result = ((__int64 (__fastcall *)(__int64, _DWORD *, _QWORD *, _QWORD))*v9)(a1, a3, a4, *(v9 - 1));
      if ( (_DWORD)result == 0 )
        return 0;
      if ( v10 != nullptr && (int)result < 0 )
        goto LABEL_22;
    }
    v9 += 3;
    if ( *v9 == 0 )
      goto LABEL_21;
  }
  v11 = a1 + *(v9 - 1);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v11 + 8LL))(v11);
  *a4 = v11;
  return 0;
}


// ===== sub_1800034B0 @ 0x1800034b0 size=0x1d6 =====
__int64 __fastcall sub_1800034B0(LPCWSTR *a1, char *a2)
{
  const WCHAR *v4; // rdi
  unsigned __int64 v5; // rax
  char *v6; // rbp
  LPWSTR v7; // rdx
  WCHAR v8; // ax
  const WCHAR *v9; // rdi
  LPWSTR v10; // rax
  __int64 v11; // r8
  signed __int64 v12; // rdi
  __int64 i; // rcx
  __int64 v15; // r14
  LPWSTR v16; // rax
  __int64 v17; // r8
  LPCWSTR v18; // r9
  signed __int64 v19; // rdi
  __int64 j; // rcx

  while ( 1 )
  {
    v4 = *a1;
    v5 = **a1;
    if ( (unsigned __int16)v5 < 9u || (unsigned __int16)v5 > 0xAu && (_WORD)v5 != 13 && (_WORD)v5 != 32 )
      break;
    *a1 = CharNextW(*a1);
  }
  if ( (_WORD)v5 == 0 )
    return 2147614729LL;
  v6 = a2;
  if ( (_WORD)v5 == 39 )
  {
    v7 = CharNextW(*a1);
    *a1 = v7;
    v8 = *v7;
    if ( *v7 != 0 )
    {
      while ( v8 != 39 || *CharNextW(v7) == 39 )
      {
        v9 = *a1;
        if ( **a1 == 39 )
        {
          v9 = CharNextW(*a1);
          *a1 = v9;
        }
        v10 = CharNextW(v9);
        *a1 = v10;
        v7 = v10;
        v11 = v10 - v9;
        if ( &a2[2 * v11 + 2] >= v6 + 0x2000 )
          return 2147614729LL;
        if ( (int)v11 > 0 )
        {
          v12 = (char *)v9 - a2;
          for ( i = (unsigned int)v11; i != 0; --i )
          {
            *(_WORD *)a2 = *(_WORD *)&a2[v12];
            a2 += 2;
          }
          v7 = (LPWSTR)*a1;
        }
        v8 = *v7;
        if ( *v7 == 0 )
          break;
      }
    }
    if ( **a1 != 0 )
    {
      *(_WORD *)a2 = 0;
      *a1 = CharNextW(*a1);
      return 0;
    }
    return 2147614729LL;
  }
  v15 = 0x100002600LL;
  do
  {
    if ( (unsigned __int16)v5 <= 0x20u && _bittest64(&v15, v5) )
      break;
    v16 = CharNextW(v4);
    *a1 = v16;
    v17 = v16 - v4;
    v18 = v16;
    if ( &a2[2 * v17 + 2] >= v6 + 0x2000 )
      return 2147614729LL;
    if ( (int)v17 > 0 )
    {
      v19 = (char *)v4 - a2;
      for ( j = (unsigned int)v17; j != 0; --j )
      {
        *(_WORD *)a2 = *(_WORD *)&a2[v19];
        a2 += 2;
      }
      v18 = *a1;
    }
    v5 = *v18;
    v4 = v18;
  }
  while ( (_WORD)v5 != 0 );
  *(_WORD *)a2 = 0;
  return 0;
}


// ===== sub_180003690 @ 0x180003690 size=0xf5 =====
LSTATUS __fastcall sub_180003690(__int64 a1, HKEY a2, const WCHAR *a3, REGSAM a4)
{
  __int64 v4; // rsi
  LSTATUS v5; // ebp
  HMODULE ModuleHandleW; // rax
  LSTATUS result; // eax
  LSTATUS (__stdcall *RegOpenKeyTransactedW)(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY, HANDLE, PVOID); // r10
  HKEY phkResult; // [rsp+60h] [rbp+8h] BYREF

  v4 = *(_QWORD *)(a1 + 16);
  v5 = 0;
  phkResult = nullptr;
  if ( v4 == 0 )
  {
LABEL_9:
    result = RegOpenKeyExW(a2, a3, 0, a4, &phkResult);
    goto LABEL_10;
  }
  if ( *(_QWORD *)v4 == 0 )
  {
    if ( *(_DWORD *)(v4 + 8) == 0 )
    {
      result = 1;
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  ModuleHandleW = GetModuleHandleW(L"Advapi32.dll");
  if ( ModuleHandleW != nullptr )
  {
    RegOpenKeyTransactedW = (LSTATUS (__stdcall *)(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY, HANDLE, PVOID))GetProcAddress(ModuleHandleW, "RegOpenKeyTransactedW");
    if ( RegOpenKeyTransactedW != nullptr )
      result = ((__int64 (__fastcall *)(HKEY, const WCHAR *, _QWORD, _QWORD, HKEY *, _QWORD, _QWORD))RegOpenKeyTransactedW)(
                 a2,
                 a3,
                 0,
                 a4,
                 &phkResult,
                 *(_QWORD *)v4,
                 0);
    else
      result = 1;
  }
  else
  {
    result = 1;
  }
LABEL_10:
  if ( result == 0 )
  {
    if ( *(_QWORD *)a1 != 0 )
      v5 = RegCloseKey(*(HKEY *)a1);
    *(_QWORD *)a1 = phkResult;
    *(_DWORD *)(a1 + 8) = a4 & 0x300;
    return v5;
  }
  return result;
}


// ===== sub_180003790 @ 0x180003790 size=0x416 =====
__int64 __fastcall sub_180003790(__int64 a1, const wchar_t *a2, _QWORD *a3)
{
  const wchar_t *v3; // rdi
  unsigned int v5; // r14d
  __int64 v6; // rax
  int v7; // eax
  unsigned __int64 v8; // rcx
  _WORD *v9; // rax
  char v10; // al
  int v11; // r13d
  char v12; // bp
  char v13; // r12
  int v14; // esi
  wchar_t *v15; // rax
  const WCHAR *v16; // rax
  const WCHAR *v17; // rax
  const WCHAR *v18; // rax
  LPWSTR v19; // rax
  int v20; // eax
  LPWSTR v21; // rax
  int v22; // eax
  LPCWSTR v23; // rdx
  LPWSTR v24; // rax
  __int64 v26; // rax
  WCHAR *v27; // r15
  __int64 v28; // rax
  errno_t v29; // eax
  __int64 v30; // rbp
  int v31; // esi
  __int64 v32; // rdi
  __int64 v33; // rax
  __int64 v34; // rdx
  __int64 v35; // r8
  int v36; // eax
  LPWSTR v37; // rax
  LPVOID v38; // rax
  char v39; // [rsp+20h] [rbp-C8h]
  char v40; // [rsp+21h] [rbp-C7h]
  __int64 v41; // [rsp+28h] [rbp-C0h] BYREF
  LPVOID pv; // [rsp+30h] [rbp-B8h]
  _QWORD *v43; // [rsp+38h] [rbp-B0h]
  __int64 v44; // [rsp+40h] [rbp-A8h]
  _QWORD *v45; // [rsp+48h] [rbp-A0h] BYREF
  _QWORD *v46; // [rsp+50h] [rbp-98h] BYREF
  _QWORD *v47; // [rsp+58h] [rbp-90h] BYREF
  WCHAR String2[32]; // [rsp+60h] [rbp-88h] BYREF

  v44 = -2;
  v43 = a3;
  v3 = a2;
  if ( a2 == nullptr || a3 == nullptr )
    return 2147500035LL;
  v5 = 0;
  *a3 = 0;
  v6 = -1;
  do
    ++v6;
  while ( a2[v6] != 0 );
  v7 = 2 * v6;
  if ( v7 < 100 )
    v7 = 1000;
  LODWORD(v41) = 0;
  HIDWORD(v41) = v7;
  v8 = 2LL * (unsigned int)v7;
  if ( v8 > 0xFFFFFFFF )
  {
    v9 = nullptr;
    pv = nullptr;
  }
  else
  {
    v9 = CoTaskMemAlloc((unsigned int)v8);
    pv = v9;
    if ( v9 != nullptr )
      *v9 = 0;
  }
  __wind
  {
    if ( v9 == nullptr )
    {
LABEL_39:
      v5 = -2147024882;
      goto LABEL_76;
    }
    *(_QWORD *)a1 = v3;
    v10 = byte_18002A140;
    v40 = byte_18002A140;
    v11 = 0;
    v12 = 0;
    v39 = 0;
    v13 = 0;
    if ( *v3 != 0 )
    {
      while ( 1 )
      {
        v14 = v11;
        if ( v10 != 1 )
          goto LABEL_35;
        if ( v11 == 0 )
        {
          v15 = wcsstr(v3, L"HKCR");
          if ( v15 != nullptr && v15 == *(wchar_t **)a1 )
          {
            v16 = CharNextW(*(LPCWSTR *)a1);
            *(_QWORD *)a1 = v16;
            v17 = CharNextW(v16);
            *(_QWORD *)a1 = v17;
            v18 = CharNextW(v17);
            *(_QWORD *)a1 = v18;
            v19 = CharNextW(v18);
            *(_QWORD *)a1 = v19;
            v45 = nullptr;
            __wind
            {
              v20 = sub_180002EA0(&v41, L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses", 31);
            }
            __unwind
            {
              sub_180002290(&v45);
            }
            if ( v20 == 0 )
              goto LABEL_39;
            v12 = 1;
            v39 = 1;
          }
        }
        if ( **(_WORD **)a1 != 39 )
          goto LABEL_26;
        if ( v13 == 0 )
        {
          v13 = 1;
          goto LABEL_35;
        }
        if ( !sub_1800032B0((const WCHAR **)a1) )
          break;
        v13 = 0;
LABEL_27:
        ++v11;
        if ( **(_WORD **)a1 != 123 )
          v11 = v14;
        if ( **(_WORD **)a1 == 125 && --v11 == 0 && v12 == 1 )
        {
          v46 = nullptr;
          __wind
          {
            v22 = sub_180002EA0(&v41, L"\r\n\t}\r\n}\r\n", 9);
          }
          __unwind
          {
            sub_180002290(&v46);
          }
          if ( v22 == 0 )
            goto LABEL_39;
          v12 = 0;
          v39 = 0;
        }
LABEL_35:
        v23 = *(LPCWSTR *)a1;
        if ( **(_WORD **)a1 != 37 )
          goto LABEL_38;
        v24 = CharNextW(*(LPCWSTR *)a1);
        *(_QWORD *)a1 = v24;
        if ( *v24 == 37 )
        {
          v23 = v24;
LABEL_38:
          if ( (unsigned int)sub_180002EA0(&v41, v23, 1) == 0 )
            goto LABEL_39;
          goto LABEL_63;
        }
        v26 = sub_180005280(v24, 37);
        v27 = (WCHAR *)v26;
        if ( v26 == 0 )
          goto LABEL_51;
        v28 = (v26 - *(_QWORD *)a1) >> 1;
        if ( v28 > 31 )
        {
          v5 = -2147467259;
          goto LABEL_76;
        }
        v29 = wcsncpy_s(String2, 0x20u, *(const wchar_t **)a1, (int)v28);
        if ( v29 != 0 )
        {
          if ( v29 == 12 )
            sub_180002FC0(-2147024882);
          if ( v29 == 22 || v29 == 34 )
            sub_180002FC0(-2147024809);
          if ( v29 != 80 )
            sub_180002FC0(-2147467259);
        }
        v30 = *(_QWORD *)(a1 + 8);
        v31 = 0;
        v32 = 0;
        if ( *(int *)(v30 + 24) <= 0 )
          goto LABEL_51;
        while ( lstrcmpiW(*(LPCWSTR *)(*(_QWORD *)(v30 + 8) + 8 * v32), String2) != 0 )
        {
          ++v31;
          ++v32;
          if ( v31 >= *(_DWORD *)(v30 + 24) )
            goto LABEL_51;
        }
        if ( v32 == -1 )
          goto LABEL_51;
        if ( v32 < 0 || v31 >= *(_DWORD *)(v30 + 24) )
        {
          sub_1800056C0(3221225612LL, 1);
          __debugbreak();
        }
        v33 = *(_QWORD *)(v30 + 16);
        v34 = *(_QWORD *)(v33 + 8 * v32);
        if ( v34 == 0 )
        {
LABEL_51:
          v5 = -2147352567;
          goto LABEL_76;
        }
        v47 = nullptr;
        __wind
        {
          v35 = -1;
          do
            ++v35;
          while ( *(_WORD *)(v34 + 2 * v35) != 0 );
          v36 = sub_180002EA0(&v41, v34, v35);
        }
        __unwind
        {
          sub_180002290(&v47);
        }
        if ( v36 == 0 )
          goto LABEL_39;
        if ( *(WCHAR **)a1 != v27 )
        {
          do
          {
            v37 = CharNextW(*(LPCWSTR *)a1);
            *(_QWORD *)a1 = v37;
          }
          while ( v37 != v27 );
        }
        v12 = v39;
LABEL_63:
        v3 = CharNextW(*(LPCWSTR *)a1);
        *(_QWORD *)a1 = v3;
        if ( *v3 == 0 )
          goto LABEL_66;
        v10 = v40;
      }
      v21 = CharNextW(*(LPCWSTR *)a1);
      *(_QWORD *)a1 = v21;
      if ( (unsigned int)sub_180002EA0(&v41, v21, 1) == 0 )
        goto LABEL_39;
LABEL_26:
      if ( v13 != 0 )
        goto LABEL_35;
      goto LABEL_27;
    }
LABEL_66:
    v38 = pv;
    pv = nullptr;
    v41 = 0;
    *v43 = v38;
  }
  __unwind
  {
    sub_1800025F0((__int64)&v41);
  }
LABEL_76:
  CoTaskMemFree(pv);
  return v5;
}


// ===== sub_180003BB0 @ 0x180003bb0 size=0x165 =====
__int64 __fastcall sub_180003BB0(__int64 a1, const WCHAR *a2)
{
  unsigned int v4; // ebx
  DWORD cchName; // [rsp+40h] [rbp-258h] BYREF
  HKEY hKey; // [rsp+48h] [rbp-250h] BYREF
  int v8; // [rsp+50h] [rbp-248h]
  __int64 v9; // [rsp+58h] [rbp-240h]
  struct _FILETIME ftLastWriteTime; // [rsp+60h] [rbp-238h] BYREF
  __int64 v11; // [rsp+68h] [rbp-230h]
  WCHAR Name[256]; // [rsp+70h] [rbp-228h] BYREF

  v11 = -2;
  hKey = nullptr;
  v8 = 0;
  v9 = 0;
  __wind
  {
    v4 = sub_180003690((__int64)&hKey, *(HKEY *)a1, a2, *(_DWORD *)(a1 + 8) | 0x2001F);
    if ( v4 == 0 )
    {
      cchName = 256;
      if ( RegEnumKeyExW(hKey, 0, Name, &cchName, nullptr, nullptr, nullptr, &ftLastWriteTime) != 0 )
      {
LABEL_6:
        if ( hKey != nullptr )
        {
          RegCloseKey(hKey);
          hKey = nullptr;
        }
        v8 = 0;
        v4 = sub_180003180(a1, a2);
      }
      else
      {
        while ( 1 )
        {
          v4 = sub_180003BB0(&hKey, Name);
          if ( v4 != 0 )
            break;
          cchName = 256;
          if ( RegEnumKeyExW(hKey, 0, Name, &cchName, nullptr, nullptr, nullptr, &ftLastWriteTime) != 0 )
            goto LABEL_6;
        }
      }
    }
  }
  __unwind
  {
    sub_180002610((__int64)&hKey);
  }
  if ( hKey != nullptr )
  {
    RegCloseKey(hKey);
    hKey = nullptr;
  }
  v8 = 0;
  return v4;
}


// ===== sub_180003D20 @ 0x180003d20 size=0x4d8 =====
__int64 __fastcall sub_180003D20(LPCWSTR *a1, const wchar_t *a2, int a3)
{
  __int64 result; // rax
  int v6; // ebx
  _WORD *v7; // r15
  WCHAR *v8; // rbx
  const WCHAR *v9; // rdi
  unsigned __int64 v10; // rax
  LPWSTR v11; // rdx
  WCHAR v12; // ax
  const WCHAR *v13; // rdi
  LPWSTR v14; // rax
  LPWSTR v15; // rax
  __int64 i; // rcx
  signed __int64 v17; // rdi
  const WCHAR *v18; // rcx
  __int64 v19; // rcx
  LPWSTR v20; // rax
  const WCHAR *v21; // r8
  __int64 v22; // rdx
  signed __int64 v23; // rdi
  __int64 j; // rcx
  unsigned int v25; // ebx
  LPCWSTR *v26; // rdi
  __int64 v27; // rbp
  __int64 v28; // rbp
  WCHAR *v29; // rbx
  const WCHAR *v30; // rdi
  unsigned __int64 v31; // rax
  LPWSTR v32; // rdx
  WCHAR v33; // ax
  const WCHAR *v34; // rdi
  LPWSTR v35; // rax
  LPWSTR v36; // rax
  __int64 k; // rcx
  signed __int64 v38; // rdi
  const WCHAR *v39; // rcx
  __int64 v40; // rcx
  LPWSTR v41; // rax
  const WCHAR *v42; // r8
  __int64 v43; // rdx
  signed __int64 v44; // rdi
  __int64 m; // rcx
  LPCWSTR v46; // rdi
  WCHAR v47; // ax
  LPVOID pv[2]; // [rsp+30h] [rbp-2058h] BYREF
  WCHAR String1[4096]; // [rsp+40h] [rbp-2048h] BYREF
  WCHAR v50[8]; // [rsp+2040h] [rbp-48h] BYREF

  pv[0] = nullptr;
  result = sub_180003790((__int64)a1, a2, pv);
  v6 = result;
  if ( (int)result < 0 )
    return result;
  v7 = pv[0];
  *a1 = (LPCWSTR)pv[0];
  if ( *v7 == 0 )
    goto LABEL_35;
  while ( 1 )
  {
    v8 = String1;
    while ( 1 )
    {
      v9 = *a1;
      v10 = **a1;
      if ( (unsigned __int16)v10 < 9u || (unsigned __int16)v10 > 0xAu && (_WORD)v10 != 13 && (_WORD)v10 != 32 )
        break;
      *a1 = CharNextW(*a1);
    }
    if ( (_WORD)v10 == 0 )
    {
LABEL_34:
      v6 = -2147352567;
      goto LABEL_35;
    }
    if ( (_WORD)v10 == 39 )
    {
      v11 = CharNextW(*a1);
      *a1 = v11;
      v12 = *v11;
      if ( *v11 != 0 )
      {
        while ( v12 != 39 || *CharNextW(v11) == 39 )
        {
          v13 = *a1;
          if ( **a1 == 39 )
          {
            v14 = CharNextW(*a1);
            *a1 = v14;
            v13 = v14;
          }
          v15 = CharNextW(v13);
          *a1 = v15;
          i = v15 - v13;
          v11 = v15;
          if ( &v8[i + 1] >= v50 )
            goto LABEL_34;
          if ( (int)i > 0 )
          {
            v17 = (char *)v13 - (char *)v8;
            for ( i = (unsigned int)i; i != 0; --i )
            {
              *v8 = *(WCHAR *)((char *)v8 + v17);
              ++v8;
            }
          }
          v12 = *v15;
          if ( *v11 == 0 )
            break;
        }
      }
      v18 = *a1;
      if ( **a1 == 0 )
        goto LABEL_34;
      *v8 = 0;
      *a1 = CharNextW(v18);
    }
    else
    {
      do
      {
        if ( (unsigned __int16)v10 <= 0x20u )
        {
          v19 = 0x100002600LL;
          if ( _bittest64(&v19, v10) )
            break;
        }
        v20 = CharNextW(v9);
        *a1 = v20;
        v21 = v20;
        v22 = v20 - v9;
        if ( &v8[v22 + 1] >= v50 )
          goto LABEL_34;
        if ( (int)v22 > 0 )
        {
          v23 = (char *)v9 - (char *)v8;
          for ( j = (unsigned int)v22; j != 0; --j )
          {
            *v8 = *(WCHAR *)((char *)v8 + v23);
            ++v8;
          }
        }
        v10 = *v20;
        v9 = v21;
      }
      while ( (_WORD)v10 != 0 );
      *v8 = 0;
    }
    v25 = 0;
    v26 = (LPCWSTR *)&off_18001A7F0;
    v27 = 0;
    while ( lstrcmpiW(String1, *v26) != 0 )
    {
      ++v25;
      ++v27;
      v26 += 2;
      if ( v25 >= 0xE )
        goto LABEL_34;
    }
    v28 = (__int64)*(&off_18001A7F0 + 2 * v27 + 1);
    if ( v28 == 0 )
      goto LABEL_34;
    v29 = String1;
    while ( 1 )
    {
      v30 = *a1;
      v31 = **a1;
      if ( (unsigned __int16)v31 < 9u || (unsigned __int16)v31 > 0xAu && (_WORD)v31 != 13 && (_WORD)v31 != 32 )
        break;
      *a1 = CharNextW(*a1);
    }
    if ( (_WORD)v31 == 0 )
      goto LABEL_34;
    if ( (_WORD)v31 == 39 )
    {
      v32 = CharNextW(*a1);
      *a1 = v32;
      v33 = *v32;
      if ( *v32 != 0 )
      {
        while ( v33 != 39 || *CharNextW(v32) == 39 )
        {
          v34 = *a1;
          if ( **a1 == 39 )
          {
            v35 = CharNextW(*a1);
            *a1 = v35;
            v34 = v35;
          }
          v36 = CharNextW(v34);
          *a1 = v36;
          k = v36 - v34;
          v32 = v36;
          if ( &v29[k + 1] >= v50 )
            goto LABEL_34;
          if ( (int)k > 0 )
          {
            v38 = (char *)v34 - (char *)v29;
            for ( k = (unsigned int)k; k != 0; --k )
            {
              *v29 = *(WCHAR *)((char *)v29 + v38);
              ++v29;
            }
          }
          v33 = *v36;
          if ( *v32 == 0 )
            break;
        }
      }
      v39 = *a1;
      if ( **a1 == 0 )
        goto LABEL_34;
      *v29 = 0;
      *a1 = CharNextW(v39);
    }
    else
    {
      do
      {
        if ( (unsigned __int16)v31 <= 0x20u )
        {
          v40 = 0x100002600LL;
          if ( _bittest64(&v40, v31) )
            break;
        }
        v41 = CharNextW(v30);
        *a1 = v41;
        v42 = v41;
        v43 = v41 - v30;
        if ( &v29[v43 + 1] >= v50 )
          goto LABEL_34;
        if ( (int)v43 > 0 )
        {
          v44 = (char *)v30 - (char *)v29;
          for ( m = (unsigned int)v43; m != 0; --m )
          {
            *v29 = *(WCHAR *)((char *)v29 + v44);
            ++v29;
          }
        }
        v31 = *v41;
        v30 = v42;
      }
      while ( (_WORD)v31 != 0 );
      *v29 = 0;
    }
    if ( String1[0] != 123 )
      goto LABEL_34;
    if ( a3 == 0 )
    {
      v6 = sub_180004400((_DWORD)a1, (unsigned int)String1, v28, 0, 0);
      if ( v6 < 0 )
        goto LABEL_35;
      goto LABEL_71;
    }
    v46 = *a1;
    v6 = sub_180004400((_DWORD)a1, (unsigned int)String1, v28, a3, 0);
    if ( v6 < 0 )
      break;
LABEL_71:
    while ( 1 )
    {
      v47 = **a1;
      if ( v47 < 9u || v47 > 0xAu && v47 != 13 && v47 != 32 )
        break;
      *a1 = CharNextW(*a1);
    }
    if ( v47 == 0 )
      goto LABEL_35;
  }
  *a1 = v46;
  sub_180004400((_DWORD)a1, (unsigned int)String1, v28, 0, 0);
LABEL_35:
  CoTaskMemFree(v7);
  return (unsigned int)v6;
}


// ===== sub_180004200 @ 0x180004200 size=0x1f4 =====
__int64 __fastcall sub_180004200(const WCHAR *a1, const WCHAR *a2, const WCHAR *a3, const WCHAR *a4, int a5)
{
  HMODULE Library; // rdi
  unsigned int v9; // ebx
  HRSRC ResourceW; // rax
  HRSRC v11; // rbx
  unsigned int v12; // eax
  const CHAR *Resource; // rsi
  DWORD cchWideChar; // ebx
  DWORD v15; // eax
  int v16; // eax
  HMODULE v18; // [rsp+38h] [rbp-480h]
  LPCWSTR v19[3]; // [rsp+48h] [rbp-470h] BYREF
  _QWORD *v20; // [rsp+60h] [rbp-458h] BYREF
  LPWSTR lpWideCharStr; // [rsp+70h] [rbp-448h] BYREF
  _BYTE v22[1032]; // [rsp+78h] [rbp-440h] BYREF

  v19[2] = (LPCWSTR)-2LL;
  v20 = nullptr;
  __wind
  {
    v19[1] = a1;
    v19[0] = nullptr;
    lpWideCharStr = nullptr;
    __wind
    {
      Library = LoadLibraryExW(a2, nullptr, 0x60u);
      v18 = Library;
      if ( Library == nullptr )
      {
        Library = LoadLibraryExW(a2, nullptr, 2u);
        v18 = Library;
        if ( Library == nullptr )
        {
          v9 = sub_180002F90();
          goto LABEL_29;
        }
      }
      ResourceW = FindResourceW(Library, a3, a4);
      v11 = ResourceW;
      if ( ResourceW != nullptr && (Resource = (const CHAR *)LoadResource(Library, ResourceW)) != nullptr )
      {
        cchWideChar = SizeofResource(Library, v11);
        v15 = cchWideChar + 1;
        if ( cchWideChar + 1 < cchWideChar )
        {
          v9 = -2147024882;
          goto LABEL_21;
        }
        try
        {
          if ( cchWideChar == -1 )
            goto LABEL_14;
          if ( 0xFFFFFFFFFFFFFFFFuLL / v15 < 2 )
            sub_180002FC0(-2147024362);
          if ( 2 * (unsigned __int64)v15 <= 0x400 )
LABEL_14:
            lpWideCharStr = (LPWSTR)v22;
          else
            sub_180002E70(&lpWideCharStr, 2LL * v15);
        }
        catch ( ... )
        {
          Library = v18;
        }
        if ( lpWideCharStr == nullptr )
        {
          v9 = -2147024882;
          goto LABEL_21;
        }
        v16 = MultiByteToWideChar(3u, 0, Resource, cchWideChar, lpWideCharStr, cchWideChar);
        if ( v16 != 0 )
        {
          lpWideCharStr[v16] = 0;
          v12 = sub_180003D20(v19, lpWideCharStr, a5);
        }
        else
        {
          v12 = sub_180002F90();
        }
      }
      else
      {
        v12 = sub_180002F90();
      }
      v9 = v12;
LABEL_21:
      if ( Library != nullptr )
        FreeLibrary(Library);
    }
    __unwind
    {
      sub_180002380(&lpWideCharStr);
    }
LABEL_29:
    if ( lpWideCharStr != (LPWSTR)v22 )
      sub_1800032F0((void **)&lpWideCharStr);
  }
  __unwind
  {
    sub_180002290(&v20);
  }
  return v9;
}


// ===== sub_180004400 @ 0x180004400 size=0xdc3 =====
__int64 __fastcall sub_180004400(LPCWSTR *a1, char *a2, HKEY a3, int a4, int a5)
{
  WCHAR *v5; // r15
  LPCWSTR *v6; // r14
  int v7; // esi
  HKEY v8; // r12
  int v9; // eax
  int v10; // ebx
  int v11; // r13d
  char *v12; // rbx
  const WCHAR *v13; // rdi
  unsigned __int16 v14; // ax
  LPWSTR v15; // r8
  WCHAR v16; // ax
  const WCHAR *v17; // rdi
  LPWSTR v18; // rax
  __int64 v19; // rdx
  signed __int64 v20; // rdi
  __int64 i; // rcx
  __int64 v22; // rdx
  LPWSTR v23; // r8
  __int64 v24; // rdx
  signed __int64 v25; // rdi
  __int64 j; // rcx
  int v27; // edi
  const WCHAR *v28; // rcx
  WCHAR v29; // ax
  LPCWSTR *v30; // rbx
  char *v31; // rbx
  const WCHAR *v32; // rdi
  unsigned __int64 v33; // rax
  LPWSTR v34; // r8
  WCHAR v35; // ax
  const WCHAR *v36; // rdi
  LPWSTR v37; // rax
  __int64 v38; // rdx
  signed __int64 v39; // rdi
  __int64 k; // rcx
  __int64 v41; // rcx
  LPWSTR v42; // r8
  __int64 v43; // rdx
  signed __int64 v44; // rdi
  __int64 m; // rcx
  WCHAR *v46; // rbx
  const WCHAR *v47; // rdi
  unsigned __int16 v48; // ax
  LPWSTR v49; // rdx
  WCHAR v50; // ax
  const WCHAR *v51; // rdi
  LPWSTR v52; // rax
  __int64 n; // rcx
  signed __int64 v54; // rdi
  const WCHAR *v55; // rcx
  __int64 v56; // rcx
  LPWSTR v57; // r8
  __int64 v58; // rdx
  signed __int64 v59; // rdi
  __int64 ii; // rcx
  char *v61; // rbx
  const WCHAR *v62; // rdi
  unsigned __int64 v63; // rax
  LPWSTR v64; // r8
  WCHAR v65; // ax
  const WCHAR *v66; // rdi
  LPWSTR v67; // rax
  __int64 v68; // rdx
  signed __int64 v69; // rdi
  __int64 jj; // rcx
  LPWSTR v71; // rax
  __int64 v72; // rcx
  LPWSTR v73; // r8
  __int64 v74; // rdx
  signed __int64 v75; // rdi
  __int64 kk; // rcx
  LSTATUS v77; // eax
  HKEY v78; // rdi
  LSTATUS v79; // eax
  const WCHAR *v80; // rcx
  WCHAR v81; // ax
  HKEY v82; // rdi
  _QWORD *v83; // rbx
  HMODULE ModuleHandleW; // rax
  LSTATUS v85; // eax
  LSTATUS (__stdcall *RegCreateKeyTransactedW)(HKEY, LPCWSTR, DWORD, LPWSTR, DWORD, REGSAM, const LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD, HANDLE, PVOID); // r10
  HRESULT v87; // eax
  __int64 v88; // rax
  LSTATUS v89; // edi
  int v90; // esi
  errno_t v91; // eax
  __int64 v92; // rax
  LPCWSTR *v93; // rdi
  int v94; // edi
  LSTATUS v95; // eax
  HKEY v98; // [rsp+68h] [rbp-98h] BYREF
  int v99; // [rsp+70h] [rbp-90h]
  __int64 v100; // [rsp+78h] [rbp-88h]
  HKEY v101; // [rsp+80h] [rbp-80h]
  DWORD dwDisposition; // [rsp+88h] [rbp-78h] BYREF
  HKEY phkResult; // [rsp+90h] [rbp-70h] BYREF
  HKEY v104; // [rsp+98h] [rbp-68h] BYREF
  int v105; // [rsp+A0h] [rbp-60h]
  __int64 v106; // [rsp+A8h] [rbp-58h]
  HKEY v107; // [rsp+B0h] [rbp-50h] BYREF
  int v108; // [rsp+B8h] [rbp-48h]
  __int64 v109; // [rsp+C0h] [rbp-40h]
  HKEY hKey; // [rsp+C8h] [rbp-38h] BYREF
  int v111; // [rsp+D0h] [rbp-30h]
  __int64 v112; // [rsp+D8h] [rbp-28h]
  HKEY v113; // [rsp+E0h] [rbp-20h] BYREF
  int v114; // [rsp+E8h] [rbp-18h]
  __int64 v115; // [rsp+F0h] [rbp-10h]
  __int64 v116; // [rsp+F8h] [rbp-8h]
  WCHAR String1[264]; // [rsp+100h] [rbp+0h] BYREF
  WCHAR ValueName[4096]; // [rsp+310h] [rbp+210h] BYREF
  WCHAR v119[40]; // [rsp+2310h] [rbp+2210h] BYREF

  v116 = -2;
  v101 = a3;
  v5 = (WCHAR *)a2;
  v6 = a1;
  v7 = 0;
  v8 = nullptr;
  v98 = nullptr;
  v99 = 0;
  v100 = 0;
LABEL_2:
  __wind
  {
    v9 = sub_1800034B0(a1, a2);
LABEL_3:
    v10 = v9;
    if ( v9 < 0 )
      goto LABEL_247;
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
LABEL_4:
          if ( *v5 == 125 )
            goto LABEL_247;
          v11 = 1;
          LOBYTE(v7) = lstrcmpiW(v5, L"Delete") == 0;
          if ( lstrcmpiW(v5, L"ForceRemove") != 0 && v7 == 0 )
            goto LABEL_52;
          v12 = (char *)v5;
          while ( 1 )
          {
            v13 = *v6;
            v14 = **v6;
            if ( v14 < 9u || v14 > 0xAu && v14 != 13 && v14 != 32 )
              break;
            *v6 = CharNextW(*v6);
          }
          if ( v14 == 0 )
            goto LABEL_240;
          if ( v14 == 39 )
          {
            v15 = CharNextW(*v6);
            *v6 = v15;
            v16 = *v15;
            if ( *v15 != 0 )
            {
              while ( v16 != 39 || *CharNextW(v15) == 39 )
              {
                v17 = *v6;
                if ( **v6 == 39 )
                {
                  v18 = CharNextW(*v6);
                  *v6 = v18;
                  v17 = v18;
                }
                v15 = CharNextW(v17);
                *v6 = v15;
                v19 = v15 - v17;
                if ( &v12[2 * v19 + 2] >= (char *)v5 + 0x2000 )
                  goto LABEL_240;
                if ( (int)v19 > 0 )
                {
                  v20 = (char *)v17 - v12;
                  for ( i = (unsigned int)v19; i != 0; --i )
                  {
                    *(_WORD *)v12 = *(_WORD *)&v12[v20];
                    v12 += 2;
                  }
                  v15 = (LPWSTR)*v6;
                }
                v16 = *v15;
                if ( *v15 == 0 )
                  break;
              }
            }
            if ( **v6 == 0 )
            {
LABEL_240:
              v10 = -2147352567;
              goto LABEL_247;
            }
            *(_WORD *)v12 = 0;
            *v6 = CharNextW(*v6);
          }
          else
          {
            do
            {
              if ( v14 <= 0x20u )
              {
                v22 = 0x100002600LL;
                if ( _bittest64(&v22, v14) )
                  break;
              }
              v23 = CharNextW(v13);
              *v6 = v23;
              v24 = v23 - v13;
              if ( &v12[2 * v24 + 2] >= (char *)v5 + 0x2000 )
                goto LABEL_240;
              if ( (int)v24 > 0 )
              {
                v25 = (char *)v13 - v12;
                for ( j = (unsigned int)v24; j != 0; --j )
                {
                  *(_WORD *)v12 = *(_WORD *)&v12[v25];
                  v12 += 2;
                }
                v23 = (LPWSTR)*v6;
              }
              v14 = *v23;
              v13 = v23;
            }
            while ( *v23 != 0 );
            *(_WORD *)v12 = 0;
          }
          v27 = a4;
          if ( a4 != 0 )
          {
            v104 = nullptr;
            v105 = 0;
            v106 = 0;
            __eh34_enter_wind_state(0, 1);
            v28 = v5;
            v29 = *v5;
            if ( *v5 != 0 )
            {
              while ( v29 != 92 )
              {
                v28 = CharNextW(v28);
                v29 = *v28;
                if ( *v28 == 0 )
                  goto LABEL_43;
              }
              if ( v28 != nullptr )
              {
                if ( __eh34_unwind(1) )
                {
unwind_state_1:
                  sub_180002610((__int64)&v104);
                  __eh34_continue_unwinding(1, 0);
                }
                __eh34_exit_wind_state(1, 0);
                v105 = 0;
LABEL_227:
                v10 = -2147352567;
                goto LABEL_247;
              }
            }
LABEL_43:
            v30 = (LPCWSTR *)off_18001A670;
            while ( lstrcmpiW(v5, *v30) != 0 )
            {
              if ( (__int64)++v30 >= (__int64)&off_18001A6D0 )
              {
                v104 = v101;
                v105 = 0;
                v106 = 0;
                sub_180003BB0((__int64)&v104, v5);
                v104 = nullptr;
                v105 = 0;
                v106 = 0;
                goto LABEL_268;
              }
            }
            if ( __eh34_unwind(1) )
              goto unwind_state_1;
LABEL_268:
            __eh34_exit_wind_state(1, 0);
            if ( v7 != 0 )
            {
              v10 = sub_1800034B0(v6, (char *)v5);
              if ( v10 < 0 )
              {
                v105 = 0;
                goto LABEL_247;
              }
              v10 = sub_1800051D0(v6, v5);
              v7 = 0;
              v105 = 0;
              if ( v10 < 0 )
                goto LABEL_247;
              goto LABEL_184;
            }
            v7 = 0;
            v105 = 0;
          }
          else
          {
LABEL_52:
            v7 = 0;
          }
          if ( lstrcmpiW(v5, L"NoRemove") == 0 )
          {
            v11 = 0;
            v31 = (char *)v5;
            while ( 1 )
            {
              v32 = *v6;
              v33 = **v6;
              if ( (unsigned __int16)v33 < 9u || (unsigned __int16)v33 > 0xAu && (_WORD)v33 != 13 && (_WORD)v33 != 32 )
                break;
              *v6 = CharNextW(*v6);
            }
            if ( (_WORD)v33 == 0 )
              goto LABEL_227;
            if ( (_WORD)v33 == 39 )
            {
              v34 = CharNextW(*v6);
              *v6 = v34;
              v35 = *v34;
              if ( *v34 != 0 )
              {
                while ( v35 != 39 || *CharNextW(v34) == 39 )
                {
                  v36 = *v6;
                  if ( **v6 == 39 )
                  {
                    v37 = CharNextW(*v6);
                    *v6 = v37;
                    v36 = v37;
                  }
                  v34 = CharNextW(v36);
                  *v6 = v34;
                  v38 = v34 - v36;
                  if ( &v31[2 * v38 + 2] >= (char *)v5 + 0x2000 )
                    goto LABEL_227;
                  if ( (int)v38 > 0 )
                  {
                    v39 = (char *)v36 - v31;
                    for ( k = (unsigned int)v38; k != 0; --k )
                    {
                      *(_WORD *)v31 = *(_WORD *)&v31[v39];
                      v31 += 2;
                    }
                    v34 = (LPWSTR)*v6;
                  }
                  v35 = *v34;
                  if ( *v34 == 0 )
                    break;
                }
              }
              if ( **v6 == 0 )
                goto LABEL_227;
              *(_WORD *)v31 = 0;
              *v6 = CharNextW(*v6);
            }
            else
            {
              do
              {
                if ( (unsigned __int16)v33 <= 0x20u )
                {
                  v41 = 0x100002600LL;
                  if ( _bittest64(&v41, v33) )
                    break;
                }
                v42 = CharNextW(v32);
                *v6 = v42;
                v43 = v42 - v32;
                if ( &v31[2 * v43 + 2] >= (char *)v5 + 0x2000 )
                  goto LABEL_227;
                if ( (int)v43 > 0 )
                {
                  v44 = (char *)v32 - v31;
                  for ( m = (unsigned int)v43; m != 0; --m )
                  {
                    *(_WORD *)v31 = *(_WORD *)&v31[v44];
                    v31 += 2;
                  }
                  v42 = (LPWSTR)*v6;
                }
                v33 = *v42;
                v32 = v42;
              }
              while ( (_WORD)v33 != 0 );
              *(_WORD *)v31 = 0;
            }
          }
          if ( lstrcmpiW(v5, L"Val") == 0 )
          {
            v46 = ValueName;
            while ( 1 )
            {
              v47 = *v6;
              v48 = **v6;
              if ( v48 < 9u || v48 > 0xAu && v48 != 13 && v48 != 32 )
                break;
              *v6 = CharNextW(*v6);
            }
            if ( v48 == 0 )
              goto LABEL_227;
            if ( v48 == 39 )
            {
              v49 = CharNextW(*v6);
              *v6 = v49;
              v50 = *v49;
              if ( *v49 != 0 )
              {
                while ( v50 != 39 || *CharNextW(v49) == 39 )
                {
                  v51 = *v6;
                  if ( **v6 == 39 )
                  {
                    v52 = CharNextW(*v6);
                    *v6 = v52;
                    v51 = v52;
                  }
                  v49 = CharNextW(v51);
                  *v6 = v49;
                  n = v49 - v51;
                  if ( &v46[n + 1] >= v119 )
                    goto LABEL_227;
                  if ( (int)n > 0 )
                  {
                    v54 = (char *)v51 - (char *)v46;
                    for ( n = (unsigned int)n; n != 0; --n )
                    {
                      *v46 = *(WCHAR *)((char *)v46 + v54);
                      ++v46;
                    }
                  }
                  v50 = *v49;
                  if ( *v49 == 0 )
                    break;
                }
              }
              v55 = *v6;
              if ( **v6 == 0 )
                goto LABEL_227;
              *v46 = 0;
              *v6 = CharNextW(v55);
            }
            else
            {
              do
              {
                if ( v48 <= 0x20u )
                {
                  v56 = 0x100002600LL;
                  if ( _bittest64(&v56, v48) )
                    break;
                }
                v57 = CharNextW(v47);
                *v6 = v57;
                v58 = v57 - v47;
                if ( &v46[v58 + 1] >= v119 )
                  goto LABEL_227;
                if ( (int)v58 > 0 )
                {
                  v59 = (char *)v47 - (char *)v46;
                  for ( ii = (unsigned int)v58; ii != 0; --ii )
                  {
                    *v46 = *(WCHAR *)((char *)v46 + v59);
                    ++v46;
                  }
                }
                v48 = *v57;
                v47 = v57;
              }
              while ( *v57 != 0 );
              *v46 = 0;
            }
            v61 = (char *)v5;
            while ( 1 )
            {
              v62 = *v6;
              v63 = **v6;
              if ( (unsigned __int16)v63 < 9u || (unsigned __int16)v63 > 0xAu && (_WORD)v63 != 13 && (_WORD)v63 != 32 )
                break;
              *v6 = CharNextW(*v6);
            }
            if ( (_WORD)v63 == 0 )
              goto LABEL_227;
            if ( (_WORD)v63 == 39 )
            {
              v64 = CharNextW(*v6);
              *v6 = v64;
              v65 = *v64;
              if ( *v64 != 0 )
              {
                while ( v65 != 39 || *CharNextW(v64) == 39 )
                {
                  v66 = *v6;
                  if ( **v6 == 39 )
                  {
                    v67 = CharNextW(*v6);
                    *v6 = v67;
                    v66 = v67;
                  }
                  v64 = CharNextW(v66);
                  *v6 = v64;
                  v68 = v64 - v66;
                  if ( &v61[2 * v68 + 2] >= (char *)v5 + 0x2000 )
                    goto LABEL_227;
                  if ( (int)v68 > 0 )
                  {
                    v69 = (char *)v66 - v61;
                    for ( jj = (unsigned int)v68; jj != 0; --jj )
                    {
                      *(_WORD *)v61 = *(_WORD *)&v61[v69];
                      v61 += 2;
                    }
                    v64 = (LPWSTR)*v6;
                  }
                  v65 = *v64;
                  if ( *v64 == 0 )
                    break;
                }
              }
              if ( **v6 == 0 )
                goto LABEL_227;
              *(_WORD *)v61 = 0;
              v71 = CharNextW(*v6);
              *v6 = v71;
            }
            else
            {
              do
              {
                if ( (unsigned __int16)v63 <= 0x20u )
                {
                  v72 = 0x100002600LL;
                  if ( _bittest64(&v72, v63) )
                    break;
                }
                v73 = CharNextW(v62);
                *v6 = v73;
                v74 = v73 - v62;
                if ( &v61[2 * v74 + 2] >= (char *)v5 + 0x2000 )
                  goto LABEL_227;
                if ( (int)v74 > 0 )
                {
                  v75 = (char *)v62 - v61;
                  for ( kk = (unsigned int)v74; kk != 0; --kk )
                  {
                    *(_WORD *)v61 = *(_WORD *)&v61[v75];
                    v61 += 2;
                  }
                  v73 = (LPWSTR)*v6;
                }
                v63 = *v73;
                v62 = v73;
              }
              while ( (_WORD)v63 != 0 );
              *(_WORD *)v61 = 0;
            }
            if ( *v5 != 61 )
              goto LABEL_227;
            if ( a4 != 0 )
            {
              v107 = nullptr;
              v108 = 0;
              v109 = 0;
              __wind
              {
                v107 = v101;
                v108 = 0;
                v109 = 0;
                v87 = sub_1800028C0(v6, &v107, ValueName, (__int64)v5);
                v10 = v87;
                v107 = nullptr;
                v108 = 0;
                v109 = 0;
              }
              __unwind
              {
                sub_180002610((__int64)&v107);
              }
              v108 = 0;
LABEL_182:
              if ( v87 < 0 )
                goto LABEL_247;
              goto LABEL_183;
            }
            if ( a5 != 0 || v11 == 0 )
            {
LABEL_155:
              v9 = sub_1800051D0(v6, v5);
              goto LABEL_3;
            }
            hKey = nullptr;
            v111 = 0;
            v112 = 0;
            __eh34_enter_wind_state(0, 3);
            v77 = sub_180003690((__int64)&hKey, v101, nullptr, 0x20006u);
            if ( v77 != 0 )
            {
              v10 = sub_180002FB0(v77);
              if ( __eh34_unwind(3) )
              {
unwind_state_3:
                sub_180002610((__int64)&hKey);
                __eh34_continue_unwinding(3, 0);
              }
              __eh34_exit_wind_state(3, 0);
              if ( hKey != nullptr )
              {
                RegCloseKey(hKey);
                hKey = nullptr;
              }
            }
            else
            {
              v78 = hKey;
              v79 = RegDeleteValueW(hKey, ValueName);
              if ( (v79 & 0xFFFFFFFD) == 0 )
              {
                if ( __eh34_unwind(3) )
                  goto unwind_state_3;
                __eh34_exit_wind_state(3, 0);
                if ( v78 != nullptr )
                {
                  RegCloseKey(v78);
                  hKey = nullptr;
                }
                v111 = 0;
                goto LABEL_155;
              }
              v10 = sub_180002FB0(v79);
              if ( __eh34_unwind(3) )
                goto unwind_state_3;
              __eh34_exit_wind_state(3, 0);
              if ( v78 != nullptr )
              {
                RegCloseKey(v78);
                hKey = nullptr;
                v111 = 0;
                goto LABEL_247;
              }
            }
            v111 = 0;
            goto LABEL_247;
          }
          v80 = v5;
          v81 = *v5;
          if ( *v5 != 0 )
          {
            while ( v81 != 92 )
            {
              v80 = CharNextW(v80);
              v81 = *v80;
              if ( *v80 == 0 )
                goto LABEL_161;
            }
            if ( v80 != nullptr )
              goto LABEL_227;
          }
LABEL_161:
          if ( a4 == 0 )
            break;
          v82 = v101;
          if ( sub_180003690((__int64)&v98, v101, v5, 0x2001Fu) == 0
            || sub_180003690((__int64)&v98, v82, v5, 0x20019u) == 0 )
          {
            v8 = v98;
            goto LABEL_179;
          }
          phkResult = nullptr;
          v83 = (_QWORD *)v100;
          if ( v100 == 0 )
            goto LABEL_172;
          if ( *(_QWORD *)v100 != 0 )
          {
            ModuleHandleW = GetModuleHandleW(L"Advapi32.dll");
            if ( ModuleHandleW != nullptr )
            {
              RegCreateKeyTransactedW = (LSTATUS (__stdcall *)(HKEY, LPCWSTR, DWORD, LPWSTR, DWORD, REGSAM, const LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD, HANDLE, PVOID))GetProcAddress(ModuleHandleW, "RegCreateKeyTransactedW");
              if ( RegCreateKeyTransactedW != nullptr )
                v85 = ((__int64 (__fastcall *)(HKEY, WCHAR *, _QWORD, _QWORD, _DWORD, int, _QWORD, HKEY *, DWORD *, _QWORD, _QWORD))RegCreateKeyTransactedW)(
                        v82,
                        v5,
                        0,
                        0,
                        0,
                        131103,
                        0,
                        &phkResult,
                        &dwDisposition,
                        *v83,
                        0);
              else
                v85 = 1;
            }
            else
            {
              v85 = 1;
            }
            goto LABEL_173;
          }
          if ( *(_DWORD *)(v100 + 8) != 0 )
LABEL_172:
            v85 = RegCreateKeyExW(v82, v5, 0, nullptr, 0, 0x2001Fu, nullptr, &phkResult, &dwDisposition);
          else
            v85 = 1;
LABEL_173:
          if ( v85 != 0 )
          {
            v8 = v98;
LABEL_237:
            v10 = sub_180002FB0(v85);
            goto LABEL_247;
          }
          v85 = 0;
          if ( v98 != nullptr )
          {
            v85 = RegCloseKey(v98);
            v98 = nullptr;
          }
          v8 = phkResult;
          v98 = phkResult;
          v99 = 0;
          if ( v85 != 0 )
            goto LABEL_237;
LABEL_179:
          v10 = sub_1800034B0(v6, (char *)v5);
          if ( v10 < 0 )
            goto LABEL_247;
          if ( *v5 == 61 )
          {
            v87 = sub_1800028C0(v6, &v98, nullptr, (__int64)v5);
            v10 = v87;
            v8 = v98;
            goto LABEL_182;
          }
LABEL_183:
          v27 = a4;
LABEL_184:
          if ( *v5 == 123 )
          {
            v88 = -1;
            do
              ++v88;
            while ( v5[v88] != 0 );
            if ( v88 == 1 )
            {
              v10 = sub_180004400((_DWORD)v6, (_DWORD)v5, (_DWORD)v8, v27, 0);
              if ( v10 < 0 )
                goto LABEL_247;
              a2 = (char *)v5;
              a1 = v6;
              goto LABEL_2;
            }
          }
        }
        if ( a5 != 0 )
        {
          v89 = 2;
        }
        else
        {
          v89 = sub_180003690((__int64)&v98, v101, v5, 0x20019u);
          v8 = v98;
        }
        v90 = a5;
        if ( v89 != 0 )
          v90 = 1;
        v91 = wcsncpy_s(String1, 0x104u, v5, 0xFFFFFFFFFFFFFFFFuLL);
        if ( v91 != 0 )
        {
          if ( v91 == 12 )
            sub_180002FC0(-2147024882);
          if ( v91 == 22 || v91 == 34 )
            sub_180002FC0(-2147024809);
          if ( v91 != 80 )
            sub_180002FC0(-2147467259);
        }
        v10 = sub_1800034B0(v6, (char *)v5);
        if ( v10 < 0 )
          goto LABEL_247;
        v10 = sub_1800051D0(v6, v5);
        if ( v10 < 0 )
          goto LABEL_247;
        if ( *v5 == 123 )
        {
          v92 = -1;
          do
            ++v92;
          while ( v5[v92] != 0 );
          if ( v92 == 1 )
          {
            v10 = sub_180004400((_DWORD)v6, (_DWORD)v5, (_DWORD)v8, 0, v90);
            if ( v10 < 0 && v90 == 0 )
              goto LABEL_247;
            v10 = sub_1800034B0(v6, (char *)v5);
            if ( v10 < 0 )
              goto LABEL_247;
          }
        }
        if ( v89 != 2 )
          break;
LABEL_212:
        v7 = 0;
      }
      if ( v89 != 0 )
      {
        if ( a5 == 0 )
        {
          v10 = sub_180002FB0(v89);
          goto LABEL_247;
        }
        goto LABEL_212;
      }
      if ( a5 != 0 && (unsigned int)sub_180003300((__int64)v6, v8) != 0 )
      {
        v93 = (LPCWSTR *)off_18001A670;
        while ( lstrcmpiW(String1, *v93) != 0 )
        {
          if ( (__int64)++v93 >= (__int64)&off_18001A6D0 )
          {
            if ( v11 == 0 )
              goto LABEL_212;
            sub_180003BB0((__int64)&v98, String1);
            v8 = v98;
            v7 = 0;
            goto LABEL_4;
          }
        }
        goto LABEL_212;
      }
      v94 = sub_180003300((__int64)v6, v8);
      v7 = 0;
      v85 = 0;
      if ( v8 != nullptr )
      {
        v85 = RegCloseKey(v8);
        v8 = nullptr;
        v98 = nullptr;
      }
      v99 = 0;
      if ( v85 != 0 )
        goto LABEL_237;
      if ( v11 != 0 && v94 == 0 )
      {
        __eh34_enter_wind_state(0, 4);
        v113 = v101;
        v114 = 0;
        v115 = 0;
        v95 = sub_180003180((__int64)&v113, String1);
        v113 = nullptr;
        v114 = 0;
        v115 = 0;
        if ( v95 != 0 )
        {
          v10 = sub_180002FB0(v95);
          if ( __eh34_unwind(4) )
          {
unwind_state_4:
            sub_180002610((__int64)&v113);
            __eh34_continue_unwinding(4, 0);
          }
          __eh34_exit_wind_state(4, 0);
          v114 = 0;
          goto LABEL_247;
        }
        if ( __eh34_unwind(4) )
          goto unwind_state_4;
        __eh34_exit_wind_state(4, 0);
        v114 = 0;
      }
    }
  }
  __unwind
  {
    sub_180002610((__int64)&v98);
  }
LABEL_247:
  if ( v8 != nullptr )
  {
    RegCloseKey(v8);
    v98 = nullptr;
  }
  v99 = 0;
  return (unsigned int)v10;
}


// ===== sub_1800051D0 @ 0x1800051d0 size=0xac =====
__int64 __fastcall sub_1800051D0(LPCWSTR *a1, char *a2)
{
  __int64 result; // rax
  WCHAR v5; // ax
  char v6[8192]; // [rsp+20h] [rbp-2018h] BYREF

  if ( *(_WORD *)a2 != 61 )
    return 0;
  result = sub_1800034B0(a1, a2);
  if ( (int)result >= 0 )
  {
    while ( 1 )
    {
      v5 = **a1;
      if ( v5 < 9u || v5 > 0xAu && v5 != 13 && v5 != 32 )
        break;
      *a1 = CharNextW(*a1);
    }
    result = sub_1800034B0(a1, v6);
    if ( (int)result >= 0 )
    {
      result = sub_1800034B0(a1, a2);
      if ( (int)result >= 0 )
        return 0;
    }
  }
  return result;
}


// ===== sub_180005280 @ 0x180005280 size=0x65 =====
LPWSTR __fastcall sub_180005280(LPWSTR a1, __int16 a2)
{
  __int64 v2; // rdi
  WCHAR v5; // ax

  v2 = 0;
  if ( a1 == nullptr )
    return nullptr;
  v5 = *a1;
  if ( *a1 != 0 )
  {
    while ( v5 != a2 )
    {
      a1 = CharNextW(a1);
      v5 = *a1;
      if ( *a1 == 0 )
        return nullptr;
    }
    return a1;
  }
  return (LPWSTR)v2;
}


// ===== sub_1800052F0 @ 0x1800052f0 size=0x3b1 =====
__int64 __fastcall sub_1800052F0(__int64 a1, unsigned __int16 a2, int a3, __int64 *a4)
{
  __int64 *v4; // rbx
  __int64 v8; // rax
  __int64 v9; // r8
  int v10; // ebx
  HMODULE v12; // rbx
  DWORD ModuleFileNameW; // eax
  WCHAR *v14; // r8
  _WORD *v15; // rax
  unsigned int i; // ecx
  __int64 v17; // rdx
  unsigned int v18; // edi
  _WORD *v19; // rcx
  __int64 v20; // rbx
  __int64 v21; // rax
  unsigned __int64 v22; // r8
  unsigned __int64 v23; // rax
  int v24; // eax
  bool v25; // zf
  void **v26; // [rsp+30h] [rbp-D0h] BYREF
  void *Block[2]; // [rsp+38h] [rbp-C8h] BYREF
  int v28; // [rsp+48h] [rbp-B8h]
  void **v29; // [rsp+58h] [rbp-A8h] BYREF
  _QWORD *v30[2]; // [rsp+60h] [rbp-A0h] BYREF
  WCHAR Filename[264]; // [rsp+70h] [rbp-90h] BYREF
  __int16 v32; // [rsp+280h] [rbp+180h] BYREF
  _BYTE v33[1054]; // [rsp+282h] [rbp+182h] BYREF
  _WORD v34[520]; // [rsp+6A0h] [rbp+5A0h] BYREF

  v30[1] = (_QWORD *)-2LL;
  v4 = a4;
  v26 = &ATL::CRegObject::`vftable';
  v29 = Block;
  *(_OWORD *)Block = 0;
  v28 = 0;
  __eh34_enter_wind_state(-1, 2);
  if ( a4 != nullptr )
  {
    v8 = *a4;
    if ( *a4 != 0 )
    {
      do
      {
        v9 = v4[1];
        if ( v8 != 0 && v9 != 0 )
        {
          v29 = nullptr;
          __wind
          {
            sub_1800026E0((__int64)Block, v8, v9);
          }
          __unwind
          {
            sub_180002290(&v29);
          }
        }
        v4 += 2;
        v8 = *v4;
      }
      while ( *v4 != 0 );
    }
  }
  v10 = (*(__int64 (__fastcall **)(__int64, void ***))(*(_QWORD *)a1 + 40LL))(a1, &v26);
  if ( v10 < 0 )
  {
    if ( __eh34_unwind(2) )
      goto unwind_state_2;
    __eh34_exit_wind_state(2, -1);
    v26 = &ATL::CRegObject::`vftable';
    __wind
    {
      sub_180002FF0((__int64)Block);
    }
    __unwind
    {
      sub_180002590((__int64)Block);
    }
    v29 = Block;
    __wind
    {
      sub_180002FF0((__int64)Block);
    }
    __unwind
    {
      sub_180002330((__int64)v29);
    }
LABEL_10:
    if ( Block[0] != nullptr )
    {
      j__free_base(Block[0]);
      Block[0] = nullptr;
    }
    if ( Block[1] != nullptr )
    {
      j__free_base(Block[1]);
      Block[1] = nullptr;
    }
    v28 = 0;
    return (unsigned int)v10;
  }
  v29 = nullptr;
  __eh34_enter_wind_state(2, 8);
  v12 = hModule;
  ModuleFileNameW = GetModuleFileNameW(hModule, Filename, 0x104u);
  if ( ModuleFileNameW == 0 )
  {
    v10 = sub_180002F90();
    if ( __eh34_unwind(8) )
      goto unwind_state_8;
    __eh34_exit_wind_state(8, 2);
    if ( __eh34_unwind(2) )
      goto unwind_state_2;
    __eh34_exit_wind_state(2, -1);
    v26 = &ATL::CRegObject::`vftable';
    __wind
    {
      sub_180002FF0((__int64)Block);
    }
    __unwind
    {
      sub_180002590((__int64)Block);
    }
    v29 = Block;
    __wind
    {
      sub_180002FF0((__int64)Block);
    }
    __unwind
    {
      sub_180002330((__int64)v29);
    }
    goto LABEL_10;
  }
  if ( ModuleFileNameW == 260 )
  {
    if ( __eh34_unwind(8) )
    {
unwind_state_8:
      sub_180002290(&v29);
      __eh34_continue_unwinding(8, 2);
    }
    __eh34_exit_wind_state(8, 2);
    if ( __eh34_unwind(2) )
    {
unwind_state_2:
      sub_180002640(&v26);
      __eh34_propagate_exception_into_caller(2, -1);
    }
    __eh34_exit_wind_state(2, -1);
    sub_180002640(&v26);
    return 2147942522LL;
  }
  else
  {
    v14 = Filename;
    v15 = v34;
    for ( i = 0; i < 0x207; ++i )
    {
      v17 = *v14;
      if ( (_WORD)v17 == 0 )
        break;
      *v15++ = v17;
      if ( (_WORD)v17 == 39 && ++i < 0x207 )
        *v15++ = 39;
      ++v14;
    }
    *v15 = 0;
    if ( v12 != nullptr && v12 != GetModuleHandleW(nullptr) )
    {
      v30[0] = nullptr;
      __wind
      {
        v18 = -2147024882;
        v10 = -2147024882;
        if ( (unsigned int)sub_1800026E0((__int64)Block, (__int64)L"Module", (__int64)v34) != 0 )
          v10 = 0;
      }
      __unwind
      {
        sub_180002290(v30);
      }
      goto LABEL_41;
    }
    v32 = 34;
    v19 = v34;
    v20 = -1;
    v21 = -1;
    do
      ++v21;
    while ( v34[v21] != 0 );
    v22 = 2LL * ((int)v21 + 1);
    if ( v22 == 0 )
    {
      do
LABEL_36:
        ++v20;
      while ( *(_WORD *)&v33[2 * v20 - 2] != 0 );
      *(_WORD *)&v33[2 * (int)v20 - 2] = 34;
      v23 = 2LL * (int)v20 + 2;
      if ( v23 >= 0x418 )
        _report_rangecheckfailure(v19, v17, v22);
      *(_WORD *)&v33[v23 - 2] = 0;
      v30[0] = nullptr;
      __wind
      {
        v18 = -2147024882;
        v10 = -2147024882;
        if ( (unsigned int)sub_1800026E0((__int64)Block, (__int64)L"Module", (__int64)&v32) != 0 )
          v10 = 0;
      }
      __unwind
      {
        sub_180002290(v30);
      }
LABEL_41:
      if ( v10 >= 0 )
      {
        v30[0] = nullptr;
        __wind
        {
          v24 = sub_1800026E0((__int64)Block, (__int64)L"Module_Raw", (__int64)v34);
          v25 = v24 == 0;
          if ( v24 != 0 )
            v18 = 0;
        }
        __unwind
        {
          sub_180002290(v30);
        }
        if ( v25 )
        {
          if ( __eh34_unwind(8) )
            goto unwind_state_8;
          __eh34_exit_wind_state(8, 2);
          if ( __eh34_unwind(2) )
            goto unwind_state_2;
          __eh34_exit_wind_state(2, -1);
          sub_180002640(&v26);
          return v18;
        }
        v30[0] = nullptr;
        if ( a3 != 0 )
        {
          __wind
          {
            v10 = sub_180004200((const WCHAR *)&v26, Filename, (const WCHAR *)a2, L"REGISTRY", 1);
          }
          __unwind
          {
            sub_180002290(v30);
          }
        }
        else
        {
          __wind
          {
            v10 = sub_180004200((const WCHAR *)&v26, Filename, (const WCHAR *)a2, L"REGISTRY", 0);
          }
          __unwind
          {
            sub_180002290(v30);
          }
        }
      }
      if ( __eh34_unwind(8) )
        goto unwind_state_8;
      __eh34_exit_wind_state(8, 2);
      if ( __eh34_unwind(2) )
        goto unwind_state_2;
      __eh34_exit_wind_state(2, -1);
      sub_180002640(&v26);
      return (unsigned int)v10;
    }
    if ( v22 <= 0x416 )
    {
      sub_1800098F0(v33, v34);
      goto LABEL_36;
    }
    *errno() = 34;
    invalid_parameter_noinfo();
    if ( __eh34_unwind(8) )
      goto unwind_state_8;
    __eh34_exit_wind_state(8, 2);
    if ( __eh34_unwind(2) )
      goto unwind_state_2;
    __eh34_exit_wind_state(2, -1);
    sub_180002640(&v26);
    return 2147500037LL;
  }
}


// ===== InitializeCriticalSectionAndSpinCount @ 0x1800056b0 size=0x7 =====
// attributes: thunk
BOOL __stdcall InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount)
{
  return __imp_InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
}


// ===== sub_1800056C0 @ 0x1800056c0 size=0xd =====
void __fastcall sub_1800056C0(DWORD a1, DWORD a2)
{
  RaiseException(a1, a2, 0, nullptr);
}


// ===== sub_1800056D0 @ 0x1800056d0 size=0x4a =====
_QWORD *__fastcall sub_1800056D0(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  _QWORD *result; // rax

  result = operator new(0x30u);
  if ( a2 == nullptr )
  {
    a2 = result;
    a3 = result;
  }
  try
  {
    *result = a2;
    result[1] = a3;
  }
  catch ( ... )
  {
    sub_180005950(a1, result, 1);
    throw;
  }
  return result;
}


// ===== ?_Xlen@?$vector@PEAXV?$allocator@PEAX@std@@@std@@IEBAXXZ @ 0x180005720 size=0x11 =====
void __noreturn std::vector<void *>::_Xlen()
{
  sub_180007690("string too long");
}


// ===== sub_180005740 @ 0x180005740 size=0x189 =====
void **__fastcall sub_180005740(void **a1, __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // rbp
  void **v7; // rsi
  __int64 v8; // rbx
  __int64 v9; // rbx
  unsigned __int64 v10; // rdx
  unsigned __int64 v11; // rdx
  size_t v12; // rcx
  void *v13; // rax
  _QWORD *v14; // rsi
  void *v15; // rcx

  v3 = (unsigned __int64)a1[3];
  if ( a3 > v3 )
  {
    v9 = 0x7FFFFFFFFFFFFFFELL;
    if ( a3 > 0x7FFFFFFFFFFFFFFELL )
      std::vector<void *>::_Xlen();
    if ( (a3 | 7) <= 0x7FFFFFFFFFFFFFFELL )
    {
      v10 = v3 >> 1;
      if ( v3 <= 0x7FFFFFFFFFFFFFFELL - (v3 >> 1) )
      {
        v9 = a3 | 7;
        if ( (a3 | 7) < v10 + v3 )
          v9 = v10 + v3;
      }
    }
    v11 = 2 * (v9 + 1);
    if ( (unsigned __int64)(v9 + 1) <= 0x7FFFFFFFFFFFFFFFLL )
    {
      if ( v11 < 0x1000 )
      {
        if ( v11 != 0 )
          v14 = operator new(2 * (v9 + 1));
        else
          v14 = nullptr;
        goto LABEL_20;
      }
    }
    else
    {
      v11 = -1;
    }
    v12 = v11 + 39;
    if ( v11 + 39 < v11 )
      v12 = -1;
    v13 = operator new(v12);
    if ( v13 == nullptr )
      goto LABEL_27;
    v14 = (_QWORD *)(((unsigned __int64)v13 + 39) & 0xFFFFFFFFFFFFFFE0uLL);
    *(v14 - 1) = v13;
LABEL_20:
    a1[3] = (void *)v9;
    a1[2] = (void *)a3;
    sub_1800098F0(v14, a2);
    *((_WORD *)v14 + a3) = 0;
    if ( v3 < 8 )
    {
LABEL_25:
      *a1 = v14;
      return a1;
    }
    v15 = *a1;
    if ( 2 * v3 + 2 < 0x1000 )
    {
LABEL_24:
      j_j_j__free_base(v15);
      goto LABEL_25;
    }
    if ( (unsigned __int64)v15 - *((_QWORD *)v15 - 1) - 8 <= 0x1F )
    {
      v15 = *((void **)v15 - 1);
      goto LABEL_24;
    }
LABEL_27:
    invalid_parameter_noinfo_noreturn();
  }
  v7 = a1;
  if ( v3 >= 8 )
    v7 = (void **)*a1;
  v8 = 2 * a3;
  a1[2] = (void *)a3;
  sub_1800098F0(v7, a2);
  *(_WORD *)((char *)v7 + v8) = 0;
  return a1;
}


// ===== sub_1800058D0 @ 0x1800058d0 size=0x73 =====
void __fastcall sub_1800058D0(__int64 a1)
{
  _QWORD *v2; // rbx
  _QWORD *v3; // rdi

  v2 = **(_QWORD ***)a1;
  **(_QWORD **)a1 = *(_QWORD *)a1;
  *(_QWORD *)(*(_QWORD *)a1 + 8LL) = *(_QWORD *)a1;
  *(_QWORD *)(a1 + 8) = 0;
  if ( v2 != *(_QWORD **)a1 )
  {
    do
    {
      v3 = (_QWORD *)*v2;
      sub_1800023E0((__int64)(v2 + 2));
      j_j_j__free_base(v2);
      v2 = v3;
    }
    while ( v3 != *(_QWORD **)a1 );
  }
}


// ===== sub_180005950 @ 0x180005950 size=0x42 =====
void __fastcall sub_180005950(__int64 a1, void *a2, __int64 a3)
{
  void *v3; // rax

  v3 = a2;
  if ( (unsigned __int64)(48 * a3) >= 0x1000 )
  {
    if ( (unsigned __int64)a2 - *((_QWORD *)a2 - 1) - 8 > 0x1F )
      invalid_parameter_noinfo_noreturn();
    v3 = *((void **)a2 - 1);
  }
  j_j_j__free_base(v3);
}


// ===== sub_1800059A0 @ 0x1800059a0 size=0x47 =====
__int64 sub_1800059A0()
{
  __int64 result; // rax

  result = sub_180005A00();
  if ( (_DWORD)result != 0 )
  {
    if ( (_DWORD)result == 12 )
      sub_180002FC0(-2147024882);
    if ( (_DWORD)result == 22 || (_DWORD)result == 34 )
      sub_180002FC0(-2147024809);
    if ( (_DWORD)result != 80 )
      sub_180002FC0(-2147467259);
  }
  return result;
}


// ===== sub_1800059F0 @ 0x1800059f0 size=0x8 =====
void *sub_1800059F0()
{
  return &unk_18002A170;
}


// ===== sub_180005A00 @ 0x180005a00 size=0xa7 =====
__int64 __fastcall sub_180005A00(__int64 a1, unsigned __int64 a2, __int64 a3, unsigned __int64 a4)
{
  if ( a4 == 0 )
    return 0;
  if ( a1 == 0 )
  {
LABEL_3:
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
  if ( a3 != 0 && a2 >= a4 )
  {
    sub_1800098F0(a1, a3);
    return 0;
  }
  sub_180009D50(a1, 0, a2);
  if ( a3 == 0 )
    goto LABEL_3;
  if ( a2 >= a4 )
    return 22;
  *errno() = 34;
  invalid_parameter_noinfo();
  return 34;
}


// ===== swprintf @ 0x180005ab0 size=0x57 =====
int swprintf(wchar_t *const Buffer, const size_t BufferCount, const wchar_t *const Format, ...)
{
  int v3; // esi
  int v4; // ebx
  int v5; // edi
  _QWORD *v6; // rax
  int result; // eax
  va_list va; // [rsp+78h] [rbp+20h] BYREF

  va_start(va, Format);
  v3 = (int)Format;
  v4 = BufferCount;
  v5 = (int)Buffer;
  v6 = sub_1800059F0();
  result = unknown_libname_54(*v6, v5, v4, v3, nullptr, (__int64)va);
  if ( result < 0 )
    return -1;
  return result;
}


// ===== sub_180005B10 @ 0x180005b10 size=0x35 =====
_QWORD *__fastcall sub_180005B10(_QWORD *a1)
{
  *a1 = 0;
  a1[1] = 0;
  *a1 = sub_180006090(a1);
  return a1;
}


// ===== sub_180005B50 @ 0x180005b50 size=0x2e =====
void __fastcall sub_180005B50(void **a1)
{
  __wind
  {
    sub_180006130(a1);
  }
  __unwind
  {
    sub_180002390(a1);
  }
  j_j_j__free_base(*a1);
}


// ===== sub_180005B80 @ 0x180005b80 size=0x2e =====
void __fastcall sub_180005B80(void **a1)
{
  __wind
  {
    sub_180006130(a1);
  }
  __unwind
  {
    sub_180002390(a1);
  }
  j_j_j__free_base(*a1);
}


// ===== sub_180005BB0 @ 0x180005bb0 size=0xb2 =====
void __fastcall sub_180005BB0(void **a1)
{
  __int64 *v2; // rbx
  __int64 **v3; // rax
  __int64 *i; // rax
  __int64 *j; // rcx

  __wind
  {
    v2 = *(__int64 **)*a1;
    while ( v2 != *a1 )
    {
      DeleteObject((HGDIOBJ)v2[5]);
      v3 = (__int64 **)v2[2];
      if ( *((_BYTE *)v3 + 25) != 0 )
      {
        for ( i = (__int64 *)v2[1]; *((_BYTE *)i + 25) == 0; i = (__int64 *)i[1] )
        {
          if ( v2 != (__int64 *)i[2] )
            break;
          v2 = i;
        }
        v2 = i;
      }
      else
      {
        v2 = (__int64 *)v2[2];
        for ( j = *v3; *((_BYTE *)j + 25) == 0; j = (__int64 *)*j )
          v2 = j;
      }
    }
    sub_180006130(a1);
  }
  __unwind
  {
    sub_180005B80(a1);
  }
  __wind
  {
    sub_180006130(a1);
  }
  __unwind
  {
    sub_180002390(a1);
  }
  j_j_j__free_base(*a1);
}


// ===== sub_180005C70 @ 0x180005c70 size=0x21a =====
HRESULT __fastcall sub_180005C70(__int64 a1, void *a2, HDC a3, HICON a4, LONG *a5)
{
  HRESULT result; // eax
  LONG v8; // r9d
  RGBQUAD *v9; // rbx
  RGBQUAD *v10; // rdx
  LONG v11; // r8d
  int v12; // eax
  int v13; // edi
  HBITMAP hbmMask; // r14
  int v15; // esi
  HANDLE ProcessHeap; // r13
  void *lpvBits; // r15
  int DIBits; // eax
  LONG biHeight; // r9d
  LONG biWidth; // edx
  int *v21; // rcx
  unsigned int v22; // esi
  int v23; // eax
  int pcxRow; // [rsp+40h] [rbp-51h] BYREF
  RGBQUAD *ppbBuffer; // [rsp+48h] [rbp-49h] BYREF
  ICONINFO piconinfo; // [rsp+50h] [rbp-41h] BYREF
  struct tagBITMAPINFO bmi; // [rsp+70h] [rbp-21h] BYREF

  result = GetBufferedPaintBits(a2, &ppbBuffer, &pcxRow);
  if ( result >= 0 )
  {
    v8 = a5[1];
    v9 = ppbBuffer;
    if ( v8 != 0 )
    {
      v10 = ppbBuffer;
      while ( 1 )
      {
        v11 = *a5;
        if ( *a5 != 0 )
          break;
LABEL_7:
        v10 += (unsigned int)(pcxRow - *a5);
        if ( --v8 == 0 )
          goto LABEL_8;
      }
      while ( 1 )
      {
        v12 = (int)*v10++;
        if ( (v12 & 0xFF000000) != 0 )
          return 0;
        if ( --v11 == 0 )
          goto LABEL_7;
      }
    }
LABEL_8:
    if ( !GetIconInfo(a4, &piconinfo) )
      return 0;
    v13 = 0;
    hbmMask = piconinfo.hbmMask;
    if ( piconinfo.hbmMask != nullptr )
    {
      v15 = pcxRow;
      *(_QWORD *)&bmi.bmiHeader.biWidth = 0;
      memset(&bmi.bmiHeader.biSizeImage, 0, 24);
      bmi.bmiHeader.biWidth = *a5;
      bmi.bmiHeader.biHeight = a5[1];
      bmi.bmiHeader.biSize = 40;
      *(_QWORD *)&bmi.bmiHeader.biPlanes = 2097153;
      ProcessHeap = GetProcessHeap();
      lpvBits = HeapAlloc(ProcessHeap, 0, 4 * bmi.bmiHeader.biWidth * bmi.bmiHeader.biHeight);
      if ( lpvBits != nullptr )
      {
        DIBits = GetDIBits(a3, hbmMask, 0, bmi.bmiHeader.biHeight, lpvBits, &bmi, 0);
        biHeight = bmi.bmiHeader.biHeight;
        if ( DIBits == bmi.bmiHeader.biHeight )
        {
          biWidth = bmi.bmiHeader.biWidth;
          v21 = (int *)lpvBits;
          v22 = v15 - bmi.bmiHeader.biWidth;
          if ( bmi.bmiHeader.biHeight != 0 )
          {
            do
            {
              if ( biWidth != 0 )
              {
                do
                {
                  v23 = *v21++;
                  if ( v23 != 0 )
                    *v9 = 0;
                  else
                    *(_DWORD *)v9 |= 0xFF000000;
                  ++v9;
                  --biWidth;
                }
                while ( biWidth != 0 );
                biWidth = bmi.bmiHeader.biWidth;
              }
              v9 += v22;
              --biHeight;
            }
            while ( biHeight != 0 );
          }
          HeapFree(ProcessHeap, 0, lpvBits);
        }
        else
        {
          HeapFree(ProcessHeap, 0, lpvBits);
          v13 = -2147418113;
        }
      }
      else
      {
        v13 = -2147024882;
      }
    }
    DeleteObject(piconinfo.hbmColor);
    DeleteObject(piconinfo.hbmMask);
    return v13;
  }
  return result;
}


// ===== sub_180005E90 @ 0x180005e90 size=0x200 =====
HBITMAP __fastcall sub_180005E90(__int64 a1, HICON a2)
{
  int v3; // r12d
  int v4; // r13d
  HDC CompatibleDC; // rbx
  HBITMAP v6; // rax
  HBITMAP v7; // rdi
  HGDIOBJ v9; // r15
  HDC v10; // rcx
  HPAINTBUFFER v11; // r14
  int v12; // [rsp+50h] [rbp-49h] BYREF
  LONG SystemMetrics; // [rsp+58h] [rbp-41h] BYREF
  int yBottom; // [rsp+5Ch] [rbp-3Dh]
  HDC phdc; // [rsp+60h] [rbp-39h] BYREF
  __int64 v16; // [rsp+68h] [rbp-31h]
  BP_PAINTPARAMS pPaintParams; // [rsp+70h] [rbp-29h] BYREF
  BITMAPINFO pbmi; // [rsp+88h] [rbp-11h] BYREF
  struct tagRECT rc; // [rsp+B8h] [rbp+1Fh] BYREF

  v16 = a1;
  if ( a2 == nullptr )
    return nullptr;
  SystemMetrics = GetSystemMetrics(49);
  v3 = SystemMetrics;
  yBottom = GetSystemMetrics(50);
  v4 = yBottom;
  SetRect(&rc, 0, 0, SystemMetrics, yBottom);
  CompatibleDC = CreateCompatibleDC(nullptr);
  if ( CompatibleDC == nullptr )
    return nullptr;
  memset(&pbmi.bmiHeader.biSizeImage, 0, 24);
  pbmi.bmiHeader.biSize = 40;
  *(_QWORD *)&pbmi.bmiHeader.biPlanes = 2097153;
  pbmi.bmiHeader.biWidth = SystemMetrics;
  pbmi.bmiHeader.biHeight = yBottom;
  v6 = CreateDIBSection(CompatibleDC, &pbmi, 0, nullptr, nullptr, 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v9 = SelectObject(CompatibleDC, v6);
    v10 = CompatibleDC;
    if ( v9 != nullptr )
    {
      v12 = 33488896;
      pPaintParams.pBlendFunction = (const BLENDFUNCTION *)&v12;
      pPaintParams.prcExclude = nullptr;
      pPaintParams.cbSize = 24;
      pPaintParams.dwFlags = 1;
      v11 = BeginBufferedPaint(CompatibleDC, &rc, BPBF_DIB, &pPaintParams, &phdc);
      if ( v11 != nullptr )
      {
        if ( DrawIconEx(phdc, 0, 0, a2, v3, v4, 0, nullptr, 3u) )
          sub_180005C70(v16, v11, CompatibleDC, a2, &SystemMetrics);
        EndBufferedPaint(v11, true);
      }
      SelectObject(CompatibleDC, v9);
      v10 = CompatibleDC;
    }
    DeleteDC(v10);
    return v7;
  }
  else
  {
    DeleteDC(CompatibleDC);
    return nullptr;
  }
}


// ===== sub_180006090 @ 0x180006090 size=0x37 =====
_QWORD *__fastcall sub_180006090(__int64 a1)
{
  _QWORD *result; // rax

  result = operator new(0x30u);
  try
  {
    *result = result;
    result[1] = result;
    result[2] = result;
  }
  catch ( ... )
  {
    sub_180005950(a1, result, 1);
    throw;
  }
  *((_WORD *)result + 12) = 257;
  return result;
}


// ===== sub_1800060D0 @ 0x1800060d0 size=0x55 =====
void __fastcall sub_1800060D0(__int64 a1, void *a2)
{
  void *v2; // rdi
  _QWORD *v4; // rbx

  v2 = a2;
  v4 = a2;
  if ( *((_BYTE *)a2 + 25) == 0 )
  {
    do
    {
      sub_1800060D0(a1, v4[2]);
      v4 = (_QWORD *)*v4;
      j_j_j__free_base(v2);
      v2 = v4;
    }
    while ( *((_BYTE *)v4 + 25) == 0 );
  }
}


// ===== sub_180006130 @ 0x180006130 size=0x8c =====
__int64 __fastcall sub_180006130(_QWORD *a1)
{
  __int64 v2; // rbp
  void **v3; // rsi
  void **v4; // rbx
  __int64 v5; // rax
  __int64 result; // rax

  v2 = *a1;
  v3 = *(void ***)(*a1 + 8LL);
  v4 = v3;
  v5 = *a1;
  if ( *((_BYTE *)v3 + 25) == 0 )
  {
    do
    {
      sub_1800060D0((__int64)a1, v4[2]);
      v4 = (void **)*v4;
      j_j_j__free_base(v3);
      v3 = v4;
    }
    while ( *((_BYTE *)v4 + 25) == 0 );
    v5 = *a1;
  }
  *(_QWORD *)(v5 + 8) = v2;
  *(_QWORD *)*a1 = v2;
  result = *a1;
  *(_QWORD *)(*a1 + 16LL) = v2;
  a1[1] = 0;
  return result;
}


// ===== sub_1800061C0 @ 0x1800061c0 size=0x18 =====
__int64 __fastcall sub_1800061C0(__int64 a1, __int64 a2)
{
  return (*(__int64 (__fastcall **)(__int64, const wchar_t *, const wchar_t *))(*(_QWORD *)a2 + 24LL))(
           a2,
           L"APPID",
           L"{FF2EA936-C1E1-428D-9572-F4285AFC4F48}");
}


// ===== sub_1800061E0 @ 0x1800061e0 size=0x44 =====
void *__fastcall sub_1800061E0(void *Block, char a2)
{
  sub_1800062E0(Block);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(Block);
  return Block;
}


// ===== sub_180006230 @ 0x180006230 size=0xd =====
__int64 __fastcall sub_180006230(__int64 a1)
{
  return (unsigned int)_InterlockedIncrement((volatile signed __int32 *)(a1 + 12));
}


// ===== sub_180006240 @ 0x180006240 size=0xd =====
__int64 __fastcall sub_180006240(__int64 a1)
{
  return (unsigned int)_InterlockedDecrement((volatile signed __int32 *)(a1 + 12));
}


// ===== sub_180006250 @ 0x180006250 size=0x4 =====
__int64 __fastcall sub_180006250(__int64 a1)
{
  return *(unsigned int *)(a1 + 12);
}


// ===== sub_180006260 @ 0x180006260 size=0x74 =====
__int64 __fastcall sub_180006260(__int64 a1, _QWORD *a2)
{
  _QWORD *v4; // rbx
  unsigned int Instance; // edi

  if ( a2 == nullptr )
    return 2147500035LL;
  v4 = (_QWORD *)(a1 + 64);
  Instance = 0;
  if ( *(_QWORD *)(a1 + 64) != 0
    || ((Instance = CoCreateInstance(&rclsid, nullptr, 1u, &riid, (LPVOID *)(a1 + 64))) & 0x80000000) == 0 )
  {
    *a2 = *v4;
    (*(void (__fastcall **)(_QWORD))(*(_QWORD *)*v4 + 8LL))(*v4);
  }
  return Instance;
}


// ===== sub_1800062E0 @ 0x1800062e0 size=0x5f =====
__int64 __fastcall sub_1800062E0(__int64 a1)
{
  unsigned __int64 v2; // rbx
  unsigned __int64 i; // rdx

  __wind
  {
    v2 = qword_18002A210;
    for ( i = qword_18002A218; v2 < i; v2 += 8LL )
    {
      if ( *(_QWORD *)v2 != 0 )
      {
        (*(void (__fastcall **)(_QWORD))(*(_QWORD *)v2 + 56LL))(0);
        i = qword_18002A218;
      }
    }
  }
  __unwind
  {
    sub_180006340(a1);
  }
  return sub_1800063D0(a1);
}


// ===== sub_180006340 @ 0x180006340 size=0x1b =====
__int64 __fastcall sub_180006340(__int64 a1)
{
  return sub_1800063D0(a1);
}


// ===== sub_180006360 @ 0x180006360 size=0x22 =====
void __fastcall sub_180006360(__int64 a1)
{
  if ( *(_BYTE *)(a1 + 8) != 0 )
  {
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)a1);
    *(_BYTE *)(a1 + 8) = 0;
  }
}


// ===== sub_180006390 @ 0x180006390 size=0x26 =====
__int64 __fastcall sub_180006390(__int64 *a1)
{
  __int64 v1; // rcx
  __int64 result; // rax

  v1 = *a1;
  if ( v1 != 0 )
    return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v1 + 16LL))(v1);
  return result;
}


// ===== sub_1800063D0 @ 0x1800063d0 size=0xac =====
void __fastcall sub_1800063D0(__int64 a1)
{
  __int64 v1; // r14
  _QWORD *v3; // rdi
  _QWORD *v4; // rbx
  __int64 v5; // rcx

  v1 = a1 + 8;
  if ( *(_DWORD *)(a1 + 8) != 0 )
  {
    if ( *(_QWORD *)(a1 + 16) != 0 )
    {
      if ( a1 == -8 )
      {
        sub_1800056C0(0xC0000005, 1u);
        JUMPOUT(0x18000647BLL);
      }
      v3 = *(_QWORD **)(a1 + 16);
      if ( v3 != nullptr )
      {
        do
        {
          ((void (__fastcall *)(_QWORD))*v3)(v3[1]);
          v4 = (_QWORD *)v3[2];
          j_j_j__free_base(v3);
          v3 = v4;
        }
        while ( v4 != nullptr );
      }
      *(_QWORD *)(v1 + 8) = 0;
      *(_QWORD *)(a1 + 16) = 0;
    }
    v5 = *(_QWORD *)(a1 + 64);
    if ( v5 != 0 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 16LL))(v5);
    DeleteCriticalSection((LPCRITICAL_SECTION)(a1 + 24));
    *(_DWORD *)v1 = 0;
  }
}


// ===== sub_180006490 @ 0x180006490 size=0x19f =====
__int64 __fastcall sub_180006490(_QWORD *a1, int a2, _QWORD *a3)
{
  int v7; // edi
  __int64 *v8; // rbx
  __int64 v9; // rsi
  __int64 v10; // rcx
  HMODULE ModuleHandleW; // rax
  HRESULT (__stdcall *UnRegisterTypeLibForUser)(const GUID *const, WORD, WORD, LCID, SYSKIND); // r10
  BSTR bstrString[7]; // [rsp+30h] [rbp-38h] BYREF
  __int64 v14; // [rsp+70h] [rbp+8h] BYREF
  __int64 v15; // [rsp+88h] [rbp+20h] BYREF

  bstrString[1] = (BSTR)-2LL;
  if ( a1 == nullptr )
    return 2147942487LL;
  v7 = 0;
  v8 = (__int64 *)a1[2];
  if ( (unsigned __int64)v8 >= a1[3] )
  {
LABEL_11:
    if ( a2 != 0 )
    {
      v10 = a1[1];
      bstrString[0] = nullptr;
      __wind
      {
        v14 = 0;
        __wind
        {
          v7 = sub_180006630(v10, 0, bstrString, &v14);
          if ( v7 >= 0 )
          {
            v7 = (*(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v14 + 56LL))(v14, &v15);
            if ( v7 >= 0 )
            {
              if ( byte_18002A140 != 1
                || (ModuleHandleW = GetModuleHandleW(L"OLEAUT32.DLL")) == nullptr
                || (UnRegisterTypeLibForUser = (HRESULT (__stdcall *)(const GUID *const, WORD, WORD, LCID, SYSKIND))GetProcAddress(ModuleHandleW, "UnRegisterTypeLibForUser")) == nullptr )
              {
                UnRegisterTypeLibForUser = UnRegisterTypeLib;
              }
              v7 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _DWORD))UnRegisterTypeLibForUser)(
                     v15,
                     *(unsigned __int16 *)(v15 + 24),
                     *(unsigned __int16 *)(v15 + 26),
                     *(unsigned int *)(v15 + 16),
                     *(_DWORD *)(v15 + 20));
              (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v14 + 96LL))(v14, v15);
            }
          }
        }
        __unwind
        {
          sub_180006390(&v14);
        }
        if ( v14 != 0 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16LL))(v14);
      }
      __unwind
      {
        sub_180006480(bstrString);
      }
      SysFreeString(bstrString[0]);
    }
  }
  else
  {
    while ( 1 )
    {
      v9 = *v8;
      if ( *v8 != 0 && (a3 == nullptr || *a3 == **(_QWORD **)v9 && a3[1] == *(_QWORD *)(*(_QWORD *)v9 + 8LL)) )
      {
        (*(void (**)(void))(v9 + 48))();
        v7 = sub_180006850(*(GUID **)v9);
        if ( v7 < 0 )
          break;
        v7 = (*(__int64 (__fastcall **)(_QWORD))(v9 + 8))(0);
        if ( v7 < 0 )
          break;
      }
      if ( (unsigned __int64)++v8 >= a1[3] )
        goto LABEL_11;
    }
  }
  return (unsigned int)v7;
}


// ===== sub_180006490 @ 0x180006490 size=0x19f =====
__int64 __fastcall sub_180006490(_QWORD *a1, int a2, _QWORD *a3)
{
  int v7; // edi
  __int64 *v8; // rbx
  __int64 v9; // rsi
  __int64 v10; // rcx
  HMODULE ModuleHandleW; // rax
  HRESULT (__stdcall *UnRegisterTypeLibForUser)(const GUID *const, WORD, WORD, LCID, SYSKIND); // r10
  BSTR bstrString[7]; // [rsp+30h] [rbp-38h] BYREF
  __int64 v14; // [rsp+70h] [rbp+8h] BYREF
  __int64 v15; // [rsp+88h] [rbp+20h] BYREF

  bstrString[1] = (BSTR)-2LL;
  if ( a1 == nullptr )
    return 2147942487LL;
  v7 = 0;
  v8 = (__int64 *)a1[2];
  if ( (unsigned __int64)v8 >= a1[3] )
  {
LABEL_11:
    if ( a2 != 0 )
    {
      v10 = a1[1];
      bstrString[0] = nullptr;
      __wind
      {
        v14 = 0;
        __wind
        {
          v7 = sub_180006630(v10, 0, bstrString, &v14);
          if ( v7 >= 0 )
          {
            v7 = (*(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v14 + 56LL))(v14, &v15);
            if ( v7 >= 0 )
            {
              if ( byte_18002A140 != 1
                || (ModuleHandleW = GetModuleHandleW(L"OLEAUT32.DLL")) == nullptr
                || (UnRegisterTypeLibForUser = (HRESULT (__stdcall *)(const GUID *const, WORD, WORD, LCID, SYSKIND))GetProcAddress(ModuleHandleW, "UnRegisterTypeLibForUser")) == nullptr )
              {
                UnRegisterTypeLibForUser = UnRegisterTypeLib;
              }
              v7 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _DWORD))UnRegisterTypeLibForUser)(
                     v15,
                     *(unsigned __int16 *)(v15 + 24),
                     *(unsigned __int16 *)(v15 + 26),
                     *(unsigned int *)(v15 + 16),
                     *(_DWORD *)(v15 + 20));
              (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v14 + 96LL))(v14, v15);
            }
          }
        }
        __unwind
        {
          sub_180006390(&v14);
        }
        if ( v14 != 0 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16LL))(v14);
      }
      __unwind
      {
        sub_180006480(bstrString);
      }
      SysFreeString(bstrString[0]);
    }
  }
  else
  {
    while ( 1 )
    {
      v9 = *v8;
      if ( *v8 != 0 && (a3 == nullptr || *a3 == **(_QWORD **)v9 && a3[1] == *(_QWORD *)(*(_QWORD *)v9 + 8LL)) )
      {
        (*(void (**)(void))(v9 + 48))();
        v7 = sub_180006850(*(GUID **)v9);
        if ( v7 < 0 )
          break;
        v7 = (*(__int64 (__fastcall **)(_QWORD))(v9 + 8))(0);
        if ( v7 < 0 )
          break;
      }
      if ( (unsigned __int64)++v8 >= a1[3] )
        goto LABEL_11;
    }
  }
  return (unsigned int)v7;
}


// ===== sub_180006630 @ 0x180006630 size=0x212 =====
__int64 __fastcall sub_180006630(HMODULE a1, __int64 a2, BSTR *a3, ITypeLib **a4)
{
  DWORD ModuleFileNameW; // eax
  __int64 v8; // rbp
  HRESULT TypeLib; // ebx
  WCHAR *v10; // rcx
  wchar_t *v11; // rdi
  WCHAR i; // ax
  __int64 v13; // rax
  unsigned int v14; // ecx
  __int64 v15; // rcx
  errno_t v16; // eax
  BSTR v17; // rax
  _QWORD *v19; // [rsp+28h] [rbp-280h] BYREF
  wchar_t Source[8]; // [rsp+30h] [rbp-278h] BYREF
  WCHAR Filename[272]; // [rsp+40h] [rbp-268h] BYREF

  if ( a3 == nullptr || a4 == nullptr )
    return 2147500035LL;
  *a3 = nullptr;
  *a4 = nullptr;
  v19 = nullptr;
  __wind
  {
    ModuleFileNameW = GetModuleFileNameW(a1, Filename, 0x104u);
    v8 = ModuleFileNameW;
    if ( ModuleFileNameW == 0 )
      return (unsigned int)sub_180002F90();
    if ( ModuleFileNameW == 260 )
      return (unsigned int)-2147024774;
    v10 = Filename;
    v11 = nullptr;
    for ( i = Filename[0]; *v10 != 0; i = *v10 )
    {
      if ( i == 46 )
      {
        v11 = v10;
      }
      else if ( i == 92 )
      {
        v11 = nullptr;
      }
      v10 = CharNextW(v10);
    }
    if ( v11 == nullptr )
      v11 = v10;
    if ( a2 != 0 )
    {
      v13 = -1;
      do
        ++v13;
      while ( *(_WORD *)(a2 + 2 * v13) != 0 );
      v14 = v13 + v8;
      if ( (int)v13 + (int)v8 < (unsigned int)v8 || v14 < (unsigned int)v13 || v14 >= 0x10E )
        return (unsigned int)-2147467259;
      sub_180006F80(&Filename[v8], 270 - v8, a2);
    }
    TypeLib = LoadTypeLib(Filename, a4);
    if ( TypeLib < 0 )
    {
      wcscpy(Source, L".tlb");
      v15 = v11 - Filename;
      if ( (unsigned __int64)(v15 + 5) > 0x104 )
        return (unsigned int)-2147467259;
      v16 = wcscpy_s(v11, 270 - v15, Source);
      if ( v16 != 0 )
      {
        if ( v16 == 12 )
          sub_180002FC0(-2147024882);
        if ( v16 == 22 || v16 == 34 )
          sub_180002FC0(-2147024809);
        if ( v16 != 80 )
          sub_180002FC0(-2147467259);
      }
      TypeLib = LoadTypeLib(Filename, a4);
      if ( TypeLib < 0 )
        return (unsigned int)TypeLib;
    }
    v17 = SysAllocString(Filename);
    *a3 = v17;
    if ( v17 == nullptr )
    {
      TypeLib = -2147024882;
      ((void (__fastcall *)(ITypeLib *))(*a4)->lpVtbl->Release)(*a4);
      *a4 = nullptr;
    }
  }
  __unwind
  {
    sub_180002290(&v19);
  }
  return (unsigned int)TypeLib;
}


// ===== sub_180006850 @ 0x180006850 size=0x51a =====
__int64 __fastcall sub_180006850(GUID *rguid, __int64 a2, int a3)
{
  __int64 v4; // rbx
  unsigned int v6; // edi
  __int64 v7; // rax
  int v8; // eax
  errno_t v9; // eax
  errno_t v10; // eax
  errno_t v11; // eax
  HKEY v12; // rbx
  __int64 InfoKeyW; // rsi
  errno_t v14; // eax
  errno_t v15; // eax
  errno_t v16; // eax
  LSTATUS v17; // eax
  HKEY v18; // rbx
  __int64 v19; // rsi
  DWORD cSubKeys[2]; // [rsp+68h] [rbp-A0h] BYREF
  LPVOID ppv; // [rsp+70h] [rbp-98h] BYREF
  HKEY hKey; // [rsp+78h] [rbp-90h] BYREF
  int v24; // [rsp+80h] [rbp-88h]
  __int64 v25; // [rsp+88h] [rbp-80h]
  unsigned __int64 v26; // [rsp+90h] [rbp-78h] BYREF
  int v27; // [rsp+98h] [rbp-70h]
  __int64 v28; // [rsp+A0h] [rbp-68h]
  __int64 v29; // [rsp+A8h] [rbp-60h]
  _QWORD *v30; // [rsp+B0h] [rbp-58h] BYREF
  __int128 v31; // [rsp+B8h] [rbp-50h] BYREF
  wchar_t Destination[128]; // [rsp+C8h] [rbp-40h] BYREF
  OLECHAR sz[64]; // [rsp+1C8h] [rbp+C0h] BYREF

  v29 = -2;
  v4 = a2;
  v6 = 0;
  ppv = nullptr;
  __wind
  {
    if ( a2 == 0
      || rguid->Data1 == 0
      && *(_DWORD *)&rguid->Data2 == 0
      && *(_DWORD *)rguid->Data4 == 0
      && *(_DWORD *)&rguid->Data4[4] == 0
      || CoCreateInstance(&stru_18001B7C8, nullptr, 1u, &stru_18001B5E0, &ppv) < 0 )
    {
      v8 = 0;
      goto LABEL_71;
    }
    for ( ; *(_DWORD *)v4 != 0; v4 += 16 )
    {
      v31 = *(_OWORD *)*(_QWORD *)(v4 + 8);
      v7 = *(_QWORD *)ppv;
      if ( a3 != 0 )
      {
        if ( *(_DWORD *)v4 == 1 )
          v8 = (*(__int64 (__fastcall **)(LPVOID, GUID *, __int64, __int128 *))(v7 + 40))(ppv, rguid, 1, &v31);
        else
          v8 = (*(__int64 (__fastcall **)(LPVOID, GUID *, __int64, __int128 *))(v7 + 56))(ppv, rguid, 1, &v31);
        if ( v8 < 0 )
          goto LABEL_71;
      }
      else if ( *(_DWORD *)v4 == 1 )
      {
        (*(void (__fastcall **)(LPVOID, GUID *, __int64, __int128 *))(v7 + 48))(ppv, rguid, 1, &v31);
      }
      else
      {
        (*(void (__fastcall **)(LPVOID, GUID *, __int64, __int128 *))(v7 + 64))(ppv, rguid, 1, &v31);
      }
    }
    if ( a3 == 0 )
    {
      if ( StringFromGUID2(rguid, sz, 64) == 0 )
      {
        v8 = 13;
LABEL_71:
        v6 = v8;
        goto LABEL_93;
      }
      v30 = nullptr;
      __wind
      {
        v9 = wcscpy_s(Destination, 0x80u, L"CLSID\\");
        if ( v9 != 0 )
        {
          if ( v9 == 12 )
            sub_180002FC0(-2147024882);
          if ( v9 == 22 || v9 == 34 )
            sub_180002FC0(-2147024809);
          if ( v9 != 80 )
            sub_180002FC0(-2147467259);
        }
        v10 = wcscat_s(Destination, 0x80u, sz);
        if ( v10 != 0 )
        {
          if ( v10 == 12 )
            sub_180002FC0(-2147024882);
          if ( v10 == 22 || v10 == 34 )
            sub_180002FC0(-2147024809);
          if ( v10 != 80 )
            sub_180002FC0(-2147467259);
        }
        v11 = wcscat_s(Destination, 0x80u, L"\\Required Categories");
        if ( v11 != 0 )
        {
          if ( v11 == 12 )
            sub_180002FC0(-2147024882);
          if ( v11 == 22 || v11 == 34 )
            sub_180002FC0(-2147024809);
          if ( v11 != 80 )
            sub_180002FC0(-2147467259);
        }
        v26 = 0xFFFFFFFF80000000uLL;
        v27 = 0;
        v28 = 0;
        __wind
        {
          hKey = nullptr;
          v24 = 0;
          v25 = 0;
          __wind
          {
            cSubKeys[0] = 0;
            if ( sub_180003690((__int64)&hKey, HKEY_CLASSES_ROOT, Destination, 0x20019u) == 0 )
            {
              v12 = hKey;
              InfoKeyW = RegQueryInfoKeyW(
                           hKey,
                           nullptr,
                           nullptr,
                           nullptr,
                           cSubKeys,
                           nullptr,
                           nullptr,
                           nullptr,
                           nullptr,
                           nullptr,
                           nullptr,
                           nullptr);
              if ( v12 != nullptr )
              {
                RegCloseKey(v12);
                hKey = nullptr;
              }
              v24 = 0;
              if ( InfoKeyW == 0 && cSubKeys[0] == 0 )
                sub_180003180((__int64)&v26, Destination);
            }
            v14 = wcscpy_s(Destination, 0x80u, L"CLSID\\");
            if ( v14 != 0 )
            {
              if ( v14 == 12 )
                sub_180002FC0(-2147024882);
              if ( v14 == 22 || v14 == 34 )
                sub_180002FC0(-2147024809);
              if ( v14 != 80 )
                sub_180002FC0(-2147467259);
            }
            v15 = wcscat_s(Destination, 0x80u, sz);
            if ( v15 != 0 )
            {
              if ( v15 == 12 )
                sub_180002FC0(-2147024882);
              if ( v15 == 22 || v15 == 34 )
                sub_180002FC0(-2147024809);
              if ( v15 != 80 )
                sub_180002FC0(-2147467259);
            }
            v16 = wcscat_s(Destination, 0x80u, L"\\Implemented Categories");
            if ( v16 != 0 )
            {
              if ( v16 == 12 )
                sub_180002FC0(-2147024882);
              if ( v16 == 22 || v16 == 34 )
                sub_180002FC0(-2147024809);
              if ( v16 != 80 )
                sub_180002FC0(-2147467259);
            }
            v17 = sub_180003690((__int64)&hKey, HKEY_CLASSES_ROOT, Destination, 0x20019u);
            v18 = hKey;
            if ( v17 == 0 )
            {
              v19 = RegQueryInfoKeyW(
                      hKey,
                      nullptr,
                      nullptr,
                      nullptr,
                      cSubKeys,
                      nullptr,
                      nullptr,
                      nullptr,
                      nullptr,
                      nullptr,
                      nullptr,
                      nullptr);
              if ( v18 != nullptr )
              {
                RegCloseKey(v18);
                v18 = nullptr;
                hKey = nullptr;
              }
              v24 = 0;
              if ( v19 == 0 && cSubKeys[0] == 0 )
                sub_180003180((__int64)&v26, Destination);
            }
          }
          __unwind
          {
            sub_180002610((__int64)&hKey);
          }
          if ( v18 != nullptr )
          {
            RegCloseKey(v18);
            hKey = nullptr;
          }
          v24 = 0;
        }
        __unwind
        {
          sub_180002610((__int64)&v26);
        }
        RegCloseKey(HKEY_CLASSES_ROOT);
        v26 = 0;
        v27 = 0;
      }
      __unwind
      {
        sub_180002290(&v30);
      }
    }
  }
  __unwind
  {
    sub_180006390((__int64 *)&ppv);
  }
LABEL_93:
  if ( ppv != nullptr )
    (*(void (__fastcall **)(LPVOID))(*(_QWORD *)ppv + 16LL))(ppv);
  return v6;
}


// ===== sub_180006D70 @ 0x180006d70 size=0x20b =====
__int64 __fastcall sub_180006D70(HMODULE a1, __int64 a2)
{
  WCHAR *v2; // rbp
  int v3; // edi
  UINT v4; // eax
  errno_t v5; // eax
  __int64 v6; // rdx
  unsigned __int64 v7; // rcx
  __int64 v8; // r8
  WCHAR *v9; // rsi
  WCHAR *v10; // rdi
  __int64 v11; // r14
  LPWSTR v12; // rax
  __int64 v13; // rsi
  HMODULE ModuleHandleW; // rax
  HRESULT (__stdcall *RegisterTypeLibForUser)(ITypeLib *, OLECHAR *, OLECHAR *); // rax
  BSTR pbstr; // [rsp+30h] [rbp-258h] BYREF
  ITypeLib *v18; // [rsp+38h] [rbp-250h] BYREF
  BSTR bstrString[2]; // [rsp+40h] [rbp-248h] BYREF
  WCHAR sz[264]; // [rsp+50h] [rbp-238h] BYREF

  bstrString[1] = (BSTR)-2LL;
  v2 = nullptr;
  bstrString[0] = nullptr;
  __wind
  {
    v18 = nullptr;
    __wind
    {
      v3 = sub_180006630(a1, a2, bstrString, &v18);
      if ( v3 >= 0 )
      {
        pbstr = nullptr;
        __wind
        {
          if ( ((int (__fastcall *)(ITypeLib *, __int64, _QWORD, _QWORD, _QWORD, BSTR *))v18->lpVtbl->GetDocumentation)(
                 v18,
                 0xFFFFFFFFLL,
                 0,
                 0,
                 0,
                 &pbstr) >= 0
            && pbstr != nullptr )
          {
            v4 = SysStringLen(pbstr);
            v5 = wcsncpy_s(sz, 0x104u, pbstr, v4);
            if ( v5 != 0 )
            {
              if ( v5 == 12 )
                sub_180002FC0(-2147024882);
              if ( v5 == 22 || v5 == 34 )
                sub_180002FC0(-2147024809);
              if ( v5 != 80 )
                sub_180002FC0(-2147467259);
            }
            sz[259] = 0;
            v9 = sz;
            v10 = sz;
            if ( sz[0] != 0 )
            {
              v11 = 0x200000000801LL;
              do
              {
                v12 = CharNextW(v10);
                v7 = *v10;
                LOWORD(v7) = v7 - 47;
                if ( (unsigned __int16)v7 <= 0x2Du && _bittest64(&v11, v7) )
                  v9 = v12;
                v10 = v12;
              }
              while ( *v12 != 0 );
            }
            v13 = v9 - sz;
            if ( 2 * (unsigned __int64)(unsigned int)v13 >= 0x208 )
              _report_rangecheckfailure(v7, v6, v8);
            sz[(unsigned int)v13] = 0;
            v2 = sz;
          }
          if ( byte_18002A140 != 1
            || (ModuleHandleW = GetModuleHandleW(L"OLEAUT32.DLL")) == nullptr
            || (RegisterTypeLibForUser = (HRESULT (__stdcall *)(ITypeLib *, OLECHAR *, OLECHAR *))GetProcAddress(
                                                                                                    ModuleHandleW,
                                                                                                    "RegisterTypeLibForUser")) == nullptr )
          {
            RegisterTypeLibForUser = (HRESULT (__stdcall *)(ITypeLib *, OLECHAR *, OLECHAR *))RegisterTypeLib;
          }
          v3 = ((__int64 (__fastcall *)(ITypeLib *, BSTR, WCHAR *))RegisterTypeLibForUser)(v18, bstrString[0], v2);
        }
        __unwind
        {
          sub_180006480(&pbstr);
        }
        SysFreeString(pbstr);
      }
    }
    __unwind
    {
      sub_180006390((__int64 *)&v18);
    }
    if ( v18 != nullptr )
      ((void (__fastcall *)(ITypeLib *))v18->lpVtbl->Release)(v18);
  }
  __unwind
  {
    sub_180006480(bstrString);
  }
  SysFreeString(bstrString[0]);
  return (unsigned int)v3;
}


// ===== sub_180006F80 @ 0x180006f80 size=0x47 =====
errno_t __fastcall sub_180006F80(wchar_t *a1, rsize_t a2, const wchar_t *a3)
{
  errno_t result; // eax

  result = wcscpy_s(a1, a2, a3);
  if ( result != 0 )
  {
    if ( result == 12 )
      sub_180002FC0(-2147024882);
    if ( result == 22 || result == 34 )
      sub_180002FC0(-2147024809);
    if ( result != 80 )
      sub_180002FC0(-2147467259);
  }
  return result;
}


// ===== DllCanUnloadNow @ 0x180006fd0 size=0x23 =====
HRESULT __stdcall DllCanUnloadNow()
{
  return (*(__int64 (__fastcall **)(__int64 *))(qword_18002A1A0 + 24))(&qword_18002A1A0) != 0;
}


// ===== DllGetClassObject @ 0x180007000 size=0x15c =====
HRESULT __stdcall DllGetClassObject(const IID *const rclsid, const IID *const riid, LPVOID *ppv)
{
  HRESULT v7; // edi
  __int64 *i; // rcx
  __int64 v9; // rbx
  _DWORD *v10; // rdx
  void **v11; // rsi
  void *v12; // rcx
  __int64 (__fastcall ***v13)(PVOID, const IID *const, LPVOID *); // rax
  struct _RTL_CRITICAL_SECTION *v14; // [rsp+28h] [rbp-30h] BYREF
  char v15; // [rsp+30h] [rbp-28h]
  PVOID Ptr; // [rsp+70h] [rbp+18h] BYREF

  if ( ppv == nullptr )
    return -2147467261;
  *ppv = nullptr;
  if ( dword_18002A200 == 0 )
    return -2147418113;
  v7 = 0;
  for ( i = (__int64 *)qword_18002A210; (unsigned __int64)i < qword_18002A218; ++i )
  {
    v9 = *i;
    if ( *i != 0 && *(_QWORD *)(v9 + 16) != 0 )
    {
      v10 = *(_DWORD **)v9;
      if ( rclsid->Data1 == **(_DWORD **)v9
        && *(_DWORD *)&rclsid->Data2 == v10[1]
        && *(_DWORD *)rclsid->Data4 == v10[2]
        && *(_DWORD *)&rclsid->Data4[4] == v10[3] )
      {
        v11 = *(void ***)(v9 + 32);
        v12 = *v11;
        if ( *v11 != nullptr )
          goto LABEL_20;
        v14 = &CriticalSection;
        v15 = 0;
        __wind
        {
          EnterCriticalSection(&CriticalSection);
          v15 = 1;
          v7 = 0;
          if ( *v11 == nullptr )
          {
            Ptr = nullptr;
            v7 = (*(__int64 (__fastcall **)(_QWORD, void *, PVOID *))(v9 + 16))(
                   *(_QWORD *)(v9 + 24),
                   &unk_18001B5C0,
                   &Ptr);
            if ( v7 >= 0 )
              *v11 = EncodePointer(Ptr);
          }
        }
        __unwind
        {
          sub_180006360((__int64)&v14);
        }
        LeaveCriticalSection(&CriticalSection);
        v15 = 0;
        v12 = *v11;
        if ( *v11 != nullptr )
        {
LABEL_20:
          v13 = (__int64 (__fastcall ***)(PVOID, const IID *const, LPVOID *))DecodePointer(v12);
          v7 = (**v13)(v13, riid, ppv);
        }
        break;
      }
    }
  }
  if ( *ppv == nullptr && v7 == 0 )
    return -2147221231;
  return v7;
}


// ===== DllMain @ 0x180007160 size=0xde =====
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  if ( fdwReason == 2 )
  {
    if ( dword_18002A190 == 0 || LoadLibraryW(L"ntdll.dll") == nullptr )
      return true;
    return sub_180062591();
  }
  else
  {
    return fdwReason != 1 || byte_18002A178 == 0;
  }
}


// ===== DllRegisterServer @ 0x180007240 size=0x10f =====
HRESULT __stdcall DllRegisterServer()
{
  LCID ThreadLocale; // ebp
  HRESULT v1; // ebx
  unsigned __int64 v2; // rax
  __int64 *v3; // rdi
  __int64 v4; // rsi
  __int64 v5; // rax
  __int64 v7[2]; // [rsp+20h] [rbp-28h] BYREF
  __int128 v8; // [rsp+30h] [rbp-18h]

  ThreadLocale = GetThreadLocale();
  SetThreadLocale(0x800u);
  v7[0] = (__int64)L"APPID";
  v7[1] = (__int64)L"{FF2EA936-C1E1-428D-9572-F4285AFC4F48}";
  v8 = 0;
  v1 = sub_1800052F0(qword_18002A148, 0x65u, 1, v7);
  if ( v1 >= 0 )
  {
    v2 = qword_18002A218;
    v3 = (__int64 *)qword_18002A210;
    if ( qword_18002A210 < (unsigned __int64)qword_18002A218 )
    {
      do
      {
        v4 = *v3;
        if ( *v3 != 0 )
        {
          v1 = (*(__int64 (__fastcall **)(__int64))(v4 + 8))(1);
          if ( v1 < 0 )
            goto LABEL_9;
          v5 = (*(__int64 (**)(void))(v4 + 48))();
          v1 = sub_180006850(*(GUID **)v4, v5, 1);
          if ( v1 < 0 )
            goto LABEL_9;
          v2 = qword_18002A218;
        }
        ++v3;
      }
      while ( (unsigned __int64)v3 < v2 );
    }
    v1 = sub_180006D70((HMODULE)qword_18002A208, 0);
LABEL_9:
    if ( v1 >= 0 && qword_18002A180 != nullptr )
      v1 = qword_18002A180(hModule);
  }
  SetThreadLocale(ThreadLocale);
  return v1;
}


// ===== DllUnregisterServer @ 0x180007350 size=0x9a =====
HRESULT __stdcall DllUnregisterServer()
{
  LCID ThreadLocale; // edi
  HRESULT v1; // ebx
  __int64 v3[2]; // [rsp+20h] [rbp-28h] BYREF
  __int128 v4; // [rsp+30h] [rbp-18h]

  ThreadLocale = GetThreadLocale();
  SetThreadLocale(0x800u);
  if ( qword_18002A188 == nullptr || (v1 = qword_18002A188()) >= 0 )
    v1 = sub_180006490(&dword_18002A200, 1, nullptr);
  if ( v1 >= 0 )
  {
    v3[0] = (__int64)L"APPID";
    v3[1] = (__int64)L"{FF2EA936-C1E1-428D-9572-F4285AFC4F48}";
    v4 = 0;
    v1 = sub_1800052F0(qword_18002A148, 0x65u, 0, v3);
  }
  SetThreadLocale(ThreadLocale);
  return v1;
}


// ===== SetWorkMode @ 0x1800073f0 size=0x7 =====
void __fastcall SetWorkMode(int a1)
{
  dword_18002A190 = a1;
}


// ===== sub_1800073F8 @ 0x1800073f8 size=0xa5 =====
__int64 __fastcall sub_1800073F8(__int64 a1)
{
  signed int LastError; // eax
  signed int v3; // ecx

  sub_180009D50(a1 + 40, 0, 40);
  *(_QWORD *)(a1 + 80) = 0;
  *(_DWORD *)(a1 + 88) = 0;
  *(_DWORD *)(a1 + 92) = 0;
  *(_QWORD *)(a1 + 16) = &_ImageBase;
  *(_QWORD *)(a1 + 8) = &_ImageBase;
  *(_QWORD *)(a1 + 32) = &unk_18001B7D8;
  *(_DWORD *)a1 = 96;
  *(_DWORD *)(a1 + 24) = 3584;
  if ( !InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a1 + 40), 0) )
  {
    LastError = GetLastError();
    v3 = (unsigned __int16)LastError | 0x80070000;
    if ( LastError <= 0 )
      v3 = LastError;
    if ( v3 < 0 )
    {
      if ( IsDebuggerPresent() )
        OutputDebugStringW(L"ERROR : Unable to initialize critical section in CAtlBaseModule\n");
      byte_18002A178 = 1;
    }
  }
  return a1;
}


// ===== sub_1800074A0 @ 0x1800074a0 size=0x34 =====
void __fastcall sub_1800074A0(struct _RTL_CRITICAL_SECTION *a1)
{
  PRTL_CRITICAL_SECTION_DEBUG DebugInfo; // rcx

  DeleteCriticalSection(a1 + 1);
  DebugInfo = a1[2].DebugInfo;
  if ( DebugInfo != nullptr )
  {
    j__free_base(DebugInfo);
    a1[2].DebugInfo = nullptr;
  }
  a1[2].LockCount = 0;
  a1[2].RecursionCount = 0;
}


// ===== sub_1800074D4 @ 0x1800074d4 size=0x3f =====
_QWORD *__fastcall sub_1800074D4(_QWORD *a1, __int64 a2)
{
  *a1 = &std::exception::`vftable';
  a1[1] = 0;
  a1[2] = 0;
  _std_exception_copy(a2 + 8);
  *a1 = &std::bad_alloc::`vftable';
  return a1;
}


// ===== sub_180007514 @ 0x180007514 size=0x1e =====
_QWORD *__fastcall sub_180007514(_QWORD *a1)
{
  a1[2] = 0;
  a1[1] = "bad allocation";
  *a1 = &std::bad_alloc::`vftable';
  return a1;
}


// ===== ??0exception@std@@QEAA@AEBV01@@Z @ 0x180007534 size=0x35 =====
std::exception *__fastcall std::exception::exception(std::exception *this, const struct std::exception *a2)
{
  *(_QWORD *)this = &std::exception::`vftable';
  *((_QWORD *)this + 1) = 0;
  *((_QWORD *)this + 2) = 0;
  _std_exception_copy((char *)a2 + 8);
  return this;
}


// ===== sub_18000756C @ 0x18000756c size=0x3f =====
_QWORD *__fastcall sub_18000756C(_QWORD *a1, __int64 a2)
{
  *a1 = &std::exception::`vftable';
  a1[1] = 0;
  a1[2] = 0;
  _std_exception_copy(a2 + 8);
  *a1 = &std::length_error::`vftable';
  return a1;
}


// ===== sub_1800075AC @ 0x1800075ac size=0x4a =====
_QWORD *__fastcall sub_1800075AC(_QWORD *a1, __int64 a2)
{
  __int64 v4; // [rsp+20h] [rbp-18h] BYREF
  char v5; // [rsp+28h] [rbp-10h]

  v5 = 1;
  v4 = a2;
  *a1 = &std::exception::`vftable';
  a1[1] = 0;
  a1[2] = 0;
  _std_exception_copy(&v4);
  *a1 = &std::length_error::`vftable';
  return a1;
}


// ===== sub_1800075F8 @ 0x1800075f8 size=0x3f =====
_QWORD *__fastcall sub_1800075F8(_QWORD *a1, __int64 a2)
{
  *a1 = &std::exception::`vftable';
  a1[1] = 0;
  a1[2] = 0;
  _std_exception_copy(a2 + 8);
  *a1 = &std::logic_error::`vftable';
  return a1;
}


// ===== ??1agent@Concurrency@@UEAA@XZ @ 0x180007638 size=0x13 =====
void __fastcall Concurrency::agent::~agent(Concurrency::agent *this)
{
  *(_QWORD *)this = &std::exception::`vftable';
  _std_exception_destroy((char *)this + 8);
}


// ===== unknown_libname_21 @ 0x18000764c size=0x42 =====
// Microsoft VisualC v14 64bit runtime
char *__fastcall unknown_libname_21(char *Block, char a2)
{
  *(_QWORD *)Block = &std::exception::`vftable';
  _std_exception_destroy(Block + 8);
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(Block);
  return Block;
}


// ===== sub_180007690 @ 0x180007690 size=0x23 =====
void __fastcall __noreturn sub_180007690(__int64 a1)
{
  _QWORD pExceptionObject[5]; // [rsp+20h] [rbp-28h] BYREF

  sub_1800075AC(pExceptionObject, a1);
  throw (std::length_error *)pExceptionObject;
}


// ===== ?get_unexpected_or_default@@YAP6AXXZQEBU__vcrt_ptd@@@Z @ 0x1800076b4 size=0x12 =====
// Microsoft VisualC v7/14 64bit runtime
void (*__fastcall get_unexpected_or_default(const struct __vcrt_ptd *const a1))()
{
  void (*result)(); // rax

  result = (void (*)())"Unknown exception";
  if ( *((_QWORD *)a1 + 1) != 0 )
    return *((void (**)())a1 + 1);
  return result;
}


// ===== sub_1800076C8 @ 0x1800076c8 size=0x2b =====
_QWORD *__fastcall sub_1800076C8(_QWORD *a1, char a2)
{
  *a1 = &type_info::`vftable';
  if ( (a2 & 1) != 0 )
    j_j_j__free_base(a1);
  return a1;
}


// ===== ??2@YAPEAX_K@Z @ 0x1800076f4 size=0x3c =====
void *__fastcall operator new(size_t Size)
{
  size_t i; // rbx
  void *result; // rax

  for ( i = Size; ; Size = i )
  {
    result = j__malloc_base(Size);
    if ( result != nullptr )
      break;
    if ( callnewh(i) == 0 )
    {
      if ( i != -1 )
        Concurrency::cancel_current_task();
      Concurrency::cancel_current_task();
    }
  }
  return result;
}


// ===== j_j_j__free_base @ 0x180007730 size=0x5 =====
// attributes: thunk
void __cdecl j_j_j__free_base(void *Block)
{
  j_j__free_base(Block);
}


// ===== j_??2@YAPEAX_K@Z @ 0x180007738 size=0x5 =====
// attributes: thunk
void *__fastcall operator new(size_t Size)
{
  return ??2@YAPEAX_K@Z(Size);
}


// ===== __raise_securityfailure @ 0x180007740 size=0x34 =====
BOOL __fastcall _raise_securityfailure(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
  HANDLE CurrentProcess; // rax

  SetUnhandledExceptionFilter(nullptr);
  UnhandledExceptionFilter(ExceptionInfo);
  CurrentProcess = GetCurrentProcess();
  return TerminateProcess(CurrentProcess, 0xC0000409);
}


// ===== __report_gsfailure @ 0x180007774 size=0xd1 =====
void __cdecl __noreturn _report_gsfailure(uintptr_t StackCookie)
{
  DWORD64 retaddr; // [rsp+38h] [rbp+0h]
  uintptr_t v2; // [rsp+40h] [rbp+8h] BYREF

  v2 = StackCookie;
  if ( IsProcessorFeaturePresent(0x17u) )
    __fastfail(2u);
  capture_previous_context(&ContextRecord);
  ContextRecord.Rip = retaddr;
  ContextRecord.Rsp = (DWORD64)&v2;
  qword_18002A2D0 = retaddr;
  ContextRecord.Rcx = v2;
  dword_18002A2C0 = -1073740791;
  dword_18002A2C4 = 1;
  dword_18002A2D8 = 1;
  unk_18002A2E0 = 2;
  _raise_securityfailure((struct _EXCEPTION_POINTERS *)&ExceptionInfo);
}


// ===== __report_rangecheckfailure @ 0x180007848 size=0xe =====
void __noreturn _report_rangecheckfailure()
{
  _report_securityfailure(8);
}


// ===== __report_securityfailure @ 0x18000785c size=0x9b =====
void __fastcall __noreturn _report_securityfailure(unsigned int a1)
{
  DWORD64 retaddr; // [rsp+28h] [rbp+0h]
  unsigned int v2; // [rsp+30h] [rbp+8h] BYREF

  v2 = a1;
  if ( IsProcessorFeaturePresent(0x17u) )
    __fastfail(v2);
  capture_current_context(&ContextRecord);
  ContextRecord.Rip = retaddr;
  ContextRecord.Rsp = (DWORD64)&v2;
  qword_18002A2D0 = retaddr;
  dword_18002A2C0 = -1073740791;
  dword_18002A2C4 = 1;
  dword_18002A2D8 = 1;
  unk_18002A2E0 = v2;
  _raise_securityfailure((struct _EXCEPTION_POINTERS *)&ExceptionInfo);
}


// ===== capture_current_context @ 0x1800078f8 size=0x6d =====
struct _IMAGE_RUNTIME_FUNCTION_ENTRY *__fastcall capture_current_context(PCONTEXT ContextRecord)
{
  ULONG64 Rip; // rdi
  struct _IMAGE_RUNTIME_FUNCTION_ENTRY *result; // rax
  unsigned __int64 ImageBase; // [rsp+50h] [rbp+8h] BYREF
  unsigned __int64 EstablisherFrame; // [rsp+58h] [rbp+10h] BYREF
  PVOID HandlerData; // [rsp+60h] [rbp+18h] BYREF

  RtlCaptureContext(ContextRecord);
  Rip = ContextRecord->Rip;
  result = RtlLookupFunctionEntry(Rip, &ImageBase, nullptr);
  if ( result != nullptr )
    return (struct _IMAGE_RUNTIME_FUNCTION_ENTRY *)RtlVirtualUnwind(
                                                     0,
                                                     ImageBase,
                                                     Rip,
                                                     result,
                                                     ContextRecord,
                                                     &HandlerData,
                                                     &EstablisherFrame,
                                                     nullptr);
  return result;
}


// ===== capture_previous_context @ 0x180007968 size=0x71 =====
struct _IMAGE_RUNTIME_FUNCTION_ENTRY *__fastcall capture_previous_context(PCONTEXT ContextRecord)
{
  ULONG64 Rip; // rsi
  int i; // edi
  struct _IMAGE_RUNTIME_FUNCTION_ENTRY *result; // rax
  unsigned __int64 ImageBase; // [rsp+60h] [rbp+8h] BYREF
  unsigned __int64 EstablisherFrame; // [rsp+68h] [rbp+10h] BYREF
  PVOID HandlerData; // [rsp+70h] [rbp+18h] BYREF

  RtlCaptureContext(ContextRecord);
  Rip = ContextRecord->Rip;
  for ( i = 0; i < 2; ++i )
  {
    result = RtlLookupFunctionEntry(Rip, &ImageBase, nullptr);
    if ( result == nullptr )
      break;
    result = (struct _IMAGE_RUNTIME_FUNCTION_ENTRY *)RtlVirtualUnwind(
                                                       0,
                                                       ImageBase,
                                                       Rip,
                                                       result,
                                                       ContextRecord,
                                                       &HandlerData,
                                                       &EstablisherFrame,
                                                       nullptr);
  }
  return result;
}


// ===== ??2@YAPEAX_KAEBUnothrow_t@std@@@Z @ 0x1800079dc size=0x1d =====
void *__fastcall operator new(size_t a1, const struct std::nothrow_t *a2)
{
  void *result; // rax

  try
  {
    result = operator new(a1);
  }
  catch ( ... )
  {
    return nullptr;
  }
  return result;
}


// ===== j_??2@YAPEAX_KAEBUnothrow_t@std@@@Z @ 0x1800079fc size=0x5 =====
// attributes: thunk
void *__fastcall operator new(size_t a1, const struct std::nothrow_t *a2)
{
  return ??2@YAPEAX_KAEBUnothrow_t@std@@@Z(a1, a2);
}


// ===== __GSHandlerCheck @ 0x180007a04 size=0x1d =====
__int64 __fastcall _GSHandlerCheck(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _GSHandlerCheckCommon(a2, a4, *(_QWORD *)(a4 + 56));
  return 1;
}


// ===== __GSHandlerCheckCommon @ 0x180007a24 size=0x5b =====
__int64 __fastcall _GSHandlerCheckCommon(__int64 a1, __int64 a2)
{
  __int64 v2; // rcx
  __int64 result; // rax

  v2 = *(unsigned int *)(*(_QWORD *)(a2 + 16) + 8LL);
  result = *(_QWORD *)(a2 + 8);
  if ( (*(_BYTE *)(v2 + result + 3) & 0xF) != 0 )
    return *(_BYTE *)(v2 + result + 3) & 0xF0;
  return result;
}


// ===== __GSHandlerCheck_EH @ 0x180007a80 size=0x7f =====
__int64 __fastcall _GSHandlerCheck_EH(struct EHExceptionRecord *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rbx
  __int64 result; // rax

  v4 = *(_QWORD *)(a4 + 56);
  _GSHandlerCheckCommon(a2, a4);
  result = 1;
  if ( ((((a1->ExceptionFlags & 0x66) != 0) + 1) & *(_DWORD *)(v4 + 4)) != 0 )
    return _CxxFrameHandler3(a1);
  return result;
}


// ===== _alloca_probe @ 0x180007b10 size=0x51 =====
unsigned __int64 __fastcall alloca_probe()
{
  unsigned __int64 result; // rax
  char *v1; // r10
  char *StackLimit; // r11
  char v3; // [rsp+18h] [rbp+8h] BYREF

  v1 = &v3 - result;
  if ( (unsigned __int64)&v3 < result )
    v1 = nullptr;
  StackLimit = (char *)NtCurrentTeb()->NtTib.StackLimit;
  if ( v1 < StackLimit )
  {
    LOWORD(v1) = (unsigned __int16)v1 & 0xF000;
    do
    {
      StackLimit -= 4096;
      *StackLimit = 0;
    }
    while ( v1 != StackLimit );
  }
  return result;
}


// ===== __security_check_cookie @ 0x180007b80 size=0x21 =====
void __cdecl _security_check_cookie(uintptr_t StackCookie)
{
  __int64 v1; // rcx

  if ( StackCookie != _security_cookie )
ReportFailure:
    _report_gsfailure(StackCookie);
  v1 = __ROL8__(StackCookie, 16);
  if ( (_WORD)v1 != 0 )
  {
    StackCookie = __ROR8__(v1, 16);
    goto ReportFailure;
  }
}


// ===== j_j__free_base @ 0x180007ba4 size=0x5 =====
// attributes: thunk
void __cdecl j_j__free_base(void *Block)
{
  j__free_base(Block);
}


// ===== __scrt_acquire_startup_lock @ 0x180007bac size=0x39 =====
char _scrt_acquire_startup_lock()
{
  int v0; // eax
  PVOID StackBase; // rcx
  signed __int64 v2; // rax

  LOBYTE(v0) = __uncaught_exception();
  if ( v0 != 0 )
  {
    StackBase = NtCurrentTeb()->NtTib.StackBase;
    while ( 1 )
    {
      v2 = _InterlockedCompareExchange64(&qword_18002A838, (signed __int64)StackBase, 0);
      if ( v2 == 0 )
        break;
      if ( StackBase == (PVOID)v2 )
        return 1;
    }
  }
  return 0;
}


// ===== __scrt_dllmain_after_initialize_c @ 0x180007be8 size=0x34 =====
char _scrt_dllmain_after_initialize_c()
{
  int v0; // eax
  charNode *v1; // rcx
  _crt_argv_mode v2; // eax

  LOBYTE(v0) = __uncaught_exception();
  if ( v0 != 0 )
  {
    _isa_available_init();
  }
  else
  {
    v2 = (unsigned int)charNode::raw_length(v1);
    if ( configure_narrow_argv(v2) != 0 )
      return 0;
    common_initialize_environment_nolock<char>();
  }
  return 1;
}


// ===== __scrt_dllmain_before_initialize_c @ 0x180007c1c size=0x15 =====
bool _scrt_dllmain_before_initialize_c()
{
  return (unsigned __int8)_scrt_initialize_onexit_tables(0) != 0;
}


// ===== sub_180007C34 @ 0x180007c34 size=0x28 =====
char __fastcall sub_180007C34(Concurrency::details::ScheduleGroupSegmentBase *a1)
{
  Concurrency::details::ScheduleGroupSegmentBase *v1; // rcx

  if ( !Concurrency::details::ScheduleGroupSegmentBase::HasUnrealizedChores(a1) )
    return 0;
  if ( !Concurrency::details::ScheduleGroupSegmentBase::HasUnrealizedChores(v1) )
  {
    _vcrt_thread_detach();
    return 0;
  }
  return 1;
}


// ===== __scrt_dllmain_crt_thread_detach @ 0x180007c5c size=0x15 =====
char _scrt_dllmain_crt_thread_detach()
{
  _acrt_thread_detach();
  _vcrt_thread_detach();
  return 1;
}


// ===== __scrt_dllmain_exception_filter @ 0x180007c74 size=0x60 =====
int __fastcall _scrt_dllmain_exception_filter(
        __int64 a1,
        int a2,
        __int64 a3,
        void (__fastcall *a4)(__int64, _QWORD, __int64),
        unsigned int ExceptionNum,
        struct _EXCEPTION_POINTERS *ExceptionPtr)
{
  int v10; // eax

  LOBYTE(v10) = __uncaught_exception();
  if ( v10 == 0 && a2 == 1 )
    a4(a1, 0, a3);
  return seh_filter_dll(ExceptionNum, ExceptionPtr);
}


// ===== __scrt_dllmain_uninitialize_c @ 0x180007cd4 size=0x30 =====
void _scrt_dllmain_uninitialize_c()
{
  int v0; // eax

  LOBYTE(v0) = __uncaught_exception();
  if ( v0 != 0 )
  {
    execute_onexit_table(&Table);
  }
  else if ( (unsigned int)sub_18000E0C8() == 0 )
  {
    cexit();
  }
}


// ===== __scrt_dllmain_uninitialize_critical @ 0x180007d04 size=0x14 =====
__vcrt_bool _scrt_dllmain_uninitialize_critical()
{
  sub_18000EC9C(0);
  return _vcrt_uninitialize_critical();
}


// ===== __scrt_initialize_crt @ 0x180007d18 size=0x49 =====
char __fastcall _scrt_initialize_crt(int a1)
{
  char v1; // al

  v1 = byte_18002A840;
  if ( a1 == 0 )
    v1 = 1;
  byte_18002A840 = v1;
  _isa_available_init();
  if ( !_vcrt_initialize() )
    return 0;
  if ( !_acrt_initialize() )
  {
    _vcrt_uninitialize(false);
    return 0;
  }
  return 1;
}


// ===== __scrt_initialize_onexit_tables @ 0x180007d64 size=0xd8 =====
char __fastcall _scrt_initialize_onexit_tables(unsigned int a1)
{
  int v2; // eax
  _PVFV *v4; // rax
  __int128 v5; // [rsp+20h] [rbp-28h]

  if ( byte_18002A841 == 0 )
  {
    if ( a1 > 1 )
    {
      _scrt_fastfail(5);
      __debugbreak();
    }
    LOBYTE(v2) = __uncaught_exception();
    if ( v2 == 0 || a1 != 0 )
    {
      v4 = (_PVFV *)(_security_cookie ^ __ROR8__(-1, 64 - ((unsigned __int8)_security_cookie & 0x3Fu)));
      *(_QWORD *)&v5 = v4;
      *((_QWORD *)&v5 + 1) = v4;
      *(_OWORD *)&Table._first = v5;
      *(_QWORD *)&v5 = v4;
      *((_QWORD *)&v5 + 1) = v4;
      Table._end = v4;
      *(_OWORD *)&stru_18002A860._first = v5;
      stru_18002A860._end = v4;
    }
    else if ( initialize_onexit_table(&Table) != 0 || initialize_onexit_table(&stru_18002A860) != 0 )
    {
      return 0;
    }
    byte_18002A841 = 1;
  }
  return 1;
}


// ===== __scrt_is_nonwritable_in_current_image @ 0x180007e3c size=0x99 =====
bool __fastcall _scrt_is_nonwritable_in_current_image(__int64 a1)
{
  unsigned __int64 v1; // r8
  _DWORD *v2; // rdx
  _DWORD *v3; // r9
  unsigned __int64 v4; // rcx

  if ( _ImageBase != 23117
    || *(_DWORD *)((char *)&_ImageBase + (int)off_18000003C) != 17744
    || *(__int16 *)((char *)&word_180000018 + (int)off_18000003C) != 523 )
  {
    return false;
  }
  v1 = a1 - (_QWORD)&_ImageBase;
  v2 = (_DWORD *)((char *)&word_180000018
                + (int)off_18000003C
                + *(unsigned __int16 *)((char *)&word_180000014 + (int)off_18000003C));
  v3 = &v2[10 * *(unsigned __int16 *)((char *)&word_180000006 + (int)off_18000003C)];
  while ( v2 != v3 )
  {
    v4 = (unsigned int)v2[3];
    if ( v1 >= v4 && v1 < (unsigned int)(v4 + v2[2]) )
      return v2 != nullptr && v2[9] >= 0;
    v2 += 10;
  }
  v2 = nullptr;
  return v2 != nullptr && v2[9] >= 0;
}


// ===== __scrt_release_startup_lock @ 0x180007ed8 size=0x24 =====
char __fastcall _scrt_release_startup_lock(char a1)
{
  int v2; // eax

  LOBYTE(v2) = __uncaught_exception();
  if ( v2 != 0 && a1 == 0 )
    _InterlockedExchange64(&qword_18002A838, 0);
  return v2;
}


// ===== __scrt_uninitialize_crt @ 0x180007efc size=0x2b =====
char __fastcall _scrt_uninitialize_crt(__crt_bool a1, char a2)
{
  if ( byte_18002A840 == 0 || a2 == 0 )
  {
    _acrt_uninitialize(a1);
    _vcrt_uninitialize(a1);
  }
  return 1;
}


// ===== _onexit @ 0x180007f28 size=0x4f =====
_onexit_t __cdecl onexit(_onexit_t Func)
{
  int v2; // eax
  int (__cdecl *v3)(); // rcx

  if ( __ROR8__((uintptr_t)Table._first ^ _security_cookie, _security_cookie & 0x3F) == -1 )
    v2 = sub_18000EA44(Func);
  else
    v2 = register_onexit_function(&Table, Func);
  v3 = nullptr;
  if ( v2 == 0 )
    return Func;
  return v3;
}


// ===== atexit @ 0x180007f78 size=0x17 =====
int __cdecl atexit(void (__cdecl *a1)())
{
  return (onexit((_onexit_t)a1) != nullptr) - 1;
}


// ===== ?dllmain_crt_dispatch@@YAHQEAUHINSTANCE__@@KQEAX@Z @ 0x180007f90 size=0x50 =====
__int64 __fastcall dllmain_crt_dispatch(Concurrency::details::ScheduleGroupSegmentBase *a1, int a2, void *const a3)
{
  int v3; // edx
  int v4; // edx
  __int64 result; // rax

  if ( a2 == 0 )
    return dllmain_crt_process_detach(a3 != nullptr);
  v3 = a2 - 1;
  if ( v3 == 0 )
    return dllmain_crt_process_attach((HINSTANCE)a1, a3);
  v4 = v3 - 1;
  if ( v4 != 0 )
  {
    if ( v4 != 1 )
      return 1;
    LOBYTE(result) = _scrt_dllmain_crt_thread_detach();
  }
  else
  {
    LOBYTE(result) = sub_180007C34(a1);
  }
  return (unsigned __int8)result;
}


// ===== ?dllmain_crt_process_attach@@YAHQEAUHINSTANCE__@@QEAX@Z @ 0x180007fe0 size=0x119 =====
__int64 __fastcall dllmain_crt_process_attach(HINSTANCE a1, void *const a2)
{
  char v5; // bl
  char v6; // di
  _QWORD *v7; // rax

  if ( _scrt_initialize_crt(0) == 0 )
    return 0;
  v5 = _scrt_acquire_startup_lock();
  v6 = 1;
  if ( dword_18002A830 != 0 )
  {
    _scrt_fastfail(7);
    __debugbreak();
  }
  dword_18002A830 = 1;
  if ( _scrt_dllmain_before_initialize_c() )
  {
    sub_180008770();
    sub_180008728();
    _scrt_initialize_default_local_stdio_options();
    if ( initterm_e((_PIFV *)&qword_18001A4B0, (_PIFV *)&qword_18001A4D0) == 0
      && _scrt_dllmain_after_initialize_c() != 0 )
    {
      initterm((_PVFV *)&First, (_PVFV *)&Last);
      dword_18002A830 = 2;
      v6 = 0;
    }
  }
  _scrt_release_startup_lock(v5);
  if ( v6 != 0 )
    return 0;
  v7 = (_QWORD *)sub_180008768();
  if ( *v7 != 0 && _scrt_is_nonwritable_in_current_image((__int64)v7) )
    guard_dispatch_icall_nop(a1, 2, a2);
  ++dword_18002A878;
  return 1;
}


// ===== ?dllmain_crt_process_detach@@YAH_N@Z @ 0x1800080fc size=0x8e =====
__int64 __fastcall dllmain_crt_process_detach(__crt_bool a1)
{
  unsigned int v2; // ebx
  char v4; // di

  v2 = 0;
  if ( dword_18002A878 <= 0 )
    return 0;
  --dword_18002A878;
  v4 = _scrt_acquire_startup_lock();
  if ( dword_18002A830 != 2 )
  {
    _scrt_fastfail(7);
    __debugbreak();
  }
  _scrt_dllmain_uninitialize_c();
  sub_180008738();
  sub_1800087AC();
  dword_18002A830 = 0;
  _scrt_dllmain_uninitialize_critical();
  _scrt_release_startup_lock(v4);
  LOBYTE(v2) = _scrt_uninitialize_crt(a1, 0) != 0;
  return v2;
}


// ===== ?dllmain_dispatch@@YAHQEAUHINSTANCE__@@KQEAX@Z @ 0x18000818c size=0x133 =====
__int64 __fastcall dllmain_dispatch(Concurrency::details::ScheduleGroupSegmentBase *a1, DWORD a2, void *const a3)
{
  unsigned int v7; // ebx
  BOOL v8; // eax

  if ( a2 == 0 && dword_18002A878 <= 0 )
    return 0;
  if ( a2 - 1 > 1 || (v7 = dllmain_crt_dispatch(a1, a2, a3)) != 0 )
  {
    v8 = DllMain((HINSTANCE)a1, a2, a3);
    v7 = v8;
    if ( a2 == 1 && !v8 )
    {
      DllMain((HINSTANCE)a1, 0, a3);
      dllmain_crt_dispatch(a1, 0, a3);
    }
    if ( a2 == 0 || a2 == 3 )
      return (unsigned int)dllmain_crt_dispatch(a1, a2, a3) != 0;
  }
  return v7;
}


// ===== DllEntryPoint @ 0x1800082c0 size=0x3d =====
BOOL __stdcall DllEntryPoint(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    _security_init_cookie();
  return dllmain_dispatch((Concurrency::details::ScheduleGroupSegmentBase *)hinstDLL, fdwReason, lpReserved);
}


// ===== sub_180008300 @ 0x180008300 size=0x3f =====
_QWORD *__fastcall sub_180008300(_QWORD *a1, __int64 a2)
{
  *a1 = &std::exception::`vftable';
  a1[1] = 0;
  a1[2] = 0;
  _std_exception_copy(a2 + 8);
  *a1 = &std::bad_array_new_length::`vftable';
  return a1;
}


// ===== sub_180008340 @ 0x180008340 size=0x1e =====
_QWORD *__fastcall sub_180008340(_QWORD *a1)
{
  a1[2] = 0;
  a1[1] = "bad array new length";
  *a1 = &std::bad_array_new_length::`vftable';
  return a1;
}


// ===== ?cancel_current_task@Concurrency@@YAXXZ @ 0x180008360 size=0x20 =====
void __fastcall __noreturn Concurrency::cancel_current_task()
{
  _QWORD pExceptionObject[5]; // [rsp+20h] [rbp-28h] BYREF

  sub_180007514(pExceptionObject);
  throw (std::bad_alloc *)pExceptionObject;
}


// ===== ?cancel_current_task@Concurrency@@YAXXZ_0 @ 0x180008380 size=0x20 =====
void __fastcall __noreturn Concurrency::cancel_current_task()
{
  _QWORD pExceptionObject[5]; // [rsp+20h] [rbp-28h] BYREF

  sub_180008340(pExceptionObject);
  throw (std::bad_array_new_length *)pExceptionObject;
}


// ===== __isa_available_init @ 0x1800083a0 size=0x17b =====
int __cdecl _isa_available_init()
{
  char v5; // di
  int v6; // r10d
  int v7; // esi
  int v9; // r9d
  int v14; // r11d
  int v15; // eax
  unsigned __int64 v16; // rax
  __int64 v17; // rcx
  int v18; // r8d
  int v23; // eax

  _RAX = 0;
  dword_18002901C = 2;
  dword_180029018 = 1;
  __asm { cpuid }
  v5 = 0;
  v6 = _RDX;
  v7 = _RAX;
  _RAX = 1;
  v9 = _RCX ^ 0x6C65746E | _RBX ^ 0x756E6547;
  __asm { cpuid }
  v14 = _RCX;
  if ( (v6 ^ 0x49656E69 | v9) == 0
    && ((qword_180029020 = -1, (v15 = _RAX & 0xFFF3FF0) == 67264)
     || v15 == 132704
     || v15 == 132720
     || (unsigned int)(v16 = (unsigned int)(v15 - 198224)) <= 0x20 && (v17 = 0x100010001LL, _bittest64(&v17, v16))) )
  {
    v18 = dword_18002A87C | 1;
    dword_18002A87C |= 1u;
  }
  else
  {
    v18 = dword_18002A87C;
  }
  _RAX = 7;
  if ( v7 >= 7 )
  {
    __asm { cpuid }
    v5 = _RBX;
    if ( (_RBX & 0x200) != 0 )
      dword_18002A87C = v18 | 2;
  }
  if ( (v14 & 0x100000) != 0 )
  {
    dword_180029018 = 2;
    dword_18002901C = 6;
    if ( (v14 & 0x8000000) != 0 && (v14 & 0x10000000) != 0 )
    {
      __asm { xgetbv }
      if ( (_RAX & 6) == 6 )
      {
        v23 = dword_18002901C | 8;
        dword_180029018 = 3;
        dword_18002901C |= 8u;
        if ( (v5 & 0x20) != 0 )
        {
          dword_180029018 = 5;
          dword_18002901C = v23 | 0x20;
        }
      }
    }
  }
  return 0;
}


// ===== ?__uncaught_exception@@YA_NXZ @ 0x18000851c size=0xc =====
_BOOL8 __fastcall __uncaught_exception()
{
  return dword_18002B488 != 0;
}


// ===== sub_180008528 @ 0x180008528 size=0x8 =====
void sub_180008528()
{
  dword_18002A880 = 0;
}


// ===== __scrt_fastfail @ 0x180008530 size=0x14a =====
void __fastcall _scrt_fastfail(unsigned int a1)
{
  ULONG64 Rip; // rbx
  struct _IMAGE_RUNTIME_FUNCTION_ENTRY *v3; // rax
  bool v4; // bl
  struct _EXCEPTION_POINTERS ExceptionInfo; // [rsp+40h] [rbp-C0h] BYREF
  _DWORD v6[4]; // [rsp+50h] [rbp-B0h] BYREF
  DWORD64 v7; // [rsp+60h] [rbp-A0h]
  struct _CONTEXT ContextRecord; // [rsp+F0h] [rbp-10h] BYREF
  DWORD64 retaddr; // [rsp+5C8h] [rbp+4C8h]
  __int64 v10; // [rsp+5D0h] [rbp+4D0h] BYREF
  unsigned __int64 ImageBase; // [rsp+5D8h] [rbp+4D8h] BYREF
  unsigned __int64 EstablisherFrame; // [rsp+5E0h] [rbp+4E0h] BYREF
  PVOID HandlerData; // [rsp+5E8h] [rbp+4E8h] BYREF

  if ( IsProcessorFeaturePresent(0x17u) )
    __fastfail(a1);
  sub_180008528();
  sub_180009D50(&ContextRecord, 0, 1232);
  RtlCaptureContext(&ContextRecord);
  Rip = ContextRecord.Rip;
  v3 = RtlLookupFunctionEntry(ContextRecord.Rip, &ImageBase, nullptr);
  if ( v3 != nullptr )
    RtlVirtualUnwind(0, ImageBase, Rip, v3, &ContextRecord, &HandlerData, &EstablisherFrame, nullptr);
  ContextRecord.Rip = retaddr;
  ContextRecord.Rsp = (DWORD64)&v10;
  sub_180009D50(v6, 0, 152);
  v7 = retaddr;
  v6[0] = 1073741845;
  v6[1] = 1;
  ExceptionInfo.ExceptionRecord = (PEXCEPTION_RECORD)v6;
  v4 = IsDebuggerPresent();
  ExceptionInfo.ContextRecord = &ContextRecord;
  SetUnhandledExceptionFilter(nullptr);
  if ( UnhandledExceptionFilter(&ExceptionInfo) == 0 && !v4 )
    sub_180008528();
}


// ===== __security_init_cookie @ 0x18000867c size=0xac =====
void __cdecl _security_init_cookie()
{
  uintptr_t v0; // rax
  struct _FILETIME v1; // [rsp+30h] [rbp+10h] BYREF
  struct _FILETIME SystemTimeAsFileTime; // [rsp+38h] [rbp+18h] BYREF
  LARGE_INTEGER PerformanceCount; // [rsp+40h] [rbp+20h] BYREF

  v0 = _security_cookie;
  if ( _security_cookie == 0x2B992DDFA232LL )
  {
    SystemTimeAsFileTime = 0;
    GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
    v1 = SystemTimeAsFileTime;
    v1 = (struct _FILETIME)(GetCurrentThreadId() ^ *(unsigned __int64 *)&v1);
    v1 = (struct _FILETIME)(GetCurrentProcessId() ^ *(unsigned __int64 *)&v1);
    QueryPerformanceCounter(&PerformanceCount);
    v0 = ((unsigned __int64)&v1
        ^ *(_QWORD *)&v1
        ^ PerformanceCount.QuadPart
        ^ ((unsigned __int64)PerformanceCount.LowPart << 32))
       & 0xFFFFFFFFFFFFLL;
    if ( v0 == 0x2B992DDFA232LL )
      v0 = 0x2B992DDFA233LL;
    _security_cookie = v0;
  }
  qword_180029000 = ~v0;
}


// ===== sub_180008728 @ 0x180008728 size=0xe =====
void sub_180008728()
{
  InitializeSListHead(&stru_18002A890);
}


// ===== sub_180008738 @ 0x180008738 size=0xc =====
__int64 sub_180008738()
{
  return _std_type_info_destroy_list(&stru_18002A890);
}


// ===== sub_180008744 @ 0x180008744 size=0x8 =====
void *sub_180008744()
{
  return &unk_18002A8A0;
}


// ===== __scrt_initialize_default_local_stdio_options @ 0x18000874c size=0x1b =====
_QWORD *_scrt_initialize_default_local_stdio_options()
{
  _QWORD *v0; // rax
  _QWORD *result; // rax

  v0 = sub_1800059F0();
  *v0 |= 4uLL;
  result = sub_180008744();
  *result |= 2uLL;
  return result;
}


// ===== sub_180008768 @ 0x180008768 size=0x8 =====
void *sub_180008768()
{
  return &unk_18002B480;
}


// ===== sub_180008770 @ 0x180008770 size=0x3c =====
void sub_180008770()
{
  void (**i)(void); // rbx

  for ( i = qword_180024CA0; i < qword_180024CA0; ++i )
  {
    if ( *i != nullptr )
      (*i)();
  }
}


// ===== sub_1800087AC @ 0x1800087ac size=0x3c =====
void sub_1800087AC()
{
  void (**i)(void); // rbx

  for ( i = qword_180024CB0; i < qword_180024CB0; ++i )
  {
    if ( *i != nullptr )
      (*i)();
  }
}


// ===== sub_1800087F0 @ 0x1800087f0 size=0xc =====
__int64 sub_1800087F0()
{
  return sub_1800087FC();
}


// ===== sub_1800087FC @ 0x1800087fc size=0x79 =====
__int64 __fastcall sub_1800087FC(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rax
  __int64 (__fastcall *v5)(__int64, __int64, __int64, __int64); // rax

  v5 = (__int64 (__fastcall *)(__int64, __int64, __int64, __int64))sub_180018CE4(&UxTheme_dll_import_table, v4);
  return v5(a1, a2, a3, a4);
}


// ===== sub_180008875 @ 0x180008875 size=0xc =====
__int64 __fastcall sub_180008875(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return sub_1800087FC(a1, a2, a3, a4);
}


// ===== sub_180008881 @ 0x180008881 size=0xc =====
__int64 __fastcall sub_180008881(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return sub_1800087FC(a1, a2, a3, a4);
}


// ===== sub_180008890 @ 0x180008890 size=0x110 =====
__int64 sub_180008890()
{
  if ( CreateFileW(L"\\\\.\\DpControl", 0x80u, 3u, nullptr, 3u, 0x80u, nullptr) == (HANDLE)-1LL )
    return 0;
  else
    return sub_180062591();
}


// ===== sub_1800089A0 @ 0x1800089a0 size=0x110 =====
__int64 sub_1800089A0()
{
  if ( CreateFileW(L"\\\\.\\DpControl", 0x80u, 3u, nullptr, 3u, 0x80u, nullptr) == (HANDLE)-1LL )
    return 0;
  else
    return sub_180062591();
}


// ===== sub_180008AB0 @ 0x180008ab0 size=0x102 =====
__int64 sub_180008AB0()
{
  LSTATUS dwErrCode; // [rsp+34h] [rbp-314h]
  DWORD pcbData; // [rsp+38h] [rbp-310h] BYREF
  DWORD pdwType; // [rsp+3Ch] [rbp-30Ch] BYREF
  _BYTE pvData[512]; // [rsp+40h] [rbp-308h] BYREF
  WCHAR pszSubKey[132]; // [rsp+240h] [rbp-108h] BYREF

  memset(pvData, 0, sizeof(pvData));
  if ( (unsigned int)sub_180008BC0(pvData) != 0 )
    return sub_180062591();
  pcbData = 512;
  swprintf(pszSubKey, 0x80u, L"SYSTEM\\CurrentControlSet\\Services\\%s", L"diskpt");
  dwErrCode = SHGetValueW(HKEY_LOCAL_MACHINE, pszSubKey, L"GUID", &pdwType, pvData, &pcbData);
  if ( dwErrCode == 0 )
    return sub_180062591();
  SetLastError(dwErrCode);
  return 0;
}


// ===== sub_180008BC0 @ 0x180008bc0 size=0x13b =====
__int64 sub_180008BC0()
{
  _BYTE v1[136]; // [rsp+60h] [rbp-A8h] BYREF

  if ( CreateFileW(L"\\\\.\\DpControl", 0x80u, 3u, nullptr, 3u, 0x80u, nullptr) == (HANDLE)-1LL )
    return 0;
  memset(v1, 0, sizeof(v1));
  return sub_180062591();
}


// ===== sub_180008D00 @ 0x180008d00 size=0x52 =====
__int64 __fastcall sub_180008D00(__int16 a1, __int64 a2)
{
  _WORD v3[20]; // [rsp+20h] [rbp-28h] BYREF

  qmemcpy(v3, L"\\\\.\\ :", 0xEu);
  v3[4] = a1;
  return sub_180008D60(v3, a2);
}


// ===== sub_180008D60 @ 0x180008d60 size=0x1a3 =====
__int64 __fastcall sub_180008D60(const WCHAR *a1)
{
  if ( CreateFileW(a1, 0x80u, 3u, nullptr, 3u, 0x80u, nullptr) == (HANDLE)-1LL )
    return 0;
  else
    return sub_180062591();
}


// ===== sub_180008F03 @ 0x180008f03 size=0x6 =====
// attributes: thunk
__int64 sub_180008F03()
{
  return ((__int64 (*)(void))(&byte_18001A418 + 2))();
}


// ===== sub_180008F09 @ 0x180008f09 size=0x6 =====
// attributes: thunk
__int64 sub_180008F09()
{
  return ((__int64 (*)(void))(&byte_18001A418 + 1))();
}


// ===== _purecall @ 0x180008f10 size=0x2e =====
void __noreturn purecall()
{
  void (*v0)(void); // rax

  v0 = (void (*)(void))__ROR8__(qword_18002A8B8 ^ _security_cookie, _security_cookie & 0x3F);
  if ( v0 != nullptr )
    v0();
  abort();
}


// ===== wcsrchr @ 0x180008f40 size=0xb4 =====
wchar_t *__cdecl wcsrchr(const wchar_t *Str, wchar_t Ch)
{
  wchar_t *v4; // rcx
  const wchar_t *v5; // rdx
  __int16 v6; // ax
  wchar_t *result; // rax
  wchar_t *v8; // rdx
  __m128i v9; // xmm1
  __m128i v10; // xmm0
  int v11; // ecx
  __m128i v12; // xmm1
  __m128i v13; // xmm0
  unsigned __int8 v14; // zf
  int v15; // ecx

  v4 = nullptr;
  if ( dword_180029018 >= 2 )
  {
    v8 = nullptr;
    while ( (((_BYTE)Str + 1) & 0xE) != 0 )
    {
      result = (wchar_t *)Str;
      if ( *Str != Ch )
        result = v8;
      v8 = result;
      if ( *Str == 0 )
        return result;
      ++Str;
    }
    if ( Ch != 0 )
    {
      v12 = _mm_cvtsi32_si128(Ch);
      while ( 1 )
      {
        v13 = _mm_loadu_si128((const __m128i *)Str);
        v15 = _mm_cmpistri(v12, v13, 65);
        v14 = _mm_cmpistrz(v12, v13, 65);
        if ( _mm_cmpistrc(v12, v13, 65) )
          v8 = (wchar_t *)&Str[v15];
        if ( v14 )
          break;
        Str += 8;
      }
      return v8;
    }
    else
    {
      v9 = _mm_cvtsi32_si128(0xFFFF0001);
      while ( 1 )
      {
        v10 = _mm_loadu_si128((const __m128i *)Str);
        v11 = _mm_cmpistri(v9, v10, 21);
        if ( _mm_cmpistrz(v9, v10, 21) )
          break;
        Str += 8;
      }
      return (wchar_t *)&Str[v11];
    }
  }
  else
  {
    v5 = Str;
    do
      v6 = *Str++;
    while ( v6 != 0 );
    do
      --Str;
    while ( Str != v5 && *Str != Ch );
    if ( *Str == Ch )
      return (wchar_t *)Str;
    return v4;
  }
}


// ===== wcsstr @ 0x180008ff4 size=0x21c =====
wchar_t *__cdecl wcsstr(const wchar_t *Str, const wchar_t *SubStr)
{
  wchar_t v2; // di
  const __m128i *v4; // r8
  __m128i v6; // xmm3
  __m128i v7; // xmm1
  unsigned int v8; // eax
  unsigned int v9; // ecx
  const __m128i *v10; // rdx
  const __m128i *i; // r9
  __m128i v12; // xmm1
  unsigned int v13; // eax
  unsigned __int64 v14; // rcx
  __m128i inserted; // xmm0
  const wchar_t *v16; // rcx
  wchar_t v17; // dx
  __int64 j; // r9
  wchar_t v19; // si
  const wchar_t *v20; // rax
  __m128i v21; // xmm1
  unsigned __int8 v22; // cf
  const __m128i *v23; // rdx
  const __m128i *k; // r9
  __m128i v25; // xmm1
  __m128i v26; // xmm2
  unsigned __int8 v27; // sf

  v2 = *SubStr;
  v4 = (const __m128i *)Str;
  if ( *SubStr == 0 )
    return (wchar_t *)Str;
  if ( dword_180029018 < 2 )
  {
    v6 = _mm_shuffle_epi32(_mm_shufflelo_epi16(_mm_cvtsi32_si128(v2), 0), 0);
    while ( 1 )
    {
      if ( ((unsigned __int16)v4 & 0xFFFu) > 0xFF0uLL )
        goto LABEL_9;
      v7 = _mm_loadu_si128(v4);
      v8 = _mm_movemask_epi8(_mm_or_si128(_mm_cmpeq_epi16(v7, (__m128i)0LL), _mm_cmpeq_epi16(v7, v6)));
      if ( v8 != 0 )
      {
        _BitScanForward(&v9, v8);
        v4 = (const __m128i *)((char *)v4 + 2 * ((unsigned __int64)v9 >> 1));
LABEL_9:
        if ( v4->m128i_i16[0] == 0 )
          return nullptr;
        if ( v2 == v4->m128i_i16[0] )
        {
          v10 = v4;
          for ( i = (const __m128i *)SubStr; ; i = (const __m128i *)((char *)i + 2) )
          {
            while ( 2 )
            {
              if ( ((unsigned __int16)i & 0xFFFu) <= 0xFF0uLL && ((unsigned __int16)v10 & 0xFFFu) <= 0xFF0uLL )
              {
                v12 = _mm_loadu_si128(i);
                v13 = _mm_movemask_epi8(
                        _mm_or_si128(
                          _mm_cmpeq_epi16(_mm_cmpeq_epi16(_mm_loadu_si128(v10), v12), (__m128i)0LL),
                          _mm_cmpeq_epi16(v12, (__m128i)0LL)));
                if ( v13 == 0 )
                {
                  ++v10;
                  ++i;
                  continue;
                }
                _BitScanForward(&v13, v13);
                v14 = 2 * ((unsigned __int64)v13 >> 1);
                v10 = (const __m128i *)((char *)v10 + v14);
                i = (const __m128i *)((char *)i + v14);
              }
              break;
            }
            if ( i->m128i_i16[0] == 0 )
              return (wchar_t *)v4;
            if ( v10->m128i_i16[0] != i->m128i_i16[0] )
              break;
            v10 = (const __m128i *)((char *)v10 + 2);
          }
        }
        v4 = (const __m128i *)((char *)v4 + 2);
      }
      else
      {
        ++v4;
      }
    }
  }
  if ( ((unsigned __int16)SubStr & 0xFFFu) > 0xFF0uLL )
  {
    inserted = 0;
    v16 = SubStr;
    v17 = *SubStr;
    for ( j = 8; j != 0; --j )
    {
      v19 = v17;
      inserted = _mm_insert_epi16(_mm_srli_si128(inserted, 2), v17, 7);
      if ( v17 != 0 )
        v17 = v16[1];
      v20 = v16 + 1;
      if ( v19 == 0 )
        v20 = v16;
      v16 = v20;
    }
  }
  else
  {
    inserted = _mm_loadu_si128((const __m128i *)SubStr);
  }
  while ( 1 )
  {
    while ( ((unsigned __int16)v4 & 0xFFFu) > 0xFF0uLL )
    {
      if ( v4->m128i_i16[0] == 0 )
        return nullptr;
      if ( v4->m128i_i16[0] == v2 )
        goto LABEL_35;
LABEL_43:
      v4 = (const __m128i *)((char *)v4 + 2);
    }
    v21 = _mm_loadu_si128(v4);
    v22 = _mm_cmpistrc(inserted, v21, 13);
    if ( v22 | _mm_cmpistrz(inserted, v21, 13) )
      break;
    ++v4;
  }
  if ( !v22 )
    return nullptr;
  v4 = (const __m128i *)((char *)v4 + 2 * _mm_cmpistri(inserted, v21, 13));
LABEL_35:
  v23 = v4;
  for ( k = (const __m128i *)SubStr; ; ++k )
  {
    while ( ((unsigned __int16)v23 & 0xFFFu) > 0xFF0uLL || ((unsigned __int16)k & 0xFFFu) > 0xFF0uLL )
    {
      if ( k->m128i_i16[0] == 0 )
        return (wchar_t *)v4;
      if ( v23->m128i_i16[0] != k->m128i_i16[0] )
        goto LABEL_43;
      v23 = (const __m128i *)((char *)v23 + 2);
      k = (const __m128i *)((char *)k + 2);
    }
    v25 = _mm_loadu_si128(v23);
    v26 = _mm_loadu_si128(k);
    v27 = _mm_cmpistrs(v26, v25, 13);
    if ( !_mm_cmpistro(v26, v25, 13) )
      goto LABEL_43;
    if ( v27 )
      break;
    ++v23;
  }
  return (wchar_t *)v4;
}


// ===== _CxxThrowException @ 0x180009210 size=0xbf =====
void __stdcall __noreturn CxxThrowException(void *pExceptionObject, _ThrowInfo *pThrowInfo)
{
  _ThrowInfo *v2; // rbx
  __int64 v4; // rcx
  PVOID v5; // rax
  ULONG_PTR Arguments[2]; // [rsp+40h] [rbp-20h] BYREF
  __int128 v7; // [rsp+50h] [rbp-10h]
  PVOID BaseOfImage; // [rsp+70h] [rbp+10h] BYREF

  v2 = pThrowInfo;
  *(_OWORD *)Arguments = xmmword_18001BA80;
  v7 = xmmword_18001BA90;
  if ( pThrowInfo != nullptr && (pThrowInfo->attributes & 0x10) != 0 )
  {
    v4 = *(_QWORD *)pExceptionObject - 8LL;
    v2 = *(_ThrowInfo **)(*(_QWORD *)v4 + 48LL);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 64LL))(v4);
  }
  Arguments[1] = (ULONG_PTR)pExceptionObject;
  *(_QWORD *)&v7 = v2;
  v5 = RtlPcToFileHeader(v2, &BaseOfImage);
  BaseOfImage = v5;
  *((_QWORD *)&v7 + 1) = v5;
  if ( v2 != nullptr && ((v2->attributes & 8) != 0 || v5 == nullptr) )
    LODWORD(Arguments[0]) = 26820608;
  RaiseException(0xE06D7363, 1u, 4u, Arguments);
}


// ===== unknown_libname_22 @ 0x1800092d0 size=0x51 =====
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_22(unsigned int *a1, __int64 a2, __int64 a3)
{
  __int64 v4; // rax
  char v6[32]; // [rsp+58h] [rbp-20h] BYREF

  *(_QWORD *)v6 = a1;
  *(_QWORD *)&v6[8] = a3;
  v4 = _vcrt_getptd();
  (*(void (__fastcall **)(_QWORD, char *))(v4 + 16))(*a1, v6);
  return 0;
}


// ===== ?CatchTryBlock@__FrameHandler3@@SAPEBU_s_TryBlockMapEntry@@PEBU_s_FuncInfo@@H@Z @ 0x180009324 size=0x56 =====
static const struct _s_TryBlockMapEntry *__fastcall __FrameHandler3::CatchTryBlock(
        const struct _s_FuncInfo *a1,
        int a2)
{
  __int64 v2; // rbx
  __int64 v5; // rax
  __int64 v6; // rdx

  LODWORD(v2) = a1->nTryBlocks;
  while ( (_DWORD)v2 != 0 )
  {
    v5 = _vcrt_getptd();
    v2 = (unsigned int)(v2 - 1);
    v6 = a1->dispTryBlockMap + *(_QWORD *)(v5 + 96) + 20 * v2;
    if ( a2 > *(_DWORD *)(v6 + 4) && a2 <= *(_DWORD *)(v6 + 8) )
      return (const struct _s_TryBlockMapEntry *)(a1->dispTryBlockMap + *(_QWORD *)(v5 + 96) + 20 * v2);
  }
  return nullptr;
}


// ===== ?ExecutionInCatch@__FrameHandler3@@SA_NPEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@@Z @ 0x18000937c size=0x2a =====
static bool __fastcall __FrameHandler3::ExecutionInCatch(struct _xDISPATCHER_CONTEXT *a1, const struct _s_FuncInfo *a2)
{
  int v3; // eax

  v3 = sub_18000A500(a2, a1);
  return __FrameHandler3::CatchTryBlock(a2, v3) != nullptr;
}


// ===== ?FrameUnwindToEmptyState@__FrameHandler3@@SAXPEA_KPEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@@Z @ 0x1800093a8 size=0x64 =====
static void __fastcall __FrameHandler3::FrameUnwindToEmptyState(
        unsigned __int64 *a1,
        struct _xDISPATCHER_CONTEXT *a2,
        const struct _s_FuncInfo *a3)
{
  unsigned __int64 *EstablisherFrame; // rsi
  int v6; // eax
  const struct _s_TryBlockMapEntry *v7; // rax
  int tryHigh; // r9d
  unsigned __int64 v9; // [rsp+48h] [rbp+20h] BYREF

  EstablisherFrame = _GetEstablisherFrame(a1, a2, a3, &v9);
  v6 = sub_18000A500(a3, a2);
  v7 = __FrameHandler3::CatchTryBlock(a3, v6);
  if ( v7 != nullptr )
    tryHigh = v7->tryHigh;
  else
    tryHigh = -1;
  __FrameHandler3::FrameUnwindToState(EstablisherFrame, a2, a3, tryHigh);
}


// ===== ?_GetEstablisherFrame@@YAPEA_KPEA_KPEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@0@Z @ 0x18000940c size=0xc9 =====
unsigned __int64 *__fastcall _GetEstablisherFrame(
        unsigned __int64 *a1,
        struct _xDISPATCHER_CONTEXT *a2,
        const struct _s_FuncInfo *a3,
        unsigned __int64 *a4)
{
  __int64 v4; // rdi
  int v9; // ebp
  _DWORD *v10; // rbx
  PRUNTIME_FUNCTION v11; // rax
  __int64 v12; // rcx
  unsigned __int64 v13; // r8
  unsigned int v14; // r9d
  _DWORD *v15; // rdx
  unsigned __int64 ImageBase; // [rsp+50h] [rbp+8h] BYREF

  LODWORD(v4) = a3->nTryBlocks;
  v9 = sub_18000A500(a3, a2);
  *a4 = *a1;
  while ( (_DWORD)v4 != 0 )
  {
    v4 = (unsigned int)(v4 - 1);
    v10 = (_DWORD *)(a2->ImageBase + a3->dispTryBlockMap + 20 * v4);
    if ( v9 > v10[1] && v9 <= v10[2] )
    {
      v11 = RtlLookupFunctionEntry(a2->ControlPc, &ImageBase, nullptr);
      v12 = 0;
      v13 = ImageBase + (int)v10[4];
      v14 = v10[3];
      if ( v14 != 0 )
      {
        v15 = (_DWORD *)(v13 + 12);
        do
        {
          if ( *v15 == (unsigned __int64)v11->BeginAddress )
            break;
          v12 = (unsigned int)(v12 + 1);
          v15 += 5;
        }
        while ( (unsigned int)v12 < v14 );
      }
      if ( (unsigned int)v12 < v14 )
      {
        *a4 = *(_QWORD *)(*(int *)(v13 + 20 * v12 + 16) + *a1);
        return a4;
      }
    }
  }
  return a4;
}


// ===== ?GetRangeOfTrysToCheck@__FrameHandler3@@SA?AU?$pair@Viterator@TryBlockMap@__FrameHandler3@@V123@@std@@AEAVTryBlockMap@1@HH@Z @ 0x1800094d8 size=0x159 =====
_OWORD *__fastcall __FrameHandler3::GetRangeOfTrysToCheck(_OWORD *a1, _QWORD *a2, int a3)
{
  __int64 v3; // rsi
  __int64 v5; // rbp
  int v6; // ebx
  __int64 v7; // rdi
  unsigned int v8; // r14d
  int v9; // r15d
  __int64 v10; // r9
  __int64 v11; // r10
  int v12; // r8d
  unsigned int v13; // edx
  __int64 v14; // r11
  __int64 v15; // rax
  unsigned int v16; // edx
  _DWORD *v17; // rcx
  int v18; // eax
  int v19; // eax
  __int128 v21; // [rsp+20h] [rbp-58h]
  __int128 v22; // [rsp+30h] [rbp-48h]
  int v24; // [rsp+88h] [rbp+10h]

  v3 = *a2;
  v5 = a2[1];
  v6 = 0;
  v7 = 0;
  v8 = *(_DWORD *)(*a2 + 12LL);
  v9 = sub_18000A500(*a2, v5);
  if ( v8 == 0 )
    terminate();
  v10 = *(_QWORD *)(v5 + 8);
  v11 = *(int *)(v3 + 16);
  v12 = -1;
  v24 = -1;
  v13 = v8;
  do
  {
    v14 = v13 - 1;
    v15 = v10 + 20 * v14;
    if ( v9 > *(_DWORD *)(v15 + v11 + 4) && v9 <= *(_DWORD *)(v15 + v11 + 8) )
      break;
    --v13;
  }
  while ( (_DWORD)v14 != 0 );
  if ( v13 != 0 )
    v7 = v10 + v11 + 20LL * (v13 - 1);
  v16 = 0;
  v17 = (_DWORD *)(v10 + v11);
  do
  {
    if ( (v7 == 0 || *v17 > *(_DWORD *)(v7 + 4) && v17[1] <= *(_DWORD *)(v7 + 8)) && a3 >= *v17 && a3 <= v17[1] )
    {
      v24 = v16;
      v18 = v16;
      if ( v12 != -1 )
        v18 = v12;
      v12 = v18;
    }
    ++v16;
    v17 += 5;
  }
  while ( v16 < v8 );
  v19 = 0;
  *(_QWORD *)&v21 = a2;
  *(_QWORD *)&v22 = a2;
  if ( v12 != -1 )
    v19 = v12;
  DWORD2(v21) = v19;
  *a1 = v21;
  if ( v12 != -1 )
    v6 = v24 + 1;
  DWORD2(v22) = v6;
  a1[1] = v22;
  return a1;
}


// ===== ?UnwindNestedFrames@__FrameHandler3@@SAXPEA_KPEAUEHExceptionRecord@@PEAU_CONTEXT@@0PEAXPEBU_s_FuncInfo@@HHPEBU_s_HandlerType@@PEAU_xDISPATCHER_CONTEXT@@E@Z @ 0x180009634 size=0x121 =====
static void __fastcall __FrameHandler3::UnwindNestedFrames(
        void **a1,
        struct EHExceptionRecord *a2,
        struct _CONTEXT *a3,
        unsigned __int64 *a4,
        void *a5,
        const struct _s_FuncInfo *a6,
        int a7,
        int a8,
        const struct _s_HandlerType *a9,
        struct _xDISPATCHER_CONTEXT *a10,
        unsigned __int8 a11)
{
  void *v11; // rcx
  void *ControlPc; // rdx
  struct _UNWIND_HISTORY_TABLE *HistoryTable; // [rsp+28h] [rbp-D8h]
  EXCEPTION_RECORD ExceptionRecord; // [rsp+30h] [rbp-D0h] BYREF
  struct _CONTEXT ContextRecord; // [rsp+D0h] [rbp-30h] BYREF

  *(_OWORD *)&ExceptionRecord.ExceptionCode = unk_18001BAA0;
  *(_OWORD *)&ExceptionRecord.ExceptionAddress = unk_18001BAB0;
  qmemcpy(ExceptionRecord.ExceptionInformation, byte_18001BAC0, 112);
  ExceptionRecord.ExceptionInformation[14] = 0;
  v11 = *a1;
  ExceptionRecord.ExceptionInformation[0] = (ULONG_PTR)unknown_libname_24;
  ExceptionRecord.ExceptionInformation[2] = (ULONG_PTR)a5;
  ExceptionRecord.ExceptionInformation[3] = a7;
  ExceptionRecord.ExceptionInformation[5] = (ULONG_PTR)a6;
  ExceptionRecord.ExceptionInformation[7] = a11;
  HistoryTable = a10->HistoryTable;
  ExceptionRecord.ExceptionInformation[1] = (ULONG_PTR)a4;
  ExceptionRecord.ExceptionInformation[4] = (ULONG_PTR)a3;
  ExceptionRecord.ExceptionInformation[6] = (ULONG_PTR)a2;
  ControlPc = (void *)a10->ControlPc;
  ExceptionRecord.ExceptionInformation[8] = 429065504;
  RtlUnwindEx(v11, ControlPc, &ExceptionRecord, nullptr, &ContextRecord, HistoryTable);
}


// ===== _CreateFrameInfo @ 0x180009758 size=0x3a =====
_QWORD *__fastcall CreateFrameInfo(_QWORD *a1, __int64 a2)
{
  __int64 v3; // rcx

  *a1 = a2;
  if ( (unsigned __int64)a1 >= *(_QWORD *)(_vcrt_getptd() + 88) )
    v3 = 0;
  else
    v3 = *(_QWORD *)(_vcrt_getptd() + 88);
  a1[1] = v3;
  *(_QWORD *)(_vcrt_getptd() + 88) = a1;
  return a1;
}


// ===== _FindAndUnlinkFrame @ 0x180009794 size=0x53 =====
__int64 __fastcall FindAndUnlinkFrame(__int64 a1)
{
  __int64 i; // rdx
  __int64 *v3; // rbx
  __int64 result; // rax

  if ( a1 != *(_QWORD *)(_vcrt_getptd() + 88) )
LABEL_8:
    terminate();
  for ( i = *(_QWORD *)(_vcrt_getptd() + 88); ; i = *v3 )
  {
    if ( i == 0 )
      goto LABEL_8;
    v3 = (__int64 *)(i + 8);
    if ( a1 == i )
      break;
  }
  result = _vcrt_getptd();
  *(_QWORD *)(result + 88) = *v3;
  return result;
}


// ===== _GetImageBase @ 0x1800097e8 size=0x12 =====
__int64 GetImageBase()
{
  return *(_QWORD *)(_vcrt_getptd() + 96);
}


// ===== _GetThrowImageBase @ 0x1800097fc size=0x12 =====
__int64 GetThrowImageBase()
{
  return *(_QWORD *)(_vcrt_getptd() + 104);
}


// ===== _SetImageBase @ 0x180009810 size=0x18 =====
__int64 __fastcall SetImageBase(__int64 a1)
{
  __int64 result; // rax

  result = _vcrt_getptd();
  *(_QWORD *)(result + 96) = a1;
  return result;
}


// ===== _SetThrowImageBase @ 0x180009828 size=0x18 =====
__int64 __fastcall SetThrowImageBase(__int64 a1)
{
  __int64 result; // rax

  result = _vcrt_getptd();
  *(_QWORD *)(result + 104) = a1;
  return result;
}


// ===== __CxxFrameHandler3 @ 0x180009840 size=0x7d =====
__int64 __fastcall _CxxFrameHandler3(struct EHExceptionRecord *a1, unsigned __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // rax
  unsigned __int64 v8; // [rsp+50h] [rbp+8h] BYREF

  v8 = a2;
  *(_QWORD *)(_vcrt_getptd() + 96) = *(_QWORD *)(a4 + 8);
  *(_QWORD *)(_vcrt_getptd() + 104) = a1->params.pThrowImageBase;
  v6 = _vcrt_getptd();
  return __InternalCxxFrameHandler<__FrameHandler3>(
           a1,
           &v8,
           (struct _s_FuncInfo *)(*(_QWORD *)(v6 + 96) + **(unsigned int **)(a4 + 56)),
           0,
           0,
           0);
}


// ===== sub_1800098D0 @ 0x1800098d0 size=0x13 =====
__int64 __fastcall sub_1800098D0(void *a1, __int64 a2, unsigned __int64 a3)
{
  const void *v3; // r10
  __int64 v4; // r11

  qmemcpy(a1, v3, a3);
  return v4;
}


// ===== sub_1800098F0 @ 0x1800098f0 size=0x425 =====
__int64 __fastcall sub_1800098F0(__m128i *a1, const __m128i *a2, unsigned __int64 a3)
{
  bool v5; // cf
  __int64 v6; // rdx
  __int64 result; // rax
  __m128i v8; // xmm1
  __int8 v9; // r8
  __int16 v10; // cx
  __int8 v11; // r9
  __int8 v12; // r8
  __int16 v13; // r8
  __int16 v14; // r8
  __int8 v15; // r9
  __int32 v16; // ecx
  __int8 v17; // r9
  __int8 v18; // cl
  __int16 v19; // cx
  __int32 v20; // ecx
  __int32 v21; // ecx
  __int16 v22; // r9
  __int32 v23; // ecx
  __int16 v24; // r9
  __int8 v25; // r10
  __m128 v26; // xmm0
  __int8 *v27; // r8
  unsigned __int64 v28; // rcx
  __m128 v29; // xmm1
  unsigned __int64 v30; // rcx
  unsigned __int64 v31; // r8
  unsigned __int64 v32; // r9
  __int128 v33; // xmm0
  __int128 v34; // xmm1
  __int128 v35; // xmm1
  __int128 v36; // xmm1
  __m128 v37; // xmm0
  __m128 v38; // xmm1
  unsigned __int64 j; // r9
  unsigned __int64 v40; // r8
  __m128 v41; // xmm0
  __m128 v42; // xmm1
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  __m128 v45; // xmm1
  __int8 *v46; // rcx
  __int128 v47; // xmm0
  unsigned __int64 v48; // rcx
  unsigned __int64 v49; // r8
  _OWORD *v50; // rax
  __int128 v51; // xmm1
  unsigned __int64 v52; // r9
  __int128 v53; // xmm0
  __int128 v54; // xmm1
  __int128 v55; // xmm1
  __int128 v56; // xmm1
  __int128 v57; // xmm0
  __int128 v58; // xmm1
  unsigned __int64 i; // r9

  result = (__int64)a1;
  switch ( a3 )
  {
    case 0uLL:
      return result;
    case 1uLL:
      a1->m128i_i8[0] = a2->m128i_i8[0];
      break;
    case 2uLL:
      a1->m128i_i16[0] = a2->m128i_i16[0];
      break;
    case 3uLL:
      v9 = a2->m128i_i8[2];
      a1->m128i_i16[0] = a2->m128i_i16[0];
      a1->m128i_i8[2] = v9;
      break;
    case 4uLL:
      a1->m128i_i32[0] = a2->m128i_i32[0];
      break;
    case 5uLL:
      v12 = a2->m128i_i8[4];
      a1->m128i_i32[0] = a2->m128i_i32[0];
      a1->m128i_i8[4] = v12;
      break;
    case 6uLL:
      v13 = a2->m128i_i16[2];
      a1->m128i_i32[0] = a2->m128i_i32[0];
      a1->m128i_i16[2] = v13;
      break;
    case 7uLL:
      v14 = a2->m128i_i16[2];
      v15 = a2->m128i_i8[6];
      a1->m128i_i32[0] = a2->m128i_i32[0];
      a1->m128i_i16[2] = v14;
      a1->m128i_i8[6] = v15;
      break;
    case 8uLL:
      a1->m128i_i64[0] = a2->m128i_i64[0];
      break;
    case 9uLL:
      v18 = a2->m128i_i8[8];
      *(_QWORD *)result = a2->m128i_i64[0];
      *(_BYTE *)(result + 8) = v18;
      break;
    case 0xAuLL:
      v19 = a2->m128i_i16[4];
      *(_QWORD *)result = a2->m128i_i64[0];
      *(_WORD *)(result + 8) = v19;
      break;
    case 0xBuLL:
      v10 = a2->m128i_i16[4];
      v11 = a2->m128i_i8[10];
      *(_QWORD *)result = a2->m128i_i64[0];
      *(_WORD *)(result + 8) = v10;
      *(_BYTE *)(result + 10) = v11;
      break;
    case 0xCuLL:
      v20 = a2->m128i_i32[2];
      *(_QWORD *)result = a2->m128i_i64[0];
      *(_DWORD *)(result + 8) = v20;
      break;
    case 0xDuLL:
      v16 = a2->m128i_i32[2];
      v17 = a2->m128i_i8[12];
      *(_QWORD *)result = a2->m128i_i64[0];
      *(_DWORD *)(result + 8) = v16;
      *(_BYTE *)(result + 12) = v17;
      break;
    case 0xEuLL:
      v21 = a2->m128i_i32[2];
      v22 = a2->m128i_i16[6];
      *(_QWORD *)result = a2->m128i_i64[0];
      *(_DWORD *)(result + 8) = v21;
      *(_WORD *)(result + 12) = v22;
      break;
    case 0xFuLL:
      v23 = a2->m128i_i32[2];
      v24 = a2->m128i_i16[6];
      v25 = a2->m128i_i8[14];
      *(_QWORD *)result = a2->m128i_i64[0];
      *(_DWORD *)(result + 8) = v23;
      *(_WORD *)(result + 12) = v24;
      *(_BYTE *)(result + 14) = v25;
      break;
    case 0x10uLL:
      *a1 = _mm_loadu_si128(a2);
      break;
    default:
      if ( a3 <= 0x20 )
      {
        v8 = *(const __m128i *)((char *)a2 + a3 - 16);
        *a1 = *a2;
        *(__m128i *)((char *)a1 + a3 - 16) = v8;
        result = (__int64)a1;
      }
      else
      {
        v5 = a2 < a1;
        v6 = (char *)a2 - (char *)a1;
        if ( v5 && a1 < (__m128i *)&a2->m128i_i8[a3] )
        {
          v46 = &a1->m128i_i8[a3];
          v47 = *(_OWORD *)&v46[v6 - 16];
          v48 = (unsigned __int64)(v46 - 16);
          v49 = a3 - 16;
          if ( (v48 & 0xF) != 0 )
          {
            v50 = (_OWORD *)v48;
            v48 &= 0xFFFFFFFFFFFFFFF0uLL;
            v51 = v47;
            v47 = *(_OWORD *)(v48 + v6);
            *v50 = v51;
            v49 = v48 - (_QWORD)a1;
          }
          v52 = v49 >> 7;
          if ( v49 >> 7 != 0 )
          {
            for ( *(_OWORD *)v48 = v47; ; *(_OWORD *)v48 = v58 )
            {
              v53 = *(_OWORD *)(v48 + v6 - 16);
              v54 = *(_OWORD *)(v48 + v6 - 32);
              v48 -= 128LL;
              *(_OWORD *)(v48 + 112) = v53;
              *(_OWORD *)(v48 + 96) = v54;
              v55 = *(_OWORD *)(v48 + v6 + 64);
              --v52;
              *(_OWORD *)(v48 + 80) = *(_OWORD *)(v48 + v6 + 80);
              *(_OWORD *)(v48 + 64) = v55;
              v56 = *(_OWORD *)(v48 + v6 + 32);
              *(_OWORD *)(v48 + 48) = *(_OWORD *)(v48 + v6 + 48);
              *(_OWORD *)(v48 + 32) = v56;
              v57 = *(_OWORD *)(v48 + v6 + 16);
              v58 = *(_OWORD *)(v48 + v6);
              if ( v52 == 0 )
                break;
              *(_OWORD *)(v48 + 16) = v57;
            }
            *(_OWORD *)(v48 + 16) = v57;
            v49 &= 0x7Fu;
            v47 = v58;
          }
          for ( i = v49 >> 4; i != 0; --i )
          {
            *(_OWORD *)v48 = v47;
            v48 -= 16LL;
            v47 = *(_OWORD *)(v48 + v6);
          }
          if ( (v49 & 0xF) != 0 )
            *a1 = *a2;
          *(_OWORD *)v48 = v47;
          result = (__int64)a1;
        }
        else
        {
          if ( a3 <= 0x80 )
          {
            v26 = *(__m128 *)((char *)a1 + v6);
            v28 = (unsigned __int64)&a1[1];
            v31 = a3 - 16;
          }
          else
          {
            if ( _bittest(&dword_18002A87C, 1u) )
              return sub_1800098D0(a1, v6, a3);
            v26 = *(__m128 *)((char *)a1 + v6);
            v27 = &a1->m128i_i8[a3];
            v28 = (unsigned __int64)&a1[1];
            if ( ((unsigned __int8)a1 & 0xF) != 0 )
            {
              v29 = v26;
              v30 = v28 & 0xFFFFFFFFFFFFFFF0uLL;
              v26 = *(__m128 *)(v30 + v6);
              v28 = v30 + 16;
              *a1 = (__m128i)v29;
            }
            v31 = (unsigned __int64)&v27[-v28];
            v32 = v31 >> 7;
            if ( v31 >> 7 != 0 )
            {
              *(__m128 *)(v28 - 16) = v26;
              if ( v32 <= qword_180029020 )
              {
                while ( 1 )
                {
                  v33 = *(_OWORD *)(v28 + v6);
                  v34 = *(_OWORD *)(v28 + v6 + 16);
                  v28 += 128LL;
                  *(_OWORD *)(v28 - 128) = v33;
                  *(_OWORD *)(v28 - 112) = v34;
                  v35 = *(_OWORD *)(v28 + v6 - 80);
                  --v32;
                  *(_OWORD *)(v28 - 96) = *(_OWORD *)(v28 + v6 - 96);
                  *(_OWORD *)(v28 - 80) = v35;
                  v36 = *(_OWORD *)(v28 + v6 - 48);
                  *(_OWORD *)(v28 - 64) = *(_OWORD *)(v28 + v6 - 64);
                  *(_OWORD *)(v28 - 48) = v36;
                  v37 = *(__m128 *)(v28 + v6 - 32);
                  v38 = *(__m128 *)(v28 + v6 - 16);
                  if ( v32 == 0 )
                    break;
                  *(__m128 *)(v28 - 32) = v37;
                  *(__m128 *)(v28 - 16) = v38;
                }
              }
              else
              {
                while ( 1 )
                {
                  _mm_prefetch((const char *)(v28 + v6 + 512), 0);
                  v41 = *(__m128 *)(v28 + v6);
                  v42 = *(__m128 *)(v28 + v6 + 16);
                  v28 += 128LL;
                  _mm_stream_ps((float *)(v28 - 128), v41);
                  _mm_stream_ps((float *)(v28 - 112), v42);
                  v43 = *(__m128 *)(v28 + v6 - 80);
                  --v32;
                  _mm_stream_ps((float *)(v28 - 96), *(__m128 *)(v28 + v6 - 96));
                  _mm_stream_ps((float *)(v28 - 80), v43);
                  v44 = *(__m128 *)(v28 + v6 - 64);
                  v45 = *(__m128 *)(v28 + v6 - 48);
                  _mm_prefetch((const char *)(v28 + v6 + 576), 0);
                  _mm_stream_ps((float *)(v28 - 64), v44);
                  _mm_stream_ps((float *)(v28 - 48), v45);
                  v37 = *(__m128 *)(v28 + v6 - 32);
                  v38 = *(__m128 *)(v28 + v6 - 16);
                  if ( v32 == 0 )
                    break;
                  _mm_stream_ps((float *)(v28 - 32), v37);
                  _mm_stream_ps((float *)(v28 - 16), v38);
                }
                _mm_sfence();
              }
              *(__m128 *)(v28 - 32) = v37;
              v31 &= 0x7Fu;
              v26 = v38;
            }
          }
          for ( j = v31 >> 4; j != 0; --j )
          {
            *(__m128 *)(v28 - 16) = v26;
            v26 = *(__m128 *)(v28 + v6);
            v28 += 16LL;
          }
          v40 = v31 & 0xF;
          if ( v40 != 0 )
            *(_OWORD *)(v28 + v40 - 16) = *(_OWORD *)(v28 + v40 + v6 - 16);
          *(__m128 *)(v28 - 16) = v26;
          result = (__int64)a1;
        }
      }
      break;
  }
  return result;
}


// ===== sub_180009D30 @ 0x180009d30 size=0x10 =====
__int64 __fastcall sub_180009D30(void *a1, char a2, unsigned __int64 a3)
{
  __int64 v3; // r11

  memset(a1, a2, a3);
  return v3;
}


// ===== sub_180009D50 @ 0x180009d50 size=0x190 =====
__int64 __fastcall sub_180009D50(__m128i *a1, unsigned __int8 a2, unsigned __int64 a3)
{
  __m128i v4; // xmm0
  __m128i *v5; // rcx
  unsigned __int64 v6; // r9
  unsigned __int64 i; // r9
  unsigned __int64 v8; // r8
  __int64 result; // rax
  __int64 v11; // kr18_8
  __int8 *v12; // rcx

  v11 = 0x101010101010101LL * a2;
  v12 = &a1->m128i_i8[a3];
  result = (__int64)a1;
  switch ( a3 )
  {
    case 0uLL:
      return result;
    case 1uLL:
      goto LABEL_16;
    case 2uLL:
      goto LABEL_24;
    case 3uLL:
      goto LABEL_15;
    case 4uLL:
      goto LABEL_18;
    case 5uLL:
      goto LABEL_21;
    case 6uLL:
      goto LABEL_23;
    case 7uLL:
      goto LABEL_14;
    case 8uLL:
      a1->m128i_i64[0] = v11;
      return result;
    case 9uLL:
      *(_QWORD *)(v12 - 9) = v11;
      *(v12 - 1) = v11;
      return result;
    case 0xAuLL:
      a1->m128i_i64[0] = v11;
      a1->m128i_i16[4] = v11;
      return result;
    case 0xBuLL:
      a1->m128i_i64[0] = v11;
      a1->m128i_i16[4] = v11;
      a1->m128i_i8[10] = v11;
      return result;
    case 0xCuLL:
      *(_QWORD *)(v12 - 12) = v11;
LABEL_18:
      *((_DWORD *)v12 - 1) = v11;
      return result;
    case 0xDuLL:
      *(_QWORD *)(v12 - 13) = v11;
LABEL_21:
      *(_DWORD *)(v12 - 5) = v11;
      *(v12 - 1) = v11;
      return result;
    case 0xEuLL:
      *(_QWORD *)(v12 - 14) = v11;
LABEL_23:
      *(_DWORD *)(v12 - 6) = v11;
LABEL_24:
      *((_WORD *)v12 - 1) = v11;
      return result;
    case 0xFuLL:
      *(_QWORD *)(v12 - 15) = v11;
LABEL_14:
      *(_DWORD *)(v12 - 7) = v11;
LABEL_15:
      *(_WORD *)(v12 - 3) = v11;
LABEL_16:
      *(v12 - 1) = v11;
      return result;
    case 0x10uLL:
      a1->m128i_i64[0] = v11;
      a1->m128i_i64[1] = v11;
      return result;
    default:
      v5 = a1;
      v4 = _mm_unpacklo_epi8((__m128i)(unsigned __int64)v11, (__m128i)(unsigned __int64)v11);
      if ( a3 <= 0x80 )
        goto LABEL_7;
      if ( _bittest(&dword_18002A87C, 1u) )
        return sub_180009D30(a1, a2, a3);
      *a1 = v4;
      v5 = (__m128i *)((unsigned __int64)&a1[1] & 0xFFFFFFFFFFFFFFF0uLL);
      a3 = &a1->m128i_i8[a3] - (__int8 *)v5;
      v6 = a3 >> 7;
      if ( a3 >> 7 != 0 )
      {
        do
        {
          *v5 = v4;
          v5[1] = v4;
          v5 += 8;
          v5[-6] = v4;
          v5[-5] = v4;
          --v6;
          v5[-4] = v4;
          v5[-3] = v4;
          v5[-2] = v4;
          v5[-1] = v4;
        }
        while ( v6 != 0 );
        a3 &= 0x7Fu;
      }
LABEL_7:
      for ( i = a3 >> 4; i != 0; --i )
        *v5++ = v4;
      v8 = a3 & 0xF;
      if ( v8 != 0 )
        *(__m128i *)((char *)v5 + v8 - 16) = v4;
      return (__int64)a1;
  }
}


// ===== __std_exception_copy @ 0x180009ee0 size=0x8d =====
void __fastcall _std_exception_copy(__int64 a1, __int64 a2)
{
  __int64 v4; // rdi
  char *v5; // rax
  char *v6; // rbx

  if ( *(_BYTE *)(a1 + 8) != 0 && *(_QWORD *)a1 != 0 )
  {
    v4 = -1;
    do
      ++v4;
    while ( *(_BYTE *)(*(_QWORD *)a1 + v4) != 0 );
    v5 = (char *)j__malloc_base(v4 + 1);
    v6 = v5;
    if ( v5 != nullptr )
    {
      strcpy_s(v5, v4 + 1, *(const char **)a1);
      *(_BYTE *)(a2 + 8) = 1;
      *(_QWORD *)a2 = v6;
      v6 = nullptr;
    }
    j__free_base(v6);
  }
  else
  {
    *(_QWORD *)a2 = *(_QWORD *)a1;
    *(_BYTE *)(a2 + 8) = 0;
  }
}


// ===== __std_exception_destroy @ 0x180009f70 size=0x25 =====
void __fastcall _std_exception_destroy(__int64 a1)
{
  if ( *(_BYTE *)(a1 + 8) != 0 )
    j__free_base(*(void **)a1);
  *(_QWORD *)a1 = 0;
  *(_BYTE *)(a1 + 8) = 0;
}


// ===== __vcrt_initialize @ 0x180009f98 size=0x32 =====
__vcrt_bool __cdecl _vcrt_initialize()
{
  _vcrt_initialize_pure_virtual_call_handler();
  _vcrt_initialize_winapi_thunks();
  if ( (unsigned __int8)_vcrt_initialize_locks() == 0 )
    return false;
  if ( (unsigned __int8)_vcrt_initialize_ptd() == 0 )
  {
    _vcrt_uninitialize_locks();
    return false;
  }
  return true;
}


// ===== ?HasUnrealizedChores@ScheduleGroupSegmentBase@details@Concurrency@@IEAA_NXZ @ 0x180009fcc size=0x14 =====
bool __fastcall Concurrency::details::ScheduleGroupSegmentBase::HasUnrealizedChores(
        Concurrency::details::ScheduleGroupSegmentBase *this)
{
  return _vcrt_getptd_noexit(this) != 0;
}


// ===== __vcrt_thread_detach @ 0x180009fe0 size=0x12 =====
__vcrt_bool __cdecl _vcrt_thread_detach()
{
  _vcrt_freeptd(nullptr);
  return true;
}


// ===== __vcrt_uninitialize @ 0x180009ff4 size=0x20 =====
__vcrt_bool __cdecl _vcrt_uninitialize(__vcrt_bool Terminating)
{
  if ( !Terminating )
  {
    _vcrt_uninitialize_ptd();
    _vcrt_uninitialize_locks();
    _vcrt_uninitialize_winapi_thunks(0);
  }
  return true;
}


// ===== __vcrt_uninitialize_critical @ 0x18000a014 size=0x10 =====
__vcrt_bool __cdecl _vcrt_uninitialize_critical()
{
  _vcrt_uninitialize_ptd();
  return true;
}


// ===== __C_specific_handler @ 0x18000a024 size=0x20b =====
EXCEPTION_DISPOSITION __cdecl _C_specific_handler(
        struct _EXCEPTION_RECORD *ExceptionRecord,
        void *EstablisherFrame,
        struct _CONTEXT *ContextRecord,
        struct _DISPATCHER_CONTEXT *DispatcherContext)
{
  DWORD64 ImageBase; // r12
  DWORD *HandlerData; // rbx
  unsigned __int64 v10; // r14
  DWORD ScopeIndex; // esi
  int v12; // eax
  DWORD v14; // r9d
  unsigned __int64 v15; // rdi
  DWORD v16; // r8d
  __int64 v17; // rcx
  DWORD i; // r10d
  __int64 v19; // rax
  _QWORD v20[2]; // [rsp+30h] [rbp-38h] BYREF

  _except_validate_context_record(ContextRecord);
  ImageBase = DispatcherContext->ImageBase;
  HandlerData = (DWORD *)DispatcherContext->HandlerData;
  v10 = DispatcherContext->ControlPc - ImageBase;
  ScopeIndex = DispatcherContext->ScopeIndex;
  if ( (ExceptionRecord->ExceptionFlags & 0x66) != 0 )
  {
    v14 = *HandlerData;
    v15 = DispatcherContext->TargetIp - ImageBase;
    if ( ScopeIndex < *HandlerData )
    {
      v16 = *HandlerData;
      do
      {
        v17 = v16;
        if ( v10 >= HandlerData[4 * ScopeIndex + 1] && v10 < HandlerData[4 * ScopeIndex + 2] )
        {
          if ( (ExceptionRecord->ExceptionFlags & 0x20) != 0 )
          {
            for ( i = 0; i < v16; ++i )
            {
              if ( v15 >= HandlerData[4 * i + 1]
                && v15 < HandlerData[4 * i + 2]
                && HandlerData[4 * i + 4] == HandlerData[4 * ScopeIndex + 4]
                && HandlerData[4 * i + 3] == HandlerData[4 * ScopeIndex + 3] )
              {
                break;
              }
            }
            v17 = v14;
            if ( i != v14 )
              return ExceptionContinueSearch;
          }
          v19 = HandlerData[4 * ScopeIndex + 4];
          if ( (_DWORD)v19 != 0 )
          {
            if ( v15 == v19 && (ExceptionRecord->ExceptionFlags & 0x20) != 0 )
              return ExceptionContinueSearch;
          }
          else
          {
            LOBYTE(v17) = 1;
            DispatcherContext->ScopeIndex = ScopeIndex + 1;
            ((void (__fastcall *)(__int64, void *))(ImageBase + HandlerData[4 * ScopeIndex + 3]))(v17, EstablisherFrame);
            v14 = *HandlerData;
            LODWORD(v17) = *HandlerData;
          }
        }
        ++ScopeIndex;
        v16 = v17;
      }
      while ( ScopeIndex < (unsigned int)v17 );
    }
  }
  else
  {
    v20[0] = ExceptionRecord;
    v20[1] = ContextRecord;
    while ( ScopeIndex < *HandlerData )
    {
      if ( v10 >= HandlerData[4 * ScopeIndex + 1]
        && v10 < HandlerData[4 * ScopeIndex + 2]
        && HandlerData[4 * ScopeIndex + 4] != 0 )
      {
        if ( HandlerData[4 * ScopeIndex + 3] == 1 )
          goto LABEL_11;
        v12 = ((__int64 (__fastcall *)(_QWORD *, void *))(ImageBase + HandlerData[4 * ScopeIndex + 3]))(
                v20,
                EstablisherFrame);
        if ( v12 < 0 )
          return ExceptionContinueExecution;
        if ( v12 > 0 )
        {
LABEL_11:
          if ( ExceptionRecord->ExceptionCode == -529697949
            && _DestructExceptionObject != nullptr
            && (unsigned int)IsNonwritableInCurrentImage(&off_18001BCB0) != 0 )
          {
            _DestructExceptionObject(ExceptionRecord, 1);
          }
          NLG_Notify(ImageBase + HandlerData[4 * ScopeIndex + 4], EstablisherFrame, 1);
          RtlUnwindEx(
            EstablisherFrame,
            (PVOID)(ImageBase + HandlerData[4 * ScopeIndex + 4]),
            ExceptionRecord,
            (PVOID)ExceptionRecord->ExceptionCode,
            DispatcherContext->ContextRecord,
            DispatcherContext->HistoryTable);
          nullsub_1();
        }
      }
      ++ScopeIndex;
    }
  }
  return ExceptionContinueSearch;
}


// ===== __std_type_info_compare @ 0x18000a230 size=0x27 =====
__int64 __fastcall _std_type_info_compare(__int64 a1, __int64 a2)
{
  char *v2; // rax
  __int64 v3; // rdx
  char v4; // cl

  if ( a1 == a2 )
    return 0;
  v2 = (char *)(a1 + 9);
  v3 = a2 - a1;
  while ( 1 )
  {
    v4 = *v2;
    if ( *v2 != v2[v3] )
      break;
    ++v2;
    if ( v4 == 0 )
      return 0;
  }
  return (unsigned __int8)*v2 < (unsigned __int8)v2[v3] ? -1 : 1;
}


// ===== __std_type_info_destroy_list @ 0x18000a258 size=0x2a =====
PSLIST_ENTRY __fastcall _std_type_info_destroy_list(union _SLIST_HEADER *a1)
{
  PSLIST_ENTRY result; // rax
  struct _SLIST_ENTRY *Next; // rbx

  result = InterlockedFlushSList(a1);
  if ( result != nullptr )
  {
    do
    {
      Next = result->Next;
      j__free_base(result);
      result = Next;
    }
    while ( Next != nullptr );
  }
  return result;
}


// ===== __vcrt_initialize_pure_virtual_call_handler @ 0x18000a284 size=0xf =====
uintptr_t _vcrt_initialize_pure_virtual_call_handler()
{
  qword_18002A8B8 = _security_cookie;
  return _security_cookie;
}


// ===== __vcrt_freefls @ 0x18000a294 size=0x1f =====
void __fastcall _vcrt_freefls(void *a1)
{
  if ( a1 != nullptr && a1 != &unk_18002A8C0 )
    j__free_base(a1);
}


// ===== __vcrt_freeptd @ 0x18000a2b4 size=0x4d =====
void __fastcall _vcrt_freeptd(void *Block)
{
  DWORD v2; // ecx
  void *Value; // rax

  v2 = dword_180029290;
  if ( dword_180029290 != -1 )
  {
    if ( Block == nullptr )
    {
      Value = (void *)_vcrt_FlsGetValue();
      v2 = dword_180029290;
      Block = Value;
    }
    _vcrt_FlsSetValue(v2, nullptr);
    if ( Block != nullptr && Block != &unk_18002A8C0 )
      j__free_base(Block);
  }
}


// ===== __vcrt_getptd @ 0x18000a304 size=0x19 =====
__int64 __fastcall _vcrt_getptd(__int64 a1)
{
  __int64 result; // rax

  result = _vcrt_getptd_noexit(a1);
  if ( result == 0 )
    abort();
  return result;
}


// ===== __vcrt_getptd_noexit @ 0x18000a320 size=0xcb =====
__int64 _vcrt_getptd_noexit()
{
  DWORD LastError; // edi
  __int64 Value; // rax
  __int64 v3; // rsi
  _DWORD *v4; // rax
  DWORD v5; // ecx
  _DWORD *v6; // rbx
  __int64 v7; // rax

  if ( dword_180029290 == -1 )
    return 0;
  LastError = GetLastError();
  Value = _vcrt_FlsGetValue(dword_180029290);
  v3 = 0;
  if ( Value != -1 )
  {
    if ( Value != 0 )
    {
      v3 = Value;
      goto LABEL_13;
    }
    if ( (unsigned int)_vcrt_FlsSetValue(dword_180029290, (LPVOID)0xFFFFFFFFFFFFFFFFLL) == 0 )
      goto LABEL_13;
    v4 = j__calloc_base(1u, 0x90u);
    v5 = dword_180029290;
    v6 = v4;
    if ( v4 != nullptr )
    {
      if ( (unsigned int)_vcrt_FlsSetValue(dword_180029290, v4) != 0 )
      {
        v6[30] = -2;
        *((_QWORD *)v6 + 16) = -2;
        v7 = (__int64)v6;
        v6 = nullptr;
        v3 = v7;
LABEL_12:
        j__free_base(v6);
        goto LABEL_13;
      }
      v5 = dword_180029290;
    }
    _vcrt_FlsSetValue(v5, nullptr);
    goto LABEL_12;
  }
LABEL_13:
  SetLastError(LastError);
  return v3;
}


// ===== __vcrt_initialize_ptd @ 0x18000a3ec size=0x51 =====
char _vcrt_initialize_ptd()
{
  DWORD v0; // eax

  v0 = _vcrt_FlsAlloc(_vcrt_freefls);
  dword_180029290 = v0;
  if ( v0 != -1 )
  {
    if ( (unsigned int)_vcrt_FlsSetValue(v0, &unk_18002A8C0) != 0 )
    {
      dword_18002A938 = -2;
      qword_18002A940 = -2;
      return 1;
    }
    _vcrt_uninitialize_ptd();
  }
  return 0;
}


// ===== __vcrt_uninitialize_ptd @ 0x18000a440 size=0x22 =====
char _vcrt_uninitialize_ptd()
{
  if ( dword_180029290 != -1 )
  {
    _vcrt_FlsFree();
    dword_180029290 = -1;
  }
  return 1;
}


// ===== sub_18000A464 @ 0x18000a464 size=0x27 =====
__int64 __fastcall sub_18000A464(_QWORD *a1, _QWORD *a2, __int64 a3)
{
  __int64 result; // rax

  result = *(unsigned int *)(*(int *)(a3 + 28) + *a1);
  if ( (_DWORD)result == -2 )
    return unknown_libname_23(a3, a2, *a2);
  return result;
}


// ===== ?__GetUnwindTryBlock@@YAHPEA_KPEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@@Z @ 0x18000a48c size=0x29 =====
__int64 __fastcall __GetUnwindTryBlock(
        unsigned __int64 *a1,
        struct _xDISPATCHER_CONTEXT *a2,
        const struct _s_FuncInfo *a3)
{
  unsigned __int64 v4; // rcx
  __int64 dispUwindHelp; // rax
  unsigned __int64 v7; // [rsp+40h] [rbp+18h] BYREF

  v4 = *_GetEstablisherFrame(a1, a2, a3, &v7);
  dispUwindHelp = a3->dispUwindHelp;
  v7 = v4;
  return *(unsigned int *)(dispUwindHelp + v4 + 4);
}


// ===== ?SetState@__FrameHandler3@@SAXPEA_KPEBU_s_FuncInfo@@H@Z @ 0x18000a4b8 size=0xc =====
static void __fastcall __FrameHandler3::SetState(unsigned __int64 *a1, const struct _s_FuncInfo *a2, int a3)
{
  *(_DWORD *)(a2->dispUwindHelp + *a1) = a3;
}


// ===== ?__SetUnwindTryBlock@@YAXPEA_KPEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@H@Z @ 0x18000a4c4 size=0x3b =====
void __fastcall __SetUnwindTryBlock(
        unsigned __int64 *a1,
        struct _xDISPATCHER_CONTEXT *a2,
        const struct _s_FuncInfo *a3,
        int a4)
{
  unsigned __int64 v6; // rcx
  __int64 dispUwindHelp; // rax
  unsigned __int64 v8; // [rsp+40h] [rbp+18h] BYREF

  v6 = *_GetEstablisherFrame(a1, a2, a3, &v8);
  dispUwindHelp = a3->dispUwindHelp;
  v8 = v6;
  if ( a4 > *(_DWORD *)(dispUwindHelp + v6 + 4) )
    *(_DWORD *)(dispUwindHelp + v6 + 4) = a4;
}


// ===== sub_18000A500 @ 0x18000a500 size=0x8 =====
__int64 __fastcall sub_18000A500(__int64 a1, _QWORD *a2)
{
  return unknown_libname_23(a1, a2, *a2);
}


// ===== unknown_libname_23 @ 0x18000a508 size=0x66 =====
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_23(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // r11
  __int64 v5; // r10
  unsigned int v6; // r8d
  __int64 v7; // r9

  if ( a1 == 0 || (v4 = *(int *)(a1 + 24), v5 = *(_QWORD *)(a2 + 8), v4 + v5 == 0) )
    terminate();
  v6 = *(_DWORD *)(a1 + 20);
  v7 = 0;
  if ( v6 == 0 )
    return 0xFFFFFFFFLL;
  do
  {
    if ( a3 < v5 + (unsigned __int64)*(unsigned int *)(v4 + 8 * v7 + v5) )
      break;
    v7 = (unsigned int)(v7 + 1);
  }
  while ( (unsigned int)v7 < v6 );
  if ( (_DWORD)v7 != 0 )
    return *(unsigned int *)(v4 + 8LL * (unsigned int)(v7 - 1) + v5 + 4);
  else
    return 0xFFFFFFFFLL;
}


// ===== ??$BuildCatchObjectHelperInternal@$$CBU_s_HandlerType@@@@YAHPEAUEHExceptionRecord@@PEAXPEBU_s_HandlerType@@PEBU_s_CatchableType@@@Z @ 0x18000a570 size=0x1fd =====
__int64 __fastcall BuildCatchObjectHelperInternal<_s_HandlerType const>(__int64 a1, __m128i *a2, int *a3, __int64 a4)
{
  unsigned int v8; // edi
  __int64 v9; // r15
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rcx
  const __m128i *v14; // rdx
  __int64 v15; // rbx
  __int64 v16; // rcx
  __int64 v17; // rcx
  unsigned __int64 v18; // rbx
  const __m128i *v19; // rax
  __int64 v20; // rcx

  v8 = 0;
  if ( a3[1] != 0 )
  {
    v9 = a3[1];
    v10 = v9 + GetImageBase();
  }
  else
  {
    v10 = 0;
    LODWORD(v9) = 0;
  }
  if ( v10 != 0 )
  {
    v11 = (_DWORD)v9 != 0 ? a3[1] + GetImageBase() : 0LL;
    if ( *(_BYTE *)(v11 + 16) != 0 && (a3[2] != 0 || *a3 < 0) )
    {
      if ( *a3 >= 0 )
        a2 = (__m128i *)(a2->m128i_i64[0] + a3[2]);
      if ( *(char *)a3 < 0 && (*(_BYTE *)a4 & 0x10) != 0 && qword_18002A9C0 != nullptr )
      {
        v12 = qword_18002A9C0();
        if ( v12 == 0 || a2 == nullptr )
          terminate();
        a2->m128i_i64[0] = v12;
        v13 = v12;
      }
      else if ( (*(_BYTE *)a3 & 8) != 0 )
      {
        v13 = *(_QWORD *)(a1 + 40);
        if ( v13 == 0 || a2 == nullptr )
          terminate();
        a2->m128i_i64[0] = v13;
      }
      else
      {
        if ( (*(_BYTE *)a4 & 1) == 0 )
        {
          if ( *(_DWORD *)(a4 + 24) != 0 )
          {
            v15 = *(int *)(a4 + 24);
            v16 = v15 + GetThrowImageBase();
          }
          else
          {
            v16 = 0;
            LODWORD(v15) = 0;
          }
          if ( v16 != 0 )
          {
            if ( *(_QWORD *)(a1 + 40) == 0
              || a2 == nullptr
              || ((_DWORD)v15 == 0 ? (v20 = 0) : (v20 = *(int *)(a4 + 24) + GetThrowImageBase()), v20 == 0) )
            {
              terminate();
            }
            return (unsigned int)((*(_BYTE *)a4 & 4) != 0) + 1;
          }
          else
          {
            v17 = *(_QWORD *)(a1 + 40);
            if ( v17 == 0 || a2 == nullptr )
              terminate();
            v18 = *(int *)(a4 + 20);
            v19 = (const __m128i *)_AdjustPointer(v17, a4 + 8);
            sub_1800098F0(a2, v19, v18);
          }
          return v8;
        }
        v14 = *(const __m128i **)(a1 + 40);
        if ( v14 == nullptr || a2 == nullptr )
          terminate();
        sub_1800098F0(a2, v14, *(int *)(a4 + 20));
        if ( *(_DWORD *)(a4 + 20) != 8 || a2->m128i_i64[0] == 0 )
          return v8;
        v13 = a2->m128i_i64[0];
      }
      a2->m128i_i64[0] = _AdjustPointer(v13, a4 + 8);
      return v8;
    }
  }
  return 0;
}


// ===== ??$BuildCatchObjectInternal@$$CBU_s_HandlerType@@@@YAXPEAUEHExceptionRecord@@PEAXPEBU_s_HandlerType@@PEBU_s_CatchableType@@@Z @ 0x18000a770 size=0xc0 =====
__int64 __fastcall BuildCatchObjectInternal<_s_HandlerType const>(__int64 a1, __m128i *a2, int *a3, __int64 a4)
{
  __int64 v6; // rbx
  __m128i *v7; // rsi
  __int64 result; // rax
  __int64 v9; // rax
  __int64 v10; // rax

  v6 = 0;
  if ( *a3 >= 0 )
    v7 = (__m128i *)(a2->m128i_i64[0] + a3[2]);
  else
    v7 = a2;
  result = (unsigned int)BuildCatchObjectHelperInternal<_s_HandlerType const>(a1, a2, a3, a4) - 1;
  if ( (_DWORD)result != 0 )
  {
    if ( (_DWORD)result == 1 )
    {
      if ( *(_DWORD *)(a4 + 24) != 0 )
        v6 = *(int *)(a4 + 24) + GetThrowImageBase();
      v9 = _AdjustPointer(*(_QWORD *)(a1 + 40), a4 + 8);
      return unknown_libname_26(v7, v6, v9, 1);
    }
  }
  else
  {
    if ( *(_DWORD *)(a4 + 24) != 0 )
      v6 = *(int *)(a4 + 24) + GetThrowImageBase();
    v10 = _AdjustPointer(*(_QWORD *)(a1 + 40), a4 + 8);
    return unknown_libname_25(v7, v6, v10);
  }
  return result;
}


// ===== ??$CatchIt@V__FrameHandler3@@@@YAXPEAUEHExceptionRecord@@PEA_KPEAU_CONTEXT@@PEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@PEBU_s_HandlerType@@PEBU_s_CatchableType@@PEBU_s_TryBlockMapEntry@@H1EE@Z @ 0x18000a830 size=0xcd =====
void __fastcall CatchIt<__FrameHandler3>(
        struct EHExceptionRecord *a1,
        unsigned __int64 *a2,
        struct _CONTEXT *a3,
        struct _xDISPATCHER_CONTEXT *a4,
        struct _s_FuncInfo *a5,
        struct _s_HandlerType *a6,
        __int64 a7,
        int *a8,
        int a9,
        int a10,
        int a11,
        char a12)
{
  const struct _s_FuncInfo *v12; // r15
  __m128i *EstablisherFrame; // rax
  unsigned __int64 *v18; // rsi
  struct _s_HandlerType *v19; // rbx
  __int64 ImageBase; // rax
  unsigned __int64 v21; // [rsp+98h] [rbp+10h] BYREF

  v12 = a5;
  EstablisherFrame = (__m128i *)_GetEstablisherFrame(a2, a4, a5, &v21);
  v18 = (unsigned __int64 *)EstablisherFrame;
  v19 = a6;
  if ( a7 != 0 )
    BuildCatchObjectInternal<_s_HandlerType const>((__int64)a1, EstablisherFrame, (int *)a6, a7);
  ImageBase = GetImageBase();
  __FrameHandler3::UnwindNestedFrames(
    (void **)a2,
    a1,
    a3,
    v18,
    (void *)(v19->dispOfHandler + ImageBase),
    v12,
    *a8,
    a8[2],
    v19,
    a4,
    a12);
}


// ===== ??$FindHandler@V__FrameHandler3@@@@YAXPEAUEHExceptionRecord@@PEA_KPEAU_CONTEXT@@PEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@EH1@Z @ 0x18000a900 size=0x461 =====
__int64 __fastcall FindHandler<__FrameHandler3>(
        struct EHExceptionRecord *a1,
        unsigned __int64 *a2,
        struct _CONTEXT *a3,
        struct _xDISPATCHER_CONTEXT *a4,
        struct _s_FuncInfo *a5,
        char a6,
        int a7,
        __int64 a8)
{
  unsigned __int64 *v8; // r12
  char v10; // r13
  __ehstate_t HandlerSearchState; // eax
  __int64 dispESTypeList; // rcx
  int v14; // r15d
  __int64 result; // rax
  __int64 v16; // rcx
  __int64 v17; // rcx
  __int64 v18; // rcx
  const struct _s_ESTypeList *v19; // r14
  __int64 v20; // rcx
  __int64 v21; // rdx
  __int64 v22; // r8
  unsigned int v23; // r12d
  int *v24; // r14
  int v25; // eax
  __int64 v26; // r13
  __int64 v27; // rdx
  __int64 ThrowImageBase; // rax
  ThrowInfo *pThrowInfo; // r8
  __int64 ImageBase; // rax
  __int64 v31; // rax
  const struct _s_ESTypeList *v32; // rdx
  unsigned __int64 *EstablisherFrame; // rax
  int v34; // [rsp+58h] [rbp-89h]
  char v35; // [rsp+68h] [rbp-79h]
  char v36; // [rsp+69h] [rbp-78h]
  int v37; // [rsp+6Ch] [rbp-75h]
  int v38; // [rsp+70h] [rbp-71h]
  int *v39; // [rsp+78h] [rbp-69h]
  struct _s_HandlerType *v40; // [rsp+80h] [rbp-61h]
  __int64 v41; // [rsp+88h] [rbp-59h]
  unsigned __int64 v42; // [rsp+90h] [rbp-51h] BYREF
  __int64 v43; // [rsp+98h] [rbp-49h]
  _QWORD pExceptionObject[2]; // [rsp+A0h] [rbp-41h] BYREF
  _QWORD v45[2]; // [rsp+B8h] [rbp-29h] BYREF
  __int128 v46; // [rsp+C8h] [rbp-19h] BYREF
  unsigned int v47; // [rsp+E0h] [rbp-1h]

  v8 = a2;
  v36 = 0;
  v10 = 0;
  v35 = 0;
  HandlerSearchState = __FrameHandler3::GetHandlerSearchState(a2, a4, a5);
  v14 = HandlerSearchState;
  if ( HandlerSearchState < -1 || HandlerSearchState >= a5->maxState )
    goto LABEL_55;
  if ( a1->ExceptionCode != -529697949
    || a1->NumberParameters != 4
    || a1->params.magicNumber - 429065504 > 2
    || a1->params.pThrowInfo != nullptr )
  {
    goto LABEL_16;
  }
  result = _vcrt_getptd(dispESTypeList);
  if ( *(_QWORD *)(result + 32) == 0 )
    return result;
  a1 = *(struct EHExceptionRecord **)(_vcrt_getptd(v16) + 32);
  v36 = 1;
  a3 = *(struct _CONTEXT **)(_vcrt_getptd(v17) + 40);
  SetThrowImageBase((__int64)a1->params.pThrowImageBase);
  if ( a1->ExceptionCode == -529697949
    && a1->NumberParameters == 4
    && a1->params.magicNumber - 429065504 <= 2
    && a1->params.pThrowInfo == nullptr )
  {
LABEL_55:
    terminate();
  }
  if ( *(_QWORD *)(_vcrt_getptd(v18) + 56) != 0 )
  {
    v19 = *(const struct _s_ESTypeList **)(_vcrt_getptd(dispESTypeList) + 56);
    *(_QWORD *)(_vcrt_getptd(v20) + 56) = 0;
    if ( IsInExceptionSpec(a1, v19) == 0 )
    {
      if ( Is_bad_exception_allowed(v19) != 0 )
      {
        LOBYTE(v21) = 1;
        _DestructExceptionObject(a1, v21);
        sub_18000B360(pExceptionObject);
        throw (std::bad_exception *)pExceptionObject;
      }
      goto LABEL_55;
    }
  }
LABEL_16:
  v45[0] = a5;
  v45[1] = a4;
  if ( a1->ExceptionCode == -529697949 && a1->NumberParameters == 4 && a1->params.magicNumber - 429065504 <= 2 )
  {
    if ( a5->nTryBlocks != 0 )
    {
      __FrameHandler3::GetRangeOfTrysToCheck(&v46, v45, v14);
      *(_OWORD *)pExceptionObject = v46;
      if ( DWORD2(v46) < v47 )
      {
        v22 = v46;
        v23 = pExceptionObject[1];
        v41 = v46;
        do
        {
          dispESTypeList = *(int *)(*(_QWORD *)pExceptionObject[0] + 16LL);
          v24 = (int *)(*(_QWORD *)(*(_QWORD *)(v22 + 8) + 8LL) + dispESTypeList + 20LL * v23);
          if ( *v24 <= v14 && v14 <= v24[1] )
          {
            v25 = v24[3];
            v26 = 0;
            v27 = a4->ImageBase + v24[4];
            v43 = v27;
            v38 = v25;
            if ( v25 != 0 )
            {
              while ( 1 )
              {
                v40 = (struct _s_HandlerType *)(v27 + 20 * v26);
                v39 = (int *)(a1->params.pThrowInfo->pCatchableTypeArray + GetThrowImageBase() + 4);
                dispESTypeList = *(unsigned int *)(GetThrowImageBase() + a1->params.pThrowInfo->pCatchableTypeArray);
                v37 = dispESTypeList;
                if ( (int)dispESTypeList > 0 )
                  break;
LABEL_28:
                v26 = (unsigned int)(v26 + 1);
                if ( (_DWORD)v26 == v38 )
                {
                  v22 = v41;
                  goto LABEL_32;
                }
                v27 = v43;
              }
              while ( 1 )
              {
                ThrowImageBase = GetThrowImageBase();
                pThrowInfo = a1->params.pThrowInfo;
                v42 = *v39 + ThrowImageBase;
                if ( (unsigned int)TypeMatchHelper<__FrameHandler3>(v40, v42, pThrowInfo) != 0 )
                  break;
                ++v39;
                if ( --v37 <= 0 )
                  goto LABEL_28;
              }
              v10 = 1;
              LOBYTE(v34) = v36;
              v35 = 1;
              CatchIt<__FrameHandler3>(a1, a2, a3, a4, a5, v40, v42, v24, a7, a8, v34, a6);
              v22 = v41;
            }
            else
            {
LABEL_32:
              v10 = v35;
            }
          }
          ++v23;
        }
        while ( v23 < v47 );
        if ( v10 != 0 )
          goto LABEL_52;
        v8 = a2;
      }
    }
    if ( (*(_DWORD *)a5 & 0x1FFFFFFFu) >= 0x19930521 )
    {
      if ( a5->dispESTypeList != 0 )
      {
        ImageBase = GetImageBase();
        dispESTypeList = a5->dispESTypeList;
        v31 = dispESTypeList + ImageBase;
      }
      else
      {
        v31 = 0;
      }
      if ( v31 != 0 || (a5->EHFlags & 4) != 0 && !__FrameHandler3::ExecutionInCatch(a4, a5) )
      {
        if ( (a5->EHFlags & 4) != 0 )
          goto LABEL_55;
        if ( a5->dispESTypeList != 0 )
          v32 = (const struct _s_ESTypeList *)(a5->dispESTypeList + GetImageBase());
        else
          v32 = nullptr;
        if ( IsInExceptionSpec(a1, v32) == 0 )
        {
          EstablisherFrame = _GetEstablisherFrame(v8, a4, a5, &v42);
          __FrameHandler3::UnwindNestedFrames(
            (void **)v8,
            a1,
            a3,
            EstablisherFrame,
            nullptr,
            a5,
            -1,
            -1,
            nullptr,
            a4,
            a6);
        }
      }
    }
  }
  else if ( a5->nTryBlocks != 0 )
  {
    if ( a6 != 0 )
      goto LABEL_55;
    FindHandlerForForeignException<__FrameHandler3>(a1, a5, v14, a7, a8);
  }
LABEL_52:
  result = _vcrt_getptd(dispESTypeList);
  if ( *(_QWORD *)(result + 56) != 0 )
    goto LABEL_55;
  return result;
}


// ===== ??$FindHandlerForForeignException@V__FrameHandler3@@@@YAXPEAUEHExceptionRecord@@PEA_KPEAU_CONTEXT@@PEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@HH1@Z @ 0x18000ad64 size=0x22e =====
void __fastcall FindHandlerForForeignException<__FrameHandler3>(
        struct EHExceptionRecord *a1,
        unsigned __int64 *a2,
        struct _CONTEXT *a3,
        struct _xDISPATCHER_CONTEXT *a4,
        struct _s_FuncInfo *a5,
        int a6,
        int a7,
        __int64 a8)
{
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 v14; // r8
  PVOID v15; // rbx
  __int64 v16; // rcx
  int v17; // r14d
  __int64 v18; // r8
  unsigned int v19; // ebp
  int *v20; // rbx
  struct _s_HandlerType *v21; // r14
  __int64 dispType; // r12
  __int64 v23; // rax
  __int64 v24; // rax
  int v25; // [rsp+50h] [rbp-88h]
  _QWORD v26[2]; // [rsp+60h] [rbp-78h] BYREF
  __int128 v27; // [rsp+70h] [rbp-68h]
  __int128 v28; // [rsp+80h] [rbp-58h] BYREF
  unsigned int v29; // [rsp+98h] [rbp-40h]
  __int64 v30; // [rsp+E0h] [rbp+8h]

  if ( a1->ExceptionCode != -2147483645 )
  {
    if ( *(_QWORD *)(_vcrt_getptd((__int64)a1) + 16) == 0
      || (v15 = EncodePointer(nullptr), *(PVOID *)(_vcrt_getptd(v16) + 16) == v15)
      || a1->ExceptionCode == -532459699
      || a1->ExceptionCode == -532462766
      || (unsigned int)unknown_libname_22(&a1->ExceptionCode, (__int64)a2, (__int64)a3) == 0 )
    {
      v26[0] = a5;
      v26[1] = a4;
      if ( a5->nTryBlocks == 0 )
        terminate(v13, v12, v14);
      v17 = a6;
      __FrameHandler3::GetRangeOfTrysToCheck(&v28, v26, a6);
      v27 = v28;
      if ( DWORD2(v28) < v29 )
      {
        v18 = v28;
        v19 = DWORD2(v27);
        v30 = v28;
        do
        {
          v20 = (int *)(*(_QWORD *)(*(_QWORD *)(v18 + 8) + 8LL) + *(int *)(*(_QWORD *)v27 + 16LL) + 20LL * v19);
          if ( *v20 <= v17 && v17 <= v20[1] )
          {
            v21 = (struct _s_HandlerType *)(v20[4] + 20LL * (unsigned int)v20[3] + a4->ImageBase - 20);
            if ( v21->dispType != 0 )
            {
              dispType = v21->dispType;
              v23 = dispType + GetImageBase();
            }
            else
            {
              v23 = 0;
              LODWORD(dispType) = 0;
            }
            if ( v23 == 0
              || ((_DWORD)dispType == 0 ? (v24 = 0) : (v24 = v21->dispType + GetImageBase()), *(_BYTE *)(v24 + 16) == 0) )
            {
              if ( (v21->adjectives & 0x40) == 0 )
              {
                LOBYTE(v25) = 1;
                CatchIt<__FrameHandler3>(a1, a2, a3, a4, a5, v21, 0, v20, a7, a8, v25, 0);
              }
            }
            v17 = a6;
            v18 = v30;
          }
          ++v19;
        }
        while ( v19 < v29 );
      }
    }
  }
}


// ===== ??$TypeMatchHelper@V__FrameHandler3@@@@YAHPEBU_s_HandlerType@@PEBU_s_CatchableType@@PEBU_s_ThrowInfo@@@Z @ 0x18000af94 size=0x141 =====
__int64 __fastcall TypeMatchHelper<__FrameHandler3>(__int64 a1, __int64 a2, _BYTE *a3)
{
  unsigned int v3; // ebx
  __int64 v7; // rsi
  __int64 v8; // rcx
  __int64 v9; // rsi
  __int64 v10; // rcx
  __int64 v11; // rsi
  __int64 v12; // rsi
  __int64 v13; // r8
  unsigned __int8 *v14; // rax
  __int64 v15; // r8
  int v16; // edx
  int v17; // ecx

  v3 = 0;
  if ( *(_DWORD *)(a1 + 4) != 0 )
  {
    v7 = *(int *)(a1 + 4);
    v8 = v7 + GetImageBase();
  }
  else
  {
    v8 = 0;
    LODWORD(v7) = 0;
  }
  if ( v8 == 0 )
    return 1;
  if ( (_DWORD)v7 != 0 )
  {
    v9 = *(int *)(a1 + 4);
    v10 = v9 + GetImageBase();
  }
  else
  {
    v10 = 0;
    LODWORD(v9) = 0;
  }
  if ( *(_BYTE *)(v10 + 16) == 0 || *(char *)a1 < 0 && (*(_BYTE *)a2 & 0x10) != 0 )
    return 1;
  if ( (_DWORD)v9 != 0 )
    v11 = *(int *)(a1 + 4) + GetImageBase();
  else
    v11 = 0;
  if ( v11 != *(int *)(a2 + 4) + GetThrowImageBase() )
  {
    v12 = *(_DWORD *)(a1 + 4) != 0 ? *(int *)(a1 + 4) + GetImageBase() : 0LL;
    v13 = GetThrowImageBase() + *(int *)(a2 + 4) + 16LL;
    v14 = (unsigned __int8 *)(v12 + 16);
    v15 = v13 - (v12 + 16);
    do
    {
      v16 = v14[v15];
      v17 = *v14 - v16;
      if ( v17 != 0 )
        break;
      ++v14;
    }
    while ( v16 != 0 );
    if ( v17 != 0 )
      return 0;
  }
  if ( ((*(_BYTE *)a2 & 2) == 0 || (*(_BYTE *)a1 & 8) != 0)
    && ((*a3 & 1) == 0 || (*(_BYTE *)a1 & 1) != 0)
    && ((*a3 & 4) == 0 || (*(_BYTE *)a1 & 4) != 0)
    && ((*a3 & 2) == 0 || (*(_BYTE *)a1 & 2) != 0) )
  {
    return 1;
  }
  return v3;
}


// ===== ??$__InternalCxxFrameHandler@V__FrameHandler3@@@@YA?AW4_EXCEPTION_DISPOSITION@@PEAUEHExceptionRecord@@PEA_KPEAU_CONTEXT@@PEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@H1E@Z @ 0x18000b0d8 size=0x246 =====
__int64 __fastcall __InternalCxxFrameHandler<__FrameHandler3>(
        struct EHExceptionRecord *a1,
        unsigned __int64 *a2,
        struct _CONTEXT *a3,
        struct _xDISPATCHER_CONTEXT *a4,
        struct _s_FuncInfo *a5,
        int a6,
        __int64 a7,
        unsigned __int8 a8)
{
  __int64 v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rdx
  __int64 v15; // rcx
  __int64 v16; // r8
  __ehstate_t v17; // eax
  __ehstate_t pThrowImageBase; // r9d
  unsigned __int64 *pExceptionObject; // rcx
  __int64 v20; // rax
  __int64 (__fastcall *v21)(struct EHExceptionRecord *, unsigned __int64 *, struct _CONTEXT *, struct _xDISPATCHER_CONTEXT *, struct _s_FuncInfo *, int, __int64, _DWORD); // r10

  _except_validate_context_record(a3);
  v13 = _vcrt_getptd(v12);
  v14 = 2147483689LL;
  v15 = 429065506;
  v16 = 2147483686LL;
  if ( *(_DWORD *)(v13 + 64) == 0 && a1->ExceptionCode != -529697949 )
  {
    if ( a1->ExceptionCode != -2147483607 )
      goto LABEL_6;
    if ( a1->NumberParameters == 15 )
    {
      if ( *(_QWORD *)&a1[1].params.magicNumber == 429065504 )
        goto LABEL_9;
LABEL_6:
      if ( a1->ExceptionCode == -2147483610 )
        goto LABEL_9;
    }
    if ( (*(_DWORD *)a5 & 0x1FFFFFFFu) >= 0x19930522 && (a5->EHFlags & 1) != 0 )
      return 1;
  }
LABEL_9:
  if ( (a1->ExceptionFlags & 0x66) != 0 )
  {
    if ( a5->maxState == 0 || a6 != 0 )
      return 1;
    if ( (a1->ExceptionFlags & 0x20) != 0 )
    {
      if ( a1->ExceptionCode == -2147483610 )
      {
        v17 = unknown_libname_23((__int64)a5, (__int64)a4, a4->TargetIp);
        if ( v17 >= -1 && v17 < a5->maxState )
        {
          pThrowImageBase = v17;
          pExceptionObject = a2;
LABEL_17:
          __FrameHandler3::FrameUnwindToState(pExceptionObject, a4, a5, pThrowImageBase);
          return 1;
        }
        goto LABEL_41;
      }
      if ( a1->ExceptionCode == -2147483607 )
      {
        pThrowImageBase = (__ehstate_t)a1->params.pThrowImageBase;
        if ( pThrowImageBase >= -1 && pThrowImageBase < a5->maxState )
        {
          pExceptionObject = (unsigned __int64 *)a1->params.pExceptionObject;
          goto LABEL_17;
        }
LABEL_41:
        terminate(v15, v14, v16);
      }
    }
    __FrameHandler3::FrameUnwindToEmptyState(a2, a4, a5);
    return 1;
  }
  if ( a5->nTryBlocks != 0
    || (*(_DWORD *)a5 & 0x1FFFFFFFu) >= 0x19930521
    && (a5->dispESTypeList == 0 ? (v20 = 0) : (v20 = a5->dispESTypeList + GetImageBase()), v20 != 0)
    || (*(_DWORD *)a5 & 0x1FFFFFFFu) >= 0x19930522 && (a5->EHFlags & 4) != 0 )
  {
    if ( a1->ExceptionCode == -529697949 && a1->NumberParameters >= 3 && a1->params.magicNumber > 0x19930522 )
    {
      v21 = a1->params.pThrowInfo->pForwardCompat != 0
          ? (__int64 (__fastcall *)(struct EHExceptionRecord *, unsigned __int64 *, struct _CONTEXT *, struct _xDISPATCHER_CONTEXT *, struct _s_FuncInfo *, int, __int64, _DWORD))(GetThrowImageBase() + a1->params.pThrowInfo->pForwardCompat)
          : nullptr;
      if ( v21 != nullptr )
        return v21(a1, a2, a3, a4, a5, a6, a7, a8);
    }
    FindHandler<__FrameHandler3>(a1, a2, a3, a4, a5, a8, a6, a7);
  }
  return 1;
}


// ===== sub_18000B320 @ 0x18000b320 size=0x3f =====
_QWORD *__fastcall sub_18000B320(_QWORD *a1, __int64 a2)
{
  *a1 = &std::exception::`vftable';
  a1[1] = 0;
  a1[2] = 0;
  _std_exception_copy(a2 + 8, (__int64)(a1 + 1));
  *a1 = &std::bad_exception::`vftable';
  return a1;
}


// ===== sub_18000B360 @ 0x18000b360 size=0x1e =====
_QWORD *__fastcall sub_18000B360(_QWORD *a1)
{
  a1[2] = 0;
  a1[1] = "bad exception";
  *a1 = &std::bad_exception::`vftable';
  return a1;
}


// ===== unknown_libname_24 @ 0x18000b380 size=0x1ea =====
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_24(_QWORD *a1)
{
  __int64 v2; // r13
  __int64 v3; // rcx
  __int64 v4; // rsi
  __int64 v5; // rbx
  _QWORD *v6; // r14
  __int64 v7; // rcx
  __int64 v8; // rcx
  __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rcx
  _QWORD *FrameInfo; // r12
  __int64 v13; // rbx
  __int64 v14; // rcx
  __int64 v15; // rdx
  __int64 v16; // rcx
  __int64 v18; // [rsp+30h] [rbp-78h]
  __int64 v19; // [rsp+48h] [rbp-60h]
  _QWORD v20[9]; // [rsp+60h] [rbp-48h] BYREF
  __int64 v21; // [rsp+C0h] [rbp+18h]

  v2 = *(_QWORD *)(_vcrt_getptd((__int64)a1) + 40);
  v21 = *(_QWORD *)(_vcrt_getptd(v3) + 32);
  v4 = a1[10];
  v18 = a1[9];
  v5 = a1[8];
  v19 = a1[6];
  v6 = (_QWORD *)a1[5];
  _except_validate_context_record(v5);
  *(_QWORD *)(_vcrt_getptd(v7) + 32) = v4;
  *(_QWORD *)(_vcrt_getptd(v8) + 40) = v5;
  v10 = _vcrt_getptd(v9);
  FrameInfo = CreateFrameInfo(v20, *(_QWORD *)(*(_QWORD *)(v10 + 32) + 40LL));
  if ( a1[11] != 0 )
    _vcrt_getptd(v11);
  v13 = CallSettingFrame(v19, v6, 256);
  FindAndUnlinkFrame((__int64)FrameInfo);
  if ( *(_DWORD *)v4 == -529697949
    && *(_DWORD *)(v4 + 24) == 4
    && (unsigned int)(*(_DWORD *)(v4 + 32) - 429065504) <= 2
    && (unsigned int)IsExceptionObjectToBeDestroyed(*(_QWORD *)(v4 + 40)) != 0 )
  {
    LOBYTE(v15) = 1;
    _DestructExceptionObject(v4, v15);
  }
  *(_QWORD *)(_vcrt_getptd(v14) + 32) = v21;
  *(_QWORD *)(_vcrt_getptd(v16) + 40) = v2;
  *(_QWORD *)(*(int *)(v18 + 28) + *v6) = -2;
  return v13;
}


// ===== ?ExFilterRethrow@@YAHPEAU_EXCEPTION_POINTERS@@PEAUEHExceptionRecord@@PEAH@Z @ 0x18000b56c size=0x87 =====
__int64 __fastcall ExFilterRethrow(struct _EXCEPTION_POINTERS *a1, struct EHExceptionRecord *a2, int *a3)
{
  PEXCEPTION_RECORD ExceptionRecord; // r9
  __int64 v5; // rcx

  ExceptionRecord = a1->ExceptionRecord;
  *a3 = 0;
  if ( ExceptionRecord->ExceptionCode != -529697949 )
    return 0;
  if ( ExceptionRecord->NumberParameters != 4 )
    return 0;
  if ( (unsigned int)(LODWORD(ExceptionRecord->ExceptionInformation[0]) - 429065504) <= 2
    && (void *)ExceptionRecord->ExceptionInformation[1] == a2->params.pExceptionObject )
  {
    *a3 = 1;
    if ( ExceptionRecord->ExceptionCode != -529697949 )
      return 0;
  }
  if ( ExceptionRecord->NumberParameters != 4 )
    return 0;
  v5 = (unsigned int)(LODWORD(ExceptionRecord->ExceptionInformation[0]) - 429065504);
  if ( (unsigned int)v5 > 2 || ExceptionRecord->ExceptionInformation[2] != 0 )
    return 0;
  *(_DWORD *)(_vcrt_getptd(v5) + 64) = 1;
  *a3 = 1;
  return 1;
}


// ===== ?FrameUnwindToState@__FrameHandler3@@SAXPEA_KPEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@H@Z @ 0x18000b5f4 size=0x193 =====
static void __fastcall __FrameHandler3::FrameUnwindToState(
        unsigned __int64 *a1,
        struct _xDISPATCHER_CONTEXT *a2,
        const struct _s_FuncInfo *a3,
        __ehstate_t a4)
{
  __int64 ImageBase; // r13
  __ehstate_t v9; // edi
  __int64 v10; // rcx
  __int64 v11; // rax
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 v14; // r8
  __int64 v15; // r14
  __int64 v16; // rax
  __int64 v17; // rbx
  __int64 v18; // rax
  __int64 v19; // rax
  __int64 v20; // rbx
  __int64 v21; // r9
  __int64 v22; // rdx
  __int64 v23; // rcx
  __int64 v24; // r8
  __int64 v25; // rax

  ImageBase = GetImageBase();
  v9 = sub_18000A464(a1, a2, (__int64)a3);
  v11 = _vcrt_getptd(v10);
  ++*(_DWORD *)(v11 + 48);
  while ( v9 != -1 && v9 > a4 )
  {
    if ( v9 <= -1 || v9 >= a3->maxState )
      terminate(v13, v12, v14);
    v15 = 8LL * v9;
    v9 = *(_DWORD *)(v15 + a3->dispUnwindMap + GetImageBase());
    v16 = GetImageBase();
    v13 = v15 + a3->dispUnwindMap;
    if ( *(_DWORD *)(v13 + v16 + 4) != 0 )
    {
      v17 = GetImageBase();
      v18 = GetImageBase();
      v13 = *(int *)(v15 + a3->dispUnwindMap + v17 + 4);
      v19 = v13 + v18;
    }
    else
    {
      v19 = 0;
    }
    if ( v19 != 0 )
    {
      __FrameHandler3::SetState(a1, a3, v9);
      if ( *(_DWORD *)(v15 + a3->dispUnwindMap + GetImageBase() + 4) != 0 )
      {
        v20 = GetImageBase();
        v21 = *(int *)(v15 + a3->dispUnwindMap + v20 + 4) + GetImageBase();
      }
      else
      {
        v21 = 0;
      }
      CallSettingFrame(v21, a1, 259);
      SetImageBase(ImageBase);
    }
  }
  if ( *(int *)(_vcrt_getptd(v13) + 48) > 0 )
  {
    v25 = _vcrt_getptd(v23);
    --*(_DWORD *)(v25 + 48);
  }
  if ( v9 != -1 && v9 > a4 )
    terminate(v23, v22, v24);
  __FrameHandler3::SetState(a1, a3, v9);
}


// ===== ?GetHandlerSearchState@__FrameHandler3@@SAHPEA_KPEAU_xDISPATCHER_CONTEXT@@PEBU_s_FuncInfo@@@Z @ 0x18000b788 size=0x96 =====
static __int64 __fastcall __FrameHandler3::GetHandlerSearchState(
        unsigned __int64 *a1,
        struct _xDISPATCHER_CONTEXT *a2,
        const struct _s_FuncInfo *a3)
{
  int v6; // ebx
  unsigned __int64 v8; // [rsp+48h] [rbp+20h] BYREF

  v6 = sub_18000A500((__int64)a3, a2);
  _GetEstablisherFrame(a1, a2, a3, &v8);
  if ( v6 <= (int)__GetUnwindTryBlock(a1, a2, a3) )
  {
    return (unsigned int)__GetUnwindTryBlock(a1, a2, a3);
  }
  else
  {
    __FrameHandler3::SetState(&v8, a3, v6);
    __SetUnwindTryBlock(a1, a2, a3, v6);
  }
  return (unsigned int)v6;
}


// ===== ?IsInExceptionSpec@@YAEPEAUEHExceptionRecord@@PEBU_s_ESTypeList@@@Z @ 0x18000b820 size=0xd6 =====
char __fastcall IsInExceptionSpec(struct EHExceptionRecord *a1, const struct _s_ESTypeList *a2, __int64 a3)
{
  char v5; // r14
  int i; // edi
  int *v7; // r12
  int v8; // ebp
  __int64 v9; // rbx
  __int64 ImageBase; // rax

  if ( a2 == nullptr )
    terminate(a1, 0, a3);
  v5 = 0;
  for ( i = 0; i < a2->nCount; ++i )
  {
    v7 = (int *)(GetThrowImageBase() + a1->params.pThrowInfo->pCatchableTypeArray + 4LL);
    v8 = *(_DWORD *)(GetThrowImageBase() + a1->params.pThrowInfo->pCatchableTypeArray);
    if ( v8 > 0 )
    {
      while ( 1 )
      {
        v9 = *v7 + GetThrowImageBase();
        ImageBase = GetImageBase();
        if ( (unsigned int)TypeMatchHelper<__FrameHandler3>(
                             ImageBase + 20LL * i + a2->dispTypeArray,
                             v9,
                             a1->params.pThrowInfo) != 0 )
          break;
        --v8;
        ++v7;
        if ( v8 <= 0 )
          goto LABEL_8;
      }
      v5 = 1;
    }
LABEL_8:
    ;
  }
  return v5;
}


// ===== ?Is_bad_exception_allowed@@YAEPEBU_s_ESTypeList@@@Z @ 0x18000b8f8 size=0x91 =====
unsigned __int8 __fastcall Is_bad_exception_allowed(const struct _s_ESTypeList *a1)
{
  int v1; // ebp
  __int64 i; // rsi
  __int64 ImageBase; // rbx
  __int64 v5; // rcx

  v1 = 0;
  if ( a1->nCount <= 0 )
    return 0;
  for ( i = 0; ; i += 20 )
  {
    if ( *(_DWORD *)(i + a1->dispTypeArray + GetImageBase() + 4) != 0 )
    {
      ImageBase = GetImageBase();
      v5 = *(int *)(i + a1->dispTypeArray + ImageBase + 4) + GetImageBase();
    }
    else
    {
      v5 = 0;
    }
    if ( (unsigned int)_std_type_info_compare(v5 + 8, (__int64)&qword_18002A100) == 0 )
      break;
    if ( ++v1 >= a1->nCount )
      return 0;
  }
  return 1;
}


// ===== unknown_libname_25 @ 0x18000b98c size=0x9 =====
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_25(__int64 a1, __int64 (__fastcall *a2)(__int64, __int64), __int64 a3)
{
  return a2(a1, a3);
}


// ===== unknown_libname_26 @ 0x18000b998 size=0xf =====
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_26(
        __int64 a1,
        __int64 (__fastcall *a2)(__int64, __int64, _QWORD),
        __int64 a3,
        unsigned int a4)
{
  return a2(a1, a3, a4);
}


// ===== __vcrt_initialize_locks @ 0x18000b9a8 size=0x46 =====
char _vcrt_initialize_locks()
{
  __int64 v0; // rbx

  v0 = 0;
  while ( (unsigned int)_vcrt_InitializeCriticalSectionEx((LPCRITICAL_SECTION)&unk_18002A950 + v0, 0xFA0u) != 0 )
  {
    ++dword_18002A978;
    v0 = (unsigned int)(v0 + 1);
    if ( (_DWORD)v0 != 0 )
      return 1;
  }
  _vcrt_uninitialize_locks();
  return 0;
}


// ===== __vcrt_uninitialize_locks @ 0x18000b9f0 size=0x37 =====
char _vcrt_uninitialize_locks()
{
  int v0; // ebx

  v0 = dword_18002A978;
  while ( v0 != 0 )
  {
    DeleteCriticalSection((LPCRITICAL_SECTION)&unk_18002A950 + (unsigned int)--v0);
    --dword_18002A978;
  }
  return 1;
}


// ===== ?try_get_function@@YAPEAXW4function_id@?A0x37284e77@@QEBDQEBW4module_id@2@2@Z @ 0x18000ba28 size=0x1d6 =====
FARPROC __fastcall try_get_function(unsigned int a1, const CHAR *a2, unsigned int *a3, unsigned int *a4)
{
  __int64 v4; // r15
  unsigned int *v6; // rbp
  uintptr_t v8; // r10
  __int64 v9; // rdx
  FARPROC result; // rax
  __int64 v11; // rsi
  HMODULE Library; // rbx
  const WCHAR *v13; // r14

  v4 = a1;
  v6 = a3;
  v8 = _security_cookie;
  v9 = __ROR8__(qword_18002A998[a1] ^ _security_cookie, _security_cookie & 0x3F);
  if ( v9 == -1 )
    return nullptr;
  if ( v9 != 0 )
    return (FARPROC)v9;
  if ( a3 == a4 )
  {
LABEL_21:
    Library = nullptr;
    goto LABEL_22;
  }
  while ( 1 )
  {
    v11 = *v6;
    Library = (HMODULE)qword_18002A980[v11];
    if ( Library == nullptr )
      break;
    if ( Library != (HMODULE)-1LL )
      goto LABEL_25;
LABEL_19:
    if ( ++v6 == a4 )
    {
      v8 = _security_cookie;
      goto LABEL_21;
    }
  }
  v13 = off_18001BB60[v11];
  Library = LoadLibraryExW(v13, nullptr, 0x800u);
  if ( Library == nullptr )
  {
    if ( GetLastError() != 87 || wcsncmp(v13, L"api-ms-", 7u) == 0 || wcsncmp(v13, L"ext-ms-", 7u) == 0 )
      Library = nullptr;
    else
      Library = LoadLibraryExW(v13, nullptr, 0);
  }
  if ( Library == nullptr )
  {
    _InterlockedExchange64(&qword_18002A980[v11], -1);
    goto LABEL_19;
  }
  if ( _InterlockedExchange64(&qword_18002A980[v11], (__int64)Library) != 0 )
    FreeLibrary(Library);
LABEL_25:
  v8 = _security_cookie;
LABEL_22:
  if ( Library != nullptr )
  {
    result = GetProcAddress(Library, a2);
    if ( result != nullptr )
    {
      _InterlockedExchange64(
        &qword_18002A998[v4],
        _security_cookie ^ __ROR8__(result, 64 - ((unsigned __int8)_security_cookie & 0x3Fu)));
      return result;
    }
    v8 = _security_cookie;
  }
  _InterlockedExchange64(&qword_18002A998[v4], v8 ^ __ROR8__(-1, 64 - ((unsigned __int8)v8 & 0x3Fu)));
  return nullptr;
}


// ===== __vcrt_FlsAlloc @ 0x18000bc00 size=0x45 =====
DWORD __fastcall _vcrt_FlsAlloc(__int64 a1)
{
  FARPROC function; // rax

  function = try_get_function(0, "FlsAlloc", (unsigned int *)&unk_18001BC30, (unsigned int *)"FlsAlloc");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(__int64))function)(a1);
  else
    return TlsAlloc();
}


// ===== __vcrt_FlsFree @ 0x18000bc48 size=0x46 =====
int __fastcall _vcrt_FlsFree(DWORD a1)
{
  FARPROC function; // rax

  function = try_get_function(1u, "FlsFree", (unsigned int *)&unk_18001BC48, (unsigned int *)"FlsFree");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(_QWORD))function)(a1);
  else
    return TlsFree(a1);
}


// ===== __vcrt_FlsGetValue @ 0x18000bc90 size=0x46 =====
LPVOID __fastcall _vcrt_FlsGetValue(DWORD a1)
{
  FARPROC function; // rax

  function = try_get_function(2u, "FlsGetValue", (unsigned int *)&unk_18001BC58, (unsigned int *)"FlsGetValue");
  if ( function != nullptr )
    return (LPVOID)((__int64 (__fastcall *)(_QWORD))function)(a1);
  else
    return TlsGetValue(a1);
}


// ===== __vcrt_FlsSetValue @ 0x18000bcd8 size=0x51 =====
int __fastcall _vcrt_FlsSetValue(DWORD dwTlsIndex, LPVOID lpTlsValue)
{
  FARPROC function; // rax

  function = try_get_function(3u, "FlsSetValue", (unsigned int *)&unk_18001BC70, (unsigned int *)"FlsSetValue");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(_QWORD, LPVOID))function)(dwTlsIndex, lpTlsValue);
  else
    return TlsSetValue(dwTlsIndex, lpTlsValue);
}


// ===== __vcrt_InitializeCriticalSectionEx @ 0x18000bd2c size=0x61 =====
int __fastcall _vcrt_InitializeCriticalSectionEx(
        LPCRITICAL_SECTION lpCriticalSection,
        DWORD dwSpinCount,
        unsigned int a3)
{
  FARPROC function; // rax

  function = try_get_function(
               4u,
               "InitializeCriticalSectionEx",
               (unsigned int *)&unk_18001BC88,
               (unsigned int *)"InitializeCriticalSectionEx");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(LPCRITICAL_SECTION, _QWORD, _QWORD))function)(lpCriticalSection, dwSpinCount, a3);
  else
    return InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
}


// ===== __vcrt_initialize_winapi_thunks @ 0x18000bd90 size=0x2f =====
uintptr_t _vcrt_initialize_winapi_thunks()
{
  uintptr_t result; // rax

  result = _security_cookie;
  memset64(qword_18002A998, _security_cookie, &qword_18002A9C0 >= (__int64 (**)(void))qword_18002A998 ? 5 : 0);
  return result;
}


// ===== __vcrt_uninitialize_winapi_thunks @ 0x18000bdc0 size=0x3e =====
__int64 *__fastcall _vcrt_uninitialize_winapi_thunks(char a1)
{
  __int64 *v1; // rbx
  HMODULE v2; // rcx
  __int64 *result; // rax

  if ( a1 == 0 )
  {
    v1 = qword_18002A980;
    do
    {
      v2 = (HMODULE)*v1;
      if ( *v1 != 0 )
      {
        if ( v2 != (HMODULE)-1LL )
          FreeLibrary(v2);
        *v1 = 0;
      }
      ++v1;
      result = qword_18002A998;
    }
    while ( v1 != qword_18002A998 );
  }
  return result;
}


// ===== _NLG_Notify @ 0x18000be10 size=0x21 =====
void NLG_Notify()
{
  ;
}


// ===== nullsub_1 @ 0x18000be40 size=0x1 =====
void nullsub_1()
{
  ;
}


// ===== __except_validate_context_record @ 0x18000be44 size=0x37 =====
void (*_except_validate_context_record())()
{
  return guard_check_icall_nop;
}


// ===== __DestructExceptionObject @ 0x18000be7c size=0x71 =====
void __fastcall _DestructExceptionObject(__int64 a1)
{
  __int64 v1; // rax
  __int64 v2; // rdx
  __int64 v3; // rcx

  if ( a1 != 0
    && *(_DWORD *)a1 == -529697949
    && *(_DWORD *)(a1 + 24) == 4
    && (unsigned int)(*(_DWORD *)(a1 + 32) - 429065504) <= 2 )
  {
    v1 = *(_QWORD *)(a1 + 48);
    if ( v1 != 0 )
    {
      v2 = *(int *)(v1 + 4);
      if ( (_DWORD)v2 != 0 )
      {
        ((void (__fastcall *)(_QWORD))(*(_QWORD *)(a1 + 56) + v2))(*(_QWORD *)(a1 + 40));
      }
      else if ( (*(_BYTE *)v1 & 0x10) != 0 )
      {
        v3 = **(_QWORD **)(a1 + 40);
        if ( v3 != 0 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 16LL))(v3);
      }
    }
  }
}


// ===== ?_CallMemberFunction0@@YAXQEAX0@Z @ 0x18000bef0 size=0x3 =====
void __fastcall _CallMemberFunction0(void *const a1, void (__fastcall *a2)(void *const))
{
  a2(a1);
}


// ===== _IsExceptionObjectToBeDestroyed @ 0x18000bef4 size=0x2f =====
__int64 __fastcall IsExceptionObjectToBeDestroyed(__int64 a1)
{
  _QWORD *i; // rdx

  for ( i = *(_QWORD **)(_vcrt_getptd(a1) + 88); ; i = (_QWORD *)i[1] )
  {
    if ( i == nullptr )
      return 1;
    if ( *i == a1 )
      break;
  }
  return 0;
}


// ===== __AdjustPointer @ 0x18000bf24 size=0x23 =====
__int64 __fastcall _AdjustPointer(__int64 a1, int *a2)
{
  __int64 result; // rax

  result = a1 + *a2;
  if ( a2[1] >= 0 )
    result += a2[1] + (__int64)*(int *)(a2[2] + *(_QWORD *)(a2[1] + a1));
  return result;
}


// ===== __FrameUnwindFilter @ 0x18000bf48 size=0x4a =====
__int64 __fastcall _FrameUnwindFilter(_QWORD *a1)
{
  _DWORD *v1; // rax
  __int64 v2; // rcx
  __int64 v3; // rax
  __int64 v5; // rdx
  __int64 v6; // rcx
  __int64 v7; // r8

  v1 = (_DWORD *)*a1;
  if ( *(_DWORD *)*a1 == -532462766 || *v1 == -532459699 )
  {
    if ( *(int *)(_vcrt_getptd((__int64)a1) + 48) > 0 )
    {
      v3 = _vcrt_getptd(v2);
      --*(_DWORD *)(v3 + 48);
    }
  }
  else if ( *v1 == -529697949 )
  {
    *(_DWORD *)(_vcrt_getptd((__int64)a1) + 48) = 0;
    terminate(v6, v5, v7);
  }
  return 0;
}


// ===== _CallSettingFrame @ 0x18000bfb0 size=0x40 =====
void CallSettingFrame()
{
  void (*v0)(void); // rax

  NLG_Notify();
  v0();
  nullsub_1();
  NLG_Notify();
}


// ===== _CallSettingFrameEncoded @ 0x18000c000 size=0x47 =====
void __fastcall CallSettingFrameEncoded(__int64 a1, __int64 a2, __int64 a3)
{
  void (__fastcall *v3)(__int64); // rax

  NLG_Notify();
  v3(a3);
  nullsub_1();
  NLG_Notify();
}


// ===== __acrt_call_reportfault @ 0x18000c048 size=0x15b =====
void __fastcall _acrt_call_reportfault(int a1, unsigned int a2, unsigned int a3)
{
  ULONG64 Rip; // r14
  struct _IMAGE_RUNTIME_FUNCTION_ENTRY *v7; // rax
  BOOL v8; // edi
  unsigned __int64 ImageBase; // [rsp+40h] [rbp-C0h] BYREF
  struct _EXCEPTION_POINTERS ExceptionInfo; // [rsp+48h] [rbp-B8h] BYREF
  PVOID HandlerData; // [rsp+58h] [rbp-A8h] BYREF
  unsigned __int64 EstablisherFrame; // [rsp+60h] [rbp-A0h] BYREF
  __m128i v13; // [rsp+70h] [rbp-90h] BYREF
  DWORD64 v14; // [rsp+80h] [rbp-80h]
  struct _CONTEXT ContextRecord; // [rsp+110h] [rbp+10h] BYREF
  DWORD64 retaddr; // [rsp+608h] [rbp+508h]
  __int64 v17; // [rsp+610h] [rbp+510h] BYREF

  if ( a1 != -1 )
    sub_180008528();
  sub_180009D50(&v13, 0, 0x98u);
  sub_180009D50((__m128i *)&ContextRecord, 0, 0x4D0u);
  ExceptionInfo.ExceptionRecord = (PEXCEPTION_RECORD)&v13;
  ExceptionInfo.ContextRecord = &ContextRecord;
  RtlCaptureContext(&ContextRecord);
  Rip = ContextRecord.Rip;
  v7 = RtlLookupFunctionEntry(ContextRecord.Rip, &ImageBase, nullptr);
  if ( v7 != nullptr )
    RtlVirtualUnwind(0, ImageBase, Rip, v7, &ContextRecord, &HandlerData, &EstablisherFrame, nullptr);
  ContextRecord.Rip = retaddr;
  v13.m128i_i64[0] = __PAIR64__(a3, a2);
  ContextRecord.Rsp = (DWORD64)&v17;
  v14 = retaddr;
  v8 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(nullptr);
  if ( UnhandledExceptionFilter(&ExceptionInfo) == 0 && !v8 && a1 != -1 )
    sub_180008528();
}


// ===== sub_18000C1A4 @ 0x18000c1a4 size=0x8 =====
void __fastcall sub_18000C1A4(__int64 a1)
{
  qword_18002AA30 = a1;
}


// ===== _invalid_parameter @ 0x18000c1ac size=0xa7 =====
__int64 __fastcall invalid_parameter(
        wchar_t *Expression,
        wchar_t *FunctionName,
        wchar_t *FileName,
        unsigned int LineNo,
        uintptr_t Reserved)
{
  __int64 v9; // rax
  __int64 (__fastcall *v10)(wchar_t *, wchar_t *, wchar_t *, _QWORD); // rbx

  v9 = _acrt_getptd_noexit();
  if ( v9 == 0 || (v10 = *(__int64 (__fastcall **)(wchar_t *, wchar_t *, wchar_t *, _QWORD))(v9 + 952)) == nullptr )
  {
    v10 = (__int64 (__fastcall *)(wchar_t *, wchar_t *, wchar_t *, _QWORD))__ROR8__(
                                                                             qword_18002AA30 ^ _security_cookie,
                                                                             _security_cookie & 0x3F);
    if ( v10 == nullptr )
      invoke_watson(Expression, FunctionName, FileName, LineNo, Reserved);
  }
  return v10(Expression, FunctionName, FileName, LineNo);
}


// ===== _invalid_parameter_noinfo @ 0x18000c254 size=0x1e =====
void __cdecl invalid_parameter_noinfo()
{
  invalid_parameter(nullptr, nullptr, nullptr, 0, 0);
}


// ===== _invalid_parameter_noinfo_noreturn @ 0x18000c274 size=0x2f =====
void __cdecl __noreturn invalid_parameter_noinfo_noreturn()
{
  invalid_parameter(nullptr, nullptr, nullptr, 0, 0);
  invoke_watson(nullptr, nullptr, nullptr, 0, 0);
}


// ===== _invoke_watson @ 0x18000c2a4 size=0x46 =====
void __cdecl __noreturn invoke_watson(
        const wchar_t *Expression,
        const wchar_t *FunctionName,
        const wchar_t *FileName,
        unsigned int LineNo,
        uintptr_t Reserved)
{
  HANDLE CurrentProcess; // rax

  if ( IsProcessorFeaturePresent(0x17u) )
    __fastfail(5u);
  _acrt_call_reportfault(2, 0xC0000417, 1u);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(CurrentProcess, 0xC0000417);
}


// ===== __acrt_errno_from_os_error @ 0x18000c2ec size=0x45 =====
__int64 __fastcall _acrt_errno_from_os_error(int a1)
{
  __int64 v1; // rax
  unsigned int *v2; // rdx
  __int64 result; // rax

  v1 = 0;
  v2 = dword_18001C690;
  do
  {
    if ( a1 == *v2 )
      return dword_18001C690[2 * v1 + 1];
    v1 = (unsigned int)(v1 + 1);
    v2 += 2;
  }
  while ( (unsigned int)v1 < 0x2D );
  if ( (unsigned int)(a1 - 19) <= 0x11 )
    return 13;
  result = 22;
  if ( (unsigned int)(a1 - 188) <= 0xE )
    return 8;
  return result;
}


// ===== __acrt_errno_map_os_error @ 0x18000c334 size=0x4e =====
__int64 __fastcall _acrt_errno_map_os_error(int a1)
{
  __int64 v2; // rax
  int *v3; // rax
  __int64 v4; // rax
  _DWORD *v5; // rbx
  __int64 result; // rax

  v2 = _acrt_getptd_noexit();
  if ( v2 != 0 )
    v3 = (int *)(v2 + 36);
  else
    v3 = (int *)&unk_1800292A4;
  *v3 = a1;
  v4 = _acrt_getptd_noexit();
  v5 = &unk_1800292A0;
  if ( v4 != 0 )
    v5 = (_DWORD *)(v4 + 32);
  result = _acrt_errno_from_os_error(a1);
  *v5 = result;
  return result;
}


// ===== __doserrno @ 0x18000c384 size=0x20 =====
unsigned int *__cdecl _doserrno()
{
  __int64 v0; // rax

  v0 = _acrt_getptd_noexit();
  if ( v0 != 0 )
    return (unsigned int *)(v0 + 36);
  else
    return (unsigned int *)&unk_1800292A4;
}


// ===== _errno @ 0x18000c3a4 size=0x20 =====
int *__cdecl errno()
{
  __int64 v0; // rax

  v0 = _acrt_getptd_noexit();
  if ( v0 != 0 )
    return (int *)(v0 + 32);
  else
    return (int *)&unk_1800292A0;
}


// ===== j__free_base @ 0x18000c3c4 size=0x5 =====
// attributes: thunk
void __cdecl j__free_base(void *Block)
{
  free_base(Block);
}


// ===== j__malloc_base @ 0x18000c3cc size=0x5 =====
// attributes: thunk
void *__cdecl j__malloc_base(size_t Size)
{
  return malloc_base(Size);
}


// ===== j__recalloc_base @ 0x18000c3d4 size=0x5 =====
// attributes: thunk
void *__cdecl j__recalloc_base(void *Block, size_t Count, size_t Size)
{
  return recalloc_base(Block, Count, Size);
}


// ===== _recalloc_base @ 0x18000c3dc size=0x95 =====
void *__cdecl recalloc_base(void *Block, size_t Count, size_t Size)
{
  size_t v7; // rdi
  size_t v8; // rbx
  char *v9; // rax
  void *v10; // rsi

  if ( Count != 0 && 0xFFFFFFFFFFFFFFE0uLL / Count < Size )
  {
    *errno() = 12;
    return nullptr;
  }
  else
  {
    if ( Block != nullptr )
      v7 = msize(Block);
    else
      v7 = 0;
    v8 = Size * Count;
    v9 = (char *)realloc_base(Block, v8);
    v10 = v9;
    if ( v9 != nullptr && v7 < v8 )
      sub_180009D50((__m128i *)&v9[v7], 0, v8 - v7);
    return v10;
  }
}


// ===== wcscat_s @ 0x18000c474 size=0x7f =====
errno_t __cdecl wcscat_s(wchar_t *Destination, rsize_t SizeInWords, const wchar_t *Source)
{
  errno_t v3; // ebx
  wchar_t *v4; // r9
  int *v5; // rax
  signed __int64 v7; // r8
  wchar_t v8; // ax

  v3 = 0;
  v4 = Destination;
  if ( Destination == nullptr || SizeInWords == 0 )
    goto LABEL_5;
  if ( Source == nullptr )
  {
    *Destination = 0;
LABEL_5:
    v5 = errno();
    v3 = 22;
LABEL_6:
    *v5 = v3;
    invalid_parameter_noinfo();
    return v3;
  }
  do
  {
    if ( *Destination == 0 )
      break;
    ++Destination;
    --SizeInWords;
  }
  while ( SizeInWords != 0 );
  if ( SizeInWords == 0 )
  {
    *v4 = 0;
    goto LABEL_5;
  }
  v7 = (char *)Source - (char *)Destination;
  do
  {
    v8 = *(wchar_t *)((char *)Destination + v7);
    *Destination++ = v8;
    if ( v8 == 0 )
      break;
    --SizeInWords;
  }
  while ( SizeInWords != 0 );
  if ( SizeInWords == 0 )
  {
    *v4 = 0;
    v5 = errno();
    v3 = 34;
    goto LABEL_6;
  }
  return v3;
}


// ===== wcsncpy_s @ 0x18000c4f4 size=0xe3 =====
errno_t __cdecl wcsncpy_s(wchar_t *Destination, rsize_t SizeInWords, const wchar_t *Source, rsize_t MaxCount)
{
  errno_t v4; // r10d
  int *v6; // rax
  errno_t v7; // ebx
  signed __int64 v9; // r8
  wchar_t *v10; // rdx
  rsize_t v11; // rbx
  rsize_t v12; // rdi
  wchar_t v13; // ax
  wchar_t v14; // ax

  v4 = 0;
  if ( MaxCount != 0 )
  {
    if ( Destination == nullptr )
      goto LABEL_4;
  }
  else if ( Destination == nullptr )
  {
    if ( SizeInWords != 0 )
    {
LABEL_4:
      v6 = errno();
      v7 = 22;
LABEL_5:
      *v6 = v7;
      invalid_parameter_noinfo();
      return v7;
    }
    return v4;
  }
  if ( SizeInWords == 0 )
    goto LABEL_4;
  if ( MaxCount == 0 )
  {
    *Destination = 0;
    return v4;
  }
  if ( Source == nullptr )
  {
    *Destination = 0;
    goto LABEL_4;
  }
  v9 = (char *)Source - (char *)Destination;
  v10 = Destination;
  v11 = SizeInWords;
  v12 = MaxCount;
  if ( MaxCount == -1 )
  {
    do
    {
      v13 = *(wchar_t *)((char *)v10 + v9);
      *v10++ = v13;
      if ( v13 == 0 )
        break;
      --v11;
    }
    while ( v11 != 0 );
  }
  else
  {
    do
    {
      v14 = *(wchar_t *)((char *)v10 + v9);
      *v10++ = v14;
      if ( v14 == 0 )
        break;
      if ( --v11 == 0 )
        break;
      --v12;
    }
    while ( v12 != 0 );
    if ( v12 == 0 )
      *v10 = 0;
  }
  if ( v11 == 0 )
  {
    if ( MaxCount == -1 )
    {
      Destination[SizeInWords - 1] = 0;
      return 80;
    }
    *Destination = 0;
    v6 = errno();
    v7 = 34;
    goto LABEL_5;
  }
  return v4;
}


// ===== sub_18000C5D8 @ 0x18000c5d8 size=0x1b4 =====
__int64 __fastcall sub_18000C5D8(
        int a1,
        _WORD *a2,
        unsigned __int64 a3,
        __int64 a4,
        struct __crt_locale_pointers *a5,
        __int64 a6)
{
  int v6; // ebx
  int v11; // eax
  unsigned __int64 v12; // rbx
  __int64 v13; // rax
  __m128i v14; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v15; // [rsp+40h] [rbp-C0h]
  char v16; // [rsp+48h] [rbp-B8h]
  __m128i *v17; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v18; // [rsp+58h] [rbp-A8h] BYREF
  _BYTE v19[32]; // [rsp+60h] [rbp-A0h] BYREF
  _BYTE v20[1120]; // [rsp+80h] [rbp-80h] BYREF
  void *Block; // [rsp+4E0h] [rbp+3E0h]

  v6 = a4;
  if ( a4 == 0 || a3 != 0 && a2 == nullptr )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFLL;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v18, a5);
  sub_180009D50(&v14, 0, 0x20u);
  v14.m128i_i64[0] = (__int64)a2;
  v14.m128i_i64[1] = a3;
  v15 = 0;
  if ( (a1 & 2) != 0 || (v16 = 0, a2 == nullptr) )
    v16 = 1;
  v17 = &v14;
  unknown_libname_46((unsigned int)v20, (unsigned int)&v17, a1, v6, (__int64)v19, a6);
  v11 = __crt_stdio_output::output_processor<wchar_t,__crt_stdio_output::string_output_adapter<wchar_t>,__crt_stdio_output::format_validation_base<wchar_t,__crt_stdio_output::string_output_adapter<wchar_t>>>::process(v20);
  v12 = v11;
  if ( a2 == nullptr )
    goto LABEL_22;
  if ( (a1 & 1) == 0 )
  {
    if ( (a1 & 2) != 0 )
    {
      if ( a3 == 0 )
        goto LABEL_22;
      if ( v11 < 0 )
      {
        *a2 = 0;
        goto LABEL_22;
      }
      v13 = v15;
      if ( v15 != a3 )
      {
LABEL_21:
        a2[v13] = 0;
        goto LABEL_22;
      }
    }
    else
    {
      if ( a3 == 0 )
      {
LABEL_26:
        LODWORD(v12) = -1;
        goto LABEL_22;
      }
      v13 = v15;
      if ( v15 != a3 )
        goto LABEL_21;
      LODWORD(v12) = -2;
    }
    a2[a3 - 1] = 0;
    goto LABEL_22;
  }
  if ( a3 == 0 && v11 != 0 )
    goto LABEL_26;
  v13 = v15;
  if ( v15 != a3 )
    goto LABEL_21;
  if ( (v12 & 0x80000000) == 0LL && v12 > a3 )
    goto LABEL_26;
LABEL_22:
  free_base(Block);
  Block = nullptr;
  if ( v19[16] != 0 )
    *(_DWORD *)(v18 + 936) &= ~2u;
  return (unsigned int)v12;
}


// ===== ??$ensure_buffer_is_big_enough@D@formatting_buffer@__crt_stdio_output@@QEAA_N_K@Z @ 0x18000c78c size=0xac =====
char __fastcall __crt_stdio_output::formatting_buffer::ensure_buffer_is_big_enough<char>(
        __int64 a1,
        unsigned __int64 a2)
{
  size_t v4; // rsi
  char v5; // di
  void *v6; // rbx

  if ( ((0xFFFFFFFFFFFFFFFFuLL / a2) & 0xFFFFFFFFFFFFFFFEuLL) >= 2 )
  {
    v4 = 2 * a2;
    v5 = 0;
    if ( (*(_QWORD *)(a1 + 1032) != 0 || v4 > 0x400) && v4 > *(_QWORD *)(a1 + 1024) )
    {
      v6 = malloc_base(v4);
      if ( v6 != nullptr )
      {
        free_base(*(void **)(a1 + 1032));
        *(_QWORD *)(a1 + 1032) = v6;
        v5 = 1;
        *(_QWORD *)(a1 + 1024) = v4;
      }
      free_base(nullptr);
      return v5;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    *errno() = 12;
    return 0;
  }
}


// ===== ??$is_wide_character_specifier@_W@__crt_stdio_output@@YA_N_K_WW4length_modifier@0@@Z @ 0x18000c838 size=0x44 =====
bool __fastcall __crt_stdio_output::is_wide_character_specifier<wchar_t>(char a1, __int16 a2, int a3)
{
  if ( a3 == 2 )
    return false;
  if ( a3 == 3 || a3 == 12 || a3 == 13 )
    return true;
  return ((a1 & 4) != 0) == (((a2 - 99) & 0xFFEF) == 0);
}


// ===== unknown_libname_44 @ 0x18000c87c size=0x9b =====
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_44(__int64 a1, unsigned int a2, unsigned int a3, char a4)
{
  __int64 v4; // rax
  __int64 v6; // rcx
  __int64 v9; // rax
  __int64 v10; // r8
  __int64 result; // rax
  char v12; // dl
  int v13; // r8d

  v4 = a1 + 88;
  v6 = *(_QWORD *)(a1 + 1120);
  if ( v6 == 0 )
    v6 = v4;
  if ( *(_QWORD *)(v4 + 1032) != 0 )
    v9 = *(_QWORD *)(v4 + 1024) >> 1;
  else
    v9 = 512;
  v10 = v9 + v6 - 1;
  for ( *(_QWORD *)(a1 + 72) = v10; ; --*(_QWORD *)(a1 + 72) )
  {
    result = *(unsigned int *)(a1 + 56);
    if ( (int)result <= 0 && a2 == 0 )
      break;
    *(_DWORD *)(a1 + 56) = result - 1;
    v12 = a2 % a3 + 48;
    a2 /= a3;
    if ( v12 > 57 )
      v12 += a4 != 0 ? 7 : 39;
    **(_BYTE **)(a1 + 72) = v12;
  }
  v13 = v10 - *(_DWORD *)(a1 + 72);
  ++*(_QWORD *)(a1 + 72);
  *(_DWORD *)(a1 + 80) = v13;
  return result;
}


// ===== unknown_libname_45 @ 0x18000c918 size=0x9c =====
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_45(__int64 a1, unsigned __int64 a2, unsigned int a3, char a4)
{
  __int64 v4; // rax
  unsigned __int64 v5; // rbx
  __int64 v8; // rcx
  __int64 v9; // rax
  __int64 v10; // r8
  __int64 result; // rax
  char v12; // dl
  int v13; // r8d

  v4 = a1 + 88;
  v5 = a3;
  v8 = *(_QWORD *)(a1 + 1120);
  if ( v8 == 0 )
    v8 = v4;
  if ( *(_QWORD *)(v4 + 1032) != 0 )
    v9 = *(_QWORD *)(v4 + 1024) >> 1;
  else
    v9 = 512;
  v10 = v9 + v8 - 1;
  for ( *(_QWORD *)(a1 + 72) = v10; ; --*(_QWORD *)(a1 + 72) )
  {
    result = *(unsigned int *)(a1 + 56);
    if ( (int)result <= 0 && a2 == 0 )
      break;
    *(_DWORD *)(a1 + 56) = result - 1;
    v12 = a2 % v5 + 48;
    a2 /= v5;
    if ( v12 > 57 )
      v12 += a4 != 0 ? 7 : 39;
    **(_BYTE **)(a1 + 72) = v12;
  }
  v13 = v10 - *(_DWORD *)(a1 + 72);
  ++*(_QWORD *)(a1 + 72);
  *(_DWORD *)(a1 + 80) = v13;
  return result;
}


// ===== ??$write_multiple_characters@V?$string_output_adapter@_W@__crt_stdio_output@@D@__crt_stdio_output@@YAXAEBV?$string_output_adapter@_W@0@DHQEAH@Z @ 0x18000c9b4 size=0x6e =====
__int64 __fastcall __crt_stdio_output::write_multiple_characters<__crt_stdio_output::string_output_adapter<wchar_t>,char>(
        __int64 *a1,
        char a2,
        int a3,
        _DWORD *a4)
{
  int i; // r11d
  __int64 result; // rax

  if ( a3 > 0 )
  {
    for ( i = 0; i < a3; ++i )
    {
      result = *(_QWORD *)(*a1 + 8);
      if ( *(_QWORD *)(*a1 + 16) == result )
      {
        if ( *(_BYTE *)(*a1 + 24) != 0 )
          ++*a4;
        else
          *a4 = -1;
      }
      else
      {
        ++*a4;
        ++*(_QWORD *)(*a1 + 16);
        **(_WORD **)*a1 = a2;
        result = *a1;
        *(_QWORD *)*a1 += 2LL;
      }
      if ( *a4 == -1 )
        break;
    }
  }
  return result;
}


// ===== unknown_libname_46 @ 0x18000ca24 size=0x7f =====
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_46(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  *(_QWORD *)a1 = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 24) = 0;
  *(_QWORD *)(a1 + 32) = 0;
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 40) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  *(_DWORD *)(a1 + 56) = 0;
  *(_BYTE *)(a1 + 64) = 0;
  *(_WORD *)(a1 + 66) = 0;
  *(_DWORD *)(a1 + 80) = 0;
  *(_BYTE *)(a1 + 84) = 0;
  *(_QWORD *)(a1 + 1112) = 0;
  *(_QWORD *)(a1 + 1120) = 0;
  *(_QWORD *)(a1 + 1128) = *a2;
  *(_QWORD *)(a1 + 8) = a5;
  *(_QWORD *)(a1 + 32) = a6;
  *(_QWORD *)a1 = a3;
  *(_QWORD *)(a1 + 24) = a4;
  *(_DWORD *)(a1 + 1136) = 0;
  *(_QWORD *)(a1 + 16) = errno();
  return a1;
}


// ===== ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z @ 0x18000caa4 size=0x90 =====
_LocaleUpdate *__fastcall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, struct __crt_locale_pointers *const a2)
{
  __int128 v3; // xmm0
  __int64 v4; // rax
  int v5; // eax

  *((_BYTE *)this + 24) = 0;
  if ( a2 != nullptr )
  {
    v3 = (__int128)*a2;
LABEL_5:
    *(_OWORD *)((char *)this + 8) = v3;
    return this;
  }
  if ( dword_18002ABE0 == 0 )
  {
    v3 = *(_OWORD *)&off_180029528;
    goto LABEL_5;
  }
  v4 = _acrt_getptd();
  *(_QWORD *)this = v4;
  *((_QWORD *)this + 1) = *(_QWORD *)(v4 + 144);
  *((_QWORD *)this + 2) = *(_QWORD *)(v4 + 136);
  sub_180010394(v4);
  sub_1800103C8(*(_QWORD *)this, (char *)this + 16);
  v5 = *(_DWORD *)(*(_QWORD *)this + 936LL);
  if ( (v5 & 2) == 0 )
  {
    *(_DWORD *)(*(_QWORD *)this + 936LL) = v5 | 2;
    *((_BYTE *)this + 24) = 1;
  }
  return this;
}


// ===== ?force_decimal_point@__crt_stdio_output@@YAXPEADQEAU__crt_locale_pointers@@@Z @ 0x18000cb34 size=0x6d =====
void __fastcall __crt_stdio_output::force_decimal_point(
        __crt_stdio_output *this,
        char *a2,
        struct __crt_locale_pointers *const a3)
{
  __crt_stdio_output *v3; // rbx
  char v5; // dl
  char *v6; // rbx
  char v7; // al
  char v8; // al

  v3 = this;
  if ( tolower(*(char *)this) != 101 )
  {
    do
      v3 = (__crt_stdio_output *)((char *)v3 + 1);
    while ( isdigit(*(unsigned __int8 *)v3) != 0 );
  }
  if ( tolower(*(char *)v3) == 120 )
    v3 = (__crt_stdio_output *)((char *)v3 + 2);
  v5 = *(_BYTE *)v3;
  *(_BYTE *)v3 = ***(_BYTE ***)(*(_QWORD *)a2 + 248LL);
  v6 = (char *)v3 + 1;
  do
  {
    v7 = *v6;
    *v6 = v5;
    v5 = v7;
    v8 = *v6++;
  }
  while ( v8 != 0 );
}


// ===== unknown_libname_47 @ 0x18000cba4 size=0x7f =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_47(__int64 a1, int *a2)
{
  int *v2; // rsi
  int v4; // ebp
  __int64 v5; // rcx
  char result; // al
  wchar_t *v7; // [rsp+30h] [rbp+8h] BYREF

  v2 = *(int **)(a1 + 16);
  v4 = *v2;
  *v2 = 0;
  v5 = *(_QWORD *)(a1 + 24);
  v7 = nullptr;
  *a2 = wcstol((const wchar_t *)(v5 - 2), &v7, 10);
  if ( **(_DWORD **)(a1 + 16) == 34 || (unsigned __int64)v7 < *(_QWORD *)(a1 + 24) )
  {
    result = 0;
  }
  else
  {
    *(_QWORD *)(a1 + 24) = v7;
    result = 1;
  }
  if ( *v2 == 0 && v4 != 0 )
    *v2 = v4;
  return result;
}


// ===== ?process@?$output_processor@_WV?$string_output_adapter@_W@__crt_stdio_output@@V?$format_validation_base@_WV?$string_output_adapter@_W@__crt_stdio_output@@@2@@__crt_stdio_output@@QEAAHXZ @ 0x18000cc24 size=0x286 =====
__int64 __fastcall __crt_stdio_output::output_processor<wchar_t,__crt_stdio_output::string_output_adapter<wchar_t>,__crt_stdio_output::format_validation_base<wchar_t,__crt_stdio_output::string_output_adapter<wchar_t>>>::process(
        __int64 a1)
{
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  char v11; // al
  int *v12; // rdx
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  __int16 v16; // dx
  __int64 v17; // rcx
  __int16 v18; // cx

  if ( *(_QWORD *)(a1 + 1128) == 0 || *(_QWORD *)(a1 + 24) == 0 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFLL;
  }
  if ( ++*(_DWORD *)(a1 + 1136) == 2 )
    return *(unsigned int *)(a1 + 40);
  while ( 2 )
  {
    *(_DWORD *)(a1 + 80) = 0;
    *(_DWORD *)(a1 + 44) = 0;
    while ( 1 )
    {
      v18 = **(_WORD **)(a1 + 24);
      *(_WORD *)(a1 + 66) = v18;
      if ( v18 == 0 )
        break;
      *(_QWORD *)(a1 + 24) += 2LL;
      if ( *(int *)(a1 + 40) < 0 )
        goto LABEL_52;
      if ( (unsigned __int16)(*(_WORD *)(a1 + 66) - 32) > 0x5Au )
        v3 = 0;
      else
        v3 = byte_18001C800[*(unsigned __int16 *)(a1 + 66) - 32] & 0xF;
      v4 = byte_18001C800[*(_DWORD *)(a1 + 44) + 8 * v3 + v3] >> 4;
      *(_DWORD *)(a1 + 44) = v4;
      if ( v4 == 8 )
        goto LABEL_56;
      if ( v4 == 0 )
      {
        v16 = *(_WORD *)(a1 + 66);
        *(_BYTE *)(a1 + 84) = 1;
        v17 = *(_QWORD *)(a1 + 1128);
        if ( *(_QWORD *)(v17 + 16) == *(_QWORD *)(v17 + 8) )
        {
          if ( *(_BYTE *)(v17 + 24) != 0 )
            ++*(_DWORD *)(a1 + 40);
          else
            *(_DWORD *)(a1 + 40) = -1;
        }
        else
        {
          ++*(_DWORD *)(a1 + 40);
          ++*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 16LL);
          ***(_WORD ***)(a1 + 1128) = v16;
          **(_QWORD **)(a1 + 1128) += 2LL;
        }
LABEL_48:
        v11 = 1;
        goto LABEL_49;
      }
      v5 = v4 - 1;
      if ( v5 != 0 )
      {
        v6 = v5 - 1;
        if ( v6 != 0 )
        {
          v7 = v6 - 1;
          if ( v7 == 0 )
          {
            if ( *(_WORD *)(a1 + 66) == 42 )
            {
              *(_QWORD *)(a1 + 32) += 8LL;
              v14 = *(_DWORD *)(*(_QWORD *)(a1 + 32) - 8LL);
              *(_DWORD *)(a1 + 52) = v14;
              if ( v14 < 0 )
              {
                *(_DWORD *)(a1 + 48) |= 4u;
                *(_DWORD *)(a1 + 52) = -v14;
              }
              goto LABEL_48;
            }
            v12 = (int *)(a1 + 52);
            goto LABEL_23;
          }
          v8 = v7 - 1;
          if ( v8 != 0 )
          {
            v9 = v8 - 1;
            if ( v9 != 0 )
            {
              v10 = v9 - 1;
              if ( v10 != 0 )
              {
                if ( v10 != 1 )
                  return 0xFFFFFFFFLL;
                v11 = _multtenpow12(a1);
              }
              else
              {
                v11 = sub_18000CEAC(a1);
              }
              goto LABEL_49;
            }
            if ( *(_WORD *)(a1 + 66) == 42 )
            {
              *(_QWORD *)(a1 + 32) += 8LL;
              v13 = *(_DWORD *)(*(_QWORD *)(a1 + 32) - 8LL);
              if ( v13 < 0 )
                v13 = -1;
              *(_DWORD *)(a1 + 56) = v13;
              goto LABEL_48;
            }
            v12 = (int *)(a1 + 56);
LABEL_23:
            v11 = unknown_libname_47(a1, v12);
LABEL_49:
            if ( v11 == 0 )
              return 0xFFFFFFFFLL;
          }
          else
          {
            *(_DWORD *)(a1 + 56) = 0;
          }
        }
        else
        {
          v15 = *(unsigned __int16 *)(a1 + 66);
          switch ( v15 )
          {
            case ' ':
              *(_DWORD *)(a1 + 48) |= 2u;
              break;
            case '#':
              *(_DWORD *)(a1 + 48) |= 0x20u;
              break;
            case '+':
              *(_DWORD *)(a1 + 48) |= 1u;
              break;
            case '-':
              *(_DWORD *)(a1 + 48) |= 4u;
              break;
            case '0':
              *(_DWORD *)(a1 + 48) |= 8u;
              break;
            default:
              break;
          }
        }
      }
      else
      {
        *(_QWORD *)(a1 + 48) = 0;
        *(_BYTE *)(a1 + 64) = 0;
        *(_DWORD *)(a1 + 56) = -1;
        *(_DWORD *)(a1 + 60) = 0;
        *(_BYTE *)(a1 + 84) = 0;
      }
    }
    *(_QWORD *)(a1 + 24) += 2LL;
LABEL_52:
    if ( *(_DWORD *)(a1 + 44) != 0 && *(_DWORD *)(a1 + 44) != 7 )
    {
LABEL_56:
      *errno() = 22;
      invalid_parameter_noinfo();
      return 0xFFFFFFFFLL;
    }
    if ( ++*(_DWORD *)(a1 + 1136) != 2 )
      continue;
    return *(unsigned int *)(a1 + 40);
  }
}


// ===== sub_18000CEAC @ 0x18000ceac size=0x1a2 =====
char __fastcall sub_18000CEAC(__int64 a1)
{
  char result; // al
  int v2; // eax
  bool v3; // zf
  _WORD *v4; // rax
  _WORD *v5; // rax
  __int16 *v6; // rdx
  __int16 v7; // ax
  unsigned __int16 v8; // ax
  __int64 v9; // rdx

  if ( *(_WORD *)(a1 + 66) == 70 )
  {
    if ( (*(_BYTE *)a1 & 8) == 0 )
    {
      *(_DWORD *)(a1 + 44) = 7;
      return _multtenpow12(a1);
    }
    return 1;
  }
  if ( *(_WORD *)(a1 + 66) == 78 )
  {
    if ( (*(_BYTE *)a1 & 8) == 0 )
    {
      *(_DWORD *)(a1 + 44) = 8;
LABEL_7:
      *errno() = 22;
      invalid_parameter_noinfo();
      return 0;
    }
    return 1;
  }
  if ( *(_DWORD *)(a1 + 60) != 0 )
    goto LABEL_7;
  v2 = *(unsigned __int16 *)(a1 + 66);
  switch ( v2 )
  {
    case 'I':
      v6 = *(__int16 **)(a1 + 24);
      v7 = *v6;
      if ( *(_DWORD *)v6 == 3276851 )
      {
        *(_DWORD *)(a1 + 60) = 10;
        *(_QWORD *)(a1 + 24) = v6 + 2;
      }
      else if ( v7 == 54 && v6[1] == 52 )
      {
        *(_DWORD *)(a1 + 60) = 11;
        *(_QWORD *)(a1 + 24) = v6 + 2;
      }
      else
      {
        v8 = v7 - 88;
        if ( v8 <= 0x20u )
        {
          v9 = 0x120821001LL;
          if ( _bittest64(&v9, v8) )
            *(_DWORD *)(a1 + 60) = 9;
        }
      }
      return 1;
    case 'L':
      *(_DWORD *)(a1 + 60) = 8;
      return 1;
    case 'T':
      *(_DWORD *)(a1 + 60) = 13;
      return 1;
    case 'h':
      v5 = *(_WORD **)(a1 + 24);
      if ( *v5 == 104 )
      {
        *(_DWORD *)(a1 + 60) = 1;
        *(_QWORD *)(a1 + 24) = v5 + 1;
      }
      else
      {
        *(_DWORD *)(a1 + 60) = 2;
      }
      return 1;
    case 'j':
      *(_DWORD *)(a1 + 60) = 5;
      return 1;
    case 'l':
      v4 = *(_WORD **)(a1 + 24);
      if ( *v4 == 108 )
      {
        *(_DWORD *)(a1 + 60) = 4;
        *(_QWORD *)(a1 + 24) = v4 + 1;
      }
      else
      {
        *(_DWORD *)(a1 + 60) = 3;
      }
      return 1;
    case 't':
      *(_DWORD *)(a1 + 60) = 7;
      return 1;
    case 'w':
      *(_DWORD *)(a1 + 60) = 12;
      return 1;
    default:
      break;
  }
  v3 = v2 == 122;
  result = 1;
  if ( v3 )
    *(_DWORD *)(a1 + 60) = 6;
  return result;
}


// ===== __multtenpow12 @ 0x18000d050 size=0x2c9 =====
char __fastcall _multtenpow12(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // eax
  __int64 v4; // rbx
  char v5; // al
  __int64 v6; // rdx
  int v7; // ecx
  int v9; // edx
  __int64 v10; // rdi
  __int16 v11; // ax
  __int16 v12; // cx
  bool v13; // r8
  bool v14; // al
  int v15; // esi
  int v16; // ecx
  int v17; // [rsp+30h] [rbp-38h] BYREF
  __int16 v18; // [rsp+34h] [rbp-34h]

  v3 = *(unsigned __int16 *)(a1 + 66);
  v4 = a1;
  if ( v3 > 0x64 )
  {
    if ( *(unsigned __int16 *)(a1 + 66) <= 0x67u )
      goto LABEL_34;
    if ( v3 != 105 )
    {
      switch ( v3 )
      {
        case 'n':
          v5 = unknown_libname_51();
          goto LABEL_35;
        case 'o':
          v7 = *(_DWORD *)(a1 + 48);
          if ( (v7 & 0x20) != 0 )
            *(_DWORD *)(v4 + 48) = v7 | 0x80;
          v6 = 8;
          a1 = v4;
          goto LABEL_32;
        case 'p':
          *(_DWORD *)(a1 + 56) = 16;
          *(_DWORD *)(a1 + 60) = 11;
LABEL_25:
          LOBYTE(a3) = 1;
          v6 = 16;
LABEL_33:
          v5 = sub_18000D688(a1, v6, a3);
          goto LABEL_35;
        case 's':
LABEL_23:
          v5 = unknown_libname_52();
          goto LABEL_35;
        default:
          break;
      }
      if ( v3 != 117 )
      {
        if ( v3 != 120 )
          return 0;
        v6 = 16;
        goto LABEL_32;
      }
LABEL_31:
      v6 = 10;
LABEL_32:
      a3 = 0;
      goto LABEL_33;
    }
LABEL_30:
    *(_DWORD *)(a1 + 48) |= 0x10u;
    goto LABEL_31;
  }
  if ( v3 == 100 )
    goto LABEL_30;
  if ( v3 != 65 )
  {
    if ( v3 == 67 )
    {
LABEL_12:
      v5 = unknown_libname_50(a1, 0);
      goto LABEL_35;
    }
    if ( *(unsigned __int16 *)(a1 + 66) <= 0x44u )
      return 0;
    if ( *(unsigned __int16 *)(a1 + 66) > 0x47u )
    {
      if ( v3 != 83 )
      {
        if ( v3 != 88 )
        {
          if ( v3 == 90 )
          {
            v5 = unknown_libname_48();
            goto LABEL_35;
          }
          if ( v3 != 97 )
          {
            if ( v3 == 99 )
              goto LABEL_12;
            return 0;
          }
          goto LABEL_34;
        }
        goto LABEL_25;
      }
      goto LABEL_23;
    }
  }
LABEL_34:
  v5 = unknown_libname_49();
LABEL_35:
  if ( v5 == 0 )
    return 0;
  if ( *(_BYTE *)(v4 + 64) == 0 )
  {
    v9 = *(_DWORD *)(v4 + 48);
    v17 = 0;
    v10 = 0;
    v18 = 0;
    if ( (v9 & 0x10) == 0 )
      goto LABEL_47;
    if ( (v9 & 0x40) != 0 )
    {
      v11 = 45;
    }
    else
    {
      if ( (v9 & 1) == 0 )
      {
        if ( (v9 & 2) != 0 )
        {
          LOWORD(v17) = 32;
LABEL_46:
          v10 = 1;
        }
LABEL_47:
        v12 = *(_WORD *)(v4 + 66);
        v13 = ((v12 - 88) & 0xFFDF) == 0 && (v9 & 0x20) != 0;
        if ( v13 || ((v12 - 65) & 0xFFDF) == 0 )
        {
          *((_WORD *)&v17 + v10++) = 48;
          v14 = v12 == 88 || v12 == 65;
          *((_WORD *)&v17 + v10) = v14 ? 88 : 120;
          LODWORD(v10) = v10 + 1;
        }
        v15 = *(_DWORD *)(v4 + 52) - *(_DWORD *)(v4 + 80) - v10;
        if ( (v9 & 0xC) == 0 )
          __crt_stdio_output::write_multiple_characters<__crt_stdio_output::string_output_adapter<wchar_t>,char>(
            (__int64 *)(v4 + 1128),
            32,
            v15,
            (_DWORD *)(v4 + 40));
        __crt_stdio_output::string_output_adapter<wchar_t>::write_string(
          v4 + 1128,
          (unsigned int)&v17,
          v10,
          v4 + 40,
          *(_QWORD *)(v4 + 16));
        v16 = *(_DWORD *)(v4 + 48);
        if ( (v16 & 8) != 0 && (v16 & 4) == 0 )
          __crt_stdio_output::write_multiple_characters<__crt_stdio_output::string_output_adapter<wchar_t>,char>(
            (__int64 *)(v4 + 1128),
            48,
            v15,
            (_DWORD *)(v4 + 40));
        unknown_libname_53(v4, 0);
        if ( *(int *)(v4 + 40) >= 0 && (*(_DWORD *)(v4 + 48) & 4) != 0 )
          __crt_stdio_output::write_multiple_characters<__crt_stdio_output::string_output_adapter<wchar_t>,char>(
            (__int64 *)(v4 + 1128),
            32,
            v15,
            (_DWORD *)(v4 + 40));
        return 1;
      }
      v11 = 43;
    }
    LOWORD(v17) = v11;
    goto LABEL_46;
  }
  return 1;
}


// ===== unknown_libname_48 @ 0x18000d31c size=0x80 =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_48(__int64 a1)
{
  unsigned __int16 *v2; // rdi
  __int64 v3; // rsi
  bool v4; // zf
  unsigned int v5; // eax

  *(_QWORD *)(a1 + 32) += 8LL;
  v2 = *(unsigned __int16 **)(*(_QWORD *)(a1 + 32) - 8LL);
  if ( v2 == nullptr || (v3 = *((_QWORD *)v2 + 1)) == 0 )
  {
    *(_DWORD *)(a1 + 80) = 6;
    *(_QWORD *)(a1 + 72) = "(null)";
    goto LABEL_7;
  }
  v4 = !__crt_stdio_output::is_wide_character_specifier<wchar_t>(
          *(_QWORD *)a1,
          *(_WORD *)(a1 + 66),
          *(_DWORD *)(a1 + 60));
  *(_QWORD *)(a1 + 72) = v3;
  v5 = *v2;
  if ( v4 )
  {
    *(_DWORD *)(a1 + 80) = v5;
LABEL_7:
    *(_BYTE *)(a1 + 84) = 0;
    return 1;
  }
  *(_DWORD *)(a1 + 80) = v5 >> 1;
  *(_BYTE *)(a1 + 84) = 1;
  return 1;
}


// ===== unknown_libname_49 @ 0x18000d39c size=0x241 =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_49(__int64 a1)
{
  int v2; // eax
  __int64 v3; // rdi
  char is_big; // al
  unsigned __int64 v5; // r8
  __int64 v6; // rax
  __int64 v7; // rax
  bool v8; // zf
  unsigned __int64 v9; // r9
  __int64 v10; // rcx
  char *v11; // r10
  char *v12; // rdx
  struct __crt_locale_pointers *v13; // r8
  char *v14; // rdx
  char v15; // r8
  char v16; // al
  char *v17; // rdx
  char *v18; // rcx
  char v19; // al
  _BYTE *v20; // rax
  _BYTE *v21; // rdx
  __int64 v22; // rcx
  __int64 v23; // rcx
  double v25; // [rsp+60h] [rbp+8h] BYREF

  *(_DWORD *)(a1 + 48) |= 0x10u;
  v2 = *(_DWORD *)(a1 + 56);
  if ( v2 >= 0 )
  {
    if ( v2 == 0 && ((*(_WORD *)(a1 + 66) - 71) & 0xFFDF) == 0 )
      *(_DWORD *)(a1 + 56) = 1;
  }
  else
  {
    *(_DWORD *)(a1 + 56) = ((*(_WORD *)(a1 + 66) - 65) & 0xFFDF) != 0 ? 6 : 13;
  }
  v3 = a1 + 88;
  is_big = __crt_stdio_output::formatting_buffer::ensure_buffer_is_big_enough<char>(a1 + 88, *(_DWORD *)(a1 + 56) + 349);
  v5 = 512;
  if ( is_big == 0 )
  {
    if ( *(_QWORD *)(v3 + 1032) != 0 )
      v6 = *(_QWORD *)(v3 + 1024) >> 1;
    else
      LODWORD(v6) = 512;
    *(_DWORD *)(a1 + 56) = v6 - 349;
  }
  v7 = *(_QWORD *)(v3 + 1032);
  if ( v7 == 0 )
    v7 = v3;
  *(_QWORD *)(a1 + 72) = v7;
  *(_QWORD *)(a1 + 32) += 8LL;
  v8 = *(_QWORD *)(v3 + 1032) == 0;
  v25 = 0.0;
  v25 = *(double *)(*(_QWORD *)(a1 + 32) - 8LL);
  if ( v8 )
    v9 = 512;
  else
    v9 = *(_QWORD *)(v3 + 1024) >> 1;
  v10 = *(_QWORD *)(v3 + 1032);
  if ( v10 != 0 )
    v11 = (char *)(v10 + (*(_QWORD *)(v3 + 1024) >> 1));
  else
    v11 = (char *)(v3 + 512);
  if ( v10 != 0 )
    v5 = *(_QWORD *)(v3 + 1024) >> 1;
  v12 = *(char **)(v3 + 1032);
  if ( v10 == 0 )
    v12 = (char *)v3;
  _acrt_fp_format(
    &v25,
    v12,
    v5,
    v11,
    v9,
    *(char *)(a1 + 66),
    *(_DWORD *)(a1 + 56),
    *(_QWORD *)a1,
    *(struct __crt_locale_pointers **)(a1 + 8));
  if ( (*(_DWORD *)(a1 + 48) & 0x20) != 0 && *(_DWORD *)(a1 + 56) == 0 )
    __crt_stdio_output::force_decimal_point(*(__crt_stdio_output **)(a1 + 72), *(char **)(a1 + 8), v13);
  if ( ((*(_WORD *)(a1 + 66) - 71) & 0xFFDF) == 0 && (*(_DWORD *)(a1 + 48) & 0x20) == 0 )
  {
    v14 = *(char **)(a1 + 72);
    v15 = ***(_BYTE ***)(**(_QWORD **)(a1 + 8) + 248LL);
    while ( *v14 != 0 && *v14 != v15 )
      ++v14;
    v16 = *v14;
    v17 = v14 + 1;
    if ( v16 != 0 )
    {
      while ( *v17 != 0 && ((*v17 - 69) & 0xDF) != 0 )
        ++v17;
      v18 = v17;
      do
        --v17;
      while ( *v17 == 48 );
      if ( *v17 == v15 )
        --v17;
      do
      {
        v19 = *v18;
        ++v17;
        ++v18;
        *v17 = v19;
      }
      while ( v19 != 0 );
    }
  }
  v20 = *(_BYTE **)(a1 + 72);
  if ( *v20 == 45 )
  {
    *(_DWORD *)(a1 + 48) |= 0x40u;
    *(_QWORD *)(a1 + 72) = ++v20;
  }
  v21 = *(_BYTE **)(a1 + 72);
  LOBYTE(v20) = *v21 - 73;
  if ( (unsigned __int8)v20 <= 0x25u )
  {
    v22 = 0x2100000021LL;
    if ( _bittest64(&v22, (unsigned __int64)v20) )
      *(_WORD *)(a1 + 66) = 115;
  }
  v23 = -1;
  do
    ++v23;
  while ( v21[v23] != 0 );
  *(_DWORD *)(a1 + 80) = v23;
  return 1;
}


// ===== unknown_libname_50 @ 0x18000d5e0 size=0xa6 =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_50(__int64 a1)
{
  wchar_t v2; // si
  bool is_wide_character; // al
  wchar_t *v4; // rcx
  __crt_locale_pointers *v5; // r9
  __int64 v6; // rcx
  char result; // al
  char SrcCh; // [rsp+30h] [rbp+8h] BYREF
  char v9; // [rsp+31h] [rbp+9h]

  *(_BYTE *)(a1 + 84) = 1;
  *(_QWORD *)(a1 + 32) += 8LL;
  v2 = *(_WORD *)(*(_QWORD *)(a1 + 32) - 8LL);
  is_wide_character = __crt_stdio_output::is_wide_character_specifier<wchar_t>(
                        *(_QWORD *)a1,
                        *(_WORD *)(a1 + 66),
                        *(_DWORD *)(a1 + 60));
  v4 = *(wchar_t **)(a1 + 1120);
  if ( is_wide_character )
  {
    if ( v4 == nullptr )
      v4 = (wchar_t *)(a1 + 88);
    *v4 = v2;
  }
  else
  {
    v5 = *(__crt_locale_pointers **)(a1 + 8);
    SrcCh = v2;
    v9 = 0;
    if ( v4 == nullptr )
      v4 = (wchar_t *)(a1 + 88);
    if ( mbtowc_l(v4, &SrcCh, *((int *)v5->locinfo + 2), v5) < 0 )
      *(_BYTE *)(a1 + 64) = 1;
  }
  v6 = *(_QWORD *)(a1 + 1120);
  result = 1;
  *(_DWORD *)(a1 + 80) = 1;
  if ( v6 == 0 )
    v6 = a1 + 88;
  *(_QWORD *)(a1 + 72) = v6;
  return result;
}


// ===== sub_18000D688 @ 0x18000d688 size=0x19f =====
char __fastcall sub_18000D688(__int64 a1, unsigned int a2, char a3)
{
  int v4; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  __int64 v9; // rdx
  int v11; // ecx
  int v12; // ecx
  __int64 v13; // rcx
  int v14; // eax
  bool v15; // zf
  __int64 v16; // rax
  int v17; // eax
  __int64 v18; // rax
  int v19; // eax
  __int64 v20; // rax

  v4 = *(_DWORD *)(a1 + 60);
  if ( v4 > 5 )
  {
    v11 = v4 - 6;
    if ( v11 == 0 )
    {
      v9 = 8;
      goto LABEL_9;
    }
    v12 = v11 - 1;
    if ( v12 == 0 )
    {
      v9 = 8;
      goto LABEL_9;
    }
    v7 = v12 - 2;
    if ( v7 == 0 )
    {
      v9 = 8;
      goto LABEL_9;
    }
  }
  else
  {
    if ( v4 == 5 )
    {
      v9 = 8;
      goto LABEL_9;
    }
    if ( v4 == 0 )
    {
LABEL_14:
      v9 = 4;
      goto LABEL_9;
    }
    v6 = v4 - 1;
    if ( v6 == 0 )
    {
      v9 = 1;
      goto LABEL_9;
    }
    v7 = v6 - 1;
    if ( v7 == 0 )
    {
      v9 = 2;
      goto LABEL_9;
    }
  }
  v8 = v7 - 1;
  if ( v8 == 0 )
    goto LABEL_14;
  if ( v8 == 1 )
    v9 = 8;
  else
    v9 = 0;
LABEL_9:
  switch ( v9 )
  {
    case 1LL:
      v19 = *(_DWORD *)(a1 + 48);
      *(_QWORD *)(a1 + 32) += 8LL;
      v15 = (v19 & 0x10) == 0;
      v20 = *(_QWORD *)(a1 + 32);
      if ( v15 )
        v13 = *(unsigned __int8 *)(v20 - 8);
      else
        v13 = *(char *)(v20 - 8);
      break;
    case 2LL:
      v17 = *(_DWORD *)(a1 + 48);
      *(_QWORD *)(a1 + 32) += 8LL;
      v15 = (v17 & 0x10) == 0;
      v18 = *(_QWORD *)(a1 + 32);
      if ( v15 )
        v13 = *(unsigned __int16 *)(v18 - 8);
      else
        v13 = *(__int16 *)(v18 - 8);
      break;
    case 4LL:
      v14 = *(_DWORD *)(a1 + 48);
      *(_QWORD *)(a1 + 32) += 8LL;
      v15 = (v14 & 0x10) == 0;
      v16 = *(_QWORD *)(a1 + 32);
      if ( v15 )
        v13 = *(unsigned int *)(v16 - 8);
      else
        v13 = *(int *)(v16 - 8);
      break;
    case 8LL:
      *(_QWORD *)(a1 + 32) += 8LL;
      v13 = *(_QWORD *)(*(_QWORD *)(a1 + 32) - 8LL);
      break;
    default:
      *errno() = 22;
      invalid_parameter_noinfo();
      return 0;
  }
  if ( (*(_DWORD *)(a1 + 48) & 0x10) != 0 && v13 < 0 )
  {
    v13 = -v13;
    *(_DWORD *)(a1 + 48) |= 0x40u;
  }
  if ( *(int *)(a1 + 56) >= 0 )
  {
    *(_DWORD *)(a1 + 48) &= ~8u;
    if ( *(int *)(a1 + 56) > 512 )
      *(_DWORD *)(a1 + 56) = 512;
  }
  else
  {
    *(_DWORD *)(a1 + 56) = 1;
  }
  if ( v13 == 0 )
    *(_DWORD *)(a1 + 48) &= ~0x20u;
  if ( v9 == 8 )
    unknown_libname_45(a1, v13, a2, a3);
  else
    unknown_libname_44(a1, v13, a2, a3);
  if ( (*(_DWORD *)(a1 + 48) & 0x80) != 0 && (*(_DWORD *)(a1 + 80) == 0 || **(_BYTE **)(a1 + 72) != 48) )
  {
    *(_BYTE *)--*(_QWORD *)(a1 + 72) = 48;
    ++*(_DWORD *)(a1 + 80);
  }
  return 1;
}


// ===== unknown_libname_51 @ 0x18000d828 size=0xdb =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_51(__int64 a1)
{
  __int64 v1; // rbx
  _QWORD *v3; // rsi
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  __int64 v11; // rbx
  __int64 v12; // rbx
  __int64 v13; // rbx

  v1 = 8;
  *(_QWORD *)(a1 + 32) += 8LL;
  v3 = *(_QWORD **)(*(_QWORD *)(a1 + 32) - 8LL);
  if ( get_printf_count_output() == 0 )
    goto LABEL_2;
  v5 = *(_DWORD *)(a1 + 60);
  if ( v5 <= 5 )
  {
    if ( v5 == 5 )
      goto LABEL_18;
    if ( v5 == 0 )
      goto LABEL_17;
    v6 = v5 - 1;
    if ( v6 == 0 )
    {
      v1 = 1;
      goto LABEL_18;
    }
    v7 = v6 - 1;
    if ( v7 == 0 )
    {
      v1 = 2;
      goto LABEL_18;
    }
LABEL_8:
    v8 = v7 - 1;
    if ( v8 != 0 )
    {
      if ( v8 != 1 )
        v1 = 0;
      goto LABEL_18;
    }
LABEL_17:
    v1 = 4;
    goto LABEL_18;
  }
  v9 = v5 - 6;
  if ( v9 != 0 )
  {
    v10 = v9 - 1;
    if ( v10 != 0 )
    {
      v7 = v10 - 2;
      if ( v7 != 0 )
        goto LABEL_8;
    }
  }
LABEL_18:
  v11 = v1 - 1;
  if ( v11 != 0 )
  {
    v12 = v11 - 1;
    if ( v12 != 0 )
    {
      v13 = v12 - 2;
      if ( v13 != 0 )
      {
        if ( v13 != 4 )
        {
LABEL_2:
          *errno() = 22;
          invalid_parameter_noinfo();
          return 0;
        }
        *v3 = *(int *)(a1 + 40);
      }
      else
      {
        *(_DWORD *)v3 = *(_DWORD *)(a1 + 40);
      }
    }
    else
    {
      *(_WORD *)v3 = *(_WORD *)(a1 + 40);
    }
  }
  else
  {
    *(_BYTE *)v3 = *(_BYTE *)(a1 + 40);
  }
  *(_BYTE *)(a1 + 64) = 1;
  return 1;
}


// ===== unknown_libname_52 @ 0x18000d904 size=0xc6 =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_52(__int64 a1)
{
  int v2; // edi
  int v3; // r8d
  __int16 v4; // dx
  const wchar_t *v5; // rsi
  const wchar_t *v6; // rcx
  _BYTE *v7; // r8
  int i; // r9d

  *(_QWORD *)(a1 + 32) += 8LL;
  v2 = *(_DWORD *)(a1 + 56);
  v3 = *(_DWORD *)(a1 + 60);
  v4 = *(_WORD *)(a1 + 66);
  v5 = *(const wchar_t **)(*(_QWORD *)(a1 + 32) - 8LL);
  *(_QWORD *)(a1 + 72) = v5;
  if ( v2 == -1 )
    v2 = 0x7FFFFFFF;
  if ( __crt_stdio_output::is_wide_character_specifier<wchar_t>(*(_QWORD *)a1, v4, v3) )
  {
    v6 = L"(null)";
    *(_BYTE *)(a1 + 84) = 1;
    if ( v5 != nullptr )
      v6 = v5;
    *(_QWORD *)(a1 + 72) = v6;
    *(_DWORD *)(a1 + 80) = wcsnlen(v6, v2);
  }
  else
  {
    if ( v5 == nullptr )
      *(_QWORD *)(a1 + 72) = "(null)";
    v7 = *(_BYTE **)(a1 + 72);
    for ( i = 0; i < v2; ++i )
    {
      if ( *v7 == 0 )
        break;
      if ( *(__int16 *)(***(_QWORD ***)(a1 + 8) + 2LL * (unsigned __int8)*v7) < 0 )
        ++v7;
      ++v7;
    }
    *(_DWORD *)(a1 + 80) = i;
  }
  return 1;
}


// ===== unknown_libname_53 @ 0x18000d9cc size=0xed =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_53(__int64 a1)
{
  const char *v2; // rsi
  int v3; // edi
  __crt_locale_pointers *v4; // r9
  int v5; // eax
  __int64 v6; // rcx
  wchar_t v7; // r8
  wchar_t DstCh; // [rsp+40h] [rbp+8h] BYREF

  if ( *(_BYTE *)(a1 + 84) != 0 || *(int *)(a1 + 80) <= 0 )
  {
    __crt_stdio_output::string_output_adapter<wchar_t>::write_string(
      a1 + 1128,
      *(_QWORD *)(a1 + 72),
      *(_DWORD *)(a1 + 80),
      a1 + 40,
      *(_QWORD *)(a1 + 16));
  }
  else
  {
    v2 = *(const char **)(a1 + 72);
    v3 = 0;
    while ( 1 )
    {
      v4 = *(__crt_locale_pointers **)(a1 + 8);
      DstCh = 0;
      v5 = mbtowc_l(&DstCh, v2, *((int *)v4->locinfo + 2), v4);
      if ( v5 <= 0 )
        break;
      v6 = *(_QWORD *)(a1 + 1128);
      v7 = DstCh;
      if ( *(_QWORD *)(v6 + 16) == *(_QWORD *)(v6 + 8) )
      {
        if ( *(_BYTE *)(v6 + 24) != 0 )
          ++*(_DWORD *)(a1 + 40);
        else
          *(_DWORD *)(a1 + 40) = -1;
      }
      else
      {
        ++*(_DWORD *)(a1 + 40);
        ++*(_QWORD *)(v6 + 16);
        ***(_WORD ***)(a1 + 1128) = v7;
        **(_QWORD **)(a1 + 1128) += 2LL;
      }
      v2 += v5;
      if ( ++v3 == *(_DWORD *)(a1 + 80) )
        return 1;
    }
    *(_DWORD *)(a1 + 40) = -1;
  }
  return 1;
}


// ===== ?write_string@?$string_output_adapter@_W@__crt_stdio_output@@QEBAXQEB_WHQEAH1@Z @ 0x18000dabc size=0xbf =====
__int64 __fastcall __crt_stdio_output::string_output_adapter<wchar_t>::write_string(
        __int64 *a1,
        const __m128i *a2,
        int a3,
        _DWORD *a4,
        int *a5)
{
  __int64 v7; // rbp
  int v8; // r15d
  _QWORD *v9; // rcx
  __int64 result; // rax
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // r14
  __m128i *v13; // rcx

  v7 = a3;
  v8 = *a5;
  *a5 = 0;
  v9 = (_QWORD *)*a1;
  result = v9[1];
  if ( v9[2] == result )
  {
    if ( *((_BYTE *)v9 + 24) != 0 )
      *a4 += a3;
    else
      *a4 = -1;
  }
  else
  {
    v11 = result - v9[2];
    v12 = a3;
    v13 = (__m128i *)*v9;
    if ( v11 < a3 )
      v12 = v11;
    sub_1800098F0(v13, a2, 2 * v12);
    *(_QWORD *)*a1 += 2 * v12;
    *(_QWORD *)(*a1 + 16) += v12;
    result = *a1;
    if ( *(_BYTE *)(*a1 + 24) != 0 )
    {
      *a4 += v7;
    }
    else if ( v12 == v7 )
    {
      *a4 += v12;
    }
    else
    {
      *a4 = -1;
    }
  }
  if ( *a5 == 0 && v8 != 0 )
    *a5 = v8;
  return result;
}


// ===== unknown_libname_54 @ 0x18000db7c size=0x6e =====
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_54(
        int a1,
        _WORD *a2,
        unsigned __int64 a3,
        __int64 a4,
        struct __crt_locale_pointers *a5,
        __int64 a6)
{
  __int64 result; // rax

  if ( a4 == 0 || a2 == nullptr || a3 == 0 )
  {
    *errno() = 22;
    goto LABEL_9;
  }
  result = sub_18000C5D8(a1, a2, a3, a4, a5, a6);
  if ( (int)result < 0 )
    *a2 = 0;
  if ( (_DWORD)result == -2 )
  {
    *errno() = 34;
LABEL_9:
    invalid_parameter_noinfo();
    return 0xFFFFFFFFLL;
  }
  return result;
}


// ===== wcscpy_s @ 0x18000dbec size=0x65 =====
errno_t __cdecl wcscpy_s(wchar_t *Destination, rsize_t SizeInWords, const wchar_t *Source)
{
  errno_t v3; // ebx
  int *v4; // rax
  wchar_t *v6; // r9
  signed __int64 v7; // r8
  wchar_t v8; // ax

  v3 = 0;
  if ( Destination == nullptr || SizeInWords == 0 )
    goto LABEL_5;
  if ( Source == nullptr )
  {
    *Destination = 0;
LABEL_5:
    v4 = errno();
    v3 = 22;
LABEL_6:
    *v4 = v3;
    invalid_parameter_noinfo();
    return v3;
  }
  v6 = Destination;
  v7 = (char *)Source - (char *)Destination;
  do
  {
    v8 = *(wchar_t *)((char *)v6 + v7);
    *v6++ = v8;
    if ( v8 == 0 )
      break;
    --SizeInWords;
  }
  while ( SizeInWords != 0 );
  if ( SizeInWords == 0 )
  {
    *Destination = 0;
    v4 = errno();
    v3 = 34;
    goto LABEL_6;
  }
  return v3;
}


// ===== sub_18000DC54 @ 0x18000dc54 size=0x8 =====
void __fastcall sub_18000DC54(__int64 a1)
{
  qword_18002AA38 = a1;
}


// ===== _callnewh @ 0x18000dc5c size=0x40 =====
int __cdecl callnewh(size_t Size)
{
  _PNH new_handler; // rax

  new_handler = query_new_handler();
  return new_handler != nullptr && ((unsigned int (__fastcall *)(size_t))new_handler)(Size) != 0;
}


// ===== _query_new_handler @ 0x18000dc9c size=0x34 =====
_PNH __cdecl query_new_handler()
{
  int (__cdecl *v0)(size_t); // rbx

  sub_180011524(0);
  v0 = (int (__cdecl *)(size_t))__ROR8__(qword_18002AA38 ^ _security_cookie, _security_cookie & 0x3F);
  sub_180011578(0);
  return v0;
}


// ===== _seh_filter_dll @ 0x18000dcd0 size=0x13 =====
int __cdecl seh_filter_dll(unsigned int ExceptionNum, struct _EXCEPTION_POINTERS *ExceptionPtr)
{
  if ( ExceptionNum == -529697949 )
    return seh_filter_exe(0xE06D7363, ExceptionPtr);
  else
    return 0;
}


// ===== _seh_filter_exe @ 0x18000dce4 size=0x18d =====
int __cdecl seh_filter_exe(unsigned int ExceptionNum, struct _EXCEPTION_POINTERS *ExceptionPtr)
{
  _QWORD *v4; // rax
  _QWORD *v5; // rbx
  __int64 v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rdx
  void (__fastcall *v10)(_QWORD, _QWORD); // rdi
  __int64 v11; // rbp
  unsigned int v12; // esi
  __int64 v13; // rcx
  __int64 v14; // rdx
  int v15; // esi

  v4 = (_QWORD *)_acrt_getptd_noexit();
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  v7 = *v4;
  v8 = v7;
  v9 = v7 + 192;
  while ( *(_DWORD *)v8 != ExceptionNum )
  {
    v8 += 16;
    if ( v8 == v9 )
    {
      v8 = 0;
      break;
    }
  }
  if ( v8 == 0 )
    return 0;
  v10 = *(void (__fastcall **)(_QWORD, _QWORD))(v8 + 8);
  if ( v10 == nullptr )
    return 0;
  if ( v10 == (void (__fastcall *)(_QWORD, _QWORD))5 )
  {
    *(_QWORD *)(v8 + 8) = 0;
    return 1;
  }
  else
  {
    if ( v10 != (void (__fastcall *)(_QWORD, _QWORD))1 )
    {
      v11 = v5[1];
      v5[1] = ExceptionPtr;
      v12 = *(_DWORD *)(v8 + 4);
      if ( v12 == 8 )
      {
        v13 = v7 + 48;
        v14 = v13 + 144;
        while ( v13 != v14 )
        {
          *(_QWORD *)(v13 + 8) = 0;
          v13 += 16;
        }
        v15 = *((_DWORD *)v5 + 4);
        switch ( *(_DWORD *)v8 )
        {
          case 0xC000008D:
            *((_DWORD *)v5 + 4) = 130;
            break;
          case 0xC000008E:
            *((_DWORD *)v5 + 4) = 131;
            break;
          case 0xC000008F:
            *((_DWORD *)v5 + 4) = 134;
            break;
          case 0xC0000090:
            *((_DWORD *)v5 + 4) = 129;
            break;
          case 0xC0000091:
            *((_DWORD *)v5 + 4) = 132;
            break;
          case 0xC0000092:
            *((_DWORD *)v5 + 4) = 138;
            break;
          case 0xC0000093:
            *((_DWORD *)v5 + 4) = 133;
            break;
          case 0xC00002B4:
            *((_DWORD *)v5 + 4) = 142;
            break;
          case 0xC00002B5:
            *((_DWORD *)v5 + 4) = 141;
            break;
          default:
            break;
        }
        ((void (__fastcall *)(__int64, _QWORD, _QWORD))v10)(8, *((unsigned int *)v5 + 4), 0);
        *((_DWORD *)v5 + 4) = v15;
      }
      else
      {
        *(_QWORD *)(v8 + 8) = 0;
        v10(v12, v9);
      }
      v5[1] = v11;
    }
    return -1;
  }
}


// ===== dyntls_init_exception_filter @ 0x18000de74 size=0xc =====
_BOOL8 __fastcall dyntls_init_exception_filter(int a1)
{
  return a1 == -529697949;
}


// ===== ?common_exit@@YAXHW4_crt_exit_cleanup_mode@@W4_crt_exit_return_mode@@@Z @ 0x18000de80 size=0x16c =====
void __fastcall common_exit(unsigned int a1, enum _crt_exit_cleanup_mode a2, enum _crt_exit_return_mode a3)
{
  HMODULE ModuleHandleW; // rax
  char *v7; // rcx
  _onexit_table_t *v8; // rcx
  char v9; // al

  if ( a3 == _crt_exit_terminate_process )
  {
    ModuleHandleW = GetModuleHandleW(nullptr);
    if ( ModuleHandleW != nullptr && *(_WORD *)ModuleHandleW == 23117 )
    {
      v7 = (char *)ModuleHandleW + *((int *)ModuleHandleW + 15);
      if ( *(_DWORD *)v7 == 17744
        && *((_WORD *)v7 + 12) == 523
        && *((_DWORD *)v7 + 33) > 0xEu
        && *((_DWORD *)v7 + 62) != a3 )
      {
        try_cor_exit_process(a1);
      }
    }
  }
  sub_180011524(2);
  if ( byte_18002AA50 == 0 )
  {
    _InterlockedExchange(&dword_18002AA40, 1);
    if ( a2 != _crt_exit_full_cleanup )
    {
      if ( a2 != _crt_exit_quick_cleanup )
      {
LABEL_17:
        if ( a2 == _crt_exit_full_cleanup )
          initterm((_PVFV *)&qword_18001A4D8, (_PVFV *)&qword_18001A4F8);
        initterm((_PVFV *)&qword_18001A500, (_PVFV *)&qword_18001A508);
        v9 = byte_18002AA50;
        if ( a3 == _crt_exit_terminate_process )
          v9 = 1;
        byte_18002AA50 = v9;
        goto LABEL_22;
      }
      v8 = &stru_18002ABA0;
    }
    else
    {
      if ( qword_18002AA48 != (_security_cookie ^ __ROR8__(0, 64 - ((unsigned __int8)_security_cookie & 0x3Fu))) )
        ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))__ROR8__(
                                                        qword_18002AA48 ^ _security_cookie,
                                                        _security_cookie & 0x3F))(
          0,
          0,
          0);
      v8 = &stru_18002AB88;
    }
    execute_onexit_table(v8);
    goto LABEL_17;
  }
LABEL_22:
  sub_180011578(2);
  if ( a3 == _crt_exit_terminate_process )
    exit_or_terminate_process(a1);
}


// ===== ?exit_or_terminate_process@@YAXI@Z @ 0x18000dfec size=0x49 =====
void __fastcall __noreturn exit_or_terminate_process(UINT a1)
{
  HANDLE CurrentProcess; // rax

  if ( (unsigned __int8)_acrt_is_packaged_app() != 0 && (NtCurrentPeb()->NtGlobalFlag & 0x100) == 0 )
  {
    CurrentProcess = GetCurrentProcess();
    TerminateProcess(CurrentProcess, a1);
  }
  try_cor_exit_process(a1);
  ExitProcess(a1);
}


// ===== ?try_cor_exit_process@@YAXI@Z @ 0x18000e038 size=0x6c =====
void __fastcall try_cor_exit_process(unsigned int a1)
{
  FARPROC CorExitProcess; // rax
  HMODULE phModule; // [rsp+38h] [rbp+10h] BYREF

  phModule = nullptr;
  if ( GetModuleHandleExW(0, L"mscoree.dll", &phModule) )
  {
    CorExitProcess = GetProcAddress(phModule, "CorExitProcess");
    if ( CorExitProcess != nullptr )
      ((void (__fastcall *)(_QWORD))CorExitProcess)(a1);
  }
  if ( phModule != nullptr )
    FreeLibrary(phModule);
}


// ===== sub_18000E0A4 @ 0x18000e0a4 size=0x8 =====
void __fastcall sub_18000E0A4(__int64 a1)
{
  qword_18002AA48 = a1;
}


// ===== _cexit @ 0x18000e0ac size=0xd =====
void __cdecl cexit()
{
  common_exit(0, _crt_exit_full_cleanup, _crt_exit_return_to_caller);
}


// ===== _exit @ 0x18000e0bc size=0xc =====
void __cdecl __noreturn exit(int Code)
{
  common_exit(Code, _crt_exit_no_cleanup, _crt_exit_terminate_process);
}


// ===== sub_18000E0C8 @ 0x18000e0c8 size=0x7 =====
__int64 sub_18000E0C8()
{
  return (unsigned int)dword_18002AA40;
}


// ===== ??$parse_command_line@D@@YAXPEADPEAPEAD0PEA_K2@Z @ 0x18000e0d0 size=0x1bc =====
char __fastcall parse_command_line<char>(char *a1, _QWORD *a2, _BYTE *a3, _QWORD *a4, _QWORD *a5)
{
  _UNKNOWN **v5; // rax
  _BYTE *v7; // rdi
  _QWORD *v8; // r14
  bool v10; // bp
  unsigned int v11; // esi
  bool v12; // si
  int v13; // edx
  unsigned int v14; // eax
  _UNKNOWN *retaddr; // [rsp+38h] [rbp+0h] BYREF

  v5 = &retaddr;
  v7 = a3;
  v8 = a2;
  *a5 = 0;
  *a4 = 1;
  if ( a2 != nullptr )
  {
    *a2 = a3;
    v8 = a2 + 1;
  }
  v10 = false;
  do
  {
    if ( *a1 == 34 )
    {
      LOBYTE(v11) = 34;
      v10 = !v10;
      ++a1;
    }
    else
    {
      ++*a5;
      if ( v7 != nullptr )
        *v7++ = *a1;
      v11 = *a1++;
      LODWORD(v5) = ismbblead(v11);
      if ( (_DWORD)v5 != 0 )
      {
        ++*a5;
        if ( v7 != nullptr )
        {
          LOBYTE(v5) = *a1;
          *v7++ = *a1;
        }
        ++a1;
      }
      if ( (_BYTE)v11 == 0 )
      {
        --a1;
        goto LABEL_19;
      }
    }
  }
  while ( v10 || (_BYTE)v11 != 32 && (_BYTE)v11 != 9 );
  if ( v7 != nullptr )
    *(v7 - 1) = 0;
LABEL_19:
  v12 = false;
  while ( *a1 != 0 )
  {
    while ( *a1 == 32 || *a1 == 9 )
      ++a1;
    if ( *a1 == 0 )
      break;
    if ( v8 != nullptr )
      *v8++ = v7;
    ++*a4;
    while ( 1 )
    {
      v13 = 1;
      v14 = 0;
      while ( *a1 == 92 )
      {
        ++a1;
        ++v14;
      }
      if ( *a1 == 34 )
      {
        if ( (v14 & 1) == 0 )
        {
          if ( v12 && a1[1] == 34 )
          {
            ++a1;
          }
          else
          {
            v13 = 0;
            v12 = !v12;
          }
        }
        v14 >>= 1;
      }
      while ( v14 != 0 )
      {
        --v14;
        if ( v7 != nullptr )
          *v7++ = 92;
        ++*a5;
      }
      LOBYTE(v5) = *a1;
      if ( *a1 == 0 || !v12 && ((_BYTE)v5 == 32 || (_BYTE)v5 == 9) )
        break;
      if ( v13 != 0 )
      {
        if ( v7 != nullptr )
          *v7++ = (_BYTE)v5;
        if ( ismbblead(*a1) != 0 )
        {
          ++*a5;
          ++a1;
          if ( v7 != nullptr )
            *v7++ = *a1;
        }
        ++*a5;
      }
      ++a1;
    }
    if ( v7 != nullptr )
      *v7++ = 0;
    ++*a5;
  }
  if ( v8 != nullptr )
    *v8 = 0;
  ++*a4;
  return (char)v5;
}


// ===== __acrt_allocate_buffer_for_argv @ 0x18000e28c size=0x61 =====
void *__fastcall _acrt_allocate_buffer_for_argv(unsigned __int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  void *v4; // rbx

  if ( a1 >= 0x1FFFFFFFFFFFFFFFLL || a2 >= 0xFFFFFFFFFFFFFFFFuLL / a3 || -1LL - 8 * a1 <= a3 * a2 )
    return nullptr;
  v4 = calloc_base(a3 * a2 + 8 * a1, 1u);
  free_base(nullptr);
  return v4;
}


// ===== _configure_narrow_argv @ 0x18000e2f0 size=0x176 =====
errno_t __cdecl configure_narrow_argv(_crt_argv_mode mode)
{
  errno_t v2; // edi
  char *v3; // rsi
  unsigned __int64 v4; // r15
  _QWORD *buffer_for_argv; // rax
  void *v6; // rbx
  void *v7; // rcx
  errno_t v8; // esi
  void *v9; // rdx
  int v10; // ecx
  _QWORD *i; // rax
  void *Block; // [rsp+68h] [rbp+38h] BYREF
  unsigned __int64 v14; // [rsp+70h] [rbp+40h] BYREF
  unsigned __int64 v15; // [rsp+78h] [rbp+48h] BYREF

  if ( (unsigned int)(mode - 1) <= 1 )
  {
    _acrt_initialize_multibyte();
    GetModuleFileNameA(nullptr, Filename, 0x104u);
    v3 = (char *)qword_18002B3F0;
    v2 = 0;
    qword_18002B400 = (__int64)Filename;
    if ( qword_18002B3F0 == 0 || *(_BYTE *)qword_18002B3F0 == 0 )
      v3 = Filename;
    v14 = 0;
    v15 = 0;
    parse_command_line<char>(v3, nullptr, nullptr, &v14, &v15);
    v4 = v14;
    buffer_for_argv = _acrt_allocate_buffer_for_argv(v14, v15, 1u);
    v6 = buffer_for_argv;
    if ( buffer_for_argv != nullptr )
    {
      parse_command_line<char>(v3, buffer_for_argv, &buffer_for_argv[v4], &v14, &v15);
      if ( mode != _crt_argv_unexpanded_arguments )
      {
        Block = nullptr;
        v8 = common_expand_argv_wildcards<char>(v6, &Block);
        if ( v8 != 0 )
        {
          free_base(Block);
          Block = nullptr;
          free_base(v6);
          return v8;
        }
        v9 = Block;
        v10 = 0;
        for ( i = Block; *i != 0; ++v10 )
          ++i;
        dword_18002B3DC = v10;
        Block = nullptr;
        qword_18002B3E0 = v9;
        free_base(nullptr);
        v7 = v6;
        Block = nullptr;
LABEL_16:
        free_base(v7);
        return v2;
      }
      qword_18002B3E0 = v6;
      dword_18002B3DC = v14 - 1;
    }
    else
    {
      v2 = 12;
      *errno() = 12;
    }
    v7 = nullptr;
    goto LABEL_16;
  }
  v2 = 22;
  *errno() = 22;
  invalid_parameter_noinfo();
  return v2;
}


// ===== ??$common_initialize_environment_nolock@D@@YAHXZ @ 0x18000e468 size=0x6c =====
__int64 common_initialize_environment_nolock<char>()
{
  unsigned int v0; // edi
  char *narrow_environment_from_os; // rax
  char *v3; // rbx
  void *v4; // rax

  v0 = 0;
  if ( qword_18002AB68 != 0 )
    return 0;
  _acrt_initialize_multibyte();
  narrow_environment_from_os = (char *)_dcrt_get_narrow_environment_from_os();
  v3 = narrow_environment_from_os;
  if ( narrow_environment_from_os != nullptr )
  {
    v4 = (void *)create_environment<char>(narrow_environment_from_os);
    if ( v4 != nullptr )
    {
      qword_18002AB80 = v4;
      qword_18002AB68 = (__int64)v4;
    }
    else
    {
      v0 = -1;
    }
    free_base(nullptr);
  }
  else
  {
    v0 = -1;
  }
  free_base(v3);
  return v0;
}


// ===== ??$create_environment@D@@YAQEAPEADQEAD@Z @ 0x18000e4d4 size=0xf9 =====
void *__fastcall create_environment<char>(char *Source)
{
  void *v1; // rsi
  const char *v2; // r14
  __int64 v3; // rdx
  __int64 v4; // rax
  void *v5; // rax
  void *v6; // rbx
  char **v7; // r15
  __int64 v8; // rbp
  size_t v9; // rbp
  char *v10; // rax
  char *v11; // rdi

  v1 = nullptr;
  v2 = Source;
  v3 = 0;
  while ( *Source != 0 )
  {
    if ( *Source != 61 )
      ++v3;
    v4 = -1;
    do
      ++v4;
    while ( Source[v4] != 0 );
    Source += v4 + 1;
  }
  v5 = calloc_base(v3 + 1, 8u);
  v6 = v5;
  if ( v5 != nullptr )
  {
    v7 = (char **)v5;
    while ( *v2 != 0 )
    {
      v8 = -1;
      do
        ++v8;
      while ( v2[v8] != 0 );
      v9 = v8 + 1;
      if ( *v2 != 61 )
      {
        v10 = (char *)calloc_base(v9, 1u);
        v11 = v10;
        if ( v10 == nullptr )
        {
          unknown_libname_55(v6);
          free_base(nullptr);
          goto LABEL_20;
        }
        if ( strcpy_s(v10, v9, v2) != 0 )
          invoke_watson(nullptr, nullptr, nullptr, 0, 0);
        *v7++ = v11;
        free_base(nullptr);
      }
      v2 += v9;
    }
    v1 = v6;
  }
LABEL_20:
  free_base(nullptr);
  return v1;
}


// ===== unknown_libname_55 @ 0x18000e5d0 size=0x41 =====
// Microsoft VisualC 64bit universal runtime
void __fastcall unknown_libname_55(void **Block)
{
  void *v1; // rax
  void **v3; // rdi

  if ( Block != nullptr )
  {
    v1 = *Block;
    v3 = Block;
    while ( v1 != nullptr )
    {
      free_base(v1);
      v1 = *++v3;
    }
    free_base(Block);
  }
}


// ===== sub_18000E614 @ 0x18000e614 size=0x1a =====
void __fastcall sub_18000E614(void ***a1)
{
  void **v1; // rcx

  v1 = *a1;
  if ( v1 != qword_18002AB80 )
    unknown_libname_55(v1);
}


// ===== sub_18000E630 @ 0x18000e630 size=0x1a =====
void __fastcall sub_18000E630(void ***a1)
{
  void **v1; // rcx

  v1 = *a1;
  if ( v1 != qword_18002AB78 )
    unknown_libname_55(v1);
}


// ===== __dcrt_uninitialize_environments_nolock @ 0x18000e64c size=0x38 =====
void _dcrt_uninitialize_environments_nolock()
{
  sub_18000E614((void ***)&qword_18002AB68);
  sub_18000E630(&qword_18002AB70);
  unknown_libname_55((void **)qword_18002AB80);
  unknown_libname_55((void **)qword_18002AB78);
}


// ===== j_??$common_initialize_environment_nolock@D@@YAHXZ @ 0x18000e684 size=0x5 =====
// attributes: thunk
__int64 common_initialize_environment_nolock<char>(void)
{
  return ??$common_initialize_environment_nolock@D@@YAHXZ();
}


// ===== ??$?RV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@V_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@$$QEAV_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@Z @ 0x18000e68c size=0x3b =====
__int64 __fastcall __crt_seh_guarded_call<int>::operator()<_lambda_b8c45f8f788dd370798f47cfe8ac3a86_,_lambda_4e60a939b0d047cfe11ddc22648dfba9_ &,_lambda_332c3edc96d0294ec56c57d38c1cdfd5_>(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        unsigned int *a4)
{
  sub_180011524(*a2);
  LODWORD(a3) = _lambda_4e60a939b0d047cfe11ddc22648dfba9_::operator()(a3);
  sub_180011578(*a4);
  return (unsigned int)a3;
}


// ===== ??$?RV_lambda_e24bbb7b643b32fcea6fa61b31d4c984_@@AEAV_lambda_275893d493268fdec8709772e3fcec0e_@@V_lambda_9d71df4d7cf3f480f8d633942495c3b0_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_e24bbb7b643b32fcea6fa61b31d4c984_@@AEAV_lambda_275893d493268fdec8709772e3fcec0e_@@$$QEAV_lambda_9d71df4d7cf3f480f8d633942495c3b0_@@@Z @ 0x18000e6c8 size=0x19f =====
__int64 __fastcall __crt_seh_guarded_call<int>::operator()<_lambda_e24bbb7b643b32fcea6fa61b31d4c984_,_lambda_275893d493268fdec8709772e3fcec0e_ &,_lambda_9d71df4d7cf3f480f8d633942495c3b0_>(
        __int64 a1,
        unsigned int *a2,
        _QWORD **a3,
        unsigned int *a4)
{
  unsigned int *v4; // rdi
  _QWORD *v6; // rdx
  unsigned int v7; // ebx
  uintptr_t v8; // rsi
  char v9; // r8
  uintptr_t *v10; // rdi
  uintptr_t *v11; // rbx
  uintptr_t *v12; // r12
  uintptr_t *v13; // r14
  uintptr_t v14; // rax
  uintptr_t v15; // rdx
  void (__fastcall *v16)(_QWORD); // rsi
  _QWORD *v17; // rdx
  uintptr_t *v18; // r9
  uintptr_t *v19; // rax

  v4 = a4;
  sub_180011524(*a2);
  v6 = (_QWORD *)**a3;
  if ( v6 != nullptr )
  {
    v8 = _security_cookie;
    v9 = _security_cookie & 0x3F;
    v10 = (uintptr_t *)__ROR8__(*v6 ^ _security_cookie, _security_cookie & 0x3F);
    v11 = (uintptr_t *)__ROR8__(v6[1] ^ _security_cookie, _security_cookie & 0x3F);
    if ( (unsigned __int64)v10 - 1 <= 0xFFFFFFFFFFFFFFFDuLL )
    {
      v12 = v10;
      v13 = v11;
LABEL_5:
      v14 = v8 ^ __ROR8__(0, 64 - v9);
      while ( --v11 >= v10 )
      {
        if ( *v11 != v14 )
        {
          if ( v11 < v10 )
            break;
          v16 = (void (__fastcall *)(_QWORD))__ROR8__(*v11 ^ v8, v8 & 0x3F);
          *v11 = v14;
          v16(v16);
          v17 = (_QWORD *)**a3;
          v8 = _security_cookie;
          v9 = _security_cookie & 0x3F;
          v18 = (uintptr_t *)__ROR8__(*v17 ^ _security_cookie, _security_cookie & 0x3F);
          v19 = (uintptr_t *)__ROR8__(_security_cookie ^ v17[1], _security_cookie & 0x3F);
          if ( v18 != v12 || v19 != v13 )
          {
            v12 = v18;
            v10 = v18;
            v13 = v19;
            v11 = v19;
          }
          goto LABEL_5;
        }
      }
      if ( v10 != (uintptr_t *)-1LL )
      {
        free_base(v10);
        v8 = _security_cookie;
      }
      v15 = v8 ^ __ROR8__(0, 64 - ((unsigned __int8)v8 & 0x3Fu));
      *(_QWORD *)**a3 = v15;
      *(_QWORD *)(**a3 + 8LL) = v15;
      *(_QWORD *)(**a3 + 16LL) = v15;
    }
    v4 = a4;
    v7 = 0;
  }
  else
  {
    v7 = -1;
  }
  sub_180011578(*v4);
  return v7;
}


// ===== ??R_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@QEBAHXZ @ 0x18000e868 size=0x1da =====
__int64 __fastcall _lambda_4e60a939b0d047cfe11ddc22648dfba9_::operator()(_QWORD **a1)
{
  __int64 v1; // rsi
  _QWORD *v3; // rbx
  uintptr_t v5; // r8
  _BYTE *v6; // rbp
  uintptr_t *v7; // r9
  char *v8; // rbx
  unsigned __int64 v9; // rbx
  __int64 v10; // rdi
  size_t v11; // rdi
  char *v12; // r14
  uintptr_t v13; // rdx
  unsigned __int64 v14; // rax
  uintptr_t *v15; // rcx

  v1 = 0;
  v3 = (_QWORD *)**a1;
  if ( v3 == nullptr )
    return 0xFFFFFFFFLL;
  v5 = _security_cookie;
  v6 = (_BYTE *)__ROR8__(_security_cookie ^ *v3, _security_cookie & 0x3F);
  v7 = (uintptr_t *)__ROR8__(_security_cookie ^ v3[1], _security_cookie & 0x3F);
  v8 = (char *)__ROR8__(_security_cookie ^ v3[2], _security_cookie & 0x3F);
  if ( v7 == (uintptr_t *)v8 )
  {
    v9 = (v8 - v6) >> 3;
    v10 = v9;
    if ( v9 > 0x200 )
      v10 = 512;
    v11 = v9 + v10;
    if ( v11 == 0 )
      v11 = 32;
    if ( v11 < v9 || (v12 = (char *)j__recalloc_base(v6, v11, 8u), free_base(nullptr), v12 == nullptr) )
    {
      v11 = v9 + 4;
      v12 = (char *)j__recalloc_base(v6, v9 + 4, 8u);
      free_base(nullptr);
      if ( v12 == nullptr )
        return 0xFFFFFFFFLL;
    }
    v5 = _security_cookie;
    v7 = (uintptr_t *)&v12[8 * v9];
    v8 = &v12[8 * v11];
    v13 = _security_cookie ^ __ROR8__(0, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
    v6 = v12;
    v14 = (unsigned __int64)(v8 - (char *)v7 + 7) >> 3;
    v15 = v7;
    if ( v7 > (uintptr_t *)v8 )
      v14 = 0;
    if ( v14 != 0 )
    {
      do
      {
        ++v1;
        *v15++ = v13;
      }
      while ( v1 != v14 );
      v5 = _security_cookie;
    }
  }
  *v7 = v5 ^ __ROR8__(*a1[1], 64 - ((unsigned __int8)v5 & 0x3Fu));
  *(_QWORD *)**a1 = _security_cookie ^ __ROR8__(v6, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
  *(_QWORD *)(**a1 + 8LL) = _security_cookie ^ __ROR8__(v7 + 1, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
  *(_QWORD *)(**a1 + 16LL) = _security_cookie ^ __ROR8__(v8, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
  return 0;
}


// ===== sub_18000EA44 @ 0x18000ea44 size=0xf =====
int __fastcall sub_18000EA44(_onexit_t Function)
{
  return register_onexit_function(&stru_18002AB88, Function);
}


// ===== _execute_onexit_table @ 0x18000ea54 size=0x3a =====
int __cdecl execute_onexit_table(_onexit_table_t *Table)
{
  _onexit_table_t **v2; // [rsp+20h] [rbp-18h] BYREF
  _onexit_table_t *v3; // [rsp+40h] [rbp+8h] BYREF
  __int64 v4; // [rsp+48h] [rbp+10h] BYREF
  unsigned int v5; // [rsp+50h] [rbp+18h] BYREF
  unsigned int v6; // [rsp+58h] [rbp+20h] BYREF

  v3 = Table;
  v2 = &v3;
  v5 = 2;
  v6 = 2;
  return __crt_seh_guarded_call<int>::operator()<_lambda_e24bbb7b643b32fcea6fa61b31d4c984_,_lambda_275893d493268fdec8709772e3fcec0e_ &,_lambda_9d71df4d7cf3f480f8d633942495c3b0_>(
           (__int64)&v4,
           &v6,
           &v2,
           &v5);
}


// ===== _initialize_onexit_table @ 0x18000ea90 size=0x3f =====
int __cdecl initialize_onexit_table(_onexit_table_t *Table)
{
  _PVFV *v2; // r9

  if ( Table == nullptr )
    return -1;
  if ( Table->_first == Table->_end )
  {
    v2 = (_PVFV *)(_security_cookie ^ __ROR8__(0, 64 - ((unsigned __int8)_security_cookie & 0x3Fu)));
    Table->_first = v2;
    Table->_last = v2;
    Table->_end = v2;
  }
  return 0;
}


// ===== _register_onexit_function @ 0x18000ead0 size=0x48 =====
int __cdecl register_onexit_function(_onexit_table_t *Table, _onexit_t Function)
{
  unsigned int v3; // [rsp+20h] [rbp-20h] BYREF
  _QWORD v4[3]; // [rsp+28h] [rbp-18h] BYREF
  _onexit_table_t *v5; // [rsp+50h] [rbp+10h] BYREF
  _onexit_t v6; // [rsp+58h] [rbp+18h] BYREF
  char v7; // [rsp+60h] [rbp+20h] BYREF
  unsigned int v8; // [rsp+68h] [rbp+28h] BYREF

  v6 = Function;
  v5 = Table;
  v4[0] = &v5;
  v4[1] = &v6;
  v8 = 2;
  v3 = 2;
  return __crt_seh_guarded_call<int>::operator()<_lambda_b8c45f8f788dd370798f47cfe8ac3a86_,_lambda_4e60a939b0d047cfe11ddc22648dfba9_ &,_lambda_332c3edc96d0294ec56c57d38c1cdfd5_>(
           (__int64)&v7,
           &v3,
           (__int64)v4,
           &v8);
}


// ===== initialize_global_variables @ 0x18000eb18 size=0x11 =====
char initialize_global_variables()
{
  qword_18002ABE8 = (__int64)&off_1800293D0;
  return 1;
}


// ===== initialize_c @ 0x18000eb2c size=0x23 =====
char initialize_c()
{
  initialize_onexit_table(&stru_18002AB88);
  initialize_onexit_table(&stru_18002ABA0);
  return 1;
}


// ===== sub_18000EB50 @ 0x18000eb50 size=0x3 =====
char sub_18000EB50()
{
  return 1;
}


// ===== uninitialize_environment @ 0x18000eb54 size=0x10 =====
char uninitialize_environment()
{
  _dcrt_uninitialize_environments_nolock();
  return 1;
}


// ===== initialize_pointers @ 0x18000eb64 size=0x51 =====
char initialize_pointers()
{
  uintptr_t v0; // rbx

  v0 = _security_cookie ^ __ROR8__(0, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
  sub_18000C1A4(v0);
  sub_18000DC54(v0);
  initp_misc_winsig(v0);
  sub_180013240(v0);
  sub_18000E0A4(v0);
  return 1;
}


// ===== sub_18000EBB8 @ 0x18000ebb8 size=0x7 =====
__vcrt_bool sub_18000EBB8()
{
  return _vcrt_uninitialize(false);
}


// ===== uninitialize_allocated_memory @ 0x18000ebc0 size=0x8e =====
char uninitialize_allocated_memory()
{
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)Block, 0xFFFFFFFF) == 1 && Block != &unk_180029540 )
  {
    free_base(Block);
    Block = &unk_180029540;
  }
  free_base(qword_18002ABD0);
  qword_18002ABD0 = nullptr;
  free_base(qword_18002ABD8);
  qword_18002ABD8 = nullptr;
  free_base(qword_18002B3E0);
  qword_18002B3E0 = nullptr;
  free_base(qword_18002B3E8);
  qword_18002B3E8 = nullptr;
  return 1;
}


// ===== __acrt_initialize @ 0x18000ec50 size=0x13 =====
__crt_bool __cdecl _acrt_initialize()
{
  return _acrt_execute_initializers(&off_18001C980, &unk_18001CA70);
}


// ===== ?HasUnrealizedChores@ScheduleGroupSegmentBase@details@Concurrency@@IEAA_NXZ_0 @ 0x18000ec64 size=0x14 =====
bool __fastcall Concurrency::details::ScheduleGroupSegmentBase::HasUnrealizedChores(
        Concurrency::details::ScheduleGroupSegmentBase *this)
{
  return _acrt_getptd_noexit(this) != 0;
}


// ===== __acrt_thread_detach @ 0x18000ec78 size=0x10 =====
__crt_bool __cdecl _acrt_thread_detach()
{
  _acrt_freeptd();
  return true;
}


// ===== __acrt_uninitialize @ 0x18000ec88 size=0x13 =====
__crt_bool __cdecl _acrt_uninitialize(__crt_bool Terminating)
{
  return _acrt_execute_uninitializers(&off_18001C980, &unk_18001CA70);
}


// ===== sub_18000EC9C @ 0x18000ec9c size=0x10 =====
char sub_18000EC9C()
{
  _vcrt_uninitialize_ptd_0();
  return 1;
}


// ===== terminate @ 0x18000ecac size=0x27 =====
void __noreturn terminate()
{
  __int64 v0; // rax
  void (__fastcall *v1)(_QWORD); // rbx

  v0 = _acrt_getptd();
  v1 = *(void (__fastcall **)(_QWORD))(v0 + 24);
  if ( v1 != nullptr )
    v1(*(_QWORD *)(v0 + 24));
  abort();
}


// ===== _initterm @ 0x18000ecd4 size=0x76 =====
void __cdecl initterm(_PVFV *First, _PVFV *Last)
{
  _PVFV *v2; // rbx
  __int64 v3; // rbp
  unsigned __int64 v4; // rdi

  v2 = First;
  v3 = 0;
  v4 = (unsigned __int64)((char *)Last - (char *)First + 7) >> 3;
  if ( First > Last )
    v4 = 0;
  if ( v4 != 0 )
  {
    do
    {
      if ( *v2 != nullptr )
        ((void (__fastcall *)(_PVFV))*v2)(*v2);
      ++v2;
      ++v3;
    }
    while ( v3 != v4 );
  }
}


// ===== _initterm_e @ 0x18000ed4c size=0x4c =====
int __cdecl initterm_e(_PIFV *First, _PIFV *Last)
{
  _PIFV *v3; // rbx
  bool i; // zf
  int result; // eax

  v3 = First;
  for ( i = First == Last; !i; i = v3 == Last )
  {
    if ( *v3 != nullptr )
    {
      result = ((__int64 (__fastcall *)(_PIFV))*v3)(*v3);
      if ( result != 0 )
        return result;
    }
    ++v3;
  }
  return 0;
}


// ===== _fclose_nolock @ 0x18000ed98 size=0x83 =====
int __cdecl fclose_nolock(FILE *Stream)
{
  int v3; // edi
  unsigned int v4; // eax
  char *tmpfname; // rcx

  if ( Stream != nullptr )
  {
    v3 = -1;
    if ( (HIDWORD(Stream->_base) & 0x2000) != 0 )
    {
      v3 = _acrt_stdio_flush_nolock();
      _acrt_stdio_free_buffer_nolock(Stream);
      v4 = fileno(Stream);
      if ( (int)sub_180013348(v4) >= 0 )
      {
        tmpfname = Stream->_tmpfname;
        if ( tmpfname != nullptr )
        {
          free_base(tmpfname);
          Stream->_tmpfname = nullptr;
        }
      }
      else
      {
        v3 = -1;
      }
    }
    __acrt_stdio_free_stream(Stream);
    return v3;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return -1;
  }
}


// ===== ftell @ 0x18000ee1c size=0x69 =====
int __cdecl ftell(FILE *Stream)
{
  int v3; // edi

  if ( Stream == nullptr )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return -1;
  }
  if ( (HIDWORD(Stream->_base) & 0x1000) != 0 )
  {
    __acrt_stdio_free_stream(Stream);
    return -1;
  }
  sub_1800111F4();
  v3 = fclose_nolock(Stream);
  sub_180011200(Stream);
  return v3;
}


// ===== _fileno @ 0x18000ee88 size=0x26 =====
int __cdecl fileno(FILE *Stream)
{
  if ( Stream != nullptr )
    return Stream->_flag;
  *errno() = 22;
  invalid_parameter_noinfo();
  return -1;
}


// ===== abort @ 0x18000eeb0 size=0x55 =====
void __cdecl __noreturn abort()
{
  if ( _acrt_get_sigabrt_handler() != 0 )
    raise(22);
  if ( (byte_1800292A8 & 2) != 0 )
  {
    if ( IsProcessorFeaturePresent(0x17u) )
      __fastfail(7u);
    _acrt_call_reportfault(3, 0x40000015u, 1u);
  }
  exit(3);
}


// ===== strcpy_s @ 0x18000ef08 size=0x5f =====
errno_t __cdecl strcpy_s(char *Destination, rsize_t SizeInBytes, const char *Source)
{
  errno_t v3; // ebx
  int *v4; // rax
  char *v6; // r9
  signed __int64 v7; // r8
  char v8; // al

  v3 = 0;
  if ( Destination == nullptr || SizeInBytes == 0 )
    goto LABEL_5;
  if ( Source == nullptr )
  {
    *Destination = 0;
LABEL_5:
    v4 = errno();
    v3 = 22;
LABEL_6:
    *v4 = v3;
    invalid_parameter_noinfo();
    return v3;
  }
  v6 = Destination;
  v7 = Source - Destination;
  do
  {
    v8 = v6[v7];
    *v6++ = v8;
    if ( v8 == 0 )
      break;
    --SizeInBytes;
  }
  while ( SizeInBytes != 0 );
  if ( SizeInBytes == 0 )
  {
    *Destination = 0;
    v4 = errno();
    v3 = 34;
    goto LABEL_6;
  }
  return v3;
}


// ===== j__calloc_base @ 0x18000ef68 size=0x5 =====
// attributes: thunk
void *__cdecl j__calloc_base(size_t Count, size_t Size)
{
  return calloc_base(Count, Size);
}


// ===== wcsncmp @ 0x18000ef70 size=0x2c =====
int __cdecl wcsncmp(const wchar_t *String1, const wchar_t *String2, size_t MaxCount)
{
  if ( MaxCount == 0 )
    return 0;
  while ( --MaxCount != 0 && *String1 != 0 && *String1 == *String2 )
  {
    ++String1;
    ++String2;
  }
  return *String1 - *String2;
}


// ===== ??$is_overflow_condition@K@__crt_strtox@@YA_NIK@Z @ 0x18000ef9c size=0x29 =====
bool __fastcall __crt_strtox::is_overflow_condition<unsigned long>(char a1, unsigned int a2)
{
  bool result; // al
  int v3; // ecx

  result = true;
  if ( (a1 & 4) == 0 )
  {
    if ( (a1 & 1) == 0 )
      return false;
    v3 = a1 & 2;
    if ( (v3 == 0 || a2 <= 0x80000000) && (v3 != 0 || a2 <= 0x7FFFFFFF) )
      return false;
  }
  return result;
}


// ===== ??$parse_integer@KV?$c_string_character_source@_W@__crt_strtox@@@__crt_strtox@@YAKQEAU__crt_locale_pointers@@V?$c_string_character_source@_W@0@H_N@Z @ 0x18000efc8 size=0x6d4 =====
__int64 __fastcall __crt_strtox::parse_integer<unsigned long,__crt_strtox::c_string_character_source<wchar_t>>(
        struct __crt_locale_pointers *a1,
        wint_t **a2,
        unsigned int a3,
        char a4)
{
  unsigned int v5; // r15d
  wint_t **v7; // rcx
  unsigned int v9; // r14d
  wint_t v10; // bx
  __int64 i; // rax
  int v12; // ebp
  int v13; // ecx
  int v14; // eax
  int v15; // eax
  wint_t v16; // dx
  wint_t *v17; // rcx
  wint_t *v18; // rcx
  unsigned int v19; // r8d
  unsigned int v20; // ecx
  int v21; // eax
  int v22; // ecx
  wint_t **v23; // rcx
  wint_t **v24; // rcx
  wint_t **v25; // rdx
  wint_t *v26; // [rsp+20h] [rbp-58h]
  _QWORD v27[3]; // [rsp+28h] [rbp-50h] BYREF
  char v28; // [rsp+40h] [rbp-38h]

  v5 = a3;
  if ( *a2 == nullptr || a3 != 0 && a3 - 2 > 0x22 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    goto LABEL_3;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v27, a1);
  v9 = 0;
  v26 = *a2;
  v10 = **a2;
  for ( i = (__int64)(*a2 + 1); ; i = (__int64)(*a2 + 1) )
  {
    *a2 = (wint_t *)i;
    if ( iswctype(v10, 8u) == 0 )
      break;
    v10 = **a2;
  }
  v12 = a4 != 0;
  if ( v10 == 45 )
  {
    v12 |= 2u;
  }
  else if ( v10 != 43 )
  {
    goto LABEL_15;
  }
  v10 = *(*a2)++;
LABEL_15:
  v13 = 1632;
  if ( (v5 & 0xFFFFFFEF) == 0 )
  {
    if ( v10 < 0x30u )
      goto LABEL_62;
    if ( v10 < 0x3Au )
    {
      v14 = v10 - 48;
      goto LABEL_61;
    }
    if ( v10 >= 0xFF10u )
    {
      if ( v10 >= 0xFF1Au )
        v14 = -1;
      else
        v14 = v10 - 65296;
    }
    else
    {
      if ( v10 < 0x660u )
        goto LABEL_62;
      if ( v10 < 0x66Au )
      {
LABEL_22:
        v14 = v10 - v13;
        goto LABEL_61;
      }
      if ( v10 < 0x6F0u )
        goto LABEL_62;
      if ( v10 >= 0x6FAu )
      {
        if ( v10 < 0x966u )
          goto LABEL_62;
        if ( v10 >= 0x970u )
        {
          if ( v10 < 0x9E6u )
            goto LABEL_62;
          if ( v10 >= 0x9F0u )
          {
            if ( v10 < 0xA66u )
              goto LABEL_62;
            if ( v10 >= 0xA70u )
            {
              v13 = 2790;
              if ( v10 < 0xAE6u )
                goto LABEL_62;
              if ( v10 >= 0xAF0u )
              {
                v13 = 2918;
                if ( v10 < 0xB66u )
                  goto LABEL_62;
                if ( v10 >= 0xB70u )
                {
                  v13 = 3174;
                  if ( v10 < 0xC66u )
                    goto LABEL_62;
                  if ( v10 >= 0xC70u )
                  {
                    v13 = 3302;
                    if ( v10 < 0xCE6u )
                      goto LABEL_62;
                    if ( v10 >= 0xCF0u )
                    {
                      v13 = 3430;
                      if ( v10 < 0xD66u )
                        goto LABEL_62;
                      if ( v10 >= 0xD70u )
                      {
                        v13 = 3664;
                        if ( v10 < 0xE50u )
                          goto LABEL_62;
                        if ( v10 >= 0xE5Au )
                        {
                          v13 = 3792;
                          if ( v10 < 0xED0u )
                            goto LABEL_62;
                          if ( v10 >= 0xEDAu )
                          {
                            v13 = 3872;
                            if ( v10 < 0xF20u )
                              goto LABEL_62;
                            if ( v10 >= 0xF2Au )
                            {
                              v13 = 4160;
                              if ( v10 < 0x1040u )
                                goto LABEL_62;
                              if ( v10 >= 0x104Au )
                              {
                                v13 = 6112;
                                if ( v10 < 0x17E0u )
                                  goto LABEL_62;
                                if ( v10 >= 0x17EAu )
                                {
                                  v13 = 6160;
                                  if ( v10 < 0x1810u || v10 >= 0x181Au )
                                    goto LABEL_62;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              goto LABEL_22;
            }
            v14 = v10 - 2662;
          }
          else
          {
            v14 = v10 - 2534;
          }
        }
        else
        {
          v14 = v10 - 2406;
        }
      }
      else
      {
        v14 = v10 - 1776;
      }
    }
LABEL_61:
    if ( v14 != -1 )
    {
LABEL_68:
      if ( v14 != 0 )
      {
        if ( v5 == 0 )
          v5 = 10;
      }
      else
      {
        v16 = **a2;
        v17 = *a2 + 1;
        *a2 = v17;
        if ( ((v16 - 88) & 0xFFDF) != 0 )
        {
          if ( v5 == 0 )
            v5 = 8;
          v18 = v17 - 1;
          *a2 = v18;
          if ( v16 != 0 && *v18 != v16 )
          {
            *errno() = 22;
            invalid_parameter_noinfo();
          }
        }
        else
        {
          v10 = *v17;
          if ( v5 == 0 )
            v5 = 16;
          *a2 = v17 + 1;
        }
      }
      goto LABEL_80;
    }
LABEL_62:
    if ( (unsigned __int16)(v10 - 65) <= 0x19u || (unsigned __int16)(v10 - 97) <= 0x19u )
    {
      v15 = v10;
      if ( (unsigned __int16)(v10 - 97) <= 0x19u )
        v15 = v10 - 32;
      v14 = v15 - 55;
    }
    else
    {
      v14 = -1;
    }
    goto LABEL_68;
  }
LABEL_80:
  v19 = 0xFFFFFFFF / v5;
  while ( 1 )
  {
    if ( v10 >= 0x30u )
    {
      if ( v10 < 0x3Au )
      {
        v20 = v10 - 48;
        goto LABEL_124;
      }
      if ( v10 >= 0xFF10u )
      {
        if ( v10 >= 0xFF1Au )
          v20 = -1;
        else
          v20 = v10 - 65296;
LABEL_124:
        if ( v20 != -1 )
          goto LABEL_131;
        goto LABEL_125;
      }
      if ( v10 >= 0x660u )
      {
        if ( v10 < 0x66Au )
        {
          v20 = v10 - 1632;
          goto LABEL_124;
        }
        if ( v10 >= 0x6F0u )
        {
          if ( v10 < 0x6FAu )
          {
            v20 = v10 - 1776;
            goto LABEL_124;
          }
          v21 = 2406;
          if ( v10 >= 0x966u )
          {
            if ( v10 < 0x970u )
              goto LABEL_93;
            v21 = 2534;
            if ( v10 >= 0x9E6u )
            {
              if ( v10 < 0x9F0u )
                goto LABEL_93;
              v21 = 2662;
              if ( v10 >= 0xA66u )
              {
                if ( v10 < 0xA70u )
                  goto LABEL_93;
                v21 = 2790;
                if ( v10 >= 0xAE6u )
                {
                  if ( v10 < 0xAF0u )
                    goto LABEL_93;
                  v21 = 2918;
                  if ( v10 >= 0xB66u )
                  {
                    if ( v10 < 0xB70u )
                      goto LABEL_93;
                    v21 = 3174;
                    if ( v10 >= 0xC66u )
                    {
                      if ( v10 < 0xC70u )
                        goto LABEL_93;
                      v21 = 3302;
                      if ( v10 >= 0xCE6u )
                      {
                        if ( v10 < 0xCF0u
                          || (v21 = 3430, v10 >= 0xD66u)
                          && (v10 < 0xD70u
                           || (v21 = 3664, v10 >= 0xE50u)
                           && (v10 < 0xE5Au
                            || (v21 = 3792, v10 >= 0xED0u)
                            && (v10 < 0xEDAu
                             || (v21 = 3872, v10 >= 0xF20u)
                             && (v10 < 0xF2Au
                              || (v21 = 4160, v10 >= 0x1040u)
                              && (v10 < 0x104Au
                               || (v21 = 6112, v10 >= 0x17E0u)
                               && (v10 < 0x17EAu || (v21 = 6160, v10 >= 0x1810u) && v10 < 0x181Au)))))) )
                        {
LABEL_93:
                          v20 = v10 - v21;
                          goto LABEL_124;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_125:
    if ( (unsigned __int16)(v10 - 65) <= 0x19u || (unsigned __int16)(v10 - 97) <= 0x19u )
    {
      v22 = v10;
      if ( (unsigned __int16)(v10 - 97) <= 0x19u )
        v22 = v10 - 32;
      v20 = v22 - 55;
    }
    else
    {
      v20 = -1;
    }
LABEL_131:
    if ( v20 == -1 || v20 >= v5 )
      break;
    v12 |= 8u;
    if ( v9 < v19 || v9 == v19 && v20 <= 0xFFFFFFFF % v5 )
      v9 = v20 + v5 * v9;
    else
      v12 |= 4u;
    v10 = *(*a2)++;
  }
  --*a2;
  if ( v10 != 0 && **a2 != v10 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  if ( (v12 & 8) != 0 )
  {
    if ( __crt_strtox::is_overflow_condition<unsigned long>(v12, v9) )
    {
      *errno() = 34;
      if ( (v12 & 1) != 0 )
      {
        if ( (v12 & 2) != 0 )
        {
          if ( v28 != 0 )
            *(_DWORD *)(v27[0] + 936LL) &= ~2u;
          v23 = (wint_t **)a2[1];
          if ( v23 != nullptr )
            *v23 = *a2;
          return 0x80000000LL;
        }
        else
        {
          if ( v28 != 0 )
            *(_DWORD *)(v27[0] + 936LL) &= ~2u;
          v24 = (wint_t **)a2[1];
          if ( v24 != nullptr )
            *v24 = *a2;
          return 0x7FFFFFFF;
        }
      }
      v9 = -1;
    }
    else if ( (v12 & 2) != 0 )
    {
      v9 = -v9;
    }
    if ( v28 != 0 )
      *(_DWORD *)(v27[0] + 936LL) &= ~2u;
    v25 = (wint_t **)a2[1];
    if ( v25 != nullptr )
      *v25 = *a2;
    return v9;
  }
  *a2 = v26;
  if ( v28 != 0 )
    *(_DWORD *)(v27[0] + 936LL) &= ~2u;
LABEL_3:
  v7 = (wint_t **)a2[1];
  if ( v7 != nullptr )
    *v7 = *a2;
  return 0;
}


// ===== strncmp @ 0x18000f6b0 size=0x7d =====
int __cdecl strncmp(const char *Str1, const char *Str2, size_t MaxCount)
{
  signed __int64 v3; // rdx
  unsigned __int8 v4; // al
  __int64 v5; // rax
  bool v6; // cc
  __int64 v7; // rax

  v3 = Str2 - Str1;
  if ( MaxCount != 0 )
  {
    if ( ((unsigned __int8)Str1 & 7) == 0 )
    {
_qword_loop_begin:
      while ( (((_WORD)Str1 + (_WORD)v3) & 0xFFFu) <= 0xFF8 )
      {
        v5 = *(_QWORD *)Str1;
        if ( *(_QWORD *)Str1 != *(_QWORD *)&Str1[v3] )
          break;
        Str1 += 8;
        v6 = MaxCount <= 8;
        MaxCount -= 8LL;
        if ( v6 || ((v5 - 0x101010101010101LL) & ~v5 & 0x8080808080808080uLL) != 0 )
          goto return_equal;
      }
    }
    while ( 1 )
    {
      v4 = *Str1;
      if ( *Str1 != Str1[v3] )
        return -(__int64)(v4 < (unsigned int)Str1[v3]) | 1;
      ++Str1;
      if ( --MaxCount == 0 || v4 == 0 )
        goto return_equal;
      if ( ((unsigned __int8)Str1 & 7) == 0 )
        goto _qword_loop_begin;
    }
  }
  else
  {
return_equal:
    LODWORD(v7) = 0;
  }
  return v7;
}


// ===== ??$?RV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@V_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@$$QEAV_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@Z @ 0x18000f730 size=0x5f =====
__int64 __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_46352004c1216016012b18bd6f87e700_,_lambda_3bd07e1a1191394380780325891bf33f_ &,_lambda_334532d3f185bcaa59b5be82d7d22bff_>(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        unsigned int *a4)
{
  void *v6; // rcx

  sub_180011524(*a2);
  v6 = *(void **)(**(_QWORD **)a3 + 136LL);
  if ( v6 != nullptr && _InterlockedExchangeAdd((volatile signed __int32 *)v6, 0xFFFFFFFF) == 1 && v6 != &unk_180029540 )
    free_base(v6);
  return sub_180011578(*a4);
}


// ===== ??$?RV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@V_lambda_341c25c0346d94847f1f3c463c57e077_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@$$QEAV_lambda_341c25c0346d94847f1f3c463c57e077_@@@Z @ 0x18000f790 size=0x45 =====
__int64 __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_5e887d1dcbef67a5eb4283622ba103bf_,_lambda_4466841279450cc726390878d4a41900_ &,_lambda_341c25c0346d94847f1f3c463c57e077_>(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        unsigned int *a4)
{
  sub_180011524(*a2);
  replace_current_thread_locale_nolock(
    **(struct __acrt_ptd *const **)a3,
    ***(struct __crt_locale_data *const ***)(a3 + 8));
  return sub_180011578(*a4);
}


// ===== ??$?RV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@V_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@$$QEAV_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@Z @ 0x18000f7d8 size=0x3f =====
__int64 __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_72d1df2b273a38828b1ce30cbf4cdab5_,_lambda_876a65b173b8412d3a47c70a915b0cf4_ &,_lambda_41932305e351933ebe8f8be3ed8bb5dc_>(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        unsigned int *a4)
{
  sub_180011524(*a2);
  _InterlockedIncrement(*(volatile signed __int32 **)(**(_QWORD **)a3 + 136LL));
  return sub_180011578(*a4);
}


// ===== ??$?RV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@V_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@$$QEAV_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@Z @ 0x18000f818 size=0x3d =====
__int64 __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_fb3a7dec4e47f37f22dae91bb15c9095_,_lambda_698284760c8add0bfb0756c19673e34b_ &,_lambda_dfb8eca1e75fef3034a8fb18dd509707_>(
        __int64 a1,
        unsigned int *a2,
        struct __acrt_ptd *const **a3,
        unsigned int *a4)
{
  sub_180011524(*a2);
  replace_current_thread_locale_nolock(**a3, nullptr);
  return sub_180011578(*a4);
}


// ===== ?construct_ptd_array@@YAXQEAU__acrt_ptd@@@Z @ 0x18000f858 size=0xcd =====
void __fastcall construct_ptd_array(struct __acrt_ptd *const a1)
{
  unsigned int v1; // [rsp+20h] [rbp-30h] BYREF
  unsigned int v2; // [rsp+24h] [rbp-2Ch] BYREF
  struct __acrt_ptd *v3; // [rsp+28h] [rbp-28h] BYREF
  __int64 *v4; // [rsp+30h] [rbp-20h] BYREF
  struct __acrt_ptd **v5; // [rsp+38h] [rbp-18h] BYREF
  _QWORD v6[2]; // [rsp+40h] [rbp-10h] BYREF
  char v7; // [rsp+68h] [rbp+18h] BYREF
  unsigned int v8; // [rsp+70h] [rbp+20h] BYREF
  unsigned int v9; // [rsp+78h] [rbp+28h] BYREF

  v3 = a1;
  v5 = &v3;
  v8 = 5;
  v9 = 5;
  v6[0] = &v3;
  v6[1] = &v4;
  v1 = 4;
  v2 = 4;
  v4 = &qword_18002ABE8;
  *((_DWORD *)a1 + 10) = 1;
  *(_QWORD *)v3 = &unk_18001C880;
  *((_DWORD *)v3 + 234) = 1;
  *((_QWORD *)v3 + 17) = &unk_180029540;
  *((_WORD *)v3 + 94) = 67;
  *((_WORD *)v3 + 225) = 67;
  *((_QWORD *)v3 + 116) = 0;
  __crt_seh_guarded_call<void>::operator()<_lambda_72d1df2b273a38828b1ce30cbf4cdab5_,_lambda_876a65b173b8412d3a47c70a915b0cf4_ &,_lambda_41932305e351933ebe8f8be3ed8bb5dc_>(
    (__int64)&v7,
    &v9,
    (__int64)&v5,
    &v8);
  __crt_seh_guarded_call<void>::operator()<_lambda_5e887d1dcbef67a5eb4283622ba103bf_,_lambda_4466841279450cc726390878d4a41900_ &,_lambda_341c25c0346d94847f1f3c463c57e077_>(
    (__int64)&v7,
    &v2,
    (__int64)v6,
    &v1);
}


// ===== ?DeleteThis@SchedulerProxy@details@Concurrency@@MEAAXXZ @ 0x18000f928 size=0x20 =====
void __fastcall Concurrency::details::SchedulerProxy::DeleteThis(Concurrency::details::SchedulerProxy *this)
{
  if ( this != nullptr )
  {
    destroy_ptd_array(this);
    free_base(this);
  }
}


// ===== ?destroy_ptd_array@@YAXQEAU__acrt_ptd@@@Z @ 0x18000f948 size=0xf5 =====
void __fastcall destroy_ptd_array(void **a1)
{
  unsigned int v1; // [rsp+20h] [rbp-20h] BYREF
  unsigned int v2; // [rsp+24h] [rbp-1Ch] BYREF
  void **v3; // [rsp+28h] [rbp-18h] BYREF
  void ***v4; // [rsp+30h] [rbp-10h] BYREF
  void ***v5; // [rsp+38h] [rbp-8h] BYREF
  char v6; // [rsp+58h] [rbp+18h] BYREF
  unsigned int v7; // [rsp+60h] [rbp+20h] BYREF
  unsigned int v8; // [rsp+68h] [rbp+28h] BYREF

  v3 = a1;
  v4 = &v3;
  v7 = 5;
  v8 = 5;
  v5 = &v3;
  v1 = 4;
  v2 = 4;
  if ( *a1 != &unk_18001C880 )
  {
    free_base(*a1);
    a1 = v3;
  }
  free_base(a1[14]);
  free_base(v3[11]);
  free_base(v3[12]);
  free_base(v3[13]);
  free_base(v3[9]);
  free_base(v3[10]);
  free_base(v3[15]);
  free_base(v3[16]);
  free_base(v3[120]);
  __crt_seh_guarded_call<void>::operator()<_lambda_46352004c1216016012b18bd6f87e700_,_lambda_3bd07e1a1191394380780325891bf33f_ &,_lambda_334532d3f185bcaa59b5be82d7d22bff_>(
    (__int64)&v6,
    &v8,
    (__int64)&v4,
    &v7);
  __crt_seh_guarded_call<void>::operator()<_lambda_fb3a7dec4e47f37f22dae91bb15c9095_,_lambda_698284760c8add0bfb0756c19673e34b_ &,_lambda_dfb8eca1e75fef3034a8fb18dd509707_>(
    (__int64)&v6,
    &v2,
    (struct __acrt_ptd *const **)&v5,
    &v1);
}


// ===== ?replace_current_thread_locale_nolock@@YAXQEAU__acrt_ptd@@QEAU__crt_locale_data@@@Z @ 0x18000fa40 size=0x67 =====
void __fastcall replace_current_thread_locale_nolock(struct __acrt_ptd *const a1, struct __crt_locale_data *const a2)
{
  wchar_t **v4; // rcx

  if ( *((_QWORD *)a1 + 18) != 0 )
  {
    _acrt_release_locale_ref();
    v4 = *((wchar_t ***)a1 + 18);
    if ( v4 != (wchar_t **)qword_18002ABE8 && v4 != &off_1800293D0 && *((_DWORD *)v4 + 4) == 0 )
      _acrt_free_locale(v4);
  }
  *((_QWORD *)a1 + 18) = a2;
  if ( a2 != nullptr )
    _acrt_add_locale_ref(a2);
}


// ===== __acrt_freeptd @ 0x18000faa8 size=0x41 =====
void _acrt_freeptd()
{
  void **v0; // rbx

  if ( dwTlsIndex != -1 )
  {
    v0 = (void **)_vcrt_FlsFree_0(dwTlsIndex);
    if ( v0 != nullptr )
    {
      _acrt_FlsSetValue(dwTlsIndex, nullptr);
      destroy_ptd_array(v0);
      free_base(v0);
    }
  }
}


// ===== __acrt_getptd @ 0x18000faec size=0x94 =====
struct __acrt_ptd *_acrt_getptd()
{
  DWORD LastError; // ebx
  struct __acrt_ptd *v1; // rdi
  struct __acrt_ptd *v2; // rax
  struct __acrt_ptd *v3; // rcx
  int v4; // eax

  LastError = GetLastError();
  if ( dwTlsIndex == -1 || (v1 = (struct __acrt_ptd *)_vcrt_FlsFree_0(dwTlsIndex)) == nullptr )
  {
    v2 = (struct __acrt_ptd *)calloc_base(1u, 0x3C8u);
    v1 = v2;
    if ( v2 == nullptr )
    {
      v3 = nullptr;
LABEL_5:
      free_base(v3);
      goto LABEL_10;
    }
    v4 = _acrt_FlsSetValue(dwTlsIndex, v2);
    v3 = v1;
    if ( v4 == 0 )
      goto LABEL_5;
    construct_ptd_array(v1);
    free_base(nullptr);
  }
  if ( v1 == nullptr )
  {
LABEL_10:
    SetLastError(LastError);
    abort();
  }
  SetLastError(LastError);
  return v1;
}


// ===== __acrt_getptd_noexit @ 0x18000fb80 size=0x9f =====
struct __acrt_ptd *_acrt_getptd_noexit()
{
  __int64 v0; // rsi
  DWORD LastError; // ebx
  struct __acrt_ptd *v2; // rdi
  struct __acrt_ptd *v3; // rax
  struct __acrt_ptd *v4; // rcx
  int v5; // eax

  v0 = 0;
  LastError = GetLastError();
  if ( dwTlsIndex == -1 || (v2 = (struct __acrt_ptd *)_vcrt_FlsFree_0(dwTlsIndex)) == nullptr )
  {
    v3 = (struct __acrt_ptd *)calloc_base(1u, 0x3C8u);
    v2 = v3;
    if ( v3 == nullptr )
    {
      v4 = nullptr;
LABEL_5:
      free_base(v4);
      goto LABEL_9;
    }
    v5 = _acrt_FlsSetValue(dwTlsIndex, v3);
    v4 = v2;
    if ( v5 == 0 )
      goto LABEL_5;
    construct_ptd_array(v2);
    free_base(nullptr);
  }
  if ( v2 != nullptr )
  {
    SetLastError(LastError);
    return v2;
  }
LABEL_9:
  SetLastError(LastError);
  return (struct __acrt_ptd *)v0;
}


// ===== __acrt_initialize_ptd @ 0x18000fc20 size=0x39 =====
char _acrt_initialize_ptd()
{
  dwTlsIndex = _acrt_FlsAlloc(Concurrency::details::SchedulerProxy::DeleteThis);
  if ( dwTlsIndex == -1 )
    return 0;
  if ( _acrt_getptd_noexit() == nullptr )
  {
    _vcrt_uninitialize_ptd_0(0);
    return 0;
  }
  return 1;
}


// ===== __vcrt_uninitialize_ptd_0 @ 0x18000fc5c size=0x22 =====
char _vcrt_uninitialize_ptd_0()
{
  if ( dwTlsIndex != -1 )
  {
    _acrt_FlsFree(dwTlsIndex);
    dwTlsIndex = -1;
  }
  return 1;
}


// ===== _free_base @ 0x18000fc80 size=0x3d =====
void __cdecl free_base(void *Block)
{
  int *v1; // rbx
  DWORD LastError; // eax

  if ( Block != nullptr && !HeapFree(hHeap, 0, Block) )
  {
    v1 = errno();
    LastError = GetLastError();
    *v1 = _acrt_errno_from_os_error(LastError);
  }
}


// ===== _malloc_base @ 0x18000fcc0 size=0x5e =====
void *__cdecl malloc_base(size_t Size)
{
  size_t v1; // rbx
  void *result; // rax

  v1 = Size;
  if ( Size > 0xFFFFFFFFFFFFFFE0uLL )
  {
LABEL_9:
    *errno() = 12;
    return nullptr;
  }
  else
  {
    if ( Size == 0 )
      v1 = 1;
    while ( 1 )
    {
      result = HeapAlloc(hHeap, 0, v1);
      if ( result != nullptr )
        break;
      if ( (unsigned int)sub_180014018() == 0 || callnewh(v1) == 0 )
        goto LABEL_9;
    }
  }
  return result;
}


// ===== _msize @ 0x18000fd20 size=0x39 =====
size_t __cdecl msize(void *Block)
{
  if ( Block != nullptr )
    return HeapSize(hHeap, 0, Block);
  *errno() = 22;
  invalid_parameter_noinfo();
  return -1;
}


// ===== _realloc_base @ 0x18000fd5c size=0x82 =====
void *__cdecl realloc_base(void *Block, size_t Size)
{
  void *result; // rax
  size_t v5; // r9
  void *i; // r8

  if ( Block == nullptr )
    return malloc_base(Size);
  if ( Size == 0 )
  {
    free_base(Block);
    return nullptr;
  }
  if ( Size > 0xFFFFFFFFFFFFFFE0uLL )
  {
LABEL_12:
    *errno() = 12;
    return nullptr;
  }
  v5 = Size;
  for ( i = Block; ; i = Block )
  {
    result = HeapReAlloc(hHeap, 0, i, v5);
    if ( result != nullptr )
      break;
    if ( (unsigned int)sub_180014018() == 0 || callnewh(Size) == 0 )
      goto LABEL_12;
    v5 = Size;
  }
  return result;
}


// ===== isdigit @ 0x18000fde0 size=0x74 =====
int __cdecl isdigit(int C)
{
  __int64 v1; // rbx
  int v2; // edx
  __int64 v4; // [rsp+20h] [rbp-28h] BYREF
  __crt_locale_pointers Locale; // [rsp+28h] [rbp-20h] BYREF
  char v6; // [rsp+38h] [rbp-10h]

  v1 = C;
  if ( dword_18002ABE0 == 0 )
    return off_1800293D0[C] & 4;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v4, nullptr);
  if ( *((int *)Locale.locinfo + 2) <= 1 )
    v2 = *(_WORD *)(*(_QWORD *)Locale.locinfo + 2 * v1) & 4;
  else
    v2 = isctype_l(v1, 4, &Locale);
  if ( v6 != 0 )
    *(_DWORD *)(v4 + 936) &= ~2u;
  return v2;
}


// ===== ?internal_isupper_l@@YA_NHQEAU__crt_locale_pointers@@@Z @ 0x18000fe54 size=0x4d =====
bool __fastcall internal_isupper_l(int a1, struct __crt_locale_pointers *const a2)
{
  __int64 v2; // rdi
  int v3; // eax
  const unsigned __int16 *v4; // rax

  v2 = a1;
  if ( a2 == nullptr )
  {
    v4 = _pctype_func();
    goto LABEL_6;
  }
  if ( *((int *)a2->locinfo + 2) <= 1 )
  {
    v4 = *(const unsigned __int16 **)a2->locinfo;
LABEL_6:
    v3 = v4[v2] & 1;
    return v3 != 0;
  }
  v3 = isctype_l(a1, 1, a2);
  return v3 != 0;
}


// ===== _tolower_l @ 0x18000fea4 size=0x13e =====
int __cdecl tolower_l(int C, _locale_t Locale)
{
  __int64 v2; // rbx
  int v3; // ecx
  int *v4; // rax
  int v5; // eax
  __int64 v7; // [rsp+50h] [rbp-20h] BYREF
  __crt_locale_pointers Localea; // [rsp+58h] [rbp-18h] BYREF
  char v9; // [rsp+68h] [rbp-8h]
  __int16 v10; // [rsp+80h] [rbp+10h] BYREF
  char v11; // [rsp+82h] [rbp+12h]
  __int16 v12; // [rsp+90h] [rbp+20h] BYREF
  char v13; // [rsp+92h] [rbp+22h]

  v2 = C;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v7, Locale);
  if ( (unsigned int)v2 < 0x100 )
  {
    if ( internal_isupper_l(v2, &Localea) )
      LODWORD(v2) = *(unsigned __int8 *)(*((_QWORD *)Localea.locinfo + 34) + v2);
LABEL_4:
    if ( v9 != 0 )
      *(_DWORD *)(v7 + 936) &= ~2u;
    return v2;
  }
  v10 = 0;
  v11 = 0;
  if ( *((int *)Localea.locinfo + 2) > 1 && isleadbyte_l(BYTE1(v2), &Localea) != 0 )
  {
    LOBYTE(v10) = BYTE1(v2);
    v3 = 2;
    HIBYTE(v10) = v2;
    v11 = 0;
  }
  else
  {
    v4 = errno();
    v3 = 1;
    *v4 = 42;
    v10 = (unsigned __int8)v2;
  }
  v12 = 0;
  v13 = 0;
  v5 = _acrt_LCMapStringA(
         &Localea,
         *((wchar_t **)Localea.locinfo + 39),
         0x100u,
         (char *)&v10,
         v3,
         (char *)&v12,
         3,
         *((_DWORD *)Localea.locinfo + 3),
         1);
  if ( v5 == 0 )
    goto LABEL_4;
  LODWORD(v2) = (unsigned __int8)v12;
  if ( v5 == 1 )
    goto LABEL_4;
  LODWORD(v2) = HIBYTE(v12) | ((unsigned __int8)v12 << 8);
  if ( v9 != 0 )
    *(_DWORD *)(v7 + 936) &= ~2u;
  return v2;
}


// ===== tolower @ 0x18000ffe4 size=0x2b =====
int __cdecl tolower(int C)
{
  if ( dword_18002ABE0 != 0 )
    return tolower_l(C, nullptr);
  if ( (unsigned int)(C - 65) <= 0x19 )
    C += 32;
  return C;
}


// ===== unknown_libname_56 @ 0x180010010 size=0x13 =====
// Microsoft VisualC 64bit universal runtime
_QWORD *__fastcall unknown_libname_56(_QWORD *a1, __int64 a2, _QWORD *a3)
{
  *a1 = a2;
  a1[1] = a3;
  if ( a3 != nullptr )
    *a3 = a2;
  return a1;
}


// ===== wcstol @ 0x180010024 size=0x2f =====
int __cdecl wcstol(const wchar_t *String, wchar_t **EndPtr, int Radix)
{
  wint_t **v4; // rax
  _QWORD v6[3]; // [rsp+20h] [rbp-18h] BYREF

  v4 = (wint_t **)unknown_libname_56(v6, (__int64)String, EndPtr);
  return __crt_strtox::parse_integer<unsigned long,__crt_strtox::c_string_character_source<wchar_t>>(
           nullptr,
           v4,
           Radix,
           1);
}


// ===== _mbtowc_l @ 0x180010054 size=0x148 =====
int __cdecl mbtowc_l(wchar_t *DstCh, const char *SrcCh, size_t SrcSizeInBytes, _locale_t Locale)
{
  int v8; // ebx
  struct __crt_locale_data *locinfo; // rcx
  int v10; // r9d
  int v11; // eax
  __int64 v12; // [rsp+30h] [rbp-28h] BYREF
  __crt_locale_pointers Localea; // [rsp+38h] [rbp-20h] BYREF
  char v14; // [rsp+48h] [rbp-10h]

  if ( SrcCh == nullptr || SrcSizeInBytes == 0 )
    return 0;
  if ( *SrcCh == 0 )
  {
    if ( DstCh != nullptr )
      *DstCh = 0;
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v12, Locale);
  if ( *((_QWORD *)Localea.locinfo + 39) == 0 )
  {
    if ( DstCh != nullptr )
      *DstCh = *(unsigned __int8 *)SrcCh;
    v8 = 1;
    goto LABEL_20;
  }
  v8 = 1;
  if ( isleadbyte_l(*(unsigned __int8 *)SrcCh, &Localea) == 0 )
  {
    if ( MultiByteToWideChar(*((_DWORD *)Localea.locinfo + 3), 9u, SrcCh, 1, DstCh, DstCh != nullptr) != 0 )
      goto LABEL_20;
LABEL_19:
    v8 = -1;
    *errno() = 42;
    goto LABEL_20;
  }
  locinfo = Localea.locinfo;
  v10 = *((_DWORD *)Localea.locinfo + 2);
  if ( v10 <= 1
    || (int)SrcSizeInBytes < v10
    || (v11 = MultiByteToWideChar(*((_DWORD *)Localea.locinfo + 3), 9u, SrcCh, v10, DstCh, DstCh != nullptr),
        locinfo = Localea.locinfo,
        v11 == 0) )
  {
    if ( SrcSizeInBytes < *((int *)locinfo + 2) || SrcCh[1] == 0 )
      goto LABEL_19;
  }
  v8 = *((_DWORD *)locinfo + 2);
LABEL_20:
  if ( v14 != 0 )
    *(_DWORD *)(v12 + 936) &= ~2u;
  return v8;
}


// ===== mbtowc @ 0x18001019c size=0x8 =====
int __cdecl mbtowc(wchar_t *DstCh, const char *SrcCh, size_t SrcSizeInBytes)
{
  return mbtowc_l(DstCh, SrcCh, SrcSizeInBytes, nullptr);
}


// ===== wcsnlen @ 0x1800101a4 size=0x1f0 =====
size_t __cdecl wcsnlen(const wchar_t *Source, size_t MaxCount)
{
  const wchar_t *v4; // rax
  const wchar_t *i; // rdx
  size_t v6; // r11
  const wchar_t *v7; // rdx
  const wchar_t *v8; // rax
  size_t v9; // rdx
  const wchar_t *v10; // rdx
  const wchar_t *v12; // r11
  const wchar_t *v15; // rax
  size_t v16; // r11
  const wchar_t *v17; // rdx
  const wchar_t *v18; // rax
  __m128i *v19; // rdx
  __m128i *v20; // r11
  __int64 v21; // rdx
  const wchar_t *v22; // rax

  if ( dword_180029018 < 5 )
  {
    if ( dword_180029018 < 1 )
    {
      v22 = &Source[MaxCount];
      for ( i = Source; i != v22; ++i )
      {
        if ( *i == 0 )
          break;
      }
      goto LABEL_46;
    }
    if ( ((unsigned __int8)Source & 1) != 0 )
    {
      v15 = &Source[MaxCount];
      for ( i = Source; i != v15; ++i )
      {
        if ( *i == 0 )
          break;
      }
      goto LABEL_46;
    }
    v16 = ((16LL - ((unsigned __int8)Source & 0xF)) & (unsigned __int64)-(__int64)(((unsigned __int8)Source & 0xF) != 0)) >> 1;
    if ( MaxCount < v16 )
      v16 = MaxCount;
    v17 = Source;
    v18 = &Source[v16];
    if ( Source != v18 )
    {
      do
      {
        if ( *v17 == 0 )
          break;
        ++v17;
      }
      while ( v17 != v18 );
    }
    v9 = v17 - Source;
    if ( v9 == v16 )
    {
      v19 = (__m128i *)&Source[v9];
      v20 = (__m128i *)((char *)v19 + 2 * (MaxCount - v16 - (((_BYTE)MaxCount - (_BYTE)v16) & 0xF)));
      while ( v19 != v20 && _mm_movemask_epi8(_mm_cmpeq_epi16((__m128i)0LL, *v19)) == 0 )
        ++v19;
      while ( v19 != (__m128i *)&Source[MaxCount] && v19->m128i_i16[0] != 0 )
        v19 = (__m128i *)((char *)v19 + 2);
      v21 = (char *)v19 - (char *)Source;
      return v21 >> 1;
    }
  }
  else
  {
    if ( ((unsigned __int8)Source & 1) != 0 )
    {
      v4 = &Source[MaxCount];
      for ( i = Source; i != v4; ++i )
      {
        if ( *i == 0 )
          break;
      }
LABEL_46:
      v21 = (char *)i - (char *)Source;
      return v21 >> 1;
    }
    v6 = ((32LL - ((unsigned __int8)Source & 0x1F)) & (unsigned __int64)-(__int64)(((unsigned __int8)Source & 0x1F) != 0)) >> 1;
    if ( MaxCount < v6 )
      v6 = MaxCount;
    v7 = Source;
    v8 = &Source[v6];
    if ( Source != v8 )
    {
      do
      {
        if ( *v7 == 0 )
          break;
        ++v7;
      }
      while ( v7 != v8 );
    }
    v9 = v7 - Source;
    if ( v9 == v6 )
    {
      v10 = &Source[v9];
      __asm { vxorps  ymm2, ymm2, ymm2 }
      v12 = &v10[MaxCount - v6 - (((_BYTE)MaxCount - (_BYTE)v6) & 0x1F)];
      while ( v10 != v12 )
      {
        __asm
        {
          vpcmpeqw ymm1, ymm2, ymmword ptr [rdx]
          vpmovmskb eax, ymm1
        }
        if ( _EAX != 0 )
          break;
        v10 += 16;
      }
      while ( v10 != &Source[MaxCount] && *v10 != 0 )
        ++v10;
      v9 = v10 - Source;
      __asm { vzeroupper }
    }
  }
  return v9;
}


// ===== sub_180010394 @ 0x180010394 size=0x31 =====
__int64 __fastcall sub_180010394(__int64 a1, __int64 *a2)
{
  __int64 result; // rax

  result = qword_18002ABE8;
  if ( *a2 != qword_18002ABE8 )
  {
    result = *(unsigned int *)(a1 + 936);
    if ( ((unsigned int)result & dword_180029A88) == 0 )
    {
      result = _acrt_update_thread_locale_data();
      *a2 = result;
    }
  }
  return result;
}


// ===== sub_1800103C8 @ 0x1800103c8 size=0x31 =====
__int64 __fastcall sub_1800103C8(__int64 a1, __int64 *a2)
{
  __int64 result; // rax

  result = (__int64)Block;
  if ( (void *)*a2 != Block )
  {
    result = *(unsigned int *)(a1 + 936);
    if ( ((unsigned int)result & dword_180029A88) == 0 )
    {
      result = _acrt_update_thread_multibyte_data();
      *a2 = result;
    }
  }
  return result;
}


// ===== ?__acrt_fp_classify@@YA?AW4__acrt_fp_class@@AEBN@Z @ 0x1800103fc size=0x65 =====
__int64 __fastcall __acrt_fp_classify(__int64 *a1)
{
  __int64 v1; // rdx

  v1 = *a1;
  if ( (((unsigned __int64)*a1 >> 52) & 0x7FF) != 0x7FF )
    return 0;
  if ( (v1 & 0xFFFFFFFFFFFFFLL) == 0 )
    return 1;
  if ( v1 < 0 && (v1 & 0xFFFFFFFFFFFFFLL) == 0x8000000000000LL )
    return 4;
  return ((v1 & 0x8000000000000LL) == 0) | 2u;
}


// ===== ?fp_format_a@@YAHQEBNPEAD_KQEAD2H_NIQEAU__crt_locale_pointers@@@Z @ 0x180010464 size=0x35d =====
__int64 __fastcall fp_format_a(
        const double *a1,
        char *a2,
        unsigned __int64 a3,
        char *const a4,
        unsigned __int64 a5,
        int a6,
        bool a7,
        unsigned int a8,
        struct __crt_locale_pointers *const a9)
{
  unsigned __int64 v9; // rbx
  char *v10; // rdi
  unsigned int v14; // ebx
  char *v15; // rax
  __int64 v16; // rbp
  char *v17; // rdi
  __m128i *v18; // r14
  __m128i *v19; // rdi
  __int16 v20; // r8
  unsigned __int64 v21; // r9
  unsigned __int16 v22; // ax
  __int8 *i; // rcx
  __int64 v24; // rcx
  __int8 *v25; // rdi
  __int8 *v26; // r8
  _QWORD v28[3]; // [rsp+50h] [rbp-38h] BYREF
  char v29; // [rsp+68h] [rbp-20h]

  v9 = (unsigned int)a6;
  v10 = a2;
  *a2 = 0;
  if ( a6 < 0 )
    v9 = 0;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v28, a9);
  if ( a3 <= (int)v9 + 11 )
  {
    v14 = 34;
    *errno() = 34;
    invalid_parameter_noinfo();
    goto LABEL_50;
  }
  if ( ((*(_QWORD *)a1 >> 52) & 0x7FFLL) == 0x7FF )
  {
    v14 = fp_format_e(a1, v10, a3, a4, a5, v9, false, a8, nullptr);
    if ( v14 != 0 )
    {
      *v10 = 0;
      goto LABEL_50;
    }
    v15 = strrchr(v10, 101);
    if ( v15 != nullptr )
    {
      *v15 = a7 ? 80 : 112;
      v15[3] = 0;
    }
  }
  else
  {
    if ( *(__int64 *)a1 < 0 )
      *v10++ = 45;
    v16 = 1023;
    if ( (*(_QWORD *)a1 & 0x7FF0000000000000LL) != 0 )
    {
      *v10 = 49;
      v17 = v10 + 1;
    }
    else
    {
      *v10 = 48;
      v17 = v10 + 1;
      v16 = (*(_QWORD *)a1 & 0xFFFFFFFFFFFFFLL) != 0 ? 0x3FE : 0;
    }
    v18 = (__m128i *)v17;
    v19 = (__m128i *)(v17 + 1);
    if ( (_DWORD)v9 != 0 )
      v18->m128i_i8[0] = ***(_BYTE ***)(v28[1] + 248LL);
    else
      v18->m128i_i8[0] = 0;
    if ( (*(_QWORD *)a1 & 0xFFFFFFFFFFFFFLL) != 0 )
    {
      v20 = 48;
      v21 = 0xF000000000000LL;
      do
      {
        if ( (int)v9 <= 0 )
          break;
        v22 = ((v21 & *(_QWORD *)a1 & 0xFFFFFFFFFFFFFLL) >> v20) + 48;
        if ( v22 > 0x39u )
          LOBYTE(v22) = (a7 ? 7 : 39) + v22;
        v19->m128i_i8[0] = v22;
        v9 = (unsigned int)(v9 - 1);
        v19 = (__m128i *)((char *)v19 + 1);
        v21 >>= 4;
        v20 -= 4;
      }
      while ( v20 >= 0 );
      if ( v20 >= 0 && (unsigned __int16)((v21 & *(_QWORD *)a1 & 0xFFFFFFFFFFFFFLL) >> v20) > 8u )
      {
        for ( i = &v19[-1].m128i_i8[15]; ((*i - 70) & 0xDF) == 0; --i )
          *i = 48;
        if ( i == (__int8 *)v18 )
        {
          ++*(i - 1);
        }
        else if ( *i == 57 )
        {
          *i = a7 ? 65 : 97;
        }
        else
        {
          ++*i;
        }
      }
    }
    if ( (int)v9 > 0 )
    {
      sub_180009D50(v19, 0x30u, v9);
      v19 = (__m128i *)((char *)v19 + v9);
    }
    if ( v18->m128i_i8[0] == 0 )
      v19 = v18;
    v19->m128i_i8[0] = a7 ? 80 : 112;
    v24 = ((*(_QWORD *)a1 >> 52) & 0x7FFLL) - v16;
    if ( v24 < 0 )
    {
      v19->m128i_i8[1] = 45;
      v25 = &v19->m128i_i8[2];
      v24 = -v24;
    }
    else
    {
      v19->m128i_i8[1] = 43;
      v25 = &v19->m128i_i8[2];
    }
    *v25 = 48;
    v26 = v25;
    if ( v24 >= 1000 && (*v25 = v24 / 1000 + 48, ++v25, v24 %= 1000, v25 != v26) || v24 >= 100 )
    {
      *v25++ = v24 / 100 + 48;
      v24 %= 100;
    }
    if ( v25 != v26 || v24 >= 10 )
    {
      *v25++ = v24 / 10 + 48;
      v24 %= 10;
    }
    *v25 = v24 + 48;
    v25[1] = 0;
  }
  v14 = 0;
LABEL_50:
  if ( v29 != 0 )
    *(_DWORD *)(v28[0] + 936LL) &= ~2u;
  return v14;
}


// ===== ?fp_format_e@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z @ 0x1800107c4 size=0xcd =====
int __fastcall fp_format_e(
        const double *const a1,
        char *const a2,
        unsigned __int64 a3,
        char *const a4,
        unsigned __int64 a5,
        int a6,
        bool a7,
        unsigned int a8,
        struct __crt_locale_pointers *const a9)
{
  _BOOL8 v11; // rcx
  _BOOL8 v12; // rax
  __int64 v13; // rdx
  int result; // eax
  _DWORD v15[6]; // [rsp+40h] [rbp-18h] BYREF

  _acrt_fltout(*(_QWORD *)a1, (unsigned int)(a6 + 1), v15, a4, a5);
  v11 = v15[0] == 45;
  v12 = a6 > 0;
  v13 = a3 - v12 - v11;
  if ( a3 == -1 )
    v13 = -1;
  result = _acrt_fp_strflt_to_string(&a2[v12 + v11], v13, (unsigned int)(a6 + 1), v15);
  if ( result == 0 )
    return fp_format_e_internal(a2, a3, a6, a7, a8, (struct _strflt *const)v15, false, a9);
  *a2 = 0;
  return result;
}


// ===== ?fp_format_e_internal@@YAHQEAD_KH_NIQEAU_strflt@@2QEAU__crt_locale_pointers@@@Z @ 0x180010894 size=0x1db =====
__int64 __fastcall fp_format_e_internal(
        char *const a1,
        unsigned __int64 a2,
        int a3,
        char a4,
        unsigned int a5,
        struct _strflt *const a6,
        bool a7,
        struct __crt_locale_pointers *const a8)
{
  int v8; // eax
  __int64 v9; // rbx
  const __m128i *v14; // rdx
  __int64 v15; // r8
  char *v16; // rdx
  char *v17; // rbx
  rsize_t v18; // rdx
  __m128i *v19; // rcx
  int v20; // r8d
  _QWORD v21[3]; // [rsp+30h] [rbp-28h] BYREF
  char v22; // [rsp+48h] [rbp-10h]

  v8 = 0;
  v9 = a3;
  if ( a3 > 0 )
    v8 = a3;
  if ( a2 > v8 + 9 )
  {
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v21, a8);
    if ( a7 )
    {
      v14 = (const __m128i *)&a1[*(_DWORD *)a6 == 45];
      if ( (int)v9 > 0 )
      {
        v15 = -1;
        do
          ++v15;
        while ( v14->m128i_i8[v15] != 0 );
        sub_1800098F0((__m128i *)((char *)v14 + ((int)v9 > 0)), v14, v15 + 1);
      }
    }
    v16 = a1;
    if ( *(_DWORD *)a6 == 45 )
    {
      *a1 = 45;
      v16 = a1 + 1;
    }
    if ( (int)v9 > 0 )
    {
      *v16 = v16[1];
      *++v16 = ***(_BYTE ***)(v21[1] + 248LL);
    }
    v17 = &v16[v9 + !a7];
    v18 = a1 - v17 + a2;
    if ( a2 == -1 )
      v18 = -1;
    if ( strcpy_s(v17, v18, "e+000") != 0 )
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
    v19 = (__m128i *)(v17 + 2);
    if ( a4 != 0 )
      *v17 = 69;
    if ( **((_BYTE **)a6 + 1) != 48 )
    {
      v20 = *((_DWORD *)a6 + 1) - 1;
      if ( v20 < 0 )
      {
        v20 = 1 - *((_DWORD *)a6 + 1);
        v17[1] = 45;
      }
      if ( v20 >= 100 )
      {
        v17[2] += v20 / 100;
        v20 %= 100;
      }
      if ( v20 >= 10 )
      {
        v17[3] += v20 / 10;
        LOBYTE(v20) = v20 % 10;
      }
      v17[4] += v20;
    }
    if ( a5 == 2 && v19->m128i_i8[0] == 48 )
      sub_1800098F0(v19, (const __m128i *)(v17 + 3), 3u);
    if ( v22 != 0 )
      *(_DWORD *)(v21[0] + 936LL) &= ~2u;
    return 0;
  }
  else
  {
    *errno() = 34;
    invalid_parameter_noinfo();
    return 34;
  }
}


// ===== ?fp_format_f_internal@@YAHQEAD_KHQEAU_strflt@@_NQEAU__crt_locale_pointers@@@Z @ 0x180010a70 size=0x148 =====
__int64 __fastcall fp_format_f_internal(
        char *const a1,
        __int64 a2,
        int a3,
        struct _strflt *const a4,
        bool a5,
        struct __crt_locale_pointers *const a6)
{
  int v9; // ecx
  __int64 v10; // rsi
  __int64 v11; // r8
  char *v12; // rbx
  char *v13; // rbp
  __int64 v14; // r8
  int v15; // ecx
  _QWORD v17[3]; // [rsp+20h] [rbp-28h] BYREF
  char v18; // [rsp+38h] [rbp-10h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v17, a6);
  v9 = *((_DWORD *)a4 + 1) - 1;
  if ( a5 && v9 == a3 )
    *(_WORD *)&a1[(*(_DWORD *)a4 == 45) + v9] = 48;
  if ( *(_DWORD *)a4 == 45 )
    *a1++ = 45;
  v10 = -1;
  if ( *((int *)a4 + 1) > 0 )
  {
    v12 = &a1[*((int *)a4 + 1)];
  }
  else
  {
    v11 = -1;
    do
      ++v11;
    while ( a1[v11] != 0 );
    sub_1800098F0((__m128i *)(a1 + 1), (const __m128i *)a1, v11 + 1);
    *a1 = 48;
    v12 = a1 + 1;
  }
  if ( a3 > 0 )
  {
    v13 = v12 + 1;
    v14 = -1;
    do
      ++v14;
    while ( v12[v14] != 0 );
    sub_1800098F0((__m128i *)(v12 + 1), (const __m128i *)v12, v14 + 1);
    *v12 = ***(_BYTE ***)(v17[1] + 248LL);
    v15 = *((_DWORD *)a4 + 1);
    if ( v15 < 0 )
    {
      if ( a5 || -v15 < a3 )
        a3 = -v15;
      if ( a3 != 0 )
      {
        do
          ++v10;
        while ( v13[v10] != 0 );
        sub_1800098F0((__m128i *)&v13[a3], (const __m128i *)(v12 + 1), v10 + 1);
      }
      sub_180009D50((__m128i *)(v12 + 1), 0x30u, a3);
    }
  }
  if ( v18 != 0 )
    *(_DWORD *)(v17[0] + 936LL) &= ~2u;
  return 0;
}


// ===== ?fp_format_g@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z @ 0x180010bb8 size=0x137 =====
__int64 __fastcall fp_format_g(
        const double *const a1,
        char *const a2,
        unsigned __int64 a3,
        char *const a4,
        unsigned __int64 a5,
        unsigned int a6,
        char a7,
        unsigned int a8,
        struct __crt_locale_pointers *const a9)
{
  __int64 v9; // rcx
  _BOOL8 v12; // rcx
  int v13; // r14d
  __int64 v14; // rdx
  char *v15; // rbx
  __int64 result; // rax
  int v17; // eax
  char v18; // al
  _QWORD v19[3]; // [rsp+40h] [rbp-18h] BYREF

  v9 = *(_QWORD *)a1;
  v19[0] = 0;
  v19[1] = 0;
  _acrt_fltout(v9, a6, v19, a4, a5);
  v12 = LODWORD(v19[0]) == 45;
  v13 = HIDWORD(v19[0]) - 1;
  v14 = a3 - v12;
  v15 = &a2[v12];
  if ( a3 == -1 )
    v14 = -1;
  result = _acrt_fp_strflt_to_string(&a2[v12], v14, a6, v19);
  if ( (_DWORD)result != 0 )
  {
    *a2 = 0;
  }
  else
  {
    v17 = HIDWORD(v19[0]) - 1;
    if ( HIDWORD(v19[0]) - 1 < -4 || v17 >= (int)a6 )
    {
      return fp_format_e_internal(a2, a3, a6, a7, a8, (struct _strflt *const)v19, true, a9);
    }
    else
    {
      if ( v13 < v17 )
      {
        do
          v18 = *v15++;
        while ( v18 != 0 );
        *(v15 - 2) = 0;
      }
      return fp_format_f_internal(a2, a3, a6, (struct _strflt *const)v19, true, a9);
    }
  }
  return result;
}


// ===== ?fp_format_nan_or_infinity@@YAHW4__acrt_fp_class@@_NPEAD_K1@Z @ 0x180010cf0 size=0x142 =====
errno_t __fastcall fp_format_nan_or_infinity(int a1, unsigned __int8 a2, char *a3, rsize_t a4, char a5)
{
  char *v6; // r9
  errno_t result; // eax
  __int64 v8; // rdx
  unsigned __int64 v9; // rax
  char *Source[16]; // [rsp+30h] [rbp-41h]

  v6 = a3;
  if ( a4 >= (unsigned __int64)a2 + 4 )
  {
    if ( a2 != 0 )
    {
      v6 = a3 + 1;
      *a3 = 45;
      --a4;
      a3[1] = 0;
    }
    Source[4] = (char *)&unk_18001CA78;
    Source[5] = (char *)&unk_18001CA78;
    Source[0] = (char *)&unk_18001CA70;
    Source[1] = (char *)&unk_18001CA70;
    Source[2] = (char *)&unk_18001CA74;
    Source[3] = (char *)&unk_18001CA74;
    Source[8] = "NAN(SNAN)";
    Source[10] = "nan(snan)";
    Source[12] = "NAN(IND)";
    Source[14] = "nan(ind)";
    Source[9] = (char *)&unk_18001CA78;
    Source[13] = (char *)&unk_18001CA78;
    Source[6] = (char *)&unk_18001CA7C;
    v8 = 4LL * (unsigned int)(a1 - 1);
    Source[7] = (char *)&unk_18001CA7C;
    Source[11] = (char *)&unk_18001CA7C;
    Source[15] = (char *)&unk_18001CA7C;
    v9 = -1;
    do
      ++v9;
    while ( (&Source[v8])[a5 != 0 ? 0 : 2][v9] != 0 );
    result = strcpy_s(v6, a4, (&(&Source[v8])[a5 != 0 ? 0 : 2])[a4 <= v9]);
    if ( result != 0 )
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  }
  else
  {
    *a3 = 0;
    return 12;
  }
  return result;
}


// ===== __acrt_fp_format @ 0x180010e34 size=0x241 =====
errno_t __fastcall _acrt_fp_format(
        double *a1,
        char *a2,
        rsize_t a3,
        char *a4,
        unsigned __int64 a5,
        int a6,
        unsigned int a7,
        __int64 a8,
        struct __crt_locale_pointers *a9)
{
  errno_t result; // eax
  bool v14; // r14
  int v15; // eax
  unsigned int v16; // edi
  __int64 v17; // rcx
  _BOOL8 v18; // rcx
  __int64 v19; // rdx
  _QWORD v20[2]; // [rsp+50h] [rbp-38h] BYREF

  if ( a2 == nullptr || a3 == 0 || a4 == nullptr || a5 == 0 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
  v14 = a6 == 65 || (unsigned int)(a6 - 69) <= 2;
  if ( (a8 & 8) == 0 )
  {
    v15 = __acrt_fp_classify((__int64 *)a1);
    if ( v15 != 0 )
      return fp_format_nan_or_infinity(v15, *(__int64 *)a1 < 0, a2, a3, v14);
  }
  v16 = ((a8 & 0x10) != 0) | 2;
  if ( a6 == 65 )
    return fp_format_a(a1, a2, a3, a4, a5, a7, v14, v16, a9);
  if ( a6 == 69 )
    return fp_format_e(a1, a2, a3, a4, a5, a7, v14, v16, a9);
  if ( a6 != 70 )
  {
    if ( a6 == 71 )
      return fp_format_g(a1, a2, a3, a4, a5, a7, v14, v16, a9);
    if ( a6 != 97 )
    {
      if ( a6 != 101 )
      {
        if ( a6 != 102 )
          return fp_format_g(a1, a2, a3, a4, a5, a7, v14, v16, a9);
        goto LABEL_21;
      }
      return fp_format_e(a1, a2, a3, a4, a5, a7, v14, v16, a9);
    }
    return fp_format_a(a1, a2, a3, a4, a5, a7, v14, v16, a9);
  }
LABEL_21:
  v17 = *(_QWORD *)a1;
  v20[0] = 0;
  v20[1] = 0;
  _acrt_fltout(v17, a7, v20, a4, a5);
  v18 = LODWORD(v20[0]) == 45;
  v19 = a3 - v18;
  if ( a3 == -1 )
    v19 = -1;
  result = _acrt_fp_strflt_to_string(&a2[v18], v19, a7 + HIDWORD(v20[0]), v20);
  if ( result == 0 )
    return fp_format_f_internal(a2, a3, a7, (struct _strflt *const)v20, false, a9);
  *a2 = 0;
  return result;
}


// ===== __acrt_initialize_stdio @ 0x180011078 size=0x11f =====
__int64 _acrt_initialize_stdio()
{
  int v0; // eax
  __int64 v1; // rbx
  __int64 v2; // rdi
  __int64 v4; // r14
  _DWORD *v5; // rsi
  char *v6; // rbp

  v0 = dword_18002ABB8;
  v1 = 0;
  v2 = 3;
  if ( dword_18002ABB8 != 0 )
  {
    if ( dword_18002ABB8 < 3 )
      v0 = 3;
  }
  else
  {
    v0 = 512;
  }
  dword_18002ABB8 = v0;
  qword_18002ABC0 = calloc_base(v0, 8u);
  free_base(nullptr);
  if ( qword_18002ABC0 == nullptr )
  {
    dword_18002ABB8 = 3;
    qword_18002ABC0 = calloc_base(3u, 8u);
    free_base(nullptr);
    if ( qword_18002ABC0 == nullptr )
      return 0xFFFFFFFFLL;
  }
  v4 = 0;
  v5 = &unk_1800292D8;
  v6 = (char *)&unk_1800292C0;
  do
  {
    _acrt_InitializeCriticalSectionEx((LPCRITICAL_SECTION)(v6 + 48), 0xFA0u);
    *(_QWORD *)((char *)qword_18002ABC0 + v4) = v6;
    if ( *(_QWORD *)(qword_18002ABF0[v1 >> 6] + ((unsigned __int64)(v1 & 0x3F) << 6) + 40) >= 0xFFFFFFFFFFFFFFFEuLL
      || *(_QWORD *)(qword_18002ABF0[v1 >> 6] + ((unsigned __int64)(v1 & 0x3F) << 6) + 40) == 0 )
    {
      *v5 = -2;
    }
    ++v1;
    v6 += 88;
    v4 += 8;
    v5 += 22;
    --v2;
  }
  while ( v2 != 0 );
  return 0;
}


// ===== __acrt_uninitialize_stdio @ 0x180011198 size=0x5b =====
void _acrt_uninitialize_stdio()
{
  __int64 i; // rbx

  flushall();
  fcloseall();
  for ( i = 0; i != 24; i += 8 )
  {
    _acrt_stdio_free_buffer_nolock(*(_QWORD *)((char *)qword_18002ABC0 + i));
    DeleteCriticalSection((LPCRITICAL_SECTION)(*(_QWORD *)((char *)qword_18002ABC0 + i) + 48LL));
  }
  free_base(qword_18002ABC0);
  qword_18002ABC0 = nullptr;
}


// ===== sub_1800111F4 @ 0x1800111f4 size=0xb =====
void __fastcall sub_1800111F4(__int64 a1)
{
  EnterCriticalSection((LPCRITICAL_SECTION)(a1 + 48));
}


// ===== sub_180011200 @ 0x180011200 size=0xb =====
void __fastcall sub_180011200(__int64 a1)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)(a1 + 48));
}


// ===== _get_printf_count_output @ 0x18001120c size=0x18 =====
int __cdecl get_printf_count_output()
{
  return qword_18002ABC8 == (_security_cookie | 1);
}


// ===== __acrt_set_locale_changed @ 0x180011224 size=0xc =====
// Microsoft VisualC v7/14 64bit runtime
__int64 _acrt_set_locale_changed()
{
  return (unsigned int)_InterlockedExchange(&dword_18002ABE0, 1);
}


// ===== __acrt_uninitialize_locale @ 0x180011230 size=0x47 =====
void _acrt_uninitialize_locale()
{
  if ( (wchar_t **)qword_18002ABE8 != &off_1800293D0 )
  {
    sub_180011524(4);
    qword_18002ABE8 = updatetlocinfoEx_nolock(&qword_18002ABE8, &off_1800293D0);
    sub_180011578(4);
  }
}


// ===== ?initialize_inherited_file_handles_nolock@@YAXXZ @ 0x180011278 size=0xeb =====
void __fastcall initialize_inherited_file_handles_nolock()
{
  LPBYTE v0; // rsi
  __int64 v1; // rdi
  HANDLE *v2; // rbx
  __int64 v3; // rbp
  __int64 v4; // rcx
  struct _STARTUPINFOW v5; // [rsp+20h] [rbp-78h] BYREF

  GetStartupInfoW(&v5);
  if ( v5.cbReserved2 != 0 && v5.lpReserved2 != nullptr )
  {
    v0 = v5.lpReserved2 + 4;
    v1 = 0x2000;
    v2 = (HANDLE *)&v5.lpReserved2[*(_DWORD *)v5.lpReserved2 + 4];
    if ( *(int *)v5.lpReserved2 < 0x2000 )
      v1 = *(unsigned int *)v5.lpReserved2;
    _acrt_lowio_ensure_fh_exists((unsigned int)v1);
    if ( (int)v1 > dword_18002AFF0 )
      v1 = (unsigned int)dword_18002AFF0;
    if ( (_DWORD)v1 != 0 )
    {
      v3 = 0;
      do
      {
        if ( *v2 != (HANDLE)-1LL && *v2 != (HANDLE)-2LL && (*v0 & 1) != 0 && ((*v0 & 8) != 0 || GetFileType(*v2) != 0) )
        {
          v4 = qword_18002ABF0[v3 >> 6] + ((unsigned __int64)(v3 & 0x3F) << 6);
          *(_QWORD *)(v4 + 40) = *v2;
          *(_BYTE *)(v4 + 56) = *v0;
        }
        ++v3;
        ++v0;
        ++v2;
        --v1;
      }
      while ( v1 != 0 );
    }
  }
}


// ===== ?initialize_stdio_handles_nolock@@YAXXZ @ 0x180011364 size=0xfb =====
void __fastcall initialize_stdio_handles_nolock()
{
  int v0; // edi
  __int64 v1; // r14
  unsigned __int64 v2; // rbx
  DWORD v3; // ecx
  HANDLE StdHandle; // rax
  HANDLE v5; // rsi
  DWORD FileType; // eax

  v0 = 0;
  v1 = 0;
  do
  {
    v2 = qword_18002ABF0[(__int64)v0 >> 6] + ((unsigned __int64)(v0 & 0x3F) << 6);
    if ( *(_QWORD *)(v2 + 40) == -2 || *(_QWORD *)(v2 + 40) == -1 )
    {
      *(_BYTE *)(v2 + 56) = -127;
      if ( v0 != 0 )
      {
        if ( v0 == 1 )
          v3 = -11;
        else
          v3 = -12;
      }
      else
      {
        v3 = -10;
      }
      StdHandle = GetStdHandle(v3);
      v5 = StdHandle;
      if ( (unsigned __int64)StdHandle + 1 <= 1 )
        FileType = 0;
      else
        FileType = GetFileType(StdHandle);
      if ( FileType != 0 )
      {
        *(_QWORD *)(v2 + 40) = v5;
        if ( (unsigned __int8)FileType == 2 )
        {
          *(_BYTE *)(v2 + 56) |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          *(_BYTE *)(v2 + 56) |= 8u;
        }
      }
      else
      {
        *(_BYTE *)(v2 + 56) |= 0x40u;
        *(_QWORD *)(v2 + 40) = -2;
        if ( qword_18002ABC0 != nullptr )
          *(_DWORD *)(*(_QWORD *)((char *)qword_18002ABC0 + v1) + 24LL) = -2;
      }
    }
    else
    {
      *(_BYTE *)(v2 + 56) |= 0x80u;
    }
    ++v0;
    v1 += 8;
  }
  while ( v0 != 3 );
}


// ===== __acrt_initialize_lowio @ 0x180011460 size=0x3b =====
char _acrt_initialize_lowio()
{
  char v0; // bl

  sub_180011524(7);
  v0 = 0;
  if ( (unsigned int)_acrt_lowio_ensure_fh_exists(0) == 0 )
  {
    initialize_inherited_file_handles_nolock();
    initialize_stdio_handles_nolock();
    v0 = 1;
  }
  sub_180011578(7);
  return v0;
}


// ===== __acrt_uninitialize_lowio @ 0x18001149c size=0x40 =====
char _acrt_uninitialize_lowio()
{
  unsigned __int64 i; // rbx
  void *v1; // rcx

  for ( i = 0; i < 128; ++i )
  {
    v1 = (void *)qword_18002ABF0[i];
    if ( v1 != nullptr )
    {
      _acrt_lowio_destroy_handle_array(v1);
      qword_18002ABF0[i] = 0;
    }
  }
  return 1;
}


// ===== __vcrt_initialize_locks_0 @ 0x1800114dc size=0x48 =====
char _vcrt_initialize_locks_0()
{
  __int64 v0; // rbx

  v0 = 0;
  while ( (unsigned int)_acrt_InitializeCriticalSectionEx((LPCRITICAL_SECTION)&unk_18002B000 + v0, 0xFA0u) != 0 )
  {
    ++dword_18002B208;
    v0 = (unsigned int)(v0 + 1);
    if ( (unsigned int)v0 >= 0xD )
      return 1;
  }
  _vcrt_uninitialize_locks_0(0);
  return 0;
}


// ===== sub_180011524 @ 0x180011524 size=0x19 =====
void __fastcall sub_180011524(int a1)
{
  EnterCriticalSection((LPCRITICAL_SECTION)&unk_18002B000 + a1);
}


// ===== __vcrt_uninitialize_locks_0 @ 0x180011540 size=0x37 =====
char _vcrt_uninitialize_locks_0()
{
  int v0; // ebx

  v0 = dword_18002B208;
  while ( v0 != 0 )
  {
    DeleteCriticalSection((LPCRITICAL_SECTION)&unk_18002B000 + (unsigned int)--v0);
    --dword_18002B208;
  }
  return 1;
}


// ===== sub_180011578 @ 0x180011578 size=0x19 =====
void __fastcall sub_180011578(int a1)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)&unk_18002B000 + a1);
}


// ===== ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z @ 0x180011594 size=0x1a0 =====
FARPROC __fastcall try_get_function(unsigned int a1, const CHAR *a2, unsigned int *a3, unsigned int *a4)
{
  __int64 v4; // r14
  unsigned int *v6; // rbp
  uintptr_t v8; // r10
  __int64 v9; // rdx
  FARPROC result; // rax
  __int64 v11; // rsi
  HMODULE Library; // rbx
  const WCHAR *v13; // r15

  v4 = a1;
  v6 = a3;
  v8 = _security_cookie;
  v9 = __ROR8__(qword_18002B2B0[a1] ^ _security_cookie, _security_cookie & 0x3F);
  if ( v9 == -1 )
    return nullptr;
  if ( v9 != 0 )
    return (FARPROC)v9;
  if ( a3 == a4 )
  {
LABEL_19:
    Library = nullptr;
    goto LABEL_20;
  }
  while ( 1 )
  {
    v11 = *v6;
    Library = (HMODULE)qword_18002B210[v11];
    if ( Library == nullptr )
      break;
    if ( Library != (HMODULE)-1LL )
      goto LABEL_23;
LABEL_17:
    if ( ++v6 == a4 )
    {
      v8 = _security_cookie;
      goto LABEL_19;
    }
  }
  v13 = off_18001D150[v11];
  Library = LoadLibraryExW(v13, nullptr, 0x800u);
  if ( Library == nullptr )
  {
    if ( GetLastError() == 87 )
      Library = LoadLibraryExW(v13, nullptr, 0);
    else
      Library = nullptr;
  }
  if ( Library == nullptr )
  {
    _InterlockedExchange64(&qword_18002B210[v11], -1);
    goto LABEL_17;
  }
  if ( _InterlockedExchange64(&qword_18002B210[v11], (__int64)Library) != 0 )
    FreeLibrary(Library);
LABEL_23:
  v8 = _security_cookie;
LABEL_20:
  if ( Library != nullptr )
  {
    result = GetProcAddress(Library, a2);
    if ( result != nullptr )
    {
      _InterlockedExchange64(
        &qword_18002B2B0[v4],
        _security_cookie ^ __ROR8__(result, 64 - ((unsigned __int8)_security_cookie & 0x3Fu)));
      return result;
    }
    v8 = _security_cookie;
  }
  _InterlockedExchange64(&qword_18002B2B0[v4], v8 ^ __ROR8__(-1, 64 - ((unsigned __int8)v8 & 0x3Fu)));
  return nullptr;
}


// ===== __acrt_FlsAlloc @ 0x180011734 size=0x55 =====
DWORD __fastcall _acrt_FlsAlloc(__int64 a1)
{
  FARPROC function; // rax

  function = try_get_function(3u, "FlsAlloc", (unsigned int *)&unk_18001D730, (unsigned int *)"FlsAlloc");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(__int64))function)(a1);
  else
    return TlsAlloc();
}


// ===== __acrt_FlsFree @ 0x18001178c size=0x55 =====
int __fastcall _acrt_FlsFree(DWORD dwTlsIndex)
{
  FARPROC function; // rax

  function = try_get_function(4u, "FlsFree", (unsigned int *)&unk_18001D748, (unsigned int *)"FlsFree");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(_QWORD))function)(dwTlsIndex);
  else
    return TlsFree(dwTlsIndex);
}


// ===== __vcrt_FlsFree_0 @ 0x1800117e4 size=0x55 =====
LPVOID __fastcall _vcrt_FlsFree_0(DWORD dwTlsIndex)
{
  FARPROC function; // rax

  function = try_get_function(5u, "FlsGetValue", (unsigned int *)&unk_18001D758, (unsigned int *)"FlsGetValue");
  if ( function != nullptr )
    return (LPVOID)((__int64 (__fastcall *)(_QWORD))function)(dwTlsIndex);
  else
    return TlsGetValue(dwTlsIndex);
}


// ===== __acrt_FlsSetValue @ 0x18001183c size=0x68 =====
int __fastcall _acrt_FlsSetValue(DWORD dwTlsIndex, LPVOID lpTlsValue)
{
  FARPROC function; // rax

  function = try_get_function(6u, "FlsSetValue", (unsigned int *)&unk_18001D770, (unsigned int *)"FlsSetValue");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(_QWORD, LPVOID))function)(dwTlsIndex, lpTlsValue);
  else
    return TlsSetValue(dwTlsIndex, lpTlsValue);
}


// ===== __acrt_InitializeCriticalSectionEx @ 0x1800118a4 size=0x78 =====
int __fastcall _acrt_InitializeCriticalSectionEx(
        LPCRITICAL_SECTION lpCriticalSection,
        DWORD dwSpinCount,
        unsigned int a3)
{
  FARPROC function; // rax

  function = try_get_function(
               0x14u,
               "InitializeCriticalSectionEx",
               (unsigned int *)"\b",
               (unsigned int *)"InitializeCriticalSectionEx");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(LPCRITICAL_SECTION, _QWORD, _QWORD))function)(lpCriticalSection, dwSpinCount, a3);
  else
    return InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
}


// ===== __acrt_LCMapStringEx @ 0x18001191c size=0xef =====
int __fastcall _acrt_LCMapStringEx(
        __int64 a1,
        DWORD a2,
        const WCHAR *a3,
        unsigned int a4,
        WCHAR *lpDestStr,
        int cchDest,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  FARPROC function; // rbx
  LCID v15; // eax

  function = try_get_function(0x16u, "LCMapStringEx", (unsigned int *)&unk_18001D7D0, (unsigned int *)"LCMapStringEx");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(__int64, _QWORD, const WCHAR *, _QWORD, WCHAR *, int, __int64, __int64, __int64))function)(
             a1,
             a2,
             a3,
             a4,
             lpDestStr,
             cchDest,
             a7,
             a8,
             a9);
  v15 = _acrt_LocaleNameToLCID(a1, 0);
  return LCMapStringW(v15, a2, a3, a4, lpDestStr, cchDest);
}


// ===== __acrt_LocaleNameToLCID @ 0x180011a0c size=0x65 =====
__int64 __fastcall _acrt_LocaleNameToLCID(__int64 a1, unsigned int a2)
{
  FARPROC function; // rax

  function = try_get_function(
               0x18u,
               "LocaleNameToLCID",
               (unsigned int *)&unk_18001D7E8,
               (unsigned int *)"LocaleNameToLCID");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(__int64, _QWORD))function)(a1, a2);
  else
    return _crtDownlevelLocaleNameToLCID(a1);
}


// ===== __acrt_initialize_winapi_thunks @ 0x180011a74 size=0x37 =====
char _acrt_initialize_winapi_thunks()
{
  memset64(qword_18002B2B0, _security_cookie ^ __ROR8__(0, 64 - ((unsigned __int8)_security_cookie & 0x3Fu)), 0x20u);
  return 1;
}


// ===== __acrt_is_packaged_app @ 0x180011aac size=0x85 =====
bool _acrt_is_packaged_app()
{
  FARPROC function; // rax
  int v2; // [rsp+30h] [rbp+8h] BYREF

  if ( dword_18002B3B0 != 0 )
    return dword_18002B3B0 == 1;
  function = try_get_function(
               8u,
               "GetCurrentPackageId",
               (unsigned int *)&unk_18001D788,
               (unsigned int *)"GetCurrentPackageId");
  if ( function != nullptr && (v2 = 0, ((unsigned int (__fastcall *)(int *, _QWORD))function)(&v2, 0) == 122) )
  {
    _InterlockedExchange(&dword_18002B3B0, 1);
    return true;
  }
  else
  {
    _InterlockedExchange(&dword_18002B3B0, 2);
    return false;
  }
}


// ===== __acrt_uninitialize_winapi_thunks @ 0x180011b34 size=0x41 =====
char __fastcall _acrt_uninitialize_winapi_thunks(char a1)
{
  __int64 *v1; // rbx
  HMODULE v2; // rcx

  if ( a1 == 0 )
  {
    v1 = qword_18002B210;
    do
    {
      v2 = (HMODULE)*v1;
      if ( *v1 != 0 )
      {
        if ( v2 != (HMODULE)-1LL )
          FreeLibrary(v2);
        *v1 = 0;
      }
      ++v1;
    }
    while ( v1 != qword_18002B2B0 );
  }
  return 1;
}


// ===== _calloc_base @ 0x180011b78 size=0x75 =====
void *__cdecl calloc_base(size_t Count, size_t Size)
{
  SIZE_T v2; // rbx
  void *result; // rax

  if ( Count != 0 && 0xFFFFFFFFFFFFFFE0uLL / Count < Size )
  {
LABEL_10:
    *errno() = 12;
    return nullptr;
  }
  else
  {
    v2 = Size * Count;
    if ( Size * Count == 0 )
      v2 = 1;
    while ( 1 )
    {
      result = HeapAlloc(hHeap, 8u, v2);
      if ( result != nullptr )
        break;
      if ( (unsigned int)sub_180014018() == 0 || callnewh(v2) == 0 )
        goto LABEL_10;
    }
  }
  return result;
}


// ===== unknown_libname_57 @ 0x180011bf0 size=0x12 =====
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_57(const void *a1, const void *a2)
{
  if ( a1 >= a2 )
    return a1 > a2;
  else
    return 0xFFFFFFFFLL;
}


// ===== ??$common_expand_argv_wildcards@D@@YAHQEAPEADQEAPEAPEAD@Z @ 0x180011c04 size=0x209 =====
__int64 __fastcall common_expand_argv_wildcards<char>(char **a1, _QWORD *a2)
{
  char **v2; // rbx
  bool i; // zf
  char *v5; // rcx
  __int64 v6; // rax
  char *v7; // rcx
  unsigned int v8; // eax
  unsigned int v9; // r14d
  char *buffer_for_argv; // rax
  char *v11; // rdx
  __int64 v13; // [rsp+B0h] [rbp+50h] BYREF
  char *v14; // [rsp+B8h] [rbp+58h]

  v2 = a1;
  if ( a2 != nullptr )
  {
    *a2 = 0;
    for ( i = *a1 == nullptr; !i; i = *v2 == nullptr )
    {
      v5 = *v2;
      strcpy((char *)&v13, "*?");
      v6 = unknown_libname_59(v5, &v13);
      v7 = *v2;
      if ( v6 != 0 )
        v8 = expand_argument_wildcards<char>(v7);
      else
        v8 = copy_and_add_argument_to_buffer<char>(v7, nullptr, 0);
      v9 = v8;
      if ( v8 != 0 )
        goto LABEL_14;
      ++v2;
    }
    v13 = 0;
    v9 = -1;
    buffer_for_argv = (char *)_acrt_allocate_buffer_for_argv(1u, 0, 1u);
    if ( buffer_for_argv != nullptr )
    {
      v11 = buffer_for_argv + 8;
      v14 = v11;
      v9 = 0;
      *a2 = buffer_for_argv;
    }
    free_base(nullptr);
LABEL_14:
    free_base(nullptr);
    return v9;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
}


// ===== ??$copy_and_add_argument_to_buffer@D@@YAHQEBD0_KAEAV?$argument_list@D@?A0x7b96f60e@@@Z @ 0x180011e10 size=0x10f =====
__int64 __fastcall copy_and_add_argument_to_buffer<char>(char *Source, char *a2, rsize_t MaxCount, __int64 a4)
{
  __int64 v5; // rdi
  rsize_t v9; // rdi
  size_t v11; // r14
  char *v12; // rax
  char *v13; // rbx
  unsigned int v14; // edi

  v5 = -1;
  do
    ++v5;
  while ( Source[v5] != 0 );
  v9 = v5 + 1;
  if ( v9 > -1LL - MaxCount )
    return 12;
  v11 = v9 + MaxCount + 1;
  v12 = (char *)calloc_base(v11, 1u);
  v13 = v12;
  if ( MaxCount != 0 && strncpy_s(v12, v11, a2, MaxCount) != 0 )
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  if ( strncpy_s(&v13[MaxCount], v11 - MaxCount, Source, v9) != 0 )
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  v14 = unknown_libname_58(a4);
  if ( v14 != 0 )
  {
    free_base(v13);
  }
  else
  {
    **(_QWORD **)(a4 + 8) = v13;
    *(_QWORD *)(a4 + 8) += 8LL;
    v14 = 0;
  }
  free_base(nullptr);
  return v14;
}


// ===== ??$expand_argument_wildcards@D@@YAHQEAD0AEAV?$argument_list@D@?A0x7b96f60e@@@Z @ 0x180011f20 size=0x1ac =====
__int64 __fastcall expand_argument_wildcards<char>(char *a1, unsigned __int8 *a2, _QWORD *a3)
{
  __int64 i; // rbx
  unsigned __int8 v6; // al
  unsigned __int8 v8; // cl
  unsigned int v9; // edi
  char v10; // al
  rsize_t v11; // r15
  HANDLE FirstFile; // rbx
  unsigned int v13; // eax
  __int64 v14; // rbp
  __int64 v15; // rdx
  struct _WIN32_FIND_DATAA FindFileData; // [rsp+30h] [rbp-178h] BYREF

  for ( i = 0x200000000801LL; a2 != (unsigned __int8 *)a1; a2 = mbsdec((const unsigned __int8 *)a1, a2) )
  {
    v6 = *a2 - 47;
    if ( v6 <= 0x2Du && _bittest64(&i, (char)v6) )
      break;
  }
  if ( *a2 == 58 && a2 != (unsigned __int8 *)(a1 + 1) )
    return copy_and_add_argument_to_buffer<char>(a1, nullptr, 0, (__int64)a3);
  v8 = *a2 - 47;
  v9 = 0;
  if ( v8 > 0x2Du || (v10 = 1, !_bittest64(&i, (char)v8)) )
    v10 = 0;
  v11 = (a2 - (unsigned __int8 *)a1 + 1) & -(__int64)(v10 != 0);
  sub_180009D50((__m128i *)&FindFileData, 0, 0x140u);
  FirstFile = FindFirstFileExA(a1, FindExInfoStandard, &FindFileData, FindExSearchNameMatch, nullptr, 0);
  if ( FirstFile == (HANDLE)-1LL )
  {
    v13 = copy_and_add_argument_to_buffer<char>(a1, nullptr, 0, (__int64)a3);
  }
  else
  {
    v14 = (__int64)(a3[1] - *a3) >> 3;
    while ( 1 )
    {
      if ( FindFileData.cFileName[0] != 46
        || FindFileData.cFileName[1] != 0 && (FindFileData.cFileName[1] != 46 || FindFileData.cFileName[2] != 0) )
      {
        v13 = copy_and_add_argument_to_buffer<char>(FindFileData.cFileName, a1, v11, (__int64)a3);
        if ( v13 != 0 )
          break;
      }
      if ( !FindNextFileA(FirstFile, &FindFileData) )
      {
        v15 = (__int64)(a3[1] - *a3) >> 3;
        if ( v14 != v15 )
          qsort((void *)(*a3 + 8 * v14), v15 - v14, 8u, (_CoreCrtNonSecureSearchSortCompareFunction)unknown_libname_57);
        goto LABEL_14;
      }
    }
  }
  v9 = v13;
LABEL_14:
  if ( FirstFile != (HANDLE)-1LL )
    FindClose(FirstFile);
  return v9;
}


// ===== unknown_libname_58 @ 0x1800120cc size=0xc7 =====
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_58(void **a1)
{
  _BYTE *v1; // rsi
  unsigned int v4; // ebx
  char *v5; // rax
  unsigned __int64 v6; // rsi
  char *v7; // rax

  v1 = a1[2];
  if ( a1[1] != v1 )
    return 0;
  v4 = 0;
  if ( *a1 == nullptr )
  {
    *a1 = calloc_base(4u, 8u);
    free_base(nullptr);
    v5 = (char *)*a1;
    if ( *a1 != nullptr )
    {
      a1[1] = v5;
      a1[2] = v5 + 32;
      return 0;
    }
    return 12;
  }
  v6 = (v1 - (_BYTE *)*a1) >> 3;
  if ( v6 > 0x7FFFFFFFFFFFFFFFLL )
    return 12;
  v7 = (char *)j__recalloc_base(*a1, 2 * v6, 8u);
  if ( v7 != nullptr )
  {
    *a1 = v7;
    a1[1] = &v7[8 * v6];
    a1[2] = &v7[16 * v6];
  }
  else
  {
    v4 = 12;
  }
  free_base(nullptr);
  return v4;
}


// ===== j_??$common_expand_argv_wildcards@D@@YAHQEAPEADQEAPEAPEAD@Z @ 0x180012194 size=0x5 =====
// attributes: thunk
__int64 __fastcall common_expand_argv_wildcards<char>(char **a1, _QWORD *a2)
{
  return ??$common_expand_argv_wildcards@D@@YAHQEAPEADQEAPEAPEAD@Z(a1, a2);
}


// ===== ??$?RV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@V_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@$$QEAV_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@Z @ 0x18001219c size=0x38 =====
void __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_99476a1ad63dd22509b5d3e65b0ffc95_,_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_ &,_lambda_f7424dd8d45958661754dc4f2697e9c3_>(
        __int64 a1,
        int *a2,
        __int64 a3,
        int *a4)
{
  sub_180011524(*a2);
  _lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_::operator()(a3);
  sub_180011578(*a4);
}


// ===== ??R_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@QEBAXXZ @ 0x1800121d4 size=0x217 =====
volatile signed __int32 *__fastcall _lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_::operator()(__int64 a1)
{
  __int64 v2; // rax
  __int64 v3; // rdi
  __m128i *v4; // rcx
  __m128i *v5; // rax
  __int64 i; // rdx
  __m128i v7; // xmm1
  __m128i *v8; // rcx
  __m128i *v9; // rax
  __m128i v10; // xmm1
  volatile signed __int32 *result; // rax

  dword_18002B3B4 = *(_DWORD *)(*(_QWORD *)(**(_QWORD **)a1 + 136LL) + 4LL);
  dword_18002B3B8 = *(_DWORD *)(*(_QWORD *)(**(_QWORD **)a1 + 136LL) + 8LL);
  qword_18002B3D0 = *(_QWORD *)(*(_QWORD *)(**(_QWORD **)a1 + 136LL) + 544LL);
  v2 = *(_QWORD *)(**(_QWORD **)a1 + 136LL) + 12LL;
  if ( *(_QWORD *)(**(_QWORD **)a1 + 136LL) == -12 )
  {
    qword_18002B3C0 = 0;
    dword_18002B3C8 = 0;
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  else
  {
    qword_18002B3C0 = *(_QWORD *)v2;
    dword_18002B3C8 = *(_DWORD *)(v2 + 8);
  }
  v3 = 2;
  v4 = xmmword_180029870;
  v5 = (__m128i *)(*(_QWORD *)(**(_QWORD **)a1 + 136LL) + 24LL);
  if ( *(_QWORD *)(**(_QWORD **)a1 + 136LL) == -24 )
  {
    sub_180009D50(xmmword_180029870, 0, 0x101u);
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  else
  {
    for ( i = 2; i != 0; --i )
    {
      *v4 = *v5;
      v4[1] = v5[1];
      v4[2] = v5[2];
      v4[3] = v5[3];
      v4[4] = v5[4];
      v4[5] = v5[5];
      v4[6] = v5[6];
      v4 += 8;
      v7 = v5[7];
      v5 += 8;
      v4[-1] = v7;
    }
    v4->m128i_i8[0] = v5->m128i_i8[0];
  }
  v8 = xmmword_180029980;
  v9 = (__m128i *)(*(_QWORD *)(**(_QWORD **)a1 + 136LL) + 281LL);
  if ( *(_QWORD *)(**(_QWORD **)a1 + 136LL) == -281 )
  {
    sub_180009D50(xmmword_180029980, 0, 0x100u);
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  else
  {
    do
    {
      *v8 = *v9;
      v8[1] = v9[1];
      v8[2] = v9[2];
      v8[3] = v9[3];
      v8[4] = v9[4];
      v8[5] = v9[5];
      v8[6] = v9[6];
      v8 += 8;
      v10 = v9[7];
      v9 += 8;
      v8[-1] = v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)Block, 0xFFFFFFFF) == 1 && Block != &unk_180029540 )
    free_base(Block);
  Block = *(void **)(**(_QWORD **)a1 + 136LL);
  result = *(volatile signed __int32 **)(**(_QWORD **)a1 + 136LL);
  _InterlockedIncrement(result);
  return result;
}


// ===== ?getSystemCP@@YAHH@Z @ 0x1800123ec size=0x7d =====
__int64 __fastcall getSystemCP(UINT a1)
{
  UINT OEMCP; // eax
  _QWORD v4[3]; // [rsp+20h] [rbp-28h] BYREF
  char v5; // [rsp+38h] [rbp-10h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v4, nullptr);
  dword_18002B3CC = 0;
  switch ( a1 )
  {
    case 0xFFFFFFFE:
      dword_18002B3CC = 1;
      OEMCP = GetOEMCP();
LABEL_5:
      a1 = OEMCP;
      break;
    case 0xFFFFFFFD:
      dword_18002B3CC = 1;
      OEMCP = GetACP();
      goto LABEL_5;
    case 0xFFFFFFFC:
      dword_18002B3CC = 1;
      a1 = *(_DWORD *)(v4[1] + 12LL);
      break;
    default:
      break;
  }
  if ( v5 != 0 )
    *(_DWORD *)(v4[0] + 936LL) &= ~2u;
  return a1;
}


// ===== ?setSBCS@@YAXPEAUthreadmbcinfostruct@@@Z @ 0x18001246c size=0x90 =====
void __fastcall setSBCS(struct threadmbcinfostruct *a1)
{
  _BYTE *v1; // rbx
  __int64 v3; // rbp
  _WORD *v4; // rdi
  __int64 v5; // rcx
  signed __int64 v6; // rdi
  _BYTE *v7; // rcx
  __int64 i; // rdx

  v1 = (char *)a1 + 24;
  v3 = 257;
  sub_180009D50((__m128i *)((char *)a1 + 24), 0, 0x101u);
  v4 = (_WORD *)((char *)a1 + 12);
  *(_QWORD *)((char *)a1 + 4) = 0;
  v5 = 6;
  *((_QWORD *)a1 + 68) = 0;
  while ( v5 != 0 )
  {
    *v4++ = 0;
    --v5;
  }
  v6 = &unk_180029540 - (_UNKNOWN *)a1;
  do
  {
    *v1 = v1[v6];
    ++v1;
    --v3;
  }
  while ( v3 != 0 );
  v7 = (char *)a1 + 281;
  for ( i = 256; i != 0; --i )
  {
    *v7 = v7[v6];
    ++v7;
  }
}


// ===== ?setSBUpLow@@YAXPEAU__crt_multibyte_data@@@Z @ 0x1800124fc size=0x1e2 =====
void __fastcall setSBUpLow(struct __crt_multibyte_data *a1)
{
  __int64 v2; // rbx
  unsigned int v3; // eax
  CHAR *v4; // rcx
  BYTE v5; // al
  BYTE *LeadByte; // rdx
  unsigned int v7; // r8d
  __int64 i; // rcx
  WORD *v9; // rdx
  char *j; // rcx
  char v11; // al
  unsigned int v12; // edx
  char *v13; // rcx
  char v14; // al
  struct _cpinfo CPInfo; // [rsp+50h] [rbp-B0h] BYREF
  CHAR MultiByteStr[256]; // [rsp+70h] [rbp-90h] BYREF
  char v17[256]; // [rsp+170h] [rbp+70h] BYREF
  char v18[256]; // [rsp+270h] [rbp+170h] BYREF
  WORD CharType[512]; // [rsp+370h] [rbp+270h] BYREF

  v2 = 256;
  if ( GetCPInfo(*((_DWORD *)a1 + 1), &CPInfo) )
  {
    v3 = 0;
    v4 = MultiByteStr;
    do
      *v4++ = v3++;
    while ( v3 < 0x100 );
    v5 = CPInfo.LeadByte[0];
    LeadByte = CPInfo.LeadByte;
    MultiByteStr[0] = 32;
    while ( v5 != 0 )
    {
      v7 = LeadByte[1];
      for ( i = v5; (unsigned int)i <= v7 && (unsigned int)i < 0x100; i = (unsigned int)(i + 1) )
        MultiByteStr[i] = 32;
      LeadByte += 2;
      v5 = *LeadByte;
    }
    _acrt_GetStringTypeA(nullptr, 1u, MultiByteStr, 256, CharType, *((_DWORD *)a1 + 1), 0);
    _acrt_LCMapStringA(nullptr, *((wchar_t **)a1 + 68), 0x100u, MultiByteStr, 256, v17, 256, *((_DWORD *)a1 + 1), 0);
    _acrt_LCMapStringA(nullptr, *((wchar_t **)a1 + 68), 0x200u, MultiByteStr, 256, v18, 256, *((_DWORD *)a1 + 1), 0);
    v9 = CharType;
    for ( j = (char *)a1 + 25; ; ++j )
    {
      if ( (*(_BYTE *)v9 & 1) != 0 )
      {
        *j |= 0x10u;
        v11 = j[v17 - (char *)a1 - 25];
      }
      else
      {
        if ( (*(_BYTE *)v9 & 2) == 0 )
        {
          j[256] = 0;
          goto LABEL_18;
        }
        *j |= 0x20u;
        v11 = j[v18 - (char *)a1 - 25];
      }
      j[256] = v11;
LABEL_18:
      ++v9;
      if ( --v2 == 0 )
        return;
    }
  }
  v12 = 0;
  v13 = (char *)a1 + 25;
  do
  {
    if ( v12 - 97 + 32 <= 0x19 )
    {
      *v13 |= 0x10u;
      v14 = v12 + 32;
LABEL_25:
      v13[256] = v14;
      goto LABEL_27;
    }
    if ( v12 - 97 <= 0x19 )
    {
      *v13 |= 0x20u;
      v14 = v12 - 32;
      goto LABEL_25;
    }
    v13[256] = 0;
LABEL_27:
    ++v12;
    ++v13;
  }
  while ( v12 < 0x100 );
}


// ===== ?setmbcp_internal@@YAHH_N@Z @ 0x1800126e0 size=0x1b5 =====
__int64 __fastcall setmbcp_internal(UINT a1, char a2)
{
  unsigned int SystemCP; // edi
  _DWORD *v6; // rax
  _DWORD *v7; // rbx
  __int64 v8; // rdx
  _OWORD *v9; // rcx
  _OWORD *v10; // rax
  __int128 v11; // xmm1
  unsigned int v12; // edi
  void *v13; // rcx
  _DWORD *v14; // rcx
  void *v15; // rax
  int v16; // [rsp+20h] [rbp-20h] BYREF
  struct __acrt_ptd *v17; // [rsp+28h] [rbp-18h] BYREF
  struct __acrt_ptd **v18; // [rsp+30h] [rbp-10h] BYREF
  char v19; // [rsp+70h] [rbp+30h] BYREF
  int v20; // [rsp+78h] [rbp+38h] BYREF

  v17 = _acrt_getptd();
  _acrt_update_thread_multibyte_data();
  SystemCP = getSystemCP(a1);
  if ( SystemCP == *(_DWORD *)(*((_QWORD *)v17 + 17) + 4LL) )
    return 0;
  v6 = malloc_base(0x228u);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v8 = 4;
    v9 = v6;
    v10 = *((_OWORD **)v17 + 17);
    do
    {
      *v9 = *v10;
      v9[1] = v10[1];
      v9[2] = v10[2];
      v9[3] = v10[3];
      v9[4] = v10[4];
      v9[5] = v10[5];
      v9[6] = v10[6];
      v9 += 8;
      v11 = v10[7];
      v10 += 8;
      *(v9 - 1) = v11;
      --v8;
    }
    while ( v8 != 0 );
    *v9 = *v10;
    v9[1] = v10[1];
    *((_QWORD *)v9 + 4) = *((_QWORD *)v10 + 4);
    *v7 = 0;
    v12 = setmbcp_nolock(SystemCP, v7, 128);
    if ( v12 != -1 )
    {
      if ( a2 == 0 )
        _acrt_set_locale_changed();
      if ( _InterlockedExchangeAdd(*((volatile signed __int32 **)v17 + 17), 0xFFFFFFFF) == 1 )
      {
        v13 = *((void **)v17 + 17);
        if ( v13 != &unk_180029540 )
          free_base(v13);
      }
      *v7 = 1;
      v14 = v7;
      v7 = nullptr;
      *((_QWORD *)v17 + 17) = v14;
      if ( (*((_BYTE *)v17 + 936) & 2) == 0 && (dword_180029A88 & 1) == 0 )
      {
        v18 = &v17;
        v20 = 5;
        v16 = 5;
        __crt_seh_guarded_call<void>::operator()<_lambda_99476a1ad63dd22509b5d3e65b0ffc95_,_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_ &,_lambda_f7424dd8d45958661754dc4f2697e9c3_>(
          (__int64)&v19,
          &v16,
          (__int64)&v18,
          &v20);
        v15 = off_180029530;
        if ( a2 != 0 )
          v15 = Block;
        off_180029530 = v15;
      }
      goto LABEL_9;
    }
    *errno() = 22;
  }
  v12 = -1;
LABEL_9:
  free_base(v7);
  return v12;
}


// ===== __acrt_initialize_multibyte @ 0x180012898 size=0x27 =====
char _acrt_initialize_multibyte()
{
  if ( byte_18002B3D8 == 0 )
  {
    setmbcp_internal(0xFFFFFFFD, 1);
    byte_18002B3D8 = 1;
  }
  return 1;
}


// ===== __acrt_update_thread_multibyte_data @ 0x1800128c0 size=0xbf =====
void *_acrt_update_thread_multibyte_data()
{
  struct __acrt_ptd *v0; // rax
  struct __acrt_ptd *v1; // rdi
  void *v2; // rbx
  void *Block; // [rsp+30h] [rbp+8h]

  v0 = _acrt_getptd();
  v1 = v0;
  if ( (dword_180029A88 & *((_DWORD *)v0 + 234)) != 0 && *((_QWORD *)v0 + 18) != 0 )
  {
    v2 = *((void **)v0 + 17);
  }
  else
  {
    sub_180011524(5);
    v2 = *((void **)v1 + 17);
    if ( v2 != ::Block )
    {
      if ( v2 != nullptr
        && _InterlockedExchangeAdd((volatile signed __int32 *)v2, 0xFFFFFFFF) == 1
        && v2 != &unk_180029540 )
      {
        free_base(v2);
      }
      *((_QWORD *)v1 + 17) = ::Block;
      Block = ::Block;
      _InterlockedIncrement((volatile signed __int32 *)::Block);
      v2 = Block;
    }
    sub_180011578(5);
  }
  if ( v2 == nullptr )
    abort();
  return v2;
}


// ===== _setmbcp_nolock @ 0x180012980 size=0x2a7 =====
__int64 __fastcall setmbcp_nolock(UINT a1, __int64 a2)
{
  const wchar_t *v3; // rsi
  UINT SystemCP; // edi
  unsigned int v5; // ebp
  _DWORD *v6; // rax
  BYTE *i; // rcx
  unsigned int v8; // eax
  unsigned int v9; // edx
  __int64 v10; // rdi
  __int64 v11; // rdx
  _BYTE *v12; // rax
  __int64 j; // rcx
  const wchar_t *v14; // rax
  _WORD *v15; // rdi
  __int64 k; // rcx
  __int64 v18; // rax
  _BYTE *v19; // r14
  __int64 v20; // rbp
  char *v21; // r9
  unsigned __int8 *v22; // rdx
  unsigned int v23; // r8d
  __int64 v24; // r10
  UINT v25; // edi
  UINT v26; // edi
  UINT v27; // edi
  _WORD *v28; // rcx
  __int64 m; // rdx
  struct _cpinfo CPInfo; // [rsp+20h] [rbp-48h] BYREF

  v3 = nullptr;
  SystemCP = getSystemCP(a1);
  if ( SystemCP != 0 )
  {
    v5 = 0;
    v6 = &unk_180029780;
    while ( *v6 != SystemCP )
    {
      ++v5;
      v6 += 12;
      if ( v5 >= 5 )
      {
        if ( SystemCP - 65000 > 1 && IsValidCodePage((unsigned __int16)SystemCP) )
        {
          if ( GetCPInfo(SystemCP, &CPInfo) )
          {
            sub_180009D50((__m128i *)(a2 + 24), 0, 0x101u);
            *(_DWORD *)(a2 + 4) = SystemCP;
            *(_QWORD *)(a2 + 544) = 0;
            if ( CPInfo.MaxCharSize <= 1 )
            {
              *(_DWORD *)(a2 + 8) = 0;
            }
            else
            {
              for ( i = CPInfo.LeadByte; *i != 0; i += 2 )
              {
                if ( i[1] == 0 )
                  break;
                v8 = i[1];
                v9 = *i;
                if ( v9 <= v8 )
                {
                  v10 = v9 + 1;
                  v11 = v8 - v9 + 1;
                  do
                  {
                    *(_BYTE *)(v10 + a2 + 24) |= 4u;
                    v10 = (unsigned int)(v10 + 1);
                    --v11;
                  }
                  while ( v11 != 0 );
                }
              }
              v12 = (_BYTE *)(a2 + 26);
              for ( j = 254; j != 0; --j )
                *v12++ |= 8u;
              switch ( *(_DWORD *)(a2 + 4) )
              {
                case 0x3A4:
                  v14 = L"ja-JP";
                  break;
                case 0x3A8:
                  v14 = L"zh-CN";
                  break;
                case 0x3B5:
                  v14 = L"ko-KR";
                  break;
                case 0x3B6:
                  v14 = L"zh-TW";
                  break;
                default:
                  v14 = nullptr;
                  break;
              }
              *(_QWORD *)(a2 + 544) = v14;
              *(_DWORD *)(a2 + 8) = 1;
            }
            v15 = (_WORD *)(a2 + 12);
            for ( k = 6; k != 0; --k )
              *v15++ = 0;
            goto LABEL_54;
          }
          if ( dword_18002B3CC != 0 )
            goto LABEL_2;
        }
        return 0xFFFFFFFFLL;
      }
    }
    sub_180009D50((__m128i *)(a2 + 24), 0, 0x101u);
    v18 = v5;
    v19 = &unk_180029770;
    v20 = 4;
    v21 = (char *)&unk_180029790 + 48 * v18;
    do
    {
      v22 = (unsigned __int8 *)v21;
      if ( *v21 != 0 )
      {
        do
        {
          if ( v22[1] == 0 )
            break;
          v23 = *v22;
          if ( v23 <= v22[1] )
          {
            v24 = v23 + 1;
            do
            {
              if ( (unsigned int)v24 >= 0x101 )
                break;
              ++v23;
              *(_BYTE *)(v24 + a2 + 24) |= *v19;
              v24 = (unsigned int)(v24 + 1);
            }
            while ( v23 <= v22[1] );
          }
          v22 += 2;
        }
        while ( *v22 != 0 );
      }
      v21 += 8;
      ++v19;
      --v20;
    }
    while ( v20 != 0 );
    *(_DWORD *)(a2 + 4) = SystemCP;
    *(_DWORD *)(a2 + 8) = 1;
    v25 = SystemCP - 932;
    if ( v25 != 0 )
    {
      v26 = v25 - 4;
      if ( v26 != 0 )
      {
        v27 = v26 - 13;
        if ( v27 != 0 )
        {
          if ( v27 == 1 )
            v3 = L"zh-TW";
        }
        else
        {
          v3 = L"ko-KR";
        }
      }
      else
      {
        v3 = L"zh-CN";
      }
    }
    else
    {
      v3 = L"ja-JP";
    }
    *(_QWORD *)(a2 + 544) = v3;
    v28 = (_WORD *)(a2 + 12);
    for ( m = 6; m != 0; --m )
    {
      *v28 = *(_WORD *)((char *)v28 + (_QWORD)&unk_180029780 + 48 * v18 - a2 - 8);
      ++v28;
    }
LABEL_54:
    setSBUpLow((struct __crt_multibyte_data *)a2);
  }
  else
  {
LABEL_2:
    setSBCS((struct threadmbcinfostruct *)a2);
  }
  return 0;
}


// ===== ?x_ismbbtype_l@@YAHPEAU__crt_locale_pointers@@IHH@Z @ 0x180012c28 size=0x75 =====
__int64 __fastcall x_ismbbtype_l(struct __crt_locale_pointers *a1, unsigned __int8 a2, int a3, unsigned __int8 a4)
{
  __int64 result; // rax
  _QWORD v8[3]; // [rsp+20h] [rbp-28h] BYREF
  char v9; // [rsp+38h] [rbp-10h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v8, a1);
  if ( (a4 & *(_BYTE *)(a2 + v8[2] + 25LL)) != 0
    || (a3 == 0 ? (result = 0) : (result = (unsigned __int16)(a3 & *(_WORD *)(*(_QWORD *)v8[1] + 2LL * a2))),
        (_DWORD)result != 0) )
  {
    result = 1;
  }
  if ( v9 != 0 )
    *(_DWORD *)(v8[0] + 936LL) &= ~2u;
  return result;
}


// ===== _ismbblead @ 0x180012ca0 size=0x12 =====
int __cdecl ismbblead(unsigned int Ch)
{
  return x_ismbbtype_l(nullptr, Ch, 0, 4u);
}


// ===== __acrt_initialize_command_line @ 0x180012cb4 size=0x25 =====
char _acrt_initialize_command_line()
{
  qword_18002B3F0 = (__int64)GetCommandLineA();
  qword_18002B3F8 = (__int64)GetCommandLineW();
  return 1;
}


// ===== __dcrt_get_narrow_environment_from_os @ 0x180012cdc size=0x103 =====
CHAR *_dcrt_get_narrow_environment_from_os()
{
  LPWCH EnvironmentStringsW; // rax
  WCHAR *v1; // rbx
  char *v2; // rsi
  __int64 v3; // rax
  __int64 v4; // rsi
  int v5; // eax
  int cbMultiByte; // ebp
  CHAR *lpMultiByteStr; // rax
  CHAR *v8; // rdi
  CHAR *v9; // rsi

  EnvironmentStringsW = GetEnvironmentStringsW();
  v1 = EnvironmentStringsW;
  if ( EnvironmentStringsW == nullptr )
    goto LABEL_12;
  v2 = (char *)EnvironmentStringsW;
  if ( *EnvironmentStringsW != 0 )
  {
    do
    {
      v3 = -1;
      do
        ++v3;
      while ( *(_WORD *)&v2[2 * v3] != 0 );
      v2 += 2 * v3 + 2;
    }
    while ( *(_WORD *)v2 != 0 );
  }
  v4 = (v2 - (char *)v1 + 2) >> 1;
  v5 = WideCharToMultiByte(0, 0, v1, v4, nullptr, 0, nullptr, nullptr);
  cbMultiByte = v5;
  if ( v5 != 0 )
  {
    lpMultiByteStr = (CHAR *)malloc_base(v5);
    v8 = lpMultiByteStr;
    if ( lpMultiByteStr != nullptr
      && WideCharToMultiByte(0, 0, v1, v4, lpMultiByteStr, cbMultiByte, nullptr, nullptr) != 0 )
    {
      v9 = v8;
      v8 = nullptr;
    }
    else
    {
      v9 = nullptr;
    }
    free_base(v8);
  }
  else
  {
LABEL_12:
    v9 = nullptr;
  }
  if ( v1 != nullptr )
    FreeEnvironmentStringsW(v1);
  return v9;
}


// ===== __acrt_initialize_heap @ 0x180012de0 size=0x1c =====
bool _acrt_initialize_heap()
{
  hHeap = GetProcessHeap();
  return hHeap != nullptr;
}


// ===== sub_180012DFC @ 0x180012dfc size=0xb =====
char sub_180012DFC()
{
  hHeap = nullptr;
  return 1;
}


// ===== __acrt_execute_initializers @ 0x180012e08 size=0x94 =====
char __fastcall _acrt_execute_initializers(_QWORD *a1, _QWORD *a2)
{
  _QWORD *v5; // rbx
  void (__fastcall **v6)(_QWORD); // rbx

  if ( a1 == a2 )
    return 1;
  v5 = a1;
  do
  {
    if ( *v5 != 0 && ((unsigned __int8 (__fastcall *)(_QWORD))*v5)(*v5) == 0 )
      break;
    v5 += 2;
  }
  while ( v5 != a2 );
  if ( v5 == a2 )
    return 1;
  if ( v5 != a1 )
  {
    v6 = (void (__fastcall **)(_QWORD))(v5 - 1);
    do
    {
      if ( *(v6 - 1) != nullptr && *v6 != nullptr )
        (*v6)(0);
      v6 -= 2;
    }
    while ( v6 + 1 != a1 );
  }
  return 0;
}


// ===== __acrt_execute_uninitializers @ 0x180012e9c size=0x4f =====
char __fastcall _acrt_execute_uninitializers(void (__fastcall **a1)(_QWORD), void (__fastcall **a2)(_QWORD))
{
  void (__fastcall **v3)(_QWORD); // rbx

  if ( a1 != a2 )
  {
    v3 = a2 - 1;
    do
    {
      if ( *v3 != nullptr )
        (*v3)(0);
      v3 -= 2;
    }
    while ( v3 + 1 != a1 );
  }
  return 1;
}


// ===== ??$?RV_lambda_c36588078e9f5dfd39652860aa6b3aaf_@@AEAV_lambda_ec61778202f4f5fc7e7711acc23c3bca_@@V_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_@@@?$__crt_seh_guarded_call@P6AXH@Z@@QEAAP6AXH@Z$$QEAV_lambda_c36588078e9f5dfd39652860aa6b3aaf_@@AEAV_lambda_ec61778202f4f5fc7e7711acc23c3bca_@@$$QEAV_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_@@@Z @ 0x180012eec size=0x45 =====
__int64 __fastcall __crt_seh_guarded_call<void (*)(int)>::operator()<_lambda_c36588078e9f5dfd39652860aa6b3aaf_,_lambda_ec61778202f4f5fc7e7711acc23c3bca_ &,_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_>(
        __int64 a1,
        int *a2,
        __int64 a3,
        int *a4)
{
  __int64 v5; // rbx

  sub_180011524(*a2);
  v5 = __ROR8__(qword_18002B420 ^ _security_cookie, _security_cookie & 0x3F);
  sub_180011578(*a4);
  return v5;
}


// ===== __acrt_get_sigabrt_handler @ 0x180012f34 size=0x2e =====
__int64 _acrt_get_sigabrt_handler()
{
  __int64 v1; // [rsp+30h] [rbp+8h] BYREF
  int v2; // [rsp+38h] [rbp+10h] BYREF
  int v3; // [rsp+40h] [rbp+18h] BYREF

  v2 = 3;
  v3 = 3;
  return __crt_seh_guarded_call<void (*)(int)>::operator()<_lambda_c36588078e9f5dfd39652860aa6b3aaf_,_lambda_ec61778202f4f5fc7e7711acc23c3bca_ &,_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_>(
           (__int64)&v1,
           &v3,
           (__int64)&v1,
           &v2);
}


// ===== _initp_misc_winsig @ 0x180012f64 size=0x1d =====
void __fastcall initp_misc_winsig(__int64 a1)
{
  qword_18002B410 = a1;
  qword_18002B418 = a1;
  qword_18002B420 = a1;
  qword_18002B428 = a1;
}


// ===== raise @ 0x180012f84 size=0x299 =====
int __cdecl raise(int Signal)
{
  struct __acrt_ptd *v2; // r13
  char v3; // si
  struct __acrt_ptd *v4; // rax
  __int64 i; // rcx
  __int64 *v7; // rbx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  void (__fastcall *v12)(_QWORD); // r15
  int v13; // r12d
  __int64 v14; // rax
  __int64 v15; // rcx
  struct __acrt_ptd *v16; // rbx
  int v17; // [rsp+90h] [rbp+18h]
  __int64 v18; // [rsp+98h] [rbp+20h]

  v2 = nullptr;
  v17 = 0;
  v3 = 1;
  if ( Signal != 2 )
  {
    switch ( Signal )
    {
      case 4:
        goto LABEL_9;
      case 6:
        goto LABEL_19;
      case 8:
      case 11:
LABEL_9:
        v4 = _acrt_getptd_noexit();
        v2 = v4;
        if ( v4 == nullptr )
          return -1;
        for ( i = *(_QWORD *)v4; i != *(_QWORD *)v4 + 192LL; i += 16 )
        {
          if ( *(_DWORD *)(i + 4) == Signal )
            goto LABEL_16;
        }
        i = 0;
LABEL_16:
        if ( i == 0 )
        {
LABEL_17:
          *errno() = 22;
          invalid_parameter_noinfo();
          return -1;
        }
        v7 = (__int64 *)(i + 8);
        v3 = 0;
        goto LABEL_29;
      default:
        break;
    }
    if ( Signal != 15 && (unsigned int)(Signal - 21) > 1 )
      goto LABEL_17;
  }
LABEL_19:
  v8 = Signal - 2;
  if ( v8 != 0 )
  {
    v9 = v8 - 4;
    if ( v9 == 0 )
    {
LABEL_25:
      v7 = &qword_18002B420;
      goto LABEL_29;
    }
    v10 = v9 - 9;
    if ( v10 != 0 )
    {
      v11 = v10 - 6;
      if ( v11 != 0 )
      {
        if ( v11 != 1 )
        {
          v7 = nullptr;
          goto LABEL_29;
        }
        goto LABEL_25;
      }
      v7 = &qword_18002B418;
    }
    else
    {
      v7 = &qword_18002B428;
    }
  }
  else
  {
    v7 = &qword_18002B410;
  }
LABEL_29:
  v18 = 0;
  if ( v3 != 0 )
  {
    sub_180011524(3);
    v12 = (void (__fastcall *)(_QWORD))__ROR8__(*v7 ^ _security_cookie, _security_cookie & 0x3F);
  }
  else
  {
    v12 = (void (__fastcall *)(_QWORD))*v7;
  }
  if ( v12 == (void (__fastcall *)(_QWORD))1 )
  {
    v13 = 2320;
    goto LABEL_47;
  }
  if ( v12 == nullptr )
  {
    if ( v3 != 0 )
      sub_180011578(3);
    exit(3);
  }
  v13 = 2320;
  if ( (unsigned int)Signal > 0xB || !_bittest(&v13, Signal) )
    goto LABEL_41;
  v18 = *((_QWORD *)v2 + 1);
  *((_QWORD *)v2 + 1) = 0;
  if ( Signal == 8 )
  {
    v17 = *((_DWORD *)_acrt_getptd() + 4);
    *((_DWORD *)_acrt_getptd() + 4) = 140;
LABEL_41:
    if ( Signal == 8 )
    {
      v14 = *(_QWORD *)v2 + 48LL;
      v15 = *(_QWORD *)v2 + 192LL;
      while ( v14 != v15 )
      {
        *(_QWORD *)(v14 + 8) = 0;
        v14 += 16;
      }
      goto LABEL_47;
    }
  }
  *v7 = _security_cookie ^ __ROR8__(0, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
LABEL_47:
  if ( v3 != 0 )
    sub_180011578(3);
  if ( v12 != (void (__fastcall *)(_QWORD))1 )
  {
    if ( Signal == 8 )
    {
      v16 = _acrt_getptd();
      guard_check_icall_nop();
      ((void (__fastcall *)(__int64, _QWORD))v12)(8, *((unsigned int *)v16 + 4));
    }
    else
    {
      guard_check_icall_nop();
      v12((unsigned int)Signal);
    }
    if ( (unsigned int)Signal <= 0xB )
    {
      if ( _bittest(&v13, Signal) )
      {
        *((_QWORD *)v2 + 1) = v18;
        if ( Signal == 8 )
          *((_DWORD *)_acrt_getptd() + 4) = v17;
      }
    }
  }
  return 0;
}


// ===== __acrt_has_user_matherr @ 0x180013220 size=0x1d =====
bool _acrt_has_user_matherr()
{
  return __ROR8__(qword_18002B430 ^ _security_cookie, _security_cookie & 0x3F) != 0;
}


// ===== sub_180013240 @ 0x180013240 size=0x8 =====
void __fastcall sub_180013240(__int64 a1)
{
  qword_18002B430 = a1;
}


// ===== __acrt_invoke_user_matherr @ 0x180013248 size=0x45 =====
__int64 __fastcall _acrt_invoke_user_matherr(__int64 a1)
{
  __int64 (__fastcall *v1)(__int64); // rbx

  v1 = (__int64 (__fastcall *)(__int64))__ROR8__(qword_18002B430 ^ _security_cookie, _security_cookie & 0x3F);
  if ( v1 != nullptr )
    return v1(a1);
  else
    return 0;
}


// ===== ?__acrt_stdio_free_stream@@YAXV__crt_stdio_stream@@@Z @ 0x180013290 size=0x42 =====
__int64 __fastcall __acrt_stdio_free_stream(__int64 a1)
{
  *(_QWORD *)a1 = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 24) = -1;
  *(_DWORD *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  *(_QWORD *)(a1 + 40) = 0;
  _InterlockedExchange((volatile __int32 *)(a1 + 20), 0);
  return a1;
}


// ===== ??$?RV_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_@@AEAV_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_@@V_lambda_237c231691f317818eb88cc1d5d642d6_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_@@AEAV_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_@@$$QEAV_lambda_237c231691f317818eb88cc1d5d642d6_@@@Z @ 0x1800132d4 size=0x71 =====
__int64 __fastcall __crt_seh_guarded_call<int>::operator()<_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_,_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_ &,_lambda_237c231691f317818eb88cc1d5d642d6_>(
        __int64 a1,
        unsigned int *a2,
        int **a3,
        unsigned int *a4)
{
  unsigned int v6; // ebx

  sub_18001383C(*a2);
  if ( (*(_BYTE *)(qword_18002ABF0[(__int64)**a3 >> 6] + ((unsigned __int64)(**a3 & 0x3F) << 6) + 56) & 1) != 0 )
  {
    v6 = close_nolock();
  }
  else
  {
    *errno() = 9;
    v6 = -1;
  }
  sub_180013860(*a4);
  return v6;
}


// ===== sub_180013348 @ 0x180013348 size=0xa1 =====
__int64 __fastcall sub_180013348(int a1)
{
  int *v2; // [rsp+20h] [rbp-18h] BYREF
  int v3; // [rsp+40h] [rbp+8h] BYREF
  char v4; // [rsp+48h] [rbp+10h] BYREF
  int v5; // [rsp+50h] [rbp+18h] BYREF
  int v6; // [rsp+58h] [rbp+20h] BYREF

  v3 = a1;
  if ( a1 == -2 )
  {
    *_doserrno() = 0;
    *errno() = 9;
  }
  else
  {
    if ( a1 >= 0
      && a1 < (unsigned int)dword_18002AFF0
      && (*(_BYTE *)(qword_18002ABF0[(__int64)a1 >> 6] + ((unsigned __int64)(a1 & 0x3F) << 6) + 56) & 1) != 0 )
    {
      v5 = a1;
      v6 = a1;
      v2 = &v3;
      return __crt_seh_guarded_call<int>::operator()<_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_,_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_ &,_lambda_237c231691f317818eb88cc1d5d642d6_>(
               (__int64)&v4,
               (unsigned int *)&v6,
               &v2,
               (unsigned int *)&v5);
    }
    *_doserrno() = 0;
    *errno() = 9;
    invalid_parameter_noinfo();
  }
  return 0xFFFFFFFFLL;
}


// ===== _close_nolock @ 0x1800133ec size=0xba =====
__int64 __fastcall close_nolock(int a1)
{
  __int64 v1; // rdi
  DWORD LastError; // ebx
  intptr_t osfhandle; // rbx
  void *v4; // rax

  v1 = a1;
  if ( get_osfhandle(a1) == -1
    || ((_DWORD)v1 == 1 && (*(_BYTE *)(qword_18002ABF0[0] + 184) & 1) != 0
     || (_DWORD)v1 == 2 && (*(_BYTE *)(qword_18002ABF0[0] + 120) & 1) != 0)
    && (osfhandle = get_osfhandle(2), get_osfhandle(1) == osfhandle)
    || (v4 = (void *)get_osfhandle(v1), CloseHandle(v4)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  free_osfhnd((unsigned int)v1);
  *(_BYTE *)(qword_18002ABF0[v1 >> 6] + ((unsigned __int64)(v1 & 0x3F) << 6) + 56) = 0;
  if ( LastError == 0 )
    return 0;
  _acrt_errno_map_os_error(LastError);
  return 0xFFFFFFFFLL;
}


// ===== __acrt_stdio_free_buffer_nolock @ 0x1800134a8 size=0x40 =====
__int64 __fastcall _acrt_stdio_free_buffer_nolock(__int64 a1)
{
  __int64 result; // rax

  result = *(_DWORD *)(a1 + 20) >> 13;
  if ( (*(_DWORD *)(a1 + 20) & 0x2000) != 0 )
  {
    result = *(_DWORD *)(a1 + 20) >> 6;
    if ( (*(_DWORD *)(a1 + 20) & 0x40) != 0 )
    {
      free_base(*(void **)(a1 + 8));
      _InterlockedAnd((volatile signed __int32 *)(a1 + 20), 0xFFFFFEBF);
      *(_QWORD *)(a1 + 8) = 0;
      *(_QWORD *)a1 = 0;
      *(_DWORD *)(a1 + 16) = 0;
      return 0;
    }
  }
  return result;
}


// ===== __acrt_stdio_flush_nolock @ 0x1800134e8 size=0x77 =====
__int64 __fastcall _acrt_stdio_flush_nolock(__int64 a1)
{
  signed int v2; // edi
  const void *v3; // rsi
  int v4; // eax

  if ( (*(_DWORD *)(a1 + 20) & 3) == 2 && (*(_DWORD *)(a1 + 20) & 0xC0) != 0 )
  {
    v2 = *(_DWORD *)a1 - *(_DWORD *)(a1 + 8);
    *(_DWORD *)(a1 + 16) = 0;
    v3 = *(const void **)(a1 + 8);
    *(_QWORD *)a1 = v3;
    if ( v2 > 0 )
    {
      v4 = fileno((FILE *)a1);
      if ( v2 != write(v4, v3, v2) )
      {
        _InterlockedOr((volatile signed __int32 *)(a1 + 20), 0x10u);
        return 0xFFFFFFFFLL;
      }
      if ( (*(_DWORD *)(a1 + 20) & 4) != 0 )
        _InterlockedAnd((volatile signed __int32 *)(a1 + 20), 0xFFFFFFFD);
    }
  }
  return 0;
}


// ===== _fflush_nolock @ 0x180013560 size=0x4b =====
int __cdecl fflush_nolock(FILE *Stream)
{
  int v3; // eax

  if ( Stream == nullptr )
    return common_flush_all();
  if ( (unsigned int)_acrt_stdio_flush_nolock((__int64)Stream) != 0 )
    return -1;
  if ( (HIDWORD(Stream->_base) & 0x800) != 0 )
  {
    v3 = fileno(Stream);
    if ( commit(v3) != 0 )
      return -1;
  }
  return 0;
}


// ===== _flushall @ 0x1800135ac size=0xa =====
int __cdecl flushall()
{
  return common_flush_all(1);
}


// ===== common_flush_all @ 0x1800135b8 size=0xe4 =====
__int64 __fastcall common_flush_all(int a1)
{
  __int64 *v2; // rdi
  __int64 *v3; // r14
  __int64 v4; // rbx
  int v5; // eax
  int v6; // edx
  __int64 result; // rax
  unsigned int v8; // [rsp+20h] [rbp-38h]
  unsigned int v9; // [rsp+24h] [rbp-34h]

  v9 = 0;
  v8 = 0;
  sub_180011524(8);
  v2 = (__int64 *)qword_18002ABC0;
  v3 = (__int64 *)((char *)qword_18002ABC0 + 8 * dword_18002ABB8);
  while ( v2 != v3 )
  {
    v4 = *v2;
    if ( *v2 != 0 )
    {
      sub_1800111F4(v4);
      if ( (*(_DWORD *)(v4 + 20) & 0x2000) != 0 )
      {
        if ( a1 == 1 )
        {
          if ( fflush_nolock((FILE *)v4) != -1 )
            ++v9;
        }
        else if ( a1 == 0 && (*(_DWORD *)(v4 + 20) & 2) != 0 )
        {
          v5 = fflush_nolock((FILE *)v4);
          v6 = v8;
          if ( v5 == -1 )
            v6 = -1;
          v8 = v6;
        }
      }
      sub_180011200(v4);
    }
    ++v2;
  }
  sub_180011578(8);
  result = v8;
  if ( a1 == 1 )
    return v9;
  return result;
}


// ===== __acrt_lowio_create_handle_array @ 0x18001369c size=0x95 =====
char *_acrt_lowio_create_handle_array()
{
  char *v0; // rax
  char *v1; // rsi
  char *v2; // rbx
  char *v3; // rbp
  char *v4; // rdi

  v0 = (char *)calloc_base(0x40u, 0x40u);
  v1 = nullptr;
  v2 = v0;
  if ( v0 != nullptr )
  {
    v3 = v0 + 4096;
    v4 = v0 + 48;
    do
    {
      _acrt_InitializeCriticalSectionEx((LPCRITICAL_SECTION)(v4 - 48), 0xFA0u, 0);
      *((_QWORD *)v4 - 1) = -1;
      *(_QWORD *)v4 = 0;
      *((_DWORD *)v4 + 2) = 168427520;
      v4[12] = 10;
      v4[13] &= 0xF8u;
      v4[14] = 0;
      v4 += 64;
    }
    while ( v4 - 48 != v3 );
    v1 = v2;
  }
  free_base(nullptr);
  return v1;
}


// ===== __acrt_lowio_destroy_handle_array @ 0x180013734 size=0x50 =====
void __fastcall _acrt_lowio_destroy_handle_array(char *Block)
{
  struct _RTL_CRITICAL_SECTION *v1; // rsi
  struct _RTL_CRITICAL_SECTION *v3; // rdi

  if ( Block != nullptr )
  {
    v1 = (struct _RTL_CRITICAL_SECTION *)(Block + 4096);
    v3 = (struct _RTL_CRITICAL_SECTION *)Block;
    do
    {
      DeleteCriticalSection(v3);
      v3 = (struct _RTL_CRITICAL_SECTION *)((char *)v3 + 64);
    }
    while ( v3 != v1 );
    free_base(Block);
  }
}


// ===== __acrt_lowio_ensure_fh_exists @ 0x180013784 size=0xb7 =====
__int64 __fastcall _acrt_lowio_ensure_fh_exists(unsigned int a1)
{
  unsigned int v2; // ebx
  __int64 v4; // rdi
  int v5; // eax
  char *handle_array; // rax

  v2 = 0;
  if ( a1 < 0x2000 )
  {
    sub_180011524(7);
    v4 = 0;
    v5 = dword_18002AFF0;
    while ( (int)a1 >= v5 )
    {
      if ( qword_18002ABF0[v4] == 0 )
      {
        handle_array = _acrt_lowio_create_handle_array();
        qword_18002ABF0[v4] = (__int64)handle_array;
        if ( handle_array == nullptr )
        {
          v2 = 12;
          break;
        }
        v5 = dword_18002AFF0 + 64;
        dword_18002AFF0 += 64;
      }
      ++v4;
    }
    sub_180011578(7);
  }
  else
  {
    v2 = 9;
    *errno() = 9;
    invalid_parameter_noinfo();
  }
  return v2;
}


// ===== sub_18001383C @ 0x18001383c size=0x23 =====
void __fastcall sub_18001383C(int a1)
{
  EnterCriticalSection((LPCRITICAL_SECTION)(qword_18002ABF0[(__int64)a1 >> 6] + ((unsigned __int64)(a1 & 0x3F) << 6)));
}


// ===== sub_180013860 @ 0x180013860 size=0x23 =====
void __fastcall sub_180013860(int a1)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)(qword_18002ABF0[(__int64)a1 >> 6] + ((unsigned __int64)(a1 & 0x3F) << 6)));
}


// ===== _free_osfhnd @ 0x180013884 size=0xba =====
__int64 __fastcall free_osfhnd(int a1)
{
  __int64 v2; // rsi
  unsigned __int64 v3; // rdi
  __int64 v4; // rax
  int v5; // ebx
  DWORD v6; // ecx

  if ( a1 >= 0 && a1 < (unsigned int)dword_18002AFF0 )
  {
    v2 = (__int64)a1 >> 6;
    v3 = (unsigned __int64)(a1 & 0x3F) << 6;
    v4 = qword_18002ABF0[v2];
    if ( (*(_BYTE *)(v4 + v3 + 56) & 1) != 0 && *(_QWORD *)(v4 + v3 + 40) != -1 )
    {
      if ( (unsigned int)sub_180017540() == 1 )
      {
        if ( a1 == 0 )
        {
          v6 = -10;
          goto LABEL_12;
        }
        v5 = a1 - 1;
        if ( v5 == 0 )
        {
          v6 = -11;
          goto LABEL_12;
        }
        if ( v5 == 1 )
        {
          v6 = -12;
LABEL_12:
          SetStdHandle(v6, nullptr);
        }
      }
      *(_QWORD *)(qword_18002ABF0[v2] + v3 + 40) = -1;
      return 0;
    }
  }
  *errno() = 9;
  *_doserrno() = 0;
  return 0xFFFFFFFFLL;
}


// ===== _get_osfhandle @ 0x180013940 size=0x75 =====
intptr_t __cdecl get_osfhandle(int FileHandle)
{
  unsigned __int64 v1; // rdx
  __int64 v2; // rax

  if ( FileHandle == -2 )
  {
    *_doserrno() = 0;
    *errno() = 9;
  }
  else
  {
    if ( FileHandle >= 0 && FileHandle < (unsigned int)dword_18002AFF0 )
    {
      v1 = (unsigned __int64)(FileHandle & 0x3F) << 6;
      v2 = qword_18002ABF0[(__int64)FileHandle >> 6];
      if ( (*(_BYTE *)(v2 + v1 + 56) & 1) != 0 )
        return *(_QWORD *)(v2 + v1 + 40);
    }
    *_doserrno() = 0;
    *errno() = 9;
    invalid_parameter_noinfo();
  }
  return -1;
}


// ===== ??$common_lseek_nolock@_J@@YA_JH_JH@Z @ 0x1800139b8 size=0x99 =====
LARGE_INTEGER __fastcall common_lseek_nolock<__int64>(int a1, LARGE_INTEGER a2, DWORD a3)
{
  __int64 v3; // rbx
  void *osfhandle; // rax
  LARGE_INTEGER result; // rax
  DWORD LastError; // eax
  LARGE_INTEGER NewFilePointer; // [rsp+48h] [rbp+20h] BYREF

  v3 = a1;
  osfhandle = (void *)get_osfhandle(a1);
  if ( osfhandle == (void *)-1LL )
  {
    *errno() = 9;
    return (LARGE_INTEGER)-1LL;
  }
  if ( !SetFilePointerEx(osfhandle, a2, &NewFilePointer, a3) )
  {
    LastError = GetLastError();
    _acrt_errno_map_os_error(LastError);
    return (LARGE_INTEGER)-1LL;
  }
  result = NewFilePointer;
  if ( NewFilePointer.QuadPart == -1 )
    return (LARGE_INTEGER)-1LL;
  *(_BYTE *)(qword_18002ABF0[v3 >> 6] + ((unsigned __int64)(v3 & 0x3F) << 6) + 56) &= ~2u;
  return result;
}


// ===== j_??$common_lseek_nolock@_J@@YA_JH_JH@Z @ 0x180013a54 size=0x5 =====
// attributes: thunk
LARGE_INTEGER __fastcall common_lseek_nolock<__int64>(int a1, LARGE_INTEGER a2, DWORD a3)
{
  return ??$common_lseek_nolock@_J@@YA_JH_JH@Z(a1, a2, a3);
}


// ===== __pctype_func @ 0x180013a5c size=0x2f =====
const unsigned __int16 *__cdecl _pctype_func()
{
  struct __acrt_ptd *v0; // rax
  const unsigned __int16 **v2; // [rsp+30h] [rbp+8h] BYREF

  v0 = _acrt_getptd();
  v2 = *((const unsigned __int16 ***)v0 + 18);
  sub_180010394((__int64)v0, (__int64 *)&v2);
  return *v2;
}


// ===== iswctype @ 0x180013a8c size=0x70 =====
int __cdecl iswctype(wint_t C, wctype_t Type)
{
  WORD v4; // ax
  WORD CharType; // [rsp+30h] [rbp+8h] BYREF
  WCHAR SrcStr; // [rsp+40h] [rbp+18h] BYREF

  if ( C == 0xFFFF )
    return 0;
  if ( C >= 0x100u )
  {
    SrcStr = C;
    CharType = 0;
    if ( !GetStringTypeW(1u, &SrcStr, 1, &CharType) )
      return 0;
    v4 = CharType;
  }
  else
  {
    v4 = *((_WORD *)off_180029A80 + C);
  }
  return Type & v4;
}


// ===== _isctype_l @ 0x180013afc size=0x10f =====
int __cdecl isctype_l(int C, int Type, _locale_t Locale)
{
  __int64 v4; // rdi
  int v5; // eax
  int v6; // r9d
  int result; // eax
  CHAR MultiByteStr; // [rsp+40h] [rbp-40h] BYREF
  char v9; // [rsp+41h] [rbp-3Fh]
  char v10; // [rsp+42h] [rbp-3Eh]
  __int64 v11; // [rsp+48h] [rbp-38h] BYREF
  __crt_locale_pointers Localea; // [rsp+50h] [rbp-30h] BYREF
  char v13; // [rsp+60h] [rbp-20h]
  WORD CharType[2]; // [rsp+68h] [rbp-18h] BYREF
  __int16 v15; // [rsp+6Ch] [rbp-14h]

  v4 = C;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v11, Locale);
  if ( (unsigned int)(v4 + 1) <= 0x100 )
  {
    v5 = *(unsigned __int16 *)(*(_QWORD *)Localea.locinfo + 2 * v4);
    goto LABEL_11;
  }
  if ( isleadbyte_l(BYTE1(v4), &Localea) != 0 )
  {
    MultiByteStr = BYTE1(v4);
    v6 = 2;
    v9 = v4;
    v10 = 0;
  }
  else
  {
    MultiByteStr = v4;
    v6 = 1;
    v9 = 0;
  }
  *(_DWORD *)CharType = 0;
  v15 = 0;
  if ( (unsigned int)_acrt_GetStringTypeA(
                       &Localea,
                       1u,
                       &MultiByteStr,
                       v6,
                       CharType,
                       *((_DWORD *)Localea.locinfo + 3),
                       1) != 0 )
  {
    v5 = CharType[0];
LABEL_11:
    result = Type & v5;
    if ( v13 != 0 )
      *(_DWORD *)(v11 + 936) &= ~2u;
    return result;
  }
  if ( v13 != 0 )
    *(_DWORD *)(v11 + 936) &= ~2u;
  return 0;
}


// ===== __acrt_add_locale_ref @ 0x180013c0c size=0x8b =====
__int64 __fastcall _acrt_add_locale_ref(__int64 a1)
{
  volatile signed __int32 *v1; // rax
  volatile signed __int32 *v2; // rax
  volatile signed __int32 *v3; // rax
  volatile signed __int32 *v4; // rax
  volatile signed __int32 **v5; // rax
  __int64 i; // r8
  volatile signed __int32 *v7; // rdx
  __int64 v8; // rcx

  _InterlockedIncrement((volatile signed __int32 *)(a1 + 16));
  v1 = *(volatile signed __int32 **)(a1 + 224);
  if ( v1 != nullptr )
    _InterlockedIncrement(v1);
  v2 = *(volatile signed __int32 **)(a1 + 240);
  if ( v2 != nullptr )
    _InterlockedIncrement(v2);
  v3 = *(volatile signed __int32 **)(a1 + 232);
  if ( v3 != nullptr )
    _InterlockedIncrement(v3);
  v4 = *(volatile signed __int32 **)(a1 + 256);
  if ( v4 != nullptr )
    _InterlockedIncrement(v4);
  v5 = (volatile signed __int32 **)(a1 + 56);
  for ( i = 6; i != 0; --i )
  {
    if ( *(v5 - 2) != (volatile signed __int32 *)&unk_180029538 && *v5 != nullptr )
      _InterlockedIncrement(*v5);
    if ( *(v5 - 3) != nullptr )
    {
      v7 = *(v5 - 1);
      if ( v7 != nullptr )
        _InterlockedIncrement(v7);
    }
    v5 += 4;
  }
  v8 = *(_QWORD *)(a1 + 288);
  if ( v8 == 0 || (_UNKNOWN **)v8 == &off_18001CAD0 )
    return 0x7FFFFFFF;
  else
    return (unsigned int)_InterlockedIncrement((volatile signed __int32 *)(v8 + 348));
}


// ===== __acrt_free_locale @ 0x180013c98 size=0x176 =====
void __fastcall _acrt_free_locale(char *Block)
{
  _UNKNOWN **v1; // rax
  _DWORD *v3; // rax
  _DWORD *v4; // rcx
  _DWORD *v5; // rcx
  _DWORD *v6; // rax
  void **v7; // rsi
  __int64 v8; // rbp
  _DWORD **v9; // rdi
  _DWORD *v10; // rcx
  _DWORD *v11; // rcx

  v1 = *((_UNKNOWN ***)Block + 31);
  if ( v1 != nullptr && v1 != &off_180029A90 )
  {
    v3 = *((_DWORD **)Block + 28);
    if ( v3 != nullptr && *v3 == 0 )
    {
      v4 = *((_DWORD **)Block + 30);
      if ( v4 != nullptr && *v4 == 0 )
      {
        free_base(v4);
        _free_lconv_mon(*((_QWORD *)Block + 31));
      }
      v5 = *((_DWORD **)Block + 29);
      if ( v5 != nullptr && *v5 == 0 )
      {
        free_base(v5);
        _free_lconv_num(*((_QWORD *)Block + 31));
      }
      free_base(*((void **)Block + 28));
      free_base(*((void **)Block + 31));
    }
  }
  v6 = *((_DWORD **)Block + 32);
  if ( v6 != nullptr && *v6 == 0 )
  {
    free_base((void *)(*((_QWORD *)Block + 33) - 254LL));
    free_base((void *)(*((_QWORD *)Block + 34) - 128LL));
    free_base((void *)(*((_QWORD *)Block + 35) - 128LL));
    free_base(*((void **)Block + 32));
  }
  _acrt_locale_free_lc_time_if_unreferenced(*((void **)Block + 36));
  v7 = (void **)(Block + 296);
  v8 = 6;
  v9 = (_DWORD **)(Block + 56);
  do
  {
    if ( *(v9 - 2) != (_DWORD *)&unk_180029538 )
    {
      v10 = *v9;
      if ( *v9 != nullptr && *v10 == 0 )
      {
        free_base(v10);
        free_base(*v7);
      }
    }
    if ( *(v9 - 3) != nullptr )
    {
      v11 = *(v9 - 1);
      if ( v11 != nullptr && *v11 == 0 )
        free_base(v11);
    }
    ++v7;
    v9 += 4;
    --v8;
  }
  while ( v8 != 0 );
  free_base(Block);
}


// ===== __acrt_locale_free_lc_time_if_unreferenced @ 0x180013e38 size=0x36 =====
void __fastcall _acrt_locale_free_lc_time_if_unreferenced(_UNKNOWN **Block)
{
  if ( Block != nullptr && Block != &off_18001CAD0 && *((_DWORD *)Block + 87) == 0 )
  {
    _acrt_locale_free_time();
    free_base(Block);
  }
}


// ===== __acrt_locale_release_lc_time_reference @ 0x180013e70 size=0x25 =====
__int64 __fastcall _acrt_locale_release_lc_time_reference(__int64 a1)
{
  if ( a1 == 0 || (_UNKNOWN **)a1 == &off_18001CAD0 )
    return 0x7FFFFFFF;
  else
    return (unsigned int)_InterlockedDecrement((volatile signed __int32 *)(a1 + 348));
}


// ===== __acrt_release_locale_ref @ 0x180013e98 size=0xa8 =====
void __fastcall _acrt_release_locale_ref(__int64 a1)
{
  volatile signed __int32 *v1; // rax
  volatile signed __int32 *v2; // rax
  volatile signed __int32 *v3; // rax
  volatile signed __int32 *v4; // rax
  volatile signed __int32 **v5; // rax
  __int64 i; // r8
  volatile signed __int32 *v7; // rdx

  if ( a1 != 0 )
  {
    _InterlockedAdd((volatile signed __int32 *)(a1 + 16), 0xFFFFFFFF);
    v1 = *(volatile signed __int32 **)(a1 + 224);
    if ( v1 != nullptr )
      _InterlockedAdd(v1, 0xFFFFFFFF);
    v2 = *(volatile signed __int32 **)(a1 + 240);
    if ( v2 != nullptr )
      _InterlockedAdd(v2, 0xFFFFFFFF);
    v3 = *(volatile signed __int32 **)(a1 + 232);
    if ( v3 != nullptr )
      _InterlockedAdd(v3, 0xFFFFFFFF);
    v4 = *(volatile signed __int32 **)(a1 + 256);
    if ( v4 != nullptr )
      _InterlockedAdd(v4, 0xFFFFFFFF);
    v5 = (volatile signed __int32 **)(a1 + 56);
    for ( i = 6; i != 0; --i )
    {
      if ( *(v5 - 2) != (volatile signed __int32 *)&unk_180029538 && *v5 != nullptr )
        _InterlockedAdd(*v5, 0xFFFFFFFF);
      if ( *(v5 - 3) != nullptr )
      {
        v7 = *(v5 - 1);
        if ( v7 != nullptr )
          _InterlockedAdd(v7, 0xFFFFFFFF);
      }
      v5 += 4;
    }
    _acrt_locale_release_lc_time_reference(*(_QWORD *)(a1 + 288));
  }
}


// ===== __acrt_update_thread_locale_data @ 0x180013f40 size=0x70 =====
__int64 _acrt_update_thread_locale_data()
{
  struct __acrt_ptd *v0; // rax
  struct __acrt_ptd *v1; // rdi
  __int64 v2; // rbx

  v0 = _acrt_getptd();
  v1 = v0;
  if ( (dword_180029A88 & *((_DWORD *)v0 + 234)) == 0 || (v2 = *((_QWORD *)v0 + 18)) == 0 )
  {
    sub_180011524(4);
    v2 = updatetlocinfoEx_nolock((char *)v1 + 144, qword_18002ABE8);
    sub_180011578(4);
    if ( v2 == 0 )
      abort();
  }
  return v2;
}


// ===== _updatetlocinfoEx_nolock @ 0x180013fb0 size=0x68 =====
__int64 __fastcall updatetlocinfoEx_nolock(__int64 *a1, __int64 a2)
{
  __int64 v3; // rbx

  if ( a2 == 0 || a1 == nullptr )
    return 0;
  v3 = *a1;
  if ( *a1 == a2 )
    return a2;
  *a1 = a2;
  _acrt_add_locale_ref(a2);
  if ( v3 != 0 )
  {
    _acrt_release_locale_ref(v3);
    if ( *(_DWORD *)(v3 + 16) == 0 && (wchar_t **)v3 != &off_1800293D0 )
      _acrt_free_locale((char *)v3);
  }
  return a2;
}


// ===== sub_180014018 @ 0x180014018 size=0x7 =====
__int64 sub_180014018()
{
  return (unsigned int)dword_18002B438;
}


// ===== _isleadbyte_l @ 0x180014020 size=0x3f =====
int __cdecl isleadbyte_l(int C, _locale_t Locale)
{
  unsigned __int8 v2; // bl
  int result; // eax
  _QWORD v4[3]; // [rsp+20h] [rbp-28h] BYREF
  char v5; // [rsp+38h] [rbp-10h]

  v2 = C;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v4, Locale);
  result = *(_WORD *)(*(_QWORD *)v4[1] + 2LL * v2) & 0x8000;
  if ( v5 != 0 )
    *(_DWORD *)(v4[0] + 936LL) &= ~2u;
  return result;
}


// ===== ?__acrt_LCMapStringA_stat@@YAHPEAU__crt_locale_pointers@@PEB_WKPEBDHPEADHHH@Z @ 0x180014060 size=0x35b =====
int __fastcall __acrt_LCMapStringA_stat(
        struct __crt_locale_pointers *a1,
        const wchar_t *a2,
        DWORD a3,
        const char *a4,
        int a5,
        char *a6,
        int a7,
        UINT CodePage,
        int a9)
{
  int v9; // ebx
  int v13; // eax
  UINT v14; // r14d
  int result; // eax
  int v16; // r12d
  unsigned __int64 v17; // rdx
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // rcx
  __int64 v20; // rax
  void *v21; // rsp
  WCHAR *v22; // rsi
  WCHAR *v23; // rax
  const wchar_t *v24; // r15
  int v25; // eax
  int v26; // edi
  unsigned __int64 v27; // rdx
  unsigned __int64 v28; // rax
  unsigned __int64 v29; // rcx
  __int64 v30; // rax
  void *v31; // rsp
  WCHAR *v32; // rbx
  WCHAR *v33; // rax
  _BYTE v34[32]; // [rsp+0h] [rbp-50h] BYREF
  LPWSTR lpWideCharStr; // [rsp+20h] [rbp-30h]
  int cchWideChar; // [rsp+28h] [rbp-28h]
  LPCCH v37; // [rsp+30h] [rbp-20h]
  LPBOOL v38; // [rsp+38h] [rbp-18h]
  const wchar_t *v39; // [rsp+50h] [rbp+0h] BYREF

  v9 = a5;
  v39 = a2;
  if ( a5 > 0 )
  {
    v13 = _strncnt(a4, a5);
    v9 = v13 + 1;
    if ( v13 >= a5 )
      v9 = v13;
  }
  v14 = CodePage;
  if ( CodePage == 0 )
    v14 = *((_DWORD *)a1->locinfo + 3);
  result = MultiByteToWideChar(v14, a9 != 0 ? 9 : 1, a4, v9, nullptr, 0);
  v16 = result;
  if ( result != 0 )
  {
    v17 = 2LL * result;
    if ( (-(__int64)(v17 < v17 + 16) & (v17 + 16)) == 0 )
    {
      v22 = nullptr;
      goto LABEL_17;
    }
    v18 = v17 + 16;
    if ( ((v17 + 16) & -(__int64)(v17 < v17 + 16)) > 0x400 )
    {
      v23 = (WCHAR *)malloc_base(v18 & -(__int64)(v17 < v18));
      v22 = v23;
      if ( v23 == nullptr )
      {
LABEL_17:
        if ( v22 != nullptr && MultiByteToWideChar(v14, 1u, a4, v9, v22, v16) != 0 )
        {
          v24 = v39;
          v25 = _acrt_LCMapStringEx((__int64)v39, a3, v22, v16, nullptr, 0, 0, 0, 0);
          v26 = v25;
          if ( v25 != 0 )
          {
            if ( (a3 & 0x400) != 0 )
            {
              if ( a7 == 0 )
                goto LABEL_43;
              if ( v25 <= a7 )
              {
                v26 = _acrt_LCMapStringEx((__int64)v24, a3, v22, v16, (WCHAR *)a6, a7, 0, 0, 0);
                if ( v26 != 0 )
                  goto LABEL_43;
              }
              goto LABEL_42;
            }
            v27 = 2LL * v25;
            if ( (-(__int64)(v27 < v27 + 16) & (v27 + 16)) == 0 )
            {
              v32 = nullptr;
LABEL_35:
              if ( v32 != nullptr )
              {
                if ( _acrt_LCMapStringEx((__int64)v24, a3, v22, v16, v32, v26, 0, 0, 0) != 0 )
                {
                  v38 = nullptr;
                  v37 = nullptr;
                  if ( a7 != 0 )
                  {
                    cchWideChar = a7;
                    lpWideCharStr = (LPWSTR)a6;
                  }
                  else
                  {
                    cchWideChar = 0;
                    lpWideCharStr = nullptr;
                  }
                  v26 = WideCharToMultiByte(v14, 0, v32, v26, (LPSTR)lpWideCharStr, cchWideChar, v37, v38);
                  if ( v26 != 0 )
                  {
                    if ( *((_DWORD *)v32 - 4) == 56797 )
                      free_base(v32 - 8);
                    goto LABEL_43;
                  }
                }
                if ( *((_DWORD *)v32 - 4) == 56797 )
                  free_base(v32 - 8);
              }
              goto LABEL_42;
            }
            v28 = v27 + 16;
            if ( ((v27 + 16) & -(__int64)(v27 < v27 + 16)) > 0x400 )
            {
              v33 = (WCHAR *)malloc_base(v28 & -(__int64)(v27 < v28));
              v32 = v33;
              if ( v33 == nullptr )
                goto LABEL_35;
              *(_DWORD *)v33 = 56797;
              goto LABEL_33;
            }
            v29 = v28 & -(__int64)(v27 < v28);
            v30 = v29 + 15;
            if ( v29 + 15 < v29 )
              v30 = 0xFFFFFFFFFFFFFF0LL;
            v31 = alloca(v30 & 0xFFFFFFFFFFFFFFF0uLL);
            v32 = (WCHAR *)&v39;
            if ( v34 != (_BYTE *)-80LL )
            {
              LODWORD(v39) = 52428;
LABEL_33:
              v32 += 8;
              goto LABEL_35;
            }
          }
        }
LABEL_42:
        v26 = 0;
LABEL_43:
        if ( v22 != nullptr && *((_DWORD *)v22 - 4) == 56797 )
          free_base(v22 - 8);
        return v26;
      }
      *(_DWORD *)v23 = 56797;
    }
    else
    {
      v19 = v18 & -(__int64)(v17 < v18);
      v20 = v19 + 15;
      if ( v19 + 15 < v19 )
        v20 = 0xFFFFFFFFFFFFFF0LL;
      v21 = alloca(v20 & 0xFFFFFFFFFFFFFFF0uLL);
      v22 = (WCHAR *)&v39;
      if ( v34 == (_BYTE *)-80LL )
        goto LABEL_42;
      LODWORD(v39) = 52428;
    }
    v22 += 8;
    goto LABEL_17;
  }
  return result;
}


// ===== __acrt_LCMapStringA @ 0x1800143bc size=0x96 =====
int __fastcall _acrt_LCMapStringA(
        struct __crt_locale_pointers *a1,
        wchar_t *a2,
        DWORD a3,
        char *a4,
        int a5,
        char *a6,
        int a7,
        UINT a8,
        int a9)
{
  int result; // eax
  __int64 v13; // [rsp+50h] [rbp-28h] BYREF
  struct __crt_locale_pointers v14; // [rsp+58h] [rbp-20h] BYREF
  char v15; // [rsp+68h] [rbp-10h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v13, a1);
  result = __acrt_LCMapStringA_stat(&v14, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( v15 != 0 )
    *(_DWORD *)(v13 + 936) &= ~2u;
  return result;
}


// ===== __acrt_fp_strflt_to_string @ 0x180014454 size=0xbf =====
__int64 __fastcall _acrt_fp_strflt_to_string(__int64 a1, unsigned __int64 a2, int a3, __int64 a4)
{
  int *v4; // rax
  unsigned int v5; // ebx
  int v7; // eax
  char *v8; // rdx
  char *v9; // rax
  char v10; // r10
  __int64 v11; // r8

  if ( a1 != 0 && a2 != 0 )
  {
    *(_BYTE *)a1 = 0;
    v7 = 0;
    if ( a3 > 0 )
      v7 = a3;
    if ( a2 <= v7 + 1 )
    {
      v4 = errno();
      v5 = 34;
      goto LABEL_3;
    }
    if ( a4 != 0 )
    {
      v8 = *(char **)(a4 + 8);
      v9 = (char *)(a1 + 1);
      *(_BYTE *)a1 = 48;
      while ( a3 > 0 )
      {
        v10 = *v8;
        if ( *v8 != 0 )
          ++v8;
        else
          v10 = 48;
        *v9++ = v10;
        --a3;
      }
      *v9 = 0;
      if ( a3 >= 0 && *v8 >= 53 )
      {
        while ( *--v9 == 57 )
          *v9 = 48;
        ++*v9;
      }
      if ( *(_BYTE *)a1 == 49 )
      {
        ++*(_DWORD *)(a4 + 4);
      }
      else
      {
        v11 = -1;
        do
          ++v11;
        while ( *(_BYTE *)(a1 + v11 + 1) != 0 );
        sub_1800098F0((__m128i *)a1, (const __m128i *)(a1 + 1), v11 + 1);
      }
      return 0;
    }
  }
  v4 = errno();
  v5 = 22;
LABEL_3:
  *v4 = v5;
  invalid_parameter_noinfo();
  return v5;
}


// ===== ?divide@__crt_strtox@@YA_KAEAUbig_integer@1@AEBU21@@Z @ 0x180014520 size=0x4ce =====
__int64 __fastcall __crt_strtox::divide(
        __crt_strtox *this,
        struct __crt_strtox::big_integer *a2,
        const struct __crt_strtox::big_integer *a3)
{
  __int64 v6; // r9
  unsigned int v7; // eax
  unsigned __int64 v8; // r15
  int v9; // r14d
  unsigned int v10; // ebx
  unsigned int v11; // ebx
  __int64 v12; // rdi
  unsigned __int64 v13; // rbp
  __int64 v14; // rax
  unsigned __int64 v15; // rtt
  __int64 v16; // rdx
  int v17; // r8d
  unsigned int v18; // r13d
  int v19; // r10d
  __int64 v20; // r11
  _DWORD *v21; // rcx
  unsigned int v22; // r10d
  unsigned int v23; // ebx
  bool v24; // zf
  int v25; // edx
  char v26; // r11
  unsigned int v27; // r10d
  unsigned int v28; // ebx
  int v29; // ebx
  __int64 v30; // r15
  __int64 v31; // rdi
  unsigned __int64 v32; // r11
  unsigned int v33; // ebp
  unsigned int v34; // r10d
  unsigned __int64 v35; // r8
  unsigned __int64 v36; // rax
  unsigned __int64 v37; // rcx
  __int64 v38; // r8
  unsigned __int64 v39; // rdx
  unsigned __int64 v40; // rcx
  unsigned int v41; // edx
  unsigned int *v42; // r9
  __int64 i; // rbx
  unsigned __int64 v44; // rcx
  unsigned int v45; // r10d
  char *v46; // r11
  unsigned int v47; // eax
  unsigned __int64 v48; // r9
  unsigned int v49; // r10d
  char *v50; // r11
  __int64 j; // rbx
  __int64 v52; // rdx
  char *v53; // rcx
  unsigned __int64 v54; // rdx
  unsigned int v55; // r9d
  unsigned int k; // ecx
  __int64 v57; // rax
  __int64 v58; // rdx
  char v59; // [rsp+20h] [rbp-238h]
  unsigned __int64 v60; // [rsp+28h] [rbp-230h]
  unsigned __int64 v61; // [rsp+30h] [rbp-228h]
  char v62; // [rsp+38h] [rbp-220h]
  _BYTE Source[468]; // [rsp+44h] [rbp-214h] BYREF
  int v64; // [rsp+260h] [rbp+8h]
  int v66; // [rsp+270h] [rbp+18h]
  unsigned int v67; // [rsp+278h] [rbp+20h]

  if ( *(_DWORD *)this == 0 || *(_DWORD *)a2 == 0 )
    return 0;
  v6 = (unsigned int)(*(_DWORD *)this - 1);
  v7 = *(_DWORD *)a2 - 1;
  if ( *(_DWORD *)a2 == 1 )
  {
    v8 = *((unsigned int *)a2 + 1);
    v9 = 0;
    if ( (_DWORD)v8 == 1 )
    {
      v10 = *((_DWORD *)this + 1);
      *(_DWORD *)this = 0;
      memcpy_s((char *)this + 4, 0x1CCu, Source, 0);
      return v10;
    }
    else if ( *(_DWORD *)this == 1 )
    {
      v11 = *((_DWORD *)this + 1);
      *(_DWORD *)this = 0;
      memcpy_s((char *)this + 4, 0x1CCu, Source, 0);
      *((_DWORD *)this + 1) = v11 % (unsigned int)v8;
      LOBYTE(v9) = v11 % (unsigned int)v8 != 0;
      *(_DWORD *)this = v9;
      return v11 / (unsigned int)v8;
    }
    else
    {
      v12 = 0;
      v13 = 0;
      if ( *(_DWORD *)this != 0 )
      {
        do
        {
          v14 = *((unsigned int *)this + v6 + 1);
          v6 = (unsigned int)(v6 - 1);
          v15 = (v13 << 32) | v14;
          v13 = v15 % v8;
          v12 = (unsigned int)(v15 / v8) + (v12 << 32);
        }
        while ( (_DWORD)v6 != -1 );
      }
      *(_DWORD *)this = 0;
      memcpy_s((char *)this + 4, 0x1CCu, Source, 0);
      *(_QWORD *)((char *)this + 4) = v13;
      LOBYTE(v9) = HIDWORD(v13) != 0;
      *(_DWORD *)this = v9 + 1;
      return v12;
    }
  }
  else if ( v7 <= (unsigned int)v6 )
  {
    v16 = (int)v6;
    v17 = v6 - v7;
    v18 = v7 + 1;
    v19 = *(_DWORD *)this - 1;
    if ( (int)v6 < (__int64)(int)(v6 - v7) )
      goto LABEL_20;
    v20 = (struct __crt_strtox::big_integer *)((char *)a2 - 4 * v17) - this;
    v21 = (_DWORD *)((char *)this + 4 * (int)v6 + 4);
    while ( *(_DWORD *)((char *)v21 + v20) == *v21 )
    {
      --v19;
      --v16;
      --v21;
      if ( v16 < v17 )
        goto LABEL_20;
    }
    if ( *((_DWORD *)a2 + v19 - (__int64)v17 + 1) < *((_DWORD *)this + v19 + 1) )
LABEL_20:
      ++v17;
    if ( v17 != 0 )
    {
      v22 = *((_DWORD *)a2 + v7 + 1);
      v23 = *((_DWORD *)a2 + v7);
      v24 = !_BitScanReverse(&v7, v22);
      v67 = *((_DWORD *)a2 + v18 - 1);
      if ( v24 )
        v25 = 32;
      else
        v25 = 31 - v7;
      v26 = 32 - v25;
      v66 = v25;
      v59 = 32 - v25;
      if ( v25 != 0 )
      {
        v27 = v23 >> v26;
        v28 = v23 << v25;
        v22 = (*((_DWORD *)a2 + v18) << v25) | v27;
        v67 = v28;
        if ( v18 > 2 )
          v67 = (*((_DWORD *)a2 + v18 - 2) >> v26) | v28;
      }
      v29 = v17 - 1;
      v64 = v17 - 1;
      v30 = 0;
      if ( v17 - 1 >= 0 )
      {
        v31 = v29 + v18;
        v32 = v22;
        v61 = v22;
        v62 = 32 - v25;
        do
        {
          if ( (unsigned int)v31 > (unsigned int)v6 )
            v33 = 0;
          else
            v33 = *((_DWORD *)this + v31 + 1);
          v34 = *((_DWORD *)this + (unsigned int)(v31 - 2) + 1);
          LODWORD(v60) = *((_DWORD *)this + (unsigned int)(v31 - 1) + 1);
          HIDWORD(v60) = v33;
          if ( v25 != 0 )
          {
            v35 = (v60 << v25) | ((unsigned __int64)v34 >> v62);
            v34 <<= v25;
            if ( (unsigned int)v31 >= 3 )
              v34 |= *((_DWORD *)this + (unsigned int)(v31 - 3) + 1) >> v59;
          }
          else
          {
            v35 = v60;
          }
          v36 = v35 / v32;
          v37 = (unsigned int)(v35 % v32);
          v38 = v36;
          if ( v36 > 0xFFFFFFFF )
          {
            v38 = 0xFFFFFFFFLL;
            v37 += v32 * (v36 - 0xFFFFFFFF);
          }
          if ( v37 <= 0xFFFFFFFF )
          {
            v39 = v38 * v67;
            do
            {
              if ( v39 <= (v34 | (v37 << 32)) )
                break;
              --v38;
              v39 -= v67;
              v37 += v61;
            }
            while ( v37 <= 0xFFFFFFFF );
            v29 = v64;
          }
          if ( v38 != 0 )
          {
            v40 = 0;
            if ( v18 != 0 )
            {
              v41 = v29;
              v42 = (unsigned int *)((char *)a2 + 4);
              for ( i = v18; i != 0; --i )
              {
                v44 = v38 * *v42 + v40;
                v45 = v44;
                v40 = HIDWORD(v44);
                v46 = (char *)this + 4 * v41;
                v47 = *((_DWORD *)v46 + 1);
                if ( v47 < v45 )
                  ++v40;
                ++v41;
                ++v42;
                *((_DWORD *)v46 + 1) = v47 - v45;
              }
              v29 = v64;
            }
            if ( v33 < v40 )
            {
              LODWORD(v48) = 0;
              if ( v18 != 0 )
              {
                v49 = v29;
                v50 = (char *)a2 + 4;
                for ( j = v18; j != 0; --j )
                {
                  v50 += 4;
                  v52 = *((unsigned int *)this + v49 + 1);
                  v53 = (char *)this + 4 * v49++;
                  v54 = (unsigned int)v48 + *((unsigned int *)v50 - 1) + v52;
                  *((_DWORD *)v53 + 1) = v54;
                  v48 = HIDWORD(v54);
                }
              }
              LODWORD(v38) = v38 - 1;
            }
            v29 = v64;
            LODWORD(v6) = v31 - 1;
          }
          v32 = v61;
          --v29;
          v25 = v66;
          v31 = (unsigned int)(v31 - 1);
          v30 = (unsigned int)v38 + (v30 << 32);
          v64 = v29;
        }
        while ( v29 >= 0 );
      }
      v55 = v6 + 1;
      for ( k = v55; k < *(_DWORD *)this; *((_DWORD *)this + v57 + 1) = 0 )
        v57 = k++;
      *(_DWORD *)this = v55;
      if ( v55 != 0 )
      {
        do
        {
          v58 = (unsigned int)(*(_DWORD *)this - 1);
          if ( *((_DWORD *)this + v58 + 1) != 0 )
            break;
          *(_DWORD *)this = v58;
        }
        while ( (_DWORD)v58 != 0 );
      }
      return v30;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 0;
  }
}


// ===== __acrt_fltout @ 0x1800149f0 size=0x136b =====
int __fastcall _acrt_fltout(__int64 a1, int a2, __int64 a3, char *a4, rsize_t SizeInBytes)
{
  __int64 v8; // rbx
  __int64 v9; // rax
  __int64 v10; // rax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  __int64 v15; // xmm0_8
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // r14
  int v18; // ebx
  double v19; // xmm0_8
  unsigned __int64 v20; // r8
  double v21; // xmm0_8
  unsigned __int64 v22; // r14
  int v23; // r12d
  unsigned int v24; // edx
  unsigned int v25; // r11d
  unsigned int v26; // r9d
  int v27; // ebx
  bool v28; // zf
  int v29; // eax
  int v30; // eax
  unsigned int v31; // edi
  unsigned int v32; // eax
  bool v33; // r15
  char v34; // cl
  unsigned int v35; // r14d
  __int64 v36; // rdi
  __int32 v37; // r10d
  __int64 v38; // rax
  __int32 v39; // edx
  unsigned int i; // ecx
  __int64 v41; // rax
  unsigned int v42; // r15d
  unsigned int v43; // r11d
  unsigned int v44; // r9d
  int v45; // ebx
  int v46; // eax
  int v47; // eax
  unsigned int v48; // edi
  unsigned int v49; // eax
  bool v50; // r12
  bool v51; // cl
  __int64 v52; // rdi
  __int32 v53; // r10d
  __int64 v54; // rax
  __int32 v55; // edx
  unsigned int j; // ecx
  __int64 v57; // rax
  int v58; // r8d
  int v59; // eax
  int v60; // eax
  unsigned int v61; // edi
  unsigned int v62; // ecx
  __int32 v63; // r8d
  __int64 v64; // rax
  unsigned __int32 v65; // edx
  __int64 v66; // rax
  int v67; // eax
  int v68; // eax
  int v69; // edi
  char v70; // al
  unsigned int v71; // ecx
  __int32 v72; // r8d
  __int64 v73; // rax
  unsigned __int32 v74; // edx
  __int64 v75; // rax
  char v76; // di
  unsigned int v77; // esi
  __int64 v78; // rbx
  unsigned int v79; // eax
  unsigned int v80; // r12d
  int v81; // r13d
  __int64 v82; // rax
  __int64 v83; // rsi
  unsigned __int64 v84; // rbx
  unsigned int v85; // r11d
  __int64 v86; // r10
  __int64 v87; // r9
  unsigned __int64 v88; // rcx
  char v89; // al
  __int64 v90; // rbx
  __int64 v91; // r9
  unsigned __int64 v92; // rcx
  unsigned int v93; // r12d
  __m128i *v94; // r13
  __m128i *v95; // rdx
  __int64 v96; // r10
  __int64 v97; // rsi
  unsigned __int64 v98; // rbx
  unsigned int v99; // r9d
  __int64 v100; // rdx
  unsigned __int64 v101; // rdx
  __int64 v102; // rcx
  unsigned __int64 v103; // rdx
  int v104; // edi
  int v105; // eax
  unsigned int v106; // eax
  unsigned int v107; // r9d
  __int64 v108; // rdx
  unsigned __int64 v109; // rcx
  unsigned int v110; // ecx
  unsigned int v111; // eax
  unsigned int v112; // r12d
  int v113; // r13d
  __int64 v114; // rax
  __int64 v115; // rsi
  unsigned __int64 v116; // rbx
  unsigned int v117; // edi
  __int64 v118; // r10
  __int64 v119; // r9
  unsigned __int64 v120; // rcx
  char v121; // al
  __int64 v122; // rbx
  __int64 v123; // r9
  unsigned __int64 v124; // rcx
  unsigned int v125; // r12d
  __m128i *v126; // r13
  __m128i *v127; // rdx
  __int64 v128; // r10
  __int64 v129; // rsi
  unsigned __int64 v130; // rbx
  unsigned int v131; // r9d
  __int64 v132; // rdx
  unsigned __int64 v133; // rdx
  __int64 v134; // rcx
  unsigned __int64 v135; // rdx
  unsigned int v136; // ecx
  unsigned int v137; // eax
  unsigned int v138; // r9d
  __int64 v139; // rdx
  unsigned __int64 v140; // rcx
  char *v141; // rsi
  char *v142; // rbx
  unsigned int v143; // r9d
  __int64 v144; // rdx
  unsigned __int64 v145; // r8
  int v146; // eax
  unsigned __int64 v147; // r8
  unsigned int v148; // r9d
  __int64 v149; // rdx
  unsigned __int64 v150; // r8
  unsigned int v151; // ecx
  rsize_t v152; // rdi
  char *k; // rdi
  unsigned int v154; // r10d
  const struct __crt_strtox::big_integer *v155; // r8
  unsigned int v156; // r9d
  __int64 v157; // rdx
  unsigned __int64 v158; // rcx
  unsigned int v159; // r8d
  unsigned int m; // r9d
  char v161; // cl
  int v163; // [rsp+30h] [rbp-D0h]
  __m128i *X; // [rsp+38h] [rbp-C8h] BYREF
  unsigned int v165; // [rsp+40h] [rbp-C0h]
  int v166; // [rsp+44h] [rbp-BCh]
  unsigned int v167; // [rsp+48h] [rbp-B8h]
  unsigned int v168; // [rsp+4Ch] [rbp-B4h]
  char *v169; // [rsp+50h] [rbp-B0h]
  __int64 v170; // [rsp+58h] [rbp-A8h]
  fenv_t Env; // [rsp+60h] [rbp-A0h] BYREF
  char v172; // [rsp+68h] [rbp-98h]
  __int64 v173; // [rsp+70h] [rbp-90h]
  unsigned int v174; // [rsp+80h] [rbp-80h] BYREF
  __m128i Destination[28]; // [rsp+84h] [rbp-7Ch] BYREF
  unsigned int v176; // [rsp+250h] [rbp+150h] BYREF
  __m128i v177; // [rsp+254h] [rbp+154h] BYREF
  unsigned int v178; // [rsp+420h] [rbp+320h]
  __m128i Source[28]; // [rsp+424h] [rbp+324h] BYREF
  unsigned int v180; // [rsp+5F0h] [rbp+4F0h]
  __m128i v181; // [rsp+5F4h] [rbp+4F4h] BYREF

  X = (__m128i *)a1;
  v169 = a4;
  v173 = a3;
  fegetenv(&Env);
  if ( (Env._Fe_ctl & 0x1F) == 0x1F )
  {
    v172 = 0;
  }
  else
  {
    feholdexcept(&Env);
    v172 = 1;
  }
  v8 = (__int64)X;
  v9 = (__int64)X;
  *(_QWORD *)(a3 + 8) = a4;
  *(_DWORD *)a3 = v9 < 0 ? 45 : 32;
  if ( (v8 & 0x7FF0000000000000LL) == 0 && (v8 & 0xFFFFFFFFFFFFFLL) == 0 )
  {
    *(_DWORD *)(a3 + 4) = 0;
    LODWORD(v10) = strcpy_s(a4, SizeInBytes, "0");
    if ( (_DWORD)v10 != 0 )
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
    goto LABEL_315;
  }
  v11 = __acrt_fp_classify((__int64 *)&X);
  if ( v11 != 0 )
    *(_DWORD *)(a3 + 4) = 1;
  v12 = v11 - 1;
  if ( v12 == 0 )
  {
    LODWORD(v10) = strcpy_s(a4, SizeInBytes, "1#INF");
    if ( (_DWORD)v10 != 0 )
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
    goto LABEL_315;
  }
  v13 = v12 - 1;
  if ( v13 == 0 )
  {
    LODWORD(v10) = strcpy_s(a4, SizeInBytes, "1#QNAN");
    if ( (_DWORD)v10 != 0 )
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
    goto LABEL_315;
  }
  v14 = v13 - 1;
  if ( v14 == 0 )
  {
    LODWORD(v10) = strcpy_s(a4, SizeInBytes, "1#SNAN");
    if ( (_DWORD)v10 != 0 )
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
    goto LABEL_315;
  }
  if ( v14 == 1 )
  {
    LODWORD(v10) = strcpy_s(a4, SizeInBytes, "1#IND");
    if ( (_DWORD)v10 != 0 )
      invoke_watson(nullptr, nullptr, nullptr, 0, 0);
    goto LABEL_315;
  }
  X = (__m128i *)(v8 & 0x7FFFFFFFFFFFFFFFLL);
  v15 = v8 & 0x7FFFFFFFFFFFFFFFLL;
  v170 = v8 & 0x7FFFFFFFFFFFFFFFLL;
  v168 = a2 + 1;
  v16 = (v8 & 0x7FFFFFFFFFFFFFFFuLL) >> 52;
  v17 = (v8 & 0xFFFFFFFFFFFFFLL) + (-(__int64)(v16 != 0) & 0x10000000000000LL);
  v18 = (v16 == 0) + 1 + v16 - 1076;
  v19 = log10(*(double *)&v15);
  v21 = ceil(v19);
  Destination[0].m128i_i32[0] = v17;
  v22 = HIDWORD(v17);
  v23 = (((int)v21 - 0x7FFFFFFF) & 0xFFFFFFFE) != 0 ? (int)v21 : 0;
  Destination[0].m128i_i32[1] = v22;
  v163 = v23;
  v24 = ((_DWORD)v22 != 0) + 1;
  v174 = v24;
  if ( v18 < 0 )
  {
    if ( v18 != -1022 )
    {
      Source[0].m128i_i64[0] = 0x10000000000000LL;
      v178 = 2;
      if ( (_DWORD)v22 != 0 )
      {
        v58 = 0;
        while ( Source[0].m128i_i32[v58] == Destination[0].m128i_i32[v58] )
        {
          if ( ++v58 == 2 )
          {
            v28 = !_BitScanReverse((unsigned int *)&v59, v22);
            LODWORD(X) = 0;
            if ( v28 )
              v60 = 0;
            else
              v60 = v59 + 1;
            v61 = 32 - v60;
            v62 = 2;
            while ( 1 )
            {
              v63 = v62 >= v24 ? 0 : Destination[0].m128i_i32[v62];
              v64 = v62 - 1;
              v65 = (unsigned int)v64 >= v24 ? 0 : Destination[0].m128i_i32[v64];
              v66 = v62--;
              Destination[0].m128i_i32[v66] = (4 * v63) ^ (v65 >> 30);
              if ( v62 == -1 )
                break;
              v24 = v174;
            }
            v35 = (v61 < 2) + 2;
            v174 = v35;
            sub_180009D50(Source, 0, 4LL * ((unsigned int)(2 - v18) >> 5));
            v42 = ((unsigned int)(2 - v18) >> 5) + 1;
            v20 = 4LL * v42;
            Source[0].m128i_i32[(unsigned int)(2 - v18) >> 5] = 1 << ((2 - v18) & 0x1F);
            goto LABEL_93;
          }
        }
      }
    }
    LODWORD(X) = 0;
    v28 = !_BitScanReverse((unsigned int *)&v67, Destination[0].m128i_u32[(_DWORD)v22 != 0]);
    if ( v28 )
      v68 = 0;
    else
      v68 = v67 + 1;
    v69 = 32 - v68;
    if ( ((_DWORD)v22 != 0) != 114 || (v70 = 1, v69 != 0) )
      v70 = 0;
    if ( v70 != 0 )
    {
      v35 = 0;
      v174 = 0;
    }
    else
    {
      v35 = 114;
      if ( v24 < 0x72 )
        v35 = v24;
      v71 = v35;
      while ( 1 )
      {
        v72 = v71 >= v24 ? 0 : Destination[0].m128i_i32[v71];
        v73 = v71 - 1;
        v74 = (unsigned int)v73 >= v24 ? 0 : Destination[0].m128i_i32[v73];
        v75 = v71--;
        Destination[0].m128i_i32[v75] = (2 * v72) ^ (v74 >> 31);
        if ( v71 == -1 )
          break;
        v24 = v174;
      }
      if ( v69 == 0 )
        ++v35;
      v174 = v35;
    }
    v76 = 1 - v18;
    v77 = (unsigned int)(1 - v18) >> 5;
    v78 = v77;
    sub_180009D50(Source, 0, v78 * 4);
    v42 = v77 + 1;
    Source[0].m128i_i32[v78] = 1 << (v76 & 0x1F);
    v20 = 4LL * (v77 + 1);
LABEL_93:
    v176 = v42;
    v178 = v42;
    if ( v20 != 0 )
    {
      if ( v20 > 0x1CC )
      {
        sub_180009D50(&v177, 0, 0x1CCu);
        *errno() = 34;
        invalid_parameter_noinfo();
      }
      else
      {
        sub_1800098F0(&v177, Source, v20);
      }
      v42 = v176;
    }
  }
  else
  {
    Source[0].m128i_i64[0] = 0x10000000000000LL;
    v178 = 2;
    if ( (_DWORD)v22 != 0 )
    {
      v20 = 0;
      while ( Source[0].m128i_i32[(unsigned int)v20] == Destination[0].m128i_i32[(unsigned int)v20] )
      {
        v20 = (unsigned int)(v20 + 1);
        if ( (_DWORD)v20 == 2 )
        {
          LODWORD(X) = 0;
          v25 = (v18 + 2) & 0x1F;
          v26 = (unsigned int)(v18 + 2) >> 5;
          v27 = (1LL << (32 - ((v18 + 2) & 0x1Fu))) - 1;
          v28 = !_BitScanReverse((unsigned int *)&v29, v22);
          if ( v28 )
            v30 = 0;
          else
            v30 = v29 + 1;
          v31 = 32 - v30;
          v32 = v26 + 2;
          v33 = v25 > v31;
          LOBYTE(v20) = v26 + 2 > 0x73;
          if ( v26 != 113 || (v34 = 1, v25 <= v31) )
            v34 = 0;
          if ( v32 > 0x73 || v34 != 0 )
          {
            v35 = 0;
            v174 = 0;
          }
          else
          {
            v35 = 114;
            if ( v32 < 0x72 )
              v35 = v26 + 2;
            v20 = v35 - v26;
            while ( 1 )
            {
              v36 = (unsigned int)v20 + v26;
              if ( (unsigned int)v36 < v26 )
                break;
              v37 = (unsigned int)v20 >= v24 ? 0 : Destination[0].m128i_i32[v20];
              v38 = (unsigned int)(v20 - 1);
              v39 = (unsigned int)v38 >= v24 ? 0 : Destination[0].m128i_i32[v38];
              v20 = (unsigned int)(v20 - 1);
              Destination[0].m128i_i32[v36] = ((v27 & v37) << v25) | ((~v27 & (unsigned int)v39) >> (32 - v25));
              if ( (_DWORD)v20 + v26 == -1 )
                break;
              v24 = v174;
            }
            for ( i = 0; i != v26; Destination[0].m128i_i32[v41] = 0 )
              v41 = i++;
            if ( v33 )
              ++v35;
            v174 = v35;
          }
          v177.m128i_i32[0] = 4;
          goto LABEL_46;
        }
      }
    }
    LODWORD(X) = 0;
    v43 = (v18 + 1) & 0x1F;
    v44 = (unsigned int)(v18 + 1) >> 5;
    v45 = (1LL << (32 - ((v18 + 1) & 0x1Fu))) - 1;
    v28 = !_BitScanReverse((unsigned int *)&v46, Destination[0].m128i_u32[(_DWORD)v22 != 0]);
    if ( v28 )
      v47 = 0;
    else
      v47 = v46 + 1;
    v48 = 32 - v47;
    v49 = v24 + v44;
    v50 = v43 > v48;
    LOBYTE(v20) = v24 + v44 > 0x73;
    v51 = v24 + v44 == 115 && v43 > v48;
    if ( v49 > 0x73 || v51 )
    {
      v35 = 0;
      v174 = 0;
    }
    else
    {
      v35 = 114;
      if ( v49 < 0x72 )
        v35 = v24 + v44;
      v20 = v35 - v44;
      while ( 1 )
      {
        v52 = (unsigned int)v20 + v44;
        if ( (unsigned int)v52 < v44 )
          break;
        v53 = (unsigned int)v20 >= v24 ? 0 : Destination[0].m128i_i32[v20];
        v54 = (unsigned int)(v20 - 1);
        v55 = (unsigned int)v54 >= v24 ? 0 : Destination[0].m128i_i32[v54];
        Destination[0].m128i_i32[v52] = ((~v45 & (unsigned int)v55) >> (32 - v43)) | ((v45 & v53) << v43);
        v20 = (unsigned int)(v20 - 1);
        if ( (_DWORD)v20 + v44 == -1 )
          break;
        v24 = v174;
      }
      for ( j = 0; j != v44; Destination[0].m128i_i32[v57] = 0 )
        v57 = j++;
      if ( v50 )
        ++v35;
      v174 = v35;
    }
    v177.m128i_i32[0] = 2;
LABEL_46:
    v23 = (((int)v21 - 0x7FFFFFFF) & 0xFFFFFFFE) != 0 ? (int)v21 : 0;
    v42 = 1;
    v176 = 1;
    v178 = 1;
    Source[0].m128i_i32[1] = 0;
  }
  if ( v23 >= 0 )
  {
    v79 = v23 / 0xAu;
    v167 = v79;
    v80 = v23 / 0xAu;
    v165 = v79;
    if ( v79 == 0 )
      goto LABEL_183;
    while ( 1 )
    {
      v81 = v80;
      if ( v80 > 0x26 )
        v81 = 38;
      v166 = v81;
      v82 = (unsigned int)(v81 - 1);
      v83 = (unsigned __int8)byte_18001E993[4 * v82];
      v84 = 4LL * (unsigned __int8)byte_18001E992[4 * v82];
      v178 = v83 + (unsigned __int8)byte_18001E992[4 * v82];
      sub_180009D50(Source, 0, v84);
      sub_1800098F0(
        (__m128i *)((char *)Source + v84),
        (const __m128i *)((char *)&unk_18001E080 + 4 * (unsigned __int16)word_18001E990[2 * (v81 - 1)]),
        4 * v83);
      v85 = v178;
      if ( v178 > 1 )
      {
        if ( v42 > 1 )
        {
          v93 = v42;
          v94 = Source;
          v95 = &v177;
          if ( v178 < v42 )
          {
            v93 = v178;
            v85 = v42;
          }
          else
          {
            v94 = &v177;
          }
          if ( v178 >= v42 )
            v95 = Source;
          v42 = 0;
          v96 = 0;
          X = v95;
          v180 = 0;
          while ( 1 )
          {
            v97 = v94->m128i_u32[v96];
            if ( (_DWORD)v97 != 0 )
            {
              LODWORD(v98) = 0;
              v99 = v96;
              if ( v85 != 0 )
              {
                while ( v99 != 115 )
                {
                  if ( v99 == v42 )
                  {
                    v181.m128i_i32[v99] = 0;
                    v180 = v99 + 1;
                  }
                  v20 = v99;
                  v100 = v95->m128i_u32[v99 - (unsigned int)v96];
                  ++v99;
                  v101 = v181.m128i_u32[v20] + (unsigned int)v98 + v97 * v100;
                  v181.m128i_i32[v20] = v101;
                  v42 = v180;
                  v98 = HIDWORD(v101);
                  if ( v99 - (_DWORD)v96 == v85 )
                    break;
                  v95 = X;
                }
                if ( (_DWORD)v98 != 0 )
                {
                  while ( v99 != 115 )
                  {
                    if ( v99 == v42 )
                    {
                      v181.m128i_i32[v99] = 0;
                      v180 = v99 + 1;
                    }
                    v102 = v99++;
                    v103 = v181.m128i_u32[v102] + (unsigned __int64)(unsigned int)v98;
                    v181.m128i_i32[v102] = v103;
                    v42 = v180;
                    LODWORD(v98) = HIDWORD(v103);
                    if ( HIDWORD(v103) == 0 )
                      goto LABEL_170;
                  }
LABEL_192:
                  v42 = 0;
                  v176 = 0;
LABEL_268:
                  v104 = v163;
LABEL_269:
                  v141 = v169;
                  v142 = v169;
                  if ( v35 != 0 )
                  {
                    LODWORD(v20) = 0;
                    v143 = 0;
                    do
                    {
                      v144 = v143++;
                      v145 = (unsigned int)v20 + 10LL * Destination[0].m128i_u32[v144];
                      Destination[0].m128i_i32[v144] = v145;
                      v20 = HIDWORD(v145);
                    }
                    while ( v143 != v35 );
                    if ( (_DWORD)v20 != 0 )
                    {
                      if ( v174 >= 0x73 )
                      {
                        v178 = 0;
                        v174 = 0;
                        memcpy_s(Destination, 0x1CCu, Source, 0);
                      }
                      else
                      {
                        Destination[0].m128i_i32[v174++] = v20;
                      }
                    }
                  }
                  goto LABEL_276;
                }
              }
LABEL_170:
              if ( v99 == 115 )
                goto LABEL_192;
              v95 = X;
            }
            else if ( (_DWORD)v96 == v42 )
            {
              v181.m128i_i32[v96] = 0;
              v42 = v96 + 1;
              v180 = v96 + 1;
            }
            v96 = (unsigned int)(v96 + 1);
            if ( (_DWORD)v96 == v93 )
            {
              v20 = 4LL * v42;
              v176 = v42;
              if ( v20 != 0 )
              {
                if ( v20 > 0x1CC )
                {
                  sub_180009D50(&v177, 0, 0x1CCu);
                  *errno() = 34;
                  invalid_parameter_noinfo();
                }
                else
                {
                  sub_1800098F0(&v177, &v181, v20);
                }
                v42 = v176;
              }
              v80 = v165;
              v81 = v166;
              goto LABEL_179;
            }
          }
        }
        v90 = v177.m128i_u32[0];
        v20 = 4LL * v178;
        v42 = v178;
        v176 = v178;
        if ( v20 != 0 )
        {
          if ( v20 > 0x1CC )
          {
            sub_180009D50(&v177, 0, 0x1CCu);
            *errno() = 34;
            invalid_parameter_noinfo();
          }
          else
          {
            sub_1800098F0(&v177, Source, v20);
          }
          v42 = v176;
        }
        if ( (_DWORD)v90 == 0 )
        {
LABEL_127:
          v42 = 0;
          goto LABEL_128;
        }
        if ( (_DWORD)v90 == 1 || v42 == 0 )
          goto LABEL_179;
        LODWORD(v20) = 0;
        v91 = 0;
        do
        {
          v92 = (unsigned int)v20 + v90 * v177.m128i_u32[v91];
          v177.m128i_i32[v91] = v92;
          v20 = HIDWORD(v92);
          v91 = (unsigned int)(v91 + 1);
        }
        while ( (_DWORD)v91 != v42 );
      }
      else
      {
        if ( Source[0].m128i_i32[0] == 0 )
          goto LABEL_127;
        if ( Source[0].m128i_i32[0] == 1 || v42 == 0 )
          goto LABEL_179;
        LODWORD(v20) = 0;
        v86 = Source[0].m128i_u32[0];
        v87 = 0;
        do
        {
          v88 = (unsigned int)v20 + v86 * v177.m128i_u32[v87];
          v177.m128i_i32[v87] = v88;
          v20 = HIDWORD(v88);
          v87 = (unsigned int)(v87 + 1);
        }
        while ( (_DWORD)v87 != v42 );
      }
      if ( (_DWORD)v20 == 0 )
        break;
      if ( v176 < 0x73 )
      {
        v177.m128i_i32[v176] = v20;
        v42 = v176 + 1;
LABEL_128:
        v176 = v42;
LABEL_179:
        v89 = 1;
        goto LABEL_180;
      }
      v42 = 0;
      v176 = 0;
      v89 = 0;
LABEL_180:
      if ( v89 == 0 )
        goto LABEL_192;
      v80 -= v81;
      v165 = v80;
      if ( v80 == 0 )
      {
        v79 = v167;
LABEL_183:
        v104 = v163;
        v105 = 10 * v79;
        if ( v163 == v105 )
          goto LABEL_269;
        v106 = dword_18001EA28[v163 - v105 - 1];
        if ( v106 != 0 )
        {
          if ( v106 == 1 || v42 == 0 )
            goto LABEL_269;
          LODWORD(v20) = 0;
          v107 = 0;
          do
          {
            v108 = v107++;
            v109 = (unsigned int)v20 + v106 * (unsigned __int64)v177.m128i_u32[v108];
            v177.m128i_i32[v108] = v109;
            v20 = HIDWORD(v109);
          }
          while ( v107 != v42 );
          if ( HIDWORD(v109) == 0 )
          {
            v42 = v176;
            goto LABEL_269;
          }
          if ( v176 < 0x73 )
          {
            v177.m128i_i32[v176] = HIDWORD(v109);
            v42 = ++v176;
            goto LABEL_269;
          }
        }
        v42 = 0;
        v176 = 0;
        goto LABEL_269;
      }
    }
    v42 = v176;
    goto LABEL_179;
  }
  v110 = -v23;
  v166 = -v23;
  v111 = v110 / 0xA;
  LODWORD(X) = -v23 / 0xAu;
  v112 = (unsigned int)X;
  v165 = v110 / 0xA;
  if ( v110 / 0xA == 0 )
    goto LABEL_256;
  do
  {
    v113 = v112;
    if ( v112 > 0x26 )
      v113 = 38;
    v167 = v113;
    v114 = (unsigned int)(v113 - 1);
    v115 = (unsigned __int8)byte_18001E993[4 * v114];
    v116 = 4LL * (unsigned __int8)byte_18001E992[4 * v114];
    v178 = v115 + (unsigned __int8)byte_18001E992[4 * v114];
    sub_180009D50(Source, 0, v116);
    sub_1800098F0(
      (__m128i *)((char *)Source + v116),
      (const __m128i *)((char *)&unk_18001E080 + 4 * (unsigned __int16)word_18001E990[2 * (v113 - 1)]),
      4 * v115);
    v117 = v178;
    if ( v178 > 1 )
    {
      if ( v35 > 1 )
      {
        v125 = v35;
        v126 = Source;
        v127 = Destination;
        if ( v178 < v35 )
        {
          v125 = v178;
          v117 = v35;
        }
        else
        {
          v126 = Destination;
        }
        if ( v178 >= v35 )
          v127 = Source;
        v35 = 0;
        v128 = 0;
        v170 = (__int64)v127;
        v180 = 0;
        do
        {
          v129 = v126->m128i_u32[v128];
          if ( (_DWORD)v129 != 0 )
          {
            LODWORD(v130) = 0;
            v131 = v128;
            if ( v117 != 0 )
            {
              while ( v131 != 115 )
              {
                if ( v131 == v35 )
                {
                  v181.m128i_i32[v131] = 0;
                  v180 = v131 + 1;
                }
                v20 = v131;
                v132 = v127->m128i_u32[v131 - (unsigned int)v128];
                ++v131;
                v133 = (unsigned int)v130 + v181.m128i_u32[v20] + v129 * v132;
                v181.m128i_i32[v20] = v133;
                v35 = v180;
                v130 = HIDWORD(v133);
                if ( v131 - (_DWORD)v128 == v117 )
                  break;
                v127 = (__m128i *)v170;
              }
              if ( (_DWORD)v130 != 0 )
              {
                while ( v131 != 115 )
                {
                  if ( v131 == v35 )
                  {
                    v181.m128i_i32[v131] = 0;
                    v180 = v131 + 1;
                  }
                  v134 = v131++;
                  v135 = (unsigned int)v130 + (unsigned __int64)v181.m128i_u32[v134];
                  v181.m128i_i32[v134] = v135;
                  v35 = v180;
                  LODWORD(v130) = HIDWORD(v135);
                  if ( HIDWORD(v135) == 0 )
                    goto LABEL_243;
                }
LABEL_265:
                v141 = v169;
                v104 = v163;
                v142 = v169;
                v174 = 0;
                goto LABEL_276;
              }
            }
LABEL_243:
            if ( v131 == 115 )
              goto LABEL_265;
            v127 = (__m128i *)v170;
          }
          else if ( (_DWORD)v128 == v35 )
          {
            v181.m128i_i32[v128] = 0;
            v35 = v128 + 1;
            v180 = v128 + 1;
          }
          v128 = (unsigned int)(v128 + 1);
        }
        while ( (_DWORD)v128 != v125 );
        v20 = 4LL * v35;
        v174 = v35;
        if ( v20 != 0 )
        {
          if ( v20 > 0x1CC )
          {
            sub_180009D50(Destination, 0, 0x1CCu);
            *errno() = 34;
            invalid_parameter_noinfo();
          }
          else
          {
            sub_1800098F0(Destination, &v181, v20);
          }
          v35 = v174;
        }
        v112 = v165;
        v113 = v167;
        goto LABEL_252;
      }
      v122 = Destination[0].m128i_u32[0];
      v20 = 4LL * v178;
      v35 = v178;
      v174 = v178;
      if ( v20 != 0 )
      {
        if ( v20 > 0x1CC )
        {
          sub_180009D50(Destination, 0, 0x1CCu);
          *errno() = 34;
          invalid_parameter_noinfo();
        }
        else
        {
          sub_1800098F0(Destination, Source, v20);
        }
        v35 = v174;
      }
      if ( (_DWORD)v122 == 0 )
      {
LABEL_200:
        v35 = 0;
        goto LABEL_201;
      }
      if ( (_DWORD)v122 == 1 || v35 == 0 )
        goto LABEL_252;
      LODWORD(v20) = 0;
      v123 = 0;
      do
      {
        v124 = (unsigned int)v20 + v122 * Destination[0].m128i_u32[v123];
        Destination[0].m128i_i32[v123] = v124;
        v20 = HIDWORD(v124);
        v123 = (unsigned int)(v123 + 1);
      }
      while ( (_DWORD)v123 != v35 );
    }
    else
    {
      if ( Source[0].m128i_i32[0] == 0 )
        goto LABEL_200;
      if ( Source[0].m128i_i32[0] == 1 || v35 == 0 )
        goto LABEL_252;
      LODWORD(v20) = 0;
      v118 = Source[0].m128i_u32[0];
      v119 = 0;
      do
      {
        v120 = (unsigned int)v20 + v118 * Destination[0].m128i_u32[v119];
        Destination[0].m128i_i32[v119] = v120;
        v20 = HIDWORD(v120);
        v119 = (unsigned int)(v119 + 1);
      }
      while ( (_DWORD)v119 != v35 );
    }
    if ( (_DWORD)v20 == 0 )
    {
      v35 = v174;
      goto LABEL_252;
    }
    if ( v174 >= 0x73 )
    {
      v35 = 0;
      v174 = 0;
      v121 = 0;
      goto LABEL_253;
    }
    Destination[0].m128i_i32[v174] = v20;
    v35 = v174 + 1;
LABEL_201:
    v174 = v35;
LABEL_252:
    v121 = 1;
LABEL_253:
    if ( v121 == 0 )
      goto LABEL_265;
    v112 -= v113;
    v165 = v112;
  }
  while ( v112 != 0 );
  v110 = v166;
  v111 = (unsigned int)X;
LABEL_256:
  v136 = v110 - 10 * v111;
  if ( v136 == 0 )
    goto LABEL_268;
  v137 = dword_18001EA28[v136 - 1];
  if ( v137 == 0 )
    goto LABEL_265;
  if ( v137 == 1 || v35 == 0 )
    goto LABEL_268;
  LODWORD(v20) = 0;
  v138 = 0;
  do
  {
    v139 = v138++;
    v140 = (unsigned int)v20 + v137 * (unsigned __int64)Destination[0].m128i_u32[v139];
    Destination[0].m128i_i32[v139] = v140;
    v20 = HIDWORD(v140);
  }
  while ( v138 != v35 );
  if ( HIDWORD(v140) == 0 )
  {
    v35 = v174;
    goto LABEL_268;
  }
  v104 = v163;
  if ( v174 < 0x73 )
  {
    Destination[0].m128i_i32[v174] = HIDWORD(v140);
    v35 = ++v174;
    goto LABEL_269;
  }
  v141 = v169;
  v142 = v169;
  v174 = 0;
LABEL_276:
  v146 = __crt_strtox::divide(
           (__crt_strtox *)&v174,
           (struct __crt_strtox::big_integer *)&v176,
           (const struct __crt_strtox::big_integer *)v20);
  if ( v146 == 10 )
  {
    ++v104;
    *v141 = 49;
    v142 = v141 + 1;
    if ( v42 != 0 )
    {
      LODWORD(v147) = 0;
      v148 = 0;
      do
      {
        v149 = v148++;
        v150 = (unsigned int)v147 + 10LL * v177.m128i_u32[v149];
        v177.m128i_i32[v149] = v150;
        v147 = HIDWORD(v150);
      }
      while ( v148 != v42 );
      if ( (_DWORD)v147 != 0 )
      {
        if ( v176 >= 0x73 )
        {
          v178 = 0;
          v176 = 0;
          memcpy_s(&v177, 0x1CCu, Source, 0);
        }
        else
        {
          v177.m128i_i32[v176++] = v147;
        }
      }
    }
  }
  else if ( v146 != 0 )
  {
    v142 = v141 + 1;
    *v141 = v146 + 48;
  }
  else
  {
    --v104;
  }
  v151 = v168;
  *(_DWORD *)(v173 + 4) = v104;
  if ( v104 >= 0 && v151 <= 0x7FFFFFFF )
    v151 += v104;
  LODWORD(v10) = SizeInBytes - 1;
  v152 = v151;
  if ( SizeInBytes - 1 < v151 )
    v152 = SizeInBytes - 1;
  for ( k = &v141[v152]; v142 != k; v142 += v10 )
  {
    v154 = v174;
    if ( v174 == 0 )
      break;
    LODWORD(v155) = 0;
    v156 = 0;
    do
    {
      v157 = v156++;
      v158 = (unsigned int)v155 + 1000000000LL * Destination[0].m128i_u32[v157];
      Destination[0].m128i_i32[v157] = v158;
      v155 = (const struct __crt_strtox::big_integer *)HIDWORD(v158);
    }
    while ( v156 != v154 );
    if ( HIDWORD(v158) != 0 )
    {
      if ( v174 >= 0x73 )
      {
        v178 = 0;
        v174 = 0;
        memcpy_s(Destination, 0x1CCu, Source, 0);
      }
      else
      {
        Destination[0].m128i_i32[v174++] = HIDWORD(v158);
      }
    }
    v159 = __crt_strtox::divide((__crt_strtox *)&v174, (struct __crt_strtox::big_integer *)&v176, v155);
    for ( m = 8; m != -1; --m )
    {
      v161 = v159 % 0xA + 48;
      v159 /= 0xAu;
      if ( (int)k - (int)v142 >= m )
        v142[m] = v161;
    }
    v10 = k - v142;
    if ( k - v142 > 9 )
      v10 = 9;
  }
  *v142 = 0;
LABEL_315:
  if ( v172 != 0 )
    LODWORD(v10) = fesetenv(&Env);
  return v10;
}


// ===== memcpy_s @ 0x180015d5c size=0x87 =====
static errno_t __cdecl memcpy_s(
        void *const Destination,
        const rsize_t DestinationSize,
        const void *const Source,
        const rsize_t SourceSize)
{
  int *v8; // rax
  errno_t v9; // ebx

  if ( SourceSize == 0 )
    return 0;
  if ( Destination != nullptr )
  {
    if ( Source != nullptr && DestinationSize >= SourceSize )
    {
      sub_1800098F0((__m128i *)Destination, (const __m128i *)Source, SourceSize);
      return 0;
    }
    sub_180009D50((__m128i *)Destination, 0, DestinationSize);
    if ( Source != nullptr )
    {
      if ( DestinationSize < SourceSize )
      {
        v8 = errno();
        v9 = 34;
        goto LABEL_5;
      }
      return 22;
    }
  }
  v8 = errno();
  v9 = 22;
LABEL_5:
  *v8 = v9;
  invalid_parameter_noinfo();
  return v9;
}


// ===== _fcloseall @ 0x180015de4 size=0xb2 =====
int __cdecl fcloseall()
{
  int i; // ebx
  __int64 v1; // rax
  int v3; // [rsp+20h] [rbp-18h]

  v3 = 0;
  sub_180011524(8);
  for ( i = 3; i != dword_18002ABB8; ++i )
  {
    v1 = *((_QWORD *)qword_18002ABC0 + i);
    if ( v1 != 0 )
    {
      if ( (*(_DWORD *)(v1 + 20) & 0x2000) != 0 && ftell(*((FILE **)qword_18002ABC0 + i)) != -1 )
        ++v3;
      DeleteCriticalSection((LPCRITICAL_SECTION)(*((_QWORD *)qword_18002ABC0 + i) + 48LL));
      free_base(*((void **)qword_18002ABC0 + i));
      *((_QWORD *)qword_18002ABC0 + i) = 0;
    }
  }
  sub_180011578(8);
  return v3;
}


// ===== _isatty @ 0x180015e98 size=0x5f =====
int __cdecl isatty(int FileHandle)
{
  if ( FileHandle == -2 )
  {
    *errno() = 9;
  }
  else
  {
    if ( FileHandle >= 0 && FileHandle < (unsigned int)dword_18002AFF0 )
      return *(_BYTE *)(qword_18002ABF0[(__int64)FileHandle >> 6] + ((unsigned __int64)(FileHandle & 0x3F) << 6) + 56)
           & 0x40;
    *errno() = 9;
    invalid_parameter_noinfo();
  }
  return 0;
}


// ===== __free_lconv_mon @ 0x180015ef8 size=0x10a =====
void __fastcall _free_lconv_mon(_QWORD *a1)
{
  void *v2; // rcx
  void *v3; // rcx
  void *v4; // rcx
  void *v5; // rcx
  void *v6; // rcx
  void *v7; // rcx
  void *v8; // rcx
  void *v9; // rcx
  void *v10; // rcx
  void *v11; // rcx
  void *v12; // rcx
  void *v13; // rcx
  void *v14; // rcx

  if ( a1 != nullptr )
  {
    v2 = (void *)a1[3];
    if ( v2 != off_180029AA8 )
      free_base(v2);
    v3 = (void *)a1[4];
    if ( v3 != off_180029AB0 )
      free_base(v3);
    v4 = (void *)a1[5];
    if ( v4 != off_180029AB8 )
      free_base(v4);
    v5 = (void *)a1[6];
    if ( v5 != off_180029AC0 )
      free_base(v5);
    v6 = (void *)a1[7];
    if ( v6 != off_180029AC8 )
      free_base(v6);
    v7 = (void *)a1[8];
    if ( v7 != off_180029AD0 )
      free_base(v7);
    v8 = (void *)a1[9];
    if ( v8 != off_180029AD8 )
      free_base(v8);
    v9 = (void *)a1[13];
    if ( v9 != off_180029AF8 )
      free_base(v9);
    v10 = (void *)a1[14];
    if ( v10 != off_180029B00 )
      free_base(v10);
    v11 = (void *)a1[15];
    if ( v11 != off_180029B08 )
      free_base(v11);
    v12 = (void *)a1[16];
    if ( v12 != off_180029B10 )
      free_base(v12);
    v13 = (void *)a1[17];
    if ( v13 != off_180029B18 )
      free_base(v13);
    v14 = (void *)a1[18];
    if ( v14 != off_180029B20 )
      free_base(v14);
  }
}


// ===== __free_lconv_num @ 0x180016004 size=0x6c =====
void __fastcall _free_lconv_num(__int64 a1)
{
  void *v2; // rcx
  void *v3; // rcx
  void *v4; // rcx
  void *v5; // rcx
  void *v6; // rcx

  if ( a1 != 0 )
  {
    v2 = *(void **)a1;
    if ( v2 != off_180029A90 )
      free_base(v2);
    v3 = *(void **)(a1 + 8);
    if ( v3 != off_180029A98 )
      free_base(v3);
    v4 = *(void **)(a1 + 16);
    if ( v4 != off_180029AA0 )
      free_base(v4);
    v5 = *(void **)(a1 + 88);
    if ( v5 != off_180029AE8 )
      free_base(v5);
    v6 = *(void **)(a1 + 96);
    if ( v6 != off_180029AF0 )
      free_base(v6);
  }
}


// ===== ?free_crt_array_internal@@YAXQEAPEBX_K@Z @ 0x180016070 size=0x56 =====
void __fastcall free_crt_array_internal(void **a1, __int64 a2)
{
  __int64 v2; // rdi
  void **v3; // rbx
  unsigned __int64 v4; // rsi

  v2 = 0;
  v3 = a1;
  v4 = (unsigned __int64)(8 * a2 + 7) >> 3;
  if ( a1 > &a1[a2] )
    v4 = 0;
  if ( v4 != 0 )
  {
    do
    {
      free_base(*v3);
      ++v2;
      ++v3;
    }
    while ( v2 != v4 );
  }
}


// ===== __acrt_locale_free_time @ 0x1800160c8 size=0x108 =====
void __fastcall _acrt_locale_free_time(void **a1)
{
  if ( a1 != nullptr )
  {
    free_crt_array_internal(a1, 7);
    free_crt_array_internal(a1 + 7, 7);
    free_crt_array_internal(a1 + 14, 12);
    free_crt_array_internal(a1 + 26, 12);
    free_crt_array_internal(a1 + 38, 2);
    free_base(a1[40]);
    free_base(a1[41]);
    free_base(a1[42]);
    free_crt_array_internal(a1 + 44, 7);
    free_crt_array_internal(a1 + 51, 7);
    free_crt_array_internal(a1 + 58, 12);
    free_crt_array_internal(a1 + 70, 12);
    free_crt_array_internal(a1 + 82, 2);
    free_base(a1[84]);
    free_base(a1[85]);
    free_base(a1[86]);
    free_base(a1[87]);
  }
}


// ===== __acrt_GetStringTypeA @ 0x1800161d0 size=0x1b1 =====
__int64 __fastcall _acrt_GetStringTypeA(
        struct __crt_locale_pointers *a1,
        DWORD dwInfoType,
        LPCCH lpMultiByteStr,
        int cbMultiByte,
        LPWORD lpCharType,
        UINT CodePage,
        int a7)
{
  UINT v10; // esi
  int v11; // eax
  __int64 cchWideChar; // r14
  unsigned int StringTypeW; // edi
  unsigned __int64 v14; // rdi
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rcx
  __int64 v17; // rax
  void *v18; // rsp
  __m128i *lpWideCharStr; // rbx
  __m128i *v20; // rax
  int v21; // eax
  __int64 v23; // [rsp+0h] [rbp-30h] BYREF
  _QWORD v24[3]; // [rsp+30h] [rbp+0h] BYREF
  char v25; // [rsp+48h] [rbp+18h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v24, a1);
  v10 = CodePage;
  if ( CodePage == 0 )
    v10 = *(_DWORD *)(v24[1] + 12LL);
  v11 = MultiByteToWideChar(v10, a7 != 0 ? 9 : 1, lpMultiByteStr, cbMultiByte, nullptr, 0);
  cchWideChar = v11;
  if ( v11 == 0 )
  {
    StringTypeW = 0;
    goto LABEL_22;
  }
  v14 = 2LL * v11;
  if ( (-(__int64)(v14 < v14 + 16) & (v14 + 16)) == 0 )
  {
    lpWideCharStr = nullptr;
    goto LABEL_15;
  }
  v15 = v14 + 16;
  if ( ((v14 + 16) & -(__int64)(v14 < v14 + 16)) <= 0x400 )
  {
    v16 = v15 & -(__int64)(v14 < v15);
    v17 = v16 + 15;
    if ( v16 + 15 < v16 )
      v17 = 0xFFFFFFFFFFFFFF0LL;
    v18 = alloca(v17 & 0xFFFFFFFFFFFFFFF0uLL);
    lpWideCharStr = (__m128i *)v24;
    if ( &v23 == (__int64 *)-48LL )
      goto LABEL_18;
    LODWORD(v24[0]) = 52428;
    goto LABEL_13;
  }
  v20 = (__m128i *)malloc_base(v15 & -(__int64)(v14 < v15));
  lpWideCharStr = v20;
  if ( v20 != nullptr )
  {
    v20->m128i_i32[0] = 56797;
LABEL_13:
    ++lpWideCharStr;
  }
LABEL_15:
  if ( lpWideCharStr == nullptr
    || (sub_180009D50(lpWideCharStr, 0, 2 * cchWideChar),
        (v21 = MultiByteToWideChar(v10, 1u, lpMultiByteStr, cbMultiByte, (LPWSTR)lpWideCharStr, cchWideChar)) == 0) )
  {
LABEL_18:
    StringTypeW = 0;
    goto LABEL_19;
  }
  StringTypeW = GetStringTypeW(dwInfoType, (LPCWCH)lpWideCharStr, v21, lpCharType);
LABEL_19:
  if ( lpWideCharStr != nullptr && lpWideCharStr[-1].m128i_i32[0] == 56797 )
    free_base(&lpWideCharStr[-1]);
LABEL_22:
  if ( v25 != 0 )
    *(_DWORD *)(v24[0] + 936LL) &= ~2u;
  return StringTypeW;
}


// ===== ?GetTableIndexFromLocaleName@@YAHPEB_W@Z @ 0x180016384 size=0xc7 =====
__int64 __fastcall GetTableIndexFromLocaleName(const wchar_t *a1)
{
  int v1; // r10d
  int v3; // r11d
  __int64 v4; // rbx
  __int64 v5; // r8
  char *v6; // r9
  signed __int64 v7; // rdi
  unsigned __int16 v8; // dx
  unsigned __int16 v9; // cx
  int v10; // ecx

  v1 = 0;
  v3 = 227;
  while ( 1 )
  {
    v4 = 85;
    v5 = (v3 + v1) / 2;
    v6 = (char *)*(&off_1800204E0 + 2 * v5);
    v7 = (char *)a1 - v6;
    do
    {
      v8 = *(_WORD *)&v6[v7];
      if ( (unsigned __int16)(v8 - 65) <= 0x19u )
        v8 += 32;
      v9 = *(_WORD *)v6;
      if ( (unsigned __int16)(*(_WORD *)v6 - 65) <= 0x19u )
        v9 += 32;
      v6 += 2;
      --v4;
    }
    while ( v4 != 0 && v8 != 0 && v8 == v9 );
    v10 = v8 - v9;
    if ( v10 == 0 )
      break;
    if ( v10 >= 0 )
      v1 = v5 + 1;
    else
      v3 = v5 - 1;
    if ( v1 > v3 )
      return 0xFFFFFFFFLL;
  }
  return *((unsigned int *)&off_1800204E0 + 4 * v5 + 2);
}


// ===== __crtDownlevelLocaleNameToLCID @ 0x18001644c size=0x32 =====
__int64 __fastcall _crtDownlevelLocaleNameToLCID(const wchar_t *a1)
{
  int TableIndexFromLocaleName; // eax

  if ( a1 != nullptr
    && (TableIndexFromLocaleName = GetTableIndexFromLocaleName(a1)) >= 0
    && (unsigned __int64)TableIndexFromLocaleName < 0xE4 )
  {
    return *((unsigned int *)&unk_18001EA80 + 4 * TableIndexFromLocaleName);
  }
  else
  {
    return 0;
  }
}


// ===== ?shortsort@@YAXPEAD0_KP6AHPEBX2@Z@Z @ 0x180016480 size=0xcc =====
void __fastcall shortsort(char *a1, char *a2, __int64 a3, int (__fastcall *a4)(char *, char *))
{
  char *v6; // rdi
  char *v7; // r12
  char *v9; // rbx
  char *i; // rsi
  __int64 v11; // r8
  char *v12; // rax
  signed __int64 v13; // rbx
  char v14; // dl

  if ( a2 > a1 )
  {
    v6 = a2;
    v7 = &a1[a3];
    do
    {
      v9 = a1;
      for ( i = v7; i <= v6; i += a3 )
      {
        if ( a4(i, v9) > 0 )
          v9 = i;
      }
      v11 = a3;
      v12 = v6;
      if ( v9 != v6 && a3 != 0 )
      {
        v13 = v9 - v6;
        do
        {
          v14 = v12[v13];
          v12[v13] = *v12;
          *v12++ = v14;
          --v11;
        }
        while ( v11 != 0 );
      }
      v6 -= a3;
    }
    while ( v6 > a1 );
  }
}


// ===== qsort @ 0x180016550 size=0x334 =====
void __cdecl qsort(
        void *Base,
        size_t NumOfElements,
        size_t SizeOfElements,
        _CoreCrtNonSecureSearchSortCompareFunction CompareFunction)
{
  char *v6; // r12
  char *v7; // r15
  __int64 v8; // r13
  size_t v9; // rsi
  char *v10; // rsi
  size_t v11; // r8
  _BYTE *v12; // rdx
  char *v13; // r9
  char v14; // cl
  size_t v15; // r8
  char *v16; // rdx
  signed __int64 v17; // r9
  char v18; // cl
  size_t v19; // r8
  char *v20; // rdx
  size_t v21; // r9
  char v22; // cl
  char *v23; // rbx
  char *v24; // rdi
  char *v25; // rdx
  __int64 v26; // r9
  char v27; // cl
  char *v28; // rdi
  _QWORD v29[124]; // [rsp+20h] [rbp-438h]

  v6 = (char *)Base;
  if ( (Base != nullptr || NumOfElements == 0) && SizeOfElements != 0 && CompareFunction != nullptr )
  {
    if ( NumOfElements >= 2 )
    {
      v7 = (char *)Base + SizeOfElements * (NumOfElements - 1);
      v8 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v9 = (v7 - v6) / SizeOfElements + 1;
          if ( v9 <= 8 )
          {
            shortsort(v6, v7, SizeOfElements, (int (__fastcall *)(char *, char *))CompareFunction);
            goto LABEL_10;
          }
          v10 = &v6[SizeOfElements * (v9 >> 1)];
          if ( ((int (__fastcall *)(char *, char *))CompareFunction)(v6, v10) > 0 )
          {
            v11 = SizeOfElements;
            v12 = v10;
            if ( v6 != v10 )
            {
              v13 = (char *)(v6 - v10);
              do
              {
                v14 = v12[(_QWORD)v13];
                v12[(_QWORD)v13] = *v12;
                *v12++ = v14;
                --v11;
              }
              while ( v11 != 0 );
            }
          }
          if ( ((int (__fastcall *)(char *, char *, size_t))CompareFunction)(v6, v7, v11) > 0 )
          {
            v15 = SizeOfElements;
            v16 = v7;
            if ( v6 != v7 )
            {
              v17 = v6 - v7;
              do
              {
                v18 = v16[v17];
                v16[v17] = *v16;
                *v16++ = v18;
                --v15;
              }
              while ( v15 != 0 );
            }
          }
          if ( ((int (__fastcall *)(char *, char *, size_t))CompareFunction)(v10, v7, v15) > 0 )
          {
            v19 = SizeOfElements;
            v20 = v7;
            if ( v10 != v7 )
            {
              v21 = v10 - v7;
              do
              {
                v22 = v20[v21];
                v20[v21] = *v20;
                *v20++ = v22;
                --v19;
              }
              while ( v19 != 0 );
            }
          }
          v23 = v6;
          v24 = v7;
          while ( 1 )
          {
            if ( v10 > v23 )
            {
              while ( 1 )
              {
                v23 += SizeOfElements;
                if ( v23 >= v10 )
                  break;
                if ( ((int (__fastcall *)(char *, char *, size_t))CompareFunction)(v23, v10, v19) > 0 )
                {
                  if ( v10 > v23 )
                    goto LABEL_31;
                  goto LABEL_29;
                }
              }
            }
            do
LABEL_29:
              v23 += SizeOfElements;
            while ( v23 <= v7 && ((int (__fastcall *)(char *, char *, size_t))CompareFunction)(v23, v10, v19) <= 0 );
            do
LABEL_31:
              v24 -= SizeOfElements;
            while ( v24 > v10 && ((int (__fastcall *)(char *, char *))CompareFunction)(v24, v10) > 0 );
            if ( v24 < v23 )
              break;
            v19 = SizeOfElements;
            v25 = v24;
            if ( v23 != v24 )
            {
              v26 = v23 - v24;
              do
              {
                v27 = v25[v26];
                v25[v26] = *v25;
                *v25++ = v27;
                --v19;
              }
              while ( v19 != 0 );
            }
            if ( v10 == v24 )
              v10 = v23;
          }
          v28 = &v24[SizeOfElements];
          if ( v10 < v28 )
          {
            while ( 1 )
            {
              v28 -= SizeOfElements;
              if ( v28 <= v10 )
                break;
              if ( ((unsigned int (__fastcall *)(char *, char *))CompareFunction)(v28, v10) != 0 )
              {
                if ( v10 < v28 )
                  goto LABEL_45;
                goto LABEL_43;
              }
            }
          }
          do
LABEL_43:
            v28 -= SizeOfElements;
          while ( v28 > v6 && ((unsigned int (__fastcall *)(char *, char *))CompareFunction)(v28, v10) == 0 );
LABEL_45:
          if ( v28 - v6 >= v7 - v23 )
            break;
          if ( v23 < v7 )
          {
            v29[v8] = v23;
            v29[v8++ + 62] = v7;
          }
          if ( v6 >= v28 )
          {
LABEL_10:
            if ( --v8 < 0 )
              return;
            v6 = (char *)v29[v8];
            v7 = (char *)v29[v8 + 62];
          }
          else
          {
            v7 = v28;
          }
        }
        if ( v6 < v28 )
        {
          v29[v8] = v6;
          v29[v8++ + 62] = v28;
        }
        if ( v23 >= v7 )
          goto LABEL_10;
        v6 = v23;
      }
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
  }
}


// ===== strncpy_s @ 0x180016884 size=0xd2 =====
errno_t __cdecl strncpy_s(char *Destination, rsize_t SizeInBytes, const char *Source, rsize_t MaxCount)
{
  errno_t v4; // r10d
  int *v6; // rax
  errno_t v7; // ebx
  signed __int64 v9; // r8
  char *v10; // rdx
  rsize_t v11; // rbx
  rsize_t v12; // rdi
  char v13; // al
  char v14; // al

  v4 = 0;
  if ( MaxCount != 0 )
  {
    if ( Destination == nullptr )
      goto LABEL_4;
  }
  else if ( Destination == nullptr )
  {
    if ( SizeInBytes != 0 )
    {
LABEL_4:
      v6 = errno();
      v7 = 22;
LABEL_5:
      *v6 = v7;
      invalid_parameter_noinfo();
      return v7;
    }
    return v4;
  }
  if ( SizeInBytes == 0 )
    goto LABEL_4;
  if ( MaxCount == 0 )
  {
    *Destination = 0;
    return v4;
  }
  if ( Source == nullptr )
  {
    *Destination = 0;
    goto LABEL_4;
  }
  v9 = Source - Destination;
  v10 = Destination;
  v11 = SizeInBytes;
  v12 = MaxCount;
  if ( MaxCount == -1 )
  {
    do
    {
      v13 = v10[v9];
      *v10++ = v13;
      if ( v13 == 0 )
        break;
      --v11;
    }
    while ( v11 != 0 );
  }
  else
  {
    do
    {
      v14 = v10[v9];
      *v10++ = v14;
      if ( v14 == 0 )
        break;
      if ( --v11 == 0 )
        break;
      --v12;
    }
    while ( v12 != 0 );
    if ( v12 == 0 )
      *v10 = 0;
  }
  if ( v11 == 0 )
  {
    if ( MaxCount == -1 )
    {
      Destination[SizeInBytes - 1] = 0;
      return 80;
    }
    *Destination = 0;
    v6 = errno();
    v7 = 34;
    goto LABEL_5;
  }
  return v4;
}


// ===== unknown_libname_59 @ 0x180016958 size=0x9e =====
// Microsoft VisualC 64bit universal runtime
_BYTE *__fastcall unknown_libname_59(_BYTE *a1, unsigned __int8 *a2)
{
  __int64 v2; // rax
  unsigned __int8 *v3; // r9
  bool v4; // cf
  unsigned __int8 i; // al
  _BYTE v8[32]; // [rsp+20h] [rbp-38h]

  v2 = 0;
  v3 = a2;
  v4 = true;
  do
  {
    if ( !v4 )
      _report_rangecheckfailure();
    v8[v2++] = 0;
    v4 = (unsigned __int64)v2 < 0x20;
  }
  while ( v2 < 32 );
  for ( i = *a2; i != 0; i = *v3 )
  {
    ++v3;
    v8[(unsigned __int64)i >> 3] |= 1 << (i & 7);
  }
  while ( 1 )
  {
    if ( *a1 == 0 )
      return nullptr;
    if ( ((unsigned __int8)(1 << (*a1 & 7)) & v8[(unsigned __int64)(unsigned __int8)*a1 >> 3]) != 0 )
      break;
    ++a1;
  }
  return a1;
}


// ===== _mbsdec @ 0x1800169f8 size=0x8 =====
unsigned __int8 *__cdecl mbsdec(const unsigned __int8 *Start, const unsigned __int8 *Pos)
{
  return mbsdec_l(Start, Pos, nullptr);
}


// ===== _mbsdec_l @ 0x180016a00 size=0x96 =====
unsigned __int8 *__cdecl mbsdec_l(const unsigned __int8 *Start, const unsigned __int8 *Pos, _locale_t Locale)
{
  unsigned __int8 *v6; // rbx
  const unsigned __int8 *v7; // rdx
  __int64 v8; // [rsp+20h] [rbp-28h] BYREF
  __int64 v9; // [rsp+30h] [rbp-18h]
  char v10; // [rsp+38h] [rbp-10h]

  if ( Start == nullptr || Pos == nullptr )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return nullptr;
  }
  if ( Start >= Pos )
    return nullptr;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v8, Locale);
  if ( *(_DWORD *)(v9 + 8) != 0 )
  {
    v7 = Pos - 1;
    do
      --v7;
    while ( Start <= v7 && (*(_BYTE *)(*v7 + v9 + 25) & 4) != 0 );
    v6 = (unsigned __int8 *)&Pos[-(((_BYTE)Pos - (_BYTE)v7) & 1) - 1];
  }
  else
  {
    v6 = (unsigned __int8 *)(Pos - 1);
  }
  if ( v10 != 0 )
    *(_DWORD *)(v8 + 936) &= ~2u;
  return v6;
}


// ===== ?initialize_multibyte@@YAHXZ @ 0x180016a98 size=0x17 =====
_BOOL8 __fastcall initialize_multibyte()
{
  return _acrt_initialize_multibyte() == 0;
}


// ===== ??$?RV_lambda_b521505b218e5242e90febf6bfebc422_@@AEAV_lambda_6978c1fb23f02e42e1d9e99668cc68aa_@@V_lambda_314360699dd331753a4119843814e9a7_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b521505b218e5242e90febf6bfebc422_@@AEAV_lambda_6978c1fb23f02e42e1d9e99668cc68aa_@@$$QEAV_lambda_314360699dd331753a4119843814e9a7_@@@Z @ 0x180016ab0 size=0x8c =====
__int64 __fastcall __crt_seh_guarded_call<int>::operator()<_lambda_b521505b218e5242e90febf6bfebc422_,_lambda_6978c1fb23f02e42e1d9e99668cc68aa_ &,_lambda_314360699dd331753a4119843814e9a7_>(
        __int64 a1,
        int *a2,
        int **a3,
        int *a4)
{
  void *osfhandle; // rax
  unsigned int v7; // ebx
  unsigned int *v8; // rbx

  sub_18001383C(*a2);
  if ( (*(_BYTE *)(qword_18002ABF0[(__int64)**a3 >> 6] + ((unsigned __int64)(**a3 & 0x3F) << 6) + 56) & 1) == 0 )
    goto LABEL_4;
  osfhandle = (void *)get_osfhandle(**a3);
  v7 = 0;
  if ( !FlushFileBuffers(osfhandle) )
  {
    v8 = _doserrno();
    *v8 = GetLastError();
LABEL_4:
    *errno() = 9;
    v7 = -1;
  }
  sub_180013860(*a4);
  return v7;
}


// ===== _commit @ 0x180016b3c size=0x91 =====
int __cdecl commit(int FileHandle)
{
  int *v2; // [rsp+20h] [rbp-18h] BYREF
  int v3; // [rsp+40h] [rbp+8h] BYREF
  char v4; // [rsp+48h] [rbp+10h] BYREF
  int v5; // [rsp+50h] [rbp+18h] BYREF
  int v6; // [rsp+58h] [rbp+20h] BYREF

  v3 = FileHandle;
  if ( FileHandle == -2 )
  {
    *errno() = 9;
  }
  else
  {
    if ( FileHandle >= 0
      && FileHandle < (unsigned int)dword_18002AFF0
      && (*(_BYTE *)(qword_18002ABF0[(__int64)FileHandle >> 6] + ((unsigned __int64)(FileHandle & 0x3F) << 6) + 56) & 1) != 0 )
    {
      v5 = FileHandle;
      v6 = FileHandle;
      v2 = &v3;
      return __crt_seh_guarded_call<int>::operator()<_lambda_b521505b218e5242e90febf6bfebc422_,_lambda_6978c1fb23f02e42e1d9e99668cc68aa_ &,_lambda_314360699dd331753a4119843814e9a7_>(
               (__int64)&v4,
               &v6,
               &v2,
               &v5);
    }
    *errno() = 9;
    invalid_parameter_noinfo();
  }
  return -1;
}


// ===== ?write_double_translated_ansi_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x180016bd0 size=0x208 =====
__int64 __fastcall write_double_translated_ansi_nolock(__int64 a1, int a2, const char *a3, int a4)
{
  __int64 v4; // r15
  unsigned __int64 v5; // rsi
  unsigned __int64 v8; // r12
  const char *v9; // rdi
  bool i; // cf
  char v11; // r13
  __int64 v12; // rdx
  char v13; // cl
  char v14; // al
  size_t v15; // r8
  const char *v16; // rdx
  DWORD v17; // eax
  DWORD v18; // r14d
  WCHAR WideCharStr[2]; // [rsp+40h] [rbp-40h] BYREF
  __int16 Buffer; // [rsp+44h] [rbp-3Ch] BYREF
  DWORD NumberOfBytesWritten; // [rsp+48h] [rbp-38h] BYREF
  UINT CodePage; // [rsp+4Ch] [rbp-34h]
  HANDLE hFile; // [rsp+50h] [rbp-30h]
  const char *v25; // [rsp+58h] [rbp-28h]
  _BYTE v26[8]; // [rsp+60h] [rbp-20h] BYREF
  CHAR MultiByteStr[8]; // [rsp+68h] [rbp-18h] BYREF

  v4 = (__int64)a2 >> 6;
  v5 = (unsigned __int64)(a2 & 0x3F) << 6;
  v25 = a3;
  v8 = (unsigned __int64)&a3[a4];
  hFile = *(HANDLE *)(qword_18002ABF0[v4] + v5 + 40);
  CodePage = GetConsoleCP();
  *(_QWORD *)a1 = 0;
  v9 = a3;
  *(_DWORD *)(a1 + 8) = 0;
  for ( i = (unsigned __int64)a3 < v8; i; i = (unsigned __int64)v9 < v8 )
  {
    v11 = *v9;
    WideCharStr[0] = 0;
    v12 = qword_18002ABF0[v4];
    v13 = *(_BYTE *)(v12 + v5 + 61);
    if ( (v13 & 4) != 0 )
    {
      v14 = *(_BYTE *)(v12 + v5 + 62);
      *(_BYTE *)(v12 + v5 + 61) = v13 & 0xFB;
      v15 = 2;
      v16 = v26;
      v26[0] = v14;
      v26[1] = v11;
      goto LABEL_10;
    }
    if ( (_pctype_func()[*(unsigned __int8 *)v9] & 0x8000u) == 0 )
    {
      v15 = 1;
      v16 = v9;
LABEL_10:
      if ( mbtowc(WideCharStr, v16, v15) == -1 )
        return a1;
      goto LABEL_11;
    }
    if ( (unsigned __int64)v9 >= v8 )
    {
      *(_BYTE *)(qword_18002ABF0[v4] + v5 + 62) = *v9;
      *(_BYTE *)(qword_18002ABF0[v4] + v5 + 61) |= 4u;
      ++*(_DWORD *)(a1 + 4);
      return a1;
    }
    if ( mbtowc(WideCharStr, v9, 2u) == -1 )
      return a1;
    ++v9;
LABEL_11:
    ++v9;
    v17 = WideCharToMultiByte(CodePage, 0, WideCharStr, 1, MultiByteStr, 5, nullptr, nullptr);
    v18 = v17;
    if ( v17 == 0 )
      return a1;
    if ( !WriteFile(hFile, MultiByteStr, v17, &NumberOfBytesWritten, nullptr) )
    {
LABEL_20:
      *(_DWORD *)a1 = GetLastError();
      return a1;
    }
    *(_DWORD *)(a1 + 4) = (_DWORD)v9 + *(_DWORD *)(a1 + 8) - (_DWORD)v25;
    if ( NumberOfBytesWritten < v18 )
      return a1;
    if ( v11 == 10 )
    {
      Buffer = 13;
      if ( !WriteFile(hFile, &Buffer, 1u, &NumberOfBytesWritten, nullptr) )
        goto LABEL_20;
      if ( NumberOfBytesWritten == 0 )
        return a1;
      ++*(_DWORD *)(a1 + 8);
      ++*(_DWORD *)(a1 + 4);
    }
  }
  return a1;
}


// ===== ?write_text_ansi_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x180016dd8 size=0x105 =====
DWORD *__fastcall write_text_ansi_nolock(DWORD *a1, int a2, char *a3, int a4)
{
  unsigned __int64 v5; // rbp
  char *v6; // rsi
  __int64 v7; // rax
  void *v8; // r14
  char *v9; // rdi
  char v10; // al
  DWORD v11; // edi
  DWORD v12; // eax
  DWORD NumberOfBytesWritten; // [rsp+30h] [rbp-1438h] BYREF
  _BYTE Buffer[5119]; // [rsp+40h] [rbp-1428h] BYREF
  char v16; // [rsp+143Fh] [rbp-29h] BYREF

  v5 = (unsigned __int64)&a3[a4];
  *a1 = 0;
  v6 = a3;
  a1[1] = 0;
  v7 = qword_18002ABF0[(__int64)a2 >> 6];
  a1[2] = 0;
  v8 = *(void **)(v7 + ((unsigned __int64)(a2 & 0x3F) << 6) + 40);
  if ( (unsigned __int64)a3 < v5 )
  {
    while ( 1 )
    {
      v9 = Buffer;
      do
      {
        if ( (unsigned __int64)v6 >= v5 )
          break;
        v10 = *v6++;
        if ( v10 == 10 )
        {
          ++a1[2];
          *v9++ = 13;
        }
        *v9++ = v10;
      }
      while ( v9 < &v16 );
      v11 = (_DWORD)v9 - (unsigned int)Buffer;
      if ( !WriteFile(v8, Buffer, v11, &NumberOfBytesWritten, nullptr) )
        break;
      v12 = NumberOfBytesWritten;
      a1[1] += NumberOfBytesWritten;
      if ( v12 < v11 || (unsigned __int64)v6 >= v5 )
        return a1;
    }
    *a1 = GetLastError();
  }
  return a1;
}


// ===== ?write_text_utf16le_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x180016ee0 size=0x11c =====
DWORD *__fastcall write_text_utf16le_nolock(DWORD *a1, int a2, __int16 *a3, unsigned int a4)
{
  unsigned __int64 v5; // rbp
  __int16 *v6; // rsi
  __int64 v7; // rax
  void *v8; // r14
  char *v9; // rbx
  __int16 v10; // ax
  DWORD v11; // ebx
  DWORD v12; // eax
  DWORD NumberOfBytesWritten; // [rsp+30h] [rbp-1438h] BYREF
  _BYTE Buffer[5118]; // [rsp+40h] [rbp-1428h] BYREF
  __int16 v16; // [rsp+143Eh] [rbp-2Ah] BYREF

  v5 = (unsigned __int64)a3 + a4;
  *a1 = 0;
  v6 = a3;
  a1[1] = 0;
  v7 = qword_18002ABF0[(__int64)a2 >> 6];
  a1[2] = 0;
  v8 = *(void **)(v7 + ((unsigned __int64)(a2 & 0x3F) << 6) + 40);
  if ( (unsigned __int64)a3 < v5 )
  {
    while ( 1 )
    {
      v9 = Buffer;
      do
      {
        if ( (unsigned __int64)v6 >= v5 )
          break;
        v10 = *v6++;
        if ( v10 == 10 )
        {
          a1[2] += 2;
          *(_WORD *)v9 = 13;
          v9 += 2;
        }
        *(_WORD *)v9 = v10;
        v9 += 2;
      }
      while ( v9 < (char *)&v16 );
      v11 = 2 * ((v9 - Buffer) >> 1);
      if ( !WriteFile(v8, Buffer, v11, &NumberOfBytesWritten, nullptr) )
        break;
      v12 = NumberOfBytesWritten;
      a1[1] += NumberOfBytesWritten;
      if ( v12 < v11 || (unsigned __int64)v6 >= v5 )
        return a1;
    }
    *a1 = GetLastError();
  }
  return a1;
}


// ===== ?write_text_utf8_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x180016ffc size=0x172 =====
__int64 __fastcall write_text_utf8_nolock(__int64 a1, int a2, WCHAR *a3, unsigned int a4)
{
  unsigned __int64 v5; // r14
  int v6; // r15d
  WCHAR *v7; // rdi
  void *v8; // r12
  bool v9; // cf
  WCHAR *v10; // rax
  WCHAR v11; // cx
  unsigned int v12; // ebp
  unsigned int v13; // esi
  DWORD NumberOfBytesWritten; // [rsp+40h] [rbp-1458h] BYREF
  WCHAR WideCharStr[852]; // [rsp+50h] [rbp-1448h] BYREF
  char v17; // [rsp+6F8h] [rbp-DA0h] BYREF
  CHAR MultiByteStr[3424]; // [rsp+700h] [rbp-D98h] BYREF

  v5 = (unsigned __int64)a3 + a4;
  v6 = (int)a3;
  v7 = a3;
  v8 = *(void **)(qword_18002ABF0[(__int64)a2 >> 6] + ((unsigned __int64)(a2 & 0x3F) << 6) + 40);
  *(_DWORD *)a1 = 0;
  *(_QWORD *)(a1 + 4) = 0;
  v9 = (unsigned __int64)a3 < v5;
LABEL_2:
  if ( v9 )
  {
    v10 = WideCharStr;
    do
    {
      if ( (unsigned __int64)v7 >= v5 )
        break;
      v11 = *v7++;
      if ( v11 == 10 )
        *v10++ = 13;
      *v10++ = v11;
    }
    while ( v10 < (WCHAR *)&v17 );
    v12 = WideCharToMultiByte(0xFDE9u, 0, WideCharStr, v10 - WideCharStr, MultiByteStr, 3413, nullptr, nullptr);
    if ( v12 != 0 )
    {
      v13 = 0;
      while ( WriteFile(v8, &MultiByteStr[v13], v12 - v13, &NumberOfBytesWritten, nullptr) )
      {
        v13 += NumberOfBytesWritten;
        if ( v13 >= v12 )
        {
          *(_DWORD *)(a1 + 4) = (_DWORD)v7 - v6;
          v9 = (unsigned __int64)v7 < v5;
          goto LABEL_2;
        }
      }
    }
    *(_DWORD *)a1 = GetLastError();
  }
  return a1;
}


// ===== _write @ 0x180017170 size=0xec =====
int __cdecl write(int FileHandle, const void *Buf, unsigned int MaxCharCount)
{
  __int64 v6; // r14
  unsigned __int64 v7; // rsi
  int v8; // edi

  if ( FileHandle == -2 )
  {
    *_doserrno() = 0;
    *errno() = 9;
    return -1;
  }
  if ( FileHandle < 0
    || FileHandle >= (unsigned int)dword_18002AFF0
    || (v6 = (__int64)FileHandle >> 6,
        v7 = (unsigned __int64)(FileHandle & 0x3F) << 6,
        (*(_BYTE *)(qword_18002ABF0[v6] + v7 + 56) & 1) == 0) )
  {
    *_doserrno() = 0;
    *errno() = 9;
    invalid_parameter_noinfo();
    return -1;
  }
  sub_18001383C(FileHandle);
  v8 = -1;
  if ( (*(_BYTE *)(qword_18002ABF0[v6] + v7 + 56) & 1) != 0 )
  {
    v8 = write_nolock((unsigned int)FileHandle, Buf, MaxCharCount);
  }
  else
  {
    *errno() = 9;
    *_doserrno() = 0;
  }
  sub_180013860(FileHandle);
  return v8;
}


// ===== _write_nolock @ 0x18001725c size=0x2e1 =====
__int64 __fastcall write_nolock(int a1, char *a2, unsigned int a3)
{
  DWORD v3; // edi
  __int64 v4; // r15
  __int64 v8; // r13
  unsigned __int64 v9; // r14
  __int64 v10; // rcx
  char v11; // bl
  char *v12; // r12
  DWORD v13; // ebx
  wchar_t *v14; // r15
  wchar_t v15; // r13
  __int64 v16; // rax
  __int64 v17; // xmm0_8
  __int64 v18; // rcx
  void *v19; // rcx
  DWORD NumberOfBytesWritten[4]; // [rsp+30h] [rbp-30h] BYREF
  __int64 v21; // [rsp+40h] [rbp-20h]
  __int64 v22; // [rsp+50h] [rbp-10h]
  DWORD Mode; // [rsp+58h] [rbp-8h] BYREF

  v3 = 0;
  v4 = a3;
  if ( a3 == 0 )
    return 0;
  if ( a2 == nullptr
    || (v8 = (__int64)a1 >> 6,
        v9 = (unsigned __int64)(a1 & 0x3F) << 6,
        v22 = v8,
        v10 = qword_18002ABF0[v8],
        (unsigned __int8)((v11 = *(_BYTE *)(v10 + v9 + 57)) - 1) <= 1u)
    && (a3 & 1) != 0 )
  {
    *_doserrno() = 0;
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFLL;
  }
  if ( (*(_BYTE *)(v10 + v9 + 56) & 0x20) != 0 )
    common_lseek_nolock<__int64>(a1, 0, 2u);
  v21 = 0;
  if ( isatty(a1) != 0
    && *(char *)(qword_18002ABF0[v8] + v9 + 56) < 0
    && (*(_QWORD *)(*((_QWORD *)_acrt_getptd() + 18) + 312LL) != 0 || *(_BYTE *)(qword_18002ABF0[v8] + v9 + 57) != 0)
    && GetConsoleMode(*(HANDLE *)(qword_18002ABF0[v8] + v9 + 40), &Mode) )
  {
    if ( v11 != 0 )
    {
      if ( (unsigned __int8)(v11 - 1) > 1u )
        goto LABEL_40;
      NumberOfBytesWritten[0] = 0;
      v12 = &a2[v4];
      v13 = 0;
      v14 = (wchar_t *)a2;
      NumberOfBytesWritten[1] = 0;
      if ( a2 < v12 )
      {
        while ( 1 )
        {
          v15 = *v14;
          if ( putwch_nolock(*v14) != v15 )
            break;
          v13 += 2;
          NumberOfBytesWritten[1] = v13;
          if ( v15 == 10 )
          {
            if ( putwch_nolock(0xDu) != 13 )
              break;
            NumberOfBytesWritten[1] = ++v13;
            ++v3;
          }
          if ( ++v14 >= (wchar_t *)v12 )
            goto LABEL_25;
        }
        NumberOfBytesWritten[0] = GetLastError();
LABEL_25:
        v8 = v22;
      }
      goto LABEL_38;
    }
    v16 = write_double_translated_ansi_nolock((__int64)NumberOfBytesWritten, a1, a2, v4);
  }
  else
  {
    v18 = qword_18002ABF0[v8];
    if ( *(char *)(v18 + v9 + 56) >= 0 )
    {
      v19 = *(void **)(v18 + v9 + 40);
      memset(NumberOfBytesWritten, 0, 12);
      if ( !WriteFile(v19, a2, v4, &NumberOfBytesWritten[1], nullptr) )
        NumberOfBytesWritten[0] = GetLastError();
      v3 = NumberOfBytesWritten[2];
LABEL_38:
      v17 = *(_QWORD *)NumberOfBytesWritten;
      goto LABEL_39;
    }
    if ( v11 != 0 )
    {
      if ( v11 == 1 )
      {
        v16 = write_text_utf8_nolock((__int64)NumberOfBytesWritten, a1, (WCHAR *)a2, v4);
      }
      else
      {
        if ( v11 != 2 )
          goto LABEL_40;
        v16 = (__int64)write_text_utf16le_nolock(NumberOfBytesWritten, a1, (__int16 *)a2, v4);
      }
    }
    else
    {
      v16 = (__int64)write_text_ansi_nolock(NumberOfBytesWritten, a1, a2, v4);
    }
  }
  v17 = *(_QWORD *)v16;
  v3 = *(_DWORD *)(v16 + 8);
LABEL_39:
  v21 = v17;
LABEL_40:
  if ( HIDWORD(v21) == 0 )
  {
    if ( (_DWORD)v21 != 0 )
    {
      if ( (_DWORD)v21 == 5 )
      {
        *errno() = 9;
        *_doserrno() = 5;
      }
      else
      {
        _acrt_errno_map_os_error(v21);
      }
    }
    else
    {
      if ( (*(_BYTE *)(qword_18002ABF0[v8] + v9 + 56) & 0x40) != 0 && *a2 == 26 )
        return 0;
      *errno() = 28;
      *_doserrno() = 0;
    }
    return 0xFFFFFFFFLL;
  }
  return HIDWORD(v21) - v3;
}


// ===== sub_180017540 @ 0x180017540 size=0x7 =====
__int64 sub_180017540()
{
  return (unsigned int)dword_18002B444;
}


// ===== __strncnt @ 0x180017548 size=0x15 =====
size_t __cdecl _strncnt(const char *String, size_t Count)
{
  size_t result; // rax

  result = 0;
  if ( *String != 0 )
  {
    do
    {
      if ( result == Count )
        break;
      ++result;
    }
    while ( String[result] != 0 );
  }
  return result;
}


// ===== fegetenv @ 0x180017560 size=0x20 =====
int __cdecl fegetenv(fenv_t *Env)
{
  Env->_Fe_ctl = getfpcontrolword();
  Env->_Fe_stat = getfpstatusword();
  return 0;
}


// ===== fesetenv @ 0x180017580 size=0x4c =====
int __cdecl fesetenv(const fenv_t *Env)
{
  __int64 Fe_ctl; // rcx
  fenv_t Enva; // [rsp+30h] [rbp+8h] BYREF

  Enva._Fe_ctl = 0;
  Fe_ctl = Env->_Fe_ctl;
  Enva._Fe_stat = 0;
  setfpcontrolword(Fe_ctl);
  setfpstatusword(Env->_Fe_stat);
  fegetenv(&Enva);
  return Env->_Fe_ctl != Enva._Fe_ctl || Env->_Fe_stat != Enva._Fe_stat;
}


// ===== feholdexcept @ 0x1800175cc size=0x50 =====
int __cdecl feholdexcept(fenv_t *Env)
{
  fenv_t v3; // rax
  fenv_t Enva; // [rsp+38h] [rbp+10h] BYREF

  Enva._Fe_ctl = 0;
  Enva._Fe_stat = 0;
  if ( fegetenv(&Enva) != 0 )
    return 1;
  v3 = Enva;
  Enva._Fe_ctl |= 0x1Fu;
  *Env = v3;
  if ( fesetenv(&Enva) != 0 )
    return 1;
  clearfp();
  return 0;
}


// ===== ceil @ 0x18001761c size=0xc2 =====
double __cdecl ceil(double X)
{
  double v1; // rdx
  double v2; // rax
  _BOOL8 v3; // r8
  double v4; // rax

  v1 = X;
  v2 = fabs(X);
  v3 = *(_QWORD *)&X != (*(_QWORD *)&X & 0x7FFFFFFFFFFFFFFFLL);
  if ( fabs(X) < 9.007199254740992e15 )
  {
    if ( *(_QWORD *)&v2 >= 0x3FF0000000000000uLL )
    {
      *(_QWORD *)&v4 = *(_QWORD *)&X & ~((1LL << (51 - (unsigned __int8)(*(_QWORD *)&X >> 52))) - 1);
      X = v4;
      if ( !v3 && *(_QWORD *)&v4 != *(_QWORD *)&v1 )
        return v4 + 1.0;
    }
    else if ( v2 != 0.0 )
    {
      if ( *(_QWORD *)&X == (*(_QWORD *)&X & 0x7FFFFFFFFFFFFFFFLL) )
        return 1.0;
      else
        return -0.0;
    }
  }
  else if ( *(_QWORD *)&v2 > 0x7FF0000000000000uLL )
  {
    *(_QWORD *)&X |= 0x8000000000000uLL;
  }
  return X;
}


// ===== log10 @ 0x1800176e0 size=0x5ab =====
// local variable allocation has failed, the output may be wrong!
double __cdecl log10(double X)
{
  __int64 v1; // rdx
  __int64 v2; // rcx
  double v3; // rax
  __m128i v4; // xmm3
  double v5; // xmm6_8
  __m128i v6; // xmm5
  __m128i v7; // xmm2
  unsigned __int64 v8; // rax
  __m128i v9; // xmm1
  unsigned __int64 v10; // rax
  double v11; // xmm2_8
  __m128i v12; // xmm0
  double v13; // xmm1_8
  double v14; // xmm6_8
  double v15; // xmm1_8
  double v16; // xmm4_8
  double v17; // xmm3_8
  __m128i v18; // xmm2

  if ( dword_18002B44C == 0 )
  {
    v3 = X;
    v4 = _mm_sub_epi64(_mm_srli_epi64(*(__m128i *)&X, 0x34u), (__m128i)xmmword_180021DC0);
    if ( COERCE_DOUBLE(*(_QWORD *)&X & 0x7FF0000000000000LL) == INFINITY )
    {
      if ( X == INFINITY )
        return X;
      if ( X != -INFINITY )
      {
        *(_QWORD *)&X |= 0x8000000000000uLL;
        return X;
      }
    }
    else
    {
      v5 = _mm_cvtepi32_pd(v4).m128d_f64[0];
      v6 = 0;
      if ( X > 0.0 )
      {
        v7 = _mm_and_si128(*(__m128i *)&X, (__m128i)xmmword_180021DE0);
        if ( v5 == -1023.0 )
        {
          v18 = _mm_or_si128(v7, (__m128i)xmmword_180021E70);
          *(double *)v18.m128i_i64 = *(double *)v18.m128i_i64 - 1.0;
          v6.m128i_i64[0] = v18.m128i_i64[0];
          v7 = _mm_and_si128(v18, (__m128i)xmmword_180021DE0);
          v3 = *(double *)v7.m128i_i64;
          v5 = _mm_cvtepi32_pd(_mm_sub_epi32(_mm_srli_epi64(v6, 0x34u), (__m128i)xmmword_180021F10)).m128d_f64[0];
        }
        v8 = 2 * (*(_QWORD *)&v3 & 0x80000000000LL) + (*(_QWORD *)&v3 & 0xFF00000000000LL);
        v9 = (__m128i)v8;
        if ( fabs(X - 1.0) < 0.0625 )
        {
          *(double *)v12.m128i_i64 = X - 1.0;
          v13 = *(double *)v12.m128i_i64 / (*(double *)v12.m128i_i64 + 2.0);
          v14 = *(double *)v12.m128i_i64 * v13;
          v15 = v13 + v13;
          v16 = (0.01250000000377175 * (v15 * v15) + 0.08333333333333179) * (v15 * v15 * v15)
              + (0.0004348877777076146 * (v15 * v15) + 0.002232139987919448)
              * (v15
               * v15
               * v15
               * (v15
                * v15
                * v15)
               * v15)
              - v14;
          v17 = *(double *)_mm_and_si128(v12, (__m128i)xmmword_180021FB0).m128i_i64;
          return v17 * 0.0000007349550096401511
               + (v16 + *(double *)v12.m128i_i64 - v17) * 0.0000007349550096401511
               + (v16 + *(double *)v12.m128i_i64 - v17) * 0.4342937469482422
               + v17 * 0.4342937469482422;
        }
        else
        {
          v10 = v8 >> 44;
          v11 = (*(double *)_mm_or_si128(v9, (__m128i)xmmword_180021E80).m128i_i64
               - *(double *)_mm_or_si128(v7, (__m128i)xmmword_180021E80).m128i_i64)
              * dbl_180022FF0[v10];
          return dbl_180021FD0[v10]
               + 0.3010299950838089 * v5
               + dbl_1800227E0[v10]
               + 5.801722962879576e-10 * v5
               - ((0.3333333333333333 * v11 + 0.5) * (v11 * v11)
                + v11
                + ((0.1666666666666667 * v11 + 0.2) * v11 + 0.25) * (v11 * v11 * (v11 * v11)))
               * 0.4342944819032518;
        }
      }
      if ( X == 0.0 )
        return log10_special(v2, v1, 1);
    }
    return log10_special(v2, v1, 2);
  }
  __asm
  {
    vpsrlq  xmm3, xmm0, 34h ; '4'
    vmovq   rax, xmm0
    vpsubq  xmm3, xmm3, cs:xmmword_180021DC0
    vcvtdq2pd xmm6, xmm3
    vpand   xmm5, xmm0, cs:xmmword_180021D90
    vcomisd xmm5, qword ptr cs:xmmword_180021D90
  }
  if ( _RAX != 0x7FF0000000000000LL )
  {
    if ( _RAX == 0xFFF0000000000000uLL )
    {
      __asm { vmovsd  xmm1, cs:qword_180021DA0 }
      log10_special(v2, v1, 2);
      __asm { vmovdqa xmm6, [rsp+58h+var_38] }
      return X;
    }
    log10_special(v2, v1, 3);
  }
  __asm { vmovdqa xmm6, [rsp+58h+var_38] }
  return X;
}


// ===== _putwch_nolock @ 0x180017c8c size=0x59 =====
wint_t __cdecl putwch_nolock(wchar_t Character)
{
  HANDLE v1; // rcx
  wint_t Buffer; // [rsp+40h] [rbp+8h] BYREF
  DWORD NumberOfCharsWritten; // [rsp+48h] [rbp+10h] BYREF

  Buffer = Character;
  v1 = hObject;
  if ( hObject == (HANDLE)-2LL )
  {
    sub_180018448();
    v1 = hObject;
  }
  if ( v1 == (HANDLE)-1LL || !WriteConsoleW(v1, &Buffer, 1u, &NumberOfCharsWritten, nullptr) )
    return -1;
  else
    return Buffer;
}


// ===== _getfpcontrolword @ 0x180017ce8 size=0x17 =====
__int64 getfpcontrolword()
{
  return controlfp(0, 0) & 0x31F;
}


// ===== _getfpstatusword @ 0x180017d00 size=0x11 =====
__int64 getfpstatusword()
{
  return statusfp() & 0x1F;
}


// ===== _setfpcontrolword @ 0x180017d14 size=0xa =====
unsigned int __fastcall setfpcontrolword(unsigned int a1)
{
  return controlfp(a1, 0x8031Fu);
}


// ===== _setfpstatusword @ 0x180017d20 size=0x50 =====
__int64 __fastcall setfpstatusword(char a1)
{
  __int64 v2; // rax
  int v3; // ecx

  v2 = get_fpsr() & 0xFFFFFFC2LL;
  v3 = 0;
  if ( (a1 & 0x1F) != 0 )
  {
    v3 = (a1 & 0x10) != 0;
    if ( (a1 & 8) != 0 )
      v3 |= 4u;
    if ( (a1 & 4) != 0 )
      v3 |= 8u;
    if ( (a1 & 2) != 0 )
      v3 |= 0x10u;
    if ( (a1 & 1) != 0 )
      v3 |= 0x20u;
  }
  return set_fpsr((unsigned int)v2 | v3);
}


// ===== _clearfp @ 0x180017d70 size=0x52 =====
unsigned int __cdecl clearfp()
{
  char fpsr; // bl
  unsigned int result; // eax

  fpsr = get_fpsr();
  fclrf();
  result = 0;
  if ( (fpsr & 0x3F) != 0 )
  {
    if ( (fpsr & 1) != 0 )
      result = 16;
    if ( (fpsr & 4) != 0 )
      result |= 8u;
    if ( (fpsr & 8) != 0 )
      result |= 4u;
    if ( (fpsr & 0x10) != 0 )
      result |= 2u;
    if ( (fpsr & 0x20) != 0 )
      result |= 1u;
    if ( (fpsr & 2) != 0 )
      result |= 0x80000u;
  }
  return result;
}


// ===== _controlfp @ 0x180017dc4 size=0x9 =====
unsigned int __cdecl controlfp(unsigned int NewValue, unsigned int Mask)
{
  unsigned int v2; // edx

  v2 = Mask & 0xFFF7FFFF;
  return common_control87(NewValue, v2);
}


// ===== _statusfp @ 0x180017dd0 size=0x48 =====
unsigned int __cdecl statusfp()
{
  char v0; // dl
  unsigned int v1; // ecx

  v0 = _mm_getcsr();
  v1 = 0;
  if ( (v0 & 0x3F) != 0 )
  {
    if ( (v0 & 1) != 0 )
      v1 = 16;
    if ( (v0 & 4) != 0 )
      v1 |= 8u;
    if ( (v0 & 8) != 0 )
      v1 |= 4u;
    if ( (v0 & 0x10) != 0 )
      v1 |= 2u;
    if ( (v0 & 0x20) != 0 )
      v1 |= 1u;
    if ( (v0 & 2) != 0 )
      v1 |= 0x80000u;
  }
  return v1;
}


// ===== common_control87 @ 0x180017e18 size=0x296 =====
int __fastcall common_control87(int a1, int a2)
{
  int v3; // ebx
  __int16 fpsr; // r9
  int v5; // edi
  int result; // eax
  int v7; // ecx
  int v8; // r9d
  int v9; // r9d
  int v10; // ecx
  unsigned int v11; // ebx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ebx
  int v16; // ebx

  v3 = a2 & 0x308031F;
  fpsr = get_fpsr();
  v5 = 0;
  result = 0;
  if ( (fpsr & 0x80) != 0 )
    result = 16;
  if ( (fpsr & 0x200) != 0 )
    result |= 8u;
  if ( (fpsr & 0x400) != 0 )
    result |= 4u;
  if ( (fpsr & 0x800) != 0 )
    result |= 2u;
  if ( (fpsr & 0x1000) != 0 )
    result |= 1u;
  if ( (fpsr & 0x100) != 0 )
    result |= 0x80000u;
  v7 = fpsr & 0x6000;
  if ( (fpsr & 0x6000) != 0 )
  {
    switch ( v7 )
    {
      case 8192:
        result |= 0x100u;
        break;
      case 16384:
        result |= 0x200u;
        break;
      case 24576:
        result |= 0x300u;
        break;
      default:
        break;
    }
  }
  v8 = (fpsr & 0x8040) - 64;
  if ( v8 != 0 )
  {
    v9 = v8 - 32704;
    if ( v9 != 0 )
    {
      if ( v9 == 64 )
        result |= 0x1000000u;
    }
    else
    {
      result |= 0x3000000u;
    }
  }
  else
  {
    result |= 0x2000000u;
  }
  v10 = v3 & a1 | result & ~v3;
  if ( v10 != result )
  {
    v11 = 0;
    if ( (v10 & 0x10) != 0 )
      v11 = 128;
    if ( (v10 & 8) != 0 )
      v11 |= 0x200u;
    if ( (v10 & 4) != 0 )
      v11 |= 0x400u;
    if ( (v10 & 2) != 0 )
      v11 |= 0x800u;
    if ( (v10 & 1) != 0 )
      v11 |= 0x1000u;
    if ( (v10 & 0x80000) != 0 )
      v11 |= 0x100u;
    v12 = v10 & 0x300;
    if ( (v10 & 0x300) != 0 )
    {
      switch ( v12 )
      {
        case 256:
          v11 |= 0x2000u;
          break;
        case 512:
          v11 |= 0x4000u;
          break;
        case 768:
          v11 |= 0x6000u;
          break;
        default:
          break;
      }
    }
    v13 = v10 & 0x3000000;
    switch ( v13 )
    {
      case 16777216:
        v11 |= 0x8040u;
        break;
      case 33554432:
        v11 |= 0x40u;
        break;
      case 50331648:
        v11 |= 0x8000u;
        break;
      default:
        break;
    }
    if ( byte_180029B30 != 0 && (v11 & 0x40) != 0 )
    {
      set_fpsr(v11);
    }
    else
    {
      v11 &= ~0x40u;
      set_fpsr(v11);
    }
    if ( (v11 & 0x80u) != 0 )
      v5 = 16;
    if ( (v11 & 0x200) != 0 )
      v5 |= 8u;
    if ( (v11 & 0x400) != 0 )
      v5 |= 4u;
    if ( (v11 & 0x800) != 0 )
      v5 |= 2u;
    if ( (v11 & 0x1000) != 0 )
      v5 |= 1u;
    if ( (v11 & 0x100) != 0 )
      v5 |= 0x80000u;
    v14 = v11 & 0x6000;
    if ( (v11 & 0x6000) != 0 )
    {
      switch ( v14 )
      {
        case 8192:
          v5 |= 0x100u;
          break;
        case 16384:
          v5 |= 0x200u;
          break;
        case 24576:
          v5 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v15 = (v11 & 0x8040) - 64;
    if ( v15 == 0 )
      return v5 | 0x2000000;
    v16 = v15 - 32704;
    if ( v16 == 0 )
      return v5 | 0x3000000;
    if ( v16 == 64 )
      return v5 | 0x1000000;
    return v5;
  }
  return result;
}


// ===== _call_matherr @ 0x1800180b0 size=0x65 =====
double __fastcall call_matherr(unsigned int a1, __int64 a2, __int64 a3, double a4, __int64 a5, double a6, __int64 a7)
{
  _QWORD v9[4]; // [rsp+20h] [rbp-38h] BYREF
  double v10; // [rsp+40h] [rbp-18h]

  LODWORD(v9[0]) = a1;
  v9[3] = a5;
  v10 = a6;
  *(double *)&v9[2] = a4;
  v9[1] = a3;
  ctrlfp(a7, 65472);
  if ( (unsigned int)_acrt_invoke_user_matherr((__int64)v9) == 0 )
    set_errno_from_matherr(a1);
  return v10;
}


// ===== _exception_enabled @ 0x180018118 size=0xb9 =====
_BOOL8 __fastcall exception_enabled(char a1, __int16 a2)
{
  int v3; // ebx

  v3 = a1 & 0x1F;
  if ( (a1 & 8) != 0 && (a2 & 0x80u) != 0 )
  {
    set_statfp(1);
    v3 &= ~8u;
  }
  else if ( (a1 & 4) != 0 && (a2 & 0x200) != 0 )
  {
    set_statfp(4);
    v3 &= ~4u;
  }
  else if ( (a1 & 1) != 0 && (a2 & 0x400) != 0 )
  {
    set_statfp(8);
    v3 &= ~1u;
  }
  else if ( (a1 & 2) != 0 && (a2 & 0x800) != 0 )
  {
    if ( (a1 & 0x10) != 0 )
      set_statfp(16);
    v3 &= ~2u;
  }
  if ( (a1 & 0x10) != 0 && (a2 & 0x1000) != 0 )
  {
    set_statfp(32);
    v3 &= ~0x10u;
  }
  return v3 == 0;
}


// ===== _handle_error @ 0x1800181d4 size=0x127 =====
double __fastcall handle_error(
        __int64 a1,
        int a2,
        __int64 a3,
        unsigned int a4,
        int a5,
        unsigned int a6,
        double a7,
        __int64 a8,
        int a9)
{
  BOOL v13; // eax
  __int64 v14; // xmm6_8
  __int64 v16; // [rsp+48h] [rbp-A1h] BYREF
  double v17[2]; // [rsp+50h] [rbp-99h] BYREF
  _QWORD v18[8]; // [rsp+68h] [rbp-81h] BYREF
  unsigned int v19; // [rsp+A8h] [rbp-41h]

  v16 = ctrlfp(8064, 65472);
  *(_QWORD *)&v17[1] = a3;
  *(_QWORD *)&v17[0] = a3;
  v13 = exception_enabled(a5, v16);
  v14 = a8;
  if ( !v13 )
  {
    if ( a9 == 2 )
    {
      v18[6] = a8;
      v19 = v19 & 0xFFFFFFE0 | 3;
    }
    raise_exc((unsigned int)v18, (unsigned int)&v16, a5, a2, (__int64)&a7, (__int64)v17);
  }
  if ( _acrt_has_user_matherr() && a4 != 0 )
    return call_matherr(a4, a6, a1, a7, v14, v17[0], v16);
  set_errno_from_matherr(a4);
  ctrlfp(v16, 65472);
  return v17[0];
}


// ===== __acrt_initialize_fma3 @ 0x180018320 size=0x70 =====
__int64 _acrt_initialize_fma3()
{
  int v0; // r8d

  v0 = 0;
  dword_18002B448 = 0;
  _RAX = 1;
  __asm { cpuid }
  if ( (_RCX & 0x18001000) == 0x18001000 )
  {
    __asm { xgetbv }
    v0 = dword_18002B448;
  }
  dword_18002B44C = v0;
  return 0;
}


// ===== _log10_special @ 0x180018390 size=0x20 =====
__int64 __fastcall log10_special(int a1, int a2, int a3)
{
  return log_special_common(a1, a2, a3, 27, (__int64)"log10");
}


// ===== _log_special_common @ 0x1800183b0 size=0x96 =====
// local variable allocation has failed, the output may be wrong!
__m128 __fastcall log_special_common(double a1, double a2, int a3, int a4, __int64 a5)
{
  __int128 v5; // xmm6
  int v7; // r8d
  unsigned int v8; // r9d
  int v10; // [rsp+20h] [rbp-48h]
  unsigned int v11; // [rsp+28h] [rbp-40h]
  double v12; // [rsp+30h] [rbp-38h]

  v5 = *(_OWORD *)&a2;
  v7 = a3 - 1;
  if ( v7 == 0 )
  {
    v8 = 2;
    v12 = a1;
    v11 = 34;
    v10 = 4;
    goto LABEL_5;
  }
  if ( v7 == 1 )
  {
    v8 = 1;
    v12 = a1;
    v11 = 33;
    v10 = 8;
LABEL_5:
    handle_error(a5, a4, *(__int64 *)&a2, v8, v10, v11, v12, 0, 1);
  }
  return (__m128)v5;
}


// ===== sub_180018448 @ 0x180018448 size=0x3b =====
HANDLE sub_180018448()
{
  HANDLE result; // rax

  result = CreateFileW(L"CONOUT$", 0x40000000u, 3u, nullptr, 3u, 0, nullptr);
  hObject = result;
  return result;
}


// ===== sub_180018484 @ 0x180018484 size=0x20 =====
int sub_180018484()
{
  int result; // eax

  result = (_DWORD)hObject + 2;
  if ( (unsigned __int64)hObject + 2 > 1 )
    return CloseHandle(hObject);
  return result;
}


// ===== _get_fpsr @ 0x1800184c0 size=0x10 =====
__int64 get_fpsr()
{
  return (unsigned int)_mm_getcsr();
}


// ===== _set_fpsr @ 0x1800184d0 size=0xa =====
void __fastcall set_fpsr(unsigned int a1)
{
  _mm_setcsr(a1);
}


// ===== _fclrf @ 0x1800184da size=0x14 =====
void fclrf()
{
  _mm_setcsr(_mm_getcsr() & 0xFFFFFFC0);
}


// ===== _return @ 0x18001850c size=0x1 =====
void return()
{
  ;
}


// ===== _raise_exc @ 0x180018510 size=0x27 =====
__int64 __fastcall raise_exc(int a1, int a2, int a3, int a4, __int64 a5, __int64 a6)
{
  return raise_exc_ex(a1, a2, a3, a4, a5, a6, 0);
}


// ===== _raise_exc_ex @ 0x180018538 size=0x306 =====
__int64 __fastcall raise_exc_ex(ULONG_PTR a1, _QWORD *a2, char a3, __int16 a4, _DWORD *a5, _DWORD *a6, int a7)
{
  DWORD v9; // edi
  char v10; // al
  __int64 v11; // rax
  _DWORD *v12; // rsi
  ULONG_PTR v13; // rcx
  __int64 result; // rax
  ULONG_PTR Arguments; // [rsp+30h] [rbp+10h] BYREF

  Arguments = a1;
  v9 = -1073741811;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(Arguments + 8) = 0;
  *(_DWORD *)(Arguments + 12) = 0;
  if ( (a3 & 0x10) != 0 )
  {
    v9 = -1073741681;
    *(_DWORD *)(Arguments + 4) |= 1u;
  }
  if ( (a3 & 2) != 0 )
  {
    v9 = -1073741677;
    *(_DWORD *)(Arguments + 4) |= 2u;
  }
  if ( (a3 & 1) != 0 )
  {
    v9 = -1073741679;
    *(_DWORD *)(Arguments + 4) |= 4u;
  }
  if ( (a3 & 4) != 0 )
  {
    v9 = -1073741682;
    *(_DWORD *)(Arguments + 4) |= 8u;
  }
  if ( (a3 & 8) != 0 )
  {
    v9 = -1073741680;
    *(_DWORD *)(Arguments + 4) |= 0x10u;
  }
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(16 * (*a2 >> 7))) & 0x10;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(8 * (*a2 >> 9))) & 8;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(4 * (*a2 >> 10))) & 4;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(2 * (*a2 >> 11))) & 2;
  *(_DWORD *)(Arguments + 8) ^= (*(_DWORD *)(Arguments + 8) ^ ~(*(_DWORD *)a2 >> 12)) & 1;
  v10 = statfp();
  if ( (v10 & 1) != 0 )
    *(_DWORD *)(Arguments + 12) |= 0x10u;
  if ( (v10 & 4) != 0 )
    *(_DWORD *)(Arguments + 12) |= 8u;
  if ( (v10 & 8) != 0 )
    *(_DWORD *)(Arguments + 12) |= 4u;
  if ( (v10 & 0x10) != 0 )
    *(_DWORD *)(Arguments + 12) |= 2u;
  if ( (v10 & 0x20) != 0 )
    *(_DWORD *)(Arguments + 12) |= 1u;
  v11 = *(_DWORD *)a2 & 0x6000LL;
  if ( v11 != 0 )
  {
    switch ( v11 )
    {
      case 8192LL:
        *(_DWORD *)Arguments &= ~2u;
        *(_DWORD *)Arguments |= 1u;
        break;
      case 16384LL:
        *(_DWORD *)Arguments &= ~1u;
        *(_DWORD *)Arguments |= 2u;
        break;
      case 24576LL:
        *(_DWORD *)Arguments |= 3u;
        break;
      default:
        break;
    }
  }
  else
  {
    *(_DWORD *)Arguments &= 0xFFFFFFFC;
  }
  *(_DWORD *)Arguments &= 0xFFFE001F;
  *(_DWORD *)Arguments |= 32 * (a4 & 0xFFF);
  v12 = a6;
  *(_DWORD *)(Arguments + 32) |= 1u;
  if ( a7 != 0 )
  {
    *(_DWORD *)(Arguments + 32) &= 0xFFFFFFE1;
    *(_DWORD *)(Arguments + 16) = *a5;
    *(_DWORD *)(Arguments + 96) |= 1u;
    *(_DWORD *)(Arguments + 96) &= 0xFFFFFFE1;
    *(_DWORD *)(Arguments + 80) = *v12;
  }
  else
  {
    *(_DWORD *)(Arguments + 32) = *(_DWORD *)(Arguments + 32) & 0xFFFFFFE1 | 2;
    *(_QWORD *)(Arguments + 16) = *(_QWORD *)a5;
    *(_DWORD *)(Arguments + 96) |= 1u;
    *(_DWORD *)(Arguments + 96) = *(_DWORD *)(Arguments + 96) & 0xFFFFFFE1 | 2;
    *(_QWORD *)(Arguments + 80) = *(_QWORD *)v12;
  }
  clrfp();
  RaiseException(v9, 0, 1u, &Arguments);
  v13 = Arguments;
  if ( (*(_BYTE *)(Arguments + 8) & 0x10) != 0 )
    *a2 &= ~0x80uLL;
  if ( (*(_BYTE *)(v13 + 8) & 8) != 0 )
    *a2 &= ~0x200uLL;
  if ( (*(_BYTE *)(v13 + 8) & 4) != 0 )
    *a2 &= ~0x400uLL;
  if ( (*(_BYTE *)(v13 + 8) & 2) != 0 )
    *a2 &= ~0x800uLL;
  if ( (*(_BYTE *)(v13 + 8) & 1) != 0 )
    *a2 &= ~0x1000uLL;
  if ( (*(_DWORD *)v13 & 3) != 0 )
  {
    switch ( *(_DWORD *)v13 & 3 )
    {
      case 1:
        *a2 &= ~0x4000uLL;
        *a2 |= 0x2000uLL;
        break;
      case 2:
        *a2 &= ~0x2000uLL;
        *a2 |= 0x4000uLL;
        break;
      case 3:
        *a2 |= 0x6000uLL;
        break;
      default:
        break;
    }
  }
  else
  {
    *a2 &= 0xFFFFFFFFFFFF9FFFuLL;
  }
  if ( a7 != 0 )
  {
    result = *(unsigned int *)(v13 + 80);
    *v12 = result;
  }
  else
  {
    result = *(_QWORD *)(v13 + 80);
    *(_QWORD *)v12 = result;
  }
  return result;
}


// ===== _set_errno_from_matherr @ 0x180018840 size=0x2e =====
int *__fastcall set_errno_from_matherr(int a1)
{
  int *result; // rax

  if ( a1 == 1 )
  {
    result = errno();
    *result = 33;
  }
  else
  {
    result = (int *)(unsigned int)(a1 - 2);
    if ( (unsigned int)result <= 1 )
    {
      result = errno();
      *result = 34;
    }
  }
  return result;
}


// ===== _clrfp @ 0x180018870 size=0x1d =====
__int64 clrfp()
{
  unsigned int v0; // ebx

  v0 = get_fpsr() & 0x3F;
  fclrf();
  return v0;
}


// ===== _ctrlfp @ 0x180018890 size=0x7c =====
__int64 __fastcall ctrlfp(int a1, int a2)
{
  unsigned int fpsr; // esi
  unsigned int v5; // ecx

  fpsr = get_fpsr();
  v5 = a2 & a1 | fpsr & (~(_WORD)a2 | 0xFFFF807F);
  if ( byte_180029B50 != 0 && (v5 & 0x40) != 0 )
    set_fpsr(v5);
  else
    set_fpsr(v5 & 0xFFFFFFBF);
  return fpsr;
}


// ===== _set_statfp @ 0x18001890c size=0x1f =====
void __fastcall set_statfp(char a1)
{
  int fpsr; // eax

  fpsr = get_fpsr();
  set_fpsr(a1 & 0x3F | fpsr);
}


// ===== _statfp @ 0x18001892c size=0x11 =====
__int64 statfp()
{
  return get_fpsr() & 0x3F;
}


// ===== IsProcessorFeaturePresent @ 0x18001893d size=0x6 =====
// attributes: thunk
BOOL __stdcall IsProcessorFeaturePresent(DWORD ProcessorFeature)
{
  return __imp_IsProcessorFeaturePresent(ProcessorFeature);
}


// ===== sub_180018944 @ 0x180018944 size=0xaa =====
void __spoils<> sub_180018944()
{
  ;
}


// ===== sub_1800189F0 @ 0x1800189f0 size=0x9b =====
bool sub_1800189F0()
{
  HMODULE ModuleHandleW; // rax
  signed __int64 v1; // rbx
  void (__stdcall *AcquireSRWLockExclusive)(PSRWLOCK); // rax
  void (__stdcall *ReleaseSRWLockExclusive)(PSRWLOCK); // rax
  signed __int64 v4; // rax
  bool result; // al

  result = false;
  if ( qword_18002B450 != 1 )
  {
    if ( qword_18002B450 != 0 )
      return true;
    ModuleHandleW = GetModuleHandleW(L"KERNEL32.DLL");
    v1 = (signed __int64)ModuleHandleW;
    if ( ModuleHandleW != nullptr
      && (AcquireSRWLockExclusive = (void (__stdcall *)(PSRWLOCK))GetProcAddress(
                                                                    ModuleHandleW,
                                                                    "AcquireSRWLockExclusive")) != nullptr
      && (qword_18002B458 = (__int64)AcquireSRWLockExclusive,
          (ReleaseSRWLockExclusive = (void (__stdcall *)(PSRWLOCK))GetProcAddress(
                                                                     (HMODULE)v1,
                                                                     "ReleaseSRWLockExclusive")) != nullptr) )
    {
      qword_18002B460 = (__int64)ReleaseSRWLockExclusive;
    }
    else
    {
      v1 = 1;
    }
    v4 = _InterlockedCompareExchange64(&qword_18002B450, v1, 0);
    if ( (v4 != 0 || v1 != 1) && v4 != 1 )
      return true;
  }
  return result;
}


// ===== sub_180018A8C @ 0x180018a8c size=0x98 =====
SIZE_T __fastcall sub_180018A8C(unsigned __int64 a1, unsigned __int64 a2)
{
  SIZE_T result; // rax
  __int64 dwPageSize; // r9
  volatile signed __int32 *v6; // r8
  unsigned __int64 v7; // rcx
  struct _MEMORY_BASIC_INFORMATION Buffer; // [rsp+20h] [rbp-68h] BYREF
  struct _SYSTEM_INFO SystemInfo; // [rsp+50h] [rbp-38h] BYREF

  result = VirtualQuery((LPCVOID)a1, &Buffer, 0x30u);
  if ( result == 0 )
    __fastfail(0x19u);
  if ( (Buffer.Protect & 0x44) != 0 )
  {
    GetSystemInfo(&SystemInfo);
    dwPageSize = SystemInfo.dwPageSize;
    v6 = (volatile signed __int32 *)(a1 & -(__int64)SystemInfo.dwPageSize);
    v7 = a2 / SystemInfo.dwPageSize
       + (SystemInfo.dwPageSize
        + (unsigned __int64)(((unsigned int)a1 & (SystemInfo.dwPageSize - 1))
                           + ((unsigned int)a2 & (SystemInfo.dwPageSize - 1)))
        - 1)
       / SystemInfo.dwPageSize;
    for ( result = (unsigned int)v7; result != 0; --result )
    {
      _InterlockedOr(v6, 0);
      v6 = (volatile signed __int32 *)((char *)v6 + dwPageSize);
    }
  }
  return result;
}


// ===== sub_180018B24 @ 0x180018b24 size=0x99 =====
char *__fastcall sub_180018B24(_DWORD *a1, _DWORD *a2)
{
  __int64 v4; // r10
  unsigned int v5; // r9d
  _DWORD *v6; // rcx
  unsigned int v7; // r10d
  unsigned int v8; // eax
  int v9; // edx

  if ( *(_DWORD *)&byte_180000040[(int)off_18000003C + 68] <= 0xDu )
    return nullptr;
  v4 = *(unsigned int *)&byte_180000040[(int)off_18000003C + 176];
  v5 = 0;
  if ( (_DWORD)v4 == 0 )
    return nullptr;
  v6 = (_DWORD *)((char *)&word_180000018
                + (int)off_18000003C
                + *(unsigned __int16 *)((char *)&word_180000014 + (int)off_18000003C));
  v7 = *(_DWORD *)((char *)&word_18000000C + v4);
  if ( *(__int16 *)((char *)&word_180000006 + (int)off_18000003C) == 0 )
    return nullptr;
  while ( 1 )
  {
    v8 = v6[3];
    if ( v7 >= v8 )
    {
      v9 = v6[2];
      if ( v7 < v9 + v8 )
        break;
    }
    ++v5;
    v6 += 10;
    if ( v5 >= *(unsigned __int16 *)((char *)&word_180000006 + (int)off_18000003C) )
      return nullptr;
  }
  *a1 = v9;
  *a2 = v6[9];
  return (char *)&_ImageBase + (unsigned int)v6[3];
}


// ===== sub_180018BC0 @ 0x180018bc0 size=0x8e =====
int __fastcall sub_180018BC0(DWORD flNewProtect, PDWORD lpflOldProtect)
{
  char *v4; // rax
  char *v5; // rbx
  SIZE_T dwSize; // [rsp+40h] [rbp+18h] BYREF
  int v8; // [rsp+48h] [rbp+20h] BYREF

  v4 = sub_180018B24(&dwSize, &v8);
  v5 = v4;
  if ( v4 != nullptr )
  {
    if ( dword_18002B478 == 0 )
    {
      dword_18002B478 = 1;
      if ( v8 >= 0 )
        __fastfail(0x19u);
      sub_180018A8C((unsigned __int64)v4, (unsigned int)dwSize);
    }
    LODWORD(v4) = VirtualProtect(v5, (unsigned int)dwSize, flNewProtect, lpflOldProtect);
    if ( (_DWORD)v4 == 0 )
      __fastfail(0x19u);
  }
  else
  {
    *lpflOldProtect = 4;
  }
  return (int)v4;
}


// ===== sub_180018C50 @ 0x180018c50 size=0x93 =====
void __spoils<> sub_180018C50()
{
  ;
}


// ===== sub_180018CE4 @ 0x180018ce4 size=0x2bd =====
FARPROC __fastcall sub_180018CE4(_DWORD *a1, char *a2)
{
  volatile __int64 *v4; // r14
  char *v5; // r9
  __int64 v6; // r13
  char *v7; // rcx
  char *v8; // r13
  int v9; // edx
  int v10; // eax
  HMODULE Library; // rdi
  __int64 v13; // r15
  bool v14; // zf
  __int64 v15; // rax
  FARPROC ProcAddress; // rbx
  int v17; // [rsp+20h] [rbp-58h] BYREF
  _DWORD *v18; // [rsp+28h] [rbp-50h]
  char *v19; // [rsp+30h] [rbp-48h]
  LPCSTR lpLibFileName; // [rsp+38h] [rbp-40h]
  __int64 v21; // [rsp+40h] [rbp-38h]
  LPCSTR lpProcName; // [rsp+48h] [rbp-30h]
  HMODULE v23; // [rsp+50h] [rbp-28h]
  INT_PTR (__stdcall *v24)(); // [rsp+58h] [rbp-20h]
  DWORD LastError; // [rsp+60h] [rbp-18h]
  int v26; // [rsp+C0h] [rbp+48h]
  ULONG_PTR Arguments; // [rsp+C8h] [rbp+50h] BYREF
  ULONG_PTR v28; // [rsp+D0h] [rbp+58h] BYREF
  ULONG_PTR v29; // [rsp+D8h] [rbp+60h] BYREF

  sub_180018944();
  v4 = (volatile __int64 *)((char *)&_ImageBase + (unsigned int)a1[2]);
  v5 = (char *)&_ImageBase + (unsigned int)a1[3];
  v6 = (unsigned int)a1[5];
  v7 = (char *)&_ImageBase + (unsigned int)a1[4];
  lpLibFileName = (char *)&_ImageBase + (unsigned int)a1[1];
  v8 = (char *)&_ImageBase + v6;
  v9 = a1[7];
  v23 = nullptr;
  v24 = nullptr;
  LastError = 0;
  v21 = 0;
  lpProcName = nullptr;
  v10 = *a1 & 1;
  v26 = v9;
  v17 = 72;
  v18 = a1;
  v19 = a2;
  if ( (_BYTE)v10 == 0 )
  {
    Arguments = (ULONG_PTR)&v17;
    sub_180018C50();
    RaiseException(0xC06D0057, 0, 1u, &Arguments);
    return nullptr;
  }
  Library = (HMODULE)*v4;
  v13 = (unsigned int)((a2 - v5) >> 3);
  v14 = *(__int64 *)&v7[8 * v13] < 0;
  LODWORD(v21) = *(_QWORD *)&v7[8 * v13] >= 0LL;
  if ( v14 )
    LODWORD(lpProcName) = *(unsigned __int16 *)&v7[8 * v13];
  else
    lpProcName = (char *)&word_180000002 + *(unsigned int *)&v7[8 * v13];
  if ( Library == nullptr )
  {
    Library = LoadLibraryExA(lpLibFileName, nullptr, 0);
    if ( Library == nullptr )
    {
      LastError = GetLastError();
      v28 = (ULONG_PTR)&v17;
      sub_180018C50();
      RaiseException(0xC06D007E, 0, 1u, &v28);
      return v24;
    }
    if ( (HMODULE)_InterlockedExchange64(v4, (__int64)Library) == Library )
      FreeLibrary(Library);
  }
  v23 = Library;
  if ( a1[5] == 0
    || a1[7] == 0
    || *(_DWORD *)((char *)Library + (v15 = *((int *)Library + 15))) != 17744
    || *(_DWORD *)((char *)Library + v15 + 8) != v26
    || Library != *(HMODULE *)((char *)Library + v15 + 48)
    || (ProcAddress = *(FARPROC *)&v8[8 * v13]) == nullptr )
  {
    ProcAddress = GetProcAddress(Library, lpProcName);
    if ( ProcAddress == nullptr )
    {
      LastError = GetLastError();
      v29 = (ULONG_PTR)&v17;
      sub_180018C50();
      RaiseException(0xC06D007F, 0, 1u, &v29);
      sub_180018944();
      ProcAddress = v24;
    }
  }
  *(_QWORD *)a2 = ProcAddress;
  sub_180018C50();
  return ProcAddress;
}


// ===== _FindPESection @ 0x180018fb0 size=0x44 =====
__int64 __fastcall FindPESection(__int64 a1, unsigned __int64 a2)
{
  unsigned int v2; // r9d
  __int64 v3; // r8
  __int64 result; // rax
  unsigned __int64 v6; // rdx

  v2 = 0;
  v3 = a1 + *(int *)(a1 + 60);
  result = v3 + *(unsigned __int16 *)(v3 + 20) + 24LL;
  if ( *(_WORD *)(v3 + 6) == 0 )
    return 0;
  while ( 1 )
  {
    v6 = *(unsigned int *)(result + 12);
    if ( a2 >= v6 && a2 < (unsigned int)(v6 + *(_DWORD *)(result + 8)) )
      break;
    ++v2;
    result += 40;
    if ( v2 >= *(unsigned __int16 *)(v3 + 6) )
      return 0;
  }
  return result;
}


// ===== _IsNonwritableInCurrentImage @ 0x180019000 size=0x4d =====
__int64 __fastcall IsNonwritableInCurrentImage(__int64 a1)
{
  __int64 result; // rax

  result = ValidateImageBase(&_ImageBase);
  if ( (_DWORD)result != 0 )
  {
    result = FindPESection((__int64)&_ImageBase, a1 - (_QWORD)&_ImageBase);
    if ( result != 0 )
      return *(int *)(result + 36) >= 0;
  }
  return result;
}


// ===== _ValidateImageBase @ 0x180019050 size=0x2d =====
_BOOL8 __fastcall ValidateImageBase(__int64 a1)
{
  __int64 v1; // rax
  _BOOL8 result; // rax

  result = false;
  if ( *(_WORD *)a1 == 23117 )
  {
    v1 = a1 + *(int *)(a1 + 60);
    if ( *(_DWORD *)v1 == 17744 && *(_WORD *)(v1 + 24) == 523 )
      return true;
  }
  return result;
}


// ===== strrchr @ 0x180019080 size=0x149 =====
char *__cdecl strrchr(const char *Str, int Ch)
{
  char *v2; // r8
  __m128i *v3; // r9
  const __m128i *v4; // rdx
  unsigned int j; // eax
  __m128i *v7; // r10
  int v8; // r9d
  __m128i v9; // xmm3
  unsigned int v10; // edx
  int i; // ecx
  unsigned int v12; // ecx
  char *v13; // rcx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  char *v16; // rcx
  char *v17; // rcx
  __m128i v18; // xmm0
  unsigned __int8 v19; // zf
  int v20; // ecx

  v2 = nullptr;
  v3 = (__m128i *)Str;
  if ( Ch != 0 )
  {
    if ( dword_180029018 >= 2 )
    {
      while ( ((unsigned __int8)v3 & 0xF) != 0 )
      {
        v17 = (char *)v3;
        if ( v3->m128i_i8[0] != Ch )
          v17 = v2;
        v2 = v17;
        if ( v3->m128i_i8[0] == 0 )
          return v17;
        v3 = (__m128i *)((char *)v3 + 1);
      }
      v18 = _mm_cvtsi32_si128((unsigned __int8)Ch);
      while ( 1 )
      {
        v20 = _mm_cmpistri(v18, *v3, 64);
        v19 = _mm_cmpistrz(v18, *v3, 64);
        if ( _mm_cmpistrc(v18, *v3, 64) )
        {
          v2 = &v3->m128i_i8[v20];
          v19 = _mm_cmpistrz(v18, *v3, 64);
        }
        if ( v19 )
          break;
        ++v3;
      }
    }
    else
    {
      v7 = (__m128i *)((unsigned __int64)Str & 0xFFFFFFFFFFFFFFF0uLL);
      v8 = -1 << ((unsigned __int8)Str & 0xF);
      v9 = _mm_shuffle_epi32(
             _mm_shufflelo_epi16(_mm_cvtsi32_si128((unsigned __int8)Ch | ((unsigned __int8)Ch << 8)), 0),
             0);
      v10 = v8 & _mm_movemask_epi8(_mm_cmpeq_epi8(v9, *(__m128i *)((unsigned __int64)Str & 0xFFFFFFFFFFFFFFF0uLL)));
      for ( i = v8
              & _mm_movemask_epi8(_mm_cmpeq_epi8((__m128i)0LL, *(__m128i *)((unsigned __int64)Str & 0xFFFFFFFFFFFFFFF0uLL)));
            i == 0;
            v10 = _mm_movemask_epi8(_mm_cmpeq_epi8(v9, *v7)) )
      {
        _BitScanReverse(&v12, v10);
        v13 = &v7->m128i_i8[v12];
        if ( v10 != 0 )
          v2 = v13;
        i = _mm_movemask_epi8(_mm_cmpeq_epi8((__m128i)0LL, *++v7));
      }
      v14 = ((i & -i) - 1) & v10;
      _BitScanReverse(&v15, v14);
      v16 = &v7->m128i_i8[v15];
      if ( v14 != 0 )
        return v16;
    }
    return v2;
  }
  else
  {
    v4 = (const __m128i *)((unsigned __int64)Str & 0xFFFFFFFFFFFFFFF0uLL);
    for ( j = (-1 << ((unsigned __int8)Str & 0xF))
            & _mm_movemask_epi8(
                _mm_cmpeq_epi8(
                  _mm_loadu_si128((const __m128i *)((unsigned __int64)Str & 0xFFFFFFFFFFFFFFF0uLL)),
                  (__m128i)0LL)); j == 0; j = _mm_movemask_epi8(_mm_cmpeq_epi8(_mm_loadu_si128(v4), (__m128i)0LL)) )
      ++v4;
    _BitScanForward(&j, j);
    return &v4->m128i_i8[j];
  }
}


// ===== memcmp @ 0x1800191e0 size=0xc7 =====
int __cdecl memcmp(const void *Buf1, const void *Buf2, size_t Size)
{
  signed __int64 v3; // rdx
  bool v4; // cf
  size_t v6; // r9
  unsigned __int64 v7; // rax
  size_t v8; // r9

  v3 = (_BYTE *)Buf2 - (_BYTE *)Buf1;
  if ( Size < 8 )
    goto mcmp30;
  for ( ; ((unsigned __int8)Buf1 & 7) != 0; --Size )
  {
    v4 = *(_BYTE *)Buf1 < *((_BYTE *)Buf1 + v3);
    if ( *(_BYTE *)Buf1 != *((_BYTE *)Buf1 + v3) )
      return -v4 - (v4 - 1);
    Buf1 = (char *)Buf1 + 1;
  }
  if ( Size >> 3 == 0 )
  {
mcmp30:
    if ( Size == 0 )
      return 0;
    while ( 1 )
    {
      v4 = *(_BYTE *)Buf1 < *((_BYTE *)Buf1 + v3);
      if ( *(_BYTE *)Buf1 != *((_BYTE *)Buf1 + v3) )
        break;
      Buf1 = (char *)Buf1 + 1;
      if ( --Size == 0 )
        return 0;
    }
    return -v4 - (v4 - 1);
  }
  v6 = Size >> 5;
  if ( Size >> 5 != 0 )
  {
    while ( 1 )
    {
      v7 = *(_QWORD *)Buf1;
      if ( *(_QWORD *)Buf1 != *(_QWORD *)((char *)Buf1 + v3) )
        break;
      v7 = *((_QWORD *)Buf1 + 1);
      if ( v7 != *(_QWORD *)((char *)Buf1 + v3 + 8) )
        goto mcmp_adjust8;
      v7 = *((_QWORD *)Buf1 + 2);
      if ( v7 != *(_QWORD *)((char *)Buf1 + v3 + 16) )
        goto mcmp_adjust16;
      v7 = *((_QWORD *)Buf1 + 3);
      if ( v7 != *(_QWORD *)((char *)Buf1 + v3 + 24) )
      {
        Buf1 = (char *)Buf1 + 8;
mcmp_adjust16:
        Buf1 = (char *)Buf1 + 8;
mcmp_adjust8:
        Buf1 = (char *)Buf1 + 8;
        break;
      }
      Buf1 = (char *)Buf1 + 32;
      if ( --v6 == 0 )
      {
        Size &= 0x1Fu;
        goto mcmp70;
      }
    }
  }
  else
  {
mcmp70:
    v8 = Size >> 3;
    if ( Size >> 3 == 0 )
      goto mcmp30;
    while ( 1 )
    {
      v7 = *(_QWORD *)Buf1;
      if ( *(_QWORD *)Buf1 != *(_QWORD *)((char *)Buf1 + v3) )
        break;
      Buf1 = (char *)Buf1 + 8;
      if ( --v8 == 0 )
      {
        Size &= 7u;
        goto mcmp30;
      }
    }
  }
  v4 = _byteswap_uint64(v7) < _byteswap_uint64(*(_QWORD *)((char *)Buf1 + v3));
  return -v4 - (v4 - 1);
}


// ===== _guard_dispatch_icall_nop @ 0x1800192c0 size=0x2 =====
__int64 __fastcall guard_dispatch_icall_nop()
{
  __int64 (*v0)(void); // rax

  return v0();
}


// ===== sub_1800192D0 @ 0x1800192d0 size=0x2a =====
void __fastcall __noreturn sub_1800192D0(__int64 a1, __int64 a2)
{
  sub_180005950(*(_QWORD *)(a2 + 64), *(void **)(a2 + 32), 1);
  throw;
}


// ===== sub_180019300 @ 0x180019300 size=0xc =====
void __fastcall sub_180019300(__int64 a1, __int64 a2)
{
  sub_180002520(*(_QWORD *)(a2 + 64));
}


// ===== ?dtor$1@?0???0?$basic_stringstream@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@H@Z@4HA @ 0x180019310 size=0x10 =====
// Microsoft VisualC v7/14 64bit runtime
void __fastcall `std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>'::`1'::dtor$1(
        __int64 a1,
        __int64 a2)
{
  sub_180002450((void **)(*(_QWORD *)(a2 + 64) + 32LL));
}


// ===== sub_180019320 @ 0x180019320 size=0x1d =====
void __fastcall sub_180019320(__int64 a1, __int64 a2)
{
  j_j_j__free_base(*(void **)(a2 + 48));
}


// ===== sub_180019340 @ 0x180019340 size=0xc =====
void __fastcall sub_180019340(__int64 a1, __int64 a2)
{
  sub_1800023B0(*(void ***)(a2 + 48));
}


// ===== sub_180019350 @ 0x180019350 size=0xc =====
void __fastcall sub_180019350(__int64 a1, __int64 a2)
{
  sub_180002390(*(void ***)(a2 + 48));
}


// ===== ?dtor$1@?0???0_Locinfo@std@@QEAA@PEBD@Z@4HA @ 0x180019360 size=0x10 =====
void __fastcall `std::_Locinfo::_Locinfo'::`1'::dtor$1(__int64 a1, __int64 a2)
{
  sub_180002480(*(_QWORD *)(a2 + 64) + 8LL);
}


// ===== ?dtor$0@?0??AllocateScheduleGroup@SchedulingRing@details@Concurrency@@QEAAPEAVScheduleGroupBase@23@XZ@4HA @ 0x180019370 size=0xc =====
void __fastcall `Concurrency::details::SchedulingRing::AllocateScheduleGroup'::`1'::dtor$0(__int64 a1, __int64 a2)
{
  __int64 v2; // rcx

  v2 = *(_QWORD *)(a2 + 64);
  if ( *(_BYTE *)(v2 + 40) != 0 )
  {
    *(_BYTE *)(v2 + 40) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)v2);
  }
}


// ===== ?dtor$1@?0??AllocateScheduleGroup@SchedulingRing@details@Concurrency@@QEAAPEAVScheduleGroupBase@23@XZ@4HA @ 0x180019380 size=0xc =====
void __fastcall `Concurrency::details::SchedulingRing::AllocateScheduleGroup'::`1'::dtor$1(__int64 a1, __int64 a2)
{
  sub_180002390(*(void ***)(a2 + 64));
}


// ===== ?dtor$0@?0???0?$target_block@V?$multi_link_registry@V?$ISource@_K@Concurrency@@@Concurrency@@V?$ordered_message_processor@_K@2@@Concurrency@@QEAA@XZ@4HA @ 0x180019390 size=0xc =====
void __fastcall `Concurrency::target_block<Concurrency::multi_link_registry<Concurrency::ISource<unsigned __int64>>,Concurrency::ordered_message_processor<unsigned __int64>>::target_block<Concurrency::multi_link_registry<Concurrency::ISource<unsigned __int64>>,Concurrency::ordered_message_processor<unsigned __int64>>'::`1'::dtor$0(
        __int64 a1,
        __int64 a2)
{
  sub_1800023B0(*(void ***)(a2 + 64));
}


// ===== ?dtor$1@?0???0?$target_block@V?$multi_link_registry@V?$ISource@_K@Concurrency@@@Concurrency@@V?$ordered_message_processor@_K@2@@Concurrency@@QEAA@XZ@4HA @ 0x1800193a0 size=0x10 =====
void __fastcall `Concurrency::target_block<Concurrency::multi_link_registry<Concurrency::ISource<unsigned __int64>>,Concurrency::ordered_message_processor<unsigned __int64>>::target_block<Concurrency::multi_link_registry<Concurrency::ISource<unsigned __int64>>,Concurrency::ordered_message_processor<unsigned __int64>>'::`1'::dtor$1(
        __int64 a1,
        __int64 a2)
{
  sub_1800022F0(*(_QWORD *)(a2 + 64) + 8LL);
}


// ===== ?dtor$0@?0???0?$target_block@V?$multi_link_registry@V?$ISource@_K@Concurrency@@@Concurrency@@V?$ordered_message_processor@_K@2@@Concurrency@@QEAA@XZ@4HA_0 @ 0x1800193b0 size=0xc =====
void __fastcall `Concurrency::target_block<Concurrency::multi_link_registry<Concurrency::ISource<unsigned __int64>>,Concurrency::ordered_message_processor<unsigned __int64>>::target_block<Concurrency::multi_link_registry<Concurrency::ISource<unsigned __int64>>,Concurrency::ordered_message_processor<unsigned __int64>>'::`1'::dtor$0(
        __int64 a1,
        __int64 a2)
{
  sub_180002330(*(_QWORD *)(a2 + 64));
}


// ===== ?dtor$1@?0???0?$target_block@V?$multi_link_registry@V?$ISource@_K@Concurrency@@@Concurrency@@V?$ordered_message_processor@_K@2@@Concurrency@@QEAA@XZ@4HA_0 @ 0x1800193c0 size=0x10 =====
void __fastcall `Concurrency::target_block<Concurrency::multi_link_registry<Concurrency::ISource<unsigned __int64>>,Concurrency::ordered_message_processor<unsigned __int64>>::target_block<Concurrency::multi_link_registry<Concurrency::ISource<unsigned __int64>>,Concurrency::ordered_message_processor<unsigned __int64>>'::`1'::dtor$1(
        __int64 a1,
        __int64 a2)
{
  sub_180002590(*(_QWORD *)(a2 + 64) + 8LL);
}


// ===== sub_1800193D0 @ 0x1800193d0 size=0xc =====
void __fastcall sub_1800193D0(__int64 a1, __int64 a2)
{
  sub_1800024B0(*(_QWORD **)(a2 + 64));
}


// ===== ?dtor$0@?0???$__acrt_get_current_directory@U__crt_win32_buffer_internal_dynamic_resizing@@@@YAHAEAV?$__crt_win32_buffer@DU__crt_win32_buffer_internal_dynamic_resizing@@@@@Z@4HA @ 0x1800193e0 size=0xc =====
void __fastcall `__acrt_get_current_directory<__crt_win32_buffer_internal_dynamic_resizing>'::`1'::dtor$0(
        __int64 a1,
        __int64 a2)
{
  sub_1800022D0((void **)(a2 + 32));
}


// ===== unknown_libname_27 @ 0x1800193f0 size=0xc =====
// Microsoft VisualC v14 64bit runtime
void __fastcall unknown_libname_27(__int64 a1, __int64 a2)
{
  sub_1800022D0((void **)(a2 + 152));
}


// ===== sub_180019400 @ 0x180019400 size=0x30 =====
__int64 __fastcall sub_180019400(__int64 a1, __int64 a2)
{
  return 8LL * *(int *)(a2 + 136);
}


// ===== sub_180019430 @ 0x180019430 size=0x34 =====
__int64 __fastcall sub_180019430(__int64 a1, __int64 a2)
{
  return 8LL * *(int *)(a2 + 136);
}


// ===== unknown_libname_4 @ 0x180019470 size=0xc =====
// Microsoft VisualC v7/14 64bit runtime
void __fastcall unknown_libname_4(__int64 a1, __int64 a2)
{
  sub_180002290((_QWORD **)(a2 + 72));
}


// ===== unknown_libname_28 @ 0x180019480 size=0x1b =====
// Microsoft VisualC v14 64bit runtime
// positive sp value has been detected, the output may be wrong!
void *unknown_libname_28()
{
  return &loc_180002A73;
}


// ===== unknown_libname_30 @ 0x18001949b size=0x1b =====
// Microsoft VisualC v14 64bit runtime
// positive sp value has been detected, the output may be wrong!
void *unknown_libname_30()
{
  return &loc_180002C72;
}


// ===== sub_1800194C0 @ 0x1800194c0 size=0xc =====
__int64 __fastcall sub_1800194C0(__int64 a1, __int64 a2)
{
  return sub_180002380(a2 + 112);
}


// ===== sub_1800194D0 @ 0x1800194d0 size=0xc =====
void __fastcall sub_1800194D0(__int64 a1, __int64 a2)
{
  sub_180002290((_QWORD **)(a2 + 64));
}


// ===== unknown_libname_32 @ 0x1800194e0 size=0x1b =====
// Microsoft VisualC v7/14 64bit runtime
// Microsoft VisualC v14 64bit runtime
// positive sp value has been detected, the output may be wrong!
void *unknown_libname_32()
{
  return &loc_180003123;
}


// ===== sub_180019500 @ 0x180019500 size=0x1f =====
void __fastcall sub_180019500(__int64 a1, __int64 a2)
{
  j_j_j__free_base(*(void **)(a2 + 48));
}


// ===== unknown_libname_34 @ 0x180019520 size=0x1b =====
// Microsoft VisualC v7/14 64bit runtime
// Microsoft VisualC v14 64bit runtime
// positive sp value has been detected, the output may be wrong!
void *unknown_libname_34()
{
  return &loc_180001DBD;
}


// ===== sub_180019540 @ 0x180019540 size=0xc =====
void __fastcall sub_180019540(__int64 a1, __int64 a2)
{
  sub_1800024B0(*(_QWORD **)(a2 + 48));
}


// ===== ?dtor$1@?0???0_Locinfo@std@@QEAA@PEBD@Z@4HA_0 @ 0x180019550 size=0x10 =====
void __fastcall `std::_Locinfo::_Locinfo'::`1'::dtor$1(__int64 a1, __int64 a2)
{
  sub_1800022F0(*(_QWORD *)(a2 + 48) + 8LL);
}


// ===== sub_180019560 @ 0x180019560 size=0x10 =====
void __fastcall sub_180019560(__int64 a1, __int64 a2)
{
  sub_180002480(*(_QWORD *)(a2 + 56) + 8LL);
}


// ===== sub_180019570 @ 0x180019570 size=0xc =====
__int64 __fastcall sub_180019570(__int64 a1, __int64 a2)
{
  return sub_1800023E0(a2 + 96);
}


// ===== sub_180019580 @ 0x180019580 size=0xc =====
void __fastcall sub_180019580(__int64 a1, __int64 a2)
{
  sub_1800025F0(a2 + 40);
}


// ===== ?dtor$0@?0??_wcrtomb_s_l@@YAHQEAHQEAD_K_WQEAU_Mbstatet@@QEAU__crt_locale_pointers@@@Z@4HA @ 0x180019590 size=0xc =====
void __fastcall `_wcrtomb_s_l'::`1'::dtor$0(__int64 a1, __int64 a2)
{
  sub_180002290((_QWORD **)(a2 + 80));
}


// ===== ?dtor$0@?0??_wcstombs_l_helper@@YA_KPEADPEB_W_KPEAU__crt_locale_pointers@@@Z@4HA @ 0x1800195a0 size=0xc =====
// Microsoft VisualC v14 64bit runtime
void __fastcall `_wcstombs_l_helper'::`1'::dtor$0(__int64 a1, __int64 a2)
{
  sub_180002290((_QWORD **)(a2 + 88));
}


// ===== unknown_libname_9 @ 0x1800195b0 size=0xc =====
// Microsoft VisualC v7/14 64bit runtime
__int64 __fastcall unknown_libname_9(__int64 a1, __int64 a2)
{
  return sub_180002610(a2 + 72);
}


// ===== __std_tzdb_get_leap_seconds$catch$0 @ 0x1800195c0 size=0x1b =====
// positive sp value has been detected, the output may be wrong!
void *_std_tzdb_get_leap_seconds_catch_0()
{
  return &loc_180004335;
}


// ===== sub_1800195E0 @ 0x1800195e0 size=0xc =====
void __fastcall sub_1800195E0(__int64 a1, __int64 a2)
{
  sub_180002290((_QWORD **)(a2 + 96));
}


// ===== sub_1800195F0 @ 0x1800195f0 size=0xc =====
__int64 __fastcall sub_1800195F0(__int64 a1, __int64 a2)
{
  return sub_180002610(a2 + 104);
}


// ===== unknown_libname_37 @ 0x180019600 size=0xc =====
// Microsoft VisualC v14 64bit runtime
__int64 __fastcall unknown_libname_37(__int64 a1, __int64 a2)
{
  return sub_180002610(a2 + 152);
}


// ===== ?dtor$0@?0??do_put@?$money_put@_WV?$ostreambuf_iterator@_WU?$char_traits@_W@std@@@std@@@std@@MEBA?AV?$ostreambuf_iterator@_WU?$char_traits@_W@std@@@2@V32@_NAEAVios_base@2@_WO@Z@4HA @ 0x180019610 size=0xc =====
__int64 __fastcall `std::money_put<wchar_t,std::ostreambuf_iterator<wchar_t>>::do_put'::`1'::dtor$0(
        __int64 a1,
        __int64 a2)
{
  return sub_180002610(a2 + 176);
}


// ===== sub_180019620 @ 0x180019620 size=0xc =====
__int64 __fastcall sub_180019620(__int64 a1, __int64 a2)
{
  return sub_180002610(a2 + 200);
}


// ===== sub_180019630 @ 0x180019630 size=0xc =====
__int64 __fastcall sub_180019630(__int64 a1, __int64 a2)
{
  return sub_180002610(a2 + 224);
}


// ===== sub_180019640 @ 0x180019640 size=0xc =====
__int64 sub_180019640()
{
  return sub_1800026C0();
}


// ===== sub_180019650 @ 0x180019650 size=0xc =====
void __fastcall sub_180019650(__int64 a1, __int64 a2)
{
  sub_180002640((_QWORD *)(a2 + 48));
}


// ===== sub_180019660 @ 0x180019660 size=0x10 =====
void __fastcall sub_180019660(__int64 a1, __int64 a2)
{
  sub_180002590(a2 + 56);
}


// ===== sub_180019670 @ 0x180019670 size=0xc =====
void __fastcall sub_180019670(__int64 a1, __int64 a2)
{
  sub_180002330(*(_QWORD *)(a2 + 88));
}


// ===== sub_180019680 @ 0x180019680 size=0x2a =====
void __fastcall __noreturn sub_180019680(__int64 a1, __int64 a2)
{
  sub_180005950(*(_QWORD *)(a2 + 64), *(void **)(a2 + 88), 1);
  throw;
}


// ===== sub_1800196B0 @ 0x1800196b0 size=0xc =====
void __fastcall sub_1800196B0(__int64 a1, __int64 a2)
{
  sub_180005B80(*(void ***)(a2 + 64));
}


// ===== ?dtor$1@?0??message@_Iostream_error_category@std@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@H@Z@4HA @ 0x1800196c0 size=0xc =====
void __fastcall `std::_Iostream_error_category::message'::`1'::dtor$1(__int64 a1, __int64 a2)
{
  sub_180005B50(*(void ***)(a2 + 72));
}


// ===== ?dtor$2@?0??message@_Iostream_error_category@std@@UEBA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@H@Z@4HA @ 0x1800196d0 size=0xc =====
void __fastcall `std::_Iostream_error_category::message'::`1'::dtor$2(__int64 a1, __int64 a2)
{
  sub_180002390(*(void ***)(a2 + 72));
}


// ===== sub_1800196E0 @ 0x1800196e0 size=0xc =====
void __fastcall sub_1800196E0(__int64 a1, __int64 a2)
{
  sub_180005B50(*(void ***)(a2 + 64));
}


// ===== sub_1800196F0 @ 0x1800196f0 size=0x2a =====
void __fastcall __noreturn sub_1800196F0(__int64 a1, __int64 a2)
{
  sub_180005950(*(_QWORD *)(a2 + 64), *(void **)(a2 + 72), 1);
  throw;
}


// ===== ?dtor$0@?0??AllocateScheduleGroup@SchedulingRing@details@Concurrency@@QEAAPEAVScheduleGroupBase@23@XZ@4HA_0 @ 0x180019720 size=0xc =====
__int64 __fastcall `Concurrency::details::SchedulingRing::AllocateScheduleGroup'::`1'::dtor$0(__int64 a1, __int64 a2)
{
  return sub_180006340(*(_QWORD *)(a2 + 64));
}


// ===== ?dtor$1@?0??AllocateScheduleGroup@SchedulingRing@details@Concurrency@@QEAAPEAVScheduleGroupBase@23@XZ@4HA_0 @ 0x180019730 size=0xc =====
void __fastcall `Concurrency::details::SchedulingRing::AllocateScheduleGroup'::`1'::dtor$1(__int64 a1, __int64 a2)
{
  sub_1800063D0(*(_QWORD *)(a2 + 64));
}


// ===== ?dtor$0@?0??AllocateScheduleGroup@SchedulingRing@details@Concurrency@@QEAAPEAVScheduleGroupBase@23@XZ@4HA_1 @ 0x180019740 size=0xc =====
__int64 __fastcall `Concurrency::details::SchedulingRing::AllocateScheduleGroup'::`1'::dtor$0(__int64 a1, __int64 a2)
{
  __int64 v2; // rcx
  __int64 result; // rax

  v2 = **(_QWORD **)(a2 + 64);
  if ( v2 != 0 )
    return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 16LL))(v2);
  return result;
}


// ===== ?dtor$1@?0??AllocateScheduleGroup@SchedulingRing@details@Concurrency@@QEAAPEAVScheduleGroupBase@23@XZ@4HA_1 @ 0x180019750 size=0xc =====
__int64 __fastcall `Concurrency::details::SchedulingRing::AllocateScheduleGroup'::`1'::dtor$1(__int64 a1, __int64 a2)
{
  return sub_1800062E0(*(_QWORD *)(a2 + 64));
}


// ===== sub_180019760 @ 0x180019760 size=0xc =====
__int64 sub_180019760()
{
  return sub_1800062E0((__int64)&qword_18002A1A0);
}


// ===== sub_180019770 @ 0x180019770 size=0xc =====
__int64 sub_180019770()
{
  return sub_180006340((__int64)&qword_18002A1A0);
}


// ===== sub_180019780 @ 0x180019780 size=0xc =====
void sub_180019780()
{
  sub_1800063D0((__int64)&qword_18002A1A0);
}


// ===== sub_180019790 @ 0x180019790 size=0xc =====
__int64 __fastcall sub_180019790(__int64 a1, __int64 a2)
{
  return sub_180006480(a2 + 48);
}


// ===== sub_1800197A0 @ 0x1800197a0 size=0xc =====
__int64 __fastcall sub_1800197A0(__int64 a1, __int64 a2)
{
  return sub_180006390((__int64 *)(a2 + 112));
}


// ===== sub_1800197B0 @ 0x1800197b0 size=0xc =====
__int64 __fastcall sub_1800197B0(__int64 a1, __int64 a2)
{
  __int64 v2; // rcx
  __int64 result; // rax

  v2 = *(_QWORD *)(a2 + 112);
  if ( v2 != 0 )
    return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 16LL))(v2);
  return result;
}


// ===== sub_1800197C0 @ 0x1800197c0 size=0xc =====
void __fastcall sub_1800197C0(__int64 a1, __int64 a2)
{
  sub_180002290((_QWORD **)(a2 + 40));
}


// ===== sub_1800197D0 @ 0x1800197d0 size=0xc =====
__int64 __fastcall sub_1800197D0(__int64 a1, __int64 a2)
{
  return sub_180006390((__int64 *)(a2 + 104));
}


// ===== sub_1800197E0 @ 0x1800197e0 size=0xc =====
void __fastcall sub_1800197E0(__int64 a1, __int64 a2)
{
  sub_180002290((_QWORD **)(a2 + 168));
}


// ===== sub_1800197F0 @ 0x1800197f0 size=0xc =====
__int64 __fastcall sub_1800197F0(__int64 a1, __int64 a2)
{
  return sub_180002610(a2 + 136);
}


// ===== sub_180019800 @ 0x180019800 size=0xc =====
__int64 __fastcall sub_180019800(__int64 a1, __int64 a2)
{
  return sub_180002610(a2 + 112);
}


// ===== ?dtor$0@?0??_Getifld@?$num_get@DV?$istreambuf_iterator@DU?$char_traits@D@std@@@std@@@std@@AEBAHPEADAEAV?$istreambuf_iterator@DU?$char_traits@D@std@@@2@1HAEBVlocale@2@@Z@4HA @ 0x180019810 size=0xc =====
__int64 __fastcall `std::num_get<char,std::istreambuf_iterator<char>>::_Getifld'::`1'::dtor$0(__int64 a1, __int64 a2)
{
  __int64 v2; // rcx
  __int64 result; // rax

  v2 = *(_QWORD *)(a2 + 104);
  if ( v2 != 0 )
    return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 16LL))(v2);
  return result;
}


// ===== ?dtor$1@?0??_Getifld@?$num_get@DV?$istreambuf_iterator@DU?$char_traits@D@std@@@std@@@std@@AEBAHPEADAEAV?$istreambuf_iterator@DU?$char_traits@D@std@@@2@1HAEBVlocale@2@@Z@4HA @ 0x180019820 size=0xc =====
__int64 __fastcall `std::num_get<char,std::istreambuf_iterator<char>>::_Getifld'::`1'::dtor$1(__int64 a1, __int64 a2)
{
  return sub_180006480(a2 + 64);
}


// ===== unknown_libname_10 @ 0x180019830 size=0xc =====
// Microsoft VisualC v7/14 64bit runtime
__int64 __fastcall unknown_libname_10(__int64 a1, __int64 a2)
{
  return sub_180006390((__int64 *)(a2 + 56));
}


// ===== unknown_libname_11 @ 0x180019840 size=0xc =====
// Microsoft VisualC v7/14 64bit runtime
__int64 __fastcall unknown_libname_11(__int64 a1, __int64 a2)
{
  __int64 v2; // rcx
  __int64 result; // rax

  v2 = *(_QWORD *)(a2 + 56);
  if ( v2 != 0 )
    return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 16LL))(v2);
  return result;
}


// ===== sub_180019850 @ 0x180019850 size=0xc =====
void __fastcall sub_180019850(__int64 a1, __int64 a2)
{
  sub_180006360(a2 + 40);
}


// ===== unknown_libname_38 @ 0x18001985c size=0x1b =====
// Microsoft VisualC v7/14 64bit runtime
// Microsoft VisualC v14 64bit runtime
void *unknown_libname_38()
{
  return &loc_1800079F1;
}


// ===== sub_180019C50 @ 0x180019c50 size=0x8e =====
void __fastcall sub_180019C50()
{
  unsigned __int64 v0; // rdx
  unsigned __int64 i; // rbx
  PVOID *v2; // rdi
  PVOID v3; // rax

  if ( dword_18002A200 != 0 )
  {
    v0 = qword_18002A218;
    for ( i = qword_18002A210; i < v0; i += 8LL )
    {
      if ( *(_QWORD *)i != 0 )
      {
        v2 = *(PVOID **)(*(_QWORD *)i + 32LL);
        if ( *v2 != nullptr )
        {
          v3 = DecodePointer(*v2);
          (*(void (__fastcall **)(PVOID))(*(_QWORD *)v3 + 16LL))(v3);
          *v2 = nullptr;
          v0 = qword_18002A218;
        }
      }
    }
    DeleteCriticalSection(&CriticalSection);
    dword_18002A200 = 0;
  }
}


// ===== sub_180019CE0 @ 0x180019ce0 size=0x50 =====
void __fastcall sub_180019CE0()
{
  unsigned __int64 v0; // rbx
  unsigned __int64 i; // rcx

  __wind
  {
    v0 = qword_18002A210;
    for ( i = qword_18002A218; v0 < i; v0 += 8LL )
    {
      if ( *(_QWORD *)v0 != 0 )
      {
        (*(void (__fastcall **)(_QWORD))(*(_QWORD *)v0 + 56LL))(0);
        i = qword_18002A218;
      }
    }
  }
  __unwind
  {
    sub_180006340((__int64)&qword_18002A1A0);
  }
  sub_1800063D0((__int64)&qword_18002A1A0);
}



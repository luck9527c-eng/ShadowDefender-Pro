// ===== sub_140001000 @ 0x140001000 =====

0x140001000  lea     rax, unk_14001DBB0
0x140001007  retn

// ===== WinMain @ 0x140001010 =====

0x140001010  mov     [rsp+arg_8], rbx
0x140001015  mov     [rsp+arg_18], rsi
0x14000101a  push    rdi
0x14000101b  sub     rsp, 300h
0x140001022  mov     rax, cs:__security_cookie
0x140001029  xor     rax, rsp
0x14000102c  mov     [rsp+308h+var_18], rax
0x140001034  lea     rax, sub_140001350
0x14000103b  xor     edi, edi
0x14000103d  lea     rsi, ServiceName; "{0CBD4F48-3751-475D-BE88-4F271385B672}"
0x140001044  mov     [rsp+308h+ServiceStartTable.lpServiceProc], rax
0x140001049  lea     rdx, aInstall; "/install"
0x140001050  mov     [rsp+308h+ServiceStartTable.lpServiceName], rsi
0x140001055  mov     rcx, r8; String1
0x140001058  mov     [rsp+308h+var_288], rdi
0x140001060  mov     [rsp+308h+var_280], rdi
0x140001068  mov     rbx, r8
0x14000106b  call    _wcsicmp
0x140001070  test    eax, eax
0x140001072  jnz     loc_1400011B4
0x140001078  xor     edx, edx
0x14000107a  mov     [rsp+308h+arg_0], rbp
0x140001082  mov     r8d, 208h
0x140001088  lea     rcx, [rsp+308h+Filename]
0x140001090  call    sub_140002F60
0x140001095  mov     r8d, 104h; nSize
0x14000109b  lea     rdx, [rsp+308h+Filename]; lpFilename
0x1400010a3  xor     ecx, ecx; hModule
0x1400010a5  call    cs:GetModuleFileNameW; KERNEL32
0x1400010ab  xor     edx, edx; lpDatabaseName
0x1400010ad  xor     ecx, ecx; lpMachineName
0x1400010af  mov     r8d, 0F003Fh; dwDesiredAccess
0x1400010b5  call    cs:OpenSCManagerW; ADVAPI32
0x1400010bb  lea     rbp, pszValue
0x1400010c2  mov     rbx, rax
0x1400010c5  test    rax, rax
0x1400010c8  jz      short loc_140001134
0x1400010ca  mov     [rsp+308h+lpPassword], rdi; lpPassword
0x1400010cf  lea     rax, [rsp+308h+Filename]
0x1400010d7  mov     [rsp+308h+lpServiceStartName], rdi; lpServiceStartName
0x1400010dc  lea     r8, DisplayName; "Shadow Defender Service"
0x1400010e3  mov     [rsp+308h+lpDependencies], rbp; lpDependencies
0x1400010e8  mov     r9d, 0F01FFh; dwDesiredAccess
0x1400010ee  mov     [rsp+308h+lpdwTagId], rdi; lpdwTagId
0x1400010f3  mov     rdx, rsi; lpServiceName
0x1400010f6  mov     [rsp+308h+lpLoadOrderGroup], rdi; lpLoadOrderGroup
0x1400010fb  mov     rcx, rbx; hSCManager
0x1400010fe  mov     [rsp+308h+lpBinaryPathName], rax; lpBinaryPathName
0x140001103  mov     [rsp+308h+dwErrorControl], edi; dwErrorControl
0x140001107  mov     [rsp+308h+dwStartType], 2; dwStartType
0x14000110f  mov     [rsp+308h+dwServiceType], 10h; dwServiceType
0x140001117  call    cs:CreateServiceW; ADVAPI32
0x14000111d  test    rax, rax
0x140001120  jz      short loc_14000112B
0x140001122  mov     rcx, rax; hSCObject
0x140001125  call    cs:CloseServiceHandle; ADVAPI32
0x14000112b  mov     rcx, rbx; hSCObject
0x14000112e  call    cs:CloseServiceHandle; ADVAPI32
0x140001134  movups  xmm0, cs:xmmword_1400191C0
0x14000113b  lea     rax, [rsp+308h+pvData]
0x140001143  mov     [rsp+308h+dwStartType], 10h; cbData
0x14000114b  mov     r9d, 1; dwType
0x140001151  mov     qword ptr [rsp+308h+dwServiceType], rax; pvData
0x140001156  mov     r8, rbp; pszValue
0x140001159  lea     rdx, pszSubKey; "SYSTEM\\CurrentControlSet\\Control\\Saf"...
0x140001160  mov     rcx, 0FFFFFFFF80000002h; hkey
0x140001167  movups  [rsp+308h+pvData], xmm0
0x14000116f  call    cs:SHSetValueW; SHLWAPI
0x140001175  lea     rax, [rsp+308h+pvData]
0x14000117d  mov     [rsp+308h+dwStartType], 10h; cbData
0x140001185  mov     r9d, 1; dwType
0x14000118b  mov     qword ptr [rsp+308h+dwServiceType], rax; pvData
0x140001190  mov     r8, rbp; pszValue
0x140001193  lea     rdx, aSystemCurrentc_0; "SYSTEM\\CurrentControlSet\\Control\\Saf"...
0x14000119a  mov     rcx, 0FFFFFFFF80000002h; hkey
0x1400011a1  call    cs:SHSetValueW; SHLWAPI
0x1400011a7  mov     rbp, [rsp+308h+arg_0]
0x1400011af  jmp     loc_140001328
0x1400011b4  lea     rdx, aUninstall; "/uninstall"
0x1400011bb  mov     rcx, rbx; String1
0x1400011be  call    _wcsicmp
0x1400011c3  test    eax, eax
0x1400011c5  jnz     short loc_140001243
0x1400011c7  xor     edx, edx; lpDatabaseName
0x1400011c9  xor     ecx, ecx; lpMachineName
0x1400011cb  mov     r8d, 0F003Fh; dwDesiredAccess
0x1400011d1  call    cs:OpenSCManagerW; ADVAPI32
0x1400011d7  mov     rbx, rax
0x1400011da  test    rax, rax
0x1400011dd  jz      short loc_14000122A
0x1400011df  mov     r8d, 10000h; dwDesiredAccess
0x1400011e5  mov     rdx, rsi; lpServiceName
0x1400011e8  mov     rcx, rax; hSCManager
0x1400011eb  call    cs:OpenServiceW; ADVAPI32
0x1400011f1  mov     rdi, rax
0x1400011f4  test    rax, rax
0x1400011f7  jz      short loc_140001221
0x1400011f9  lea     r8, [rsp+308h+pvData]; lpServiceStatus
0x140001201  mov     edx, 1; dwControl
0x140001206  mov     rcx, rbx; hService
0x140001209  call    cs:ControlService; ADVAPI32
0x14000120f  mov     rcx, rdi; hService
0x140001212  call    cs:DeleteService; ADVAPI32
0x140001218  mov     rcx, rdi; hSCObject
0x14000121b  call    cs:CloseServiceHandle; ADVAPI32
0x140001221  mov     rcx, rbx; hSCObject
0x140001224  call    cs:CloseServiceHandle; ADVAPI32
0x14000122a  lea     rdx, pszSubKey; "SYSTEM\\CurrentControlSet\\Control\\Saf"...
0x140001231  mov     rcx, 0FFFFFFFF80000002h; hkey
0x140001238  call    cs:SHDeleteKeyW; SHLWAPI
0x14000123e  jmp     loc_140001328
0x140001243  mov     edx, 1; dwRevision
0x140001248  lea     rcx, [rsp+308h+pSecurityDescriptor]; pSecurityDescriptor
0x140001250  call    cs:InitializeSecurityDescriptor; ADVAPI32
0x140001256  xor     r9d, r9d; bDaclDefaulted
0x140001259  lea     rcx, [rsp+308h+pSecurityDescriptor]; pSecurityDescriptor
0x140001261  xor     r8d, r8d; pDacl
0x140001264  lea     edx, [r9+1]; bDaclPresent
0x140001268  call    cs:SetSecurityDescriptorDacl; ADVAPI32
0x14000126e  xor     r8d, r8d; bInitialState
0x140001271  mov     dword ptr [rsp+308h+pvData], 18h
0x14000127c  lea     rax, [rsp+308h+pSecurityDescriptor]
0x140001284  mov     [rsp+308h+var_240], edi
0x14000128b  lea     r9, Name; "Global\\{C6F6A26F-B5C2-4284-9AB3-767CB9"...
0x140001292  mov     qword ptr [rsp+308h+pvData+8], rax
0x14000129a  lea     rcx, [rsp+308h+pvData]; lpEventAttributes
0x1400012a2  lea     edx, [r8+1]; bManualReset
0x1400012a6  call    cs:CreateEventW; KERNEL32
0x1400012ac  xor     r9d, r9d; lpParameter
0x1400012af  mov     qword ptr [rsp+308h+dwStartType], rdi; lpThreadId
0x1400012b4  lea     r8, StartAddress; lpStartAddress
0x1400012bb  mov     cs:hEvent, rax
0x1400012c2  xor     edx, edx; dwStackSize
0x1400012c4  mov     [rsp+308h+dwServiceType], edi; dwCreationFlags
0x1400012c8  xor     ecx, ecx; lpThreadAttributes
0x1400012ca  call    cs:CreateThread; KERNEL32
0x1400012d0  lea     rcx, [rsp+308h+ServiceStartTable]; lpServiceStartTable
0x1400012d5  mov     cs:hObject, rax
0x1400012dc  call    cs:StartServiceCtrlDispatcherW; ADVAPI32
0x1400012e2  test    eax, eax
0x1400012e4  jnz     short loc_140001328
0x1400012e6  mov     rcx, cs:hObject; hHandle
0x1400012ed  mov     edx, 0FFFFFFFFh; dwMilliseconds
0x1400012f2  call    cs:WaitForSingleObject; KERNEL32
0x1400012f8  mov     rcx, cs:hObject; hObject
0x1400012ff  call    cs:CloseHandle; KERNEL32
0x140001305  mov     rcx, cs:hEvent; hObject
0x14000130c  mov     cs:hObject, 0FFFFFFFFFFFFFFFFh
0x140001317  call    cs:CloseHandle; KERNEL32
0x14000131d  mov     cs:hEvent, 0FFFFFFFFFFFFFFFFh
0x140001328  xor     eax, eax
0x14000132a  mov     rcx, [rsp+308h+var_18]
0x140001332  xor     rcx, rsp; StackCookie
0x140001335  call    __security_check_cookie
0x14000133a  lea     r11, [rsp+308h+var_8]
0x140001342  mov     rbx, [r11+18h]
0x140001346  mov     rsi, [r11+28h]
0x14000134a  mov     rsp, r11
0x14000134d  pop     rdi
0x14000134e  retn

// ===== sub_140001350 @ 0x140001350 =====

0x140001350  sub     rsp, 58h
0x140001354  mov     rax, cs:__security_cookie
0x14000135b  xor     rax, rsp
0x14000135e  mov     [rsp+58h+var_18], rax
0x140001363  xor     r8d, r8d; lpContext
0x140001366  lea     rdx, HandlerProc; lpHandlerProc
0x14000136d  lea     rcx, ServiceName; "{0CBD4F48-3751-475D-BE88-4F271385B672}"
0x140001374  call    cs:RegisterServiceCtrlHandlerExW; ADVAPI32
0x14000137a  mov     cs:hServiceStatus, rax
0x140001381  test    rax, rax
0x140001384  jz      loc_140001459
0x14000138a  mov     ecx, cs:dword_14001DBC0
0x140001390  lea     rdx, ServiceStatus; lpServiceStatus
0x140001397  mov     cs:ServiceStatus.dwCheckPoint, ecx
0x14000139d  inc     ecx
0x14000139f  mov     cs:dword_14001DBC0, ecx
0x1400013a5  mov     rcx, rax; hServiceStatus
0x1400013a8  mov     [rsp+58h+var_8], rbx
0x1400013ad  xor     ebx, ebx
0x1400013af  mov     cs:ServiceStatus.dwServiceType, 10h
0x1400013b9  mov     qword ptr cs:ServiceStatus.dwWin32ExitCode, rbx
0x1400013c0  mov     cs:ServiceStatus.dwCurrentState, 2
0x1400013ca  mov     cs:ServiceStatus.dwWaitHint, 0EA60h
0x1400013d4  mov     cs:ServiceStatus.dwControlsAccepted, 81h
0x1400013de  call    cs:SetServiceStatus; ADVAPI32
0x1400013e4  movups  xmm0, cs:xmmword_1400113F0
0x1400013eb  mov     rcx, cs:hServiceStatus; hRecipient
0x1400013f2  lea     r8d, [rbx+1]; Flags
0x1400013f6  lea     rdx, [rsp+58h+NotificationFilter]; NotificationFilter
0x1400013fb  mov     [rsp+58h+var_34], 5
0x140001404  movups  [rsp+58h+var_2C], xmm0
0x140001409  mov     [rsp+58h+var_1C], ebx
0x14000140d  mov     [rsp+58h+NotificationFilter], 20h ; ' '
0x140001415  call    cs:RegisterDeviceNotificationW; USER32
0x14000141b  mov     rcx, cs:hServiceStatus; hServiceStatus
0x140001422  lea     rdx, ServiceStatus; lpServiceStatus
0x140001429  mov     cs:ServiceStatus.dwCurrentState, 4
0x140001433  mov     qword ptr cs:ServiceStatus.dwControlsAccepted, 81h
0x14000143e  mov     cs:ServiceStatus.dwWaitHint, 0EA60h
0x140001448  mov     cs:ServiceStatus.dwCheckPoint, ebx
0x14000144e  call    cs:SetServiceStatus; ADVAPI32
0x140001454  mov     rbx, [rsp+58h+var_8]
0x140001459  mov     rcx, [rsp+58h+var_18]
0x14000145e  xor     rcx, rsp; StackCookie
0x140001461  call    __security_check_cookie
0x140001466  add     rsp, 58h
0x14000146a  retn

// ===== HandlerProc @ 0x140001470 =====

0x140001470  mov     rax, rsp
0x140001473  push    rsi
0x140001474  sub     rsp, 0D0h
0x14000147b  xor     esi, esi
0x14000147d  mov     [rax+10h], rbx
0x140001481  mov     [rax+18h], rdi
0x140001485  mov     rdi, r8
0x140001488  sub     ecx, 1
0x14000148b  jz      loc_1400015EE
0x140001491  sub     ecx, 2
0x140001494  jz      loc_1400015E2
0x14000149a  sub     ecx, 8
0x14000149d  jz      loc_14000158E
0x1400014a3  cmp     ecx, 3
0x1400014a6  jnz     loc_140001628
0x1400014ac  cmp     cs:dword_14001DBBC, esi
0x1400014b2  jnz     loc_140001628
0x1400014b8  mov     [rsp+0D8h+hTemplateFile], rsi; hTemplateFile
0x1400014bd  lea     edx, [rcx+7Dh]; dwDesiredAccess
0x1400014c0  mov     r8d, ecx; dwShareMode
0x1400014c3  mov     [rsp+0D8h+dwFlagsAndAttributes], 80h; dwFlagsAndAttributes
0x1400014cb  mov     [rsp+0D8h+dwCreationDisposition], ecx; dwCreationDisposition
0x1400014cf  xor     r9d, r9d; lpSecurityAttributes
0x1400014d2  lea     rcx, FileName; "\\\\.\\DpControl"
0x1400014d9  call    cs:CreateFileW; KERNEL32
0x1400014df  mov     rdi, rax
0x1400014e2  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x1400014e6  jz      loc_14000157F
0x1400014ec  xor     edx, edx
0x1400014ee  lea     rcx, [rsp+0D8h+var_94]
0x1400014f3  mov     r8d, 84h
0x1400014f9  call    sub_140002F60
0x1400014fe  mov     [rsp+0D8h+lpOverlapped], rsi; lpOverlapped
0x140001503  lea     rax, [rsp+0D8h+BytesReturned]
0x14000150b  mov     [rsp+0D8h+hTemplateFile], rax; lpBytesReturned
0x140001510  lea     r8, [rsp+0D8h+OutBuffer]; lpInBuffer
0x140001515  lea     rax, [rsp+0D8h+OutBuffer]
0x14000151a  mov     [rsp+0D8h+dwFlagsAndAttributes], 88h; nOutBufferSize
0x140001522  mov     r9d, 88h; nInBufferSize
0x140001528  mov     qword ptr [rsp+0D8h+dwCreationDisposition], rax; lpOutBuffer
0x14000152d  mov     edx, 80000D18h; dwIoControlCode
0x140001532  mov     [rsp+0D8h+OutBuffer], 74706B64h
0x14000153a  mov     rcx, rdi; hDevice
0x14000153d  mov     [rsp+0D8h+BytesReturned], esi
0x140001544  call    cs:DeviceIoControl; KERNEL32
0x14000154a  test    eax, eax
0x14000154c  jnz     short loc_140001576
0x14000154e  call    cs:GetLastError; KERNEL32
0x140001554  mov     rcx, rdi; hObject
0x140001557  mov     ebx, eax
0x140001559  call    cs:CloseHandle; KERNEL32
0x14000155f  mov     ecx, ebx; dwErrCode
0x140001561  call    cs:SetLastError; KERNEL32
0x140001567  mov     cs:dword_14001DBBC, 1
0x140001571  jmp     loc_140001628
0x140001576  mov     rcx, rdi; hObject
0x140001579  call    cs:CloseHandle; KERNEL32
0x14000157f  mov     cs:dword_14001DBBC, 1
0x140001589  jmp     loc_140001628
0x14000158e  cmp     edx, 8000h
0x140001594  jnz     loc_140001628
0x14000159a  mov     eax, [r8+4]
0x14000159e  cmp     eax, 2
0x1400015a1  jnz     short loc_1400015D6
0x1400015a3  mov     ebx, 41h ; 'A'
0x1400015a8  nop     dword ptr [rax+rax+00000000h]
0x1400015b0  mov     ecx, esi
0x1400015b2  movzx   eax, bx
0x1400015b5  sub     eax, 41h ; 'A'
0x1400015b8  cmp     eax, 1
0x1400015bb  setnle  cl
0x1400015be  test    [rdi+0Ch], ecx
0x1400015c1  jz      short loc_1400015CB
0x1400015c3  movzx   ecx, bx
0x1400015c6  call    sub_1400018A0
0x1400015cb  inc     bx
0x1400015ce  cmp     bx, 5Ah ; 'Z'
0x1400015d2  jbe     short loc_1400015B0
0x1400015d4  jmp     short loc_140001628
0x1400015d6  cmp     eax, 5
0x1400015d9  jnz     short loc_140001628
0x1400015db  call    sub_140001A50
0x1400015e0  jmp     short loc_140001628
0x1400015e2  mov     cs:ServiceStatus.dwCurrentState, 4
0x1400015ec  jmp     short loc_140001628
0x1400015ee  mov     rcx, cs:hObject; hHandle
0x1400015f5  cmp     rcx, 0FFFFFFFFFFFFFFFFh
0x1400015f9  jz      short loc_14000161E
0x1400015fb  mov     edx, 0FFFFFFFFh; dwMilliseconds
0x140001600  call    cs:WaitForSingleObject; KERNEL32
0x140001606  mov     rcx, cs:hObject; hObject
0x14000160d  call    cs:CloseHandle; KERNEL32
0x140001613  mov     cs:hObject, 0FFFFFFFFFFFFFFFFh
0x14000161e  mov     cs:ServiceStatus.dwCurrentState, 1
0x140001628  mov     eax, cs:ServiceStatus.dwCurrentState
0x14000162e  mov     rdi, [rsp+0D8h+arg_10]
0x140001636  mov     rbx, [rsp+0D8h+arg_8]
0x14000163e  mov     qword ptr cs:ServiceStatus.dwControlsAccepted, 81h
0x140001649  mov     cs:ServiceStatus.dwWaitHint, 0BB8h
0x140001653  cmp     eax, 4
0x140001656  jz      short loc_140001673
0x140001658  cmp     eax, 1
0x14000165b  jz      short loc_140001673
0x14000165d  mov     eax, cs:dword_14001DBC0
0x140001663  mov     cs:ServiceStatus.dwCheckPoint, eax
0x140001669  inc     eax
0x14000166b  mov     cs:dword_14001DBC0, eax
0x140001671  jmp     short loc_140001679
0x140001673  mov     cs:ServiceStatus.dwCheckPoint, esi
0x140001679  mov     rcx, cs:hServiceStatus; hServiceStatus
0x140001680  lea     rdx, ServiceStatus; lpServiceStatus
0x140001687  call    cs:SetServiceStatus; ADVAPI32
0x14000168d  xor     eax, eax
0x14000168f  add     rsp, 0D0h
0x140001696  pop     rsi
0x140001697  retn

// ===== sub_1400016A0 @ 0x1400016a0 =====

0x1400016a0  mov     [rsp+arg_8], rbx
0x1400016a5  push    rdi
0x1400016a6  sub     rsp, 8C0h
0x1400016ad  mov     rax, cs:__security_cookie
0x1400016b4  xor     rax, rsp
0x1400016b7  mov     [rsp+8C8h+var_18], rax
0x1400016bf  mov     rdi, rcx
0x1400016c2  call    cs:RemoveDirectoryW; KERNEL32
0x1400016c8  test    eax, eax
0x1400016ca  jnz     short loc_1400016E2
0x1400016cc  call    cs:GetLastError; KERNEL32
0x1400016d2  cmp     eax, 91h
0x1400016d7  jz      short loc_1400016E2
0x1400016d9  cmp     eax, 20h ; ' '
0x1400016dc  jnz     loc_140001796
0x1400016e2  xor     edx, edx
0x1400016e4  lea     rcx, [rsp+8C8h+FindFileData]
0x1400016e9  mov     r8d, 250h
0x1400016ef  call    sub_140002F60
0x1400016f4  mov     r8, rdi; Source
0x1400016f7  lea     rcx, [rsp+8C8h+Destination]; Destination
0x1400016ff  mov     edx, 104h; SizeInWords
0x140001704  call    wcscpy_s
0x140001709  lea     rcx, [rsp+8C8h+Destination]
0x140001711  mov     rax, 0FFFFFFFFFFFFFFFFh
0x140001718  nop     dword ptr [rax+rax+00000000h]
0x140001720  cmp     word ptr [rcx+rax*2+2], 0
0x140001726  lea     rax, [rax+1]
0x14000172a  jnz     short loc_140001720
0x14000172c  movzx   ecx, [rsp+rax*2+8C8h+FindFileData.cAlternateFileName+1Ah]
0x140001734  cmp     cx, 5Ch ; '\'
0x140001738  jz      short loc_140001759
0x14000173a  cmp     cx, 2Fh ; '/'
0x14000173e  jz      short loc_140001759
0x140001740  lea     r8, Source; "\\"
0x140001747  mov     edx, 104h; SizeInWords
0x14000174c  lea     rcx, [rsp+8C8h+Destination]; Destination
0x140001754  call    wcscat_s
0x140001759  lea     r9, [rsp+8C8h+Destination]
0x140001761  mov     edx, 104h; BufferCount
0x140001766  lea     r8, aS; "%s*.*"
0x14000176d  lea     rcx, [rsp+8C8h+FileName]; Buffer
0x140001775  call    swprintf
0x14000177a  lea     rdx, [rsp+8C8h+FindFileData]; lpFindFileData
0x14000177f  lea     rcx, [rsp+8C8h+FileName]; lpFileName
0x140001787  call    cs:FindFirstFileW; KERNEL32
0x14000178d  mov     rbx, rax
0x140001790  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x140001794  jnz     short loc_1400017A0
0x140001796  xor     eax, eax
0x140001798  jmp     loc_140001875
0x1400017a0  lea     rax, [rsp+8C8h+FindFileData.cFileName]
0x1400017a5  mov     edx, 104h; BufferCount
0x1400017aa  lea     r9, [rsp+8C8h+Destination]
0x1400017b2  mov     [rsp+8C8h+var_8A8], rax
0x1400017b7  lea     r8, aSS; "%s%s"
0x1400017be  lea     rcx, [rsp+8C8h+PathName]; Buffer
0x1400017c6  call    swprintf
0x1400017cb  test    byte ptr [rsp+8C8h+FindFileData.dwFileAttributes], 10h
0x1400017d0  jz      short loc_14000181D
0x1400017d2  movzx   ecx, [rsp+8C8h+FindFileData.cFileName]
0x1400017d7  cmp     cx, cs:word_1400193CC
0x1400017de  movzx   eax, [rsp+8C8h+FindFileData.cFileName+2]
0x1400017e3  jnz     short loc_1400017EE
0x1400017e5  cmp     ax, cs:word_1400193CE
0x1400017ec  jz      short loc_14000183E
0x1400017ee  cmp     cx, cs:word_1400193D0
0x1400017f5  jnz     short loc_14000180E
0x1400017f7  cmp     ax, cs:word_1400193D2
0x1400017fe  jnz     short loc_14000180E
0x140001800  movzx   eax, [rsp+8C8h+FindFileData.cFileName+4]
0x140001805  cmp     ax, cs:word_1400193D4
0x14000180c  jz      short loc_14000183E
0x14000180e  lea     rcx, [rsp+8C8h+PathName]
0x140001816  call    sub_1400016A0
0x14000181b  jmp     short loc_14000183E
0x14000181d  mov     edx, 80h; dwFileAttributes
0x140001822  lea     rcx, [rsp+8C8h+PathName]; lpFileName
0x14000182a  call    cs:SetFileAttributesW; KERNEL32
0x140001830  lea     rcx, [rsp+8C8h+PathName]; lpFileName
0x140001838  call    cs:DeleteFileW; KERNEL32
0x14000183e  lea     rdx, [rsp+8C8h+FindFileData]; lpFindFileData
0x140001843  mov     rcx, rbx; hFindFile
0x140001846  call    cs:FindNextFileW; KERNEL32
0x14000184c  test    eax, eax
0x14000184e  jnz     loc_1400017A0
0x140001854  call    cs:GetLastError; KERNEL32
0x14000185a  cmp     eax, 12h
0x14000185d  jnz     loc_1400017A0
0x140001863  mov     rcx, rbx; hFindFile
0x140001866  call    cs:FindClose; KERNEL32
0x14000186c  mov     rcx, rdi; lpPathName
0x14000186f  call    cs:RemoveDirectoryW; KERNEL32
0x140001875  mov     rcx, [rsp+8C8h+var_18]
0x14000187d  xor     rcx, rsp; StackCookie
0x140001880  call    __security_check_cookie
0x140001885  mov     rbx, [rsp+8C8h+arg_8]
0x14000188d  add     rsp, 8C0h
0x140001894  pop     rdi
0x140001895  retn

// ===== sub_1400018A0 @ 0x1400018a0 =====

0x1400018a0  mov     [rsp+arg_8], rbx
0x1400018a5  push    rdi
0x1400018a6  sub     rsp, 500h
0x1400018ad  mov     rax, cs:__security_cookie
0x1400018b4  xor     rax, rsp
0x1400018b7  mov     [rsp+508h+var_18], rax
0x1400018bf  movzx   ebx, cx
0x1400018c2  xor     edx, edx
0x1400018c4  lea     rcx, [rsp+508h+FileName]
0x1400018cc  mov     r8d, 200h
0x1400018d2  call    sub_140002F60
0x1400018d7  mov     r9d, ebx
0x1400018da  lea     r8, aC; "\\\\.\\%C:"
0x1400018e1  mov     edx, 100h; BufferCount
0x1400018e6  lea     rcx, [rsp+508h+FileName]; Buffer
0x1400018ee  call    swprintf
0x1400018f3  xor     edx, edx
0x1400018f5  lea     rcx, [rsp+508h+Destination]
0x1400018fd  mov     r8d, 208h
0x140001903  call    sub_140002F60
0x140001908  lea     r8, [rsp+508h+FileName]; Source
0x140001910  mov     edx, 104h; SizeInWords
0x140001915  lea     rcx, [rsp+508h+Destination]; Destination
0x14000191d  call    wcscpy_s
0x140001922  lea     r8, a0d9db60eB0ea4d; "\\{0D9DB60E-B0EA-4d53-A392-A5D274956846"...
0x140001929  mov     edx, 104h; SizeInWords
0x14000192e  lea     rcx, [rsp+508h+Destination]; Destination
0x140001936  call    wcscat_s
0x14000193b  lea     rcx, [rsp+508h+Destination]
0x140001943  call    sub_1400016A0
0x140001948  xor     edi, edi
0x14000194a  lea     rcx, [rsp+508h+FileName]; lpFileName
0x140001952  mov     [rsp+508h+hTemplateFile], rdi; hTemplateFile
0x140001957  xor     r9d, r9d; lpSecurityAttributes
0x14000195a  mov     [rsp+508h+dwFlagsAndAttributes], edi; dwFlagsAndAttributes
0x14000195e  mov     edx, 80000000h; dwDesiredAccess
0x140001963  mov     [rsp+508h+dwCreationDisposition], 3; dwCreationDisposition
0x14000196b  lea     r8d, [rdi+3]; dwShareMode
0x14000196f  call    cs:CreateFileW; KERNEL32
0x140001975  mov     rbx, rax
0x140001978  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x14000197c  jz      loc_140001A2E
0x140001982  mov     [rsp+508h+lpOverlapped], rdi; lpOverlapped
0x140001987  lea     rax, [rsp+508h+BytesReturned]
0x14000198c  mov     [rsp+508h+hTemplateFile], rax; lpBytesReturned
0x140001991  lea     r8, [rsp+508h+OutBuffer]; lpInBuffer
0x140001996  lea     rax, [rsp+508h+OutBuffer]
0x14000199b  mov     [rsp+508h+dwFlagsAndAttributes], 88h; nOutBufferSize
0x1400019a3  mov     r9d, 88h; nInBufferSize
0x1400019a9  mov     qword ptr [rsp+508h+dwCreationDisposition], rax; lpOutBuffer
0x1400019ae  mov     edx, 80002D48h; dwIoControlCode
0x1400019b3  mov     [rsp+508h+BytesReturned], edi
0x1400019b7  mov     rcx, rbx; hDevice
0x1400019ba  call    cs:DeviceIoControl; KERNEL32
0x1400019c0  test    eax, eax
0x1400019c2  jnz     short loc_140001A25
0x1400019c4  call    cs:GetLastError; KERNEL32
0x1400019ca  cmp     eax, 20000001h
0x1400019cf  jz      short loc_140001A25
0x1400019d1  lea     r8, [rsp+508h+FileName]; Source
0x1400019d9  mov     edx, 104h; SizeInWords
0x1400019de  lea     rcx, [rsp+508h+Destination]; Destination
0x1400019e6  call    wcscpy_s
0x1400019eb  lea     r8, aDiskpt0Sys; "\\diskpt0.sys"
0x1400019f2  mov     edx, 104h; SizeInWords
0x1400019f7  lea     rcx, [rsp+508h+Destination]; Destination
0x1400019ff  call    wcscat_s
0x140001a04  mov     edx, 80h; dwFileAttributes
0x140001a09  lea     rcx, [rsp+508h+Destination]; lpFileName
0x140001a11  call    cs:SetFileAttributesW; KERNEL32
0x140001a17  lea     rcx, [rsp+508h+Destination]; lpFileName
0x140001a1f  call    cs:DeleteFileW; KERNEL32
0x140001a25  mov     rcx, rbx; hObject
0x140001a28  call    cs:CloseHandle; KERNEL32
0x140001a2e  mov     rcx, [rsp+508h+var_18]
0x140001a36  xor     rcx, rsp; StackCookie
0x140001a39  call    __security_check_cookie
0x140001a3e  mov     rbx, [rsp+508h+arg_8]
0x140001a46  add     rsp, 500h
0x140001a4d  pop     rdi
0x140001a4e  retn

// ===== sub_140001A50 @ 0x140001a50 =====

0x140001a50  mov     [rsp-8+arg_0], rbx
0x140001a55  mov     [rsp-8+arg_8], rsi
0x140001a5a  mov     [rsp-8+arg_10], rdi
0x140001a5f  mov     [rsp-8+arg_18], r12
0x140001a64  push    rbp
0x140001a65  push    r14
0x140001a67  push    r15
0x140001a69  lea     rbp, [rsp-480h]
0x140001a71  sub     rsp, 580h
0x140001a78  mov     rax, cs:__security_cookie
0x140001a7f  xor     rax, rsp
0x140001a82  mov     [rbp+490h+var_20], rax
0x140001a89  mov     edi, 5Ah ; 'Z'
0x140001a8e  mov     r15, 5C003A0020h
0x140001a98  xor     r14d, r14d
0x140001a9b  mov     esi, 0FFFFh
0x140001aa0  mov     r12, 5C003A0043h
0x140001aaa  nop     word ptr [rax+rax+00h]
0x140001ab0  mov     qword ptr [rsp+590h+RootPathName], r15
0x140001ab5  xor     ecx, ecx; dwErrCode
0x140001ab7  mov     [rsp+590h+RootPathName], di
0x140001abc  call    cs:SetLastError; KERNEL32
0x140001ac2  lea     rcx, [rsp+590h+RootPathName]; lpRootPathName
0x140001ac7  call    cs:GetDriveTypeW; KERNEL32
0x140001acd  add     eax, 0FFFFFFFEh
0x140001ad0  cmp     eax, 1
0x140001ad3  ja      loc_140001C34
0x140001ad9  call    cs:GetLastError; KERNEL32
0x140001adf  test    eax, eax
0x140001ae1  jnz     loc_140001C34
0x140001ae7  mov     [rsp+590h+nFileSystemNameSize], 10h; nFileSystemNameSize
0x140001aef  lea     rax, [rsp+590h+FileSystemNameBuffer]
0x140001af4  mov     [rsp+590h+lpFileSystemNameBuffer], rax; lpFileSystemNameBuffer
0x140001af9  lea     rcx, [rsp+590h+RootPathName]; lpRootPathName
0x140001afe  mov     [rsp+590h+lpFileSystemFlags], r14; lpFileSystemFlags
0x140001b03  xor     r9d, r9d; lpVolumeSerialNumber
0x140001b06  xor     r8d, r8d; nVolumeNameSize
0x140001b09  mov     [rsp+590h+lpMaximumComponentLength], r14; lpMaximumComponentLength
0x140001b0e  xor     edx, edx; lpVolumeNameBuffer
0x140001b10  call    cs:GetVolumeInformationW; KERNEL32
0x140001b16  test    eax, eax
0x140001b18  jz      loc_140001C34
0x140001b1e  lea     rdx, aFat; "FAT"
0x140001b25  lea     rcx, [rsp+590h+FileSystemNameBuffer]; String1
0x140001b2a  call    _wcsicmp
0x140001b2f  test    eax, eax
0x140001b31  jz      short loc_140001B8B
0x140001b33  lea     rdx, aFat32; "FAT32"
0x140001b3a  lea     rcx, [rsp+590h+FileSystemNameBuffer]; String1
0x140001b3f  call    _wcsicmp
0x140001b44  test    eax, eax
0x140001b46  jz      short loc_140001B8B
0x140001b48  lea     rdx, aFat16; "FAT16"
0x140001b4f  lea     rcx, [rsp+590h+FileSystemNameBuffer]; String1
0x140001b54  call    _wcsicmp
0x140001b59  test    eax, eax
0x140001b5b  jz      short loc_140001B8B
0x140001b5d  lea     rdx, aExfat; "EXFAT"
0x140001b64  lea     rcx, [rsp+590h+FileSystemNameBuffer]; String1
0x140001b69  call    _wcsicmp
0x140001b6e  test    eax, eax
0x140001b70  jz      short loc_140001B8B
0x140001b72  lea     rdx, aNtfs; "NTFS"
0x140001b79  lea     rcx, [rsp+590h+FileSystemNameBuffer]; String1
0x140001b7e  call    _wcsicmp
0x140001b83  test    eax, eax
0x140001b85  jnz     loc_140001C34
0x140001b8b  mov     qword ptr [rsp+590h+szVolumeMountPoint], r12
0x140001b90  lea     rdx, [rbp+490h+szVolumeName]; lpszVolumeName
0x140001b97  mov     r8d, 100h; cchBufferLength
0x140001b9d  mov     [rsp+590h+szVolumeMountPoint], di
0x140001ba2  lea     rcx, [rsp+590h+szVolumeMountPoint]; lpszVolumeMountPoint
0x140001ba7  call    cs:GetVolumeNameForVolumeMountPointW; KERNEL32
0x140001bad  test    eax, eax
0x140001baf  jz      loc_140001C34
0x140001bb5  mov     edx, 100h; cchBufferLength
0x140001bba  lea     rcx, [rbp+490h+String2]; lpszVolumeName
0x140001bbe  call    cs:FindFirstVolumeW; KERNEL32
0x140001bc4  mov     rbx, rax
0x140001bc7  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x140001bcb  jz      short loc_140001C34
0x140001bcd  nop     dword ptr [rax]
0x140001bd0  lea     rdx, [rbp+490h+String2]; String2
0x140001bd4  lea     rcx, [rbp+490h+szVolumeName]; String1
0x140001bdb  call    _wcsicmp
0x140001be0  mov     rcx, rbx; hFindVolume
0x140001be3  test    eax, eax
0x140001be5  jz      short loc_140001C06
0x140001be7  mov     r8d, 100h; cchBufferLength
0x140001bed  lea     rdx, [rbp+490h+String2]; lpszVolumeName
0x140001bf1  call    cs:FindNextVolumeW; KERNEL32
0x140001bf7  test    eax, eax
0x140001bf9  jnz     short loc_140001BD0
0x140001bfb  mov     rcx, rbx; hFindVolume
0x140001bfe  call    cs:FindVolumeClose; KERNEL32
0x140001c04  jmp     short loc_140001C34
0x140001c06  call    cs:FindVolumeClose; KERNEL32
0x140001c0c  movzx   r8d, di
0x140001c10  lea     rdx, aC_0; "!!! %C: =>.\n"
0x140001c17  lea     rcx, [rsp+590h+OutputString]; int
0x140001c1c  call    sub_140001FE0
0x140001c21  lea     rcx, [rsp+590h+OutputString]; lpOutputString
0x140001c26  call    cs:OutputDebugStringW; KERNEL32
0x140001c2c  movzx   ecx, di
0x140001c2f  call    sub_1400018A0
0x140001c34  add     di, si
0x140001c37  cmp     di, 43h ; 'C'
0x140001c3b  jnb     loc_140001AB0
0x140001c41  mov     rcx, [rbp+490h+var_20]
0x140001c48  xor     rcx, rsp; StackCookie
0x140001c4b  call    __security_check_cookie
0x140001c50  lea     r11, [rsp+590h+var_10]
0x140001c58  mov     rbx, [r11+20h]
0x140001c5c  mov     rsi, [r11+28h]
0x140001c60  mov     rdi, [r11+30h]
0x140001c64  mov     r12, [r11+38h]
0x140001c68  mov     rsp, r11
0x140001c6b  pop     r15
0x140001c6d  pop     r14
0x140001c6f  pop     rbp
0x140001c70  retn

// ===== sub_140001C80 @ 0x140001c80 =====

0x140001c80  mov     [rsp-8+arg_10], rbx
0x140001c85  push    rbp
0x140001c86  push    rsi
0x140001c87  push    rdi
0x140001c88  lea     rbp, [rsp-200h]
0x140001c90  sub     rsp, 300h
0x140001c97  mov     rax, cs:__security_cookie
0x140001c9e  xor     rax, rsp
0x140001ca1  mov     [rbp+210h+var_20], rax
0x140001ca8  call    cs:GetCurrentThread; KERNEL32
0x140001cae  mov     rcx, rax; hThread
0x140001cb1  mov     edx, 0Fh; nPriority
0x140001cb6  call    cs:SetThreadPriority; KERNEL32
0x140001cbc  mov     ecx, 2; uMode
0x140001cc1  call    cs:SetErrorMode; KERNEL32
0x140001cc7  mov     esi, eax
0x140001cc9  call    cs:GetLogicalDrives; KERNEL32
0x140001ccf  mov     r8d, 0FFFFh
0x140001cd5  mov     ebx, 5Ah ; 'Z'
0x140001cda  nop     word ptr [rax+rax+00h]
0x140001ce0  movzx   edi, bx
0x140001ce3  lea     ecx, [rdi-41h]
0x140001ce6  movzx   edx, cl
0x140001ce9  bt      eax, edx
0x140001cec  jnb     short loc_140001CFD
0x140001cee  add     bx, r8w
0x140001cf2  cmp     bx, 43h ; 'C'
0x140001cf6  jnb     short loc_140001CE0
0x140001cf8  jmp     loc_140001F64
0x140001cfd  cmp     bx, 3Fh ; '?'
0x140001d01  jz      loc_140001F64
0x140001d07  mov     [rsp+310h+arg_0], r14
0x140001d0f  lea     rax, [rsp+310h+var_2A8]
0x140001d14  mov     [rsp+310h+pcbData], rax; pcbData
0x140001d19  lea     r9, [rsp+310h+pdwType]; pdwType
0x140001d1e  mov     [rsp+310h+arg_8], r15
0x140001d26  lea     r8, aNodriveautorun; "NoDriveAutoRun"
0x140001d2d  lea     r15, dword_14001DBB8
0x140001d34  mov     [rsp+310h+pdwType], 4
0x140001d3c  xor     r14d, r14d
0x140001d3f  mov     [rsp+310h+pvData], r15; pvData
0x140001d44  lea     rdx, aSoftwareMicros; "Software\\Microsoft\\Windows\\CurrentVe"...
0x140001d4b  mov     [rsp+310h+var_2A8], 4
0x140001d53  mov     rcx, 0FFFFFFFF80000001h; hkey
0x140001d5a  mov     cs:dword_14001DBB8, r14d
0x140001d61  call    cs:SHGetValueW; SHLWAPI
0x140001d67  lea     rax, [rsp+310h+var_2A0]
0x140001d6c  mov     dword ptr [rsp+310h+pcbData], 4; cbData
0x140001d74  lea     r9d, [r14+4]; dwType
0x140001d78  mov     [rsp+310h+pvData], rax; pvData
0x140001d7d  lea     r8, aNodriveautorun; "NoDriveAutoRun"
0x140001d84  mov     [rsp+310h+var_2A0], 7FFFFFFh
0x140001d8c  lea     rdx, aSoftwareMicros; "Software\\Microsoft\\Windows\\CurrentVe"...
0x140001d93  mov     rcx, 0FFFFFFFF80000001h; hkey
0x140001d9a  call    cs:SHSetValueW; SHLWAPI
0x140001da0  xor     edx, edx
0x140001da2  lea     rcx, [rbp+210h+CommandLine]
0x140001da6  mov     r8d, 200h
0x140001dac  call    sub_140002F60
0x140001db1  mov     r9d, edi
0x140001db4  lea     r8, aMountvolCS; "mountvol %C: /s"
0x140001dbb  mov     edx, 100h; BufferCount
0x140001dc0  lea     rcx, [rbp+210h+CommandLine]; Buffer
0x140001dc4  call    swprintf
0x140001dc9  xor     edx, edx
0x140001dcb  lea     r8d, [r14+68h]
0x140001dcf  lea     rcx, [rbp+210h+StartupInfo]
0x140001dd3  call    sub_140002F60
0x140001dd8  xor     eax, eax
0x140001dda  mov     [rbp+210h+StartupInfo.cb], 68h ; 'h'
0x140001de1  mov     [rsp+310h+ProcessInformation.hProcess], rax
0x140001de6  lea     rdx, [rbp+210h+CommandLine]; lpCommandLine
0x140001dea  mov     [rsp+310h+ProcessInformation.hThread], rax
0x140001def  xor     r9d, r9d; lpThreadAttributes
0x140001df2  mov     qword ptr [rsp+310h+ProcessInformation.dwProcessId], rax
0x140001df7  xor     r8d, r8d; lpProcessAttributes
0x140001dfa  lea     rax, [rsp+310h+ProcessInformation]
0x140001dff  mov     [rbp+210h+StartupInfo.dwFlags], 1
0x140001e06  mov     [rsp+310h+lpProcessInformation], rax; lpProcessInformation
0x140001e0b  xor     ecx, ecx; lpApplicationName
0x140001e0d  lea     rax, [rbp+210h+StartupInfo]
0x140001e11  mov     [rbp+210h+StartupInfo.wShowWindow], r14w
0x140001e16  mov     [rsp+310h+lpStartupInfo], rax; lpStartupInfo
0x140001e1b  mov     [rsp+310h+lpCurrentDirectory], r14; lpCurrentDirectory
0x140001e20  mov     [rsp+310h+lpEnvironment], r14; lpEnvironment
0x140001e25  mov     dword ptr [rsp+310h+pcbData], r14d; dwCreationFlags
0x140001e2a  mov     dword ptr [rsp+310h+pvData], r14d; bInheritHandles
0x140001e2f  call    cs:CreateProcessW; KERNEL32
0x140001e35  test    eax, eax
0x140001e37  jz      short loc_140001E5F
0x140001e39  mov     rcx, [rsp+310h+ProcessInformation.hProcess]; hHandle
0x140001e3e  mov     edx, 0FFFFFFFFh; dwMilliseconds
0x140001e43  call    cs:WaitForSingleObject; KERNEL32
0x140001e49  mov     rcx, [rsp+310h+ProcessInformation.hThread]; hObject
0x140001e4e  call    cs:CloseHandle; KERNEL32
0x140001e54  mov     rcx, [rsp+310h+ProcessInformation.hProcess]; hObject
0x140001e59  call    cs:CloseHandle; KERNEL32
0x140001e5f  movzx   ecx, bx
0x140001e62  call    sub_1400018A0
0x140001e67  xor     edx, edx
0x140001e69  lea     rcx, [rbp+210h+CommandLine]
0x140001e6d  mov     r8d, 200h
0x140001e73  call    sub_140002F60
0x140001e78  mov     r9d, edi
0x140001e7b  lea     r8, aMountvolCD; "mountvol %C: /d"
0x140001e82  mov     edx, 100h; BufferCount
0x140001e87  lea     rcx, [rbp+210h+CommandLine]; Buffer
0x140001e8b  call    swprintf
0x140001e90  xor     edx, edx
0x140001e92  lea     rcx, [rbp+210h+StartupInfo]
0x140001e96  lea     r8d, [rdx+68h]
0x140001e9a  call    sub_140002F60
0x140001e9f  xor     eax, eax
0x140001ea1  mov     [rbp+210h+StartupInfo.cb], 68h ; 'h'
0x140001ea8  mov     [rsp+310h+ProcessInformation.hProcess], rax
0x140001ead  lea     rdx, [rbp+210h+CommandLine]; lpCommandLine
0x140001eb1  mov     [rsp+310h+ProcessInformation.hThread], rax
0x140001eb6  xor     r9d, r9d; lpThreadAttributes
0x140001eb9  mov     qword ptr [rsp+310h+ProcessInformation.dwProcessId], rax
0x140001ebe  xor     r8d, r8d; lpProcessAttributes
0x140001ec1  lea     rax, [rsp+310h+ProcessInformation]
0x140001ec6  mov     [rbp+210h+StartupInfo.dwFlags], 1
0x140001ecd  mov     [rsp+310h+lpProcessInformation], rax; lpProcessInformation
0x140001ed2  xor     ecx, ecx; lpApplicationName
0x140001ed4  lea     rax, [rbp+210h+StartupInfo]
0x140001ed8  mov     [rbp+210h+StartupInfo.wShowWindow], r14w
0x140001edd  mov     [rsp+310h+lpStartupInfo], rax; lpStartupInfo
0x140001ee2  mov     [rsp+310h+lpCurrentDirectory], r14; lpCurrentDirectory
0x140001ee7  mov     [rsp+310h+lpEnvironment], r14; lpEnvironment
0x140001eec  mov     dword ptr [rsp+310h+pcbData], r14d; dwCreationFlags
0x140001ef1  mov     dword ptr [rsp+310h+pvData], r14d; bInheritHandles
0x140001ef6  call    cs:CreateProcessW; KERNEL32
0x140001efc  mov     r14, [rsp+310h+arg_0]
0x140001f04  test    eax, eax
0x140001f06  jz      short loc_140001F2E
0x140001f08  mov     rcx, [rsp+310h+ProcessInformation.hProcess]; hHandle
0x140001f0d  mov     edx, 0FFFFFFFFh; dwMilliseconds
0x140001f12  call    cs:WaitForSingleObject; KERNEL32
0x140001f18  mov     rcx, [rsp+310h+ProcessInformation.hThread]; hObject
0x140001f1d  call    cs:CloseHandle; KERNEL32
0x140001f23  mov     rcx, [rsp+310h+ProcessInformation.hProcess]; hObject
0x140001f28  call    cs:CloseHandle; KERNEL32
0x140001f2e  mov     dword ptr [rsp+310h+pcbData], 4; cbData
0x140001f36  lea     r8, aNodriveautorun; "NoDriveAutoRun"
0x140001f3d  mov     r9d, 4; dwType
0x140001f43  mov     [rsp+310h+pvData], r15; pvData
0x140001f48  lea     rdx, aSoftwareMicros; "Software\\Microsoft\\Windows\\CurrentVe"...
0x140001f4f  mov     rcx, 0FFFFFFFF80000001h; hkey
0x140001f56  call    cs:SHSetValueW; SHLWAPI
0x140001f5c  mov     r15, [rsp+310h+arg_8]
0x140001f64  mov     ecx, esi; uMode
0x140001f66  call    cs:SetErrorMode; KERNEL32
0x140001f6c  mov     rcx, cs:hEvent; hEvent
0x140001f73  call    cs:SetEvent; KERNEL32
0x140001f79  mov     rcx, cs:hEvent; hObject
0x140001f80  call    cs:CloseHandle; KERNEL32
0x140001f86  mov     cs:hEvent, 0FFFFFFFFFFFFFFFFh
0x140001f91  mov     rcx, [rbp+210h+var_20]
0x140001f98  xor     rcx, rsp; StackCookie
0x140001f9b  call    __security_check_cookie
0x140001fa0  mov     rbx, [rsp+310h+arg_10]
0x140001fa8  add     rsp, 300h
0x140001faf  pop     rdi
0x140001fb0  pop     rsi
0x140001fb1  pop     rbp
0x140001fb2  retn

// ===== StartAddress @ 0x140001fc0 =====

0x140001fc0  sub     rsp, 28h
0x140001fc4  call    cs:GetTickCount; KERNEL32
0x140001fca  call    sub_140001C80
0x140001fcf  call    sub_140001A50
0x140001fd4  xor     eax, eax
0x140001fd6  add     rsp, 28h
0x140001fda  retn

// ===== sub_140001FE0 @ 0x140001fe0 =====

0x140001fe0  mov     [rsp+arg_8], rdx
0x140001fe5  mov     [rsp+arg_10], r8
0x140001fea  mov     [rsp+arg_18], r9
0x140001fef  push    rbx
0x140001ff0  push    rsi
0x140001ff1  push    rdi
0x140001ff2  sub     rsp, 30h
0x140001ff6  mov     rbx, rdx
0x140001ff9  lea     rsi, [rsp+48h+arg_10]
0x140001ffe  mov     rdi, rcx
0x140002001  call    sub_140001000
0x140002006  mov     [rsp+48h+var_20], rsi; __int64
0x14000200b  mov     r9, rbx; int
0x14000200e  mov     r8d, 80h; int
0x140002014  mov     [rsp+48h+var_28], 0; struct __crt_locale_pointers *
0x14000201d  mov     rdx, rdi; int
0x140002020  mov     rcx, [rax]; int
0x140002023  call    unknown_libname_13; Microsoft VisualC 64bit universal runtime
0x140002028  test    eax, eax
0x14000202a  mov     ecx, 0FFFFFFFFh
0x14000202f  cmovs   eax, ecx
0x140002032  add     rsp, 30h
0x140002036  pop     rdi
0x140002037  pop     rsi
0x140002038  pop     rbx
0x140002039  retn

// ===== swprintf @ 0x140002040 =====

0x140002040  mov     [rsp+arg_10], r8
0x140002045  mov     [rsp+arg_18], r9
0x14000204a  push    rbx
0x14000204b  push    rbp
0x14000204c  push    rsi
0x14000204d  push    rdi
0x14000204e  sub     rsp, 38h
0x140002052  mov     rsi, r8
0x140002055  lea     rbp, [rsp+58h+arg_18]
0x14000205a  mov     rbx, rdx
0x14000205d  mov     rdi, rcx
0x140002060  call    sub_140001000
0x140002065  mov     [rsp+58h+var_30], rbp; __int64
0x14000206a  mov     r9, rsi; int
0x14000206d  mov     r8, rbx; int
0x140002070  mov     [rsp+58h+var_38], 0; struct __crt_locale_pointers *
0x140002079  mov     rdx, rdi; int
0x14000207c  mov     rcx, [rax]; int
0x14000207f  call    unknown_libname_13; Microsoft VisualC 64bit universal runtime
0x140002084  test    eax, eax
0x140002086  mov     ecx, 0FFFFFFFFh
0x14000208b  cmovs   eax, ecx
0x14000208e  add     rsp, 38h
0x140002092  pop     rdi
0x140002093  pop     rsi
0x140002094  pop     rbp
0x140002095  pop     rbx
0x140002096  retn

// ===== ?pre_c_initialization@@YAHXZ @ 0x140002098 =====

0x140002098  push    rbx
0x14000209a  sub     rsp, 20h
0x14000209e  mov     ecx, 2
0x1400020a3  call    sub_140005748
0x1400020a8  call    _get_startup_file_mode
0x1400020ad  mov     ecx, eax; Mode
0x1400020af  call    _set_fmode
0x1400020b4  call    sub_14000627C
0x1400020b9  mov     rbx, rax
0x1400020bc  call    UserMathErrorFunction
0x1400020c1  mov     ecx, 1
0x1400020c6  mov     [rbx], eax
0x1400020c8  call    __scrt_initialize_onexit_tables
0x1400020cd  test    al, al
0x1400020cf  jz      short loc_140002144
0x1400020d1  call    sub_140002944
0x1400020d6  lea     rcx, sub_140002980; void (__cdecl *)()
0x1400020dd  call    atexit
0x1400020e2  call    ?raw_length@charNode@@UEBAHXZ
0x1400020e7  mov     ecx, eax; mode
0x1400020e9  call    _configure_wide_argv
0x1400020ee  test    eax, eax
0x1400020f0  jnz     short loc_140002144
0x1400020f2  call    sub_1400026B8
0x1400020f7  call    __scrt_is_user_matherr_present
0x1400020fc  test    eax, eax
0x1400020fe  jz      short loc_14000210C
0x140002100  lea     rcx, UserMathErrorFunction; UserMathErrorFunction
0x140002107  call    __setusermatherr
0x14000210c  call    _guard_check_icall_nop
0x140002111  call    _guard_check_icall_nop
0x140002116  call    UserMathErrorFunction
0x14000211b  mov     ecx, eax; Flag
0x14000211d  call    _configthreadlocale
0x140002122  call    sub_1400026C8
0x140002127  test    al, al
0x140002129  jz      short loc_140002130
0x14000212b  call    j_??$common_initialize_environment_nolock@_W@@YAHXZ
0x140002130  call    UserMathErrorFunction
0x140002135  call    j_UserMathErrorFunction
0x14000213a  test    eax, eax
0x14000213c  jnz     short loc_140002144
0x14000213e  add     rsp, 20h
0x140002142  pop     rbx
0x140002143  retn
0x140002144  mov     ecx, 7
0x140002149  call    __scrt_fastfail

// ===== ?post_pgo_initialization@@YAHXZ @ 0x140002150 =====

0x140002150  sub     rsp, 28h
0x140002154  call    __scrt_initialize_default_local_stdio_options
0x140002159  xor     eax, eax
0x14000215b  add     rsp, 28h
0x14000215f  retn

// ===== ?pre_cpp_initialization@@YAXXZ @ 0x140002160 =====

0x140002160  sub     rsp, 28h
0x140002164  call    __scrt_set_unhandled_exception_filter
0x140002169  call    UserMathErrorFunction
0x14000216e  mov     ecx, eax; NewMode
0x140002170  add     rsp, 28h
0x140002174  jmp     _set_new_mode

// ===== ?__scrt_common_main_seh@@YAHXZ @ 0x14000217c =====

0x14000217c  mov     [rsp+arg_0], rbx
0x140002181  push    rdi
0x140002182  sub     rsp, 30h
0x140002186  mov     ecx, 1
0x14000218b  call    __scrt_initialize_crt
0x140002190  test    al, al
0x140002192  jz      loc_1400022C8
0x140002198  xor     dil, dil
0x14000219b  mov     [rsp+38h+var_18], dil
0x1400021a0  call    __scrt_acquire_startup_lock
0x1400021a5  mov     bl, al
0x1400021a7  mov     ecx, cs:dword_14001C920
0x1400021ad  cmp     ecx, 1
0x1400021b0  jz      loc_1400022D3
0x1400021b6  test    ecx, ecx
0x1400021b8  jnz     short loc_140002204
0x1400021ba  mov     cs:dword_14001C920, 1
0x1400021c4  lea     rdx, qword_1400113A8; Last
0x1400021cb  lea     rcx, qword_140011378; First
0x1400021d2  call    _initterm_e
0x1400021d7  test    eax, eax
0x1400021d9  jz      short loc_1400021E5
0x1400021db  mov     eax, 0FFh
0x1400021e0  jmp     loc_1400022BD
0x1400021e5  lea     rdx, Last; Last
0x1400021ec  lea     rcx, First; First
0x1400021f3  call    _initterm
0x1400021f8  mov     cs:dword_14001C920, 2
0x140002202  jmp     short loc_14000220C
0x140002204  mov     dil, 1
0x140002207  mov     [rsp+38h+var_18], dil
0x14000220c  mov     cl, bl
0x14000220e  call    __scrt_release_startup_lock
0x140002213  call    sub_140002700
0x140002218  mov     rbx, rax
0x14000221b  cmp     qword ptr [rax], 0
0x14000221f  jz      short loc_14000223F
0x140002221  mov     rcx, rax
0x140002224  call    __scrt_is_nonwritable_in_current_image
0x140002229  test    al, al
0x14000222b  jz      short loc_14000223F
0x14000222d  xor     r8d, r8d
0x140002230  lea     edx, [r8+2]
0x140002234  xor     ecx, ecx
0x140002236  mov     rax, [rbx]
0x140002239  call    cs:__guard_dispatch_icall_fptr
0x14000223f  call    sub_140002708
0x140002244  mov     rbx, rax
0x140002247  cmp     qword ptr [rax], 0
0x14000224b  jz      short loc_140002261
0x14000224d  mov     rcx, rax
0x140002250  call    __scrt_is_nonwritable_in_current_image
0x140002255  test    al, al
0x140002257  jz      short loc_140002261
0x140002259  mov     rcx, [rbx]; Callback
0x14000225c  call    _register_thread_local_exe_atexit_callback
0x140002261  call    __scrt_get_show_window_mode
0x140002266  movzx   ebx, ax
0x140002269  call    _get_wide_winmain_command_line
0x14000226e  mov     r8, rax; lpCmdLine
0x140002271  mov     r9d, ebx; nShowCmd
0x140002274  xor     edx, edx; hPrevInstance
0x140002276  lea     rcx, cs:140000000h; hInstance
0x14000227d  call    WinMain
0x140002282  mov     ebx, eax
0x140002284  call    __scrt_is_managed_app
0x140002289  test    al, al
0x14000228b  jz      short loc_1400022DD
0x14000228d  test    dil, dil
0x140002290  jnz     short loc_140002297
0x140002292  call    _cexit
0x140002297  xor     edx, edx
0x140002299  mov     cl, 1
0x14000229b  call    __scrt_uninitialize_crt
0x1400022a0  mov     eax, ebx
0x1400022a2  jmp     short loc_1400022BD
0x1400022a4  mov     ebx, eax
0x1400022a6  call    __scrt_is_managed_app
0x1400022ab  test    al, al
0x1400022ad  jz      short loc_1400022E5
0x1400022af  cmp     [rsp+38h+var_18], 0
0x1400022b4  jnz     short loc_1400022BB
0x1400022b6  call    _c_exit
0x1400022bb  mov     eax, ebx
0x1400022bd  mov     rbx, [rsp+38h+arg_0]
0x1400022c2  add     rsp, 30h
0x1400022c6  pop     rdi
0x1400022c7  retn
0x1400022c8  mov     ecx, 7
0x1400022cd  call    __scrt_fastfail
0x1400022d2  nop
0x1400022d3  mov     ecx, 7
0x1400022d8  call    __scrt_fastfail
0x1400022dd  mov     ecx, ebx; Code
0x1400022df  call    exit
0x1400022e5  mov     ecx, ebx; Code
0x1400022e7  call    _exit
0x1400109a0  push    rbp
0x1400109a2  sub     rsp, 20h
0x1400109a6  mov     rbp, rdx
0x1400109a9  mov     rax, [rcx]
0x1400109ac  mov     rdx, rcx; ExceptionPtr
0x1400109af  mov     ecx, [rax]; ExceptionNum
0x1400109b1  call    _seh_filter_exe
0x1400109b6  nop
0x1400109b7  add     rsp, 20h
0x1400109bb  pop     rbp
0x1400109bc  retn

// ===== start @ 0x1400022f0 =====

0x1400022f0  sub     rsp, 28h
0x1400022f4  call    __security_init_cookie
0x1400022f9  add     rsp, 28h
0x1400022fd  jmp     ?__scrt_common_main_seh@@YAHXZ

// ===== j_j__free_base @ 0x140002304 =====

0x140002304  jmp     j__free_base

// ===== __security_check_cookie @ 0x140002320 =====

0x140002320  cmp     rcx, cs:__security_cookie
0x140002327  bnd jnz short ReportFailure
0x14000232a  rol     rcx, 10h
0x14000232e  test    cx, 0FFFFh
0x140002333  bnd jnz short RestoreRcx
0x140002336  bnd retn
0x140002338  ror     rcx, 10h; StackCookie
0x14000233c  jmp     __report_gsfailure

// ===== __scrt_acquire_startup_lock @ 0x140002344 =====

0x140002344  sub     rsp, 28h
0x140002348  call    __scrt_is_ucrt_dll_in_use
0x14000234d  test    eax, eax
0x14000234f  jz      short loc_140002372
0x140002351  mov     rax, gs:30h
0x14000235a  mov     rcx, [rax+8]
0x14000235e  jmp     short loc_140002365
0x140002360  cmp     rcx, rax
0x140002363  jz      short loc_140002379
0x140002365  xor     eax, eax
0x140002367  lock cmpxchg cs:qword_14001C928, rcx
0x140002370  jnz     short loc_140002360
0x140002372  xor     al, al
0x140002374  add     rsp, 28h
0x140002378  retn
0x140002379  mov     al, 1
0x14000237b  jmp     short loc_140002374

// ===== __scrt_initialize_crt @ 0x140002380 =====

0x140002380  push    rbx
0x140002382  sub     rsp, 20h
0x140002386  movzx   eax, cs:byte_14001C930
0x14000238d  test    ecx, ecx
0x14000238f  mov     ebx, 1
0x140002394  cmovz   eax, ebx
0x140002397  mov     cs:byte_14001C930, al
0x14000239d  call    __isa_available_init
0x1400023a2  call    __vcrt_initialize
0x1400023a7  test    al, al
0x1400023a9  jnz     short loc_1400023AF
0x1400023ab  xor     al, al
0x1400023ad  jmp     short loc_1400023C3
0x1400023af  call    __acrt_initialize
0x1400023b4  test    al, al
0x1400023b6  jnz     short loc_1400023C1
0x1400023b8  xor     ecx, ecx; Terminating
0x1400023ba  call    __vcrt_uninitialize
0x1400023bf  jmp     short loc_1400023AB
0x1400023c1  mov     al, bl
0x1400023c3  add     rsp, 20h
0x1400023c7  pop     rbx
0x1400023c8  retn

// ===== __scrt_initialize_onexit_tables @ 0x1400023cc =====

0x1400023cc  push    rbx
0x1400023ce  sub     rsp, 40h
0x1400023d2  cmp     cs:byte_14001C931, 0
0x1400023d9  mov     ebx, ecx
0x1400023db  jnz     loc_140002491
0x1400023e1  cmp     ecx, 1
0x1400023e4  ja      loc_140002499
0x1400023ea  call    __scrt_is_ucrt_dll_in_use
0x1400023ef  test    eax, eax
0x1400023f1  jz      short loc_14000241B
0x1400023f3  test    ebx, ebx
0x1400023f5  jnz     short loc_14000241B
0x1400023f7  lea     rcx, stru_14001C938; Table
0x1400023fe  call    _initialize_onexit_table
0x140002403  test    eax, eax
0x140002405  jnz     short loc_140002417
0x140002407  lea     rcx, stru_14001C950; Table
0x14000240e  call    _initialize_onexit_table
0x140002413  test    eax, eax
0x140002415  jz      short loc_14000248A
0x140002417  xor     al, al
0x140002419  jmp     short loc_140002493
0x14000241b  mov     rdx, cs:__security_cookie
0x140002422  mov     ecx, 40h ; '@'
0x140002427  mov     eax, edx
0x140002429  and     eax, 3Fh
0x14000242c  sub     ecx, eax
0x14000242e  or      rax, 0FFFFFFFFFFFFFFFFh
0x140002432  ror     rax, cl
0x140002435  xor     rax, rdx
0x140002438  mov     qword ptr [rsp+48h+var_28], rax
0x14000243d  mov     qword ptr [rsp+48h+var_28+8], rax
0x140002442  movups  xmm0, [rsp+48h+var_28]
0x140002447  mov     [rsp+48h+var_18], rax
0x14000244c  movsd   xmm1, [rsp+48h+var_18]
0x140002452  movups  xmmword ptr cs:stru_14001C938._first, xmm0
0x140002459  mov     qword ptr [rsp+48h+var_28], rax
0x14000245e  mov     qword ptr [rsp+48h+var_28+8], rax
0x140002463  movups  xmm0, [rsp+48h+var_28]
0x140002468  mov     [rsp+48h+var_18], rax
0x14000246d  movsd   cs:stru_14001C938._end, xmm1
0x140002475  movsd   xmm1, [rsp+48h+var_18]
0x14000247b  movups  xmmword ptr cs:stru_14001C950._first, xmm0
0x140002482  movsd   cs:stru_14001C950._end, xmm1
0x14000248a  mov     cs:byte_14001C931, 1
0x140002491  mov     al, 1
0x140002493  add     rsp, 40h
0x140002497  pop     rbx
0x140002498  retn
0x140002499  mov     ecx, 5
0x14000249e  call    __scrt_fastfail
0x1400024a3  int     3; Trap to Debugger

// ===== __scrt_is_nonwritable_in_current_image @ 0x1400024a4 =====

0x1400024a4  sub     rsp, 18h
0x1400024a8  mov     r8, rcx
0x1400024ab  mov     eax, 5A4Dh
0x1400024b0  cmp     cs:140000000h, ax
0x1400024b7  jnz     short loc_140002532
0x1400024b9  movsxd  rax, dword ptr cs:14000003Ch
0x1400024c0  lea     rdx, cs:140000000h
0x1400024c7  lea     rcx, [rax+rdx]
0x1400024cb  cmp     dword ptr [rcx], 4550h
0x1400024d1  jnz     short loc_140002532
0x1400024d3  mov     eax, 20Bh
0x1400024d8  cmp     [rcx+18h], ax
0x1400024dc  jnz     short loc_140002532
0x1400024de  sub     r8, rdx
0x1400024e1  movzx   eax, word ptr [rcx+14h]
0x1400024e5  lea     rdx, [rcx+18h]
0x1400024e9  add     rdx, rax
0x1400024ec  movzx   eax, word ptr [rcx+6]
0x1400024f0  lea     rcx, [rax+rax*4]
0x1400024f4  lea     r9, [rdx+rcx*8]
0x1400024f8  mov     [rsp+18h+var_18], rdx
0x1400024fc  cmp     rdx, r9
0x1400024ff  jz      short loc_140002519
0x140002501  mov     ecx, [rdx+0Ch]
0x140002504  cmp     r8, rcx
0x140002507  jb      short loc_140002513
0x140002509  mov     eax, [rdx+8]
0x14000250c  add     eax, ecx
0x14000250e  cmp     r8, rax
0x140002511  jb      short loc_14000251B
0x140002513  add     rdx, 28h ; '('
0x140002517  jmp     short loc_1400024F8
0x140002519  xor     edx, edx
0x14000251b  test    rdx, rdx
0x14000251e  jnz     short loc_140002524
0x140002520  xor     al, al
0x140002522  jmp     short loc_140002538
0x140002524  cmp     dword ptr [rdx+24h], 0
0x140002528  jge     short loc_14000252E
0x14000252a  xor     al, al
0x14000252c  jmp     short loc_140002538
0x14000252e  mov     al, 1
0x140002530  jmp     short loc_140002538
0x140002532  xor     al, al
0x140002534  jmp     short loc_140002538
0x140002536  xor     al, al
0x140002538  add     rsp, 18h
0x14000253c  retn
0x1400109be  push    rbp
0x1400109c0  mov     rbp, rdx
0x1400109c3  mov     rax, [rcx]
0x1400109c6  xor     ecx, ecx
0x1400109c8  cmp     dword ptr [rax], 0C0000005h
0x1400109ce  setz    cl
0x1400109d1  mov     eax, ecx
0x1400109d3  pop     rbp
0x1400109d4  retn

// ===== __scrt_release_startup_lock @ 0x140002540 =====

0x140002540  push    rbx
0x140002542  sub     rsp, 20h
0x140002546  mov     bl, cl
0x140002548  call    __scrt_is_ucrt_dll_in_use
0x14000254d  xor     edx, edx
0x14000254f  test    eax, eax
0x140002551  jz      short loc_14000255E
0x140002553  test    bl, bl
0x140002555  jnz     short loc_14000255E
0x140002557  xchg    rdx, cs:qword_14001C928
0x14000255e  add     rsp, 20h
0x140002562  pop     rbx
0x140002563  retn

// ===== __scrt_uninitialize_crt @ 0x140002564 =====

0x140002564  push    rbx
0x140002566  sub     rsp, 20h
0x14000256a  cmp     cs:byte_14001C930, 0
0x140002571  mov     bl, cl
0x140002573  jz      short loc_140002579
0x140002575  test    dl, dl
0x140002577  jnz     short loc_140002587
0x140002579  mov     cl, bl; Terminating
0x14000257b  call    __acrt_uninitialize
0x140002580  mov     cl, bl; Terminating
0x140002582  call    __vcrt_uninitialize
0x140002587  mov     al, 1
0x140002589  add     rsp, 20h
0x14000258d  pop     rbx
0x14000258e  retn

// ===== _onexit @ 0x140002590 =====

0x140002590  push    rbx
0x140002592  sub     rsp, 20h
0x140002596  mov     rdx, cs:__security_cookie
0x14000259d  mov     rbx, rcx
0x1400025a0  mov     ecx, edx
0x1400025a2  xor     rdx, cs:stru_14001C938._first
0x1400025a9  and     ecx, 3Fh
0x1400025ac  ror     rdx, cl
0x1400025af  cmp     rdx, 0FFFFFFFFFFFFFFFFh
0x1400025b3  jnz     short loc_1400025BF
0x1400025b5  mov     rcx, rbx; Function
0x1400025b8  call    sub_140006644
0x1400025bd  jmp     short loc_1400025CE
0x1400025bf  mov     rdx, rbx; Function
0x1400025c2  lea     rcx, stru_14001C938; Table
0x1400025c9  call    _register_onexit_function
0x1400025ce  xor     ecx, ecx
0x1400025d0  test    eax, eax
0x1400025d2  cmovz   rcx, rbx
0x1400025d6  mov     rax, rcx
0x1400025d9  add     rsp, 20h
0x1400025dd  pop     rbx
0x1400025de  retn

// ===== atexit @ 0x1400025e0 =====

0x1400025e0  sub     rsp, 28h
0x1400025e4  call    _onexit
0x1400025e9  neg     rax
0x1400025ec  sbb     eax, eax
0x1400025ee  neg     eax
0x1400025f0  dec     eax
0x1400025f2  add     rsp, 28h
0x1400025f6  retn

// ===== __security_init_cookie @ 0x1400025f8 =====

0x1400025f8  mov     [rsp-8+arg_18], rbx
0x1400025fd  push    rbp
0x1400025fe  mov     rbp, rsp
0x140002601  sub     rsp, 20h
0x140002605  mov     rax, cs:__security_cookie
0x14000260c  mov     rbx, 2B992DDFA232h
0x140002616  cmp     rax, rbx
0x140002619  jnz     short loc_14000268F
0x14000261b  and     qword ptr [rbp+SystemTimeAsFileTime.dwLowDateTime], 0
0x140002620  lea     rcx, [rbp+SystemTimeAsFileTime]; lpSystemTimeAsFileTime
0x140002624  call    cs:GetSystemTimeAsFileTime; KERNEL32
0x14000262a  mov     rax, qword ptr [rbp+SystemTimeAsFileTime.dwLowDateTime]
0x14000262e  mov     [rbp+arg_0], rax
0x140002632  call    cs:GetCurrentThreadId; KERNEL32
0x140002638  mov     eax, eax
0x14000263a  xor     [rbp+arg_0], rax
0x14000263e  call    cs:GetCurrentProcessId; KERNEL32
0x140002644  mov     eax, eax
0x140002646  lea     rcx, [rbp+PerformanceCount]; lpPerformanceCount
0x14000264a  xor     [rbp+arg_0], rax
0x14000264e  call    cs:QueryPerformanceCounter; KERNEL32
0x140002654  mov     eax, dword ptr [rbp+PerformanceCount]
0x140002657  lea     rcx, [rbp+arg_0]
0x14000265b  shl     rax, 20h
0x14000265f  xor     rax, qword ptr [rbp+PerformanceCount]
0x140002663  xor     rax, [rbp+arg_0]
0x140002667  xor     rax, rcx
0x14000266a  mov     rcx, 0FFFFFFFFFFFFh
0x140002674  and     rax, rcx
0x140002677  mov     rcx, 2B992DDFA233h
0x140002681  cmp     rax, rbx
0x140002684  cmovz   rax, rcx
0x140002688  mov     cs:__security_cookie, rax
0x14000268f  mov     rbx, [rsp+20h+arg_18]
0x140002694  not     rax
0x140002697  mov     cs:qword_14001C008, rax
0x14000269e  add     rsp, 20h
0x1400026a2  pop     rbp
0x1400026a3  retn

// ===== UserMathErrorFunction @ 0x1400026a4 =====

0x1400026a4  xor     eax, eax
0x1400026a6  retn

// ===== ?raw_length@charNode@@UEBAHXZ @ 0x1400026a8 =====

0x1400026a8  mov     eax, 1
0x1400026ad  retn

// ===== _get_startup_file_mode @ 0x1400026b0 =====

0x1400026b0  mov     eax, 4000h
0x1400026b5  retn

// ===== sub_1400026B8 @ 0x1400026b8 =====

0x1400026b8  lea     rcx, stru_14001C970
0x1400026bf  jmp     cs:InitializeSListHead; KERNEL32

// ===== sub_1400026C8 @ 0x1400026c8 =====

0x1400026c8  mov     al, 1
0x1400026ca  retn

// ===== _guard_check_icall_nop @ 0x1400026cc =====

0x1400026cc  retn    0

// ===== sub_1400026D0 @ 0x1400026d0 =====

0x1400026d0  lea     rax, unk_14001C980
0x1400026d7  retn

// ===== __scrt_initialize_default_local_stdio_options @ 0x1400026d8 =====

0x1400026d8  sub     rsp, 28h
0x1400026dc  call    sub_140001000
0x1400026e1  or      qword ptr [rax], 4
0x1400026e5  call    sub_1400026D0
0x1400026ea  or      qword ptr [rax], 2
0x1400026ee  add     rsp, 28h
0x1400026f2  retn

// ===== __scrt_is_user_matherr_present @ 0x1400026f4 =====

0x1400026f4  xor     eax, eax
0x1400026f6  cmp     cs:dword_14001C004, eax
0x1400026fc  setz    al
0x1400026ff  retn

// ===== sub_140002700 @ 0x140002700 =====

0x140002700  lea     rax, unk_14001DC00
0x140002707  retn

// ===== sub_140002708 @ 0x140002708 =====

0x140002708  lea     rax, unk_14001DBF8
0x14000270f  retn

// ===== sub_140002710 @ 0x140002710 =====

0x140002710  and     cs:dword_14001C988, 0
0x140002717  retn

// ===== __scrt_fastfail @ 0x140002718 =====

0x140002718  mov     [rsp-8+arg_0], rbx
0x14000271d  push    rbp
0x14000271e  lea     rbp, [rsp-4C0h]
0x140002726  sub     rsp, 5C0h
0x14000272d  mov     ebx, ecx
0x14000272f  mov     ecx, 17h; ProcessorFeature
0x140002734  call    IsProcessorFeaturePresent
0x140002739  test    eax, eax
0x14000273b  jz      short loc_140002741
0x14000273d  mov     ecx, ebx
0x14000273f  int     29h; Win8: RtlFailFast(ecx)
0x140002741  mov     ecx, 3
0x140002746  call    sub_140002710
0x14000274b  xor     edx, edx
0x14000274d  lea     rcx, [rbp+4C0h+ContextRecord]
0x140002751  mov     r8d, 4D0h
0x140002757  call    sub_140002F60
0x14000275c  lea     rcx, [rbp+4C0h+ContextRecord]; ContextRecord
0x140002760  call    cs:RtlCaptureContext; KERNEL32
0x140002766  mov     rbx, [rbp+4C0h+ContextRecord.Rip]
0x14000276d  lea     rdx, [rbp+4C0h+ImageBase]; ImageBase
0x140002774  mov     rcx, rbx; ControlPc
0x140002777  xor     r8d, r8d; HistoryTable
0x14000277a  call    cs:RtlLookupFunctionEntry; KERNEL32
0x140002780  test    rax, rax
0x140002783  jz      short loc_1400027C1
0x140002785  and     [rsp+5C0h+var_588], 0
0x14000278b  lea     rcx, [rbp+4C0h+arg_10]
0x140002792  mov     rdx, [rbp+4C0h+ImageBase]; ImageBase
0x140002799  mov     r9, rax; FunctionEntry
0x14000279c  mov     [rsp+5C0h+EstablisherFrame], rcx; EstablisherFrame
0x1400027a1  mov     r8, rbx; ControlPc
0x1400027a4  lea     rcx, [rbp+4C0h+arg_18]
0x1400027ab  mov     [rsp+5C0h+HandlerData], rcx; HandlerData
0x1400027b0  lea     rcx, [rbp+4C0h+ContextRecord]
0x1400027b4  mov     [rsp+5C0h+var_5A0], rcx; ContextRecord
0x1400027b9  xor     ecx, ecx; HandlerType
0x1400027bb  call    cs:RtlVirtualUnwind; KERNEL32
0x1400027c1  mov     rax, [rbp+4C8h]
0x1400027c8  lea     rcx, [rsp+5C0h+var_570]
0x1400027cd  mov     [rbp+4C0h+ContextRecord.Rip], rax
0x1400027d4  xor     edx, edx
0x1400027d6  lea     rax, [rbp+4C8h]
0x1400027dd  mov     r8d, 98h
0x1400027e3  add     rax, 8
0x1400027e7  mov     [rbp+4C0h+ContextRecord.Rsp], rax
0x1400027ee  call    sub_140002F60
0x1400027f3  mov     rax, [rbp+4C8h]
0x1400027fa  mov     [rsp+5C0h+var_560], rax
0x1400027ff  mov     [rsp+5C0h+var_570], 40000015h
0x140002807  mov     [rsp+5C0h+var_56C], 1
0x14000280f  call    cs:IsDebuggerPresent; KERNEL32
0x140002815  cmp     eax, 1
0x140002818  lea     rax, [rsp+5C0h+var_570]
0x14000281d  mov     [rsp+5C0h+ExceptionInfo.ExceptionRecord], rax
0x140002822  lea     rax, [rbp+4C0h+ContextRecord]
0x140002826  setz    bl
0x140002829  mov     [rsp+5C0h+ExceptionInfo.ContextRecord], rax
0x14000282e  xor     ecx, ecx; lpTopLevelExceptionFilter
0x140002830  call    cs:SetUnhandledExceptionFilter; KERNEL32
0x140002836  lea     rcx, [rsp+5C0h+ExceptionInfo]; ExceptionInfo
0x14000283b  call    cs:UnhandledExceptionFilter; KERNEL32
0x140002841  test    eax, eax
0x140002843  jnz     short loc_140002851
0x140002845  test    bl, bl
0x140002847  jnz     short loc_140002851
0x140002849  lea     ecx, [rax+3]
0x14000284c  call    sub_140002710
0x140002851  mov     rbx, [rsp+5C0h+arg_0]
0x140002859  add     rsp, 5C0h
0x140002860  pop     rbp
0x140002861  retn

// ===== __scrt_get_show_window_mode @ 0x140002864 =====

0x140002864  sub     rsp, 98h
0x14000286b  xor     edx, edx
0x14000286d  lea     rcx, [rsp+98h+StartupInfo]
0x140002872  lea     r8d, [rdx+68h]
0x140002876  call    sub_140002F60
0x14000287b  lea     rcx, [rsp+98h+StartupInfo]; lpStartupInfo
0x140002880  call    cs:GetStartupInfoW; KERNEL32
0x140002886  test    byte ptr [rsp+98h+StartupInfo.dwFlags], 1
0x14000288b  mov     eax, 0Ah
0x140002890  cmovnz  ax, [rsp+98h+StartupInfo.wShowWindow]
0x140002896  add     rsp, 98h
0x14000289d  retn

// ===== j_UserMathErrorFunction @ 0x1400028a0 =====

0x1400028a0  jmp     UserMathErrorFunction

// ===== __scrt_is_managed_app @ 0x1400028a8 =====

0x1400028a8  sub     rsp, 28h
0x1400028ac  xor     ecx, ecx; lpModuleName
0x1400028ae  call    cs:GetModuleHandleW; KERNEL32
0x1400028b4  test    rax, rax
0x1400028b7  jz      short loc_1400028F3
0x1400028b9  mov     ecx, 5A4Dh
0x1400028be  cmp     [rax], cx
0x1400028c1  jnz     short loc_1400028F3
0x1400028c3  movsxd  rcx, dword ptr [rax+3Ch]
0x1400028c7  add     rcx, rax
0x1400028ca  cmp     dword ptr [rcx], 4550h
0x1400028d0  jnz     short loc_1400028F3
0x1400028d2  mov     eax, 20Bh
0x1400028d7  cmp     [rcx+18h], ax
0x1400028db  jnz     short loc_1400028F3
0x1400028dd  cmp     dword ptr [rcx+84h], 0Eh
0x1400028e4  jbe     short loc_1400028F3
0x1400028e6  cmp     dword ptr [rcx+0F8h], 0
0x1400028ed  jz      short loc_1400028F3
0x1400028ef  mov     al, 1
0x1400028f1  jmp     short loc_1400028F5
0x1400028f3  xor     al, al
0x1400028f5  add     rsp, 28h
0x1400028f9  retn

// ===== __scrt_set_unhandled_exception_filter @ 0x1400028fc =====

0x1400028fc  lea     rcx, __scrt_unhandled_exception_filter
0x140002903  jmp     cs:SetUnhandledExceptionFilter; KERNEL32

// ===== __scrt_unhandled_exception_filter @ 0x14000290c =====

0x14000290c  sub     rsp, 28h
0x140002910  mov     rax, [rcx]
0x140002913  cmp     dword ptr [rax], 0E06D7363h
0x140002919  jnz     short loc_140002937
0x14000291b  cmp     dword ptr [rax+18h], 4
0x14000291f  jnz     short loc_140002937
0x140002921  mov     ecx, [rax+20h]
0x140002924  lea     eax, [rcx-19930520h]
0x14000292a  cmp     eax, 2
0x14000292d  jbe     short loc_14000293E
0x14000292f  cmp     ecx, 1994000h
0x140002935  jz      short loc_14000293E
0x140002937  xor     eax, eax
0x140002939  add     rsp, 28h
0x14000293d  retn
0x14000293e  call    terminate

// ===== sub_140002944 @ 0x140002944 =====

0x140002944  mov     [rsp+arg_0], rbx
0x140002949  push    rdi
0x14000294a  sub     rsp, 20h
0x14000294e  lea     rbx, qword_1400199E8
0x140002955  lea     rdi, qword_1400199E8
0x14000295c  jmp     short loc_140002970
0x14000295e  mov     rax, [rbx]
0x140002961  test    rax, rax
0x140002964  jz      short loc_14000296C
0x140002966  call    cs:__guard_dispatch_icall_fptr
0x14000296c  add     rbx, 8
0x140002970  cmp     rbx, rdi
0x140002973  jb      short loc_14000295E
0x140002975  mov     rbx, [rsp+28h+arg_0]
0x14000297a  add     rsp, 20h
0x14000297e  pop     rdi
0x14000297f  retn

// ===== sub_140002980 @ 0x140002980 =====

0x140002980  mov     [rsp+arg_0], rbx
0x140002985  push    rdi
0x140002986  sub     rsp, 20h
0x14000298a  lea     rbx, qword_1400199F8
0x140002991  lea     rdi, qword_1400199F8
0x140002998  jmp     short loc_1400029AC
0x14000299a  mov     rax, [rbx]
0x14000299d  test    rax, rax
0x1400029a0  jz      short loc_1400029A8
0x1400029a2  call    cs:__guard_dispatch_icall_fptr
0x1400029a8  add     rbx, 8
0x1400029ac  cmp     rbx, rdi
0x1400029af  jb      short loc_14000299A
0x1400029b1  mov     rbx, [rsp+28h+arg_0]
0x1400029b6  add     rsp, 20h
0x1400029ba  pop     rdi
0x1400029bb  retn

// ===== __raise_securityfailure @ 0x1400029bc =====

0x1400029bc  push    rbx
0x1400029be  sub     rsp, 20h
0x1400029c2  mov     rbx, rcx
0x1400029c5  xor     ecx, ecx; lpTopLevelExceptionFilter
0x1400029c7  call    cs:SetUnhandledExceptionFilter; KERNEL32
0x1400029cd  mov     rcx, rbx; ExceptionInfo
0x1400029d0  call    cs:UnhandledExceptionFilter; KERNEL32
0x1400029d6  call    cs:GetCurrentProcess; KERNEL32
0x1400029dc  mov     rcx, rax
0x1400029df  mov     edx, 0C0000409h
0x1400029e4  add     rsp, 20h
0x1400029e8  pop     rbx
0x1400029e9  jmp     cs:TerminateProcess; KERNEL32

// ===== __report_gsfailure @ 0x1400029f0 =====

0x1400029f0  mov     [rsp+arg_0], rcx
0x1400029f5  sub     rsp, 38h
0x1400029f9  mov     ecx, 17h; ProcessorFeature
0x1400029fe  call    IsProcessorFeaturePresent
0x140002a03  test    eax, eax
0x140002a05  jz      short loc_140002A0E
0x140002a07  mov     ecx, 2
0x140002a0c  int     29h; Win8: RtlFailFast(ecx)
0x140002a0e  lea     rcx, ContextRecord; ContextRecord
0x140002a15  call    capture_previous_context
0x140002a1a  mov     rax, [rsp+38h]
0x140002a1f  mov     cs:ContextRecord.Rip, rax
0x140002a26  lea     rax, [rsp+38h]
0x140002a2b  add     rax, 8
0x140002a2f  mov     cs:ContextRecord.Rsp, rax
0x140002a36  mov     rax, cs:ContextRecord.Rip
0x140002a3d  mov     cs:qword_14001C9A0, rax
0x140002a44  mov     rax, [rsp+38h+arg_0]
0x140002a49  mov     cs:ContextRecord.Rcx, rax
0x140002a50  mov     cs:dword_14001C990, 0C0000409h
0x140002a5a  mov     cs:dword_14001C994, 1
0x140002a64  mov     cs:dword_14001C9A8, 1
0x140002a6e  mov     eax, 8
0x140002a73  imul    rax, 0
0x140002a77  lea     rcx, unk_14001C9B0
0x140002a7e  mov     qword ptr [rcx+rax], 2
0x140002a86  mov     eax, 8
0x140002a8b  imul    rax, 0
0x140002a8f  mov     rcx, cs:__security_cookie
0x140002a96  mov     [rsp+rax+38h+var_18], rcx
0x140002a9b  mov     eax, 8
0x140002aa0  imul    rax, 1
0x140002aa4  mov     rcx, cs:qword_14001C008
0x140002aab  mov     [rsp+rax+38h+var_18], rcx
0x140002ab0  lea     rcx, ExceptionInfo; ExceptionInfo
0x140002ab7  call    __raise_securityfailure
0x140002abc  add     rsp, 38h
0x140002ac0  retn

// ===== capture_previous_context @ 0x140002ac4 =====

0x140002ac4  push    rbx
0x140002ac6  push    rsi
0x140002ac7  push    rdi
0x140002ac8  sub     rsp, 40h
0x140002acc  mov     rbx, rcx
0x140002acf  call    cs:RtlCaptureContext; KERNEL32
0x140002ad5  mov     rsi, [rbx+0F8h]
0x140002adc  xor     edi, edi
0x140002ade  xor     r8d, r8d; HistoryTable
0x140002ae1  lea     rdx, [rsp+58h+ImageBase]; ImageBase
0x140002ae6  mov     rcx, rsi; ControlPc
0x140002ae9  call    cs:RtlLookupFunctionEntry; KERNEL32
0x140002aef  test    rax, rax
0x140002af2  jz      short loc_140002B2D
0x140002af4  and     [rsp+58h+var_20], 0
0x140002afa  lea     rcx, [rsp+58h+arg_8]
0x140002aff  mov     rdx, [rsp+58h+ImageBase]; ImageBase
0x140002b04  mov     r9, rax; FunctionEntry
0x140002b07  mov     [rsp+58h+EstablisherFrame], rcx; EstablisherFrame
0x140002b0c  mov     r8, rsi; ControlPc
0x140002b0f  lea     rcx, [rsp+58h+arg_10]
0x140002b14  mov     [rsp+58h+HandlerData], rcx; HandlerData
0x140002b19  xor     ecx, ecx; HandlerType
0x140002b1b  mov     [rsp+58h+ContextRecord], rbx; ContextRecord
0x140002b20  call    cs:RtlVirtualUnwind; KERNEL32
0x140002b26  inc     edi
0x140002b28  cmp     edi, 2
0x140002b2b  jl      short loc_140002ADE
0x140002b2d  add     rsp, 40h
0x140002b31  pop     rdi
0x140002b32  pop     rsi
0x140002b33  pop     rbx
0x140002b34  retn

// ===== __isa_available_init @ 0x140002b38 =====

0x140002b38  mov     [rsp+arg_8], rbx
0x140002b3d  mov     [rsp+arg_10], rsi
0x140002b42  push    rdi
0x140002b43  sub     rsp, 10h
0x140002b47  xor     eax, eax
0x140002b49  mov     cs:dword_14001C01C, 2
0x140002b53  xor     ecx, ecx
0x140002b55  mov     cs:dword_14001C018, 1
0x140002b5f  cpuid
0x140002b61  mov     r8d, ecx
0x140002b64  xor     edi, edi
0x140002b66  mov     r9d, ebx
0x140002b69  xor     r8d, 6C65746Eh
0x140002b70  xor     r9d, 756E6547h
0x140002b77  mov     r10d, edx
0x140002b7a  mov     esi, eax
0x140002b7c  xor     ecx, ecx
0x140002b7e  lea     eax, [rdi+1]
0x140002b81  or      r9d, r8d
0x140002b84  cpuid
0x140002b86  xor     r10d, 49656E69h
0x140002b8d  mov     [rsp+18h+var_18], eax
0x140002b90  or      r9d, r10d
0x140002b93  mov     [rsp+18h+var_14], ebx
0x140002b97  mov     r11d, ecx
0x140002b9a  mov     [rsp+18h+var_10], ecx
0x140002b9e  mov     [rsp+18h+var_C], edx
0x140002ba2  jnz     short loc_140002BF4
0x140002ba4  or      cs:qword_14001C020, 0FFFFFFFFFFFFFFFFh
0x140002bac  and     eax, 0FFF3FF0h
0x140002bb1  cmp     eax, 106C0h
0x140002bb6  jz      short loc_140002BE0
0x140002bb8  cmp     eax, 20660h
0x140002bbd  jz      short loc_140002BE0
0x140002bbf  cmp     eax, 20670h
0x140002bc4  jz      short loc_140002BE0
0x140002bc6  add     eax, 0FFFCF9B0h
0x140002bcb  cmp     eax, 20h ; ' '
0x140002bce  ja      short loc_140002BF4
0x140002bd0  mov     rcx, 100010001h
0x140002bda  bt      rcx, rax
0x140002bde  jnb     short loc_140002BF4
0x140002be0  mov     r8d, cs:dword_14001CF00
0x140002be7  or      r8d, 1
0x140002beb  mov     cs:dword_14001CF00, r8d
0x140002bf2  jmp     short loc_140002BFB
0x140002bf4  mov     r8d, cs:dword_14001CF00
0x140002bfb  mov     eax, 7
0x140002c00  cmp     esi, eax
0x140002c02  jl      short loc_140002C2A
0x140002c04  xor     ecx, ecx
0x140002c06  cpuid
0x140002c08  mov     [rsp+18h+var_18], eax
0x140002c0b  mov     edi, ebx
0x140002c0d  mov     [rsp+18h+var_14], ebx
0x140002c11  mov     [rsp+18h+var_10], ecx
0x140002c15  mov     [rsp+18h+var_C], edx
0x140002c19  bt      ebx, 9
0x140002c1d  jnb     short loc_140002C2A
0x140002c1f  or      r8d, 2
0x140002c23  mov     cs:dword_14001CF00, r8d
0x140002c2a  bt      r11d, 14h
0x140002c2f  jnb     short loc_140002CA1
0x140002c31  mov     cs:dword_14001C018, 2
0x140002c3b  mov     cs:dword_14001C01C, 6
0x140002c45  bt      r11d, 1Bh
0x140002c4a  jnb     short loc_140002CA1
0x140002c4c  bt      r11d, 1Ch
0x140002c51  jnb     short loc_140002CA1
0x140002c53  xor     ecx, ecx
0x140002c55  xgetbv
0x140002c58  shl     rdx, 20h
0x140002c5c  or      rdx, rax
0x140002c5f  mov     [rsp+18h+arg_0], rdx
0x140002c64  mov     rax, [rsp+18h+arg_0]
0x140002c69  and     al, 6
0x140002c6b  cmp     al, 6
0x140002c6d  jnz     short loc_140002CA1
0x140002c6f  mov     eax, cs:dword_14001C01C
0x140002c75  or      eax, 8
0x140002c78  mov     cs:dword_14001C018, 3
0x140002c82  mov     cs:dword_14001C01C, eax
0x140002c88  test    dil, 20h
0x140002c8c  jz      short loc_140002CA1
0x140002c8e  or      eax, 20h
0x140002c91  mov     cs:dword_14001C018, 5
0x140002c9b  mov     cs:dword_14001C01C, eax
0x140002ca1  mov     rbx, [rsp+18h+arg_8]
0x140002ca6  xor     eax, eax
0x140002ca8  mov     rsi, [rsp+18h+arg_10]
0x140002cad  add     rsp, 10h
0x140002cb1  pop     rdi
0x140002cb2  retn

// ===== __scrt_is_ucrt_dll_in_use @ 0x140002cb4 =====

0x140002cb4  xor     eax, eax
0x140002cb6  cmp     cs:dword_14001DBF4, eax
0x140002cbc  setnz   al
0x140002cbf  retn

// ===== IsProcessorFeaturePresent @ 0x140002cc0 =====

0x140002cc0  jmp     cs:__imp_IsProcessorFeaturePresent; KERNEL32

// ===== __C_specific_handler @ 0x140002cc8 =====

0x140002cc8  mov     [rsp+arg_0], rbx
0x140002ccd  mov     [rsp+arg_8], rbp
0x140002cd2  mov     [rsp+arg_10], rsi
0x140002cd7  push    rdi
0x140002cd8  push    r12
0x140002cda  push    r13
0x140002cdc  push    r14
0x140002cde  push    r15
0x140002ce0  sub     rsp, 40h
0x140002ce4  mov     rbp, rcx
0x140002ce7  mov     r15, r9
0x140002cea  mov     rcx, r8
0x140002ced  mov     rdi, r8
0x140002cf0  mov     r13, rdx
0x140002cf3  call    __except_validate_context_record
0x140002cf8  mov     r12, [r15+8]
0x140002cfc  mov     r14, [r15]
0x140002cff  mov     rbx, [r15+38h]
0x140002d03  sub     r14, r12
0x140002d06  test    byte ptr [rbp+4], 66h
0x140002d0a  mov     esi, [r15+48h]
0x140002d0e  jnz     loc_140002DF0
0x140002d14  mov     [rsp+68h+var_38], rbp
0x140002d19  mov     [rsp+68h+var_30], rdi
0x140002d1e  cmp     esi, [rbx]
0x140002d20  jnb     loc_140002EB0
0x140002d26  mov     edi, esi
0x140002d28  add     rdi, rdi
0x140002d2b  mov     eax, [rbx+rdi*8+4]
0x140002d2f  cmp     r14, rax
0x140002d32  jb      loc_140002DE2
0x140002d38  mov     eax, [rbx+rdi*8+8]
0x140002d3c  cmp     r14, rax
0x140002d3f  jnb     loc_140002DE2
0x140002d45  cmp     dword ptr [rbx+rdi*8+10h], 0
0x140002d4a  jz      loc_140002DE2
0x140002d50  cmp     dword ptr [rbx+rdi*8+0Ch], 1
0x140002d55  jz      short loc_140002D6E
0x140002d57  mov     eax, [rbx+rdi*8+0Ch]
0x140002d5b  lea     rcx, [rsp+68h+var_38]
0x140002d60  add     rax, r12
0x140002d63  mov     rdx, r13
0x140002d66  call    rax
0x140002d68  test    eax, eax
0x140002d6a  js      short loc_140002DE9
0x140002d6c  jle     short loc_140002DE2
0x140002d6e  cmp     dword ptr [rbp+0], 0E06D7363h
0x140002d75  jnz     short loc_140002D9F
0x140002d77  cmp     cs:off_140011410, 0
0x140002d7f  jz      short loc_140002D9F
0x140002d81  lea     rcx, off_140011410
0x140002d88  call    _IsNonwritableInCurrentImage
0x140002d8d  test    eax, eax
0x140002d8f  jz      short loc_140002D9F
0x140002d91  mov     edx, 1
0x140002d96  mov     rcx, rbp
0x140002d99  call    cs:off_140011410
0x140002d9f  mov     ecx, [rbx+rdi*8+10h]
0x140002da3  mov     r8d, 1
0x140002da9  add     rcx, r12
0x140002dac  mov     rdx, r13
0x140002daf  call    _NLG_Notify
0x140002db4  mov     rax, [r15+40h]
0x140002db8  mov     r8, rbp; ExceptionRecord
0x140002dbb  mov     edx, [rbx+rdi*8+10h]
0x140002dbf  mov     rcx, r13; TargetFrame
0x140002dc2  mov     r9d, [rbp+0]; ReturnValue
0x140002dc6  add     rdx, r12; TargetIp
0x140002dc9  mov     [rsp+68h+HistoryTable], rax; HistoryTable
0x140002dce  mov     rax, [r15+28h]
0x140002dd2  mov     [rsp+68h+ContextRecord], rax; ContextRecord
0x140002dd7  call    cs:RtlUnwindEx; KERNEL32
0x140002ddd  call    __NLG_Return2
0x140002de2  inc     esi
0x140002de4  jmp     loc_140002D1E
0x140002de9  xor     eax, eax
0x140002deb  jmp     loc_140002EB5
0x140002df0  mov     rdi, [r15+20h]
0x140002df4  mov     r9d, [rbx]
0x140002df7  sub     rdi, r12
0x140002dfa  cmp     esi, r9d
0x140002dfd  jnb     loc_140002EB0
0x140002e03  mov     r8d, r9d
0x140002e06  mov     edx, esi
0x140002e08  mov     ecx, r8d
0x140002e0b  add     rdx, rdx
0x140002e0e  mov     eax, [rbx+rdx*8+4]
0x140002e12  cmp     r14, rax
0x140002e15  jb      loc_140002EA3
0x140002e1b  mov     eax, [rbx+rdx*8+8]
0x140002e1f  cmp     r14, rax
0x140002e22  jnb     short loc_140002EA3
0x140002e24  mov     r11d, [rbp+4]
0x140002e28  and     r11d, 20h
0x140002e2c  jz      short loc_140002E72
0x140002e2e  xor     r10d, r10d
0x140002e31  test    r8d, r8d
0x140002e34  jz      short loc_140002E6A
0x140002e36  mov     ecx, r10d
0x140002e39  add     rcx, rcx
0x140002e3c  mov     eax, [rbx+rcx*8+4]
0x140002e40  cmp     rdi, rax
0x140002e43  jb      short loc_140002E62
0x140002e45  mov     eax, [rbx+rcx*8+8]
0x140002e49  cmp     rdi, rax
0x140002e4c  jnb     short loc_140002E62
0x140002e4e  mov     eax, [rbx+rdx*8+10h]
0x140002e52  cmp     [rbx+rcx*8+10h], eax
0x140002e56  jnz     short loc_140002E62
0x140002e58  mov     eax, [rbx+rdx*8+0Ch]
0x140002e5c  cmp     [rbx+rcx*8+0Ch], eax
0x140002e60  jz      short loc_140002E6A
0x140002e62  inc     r10d
0x140002e65  cmp     r10d, r8d
0x140002e68  jb      short loc_140002E36
0x140002e6a  mov     ecx, r9d
0x140002e6d  cmp     r10d, r9d
0x140002e70  jnz     short loc_140002EB0
0x140002e72  mov     eax, [rbx+rdx*8+10h]
0x140002e76  test    eax, eax
0x140002e78  jz      short loc_140002E86
0x140002e7a  cmp     rdi, rax
0x140002e7d  jnz     short loc_140002EA3
0x140002e7f  test    r11d, r11d
0x140002e82  jnz     short loc_140002EB0
0x140002e84  jmp     short loc_140002EA3
0x140002e86  lea     eax, [rsi+1]
0x140002e89  mov     cl, 1
0x140002e8b  mov     [r15+48h], eax
0x140002e8f  mov     r8d, [rbx+rdx*8+0Ch]
0x140002e94  mov     rdx, r13
0x140002e97  add     r8, r12
0x140002e9a  call    r8
0x140002e9d  mov     r9d, [rbx]
0x140002ea0  mov     ecx, r9d
0x140002ea3  inc     esi
0x140002ea5  mov     r8d, ecx
0x140002ea8  cmp     esi, ecx
0x140002eaa  jb      loc_140002E06
0x140002eb0  mov     eax, 1
0x140002eb5  lea     r11, [rsp+68h+var_28]
0x140002eba  mov     rbx, [r11+30h]
0x140002ebe  mov     rbp, [r11+38h]
0x140002ec2  mov     rsi, [r11+40h]
0x140002ec6  mov     rsp, r11
0x140002ec9  pop     r15
0x140002ecb  pop     r14
0x140002ecd  pop     r13
0x140002ecf  pop     r12
0x140002ed1  pop     rdi
0x140002ed2  retn

// ===== __vcrt_initialize @ 0x140002ed4 =====

0x140002ed4  sub     rsp, 28h
0x140002ed8  call    __vcrt_initialize_pure_virtual_call_handler
0x140002edd  call    __vcrt_initialize_winapi_thunks
0x140002ee2  call    __vcrt_initialize_locks
0x140002ee7  test    al, al
0x140002ee9  jnz     short loc_140002EEF
0x140002eeb  xor     al, al
0x140002eed  jmp     short loc_140002F01
0x140002eef  call    __vcrt_initialize_ptd
0x140002ef4  test    al, al
0x140002ef6  jnz     short loc_140002EFF
0x140002ef8  call    __vcrt_uninitialize_locks
0x140002efd  jmp     short loc_140002EEB
0x140002eff  mov     al, 1
0x140002f01  add     rsp, 28h
0x140002f05  retn

// ===== __vcrt_uninitialize @ 0x140002f08 =====

0x140002f08  sub     rsp, 28h
0x140002f0c  test    cl, cl
0x140002f0e  jnz     short loc_140002F21
0x140002f10  call    __vcrt_uninitialize_ptd
0x140002f15  call    __vcrt_uninitialize_locks
0x140002f1a  xor     ecx, ecx
0x140002f1c  call    __vcrt_uninitialize_winapi_thunks
0x140002f21  mov     al, 1
0x140002f23  add     rsp, 28h
0x140002f27  retn

// ===== sub_140002F40 @ 0x140002f40 =====

0x140002f40  push    rdi
0x140002f41  mov     eax, edx
0x140002f43  mov     rdi, rcx
0x140002f46  mov     rcx, r8
0x140002f49  rep stosb
0x140002f4b  mov     rax, r11
0x140002f4e  pop     rdi
0x140002f4f  retn

// ===== sub_140002F60 @ 0x140002f60 =====

0x140002f60  mov     r11, rcx
0x140002f63  movzx   edx, dl
0x140002f66  mov     r9, 101010101010101h
0x140002f70  imul    r9, rdx
0x140002f74  cmp     r8, 10h; switch 17 cases
0x140002f78  jbe     loc_140003070
0x140002f7e  movq    xmm0, r9; jumptable 000000014000308B default case
0x140002f83  punpcklbw xmm0, xmm0
0x140002f87  cmp     r8, 80h
0x140002f8e  ja      short loc_140002FA0
0x140002f90  jmp     loc_140003000
0x140002fa0  bt      cs:dword_14001CF00, 1
0x140002fa8  jb      short sub_140002F40
0x140002faa  movups  xmmword ptr [rcx], xmm0
0x140002fad  add     r8, rcx
0x140002fb0  add     rcx, 10h
0x140002fb4  and     rcx, 0FFFFFFFFFFFFFFF0h
0x140002fb8  sub     r8, rcx
0x140002fbb  mov     r9, r8
0x140002fbe  shr     r9, 7
0x140002fc2  jz      short loc_140003000
0x140002fc4  nop     word ptr [rax+rax+00000000h]
0x140002fd0  movaps  xmmword ptr [rcx], xmm0
0x140002fd3  movaps  xmmword ptr [rcx+10h], xmm0
0x140002fd7  add     rcx, 80h
0x140002fde  movaps  xmmword ptr [rcx-60h], xmm0
0x140002fe2  movaps  xmmword ptr [rcx-50h], xmm0
0x140002fe6  dec     r9
0x140002fe9  movaps  xmmword ptr [rcx-40h], xmm0
0x140002fed  movaps  xmmword ptr [rcx-30h], xmm0
0x140002ff1  movaps  xmmword ptr [rcx-20h], xmm0
0x140002ff5  movapd  xmmword ptr [rcx-10h], xmm0
0x140002ffa  jnz     short loc_140002FD0
0x140002ffc  and     r8, 7Fh
0x140003000  mov     r9, r8
0x140003003  shr     r9, 4
0x140003007  jz      short loc_14000301C
0x140003009  nop     dword ptr [rax+00000000h]
0x140003010  movups  xmmword ptr [rcx], xmm0
0x140003013  add     rcx, 10h
0x140003017  dec     r9
0x14000301a  jnz     short loc_140003010
0x14000301c  and     r8, 0Fh
0x140003020  jz      short loc_140003028
0x140003022  movups  xmmword ptr [rcx+r8-10h], xmm0
0x140003028  mov     rax, r11
0x14000302b  retn
0x140003070  mov     rdx, r9
0x140003073  lea     r9, cs:140000000h
0x14000307a  mov     eax, ds:(jpt_14000308B - 140000000h)[r9+r8*4]
0x140003082  add     r9, rax
0x140003085  add     rcx, r8
0x140003088  mov     rax, r11
0x14000308b  jmp     r9; switch jump
0x140003090  mov     [rcx-0Fh], rdx; jumptable 000000014000308B case 15
0x140003094  mov     [rcx-7], edx; jumptable 000000014000308B case 7
0x140003097  mov     [rcx-3], dx; jumptable 000000014000308B case 3
0x14000309b  mov     [rcx-1], dl; jumptable 000000014000308B case 1
0x14000309e  retn; jumptable 000000014000308B case 0
0x1400030a0  mov     [rcx-0Ch], rdx; jumptable 000000014000308B case 12
0x1400030a4  mov     [rcx-4], edx; jumptable 000000014000308B case 4
0x1400030a7  retn
0x1400030a8  mov     [rcx-9], rdx; jumptable 000000014000308B case 9
0x1400030ac  mov     [rcx-1], dl
0x1400030af  retn
0x1400030b0  mov     [rcx-0Dh], rdx; jumptable 000000014000308B case 13
0x1400030b4  mov     [rcx-5], edx; jumptable 000000014000308B case 5
0x1400030b7  mov     [rcx-1], dl
0x1400030ba  retn
0x1400030c0  mov     [rcx-0Eh], rdx; jumptable 000000014000308B case 14
0x1400030c4  mov     [rcx-6], edx; jumptable 000000014000308B case 6
0x1400030c7  mov     [rcx-2], dx; jumptable 000000014000308B case 2
0x1400030cb  retn
0x1400030cc  mov     [rax], rdx; jumptable 000000014000308B case 8
0x1400030cf  retn
0x1400030d0  mov     [rax], rdx; jumptable 000000014000308B case 11
0x1400030d3  mov     [rax+8], dx
0x1400030d7  mov     [rax+0Ah], dl
0x1400030da  retn
0x1400030e0  mov     [rax], rdx; jumptable 000000014000308B case 10
0x1400030e3  mov     [rax+8], dx
0x1400030e7  retn
0x1400030e8  mov     [rax], rdx; jumptable 000000014000308B case 16
0x1400030eb  mov     [rax+8], rdx
0x1400030ef  retn

// ===== _NLG_Notify @ 0x140003100 =====

0x140003100  mov     [rsp+arg_0], rcx
0x140003105  mov     [rsp+arg_10], rdx
0x14000310a  mov     [rsp+arg_8], r8d
0x14000310f  mov     r9, 19930520h
0x140003116  jmp     short __NLG_Dispatch2
0x140003120  retn

// ===== __NLG_Return2 @ 0x140003130 =====

0x140003130  retn

// ===== __except_validate_context_record @ 0x140003134 =====

0x140003134  mov     rax, cs:__guard_check_icall_fptr
0x14000313b  lea     rdx, _guard_check_icall_nop
0x140003142  cmp     rax, rdx
0x140003145  jz      short locret_14000316A
0x140003147  mov     rax, gs:30h
0x140003150  mov     rcx, [rcx+98h]
0x140003157  cmp     rcx, [rax+10h]
0x14000315b  jb      short loc_140003163
0x14000315d  cmp     rcx, [rax+8]
0x140003161  jbe     short locret_14000316A
0x140003163  mov     ecx, 0Dh
0x140003168  int     29h; Win8: RtlFailFast(ecx)
0x14000316a  retn

// ===== __DestructExceptionObject @ 0x14000316c =====

0x14000316c  test    rcx, rcx
0x14000316f  jz      short locret_1400031D6
0x140003171  mov     [rsp+arg_8], dl
0x140003175  sub     rsp, 28h
0x140003179  cmp     dword ptr [rcx], 0E06D7363h
0x14000317f  jnz     short loc_1400031D2
0x140003181  cmp     dword ptr [rcx+18h], 4
0x140003185  jnz     short loc_1400031D2
0x140003187  mov     eax, [rcx+20h]
0x14000318a  sub     eax, 19930520h
0x14000318f  cmp     eax, 2
0x140003192  ja      short loc_1400031D2
0x140003194  mov     rax, [rcx+30h]
0x140003198  test    rax, rax
0x14000319b  jz      short loc_1400031D2
0x14000319d  movsxd  rdx, dword ptr [rax+4]
0x1400031a1  test    edx, edx
0x1400031a3  jz      short loc_1400031B4
0x1400031a5  add     rdx, [rcx+38h]; void *
0x1400031a9  mov     rcx, [rcx+28h]; void *
0x1400031ad  call    ?_CallMemberFunction0@@YAXQEAX0@Z
0x1400031b2  jmp     short loc_1400031D2
0x1400031b4  test    byte ptr [rax], 10h
0x1400031b7  jz      short loc_1400031D2
0x1400031b9  mov     rax, [rcx+28h]
0x1400031bd  mov     rcx, [rax]
0x1400031c0  test    rcx, rcx
0x1400031c3  jz      short loc_1400031D2
0x1400031c5  mov     rax, [rcx]
0x1400031c8  mov     rax, [rax+10h]
0x1400031cc  call    cs:__guard_dispatch_icall_fptr
0x1400031d2  add     rsp, 28h
0x1400031d6  retn
0x1400031d7  call    terminate
0x1400109d6  push    rbp
0x1400109d8  sub     rsp, 20h
0x1400109dc  mov     rbp, rdx
0x1400109df  xor     eax, eax
0x1400109e1  cmp     [rbp+38h], al
0x1400109e4  setnz   al
0x1400109e7  add     rsp, 20h
0x1400109eb  pop     rbp
0x1400109ec  retn

// ===== ?_CallMemberFunction0@@YAXQEAX0@Z @ 0x1400031e0 =====

0x1400031e0  jmp     rdx

// ===== __vcrt_freefls @ 0x1400031e4 =====

0x1400031e4  sub     rsp, 28h
0x1400031e8  test    rcx, rcx
0x1400031eb  jz      short loc_1400031FE
0x1400031ed  lea     rax, unk_14001CF10
0x1400031f4  cmp     rcx, rax
0x1400031f7  jz      short loc_1400031FE
0x1400031f9  call    j__free_base
0x1400031fe  add     rsp, 28h
0x140003202  retn

// ===== __vcrt_initialize_ptd @ 0x140003204 =====

0x140003204  sub     rsp, 28h
0x140003208  lea     rcx, __vcrt_freefls
0x14000320f  call    __vcrt_FlsAlloc
0x140003214  mov     cs:dword_14001C030, eax
0x14000321a  cmp     eax, 0FFFFFFFFh
0x14000321d  jz      short loc_14000324E
0x14000321f  lea     rdx, unk_14001CF10; lpTlsValue
0x140003226  mov     ecx, eax; dwTlsIndex
0x140003228  call    __vcrt_FlsSetValue
0x14000322d  test    eax, eax
0x14000322f  jz      short loc_140003249
0x140003231  mov     rax, 0FFFFFFFFFFFFFFFEh
0x140003238  mov     cs:dword_14001CF88, eax
0x14000323e  mov     cs:qword_14001CF90, rax
0x140003245  mov     al, 1
0x140003247  jmp     short loc_140003250
0x140003249  call    __vcrt_uninitialize_ptd
0x14000324e  xor     al, al
0x140003250  add     rsp, 28h
0x140003254  retn

// ===== __vcrt_uninitialize_ptd @ 0x140003258 =====

0x140003258  sub     rsp, 28h
0x14000325c  mov     ecx, cs:dword_14001C030
0x140003262  cmp     ecx, 0FFFFFFFFh
0x140003265  jz      short loc_140003273
0x140003267  call    __vcrt_FlsFree
0x14000326c  or      cs:dword_14001C030, 0FFFFFFFFh
0x140003273  mov     al, 1
0x140003275  add     rsp, 28h
0x140003279  retn

// ===== __vcrt_initialize_locks @ 0x14000327c =====

0x14000327c  push    rbx
0x14000327e  sub     rsp, 20h
0x140003282  xor     ebx, ebx
0x140003284  lea     rdx, unk_14001CFA0
0x14000328b  xor     r8d, r8d
0x14000328e  lea     rcx, [rbx+rbx*4]
0x140003292  lea     rcx, [rdx+rcx*8]; lpCriticalSection
0x140003296  mov     edx, 0FA0h; dwSpinCount
0x14000329b  call    __vcrt_InitializeCriticalSectionEx
0x1400032a0  test    eax, eax
0x1400032a2  jz      short loc_1400032B5
0x1400032a4  inc     cs:dword_14001CFC8
0x1400032aa  inc     ebx
0x1400032ac  cmp     ebx, 1
0x1400032af  jb      short loc_140003284
0x1400032b1  mov     al, 1
0x1400032b3  jmp     short loc_1400032BC
0x1400032b5  call    __vcrt_uninitialize_locks
0x1400032ba  xor     al, al
0x1400032bc  add     rsp, 20h
0x1400032c0  pop     rbx
0x1400032c1  retn

// ===== __vcrt_uninitialize_locks @ 0x1400032c4 =====

0x1400032c4  push    rbx
0x1400032c6  sub     rsp, 20h
0x1400032ca  mov     ebx, cs:dword_14001CFC8
0x1400032d0  jmp     short loc_1400032EF
0x1400032d2  lea     rax, unk_14001CFA0
0x1400032d9  dec     ebx
0x1400032db  lea     rcx, [rbx+rbx*4]
0x1400032df  lea     rcx, [rax+rcx*8]; lpCriticalSection
0x1400032e3  call    cs:DeleteCriticalSection; KERNEL32
0x1400032e9  dec     cs:dword_14001CFC8
0x1400032ef  test    ebx, ebx
0x1400032f1  jnz     short loc_1400032D2
0x1400032f3  mov     al, 1
0x1400032f5  add     rsp, 20h
0x1400032f9  pop     rbx
0x1400032fa  retn

// ===== ?try_get_function@@YAPEAXW4function_id@?A0x37284e77@@QEBDQEBW4module_id@2@2@Z @ 0x1400032fc =====

0x1400032fc  mov     [rsp+arg_0], rbx
0x140003301  mov     [rsp+arg_8], rbp
0x140003306  mov     [rsp+arg_10], rsi
0x14000330b  push    rdi
0x14000330c  push    r12
0x14000330e  push    r13
0x140003310  push    r14
0x140003312  push    r15
0x140003314  sub     rsp, 20h
0x140003318  mov     r15d, ecx
0x14000331b  lea     r14, cs:140000000h
0x140003322  mov     r12, r9
0x140003325  mov     rbp, r8
0x140003328  mov     r13, rdx
0x14000332b  mov     rcx, rva qword_14001CFE8[r14+r15*8]
0x140003333  mov     r10, cs:__security_cookie
0x14000333a  or      rdi, 0FFFFFFFFFFFFFFFFh
0x14000333e  mov     eax, r10d
0x140003341  mov     rdx, r10
0x140003344  xor     rdx, rcx
0x140003347  and     eax, 3Fh
0x14000334a  mov     cl, al
0x14000334c  ror     rdx, cl
0x14000334f  cmp     rdx, rdi
0x140003352  jz      loc_1400034B3
0x140003358  test    rdx, rdx
0x14000335b  jz      short loc_140003365
0x14000335d  mov     rax, rdx
0x140003360  jmp     loc_1400034B5
0x140003365  cmp     r8, r12
0x140003368  jz      loc_140003447
0x14000336e  mov     esi, [rbp+0]
0x140003371  mov     rbx, rva qword_14001CFD0[r14+rsi*8]
0x140003379  test    rbx, rbx
0x14000337c  jz      short loc_14000338C
0x14000337e  cmp     rbx, rdi
0x140003381  jz      loc_140003433
0x140003387  jmp     loc_14000342E
0x14000338c  mov     r14, ds:rva off_140011418[r14+rsi*8]
0x140003394  xor     edx, edx; hFile
0x140003396  mov     rcx, r14; lpLibFileName
0x140003399  mov     r8d, 800h; dwFlags
0x14000339f  call    cs:LoadLibraryExW; KERNEL32
0x1400033a5  mov     rbx, rax
0x1400033a8  test    rax, rax
0x1400033ab  jnz     short loc_1400033FC
0x1400033ad  call    cs:GetLastError; KERNEL32
0x1400033b3  cmp     eax, 57h ; 'W'
0x1400033b6  jnz     short loc_1400033FA
0x1400033b8  lea     ebx, [rax-50h]
0x1400033bb  mov     rcx, r14; String1
0x1400033be  mov     r8d, ebx; MaxCount
0x1400033c1  lea     rdx, aApiMs
0x1400033c8  call    wcsncmp
0x1400033cd  test    eax, eax
0x1400033cf  jz      short loc_1400033FA
0x1400033d1  mov     r8d, ebx; MaxCount
0x1400033d4  lea     rdx, aExtMs
0x1400033db  mov     rcx, r14; String1
0x1400033de  call    wcsncmp
0x1400033e3  test    eax, eax
0x1400033e5  jz      short loc_1400033FA
0x1400033e7  xor     r8d, r8d; dwFlags
0x1400033ea  xor     edx, edx; hFile
0x1400033ec  mov     rcx, r14; lpLibFileName
0x1400033ef  call    cs:LoadLibraryExW; KERNEL32
0x1400033f5  mov     rbx, rax
0x1400033f8  jmp     short loc_1400033FC
0x1400033fa  xor     ebx, ebx
0x1400033fc  lea     r14, cs:140000000h
0x140003403  test    rbx, rbx
0x140003406  jnz     short loc_140003415
0x140003408  mov     rax, rdi
0x14000340b  xchg    rax, rva qword_14001CFD0[r14+rsi*8]
0x140003413  jmp     short loc_140003433
0x140003415  mov     rax, rbx
0x140003418  xchg    rax, rva qword_14001CFD0[r14+rsi*8]
0x140003420  test    rax, rax
0x140003423  jz      short loc_14000342E
0x140003425  mov     rcx, rbx; hLibModule
0x140003428  call    cs:FreeLibrary; KERNEL32
0x14000342e  test    rbx, rbx
0x140003431  jnz     short loc_140003488
0x140003433  add     rbp, 4
0x140003437  cmp     rbp, r12
0x14000343a  jnz     loc_14000336E
0x140003440  mov     r10, cs:__security_cookie
0x140003447  xor     ebx, ebx
0x140003449  test    rbx, rbx
0x14000344c  jz      short loc_140003498
0x14000344e  mov     rdx, r13; lpProcName
0x140003451  mov     rcx, rbx; hModule
0x140003454  call    cs:GetProcAddress; KERNEL32
0x14000345a  test    rax, rax
0x14000345d  jz      short loc_140003491
0x14000345f  mov     r8, cs:__security_cookie
0x140003466  mov     edx, 40h ; '@'
0x14000346b  mov     ecx, r8d
0x14000346e  and     ecx, 3Fh
0x140003471  sub     edx, ecx
0x140003473  mov     cl, dl
0x140003475  mov     rdx, rax
0x140003478  ror     rdx, cl
0x14000347b  xor     rdx, r8
0x14000347e  xchg    rdx, rva qword_14001CFE8[r14+r15*8]
0x140003486  jmp     short loc_1400034B5
0x140003488  mov     r10, cs:__security_cookie
0x14000348f  jmp     short loc_140003449
0x140003491  mov     r10, cs:__security_cookie
0x140003498  mov     eax, r10d
0x14000349b  mov     ecx, 40h ; '@'
0x1400034a0  and     eax, 3Fh
0x1400034a3  sub     ecx, eax
0x1400034a5  ror     rdi, cl
0x1400034a8  xor     rdi, r10
0x1400034ab  xchg    rdi, rva qword_14001CFE8[r14+r15*8]
0x1400034b3  xor     eax, eax
0x1400034b5  mov     rbx, [rsp+48h+arg_0]
0x1400034ba  mov     rbp, [rsp+48h+arg_8]
0x1400034bf  mov     rsi, [rsp+48h+arg_10]
0x1400034c4  add     rsp, 20h
0x1400034c8  pop     r15
0x1400034ca  pop     r14
0x1400034cc  pop     r13
0x1400034ce  pop     r12
0x1400034d0  pop     rdi
0x1400034d1  retn

// ===== __vcrt_FlsAlloc @ 0x1400034d4 =====

0x1400034d4  push    rbx
0x1400034d6  sub     rsp, 20h
0x1400034da  mov     rbx, rcx
0x1400034dd  lea     r9, aFlsalloc
0x1400034e4  xor     ecx, ecx
0x1400034e6  lea     r8, unk_1400114E8
0x1400034ed  lea     rdx, aFlsalloc
0x1400034f4  call    ?try_get_function@@YAPEAXW4function_id@?A0x37284e77@@QEBDQEBW4module_id@2@2@Z
0x1400034f9  test    rax, rax
0x1400034fc  jz      short loc_14000350D
0x1400034fe  mov     rcx, rbx
0x140003501  add     rsp, 20h
0x140003505  pop     rbx
0x140003506  jmp     cs:__guard_dispatch_icall_fptr
0x14000350d  add     rsp, 20h
0x140003511  pop     rbx
0x140003512  jmp     cs:TlsAlloc; KERNEL32

// ===== __vcrt_FlsFree @ 0x14000351c =====

0x14000351c  push    rbx
0x14000351e  sub     rsp, 20h
0x140003522  mov     ebx, ecx
0x140003524  lea     r9, aFlsfree
0x14000352b  mov     ecx, 1
0x140003530  lea     r8, unk_140011500
0x140003537  lea     rdx, aFlsfree
0x14000353e  call    ?try_get_function@@YAPEAXW4function_id@?A0x37284e77@@QEBDQEBW4module_id@2@2@Z
0x140003543  mov     ecx, ebx
0x140003545  test    rax, rax
0x140003548  jz      short loc_140003556
0x14000354a  add     rsp, 20h
0x14000354e  pop     rbx
0x14000354f  jmp     cs:__guard_dispatch_icall_fptr
0x140003556  add     rsp, 20h
0x14000355a  pop     rbx
0x14000355b  jmp     cs:TlsFree; KERNEL32

// ===== __vcrt_FlsSetValue @ 0x140003564 =====

0x140003564  mov     [rsp+arg_0], rbx
0x140003569  push    rdi
0x14000356a  sub     rsp, 20h
0x14000356e  mov     rbx, rdx
0x140003571  lea     r9, aFlssetvalue
0x140003578  mov     edi, ecx
0x14000357a  lea     rdx, aFlssetvalue
0x140003581  mov     ecx, 3
0x140003586  lea     r8, unk_140011510
0x14000358d  call    ?try_get_function@@YAPEAXW4function_id@?A0x37284e77@@QEBDQEBW4module_id@2@2@Z
0x140003592  mov     rdx, rbx; lpTlsValue
0x140003595  mov     ecx, edi; dwTlsIndex
0x140003597  test    rax, rax
0x14000359a  jz      short loc_1400035A4
0x14000359c  call    cs:__guard_dispatch_icall_fptr
0x1400035a2  jmp     short loc_1400035AA
0x1400035a4  call    cs:TlsSetValue; KERNEL32
0x1400035aa  mov     rbx, [rsp+28h+arg_0]
0x1400035af  add     rsp, 20h
0x1400035b3  pop     rdi
0x1400035b4  retn

// ===== __vcrt_InitializeCriticalSectionEx @ 0x1400035b8 =====

0x1400035b8  mov     [rsp+arg_0], rbx
0x1400035bd  mov     [rsp+arg_8], rsi
0x1400035c2  push    rdi
0x1400035c3  sub     rsp, 20h
0x1400035c7  mov     esi, r8d
0x1400035ca  lea     r9, aInitializecrit
0x1400035d1  mov     ebx, edx
0x1400035d3  lea     r8, unk_140011528
0x1400035da  mov     rdi, rcx
0x1400035dd  lea     rdx, aInitializecrit
0x1400035e4  mov     ecx, 4
0x1400035e9  call    ?try_get_function@@YAPEAXW4function_id@?A0x37284e77@@QEBDQEBW4module_id@2@2@Z
0x1400035ee  mov     edx, ebx; dwSpinCount
0x1400035f0  mov     rcx, rdi; lpCriticalSection
0x1400035f3  test    rax, rax
0x1400035f6  jz      short loc_140003603
0x1400035f8  mov     r8d, esi
0x1400035fb  call    cs:__guard_dispatch_icall_fptr
0x140003601  jmp     short loc_140003609
0x140003603  call    cs:InitializeCriticalSectionAndSpinCount; KERNEL32
0x140003609  mov     rbx, [rsp+28h+arg_0]
0x14000360e  mov     rsi, [rsp+28h+arg_8]
0x140003613  add     rsp, 20h
0x140003617  pop     rdi
0x140003618  retn

// ===== __vcrt_initialize_winapi_thunks @ 0x14000361c =====

0x14000361c  mov     [rsp+arg_0], rdi
0x140003621  lea     rdi, qword_14001CFE8
0x140003628  lea     rax, qword_14001D010
0x14000362f  cmp     rax, rdi
0x140003632  mov     rax, cs:__security_cookie
0x140003639  sbb     rcx, rcx
0x14000363c  not     rcx
0x14000363f  and     ecx, 5
0x140003642  rep stosq
0x140003645  mov     rdi, [rsp+arg_0]
0x14000364a  retn

// ===== __vcrt_uninitialize_winapi_thunks @ 0x14000364c =====

0x14000364c  test    cl, cl
0x14000364e  jnz     short locret_140003689
0x140003650  push    rbx
0x140003651  sub     rsp, 20h
0x140003655  lea     rbx, qword_14001CFD0
0x14000365c  mov     rcx, [rbx]; hLibModule
0x14000365f  test    rcx, rcx
0x140003662  jz      short loc_140003674
0x140003664  cmp     rcx, 0FFFFFFFFFFFFFFFFh
0x140003668  jz      short loc_140003670
0x14000366a  call    cs:FreeLibrary; KERNEL32
0x140003670  and     qword ptr [rbx], 0
0x140003674  add     rbx, 8
0x140003678  lea     rax, qword_14001CFE8
0x14000367f  cmp     rbx, rax
0x140003682  jnz     short loc_14000365C
0x140003684  add     rsp, 20h
0x140003688  pop     rbx
0x140003689  retn

// ===== __vcrt_initialize_pure_virtual_call_handler @ 0x14000368c =====

0x14000368c  mov     rax, cs:__security_cookie
0x140003693  mov     cs:qword_14001D010, rax
0x14000369a  retn

// ===== sub_1400036B0 @ 0x1400036b0 =====

0x1400036b0  push    rdi
0x1400036b1  push    rsi
0x1400036b2  mov     rax, r11
0x1400036b5  mov     rdi, rcx
0x1400036b8  mov     rcx, r8
0x1400036bb  mov     rsi, r10
0x1400036be  rep movsb
0x1400036c0  pop     rsi
0x1400036c1  pop     rdi
0x1400036c2  retn

// ===== sub_1400036D0 @ 0x1400036d0 =====

0x1400036d0  mov     r11, rcx
0x1400036d3  mov     r10, rdx
0x1400036d6  cmp     r8, 10h; switch 17 cases
0x1400036da  jbe     short loc_140003740
0x1400036dc  cmp     r8, 20h ; ' '; jumptable 0000000140003755 default case
0x1400036e0  jbe     short loc_140003720
0x1400036e2  sub     rdx, rcx
0x1400036e5  jnb     short loc_1400036F4
0x1400036e7  lea     rax, [r8+r10]
0x1400036eb  cmp     rcx, rax
0x1400036ee  jb      loc_140003A20
0x1400036f4  cmp     r8, 80h
0x1400036fb  jbe     loc_140003960
0x140003701  bt      cs:dword_14001CF00, 1
0x140003709  jnb     loc_1400038B0
0x14000370f  jmp     short sub_1400036B0
0x140003720  movups  xmm0, xmmword ptr [rdx]
0x140003723  movups  xmm1, xmmword ptr [rdx+r8-10h]
0x140003729  movups  xmmword ptr [rcx], xmm0
0x14000372c  movups  xmmword ptr [rcx+r8-10h], xmm1
0x140003732  mov     rax, rcx
0x140003735  retn
0x140003740  mov     rax, rcx
0x140003743  lea     r9, cs:140000000h
0x14000374a  mov     ecx, ds:(jpt_140003755 - 140000000h)[r9+r8*4]
0x140003752  add     rcx, r9
0x140003755  jmp     rcx; switch jump
0x1400037a0  retn; jumptable 0000000140003755 case 0
0x1400037a1  movzx   ecx, word ptr [rdx]; jumptable 0000000140003755 case 2
0x1400037a4  mov     [rax], cx
0x1400037a7  retn
0x1400037a8  mov     rcx, [rdx]; jumptable 0000000140003755 case 8
0x1400037ab  mov     [rax], rcx
0x1400037ae  retn
0x1400037af  movzx   ecx, word ptr [rdx]; jumptable 0000000140003755 case 3
0x1400037b2  movzx   r8d, byte ptr [rdx+2]
0x1400037b7  mov     [rax], cx
0x1400037ba  mov     [rax+2], r8b
0x1400037be  retn
0x1400037bf  movzx   ecx, byte ptr [rdx]; jumptable 0000000140003755 case 1
0x1400037c2  mov     [rax], cl
0x1400037c4  retn
0x1400037c5  movdqu  xmm0, xmmword ptr [rdx]; jumptable 0000000140003755 case 16
0x1400037c9  movdqu  xmmword ptr [rax], xmm0
0x1400037cd  retn
0x1400037d0  mov     r8, [rdx]; jumptable 0000000140003755 case 11
0x1400037d3  movzx   ecx, word ptr [rdx+8]
0x1400037d7  movzx   r9d, byte ptr [rdx+0Ah]
0x1400037dc  mov     [rax], r8
0x1400037df  mov     [rax+8], cx
0x1400037e3  mov     [rax+0Ah], r9b
0x1400037e7  retn
0x1400037e8  mov     ecx, [rdx]; jumptable 0000000140003755 case 4
0x1400037ea  mov     [rax], ecx
0x1400037ec  retn
0x1400037f0  mov     ecx, [rdx]; jumptable 0000000140003755 case 5
0x1400037f2  movzx   r8d, byte ptr [rdx+4]
0x1400037f7  mov     [rax], ecx
0x1400037f9  mov     [rax+4], r8b
0x1400037fd  retn
0x140003800  mov     ecx, [rdx]; jumptable 0000000140003755 case 6
0x140003802  movzx   r8d, word ptr [rdx+4]
0x140003807  mov     [rax], ecx
0x140003809  mov     [rax+4], r8w
0x14000380e  retn
0x140003810  mov     ecx, [rdx]; jumptable 0000000140003755 case 7
0x140003812  movzx   r8d, word ptr [rdx+4]
0x140003817  movzx   r9d, byte ptr [rdx+6]
0x14000381c  mov     [rax], ecx
0x14000381e  mov     [rax+4], r8w
0x140003823  mov     [rax+6], r9b
0x140003827  retn
0x140003828  mov     r8, [rdx]; jumptable 0000000140003755 case 13
0x14000382b  mov     ecx, [rdx+8]
0x14000382e  movzx   r9d, byte ptr [rdx+0Ch]
0x140003833  mov     [rax], r8
0x140003836  mov     [rax+8], ecx
0x140003839  mov     [rax+0Ch], r9b
0x14000383d  retn
0x140003840  mov     r8, [rdx]; jumptable 0000000140003755 case 9
0x140003843  movzx   ecx, byte ptr [rdx+8]
0x140003847  mov     [rax], r8
0x14000384a  mov     [rax+8], cl
0x14000384d  retn
0x140003850  mov     r8, [rdx]; jumptable 0000000140003755 case 10
0x140003853  movzx   ecx, word ptr [rdx+8]
0x140003857  mov     [rax], r8
0x14000385a  mov     [rax+8], cx
0x14000385e  retn
0x140003860  mov     r8, [rdx]; jumptable 0000000140003755 case 12
0x140003863  mov     ecx, [rdx+8]
0x140003866  mov     [rax], r8
0x140003869  mov     [rax+8], ecx
0x14000386c  retn
0x140003870  mov     r8, [rdx]; jumptable 0000000140003755 case 14
0x140003873  mov     ecx, [rdx+8]
0x140003876  movzx   r9d, word ptr [rdx+0Ch]
0x14000387b  mov     [rax], r8
0x14000387e  mov     [rax+8], ecx
0x140003881  mov     [rax+0Ch], r9w
0x140003886  retn
0x140003890  mov     r8, [rdx]; jumptable 0000000140003755 case 15
0x140003893  mov     ecx, [rdx+8]
0x140003896  movzx   r9d, word ptr [rdx+0Ch]
0x14000389b  movzx   r10d, byte ptr [rdx+0Eh]
0x1400038a0  mov     [rax], r8
0x1400038a3  mov     [rax+8], ecx
0x1400038a6  mov     [rax+0Ch], r9w
0x1400038ab  mov     [rax+0Eh], r10b
0x1400038af  retn
0x1400038b0  movups  xmm0, xmmword ptr [rcx+rdx]
0x1400038b4  add     r8, rcx
0x1400038b7  add     rcx, 10h
0x1400038bb  test    r11b, 0Fh
0x1400038bf  jz      short loc_1400038D4
0x1400038c1  movaps  xmm1, xmm0
0x1400038c4  and     rcx, 0FFFFFFFFFFFFFFF0h
0x1400038c8  movups  xmm0, xmmword ptr [rcx+rdx]
0x1400038cc  add     rcx, 10h
0x1400038d0  movups  xmmword ptr [r11], xmm1
0x1400038d4  sub     r8, rcx
0x1400038d7  mov     r9, r8
0x1400038da  shr     r9, 7
0x1400038de  jz      loc_14000396C
0x1400038e4  movaps  xmmword ptr [rcx-10h], xmm0
0x1400038e8  cmp     r9, cs:qword_14001C020
0x1400038ef  jbe     short loc_140003908
0x1400038f1  jmp     loc_1400039B8
0x140003900  movaps  xmmword ptr [rcx-20h], xmm0
0x140003904  movaps  xmmword ptr [rcx-10h], xmm1
0x140003908  movups  xmm0, xmmword ptr [rcx+rdx]
0x14000390c  movups  xmm1, xmmword ptr [rcx+rdx+10h]
0x140003911  add     rcx, 80h
0x140003918  movaps  xmmword ptr [rcx-80h], xmm0
0x14000391c  movaps  xmmword ptr [rcx-70h], xmm1
0x140003920  movups  xmm0, xmmword ptr [rcx+rdx-60h]
0x140003925  movups  xmm1, xmmword ptr [rcx+rdx-50h]
0x14000392a  dec     r9
0x14000392d  movaps  xmmword ptr [rcx-60h], xmm0
0x140003931  movaps  xmmword ptr [rcx-50h], xmm1
0x140003935  movups  xmm0, xmmword ptr [rcx+rdx-40h]
0x14000393a  movups  xmm1, xmmword ptr [rcx+rdx-30h]
0x14000393f  movaps  xmmword ptr [rcx-40h], xmm0
0x140003943  movaps  xmmword ptr [rcx-30h], xmm1
0x140003947  movups  xmm0, xmmword ptr [rcx+rdx-20h]
0x14000394c  movups  xmm1, xmmword ptr [rcx+rdx-10h]
0x140003951  jnz     short loc_140003900
0x140003953  movaps  xmmword ptr [rcx-20h], xmm0
0x140003957  and     r8, 7Fh
0x14000395b  movaps  xmm0, xmm1
0x14000395e  jmp     short loc_14000396C
0x140003960  movups  xmm0, xmmword ptr [rcx+rdx]
0x140003964  add     rcx, 10h
0x140003968  sub     r8, 10h
0x14000396c  mov     r9, r8
0x14000396f  shr     r9, 4
0x140003973  jz      short loc_140003991
0x140003975  nop     word ptr [rax+rax+00000000h]
0x140003980  movups  xmmword ptr [rcx-10h], xmm0
0x140003984  movups  xmm0, xmmword ptr [rcx+rdx]
0x140003988  add     rcx, 10h
0x14000398c  dec     r9
0x14000398f  jnz     short loc_140003980
0x140003991  and     r8, 0Fh
0x140003995  jz      short loc_1400039A4
0x140003997  lea     rax, [rcx+r8]
0x14000399b  movups  xmm1, xmmword ptr [rax+rdx-10h]
0x1400039a0  movups  xmmword ptr [rax-10h], xmm1
0x1400039a4  movups  xmmword ptr [rcx-10h], xmm0
0x1400039a8  mov     rax, r11
0x1400039ab  retn
0x1400039b0  movntps xmmword ptr [rcx-20h], xmm0
0x1400039b4  movntps xmmword ptr [rcx-10h], xmm1
0x1400039b8  prefetchnta byte ptr [rcx+rdx+200h]
0x1400039c0  movups  xmm0, xmmword ptr [rcx+rdx]
0x1400039c4  movups  xmm1, xmmword ptr [rcx+rdx+10h]
0x1400039c9  add     rcx, 80h
0x1400039d0  movntps xmmword ptr [rcx-80h], xmm0
0x1400039d4  movntps xmmword ptr [rcx-70h], xmm1
0x1400039d8  movups  xmm0, xmmword ptr [rcx+rdx-60h]
0x1400039dd  movups  xmm1, xmmword ptr [rcx+rdx-50h]
0x1400039e2  dec     r9
0x1400039e5  movntps xmmword ptr [rcx-60h], xmm0
0x1400039e9  movntps xmmword ptr [rcx-50h], xmm1
0x1400039ed  movups  xmm0, xmmword ptr [rcx+rdx-40h]
0x1400039f2  movups  xmm1, xmmword ptr [rcx+rdx-30h]
0x1400039f7  prefetchnta byte ptr [rcx+rdx+240h]
0x1400039ff  movntps xmmword ptr [rcx-40h], xmm0
0x140003a03  movntps xmmword ptr [rcx-30h], xmm1
0x140003a07  movups  xmm0, xmmword ptr [rcx+rdx-20h]
0x140003a0c  movups  xmm1, xmmword ptr [rcx+rdx-10h]
0x140003a11  jnz     short loc_1400039B0
0x140003a13  sfence
0x140003a16  jmp     loc_140003953
0x140003a20  add     rcx, r8
0x140003a23  movups  xmm0, xmmword ptr [rcx+rdx-10h]
0x140003a28  sub     rcx, 10h
0x140003a2c  sub     r8, 10h
0x140003a30  test    cl, 0Fh
0x140003a33  jz      short loc_140003A4C
0x140003a35  mov     rax, rcx
0x140003a38  and     rcx, 0FFFFFFFFFFFFFFF0h
0x140003a3c  movups  xmm1, xmm0
0x140003a3f  movups  xmm0, xmmword ptr [rcx+rdx]
0x140003a43  movups  xmmword ptr [rax], xmm1
0x140003a46  mov     r8, rcx
0x140003a49  sub     r8, r11
0x140003a4c  mov     r9, r8
0x140003a4f  shr     r9, 7
0x140003a53  jz      short loc_140003ABD
0x140003a55  movaps  xmmword ptr [rcx], xmm0
0x140003a58  jmp     short loc_140003A67
0x140003a60  movaps  xmmword ptr [rcx+10h], xmm0
0x140003a64  movaps  xmmword ptr [rcx], xmm1
0x140003a67  movups  xmm0, xmmword ptr [rcx+rdx-10h]
0x140003a6c  movups  xmm1, xmmword ptr [rcx+rdx-20h]
0x140003a71  sub     rcx, 80h
0x140003a78  movaps  xmmword ptr [rcx+70h], xmm0
0x140003a7c  movaps  xmmword ptr [rcx+60h], xmm1
0x140003a80  movups  xmm0, xmmword ptr [rcx+rdx+50h]
0x140003a85  movups  xmm1, xmmword ptr [rcx+rdx+40h]
0x140003a8a  dec     r9
0x140003a8d  movaps  xmmword ptr [rcx+50h], xmm0
0x140003a91  movaps  xmmword ptr [rcx+40h], xmm1
0x140003a95  movups  xmm0, xmmword ptr [rcx+rdx+30h]
0x140003a9a  movups  xmm1, xmmword ptr [rcx+rdx+20h]
0x140003a9f  movaps  xmmword ptr [rcx+30h], xmm0
0x140003aa3  movaps  xmmword ptr [rcx+20h], xmm1
0x140003aa7  movups  xmm0, xmmword ptr [rcx+rdx+10h]
0x140003aac  movups  xmm1, xmmword ptr [rcx+rdx]
0x140003ab0  jnz     short loc_140003A60
0x140003ab2  movaps  xmmword ptr [rcx+10h], xmm0
0x140003ab6  and     r8, 7Fh
0x140003aba  movaps  xmm0, xmm1
0x140003abd  mov     r9, r8
0x140003ac0  shr     r9, 4
0x140003ac4  jz      short loc_140003AE0
0x140003ac6  nop     word ptr [rax+rax+00000000h]
0x140003ad0  movups  xmmword ptr [rcx], xmm0
0x140003ad3  sub     rcx, 10h
0x140003ad7  movups  xmm0, xmmword ptr [rcx+rdx]
0x140003adb  dec     r9
0x140003ade  jnz     short loc_140003AD0
0x140003ae0  and     r8, 0Fh
0x140003ae4  jz      short loc_140003AEE
0x140003ae6  movups  xmm1, xmmword ptr [r10]
0x140003aea  movups  xmmword ptr [r11], xmm1
0x140003aee  movups  xmmword ptr [rcx], xmm0
0x140003af1  mov     rax, r11
0x140003af4  retn

// ===== _CallSettingFrame @ 0x140003b10 =====

0x140003b10  sub     rsp, 28h
0x140003b14  mov     [rsp+28h+arg_0], rcx
0x140003b19  mov     [rsp+28h+arg_8], rdx
0x140003b1e  mov     [rsp+28h+arg_10], r8d
0x140003b23  mov     rdx, [rdx]
0x140003b26  mov     rax, rcx
0x140003b29  call    _NLG_Notify
0x140003b2e  call    rax
0x140003b30  call    __NLG_Return2
0x140003b35  mov     rcx, rax
0x140003b38  mov     rdx, [rsp+28h+arg_8]
0x140003b3d  mov     rdx, [rdx]
0x140003b40  mov     r8d, 2
0x140003b46  call    _NLG_Notify
0x140003b4b  add     rsp, 28h
0x140003b4f  retn

// ===== _CallSettingFrameEncoded @ 0x140003b60 =====

0x140003b60  sub     rsp, 28h
0x140003b64  mov     [rsp+28h+arg_0], rcx
0x140003b69  mov     [rsp+28h+arg_8], rdx
0x140003b6e  mov     [rsp+28h+arg_10], r8
0x140003b73  mov     [rsp+28h+arg_18], r9d
0x140003b78  mov     r8d, r9d
0x140003b7b  mov     rax, rcx
0x140003b7e  call    _NLG_Notify
0x140003b83  mov     rcx, [rsp+28h+arg_10]
0x140003b88  call    rax
0x140003b8a  call    __NLG_Return2
0x140003b8f  mov     rcx, rax
0x140003b92  mov     rdx, [rsp+28h+arg_8]
0x140003b97  mov     r8d, 2
0x140003b9d  call    _NLG_Notify
0x140003ba2  add     rsp, 28h
0x140003ba6  retn

// ===== sub_140003BA8 @ 0x140003ba8 =====

0x140003ba8  mov     [rsp-8+arg_0], rbx
0x140003bad  mov     [rsp-8+arg_18], rsi
0x140003bb2  push    rbp
0x140003bb3  push    rdi
0x140003bb4  push    r12
0x140003bb6  push    r14
0x140003bb8  push    r15
0x140003bba  lea     rbp, [rsp-410h]
0x140003bc2  sub     rsp, 510h
0x140003bc9  mov     rax, cs:__security_cookie
0x140003bd0  xor     rax, rsp
0x140003bd3  mov     [rbp+430h+var_30], rax
0x140003bda  xor     r12d, r12d
0x140003bdd  mov     rbx, r9
0x140003be0  mov     rdi, r8
0x140003be3  mov     rsi, rdx
0x140003be6  mov     r15, rcx
0x140003be9  test    r9, r9
0x140003bec  jnz     short loc_140003C06
0x140003bee  call    _errno
0x140003bf3  mov     dword ptr [rax], 16h
0x140003bf9  call    _invalid_parameter_noinfo
0x140003bfe  or      eax, 0FFFFFFFFh
0x140003c01  jmp     loc_140003D10
0x140003c06  test    r8, r8
0x140003c09  jz      short loc_140003C10
0x140003c0b  test    rdx, rdx
0x140003c0e  jz      short loc_140003BEE
0x140003c10  mov     rdx, [rbp+430h+arg_20]; struct __crt_locale_pointers *
0x140003c17  lea     rcx, [rsp+530h+var_4D8]; this
0x140003c1c  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z; _LocaleUpdate::_LocaleUpdate(__crt_locale_pointers * const)
0x140003c21  xor     edx, edx
0x140003c23  lea     rcx, [rsp+530h+var_500]
0x140003c28  lea     r8d, [rdx+20h]
0x140003c2c  call    sub_140002F60
0x140003c31  mov     r14, r15
0x140003c34  mov     [rsp+530h+var_500], rsi
0x140003c39  mov     [rsp+530h+var_4F8], rdi
0x140003c3e  mov     [rsp+530h+var_4F0], r12
0x140003c43  and     r14d, 2
0x140003c47  jnz     short loc_140003C53
0x140003c49  mov     [rsp+530h+var_4E8], r12b
0x140003c4e  test    rsi, rsi
0x140003c51  jnz     short loc_140003C58
0x140003c53  mov     [rsp+530h+var_4E8], 1
0x140003c58  lea     rax, [rsp+530h+var_500]
0x140003c5d  mov     r9, rbx
0x140003c60  mov     [rsp+530h+var_4E0], rax
0x140003c65  lea     rdx, [rsp+530h+var_4E0]
0x140003c6a  mov     rax, [rbp+430h+arg_28]
0x140003c71  lea     rcx, [rbp+430h+var_4B0]
0x140003c75  mov     [rsp+530h+var_508], rax
0x140003c7a  mov     r8, r15
0x140003c7d  lea     rax, [rsp+530h+var_4D0]
0x140003c82  mov     [rsp+530h+var_510], rax
0x140003c87  call    unknown_libname_5; Microsoft VisualC 64bit universal runtime
0x140003c8c  lea     rcx, [rbp+430h+var_4B0]
0x140003c90  call    ?process@?$output_processor@_WV?$string_output_adapter@_W@__crt_stdio_output@@V?$format_validation_base@_WV?$string_output_adapter@_W@__crt_stdio_output@@@2@@__crt_stdio_output@@QEAAHXZ; __crt_stdio_output::output_processor<wchar_t,__crt_stdio_output::string_output_adapter<wchar_t>,__crt_stdio_output::format_validation_base<wchar_t,__crt_stdio_output::string_output_adapter<wchar_t>>>::process(void)
0x140003c95  movsxd  rbx, eax
0x140003c98  test    rsi, rsi
0x140003c9b  jz      short loc_140003CE8
0x140003c9d  test    r15b, 1
0x140003ca1  jz      short loc_140003CC5
0x140003ca3  test    rdi, rdi
0x140003ca6  jnz     short loc_140003CB0
0x140003ca8  test    eax, eax
0x140003caa  jnz     loc_140003D40
0x140003cb0  mov     rax, [rsp+530h+var_4F0]
0x140003cb5  cmp     rax, rdi
0x140003cb8  jnz     short loc_140003CE3
0x140003cba  test    ebx, ebx
0x140003cbc  js      short loc_140003CE8
0x140003cbe  cmp     rbx, rdi
0x140003cc1  jbe     short loc_140003CE8
0x140003cc3  jmp     short loc_140003D40
0x140003cc5  test    r14, r14
0x140003cc8  jz      short loc_140003D3B
0x140003cca  test    rdi, rdi
0x140003ccd  jz      short loc_140003CE8
0x140003ccf  test    eax, eax
0x140003cd1  jns     short loc_140003CD9
0x140003cd3  mov     [rsi], r12w
0x140003cd7  jmp     short loc_140003CE8
0x140003cd9  mov     rax, [rsp+530h+var_4F0]
0x140003cde  cmp     rax, rdi
0x140003ce1  jz      short loc_140003D54
0x140003ce3  mov     [rsi+rax*2], r12w
0x140003ce8  mov     rcx, [rbp+430h+Block]; Block
0x140003cef  call    _free_base
0x140003cf4  mov     [rbp+430h+Block], r12
0x140003cfb  cmp     [rsp+530h+var_4C0], r12b
0x140003d00  jz      short loc_140003D0E
0x140003d02  mov     rcx, [rsp+530h+var_4D8]
0x140003d07  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x140003d0e  mov     eax, ebx
0x140003d10  mov     rcx, [rbp+430h+var_30]
0x140003d17  xor     rcx, rsp; StackCookie
0x140003d1a  call    __security_check_cookie
0x140003d1f  lea     r11, [rsp+530h+var_20]
0x140003d27  mov     rbx, [r11+30h]
0x140003d2b  mov     rsi, [r11+48h]
0x140003d2f  mov     rsp, r11
0x140003d32  pop     r15
0x140003d34  pop     r14
0x140003d36  pop     r12
0x140003d38  pop     rdi
0x140003d39  pop     rbp
0x140003d3a  retn
0x140003d3b  test    rdi, rdi
0x140003d3e  jnz     short loc_140003D45
0x140003d40  or      ebx, 0FFFFFFFFh
0x140003d43  jmp     short loc_140003CE8
0x140003d45  mov     rax, [rsp+530h+var_4F0]
0x140003d4a  cmp     rax, rdi
0x140003d4d  jnz     short loc_140003CE3
0x140003d4f  mov     ebx, 0FFFFFFFEh
0x140003d54  mov     [rsi+rdi*2-2], r12w
0x140003d5a  jmp     short loc_140003CE8

// ===== ??$ensure_buffer_is_big_enough@D@formatting_buffer@__crt_stdio_output@@QEAA_N_K@Z @ 0x140003d5c =====

0x140003d5c  mov     [rsp+arg_0], rbx
0x140003d61  mov     [rsp+arg_8], rbp
0x140003d66  mov     [rsp+arg_10], rsi
0x140003d6b  push    rdi
0x140003d6c  sub     rsp, 20h
0x140003d70  or      rax, 0FFFFFFFFFFFFFFFFh
0x140003d74  mov     rsi, rdx
0x140003d77  xor     edx, edx
0x140003d79  mov     rbp, rcx
0x140003d7c  div     rsi
0x140003d7f  and     rax, 0FFFFFFFFFFFFFFFEh
0x140003d83  cmp     rax, 2
0x140003d87  jnb     short loc_140003D98
0x140003d89  call    _errno
0x140003d8e  mov     dword ptr [rax], 0Ch
0x140003d94  xor     al, al
0x140003d96  jmp     short loc_140003DF3
0x140003d98  add     rsi, rsi
0x140003d9b  xor     edi, edi
0x140003d9d  cmp     [rcx+408h], rdi
0x140003da4  jnz     short loc_140003DB3
0x140003da6  cmp     rsi, 400h
0x140003dad  ja      short loc_140003DB3
0x140003daf  mov     al, 1
0x140003db1  jmp     short loc_140003DF3
0x140003db3  cmp     rsi, [rcx+400h]
0x140003dba  jbe     short loc_140003DAF
0x140003dbc  mov     rcx, rsi; Size
0x140003dbf  call    _malloc_base
0x140003dc4  mov     rbx, rax
0x140003dc7  test    rax, rax
0x140003dca  jz      short loc_140003DE9
0x140003dcc  mov     rcx, [rbp+408h]; Block
0x140003dd3  call    _free_base
0x140003dd8  mov     [rbp+408h], rbx
0x140003ddf  mov     dil, 1
0x140003de2  mov     [rbp+400h], rsi
0x140003de9  xor     ecx, ecx; Block
0x140003deb  call    _free_base
0x140003df0  mov     al, dil
0x140003df3  mov     rbx, [rsp+28h+arg_0]
0x140003df8  mov     rbp, [rsp+28h+arg_8]
0x140003dfd  mov     rsi, [rsp+28h+arg_10]
0x140003e02  add     rsp, 20h
0x140003e06  pop     rdi
0x140003e07  retn

// ===== ??$is_wide_character_specifier@_W@__crt_stdio_output@@YA_N_K_WW4length_modifier@0@@Z @ 0x140003e08 =====

0x140003e08  mov     r9d, r8d
0x140003e0b  mov     r10, rcx
0x140003e0e  sub     r9d, 2
0x140003e12  jz      short loc_140003E49
0x140003e14  sub     r9d, 1
0x140003e18  jz      short loc_140003E46
0x140003e1a  cmp     r9d, 9
0x140003e1e  jz      short loc_140003E46
0x140003e20  cmp     r8d, 0Dh
0x140003e24  jz      short loc_140003E46
0x140003e26  shr     r10b, 2
0x140003e2a  sub     dx, 63h ; 'c'
0x140003e2e  and     r10b, 1
0x140003e32  mov     eax, 0FFEFh
0x140003e37  test    ax, dx
0x140003e3a  setz    cl
0x140003e3d  xor     eax, eax
0x140003e3f  cmp     r10b, cl
0x140003e42  setz    al
0x140003e45  retn
0x140003e46  mov     al, 1
0x140003e48  retn
0x140003e49  xor     al, al
0x140003e4b  retn

// ===== unknown_libname_3 @ 0x140003e4c =====

0x140003e4c  mov     [rsp+arg_0], rbx
0x140003e51  lea     rax, [rcx+58h]
0x140003e55  mov     r10, rcx
0x140003e58  mov     rcx, [rax+408h]
0x140003e5f  mov     ebx, r8d
0x140003e62  test    rcx, rcx
0x140003e65  mov     r11d, edx
0x140003e68  cmovz   rcx, rax
0x140003e6c  cmp     qword ptr [rax+408h], 0
0x140003e74  jnz     short loc_140003E7D
0x140003e76  mov     eax, 200h
0x140003e7b  jmp     short loc_140003E87
0x140003e7d  mov     rax, [rax+400h]
0x140003e84  shr     rax, 1
0x140003e87  lea     r8, [rcx-1]
0x140003e8b  add     r8, rax
0x140003e8e  mov     [r10+48h], r8
0x140003e92  mov     eax, [r10+38h]
0x140003e96  test    eax, eax
0x140003e98  jg      short loc_140003E9F
0x140003e9a  test    r11d, r11d
0x140003e9d  jz      short loc_140003ED5
0x140003e9f  dec     eax
0x140003ea1  xor     edx, edx
0x140003ea3  mov     [r10+38h], eax
0x140003ea7  mov     eax, r11d
0x140003eaa  div     ebx
0x140003eac  add     dl, 30h ; '0'
0x140003eaf  mov     r11d, eax
0x140003eb2  cmp     dl, 39h ; '9'
0x140003eb5  jle     short loc_140003EC9
0x140003eb7  mov     al, r9b
0x140003eba  neg     al
0x140003ebc  sbb     cl, cl
0x140003ebe  and     cl, 0E0h
0x140003ec1  add     cl, 61h ; 'a'
0x140003ec4  sub     cl, 3Ah ; ':'
0x140003ec7  add     dl, cl
0x140003ec9  mov     rax, [r10+48h]
0x140003ecd  mov     [rax], dl
0x140003ecf  dec     qword ptr [r10+48h]
0x140003ed3  jmp     short loc_140003E92
0x140003ed5  sub     r8d, [r10+48h]
0x140003ed9  inc     qword ptr [r10+48h]
0x140003edd  mov     rbx, [rsp+arg_0]
0x140003ee2  mov     [r10+50h], r8d
0x140003ee6  retn

// ===== unknown_libname_4 @ 0x140003ee8 =====

0x140003ee8  mov     [rsp+arg_0], rbx
0x140003eed  lea     rax, [rcx+58h]
0x140003ef1  mov     ebx, r8d
0x140003ef4  mov     r10, rcx
0x140003ef7  mov     r11, rdx
0x140003efa  mov     rcx, [rax+408h]
0x140003f01  test    rcx, rcx
0x140003f04  cmovz   rcx, rax
0x140003f08  cmp     qword ptr [rax+408h], 0
0x140003f10  jnz     short loc_140003F19
0x140003f12  mov     eax, 200h
0x140003f17  jmp     short loc_140003F23
0x140003f19  mov     rax, [rax+400h]
0x140003f20  shr     rax, 1
0x140003f23  lea     r8, [rcx-1]
0x140003f27  add     r8, rax
0x140003f2a  mov     [r10+48h], r8
0x140003f2e  mov     eax, [r10+38h]
0x140003f32  test    eax, eax
0x140003f34  jg      short loc_140003F3B
0x140003f36  test    r11, r11
0x140003f39  jz      short loc_140003F72
0x140003f3b  dec     eax
0x140003f3d  xor     edx, edx
0x140003f3f  mov     [r10+38h], eax
0x140003f43  mov     rax, r11
0x140003f46  div     rbx
0x140003f49  add     dl, 30h ; '0'
0x140003f4c  mov     r11, rax
0x140003f4f  cmp     dl, 39h ; '9'
0x140003f52  jle     short loc_140003F66
0x140003f54  mov     al, r9b
0x140003f57  neg     al
0x140003f59  sbb     cl, cl
0x140003f5b  and     cl, 0E0h
0x140003f5e  add     cl, 61h ; 'a'
0x140003f61  sub     cl, 3Ah ; ':'
0x140003f64  add     dl, cl
0x140003f66  mov     rax, [r10+48h]
0x140003f6a  mov     [rax], dl
0x140003f6c  dec     qword ptr [r10+48h]
0x140003f70  jmp     short loc_140003F2E
0x140003f72  sub     r8d, [r10+48h]
0x140003f76  inc     qword ptr [r10+48h]
0x140003f7a  mov     rbx, [rsp+arg_0]
0x140003f7f  mov     [r10+50h], r8d
0x140003f83  retn

// ===== ??$write_multiple_characters@V?$string_output_adapter@_W@__crt_stdio_output@@D@__crt_stdio_output@@YAXAEBV?$string_output_adapter@_W@0@DHQEAH@Z @ 0x140003f84 =====

0x140003f84  test    r8d, r8d
0x140003f87  jle     short locret_140003FF1
0x140003f89  mov     [rsp+arg_0], rbx
0x140003f8e  mov     [rsp+arg_8], rdi
0x140003f93  mov     dil, dl
0x140003f96  mov     rbx, rcx
0x140003f99  xor     r11d, r11d
0x140003f9c  mov     r10, [rbx]
0x140003f9f  mov     rax, [r10+8]
0x140003fa3  cmp     [r10+10h], rax
0x140003fa7  jnz     short loc_140003FBB
0x140003fa9  cmp     byte ptr [r10+18h], 0
0x140003fae  jz      short loc_140003FB5
0x140003fb0  inc     dword ptr [r9]
0x140003fb3  jmp     short loc_140003FD9
0x140003fb5  or      dword ptr [r9], 0FFFFFFFFh
0x140003fb9  jmp     short loc_140003FD9
0x140003fbb  inc     dword ptr [r9]
0x140003fbe  mov     rax, [rbx]
0x140003fc1  movsx   edx, dil
0x140003fc5  inc     qword ptr [rax+10h]
0x140003fc9  mov     rax, [rbx]
0x140003fcc  mov     rcx, [rax]
0x140003fcf  mov     [rcx], dx
0x140003fd2  mov     rax, [rbx]
0x140003fd5  add     qword ptr [rax], 2
0x140003fd9  cmp     dword ptr [r9], 0FFFFFFFFh
0x140003fdd  jz      short loc_140003FE7
0x140003fdf  inc     r11d
0x140003fe2  cmp     r11d, r8d
0x140003fe5  jl      short loc_140003F9C
0x140003fe7  mov     rbx, [rsp+arg_0]
0x140003fec  mov     rdi, [rsp+arg_8]
0x140003ff1  retn

// ===== unknown_libname_5 @ 0x140003ff4 =====

0x140003ff4  push    rbx
0x140003ff6  sub     rsp, 20h
0x140003ffa  mov     rbx, rcx
0x140003ffd  xor     ecx, ecx
0x140003fff  mov     [rbx], rcx
0x140004002  mov     [rbx+8], rcx
0x140004006  mov     [rbx+18h], rcx
0x14000400a  mov     [rbx+20h], rcx
0x14000400e  mov     [rbx+10h], rcx
0x140004012  mov     [rbx+28h], rcx
0x140004016  mov     [rbx+30h], rcx
0x14000401a  mov     [rbx+38h], ecx
0x14000401d  mov     [rbx+40h], cl
0x140004020  mov     [rbx+42h], cx
0x140004024  mov     [rbx+50h], ecx
0x140004027  mov     [rbx+54h], cl
0x14000402a  mov     [rbx+458h], rcx
0x140004031  mov     [rbx+460h], rcx
0x140004038  mov     rax, [rdx]
0x14000403b  mov     [rbx+468h], rax
0x140004042  mov     rax, [rsp+28h+arg_20]
0x140004047  mov     [rbx+8], rax
0x14000404b  mov     rax, [rsp+28h+arg_28]
0x140004050  mov     [rbx+20h], rax
0x140004054  mov     [rbx], r8
0x140004057  mov     [rbx+18h], r9
0x14000405b  mov     [rbx+470h], ecx
0x140004061  call    _errno
0x140004066  mov     [rbx+10h], rax
0x14000406a  mov     rax, rbx
0x14000406d  add     rsp, 20h
0x140004071  pop     rbx
0x140004072  retn

// ===== ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z @ 0x140004074 =====

0x140004074  mov     [rsp+arg_0], rbx
0x140004079  push    rdi
0x14000407a  sub     rsp, 20h
0x14000407e  mov     byte ptr [rcx+18h], 0
0x140004082  mov     rdi, rcx
0x140004085  test    rdx, rdx
0x140004088  jz      short loc_14000408F
0x14000408a  movups  xmm0, xmmword ptr [rdx]
0x14000408d  jmp     short loc_1400040A0
0x14000408f  mov     eax, cs:dword_14001D2E4
0x140004095  test    eax, eax
0x140004097  jnz     short loc_1400040A7
0x140004099  movups  xmm0, xmmword ptr cs:off_14001C2B8
0x1400040a0  movdqu  xmmword ptr [rcx+8], xmm0
0x1400040a5  jmp     short loc_1400040F6
0x1400040a7  call    __acrt_getptd
0x1400040ac  mov     [rdi], rax
0x1400040af  lea     rdx, [rdi+8]
0x1400040b3  mov     rcx, [rax+90h]
0x1400040ba  mov     [rdx], rcx
0x1400040bd  mov     rcx, [rax+88h]
0x1400040c4  mov     [rdi+10h], rcx
0x1400040c8  mov     rcx, rax
0x1400040cb  call    sub_140007FBC
0x1400040d0  mov     rcx, [rdi]
0x1400040d3  lea     rdx, [rdi+10h]
0x1400040d7  call    sub_140007FF0
0x1400040dc  mov     rcx, [rdi]
0x1400040df  mov     eax, [rcx+3A8h]
0x1400040e5  test    al, 2
0x1400040e7  jnz     short loc_1400040F6
0x1400040e9  or      eax, 2
0x1400040ec  mov     [rcx+3A8h], eax
0x1400040f2  mov     byte ptr [rdi+18h], 1
0x1400040f6  mov     rax, rdi
0x1400040f9  mov     rbx, [rsp+28h+arg_0]
0x1400040fe  add     rsp, 20h
0x140004102  pop     rdi
0x140004103  retn

// ===== ?force_decimal_point@__crt_stdio_output@@YAXPEADQEAU__crt_locale_pointers@@@Z @ 0x140004104 =====

0x140004104  mov     [rsp+arg_0], rbx
0x140004109  push    rdi
0x14000410a  sub     rsp, 20h
0x14000410e  mov     rbx, rcx
0x140004111  mov     rdi, rdx
0x140004114  movsx   ecx, byte ptr [rcx]; C
0x140004117  call    tolower
0x14000411c  cmp     eax, 65h ; 'e'
0x14000411f  jz      short loc_140004130
0x140004121  inc     rbx
0x140004124  movzx   ecx, byte ptr [rbx]; C
0x140004127  call    isdigit
0x14000412c  test    eax, eax
0x14000412e  jnz     short loc_140004121
0x140004130  movsx   ecx, byte ptr [rbx]; C
0x140004133  call    tolower
0x140004138  cmp     eax, 78h ; 'x'
0x14000413b  jnz     short loc_140004141
0x14000413d  add     rbx, 2
0x140004141  mov     rax, [rdi]
0x140004144  mov     dl, [rbx]
0x140004146  mov     rcx, [rax+0F8h]
0x14000414d  mov     rax, [rcx]
0x140004150  mov     cl, [rax]
0x140004152  mov     [rbx], cl
0x140004154  inc     rbx
0x140004157  mov     al, [rbx]
0x140004159  mov     [rbx], dl
0x14000415b  mov     dl, al
0x14000415d  mov     al, [rbx]
0x14000415f  inc     rbx
0x140004162  test    al, al
0x140004164  jnz     short loc_140004157
0x140004166  mov     rbx, [rsp+28h+arg_0]
0x14000416b  add     rsp, 20h
0x14000416f  pop     rdi
0x140004170  retn

// ===== unknown_libname_6 @ 0x140004174 =====

0x140004174  mov     rax, rsp
0x140004177  mov     [rax+10h], rbx
0x14000417b  mov     [rax+18h], rbp
0x14000417f  mov     [rax+20h], rsi
0x140004183  push    rdi
0x140004184  sub     rsp, 20h
0x140004188  mov     rsi, [rcx+10h]
0x14000418c  mov     rdi, rcx
0x14000418f  mov     rbx, rdx
0x140004192  mov     r8d, 0Ah; Radix
0x140004198  lea     rdx, [rax+8]; EndPtr
0x14000419c  mov     ebp, [rsi]
0x14000419e  and     dword ptr [rsi], 0
0x1400041a1  mov     rcx, [rcx+18h]
0x1400041a5  and     qword ptr [rax+8], 0
0x1400041aa  sub     rcx, 2; String
0x1400041ae  call    wcstol
0x1400041b3  mov     [rbx], eax
0x1400041b5  mov     rax, [rdi+10h]
0x1400041b9  cmp     dword ptr [rax], 22h ; '"'
0x1400041bc  jz      short loc_1400041D1
0x1400041be  mov     rax, [rsp+28h+arg_0]
0x1400041c3  cmp     rax, [rdi+18h]
0x1400041c7  jb      short loc_1400041D1
0x1400041c9  mov     [rdi+18h], rax
0x1400041cd  mov     al, 1
0x1400041cf  jmp     short loc_1400041D3
0x1400041d1  xor     al, al
0x1400041d3  cmp     dword ptr [rsi], 0
0x1400041d6  jnz     short loc_1400041DE
0x1400041d8  test    ebp, ebp
0x1400041da  jz      short loc_1400041DE
0x1400041dc  mov     [rsi], ebp
0x1400041de  mov     rbx, [rsp+28h+arg_8]
0x1400041e3  mov     rbp, [rsp+28h+arg_10]
0x1400041e8  mov     rsi, [rsp+28h+arg_18]
0x1400041ed  add     rsp, 20h
0x1400041f1  pop     rdi
0x1400041f2  retn

// ===== ?process@?$output_processor@_WV?$string_output_adapter@_W@__crt_stdio_output@@V?$format_validation_base@_WV?$string_output_adapter@_W@__crt_stdio_output@@@2@@__crt_stdio_output@@QEAAHXZ @ 0x1400041f4 =====

0x1400041f4  mov     rax, rsp
0x1400041f7  mov     [rax+8], rbx
0x1400041fb  mov     [rax+10h], rbp
0x1400041ff  mov     [rax+18h], rsi
0x140004203  mov     [rax+20h], rdi
0x140004207  push    r14
0x140004209  sub     rsp, 20h
0x14000420d  xor     esi, esi
0x14000420f  mov     rbx, rcx
0x140004212  cmp     [rcx+468h], rsi
0x140004219  jnz     short loc_140004233
0x14000421b  call    _errno
0x140004220  mov     dword ptr [rax], 16h
0x140004226  call    _invalid_parameter_noinfo
0x14000422b  or      eax, 0FFFFFFFFh
0x14000422e  jmp     loc_14000444B
0x140004233  cmp     [rcx+18h], rsi
0x140004237  jz      short loc_14000421B
0x140004239  inc     dword ptr [rcx+470h]
0x14000423f  cmp     dword ptr [rcx+470h], 2
0x140004246  jz      loc_140004448
0x14000424c  or      edi, 0FFFFFFFFh
0x14000424f  lea     r14, byte_140011F20
0x140004256  lea     ebp, [rdi+21h]
0x140004259  mov     [rbx+50h], esi
0x14000425c  mov     [rbx+2Ch], esi
0x14000425f  jmp     loc_140004411
0x140004264  add     qword ptr [rbx+18h], 2
0x140004269  cmp     [rbx+28h], esi
0x14000426c  jl      loc_14000442A
0x140004272  movzx   eax, word ptr [rbx+42h]
0x140004276  mov     edx, [rbx+2Ch]
0x140004279  sub     ax, bp
0x14000427c  cmp     ax, 5Ah ; 'Z'
0x140004280  ja      short loc_140004291
0x140004282  movzx   eax, word ptr [rbx+42h]
0x140004286  movzx   ecx, byte ptr [rax+r14-20h]
0x14000428c  and     ecx, 0Fh
0x14000428f  jmp     short loc_140004293
0x140004291  mov     ecx, esi
0x140004293  lea     eax, [rdx+rcx*8]
0x140004296  add     ecx, eax
0x140004298  movzx   ecx, byte ptr [rcx+r14]
0x14000429d  shr     ecx, 4
0x1400042a0  mov     [rbx+2Ch], ecx
0x1400042a3  cmp     ecx, 8
0x1400042a6  jz      loc_140004466
0x1400042ac  test    ecx, ecx
0x1400042ae  jz      loc_1400043BC
0x1400042b4  sub     ecx, 1
0x1400042b7  jz      loc_1400043A8
0x1400042bd  sub     ecx, 1
0x1400042c0  jz      loc_140004368
0x1400042c6  sub     ecx, 1
0x1400042c9  jz      short loc_140004336
0x1400042cb  sub     ecx, 1
0x1400042ce  jz      short loc_14000432E
0x1400042d0  sub     ecx, 1
0x1400042d3  jz      short loc_1400042FD
0x1400042d5  sub     ecx, 1
0x1400042d8  jz      short loc_1400042F0
0x1400042da  cmp     ecx, 1
0x1400042dd  jnz     loc_140004476
0x1400042e3  mov     rcx, rbx
0x1400042e6  call    sub_140004620
0x1400042eb  jmp     loc_14000440D
0x1400042f0  mov     rcx, rbx
0x1400042f3  call    sub_14000447C
0x1400042f8  jmp     loc_14000440D
0x1400042fd  cmp     word ptr [rbx+42h], 2Ah ; '*'
0x140004302  jz      short loc_140004315
0x140004304  lea     rdx, [rbx+38h]
0x140004308  mov     rcx, rbx
0x14000430b  call    unknown_libname_6; Microsoft VisualC 64bit universal runtime
0x140004310  jmp     loc_14000440D
0x140004315  add     qword ptr [rbx+20h], 8
0x14000431a  mov     rax, [rbx+20h]
0x14000431e  mov     ecx, [rax-8]
0x140004321  test    ecx, ecx
0x140004323  cmovs   ecx, edi
0x140004326  mov     [rbx+38h], ecx
0x140004329  jmp     loc_14000440B
0x14000432e  mov     [rbx+38h], esi
0x140004331  jmp     loc_140004411
0x140004336  cmp     word ptr [rbx+42h], 2Ah ; '*'
0x14000433b  jz      short loc_140004343
0x14000433d  lea     rdx, [rbx+34h]
0x140004341  jmp     short loc_140004308
0x140004343  add     qword ptr [rbx+20h], 8
0x140004348  mov     rax, [rbx+20h]
0x14000434c  mov     ecx, [rax-8]
0x14000434f  mov     [rbx+34h], ecx
0x140004352  test    ecx, ecx
0x140004354  jns     loc_14000440B
0x14000435a  or      dword ptr [rbx+30h], 4
0x14000435e  neg     ecx
0x140004360  mov     [rbx+34h], ecx
0x140004363  jmp     loc_14000440B
0x140004368  movzx   eax, word ptr [rbx+42h]
0x14000436c  cmp     eax, ebp
0x14000436e  jz      short loc_1400043A2
0x140004370  cmp     eax, 23h ; '#'
0x140004373  jz      short loc_14000439D
0x140004375  cmp     eax, 2Bh ; '+'
0x140004378  jz      short loc_140004397
0x14000437a  cmp     eax, 2Dh ; '-'
0x14000437d  jz      short loc_140004391
0x14000437f  cmp     eax, 30h ; '0'
0x140004382  jnz     loc_140004411
0x140004388  or      dword ptr [rbx+30h], 8
0x14000438c  jmp     loc_140004411
0x140004391  or      dword ptr [rbx+30h], 4
0x140004395  jmp     short loc_140004411
0x140004397  or      dword ptr [rbx+30h], 1
0x14000439b  jmp     short loc_140004411
0x14000439d  or      [rbx+30h], ebp
0x1400043a0  jmp     short loc_140004411
0x1400043a2  or      dword ptr [rbx+30h], 2
0x1400043a6  jmp     short loc_140004411
0x1400043a8  mov     [rbx+30h], rsi
0x1400043ac  mov     [rbx+40h], sil
0x1400043b0  mov     [rbx+38h], edi
0x1400043b3  mov     [rbx+3Ch], esi
0x1400043b6  mov     [rbx+54h], sil
0x1400043ba  jmp     short loc_140004411
0x1400043bc  movzx   edx, word ptr [rbx+42h]
0x1400043c0  mov     byte ptr [rbx+54h], 1
0x1400043c4  mov     rcx, [rbx+468h]
0x1400043cb  mov     rax, [rcx+8]
0x1400043cf  cmp     [rcx+10h], rax
0x1400043d3  jnz     short loc_1400043E5
0x1400043d5  cmp     [rcx+18h], sil
0x1400043d9  jz      short loc_1400043E0
0x1400043db  inc     dword ptr [rbx+28h]
0x1400043de  jmp     short loc_14000440B
0x1400043e0  mov     [rbx+28h], edi
0x1400043e3  jmp     short loc_14000440B
0x1400043e5  inc     dword ptr [rbx+28h]
0x1400043e8  mov     rax, [rbx+468h]
0x1400043ef  inc     qword ptr [rax+10h]
0x1400043f3  mov     rax, [rbx+468h]
0x1400043fa  mov     rcx, [rax]
0x1400043fd  mov     [rcx], dx
0x140004400  mov     rax, [rbx+468h]
0x140004407  add     qword ptr [rax], 2
0x14000440b  mov     al, 1
0x14000440d  test    al, al
0x14000440f  jz      short loc_140004476
0x140004411  mov     rax, [rbx+18h]
0x140004415  movzx   ecx, word ptr [rax]
0x140004418  mov     [rbx+42h], cx
0x14000441c  test    cx, cx
0x14000441f  jnz     loc_140004264
0x140004425  add     qword ptr [rbx+18h], 2
0x14000442a  cmp     [rbx+2Ch], esi
0x14000442d  jz      short loc_140004435
0x14000442f  cmp     dword ptr [rbx+2Ch], 7
0x140004433  jnz     short loc_140004466
0x140004435  inc     dword ptr [rbx+470h]
0x14000443b  cmp     dword ptr [rbx+470h], 2
0x140004442  jnz     loc_140004259
0x140004448  mov     eax, [rbx+28h]
0x14000444b  mov     rbx, [rsp+28h+arg_0]
0x140004450  mov     rbp, [rsp+28h+arg_8]
0x140004455  mov     rsi, [rsp+28h+arg_10]
0x14000445a  mov     rdi, [rsp+28h+arg_18]
0x14000445f  add     rsp, 20h
0x140004463  pop     r14
0x140004465  retn
0x140004466  call    _errno
0x14000446b  mov     dword ptr [rax], 16h
0x140004471  call    _invalid_parameter_noinfo
0x140004476  mov     eax, edi
0x140004478  jmp     short loc_14000444B

// ===== sub_14000447C @ 0x14000447c =====

0x14000447c  sub     rsp, 28h
0x140004480  cmp     word ptr [rcx+42h], 46h ; 'F'
0x140004485  jnz     short loc_1400044A0
0x140004487  test    byte ptr [rcx], 8
0x14000448a  jnz     loc_140004617
0x140004490  mov     dword ptr [rcx+2Ch], 7
0x140004497  add     rsp, 28h
0x14000449b  jmp     sub_140004620
0x1400044a0  cmp     word ptr [rcx+42h], 4Eh ; 'N'
0x1400044a5  jnz     short loc_1400044CE
0x1400044a7  test    byte ptr [rcx], 8
0x1400044aa  jnz     loc_140004617
0x1400044b0  mov     dword ptr [rcx+2Ch], 8
0x1400044b7  call    _errno
0x1400044bc  mov     dword ptr [rax], 16h
0x1400044c2  call    _invalid_parameter_noinfo
0x1400044c7  xor     al, al
0x1400044c9  jmp     loc_140004619
0x1400044ce  cmp     dword ptr [rcx+3Ch], 0
0x1400044d2  jnz     short loc_1400044B7
0x1400044d4  movzx   eax, word ptr [rcx+42h]
0x1400044d8  cmp     eax, 49h ; 'I'
0x1400044db  jz      loc_1400045B0
0x1400044e1  cmp     eax, 4Ch ; 'L'
0x1400044e4  jz      loc_1400045A7
0x1400044ea  cmp     eax, 54h ; 'T'
0x1400044ed  jz      loc_14000459E
0x1400044f3  mov     edx, 68h ; 'h'
0x1400044f8  cmp     eax, edx
0x1400044fa  jz      short loc_140004578
0x1400044fc  cmp     eax, 6Ah ; 'j'
0x1400044ff  jz      short loc_14000456C
0x140004501  mov     edx, 6Ch ; 'l'
0x140004506  cmp     eax, edx
0x140004508  jz      short loc_140004543
0x14000450a  cmp     eax, 74h ; 't'
0x14000450d  jz      short loc_140004537
0x14000450f  cmp     eax, 77h ; 'w'
0x140004512  jz      short loc_14000452B
0x140004514  cmp     eax, 7Ah ; 'z'
0x140004517  mov     al, 1
0x140004519  jnz     loc_140004619
0x14000451f  mov     dword ptr [rcx+3Ch], 6
0x140004526  jmp     loc_140004619
0x14000452b  mov     dword ptr [rcx+3Ch], 0Ch
0x140004532  jmp     loc_140004617
0x140004537  mov     dword ptr [rcx+3Ch], 7
0x14000453e  jmp     loc_140004617
0x140004543  mov     rax, [rcx+18h]
0x140004547  cmp     [rax], dx
0x14000454a  jnz     short loc_140004560
0x14000454c  add     rax, 2
0x140004550  mov     dword ptr [rcx+3Ch], 4
0x140004557  mov     [rcx+18h], rax
0x14000455b  jmp     loc_140004617
0x140004560  mov     dword ptr [rcx+3Ch], 3
0x140004567  jmp     loc_140004617
0x14000456c  mov     dword ptr [rcx+3Ch], 5
0x140004573  jmp     loc_140004617
0x140004578  mov     rax, [rcx+18h]
0x14000457c  cmp     [rax], dx
0x14000457f  jnz     short loc_140004595
0x140004581  add     rax, 2
0x140004585  mov     dword ptr [rcx+3Ch], 1
0x14000458c  mov     [rcx+18h], rax
0x140004590  jmp     loc_140004617
0x140004595  mov     dword ptr [rcx+3Ch], 2
0x14000459c  jmp     short loc_140004617
0x14000459e  mov     dword ptr [rcx+3Ch], 0Dh
0x1400045a5  jmp     short loc_140004617
0x1400045a7  mov     dword ptr [rcx+3Ch], 8
0x1400045ae  jmp     short loc_140004617
0x1400045b0  mov     rdx, [rcx+18h]
0x1400045b4  movzx   eax, word ptr [rdx]
0x1400045b7  cmp     ax, 33h ; '3'
0x1400045bb  jnz     short loc_1400045D5
0x1400045bd  cmp     word ptr [rdx+2], 32h ; '2'
0x1400045c2  jnz     short loc_1400045D5
0x1400045c4  lea     rax, [rdx+4]
0x1400045c8  mov     dword ptr [rcx+3Ch], 0Ah
0x1400045cf  mov     [rcx+18h], rax
0x1400045d3  jmp     short loc_140004617
0x1400045d5  cmp     ax, 36h ; '6'
0x1400045d9  jnz     short loc_1400045F3
0x1400045db  cmp     word ptr [rdx+2], 34h ; '4'
0x1400045e0  jnz     short loc_1400045F3
0x1400045e2  lea     rax, [rdx+4]
0x1400045e6  mov     dword ptr [rcx+3Ch], 0Bh
0x1400045ed  mov     [rcx+18h], rax
0x1400045f1  jmp     short loc_140004617
0x1400045f3  sub     ax, 58h ; 'X'
0x1400045f7  cmp     ax, 20h ; ' '
0x1400045fb  ja      short loc_140004617
0x1400045fd  movzx   eax, ax
0x140004600  mov     rdx, 120821001h
0x14000460a  bt      rdx, rax
0x14000460e  jnb     short loc_140004617
0x140004610  mov     dword ptr [rcx+3Ch], 9
0x140004617  mov     al, 1
0x140004619  add     rsp, 28h
0x14000461d  retn

// ===== sub_140004620 @ 0x140004620 =====

0x140004620  mov     [rsp+arg_8], rbx
0x140004625  mov     [rsp+arg_10], rbp
0x14000462a  mov     [rsp+arg_18], rsi
0x14000462f  push    rdi
0x140004630  push    r12
0x140004632  push    r13
0x140004634  push    r14
0x140004636  push    r15
0x140004638  sub     rsp, 40h
0x14000463c  mov     rax, cs:__security_cookie
0x140004643  xor     rax, rsp
0x140004646  mov     [rsp+68h+var_30], rax
0x14000464b  movzx   eax, word ptr [rcx+42h]
0x14000464f  mov     esi, 58h ; 'X'
0x140004654  mov     rbx, rcx
0x140004657  lea     ebp, [rsi-17h]
0x14000465a  lea     r15d, [rsi-57h]
0x14000465e  cmp     eax, 64h ; 'd'
0x140004661  jg      short loc_1400046BE
0x140004663  jz      loc_14000472F
0x140004669  cmp     eax, ebp
0x14000466b  jz      loc_140004742
0x140004671  cmp     eax, 43h ; 'C'
0x140004674  jz      short loc_1400046A8
0x140004676  cmp     eax, 44h ; 'D'
0x140004679  jle     loc_14000474B
0x14000467f  cmp     eax, 47h ; 'G'
0x140004682  jle     loc_140004742
0x140004688  cmp     eax, 53h ; 'S'
0x14000468b  jz      short loc_1400046EB
0x14000468d  cmp     eax, esi
0x14000468f  jz      short loc_140004700
0x140004691  cmp     eax, 5Ah ; 'Z'
0x140004694  jz      short loc_1400046B4
0x140004696  cmp     eax, 61h ; 'a'
0x140004699  jz      loc_140004742
0x14000469f  cmp     eax, 63h ; 'c'
0x1400046a2  jnz     loc_14000474B
0x1400046a8  xor     edx, edx
0x1400046aa  call    unknown_libname_9; Microsoft VisualC 64bit universal runtime
0x1400046af  jmp     loc_140004747
0x1400046b4  call    unknown_libname_7; Microsoft VisualC 64bit universal runtime
0x1400046b9  jmp     loc_140004747
0x1400046be  cmp     eax, 67h ; 'g'
0x1400046c1  jle     short loc_140004742
0x1400046c3  cmp     eax, 69h ; 'i'
0x1400046c6  jz      short loc_14000472F
0x1400046c8  cmp     eax, 6Eh ; 'n'
0x1400046cb  jz      short loc_140004728
0x1400046cd  cmp     eax, 6Fh ; 'o'
0x1400046d0  jz      short loc_14000470A
0x1400046d2  cmp     eax, 70h ; 'p'
0x1400046d5  jz      short loc_1400046F2
0x1400046d7  cmp     eax, 73h ; 's'
0x1400046da  jz      short loc_1400046EB
0x1400046dc  cmp     eax, 75h ; 'u'
0x1400046df  jz      short loc_140004733
0x1400046e1  cmp     eax, 78h ; 'x'
0x1400046e4  jnz     short loc_14000474B
0x1400046e6  lea     edx, [rax-68h]
0x1400046e9  jmp     short loc_140004738
0x1400046eb  call    unknown_libname_11; Microsoft VisualC 64bit universal runtime
0x1400046f0  jmp     short loc_140004747
0x1400046f2  mov     dword ptr [rcx+38h], 10h
0x1400046f9  mov     dword ptr [rcx+3Ch], 0Bh
0x140004700  mov     r8b, r15b
0x140004703  mov     edx, 10h
0x140004708  jmp     short loc_14000473B
0x14000470a  mov     ecx, [rcx+30h]
0x14000470d  mov     eax, ecx
0x14000470f  shr     eax, 5
0x140004712  test    r15b, al
0x140004715  jz      short loc_14000471E
0x140004717  bts     ecx, 7
0x14000471b  mov     [rbx+30h], ecx
0x14000471e  mov     edx, 8
0x140004723  mov     rcx, rbx
0x140004726  jmp     short loc_140004738
0x140004728  call    unknown_libname_10; Microsoft VisualC 64bit universal runtime
0x14000472d  jmp     short loc_140004747
0x14000472f  or      dword ptr [rcx+30h], 10h
0x140004733  mov     edx, 0Ah
0x140004738  xor     r8d, r8d
0x14000473b  call    sub_140004C58
0x140004740  jmp     short loc_140004747
0x140004742  call    unknown_libname_8; Microsoft VisualC 64bit universal runtime
0x140004747  test    al, al
0x140004749  jnz     short loc_140004752
0x14000474b  xor     al, al
0x14000474d  jmp     loc_1400048BE
0x140004752  cmp     byte ptr [rbx+40h], 0
0x140004756  jnz     loc_1400048BB
0x14000475c  mov     edx, [rbx+30h]
0x14000475f  xor     eax, eax
0x140004761  mov     [rsp+68h+var_38], eax
0x140004765  xor     edi, edi
0x140004767  mov     [rsp+68h+var_34], ax
0x14000476c  mov     eax, edx
0x14000476e  shr     eax, 4
0x140004771  lea     r13d, [rdi+20h]
0x140004775  test    r15b, al
0x140004778  jz      short loc_1400047AC
0x14000477a  mov     eax, edx
0x14000477c  shr     eax, 6
0x14000477f  test    r15b, al
0x140004782  jz      short loc_14000478E
0x140004784  lea     eax, [rdi+2Dh]
0x140004787  mov     word ptr [rsp+68h+var_38], ax
0x14000478c  jmp     short loc_1400047A9
0x14000478e  test    r15b, dl
0x140004791  jz      short loc_14000479A
0x140004793  mov     eax, 2Bh ; '+'
0x140004798  jmp     short loc_140004787
0x14000479a  mov     eax, edx
0x14000479c  shr     eax, 1
0x14000479e  test    r15b, al
0x1400047a1  jz      short loc_1400047AC
0x1400047a3  mov     word ptr [rsp+68h+var_38], r13w
0x1400047a9  mov     rdi, r15
0x1400047ac  movzx   ecx, word ptr [rbx+42h]
0x1400047b0  mov     r9d, 0FFDFh
0x1400047b6  movzx   eax, cx
0x1400047b9  sub     ax, si
0x1400047bc  test    r9w, ax
0x1400047c0  jnz     short loc_1400047D1
0x1400047c2  mov     eax, edx
0x1400047c4  shr     eax, 5
0x1400047c7  test    r15b, al
0x1400047ca  jz      short loc_1400047D1
0x1400047cc  mov     r8b, r15b
0x1400047cf  jmp     short loc_1400047D4
0x1400047d1  xor     r8b, r8b
0x1400047d4  movzx   eax, cx
0x1400047d7  mov     r12d, 30h ; '0'
0x1400047dd  sub     ax, bp
0x1400047e0  test    r9w, ax
0x1400047e4  setz    al
0x1400047e7  test    r8b, r8b
0x1400047ea  jnz     short loc_1400047F0
0x1400047ec  test    al, al
0x1400047ee  jz      short loc_14000481F
0x1400047f0  mov     word ptr [rsp+rdi*2+68h+var_38], r12w
0x1400047f6  add     rdi, r15
0x1400047f9  cmp     cx, si
0x1400047fc  jz      short loc_140004807
0x1400047fe  cmp     cx, bp
0x140004801  jz      short loc_140004807
0x140004803  xor     al, al
0x140004805  jmp     short loc_14000480A
0x140004807  mov     al, r15b
0x14000480a  neg     al
0x14000480c  sbb     al, al
0x14000480e  and     al, 0E0h
0x140004810  add     al, 61h ; 'a'
0x140004812  add     al, 17h
0x140004814  movsx   eax, al
0x140004817  mov     word ptr [rsp+rdi*2+68h+var_38], ax
0x14000481c  add     rdi, r15
0x14000481f  mov     esi, [rbx+34h]
0x140004822  sub     esi, [rbx+50h]
0x140004825  sub     esi, edi
0x140004827  test    dl, 0Ch
0x14000482a  jnz     short loc_140004842
0x14000482c  lea     r9, [rbx+28h]
0x140004830  mov     r8d, esi
0x140004833  lea     rcx, [rbx+468h]
0x14000483a  mov     dl, r13b
0x14000483d  call    ??$write_multiple_characters@V?$string_output_adapter@_W@__crt_stdio_output@@D@__crt_stdio_output@@YAXAEBV?$string_output_adapter@_W@0@DHQEAH@Z; __crt_stdio_output::write_multiple_characters<__crt_stdio_output::string_output_adapter<wchar_t>,char>(__crt_stdio_output::string_output_adapter<wchar_t> const &,char,int,int * const)
0x140004842  mov     rax, [rbx+10h]
0x140004846  lea     rbp, [rbx+28h]
0x14000484a  lea     r14, [rbx+468h]
0x140004851  mov     [rsp+68h+var_48], rax
0x140004856  mov     r9, rbp
0x140004859  lea     rdx, [rsp+68h+var_38]
0x14000485e  mov     rcx, r14
0x140004861  mov     r8d, edi
0x140004864  call    ?write_string@?$string_output_adapter@_W@__crt_stdio_output@@QEBAXQEB_WHQEAH1@Z; __crt_stdio_output::string_output_adapter<wchar_t>::write_string(wchar_t const * const,int,int * const,int * const)
0x140004869  mov     ecx, [rbx+30h]
0x14000486c  mov     eax, ecx
0x14000486e  shr     eax, 3
0x140004871  test    r15b, al
0x140004874  jz      short loc_14000488F
0x140004876  shr     ecx, 2
0x140004879  test    r15b, cl
0x14000487c  jnz     short loc_14000488F
0x14000487e  mov     r9, rbp
0x140004881  mov     r8d, esi
0x140004884  mov     dl, r12b
0x140004887  mov     rcx, r14
0x14000488a  call    ??$write_multiple_characters@V?$string_output_adapter@_W@__crt_stdio_output@@D@__crt_stdio_output@@YAXAEBV?$string_output_adapter@_W@0@DHQEAH@Z; __crt_stdio_output::write_multiple_characters<__crt_stdio_output::string_output_adapter<wchar_t>,char>(__crt_stdio_output::string_output_adapter<wchar_t> const &,char,int,int * const)
0x14000488f  xor     edx, edx
0x140004891  mov     rcx, rbx
0x140004894  call    unknown_libname_12; Microsoft VisualC 64bit universal runtime
0x140004899  cmp     dword ptr [rbp+0], 0
0x14000489d  jl      short loc_1400048BB
0x14000489f  mov     eax, [rbx+30h]
0x1400048a2  shr     eax, 2
0x1400048a5  test    r15b, al
0x1400048a8  jz      short loc_1400048BB
0x1400048aa  mov     r9, rbp
0x1400048ad  mov     r8d, esi
0x1400048b0  mov     dl, r13b
0x1400048b3  mov     rcx, r14
0x1400048b6  call    ??$write_multiple_characters@V?$string_output_adapter@_W@__crt_stdio_output@@D@__crt_stdio_output@@YAXAEBV?$string_output_adapter@_W@0@DHQEAH@Z; __crt_stdio_output::write_multiple_characters<__crt_stdio_output::string_output_adapter<wchar_t>,char>(__crt_stdio_output::string_output_adapter<wchar_t> const &,char,int,int * const)
0x1400048bb  mov     al, r15b
0x1400048be  mov     rcx, [rsp+68h+var_30]
0x1400048c3  xor     rcx, rsp; StackCookie
0x1400048c6  call    __security_check_cookie
0x1400048cb  lea     r11, [rsp+68h+var_28]
0x1400048d0  mov     rbx, [r11+38h]
0x1400048d4  mov     rbp, [r11+40h]
0x1400048d8  mov     rsi, [r11+48h]
0x1400048dc  mov     rsp, r11
0x1400048df  pop     r15
0x1400048e1  pop     r14
0x1400048e3  pop     r13
0x1400048e5  pop     r12
0x1400048e7  pop     rdi
0x1400048e8  retn

// ===== unknown_libname_7 @ 0x1400048ec =====

0x1400048ec  mov     [rsp+arg_0], rbx
0x1400048f1  mov     [rsp+arg_8], rsi
0x1400048f6  push    rdi
0x1400048f7  sub     rsp, 20h
0x1400048fb  add     qword ptr [rcx+20h], 8
0x140004900  mov     rbx, rcx
0x140004903  mov     rax, [rcx+20h]
0x140004907  mov     rdi, [rax-8]
0x14000490b  test    rdi, rdi
0x14000490e  jz      short loc_140004944
0x140004910  mov     rsi, [rdi+8]
0x140004914  test    rsi, rsi
0x140004917  jz      short loc_140004944
0x140004919  mov     r8d, [rcx+3Ch]
0x14000491d  movzx   edx, word ptr [rcx+42h]
0x140004921  mov     rcx, [rcx]
0x140004924  call    ??$is_wide_character_specifier@_W@__crt_stdio_output@@YA_N_K_WW4length_modifier@0@@Z
0x140004929  test    al, al
0x14000492b  mov     [rbx+48h], rsi
0x14000492f  movzx   eax, word ptr [rdi]
0x140004932  jz      short loc_14000493F
0x140004934  shr     eax, 1
0x140004936  mov     [rbx+50h], eax
0x140004939  mov     byte ptr [rbx+54h], 1
0x14000493d  jmp     short loc_14000495A
0x14000493f  mov     [rbx+50h], eax
0x140004942  jmp     short loc_140004956
0x140004944  lea     rcx, aNull
0x14000494b  mov     dword ptr [rbx+50h], 6
0x140004952  mov     [rbx+48h], rcx
0x140004956  mov     byte ptr [rbx+54h], 0
0x14000495a  mov     rbx, [rsp+28h+arg_0]
0x14000495f  mov     al, 1
0x140004961  mov     rsi, [rsp+28h+arg_8]
0x140004966  add     rsp, 20h
0x14000496a  pop     rdi
0x14000496b  retn

// ===== unknown_libname_8 @ 0x14000496c =====

0x14000496c  mov     [rsp+arg_8], rbx
0x140004971  mov     [rsp+arg_10], rdi
0x140004976  push    r14
0x140004978  sub     rsp, 50h
0x14000497c  or      dword ptr [rcx+30h], 10h
0x140004980  mov     rbx, rcx
0x140004983  mov     eax, [rcx+38h]
0x140004986  mov     r14d, 0FFDFh
0x14000498c  test    eax, eax
0x14000498e  jns     short loc_1400049AC
0x140004990  movzx   eax, word ptr [rcx+42h]
0x140004994  sub     ax, 41h ; 'A'
0x140004998  and     ax, r14w
0x14000499c  neg     ax
0x14000499f  sbb     eax, eax
0x1400049a1  and     eax, 0FFFFFFF9h
0x1400049a4  add     eax, 0Dh
0x1400049a7  mov     [rcx+38h], eax
0x1400049aa  jmp     short loc_1400049C3
0x1400049ac  jnz     short loc_1400049C3
0x1400049ae  movzx   eax, word ptr [rcx+42h]
0x1400049b2  sub     ax, 47h ; 'G'
0x1400049b6  test    r14w, ax
0x1400049ba  jnz     short loc_1400049C3
0x1400049bc  mov     dword ptr [rcx+38h], 1
0x1400049c3  mov     eax, [rcx+38h]
0x1400049c6  lea     rdi, [rcx+58h]
0x1400049ca  add     eax, 15Dh
0x1400049cf  mov     rcx, rdi
0x1400049d2  movsxd  rdx, eax
0x1400049d5  call    ??$ensure_buffer_is_big_enough@D@formatting_buffer@__crt_stdio_output@@QEAA_N_K@Z
0x1400049da  mov     r8d, 200h
0x1400049e0  test    al, al
0x1400049e2  jnz     short loc_140004A05
0x1400049e4  cmp     qword ptr [rdi+408h], 0
0x1400049ec  jnz     short loc_1400049F3
0x1400049ee  mov     eax, r8d
0x1400049f1  jmp     short loc_1400049FD
0x1400049f3  mov     rax, [rdi+400h]
0x1400049fa  shr     rax, 1
0x1400049fd  add     eax, 0FFFFFEA3h
0x140004a02  mov     [rbx+38h], eax
0x140004a05  mov     rax, [rdi+408h]
0x140004a0c  test    rax, rax
0x140004a0f  cmovz   rax, rdi
0x140004a13  mov     [rbx+48h], rax
0x140004a17  xor     eax, eax
0x140004a19  add     qword ptr [rbx+20h], 8
0x140004a1e  cmp     qword ptr [rdi+408h], 0
0x140004a26  mov     [rsp+58h+arg_0], rax
0x140004a2b  mov     rax, [rbx+20h]
0x140004a2f  movsd   xmm0, qword ptr [rax-8]
0x140004a34  movsd   [rsp+58h+arg_0], xmm0
0x140004a3a  jnz     short loc_140004A41
0x140004a3c  mov     r9, r8
0x140004a3f  jmp     short loc_140004A4B
0x140004a41  mov     r9, [rdi+400h]
0x140004a48  shr     r9, 1
0x140004a4b  mov     rcx, [rdi+408h]
0x140004a52  test    rcx, rcx
0x140004a55  jnz     short loc_140004A60
0x140004a57  lea     r10, [rdi+200h]
0x140004a5e  jmp     short loc_140004A6D
0x140004a60  mov     r10, [rdi+400h]
0x140004a67  shr     r10, 1
0x140004a6a  add     r10, rcx
0x140004a6d  cmp     rcx, 0
0x140004a71  jz      short loc_140004A7D
0x140004a73  mov     r8, [rdi+400h]
0x140004a7a  shr     r8, 1; unsigned __int64
0x140004a7d  mov     rax, [rbx+8]
0x140004a81  mov     rdx, rcx
0x140004a84  mov     [rsp+58h+var_18], rax; struct __crt_locale_pointers *
0x140004a89  test    rcx, rcx
0x140004a8c  mov     rax, [rbx]
0x140004a8f  movsx   ecx, byte ptr [rbx+42h]
0x140004a93  cmovz   rdx, rdi; char *
0x140004a97  mov     [rsp+58h+var_20], rax; __int64
0x140004a9c  mov     eax, [rbx+38h]
0x140004a9f  mov     [rsp+58h+var_28], eax; int
0x140004aa3  mov     [rsp+58h+var_30], ecx; int
0x140004aa7  lea     rcx, [rsp+58h+arg_0]; double *
0x140004aac  mov     [rsp+58h+var_38], r9; unsigned __int64
0x140004ab1  mov     r9, r10; char *
0x140004ab4  call    __acrt_fp_format
0x140004ab9  mov     eax, [rbx+30h]
0x140004abc  shr     eax, 5
0x140004abf  test    al, 1
0x140004ac1  jz      short loc_140004AD6
0x140004ac3  cmp     dword ptr [rbx+38h], 0
0x140004ac7  jnz     short loc_140004AD6
0x140004ac9  mov     rdx, [rbx+8]; char *
0x140004acd  mov     rcx, [rbx+48h]; this
0x140004ad1  call    ?force_decimal_point@__crt_stdio_output@@YAXPEADQEAU__crt_locale_pointers@@@Z
0x140004ad6  movzx   eax, word ptr [rbx+42h]
0x140004ada  sub     ax, 47h ; 'G'
0x140004ade  test    r14w, ax
0x140004ae2  jnz     short loc_140004B51
0x140004ae4  mov     eax, [rbx+30h]
0x140004ae7  shr     eax, 5
0x140004aea  test    al, 1
0x140004aec  jnz     short loc_140004B51
0x140004aee  mov     rax, [rbx+8]
0x140004af2  mov     rdx, [rbx+48h]
0x140004af6  mov     rcx, [rax]
0x140004af9  mov     rax, [rcx+0F8h]
0x140004b00  mov     rcx, [rax]
0x140004b03  mov     r8b, [rcx]
0x140004b06  jmp     short loc_140004B10
0x140004b08  cmp     al, r8b
0x140004b0b  jz      short loc_140004B16
0x140004b0d  inc     rdx
0x140004b10  mov     al, [rdx]
0x140004b12  test    al, al
0x140004b14  jnz     short loc_140004B08
0x140004b16  mov     al, [rdx]
0x140004b18  inc     rdx
0x140004b1b  test    al, al
0x140004b1d  jz      short loc_140004B51
0x140004b1f  jmp     short loc_140004B2A
0x140004b21  sub     al, 45h ; 'E'
0x140004b23  test    al, 0DFh
0x140004b25  jz      short loc_140004B30
0x140004b27  inc     rdx
0x140004b2a  mov     al, [rdx]
0x140004b2c  test    al, al
0x140004b2e  jnz     short loc_140004B21
0x140004b30  mov     rcx, rdx
0x140004b33  dec     rdx
0x140004b36  cmp     byte ptr [rdx], 30h ; '0'
0x140004b39  jz      short loc_140004B33
0x140004b3b  cmp     [rdx], r8b
0x140004b3e  jnz     short loc_140004B43
0x140004b40  dec     rdx
0x140004b43  mov     al, [rcx]
0x140004b45  inc     rdx
0x140004b48  inc     rcx
0x140004b4b  mov     [rdx], al
0x140004b4d  test    al, al
0x140004b4f  jnz     short loc_140004B43
0x140004b51  mov     rax, [rbx+48h]
0x140004b55  cmp     byte ptr [rax], 2Dh ; '-'
0x140004b58  jnz     short loc_140004B65
0x140004b5a  or      dword ptr [rbx+30h], 40h
0x140004b5e  inc     rax
0x140004b61  mov     [rbx+48h], rax
0x140004b65  mov     rdx, [rbx+48h]
0x140004b69  mov     al, [rdx]
0x140004b6b  sub     al, 49h ; 'I'
0x140004b6d  cmp     al, 25h ; '%'
0x140004b6f  ja      short loc_140004B8A
0x140004b71  mov     rcx, 2100000021h
0x140004b7b  bt      rcx, rax
0x140004b7f  jnb     short loc_140004B8A
0x140004b81  mov     eax, 73h ; 's'
0x140004b86  mov     [rbx+42h], ax
0x140004b8a  or      rcx, 0FFFFFFFFFFFFFFFFh
0x140004b8e  inc     rcx
0x140004b91  cmp     byte ptr [rdx+rcx], 0
0x140004b95  jnz     short loc_140004B8E
0x140004b97  mov     rdi, [rsp+58h+arg_10]
0x140004b9c  mov     al, 1
0x140004b9e  mov     [rbx+50h], ecx
0x140004ba1  mov     rbx, [rsp+58h+arg_8]
0x140004ba6  add     rsp, 50h
0x140004baa  pop     r14
0x140004bac  retn

// ===== unknown_libname_9 @ 0x140004bb0 =====

0x140004bb0  mov     [rsp+arg_8], rbx
0x140004bb5  mov     [rsp+arg_10], rsi
0x140004bba  push    rdi
0x140004bbb  sub     rsp, 20h
0x140004bbf  mov     byte ptr [rcx+54h], 1
0x140004bc3  mov     rbx, rcx
0x140004bc6  add     qword ptr [rcx+20h], 8
0x140004bcb  mov     rax, [rcx+20h]
0x140004bcf  mov     r8d, [rcx+3Ch]
0x140004bd3  movzx   edx, word ptr [rcx+42h]
0x140004bd7  mov     rcx, [rcx]
0x140004bda  movzx   esi, word ptr [rax-8]
0x140004bde  call    ??$is_wide_character_specifier@_W@__crt_stdio_output@@YA_N_K_WW4length_modifier@0@@Z
0x140004be3  lea     rdi, [rbx+58h]
0x140004be7  mov     rcx, [rdi+408h]
0x140004bee  test    al, al
0x140004bf0  jnz     short loc_140004C21
0x140004bf2  mov     r9, [rbx+8]; Locale
0x140004bf6  lea     rdx, [rsp+28h+SrcCh]; SrcCh
0x140004bfb  mov     [rsp+28h+SrcCh], sil
0x140004c00  test    rcx, rcx
0x140004c03  mov     [rsp+28h+arg_1], al
0x140004c07  cmovz   rcx, rdi; DstCh
0x140004c0b  mov     rax, [r9]
0x140004c0e  movsxd  r8, dword ptr [rax+8]; SrcSizeInBytes
0x140004c12  call    _mbtowc_l
0x140004c17  test    eax, eax
0x140004c19  jns     short loc_140004C2B
0x140004c1b  mov     byte ptr [rbx+40h], 1
0x140004c1f  jmp     short loc_140004C2B
0x140004c21  test    rcx, rcx
0x140004c24  cmovz   rcx, rdi
0x140004c28  mov     [rcx], si
0x140004c2b  mov     rcx, [rdi+408h]
0x140004c32  mov     al, 1
0x140004c34  mov     rsi, [rsp+28h+arg_10]
0x140004c39  test    rcx, rcx
0x140004c3c  mov     dword ptr [rbx+50h], 1
0x140004c43  cmovz   rcx, rdi
0x140004c47  mov     [rbx+48h], rcx
0x140004c4b  mov     rbx, [rsp+28h+arg_8]
0x140004c50  add     rsp, 20h
0x140004c54  pop     rdi
0x140004c55  retn

// ===== sub_140004C58 @ 0x140004c58 =====

0x140004c58  push    rbx
0x140004c5a  sub     rsp, 20h
0x140004c5e  mov     r11d, 8
0x140004c64  mov     rbx, rcx
0x140004c67  mov     ecx, [rcx+3Ch]
0x140004c6a  mov     r9b, r8b
0x140004c6d  mov     r10d, edx
0x140004c70  lea     r8d, [r11-4]
0x140004c74  cmp     ecx, 5
0x140004c77  jg      short loc_140004CDE
0x140004c79  jz      short loc_140004C93
0x140004c7b  test    ecx, ecx
0x140004c7d  jz      short loc_140004CCB
0x140004c7f  sub     ecx, 1
0x140004c82  jz      short loc_140004CD7
0x140004c84  sub     ecx, 1
0x140004c87  jz      short loc_140004CD0
0x140004c89  sub     ecx, 1
0x140004c8c  jz      short loc_140004CCB
0x140004c8e  cmp     ecx, 1
0x140004c91  jnz     short loc_140004CEF
0x140004c93  mov     rdx, r11
0x140004c96  mov     rax, rdx
0x140004c99  sub     rax, 1
0x140004c9d  jz      loc_140004D45
0x140004ca3  sub     rax, 1
0x140004ca7  jz      short loc_140004D26
0x140004ca9  sub     rax, 2
0x140004cad  jz      short loc_140004D09
0x140004caf  cmp     rax, r8
0x140004cb2  jz      short loc_140004CF3
0x140004cb4  call    _errno
0x140004cb9  mov     dword ptr [rax], 16h
0x140004cbf  call    _invalid_parameter_noinfo
0x140004cc4  xor     al, al
0x140004cc6  jmp     loc_140004DF1
0x140004ccb  mov     rdx, r8
0x140004cce  jmp     short loc_140004C96
0x140004cd0  mov     edx, 2
0x140004cd5  jmp     short loc_140004C96
0x140004cd7  mov     edx, 1
0x140004cdc  jmp     short loc_140004C96
0x140004cde  sub     ecx, 6
0x140004ce1  jz      short loc_140004C93
0x140004ce3  sub     ecx, 1
0x140004ce6  jz      short loc_140004C93
0x140004ce8  sub     ecx, 2
0x140004ceb  jz      short loc_140004C93
0x140004ced  jmp     short loc_140004C89
0x140004cef  xor     edx, edx
0x140004cf1  jmp     short loc_140004C96
0x140004cf3  mov     eax, [rbx+30h]
0x140004cf6  add     [rbx+20h], r11
0x140004cfa  shr     eax, 4
0x140004cfd  test    al, 1
0x140004cff  mov     rax, [rbx+20h]
0x140004d03  mov     rcx, [rax-8]
0x140004d07  jmp     short loc_140004D62
0x140004d09  mov     eax, [rbx+30h]
0x140004d0c  add     [rbx+20h], r11
0x140004d10  shr     eax, 4
0x140004d13  test    al, 1
0x140004d15  mov     rax, [rbx+20h]
0x140004d19  jz      short loc_140004D21
0x140004d1b  movsxd  rcx, dword ptr [rax-8]
0x140004d1f  jmp     short loc_140004D62
0x140004d21  mov     ecx, [rax-8]
0x140004d24  jmp     short loc_140004D62
0x140004d26  mov     eax, [rbx+30h]
0x140004d29  add     [rbx+20h], r11
0x140004d2d  shr     eax, 4
0x140004d30  test    al, 1
0x140004d32  mov     rax, [rbx+20h]
0x140004d36  jz      short loc_140004D3F
0x140004d38  movsx   rcx, word ptr [rax-8]
0x140004d3d  jmp     short loc_140004D62
0x140004d3f  movzx   ecx, word ptr [rax-8]
0x140004d43  jmp     short loc_140004D62
0x140004d45  mov     eax, [rbx+30h]
0x140004d48  add     [rbx+20h], r11
0x140004d4c  shr     eax, 4
0x140004d4f  test    al, 1
0x140004d51  mov     rax, [rbx+20h]
0x140004d55  jz      short loc_140004D5E
0x140004d57  movsx   rcx, byte ptr [rax-8]
0x140004d5c  jmp     short loc_140004D62
0x140004d5e  movzx   ecx, byte ptr [rax-8]
0x140004d62  mov     r8d, [rbx+30h]
0x140004d66  mov     eax, r8d
0x140004d69  shr     eax, 4
0x140004d6c  test    al, 1
0x140004d6e  jz      short loc_140004D80
0x140004d70  test    rcx, rcx
0x140004d73  jns     short loc_140004D80
0x140004d75  neg     rcx
0x140004d78  or      r8d, 40h
0x140004d7c  mov     [rbx+30h], r8d
0x140004d80  cmp     dword ptr [rbx+38h], 0
0x140004d84  jge     short loc_140004D8F
0x140004d86  mov     dword ptr [rbx+38h], 1
0x140004d8d  jmp     short loc_140004DA0
0x140004d8f  and     dword ptr [rbx+30h], 0FFFFFFF7h
0x140004d93  mov     eax, 200h
0x140004d98  cmp     [rbx+38h], eax
0x140004d9b  jle     short loc_140004DA0
0x140004d9d  mov     [rbx+38h], eax
0x140004da0  test    rcx, rcx
0x140004da3  jnz     short loc_140004DA9
0x140004da5  and     dword ptr [rbx+30h], 0FFFFFFDFh
0x140004da9  mov     r8d, r10d
0x140004dac  cmp     rdx, r11
0x140004daf  jnz     short loc_140004DBE
0x140004db1  mov     rdx, rcx
0x140004db4  mov     rcx, rbx
0x140004db7  call    unknown_libname_4; Microsoft VisualC 64bit universal runtime
0x140004dbc  jmp     short loc_140004DC8
0x140004dbe  mov     edx, ecx
0x140004dc0  mov     rcx, rbx
0x140004dc3  call    unknown_libname_3; Microsoft VisualC 64bit universal runtime
0x140004dc8  mov     eax, [rbx+30h]
0x140004dcb  shr     eax, 7
0x140004dce  test    al, 1
0x140004dd0  jz      short loc_140004DEF
0x140004dd2  cmp     dword ptr [rbx+50h], 0
0x140004dd6  jz      short loc_140004DE1
0x140004dd8  mov     rcx, [rbx+48h]
0x140004ddc  cmp     byte ptr [rcx], 30h ; '0'
0x140004ddf  jz      short loc_140004DEF
0x140004de1  dec     qword ptr [rbx+48h]
0x140004de5  mov     rcx, [rbx+48h]
0x140004de9  mov     byte ptr [rcx], 30h ; '0'
0x140004dec  inc     dword ptr [rbx+50h]
0x140004def  mov     al, 1
0x140004df1  add     rsp, 20h
0x140004df5  pop     rbx
0x140004df6  retn

// ===== unknown_libname_10 @ 0x140004df8 =====

0x140004df8  mov     [rsp+arg_0], rbx
0x140004dfd  mov     [rsp+arg_8], rsi
0x140004e02  push    rdi
0x140004e03  sub     rsp, 20h
0x140004e07  mov     ebx, 8
0x140004e0c  mov     rdi, rcx
0x140004e0f  add     [rcx+20h], rbx
0x140004e13  mov     rax, [rcx+20h]
0x140004e17  mov     rsi, [rax-8]
0x140004e1b  call    _get_printf_count_output
0x140004e20  test    eax, eax
0x140004e22  jnz     short loc_140004E3B
0x140004e24  call    _errno
0x140004e29  mov     dword ptr [rax], 16h
0x140004e2f  call    _invalid_parameter_noinfo
0x140004e34  xor     al, al
0x140004e36  jmp     loc_140004EC3
0x140004e3b  mov     ecx, [rdi+3Ch]
0x140004e3e  mov     edx, 4
0x140004e43  cmp     ecx, 5
0x140004e46  jg      short loc_140004E74
0x140004e48  jz      short loc_140004E88
0x140004e4a  test    ecx, ecx
0x140004e4c  jz      short loc_140004E85
0x140004e4e  sub     ecx, 1
0x140004e51  jz      short loc_140004E6D
0x140004e53  sub     ecx, 1
0x140004e56  jz      short loc_140004E66
0x140004e58  sub     ecx, 1
0x140004e5b  jz      short loc_140004E85
0x140004e5d  cmp     ecx, 1
0x140004e60  jz      short loc_140004E88
0x140004e62  xor     ebx, ebx
0x140004e64  jmp     short loc_140004E88
0x140004e66  mov     ebx, 2
0x140004e6b  jmp     short loc_140004E88
0x140004e6d  mov     ebx, 1
0x140004e72  jmp     short loc_140004E88
0x140004e74  sub     ecx, 6
0x140004e77  jz      short loc_140004E88
0x140004e79  sub     ecx, 1
0x140004e7c  jz      short loc_140004E88
0x140004e7e  sub     ecx, 2
0x140004e81  jz      short loc_140004E88
0x140004e83  jmp     short loc_140004E58
0x140004e85  mov     rbx, rdx
0x140004e88  sub     rbx, 1
0x140004e8c  jz      short loc_140004EB8
0x140004e8e  sub     rbx, 1
0x140004e92  jz      short loc_140004EAF
0x140004e94  sub     rbx, 2
0x140004e98  jz      short loc_140004EA8
0x140004e9a  cmp     rbx, rdx
0x140004e9d  jnz     short loc_140004E24
0x140004e9f  movsxd  rax, dword ptr [rdi+28h]
0x140004ea3  mov     [rsi], rax
0x140004ea6  jmp     short loc_140004EBD
0x140004ea8  mov     eax, [rdi+28h]
0x140004eab  mov     [rsi], eax
0x140004ead  jmp     short loc_140004EBD
0x140004eaf  movzx   eax, word ptr [rdi+28h]
0x140004eb3  mov     [rsi], ax
0x140004eb6  jmp     short loc_140004EBD
0x140004eb8  mov     cl, [rdi+28h]
0x140004ebb  mov     [rsi], cl
0x140004ebd  mov     byte ptr [rdi+40h], 1
0x140004ec1  mov     al, 1
0x140004ec3  mov     rbx, [rsp+28h+arg_0]
0x140004ec8  mov     rsi, [rsp+28h+arg_8]
0x140004ecd  add     rsp, 20h
0x140004ed1  pop     rdi
0x140004ed2  retn

// ===== unknown_libname_11 @ 0x140004ed4 =====

0x140004ed4  mov     [rsp+arg_0], rbx
0x140004ed9  mov     [rsp+arg_8], rsi
0x140004ede  push    rdi
0x140004edf  sub     rsp, 20h
0x140004ee3  add     qword ptr [rcx+20h], 8
0x140004ee8  mov     rbx, rcx
0x140004eeb  mov     rax, [rcx+20h]
0x140004eef  mov     edi, [rcx+38h]
0x140004ef2  cmp     edi, 0FFFFFFFFh
0x140004ef5  mov     r8d, [rcx+3Ch]
0x140004ef9  movzx   edx, word ptr [rcx+42h]
0x140004efd  mov     rsi, [rax-8]
0x140004f01  mov     eax, 7FFFFFFFh
0x140004f06  mov     [rcx+48h], rsi
0x140004f0a  cmovz   edi, eax
0x140004f0d  mov     rcx, [rcx]
0x140004f10  call    ??$is_wide_character_specifier@_W@__crt_stdio_output@@YA_N_K_WW4length_modifier@0@@Z
0x140004f15  test    al, al
0x140004f17  jz      short loc_140004F3C
0x140004f19  test    rsi, rsi
0x140004f1c  movsxd  rdx, edi; MaxCount
0x140004f1f  lea     rcx, aNull_0
0x140004f26  mov     byte ptr [rbx+54h], 1
0x140004f2a  cmovnz  rcx, rsi; Source
0x140004f2e  mov     [rbx+48h], rcx
0x140004f32  call    wcsnlen
0x140004f37  mov     [rbx+50h], eax
0x140004f3a  jmp     short loc_140004F88
0x140004f3c  test    rsi, rsi
0x140004f3f  jnz     short loc_140004F4C
0x140004f41  lea     rax, aNull
0x140004f48  mov     [rbx+48h], rax
0x140004f4c  mov     r8, [rbx+48h]
0x140004f50  xor     r9d, r9d
0x140004f53  test    edi, edi
0x140004f55  jle     short loc_140004F84
0x140004f57  cmp     byte ptr [r8], 0
0x140004f5b  jz      short loc_140004F84
0x140004f5d  mov     rax, [rbx+8]
0x140004f61  movzx   edx, byte ptr [r8]
0x140004f65  mov     rcx, [rax]
0x140004f68  mov     rax, [rcx]
0x140004f6b  mov     ecx, 8000h
0x140004f70  test    [rax+rdx*2], cx
0x140004f74  jz      short loc_140004F79
0x140004f76  inc     r8
0x140004f79  inc     r8
0x140004f7c  inc     r9d
0x140004f7f  cmp     r9d, edi
0x140004f82  jl      short loc_140004F57
0x140004f84  mov     [rbx+50h], r9d
0x140004f88  mov     rbx, [rsp+28h+arg_0]
0x140004f8d  mov     al, 1
0x140004f8f  mov     rsi, [rsp+28h+arg_8]
0x140004f94  add     rsp, 20h
0x140004f98  pop     rdi
0x140004f99  retn

// ===== unknown_libname_12 @ 0x140004f9c =====

0x140004f9c  mov     [rsp+arg_8], rbx
0x140004fa1  mov     [rsp+arg_10], rbp
0x140004fa6  mov     [rsp+arg_18], rsi
0x140004fab  push    rdi
0x140004fac  sub     rsp, 30h
0x140004fb0  xor     ebp, ebp
0x140004fb2  mov     rbx, rcx
0x140004fb5  cmp     [rcx+54h], bpl
0x140004fb9  jnz     loc_140005051
0x140004fbf  mov     eax, [rcx+50h]
0x140004fc2  test    eax, eax
0x140004fc4  jle     loc_140005051
0x140004fca  mov     rsi, [rcx+48h]
0x140004fce  mov     edi, ebp
0x140004fd0  mov     r9, [rbx+8]; Locale
0x140004fd4  lea     rcx, [rsp+38h+DstCh]; DstCh
0x140004fd9  mov     [rsp+38h+DstCh], bp
0x140004fde  mov     rdx, rsi; SrcCh
0x140004fe1  mov     rax, [r9]
0x140004fe4  movsxd  r8, dword ptr [rax+8]; SrcSizeInBytes
0x140004fe8  call    _mbtowc_l
0x140004fed  movsxd  rdx, eax
0x140004ff0  test    eax, eax
0x140004ff2  jle     short loc_14000504B
0x140004ff4  mov     rcx, [rbx+468h]
0x140004ffb  movzx   r8d, [rsp+38h+DstCh]
0x140005001  mov     rax, [rcx+8]
0x140005005  cmp     [rcx+10h], rax
0x140005009  jnz     short loc_14000501C
0x14000500b  cmp     [rcx+18h], bpl
0x14000500f  jz      short loc_140005016
0x140005011  inc     dword ptr [rbx+28h]
0x140005014  jmp     short loc_14000503C
0x140005016  or      dword ptr [rbx+28h], 0FFFFFFFFh
0x14000501a  jmp     short loc_14000503C
0x14000501c  inc     dword ptr [rbx+28h]
0x14000501f  inc     qword ptr [rcx+10h]
0x140005023  mov     rax, [rbx+468h]
0x14000502a  mov     rcx, [rax]
0x14000502d  mov     [rcx], r8w
0x140005031  mov     rax, [rbx+468h]
0x140005038  add     qword ptr [rax], 2
0x14000503c  add     rsi, rdx
0x14000503f  inc     edi
0x140005041  mov     rax, rdx
0x140005044  cmp     edi, [rbx+50h]
0x140005047  jnz     short loc_140004FD0
0x140005049  jmp     short loc_140005072
0x14000504b  or      dword ptr [rbx+28h], 0FFFFFFFFh
0x14000504f  jmp     short loc_140005072
0x140005051  mov     rax, [rbx+10h]
0x140005055  lea     r9, [rcx+28h]
0x140005059  mov     r8d, [rbx+50h]
0x14000505d  add     rcx, 468h
0x140005064  mov     rdx, [rbx+48h]
0x140005068  mov     [rsp+38h+var_18], rax
0x14000506d  call    ?write_string@?$string_output_adapter@_W@__crt_stdio_output@@QEBAXQEB_WHQEAH1@Z
0x140005072  mov     rbx, [rsp+38h+arg_8]
0x140005077  mov     al, 1
0x140005079  mov     rbp, [rsp+38h+arg_10]
0x14000507e  mov     rsi, [rsp+38h+arg_18]
0x140005083  add     rsp, 30h
0x140005087  pop     rdi
0x140005088  retn

// ===== ?write_string@?$string_output_adapter@_W@__crt_stdio_output@@QEBAXQEB_WHQEAH1@Z @ 0x14000508c =====

0x14000508c  mov     [rsp+arg_0], rbx
0x140005091  mov     [rsp+arg_8], rbp
0x140005096  mov     [rsp+arg_10], rsi
0x14000509b  push    rdi
0x14000509c  push    r12
0x14000509e  push    r13
0x1400050a0  push    r14
0x1400050a2  push    r15
0x1400050a4  sub     rsp, 20h
0x1400050a8  mov     rsi, [rsp+48h+arg_20]
0x1400050ad  mov     r12, rcx
0x1400050b0  mov     rdi, r9
0x1400050b3  movsxd  rbp, r8d
0x1400050b6  mov     r15d, [rsi]
0x1400050b9  and     dword ptr [rsi], 0
0x1400050bc  mov     rcx, [rcx]
0x1400050bf  mov     rax, [rcx+8]
0x1400050c3  cmp     [rcx+10h], rax
0x1400050c7  jnz     short loc_1400050DA
0x1400050c9  cmp     byte ptr [rcx+18h], 0
0x1400050cd  jz      short loc_1400050D4
0x1400050cf  add     [r9], ebp
0x1400050d2  jmp     short loc_140005121
0x1400050d4  or      dword ptr [r9], 0FFFFFFFFh
0x1400050d8  jmp     short loc_140005121
0x1400050da  sub     rax, [rcx+10h]
0x1400050de  mov     r14, rbp
0x1400050e1  mov     rcx, [rcx]
0x1400050e4  cmp     rax, rbp
0x1400050e7  cmovb   r14, rax
0x1400050eb  lea     rbx, [r14+r14]
0x1400050ef  mov     r8, rbx
0x1400050f2  call    sub_1400036D0
0x1400050f7  mov     rax, [r12]
0x1400050fb  add     [rax], rbx
0x1400050fe  mov     rax, [r12]
0x140005102  add     [rax+10h], r14
0x140005106  mov     rax, [r12]
0x14000510a  cmp     byte ptr [rax+18h], 0
0x14000510e  jz      short loc_140005114
0x140005110  add     [rdi], ebp
0x140005112  jmp     short loc_140005121
0x140005114  cmp     r14, rbp
0x140005117  jz      short loc_14000511E
0x140005119  or      dword ptr [rdi], 0FFFFFFFFh
0x14000511c  jmp     short loc_140005121
0x14000511e  add     [rdi], r14d
0x140005121  cmp     dword ptr [rsi], 0
0x140005124  jnz     short loc_14000512E
0x140005126  test    r15d, r15d
0x140005129  jz      short loc_14000512E
0x14000512b  mov     [rsi], r15d
0x14000512e  mov     rbx, [rsp+48h+arg_0]
0x140005133  mov     rbp, [rsp+48h+arg_8]
0x140005138  mov     rsi, [rsp+48h+arg_10]
0x14000513d  add     rsp, 20h
0x140005141  pop     r15
0x140005143  pop     r14
0x140005145  pop     r13
0x140005147  pop     r12
0x140005149  pop     rdi
0x14000514a  retn

// ===== unknown_libname_13 @ 0x14000514c =====

0x14000514c  mov     [rsp+arg_0], rbx
0x140005151  push    rdi
0x140005152  sub     rsp, 30h
0x140005156  xor     edi, edi
0x140005158  mov     rbx, rdx
0x14000515b  test    r9, r9
0x14000515e  jz      short loc_14000519C
0x140005160  test    rdx, rdx
0x140005163  jz      short loc_14000519C
0x140005165  test    r8, r8
0x140005168  jz      short loc_14000519C
0x14000516a  mov     rax, [rsp+38h+arg_28]
0x14000516f  mov     [rsp+38h+var_10], rax; __int64
0x140005174  mov     rax, [rsp+38h+arg_20]
0x140005179  mov     [rsp+38h+var_18], rax; struct __crt_locale_pointers *
0x14000517e  call    sub_140003BA8
0x140005183  test    eax, eax
0x140005185  jns     short loc_14000518A
0x140005187  mov     [rbx], di
0x14000518a  cmp     eax, 0FFFFFFFEh
0x14000518d  jnz     short loc_1400051AF
0x14000518f  call    _errno
0x140005194  mov     dword ptr [rax], 22h ; '"'
0x14000519a  jmp     short loc_1400051A7
0x14000519c  call    _errno
0x1400051a1  mov     dword ptr [rax], 16h
0x1400051a7  call    _invalid_parameter_noinfo
0x1400051ac  or      eax, 0FFFFFFFFh
0x1400051af  mov     rbx, [rsp+38h+arg_0]
0x1400051b4  add     rsp, 30h
0x1400051b8  pop     rdi
0x1400051b9  retn

// ===== __acrt_initialize_stdio @ 0x1400051bc =====

0x1400051bc  mov     rax, rsp
0x1400051bf  mov     [rax+8], rbx
0x1400051c3  mov     [rax+10h], rbp
0x1400051c7  mov     [rax+18h], rsi
0x1400051cb  mov     [rax+20h], rdi
0x1400051cf  push    r14
0x1400051d1  sub     rsp, 20h
0x1400051d5  mov     eax, cs:dword_14001D080
0x1400051db  xor     ebx, ebx
0x1400051dd  mov     edi, 3
0x1400051e2  test    eax, eax
0x1400051e4  jnz     short loc_1400051ED
0x1400051e6  mov     eax, 200h
0x1400051eb  jmp     short loc_1400051F2
0x1400051ed  cmp     eax, edi
0x1400051ef  cmovl   eax, edi
0x1400051f2  movsxd  rcx, eax; Count
0x1400051f5  mov     edx, 8; Size
0x1400051fa  mov     cs:dword_14001D080, eax
0x140005200  call    _calloc_base
0x140005205  xor     ecx, ecx; Block
0x140005207  mov     cs:Block, rax
0x14000520e  call    _free_base
0x140005213  cmp     cs:Block, rbx
0x14000521a  jnz     short loc_14000524B
0x14000521c  mov     edx, 8; Size
0x140005221  mov     cs:dword_14001D080, edi
0x140005227  mov     rcx, rdi; Count
0x14000522a  call    _calloc_base
0x14000522f  xor     ecx, ecx; Block
0x140005231  mov     cs:Block, rax
0x140005238  call    _free_base
0x14000523d  cmp     cs:Block, rbx
0x140005244  jnz     short loc_14000524B
0x140005246  or      eax, 0FFFFFFFFh
0x140005249  jmp     short loc_1400052C0
0x14000524b  mov     r14, rbx
0x14000524e  lea     rsi, unk_14001C058
0x140005255  lea     rbp, unk_14001C040
0x14000525c  lea     rcx, [rbp+30h]; lpCriticalSection
0x140005260  xor     r8d, r8d
0x140005263  mov     edx, 0FA0h; dwSpinCount
0x140005268  call    __acrt_InitializeCriticalSectionEx
0x14000526d  mov     rax, cs:Block
0x140005274  lea     rdx, qword_14001D350
0x14000527b  mov     rcx, rbx
0x14000527e  and     ecx, 3Fh
0x140005281  shl     rcx, 6
0x140005285  mov     [r14+rax], rbp
0x140005289  mov     rax, rbx
0x14000528c  sar     rax, 6
0x140005290  mov     rax, [rdx+rax*8]
0x140005294  mov     rcx, [rax+rcx+28h]
0x140005299  add     rcx, 2
0x14000529d  cmp     rcx, 2
0x1400052a1  ja      short loc_1400052A9
0x1400052a3  mov     dword ptr [rsi], 0FFFFFFFEh
0x1400052a9  inc     rbx
0x1400052ac  add     rbp, 58h ; 'X'
0x1400052b0  add     r14, 8
0x1400052b4  add     rsi, 58h ; 'X'
0x1400052b8  sub     rdi, 1
0x1400052bc  jnz     short loc_14000525C
0x1400052be  xor     eax, eax
0x1400052c0  mov     rbx, [rsp+28h+arg_0]
0x1400052c5  mov     rbp, [rsp+28h+arg_8]
0x1400052ca  mov     rsi, [rsp+28h+arg_10]
0x1400052cf  mov     rdi, [rsp+28h+arg_18]
0x1400052d4  add     rsp, 20h
0x1400052d8  pop     r14
0x1400052da  retn

// ===== __acrt_uninitialize_stdio @ 0x1400052dc =====

0x1400052dc  push    rbx
0x1400052de  sub     rsp, 20h
0x1400052e2  call    _flushall
0x1400052e7  call    _fcloseall
0x1400052ec  xor     ebx, ebx
0x1400052ee  mov     rcx, cs:Block
0x1400052f5  mov     rcx, [rbx+rcx]
0x1400052f9  call    __acrt_stdio_free_buffer_nolock
0x1400052fe  mov     rax, cs:Block
0x140005305  mov     rcx, [rbx+rax]
0x140005309  add     rcx, 30h ; '0'; lpCriticalSection
0x14000530d  call    cs:DeleteCriticalSection; KERNEL32
0x140005313  add     rbx, 8
0x140005317  cmp     rbx, 18h
0x14000531b  jnz     short loc_1400052EE
0x14000531d  mov     rcx, cs:Block; Block
0x140005324  call    _free_base
0x140005329  and     cs:Block, 0
0x140005331  add     rsp, 20h
0x140005335  pop     rbx
0x140005336  retn

// ===== sub_140005338 @ 0x140005338 =====

0x140005338  add     rcx, 30h ; '0'
0x14000533c  jmp     cs:EnterCriticalSection; KERNEL32

// ===== sub_140005344 @ 0x140005344 =====

0x140005344  add     rcx, 30h ; '0'
0x140005348  jmp     cs:LeaveCriticalSection; KERNEL32

// ===== _wcsicmp @ 0x140005350 =====

0x140005350  sub     rsp, 28h
0x140005354  mov     eax, cs:dword_14001D2E4
0x14000535a  mov     r9, rdx
0x14000535d  mov     r10, rcx
0x140005360  xor     r8d, r8d; Locale
0x140005363  test    eax, eax
0x140005365  jnz     short loc_1400053CC
0x140005367  test    rcx, rcx
0x14000536a  jnz     short loc_140005386
0x14000536c  call    _errno
0x140005371  mov     dword ptr [rax], 16h
0x140005377  call    _invalid_parameter_noinfo
0x14000537c  mov     eax, 7FFFFFFFh
0x140005381  add     rsp, 28h
0x140005385  retn
0x140005386  test    rdx, rdx
0x140005389  jz      short loc_14000536C
0x14000538b  sub     r10, rdx
0x14000538e  movzx   edx, word ptr [r10+r9]
0x140005393  lea     eax, [rdx-41h]
0x140005396  cmp     ax, 19h
0x14000539a  ja      short loc_1400053A0
0x14000539c  add     dx, 20h ; ' '; String2
0x1400053a0  movzx   ecx, word ptr [r9]
0x1400053a4  lea     eax, [rcx-41h]
0x1400053a7  cmp     ax, 19h
0x1400053ab  ja      short loc_1400053B1
0x1400053ad  add     cx, 20h ; ' '
0x1400053b1  add     r9, 2
0x1400053b5  test    dx, dx
0x1400053b8  jz      short loc_1400053BF
0x1400053ba  cmp     dx, cx
0x1400053bd  jz      short loc_14000538E
0x1400053bf  movzx   ecx, cx; String1
0x1400053c2  movzx   eax, dx
0x1400053c5  sub     eax, ecx
0x1400053c7  add     rsp, 28h
0x1400053cb  retn
0x1400053cc  add     rsp, 28h
0x1400053d0  jmp     _wcsicmp_l

// ===== _wcsicmp_l @ 0x1400053d8 =====

0x1400053d8  mov     rax, rsp
0x1400053db  mov     [rax+8], rbx
0x1400053df  mov     [rax+10h], rbp
0x1400053e3  mov     [rax+18h], rsi
0x1400053e7  push    rdi
0x1400053e8  sub     rsp, 40h
0x1400053ec  mov     rdi, rdx
0x1400053ef  mov     rsi, rcx
0x1400053f2  mov     rdx, r8; struct __crt_locale_pointers *
0x1400053f5  lea     rcx, [rax-28h]; this
0x1400053f9  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x1400053fe  xor     ebp, ebp
0x140005400  test    rsi, rsi
0x140005403  jz      short loc_14000540A
0x140005405  test    rdi, rdi
0x140005408  jnz     short loc_140005421
0x14000540a  call    _errno
0x14000540f  mov     dword ptr [rax], 16h
0x140005415  call    _invalid_parameter_noinfo
0x14000541a  mov     eax, 7FFFFFFFh
0x14000541f  jmp     short loc_14000549D
0x140005421  mov     rax, [rsp+48h+Locale.locinfo]
0x140005426  cmp     [rax+138h], rbp
0x14000542d  jnz     short loc_140005463
0x14000542f  sub     rsi, rdi
0x140005432  movzx   ebx, word ptr [rsi+rdi]
0x140005436  lea     eax, [rbx-41h]
0x140005439  cmp     ax, 19h
0x14000543d  ja      short loc_140005443
0x14000543f  add     bx, 20h ; ' '
0x140005443  movzx   ecx, word ptr [rdi]
0x140005446  lea     eax, [rcx-41h]
0x140005449  cmp     ax, 19h
0x14000544d  ja      short loc_140005453
0x14000544f  add     cx, 20h ; ' '
0x140005453  add     rdi, 2
0x140005457  test    bx, bx
0x14000545a  jz      short loc_140005495
0x14000545c  cmp     bx, cx
0x14000545f  jz      short loc_140005432
0x140005461  jmp     short loc_140005495
0x140005463  movzx   ecx, word ptr [rsi]; C
0x140005466  lea     rdx, [rsp+48h+Locale]; Locale
0x14000546b  call    _towlower_l
0x140005470  movzx   ecx, word ptr [rdi]; C
0x140005473  lea     rdx, [rsp+48h+Locale]; Locale
0x140005478  movzx   ebx, ax
0x14000547b  lea     rsi, [rsi+2]
0x14000547f  call    _towlower_l
0x140005484  lea     rdi, [rdi+2]
0x140005488  movzx   ecx, ax
0x14000548b  test    bx, bx
0x14000548e  jz      short loc_140005495
0x140005490  cmp     bx, ax
0x140005493  jz      short loc_140005463
0x140005495  movzx   ecx, cx
0x140005498  movzx   eax, bx
0x14000549b  sub     eax, ecx
0x14000549d  cmp     [rsp+48h+var_10], bpl
0x1400054a2  jz      short loc_1400054B0
0x1400054a4  mov     rcx, [rsp+48h+var_28]
0x1400054a9  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x1400054b0  mov     rbx, [rsp+48h+arg_0]
0x1400054b5  mov     rbp, [rsp+48h+arg_8]
0x1400054ba  mov     rsi, [rsp+48h+arg_10]
0x1400054bf  add     rsp, 40h
0x1400054c3  pop     rdi
0x1400054c4  retn

// ===== wcscpy_s @ 0x1400054c8 =====

0x1400054c8  push    rbx
0x1400054ca  sub     rsp, 20h
0x1400054ce  xor     ebx, ebx
0x1400054d0  test    rcx, rcx
0x1400054d3  jz      short loc_1400054E2
0x1400054d5  test    rdx, rdx
0x1400054d8  jz      short loc_1400054E2
0x1400054da  test    r8, r8
0x1400054dd  jnz     short loc_1400054FB
0x1400054df  mov     [rcx], bx
0x1400054e2  call    _errno
0x1400054e7  mov     ebx, 16h
0x1400054ec  mov     [rax], ebx
0x1400054ee  call    _invalid_parameter_noinfo
0x1400054f3  mov     eax, ebx
0x1400054f5  add     rsp, 20h
0x1400054f9  pop     rbx
0x1400054fa  retn
0x1400054fb  mov     r9, rcx
0x1400054fe  sub     r8, rcx
0x140005501  movzx   eax, word ptr [r8+r9]
0x140005506  mov     [r9], ax
0x14000550a  lea     r9, [r9+2]
0x14000550e  test    ax, ax
0x140005511  jz      short loc_140005519
0x140005513  sub     rdx, 1
0x140005517  jnz     short loc_140005501
0x140005519  test    rdx, rdx
0x14000551c  jnz     short loc_1400054F3
0x14000551e  mov     [rcx], bx
0x140005521  call    _errno
0x140005526  mov     ebx, 22h ; '"'
0x14000552b  jmp     short loc_1400054EC

// ===== wcscat_s @ 0x140005530 =====

0x140005530  push    rbx
0x140005532  sub     rsp, 20h
0x140005536  xor     ebx, ebx
0x140005538  mov     r9, rcx
0x14000553b  test    rcx, rcx
0x14000553e  jz      short loc_14000554D
0x140005540  test    rdx, rdx
0x140005543  jz      short loc_14000554D
0x140005545  test    r8, r8
0x140005548  jnz     short loc_140005566
0x14000554a  mov     [rcx], bx
0x14000554d  call    _errno
0x140005552  mov     ebx, 16h
0x140005557  mov     [rax], ebx
0x140005559  call    _invalid_parameter_noinfo
0x14000555e  mov     eax, ebx
0x140005560  add     rsp, 20h
0x140005564  pop     rbx
0x140005565  retn
0x140005566  cmp     [rcx], bx
0x140005569  jz      short loc_140005575
0x14000556b  add     rcx, 2
0x14000556f  sub     rdx, 1
0x140005573  jnz     short loc_140005566
0x140005575  test    rdx, rdx
0x140005578  jnz     short loc_140005580
0x14000557a  mov     [r9], bx
0x14000557e  jmp     short loc_14000554D
0x140005580  sub     r8, rcx
0x140005583  movzx   eax, word ptr [r8+rcx]
0x140005588  mov     [rcx], ax
0x14000558b  lea     rcx, [rcx+2]
0x14000558f  test    ax, ax
0x140005592  jz      short loc_14000559A
0x140005594  sub     rdx, 1
0x140005598  jnz     short loc_140005583
0x14000559a  test    rdx, rdx
0x14000559d  jnz     short loc_14000555E
0x14000559f  mov     [r9], bx
0x1400055a3  call    _errno
0x1400055a8  mov     ebx, 22h ; '"'
0x1400055ad  jmp     short loc_140005557

// ===== _seh_filter_exe @ 0x1400055b0 =====

0x1400055b0  mov     [rsp+arg_0], rbx
0x1400055b5  mov     [rsp+arg_8], rbp
0x1400055ba  mov     [rsp+arg_10], rsi
0x1400055bf  push    rdi
0x1400055c0  sub     rsp, 20h
0x1400055c4  mov     rsi, rdx
0x1400055c7  mov     edi, ecx
0x1400055c9  call    __acrt_getptd_noexit
0x1400055ce  xor     r8d, r8d
0x1400055d1  mov     rbx, rax
0x1400055d4  test    rax, rax
0x1400055d7  jnz     short loc_1400055E0
0x1400055d9  xor     eax, eax
0x1400055db  jmp     loc_140005728
0x1400055e0  mov     rcx, [rax]
0x1400055e3  mov     rax, rcx
0x1400055e6  lea     rdx, [rcx+0C0h]
0x1400055ed  cmp     rcx, rdx
0x1400055f0  jz      short loc_1400055FF
0x1400055f2  cmp     [rax], edi
0x1400055f4  jz      short loc_140005602
0x1400055f6  add     rax, 10h
0x1400055fa  cmp     rax, rdx
0x1400055fd  jnz     short loc_1400055F2
0x1400055ff  mov     rax, r8
0x140005602  test    rax, rax
0x140005605  jz      short loc_1400055D9
0x140005607  mov     rdi, [rax+8]
0x14000560b  test    rdi, rdi
0x14000560e  jz      short loc_1400055D9
0x140005610  cmp     rdi, 5
0x140005614  jnz     short loc_140005622
0x140005616  mov     [rax+8], r8
0x14000561a  lea     eax, [rdi-4]
0x14000561d  jmp     loc_140005728
0x140005622  cmp     rdi, 1
0x140005626  jz      loc_140005725
0x14000562c  mov     rbp, [rbx+8]
0x140005630  mov     [rbx+8], rsi
0x140005634  mov     esi, [rax+4]
0x140005637  cmp     esi, 8
0x14000563a  jnz     loc_140005710
0x140005640  add     rcx, 30h ; '0'
0x140005644  lea     rdx, [rcx+90h]
0x14000564b  jmp     short loc_140005655
0x14000564d  mov     [rcx+8], r8
0x140005651  add     rcx, 10h
0x140005655  cmp     rcx, rdx
0x140005658  jnz     short loc_14000564D
0x14000565a  cmp     dword ptr [rax], 0C000008Dh
0x140005660  mov     esi, [rbx+10h]
0x140005663  jz      loc_1400056F1
0x140005669  cmp     dword ptr [rax], 0C000008Eh
0x14000566f  jz      short loc_1400056E8
0x140005671  cmp     dword ptr [rax], 0C000008Fh
0x140005677  jz      short loc_1400056DF
0x140005679  cmp     dword ptr [rax], 0C0000090h
0x14000567f  jz      short loc_1400056D6
0x140005681  cmp     dword ptr [rax], 0C0000091h
0x140005687  jz      short loc_1400056CD
0x140005689  cmp     dword ptr [rax], 0C0000092h
0x14000568f  jz      short loc_1400056C4
0x140005691  cmp     dword ptr [rax], 0C0000093h
0x140005697  jz      short loc_1400056BB
0x140005699  cmp     dword ptr [rax], 0C00002B4h
0x14000569f  jz      short loc_1400056B2
0x1400056a1  cmp     dword ptr [rax], 0C00002B5h
0x1400056a7  jnz     short loc_1400056F8
0x1400056a9  mov     dword ptr [rbx+10h], 8Dh
0x1400056b0  jmp     short loc_1400056F8
0x1400056b2  mov     dword ptr [rbx+10h], 8Eh
0x1400056b9  jmp     short loc_1400056F8
0x1400056bb  mov     dword ptr [rbx+10h], 85h
0x1400056c2  jmp     short loc_1400056F8
0x1400056c4  mov     dword ptr [rbx+10h], 8Ah
0x1400056cb  jmp     short loc_1400056F8
0x1400056cd  mov     dword ptr [rbx+10h], 84h
0x1400056d4  jmp     short loc_1400056F8
0x1400056d6  mov     dword ptr [rbx+10h], 81h
0x1400056dd  jmp     short loc_1400056F8
0x1400056df  mov     dword ptr [rbx+10h], 86h
0x1400056e6  jmp     short loc_1400056F8
0x1400056e8  mov     dword ptr [rbx+10h], 83h
0x1400056ef  jmp     short loc_1400056F8
0x1400056f1  mov     dword ptr [rbx+10h], 82h
0x1400056f8  mov     rcx, rdi
0x1400056fb  call    cs:__guard_check_icall_fptr
0x140005701  mov     edx, [rbx+10h]
0x140005704  mov     ecx, 8
0x140005709  call    rdi
0x14000570b  mov     [rbx+10h], esi
0x14000570e  jmp     short loc_140005721
0x140005710  mov     rcx, rdi
0x140005713  mov     [rax+8], r8
0x140005717  call    cs:__guard_check_icall_fptr
0x14000571d  mov     ecx, esi
0x14000571f  call    rdi
0x140005721  mov     [rbx+8], rbp
0x140005725  or      eax, 0FFFFFFFFh
0x140005728  mov     rbx, [rsp+28h+arg_0]
0x14000572d  mov     rbp, [rsp+28h+arg_8]
0x140005732  mov     rsi, [rsp+28h+arg_10]
0x140005737  add     rsp, 20h
0x14000573b  pop     rdi
0x14000573c  retn

// ===== sub_140005740 @ 0x140005740 =====

0x140005740  mov     eax, cs:dword_14001D090
0x140005746  retn

// ===== sub_140005748 @ 0x140005748 =====

0x140005748  mov     cs:dword_14001D090, ecx
0x14000574e  retn

// ===== __acrt_has_user_matherr @ 0x140005750 =====

0x140005750  mov     rdx, cs:__security_cookie
0x140005757  mov     ecx, edx
0x140005759  xor     rdx, cs:qword_14001D098
0x140005760  and     ecx, 3Fh
0x140005763  ror     rdx, cl
0x140005766  test    rdx, rdx
0x140005769  setnz   al
0x14000576c  retn

// ===== sub_140005770 @ 0x140005770 =====

0x140005770  mov     cs:qword_14001D098, rcx
0x140005777  retn

// ===== __acrt_invoke_user_matherr @ 0x140005778 =====

0x140005778  mov     [rsp+arg_0], rbx
0x14000577d  push    rdi
0x14000577e  sub     rsp, 20h
0x140005782  mov     rbx, cs:__security_cookie
0x140005789  mov     rdi, rcx
0x14000578c  mov     ecx, ebx
0x14000578e  xor     rbx, cs:qword_14001D098
0x140005795  and     ecx, 3Fh
0x140005798  ror     rbx, cl
0x14000579b  test    rbx, rbx
0x14000579e  jnz     short loc_1400057A4
0x1400057a0  xor     eax, eax
0x1400057a2  jmp     short loc_1400057B2
0x1400057a4  mov     rcx, rbx
0x1400057a7  call    cs:__guard_check_icall_fptr
0x1400057ad  mov     rcx, rdi
0x1400057b0  call    rbx
0x1400057b2  mov     rbx, [rsp+28h+arg_0]
0x1400057b7  add     rsp, 20h
0x1400057bb  pop     rdi
0x1400057bc  retn

// ===== __setusermatherr @ 0x1400057c0 =====

0x1400057c0  mov     r8, cs:__security_cookie
0x1400057c7  mov     r9, rcx
0x1400057ca  mov     edx, r8d
0x1400057cd  mov     ecx, 40h ; '@'
0x1400057d2  and     edx, 3Fh
0x1400057d5  sub     ecx, edx
0x1400057d7  ror     r9, cl
0x1400057da  xor     r9, r8
0x1400057dd  mov     cs:qword_14001D098, r9
0x1400057e4  retn

// ===== ??$parse_command_line@_W@@YAXPEA_WPEAPEA_W0PEA_K2@Z @ 0x1400057e8 =====

0x1400057e8  mov     rax, rsp
0x1400057eb  mov     [rax+8], rbx
0x1400057ef  mov     [rax+10h], rsi
0x1400057f3  mov     [rax+18h], rdi
0x1400057f7  mov     [rax+20h], r12
0x1400057fb  push    r15
0x1400057fd  mov     r10, [rsp+8+arg_20]
0x140005802  xor     esi, esi
0x140005804  mov     rbx, r9
0x140005807  mov     [r10], rsi
0x14000580a  mov     qword ptr [r9], 1
0x140005811  test    rdx, rdx
0x140005814  jz      short loc_14000581D
0x140005816  mov     [rdx], r8
0x140005819  add     rdx, 8
0x14000581d  mov     r9b, sil
0x140005820  mov     r12d, 22h ; '"'
0x140005826  cmp     [rcx], r12w
0x14000582a  jnz     short loc_14000583D
0x14000582c  test    r9b, r9b
0x14000582f  movzx   eax, r12w
0x140005833  setz    r9b
0x140005837  add     rcx, 2
0x14000583b  jmp     short loc_14000585C
0x14000583d  inc     qword ptr [r10]
0x140005840  test    r8, r8
0x140005843  jz      short loc_140005850
0x140005845  movzx   eax, word ptr [rcx]
0x140005848  mov     [r8], ax
0x14000584c  add     r8, 2
0x140005850  movzx   eax, word ptr [rcx]
0x140005853  add     rcx, 2
0x140005857  test    ax, ax
0x14000585a  jz      short loc_140005879
0x14000585c  test    r9b, r9b
0x14000585f  jnz     short loc_140005826
0x140005861  cmp     ax, 20h ; ' '
0x140005865  jz      short loc_14000586D
0x140005867  cmp     ax, 9
0x14000586b  jnz     short loc_140005826
0x14000586d  test    r8, r8
0x140005870  jz      short loc_14000587D
0x140005872  mov     [r8-2], si
0x140005877  jmp     short loc_14000587D
0x140005879  sub     rcx, 2
0x14000587d  mov     dil, sil
0x140005880  mov     r15d, 5Ch ; '\'
0x140005886  cmp     [rcx], si
0x140005889  jz      loc_14000595C
0x14000588f  cmp     word ptr [rcx], 20h ; ' '
0x140005893  jz      short loc_14000589B
0x140005895  cmp     word ptr [rcx], 9
0x140005899  jnz     short loc_1400058A1
0x14000589b  add     rcx, 2
0x14000589f  jmp     short loc_14000588F
0x1400058a1  cmp     [rcx], si
0x1400058a4  jz      loc_14000595C
0x1400058aa  test    rdx, rdx
0x1400058ad  jz      short loc_1400058B6
0x1400058af  mov     [rdx], r8
0x1400058b2  add     rdx, 8
0x1400058b6  inc     qword ptr [rbx]
0x1400058b9  mov     r11d, 1
0x1400058bf  mov     eax, esi
0x1400058c1  jmp     short loc_1400058C9
0x1400058c3  add     rcx, 2
0x1400058c7  inc     eax
0x1400058c9  cmp     [rcx], r15w
0x1400058cd  jz      short loc_1400058C3
0x1400058cf  cmp     [rcx], r12w
0x1400058d3  jnz     short loc_14000590C
0x1400058d5  test    r11b, al
0x1400058d8  jnz     short loc_1400058F6
0x1400058da  test    dil, dil
0x1400058dd  jz      short loc_1400058EC
0x1400058df  cmp     [rcx+2], r12w
0x1400058e4  jnz     short loc_1400058EC
0x1400058e6  add     rcx, 2
0x1400058ea  jmp     short loc_1400058F6
0x1400058ec  test    dil, dil
0x1400058ef  mov     r11d, esi
0x1400058f2  setz    dil
0x1400058f6  shr     eax, 1
0x1400058f8  jmp     short loc_14000590C
0x1400058fa  dec     eax
0x1400058fc  test    r8, r8
0x1400058ff  jz      short loc_140005909
0x140005901  mov     [r8], r15w
0x140005905  add     r8, 2
0x140005909  inc     qword ptr [r10]
0x14000590c  test    eax, eax
0x14000590e  jnz     short loc_1400058FA
0x140005910  movzx   eax, word ptr [rcx]
0x140005913  test    ax, ax
0x140005916  jz      short loc_140005947
0x140005918  test    dil, dil
0x14000591b  jnz     short loc_140005929
0x14000591d  cmp     ax, 20h ; ' '
0x140005921  jz      short loc_140005947
0x140005923  cmp     ax, 9
0x140005927  jz      short loc_140005947
0x140005929  test    r11d, r11d
0x14000592c  jz      short loc_14000593E
0x14000592e  test    r8, r8
0x140005931  jz      short loc_14000593B
0x140005933  mov     [r8], ax
0x140005937  add     r8, 2
0x14000593b  inc     qword ptr [r10]
0x14000593e  add     rcx, 2
0x140005942  jmp     loc_1400058B9
0x140005947  test    r8, r8
0x14000594a  jz      short loc_140005954
0x14000594c  mov     [r8], si
0x140005950  add     r8, 2
0x140005954  inc     qword ptr [r10]
0x140005957  jmp     loc_140005886
0x14000595c  test    rdx, rdx
0x14000595f  jz      short loc_140005964
0x140005961  mov     [rdx], rsi
0x140005964  inc     qword ptr [rbx]
0x140005967  mov     rbx, [rsp+8+arg_0]
0x14000596c  mov     rsi, [rsp+8+arg_8]
0x140005971  mov     rdi, [rsp+8+arg_10]
0x140005976  mov     r12, [rsp+8+arg_18]
0x14000597b  pop     r15
0x14000597d  retn

// ===== __acrt_allocate_buffer_for_argv @ 0x140005980 =====

0x140005980  push    rbx
0x140005982  sub     rsp, 20h
0x140005986  mov     rax, 1FFFFFFFFFFFFFFFh
0x140005990  mov     r9, rdx
0x140005993  mov     r10, rcx
0x140005996  cmp     rcx, rax
0x140005999  jb      short loc_14000599F
0x14000599b  xor     eax, eax
0x14000599d  jmp     short loc_1400059DB
0x14000599f  or      rcx, 0FFFFFFFFFFFFFFFFh
0x1400059a3  xor     edx, edx
0x1400059a5  mov     rax, rcx
0x1400059a8  div     r8
0x1400059ab  cmp     r9, rax
0x1400059ae  jnb     short loc_14000599B
0x1400059b0  shl     r10, 3
0x1400059b4  imul    r9, r8
0x1400059b8  sub     rcx, r10
0x1400059bb  cmp     rcx, r9
0x1400059be  jbe     short loc_14000599B
0x1400059c0  lea     rcx, [r9+r10]; Count
0x1400059c4  mov     edx, 1; Size
0x1400059c9  call    _calloc_base
0x1400059ce  xor     ecx, ecx; Block
0x1400059d0  mov     rbx, rax
0x1400059d3  call    _free_base
0x1400059d8  mov     rax, rbx
0x1400059db  add     rsp, 20h
0x1400059df  pop     rbx
0x1400059e0  retn

// ===== _configure_wide_argv @ 0x1400059e4 =====

0x1400059e4  mov     [rsp-28h+arg_0], rbx
0x1400059e9  push    rbp
0x1400059ea  push    rsi
0x1400059eb  push    rdi
0x1400059ec  push    r14
0x1400059ee  push    r15
0x1400059f0  mov     rbp, rsp
0x1400059f3  sub     rsp, 30h
0x1400059f7  lea     eax, [rcx-1]
0x1400059fa  mov     r14d, ecx
0x1400059fd  cmp     eax, 1
0x140005a00  jbe     short loc_140005A18
0x140005a02  call    _errno
0x140005a07  mov     edi, 16h
0x140005a0c  mov     [rax], edi
0x140005a0e  call    _invalid_parameter_noinfo
0x140005a13  jmp     loc_140005B42
0x140005a18  lea     rbx, Filename
0x140005a1f  mov     r8d, 104h; nSize
0x140005a25  mov     rdx, rbx; lpFilename
0x140005a28  xor     ecx, ecx; hModule
0x140005a2a  call    cs:GetModuleFileNameW; KERNEL32
0x140005a30  mov     rsi, cs:qword_14001D948
0x140005a37  xor     edi, edi
0x140005a39  mov     cs:qword_14001D950, rbx
0x140005a40  test    rsi, rsi
0x140005a43  jz      short loc_140005A4A
0x140005a45  cmp     [rsi], di
0x140005a48  jnz     short loc_140005A4D
0x140005a4a  mov     rsi, rbx
0x140005a4d  lea     rax, [rbp+arg_18]
0x140005a51  mov     [rbp+arg_10], rdi
0x140005a55  lea     r9, [rbp+arg_10]
0x140005a59  mov     [rsp+30h+var_10], rax
0x140005a5e  xor     r8d, r8d
0x140005a61  mov     [rbp+arg_18], rdi
0x140005a65  xor     edx, edx
0x140005a67  mov     rcx, rsi
0x140005a6a  call    ??$parse_command_line@_W@@YAXPEA_WPEAPEA_W0PEA_K2@Z
0x140005a6f  mov     r15, [rbp+arg_10]
0x140005a73  mov     r8d, 2
0x140005a79  mov     rdx, [rbp+arg_18]
0x140005a7d  mov     rcx, r15
0x140005a80  call    __acrt_allocate_buffer_for_argv
0x140005a85  mov     rbx, rax
0x140005a88  test    rax, rax
0x140005a8b  jnz     short loc_140005A9E
0x140005a8d  call    _errno
0x140005a92  lea     edi, [rbx+0Ch]
0x140005a95  mov     [rax], edi
0x140005a97  xor     ecx, ecx
0x140005a99  jmp     loc_140005B3D
0x140005a9e  lea     r8, [rax+r15*8]
0x140005aa2  mov     rdx, rbx
0x140005aa5  lea     rax, [rbp+arg_18]
0x140005aa9  mov     rcx, rsi
0x140005aac  lea     r9, [rbp+arg_10]
0x140005ab0  mov     [rsp+30h+var_10], rax
0x140005ab5  call    ??$parse_command_line@_W@@YAXPEA_WPEAPEA_W0PEA_K2@Z
0x140005aba  cmp     r14d, 1
0x140005abe  jnz     short loc_140005AD4
0x140005ac0  mov     eax, dword ptr [rbp+arg_10]
0x140005ac3  dec     eax
0x140005ac5  mov     cs:qword_14001D938, rbx
0x140005acc  mov     cs:dword_14001D92C, eax
0x140005ad2  jmp     short loc_140005A97
0x140005ad4  lea     rdx, [rbp+Block]
0x140005ad8  mov     [rbp+Block], rdi
0x140005adc  mov     rcx, rbx
0x140005adf  call    j_??$common_expand_argv_wildcards@_W@@YAHQEAPEA_WQEAPEAPEA_W@Z
0x140005ae4  mov     esi, eax
0x140005ae6  test    eax, eax
0x140005ae8  jz      short loc_140005B03
0x140005aea  mov     rcx, [rbp+Block]; Block
0x140005aee  call    _free_base
0x140005af3  mov     rcx, rbx; Block
0x140005af6  mov     [rbp+Block], rdi
0x140005afa  call    _free_base
0x140005aff  mov     edi, esi
0x140005b01  jmp     short loc_140005B42
0x140005b03  mov     rdx, [rbp+Block]
0x140005b07  mov     rcx, rdi
0x140005b0a  mov     rax, rdx
0x140005b0d  cmp     [rdx], rdi
0x140005b10  jz      short loc_140005B1E
0x140005b12  lea     rax, [rax+8]
0x140005b16  inc     rcx
0x140005b19  cmp     [rax], rdi
0x140005b1c  jnz     short loc_140005B12
0x140005b1e  mov     cs:dword_14001D92C, ecx
0x140005b24  xor     ecx, ecx; Block
0x140005b26  mov     [rbp+Block], rdi
0x140005b2a  mov     cs:qword_14001D938, rdx
0x140005b31  call    _free_base
0x140005b36  mov     rcx, rbx; Block
0x140005b39  mov     [rbp+Block], rdi
0x140005b3d  call    _free_base
0x140005b42  mov     eax, edi
0x140005b44  mov     rbx, [rsp+30h+arg_0]
0x140005b49  add     rsp, 30h
0x140005b4d  pop     r15
0x140005b4f  pop     r14
0x140005b51  pop     rdi
0x140005b52  pop     rsi
0x140005b53  pop     rbp
0x140005b54  retn

// ===== ??$common_initialize_environment_nolock@_W@@YAHXZ @ 0x140005b58 =====

0x140005b58  mov     [rsp+arg_0], rbx
0x140005b5d  push    rdi
0x140005b5e  sub     rsp, 20h
0x140005b62  xor     edi, edi
0x140005b64  cmp     cs:qword_14001D2B8, rdi
0x140005b6b  jz      short loc_140005B71
0x140005b6d  xor     eax, eax
0x140005b6f  jmp     short loc_140005BB4
0x140005b71  call    __dcrt_get_wide_environment_from_os
0x140005b76  mov     rbx, rax
0x140005b79  test    rax, rax
0x140005b7c  jnz     short loc_140005B83
0x140005b7e  or      edi, 0FFFFFFFFh
0x140005b81  jmp     short loc_140005BAA
0x140005b83  mov     rcx, rax; Source
0x140005b86  call    ??$create_environment@_W@@YAQEAPEA_WQEA_W@Z
0x140005b8b  test    rax, rax
0x140005b8e  jnz     short loc_140005B95
0x140005b90  or      edi, 0FFFFFFFFh
0x140005b93  jmp     short loc_140005BA3
0x140005b95  mov     cs:qword_14001D2C0, rax
0x140005b9c  mov     cs:qword_14001D2B8, rax
0x140005ba3  xor     ecx, ecx; Block
0x140005ba5  call    _free_base
0x140005baa  mov     rcx, rbx; Block
0x140005bad  call    _free_base
0x140005bb2  mov     eax, edi
0x140005bb4  mov     rbx, [rsp+28h+arg_0]
0x140005bb9  add     rsp, 20h
0x140005bbd  pop     rdi
0x140005bbe  retn

// ===== ??$create_environment@_W@@YAQEAPEA_WQEA_W@Z @ 0x140005bc0 =====

0x140005bc0  mov     [rsp+arg_0], rbx
0x140005bc5  mov     [rsp+arg_8], rbp
0x140005bca  mov     [rsp+arg_10], rsi
0x140005bcf  push    rdi
0x140005bd0  push    r14
0x140005bd2  push    r15
0x140005bd4  sub     rsp, 30h
0x140005bd8  xor     esi, esi
0x140005bda  mov     r14, rcx
0x140005bdd  mov     edx, esi
0x140005bdf  jmp     short loc_140005BFF
0x140005be1  cmp     ax, 3Dh ; '='
0x140005be5  jz      short loc_140005BEA
0x140005be7  inc     rdx
0x140005bea  or      rax, 0FFFFFFFFFFFFFFFFh
0x140005bee  inc     rax
0x140005bf1  cmp     [rcx+rax*2], si
0x140005bf5  jnz     short loc_140005BEE
0x140005bf7  lea     rcx, [rcx+rax*2]
0x140005bfb  add     rcx, 2
0x140005bff  movzx   eax, word ptr [rcx]
0x140005c02  test    ax, ax
0x140005c05  jnz     short loc_140005BE1
0x140005c07  lea     rcx, [rdx+1]; Count
0x140005c0b  mov     edx, 8; Size
0x140005c10  call    _calloc_base
0x140005c15  mov     rbx, rax
0x140005c18  test    rax, rax
0x140005c1b  jz      short loc_140005C8D
0x140005c1d  mov     r15, rax
0x140005c20  cmp     [r14], si
0x140005c24  jz      short loc_140005C8A
0x140005c26  or      rbp, 0FFFFFFFFFFFFFFFFh
0x140005c2a  inc     rbp
0x140005c2d  cmp     [r14+rbp*2], si
0x140005c32  jnz     short loc_140005C2A
0x140005c34  inc     rbp
0x140005c37  cmp     word ptr [r14], 3Dh ; '='
0x140005c3c  jz      short loc_140005C73
0x140005c3e  mov     edx, 2; Size
0x140005c43  mov     rcx, rbp; Count
0x140005c46  call    _calloc_base
0x140005c4b  mov     rdi, rax
0x140005c4e  test    rax, rax
0x140005c51  jz      short loc_140005C79
0x140005c53  mov     r8, r14; Source
0x140005c56  mov     rdx, rbp; SizeInWords
0x140005c59  mov     rcx, rax; Destination
0x140005c5c  call    wcscpy_s
0x140005c61  xor     ecx, ecx; Block
0x140005c63  test    eax, eax
0x140005c65  jnz     short loc_140005CB0
0x140005c67  mov     [r15], rdi
0x140005c6a  add     r15, 8
0x140005c6e  call    _free_base
0x140005c73  lea     r14, [r14+rbp*2]
0x140005c77  jmp     short loc_140005C20
0x140005c79  mov     rcx, rbx; Block
0x140005c7c  call    unknown_libname_14; Microsoft VisualC 64bit universal runtime
0x140005c81  xor     ecx, ecx; Block
0x140005c83  call    _free_base
0x140005c88  jmp     short loc_140005C8D
0x140005c8a  mov     rsi, rbx
0x140005c8d  xor     ecx, ecx; Block
0x140005c8f  call    _free_base
0x140005c94  mov     rbx, [rsp+48h+arg_0]
0x140005c99  mov     rax, rsi
0x140005c9c  mov     rsi, [rsp+48h+arg_10]
0x140005ca1  mov     rbp, [rsp+48h+arg_8]
0x140005ca6  add     rsp, 30h
0x140005caa  pop     r15
0x140005cac  pop     r14
0x140005cae  pop     rdi
0x140005caf  retn
0x140005cb0  xor     r9d, r9d; LineNo
0x140005cb3  mov     [rsp+48h+Reserved], rsi; Reserved
0x140005cb8  xor     r8d, r8d; FileName
0x140005cbb  xor     edx, edx; FunctionName
0x140005cbd  call    _invoke_watson

// ===== unknown_libname_14 @ 0x140005cc4 =====

0x140005cc4  test    rcx, rcx
0x140005cc7  jz      short locret_140005D04
0x140005cc9  mov     [rsp+arg_0], rbx
0x140005cce  push    rdi
0x140005ccf  sub     rsp, 20h
0x140005cd3  mov     rax, [rcx]
0x140005cd6  mov     rbx, rcx
0x140005cd9  mov     rdi, rcx
0x140005cdc  jmp     short loc_140005CED
0x140005cde  mov     rcx, rax; Block
0x140005ce1  call    _free_base
0x140005ce6  lea     rdi, [rdi+8]
0x140005cea  mov     rax, [rdi]
0x140005ced  test    rax, rax
0x140005cf0  jnz     short loc_140005CDE
0x140005cf2  mov     rcx, rbx; Block
0x140005cf5  call    _free_base
0x140005cfa  mov     rbx, [rsp+28h+arg_0]
0x140005cff  add     rsp, 20h
0x140005d03  pop     rdi
0x140005d04  retn

// ===== sub_140005D08 @ 0x140005d08 =====

0x140005d08  sub     rsp, 28h
0x140005d0c  mov     rcx, [rcx]; Block
0x140005d0f  cmp     rcx, cs:qword_14001D2C8
0x140005d16  jz      short loc_140005D1D
0x140005d18  call    unknown_libname_14; Microsoft VisualC 64bit universal runtime
0x140005d1d  add     rsp, 28h
0x140005d21  retn

// ===== sub_140005D24 @ 0x140005d24 =====

0x140005d24  sub     rsp, 28h
0x140005d28  mov     rcx, [rcx]; Block
0x140005d2b  cmp     rcx, cs:qword_14001D2C0
0x140005d32  jz      short loc_140005D39
0x140005d34  call    unknown_libname_14; Microsoft VisualC 64bit universal runtime
0x140005d39  add     rsp, 28h
0x140005d3d  retn

// ===== __dcrt_uninitialize_environments_nolock @ 0x140005d40 =====

0x140005d40  sub     rsp, 28h
0x140005d44  lea     rcx, qword_14001D2B0
0x140005d4b  call    sub_140005D08
0x140005d50  lea     rcx, qword_14001D2B8
0x140005d57  call    sub_140005D24
0x140005d5c  mov     rcx, cs:qword_14001D2C8; Block
0x140005d63  call    unknown_libname_14; Microsoft VisualC 64bit universal runtime
0x140005d68  mov     rcx, cs:qword_14001D2C0; Block
0x140005d6f  add     rsp, 28h
0x140005d73  jmp     unknown_libname_14; Microsoft VisualC 64bit universal runtime

// ===== j_??$common_initialize_environment_nolock@_W@@YAHXZ @ 0x140005d78 =====

0x140005d78  jmp     ??$common_initialize_environment_nolock@_W@@YAHXZ

// ===== _get_wide_winmain_command_line @ 0x140005d80 =====

0x140005d80  mov     rax, cs:qword_14001D948
0x140005d87  lea     rcx, unk_14001D2D0
0x140005d8e  xor     edx, edx
0x140005d90  test    rax, rax
0x140005d93  cmovnz  rcx, rax
0x140005d97  mov     al, dl
0x140005d99  cmp     word ptr [rcx], 20h ; ' '
0x140005d9d  ja      short loc_140005DA8
0x140005d9f  cmp     [rcx], dx
0x140005da2  jz      short loc_140005DCB
0x140005da4  test    al, al
0x140005da6  jz      short loc_140005DC3
0x140005da8  cmp     word ptr [rcx], 22h ; '"'
0x140005dac  jnz     short loc_140005DB3
0x140005dae  test    al, al
0x140005db0  setz    al
0x140005db3  add     rcx, 2
0x140005db7  jmp     short loc_140005D99
0x140005db9  cmp     ax, 20h ; ' '
0x140005dbd  ja      short loc_140005DCB
0x140005dbf  add     rcx, 2
0x140005dc3  movzx   eax, word ptr [rcx]
0x140005dc6  test    ax, ax
0x140005dc9  jnz     short loc_140005DB9
0x140005dcb  mov     rax, rcx
0x140005dce  retn

// ===== _initterm @ 0x140005dd0 =====

0x140005dd0  mov     rax, rsp
0x140005dd3  mov     [rax+8], rbx
0x140005dd7  mov     [rax+10h], rbp
0x140005ddb  mov     [rax+18h], rsi
0x140005ddf  mov     [rax+20h], rdi
0x140005de3  push    r14
0x140005de5  sub     rsp, 20h
0x140005de9  xor     r14d, r14d
0x140005dec  mov     rdi, rdx
0x140005def  sub     rdi, rcx
0x140005df2  mov     rbx, rcx
0x140005df5  add     rdi, 7
0x140005df9  mov     ebp, r14d
0x140005dfc  shr     rdi, 3
0x140005e00  cmp     rcx, rdx
0x140005e03  cmova   rdi, r14
0x140005e07  test    rdi, rdi
0x140005e0a  jz      short loc_140005E2B
0x140005e0c  mov     rsi, [rbx]
0x140005e0f  test    rsi, rsi
0x140005e12  jz      short loc_140005E1F
0x140005e14  mov     rcx, rsi
0x140005e17  call    cs:__guard_check_icall_fptr
0x140005e1d  call    rsi
0x140005e1f  add     rbx, 8
0x140005e23  inc     rbp
0x140005e26  cmp     rbp, rdi
0x140005e29  jnz     short loc_140005E0C
0x140005e2b  mov     rbx, [rsp+28h+arg_0]
0x140005e30  mov     rbp, [rsp+28h+arg_8]
0x140005e35  mov     rsi, [rsp+28h+arg_10]
0x140005e3a  mov     rdi, [rsp+28h+arg_18]
0x140005e3f  add     rsp, 20h
0x140005e43  pop     r14
0x140005e45  retn

// ===== _initterm_e @ 0x140005e48 =====

0x140005e48  mov     [rsp+arg_0], rbx
0x140005e4d  mov     [rsp+arg_8], rsi
0x140005e52  push    rdi
0x140005e53  sub     rsp, 20h
0x140005e57  mov     rsi, rdx
0x140005e5a  mov     rbx, rcx
0x140005e5d  cmp     rcx, rdx
0x140005e60  jz      short loc_140005E82
0x140005e62  mov     rdi, [rbx]
0x140005e65  test    rdi, rdi
0x140005e68  jz      short loc_140005E79
0x140005e6a  mov     rcx, rdi
0x140005e6d  call    cs:__guard_check_icall_fptr
0x140005e73  call    rdi
0x140005e75  test    eax, eax
0x140005e77  jnz     short loc_140005E84
0x140005e79  add     rbx, 8
0x140005e7d  cmp     rbx, rsi
0x140005e80  jmp     short loc_140005E60
0x140005e82  xor     eax, eax
0x140005e84  mov     rbx, [rsp+28h+arg_0]
0x140005e89  mov     rsi, [rsp+28h+arg_8]
0x140005e8e  add     rsp, 20h
0x140005e92  pop     rdi
0x140005e93  retn

// ===== dyntls_init_exception_filter @ 0x140005e94 =====

0x140005e94  xor     eax, eax
0x140005e96  cmp     ecx, 0E06D7363h
0x140005e9c  setz    al
0x140005e9f  retn

// ===== ?common_exit@@YAXHW4_crt_exit_cleanup_mode@@W4_crt_exit_return_mode@@@Z @ 0x140005ea0 =====

0x140005ea0  mov     rax, rsp
0x140005ea3  mov     [rax+8], rbx
0x140005ea7  mov     [rax+10h], rsi
0x140005eab  mov     [rax+18h], rdi
0x140005eaf  mov     [rax+20h], r14
0x140005eb3  push    r15
0x140005eb5  sub     rsp, 20h
0x140005eb9  mov     esi, r8d
0x140005ebc  mov     ebx, edx
0x140005ebe  mov     r14d, ecx
0x140005ec1  test    r8d, r8d
0x140005ec4  jnz     short loc_140005F10
0x140005ec6  xor     ecx, ecx; lpModuleName
0x140005ec8  call    cs:GetModuleHandleW; KERNEL32
0x140005ece  test    rax, rax
0x140005ed1  jz      short loc_140005F10
0x140005ed3  mov     ecx, 5A4Dh
0x140005ed8  cmp     [rax], cx
0x140005edb  jnz     short loc_140005F10
0x140005edd  movsxd  rcx, dword ptr [rax+3Ch]
0x140005ee1  add     rcx, rax
0x140005ee4  cmp     dword ptr [rcx], 4550h
0x140005eea  jnz     short loc_140005F10
0x140005eec  mov     eax, 20Bh
0x140005ef1  cmp     [rcx+18h], ax
0x140005ef5  jnz     short loc_140005F10
0x140005ef7  cmp     dword ptr [rcx+84h], 0Eh
0x140005efe  jbe     short loc_140005F10
0x140005f00  cmp     [rcx+0F8h], esi
0x140005f06  jz      short loc_140005F10
0x140005f08  mov     ecx, r14d; unsigned int
0x140005f0b  call    ?try_cor_exit_process@@YAXI@Z
0x140005f10  mov     ecx, 2
0x140005f15  call    sub_14000AB5C
0x140005f1a  nop
0x140005f1b  cmp     cs:byte_14001D2E0, 0
0x140005f22  jnz     loc_140005FDA
0x140005f28  mov     r15d, 1
0x140005f2e  mov     eax, r15d
0x140005f31  xchg    eax, cs:dword_14001D2D4
0x140005f37  test    ebx, ebx
0x140005f39  jnz     short loc_140005F83
0x140005f3b  mov     rdi, cs:__security_cookie
0x140005f42  mov     edx, edi
0x140005f44  and     edx, 3Fh
0x140005f47  lea     ecx, [rbx+40h]
0x140005f4a  sub     ecx, edx
0x140005f4c  xor     eax, eax
0x140005f4e  ror     rax, cl
0x140005f51  xor     rax, rdi
0x140005f54  mov     rcx, cs:qword_14001D2D8
0x140005f5b  cmp     rcx, rax
0x140005f5e  jz      short loc_140005F7A
0x140005f60  xor     rdi, rcx
0x140005f63  mov     ecx, edx
0x140005f65  ror     rdi, cl
0x140005f68  mov     rcx, rdi
0x140005f6b  call    cs:__guard_check_icall_fptr
0x140005f71  xor     r8d, r8d
0x140005f74  xor     edx, edx
0x140005f76  xor     ecx, ecx
0x140005f78  call    rdi
0x140005f7a  lea     rcx, stru_14001D2F0
0x140005f81  jmp     short loc_140005F8F
0x140005f83  cmp     ebx, r15d
0x140005f86  jnz     short loc_140005F95
0x140005f88  lea     rcx, Table; Table
0x140005f8f  call    _execute_onexit_table
0x140005f94  nop
0x140005f95  test    ebx, ebx
0x140005f97  jnz     short loc_140005FAC
0x140005f99  lea     rdx, qword_1400113D0; Last
0x140005fa0  lea     rcx, qword_1400113B0; First
0x140005fa7  call    _initterm
0x140005fac  lea     rdx, qword_1400113E0; Last
0x140005fb3  lea     rcx, qword_1400113D8; First
0x140005fba  call    _initterm
0x140005fbf  movzx   eax, cs:byte_14001D2E0
0x140005fc6  test    esi, esi
0x140005fc8  cmovz   eax, r15d
0x140005fcc  mov     cs:byte_14001D2E0, al
0x140005fd2  jmp     short loc_140005FDA
0x140005fd4  call    terminate
0x140005fda  mov     ecx, 2
0x140005fdf  call    sub_14000ABB0
0x140005fe4  test    esi, esi
0x140005fe6  jnz     short loc_140005FF1
0x140005fe8  mov     ecx, r14d; unsigned int
0x140005feb  call    ?exit_or_terminate_process@@YAXI@Z
0x140005ff1  mov     rbx, [rsp+28h+arg_0]
0x140005ff6  mov     rsi, [rsp+28h+arg_8]
0x140005ffb  mov     rdi, [rsp+28h+arg_10]
0x140006000  mov     r14, [rsp+28h+arg_18]
0x140006005  add     rsp, 20h
0x140006009  pop     r15
0x14000600b  retn
0x1400109ee  push    rbp
0x1400109f0  sub     rsp, 20h
0x1400109f4  mov     rbp, rdx
0x1400109f7  mov     rax, [rcx]
0x1400109fa  mov     ecx, [rax]
0x1400109fc  call    dyntls_init_exception_filter
0x140010a01  nop
0x140010a02  add     rsp, 20h
0x140010a06  pop     rbp
0x140010a07  retn
0x140010a09  push    rbp; Microsoft VisualC 64bit universal runtime
0x140010a0b  sub     rsp, 20h
0x140010a0f  mov     rbp, rdx
0x140010a12  mov     ecx, 2
0x140010a17  add     rsp, 20h
0x140010a1b  pop     rbp
0x140010a1c  jmp     sub_14000ABB0

// ===== ?exit_or_terminate_process@@YAXI@Z @ 0x14000600c =====

0x14000600c  push    rbx
0x14000600e  sub     rsp, 20h
0x140006012  mov     ebx, ecx
0x140006014  call    __acrt_is_packaged_app
0x140006019  test    al, al
0x14000601b  jz      short loc_140006045
0x14000601d  mov     rax, gs:60h
0x140006026  mov     edx, [rax+0BCh]
0x14000602c  shr     edx, 8
0x14000602f  test    dl, 1
0x140006032  jnz     short loc_140006045
0x140006034  call    cs:GetCurrentProcess; KERNEL32
0x14000603a  mov     rcx, rax; hProcess
0x14000603d  mov     edx, ebx; uExitCode
0x14000603f  call    cs:TerminateProcess; KERNEL32
0x140006045  mov     ecx, ebx; unsigned int
0x140006047  call    ?try_cor_exit_process@@YAXI@Z
0x14000604c  mov     ecx, ebx; uExitCode
0x14000604e  call    cs:ExitProcess; KERNEL32

// ===== ?try_cor_exit_process@@YAXI@Z @ 0x140006058 =====

0x140006058  mov     [rsp+arg_0], rbx
0x14000605d  push    rdi
0x14000605e  sub     rsp, 20h
0x140006062  and     [rsp+28h+phModule], 0
0x140006068  lea     r8, [rsp+28h+phModule]; phModule
0x14000606d  mov     edi, ecx
0x14000606f  lea     rdx, ModuleName
0x140006076  xor     ecx, ecx; dwFlags
0x140006078  call    cs:GetModuleHandleExW; KERNEL32
0x14000607e  test    eax, eax
0x140006080  jz      short loc_1400060A9
0x140006082  mov     rcx, [rsp+28h+phModule]; hModule
0x140006087  lea     rdx, ProcName
0x14000608e  call    cs:GetProcAddress; KERNEL32
0x140006094  mov     rbx, rax
0x140006097  test    rax, rax
0x14000609a  jz      short loc_1400060A9
0x14000609c  mov     rcx, rax
0x14000609f  call    cs:__guard_check_icall_fptr
0x1400060a5  mov     ecx, edi
0x1400060a7  call    rbx
0x1400060a9  mov     rcx, [rsp+28h+phModule]; hLibModule
0x1400060ae  test    rcx, rcx
0x1400060b1  jz      short loc_1400060B9
0x1400060b3  call    cs:FreeLibrary; KERNEL32
0x1400060b9  mov     rbx, [rsp+28h+arg_0]
0x1400060be  add     rsp, 20h
0x1400060c2  pop     rdi
0x1400060c3  retn

// ===== sub_1400060C4 @ 0x1400060c4 =====

0x1400060c4  mov     cs:qword_14001D2D8, rcx
0x1400060cb  retn

// ===== _c_exit @ 0x1400060cc =====

0x1400060cc  mov     edx, 2; enum _crt_exit_cleanup_mode
0x1400060d1  xor     ecx, ecx; unsigned int
0x1400060d3  lea     r8d, [rdx-1]; enum _crt_exit_return_mode
0x1400060d7  jmp     ?common_exit@@YAXHW4_crt_exit_cleanup_mode@@W4_crt_exit_return_mode@@@Z

// ===== _cexit @ 0x1400060dc =====

0x1400060dc  xor     edx, edx; enum _crt_exit_cleanup_mode
0x1400060de  xor     ecx, ecx; unsigned int
0x1400060e0  lea     r8d, [rdx+1]; enum _crt_exit_return_mode
0x1400060e4  jmp     ?common_exit@@YAXHW4_crt_exit_cleanup_mode@@W4_crt_exit_return_mode@@@Z

// ===== _exit @ 0x1400060ec =====

0x1400060ec  xor     r8d, r8d; enum _crt_exit_return_mode
0x1400060ef  lea     edx, [r8+2]; enum _crt_exit_cleanup_mode
0x1400060f3  jmp     ?common_exit@@YAXHW4_crt_exit_cleanup_mode@@W4_crt_exit_return_mode@@@Z

// ===== _register_thread_local_exe_atexit_callback @ 0x1400060f8 =====

0x1400060f8  sub     rsp, 28h
0x1400060fc  mov     r8, cs:__security_cookie
0x140006103  mov     rdx, rcx
0x140006106  mov     eax, r8d
0x140006109  mov     ecx, 40h ; '@'
0x14000610e  and     eax, 3Fh
0x140006111  sub     ecx, eax
0x140006113  xor     eax, eax
0x140006115  ror     rax, cl
0x140006118  xor     rax, r8
0x14000611b  cmp     cs:qword_14001D2D8, rax
0x140006122  jnz     short loc_140006136
0x140006124  ror     rdx, cl
0x140006127  xor     rdx, r8
0x14000612a  mov     cs:qword_14001D2D8, rdx
0x140006131  add     rsp, 28h
0x140006135  retn
0x140006136  call    terminate

// ===== exit @ 0x14000613c =====

0x14000613c  xor     r8d, r8d; enum _crt_exit_return_mode
0x14000613f  xor     edx, edx; enum _crt_exit_cleanup_mode
0x140006141  jmp     ?common_exit@@YAXHW4_crt_exit_cleanup_mode@@W4_crt_exit_return_mode@@@Z

// ===== _set_fmode @ 0x140006148 =====

0x140006148  sub     rsp, 28h
0x14000614c  lea     eax, [rcx-4000h]
0x140006152  test    eax, 0FFFF3FFFh
0x140006157  jnz     short loc_14000616B
0x140006159  cmp     ecx, 0C000h
0x14000615f  jz      short loc_14000616B
0x140006161  xchg    ecx, cs:dword_14001DB6C
0x140006167  xor     eax, eax
0x140006169  jmp     short loc_140006180
0x14000616b  call    _errno
0x140006170  mov     dword ptr [rax], 16h
0x140006176  call    _invalid_parameter_noinfo
0x14000617b  mov     eax, 16h
0x140006180  add     rsp, 28h
0x140006184  retn

// ===== __acrt_set_locale_changed @ 0x140006188 =====

0x140006188  mov     eax, 1
0x14000618d  xchg    eax, cs:dword_14001D2E4
0x140006193  retn

// ===== __acrt_uninitialize_locale @ 0x140006194 =====

0x140006194  push    rdi
0x140006196  sub     rsp, 20h
0x14000619a  lea     rdi, off_14001C160
0x1400061a1  cmp     cs:qword_14001D340, rdi
0x1400061a8  jz      short loc_1400061D5
0x1400061aa  mov     ecx, 4
0x1400061af  call    sub_14000AB5C
0x1400061b4  nop
0x1400061b5  mov     rdx, rdi
0x1400061b8  lea     rcx, qword_14001D340
0x1400061bf  call    _updatetlocinfoEx_nolock
0x1400061c4  mov     cs:qword_14001D340, rax
0x1400061cb  mov     ecx, 4
0x1400061d0  call    sub_14000ABB0
0x1400061d5  add     rsp, 20h
0x1400061d9  pop     rdi
0x1400061da  retn
0x140010a22  push    rbp; Microsoft VisualC 64bit universal runtime
0x140010a24  sub     rsp, 20h
0x140010a28  mov     rbp, rdx
0x140010a2b  mov     ecx, 4
0x140010a30  add     rsp, 20h
0x140010a34  pop     rbp
0x140010a35  jmp     sub_14000ABB0

// ===== _configthreadlocale @ 0x1400061dc =====

0x1400061dc  push    rbx
0x1400061de  sub     rsp, 20h
0x1400061e2  mov     ebx, ecx
0x1400061e4  call    __acrt_getptd
0x1400061e9  mov     r8d, [rax+3A8h]
0x1400061f0  mov     edx, r8d
0x1400061f3  and     dl, 2
0x1400061f6  neg     dl
0x1400061f8  sbb     ecx, ecx
0x1400061fa  cmp     ebx, 0FFFFFFFFh
0x1400061fd  jz      short loc_140006235
0x1400061ff  test    ebx, ebx
0x140006201  jz      short loc_14000623C
0x140006203  cmp     ebx, 1
0x140006206  jz      short loc_140006228
0x140006208  cmp     ebx, 2
0x14000620b  jz      short loc_140006222
0x14000620d  call    _errno
0x140006212  mov     dword ptr [rax], 16h
0x140006218  call    _invalid_parameter_noinfo
0x14000621d  or      eax, 0FFFFFFFFh
0x140006220  jmp     short loc_14000623F
0x140006222  and     r8d, 0FFFFFFFDh
0x140006226  jmp     short loc_14000622C
0x140006228  or      r8d, 2
0x14000622c  mov     [rax+3A8h], r8d
0x140006233  jmp     short loc_14000623C
0x140006235  or      cs:dword_14001C8C0, 0FFFFFFFFh
0x14000623c  lea     eax, [rcx+2]
0x14000623f  add     rsp, 20h
0x140006243  pop     rbx
0x140006244  retn

// ===== sub_140006248 @ 0x140006248 =====

0x140006248  mov     eax, cs:dword_14001D2E8
0x14000624e  retn

// ===== _set_new_mode @ 0x140006250 =====

0x140006250  sub     rsp, 28h
0x140006254  cmp     ecx, 1
0x140006257  jbe     short loc_14000626E
0x140006259  call    _errno
0x14000625e  mov     dword ptr [rax], 16h
0x140006264  call    _invalid_parameter_noinfo
0x140006269  or      eax, 0FFFFFFFFh
0x14000626c  jmp     short loc_140006276
0x14000626e  xchg    ecx, cs:dword_14001D2E8
0x140006274  mov     eax, ecx
0x140006276  add     rsp, 28h
0x14000627a  retn

// ===== sub_14000627C @ 0x14000627c =====

0x14000627c  lea     rax, unk_14001D2EC
0x140006283  retn

// ===== j__free_base @ 0x140006284 =====

0x140006284  jmp     _free_base

// ===== ??$?RV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@V_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@$$QEAV_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@Z @ 0x14000628c =====

0x14000628c  mov     [rsp+arg_0], rbx
0x140006291  mov     [rsp+arg_18], r9
0x140006296  push    rdi
0x140006297  sub     rsp, 20h
0x14000629b  mov     rbx, r9
0x14000629e  mov     rdi, r8
0x1400062a1  mov     ecx, [rdx]
0x1400062a3  call    sub_14000AB5C
0x1400062a8  nop
0x1400062a9  mov     rcx, rdi
0x1400062ac  call    ??R_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@QEBAHXZ
0x1400062b1  mov     edi, eax
0x1400062b3  mov     ecx, [rbx]
0x1400062b5  call    sub_14000ABB0
0x1400062ba  mov     eax, edi
0x1400062bc  mov     rbx, [rsp+28h+arg_0]
0x1400062c1  add     rsp, 20h
0x1400062c5  pop     rdi
0x1400062c6  retn
0x140010a3b  push    rbp
0x140010a3d  sub     rsp, 20h
0x140010a41  mov     rbp, rdx
0x140010a44  mov     rax, [rbp+48h]
0x140010a48  mov     ecx, [rax]
0x140010a4a  add     rsp, 20h
0x140010a4e  pop     rbp
0x140010a4f  jmp     sub_14000ABB0

// ===== ??$?RV_lambda_e24bbb7b643b32fcea6fa61b31d4c984_@@AEAV_lambda_275893d493268fdec8709772e3fcec0e_@@V_lambda_9d71df4d7cf3f480f8d633942495c3b0_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_e24bbb7b643b32fcea6fa61b31d4c984_@@AEAV_lambda_275893d493268fdec8709772e3fcec0e_@@$$QEAV_lambda_9d71df4d7cf3f480f8d633942495c3b0_@@@Z @ 0x1400062c8 =====

0x1400062c8  mov     [rsp+arg_0], rbx
0x1400062cd  mov     [rsp+arg_8], rsi
0x1400062d2  mov     [rsp+arg_18], r9
0x1400062d7  push    rdi
0x1400062d8  push    r12
0x1400062da  push    r13
0x1400062dc  push    r14
0x1400062de  push    r15
0x1400062e0  sub     rsp, 40h
0x1400062e4  mov     rdi, r9
0x1400062e7  mov     r15, r8
0x1400062ea  mov     ecx, [rdx]
0x1400062ec  call    sub_14000AB5C
0x1400062f1  nop
0x1400062f2  mov     rax, [r15]
0x1400062f5  mov     rdx, [rax]
0x1400062f8  test    rdx, rdx
0x1400062fb  jnz     short loc_140006306
0x1400062fd  or      rbx, 0FFFFFFFFFFFFFFFFh
0x140006301  jmp     loc_140006446
0x140006306  mov     rsi, cs:__security_cookie
0x14000630d  mov     r8d, esi
0x140006310  and     r8d, 3Fh
0x140006314  mov     rdi, rsi
0x140006317  xor     rdi, [rdx]
0x14000631a  mov     ecx, r8d
0x14000631d  ror     rdi, cl
0x140006320  mov     [rsp+68h+var_38], rdi
0x140006325  mov     rbx, rsi
0x140006328  xor     rbx, [rdx+8]
0x14000632c  ror     rbx, cl
0x14000632f  mov     [rsp+68h+var_48], rbx
0x140006334  lea     rax, [rdi-1]
0x140006338  cmp     rax, 0FFFFFFFFFFFFFFFDh
0x14000633c  ja      loc_14000643C
0x140006342  mov     r12, rdi
0x140006345  mov     [rsp+68h+var_40], rdi
0x14000634a  mov     r14, rbx
0x14000634d  mov     [rsp+68h+var_30], rbx
0x140006352  mov     r13d, 40h ; '@'
0x140006358  mov     ecx, r13d
0x14000635b  sub     ecx, r8d
0x14000635e  xor     eax, eax
0x140006360  ror     rax, cl
0x140006363  xor     rax, rsi
0x140006366  sub     rbx, 8
0x14000636a  mov     [rsp+68h+var_48], rbx
0x14000636f  cmp     rbx, rdi
0x140006372  jb      short loc_140006380
0x140006374  cmp     [rbx], rax
0x140006377  jnz     short loc_14000637B
0x140006379  jmp     short loc_140006366
0x14000637b  cmp     rbx, rdi
0x14000637e  jnb     short loc_1400063CA
0x140006380  or      rbx, 0FFFFFFFFFFFFFFFFh
0x140006384  cmp     rdi, rbx
0x140006387  jz      short loc_140006398
0x140006389  mov     rcx, rdi; Block
0x14000638c  call    _free_base
0x140006391  mov     rsi, cs:__security_cookie
0x140006398  mov     eax, esi
0x14000639a  and     eax, 3Fh
0x14000639d  sub     r13d, eax
0x1400063a0  mov     ecx, r13d
0x1400063a3  xor     edx, edx
0x1400063a5  ror     rdx, cl
0x1400063a8  xor     rdx, rsi
0x1400063ab  mov     rax, [r15]
0x1400063ae  mov     rcx, [rax]
0x1400063b1  mov     [rcx], rdx
0x1400063b4  mov     rax, [r15]
0x1400063b7  mov     rcx, [rax]
0x1400063ba  mov     [rcx+8], rdx
0x1400063be  mov     rax, [r15]
0x1400063c1  mov     rcx, [rax]
0x1400063c4  mov     [rcx+10h], rdx
0x1400063c8  jmp     short loc_14000643C
0x1400063ca  mov     ecx, esi
0x1400063cc  and     ecx, 3Fh
0x1400063cf  xor     rsi, [rbx]
0x1400063d2  ror     rsi, cl
0x1400063d5  mov     [rbx], rax
0x1400063d8  mov     rcx, rsi
0x1400063db  call    cs:__guard_check_icall_fptr
0x1400063e1  call    rsi
0x1400063e3  mov     rax, [r15]
0x1400063e6  mov     rdx, [rax]
0x1400063e9  mov     rsi, cs:__security_cookie
0x1400063f0  mov     r8d, esi
0x1400063f3  and     r8d, 3Fh
0x1400063f7  mov     r9, rsi
0x1400063fa  xor     r9, [rdx]
0x1400063fd  mov     ecx, r8d
0x140006400  ror     r9, cl
0x140006403  mov     rax, [rdx+8]
0x140006407  xor     rax, rsi
0x14000640a  ror     rax, cl
0x14000640d  cmp     r9, r12
0x140006410  jnz     short loc_140006417
0x140006412  cmp     rax, r14
0x140006415  jz      short loc_140006437
0x140006417  mov     r12, r9
0x14000641a  mov     [rsp+68h+var_40], r9
0x14000641f  mov     rdi, r9
0x140006422  mov     [rsp+68h+var_38], r9
0x140006427  mov     r14, rax
0x14000642a  mov     [rsp+68h+var_30], rax
0x14000642f  mov     rbx, rax
0x140006432  mov     [rsp+68h+var_48], rax
0x140006437  jmp     loc_140006358
0x14000643c  mov     rdi, [rsp+68h+arg_18]
0x140006444  xor     ebx, ebx
0x140006446  mov     ecx, [rdi]
0x140006448  call    sub_14000ABB0
0x14000644d  mov     eax, ebx
0x14000644f  mov     rbx, [rsp+68h+arg_0]
0x140006454  mov     rsi, [rsp+68h+arg_8]
0x140006459  add     rsp, 40h
0x14000645d  pop     r15
0x14000645f  pop     r14
0x140006461  pop     r13
0x140006463  pop     r12
0x140006465  pop     rdi
0x140006466  retn
0x140010a55  push    rbp
0x140010a57  sub     rsp, 20h
0x140010a5b  mov     rbp, rdx
0x140010a5e  mov     rax, [rbp+88h]
0x140010a65  mov     ecx, [rax]
0x140010a67  add     rsp, 20h
0x140010a6b  pop     rbp
0x140010a6c  jmp     sub_14000ABB0

// ===== ??R_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@QEBAHXZ @ 0x140006468 =====

0x140006468  mov     rax, rsp
0x14000646b  mov     [rax+8], rbx
0x14000646f  mov     [rax+10h], rbp
0x140006473  mov     [rax+18h], rsi
0x140006477  mov     [rax+20h], rdi
0x14000647b  push    r12
0x14000647d  push    r14
0x14000647f  push    r15
0x140006481  sub     rsp, 20h
0x140006485  mov     rax, [rcx]
0x140006488  xor     esi, esi
0x14000648a  mov     r15, rcx
0x14000648d  mov     rbx, [rax]
0x140006490  test    rbx, rbx
0x140006493  jnz     short loc_14000649D
0x140006495  or      eax, 0FFFFFFFFh
0x140006498  jmp     loc_140006623
0x14000649d  mov     r8, cs:__security_cookie
0x1400064a4  mov     r12d, 40h ; '@'
0x1400064aa  mov     rbp, [rbx]
0x1400064ad  mov     ecx, r8d
0x1400064b0  mov     r9, [rbx+8]
0x1400064b4  and     ecx, 3Fh
0x1400064b7  mov     rbx, [rbx+10h]
0x1400064bb  xor     rbp, r8
0x1400064be  xor     r9, r8
0x1400064c1  ror     rbp, cl
0x1400064c4  xor     rbx, r8
0x1400064c7  ror     r9, cl
0x1400064ca  ror     rbx, cl
0x1400064cd  cmp     r9, rbx
0x1400064d0  jnz     loc_14000659D
0x1400064d6  sub     rbx, rbp
0x1400064d9  mov     eax, 200h
0x1400064de  sar     rbx, 3
0x1400064e2  cmp     rbx, rax
0x1400064e5  mov     rdi, rbx
0x1400064e8  cmova   rdi, rax
0x1400064ec  lea     eax, [r12-20h]
0x1400064f1  add     rdi, rbx
0x1400064f4  cmovz   rdi, rax
0x1400064f8  cmp     rdi, rbx
0x1400064fb  jb      short loc_14000651C
0x1400064fd  lea     r8d, [r12-38h]; Size
0x140006502  mov     rdx, rdi; Count
0x140006505  mov     rcx, rbp; Block
0x140006508  call    j__recalloc_base
0x14000650d  xor     ecx, ecx; Block
0x14000650f  mov     r14, rax
0x140006512  call    _free_base
0x140006517  test    r14, r14
0x14000651a  jnz     short loc_140006544
0x14000651c  lea     rdi, [rbx+4]
0x140006520  mov     r8d, 8; Size
0x140006526  mov     rdx, rdi; Count
0x140006529  mov     rcx, rbp; Block
0x14000652c  call    j__recalloc_base
0x140006531  xor     ecx, ecx; Block
0x140006533  mov     r14, rax
0x140006536  call    _free_base
0x14000653b  test    r14, r14
0x14000653e  jz      loc_140006495
0x140006544  mov     r8, cs:__security_cookie
0x14000654b  lea     r9, [r14+rbx*8]
0x14000654f  mov     eax, r8d
0x140006552  lea     rbx, [r14+rdi*8]
0x140006556  and     eax, 3Fh
0x140006559  mov     ecx, r12d
0x14000655c  sub     ecx, eax
0x14000655e  mov     rdx, rsi
0x140006561  ror     rdx, cl
0x140006564  mov     rax, rbx
0x140006567  sub     rax, r9
0x14000656a  xor     rdx, r8
0x14000656d  add     rax, 7
0x140006571  mov     rbp, r14
0x140006574  shr     rax, 3
0x140006578  mov     rcx, r9
0x14000657b  cmp     r9, rbx
0x14000657e  cmova   rax, rsi
0x140006582  test    rax, rax
0x140006585  jz      short loc_14000659D
0x140006587  inc     rsi
0x14000658a  mov     [rcx], rdx
0x14000658d  lea     rcx, [rcx+8]
0x140006591  cmp     rsi, rax
0x140006594  jnz     short loc_140006587
0x140006596  mov     r8, cs:__security_cookie
0x14000659d  mov     eax, r8d
0x1400065a0  mov     ecx, r12d
0x1400065a3  and     eax, 3Fh
0x1400065a6  sub     ecx, eax
0x1400065a8  mov     rax, [r15+8]
0x1400065ac  mov     rdx, [rax]
0x1400065af  mov     eax, r12d
0x1400065b2  ror     rdx, cl
0x1400065b5  xor     rdx, r8
0x1400065b8  lea     r8, [r9+8]
0x1400065bc  mov     [r9], rdx
0x1400065bf  mov     rdx, cs:__security_cookie
0x1400065c6  mov     ecx, edx
0x1400065c8  and     ecx, 3Fh
0x1400065cb  sub     eax, ecx
0x1400065cd  mov     cl, al
0x1400065cf  mov     rax, [r15]
0x1400065d2  ror     rbp, cl
0x1400065d5  xor     rbp, rdx
0x1400065d8  mov     rcx, [rax]
0x1400065db  mov     [rcx], rbp
0x1400065de  mov     ecx, r12d
0x1400065e1  mov     rdx, cs:__security_cookie
0x1400065e8  mov     eax, edx
0x1400065ea  and     eax, 3Fh
0x1400065ed  sub     ecx, eax
0x1400065ef  mov     rax, [r15]
0x1400065f2  ror     r8, cl
0x1400065f5  xor     r8, rdx
0x1400065f8  mov     rdx, [rax]
0x1400065fb  mov     [rdx+8], r8
0x1400065ff  mov     rdx, cs:__security_cookie
0x140006606  mov     eax, edx
0x140006608  and     eax, 3Fh
0x14000660b  sub     r12d, eax
0x14000660e  mov     rax, [r15]
0x140006611  mov     cl, r12b
0x140006614  ror     rbx, cl
0x140006617  xor     rbx, rdx
0x14000661a  mov     rcx, [rax]
0x14000661d  xor     eax, eax
0x14000661f  mov     [rcx+10h], rbx
0x140006623  mov     rbx, [rsp+38h+arg_0]
0x140006628  mov     rbp, [rsp+38h+arg_8]
0x14000662d  mov     rsi, [rsp+38h+arg_10]
0x140006632  mov     rdi, [rsp+38h+arg_18]
0x140006637  add     rsp, 20h
0x14000663b  pop     r15
0x14000663d  pop     r14
0x14000663f  pop     r12
0x140006641  retn

// ===== sub_140006644 @ 0x140006644 =====

0x140006644  mov     rdx, rcx; Function
0x140006647  lea     rcx, stru_14001D2F0; Table
0x14000664e  jmp     _register_onexit_function

// ===== _execute_onexit_table @ 0x140006654 =====

0x140006654  mov     r11, rsp
0x140006657  mov     [r11+8], rcx
0x14000665b  sub     rsp, 38h
0x14000665f  lea     rax, [r11+8]
0x140006663  mov     [r11-18h], rax
0x140006667  lea     r9, [r11+18h]
0x14000666b  mov     eax, 2
0x140006670  lea     r8, [r11-18h]
0x140006674  lea     rdx, [r11+20h]
0x140006678  mov     [rsp+38h+arg_10], eax
0x14000667c  lea     rcx, [r11+10h]
0x140006680  mov     [rsp+38h+arg_18], eax
0x140006684  call    ??$?RV_lambda_e24bbb7b643b32fcea6fa61b31d4c984_@@AEAV_lambda_275893d493268fdec8709772e3fcec0e_@@V_lambda_9d71df4d7cf3f480f8d633942495c3b0_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_e24bbb7b643b32fcea6fa61b31d4c984_@@AEAV_lambda_275893d493268fdec8709772e3fcec0e_@@$$QEAV_lambda_9d71df4d7cf3f480f8d633942495c3b0_@@@Z
0x140006689  add     rsp, 38h
0x14000668d  retn

// ===== _initialize_onexit_table @ 0x140006690 =====

0x140006690  xor     r9d, r9d
0x140006693  mov     r8, rcx
0x140006696  test    rcx, rcx
0x140006699  jnz     short loc_14000669F
0x14000669b  or      eax, 0FFFFFFFFh
0x14000669e  retn
0x14000669f  mov     rax, [rcx+10h]
0x1400066a3  cmp     [rcx], rax
0x1400066a6  jnz     short loc_1400066CC
0x1400066a8  mov     rdx, cs:__security_cookie
0x1400066af  mov     ecx, 40h ; '@'
0x1400066b4  mov     eax, edx
0x1400066b6  and     eax, 3Fh
0x1400066b9  sub     ecx, eax
0x1400066bb  ror     r9, cl
0x1400066be  xor     r9, rdx
0x1400066c1  mov     [r8], r9
0x1400066c4  mov     [r8+8], r9
0x1400066c8  mov     [r8+10h], r9
0x1400066cc  xor     eax, eax
0x1400066ce  retn

// ===== _register_onexit_function @ 0x1400066d0 =====

0x1400066d0  mov     [rsp-8+arg_8], rdx
0x1400066d5  mov     [rsp-8+arg_0], rcx
0x1400066da  push    rbp
0x1400066db  mov     rbp, rsp
0x1400066de  sub     rsp, 40h
0x1400066e2  lea     rax, [rbp+arg_0]
0x1400066e6  mov     [rbp+var_18], rax
0x1400066ea  lea     r9, [rbp+arg_18]
0x1400066ee  lea     rax, [rbp+arg_8]
0x1400066f2  mov     [rbp+var_10], rax
0x1400066f6  lea     r8, [rbp+var_18]
0x1400066fa  mov     eax, 2
0x1400066ff  lea     rdx, [rbp+var_20]
0x140006703  lea     rcx, [rbp+arg_10]
0x140006707  mov     [rbp+arg_18], eax
0x14000670a  mov     [rbp+var_20], eax
0x14000670d  call    ??$?RV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@V_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@$$QEAV_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@Z
0x140006712  add     rsp, 40h
0x140006716  pop     rbp
0x140006717  retn

// ===== initialize_global_variables @ 0x140006718 =====

0x140006718  lea     rax, off_14001C160
0x14000671f  mov     cs:qword_14001D340, rax
0x140006726  mov     al, 1
0x140006728  retn

// ===== initialize_c @ 0x14000672c =====

0x14000672c  sub     rsp, 28h
0x140006730  lea     rcx, stru_14001D2F0; Table
0x140006737  call    _initialize_onexit_table
0x14000673c  lea     rcx, Table; Table
0x140006743  call    _initialize_onexit_table
0x140006748  mov     al, 1
0x14000674a  add     rsp, 28h
0x14000674e  retn

// ===== uninitialize_environment @ 0x140006750 =====

0x140006750  sub     rsp, 28h
0x140006754  call    __dcrt_uninitialize_environments_nolock
0x140006759  mov     al, 1
0x14000675b  add     rsp, 28h
0x14000675f  retn

// ===== initialize_pointers @ 0x140006760 =====

0x140006760  push    rbx
0x140006762  sub     rsp, 20h
0x140006766  mov     rdx, cs:__security_cookie
0x14000676d  mov     ecx, 40h ; '@'
0x140006772  mov     eax, edx
0x140006774  xor     ebx, ebx
0x140006776  and     eax, 3Fh
0x140006779  sub     ecx, eax
0x14000677b  ror     rbx, cl
0x14000677e  xor     rbx, rdx
0x140006781  mov     rcx, rbx
0x140006784  call    sub_14000726C
0x140006789  mov     rcx, rbx
0x14000678c  call    sub_14000B994
0x140006791  mov     rcx, rbx
0x140006794  call    __acrt_initialize_signal_handlers
0x140006799  mov     rcx, rbx
0x14000679c  call    sub_140005770
0x1400067a1  mov     rcx, rbx
0x1400067a4  call    sub_1400060C4
0x1400067a9  mov     al, 1
0x1400067ab  add     rsp, 20h
0x1400067af  pop     rbx
0x1400067b0  retn

// ===== sub_1400067B4 @ 0x1400067b4 =====

0x1400067b4  xor     ecx, ecx
0x1400067b6  jmp     __vcrt_uninitialize

// ===== uninitialize_allocated_memory @ 0x1400067bc =====

0x1400067bc  push    rbx
0x1400067be  sub     rsp, 20h
0x1400067c2  mov     rcx, cs:off_14001C4F8
0x1400067c9  or      eax, 0FFFFFFFFh
0x1400067cc  lock xadd [rcx], eax
0x1400067d0  cmp     eax, 1
0x1400067d3  jnz     short loc_1400067F4
0x1400067d5  mov     rcx, cs:off_14001C4F8; Block
0x1400067dc  lea     rbx, unk_14001C2D0
0x1400067e3  cmp     rcx, rbx
0x1400067e6  jz      short loc_1400067F4
0x1400067e8  call    _free_base
0x1400067ed  mov     cs:off_14001C4F8, rbx
0x1400067f4  mov     rcx, cs:qword_14001D330; Block
0x1400067fb  call    _free_base
0x140006800  mov     rcx, cs:qword_14001D338; Block
0x140006807  xor     ebx, ebx
0x140006809  mov     cs:qword_14001D330, rbx
0x140006810  call    _free_base
0x140006815  mov     rcx, cs:qword_14001D930; Block
0x14000681c  mov     cs:qword_14001D338, rbx
0x140006823  call    _free_base
0x140006828  mov     rcx, cs:qword_14001D938; Block
0x14000682f  mov     cs:qword_14001D930, rbx
0x140006836  call    _free_base
0x14000683b  mov     al, 1
0x14000683d  mov     cs:qword_14001D938, rbx
0x140006844  add     rsp, 20h
0x140006848  pop     rbx
0x140006849  retn

// ===== __acrt_initialize @ 0x14000684c =====

0x14000684c  lea     rdx, dword_140012190
0x140006853  lea     rcx, off_1400120A0
0x14000685a  jmp     __acrt_execute_initializers

// ===== __acrt_uninitialize @ 0x140006860 =====

0x140006860  lea     rdx, dword_140012190
0x140006867  lea     rcx, off_1400120A0
0x14000686e  jmp     __acrt_execute_uninitializers

// ===== terminate @ 0x140006874 =====

0x140006874  push    rbx
0x140006876  sub     rsp, 20h
0x14000687a  call    __acrt_getptd
0x14000687f  mov     rbx, [rax+18h]
0x140006883  test    rbx, rbx
0x140006886  jz      short loc_140006895
0x140006888  mov     rcx, rbx
0x14000688b  call    cs:__guard_check_icall_fptr
0x140006891  call    rbx
0x140006893  jmp     short $+2
0x140006895  call    abort

// ===== strcpy_s @ 0x14000689c =====

0x14000689c  push    rbx
0x14000689e  sub     rsp, 20h
0x1400068a2  xor     ebx, ebx
0x1400068a4  test    rcx, rcx
0x1400068a7  jz      short loc_1400068B5
0x1400068a9  test    rdx, rdx
0x1400068ac  jz      short loc_1400068B5
0x1400068ae  test    r8, r8
0x1400068b1  jnz     short loc_1400068CE
0x1400068b3  mov     [rcx], bl
0x1400068b5  call    _errno
0x1400068ba  mov     ebx, 16h
0x1400068bf  mov     [rax], ebx
0x1400068c1  call    _invalid_parameter_noinfo
0x1400068c6  mov     eax, ebx
0x1400068c8  add     rsp, 20h
0x1400068cc  pop     rbx
0x1400068cd  retn
0x1400068ce  mov     r9, rcx
0x1400068d1  sub     r8, rcx
0x1400068d4  mov     al, [r8+r9]
0x1400068d8  mov     [r9], al
0x1400068db  inc     r9
0x1400068de  test    al, al
0x1400068e0  jz      short loc_1400068E8
0x1400068e2  sub     rdx, 1
0x1400068e6  jnz     short loc_1400068D4
0x1400068e8  test    rdx, rdx
0x1400068eb  jnz     short loc_1400068C6
0x1400068ed  mov     [rcx], bl
0x1400068ef  call    _errno
0x1400068f4  mov     ebx, 22h ; '"'
0x1400068f9  jmp     short loc_1400068BF

// ===== abort @ 0x1400068fc =====

0x1400068fc  sub     rsp, 28h
0x140006900  call    __acrt_get_sigabrt_handler
0x140006905  test    rax, rax
0x140006908  jz      short loc_140006914
0x14000690a  mov     ecx, 16h; Signal
0x14000690f  call    raise
0x140006914  test    cs:byte_14001C148, 2
0x14000691b  jz      short loc_140006946
0x14000691d  mov     ecx, 17h; ProcessorFeature
0x140006922  call    IsProcessorFeaturePresent
0x140006927  test    eax, eax
0x140006929  jz      short loc_140006932
0x14000692b  mov     ecx, 7
0x140006930  int     29h; Win8: RtlFailFast(ecx)
0x140006932  mov     r8d, 1
0x140006938  mov     edx, 40000015h
0x14000693d  lea     ecx, [r8+2]
0x140006941  call    __acrt_call_reportfault
0x140006946  mov     ecx, 3; Code
0x14000694b  call    _exit

// ===== wcsncmp @ 0x140006954 =====

0x140006954  test    r8, r8
0x140006957  jnz     short loc_140006971
0x140006959  xor     eax, eax
0x14000695b  retn
0x14000695c  movzx   eax, word ptr [rcx]
0x14000695f  test    ax, ax
0x140006962  jz      short loc_140006977
0x140006964  cmp     ax, [rdx]
0x140006967  jnz     short loc_140006977
0x140006969  add     rcx, 2
0x14000696d  add     rdx, 2
0x140006971  sub     r8, 1
0x140006975  jnz     short loc_14000695C
0x140006977  movzx   eax, word ptr [rcx]
0x14000697a  movzx   ecx, word ptr [rdx]
0x14000697d  sub     eax, ecx
0x14000697f  retn

// ===== ??$is_overflow_condition@K@__crt_strtox@@YA_NIK@Z @ 0x140006980 =====

0x140006980  test    cl, 4
0x140006983  jz      short loc_140006988
0x140006985  mov     al, 1
0x140006987  retn
0x140006988  test    cl, 1
0x14000698b  jz      short loc_1400069A6
0x14000698d  and     ecx, 2
0x140006990  jz      short loc_14000699A
0x140006992  cmp     edx, 80000000h
0x140006998  ja      short loc_140006985
0x14000699a  test    ecx, ecx
0x14000699c  jnz     short loc_1400069A6
0x14000699e  cmp     edx, 7FFFFFFFh
0x1400069a4  ja      short loc_140006985
0x1400069a6  xor     al, al
0x1400069a8  retn

// ===== ??$parse_integer@KV?$c_string_character_source@_W@__crt_strtox@@@__crt_strtox@@YAKQEAU__crt_locale_pointers@@V?$c_string_character_source@_W@0@H_N@Z @ 0x1400069ac =====

0x1400069ac  mov     [rsp+arg_0], rbx
0x1400069b1  mov     [rsp+arg_10], rbp
0x1400069b6  mov     [rsp+arg_18], rsi
0x1400069bb  push    rdi
0x1400069bc  push    r12
0x1400069be  push    r13
0x1400069c0  push    r14
0x1400069c2  push    r15
0x1400069c4  sub     rsp, 50h
0x1400069c8  xor     r13d, r13d
0x1400069cb  mov     sil, r9b
0x1400069ce  mov     r15d, r8d
0x1400069d1  mov     rdi, rdx
0x1400069d4  cmp     [rdx], r13
0x1400069d7  jnz     short loc_1400069FF
0x1400069d9  call    _errno
0x1400069de  mov     dword ptr [rax], 16h
0x1400069e4  call    _invalid_parameter_noinfo
0x1400069e9  mov     rcx, [rdi+8]
0x1400069ed  test    rcx, rcx
0x1400069f0  jz      short loc_1400069F8
0x1400069f2  mov     rax, [rdi]
0x1400069f5  mov     [rcx], rax
0x1400069f8  xor     eax, eax
0x1400069fa  jmp     loc_140007062
0x1400069ff  test    r8d, r8d
0x140006a02  jz      short loc_140006A0D
0x140006a04  lea     eax, [r8-2]
0x140006a08  cmp     eax, 22h ; '"'
0x140006a0b  ja      short loc_1400069D9
0x140006a0d  mov     rdx, rcx; struct __crt_locale_pointers *
0x140006a10  lea     rcx, [rsp+78h+var_50]; this
0x140006a15  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x140006a1a  mov     r12, [rdi]
0x140006a1d  mov     r14d, r13d
0x140006a20  mov     [rsp+78h+var_58], r12
0x140006a25  mov     ebp, 8
0x140006a2a  movzx   ebx, word ptr [r12]
0x140006a2f  lea     rax, [r12+2]
0x140006a34  jmp     short loc_140006A40
0x140006a36  mov     rax, [rdi]
0x140006a39  movzx   ebx, word ptr [rax]
0x140006a3c  add     rax, 2
0x140006a40  mov     edx, ebp; Type
0x140006a42  mov     [rdi], rax
0x140006a45  movzx   ecx, bx; C
0x140006a48  call    iswctype
0x140006a4d  test    eax, eax
0x140006a4f  jnz     short loc_140006A36
0x140006a51  test    sil, sil
0x140006a54  mov     ebp, r13d
0x140006a57  setnz   bpl
0x140006a5b  cmp     bx, 2Dh ; '-'
0x140006a5f  jnz     short loc_140006A66
0x140006a61  or      ebp, 2
0x140006a64  jmp     short loc_140006A6C
0x140006a66  cmp     bx, 2Bh ; '+'
0x140006a6a  jnz     short loc_140006A79
0x140006a6c  mov     rax, [rdi]
0x140006a6f  movzx   ebx, word ptr [rax]
0x140006a72  add     rax, 2
0x140006a76  mov     [rdi], rax
0x140006a79  mov     esi, 9E6h
0x140006a7e  mov     [rsp+78h+arg_8], 66Ah
0x140006a89  or      r9d, 0FFFFFFFFh
0x140006a8d  mov     ecx, 660h
0x140006a92  mov     r10d, 30h ; '0'
0x140006a98  mov     r11d, 0FF10h
0x140006a9e  mov     edx, 6F0h
0x140006aa3  mov     eax, 0A66h
0x140006aa8  lea     r8d, [rsi-80h]
0x140006aac  test    r15d, 0FFFFFFEFh
0x140006ab3  jnz     loc_140006D38
0x140006ab9  cmp     bx, r10w
0x140006abd  jb      loc_140006C8D
0x140006ac3  cmp     bx, 3Ah ; ':'
0x140006ac7  jnb     short loc_140006AD4
0x140006ac9  movzx   eax, bx
0x140006acc  sub     eax, r10d
0x140006acf  jmp     loc_140006C88
0x140006ad4  cmp     bx, r11w
0x140006ad8  jnb     loc_140006C73
0x140006ade  cmp     bx, cx
0x140006ae1  jb      loc_140006C8D
0x140006ae7  cmp     bx, word ptr [rsp+78h+arg_8]
0x140006aef  jnb     short loc_140006AFB
0x140006af1  movzx   eax, bx
0x140006af4  sub     eax, ecx
0x140006af6  jmp     loc_140006C88
0x140006afb  cmp     bx, dx
0x140006afe  jb      loc_140006C8D
0x140006b04  mov     ecx, 6FAh
0x140006b09  cmp     bx, cx
0x140006b0c  jnb     short loc_140006B18
0x140006b0e  movzx   eax, bx
0x140006b11  sub     eax, edx
0x140006b13  jmp     loc_140006C88
0x140006b18  cmp     bx, r8w
0x140006b1c  jb      loc_140006C8D
0x140006b22  mov     ecx, 970h
0x140006b27  cmp     bx, cx
0x140006b2a  jnb     short loc_140006B37
0x140006b2c  movzx   eax, bx
0x140006b2f  sub     eax, r8d
0x140006b32  jmp     loc_140006C88
0x140006b37  cmp     bx, si
0x140006b3a  jb      loc_140006C8D
0x140006b40  mov     ecx, 9F0h
0x140006b45  cmp     bx, cx
0x140006b48  jnb     short loc_140006B54
0x140006b4a  movzx   eax, bx
0x140006b4d  sub     eax, esi
0x140006b4f  jmp     loc_140006C88
0x140006b54  cmp     bx, ax
0x140006b57  jb      loc_140006C8D
0x140006b5d  mov     eax, 0A70h
0x140006b62  cmp     bx, ax
0x140006b65  jnb     short loc_140006B74
0x140006b67  movzx   eax, bx
0x140006b6a  sub     eax, 0A66h
0x140006b6f  jmp     loc_140006C88
0x140006b74  mov     ecx, 0AE6h
0x140006b79  cmp     bx, cx
0x140006b7c  jb      loc_140006C8D
0x140006b82  lea     eax, [rcx+0Ah]
0x140006b85  cmp     bx, ax
0x140006b88  jb      loc_140006AF1
0x140006b8e  lea     ecx, [rax+76h]
0x140006b91  cmp     bx, cx
0x140006b94  jb      loc_140006C8D
0x140006b9a  lea     eax, [rcx+0Ah]
0x140006b9d  cmp     bx, ax
0x140006ba0  jb      loc_140006AF1
0x140006ba6  mov     ecx, 0C66h
0x140006bab  cmp     bx, cx
0x140006bae  jb      loc_140006C8D
0x140006bb4  lea     eax, [rcx+0Ah]
0x140006bb7  cmp     bx, ax
0x140006bba  jb      loc_140006AF1
0x140006bc0  lea     ecx, [rax+76h]
0x140006bc3  cmp     bx, cx
0x140006bc6  jb      loc_140006C8D
0x140006bcc  lea     eax, [rcx+0Ah]
0x140006bcf  cmp     bx, ax
0x140006bd2  jb      loc_140006AF1
0x140006bd8  lea     ecx, [rax+76h]
0x140006bdb  cmp     bx, cx
0x140006bde  jb      loc_140006C8D
0x140006be4  lea     eax, [rcx+0Ah]
0x140006be7  cmp     bx, ax
0x140006bea  jb      loc_140006AF1
0x140006bf0  mov     ecx, 0E50h
0x140006bf5  cmp     bx, cx
0x140006bf8  jb      loc_140006C8D
0x140006bfe  lea     eax, [rcx+0Ah]
0x140006c01  cmp     bx, ax
0x140006c04  jb      loc_140006AF1
0x140006c0a  lea     ecx, [rax+76h]
0x140006c0d  cmp     bx, cx
0x140006c10  jb      short loc_140006C8D
0x140006c12  lea     eax, [rcx+0Ah]
0x140006c15  cmp     bx, ax
0x140006c18  jb      loc_140006AF1
0x140006c1e  lea     ecx, [rax+46h]
0x140006c21  cmp     bx, cx
0x140006c24  jb      short loc_140006C8D
0x140006c26  lea     eax, [rcx+0Ah]
0x140006c29  cmp     bx, ax
0x140006c2c  jb      loc_140006AF1
0x140006c32  mov     ecx, 1040h
0x140006c37  cmp     bx, cx
0x140006c3a  jb      short loc_140006C8D
0x140006c3c  lea     eax, [rcx+0Ah]
0x140006c3f  cmp     bx, ax
0x140006c42  jb      loc_140006AF1
0x140006c48  mov     ecx, 17E0h
0x140006c4d  cmp     bx, cx
0x140006c50  jb      short loc_140006C8D
0x140006c52  lea     eax, [rcx+0Ah]
0x140006c55  cmp     bx, ax
0x140006c58  jb      loc_140006AF1
0x140006c5e  lea     ecx, [rax+26h]
0x140006c61  cmp     bx, cx
0x140006c64  jb      short loc_140006C8D
0x140006c66  lea     eax, [rcx+0Ah]
0x140006c69  cmp     bx, ax
0x140006c6c  jnb     short loc_140006C8D
0x140006c6e  jmp     loc_140006AF1
0x140006c73  mov     eax, 0FF1Ah
0x140006c78  cmp     bx, ax
0x140006c7b  jnb     short loc_140006C85
0x140006c7d  movzx   eax, bx
0x140006c80  sub     eax, r11d
0x140006c83  jmp     short loc_140006C88
0x140006c85  or      eax, 0FFFFFFFFh
0x140006c88  cmp     eax, 0FFFFFFFFh
0x140006c8b  jnz     short loc_140006CB6
0x140006c8d  lea     eax, [rbx-41h]
0x140006c90  cmp     ax, 19h
0x140006c94  jbe     short loc_140006CA4
0x140006c96  lea     eax, [rbx-61h]
0x140006c99  cmp     ax, 19h
0x140006c9d  jbe     short loc_140006CA4
0x140006c9f  mov     eax, r9d
0x140006ca2  jmp     short loc_140006CB6
0x140006ca4  lea     eax, [rbx-61h]
0x140006ca7  cmp     ax, 19h
0x140006cab  movzx   eax, bx
0x140006cae  ja      short loc_140006CB3
0x140006cb0  sub     eax, 20h ; ' '
0x140006cb3  add     eax, 0FFFFFFC9h
0x140006cb6  mov     esi, 8
0x140006cbb  test    eax, eax
0x140006cbd  jz      short loc_140006CCA
0x140006cbf  test    r15d, r15d
0x140006cc2  jnz     short loc_140006D3D
0x140006cc4  lea     r15d, [rsi+2]
0x140006cc8  jmp     short loc_140006D3D
0x140006cca  mov     rax, [rdi]
0x140006ccd  mov     r8d, 0FFDFh
0x140006cd3  movzx   edx, word ptr [rax]
0x140006cd6  lea     rcx, [rax+2]
0x140006cda  mov     [rdi], rcx
0x140006cdd  lea     eax, [rdx-58h]
0x140006ce0  test    r8w, ax
0x140006ce4  jz      short loc_140006D20
0x140006ce6  test    r15d, r15d
0x140006ce9  cmovz   r15d, esi
0x140006ced  add     rcx, 0FFFFFFFFFFFFFFFEh
0x140006cf1  mov     [rdi], rcx
0x140006cf4  test    dx, dx
0x140006cf7  jz      short loc_140006D3D
0x140006cf9  cmp     [rcx], dx
0x140006cfc  jz      short loc_140006D3D
0x140006cfe  call    _errno
0x140006d03  mov     dword ptr [rax], 16h
0x140006d09  call    _invalid_parameter_noinfo
0x140006d0e  or      r9d, 0FFFFFFFFh
0x140006d12  mov     r10d, 30h ; '0'
0x140006d18  mov     r11d, 0FF10h
0x140006d1e  jmp     short loc_140006D3D
0x140006d20  movzx   ebx, word ptr [rcx]
0x140006d23  mov     eax, 10h
0x140006d28  test    r15d, r15d
0x140006d2b  cmovz   r15d, eax
0x140006d2f  lea     rax, [rcx+2]
0x140006d33  mov     [rdi], rax
0x140006d36  jmp     short loc_140006D3D
0x140006d38  mov     esi, 8
0x140006d3d  xor     edx, edx
0x140006d3f  mov     eax, r9d
0x140006d42  div     r15d
0x140006d45  mov     r13d, 660h
0x140006d4b  mov     r12d, 6F0h
0x140006d51  mov     r8d, eax
0x140006d54  cmp     bx, r10w
0x140006d58  jb      loc_140006F0C
0x140006d5e  cmp     bx, 3Ah ; ':'
0x140006d62  jnb     short loc_140006D6F
0x140006d64  movzx   ecx, bx
0x140006d67  sub     ecx, r10d
0x140006d6a  jmp     loc_140006F07
0x140006d6f  cmp     bx, r11w
0x140006d73  jnb     loc_140006EF2
0x140006d79  cmp     bx, r13w
0x140006d7d  jb      loc_140006F0C
0x140006d83  mov     eax, 66Ah
0x140006d88  cmp     bx, ax
0x140006d8b  jnb     short loc_140006D98
0x140006d8d  movzx   ecx, bx
0x140006d90  sub     ecx, r13d
0x140006d93  jmp     loc_140006F07
0x140006d98  cmp     bx, r12w
0x140006d9c  jb      loc_140006F0C
0x140006da2  mov     eax, 6FAh
0x140006da7  cmp     bx, ax
0x140006daa  jnb     short loc_140006DB7
0x140006dac  movzx   ecx, bx
0x140006daf  sub     ecx, r12d
0x140006db2  jmp     loc_140006F07
0x140006db7  mov     eax, 966h
0x140006dbc  cmp     bx, ax
0x140006dbf  jb      loc_140006F0C
0x140006dc5  lea     ecx, [rax+0Ah]
0x140006dc8  cmp     bx, cx
0x140006dcb  jnb     short loc_140006DD7
0x140006dcd  movzx   ecx, bx
0x140006dd0  sub     ecx, eax
0x140006dd2  jmp     loc_140006F07
0x140006dd7  mov     eax, 9E6h
0x140006ddc  cmp     bx, ax
0x140006ddf  jb      loc_140006F0C
0x140006de5  lea     ecx, [rax+0Ah]
0x140006de8  cmp     bx, cx
0x140006deb  jb      short loc_140006DCD
0x140006ded  lea     eax, [rcx+76h]
0x140006df0  cmp     bx, ax
0x140006df3  jb      loc_140006F0C
0x140006df9  lea     ecx, [rax+0Ah]
0x140006dfc  cmp     bx, cx
0x140006dff  jb      short loc_140006DCD
0x140006e01  lea     eax, [rcx+76h]
0x140006e04  cmp     bx, ax
0x140006e07  jb      loc_140006F0C
0x140006e0d  lea     ecx, [rax+0Ah]
0x140006e10  cmp     bx, cx
0x140006e13  jb      short loc_140006DCD
0x140006e15  lea     eax, [rcx+76h]
0x140006e18  cmp     bx, ax
0x140006e1b  jb      loc_140006F0C
0x140006e21  lea     ecx, [rax+0Ah]
0x140006e24  cmp     bx, cx
0x140006e27  jb      short loc_140006DCD
0x140006e29  mov     eax, 0C66h
0x140006e2e  cmp     bx, ax
0x140006e31  jb      loc_140006F0C
0x140006e37  lea     ecx, [rax+0Ah]
0x140006e3a  cmp     bx, cx
0x140006e3d  jb      short loc_140006DCD
0x140006e3f  lea     eax, [rcx+76h]
0x140006e42  cmp     bx, ax
0x140006e45  jb      loc_140006F0C
0x140006e4b  lea     ecx, [rax+0Ah]
0x140006e4e  cmp     bx, cx
0x140006e51  jb      loc_140006DCD
0x140006e57  lea     eax, [rcx+76h]
0x140006e5a  cmp     bx, ax
0x140006e5d  jb      loc_140006F0C
0x140006e63  lea     ecx, [rax+0Ah]
0x140006e66  cmp     bx, cx
0x140006e69  jb      loc_140006DCD
0x140006e6f  mov     eax, 0E50h
0x140006e74  cmp     bx, ax
0x140006e77  jb      loc_140006F0C
0x140006e7d  lea     ecx, [rax+0Ah]
0x140006e80  cmp     bx, cx
0x140006e83  jb      loc_140006DCD
0x140006e89  lea     eax, [rcx+76h]
0x140006e8c  cmp     bx, ax
0x140006e8f  jb      short loc_140006F0C
0x140006e91  lea     ecx, [rax+0Ah]
0x140006e94  cmp     bx, cx
0x140006e97  jb      loc_140006DCD
0x140006e9d  lea     eax, [rcx+46h]
0x140006ea0  cmp     bx, ax
0x140006ea3  jb      short loc_140006F0C
0x140006ea5  lea     ecx, [rax+0Ah]
0x140006ea8  cmp     bx, cx
0x140006eab  jb      loc_140006DCD
0x140006eb1  mov     eax, 1040h
0x140006eb6  cmp     bx, ax
0x140006eb9  jb      short loc_140006F0C
0x140006ebb  lea     ecx, [rax+0Ah]
0x140006ebe  cmp     bx, cx
0x140006ec1  jb      loc_140006DCD
0x140006ec7  mov     eax, 17E0h
0x140006ecc  cmp     bx, ax
0x140006ecf  jb      short loc_140006F0C
0x140006ed1  lea     ecx, [rax+0Ah]
0x140006ed4  cmp     bx, cx
0x140006ed7  jb      loc_140006DCD
0x140006edd  lea     eax, [rcx+26h]
0x140006ee0  cmp     bx, ax
0x140006ee3  jb      short loc_140006F0C
0x140006ee5  lea     ecx, [rax+0Ah]
0x140006ee8  cmp     bx, cx
0x140006eeb  jnb     short loc_140006F0C
0x140006eed  jmp     loc_140006DCD
0x140006ef2  mov     eax, 0FF1Ah
0x140006ef7  cmp     bx, ax
0x140006efa  jnb     short loc_140006F04
0x140006efc  movzx   ecx, bx
0x140006eff  sub     ecx, r11d
0x140006f02  jmp     short loc_140006F07
0x140006f04  or      ecx, 0FFFFFFFFh
0x140006f07  cmp     ecx, 0FFFFFFFFh
0x140006f0a  jnz     short loc_140006F35
0x140006f0c  lea     eax, [rbx-41h]
0x140006f0f  cmp     ax, 19h
0x140006f13  jbe     short loc_140006F23
0x140006f15  lea     eax, [rbx-61h]
0x140006f18  cmp     ax, 19h
0x140006f1c  jbe     short loc_140006F23
0x140006f1e  mov     ecx, r9d
0x140006f21  jmp     short loc_140006F35
0x140006f23  lea     eax, [rbx-61h]
0x140006f26  movzx   ecx, bx
0x140006f29  cmp     ax, 19h
0x140006f2d  ja      short loc_140006F32
0x140006f2f  sub     ecx, 20h ; ' '
0x140006f32  add     ecx, 0FFFFFFC9h
0x140006f35  cmp     ecx, r9d
0x140006f38  jz      short loc_140006F6A
0x140006f3a  cmp     ecx, r15d
0x140006f3d  jnb     short loc_140006F6A
0x140006f3f  or      ebp, esi
0x140006f41  cmp     r14d, r8d
0x140006f44  jb      short loc_140006F51
0x140006f46  jnz     short loc_140006F4C
0x140006f48  cmp     ecx, edx
0x140006f4a  jbe     short loc_140006F51
0x140006f4c  or      ebp, 4
0x140006f4f  jmp     short loc_140006F58
0x140006f51  imul    r14d, r15d
0x140006f55  add     r14d, ecx
0x140006f58  mov     rax, [rdi]
0x140006f5b  movzx   ebx, word ptr [rax]
0x140006f5e  add     rax, 2
0x140006f62  mov     [rdi], rax
0x140006f65  jmp     loc_140006D54
0x140006f6a  add     qword ptr [rdi], 0FFFFFFFFFFFFFFFEh
0x140006f6e  xor     r13d, r13d
0x140006f71  mov     rax, [rdi]
0x140006f74  mov     r12, [rsp+78h+var_58]
0x140006f79  test    bx, bx
0x140006f7c  jz      short loc_140006F93
0x140006f7e  cmp     [rax], bx
0x140006f81  jz      short loc_140006F93
0x140006f83  call    _errno
0x140006f88  mov     dword ptr [rax], 16h
0x140006f8e  call    _invalid_parameter_noinfo
0x140006f93  test    sil, bpl
0x140006f96  jnz     short loc_140006FB7
0x140006f98  mov     [rdi], r12
0x140006f9b  cmp     [rsp+78h+var_38], r13b
0x140006fa0  jz      loc_1400069E9
0x140006fa6  mov     rax, [rsp+78h+var_50]
0x140006fab  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x140006fb2  jmp     loc_1400069E9
0x140006fb7  mov     edx, r14d
0x140006fba  mov     ecx, ebp
0x140006fbc  call    ??$is_overflow_condition@K@__crt_strtox@@YA_NIK@Z
0x140006fc1  test    al, al
0x140006fc3  jz      short loc_140007034
0x140006fc5  call    _errno
0x140006fca  mov     dword ptr [rax], 22h ; '"'
0x140006fd0  test    bpl, 1
0x140006fd4  jnz     short loc_140006FDC
0x140006fd6  or      r14d, 0FFFFFFFFh
0x140006fda  jmp     short loc_14000703D
0x140006fdc  test    bpl, 2
0x140006fe0  jz      short loc_14000700B
0x140006fe2  cmp     [rsp+78h+var_38], r13b
0x140006fe7  jz      short loc_140006FF5
0x140006fe9  mov     rax, [rsp+78h+var_50]
0x140006fee  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x140006ff5  mov     rcx, [rdi+8]
0x140006ff9  test    rcx, rcx
0x140006ffc  jz      short loc_140007004
0x140006ffe  mov     rax, [rdi]
0x140007001  mov     [rcx], rax
0x140007004  mov     eax, 80000000h
0x140007009  jmp     short loc_140007062
0x14000700b  cmp     [rsp+78h+var_38], r13b
0x140007010  jz      short loc_14000701E
0x140007012  mov     rax, [rsp+78h+var_50]
0x140007017  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x14000701e  mov     rcx, [rdi+8]
0x140007022  test    rcx, rcx
0x140007025  jz      short loc_14000702D
0x140007027  mov     rax, [rdi]
0x14000702a  mov     [rcx], rax
0x14000702d  mov     eax, 7FFFFFFFh
0x140007032  jmp     short loc_140007062
0x140007034  test    bpl, 2
0x140007038  jz      short loc_14000703D
0x14000703a  neg     r14d
0x14000703d  cmp     [rsp+78h+var_38], r13b
0x140007042  jz      short loc_140007050
0x140007044  mov     rcx, [rsp+78h+var_50]
0x140007049  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x140007050  mov     rdx, [rdi+8]
0x140007054  test    rdx, rdx
0x140007057  jz      short loc_14000705F
0x140007059  mov     rcx, [rdi]
0x14000705c  mov     [rdx], rcx
0x14000705f  mov     eax, r14d
0x140007062  lea     r11, [rsp+78h+var_28]
0x140007067  mov     rbx, [r11+30h]
0x14000706b  mov     rbp, [r11+40h]
0x14000706f  mov     rsi, [r11+48h]
0x140007073  mov     rsp, r11
0x140007076  pop     r15
0x140007078  pop     r14
0x14000707a  pop     r13
0x14000707c  pop     r12
0x14000707e  pop     rdi
0x14000707f  retn

// ===== strncmp @ 0x140007090 =====

0x140007090  sub     rdx, rcx
0x140007093  test    r8, r8
0x140007096  jz      short return_equal
0x140007098  test    ecx, 7
0x14000709e  jz      short _qword_loop_enter
0x1400070a0  movzx   eax, byte ptr [rcx]
0x1400070a3  cmp     al, [rcx+rdx]
0x1400070a6  jnz     short return_not_equal
0x1400070a8  inc     rcx
0x1400070ab  dec     r8
0x1400070ae  jz      short return_equal
0x1400070b0  test    al, al
0x1400070b2  jz      short return_equal
0x1400070b4  test    rcx, 7
0x1400070bb  jnz     short comp_head_loop_begin
0x1400070bd  mov     r11, 8080808080808080h
0x1400070c7  mov     r10, 0FEFEFEFEFEFEFEFFh
0x1400070d1  lea     eax, [rcx+rdx]
0x1400070d4  and     eax, 0FFFh
0x1400070d9  cmp     eax, 0FF8h
0x1400070de  ja      short comp_head_loop_begin
0x1400070e0  mov     rax, [rcx]
0x1400070e3  cmp     rax, [rcx+rdx]
0x1400070e7  jnz     short comp_head_loop_begin
0x1400070e9  add     rcx, 8
0x1400070ed  sub     r8, 8
0x1400070f1  jbe     short return_equal
0x1400070f3  lea     r9, [rax+r10]
0x1400070f7  not     rax
0x1400070fa  and     rax, r9
0x1400070fd  test    r11, rax
0x140007100  jz      short _qword_loop_begin
0x140007102  xor     eax, eax
0x140007104  retn
0x140007105  sbb     rax, rax
0x140007108  or      rax, 1
0x14000710c  retn

// ===== __acrt_call_reportfault @ 0x140007110 =====

0x140007110  mov     [rsp-8+arg_8], rbx
0x140007115  mov     [rsp-8+arg_10], rsi
0x14000711a  push    rbp
0x14000711b  push    rdi
0x14000711c  push    r14
0x14000711e  lea     rbp, [rsp-4F0h]
0x140007126  sub     rsp, 5F0h
0x14000712d  mov     rax, cs:__security_cookie
0x140007134  xor     rax, rsp
0x140007137  mov     [rbp+500h+var_20], rax
0x14000713e  mov     edi, r8d
0x140007141  mov     esi, edx
0x140007143  mov     ebx, ecx
0x140007145  cmp     ecx, 0FFFFFFFFh
0x140007148  jz      short loc_14000714F
0x14000714a  call    sub_140002710
0x14000714f  xor     edx, edx
0x140007151  lea     rcx, [rsp+600h+var_590]
0x140007156  mov     r8d, 98h
0x14000715c  call    sub_140002F60
0x140007161  xor     edx, edx
0x140007163  lea     rcx, [rbp+500h+ContextRecord]
0x140007167  mov     r8d, 4D0h
0x14000716d  call    sub_140002F60
0x140007172  lea     rax, [rsp+600h+var_590]
0x140007177  mov     [rsp+600h+ExceptionInfo.ExceptionRecord], rax
0x14000717c  lea     rcx, [rbp+500h+ContextRecord]; ContextRecord
0x140007180  lea     rax, [rbp+500h+ContextRecord]
0x140007184  mov     [rsp+600h+ExceptionInfo.ContextRecord], rax
0x140007189  call    cs:RtlCaptureContext; KERNEL32
0x14000718f  mov     r14, [rbp+500h+ContextRecord.Rip]
0x140007196  lea     rdx, [rsp+600h+ImageBase]; ImageBase
0x14000719b  mov     rcx, r14; ControlPc
0x14000719e  xor     r8d, r8d; HistoryTable
0x1400071a1  call    cs:RtlLookupFunctionEntry; KERNEL32
0x1400071a7  test    rax, rax
0x1400071aa  jz      short loc_1400071E2
0x1400071ac  and     [rsp+600h+var_5C8], 0
0x1400071b2  lea     rcx, [rsp+600h+var_5A0]
0x1400071b7  mov     rdx, [rsp+600h+ImageBase]; ImageBase
0x1400071bc  mov     r9, rax; FunctionEntry
0x1400071bf  mov     [rsp+600h+EstablisherFrame], rcx; EstablisherFrame
0x1400071c4  mov     r8, r14; ControlPc
0x1400071c7  lea     rcx, [rsp+600h+var_5A8]
0x1400071cc  mov     [rsp+600h+HandlerData], rcx; HandlerData
0x1400071d1  lea     rcx, [rbp+500h+ContextRecord]
0x1400071d5  mov     [rsp+600h+var_5E0], rcx; ContextRecord
0x1400071da  xor     ecx, ecx; HandlerType
0x1400071dc  call    cs:RtlVirtualUnwind; KERNEL32
0x1400071e2  mov     rax, [rbp+508h]
0x1400071e9  mov     [rbp+500h+ContextRecord.Rip], rax
0x1400071f0  lea     rax, [rbp+508h]
0x1400071f7  add     rax, 8
0x1400071fb  mov     [rsp+600h+var_590], esi
0x1400071ff  mov     [rbp+500h+ContextRecord.Rsp], rax
0x140007206  mov     rax, [rbp+508h]
0x14000720d  mov     [rbp+500h+var_580], rax
0x140007211  mov     [rsp+600h+var_58C], edi
0x140007215  call    cs:IsDebuggerPresent; KERNEL32
0x14000721b  xor     ecx, ecx; lpTopLevelExceptionFilter
0x14000721d  mov     edi, eax
0x14000721f  call    cs:SetUnhandledExceptionFilter; KERNEL32
0x140007225  lea     rcx, [rsp+600h+ExceptionInfo]; ExceptionInfo
0x14000722a  call    cs:UnhandledExceptionFilter; KERNEL32
0x140007230  test    eax, eax
0x140007232  jnz     short loc_140007244
0x140007234  test    edi, edi
0x140007236  jnz     short loc_140007244
0x140007238  cmp     ebx, 0FFFFFFFFh
0x14000723b  jz      short loc_140007244
0x14000723d  mov     ecx, ebx
0x14000723f  call    sub_140002710
0x140007244  mov     rcx, [rbp+500h+var_20]
0x14000724b  xor     rcx, rsp; StackCookie
0x14000724e  call    __security_check_cookie
0x140007253  lea     r11, [rsp+600h+var_10]
0x14000725b  mov     rbx, [r11+28h]
0x14000725f  mov     rsi, [r11+30h]
0x140007263  mov     rsp, r11
0x140007266  pop     r14
0x140007268  pop     rdi
0x140007269  pop     rbp
0x14000726a  retn

// ===== sub_14000726C @ 0x14000726c =====

0x14000726c  mov     cs:qword_14001D320, rcx
0x140007273  retn

// ===== _invalid_parameter @ 0x140007274 =====

0x140007274  mov     rax, rsp
0x140007277  mov     [rax+8], rbx
0x14000727b  mov     [rax+10h], rbp
0x14000727f  mov     [rax+18h], rsi
0x140007283  mov     [rax+20h], rdi
0x140007287  push    r14
0x140007289  sub     rsp, 30h
0x14000728d  mov     edi, r9d
0x140007290  mov     rsi, r8
0x140007293  mov     rbp, rdx
0x140007296  mov     r14, rcx
0x140007299  call    __acrt_getptd_noexit
0x14000729e  test    rax, rax
0x1400072a1  jz      short loc_1400072E4
0x1400072a3  mov     rbx, [rax+3B8h]
0x1400072aa  test    rbx, rbx
0x1400072ad  jz      short loc_1400072E4
0x1400072af  mov     rcx, rbx
0x1400072b2  call    cs:__guard_check_icall_fptr
0x1400072b8  mov     r9d, edi
0x1400072bb  mov     r8, rsi
0x1400072be  mov     rdx, rbp
0x1400072c1  mov     rcx, r14
0x1400072c4  mov     rax, rbx
0x1400072c7  mov     rbx, [rsp+38h+arg_0]
0x1400072cc  mov     rbp, [rsp+38h+arg_8]
0x1400072d1  mov     rsi, [rsp+38h+arg_10]
0x1400072d6  mov     rdi, [rsp+38h+arg_18]
0x1400072db  add     rsp, 30h
0x1400072df  pop     r14
0x1400072e1  jmp     rax
0x1400072e4  mov     rbx, cs:__security_cookie
0x1400072eb  mov     ecx, ebx
0x1400072ed  xor     rbx, cs:qword_14001D320
0x1400072f4  and     ecx, 3Fh
0x1400072f7  ror     rbx, cl
0x1400072fa  test    rbx, rbx
0x1400072fd  jnz     short loc_1400072AF
0x1400072ff  mov     rax, [rsp+38h+arg_20]
0x140007304  mov     r9d, edi; LineNo
0x140007307  mov     r8, rsi; FileName
0x14000730a  mov     [rsp+38h+Reserved], rax; Reserved
0x14000730f  mov     rdx, rbp; FunctionName
0x140007312  mov     rcx, r14; Expression
0x140007315  call    _invoke_watson

// ===== _invalid_parameter_noinfo @ 0x14000731c =====

0x14000731c  sub     rsp, 38h
0x140007320  and     [rsp+38h+var_18], 0
0x140007326  xor     r9d, r9d; LineNo
0x140007329  xor     r8d, r8d; FileName
0x14000732c  xor     edx, edx; FunctionName
0x14000732e  xor     ecx, ecx; Expression
0x140007330  call    _invalid_parameter
0x140007335  add     rsp, 38h
0x140007339  retn

// ===== _invoke_watson @ 0x14000733c =====

0x14000733c  sub     rsp, 28h
0x140007340  mov     ecx, 17h; ProcessorFeature
0x140007345  call    IsProcessorFeaturePresent
0x14000734a  test    eax, eax
0x14000734c  jz      short loc_140007355
0x14000734e  mov     ecx, 5
0x140007353  int     29h; Win8: RtlFailFast(ecx)
0x140007355  mov     r8d, 1
0x14000735b  mov     edx, 0C0000417h
0x140007360  lea     ecx, [r8+1]
0x140007364  call    __acrt_call_reportfault
0x140007369  call    cs:GetCurrentProcess; KERNEL32
0x14000736f  mov     rcx, rax
0x140007372  mov     edx, 0C0000417h
0x140007377  add     rsp, 28h
0x14000737b  jmp     cs:TerminateProcess; KERNEL32

// ===== isdigit @ 0x140007384 =====

0x140007384  push    rbx
0x140007386  sub     rsp, 40h
0x14000738a  movsxd  rbx, ecx
0x14000738d  mov     eax, cs:dword_14001D2E4
0x140007393  test    eax, eax
0x140007395  jz      short loc_1400073E2
0x140007397  xor     edx, edx; struct __crt_locale_pointers *
0x140007399  lea     rcx, [rsp+48h+var_28]; this
0x14000739e  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x1400073a3  mov     rax, [rsp+48h+Locale.locinfo]
0x1400073a8  cmp     dword ptr [rax+8], 1
0x1400073ac  jle     short loc_1400073C3
0x1400073ae  lea     r8, [rsp+48h+Locale]; Locale
0x1400073b3  mov     edx, 4; Type
0x1400073b8  mov     ecx, ebx; C
0x1400073ba  call    _isctype_l
0x1400073bf  mov     edx, eax
0x1400073c1  jmp     short loc_1400073CD
0x1400073c3  mov     rax, [rax]
0x1400073c6  movzx   edx, word ptr [rax+rbx*2]
0x1400073ca  and     edx, 4
0x1400073cd  cmp     [rsp+48h+var_10], 0
0x1400073d2  jz      short loc_1400073F0
0x1400073d4  mov     rax, [rsp+48h+var_28]
0x1400073d9  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x1400073e0  jmp     short loc_1400073F0
0x1400073e2  mov     rax, cs:off_14001C160
0x1400073e9  movzx   edx, word ptr [rax+rbx*2]
0x1400073ed  and     edx, 4
0x1400073f0  mov     eax, edx
0x1400073f2  add     rsp, 40h
0x1400073f6  pop     rbx
0x1400073f7  retn

// ===== ?internal_isupper_l@@YA_NHQEAU__crt_locale_pointers@@@Z @ 0x1400073f8 =====

0x1400073f8  mov     [rsp+arg_0], rbx
0x1400073fd  push    rdi
0x1400073fe  sub     rsp, 20h
0x140007402  movsxd  rdi, ecx
0x140007405  test    rdx, rdx
0x140007408  jz      short loc_140007429
0x14000740a  mov     rax, [rdx]
0x14000740d  cmp     dword ptr [rax+8], 1
0x140007411  jle     short loc_140007424
0x140007413  mov     r8, rdx; Locale
0x140007416  mov     ecx, edi; C
0x140007418  mov     edx, 1; Type
0x14000741d  call    _isctype_l
0x140007422  jmp     short loc_140007435
0x140007424  mov     rax, [rax]
0x140007427  jmp     short loc_14000742E
0x140007429  call    __pctype_func
0x14000742e  movzx   eax, word ptr [rax+rdi*2]
0x140007432  and     eax, 1
0x140007435  mov     rbx, [rsp+28h+arg_0]
0x14000743a  test    eax, eax
0x14000743c  setnz   al
0x14000743f  add     rsp, 20h
0x140007443  pop     rdi
0x140007444  retn

// ===== _tolower_l @ 0x140007448 =====

0x140007448  mov     [rsp-8+arg_8], rbx
0x14000744d  mov     [rsp-8+arg_18], rsi
0x140007452  push    rbp
0x140007453  mov     rbp, rsp
0x140007456  sub     rsp, 70h
0x14000745a  movsxd  rbx, ecx
0x14000745d  lea     rcx, [rbp+var_20]; this
0x140007461  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x140007466  cmp     ebx, 100h
0x14000746c  jnb     short loc_1400074A6
0x14000746e  lea     rdx, [rbp+Locale]; struct __crt_locale_pointers *
0x140007472  mov     ecx, ebx; int
0x140007474  call    ?internal_isupper_l@@YA_NHQEAU__crt_locale_pointers@@@Z
0x140007479  test    al, al
0x14000747b  jz      short loc_14000748C
0x14000747d  mov     rax, [rbp+Locale.locinfo]
0x140007481  mov     rcx, [rax+110h]
0x140007488  movzx   ebx, byte ptr [rcx+rbx]
0x14000748c  cmp     [rbp+var_8], 0
0x140007490  jz      loc_140007572
0x140007496  mov     rax, [rbp+var_20]
0x14000749a  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x1400074a1  jmp     loc_140007572
0x1400074a6  xor     eax, eax
0x1400074a8  mov     [rbp+arg_0], ax
0x1400074ac  mov     [rbp+arg_2], al
0x1400074af  mov     rax, [rbp+Locale.locinfo]
0x1400074b3  cmp     dword ptr [rax+8], 1
0x1400074b7  jle     short loc_1400074E1
0x1400074b9  mov     esi, ebx
0x1400074bb  lea     rdx, [rbp+Locale]; Locale
0x1400074bf  sar     esi, 8
0x1400074c2  movzx   ecx, sil; C
0x1400074c6  call    _isleadbyte_l
0x1400074cb  test    eax, eax
0x1400074cd  jz      short loc_1400074E1
0x1400074cf  mov     byte ptr [rbp+arg_0], sil
0x1400074d3  mov     ecx, 2
0x1400074d8  mov     byte ptr [rbp+arg_0+1], bl
0x1400074db  mov     [rbp+arg_2], 0
0x1400074df  jmp     short loc_1400074F8
0x1400074e1  call    _errno
0x1400074e6  mov     ecx, 1
0x1400074eb  mov     dword ptr [rax], 2Ah ; '*'
0x1400074f1  mov     byte ptr [rbp+arg_0], bl
0x1400074f4  mov     byte ptr [rbp+arg_0+1], 0
0x1400074f8  mov     rdx, [rbp+Locale.locinfo]
0x1400074fc  lea     r9, [rbp+arg_0]; char *
0x140007500  xor     eax, eax
0x140007502  mov     [rsp+70h+var_30], 1; int
0x14000750a  mov     [rbp+arg_10], ax
0x14000750e  mov     r8d, 100h; unsigned int
0x140007514  mov     [rbp+arg_12], al
0x140007517  mov     eax, [rdx+0Ch]
0x14000751a  mov     rdx, [rdx+138h]; wchar_t *
0x140007521  mov     [rsp+70h+var_38], eax; int
0x140007525  lea     rax, [rbp+arg_10]
0x140007529  mov     [rsp+70h+var_40], 3; int
0x140007531  mov     [rsp+70h+var_48], rax; char *
0x140007536  mov     [rsp+70h+var_50], ecx; int
0x14000753a  lea     rcx, [rbp+Locale]; struct __crt_locale_pointers *
0x14000753e  call    __acrt_LCMapStringA
0x140007543  test    eax, eax
0x140007545  jz      loc_14000748C
0x14000754b  movzx   ebx, byte ptr [rbp+arg_10]
0x14000754f  cmp     eax, 1
0x140007552  jz      loc_14000748C
0x140007558  movzx   ecx, byte ptr [rbp+arg_10+1]
0x14000755c  shl     ebx, 8
0x14000755f  or      ebx, ecx
0x140007561  cmp     [rbp+var_8], 0
0x140007565  jz      short loc_140007572
0x140007567  mov     rcx, [rbp+var_20]
0x14000756b  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x140007572  lea     r11, [rsp+70h+var_s0]
0x140007577  mov     eax, ebx
0x140007579  mov     rbx, [r11+18h]
0x14000757d  mov     rsi, [r11+28h]
0x140007581  mov     rsp, r11
0x140007584  pop     rbp
0x140007585  retn

// ===== tolower @ 0x140007588 =====

0x140007588  sub     rsp, 28h
0x14000758c  mov     eax, cs:dword_14001D2E4
0x140007592  test    eax, eax
0x140007594  jz      short loc_1400075A1
0x140007596  xor     edx, edx; Locale
0x140007598  call    _tolower_l
0x14000759d  mov     ecx, eax
0x14000759f  jmp     short loc_1400075AC
0x1400075a1  lea     eax, [rcx-41h]
0x1400075a4  cmp     eax, 19h
0x1400075a7  ja      short loc_1400075AC
0x1400075a9  add     ecx, 20h ; ' '
0x1400075ac  mov     eax, ecx
0x1400075ae  add     rsp, 28h
0x1400075b2  retn

// ===== __acrt_errno_from_os_error @ 0x1400075b4 =====

0x1400075b4  xor     eax, eax
0x1400075b6  lea     r9, dword_140012190
0x1400075bd  mov     rdx, r9
0x1400075c0  lea     r8d, [rax+8]
0x1400075c4  cmp     ecx, [rdx]
0x1400075c6  jz      short loc_1400075F3
0x1400075c8  inc     eax
0x1400075ca  add     rdx, r8
0x1400075cd  cmp     eax, 2Dh ; '-'
0x1400075d0  jb      short loc_1400075C4
0x1400075d2  lea     eax, [rcx-13h]
0x1400075d5  cmp     eax, 11h
0x1400075d8  ja      short loc_1400075E0
0x1400075da  mov     eax, 0Dh
0x1400075df  retn
0x1400075e0  add     ecx, 0FFFFFF44h
0x1400075e6  mov     eax, 16h
0x1400075eb  cmp     ecx, 0Eh
0x1400075ee  cmovbe  eax, r8d
0x1400075f2  retn
0x1400075f3  mov     eax, [r9+rax*8+4]
0x1400075f8  retn

// ===== __acrt_errno_map_os_error @ 0x1400075fc =====

0x1400075fc  mov     [rsp+arg_0], rbx
0x140007601  push    rdi
0x140007602  sub     rsp, 20h
0x140007606  mov     edi, ecx
0x140007608  call    __acrt_getptd_noexit
0x14000760d  test    rax, rax
0x140007610  jnz     short loc_14000761B
0x140007612  lea     rax, unk_14001C154
0x140007619  jmp     short loc_14000761F
0x14000761b  add     rax, 24h ; '$'
0x14000761f  mov     [rax], edi
0x140007621  call    __acrt_getptd_noexit
0x140007626  lea     rbx, unk_14001C150
0x14000762d  test    rax, rax
0x140007630  jz      short loc_140007636
0x140007632  lea     rbx, [rax+20h]
0x140007636  mov     ecx, edi
0x140007638  call    __acrt_errno_from_os_error
0x14000763d  mov     [rbx], eax
0x14000763f  mov     rbx, [rsp+28h+arg_0]
0x140007644  add     rsp, 20h
0x140007648  pop     rdi
0x140007649  retn

// ===== __doserrno @ 0x14000764c =====

0x14000764c  sub     rsp, 28h
0x140007650  call    __acrt_getptd_noexit
0x140007655  test    rax, rax
0x140007658  jnz     short loc_140007663
0x14000765a  lea     rax, unk_14001C154
0x140007661  jmp     short loc_140007667
0x140007663  add     rax, 24h ; '$'
0x140007667  add     rsp, 28h
0x14000766b  retn

// ===== _errno @ 0x14000766c =====

0x14000766c  sub     rsp, 28h
0x140007670  call    __acrt_getptd_noexit
0x140007675  test    rax, rax
0x140007678  jnz     short loc_140007683
0x14000767a  lea     rax, unk_14001C150
0x140007681  jmp     short loc_140007687
0x140007683  add     rax, 20h ; ' '
0x140007687  add     rsp, 28h
0x14000768b  retn

// ===== _free_base @ 0x14000768c =====

0x14000768c  test    rcx, rcx
0x14000768f  jz      short locret_1400076C8
0x140007691  push    rbx
0x140007692  sub     rsp, 20h
0x140007696  mov     r8, rcx; lpMem
0x140007699  xor     edx, edx; dwFlags
0x14000769b  mov     rcx, cs:hHeap; hHeap
0x1400076a2  call    cs:HeapFree; KERNEL32
0x1400076a8  test    eax, eax
0x1400076aa  jnz     short loc_1400076C3
0x1400076ac  call    _errno
0x1400076b1  mov     rbx, rax
0x1400076b4  call    cs:GetLastError; KERNEL32
0x1400076ba  mov     ecx, eax
0x1400076bc  call    __acrt_errno_from_os_error
0x1400076c1  mov     [rbx], eax
0x1400076c3  add     rsp, 20h
0x1400076c7  pop     rbx
0x1400076c8  retn

// ===== _malloc_base @ 0x1400076cc =====

0x1400076cc  push    rbx
0x1400076ce  sub     rsp, 20h
0x1400076d2  mov     rbx, rcx
0x1400076d5  cmp     rcx, 0FFFFFFFFFFFFFFE0h
0x1400076d9  ja      short loc_140007717
0x1400076db  test    rcx, rcx
0x1400076de  mov     eax, 1
0x1400076e3  cmovz   rbx, rax
0x1400076e7  jmp     short loc_1400076FE
0x1400076e9  call    sub_140006248
0x1400076ee  test    eax, eax
0x1400076f0  jz      short loc_140007717
0x1400076f2  mov     rcx, rbx; Size
0x1400076f5  call    _callnewh
0x1400076fa  test    eax, eax
0x1400076fc  jz      short loc_140007717
0x1400076fe  mov     rcx, cs:hHeap; hHeap
0x140007705  mov     r8, rbx; dwBytes
0x140007708  xor     edx, edx; dwFlags
0x14000770a  call    cs:HeapAlloc; KERNEL32
0x140007710  test    rax, rax
0x140007713  jz      short loc_1400076E9
0x140007715  jmp     short loc_140007724
0x140007717  call    _errno
0x14000771c  mov     dword ptr [rax], 0Ch
0x140007722  xor     eax, eax
0x140007724  add     rsp, 20h
0x140007728  pop     rbx
0x140007729  retn

// ===== unknown_libname_15 @ 0x14000772c =====

0x14000772c  mov     [rcx], rdx
0x14000772f  mov     [rcx+8], r8
0x140007733  test    r8, r8
0x140007736  jz      short loc_14000773B
0x140007738  mov     [r8], rdx
0x14000773b  mov     rax, rcx
0x14000773e  retn

// ===== wcstol @ 0x140007740 =====

0x140007740  push    rbx
0x140007742  sub     rsp, 30h
0x140007746  mov     ebx, r8d
0x140007749  mov     r8, rdx
0x14000774c  mov     rdx, rcx
0x14000774f  lea     rcx, [rsp+38h+var_18]
0x140007754  call    unknown_libname_15; Microsoft VisualC 64bit universal runtime
0x140007759  mov     rdx, rax
0x14000775c  mov     r9b, 1
0x14000775f  mov     r8d, ebx
0x140007762  xor     ecx, ecx; struct __crt_locale_pointers *
0x140007764  call    ??$parse_integer@KV?$c_string_character_source@_W@__crt_strtox@@@__crt_strtox@@YAKQEAU__crt_locale_pointers@@V?$c_string_character_source@_W@0@H_N@Z
0x140007769  add     rsp, 30h
0x14000776d  pop     rbx
0x14000776e  retn

// ===== _mbtowc_l @ 0x140007770 =====

0x140007770  mov     rax, rsp
0x140007773  mov     [rax+8], rbx
0x140007777  mov     [rax+10h], rbp
0x14000777b  mov     [rax+18h], rsi
0x14000777f  mov     [rax+20h], rdi
0x140007783  push    r14
0x140007785  sub     rsp, 50h
0x140007789  xor     r14d, r14d
0x14000778c  mov     rbp, r8
0x14000778f  mov     rsi, rdx
0x140007792  mov     rdi, rcx
0x140007795  test    rdx, rdx
0x140007798  jz      short loc_1400077AD
0x14000779a  test    r8, r8
0x14000779d  jz      short loc_1400077AD
0x14000779f  cmp     [rdx], r14b
0x1400077a2  jnz     short loc_1400077CA
0x1400077a4  test    rcx, rcx
0x1400077a7  jz      short loc_1400077AD
0x1400077a9  mov     [rcx], r14w
0x1400077ad  xor     eax, eax
0x1400077af  mov     rbx, [rsp+58h+arg_0]
0x1400077b4  mov     rbp, [rsp+58h+arg_8]
0x1400077b9  mov     rsi, [rsp+58h+arg_10]
0x1400077be  mov     rdi, [rsp+58h+arg_18]
0x1400077c3  add     rsp, 50h
0x1400077c7  pop     r14
0x1400077c9  retn
0x1400077ca  mov     rdx, r9; struct __crt_locale_pointers *
0x1400077cd  lea     rcx, [rsp+58h+var_28]; this
0x1400077d2  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x1400077d7  mov     rax, [rsp+58h+Locale.locinfo]
0x1400077dc  cmp     [rax+138h], r14
0x1400077e3  jnz     short loc_1400077FA
0x1400077e5  test    rdi, rdi
0x1400077e8  jz      short loc_1400077F0
0x1400077ea  movzx   eax, byte ptr [rsi]
0x1400077ed  mov     [rdi], ax
0x1400077f0  mov     ebx, 1
0x1400077f5  jmp     loc_14000789E
0x1400077fa  movzx   ecx, byte ptr [rsi]; C
0x1400077fd  lea     rdx, [rsp+58h+Locale]; Locale
0x140007802  call    _isleadbyte_l
0x140007807  mov     ebx, 1
0x14000780c  test    eax, eax
0x14000780e  jz      short loc_140007861
0x140007810  mov     rcx, [rsp+58h+Locale.locinfo]
0x140007815  mov     r9d, [rcx+8]; cbMultiByte
0x140007819  cmp     r9d, ebx
0x14000781c  jle     short loc_14000784D
0x14000781e  cmp     ebp, r9d
0x140007821  jl      short loc_14000784D
0x140007823  mov     ecx, [rcx+0Ch]; CodePage
0x140007826  lea     edx, [rbx+8]; dwFlags
0x140007829  mov     eax, r14d
0x14000782c  test    rdi, rdi
0x14000782f  mov     r8, rsi; lpMultiByteStr
0x140007832  setnz   al
0x140007835  mov     [rsp+58h+cchWideChar], eax; cchWideChar
0x140007839  mov     [rsp+58h+lpWideCharStr], rdi; lpWideCharStr
0x14000783e  call    cs:MultiByteToWideChar; KERNEL32
0x140007844  mov     rcx, [rsp+58h+Locale.locinfo]
0x140007849  test    eax, eax
0x14000784b  jnz     short loc_14000785C
0x14000784d  movsxd  rax, dword ptr [rcx+8]
0x140007851  cmp     rbp, rax
0x140007854  jb      short loc_140007890
0x140007856  cmp     [rsi+1], r14b
0x14000785a  jz      short loc_140007890
0x14000785c  mov     ebx, [rcx+8]
0x14000785f  jmp     short loc_14000789E
0x140007861  mov     eax, r14d
0x140007864  test    rdi, rdi
0x140007867  mov     r9d, ebx; cbMultiByte
0x14000786a  mov     r8, rsi; lpMultiByteStr
0x14000786d  setnz   al
0x140007870  mov     edx, 9; dwFlags
0x140007875  mov     [rsp+58h+cchWideChar], eax; cchWideChar
0x140007879  mov     rax, [rsp+58h+Locale.locinfo]
0x14000787e  mov     [rsp+58h+lpWideCharStr], rdi; lpWideCharStr
0x140007883  mov     ecx, [rax+0Ch]; CodePage
0x140007886  call    cs:MultiByteToWideChar; KERNEL32
0x14000788c  test    eax, eax
0x14000788e  jnz     short loc_14000789E
0x140007890  call    _errno
0x140007895  or      ebx, 0FFFFFFFFh
0x140007898  mov     dword ptr [rax], 2Ah ; '*'
0x14000789e  cmp     [rsp+58h+var_10], r14b
0x1400078a3  jz      short loc_1400078B1
0x1400078a5  mov     rcx, [rsp+58h+var_28]
0x1400078aa  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x1400078b1  mov     eax, ebx
0x1400078b3  jmp     loc_1400077AF

// ===== mbtowc @ 0x1400078b8 =====

0x1400078b8  xor     r9d, r9d; Locale
0x1400078bb  jmp     _mbtowc_l

// ===== wcsnlen @ 0x1400078c0 =====

0x1400078c0  push    rbp
0x1400078c2  sub     rsp, 20h
0x1400078c6  lea     rbp, [rsp+20h]
0x1400078cb  and     rbp, 0FFFFFFFFFFFFFFE0h
0x1400078cf  mov     eax, cs:dword_14001C018
0x1400078d5  mov     r10, rdx
0x1400078d8  mov     r8, rcx
0x1400078db  cmp     eax, 5
0x1400078de  jl      loc_1400079B4
0x1400078e4  test    cl, 1
0x1400078e7  jz      short loc_140007914
0x1400078e9  lea     rax, [rcx+rdx*2]
0x1400078ed  mov     rdx, rcx
0x1400078f0  cmp     rcx, rax
0x1400078f3  jz      loc_140007AA1
0x1400078f9  xor     r9d, r9d
0x1400078fc  cmp     [rdx], r9w
0x140007900  jz      loc_140007AA1
0x140007906  add     rdx, 2
0x14000790a  cmp     rdx, rax
0x14000790d  jnz     short loc_1400078FC
0x14000790f  jmp     loc_140007AA1
0x140007914  and     ecx, 1Fh
0x140007917  mov     eax, 20h ; ' '
0x14000791c  sub     rax, rcx
0x14000791f  neg     rcx
0x140007922  sbb     r11, r11
0x140007925  and     r11, rax
0x140007928  shr     r11, 1
0x14000792b  cmp     rdx, r11
0x14000792e  cmovb   r11, rdx
0x140007932  xor     r9d, r9d
0x140007935  mov     rdx, r8
0x140007938  lea     rax, [r8+r11*2]
0x14000793c  cmp     r8, rax
0x14000793f  jz      short loc_140007950
0x140007941  cmp     [rdx], r9w
0x140007945  jz      short loc_140007950
0x140007947  add     rdx, 2
0x14000794b  cmp     rdx, rax
0x14000794e  jnz     short loc_140007941
0x140007950  sub     rdx, r8
0x140007953  sar     rdx, 1
0x140007956  cmp     rdx, r11
0x140007959  jnz     loc_140007AA7
0x14000795f  mov     rcx, r10
0x140007962  lea     rdx, [r8+rdx*2]
0x140007966  sub     rcx, r11
0x140007969  mov     rax, rcx
0x14000796c  and     eax, 1Fh
0x14000796f  sub     rcx, rax
0x140007972  vxorps  ymm2, ymm2, ymm2
0x140007976  lea     r11, [rdx+rcx*2]
0x14000797a  jmp     short loc_14000798C
0x14000797c  vpcmpeqw ymm1, ymm2, ymmword ptr [rdx]
0x140007980  vpmovmskb eax, ymm1
0x140007984  test    eax, eax
0x140007986  jnz     short loc_140007991
0x140007988  add     rdx, 20h ; ' '
0x14000798c  cmp     rdx, r11
0x14000798f  jnz     short loc_14000797C
0x140007991  lea     rax, [r8+r10*2]
0x140007995  jmp     short loc_1400079A1
0x140007997  cmp     [rdx], r9w
0x14000799b  jz      short loc_1400079A6
0x14000799d  add     rdx, 2
0x1400079a1  cmp     rdx, rax
0x1400079a4  jnz     short loc_140007997
0x1400079a6  sub     rdx, r8
0x1400079a9  sar     rdx, 1
0x1400079ac  vzeroupper
0x1400079af  jmp     loc_140007AA7
0x1400079b4  cmp     eax, 1
0x1400079b7  jl      loc_140007A83
0x1400079bd  test    cl, 1
0x1400079c0  jz      short loc_1400079ED
0x1400079c2  lea     rax, [rcx+rdx*2]
0x1400079c6  mov     rdx, rcx
0x1400079c9  cmp     rcx, rax
0x1400079cc  jz      loc_140007AA1
0x1400079d2  xor     r9d, r9d
0x1400079d5  cmp     [rdx], r9w
0x1400079d9  jz      loc_140007AA1
0x1400079df  add     rdx, 2
0x1400079e3  cmp     rdx, rax
0x1400079e6  jnz     short loc_1400079D5
0x1400079e8  jmp     loc_140007AA1
0x1400079ed  and     ecx, 0Fh
0x1400079f0  mov     eax, 10h
0x1400079f5  sub     rax, rcx
0x1400079f8  neg     rcx
0x1400079fb  sbb     r11, r11
0x1400079fe  and     r11, rax
0x140007a01  shr     r11, 1
0x140007a04  cmp     rdx, r11
0x140007a07  cmovb   r11, rdx
0x140007a0b  xor     r9d, r9d
0x140007a0e  mov     rdx, r8
0x140007a11  lea     rax, [r8+r11*2]
0x140007a15  cmp     r8, rax
0x140007a18  jz      short loc_140007A29
0x140007a1a  cmp     [rdx], r9w
0x140007a1e  jz      short loc_140007A29
0x140007a20  add     rdx, 2
0x140007a24  cmp     rdx, rax
0x140007a27  jnz     short loc_140007A1A
0x140007a29  sub     rdx, r8
0x140007a2c  sar     rdx, 1
0x140007a2f  cmp     rdx, r11
0x140007a32  jnz     short loc_140007AA7
0x140007a34  mov     rcx, r10
0x140007a37  lea     rdx, [r8+rdx*2]
0x140007a3b  sub     rcx, r11
0x140007a3e  xorps   xmm1, xmm1
0x140007a41  mov     rax, rcx
0x140007a44  and     eax, 0Fh
0x140007a47  sub     rcx, rax
0x140007a4a  lea     r11, [rdx+rcx*2]
0x140007a4e  jmp     short loc_140007A64
0x140007a50  movdqa  xmm0, xmm1
0x140007a54  pcmpeqw xmm0, xmmword ptr [rdx]
0x140007a58  pmovmskb eax, xmm0
0x140007a5c  test    eax, eax
0x140007a5e  jnz     short loc_140007A69
0x140007a60  add     rdx, 10h
0x140007a64  cmp     rdx, r11
0x140007a67  jnz     short loc_140007A50
0x140007a69  lea     rax, [r8+r10*2]
0x140007a6d  jmp     short loc_140007A79
0x140007a6f  cmp     [rdx], r9w
0x140007a73  jz      short loc_140007A7E
0x140007a75  add     rdx, 2
0x140007a79  cmp     rdx, rax
0x140007a7c  jnz     short loc_140007A6F
0x140007a7e  sub     rdx, r8
0x140007a81  jmp     short loc_140007AA4
0x140007a83  lea     rax, [rcx+rdx*2]
0x140007a87  mov     rdx, rcx
0x140007a8a  cmp     rcx, rax
0x140007a8d  jz      short loc_140007AA1
0x140007a8f  xor     r9d, r9d
0x140007a92  cmp     [rdx], r9w
0x140007a96  jz      short loc_140007AA1
0x140007a98  add     rdx, 2
0x140007a9c  cmp     rdx, rax
0x140007a9f  jnz     short loc_140007A92
0x140007aa1  sub     rdx, rcx
0x140007aa4  sar     rdx, 1
0x140007aa7  mov     rax, rdx
0x140007aaa  add     rsp, 20h
0x140007aae  pop     rbp
0x140007aaf  retn

// ===== ??$?RV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@V_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@$$QEAV_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@Z @ 0x140007ab0 =====

0x140007ab0  mov     [rsp+arg_0], rbx
0x140007ab5  mov     [rsp+arg_18], r9
0x140007aba  push    rdi
0x140007abb  sub     rsp, 20h
0x140007abf  mov     rbx, r9
0x140007ac2  mov     rdi, r8
0x140007ac5  mov     ecx, [rdx]
0x140007ac7  call    sub_14000AB5C
0x140007acc  nop
0x140007acd  mov     rax, [rdi]
0x140007ad0  mov     rcx, [rax]
0x140007ad3  mov     rcx, [rcx+88h]; Block
0x140007ada  test    rcx, rcx
0x140007add  jz      short loc_140007AFD
0x140007adf  or      eax, 0FFFFFFFFh
0x140007ae2  lock xadd [rcx], eax
0x140007ae6  cmp     eax, 1
0x140007ae9  jnz     short loc_140007AFD
0x140007aeb  lea     rax, unk_14001C2D0
0x140007af2  cmp     rcx, rax
0x140007af5  jz      short loc_140007AFD
0x140007af7  call    _free_base
0x140007afc  nop
0x140007afd  mov     ecx, [rbx]
0x140007aff  call    sub_14000ABB0
0x140007b04  mov     rbx, [rsp+28h+arg_0]
0x140007b09  add     rsp, 20h
0x140007b0d  pop     rdi
0x140007b0e  retn
0x140010a3b  push    rbp
0x140010a3d  sub     rsp, 20h
0x140010a41  mov     rbp, rdx
0x140010a44  mov     rax, [rbp+48h]
0x140010a48  mov     ecx, [rax]
0x140010a4a  add     rsp, 20h
0x140010a4e  pop     rbp
0x140010a4f  jmp     sub_14000ABB0

// ===== ??$?RV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@V_lambda_341c25c0346d94847f1f3c463c57e077_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@$$QEAV_lambda_341c25c0346d94847f1f3c463c57e077_@@@Z @ 0x140007b10 =====

0x140007b10  mov     [rsp+arg_0], rbx
0x140007b15  mov     [rsp+arg_18], r9
0x140007b1a  push    rdi
0x140007b1b  sub     rsp, 20h
0x140007b1f  mov     rbx, r9
0x140007b22  mov     rdi, r8
0x140007b25  mov     ecx, [rdx]
0x140007b27  call    sub_14000AB5C
0x140007b2c  nop
0x140007b2d  mov     rax, [rdi+8]
0x140007b31  mov     rdx, [rax]
0x140007b34  mov     rcx, [rdi]
0x140007b37  mov     rdx, [rdx]; struct __crt_locale_data *
0x140007b3a  mov     rcx, [rcx]; struct __acrt_ptd *
0x140007b3d  call    ?replace_current_thread_locale_nolock@@YAXQEAU__acrt_ptd@@QEAU__crt_locale_data@@@Z
0x140007b42  nop
0x140007b43  mov     ecx, [rbx]
0x140007b45  call    sub_14000ABB0
0x140007b4a  mov     rbx, [rsp+28h+arg_0]
0x140007b4f  add     rsp, 20h
0x140007b53  pop     rdi
0x140007b54  retn
0x140010a3b  push    rbp
0x140010a3d  sub     rsp, 20h
0x140010a41  mov     rbp, rdx
0x140010a44  mov     rax, [rbp+48h]
0x140010a48  mov     ecx, [rax]
0x140010a4a  add     rsp, 20h
0x140010a4e  pop     rbp
0x140010a4f  jmp     sub_14000ABB0

// ===== ??$?RV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@V_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@$$QEAV_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@Z @ 0x140007b58 =====

0x140007b58  mov     [rsp+arg_0], rbx
0x140007b5d  mov     [rsp+arg_18], r9
0x140007b62  push    rdi
0x140007b63  sub     rsp, 20h
0x140007b67  mov     rbx, r9
0x140007b6a  mov     rdi, r8
0x140007b6d  mov     ecx, [rdx]
0x140007b6f  call    sub_14000AB5C
0x140007b74  nop
0x140007b75  mov     rax, [rdi]
0x140007b78  mov     rcx, [rax]
0x140007b7b  mov     rax, [rcx+88h]
0x140007b82  lock inc dword ptr [rax]
0x140007b85  mov     ecx, [rbx]
0x140007b87  call    sub_14000ABB0
0x140007b8c  mov     rbx, [rsp+28h+arg_0]
0x140007b91  add     rsp, 20h
0x140007b95  pop     rdi
0x140007b96  retn
0x140010a3b  push    rbp
0x140010a3d  sub     rsp, 20h
0x140010a41  mov     rbp, rdx
0x140010a44  mov     rax, [rbp+48h]
0x140010a48  mov     ecx, [rax]
0x140010a4a  add     rsp, 20h
0x140010a4e  pop     rbp
0x140010a4f  jmp     sub_14000ABB0

// ===== ??$?RV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@V_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@$$QEAV_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@Z @ 0x140007b98 =====

0x140007b98  mov     [rsp+arg_0], rbx
0x140007b9d  mov     [rsp+arg_18], r9
0x140007ba2  push    rdi
0x140007ba3  sub     rsp, 20h
0x140007ba7  mov     rbx, r9
0x140007baa  mov     rdi, r8
0x140007bad  mov     ecx, [rdx]
0x140007baf  call    sub_14000AB5C
0x140007bb4  nop
0x140007bb5  mov     rcx, [rdi]
0x140007bb8  xor     edx, edx; struct __crt_locale_data *
0x140007bba  mov     rcx, [rcx]; struct __acrt_ptd *
0x140007bbd  call    ?replace_current_thread_locale_nolock@@YAXQEAU__acrt_ptd@@QEAU__crt_locale_data@@@Z
0x140007bc2  nop
0x140007bc3  mov     ecx, [rbx]
0x140007bc5  call    sub_14000ABB0
0x140007bca  mov     rbx, [rsp+28h+arg_0]
0x140007bcf  add     rsp, 20h
0x140007bd3  pop     rdi
0x140007bd4  retn
0x140010a3b  push    rbp
0x140010a3d  sub     rsp, 20h
0x140010a41  mov     rbp, rdx
0x140010a44  mov     rax, [rbp+48h]
0x140010a48  mov     ecx, [rax]
0x140010a4a  add     rsp, 20h
0x140010a4e  pop     rbp
0x140010a4f  jmp     sub_14000ABB0

// ===== ?construct_ptd_array@@YAXQEAU__acrt_ptd@@@Z @ 0x140007bd8 =====

0x140007bd8  push    rbp
0x140007bda  mov     rbp, rsp
0x140007bdd  sub     rsp, 50h
0x140007be1  mov     [rbp+var_28], rcx
0x140007be5  lea     rax, [rbp+var_28]
0x140007be9  mov     [rbp+var_18], rax
0x140007bed  lea     r9, [rbp+arg_10]
0x140007bf1  mov     edx, 1
0x140007bf6  lea     r8, [rbp+var_18]
0x140007bfa  mov     eax, 5
0x140007bff  mov     [rbp+arg_10], eax
0x140007c02  mov     [rbp+arg_18], eax
0x140007c05  lea     rax, [rbp+var_28]
0x140007c09  mov     [rbp+var_10], rax
0x140007c0d  lea     rax, [rbp+var_20]
0x140007c11  mov     [rbp+var_8], rax
0x140007c15  mov     eax, 4
0x140007c1a  mov     [rbp+var_30], eax
0x140007c1d  mov     [rbp+var_2C], eax
0x140007c20  lea     rax, qword_14001D340
0x140007c27  mov     [rbp+var_20], rax
0x140007c2b  mov     [rcx+28h], edx
0x140007c2e  lea     rcx, unk_140011FA0
0x140007c35  mov     rax, [rbp+var_28]
0x140007c39  mov     [rax], rcx
0x140007c3c  lea     rcx, unk_14001C2D0
0x140007c43  mov     rax, [rbp+var_28]
0x140007c47  mov     [rax+3A8h], edx
0x140007c4d  mov     rax, [rbp+var_28]
0x140007c51  mov     [rax+88h], rcx
0x140007c58  lea     ecx, [rdx+42h]
0x140007c5b  mov     rax, [rbp+var_28]
0x140007c5f  lea     rdx, [rbp+arg_18]
0x140007c63  mov     [rax+0BCh], cx
0x140007c6a  mov     rax, [rbp+var_28]
0x140007c6e  mov     [rax+1C2h], cx
0x140007c75  lea     rcx, [rbp+arg_8]
0x140007c79  mov     rax, [rbp+var_28]
0x140007c7d  and     qword ptr [rax+3A0h], 0
0x140007c85  call    ??$?RV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@V_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@$$QEAV_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@Z
0x140007c8a  lea     r9, [rbp+var_30]
0x140007c8e  lea     r8, [rbp+var_10]
0x140007c92  lea     rdx, [rbp+var_2C]
0x140007c96  lea     rcx, [rbp+arg_8]
0x140007c9a  call    ??$?RV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@V_lambda_341c25c0346d94847f1f3c463c57e077_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@$$QEAV_lambda_341c25c0346d94847f1f3c463c57e077_@@@Z
0x140007c9f  add     rsp, 50h
0x140007ca3  pop     rbp
0x140007ca4  retn

// ===== ?destroy_fls@@YAXPEAX@Z @ 0x140007ca8 =====

0x140007ca8  test    rcx, rcx
0x140007cab  jz      short locret_140007CC7
0x140007cad  push    rbx
0x140007cae  sub     rsp, 20h
0x140007cb2  mov     rbx, rcx
0x140007cb5  call    ?destroy_ptd_array@@YAXQEAU__acrt_ptd@@@Z
0x140007cba  mov     rcx, rbx; Block
0x140007cbd  call    _free_base
0x140007cc2  add     rsp, 20h
0x140007cc6  pop     rbx
0x140007cc7  retn

// ===== ?destroy_ptd_array@@YAXQEAU__acrt_ptd@@@Z @ 0x140007cc8 =====

0x140007cc8  push    rbp
0x140007cca  mov     rbp, rsp
0x140007ccd  sub     rsp, 40h
0x140007cd1  lea     rax, [rbp+var_18]
0x140007cd5  mov     [rbp+var_18], rcx
0x140007cd9  mov     [rbp+var_10], rax
0x140007cdd  lea     rdx, unk_140011FA0
0x140007ce4  mov     eax, 5
0x140007ce9  mov     [rbp+arg_10], eax
0x140007cec  mov     [rbp+arg_18], eax
0x140007cef  lea     rax, [rbp+var_18]
0x140007cf3  mov     [rbp+var_8], rax
0x140007cf7  mov     eax, 4
0x140007cfc  mov     [rbp+var_20], eax
0x140007cff  mov     [rbp+var_1C], eax
0x140007d02  mov     rax, [rcx]
0x140007d05  cmp     rax, rdx
0x140007d08  jz      short loc_140007D16
0x140007d0a  mov     rcx, rax; Block
0x140007d0d  call    _free_base
0x140007d12  mov     rcx, [rbp+var_18]
0x140007d16  mov     rcx, [rcx+70h]; Block
0x140007d1a  call    _free_base
0x140007d1f  mov     rcx, [rbp+var_18]
0x140007d23  mov     rcx, [rcx+58h]; Block
0x140007d27  call    _free_base
0x140007d2c  mov     rcx, [rbp+var_18]
0x140007d30  mov     rcx, [rcx+60h]; Block
0x140007d34  call    _free_base
0x140007d39  mov     rcx, [rbp+var_18]
0x140007d3d  mov     rcx, [rcx+68h]; Block
0x140007d41  call    _free_base
0x140007d46  mov     rcx, [rbp+var_18]
0x140007d4a  mov     rcx, [rcx+48h]; Block
0x140007d4e  call    _free_base
0x140007d53  mov     rcx, [rbp+var_18]
0x140007d57  mov     rcx, [rcx+50h]; Block
0x140007d5b  call    _free_base
0x140007d60  mov     rcx, [rbp+var_18]
0x140007d64  mov     rcx, [rcx+78h]; Block
0x140007d68  call    _free_base
0x140007d6d  mov     rcx, [rbp+var_18]
0x140007d71  mov     rcx, [rcx+80h]; Block
0x140007d78  call    _free_base
0x140007d7d  mov     rcx, [rbp+var_18]
0x140007d81  mov     rcx, [rcx+3C0h]; Block
0x140007d88  call    _free_base
0x140007d8d  lea     r9, [rbp+arg_10]
0x140007d91  lea     r8, [rbp+var_10]
0x140007d95  lea     rdx, [rbp+arg_18]
0x140007d99  lea     rcx, [rbp+arg_8]
0x140007d9d  call    ??$?RV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@V_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@$$QEAV_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@Z
0x140007da2  lea     r9, [rbp+var_20]
0x140007da6  lea     r8, [rbp+var_8]
0x140007daa  lea     rdx, [rbp+var_1C]
0x140007dae  lea     rcx, [rbp+arg_8]
0x140007db2  call    ??$?RV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@V_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@$$QEAV_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@Z
0x140007db7  add     rsp, 40h
0x140007dbb  pop     rbp
0x140007dbc  retn

// ===== ?replace_current_thread_locale_nolock@@YAXQEAU__acrt_ptd@@QEAU__crt_locale_data@@@Z @ 0x140007dc0 =====

0x140007dc0  mov     [rsp+arg_0], rbx
0x140007dc5  push    rdi
0x140007dc6  sub     rsp, 20h
0x140007dca  mov     rdi, rcx
0x140007dcd  mov     rbx, rdx
0x140007dd0  mov     rcx, [rcx+90h]
0x140007dd7  test    rcx, rcx
0x140007dda  jz      short loc_140007E08
0x140007ddc  call    __acrt_release_locale_ref
0x140007de1  mov     rcx, [rdi+90h]; Block
0x140007de8  cmp     rcx, cs:qword_14001D340
0x140007def  jz      short loc_140007E08
0x140007df1  lea     rax, off_14001C160
0x140007df8  cmp     rcx, rax
0x140007dfb  jz      short loc_140007E08
0x140007dfd  cmp     dword ptr [rcx+10h], 0
0x140007e01  jnz     short loc_140007E08
0x140007e03  call    __acrt_free_locale
0x140007e08  mov     [rdi+90h], rbx
0x140007e0f  test    rbx, rbx
0x140007e12  jz      short loc_140007E1C
0x140007e14  mov     rcx, rbx
0x140007e17  call    __acrt_add_locale_ref
0x140007e1c  mov     rbx, [rsp+28h+arg_0]
0x140007e21  add     rsp, 20h
0x140007e25  pop     rdi
0x140007e26  retn

// ===== __acrt_getptd @ 0x140007e28 =====

0x140007e28  mov     [rsp+arg_0], rbx
0x140007e2d  push    rdi
0x140007e2e  sub     rsp, 20h
0x140007e32  call    cs:GetLastError; KERNEL32
0x140007e38  mov     ecx, cs:dwTlsIndex; dwTlsIndex
0x140007e3e  mov     ebx, eax
0x140007e40  cmp     ecx, 0FFFFFFFFh
0x140007e43  jz      short loc_140007E52
0x140007e45  call    __vcrt_FlsFree_0
0x140007e4a  mov     rdi, rax
0x140007e4d  test    rax, rax
0x140007e50  jnz     short loc_140007E93
0x140007e52  mov     edx, 3C8h; Size
0x140007e57  mov     ecx, 1; Count
0x140007e5c  call    _calloc_base
0x140007e61  mov     rdi, rax
0x140007e64  test    rax, rax
0x140007e67  jnz     short loc_140007E72
0x140007e69  xor     ecx, ecx; Block
0x140007e6b  call    _free_base
0x140007e70  jmp     short loc_140007EAE
0x140007e72  mov     ecx, cs:dwTlsIndex; dwTlsIndex
0x140007e78  mov     rdx, rax; lpTlsValue
0x140007e7b  call    __acrt_FlsSetValue
0x140007e80  mov     rcx, rdi; struct __acrt_ptd *
0x140007e83  test    eax, eax
0x140007e85  jz      short loc_140007E6B
0x140007e87  call    ?construct_ptd_array@@YAXQEAU__acrt_ptd@@@Z
0x140007e8c  xor     ecx, ecx; Block
0x140007e8e  call    _free_base
0x140007e93  test    rdi, rdi
0x140007e96  jz      short loc_140007EAE
0x140007e98  mov     ecx, ebx; dwErrCode
0x140007e9a  call    cs:SetLastError; KERNEL32
0x140007ea0  mov     rbx, [rsp+28h+arg_0]
0x140007ea5  mov     rax, rdi
0x140007ea8  add     rsp, 20h
0x140007eac  pop     rdi
0x140007ead  retn
0x140007eae  mov     ecx, ebx; dwErrCode
0x140007eb0  call    cs:SetLastError; KERNEL32
0x140007eb6  call    abort

// ===== __acrt_getptd_noexit @ 0x140007ebc =====

0x140007ebc  mov     [rsp+arg_0], rbx
0x140007ec1  mov     [rsp+arg_8], rsi
0x140007ec6  push    rdi
0x140007ec7  sub     rsp, 20h
0x140007ecb  call    cs:GetLastError; KERNEL32
0x140007ed1  mov     ecx, cs:dwTlsIndex; dwTlsIndex
0x140007ed7  xor     esi, esi
0x140007ed9  mov     ebx, eax
0x140007edb  cmp     ecx, 0FFFFFFFFh
0x140007ede  jz      short loc_140007EED
0x140007ee0  call    __vcrt_FlsFree_0
0x140007ee5  mov     rdi, rax
0x140007ee8  test    rax, rax
0x140007eeb  jnz     short loc_140007F2E
0x140007eed  mov     edx, 3C8h; Size
0x140007ef2  mov     ecx, 1; Count
0x140007ef7  call    _calloc_base
0x140007efc  mov     rdi, rax
0x140007eff  test    rax, rax
0x140007f02  jnz     short loc_140007F0D
0x140007f04  xor     ecx, ecx; Block
0x140007f06  call    _free_base
0x140007f0b  jmp     short loc_140007F33
0x140007f0d  mov     ecx, cs:dwTlsIndex; dwTlsIndex
0x140007f13  mov     rdx, rax; lpTlsValue
0x140007f16  call    __acrt_FlsSetValue
0x140007f1b  mov     rcx, rdi; struct __acrt_ptd *
0x140007f1e  test    eax, eax
0x140007f20  jz      short loc_140007F06
0x140007f22  call    ?construct_ptd_array@@YAXQEAU__acrt_ptd@@@Z
0x140007f27  xor     ecx, ecx; Block
0x140007f29  call    _free_base
0x140007f2e  test    rdi, rdi
0x140007f31  jnz     short loc_140007F3D
0x140007f33  mov     ecx, ebx; dwErrCode
0x140007f35  call    cs:SetLastError; KERNEL32
0x140007f3b  jmp     short loc_140007F48
0x140007f3d  mov     ecx, ebx; dwErrCode
0x140007f3f  call    cs:SetLastError; KERNEL32
0x140007f45  mov     rsi, rdi
0x140007f48  mov     rbx, [rsp+28h+arg_0]
0x140007f4d  mov     rax, rsi
0x140007f50  mov     rsi, [rsp+28h+arg_8]
0x140007f55  add     rsp, 20h
0x140007f59  pop     rdi
0x140007f5a  retn

// ===== __acrt_initialize_ptd @ 0x140007f5c =====

0x140007f5c  sub     rsp, 28h
0x140007f60  lea     rcx, ?destroy_fls@@YAXPEAX@Z
0x140007f67  call    __acrt_FlsAlloc
0x140007f6c  mov     cs:dwTlsIndex, eax
0x140007f72  cmp     eax, 0FFFFFFFFh
0x140007f75  jnz     short loc_140007F7B
0x140007f77  xor     al, al
0x140007f79  jmp     short loc_140007F90
0x140007f7b  call    __acrt_getptd_noexit
0x140007f80  test    rax, rax
0x140007f83  jnz     short loc_140007F8E
0x140007f85  xor     ecx, ecx
0x140007f87  call    __vcrt_uninitialize_ptd_0
0x140007f8c  jmp     short loc_140007F77
0x140007f8e  mov     al, 1
0x140007f90  add     rsp, 28h
0x140007f94  retn

// ===== __vcrt_uninitialize_ptd_0 @ 0x140007f98 =====

0x140007f98  sub     rsp, 28h
0x140007f9c  mov     ecx, cs:dwTlsIndex; dwTlsIndex
0x140007fa2  cmp     ecx, 0FFFFFFFFh
0x140007fa5  jz      short loc_140007FB3
0x140007fa7  call    __acrt_FlsFree
0x140007fac  or      cs:dwTlsIndex, 0FFFFFFFFh
0x140007fb3  mov     al, 1
0x140007fb5  add     rsp, 28h
0x140007fb9  retn

// ===== sub_140007FBC @ 0x140007fbc =====

0x140007fbc  push    rbx
0x140007fbe  sub     rsp, 20h
0x140007fc2  mov     rax, cs:qword_14001D340
0x140007fc9  mov     rbx, rdx
0x140007fcc  cmp     [rdx], rax
0x140007fcf  jz      short loc_140007FE7
0x140007fd1  mov     eax, [rcx+3A8h]
0x140007fd7  test    cs:dword_14001C8C0, eax
0x140007fdd  jnz     short loc_140007FE7
0x140007fdf  call    __acrt_update_thread_locale_data
0x140007fe4  mov     [rbx], rax
0x140007fe7  add     rsp, 20h
0x140007feb  pop     rbx
0x140007fec  retn

// ===== sub_140007FF0 @ 0x140007ff0 =====

0x140007ff0  push    rbx
0x140007ff2  sub     rsp, 20h
0x140007ff6  mov     rax, cs:off_14001C4F8
0x140007ffd  mov     rbx, rdx
0x140008000  cmp     [rdx], rax
0x140008003  jz      short loc_14000801B
0x140008005  mov     eax, [rcx+3A8h]
0x14000800b  test    cs:dword_14001C8C0, eax
0x140008011  jnz     short loc_14000801B
0x140008013  call    __acrt_update_thread_multibyte_data
0x140008018  mov     [rbx], rax
0x14000801b  add     rsp, 20h
0x14000801f  pop     rbx
0x140008020  retn

// ===== ?__acrt_fp_classify@@YA?AW4__acrt_fp_class@@AEBN@Z @ 0x140008024 =====

0x140008024  mov     rdx, [rcx]
0x140008027  mov     ecx, 7FFh
0x14000802c  mov     rax, rdx
0x14000802f  shr     rax, 34h
0x140008033  and     rax, rcx
0x140008036  cmp     rax, rcx
0x140008039  jz      short loc_14000803E
0x14000803b  xor     eax, eax
0x14000803d  retn
0x14000803e  mov     rcx, 0FFFFFFFFFFFFFh
0x140008048  mov     rax, rdx
0x14000804b  and     rax, rcx
0x14000804e  jnz     short loc_140008056
0x140008050  mov     eax, 1
0x140008055  retn
0x140008056  mov     rcx, 8000000000000000h
0x140008060  test    rcx, rdx
0x140008063  jz      short loc_14000807A
0x140008065  mov     rcx, 8000000000000h
0x14000806f  cmp     rax, rcx
0x140008072  jnz     short loc_14000807A
0x140008074  mov     eax, 4
0x140008079  retn
0x14000807a  shr     rdx, 33h
0x14000807e  not     edx
0x140008080  and     edx, 1
0x140008083  or      edx, 2
0x140008086  mov     eax, edx
0x140008088  retn

// ===== ?fp_format_a@@YAHQEBNPEAD_KQEAD2H_NIQEAU__crt_locale_pointers@@@Z @ 0x14000808c =====

0x14000808c  mov     rax, rsp
0x14000808f  mov     [rax+8], rbx
0x140008093  mov     [rax+10h], rbp
0x140008097  mov     [rax+18h], rsi
0x14000809b  mov     [rax+20h], rdi
0x14000809f  push    r12
0x1400080a1  push    r14
0x1400080a3  push    r15
0x1400080a5  sub     rsp, 70h
0x1400080a9  mov     ebx, [rsp+88h+arg_28]
0x1400080b0  xor     r12d, r12d
0x1400080b3  mov     rdi, rdx
0x1400080b6  mov     [rdx], r12b
0x1400080b9  mov     rdx, [rsp+88h+arg_40]; struct __crt_locale_pointers *
0x1400080c1  mov     rsi, rcx
0x1400080c4  test    ebx, ebx
0x1400080c6  lea     rcx, [rax-38h]; this
0x1400080ca  mov     r14, r9
0x1400080cd  mov     rbp, r8
0x1400080d0  cmovs   ebx, r12d
0x1400080d4  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x1400080d9  lea     eax, [rbx+0Bh]
0x1400080dc  movsxd  rdx, eax
0x1400080df  cmp     rbp, rdx
0x1400080e2  ja      short loc_1400080FA
0x1400080e4  call    _errno
0x1400080e9  lea     ebx, [r12+22h]
0x1400080ee  mov     [rax], ebx
0x1400080f0  call    _invalid_parameter_noinfo
0x1400080f5  jmp     loc_1400083B5
0x1400080fa  mov     rax, [rsi]
0x1400080fd  mov     ecx, 7FFh
0x140008102  shr     rax, 34h
0x140008106  and     rax, rcx
0x140008109  cmp     rax, rcx
0x14000810c  jnz     short loc_140008185
0x14000810e  mov     eax, [rsp+88h+arg_38]
0x140008115  mov     r9, r14; char *
0x140008118  mov     [rsp+88h+var_48], r12; struct __crt_locale_pointers *
0x14000811d  mov     r8, rbp; unsigned __int64
0x140008120  mov     [rsp+88h+var_50], eax; unsigned int
0x140008124  mov     rdx, rdi; char *
0x140008127  mov     rax, [rsp+88h+arg_20]
0x14000812f  mov     rcx, rsi; double *
0x140008132  mov     [rsp+88h+var_58], r12b; bool
0x140008137  mov     [rsp+88h+var_60], ebx; int
0x14000813b  mov     [rsp+88h+var_68], rax; unsigned __int64
0x140008140  call    ?fp_format_e@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z
0x140008145  mov     ebx, eax
0x140008147  test    eax, eax
0x140008149  jz      short loc_140008153
0x14000814b  mov     [rdi], r12b
0x14000814e  jmp     loc_1400083B5
0x140008153  mov     edx, 65h ; 'e'; Ch
0x140008158  mov     rcx, rdi; Str
0x14000815b  call    strrchr
0x140008160  test    rax, rax
0x140008163  jz      loc_1400083B2
0x140008169  mov     cl, [rsp+88h+arg_30]
0x140008170  neg     cl
0x140008172  sbb     dl, dl
0x140008174  and     dl, 0E0h
0x140008177  add     dl, 70h ; 'p'
0x14000817a  mov     [rax], dl
0x14000817c  mov     [rax+3], r12b
0x140008180  jmp     loc_1400083B2
0x140008185  mov     rax, 8000000000000000h
0x14000818f  test    [rsi], rax
0x140008192  jz      short loc_14000819A
0x140008194  mov     byte ptr [rdi], 2Dh ; '-'
0x140008197  inc     rdi
0x14000819a  mov     r15b, [rsp+88h+arg_30]
0x1400081a2  mov     ebp, 3FFh
0x1400081a7  mov     al, r15b
0x1400081aa  mov     r10d, 30h ; '0'
0x1400081b0  neg     al
0x1400081b2  mov     r11, 0FFFFFFFFFFFFFh
0x1400081bc  mov     rax, 7FF0000000000000h
0x1400081c6  sbb     edx, edx
0x1400081c8  and     edx, 0FFFFFFE0h
0x1400081cb  sub     edx, 0FFFFFFD9h
0x1400081ce  test    [rsi], rax
0x1400081d1  jnz     short loc_1400081ED
0x1400081d3  mov     [rdi], r10b
0x1400081d6  inc     rdi
0x1400081d9  mov     rax, [rsi]
0x1400081dc  and     rax, r11
0x1400081df  neg     rax
0x1400081e2  sbb     rbp, rbp
0x1400081e5  and     ebp, 3FEh
0x1400081eb  jmp     short loc_1400081F3
0x1400081ed  mov     byte ptr [rdi], 31h ; '1'
0x1400081f0  inc     rdi
0x1400081f3  mov     r14, rdi
0x1400081f6  inc     rdi
0x1400081f9  test    ebx, ebx
0x1400081fb  jnz     short loc_140008202
0x1400081fd  mov     [r14], r12b
0x140008200  jmp     short loc_140008216
0x140008202  mov     rax, [rsp+88h+var_30]
0x140008207  mov     rcx, [rax+0F8h]
0x14000820e  mov     rax, [rcx]
0x140008211  mov     cl, [rax]
0x140008213  mov     [r14], cl
0x140008216  test    [rsi], r11
0x140008219  jbe     loc_1400082A9
0x14000821f  movzx   r8d, r10w
0x140008223  mov     r9, 0F000000000000h
0x14000822d  test    ebx, ebx
0x14000822f  jle     short loc_14000825F
0x140008231  mov     rax, [rsi]
0x140008234  mov     cl, r8b
0x140008237  and     rax, r9
0x14000823a  and     rax, r11
0x14000823d  shr     rax, cl
0x140008240  add     ax, r10w
0x140008244  cmp     ax, 39h ; '9'
0x140008248  jbe     short loc_14000824D
0x14000824a  add     ax, dx
0x14000824d  mov     [rdi], al
0x14000824f  dec     ebx
0x140008251  inc     rdi
0x140008254  shr     r9, 4
0x140008258  add     r8w, 0FFFCh
0x14000825d  jns     short loc_14000822D
0x14000825f  test    r8w, r8w
0x140008263  js      short loc_1400082A9
0x140008265  mov     rax, [rsi]
0x140008268  mov     cl, r8b
0x14000826b  and     rax, r9
0x14000826e  and     rax, r11
0x140008271  shr     rax, cl
0x140008274  cmp     ax, 8
0x140008278  jbe     short loc_1400082A9
0x14000827a  lea     rcx, [rdi-1]
0x14000827e  mov     al, [rcx]
0x140008280  sub     al, 46h ; 'F'
0x140008282  test    al, 0DFh
0x140008284  jnz     short loc_14000828E
0x140008286  mov     [rcx], r10b
0x140008289  dec     rcx
0x14000828c  jmp     short loc_14000827E
0x14000828e  cmp     rcx, r14
0x140008291  jz      short loc_1400082A6
0x140008293  mov     al, [rcx]
0x140008295  cmp     al, 39h ; '9'
0x140008297  jnz     short loc_1400082A0
0x140008299  add     dl, 3Ah ; ':'
0x14000829c  mov     [rcx], dl
0x14000829e  jmp     short loc_1400082A9
0x1400082a0  inc     al
0x1400082a2  mov     [rcx], al
0x1400082a4  jmp     short loc_1400082A9
0x1400082a6  inc     byte ptr [rcx-1]
0x1400082a9  test    ebx, ebx
0x1400082ab  jle     short loc_1400082C4
0x1400082ad  mov     r8, rbx
0x1400082b0  mov     dl, r10b
0x1400082b3  mov     rcx, rdi
0x1400082b6  call    sub_140002F60
0x1400082bb  add     rdi, rbx
0x1400082be  mov     r10d, 30h ; '0'
0x1400082c4  cmp     [r14], r12b
0x1400082c7  cmovz   rdi, r14
0x1400082cb  neg     r15b
0x1400082ce  sbb     al, al
0x1400082d0  and     al, 0E0h
0x1400082d2  add     al, 70h ; 'p'
0x1400082d4  mov     [rdi], al
0x1400082d6  mov     rcx, [rsi]
0x1400082d9  shr     rcx, 34h
0x1400082dd  and     ecx, 7FFh
0x1400082e3  sub     rcx, rbp
0x1400082e6  js      short loc_1400082F2
0x1400082e8  mov     byte ptr [rdi+1], 2Bh ; '+'
0x1400082ec  add     rdi, 2
0x1400082f0  jmp     short loc_1400082FD
0x1400082f2  mov     byte ptr [rdi+1], 2Dh ; '-'
0x1400082f6  add     rdi, 2
0x1400082fa  neg     rcx
0x1400082fd  mov     [rdi], r10b
0x140008300  mov     r8, rdi
0x140008303  cmp     rcx, 3E8h
0x14000830a  jl      short loc_14000833F
0x14000830c  mov     rax, 20C49BA5E353F7CFh
0x140008316  imul    rcx
0x140008319  sar     rdx, 7
0x14000831d  mov     rax, rdx
0x140008320  shr     rax, 3Fh
0x140008324  add     rdx, rax
0x140008327  lea     eax, [r10+rdx]
0x14000832b  mov     [rdi], al
0x14000832d  inc     rdi
0x140008330  imul    rax, rdx, 0FFFFFFFFFFFFFC18h
0x140008337  add     rcx, rax
0x14000833a  cmp     rdi, r8
0x14000833d  jnz     short loc_140008345
0x14000833f  cmp     rcx, 64h ; 'd'
0x140008343  jl      short loc_140008373
0x140008345  mov     rax, 0A3D70A3D70A3D70Bh
0x14000834f  imul    rcx
0x140008352  add     rdx, rcx
0x140008355  sar     rdx, 6
0x140008359  mov     rax, rdx
0x14000835c  shr     rax, 3Fh
0x140008360  add     rdx, rax
0x140008363  lea     eax, [r10+rdx]
0x140008367  mov     [rdi], al
0x140008369  inc     rdi
0x14000836c  imul    rax, rdx, -64h
0x140008370  add     rcx, rax
0x140008373  cmp     rdi, r8
0x140008376  jnz     short loc_14000837E
0x140008378  cmp     rcx, 0Ah
0x14000837c  jl      short loc_1400083A9
0x14000837e  mov     rax, 6666666666666667h
0x140008388  imul    rcx
0x14000838b  sar     rdx, 2
0x14000838f  mov     rax, rdx
0x140008392  shr     rax, 3Fh
0x140008396  add     rdx, rax
0x140008399  lea     eax, [r10+rdx]
0x14000839d  mov     [rdi], al
0x14000839f  inc     rdi
0x1400083a2  imul    rax, rdx, -0Ah
0x1400083a6  add     rcx, rax
0x1400083a9  add     cl, r10b
0x1400083ac  mov     [rdi], cl
0x1400083ae  mov     [rdi+1], r12b
0x1400083b2  mov     ebx, r12d
0x1400083b5  cmp     [rsp+88h+var_20], r12b
0x1400083ba  jz      short loc_1400083C8
0x1400083bc  mov     rcx, [rsp+88h+var_38]
0x1400083c1  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x1400083c8  lea     r11, [rsp+88h+var_18]
0x1400083cd  mov     eax, ebx
0x1400083cf  mov     rbx, [r11+20h]
0x1400083d3  mov     rbp, [r11+28h]
0x1400083d7  mov     rsi, [r11+30h]
0x1400083db  mov     rdi, [r11+38h]
0x1400083df  mov     rsp, r11
0x1400083e2  pop     r15
0x1400083e4  pop     r14
0x1400083e6  pop     r12
0x1400083e8  retn

// ===== ?fp_format_e@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z @ 0x1400083ec =====

0x1400083ec  mov     r11, rsp
0x1400083ef  mov     [r11+8], rbx
0x1400083f3  mov     [r11+10h], rbp
0x1400083f7  mov     [r11+18h], rsi
0x1400083fb  push    rdi
0x1400083fc  sub     rsp, 50h
0x140008400  mov     rax, [rsp+58h+arg_20]
0x140008408  mov     rsi, r8
0x14000840b  mov     ebp, [rsp+58h+arg_28]
0x140008412  lea     r8, [r11-18h]
0x140008416  mov     rcx, [rcx]
0x140008419  mov     rdi, rdx
0x14000841c  mov     [r11-38h], rax
0x140008420  lea     edx, [rbp+1]
0x140008423  call    __acrt_fltout
0x140008428  xor     ecx, ecx
0x14000842a  lea     r9, [rsp+58h+var_18]
0x14000842f  cmp     [rsp+58h+var_18], 2Dh ; '-'
0x140008434  lea     r8d, [rbp+1]
0x140008438  mov     rdx, rsi
0x14000843b  setz    cl
0x14000843e  xor     eax, eax
0x140008440  test    ebp, ebp
0x140008442  setnle  al
0x140008445  sub     rdx, rax
0x140008448  sub     rdx, rcx
0x14000844b  cmp     rsi, 0FFFFFFFFFFFFFFFFh
0x14000844f  cmovz   rdx, rsi
0x140008453  add     rcx, rax
0x140008456  add     rcx, rdi
0x140008459  call    __acrt_fp_strflt_to_string
0x14000845e  test    eax, eax
0x140008460  jz      short loc_140008467
0x140008462  mov     byte ptr [rdi], 0
0x140008465  jmp     short loc_1400084A4
0x140008467  mov     rax, [rsp+58h+arg_40]
0x14000846f  mov     r8d, ebp; int
0x140008472  mov     r9b, [rsp+58h+arg_30]; bool
0x14000847a  mov     rdx, rsi; unsigned __int64
0x14000847d  mov     [rsp+58h+var_20], rax; struct __crt_locale_pointers *
0x140008482  mov     rcx, rdi; char *
0x140008485  lea     rax, [rsp+58h+var_18]
0x14000848a  mov     [rsp+58h+var_28], 0; bool
0x14000848f  mov     [rsp+58h+var_30], rax; struct _strflt *
0x140008494  mov     eax, [rsp+58h+arg_38]
0x14000849b  mov     [rsp+58h+var_38], eax; unsigned int
0x14000849f  call    ?fp_format_e_internal@@YAHQEAD_KH_NIQEAU_strflt@@2QEAU__crt_locale_pointers@@@Z
0x1400084a4  mov     rbx, [rsp+58h+arg_0]
0x1400084a9  mov     rbp, [rsp+58h+arg_8]
0x1400084ae  mov     rsi, [rsp+58h+arg_10]
0x1400084b3  add     rsp, 50h
0x1400084b7  pop     rdi
0x1400084b8  retn

// ===== ?fp_format_e_internal@@YAHQEAD_KH_NIQEAU_strflt@@2QEAU__crt_locale_pointers@@@Z @ 0x1400084bc =====

0x1400084bc  mov     rax, rsp
0x1400084bf  mov     [rax+8], rbx
0x1400084c3  mov     [rax+10h], rbp
0x1400084c7  mov     [rax+18h], rsi
0x1400084cb  mov     [rax+20h], rdi
0x1400084cf  push    r15
0x1400084d1  sub     rsp, 50h
0x1400084d5  xor     eax, eax
0x1400084d7  movsxd  rbx, r8d
0x1400084da  test    r8d, r8d
0x1400084dd  mov     r15b, r9b
0x1400084e0  mov     rbp, rdx
0x1400084e3  mov     rdi, rcx
0x1400084e6  cmovg   eax, ebx
0x1400084e9  add     eax, 9
0x1400084ec  cdqe
0x1400084ee  cmp     rdx, rax
0x1400084f1  ja      short loc_140008521
0x1400084f3  call    _errno
0x1400084f8  mov     ebx, 22h ; '"'
0x1400084fd  mov     [rax], ebx
0x1400084ff  call    _invalid_parameter_noinfo
0x140008504  mov     eax, ebx
0x140008506  mov     rbx, [rsp+58h+arg_0]
0x14000850b  mov     rbp, [rsp+58h+arg_8]
0x140008510  mov     rsi, [rsp+58h+arg_10]
0x140008515  mov     rdi, [rsp+58h+arg_18]
0x14000851a  add     rsp, 50h
0x14000851e  pop     r15
0x140008520  retn
0x140008521  mov     rdx, [rsp+58h+arg_38]; struct __crt_locale_pointers *
0x140008529  lea     rcx, [rsp+58h+var_28]; this
0x14000852e  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x140008533  cmp     [rsp+58h+arg_30], 0
0x14000853b  mov     rsi, [rsp+58h+arg_28]
0x140008543  jz      short loc_140008577
0x140008545  xor     edx, edx
0x140008547  cmp     dword ptr [rsi], 2Dh ; '-'
0x14000854a  setz    dl
0x14000854d  xor     eax, eax
0x14000854f  add     rdx, rdi
0x140008552  test    ebx, ebx
0x140008554  setnle  al
0x140008557  test    eax, eax
0x140008559  jz      short loc_140008577
0x14000855b  or      r8, 0FFFFFFFFFFFFFFFFh
0x14000855f  inc     r8
0x140008562  cmp     byte ptr [rdx+r8], 0
0x140008567  jnz     short loc_14000855F
0x140008569  movsxd  rcx, eax
0x14000856c  inc     r8
0x14000856f  add     rcx, rdx
0x140008572  call    sub_1400036D0
0x140008577  cmp     dword ptr [rsi], 2Dh ; '-'
0x14000857a  mov     rdx, rdi
0x14000857d  jnz     short loc_140008586
0x14000857f  mov     byte ptr [rdi], 2Dh ; '-'
0x140008582  lea     rdx, [rdi+1]
0x140008586  test    ebx, ebx
0x140008588  jle     short loc_1400085A5
0x14000858a  mov     al, [rdx+1]
0x14000858d  mov     [rdx], al
0x14000858f  inc     rdx
0x140008592  mov     rax, [rsp+58h+var_20]
0x140008597  mov     rcx, [rax+0F8h]
0x14000859e  mov     rax, [rcx]
0x1400085a1  mov     cl, [rax]
0x1400085a3  mov     [rdx], cl
0x1400085a5  xor     ecx, ecx
0x1400085a7  lea     r8, aE000
0x1400085ae  cmp     [rsp+58h+arg_30], cl
0x1400085b5  setz    cl
0x1400085b8  add     rbx, rdx
0x1400085bb  add     rbx, rcx
0x1400085be  sub     rdi, rbx
0x1400085c1  mov     rcx, rbx; Destination
0x1400085c4  cmp     rbp, 0FFFFFFFFFFFFFFFFh
0x1400085c8  lea     rdx, [rdi+rbp]
0x1400085cc  cmovz   rdx, rbp; SizeInBytes
0x1400085d0  call    strcpy_s
0x1400085d5  test    eax, eax
0x1400085d7  jnz     loc_140008681
0x1400085dd  lea     rcx, [rbx+2]
0x1400085e1  test    r15b, r15b
0x1400085e4  jz      short loc_1400085E9
0x1400085e6  mov     byte ptr [rbx], 45h ; 'E'
0x1400085e9  mov     rax, [rsi+8]
0x1400085ed  cmp     byte ptr [rax], 30h ; '0'
0x1400085f0  jz      short loc_140008649
0x1400085f2  mov     r8d, [rsi+4]
0x1400085f6  sub     r8d, 1
0x1400085fa  jns     short loc_140008603
0x1400085fc  neg     r8d
0x1400085ff  mov     byte ptr [rbx+1], 2Dh ; '-'
0x140008603  cmp     r8d, 64h ; 'd'
0x140008607  jl      short loc_140008624
0x140008609  mov     eax, 51EB851Fh
0x14000860e  imul    r8d
0x140008611  sar     edx, 5
0x140008614  mov     eax, edx
0x140008616  shr     eax, 1Fh
0x140008619  add     edx, eax
0x14000861b  add     [rbx+2], dl
0x14000861e  imul    eax, edx, -64h
0x140008621  add     r8d, eax
0x140008624  cmp     r8d, 0Ah
0x140008628  jl      short loc_140008645
0x14000862a  mov     eax, 66666667h
0x14000862f  imul    r8d
0x140008632  sar     edx, 2
0x140008635  mov     eax, edx
0x140008637  shr     eax, 1Fh
0x14000863a  add     edx, eax
0x14000863c  add     [rbx+3], dl
0x14000863f  imul    eax, edx, -0Ah
0x140008642  add     r8d, eax
0x140008645  add     [rbx+4], r8b
0x140008649  cmp     [rsp+58h+arg_20], 2
0x140008651  jnz     short loc_140008667
0x140008653  cmp     byte ptr [rcx], 30h ; '0'
0x140008656  jnz     short loc_140008667
0x140008658  lea     rdx, [rcx+1]
0x14000865c  mov     r8d, 3
0x140008662  call    sub_1400036D0
0x140008667  cmp     [rsp+58h+var_10], 0
0x14000866c  jz      short loc_14000867A
0x14000866e  mov     rax, [rsp+58h+var_28]
0x140008673  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x14000867a  xor     eax, eax
0x14000867c  jmp     loc_140008506
0x140008681  and     [rsp+58h+var_38], 0
0x140008687  xor     r9d, r9d; LineNo
0x14000868a  xor     r8d, r8d; FileName
0x14000868d  xor     edx, edx; FunctionName
0x14000868f  xor     ecx, ecx; Expression
0x140008691  call    _invoke_watson

// ===== ?fp_format_f_internal@@YAHQEAD_KHQEAU_strflt@@_NQEAU__crt_locale_pointers@@@Z @ 0x140008698 =====

0x140008698  mov     rax, rsp
0x14000869b  mov     [rax+8], rbx
0x14000869f  mov     [rax+10h], rbp
0x1400086a3  mov     [rax+18h], rsi
0x1400086a7  mov     [rax+20h], rdi
0x1400086ab  push    r14
0x1400086ad  sub     rsp, 40h
0x1400086b1  mov     rdx, [rsp+48h+arg_28]; struct __crt_locale_pointers *
0x1400086b6  mov     rbx, rcx
0x1400086b9  lea     rcx, [rax-28h]; this
0x1400086bd  mov     r14, r9
0x1400086c0  mov     edi, r8d
0x1400086c3  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x1400086c8  mov     ecx, [r14+4]
0x1400086cc  dec     ecx
0x1400086ce  cmp     [rsp+48h+arg_20], 0
0x1400086d3  jz      short loc_1400086EE
0x1400086d5  cmp     ecx, edi
0x1400086d7  jnz     short loc_1400086EE
0x1400086d9  xor     eax, eax
0x1400086db  movsxd  rcx, ecx
0x1400086de  cmp     dword ptr [r14], 2Dh ; '-'
0x1400086e2  setz    al
0x1400086e5  add     rax, rbx
0x1400086e8  mov     word ptr [rcx+rax], 30h ; '0'
0x1400086ee  cmp     dword ptr [r14], 2Dh ; '-'
0x1400086f2  jnz     short loc_1400086FA
0x1400086f4  mov     byte ptr [rbx], 2Dh ; '-'
0x1400086f7  inc     rbx
0x1400086fa  or      rsi, 0FFFFFFFFFFFFFFFFh
0x1400086fe  cmp     dword ptr [r14+4], 0
0x140008703  jg      short loc_140008729
0x140008705  mov     r8, rsi
0x140008708  inc     r8
0x14000870b  cmp     byte ptr [rbx+r8], 0
0x140008710  jnz     short loc_140008708
0x140008712  inc     r8
0x140008715  lea     rcx, [rbx+1]
0x140008719  mov     rdx, rbx
0x14000871c  call    sub_1400036D0
0x140008721  mov     byte ptr [rbx], 30h ; '0'
0x140008724  inc     rbx
0x140008727  jmp     short loc_140008730
0x140008729  movsxd  rax, dword ptr [r14+4]
0x14000872d  add     rbx, rax
0x140008730  test    edi, edi
0x140008732  jle     short loc_1400087B0
0x140008734  lea     rbp, [rbx+1]
0x140008738  mov     r8, rsi
0x14000873b  inc     r8
0x14000873e  cmp     byte ptr [rbx+r8], 0
0x140008743  jnz     short loc_14000873B
0x140008745  inc     r8
0x140008748  mov     rdx, rbx
0x14000874b  mov     rcx, rbp
0x14000874e  call    sub_1400036D0
0x140008753  mov     rax, [rsp+48h+var_20]
0x140008758  mov     rcx, [rax+0F8h]
0x14000875f  mov     rax, [rcx]
0x140008762  mov     cl, [rax]
0x140008764  mov     [rbx], cl
0x140008766  mov     ecx, [r14+4]
0x14000876a  test    ecx, ecx
0x14000876c  jns     short loc_1400087B0
0x14000876e  cmp     [rsp+48h+arg_20], 0
0x140008773  jnz     short loc_14000877D
0x140008775  mov     eax, ecx
0x140008777  neg     eax
0x140008779  cmp     eax, edi
0x14000877b  jge     short loc_140008781
0x14000877d  mov     edi, ecx
0x14000877f  neg     edi
0x140008781  test    edi, edi
0x140008783  jz      short loc_1400087A0
0x140008785  inc     rsi
0x140008788  cmp     byte ptr [rsi+rbp], 0
0x14000878c  jnz     short loc_140008785
0x14000878e  movsxd  rcx, edi
0x140008791  lea     r8, [rsi+1]
0x140008795  add     rcx, rbp
0x140008798  mov     rdx, rbp
0x14000879b  call    sub_1400036D0
0x1400087a0  movsxd  r8, edi
0x1400087a3  mov     edx, 30h ; '0'
0x1400087a8  mov     rcx, rbp
0x1400087ab  call    sub_140002F60
0x1400087b0  cmp     [rsp+48h+var_10], 0
0x1400087b5  jz      short loc_1400087C3
0x1400087b7  mov     rax, [rsp+48h+var_28]
0x1400087bc  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x1400087c3  mov     rbx, [rsp+48h+arg_0]
0x1400087c8  xor     eax, eax
0x1400087ca  mov     rbp, [rsp+48h+arg_8]
0x1400087cf  mov     rsi, [rsp+48h+arg_10]
0x1400087d4  mov     rdi, [rsp+48h+arg_18]
0x1400087d9  add     rsp, 40h
0x1400087dd  pop     r14
0x1400087df  retn

// ===== ?fp_format_g@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z @ 0x1400087e0 =====

0x1400087e0  mov     r11, rsp
0x1400087e3  mov     [r11+8], rbx
0x1400087e7  mov     [r11+10h], rbp
0x1400087eb  mov     [r11+18h], rsi
0x1400087ef  push    r14
0x1400087f1  sub     rsp, 50h
0x1400087f5  mov     rcx, [rcx]
0x1400087f8  xor     eax, eax
0x1400087fa  mov     [r11-18h], rax
0x1400087fe  mov     rbp, r8
0x140008801  mov     [r11-10h], rax
0x140008805  lea     r8, [r11-18h]
0x140008809  mov     rax, [rsp+58h+arg_20]
0x140008811  mov     rsi, rdx
0x140008814  mov     edx, [rsp+58h+arg_28]
0x14000881b  mov     [r11-38h], rax
0x14000881f  call    __acrt_fltout
0x140008824  mov     r14d, [rsp+58h+var_14]
0x140008829  lea     r9, [rsp+58h+var_18]
0x14000882e  mov     r8d, [rsp+58h+arg_28]
0x140008836  xor     ecx, ecx
0x140008838  cmp     [rsp+58h+var_18], 2Dh ; '-'
0x14000883d  mov     rdx, rbp
0x140008840  setz    cl
0x140008843  dec     r14d
0x140008846  sub     rdx, rcx
0x140008849  cmp     rbp, 0FFFFFFFFFFFFFFFFh
0x14000884d  lea     rbx, [rcx+rsi]
0x140008851  cmovz   rdx, rbp
0x140008855  mov     rcx, rbx
0x140008858  call    __acrt_fp_strflt_to_string
0x14000885d  test    eax, eax
0x14000885f  jz      short loc_140008869
0x140008861  mov     byte ptr [rsi], 0
0x140008864  jmp     loc_140008901
0x140008869  mov     eax, [rsp+58h+var_14]
0x14000886d  dec     eax
0x14000886f  cmp     r14d, eax
0x140008872  setl    cl
0x140008875  cmp     eax, 0FFFFFFFCh
0x140008878  jl      short loc_1400088BF
0x14000887a  cmp     eax, [rsp+58h+arg_28]
0x140008881  jge     short loc_1400088BF
0x140008883  test    cl, cl
0x140008885  jz      short loc_140008893
0x140008887  mov     al, [rbx]
0x140008889  inc     rbx
0x14000888c  test    al, al
0x14000888e  jnz     short loc_140008887
0x140008890  mov     [rbx-2], al
0x140008893  mov     rax, [rsp+58h+arg_40]
0x14000889b  lea     r9, [rsp+58h+var_18]; struct _strflt *
0x1400088a0  mov     r8d, [rsp+58h+arg_28]; int
0x1400088a8  mov     rdx, rbp; unsigned __int64
0x1400088ab  mov     [rsp+58h+var_30], rax; struct __crt_locale_pointers *
0x1400088b0  mov     rcx, rsi; char *
0x1400088b3  mov     [rsp+58h+var_38], 1; bool
0x1400088b8  call    ?fp_format_f_internal@@YAHQEAD_KHQEAU_strflt@@_NQEAU__crt_locale_pointers@@@Z
0x1400088bd  jmp     short loc_140008901
0x1400088bf  mov     rax, [rsp+58h+arg_40]
0x1400088c7  mov     rdx, rbp; unsigned __int64
0x1400088ca  mov     r9b, [rsp+58h+arg_30]; bool
0x1400088d2  mov     rcx, rsi; char *
0x1400088d5  mov     r8d, [rsp+58h+arg_28]; int
0x1400088dd  mov     [rsp+58h+var_20], rax; struct __crt_locale_pointers *
0x1400088e2  lea     rax, [rsp+58h+var_18]
0x1400088e7  mov     [rsp+58h+var_28], 1; bool
0x1400088ec  mov     [rsp+58h+var_30], rax; struct _strflt *
0x1400088f1  mov     eax, [rsp+58h+arg_38]
0x1400088f8  mov     dword ptr [rsp+58h+var_38], eax; unsigned int
0x1400088fc  call    ?fp_format_e_internal@@YAHQEAD_KH_NIQEAU_strflt@@2QEAU__crt_locale_pointers@@@Z
0x140008901  mov     rbx, [rsp+58h+arg_0]
0x140008906  mov     rbp, [rsp+58h+arg_8]
0x14000890b  mov     rsi, [rsp+58h+arg_10]
0x140008910  add     rsp, 50h
0x140008914  pop     r14
0x140008916  retn

// ===== ?fp_format_nan_or_infinity@@YAHW4__acrt_fp_class@@_NPEAD_K1@Z @ 0x140008918 =====

0x140008918  push    rbp
0x14000891a  lea     rbp, [rsp-4Fh]
0x14000891f  sub     rsp, 0C0h
0x140008926  mov     rax, cs:__security_cookie
0x14000892d  xor     rax, rsp
0x140008930  mov     [rbp+4Fh+var_10], rax
0x140008934  mov     r10, r9
0x140008937  movzx   eax, dl
0x14000893a  add     rax, 4
0x14000893e  mov     r9, r8
0x140008941  cmp     r10, rax
0x140008944  jnb     short loc_140008964
0x140008946  mov     byte ptr [r8], 0
0x14000894a  mov     eax, 0Ch
0x14000894f  mov     rcx, [rbp+4Fh+var_10]
0x140008953  xor     rcx, rsp; StackCookie
0x140008956  call    __security_check_cookie
0x14000895b  add     rsp, 0C0h
0x140008962  pop     rbp
0x140008963  retn
0x140008964  test    dl, dl
0x140008966  jz      short loc_140008976
0x140008968  inc     r9
0x14000896b  mov     byte ptr [r8], 2Dh ; '-'
0x14000896f  dec     r10
0x140008972  mov     byte ptr [r9], 0
0x140008976  neg     [rbp+4Fh+arg_20]
0x140008979  lea     rdx, unk_140012300
0x140008980  lea     r8, unk_140012304
0x140008987  mov     [rbp+4Fh+var_70], rdx
0x14000898b  lea     rax, unk_1400122F8
0x140008992  mov     [rbp+4Fh+var_68], rdx
0x140008996  mov     [rbp+4Fh+Source], rax
0x14000899a  mov     [rbp+4Fh+var_88], rax
0x14000899e  lea     rax, unk_1400122FC
0x1400089a5  mov     [rbp+4Fh+var_80], rax
0x1400089a9  mov     [rbp+4Fh+var_78], rax
0x1400089ad  lea     rax, aNanSnan
0x1400089b4  mov     [rbp+4Fh+var_50], rax
0x1400089b8  lea     rax, aNanSnan_0
0x1400089bf  mov     [rbp+4Fh+var_40], rax
0x1400089c3  lea     rax, aNanInd
0x1400089ca  mov     [rbp+4Fh+var_30], rax
0x1400089ce  lea     rax, aNanInd_0
0x1400089d5  mov     [rbp+4Fh+var_20], rax
0x1400089d9  mov     [rbp+4Fh+var_48], rdx
0x1400089dd  mov     [rbp+4Fh+var_28], rdx
0x1400089e1  lea     edx, [rcx-1]
0x1400089e4  sbb     ecx, ecx
0x1400089e6  mov     [rbp+4Fh+var_60], r8
0x1400089ea  shl     rdx, 2
0x1400089ee  not     ecx
0x1400089f0  and     ecx, 2
0x1400089f3  mov     [rbp+4Fh+var_58], r8
0x1400089f7  mov     eax, ecx
0x1400089f9  add     rax, rdx
0x1400089fc  mov     [rbp+4Fh+var_38], r8
0x140008a00  mov     [rbp+4Fh+var_18], r8
0x140008a04  mov     r8, [rbp+rax*8+4Fh+Source]
0x140008a09  or      rax, 0FFFFFFFFFFFFFFFFh
0x140008a0d  inc     rax
0x140008a10  cmp     byte ptr [r8+rax], 0
0x140008a15  jnz     short loc_140008A0D
0x140008a17  cmp     r10, rax
0x140008a1a  setnbe  al
0x140008a1d  xor     r8d, r8d
0x140008a20  test    al, al
0x140008a22  setz    r8b
0x140008a26  add     r8d, ecx
0x140008a29  mov     rcx, r9; Destination
0x140008a2c  add     r8, rdx
0x140008a2f  mov     rdx, r10; SizeInBytes
0x140008a32  mov     r8, [rbp+r8*8+4Fh+Source]; Source
0x140008a37  call    strcpy_s
0x140008a3c  test    eax, eax
0x140008a3e  jz      loc_14000894F
0x140008a44  and     [rsp+0C0h+var_A0], 0
0x140008a4a  xor     r9d, r9d; LineNo
0x140008a4d  xor     r8d, r8d; FileName
0x140008a50  xor     edx, edx; FunctionName
0x140008a52  xor     ecx, ecx; Expression
0x140008a54  call    _invoke_watson

// ===== __acrt_fp_format @ 0x140008a5c =====

0x140008a5c  mov     [rsp+arg_0], rbx
0x140008a61  mov     [rsp+arg_8], rbp
0x140008a66  mov     [rsp+arg_10], rsi
0x140008a6b  push    rdi
0x140008a6c  push    r12
0x140008a6e  push    r13
0x140008a70  push    r14
0x140008a72  push    r15
0x140008a74  sub     rsp, 60h
0x140008a78  mov     r13, r9
0x140008a7b  mov     rbp, r8
0x140008a7e  mov     rsi, rdx
0x140008a81  mov     r15, rcx
0x140008a84  test    rdx, rdx
0x140008a87  jnz     short loc_140008AA1
0x140008a89  call    _errno
0x140008a8e  mov     ebx, 16h
0x140008a93  mov     [rax], ebx
0x140008a95  call    _invalid_parameter_noinfo
0x140008a9a  mov     eax, ebx
0x140008a9c  jmp     loc_140008C7F
0x140008aa1  test    r8, r8
0x140008aa4  jz      short loc_140008A89
0x140008aa6  test    r9, r9
0x140008aa9  jz      short loc_140008A89
0x140008aab  mov     r12, [rsp+88h+arg_20]
0x140008ab3  test    r12, r12
0x140008ab6  jz      short loc_140008A89
0x140008ab8  mov     ebx, [rsp+88h+arg_28]
0x140008abf  cmp     ebx, 41h ; 'A'
0x140008ac2  jz      short loc_140008AD1
0x140008ac4  lea     eax, [rbx-45h]
0x140008ac7  cmp     eax, 2
0x140008aca  jbe     short loc_140008AD1
0x140008acc  xor     r14b, r14b
0x140008acf  jmp     short loc_140008AD4
0x140008ad1  mov     r14b, 1
0x140008ad4  mov     rdi, [rsp+88h+arg_38]
0x140008adc  test    dil, 8
0x140008ae0  jnz     short loc_140008B0C
0x140008ae2  call    ?__acrt_fp_classify@@YA?AW4__acrt_fp_class@@AEBN@Z
0x140008ae7  test    eax, eax
0x140008ae9  jz      short loc_140008B0C
0x140008aeb  mov     rdx, [r15]
0x140008aee  mov     r9, rbp
0x140008af1  shr     rdx, 3Fh
0x140008af5  mov     r8, rsi
0x140008af8  and     dl, 1
0x140008afb  mov     [rsp+88h+var_68], r14b
0x140008b00  mov     ecx, eax
0x140008b02  call    ?fp_format_nan_or_infinity@@YAHW4__acrt_fp_class@@_NPEAD_K1@Z
0x140008b07  jmp     loc_140008C7F
0x140008b0c  shr     rdi, 4
0x140008b10  and     edi, 1
0x140008b13  or      edi, 2
0x140008b16  sub     ebx, 41h ; 'A'
0x140008b19  jz      loc_140008C48
0x140008b1f  sub     ebx, 4
0x140008b22  jz      loc_140008C0F
0x140008b28  sub     ebx, 1
0x140008b2b  jz      short loc_140008B85
0x140008b2d  sub     ebx, 1
0x140008b30  jz      short loc_140008B49
0x140008b32  sub     ebx, 1Ah
0x140008b35  jz      loc_140008C48
0x140008b3b  sub     ebx, 4
0x140008b3e  jz      loc_140008C0F
0x140008b44  cmp     ebx, 1
0x140008b47  jz      short loc_140008B85
0x140008b49  mov     rax, [rsp+88h+arg_40]
0x140008b51  mov     r9, r13; char *
0x140008b54  mov     [rsp+88h+var_48], rax; struct __crt_locale_pointers *
0x140008b59  mov     r8, rbp; unsigned __int64
0x140008b5c  mov     eax, [rsp+88h+arg_30]
0x140008b63  mov     rdx, rsi; char *
0x140008b66  mov     [rsp+88h+var_50], edi; unsigned int
0x140008b6a  mov     rcx, r15; double *
0x140008b6d  mov     [rsp+88h+var_58], r14b; bool
0x140008b72  mov     dword ptr [rsp+88h+var_60], eax; int
0x140008b76  mov     qword ptr [rsp+88h+var_68], r12; unsigned __int64
0x140008b7b  call    ?fp_format_g@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z
0x140008b80  jmp     loc_140008C7F
0x140008b85  mov     ebx, [rsp+88h+arg_30]
0x140008b8c  lea     r8, [rsp+88h+var_38]
0x140008b91  mov     rcx, [r15]
0x140008b94  xor     eax, eax
0x140008b96  mov     edx, ebx
0x140008b98  mov     [rsp+88h+var_38], rax
0x140008b9d  mov     r9, r13
0x140008ba0  mov     [rsp+88h+var_30], rax
0x140008ba5  mov     qword ptr [rsp+88h+var_68], r12
0x140008baa  call    __acrt_fltout
0x140008baf  mov     r8d, dword ptr [rsp+88h+var_38+4]
0x140008bb4  lea     r9, [rsp+88h+var_38]
0x140008bb9  xor     ecx, ecx
0x140008bbb  mov     rdx, rbp
0x140008bbe  cmp     dword ptr [rsp+88h+var_38], 2Dh ; '-'
0x140008bc3  setz    cl
0x140008bc6  add     r8d, ebx
0x140008bc9  sub     rdx, rcx
0x140008bcc  cmp     rbp, 0FFFFFFFFFFFFFFFFh
0x140008bd0  cmovz   rdx, rbp
0x140008bd4  add     rcx, rsi
0x140008bd7  call    __acrt_fp_strflt_to_string
0x140008bdc  test    eax, eax
0x140008bde  jz      short loc_140008BE8
0x140008be0  mov     byte ptr [rsi], 0
0x140008be3  jmp     loc_140008C7F
0x140008be8  mov     rax, [rsp+88h+arg_40]
0x140008bf0  lea     r9, [rsp+88h+var_38]; struct _strflt *
0x140008bf5  mov     [rsp+88h+var_60], rax; struct __crt_locale_pointers *
0x140008bfa  mov     r8d, ebx; int
0x140008bfd  mov     rdx, rbp; unsigned __int64
0x140008c00  mov     [rsp+88h+var_68], 0; bool
0x140008c05  mov     rcx, rsi; char *
0x140008c08  call    ?fp_format_f_internal@@YAHQEAD_KHQEAU_strflt@@_NQEAU__crt_locale_pointers@@@Z
0x140008c0d  jmp     short loc_140008C7F
0x140008c0f  mov     rax, [rsp+88h+arg_40]
0x140008c17  mov     r9, r13; char *
0x140008c1a  mov     [rsp+88h+var_48], rax; struct __crt_locale_pointers *
0x140008c1f  mov     r8, rbp; unsigned __int64
0x140008c22  mov     eax, [rsp+88h+arg_30]
0x140008c29  mov     rdx, rsi; char *
0x140008c2c  mov     [rsp+88h+var_50], edi; unsigned int
0x140008c30  mov     rcx, r15; double *
0x140008c33  mov     [rsp+88h+var_58], r14b; bool
0x140008c38  mov     dword ptr [rsp+88h+var_60], eax; int
0x140008c3c  mov     qword ptr [rsp+88h+var_68], r12; unsigned __int64
0x140008c41  call    ?fp_format_e@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z
0x140008c46  jmp     short loc_140008C7F
0x140008c48  mov     rax, [rsp+88h+arg_40]
0x140008c50  mov     r9, r13; char *
0x140008c53  mov     [rsp+88h+var_48], rax; struct __crt_locale_pointers *
0x140008c58  mov     r8, rbp; unsigned __int64
0x140008c5b  mov     eax, [rsp+88h+arg_30]
0x140008c62  mov     rdx, rsi; char *
0x140008c65  mov     [rsp+88h+var_50], edi; unsigned int
0x140008c69  mov     rcx, r15; double *
0x140008c6c  mov     [rsp+88h+var_58], r14b; bool
0x140008c71  mov     dword ptr [rsp+88h+var_60], eax; int
0x140008c75  mov     qword ptr [rsp+88h+var_68], r12; unsigned __int64
0x140008c7a  call    ?fp_format_a@@YAHQEBNPEAD_KQEAD2H_NIQEAU__crt_locale_pointers@@@Z
0x140008c7f  lea     r11, [rsp+88h+var_28]
0x140008c84  mov     rbx, [r11+30h]
0x140008c88  mov     rbp, [r11+38h]
0x140008c8c  mov     rsi, [r11+40h]
0x140008c90  mov     rsp, r11
0x140008c93  pop     r15
0x140008c95  pop     r14
0x140008c97  pop     r13
0x140008c99  pop     r12
0x140008c9b  pop     rdi
0x140008c9c  retn

// ===== _fileno @ 0x140008ca0 =====

0x140008ca0  sub     rsp, 28h
0x140008ca4  test    rcx, rcx
0x140008ca7  jnz     short loc_140008CBE
0x140008ca9  call    _errno
0x140008cae  mov     dword ptr [rax], 16h
0x140008cb4  call    _invalid_parameter_noinfo
0x140008cb9  or      eax, 0FFFFFFFFh
0x140008cbc  jmp     short loc_140008CC1
0x140008cbe  mov     eax, [rcx+18h]
0x140008cc1  add     rsp, 28h
0x140008cc5  retn

// ===== _get_printf_count_output @ 0x140008cc8 =====

0x140008cc8  mov     rcx, cs:__security_cookie
0x140008ccf  xor     eax, eax
0x140008cd1  or      rcx, 1
0x140008cd5  cmp     cs:qword_14001D328, rcx
0x140008cdc  setz    al
0x140008cdf  retn

// ===== ?initialize_inherited_file_handles_nolock@@YAXXZ @ 0x140008ce0 =====

0x140008ce0  mov     rax, rsp
0x140008ce3  mov     [rax+8], rbx
0x140008ce7  mov     [rax+10h], rbp
0x140008ceb  mov     [rax+18h], rsi
0x140008cef  mov     [rax+20h], rdi
0x140008cf3  push    r14
0x140008cf5  sub     rsp, 90h
0x140008cfc  lea     rcx, [rax-78h]; lpStartupInfo
0x140008d00  call    cs:GetStartupInfoW; KERNEL32
0x140008d06  xor     r14d, r14d
0x140008d09  cmp     [rsp+98h+var_36], r14w
0x140008d0f  jz      loc_140008DAD
0x140008d15  mov     rax, [rsp+98h+var_30]
0x140008d1a  test    rax, rax
0x140008d1d  jz      loc_140008DAD
0x140008d23  movsxd  rbx, dword ptr [rax]
0x140008d26  lea     rsi, [rax+4]
0x140008d2a  mov     edi, 2000h
0x140008d2f  add     rbx, rsi
0x140008d32  cmp     [rax], edi
0x140008d34  cmovl   edi, [rax]
0x140008d37  mov     ecx, edi
0x140008d39  call    __acrt_lowio_ensure_fh_exists
0x140008d3e  cmp     edi, cs:dword_14001D750
0x140008d44  cmovg   edi, cs:dword_14001D750
0x140008d4b  test    edi, edi
0x140008d4d  jz      short loc_140008DAD
0x140008d4f  mov     ebp, r14d
0x140008d52  cmp     qword ptr [rbx], 0FFFFFFFFFFFFFFFFh
0x140008d56  jz      short loc_140008D9D
0x140008d58  cmp     qword ptr [rbx], 0FFFFFFFFFFFFFFFEh
0x140008d5c  jz      short loc_140008D9D
0x140008d5e  test    byte ptr [rsi], 1
0x140008d61  jz      short loc_140008D9D
0x140008d63  test    byte ptr [rsi], 8
0x140008d66  jnz     short loc_140008D75
0x140008d68  mov     rcx, [rbx]; hFile
0x140008d6b  call    cs:GetFileType; KERNEL32
0x140008d71  test    eax, eax
0x140008d73  jz      short loc_140008D9D
0x140008d75  mov     rcx, rbp
0x140008d78  lea     rdx, qword_14001D350
0x140008d7f  and     ecx, 3Fh
0x140008d82  mov     rax, rbp
0x140008d85  sar     rax, 6
0x140008d89  shl     rcx, 6
0x140008d8d  add     rcx, [rdx+rax*8]
0x140008d91  mov     rax, [rbx]
0x140008d94  mov     [rcx+28h], rax
0x140008d98  mov     al, [rsi]
0x140008d9a  mov     [rcx+38h], al
0x140008d9d  inc     rbp
0x140008da0  inc     rsi
0x140008da3  add     rbx, 8
0x140008da7  sub     rdi, 1
0x140008dab  jnz     short loc_140008D52
0x140008dad  lea     r11, [rsp+98h+var_8]
0x140008db5  mov     rbx, [r11+10h]
0x140008db9  mov     rbp, [r11+18h]
0x140008dbd  mov     rsi, [r11+20h]
0x140008dc1  mov     rdi, [r11+28h]
0x140008dc5  mov     rsp, r11
0x140008dc8  pop     r14
0x140008dca  retn

// ===== ?initialize_stdio_handles_nolock@@YAXXZ @ 0x140008dcc =====

0x140008dcc  mov     [rsp+arg_0], rbx
0x140008dd1  mov     [rsp+arg_8], rsi
0x140008dd6  mov     [rsp+arg_10], rdi
0x140008ddb  push    r14
0x140008ddd  sub     rsp, 20h
0x140008de1  xor     edi, edi
0x140008de3  xor     r14d, r14d
0x140008de6  movsxd  rbx, edi
0x140008de9  lea     rcx, qword_14001D350
0x140008df0  mov     rax, rbx
0x140008df3  and     ebx, 3Fh
0x140008df6  sar     rax, 6
0x140008dfa  shl     rbx, 6
0x140008dfe  add     rbx, [rcx+rax*8]
0x140008e02  mov     rax, [rbx+28h]
0x140008e06  add     rax, 2
0x140008e0a  cmp     rax, 1
0x140008e0e  jbe     short loc_140008E19
0x140008e10  or      byte ptr [rbx+38h], 80h
0x140008e14  jmp     loc_140008EA2
0x140008e19  mov     byte ptr [rbx+38h], 81h
0x140008e1d  mov     ecx, edi
0x140008e1f  test    edi, edi
0x140008e21  jz      short loc_140008E39
0x140008e23  sub     ecx, 1
0x140008e26  jz      short loc_140008E32
0x140008e28  cmp     ecx, 1
0x140008e2b  mov     ecx, 0FFFFFFF4h
0x140008e30  jmp     short loc_140008E3E
0x140008e32  mov     ecx, 0FFFFFFF5h
0x140008e37  jmp     short loc_140008E3E
0x140008e39  mov     ecx, 0FFFFFFF6h; nStdHandle
0x140008e3e  call    cs:GetStdHandle; KERNEL32
0x140008e44  mov     rsi, rax
0x140008e47  lea     rcx, [rax+1]
0x140008e4b  cmp     rcx, 1
0x140008e4f  jbe     short loc_140008E5C
0x140008e51  mov     rcx, rax; hFile
0x140008e54  call    cs:GetFileType; KERNEL32
0x140008e5a  jmp     short loc_140008E5E
0x140008e5c  xor     eax, eax
0x140008e5e  test    eax, eax
0x140008e60  jz      short loc_140008E7F
0x140008e62  movzx   ecx, al
0x140008e65  mov     [rbx+28h], rsi
0x140008e69  cmp     ecx, 2
0x140008e6c  jnz     short loc_140008E74
0x140008e6e  or      byte ptr [rbx+38h], 40h
0x140008e72  jmp     short loc_140008EA2
0x140008e74  cmp     ecx, 3
0x140008e77  jnz     short loc_140008EA2
0x140008e79  or      byte ptr [rbx+38h], 8
0x140008e7d  jmp     short loc_140008EA2
0x140008e7f  or      byte ptr [rbx+38h], 40h
0x140008e83  mov     qword ptr [rbx+28h], 0FFFFFFFFFFFFFFFEh
0x140008e8b  mov     rax, cs:Block
0x140008e92  test    rax, rax
0x140008e95  jz      short loc_140008EA2
0x140008e97  mov     rax, [r14+rax]
0x140008e9b  mov     dword ptr [rax+18h], 0FFFFFFFEh
0x140008ea2  inc     edi
0x140008ea4  add     r14, 8
0x140008ea8  cmp     edi, 3
0x140008eab  jnz     loc_140008DE6
0x140008eb1  mov     rbx, [rsp+28h+arg_0]
0x140008eb6  mov     rsi, [rsp+28h+arg_8]
0x140008ebb  mov     rdi, [rsp+28h+arg_10]
0x140008ec0  add     rsp, 20h
0x140008ec4  pop     r14
0x140008ec6  retn

// ===== __acrt_initialize_lowio @ 0x140008ec8 =====

0x140008ec8  push    rbx
0x140008eca  sub     rsp, 20h
0x140008ece  mov     ecx, 7
0x140008ed3  call    sub_14000AB5C
0x140008ed8  xor     ebx, ebx
0x140008eda  xor     ecx, ecx
0x140008edc  call    __acrt_lowio_ensure_fh_exists
0x140008ee1  test    eax, eax
0x140008ee3  jnz     short loc_140008EF1
0x140008ee5  call    ?initialize_inherited_file_handles_nolock@@YAXXZ
0x140008eea  call    ?initialize_stdio_handles_nolock@@YAXXZ
0x140008eef  mov     bl, 1
0x140008ef1  mov     ecx, 7
0x140008ef6  call    sub_14000ABB0
0x140008efb  mov     al, bl
0x140008efd  add     rsp, 20h
0x140008f01  pop     rbx
0x140008f02  retn
0x140010a72  push    rbp; Microsoft VisualC 64bit universal runtime
0x140010a74  sub     rsp, 20h
0x140010a78  mov     rbp, rdx
0x140010a7b  mov     ecx, 7
0x140010a80  add     rsp, 20h
0x140010a84  pop     rbp
0x140010a85  jmp     sub_14000ABB0

// ===== __acrt_uninitialize_lowio @ 0x140008f04 =====

0x140008f04  mov     [rsp+arg_0], rbx
0x140008f09  push    rdi
0x140008f0a  sub     rsp, 20h
0x140008f0e  xor     ebx, ebx
0x140008f10  lea     rdi, qword_14001D350
0x140008f17  mov     rcx, [rbx+rdi]; Block
0x140008f1b  test    rcx, rcx
0x140008f1e  jz      short loc_140008F2A
0x140008f20  call    __acrt_lowio_destroy_handle_array
0x140008f25  and     qword ptr [rbx+rdi], 0
0x140008f2a  add     rbx, 8
0x140008f2e  cmp     rbx, 400h
0x140008f35  jb      short loc_140008F10
0x140008f37  mov     al, 1
0x140008f39  mov     rbx, [rsp+28h+arg_0]
0x140008f3e  add     rsp, 20h
0x140008f42  pop     rdi
0x140008f43  retn

// ===== _calloc_base @ 0x140008f44 =====

0x140008f44  push    rbx
0x140008f46  sub     rsp, 20h
0x140008f4a  mov     r8, rdx
0x140008f4d  mov     rbx, rcx
0x140008f50  test    rcx, rcx
0x140008f53  jz      short loc_140008F63
0x140008f55  xor     edx, edx
0x140008f57  lea     rax, [rdx-20h]
0x140008f5b  div     rbx
0x140008f5e  cmp     rax, r8
0x140008f61  jb      short loc_140008FA6
0x140008f63  imul    rbx, r8
0x140008f67  mov     eax, 1
0x140008f6c  test    rbx, rbx
0x140008f6f  cmovz   rbx, rax
0x140008f73  jmp     short loc_140008F8A
0x140008f75  call    sub_140006248
0x140008f7a  test    eax, eax
0x140008f7c  jz      short loc_140008FA6
0x140008f7e  mov     rcx, rbx; Size
0x140008f81  call    _callnewh
0x140008f86  test    eax, eax
0x140008f88  jz      short loc_140008FA6
0x140008f8a  mov     rcx, cs:hHeap; hHeap
0x140008f91  mov     r8, rbx; dwBytes
0x140008f94  mov     edx, 8; dwFlags
0x140008f99  call    cs:HeapAlloc; KERNEL32
0x140008f9f  test    rax, rax
0x140008fa2  jz      short loc_140008F75
0x140008fa4  jmp     short loc_140008FB3
0x140008fa6  call    _errno
0x140008fab  mov     dword ptr [rax], 0Ch
0x140008fb1  xor     eax, eax
0x140008fb3  add     rsp, 20h
0x140008fb7  pop     rbx
0x140008fb8  retn

// ===== ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z @ 0x140008fbc =====

0x140008fbc  mov     [rsp+arg_0], rbx
0x140008fc1  mov     [rsp+arg_8], rbp
0x140008fc6  mov     [rsp+arg_10], rsi
0x140008fcb  push    rdi
0x140008fcc  push    r12
0x140008fce  push    r13
0x140008fd0  push    r14
0x140008fd2  push    r15
0x140008fd4  sub     rsp, 20h
0x140008fd8  mov     r14d, ecx
0x140008fdb  lea     r15, cs:140000000h
0x140008fe2  mov     r12, r9
0x140008fe5  mov     rbp, r8
0x140008fe8  mov     r13, rdx
0x140008feb  mov     rcx, rva qword_14001D800[r15+r14*8]
0x140008ff3  mov     r10, cs:__security_cookie
0x140008ffa  or      rdi, 0FFFFFFFFFFFFFFFFh
0x140008ffe  mov     eax, r10d
0x140009001  mov     rdx, r10
0x140009004  xor     rdx, rcx
0x140009007  and     eax, 3Fh
0x14000900a  mov     cl, al
0x14000900c  ror     rdx, cl
0x14000900f  cmp     rdx, rdi
0x140009012  jz      loc_14000913D
0x140009018  test    rdx, rdx
0x14000901b  jz      short loc_140009025
0x14000901d  mov     rax, rdx
0x140009020  jmp     loc_14000913F
0x140009025  cmp     r8, r9
0x140009028  jz      loc_1400090D1
0x14000902e  mov     esi, [rbp+0]
0x140009031  mov     rbx, rva qword_14001D760[r15+rsi*8]
0x140009039  test    rbx, rbx
0x14000903c  jz      short loc_140009045
0x14000903e  cmp     rbx, rdi
0x140009041  jz      short loc_1400090BD
0x140009043  jmp     short loc_1400090B8
0x140009045  mov     r15, ds:rva off_1400129D0[r15+rsi*8]
0x14000904d  xor     edx, edx; hFile
0x14000904f  mov     rcx, r15; lpLibFileName
0x140009052  mov     r8d, 800h; dwFlags
0x140009058  call    cs:LoadLibraryExW; KERNEL32
0x14000905e  mov     rbx, rax
0x140009061  test    rax, rax
0x140009064  jnz     short loc_140009086
0x140009066  call    cs:GetLastError; KERNEL32
0x14000906c  cmp     eax, 57h ; 'W'
0x14000906f  jnz     short loc_140009084
0x140009071  xor     r8d, r8d; dwFlags
0x140009074  xor     edx, edx; hFile
0x140009076  mov     rcx, r15; lpLibFileName
0x140009079  call    cs:LoadLibraryExW; KERNEL32
0x14000907f  mov     rbx, rax
0x140009082  jmp     short loc_140009086
0x140009084  xor     ebx, ebx
0x140009086  lea     r15, cs:140000000h
0x14000908d  test    rbx, rbx
0x140009090  jnz     short loc_14000909F
0x140009092  mov     rax, rdi
0x140009095  xchg    rax, rva qword_14001D760[r15+rsi*8]
0x14000909d  jmp     short loc_1400090BD
0x14000909f  mov     rax, rbx
0x1400090a2  xchg    rax, rva qword_14001D760[r15+rsi*8]
0x1400090aa  test    rax, rax
0x1400090ad  jz      short loc_1400090B8
0x1400090af  mov     rcx, rbx; hLibModule
0x1400090b2  call    cs:FreeLibrary; KERNEL32
0x1400090b8  test    rbx, rbx
0x1400090bb  jnz     short loc_140009112
0x1400090bd  add     rbp, 4
0x1400090c1  cmp     rbp, r12
0x1400090c4  jnz     loc_14000902E
0x1400090ca  mov     r10, cs:__security_cookie
0x1400090d1  xor     ebx, ebx
0x1400090d3  test    rbx, rbx
0x1400090d6  jz      short loc_140009122
0x1400090d8  mov     rdx, r13; lpProcName
0x1400090db  mov     rcx, rbx; hModule
0x1400090de  call    cs:GetProcAddress; KERNEL32
0x1400090e4  test    rax, rax
0x1400090e7  jz      short loc_14000911B
0x1400090e9  mov     r8, cs:__security_cookie
0x1400090f0  mov     edx, 40h ; '@'
0x1400090f5  mov     ecx, r8d
0x1400090f8  and     ecx, 3Fh
0x1400090fb  sub     edx, ecx
0x1400090fd  mov     cl, dl
0x1400090ff  mov     rdx, rax
0x140009102  ror     rdx, cl
0x140009105  xor     rdx, r8
0x140009108  xchg    rdx, rva qword_14001D800[r15+r14*8]
0x140009110  jmp     short loc_14000913F
0x140009112  mov     r10, cs:__security_cookie
0x140009119  jmp     short loc_1400090D3
0x14000911b  mov     r10, cs:__security_cookie
0x140009122  mov     eax, r10d
0x140009125  mov     ecx, 40h ; '@'
0x14000912a  and     eax, 3Fh
0x14000912d  sub     ecx, eax
0x14000912f  ror     rdi, cl
0x140009132  xor     rdi, r10
0x140009135  xchg    rdi, rva qword_14001D800[r15+r14*8]
0x14000913d  xor     eax, eax
0x14000913f  mov     rbx, [rsp+48h+arg_0]
0x140009144  mov     rbp, [rsp+48h+arg_8]
0x140009149  mov     rsi, [rsp+48h+arg_10]
0x14000914e  add     rsp, 20h
0x140009152  pop     r15
0x140009154  pop     r14
0x140009156  pop     r13
0x140009158  pop     r12
0x14000915a  pop     rdi
0x14000915b  retn

// ===== __acrt_FlsAlloc @ 0x14000915c =====

0x14000915c  mov     [rsp+arg_0], rbx
0x140009161  push    rdi
0x140009162  sub     rsp, 20h
0x140009166  mov     rdi, rcx
0x140009169  lea     r9, aFlsalloc_0
0x140009170  mov     ecx, 3
0x140009175  lea     r8, unk_140012FB0
0x14000917c  lea     rdx, aFlsalloc_0
0x140009183  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x140009188  mov     rbx, rax
0x14000918b  test    rax, rax
0x14000918e  jz      short loc_1400091A0
0x140009190  mov     rcx, rax
0x140009193  call    cs:__guard_check_icall_fptr
0x140009199  mov     rcx, rdi
0x14000919c  call    rbx
0x14000919e  jmp     short loc_1400091A6
0x1400091a0  call    cs:TlsAlloc; KERNEL32
0x1400091a6  mov     rbx, [rsp+28h+arg_0]
0x1400091ab  add     rsp, 20h
0x1400091af  pop     rdi
0x1400091b0  retn

// ===== __acrt_FlsFree @ 0x1400091b4 =====

0x1400091b4  mov     [rsp+arg_0], rbx
0x1400091b9  push    rdi
0x1400091ba  sub     rsp, 20h
0x1400091be  mov     ebx, ecx
0x1400091c0  lea     r9, aFlsfree_0
0x1400091c7  mov     ecx, 4
0x1400091cc  lea     r8, unk_140012FC8
0x1400091d3  lea     rdx, aFlsfree_0
0x1400091da  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x1400091df  mov     rdi, rax
0x1400091e2  test    rax, rax
0x1400091e5  jz      short loc_1400091F6
0x1400091e7  mov     rcx, rax
0x1400091ea  call    cs:__guard_check_icall_fptr
0x1400091f0  mov     ecx, ebx
0x1400091f2  call    rdi
0x1400091f4  jmp     short loc_1400091FE
0x1400091f6  mov     ecx, ebx; dwTlsIndex
0x1400091f8  call    cs:TlsFree; KERNEL32
0x1400091fe  mov     rbx, [rsp+28h+arg_0]
0x140009203  add     rsp, 20h
0x140009207  pop     rdi
0x140009208  retn

// ===== __vcrt_FlsFree_0 @ 0x14000920c =====

0x14000920c  mov     [rsp+arg_0], rbx
0x140009211  push    rdi
0x140009212  sub     rsp, 20h
0x140009216  mov     ebx, ecx
0x140009218  lea     r9, aFlsgetvalue
0x14000921f  mov     ecx, 5
0x140009224  lea     r8, unk_140012FD8
0x14000922b  lea     rdx, aFlsgetvalue
0x140009232  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x140009237  mov     rdi, rax
0x14000923a  test    rax, rax
0x14000923d  jz      short loc_14000924E
0x14000923f  mov     rcx, rax
0x140009242  call    cs:__guard_check_icall_fptr
0x140009248  mov     ecx, ebx
0x14000924a  call    rdi
0x14000924c  jmp     short loc_140009256
0x14000924e  mov     ecx, ebx; dwTlsIndex
0x140009250  call    cs:TlsGetValue; KERNEL32
0x140009256  mov     rbx, [rsp+28h+arg_0]
0x14000925b  add     rsp, 20h
0x14000925f  pop     rdi
0x140009260  retn

// ===== __acrt_FlsSetValue @ 0x140009264 =====

0x140009264  mov     [rsp+arg_0], rbx
0x140009269  mov     [rsp+arg_8], rsi
0x14000926e  push    rdi
0x14000926f  sub     rsp, 20h
0x140009273  mov     rbx, rdx
0x140009276  lea     r9, aFlssetvalue_0
0x14000927d  mov     edi, ecx
0x14000927f  lea     rdx, aFlssetvalue_0
0x140009286  mov     ecx, 6
0x14000928b  lea     r8, unk_140012FF0
0x140009292  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x140009297  mov     rsi, rax
0x14000929a  test    rax, rax
0x14000929d  jz      short loc_1400092B1
0x14000929f  mov     rcx, rax
0x1400092a2  call    cs:__guard_check_icall_fptr
0x1400092a8  mov     rdx, rbx
0x1400092ab  mov     ecx, edi
0x1400092ad  call    rsi
0x1400092af  jmp     short loc_1400092BC
0x1400092b1  mov     rdx, rbx; lpTlsValue
0x1400092b4  mov     ecx, edi; dwTlsIndex
0x1400092b6  call    cs:TlsSetValue; KERNEL32
0x1400092bc  mov     rbx, [rsp+28h+arg_0]
0x1400092c1  mov     rsi, [rsp+28h+arg_8]
0x1400092c6  add     rsp, 20h
0x1400092ca  pop     rdi
0x1400092cb  retn

// ===== __acrt_InitializeCriticalSectionEx @ 0x1400092cc =====

0x1400092cc  mov     [rsp+arg_0], rbx
0x1400092d1  mov     [rsp+arg_8], rbp
0x1400092d6  mov     [rsp+arg_10], rsi
0x1400092db  push    rdi
0x1400092dc  sub     rsp, 20h
0x1400092e0  mov     ebp, r8d
0x1400092e3  lea     r9, aInitializecrit_0
0x1400092ea  mov     ebx, edx
0x1400092ec  lea     r8, asc_140013028
0x1400092f3  mov     rdi, rcx
0x1400092f6  lea     rdx, aInitializecrit_0
0x1400092fd  mov     ecx, 14h
0x140009302  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x140009307  mov     rsi, rax
0x14000930a  test    rax, rax
0x14000930d  jz      short loc_140009324
0x14000930f  mov     rcx, rax
0x140009312  call    cs:__guard_check_icall_fptr
0x140009318  mov     r8d, ebp
0x14000931b  mov     edx, ebx
0x14000931d  mov     rcx, rdi
0x140009320  call    rsi
0x140009322  jmp     short loc_14000932F
0x140009324  mov     edx, ebx; dwSpinCount
0x140009326  mov     rcx, rdi; lpCriticalSection
0x140009329  call    cs:InitializeCriticalSectionAndSpinCount; KERNEL32
0x14000932f  mov     rbx, [rsp+28h+arg_0]
0x140009334  mov     rbp, [rsp+28h+arg_8]
0x140009339  mov     rsi, [rsp+28h+arg_10]
0x14000933e  add     rsp, 20h
0x140009342  pop     rdi
0x140009343  retn

// ===== __acrt_LCMapStringEx @ 0x140009344 =====

0x140009344  mov     rax, rsp
0x140009347  mov     [rax+8], rbx
0x14000934b  mov     [rax+10h], rbp
0x14000934f  mov     [rax+18h], rsi
0x140009353  mov     [rax+20h], rdi
0x140009357  push    r14
0x140009359  sub     rsp, 50h
0x14000935d  mov     edi, r9d
0x140009360  mov     rsi, r8
0x140009363  mov     ebp, edx
0x140009365  lea     r9, aLcmapstringex
0x14000936c  mov     r14, rcx
0x14000936f  lea     r8, unk_140013050
0x140009376  lea     rdx, aLcmapstringex
0x14000937d  mov     ecx, 16h
0x140009382  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x140009387  mov     rbx, rax
0x14000938a  test    rax, rax
0x14000938d  jz      short loc_1400093E6
0x14000938f  mov     rcx, rax
0x140009392  call    cs:__guard_check_icall_fptr
0x140009398  mov     rcx, [rsp+58h+arg_40]
0x1400093a0  mov     r9d, edi
0x1400093a3  mov     rax, [rsp+58h+arg_20]
0x1400093ab  mov     r8, rsi
0x1400093ae  mov     [rsp+58h+var_18], rcx
0x1400093b3  mov     edx, ebp
0x1400093b5  mov     rcx, [rsp+58h+arg_38]
0x1400093bd  mov     [rsp+58h+var_20], rcx
0x1400093c2  mov     rcx, [rsp+58h+arg_30]
0x1400093ca  mov     [rsp+58h+var_28], rcx
0x1400093cf  mov     ecx, [rsp+58h+arg_28]
0x1400093d6  mov     [rsp+58h+cchDest], ecx
0x1400093da  mov     rcx, r14
0x1400093dd  mov     [rsp+58h+lpDestStr], rax
0x1400093e2  call    rbx
0x1400093e4  jmp     short loc_140009418
0x1400093e6  xor     edx, edx
0x1400093e8  mov     rcx, r14
0x1400093eb  call    __acrt_LocaleNameToLCID
0x1400093f0  mov     ecx, eax; Locale
0x1400093f2  mov     r9d, edi; cchSrc
0x1400093f5  mov     eax, [rsp+58h+arg_28]
0x1400093fc  mov     r8, rsi; lpSrcStr
0x1400093ff  mov     [rsp+58h+cchDest], eax; cchDest
0x140009403  mov     edx, ebp; dwMapFlags
0x140009405  mov     rax, [rsp+58h+arg_20]
0x14000940d  mov     [rsp+58h+lpDestStr], rax; lpDestStr
0x140009412  call    cs:LCMapStringW; KERNEL32
0x140009418  mov     rbx, [rsp+58h+arg_0]
0x14000941d  mov     rbp, [rsp+58h+arg_8]
0x140009422  mov     rsi, [rsp+58h+arg_10]
0x140009427  mov     rdi, [rsp+58h+arg_18]
0x14000942c  add     rsp, 50h
0x140009430  pop     r14
0x140009432  retn

// ===== __acrt_LocaleNameToLCID @ 0x140009434 =====

0x140009434  mov     [rsp+arg_0], rbx
0x140009439  mov     [rsp+arg_8], rsi
0x14000943e  push    rdi
0x14000943f  sub     rsp, 20h
0x140009443  mov     esi, edx
0x140009445  lea     r9, aLocalenametolc
0x14000944c  mov     rbx, rcx
0x14000944f  lea     rdx, aLocalenametolc
0x140009456  mov     ecx, 18h
0x14000945b  lea     r8, unk_140013068
0x140009462  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x140009467  mov     rdi, rax
0x14000946a  test    rax, rax
0x14000946d  jz      short loc_140009481
0x14000946f  mov     rcx, rax
0x140009472  call    cs:__guard_check_icall_fptr
0x140009478  mov     edx, esi
0x14000947a  mov     rcx, rbx
0x14000947d  call    rdi
0x14000947f  jmp     short loc_140009489
0x140009481  mov     rcx, rbx
0x140009484  call    __crtDownlevelLocaleNameToLCID
0x140009489  mov     rbx, [rsp+28h+arg_0]
0x14000948e  mov     rsi, [rsp+28h+arg_8]
0x140009493  add     rsp, 20h
0x140009497  pop     rdi
0x140009498  retn

// ===== __acrt_initialize_winapi_thunks @ 0x14000949c =====

0x14000949c  mov     [rsp+arg_0], rdi
0x1400094a1  mov     rdx, cs:__security_cookie
0x1400094a8  lea     rdi, qword_14001D800
0x1400094af  mov     eax, edx
0x1400094b1  mov     ecx, 40h ; '@'
0x1400094b6  and     eax, 3Fh
0x1400094b9  sub     ecx, eax
0x1400094bb  xor     eax, eax
0x1400094bd  ror     rax, cl
0x1400094c0  mov     ecx, 20h ; ' '
0x1400094c5  xor     rax, rdx
0x1400094c8  rep stosq
0x1400094cb  mov     rdi, [rsp+arg_0]
0x1400094d0  mov     al, 1
0x1400094d2  retn

// ===== __acrt_is_packaged_app @ 0x1400094d4 =====

0x1400094d4  mov     [rsp+arg_8], rbx
0x1400094d9  push    rdi
0x1400094da  sub     rsp, 20h
0x1400094de  mov     eax, cs:dword_14001D900
0x1400094e4  xor     ebx, ebx
0x1400094e6  test    eax, eax
0x1400094e8  jz      short loc_1400094F2
0x1400094ea  cmp     eax, 1
0x1400094ed  setz    al
0x1400094f0  jmp     short loc_14000954E
0x1400094f2  lea     r9, aGetcurrentpack
0x1400094f9  mov     ecx, 8
0x1400094fe  lea     r8, unk_140013008
0x140009505  lea     rdx, aGetcurrentpack
0x14000950c  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x140009511  mov     rdi, rax
0x140009514  test    rax, rax
0x140009517  jz      short loc_140009541
0x140009519  mov     rcx, rax
0x14000951c  mov     [rsp+28h+arg_0], ebx
0x140009520  call    cs:__guard_check_icall_fptr
0x140009526  xor     edx, edx
0x140009528  lea     rcx, [rsp+28h+arg_0]
0x14000952d  call    rdi
0x14000952f  cmp     eax, 7Ah ; 'z'
0x140009532  jnz     short loc_140009541
0x140009534  lea     ecx, [rax-79h]
0x140009537  mov     al, 1
0x140009539  xchg    ecx, cs:dword_14001D900
0x14000953f  jmp     short loc_14000954E
0x140009541  mov     eax, 2
0x140009546  xchg    eax, cs:dword_14001D900
0x14000954c  xor     al, al
0x14000954e  mov     rbx, [rsp+28h+arg_8]
0x140009553  add     rsp, 20h
0x140009557  pop     rdi
0x140009558  retn

// ===== __acrt_uninitialize_winapi_thunks @ 0x14000955c =====

0x14000955c  push    rbx
0x14000955e  sub     rsp, 20h
0x140009562  test    cl, cl
0x140009564  jnz     short loc_140009595
0x140009566  lea     rbx, qword_14001D760
0x14000956d  mov     rcx, [rbx]; hLibModule
0x140009570  test    rcx, rcx
0x140009573  jz      short loc_140009585
0x140009575  cmp     rcx, 0FFFFFFFFFFFFFFFFh
0x140009579  jz      short loc_140009581
0x14000957b  call    cs:FreeLibrary; KERNEL32
0x140009581  and     qword ptr [rbx], 0
0x140009585  add     rbx, 8
0x140009589  lea     rax, qword_14001D800
0x140009590  cmp     rbx, rax
0x140009593  jnz     short loc_14000956D
0x140009595  mov     al, 1
0x140009597  add     rsp, 20h
0x14000959b  pop     rbx
0x14000959c  retn

// ===== _fcloseall @ 0x1400095a0 =====

0x1400095a0  mov     [rsp+arg_0], rbx
0x1400095a5  push    rdi
0x1400095a6  sub     rsp, 30h
0x1400095aa  and     [rsp+38h+var_18], 0
0x1400095af  mov     ecx, 8
0x1400095b4  call    sub_14000AB5C
0x1400095b9  nop
0x1400095ba  mov     ebx, 3
0x1400095bf  mov     [rsp+38h+var_14], ebx
0x1400095c3  cmp     ebx, cs:dword_14001D080
0x1400095c9  jz      short loc_140009639
0x1400095cb  movsxd  rdi, ebx
0x1400095ce  mov     rax, cs:Block
0x1400095d5  mov     rax, [rax+rdi*8]
0x1400095d9  test    rax, rax
0x1400095dc  jnz     short loc_1400095E0
0x1400095de  jmp     short loc_140009635
0x1400095e0  mov     ecx, [rax+14h]
0x1400095e3  shr     ecx, 0Dh
0x1400095e6  test    cl, 1
0x1400095e9  jz      short loc_140009604
0x1400095eb  mov     rcx, cs:Block
0x1400095f2  mov     rcx, [rcx+rdi*8]; Stream
0x1400095f6  call    fclose
0x1400095fb  cmp     eax, 0FFFFFFFFh
0x1400095fe  jz      short loc_140009604
0x140009600  inc     [rsp+38h+var_18]
0x140009604  mov     rax, cs:Block
0x14000960b  mov     rcx, [rax+rdi*8]
0x14000960f  add     rcx, 30h ; '0'; lpCriticalSection
0x140009613  call    cs:DeleteCriticalSection; KERNEL32
0x140009619  mov     rcx, cs:Block
0x140009620  mov     rcx, [rcx+rdi*8]; Block
0x140009624  call    _free_base
0x140009629  mov     rax, cs:Block
0x140009630  and     qword ptr [rax+rdi*8], 0
0x140009635  inc     ebx
0x140009637  jmp     short loc_1400095BF
0x140009639  mov     ecx, 8
0x14000963e  call    sub_14000ABB0
0x140009643  mov     eax, [rsp+38h+var_18]
0x140009647  mov     rbx, [rsp+38h+arg_0]
0x14000964c  add     rsp, 30h
0x140009650  pop     rdi
0x140009651  retn
0x140010a8b  push    rbp; Microsoft VisualC 64bit universal runtime
0x140010a8d  sub     rsp, 20h
0x140010a91  mov     rbp, rdx
0x140010a94  mov     ecx, 8
0x140010a99  add     rsp, 20h
0x140010a9d  pop     rbp
0x140010a9e  jmp     sub_14000ABB0

// ===== __acrt_stdio_flush_nolock @ 0x140009654 =====

0x140009654  mov     [rsp+arg_0], rbx
0x140009659  mov     [rsp+arg_8], rsi
0x14000965e  push    rdi
0x14000965f  sub     rsp, 20h
0x140009663  mov     rbx, rcx
0x140009666  mov     eax, [rcx+14h]
0x140009669  and     al, 3
0x14000966b  cmp     al, 2
0x14000966d  jnz     short loc_1400096B9
0x14000966f  mov     eax, [rcx+14h]
0x140009672  test    al, 0C0h
0x140009674  jz      short loc_1400096B9
0x140009676  mov     edi, [rcx]
0x140009678  sub     edi, [rcx+8]
0x14000967b  and     dword ptr [rcx+10h], 0
0x14000967f  mov     rsi, [rcx+8]
0x140009683  mov     [rcx], rsi
0x140009686  test    edi, edi
0x140009688  jle     short loc_1400096B9
0x14000968a  call    _fileno
0x14000968f  mov     ecx, eax; FileHandle
0x140009691  mov     r8d, edi; MaxCharCount
0x140009694  mov     rdx, rsi; Buf
0x140009697  call    _write
0x14000969c  cmp     edi, eax
0x14000969e  jz      short loc_1400096AA
0x1400096a0  lock or dword ptr [rbx+14h], 10h
0x1400096a5  or      eax, 0FFFFFFFFh
0x1400096a8  jmp     short loc_1400096BB
0x1400096aa  mov     eax, [rbx+14h]
0x1400096ad  shr     eax, 2
0x1400096b0  test    al, 1
0x1400096b2  jz      short loc_1400096B9
0x1400096b4  lock and dword ptr [rbx+14h], 0FFFFFFFDh
0x1400096b9  xor     eax, eax
0x1400096bb  mov     rbx, [rsp+28h+arg_0]
0x1400096c0  mov     rsi, [rsp+28h+arg_8]
0x1400096c5  add     rsp, 20h
0x1400096c9  pop     rdi
0x1400096ca  retn

// ===== _fflush_nolock @ 0x1400096cc =====

0x1400096cc  push    rbx
0x1400096ce  sub     rsp, 20h
0x1400096d2  mov     rbx, rcx
0x1400096d5  test    rcx, rcx
0x1400096d8  jnz     short loc_1400096E4
0x1400096da  add     rsp, 20h
0x1400096de  pop     rbx
0x1400096df  jmp     common_flush_all
0x1400096e4  call    __acrt_stdio_flush_nolock
0x1400096e9  test    eax, eax
0x1400096eb  jz      short loc_1400096F2
0x1400096ed  or      eax, 0FFFFFFFFh
0x1400096f0  jmp     short loc_140009711
0x1400096f2  mov     eax, [rbx+14h]
0x1400096f5  shr     eax, 0Bh
0x1400096f8  test    al, 1
0x1400096fa  jz      short loc_14000970F
0x1400096fc  mov     rcx, rbx; Stream
0x1400096ff  call    _fileno
0x140009704  mov     ecx, eax; FileHandle
0x140009706  call    _commit
0x14000970b  test    eax, eax
0x14000970d  jnz     short loc_1400096ED
0x14000970f  xor     eax, eax
0x140009711  add     rsp, 20h
0x140009715  pop     rbx
0x140009716  retn

// ===== _flushall @ 0x140009718 =====

0x140009718  mov     ecx, 1
0x14000971d  jmp     common_flush_all

// ===== common_flush_all @ 0x140009724 =====

0x140009724  mov     rax, rsp
0x140009727  mov     [rax+8], rbx
0x14000972b  mov     [rax+18h], rsi
0x14000972f  push    rdi
0x140009730  push    r14
0x140009732  push    r15
0x140009734  sub     rsp, 40h
0x140009738  mov     esi, ecx
0x14000973a  and     dword ptr [rax-34h], 0
0x14000973e  and     dword ptr [rax-38h], 0
0x140009742  mov     ecx, 8
0x140009747  call    sub_14000AB5C
0x14000974c  nop
0x14000974d  mov     rdi, cs:Block
0x140009754  movsxd  rax, cs:dword_14001D080
0x14000975b  lea     r14, [rdi+rax*8]
0x14000975f  or      r15d, 0FFFFFFFFh
0x140009763  mov     [rsp+58h+var_30], rdi
0x140009768  cmp     rdi, r14
0x14000976b  jz      short loc_1400097DE
0x14000976d  mov     rbx, [rdi]
0x140009770  mov     [rsp+58h+arg_8], rbx
0x140009775  mov     [rsp+58h+var_28], rbx
0x14000977a  test    rbx, rbx
0x14000977d  jnz     short loc_140009781
0x14000977f  jmp     short loc_1400097D8
0x140009781  mov     rcx, rbx
0x140009784  call    sub_140005338
0x140009789  nop
0x14000978a  mov     eax, [rbx+14h]
0x14000978d  shr     eax, 0Dh
0x140009790  test    al, 1
0x140009792  jz      short loc_1400097D0
0x140009794  cmp     esi, 1
0x140009797  jnz     short loc_1400097AC
0x140009799  mov     rcx, rbx; Stream
0x14000979c  call    _fflush_nolock
0x1400097a1  cmp     eax, r15d
0x1400097a4  jz      short loc_1400097D0
0x1400097a6  inc     [rsp+58h+var_34]
0x1400097aa  jmp     short loc_1400097D0
0x1400097ac  test    esi, esi
0x1400097ae  jnz     short loc_1400097D0
0x1400097b0  mov     eax, [rbx+14h]
0x1400097b3  shr     eax, 1
0x1400097b5  test    al, 1
0x1400097b7  jz      short loc_1400097D0
0x1400097b9  mov     rcx, rbx; Stream
0x1400097bc  call    _fflush_nolock
0x1400097c1  mov     edx, [rsp+58h+var_38]
0x1400097c5  cmp     eax, r15d
0x1400097c8  cmovz   edx, r15d
0x1400097cc  mov     [rsp+58h+var_38], edx
0x1400097d0  mov     rcx, rbx
0x1400097d3  call    sub_140005344
0x1400097d8  add     rdi, 8
0x1400097dc  jmp     short loc_140009763
0x1400097de  mov     ecx, 8
0x1400097e3  call    sub_14000ABB0
0x1400097e8  mov     eax, [rsp+58h+var_38]
0x1400097ec  cmp     esi, 1
0x1400097ef  cmovz   eax, [rsp+58h+var_34]
0x1400097f4  mov     rbx, [rsp+58h+arg_0]
0x1400097f9  mov     rsi, [rsp+58h+arg_10]
0x1400097fe  add     rsp, 40h
0x140009802  pop     r15
0x140009804  pop     r14
0x140009806  pop     rdi
0x140009807  retn
0x140010aa4  push    rbp
0x140010aa6  sub     rsp, 20h
0x140010aaa  mov     rbp, rdx
0x140010aad  mov     rcx, [rbp+68h]
0x140010ab1  call    sub_140005344
0x140010ab6  nop
0x140010ab7  add     rsp, 20h
0x140010abb  pop     rbp
0x140010abc  retn
0x140010abe  push    rbp
0x140010ac0  sub     rsp, 20h
0x140010ac4  mov     rbp, rdx
0x140010ac7  mov     ecx, 8
0x140010acc  add     rsp, 20h
0x140010ad0  pop     rbp
0x140010ad1  jmp     sub_14000ABB0

// ===== __acrt_stdio_free_buffer_nolock @ 0x140009808 =====

0x140009808  push    rbx
0x14000980a  sub     rsp, 20h
0x14000980e  mov     rbx, rcx
0x140009811  mov     eax, [rcx+14h]
0x140009814  shr     eax, 0Dh
0x140009817  test    al, 1
0x140009819  jz      short loc_140009842
0x14000981b  mov     eax, [rcx+14h]
0x14000981e  shr     eax, 6
0x140009821  test    al, 1
0x140009823  jz      short loc_140009842
0x140009825  mov     rcx, [rcx+8]; Block
0x140009829  call    _free_base
0x14000982e  lock and dword ptr [rbx+14h], 0FFFFFEBFh
0x140009836  xor     eax, eax
0x140009838  mov     [rbx+8], rax
0x14000983c  mov     [rbx], rax
0x14000983f  mov     [rbx+10h], eax
0x140009842  add     rsp, 20h
0x140009846  pop     rbx
0x140009847  retn

// ===== _towlower_l @ 0x140009848 =====

0x140009848  mov     [rsp-8+arg_0], cx
0x14000984d  push    rbp
0x14000984e  mov     rbp, rsp
0x140009851  sub     rsp, 50h
0x140009855  mov     eax, 0FFFFh
0x14000985a  cmp     cx, ax
0x14000985d  jz      loc_140009906
0x140009863  lea     rcx, [rbp+var_20]; this
0x140009867  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000986c  mov     rax, [rbp+var_18]
0x140009870  mov     r10, [rax+138h]
0x140009877  test    r10, r10
0x14000987a  jnz     short loc_14000988F
0x14000987c  movzx   edx, [rbp+arg_0]
0x140009880  lea     eax, [rdx-41h]
0x140009883  cmp     ax, 19h
0x140009887  ja      short loc_1400098F2
0x140009889  add     dx, 20h ; ' '
0x14000988d  jmp     short loc_1400098F2
0x14000988f  movzx   ecx, [rbp+arg_0]; C
0x140009893  mov     edx, 100h
0x140009898  cmp     cx, dx
0x14000989b  jnb     short loc_1400098C6
0x14000989d  mov     edx, 1; Type
0x1400098a2  call    iswctype
0x1400098a7  test    eax, eax
0x1400098a9  jnz     short loc_1400098B1
0x1400098ab  movzx   edx, [rbp+arg_0]
0x1400098af  jmp     short loc_1400098F2
0x1400098b1  mov     rax, [rbp+var_18]
0x1400098b5  movzx   edx, [rbp+arg_0]
0x1400098b9  mov     rcx, [rax+110h]
0x1400098c0  movzx   edx, byte ptr [rcx+rdx]
0x1400098c4  jmp     short loc_1400098F2
0x1400098c6  mov     r9d, 1
0x1400098cc  lea     rax, [rbp+arg_10]
0x1400098d0  mov     [rsp+50h+var_28], r9d
0x1400098d5  lea     r8, [rbp+arg_0]
0x1400098d9  mov     rcx, r10
0x1400098dc  mov     [rsp+50h+var_30], rax
0x1400098e1  call    __crtLCMapStringW
0x1400098e6  movzx   edx, [rbp+arg_0]
0x1400098ea  test    eax, eax
0x1400098ec  jz      short loc_1400098F2
0x1400098ee  movzx   edx, [rbp+arg_10]
0x1400098f2  cmp     [rbp+var_8], 0
0x1400098f6  jz      short loc_140009903
0x1400098f8  mov     rcx, [rbp+var_20]
0x1400098fc  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x140009903  movzx   eax, dx
0x140009906  add     rsp, 50h
0x14000990a  pop     rbp
0x14000990b  retn

// ===== wcsncpy_s @ 0x14000990c =====

0x14000990c  mov     [rsp+arg_0], rbx
0x140009911  push    rdi
0x140009912  sub     rsp, 20h
0x140009916  xor     r10d, r10d
0x140009919  mov     r11, rdx
0x14000991c  test    r9, r9
0x14000991f  jnz     short loc_14000994D
0x140009921  test    rcx, rcx
0x140009924  jnz     short loc_140009952
0x140009926  test    rdx, rdx
0x140009929  jz      short loc_14000993F
0x14000992b  call    _errno
0x140009930  mov     ebx, 16h
0x140009935  mov     [rax], ebx
0x140009937  call    _invalid_parameter_noinfo
0x14000993c  mov     r10d, ebx
0x14000993f  mov     eax, r10d
0x140009942  mov     rbx, [rsp+28h+arg_0]
0x140009947  add     rsp, 20h
0x14000994b  pop     rdi
0x14000994c  retn
0x14000994d  test    rcx, rcx
0x140009950  jz      short loc_14000992B
0x140009952  test    rdx, rdx
0x140009955  jz      short loc_14000992B
0x140009957  test    r9, r9
0x14000995a  jnz     short loc_140009962
0x14000995c  mov     [rcx], r10w
0x140009960  jmp     short loc_14000993F
0x140009962  test    r8, r8
0x140009965  jnz     short loc_14000996D
0x140009967  mov     [rcx], r10w
0x14000996b  jmp     short loc_14000992B
0x14000996d  sub     r8, rcx
0x140009970  mov     rdx, rcx
0x140009973  mov     rbx, r11
0x140009976  mov     rdi, r9
0x140009979  cmp     r9, 0FFFFFFFFFFFFFFFFh
0x14000997d  jnz     short loc_140009998
0x14000997f  movzx   eax, word ptr [r8+rdx]
0x140009984  mov     [rdx], ax
0x140009987  lea     rdx, [rdx+2]
0x14000998b  test    ax, ax
0x14000998e  jz      short loc_1400099BE
0x140009990  sub     rbx, 1
0x140009994  jnz     short loc_14000997F
0x140009996  jmp     short loc_1400099BE
0x140009998  movzx   eax, word ptr [r8+rdx]
0x14000999d  mov     [rdx], ax
0x1400099a0  lea     rdx, [rdx+2]
0x1400099a4  test    ax, ax
0x1400099a7  jz      short loc_1400099B5
0x1400099a9  sub     rbx, 1
0x1400099ad  jz      short loc_1400099B5
0x1400099af  sub     rdi, 1
0x1400099b3  jnz     short loc_140009998
0x1400099b5  test    rdi, rdi
0x1400099b8  jnz     short loc_1400099BE
0x1400099ba  mov     [rdx], r10w
0x1400099be  test    rbx, rbx
0x1400099c1  jnz     loc_14000993F
0x1400099c7  cmp     r9, 0FFFFFFFFFFFFFFFFh
0x1400099cb  jnz     short loc_1400099DC
0x1400099cd  mov     [rcx+r11*2-2], r10w
0x1400099d3  lea     r10d, [rbx+50h]
0x1400099d7  jmp     loc_14000993F
0x1400099dc  mov     [rcx], r10w
0x1400099e0  call    _errno
0x1400099e5  mov     ebx, 22h ; '"'
0x1400099ea  jmp     loc_140009935

// ===== CompareFunction @ 0x1400099f0 =====

0x1400099f0  cmp     rcx, rdx
0x1400099f3  jnb     short loc_1400099F9
0x1400099f5  or      eax, 0FFFFFFFFh
0x1400099f8  retn
0x1400099f9  xor     eax, eax
0x1400099fb  cmp     rcx, rdx
0x1400099fe  setnbe  al
0x140009a01  retn

// ===== ??$common_expand_argv_wildcards@_W@@YAHQEAPEA_WQEAPEAPEA_W@Z @ 0x140009a04 =====

0x140009a04  mov     [rsp-38h+arg_10], rbx
0x140009a09  push    rbp
0x140009a0a  push    rsi
0x140009a0b  push    rdi
0x140009a0c  push    r12
0x140009a0e  push    r13
0x140009a10  push    r14
0x140009a12  push    r15
0x140009a14  mov     rbp, rsp
0x140009a17  sub     rsp, 80h
0x140009a1e  mov     rax, cs:__security_cookie
0x140009a25  xor     rax, rsp
0x140009a28  mov     [rbp+var_10], rax
0x140009a2c  xor     edi, edi
0x140009a2e  mov     [rbp+var_28], rdx
0x140009a32  mov     rbx, rcx
0x140009a35  test    rdx, rdx
0x140009a38  jnz     short loc_140009A50
0x140009a3a  call    _errno
0x140009a3f  lea     ebx, [rdi+16h]
0x140009a42  mov     [rax], ebx
0x140009a44  call    _invalid_parameter_noinfo
0x140009a49  mov     eax, ebx
0x140009a4b  jmp     loc_140009BF7
0x140009a50  xorps   xmm0, xmm0
0x140009a53  mov     [rdx], rdi
0x140009a56  cmp     [rcx], rdi
0x140009a59  movdqu  xmmword ptr [rbp+Block], xmm0
0x140009a5e  mov     [rbp+var_38], rdi
0x140009a62  jz      short loc_140009ABC
0x140009a64  mov     rcx, [rbx]; String
0x140009a67  lea     rdx, [rbp+Control]; Control
0x140009a6b  mov     dword ptr [rbp+Control], 3F002Ah
0x140009a72  mov     [rbp+Control+4], di
0x140009a76  call    wcspbrk
0x140009a7b  mov     rcx, [rbx]; wchar_t *
0x140009a7e  test    rax, rax
0x140009a81  jnz     short loc_140009A93
0x140009a83  lea     r9, [rbp+Block]
0x140009a87  xor     r8d, r8d; MaxCount
0x140009a8a  xor     edx, edx; wchar_t *
0x140009a8c  call    ??$copy_and_add_argument_to_buffer@_W@@YAHQEB_W0_KAEAV?$argument_list@_W@?A0x7b96f60e@@@Z
0x140009a91  jmp     short loc_140009A9F
0x140009a93  lea     r8, [rbp+Block]
0x140009a97  mov     rdx, rax
0x140009a9a  call    ??$expand_argument_wildcards@_W@@YAHQEA_W0AEAV?$argument_list@_W@?A0x7b96f60e@@@Z
0x140009a9f  mov     r14d, eax
0x140009aa2  test    eax, eax
0x140009aa4  jnz     short loc_140009AAF
0x140009aa6  add     rbx, 8
0x140009aaa  cmp     [rbx], rdi
0x140009aad  jmp     short loc_140009A62
0x140009aaf  mov     r12, [rbp+Block+8]
0x140009ab3  mov     rsi, [rbp+Block]
0x140009ab7  jmp     loc_140009BBB
0x140009abc  mov     rsi, [rbp+Block]
0x140009ac0  mov     r9, rdi
0x140009ac3  mov     r12, [rbp+Block+8]
0x140009ac7  mov     rdx, rsi
0x140009aca  mov     rax, r12
0x140009acd  mov     qword ptr [rbp+Control], rdi
0x140009ad1  sub     rax, rsi
0x140009ad4  mov     r8, rdi
0x140009ad7  mov     r15, rax
0x140009ada  sar     r15, 3
0x140009ade  inc     r15
0x140009ae1  lea     rcx, [rax+7]
0x140009ae5  shr     rcx, 3
0x140009ae9  cmp     rsi, r12
0x140009aec  cmova   rcx, rdi
0x140009af0  or      r14, 0FFFFFFFFFFFFFFFFh
0x140009af4  test    rcx, rcx
0x140009af7  jz      short loc_140009B1F
0x140009af9  mov     r10, [rdx]
0x140009afc  mov     rax, r14
0x140009aff  inc     rax
0x140009b02  cmp     [r10+rax*2], di
0x140009b07  jnz     short loc_140009AFF
0x140009b09  inc     r9
0x140009b0c  add     rdx, 8
0x140009b10  add     r9, rax
0x140009b13  inc     r8
0x140009b16  cmp     r8, rcx
0x140009b19  jnz     short loc_140009AF9
0x140009b1b  mov     qword ptr [rbp+Control], r9
0x140009b1f  mov     r8d, 2
0x140009b25  mov     rdx, r9
0x140009b28  mov     rcx, r15
0x140009b2b  call    __acrt_allocate_buffer_for_argv
0x140009b30  mov     rbx, rax
0x140009b33  test    rax, rax
0x140009b36  jz      short loc_140009BB4
0x140009b38  lea     rdx, [rax+r15*8]
0x140009b3c  mov     r15, rsi
0x140009b3f  mov     [rbp+var_20], rdx
0x140009b43  mov     rcx, rdx; Destination
0x140009b46  mov     [rbp+var_50], rdx
0x140009b4a  cmp     rsi, r12
0x140009b4d  jz      short loc_140009BAA
0x140009b4f  sub     rax, rsi
0x140009b52  mov     [rbp+var_30], rax
0x140009b56  mov     r8, [r15]; Source
0x140009b59  mov     r13, r14
0x140009b5c  inc     r13
0x140009b5f  cmp     [r8+r13*2], di
0x140009b64  jnz     short loc_140009B5C
0x140009b66  mov     rax, rcx
0x140009b69  inc     r13
0x140009b6c  sub     rax, rdx
0x140009b6f  mov     r9, r13; MaxCount
0x140009b72  mov     rdx, qword ptr [rbp+Control]
0x140009b76  sar     rax, 1
0x140009b79  sub     rdx, rax; SizeInWords
0x140009b7c  call    wcsncpy_s
0x140009b81  test    eax, eax
0x140009b83  jnz     loc_140009C1E
0x140009b89  mov     rcx, [rbp+var_50]
0x140009b8d  mov     rax, [rbp+var_30]
0x140009b91  mov     rdx, [rbp+var_20]
0x140009b95  mov     [rax+r15], rcx
0x140009b99  add     r15, 8
0x140009b9d  lea     rcx, [rcx+r13*2]
0x140009ba1  mov     [rbp+var_50], rcx
0x140009ba5  cmp     r15, r12
0x140009ba8  jnz     short loc_140009B56
0x140009baa  mov     rax, [rbp+var_28]
0x140009bae  mov     r14d, edi
0x140009bb1  mov     [rax], rbx
0x140009bb4  xor     ecx, ecx; Block
0x140009bb6  call    _free_base
0x140009bbb  mov     rbx, r12
0x140009bbe  mov     r15, rsi
0x140009bc1  sub     rbx, rsi
0x140009bc4  add     rbx, 7
0x140009bc8  shr     rbx, 3
0x140009bcc  cmp     rsi, r12
0x140009bcf  cmova   rbx, rdi
0x140009bd3  test    rbx, rbx
0x140009bd6  jz      short loc_140009BEC
0x140009bd8  mov     rcx, [r15]; Block
0x140009bdb  call    _free_base
0x140009be0  inc     rdi
0x140009be3  lea     r15, [r15+8]
0x140009be7  cmp     rdi, rbx
0x140009bea  jnz     short loc_140009BD8
0x140009bec  mov     rcx, rsi; Block
0x140009bef  call    _free_base
0x140009bf4  mov     eax, r14d
0x140009bf7  mov     rcx, [rbp+var_10]
0x140009bfb  xor     rcx, rsp; StackCookie
0x140009bfe  call    __security_check_cookie
0x140009c03  mov     rbx, [rsp+80h+arg_10]
0x140009c0b  add     rsp, 80h
0x140009c12  pop     r15
0x140009c14  pop     r14
0x140009c16  pop     r13
0x140009c18  pop     r12
0x140009c1a  pop     rdi
0x140009c1b  pop     rsi
0x140009c1c  pop     rbp
0x140009c1d  retn
0x140009c1e  xor     r9d, r9d; LineNo
0x140009c21  mov     [rsp+80h+Reserved], rdi; Reserved
0x140009c26  xor     r8d, r8d; FileName
0x140009c29  xor     edx, edx; FunctionName
0x140009c2b  xor     ecx, ecx; Expression
0x140009c2d  call    _invoke_watson

// ===== ??$copy_and_add_argument_to_buffer@_W@@YAHQEB_W0_KAEAV?$argument_list@_W@?A0x7b96f60e@@@Z @ 0x140009c34 =====

0x140009c34  mov     [rsp+arg_0], rbx
0x140009c39  mov     [rsp+arg_8], rbp
0x140009c3e  mov     [rsp+arg_10], rsi
0x140009c43  push    rdi
0x140009c44  push    r12
0x140009c46  push    r13
0x140009c48  push    r14
0x140009c4a  push    r15
0x140009c4c  sub     rsp, 30h
0x140009c50  or      rax, 0FFFFFFFFFFFFFFFFh
0x140009c54  mov     rsi, r9
0x140009c57  mov     rdi, rax
0x140009c5a  xor     r13d, r13d
0x140009c5d  mov     rbp, r8
0x140009c60  mov     r12, rdx
0x140009c63  mov     r15, rcx
0x140009c66  inc     rdi
0x140009c69  cmp     [rcx+rdi*2], r13w
0x140009c6e  jnz     short loc_140009C66
0x140009c70  inc     rdi
0x140009c73  sub     rax, r8
0x140009c76  cmp     rdi, rax
0x140009c79  jbe     short loc_140009C9D
0x140009c7b  mov     eax, 0Ch
0x140009c80  mov     rbx, [rsp+58h+arg_0]
0x140009c85  mov     rbp, [rsp+58h+arg_8]
0x140009c8a  mov     rsi, [rsp+58h+arg_10]
0x140009c8f  add     rsp, 30h
0x140009c93  pop     r15
0x140009c95  pop     r14
0x140009c97  pop     r13
0x140009c99  pop     r12
0x140009c9b  pop     rdi
0x140009c9c  retn
0x140009c9d  lea     r14, [r8+1]
0x140009ca1  mov     edx, 2; Size
0x140009ca6  add     r14, rdi
0x140009ca9  mov     rcx, r14; Count
0x140009cac  call    _calloc_base
0x140009cb1  mov     rbx, rax
0x140009cb4  test    rbp, rbp
0x140009cb7  jz      short loc_140009CCE
0x140009cb9  mov     r9, rbp; MaxCount
0x140009cbc  mov     r8, r12; Source
0x140009cbf  mov     rdx, r14; SizeInWords
0x140009cc2  mov     rcx, rax; Destination
0x140009cc5  call    wcsncpy_s
0x140009cca  test    eax, eax
0x140009ccc  jnz     short loc_140009D1C
0x140009cce  sub     r14, rbp
0x140009cd1  lea     rcx, [rbx+rbp*2]; Destination
0x140009cd5  mov     rdx, r14; SizeInWords
0x140009cd8  mov     r9, rdi; MaxCount
0x140009cdb  mov     r8, r15; Source
0x140009cde  call    wcsncpy_s
0x140009ce3  test    eax, eax
0x140009ce5  jnz     short loc_140009D31
0x140009ce7  mov     rcx, rsi
0x140009cea  call    unknown_libname_17; Microsoft VisualC 64bit universal runtime
0x140009cef  mov     edi, eax
0x140009cf1  test    eax, eax
0x140009cf3  jz      short loc_140009CFF
0x140009cf5  mov     rcx, rbx; Block
0x140009cf8  call    _free_base
0x140009cfd  jmp     short loc_140009D0E
0x140009cff  mov     rax, [rsi+8]
0x140009d03  mov     edi, r13d
0x140009d06  mov     [rax], rbx
0x140009d09  add     qword ptr [rsi+8], 8
0x140009d0e  xor     ecx, ecx; Block
0x140009d10  call    _free_base
0x140009d15  mov     eax, edi
0x140009d17  jmp     loc_140009C80
0x140009d1c  xor     r9d, r9d; LineNo
0x140009d1f  mov     [rsp+58h+Reserved], r13; Reserved
0x140009d24  xor     r8d, r8d; FileName
0x140009d27  xor     edx, edx; FunctionName
0x140009d29  xor     ecx, ecx; Expression
0x140009d2b  call    _invoke_watson
0x140009d31  xor     r9d, r9d; LineNo
0x140009d34  mov     [rsp+58h+Reserved], r13; Reserved
0x140009d39  xor     r8d, r8d; FileName
0x140009d3c  xor     edx, edx; FunctionName
0x140009d3e  xor     ecx, ecx; Expression
0x140009d40  call    _invoke_watson

// ===== ??$expand_argument_wildcards@_W@@YAHQEA_W0AEAV?$argument_list@_W@?A0x7b96f60e@@@Z @ 0x140009d48 =====

0x140009d48  mov     [rsp+arg_18], rbx
0x140009d4d  push    rbp
0x140009d4e  push    rsi
0x140009d4f  push    rdi
0x140009d50  push    r14
0x140009d52  push    r15
0x140009d54  sub     rsp, 290h
0x140009d5b  mov     rax, cs:__security_cookie
0x140009d62  xor     rax, rsp
0x140009d65  mov     [rsp+2B8h+var_38], rax
0x140009d6d  mov     r14, r8
0x140009d70  mov     rbp, rcx
0x140009d73  mov     r8, 200000000801h
0x140009d7d  jmp     short loc_140009D99
0x140009d7f  movzx   eax, word ptr [rdx]
0x140009d82  sub     ax, 2Fh ; '/'
0x140009d86  cmp     ax, 2Dh ; '-'
0x140009d8a  ja      short loc_140009D95
0x140009d8c  movzx   eax, ax
0x140009d8f  bt      r8, rax
0x140009d93  jb      short loc_140009D9E
0x140009d95  sub     rdx, 2
0x140009d99  cmp     rdx, rcx
0x140009d9c  jnz     short loc_140009D7F
0x140009d9e  movzx   ecx, word ptr [rdx]
0x140009da1  cmp     cx, 3Ah ; ':'
0x140009da5  jnz     short loc_140009DC5
0x140009da7  lea     rax, [rbp+2]
0x140009dab  cmp     rdx, rax
0x140009dae  jz      short loc_140009DC5
0x140009db0  mov     r9, r14
0x140009db3  xor     r8d, r8d; MaxCount
0x140009db6  xor     edx, edx; wchar_t *
0x140009db8  mov     rcx, rbp; Source
0x140009dbb  call    ??$copy_and_add_argument_to_buffer@_W@@YAHQEB_W0_KAEAV?$argument_list@_W@?A0x7b96f60e@@@Z
0x140009dc0  jmp     loc_140009E4A
0x140009dc5  sub     cx, 2Fh ; '/'
0x140009dc9  xor     edi, edi
0x140009dcb  cmp     cx, 2Dh ; '-'
0x140009dcf  ja      short loc_140009DDD
0x140009dd1  movzx   eax, cx
0x140009dd4  bt      r8, rax
0x140009dd8  lea     eax, [rdi+1]
0x140009ddb  jb      short loc_140009DDF
0x140009ddd  mov     eax, edi
0x140009ddf  sub     rdx, rbp
0x140009de2  lea     rcx, [rsp+2B8h+FindFileData]
0x140009de7  sar     rdx, 1
0x140009dea  mov     r8d, 250h
0x140009df0  inc     rdx
0x140009df3  neg     al
0x140009df5  sbb     r15, r15
0x140009df8  and     r15, rdx
0x140009dfb  xor     edx, edx
0x140009dfd  call    sub_140002F60
0x140009e02  xor     r9d, r9d; fSearchOp
0x140009e05  mov     [rsp+2B8h+dwAdditionalFlags], edi; dwAdditionalFlags
0x140009e09  lea     r8, [rsp+2B8h+FindFileData]; lpFindFileData
0x140009e0e  mov     [rsp+2B8h+lpSearchFilter], rdi; lpSearchFilter
0x140009e13  xor     edx, edx; fInfoLevelId
0x140009e15  mov     rcx, rbp; lpFileName
0x140009e18  call    cs:FindFirstFileExW; KERNEL32
0x140009e1e  mov     rbx, rax
0x140009e21  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x140009e25  jnz     short loc_140009E71
0x140009e27  mov     r9, r14
0x140009e2a  xor     r8d, r8d; MaxCount
0x140009e2d  xor     edx, edx; wchar_t *
0x140009e2f  mov     rcx, rbp; Source
0x140009e32  call    ??$copy_and_add_argument_to_buffer@_W@@YAHQEB_W0_KAEAV?$argument_list@_W@?A0x7b96f60e@@@Z
0x140009e37  mov     edi, eax
0x140009e39  cmp     rbx, 0FFFFFFFFFFFFFFFFh
0x140009e3d  jz      short loc_140009E48
0x140009e3f  mov     rcx, rbx; hFindFile
0x140009e42  call    cs:FindClose; KERNEL32
0x140009e48  mov     eax, edi
0x140009e4a  mov     rcx, [rsp+2B8h+var_38]
0x140009e52  xor     rcx, rsp; StackCookie
0x140009e55  call    __security_check_cookie
0x140009e5a  mov     rbx, [rsp+2B8h+arg_18]
0x140009e62  add     rsp, 290h
0x140009e69  pop     r15
0x140009e6b  pop     r14
0x140009e6d  pop     rdi
0x140009e6e  pop     rsi
0x140009e6f  pop     rbp
0x140009e70  retn
0x140009e71  mov     rsi, [r14+8]
0x140009e75  sub     rsi, [r14]
0x140009e78  sar     rsi, 3
0x140009e7c  cmp     [rsp+2B8h+Source], 2Eh ; '.'
0x140009e82  jnz     short loc_140009E9A
0x140009e84  cmp     [rsp+2B8h+var_25A], di
0x140009e89  jz      short loc_140009EB1
0x140009e8b  cmp     [rsp+2B8h+var_25A], 2Eh ; '.'
0x140009e91  jnz     short loc_140009E9A
0x140009e93  cmp     [rsp+2B8h+var_258], di
0x140009e98  jz      short loc_140009EB1
0x140009e9a  mov     r9, r14
0x140009e9d  lea     rcx, [rsp+2B8h+Source]; Source
0x140009ea2  mov     r8, r15; MaxCount
0x140009ea5  mov     rdx, rbp; wchar_t *
0x140009ea8  call    ??$copy_and_add_argument_to_buffer@_W@@YAHQEB_W0_KAEAV?$argument_list@_W@?A0x7b96f60e@@@Z
0x140009ead  test    eax, eax
0x140009eaf  jnz     short loc_140009E37
0x140009eb1  lea     rdx, [rsp+2B8h+FindFileData]; lpFindFileData
0x140009eb6  mov     rcx, rbx; hFindFile
0x140009eb9  call    cs:FindNextFileW; KERNEL32
0x140009ebf  test    eax, eax
0x140009ec1  jnz     short loc_140009E7C
0x140009ec3  mov     rax, [r14]
0x140009ec6  mov     rdx, [r14+8]
0x140009eca  sub     rdx, rax
0x140009ecd  sar     rdx, 3
0x140009ed1  cmp     rsi, rdx
0x140009ed4  jz      loc_140009E39
0x140009eda  sub     rdx, rsi; NumOfElements
0x140009edd  lea     rcx, [rax+rsi*8]; Base
0x140009ee1  lea     r9, CompareFunction; CompareFunction
0x140009ee8  mov     r8d, 8; SizeOfElements
0x140009eee  call    qsort
0x140009ef3  jmp     loc_140009E39

// ===== unknown_libname_17 @ 0x140009ef8 =====

0x140009ef8  mov     [rsp+arg_0], rbx
0x140009efd  mov     [rsp+arg_8], rbp
0x140009f02  mov     [rsp+arg_10], rsi
0x140009f07  push    rdi
0x140009f08  sub     rsp, 20h
0x140009f0c  mov     rsi, [rcx+10h]
0x140009f10  mov     rdi, rcx
0x140009f13  cmp     [rcx+8], rsi
0x140009f17  jz      short loc_140009F20
0x140009f19  xor     eax, eax
0x140009f1b  jmp     loc_140009FAA
0x140009f20  xor     ebx, ebx
0x140009f22  cmp     [rcx], rbx
0x140009f25  jnz     short loc_140009F59
0x140009f27  lea     edx, [rbx+8]; Size
0x140009f2a  lea     ecx, [rbx+4]; Count
0x140009f2d  call    _calloc_base
0x140009f32  xor     ecx, ecx; Block
0x140009f34  mov     [rdi], rax
0x140009f37  call    _free_base
0x140009f3c  mov     rax, [rdi]
0x140009f3f  test    rax, rax
0x140009f42  jnz     short loc_140009F4B
0x140009f44  mov     eax, 0Ch
0x140009f49  jmp     short loc_140009FAA
0x140009f4b  mov     [rdi+8], rax
0x140009f4f  add     rax, 20h ; ' '
0x140009f53  mov     [rdi+10h], rax
0x140009f57  jmp     short loc_140009F19
0x140009f59  sub     rsi, [rcx]
0x140009f5c  mov     rax, 7FFFFFFFFFFFFFFFh
0x140009f66  sar     rsi, 3
0x140009f6a  cmp     rsi, rax
0x140009f6d  ja      short loc_140009F44
0x140009f6f  mov     rcx, [rcx]; Block
0x140009f72  lea     rbp, [rsi+rsi]
0x140009f76  mov     rdx, rbp; Count
0x140009f79  mov     r8d, 8; Size
0x140009f7f  call    j__recalloc_base
0x140009f84  test    rax, rax
0x140009f87  jnz     short loc_140009F8E
0x140009f89  lea     ebx, [rax+0Ch]
0x140009f8c  jmp     short loc_140009FA1
0x140009f8e  lea     rcx, [rax+rsi*8]
0x140009f92  mov     [rdi], rax
0x140009f95  mov     [rdi+8], rcx
0x140009f99  lea     rcx, [rax+rbp*8]
0x140009f9d  mov     [rdi+10h], rcx
0x140009fa1  xor     ecx, ecx; Block
0x140009fa3  call    _free_base
0x140009fa8  mov     eax, ebx
0x140009faa  mov     rbx, [rsp+28h+arg_0]
0x140009faf  mov     rbp, [rsp+28h+arg_8]
0x140009fb4  mov     rsi, [rsp+28h+arg_10]
0x140009fb9  add     rsp, 20h
0x140009fbd  pop     rdi
0x140009fbe  retn

// ===== j_??$common_expand_argv_wildcards@_W@@YAHQEAPEA_WQEAPEAPEA_W@Z @ 0x140009fc0 =====

0x140009fc0  jmp     ??$common_expand_argv_wildcards@_W@@YAHQEAPEA_WQEAPEAPEA_W@Z

// ===== ??$?RV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@V_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@$$QEAV_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@Z @ 0x140009fc8 =====

0x140009fc8  mov     [rsp+arg_0], rbx
0x140009fcd  mov     [rsp+arg_18], r9
0x140009fd2  push    rdi
0x140009fd3  sub     rsp, 20h
0x140009fd7  mov     rbx, r9
0x140009fda  mov     rdi, r8
0x140009fdd  mov     ecx, [rdx]
0x140009fdf  call    sub_14000AB5C
0x140009fe4  nop
0x140009fe5  mov     rcx, rdi
0x140009fe8  call    ??R_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@QEBAXXZ
0x140009fed  nop
0x140009fee  mov     ecx, [rbx]
0x140009ff0  call    sub_14000ABB0
0x140009ff5  mov     rbx, [rsp+28h+arg_0]
0x140009ffa  add     rsp, 20h
0x140009ffe  pop     rdi
0x140009fff  retn
0x140010a3b  push    rbp
0x140010a3d  sub     rsp, 20h
0x140010a41  mov     rbp, rdx
0x140010a44  mov     rax, [rbp+48h]
0x140010a48  mov     ecx, [rax]
0x140010a4a  add     rsp, 20h
0x140010a4e  pop     rbp
0x140010a4f  jmp     sub_14000ABB0

// ===== ??R_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@QEBAXXZ @ 0x14000a000 =====

0x14000a000  mov     [rsp+arg_0], rbx
0x14000a005  mov     [rsp+arg_8], rsi
0x14000a00a  push    rdi
0x14000a00b  sub     rsp, 20h
0x14000a00f  mov     rax, [rcx]
0x14000a012  mov     rbx, rcx
0x14000a015  mov     rdx, [rax]
0x14000a018  mov     rax, [rdx+88h]
0x14000a01f  mov     edx, [rax+4]
0x14000a022  mov     cs:dword_14001D904, edx
0x14000a028  mov     rax, [rcx]
0x14000a02b  mov     rdx, [rax]
0x14000a02e  mov     rax, [rdx+88h]
0x14000a035  mov     edx, [rax+8]
0x14000a038  mov     cs:dword_14001D908, edx
0x14000a03e  mov     rax, [rcx]
0x14000a041  mov     rdx, [rax]
0x14000a044  mov     rax, [rdx+88h]
0x14000a04b  mov     rcx, [rax+220h]
0x14000a052  mov     cs:qword_14001D920, rcx
0x14000a059  mov     rax, [rbx]
0x14000a05c  mov     rcx, [rax]
0x14000a05f  mov     rax, [rcx+88h]
0x14000a066  add     rax, 0Ch
0x14000a06a  jz      short loc_14000A083
0x14000a06c  movsd   xmm0, qword ptr [rax]
0x14000a070  movsd   cs:qword_14001D910, xmm0
0x14000a078  mov     eax, [rax+8]
0x14000a07b  mov     cs:dword_14001D918, eax
0x14000a081  jmp     short loc_14000A0A2
0x14000a083  xor     eax, eax
0x14000a085  mov     cs:qword_14001D910, rax
0x14000a08c  mov     cs:dword_14001D918, eax
0x14000a092  call    _errno
0x14000a097  mov     dword ptr [rax], 16h
0x14000a09d  call    _invalid_parameter_noinfo
0x14000a0a2  mov     rax, [rbx]
0x14000a0a5  mov     edi, 2
0x14000a0aa  mov     rcx, [rax]
0x14000a0ad  lea     esi, [rdi+7Eh]
0x14000a0b0  mov     rax, [rcx+88h]
0x14000a0b7  lea     rcx, xmmword_14001C600
0x14000a0be  add     rax, 18h
0x14000a0c2  jz      short loc_14000A116
0x14000a0c4  mov     edx, edi
0x14000a0c6  movups  xmm0, xmmword ptr [rax]
0x14000a0c9  movups  xmmword ptr [rcx], xmm0
0x14000a0cc  movups  xmm1, xmmword ptr [rax+10h]
0x14000a0d0  movups  xmmword ptr [rcx+10h], xmm1
0x14000a0d4  movups  xmm0, xmmword ptr [rax+20h]
0x14000a0d8  movups  xmmword ptr [rcx+20h], xmm0
0x14000a0dc  movups  xmm1, xmmword ptr [rax+30h]
0x14000a0e0  movups  xmmword ptr [rcx+30h], xmm1
0x14000a0e4  movups  xmm0, xmmword ptr [rax+40h]
0x14000a0e8  movups  xmmword ptr [rcx+40h], xmm0
0x14000a0ec  movups  xmm1, xmmword ptr [rax+50h]
0x14000a0f0  movups  xmmword ptr [rcx+50h], xmm1
0x14000a0f4  movups  xmm0, xmmword ptr [rax+60h]
0x14000a0f8  movups  xmmword ptr [rcx+60h], xmm0
0x14000a0fc  add     rcx, rsi
0x14000a0ff  movups  xmm1, xmmword ptr [rax+70h]
0x14000a103  add     rax, rsi
0x14000a106  movups  xmmword ptr [rcx-10h], xmm1
0x14000a10a  sub     rdx, 1
0x14000a10e  jnz     short loc_14000A0C6
0x14000a110  mov     al, [rax]
0x14000a112  mov     [rcx], al
0x14000a114  jmp     short loc_14000A133
0x14000a116  xor     edx, edx
0x14000a118  mov     r8d, 101h
0x14000a11e  call    sub_140002F60
0x14000a123  call    _errno
0x14000a128  mov     dword ptr [rax], 16h
0x14000a12e  call    _invalid_parameter_noinfo
0x14000a133  mov     rax, [rbx]
0x14000a136  mov     rcx, [rax]
0x14000a139  mov     rax, [rcx+88h]
0x14000a140  lea     rcx, xmmword_14001C710
0x14000a147  add     rax, 119h
0x14000a14d  jz      short loc_14000A19B
0x14000a14f  movups  xmm0, xmmword ptr [rax]
0x14000a152  movups  xmmword ptr [rcx], xmm0
0x14000a155  movups  xmm1, xmmword ptr [rax+10h]
0x14000a159  movups  xmmword ptr [rcx+10h], xmm1
0x14000a15d  movups  xmm0, xmmword ptr [rax+20h]
0x14000a161  movups  xmmword ptr [rcx+20h], xmm0
0x14000a165  movups  xmm1, xmmword ptr [rax+30h]
0x14000a169  movups  xmmword ptr [rcx+30h], xmm1
0x14000a16d  movups  xmm0, xmmword ptr [rax+40h]
0x14000a171  movups  xmmword ptr [rcx+40h], xmm0
0x14000a175  movups  xmm1, xmmword ptr [rax+50h]
0x14000a179  movups  xmmword ptr [rcx+50h], xmm1
0x14000a17d  movups  xmm0, xmmword ptr [rax+60h]
0x14000a181  movups  xmmword ptr [rcx+60h], xmm0
0x14000a185  add     rcx, rsi
0x14000a188  movups  xmm1, xmmword ptr [rax+70h]
0x14000a18c  add     rax, rsi
0x14000a18f  movups  xmmword ptr [rcx-10h], xmm1
0x14000a193  sub     rdi, 1
0x14000a197  jnz     short loc_14000A14F
0x14000a199  jmp     short loc_14000A1B8
0x14000a19b  xor     edx, edx
0x14000a19d  mov     r8d, 100h
0x14000a1a3  call    sub_140002F60
0x14000a1a8  call    _errno
0x14000a1ad  mov     dword ptr [rax], 16h
0x14000a1b3  call    _invalid_parameter_noinfo
0x14000a1b8  mov     rcx, cs:off_14001C4F8
0x14000a1bf  or      eax, 0FFFFFFFFh
0x14000a1c2  lock xadd [rcx], eax
0x14000a1c6  cmp     eax, 1
0x14000a1c9  jnz     short loc_14000A1E3
0x14000a1cb  mov     rcx, cs:off_14001C4F8; Block
0x14000a1d2  lea     rax, unk_14001C2D0
0x14000a1d9  cmp     rcx, rax
0x14000a1dc  jz      short loc_14000A1E3
0x14000a1de  call    _free_base
0x14000a1e3  mov     rax, [rbx]
0x14000a1e6  mov     rcx, [rax]
0x14000a1e9  mov     rax, [rcx+88h]
0x14000a1f0  mov     cs:off_14001C4F8, rax
0x14000a1f7  mov     rax, [rbx]
0x14000a1fa  mov     rcx, [rax]
0x14000a1fd  mov     rax, [rcx+88h]
0x14000a204  lock inc dword ptr [rax]
0x14000a207  mov     rbx, [rsp+28h+arg_0]
0x14000a20c  mov     rsi, [rsp+28h+arg_8]
0x14000a211  add     rsp, 20h
0x14000a215  pop     rdi
0x14000a216  retn

// ===== ?getSystemCP@@YAHH@Z @ 0x14000a218 =====

0x14000a218  push    rbx
0x14000a21a  sub     rsp, 40h
0x14000a21e  mov     ebx, ecx
0x14000a220  xor     edx, edx; struct __crt_locale_pointers *
0x14000a222  lea     rcx, [rsp+48h+var_28]; this
0x14000a227  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000a22c  and     cs:dword_14001D91C, 0
0x14000a233  cmp     ebx, 0FFFFFFFEh
0x14000a236  jnz     short loc_14000A24A
0x14000a238  mov     cs:dword_14001D91C, 1
0x14000a242  call    cs:GetOEMCP; KERNEL32
0x14000a248  jmp     short loc_14000A25F
0x14000a24a  cmp     ebx, 0FFFFFFFDh
0x14000a24d  jnz     short loc_14000A263
0x14000a24f  mov     cs:dword_14001D91C, 1
0x14000a259  call    cs:GetACP; KERNEL32
0x14000a25f  mov     ebx, eax
0x14000a261  jmp     short loc_14000A27A
0x14000a263  cmp     ebx, 0FFFFFFFCh
0x14000a266  jnz     short loc_14000A27A
0x14000a268  mov     rax, [rsp+48h+var_20]
0x14000a26d  mov     cs:dword_14001D91C, 1
0x14000a277  mov     ebx, [rax+0Ch]
0x14000a27a  cmp     [rsp+48h+var_10], 0
0x14000a27f  jz      short loc_14000A28D
0x14000a281  mov     rcx, [rsp+48h+var_28]
0x14000a286  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x14000a28d  mov     eax, ebx
0x14000a28f  add     rsp, 40h
0x14000a293  pop     rbx
0x14000a294  retn

// ===== ?setSBCS@@YAXPEAU__crt_multibyte_data@@@Z @ 0x14000a298 =====

0x14000a298  mov     [rsp+arg_0], rbx
0x14000a29d  mov     [rsp+arg_8], rbp
0x14000a2a2  mov     [rsp+arg_10], rsi
0x14000a2a7  push    rdi
0x14000a2a8  sub     rsp, 20h
0x14000a2ac  lea     rbx, [rcx+18h]
0x14000a2b0  mov     rsi, rcx
0x14000a2b3  mov     ebp, 101h
0x14000a2b8  mov     rcx, rbx
0x14000a2bb  mov     r8d, ebp
0x14000a2be  xor     edx, edx
0x14000a2c0  call    sub_140002F60
0x14000a2c5  xor     eax, eax
0x14000a2c7  lea     rdi, [rsi+0Ch]
0x14000a2cb  mov     [rsi+4], rax
0x14000a2cf  mov     ecx, 6
0x14000a2d4  mov     [rsi+220h], rax
0x14000a2db  movzx   eax, ax
0x14000a2de  rep stosw
0x14000a2e1  lea     rdi, unk_14001C2D0
0x14000a2e8  sub     rdi, rsi
0x14000a2eb  mov     al, [rdi+rbx]
0x14000a2ee  mov     [rbx], al
0x14000a2f0  inc     rbx
0x14000a2f3  sub     rbp, 1
0x14000a2f7  jnz     short loc_14000A2EB
0x14000a2f9  lea     rcx, [rsi+119h]
0x14000a300  mov     edx, 100h
0x14000a305  mov     al, [rcx+rdi]
0x14000a308  mov     [rcx], al
0x14000a30a  inc     rcx
0x14000a30d  sub     rdx, 1
0x14000a311  jnz     short loc_14000A305
0x14000a313  mov     rbx, [rsp+28h+arg_0]
0x14000a318  mov     rbp, [rsp+28h+arg_8]
0x14000a31d  mov     rsi, [rsp+28h+arg_10]
0x14000a322  add     rsp, 20h
0x14000a326  pop     rdi
0x14000a327  retn

// ===== ?setSBUpLow@@YAXPEAU__crt_multibyte_data@@@Z @ 0x14000a328 =====

0x14000a328  mov     [rsp-8+arg_8], rbx
0x14000a32d  mov     [rsp-8+arg_10], rdi
0x14000a332  push    rbp
0x14000a333  lea     rbp, [rsp-680h]
0x14000a33b  sub     rsp, 780h
0x14000a342  mov     rax, cs:__security_cookie
0x14000a349  xor     rax, rsp
0x14000a34c  mov     [rbp+680h+var_10], rax
0x14000a353  mov     rdi, rcx
0x14000a356  lea     rdx, [rsp+780h+CPInfo]; lpCPInfo
0x14000a35b  mov     ecx, [rcx+4]; CodePage
0x14000a35e  call    cs:GetCPInfo; KERNEL32
0x14000a364  mov     ebx, 100h
0x14000a369  test    eax, eax
0x14000a36b  jz      loc_14000A4A7
0x14000a371  xor     eax, eax
0x14000a373  lea     rcx, [rsp+780h+MultiByteStr]
0x14000a378  mov     [rcx], al
0x14000a37a  inc     eax
0x14000a37c  inc     rcx
0x14000a37f  cmp     eax, ebx
0x14000a381  jb      short loc_14000A378
0x14000a383  mov     al, [rsp+780h+CPInfo.LeadByte]
0x14000a387  lea     rdx, [rsp+780h+CPInfo.LeadByte]
0x14000a38c  mov     [rsp+780h+MultiByteStr], 20h ; ' '
0x14000a391  jmp     short loc_14000A3B5
0x14000a393  movzx   r8d, byte ptr [rdx+1]
0x14000a398  movzx   ecx, al
0x14000a39b  jmp     short loc_14000A3AA
0x14000a39d  cmp     ecx, ebx
0x14000a39f  jnb     short loc_14000A3AF
0x14000a3a1  mov     eax, ecx
0x14000a3a3  mov     [rsp+rcx+780h+MultiByteStr], 20h ; ' '
0x14000a3a8  inc     ecx
0x14000a3aa  cmp     ecx, r8d
0x14000a3ad  jbe     short loc_14000A39D
0x14000a3af  add     rdx, 2
0x14000a3b3  mov     al, [rdx]
0x14000a3b5  test    al, al
0x14000a3b7  jnz     short loc_14000A393
0x14000a3b9  mov     eax, [rdi+4]
0x14000a3bc  lea     r8, [rsp+780h+MultiByteStr]; lpMultiByteStr
0x14000a3c1  and     [rsp+780h+var_750], 0
0x14000a3c6  mov     r9d, ebx; cbMultiByte
0x14000a3c9  mov     [rsp+780h+CodePage], eax; CodePage
0x14000a3cd  mov     edx, 1; dwInfoType
0x14000a3d2  lea     rax, [rbp+680h+CharType]
0x14000a3d9  xor     ecx, ecx; struct __crt_locale_pointers *
0x14000a3db  mov     [rsp+780h+lpCharType], rax; lpCharType
0x14000a3e0  call    __acrt_GetStringTypeA
0x14000a3e5  and     [rsp+780h+var_740], 0
0x14000a3ea  lea     r9, [rsp+780h+MultiByteStr]; char *
0x14000a3ef  mov     eax, [rdi+4]
0x14000a3f2  mov     r8d, ebx; unsigned int
0x14000a3f5  mov     rdx, [rdi+220h]; wchar_t *
0x14000a3fc  xor     ecx, ecx; struct __crt_locale_pointers *
0x14000a3fe  mov     [rsp+780h+var_748], eax; int
0x14000a402  lea     rax, [rbp+680h+var_610]
0x14000a406  mov     [rsp+780h+var_750], ebx; int
0x14000a40a  mov     qword ptr [rsp+780h+CodePage], rax; char *
0x14000a40f  mov     dword ptr [rsp+780h+lpCharType], ebx; int
0x14000a413  call    __acrt_LCMapStringA
0x14000a418  and     [rsp+780h+var_740], 0
0x14000a41d  lea     r9, [rsp+780h+MultiByteStr]; char *
0x14000a422  mov     eax, [rdi+4]
0x14000a425  mov     r8d, 200h; unsigned int
0x14000a42b  mov     rdx, [rdi+220h]; wchar_t *
0x14000a432  xor     ecx, ecx; struct __crt_locale_pointers *
0x14000a434  mov     [rsp+780h+var_748], eax; int
0x14000a438  lea     rax, [rbp+680h+var_510]
0x14000a43f  mov     [rsp+780h+var_750], ebx; int
0x14000a443  mov     qword ptr [rsp+780h+CodePage], rax; char *
0x14000a448  mov     dword ptr [rsp+780h+lpCharType], ebx; int
0x14000a44c  call    __acrt_LCMapStringA
0x14000a451  lea     r8, [rbp+680h+var_610]
0x14000a455  sub     r8, rdi
0x14000a458  lea     r9, [rbp+680h+var_510]
0x14000a45f  sub     r9, rdi
0x14000a462  lea     rdx, [rbp+680h+CharType]
0x14000a469  lea     rcx, [rdi+19h]
0x14000a46d  test    byte ptr [rdx], 1
0x14000a470  jz      short loc_14000A47C
0x14000a472  or      byte ptr [rcx], 10h
0x14000a475  mov     al, [r8+rcx-19h]
0x14000a47a  jmp     short loc_14000A489
0x14000a47c  test    byte ptr [rdx], 2
0x14000a47f  jz      short loc_14000A491
0x14000a481  or      byte ptr [rcx], 20h
0x14000a484  mov     al, [r9+rcx-19h]
0x14000a489  mov     [rcx+100h], al
0x14000a48f  jmp     short loc_14000A498
0x14000a491  mov     byte ptr [rcx+100h], 0
0x14000a498  inc     rcx
0x14000a49b  add     rdx, 2
0x14000a49f  sub     rbx, 1
0x14000a4a3  jnz     short loc_14000A46D
0x14000a4a5  jmp     short loc_14000A4E6
0x14000a4a7  xor     edx, edx
0x14000a4a9  lea     rcx, [rdi+19h]
0x14000a4ad  lea     r8d, [rdx-61h]
0x14000a4b1  lea     eax, [r8+20h]
0x14000a4b5  cmp     eax, 19h
0x14000a4b8  ja      short loc_14000A4C2
0x14000a4ba  or      byte ptr [rcx], 10h
0x14000a4bd  lea     eax, [rdx+20h]
0x14000a4c0  jmp     short loc_14000A4CE
0x14000a4c2  cmp     r8d, 19h
0x14000a4c6  ja      short loc_14000A4D6
0x14000a4c8  or      byte ptr [rcx], 20h
0x14000a4cb  lea     eax, [rdx-20h]
0x14000a4ce  mov     [rcx+100h], al
0x14000a4d4  jmp     short loc_14000A4DD
0x14000a4d6  mov     byte ptr [rcx+100h], 0
0x14000a4dd  inc     edx
0x14000a4df  inc     rcx
0x14000a4e2  cmp     edx, ebx
0x14000a4e4  jb      short loc_14000A4AD
0x14000a4e6  mov     rcx, [rbp+680h+var_10]
0x14000a4ed  xor     rcx, rsp; StackCookie
0x14000a4f0  call    __security_check_cookie
0x14000a4f5  lea     r11, [rsp+780h+var_s0]
0x14000a4fd  mov     rbx, [r11+18h]
0x14000a501  mov     rdi, [r11+20h]
0x14000a505  mov     rsp, r11
0x14000a508  pop     rbp
0x14000a509  retn

// ===== ?setmbcp_internal@@YAHH_N@Z @ 0x14000a50c =====

0x14000a50c  mov     [rsp-18h+arg_0], rbx
0x14000a511  push    rbp
0x14000a512  push    rsi
0x14000a513  push    rdi
0x14000a514  mov     rbp, rsp
0x14000a517  sub     rsp, 40h
0x14000a51b  mov     sil, dl
0x14000a51e  mov     ebx, ecx
0x14000a520  call    __acrt_getptd
0x14000a525  mov     [rbp+var_18], rax
0x14000a529  call    __acrt_update_thread_multibyte_data
0x14000a52e  mov     ecx, ebx; int
0x14000a530  call    ?getSystemCP@@YAHH@Z
0x14000a535  mov     rcx, [rbp+var_18]
0x14000a539  mov     edi, eax
0x14000a53b  mov     r8, [rcx+88h]
0x14000a542  cmp     eax, [r8+4]
0x14000a546  jnz     short loc_14000A54F
0x14000a548  xor     eax, eax
0x14000a54a  jmp     loc_14000A607
0x14000a54f  mov     ecx, 228h; Size
0x14000a554  call    _malloc_base
0x14000a559  mov     rbx, rax
0x14000a55c  test    rax, rax
0x14000a55f  jz      loc_14000A5FA
0x14000a565  mov     rax, [rbp+var_18]
0x14000a569  mov     edx, 4
0x14000a56e  mov     rcx, rbx
0x14000a571  mov     rax, [rax+88h]
0x14000a578  lea     r8d, [rdx+7Ch]
0x14000a57c  movups  xmm0, xmmword ptr [rax]
0x14000a57f  movups  xmmword ptr [rcx], xmm0
0x14000a582  movups  xmm1, xmmword ptr [rax+10h]
0x14000a586  movups  xmmword ptr [rcx+10h], xmm1
0x14000a58a  movups  xmm0, xmmword ptr [rax+20h]
0x14000a58e  movups  xmmword ptr [rcx+20h], xmm0
0x14000a592  movups  xmm1, xmmword ptr [rax+30h]
0x14000a596  movups  xmmword ptr [rcx+30h], xmm1
0x14000a59a  movups  xmm0, xmmword ptr [rax+40h]
0x14000a59e  movups  xmmword ptr [rcx+40h], xmm0
0x14000a5a2  movups  xmm1, xmmword ptr [rax+50h]
0x14000a5a6  movups  xmmword ptr [rcx+50h], xmm1
0x14000a5aa  movups  xmm0, xmmword ptr [rax+60h]
0x14000a5ae  movups  xmmword ptr [rcx+60h], xmm0
0x14000a5b2  add     rcx, r8
0x14000a5b5  movups  xmm1, xmmword ptr [rax+70h]
0x14000a5b9  add     rax, r8
0x14000a5bc  movups  xmmword ptr [rcx-10h], xmm1
0x14000a5c0  sub     rdx, 1
0x14000a5c4  jnz     short loc_14000A57C
0x14000a5c6  movups  xmm0, xmmword ptr [rax]
0x14000a5c9  movups  xmmword ptr [rcx], xmm0
0x14000a5cc  movups  xmm1, xmmword ptr [rax+10h]
0x14000a5d0  movups  xmmword ptr [rcx+10h], xmm1
0x14000a5d4  mov     rax, [rax+20h]
0x14000a5d8  mov     [rcx+20h], rax
0x14000a5dc  mov     ecx, edi
0x14000a5de  and     [rbx], edx
0x14000a5e0  mov     rdx, rbx
0x14000a5e3  call    _setmbcp_nolock
0x14000a5e8  mov     edi, eax
0x14000a5ea  cmp     eax, 0FFFFFFFFh
0x14000a5ed  jnz     short loc_14000A614
0x14000a5ef  call    _errno
0x14000a5f4  mov     dword ptr [rax], 16h
0x14000a5fa  or      edi, 0FFFFFFFFh
0x14000a5fd  mov     rcx, rbx; Block
0x14000a600  call    _free_base
0x14000a605  mov     eax, edi
0x14000a607  mov     rbx, [rsp+40h+arg_0]
0x14000a60c  add     rsp, 40h
0x14000a610  pop     rdi
0x14000a611  pop     rsi
0x14000a612  pop     rbp
0x14000a613  retn
0x14000a614  test    sil, sil
0x14000a617  jnz     short loc_14000A61E
0x14000a619  call    __acrt_set_locale_changed
0x14000a61e  mov     rax, [rbp+var_18]
0x14000a622  mov     rcx, [rax+88h]
0x14000a629  or      eax, 0FFFFFFFFh
0x14000a62c  lock xadd [rcx], eax
0x14000a630  cmp     eax, 1
0x14000a633  jnz     short loc_14000A651
0x14000a635  mov     rax, [rbp+var_18]
0x14000a639  mov     rcx, [rax+88h]; Block
0x14000a640  lea     rax, unk_14001C2D0
0x14000a647  cmp     rcx, rax
0x14000a64a  jz      short loc_14000A651
0x14000a64c  call    _free_base
0x14000a651  mov     dword ptr [rbx], 1
0x14000a657  mov     rcx, rbx
0x14000a65a  mov     rax, [rbp+var_18]
0x14000a65e  xor     ebx, ebx
0x14000a660  mov     [rax+88h], rcx
0x14000a667  mov     rax, [rbp+var_18]
0x14000a66b  test    byte ptr [rax+3A8h], 2
0x14000a672  jnz     short loc_14000A5FD
0x14000a674  test    byte ptr cs:dword_14001C8C0, 1
0x14000a67b  jnz     short loc_14000A5FD
0x14000a67d  lea     rax, [rbp+var_18]
0x14000a681  mov     [rbp+var_10], rax
0x14000a685  lea     r9, [rbp+arg_18]
0x14000a689  lea     eax, [rbx+5]
0x14000a68c  lea     r8, [rbp+var_10]
0x14000a690  mov     [rbp+arg_18], eax
0x14000a693  lea     rdx, [rbp+var_20]
0x14000a697  mov     [rbp+var_20], eax
0x14000a69a  lea     rcx, [rbp+arg_10]
0x14000a69e  call    ??$?RV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@V_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@$$QEAV_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@Z
0x14000a6a3  mov     rax, cs:off_14001C2C0
0x14000a6aa  test    sil, sil
0x14000a6ad  cmovnz  rax, cs:off_14001C4F8
0x14000a6b5  mov     cs:off_14001C2C0, rax
0x14000a6bc  jmp     loc_14000A5FD

// ===== __acrt_initialize_multibyte @ 0x14000a6c4 =====

0x14000a6c4  sub     rsp, 28h
0x14000a6c8  cmp     cs:byte_14001D928, 0
0x14000a6cf  jnz     short loc_14000A6E4
0x14000a6d1  mov     dl, 1; bool
0x14000a6d3  mov     ecx, 0FFFFFFFDh; int
0x14000a6d8  call    ?setmbcp_internal@@YAHH_N@Z
0x14000a6dd  mov     cs:byte_14001D928, 1
0x14000a6e4  mov     al, 1
0x14000a6e6  add     rsp, 28h
0x14000a6ea  retn

// ===== __acrt_update_thread_multibyte_data @ 0x14000a6ec =====

0x14000a6ec  mov     [rsp+arg_8], rbx
0x14000a6f1  push    rdi
0x14000a6f2  sub     rsp, 20h
0x14000a6f6  call    __acrt_getptd
0x14000a6fb  mov     rdi, rax
0x14000a6fe  mov     ecx, cs:dword_14001C8C0
0x14000a704  test    [rax+3A8h], ecx
0x14000a70a  jz      short loc_14000A71F
0x14000a70c  cmp     qword ptr [rax+90h], 0
0x14000a714  jz      short loc_14000A71F
0x14000a716  mov     rbx, [rax+88h]
0x14000a71d  jmp     short loc_14000A792
0x14000a71f  mov     ecx, 5
0x14000a724  call    sub_14000AB5C
0x14000a729  nop
0x14000a72a  mov     rbx, [rdi+88h]
0x14000a731  mov     [rsp+28h+Block], rbx
0x14000a736  cmp     rbx, cs:off_14001C4F8
0x14000a73d  jz      short loc_14000A788
0x14000a73f  test    rbx, rbx
0x14000a742  jz      short loc_14000A766
0x14000a744  or      eax, 0FFFFFFFFh
0x14000a747  lock xadd [rbx], eax
0x14000a74b  cmp     eax, 1
0x14000a74e  jnz     short loc_14000A766
0x14000a750  lea     rax, unk_14001C2D0
0x14000a757  mov     rcx, [rsp+28h+Block]; Block
0x14000a75c  cmp     rcx, rax
0x14000a75f  jz      short loc_14000A766
0x14000a761  call    _free_base
0x14000a766  mov     rax, cs:off_14001C4F8
0x14000a76d  mov     [rdi+88h], rax
0x14000a774  mov     rax, cs:off_14001C4F8
0x14000a77b  mov     [rsp+28h+Block], rax
0x14000a780  lock inc dword ptr [rax]
0x14000a783  mov     rbx, [rsp+28h+Block]
0x14000a788  mov     ecx, 5
0x14000a78d  call    sub_14000ABB0
0x14000a792  test    rbx, rbx
0x14000a795  jnz     short loc_14000A79D
0x14000a797  call    abort
0x14000a79d  mov     rax, rbx
0x14000a7a0  mov     rbx, [rsp+28h+arg_8]
0x14000a7a5  add     rsp, 20h
0x14000a7a9  pop     rdi
0x14000a7aa  retn
0x140010ad7  push    rbp
0x140010ad9  sub     rsp, 20h
0x140010add  mov     rbp, rdx
0x140010ae0  mov     ecx, 5
0x140010ae5  add     rsp, 20h
0x140010ae9  pop     rbp
0x140010aea  jmp     sub_14000ABB0

// ===== _setmbcp_nolock @ 0x14000a7ac =====

0x14000a7ac  mov     [rsp+arg_10], rbx
0x14000a7b1  mov     [rsp+arg_18], rbp
0x14000a7b6  push    rsi
0x14000a7b7  push    rdi
0x14000a7b8  push    r12
0x14000a7ba  push    r14
0x14000a7bc  push    r15
0x14000a7be  sub     rsp, 40h
0x14000a7c2  mov     rax, cs:__security_cookie
0x14000a7c9  xor     rax, rsp
0x14000a7cc  mov     [rsp+68h+var_30], rax
0x14000a7d1  mov     rbx, rdx
0x14000a7d4  call    ?getSystemCP@@YAHH@Z
0x14000a7d9  xor     esi, esi
0x14000a7db  mov     edi, eax
0x14000a7dd  test    eax, eax
0x14000a7df  jnz     short loc_14000A7EE
0x14000a7e1  mov     rcx, rbx; struct __crt_multibyte_data *
0x14000a7e4  call    ?setSBCS@@YAXPEAU__crt_multibyte_data@@@Z
0x14000a7e9  jmp     loc_14000AA2B
0x14000a7ee  lea     r12, unk_14001C510
0x14000a7f5  mov     ebp, esi
0x14000a7f7  mov     rax, r12
0x14000a7fa  mov     r15d, 1
0x14000a800  cmp     [rax], edi
0x14000a802  jz      loc_14000A938
0x14000a808  add     ebp, r15d
0x14000a80b  add     rax, 30h ; '0'
0x14000a80f  cmp     ebp, 5
0x14000a812  jb      short loc_14000A800
0x14000a814  lea     eax, [rdi-0FDE8h]
0x14000a81a  cmp     eax, r15d
0x14000a81d  jbe     loc_14000A930
0x14000a823  movzx   ecx, di; CodePage
0x14000a826  call    cs:IsValidCodePage; KERNEL32
0x14000a82c  test    eax, eax
0x14000a82e  jz      loc_14000A930
0x14000a834  lea     rdx, [rsp+68h+CPInfo]; lpCPInfo
0x14000a839  mov     ecx, edi; CodePage
0x14000a83b  call    cs:GetCPInfo; KERNEL32
0x14000a841  test    eax, eax
0x14000a843  jz      loc_14000A924
0x14000a849  lea     rcx, [rbx+18h]
0x14000a84d  xor     edx, edx
0x14000a84f  mov     r8d, 101h
0x14000a855  call    sub_140002F60
0x14000a85a  mov     [rbx+4], edi
0x14000a85d  mov     [rbx+220h], rsi
0x14000a864  cmp     [rsp+68h+CPInfo.MaxCharSize], r15d
0x14000a869  jbe     loc_14000A90D
0x14000a86f  lea     rcx, [rsp+68h+CPInfo.LeadByte]
0x14000a874  cmp     [rsp+68h+CPInfo.LeadByte], sil
0x14000a879  jz      short loc_14000A8AB
0x14000a87b  cmp     [rcx+1], sil
0x14000a87f  jz      short loc_14000A8AB
0x14000a881  movzx   eax, byte ptr [rcx+1]
0x14000a885  movzx   edx, byte ptr [rcx]
0x14000a888  cmp     edx, eax
0x14000a88a  ja      short loc_14000A8A2
0x14000a88c  sub     eax, edx
0x14000a88e  lea     edi, [rdx+1]
0x14000a891  lea     edx, [r15+rax]
0x14000a895  or      byte ptr [rdi+rbx+18h], 4
0x14000a89a  add     edi, r15d
0x14000a89d  sub     rdx, r15
0x14000a8a0  jnz     short loc_14000A895
0x14000a8a2  add     rcx, 2
0x14000a8a6  cmp     [rcx], sil
0x14000a8a9  jnz     short loc_14000A87B
0x14000a8ab  lea     rax, [rbx+1Ah]
0x14000a8af  mov     ecx, 0FEh
0x14000a8b4  or      byte ptr [rax], 8
0x14000a8b7  add     rax, r15
0x14000a8ba  sub     rcx, r15
0x14000a8bd  jnz     short loc_14000A8B4
0x14000a8bf  mov     ecx, [rbx+4]
0x14000a8c2  sub     ecx, 3A4h
0x14000a8c8  jz      short loc_14000A8F9
0x14000a8ca  sub     ecx, 4
0x14000a8cd  jz      short loc_14000A8F0
0x14000a8cf  sub     ecx, 0Dh
0x14000a8d2  jz      short loc_14000A8E7
0x14000a8d4  cmp     ecx, r15d
0x14000a8d7  jz      short loc_14000A8DE
0x14000a8d9  mov     rax, rsi
0x14000a8dc  jmp     short loc_14000A900
0x14000a8de  mov     rax, cs:off_1400130A0
0x14000a8e5  jmp     short loc_14000A900
0x14000a8e7  mov     rax, cs:off_140013098
0x14000a8ee  jmp     short loc_14000A900
0x14000a8f0  mov     rax, cs:off_140013090
0x14000a8f7  jmp     short loc_14000A900
0x14000a8f9  mov     rax, cs:off_140013088
0x14000a900  mov     [rbx+220h], rax
0x14000a907  mov     [rbx+8], r15d
0x14000a90b  jmp     short loc_14000A910
0x14000a90d  mov     [rbx+8], esi
0x14000a910  lea     rdi, [rbx+0Ch]
0x14000a914  movzx   eax, si
0x14000a917  mov     ecx, 6
0x14000a91c  rep stosw
0x14000a91f  jmp     loc_14000AA23
0x14000a924  cmp     cs:dword_14001D91C, esi
0x14000a92a  jnz     loc_14000A7E1
0x14000a930  or      eax, 0FFFFFFFFh
0x14000a933  jmp     loc_14000AA2D
0x14000a938  lea     rcx, [rbx+18h]
0x14000a93c  xor     edx, edx
0x14000a93e  mov     r8d, 101h
0x14000a944  call    sub_140002F60
0x14000a949  mov     eax, ebp
0x14000a94b  lea     r9, [r12+10h]
0x14000a950  lea     r14, unk_14001C500
0x14000a957  mov     ebp, 4
0x14000a95c  lea     r11, [rax+rax*2]
0x14000a960  shl     r11, 4
0x14000a964  add     r9, r11
0x14000a967  mov     rdx, r9
0x14000a96a  cmp     [r9], sil
0x14000a96d  jz      short loc_14000A9AF
0x14000a96f  cmp     [rdx+1], sil
0x14000a973  jz      short loc_14000A9AF
0x14000a975  movzx   r8d, byte ptr [rdx]
0x14000a979  movzx   eax, byte ptr [rdx+1]
0x14000a97d  cmp     r8d, eax
0x14000a980  ja      short loc_14000A9A6
0x14000a982  lea     r10d, [r8+1]
0x14000a986  cmp     r10d, 101h
0x14000a98d  jnb     short loc_14000A9A6
0x14000a98f  mov     al, [r14]
0x14000a992  add     r8d, r15d
0x14000a995  or      [r10+rbx+18h], al
0x14000a99a  add     r10d, r15d
0x14000a99d  movzx   eax, byte ptr [rdx+1]
0x14000a9a1  cmp     r8d, eax
0x14000a9a4  jbe     short loc_14000A986
0x14000a9a6  add     rdx, 2
0x14000a9aa  cmp     [rdx], sil
0x14000a9ad  jnz     short loc_14000A96F
0x14000a9af  add     r9, 8
0x14000a9b3  add     r14, r15
0x14000a9b6  sub     rbp, r15
0x14000a9b9  jnz     short loc_14000A967
0x14000a9bb  mov     [rbx+4], edi
0x14000a9be  mov     [rbx+8], r15d
0x14000a9c2  sub     edi, 3A4h
0x14000a9c8  jz      short loc_14000A9F4
0x14000a9ca  sub     edi, 4
0x14000a9cd  jz      short loc_14000A9EB
0x14000a9cf  sub     edi, 0Dh
0x14000a9d2  jz      short loc_14000A9E2
0x14000a9d4  cmp     edi, r15d
0x14000a9d7  jnz     short loc_14000A9FB
0x14000a9d9  mov     rsi, cs:off_1400130A0
0x14000a9e0  jmp     short loc_14000A9FB
0x14000a9e2  mov     rsi, cs:off_140013098
0x14000a9e9  jmp     short loc_14000A9FB
0x14000a9eb  mov     rsi, cs:off_140013090
0x14000a9f2  jmp     short loc_14000A9FB
0x14000a9f4  mov     rsi, cs:off_140013088
0x14000a9fb  sub     r11, rbx
0x14000a9fe  mov     [rbx+220h], rsi
0x14000aa05  lea     rcx, [rbx+0Ch]
0x14000aa09  mov     edx, 6
0x14000aa0e  lea     rdi, [r11+r12]
0x14000aa12  movzx   eax, word ptr [rdi+rcx-8]
0x14000aa17  mov     [rcx], ax
0x14000aa1a  lea     rcx, [rcx+2]
0x14000aa1e  sub     rdx, r15
0x14000aa21  jnz     short loc_14000AA12
0x14000aa23  mov     rcx, rbx; struct __crt_multibyte_data *
0x14000aa26  call    ?setSBUpLow@@YAXPEAU__crt_multibyte_data@@@Z
0x14000aa2b  xor     eax, eax
0x14000aa2d  mov     rcx, [rsp+68h+var_30]
0x14000aa32  xor     rcx, rsp; StackCookie
0x14000aa35  call    __security_check_cookie
0x14000aa3a  lea     r11, [rsp+68h+var_28]
0x14000aa3f  mov     rbx, [r11+40h]
0x14000aa43  mov     rbp, [r11+48h]
0x14000aa47  mov     rsp, r11
0x14000aa4a  pop     r15
0x14000aa4c  pop     r14
0x14000aa4e  pop     r12
0x14000aa50  pop     rdi
0x14000aa51  pop     rsi
0x14000aa52  retn

// ===== __acrt_initialize_command_line @ 0x14000aa54 =====

0x14000aa54  sub     rsp, 28h
0x14000aa58  call    cs:GetCommandLineA; KERNEL32
0x14000aa5e  mov     cs:qword_14001D940, rax
0x14000aa65  call    cs:GetCommandLineW; KERNEL32
0x14000aa6b  mov     cs:qword_14001D948, rax
0x14000aa72  mov     al, 1
0x14000aa74  add     rsp, 28h
0x14000aa78  retn

// ===== __dcrt_get_wide_environment_from_os @ 0x14000aa7c =====

0x14000aa7c  mov     [rsp+arg_0], rbx
0x14000aa81  mov     [rsp+arg_8], rbp
0x14000aa86  mov     [rsp+arg_10], rsi
0x14000aa8b  push    rdi
0x14000aa8c  sub     rsp, 20h
0x14000aa90  call    cs:GetEnvironmentStringsW; KERNEL32
0x14000aa96  xor     esi, esi
0x14000aa98  mov     rbx, rax
0x14000aa9b  test    rax, rax
0x14000aa9e  jz      short loc_14000AAFB
0x14000aaa0  jmp     short loc_14000AAB7
0x14000aaa2  or      rcx, 0FFFFFFFFFFFFFFFFh
0x14000aaa6  inc     rcx
0x14000aaa9  cmp     [rax+rcx*2], si
0x14000aaad  jnz     short loc_14000AAA6
0x14000aaaf  lea     rax, [rax+rcx*2]
0x14000aab3  add     rax, 2
0x14000aab7  cmp     [rax], si
0x14000aaba  jnz     short loc_14000AAA2
0x14000aabc  sub     rax, rbx
0x14000aabf  add     rax, 2
0x14000aac3  sar     rax, 1
0x14000aac6  lea     rbp, [rax+rax]
0x14000aaca  mov     rcx, rbp; Size
0x14000aacd  call    _malloc_base
0x14000aad2  mov     rdi, rax
0x14000aad5  test    rax, rax
0x14000aad8  jz      short loc_14000AAEB
0x14000aada  mov     r8, rbp
0x14000aadd  mov     rdx, rbx
0x14000aae0  mov     rcx, rax
0x14000aae3  call    sub_1400036D0
0x14000aae8  mov     rsi, rdi
0x14000aaeb  xor     ecx, ecx; Block
0x14000aaed  call    _free_base
0x14000aaf2  mov     rcx, rbx; penv
0x14000aaf5  call    cs:FreeEnvironmentStringsW; KERNEL32
0x14000aafb  mov     rbx, [rsp+28h+arg_0]
0x14000ab00  mov     rax, rsi
0x14000ab03  mov     rsi, [rsp+28h+arg_10]
0x14000ab08  mov     rbp, [rsp+28h+arg_8]
0x14000ab0d  add     rsp, 20h
0x14000ab11  pop     rdi
0x14000ab12  retn

// ===== __vcrt_initialize_locks_0 @ 0x14000ab14 =====

0x14000ab14  push    rbx
0x14000ab16  sub     rsp, 20h
0x14000ab1a  xor     ebx, ebx
0x14000ab1c  lea     rdx, unk_14001D960
0x14000ab23  xor     r8d, r8d
0x14000ab26  lea     rcx, [rbx+rbx*4]
0x14000ab2a  lea     rcx, [rdx+rcx*8]; lpCriticalSection
0x14000ab2e  mov     edx, 0FA0h; dwSpinCount
0x14000ab33  call    __acrt_InitializeCriticalSectionEx
0x14000ab38  test    eax, eax
0x14000ab3a  jz      short loc_14000AB4D
0x14000ab3c  inc     cs:dword_14001DB68
0x14000ab42  inc     ebx
0x14000ab44  cmp     ebx, 0Dh
0x14000ab47  jb      short loc_14000AB1C
0x14000ab49  mov     al, 1
0x14000ab4b  jmp     short loc_14000AB56
0x14000ab4d  xor     ecx, ecx
0x14000ab4f  call    __vcrt_uninitialize_locks_0
0x14000ab54  xor     al, al
0x14000ab56  add     rsp, 20h
0x14000ab5a  pop     rbx
0x14000ab5b  retn

// ===== sub_14000AB5C @ 0x14000ab5c =====

0x14000ab5c  movsxd  rax, ecx
0x14000ab5f  lea     rcx, [rax+rax*4]
0x14000ab63  lea     rax, unk_14001D960
0x14000ab6a  lea     rcx, [rax+rcx*8]
0x14000ab6e  jmp     cs:EnterCriticalSection; KERNEL32

// ===== __vcrt_uninitialize_locks_0 @ 0x14000ab78 =====

0x14000ab78  push    rbx
0x14000ab7a  sub     rsp, 20h
0x14000ab7e  mov     ebx, cs:dword_14001DB68
0x14000ab84  jmp     short loc_14000ABA3
0x14000ab86  lea     rax, unk_14001D960
0x14000ab8d  dec     ebx
0x14000ab8f  lea     rcx, [rbx+rbx*4]
0x14000ab93  lea     rcx, [rax+rcx*8]; lpCriticalSection
0x14000ab97  call    cs:DeleteCriticalSection; KERNEL32
0x14000ab9d  dec     cs:dword_14001DB68
0x14000aba3  test    ebx, ebx
0x14000aba5  jnz     short loc_14000AB86
0x14000aba7  mov     al, 1
0x14000aba9  add     rsp, 20h
0x14000abad  pop     rbx
0x14000abae  retn

// ===== sub_14000ABB0 @ 0x14000abb0 =====

0x14000abb0  movsxd  rax, ecx
0x14000abb3  lea     rcx, [rax+rax*4]
0x14000abb7  lea     rax, unk_14001D960
0x14000abbe  lea     rcx, [rax+rcx*8]
0x14000abc2  jmp     cs:LeaveCriticalSection; KERNEL32

// ===== __acrt_lowio_create_handle_array @ 0x14000abcc =====

0x14000abcc  mov     [rsp+arg_0], rbx
0x14000abd1  mov     [rsp+arg_8], rbp
0x14000abd6  mov     [rsp+arg_10], rsi
0x14000abdb  push    rdi
0x14000abdc  sub     rsp, 20h
0x14000abe0  mov     edx, 40h ; '@'; Size
0x14000abe5  mov     ecx, edx; Count
0x14000abe7  call    _calloc_base
0x14000abec  xor     esi, esi
0x14000abee  mov     rbx, rax
0x14000abf1  test    rax, rax
0x14000abf4  jz      short loc_14000AC42
0x14000abf6  lea     rbp, [rax+1000h]
0x14000abfd  cmp     rax, rbp
0x14000ac00  jz      short loc_14000AC3F
0x14000ac02  lea     rdi, [rax+30h]
0x14000ac06  lea     rcx, [rdi-30h]; lpCriticalSection
0x14000ac0a  xor     r8d, r8d
0x14000ac0d  mov     edx, 0FA0h; dwSpinCount
0x14000ac12  call    __acrt_InitializeCriticalSectionEx
0x14000ac17  or      qword ptr [rdi-8], 0FFFFFFFFFFFFFFFFh
0x14000ac1c  mov     [rdi], rsi
0x14000ac1f  mov     dword ptr [rdi+8], 0A0A0000h
0x14000ac26  mov     byte ptr [rdi+0Ch], 0Ah
0x14000ac2a  and     byte ptr [rdi+0Dh], 0F8h
0x14000ac2e  mov     [rdi+0Eh], sil
0x14000ac32  lea     rdi, [rdi+40h]
0x14000ac36  lea     rax, [rdi-30h]
0x14000ac3a  cmp     rax, rbp
0x14000ac3d  jnz     short loc_14000AC06
0x14000ac3f  mov     rsi, rbx
0x14000ac42  xor     ecx, ecx; Block
0x14000ac44  call    _free_base
0x14000ac49  mov     rbx, [rsp+28h+arg_0]
0x14000ac4e  mov     rax, rsi
0x14000ac51  mov     rsi, [rsp+28h+arg_10]
0x14000ac56  mov     rbp, [rsp+28h+arg_8]
0x14000ac5b  add     rsp, 20h
0x14000ac5f  pop     rdi
0x14000ac60  retn

// ===== __acrt_lowio_destroy_handle_array @ 0x14000ac64 =====

0x14000ac64  test    rcx, rcx
0x14000ac67  jz      short locret_14000ACB3
0x14000ac69  mov     [rsp+arg_0], rbx
0x14000ac6e  mov     [rsp+arg_8], rsi
0x14000ac73  push    rdi
0x14000ac74  sub     rsp, 20h
0x14000ac78  lea     rsi, [rcx+1000h]
0x14000ac7f  mov     rbx, rcx
0x14000ac82  mov     rdi, rcx
0x14000ac85  cmp     rcx, rsi
0x14000ac88  jz      short loc_14000AC9C
0x14000ac8a  mov     rcx, rdi; lpCriticalSection
0x14000ac8d  call    cs:DeleteCriticalSection; KERNEL32
0x14000ac93  add     rdi, 40h ; '@'
0x14000ac97  cmp     rdi, rsi
0x14000ac9a  jnz     short loc_14000AC8A
0x14000ac9c  mov     rcx, rbx; Block
0x14000ac9f  call    _free_base
0x14000aca4  mov     rbx, [rsp+28h+arg_0]
0x14000aca9  mov     rsi, [rsp+28h+arg_8]
0x14000acae  add     rsp, 20h
0x14000acb2  pop     rdi
0x14000acb3  retn

// ===== __acrt_lowio_ensure_fh_exists @ 0x14000acb4 =====

0x14000acb4  mov     [rsp+arg_0], rbx
0x14000acb9  mov     [rsp+arg_8], rsi
0x14000acbe  mov     [rsp+arg_10], rdi
0x14000acc3  push    r15
0x14000acc5  sub     rsp, 30h
0x14000acc9  mov     esi, ecx
0x14000accb  xor     ebx, ebx
0x14000accd  mov     eax, ebx
0x14000accf  cmp     ecx, 2000h
0x14000acd5  setb    al
0x14000acd8  test    eax, eax
0x14000acda  jnz     short loc_14000ACF1
0x14000acdc  call    _errno
0x14000ace1  mov     ebx, 9
0x14000ace6  mov     [rax], ebx
0x14000ace8  call    _invalid_parameter_noinfo
0x14000aced  mov     eax, ebx
0x14000acef  jmp     short loc_14000AD55
0x14000acf1  mov     ecx, 7
0x14000acf6  call    sub_14000AB5C
0x14000acfb  nop
0x14000acfc  mov     rdi, rbx
0x14000acff  mov     [rsp+38h+var_18], rbx
0x14000ad04  mov     eax, cs:dword_14001D750
0x14000ad0a  cmp     esi, eax
0x14000ad0c  jl      short loc_14000AD49
0x14000ad0e  lea     r15, qword_14001D350
0x14000ad15  cmp     [r15+rdi*8], rbx
0x14000ad19  jz      short loc_14000AD1D
0x14000ad1b  jmp     short loc_14000AD3F
0x14000ad1d  call    __acrt_lowio_create_handle_array
0x14000ad22  mov     [r15+rdi*8], rax
0x14000ad26  test    rax, rax
0x14000ad29  jnz     short loc_14000AD30
0x14000ad2b  lea     ebx, [rax+0Ch]
0x14000ad2e  jmp     short loc_14000AD49
0x14000ad30  mov     eax, cs:dword_14001D750
0x14000ad36  add     eax, 40h ; '@'
0x14000ad39  mov     cs:dword_14001D750, eax
0x14000ad3f  inc     rdi
0x14000ad42  mov     [rsp+38h+var_18], rdi
0x14000ad47  jmp     short loc_14000AD0A
0x14000ad49  mov     ecx, 7
0x14000ad4e  call    sub_14000ABB0
0x14000ad53  jmp     short loc_14000ACED
0x14000ad55  mov     rbx, [rsp+38h+arg_0]
0x14000ad5a  mov     rsi, [rsp+38h+arg_8]
0x14000ad5f  mov     rdi, [rsp+38h+arg_10]
0x14000ad64  add     rsp, 30h
0x14000ad68  pop     r15
0x14000ad6a  retn
0x140010a72  push    rbp; Microsoft VisualC 64bit universal runtime
0x140010a74  sub     rsp, 20h
0x140010a78  mov     rbp, rdx
0x140010a7b  mov     ecx, 7
0x140010a80  add     rsp, 20h
0x140010a84  pop     rbp
0x140010a85  jmp     sub_14000ABB0

// ===== sub_14000AD6C @ 0x14000ad6c =====

0x14000ad6c  movsxd  rcx, ecx
0x14000ad6f  lea     rdx, qword_14001D350
0x14000ad76  mov     rax, rcx
0x14000ad79  and     ecx, 3Fh
0x14000ad7c  sar     rax, 6
0x14000ad80  shl     rcx, 6
0x14000ad84  add     rcx, [rdx+rax*8]
0x14000ad88  jmp     cs:EnterCriticalSection; KERNEL32

// ===== sub_14000AD90 @ 0x14000ad90 =====

0x14000ad90  movsxd  rcx, ecx
0x14000ad93  lea     rdx, qword_14001D350
0x14000ad9a  mov     rax, rcx
0x14000ad9d  and     ecx, 3Fh
0x14000ada0  sar     rax, 6
0x14000ada4  shl     rcx, 6
0x14000ada8  add     rcx, [rdx+rax*8]
0x14000adac  jmp     cs:LeaveCriticalSection; KERNEL32

// ===== _free_osfhnd @ 0x14000adb4 =====

0x14000adb4  mov     [rsp+arg_0], rbx
0x14000adb9  mov     [rsp+arg_8], rsi
0x14000adbe  mov     [rsp+arg_10], rdi
0x14000adc3  push    r14
0x14000adc5  sub     rsp, 20h
0x14000adc9  movsxd  rbx, ecx
0x14000adcc  test    ecx, ecx
0x14000adce  js      short loc_14000AE42
0x14000add0  cmp     ebx, cs:dword_14001D750
0x14000add6  jnb     short loc_14000AE42
0x14000add8  mov     rdi, rbx
0x14000addb  lea     r14, qword_14001D350
0x14000ade2  and     edi, 3Fh
0x14000ade5  mov     rsi, rbx
0x14000ade8  sar     rsi, 6
0x14000adec  shl     rdi, 6
0x14000adf0  mov     rax, [r14+rsi*8]
0x14000adf4  test    byte ptr [rax+rdi+38h], 1
0x14000adf9  jz      short loc_14000AE42
0x14000adfb  cmp     qword ptr [rax+rdi+28h], 0FFFFFFFFFFFFFFFFh
0x14000ae01  jz      short loc_14000AE42
0x14000ae03  call    sub_140005740
0x14000ae08  cmp     eax, 1
0x14000ae0b  jnz     short loc_14000AE34
0x14000ae0d  test    ebx, ebx
0x14000ae0f  jz      short loc_14000AE27
0x14000ae11  sub     ebx, eax
0x14000ae13  jz      short loc_14000AE20
0x14000ae15  cmp     ebx, eax
0x14000ae17  jnz     short loc_14000AE34
0x14000ae19  mov     ecx, 0FFFFFFF4h
0x14000ae1e  jmp     short loc_14000AE2C
0x14000ae20  mov     ecx, 0FFFFFFF5h
0x14000ae25  jmp     short loc_14000AE2C
0x14000ae27  mov     ecx, 0FFFFFFF6h; nStdHandle
0x14000ae2c  xor     edx, edx; hHandle
0x14000ae2e  call    cs:SetStdHandle; KERNEL32
0x14000ae34  mov     rax, [r14+rsi*8]
0x14000ae38  or      qword ptr [rax+rdi+28h], 0FFFFFFFFFFFFFFFFh
0x14000ae3e  xor     eax, eax
0x14000ae40  jmp     short loc_14000AE58
0x14000ae42  call    _errno
0x14000ae47  mov     dword ptr [rax], 9
0x14000ae4d  call    __doserrno
0x14000ae52  and     dword ptr [rax], 0
0x14000ae55  or      eax, 0FFFFFFFFh
0x14000ae58  mov     rbx, [rsp+28h+arg_0]
0x14000ae5d  mov     rsi, [rsp+28h+arg_8]
0x14000ae62  mov     rdi, [rsp+28h+arg_10]
0x14000ae67  add     rsp, 20h
0x14000ae6b  pop     r14
0x14000ae6d  retn

// ===== _get_osfhandle @ 0x14000ae70 =====

0x14000ae70  sub     rsp, 28h
0x14000ae74  cmp     ecx, 0FFFFFFFEh
0x14000ae77  jnz     short loc_14000AE8E
0x14000ae79  call    __doserrno
0x14000ae7e  and     dword ptr [rax], 0
0x14000ae81  call    _errno
0x14000ae86  mov     dword ptr [rax], 9
0x14000ae8c  jmp     short loc_14000AEDC
0x14000ae8e  test    ecx, ecx
0x14000ae90  js      short loc_14000AEC4
0x14000ae92  cmp     ecx, cs:dword_14001D750
0x14000ae98  jnb     short loc_14000AEC4
0x14000ae9a  movsxd  rdx, ecx
0x14000ae9d  lea     rcx, qword_14001D350
0x14000aea4  mov     rax, rdx
0x14000aea7  and     edx, 3Fh
0x14000aeaa  sar     rax, 6
0x14000aeae  shl     rdx, 6
0x14000aeb2  mov     rax, [rcx+rax*8]
0x14000aeb6  test    byte ptr [rax+rdx+38h], 1
0x14000aebb  jz      short loc_14000AEC4
0x14000aebd  mov     rax, [rax+rdx+28h]
0x14000aec2  jmp     short loc_14000AEE0
0x14000aec4  call    __doserrno
0x14000aec9  and     dword ptr [rax], 0
0x14000aecc  call    _errno
0x14000aed1  mov     dword ptr [rax], 9
0x14000aed7  call    _invalid_parameter_noinfo
0x14000aedc  or      rax, 0FFFFFFFFFFFFFFFFh
0x14000aee0  add     rsp, 28h
0x14000aee4  retn

// ===== __acrt_locale_free_monetary @ 0x14000aee8 =====

0x14000aee8  test    rcx, rcx
0x14000aeeb  jz      locret_14000AFF1
0x14000aef1  push    rbx
0x14000aef2  sub     rsp, 20h
0x14000aef6  mov     rbx, rcx
0x14000aef9  mov     rcx, [rcx+18h]; Block
0x14000aefd  cmp     rcx, cs:off_14001C838
0x14000af04  jz      short loc_14000AF0B
0x14000af06  call    _free_base
0x14000af0b  mov     rcx, [rbx+20h]; Block
0x14000af0f  cmp     rcx, cs:off_14001C840
0x14000af16  jz      short loc_14000AF1D
0x14000af18  call    _free_base
0x14000af1d  mov     rcx, [rbx+28h]; Block
0x14000af21  cmp     rcx, cs:off_14001C848
0x14000af28  jz      short loc_14000AF2F
0x14000af2a  call    _free_base
0x14000af2f  mov     rcx, [rbx+30h]; Block
0x14000af33  cmp     rcx, cs:off_14001C850
0x14000af3a  jz      short loc_14000AF41
0x14000af3c  call    _free_base
0x14000af41  mov     rcx, [rbx+38h]; Block
0x14000af45  cmp     rcx, cs:off_14001C858
0x14000af4c  jz      short loc_14000AF53
0x14000af4e  call    _free_base
0x14000af53  mov     rcx, [rbx+40h]; Block
0x14000af57  cmp     rcx, cs:off_14001C860
0x14000af5e  jz      short loc_14000AF65
0x14000af60  call    _free_base
0x14000af65  mov     rcx, [rbx+48h]; Block
0x14000af69  cmp     rcx, cs:off_14001C868
0x14000af70  jz      short loc_14000AF77
0x14000af72  call    _free_base
0x14000af77  mov     rcx, [rbx+68h]; Block
0x14000af7b  cmp     rcx, cs:off_14001C888
0x14000af82  jz      short loc_14000AF89
0x14000af84  call    _free_base
0x14000af89  mov     rcx, [rbx+70h]; Block
0x14000af8d  cmp     rcx, cs:off_14001C890
0x14000af94  jz      short loc_14000AF9B
0x14000af96  call    _free_base
0x14000af9b  mov     rcx, [rbx+78h]; Block
0x14000af9f  cmp     rcx, cs:off_14001C898
0x14000afa6  jz      short loc_14000AFAD
0x14000afa8  call    _free_base
0x14000afad  mov     rcx, [rbx+80h]; Block
0x14000afb4  cmp     rcx, cs:off_14001C8A0
0x14000afbb  jz      short loc_14000AFC2
0x14000afbd  call    _free_base
0x14000afc2  mov     rcx, [rbx+88h]; Block
0x14000afc9  cmp     rcx, cs:off_14001C8A8
0x14000afd0  jz      short loc_14000AFD7
0x14000afd2  call    _free_base
0x14000afd7  mov     rcx, [rbx+90h]; Block
0x14000afde  cmp     rcx, cs:off_14001C8B0
0x14000afe5  jz      short loc_14000AFEC
0x14000afe7  call    _free_base
0x14000afec  add     rsp, 20h
0x14000aff0  pop     rbx
0x14000aff1  retn

// ===== __acrt_locale_free_numeric @ 0x14000aff4 =====

0x14000aff4  test    rcx, rcx
0x14000aff7  jz      short locret_14000B05F
0x14000aff9  push    rbx
0x14000affa  sub     rsp, 20h
0x14000affe  mov     rbx, rcx
0x14000b001  mov     rcx, [rcx]; Block
0x14000b004  cmp     rcx, cs:off_14001C820
0x14000b00b  jz      short loc_14000B012
0x14000b00d  call    _free_base
0x14000b012  mov     rcx, [rbx+8]; Block
0x14000b016  cmp     rcx, cs:off_14001C828
0x14000b01d  jz      short loc_14000B024
0x14000b01f  call    _free_base
0x14000b024  mov     rcx, [rbx+10h]; Block
0x14000b028  cmp     rcx, cs:off_14001C830
0x14000b02f  jz      short loc_14000B036
0x14000b031  call    _free_base
0x14000b036  mov     rcx, [rbx+58h]; Block
0x14000b03a  cmp     rcx, cs:off_14001C878
0x14000b041  jz      short loc_14000B048
0x14000b043  call    _free_base
0x14000b048  mov     rcx, [rbx+60h]; Block
0x14000b04c  cmp     rcx, cs:off_14001C880
0x14000b053  jz      short loc_14000B05A
0x14000b055  call    _free_base
0x14000b05a  add     rsp, 20h
0x14000b05e  pop     rbx
0x14000b05f  retn

// ===== ?free_crt_array_internal@@YAXQEAPEBX_K@Z @ 0x14000b060 =====

0x14000b060  mov     [rsp+arg_0], rbx
0x14000b065  mov     [rsp+arg_8], rsi
0x14000b06a  push    rdi
0x14000b06b  sub     rsp, 20h
0x14000b06f  xor     edi, edi
0x14000b071  lea     rax, [rcx+rdx*8]
0x14000b075  mov     rsi, rax
0x14000b078  mov     rbx, rcx
0x14000b07b  sub     rsi, rcx
0x14000b07e  add     rsi, 7
0x14000b082  shr     rsi, 3
0x14000b086  cmp     rcx, rax
0x14000b089  cmova   rsi, rdi
0x14000b08d  test    rsi, rsi
0x14000b090  jz      short loc_14000B0A6
0x14000b092  mov     rcx, [rbx]; Block
0x14000b095  call    _free_base
0x14000b09a  inc     rdi
0x14000b09d  lea     rbx, [rbx+8]
0x14000b0a1  cmp     rdi, rsi
0x14000b0a4  jnz     short loc_14000B092
0x14000b0a6  mov     rbx, [rsp+28h+arg_0]
0x14000b0ab  mov     rsi, [rsp+28h+arg_8]
0x14000b0b0  add     rsp, 20h
0x14000b0b4  pop     rdi
0x14000b0b5  retn

// ===== __acrt_locale_free_time @ 0x14000b0b8 =====

0x14000b0b8  test    rcx, rcx
0x14000b0bb  jz      locret_14000B1BF
0x14000b0c1  mov     [rsp+arg_0], rbx
0x14000b0c6  mov     [rsp+arg_8], rbp
0x14000b0cb  push    rsi
0x14000b0cc  sub     rsp, 20h
0x14000b0d0  mov     ebp, 7
0x14000b0d5  mov     rbx, rcx
0x14000b0d8  mov     edx, ebp; unsigned __int64
0x14000b0da  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000b0df  lea     rcx, [rbx+38h]; void **
0x14000b0e3  mov     edx, ebp; unsigned __int64
0x14000b0e5  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000b0ea  lea     esi, [rbp+5]
0x14000b0ed  mov     edx, esi; unsigned __int64
0x14000b0ef  lea     rcx, [rbx+70h]; void **
0x14000b0f3  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000b0f8  lea     rcx, [rbx+0D0h]; void **
0x14000b0ff  mov     edx, esi; unsigned __int64
0x14000b101  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000b106  lea     rcx, [rbx+130h]; void **
0x14000b10d  lea     edx, [rbp-5]; unsigned __int64
0x14000b110  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000b115  mov     rcx, [rbx+140h]; Block
0x14000b11c  call    _free_base
0x14000b121  mov     rcx, [rbx+148h]; Block
0x14000b128  call    _free_base
0x14000b12d  mov     rcx, [rbx+150h]; Block
0x14000b134  call    _free_base
0x14000b139  lea     rcx, [rbx+160h]; void **
0x14000b140  mov     edx, ebp; unsigned __int64
0x14000b142  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000b147  lea     rcx, [rbx+198h]; void **
0x14000b14e  mov     edx, ebp; unsigned __int64
0x14000b150  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000b155  lea     rcx, [rbx+1D0h]; void **
0x14000b15c  mov     edx, esi; unsigned __int64
0x14000b15e  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000b163  lea     rcx, [rbx+230h]; void **
0x14000b16a  mov     edx, esi; unsigned __int64
0x14000b16c  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000b171  lea     rcx, [rbx+290h]; void **
0x14000b178  lea     edx, [rbp-5]; unsigned __int64
0x14000b17b  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000b180  mov     rcx, [rbx+2A0h]; Block
0x14000b187  call    _free_base
0x14000b18c  mov     rcx, [rbx+2A8h]; Block
0x14000b193  call    _free_base
0x14000b198  mov     rcx, [rbx+2B0h]; Block
0x14000b19f  call    _free_base
0x14000b1a4  mov     rcx, [rbx+2B8h]; Block
0x14000b1ab  call    _free_base
0x14000b1b0  mov     rbx, [rsp+28h+arg_0]
0x14000b1b5  mov     rbp, [rsp+28h+arg_8]
0x14000b1ba  add     rsp, 20h
0x14000b1be  pop     rsi
0x14000b1bf  retn

// ===== __pctype_func @ 0x14000b1c0 =====

0x14000b1c0  sub     rsp, 28h
0x14000b1c4  call    __acrt_getptd
0x14000b1c9  lea     rdx, [rsp+28h+arg_0]
0x14000b1ce  mov     rcx, [rax+90h]
0x14000b1d5  mov     [rsp+28h+arg_0], rcx
0x14000b1da  mov     rcx, rax
0x14000b1dd  call    sub_140007FBC
0x14000b1e2  mov     rax, [rsp+28h+arg_0]
0x14000b1e7  mov     rax, [rax]
0x14000b1ea  add     rsp, 28h
0x14000b1ee  retn

// ===== wcspbrk @ 0x14000b1f0 =====

0x14000b1f0  mov     r8, rdx
0x14000b1f3  xor     r9d, r9d
0x14000b1f6  cmp     [rcx], r9w
0x14000b1fa  jz      short loc_14000B224
0x14000b1fc  mov     rax, r8
0x14000b1ff  cmp     [r8], r9w
0x14000b203  jz      short loc_14000B21A
0x14000b205  movzx   edx, word ptr [r8]
0x14000b209  cmp     dx, [rcx]
0x14000b20c  jz      short loc_14000B220
0x14000b20e  add     rax, 2
0x14000b212  movzx   edx, word ptr [rax]
0x14000b215  test    dx, dx
0x14000b218  jnz     short loc_14000B209
0x14000b21a  add     rcx, 2
0x14000b21e  jmp     short loc_14000B1F6
0x14000b220  mov     rax, rcx
0x14000b223  retn
0x14000b224  xor     eax, eax
0x14000b226  retn

// ===== __acrt_GetStringTypeA @ 0x14000b228 =====

0x14000b228  push    rbp
0x14000b22a  push    r12
0x14000b22c  push    r13
0x14000b22e  push    r14
0x14000b230  push    r15
0x14000b232  sub     rsp, 60h
0x14000b236  lea     rbp, [rsp+30h]
0x14000b23b  mov     [rbp+50h+arg_0], rbx
0x14000b23f  mov     [rbp+50h+arg_8], rsi
0x14000b243  mov     [rbp+50h+arg_10], rdi
0x14000b247  mov     rax, cs:__security_cookie
0x14000b24e  xor     rax, rbp
0x14000b251  mov     [rbp+50h+var_30], rax
0x14000b255  mov     r13d, edx
0x14000b258  mov     r15d, r9d
0x14000b25b  mov     rdx, rcx; struct __crt_locale_pointers *
0x14000b25e  mov     r12, r8
0x14000b261  lea     rcx, [rbp+50h+var_50]; this
0x14000b265  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000b26a  mov     esi, [rbp+50h+CodePage]
0x14000b270  test    esi, esi
0x14000b272  jnz     short loc_14000B27B
0x14000b274  mov     rax, [rbp+50h+var_48]
0x14000b278  mov     esi, [rax+0Ch]
0x14000b27b  neg     [rbp+50h+arg_30]
0x14000b281  mov     r9d, r15d; cbMultiByte
0x14000b284  mov     r8, r12; lpMultiByteStr
0x14000b287  mov     ecx, esi; CodePage
0x14000b289  sbb     edx, edx
0x14000b28b  and     [rsp+80h+cchWideChar], 0
0x14000b290  and     [rsp+80h+lpWideCharStr], 0
0x14000b296  and     edx, 8
0x14000b299  inc     edx; dwFlags
0x14000b29b  call    cs:MultiByteToWideChar; KERNEL32
0x14000b2a1  movsxd  r14, eax
0x14000b2a4  test    eax, eax
0x14000b2a6  jnz     short loc_14000B2AF
0x14000b2a8  xor     edi, edi
0x14000b2aa  jmp     loc_14000B3A0
0x14000b2af  mov     rdi, r14
0x14000b2b2  add     rdi, rdi
0x14000b2b5  lea     rcx, [rdi+10h]
0x14000b2b9  cmp     rdi, rcx
0x14000b2bc  sbb     rax, rax
0x14000b2bf  test    rcx, rax
0x14000b2c2  jz      short loc_14000B339
0x14000b2c4  lea     rcx, [rdi+10h]
0x14000b2c8  cmp     rdi, rcx
0x14000b2cb  sbb     rax, rax
0x14000b2ce  and     rax, rcx
0x14000b2d1  cmp     rax, 400h
0x14000b2d7  lea     rax, [rdi+10h]
0x14000b2db  ja      short loc_14000B317
0x14000b2dd  cmp     rdi, rax
0x14000b2e0  sbb     rcx, rcx
0x14000b2e3  and     rcx, rax
0x14000b2e6  lea     rax, [rcx+0Fh]
0x14000b2ea  cmp     rax, rcx
0x14000b2ed  ja      short loc_14000B2F9
0x14000b2ef  mov     rax, 0FFFFFFFFFFFFFF0h
0x14000b2f9  and     rax, 0FFFFFFFFFFFFFFF0h
0x14000b2fd  call    _alloca_probe
0x14000b302  sub     rsp, rax
0x14000b305  lea     rbx, [rsp+80h+var_50]
0x14000b30a  test    rbx, rbx
0x14000b30d  jz      short loc_14000B388
0x14000b30f  mov     dword ptr [rbx], 0CCCCh
0x14000b315  jmp     short loc_14000B333
0x14000b317  cmp     rdi, rax
0x14000b31a  sbb     rcx, rcx
0x14000b31d  and     rcx, rax; Size
0x14000b320  call    _malloc_base
0x14000b325  mov     rbx, rax
0x14000b328  test    rax, rax
0x14000b32b  jz      short loc_14000B33B
0x14000b32d  mov     dword ptr [rax], 0DDDDh
0x14000b333  add     rbx, 10h
0x14000b337  jmp     short loc_14000B33B
0x14000b339  xor     ebx, ebx
0x14000b33b  test    rbx, rbx
0x14000b33e  jz      short loc_14000B388
0x14000b340  mov     r8, rdi
0x14000b343  xor     edx, edx
0x14000b345  mov     rcx, rbx
0x14000b348  call    sub_140002F60
0x14000b34d  mov     r9d, r15d; cbMultiByte
0x14000b350  mov     [rsp+80h+cchWideChar], r14d; cchWideChar
0x14000b355  mov     r8, r12; lpMultiByteStr
0x14000b358  mov     [rsp+80h+lpWideCharStr], rbx; lpWideCharStr
0x14000b35d  mov     edx, 1; dwFlags
0x14000b362  mov     ecx, esi; CodePage
0x14000b364  call    cs:MultiByteToWideChar; KERNEL32
0x14000b36a  test    eax, eax
0x14000b36c  jz      short loc_14000B388
0x14000b36e  mov     r9, [rbp+50h+lpCharType]; lpCharType
0x14000b375  mov     r8d, eax; cchSrc
0x14000b378  mov     rdx, rbx; lpSrcStr
0x14000b37b  mov     ecx, r13d; dwInfoType
0x14000b37e  call    cs:GetStringTypeW; KERNEL32
0x14000b384  mov     edi, eax
0x14000b386  jmp     short loc_14000B38A
0x14000b388  xor     edi, edi
0x14000b38a  test    rbx, rbx
0x14000b38d  jz      short loc_14000B3A0
0x14000b38f  lea     rcx, [rbx-10h]; Block
0x14000b393  cmp     dword ptr [rcx], 0DDDDh
0x14000b399  jnz     short loc_14000B3A0
0x14000b39b  call    _free_base
0x14000b3a0  cmp     [rbp+50h+var_38], 0
0x14000b3a4  jz      short loc_14000B3B1
0x14000b3a6  mov     rax, [rbp+50h+var_50]
0x14000b3aa  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x14000b3b1  mov     eax, edi
0x14000b3b3  mov     rcx, [rbp+50h+var_30]
0x14000b3b7  xor     rcx, rbp; StackCookie
0x14000b3ba  call    __security_check_cookie
0x14000b3bf  mov     rbx, [rbp+50h+arg_0]
0x14000b3c3  mov     rsi, [rbp+50h+arg_8]
0x14000b3c7  mov     rdi, [rbp+50h+arg_10]
0x14000b3cb  lea     rsp, [rbp+30h]
0x14000b3cf  pop     r15
0x14000b3d1  pop     r14
0x14000b3d3  pop     r13
0x14000b3d5  pop     r12
0x14000b3d7  pop     rbp
0x14000b3d8  retn

// ===== __acrt_add_locale_ref @ 0x14000b3dc =====

0x14000b3dc  lock inc dword ptr [rcx+10h]
0x14000b3e0  mov     rax, [rcx+0E0h]
0x14000b3e7  test    rax, rax
0x14000b3ea  jz      short loc_14000B3EF
0x14000b3ec  lock inc dword ptr [rax]
0x14000b3ef  mov     rax, [rcx+0F0h]
0x14000b3f6  test    rax, rax
0x14000b3f9  jz      short loc_14000B3FE
0x14000b3fb  lock inc dword ptr [rax]
0x14000b3fe  mov     rax, [rcx+0E8h]
0x14000b405  test    rax, rax
0x14000b408  jz      short loc_14000B40D
0x14000b40a  lock inc dword ptr [rax]
0x14000b40d  mov     rax, [rcx+100h]
0x14000b414  test    rax, rax
0x14000b417  jz      short loc_14000B41C
0x14000b419  lock inc dword ptr [rax]
0x14000b41c  lea     rax, [rcx+38h]
0x14000b420  mov     r8d, 6
0x14000b426  lea     rdx, unk_14001C2C8
0x14000b42d  cmp     [rax-10h], rdx
0x14000b431  jz      short loc_14000B43E
0x14000b433  mov     rdx, [rax]
0x14000b436  test    rdx, rdx
0x14000b439  jz      short loc_14000B43E
0x14000b43b  lock inc dword ptr [rdx]
0x14000b43e  cmp     qword ptr [rax-18h], 0
0x14000b443  jz      short loc_14000B451
0x14000b445  mov     rdx, [rax-8]
0x14000b449  test    rdx, rdx
0x14000b44c  jz      short loc_14000B451
0x14000b44e  lock inc dword ptr [rdx]
0x14000b451  add     rax, 20h ; ' '
0x14000b455  sub     r8, 1
0x14000b459  jnz     short loc_14000B426
0x14000b45b  mov     rcx, [rcx+120h]
0x14000b462  jmp     __acrt_locale_add_lc_time_reference
0x14000b5e0  test    rcx, rcx
0x14000b5e3  jz      short loc_14000B601
0x14000b5e5  lea     rax, off_140012350
0x14000b5ec  cmp     rcx, rax
0x14000b5ef  jz      short loc_14000B601
0x14000b5f1  mov     eax, 1
0x14000b5f6  lock xadd [rcx+15Ch], eax
0x14000b5fe  inc     eax
0x14000b600  retn
0x14000b601  mov     eax, 7FFFFFFFh
0x14000b606  retn

// ===== __acrt_free_locale @ 0x14000b468 =====

0x14000b468  mov     [rsp+arg_0], rbx
0x14000b46d  mov     [rsp+arg_8], rbp
0x14000b472  mov     [rsp+arg_10], rsi
0x14000b477  push    rdi
0x14000b478  sub     rsp, 20h
0x14000b47c  mov     rax, [rcx+0F8h]
0x14000b483  mov     rbx, rcx
0x14000b486  test    rax, rax
0x14000b489  jz      short loc_14000B504
0x14000b48b  lea     rcx, off_14001C820
0x14000b492  cmp     rax, rcx
0x14000b495  jz      short loc_14000B504
0x14000b497  mov     rax, [rbx+0E0h]
0x14000b49e  test    rax, rax
0x14000b4a1  jz      short loc_14000B504
0x14000b4a3  cmp     dword ptr [rax], 0
0x14000b4a6  jnz     short loc_14000B504
0x14000b4a8  mov     rcx, [rbx+0F0h]; Block
0x14000b4af  test    rcx, rcx
0x14000b4b2  jz      short loc_14000B4CA
0x14000b4b4  cmp     dword ptr [rcx], 0
0x14000b4b7  jnz     short loc_14000B4CA
0x14000b4b9  call    _free_base
0x14000b4be  mov     rcx, [rbx+0F8h]
0x14000b4c5  call    __acrt_locale_free_monetary
0x14000b4ca  mov     rcx, [rbx+0E8h]; Block
0x14000b4d1  test    rcx, rcx
0x14000b4d4  jz      short loc_14000B4EC
0x14000b4d6  cmp     dword ptr [rcx], 0
0x14000b4d9  jnz     short loc_14000B4EC
0x14000b4db  call    _free_base
0x14000b4e0  mov     rcx, [rbx+0F8h]
0x14000b4e7  call    __acrt_locale_free_numeric
0x14000b4ec  mov     rcx, [rbx+0E0h]; Block
0x14000b4f3  call    _free_base
0x14000b4f8  mov     rcx, [rbx+0F8h]; Block
0x14000b4ff  call    _free_base
0x14000b504  mov     rax, [rbx+100h]
0x14000b50b  test    rax, rax
0x14000b50e  jz      short loc_14000B557
0x14000b510  cmp     dword ptr [rax], 0
0x14000b513  jnz     short loc_14000B557
0x14000b515  mov     rcx, [rbx+108h]
0x14000b51c  sub     rcx, 0FEh; Block
0x14000b523  call    _free_base
0x14000b528  mov     rcx, [rbx+110h]
0x14000b52f  mov     edi, 80h
0x14000b534  sub     rcx, rdi; Block
0x14000b537  call    _free_base
0x14000b53c  mov     rcx, [rbx+118h]
0x14000b543  sub     rcx, rdi; Block
0x14000b546  call    _free_base
0x14000b54b  mov     rcx, [rbx+100h]; Block
0x14000b552  call    _free_base
0x14000b557  mov     rcx, [rbx+120h]; Block
0x14000b55e  call    __acrt_locale_free_lc_time_if_unreferenced
0x14000b563  lea     rsi, [rbx+128h]
0x14000b56a  mov     ebp, 6
0x14000b56f  lea     rdi, [rbx+38h]
0x14000b573  lea     rax, unk_14001C2C8
0x14000b57a  cmp     [rdi-10h], rax
0x14000b57e  jz      short loc_14000B59A
0x14000b580  mov     rcx, [rdi]; Block
0x14000b583  test    rcx, rcx
0x14000b586  jz      short loc_14000B59A
0x14000b588  cmp     dword ptr [rcx], 0
0x14000b58b  jnz     short loc_14000B59A
0x14000b58d  call    _free_base
0x14000b592  mov     rcx, [rsi]; Block
0x14000b595  call    _free_base
0x14000b59a  cmp     qword ptr [rdi-18h], 0
0x14000b59f  jz      short loc_14000B5B4
0x14000b5a1  mov     rcx, [rdi-8]; Block
0x14000b5a5  test    rcx, rcx
0x14000b5a8  jz      short loc_14000B5B4
0x14000b5aa  cmp     dword ptr [rcx], 0
0x14000b5ad  jnz     short loc_14000B5B4
0x14000b5af  call    _free_base
0x14000b5b4  add     rsi, 8
0x14000b5b8  add     rdi, 20h ; ' '
0x14000b5bc  sub     rbp, 1
0x14000b5c0  jnz     short loc_14000B573
0x14000b5c2  mov     rcx, rbx; Block
0x14000b5c5  mov     rbx, [rsp+28h+arg_0]
0x14000b5ca  mov     rbp, [rsp+28h+arg_8]
0x14000b5cf  mov     rsi, [rsp+28h+arg_10]
0x14000b5d4  add     rsp, 20h
0x14000b5d8  pop     rdi
0x14000b5d9  jmp     _free_base

// ===== __acrt_locale_free_lc_time_if_unreferenced @ 0x14000b608 =====

0x14000b608  test    rcx, rcx
0x14000b60b  jz      short locret_14000B63D
0x14000b60d  push    rbx
0x14000b60e  sub     rsp, 20h
0x14000b612  lea     rax, off_140012350
0x14000b619  mov     rbx, rcx
0x14000b61c  cmp     rcx, rax
0x14000b61f  jz      short loc_14000B638
0x14000b621  mov     eax, [rcx+15Ch]
0x14000b627  test    eax, eax
0x14000b629  jnz     short loc_14000B638
0x14000b62b  call    __acrt_locale_free_time
0x14000b630  mov     rcx, rbx; Block
0x14000b633  call    _free_base
0x14000b638  add     rsp, 20h
0x14000b63c  pop     rbx
0x14000b63d  retn

// ===== __acrt_locale_release_lc_time_reference @ 0x14000b640 =====

0x14000b640  test    rcx, rcx
0x14000b643  jz      short loc_14000B65F
0x14000b645  lea     rax, off_140012350
0x14000b64c  cmp     rcx, rax
0x14000b64f  jz      short loc_14000B65F
0x14000b651  or      eax, 0FFFFFFFFh
0x14000b654  lock xadd [rcx+15Ch], eax
0x14000b65c  dec     eax
0x14000b65e  retn
0x14000b65f  mov     eax, 7FFFFFFFh
0x14000b664  retn

// ===== __acrt_release_locale_ref @ 0x14000b668 =====

0x14000b668  sub     rsp, 28h
0x14000b66c  test    rcx, rcx
0x14000b66f  jz      loc_14000B70B
0x14000b675  or      r9d, 0FFFFFFFFh
0x14000b679  lock add [rcx+10h], r9d
0x14000b67e  mov     rax, [rcx+0E0h]
0x14000b685  test    rax, rax
0x14000b688  jz      short loc_14000B68E
0x14000b68a  lock add [rax], r9d
0x14000b68e  mov     rax, [rcx+0F0h]
0x14000b695  test    rax, rax
0x14000b698  jz      short loc_14000B69E
0x14000b69a  lock add [rax], r9d
0x14000b69e  mov     rax, [rcx+0E8h]
0x14000b6a5  test    rax, rax
0x14000b6a8  jz      short loc_14000B6AE
0x14000b6aa  lock add [rax], r9d
0x14000b6ae  mov     rax, [rcx+100h]
0x14000b6b5  test    rax, rax
0x14000b6b8  jz      short loc_14000B6BE
0x14000b6ba  lock add [rax], r9d
0x14000b6be  lea     rax, [rcx+38h]
0x14000b6c2  mov     r8d, 6
0x14000b6c8  lea     rdx, unk_14001C2C8
0x14000b6cf  cmp     [rax-10h], rdx
0x14000b6d3  jz      short loc_14000B6E1
0x14000b6d5  mov     rdx, [rax]
0x14000b6d8  test    rdx, rdx
0x14000b6db  jz      short loc_14000B6E1
0x14000b6dd  lock add [rdx], r9d
0x14000b6e1  cmp     qword ptr [rax-18h], 0
0x14000b6e6  jz      short loc_14000B6F5
0x14000b6e8  mov     rdx, [rax-8]
0x14000b6ec  test    rdx, rdx
0x14000b6ef  jz      short loc_14000B6F5
0x14000b6f1  lock add [rdx], r9d
0x14000b6f5  add     rax, 20h ; ' '
0x14000b6f9  sub     r8, 1
0x14000b6fd  jnz     short loc_14000B6C8
0x14000b6ff  mov     rcx, [rcx+120h]
0x14000b706  call    __acrt_locale_release_lc_time_reference
0x14000b70b  add     rsp, 28h
0x14000b70f  retn

// ===== __acrt_update_thread_locale_data @ 0x14000b710 =====

0x14000b710  mov     [rsp+arg_0], rbx
0x14000b715  push    rdi
0x14000b716  sub     rsp, 20h
0x14000b71a  call    __acrt_getptd
0x14000b71f  mov     rdi, rax
0x14000b722  mov     ecx, cs:dword_14001C8C0
0x14000b728  test    [rax+3A8h], ecx
0x14000b72e  jz      short loc_14000B73C
0x14000b730  mov     rbx, [rax+90h]
0x14000b737  test    rbx, rbx
0x14000b73a  jnz     short loc_14000B772
0x14000b73c  mov     ecx, 4
0x14000b741  call    sub_14000AB5C
0x14000b746  nop
0x14000b747  lea     rcx, [rdi+90h]
0x14000b74e  mov     rdx, cs:qword_14001D340
0x14000b755  call    _updatetlocinfoEx_nolock
0x14000b75a  mov     rbx, rax
0x14000b75d  mov     ecx, 4
0x14000b762  call    sub_14000ABB0
0x14000b767  test    rbx, rbx
0x14000b76a  jnz     short loc_14000B772
0x14000b76c  call    abort
0x14000b772  mov     rax, rbx
0x14000b775  mov     rbx, [rsp+28h+arg_0]
0x14000b77a  add     rsp, 20h
0x14000b77e  pop     rdi
0x14000b77f  retn
0x140010a22  push    rbp; Microsoft VisualC 64bit universal runtime
0x140010a24  sub     rsp, 20h
0x140010a28  mov     rbp, rdx
0x140010a2b  mov     ecx, 4
0x140010a30  add     rsp, 20h
0x140010a34  pop     rbp
0x140010a35  jmp     sub_14000ABB0

// ===== _updatetlocinfoEx_nolock @ 0x14000b780 =====

0x14000b780  mov     [rsp+arg_0], rbx
0x14000b785  push    rdi
0x14000b786  sub     rsp, 20h
0x14000b78a  mov     rdi, rdx
0x14000b78d  test    rdx, rdx
0x14000b790  jz      short loc_14000B7DB
0x14000b792  test    rcx, rcx
0x14000b795  jz      short loc_14000B7DB
0x14000b797  mov     rbx, [rcx]
0x14000b79a  cmp     rbx, rdx
0x14000b79d  jnz     short loc_14000B7A4
0x14000b79f  mov     rax, rdx
0x14000b7a2  jmp     short loc_14000B7DD
0x14000b7a4  mov     [rcx], rdx
0x14000b7a7  mov     rcx, rdx
0x14000b7aa  call    __acrt_add_locale_ref
0x14000b7af  test    rbx, rbx
0x14000b7b2  jz      short loc_14000B7D6
0x14000b7b4  mov     rcx, rbx
0x14000b7b7  call    __acrt_release_locale_ref
0x14000b7bc  cmp     dword ptr [rbx+10h], 0
0x14000b7c0  jnz     short loc_14000B7D6
0x14000b7c2  lea     rax, off_14001C160
0x14000b7c9  cmp     rbx, rax
0x14000b7cc  jz      short loc_14000B7D6
0x14000b7ce  mov     rcx, rbx; Block
0x14000b7d1  call    __acrt_free_locale
0x14000b7d6  mov     rax, rdi
0x14000b7d9  jmp     short loc_14000B7DD
0x14000b7db  xor     eax, eax
0x14000b7dd  mov     rbx, [rsp+28h+arg_0]
0x14000b7e2  add     rsp, 20h
0x14000b7e6  pop     rdi
0x14000b7e7  retn

// ===== j__recalloc_base @ 0x14000b7e8 =====

0x14000b7e8  jmp     _recalloc_base

// ===== _recalloc_base @ 0x14000b7f0 =====

0x14000b7f0  mov     [rsp+arg_0], rbx
0x14000b7f5  mov     [rsp+arg_8], rbp
0x14000b7fa  mov     [rsp+arg_10], rsi
0x14000b7ff  push    rdi
0x14000b800  sub     rsp, 20h
0x14000b804  mov     rbp, r8
0x14000b807  mov     rbx, rdx
0x14000b80a  mov     rsi, rcx
0x14000b80d  test    rdx, rdx
0x14000b810  jz      short loc_14000B82F
0x14000b812  xor     edx, edx
0x14000b814  lea     rax, [rdx-20h]
0x14000b818  div     rbx
0x14000b81b  cmp     rax, r8
0x14000b81e  jnb     short loc_14000B82F
0x14000b820  call    _errno
0x14000b825  mov     dword ptr [rax], 0Ch
0x14000b82b  xor     eax, eax
0x14000b82d  jmp     short loc_14000B870
0x14000b82f  test    rcx, rcx
0x14000b832  jz      short loc_14000B83E
0x14000b834  call    _msize
0x14000b839  mov     rdi, rax
0x14000b83c  jmp     short loc_14000B840
0x14000b83e  xor     edi, edi
0x14000b840  imul    rbx, rbp
0x14000b844  mov     rcx, rsi; Block
0x14000b847  mov     rdx, rbx; Size
0x14000b84a  call    _realloc_base
0x14000b84f  mov     rsi, rax
0x14000b852  test    rax, rax
0x14000b855  jz      short loc_14000B86D
0x14000b857  cmp     rdi, rbx
0x14000b85a  jnb     short loc_14000B86D
0x14000b85c  sub     rbx, rdi
0x14000b85f  lea     rcx, [rax+rdi]
0x14000b863  mov     r8, rbx
0x14000b866  xor     edx, edx
0x14000b868  call    sub_140002F60
0x14000b86d  mov     rax, rsi
0x14000b870  mov     rbx, [rsp+28h+arg_0]
0x14000b875  mov     rbp, [rsp+28h+arg_8]
0x14000b87a  mov     rsi, [rsp+28h+arg_10]
0x14000b87f  add     rsp, 20h
0x14000b883  pop     rdi
0x14000b884  retn

// ===== __acrt_initialize_heap @ 0x14000b888 =====

0x14000b888  sub     rsp, 28h
0x14000b88c  call    cs:GetProcessHeap; KERNEL32
0x14000b892  test    rax, rax
0x14000b895  mov     cs:hHeap, rax
0x14000b89c  setnz   al
0x14000b89f  add     rsp, 28h
0x14000b8a3  retn

// ===== sub_14000B8A4 @ 0x14000b8a4 =====

0x14000b8a4  and     cs:hHeap, 0
0x14000b8ac  mov     al, 1
0x14000b8ae  retn

// ===== __acrt_execute_initializers @ 0x14000b8b0 =====

0x14000b8b0  mov     [rsp+arg_0], rbx
0x14000b8b5  mov     [rsp+arg_8], rbp
0x14000b8ba  mov     [rsp+arg_10], rsi
0x14000b8bf  push    rdi
0x14000b8c0  sub     rsp, 20h
0x14000b8c4  mov     rsi, rdx
0x14000b8c7  mov     rdi, rcx
0x14000b8ca  cmp     rcx, rdx
0x14000b8cd  jnz     short loc_14000B8D3
0x14000b8cf  mov     al, 1
0x14000b8d1  jmp     short loc_14000B92F
0x14000b8d3  mov     rbx, rcx
0x14000b8d6  mov     rbp, [rbx]
0x14000b8d9  test    rbp, rbp
0x14000b8dc  jz      short loc_14000B8ED
0x14000b8de  mov     rcx, rbp
0x14000b8e1  call    cs:__guard_check_icall_fptr
0x14000b8e7  call    rbp
0x14000b8e9  test    al, al
0x14000b8eb  jz      short loc_14000B8F6
0x14000b8ed  add     rbx, 10h
0x14000b8f1  cmp     rbx, rsi
0x14000b8f4  jnz     short loc_14000B8D6
0x14000b8f6  cmp     rbx, rsi
0x14000b8f9  jz      short loc_14000B8CF
0x14000b8fb  cmp     rbx, rdi
0x14000b8fe  jz      short loc_14000B92D
0x14000b900  add     rbx, 0FFFFFFFFFFFFFFF8h
0x14000b904  cmp     qword ptr [rbx-8], 0
0x14000b909  jz      short loc_14000B920
0x14000b90b  mov     rsi, [rbx]
0x14000b90e  test    rsi, rsi
0x14000b911  jz      short loc_14000B920
0x14000b913  mov     rcx, rsi
0x14000b916  call    cs:__guard_check_icall_fptr
0x14000b91c  xor     ecx, ecx
0x14000b91e  call    rsi
0x14000b920  sub     rbx, 10h
0x14000b924  lea     rax, [rbx+8]
0x14000b928  cmp     rax, rdi
0x14000b92b  jnz     short loc_14000B904
0x14000b92d  xor     al, al
0x14000b92f  mov     rbx, [rsp+28h+arg_0]
0x14000b934  mov     rbp, [rsp+28h+arg_8]
0x14000b939  mov     rsi, [rsp+28h+arg_10]
0x14000b93e  add     rsp, 20h
0x14000b942  pop     rdi
0x14000b943  retn

// ===== __acrt_execute_uninitializers @ 0x14000b944 =====

0x14000b944  mov     [rsp+arg_0], rbx
0x14000b949  mov     [rsp+arg_8], rsi
0x14000b94e  push    rdi
0x14000b94f  sub     rsp, 20h
0x14000b953  mov     rsi, rcx
0x14000b956  cmp     rcx, rdx
0x14000b959  jz      short loc_14000B981
0x14000b95b  lea     rbx, [rdx-8]
0x14000b95f  mov     rdi, [rbx]
0x14000b962  test    rdi, rdi
0x14000b965  jz      short loc_14000B974
0x14000b967  mov     rcx, rdi
0x14000b96a  call    cs:__guard_check_icall_fptr
0x14000b970  xor     ecx, ecx
0x14000b972  call    rdi
0x14000b974  sub     rbx, 10h
0x14000b978  lea     rax, [rbx+8]
0x14000b97c  cmp     rax, rsi
0x14000b97f  jnz     short loc_14000B95F
0x14000b981  mov     rbx, [rsp+28h+arg_0]
0x14000b986  mov     al, 1
0x14000b988  mov     rsi, [rsp+28h+arg_8]
0x14000b98d  add     rsp, 20h
0x14000b991  pop     rdi
0x14000b992  retn

// ===== sub_14000B994 @ 0x14000b994 =====

0x14000b994  mov     cs:qword_14001DB80, rcx
0x14000b99b  retn

// ===== _callnewh @ 0x14000b99c =====

0x14000b99c  mov     [rsp+arg_0], rbx
0x14000b9a1  push    rdi
0x14000b9a2  sub     rsp, 20h
0x14000b9a6  mov     rdi, rcx
0x14000b9a9  call    _query_new_handler
0x14000b9ae  mov     rbx, rax
0x14000b9b1  test    rax, rax
0x14000b9b4  jz      short loc_14000B9CF
0x14000b9b6  mov     rcx, rax
0x14000b9b9  call    cs:__guard_check_icall_fptr
0x14000b9bf  mov     rcx, rdi
0x14000b9c2  call    rbx
0x14000b9c4  test    eax, eax
0x14000b9c6  jz      short loc_14000B9CF
0x14000b9c8  mov     eax, 1
0x14000b9cd  jmp     short loc_14000B9D1
0x14000b9cf  xor     eax, eax
0x14000b9d1  mov     rbx, [rsp+28h+arg_0]
0x14000b9d6  add     rsp, 20h
0x14000b9da  pop     rdi
0x14000b9db  retn

// ===== _query_new_handler @ 0x14000b9dc =====

0x14000b9dc  push    rbx
0x14000b9de  sub     rsp, 20h
0x14000b9e2  xor     ecx, ecx
0x14000b9e4  call    sub_14000AB5C
0x14000b9e9  nop
0x14000b9ea  mov     rbx, cs:__security_cookie
0x14000b9f1  mov     ecx, ebx
0x14000b9f3  and     ecx, 3Fh
0x14000b9f6  xor     rbx, cs:qword_14001DB80
0x14000b9fd  ror     rbx, cl
0x14000ba00  xor     ecx, ecx
0x14000ba02  call    sub_14000ABB0
0x14000ba07  mov     rax, rbx
0x14000ba0a  add     rsp, 20h
0x14000ba0e  pop     rbx
0x14000ba0f  retn
0x140010af0  push    rbp; Microsoft VisualC v14 64bit runtime
0x140010af2  sub     rsp, 20h
0x140010af6  mov     rbp, rdx
0x140010af9  xor     ecx, ecx
0x140010afb  add     rsp, 20h
0x140010aff  pop     rbp
0x140010b00  jmp     sub_14000ABB0

// ===== ??$?RV_lambda_c36588078e9f5dfd39652860aa6b3aaf_@@AEAV_lambda_ec61778202f4f5fc7e7711acc23c3bca_@@V_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_@@@?$__crt_seh_guarded_call@P6AXH@Z@@QEAAP6AXH@Z$$QEAV_lambda_c36588078e9f5dfd39652860aa6b3aaf_@@AEAV_lambda_ec61778202f4f5fc7e7711acc23c3bca_@@$$QEAV_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_@@@Z @ 0x14000ba10 =====

0x14000ba10  mov     [rsp+arg_0], rbx
0x14000ba15  mov     [rsp+arg_18], r9
0x14000ba1a  push    rdi
0x14000ba1b  sub     rsp, 20h
0x14000ba1f  mov     rdi, r9
0x14000ba22  mov     ecx, [rdx]
0x14000ba24  call    sub_14000AB5C
0x14000ba29  nop
0x14000ba2a  mov     rbx, cs:__security_cookie
0x14000ba31  mov     ecx, ebx
0x14000ba33  and     ecx, 3Fh
0x14000ba36  xor     rbx, cs:qword_14001DB98
0x14000ba3d  ror     rbx, cl
0x14000ba40  mov     ecx, [rdi]
0x14000ba42  call    sub_14000ABB0
0x14000ba47  mov     rax, rbx
0x14000ba4a  mov     rbx, [rsp+28h+arg_0]
0x14000ba4f  add     rsp, 20h
0x14000ba53  pop     rdi
0x14000ba54  retn
0x140010a3b  push    rbp
0x140010a3d  sub     rsp, 20h
0x140010a41  mov     rbp, rdx
0x140010a44  mov     rax, [rbp+48h]
0x140010a48  mov     ecx, [rax]
0x140010a4a  add     rsp, 20h
0x140010a4e  pop     rbp
0x140010a4f  jmp     sub_14000ABB0

// ===== __acrt_get_sigabrt_handler @ 0x14000ba58 =====

0x14000ba58  mov     r11, rsp
0x14000ba5b  sub     rsp, 28h
0x14000ba5f  mov     eax, 3
0x14000ba64  lea     r9, [r11+10h]
0x14000ba68  lea     r8, [r11+8]
0x14000ba6c  mov     [rsp+28h+arg_8], eax
0x14000ba70  lea     rdx, [r11+18h]
0x14000ba74  mov     [rsp+28h+arg_10], eax
0x14000ba78  lea     rcx, [r11+8]
0x14000ba7c  call    ??$?RV_lambda_c36588078e9f5dfd39652860aa6b3aaf_@@AEAV_lambda_ec61778202f4f5fc7e7711acc23c3bca_@@V_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_@@@?$__crt_seh_guarded_call@P6AXH@Z@@QEAAP6AXH@Z$$QEAV_lambda_c36588078e9f5dfd39652860aa6b3aaf_@@AEAV_lambda_ec61778202f4f5fc7e7711acc23c3bca_@@$$QEAV_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_@@@Z
0x14000ba81  add     rsp, 28h
0x14000ba85  retn

// ===== __acrt_initialize_signal_handlers @ 0x14000ba88 =====

0x14000ba88  mov     cs:qword_14001DB88, rcx
0x14000ba8f  mov     cs:qword_14001DB90, rcx
0x14000ba96  mov     cs:qword_14001DB98, rcx
0x14000ba9d  mov     cs:qword_14001DBA0, rcx
0x14000baa4  retn

// ===== raise @ 0x14000baa8 =====

0x14000baa8  mov     rax, rsp
0x14000baab  push    rbx
0x14000baac  push    rsi
0x14000baad  push    rdi
0x14000baae  push    r12
0x14000bab0  push    r13
0x14000bab2  push    r15
0x14000bab4  sub     rsp, 48h
0x14000bab8  mov     edi, ecx
0x14000baba  xor     r13d, r13d
0x14000babd  and     [rax+18h], r13d
0x14000bac1  mov     sil, 1
0x14000bac4  mov     [rsp+78h+arg_0], sil
0x14000bacc  cmp     ecx, 2
0x14000bacf  jz      loc_14000BB63
0x14000bad5  cmp     ecx, 4
0x14000bad8  jz      short loc_14000BAFC
0x14000bada  cmp     ecx, 6
0x14000badd  jz      loc_14000BB63
0x14000bae3  cmp     ecx, 8
0x14000bae6  jz      short loc_14000BAFC
0x14000bae8  cmp     ecx, 0Bh
0x14000baeb  jz      short loc_14000BAFC
0x14000baed  cmp     ecx, 0Fh
0x14000baf0  jz      short loc_14000BB63
0x14000baf2  lea     eax, [rcx-15h]
0x14000baf5  cmp     eax, 1
0x14000baf8  jbe     short loc_14000BB63
0x14000bafa  jmp     short loc_14000BB40
0x14000bafc  call    __acrt_getptd_noexit
0x14000bb01  mov     r13, rax
0x14000bb04  test    rax, rax
0x14000bb07  jnz     short loc_14000BB11
0x14000bb09  or      eax, 0FFFFFFFFh
0x14000bb0c  jmp     loc_14000BD33
0x14000bb11  mov     rcx, [rax]
0x14000bb14  mov     rdx, cs:qword_140012060
0x14000bb1b  shl     rdx, 4
0x14000bb1f  add     rdx, rcx
0x14000bb22  jmp     short loc_14000BB2D
0x14000bb24  cmp     [rcx+4], edi
0x14000bb27  jz      short loc_14000BB34
0x14000bb29  add     rcx, 10h
0x14000bb2d  cmp     rcx, rdx
0x14000bb30  jnz     short loc_14000BB24
0x14000bb32  xor     ecx, ecx
0x14000bb34  xor     eax, eax
0x14000bb36  test    rcx, rcx
0x14000bb39  setnz   al
0x14000bb3c  test    eax, eax
0x14000bb3e  jnz     short loc_14000BB52
0x14000bb40  call    _errno
0x14000bb45  mov     dword ptr [rax], 16h
0x14000bb4b  call    _invalid_parameter_noinfo
0x14000bb50  jmp     short loc_14000BB09
0x14000bb52  lea     rbx, [rcx+8]
0x14000bb56  xor     sil, sil
0x14000bb59  mov     [rsp+78h+arg_0], sil
0x14000bb61  jmp     short loc_14000BBA2
0x14000bb63  sub     ecx, 2
0x14000bb66  jz      short loc_14000BB9B
0x14000bb68  sub     ecx, 4
0x14000bb6b  jz      short loc_14000BB80
0x14000bb6d  sub     ecx, 9
0x14000bb70  jz      short loc_14000BB92
0x14000bb72  sub     ecx, 6
0x14000bb75  jz      short loc_14000BB89
0x14000bb77  cmp     ecx, 1
0x14000bb7a  jz      short loc_14000BB80
0x14000bb7c  xor     ebx, ebx
0x14000bb7e  jmp     short loc_14000BBA2
0x14000bb80  lea     rbx, qword_14001DB98
0x14000bb87  jmp     short loc_14000BBA2
0x14000bb89  lea     rbx, qword_14001DB90
0x14000bb90  jmp     short loc_14000BBA2
0x14000bb92  lea     rbx, qword_14001DBA0
0x14000bb99  jmp     short loc_14000BBA2
0x14000bb9b  lea     rbx, qword_14001DB88
0x14000bba2  and     [rsp+78h+arg_18], 0
0x14000bbab  test    sil, sil
0x14000bbae  jz      short loc_14000BBBB
0x14000bbb0  mov     ecx, 3
0x14000bbb5  call    sub_14000AB5C
0x14000bbba  nop
0x14000bbbb  test    sil, sil
0x14000bbbe  jz      short loc_14000BBD7
0x14000bbc0  mov     rdx, cs:__security_cookie
0x14000bbc7  mov     ecx, edx
0x14000bbc9  and     ecx, 3Fh
0x14000bbcc  xor     rdx, [rbx]
0x14000bbcf  ror     rdx, cl
0x14000bbd2  mov     r15, rdx
0x14000bbd5  jmp     short loc_14000BBDA
0x14000bbd7  mov     r15, [rbx]
0x14000bbda  cmp     r15, 1
0x14000bbde  setz    al
0x14000bbe1  mov     [rsp+78h+arg_8], al
0x14000bbe8  test    al, al
0x14000bbea  jnz     loc_14000BCAF
0x14000bbf0  test    r15, r15
0x14000bbf3  jnz     short loc_14000BC0D
0x14000bbf5  test    sil, sil
0x14000bbf8  jz      short loc_14000BC03
0x14000bbfa  lea     ecx, [r15+3]
0x14000bbfe  call    sub_14000ABB0
0x14000bc03  mov     ecx, 3; Code
0x14000bc08  call    _exit
0x14000bc0d  mov     r12d, 910h
0x14000bc13  cmp     edi, 0Bh
0x14000bc16  ja      short loc_14000BC58
0x14000bc18  bt      r12d, edi
0x14000bc1c  jnb     short loc_14000BC58
0x14000bc1e  mov     rax, [r13+8]
0x14000bc22  mov     [rsp+78h+arg_18], rax
0x14000bc2a  mov     [rsp+78h+var_48], rax
0x14000bc2f  and     qword ptr [r13+8], 0
0x14000bc34  cmp     edi, 8
0x14000bc37  jnz     short loc_14000BC8F
0x14000bc39  call    __acrt_getptd
0x14000bc3e  mov     eax, [rax+10h]
0x14000bc41  mov     [rsp+78h+arg_10], eax
0x14000bc48  mov     [rsp+78h+var_58], eax
0x14000bc4c  call    __acrt_getptd
0x14000bc51  mov     dword ptr [rax+10h], 8Ch
0x14000bc58  cmp     edi, 8
0x14000bc5b  jnz     short loc_14000BC8F
0x14000bc5d  mov     rax, cs:qword_140012068
0x14000bc64  shl     rax, 4
0x14000bc68  add     rax, [r13+0]
0x14000bc6c  mov     rcx, cs:qword_140012070
0x14000bc73  shl     rcx, 4
0x14000bc77  add     rcx, rax
0x14000bc7a  mov     [rsp+78h+var_50], rax
0x14000bc7f  cmp     rax, rcx
0x14000bc82  jz      short loc_14000BCB5
0x14000bc84  and     qword ptr [rax+8], 0
0x14000bc89  add     rax, 10h
0x14000bc8d  jmp     short loc_14000BC7A
0x14000bc8f  mov     rdx, cs:__security_cookie
0x14000bc96  mov     eax, edx
0x14000bc98  and     eax, 3Fh
0x14000bc9b  mov     ecx, 40h ; '@'
0x14000bca0  sub     ecx, eax
0x14000bca2  xor     eax, eax
0x14000bca4  ror     rax, cl
0x14000bca7  xor     rax, rdx
0x14000bcaa  mov     [rbx], rax
0x14000bcad  jmp     short loc_14000BCB5
0x14000bcaf  mov     r12d, 910h
0x14000bcb5  test    sil, sil
0x14000bcb8  jz      short loc_14000BCC4
0x14000bcba  mov     ecx, 3
0x14000bcbf  call    sub_14000ABB0
0x14000bcc4  cmp     [rsp+78h+arg_8], 0
0x14000bccc  jz      short loc_14000BCD2
0x14000bcce  xor     eax, eax
0x14000bcd0  jmp     short loc_14000BD33
0x14000bcd2  cmp     edi, 8
0x14000bcd5  jnz     short loc_14000BCF5
0x14000bcd7  call    __acrt_getptd
0x14000bcdc  mov     rbx, rax
0x14000bcdf  mov     rcx, r15
0x14000bce2  mov     rdx, cs:__guard_check_icall_fptr
0x14000bce9  call    rdx ; _guard_check_icall_nop
0x14000bceb  mov     edx, [rbx+10h]
0x14000bcee  mov     ecx, edi
0x14000bcf0  call    r15
0x14000bcf3  jmp     short loc_14000BD06
0x14000bcf5  mov     rcx, r15
0x14000bcf8  mov     rax, cs:__guard_check_icall_fptr
0x14000bcff  call    rax ; _guard_check_icall_nop
0x14000bd01  mov     ecx, edi
0x14000bd03  call    r15
0x14000bd06  cmp     edi, 0Bh
0x14000bd09  ja      short loc_14000BCCE
0x14000bd0b  bt      r12d, edi
0x14000bd0f  jnb     short loc_14000BCCE
0x14000bd11  mov     rax, [rsp+78h+arg_18]
0x14000bd19  mov     [r13+8], rax
0x14000bd1d  cmp     edi, 8
0x14000bd20  jnz     short loc_14000BCCE
0x14000bd22  call    __acrt_getptd
0x14000bd27  mov     ecx, [rsp+78h+arg_10]
0x14000bd2e  mov     [rax+10h], ecx
0x14000bd31  jmp     short loc_14000BCCE
0x14000bd33  add     rsp, 48h
0x14000bd37  pop     r15
0x14000bd39  pop     r13
0x14000bd3b  pop     r12
0x14000bd3d  pop     rdi
0x14000bd3e  pop     rsi
0x14000bd3f  pop     rbx
0x14000bd40  retn
0x140010b06  push    rbp
0x140010b08  sub     rsp, 20h
0x140010b0c  mov     rbp, rdx
0x140010b0f  cmp     byte ptr [rbp+80h], 0
0x140010b16  jz      short loc_140010B23
0x140010b18  mov     ecx, 3
0x140010b1d  call    sub_14000ABB0
0x140010b22  nop
0x140010b23  add     rsp, 20h
0x140010b27  pop     rbp
0x140010b28  retn

// ===== iswctype @ 0x14000bd44 =====

0x14000bd44  mov     [rsp+arg_8], rbx
0x14000bd49  push    rdi
0x14000bd4a  sub     rsp, 20h
0x14000bd4e  mov     eax, 0FFFFh
0x14000bd53  movzx   ebx, dx
0x14000bd56  cmp     cx, ax
0x14000bd59  jnz     short loc_14000BD5F
0x14000bd5b  xor     eax, eax
0x14000bd5d  jmp     short loc_14000BDA9
0x14000bd5f  mov     eax, 100h
0x14000bd64  cmp     cx, ax
0x14000bd67  jnb     short loc_14000BD79
0x14000bd69  mov     rax, cs:off_14001C810
0x14000bd70  movzx   ecx, cx
0x14000bd73  movzx   eax, word ptr [rax+rcx*2]
0x14000bd77  jmp     short loc_14000BDA4
0x14000bd79  xor     edi, edi
0x14000bd7b  mov     [rsp+28h+SrcStr], cx
0x14000bd80  lea     r9, [rsp+28h+CharType]; lpCharType
0x14000bd85  mov     [rsp+28h+CharType], di
0x14000bd8a  lea     rdx, [rsp+28h+SrcStr]; lpSrcStr
0x14000bd8f  lea     ecx, [rdi+1]; dwInfoType
0x14000bd92  mov     r8d, ecx; cchSrc
0x14000bd95  call    cs:GetStringTypeW; KERNEL32
0x14000bd9b  test    eax, eax
0x14000bd9d  jz      short loc_14000BD5B
0x14000bd9f  movzx   eax, [rsp+28h+CharType]
0x14000bda4  movzx   ecx, bx
0x14000bda7  and     eax, ecx
0x14000bda9  mov     rbx, [rsp+28h+arg_8]
0x14000bdae  add     rsp, 20h
0x14000bdb2  pop     rdi
0x14000bdb3  retn

// ===== _isctype_l @ 0x14000bdb4 =====

0x14000bdb4  mov     [rsp-8+arg_8], rsi
0x14000bdb9  mov     [rsp-8+arg_10], rdi
0x14000bdbe  mov     [rsp-8+arg_18], r14
0x14000bdc3  push    rbp
0x14000bdc4  mov     rbp, rsp
0x14000bdc7  sub     rsp, 80h
0x14000bdce  mov     rax, cs:__security_cookie
0x14000bdd5  xor     rax, rsp
0x14000bdd8  mov     [rbp+var_10], rax
0x14000bddc  mov     r14d, edx
0x14000bddf  movsxd  rdi, ecx
0x14000bde2  mov     rdx, r8; struct __crt_locale_pointers *
0x14000bde5  lea     rcx, [rbp+var_38]; this
0x14000bde9  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000bdee  lea     eax, [rdi+1]
0x14000bdf1  cmp     eax, 100h
0x14000bdf6  ja      short loc_14000BE08
0x14000bdf8  mov     rax, [rbp+Locale.locinfo]
0x14000bdfc  mov     rcx, [rax]
0x14000bdff  movzx   eax, word ptr [rcx+rdi*2]
0x14000be03  jmp     loc_14000BE8A
0x14000be08  mov     esi, edi
0x14000be0a  lea     rdx, [rbp+Locale]; Locale
0x14000be0e  sar     esi, 8
0x14000be11  movzx   ecx, sil; C
0x14000be15  call    _isleadbyte_l
0x14000be1a  mov     edx, 1; dwInfoType
0x14000be1f  test    eax, eax
0x14000be21  jz      short loc_14000BE35
0x14000be23  mov     [rbp+MultiByteStr], sil
0x14000be27  lea     r9d, [rdx+1]
0x14000be2b  mov     [rbp+var_3F], dil
0x14000be2f  mov     [rbp+var_3E], 0
0x14000be33  jmp     short loc_14000BE40
0x14000be35  mov     [rbp+MultiByteStr], dil
0x14000be39  mov     r9d, edx; cbMultiByte
0x14000be3c  mov     [rbp+var_3F], 0
0x14000be40  xor     eax, eax
0x14000be42  mov     [rsp+80h+var_50], edx; int
0x14000be46  mov     dword ptr [rbp+CharType], eax
0x14000be49  lea     r8, [rbp+MultiByteStr]; lpMultiByteStr
0x14000be4d  mov     [rbp+var_14], ax
0x14000be51  mov     rax, [rbp+Locale.locinfo]
0x14000be55  mov     ecx, [rax+0Ch]
0x14000be58  lea     rax, [rbp+CharType]
0x14000be5c  mov     [rsp+80h+CodePage], ecx; CodePage
0x14000be60  lea     rcx, [rbp+Locale]; struct __crt_locale_pointers *
0x14000be64  mov     [rsp+80h+lpCharType], rax; lpCharType
0x14000be69  call    __acrt_GetStringTypeA
0x14000be6e  test    eax, eax
0x14000be70  jnz     short loc_14000BE86
0x14000be72  cmp     [rbp+var_20], al
0x14000be75  jz      short loc_14000BE82
0x14000be77  mov     rax, [rbp+var_38]
0x14000be7b  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x14000be82  xor     eax, eax
0x14000be84  jmp     short loc_14000BE9E
0x14000be86  movzx   eax, [rbp+CharType]
0x14000be8a  and     eax, r14d
0x14000be8d  cmp     [rbp+var_20], 0
0x14000be91  jz      short loc_14000BE9E
0x14000be93  mov     rcx, [rbp+var_38]
0x14000be97  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x14000be9e  mov     rcx, [rbp+var_10]
0x14000bea2  xor     rcx, rsp; StackCookie
0x14000bea5  call    __security_check_cookie
0x14000beaa  lea     r11, [rsp+80h+var_s0]
0x14000beb2  mov     rsi, [r11+18h]
0x14000beb6  mov     rdi, [r11+20h]
0x14000beba  mov     r14, [r11+28h]
0x14000bebe  mov     rsp, r11
0x14000bec1  pop     rbp
0x14000bec2  retn

// ===== _isleadbyte_l @ 0x14000bec4 =====

0x14000bec4  push    rbx
0x14000bec6  sub     rsp, 40h
0x14000beca  mov     ebx, ecx
0x14000becc  lea     rcx, [rsp+48h+var_28]; this
0x14000bed1  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000bed6  mov     rax, [rsp+48h+var_20]
0x14000bedb  movzx   edx, bl
0x14000bede  mov     rcx, [rax]
0x14000bee1  movzx   eax, word ptr [rcx+rdx*2]
0x14000bee5  and     eax, 8000h
0x14000beea  cmp     [rsp+48h+var_10], 0
0x14000beef  jz      short loc_14000BEFD
0x14000bef1  mov     rcx, [rsp+48h+var_28]
0x14000bef6  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x14000befd  add     rsp, 40h
0x14000bf01  pop     rbx
0x14000bf02  retn

// ===== ?__acrt_LCMapStringA_stat@@YAHPEAU__crt_locale_pointers@@PEB_WKPEBDHPEADHHH@Z @ 0x14000bf04 =====

0x14000bf04  push    rbp
0x14000bf06  push    r12
0x14000bf08  push    r13
0x14000bf0a  push    r14
0x14000bf0c  push    r15
0x14000bf0e  sub     rsp, 60h
0x14000bf12  lea     rbp, [rsp+50h]
0x14000bf17  mov     [rbp+30h+arg_0], rbx
0x14000bf1b  mov     [rbp+30h+arg_8], rsi
0x14000bf1f  mov     [rbp+30h+arg_10], rdi
0x14000bf23  mov     rax, cs:__security_cookie
0x14000bf2a  xor     rax, rbp
0x14000bf2d  mov     [rbp+30h+var_28], rax
0x14000bf31  movsxd  rbx, [rbp+30h+arg_20]
0x14000bf35  mov     r15, r9
0x14000bf38  mov     [rbp+30h+var_30], rdx
0x14000bf3c  mov     r13d, r8d
0x14000bf3f  mov     rdi, rcx
0x14000bf42  test    ebx, ebx
0x14000bf44  jle     short loc_14000BF5A
0x14000bf46  mov     rdx, rbx; Count
0x14000bf49  mov     rcx, r9; String
0x14000bf4c  call    __strncnt
0x14000bf51  cmp     eax, ebx
0x14000bf53  lea     ebx, [rax+1]
0x14000bf56  jl      short loc_14000BF5A
0x14000bf58  mov     ebx, eax
0x14000bf5a  mov     r14d, [rbp+30h+CodePage]
0x14000bf5e  test    r14d, r14d
0x14000bf61  jnz     short loc_14000BF6A
0x14000bf63  mov     rax, [rdi]
0x14000bf66  mov     r14d, [rax+0Ch]
0x14000bf6a  neg     [rbp+30h+arg_40]
0x14000bf70  mov     r9d, ebx; cbMultiByte
0x14000bf73  mov     r8, r15; lpMultiByteStr
0x14000bf76  mov     ecx, r14d; CodePage
0x14000bf79  sbb     edx, edx
0x14000bf7b  and     [rsp+80h+cchWideChar], 0
0x14000bf80  and     [rsp+80h+lpWideCharStr], 0
0x14000bf86  and     edx, 8
0x14000bf89  inc     edx; dwFlags
0x14000bf8b  call    cs:MultiByteToWideChar; KERNEL32
0x14000bf91  movsxd  r12, eax
0x14000bf94  test    eax, eax
0x14000bf96  jz      loc_14000C217
0x14000bf9c  mov     rdx, r12
0x14000bf9f  mov     r8, 0FFFFFFFFFFFFFF0h
0x14000bfa9  add     rdx, rdx
0x14000bfac  lea     rcx, [rdx+10h]
0x14000bfb0  cmp     rdx, rcx
0x14000bfb3  sbb     rax, rax
0x14000bfb6  test    rcx, rax
0x14000bfb9  jz      short loc_14000C02D
0x14000bfbb  lea     rcx, [rdx+10h]
0x14000bfbf  cmp     rdx, rcx
0x14000bfc2  sbb     rax, rax
0x14000bfc5  and     rax, rcx
0x14000bfc8  cmp     rax, 400h
0x14000bfce  lea     rax, [rdx+10h]
0x14000bfd2  ja      short loc_14000C00B
0x14000bfd4  cmp     rdx, rax
0x14000bfd7  sbb     rcx, rcx
0x14000bfda  and     rcx, rax
0x14000bfdd  lea     rax, [rcx+0Fh]
0x14000bfe1  cmp     rax, rcx
0x14000bfe4  ja      short loc_14000BFE9
0x14000bfe6  mov     rax, r8
0x14000bfe9  and     rax, 0FFFFFFFFFFFFFFF0h
0x14000bfed  call    _alloca_probe
0x14000bff2  sub     rsp, rax
0x14000bff5  lea     rsi, [rsp+80h+var_30]
0x14000bffa  test    rsi, rsi
0x14000bffd  jz      loc_14000C1FD
0x14000c003  mov     dword ptr [rsi], 0CCCCh
0x14000c009  jmp     short loc_14000C027
0x14000c00b  cmp     rdx, rax
0x14000c00e  sbb     rcx, rcx
0x14000c011  and     rcx, rax; Size
0x14000c014  call    _malloc_base
0x14000c019  mov     rsi, rax
0x14000c01c  test    rax, rax
0x14000c01f  jz      short loc_14000C02F
0x14000c021  mov     dword ptr [rax], 0DDDDh
0x14000c027  add     rsi, 10h
0x14000c02b  jmp     short loc_14000C02F
0x14000c02d  xor     esi, esi
0x14000c02f  test    rsi, rsi
0x14000c032  jz      loc_14000C1FD
0x14000c038  mov     [rsp+80h+cchWideChar], r12d; cchWideChar
0x14000c03d  mov     r9d, ebx; cbMultiByte
0x14000c040  mov     r8, r15; lpMultiByteStr
0x14000c043  mov     [rsp+80h+lpWideCharStr], rsi; lpWideCharStr
0x14000c048  mov     edx, 1; dwFlags
0x14000c04d  mov     ecx, r14d; CodePage
0x14000c050  call    cs:MultiByteToWideChar; KERNEL32
0x14000c056  test    eax, eax
0x14000c058  jz      loc_14000C1FD
0x14000c05e  and     [rsp+80h+var_40], 0
0x14000c064  mov     r9d, r12d
0x14000c067  and     [rsp+80h+var_48], 0
0x14000c06d  mov     r8, rsi
0x14000c070  and     [rsp+80h+var_50], 0
0x14000c076  mov     edx, r13d
0x14000c079  mov     r15, [rbp+30h+var_30]
0x14000c07d  and     [rsp+80h+cchWideChar], 0
0x14000c082  mov     rcx, r15
0x14000c085  and     [rsp+80h+lpWideCharStr], 0
0x14000c08b  call    __acrt_LCMapStringEx
0x14000c090  movsxd  rdi, eax
0x14000c093  test    eax, eax
0x14000c095  jz      loc_14000C1FD
0x14000c09b  mov     r8d, 400h
0x14000c0a1  test    r8d, r13d
0x14000c0a4  jz      short loc_14000C0F8
0x14000c0a6  mov     eax, [rbp+30h+arg_30]
0x14000c0a9  test    eax, eax
0x14000c0ab  jz      loc_14000C1FF
0x14000c0b1  cmp     edi, eax
0x14000c0b3  jg      loc_14000C1FD
0x14000c0b9  and     [rsp+80h+var_40], 0
0x14000c0bf  mov     r9d, r12d
0x14000c0c2  and     [rsp+80h+var_48], 0
0x14000c0c8  mov     r8, rsi
0x14000c0cb  and     [rsp+80h+var_50], 0
0x14000c0d1  mov     edx, r13d
0x14000c0d4  mov     [rsp+80h+cchWideChar], eax
0x14000c0d8  mov     rcx, r15
0x14000c0db  mov     rax, [rbp+30h+arg_28]
0x14000c0df  mov     [rsp+80h+lpWideCharStr], rax
0x14000c0e4  call    __acrt_LCMapStringEx
0x14000c0e9  mov     edi, eax
0x14000c0eb  test    eax, eax
0x14000c0ed  jnz     loc_14000C1FF
0x14000c0f3  jmp     loc_14000C1FD
0x14000c0f8  mov     rdx, rdi
0x14000c0fb  add     rdx, rdx
0x14000c0fe  lea     rcx, [rdx+10h]
0x14000c102  cmp     rdx, rcx
0x14000c105  sbb     rax, rax
0x14000c108  test    rcx, rax
0x14000c10b  jz      short loc_14000C183
0x14000c10d  lea     rcx, [rdx+10h]
0x14000c111  cmp     rdx, rcx
0x14000c114  sbb     rax, rax
0x14000c117  and     rax, rcx
0x14000c11a  cmp     rax, r8
0x14000c11d  lea     rax, [rdx+10h]
0x14000c121  ja      short loc_14000C161
0x14000c123  cmp     rdx, rax
0x14000c126  sbb     rcx, rcx
0x14000c129  and     rcx, rax
0x14000c12c  lea     rax, [rcx+0Fh]
0x14000c130  cmp     rax, rcx
0x14000c133  ja      short loc_14000C13F
0x14000c135  mov     rax, 0FFFFFFFFFFFFFF0h
0x14000c13f  and     rax, 0FFFFFFFFFFFFFFF0h
0x14000c143  call    _alloca_probe
0x14000c148  sub     rsp, rax
0x14000c14b  lea     rbx, [rsp+80h+var_30]
0x14000c150  test    rbx, rbx
0x14000c153  jz      loc_14000C1FD
0x14000c159  mov     dword ptr [rbx], 0CCCCh
0x14000c15f  jmp     short loc_14000C17D
0x14000c161  cmp     rdx, rax
0x14000c164  sbb     rcx, rcx
0x14000c167  and     rcx, rax; Size
0x14000c16a  call    _malloc_base
0x14000c16f  mov     rbx, rax
0x14000c172  test    rax, rax
0x14000c175  jz      short loc_14000C185
0x14000c177  mov     dword ptr [rax], 0DDDDh
0x14000c17d  add     rbx, 10h
0x14000c181  jmp     short loc_14000C185
0x14000c183  xor     ebx, ebx
0x14000c185  test    rbx, rbx
0x14000c188  jz      short loc_14000C1FD
0x14000c18a  and     [rsp+80h+var_40], 0
0x14000c190  mov     r9d, r12d
0x14000c193  and     [rsp+80h+var_48], 0
0x14000c199  mov     r8, rsi
0x14000c19c  and     [rsp+80h+var_50], 0
0x14000c1a2  mov     edx, r13d
0x14000c1a5  mov     [rsp+80h+cchWideChar], edi; cbMultiByte
0x14000c1a9  mov     rcx, r15
0x14000c1ac  mov     [rsp+80h+lpWideCharStr], rbx; lpMultiByteStr
0x14000c1b1  call    __acrt_LCMapStringEx
0x14000c1b6  test    eax, eax
0x14000c1b8  jz      short loc_14000C1EC
0x14000c1ba  and     [rsp+80h+var_48], 0
0x14000c1c0  xor     edx, edx; dwFlags
0x14000c1c2  and     [rsp+80h+var_50], rdx
0x14000c1c7  mov     r9d, edi; cchWideChar
0x14000c1ca  mov     eax, [rbp+30h+arg_30]
0x14000c1cd  mov     r8, rbx; lpWideCharStr
0x14000c1d0  mov     ecx, r14d; CodePage
0x14000c1d3  test    eax, eax
0x14000c1d5  jnz     short loc_14000C23D
0x14000c1d7  and     [rsp+80h+cchWideChar], edx
0x14000c1db  and     [rsp+80h+lpWideCharStr], rdx
0x14000c1e0  call    cs:WideCharToMultiByte; KERNEL32
0x14000c1e6  mov     edi, eax
0x14000c1e8  test    eax, eax
0x14000c1ea  jnz     short loc_14000C24C
0x14000c1ec  lea     rcx, [rbx-10h]; Block
0x14000c1f0  cmp     dword ptr [rcx], 0DDDDh
0x14000c1f6  jnz     short loc_14000C1FD
0x14000c1f8  call    _free_base
0x14000c1fd  xor     edi, edi
0x14000c1ff  test    rsi, rsi
0x14000c202  jz      short loc_14000C215
0x14000c204  lea     rcx, [rsi-10h]; Block
0x14000c208  cmp     dword ptr [rcx], 0DDDDh
0x14000c20e  jnz     short loc_14000C215
0x14000c210  call    _free_base
0x14000c215  mov     eax, edi
0x14000c217  mov     rcx, [rbp+30h+var_28]
0x14000c21b  xor     rcx, rbp; StackCookie
0x14000c21e  call    __security_check_cookie
0x14000c223  mov     rbx, [rbp+30h+arg_0]
0x14000c227  mov     rsi, [rbp+30h+arg_8]
0x14000c22b  mov     rdi, [rbp+30h+arg_10]
0x14000c22f  lea     rsp, [rbp+10h]
0x14000c233  pop     r15
0x14000c235  pop     r14
0x14000c237  pop     r13
0x14000c239  pop     r12
0x14000c23b  pop     rbp
0x14000c23c  retn
0x14000c23d  mov     [rsp+80h+cchWideChar], eax
0x14000c241  mov     rax, [rbp+30h+arg_28]
0x14000c245  mov     [rsp+80h+lpWideCharStr], rax
0x14000c24a  jmp     short loc_14000C1E0
0x14000c24c  lea     rcx, [rbx-10h]; Block
0x14000c250  cmp     dword ptr [rcx], 0DDDDh
0x14000c256  jnz     short loc_14000C1FF
0x14000c258  call    _free_base
0x14000c25d  jmp     short loc_14000C1FF

// ===== __acrt_LCMapStringA @ 0x14000c260 =====

0x14000c260  mov     [rsp+arg_0], rbx
0x14000c265  mov     [rsp+arg_8], rsi
0x14000c26a  push    rdi
0x14000c26b  sub     rsp, 70h
0x14000c26f  mov     rsi, rdx
0x14000c272  mov     rbx, r9
0x14000c275  mov     rdx, rcx; struct __crt_locale_pointers *
0x14000c278  mov     edi, r8d
0x14000c27b  lea     rcx, [rsp+78h+var_28]; this
0x14000c280  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000c285  mov     eax, [rsp+78h+arg_40]
0x14000c28c  lea     rcx, [rsp+78h+var_20]; struct __crt_locale_pointers *
0x14000c291  mov     [rsp+78h+var_38], eax; int
0x14000c295  mov     r9, rbx; char *
0x14000c298  mov     eax, [rsp+78h+arg_38]
0x14000c29f  mov     r8d, edi; unsigned int
0x14000c2a2  mov     [rsp+78h+var_40], eax; int
0x14000c2a6  mov     rdx, rsi; wchar_t *
0x14000c2a9  mov     eax, [rsp+78h+arg_30]
0x14000c2b0  mov     [rsp+78h+var_48], eax; int
0x14000c2b4  mov     rax, [rsp+78h+arg_28]
0x14000c2bc  mov     [rsp+78h+var_50], rax; char *
0x14000c2c1  mov     eax, [rsp+78h+arg_20]
0x14000c2c8  mov     [rsp+78h+var_58], eax; int
0x14000c2cc  call    ?__acrt_LCMapStringA_stat@@YAHPEAU__crt_locale_pointers@@PEB_WKPEBDHPEADHHH@Z
0x14000c2d1  cmp     [rsp+78h+var_10], 0
0x14000c2d6  jz      short loc_14000C2E4
0x14000c2d8  mov     rcx, [rsp+78h+var_28]
0x14000c2dd  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x14000c2e4  lea     r11, [rsp+78h+var_8]
0x14000c2e9  mov     rbx, [r11+10h]
0x14000c2ed  mov     rsi, [r11+18h]
0x14000c2f1  mov     rsp, r11
0x14000c2f4  pop     rdi
0x14000c2f5  retn

// ===== __acrt_fp_strflt_to_string @ 0x14000c2f8 =====

0x14000c2f8  push    rbx
0x14000c2fa  sub     rsp, 20h
0x14000c2fe  xor     ebx, ebx
0x14000c300  test    rcx, rcx
0x14000c303  jnz     short loc_14000C31D
0x14000c305  call    _errno
0x14000c30a  mov     ebx, 16h
0x14000c30f  mov     [rax], ebx
0x14000c311  call    _invalid_parameter_noinfo
0x14000c316  mov     eax, ebx
0x14000c318  jmp     loc_14000C3B1
0x14000c31d  test    rdx, rdx
0x14000c320  jz      short loc_14000C305
0x14000c322  test    r8d, r8d
0x14000c325  mov     [rcx], bl
0x14000c327  mov     eax, ebx
0x14000c329  cmovg   eax, r8d
0x14000c32d  inc     eax
0x14000c32f  cdqe
0x14000c331  cmp     rdx, rax
0x14000c334  ja      short loc_14000C342
0x14000c336  call    _errno
0x14000c33b  mov     ebx, 22h ; '"'
0x14000c340  jmp     short loc_14000C30F
0x14000c342  test    r9, r9
0x14000c345  jz      short loc_14000C305
0x14000c347  mov     rdx, [r9+8]
0x14000c34b  lea     rax, [rcx+1]
0x14000c34f  mov     byte ptr [rcx], 30h ; '0'
0x14000c352  jmp     short loc_14000C36D
0x14000c354  mov     r10b, [rdx]
0x14000c357  test    r10b, r10b
0x14000c35a  jz      short loc_14000C361
0x14000c35c  inc     rdx
0x14000c35f  jmp     short loc_14000C364
0x14000c361  mov     r10b, 30h ; '0'
0x14000c364  mov     [rax], r10b
0x14000c367  inc     rax
0x14000c36a  dec     r8d
0x14000c36d  test    r8d, r8d
0x14000c370  jg      short loc_14000C354
0x14000c372  mov     [rax], bl
0x14000c374  js      short loc_14000C38A
0x14000c376  cmp     byte ptr [rdx], 35h ; '5'
0x14000c379  jl      short loc_14000C38A
0x14000c37b  jmp     short loc_14000C380
0x14000c37d  mov     byte ptr [rax], 30h ; '0'
0x14000c380  dec     rax
0x14000c383  cmp     byte ptr [rax], 39h ; '9'
0x14000c386  jz      short loc_14000C37D
0x14000c388  inc     byte ptr [rax]
0x14000c38a  cmp     byte ptr [rcx], 31h ; '1'
0x14000c38d  jnz     short loc_14000C395
0x14000c38f  inc     dword ptr [r9+4]
0x14000c393  jmp     short loc_14000C3AF
0x14000c395  or      r8, 0FFFFFFFFFFFFFFFFh
0x14000c399  inc     r8
0x14000c39c  cmp     [rcx+r8+1], bl
0x14000c3a1  jnz     short loc_14000C399
0x14000c3a3  inc     r8
0x14000c3a6  lea     rdx, [rcx+1]
0x14000c3aa  call    sub_1400036D0
0x14000c3af  xor     eax, eax
0x14000c3b1  add     rsp, 20h
0x14000c3b5  pop     rbx
0x14000c3b6  retn

// ===== ?divide@__crt_strtox@@YA_KAEAUbig_integer@1@AEBU21@@Z @ 0x14000c3c0 =====

0x14000c3c0  mov     [rsp+arg_8], rdx
0x14000c3c5  push    rsi
0x14000c3c6  push    rdi
0x14000c3c7  sub     rsp, 248h
0x14000c3ce  mov     r9d, [rcx]
0x14000c3d1  mov     rdi, rdx
0x14000c3d4  mov     rsi, rcx
0x14000c3d7  test    r9d, r9d
0x14000c3da  jnz     short loc_14000C3E8
0x14000c3dc  xor     eax, eax
0x14000c3de  add     rsp, 248h
0x14000c3e5  pop     rdi
0x14000c3e6  pop     rsi
0x14000c3e7  retn
0x14000c3e8  mov     eax, [rdx]
0x14000c3ea  test    eax, eax
0x14000c3ec  jz      short loc_14000C3DC
0x14000c3ee  mov     [rsp+258h+var_18], rbx
0x14000c3f6  dec     r9d
0x14000c3f9  mov     [rsp+258h+var_20], rbp
0x14000c401  mov     [rsp+258h+var_28], r12
0x14000c409  mov     [rsp+258h+var_38], r14
0x14000c411  mov     [rsp+258h+var_40], r15
0x14000c419  sub     eax, 1
0x14000c41c  jnz     loc_14000C514
0x14000c422  mov     r15d, [rdx+4]
0x14000c426  xor     r14d, r14d
0x14000c429  cmp     r15d, 1
0x14000c42d  jnz     short loc_14000C457
0x14000c42f  mov     ebx, [rcx+4]
0x14000c432  lea     r8, [rsp+258h+Source]; Source
0x14000c437  add     rcx, 4; Destination
0x14000c43b  mov     [rsi], r14d
0x14000c43e  xor     r9d, r9d; SourceSize
0x14000c441  mov     [rsp+258h+var_218], r14d
0x14000c446  mov     edx, 1CCh; DestinationSize
0x14000c44b  call    memcpy_s
0x14000c450  mov     eax, ebx
0x14000c452  jmp     loc_14000C85C
0x14000c457  test    r9d, r9d
0x14000c45a  jnz     short loc_14000C495
0x14000c45c  mov     ebx, [rcx+4]
0x14000c45f  lea     r8, [rsp+258h+Source]; Source
0x14000c464  mov     [rcx], r14d
0x14000c467  xor     r9d, r9d; SourceSize
0x14000c46a  add     rcx, 4; Destination
0x14000c46e  mov     [rsp+258h+var_218], r14d
0x14000c473  mov     edx, 1CCh; DestinationSize
0x14000c478  call    memcpy_s
0x14000c47d  xor     edx, edx
0x14000c47f  mov     eax, ebx
0x14000c481  div     r15d
0x14000c484  test    edx, edx
0x14000c486  mov     [rsi+4], edx
0x14000c489  setnz   r14b
0x14000c48d  mov     [rsi], r14d
0x14000c490  jmp     loc_14000C85C
0x14000c495  mov     r12d, 0FFFFFFFFh
0x14000c49b  mov     rdi, r14
0x14000c49e  mov     rbp, r14
0x14000c4a1  cmp     r9d, r12d
0x14000c4a4  jz      short loc_14000C4D5
0x14000c4a6  mov     rcx, r15
0x14000c4a9  nop     dword ptr [rax+00000000h]
0x14000c4b0  mov     eax, [rsi+r9*4+4]
0x14000c4b5  xor     edx, edx
0x14000c4b7  shl     rbp, 20h
0x14000c4bb  add     r9d, r12d
0x14000c4be  or      rax, rbp
0x14000c4c1  shl     rdi, 20h
0x14000c4c5  div     rcx
0x14000c4c8  mov     eax, eax
0x14000c4ca  mov     rbp, rdx
0x14000c4cd  add     rdi, rax
0x14000c4d0  cmp     r9d, r12d
0x14000c4d3  jnz     short loc_14000C4B0
0x14000c4d5  xor     r9d, r9d; SourceSize
0x14000c4d8  mov     [rsp+258h+var_218], r14d
0x14000c4dd  lea     r8, [rsp+258h+Source]; Source
0x14000c4e2  mov     [rsi], r14d
0x14000c4e5  mov     edx, 1CCh; DestinationSize
0x14000c4ea  lea     rcx, [rsi+4]; Destination
0x14000c4ee  call    memcpy_s
0x14000c4f3  mov     rcx, rbp
0x14000c4f6  mov     [rsi+4], ebp
0x14000c4f9  shr     rcx, 20h
0x14000c4fd  mov     rax, rdi
0x14000c500  test    ecx, ecx
0x14000c502  mov     [rsi+8], ecx
0x14000c505  setnz   r14b
0x14000c509  inc     r14d
0x14000c50c  mov     [rsi], r14d
0x14000c50f  jmp     loc_14000C85C
0x14000c514  cmp     eax, r9d
0x14000c517  jbe     short loc_14000C520
0x14000c519  xor     eax, eax
0x14000c51b  jmp     loc_14000C85C
0x14000c520  mov     r8d, r9d
0x14000c523  movsxd  rdx, r9d
0x14000c526  sub     r8d, eax
0x14000c529  mov     [rsp+258h+var_30], r13
0x14000c531  movsxd  rbx, r8d
0x14000c534  lea     r13d, [rax+1]
0x14000c538  mov     r10d, r9d
0x14000c53b  cmp     rdx, rbx
0x14000c53e  jl      short loc_14000C58C
0x14000c540  add     rcx, 4
0x14000c544  lea     rax, ds:0[rbx*4]
0x14000c54c  mov     r11, rdi
0x14000c54f  sub     r11, rax
0x14000c552  sub     r11, rsi
0x14000c555  lea     rcx, [rcx+rdx*4]
0x14000c559  nop     dword ptr [rax+00000000h]
0x14000c560  mov     eax, [rcx]
0x14000c562  cmp     [r11+rcx], eax
0x14000c566  jnz     short loc_14000C579
0x14000c568  dec     r10d
0x14000c56b  dec     rdx
0x14000c56e  sub     rcx, 4
0x14000c572  cmp     rdx, rbx
0x14000c575  jge     short loc_14000C560
0x14000c577  jmp     short loc_14000C58C
0x14000c579  movsxd  rax, r10d
0x14000c57c  mov     rcx, rax
0x14000c57f  sub     rcx, rbx
0x14000c582  mov     eax, [rsi+rax*4+4]
0x14000c586  cmp     [rdi+rcx*4+4], eax
0x14000c58a  jnb     short loc_14000C58F
0x14000c58c  inc     r8d
0x14000c58f  test    r8d, r8d
0x14000c592  jnz     short loc_14000C59B
0x14000c594  xor     eax, eax
0x14000c596  jmp     loc_14000C854
0x14000c59b  lea     eax, [r13-1]
0x14000c59f  mov     r11d, 20h ; ' '
0x14000c5a5  mov     r10d, [rdi+rax*4+4]
0x14000c5aa  lea     eax, [r13-2]
0x14000c5ae  mov     ebx, [rdi+rax*4+4]
0x14000c5b2  bsr     eax, r10d
0x14000c5b6  mov     [rsp+258h+arg_18], ebx
0x14000c5bd  jz      short loc_14000C5C8
0x14000c5bf  mov     edx, 1Fh
0x14000c5c4  sub     edx, eax
0x14000c5c6  jmp     short loc_14000C5CB
0x14000c5c8  mov     edx, r11d
0x14000c5cb  sub     r11d, edx
0x14000c5ce  mov     [rsp+258h+arg_10], edx
0x14000c5d5  mov     dword ptr [rsp+258h+var_238], r11d
0x14000c5da  test    edx, edx
0x14000c5dc  jz      short loc_14000C61E
0x14000c5de  mov     eax, r10d
0x14000c5e1  mov     edx, ebx
0x14000c5e3  mov     ecx, r11d
0x14000c5e6  shr     edx, cl
0x14000c5e8  mov     ecx, [rsp+258h+arg_10]
0x14000c5ef  mov     r10d, edx
0x14000c5f2  shl     eax, cl
0x14000c5f4  mov     edx, ecx
0x14000c5f6  shl     ebx, cl
0x14000c5f8  or      r10d, eax
0x14000c5fb  mov     [rsp+258h+arg_18], ebx
0x14000c602  cmp     r13d, 2
0x14000c606  jbe     short loc_14000C61E
0x14000c608  lea     eax, [r13-3]
0x14000c60c  mov     ecx, r11d
0x14000c60f  mov     eax, [rdi+rax*4+4]
0x14000c613  shr     eax, cl
0x14000c615  or      ebx, eax
0x14000c617  mov     [rsp+258h+arg_18], ebx
0x14000c61e  xor     r14d, r14d
0x14000c621  lea     ebx, [r8-1]
0x14000c625  mov     [rsp+258h+arg_0], ebx
0x14000c62c  mov     r15d, r14d
0x14000c62f  test    ebx, ebx
0x14000c631  js      loc_14000C816
0x14000c637  mov     eax, r11d
0x14000c63a  lea     edi, [rbx+r13]
0x14000c63e  mov     r11d, r10d
0x14000c641  mov     r12d, 0FFFFFFFFh
0x14000c647  mov     [rsp+258h+var_228], r11
0x14000c64c  mov     [rsp+258h+var_220], rax
0x14000c651  cmp     edi, r9d
0x14000c654  ja      short loc_14000C65C
0x14000c656  mov     ebp, [rsi+rdi*4+4]
0x14000c65a  jmp     short loc_14000C65F
0x14000c65c  mov     ebp, r14d
0x14000c65f  lea     eax, [rdi-1]
0x14000c662  mov     ecx, [rsi+rax*4+4]
0x14000c666  lea     eax, [rdi-2]
0x14000c669  mov     r10d, [rsi+rax*4+4]
0x14000c66e  mov     [rsp+258h+var_230], rcx
0x14000c673  mov     dword ptr [rsp+258h+var_230+4], ebp
0x14000c677  test    edx, edx
0x14000c679  jz      short loc_14000C6AD
0x14000c67b  mov     rcx, [rsp+258h+var_220]
0x14000c680  mov     r8d, r10d
0x14000c683  mov     rax, [rsp+258h+var_230]
0x14000c688  shr     r8, cl
0x14000c68b  mov     ecx, edx
0x14000c68d  shl     rax, cl
0x14000c690  or      r8, rax
0x14000c693  shl     r10d, cl
0x14000c696  cmp     edi, 3
0x14000c699  jb      short loc_14000C6B2
0x14000c69b  mov     ecx, dword ptr [rsp+258h+var_238]
0x14000c69f  lea     eax, [rdi-3]
0x14000c6a2  mov     eax, [rsi+rax*4+4]
0x14000c6a6  shr     eax, cl
0x14000c6a8  or      r10d, eax
0x14000c6ab  jmp     short loc_14000C6B2
0x14000c6ad  mov     r8, [rsp+258h+var_230]
0x14000c6b2  xor     edx, edx
0x14000c6b4  mov     rax, r8
0x14000c6b7  div     r11
0x14000c6ba  mov     ecx, edx
0x14000c6bc  mov     r8, rax
0x14000c6bf  cmp     rax, r12
0x14000c6c2  jbe     short loc_14000C6DB
0x14000c6c4  mov     rax, 0FFFFFFFF00000001h
0x14000c6ce  add     rax, r8
0x14000c6d1  mov     r8, r12
0x14000c6d4  imul    rax, r11
0x14000c6d8  add     rcx, rax
0x14000c6db  cmp     rcx, r12
0x14000c6de  ja      short loc_14000C724
0x14000c6e0  mov     rbx, [rsp+258h+var_228]
0x14000c6e5  mov     r11d, r10d
0x14000c6e8  mov     r10d, [rsp+258h+arg_18]
0x14000c6f0  mov     edx, r10d
0x14000c6f3  imul    rdx, r8
0x14000c6f7  neg     r10
0x14000c6fa  nop     word ptr [rax+rax+00h]
0x14000c700  mov     rax, rcx
0x14000c703  shl     rax, 20h
0x14000c707  or      rax, r11
0x14000c70a  cmp     rdx, rax
0x14000c70d  jbe     short loc_14000C71D
0x14000c70f  dec     r8
0x14000c712  add     rdx, r10
0x14000c715  add     rcx, rbx
0x14000c718  cmp     rcx, r12
0x14000c71b  jbe     short loc_14000C700
0x14000c71d  mov     ebx, [rsp+258h+arg_0]
0x14000c724  test    r8, r8
0x14000c727  jz      loc_14000C7ED
0x14000c72d  mov     rcx, r14
0x14000c730  test    r13d, r13d
0x14000c733  jz      short loc_14000C78D
0x14000c735  mov     r9, [rsp+258h+arg_8]
0x14000c73d  mov     edx, ebx
0x14000c73f  add     r9, 4
0x14000c743  mov     ebx, r13d
0x14000c746  nop     word ptr [rax+rax+00000000h]
0x14000c750  mov     eax, [r9]
0x14000c753  imul    rax, r8
0x14000c757  add     rcx, rax
0x14000c75a  mov     eax, edx
0x14000c75c  mov     r10d, ecx
0x14000c75f  shr     rcx, 20h
0x14000c763  lea     r11, [rsi+rax*4]
0x14000c767  mov     eax, [rsi+rax*4+4]
0x14000c76b  cmp     eax, r10d
0x14000c76e  jnb     short loc_14000C773
0x14000c770  inc     rcx
0x14000c773  sub     eax, r10d
0x14000c776  inc     edx
0x14000c778  add     r9, 4
0x14000c77c  mov     [r11+4], eax
0x14000c780  sub     rbx, 1
0x14000c784  jnz     short loc_14000C750
0x14000c786  mov     ebx, [rsp+258h+arg_0]
0x14000c78d  mov     eax, ebp
0x14000c78f  cmp     rax, rcx
0x14000c792  jnb     short loc_14000C7E2
0x14000c794  mov     r9d, r14d
0x14000c797  test    r13d, r13d
0x14000c79a  jz      short loc_14000C7DF
0x14000c79c  mov     r11, [rsp+258h+arg_8]
0x14000c7a4  mov     r10d, ebx
0x14000c7a7  add     r11, 4
0x14000c7ab  mov     ebx, r13d
0x14000c7ae  xchg    ax, ax
0x14000c7b0  mov     eax, r10d
0x14000c7b3  lea     r11, [r11+4]
0x14000c7b7  mov     edx, [rsi+rax*4+4]
0x14000c7bb  lea     rcx, [rsi+rax*4]
0x14000c7bf  mov     eax, [r11-4]
0x14000c7c3  inc     r10d
0x14000c7c6  add     rdx, rax
0x14000c7c9  mov     eax, r9d
0x14000c7cc  add     rdx, rax
0x14000c7cf  mov     r9, rdx
0x14000c7d2  mov     [rcx+4], edx
0x14000c7d5  shr     r9, 20h
0x14000c7d9  sub     rbx, 1
0x14000c7dd  jnz     short loc_14000C7B0
0x14000c7df  dec     r8
0x14000c7e2  mov     ebx, [rsp+258h+arg_0]
0x14000c7e9  lea     r9d, [rdi-1]
0x14000c7ed  mov     r11, [rsp+258h+var_228]
0x14000c7f2  dec     ebx
0x14000c7f4  mov     edx, [rsp+258h+arg_10]
0x14000c7fb  dec     edi
0x14000c7fd  shl     r15, 20h
0x14000c801  mov     eax, r8d
0x14000c804  add     r15, rax
0x14000c807  mov     [rsp+258h+arg_0], ebx
0x14000c80e  test    ebx, ebx
0x14000c810  jns     loc_14000C651
0x14000c816  inc     r9d
0x14000c819  mov     ecx, r9d
0x14000c81c  cmp     r9d, [rsi]
0x14000c81f  jnb     short loc_14000C82E
0x14000c821  mov     eax, ecx
0x14000c823  inc     ecx
0x14000c825  mov     [rsi+rax*4+4], r14d
0x14000c82a  cmp     ecx, [rsi]
0x14000c82c  jb      short loc_14000C821
0x14000c82e  mov     [rsi], r9d
0x14000c831  test    r9d, r9d
0x14000c834  jz      short loc_14000C851
0x14000c836  nop     word ptr [rax+rax+00000000h]
0x14000c840  mov     edx, [rsi]
0x14000c842  dec     edx
0x14000c844  cmp     [rsi+rdx*4+4], r14d
0x14000c849  jnz     short loc_14000C851
0x14000c84b  mov     [rsi], edx
0x14000c84d  test    edx, edx
0x14000c84f  jnz     short loc_14000C840
0x14000c851  mov     rax, r15
0x14000c854  mov     r13, [rsp+258h+var_30]
0x14000c85c  mov     r14, [rsp+258h+var_38]
0x14000c864  mov     r12, [rsp+258h+var_28]
0x14000c86c  mov     rbp, [rsp+258h+var_20]
0x14000c874  mov     rbx, [rsp+258h+var_18]
0x14000c87c  mov     r15, [rsp+258h+var_40]
0x14000c884  add     rsp, 248h
0x14000c88b  pop     rdi
0x14000c88c  pop     rsi
0x14000c88d  retn

// ===== __acrt_fltout @ 0x14000c890 =====

0x14000c890  push    rbp
0x14000c892  push    rbx
0x14000c893  push    rsi
0x14000c894  push    rdi
0x14000c895  push    r12
0x14000c897  push    r13
0x14000c899  push    r14
0x14000c89b  push    r15
0x14000c89d  lea     rbp, [rsp-6D8h]
0x14000c8a5  sub     rsp, 7D8h
0x14000c8ac  mov     rax, cs:__security_cookie
0x14000c8b3  xor     rax, rsp
0x14000c8b6  mov     [rbp+710h+var_50], rax
0x14000c8bd  mov     [rsp+810h+X], rcx
0x14000c8c2  mov     r14, r9
0x14000c8c5  lea     rcx, [rsp+810h+Env]; Env
0x14000c8ca  mov     [rsp+810h+var_7C0], r9
0x14000c8cf  mov     r15, r8
0x14000c8d2  mov     [rsp+810h+var_7A0], r8
0x14000c8d7  mov     esi, edx
0x14000c8d9  call    fegetenv
0x14000c8de  mov     eax, [rsp+810h+Env._Fe_ctl]
0x14000c8e2  xor     r13d, r13d
0x14000c8e5  and     eax, 1Fh
0x14000c8e8  cmp     al, 1Fh
0x14000c8ea  jnz     short loc_14000C8F3
0x14000c8ec  mov     [rsp+810h+var_7A8], r13b
0x14000c8f1  jmp     short loc_14000C902
0x14000c8f3  lea     rcx, [rsp+810h+Env]; Env
0x14000c8f8  call    feholdexcept
0x14000c8fd  mov     [rsp+810h+var_7A8], 1
0x14000c902  mov     rbx, [rsp+810h+X]
0x14000c907  mov     rcx, 8000000000000000h
0x14000c911  mov     rax, rbx
0x14000c914  mov     [r15+8], r14
0x14000c918  and     rax, rcx
0x14000c91b  mov     edi, 20h ; ' '
0x14000c920  neg     rax
0x14000c923  mov     r12, 0FFFFFFFFFFFFFh
0x14000c92d  mov     rax, 7FF0000000000000h
0x14000c937  sbb     ecx, ecx
0x14000c939  and     ecx, 0Dh
0x14000c93c  add     ecx, edi
0x14000c93e  mov     [r15], ecx
0x14000c941  test    rax, rbx
0x14000c944  jnz     short loc_14000C972
0x14000c946  test    r12, rbx
0x14000c949  jnz     short loc_14000C972
0x14000c94b  mov     rdx, [rbp+710h+SizeInBytes]; SizeInBytes
0x14000c952  lea     r8, a0
0x14000c959  mov     rcx, r14; Destination
0x14000c95c  mov     [r15+4], r13d
0x14000c960  call    strcpy_s
0x14000c965  test    eax, eax
0x14000c967  jz      loc_14000DB5E
0x14000c96d  jmp     loc_14000DB92
0x14000c972  lea     rcx, [rsp+810h+X]
0x14000c977  call    ?__acrt_fp_classify@@YA?AW4__acrt_fp_class@@AEBN@Z
0x14000c97c  test    eax, eax
0x14000c97e  jz      short loc_14000C988
0x14000c980  mov     dword ptr [r15+4], 1
0x14000c988  sub     eax, 1
0x14000c98b  jz      loc_14000DB40
0x14000c991  sub     eax, 1
0x14000c994  jz      loc_14000DB21
0x14000c99a  sub     eax, 1
0x14000c99d  jz      loc_14000DB02
0x14000c9a3  cmp     eax, 1
0x14000c9a6  jz      loc_14000DAE3
0x14000c9ac  mov     rax, 7FFFFFFFFFFFFFFFh
0x14000c9b6  mov     r9d, 7FFh
0x14000c9bc  and     rbx, rax
0x14000c9bf  inc     esi
0x14000c9c1  mov     [rsp+810h+X], rbx
0x14000c9c6  movsd   xmm0, [rsp+810h+X]; X
0x14000c9cc  movsd   [rsp+810h+var_7B8], xmm0
0x14000c9d2  mov     rdx, [rsp+810h+var_7B8]
0x14000c9d7  mov     r8, rdx
0x14000c9da  mov     [rsp+810h+var_7C4], esi
0x14000c9de  shr     r8, 34h
0x14000c9e2  test    r9, r8
0x14000c9e5  setz    cl
0x14000c9e8  mov     al, cl
0x14000c9ea  neg     al
0x14000c9ec  mov     rax, 10000000000000h
0x14000c9f6  sbb     r14, r14
0x14000c9f9  and     rdx, r12
0x14000c9fc  not     r14
0x14000c9ff  and     r14, rax
0x14000ca02  add     r14, rdx
0x14000ca05  neg     cl
0x14000ca07  sbb     eax, eax
0x14000ca09  and     r8d, r9d
0x14000ca0c  neg     eax
0x14000ca0e  inc     eax
0x14000ca10  lea     ebx, [r8-434h]
0x14000ca17  add     ebx, eax
0x14000ca19  call    log10
0x14000ca1e  call    ceil
0x14000ca23  cvttsd2si ecx, xmm0
0x14000ca27  mov     [rbp+710h+Destination], r14d
0x14000ca2b  mov     r10d, 1
0x14000ca31  lea     eax, [rcx-7FFFFFFFh]
0x14000ca37  and     eax, 0FFFFFFFEh
0x14000ca3a  neg     eax
0x14000ca3c  sbb     r12d, r12d
0x14000ca3f  shr     r14, 20h
0x14000ca43  and     r12d, ecx
0x14000ca46  mov     [rbp+710h+var_788], r14d
0x14000ca4a  mov     eax, r14d
0x14000ca4d  mov     [rsp+810h+var_7E0], r12d
0x14000ca52  neg     eax
0x14000ca54  sbb     edx, edx
0x14000ca56  neg     edx
0x14000ca58  add     edx, r10d
0x14000ca5b  mov     [rbp+710h+var_790], edx
0x14000ca5e  test    ebx, ebx
0x14000ca60  js      loc_14000CD0F
0x14000ca66  xor     eax, eax
0x14000ca68  mov     [rbp+710h+var_3E8], 100000h
0x14000ca72  mov     [rbp+710h+Source], eax
0x14000ca78  lea     esi, [rax+2]
0x14000ca7b  mov     [rbp+710h+var_3F0], esi
0x14000ca81  cmp     edx, esi
0x14000ca83  jnz     loc_14000CBEA
0x14000ca89  mov     r8d, r13d
0x14000ca8c  mov     ecx, r8d
0x14000ca8f  mov     eax, [rbp+rcx*4+710h+Destination]
0x14000ca93  cmp     [rbp+rcx*4+710h+Source], eax
0x14000ca9a  jnz     loc_14000CBEA
0x14000caa0  add     r8d, r10d
0x14000caa3  cmp     r8d, esi
0x14000caa6  jnz     short loc_14000CA8C
0x14000caa8  lea     r11d, [rbx+2]
0x14000caac  mov     dword ptr [rsp+810h+X], r13d
0x14000cab1  mov     r9d, r11d
0x14000cab4  mov     esi, edi
0x14000cab6  and     r11d, 1Fh
0x14000caba  shr     r9d, 5
0x14000cabe  sub     esi, r11d
0x14000cac1  mov     rbx, r10
0x14000cac4  mov     ecx, esi
0x14000cac6  shl     rbx, cl
0x14000cac9  sub     ebx, r10d
0x14000cacc  bsr     eax, r14d
0x14000cad0  mov     r12d, ebx
0x14000cad3  not     r12d
0x14000cad6  jz      short loc_14000CADC
0x14000cad8  inc     eax
0x14000cada  jmp     short loc_14000CADF
0x14000cadc  mov     eax, r13d
0x14000cadf  sub     edi, eax
0x14000cae1  lea     eax, [r9+2]
0x14000cae5  cmp     r11d, edi
0x14000cae8  setnbe  r15b
0x14000caec  cmp     eax, 73h ; 's'
0x14000caef  setnbe  r8b
0x14000caf3  cmp     eax, 73h ; 's'
0x14000caf6  jnz     short loc_14000CB00
0x14000caf8  mov     cl, r10b
0x14000cafb  test    r15b, r15b
0x14000cafe  jnz     short loc_14000CB03
0x14000cb00  mov     cl, r13b
0x14000cb03  or      r13d, 0FFFFFFFFh
0x14000cb07  test    r8b, r8b
0x14000cb0a  jnz     loc_14000CBB1
0x14000cb10  test    cl, cl
0x14000cb12  jnz     loc_14000CBB1
0x14000cb18  mov     r14d, 72h ; 'r'
0x14000cb1e  cmp     eax, r14d
0x14000cb21  cmovb   r14d, eax
0x14000cb25  cmp     r14d, r13d
0x14000cb28  jz      short loc_14000CB86
0x14000cb2a  mov     r8d, r14d
0x14000cb2d  sub     r8d, r9d
0x14000cb30  lea     edi, [r8+r9]
0x14000cb34  cmp     edi, r9d
0x14000cb37  jb      short loc_14000CB80
0x14000cb39  cmp     r8d, edx
0x14000cb3c  jnb     short loc_14000CB45
0x14000cb3e  mov     r10d, [rbp+r8*4+710h+Destination]
0x14000cb43  jmp     short loc_14000CB48
0x14000cb45  xor     r10d, r10d
0x14000cb48  lea     eax, [r8-1]
0x14000cb4c  cmp     eax, edx
0x14000cb4e  jnb     short loc_14000CB56
0x14000cb50  mov     edx, [rbp+rax*4+710h+Destination]
0x14000cb54  jmp     short loc_14000CB58
0x14000cb56  xor     edx, edx
0x14000cb58  and     edx, r12d
0x14000cb5b  mov     ecx, esi
0x14000cb5d  shr     edx, cl
0x14000cb5f  add     r8d, r13d
0x14000cb62  and     r10d, ebx
0x14000cb65  mov     ecx, r11d
0x14000cb68  shl     r10d, cl
0x14000cb6b  or      edx, r10d
0x14000cb6e  lea     eax, [r8+r9]
0x14000cb72  mov     [rbp+rdi*4+710h+Destination], edx
0x14000cb76  cmp     eax, r13d
0x14000cb79  jz      short loc_14000CB80
0x14000cb7b  mov     edx, [rbp+710h+var_790]
0x14000cb7e  jmp     short loc_14000CB30
0x14000cb80  mov     r10d, 1
0x14000cb86  xor     r13d, r13d
0x14000cb89  mov     ecx, r13d
0x14000cb8c  test    r9d, r9d
0x14000cb8f  jz      short loc_14000CBA0
0x14000cb91  mov     eax, ecx
0x14000cb93  add     ecx, r10d
0x14000cb96  mov     [rbp+rax*4+710h+Destination], r13d
0x14000cb9b  cmp     ecx, r9d
0x14000cb9e  jnz     short loc_14000CB91
0x14000cba0  test    r15b, r15b
0x14000cba3  lea     eax, [r14+1]
0x14000cba7  cmovnz  r14d, eax
0x14000cbab  mov     [rbp+710h+var_790], r14d
0x14000cbaf  jmp     short loc_14000CBBB
0x14000cbb1  xor     r13d, r13d
0x14000cbb4  mov     r14d, r13d
0x14000cbb7  mov     [rbp+710h+var_790], r13d
0x14000cbbb  mov     dword ptr [rbp+710h+var_5BC], 4
0x14000cbc5  mov     r12d, [rsp+810h+var_7E0]
0x14000cbca  mov     r15d, 1
0x14000cbd0  mov     [rbp+710h+var_5C0], r15d
0x14000cbd7  mov     [rbp+710h+var_3F0], r15d
0x14000cbde  mov     [rbp+710h+var_3E8], r13d
0x14000cbe5  jmp     loc_14000CF5E
0x14000cbea  and     dword ptr [rsp+810h+X], 0
0x14000cbef  lea     r11d, [rbx+1]
0x14000cbf3  mov     r9d, r11d
0x14000cbf6  lea     eax, [rdx-1]
0x14000cbf9  and     r11d, 1Fh
0x14000cbfd  shr     r9d, 5
0x14000cc01  mov     r15d, edi
0x14000cc04  mov     rbx, r10
0x14000cc07  sub     r15d, r11d
0x14000cc0a  mov     ecx, r15d
0x14000cc0d  shl     rbx, cl
0x14000cc10  sub     ebx, r10d
0x14000cc13  mov     ecx, eax
0x14000cc15  bsr     eax, [rbp+rax*4+710h+Destination]
0x14000cc1a  mov     r13d, ebx
0x14000cc1d  not     r13d
0x14000cc20  jz      short loc_14000CC26
0x14000cc22  inc     eax
0x14000cc24  jmp     short loc_14000CC28
0x14000cc26  xor     eax, eax
0x14000cc28  sub     edi, eax
0x14000cc2a  lea     eax, [rdx+r9]
0x14000cc2e  cmp     r11d, edi
0x14000cc31  setnbe  r12b
0x14000cc35  cmp     eax, 73h ; 's'
0x14000cc38  setnbe  r8b
0x14000cc3c  cmp     eax, 73h ; 's'
0x14000cc3f  jnz     short loc_14000CC4B
0x14000cc41  test    r12b, r12b
0x14000cc44  jz      short loc_14000CC4B
0x14000cc46  mov     cl, r10b
0x14000cc49  jmp     short loc_14000CC4D
0x14000cc4b  xor     cl, cl
0x14000cc4d  or      r10d, 0FFFFFFFFh
0x14000cc51  test    r8b, r8b
0x14000cc54  jnz     loc_14000CCFA
0x14000cc5a  test    cl, cl
0x14000cc5c  jnz     loc_14000CCFA
0x14000cc62  mov     r14d, 72h ; 'r'
0x14000cc68  cmp     eax, r14d
0x14000cc6b  cmovb   r14d, eax
0x14000cc6f  cmp     r14d, r10d
0x14000cc72  jz      short loc_14000CCD0
0x14000cc74  mov     r8d, r14d
0x14000cc77  sub     r8d, r9d
0x14000cc7a  lea     edi, [r8+r9]
0x14000cc7e  cmp     edi, r9d
0x14000cc81  jb      short loc_14000CCD0
0x14000cc83  cmp     r8d, edx
0x14000cc86  jnb     short loc_14000CC8F
0x14000cc88  mov     r10d, [rbp+r8*4+710h+Destination]
0x14000cc8d  jmp     short loc_14000CC92
0x14000cc8f  xor     r10d, r10d
0x14000cc92  lea     eax, [r8-1]
0x14000cc96  cmp     eax, edx
0x14000cc98  jnb     short loc_14000CCA0
0x14000cc9a  mov     edx, [rbp+rax*4+710h+Destination]
0x14000cc9e  jmp     short loc_14000CCA2
0x14000cca0  xor     edx, edx
0x14000cca2  and     r10d, ebx
0x14000cca5  mov     ecx, r11d
0x14000cca8  shl     r10d, cl
0x14000ccab  and     edx, r13d
0x14000ccae  mov     ecx, r15d
0x14000ccb1  shr     edx, cl
0x14000ccb3  or      r10d, edx
0x14000ccb6  mov     [rbp+rdi*4+710h+Destination], r10d
0x14000ccbb  or      r10d, 0FFFFFFFFh
0x14000ccbf  add     r8d, r10d
0x14000ccc2  lea     eax, [r8+r9]
0x14000ccc6  cmp     eax, r10d
0x14000ccc9  jz      short loc_14000CCD0
0x14000cccb  mov     edx, [rbp+710h+var_790]
0x14000ccce  jmp     short loc_14000CC7A
0x14000ccd0  xor     r13d, r13d
0x14000ccd3  mov     ecx, r13d
0x14000ccd6  test    r9d, r9d
0x14000ccd9  jz      short loc_14000CCE9
0x14000ccdb  mov     eax, ecx
0x14000ccdd  inc     ecx
0x14000ccdf  mov     [rbp+rax*4+710h+Destination], r13d
0x14000cce4  cmp     ecx, r9d
0x14000cce7  jnz     short loc_14000CCDB
0x14000cce9  test    r12b, r12b
0x14000ccec  lea     eax, [r14+1]
0x14000ccf0  cmovnz  r14d, eax
0x14000ccf4  mov     [rbp+710h+var_790], r14d
0x14000ccf8  jmp     short loc_14000CD04
0x14000ccfa  xor     r13d, r13d
0x14000ccfd  mov     r14d, r13d
0x14000cd00  mov     [rbp+710h+var_790], r13d
0x14000cd04  mov     dword ptr [rbp+710h+var_5BC], esi
0x14000cd0a  jmp     loc_14000CBC5
0x14000cd0f  cmp     ebx, 0FFFFFC02h
0x14000cd15  jz      loc_14000CE47
0x14000cd1b  xor     eax, eax
0x14000cd1d  mov     [rbp+710h+var_3E8], 100000h
0x14000cd27  mov     [rbp+710h+Source], eax
0x14000cd2d  lea     esi, [rax+2]
0x14000cd30  mov     [rbp+710h+var_3F0], esi
0x14000cd36  cmp     edx, esi
0x14000cd38  jnz     loc_14000CE47
0x14000cd3e  mov     r8d, r13d
0x14000cd41  mov     ecx, r8d
0x14000cd44  mov     eax, [rbp+rcx*4+710h+Destination]
0x14000cd48  cmp     [rbp+rcx*4+710h+Source], eax
0x14000cd4f  jnz     loc_14000CE47
0x14000cd55  add     r8d, r10d
0x14000cd58  cmp     r8d, esi
0x14000cd5b  jnz     short loc_14000CD41
0x14000cd5d  bsr     eax, r14d
0x14000cd61  mov     dword ptr [rsp+810h+X], r13d
0x14000cd66  jz      short loc_14000CD6C
0x14000cd68  inc     eax
0x14000cd6a  jmp     short loc_14000CD6F
0x14000cd6c  mov     eax, r13d
0x14000cd6f  sub     edi, eax
0x14000cd71  mov     ecx, esi
0x14000cd73  cmp     edi, esi
0x14000cd75  setb    r9b
0x14000cd79  or      r13d, 0FFFFFFFFh
0x14000cd7d  cmp     ecx, edx
0x14000cd7f  jnb     short loc_14000CD8A
0x14000cd81  mov     eax, ecx
0x14000cd83  mov     r8d, [rbp+rax*4+710h+Destination]
0x14000cd88  jmp     short loc_14000CD8D
0x14000cd8a  xor     r8d, r8d
0x14000cd8d  lea     eax, [rcx-1]
0x14000cd90  cmp     eax, edx
0x14000cd92  jnb     short loc_14000CD9A
0x14000cd94  mov     edx, [rbp+rax*4+710h+Destination]
0x14000cd98  jmp     short loc_14000CD9C
0x14000cd9a  xor     edx, edx
0x14000cd9c  mov     eax, r8d
0x14000cd9f  shr     edx, 1Eh
0x14000cda2  shl     eax, 2
0x14000cda5  xor     edx, eax
0x14000cda7  mov     eax, ecx
0x14000cda9  add     ecx, r13d
0x14000cdac  mov     [rbp+rax*4+710h+Destination], edx
0x14000cdb0  cmp     ecx, r13d
0x14000cdb3  jz      short loc_14000CDBA
0x14000cdb5  mov     edx, [rbp+710h+var_790]
0x14000cdb8  jmp     short loc_14000CD7D
0x14000cdba  neg     r9b
0x14000cdbd  lea     rcx, [rbp+710h+Source]
0x14000cdc4  sbb     r14d, r14d
0x14000cdc7  xor     edx, edx
0x14000cdc9  neg     r14d
0x14000cdcc  add     r14d, esi
0x14000cdcf  sub     esi, ebx
0x14000cdd1  mov     edi, esi
0x14000cdd3  mov     [rbp+710h+var_790], r14d
0x14000cdd7  shr     edi, 5
0x14000cdda  mov     ebx, edi
0x14000cddc  shl     rbx, 2
0x14000cde0  mov     r8, rbx
0x14000cde3  call    sub_140002F60
0x14000cde8  and     esi, 1Fh
0x14000cdeb  lea     r15d, [rdi+1]
0x14000cdef  mov     cl, sil
0x14000cdf2  mov     r8d, r15d
0x14000cdf5  mov     eax, 1
0x14000cdfa  shl     r8, 2
0x14000cdfe  shl     eax, cl
0x14000ce00  mov     [rbp+rbx+710h+Source], eax
0x14000ce07  xor     r13d, r13d
0x14000ce0a  mov     [rbp+710h+var_5C0], r15d
0x14000ce11  mov     [rbp+710h+var_3F0], r15d
0x14000ce18  test    r8, r8
0x14000ce1b  jz      loc_14000CF5E
0x14000ce21  mov     ebx, 1CCh
0x14000ce26  lea     rcx, [rbp+710h+var_5BC]
0x14000ce2d  cmp     r8, rbx
0x14000ce30  ja      loc_14000CF3D
0x14000ce36  lea     rdx, [rbp+710h+Source]
0x14000ce3d  call    sub_1400036D0
0x14000ce42  jmp     loc_14000CF57
0x14000ce47  lea     eax, [rdx-1]
0x14000ce4a  mov     dword ptr [rsp+810h+X], r13d
0x14000ce4f  mov     ecx, eax
0x14000ce51  bsr     eax, [rbp+rax*4+710h+Destination]
0x14000ce56  jz      short loc_14000CE5C
0x14000ce58  inc     eax
0x14000ce5a  jmp     short loc_14000CE5F
0x14000ce5c  mov     eax, r13d
0x14000ce5f  sub     edi, eax
0x14000ce61  cmp     edi, r10d
0x14000ce64  setb    r9b
0x14000ce68  cmp     edx, 73h ; 's'
0x14000ce6b  setnbe  cl
0x14000ce6e  cmp     edx, 73h ; 's'
0x14000ce71  jnz     short loc_14000CE7B
0x14000ce73  mov     al, r10b
0x14000ce76  test    r9b, r9b
0x14000ce79  jnz     short loc_14000CE7E
0x14000ce7b  mov     al, r13b
0x14000ce7e  or      r13d, 0FFFFFFFFh
0x14000ce82  test    cl, cl
0x14000ce84  jnz     short loc_14000CEEE
0x14000ce86  test    al, al
0x14000ce88  jnz     short loc_14000CEEE
0x14000ce8a  mov     r14d, 72h ; 'r'
0x14000ce90  cmp     edx, r14d
0x14000ce93  cmovb   r14d, edx
0x14000ce97  cmp     r14d, r13d
0x14000ce9a  jz      short loc_14000CEDA
0x14000ce9c  mov     ecx, r14d
0x14000ce9f  cmp     ecx, edx
0x14000cea1  jnb     short loc_14000CEAC
0x14000cea3  mov     eax, ecx
0x14000cea5  mov     r8d, [rbp+rax*4+710h+Destination]
0x14000ceaa  jmp     short loc_14000CEAF
0x14000ceac  xor     r8d, r8d
0x14000ceaf  lea     eax, [rcx-1]
0x14000ceb2  cmp     eax, edx
0x14000ceb4  jnb     short loc_14000CEBC
0x14000ceb6  mov     edx, [rbp+rax*4+710h+Destination]
0x14000ceba  jmp     short loc_14000CEBE
0x14000cebc  xor     edx, edx
0x14000cebe  shr     edx, 1Fh
0x14000cec1  lea     eax, [r8+r8]
0x14000cec5  xor     edx, eax
0x14000cec7  mov     eax, ecx
0x14000cec9  add     ecx, r13d
0x14000cecc  mov     [rbp+rax*4+710h+Destination], edx
0x14000ced0  cmp     ecx, r13d
0x14000ced3  jz      short loc_14000CEDA
0x14000ced5  mov     edx, [rbp+710h+var_790]
0x14000ced8  jmp     short loc_14000CE9F
0x14000ceda  xor     r13d, r13d
0x14000cedd  lea     eax, [r14+1]
0x14000cee1  test    r9b, r9b
0x14000cee4  cmovnz  r14d, eax
0x14000cee8  mov     [rbp+710h+var_790], r14d
0x14000ceec  jmp     short loc_14000CEF8
0x14000ceee  xor     r13d, r13d
0x14000cef1  mov     r14d, r13d
0x14000cef4  mov     [rbp+710h+var_790], r13d
0x14000cef8  mov     edi, r10d
0x14000cefb  lea     rcx, [rbp+710h+Source]
0x14000cf02  sub     edi, ebx
0x14000cf04  xor     edx, edx
0x14000cf06  mov     esi, edi
0x14000cf08  shr     esi, 5
0x14000cf0b  mov     ebx, esi
0x14000cf0d  shl     rbx, 2
0x14000cf11  mov     r8, rbx
0x14000cf14  call    sub_140002F60
0x14000cf19  and     edi, 1Fh
0x14000cf1c  lea     r15d, [rsi+1]
0x14000cf20  mov     cl, dil
0x14000cf23  mov     r8d, r15d
0x14000cf26  mov     eax, 1
0x14000cf2b  shl     eax, cl
0x14000cf2d  mov     [rbp+rbx+710h+Source], eax
0x14000cf34  shl     r8, 2
0x14000cf38  jmp     loc_14000CE0A
0x14000cf3d  mov     r8, rbx
0x14000cf40  xor     edx, edx
0x14000cf42  call    sub_140002F60
0x14000cf47  call    _errno
0x14000cf4c  mov     dword ptr [rax], 22h ; '"'
0x14000cf52  call    _invalid_parameter_noinfo
0x14000cf57  mov     r15d, [rbp+710h+var_5C0]
0x14000cf5e  mov     eax, 0CCCCCCCDh
0x14000cf63  test    r12d, r12d
0x14000cf66  js      loc_14000D42A
0x14000cf6c  mul     r12d
0x14000cf6f  mov     eax, edx
0x14000cf71  lea     rdx, cs:140000000h
0x14000cf78  shr     eax, 3
0x14000cf7b  mov     [rsp+810h+var_7C8], eax
0x14000cf7f  mov     r12d, eax
0x14000cf82  mov     [rsp+810h+var_7D0], eax
0x14000cf86  test    eax, eax
0x14000cf88  jz      loc_14000D361
0x14000cf8e  mov     eax, 26h ; '&'
0x14000cf93  mov     r13d, r12d
0x14000cf96  cmp     r12d, eax
0x14000cf99  cmova   r13d, eax
0x14000cf9d  mov     [rsp+810h+var_7CC], r13d
0x14000cfa2  lea     eax, [r13-1]
0x14000cfa6  movzx   ecx, ds:rva byte_140014212[rdx+rax*4]
0x14000cfae  movzx   esi, ds:rva byte_140014213[rdx+rax*4]
0x14000cfb6  mov     ebx, ecx
0x14000cfb8  mov     edi, eax
0x14000cfba  xor     edx, edx
0x14000cfbc  shl     rbx, 2
0x14000cfc0  mov     r8, rbx
0x14000cfc3  lea     eax, [rsi+rcx]
0x14000cfc6  lea     rcx, [rbp+710h+Source]
0x14000cfcd  mov     [rbp+710h+var_3F0], eax
0x14000cfd3  call    sub_140002F60
0x14000cfd8  lea     rcx, cs:140000000h
0x14000cfdf  shl     rsi, 2
0x14000cfe3  movzx   eax, ds:rva word_140014210[rcx+rdi*4]
0x14000cfeb  lea     rdx, rva unk_140013900[rcx]
0x14000cff2  lea     rcx, [rbp+710h+Source]
0x14000cff9  mov     r8, rsi
0x14000cffc  add     rcx, rbx
0x14000cfff  lea     rdx, [rdx+rax*4]
0x14000d003  call    sub_1400036D0
0x14000d008  mov     r11d, [rbp+710h+var_3F0]
0x14000d00f  cmp     r11d, 1
0x14000d013  ja      loc_14000D0BB
0x14000d019  mov     eax, [rbp+710h+Source]
0x14000d01f  test    eax, eax
0x14000d021  jnz     short loc_14000D032
0x14000d023  xor     r15d, r15d
0x14000d026  mov     [rbp+710h+var_5C0], r15d
0x14000d02d  jmp     loc_14000D33B
0x14000d032  cmp     eax, 1
0x14000d035  jz      loc_14000D33B
0x14000d03b  test    r15d, r15d
0x14000d03e  jz      loc_14000D33B
0x14000d044  xor     r8d, r8d
0x14000d047  mov     r10, rax
0x14000d04a  xor     r9d, r9d
0x14000d04d  mov     ecx, dword ptr [rbp+r9*4+710h+var_5BC]
0x14000d055  mov     eax, r8d
0x14000d058  imul    rcx, r10
0x14000d05c  add     rcx, rax
0x14000d05f  mov     r8, rcx
0x14000d062  mov     dword ptr [rbp+r9*4+710h+var_5BC], ecx
0x14000d06a  shr     r8, 20h
0x14000d06e  inc     r9d
0x14000d071  cmp     r9d, r15d
0x14000d074  jnz     short loc_14000D04D
0x14000d076  test    r8d, r8d
0x14000d079  jz      short loc_14000D0AF
0x14000d07b  cmp     [rbp+710h+var_5C0], 73h ; 's'
0x14000d082  jnb     short loc_14000D09E
0x14000d084  mov     eax, [rbp+710h+var_5C0]
0x14000d08a  mov     dword ptr [rbp+rax*4+710h+var_5BC], r8d
0x14000d092  mov     r15d, [rbp+710h+var_5C0]
0x14000d099  inc     r15d
0x14000d09c  jmp     short loc_14000D026
0x14000d09e  xor     r15d, r15d
0x14000d0a1  mov     [rbp+710h+var_5C0], r15d
0x14000d0a8  xor     al, al
0x14000d0aa  jmp     loc_14000D33D
0x14000d0af  mov     r15d, [rbp+710h+var_5C0]
0x14000d0b6  jmp     loc_14000D33B
0x14000d0bb  cmp     r15d, 1
0x14000d0bf  ja      loc_14000D172
0x14000d0c5  mov     ebx, dword ptr [rbp+710h+var_5BC]
0x14000d0cb  mov     r8, r11
0x14000d0ce  shl     r8, 2
0x14000d0d2  mov     r15d, r11d
0x14000d0d5  mov     [rbp+710h+var_5C0], r11d
0x14000d0dc  test    r8, r8
0x14000d0df  jz      short loc_14000D121
0x14000d0e1  mov     eax, 1CCh
0x14000d0e6  lea     rcx, [rbp+710h+var_5BC]
0x14000d0ed  cmp     r8, rax
0x14000d0f0  ja      short loc_14000D100
0x14000d0f2  lea     rdx, [rbp+710h+Source]
0x14000d0f9  call    sub_1400036D0
0x14000d0fe  jmp     short loc_14000D11A
0x14000d100  mov     r8, rax
0x14000d103  xor     edx, edx
0x14000d105  call    sub_140002F60
0x14000d10a  call    _errno
0x14000d10f  mov     dword ptr [rax], 22h ; '"'
0x14000d115  call    _invalid_parameter_noinfo
0x14000d11a  mov     r15d, [rbp+710h+var_5C0]
0x14000d121  test    ebx, ebx
0x14000d123  jz      loc_14000D023
0x14000d129  cmp     ebx, 1
0x14000d12c  jz      loc_14000D33B
0x14000d132  test    r15d, r15d
0x14000d135  jz      loc_14000D33B
0x14000d13b  xor     r8d, r8d
0x14000d13e  mov     r10, rbx
0x14000d141  xor     r9d, r9d
0x14000d144  mov     ecx, dword ptr [rbp+r9*4+710h+var_5BC]
0x14000d14c  mov     eax, r8d
0x14000d14f  imul    rcx, r10
0x14000d153  add     rcx, rax
0x14000d156  mov     r8, rcx
0x14000d159  mov     dword ptr [rbp+r9*4+710h+var_5BC], ecx
0x14000d161  shr     r8, 20h
0x14000d165  inc     r9d
0x14000d168  cmp     r9d, r15d
0x14000d16b  jnz     short loc_14000D144
0x14000d16d  jmp     loc_14000D076
0x14000d172  cmp     r11d, r15d
0x14000d175  lea     rcx, [rbp+710h+var_5BC]
0x14000d17c  mov     r12d, r15d
0x14000d17f  lea     r13, [rbp+710h+Source]
0x14000d186  setb    al
0x14000d189  lea     rdx, [rbp+710h+var_5BC]
0x14000d190  test    al, al
0x14000d192  cmovz   r13, rcx
0x14000d196  cmovnz  r12d, r11d
0x14000d19a  cmovnz  r11d, r15d
0x14000d19e  lea     rcx, [rbp+710h+Source]
0x14000d1a5  cmovz   rdx, rcx
0x14000d1a9  xor     r15d, r15d
0x14000d1ac  xor     r10d, r10d
0x14000d1af  mov     [rsp+810h+X], rdx
0x14000d1b4  mov     [rbp+710h+var_220], r15d
0x14000d1bb  test    r12d, r12d
0x14000d1be  jz      loc_14000D2DE
0x14000d1c4  mov     esi, [r13+r10*4+0]
0x14000d1c9  mov     eax, r10d
0x14000d1cc  test    esi, esi
0x14000d1ce  jnz     short loc_14000D1F1
0x14000d1d0  cmp     r10d, r15d
0x14000d1d3  jnz     loc_14000D2D2
0x14000d1d9  and     dword ptr [rbp+r10*4+710h+var_21C], esi
0x14000d1e1  lea     r15d, [r10+1]
0x14000d1e5  mov     [rbp+710h+var_220], r15d
0x14000d1ec  jmp     loc_14000D2D2
0x14000d1f1  xor     ebx, ebx
0x14000d1f3  mov     r9d, r10d
0x14000d1f6  test    r11d, r11d
0x14000d1f9  jz      loc_14000D2C3
0x14000d1ff  mov     edi, r10d
0x14000d202  neg     edi
0x14000d204  cmp     r9d, 73h ; 's'
0x14000d208  jz      short loc_14000D271
0x14000d20a  cmp     r9d, r15d
0x14000d20d  jnz     short loc_14000D22A
0x14000d20f  mov     eax, r9d
0x14000d212  lea     ecx, [r10+1]
0x14000d216  and     dword ptr [rbp+rax*4+710h+var_21C], 0
0x14000d21e  lea     eax, [rdi+r9]
0x14000d222  add     ecx, eax
0x14000d224  mov     [rbp+710h+var_220], ecx
0x14000d22a  lea     eax, [rdi+r9]
0x14000d22e  mov     r8d, r9d
0x14000d231  mov     edx, [rdx+rax*4]
0x14000d234  inc     r9d
0x14000d237  mov     eax, ebx
0x14000d239  imul    rdx, rsi
0x14000d23d  add     rdx, rax
0x14000d240  mov     eax, dword ptr [rbp+r8*4+710h+var_21C]
0x14000d248  add     rdx, rax
0x14000d24b  lea     eax, [rdi+r9]
0x14000d24f  mov     rbx, rdx
0x14000d252  mov     dword ptr [rbp+r8*4+710h+var_21C], edx
0x14000d25a  mov     r15d, [rbp+710h+var_220]
0x14000d261  shr     rbx, 20h
0x14000d265  cmp     eax, r11d
0x14000d268  jz      short loc_14000D271
0x14000d26a  mov     rdx, [rsp+810h+X]
0x14000d26f  jmp     short loc_14000D204
0x14000d271  test    ebx, ebx
0x14000d273  jz      short loc_14000D2C3
0x14000d275  cmp     r9d, 73h ; 's'
0x14000d279  jz      loc_14000D3FD
0x14000d27f  cmp     r9d, r15d
0x14000d282  jnz     short loc_14000D299
0x14000d284  mov     eax, r9d
0x14000d287  and     dword ptr [rbp+rax*4+710h+var_21C], 0
0x14000d28f  lea     eax, [r9+1]
0x14000d293  mov     [rbp+710h+var_220], eax
0x14000d299  mov     ecx, r9d
0x14000d29c  inc     r9d
0x14000d29f  mov     edx, ebx
0x14000d2a1  mov     eax, dword ptr [rbp+rcx*4+710h+var_21C]
0x14000d2a8  add     rdx, rax
0x14000d2ab  mov     dword ptr [rbp+rcx*4+710h+var_21C], edx
0x14000d2b2  mov     r15d, [rbp+710h+var_220]
0x14000d2b9  shr     rdx, 20h
0x14000d2bd  mov     ebx, edx
0x14000d2bf  test    edx, edx
0x14000d2c1  jnz     short loc_14000D275
0x14000d2c3  cmp     r9d, 73h ; 's'
0x14000d2c7  jz      loc_14000D3FD
0x14000d2cd  mov     rdx, [rsp+810h+X]
0x14000d2d2  inc     r10d
0x14000d2d5  cmp     r10d, r12d
0x14000d2d8  jnz     loc_14000D1C4
0x14000d2de  mov     r8d, r15d
0x14000d2e1  shl     r8, 2
0x14000d2e5  mov     [rbp+710h+var_5C0], r15d
0x14000d2ec  test    r8, r8
0x14000d2ef  jz      short loc_14000D331
0x14000d2f1  mov     eax, 1CCh
0x14000d2f6  lea     rcx, [rbp+710h+var_5BC]
0x14000d2fd  cmp     r8, rax
0x14000d300  ja      short loc_14000D310
0x14000d302  lea     rdx, [rbp+710h+var_21C]
0x14000d309  call    sub_1400036D0
0x14000d30e  jmp     short loc_14000D32A
0x14000d310  mov     r8, rax
0x14000d313  xor     edx, edx
0x14000d315  call    sub_140002F60
0x14000d31a  call    _errno
0x14000d31f  mov     dword ptr [rax], 22h ; '"'
0x14000d325  call    _invalid_parameter_noinfo
0x14000d32a  mov     r15d, [rbp+710h+var_5C0]
0x14000d331  mov     r12d, [rsp+810h+var_7D0]
0x14000d336  mov     r13d, [rsp+810h+var_7CC]
0x14000d33b  mov     al, 1
0x14000d33d  test    al, al
0x14000d33f  jz      loc_14000D3FD
0x14000d345  sub     r12d, r13d
0x14000d348  lea     rdx, cs:140000000h
0x14000d34f  mov     [rsp+810h+var_7D0], r12d
0x14000d354  jnz     loc_14000CF8E
0x14000d35a  mov     eax, [rsp+810h+var_7C8]
0x14000d35e  xor     r13d, r13d
0x14000d361  mov     edi, [rsp+810h+var_7E0]
0x14000d365  lea     eax, [rax+rax*4]
0x14000d368  add     eax, eax
0x14000d36a  mov     ecx, edi
0x14000d36c  sub     ecx, eax
0x14000d36e  jz      loc_14000D893
0x14000d374  lea     eax, [rcx-1]
0x14000d377  mov     eax, ds:rva dword_1400142A8[rdx+rax*4]
0x14000d37e  test    eax, eax
0x14000d380  jz      loc_14000D40F
0x14000d386  cmp     eax, 1
0x14000d389  jz      loc_14000D893
0x14000d38f  test    r15d, r15d
0x14000d392  jz      loc_14000D893
0x14000d398  mov     r8d, r13d
0x14000d39b  mov     r9d, r13d
0x14000d39e  mov     r10d, eax
0x14000d3a1  mov     edx, r9d
0x14000d3a4  inc     r9d
0x14000d3a7  mov     eax, r8d
0x14000d3aa  mov     ecx, dword ptr [rbp+rdx*4+710h+var_5BC]
0x14000d3b1  imul    rcx, r10
0x14000d3b5  add     rcx, rax
0x14000d3b8  mov     r8, rcx
0x14000d3bb  mov     dword ptr [rbp+rdx*4+710h+var_5BC], ecx
0x14000d3c2  shr     r8, 20h
0x14000d3c6  cmp     r9d, r15d
0x14000d3c9  jnz     short loc_14000D3A1
0x14000d3cb  test    r8d, r8d
0x14000d3ce  jz      short loc_14000D41E
0x14000d3d0  cmp     [rbp+710h+var_5C0], 73h ; 's'
0x14000d3d7  jnb     short loc_14000D40F
0x14000d3d9  mov     eax, [rbp+710h+var_5C0]
0x14000d3df  mov     dword ptr [rbp+rax*4+710h+var_5BC], r8d
0x14000d3e7  mov     r15d, [rbp+710h+var_5C0]
0x14000d3ee  inc     r15d
0x14000d3f1  mov     [rbp+710h+var_5C0], r15d
0x14000d3f8  jmp     loc_14000D893
0x14000d3fd  xor     r13d, r13d
0x14000d400  mov     r15d, r13d
0x14000d403  mov     [rbp+710h+var_5C0], r13d
0x14000d40a  jmp     loc_14000D88F
0x14000d40f  mov     r15d, r13d
0x14000d412  mov     [rbp+710h+var_5C0], r13d
0x14000d419  jmp     loc_14000D893
0x14000d41e  mov     r15d, [rbp+710h+var_5C0]
0x14000d425  jmp     loc_14000D893
0x14000d42a  mov     ecx, r12d
0x14000d42d  neg     ecx
0x14000d42f  mul     ecx
0x14000d431  mov     [rsp+810h+var_7CC], ecx
0x14000d435  mov     eax, edx
0x14000d437  lea     rdx, cs:140000000h
0x14000d43e  shr     eax, 3
0x14000d441  mov     dword ptr [rsp+810h+X], eax
0x14000d445  mov     r12d, eax
0x14000d448  mov     [rsp+810h+var_7D0], eax
0x14000d44c  test    eax, eax
0x14000d44e  jz      loc_14000D7EB
0x14000d454  mov     eax, 26h ; '&'
0x14000d459  mov     r13d, r12d
0x14000d45c  cmp     r12d, eax
0x14000d45f  cmova   r13d, eax
0x14000d463  mov     [rsp+810h+var_7C8], r13d
0x14000d468  lea     eax, [r13-1]
0x14000d46c  movzx   ecx, ds:rva byte_140014212[rdx+rax*4]
0x14000d474  movzx   esi, ds:rva byte_140014213[rdx+rax*4]
0x14000d47c  mov     ebx, ecx
0x14000d47e  mov     edi, eax
0x14000d480  xor     edx, edx
0x14000d482  shl     rbx, 2
0x14000d486  mov     r8, rbx
0x14000d489  lea     eax, [rsi+rcx]
0x14000d48c  lea     rcx, [rbp+710h+Source]
0x14000d493  mov     [rbp+710h+var_3F0], eax
0x14000d499  call    sub_140002F60
0x14000d49e  lea     rcx, cs:140000000h
0x14000d4a5  shl     rsi, 2
0x14000d4a9  movzx   eax, ds:rva word_140014210[rcx+rdi*4]
0x14000d4b1  lea     rdx, rva unk_140013900[rcx]
0x14000d4b8  lea     rcx, [rbp+710h+Source]
0x14000d4bf  mov     r8, rsi
0x14000d4c2  add     rcx, rbx
0x14000d4c5  lea     rdx, [rdx+rax*4]
0x14000d4c9  call    sub_1400036D0
0x14000d4ce  mov     edi, [rbp+710h+var_3F0]
0x14000d4d4  cmp     edi, 1
0x14000d4d7  ja      loc_14000D564
0x14000d4dd  mov     eax, [rbp+710h+Source]
0x14000d4e3  test    eax, eax
0x14000d4e5  jnz     short loc_14000D4F3
0x14000d4e7  xor     r14d, r14d
0x14000d4ea  mov     [rbp+710h+var_790], r14d
0x14000d4ee  jmp     loc_14000D7C1
0x14000d4f3  cmp     eax, 1
0x14000d4f6  jz      loc_14000D7C1
0x14000d4fc  test    r14d, r14d
0x14000d4ff  jz      loc_14000D7C1
0x14000d505  xor     r8d, r8d
0x14000d508  mov     r10, rax
0x14000d50b  xor     r9d, r9d
0x14000d50e  mov     ecx, [rbp+r9*4+710h+Destination]
0x14000d513  mov     eax, r8d
0x14000d516  imul    rcx, r10
0x14000d51a  add     rcx, rax
0x14000d51d  mov     r8, rcx
0x14000d520  mov     [rbp+r9*4+710h+Destination], ecx
0x14000d525  shr     r8, 20h
0x14000d529  inc     r9d
0x14000d52c  cmp     r9d, r14d
0x14000d52f  jnz     short loc_14000D50E
0x14000d531  test    r8d, r8d
0x14000d534  jz      short loc_14000D55B
0x14000d536  cmp     [rbp+710h+var_790], 73h ; 's'
0x14000d53a  jnb     short loc_14000D54D
0x14000d53c  mov     eax, [rbp+710h+var_790]
0x14000d53f  mov     [rbp+rax*4+710h+Destination], r8d
0x14000d544  mov     r14d, [rbp+710h+var_790]
0x14000d548  inc     r14d
0x14000d54b  jmp     short loc_14000D4EA
0x14000d54d  xor     r14d, r14d
0x14000d550  mov     [rbp+710h+var_790], r14d
0x14000d554  xor     al, al
0x14000d556  jmp     loc_14000D7C3
0x14000d55b  mov     r14d, [rbp+710h+var_790]
0x14000d55f  jmp     loc_14000D7C1
0x14000d564  cmp     r14d, 1
0x14000d568  ja      loc_14000D608
0x14000d56e  mov     ebx, [rbp+710h+Destination]
0x14000d571  mov     r8, rdi
0x14000d574  shl     r8, 2
0x14000d578  mov     r14d, edi
0x14000d57b  mov     [rbp+710h+var_790], edi
0x14000d57e  test    r8, r8
0x14000d581  jz      short loc_14000D5BD
0x14000d583  mov     eax, 1CCh
0x14000d588  lea     rcx, [rbp+710h+Destination]
0x14000d58c  cmp     r8, rax
0x14000d58f  ja      short loc_14000D59F
0x14000d591  lea     rdx, [rbp+710h+Source]
0x14000d598  call    sub_1400036D0
0x14000d59d  jmp     short loc_14000D5B9
0x14000d59f  mov     r8, rax
0x14000d5a2  xor     edx, edx
0x14000d5a4  call    sub_140002F60
0x14000d5a9  call    _errno
0x14000d5ae  mov     dword ptr [rax], 22h ; '"'
0x14000d5b4  call    _invalid_parameter_noinfo
0x14000d5b9  mov     r14d, [rbp+710h+var_790]
0x14000d5bd  test    ebx, ebx
0x14000d5bf  jz      loc_14000D4E7
0x14000d5c5  cmp     ebx, 1
0x14000d5c8  jz      loc_14000D7C1
0x14000d5ce  test    r14d, r14d
0x14000d5d1  jz      loc_14000D7C1
0x14000d5d7  xor     r8d, r8d
0x14000d5da  mov     r10, rbx
0x14000d5dd  xor     r9d, r9d
0x14000d5e0  mov     ecx, [rbp+r9*4+710h+Destination]
0x14000d5e5  mov     eax, r8d
0x14000d5e8  imul    rcx, r10
0x14000d5ec  add     rcx, rax
0x14000d5ef  mov     r8, rcx
0x14000d5f2  mov     [rbp+r9*4+710h+Destination], ecx
0x14000d5f7  shr     r8, 20h
0x14000d5fb  inc     r9d
0x14000d5fe  cmp     r9d, r14d
0x14000d601  jnz     short loc_14000D5E0
0x14000d603  jmp     loc_14000D531
0x14000d608  cmp     edi, r14d
0x14000d60b  lea     rcx, [rbp+710h+Destination]
0x14000d60f  mov     r12d, r14d
0x14000d612  lea     r13, [rbp+710h+Source]
0x14000d619  setb    al
0x14000d61c  lea     rdx, [rbp+710h+Destination]
0x14000d620  test    al, al
0x14000d622  cmovz   r13, rcx
0x14000d626  cmovnz  r12d, edi
0x14000d62a  cmovnz  edi, r14d
0x14000d62e  lea     rcx, [rbp+710h+Source]
0x14000d635  cmovz   rdx, rcx
0x14000d639  xor     r14d, r14d
0x14000d63c  xor     r10d, r10d
0x14000d63f  mov     [rsp+810h+var_7B8], rdx
0x14000d644  mov     [rbp+710h+var_220], r14d
0x14000d64b  test    r12d, r12d
0x14000d64e  jz      loc_14000D76D
0x14000d654  mov     esi, [r13+r10*4+0]
0x14000d659  mov     eax, r10d
0x14000d65c  test    esi, esi
0x14000d65e  jnz     short loc_14000D681
0x14000d660  cmp     r10d, r14d
0x14000d663  jnz     loc_14000D761
0x14000d669  and     dword ptr [rbp+r10*4+710h+var_21C], esi
0x14000d671  lea     r14d, [r10+1]
0x14000d675  mov     [rbp+710h+var_220], r14d
0x14000d67c  jmp     loc_14000D761
0x14000d681  xor     ebx, ebx
0x14000d683  mov     r9d, r10d
0x14000d686  test    edi, edi
0x14000d688  jz      loc_14000D752
0x14000d68e  mov     r11d, r10d
0x14000d691  neg     r11d
0x14000d694  cmp     r9d, 73h ; 's'
0x14000d698  jz      short loc_14000D700
0x14000d69a  cmp     r9d, r14d
0x14000d69d  jnz     short loc_14000D6BA
0x14000d69f  mov     eax, r9d
0x14000d6a2  lea     ecx, [r9+1]
0x14000d6a6  and     dword ptr [rbp+rax*4+710h+var_21C], 0
0x14000d6ae  lea     eax, [r10+r11]
0x14000d6b2  add     ecx, eax
0x14000d6b4  mov     [rbp+710h+var_220], ecx
0x14000d6ba  lea     eax, [r11+r9]
0x14000d6be  mov     r8d, r9d
0x14000d6c1  mov     edx, [rdx+rax*4]
0x14000d6c4  inc     r9d
0x14000d6c7  imul    rdx, rsi
0x14000d6cb  mov     eax, dword ptr [rbp+r8*4+710h+var_21C]
0x14000d6d3  add     rdx, rax
0x14000d6d6  mov     eax, ebx
0x14000d6d8  add     rdx, rax
0x14000d6db  lea     eax, [r11+r9]
0x14000d6df  mov     rbx, rdx
0x14000d6e2  mov     dword ptr [rbp+r8*4+710h+var_21C], edx
0x14000d6ea  mov     r14d, [rbp+710h+var_220]
0x14000d6f1  shr     rbx, 20h
0x14000d6f5  cmp     eax, edi
0x14000d6f7  jz      short loc_14000D700
0x14000d6f9  mov     rdx, [rsp+810h+var_7B8]
0x14000d6fe  jmp     short loc_14000D694
0x14000d700  test    ebx, ebx
0x14000d702  jz      short loc_14000D752
0x14000d704  cmp     r9d, 73h ; 's'
0x14000d708  jz      loc_14000D865
0x14000d70e  cmp     r9d, r14d
0x14000d711  jnz     short loc_14000D728
0x14000d713  mov     eax, r9d
0x14000d716  and     dword ptr [rbp+rax*4+710h+var_21C], 0
0x14000d71e  lea     eax, [r9+1]
0x14000d722  mov     [rbp+710h+var_220], eax
0x14000d728  mov     ecx, r9d
0x14000d72b  inc     r9d
0x14000d72e  mov     eax, ebx
0x14000d730  mov     edx, dword ptr [rbp+rcx*4+710h+var_21C]
0x14000d737  add     rdx, rax
0x14000d73a  mov     dword ptr [rbp+rcx*4+710h+var_21C], edx
0x14000d741  mov     r14d, [rbp+710h+var_220]
0x14000d748  shr     rdx, 20h
0x14000d74c  mov     ebx, edx
0x14000d74e  test    edx, edx
0x14000d750  jnz     short loc_14000D704
0x14000d752  cmp     r9d, 73h ; 's'
0x14000d756  jz      loc_14000D865
0x14000d75c  mov     rdx, [rsp+810h+var_7B8]
0x14000d761  inc     r10d
0x14000d764  cmp     r10d, r12d
0x14000d767  jnz     loc_14000D654
0x14000d76d  mov     r8d, r14d
0x14000d770  shl     r8, 2
0x14000d774  mov     [rbp+710h+var_790], r14d
0x14000d778  test    r8, r8
0x14000d77b  jz      short loc_14000D7B7
0x14000d77d  mov     eax, 1CCh
0x14000d782  lea     rcx, [rbp+710h+Destination]
0x14000d786  cmp     r8, rax
0x14000d789  ja      short loc_14000D799
0x14000d78b  lea     rdx, [rbp+710h+var_21C]
0x14000d792  call    sub_1400036D0
0x14000d797  jmp     short loc_14000D7B3
0x14000d799  mov     r8, rax
0x14000d79c  xor     edx, edx
0x14000d79e  call    sub_140002F60
0x14000d7a3  call    _errno
0x14000d7a8  mov     dword ptr [rax], 22h ; '"'
0x14000d7ae  call    _invalid_parameter_noinfo
0x14000d7b3  mov     r14d, [rbp+710h+var_790]
0x14000d7b7  mov     r12d, [rsp+810h+var_7D0]
0x14000d7bc  mov     r13d, [rsp+810h+var_7C8]
0x14000d7c1  mov     al, 1
0x14000d7c3  test    al, al
0x14000d7c5  jz      loc_14000D865
0x14000d7cb  sub     r12d, r13d
0x14000d7ce  lea     rdx, cs:140000000h
0x14000d7d5  mov     [rsp+810h+var_7D0], r12d
0x14000d7da  jnz     loc_14000D454
0x14000d7e0  mov     ecx, [rsp+810h+var_7CC]
0x14000d7e4  xor     r13d, r13d
0x14000d7e7  mov     eax, dword ptr [rsp+810h+X]
0x14000d7eb  lea     eax, [rax+rax*4]
0x14000d7ee  add     eax, eax
0x14000d7f0  sub     ecx, eax
0x14000d7f2  jz      loc_14000D88F
0x14000d7f8  lea     eax, [rcx-1]
0x14000d7fb  mov     eax, ds:rva dword_1400142A8[rdx+rax*4]
0x14000d802  test    eax, eax
0x14000d804  jz      short loc_14000D868
0x14000d806  cmp     eax, 1
0x14000d809  jz      loc_14000D88F
0x14000d80f  test    r14d, r14d
0x14000d812  jz      short loc_14000D88F
0x14000d814  mov     r8d, r13d
0x14000d817  mov     r9d, r13d
0x14000d81a  mov     r10d, eax
0x14000d81d  mov     edx, r9d
0x14000d820  inc     r9d
0x14000d823  mov     eax, r8d
0x14000d826  mov     ecx, [rbp+rdx*4+710h+Destination]
0x14000d82a  imul    rcx, r10
0x14000d82e  add     rcx, rax
0x14000d831  mov     r8, rcx
0x14000d834  mov     [rbp+rdx*4+710h+Destination], ecx
0x14000d838  shr     r8, 20h
0x14000d83c  cmp     r9d, r14d
0x14000d83f  jnz     short loc_14000D81D
0x14000d841  test    r8d, r8d
0x14000d844  jz      short loc_14000D88B
0x14000d846  cmp     [rbp+710h+var_790], 73h ; 's'
0x14000d84a  mov     edi, [rsp+810h+var_7E0]
0x14000d84e  jnb     short loc_14000D87D
0x14000d850  mov     eax, [rbp+710h+var_790]
0x14000d853  mov     [rbp+rax*4+710h+Destination], r8d
0x14000d858  mov     r14d, [rbp+710h+var_790]
0x14000d85c  inc     r14d
0x14000d85f  mov     [rbp+710h+var_790], r14d
0x14000d863  jmp     short loc_14000D893
0x14000d865  xor     r13d, r13d
0x14000d868  mov     rsi, [rsp+810h+var_7C0]
0x14000d86d  mov     edi, [rsp+810h+var_7E0]
0x14000d871  mov     rbx, rsi
0x14000d874  mov     [rbp+710h+var_790], r13d
0x14000d878  jmp     loc_14000D904
0x14000d87d  mov     rsi, [rsp+810h+var_7C0]
0x14000d882  mov     rbx, rsi
0x14000d885  mov     [rbp+710h+var_790], r13d
0x14000d889  jmp     short loc_14000D904
0x14000d88b  mov     r14d, [rbp+710h+var_790]
0x14000d88f  mov     edi, [rsp+810h+var_7E0]
0x14000d893  mov     rsi, [rsp+810h+var_7C0]
0x14000d898  mov     rbx, rsi
0x14000d89b  test    r14d, r14d
0x14000d89e  jz      short loc_14000D904
0x14000d8a0  mov     r8d, r13d
0x14000d8a3  mov     r9d, r13d
0x14000d8a6  mov     edx, r9d
0x14000d8a9  inc     r9d
0x14000d8ac  mov     eax, [rbp+rdx*4+710h+Destination]
0x14000d8b0  lea     rcx, [rax+rax*4]
0x14000d8b4  mov     eax, r8d
0x14000d8b7  lea     r8, [rax+rcx*2]
0x14000d8bb  mov     [rbp+rdx*4+710h+Destination], r8d
0x14000d8c0  shr     r8, 20h
0x14000d8c4  cmp     r9d, r14d
0x14000d8c7  jnz     short loc_14000D8A6
0x14000d8c9  test    r8d, r8d
0x14000d8cc  jz      short loc_14000D904
0x14000d8ce  cmp     [rbp+710h+var_790], 73h ; 's'
0x14000d8d2  jnb     short loc_14000D8E1
0x14000d8d4  mov     eax, [rbp+710h+var_790]
0x14000d8d7  mov     [rbp+rax*4+710h+Destination], r8d
0x14000d8dc  inc     [rbp+710h+var_790]
0x14000d8df  jmp     short loc_14000D904
0x14000d8e1  xor     r9d, r9d; SourceSize
0x14000d8e4  mov     [rbp+710h+var_3F0], r13d
0x14000d8eb  lea     r8, [rbp+710h+Source]; Source
0x14000d8f2  mov     [rbp+710h+var_790], r13d
0x14000d8f6  mov     edx, 1CCh; DestinationSize
0x14000d8fb  lea     rcx, [rbp+710h+Destination]; Destination
0x14000d8ff  call    memcpy_s
0x14000d904  lea     rdx, [rbp+710h+var_5C0]; struct __crt_strtox::big_integer *
0x14000d90b  lea     rcx, [rbp+710h+var_790]; this
0x14000d90f  call    ?divide@__crt_strtox@@YA_KAEAUbig_integer@1@AEBU21@@Z
0x14000d914  cmp     eax, 0Ah
0x14000d917  jnz     loc_14000D9AD
0x14000d91d  inc     edi
0x14000d91f  mov     byte ptr [rsi], 31h ; '1'
0x14000d922  lea     rbx, [rsi+1]
0x14000d926  test    r15d, r15d
0x14000d929  jz      loc_14000D9BD
0x14000d92f  mov     r8d, r13d
0x14000d932  mov     r9d, r13d
0x14000d935  mov     edx, r9d
0x14000d938  inc     r9d
0x14000d93b  mov     eax, dword ptr [rbp+rdx*4+710h+var_5BC]
0x14000d942  lea     rcx, [rax+rax*4]
0x14000d946  mov     eax, r8d
0x14000d949  lea     r8, [rax+rcx*2]
0x14000d94d  mov     dword ptr [rbp+rdx*4+710h+var_5BC], r8d
0x14000d955  shr     r8, 20h
0x14000d959  cmp     r9d, r15d
0x14000d95c  jnz     short loc_14000D935
0x14000d95e  test    r8d, r8d
0x14000d961  jz      short loc_14000D9BD
0x14000d963  cmp     [rbp+710h+var_5C0], 73h ; 's'
0x14000d96a  jnb     short loc_14000D982
0x14000d96c  mov     eax, [rbp+710h+var_5C0]
0x14000d972  mov     dword ptr [rbp+rax*4+710h+var_5BC], r8d
0x14000d97a  inc     [rbp+710h+var_5C0]
0x14000d980  jmp     short loc_14000D9BD
0x14000d982  xor     r9d, r9d; SourceSize
0x14000d985  mov     [rbp+710h+var_3F0], r13d
0x14000d98c  lea     r8, [rbp+710h+Source]; Source
0x14000d993  mov     [rbp+710h+var_5C0], r13d
0x14000d99a  mov     edx, 1CCh; DestinationSize
0x14000d99f  lea     rcx, [rbp+710h+var_5BC]; Destination
0x14000d9a6  call    memcpy_s
0x14000d9ab  jmp     short loc_14000D9BD
0x14000d9ad  test    eax, eax
0x14000d9af  jnz     short loc_14000D9B5
0x14000d9b1  dec     edi
0x14000d9b3  jmp     short loc_14000D9BD
0x14000d9b5  add     al, 30h ; '0'
0x14000d9b7  lea     rbx, [rsi+1]
0x14000d9bb  mov     [rsi], al
0x14000d9bd  mov     rax, [rsp+810h+var_7A0]
0x14000d9c2  mov     ecx, [rsp+810h+var_7C4]
0x14000d9c6  mov     [rax+4], edi
0x14000d9c9  test    edi, edi
0x14000d9cb  js      short loc_14000D9D7
0x14000d9cd  cmp     ecx, 7FFFFFFFh
0x14000d9d3  ja      short loc_14000D9D7
0x14000d9d5  add     ecx, edi
0x14000d9d7  mov     rax, [rbp+710h+SizeInBytes]
0x14000d9de  dec     rax
0x14000d9e1  mov     edi, ecx
0x14000d9e3  cmp     rax, rdi
0x14000d9e6  cmovb   rdi, rax
0x14000d9ea  add     rdi, rsi
0x14000d9ed  cmp     rbx, rdi
0x14000d9f0  jz      loc_14000DADE
0x14000d9f6  mov     r14d, 9
0x14000d9fc  or      esi, 0FFFFFFFFh
0x14000d9ff  mov     r10d, [rbp+710h+var_790]
0x14000da03  test    r10d, r10d
0x14000da06  jz      loc_14000DADE
0x14000da0c  mov     r8d, r13d
0x14000da0f  mov     r9d, r13d
0x14000da12  mov     edx, r9d
0x14000da15  inc     r9d
0x14000da18  mov     eax, [rbp+rdx*4+710h+Destination]
0x14000da1c  imul    rcx, rax, 3B9ACA00h
0x14000da23  mov     eax, r8d
0x14000da26  add     rcx, rax
0x14000da29  mov     r8, rcx
0x14000da2c  mov     [rbp+rdx*4+710h+Destination], ecx
0x14000da30  shr     r8, 20h
0x14000da34  cmp     r9d, r10d
0x14000da37  jnz     short loc_14000DA12
0x14000da39  test    r8d, r8d
0x14000da3c  jz      short loc_14000DA74
0x14000da3e  cmp     [rbp+710h+var_790], 73h ; 's'
0x14000da42  jnb     short loc_14000DA51
0x14000da44  mov     eax, [rbp+710h+var_790]
0x14000da47  mov     [rbp+rax*4+710h+Destination], r8d
0x14000da4c  inc     [rbp+710h+var_790]
0x14000da4f  jmp     short loc_14000DA74
0x14000da51  xor     r9d, r9d; SourceSize
0x14000da54  mov     [rbp+710h+var_3F0], r13d
0x14000da5b  lea     r8, [rbp+710h+Source]; Source
0x14000da62  mov     [rbp+710h+var_790], r13d
0x14000da66  mov     edx, 1CCh; DestinationSize
0x14000da6b  lea     rcx, [rbp+710h+Destination]; Destination
0x14000da6f  call    memcpy_s
0x14000da74  lea     rdx, [rbp+710h+var_5C0]; struct __crt_strtox::big_integer *
0x14000da7b  lea     rcx, [rbp+710h+var_790]; this
0x14000da7f  call    ?divide@__crt_strtox@@YA_KAEAUbig_integer@1@AEBU21@@Z
0x14000da84  mov     r10d, edi
0x14000da87  mov     r8, rax
0x14000da8a  sub     r10d, ebx
0x14000da8d  mov     r9d, 8
0x14000da93  mov     eax, 0CCCCCCCDh
0x14000da98  mul     r8d
0x14000da9b  shr     edx, 3
0x14000da9e  mov     cl, dl
0x14000daa0  shl     cl, 2
0x14000daa3  lea     eax, [rcx+rdx]
0x14000daa6  add     al, al
0x14000daa8  sub     r8b, al
0x14000daab  lea     ecx, [r8+30h]
0x14000daaf  mov     r8d, edx
0x14000dab2  cmp     r10d, r9d
0x14000dab5  jb      short loc_14000DABD
0x14000dab7  mov     eax, r9d
0x14000daba  mov     [rax+rbx], cl
0x14000dabd  add     r9d, esi
0x14000dac0  cmp     r9d, esi
0x14000dac3  jnz     short loc_14000DA93
0x14000dac5  mov     rax, rdi
0x14000dac8  sub     rax, rbx
0x14000dacb  cmp     rax, r14
0x14000dace  cmovg   rax, r14
0x14000dad2  add     rbx, rax
0x14000dad5  cmp     rbx, rdi
0x14000dad8  jnz     loc_14000D9FF
0x14000dade  mov     [rbx], r13b
0x14000dae1  jmp     short loc_14000DB5E
0x14000dae3  mov     rdx, [rbp+710h+SizeInBytes]; SizeInBytes
0x14000daea  lea     r8, a1Ind
0x14000daf1  mov     rcx, r14; Destination
0x14000daf4  call    strcpy_s
0x14000daf9  test    eax, eax
0x14000dafb  jz      short loc_14000DB5E
0x14000dafd  jmp     loc_14000DBA7
0x14000db02  mov     rdx, [rbp+710h+SizeInBytes]; SizeInBytes
0x14000db09  lea     r8, a1Snan
0x14000db10  mov     rcx, r14; Destination
0x14000db13  call    strcpy_s
0x14000db18  test    eax, eax
0x14000db1a  jz      short loc_14000DB5E
0x14000db1c  jmp     loc_14000DBBC
0x14000db21  mov     rdx, [rbp+710h+SizeInBytes]; SizeInBytes
0x14000db28  lea     r8, a1Qnan
0x14000db2f  mov     rcx, r14; Destination
0x14000db32  call    strcpy_s
0x14000db37  test    eax, eax
0x14000db39  jz      short loc_14000DB5E
0x14000db3b  jmp     loc_14000DBD1
0x14000db40  mov     rdx, [rbp+710h+SizeInBytes]; SizeInBytes
0x14000db47  lea     r8, a1Inf
0x14000db4e  mov     rcx, r14; Destination
0x14000db51  call    strcpy_s
0x14000db56  test    eax, eax
0x14000db58  jnz     loc_14000DBE6
0x14000db5e  cmp     [rsp+810h+var_7A8], r13b
0x14000db63  jz      short loc_14000DB6F
0x14000db65  lea     rcx, [rsp+810h+Env]; Env
0x14000db6a  call    fesetenv
0x14000db6f  mov     rcx, [rbp+710h+var_50]
0x14000db76  xor     rcx, rsp; StackCookie
0x14000db79  call    __security_check_cookie
0x14000db7e  add     rsp, 7D8h
0x14000db85  pop     r15
0x14000db87  pop     r14
0x14000db89  pop     r13
0x14000db8b  pop     r12
0x14000db8d  pop     rdi
0x14000db8e  pop     rsi
0x14000db8f  pop     rbx
0x14000db90  pop     rbp
0x14000db91  retn
0x14000db92  xor     r9d, r9d; LineNo
0x14000db95  mov     [rsp+810h+Reserved], r13; Reserved
0x14000db9a  xor     r8d, r8d; FileName
0x14000db9d  xor     edx, edx; FunctionName
0x14000db9f  xor     ecx, ecx; Expression
0x14000dba1  call    _invoke_watson
0x14000dba7  xor     r9d, r9d; LineNo
0x14000dbaa  mov     [rsp+810h+Reserved], r13; Reserved
0x14000dbaf  xor     r8d, r8d; FileName
0x14000dbb2  xor     edx, edx; FunctionName
0x14000dbb4  xor     ecx, ecx; Expression
0x14000dbb6  call    _invoke_watson
0x14000dbbc  xor     r9d, r9d; LineNo
0x14000dbbf  mov     [rsp+810h+Reserved], r13; Reserved
0x14000dbc4  xor     r8d, r8d; FileName
0x14000dbc7  xor     edx, edx; FunctionName
0x14000dbc9  xor     ecx, ecx; Expression
0x14000dbcb  call    _invoke_watson
0x14000dbd1  xor     r9d, r9d; LineNo
0x14000dbd4  mov     [rsp+810h+Reserved], r13; Reserved
0x14000dbd9  xor     r8d, r8d; FileName
0x14000dbdc  xor     edx, edx; FunctionName
0x14000dbde  xor     ecx, ecx; Expression
0x14000dbe0  call    _invoke_watson
0x14000dbe6  xor     r9d, r9d; LineNo
0x14000dbe9  mov     [rsp+810h+Reserved], r13; Reserved
0x14000dbee  xor     r8d, r8d; FileName
0x14000dbf1  xor     edx, edx; FunctionName
0x14000dbf3  xor     ecx, ecx; Expression
0x14000dbf5  call    _invoke_watson

// ===== memcpy_s @ 0x14000dbfc =====

0x14000dbfc  mov     [rsp+arg_0], rbx
0x14000dc01  mov     [rsp+arg_8], rsi
0x14000dc06  push    rdi
0x14000dc07  sub     rsp, 20h
0x14000dc0b  mov     rbx, r9
0x14000dc0e  mov     rsi, r8
0x14000dc11  mov     rdi, rdx
0x14000dc14  test    r9, r9
0x14000dc17  jnz     short loc_14000DC1D
0x14000dc19  xor     eax, eax
0x14000dc1b  jmp     short loc_14000DC73
0x14000dc1d  test    rcx, rcx
0x14000dc20  jnz     short loc_14000DC37
0x14000dc22  call    _errno
0x14000dc27  mov     ebx, 16h
0x14000dc2c  mov     [rax], ebx
0x14000dc2e  call    _invalid_parameter_noinfo
0x14000dc33  mov     eax, ebx
0x14000dc35  jmp     short loc_14000DC73
0x14000dc37  test    r8, r8
0x14000dc3a  jz      short loc_14000DC4E
0x14000dc3c  cmp     rdx, rbx
0x14000dc3f  jb      short loc_14000DC4E
0x14000dc41  mov     r8, rbx
0x14000dc44  mov     rdx, rsi
0x14000dc47  call    sub_1400036D0
0x14000dc4c  jmp     short loc_14000DC19
0x14000dc4e  mov     r8, rdx
0x14000dc51  xor     edx, edx
0x14000dc53  call    sub_140002F60
0x14000dc58  test    rsi, rsi
0x14000dc5b  jz      short loc_14000DC22
0x14000dc5d  cmp     rdi, rbx
0x14000dc60  jnb     short loc_14000DC6E
0x14000dc62  call    _errno
0x14000dc67  mov     ebx, 22h ; '"'
0x14000dc6c  jmp     short loc_14000DC2C
0x14000dc6e  mov     eax, 16h
0x14000dc73  mov     rbx, [rsp+28h+arg_0]
0x14000dc78  mov     rsi, [rsp+28h+arg_8]
0x14000dc7d  add     rsp, 20h
0x14000dc81  pop     rdi
0x14000dc82  retn

// ===== _isatty @ 0x14000dc84 =====

0x14000dc84  sub     rsp, 28h
0x14000dc88  cmp     ecx, 0FFFFFFFEh
0x14000dc8b  jnz     short loc_14000DC9A
0x14000dc8d  call    _errno
0x14000dc92  mov     dword ptr [rax], 9
0x14000dc98  jmp     short loc_14000DCDC
0x14000dc9a  test    ecx, ecx
0x14000dc9c  js      short loc_14000DCCC
0x14000dc9e  cmp     ecx, cs:dword_14001D750
0x14000dca4  jnb     short loc_14000DCCC
0x14000dca6  movsxd  rcx, ecx
0x14000dca9  lea     rdx, qword_14001D350
0x14000dcb0  mov     rax, rcx
0x14000dcb3  and     ecx, 3Fh
0x14000dcb6  sar     rax, 6
0x14000dcba  shl     rcx, 6
0x14000dcbe  mov     rax, [rdx+rax*8]
0x14000dcc2  movzx   eax, byte ptr [rax+rcx+38h]
0x14000dcc7  and     eax, 40h
0x14000dcca  jmp     short loc_14000DCDE
0x14000dccc  call    _errno
0x14000dcd1  mov     dword ptr [rax], 9
0x14000dcd7  call    _invalid_parameter_noinfo
0x14000dcdc  xor     eax, eax
0x14000dcde  add     rsp, 28h
0x14000dce2  retn

// ===== ?GetTableIndexFromLocaleName@@YAHPEB_W@Z @ 0x14000dce4 =====

0x14000dce4  mov     rax, rsp
0x14000dce7  mov     [rax+8], rbx
0x14000dceb  mov     [rax+10h], rbp
0x14000dcef  mov     [rax+18h], rsi
0x14000dcf3  mov     [rax+20h], rdi
0x14000dcf7  push    r14
0x14000dcf9  xor     ebp, ebp
0x14000dcfb  lea     r14, off_140015D50
0x14000dd02  mov     r10d, ebp
0x14000dd05  mov     rsi, rcx
0x14000dd08  mov     r11d, 0E3h
0x14000dd0e  lea     eax, [r11+r10]
0x14000dd12  mov     rdi, rsi
0x14000dd15  cdq
0x14000dd16  mov     ebx, 55h ; 'U'
0x14000dd1b  sub     eax, edx
0x14000dd1d  sar     eax, 1
0x14000dd1f  movsxd  r8, eax
0x14000dd22  mov     rcx, r8
0x14000dd25  shl     rcx, 4
0x14000dd29  mov     r9, [rcx+r14]
0x14000dd2d  sub     rdi, r9
0x14000dd30  movzx   edx, word ptr [rdi+r9]
0x14000dd35  lea     ecx, [rdx-41h]
0x14000dd38  cmp     cx, 19h
0x14000dd3c  ja      short loc_14000DD42
0x14000dd3e  add     dx, 20h ; ' '
0x14000dd42  movzx   ecx, word ptr [r9]
0x14000dd46  lea     eax, [rcx-41h]
0x14000dd49  cmp     ax, 19h
0x14000dd4d  ja      short loc_14000DD53
0x14000dd4f  add     cx, 20h ; ' '
0x14000dd53  add     r9, 2
0x14000dd57  sub     rbx, 1
0x14000dd5b  jz      short loc_14000DD67
0x14000dd5d  test    dx, dx
0x14000dd60  jz      short loc_14000DD67
0x14000dd62  cmp     dx, cx
0x14000dd65  jz      short loc_14000DD30
0x14000dd67  movzx   eax, cx
0x14000dd6a  movzx   ecx, dx
0x14000dd6d  sub     ecx, eax
0x14000dd6f  jz      short loc_14000DD89
0x14000dd71  test    ecx, ecx
0x14000dd73  jns     short loc_14000DD7B
0x14000dd75  lea     r11d, [r8-1]
0x14000dd79  jmp     short loc_14000DD7F
0x14000dd7b  lea     r10d, [r8+1]
0x14000dd7f  cmp     r10d, r11d
0x14000dd82  jle     short loc_14000DD0E
0x14000dd84  or      eax, 0FFFFFFFFh
0x14000dd87  jmp     short loc_14000DD94
0x14000dd89  mov     rax, r8
0x14000dd8c  add     rax, rax
0x14000dd8f  mov     eax, [r14+rax*8+8]
0x14000dd94  mov     rbx, [rsp+8+arg_0]
0x14000dd99  mov     rbp, [rsp+8+arg_8]
0x14000dd9e  mov     rsi, [rsp+8+arg_10]
0x14000dda3  mov     rdi, [rsp+8+arg_18]
0x14000dda8  pop     r14
0x14000ddaa  retn

// ===== __crtDownlevelLocaleNameToLCID @ 0x14000ddac =====

0x14000ddac  sub     rsp, 28h
0x14000ddb0  test    rcx, rcx
0x14000ddb3  jz      short loc_14000DDD7
0x14000ddb5  call    ?GetTableIndexFromLocaleName@@YAHPEB_W@Z
0x14000ddba  test    eax, eax
0x14000ddbc  js      short loc_14000DDD7
0x14000ddbe  cdqe
0x14000ddc0  cmp     rax, 0E4h
0x14000ddc6  jnb     short loc_14000DDD7
0x14000ddc8  add     rax, rax
0x14000ddcb  lea     rcx, unk_1400142F0
0x14000ddd2  mov     eax, [rcx+rax*8]
0x14000ddd5  jmp     short loc_14000DDD9
0x14000ddd7  xor     eax, eax
0x14000ddd9  add     rsp, 28h
0x14000dddd  retn

// ===== _fclose_nolock @ 0x14000dde0 =====

0x14000dde0  mov     [rsp+arg_0], rbx
0x14000dde5  push    rdi
0x14000dde6  sub     rsp, 20h
0x14000ddea  mov     rbx, rcx
0x14000dded  test    rcx, rcx
0x14000ddf0  jnz     short loc_14000DE07
0x14000ddf2  call    _errno
0x14000ddf7  mov     dword ptr [rax], 16h
0x14000ddfd  call    _invalid_parameter_noinfo
0x14000de02  or      eax, 0FFFFFFFFh
0x14000de05  jmp     short loc_14000DE58
0x14000de07  or      edi, 0FFFFFFFFh
0x14000de0a  mov     eax, [rcx+14h]
0x14000de0d  shr     eax, 0Dh
0x14000de10  test    al, 1
0x14000de12  jz      short loc_14000DE4E
0x14000de14  call    __acrt_stdio_flush_nolock
0x14000de19  mov     rcx, rbx
0x14000de1c  mov     edi, eax
0x14000de1e  call    __acrt_stdio_free_buffer_nolock
0x14000de23  mov     rcx, rbx; Stream
0x14000de26  call    _fileno
0x14000de2b  mov     ecx, eax
0x14000de2d  call    sub_14000F734
0x14000de32  test    eax, eax
0x14000de34  jns     short loc_14000DE3B
0x14000de36  or      edi, 0FFFFFFFFh
0x14000de39  jmp     short loc_14000DE4E
0x14000de3b  mov     rcx, [rbx+28h]; Block
0x14000de3f  test    rcx, rcx
0x14000de42  jz      short loc_14000DE4E
0x14000de44  call    _free_base
0x14000de49  and     qword ptr [rbx+28h], 0
0x14000de4e  mov     rcx, rbx
0x14000de51  call    ?__acrt_stdio_free_stream@@YAXV__crt_stdio_stream@@@Z
0x14000de56  mov     eax, edi
0x14000de58  mov     rbx, [rsp+28h+arg_0]
0x14000de5d  add     rsp, 20h
0x14000de61  pop     rdi
0x14000de62  retn

// ===== fclose @ 0x14000de64 =====

0x14000de64  mov     [rsp+arg_8], rbx
0x14000de69  mov     [rsp+arg_0], rcx
0x14000de6e  push    rdi
0x14000de6f  sub     rsp, 20h
0x14000de73  mov     rbx, rcx
0x14000de76  xor     eax, eax
0x14000de78  test    rcx, rcx
0x14000de7b  setnz   al
0x14000de7e  test    eax, eax
0x14000de80  jnz     short loc_14000DE97
0x14000de82  call    _errno
0x14000de87  mov     dword ptr [rax], 16h
0x14000de8d  call    _invalid_parameter_noinfo
0x14000de92  or      eax, 0FFFFFFFFh
0x14000de95  jmp     short loc_14000DEC2
0x14000de97  mov     eax, [rcx+14h]
0x14000de9a  shr     eax, 0Ch
0x14000de9d  test    al, 1
0x14000de9f  jz      short loc_14000DEA8
0x14000dea1  call    ?__acrt_stdio_free_stream@@YAXV__crt_stdio_stream@@@Z
0x14000dea6  jmp     short loc_14000DE92
0x14000dea8  call    sub_140005338
0x14000dead  nop
0x14000deae  mov     rcx, rbx; Stream
0x14000deb1  call    _fclose_nolock
0x14000deb6  mov     edi, eax
0x14000deb8  mov     rcx, rbx
0x14000debb  call    sub_140005344
0x14000dec0  mov     eax, edi
0x14000dec2  mov     rbx, [rsp+28h+arg_8]
0x14000dec7  add     rsp, 20h
0x14000decb  pop     rdi
0x14000decc  retn
0x140010b2a  push    rbp; Microsoft VisualC 64bit universal runtime
0x140010b2c  sub     rsp, 20h
0x140010b30  mov     rbp, rdx
0x140010b33  mov     rcx, [rbp+30h]
0x140010b37  add     rsp, 20h
0x140010b3b  pop     rbp
0x140010b3c  jmp     sub_140005344

// ===== ??$?RV_lambda_b521505b218e5242e90febf6bfebc422_@@AEAV_lambda_6978c1fb23f02e42e1d9e99668cc68aa_@@V_lambda_314360699dd331753a4119843814e9a7_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b521505b218e5242e90febf6bfebc422_@@AEAV_lambda_6978c1fb23f02e42e1d9e99668cc68aa_@@$$QEAV_lambda_314360699dd331753a4119843814e9a7_@@@Z @ 0x14000ded0 =====

0x14000ded0  mov     [rsp+arg_0], rbx
0x14000ded5  mov     [rsp+arg_18], r9
0x14000deda  push    rdi
0x14000dedb  sub     rsp, 20h
0x14000dedf  mov     rdi, r9
0x14000dee2  mov     rbx, r8
0x14000dee5  mov     ecx, [rdx]
0x14000dee7  call    sub_14000AD6C
0x14000deec  nop
0x14000deed  mov     rax, [rbx]
0x14000def0  movsxd  rcx, dword ptr [rax]; FileHandle
0x14000def3  mov     rdx, rcx
0x14000def6  mov     rax, rcx
0x14000def9  sar     rax, 6
0x14000defd  lea     r8, qword_14001D350
0x14000df04  and     edx, 3Fh
0x14000df07  shl     rdx, 6
0x14000df0b  mov     rax, [r8+rax*8]
0x14000df0f  test    byte ptr [rax+rdx+38h], 1
0x14000df14  jz      short loc_14000DF3A
0x14000df16  call    _get_osfhandle
0x14000df1b  mov     rcx, rax; hFile
0x14000df1e  call    cs:FlushFileBuffers; KERNEL32
0x14000df24  xor     ebx, ebx
0x14000df26  test    eax, eax
0x14000df28  jnz     short loc_14000DF48
0x14000df2a  call    __doserrno
0x14000df2f  mov     rbx, rax
0x14000df32  call    cs:GetLastError; KERNEL32
0x14000df38  mov     [rbx], eax
0x14000df3a  call    _errno
0x14000df3f  mov     dword ptr [rax], 9
0x14000df45  or      ebx, 0FFFFFFFFh
0x14000df48  mov     ecx, [rdi]
0x14000df4a  call    sub_14000AD90
0x14000df4f  mov     eax, ebx
0x14000df51  mov     rbx, [rsp+28h+arg_0]
0x14000df56  add     rsp, 20h
0x14000df5a  pop     rdi
0x14000df5b  retn
0x140010b42  push    rbp
0x140010b44  sub     rsp, 20h
0x140010b48  mov     rbp, rdx
0x140010b4b  mov     rax, [rbp+48h]
0x140010b4f  mov     ecx, [rax]
0x140010b51  add     rsp, 20h
0x140010b55  pop     rbp
0x140010b56  jmp     sub_14000AD90

// ===== _commit @ 0x14000df5c =====

0x14000df5c  mov     [rsp+arg_0], ecx
0x14000df60  sub     rsp, 38h
0x14000df64  movsxd  rdx, ecx
0x14000df67  cmp     edx, 0FFFFFFFEh
0x14000df6a  jnz     short loc_14000DF79
0x14000df6c  call    _errno
0x14000df71  mov     dword ptr [rax], 9
0x14000df77  jmp     short loc_14000DFE5
0x14000df79  test    ecx, ecx
0x14000df7b  js      short loc_14000DFD5
0x14000df7d  cmp     edx, cs:dword_14001D750
0x14000df83  jnb     short loc_14000DFD5
0x14000df85  mov     rcx, rdx
0x14000df88  lea     r8, qword_14001D350
0x14000df8f  and     ecx, 3Fh
0x14000df92  mov     rax, rdx
0x14000df95  sar     rax, 6
0x14000df99  shl     rcx, 6
0x14000df9d  mov     rax, [r8+rax*8]
0x14000dfa1  test    byte ptr [rax+rcx+38h], 1
0x14000dfa6  jz      short loc_14000DFD5
0x14000dfa8  lea     rax, [rsp+38h+arg_0]
0x14000dfad  mov     [rsp+38h+arg_10], edx
0x14000dfb1  mov     [rsp+38h+arg_18], edx
0x14000dfb5  lea     r9, [rsp+38h+arg_10]
0x14000dfba  lea     rdx, [rsp+38h+arg_18]
0x14000dfbf  mov     [rsp+38h+var_18], rax
0x14000dfc4  lea     r8, [rsp+38h+var_18]
0x14000dfc9  lea     rcx, [rsp+38h+arg_8]
0x14000dfce  call    ??$?RV_lambda_b521505b218e5242e90febf6bfebc422_@@AEAV_lambda_6978c1fb23f02e42e1d9e99668cc68aa_@@V_lambda_314360699dd331753a4119843814e9a7_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b521505b218e5242e90febf6bfebc422_@@AEAV_lambda_6978c1fb23f02e42e1d9e99668cc68aa_@@$$QEAV_lambda_314360699dd331753a4119843814e9a7_@@@Z
0x14000dfd3  jmp     short loc_14000DFE8
0x14000dfd5  call    _errno
0x14000dfda  mov     dword ptr [rax], 9
0x14000dfe0  call    _invalid_parameter_noinfo
0x14000dfe5  or      eax, 0FFFFFFFFh
0x14000dfe8  add     rsp, 38h
0x14000dfec  retn

// ===== ?write_double_translated_ansi_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x14000dff0 =====

0x14000dff0  mov     [rsp-38h+arg_0], rbx
0x14000dff5  push    rbp
0x14000dff6  push    rsi
0x14000dff7  push    rdi
0x14000dff8  push    r12
0x14000dffa  push    r13
0x14000dffc  push    r14
0x14000dffe  push    r15
0x14000e000  mov     rbp, rsp
0x14000e003  sub     rsp, 80h
0x14000e00a  mov     rax, cs:__security_cookie
0x14000e011  xor     rax, rsp
0x14000e014  mov     [rbp+var_10], rax
0x14000e018  movsxd  rsi, edx
0x14000e01b  lea     rax, qword_14001D350
0x14000e022  mov     r15, rsi
0x14000e025  mov     r12d, r9d
0x14000e028  sar     r15, 6
0x14000e02c  and     esi, 3Fh
0x14000e02f  shl     rsi, 6
0x14000e033  mov     r14, r8
0x14000e036  mov     [rbp+var_28], r8
0x14000e03a  mov     rbx, rcx
0x14000e03d  add     r12, r8
0x14000e040  mov     rax, [rax+r15*8]
0x14000e044  mov     rax, [rax+rsi+28h]
0x14000e049  mov     [rbp+hFile], rax
0x14000e04d  call    cs:GetConsoleCP; KERNEL32
0x14000e053  xor     edx, edx
0x14000e055  mov     [rbp+CodePage], eax
0x14000e058  mov     [rbx], rdx
0x14000e05b  mov     rdi, r14
0x14000e05e  mov     [rbx+8], edx
0x14000e061  cmp     r14, r12
0x14000e064  jnb     loc_14000E1CE
0x14000e06a  mov     r13b, [rdi]
0x14000e06d  lea     r14, qword_14001D350
0x14000e074  mov     [rbp+WideCharStr], dx
0x14000e078  mov     rdx, [r14+r15*8]
0x14000e07c  mov     cl, [rdx+rsi+3Dh]
0x14000e080  test    cl, 4
0x14000e083  jz      short loc_14000E0A3
0x14000e085  mov     al, [rdx+rsi+3Eh]
0x14000e089  and     cl, 0FBh
0x14000e08c  mov     [rdx+rsi+3Dh], cl
0x14000e090  mov     r8d, 2
0x14000e096  lea     rdx, [rbp+var_20]
0x14000e09a  mov     [rbp+var_20], al
0x14000e09d  mov     [rbp+var_1F], r13b
0x14000e0a1  jmp     short loc_14000E0E8
0x14000e0a3  call    __pctype_func
0x14000e0a8  movzx   ecx, byte ptr [rdi]
0x14000e0ab  mov     edx, 8000h
0x14000e0b0  test    [rax+rcx*2], dx
0x14000e0b4  jz      short loc_14000E0DF
0x14000e0b6  cmp     rdi, r12
0x14000e0b9  jnb     loc_14000E1AE
0x14000e0bf  mov     r8d, 2; SrcSizeInBytes
0x14000e0c5  lea     rcx, [rbp+WideCharStr]; DstCh
0x14000e0c9  mov     rdx, rdi; SrcCh
0x14000e0cc  call    mbtowc
0x14000e0d1  cmp     eax, 0FFFFFFFFh
0x14000e0d4  jz      loc_14000E1CE
0x14000e0da  inc     rdi
0x14000e0dd  jmp     short loc_14000E0FA
0x14000e0df  mov     r8d, 1; SrcSizeInBytes
0x14000e0e5  mov     rdx, rdi; SrcCh
0x14000e0e8  lea     rcx, [rbp+WideCharStr]; DstCh
0x14000e0ec  call    mbtowc
0x14000e0f1  cmp     eax, 0FFFFFFFFh
0x14000e0f4  jz      loc_14000E1CE
0x14000e0fa  and     [rsp+80h+var_48], 0
0x14000e100  lea     rax, [rbp+MultiByteStr]
0x14000e104  and     [rsp+80h+var_50], 0
0x14000e10a  lea     r8, [rbp+WideCharStr]; lpWideCharStr
0x14000e10e  mov     ecx, [rbp+CodePage]; CodePage
0x14000e111  mov     r9d, 1; cchWideChar
0x14000e117  mov     [rsp+80h+cbMultiByte], 5; cbMultiByte
0x14000e11f  xor     edx, edx; dwFlags
0x14000e121  mov     [rsp+80h+lpMultiByteStr], rax; lpOverlapped
0x14000e126  inc     rdi
0x14000e129  call    cs:WideCharToMultiByte; KERNEL32
0x14000e12f  mov     r14d, eax
0x14000e132  test    eax, eax
0x14000e134  jz      loc_14000E1CE
0x14000e13a  mov     rcx, [rbp+hFile]; hFile
0x14000e13e  lea     r9, [rbp+NumberOfBytesWritten]; lpNumberOfBytesWritten
0x14000e142  and     [rsp+80h+lpMultiByteStr], 0
0x14000e148  lea     rdx, [rbp+MultiByteStr]; lpBuffer
0x14000e14c  mov     r8d, eax; nNumberOfBytesToWrite
0x14000e14f  call    cs:WriteFile; KERNEL32
0x14000e155  xor     edx, edx
0x14000e157  test    eax, eax
0x14000e159  jz      short loc_14000E1C6
0x14000e15b  mov     ecx, [rbx+8]
0x14000e15e  sub     ecx, dword ptr [rbp+var_28]
0x14000e161  add     ecx, edi
0x14000e163  mov     [rbx+4], ecx
0x14000e166  cmp     [rbp+NumberOfBytesWritten], r14d
0x14000e16a  jb      short loc_14000E1CE
0x14000e16c  cmp     r13b, 0Ah
0x14000e170  jnz     short loc_14000E1A6
0x14000e172  mov     rcx, [rbp+hFile]; hFile
0x14000e176  lea     eax, [rdx+0Dh]
0x14000e179  mov     [rsp+80h+lpMultiByteStr], rdx; lpOverlapped
0x14000e17e  lea     r8d, [rdx+1]; nNumberOfBytesToWrite
0x14000e182  lea     rdx, [rbp+Buffer]; lpBuffer
0x14000e186  mov     [rbp+Buffer], ax
0x14000e18a  lea     r9, [rbp+NumberOfBytesWritten]; lpNumberOfBytesWritten
0x14000e18e  call    cs:WriteFile; KERNEL32
0x14000e194  xor     edx, edx
0x14000e196  test    eax, eax
0x14000e198  jz      short loc_14000E1C6
0x14000e19a  cmp     [rbp+NumberOfBytesWritten], 1
0x14000e19e  jb      short loc_14000E1CE
0x14000e1a0  inc     dword ptr [rbx+8]
0x14000e1a3  inc     dword ptr [rbx+4]
0x14000e1a6  cmp     rdi, r12
0x14000e1a9  jmp     loc_14000E064
0x14000e1ae  mov     al, [rdi]
0x14000e1b0  mov     rcx, [r14+r15*8]
0x14000e1b4  mov     [rcx+rsi+3Eh], al
0x14000e1b8  mov     rax, [r14+r15*8]
0x14000e1bc  or      byte ptr [rax+rsi+3Dh], 4
0x14000e1c1  inc     dword ptr [rbx+4]
0x14000e1c4  jmp     short loc_14000E1CE
0x14000e1c6  call    cs:GetLastError; KERNEL32
0x14000e1cc  mov     [rbx], eax
0x14000e1ce  mov     rax, rbx
0x14000e1d1  mov     rcx, [rbp+var_10]
0x14000e1d5  xor     rcx, rsp; StackCookie
0x14000e1d8  call    __security_check_cookie
0x14000e1dd  mov     rbx, [rsp+80h+arg_0]
0x14000e1e5  add     rsp, 80h
0x14000e1ec  pop     r15
0x14000e1ee  pop     r14
0x14000e1f0  pop     r13
0x14000e1f2  pop     r12
0x14000e1f4  pop     rdi
0x14000e1f5  pop     rsi
0x14000e1f6  pop     rbp
0x14000e1f7  retn

// ===== ?write_text_ansi_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x14000e1f8 =====

0x14000e1f8  mov     [rsp+arg_0], rbx; lpOverlapped
0x14000e1fd  mov     [rsp+arg_10], rbp
0x14000e202  push    rsi
0x14000e203  push    rdi
0x14000e204  push    r14
0x14000e206  mov     eax, 1450h
0x14000e20b  call    _alloca_probe
0x14000e210  sub     rsp, rax
0x14000e213  mov     rax, cs:__security_cookie
0x14000e21a  xor     rax, rsp
0x14000e21d  mov     [rsp+1468h+var_28], rax
0x14000e225  mov     rbx, rcx
0x14000e228  movsxd  r10, edx
0x14000e22b  mov     rax, r10
0x14000e22e  mov     ebp, r9d
0x14000e231  sar     rax, 6
0x14000e235  lea     rcx, qword_14001D350
0x14000e23c  and     r10d, 3Fh
0x14000e240  add     rbp, r8
0x14000e243  and     dword ptr [rbx], 0
0x14000e246  mov     rsi, r8
0x14000e249  and     dword ptr [rbx+4], 0
0x14000e24d  mov     rax, [rcx+rax*8]
0x14000e251  and     dword ptr [rbx+8], 0
0x14000e255  shl     r10, 6
0x14000e259  mov     r14, [rax+r10+28h]
0x14000e25e  cmp     r8, rbp
0x14000e261  jnb     short loc_14000E2D2
0x14000e263  lea     rdi, [rsp+1468h+Buffer]
0x14000e268  cmp     rsi, rbp
0x14000e26b  jnb     short loc_14000E291
0x14000e26d  mov     al, [rsi]
0x14000e26f  inc     rsi
0x14000e272  cmp     al, 0Ah
0x14000e274  jnz     short loc_14000E27F
0x14000e276  inc     dword ptr [rbx+8]
0x14000e279  mov     byte ptr [rdi], 0Dh
0x14000e27c  inc     rdi
0x14000e27f  mov     [rdi], al
0x14000e281  inc     rdi
0x14000e284  lea     rax, [rsp+1468h+var_29]
0x14000e28c  cmp     rdi, rax
0x14000e28f  jb      short loc_14000E268
0x14000e291  and     [rsp+1468h+var_1448], 0
0x14000e297  lea     rax, [rsp+1468h+Buffer]
0x14000e29c  sub     edi, eax
0x14000e29e  lea     r9, [rsp+1468h+NumberOfBytesWritten]; lpNumberOfBytesWritten
0x14000e2a3  mov     r8d, edi; nNumberOfBytesToWrite
0x14000e2a6  lea     rdx, [rsp+1468h+Buffer]; lpBuffer
0x14000e2ab  mov     rcx, r14; hFile
0x14000e2ae  call    cs:WriteFile; KERNEL32
0x14000e2b4  test    eax, eax
0x14000e2b6  jz      short loc_14000E2CA
0x14000e2b8  mov     eax, [rsp+1468h+NumberOfBytesWritten]
0x14000e2bc  add     [rbx+4], eax
0x14000e2bf  cmp     eax, edi
0x14000e2c1  jb      short loc_14000E2D2
0x14000e2c3  cmp     rsi, rbp
0x14000e2c6  jb      short loc_14000E263
0x14000e2c8  jmp     short loc_14000E2D2
0x14000e2ca  call    cs:GetLastError; KERNEL32
0x14000e2d0  mov     [rbx], eax
0x14000e2d2  mov     rax, rbx
0x14000e2d5  mov     rcx, [rsp+1468h+var_28]
0x14000e2dd  xor     rcx, rsp; StackCookie
0x14000e2e0  call    __security_check_cookie
0x14000e2e5  lea     r11, [rsp+1468h+var_18]
0x14000e2ed  mov     rbx, [r11+20h]
0x14000e2f1  mov     rbp, [r11+30h]
0x14000e2f5  mov     rsp, r11
0x14000e2f8  pop     r14
0x14000e2fa  pop     rdi
0x14000e2fb  pop     rsi
0x14000e2fc  retn

// ===== ?write_text_utf16le_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x14000e300 =====

0x14000e300  mov     [rsp+arg_0], rbx; lpOverlapped
0x14000e305  mov     [rsp+arg_10], rbp
0x14000e30a  push    rsi
0x14000e30b  push    rdi
0x14000e30c  push    r14
0x14000e30e  mov     eax, 1450h
0x14000e313  call    _alloca_probe
0x14000e318  sub     rsp, rax
0x14000e31b  mov     rax, cs:__security_cookie
0x14000e322  xor     rax, rsp
0x14000e325  mov     [rsp+1468h+var_28], rax
0x14000e32d  mov     rdi, rcx
0x14000e330  movsxd  r10, edx
0x14000e333  mov     rax, r10
0x14000e336  mov     ebp, r9d
0x14000e339  sar     rax, 6
0x14000e33d  lea     rcx, qword_14001D350
0x14000e344  and     r10d, 3Fh
0x14000e348  add     rbp, r8
0x14000e34b  and     dword ptr [rdi], 0
0x14000e34e  mov     rsi, r8
0x14000e351  and     dword ptr [rdi+4], 0
0x14000e355  mov     rax, [rcx+rax*8]
0x14000e359  and     dword ptr [rdi+8], 0
0x14000e35d  shl     r10, 6
0x14000e361  mov     r14, [rax+r10+28h]
0x14000e366  cmp     r8, rbp
0x14000e369  jnb     loc_14000E3F1
0x14000e36f  lea     rbx, [rsp+1468h+Buffer]
0x14000e374  cmp     rsi, rbp
0x14000e377  jnb     short loc_14000E3AA
0x14000e379  movzx   eax, word ptr [rsi]
0x14000e37c  add     rsi, 2
0x14000e380  cmp     ax, 0Ah
0x14000e384  jnz     short loc_14000E396
0x14000e386  add     dword ptr [rdi+8], 2
0x14000e38a  mov     ecx, 0Dh
0x14000e38f  mov     [rbx], cx
0x14000e392  add     rbx, 2
0x14000e396  mov     [rbx], ax
0x14000e399  add     rbx, 2
0x14000e39d  lea     rax, [rsp+1468h+var_2A]
0x14000e3a5  cmp     rbx, rax
0x14000e3a8  jb      short loc_14000E374
0x14000e3aa  and     [rsp+1468h+var_1448], 0
0x14000e3b0  lea     rax, [rsp+1468h+Buffer]
0x14000e3b5  sub     rbx, rax
0x14000e3b8  lea     r9, [rsp+1468h+NumberOfBytesWritten]; lpNumberOfBytesWritten
0x14000e3bd  sar     rbx, 1
0x14000e3c0  lea     rdx, [rsp+1468h+Buffer]; lpBuffer
0x14000e3c5  add     ebx, ebx
0x14000e3c7  mov     rcx, r14; hFile
0x14000e3ca  mov     r8d, ebx; nNumberOfBytesToWrite
0x14000e3cd  call    cs:WriteFile; KERNEL32
0x14000e3d3  test    eax, eax
0x14000e3d5  jz      short loc_14000E3E9
0x14000e3d7  mov     eax, [rsp+1468h+NumberOfBytesWritten]
0x14000e3db  add     [rdi+4], eax
0x14000e3de  cmp     eax, ebx
0x14000e3e0  jb      short loc_14000E3F1
0x14000e3e2  cmp     rsi, rbp
0x14000e3e5  jb      short loc_14000E36F
0x14000e3e7  jmp     short loc_14000E3F1
0x14000e3e9  call    cs:GetLastError; KERNEL32
0x14000e3ef  mov     [rdi], eax
0x14000e3f1  mov     rax, rdi
0x14000e3f4  mov     rcx, [rsp+1468h+var_28]
0x14000e3fc  xor     rcx, rsp; StackCookie
0x14000e3ff  call    __security_check_cookie
0x14000e404  lea     r11, [rsp+1468h+var_18]
0x14000e40c  mov     rbx, [r11+20h]
0x14000e410  mov     rbp, [r11+30h]
0x14000e414  mov     rsp, r11
0x14000e417  pop     r14
0x14000e419  pop     rdi
0x14000e41a  pop     rsi
0x14000e41b  retn

// ===== ?write_text_utf8_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x14000e41c =====

0x14000e41c  mov     [rsp+arg_0], rbx; lpDefaultChar
0x14000e421  mov     [rsp+arg_10], rbp
0x14000e426  push    rsi
0x14000e427  push    rdi
0x14000e428  push    r12
0x14000e42a  push    r14
0x14000e42c  push    r15
0x14000e42e  mov     eax, 1470h
0x14000e433  call    _alloca_probe
0x14000e438  sub     rsp, rax
0x14000e43b  mov     rax, cs:__security_cookie
0x14000e442  xor     rax, rsp
0x14000e445  mov     [rsp+1498h+var_38], rax
0x14000e44d  movsxd  r10, edx
0x14000e450  mov     rbx, rcx
0x14000e453  mov     rax, r10
0x14000e456  mov     r14d, r9d
0x14000e459  sar     rax, 6
0x14000e45d  lea     rcx, qword_14001D350
0x14000e464  and     r10d, 3Fh
0x14000e468  add     r14, r8
0x14000e46b  shl     r10, 6
0x14000e46f  mov     r15, r8
0x14000e472  mov     rdi, r8
0x14000e475  mov     rax, [rcx+rax*8]
0x14000e479  mov     r12, [rax+r10+28h]
0x14000e47e  xor     eax, eax
0x14000e480  and     dword ptr [rbx], 0
0x14000e483  mov     [rbx+4], rax
0x14000e487  cmp     r8, r14
0x14000e48a  jnb     loc_14000E55F
0x14000e490  lea     rax, [rsp+1498h+WideCharStr]
0x14000e495  cmp     rdi, r14
0x14000e498  jnb     short loc_14000E4C7
0x14000e49a  movzx   ecx, word ptr [rdi]
0x14000e49d  add     rdi, 2
0x14000e4a1  cmp     cx, 0Ah
0x14000e4a5  jnz     short loc_14000E4B3
0x14000e4a7  mov     edx, 0Dh
0x14000e4ac  mov     [rax], dx
0x14000e4af  add     rax, 2
0x14000e4b3  mov     [rax], cx
0x14000e4b6  add     rax, 2
0x14000e4ba  lea     rcx, [rsp+1498h+var_DA0]
0x14000e4c2  cmp     rax, rcx
0x14000e4c5  jb      short loc_14000E495
0x14000e4c7  and     [rsp+1498h+var_1460], 0
0x14000e4cd  lea     rcx, [rsp+1498h+WideCharStr]
0x14000e4d2  and     [rsp+1498h+var_1468], 0
0x14000e4d8  lea     r8, [rsp+1498h+WideCharStr]; lpWideCharStr
0x14000e4dd  sub     rax, rcx
0x14000e4e0  mov     [rsp+1498h+cbMultiByte], 0D55h; cbMultiByte
0x14000e4e8  lea     rcx, [rsp+1498h+MultiByteStr]
0x14000e4f0  sar     rax, 1
0x14000e4f3  mov     [rsp+1498h+lpMultiByteStr], rcx; lpOverlapped
0x14000e4f8  mov     r9d, eax; cchWideChar
0x14000e4fb  mov     ecx, 0FDE9h; CodePage
0x14000e500  xor     edx, edx; dwFlags
0x14000e502  call    cs:WideCharToMultiByte; KERNEL32
0x14000e508  mov     ebp, eax
0x14000e50a  test    eax, eax
0x14000e50c  jz      short loc_14000E557
0x14000e50e  xor     esi, esi
0x14000e510  test    eax, eax
0x14000e512  jz      short loc_14000E547
0x14000e514  and     [rsp+1498h+lpMultiByteStr], 0
0x14000e51a  lea     rdx, [rsp+1498h+MultiByteStr]
0x14000e522  mov     ecx, esi
0x14000e524  lea     r9, [rsp+1498h+NumberOfBytesWritten]; lpNumberOfBytesWritten
0x14000e529  mov     r8d, ebp
0x14000e52c  add     rdx, rcx; lpBuffer
0x14000e52f  mov     rcx, r12; hFile
0x14000e532  sub     r8d, esi; nNumberOfBytesToWrite
0x14000e535  call    cs:WriteFile; KERNEL32
0x14000e53b  test    eax, eax
0x14000e53d  jz      short loc_14000E557
0x14000e53f  add     esi, [rsp+1498h+NumberOfBytesWritten]
0x14000e543  cmp     esi, ebp
0x14000e545  jb      short loc_14000E514
0x14000e547  mov     eax, edi
0x14000e549  sub     eax, r15d
0x14000e54c  mov     [rbx+4], eax
0x14000e54f  cmp     rdi, r14
0x14000e552  jmp     loc_14000E48A
0x14000e557  call    cs:GetLastError; KERNEL32
0x14000e55d  mov     [rbx], eax
0x14000e55f  mov     rax, rbx
0x14000e562  mov     rcx, [rsp+1498h+var_38]
0x14000e56a  xor     rcx, rsp; StackCookie
0x14000e56d  call    __security_check_cookie
0x14000e572  lea     r11, [rsp+1498h+var_28]
0x14000e57a  mov     rbx, [r11+30h]
0x14000e57e  mov     rbp, [r11+40h]
0x14000e582  mov     rsp, r11
0x14000e585  pop     r15
0x14000e587  pop     r14
0x14000e589  pop     r12
0x14000e58b  pop     rdi
0x14000e58c  pop     rsi
0x14000e58d  retn

// ===== _write @ 0x14000e590 =====

0x14000e590  mov     [rsp+arg_8], rbx
0x14000e595  mov     [rsp+arg_10], rsi
0x14000e59a  mov     [rsp+arg_0], ecx
0x14000e59e  push    rdi
0x14000e59f  push    r12
0x14000e5a1  push    r13
0x14000e5a3  push    r14
0x14000e5a5  push    r15
0x14000e5a7  sub     rsp, 20h
0x14000e5ab  mov     r15d, r8d
0x14000e5ae  mov     r12, rdx
0x14000e5b1  movsxd  rbx, ecx
0x14000e5b4  cmp     ebx, 0FFFFFFFEh
0x14000e5b7  jnz     short loc_14000E5D1
0x14000e5b9  call    __doserrno
0x14000e5be  and     dword ptr [rax], 0
0x14000e5c1  call    _errno
0x14000e5c6  mov     dword ptr [rax], 9
0x14000e5cc  jmp     loc_14000E661
0x14000e5d1  test    ecx, ecx
0x14000e5d3  js      short loc_14000E649
0x14000e5d5  cmp     ebx, cs:dword_14001D750
0x14000e5db  jnb     short loc_14000E649
0x14000e5dd  mov     rsi, rbx
0x14000e5e0  mov     r14, rbx
0x14000e5e3  sar     r14, 6
0x14000e5e7  lea     r13, qword_14001D350
0x14000e5ee  and     esi, 3Fh
0x14000e5f1  shl     rsi, 6
0x14000e5f5  mov     rax, [r13+r14*8+0]
0x14000e5fa  movzx   ecx, byte ptr [rax+rsi+38h]
0x14000e5ff  and     ecx, 1
0x14000e602  jz      short loc_14000E649
0x14000e604  mov     ecx, ebx
0x14000e606  call    sub_14000AD6C
0x14000e60b  or      edi, 0FFFFFFFFh
0x14000e60e  mov     rax, [r13+r14*8+0]
0x14000e613  test    byte ptr [rax+rsi+38h], 1
0x14000e618  jnz     short loc_14000E62F
0x14000e61a  call    _errno
0x14000e61f  mov     dword ptr [rax], 9
0x14000e625  call    __doserrno
0x14000e62a  and     dword ptr [rax], 0
0x14000e62d  jmp     short loc_14000E63E
0x14000e62f  mov     r8d, r15d
0x14000e632  mov     rdx, r12
0x14000e635  mov     ecx, ebx
0x14000e637  call    _write_nolock
0x14000e63c  mov     edi, eax
0x14000e63e  mov     ecx, ebx
0x14000e640  call    sub_14000AD90
0x14000e645  mov     eax, edi
0x14000e647  jmp     short loc_14000E664
0x14000e649  call    __doserrno
0x14000e64e  and     dword ptr [rax], 0
0x14000e651  call    _errno
0x14000e656  mov     dword ptr [rax], 9
0x14000e65c  call    _invalid_parameter_noinfo
0x14000e661  or      eax, 0FFFFFFFFh
0x14000e664  mov     rbx, [rsp+48h+arg_8]
0x14000e669  mov     rsi, [rsp+48h+arg_10]
0x14000e66e  add     rsp, 20h
0x14000e672  pop     r15
0x14000e674  pop     r14
0x14000e676  pop     r13
0x14000e678  pop     r12
0x14000e67a  pop     rdi
0x14000e67b  retn
0x140010b5c  push    rbp; Microsoft VisualC 64bit universal runtime
0x140010b5e  sub     rsp, 20h
0x140010b62  mov     rbp, rdx
0x140010b65  mov     ecx, [rbp+50h]
0x140010b68  add     rsp, 20h
0x140010b6c  pop     rbp
0x140010b6d  jmp     sub_14000AD90

// ===== _write_nolock @ 0x14000e67c =====

0x14000e67c  mov     [rsp-38h+arg_18], rbx
0x14000e681  push    rbp
0x14000e682  push    rsi
0x14000e683  push    rdi
0x14000e684  push    r12
0x14000e686  push    r13
0x14000e688  push    r14
0x14000e68a  push    r15
0x14000e68c  mov     rbp, rsp
0x14000e68f  sub     rsp, 60h
0x14000e693  xor     edi, edi
0x14000e695  mov     r15d, r8d
0x14000e698  movsxd  r12, ecx
0x14000e69b  mov     rsi, rdx
0x14000e69e  test    r8d, r8d
0x14000e6a1  jnz     short loc_14000E6AA
0x14000e6a3  xor     eax, eax
0x14000e6a5  jmp     loc_14000E945
0x14000e6aa  test    rdx, rdx
0x14000e6ad  jnz     short loc_14000E6CE
0x14000e6af  call    __doserrno
0x14000e6b4  mov     [rax], edi
0x14000e6b6  call    _errno
0x14000e6bb  mov     dword ptr [rax], 16h
0x14000e6c1  call    _invalid_parameter_noinfo
0x14000e6c6  or      eax, 0FFFFFFFFh
0x14000e6c9  jmp     loc_14000E945
0x14000e6ce  mov     r14, r12
0x14000e6d1  lea     rax, qword_14001D350
0x14000e6d8  and     r14d, 3Fh
0x14000e6dc  mov     r13, r12
0x14000e6df  sar     r13, 6
0x14000e6e3  shl     r14, 6
0x14000e6e7  mov     [rbp+var_10], r13
0x14000e6eb  mov     rcx, [rax+r13*8]
0x14000e6ef  mov     bl, [rcx+r14+39h]
0x14000e6f4  lea     eax, [rbx-1]
0x14000e6f7  cmp     al, 1
0x14000e6f9  ja      short loc_14000E704
0x14000e6fb  mov     eax, r15d
0x14000e6fe  not     eax
0x14000e700  test    al, 1
0x14000e702  jz      short loc_14000E6AF
0x14000e704  test    byte ptr [rcx+r14+38h], 20h
0x14000e70a  jz      short loc_14000E71A
0x14000e70c  xor     edx, edx
0x14000e70e  mov     ecx, r12d
0x14000e711  lea     r8d, [rdx+2]
0x14000e715  call    j_??$common_lseek_nolock@_J@@YA_JH_JH@Z
0x14000e71a  mov     ecx, r12d; FileHandle
0x14000e71d  mov     [rbp+var_20], rdi
0x14000e721  call    _isatty
0x14000e726  test    eax, eax
0x14000e728  jz      loc_14000E82F
0x14000e72e  lea     rax, qword_14001D350
0x14000e735  mov     rax, [rax+r13*8]
0x14000e739  test    byte ptr [rax+r14+38h], 80h
0x14000e73f  jz      loc_14000E82F
0x14000e745  call    __acrt_getptd
0x14000e74a  mov     rcx, [rax+90h]
0x14000e751  cmp     [rcx+138h], rdi
0x14000e758  jnz     short loc_14000E770
0x14000e75a  lea     rax, qword_14001D350
0x14000e761  mov     rax, [rax+r13*8]
0x14000e765  cmp     [rax+r14+39h], dil
0x14000e76a  jz      loc_14000E82F
0x14000e770  lea     rax, qword_14001D350
0x14000e777  mov     rcx, [rax+r13*8]
0x14000e77b  lea     rdx, [rbp+Mode]; lpMode
0x14000e77f  mov     rcx, [rcx+r14+28h]; hConsoleHandle
0x14000e784  call    cs:GetConsoleMode; KERNEL32
0x14000e78a  test    eax, eax
0x14000e78c  jz      loc_14000E82F
0x14000e792  test    bl, bl
0x14000e794  jz      short loc_14000E811
0x14000e796  dec     bl
0x14000e798  cmp     bl, 1
0x14000e79b  ja      loc_14000E8CC
0x14000e7a1  and     [rbp+NumberOfBytesWritten], edi
0x14000e7a4  lea     r12, [rsi+r15]
0x14000e7a8  xor     ebx, ebx
0x14000e7aa  mov     r15, rsi
0x14000e7ad  mov     [rbp+NumberOfBytesWritten+4], ebx
0x14000e7b0  cmp     rsi, r12
0x14000e7b3  jnb     loc_14000E8C2
0x14000e7b9  movzx   r13d, word ptr [r15]
0x14000e7bd  movzx   ecx, r13w; Character
0x14000e7c1  call    _putwch_nolock
0x14000e7c6  cmp     ax, r13w
0x14000e7ca  jnz     short loc_14000E7FF
0x14000e7cc  add     ebx, 2
0x14000e7cf  mov     [rbp+NumberOfBytesWritten+4], ebx
0x14000e7d2  cmp     r13w, 0Ah
0x14000e7d7  jnz     short loc_14000E7F4
0x14000e7d9  mov     r13d, 0Dh
0x14000e7df  mov     ecx, r13d; Character
0x14000e7e2  call    _putwch_nolock
0x14000e7e7  cmp     ax, r13w
0x14000e7eb  jnz     short loc_14000E7FF
0x14000e7ed  inc     ebx
0x14000e7ef  mov     [rbp+NumberOfBytesWritten+4], ebx
0x14000e7f2  inc     edi
0x14000e7f4  add     r15, 2
0x14000e7f8  cmp     r15, r12
0x14000e7fb  jnb     short loc_14000E808
0x14000e7fd  jmp     short loc_14000E7B9
0x14000e7ff  call    cs:GetLastError; KERNEL32
0x14000e805  mov     [rbp+NumberOfBytesWritten], eax
0x14000e808  mov     r13, [rbp+var_10]
0x14000e80c  jmp     loc_14000E8C2
0x14000e811  mov     r9d, r15d
0x14000e814  lea     rcx, [rbp+NumberOfBytesWritten]
0x14000e818  mov     r8, rsi
0x14000e81b  mov     edx, r12d
0x14000e81e  call    ?write_double_translated_ansi_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z
0x14000e823  movsd   xmm0, qword ptr [rax]
0x14000e827  mov     edi, [rax+8]
0x14000e82a  jmp     loc_14000E8C7
0x14000e82f  lea     rax, qword_14001D350
0x14000e836  mov     rcx, [rax+r13*8]
0x14000e83a  test    byte ptr [rcx+r14+38h], 80h
0x14000e840  jz      short loc_14000E88F
0x14000e842  movsx   ecx, bl
0x14000e845  test    bl, bl
0x14000e847  jz      short loc_14000E87B
0x14000e849  sub     ecx, 1
0x14000e84c  jz      short loc_14000E867
0x14000e84e  cmp     ecx, 1
0x14000e851  jnz     short loc_14000E8CC
0x14000e853  mov     r9d, r15d
0x14000e856  lea     rcx, [rbp+NumberOfBytesWritten]
0x14000e85a  mov     r8, rsi
0x14000e85d  mov     edx, r12d
0x14000e860  call    ?write_text_utf16le_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z
0x14000e865  jmp     short loc_14000E823
0x14000e867  mov     r9d, r15d
0x14000e86a  lea     rcx, [rbp+NumberOfBytesWritten]
0x14000e86e  mov     r8, rsi
0x14000e871  mov     edx, r12d
0x14000e874  call    ?write_text_utf8_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z
0x14000e879  jmp     short loc_14000E823
0x14000e87b  mov     r9d, r15d
0x14000e87e  lea     rcx, [rbp+NumberOfBytesWritten]
0x14000e882  mov     r8, rsi
0x14000e885  mov     edx, r12d
0x14000e888  call    ?write_text_ansi_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z
0x14000e88d  jmp     short loc_14000E823
0x14000e88f  mov     rcx, [rcx+r14+28h]; hFile
0x14000e894  lea     r9, [rbp+NumberOfBytesWritten+4]; lpNumberOfBytesWritten
0x14000e898  and     [rbp+NumberOfBytesWritten], edi
0x14000e89b  xor     eax, eax
0x14000e89d  and     [rsp+60h+var_40], rax
0x14000e8a2  mov     r8d, r15d; nNumberOfBytesToWrite
0x14000e8a5  mov     rdx, rsi; lpBuffer
0x14000e8a8  mov     qword ptr [rbp+NumberOfBytesWritten+4], rax
0x14000e8ac  call    cs:WriteFile; KERNEL32
0x14000e8b2  test    eax, eax
0x14000e8b4  jnz     short loc_14000E8BF
0x14000e8b6  call    cs:GetLastError; KERNEL32
0x14000e8bc  mov     [rbp+NumberOfBytesWritten], eax
0x14000e8bf  mov     edi, [rbp+NumberOfBytesWritten+8]
0x14000e8c2  movsd   xmm0, qword ptr [rbp+NumberOfBytesWritten]
0x14000e8c7  movsd   [rbp+var_20], xmm0
0x14000e8cc  mov     rax, [rbp+var_20]
0x14000e8d0  shr     rax, 20h
0x14000e8d4  test    eax, eax
0x14000e8d6  jnz     short loc_14000E940
0x14000e8d8  mov     eax, dword ptr [rbp+var_20]
0x14000e8db  test    eax, eax
0x14000e8dd  jz      short loc_14000E90C
0x14000e8df  cmp     eax, 5
0x14000e8e2  jnz     short loc_14000E8FF
0x14000e8e4  call    _errno
0x14000e8e9  mov     dword ptr [rax], 9
0x14000e8ef  call    __doserrno
0x14000e8f4  mov     dword ptr [rax], 5
0x14000e8fa  jmp     loc_14000E6C6
0x14000e8ff  mov     ecx, dword ptr [rbp+var_20]
0x14000e902  call    __acrt_errno_map_os_error
0x14000e907  jmp     loc_14000E6C6
0x14000e90c  lea     rax, qword_14001D350
0x14000e913  mov     rax, [rax+r13*8]
0x14000e917  test    byte ptr [rax+r14+38h], 40h
0x14000e91d  jz      short loc_14000E928
0x14000e91f  cmp     byte ptr [rsi], 1Ah
0x14000e922  jz      loc_14000E6A3
0x14000e928  call    _errno
0x14000e92d  mov     dword ptr [rax], 1Ch
0x14000e933  call    __doserrno
0x14000e938  and     dword ptr [rax], 0
0x14000e93b  jmp     loc_14000E6C6
0x14000e940  mov     eax, dword ptr [rbp+var_20+4]
0x14000e943  sub     eax, edi
0x14000e945  mov     rbx, [rsp+60h+arg_18]
0x14000e94d  add     rsp, 60h
0x14000e951  pop     r15
0x14000e953  pop     r14
0x14000e955  pop     r13
0x14000e957  pop     r12
0x14000e959  pop     rdi
0x14000e95a  pop     rsi
0x14000e95b  pop     rbp
0x14000e95c  retn

// ===== __crtLCMapStringW @ 0x14000e960 =====

0x14000e960  mov     [rsp+arg_0], rbx
0x14000e965  mov     [rsp+arg_8], rbp
0x14000e96a  mov     [rsp+arg_10], rsi
0x14000e96f  push    rdi
0x14000e970  sub     rsp, 50h
0x14000e974  movsxd  rbx, r9d
0x14000e977  mov     rdi, r8
0x14000e97a  mov     esi, edx
0x14000e97c  mov     rbp, rcx
0x14000e97f  test    r9d, r9d
0x14000e982  jle     short loc_14000E998
0x14000e984  mov     rdx, rbx; MaxCount
0x14000e987  mov     rcx, r8; Source
0x14000e98a  call    wcsnlen
0x14000e98f  cmp     eax, ebx
0x14000e991  lea     ebx, [rax+1]
0x14000e994  jl      short loc_14000E998
0x14000e996  mov     ebx, eax
0x14000e998  and     [rsp+58h+var_18], 0
0x14000e99e  mov     r9d, ebx
0x14000e9a1  and     [rsp+58h+var_20], 0
0x14000e9a7  mov     r8, rdi
0x14000e9aa  and     [rsp+58h+var_28], 0
0x14000e9b0  mov     edx, esi
0x14000e9b2  mov     eax, [rsp+58h+arg_28]
0x14000e9b9  mov     rcx, rbp
0x14000e9bc  mov     [rsp+58h+var_30], eax
0x14000e9c0  mov     rax, [rsp+58h+arg_20]
0x14000e9c8  mov     [rsp+58h+var_38], rax
0x14000e9cd  call    __acrt_LCMapStringEx
0x14000e9d2  mov     rbx, [rsp+58h+arg_0]
0x14000e9d7  mov     rbp, [rsp+58h+arg_8]
0x14000e9dc  mov     rsi, [rsp+58h+arg_10]
0x14000e9e1  add     rsp, 50h
0x14000e9e5  pop     rdi
0x14000e9e6  retn

// ===== ?shortsort@@YAXPEAD0_KP6AHPEBX2@Z@Z @ 0x14000e9f0 =====

0x14000e9f0  cmp     rdx, rcx
0x14000e9f3  jbe     locret_14000EABB
0x14000e9f9  mov     [rsp+arg_18], rbp
0x14000e9fe  push    rdi
0x14000e9ff  push    r14
0x14000ea01  push    r15
0x14000ea03  sub     rsp, 20h
0x14000ea07  mov     [rsp+38h+arg_0], rbx
0x14000ea0c  mov     r14, r9
0x14000ea0f  mov     [rsp+38h+arg_8], rsi
0x14000ea14  mov     rbp, r8
0x14000ea17  mov     [rsp+38h+arg_10], r12
0x14000ea1c  mov     rdi, rdx
0x14000ea1f  lea     r12, [rcx+r8]
0x14000ea23  mov     r15, rcx
0x14000ea26  nop     word ptr [rax+rax+00000000h]
0x14000ea30  mov     rbx, r15
0x14000ea33  mov     rsi, r12
0x14000ea36  cmp     r12, rdi
0x14000ea39  ja      short loc_14000EA60
0x14000ea3b  nop     dword ptr [rax+rax+00h]
0x14000ea40  mov     rcx, r14
0x14000ea43  call    cs:__guard_check_icall_fptr
0x14000ea49  mov     rdx, rbx
0x14000ea4c  mov     rcx, rsi
0x14000ea4f  call    r14
0x14000ea52  test    eax, eax
0x14000ea54  cmovg   rbx, rsi
0x14000ea58  add     rsi, rbp
0x14000ea5b  cmp     rsi, rdi
0x14000ea5e  jbe     short loc_14000EA40
0x14000ea60  mov     r8, rbp
0x14000ea63  mov     rax, rdi
0x14000ea66  cmp     rbx, rdi
0x14000ea69  jz      short loc_14000EA96
0x14000ea6b  test    rbp, rbp
0x14000ea6e  jz      short loc_14000EA96
0x14000ea70  sub     rbx, rdi
0x14000ea73  nop     dword ptr [rax+00h]
0x14000ea77  nop     word ptr [rax+rax+00000000h]
0x14000ea80  movzx   ecx, byte ptr [rax]
0x14000ea83  movzx   edx, byte ptr [rbx+rax]
0x14000ea87  mov     [rbx+rax], cl
0x14000ea8a  mov     [rax], dl
0x14000ea8c  lea     rax, [rax+1]
0x14000ea90  sub     r8, 1
0x14000ea94  jnz     short loc_14000EA80
0x14000ea96  sub     rdi, rbp
0x14000ea99  cmp     rdi, r15
0x14000ea9c  ja      short loc_14000EA30
0x14000ea9e  mov     r12, [rsp+38h+arg_10]
0x14000eaa3  mov     rsi, [rsp+38h+arg_8]
0x14000eaa8  mov     rbx, [rsp+38h+arg_0]
0x14000eaad  mov     rbp, [rsp+38h+arg_18]
0x14000eab2  add     rsp, 20h
0x14000eab6  pop     r15
0x14000eab8  pop     r14
0x14000eaba  pop     rdi
0x14000eabb  retn

// ===== qsort @ 0x14000eac0 =====

0x14000eac0  push    rbp
0x14000eac2  push    r12
0x14000eac4  push    r14
0x14000eac6  sub     rsp, 440h
0x14000eacd  mov     rax, cs:__security_cookie
0x14000ead4  xor     rax, rsp
0x14000ead7  mov     [rsp+458h+var_58], rax
0x14000eadf  mov     r14, r9
0x14000eae2  mov     rbp, r8
0x14000eae5  mov     r12, rcx
0x14000eae8  test    rcx, rcx
0x14000eaeb  jnz     short loc_14000EB07
0x14000eaed  test    rdx, rdx
0x14000eaf0  jz      short loc_14000EB07
0x14000eaf2  call    _errno
0x14000eaf7  mov     dword ptr [rax], 16h
0x14000eafd  call    _invalid_parameter_noinfo
0x14000eb02  jmp     loc_14000EDD7
0x14000eb07  test    r8, r8
0x14000eb0a  jz      short loc_14000EAF2
0x14000eb0c  test    r9, r9
0x14000eb0f  jz      short loc_14000EAF2
0x14000eb11  cmp     rdx, 2
0x14000eb15  jb      loc_14000EDD7
0x14000eb1b  mov     [rsp+458h+var_20], rbx
0x14000eb23  mov     [rsp+458h+var_28], rsi
0x14000eb2b  mov     [rsp+458h+var_30], rdi
0x14000eb33  mov     [rsp+458h+var_38], r13
0x14000eb3b  mov     [rsp+458h+var_40], r15
0x14000eb43  lea     r15, [rdx-1]
0x14000eb47  imul    r15, rbp
0x14000eb4b  add     r15, rcx
0x14000eb4e  xor     r13d, r13d
0x14000eb51  xor     edx, edx
0x14000eb53  mov     rax, r15
0x14000eb56  sub     rax, r12
0x14000eb59  div     rbp
0x14000eb5c  lea     rsi, [rax+1]
0x14000eb60  cmp     rsi, 8
0x14000eb64  ja      short loc_14000EB90
0x14000eb66  mov     r9, r14; int (*)(const void *, const void *)
0x14000eb69  mov     r8, rbp; unsigned __int64
0x14000eb6c  mov     rdx, r15; char *
0x14000eb6f  mov     rcx, r12; char *
0x14000eb72  call    ?shortsort@@YAXPEAD0_KP6AHPEBX2@Z@Z
0x14000eb77  sub     r13, 1
0x14000eb7b  js      loc_14000EDAF
0x14000eb81  mov     r12, [rsp+r13*8+458h+var_438]
0x14000eb86  mov     r15, [rsp+r13*8+458h+var_248]
0x14000eb8e  jmp     short $recurse$173
0x14000eb90  shr     rsi, 1
0x14000eb93  mov     rcx, r14
0x14000eb96  imul    rsi, rbp
0x14000eb9a  add     rsi, r12
0x14000eb9d  call    cs:__guard_check_icall_fptr
0x14000eba3  mov     rdx, rsi
0x14000eba6  mov     rcx, r12
0x14000eba9  call    r14
0x14000ebac  test    eax, eax
0x14000ebae  jle     short loc_14000EBD9
0x14000ebb0  mov     r8, rbp
0x14000ebb3  mov     rdx, rsi
0x14000ebb6  cmp     r12, rsi
0x14000ebb9  jz      short loc_14000EBD9
0x14000ebbb  mov     r9, r12
0x14000ebbe  sub     r9, rsi
0x14000ebc1  movzx   eax, byte ptr [rdx]
0x14000ebc4  movzx   ecx, byte ptr [r9+rdx]
0x14000ebc9  mov     [r9+rdx], al
0x14000ebcd  mov     [rdx], cl
0x14000ebcf  lea     rdx, [rdx+1]
0x14000ebd3  sub     r8, 1
0x14000ebd7  jnz     short loc_14000EBC1
0x14000ebd9  mov     rcx, r14
0x14000ebdc  call    cs:__guard_check_icall_fptr
0x14000ebe2  mov     rdx, r15
0x14000ebe5  mov     rcx, r12
0x14000ebe8  call    r14
0x14000ebeb  test    eax, eax
0x14000ebed  jle     short loc_14000EC18
0x14000ebef  mov     r8, rbp
0x14000ebf2  mov     rdx, r15
0x14000ebf5  cmp     r12, r15
0x14000ebf8  jz      short loc_14000EC18
0x14000ebfa  mov     r9, r12
0x14000ebfd  sub     r9, r15
0x14000ec00  movzx   eax, byte ptr [rdx]
0x14000ec03  movzx   ecx, byte ptr [r9+rdx]
0x14000ec08  mov     [r9+rdx], al
0x14000ec0c  mov     [rdx], cl
0x14000ec0e  lea     rdx, [rdx+1]
0x14000ec12  sub     r8, 1
0x14000ec16  jnz     short loc_14000EC00
0x14000ec18  mov     rcx, r14
0x14000ec1b  call    cs:__guard_check_icall_fptr
0x14000ec21  mov     rdx, r15
0x14000ec24  mov     rcx, rsi
0x14000ec27  call    r14
0x14000ec2a  test    eax, eax
0x14000ec2c  jle     short loc_14000EC58
0x14000ec2e  mov     r8, rbp
0x14000ec31  mov     rdx, r15
0x14000ec34  cmp     rsi, r15
0x14000ec37  jz      short loc_14000EC58
0x14000ec39  mov     r9, rsi
0x14000ec3c  sub     r9, r15
0x14000ec3f  nop
0x14000ec40  movzx   eax, byte ptr [rdx]
0x14000ec43  movzx   ecx, byte ptr [r9+rdx]
0x14000ec48  mov     [r9+rdx], al
0x14000ec4c  mov     [rdx], cl
0x14000ec4e  lea     rdx, [rdx+1]
0x14000ec52  sub     r8, 1
0x14000ec56  jnz     short loc_14000EC40
0x14000ec58  mov     rbx, r12
0x14000ec5b  mov     rdi, r15
0x14000ec5e  xchg    ax, ax
0x14000ec60  cmp     rsi, rbx
0x14000ec63  jbe     short loc_14000EC88
0x14000ec65  add     rbx, rbp
0x14000ec68  cmp     rbx, rsi
0x14000ec6b  jnb     short loc_14000EC88
0x14000ec6d  mov     rcx, r14
0x14000ec70  call    cs:__guard_check_icall_fptr
0x14000ec76  mov     rdx, rsi
0x14000ec79  mov     rcx, rbx
0x14000ec7c  call    r14
0x14000ec7f  test    eax, eax
0x14000ec81  jle     short loc_14000EC65
0x14000ec83  cmp     rsi, rbx
0x14000ec86  ja      short loc_14000ECA6
0x14000ec88  add     rbx, rbp
0x14000ec8b  cmp     rbx, r15
0x14000ec8e  ja      short loc_14000ECA6
0x14000ec90  mov     rcx, r14
0x14000ec93  call    cs:__guard_check_icall_fptr
0x14000ec99  mov     rdx, rsi
0x14000ec9c  mov     rcx, rbx
0x14000ec9f  call    r14
0x14000eca2  test    eax, eax
0x14000eca4  jle     short loc_14000EC88
0x14000eca6  sub     rdi, rbp
0x14000eca9  cmp     rdi, rsi
0x14000ecac  jbe     short loc_14000ECC4
0x14000ecae  mov     rcx, r14
0x14000ecb1  call    cs:__guard_check_icall_fptr
0x14000ecb7  mov     rdx, rsi
0x14000ecba  mov     rcx, rdi
0x14000ecbd  call    r14
0x14000ecc0  test    eax, eax
0x14000ecc2  jg      short loc_14000ECA6
0x14000ecc4  cmp     rdi, rbx
0x14000ecc7  jb      short loc_14000ED09
0x14000ecc9  mov     r8, rbp
0x14000eccc  mov     rdx, rdi
0x14000eccf  cmp     rbx, rdi
0x14000ecd2  jz      short loc_14000ECF8
0x14000ecd4  mov     r9, rbx
0x14000ecd7  sub     r9, rdi
0x14000ecda  nop     word ptr [rax+rax+00h]
0x14000ece0  movzx   eax, byte ptr [rdx]
0x14000ece3  movzx   ecx, byte ptr [r9+rdx]
0x14000ece8  mov     [r9+rdx], al
0x14000ecec  mov     [rdx], cl
0x14000ecee  lea     rdx, [rdx+1]
0x14000ecf2  sub     r8, 1
0x14000ecf6  jnz     short loc_14000ECE0
0x14000ecf8  cmp     rsi, rdi
0x14000ecfb  jnz     loc_14000EC60
0x14000ed01  mov     rsi, rbx
0x14000ed04  jmp     loc_14000EC60
0x14000ed09  add     rdi, rbp
0x14000ed0c  cmp     rsi, rdi
0x14000ed0f  jnb     short loc_14000ED34
0x14000ed11  sub     rdi, rbp
0x14000ed14  cmp     rdi, rsi
0x14000ed17  jbe     short loc_14000ED34
0x14000ed19  mov     rcx, r14
0x14000ed1c  call    cs:__guard_check_icall_fptr
0x14000ed22  mov     rdx, rsi
0x14000ed25  mov     rcx, rdi
0x14000ed28  call    r14
0x14000ed2b  test    eax, eax
0x14000ed2d  jz      short loc_14000ED11
0x14000ed2f  cmp     rsi, rdi
0x14000ed32  jb      short loc_14000ED52
0x14000ed34  sub     rdi, rbp
0x14000ed37  cmp     rdi, r12
0x14000ed3a  jbe     short loc_14000ED52
0x14000ed3c  mov     rcx, r14
0x14000ed3f  call    cs:__guard_check_icall_fptr
0x14000ed45  mov     rdx, rsi
0x14000ed48  mov     rcx, rdi
0x14000ed4b  call    r14
0x14000ed4e  test    eax, eax
0x14000ed50  jz      short loc_14000ED34
0x14000ed52  mov     rcx, r15
0x14000ed55  mov     rax, rdi
0x14000ed58  sub     rcx, rbx
0x14000ed5b  sub     rax, r12
0x14000ed5e  cmp     rax, rcx
0x14000ed61  jl      short loc_14000ED89
0x14000ed63  cmp     r12, rdi
0x14000ed66  jnb     short loc_14000ED78
0x14000ed68  mov     [rsp+r13*8+458h+var_438], r12
0x14000ed6d  mov     [rsp+r13*8+458h+var_248], rdi
0x14000ed75  inc     r13
0x14000ed78  cmp     rbx, r15
0x14000ed7b  jnb     loc_14000EB77
0x14000ed81  mov     r12, rbx
0x14000ed84  jmp     $recurse$173
0x14000ed89  cmp     rbx, r15
0x14000ed8c  jnb     short loc_14000ED9E
0x14000ed8e  mov     [rsp+r13*8+458h+var_438], rbx
0x14000ed93  mov     [rsp+r13*8+458h+var_248], r15
0x14000ed9b  inc     r13
0x14000ed9e  cmp     r12, rdi
0x14000eda1  jnb     loc_14000EB77
0x14000eda7  mov     r15, rdi
0x14000edaa  jmp     $recurse$173
0x14000edaf  mov     r13, [rsp+458h+var_38]
0x14000edb7  mov     rdi, [rsp+458h+var_30]
0x14000edbf  mov     rsi, [rsp+458h+var_28]
0x14000edc7  mov     rbx, [rsp+458h+var_20]
0x14000edcf  mov     r15, [rsp+458h+var_40]
0x14000edd7  mov     rcx, [rsp+458h+var_58]
0x14000eddf  xor     rcx, rsp; StackCookie
0x14000ede2  call    __security_check_cookie
0x14000ede7  add     rsp, 440h
0x14000edee  pop     r14
0x14000edf0  pop     r12
0x14000edf2  pop     rbp
0x14000edf3  retn

// ===== ?initialize_multibyte@@YAHXZ @ 0x14000edf4 =====

0x14000edf4  sub     rsp, 28h
0x14000edf8  call    __acrt_initialize_multibyte
0x14000edfd  xor     ecx, ecx
0x14000edff  test    al, al
0x14000ee01  setz    cl
0x14000ee04  mov     eax, ecx
0x14000ee06  add     rsp, 28h
0x14000ee0a  retn

// ===== _msize @ 0x14000ee0c =====

0x14000ee0c  sub     rsp, 28h
0x14000ee10  test    rcx, rcx
0x14000ee13  jnz     short loc_14000EE2E
0x14000ee15  call    _errno
0x14000ee1a  mov     dword ptr [rax], 16h
0x14000ee20  call    _invalid_parameter_noinfo
0x14000ee25  or      rax, 0FFFFFFFFFFFFFFFFh
0x14000ee29  add     rsp, 28h
0x14000ee2d  retn
0x14000ee2e  mov     r8, rcx
0x14000ee31  xor     edx, edx
0x14000ee33  mov     rcx, cs:hHeap
0x14000ee3a  add     rsp, 28h
0x14000ee3e  jmp     cs:HeapSize; KERNEL32

// ===== _realloc_base @ 0x14000ee48 =====

0x14000ee48  mov     [rsp+arg_0], rbx
0x14000ee4d  push    rdi
0x14000ee4e  sub     rsp, 20h
0x14000ee52  mov     rbx, rdx
0x14000ee55  mov     rdi, rcx
0x14000ee58  test    rcx, rcx
0x14000ee5b  jnz     short loc_14000EE67
0x14000ee5d  mov     rcx, rdx; Size
0x14000ee60  call    _malloc_base
0x14000ee65  jmp     short loc_14000EEBF
0x14000ee67  test    rdx, rdx
0x14000ee6a  jnz     short loc_14000EE73
0x14000ee6c  call    _free_base
0x14000ee71  jmp     short loc_14000EEBD
0x14000ee73  cmp     rdx, 0FFFFFFFFFFFFFFE0h
0x14000ee77  ja      short loc_14000EEB2
0x14000ee79  mov     r9, rdx
0x14000ee7c  mov     r8, rcx
0x14000ee7f  jmp     short loc_14000EE9C
0x14000ee81  call    sub_140006248
0x14000ee86  test    eax, eax
0x14000ee88  jz      short loc_14000EEB2
0x14000ee8a  mov     rcx, rbx; Size
0x14000ee8d  call    _callnewh
0x14000ee92  test    eax, eax
0x14000ee94  jz      short loc_14000EEB2
0x14000ee96  mov     r9, rbx; dwBytes
0x14000ee99  mov     r8, rdi; lpMem
0x14000ee9c  mov     rcx, cs:hHeap; hHeap
0x14000eea3  xor     edx, edx; dwFlags
0x14000eea5  call    cs:HeapReAlloc; KERNEL32
0x14000eeab  test    rax, rax
0x14000eeae  jz      short loc_14000EE81
0x14000eeb0  jmp     short loc_14000EEBF
0x14000eeb2  call    _errno
0x14000eeb7  mov     dword ptr [rax], 0Ch
0x14000eebd  xor     eax, eax
0x14000eebf  mov     rbx, [rsp+28h+arg_0]
0x14000eec4  add     rsp, 20h
0x14000eec8  pop     rdi
0x14000eec9  retn

// ===== __strncnt @ 0x14000eecc =====

0x14000eecc  xor     eax, eax
0x14000eece  cmp     [rcx], al
0x14000eed0  jz      short locret_14000EEE0
0x14000eed2  cmp     rax, rdx
0x14000eed5  jz      short locret_14000EEE0
0x14000eed7  inc     rax
0x14000eeda  cmp     byte ptr [rax+rcx], 0
0x14000eede  jnz     short loc_14000EED2
0x14000eee0  retn

// ===== fegetenv @ 0x14000eee4 =====

0x14000eee4  push    rbx
0x14000eee6  sub     rsp, 20h
0x14000eeea  mov     rbx, rcx
0x14000eeed  call    _getfpcontrolword
0x14000eef2  mov     [rbx], eax
0x14000eef4  call    _getfpstatusword
0x14000eef9  mov     [rbx+4], eax
0x14000eefc  xor     eax, eax
0x14000eefe  add     rsp, 20h
0x14000ef02  pop     rbx
0x14000ef03  retn

// ===== fesetenv @ 0x14000ef04 =====

0x14000ef04  push    rbx
0x14000ef06  sub     rsp, 20h
0x14000ef0a  and     [rsp+28h+Env._Fe_ctl], 0
0x14000ef0f  mov     rbx, rcx
0x14000ef12  mov     ecx, [rcx]
0x14000ef14  and     [rsp+28h+Env._Fe_stat], 0
0x14000ef19  call    _setfpcontrolword
0x14000ef1e  mov     ecx, [rbx+4]
0x14000ef21  call    _setfpstatusword
0x14000ef26  lea     rcx, [rsp+28h+Env]; Env
0x14000ef2b  call    fegetenv
0x14000ef30  mov     eax, [rsp+28h+Env._Fe_ctl]
0x14000ef34  cmp     [rbx], eax
0x14000ef36  jnz     short loc_14000EF45
0x14000ef38  mov     eax, [rsp+28h+Env._Fe_stat]
0x14000ef3c  cmp     [rbx+4], eax
0x14000ef3f  jnz     short loc_14000EF45
0x14000ef41  xor     eax, eax
0x14000ef43  jmp     short loc_14000EF4A
0x14000ef45  mov     eax, 1
0x14000ef4a  add     rsp, 20h
0x14000ef4e  pop     rbx
0x14000ef4f  retn

// ===== feholdexcept @ 0x14000ef50 =====

0x14000ef50  push    rbx
0x14000ef52  sub     rsp, 20h
0x14000ef56  and     [rsp+28h+Env._Fe_ctl], 0
0x14000ef5b  mov     rbx, rcx
0x14000ef5e  and     [rsp+28h+Env._Fe_stat], 0
0x14000ef63  lea     rcx, [rsp+28h+Env]; Env
0x14000ef68  call    fegetenv
0x14000ef6d  test    eax, eax
0x14000ef6f  jz      short loc_14000EF78
0x14000ef71  mov     eax, 1
0x14000ef76  jmp     short loc_14000EF9A
0x14000ef78  mov     rax, qword ptr [rsp+28h+Env._Fe_ctl]
0x14000ef7d  lea     rcx, [rsp+28h+Env]; Env
0x14000ef82  or      [rsp+28h+Env._Fe_ctl], 1Fh
0x14000ef87  mov     [rbx], rax
0x14000ef8a  call    fesetenv
0x14000ef8f  test    eax, eax
0x14000ef91  jnz     short loc_14000EF71
0x14000ef93  call    _clearfp
0x14000ef98  xor     eax, eax
0x14000ef9a  add     rsp, 20h
0x14000ef9e  pop     rbx
0x14000ef9f  retn

// ===== ceil @ 0x14000efa0 =====

0x14000efa0  xor     r8d, r8d
0x14000efa3  movsd   [rsp+arg_0], xmm0
0x14000efa9  mov     rdx, [rsp+arg_0]
0x14000efae  mov     rcx, 7FFFFFFFFFFFFFFFh
0x14000efb8  mov     rax, rdx
0x14000efbb  and     rax, rcx
0x14000efbe  mov     rcx, 4340000000000000h
0x14000efc8  cmp     rdx, rax
0x14000efcb  setnz   r8b
0x14000efcf  cmp     rax, rcx
0x14000efd2  jb      short loc_14000EFEB
0x14000efd4  mov     rcx, 7FF0000000000000h
0x14000efde  cmp     rax, rcx
0x14000efe1  jbe     short locret_14000F061
0x14000efe3  mov     rcx, rdx
0x14000efe6  jmp     _handle_nan
0x14000efeb  mov     rcx, 3FF0000000000000h
0x14000eff5  cmp     rax, rcx
0x14000eff8  jnb     short loc_14000F025
0x14000effa  test    rax, rax
0x14000effd  jz      short locret_14000F061
0x14000efff  test    r8, r8
0x14000f002  jz      short loc_14000F01B
0x14000f004  mov     rax, 8000000000000000h
0x14000f00e  mov     [rsp+arg_0], rax
0x14000f013  movsd   xmm0, [rsp+arg_0]
0x14000f019  jmp     short locret_14000F061
0x14000f01b  movsd   xmm0, cs:qword_1400175E8
0x14000f023  jmp     short locret_14000F061
0x14000f025  mov     rax, rdx
0x14000f028  mov     ecx, 33h ; '3'
0x14000f02d  shr     rax, 34h
0x14000f031  sub     cl, al
0x14000f033  mov     eax, 1
0x14000f038  shl     rax, cl
0x14000f03b  dec     rax
0x14000f03e  not     rax
0x14000f041  and     rax, rdx
0x14000f044  mov     [rsp+arg_0], rax
0x14000f049  movsd   xmm0, [rsp+arg_0]
0x14000f04f  test    r8, r8
0x14000f052  jnz     short locret_14000F061
0x14000f054  cmp     rax, rdx
0x14000f057  jz      short locret_14000F061
0x14000f059  addsd   xmm0, cs:qword_1400175E8
0x14000f061  retn
0x14000ff48  mov     rax, 8000000000000h
0x14000ff52  or      rcx, rax
0x14000ff55  mov     [rsp+arg_0], rcx
0x14000ff5a  movsd   xmm0, [rsp+arg_0]
0x14000ff60  retn

// ===== log10 @ 0x14000f070 =====

0x14000f070  sub     rsp, 58h
0x14000f074  movdqa  [rsp+58h+var_38], xmm6
0x14000f07a  cmp     cs:dword_14001DBAC, 0
0x14000f081  jnz     Llog10_fma3
0x14000f087  movapd  xmm3, xmm0
0x14000f08b  movapd  xmm4, xmm0
0x14000f08f  psrlq   xmm3, 34h ; '4'
0x14000f094  movq    rax, xmm0
0x14000f099  psubq   xmm3, cs:xmmword_140017630
0x14000f0a1  movapd  xmm5, xmm0
0x14000f0a5  andpd   xmm5, cs:xmmword_140017600
0x14000f0ad  comisd  xmm5, qword ptr cs:xmmword_140017600
0x14000f0b5  jz      Llog10_sse2_x_is_inf_or_nan
0x14000f0bb  movapd  xmm2, xmm0
0x14000f0bf  cvtdq2pd xmm6, xmm3
0x14000f0c3  xorpd   xmm5, xmm5
0x14000f0c7  comisd  xmm0, xmm5
0x14000f0cb  jbe     Llog10_sse2_x_is_zero_or_neg
0x14000f0d1  pand    xmm2, cs:xmmword_140017650
0x14000f0d9  subsd   xmm4, qword ptr cs:xmmword_1400176E0
0x14000f0e1  comisd  xmm6, cs:qword_140017770
0x14000f0e9  jz      Llog10_sse2_denormal_adjust
0x14000f0ef  andpd   xmm4, cs:xmmword_1400177D0
0x14000f0f7  mov     r9, rax
0x14000f0fa  and     rax, qword ptr cs:xmmword_140017660
0x14000f101  and     r9, qword ptr cs:xmmword_140017670
0x14000f108  shl     r9, 1
0x14000f10b  add     rax, r9
0x14000f10e  movq    xmm1, rax
0x14000f113  comisd  xmm4, cs:qword_140017790
0x14000f11b  jb      Llog10_sse2_near_one
0x14000f121  shr     rax, 2Ch
0x14000f125  por     xmm2, cs:xmmword_1400176F0
0x14000f12d  por     xmm1, cs:xmmword_1400176F0
0x14000f135  lea     r9, dbl_140018860
0x14000f13c  subsd   xmm1, xmm2
0x14000f140  mulsd   xmm1, qword ptr [r9+rax*8]
0x14000f146  movapd  xmm2, xmm1
0x14000f14a  movapd  xmm0, xmm1
0x14000f14e  lea     r9, dbl_140017840
0x14000f155  movsd   xmm3, cs:qword_140017760
0x14000f15d  movsd   xmm1, cs:qword_140017730
0x14000f165  mulsd   xmm3, xmm2
0x14000f169  mulsd   xmm1, xmm2
0x14000f16d  mulsd   xmm0, xmm2
0x14000f171  movapd  xmm4, xmm0
0x14000f175  addsd   xmm3, cs:qword_140017750
0x14000f17d  addsd   xmm1, cs:qword_140017720
0x14000f185  mulsd   xmm4, xmm0
0x14000f189  mulsd   xmm3, xmm2
0x14000f18d  mulsd   xmm1, xmm0
0x14000f191  addsd   xmm3, cs:qword_140017740
0x14000f199  addsd   xmm1, xmm2
0x14000f19d  mulsd   xmm3, xmm4
0x14000f1a1  addsd   xmm1, xmm3
0x14000f1a5  movsd   xmm5, cs:qword_1400176C0
0x14000f1ad  mulsd   xmm1, cs:qword_140017680
0x14000f1b5  mulsd   xmm5, xmm6
0x14000f1b9  subsd   xmm5, xmm1
0x14000f1bd  movsd   xmm0, qword ptr [r9+rax*8]
0x14000f1c3  lea     rdx, dbl_140018050
0x14000f1ca  movsd   xmm2, qword ptr [rdx+rax*8]
0x14000f1cf  movsd   xmm4, cs:qword_1400176B0
0x14000f1d7  mulsd   xmm4, xmm6
0x14000f1db  addsd   xmm0, xmm4
0x14000f1df  addsd   xmm2, xmm5
0x14000f1e3  addsd   xmm0, xmm2
0x14000f1e7  movdqa  xmm6, [rsp+58h+var_38]
0x14000f1ed  add     rsp, 58h
0x14000f1f1  retn
0x14000f200  movsd   xmm2, cs:qword_1400176D0
0x14000f208  subsd   xmm0, qword ptr cs:xmmword_1400176E0
0x14000f210  addsd   xmm2, xmm0
0x14000f214  movapd  xmm1, xmm0
0x14000f218  divsd   xmm1, xmm2
0x14000f21c  movsd   xmm4, cs:qword_1400177F0
0x14000f224  movsd   xmm5, cs:qword_140017810
0x14000f22c  movapd  xmm6, xmm0
0x14000f230  mulsd   xmm6, xmm1
0x14000f234  addsd   xmm1, xmm1
0x14000f238  movapd  xmm2, xmm1
0x14000f23c  mulsd   xmm2, xmm1
0x14000f240  mulsd   xmm4, xmm2
0x14000f244  mulsd   xmm5, xmm2
0x14000f248  addsd   xmm4, cs:qword_1400177E0
0x14000f250  addsd   xmm5, cs:qword_140017800
0x14000f258  mulsd   xmm2, xmm1
0x14000f25c  mulsd   xmm4, xmm2
0x14000f260  mulsd   xmm2, xmm2
0x14000f264  mulsd   xmm2, xmm1
0x14000f268  mulsd   xmm5, xmm2
0x14000f26c  movsd   xmm2, cs:qword_1400176A0
0x14000f274  addsd   xmm4, xmm5
0x14000f278  subsd   xmm4, xmm6
0x14000f27c  movsd   xmm6, cs:qword_140017690
0x14000f284  movapd  xmm3, xmm0
0x14000f288  pand    xmm3, cs:xmmword_140017820
0x14000f290  subsd   xmm0, xmm3
0x14000f294  addsd   xmm4, xmm0
0x14000f298  movapd  xmm0, xmm3
0x14000f29c  movapd  xmm1, xmm4
0x14000f2a0  mulsd   xmm4, xmm2
0x14000f2a4  mulsd   xmm0, xmm2
0x14000f2a8  mulsd   xmm1, xmm6
0x14000f2ac  mulsd   xmm3, xmm6
0x14000f2b0  addsd   xmm0, xmm4
0x14000f2b4  addsd   xmm0, xmm1
0x14000f2b8  addsd   xmm0, xmm3
0x14000f2bc  movdqa  xmm6, [rsp+58h+var_38]
0x14000f2c2  add     rsp, 58h
0x14000f2c6  retn
0x14000f2c7  por     xmm2, cs:xmmword_1400176E0
0x14000f2cf  subsd   xmm2, qword ptr cs:xmmword_1400176E0
0x14000f2d7  movsd   xmm5, xmm2
0x14000f2db  pand    xmm2, cs:xmmword_140017650
0x14000f2e3  movq    rax, xmm2
0x14000f2e8  psrlq   xmm5, 34h ; '4'
0x14000f2ed  psubd   xmm5, cs:xmmword_140017780
0x14000f2f5  cvtdq2pd xmm6, xmm5
0x14000f2f9  jmp     Llog10_sse2_continue_common
0x14000f300  jnz     short Llog10_sse2_x_is_neg
0x14000f302  movsd   xmm1, cs:qword_1400175F0
0x14000f30a  mov     r8d, cs:dword_140017830
0x14000f311  call    _log10_special
0x14000f316  jmp     short Llog10_sse2_finish
0x14000f320  movsd   xmm1, cs:qword_140017610
0x14000f328  mov     r8d, cs:dword_140017834
0x14000f32f  call    _log10_special
0x14000f334  jmp     short Llog10_sse2_finish
0x14000f340  cmp     rax, qword ptr cs:xmmword_140017600
0x14000f347  jz      short Llog10_sse2_finish
0x14000f349  cmp     rax, cs:qword_1400175F0
0x14000f350  jz      short Llog10_sse2_x_is_neg
0x14000f352  or      rax, cs:qword_140017620
0x14000f359  movq    xmm0, rax
0x14000f35e  xchg    ax, ax
0x14000f360  movdqa  xmm6, [rsp+58h+var_38]
0x14000f366  add     rsp, 58h
0x14000f36a  retn
0x14000f370  xor     rax, rax
0x14000f373  vpsrlq  xmm3, xmm0, 34h ; '4'
0x14000f378  vmovq   rax, xmm0
0x14000f37d  vpsubq  xmm3, xmm3, cs:xmmword_140017630
0x14000f385  vcvtdq2pd xmm6, xmm3
0x14000f389  vpand   xmm5, xmm0, cs:xmmword_140017600
0x14000f391  vcomisd xmm5, qword ptr cs:xmmword_140017600
0x14000f399  jz      Llog10_fma3_x_is_inf_or_nan
0x14000f39f  vpxor   xmm5, xmm5, xmm5
0x14000f3a3  vcomisd xmm0, xmm5
0x14000f3a7  jbe     Llog10_fma3_x_is_zero_or_neg
0x14000f3ad  vpand   xmm2, xmm0, cs:xmmword_140017650
0x14000f3b5  vsubsd  xmm4, xmm0, qword ptr cs:xmmword_1400176E0
0x14000f3bd  vcomisd xmm6, cs:qword_140017770
0x14000f3c5  jz      Llog10_fma3_denormal_adjust
0x14000f3cb  vpand   xmm1, xmm0, cs:xmmword_140017660
0x14000f3d3  vpand   xmm3, xmm0, cs:xmmword_140017670
0x14000f3db  vpsllq  xmm3, xmm3, 1
0x14000f3e0  vpaddq  xmm1, xmm3, xmm1
0x14000f3e4  vmovq   rax, xmm1
0x14000f3e9  vpand   xmm4, xmm4, cs:xmmword_1400177D0
0x14000f3f1  vcomisd xmm4, cs:qword_140017790
0x14000f3f9  jb      Llog10_fma3_near_one
0x14000f3ff  shr     rax, 2Ch
0x14000f403  vpor    xmm2, xmm2, cs:xmmword_1400176F0
0x14000f40b  vpor    xmm1, xmm1, cs:xmmword_1400176F0
0x14000f413  lea     r9, dbl_140018860
0x14000f41a  vsubsd  xmm1, xmm1, xmm2
0x14000f41e  vmulsd  xmm1, xmm1, qword ptr [r9+rax*8]
0x14000f424  lea     r9, dbl_140017840
0x14000f42b  vmulsd  xmm0, xmm1, xmm1
0x14000f42f  vmovsd  xmm3, cs:qword_140017760
0x14000f437  vmovsd  xmm5, cs:qword_140017730
0x14000f43f  vfmadd213sd xmm3, xmm1, cs:qword_140017750
0x14000f448  vfmadd213sd xmm5, xmm1, qword ptr cs:xmmword_1400176F0
0x14000f451  movsd   xmm4, xmm0
0x14000f455  vfmadd213sd xmm3, xmm1, cs:qword_140017740
0x14000f45e  vmulsd  xmm4, xmm0, xmm0
0x14000f462  vfmadd231sd xmm1, xmm5, xmm0
0x14000f467  vfmadd231sd xmm1, xmm3, xmm4
0x14000f46c  vmulsd  xmm1, xmm1, cs:qword_140017680
0x14000f474  vmovsd  xmm5, cs:qword_1400176C0
0x14000f47c  vfmsub213sd xmm5, xmm6, xmm1
0x14000f481  movsd   xmm0, qword ptr [r9+rax*8]
0x14000f487  lea     rdx, dbl_140018050
0x14000f48e  movsd   xmm2, qword ptr [rdx+rax*8]
0x14000f493  vaddsd  xmm2, xmm2, xmm5
0x14000f497  vfmadd231sd xmm0, xmm6, cs:qword_1400176B0
0x14000f4a0  vaddsd  xmm0, xmm0, xmm2
0x14000f4a4  vmovdqa xmm6, [rsp+58h+var_38]
0x14000f4aa  add     rsp, 58h
0x14000f4ae  retn
0x14000f4b0  vmovsd  xmm2, cs:qword_1400176D0
0x14000f4b8  vsubsd  xmm0, xmm0, qword ptr cs:xmmword_1400176E0
0x14000f4c0  vaddsd  xmm2, xmm2, xmm0
0x14000f4c4  vdivsd  xmm1, xmm0, xmm2
0x14000f4c8  vmovsd  xmm4, cs:qword_1400177F0
0x14000f4d0  vmovsd  xmm5, cs:qword_140017810
0x14000f4d8  vmulsd  xmm6, xmm0, xmm1
0x14000f4dc  vaddsd  xmm1, xmm1, xmm1
0x14000f4e0  vmulsd  xmm2, xmm1, xmm1
0x14000f4e4  vfmadd213sd xmm4, xmm2, cs:qword_1400177E0
0x14000f4ed  vfmadd213sd xmm5, xmm2, cs:qword_140017800
0x14000f4f6  vmulsd  xmm2, xmm2, xmm1
0x14000f4fa  vmulsd  xmm4, xmm4, xmm2
0x14000f4fe  vmulsd  xmm2, xmm2, xmm2
0x14000f502  vmulsd  xmm2, xmm2, xmm1
0x14000f506  vmulsd  xmm5, xmm5, xmm2
0x14000f50a  vaddsd  xmm4, xmm4, xmm5
0x14000f50e  vsubsd  xmm4, xmm4, xmm6
0x14000f512  vpand   xmm3, xmm0, cs:xmmword_140017820
0x14000f51a  vsubsd  xmm0, xmm0, xmm3
0x14000f51e  vaddsd  xmm4, xmm4, xmm0
0x14000f522  vmulsd  xmm1, xmm4, cs:qword_140017690
0x14000f52a  vmulsd  xmm4, xmm4, cs:qword_1400176A0
0x14000f532  vmulsd  xmm0, xmm3, cs:qword_1400176A0
0x14000f53a  vmulsd  xmm3, xmm3, cs:qword_140017690
0x14000f542  vaddsd  xmm0, xmm0, xmm4
0x14000f546  vaddsd  xmm0, xmm0, xmm1
0x14000f54a  vaddsd  xmm0, xmm0, xmm3
0x14000f54e  vmovdqa xmm6, [rsp+58h+var_38]
0x14000f554  add     rsp, 58h
0x14000f558  retn
0x14000f559  vpor    xmm2, xmm2, cs:xmmword_1400176E0
0x14000f561  vsubsd  xmm2, xmm2, qword ptr cs:xmmword_1400176E0
0x14000f569  vpsrlq  xmm5, xmm2, 34h ; '4'
0x14000f56e  vpand   xmm2, xmm2, cs:xmmword_140017650
0x14000f576  vmovapd xmm0, xmm2
0x14000f57a  vpsubd  xmm5, xmm5, cs:xmmword_140017780
0x14000f582  vcvtdq2pd xmm6, xmm5
0x14000f586  jmp     Llog10_fma3_continue_common
0x14000f590  jnz     short Llog10_fma3_x_is_neg
0x14000f592  vmovsd  xmm1, cs:qword_1400175F0
0x14000f59a  mov     r8d, cs:dword_140017830
0x14000f5a1  call    _log10_special
0x14000f5a6  vmovdqa xmm6, [rsp+58h+var_38]
0x14000f5ac  add     rsp, 58h
0x14000f5b0  retn
0x14000f5c0  vmovsd  xmm1, cs:qword_140017610
0x14000f5c8  mov     r8d, cs:dword_140017834
0x14000f5cf  call    _log10_special
0x14000f5d4  vmovdqa xmm6, [rsp+58h+var_38]
0x14000f5da  add     rsp, 58h
0x14000f5de  retn
0x14000f5e0  cmp     rax, qword ptr cs:xmmword_140017600
0x14000f5e7  jz      short Llog10_fma3_finish
0x14000f5e9  cmp     rax, cs:qword_1400175F0
0x14000f5f0  jz      short Llog10_fma3_x_is_neg
0x14000f5f2  or      rax, cs:qword_140017620
0x14000f5f9  movq    xmm1, rax
0x14000f5fe  mov     r8d, cs:dword_140017838
0x14000f605  call    _log10_special
0x14000f60a  jmp     short Llog10_fma3_finish
0x14000f610  vmovdqa xmm6, [rsp+58h+var_38]
0x14000f616  add     rsp, 58h
0x14000f61a  retn

// ===== ??$common_lseek_nolock@_J@@YA_JH_JH@Z @ 0x14000f61c =====

0x14000f61c  mov     [rsp+arg_0], rbx
0x14000f621  mov     [rsp+arg_8], rsi
0x14000f626  push    rdi
0x14000f627  sub     rsp, 20h
0x14000f62b  movsxd  rbx, ecx
0x14000f62e  mov     edi, r8d
0x14000f631  mov     ecx, ebx; FileHandle
0x14000f633  mov     rsi, rdx
0x14000f636  call    _get_osfhandle
0x14000f63b  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x14000f63f  jnz     short loc_14000F652
0x14000f641  call    _errno
0x14000f646  mov     dword ptr [rax], 9
0x14000f64c  or      rax, 0FFFFFFFFFFFFFFFFh
0x14000f650  jmp     short loc_14000F6A5
0x14000f652  mov     r9d, edi; dwMoveMethod
0x14000f655  lea     r8, [rsp+28h+NewFilePointer]; lpNewFilePointer
0x14000f65a  mov     rdx, rsi; liDistanceToMove
0x14000f65d  mov     rcx, rax; hFile
0x14000f660  call    cs:SetFilePointerEx; KERNEL32
0x14000f666  test    eax, eax
0x14000f668  jnz     short loc_14000F679
0x14000f66a  call    cs:GetLastError; KERNEL32
0x14000f670  mov     ecx, eax
0x14000f672  call    __acrt_errno_map_os_error
0x14000f677  jmp     short loc_14000F64C
0x14000f679  mov     rax, qword ptr [rsp+28h+NewFilePointer]
0x14000f67e  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x14000f682  jz      short loc_14000F64C
0x14000f684  mov     rdx, rbx
0x14000f687  lea     r8, qword_14001D350
0x14000f68e  and     edx, 3Fh
0x14000f691  mov     rcx, rbx
0x14000f694  sar     rcx, 6
0x14000f698  shl     rdx, 6
0x14000f69c  mov     rcx, [r8+rcx*8]
0x14000f6a0  and     byte ptr [rcx+rdx+38h], 0FDh
0x14000f6a5  mov     rbx, [rsp+28h+arg_0]
0x14000f6aa  mov     rsi, [rsp+28h+arg_8]
0x14000f6af  add     rsp, 20h
0x14000f6b3  pop     rdi
0x14000f6b4  retn

// ===== j_??$common_lseek_nolock@_J@@YA_JH_JH@Z @ 0x14000f6b8 =====

0x14000f6b8  jmp     ??$common_lseek_nolock@_J@@YA_JH_JH@Z

// ===== ??$?RV_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_@@AEAV_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_@@V_lambda_237c231691f317818eb88cc1d5d642d6_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_@@AEAV_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_@@$$QEAV_lambda_237c231691f317818eb88cc1d5d642d6_@@@Z @ 0x14000f6c0 =====

0x14000f6c0  mov     [rsp+arg_0], rbx
0x14000f6c5  mov     [rsp+arg_18], r9
0x14000f6ca  push    rdi
0x14000f6cb  sub     rsp, 20h
0x14000f6cf  mov     rdi, r9
0x14000f6d2  mov     rbx, r8
0x14000f6d5  mov     ecx, [rdx]
0x14000f6d7  call    sub_14000AD6C
0x14000f6dc  nop
0x14000f6dd  mov     rax, [rbx]
0x14000f6e0  movsxd  rcx, dword ptr [rax]
0x14000f6e3  mov     rdx, rcx
0x14000f6e6  mov     rax, rcx
0x14000f6e9  sar     rax, 6
0x14000f6ed  lea     r8, qword_14001D350
0x14000f6f4  and     edx, 3Fh
0x14000f6f7  shl     rdx, 6
0x14000f6fb  mov     rax, [r8+rax*8]
0x14000f6ff  test    byte ptr [rax+rdx+38h], 1
0x14000f704  jz      short loc_14000F70F
0x14000f706  call    _close_nolock
0x14000f70b  mov     ebx, eax
0x14000f70d  jmp     short loc_14000F71D
0x14000f70f  call    _errno
0x14000f714  mov     dword ptr [rax], 9
0x14000f71a  or      ebx, 0FFFFFFFFh
0x14000f71d  mov     ecx, [rdi]
0x14000f71f  call    sub_14000AD90
0x14000f724  mov     eax, ebx
0x14000f726  mov     rbx, [rsp+28h+arg_0]
0x14000f72b  add     rsp, 20h
0x14000f72f  pop     rdi
0x14000f730  retn
0x140010b42  push    rbp
0x140010b44  sub     rsp, 20h
0x140010b48  mov     rbp, rdx
0x140010b4b  mov     rax, [rbp+48h]
0x140010b4f  mov     ecx, [rax]
0x140010b51  add     rsp, 20h
0x140010b55  pop     rbp
0x140010b56  jmp     sub_14000AD90

// ===== sub_14000F734 @ 0x14000f734 =====

0x14000f734  mov     [rsp+arg_0], ecx
0x14000f738  sub     rsp, 38h
0x14000f73c  movsxd  rdx, ecx
0x14000f73f  cmp     edx, 0FFFFFFFEh
0x14000f742  jnz     short loc_14000F759
0x14000f744  call    __doserrno
0x14000f749  and     dword ptr [rax], 0
0x14000f74c  call    _errno
0x14000f751  mov     dword ptr [rax], 9
0x14000f757  jmp     short loc_14000F7CD
0x14000f759  test    ecx, ecx
0x14000f75b  js      short loc_14000F7B5
0x14000f75d  cmp     edx, cs:dword_14001D750
0x14000f763  jnb     short loc_14000F7B5
0x14000f765  mov     rcx, rdx
0x14000f768  lea     r8, qword_14001D350
0x14000f76f  and     ecx, 3Fh
0x14000f772  mov     rax, rdx
0x14000f775  sar     rax, 6
0x14000f779  shl     rcx, 6
0x14000f77d  mov     rax, [r8+rax*8]
0x14000f781  test    byte ptr [rax+rcx+38h], 1
0x14000f786  jz      short loc_14000F7B5
0x14000f788  lea     rax, [rsp+38h+arg_0]
0x14000f78d  mov     [rsp+38h+arg_10], edx
0x14000f791  mov     [rsp+38h+arg_18], edx
0x14000f795  lea     r9, [rsp+38h+arg_10]
0x14000f79a  lea     rdx, [rsp+38h+arg_18]
0x14000f79f  mov     [rsp+38h+var_18], rax
0x14000f7a4  lea     r8, [rsp+38h+var_18]
0x14000f7a9  lea     rcx, [rsp+38h+arg_8]
0x14000f7ae  call    ??$?RV_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_@@AEAV_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_@@V_lambda_237c231691f317818eb88cc1d5d642d6_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_@@AEAV_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_@@$$QEAV_lambda_237c231691f317818eb88cc1d5d642d6_@@@Z; __crt_seh_guarded_call<int>::operator()<_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_,_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_ &,_lambda_237c231691f317818eb88cc1d5d642d6_>(_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_ &&,_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_ &,_lambda_237c231691f317818eb88cc1d5d642d6_ &&)
0x14000f7b3  jmp     short loc_14000F7D0
0x14000f7b5  call    __doserrno
0x14000f7ba  and     dword ptr [rax], 0
0x14000f7bd  call    _errno
0x14000f7c2  mov     dword ptr [rax], 9
0x14000f7c8  call    _invalid_parameter_noinfo
0x14000f7cd  or      eax, 0FFFFFFFFh
0x14000f7d0  add     rsp, 38h
0x14000f7d4  retn

// ===== _close_nolock @ 0x14000f7d8 =====

0x14000f7d8  mov     [rsp+arg_0], rbx
0x14000f7dd  push    rdi
0x14000f7de  sub     rsp, 20h
0x14000f7e2  movsxd  rdi, ecx
0x14000f7e5  mov     ecx, edi; FileHandle
0x14000f7e7  call    _get_osfhandle
0x14000f7ec  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x14000f7f0  jnz     short loc_14000F7F6
0x14000f7f2  xor     ebx, ebx
0x14000f7f4  jmp     short loc_14000F84D
0x14000f7f6  mov     rax, cs:qword_14001D350
0x14000f7fd  mov     ecx, 2; FileHandle
0x14000f802  cmp     edi, 1
0x14000f805  jnz     short loc_14000F810
0x14000f807  test    [rax+0B8h], dil
0x14000f80e  jnz     short loc_14000F81A
0x14000f810  cmp     edi, ecx
0x14000f812  jnz     short loc_14000F831
0x14000f814  test    byte ptr [rax+78h], 1
0x14000f818  jz      short loc_14000F831
0x14000f81a  call    _get_osfhandle
0x14000f81f  mov     ecx, 1; FileHandle
0x14000f824  mov     rbx, rax
0x14000f827  call    _get_osfhandle
0x14000f82c  cmp     rax, rbx
0x14000f82f  jz      short loc_14000F7F2
0x14000f831  mov     ecx, edi; FileHandle
0x14000f833  call    _get_osfhandle
0x14000f838  mov     rcx, rax; hObject
0x14000f83b  call    cs:CloseHandle; KERNEL32
0x14000f841  test    eax, eax
0x14000f843  jnz     short loc_14000F7F2
0x14000f845  call    cs:GetLastError; KERNEL32
0x14000f84b  mov     ebx, eax
0x14000f84d  mov     ecx, edi
0x14000f84f  call    _free_osfhnd
0x14000f854  mov     rdx, rdi
0x14000f857  lea     r8, qword_14001D350
0x14000f85e  and     edx, 3Fh
0x14000f861  mov     rcx, rdi
0x14000f864  sar     rcx, 6
0x14000f868  shl     rdx, 6
0x14000f86c  mov     rcx, [r8+rcx*8]
0x14000f870  mov     byte ptr [rcx+rdx+38h], 0
0x14000f875  test    ebx, ebx
0x14000f877  jz      short loc_14000F885
0x14000f879  mov     ecx, ebx
0x14000f87b  call    __acrt_errno_map_os_error
0x14000f880  or      eax, 0FFFFFFFFh
0x14000f883  jmp     short loc_14000F887
0x14000f885  xor     eax, eax
0x14000f887  mov     rbx, [rsp+28h+arg_0]
0x14000f88c  add     rsp, 20h
0x14000f890  pop     rdi
0x14000f891  retn

// ===== ?__acrt_stdio_free_stream@@YAXV__crt_stdio_stream@@@Z @ 0x14000f894 =====

0x14000f894  mov     [rsp+arg_0], rcx
0x14000f899  mov     r11, rsp
0x14000f89c  xor     edx, edx
0x14000f89e  mov     [rcx], rdx
0x14000f8a1  mov     rax, [r11+8]
0x14000f8a5  mov     [rax+8], rdx
0x14000f8a9  mov     rax, [r11+8]
0x14000f8ad  mov     [rax+10h], edx
0x14000f8b0  mov     rax, [r11+8]
0x14000f8b4  or      dword ptr [rax+18h], 0FFFFFFFFh
0x14000f8b8  mov     rax, [r11+8]
0x14000f8bc  mov     [rax+1Ch], edx
0x14000f8bf  mov     rax, [r11+8]
0x14000f8c3  mov     [rax+20h], edx
0x14000f8c6  mov     rax, [r11+8]
0x14000f8ca  mov     [rax+28h], rdx
0x14000f8ce  mov     rax, [r11+8]
0x14000f8d2  xchg    edx, [rax+14h]
0x14000f8d5  retn

// ===== _putwch_nolock @ 0x14000f8d8 =====

0x14000f8d8  mov     [rsp+Buffer], cx
0x14000f8dd  sub     rsp, 38h
0x14000f8e1  mov     rcx, cs:hConsoleOutput
0x14000f8e8  cmp     rcx, 0FFFFFFFFFFFFFFFEh
0x14000f8ec  jnz     short loc_14000F8FA
0x14000f8ee  call    sub_140010098
0x14000f8f3  mov     rcx, cs:hConsoleOutput; hConsoleOutput
0x14000f8fa  cmp     rcx, 0FFFFFFFFFFFFFFFFh
0x14000f8fe  jnz     short loc_14000F907
0x14000f900  mov     eax, 0FFFFh
0x14000f905  jmp     short loc_14000F92C
0x14000f907  and     [rsp+38h+var_18], 0
0x14000f90d  lea     r9, [rsp+38h+NumberOfCharsWritten]; lpNumberOfCharsWritten
0x14000f912  mov     r8d, 1; nNumberOfCharsToWrite
0x14000f918  lea     rdx, [rsp+38h+Buffer]; lpBuffer
0x14000f91d  call    cs:WriteConsoleW; KERNEL32
0x14000f923  test    eax, eax
0x14000f925  jz      short loc_14000F900
0x14000f927  movzx   eax, [rsp+38h+Buffer]
0x14000f92c  add     rsp, 38h
0x14000f930  retn

// ===== _getfpcontrolword @ 0x14000f934 =====

0x14000f934  sub     rsp, 28h
0x14000f938  xor     edx, edx; Mask
0x14000f93a  xor     ecx, ecx; NewValue
0x14000f93c  call    _controlfp
0x14000f941  and     eax, 31Fh
0x14000f946  add     rsp, 28h
0x14000f94a  retn

// ===== _getfpstatusword @ 0x14000f94c =====

0x14000f94c  sub     rsp, 28h
0x14000f950  call    _statusfp
0x14000f955  and     eax, 1Fh
0x14000f958  add     rsp, 28h
0x14000f95c  retn

// ===== _setfpcontrolword @ 0x14000f960 =====

0x14000f960  mov     edx, 8031Fh; Mask
0x14000f965  jmp     _controlfp

// ===== _setfpstatusword @ 0x14000f96c =====

0x14000f96c  push    rbx
0x14000f96e  sub     rsp, 20h
0x14000f972  mov     ebx, ecx
0x14000f974  call    _get_fpsr
0x14000f979  and     eax, 0FFFFFFC2h
0x14000f97c  xor     ecx, ecx
0x14000f97e  test    bl, 1Fh
0x14000f981  jz      short loc_14000F9B0
0x14000f983  mov     dl, bl
0x14000f985  lea     r8d, [rcx+1]
0x14000f989  and     dl, 10h
0x14000f98c  cmovnz  ecx, r8d
0x14000f990  test    bl, 8
0x14000f993  jz      short loc_14000F998
0x14000f995  or      ecx, 4
0x14000f998  test    bl, 4
0x14000f99b  jz      short loc_14000F9A0
0x14000f99d  or      ecx, 8
0x14000f9a0  test    bl, 2
0x14000f9a3  jz      short loc_14000F9A8
0x14000f9a5  or      ecx, 10h
0x14000f9a8  test    r8b, bl
0x14000f9ab  jz      short loc_14000F9B0
0x14000f9ad  or      ecx, 20h
0x14000f9b0  or      ecx, eax
0x14000f9b2  add     rsp, 20h
0x14000f9b6  pop     rbx
0x14000f9b7  jmp     _set_fpsr

// ===== _clearfp @ 0x14000f9bc =====

0x14000f9bc  push    rbx
0x14000f9be  sub     rsp, 20h
0x14000f9c2  call    _get_fpsr
0x14000f9c7  mov     ebx, eax
0x14000f9c9  call    _fclrf
0x14000f9ce  xor     eax, eax
0x14000f9d0  test    bl, 3Fh
0x14000f9d3  jz      short loc_14000FA08
0x14000f9d5  mov     cl, bl
0x14000f9d7  lea     edx, [rax+10h]
0x14000f9da  and     cl, 1
0x14000f9dd  cmovnz  eax, edx
0x14000f9e0  test    bl, 4
0x14000f9e3  jz      short loc_14000F9E8
0x14000f9e5  or      eax, 8
0x14000f9e8  test    bl, 8
0x14000f9eb  jz      short loc_14000F9F0
0x14000f9ed  or      eax, 4
0x14000f9f0  test    dl, bl
0x14000f9f2  jz      short loc_14000F9F7
0x14000f9f4  or      eax, 2
0x14000f9f7  test    bl, 20h
0x14000f9fa  jz      short loc_14000F9FF
0x14000f9fc  or      eax, 1
0x14000f9ff  test    bl, 2
0x14000fa02  jz      short loc_14000FA08
0x14000fa04  bts     eax, 13h
0x14000fa08  add     rsp, 20h
0x14000fa0c  pop     rbx
0x14000fa0d  retn

// ===== _controlfp @ 0x14000fa10 =====

0x14000fa10  btr     edx, 13h
0x14000fa14  jmp     common_control87

// ===== _statusfp @ 0x14000fa1c =====

0x14000fa1c  stmxcsr [rsp+arg_0]
0x14000fa21  mov     edx, [rsp+arg_0]
0x14000fa25  xor     ecx, ecx
0x14000fa27  test    dl, 3Fh
0x14000fa2a  jz      short loc_14000FA61
0x14000fa2c  mov     al, dl
0x14000fa2e  lea     r8d, [rcx+10h]
0x14000fa32  and     al, 1
0x14000fa34  cmovnz  ecx, r8d
0x14000fa38  test    dl, 4
0x14000fa3b  jz      short loc_14000FA40
0x14000fa3d  or      ecx, 8
0x14000fa40  test    dl, 8
0x14000fa43  jz      short loc_14000FA48
0x14000fa45  or      ecx, 4
0x14000fa48  test    r8b, dl
0x14000fa4b  jz      short loc_14000FA50
0x14000fa4d  or      ecx, 2
0x14000fa50  test    dl, 20h
0x14000fa53  jz      short loc_14000FA58
0x14000fa55  or      ecx, 1
0x14000fa58  test    dl, 2
0x14000fa5b  jz      short loc_14000FA61
0x14000fa5d  bts     ecx, 13h
0x14000fa61  mov     eax, ecx
0x14000fa63  retn

// ===== common_control87 @ 0x14000fa64 =====

0x14000fa64  mov     [rsp+arg_8], rbx
0x14000fa69  mov     [rsp+arg_10], rsi
0x14000fa6e  mov     [rsp+arg_18], rdi
0x14000fa73  push    r12
0x14000fa75  push    r14
0x14000fa77  push    r15
0x14000fa79  sub     rsp, 20h
0x14000fa7d  mov     ebx, edx
0x14000fa7f  mov     esi, ecx
0x14000fa81  and     ebx, 308031Fh
0x14000fa87  call    _get_fpsr
0x14000fa8c  mov     r9d, eax
0x14000fa8f  xor     edi, edi
0x14000fa91  mov     r8b, al
0x14000fa94  mov     r11d, 80h
0x14000fa9a  mov     eax, edi
0x14000fa9c  lea     ecx, [rdi+10h]
0x14000fa9f  and     r8b, r11b
0x14000faa2  cmovnz  eax, ecx
0x14000faa5  mov     r12d, 200h
0x14000faab  test    r12d, r9d
0x14000faae  jz      short loc_14000FAB3
0x14000fab0  or      eax, 8
0x14000fab3  bt      r9d, 0Ah
0x14000fab8  jnb     short loc_14000FABD
0x14000faba  or      eax, 4
0x14000fabd  mov     r8d, 800h
0x14000fac3  test    r8d, r9d
0x14000fac6  jz      short loc_14000FACB
0x14000fac8  or      eax, 2
0x14000facb  mov     r10d, 1000h
0x14000fad1  test    r10d, r9d
0x14000fad4  jz      short loc_14000FAD9
0x14000fad6  or      eax, 1
0x14000fad9  mov     r14d, 100h
0x14000fadf  test    r14d, r9d
0x14000fae2  jz      short loc_14000FAE8
0x14000fae4  bts     eax, 13h
0x14000fae8  mov     ecx, r9d
0x14000faeb  mov     r15d, 6000h
0x14000faf1  and     ecx, r15d
0x14000faf4  jz      short loc_14000FB1A
0x14000faf6  cmp     ecx, 2000h
0x14000fafc  jz      short loc_14000FB17
0x14000fafe  cmp     ecx, 4000h
0x14000fb04  jz      short loc_14000FB12
0x14000fb06  cmp     ecx, r15d
0x14000fb09  jnz     short loc_14000FB1A
0x14000fb0b  or      eax, 300h
0x14000fb10  jmp     short loc_14000FB1A
0x14000fb12  or      eax, r12d
0x14000fb15  jmp     short loc_14000FB1A
0x14000fb17  or      eax, r14d
0x14000fb1a  mov     edx, 8040h
0x14000fb1f  and     r9d, edx
0x14000fb22  sub     r9d, 40h ; '@'
0x14000fb26  jz      short loc_14000FB44
0x14000fb28  sub     r9d, 7FC0h
0x14000fb2f  jz      short loc_14000FB3D
0x14000fb31  cmp     r9d, 40h ; '@'
0x14000fb35  jnz     short loc_14000FB48
0x14000fb37  bts     eax, 18h
0x14000fb3b  jmp     short loc_14000FB48
0x14000fb3d  or      eax, 3000000h
0x14000fb42  jmp     short loc_14000FB48
0x14000fb44  bts     eax, 19h
0x14000fb48  mov     ecx, ebx
0x14000fb4a  not     ecx
0x14000fb4c  and     ecx, eax
0x14000fb4e  and     esi, ebx
0x14000fb50  or      ecx, esi
0x14000fb52  cmp     ecx, eax
0x14000fb54  jz      loc_14000FCE0
0x14000fb5a  mov     al, cl
0x14000fb5c  mov     esi, 10h
0x14000fb61  mov     ebx, edi
0x14000fb63  and     al, sil
0x14000fb66  cmovnz  ebx, r11d
0x14000fb6a  mov     [rsp+38h+arg_0], ebx
0x14000fb6e  test    cl, 8
0x14000fb71  jz      short loc_14000FB7A
0x14000fb73  or      ebx, r12d
0x14000fb76  mov     [rsp+38h+arg_0], ebx
0x14000fb7a  test    cl, 4
0x14000fb7d  jz      short loc_14000FB87
0x14000fb7f  bts     ebx, 0Ah
0x14000fb83  mov     [rsp+38h+arg_0], ebx
0x14000fb87  test    cl, 2
0x14000fb8a  jz      short loc_14000FB93
0x14000fb8c  or      ebx, r8d
0x14000fb8f  mov     [rsp+38h+arg_0], ebx
0x14000fb93  test    cl, 1
0x14000fb96  jz      short loc_14000FB9F
0x14000fb98  or      ebx, r10d
0x14000fb9b  mov     [rsp+38h+arg_0], ebx
0x14000fb9f  bt      ecx, 13h
0x14000fba3  jnb     short loc_14000FBAC
0x14000fba5  or      ebx, r14d
0x14000fba8  mov     [rsp+38h+arg_0], ebx
0x14000fbac  mov     eax, ecx
0x14000fbae  and     eax, 300h
0x14000fbb3  jz      short loc_14000FBD9
0x14000fbb5  cmp     eax, r14d
0x14000fbb8  jz      short loc_14000FBD1
0x14000fbba  cmp     eax, r12d
0x14000fbbd  jz      short loc_14000FBCB
0x14000fbbf  cmp     eax, 300h
0x14000fbc4  jnz     short loc_14000FBD9
0x14000fbc6  or      ebx, r15d
0x14000fbc9  jmp     short loc_14000FBD5
0x14000fbcb  bts     ebx, 0Eh
0x14000fbcf  jmp     short loc_14000FBD5
0x14000fbd1  bts     ebx, 0Dh
0x14000fbd5  mov     [rsp+38h+arg_0], ebx
0x14000fbd9  and     ecx, 3000000h
0x14000fbdf  cmp     ecx, 1000000h
0x14000fbe5  jz      short loc_14000FC02
0x14000fbe7  cmp     ecx, 2000000h
0x14000fbed  jz      short loc_14000FBFD
0x14000fbef  cmp     ecx, 3000000h
0x14000fbf5  jnz     short loc_14000FC08
0x14000fbf7  bts     ebx, 0Fh
0x14000fbfb  jmp     short loc_14000FC04
0x14000fbfd  or      ebx, 40h
0x14000fc00  jmp     short loc_14000FC04
0x14000fc02  or      ebx, edx
0x14000fc04  mov     [rsp+38h+arg_0], ebx
0x14000fc08  cmp     cs:byte_14001C8D0, dil
0x14000fc0f  jz      short loc_14000FC4D
0x14000fc11  test    bl, 40h
0x14000fc14  jz      short loc_14000FC4D
0x14000fc16  mov     ecx, ebx
0x14000fc18  call    _set_fpsr
0x14000fc1d  jmp     short loc_14000FC4B
0x14000fc1f  mov     cs:byte_14001C8D0, 0
0x14000fc26  mov     ebx, [rsp+38h+arg_0]
0x14000fc2a  and     ebx, 0FFFFFFBFh
0x14000fc2d  mov     ecx, ebx
0x14000fc2f  call    _set_fpsr
0x14000fc34  xor     edi, edi
0x14000fc36  lea     esi, [rdi+10h]
0x14000fc39  mov     r12d, 200h
0x14000fc3f  mov     r14d, 100h
0x14000fc45  mov     r15d, 6000h
0x14000fc4b  jmp     short loc_14000FC57
0x14000fc4d  and     ebx, 0FFFFFFBFh
0x14000fc50  mov     ecx, ebx
0x14000fc52  call    _set_fpsr
0x14000fc57  mov     al, bl
0x14000fc59  and     al, 80h
0x14000fc5b  cmovnz  edi, esi
0x14000fc5e  test    r12d, ebx
0x14000fc61  jz      short loc_14000FC66
0x14000fc63  or      edi, 8
0x14000fc66  bt      ebx, 0Ah
0x14000fc6a  jnb     short loc_14000FC6F
0x14000fc6c  or      edi, 4
0x14000fc6f  bt      ebx, 0Bh
0x14000fc73  jnb     short loc_14000FC78
0x14000fc75  or      edi, 2
0x14000fc78  bt      ebx, 0Ch
0x14000fc7c  jnb     short loc_14000FC81
0x14000fc7e  or      edi, 1
0x14000fc81  test    r14d, ebx
0x14000fc84  jz      short loc_14000FC8A
0x14000fc86  bts     edi, 13h
0x14000fc8a  mov     eax, ebx
0x14000fc8c  and     eax, r15d
0x14000fc8f  jz      short loc_14000FCB4
0x14000fc91  cmp     eax, 2000h
0x14000fc96  jz      short loc_14000FCB1
0x14000fc98  cmp     eax, 4000h
0x14000fc9d  jz      short loc_14000FCAC
0x14000fc9f  cmp     eax, r15d
0x14000fca2  jnz     short loc_14000FCB4
0x14000fca4  or      edi, 300h
0x14000fcaa  jmp     short loc_14000FCB4
0x14000fcac  or      edi, r12d
0x14000fcaf  jmp     short loc_14000FCB4
0x14000fcb1  or      edi, r14d
0x14000fcb4  and     ebx, 8040h
0x14000fcba  sub     ebx, 40h ; '@'
0x14000fcbd  jz      short loc_14000FCDA
0x14000fcbf  sub     ebx, 7FC0h
0x14000fcc5  jz      short loc_14000FCD2
0x14000fcc7  cmp     ebx, 40h ; '@'
0x14000fcca  jnz     short loc_14000FCDE
0x14000fccc  bts     edi, 18h
0x14000fcd0  jmp     short loc_14000FCDE
0x14000fcd2  or      edi, 3000000h
0x14000fcd8  jmp     short loc_14000FCDE
0x14000fcda  bts     edi, 19h
0x14000fcde  mov     eax, edi
0x14000fce0  mov     rbx, [rsp+38h+arg_8]
0x14000fce5  mov     rsi, [rsp+38h+arg_10]
0x14000fcea  mov     rdi, [rsp+38h+arg_18]
0x14000fcef  add     rsp, 20h
0x14000fcf3  pop     r15
0x14000fcf5  pop     r14
0x14000fcf7  pop     r12
0x14000fcf9  retn
0x140010b73  push    rbp; Microsoft VisualC 64bit universal runtime
0x140010b75  sub     rsp, 20h
0x140010b79  mov     rbp, rdx
0x140010b7c  mov     rax, [rcx]
0x140010b7f  cmp     dword ptr [rax], 0C0000005h
0x140010b85  jz      short loc_140010B93
0x140010b87  cmp     dword ptr [rax], 0C000001Dh
0x140010b8d  jz      short loc_140010B93
0x140010b8f  xor     eax, eax
0x140010b91  jmp     short loc_140010B98
0x140010b93  mov     eax, 1
0x140010b98  add     rsp, 20h
0x140010b9c  pop     rbp
0x140010b9d  retn

// ===== _call_matherr @ 0x14000fcfc =====

0x14000fcfc  mov     rax, rsp
0x14000fcff  push    rbx
0x14000fd00  sub     rsp, 50h
0x14000fd04  movsd   xmm0, [rsp+58h+arg_20]
0x14000fd0d  mov     ebx, ecx
0x14000fd0f  movsd   xmm1, [rsp+58h+arg_28]
0x14000fd18  mov     edx, 0FFC0h
0x14000fd1d  mov     [rax-38h], ecx
0x14000fd20  mov     rcx, [rsp+58h+arg_30]
0x14000fd28  movsd   qword ptr [rax-20h], xmm0
0x14000fd2d  movsd   qword ptr [rax-18h], xmm1
0x14000fd32  movsd   qword ptr [rax-28h], xmm3
0x14000fd37  mov     [rax-30h], r8
0x14000fd3b  call    _ctrlfp
0x14000fd40  lea     rcx, [rsp+58h+var_38]
0x14000fd45  call    __acrt_invoke_user_matherr
0x14000fd4a  test    eax, eax
0x14000fd4c  jnz     short loc_14000FD55
0x14000fd4e  mov     ecx, ebx
0x14000fd50  call    _set_errno_from_matherr
0x14000fd55  movsd   xmm0, [rsp+58h+var_18]
0x14000fd5b  add     rsp, 50h
0x14000fd5f  pop     rbx
0x14000fd60  retn

// ===== _exception_enabled @ 0x14000fd64 =====

0x14000fd64  mov     [rsp+arg_0], rbx
0x14000fd69  mov     [rsp+arg_8], rsi
0x14000fd6e  push    rdi
0x14000fd6f  sub     rsp, 20h
0x14000fd73  mov     ebx, ecx
0x14000fd75  mov     rsi, rdx
0x14000fd78  and     ebx, 1Fh
0x14000fd7b  mov     edi, ecx
0x14000fd7d  test    cl, 8
0x14000fd80  jz      short loc_14000FD95
0x14000fd82  test    dl, dl
0x14000fd84  jns     short loc_14000FD95
0x14000fd86  mov     ecx, 1
0x14000fd8b  call    _set_statfp
0x14000fd90  and     ebx, 0FFFFFFF7h
0x14000fd93  jmp     short loc_14000FDEC
0x14000fd95  mov     ecx, 4
0x14000fd9a  test    cl, dil
0x14000fd9d  jz      short loc_14000FDB0
0x14000fd9f  bt      rdx, 9
0x14000fda4  jnb     short loc_14000FDB0
0x14000fda6  call    _set_statfp
0x14000fdab  and     ebx, 0FFFFFFFBh
0x14000fdae  jmp     short loc_14000FDEC
0x14000fdb0  test    dil, 1
0x14000fdb4  jz      short loc_14000FDCC
0x14000fdb6  bt      rdx, 0Ah
0x14000fdbb  jnb     short loc_14000FDCC
0x14000fdbd  mov     ecx, 8
0x14000fdc2  call    _set_statfp
0x14000fdc7  and     ebx, 0FFFFFFFEh
0x14000fdca  jmp     short loc_14000FDEC
0x14000fdcc  test    dil, 2
0x14000fdd0  jz      short loc_14000FDEC
0x14000fdd2  bt      rdx, 0Bh
0x14000fdd7  jnb     short loc_14000FDEC
0x14000fdd9  test    dil, 10h
0x14000fddd  jz      short loc_14000FDE9
0x14000fddf  mov     ecx, 10h
0x14000fde4  call    _set_statfp
0x14000fde9  and     ebx, 0FFFFFFFDh
0x14000fdec  test    dil, 10h
0x14000fdf0  jz      short loc_14000FE06
0x14000fdf2  bt      rsi, 0Ch
0x14000fdf7  jnb     short loc_14000FE06
0x14000fdf9  mov     ecx, 20h ; ' '
0x14000fdfe  call    _set_statfp
0x14000fe03  and     ebx, 0FFFFFFEFh
0x14000fe06  mov     rsi, [rsp+28h+arg_8]
0x14000fe0b  xor     eax, eax
0x14000fe0d  test    ebx, ebx
0x14000fe0f  mov     rbx, [rsp+28h+arg_0]
0x14000fe14  setz    al
0x14000fe17  add     rsp, 20h
0x14000fe1b  pop     rdi
0x14000fe1c  retn

// ===== _handle_error @ 0x14000fe20 =====

0x14000fe20  mov     rax, rsp
0x14000fe23  push    rbp
0x14000fe24  push    rbx
0x14000fe25  push    rsi
0x14000fe26  push    rdi
0x14000fe27  push    r14
0x14000fe29  lea     rbp, [rax-37h]
0x14000fe2d  sub     rsp, 0F0h
0x14000fe34  movaps  xmmword ptr [rax-38h], xmm6
0x14000fe38  mov     rax, cs:__security_cookie
0x14000fe3f  xor     rax, rsp
0x14000fe42  mov     [rbp+2Fh+var_40], rax
0x14000fe46  mov     esi, edx
0x14000fe48  mov     r14, rcx
0x14000fe4b  mov     edx, 0FFC0h
0x14000fe50  mov     ecx, 1F80h
0x14000fe55  mov     edi, r9d
0x14000fe58  mov     rbx, r8
0x14000fe5b  call    _ctrlfp
0x14000fe60  mov     ecx, [rbp+2Fh+arg_20]
0x14000fe63  mov     [rsp+110h+var_D0], rax
0x14000fe68  mov     [rsp+110h+var_C8+8], rbx
0x14000fe6d  movsd   xmm0, [rsp+110h+var_C8+8]
0x14000fe73  mov     rdx, [rsp+110h+var_D0]
0x14000fe78  movsd   [rsp+110h+var_C8], xmm0
0x14000fe7e  call    _exception_enabled
0x14000fe83  movsd   xmm6, [rbp+2Fh+arg_38]
0x14000fe88  test    eax, eax
0x14000fe8a  jnz     short loc_14000FECC
0x14000fe8c  cmp     [rbp+2Fh+arg_40], 2
0x14000fe90  jnz     short loc_14000FEA3
0x14000fe92  mov     eax, [rbp+2Fh+var_70]
0x14000fe95  and     eax, 0FFFFFFE3h
0x14000fe98  movsd   [rbp+2Fh+var_80], xmm6
0x14000fe9d  or      eax, 3
0x14000fea0  mov     [rbp+2Fh+var_70], eax
0x14000fea3  mov     r8d, [rbp+2Fh+arg_20]
0x14000fea7  lea     rax, [rsp+110h+var_C8]
0x14000feac  mov     [rsp+110h+var_E8], rax
0x14000feb1  lea     rdx, [rsp+110h+var_D0]
0x14000feb6  lea     rax, [rbp+2Fh+arg_30]
0x14000feba  mov     r9d, esi
0x14000febd  lea     rcx, [rsp+60h]
0x14000fec2  mov     [rsp+110h+var_F0], rax
0x14000fec7  call    _raise_exc
0x14000fecc  call    __acrt_has_user_matherr
0x14000fed1  test    al, al
0x14000fed3  jz      short loc_14000FF09
0x14000fed5  test    edi, edi
0x14000fed7  jz      short loc_14000FF09
0x14000fed9  mov     rax, [rsp+110h+var_D0]
0x14000fede  mov     r8, r14
0x14000fee1  movsd   xmm0, [rsp+110h+var_C8]
0x14000fee7  mov     ecx, edi
0x14000fee9  movsd   xmm3, [rbp+2Fh+arg_30]
0x14000feee  mov     edx, [rbp+2Fh+arg_28]
0x14000fef1  mov     [rsp+30h], rax
0x14000fef6  movsd   [rsp+110h+var_E8], xmm0
0x14000fefc  movsd   [rsp+110h+var_F0], xmm6
0x14000ff02  call    _call_matherr
0x14000ff07  jmp     short loc_14000FF25
0x14000ff09  mov     ecx, edi
0x14000ff0b  call    _set_errno_from_matherr
0x14000ff10  mov     rcx, [rsp+110h+var_D0]
0x14000ff15  mov     edx, 0FFC0h
0x14000ff1a  call    _ctrlfp
0x14000ff1f  movsd   xmm0, [rsp+110h+var_C8]
0x14000ff25  mov     rcx, [rbp+2Fh+var_40]
0x14000ff29  xor     rcx, rsp; StackCookie
0x14000ff2c  call    __security_check_cookie
0x14000ff31  movaps  xmm6, [rsp+110h+var_38+8]
0x14000ff39  add     rsp, 0F0h
0x14000ff40  pop     r14
0x14000ff42  pop     rdi
0x14000ff43  pop     rsi
0x14000ff44  pop     rbx
0x14000ff45  pop     rbp
0x14000ff46  retn

// ===== __acrt_initialize_fma3 @ 0x14000ff70 =====

0x14000ff70  push    rbx
0x14000ff72  sub     rsp, 10h
0x14000ff76  xor     r8d, r8d
0x14000ff79  xor     ecx, ecx
0x14000ff7b  mov     cs:dword_14001DBA8, r8d
0x14000ff82  lea     r9d, [r8+1]
0x14000ff86  mov     eax, r9d
0x14000ff89  cpuid
0x14000ff8b  mov     [rsp+18h+var_18], eax
0x14000ff8e  mov     eax, 18001000h
0x14000ff93  mov     [rsp+18h+var_10], ecx
0x14000ff97  and     ecx, eax
0x14000ff99  mov     [rsp+18h+var_14], ebx
0x14000ff9d  mov     [rsp+18h+var_C], edx
0x14000ffa1  cmp     ecx, eax
0x14000ffa3  jnz     short loc_14000FFD1
0x14000ffa5  xor     ecx, ecx
0x14000ffa7  xgetbv
0x14000ffaa  shl     rdx, 20h
0x14000ffae  or      rdx, rax
0x14000ffb1  mov     [rsp+18h+arg_0], rdx
0x14000ffb6  mov     rax, [rsp+18h+arg_0]
0x14000ffbb  mov     r8d, cs:dword_14001DBA8
0x14000ffc2  and     al, 6
0x14000ffc4  cmp     al, 6
0x14000ffc6  cmovz   r8d, r9d
0x14000ffca  mov     cs:dword_14001DBA8, r8d
0x14000ffd1  mov     cs:dword_14001DBAC, r8d
0x14000ffd8  xor     eax, eax
0x14000ffda  add     rsp, 10h
0x14000ffde  pop     rbx
0x14000ffdf  retn

// ===== _log10_special @ 0x14000ffe0 =====

0x14000ffe0  sub     rsp, 38h
0x14000ffe4  lea     rax, aLog10
0x14000ffeb  mov     r9d, 1Bh
0x14000fff1  mov     [rsp+38h+var_18], rax
0x14000fff6  call    _log_special_common
0x14000fffb  add     rsp, 38h
0x14000ffff  retn

// ===== _log_special_common @ 0x140010000 =====

0x140010000  mov     rax, rsp
0x140010003  sub     rsp, 68h
0x140010007  movaps  xmmword ptr [rax-18h], xmm6
0x14001000b  movaps  xmm6, xmm1
0x14001000e  mov     edx, r9d
0x140010011  movaps  xmm3, xmm0
0x140010014  sub     r8d, 1
0x140010018  jz      short loc_140010044
0x14001001a  cmp     r8d, 1
0x14001001e  jnz     short loc_140010089
0x140010020  mov     [rax-28h], r8d
0x140010024  xorps   xmm2, xmm2
0x140010027  movsd   qword ptr [rax-30h], xmm2
0x14001002c  mov     r9d, r8d
0x14001002f  movsd   qword ptr [rax-38h], xmm0
0x140010034  mov     dword ptr [rax-40h], 21h ; '!'
0x14001003b  mov     dword ptr [rax-48h], 8
0x140010042  jmp     short loc_140010071
0x140010044  mov     [rsp+68h+var_28], 1
0x14001004c  xorps   xmm0, xmm0
0x14001004f  movsd   [rsp+68h+var_30], xmm0
0x140010055  mov     r9d, 2
0x14001005b  movsd   [rsp+68h+var_38], xmm3
0x140010061  mov     [rsp+68h+var_40], 22h ; '"'
0x140010069  mov     [rsp+68h+var_48], 4
0x140010071  mov     rcx, [rsp+68h+arg_20]
0x140010079  movsd   [rsp+68h+arg_8], xmm1
0x14001007f  mov     r8, [rsp+68h+arg_8]
0x140010084  call    _handle_error
0x140010089  movaps  xmm0, xmm6
0x14001008c  movaps  xmm6, [rsp+68h+var_18]
0x140010091  add     rsp, 68h
0x140010095  retn

// ===== sub_140010098 @ 0x140010098 =====

0x140010098  sub     rsp, 48h
0x14001009c  and     [rsp+48h+var_18], 0
0x1400100a2  lea     rcx, aConout; "CONOUT$"
0x1400100a9  and     [rsp+48h+var_20], 0
0x1400100ae  mov     r8d, 3; dwShareMode
0x1400100b4  xor     r9d, r9d; lpSecurityAttributes
0x1400100b7  mov     [rsp+48h+dwCreationDisposition], r8d; dwCreationDisposition
0x1400100bc  mov     edx, 40000000h; dwDesiredAccess
0x1400100c1  call    cs:CreateFileW; KERNEL32
0x1400100c7  mov     cs:hConsoleOutput, rax
0x1400100ce  add     rsp, 48h
0x1400100d2  retn

// ===== sub_1400100D4 @ 0x1400100d4 =====

0x1400100d4  sub     rsp, 28h
0x1400100d8  mov     rcx, cs:hConsoleOutput; hObject
0x1400100df  lea     rax, [rcx+2]
0x1400100e3  cmp     rax, 1
0x1400100e7  jbe     short loc_1400100EF
0x1400100e9  call    cs:CloseHandle; KERNEL32
0x1400100ef  add     rsp, 28h
0x1400100f3  retn

// ===== _get_fpsr @ 0x140010110 =====

0x140010110  sub     rsp, 8
0x140010114  stmxcsr [rsp+8+var_8]
0x140010118  mov     eax, [rsp+8+var_8]
0x14001011b  add     rsp, 8
0x14001011f  retn

// ===== _set_fpsr @ 0x140010120 =====

0x140010120  mov     [rsp+arg_0], ecx
0x140010124  ldmxcsr [rsp+arg_0]
0x140010129  retn

// ===== _fclrf @ 0x14001012a =====

0x14001012a  stmxcsr [rsp+arg_0]
0x14001012f  mov     ecx, 0FFFFFFC0h
0x140010134  and     [rsp+arg_0], ecx
0x140010138  ldmxcsr [rsp+arg_0]
0x14001013d  retn

// ===== _return @ 0x14001015c =====

0x14001015c  retn

// ===== _raise_exc @ 0x140010160 =====

0x140010160  sub     rsp, 48h
0x140010164  and     [rsp+48h+var_18], 0
0x140010169  mov     rax, [rsp+48h+arg_28]
0x14001016e  mov     [rsp+48h+var_20], rax
0x140010173  mov     rax, [rsp+48h+arg_20]
0x140010178  mov     [rsp+48h+var_28], rax
0x14001017d  call    _raise_exc_ex
0x140010182  add     rsp, 48h
0x140010186  retn

// ===== _raise_exc_ex @ 0x140010188 =====

0x140010188  mov     rax, rsp
0x14001018b  mov     [rax+10h], rbx
0x14001018f  mov     [rax+18h], rsi
0x140010193  mov     [rax+20h], rdi
0x140010197  mov     [rax+8], rcx
0x14001019b  push    rbp
0x14001019c  mov     rbp, rsp
0x14001019f  sub     rsp, 20h
0x1400101a3  mov     rbx, rdx
0x1400101a6  mov     esi, r9d
0x1400101a9  xor     edx, edx
0x1400101ab  mov     edi, 0C000000Dh
0x1400101b0  mov     [rcx+4], edx
0x1400101b3  mov     rax, [rbp+Arguments]
0x1400101b7  mov     [rax+8], edx
0x1400101ba  mov     rax, [rbp+Arguments]
0x1400101be  mov     [rax+0Ch], edx
0x1400101c1  test    r8b, 10h
0x1400101c5  jz      short loc_1400101D4
0x1400101c7  mov     rax, [rbp+Arguments]
0x1400101cb  mov     edi, 0C000008Fh
0x1400101d0  or      dword ptr [rax+4], 1
0x1400101d4  test    r8b, 2
0x1400101d8  jz      short loc_1400101E7
0x1400101da  mov     rax, [rbp+Arguments]
0x1400101de  mov     edi, 0C0000093h
0x1400101e3  or      dword ptr [rax+4], 2
0x1400101e7  test    r8b, 1
0x1400101eb  jz      short loc_1400101FA
0x1400101ed  mov     rax, [rbp+Arguments]
0x1400101f1  mov     edi, 0C0000091h
0x1400101f6  or      dword ptr [rax+4], 4
0x1400101fa  test    r8b, 4
0x1400101fe  jz      short loc_14001020D
0x140010200  mov     rax, [rbp+Arguments]
0x140010204  mov     edi, 0C000008Eh
0x140010209  or      dword ptr [rax+4], 8
0x14001020d  test    r8b, 8
0x140010211  jz      short loc_140010220
0x140010213  mov     rax, [rbp+Arguments]
0x140010217  mov     edi, 0C0000090h
0x14001021c  or      dword ptr [rax+4], 10h
0x140010220  mov     rcx, [rbp+Arguments]
0x140010224  mov     rax, [rbx]
0x140010227  shr     rax, 7
0x14001022b  shl     eax, 4
0x14001022e  not     eax
0x140010230  xor     eax, [rcx+8]
0x140010233  and     eax, 10h
0x140010236  xor     [rcx+8], eax
0x140010239  mov     rcx, [rbp+Arguments]
0x14001023d  mov     rax, [rbx]
0x140010240  shr     rax, 9
0x140010244  shl     eax, 3
0x140010247  not     eax
0x140010249  xor     eax, [rcx+8]
0x14001024c  and     eax, 8
0x14001024f  xor     [rcx+8], eax
0x140010252  mov     rcx, [rbp+Arguments]
0x140010256  mov     rax, [rbx]
0x140010259  shr     rax, 0Ah
0x14001025d  shl     eax, 2
0x140010260  not     eax
0x140010262  xor     eax, [rcx+8]
0x140010265  and     eax, 4
0x140010268  xor     [rcx+8], eax
0x14001026b  mov     rcx, [rbp+Arguments]
0x14001026f  mov     rax, [rbx]
0x140010272  shr     rax, 0Bh
0x140010276  add     eax, eax
0x140010278  not     eax
0x14001027a  xor     eax, [rcx+8]
0x14001027d  and     eax, 2
0x140010280  xor     [rcx+8], eax
0x140010283  mov     eax, [rbx]
0x140010285  mov     rcx, [rbp+Arguments]
0x140010289  shr     rax, 0Ch
0x14001028d  not     eax
0x14001028f  xor     eax, [rcx+8]
0x140010292  and     eax, 1
0x140010295  xor     [rcx+8], eax
0x140010298  call    _statfp
0x14001029d  mov     rdx, rax
0x1400102a0  test    al, 1
0x1400102a2  jz      short loc_1400102AC
0x1400102a4  mov     rcx, [rbp+Arguments]
0x1400102a8  or      dword ptr [rcx+0Ch], 10h
0x1400102ac  test    al, 4
0x1400102ae  jz      short loc_1400102B8
0x1400102b0  mov     rcx, [rbp+Arguments]
0x1400102b4  or      dword ptr [rcx+0Ch], 8
0x1400102b8  test    al, 8
0x1400102ba  jz      short loc_1400102C4
0x1400102bc  mov     rax, [rbp+Arguments]
0x1400102c0  or      dword ptr [rax+0Ch], 4
0x1400102c4  test    dl, 10h
0x1400102c7  jz      short loc_1400102D1
0x1400102c9  mov     rax, [rbp+Arguments]
0x1400102cd  or      dword ptr [rax+0Ch], 2
0x1400102d1  test    dl, 20h
0x1400102d4  jz      short loc_1400102DE
0x1400102d6  mov     rax, [rbp+Arguments]
0x1400102da  or      dword ptr [rax+0Ch], 1
0x1400102de  mov     eax, [rbx]
0x1400102e0  mov     ecx, 6000h
0x1400102e5  and     rax, rcx
0x1400102e8  jz      short loc_140010328
0x1400102ea  cmp     rax, 2000h
0x1400102f0  jz      short loc_140010318
0x1400102f2  cmp     rax, 4000h
0x1400102f8  jz      short loc_140010308
0x1400102fa  cmp     rax, rcx
0x1400102fd  jnz     short loc_14001032F
0x1400102ff  mov     rax, [rbp+Arguments]
0x140010303  or      dword ptr [rax], 3
0x140010306  jmp     short loc_14001032F
0x140010308  mov     rax, [rbp+Arguments]
0x14001030c  and     dword ptr [rax], 0FFFFFFFEh
0x14001030f  mov     rax, [rbp+Arguments]
0x140010313  or      dword ptr [rax], 2
0x140010316  jmp     short loc_14001032F
0x140010318  mov     rax, [rbp+Arguments]
0x14001031c  and     dword ptr [rax], 0FFFFFFFDh
0x14001031f  mov     rax, [rbp+Arguments]
0x140010323  or      dword ptr [rax], 1
0x140010326  jmp     short loc_14001032F
0x140010328  mov     rax, [rbp+Arguments]
0x14001032c  and     dword ptr [rax], 0FFFFFFFCh
0x14001032f  mov     rax, [rbp+Arguments]
0x140010333  and     esi, 0FFFh
0x140010339  shl     esi, 5
0x14001033c  and     dword ptr [rax], 0FFFE001Fh
0x140010342  mov     rax, [rbp+Arguments]
0x140010346  or      [rax], esi
0x140010348  mov     rax, [rbp+Arguments]
0x14001034c  mov     rsi, [rbp+arg_28]
0x140010350  or      dword ptr [rax+20h], 1
0x140010354  cmp     [rbp+arg_30], 0
0x140010358  jz      short loc_14001038D
0x14001035a  mov     rax, [rbp+Arguments]
0x14001035e  mov     edx, 0FFFFFFE1h
0x140010363  and     [rax+20h], edx
0x140010366  mov     rax, [rbp+arg_20]
0x14001036a  mov     ecx, [rax]
0x14001036c  mov     rax, [rbp+Arguments]
0x140010370  mov     [rax+10h], ecx
0x140010373  mov     rax, [rbp+Arguments]
0x140010377  or      dword ptr [rax+60h], 1
0x14001037b  mov     rax, [rbp+Arguments]
0x14001037f  and     [rax+60h], edx
0x140010382  mov     rax, [rbp+Arguments]
0x140010386  mov     ecx, [rsi]
0x140010388  mov     [rax+50h], ecx
0x14001038b  jmp     short loc_1400103D5
0x14001038d  mov     rcx, [rbp+Arguments]
0x140010391  mov     r8d, 0FFFFFFE3h
0x140010397  mov     eax, [rcx+20h]
0x14001039a  and     eax, r8d
0x14001039d  or      eax, 2
0x1400103a0  mov     [rcx+20h], eax
0x1400103a3  mov     rax, [rbp+arg_20]
0x1400103a7  mov     rcx, [rax]
0x1400103aa  mov     rax, [rbp+Arguments]
0x1400103ae  mov     [rax+10h], rcx
0x1400103b2  mov     rax, [rbp+Arguments]
0x1400103b6  or      dword ptr [rax+60h], 1
0x1400103ba  mov     rdx, [rbp+Arguments]
0x1400103be  mov     eax, [rdx+60h]
0x1400103c1  and     eax, r8d
0x1400103c4  or      eax, 2
0x1400103c7  mov     [rdx+60h], eax
0x1400103ca  mov     rax, [rbp+Arguments]
0x1400103ce  mov     rdx, [rsi]
0x1400103d1  mov     [rax+50h], rdx
0x1400103d5  call    _clrfp
0x1400103da  xor     edx, edx; dwExceptionFlags
0x1400103dc  lea     r9, [rbp+Arguments]; lpArguments
0x1400103e0  mov     ecx, edi; dwExceptionCode
0x1400103e2  lea     r8d, [rdx+1]; nNumberOfArguments
0x1400103e6  call    cs:RaiseException; KERNEL32
0x1400103ec  mov     rcx, [rbp+Arguments]
0x1400103f0  test    byte ptr [rcx+8], 10h
0x1400103f4  jz      short loc_1400103FB
0x1400103f6  btr     qword ptr [rbx], 7
0x1400103fb  test    byte ptr [rcx+8], 8
0x1400103ff  jz      short loc_140010406
0x140010401  btr     qword ptr [rbx], 9
0x140010406  test    byte ptr [rcx+8], 4
0x14001040a  jz      short loc_140010411
0x14001040c  btr     qword ptr [rbx], 0Ah
0x140010411  test    byte ptr [rcx+8], 2
0x140010415  jz      short loc_14001041C
0x140010417  btr     qword ptr [rbx], 0Bh
0x14001041c  test    byte ptr [rcx+8], 1
0x140010420  jz      short loc_140010427
0x140010422  btr     qword ptr [rbx], 0Ch
0x140010427  mov     eax, [rcx]
0x140010429  and     eax, 3
0x14001042c  jz      short loc_14001045E
0x14001042e  sub     eax, 1
0x140010431  jz      short loc_140010452
0x140010433  sub     eax, 1
0x140010436  jz      short loc_140010446
0x140010438  cmp     eax, 1
0x14001043b  jnz     short loc_140010465
0x14001043d  or      qword ptr [rbx], 6000h
0x140010444  jmp     short loc_140010465
0x140010446  btr     qword ptr [rbx], 0Dh
0x14001044b  bts     qword ptr [rbx], 0Eh
0x140010450  jmp     short loc_140010465
0x140010452  btr     qword ptr [rbx], 0Eh
0x140010457  bts     qword ptr [rbx], 0Dh
0x14001045c  jmp     short loc_140010465
0x14001045e  and     qword ptr [rbx], 0FFFFFFFFFFFF9FFFh
0x140010465  cmp     [rbp+arg_30], 0
0x140010469  jz      short loc_140010472
0x14001046b  mov     eax, [rcx+50h]
0x14001046e  mov     [rsi], eax
0x140010470  jmp     short loc_140010479
0x140010472  mov     rax, [rcx+50h]
0x140010476  mov     [rsi], rax
0x140010479  mov     rbx, [rsp+20h+arg_8]
0x14001047e  mov     rsi, [rsp+20h+arg_10]
0x140010483  mov     rdi, [rsp+20h+arg_18]
0x140010488  add     rsp, 20h
0x14001048c  pop     rbp
0x14001048d  retn

// ===== _set_errno_from_matherr @ 0x140010490 =====

0x140010490  sub     rsp, 28h
0x140010494  cmp     ecx, 1
0x140010497  jz      short loc_1400104AE
0x140010499  lea     eax, [rcx-2]
0x14001049c  cmp     eax, 1
0x14001049f  ja      short loc_1400104B9
0x1400104a1  call    _errno
0x1400104a6  mov     dword ptr [rax], 22h ; '"'
0x1400104ac  jmp     short loc_1400104B9
0x1400104ae  call    _errno
0x1400104b3  mov     dword ptr [rax], 21h ; '!'
0x1400104b9  add     rsp, 28h
0x1400104bd  retn

// ===== _clrfp @ 0x1400104c0 =====

0x1400104c0  push    rbx
0x1400104c2  sub     rsp, 20h
0x1400104c6  call    _get_fpsr
0x1400104cb  mov     ebx, eax
0x1400104cd  and     ebx, 3Fh
0x1400104d0  call    _fclrf
0x1400104d5  mov     eax, ebx
0x1400104d7  add     rsp, 20h
0x1400104db  pop     rbx
0x1400104dc  retn

// ===== _ctrlfp @ 0x1400104e0 =====

0x1400104e0  mov     [rsp+arg_10], rbx
0x1400104e5  mov     [rsp+arg_18], rsi
0x1400104ea  push    rdi
0x1400104eb  sub     rsp, 20h
0x1400104ef  mov     rbx, rdx
0x1400104f2  mov     rdi, rcx
0x1400104f5  call    _get_fpsr
0x1400104fa  mov     esi, eax
0x1400104fc  mov     [rsp+28h+arg_8], eax
0x140010500  mov     ecx, ebx
0x140010502  not     ecx
0x140010504  or      ecx, 0FFFF807Fh
0x14001050a  and     ecx, eax
0x14001050c  and     edi, ebx
0x14001050e  or      ecx, edi
0x140010510  mov     [rsp+28h+arg_0], ecx
0x140010514  cmp     cs:byte_14001C8F0, 0
0x14001051b  jz      short loc_140010542
0x14001051d  test    cl, 40h
0x140010520  jz      short loc_140010542
0x140010522  call    _set_fpsr
0x140010527  jmp     short loc_140010540
0x140010529  mov     cs:byte_14001C8F0, 0
0x140010530  mov     ecx, [rsp+28h+arg_0]
0x140010534  and     ecx, 0FFFFFFBFh
0x140010537  call    _set_fpsr
0x14001053c  mov     esi, [rsp+28h+arg_8]
0x140010540  jmp     short loc_14001054A
0x140010542  and     ecx, 0FFFFFFBFh
0x140010545  call    _set_fpsr
0x14001054a  mov     eax, esi
0x14001054c  mov     rbx, [rsp+28h+arg_10]
0x140010551  mov     rsi, [rsp+28h+arg_18]
0x140010556  add     rsp, 20h
0x14001055a  pop     rdi
0x14001055b  retn
0x140010b73  push    rbp; Microsoft VisualC 64bit universal runtime
0x140010b75  sub     rsp, 20h
0x140010b79  mov     rbp, rdx
0x140010b7c  mov     rax, [rcx]
0x140010b7f  cmp     dword ptr [rax], 0C0000005h
0x140010b85  jz      short loc_140010B93
0x140010b87  cmp     dword ptr [rax], 0C000001Dh
0x140010b8d  jz      short loc_140010B93
0x140010b8f  xor     eax, eax
0x140010b91  jmp     short loc_140010B98
0x140010b93  mov     eax, 1
0x140010b98  add     rsp, 20h
0x140010b9c  pop     rbp
0x140010b9d  retn

// ===== _set_statfp @ 0x14001055c =====

0x14001055c  push    rbx
0x14001055e  sub     rsp, 20h
0x140010562  mov     rbx, rcx
0x140010565  call    _get_fpsr
0x14001056a  and     ebx, 3Fh
0x14001056d  or      eax, ebx
0x14001056f  mov     ecx, eax
0x140010571  add     rsp, 20h
0x140010575  pop     rbx
0x140010576  jmp     _set_fpsr

// ===== _statfp @ 0x14001057c =====

0x14001057c  sub     rsp, 28h
0x140010580  call    _get_fpsr
0x140010585  and     eax, 3Fh
0x140010588  add     rsp, 28h
0x14001058c  retn

// ===== _FindPESection @ 0x140010590 =====

0x140010590  movsxd  r8, dword ptr [rcx+3Ch]
0x140010594  xor     r9d, r9d
0x140010597  add     r8, rcx
0x14001059a  mov     r10, rdx
0x14001059d  movzx   eax, word ptr [r8+14h]
0x1400105a2  movzx   r11d, word ptr [r8+6]
0x1400105a7  add     rax, 18h
0x1400105ab  add     rax, r8
0x1400105ae  test    r11d, r11d
0x1400105b1  jz      short loc_1400105D1
0x1400105b3  mov     edx, [rax+0Ch]
0x1400105b6  cmp     r10, rdx
0x1400105b9  jb      short loc_1400105C5
0x1400105bb  mov     ecx, [rax+8]
0x1400105be  add     ecx, edx
0x1400105c0  cmp     r10, rcx
0x1400105c3  jb      short locret_1400105D3
0x1400105c5  inc     r9d
0x1400105c8  add     rax, 28h ; '('
0x1400105cc  cmp     r9d, r11d
0x1400105cf  jb      short loc_1400105B3
0x1400105d1  xor     eax, eax
0x1400105d3  retn

// ===== _IsNonwritableInCurrentImage @ 0x1400105e0 =====

0x1400105e0  mov     [rsp+arg_0], rbx
0x1400105e5  push    rdi
0x1400105e6  sub     rsp, 20h
0x1400105ea  mov     rbx, rcx
0x1400105ed  lea     rdi, cs:140000000h
0x1400105f4  mov     rcx, rdi
0x1400105f7  call    _ValidateImageBase
0x1400105fc  test    eax, eax
0x1400105fe  jz      short loc_140010622
0x140010600  sub     rbx, rdi
0x140010603  mov     rdx, rbx
0x140010606  mov     rcx, rdi
0x140010609  call    _FindPESection
0x14001060e  test    rax, rax
0x140010611  jz      short loc_140010622
0x140010613  mov     eax, [rax+24h]
0x140010616  shr     eax, 1Fh
0x140010619  not     eax
0x14001061b  and     eax, 1
0x14001061e  jmp     short loc_140010622
0x140010620  xor     eax, eax
0x140010622  mov     rbx, [rsp+28h+arg_0]
0x140010627  add     rsp, 20h
0x14001062b  pop     rdi
0x14001062c  retn
0x140010ba0  push    rbp; Microsoft VisualC v14 64bit runtime
0x140010ba2  sub     rsp, 20h
0x140010ba6  mov     rbp, rdx
0x140010ba9  mov     rax, [rcx]
0x140010bac  xor     ecx, ecx
0x140010bae  cmp     dword ptr [rax], 0C0000005h
0x140010bb4  setz    cl
0x140010bb7  mov     eax, ecx
0x140010bb9  add     rsp, 20h
0x140010bbd  pop     rbp
0x140010bbe  retn

// ===== _ValidateImageBase @ 0x140010630 =====

0x140010630  mov     eax, 5A4Dh
0x140010635  cmp     [rcx], ax
0x140010638  jnz     short loc_14001065A
0x14001063a  movsxd  rax, dword ptr [rcx+3Ch]
0x14001063e  add     rax, rcx
0x140010641  cmp     dword ptr [rax], 4550h
0x140010647  jnz     short loc_14001065A
0x140010649  mov     ecx, 20Bh
0x14001064e  cmp     [rax+18h], cx
0x140010652  jnz     short loc_14001065A
0x140010654  mov     eax, 1
0x140010659  retn
0x14001065a  xor     eax, eax
0x14001065c  retn

// ===== __GSHandlerCheck @ 0x140010660 =====

0x140010660  sub     rsp, 28h
0x140010664  mov     r8, [r9+38h]
0x140010668  mov     rcx, rdx
0x14001066b  mov     rdx, r9
0x14001066e  call    __GSHandlerCheckCommon
0x140010673  mov     eax, 1
0x140010678  add     rsp, 28h
0x14001067c  retn

// ===== __GSHandlerCheckCommon @ 0x140010680 =====

0x140010680  push    rbx
0x140010682  mov     r11d, [r8]
0x140010685  mov     rbx, rdx
0x140010688  and     r11d, 0FFFFFFF8h
0x14001068c  mov     r9, rcx
0x14001068f  test    byte ptr [r8], 4
0x140010693  mov     r10, rcx
0x140010696  jz      short loc_1400106AB
0x140010698  mov     eax, [r8+8]
0x14001069c  movsxd  r10, dword ptr [r8+4]
0x1400106a0  neg     eax
0x1400106a2  add     r10, rcx
0x1400106a5  movsxd  rcx, eax
0x1400106a8  and     r10, rcx
0x1400106ab  movsxd  rax, r11d
0x1400106ae  mov     rdx, [rax+r10]
0x1400106b2  mov     rax, [rbx+10h]
0x1400106b6  mov     ecx, [rax+8]
0x1400106b9  mov     rax, [rbx+8]
0x1400106bd  test    byte ptr [rcx+rax+3], 0Fh
0x1400106c2  jz      short loc_1400106CF
0x1400106c4  movzx   eax, byte ptr [rcx+rax+3]
0x1400106c9  and     eax, 0FFFFFFF0h
0x1400106cc  add     r9, rax
0x1400106cf  xor     r9, rdx
0x1400106d2  mov     rcx, r9; StackCookie
0x1400106d5  pop     rbx
0x1400106d6  jmp     __security_check_cookie

// ===== _alloca_probe @ 0x1400106f0 =====

0x1400106f0  sub     rsp, 10h
0x1400106f4  mov     [rsp+10h+var_10], r10
0x1400106f8  mov     [rsp+10h+var_8], r11
0x1400106fd  xor     r11, r11
0x140010700  lea     r10, [rsp+10h+arg_0]
0x140010705  sub     r10, rax
0x140010708  cmovb   r10, r11
0x14001070c  mov     r11, gs:10h
0x140010715  cmp     r10, r11
0x140010718  bnd jnb short cs20
0x14001071b  and     r10w, 0F000h
0x140010721  lea     r11, [r11-1000h]
0x140010728  mov     byte ptr [r11], 0
0x14001072c  cmp     r10, r11
0x14001072f  bnd jnz short cs10
0x140010732  mov     r10, [rsp+10h+var_10]
0x140010736  mov     r11, [rsp+10h+var_8]
0x14001073b  add     rsp, 10h
0x14001073f  bnd retn

// ===== memcmp @ 0x140010760 =====

0x140010760  sub     rdx, rcx
0x140010763  cmp     r8, 8
0x140010767  jb      short mcmp30
0x140010769  test    cl, 7
0x14001076c  jz      short mcmp20
0x14001076e  xchg    ax, ax
0x140010770  mov     al, [rcx]
0x140010772  cmp     al, [rcx+rdx]
0x140010775  jnz     short mcmp_not_equal
0x140010777  inc     rcx
0x14001077a  dec     r8
0x14001077d  test    cl, 7
0x140010780  jnz     short mcmp10
0x140010782  mov     r9, r8
0x140010785  shr     r9, 3
0x140010789  jnz     short mcmp50
0x14001078b  test    r8, r8
0x14001078e  jz      short mcmp_equal
0x140010790  mov     al, [rcx]
0x140010792  cmp     al, [rcx+rdx]
0x140010795  jnz     short mcmp_not_equal
0x140010797  inc     rcx
0x14001079a  dec     r8
0x14001079d  jnz     short mcmp40
0x14001079f  xor     rax, rax
0x1400107a2  retn
0x1400107a3  sbb     eax, eax
0x1400107a5  sbb     eax, 0FFFFFFFFh
0x1400107a8  retn
0x1400107aa  shr     r9, 2
0x1400107ae  jz      short mcmp70
0x1400107b0  mov     rax, [rcx]
0x1400107b3  cmp     rax, [rcx+rdx]
0x1400107b7  jnz     short mcmp_adjust0
0x1400107b9  mov     rax, [rcx+8]
0x1400107bd  cmp     rax, [rcx+rdx+8]
0x1400107c2  jnz     short mcmp_adjust8
0x1400107c4  mov     rax, [rcx+10h]
0x1400107c8  cmp     rax, [rcx+rdx+10h]
0x1400107cd  jnz     short mcmp_adjust16
0x1400107cf  mov     rax, [rcx+18h]
0x1400107d3  cmp     rax, [rcx+rdx+18h]
0x1400107d8  jnz     short mcmp_adjust24
0x1400107da  add     rcx, 20h ; ' '
0x1400107de  dec     r9
0x1400107e1  jnz     short mcmp60
0x1400107e3  and     r8, 1Fh
0x1400107e7  mov     r9, r8
0x1400107ea  shr     r9, 3
0x1400107ee  jz      short mcmp30
0x1400107f0  mov     rax, [rcx]
0x1400107f3  cmp     rax, [rcx+rdx]
0x1400107f7  jnz     short mcmp_adjust0
0x1400107f9  add     rcx, 8
0x1400107fd  dec     r9
0x140010800  jnz     short mcmp80
0x140010802  and     r8, 7
0x140010806  jmp     short mcmp30
0x140010808  add     rcx, 8
0x14001080c  add     rcx, 8
0x140010810  add     rcx, 8
0x140010814  mov     rcx, [rdx+rcx]
0x140010818  bswap   rax
0x14001081b  bswap   rcx
0x14001081e  cmp     rax, rcx
0x140010821  sbb     eax, eax
0x140010823  sbb     eax, 0FFFFFFFFh
0x140010826  retn

// ===== strrchr @ 0x140010828 =====

0x140010828  sub     rsp, 18h
0x14001082c  xor     r8d, r8d
0x14001082f  mov     r9, rcx
0x140010832  test    edx, edx
0x140010834  jnz     short loc_14001087E
0x140010836  and     r9d, 0Fh
0x14001083a  mov     rdx, rcx
0x14001083d  and     rdx, 0FFFFFFFFFFFFFFF0h
0x140010841  mov     ecx, r9d
0x140010844  or      r9d, 0FFFFFFFFh
0x140010848  xorps   xmm1, xmm1
0x14001084b  shl     r9d, cl
0x14001084e  movdqu  xmm0, xmmword ptr [rdx]
0x140010852  pcmpeqb xmm0, xmm1
0x140010856  pmovmskb eax, xmm0
0x14001085a  and     eax, r9d
0x14001085d  jnz     short loc_140010873
0x14001085f  add     rdx, 10h
0x140010863  movdqu  xmm0, xmmword ptr [rdx]
0x140010867  pcmpeqb xmm0, xmm1
0x14001086b  pmovmskb eax, xmm0
0x14001086f  test    eax, eax
0x140010871  jz      short loc_14001085F
0x140010873  bsf     eax, eax
0x140010876  add     rax, rdx
0x140010879  jmp     loc_140010923
0x14001087e  cmp     cs:dword_14001C018, 2
0x140010885  jge     loc_140010941
0x14001088b  movzx   eax, dl
0x14001088e  mov     r10, r9
0x140010891  and     r9d, 0Fh
0x140010895  and     r10, 0FFFFFFFFFFFFFFF0h
0x140010899  mov     ecx, eax
0x14001089b  xorps   xmm2, xmm2
0x14001089e  shl     ecx, 8
0x1400108a1  or      ecx, eax
0x1400108a3  movd    xmm0, ecx
0x1400108a7  mov     ecx, r9d
0x1400108aa  pshuflw xmm1, xmm0, 0
0x1400108af  or      r9d, 0FFFFFFFFh
0x1400108b3  xorps   xmm0, xmm0
0x1400108b6  shl     r9d, cl
0x1400108b9  pcmpeqb xmm0, xmmword ptr [r10]
0x1400108be  pmovmskb ecx, xmm0
0x1400108c2  pshufd  xmm3, xmm1, 0
0x1400108c7  movdqa  xmm0, xmm3
0x1400108cb  pcmpeqb xmm0, xmmword ptr [r10]
0x1400108d0  pmovmskb edx, xmm0
0x1400108d4  and     edx, r9d
0x1400108d7  and     ecx, r9d
0x1400108da  jnz     short loc_14001090A
0x1400108dc  bsr     ecx, edx
0x1400108df  movdqa  xmm1, xmm2
0x1400108e3  movdqa  xmm0, xmm3
0x1400108e7  add     rcx, r10
0x1400108ea  test    edx, edx
0x1400108ec  cmovnz  r8, rcx
0x1400108f0  add     r10, 10h
0x1400108f4  pcmpeqb xmm1, xmmword ptr [r10]
0x1400108f9  pcmpeqb xmm0, xmmword ptr [r10]
0x1400108fe  pmovmskb ecx, xmm1
0x140010902  pmovmskb edx, xmm0
0x140010906  test    ecx, ecx
0x140010908  jz      short loc_1400108DC
0x14001090a  mov     eax, ecx
0x14001090c  neg     eax
0x14001090e  and     eax, ecx
0x140010910  dec     eax
0x140010912  and     edx, eax
0x140010914  bsr     ecx, edx
0x140010917  add     rcx, r10
0x14001091a  test    edx, edx
0x14001091c  cmovnz  r8, rcx
0x140010920  mov     rax, r8
0x140010923  add     rsp, 18h
0x140010927  retn
0x140010928  movsx   eax, byte ptr [r9]
0x14001092c  mov     rcx, r9
0x14001092f  cmp     eax, edx
0x140010931  cmovnz  rcx, r8
0x140010935  cmp     byte ptr [r9], 0
0x140010939  mov     r8, rcx
0x14001093c  jz      short loc_14001096C
0x14001093e  inc     r9
0x140010941  test    r9b, 0Fh
0x140010945  jnz     short loc_140010928
0x140010947  movzx   eax, dl
0x14001094a  movd    xmm0, eax
0x14001094e  pcmpistri xmm0, xmmword ptr [r9], 40h ; '@'
0x140010955  jnb     short loc_140010964
0x140010957  movsxd  r8, ecx
0x14001095a  add     r8, r9
0x14001095d  pcmpistri xmm0, xmmword ptr [r9], 40h ; '@'
0x140010964  jz      short loc_140010920
0x140010966  add     r9, 10h
0x14001096a  jmp     short loc_14001094E
0x14001096c  mov     rax, rcx
0x14001096f  jmp     short loc_140010923

// ===== _guard_dispatch_icall_nop @ 0x140010990 =====

0x140010990  jmp     rax


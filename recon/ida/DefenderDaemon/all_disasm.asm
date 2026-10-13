// ===== sub_140001000 @ 0x140001000 =====

0x140001000  sub     rsp, 28h
0x140001004  lea     rcx, String; "TaskbarCreated"
0x14000100b  call    cs:RegisterWindowMessageW; USER32
0x140001011  mov     cs:dword_140020D80, eax
0x140001017  add     rsp, 28h
0x14000101b  retn

// ===== sub_140001020 @ 0x140001020 =====

0x140001020  sub     rsp, 28h
0x140001024  call    sub_140004FC0
0x140001029  mov     cs:dword_140021390, eax
0x14000102f  add     rsp, 28h
0x140001033  retn

// ===== sub_140001040 @ 0x140001040 =====

0x140001040  mov     [rsp+arg_8], rbx
0x140001045  mov     [rsp+arg_10], rsi
0x14000104a  push    rdi
0x14000104b  sub     rsp, 20h
0x14000104f  mov     rbx, 0FFFFFFFFFFFFFFFFh
0x140001056  mov     rdi, rcx
0x140001059  mov     rdx, rbx
0x14000105c  nop     dword ptr [rax+00h]
0x140001060  inc     rdx
0x140001063  cmp     word ptr [rcx+rdx*2], 0
0x140001068  jnz     short loc_140001060
0x14000106a  inc     rdx
0x14000106d  mov     eax, 2
0x140001072  mul     rdx
0x140001075  cmovo   rax, rbx
0x140001079  mov     rcx, rax; Size
0x14000107c  call    j_??2@YAPEAX_K@Z; operator new(unsigned __int64)
0x140001081  mov     rsi, rax
0x140001084  cmp     word ptr [rdi+rbx*2+2], 0
0x14000108a  lea     rbx, [rbx+1]
0x14000108e  jnz     short loc_140001084
0x140001090  lea     rdx, [rbx+1]; SizeInWords
0x140001094  mov     r8, rdi; Source
0x140001097  mov     rcx, rsi; Destination
0x14000109a  call    wcscpy_s
0x14000109f  mov     edi, 5Ch ; '\'
0x1400010a4  mov     rcx, rsi; Str
0x1400010a7  mov     edx, edi; Ch
0x1400010a9  call    wcschr
0x1400010ae  mov     rbx, rax
0x1400010b1  test    rax, rax
0x1400010b4  jz      short loc_1400010E9
0x1400010b6  mov     [rsp+28h+arg_0], rbp
0x1400010bb  xor     ebp, ebp
0x1400010bd  nop     dword ptr [rax]
0x1400010c0  xor     edx, edx; lpSecurityAttributes
0x1400010c2  mov     [rbx], bp
0x1400010c5  mov     rcx, rsi; lpPathName
0x1400010c8  call    cs:CreateDirectoryW; KERNEL32
0x1400010ce  mov     edx, edi; Ch
0x1400010d0  mov     [rbx], di
0x1400010d3  lea     rcx, [rbx+2]; Str
0x1400010d7  call    wcschr
0x1400010dc  mov     rbx, rax
0x1400010df  test    rax, rax
0x1400010e2  jnz     short loc_1400010C0
0x1400010e4  mov     rbp, [rsp+28h+arg_0]
0x1400010e9  xor     edx, edx; lpSecurityAttributes
0x1400010eb  mov     rcx, rsi; lpPathName
0x1400010ee  call    cs:CreateDirectoryW; KERNEL32
0x1400010f4  mov     rcx, rsi; Block
0x1400010f7  mov     ebx, eax
0x1400010f9  call    j_j_j__free_base
0x1400010fe  mov     rsi, [rsp+28h+arg_10]
0x140001103  mov     eax, ebx
0x140001105  mov     rbx, [rsp+28h+arg_8]
0x14000110a  add     rsp, 20h
0x14000110e  pop     rdi
0x14000110f  retn

// ===== sub_140001110 @ 0x140001110 =====

0x140001110  push    rbx
0x140001112  sub     rsp, 480h
0x140001119  mov     rax, cs:__security_cookie
0x140001120  xor     rax, rsp
0x140001123  mov     [rsp+488h+var_18], rax
0x14000112b  mov     rax, 5C003A0020h
0x140001135  movzx   ebx, cx
0x140001138  mov     qword ptr [rsp+488h+RootPathName], rax
0x14000113d  mov     [rsp+488h+RootPathName], cx
0x140001142  xor     ecx, ecx; dwErrCode
0x140001144  call    cs:SetLastError; KERNEL32
0x14000114a  lea     rcx, [rsp+488h+RootPathName]; lpRootPathName
0x14000114f  call    cs:GetDriveTypeW; KERNEL32
0x140001155  add     eax, 0FFFFFFFEh
0x140001158  cmp     eax, 1
0x14000115b  ja      loc_140001297
0x140001161  call    cs:GetLastError; KERNEL32
0x140001167  test    eax, eax
0x140001169  jnz     loc_140001297
0x14000116f  mov     [rsp+488h+nFileSystemNameSize], 10h; nFileSystemNameSize
0x140001177  lea     rax, [rsp+488h+FileSystemNameBuffer]
0x14000117c  mov     [rsp+488h+lpFileSystemNameBuffer], rax; lpFileSystemNameBuffer
0x140001181  lea     rcx, [rsp+488h+RootPathName]; lpRootPathName
0x140001186  xor     eax, eax
0x140001188  xor     r9d, r9d; lpVolumeSerialNumber
0x14000118b  mov     [rsp+488h+lpFileSystemFlags], rax; lpFileSystemFlags
0x140001190  xor     r8d, r8d; nVolumeNameSize
0x140001193  xor     edx, edx; lpVolumeNameBuffer
0x140001195  mov     [rsp+488h+lpMaximumComponentLength], rax; lpMaximumComponentLength
0x14000119a  call    cs:GetVolumeInformationW; KERNEL32
0x1400011a0  test    eax, eax
0x1400011a2  jz      loc_140001297
0x1400011a8  lea     rdx, aFat; "FAT"
0x1400011af  lea     rcx, [rsp+488h+FileSystemNameBuffer]; String1
0x1400011b4  call    _wcsicmp
0x1400011b9  test    eax, eax
0x1400011bb  jz      short loc_140001215
0x1400011bd  lea     rdx, aFat32; "FAT32"
0x1400011c4  lea     rcx, [rsp+488h+FileSystemNameBuffer]; String1
0x1400011c9  call    _wcsicmp
0x1400011ce  test    eax, eax
0x1400011d0  jz      short loc_140001215
0x1400011d2  lea     rdx, aFat16; "FAT16"
0x1400011d9  lea     rcx, [rsp+488h+FileSystemNameBuffer]; String1
0x1400011de  call    _wcsicmp
0x1400011e3  test    eax, eax
0x1400011e5  jz      short loc_140001215
0x1400011e7  lea     rdx, aExfat; "EXFAT"
0x1400011ee  lea     rcx, [rsp+488h+FileSystemNameBuffer]; String1
0x1400011f3  call    _wcsicmp
0x1400011f8  test    eax, eax
0x1400011fa  jz      short loc_140001215
0x1400011fc  lea     rdx, aNtfs; "NTFS"
0x140001203  lea     rcx, [rsp+488h+FileSystemNameBuffer]; String1
0x140001208  call    _wcsicmp
0x14000120d  test    eax, eax
0x14000120f  jnz     loc_140001297
0x140001215  mov     rax, 5C003A0043h
0x14000121f  lea     rdx, [rsp+488h+szVolumeName]; lpszVolumeName
0x140001227  mov     qword ptr [rsp+488h+szVolumeMountPoint], rax
0x14000122c  lea     rcx, [rsp+488h+szVolumeMountPoint]; lpszVolumeMountPoint
0x140001231  mov     r8d, 100h; cchBufferLength
0x140001237  mov     [rsp+488h+szVolumeMountPoint], bx
0x14000123c  call    cs:GetVolumeNameForVolumeMountPointW; KERNEL32
0x140001242  test    eax, eax
0x140001244  jz      short loc_140001297
0x140001246  mov     edx, 100h; cchBufferLength
0x14000124b  lea     rcx, [rsp+488h+String2]; lpszVolumeName
0x140001250  call    cs:FindFirstVolumeW; KERNEL32
0x140001256  mov     rbx, rax
0x140001259  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x14000125d  jz      short loc_140001297
0x14000125f  nop
0x140001260  lea     rdx, [rsp+488h+String2]; String2
0x140001265  lea     rcx, [rsp+488h+szVolumeName]; String1
0x14000126d  call    _wcsicmp
0x140001272  mov     rcx, rbx; hFindVolume
0x140001275  test    eax, eax
0x140001277  jz      short loc_1400012B2
0x140001279  mov     r8d, 100h; cchBufferLength
0x14000127f  lea     rdx, [rsp+488h+String2]; lpszVolumeName
0x140001284  call    cs:FindNextVolumeW; KERNEL32
0x14000128a  test    eax, eax
0x14000128c  jnz     short loc_140001260
0x14000128e  mov     rcx, rbx; hFindVolume
0x140001291  call    cs:FindVolumeClose; KERNEL32
0x140001297  xor     eax, eax
0x140001299  mov     rcx, [rsp+488h+var_18]
0x1400012a1  xor     rcx, rsp; StackCookie
0x1400012a4  call    __security_check_cookie
0x1400012a9  add     rsp, 480h
0x1400012b0  pop     rbx
0x1400012b1  retn
0x1400012b2  call    cs:FindVolumeClose; KERNEL32
0x1400012b8  mov     eax, 1
0x1400012bd  jmp     short loc_140001299

// ===== sub_1400012C0 @ 0x1400012c0 =====

0x1400012c0  lea     rax, unk_140020C10
0x1400012c7  retn

// ===== swprintf @ 0x1400012d0 =====

0x1400012d0  mov     [rsp+arg_10], r8
0x1400012d5  mov     [rsp+arg_18], r9
0x1400012da  push    rbx
0x1400012db  push    rbp
0x1400012dc  push    rsi
0x1400012dd  push    rdi
0x1400012de  sub     rsp, 38h
0x1400012e2  mov     rsi, r8
0x1400012e5  lea     rbp, [rsp+58h+arg_18]
0x1400012ea  mov     rbx, rdx
0x1400012ed  mov     rdi, rcx
0x1400012f0  call    sub_1400012C0
0x1400012f5  mov     [rsp+58h+var_30], rbp; __int64
0x1400012fa  mov     r9, rsi; int
0x1400012fd  mov     r8, rbx; int
0x140001300  mov     [rsp+58h+var_38], 0; struct __crt_locale_pointers *
0x140001309  mov     rdx, rdi; int
0x14000130c  mov     rcx, [rax]; int
0x14000130f  call    unknown_libname_15; Microsoft VisualC 64bit universal runtime
0x140001314  test    eax, eax
0x140001316  mov     ecx, 0FFFFFFFFh
0x14000131b  cmovs   eax, ecx
0x14000131e  add     rsp, 38h
0x140001322  pop     rdi
0x140001323  pop     rsi
0x140001324  pop     rbp
0x140001325  pop     rbx
0x140001326  retn

// ===== sub_140001330 @ 0x140001330 =====

0x140001330  mov     [rsp+arg_8], rbx
0x140001335  mov     [rsp+arg_10], rsi
0x14000133a  push    rdi
0x14000133b  sub     rsp, 290h
0x140001342  mov     rax, cs:__security_cookie
0x140001349  xor     rax, rsp
0x14000134c  mov     [rsp+298h+var_18], rax
0x140001354  mov     rdi, rcx
0x140001357  lea     rdx, [rsp+298h+Filename]; lpFilename
0x14000135c  xor     ecx, ecx; hModule
0x14000135e  mov     r8d, 104h; nSize
0x140001364  call    cs:GetModuleFileNameW; KERNEL32
0x14000136a  mov     edx, 5Ch ; '\'; Ch
0x14000136f  lea     rcx, [rsp+298h+Filename]; Str
0x140001374  call    wcsrchr
0x140001379  xor     esi, esi
0x14000137b  test    rax, rax
0x14000137e  jz      short loc_140001383
0x140001380  mov     [rax], si
0x140001383  lea     r8, aShadowBmp; "\\shadow.bmp"
0x14000138a  mov     edx, 104h; SizeInWords
0x14000138f  lea     rcx, [rsp+298h+Filename]; Destination
0x140001394  call    wcscat_s
0x140001399  xor     r9d, r9d; cx
0x14000139c  mov     [rsp+298h+fuLoad], 10h; fuLoad
0x1400013a4  xor     r8d, r8d; type
0x1400013a7  mov     [rsp+298h+cy], esi; cy
0x1400013ab  lea     rdx, [rsp+298h+Filename]; name
0x1400013b0  xor     ecx, ecx; hInst
0x1400013b2  call    cs:LoadImageW; USER32
0x1400013b8  mov     rbx, rax
0x1400013bb  test    rax, rax
0x1400013be  jnz     short loc_1400013D5
0x1400013c0  mov     rcx, cs:hInstance; hInstance
0x1400013c7  mov     edx, 83h; lpBitmapName
0x1400013cc  call    cs:LoadBitmapW; USER32
0x1400013d2  mov     rbx, rax
0x1400013d5  lea     r8, [rsp+298h+pv]; pv
0x1400013da  mov     edx, 20h ; ' '; c
0x1400013df  mov     rcx, rbx; h
0x1400013e2  call    cs:GetObjectW; GDI32
0x1400013e8  mov     rcx, rbx; ho
0x1400013eb  call    cs:DeleteObject; GDI32
0x1400013f1  xor     r8d, r8d; hWndParent
0x1400013f4  mov     qword ptr [rsp+298h+cy], rsi; dwInitParam
0x1400013f9  lea     r9, DialogFunc; lpDialogFunc
0x140001400  mov     rcx, rdi; hInstance
0x140001403  lea     edx, [r8+66h]; lpTemplateName
0x140001407  call    cs:CreateDialogParamW; USER32
0x14000140d  mov     rcx, rax; hWnd
0x140001410  mov     edx, 0FFFFFFECh; nIndex
0x140001415  mov     rbx, rax
0x140001418  call    cs:GetWindowLongW; USER32
0x14000141e  mov     edx, 0FFFFFFECh; nIndex
0x140001423  mov     rcx, rbx; hWnd
0x140001426  bts     eax, 7
0x14000142a  mov     r8d, eax; dwNewLong
0x14000142d  call    cs:SetWindowLongW; USER32
0x140001433  mov     ecx, [rsp+298h+var_250]
0x140001437  xor     r9d, r9d; Y
0x14000143a  mov     eax, [rsp+298h+var_254]
0x14000143e  inc     ecx
0x140001440  mov     [rsp+298h+uFlags], 2; uFlags
0x140001448  xor     r8d, r8d; X
0x14000144b  mov     [rsp+298h+fuLoad], ecx; cy
0x14000144f  mov     rcx, rbx; hWnd
0x140001452  lea     rdx, [r9-1]; hWndInsertAfter
0x140001456  mov     [rsp+298h+cy], eax; cx
0x14000145a  call    cs:SetWindowPos; USER32
0x140001460  mov     rcx, rbx; hWnd
0x140001463  call    sub_140002AF0
0x140001468  mov     edx, 5; nCmdShow
0x14000146d  mov     rcx, rbx; hWnd
0x140001470  call    cs:ShowWindow; USER32
0x140001476  mov     rcx, rbx; hWnd
0x140001479  call    cs:SetForegroundWindow; USER32
0x14000147f  lea     rdx, [rsp+298h+Rect]; lpRect
0x140001484  mov     rcx, rbx; hWnd
0x140001487  call    cs:GetClientRect; USER32
0x14000148d  mov     r9d, [rsp+298h+Rect.bottom]; y2
0x140001492  xor     edx, edx; y1
0x140001494  mov     r8d, [rsp+298h+Rect.right]; x2
0x140001499  xor     ecx, ecx; x1
0x14000149b  mov     [rsp+298h+fuLoad], 5; h
0x1400014a3  mov     [rsp+298h+cy], 5; w
0x1400014ab  call    cs:CreateRoundRectRgn; GDI32
0x1400014b1  xor     r8d, r8d; bRedraw
0x1400014b4  mov     rcx, rbx; hWnd
0x1400014b7  mov     rdx, rax; hRgn
0x1400014ba  call    cs:SetWindowRgn; USER32
0x1400014c0  mov     rax, rbx
0x1400014c3  mov     rcx, [rsp+298h+var_18]
0x1400014cb  xor     rcx, rsp; StackCookie
0x1400014ce  call    __security_check_cookie
0x1400014d3  lea     r11, [rsp+298h+var_8]
0x1400014db  mov     rbx, [r11+18h]
0x1400014df  mov     rsi, [r11+20h]
0x1400014e3  mov     rsp, r11
0x1400014e6  pop     rdi
0x1400014e7  retn

// ===== sub_1400014F0 @ 0x1400014f0 =====

0x1400014f0  push    rbp
0x1400014f2  push    rbx
0x1400014f3  push    rsi
0x1400014f4  push    rdi
0x1400014f5  push    r12
0x1400014f7  lea     rbp, [rsp-2F90h]
0x1400014ff  mov     eax, 3090h
0x140001504  call    _alloca_probe
0x140001509  sub     rsp, rax
0x14000150c  mov     rax, cs:__security_cookie
0x140001513  xor     rax, rsp
0x140001516  mov     [rbp+2FB0h+var_30], rax
0x14000151d  xor     edi, edi
0x14000151f  mov     [rsp+30B0h+var_3068], edx
0x140001523  mov     [rsp+30B0h+var_3058], rcx
0x140001528  mov     eax, edx
0x14000152a  mov     r12, rcx
0x14000152d  cmp     edx, 312h
0x140001533  ja      loc_14000170A
0x140001539  jz      loc_1400016AD
0x14000153f  sub     eax, 1Ah
0x140001542  jz      loc_1400016F0
0x140001548  sub     eax, 0F6h
0x14000154d  jz      loc_1400016B9
0x140001553  sub     eax, 1
0x140001556  jz      short loc_14000156D
0x140001558  cmp     eax, 2
0x14000155b  jnz     loc_140001AE6
0x140001561  xor     ecx, ecx
0x140001563  call    sub_1400034C0
0x140001568  jmp     loc_140001AE6
0x14000156d  movzx   ecx, r8w
0x140001571  sub     ecx, 31E3h
0x140001577  jz      loc_1400016AD
0x14000157d  sub     ecx, 1
0x140001580  jz      loc_140001655
0x140001586  sub     ecx, 1
0x140001589  jz      short loc_1400015C6
0x14000158b  sub     ecx, 1
0x14000158e  jz      short loc_1400015A8
0x140001590  cmp     ecx, 1
0x140001593  jnz     loc_140001AE6
0x140001599  mov     ecx, 1
0x14000159e  call    sub_1400025D0
0x1400015a3  jmp     loc_140001AE6
0x1400015a8  mov     rcx, cs:qword_140020C30
0x1400015af  xor     edx, edx
0x1400015b1  mov     cs:byte_140020C59, 1
0x1400015b8  lea     r8d, [rdx+2]
0x1400015bc  call    sub_140001DB0
0x1400015c1  jmp     loc_140001AE6
0x1400015c6  lea     rax, [rsp+30B0h+NumberOfFreeClusters]
0x1400015cb  mov     [rsp+30B0h+NumberOfFreeClusters], 208h
0x1400015d3  mov     [rsp+30B0h+pcbData], rax; pcbData
0x1400015d8  lea     r9, [rsp+30B0h+pdwType]; pdwType
0x1400015dd  lea     rax, [rbp+2FB0h+Filename]
0x1400015e1  mov     rcx, 0FFFFFFFF80000002h; hkey
0x1400015e8  lea     r8, pszValue; "Path"
0x1400015ef  mov     [rsp+30B0h+pvData], rax; pvData
0x1400015f4  lea     rdx, pszSubKey; "SOFTWARE\\Shadow Defender"
0x1400015fb  call    cs:SHGetValueW; SHLWAPI
0x140001601  test    eax, eax
0x140001603  jz      short loc_140001628
0x140001605  mov     r8d, 104h; nSize
0x14000160b  lea     rdx, [rbp+2FB0h+Filename]; lpFilename
0x14000160f  xor     ecx, ecx; hModule
0x140001611  call    cs:GetModuleFileNameW; KERNEL32
0x140001617  mov     edx, 5Ch ; '\'; Ch
0x14000161c  lea     rcx, [rbp+2FB0h+Filename]; Str
0x140001620  call    wcsrchr
0x140001625  mov     [rax], di
0x140001628  lea     r8, aHelpChm; "\\Help.chm"
0x14000162f  mov     edx, 104h; SizeInWords
0x140001634  lea     rcx, [rbp+2FB0h+Filename]; Destination
0x140001638  call    wcscat_s
0x14000163d  xor     r9d, r9d
0x140001640  lea     rdx, [rbp+2FB0h+Filename]
0x140001644  mov     rcx, r12
0x140001647  lea     r8d, [r9+1]
0x14000164b  call    sub_140003C1C
0x140001650  jmp     loc_140001AE6
0x140001655  mov     rcx, cs:hWnd; hWnd
0x14000165c  test    rcx, rcx
0x14000165f  jz      short loc_14000167B
0x140001661  call    cs:DestroyWindow; USER32
0x140001667  mov     al, 1
0x140001669  mov     cs:hWnd, rdi
0x140001670  mov     cs:byte_140020C58, al
0x140001676  jmp     loc_140001AE6
0x14000167b  call    sub_1400023E0
0x140001680  test    eax, eax
0x140001682  jz      short loc_1400016A0
0x140001684  cmp     cs:hWnd, rdi
0x14000168b  jnz     short loc_1400016A0
0x14000168d  mov     rcx, cs:hInstance; hInstance
0x140001694  call    sub_140001330
0x140001699  mov     cs:hWnd, rax
0x1400016a0  xor     al, al
0x1400016a2  mov     cs:byte_140020C58, al
0x1400016a8  jmp     loc_140001AE6
0x1400016ad  xor     ecx, ecx
0x1400016af  call    sub_1400025D0
0x1400016b4  jmp     loc_140001AE6
0x1400016b9  cmp     cs:byte_140020C59, dil
0x1400016c0  jnz     short loc_1400016D5
0x1400016c2  mov     edx, edi
0x1400016c4  cmp     cs:dword_140020C5C, edx
0x1400016ca  setnz   dl
0x1400016cd  xor     r8d, r8d
0x1400016d0  call    sub_140001DB0
0x1400016d5  xor     r9d, r9d; lpTimerFunc
0x1400016d8  mov     r8d, 7530h; uElapse
0x1400016de  mov     rcx, r12; hWnd
0x1400016e1  lea     edx, [r9+1]; nIDEvent
0x1400016e5  call    cs:SetTimer; USER32
0x1400016eb  jmp     loc_140001AE6
0x1400016f0  mov     rcx, cs:hWnd; hWnd
0x1400016f7  test    rcx, rcx
0x1400016fa  jz      loc_140001AE6
0x140001700  call    sub_140002AF0
0x140001705  jmp     loc_140001AE6
0x14000170a  sub     eax, 464h
0x14000170f  jz      loc_140001B3A
0x140001715  sub     eax, 2
0x140001718  jz      loc_140001897
0x14000171e  sub     eax, 1
0x140001721  jz      loc_1400017DD
0x140001727  cmp     eax, 14h
0x14000172a  jnz     loc_140001AE6
0x140001730  test    r8, r8
0x140001733  jnz     short loc_140001776
0x140001735  mov     rcx, cs:hWnd; hWnd
0x14000173c  test    rcx, rcx
0x14000173f  jz      short loc_140001747
0x140001741  call    cs:DestroyWindow; USER32
0x140001747  xor     edx, edx
0x140001749  mov     rcx, r12
0x14000174c  lea     r8d, [rdx+2]
0x140001750  call    sub_140001DB0
0x140001755  xor     edx, edx; id
0x140001757  mov     rcx, r12; hWnd
0x14000175a  call    cs:UnregisterHotKey; USER32
0x140001760  mov     rcx, r12; hWnd
0x140001763  call    cs:DestroyWindow; USER32
0x140001769  xor     ecx, ecx; nExitCode
0x14000176b  call    cs:PostQuitMessage; USER32
0x140001771  jmp     loc_140001AE6
0x140001776  cmp     r8, 1
0x14000177a  jz      short loc_14000179E
0x14000177c  mov     rcx, cs:hWnd; hWnd
0x140001783  test    rcx, rcx
0x140001786  jz      loc_140001AE6
0x14000178c  call    cs:DestroyWindow; USER32
0x140001792  mov     cs:hWnd, rdi
0x140001799  jmp     loc_140001AE6
0x14000179e  call    sub_1400023E0
0x1400017a3  test    eax, eax
0x1400017a5  jz      loc_140001AE6
0x1400017ab  cmp     cs:byte_140020C58, dil
0x1400017b2  jnz     loc_140001AE6
0x1400017b8  cmp     cs:hWnd, rdi
0x1400017bf  jnz     loc_140001AE6
0x1400017c5  mov     rcx, cs:hInstance; hInstance
0x1400017cc  call    sub_140001330
0x1400017d1  mov     cs:hWnd, rax
0x1400017d8  jmp     loc_140001AE6
0x1400017dd  xor     edx, edx
0x1400017df  lea     rcx, [rbp+2FB0h+Filename]
0x1400017e3  cmp     r8, 1
0x1400017e7  mov     r8d, 1000h
0x1400017ed  jnz     short loc_140001840
0x1400017ef  call    sub_140005B30
0x1400017f4  xor     edx, edx
0x1400017f6  lea     rcx, [rbp+2FB0h+Data]
0x1400017fd  mov     r8d, 1000h
0x140001803  call    sub_140005B30
0x140001808  mov     r8d, 800h
0x14000180e  lea     rdx, [rbp+2FB0h+Filename]
0x140001812  xor     ecx, ecx
0x140001814  call    sub_140002140
0x140001819  mov     r8d, 800h
0x14000181f  lea     rdx, [rbp+2FB0h+Data]
0x140001826  mov     ecx, 3FEh
0x14000182b  call    sub_140002140
0x140001830  lea     r8, [rbp+2FB0h+Data]
0x140001837  lea     rdx, [rbp+2FB0h+Filename]
0x14000183b  jmp     loc_140001AD4
0x140001840  call    sub_140005B30
0x140001845  xor     edx, edx
0x140001847  lea     rcx, [rbp+2FB0h+Data]
0x14000184e  mov     r8d, 1000h
0x140001854  call    sub_140005B30
0x140001859  mov     r8d, 800h
0x14000185f  lea     rdx, [rbp+2FB0h+Filename]
0x140001863  xor     ecx, ecx
0x140001865  call    sub_140002140
0x14000186a  mov     r8d, 800h
0x140001870  lea     rdx, [rbp+2FB0h+Data]
0x140001877  mov     ecx, 3FFh
0x14000187c  call    sub_140002140
0x140001881  mov     r9d, 2710h
0x140001887  lea     r8, [rbp+2FB0h+Data]
0x14000188e  lea     rdx, [rbp+2FB0h+Filename]
0x140001892  jmp     loc_140001ADA
0x140001897  mov     esi, 1
0x14000189c  mov     ecx, esi
0x14000189e  call    sub_1400034C0
0x1400018a3  lea     rax, [rsp+30B0h+NumberOfFreeClusters]
0x1400018a8  mov     [rsp+30B0h+NumberOfFreeClusters], 208h
0x1400018b0  mov     [rsp+30B0h+pcbData], rax; pcbData
0x1400018b5  lea     r9, [rsp+30B0h+pdwType]; pdwType
0x1400018ba  lea     rax, [rbp+2FB0h+Filename]
0x1400018be  mov     rcx, 0FFFFFFFF80000002h; hkey
0x1400018c5  lea     r8, pszValue; "Path"
0x1400018cc  mov     [rsp+30B0h+pvData], rax; pvData
0x1400018d1  lea     rdx, pszSubKey; "SOFTWARE\\Shadow Defender"
0x1400018d8  call    cs:SHGetValueW; SHLWAPI
0x1400018de  test    eax, eax
0x1400018e0  jz      short loc_140001903
0x1400018e2  mov     r8d, 104h; nSize
0x1400018e8  lea     rdx, [rbp+2FB0h+Filename]; lpFilename
0x1400018ec  xor     ecx, ecx; hModule
0x1400018ee  call    cs:GetModuleFileNameW; KERNEL32
0x1400018f4  lea     edx, [rsi+5Bh]; Ch
0x1400018f7  lea     rcx, [rbp+2FB0h+Filename]; Str
0x1400018fb  call    wcsrchr
0x140001900  mov     [rax], di
0x140001903  lea     r8, aUserDat; "\\user.dat"
0x14000190a  mov     edx, 104h; SizeInWords
0x14000190f  lea     rcx, [rbp+2FB0h+Filename]; Destination
0x140001913  call    wcscat_s
0x140001918  lea     r9, [rbp+2FB0h+Filename]; lpFileName
0x14000191c  xor     r8d, r8d; nDefault
0x14000191f  lea     rdx, KeyName; "disable"
0x140001926  lea     rcx, AppName; "space"
0x14000192d  call    cs:GetPrivateProfileIntW; KERNEL32
0x140001933  cmp     eax, esi
0x140001935  jz      loc_140001AE6
0x14000193b  mov     [rsp+30B0h+arg_8], r13
0x140001943  lea     rcx, [rbp+2FB0h+Data]
0x14000194a  mov     [rsp+30B0h+arg_10], r14
0x140001952  xor     edx, edx
0x140001954  mov     r8d, 1000h
0x14000195a  mov     [rsp+30B0h+arg_18], r15
0x140001962  mov     r13d, edi
0x140001965  call    sub_140005B30
0x14000196a  xor     edx, edx
0x14000196c  lea     rcx, [rbp+2FB0h+Filename]
0x140001970  mov     r8d, 100h
0x140001976  call    sub_140005B30
0x14000197b  xor     edx, edx
0x14000197d  lea     rcx, [rbp+2FB0h+Buffer]
0x140001984  mov     r8d, 1000h
0x14000198a  call    sub_140005B30
0x14000198f  mov     r15d, edi
0x140001992  lea     r14, unk_140020C60
0x140001999  mov     rdi, 5C003A0020h
0x1400019a3  mov     r12, 20003A0020h
0x1400019ad  nop     dword ptr [rax]
0x1400019b0  lea     ebx, [r15+43h]
0x1400019b4  movzx   ecx, bx
0x1400019b7  call    sub_140001110
0x1400019bc  test    eax, eax
0x1400019be  jz      loc_140001A47
0x1400019c4  cmp     dword ptr [r14], 0
0x1400019c8  jnz     short loc_140001A47
0x1400019ca  lea     rdx, [rsp+30B0h+var_3050]
0x1400019cf  movzx   ecx, bx
0x1400019d2  call    sub_140005210
0x1400019d7  test    eax, eax
0x1400019d9  jz      short loc_140001A47
0x1400019db  cmp     [rsp+30B0h+var_304C], esi
0x1400019df  jnz     short loc_140001A47
0x1400019e1  lea     rax, [rsp+30B0h+pdwType]
0x1400019e6  mov     qword ptr [rsp+30B0h+RootPathName], rdi
0x1400019eb  lea     r9, [rsp+30B0h+NumberOfFreeClusters]; lpNumberOfFreeClusters
0x1400019f0  mov     [rsp+30B0h+pvData], rax; lpTotalNumberOfClusters
0x1400019f5  lea     r8, [rsp+30B0h+BytesPerSector]; lpBytesPerSector
0x1400019fa  mov     [rsp+30B0h+RootPathName], bx
0x1400019ff  lea     rdx, [rsp+30B0h+SectorsPerCluster]; lpSectorsPerCluster
0x140001a04  lea     rcx, [rsp+30B0h+RootPathName]; lpRootPathName
0x140001a09  call    cs:GetDiskFreeSpaceW; KERNEL32
0x140001a0f  movzx   ecx, bx
0x140001a12  call    sub_140002240
0x140001a17  mov     eax, eax
0x140001a19  shl     rax, 14h
0x140001a1d  cmp     [rsp+30B0h+var_3048], rax
0x140001a22  jge     short loc_140001A47
0x140001a24  mov     qword ptr [rsp+30B0h+Point.x], r12
0x140001a29  lea     r8, [rsp+30B0h+Point]; Source
0x140001a2e  mov     edx, 80h; SizeInWords
0x140001a33  mov     word ptr [rsp+30B0h+Point.x], bx
0x140001a38  lea     rcx, [rbp+2FB0h+Filename]; Destination
0x140001a3c  mov     [r14], esi
0x140001a3f  mov     r13d, esi
0x140001a42  call    wcscat_s
0x140001a47  inc     r15d
0x140001a4a  add     r14, 4
0x140001a4e  cmp     r15d, 18h
0x140001a52  jl      loc_1400019B0
0x140001a58  mov     r15, [rsp+30B0h+arg_18]
0x140001a60  test    r13d, r13d
0x140001a63  mov     r13, [rsp+30B0h+arg_8]
0x140001a6b  mov     edi, 0
0x140001a70  mov     r14, [rsp+30B0h+arg_10]
0x140001a78  mov     r12, [rsp+30B0h+var_3058]
0x140001a7d  jz      short loc_140001AE6
0x140001a7f  mov     r8d, 800h
0x140001a85  lea     rdx, [rbp+2FB0h+Data]
0x140001a8c  mov     ecx, 3F8h
0x140001a91  call    sub_140002140
0x140001a96  lea     r9, [rbp+2FB0h+Filename]
0x140001a9a  mov     edx, 800h; BufferCount
0x140001a9f  lea     r8, [rbp+2FB0h+Data]; Format
0x140001aa6  lea     rcx, [rbp+2FB0h+Buffer]; Buffer
0x140001aad  call    swprintf
0x140001ab2  mov     r8d, 800h
0x140001ab8  lea     rdx, [rbp+2FB0h+Data]
0x140001abf  xor     ecx, ecx
0x140001ac1  call    sub_140002140
0x140001ac6  lea     r8, [rbp+2FB0h+Buffer]
0x140001acd  lea     rdx, [rbp+2FB0h+Data]
0x140001ad4  mov     r9d, 7530h
0x140001ada  mov     rcx, cs:qword_140020C30
0x140001ae1  call    sub_1400026C0
0x140001ae6  mov     eax, [rsp+30B0h+var_3068]
0x140001aea  cmp     eax, cs:dword_140020D80
0x140001af0  jnz     loc_140001D8B
0x140001af6  cmp     cs:byte_140020C59, 0
0x140001afd  jnz     loc_140001D8B
0x140001b03  cmp     cs:dword_140020C5C, 0
0x140001b0a  mov     edx, edi
0x140001b0c  mov     r8d, 2
0x140001b12  mov     rcx, r12
0x140001b15  setnz   dl
0x140001b18  call    sub_140001DB0
0x140001b1d  cmp     cs:dword_140020C5C, 0
0x140001b24  mov     rcx, r12
0x140001b27  setnz   dil
0x140001b2b  xor     r8d, r8d
0x140001b2e  mov     edx, edi
0x140001b30  call    sub_140001DB0
0x140001b35  jmp     loc_140001D8B
0x140001b3a  cmp     r9, 203h
0x140001b41  jz      loc_140001D84
0x140001b47  cmp     r9, 205h
0x140001b4e  jz      short loc_140001B8F
0x140001b50  lea     rax, [r9-403h]
0x140001b57  cmp     rax, 2
0x140001b5b  ja      loc_140001D8B
0x140001b61  cmp     cs:byte_140020C59, dil
0x140001b68  jnz     short loc_140001B71
0x140001b6a  mov     esi, 1
0x140001b6f  jmp     short loc_140001B76
0x140001b71  mov     esi, 2
0x140001b76  cmp     cs:dword_140020C5C, edi
0x140001b7c  mov     r8d, esi
0x140001b7f  setnz   dil
0x140001b83  mov     edx, edi
0x140001b85  call    sub_140001DB0
0x140001b8a  jmp     loc_140001D8B
0x140001b8f  mov     rcx, cs:hInstance; hInstance
0x140001b96  mov     edx, 84h; lpMenuName
0x140001b9b  call    cs:LoadMenuW; USER32
0x140001ba1  mov     rcx, rax; hMenu
0x140001ba4  xor     edx, edx; nPos
0x140001ba6  call    cs:GetSubMenu; USER32
0x140001bac  xor     r8d, r8d; fByPos
0x140001baf  mov     edx, 31E3h; uItem
0x140001bb4  mov     rcx, rax; hMenu
0x140001bb7  mov     rbx, rax
0x140001bba  call    cs:SetMenuDefaultItem; USER32
0x140001bc0  mov     r8d, 40h ; '@'
0x140001bc6  lea     rdx, [rbp+2FB0h+Filename]
0x140001bca  lea     ecx, [r8-22h]
0x140001bce  call    sub_140002140
0x140001bd3  mov     r9d, 31E3h; uIDNewItem
0x140001bd9  lea     rax, [rbp+2FB0h+Filename]
0x140001bdd  mov     edx, r9d; uPosition
0x140001be0  mov     [rsp+30B0h+pvData], rax; lpNewItem
0x140001be5  xor     r8d, r8d; uFlags
0x140001be8  mov     rcx, rbx; hMnu
0x140001beb  call    cs:ModifyMenuW; USER32
0x140001bf1  mov     r8d, 40h ; '@'
0x140001bf7  lea     rdx, [rbp+2FB0h+Filename]
0x140001bfb  lea     ecx, [r8-21h]
0x140001bff  call    sub_140002140
0x140001c04  mov     r9d, 31E4h; uIDNewItem
0x140001c0a  lea     rax, [rbp+2FB0h+Filename]
0x140001c0e  mov     edx, r9d; uPosition
0x140001c11  mov     [rsp+30B0h+pvData], rax; lpNewItem
0x140001c16  xor     r8d, r8d; uFlags
0x140001c19  mov     rcx, rbx; hMnu
0x140001c1c  call    cs:ModifyMenuW; USER32
0x140001c22  mov     r8d, 40h ; '@'
0x140001c28  lea     rdx, [rbp+2FB0h+Filename]
0x140001c2c  lea     ecx, [r8-20h]
0x140001c30  call    sub_140002140
0x140001c35  mov     r9d, 31E6h; uIDNewItem
0x140001c3b  lea     rax, [rbp+2FB0h+Filename]
0x140001c3f  mov     edx, r9d; uPosition
0x140001c42  mov     [rsp+30B0h+pvData], rax; lpNewItem
0x140001c47  xor     r8d, r8d; uFlags
0x140001c4a  mov     rcx, rbx; hMnu
0x140001c4d  call    cs:ModifyMenuW; USER32
0x140001c53  mov     r8d, 40h ; '@'
0x140001c59  lea     rdx, [rbp+2FB0h+Filename]
0x140001c5d  lea     ecx, [r8-1Fh]
0x140001c61  call    sub_140002140
0x140001c66  mov     r9d, 31E5h; uIDNewItem
0x140001c6c  lea     rax, [rbp+2FB0h+Filename]
0x140001c70  mov     edx, r9d; uPosition
0x140001c73  mov     [rsp+30B0h+pvData], rax; lpNewItem
0x140001c78  xor     r8d, r8d; uFlags
0x140001c7b  mov     rcx, rbx; hMnu
0x140001c7e  call    cs:ModifyMenuW; USER32
0x140001c84  mov     r8d, 40h ; '@'
0x140001c8a  lea     rdx, [rbp+2FB0h+Filename]
0x140001c8e  lea     ecx, [r8-1Eh]
0x140001c92  call    sub_140002140
0x140001c97  mov     r9d, 31E7h; uIDNewItem
0x140001c9d  lea     rax, [rbp+2FB0h+Filename]
0x140001ca1  mov     edx, r9d; uPosition
0x140001ca4  mov     [rsp+30B0h+pvData], rax; lpNewItem
0x140001ca9  xor     r8d, r8d; uFlags
0x140001cac  mov     rcx, rbx; hMnu
0x140001caf  call    cs:ModifyMenuW; USER32
0x140001cb5  cmp     cs:dword_140020C5C, edi
0x140001cbb  jz      short loc_140001CE5
0x140001cbd  call    sub_1400023E0
0x140001cc2  test    eax, eax
0x140001cc4  jz      short loc_140001CE5
0x140001cc6  cmp     cs:hWnd, rdi
0x140001ccd  jz      short loc_140001CF6
0x140001ccf  mov     edx, 31E4h; uIDCheckItem
0x140001cd4  mov     r8d, 8; uCheck
0x140001cda  mov     rcx, rbx; hMenu
0x140001cdd  call    cs:CheckMenuItem; USER32
0x140001ce3  jmp     short loc_140001CF6
0x140001ce5  xor     r8d, r8d; uFlags
0x140001ce8  mov     edx, 31E4h; uPosition
0x140001ced  mov     rcx, rbx; hMenu
0x140001cf0  call    cs:DeleteMenu; USER32
0x140001cf6  cmp     cs:dword_140020C5C, edi
0x140001cfc  jnz     short loc_140001D0F
0x140001cfe  xor     r8d, r8d; uFlags
0x140001d01  mov     edx, 31E7h; uPosition
0x140001d06  mov     rcx, rbx; hMenu
0x140001d09  call    cs:DeleteMenu; USER32
0x140001d0f  lea     rcx, [rsp+30B0h+Point]; lpPoint
0x140001d14  call    cs:GetCursorPos; USER32
0x140001d1a  mov     rcx, r12; hWnd
0x140001d1d  call    cs:SetForegroundWindow; USER32
0x140001d23  mov     rcx, r12; hWnd
0x140001d26  call    cs:SetFocus; USER32
0x140001d2c  mov     r9d, [rsp+30B0h+Point.y]; y
0x140001d31  xor     edx, edx; uFlags
0x140001d33  mov     r8d, [rsp+30B0h+Point.x]; x
0x140001d38  mov     rcx, rbx; hMenu
0x140001d3b  mov     [rsp+30B0h+prcRect], rdi; prcRect
0x140001d40  mov     [rsp+30B0h+pcbData], r12; hWnd
0x140001d45  mov     dword ptr [rsp+30B0h+pvData], edi; nReserved
0x140001d49  call    cs:TrackPopupMenu; USER32
0x140001d4f  test    eax, eax
0x140001d51  jnz     short loc_140001D8B
0x140001d53  mov     [rbp+2FB0h+Data.cbSize], 3C8h
0x140001d5d  mov     [rbp+2FB0h+Data.hWnd], r12
0x140001d64  call    cs:GetCurrentProcessId; KERNEL32
0x140001d6a  lea     rdx, [rbp+2FB0h+Data]; lpData
0x140001d71  mov     ecx, 3; dwMessage
0x140001d76  mov     [rbp+2FB0h+Data.uID], eax
0x140001d7c  call    cs:Shell_NotifyIconW; SHELL32
0x140001d82  jmp     short loc_140001D8B
0x140001d84  xor     ecx, ecx
0x140001d86  call    sub_1400025D0
0x140001d8b  xor     eax, eax
0x140001d8d  mov     rcx, [rbp+2FB0h+var_30]
0x140001d94  xor     rcx, rsp; StackCookie
0x140001d97  call    __security_check_cookie
0x140001d9c  add     rsp, 3090h
0x140001da3  pop     r12
0x140001da5  pop     rdi
0x140001da6  pop     rsi
0x140001da7  pop     rbx
0x140001da8  pop     rbp
0x140001da9  retn

// ===== sub_140001DB0 @ 0x140001db0 =====

0x140001db0  mov     [rsp-8+arg_18], rbx
0x140001db5  push    rbp
0x140001db6  push    rsi
0x140001db7  push    rdi
0x140001db8  push    r12
0x140001dba  push    r14
0x140001dbc  lea     rbp, [rsp-7D0h]
0x140001dc4  sub     rsp, 8D0h
0x140001dcb  mov     rax, cs:__security_cookie
0x140001dd2  xor     rax, rsp
0x140001dd5  mov     [rbp+7F0h+var_30], rax
0x140001ddc  mov     r12d, r8d
0x140001ddf  mov     [rsp+8F0h+arg_8], r15
0x140001de7  mov     r15, rcx
0x140001dea  mov     r14d, edx
0x140001ded  lea     rcx, [rbp+7F0h+Buffer]
0x140001df4  xor     edx, edx
0x140001df6  mov     r8d, 80h
0x140001dfc  call    sub_140005B30
0x140001e01  xor     edx, edx
0x140001e03  lea     rcx, [rbp+7F0h+Filename]
0x140001e0a  mov     r8d, 208h
0x140001e10  call    sub_140005B30
0x140001e15  mov     r8d, 104h; nSize
0x140001e1b  lea     rdx, [rbp+7F0h+Filename]; lpFilename
0x140001e22  xor     ecx, ecx; hModule
0x140001e24  call    cs:GetModuleFileNameW; KERNEL32
0x140001e2a  xor     edx, edx; lpdwHandle
0x140001e2c  lea     rcx, [rbp+7F0h+Filename]; lptstrFilename
0x140001e33  call    GetFileVersionInfoSizeW
0x140001e38  xor     esi, esi
0x140001e3a  movsxd  rdi, eax
0x140001e3d  test    eax, eax
0x140001e3f  jle     loc_140001EDD
0x140001e45  mov     rcx, rdi; Size
0x140001e48  call    j_??2@YAPEAX_K@Z; operator new(unsigned __int64)
0x140001e4d  mov     rbx, rax
0x140001e50  test    rax, rax
0x140001e53  jz      loc_140001EDD
0x140001e59  mov     r9, rax; lpData
0x140001e5c  lea     rcx, [rbp+7F0h+Filename]; lptstrFilename
0x140001e63  mov     r8d, edi; dwLen
0x140001e66  xor     edx, edx; dwHandle
0x140001e68  call    GetFileVersionInfoW
0x140001e6d  test    eax, eax
0x140001e6f  jz      short loc_140001EDD
0x140001e71  lea     r9, [rsp+8F0h+puLen]; puLen
0x140001e76  mov     [rbp+7F0h+lpBuffer], rsi
0x140001e7d  lea     r8, [rbp+7F0h+lpBuffer]; lplpBuffer
0x140001e84  mov     [rsp+8F0h+puLen], esi
0x140001e88  lea     rdx, SubBlock; "\\"
0x140001e8f  mov     rcx, rbx; pBlock
0x140001e92  call    VerQueryValueW
0x140001e97  mov     rax, [rbp+7F0h+lpBuffer]
0x140001e9e  lea     r8, aDDDD; "%d.%d.%d.%d"
0x140001ea5  mov     edx, [rax+0Ch]
0x140001ea8  mov     r9d, [rax+8]
0x140001eac  movzx   ecx, dx
0x140001eaf  mov     [rsp+8F0h+var_8C0], ecx
0x140001eb3  lea     rcx, [rbp+7F0h+Buffer]; Buffer
0x140001eba  shr     edx, 10h
0x140001ebd  mov     [rsp+8F0h+var_8C8], edx
0x140001ec1  lea     edx, [rsi+40h]; BufferCount
0x140001ec4  movzx   eax, r9w
0x140001ec8  shr     r9d, 10h
0x140001ecc  mov     [rsp+8F0h+var_8D0], eax
0x140001ed0  call    swprintf
0x140001ed5  mov     rcx, rbx; Block
0x140001ed8  call    j_j_j__free_base
0x140001edd  mov     [rsp+8F0h+Data.cbSize], 3C8h
0x140001ee5  mov     [rsp+8F0h+Data.hWnd], r15
0x140001eea  call    cs:GetCurrentProcessId; KERNEL32
0x140001ef0  mov     r15, [rsp+8F0h+arg_8]
0x140001ef8  mov     [rsp+8F0h+Data.uID], eax
0x140001efc  mov     [rsp+8F0h+Data.uCallbackMessage], 464h
0x140001f04  cmp     r12d, 2
0x140001f08  jz      loc_140002103
0x140001f0e  test    r14d, r14d
0x140001f11  jz      loc_14000209C
0x140001f17  xor     edx, edx
0x140001f19  lea     rcx, [rbp+7F0h+Source]
0x140001f20  mov     r8d, 100h
0x140001f26  call    sub_140005B30
0x140001f2b  xor     edx, edx
0x140001f2d  lea     rcx, [rbp+7F0h+Destination]
0x140001f34  mov     r8d, 100h
0x140001f3a  call    sub_140005B30
0x140001f3f  mov     edi, esi
0x140001f41  mov     ebx, 43h ; 'C'
0x140001f46  mov     r14, 20003A0020h
0x140001f50  movzx   eax, bx
0x140001f53  sub     eax, 43h ; 'C'
0x140001f56  movzx   ecx, al
0x140001f59  mov     eax, cs:dword_140020C5C
0x140001f5f  bt      eax, ecx
0x140001f62  jnb     short loc_140001F8C
0x140001f64  mov     [rbp+7F0h+lpBuffer], r14
0x140001f6b  lea     r8, [rbp+7F0h+lpBuffer]; Source
0x140001f72  mov     edx, 80h; SizeInWords
0x140001f77  mov     word ptr [rbp+7F0h+lpBuffer], bx
0x140001f7e  lea     rcx, [rbp+7F0h+Destination]; Destination
0x140001f85  call    wcscat_s
0x140001f8a  inc     edi
0x140001f8c  inc     bx
0x140001f8f  cmp     bx, 5Ah ; 'Z'
0x140001f93  jbe     short loc_140001F50
0x140001f95  mov     rbx, 0FFFFFFFFFFFFFFFFh
0x140001f9c  cmp     [rbp+7F0h+Destination], si
0x140001fa3  jz      short loc_140001FD7
0x140001fa5  lea     rcx, [rbp+7F0h+Destination]
0x140001fac  mov     rax, rbx
0x140001faf  nop
0x140001fb0  cmp     [rcx+rax*2+2], si
0x140001fb5  lea     rax, [rax+1]
0x140001fb9  jnz     short loc_140001FB0
0x140001fbb  lea     rax, ds:0FFFFFFFFFFFFFFFEh[rax*2]
0x140001fc3  cmp     rax, 100h
0x140001fc9  jnb     loc_140002137
0x140001fcf  mov     [rbp+rax+7F0h+Destination], si
0x140001fd7  cmp     edi, 1
0x140001fda  lea     rdx, [rbp+7F0h+Filename]
0x140001fe1  mov     r8d, 80h
0x140001fe7  setnz   sil
0x140001feb  lea     ecx, [rsi+3F9h]
0x140001ff1  call    sub_140002140
0x140001ff6  lea     r9, [rbp+7F0h+Destination]
0x140001ffd  mov     edx, 80h; BufferCount
0x140002002  lea     r8, [rbp+7F0h+Filename]; Format
0x140002009  lea     rcx, [rbp+7F0h+Source]; Buffer
0x140002010  call    swprintf
0x140002015  lea     rax, [rbp+7F0h+Buffer]
0x14000201c  nop     dword ptr [rax+00h]
0x140002020  inc     rbx
0x140002023  cmp     word ptr [rax+rbx*2], 0
0x140002028  jnz     short loc_140002020
0x14000202a  lea     rcx, [rsp+8F0h+Data.szTip]; Destination
0x14000202f  mov     edx, 80h; SizeInWords
0x140002034  test    rbx, rbx
0x140002037  jnz     short loc_140002047
0x140002039  lea     r8, aShadowDefender; "Shadow Defender\n"
0x140002040  call    wcscpy_s
0x140002045  jmp     short loc_14000207F
0x140002047  lea     r8, aShadowDefender_0; "Shadow Defender "
0x14000204e  call    wcscpy_s
0x140002053  lea     r8, [rbp+7F0h+Buffer]; Source
0x14000205a  mov     edx, 80h; SizeInWords
0x14000205f  lea     rcx, [rsp+8F0h+Data.szTip]; Destination
0x140002064  call    wcscat_s
0x140002069  lea     r8, asc_140014B4C; "\n"
0x140002070  mov     edx, 80h; SizeInWords
0x140002075  lea     rcx, [rsp+8F0h+Data.szTip]; Destination
0x14000207a  call    wcscat_s
0x14000207f  lea     r8, [rbp+7F0h+Source]; Source
0x140002086  mov     edx, 80h; SizeInWords
0x14000208b  lea     rcx, [rsp+8F0h+Data.szTip]; Destination
0x140002090  call    wcscat_s
0x140002095  mov     edx, 85h
0x14000209a  jmp     short loc_1400020E9
0x14000209c  lea     r8, aShadowDefender_0; "Shadow Defender "
0x1400020a3  mov     edx, 80h; SizeInWords
0x1400020a8  lea     rcx, [rsp+8F0h+Data.szTip]; Destination
0x1400020ad  call    wcscpy_s
0x1400020b2  lea     rax, [rbp+7F0h+Buffer]
0x1400020b9  mov     rbx, 0FFFFFFFFFFFFFFFFh
0x1400020c0  inc     rbx
0x1400020c3  cmp     [rax+rbx*2], si
0x1400020c7  jnz     short loc_1400020C0
0x1400020c9  test    rbx, rbx
0x1400020cc  jz      short loc_1400020E4
0x1400020ce  lea     r8, [rbp+7F0h+Buffer]; Source
0x1400020d5  mov     edx, 80h; SizeInWords
0x1400020da  lea     rcx, [rsp+8F0h+Data.szTip]; Destination
0x1400020df  call    wcscat_s
0x1400020e4  mov     edx, 86h; lpIconName
0x1400020e9  mov     rcx, cs:hInstance; hInstance
0x1400020f0  call    cs:LoadIconW; USER32
0x1400020f6  mov     [rsp+8F0h+Data.hIcon], rax
0x1400020fb  mov     [rsp+8F0h+Data.uFlags], 7
0x140002103  lea     rdx, [rsp+8F0h+Data]; lpData
0x140002108  mov     ecx, r12d; dwMessage
0x14000210b  call    cs:Shell_NotifyIconW; SHELL32
0x140002111  mov     rcx, [rbp+7F0h+var_30]
0x140002118  xor     rcx, rsp; StackCookie
0x14000211b  call    __security_check_cookie
0x140002120  mov     rbx, [rsp+8F0h+arg_18]
0x140002128  add     rsp, 8D0h
0x14000212f  pop     r14
0x140002131  pop     r12
0x140002133  pop     rdi
0x140002134  pop     rsi
0x140002135  pop     rbp
0x140002136  retn
0x140002137  call    __report_rangecheckfailure

// ===== sub_140002140 @ 0x140002140 =====

0x140002140  push    rbx
0x140002142  push    rsi
0x140002143  push    rdi
0x140002144  sub     rsp, 280h
0x14000214b  mov     rax, cs:__security_cookie
0x140002152  xor     rax, rsp
0x140002155  mov     [rsp+298h+var_28], rax
0x14000215d  lea     rax, [rsp+298h+var_268]
0x140002162  mov     [rsp+298h+var_268], 208h
0x14000216a  mov     [rsp+298h+pcbData], rax; pcbData
0x14000216f  lea     r9, [rsp+298h+pdwType]; pdwType
0x140002174  lea     rax, [rsp+298h+Filename]
0x140002179  mov     esi, r8d
0x14000217c  mov     rdi, rdx
0x14000217f  mov     [rsp+298h+pvData], rax; pvData
0x140002184  mov     ebx, ecx
0x140002186  lea     r8, pszValue; "Path"
0x14000218d  lea     rdx, pszSubKey; "SOFTWARE\\Shadow Defender"
0x140002194  mov     rcx, 0FFFFFFFF80000002h; hkey
0x14000219b  call    cs:SHGetValueW; SHLWAPI
0x1400021a1  test    eax, eax
0x1400021a3  jz      short loc_1400021CC
0x1400021a5  mov     r8d, 104h; nSize
0x1400021ab  lea     rdx, [rsp+298h+Filename]; lpFilename
0x1400021b0  xor     ecx, ecx; hModule
0x1400021b2  call    cs:GetModuleFileNameW; KERNEL32
0x1400021b8  mov     edx, 5Ch ; '\'; Ch
0x1400021bd  lea     rcx, [rsp+298h+Filename]; Str
0x1400021c2  call    wcsrchr
0x1400021c7  xor     ecx, ecx
0x1400021c9  mov     [rax], cx
0x1400021cc  lea     r8, aResIni; "\\res.ini"
0x1400021d3  mov     edx, 104h; SizeInWords
0x1400021d8  lea     rcx, [rsp+298h+Filename]; Destination
0x1400021dd  call    wcscat_s
0x1400021e2  mov     r9d, ebx
0x1400021e5  lea     r8, aD; "%d"
0x1400021ec  mov     edx, 10h; BufferCount
0x1400021f1  lea     rcx, [rsp+298h+KeyName]; Buffer
0x1400021f6  call    swprintf
0x1400021fb  lea     rax, [rsp+298h+Filename]
0x140002200  mov     r9, rdi; lpReturnedString
0x140002203  mov     [rsp+298h+pcbData], rax; lpFileName
0x140002208  lea     r8, Default; lpDefault
0x14000220f  lea     rdx, [rsp+298h+KeyName]; lpKeyName
0x140002214  mov     dword ptr [rsp+298h+pvData], esi; nSize
0x140002218  lea     rcx, aCommon; "common"
0x14000221f  call    cs:GetPrivateProfileStringW; KERNEL32
0x140002225  mov     rcx, [rsp+298h+var_28]
0x14000222d  xor     rcx, rsp; StackCookie
0x140002230  call    __security_check_cookie
0x140002235  add     rsp, 280h
0x14000223c  pop     rdi
0x14000223d  pop     rsi
0x14000223e  pop     rbx
0x14000223f  retn

// ===== sub_140002240 @ 0x140002240 =====

0x140002240  mov     [rsp-8+arg_0], rbx
0x140002245  mov     [rsp-8+arg_8], rdi
0x14000224a  push    rbp
0x14000224b  lea     rbp, [rsp-180h]
0x140002253  sub     rsp, 280h
0x14000225a  mov     rax, cs:__security_cookie
0x140002261  xor     rax, rsp
0x140002264  mov     [rbp+180h+var_10], rax
0x14000226b  lea     rax, [rsp+280h+var_250]
0x140002270  mov     [rsp+280h+var_250], 208h
0x140002278  mov     [rsp+280h+pcbData], rax; pcbData
0x14000227d  lea     r9, [rsp+280h+pdwType]; pdwType
0x140002282  lea     rax, [rsp+280h+Filename]
0x140002287  movzx   ebx, cx
0x14000228a  lea     r8, pszValue; "Path"
0x140002291  mov     [rsp+280h+pvData], rax; pvData
0x140002296  lea     rdx, pszSubKey; "SOFTWARE\\Shadow Defender"
0x14000229d  mov     rcx, 0FFFFFFFF80000002h; hkey
0x1400022a4  call    cs:SHGetValueW; SHLWAPI
0x1400022aa  xor     edi, edi
0x1400022ac  test    eax, eax
0x1400022ae  jz      short loc_1400022D3
0x1400022b0  mov     r8d, 104h; nSize
0x1400022b6  lea     rdx, [rsp+280h+Filename]; lpFilename
0x1400022bb  xor     ecx, ecx; hModule
0x1400022bd  call    cs:GetModuleFileNameW; KERNEL32
0x1400022c3  lea     edx, [rdi+5Ch]; Ch
0x1400022c6  lea     rcx, [rsp+280h+Filename]; Str
0x1400022cb  call    wcsrchr
0x1400022d0  mov     [rax], di
0x1400022d3  lea     r8, aUserDat; "\\user.dat"
0x1400022da  mov     edx, 104h; SizeInWords
0x1400022df  lea     rcx, [rsp+280h+Filename]; Destination
0x1400022e4  call    wcscat_s
0x1400022e9  xor     eax, eax
0x1400022eb  mov     [rsp+280h+KeyName], bx
0x1400022f0  lea     r9, [rsp+280h+Filename]; lpFileName
0x1400022f5  mov     [rsp+280h+var_236], eax
0x1400022f9  xor     r8d, r8d; nDefault
0x1400022fc  mov     [rsp+280h+var_232], ax
0x140002301  lea     rdx, [rsp+280h+KeyName]; lpKeyName
0x140002306  lea     rcx, AppName; "space"
0x14000230d  call    cs:GetPrivateProfileIntW; KERNEL32
0x140002313  test    eax, eax
0x140002315  jnz     loc_1400023B7
0x14000231b  lea     r9, [rsp+280h+Filename]; lpFileName
0x140002320  xor     r8d, r8d; nDefault
0x140002323  lea     rdx, aDefault; "default"
0x14000232a  lea     rcx, AppName; "space"
0x140002331  call    cs:GetPrivateProfileIntW; KERNEL32
0x140002337  test    eax, eax
0x140002339  jnz     short loc_1400023B7
0x14000233b  mov     rax, 5C003A0020h
0x140002345  lea     r9, [rsp+280h+NumberOfFreeClusters]; lpNumberOfFreeClusters
0x14000234a  mov     qword ptr [rsp+280h+RootPathName], rax
0x14000234f  lea     r8, [rsp+280h+BytesPerSector]; lpBytesPerSector
0x140002354  lea     rax, [rsp+280h+TotalNumberOfClusters]
0x140002359  mov     [rsp+280h+RootPathName], bx
0x14000235e  lea     rdx, [rsp+280h+SectorsPerCluster]; lpSectorsPerCluster
0x140002363  mov     [rsp+280h+pvData], rax; lpTotalNumberOfClusters
0x140002368  lea     rcx, [rsp+280h+RootPathName]; lpRootPathName
0x14000236d  mov     [rsp+280h+RootPathName+4], di
0x140002372  call    cs:GetDiskFreeSpaceW; KERNEL32
0x140002378  mov     eax, [rsp+280h+BytesPerSector]
0x14000237c  mov     ecx, [rsp+280h+SectorsPerCluster]
0x140002380  imul    rcx, rax
0x140002384  mov     eax, [rsp+280h+TotalNumberOfClusters]
0x140002388  imul    rcx, rax
0x14000238c  cmp     rcx, 40000000h
0x140002393  jge     short loc_1400023B2
0x140002395  mov     rax, 6666666666666667h
0x14000239f  imul    rcx
0x1400023a2  sar     rdx, 15h
0x1400023a6  mov     rax, rdx
0x1400023a9  shr     rax, 3Fh
0x1400023ad  add     rax, rdx
0x1400023b0  jmp     short loc_1400023B7
0x1400023b2  mov     eax, 0C8h
0x1400023b7  mov     rcx, [rbp+180h+var_10]
0x1400023be  xor     rcx, rsp; StackCookie
0x1400023c1  call    __security_check_cookie
0x1400023c6  lea     r11, [rsp+280h+var_s0]
0x1400023ce  mov     rbx, [r11+10h]
0x1400023d2  mov     rdi, [r11+18h]
0x1400023d6  mov     rsp, r11
0x1400023d9  pop     rbp
0x1400023da  retn

// ===== sub_1400023E0 @ 0x1400023e0 =====

0x1400023e0  push    rbx
0x1400023e2  sub     rsp, 260h
0x1400023e9  mov     rax, cs:__security_cookie
0x1400023f0  xor     rax, rsp
0x1400023f3  mov     [rsp+268h+var_18], rax
0x1400023fb  lea     rax, [rsp+268h+var_238]
0x140002400  mov     [rsp+268h+var_238], 208h
0x140002408  mov     [rsp+268h+pcbData], rax; pcbData
0x14000240d  lea     r9, [rsp+268h+pdwType]; pdwType
0x140002412  lea     rax, [rsp+268h+Filename]
0x140002417  mov     rcx, 0FFFFFFFF80000002h; hkey
0x14000241e  lea     r8, pszValue; "Path"
0x140002425  mov     [rsp+268h+pvData], rax; pvData
0x14000242a  lea     rdx, pszSubKey; "SOFTWARE\\Shadow Defender"
0x140002431  call    cs:SHGetValueW; SHLWAPI
0x140002437  xor     ebx, ebx
0x140002439  test    eax, eax
0x14000243b  jz      short loc_140002460
0x14000243d  mov     r8d, 104h; nSize
0x140002443  lea     rdx, [rsp+268h+Filename]; lpFilename
0x140002448  xor     ecx, ecx; hModule
0x14000244a  call    cs:GetModuleFileNameW; KERNEL32
0x140002450  lea     edx, [rbx+5Ch]; Ch
0x140002453  lea     rcx, [rsp+268h+Filename]; Str
0x140002458  call    wcsrchr
0x14000245d  mov     [rax], bx
0x140002460  lea     r8, aUserDat; "\\user.dat"
0x140002467  mov     edx, 104h; SizeInWords
0x14000246c  lea     rcx, [rsp+268h+Filename]; Destination
0x140002471  call    wcscat_s
0x140002476  lea     r9, [rsp+268h+Filename]; lpFileName
0x14000247b  mov     r8d, 0FFFFFFFFh; nDefault
0x140002481  lea     rdx, aTip; "tip"
0x140002488  lea     rcx, aCommon; "common"
0x14000248f  call    cs:GetPrivateProfileIntW; KERNEL32
0x140002495  cmp     eax, 0FFFFFFFFh
0x140002498  jnz     short loc_1400024C4
0x14000249a  mov     ecx, 1F4h; dwMilliseconds
0x14000249f  call    cs:Sleep; KERNEL32
0x1400024a5  lea     r9, [rsp+268h+Filename]; lpFileName
0x1400024aa  mov     r8d, 1; nDefault
0x1400024b0  lea     rdx, aTip; "tip"
0x1400024b7  lea     rcx, aCommon; "common"
0x1400024be  call    cs:GetPrivateProfileIntW; KERNEL32
0x1400024c4  cmp     eax, 1
0x1400024c7  setz    bl
0x1400024ca  mov     eax, ebx
0x1400024cc  mov     rcx, [rsp+268h+var_18]
0x1400024d4  xor     rcx, rsp; StackCookie
0x1400024d7  call    __security_check_cookie
0x1400024dc  add     rsp, 260h
0x1400024e3  pop     rbx
0x1400024e4  retn

// ===== sub_1400024F0 @ 0x1400024f0 =====

0x1400024f0  push    rbx
0x1400024f2  sub     rsp, 260h
0x1400024f9  mov     rax, cs:__security_cookie
0x140002500  xor     rax, rsp
0x140002503  mov     [rsp+268h+var_18], rax
0x14000250b  lea     rax, [rsp+268h+var_238]
0x140002510  mov     [rsp+268h+var_238], 208h
0x140002518  mov     [rsp+268h+pcbData], rax; pcbData
0x14000251d  lea     r9, [rsp+268h+pdwType]; pdwType
0x140002522  lea     rax, [rsp+268h+Filename]
0x140002527  mov     rcx, 0FFFFFFFF80000002h; hkey
0x14000252e  lea     r8, pszValue; "Path"
0x140002535  mov     [rsp+268h+pvData], rax; pvData
0x14000253a  lea     rdx, pszSubKey; "SOFTWARE\\Shadow Defender"
0x140002541  call    cs:SHGetValueW; SHLWAPI
0x140002547  xor     ebx, ebx
0x140002549  test    eax, eax
0x14000254b  jz      short loc_140002570
0x14000254d  mov     r8d, 104h; nSize
0x140002553  lea     rdx, [rsp+268h+Filename]; lpFilename
0x140002558  xor     ecx, ecx; hModule
0x14000255a  call    cs:GetModuleFileNameW; KERNEL32
0x140002560  lea     edx, [rbx+5Ch]; Ch
0x140002563  lea     rcx, [rsp+268h+Filename]; Str
0x140002568  call    wcsrchr
0x14000256d  mov     [rax], bx
0x140002570  lea     r8, aUserDat; "\\user.dat"
0x140002577  mov     edx, 104h; SizeInWords
0x14000257c  lea     rcx, [rsp+268h+Filename]; Destination
0x140002581  call    wcscat_s
0x140002586  lea     r9, [rsp+268h+Filename]; lpFileName
0x14000258b  mov     r8d, 1; nDefault
0x140002591  lea     rdx, aTrayicon; "trayicon"
0x140002598  lea     rcx, aCommon; "common"
0x14000259f  call    cs:GetPrivateProfileIntW; KERNEL32
0x1400025a5  cmp     eax, 1
0x1400025a8  setz    bl
0x1400025ab  mov     eax, ebx
0x1400025ad  mov     rcx, [rsp+268h+var_18]
0x1400025b5  xor     rcx, rsp; StackCookie
0x1400025b8  call    __security_check_cookie
0x1400025bd  add     rsp, 260h
0x1400025c4  pop     rbx
0x1400025c5  retn

// ===== sub_1400025D0 @ 0x1400025d0 =====

0x1400025d0  mov     [rsp+arg_0], rbx
0x1400025d5  push    rdi
0x1400025d6  sub     rsp, 260h
0x1400025dd  mov     rax, cs:__security_cookie
0x1400025e4  xor     rax, rsp
0x1400025e7  mov     [rsp+268h+var_18], rax
0x1400025ef  lea     rax, [rsp+268h+var_238]
0x1400025f4  mov     [rsp+268h+var_238], 208h
0x1400025fc  mov     [rsp+268h+pcbData], rax; pcbData
0x140002601  lea     r9, [rsp+268h+pdwType]; pdwType
0x140002606  lea     rax, [rsp+268h+Filename]
0x14000260b  mov     ebx, ecx
0x14000260d  lea     r8, pszValue; "Path"
0x140002614  mov     [rsp+268h+pvData], rax; pvData
0x140002619  lea     rdx, pszSubKey; "SOFTWARE\\Shadow Defender"
0x140002620  mov     rcx, 0FFFFFFFF80000002h; hkey
0x140002627  call    cs:SHGetValueW; SHLWAPI
0x14000262d  xor     edi, edi
0x14000262f  test    eax, eax
0x140002631  jz      short loc_140002656
0x140002633  mov     r8d, 104h; nSize
0x140002639  lea     rdx, [rsp+268h+Filename]; lpFilename
0x14000263e  xor     ecx, ecx; hModule
0x140002640  call    cs:GetModuleFileNameW; KERNEL32
0x140002646  lea     edx, [rdi+5Ch]; Ch
0x140002649  lea     rcx, [rsp+268h+Filename]; Str
0x14000264e  call    wcsrchr
0x140002653  mov     [rax], di
0x140002656  lea     r8, aDefenderExe; "\\Defender.exe"
0x14000265d  mov     edx, 104h; SizeInWords
0x140002662  lea     rcx, [rsp+268h+Filename]; Destination
0x140002667  call    wcscat_s
0x14000266c  xor     ecx, ecx; hwnd
0x14000266e  mov     dword ptr [rsp+268h+pcbData], 5; nShowCmd
0x140002676  mov     [rsp+268h+pvData], rdi; lpDirectory
0x14000267b  lea     r8, [rsp+268h+Filename]; lpFile
0x140002680  lea     rdx, Operation; "open"
0x140002687  test    ebx, ebx
0x140002689  jz      short loc_140002694
0x14000268b  lea     r9, aExit; "/exit"
0x140002692  jmp     short loc_140002697
0x140002694  xor     r9d, r9d; lpParameters
0x140002697  call    cs:ShellExecuteW; SHELL32
0x14000269d  mov     rcx, [rsp+268h+var_18]
0x1400026a5  xor     rcx, rsp; StackCookie
0x1400026a8  call    __security_check_cookie
0x1400026ad  mov     rbx, [rsp+268h+arg_0]
0x1400026b5  add     rsp, 260h
0x1400026bc  pop     rdi
0x1400026bd  retn

// ===== sub_1400026C0 @ 0x1400026c0 =====

0x1400026c0  push    rbx
0x1400026c2  push    rsi
0x1400026c3  push    rdi
0x1400026c4  sub     rsp, 400h
0x1400026cb  mov     rax, cs:__security_cookie
0x1400026d2  xor     rax, rsp
0x1400026d5  mov     [rsp+418h+var_28], rax
0x1400026dd  mov     esi, r9d
0x1400026e0  mov     [rsp+418h+Data.cbSize], 3C8h
0x1400026e8  mov     rdi, r8
0x1400026eb  mov     [rsp+418h+Data.hWnd], rcx
0x1400026f0  mov     rbx, rdx
0x1400026f3  call    cs:GetCurrentProcessId; KERNEL32
0x1400026f9  mov     r8, rbx; Source
0x1400026fc  mov     [rsp+418h+Data.uCallbackMessage], 464h
0x140002704  mov     edx, 40h ; '@'; SizeInWords
0x140002709  mov     [rsp+418h+Data.uID], eax
0x14000270d  lea     rcx, [rsp+418h+Data.szInfoTitle]; Destination
0x140002715  call    wcscpy_s
0x14000271a  mov     r8, rdi; Source
0x14000271d  lea     rcx, [rsp+418h+Data.szInfo]; Destination
0x140002725  mov     edx, 100h; SizeInWords
0x14000272a  call    wcscpy_s
0x14000272f  mov     rcx, cs:hInstance; hInstance
0x140002736  mov     edx, 85h; lpIconName
0x14000273b  call    cs:LoadIconW; USER32
0x140002741  cmp     cs:byte_140020C59, 0
0x140002748  lea     rdx, [rsp+418h+Data]; lpData
0x14000274d  mov     [rsp+418h+Data.hIcon], rax
0x140002752  mov     [rsp+418h+Data.uFlags], 17h
0x14000275a  mov     [rsp+418h+Data.dwInfoFlags], 1
0x140002765  mov     dword ptr [rsp+418h+Data.330h], esi
0x14000276c  jz      short loc_140002772
0x14000276e  xor     ecx, ecx
0x140002770  jmp     short loc_140002777
0x140002772  mov     ecx, 1; dwMessage
0x140002777  call    cs:Shell_NotifyIconW; SHELL32
0x14000277d  mov     rcx, [rsp+418h+var_28]
0x140002785  xor     rcx, rsp; StackCookie
0x140002788  call    __security_check_cookie
0x14000278d  add     rsp, 400h
0x140002794  pop     rdi
0x140002795  pop     rsi
0x140002796  pop     rbx
0x140002797  retn

// ===== sub_1400027A0 @ 0x1400027a0 =====

0x1400027a0  mov     [rsp+arg_0], rbx
0x1400027a5  push    rdi
0x1400027a6  sub     rsp, 50h
0x1400027aa  mov     rax, cs:__security_cookie
0x1400027b1  xor     rax, rsp
0x1400027b4  mov     [rsp+58h+var_10], rax
0x1400027b9  mov     rax, cs:hEvent
0x1400027c0  xor     r9d, r9d; lpName
0x1400027c3  xor     r8d, r8d; bInitialState
0x1400027c6  mov     [rsp+58h+Handles], rax
0x1400027cb  xor     edx, edx; bManualReset
0x1400027cd  xor     ecx, ecx; lpEventAttributes
0x1400027cf  call    cs:CreateEventW; KERNEL32
0x1400027d5  xor     r9d, r9d; lpName
0x1400027d8  xor     r8d, r8d; bInitialState
0x1400027db  xor     edx, edx; bManualReset
0x1400027dd  mov     [rsp+58h+hObject], rax
0x1400027e2  xor     ecx, ecx; lpEventAttributes
0x1400027e4  call    cs:CreateEventW; KERNEL32
0x1400027ea  mov     rcx, [rsp+58h+hObject]
0x1400027ef  mov     rdx, rax
0x1400027f2  mov     [rsp+58h+var_18], rax
0x1400027f7  call    sub_1400057A0
0x1400027fc  mov     rbx, rax
0x1400027ff  xor     edi, edi
0x140002801  xor     r8d, r8d; bWaitAll
0x140002804  mov     [rsp+58h+bAlertable], edi; bAlertable
0x140002808  mov     r9d, 0FFFFFFFFh; dwMilliseconds
0x14000280e  lea     rdx, [rsp+58h+Handles]; lpHandles
0x140002813  lea     ecx, [r8+3]; nCount
0x140002817  call    cs:WaitForMultipleObjectsEx; KERNEL32
0x14000281d  cmp     eax, 1
0x140002820  jnz     short loc_14000283C
0x140002822  mov     rcx, cs:qword_140020C30; hWnd
0x140002829  xor     r9d, r9d; lParam
0x14000282c  mov     edx, 467h; Msg
0x140002831  mov     r8d, eax; wParam
0x140002834  call    cs:PostMessageW; USER32
0x14000283a  jmp     short loc_140002801
0x14000283c  cmp     eax, 2
0x14000283f  jnz     short loc_14000285B
0x140002841  mov     rcx, cs:qword_140020C30; hWnd
0x140002848  xor     r9d, r9d; lParam
0x14000284b  xor     r8d, r8d; wParam
0x14000284e  mov     edx, 467h; Msg
0x140002853  call    cs:PostMessageW; USER32
0x140002859  jmp     short loc_140002801
0x14000285b  mov     rcx, rbx; hObject
0x14000285e  call    cs:CloseHandle; KERNEL32
0x140002864  mov     rcx, [rsp+58h+hObject]; hObject
0x140002869  call    cs:CloseHandle; KERNEL32
0x14000286f  mov     rcx, [rsp+58h+var_18]; hObject
0x140002874  call    cs:CloseHandle; KERNEL32
0x14000287a  xor     eax, eax
0x14000287c  mov     rcx, [rsp+58h+var_10]
0x140002881  xor     rcx, rsp; StackCookie
0x140002884  call    __security_check_cookie
0x140002889  mov     rbx, [rsp+58h+arg_0]
0x14000288e  add     rsp, 50h
0x140002892  pop     rdi
0x140002893  retn

// ===== sub_1400028A0 @ 0x1400028a0 =====

0x1400028a0  mov     r11, rsp
0x1400028a3  mov     [r11+10h], rsi
0x1400028a7  mov     [r11+18h], rdi
0x1400028ab  push    rbp
0x1400028ac  push    r12
0x1400028ae  push    r13
0x1400028b0  push    r14
0x1400028b2  push    r15
0x1400028b4  lea     rbp, [r11-1B8h]
0x1400028bb  sub     rsp, 290h
0x1400028c2  mov     rax, cs:__security_cookie
0x1400028c9  xor     rax, rsp
0x1400028cc  mov     [rbp+1B0h+var_30], rax
0x1400028d3  xor     r14d, r14d
0x1400028d6  mov     [r11+8], rbx
0x1400028da  mov     esi, r14d
0x1400028dd  lea     r15, cs:140000000h
0x1400028e4  mov     r13, 5C003A0020h
0x1400028ee  mov     r12, 6666666666666667h
0x1400028f8  lea     edi, [r14+43h]
0x1400028fc  nop     dword ptr [rax+00h]
0x140002900  movzx   ecx, di
0x140002903  call    sub_140001110
0x140002908  test    eax, eax
0x14000290a  jz      loc_140002AA4
0x140002910  lea     rdx, [rsp+2B0h+var_268]
0x140002915  mov     dword ptr [rsp+2B0h+var_268+4], r14d
0x14000291a  movzx   ecx, di
0x14000291d  mov     qword ptr [rsp+2B0h+var_260], r14
0x140002922  call    sub_140005210
0x140002927  cmp     dword ptr [rsp+2B0h+var_268+4], 1
0x14000292c  jnz     loc_140002AA4
0x140002932  lea     rax, [rsp+2B0h+var_280]
0x140002937  mov     [rsp+2B0h+var_280], 208h
0x14000293f  mov     [rsp+2B0h+pcbData], rax; pcbData
0x140002944  lea     r9, [rsp+2B0h+pdwType]; pdwType
0x140002949  lea     rax, [rsp+2B0h+Filename]
0x14000294e  mov     rcx, 0FFFFFFFF80000002h; hkey
0x140002955  lea     r8, pszValue; "Path"
0x14000295c  mov     [rsp+2B0h+pvData], rax; pvData
0x140002961  lea     rdx, pszSubKey; "SOFTWARE\\Shadow Defender"
0x140002968  call    cs:SHGetValueW; SHLWAPI
0x14000296e  test    eax, eax
0x140002970  jz      short loc_140002998
0x140002972  mov     r8d, 104h; nSize
0x140002978  lea     rdx, [rsp+2B0h+Filename]; lpFilename
0x14000297d  xor     ecx, ecx; hModule
0x14000297f  call    cs:GetModuleFileNameW; KERNEL32
0x140002985  mov     edx, 5Ch ; '\'; Ch
0x14000298a  lea     rcx, [rsp+2B0h+Filename]; Str
0x14000298f  call    wcsrchr
0x140002994  mov     [rax], r14w
0x140002998  lea     r8, aUserDat; "\\user.dat"
0x14000299f  mov     edx, 104h; SizeInWords
0x1400029a4  lea     rcx, [rsp+2B0h+Filename]; Destination
0x1400029a9  call    wcscat_s
0x1400029ae  xor     eax, eax
0x1400029b0  mov     [rsp+2B0h+KeyName], di
0x1400029b5  lea     r9, [rsp+2B0h+Filename]; lpFileName
0x1400029ba  mov     dword ptr [rsp+2B0h+KeyName+2], eax
0x1400029be  xor     r8d, r8d; nDefault
0x1400029c1  mov     [rsp+2B0h+KeyName+6], ax
0x1400029c6  lea     rdx, [rsp+2B0h+KeyName]; lpKeyName
0x1400029cb  lea     rcx, AppName; "space"
0x1400029d2  call    cs:GetPrivateProfileIntW; KERNEL32
0x1400029d8  mov     ebx, eax
0x1400029da  test    eax, eax
0x1400029dc  jnz     loc_140002A71
0x1400029e2  lea     r9, [rsp+2B0h+Filename]; lpFileName
0x1400029e7  xor     r8d, r8d; nDefault
0x1400029ea  lea     rdx, aDefault; "default"
0x1400029f1  lea     rcx, AppName; "space"
0x1400029f8  call    cs:GetPrivateProfileIntW; KERNEL32
0x1400029fe  mov     ebx, eax
0x140002a00  test    eax, eax
0x140002a02  jnz     short loc_140002A71
0x140002a04  mov     qword ptr [rsp+2B0h+RootPathName], r13
0x140002a09  lea     rax, [rsp+2B0h+TotalNumberOfClusters]
0x140002a0e  lea     r9, [rsp+2B0h+NumberOfFreeClusters]; lpNumberOfFreeClusters
0x140002a13  mov     [rsp+2B0h+pvData], rax; lpTotalNumberOfClusters
0x140002a18  lea     r8, [rsp+2B0h+BytesPerSector]; lpBytesPerSector
0x140002a1d  mov     [rsp+2B0h+RootPathName], di
0x140002a22  lea     rdx, [rsp+2B0h+SectorsPerCluster]; lpSectorsPerCluster
0x140002a27  mov     [rsp+2B0h+RootPathName+4], r14w
0x140002a2d  lea     rcx, [rsp+2B0h+RootPathName]; lpRootPathName
0x140002a32  mov     ebx, 0C8h
0x140002a37  call    cs:GetDiskFreeSpaceW; KERNEL32
0x140002a3d  mov     eax, [rsp+2B0h+BytesPerSector]
0x140002a41  mov     ecx, [rsp+2B0h+SectorsPerCluster]
0x140002a45  imul    rcx, rax
0x140002a49  mov     eax, [rsp+2B0h+TotalNumberOfClusters]
0x140002a4d  imul    rcx, rax
0x140002a51  cmp     rcx, 40000000h
0x140002a58  jge     short loc_140002A71
0x140002a5a  mov     rax, r12
0x140002a5d  imul    rcx
0x140002a60  mov     rbx, rdx
0x140002a63  sar     rbx, 15h
0x140002a67  mov     rax, rbx
0x140002a6a  shr     rax, 3Fh
0x140002a6e  add     rbx, rax
0x140002a71  mov     ebx, ebx
0x140002a73  movzx   ecx, di
0x140002a76  shl     rbx, 14h
0x140002a7a  mov     rdx, rbx
0x140002a7d  call    sub_1400058F0
0x140002a82  movzx   eax, di
0x140002a85  cmp     rva off_140020AA8[r15+rax*8], rbx
0x140002a8d  jz      short loc_140002AA4
0x140002a8f  mov     rva off_140020AA8[r15+rax*8], rbx
0x140002a97  mov     esi, 1
0x140002a9c  mov     rva dword_140020B54[r15+rax*4], r14d
0x140002aa4  inc     di
0x140002aa7  cmp     di, 5Ah ; 'Z'
0x140002aab  jbe     loc_140002900
0x140002ab1  mov     rbx, [rsp+2B0h+arg_0]
0x140002ab9  mov     eax, esi
0x140002abb  mov     rcx, [rbp+1B0h+var_30]
0x140002ac2  xor     rcx, rsp; StackCookie
0x140002ac5  call    __security_check_cookie
0x140002aca  lea     r11, [rsp+2B0h+var_20]
0x140002ad2  mov     rsi, [r11+38h]
0x140002ad6  mov     rdi, [r11+40h]
0x140002ada  mov     rsp, r11
0x140002add  pop     r15
0x140002adf  pop     r14
0x140002ae1  pop     r13
0x140002ae3  pop     r12
0x140002ae5  pop     rbp
0x140002ae6  retn

// ===== sub_140002AF0 @ 0x140002af0 =====

0x140002af0  mov     [rsp+arg_8], rbx
0x140002af5  mov     [rsp+arg_10], rsi
0x140002afa  push    rdi
0x140002afb  sub     rsp, 280h
0x140002b02  mov     rax, cs:__security_cookie
0x140002b09  xor     rax, rsp
0x140002b0c  mov     [rsp+288h+var_18], rax
0x140002b14  xor     edx, edx; uiParam
0x140002b16  lea     r8, [rsp+288h+pvParam]; pvParam
0x140002b1b  mov     rsi, rcx
0x140002b1e  xor     r9d, r9d; fWinIni
0x140002b21  lea     ecx, [rdx+30h]; uiAction
0x140002b24  call    cs:SystemParametersInfoW; USER32
0x140002b2a  lea     rdx, [rsp+288h+Rect]; lpRect
0x140002b2f  mov     rcx, rsi; hWnd
0x140002b32  call    cs:GetClientRect; USER32
0x140002b38  mov     ebx, [rsp+288h+Rect.right]
0x140002b3c  lea     rax, [rsp+288h+FileName]
0x140002b41  mov     edi, [rsp+288h+Rect.bottom]
0x140002b45  xor     r9d, r9d; dwFlags
0x140002b48  sub     ebx, [rsp+288h+Rect.left]
0x140002b4c  xor     r8d, r8d; hToken
0x140002b4f  sub     edi, [rsp+288h+Rect.top]
0x140002b53  mov     edx, 801Ah; csidl
0x140002b58  xor     ecx, ecx; hwnd
0x140002b5a  mov     [rsp+288h+pszPath], rax; pszPath
0x140002b5f  call    cs:SHGetFolderPathW; SHELL32
0x140002b65  test    eax, eax
0x140002b67  js      short loc_140002BDC
0x140002b69  lea     r8, aShadowDefender_1; "\\Shadow Defender\\user.dat"
0x140002b70  mov     edx, 104h; SizeInWords
0x140002b75  lea     rcx, [rsp+288h+FileName]; Destination
0x140002b7a  call    wcscat_s
0x140002b7f  lea     r9, [rsp+288h+FileName]; lpFileName
0x140002b84  xor     r8d, r8d; nDefault
0x140002b87  lea     rdx, aTippos; "tippos"
0x140002b8e  lea     rcx, aCommon; "common"
0x140002b95  call    cs:GetPrivateProfileIntW; KERNEL32
0x140002b9b  test    eax, eax
0x140002b9d  jz      short loc_140002BDC
0x140002b9f  mov     edx, [rsp+288h+var_22C]
0x140002ba3  mov     ecx, eax
0x140002ba5  mov     r10d, [rsp+288h+var_230]
0x140002baa  sub     edx, edi
0x140002bac  shr     ecx, 10h
0x140002baf  sub     r10d, ebx
0x140002bb2  movsx   r8d, ax
0x140002bb6  movsx   r9d, cx
0x140002bba  cmp     r9d, edx
0x140002bbd  mov     [rsp+288h+uFlags], 5
0x140002bc5  cmovge  r9d, edx
0x140002bc9  cmp     r8d, r10d
0x140002bcc  cmovge  r8d, r10d
0x140002bd0  xor     eax, eax
0x140002bd2  mov     [rsp+288h+cy], eax
0x140002bd6  mov     dword ptr [rsp+288h+pszPath], eax
0x140002bda  jmp     short loc_140002C07
0x140002bdc  mov     eax, [rsp+288h+var_230]
0x140002be0  mov     r9d, 2; Y
0x140002be6  mov     ecx, [rsp+288h+pvParam]
0x140002bea  sub     eax, ecx
0x140002bec  sub     eax, ebx
0x140002bee  mov     [rsp+288h+uFlags], 5; uFlags
0x140002bf6  cdq
0x140002bf7  mov     [rsp+288h+cy], edi; cy
0x140002bfb  sub     eax, edx
0x140002bfd  mov     dword ptr [rsp+288h+pszPath], ebx; cx
0x140002c01  sar     eax, 1
0x140002c03  lea     r8d, [rcx+rax]; X
0x140002c07  mov     rdx, 0FFFFFFFFFFFFFFFEh; hWndInsertAfter
0x140002c0e  mov     rcx, rsi; hWnd
0x140002c11  call    cs:SetWindowPos; USER32
0x140002c17  mov     rcx, [rsp+288h+var_18]
0x140002c1f  xor     rcx, rsp; StackCookie
0x140002c22  call    __security_check_cookie
0x140002c27  lea     r11, [rsp+288h+var_8]
0x140002c2f  mov     rbx, [r11+18h]
0x140002c33  mov     rsi, [r11+20h]
0x140002c37  mov     rsp, r11
0x140002c3a  pop     rdi
0x140002c3b  retn

// ===== StartAddress @ 0x140002c40 =====

0x140002c40  push    rbp
0x140002c42  push    r14
0x140002c44  sub     rsp, 68h
0x140002c48  mov     rax, cs:__security_cookie
0x140002c4f  xor     rax, rsp
0x140002c52  mov     [rsp+78h+var_28], rax
0x140002c57  mov     rax, cs:qword_140020C48
0x140002c5e  xor     r9d, r9d; lpName
0x140002c61  xor     r8d, r8d; bInitialState
0x140002c64  mov     [rsp+78h+Handles], rax
0x140002c69  xor     edx, edx; bManualReset
0x140002c6b  xor     ecx, ecx; lpEventAttributes
0x140002c6d  call    cs:CreateEventW; KERNEL32
0x140002c73  mov     [rsp+78h+hObject], rax
0x140002c78  call    sub_1400028A0
0x140002c7d  mov     rcx, [rsp+78h+hObject]
0x140002c82  call    sub_140005670
0x140002c87  xor     r14d, r14d
0x140002c8a  lea     rdx, [rsp+78h+Handles]; lpHandles
0x140002c8f  mov     r9d, 0FFFFFFFFh; dwMilliseconds
0x140002c95  mov     [rsp+78h+bAlertable], r14d; bAlertable
0x140002c9a  xor     r8d, r8d; bWaitAll
0x140002c9d  mov     rbp, rax
0x140002ca0  lea     ecx, [r14+2]; nCount
0x140002ca4  call    cs:WaitForMultipleObjectsEx; KERNEL32
0x140002caa  cmp     eax, 1
0x140002cad  jnz     loc_140002E00
0x140002cb3  mov     [rsp+78h+arg_0], rbx
0x140002cbb  mov     [rsp+78h+arg_8], rsi
0x140002cc3  mov     [rsp+78h+arg_10], rdi
0x140002ccb  mov     [rsp+78h+arg_18], r12
0x140002cd3  mov     r12d, 43h ; 'C'
0x140002cd9  mov     [rsp+78h+var_18], r15
0x140002cde  lea     r15, cs:140000000h
0x140002ce5  nop     word ptr [rax+rax+00000000h]
0x140002cf0  mov     esi, r14d
0x140002cf3  movzx   edi, r12w
0x140002cf7  movzx   ecx, di
0x140002cfa  call    sub_140001110
0x140002cff  test    eax, eax
0x140002d01  jz      short loc_140002D5C
0x140002d03  lea     rdx, [rsp+78h+var_38]
0x140002d08  mov     [rsp+78h+var_34], r14d
0x140002d0d  movzx   ecx, di
0x140002d10  mov     [rsp+78h+var_30], r14
0x140002d15  call    sub_140005210
0x140002d1a  cmp     [rsp+78h+var_34], 1
0x140002d1f  jnz     short loc_140002D5C
0x140002d21  movzx   ecx, di
0x140002d24  call    sub_140002240
0x140002d29  mov     ebx, eax
0x140002d2b  movzx   ecx, di
0x140002d2e  shl     rbx, 14h
0x140002d32  mov     rdx, rbx
0x140002d35  call    sub_1400058F0
0x140002d3a  movzx   eax, di
0x140002d3d  cmp     rva off_140020AA8[r15+rax*8], rbx
0x140002d45  jz      short loc_140002D5C
0x140002d47  mov     rva off_140020AA8[r15+rax*8], rbx
0x140002d4f  mov     esi, 1
0x140002d54  mov     rva dword_140020B54[r15+rax*4], r14d
0x140002d5c  inc     di
0x140002d5f  cmp     di, 5Ah ; 'Z'
0x140002d63  jbe     short loc_140002CF7
0x140002d65  test    esi, esi
0x140002d67  jz      short loc_140002D9D
0x140002d69  mov     rcx, rbp; hObject
0x140002d6c  call    cs:CloseHandle; KERNEL32
0x140002d72  mov     rcx, [rsp+78h+hObject]; hObject
0x140002d77  call    cs:CloseHandle; KERNEL32
0x140002d7d  xor     r9d, r9d; lpName
0x140002d80  xor     r8d, r8d; bInitialState
0x140002d83  xor     edx, edx; bManualReset
0x140002d85  xor     ecx, ecx; lpEventAttributes
0x140002d87  call    cs:CreateEventW; KERNEL32
0x140002d8d  mov     rcx, rax
0x140002d90  mov     [rsp+78h+hObject], rax
0x140002d95  call    sub_140005670
0x140002d9a  mov     rbp, rax
0x140002d9d  mov     rcx, cs:qword_140020C30; hWnd
0x140002da4  xor     r9d, r9d; lParam
0x140002da7  xor     r8d, r8d; wParam
0x140002daa  mov     edx, 466h; Msg
0x140002daf  call    cs:PostMessageW; USER32
0x140002db5  xor     r8d, r8d; bWaitAll
0x140002db8  mov     [rsp+78h+bAlertable], r14d; bAlertable
0x140002dbd  mov     r9d, 0FFFFFFFFh; dwMilliseconds
0x140002dc3  lea     rdx, [rsp+78h+Handles]; lpHandles
0x140002dc8  lea     ecx, [r8+2]; nCount
0x140002dcc  call    cs:WaitForMultipleObjectsEx; KERNEL32
0x140002dd2  cmp     eax, 1
0x140002dd5  jz      loc_140002CF0
0x140002ddb  mov     r15, [rsp+78h+var_18]
0x140002de0  mov     r12, [rsp+78h+arg_18]
0x140002de8  mov     rdi, [rsp+78h+arg_10]
0x140002df0  mov     rsi, [rsp+78h+arg_8]
0x140002df8  mov     rbx, [rsp+78h+arg_0]
0x140002e00  mov     rcx, rbp; hObject
0x140002e03  call    cs:CloseHandle; KERNEL32
0x140002e09  mov     rcx, [rsp+78h+hObject]; hObject
0x140002e0e  call    cs:CloseHandle; KERNEL32
0x140002e14  xor     eax, eax
0x140002e16  mov     rcx, [rsp+78h+var_28]
0x140002e1b  xor     rcx, rsp; StackCookie
0x140002e1e  call    __security_check_cookie
0x140002e23  add     rsp, 68h
0x140002e27  pop     r14
0x140002e29  pop     rbp
0x140002e2a  retn

// ===== DialogFunc @ 0x140002e30 =====

0x140002e30  push    rbp
0x140002e32  push    rbx
0x140002e33  push    rsi
0x140002e34  push    rdi
0x140002e35  push    r14
0x140002e37  push    r15
0x140002e39  lea     rbp, [rsp-408h]
0x140002e41  sub     rsp, 508h
0x140002e48  mov     rax, cs:__security_cookie
0x140002e4f  xor     rax, rsp
0x140002e52  mov     [rbp+430h+var_40], rax
0x140002e59  mov     rbx, r9
0x140002e5c  mov     dword ptr [rsp+530h+lParam], edx
0x140002e60  mov     r14, rcx
0x140002e63  lea     r9, [rsp+530h+lParam]; lParam
0x140002e68  mov     rcx, cs:qword_140020C40; hWnd
0x140002e6f  mov     edx, 407h; Msg
0x140002e74  xor     r8d, r8d; wParam
0x140002e77  call    cs:SendMessageW; USER32
0x140002e7d  mov     eax, dword ptr [rsp+530h+lParam]
0x140002e81  cmp     eax, 110h
0x140002e86  ja      loc_140003233
0x140002e8c  jz      loc_14000310F
0x140002e92  cmp     eax, 2
0x140002e95  jz      loc_1400030F2
0x140002e9b  cmp     eax, 0Fh
0x140002e9e  jz      loc_140002F58
0x140002ea4  cmp     eax, 14h
0x140002ea7  jz      loc_140003490
0x140002ead  cmp     eax, 46h ; 'F'
0x140002eb0  jnz     loc_140002F51
0x140002eb6  xor     r9d, r9d; fWinIni
0x140002eb9  lea     r8, [rbp+430h+pvParam]; pvParam
0x140002ebd  xor     edx, edx; uiParam
0x140002ebf  lea     ecx, [rax-16h]; uiAction
0x140002ec2  call    cs:SystemParametersInfoW; USER32
0x140002ec8  mov     r8d, [rbx+10h]
0x140002ecc  xor     esi, esi
0x140002ece  mov     ecx, esi
0x140002ed0  test    r8d, r8d
0x140002ed3  jns     short loc_140002EDE
0x140002ed5  mov     [rbx+10h], esi
0x140002ed8  lea     ecx, [rsi+1]
0x140002edb  mov     r8d, esi
0x140002ede  mov     edx, [rbx+18h]
0x140002ee1  mov     r9d, [rbp+430h+var_458]
0x140002ee5  lea     eax, [rdx+r8]
0x140002ee9  cmp     eax, r9d
0x140002eec  jle     short loc_140002EFD
0x140002eee  mov     r8d, r9d
0x140002ef1  mov     ecx, 1
0x140002ef6  sub     r8d, edx; X
0x140002ef9  mov     [rbx+10h], r8d
0x140002efd  mov     r9d, [rbx+14h]
0x140002f01  test    r9d, r9d
0x140002f04  jns     short loc_140002F11
0x140002f06  mov     [rbx+14h], esi
0x140002f09  mov     ecx, 1
0x140002f0e  mov     r9d, esi; Y
0x140002f11  mov     edx, [rbx+1Ch]
0x140002f14  mov     r10d, [rbp+430h+var_454]
0x140002f18  lea     eax, [rdx+r9]
0x140002f1c  cmp     eax, r10d
0x140002f1f  jle     short loc_140002F2D
0x140002f21  mov     r9d, r10d
0x140002f24  sub     r9d, edx
0x140002f27  mov     [rbx+14h], r9d
0x140002f2b  jmp     short loc_140002F31
0x140002f2d  test    ecx, ecx
0x140002f2f  jz      short loc_140002F51
0x140002f31  mov     [rsp+530h+uFlags], 5; uFlags
0x140002f39  mov     rdx, 0FFFFFFFFFFFFFFFEh; hWndInsertAfter
0x140002f40  mov     [rsp+530h+cy], esi; cy
0x140002f44  mov     rcx, r14; hWnd
0x140002f47  mov     [rsp+530h+bottom], esi; cx
0x140002f4b  call    cs:SetWindowPos; USER32
0x140002f51  xor     eax, eax
0x140002f53  jmp     loc_140003495
0x140002f58  lea     rdx, [rsp+530h+Paint]; lpPaint
0x140002f5d  mov     [rsp+530h+var_30], r12
0x140002f65  mov     rcx, r14; hWnd
0x140002f68  call    cs:BeginPaint; USER32
0x140002f6e  mov     r15, [rsp+530h+Paint.hdc]
0x140002f73  lea     rdx, [rbp+430h+Rect]; lpRect
0x140002f77  xor     esi, esi
0x140002f79  mov     rcx, r14; hWnd
0x140002f7c  mov     r12d, esi
0x140002f7f  call    cs:GetClientRect; USER32
0x140002f85  test    r15, r15
0x140002f88  jnz     short loc_140002F99
0x140002f8a  mov     rcx, r14; hWnd
0x140002f8d  call    cs:GetDC; USER32
0x140002f93  mov     r12, rax
0x140002f96  mov     r15, rax
0x140002f99  xor     ecx, ecx; i
0x140002f9b  call    cs:GetStockObject; GDI32
0x140002fa1  mov     rdx, rax; h
0x140002fa4  mov     rcx, r15; hdc
0x140002fa7  call    cs:SelectObject; GDI32
0x140002fad  mov     ecx, 6; i
0x140002fb2  mov     rdi, rax
0x140002fb5  call    cs:GetStockObject; GDI32
0x140002fbb  mov     rdx, rax; h
0x140002fbe  mov     rcx, r15; hdc
0x140002fc1  call    cs:SelectObject; GDI32
0x140002fc7  mov     r9d, [rbp+430h+Rect.right]; right
0x140002fcb  mov     rcx, r15; hdc
0x140002fce  mov     r8d, [rbp+430h+Rect.top]; top
0x140002fd2  mov     rbx, rax
0x140002fd5  mov     eax, [rbp+430h+Rect.bottom]
0x140002fd8  mov     edx, [rbp+430h+Rect.left]; left
0x140002fdb  mov     [rsp+530h+bottom], eax; bottom
0x140002fdf  call    cs:Rectangle; GDI32
0x140002fe5  mov     rdx, rbx; h
0x140002fe8  mov     rcx, r15; hdc
0x140002feb  call    cs:SelectObject; GDI32
0x140002ff1  mov     rdx, rdi; h
0x140002ff4  mov     rcx, r15; hdc
0x140002ff7  call    cs:SelectObject; GDI32
0x140002ffd  mov     r8d, 104h; nSize
0x140003003  lea     rdx, [rbp+430h+Filename]; lpFilename
0x140003007  xor     ecx, ecx; hModule
0x140003009  call    cs:GetModuleFileNameW; KERNEL32
0x14000300f  mov     edx, 5Ch ; '\'; Ch
0x140003014  lea     rcx, [rbp+430h+Filename]; Str
0x140003018  call    wcsrchr
0x14000301d  test    rax, rax
0x140003020  jz      short loc_140003025
0x140003022  mov     [rax], si
0x140003025  lea     r8, aShadowBmp; "\\shadow.bmp"
0x14000302c  mov     edx, 104h; SizeInWords
0x140003031  lea     rcx, [rbp+430h+Filename]; Destination
0x140003035  call    wcscat_s
0x14000303a  xor     r9d, r9d; cx
0x14000303d  mov     [rsp+530h+cy], 10h; fuLoad
0x140003045  xor     r8d, r8d; type
0x140003048  mov     [rsp+530h+bottom], esi; cy
0x14000304c  lea     rdx, [rbp+430h+Filename]; name
0x140003050  xor     ecx, ecx; hInst
0x140003052  call    cs:LoadImageW; USER32
0x140003058  mov     rdi, rax
0x14000305b  test    rax, rax
0x14000305e  jnz     short loc_140003075
0x140003060  mov     rcx, cs:hInstance; hInstance
0x140003067  mov     edx, 83h; lpBitmapName
0x14000306c  call    cs:LoadBitmapW; USER32
0x140003072  mov     rdi, rax
0x140003075  mov     rcx, r15; hdc
0x140003078  call    cs:CreateCompatibleDC; GDI32
0x14000307e  mov     rcx, rax; hdc
0x140003081  mov     rdx, rdi; h
0x140003084  mov     rbx, rax
0x140003087  call    cs:SelectObject; GDI32
0x14000308d  mov     eax, [rbp+430h+Rect.bottom]
0x140003090  xor     r8d, r8d; y
0x140003093  mov     r9d, [rbp+430h+Rect.right]; cx
0x140003097  xor     edx, edx; x
0x140003099  mov     [rsp+530h+rop], 0CC0020h; rop
0x1400030a1  mov     rcx, r15; hdc
0x1400030a4  mov     [rsp+530h+y1], esi; y1
0x1400030a8  mov     [rsp+530h+uFlags], esi; x1
0x1400030ac  mov     qword ptr [rsp+530h+cy], rbx; hdcSrc
0x1400030b1  mov     [rsp+530h+bottom], eax; cy
0x1400030b5  call    cs:BitBlt; GDI32
0x1400030bb  cmp     r15, r12
0x1400030be  jnz     short loc_1400030CC
0x1400030c0  mov     rdx, r12; hDC
0x1400030c3  mov     rcx, r14; hWnd
0x1400030c6  call    cs:ReleaseDC; USER32
0x1400030cc  mov     rcx, rdi; ho
0x1400030cf  call    cs:DeleteObject; GDI32
0x1400030d5  lea     rdx, [rsp+530h+Paint]; lpPaint
0x1400030da  mov     rcx, r14; hWnd
0x1400030dd  call    cs:EndPaint; USER32
0x1400030e3  mov     r12, [rsp+530h+var_30]
0x1400030eb  xor     eax, eax
0x1400030ed  jmp     loc_140003495
0x1400030f2  mov     rcx, cs:qword_140020C40; hWnd
0x1400030f9  call    cs:DestroyWindow; USER32
0x1400030ff  xor     esi, esi
0x140003101  mov     cs:qword_140020C40, rsi
0x140003108  xor     eax, eax
0x14000310a  jmp     loc_140003495
0x14000310f  mov     rax, cs:hInstance
0x140003116  lea     rdx, ClassName; "tooltips_class32"
0x14000311d  xor     esi, esi
0x14000311f  mov     r9d, 80000003h; dwStyle
0x140003125  mov     [rsp+530h+lpParam], rsi; lpParam
0x14000312a  xor     r8d, r8d; lpWindowName
0x14000312d  mov     [rsp+530h+hInstance], rax; hInstance
0x140003132  mov     [rsp+530h+hMenu], rsi; hMenu
0x140003137  mov     qword ptr [rsp+530h+rop], r14; hWndParent
0x14000313c  lea     ecx, [rsi+8]; dwExStyle
0x14000313f  mov     [rsp+530h+y1], 80000000h; nHeight
0x140003147  mov     [rsp+530h+uFlags], 80000000h; nWidth
0x14000314f  mov     [rsp+530h+cy], 80000000h; Y
0x140003157  mov     [rsp+530h+bottom], 80000000h; X
0x14000315f  call    cs:CreateWindowExW; USER32
0x140003165  mov     [rsp+530h+uFlags], 13h; uFlags
0x14000316d  lea     rdx, [rsi-1]; hWndInsertAfter
0x140003171  mov     rcx, rax; hWnd
0x140003174  mov     [rsp+530h+cy], esi; cy
0x140003178  xor     r9d, r9d; Y
0x14000317b  mov     cs:qword_140020C40, rax
0x140003182  xor     r8d, r8d; X
0x140003185  mov     [rsp+530h+bottom], esi; cx
0x140003189  call    cs:SetWindowPos; USER32
0x14000318f  lea     rdx, [rbp+430h+Rect]; lpRect
0x140003193  mov     rcx, r14; hWnd
0x140003196  call    cs:GetClientRect; USER32
0x14000319c  mov     rax, cs:hInstance
0x1400031a3  lea     r9, [rsp+530h+Paint]; lParam
0x1400031a8  mov     rcx, cs:qword_140020C40; hWnd
0x1400031af  xor     r8d, r8d; wParam
0x1400031b2  mov     qword ptr [rbp+430h+Paint.rgbReserved+4], rax
0x1400031b6  mov     edx, 432h; Msg
0x1400031bb  lea     rax, Default
0x1400031c2  mov     dword ptr [rsp+530h+Paint.hdc], 48h ; 'H'
0x1400031ca  mov     qword ptr [rbp+430h+Paint.rgbReserved+0Ch], rax
0x1400031ce  mov     eax, [rbp+430h+Rect.left]
0x1400031d1  mov     [rbp+430h+Paint.rcPaint.bottom], eax
0x1400031d4  mov     eax, [rbp+430h+Rect.top]
0x1400031d7  mov     [rbp+430h+Paint.fRestore], eax
0x1400031da  mov     eax, [rbp+430h+Rect.right]
0x1400031dd  mov     [rbp+430h+Paint.fIncUpdate], eax
0x1400031e0  mov     eax, [rbp+430h+Rect.bottom]
0x1400031e3  mov     dword ptr [rbp+430h+Paint.rgbReserved], eax
0x1400031e6  mov     dword ptr [rsp+530h+Paint.hdc+4], 10h
0x1400031ee  mov     qword ptr [rsp+530h+Paint.fErase], r14
0x1400031f3  mov     qword ptr [rbp+430h+Paint.rcPaint.top], rsi
0x1400031f7  call    cs:SendMessageW; USER32
0x1400031fd  mov     rcx, cs:qword_140020C40; hWnd
0x140003204  lea     r9, lParam; "Shadow Defender"
0x14000320b  mov     edx, 421h; Msg
0x140003210  lea     r8d, [rsi+1]; wParam
0x140003214  call    cs:SendMessageW; USER32
0x14000321a  xor     r9d, r9d; lParam
0x14000321d  xor     r8d, r8d; wParam
0x140003220  mov     edx, 465h; Msg
0x140003225  mov     rcx, r14; hWnd
0x140003228  call    cs:PostMessageW; USER32
0x14000322e  jmp     loc_140003490
0x140003233  sub     eax, 201h
0x140003238  jz      loc_1400033A8
0x14000323e  sub     eax, 2
0x140003241  jz      loc_14000339A
0x140003247  cmp     eax, 262h
0x14000324c  jnz     loc_140002F51
0x140003252  xor     edx, edx
0x140003254  lea     rcx, [rbp+430h+Buffer]
0x14000325b  mov     r8d, 100h
0x140003261  call    sub_140005B30
0x140003266  xor     edx, edx
0x140003268  lea     rcx, [rbp+430h+Destination]
0x14000326f  mov     r8d, 100h
0x140003275  call    sub_140005B30
0x14000327a  xor     esi, esi
0x14000327c  lea     r8, asc_1400147F4; "  "
0x140003283  mov     edx, 80h; SizeInWords
0x140003288  lea     rcx, [rbp+430h+Destination]; Destination
0x14000328f  mov     edi, esi
0x140003291  call    wcscpy_s
0x140003296  mov     ebx, 43h ; 'C'
0x14000329b  mov     r15, 3A00200020h
0x1400032a5  nop     word ptr [rax+rax+00000000h]
0x1400032b0  movzx   eax, bx
0x1400032b3  sub     eax, 43h ; 'C'
0x1400032b6  movzx   ecx, al
0x1400032b9  mov     eax, cs:dword_140020C5C
0x1400032bf  bt      eax, ecx
0x1400032c2  jnb     short loc_1400032E3
0x1400032c4  mov     qword ptr [rbp+430h+Rect.left], r15
0x1400032c8  lea     r8, [rbp+430h+Rect]; Source
0x1400032cc  mov     edx, 80h; SizeInWords
0x1400032d1  mov     word ptr [rbp+430h+Rect.left+2], bx
0x1400032d5  lea     rcx, [rbp+430h+Destination]; Destination
0x1400032dc  call    wcscat_s
0x1400032e1  inc     edi
0x1400032e3  inc     bx
0x1400032e6  cmp     bx, 5Ah ; 'Z'
0x1400032ea  jbe     short loc_1400032B0
0x1400032ec  mov     ecx, esi
0x1400032ee  lea     rdx, [rbp+430h+Filename]
0x1400032f2  cmp     edi, 1
0x1400032f5  mov     r8d, 80h
0x1400032fb  setnz   cl
0x1400032fe  add     ecx, 3F9h
0x140003304  call    sub_140002140
0x140003309  lea     r9, [rbp+430h+Destination]
0x140003310  mov     edx, 80h; BufferCount
0x140003315  lea     r8, [rbp+430h+Filename]; Format
0x140003319  lea     rcx, [rbp+430h+Buffer]; Buffer
0x140003320  call    swprintf
0x140003325  mov     rax, cs:hInstance
0x14000332c  lea     rdx, [rbp+430h+pvParam]; lpRect
0x140003330  mov     qword ptr [rbp+430h+Paint.rgbReserved+4], rax
0x140003334  mov     rcx, r14; hWnd
0x140003337  lea     rax, [rbp+430h+Buffer]
0x14000333e  mov     dword ptr [rsp+530h+Paint.hdc], 48h ; 'H'
0x140003346  mov     qword ptr [rbp+430h+Paint.rgbReserved+0Ch], rax
0x14000334a  mov     dword ptr [rsp+530h+Paint.hdc+4], 10h
0x140003352  mov     qword ptr [rsp+530h+Paint.fErase], r14
0x140003357  mov     qword ptr [rbp+430h+Paint.rcPaint.top], rsi
0x14000335b  call    cs:GetClientRect; USER32
0x140003361  mov     eax, [rbp+430h+pvParam]
0x140003364  lea     r9, [rsp+530h+Paint]; lParam
0x140003369  mov     rcx, cs:qword_140020C40; hWnd
0x140003370  xor     r8d, r8d; wParam
0x140003373  mov     [rbp+430h+Paint.rcPaint.bottom], eax
0x140003376  mov     edx, 436h; Msg
0x14000337b  mov     eax, [rbp+430h+var_45C]
0x14000337e  mov     [rbp+430h+Paint.fRestore], eax
0x140003381  mov     eax, [rbp+430h+var_458]
0x140003384  mov     [rbp+430h+Paint.fIncUpdate], eax
0x140003387  mov     eax, [rbp+430h+var_454]
0x14000338a  mov     dword ptr [rbp+430h+Paint.rgbReserved], eax
0x14000338d  call    cs:SendMessageW; USER32
0x140003393  xor     eax, eax
0x140003395  jmp     loc_140003495
0x14000339a  xor     ecx, ecx
0x14000339c  call    sub_1400025D0
0x1400033a1  xor     eax, eax
0x1400033a3  jmp     loc_140003495
0x1400033a8  xor     r9d, r9d; lParam
0x1400033ab  mov     edx, 0A1h; Msg
0x1400033b0  mov     rcx, r14; hWnd
0x1400033b3  lea     r8d, [r9+2]; wParam
0x1400033b7  call    cs:SendMessageW; USER32
0x1400033bd  lea     rdx, [rbp+430h+pvParam]; lpRect
0x1400033c1  mov     rcx, r14; hWnd
0x1400033c4  call    cs:GetWindowRect; USER32
0x1400033ca  movzx   eax, word ptr [rbp+430h+pvParam]
0x1400033ce  xor     r9d, r9d; dwFlags
0x1400033d1  movzx   ebx, word ptr [rbp+430h+var_45C]
0x1400033d5  xor     r8d, r8d; hToken
0x1400033d8  shl     ebx, 10h
0x1400033db  mov     edx, 801Ah; csidl
0x1400033e0  or      ebx, eax
0x1400033e2  xor     ecx, ecx; hwnd
0x1400033e4  lea     rax, [rbp+430h+Filename]
0x1400033e8  mov     qword ptr [rsp+530h+bottom], rax; pszPath
0x1400033ed  call    cs:SHGetFolderPathW; SHELL32
0x1400033f3  test    eax, eax
0x1400033f5  js      loc_140003490
0x1400033fb  lea     r8, aShadowDefender_2; "\\Shadow Defender"
0x140003402  mov     edx, 104h; SizeInWords
0x140003407  lea     rcx, [rbp+430h+Filename]; Destination
0x14000340b  call    wcscat_s
0x140003410  xor     edx, edx; lpSecurityAttributes
0x140003412  lea     rcx, [rbp+430h+Filename]; lpPathName
0x140003416  call    cs:CreateDirectoryW; KERNEL32
0x14000341c  lea     r8, aUserDat; "\\user.dat"
0x140003423  mov     edx, 104h; SizeInWords
0x140003428  lea     rcx, [rbp+430h+Filename]; Destination
0x14000342c  call    wcscat_s
0x140003431  mov     r9d, ebx
0x140003434  lea     r8, aD; "%d"
0x14000343b  mov     edx, 20h ; ' '; BufferCount
0x140003440  lea     rcx, [rsp+530h+Paint]; Buffer
0x140003445  call    swprintf
0x14000344a  mov     edi, 5Ch ; '\'
0x14000344f  lea     rcx, [rbp+430h+Filename]; Str
0x140003453  mov     edx, edi; Ch
0x140003455  call    wcsrchr
0x14000345a  mov     rbx, rax
0x14000345d  test    rax, rax
0x140003460  jz      short loc_140003473
0x140003462  xor     esi, esi
0x140003464  lea     rcx, [rbp+430h+Filename]; Source
0x140003468  mov     [rax], si
0x14000346b  call    sub_140001040
0x140003470  mov     [rbx], di
0x140003473  lea     r9, [rbp+430h+Filename]; lpFileName
0x140003477  lea     r8, [rsp+530h+Paint]; lpString
0x14000347c  lea     rdx, aTippos; "tippos"
0x140003483  lea     rcx, aCommon; "common"
0x14000348a  call    cs:WritePrivateProfileStringW; KERNEL32
0x140003490  mov     eax, 1
0x140003495  mov     rcx, [rbp+430h+var_40]
0x14000349c  xor     rcx, rsp; StackCookie
0x14000349f  call    __security_check_cookie
0x1400034a4  add     rsp, 508h
0x1400034ab  pop     r15
0x1400034ad  pop     r14
0x1400034af  pop     rdi
0x1400034b0  pop     rsi
0x1400034b1  pop     rbx
0x1400034b2  pop     rbp
0x1400034b3  retn

// ===== sub_1400034C0 @ 0x1400034c0 =====

0x1400034c0  mov     [rsp+arg_0], rbx
0x1400034c5  mov     [rsp+arg_8], rsi
0x1400034ca  push    rdi
0x1400034cb  sub     rsp, 40h
0x1400034cf  mov     rax, cs:__security_cookie
0x1400034d6  xor     rax, rsp
0x1400034d9  mov     [rsp+48h+var_18], rax
0x1400034de  xor     edi, edi
0x1400034e0  mov     esi, ecx
0x1400034e2  mov     cs:dword_140020C5C, edi
0x1400034e8  mov     ebx, 43h ; 'C'
0x1400034ed  nop     dword ptr [rax]
0x1400034f0  movzx   ecx, bx
0x1400034f3  call    sub_140001110
0x1400034f8  test    eax, eax
0x1400034fa  jz      short loc_14000352A
0x1400034fc  lea     rdx, [rsp+48h+var_28]
0x140003501  movzx   ecx, bx
0x140003504  call    sub_140005210
0x140003509  test    eax, eax
0x14000350b  jz      short loc_14000352A
0x14000350d  cmp     [rsp+48h+var_24], 1
0x140003512  jnz     short loc_14000352A
0x140003514  movzx   eax, bx
0x140003517  mov     edx, 1
0x14000351c  sub     eax, 43h ; 'C'
0x14000351f  movzx   ecx, al
0x140003522  shl     edx, cl
0x140003524  or      cs:dword_140020C5C, edx
0x14000352a  inc     bx
0x14000352d  cmp     bx, 5Ah ; 'Z'
0x140003531  jbe     short loc_1400034F0
0x140003533  mov     rcx, cs:hWnd; hWnd
0x14000353a  xor     r9d, r9d; lParam
0x14000353d  xor     r8d, r8d; wParam
0x140003540  mov     edx, 465h; Msg
0x140003545  call    cs:SendMessageW; USER32
0x14000354b  test    esi, esi
0x14000354d  jz      short loc_140003561
0x14000354f  call    sub_1400023E0
0x140003554  test    eax, eax
0x140003556  setz    al
0x140003559  mov     cs:byte_140020C58, al
0x14000355f  jmp     short loc_140003568
0x140003561  movzx   eax, cs:byte_140020C58
0x140003568  cmp     cs:dword_140020C5C, edi
0x14000356e  jz      short loc_1400035AD
0x140003570  cmp     cs:byte_140020C5A, al
0x140003576  jz      short loc_1400035A0
0x140003578  mov     cs:byte_140020C5A, al
0x14000357e  test    al, al
0x140003580  jnz     short loc_140003597
0x140003582  lea     rcx, OutputString; "UpdateStatus: WM_DAEMONMSG, DM_SHOWTIP"
0x140003589  call    cs:OutputDebugStringW; KERNEL32
0x14000358f  mov     r8d, 1
0x140003595  jmp     short loc_1400035C0
0x140003597  lea     rcx, aUpdatestatusWm_0; "UpdateStatus: WM_DAEMONMSG, DM_HIDETIP"
0x14000359e  jmp     short loc_1400035B4
0x1400035a0  test    al, al
0x1400035a2  jnz     short loc_1400035D5
0x1400035a4  lea     rcx, aUpdatestatusWm_1; "UpdateStatus: WM_DAEMONMSG, DM_SHOWTIP "...
0x1400035ab  jmp     short loc_140003589
0x1400035ad  lea     rcx, aUpdatestatusWm_2; "UpdateStatus: WM_DAEMONMSG, DM_HIDETIP "...
0x1400035b4  call    cs:OutputDebugStringW; KERNEL32
0x1400035ba  mov     r8d, 2; wParam
0x1400035c0  mov     rcx, cs:qword_140020C30; hWnd
0x1400035c7  xor     r9d, r9d; lParam
0x1400035ca  mov     edx, 47Bh; Msg
0x1400035cf  call    cs:SendMessageW; USER32
0x1400035d5  test    esi, esi
0x1400035d7  jz      short loc_1400035EB
0x1400035d9  call    sub_1400024F0
0x1400035de  test    eax, eax
0x1400035e0  setz    al
0x1400035e3  mov     cs:byte_140020C59, al
0x1400035e9  jmp     short loc_1400035F2
0x1400035eb  movzx   eax, cs:byte_140020C59
0x1400035f2  cmp     cs:byte_140020C5B, al
0x1400035f8  jz      short loc_14000363C
0x1400035fa  mov     rcx, cs:qword_140020C30
0x140003601  mov     r8d, 2
0x140003607  mov     cs:byte_140020C5B, al
0x14000360d  test    al, al
0x14000360f  jnz     short loc_140003630
0x140003611  mov     edx, edi
0x140003613  cmp     cs:dword_140020C5C, edx
0x140003619  setnz   dl
0x14000361c  call    sub_140001DB0
0x140003621  cmp     cs:dword_140020C5C, edi
0x140003627  setnz   dil
0x14000362b  xor     r8d, r8d
0x14000362e  jmp     short loc_14000364C
0x140003630  cmp     cs:dword_140020C5C, edi
0x140003636  setnz   dil
0x14000363a  jmp     short loc_140003653
0x14000363c  cmp     cs:dword_140020C5C, edi
0x140003642  mov     r8d, 1
0x140003648  setnz   dil
0x14000364c  mov     rcx, cs:qword_140020C30
0x140003653  mov     edx, edi
0x140003655  call    sub_140001DB0
0x14000365a  mov     rcx, [rsp+48h+var_18]
0x14000365f  xor     rcx, rsp; StackCookie
0x140003662  call    __security_check_cookie
0x140003667  mov     rbx, [rsp+48h+arg_0]
0x14000366c  mov     rsi, [rsp+48h+arg_8]
0x140003671  add     rsp, 40h
0x140003675  pop     rdi
0x140003676  retn

// ===== WinMain @ 0x140003680 =====

0x140003680  mov     [rsp+arg_18], rsi
0x140003685  push    rdi
0x140003686  sub     rsp, 2A0h
0x14000368d  mov     rax, cs:__security_cookie
0x140003694  xor     rax, rsp
0x140003697  mov     [rsp+2A8h+var_18], rax
0x14000369f  mov     rsi, r8
0x1400036a2  mov     cs:hInstance, rcx
0x1400036a9  mov     rdi, rcx
0x1400036ac  lea     r8, Name; "Local\\Shadow Defender Daemon Mutex"
0x1400036b3  xor     ecx, ecx; lpMutexAttributes
0x1400036b5  xor     edx, edx; bInitialOwner
0x1400036b7  call    cs:CreateMutexW; KERNEL32
0x1400036bd  mov     cs:hObject, rax
0x1400036c4  test    rax, rax
0x1400036c7  jz      short loc_1400036E3
0x1400036c9  call    cs:GetLastError; KERNEL32
0x1400036cf  cmp     eax, 0B7h
0x1400036d4  jnz     short loc_1400036EA
0x1400036d6  mov     rcx, cs:hObject; hObject
0x1400036dd  call    cs:CloseHandle; KERNEL32
0x1400036e3  xor     eax, eax
0x1400036e5  jmp     loc_140003AC9
0x1400036ea  lea     r8, aGlobalC6f6a26f; "Global\\{C6F6A26F-B5C2-4284-9AB3-767CB9"...
0x1400036f1  mov     [rsp+2A8h+arg_8], rbx
0x1400036f9  xor     edx, edx; bInheritHandle
0x1400036fb  mov     ecx, 1F0003h; dwDesiredAccess
0x140003700  call    cs:OpenEventW; KERNEL32
0x140003706  mov     rbx, rax
0x140003709  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x14000370d  jz      short loc_140003726
0x14000370f  mov     edx, 0FFFFFFFFh; dwMilliseconds
0x140003714  mov     rcx, rax; hHandle
0x140003717  call    cs:WaitForSingleObject; KERNEL32
0x14000371d  mov     rcx, rbx; hObject
0x140003720  call    cs:CloseHandle; KERNEL32
0x140003726  lea     rdx, aAuto; "/Auto"
0x14000372d  mov     rcx, rsi; String1
0x140003730  call    _wcsicmp
0x140003735  xor     esi, esi
0x140003737  test    eax, eax
0x140003739  jnz     loc_1400037EB
0x14000373f  lea     rax, [rsp+2A8h+var_278]
0x140003744  mov     [rsp+2A8h+var_278], 208h
0x14000374c  mov     [rsp+2A8h+pcbData], rax; pcbData
0x140003751  lea     r9, [rsp+2A8h+pdwType]; pdwType
0x140003756  lea     rax, [rsp+2A8h+Filename]
0x14000375e  mov     rcx, 0FFFFFFFF80000002h; hkey
0x140003765  lea     r8, pszValue; "Path"
0x14000376c  mov     [rsp+2A8h+pvData], rax; pvData
0x140003771  lea     rdx, pszSubKey; "SOFTWARE\\Shadow Defender"
0x140003778  call    cs:SHGetValueW; SHLWAPI
0x14000377e  test    eax, eax
0x140003780  jz      short loc_1400037AB
0x140003782  mov     r8d, 104h; nSize
0x140003788  lea     rdx, [rsp+2A8h+Filename]; lpFilename
0x140003790  xor     ecx, ecx; hModule
0x140003792  call    cs:GetModuleFileNameW; KERNEL32
0x140003798  lea     edx, [rsi+5Ch]; Ch
0x14000379b  lea     rcx, [rsp+2A8h+Filename]; Str
0x1400037a3  call    wcsrchr
0x1400037a8  mov     [rax], si
0x1400037ab  lea     r8, aUserDat; "\\user.dat"
0x1400037b2  mov     edx, 104h; SizeInWords
0x1400037b7  lea     rcx, [rsp+2A8h+Filename]; Destination
0x1400037bf  call    wcscat_s
0x1400037c4  lea     r9, [rsp+2A8h+Filename]; lpFileName
0x1400037cc  mov     r8d, 1; nDefault
0x1400037d2  lea     rdx, aAutostart; "autostart"
0x1400037d9  lea     rcx, aCommon; "common"
0x1400037e0  call    cs:GetPrivateProfileIntW; KERNEL32
0x1400037e6  cmp     eax, 1
0x1400037e9  jnz     short loc_1400037F4
0x1400037eb  call    sub_140005420
0x1400037f0  test    eax, eax
0x1400037f2  jnz     short loc_140003808
0x1400037f4  mov     rcx, cs:hObject; hObject
0x1400037fb  call    cs:CloseHandle; KERNEL32
0x140003801  xor     eax, eax
0x140003803  jmp     loc_140003AC1
0x140003808  mov     cs:dword_140020C5C, esi
0x14000380e  mov     ebx, 43h ; 'C'
0x140003813  movzx   ecx, bx
0x140003816  call    sub_140001110
0x14000381b  test    eax, eax
0x14000381d  jz      short loc_14000384A
0x14000381f  lea     rdx, [rsp+2A8h+var_240]
0x140003824  movzx   ecx, bx
0x140003827  call    sub_140005210
0x14000382c  test    eax, eax
0x14000382e  jz      short loc_14000384A
0x140003830  cmp     [rsp+2A8h+var_23C], 1
0x140003835  jnz     short loc_14000384A
0x140003837  movzx   ecx, bx
0x14000383a  mov     edx, 1
0x14000383f  sub     ecx, 43h ; 'C'
0x140003842  shl     edx, cl
0x140003844  or      cs:dword_140020C5C, edx
0x14000384a  inc     bx
0x14000384d  cmp     bx, 5Ah ; 'Z'
0x140003851  jbe     short loc_140003813
0x140003853  call    sub_1400023E0
0x140003858  test    eax, eax
0x14000385a  setz    cs:byte_140020C58
0x140003861  call    sub_1400024F0
0x140003866  test    eax, eax
0x140003868  mov     [rsp+2A8h+pvData], rsi; dwInitParam
0x14000386d  movzx   eax, cs:byte_140020C58
0x140003874  lea     r9, sub_1400014F0; lpDialogFunc
0x14000387b  setz    cl
0x14000387e  mov     cs:byte_140020C5A, al
0x140003884  xor     r8d, r8d; hWndParent
0x140003887  mov     cs:byte_140020C59, cl
0x14000388d  mov     cs:byte_140020C5B, cl
0x140003893  mov     rcx, rdi; hInstance
0x140003896  lea     edx, [r8+65h]; lpTemplateName
0x14000389a  call    cs:CreateDialogParamW; USER32
0x1400038a0  mov     rcx, rax; hWnd
0x1400038a3  lea     rdx, aShadowDefender_4; "Shadow Defender Daemon Window"
0x1400038aa  mov     rbx, rax
0x1400038ad  call    cs:SetWindowTextW; USER32
0x1400038b3  mov     edx, 0FFFFFFECh; nIndex
0x1400038b8  mov     rcx, rbx; hWnd
0x1400038bb  call    cs:GetWindowLongW; USER32
0x1400038c1  mov     edx, 0FFFFFFECh; nIndex
0x1400038c6  mov     rcx, rbx; hWnd
0x1400038c9  bts     eax, 7
0x1400038cd  mov     r8d, eax; dwNewLong
0x1400038d0  call    cs:SetWindowLongW; USER32
0x1400038d6  xor     r9d, r9d; nWidth
0x1400038d9  mov     dword ptr [rsp+2A8h+pcbData], esi; bRepaint
0x1400038dd  xor     r8d, r8d; Y
0x1400038e0  mov     dword ptr [rsp+2A8h+pvData], esi; nHeight
0x1400038e4  xor     edx, edx; X
0x1400038e6  mov     rcx, rbx; hWnd
0x1400038e9  call    cs:MoveWindow; USER32
0x1400038ef  mov     edx, 5; nCmdShow
0x1400038f4  mov     rcx, rbx; hWnd
0x1400038f7  call    cs:ShowWindow; USER32
0x1400038fd  xor     edx, edx; nCmdShow
0x1400038ff  mov     rcx, rbx; hWnd
0x140003902  call    cs:ShowWindow; USER32
0x140003908  cmp     cs:dword_140020C5C, esi
0x14000390e  mov     cs:qword_140020C30, rbx
0x140003915  jz      short loc_14000392F
0x140003917  cmp     cs:byte_140020C58, sil
0x14000391e  jnz     short loc_14000392F
0x140003920  mov     rcx, rdi; hInstance
0x140003923  call    sub_140001330
0x140003928  mov     cs:hWnd, rax
0x14000392f  xor     r9d, r9d; lpName
0x140003932  xor     r8d, r8d; bInitialState
0x140003935  xor     ecx, ecx; lpEventAttributes
0x140003937  lea     edx, [r9+1]; bManualReset
0x14000393b  call    cs:CreateEventW; KERNEL32
0x140003941  mov     cs:qword_140020C48, rax
0x140003948  test    rax, rax
0x14000394b  jz      short loc_140003988
0x14000394d  mov     [rsp+2A8h+pcbData], rsi; lpThreadId
0x140003952  lea     r8, StartAddress; lpStartAddress
0x140003959  xor     r9d, r9d; lpParameter
0x14000395c  mov     dword ptr [rsp+2A8h+pvData], 4; dwCreationFlags
0x140003964  xor     edx, edx; dwStackSize
0x140003966  xor     ecx, ecx; lpThreadAttributes
0x140003968  call    cs:CreateThread; KERNEL32
0x14000396e  mov     rbx, rax
0x140003971  test    rax, rax
0x140003974  jz      short loc_140003988
0x140003976  mov     rcx, rax; hThread
0x140003979  call    cs:ResumeThread; KERNEL32
0x14000397f  mov     rcx, rbx; hObject
0x140003982  call    cs:CloseHandle; KERNEL32
0x140003988  xor     r9d, r9d; lpName
0x14000398b  xor     r8d, r8d; bInitialState
0x14000398e  xor     ecx, ecx; lpEventAttributes
0x140003990  lea     edx, [r9+1]; bManualReset
0x140003994  call    cs:CreateEventW; KERNEL32
0x14000399a  mov     cs:hEvent, rax
0x1400039a1  test    rax, rax
0x1400039a4  jz      short loc_1400039E1
0x1400039a6  mov     [rsp+2A8h+pcbData], rsi; lpThreadId
0x1400039ab  lea     r8, sub_1400027A0; lpStartAddress
0x1400039b2  xor     r9d, r9d; lpParameter
0x1400039b5  mov     dword ptr [rsp+2A8h+pvData], 4; dwCreationFlags
0x1400039bd  xor     edx, edx; dwStackSize
0x1400039bf  xor     ecx, ecx; lpThreadAttributes
0x1400039c1  call    cs:CreateThread; KERNEL32
0x1400039c7  mov     rbx, rax
0x1400039ca  test    rax, rax
0x1400039cd  jz      short loc_1400039E1
0x1400039cf  mov     rcx, rax; hThread
0x1400039d2  call    cs:ResumeThread; KERNEL32
0x1400039d8  mov     rcx, rbx; hObject
0x1400039db  call    cs:CloseHandle; KERNEL32
0x1400039e1  mov     rcx, cs:qword_140020C30; hWnd
0x1400039e8  xor     edx, edx; id
0x1400039ea  lea     r9d, [rdx+75h]; vk
0x1400039ee  lea     r8d, [rdx+7]; fsModifiers
0x1400039f2  call    cs:RegisterHotKey; USER32
0x1400039f8  lea     rcx, LibFileName; "ShellExt.dll"
0x1400039ff  call    cs:LoadLibraryW; KERNEL32
0x140003a05  test    rax, rax
0x140003a08  jz      short loc_140003A21
0x140003a0a  lea     rdx, ProcName; "SetWorkMode"
0x140003a11  mov     rcx, rax; hModule
0x140003a14  call    cs:GetProcAddress; KERNEL32
0x140003a1a  mov     ecx, 1
0x140003a1f  call    rax
0x140003a21  xor     r9d, r9d; wMsgFilterMax
0x140003a24  lea     rcx, [rsp+2A8h+Msg]; lpMsg
0x140003a29  xor     r8d, r8d; wMsgFilterMin
0x140003a2c  xor     edx, edx; hWnd
0x140003a2e  call    cs:GetMessageW; USER32
0x140003a34  test    eax, eax
0x140003a36  jz      short loc_140003A6D
0x140003a38  nop     dword ptr [rax+rax+00000000h]
0x140003a40  lea     rcx, [rsp+2A8h+Msg]; lpMsg
0x140003a45  call    cs:TranslateMessage; USER32
0x140003a4b  lea     rcx, [rsp+2A8h+Msg]; lpMsg
0x140003a50  call    cs:DispatchMessageW; USER32
0x140003a56  xor     r9d, r9d; wMsgFilterMax
0x140003a59  lea     rcx, [rsp+2A8h+Msg]; lpMsg
0x140003a5e  xor     r8d, r8d; wMsgFilterMin
0x140003a61  xor     edx, edx; hWnd
0x140003a63  call    cs:GetMessageW; USER32
0x140003a69  test    eax, eax
0x140003a6b  jnz     short loc_140003A40
0x140003a6d  mov     rcx, cs:hEvent; hEvent
0x140003a74  test    rcx, rcx
0x140003a77  jz      short loc_140003A8C
0x140003a79  call    cs:SetEvent; KERNEL32
0x140003a7f  mov     rcx, cs:hEvent; hObject
0x140003a86  call    cs:CloseHandle; KERNEL32
0x140003a8c  mov     rcx, cs:qword_140020C48; hEvent
0x140003a93  test    rcx, rcx
0x140003a96  jz      short loc_140003AAB
0x140003a98  call    cs:SetEvent; KERNEL32
0x140003a9e  mov     rcx, cs:qword_140020C48; hObject
0x140003aa5  call    cs:CloseHandle; KERNEL32
0x140003aab  call    sub_140004D80
0x140003ab0  mov     rcx, cs:hObject; hObject
0x140003ab7  call    cs:CloseHandle; KERNEL32
0x140003abd  mov     eax, dword ptr [rsp+2A8h+Msg.wParam]
0x140003ac1  mov     rbx, [rsp+2A8h+arg_8]
0x140003ac9  mov     rcx, [rsp+2A8h+var_18]
0x140003ad1  xor     rcx, rsp; StackCookie
0x140003ad4  call    __security_check_cookie
0x140003ad9  mov     rsi, [rsp+2A8h+arg_18]
0x140003ae1  add     rsp, 2A0h
0x140003ae8  pop     rdi
0x140003ae9  retn

// ===== sub_140003AEC @ 0x140003aec =====

0x140003aec  mov     rax, rsp
0x140003aef  mov     [rax+10h], rbx
0x140003af3  mov     [rax+18h], rsi
0x140003af7  mov     [rax+20h], rdi
0x140003afb  push    rbp
0x140003afc  lea     rbp, [rax-68h]
0x140003b00  sub     rsp, 160h
0x140003b07  mov     rax, cs:__security_cookie
0x140003b0e  xor     rax, rsp
0x140003b11  mov     [rbp+60h+var_10], rax
0x140003b15  lea     rax, [rsp+160h+hKey]
0x140003b1a  mov     rdi, rcx
0x140003b1d  lea     rdx, SubKey; "CLSID\\{ADB880A6-D8FF-11CF-9377-00AA003"...
0x140003b24  mov     r9d, 20019h; samDesired
0x140003b2a  xor     r8d, r8d; ulOptions
0x140003b2d  mov     rcx, 0FFFFFFFF80000000h; hKey
0x140003b34  mov     [rsp+160h+phkResult], rax; phkResult
0x140003b39  xor     ebx, ebx
0x140003b3b  call    cs:RegOpenKeyExA; ADVAPI32
0x140003b41  test    eax, eax
0x140003b43  jnz     loc_140003BF3
0x140003b49  mov     rcx, [rsp+160h+hKey]; hKey
0x140003b4e  lea     rax, [rsp+160h+cbData+4]
0x140003b53  lea     r9, [rsp+160h+cbData]; lpType
0x140003b58  mov     [rsp+160h+lpcbData], rax; lpcbData
0x140003b5d  lea     rax, [rsp+160h+Data]
0x140003b62  mov     esi, 104h
0x140003b67  xor     r8d, r8d; lpReserved
0x140003b6a  xor     edx, edx; lpValueName
0x140003b6c  mov     [rsp+160h+cbData], 1
0x140003b74  mov     [rsp+160h+phkResult], rax; lpData
0x140003b79  mov     [rsp+160h+cbData+4], esi
0x140003b7d  call    cs:RegQueryValueExA; ADVAPI32
0x140003b83  test    eax, eax
0x140003b85  jnz     short loc_140003BE4
0x140003b87  cmp     [rsp+160h+cbData], 2
0x140003b8c  mov     [rbp+60h+var_1D], bl
0x140003b8f  lea     rcx, [rsp+160h+Data]; lpSrc
0x140003b94  jnz     short loc_140003BAE
0x140003b96  mov     r8d, esi; nSize
0x140003b99  mov     rdx, rdi; lpDst
0x140003b9c  call    cs:ExpandEnvironmentStringsA; KERNEL32
0x140003ba2  dec     eax
0x140003ba4  cmp     eax, 103h
0x140003ba9  setbe   bl
0x140003bac  jmp     short loc_140003BE4
0x140003bae  mov     edx, ebx
0x140003bb0  sub     rcx, rdi
0x140003bb3  lea     rax, [rsi+7FFFFEFAh]
0x140003bba  test    rax, rax
0x140003bbd  jz      short loc_140003BD0
0x140003bbf  mov     al, [rcx+rdi]
0x140003bc2  test    al, al
0x140003bc4  jz      short loc_140003BD0
0x140003bc6  mov     [rdi], al
0x140003bc8  inc     rdi
0x140003bcb  dec     rsi
0x140003bce  jnz     short loc_140003BB3
0x140003bd0  test    rsi, rsi
0x140003bd3  jnz     short loc_140003BDD
0x140003bd5  dec     rdi
0x140003bd8  mov     edx, 8007007Ah
0x140003bdd  test    edx, edx
0x140003bdf  mov     [rdi], bl
0x140003be1  setns   bl
0x140003be4  mov     rcx, [rsp+160h+hKey]; hKey
0x140003be9  call    cs:RegCloseKey; ADVAPI32
0x140003bef  mov     eax, ebx
0x140003bf1  jmp     short loc_140003BF5
0x140003bf3  xor     eax, eax
0x140003bf5  mov     rcx, [rbp+60h+var_10]
0x140003bf9  xor     rcx, rsp; StackCookie
0x140003bfc  call    __security_check_cookie
0x140003c01  lea     r11, [rsp+160h+var_s0]
0x140003c09  mov     rbx, [r11+18h]
0x140003c0d  mov     rsi, [r11+20h]
0x140003c11  mov     rdi, [r11+28h]
0x140003c15  mov     rsp, r11
0x140003c18  pop     rbp
0x140003c19  retn

// ===== sub_140003C1C @ 0x140003c1c =====

0x140003c1c  push    rbx
0x140003c1e  push    rbp
0x140003c1f  push    rsi
0x140003c20  push    rdi
0x140003c21  push    r14
0x140003c23  sub     rsp, 140h
0x140003c2a  mov     rax, cs:__security_cookie
0x140003c31  xor     rax, rsp
0x140003c34  mov     [rsp+168h+var_38], rax
0x140003c3c  mov     rax, cs:hModule
0x140003c43  mov     r14, r9
0x140003c46  mov     ebp, r8d
0x140003c49  mov     rsi, rdx
0x140003c4c  mov     rdi, rcx
0x140003c4f  test    rax, rax
0x140003c52  jnz     short loc_140003CBB
0x140003c54  cmp     cs:dword_140020D98, eax
0x140003c5a  jnz     short loc_140003CBB
0x140003c5c  lea     rcx, [rsp+168h+LibFileName]; lpDst
0x140003c61  call    sub_140003AEC
0x140003c66  test    eax, eax
0x140003c68  jz      short loc_140003C83
0x140003c6a  lea     rcx, [rsp+168h+LibFileName]; lpLibFileName
0x140003c6f  xor     r8d, r8d; dwFlags
0x140003c72  xor     edx, edx; hFile
0x140003c74  call    cs:LoadLibraryExA; KERNEL32
0x140003c7a  mov     cs:hModule, rax
0x140003c81  jmp     short loc_140003C8A
0x140003c83  mov     rax, cs:hModule
0x140003c8a  test    rax, rax
0x140003c8d  jnz     short loc_140003CBB
0x140003c8f  lea     rcx, aHhctrlOcx; "hhctrl.ocx"
0x140003c96  xor     r8d, r8d; dwFlags
0x140003c99  xor     edx, edx; hFile
0x140003c9b  call    cs:LoadLibraryExA; KERNEL32
0x140003ca1  mov     cs:hModule, rax
0x140003ca8  test    rax, rax
0x140003cab  jnz     short loc_140003CBB
0x140003cad  mov     cs:dword_140020D98, 1
0x140003cb7  xor     eax, eax
0x140003cb9  jmp     short loc_140003CF9
0x140003cbb  mov     rbx, cs:qword_140020D90
0x140003cc2  test    rbx, rbx
0x140003cc5  jnz     short loc_140003CE2
0x140003cc7  lea     edx, [rbx+0Fh]; lpProcName
0x140003cca  mov     rcx, rax; hModule
0x140003ccd  call    cs:GetProcAddress; KERNEL32
0x140003cd3  mov     rbx, rax
0x140003cd6  mov     cs:qword_140020D90, rax
0x140003cdd  test    rax, rax
0x140003ce0  jz      short loc_140003CAD
0x140003ce2  mov     rcx, rbx
0x140003ce5  call    cs:__guard_check_icall_fptr
0x140003ceb  mov     r9, r14
0x140003cee  mov     r8d, ebp
0x140003cf1  mov     rdx, rsi
0x140003cf4  mov     rcx, rdi
0x140003cf7  call    rbx ; qword_140020D90
0x140003cf9  mov     rcx, [rsp+168h+var_38]
0x140003d01  xor     rcx, rsp; StackCookie
0x140003d04  call    __security_check_cookie
0x140003d09  add     rsp, 140h
0x140003d10  pop     r14
0x140003d12  pop     rdi
0x140003d13  pop     rsi
0x140003d14  pop     rbp
0x140003d15  pop     rbx
0x140003d16  retn

// ===== _guard_check_icall_nop @ 0x140003d18 =====

0x140003d18  retn    0

// ===== j_j_j__free_base @ 0x140003d1c =====

0x140003d1c  jmp     j_j__free_base

// ===== __GSHandlerCheck @ 0x140003d24 =====

0x140003d24  sub     rsp, 28h
0x140003d28  mov     r8, [r9+38h]
0x140003d2c  mov     rcx, rdx
0x140003d2f  mov     rdx, r9
0x140003d32  call    __GSHandlerCheckCommon
0x140003d37  mov     eax, 1
0x140003d3c  add     rsp, 28h
0x140003d40  retn

// ===== __GSHandlerCheckCommon @ 0x140003d44 =====

0x140003d44  push    rbx
0x140003d46  mov     r11d, [r8]
0x140003d49  mov     rbx, rdx
0x140003d4c  and     r11d, 0FFFFFFF8h
0x140003d50  mov     r9, rcx
0x140003d53  test    byte ptr [r8], 4
0x140003d57  mov     r10, rcx
0x140003d5a  jz      short loc_140003D6F
0x140003d5c  mov     eax, [r8+8]
0x140003d60  movsxd  r10, dword ptr [r8+4]
0x140003d64  neg     eax
0x140003d66  add     r10, rcx
0x140003d69  movsxd  rcx, eax
0x140003d6c  and     r10, rcx
0x140003d6f  movsxd  rax, r11d
0x140003d72  mov     rdx, [rax+r10]
0x140003d76  mov     rax, [rbx+10h]
0x140003d7a  mov     ecx, [rax+8]
0x140003d7d  mov     rax, [rbx+8]
0x140003d81  test    byte ptr [rcx+rax+3], 0Fh
0x140003d86  jz      short loc_140003D93
0x140003d88  movzx   eax, byte ptr [rcx+rax+3]
0x140003d8d  and     eax, 0FFFFFFF0h
0x140003d90  add     r9, rax
0x140003d93  xor     r9, rdx
0x140003d96  mov     rcx, r9; StackCookie
0x140003d99  pop     rbx
0x140003d9a  jmp     __security_check_cookie

// ===== __security_check_cookie @ 0x140003db0 =====

0x140003db0  cmp     rcx, cs:__security_cookie
0x140003db7  bnd jnz short ReportFailure
0x140003dba  rol     rcx, 10h
0x140003dbe  test    cx, 0FFFFh
0x140003dc3  bnd jnz short RestoreRcx
0x140003dc6  bnd retn
0x140003dc8  ror     rcx, 10h; StackCookie
0x140003dcc  jmp     __report_gsfailure

// ===== sub_140003DD4 @ 0x140003dd4 =====

0x140003dd4  push    rbx
0x140003dd6  sub     rsp, 20h
0x140003dda  lea     rax, ??_7type_info@@6B@; const type_info::`vftable'
0x140003de1  mov     rbx, rcx
0x140003de4  mov     [rcx], rax
0x140003de7  test    dl, 1
0x140003dea  jz      short loc_140003DF6
0x140003dec  mov     edx, 18h
0x140003df1  call    j_j_j__free_base
0x140003df6  mov     rax, rbx
0x140003df9  add     rsp, 20h
0x140003dfd  pop     rbx
0x140003dfe  retn

// ===== j_??2@YAPEAX_K@Z @ 0x140003e00 =====

0x140003e00  jmp     ??2@YAPEAX_K@Z

// ===== _alloca_probe @ 0x140003e20 =====

0x140003e20  sub     rsp, 10h
0x140003e24  mov     [rsp+10h+var_10], r10
0x140003e28  mov     [rsp+10h+var_8], r11
0x140003e2d  xor     r11, r11
0x140003e30  lea     r10, [rsp+10h+arg_0]
0x140003e35  sub     r10, rax
0x140003e38  cmovb   r10, r11
0x140003e3c  mov     r11, gs:10h
0x140003e45  cmp     r10, r11
0x140003e48  bnd jnb short cs20
0x140003e4b  and     r10w, 0F000h
0x140003e51  lea     r11, [r11-1000h]
0x140003e58  mov     byte ptr [r11], 0
0x140003e5c  cmp     r10, r11
0x140003e5f  bnd jnz short cs10
0x140003e62  mov     r10, [rsp+10h+var_10]
0x140003e66  mov     r11, [rsp+10h+var_8]
0x140003e6b  add     rsp, 10h
0x140003e6f  bnd retn

// ===== __raise_securityfailure @ 0x140003e74 =====

0x140003e74  push    rbx
0x140003e76  sub     rsp, 20h
0x140003e7a  mov     rbx, rcx
0x140003e7d  xor     ecx, ecx; lpTopLevelExceptionFilter
0x140003e7f  call    cs:SetUnhandledExceptionFilter; KERNEL32
0x140003e85  mov     rcx, rbx; ExceptionInfo
0x140003e88  call    cs:UnhandledExceptionFilter; KERNEL32
0x140003e8e  call    cs:GetCurrentProcess; KERNEL32
0x140003e94  mov     rcx, rax
0x140003e97  mov     edx, 0C0000409h
0x140003e9c  add     rsp, 20h
0x140003ea0  pop     rbx
0x140003ea1  jmp     cs:TerminateProcess; KERNEL32

// ===== __report_gsfailure @ 0x140003ea8 =====

0x140003ea8  mov     [rsp+arg_0], rcx
0x140003ead  sub     rsp, 38h
0x140003eb1  mov     ecx, 17h; ProcessorFeature
0x140003eb6  call    IsProcessorFeaturePresent
0x140003ebb  test    eax, eax
0x140003ebd  jz      short loc_140003EC6
0x140003ebf  mov     ecx, 2
0x140003ec4  int     29h; Win8: RtlFailFast(ecx)
0x140003ec6  lea     rcx, ContextRecord; ContextRecord
0x140003ecd  call    capture_previous_context
0x140003ed2  mov     rax, [rsp+38h]
0x140003ed7  mov     cs:ContextRecord.Rip, rax
0x140003ede  lea     rax, [rsp+38h]
0x140003ee3  add     rax, 8
0x140003ee7  mov     cs:ContextRecord.Rsp, rax
0x140003eee  mov     rax, cs:ContextRecord.Rip
0x140003ef5  mov     cs:qword_140020DC0, rax
0x140003efc  mov     rax, [rsp+38h+arg_0]
0x140003f01  mov     cs:ContextRecord.Rcx, rax
0x140003f08  mov     cs:dword_140020DB0, 0C0000409h
0x140003f12  mov     cs:dword_140020DB4, 1
0x140003f1c  mov     cs:dword_140020DC8, 1
0x140003f26  mov     eax, 8
0x140003f2b  imul    rax, 0
0x140003f2f  lea     rcx, unk_140020DD0
0x140003f36  mov     qword ptr [rcx+rax], 2
0x140003f3e  mov     eax, 8
0x140003f43  imul    rax, 0
0x140003f47  mov     rcx, cs:__security_cookie
0x140003f4e  mov     [rsp+rax+38h+var_18], rcx
0x140003f53  mov     eax, 8
0x140003f58  imul    rax, 1
0x140003f5c  mov     rcx, cs:qword_140020000
0x140003f63  mov     [rsp+rax+38h+var_18], rcx
0x140003f68  lea     rcx, ExceptionInfo; ExceptionInfo
0x140003f6f  call    __raise_securityfailure
0x140003f74  add     rsp, 38h
0x140003f78  retn

// ===== __report_rangecheckfailure @ 0x140003f7c =====

0x140003f7c  sub     rsp, 28h
0x140003f80  mov     ecx, 8
0x140003f85  call    __report_securityfailure
0x140003f8a  add     rsp, 28h
0x140003f8e  retn

// ===== __report_securityfailure @ 0x140003f90 =====

0x140003f90  mov     [rsp+arg_0], ecx
0x140003f94  sub     rsp, 28h
0x140003f98  mov     ecx, 17h; ProcessorFeature
0x140003f9d  call    IsProcessorFeaturePresent
0x140003fa2  test    eax, eax
0x140003fa4  jz      short loc_140003FAE
0x140003fa6  mov     eax, [rsp+28h+arg_0]
0x140003faa  mov     ecx, eax
0x140003fac  int     29h; Win8: RtlFailFast(ecx)
0x140003fae  lea     rcx, ContextRecord; ContextRecord
0x140003fb5  call    capture_current_context
0x140003fba  mov     rax, [rsp+28h]
0x140003fbf  mov     cs:ContextRecord.Rip, rax
0x140003fc6  lea     rax, [rsp+28h]
0x140003fcb  add     rax, 8
0x140003fcf  mov     cs:ContextRecord.Rsp, rax
0x140003fd6  mov     rax, cs:ContextRecord.Rip
0x140003fdd  mov     cs:qword_140020DC0, rax
0x140003fe4  mov     cs:dword_140020DB0, 0C0000409h
0x140003fee  mov     cs:dword_140020DB4, 1
0x140003ff8  mov     cs:dword_140020DC8, 1
0x140004002  mov     eax, 8
0x140004007  imul    rax, 0
0x14000400b  lea     rcx, unk_140020DD0
0x140004012  mov     edx, [rsp+28h+arg_0]
0x140004016  mov     [rcx+rax], rdx
0x14000401a  lea     rcx, ExceptionInfo; ExceptionInfo
0x140004021  call    __raise_securityfailure
0x140004026  add     rsp, 28h
0x14000402a  retn

// ===== capture_current_context @ 0x14000402c =====

0x14000402c  mov     [rsp+arg_18], rbx
0x140004031  push    rdi
0x140004032  sub     rsp, 40h
0x140004036  mov     rbx, rcx
0x140004039  call    cs:RtlCaptureContext; KERNEL32
0x14000403f  mov     rdi, [rbx+0F8h]
0x140004046  lea     rdx, [rsp+48h+ImageBase]; ImageBase
0x14000404b  mov     rcx, rdi; ControlPc
0x14000404e  xor     r8d, r8d; HistoryTable
0x140004051  call    cs:RtlLookupFunctionEntry; KERNEL32
0x140004057  test    rax, rax
0x14000405a  jz      short loc_14000408E
0x14000405c  and     [rsp+48h+var_10], 0
0x140004062  lea     rcx, [rsp+48h+arg_8]
0x140004067  mov     rdx, [rsp+48h+ImageBase]; ImageBase
0x14000406c  mov     r9, rax; FunctionEntry
0x14000406f  mov     [rsp+48h+EstablisherFrame], rcx; EstablisherFrame
0x140004074  mov     r8, rdi; ControlPc
0x140004077  lea     rcx, [rsp+48h+arg_10]
0x14000407c  mov     [rsp+48h+HandlerData], rcx; HandlerData
0x140004081  xor     ecx, ecx; HandlerType
0x140004083  mov     [rsp+48h+ContextRecord], rbx; ContextRecord
0x140004088  call    cs:RtlVirtualUnwind; KERNEL32
0x14000408e  mov     rbx, [rsp+48h+arg_18]
0x140004093  add     rsp, 40h
0x140004097  pop     rdi
0x140004098  retn

// ===== capture_previous_context @ 0x14000409c =====

0x14000409c  push    rbx
0x14000409e  push    rsi
0x14000409f  push    rdi
0x1400040a0  sub     rsp, 40h
0x1400040a4  mov     rbx, rcx
0x1400040a7  call    cs:RtlCaptureContext; KERNEL32
0x1400040ad  mov     rsi, [rbx+0F8h]
0x1400040b4  xor     edi, edi
0x1400040b6  xor     r8d, r8d; HistoryTable
0x1400040b9  lea     rdx, [rsp+58h+ImageBase]; ImageBase
0x1400040be  mov     rcx, rsi; ControlPc
0x1400040c1  call    cs:RtlLookupFunctionEntry; KERNEL32
0x1400040c7  test    rax, rax
0x1400040ca  jz      short loc_140004105
0x1400040cc  and     [rsp+58h+var_20], 0
0x1400040d2  lea     rcx, [rsp+58h+arg_8]
0x1400040d7  mov     rdx, [rsp+58h+ImageBase]; ImageBase
0x1400040dc  mov     r9, rax; FunctionEntry
0x1400040df  mov     [rsp+58h+EstablisherFrame], rcx; EstablisherFrame
0x1400040e4  mov     r8, rsi; ControlPc
0x1400040e7  lea     rcx, [rsp+58h+arg_10]
0x1400040ec  mov     [rsp+58h+HandlerData], rcx; HandlerData
0x1400040f1  xor     ecx, ecx; HandlerType
0x1400040f3  mov     [rsp+58h+ContextRecord], rbx; ContextRecord
0x1400040f8  call    cs:RtlVirtualUnwind; KERNEL32
0x1400040fe  inc     edi
0x140004100  cmp     edi, 2
0x140004103  jl      short loc_1400040B6
0x140004105  add     rsp, 40h
0x140004109  pop     rdi
0x14000410a  pop     rsi
0x14000410b  pop     rbx
0x14000410c  retn

// ===== ?pre_c_initialization@@YAHXZ @ 0x140004110 =====

0x140004110  push    rbx
0x140004112  sub     rsp, 20h
0x140004116  mov     ecx, 2
0x14000411b  call    sub_140008708
0x140004120  call    _get_startup_file_mode
0x140004125  mov     ecx, eax; Mode
0x140004127  call    _set_fmode
0x14000412c  call    sub_14000923C
0x140004131  mov     rbx, rax
0x140004134  call    UserMathErrorFunction
0x140004139  mov     ecx, 1
0x14000413e  mov     [rbx], eax
0x140004140  call    __scrt_initialize_onexit_tables
0x140004145  test    al, al
0x140004147  jz      short loc_1400041BC
0x140004149  call    sub_1400049BC
0x14000414e  lea     rcx, sub_1400049F8; void (__cdecl *)()
0x140004155  call    atexit
0x14000415a  call    ?raw_length@charNode@@UEBAHXZ
0x14000415f  mov     ecx, eax; mode
0x140004161  call    _configure_wide_argv
0x140004166  test    eax, eax
0x140004168  jnz     short loc_1400041BC
0x14000416a  call    sub_140004734
0x14000416f  call    __scrt_is_user_matherr_present
0x140004174  test    eax, eax
0x140004176  jz      short loc_140004184
0x140004178  lea     rcx, UserMathErrorFunction; UserMathErrorFunction
0x14000417f  call    __setusermatherr
0x140004184  call    _guard_check_icall_nop
0x140004189  call    _guard_check_icall_nop
0x14000418e  call    UserMathErrorFunction
0x140004193  mov     ecx, eax; Flag
0x140004195  call    _configthreadlocale
0x14000419a  call    sub_140004744
0x14000419f  test    al, al
0x1400041a1  jz      short loc_1400041A8
0x1400041a3  call    j_??$common_initialize_environment_nolock@_W@@YAHXZ
0x1400041a8  call    UserMathErrorFunction
0x1400041ad  call    j_UserMathErrorFunction
0x1400041b2  test    eax, eax
0x1400041b4  jnz     short loc_1400041BC
0x1400041b6  add     rsp, 20h
0x1400041ba  pop     rbx
0x1400041bb  retn
0x1400041bc  mov     ecx, 7
0x1400041c1  call    __scrt_fastfail

// ===== ?post_pgo_initialization@@YAHXZ @ 0x1400041c8 =====

0x1400041c8  sub     rsp, 28h
0x1400041cc  call    __scrt_initialize_default_local_stdio_options
0x1400041d1  xor     eax, eax
0x1400041d3  add     rsp, 28h
0x1400041d7  retn

// ===== ?pre_cpp_initialization@@YAXXZ @ 0x1400041d8 =====

0x1400041d8  sub     rsp, 28h
0x1400041dc  call    __scrt_set_unhandled_exception_filter
0x1400041e1  call    UserMathErrorFunction
0x1400041e6  mov     ecx, eax; NewMode
0x1400041e8  add     rsp, 28h
0x1400041ec  jmp     _set_new_mode

// ===== ?__scrt_common_main_seh@@YAHXZ @ 0x1400041f4 =====

0x1400041f4  mov     [rsp+arg_0], rbx
0x1400041f9  push    rdi
0x1400041fa  sub     rsp, 30h
0x1400041fe  mov     ecx, 1
0x140004203  call    __scrt_initialize_crt
0x140004208  test    al, al
0x14000420a  jz      loc_140004340
0x140004210  xor     dil, dil
0x140004213  mov     [rsp+38h+var_18], dil
0x140004218  call    __scrt_acquire_startup_lock
0x14000421d  mov     bl, al
0x14000421f  mov     ecx, cs:dword_140021320
0x140004225  cmp     ecx, 1
0x140004228  jz      loc_14000434B
0x14000422e  test    ecx, ecx
0x140004230  jnz     short loc_14000427C
0x140004232  mov     cs:dword_140021320, 1
0x14000423c  lea     rdx, qword_140014558; Last
0x140004243  lea     rcx, qword_140014528; First
0x14000424a  call    _initterm_e
0x14000424f  test    eax, eax
0x140004251  jz      short loc_14000425D
0x140004253  mov     eax, 0FFh
0x140004258  jmp     loc_140004335
0x14000425d  lea     rdx, Last; Last
0x140004264  lea     rcx, First; First
0x14000426b  call    _initterm
0x140004270  mov     cs:dword_140021320, 2
0x14000427a  jmp     short loc_140004284
0x14000427c  mov     dil, 1
0x14000427f  mov     [rsp+38h+var_18], dil
0x140004284  mov     cl, bl
0x140004286  call    __scrt_release_startup_lock
0x14000428b  call    sub_140004778
0x140004290  mov     rbx, rax
0x140004293  cmp     qword ptr [rax], 0
0x140004297  jz      short loc_1400042B7
0x140004299  mov     rcx, rax
0x14000429c  call    __scrt_is_nonwritable_in_current_image
0x1400042a1  test    al, al
0x1400042a3  jz      short loc_1400042B7
0x1400042a5  xor     r8d, r8d
0x1400042a8  lea     edx, [r8+2]
0x1400042ac  xor     ecx, ecx
0x1400042ae  mov     rax, [rbx]
0x1400042b1  call    cs:__guard_dispatch_icall_fptr
0x1400042b7  call    sub_140004780
0x1400042bc  mov     rbx, rax
0x1400042bf  cmp     qword ptr [rax], 0
0x1400042c3  jz      short loc_1400042D9
0x1400042c5  mov     rcx, rax
0x1400042c8  call    __scrt_is_nonwritable_in_current_image
0x1400042cd  test    al, al
0x1400042cf  jz      short loc_1400042D9
0x1400042d1  mov     rcx, [rbx]; Callback
0x1400042d4  call    _register_thread_local_exe_atexit_callback
0x1400042d9  call    __scrt_get_show_window_mode
0x1400042de  movzx   ebx, ax
0x1400042e1  call    _get_wide_winmain_command_line
0x1400042e6  mov     r8, rax; lpCmdLine
0x1400042e9  mov     r9d, ebx; nShowCmd
0x1400042ec  xor     edx, edx; hPrevInstance
0x1400042ee  lea     rcx, cs:140000000h; hInstance
0x1400042f5  call    WinMain
0x1400042fa  mov     ebx, eax
0x1400042fc  call    __scrt_is_managed_app
0x140004301  test    al, al
0x140004303  jz      short loc_140004355
0x140004305  test    dil, dil
0x140004308  jnz     short loc_14000430F
0x14000430a  call    _cexit
0x14000430f  xor     edx, edx
0x140004311  mov     cl, 1
0x140004313  call    __scrt_uninitialize_crt
0x140004318  mov     eax, ebx
0x14000431a  jmp     short loc_140004335
0x14000431c  mov     ebx, eax
0x14000431e  call    __scrt_is_managed_app
0x140004323  test    al, al
0x140004325  jz      short loc_14000435D
0x140004327  cmp     [rsp+38h+var_18], 0
0x14000432c  jnz     short loc_140004333
0x14000432e  call    _c_exit
0x140004333  mov     eax, ebx
0x140004335  mov     rbx, [rsp+38h+arg_0]
0x14000433a  add     rsp, 30h
0x14000433e  pop     rdi
0x14000433f  retn
0x140004340  mov     ecx, 7
0x140004345  call    __scrt_fastfail
0x14000434a  nop
0x14000434b  mov     ecx, 7
0x140004350  call    __scrt_fastfail
0x140004355  mov     ecx, ebx; Code
0x140004357  call    exit
0x14000435d  mov     ecx, ebx; Code
0x14000435f  call    _exit
0x140013930  push    rbp
0x140013932  sub     rsp, 20h
0x140013936  mov     rbp, rdx
0x140013939  mov     rax, [rcx]
0x14001393c  mov     rdx, rcx; ExceptionPtr
0x14001393f  mov     ecx, [rax]; ExceptionNum
0x140013941  call    _seh_filter_exe
0x140013946  nop
0x140013947  add     rsp, 20h
0x14001394b  pop     rbp
0x14001394c  retn

// ===== start @ 0x140004368 =====

0x140004368  sub     rsp, 28h
0x14000436c  call    __security_init_cookie
0x140004371  add     rsp, 28h
0x140004375  jmp     ?__scrt_common_main_seh@@YAHXZ

// ===== j_j__free_base @ 0x14000437c =====

0x14000437c  jmp     j__free_base

// ===== ??2@YAPEAX_K@Z @ 0x140004384 =====

0x140004384  push    rbx
0x140004386  sub     rsp, 20h
0x14000438a  mov     rbx, rcx
0x14000438d  jmp     short loc_14000439E
0x14000438f  mov     rcx, rbx; Size
0x140004392  call    _callnewh
0x140004397  test    eax, eax
0x140004399  jz      short loc_1400043AE
0x14000439b  mov     rcx, rbx; Size
0x14000439e  call    j__malloc_base
0x1400043a3  test    rax, rax
0x1400043a6  jz      short loc_14000438F
0x1400043a8  add     rsp, 20h
0x1400043ac  pop     rbx
0x1400043ad  retn
0x1400043ae  cmp     rbx, 0FFFFFFFFFFFFFFFFh
0x1400043b2  jz      short loc_1400043BA
0x1400043b4  call    sub_140004B84
0x1400043ba  call    sub_140004BA4

// ===== __scrt_acquire_startup_lock @ 0x1400043c0 =====

0x1400043c0  sub     rsp, 28h
0x1400043c4  call    __scrt_is_ucrt_dll_in_use
0x1400043c9  test    eax, eax
0x1400043cb  jz      short loc_1400043EE
0x1400043cd  mov     rax, gs:30h
0x1400043d6  mov     rcx, [rax+8]
0x1400043da  jmp     short loc_1400043E1
0x1400043dc  cmp     rcx, rax
0x1400043df  jz      short loc_1400043F5
0x1400043e1  xor     eax, eax
0x1400043e3  lock cmpxchg cs:qword_140021328, rcx
0x1400043ec  jnz     short loc_1400043DC
0x1400043ee  xor     al, al
0x1400043f0  add     rsp, 28h
0x1400043f4  retn
0x1400043f5  mov     al, 1
0x1400043f7  jmp     short loc_1400043F0

// ===== __scrt_initialize_crt @ 0x1400043fc =====

0x1400043fc  push    rbx
0x1400043fe  sub     rsp, 20h
0x140004402  movzx   eax, cs:byte_140021330
0x140004409  test    ecx, ecx
0x14000440b  mov     ebx, 1
0x140004410  cmovz   eax, ebx
0x140004413  mov     cs:byte_140021330, al
0x140004419  call    __isa_available_init
0x14000441e  call    __vcrt_initialize
0x140004423  test    al, al
0x140004425  jnz     short loc_14000442B
0x140004427  xor     al, al
0x140004429  jmp     short loc_14000443F
0x14000442b  call    __acrt_initialize
0x140004430  test    al, al
0x140004432  jnz     short loc_14000443D
0x140004434  xor     ecx, ecx; Terminating
0x140004436  call    __vcrt_uninitialize
0x14000443b  jmp     short loc_140004427
0x14000443d  mov     al, bl
0x14000443f  add     rsp, 20h
0x140004443  pop     rbx
0x140004444  retn

// ===== __scrt_initialize_onexit_tables @ 0x140004448 =====

0x140004448  push    rbx
0x14000444a  sub     rsp, 40h
0x14000444e  cmp     cs:byte_140021331, 0
0x140004455  mov     ebx, ecx
0x140004457  jnz     loc_14000450D
0x14000445d  cmp     ecx, 1
0x140004460  ja      loc_140004515
0x140004466  call    __scrt_is_ucrt_dll_in_use
0x14000446b  test    eax, eax
0x14000446d  jz      short loc_140004497
0x14000446f  test    ebx, ebx
0x140004471  jnz     short loc_140004497
0x140004473  lea     rcx, stru_140021338; Table
0x14000447a  call    _initialize_onexit_table
0x14000447f  test    eax, eax
0x140004481  jnz     short loc_140004493
0x140004483  lea     rcx, stru_140021350; Table
0x14000448a  call    _initialize_onexit_table
0x14000448f  test    eax, eax
0x140004491  jz      short loc_140004506
0x140004493  xor     al, al
0x140004495  jmp     short loc_14000450F
0x140004497  mov     rdx, cs:__security_cookie
0x14000449e  mov     ecx, 40h ; '@'
0x1400044a3  mov     eax, edx
0x1400044a5  and     eax, 3Fh
0x1400044a8  sub     ecx, eax
0x1400044aa  or      rax, 0FFFFFFFFFFFFFFFFh
0x1400044ae  ror     rax, cl
0x1400044b1  xor     rax, rdx
0x1400044b4  mov     qword ptr [rsp+48h+var_28], rax
0x1400044b9  mov     qword ptr [rsp+48h+var_28+8], rax
0x1400044be  movups  xmm0, [rsp+48h+var_28]
0x1400044c3  mov     [rsp+48h+var_18], rax
0x1400044c8  movsd   xmm1, [rsp+48h+var_18]
0x1400044ce  movups  xmmword ptr cs:stru_140021338._first, xmm0
0x1400044d5  mov     qword ptr [rsp+48h+var_28], rax
0x1400044da  mov     qword ptr [rsp+48h+var_28+8], rax
0x1400044df  movups  xmm0, [rsp+48h+var_28]
0x1400044e4  mov     [rsp+48h+var_18], rax
0x1400044e9  movsd   cs:stru_140021338._end, xmm1
0x1400044f1  movsd   xmm1, [rsp+48h+var_18]
0x1400044f7  movups  xmmword ptr cs:stru_140021350._first, xmm0
0x1400044fe  movsd   cs:stru_140021350._end, xmm1
0x140004506  mov     cs:byte_140021331, 1
0x14000450d  mov     al, 1
0x14000450f  add     rsp, 40h
0x140004513  pop     rbx
0x140004514  retn
0x140004515  mov     ecx, 5
0x14000451a  call    __scrt_fastfail
0x14000451f  int     3; Trap to Debugger

// ===== __scrt_is_nonwritable_in_current_image @ 0x140004520 =====

0x140004520  sub     rsp, 18h
0x140004524  mov     r8, rcx
0x140004527  mov     eax, 5A4Dh
0x14000452c  cmp     cs:140000000h, ax
0x140004533  jnz     short loc_1400045AE
0x140004535  movsxd  rax, dword ptr cs:14000003Ch
0x14000453c  lea     rdx, cs:140000000h
0x140004543  lea     rcx, [rax+rdx]
0x140004547  cmp     dword ptr [rcx], 4550h
0x14000454d  jnz     short loc_1400045AE
0x14000454f  mov     eax, 20Bh
0x140004554  cmp     [rcx+18h], ax
0x140004558  jnz     short loc_1400045AE
0x14000455a  sub     r8, rdx
0x14000455d  movzx   eax, word ptr [rcx+14h]
0x140004561  lea     rdx, [rcx+18h]
0x140004565  add     rdx, rax
0x140004568  movzx   eax, word ptr [rcx+6]
0x14000456c  lea     rcx, [rax+rax*4]
0x140004570  lea     r9, [rdx+rcx*8]
0x140004574  mov     [rsp+18h+var_18], rdx
0x140004578  cmp     rdx, r9
0x14000457b  jz      short loc_140004595
0x14000457d  mov     ecx, [rdx+0Ch]
0x140004580  cmp     r8, rcx
0x140004583  jb      short loc_14000458F
0x140004585  mov     eax, [rdx+8]
0x140004588  add     eax, ecx
0x14000458a  cmp     r8, rax
0x14000458d  jb      short loc_140004597
0x14000458f  add     rdx, 28h ; '('
0x140004593  jmp     short loc_140004574
0x140004595  xor     edx, edx
0x140004597  test    rdx, rdx
0x14000459a  jnz     short loc_1400045A0
0x14000459c  xor     al, al
0x14000459e  jmp     short loc_1400045B4
0x1400045a0  cmp     dword ptr [rdx+24h], 0
0x1400045a4  jge     short loc_1400045AA
0x1400045a6  xor     al, al
0x1400045a8  jmp     short loc_1400045B4
0x1400045aa  mov     al, 1
0x1400045ac  jmp     short loc_1400045B4
0x1400045ae  xor     al, al
0x1400045b0  jmp     short loc_1400045B4
0x1400045b2  xor     al, al
0x1400045b4  add     rsp, 18h
0x1400045b8  retn
0x14001394e  push    rbp
0x140013950  mov     rbp, rdx
0x140013953  mov     rax, [rcx]
0x140013956  xor     ecx, ecx
0x140013958  cmp     dword ptr [rax], 0C0000005h
0x14001395e  setz    cl
0x140013961  mov     eax, ecx
0x140013963  pop     rbp
0x140013964  retn

// ===== __scrt_release_startup_lock @ 0x1400045bc =====

0x1400045bc  push    rbx
0x1400045be  sub     rsp, 20h
0x1400045c2  mov     bl, cl
0x1400045c4  call    __scrt_is_ucrt_dll_in_use
0x1400045c9  xor     edx, edx
0x1400045cb  test    eax, eax
0x1400045cd  jz      short loc_1400045DA
0x1400045cf  test    bl, bl
0x1400045d1  jnz     short loc_1400045DA
0x1400045d3  xchg    rdx, cs:qword_140021328
0x1400045da  add     rsp, 20h
0x1400045de  pop     rbx
0x1400045df  retn

// ===== __scrt_uninitialize_crt @ 0x1400045e0 =====

0x1400045e0  push    rbx
0x1400045e2  sub     rsp, 20h
0x1400045e6  cmp     cs:byte_140021330, 0
0x1400045ed  mov     bl, cl
0x1400045ef  jz      short loc_1400045F5
0x1400045f1  test    dl, dl
0x1400045f3  jnz     short loc_140004603
0x1400045f5  mov     cl, bl; Terminating
0x1400045f7  call    __acrt_uninitialize
0x1400045fc  mov     cl, bl; Terminating
0x1400045fe  call    __vcrt_uninitialize
0x140004603  mov     al, 1
0x140004605  add     rsp, 20h
0x140004609  pop     rbx
0x14000460a  retn

// ===== _onexit @ 0x14000460c =====

0x14000460c  push    rbx
0x14000460e  sub     rsp, 20h
0x140004612  mov     rdx, cs:__security_cookie
0x140004619  mov     rbx, rcx
0x14000461c  mov     ecx, edx
0x14000461e  xor     rdx, cs:stru_140021338._first
0x140004625  and     ecx, 3Fh
0x140004628  ror     rdx, cl
0x14000462b  cmp     rdx, 0FFFFFFFFFFFFFFFFh
0x14000462f  jnz     short loc_14000463B
0x140004631  mov     rcx, rbx; Function
0x140004634  call    sub_140009688
0x140004639  jmp     short loc_14000464A
0x14000463b  mov     rdx, rbx; Function
0x14000463e  lea     rcx, stru_140021338; Table
0x140004645  call    _register_onexit_function
0x14000464a  xor     ecx, ecx
0x14000464c  test    eax, eax
0x14000464e  cmovz   rcx, rbx
0x140004652  mov     rax, rcx
0x140004655  add     rsp, 20h
0x140004659  pop     rbx
0x14000465a  retn

// ===== atexit @ 0x14000465c =====

0x14000465c  sub     rsp, 28h
0x140004660  call    _onexit
0x140004665  neg     rax
0x140004668  sbb     eax, eax
0x14000466a  neg     eax
0x14000466c  dec     eax
0x14000466e  add     rsp, 28h
0x140004672  retn

// ===== __security_init_cookie @ 0x140004674 =====

0x140004674  mov     [rsp-8+arg_18], rbx
0x140004679  push    rbp
0x14000467a  mov     rbp, rsp
0x14000467d  sub     rsp, 20h
0x140004681  mov     rax, cs:__security_cookie
0x140004688  mov     rbx, 2B992DDFA232h
0x140004692  cmp     rax, rbx
0x140004695  jnz     short loc_14000470B
0x140004697  and     qword ptr [rbp+SystemTimeAsFileTime.dwLowDateTime], 0
0x14000469c  lea     rcx, [rbp+SystemTimeAsFileTime]; lpSystemTimeAsFileTime
0x1400046a0  call    cs:GetSystemTimeAsFileTime; KERNEL32
0x1400046a6  mov     rax, qword ptr [rbp+SystemTimeAsFileTime.dwLowDateTime]
0x1400046aa  mov     [rbp+arg_0], rax
0x1400046ae  call    cs:GetCurrentThreadId; KERNEL32
0x1400046b4  mov     eax, eax
0x1400046b6  xor     [rbp+arg_0], rax
0x1400046ba  call    cs:GetCurrentProcessId; KERNEL32
0x1400046c0  mov     eax, eax
0x1400046c2  lea     rcx, [rbp+PerformanceCount]; lpPerformanceCount
0x1400046c6  xor     [rbp+arg_0], rax
0x1400046ca  call    cs:QueryPerformanceCounter; KERNEL32
0x1400046d0  mov     eax, dword ptr [rbp+PerformanceCount]
0x1400046d3  lea     rcx, [rbp+arg_0]
0x1400046d7  shl     rax, 20h
0x1400046db  xor     rax, qword ptr [rbp+PerformanceCount]
0x1400046df  xor     rax, [rbp+arg_0]
0x1400046e3  xor     rax, rcx
0x1400046e6  mov     rcx, 0FFFFFFFFFFFFh
0x1400046f0  and     rax, rcx
0x1400046f3  mov     rcx, 2B992DDFA233h
0x1400046fd  cmp     rax, rbx
0x140004700  cmovz   rax, rcx
0x140004704  mov     cs:__security_cookie, rax
0x14000470b  mov     rbx, [rsp+20h+arg_18]
0x140004710  not     rax
0x140004713  mov     cs:qword_140020000, rax
0x14000471a  add     rsp, 20h
0x14000471e  pop     rbp
0x14000471f  retn

// ===== UserMathErrorFunction @ 0x140004720 =====

0x140004720  xor     eax, eax
0x140004722  retn

// ===== ?raw_length@charNode@@UEBAHXZ @ 0x140004724 =====

0x140004724  mov     eax, 1
0x140004729  retn

// ===== _get_startup_file_mode @ 0x14000472c =====

0x14000472c  mov     eax, 4000h
0x140004731  retn

// ===== sub_140004734 @ 0x140004734 =====

0x140004734  lea     rcx, stru_140021370
0x14000473b  jmp     cs:InitializeSListHead; KERNEL32

// ===== sub_140004744 @ 0x140004744 =====

0x140004744  mov     al, 1
0x140004746  retn

// ===== sub_140004748 @ 0x140004748 =====

0x140004748  lea     rax, unk_140021380
0x14000474f  retn

// ===== __scrt_initialize_default_local_stdio_options @ 0x140004750 =====

0x140004750  sub     rsp, 28h
0x140004754  call    sub_1400012C0
0x140004759  or      qword ptr [rax], 4
0x14000475d  call    sub_140004748
0x140004762  or      qword ptr [rax], 2
0x140004766  add     rsp, 28h
0x14000476a  retn

// ===== __scrt_is_user_matherr_present @ 0x14000476c =====

0x14000476c  xor     eax, eax
0x14000476e  cmp     cs:dword_140020014, eax
0x140004774  setz    al
0x140004777  retn

// ===== sub_140004778 @ 0x140004778 =====

0x140004778  lea     rax, unk_140022050
0x14000477f  retn

// ===== sub_140004780 @ 0x140004780 =====

0x140004780  lea     rax, unk_140022048
0x140004787  retn

// ===== sub_140004788 @ 0x140004788 =====

0x140004788  and     cs:dword_140021388, 0
0x14000478f  retn

// ===== __scrt_fastfail @ 0x140004790 =====

0x140004790  mov     [rsp-8+arg_0], rbx
0x140004795  push    rbp
0x140004796  lea     rbp, [rsp-4C0h]
0x14000479e  sub     rsp, 5C0h
0x1400047a5  mov     ebx, ecx
0x1400047a7  mov     ecx, 17h; ProcessorFeature
0x1400047ac  call    IsProcessorFeaturePresent
0x1400047b1  test    eax, eax
0x1400047b3  jz      short loc_1400047B9
0x1400047b5  mov     ecx, ebx
0x1400047b7  int     29h; Win8: RtlFailFast(ecx)
0x1400047b9  mov     ecx, 3
0x1400047be  call    sub_140004788
0x1400047c3  xor     edx, edx
0x1400047c5  lea     rcx, [rbp+4C0h+ContextRecord]
0x1400047c9  mov     r8d, 4D0h
0x1400047cf  call    sub_140005B30
0x1400047d4  lea     rcx, [rbp+4C0h+ContextRecord]; ContextRecord
0x1400047d8  call    cs:RtlCaptureContext; KERNEL32
0x1400047de  mov     rbx, [rbp+4C0h+ContextRecord.Rip]
0x1400047e5  lea     rdx, [rbp+4C0h+ImageBase]; ImageBase
0x1400047ec  mov     rcx, rbx; ControlPc
0x1400047ef  xor     r8d, r8d; HistoryTable
0x1400047f2  call    cs:RtlLookupFunctionEntry; KERNEL32
0x1400047f8  test    rax, rax
0x1400047fb  jz      short loc_140004839
0x1400047fd  and     [rsp+5C0h+var_588], 0
0x140004803  lea     rcx, [rbp+4C0h+arg_10]
0x14000480a  mov     rdx, [rbp+4C0h+ImageBase]; ImageBase
0x140004811  mov     r9, rax; FunctionEntry
0x140004814  mov     [rsp+5C0h+EstablisherFrame], rcx; EstablisherFrame
0x140004819  mov     r8, rbx; ControlPc
0x14000481c  lea     rcx, [rbp+4C0h+arg_18]
0x140004823  mov     [rsp+5C0h+HandlerData], rcx; HandlerData
0x140004828  lea     rcx, [rbp+4C0h+ContextRecord]
0x14000482c  mov     [rsp+5C0h+var_5A0], rcx; ContextRecord
0x140004831  xor     ecx, ecx; HandlerType
0x140004833  call    cs:RtlVirtualUnwind; KERNEL32
0x140004839  mov     rax, [rbp+4C8h]
0x140004840  lea     rcx, [rsp+5C0h+var_570]
0x140004845  mov     [rbp+4C0h+ContextRecord.Rip], rax
0x14000484c  xor     edx, edx
0x14000484e  lea     rax, [rbp+4C8h]
0x140004855  mov     r8d, 98h
0x14000485b  add     rax, 8
0x14000485f  mov     [rbp+4C0h+ContextRecord.Rsp], rax
0x140004866  call    sub_140005B30
0x14000486b  mov     rax, [rbp+4C8h]
0x140004872  mov     [rsp+5C0h+var_560], rax
0x140004877  mov     [rsp+5C0h+var_570], 40000015h
0x14000487f  mov     [rsp+5C0h+var_56C], 1
0x140004887  call    cs:IsDebuggerPresent; KERNEL32
0x14000488d  cmp     eax, 1
0x140004890  lea     rax, [rsp+5C0h+var_570]
0x140004895  mov     [rsp+5C0h+ExceptionInfo.ExceptionRecord], rax
0x14000489a  lea     rax, [rbp+4C0h+ContextRecord]
0x14000489e  setz    bl
0x1400048a1  mov     [rsp+5C0h+ExceptionInfo.ContextRecord], rax
0x1400048a6  xor     ecx, ecx; lpTopLevelExceptionFilter
0x1400048a8  call    cs:SetUnhandledExceptionFilter; KERNEL32
0x1400048ae  lea     rcx, [rsp+5C0h+ExceptionInfo]; ExceptionInfo
0x1400048b3  call    cs:UnhandledExceptionFilter; KERNEL32
0x1400048b9  test    eax, eax
0x1400048bb  jnz     short loc_1400048C9
0x1400048bd  test    bl, bl
0x1400048bf  jnz     short loc_1400048C9
0x1400048c1  lea     ecx, [rax+3]
0x1400048c4  call    sub_140004788
0x1400048c9  mov     rbx, [rsp+5C0h+arg_0]
0x1400048d1  add     rsp, 5C0h
0x1400048d8  pop     rbp
0x1400048d9  retn

// ===== __scrt_get_show_window_mode @ 0x1400048dc =====

0x1400048dc  sub     rsp, 98h
0x1400048e3  xor     edx, edx
0x1400048e5  lea     rcx, [rsp+98h+StartupInfo]
0x1400048ea  lea     r8d, [rdx+68h]
0x1400048ee  call    sub_140005B30
0x1400048f3  lea     rcx, [rsp+98h+StartupInfo]; lpStartupInfo
0x1400048f8  call    cs:GetStartupInfoW; KERNEL32
0x1400048fe  test    byte ptr [rsp+98h+StartupInfo.dwFlags], 1
0x140004903  mov     eax, 0Ah
0x140004908  cmovnz  ax, [rsp+98h+StartupInfo.wShowWindow]
0x14000490e  add     rsp, 98h
0x140004915  retn

// ===== j_UserMathErrorFunction @ 0x140004918 =====

0x140004918  jmp     UserMathErrorFunction

// ===== __scrt_is_managed_app @ 0x140004920 =====

0x140004920  sub     rsp, 28h
0x140004924  xor     ecx, ecx; lpModuleName
0x140004926  call    cs:GetModuleHandleW; KERNEL32
0x14000492c  test    rax, rax
0x14000492f  jz      short loc_14000496B
0x140004931  mov     ecx, 5A4Dh
0x140004936  cmp     [rax], cx
0x140004939  jnz     short loc_14000496B
0x14000493b  movsxd  rcx, dword ptr [rax+3Ch]
0x14000493f  add     rcx, rax
0x140004942  cmp     dword ptr [rcx], 4550h
0x140004948  jnz     short loc_14000496B
0x14000494a  mov     eax, 20Bh
0x14000494f  cmp     [rcx+18h], ax
0x140004953  jnz     short loc_14000496B
0x140004955  cmp     dword ptr [rcx+84h], 0Eh
0x14000495c  jbe     short loc_14000496B
0x14000495e  cmp     dword ptr [rcx+0F8h], 0
0x140004965  jz      short loc_14000496B
0x140004967  mov     al, 1
0x140004969  jmp     short loc_14000496D
0x14000496b  xor     al, al
0x14000496d  add     rsp, 28h
0x140004971  retn

// ===== __scrt_set_unhandled_exception_filter @ 0x140004974 =====

0x140004974  lea     rcx, __scrt_unhandled_exception_filter
0x14000497b  jmp     cs:SetUnhandledExceptionFilter; KERNEL32

// ===== __scrt_unhandled_exception_filter @ 0x140004984 =====

0x140004984  sub     rsp, 28h
0x140004988  mov     rax, [rcx]
0x14000498b  cmp     dword ptr [rax], 0E06D7363h
0x140004991  jnz     short loc_1400049AF
0x140004993  cmp     dword ptr [rax+18h], 4
0x140004997  jnz     short loc_1400049AF
0x140004999  mov     ecx, [rax+20h]
0x14000499c  lea     eax, [rcx-19930520h]
0x1400049a2  cmp     eax, 2
0x1400049a5  jbe     short loc_1400049B6
0x1400049a7  cmp     ecx, 1994000h
0x1400049ad  jz      short loc_1400049B6
0x1400049af  xor     eax, eax
0x1400049b1  add     rsp, 28h
0x1400049b5  retn
0x1400049b6  call    terminate

// ===== sub_1400049BC @ 0x1400049bc =====

0x1400049bc  mov     [rsp+arg_0], rbx
0x1400049c1  push    rdi
0x1400049c2  sub     rsp, 20h
0x1400049c6  lea     rbx, qword_14001D098
0x1400049cd  lea     rdi, qword_14001D098
0x1400049d4  jmp     short loc_1400049E8
0x1400049d6  mov     rax, [rbx]
0x1400049d9  test    rax, rax
0x1400049dc  jz      short loc_1400049E4
0x1400049de  call    cs:__guard_dispatch_icall_fptr
0x1400049e4  add     rbx, 8
0x1400049e8  cmp     rbx, rdi
0x1400049eb  jb      short loc_1400049D6
0x1400049ed  mov     rbx, [rsp+28h+arg_0]
0x1400049f2  add     rsp, 20h
0x1400049f6  pop     rdi
0x1400049f7  retn

// ===== sub_1400049F8 @ 0x1400049f8 =====

0x1400049f8  mov     [rsp+arg_0], rbx
0x1400049fd  push    rdi
0x1400049fe  sub     rsp, 20h
0x140004a02  lea     rbx, qword_14001D0A8
0x140004a09  lea     rdi, qword_14001D0A8
0x140004a10  jmp     short loc_140004A24
0x140004a12  mov     rax, [rbx]
0x140004a15  test    rax, rax
0x140004a18  jz      short loc_140004A20
0x140004a1a  call    cs:__guard_dispatch_icall_fptr
0x140004a20  add     rbx, 8
0x140004a24  cmp     rbx, rdi
0x140004a27  jb      short loc_140004A12
0x140004a29  mov     rbx, [rsp+28h+arg_0]
0x140004a2e  add     rsp, 20h
0x140004a32  pop     rdi
0x140004a33  retn

// ===== sub_140004A34 @ 0x140004a34 =====

0x140004a34  push    rbx
0x140004a36  sub     rsp, 20h
0x140004a3a  mov     rbx, rcx
0x140004a3d  mov     rax, rdx
0x140004a40  lea     rcx, ??_7exception@std@@6B@; const std::exception::`vftable'
0x140004a47  mov     [rbx], rcx
0x140004a4a  lea     rdx, [rbx+8]
0x140004a4e  xor     ecx, ecx
0x140004a50  mov     [rdx], rcx
0x140004a53  mov     [rdx+8], rcx
0x140004a57  lea     rcx, [rax+8]
0x140004a5b  call    __std_exception_copy
0x140004a60  lea     rax, ??_7bad_alloc@std@@6B@; const std::bad_alloc::`vftable'
0x140004a67  mov     [rbx], rax
0x140004a6a  mov     rax, rbx
0x140004a6d  add     rsp, 20h
0x140004a71  pop     rbx
0x140004a72  retn

// ===== sub_140004A74 @ 0x140004a74 =====

0x140004a74  and     qword ptr [rcx+10h], 0
0x140004a79  lea     rax, aBadAllocation; "bad allocation"
0x140004a80  mov     [rcx+8], rax
0x140004a84  lea     rax, ??_7bad_alloc@std@@6B@; const std::bad_alloc::`vftable'
0x140004a8b  mov     [rcx], rax
0x140004a8e  mov     rax, rcx
0x140004a91  retn

// ===== sub_140004A94 @ 0x140004a94 =====

0x140004a94  push    rbx
0x140004a96  sub     rsp, 20h
0x140004a9a  mov     rbx, rcx
0x140004a9d  mov     rax, rdx
0x140004aa0  lea     rcx, ??_7exception@std@@6B@; const std::exception::`vftable'
0x140004aa7  mov     [rbx], rcx
0x140004aaa  lea     rdx, [rbx+8]
0x140004aae  xor     ecx, ecx
0x140004ab0  mov     [rdx], rcx
0x140004ab3  mov     [rdx+8], rcx
0x140004ab7  lea     rcx, [rax+8]
0x140004abb  call    __std_exception_copy
0x140004ac0  lea     rax, ??_7bad_array_new_length@std@@6B@; const std::bad_array_new_length::`vftable'
0x140004ac7  mov     [rbx], rax
0x140004aca  mov     rax, rbx
0x140004acd  add     rsp, 20h
0x140004ad1  pop     rbx
0x140004ad2  retn

// ===== sub_140004AD4 @ 0x140004ad4 =====

0x140004ad4  and     qword ptr [rcx+10h], 0
0x140004ad9  lea     rax, aBadArrayNewLen; "bad array new length"
0x140004ae0  mov     [rcx+8], rax
0x140004ae4  lea     rax, ??_7bad_array_new_length@std@@6B@; const std::bad_array_new_length::`vftable'
0x140004aeb  mov     [rcx], rax
0x140004aee  mov     rax, rcx
0x140004af1  retn

// ===== ??0exception@std@@QEAA@AEBV01@@Z @ 0x140004af4 =====

0x140004af4  push    rbx
0x140004af6  sub     rsp, 20h
0x140004afa  mov     rbx, rcx
0x140004afd  mov     rax, rdx
0x140004b00  lea     rcx, ??_7exception@std@@6B@
0x140004b07  mov     [rbx], rcx
0x140004b0a  lea     rdx, [rbx+8]
0x140004b0e  xor     ecx, ecx
0x140004b10  mov     [rdx], rcx
0x140004b13  mov     [rdx+8], rcx
0x140004b17  lea     rcx, [rax+8]
0x140004b1b  call    __std_exception_copy
0x140004b20  mov     rax, rbx
0x140004b23  add     rsp, 20h
0x140004b27  pop     rbx
0x140004b28  retn

// ===== unknown_libname_1 @ 0x140004b2c =====

0x140004b2c  lea     rax, ??_7exception@std@@6B@
0x140004b33  mov     [rcx], rax
0x140004b36  add     rcx, 8
0x140004b3a  jmp     __std_exception_destroy

// ===== unknown_libname_2 @ 0x140004b40 =====

0x140004b40  mov     [rsp+arg_0], rbx
0x140004b45  push    rdi
0x140004b46  sub     rsp, 20h
0x140004b4a  lea     rax, ??_7exception@std@@6B@
0x140004b51  mov     rdi, rcx
0x140004b54  mov     [rcx], rax
0x140004b57  mov     ebx, edx
0x140004b59  add     rcx, 8
0x140004b5d  call    __std_exception_destroy
0x140004b62  test    bl, 1
0x140004b65  jz      short loc_140004B74
0x140004b67  mov     edx, 18h
0x140004b6c  mov     rcx, rdi; Block
0x140004b6f  call    j_j_j__free_base
0x140004b74  mov     rbx, [rsp+28h+arg_0]
0x140004b79  mov     rax, rdi
0x140004b7c  add     rsp, 20h
0x140004b80  pop     rdi
0x140004b81  retn

// ===== sub_140004B84 @ 0x140004b84 =====

0x140004b84  sub     rsp, 48h
0x140004b88  lea     rcx, [rsp+48h+pExceptionObject]
0x140004b8d  call    sub_140004A74
0x140004b92  lea     rdx, __TI2?AVbad_alloc@std@@; pThrowInfo
0x140004b99  lea     rcx, [rsp+48h+pExceptionObject]; pExceptionObject
0x140004b9e  call    _CxxThrowException

// ===== sub_140004BA4 @ 0x140004ba4 =====

0x140004ba4  sub     rsp, 48h
0x140004ba8  lea     rcx, [rsp+48h+pExceptionObject]
0x140004bad  call    sub_140004AD4
0x140004bb2  lea     rdx, __TI3?AVbad_array_new_length@std@@; pThrowInfo
0x140004bb9  lea     rcx, [rsp+48h+pExceptionObject]; pExceptionObject
0x140004bbe  call    _CxxThrowException

// ===== ?get_unexpected_or_default@@YAP6AXXZQEBU__vcrt_ptd@@@Z @ 0x140004bc4 =====

0x140004bc4  cmp     qword ptr [rcx+8], 0
0x140004bc9  lea     rax, aUnknownExcepti
0x140004bd0  cmovnz  rax, [rcx+8]
0x140004bd5  retn

// ===== __isa_available_init @ 0x140004bd8 =====

0x140004bd8  mov     [rsp+arg_8], rbx
0x140004bdd  mov     [rsp+arg_10], rsi
0x140004be2  push    rdi
0x140004be3  sub     rsp, 10h
0x140004be7  xor     eax, eax
0x140004be9  mov     cs:dword_14002001C, 2
0x140004bf3  xor     ecx, ecx
0x140004bf5  mov     cs:dword_140020018, 1
0x140004bff  cpuid
0x140004c01  mov     r8d, ecx
0x140004c04  xor     edi, edi
0x140004c06  mov     r9d, ebx
0x140004c09  xor     r8d, 6C65746Eh
0x140004c10  xor     r9d, 756E6547h
0x140004c17  mov     r10d, edx
0x140004c1a  mov     esi, eax
0x140004c1c  xor     ecx, ecx
0x140004c1e  lea     eax, [rdi+1]
0x140004c21  or      r9d, r8d
0x140004c24  cpuid
0x140004c26  xor     r10d, 49656E69h
0x140004c2d  mov     [rsp+18h+var_18], eax
0x140004c30  or      r9d, r10d
0x140004c33  mov     [rsp+18h+var_14], ebx
0x140004c37  mov     r11d, ecx
0x140004c3a  mov     [rsp+18h+var_10], ecx
0x140004c3e  mov     [rsp+18h+var_C], edx
0x140004c42  jnz     short loc_140004C94
0x140004c44  or      cs:qword_140020020, 0FFFFFFFFFFFFFFFFh
0x140004c4c  and     eax, 0FFF3FF0h
0x140004c51  cmp     eax, 106C0h
0x140004c56  jz      short loc_140004C80
0x140004c58  cmp     eax, 20660h
0x140004c5d  jz      short loc_140004C80
0x140004c5f  cmp     eax, 20670h
0x140004c64  jz      short loc_140004C80
0x140004c66  add     eax, 0FFFCF9B0h
0x140004c6b  cmp     eax, 20h ; ' '
0x140004c6e  ja      short loc_140004C94
0x140004c70  mov     rcx, 100010001h
0x140004c7a  bt      rcx, rax
0x140004c7e  jnb     short loc_140004C94
0x140004c80  mov     r8d, cs:dword_14002138C
0x140004c87  or      r8d, 1
0x140004c8b  mov     cs:dword_14002138C, r8d
0x140004c92  jmp     short loc_140004C9B
0x140004c94  mov     r8d, cs:dword_14002138C
0x140004c9b  mov     eax, 7
0x140004ca0  cmp     esi, eax
0x140004ca2  jl      short loc_140004CCA
0x140004ca4  xor     ecx, ecx
0x140004ca6  cpuid
0x140004ca8  mov     [rsp+18h+var_18], eax
0x140004cab  mov     edi, ebx
0x140004cad  mov     [rsp+18h+var_14], ebx
0x140004cb1  mov     [rsp+18h+var_10], ecx
0x140004cb5  mov     [rsp+18h+var_C], edx
0x140004cb9  bt      ebx, 9
0x140004cbd  jnb     short loc_140004CCA
0x140004cbf  or      r8d, 2
0x140004cc3  mov     cs:dword_14002138C, r8d
0x140004cca  bt      r11d, 14h
0x140004ccf  jnb     short loc_140004D41
0x140004cd1  mov     cs:dword_140020018, 2
0x140004cdb  mov     cs:dword_14002001C, 6
0x140004ce5  bt      r11d, 1Bh
0x140004cea  jnb     short loc_140004D41
0x140004cec  bt      r11d, 1Ch
0x140004cf1  jnb     short loc_140004D41
0x140004cf3  xor     ecx, ecx
0x140004cf5  xgetbv
0x140004cf8  shl     rdx, 20h
0x140004cfc  or      rdx, rax
0x140004cff  mov     [rsp+18h+arg_0], rdx
0x140004d04  mov     rax, [rsp+18h+arg_0]
0x140004d09  and     al, 6
0x140004d0b  cmp     al, 6
0x140004d0d  jnz     short loc_140004D41
0x140004d0f  mov     eax, cs:dword_14002001C
0x140004d15  or      eax, 8
0x140004d18  mov     cs:dword_140020018, 3
0x140004d22  mov     cs:dword_14002001C, eax
0x140004d28  test    dil, 20h
0x140004d2c  jz      short loc_140004D41
0x140004d2e  or      eax, 20h
0x140004d31  mov     cs:dword_140020018, 5
0x140004d3b  mov     cs:dword_14002001C, eax
0x140004d41  mov     rbx, [rsp+18h+arg_8]
0x140004d46  xor     eax, eax
0x140004d48  mov     rsi, [rsp+18h+arg_10]
0x140004d4d  add     rsp, 10h
0x140004d51  pop     rdi
0x140004d52  retn

// ===== __scrt_is_ucrt_dll_in_use @ 0x140004d54 =====

0x140004d54  xor     eax, eax
0x140004d56  cmp     cs:dword_140022040, eax
0x140004d5c  setnz   al
0x140004d5f  retn

// ===== GetFileVersionInfoSizeW @ 0x140004d60 =====

0x140004d60  jmp     cs:__imp_GetFileVersionInfoSizeW; VERSION

// ===== GetFileVersionInfoW @ 0x140004d66 =====

0x140004d66  jmp     cs:__imp_GetFileVersionInfoW; VERSION

// ===== VerQueryValueW @ 0x140004d6c =====

0x140004d6c  jmp     cs:__imp_VerQueryValueW; VERSION

// ===== sub_140004D80 @ 0x140004d80 =====

0x140004d80  sub     rsp, 28h
0x140004d84  mov     rcx, cs:qword_140020030; hObject
0x140004d8b  call    cs:CloseHandle; KERNEL32
0x140004d91  add     rsp, 28h
0x140004d95  retn

// ===== sub_140004DA0 @ 0x140004da0 =====

0x140004da0  sub     rsp, 0F8h
0x140004da7  mov     [rsp+0F8h+hTemplateFile], 0; hTemplateFile
0x140004db0  mov     [rsp+0F8h+dwFlagsAndAttributes], 80h; dwFlagsAndAttributes
0x140004db8  mov     [rsp+0F8h+dwCreationDisposition], 3; dwCreationDisposition
0x140004dc0  xor     r9d, r9d; lpSecurityAttributes
0x140004dc3  mov     r8d, 3; dwShareMode
0x140004dc9  mov     edx, 80h; dwDesiredAccess
0x140004dce  lea     rcx, FileName; "\\\\.\\DpControl"
0x140004dd5  call    cs:CreateFileW; KERNEL32
0x140004ddb  mov     [rsp+0F8h+var_B8], rax
0x140004de0  cmp     [rsp+0F8h+var_B8], 0FFFFFFFFFFFFFFFFh
0x140004de6  jnz     short loc_140004DEF
0x140004de8  xor     eax, eax
0x140004dea  jmp     loc_140004EA8
0x140004def  jmp     loc_14008E114
0x140004ea8  add     rsp, 0F8h
0x140004eaf  retn
0x14008e114  push    8DF3Bh
0x14008e119  push    46h ; 'F'
0x14008e11e  jmp     sub_14008DE87

// ===== sub_140004EB0 @ 0x140004eb0 =====

0x140004eb0  sub     rsp, 0F8h
0x140004eb7  mov     [rsp+0F8h+hTemplateFile], 0; hTemplateFile
0x140004ec0  mov     dword ptr [rsp+0F8h+dwFlagsAndAttributes], 80h; dwFlagsAndAttributes
0x140004ec8  mov     dword ptr [rsp+0F8h+dwCreationDisposition], 3; dwCreationDisposition
0x140004ed0  xor     r9d, r9d; lpSecurityAttributes
0x140004ed3  mov     r8d, 3; dwShareMode
0x140004ed9  mov     edx, 80h; dwDesiredAccess
0x140004ede  lea     rcx, FileName; "\\\\.\\DpControl"
0x140004ee5  call    cs:CreateFileW; KERNEL32
0x140004eeb  mov     [rsp+0F8h+hObject], rax
0x140004ef0  cmp     [rsp+0F8h+hObject], 0FFFFFFFFFFFFFFFFh
0x140004ef6  jnz     short loc_140004EFF
0x140004ef8  xor     eax, eax
0x140004efa  jmp     loc_140004FB8
0x140004eff  jmp     loc_14008E301
0x140004f04  scasd
0x140004f05  xor     [rbx], esi
0x140004f07  cmp     [rdi+0FD0469h], cl
0x140004f0d  clc
0x140004f0e  push    rcx
0x140004f0f  fcom    st(3)
0x140004f11  push    rbx
0x140004f12  mov     dh, 0
0x140004f14  push    rbx
0x140004f15  pop     rbx
0x140004f16  push    rcx
0x140004f17  pop     rcx
0x140004f18  nop
0x140004f19  lea     rcx, aKernel32Dll_0; "kernel32.dll"
0x140004f20  call    cs:GetModuleHandleW; KERNEL32
0x140004f26  lea     rdx, aDeviceiocontro; "DeviceIoControl"
0x140004f2d  mov     rcx, rax; hModule
0x140004f30  call    cs:GetProcAddress; KERNEL32
0x140004f36  mov     qword ptr [rsp+0F8h+var_A8], rax
0x140004f3b  mov     eax, cs:dword_140021390
0x140004f41  add     eax, 800025E4h
0x140004f46  mov     qword ptr [rsp+0F8h+var_C0], 0
0x140004f4f  lea     rcx, [rsp+0F8h+var_AC]
0x140004f54  mov     [rsp+0F8h+hTemplateFile], rcx
0x140004f59  mov     dword ptr [rsp+0F8h+dwFlagsAndAttributes], 88h
0x140004f61  lea     rcx, [rsp+0F8h+var_98]
0x140004f66  mov     [rsp+0F8h+dwCreationDisposition], rcx
0x140004f6b  mov     r9d, 88h
0x140004f71  lea     r8, [rsp+0F8h+var_98]
0x140004f76  mov     edx, eax
0x140004f78  mov     rcx, [rsp+0F8h+hObject]
0x140004f7d  call    qword ptr [rsp+0F8h+var_A8]
0x140004f81  test    eax, eax
0x140004f83  jnz     short loc_140004FA8
0x140004f85  call    cs:GetLastError; KERNEL32
0x140004f8b  mov     [rsp+0F8h+dwErrCode], eax
0x140004f8f  mov     rcx, [rsp+0F8h+hObject]; hObject
0x140004f94  call    cs:CloseHandle; KERNEL32
0x140004f9a  mov     ecx, [rsp+0F8h+dwErrCode]; dwErrCode
0x140004f9e  call    cs:SetLastError; KERNEL32
0x140004fa4  xor     eax, eax
0x140004fa6  jmp     short loc_140004FB8
0x140004fa8  mov     rcx, [rsp+0F8h+hObject]; hObject
0x140004fad  call    cs:CloseHandle; KERNEL32
0x140004fb3  mov     eax, 1
0x140004fb8  add     rsp, 0F8h
0x140004fbf  retn
0x14008e301  push    8E128h
0x14008e306  push    46h ; 'F'
0x14008e30b  jmp     sub_14008DE87

// ===== sub_140004FC0 @ 0x140004fc0 =====

0x140004fc0  push    rdi
0x140004fc2  sub     rsp, 340h
0x140004fc9  lea     rax, [rsp+348h+var_308]
0x140004fce  mov     rdi, rax
0x140004fd1  xor     eax, eax
0x140004fd3  mov     ecx, 200h
0x140004fd8  rep stosb
0x140004fda  lea     rcx, [rsp+348h+var_308]
0x140004fdf  call    sub_1400050D0
0x140004fe4  test    eax, eax
0x140004fe6  jnz     short loc_14000505E
0x140004fe8  mov     [rsp+348h+var_310], 200h
0x140004ff0  lea     r9, aDiskpt; "diskpt"
0x140004ff7  lea     r8, aSystemCurrentc; "SYSTEM\\CurrentControlSet\\Services\\%s"
0x140004ffe  mov     edx, 80h; BufferCount
0x140005003  lea     rcx, [rsp+348h+pszSubKey]; Buffer
0x14000500b  call    swprintf
0x140005010  lea     rax, [rsp+348h+var_310]
0x140005015  mov     [rsp+348h+pcbData], rax; pcbData
0x14000501a  lea     rax, [rsp+348h+var_308]
0x14000501f  mov     [rsp+348h+pvData], rax; pvData
0x140005024  lea     r9, [rsp+348h+pdwType]; pdwType
0x140005029  lea     r8, aGuid; "GUID"
0x140005030  lea     rdx, [rsp+348h+pszSubKey]; pszSubKey
0x140005038  mov     rcx, 0FFFFFFFF80000002h; hkey
0x14000503f  call    cs:SHGetValueW; SHLWAPI
0x140005045  mov     [rsp+348h+dwErrCode], eax
0x140005049  cmp     [rsp+348h+dwErrCode], 0
0x14000504e  jz      short loc_14000505E
0x140005050  mov     ecx, [rsp+348h+dwErrCode]; dwErrCode
0x140005054  call    cs:SetLastError; KERNEL32
0x14000505a  xor     eax, eax
0x14000505c  jmp     short loc_1400050B9
0x14000505e  jmp     loc_14008ECE6
0x1400050b9  add     rsp, 340h
0x1400050c0  pop     rdi
0x1400050c1  retn
0x14008ece6  push    8E315h
0x14008eceb  push    46h ; 'F'
0x14008ecf0  jmp     sub_14008DE87

// ===== sub_1400050D0 @ 0x1400050d0 =====

0x1400050d0  mov     [rsp+arg_0], rcx
0x1400050d5  push    rsi
0x1400050d6  push    rdi
0x1400050d7  sub     rsp, 0F8h
0x1400050de  mov     [rsp+108h+hTemplateFile], 0; hTemplateFile
0x1400050e7  mov     [rsp+108h+dwFlagsAndAttributes], 80h; dwFlagsAndAttributes
0x1400050ef  mov     dword ptr [rsp+108h+dwCreationDisposition], 3; dwCreationDisposition
0x1400050f7  xor     r9d, r9d; lpSecurityAttributes
0x1400050fa  mov     r8d, 3; dwShareMode
0x140005100  mov     edx, 80h; dwDesiredAccess
0x140005105  lea     rcx, FileName; "\\\\.\\DpControl"
0x14000510c  call    cs:CreateFileW; KERNEL32
0x140005112  mov     [rsp+108h+hObject], rax
0x140005117  cmp     [rsp+108h+hObject], 0FFFFFFFFFFFFFFFFh
0x14000511d  jnz     short loc_140005126
0x14000511f  xor     eax, eax
0x140005121  jmp     loc_140005201
0x140005126  lea     rax, [rsp+108h+var_A8]
0x14000512b  mov     rdi, rax
0x14000512e  xor     eax, eax
0x140005130  mov     ecx, 88h
0x140005135  rep stosb
0x140005137  jmp     loc_14008EE97
0x140005140  mov     ah, 88h
0x140005142  clc
0x140005143  push    rcx
0x140005145  pop     rcx
0x140005146  push    rax
0x140005147  pop     rax
0x140005148  nop
0x140005149  lea     rcx, aKernel32Dll_0; "kernel32.dll"
0x140005150  call    cs:GetModuleHandleW; KERNEL32
0x140005156  lea     rdx, aDeviceiocontro; "DeviceIoControl"
0x14000515d  mov     rcx, rax; hModule
0x140005160  call    cs:GetProcAddress; KERNEL32
0x140005166  mov     [rsp+108h+var_B8], rax
0x14000516b  mov     [rsp+108h+var_D0], 0
0x140005174  lea     rax, [rsp+108h+var_BC]
0x140005179  mov     [rsp+108h+hTemplateFile], rax
0x14000517e  mov     [rsp+108h+dwFlagsAndAttributes], 88h
0x140005186  lea     rax, [rsp+108h+var_A8]
0x14000518b  mov     [rsp+108h+dwCreationDisposition], rax
0x140005190  mov     r9d, 88h
0x140005196  lea     r8, [rsp+108h+var_A8]
0x14000519b  mov     edx, 800030A0h
0x1400051a0  mov     rcx, [rsp+108h+hObject]
0x1400051a5  call    [rsp+108h+var_B8]
0x1400051a9  test    eax, eax
0x1400051ab  jnz     short loc_1400051D0
0x1400051ad  call    cs:GetLastError; KERNEL32
0x1400051b3  mov     [rsp+108h+dwErrCode], eax
0x1400051b7  mov     rcx, [rsp+108h+hObject]; hObject
0x1400051bc  call    cs:CloseHandle; KERNEL32
0x1400051c2  mov     ecx, [rsp+108h+dwErrCode]; dwErrCode
0x1400051c6  call    cs:SetLastError; KERNEL32
0x1400051cc  xor     eax, eax
0x1400051ce  jmp     short loc_140005201
0x1400051d0  jmp     loc_14008F190
0x140005201  add     rsp, 0F8h
0x140005208  pop     rdi
0x140005209  pop     rsi
0x14000520a  retn
0x14008ee97  push    8ECFAh
0x14008ee9c  push    46h ; 'F'
0x14008eea1  jmp     sub_14008DE87
0x14008f190  push    8EEABh
0x14008f195  push    46h ; 'F'
0x14008f19a  jmp     sub_14008DE87

// ===== sub_140005210 @ 0x140005210 =====

0x140005210  mov     [rsp+arg_8], rdx
0x140005215  mov     [rsp+arg_0], cx
0x14000521a  push    rsi
0x14000521b  push    rdi
0x14000521c  sub     rsp, 38h
0x140005220  lea     rax, [rsp+48h+var_28]
0x140005225  lea     rcx, asc_140014C90; "\\\\.\\ :"
0x14000522c  mov     rdi, rax
0x14000522f  mov     rsi, rcx
0x140005232  mov     ecx, 0Eh
0x140005237  rep movsb
0x140005239  mov     eax, 2
0x14000523e  imul    rax, 4
0x140005242  movzx   ecx, [rsp+48h+arg_0]
0x140005247  mov     [rsp+rax+48h+var_28], cx
0x14000524c  mov     rdx, [rsp+48h+arg_8]
0x140005251  lea     rcx, [rsp+48h+var_28]
0x140005256  call    sub_140005270
0x14000525b  add     rsp, 38h
0x14000525f  pop     rdi
0x140005260  pop     rsi
0x140005261  retn

// ===== sub_140005270 @ 0x140005270 =====

0x140005270  mov     [rsp+arg_8], rdx
0x140005275  mov     [rsp+lpFileName], rcx
0x14000527a  sub     rsp, 0F8h
0x140005281  mov     [rsp+0F8h+hTemplateFile], 0; hTemplateFile
0x14000528a  mov     [rsp+0F8h+dwFlagsAndAttributes], 80h; dwFlagsAndAttributes
0x140005292  mov     [rsp+0F8h+dwCreationDisposition], 3; dwCreationDisposition
0x14000529a  xor     r9d, r9d; lpSecurityAttributes
0x14000529d  mov     r8d, 3; dwShareMode
0x1400052a3  mov     edx, 80h; dwDesiredAccess
0x1400052a8  mov     rcx, [rsp+0F8h+lpFileName]; lpFileName
0x1400052b0  call    cs:CreateFileW; KERNEL32
0x1400052b6  mov     [rsp+0F8h+var_B8], rax
0x1400052bb  cmp     [rsp+0F8h+var_B8], 0FFFFFFFFFFFFFFFFh
0x1400052c1  jnz     short loc_1400052CA
0x1400052c3  xor     eax, eax
0x1400052c5  jmp     loc_14000540B
0x1400052ca  jmp     loc_14008F37D
0x14000540b  add     rsp, 0F8h
0x140005412  retn
0x14008f37d  push    8F1A4h
0x14008f382  push    46h ; 'F'
0x14008f387  jmp     sub_14008DE87

// ===== sub_140005420 @ 0x140005420 =====

0x140005420  sub     rsp, 0F8h
0x140005427  jmp     loc_140091405
0x140091405  push    8F391h
0x14009140a  push    46h ; 'F'
0x14009140f  jmp     sub_14008DE87

// ===== sub_140005670 @ 0x140005670 =====

0x140005670  mov     [rsp+arg_0], rcx
0x140005675  sub     rsp, 0F8h
0x14000567c  mov     [rsp+0F8h+hTemplateFile], 0; hTemplateFile
0x140005685  mov     [rsp+0F8h+dwFlagsAndAttributes], 80h; dwFlagsAndAttributes
0x14000568d  mov     [rsp+0F8h+dwCreationDisposition], 3; dwCreationDisposition
0x140005695  xor     r9d, r9d; lpSecurityAttributes
0x140005698  mov     r8d, 3; dwShareMode
0x14000569e  mov     edx, 80h; dwDesiredAccess
0x1400056a3  lea     rcx, FileName; "\\\\.\\DpControl"
0x1400056aa  call    cs:CreateFileW; KERNEL32
0x1400056b0  mov     [rsp+0F8h+var_B8], rax
0x1400056b5  cmp     [rsp+0F8h+var_B8], 0FFFFFFFFFFFFFFFFh
0x1400056bb  jnz     short loc_1400056C9
0x1400056bd  mov     rax, 0FFFFFFFFFFFFFFFFh
0x1400056c4  jmp     loc_140005789
0x1400056c9  jmp     loc_14009185D
0x140005789  add     rsp, 0F8h
0x140005790  retn
0x14009185d  push    9160Ch
0x140091862  push    46h ; 'F'
0x140091867  jmp     sub_14008DE87

// ===== sub_1400057A0 @ 0x1400057a0 =====

0x1400057a0  mov     [rsp+arg_8], rdx
0x1400057a5  mov     [rsp+arg_0], rcx
0x1400057aa  push    rdi
0x1400057ab  sub     rsp, 0F0h
0x1400057b2  mov     [rsp+0F8h+hTemplateFile], 0; hTemplateFile
0x1400057bb  mov     [rsp+0F8h+dwFlagsAndAttributes], 80h; dwFlagsAndAttributes
0x1400057c3  mov     [rsp+0F8h+dwCreationDisposition], 3; dwCreationDisposition
0x1400057cb  xor     r9d, r9d; lpSecurityAttributes
0x1400057ce  mov     r8d, 3; dwShareMode
0x1400057d4  mov     edx, 80h; dwDesiredAccess
0x1400057d9  lea     rcx, FileName; "\\\\.\\DpControl"
0x1400057e0  call    cs:CreateFileW; KERNEL32
0x1400057e6  mov     [rsp+0F8h+var_B8], rax
0x1400057eb  cmp     [rsp+0F8h+var_B8], 0FFFFFFFFFFFFFFFFh
0x1400057f1  jnz     short loc_1400057FF
0x1400057f3  mov     rax, 0FFFFFFFFFFFFFFFFh
0x1400057fa  jmp     loc_1400058DD
0x1400057ff  lea     rax, [rsp+0F8h+var_98]
0x140005804  mov     rdi, rax
0x140005807  xor     eax, eax
0x140005809  mov     ecx, 88h
0x14000580e  rep stosb
0x140005810  jmp     loc_140091B3A
0x1400058d8  mov     rax, [rsp+0F8h+var_B8]
0x1400058dd  add     rsp, 0F0h
0x1400058e4  pop     rdi
0x1400058e5  retn
0x140091b3a  push    91871h
0x140091b3f  push    46h ; 'F'
0x140091b44  jmp     sub_14008DE87

// ===== sub_1400058F0 @ 0x1400058f0 =====

0x1400058f0  mov     [rsp+arg_8], rdx
0x1400058f5  mov     [rsp+arg_0], cx
0x1400058fa  push    rsi
0x1400058fb  push    rdi
0x1400058fc  sub     rsp, 108h
0x140005903  lea     rax, [rsp+118h+FileName]
0x140005908  lea     rcx, asc_140014C90; "\\\\.\\ :"
0x14000590f  mov     rdi, rax
0x140005912  mov     rsi, rcx
0x140005915  mov     ecx, 0Eh
0x14000591a  rep movsb
0x14000591c  mov     eax, 2
0x140005921  imul    rax, 4
0x140005925  movzx   ecx, [rsp+118h+arg_0]
0x14000592d  mov     [rsp+rax+118h+FileName], cx
0x140005932  mov     [rsp+118h+hTemplateFile], 0; hTemplateFile
0x14000593b  mov     [rsp+118h+dwFlagsAndAttributes], 80h; dwFlagsAndAttributes
0x140005943  mov     [rsp+118h+dwCreationDisposition], 3; dwCreationDisposition
0x14000594b  xor     r9d, r9d; lpSecurityAttributes
0x14000594e  mov     r8d, 3; dwShareMode
0x140005954  mov     edx, 80h; dwDesiredAccess
0x140005959  lea     rcx, [rsp+118h+FileName]; lpFileName
0x14000595e  call    cs:CreateFileW; KERNEL32
0x140005964  mov     [rsp+118h+var_D8], rax
0x140005969  cmp     [rsp+118h+var_D8], 0FFFFFFFFFFFFFFFFh
0x14000596f  jnz     short loc_140005978
0x140005971  xor     eax, eax
0x140005973  jmp     loc_140005A4D
0x140005978  jmp     loc_140091D9F
0x140005a48  mov     eax, 1
0x140005a4d  add     rsp, 108h
0x140005a54  pop     rdi
0x140005a55  pop     rsi
0x140005a56  retn
0x140091d9f  push    91B4Eh
0x140091da4  push    46h ; 'F'
0x140091da9  jmp     sub_14008DE87

// ===== sub_140005A57 @ 0x140005a57 =====

0x140005a57  jmp     qword ptr cs:byte_1400144D0+8

// ===== sub_140005A5D @ 0x140005a5d =====

0x140005a5d  jmp     qword ptr cs:byte_1400144D0+10h

// ===== wcschr @ 0x140005a64 =====

0x140005a64  sub     rsp, 18h
0x140005a68  movdqa  xmm2, [rsp+18h+var_18]
0x140005a6d  mov     r8, rcx
0x140005a70  movzx   eax, dx
0x140005a73  xor     r9d, r9d
0x140005a76  movd    xmm0, eax
0x140005a7a  pshuflw xmm1, xmm0, 0
0x140005a7f  pshufd  xmm3, xmm1, 0
0x140005a84  mov     rax, r8
0x140005a87  and     eax, 0FFFh
0x140005a8c  cmp     rax, 0FF0h
0x140005a92  ja      short loc_140005AC0
0x140005a94  movdqu  xmm1, xmmword ptr [r8]
0x140005a99  movdqa  xmm0, xmm2
0x140005a9d  pxor    xmm0, xmm2
0x140005aa1  movdqa  xmm2, xmm0
0x140005aa5  pcmpeqw xmm2, xmm1
0x140005aa9  pcmpeqw xmm1, xmm3
0x140005aad  por     xmm2, xmm1
0x140005ab1  pmovmskb eax, xmm2
0x140005ab5  test    eax, eax
0x140005ab7  jnz     short loc_140005AD6
0x140005ab9  mov     eax, 10h
0x140005abe  jmp     short loc_140005AD1
0x140005ac0  cmp     [r8], dx
0x140005ac4  jz      short loc_140005AED
0x140005ac6  cmp     [r8], r9w
0x140005aca  jz      short loc_140005AE9
0x140005acc  mov     eax, 2
0x140005ad1  add     r8, rax
0x140005ad4  jmp     short loc_140005A84
0x140005ad6  bsf     ecx, eax
0x140005ad9  add     r8, rcx
0x140005adc  cmp     [r8], dx
0x140005ae0  cmovz   r9, r8
0x140005ae4  mov     rax, r9
0x140005ae7  jmp     short loc_140005AF0
0x140005ae9  xor     eax, eax
0x140005aeb  jmp     short loc_140005AF0
0x140005aed  mov     rax, r8
0x140005af0  add     rsp, 18h
0x140005af4  retn

// ===== sub_140005B10 @ 0x140005b10 =====

0x140005b10  push    rdi
0x140005b11  mov     eax, edx
0x140005b13  mov     rdi, rcx
0x140005b16  mov     rcx, r8
0x140005b19  rep stosb
0x140005b1b  mov     rax, r11
0x140005b1e  pop     rdi
0x140005b1f  retn

// ===== sub_140005B30 @ 0x140005b30 =====

0x140005b30  mov     r11, rcx
0x140005b33  movzx   edx, dl
0x140005b36  mov     r9, 101010101010101h
0x140005b40  imul    r9, rdx
0x140005b44  cmp     r8, 10h; switch 17 cases
0x140005b48  jbe     loc_140005C40
0x140005b4e  movq    xmm0, r9; jumptable 0000000140005C5B default case
0x140005b53  punpcklbw xmm0, xmm0
0x140005b57  cmp     r8, 80h
0x140005b5e  ja      short loc_140005B70
0x140005b60  jmp     loc_140005BD0
0x140005b70  bt      cs:dword_14002138C, 1
0x140005b78  jb      short sub_140005B10
0x140005b7a  movups  xmmword ptr [rcx], xmm0
0x140005b7d  add     r8, rcx
0x140005b80  add     rcx, 10h
0x140005b84  and     rcx, 0FFFFFFFFFFFFFFF0h
0x140005b88  sub     r8, rcx
0x140005b8b  mov     r9, r8
0x140005b8e  shr     r9, 7
0x140005b92  jz      short loc_140005BD0
0x140005b94  nop     word ptr [rax+rax+00000000h]
0x140005ba0  movaps  xmmword ptr [rcx], xmm0
0x140005ba3  movaps  xmmword ptr [rcx+10h], xmm0
0x140005ba7  add     rcx, 80h
0x140005bae  movaps  xmmword ptr [rcx-60h], xmm0
0x140005bb2  movaps  xmmword ptr [rcx-50h], xmm0
0x140005bb6  dec     r9
0x140005bb9  movaps  xmmword ptr [rcx-40h], xmm0
0x140005bbd  movaps  xmmword ptr [rcx-30h], xmm0
0x140005bc1  movaps  xmmword ptr [rcx-20h], xmm0
0x140005bc5  movapd  xmmword ptr [rcx-10h], xmm0
0x140005bca  jnz     short loc_140005BA0
0x140005bcc  and     r8, 7Fh
0x140005bd0  mov     r9, r8
0x140005bd3  shr     r9, 4
0x140005bd7  jz      short loc_140005BEC
0x140005bd9  nop     dword ptr [rax+00000000h]
0x140005be0  movups  xmmword ptr [rcx], xmm0
0x140005be3  add     rcx, 10h
0x140005be7  dec     r9
0x140005bea  jnz     short loc_140005BE0
0x140005bec  and     r8, 0Fh
0x140005bf0  jz      short loc_140005BF8
0x140005bf2  movups  xmmword ptr [rcx+r8-10h], xmm0
0x140005bf8  mov     rax, r11
0x140005bfb  retn
0x140005c40  mov     rdx, r9
0x140005c43  lea     r9, cs:140000000h
0x140005c4a  mov     eax, ds:(jpt_140005C5B - 140000000h)[r9+r8*4]
0x140005c52  add     r9, rax
0x140005c55  add     rcx, r8
0x140005c58  mov     rax, r11
0x140005c5b  jmp     r9; switch jump
0x140005c60  mov     [rcx-0Fh], rdx; jumptable 0000000140005C5B case 15
0x140005c64  mov     [rcx-7], edx; jumptable 0000000140005C5B case 7
0x140005c67  mov     [rcx-3], dx; jumptable 0000000140005C5B case 3
0x140005c6b  mov     [rcx-1], dl; jumptable 0000000140005C5B case 1
0x140005c6e  retn; jumptable 0000000140005C5B case 0
0x140005c70  mov     [rcx-0Ch], rdx; jumptable 0000000140005C5B case 12
0x140005c74  mov     [rcx-4], edx; jumptable 0000000140005C5B case 4
0x140005c77  retn
0x140005c78  mov     [rcx-9], rdx; jumptable 0000000140005C5B case 9
0x140005c7c  mov     [rcx-1], dl
0x140005c7f  retn
0x140005c80  mov     [rcx-0Dh], rdx; jumptable 0000000140005C5B case 13
0x140005c84  mov     [rcx-5], edx; jumptable 0000000140005C5B case 5
0x140005c87  mov     [rcx-1], dl
0x140005c8a  retn
0x140005c90  mov     [rcx-0Eh], rdx; jumptable 0000000140005C5B case 14
0x140005c94  mov     [rcx-6], edx; jumptable 0000000140005C5B case 6
0x140005c97  mov     [rcx-2], dx; jumptable 0000000140005C5B case 2
0x140005c9b  retn
0x140005c9c  mov     [rax], rdx; jumptable 0000000140005C5B case 8
0x140005c9f  retn
0x140005ca0  mov     [rax], rdx; jumptable 0000000140005C5B case 11
0x140005ca3  mov     [rax+8], dx
0x140005ca7  mov     [rax+0Ah], dl
0x140005caa  retn
0x140005cb0  mov     [rax], rdx; jumptable 0000000140005C5B case 10
0x140005cb3  mov     [rax+8], dx
0x140005cb7  retn
0x140005cb8  mov     [rax], rdx; jumptable 0000000140005C5B case 16
0x140005cbb  mov     [rax+8], rdx
0x140005cbf  retn

// ===== wcsrchr @ 0x140005cc0 =====

0x140005cc0  mov     r8, rcx
0x140005cc3  movzx   r9d, dx
0x140005cc7  xor     ecx, ecx
0x140005cc9  cmp     cs:dword_140020018, 2
0x140005cd0  jge     short loc_140005CFD
0x140005cd2  mov     rdx, r8
0x140005cd5  movzx   eax, word ptr [r8]
0x140005cd9  add     r8, 2
0x140005cdd  test    ax, ax
0x140005ce0  jnz     short loc_140005CD5
0x140005ce2  sub     r8, 2
0x140005ce6  cmp     r8, rdx
0x140005ce9  jz      short loc_140005CF1
0x140005ceb  cmp     [r8], r9w
0x140005cef  jnz     short loc_140005CE2
0x140005cf1  cmp     [r8], r9w
0x140005cf5  cmovz   rcx, r8
0x140005cf9  mov     rax, rcx
0x140005cfc  retn
0x140005cfd  mov     rdx, rcx
0x140005d00  jmp     short loc_140005D1A
0x140005d02  cmp     [r8], r9w
0x140005d06  mov     rax, r8
0x140005d09  cmovnz  rax, rdx
0x140005d0d  mov     rdx, rax
0x140005d10  cmp     [r8], cx
0x140005d14  jz      short locret_140005D73
0x140005d16  add     r8, 2
0x140005d1a  lea     eax, [r8+1]
0x140005d1e  test    al, 0Eh
0x140005d20  jnz     short loc_140005D02
0x140005d22  cmp     cx, r9w
0x140005d26  jnz     short loc_140005D4C
0x140005d28  mov     eax, 0FFFF0001h
0x140005d2d  movd    xmm1, eax
0x140005d31  jmp     short loc_140005D37
0x140005d33  add     r8, 10h
0x140005d37  movdqu  xmm0, xmmword ptr [r8]
0x140005d3c  pcmpistri xmm1, xmm0, 15h
0x140005d42  jnz     short loc_140005D33
0x140005d44  movsxd  rax, ecx
0x140005d47  lea     rax, [r8+rax*2]
0x140005d4b  retn
0x140005d4c  movzx   eax, r9w
0x140005d50  movd    xmm1, eax
0x140005d54  movdqu  xmm0, xmmword ptr [r8]
0x140005d59  pcmpistri xmm1, xmm0, 41h ; 'A'
0x140005d5f  jnb     short loc_140005D68
0x140005d61  movsxd  rax, ecx
0x140005d64  lea     rdx, [r8+rax*2]
0x140005d68  jz      short loc_140005D70
0x140005d6a  add     r8, 10h
0x140005d6e  jmp     short loc_140005D54
0x140005d70  mov     rax, rdx
0x140005d73  retn

// ===== __C_specific_handler @ 0x140005d74 =====

0x140005d74  mov     [rsp+arg_0], rbx
0x140005d79  mov     [rsp+arg_8], rbp
0x140005d7e  mov     [rsp+arg_10], rsi
0x140005d83  push    rdi
0x140005d84  push    r12
0x140005d86  push    r13
0x140005d88  push    r14
0x140005d8a  push    r15
0x140005d8c  sub     rsp, 40h
0x140005d90  mov     rbp, rcx
0x140005d93  mov     r15, r9
0x140005d96  mov     rcx, r8
0x140005d99  mov     rdi, r8
0x140005d9c  mov     r13, rdx
0x140005d9f  call    __except_validate_context_record
0x140005da4  mov     r12, [r15+8]
0x140005da8  mov     r14, [r15]
0x140005dab  mov     rbx, [r15+38h]
0x140005daf  sub     r14, r12
0x140005db2  test    byte ptr [rbp+4], 66h
0x140005db6  mov     esi, [r15+48h]
0x140005dba  jnz     loc_140005E9C
0x140005dc0  mov     [rsp+68h+var_38], rbp
0x140005dc5  mov     [rsp+68h+var_30], rdi
0x140005dca  cmp     esi, [rbx]
0x140005dcc  jnb     loc_140005F5C
0x140005dd2  mov     edi, esi
0x140005dd4  add     rdi, rdi
0x140005dd7  mov     eax, [rbx+rdi*8+4]
0x140005ddb  cmp     r14, rax
0x140005dde  jb      loc_140005E8E
0x140005de4  mov     eax, [rbx+rdi*8+8]
0x140005de8  cmp     r14, rax
0x140005deb  jnb     loc_140005E8E
0x140005df1  cmp     dword ptr [rbx+rdi*8+10h], 0
0x140005df6  jz      loc_140005E8E
0x140005dfc  cmp     dword ptr [rbx+rdi*8+0Ch], 1
0x140005e01  jz      short loc_140005E1A
0x140005e03  mov     eax, [rbx+rdi*8+0Ch]
0x140005e07  lea     rcx, [rsp+68h+var_38]
0x140005e0c  add     rax, r12
0x140005e0f  mov     rdx, r13
0x140005e12  call    rax
0x140005e14  test    eax, eax
0x140005e16  js      short loc_140005E95
0x140005e18  jle     short loc_140005E8E
0x140005e1a  cmp     dword ptr [rbp+0], 0E06D7363h
0x140005e21  jnz     short loc_140005E4B
0x140005e23  cmp     cs:off_140014D30, 0
0x140005e2b  jz      short loc_140005E4B
0x140005e2d  lea     rcx, off_140014D30
0x140005e34  call    _IsNonwritableInCurrentImage
0x140005e39  test    eax, eax
0x140005e3b  jz      short loc_140005E4B
0x140005e3d  mov     edx, 1
0x140005e42  mov     rcx, rbp
0x140005e45  call    cs:off_140014D30
0x140005e4b  mov     ecx, [rbx+rdi*8+10h]
0x140005e4f  mov     r8d, 1
0x140005e55  add     rcx, r12
0x140005e58  mov     rdx, r13
0x140005e5b  call    _NLG_Notify
0x140005e60  mov     rax, [r15+40h]
0x140005e64  mov     r8, rbp; ExceptionRecord
0x140005e67  mov     edx, [rbx+rdi*8+10h]
0x140005e6b  mov     rcx, r13; TargetFrame
0x140005e6e  mov     r9d, [rbp+0]; ReturnValue
0x140005e72  add     rdx, r12; TargetIp
0x140005e75  mov     [rsp+68h+HistoryTable], rax; HistoryTable
0x140005e7a  mov     rax, [r15+28h]
0x140005e7e  mov     [rsp+68h+ContextRecord], rax; ContextRecord
0x140005e83  call    cs:RtlUnwindEx; KERNEL32
0x140005e89  call    __NLG_Return2
0x140005e8e  inc     esi
0x140005e90  jmp     loc_140005DCA
0x140005e95  xor     eax, eax
0x140005e97  jmp     loc_140005F61
0x140005e9c  mov     rdi, [r15+20h]
0x140005ea0  mov     r9d, [rbx]
0x140005ea3  sub     rdi, r12
0x140005ea6  cmp     esi, r9d
0x140005ea9  jnb     loc_140005F5C
0x140005eaf  mov     r8d, r9d
0x140005eb2  mov     edx, esi
0x140005eb4  mov     ecx, r8d
0x140005eb7  add     rdx, rdx
0x140005eba  mov     eax, [rbx+rdx*8+4]
0x140005ebe  cmp     r14, rax
0x140005ec1  jb      loc_140005F4F
0x140005ec7  mov     eax, [rbx+rdx*8+8]
0x140005ecb  cmp     r14, rax
0x140005ece  jnb     short loc_140005F4F
0x140005ed0  mov     r11d, [rbp+4]
0x140005ed4  and     r11d, 20h
0x140005ed8  jz      short loc_140005F1E
0x140005eda  xor     r10d, r10d
0x140005edd  test    r8d, r8d
0x140005ee0  jz      short loc_140005F16
0x140005ee2  mov     ecx, r10d
0x140005ee5  add     rcx, rcx
0x140005ee8  mov     eax, [rbx+rcx*8+4]
0x140005eec  cmp     rdi, rax
0x140005eef  jb      short loc_140005F0E
0x140005ef1  mov     eax, [rbx+rcx*8+8]
0x140005ef5  cmp     rdi, rax
0x140005ef8  jnb     short loc_140005F0E
0x140005efa  mov     eax, [rbx+rdx*8+10h]
0x140005efe  cmp     [rbx+rcx*8+10h], eax
0x140005f02  jnz     short loc_140005F0E
0x140005f04  mov     eax, [rbx+rdx*8+0Ch]
0x140005f08  cmp     [rbx+rcx*8+0Ch], eax
0x140005f0c  jz      short loc_140005F16
0x140005f0e  inc     r10d
0x140005f11  cmp     r10d, r8d
0x140005f14  jb      short loc_140005EE2
0x140005f16  mov     ecx, r9d
0x140005f19  cmp     r10d, r9d
0x140005f1c  jnz     short loc_140005F5C
0x140005f1e  mov     eax, [rbx+rdx*8+10h]
0x140005f22  test    eax, eax
0x140005f24  jz      short loc_140005F32
0x140005f26  cmp     rdi, rax
0x140005f29  jnz     short loc_140005F4F
0x140005f2b  test    r11d, r11d
0x140005f2e  jnz     short loc_140005F5C
0x140005f30  jmp     short loc_140005F4F
0x140005f32  lea     eax, [rsi+1]
0x140005f35  mov     cl, 1
0x140005f37  mov     [r15+48h], eax
0x140005f3b  mov     r8d, [rbx+rdx*8+0Ch]
0x140005f40  mov     rdx, r13
0x140005f43  add     r8, r12
0x140005f46  call    r8
0x140005f49  mov     r9d, [rbx]
0x140005f4c  mov     ecx, r9d
0x140005f4f  inc     esi
0x140005f51  mov     r8d, ecx
0x140005f54  cmp     esi, ecx
0x140005f56  jb      loc_140005EB2
0x140005f5c  mov     eax, 1
0x140005f61  lea     r11, [rsp+68h+var_28]
0x140005f66  mov     rbx, [r11+30h]
0x140005f6a  mov     rbp, [r11+38h]
0x140005f6e  mov     rsi, [r11+40h]
0x140005f72  mov     rsp, r11
0x140005f75  pop     r15
0x140005f77  pop     r14
0x140005f79  pop     r13
0x140005f7b  pop     r12
0x140005f7d  pop     rdi
0x140005f7e  retn

// ===== __vcrt_initialize @ 0x140005f80 =====

0x140005f80  sub     rsp, 28h
0x140005f84  call    __vcrt_initialize_pure_virtual_call_handler
0x140005f89  call    __vcrt_initialize_winapi_thunks
0x140005f8e  call    __vcrt_initialize_locks
0x140005f93  test    al, al
0x140005f95  jnz     short loc_140005F9B
0x140005f97  xor     al, al
0x140005f99  jmp     short loc_140005FAD
0x140005f9b  call    __vcrt_initialize_ptd
0x140005fa0  test    al, al
0x140005fa2  jnz     short loc_140005FAB
0x140005fa4  call    __vcrt_uninitialize_locks
0x140005fa9  jmp     short loc_140005F97
0x140005fab  mov     al, 1
0x140005fad  add     rsp, 28h
0x140005fb1  retn

// ===== __vcrt_uninitialize @ 0x140005fb4 =====

0x140005fb4  sub     rsp, 28h
0x140005fb8  test    cl, cl
0x140005fba  jnz     short loc_140005FCD
0x140005fbc  call    __vcrt_uninitialize_ptd
0x140005fc1  call    __vcrt_uninitialize_locks
0x140005fc6  xor     ecx, ecx
0x140005fc8  call    __vcrt_uninitialize_winapi_thunks
0x140005fcd  mov     al, 1
0x140005fcf  add     rsp, 28h
0x140005fd3  retn

// ===== __std_exception_copy @ 0x140005fd4 =====

0x140005fd4  mov     [rsp+arg_0], rbx
0x140005fd9  mov     [rsp+arg_8], rsi
0x140005fde  mov     [rsp+arg_10], rdi
0x140005fe3  push    r14
0x140005fe5  sub     rsp, 20h
0x140005fe9  cmp     byte ptr [rcx+8], 0
0x140005fed  mov     r14, rdx
0x140005ff0  mov     rsi, rcx
0x140005ff3  jz      short loc_140006041
0x140005ff5  mov     rax, [rcx]
0x140005ff8  test    rax, rax
0x140005ffb  jz      short loc_140006041
0x140005ffd  or      rdi, 0FFFFFFFFFFFFFFFFh
0x140006001  inc     rdi
0x140006004  cmp     byte ptr [rax+rdi], 0
0x140006008  jnz     short loc_140006001
0x14000600a  lea     rcx, [rdi+1]; Size
0x14000600e  call    j__malloc_base
0x140006013  mov     rbx, rax
0x140006016  test    rax, rax
0x140006019  jz      short loc_140006037
0x14000601b  mov     r8, [rsi]; Source
0x14000601e  lea     rdx, [rdi+1]; SizeInBytes
0x140006022  mov     rcx, rax; Destination
0x140006025  call    strcpy_s
0x14000602a  mov     rax, rbx
0x14000602d  mov     byte ptr [r14+8], 1
0x140006032  mov     [r14], rax
0x140006035  xor     ebx, ebx
0x140006037  mov     rcx, rbx; Block
0x14000603a  call    j__free_base
0x14000603f  jmp     short loc_14000604B
0x140006041  mov     rax, [rcx]
0x140006044  mov     [rdx], rax
0x140006047  mov     byte ptr [rdx+8], 0
0x14000604b  mov     rbx, [rsp+28h+arg_0]
0x140006050  mov     rsi, [rsp+28h+arg_8]
0x140006055  mov     rdi, [rsp+28h+arg_10]
0x14000605a  add     rsp, 20h
0x14000605e  pop     r14
0x140006060  retn

// ===== __std_exception_destroy @ 0x140006064 =====

0x140006064  push    rbx
0x140006066  sub     rsp, 20h
0x14000606a  cmp     byte ptr [rcx+8], 0
0x14000606e  mov     rbx, rcx
0x140006071  jz      short loc_14000607B
0x140006073  mov     rcx, [rcx]; Block
0x140006076  call    j__free_base
0x14000607b  and     qword ptr [rbx], 0
0x14000607f  mov     byte ptr [rbx+8], 0
0x140006083  add     rsp, 20h
0x140006087  pop     rbx
0x140006088  retn

// ===== _CxxThrowException @ 0x14000608c =====

0x14000608c  mov     [rsp-8+arg_8], rbx
0x140006091  mov     [rsp-8+arg_10], rdi
0x140006096  push    rbp
0x140006097  mov     rbp, rsp
0x14000609a  sub     rsp, 60h
0x14000609e  movaps  xmm0, cs:xmmword_140014CF0
0x1400060a5  mov     rbx, rdx
0x1400060a8  movaps  xmm1, cs:xmmword_140014D00
0x1400060af  mov     rdi, rcx
0x1400060b2  movaps  xmmword ptr [rbp+dwExceptionCode], xmm0
0x1400060b6  movaps  xmm0, cs:xmmword_140014D10
0x1400060bd  movaps  xmmword ptr [rbp+nNumberOfArguments], xmm1
0x1400060c1  movaps  xmm1, cs:xmmword_140014D20
0x1400060c8  movaps  xmmword ptr [rbp+Arguments], xmm0
0x1400060cc  movaps  [rbp+var_10], xmm1
0x1400060d0  test    rdx, rdx
0x1400060d3  jz      short loc_1400060F2
0x1400060d5  test    byte ptr [rdx], 10h
0x1400060d8  jz      short loc_1400060F2
0x1400060da  mov     rcx, [rcx]
0x1400060dd  sub     rcx, 8
0x1400060e1  mov     rax, [rcx]
0x1400060e4  mov     rbx, [rax+30h]
0x1400060e8  mov     rax, [rax+40h]
0x1400060ec  call    cs:__guard_dispatch_icall_fptr
0x1400060f2  lea     rdx, [rbp+BaseOfImage]; BaseOfImage
0x1400060f6  mov     [rbp+Arguments+8], rdi
0x1400060fa  mov     rcx, rbx; PcValue
0x1400060fd  mov     qword ptr [rbp+var_10], rbx
0x140006101  call    cs:RtlPcToFileHeader; KERNEL32
0x140006107  mov     [rbp+BaseOfImage], rax
0x14000610b  mov     qword ptr [rbp+var_10+8], rax
0x14000610f  test    rbx, rbx
0x140006112  jz      short loc_140006125
0x140006114  test    byte ptr [rbx], 8
0x140006117  jnz     short loc_14000611E
0x140006119  test    rax, rax
0x14000611c  jnz     short loc_140006125
0x14000611e  mov     dword ptr [rbp+Arguments], 1994000h
0x140006125  mov     r8d, [rbp+nNumberOfArguments+8]; nNumberOfArguments
0x140006129  lea     r9, [rbp+Arguments]; lpArguments
0x14000612d  mov     edx, [rbp+dwExceptionCode+4]; dwExceptionFlags
0x140006130  mov     ecx, [rbp+dwExceptionCode]; dwExceptionCode
0x140006133  call    cs:RaiseException; KERNEL32
0x140006139  lea     r11, [rsp+60h+var_s0]
0x14000613e  mov     rbx, [r11+18h]
0x140006142  mov     rdi, [r11+20h]
0x140006146  mov     rsp, r11
0x140006149  pop     rbp
0x14000614a  retn

// ===== __vcrt_freefls @ 0x14000614c =====

0x14000614c  sub     rsp, 28h
0x140006150  test    rcx, rcx
0x140006153  jz      short loc_140006166
0x140006155  lea     rax, unk_1400213A0
0x14000615c  cmp     rcx, rax
0x14000615f  jz      short loc_140006166
0x140006161  call    j__free_base
0x140006166  add     rsp, 28h
0x14000616a  retn

// ===== __vcrt_initialize_ptd @ 0x14000616c =====

0x14000616c  sub     rsp, 28h
0x140006170  lea     rcx, __vcrt_freefls
0x140006177  call    __vcrt_FlsAlloc
0x14000617c  mov     cs:dword_140020290, eax
0x140006182  cmp     eax, 0FFFFFFFFh
0x140006185  jz      short loc_1400061B6
0x140006187  lea     rdx, unk_1400213A0; lpTlsValue
0x14000618e  mov     ecx, eax; dwTlsIndex
0x140006190  call    __vcrt_FlsSetValue
0x140006195  test    eax, eax
0x140006197  jz      short loc_1400061B1
0x140006199  mov     rax, 0FFFFFFFFFFFFFFFEh
0x1400061a0  mov     cs:dword_140021418, eax
0x1400061a6  mov     cs:qword_140021420, rax
0x1400061ad  mov     al, 1
0x1400061af  jmp     short loc_1400061B8
0x1400061b1  call    __vcrt_uninitialize_ptd
0x1400061b6  xor     al, al
0x1400061b8  add     rsp, 28h
0x1400061bc  retn

// ===== __vcrt_uninitialize_ptd @ 0x1400061c0 =====

0x1400061c0  sub     rsp, 28h
0x1400061c4  mov     ecx, cs:dword_140020290
0x1400061ca  cmp     ecx, 0FFFFFFFFh
0x1400061cd  jz      short loc_1400061DB
0x1400061cf  call    __vcrt_FlsFree
0x1400061d4  or      cs:dword_140020290, 0FFFFFFFFh
0x1400061db  mov     al, 1
0x1400061dd  add     rsp, 28h
0x1400061e1  retn

// ===== _NLG_Notify @ 0x140006200 =====

0x140006200  mov     [rsp+arg_0], rcx
0x140006205  mov     [rsp+arg_10], rdx
0x14000620a  mov     [rsp+arg_8], r8d
0x14000620f  mov     r9, 19930520h
0x140006216  jmp     short __NLG_Dispatch2
0x140006220  retn

// ===== __NLG_Return2 @ 0x140006230 =====

0x140006230  retn

// ===== __except_validate_context_record @ 0x140006234 =====

0x140006234  mov     rax, cs:__guard_check_icall_fptr
0x14000623b  lea     rdx, _guard_check_icall_nop
0x140006242  cmp     rax, rdx
0x140006245  jz      short locret_14000626A
0x140006247  mov     rax, gs:30h
0x140006250  mov     rcx, [rcx+98h]
0x140006257  cmp     rcx, [rax+10h]
0x14000625b  jb      short loc_140006263
0x14000625d  cmp     rcx, [rax+8]
0x140006261  jbe     short locret_14000626A
0x140006263  mov     ecx, 0Dh
0x140006268  int     29h; Win8: RtlFailFast(ecx)
0x14000626a  retn

// ===== __DestructExceptionObject @ 0x14000626c =====

0x14000626c  test    rcx, rcx
0x14000626f  jz      short locret_1400062D6
0x140006271  mov     [rsp+arg_8], dl
0x140006275  sub     rsp, 28h
0x140006279  cmp     dword ptr [rcx], 0E06D7363h
0x14000627f  jnz     short loc_1400062D2
0x140006281  cmp     dword ptr [rcx+18h], 4
0x140006285  jnz     short loc_1400062D2
0x140006287  mov     eax, [rcx+20h]
0x14000628a  sub     eax, 19930520h
0x14000628f  cmp     eax, 2
0x140006292  ja      short loc_1400062D2
0x140006294  mov     rax, [rcx+30h]
0x140006298  test    rax, rax
0x14000629b  jz      short loc_1400062D2
0x14000629d  movsxd  rdx, dword ptr [rax+4]
0x1400062a1  test    edx, edx
0x1400062a3  jz      short loc_1400062B4
0x1400062a5  add     rdx, [rcx+38h]; void *
0x1400062a9  mov     rcx, [rcx+28h]; void *
0x1400062ad  call    ?_CallMemberFunction0@@YAXQEAX0@Z
0x1400062b2  jmp     short loc_1400062D2
0x1400062b4  test    byte ptr [rax], 10h
0x1400062b7  jz      short loc_1400062D2
0x1400062b9  mov     rax, [rcx+28h]
0x1400062bd  mov     rcx, [rax]
0x1400062c0  test    rcx, rcx
0x1400062c3  jz      short loc_1400062D2
0x1400062c5  mov     rax, [rcx]
0x1400062c8  mov     rax, [rax+10h]
0x1400062cc  call    cs:__guard_dispatch_icall_fptr
0x1400062d2  add     rsp, 28h
0x1400062d6  retn
0x1400062d7  call    terminate
0x140013966  push    rbp
0x140013968  sub     rsp, 20h
0x14001396c  mov     rbp, rdx
0x14001396f  xor     eax, eax
0x140013971  cmp     [rbp+38h], al
0x140013974  setnz   al
0x140013977  add     rsp, 20h
0x14001397b  pop     rbp
0x14001397c  retn

// ===== ?_CallMemberFunction0@@YAXQEAX0@Z @ 0x1400062e0 =====

0x1400062e0  jmp     rdx

// ===== __vcrt_initialize_locks @ 0x1400062e4 =====

0x1400062e4  push    rbx
0x1400062e6  sub     rsp, 20h
0x1400062ea  xor     ebx, ebx
0x1400062ec  lea     rdx, unk_140021438
0x1400062f3  xor     r8d, r8d
0x1400062f6  lea     rcx, [rbx+rbx*4]
0x1400062fa  lea     rcx, [rdx+rcx*8]; lpCriticalSection
0x1400062fe  mov     edx, 0FA0h; dwSpinCount
0x140006303  call    __vcrt_InitializeCriticalSectionEx
0x140006308  test    eax, eax
0x14000630a  jz      short loc_14000631D
0x14000630c  inc     cs:dword_140021460
0x140006312  inc     ebx
0x140006314  cmp     ebx, 1
0x140006317  jb      short loc_1400062EC
0x140006319  mov     al, 1
0x14000631b  jmp     short loc_140006324
0x14000631d  call    __vcrt_uninitialize_locks
0x140006322  xor     al, al
0x140006324  add     rsp, 20h
0x140006328  pop     rbx
0x140006329  retn

// ===== __vcrt_uninitialize_locks @ 0x14000632c =====

0x14000632c  push    rbx
0x14000632e  sub     rsp, 20h
0x140006332  mov     ebx, cs:dword_140021460
0x140006338  jmp     short loc_140006357
0x14000633a  lea     rax, unk_140021438
0x140006341  dec     ebx
0x140006343  lea     rcx, [rbx+rbx*4]
0x140006347  lea     rcx, [rax+rcx*8]; lpCriticalSection
0x14000634b  call    cs:DeleteCriticalSection; KERNEL32
0x140006351  dec     cs:dword_140021460
0x140006357  test    ebx, ebx
0x140006359  jnz     short loc_14000633A
0x14000635b  mov     al, 1
0x14000635d  add     rsp, 20h
0x140006361  pop     rbx
0x140006362  retn

// ===== ?try_get_function@@YAPEAXW4function_id@?A0x37284e77@@QEBDQEBW4module_id@2@2@Z @ 0x140006364 =====

0x140006364  mov     [rsp+arg_0], rbx
0x140006369  mov     [rsp+arg_8], rbp
0x14000636e  mov     [rsp+arg_10], rsi
0x140006373  push    rdi
0x140006374  push    r12
0x140006376  push    r13
0x140006378  push    r14
0x14000637a  push    r15
0x14000637c  sub     rsp, 20h
0x140006380  mov     r15d, ecx
0x140006383  lea     r14, cs:140000000h
0x14000638a  mov     r12, r9
0x14000638d  mov     rbp, r8
0x140006390  mov     r13, rdx
0x140006393  mov     rcx, rva qword_140021480[r14+r15*8]
0x14000639b  mov     r10, cs:__security_cookie
0x1400063a2  or      rdi, 0FFFFFFFFFFFFFFFFh
0x1400063a6  mov     eax, r10d
0x1400063a9  mov     rdx, r10
0x1400063ac  xor     rdx, rcx
0x1400063af  and     eax, 3Fh
0x1400063b2  mov     cl, al
0x1400063b4  ror     rdx, cl
0x1400063b7  cmp     rdx, rdi
0x1400063ba  jz      loc_14000651B
0x1400063c0  test    rdx, rdx
0x1400063c3  jz      short loc_1400063CD
0x1400063c5  mov     rax, rdx
0x1400063c8  jmp     loc_14000651D
0x1400063cd  cmp     r8, r12
0x1400063d0  jz      loc_1400064AF
0x1400063d6  mov     esi, [rbp+0]
0x1400063d9  mov     rbx, rva qword_140021468[r14+rsi*8]
0x1400063e1  test    rbx, rbx
0x1400063e4  jz      short loc_1400063F4
0x1400063e6  cmp     rbx, rdi
0x1400063e9  jz      loc_14000649B
0x1400063ef  jmp     loc_140006496
0x1400063f4  mov     r14, ds:rva off_140014D38[r14+rsi*8]
0x1400063fc  xor     edx, edx; hFile
0x1400063fe  mov     rcx, r14; lpLibFileName
0x140006401  mov     r8d, 800h; dwFlags
0x140006407  call    cs:LoadLibraryExW; KERNEL32
0x14000640d  mov     rbx, rax
0x140006410  test    rax, rax
0x140006413  jnz     short loc_140006464
0x140006415  call    cs:GetLastError; KERNEL32
0x14000641b  cmp     eax, 57h ; 'W'
0x14000641e  jnz     short loc_140006462
0x140006420  lea     ebx, [rax-50h]
0x140006423  mov     rcx, r14; String1
0x140006426  mov     r8d, ebx; MaxCount
0x140006429  lea     rdx, aApiMs
0x140006430  call    wcsncmp
0x140006435  test    eax, eax
0x140006437  jz      short loc_140006462
0x140006439  mov     r8d, ebx; MaxCount
0x14000643c  lea     rdx, aExtMs
0x140006443  mov     rcx, r14; String1
0x140006446  call    wcsncmp
0x14000644b  test    eax, eax
0x14000644d  jz      short loc_140006462
0x14000644f  xor     r8d, r8d; dwFlags
0x140006452  xor     edx, edx; hFile
0x140006454  mov     rcx, r14; lpLibFileName
0x140006457  call    cs:LoadLibraryExW; KERNEL32
0x14000645d  mov     rbx, rax
0x140006460  jmp     short loc_140006464
0x140006462  xor     ebx, ebx
0x140006464  lea     r14, cs:140000000h
0x14000646b  test    rbx, rbx
0x14000646e  jnz     short loc_14000647D
0x140006470  mov     rax, rdi
0x140006473  xchg    rax, rva qword_140021468[r14+rsi*8]
0x14000647b  jmp     short loc_14000649B
0x14000647d  mov     rax, rbx
0x140006480  xchg    rax, rva qword_140021468[r14+rsi*8]
0x140006488  test    rax, rax
0x14000648b  jz      short loc_140006496
0x14000648d  mov     rcx, rbx; hLibModule
0x140006490  call    cs:FreeLibrary; KERNEL32
0x140006496  test    rbx, rbx
0x140006499  jnz     short loc_1400064F0
0x14000649b  add     rbp, 4
0x14000649f  cmp     rbp, r12
0x1400064a2  jnz     loc_1400063D6
0x1400064a8  mov     r10, cs:__security_cookie
0x1400064af  xor     ebx, ebx
0x1400064b1  test    rbx, rbx
0x1400064b4  jz      short loc_140006500
0x1400064b6  mov     rdx, r13; lpProcName
0x1400064b9  mov     rcx, rbx; hModule
0x1400064bc  call    cs:GetProcAddress; KERNEL32
0x1400064c2  test    rax, rax
0x1400064c5  jz      short loc_1400064F9
0x1400064c7  mov     r8, cs:__security_cookie
0x1400064ce  mov     edx, 40h ; '@'
0x1400064d3  mov     ecx, r8d
0x1400064d6  and     ecx, 3Fh
0x1400064d9  sub     edx, ecx
0x1400064db  mov     cl, dl
0x1400064dd  mov     rdx, rax
0x1400064e0  ror     rdx, cl
0x1400064e3  xor     rdx, r8
0x1400064e6  xchg    rdx, rva qword_140021480[r14+r15*8]
0x1400064ee  jmp     short loc_14000651D
0x1400064f0  mov     r10, cs:__security_cookie
0x1400064f7  jmp     short loc_1400064B1
0x1400064f9  mov     r10, cs:__security_cookie
0x140006500  mov     eax, r10d
0x140006503  mov     ecx, 40h ; '@'
0x140006508  and     eax, 3Fh
0x14000650b  sub     ecx, eax
0x14000650d  ror     rdi, cl
0x140006510  xor     rdi, r10
0x140006513  xchg    rdi, rva qword_140021480[r14+r15*8]
0x14000651b  xor     eax, eax
0x14000651d  mov     rbx, [rsp+48h+arg_0]
0x140006522  mov     rbp, [rsp+48h+arg_8]
0x140006527  mov     rsi, [rsp+48h+arg_10]
0x14000652c  add     rsp, 20h
0x140006530  pop     r15
0x140006532  pop     r14
0x140006534  pop     r13
0x140006536  pop     r12
0x140006538  pop     rdi
0x140006539  retn

// ===== __vcrt_FlsAlloc @ 0x14000653c =====

0x14000653c  push    rbx
0x14000653e  sub     rsp, 20h
0x140006542  mov     rbx, rcx
0x140006545  lea     r9, aFlsalloc
0x14000654c  xor     ecx, ecx
0x14000654e  lea     r8, unk_140014E08
0x140006555  lea     rdx, aFlsalloc
0x14000655c  call    ?try_get_function@@YAPEAXW4function_id@?A0x37284e77@@QEBDQEBW4module_id@2@2@Z
0x140006561  test    rax, rax
0x140006564  jz      short loc_140006575
0x140006566  mov     rcx, rbx
0x140006569  add     rsp, 20h
0x14000656d  pop     rbx
0x14000656e  jmp     cs:__guard_dispatch_icall_fptr
0x140006575  add     rsp, 20h
0x140006579  pop     rbx
0x14000657a  jmp     cs:TlsAlloc; KERNEL32

// ===== __vcrt_FlsFree @ 0x140006584 =====

0x140006584  push    rbx
0x140006586  sub     rsp, 20h
0x14000658a  mov     ebx, ecx
0x14000658c  lea     r9, aFlsfree
0x140006593  mov     ecx, 1
0x140006598  lea     r8, unk_140014E20
0x14000659f  lea     rdx, aFlsfree
0x1400065a6  call    ?try_get_function@@YAPEAXW4function_id@?A0x37284e77@@QEBDQEBW4module_id@2@2@Z
0x1400065ab  mov     ecx, ebx
0x1400065ad  test    rax, rax
0x1400065b0  jz      short loc_1400065BE
0x1400065b2  add     rsp, 20h
0x1400065b6  pop     rbx
0x1400065b7  jmp     cs:__guard_dispatch_icall_fptr
0x1400065be  add     rsp, 20h
0x1400065c2  pop     rbx
0x1400065c3  jmp     cs:TlsFree; KERNEL32

// ===== __vcrt_FlsSetValue @ 0x1400065cc =====

0x1400065cc  mov     [rsp+arg_0], rbx
0x1400065d1  push    rdi
0x1400065d2  sub     rsp, 20h
0x1400065d6  mov     rbx, rdx
0x1400065d9  lea     r9, aFlssetvalue
0x1400065e0  mov     edi, ecx
0x1400065e2  lea     rdx, aFlssetvalue
0x1400065e9  mov     ecx, 3
0x1400065ee  lea     r8, unk_140014E30
0x1400065f5  call    ?try_get_function@@YAPEAXW4function_id@?A0x37284e77@@QEBDQEBW4module_id@2@2@Z
0x1400065fa  mov     rdx, rbx; lpTlsValue
0x1400065fd  mov     ecx, edi; dwTlsIndex
0x1400065ff  test    rax, rax
0x140006602  jz      short loc_14000660C
0x140006604  call    cs:__guard_dispatch_icall_fptr
0x14000660a  jmp     short loc_140006612
0x14000660c  call    cs:TlsSetValue; KERNEL32
0x140006612  mov     rbx, [rsp+28h+arg_0]
0x140006617  add     rsp, 20h
0x14000661b  pop     rdi
0x14000661c  retn

// ===== __vcrt_InitializeCriticalSectionEx @ 0x140006620 =====

0x140006620  mov     [rsp+arg_0], rbx
0x140006625  mov     [rsp+arg_8], rsi
0x14000662a  push    rdi
0x14000662b  sub     rsp, 20h
0x14000662f  mov     esi, r8d
0x140006632  lea     r9, aInitializecrit
0x140006639  mov     ebx, edx
0x14000663b  lea     r8, unk_140014E48
0x140006642  mov     rdi, rcx
0x140006645  lea     rdx, aInitializecrit
0x14000664c  mov     ecx, 4
0x140006651  call    ?try_get_function@@YAPEAXW4function_id@?A0x37284e77@@QEBDQEBW4module_id@2@2@Z
0x140006656  mov     edx, ebx; dwSpinCount
0x140006658  mov     rcx, rdi; lpCriticalSection
0x14000665b  test    rax, rax
0x14000665e  jz      short loc_14000666B
0x140006660  mov     r8d, esi
0x140006663  call    cs:__guard_dispatch_icall_fptr
0x140006669  jmp     short loc_140006671
0x14000666b  call    cs:InitializeCriticalSectionAndSpinCount; KERNEL32
0x140006671  mov     rbx, [rsp+28h+arg_0]
0x140006676  mov     rsi, [rsp+28h+arg_8]
0x14000667b  add     rsp, 20h
0x14000667f  pop     rdi
0x140006680  retn

// ===== __vcrt_initialize_winapi_thunks @ 0x140006684 =====

0x140006684  mov     [rsp+arg_0], rdi
0x140006689  lea     rdi, qword_140021480
0x140006690  lea     rax, qword_1400214A8
0x140006697  cmp     rax, rdi
0x14000669a  mov     rax, cs:__security_cookie
0x1400066a1  sbb     rcx, rcx
0x1400066a4  not     rcx
0x1400066a7  and     ecx, 5
0x1400066aa  rep stosq
0x1400066ad  mov     rdi, [rsp+arg_0]
0x1400066b2  retn

// ===== __vcrt_uninitialize_winapi_thunks @ 0x1400066b4 =====

0x1400066b4  test    cl, cl
0x1400066b6  jnz     short locret_1400066F1
0x1400066b8  push    rbx
0x1400066b9  sub     rsp, 20h
0x1400066bd  lea     rbx, qword_140021468
0x1400066c4  mov     rcx, [rbx]; hLibModule
0x1400066c7  test    rcx, rcx
0x1400066ca  jz      short loc_1400066DC
0x1400066cc  cmp     rcx, 0FFFFFFFFFFFFFFFFh
0x1400066d0  jz      short loc_1400066D8
0x1400066d2  call    cs:FreeLibrary; KERNEL32
0x1400066d8  and     qword ptr [rbx], 0
0x1400066dc  add     rbx, 8
0x1400066e0  lea     rax, qword_140021480
0x1400066e7  cmp     rbx, rax
0x1400066ea  jnz     short loc_1400066C4
0x1400066ec  add     rsp, 20h
0x1400066f0  pop     rbx
0x1400066f1  retn

// ===== __vcrt_initialize_pure_virtual_call_handler @ 0x1400066f4 =====

0x1400066f4  mov     rax, cs:__security_cookie
0x1400066fb  mov     cs:qword_1400214A8, rax
0x140006702  retn

// ===== _CallSettingFrame @ 0x140006720 =====

0x140006720  sub     rsp, 28h
0x140006724  mov     [rsp+28h+arg_0], rcx
0x140006729  mov     [rsp+28h+arg_8], rdx
0x14000672e  mov     [rsp+28h+arg_10], r8d
0x140006733  mov     rdx, [rdx]
0x140006736  mov     rax, rcx
0x140006739  call    _NLG_Notify
0x14000673e  call    rax
0x140006740  call    __NLG_Return2
0x140006745  mov     rcx, rax
0x140006748  mov     rdx, [rsp+28h+arg_8]
0x14000674d  mov     rdx, [rdx]
0x140006750  mov     r8d, 2
0x140006756  call    _NLG_Notify
0x14000675b  add     rsp, 28h
0x14000675f  retn

// ===== _CallSettingFrameEncoded @ 0x140006770 =====

0x140006770  sub     rsp, 28h
0x140006774  mov     [rsp+28h+arg_0], rcx
0x140006779  mov     [rsp+28h+arg_8], rdx
0x14000677e  mov     [rsp+28h+arg_10], r8
0x140006783  mov     [rsp+28h+arg_18], r9d
0x140006788  mov     r8d, r9d
0x14000678b  mov     rax, rcx
0x14000678e  call    _NLG_Notify
0x140006793  mov     rcx, [rsp+28h+arg_10]
0x140006798  call    rax
0x14000679a  call    __NLG_Return2
0x14000679f  mov     rcx, rax
0x1400067a2  mov     rdx, [rsp+28h+arg_8]
0x1400067a7  mov     r8d, 2
0x1400067ad  call    _NLG_Notify
0x1400067b2  add     rsp, 28h
0x1400067b6  retn

// ===== sub_1400067D0 @ 0x1400067d0 =====

0x1400067d0  push    rdi
0x1400067d1  push    rsi
0x1400067d2  mov     rax, r11
0x1400067d5  mov     rdi, rcx
0x1400067d8  mov     rcx, r8
0x1400067db  mov     rsi, r10
0x1400067de  rep movsb
0x1400067e0  pop     rsi
0x1400067e1  pop     rdi
0x1400067e2  retn

// ===== sub_1400067F0 @ 0x1400067f0 =====

0x1400067f0  mov     r11, rcx
0x1400067f3  mov     r10, rdx
0x1400067f6  cmp     r8, 10h; switch 17 cases
0x1400067fa  jbe     short loc_140006860
0x1400067fc  cmp     r8, 20h ; ' '; jumptable 0000000140006875 default case
0x140006800  jbe     short loc_140006840
0x140006802  sub     rdx, rcx
0x140006805  jnb     short loc_140006814
0x140006807  lea     rax, [r8+r10]
0x14000680b  cmp     rcx, rax
0x14000680e  jb      loc_140006B40
0x140006814  cmp     r8, 80h
0x14000681b  jbe     loc_140006A80
0x140006821  bt      cs:dword_14002138C, 1
0x140006829  jnb     loc_1400069D0
0x14000682f  jmp     short sub_1400067D0
0x140006840  movups  xmm0, xmmword ptr [rdx]
0x140006843  movups  xmm1, xmmword ptr [rdx+r8-10h]
0x140006849  movups  xmmword ptr [rcx], xmm0
0x14000684c  movups  xmmword ptr [rcx+r8-10h], xmm1
0x140006852  mov     rax, rcx
0x140006855  retn
0x140006860  mov     rax, rcx
0x140006863  lea     r9, cs:140000000h
0x14000686a  mov     ecx, ds:(jpt_140006875 - 140000000h)[r9+r8*4]
0x140006872  add     rcx, r9
0x140006875  jmp     rcx; switch jump
0x1400068c0  retn; jumptable 0000000140006875 case 0
0x1400068c1  movzx   ecx, word ptr [rdx]; jumptable 0000000140006875 case 2
0x1400068c4  mov     [rax], cx
0x1400068c7  retn
0x1400068c8  mov     rcx, [rdx]; jumptable 0000000140006875 case 8
0x1400068cb  mov     [rax], rcx
0x1400068ce  retn
0x1400068cf  movzx   ecx, word ptr [rdx]; jumptable 0000000140006875 case 3
0x1400068d2  movzx   r8d, byte ptr [rdx+2]
0x1400068d7  mov     [rax], cx
0x1400068da  mov     [rax+2], r8b
0x1400068de  retn
0x1400068df  movzx   ecx, byte ptr [rdx]; jumptable 0000000140006875 case 1
0x1400068e2  mov     [rax], cl
0x1400068e4  retn
0x1400068e5  movdqu  xmm0, xmmword ptr [rdx]; jumptable 0000000140006875 case 16
0x1400068e9  movdqu  xmmword ptr [rax], xmm0
0x1400068ed  retn
0x1400068f0  mov     r8, [rdx]; jumptable 0000000140006875 case 11
0x1400068f3  movzx   ecx, word ptr [rdx+8]
0x1400068f7  movzx   r9d, byte ptr [rdx+0Ah]
0x1400068fc  mov     [rax], r8
0x1400068ff  mov     [rax+8], cx
0x140006903  mov     [rax+0Ah], r9b
0x140006907  retn
0x140006908  mov     ecx, [rdx]; jumptable 0000000140006875 case 4
0x14000690a  mov     [rax], ecx
0x14000690c  retn
0x140006910  mov     ecx, [rdx]; jumptable 0000000140006875 case 5
0x140006912  movzx   r8d, byte ptr [rdx+4]
0x140006917  mov     [rax], ecx
0x140006919  mov     [rax+4], r8b
0x14000691d  retn
0x140006920  mov     ecx, [rdx]; jumptable 0000000140006875 case 6
0x140006922  movzx   r8d, word ptr [rdx+4]
0x140006927  mov     [rax], ecx
0x140006929  mov     [rax+4], r8w
0x14000692e  retn
0x140006930  mov     ecx, [rdx]; jumptable 0000000140006875 case 7
0x140006932  movzx   r8d, word ptr [rdx+4]
0x140006937  movzx   r9d, byte ptr [rdx+6]
0x14000693c  mov     [rax], ecx
0x14000693e  mov     [rax+4], r8w
0x140006943  mov     [rax+6], r9b
0x140006947  retn
0x140006948  mov     r8, [rdx]; jumptable 0000000140006875 case 13
0x14000694b  mov     ecx, [rdx+8]
0x14000694e  movzx   r9d, byte ptr [rdx+0Ch]
0x140006953  mov     [rax], r8
0x140006956  mov     [rax+8], ecx
0x140006959  mov     [rax+0Ch], r9b
0x14000695d  retn
0x140006960  mov     r8, [rdx]; jumptable 0000000140006875 case 9
0x140006963  movzx   ecx, byte ptr [rdx+8]
0x140006967  mov     [rax], r8
0x14000696a  mov     [rax+8], cl
0x14000696d  retn
0x140006970  mov     r8, [rdx]; jumptable 0000000140006875 case 10
0x140006973  movzx   ecx, word ptr [rdx+8]
0x140006977  mov     [rax], r8
0x14000697a  mov     [rax+8], cx
0x14000697e  retn
0x140006980  mov     r8, [rdx]; jumptable 0000000140006875 case 12
0x140006983  mov     ecx, [rdx+8]
0x140006986  mov     [rax], r8
0x140006989  mov     [rax+8], ecx
0x14000698c  retn
0x140006990  mov     r8, [rdx]; jumptable 0000000140006875 case 14
0x140006993  mov     ecx, [rdx+8]
0x140006996  movzx   r9d, word ptr [rdx+0Ch]
0x14000699b  mov     [rax], r8
0x14000699e  mov     [rax+8], ecx
0x1400069a1  mov     [rax+0Ch], r9w
0x1400069a6  retn
0x1400069b0  mov     r8, [rdx]; jumptable 0000000140006875 case 15
0x1400069b3  mov     ecx, [rdx+8]
0x1400069b6  movzx   r9d, word ptr [rdx+0Ch]
0x1400069bb  movzx   r10d, byte ptr [rdx+0Eh]
0x1400069c0  mov     [rax], r8
0x1400069c3  mov     [rax+8], ecx
0x1400069c6  mov     [rax+0Ch], r9w
0x1400069cb  mov     [rax+0Eh], r10b
0x1400069cf  retn
0x1400069d0  movups  xmm0, xmmword ptr [rcx+rdx]
0x1400069d4  add     r8, rcx
0x1400069d7  add     rcx, 10h
0x1400069db  test    r11b, 0Fh
0x1400069df  jz      short loc_1400069F4
0x1400069e1  movaps  xmm1, xmm0
0x1400069e4  and     rcx, 0FFFFFFFFFFFFFFF0h
0x1400069e8  movups  xmm0, xmmword ptr [rcx+rdx]
0x1400069ec  add     rcx, 10h
0x1400069f0  movups  xmmword ptr [r11], xmm1
0x1400069f4  sub     r8, rcx
0x1400069f7  mov     r9, r8
0x1400069fa  shr     r9, 7
0x1400069fe  jz      loc_140006A8C
0x140006a04  movaps  xmmword ptr [rcx-10h], xmm0
0x140006a08  cmp     r9, cs:qword_140020020
0x140006a0f  jbe     short loc_140006A28
0x140006a11  jmp     loc_140006AD8
0x140006a20  movaps  xmmword ptr [rcx-20h], xmm0
0x140006a24  movaps  xmmword ptr [rcx-10h], xmm1
0x140006a28  movups  xmm0, xmmword ptr [rcx+rdx]
0x140006a2c  movups  xmm1, xmmword ptr [rcx+rdx+10h]
0x140006a31  add     rcx, 80h
0x140006a38  movaps  xmmword ptr [rcx-80h], xmm0
0x140006a3c  movaps  xmmword ptr [rcx-70h], xmm1
0x140006a40  movups  xmm0, xmmword ptr [rcx+rdx-60h]
0x140006a45  movups  xmm1, xmmword ptr [rcx+rdx-50h]
0x140006a4a  dec     r9
0x140006a4d  movaps  xmmword ptr [rcx-60h], xmm0
0x140006a51  movaps  xmmword ptr [rcx-50h], xmm1
0x140006a55  movups  xmm0, xmmword ptr [rcx+rdx-40h]
0x140006a5a  movups  xmm1, xmmword ptr [rcx+rdx-30h]
0x140006a5f  movaps  xmmword ptr [rcx-40h], xmm0
0x140006a63  movaps  xmmword ptr [rcx-30h], xmm1
0x140006a67  movups  xmm0, xmmword ptr [rcx+rdx-20h]
0x140006a6c  movups  xmm1, xmmword ptr [rcx+rdx-10h]
0x140006a71  jnz     short loc_140006A20
0x140006a73  movaps  xmmword ptr [rcx-20h], xmm0
0x140006a77  and     r8, 7Fh
0x140006a7b  movaps  xmm0, xmm1
0x140006a7e  jmp     short loc_140006A8C
0x140006a80  movups  xmm0, xmmword ptr [rcx+rdx]
0x140006a84  add     rcx, 10h
0x140006a88  sub     r8, 10h
0x140006a8c  mov     r9, r8
0x140006a8f  shr     r9, 4
0x140006a93  jz      short loc_140006AB1
0x140006a95  nop     word ptr [rax+rax+00000000h]
0x140006aa0  movups  xmmword ptr [rcx-10h], xmm0
0x140006aa4  movups  xmm0, xmmword ptr [rcx+rdx]
0x140006aa8  add     rcx, 10h
0x140006aac  dec     r9
0x140006aaf  jnz     short loc_140006AA0
0x140006ab1  and     r8, 0Fh
0x140006ab5  jz      short loc_140006AC4
0x140006ab7  lea     rax, [rcx+r8]
0x140006abb  movups  xmm1, xmmword ptr [rax+rdx-10h]
0x140006ac0  movups  xmmword ptr [rax-10h], xmm1
0x140006ac4  movups  xmmword ptr [rcx-10h], xmm0
0x140006ac8  mov     rax, r11
0x140006acb  retn
0x140006ad0  movntps xmmword ptr [rcx-20h], xmm0
0x140006ad4  movntps xmmword ptr [rcx-10h], xmm1
0x140006ad8  prefetchnta byte ptr [rcx+rdx+200h]
0x140006ae0  movups  xmm0, xmmword ptr [rcx+rdx]
0x140006ae4  movups  xmm1, xmmword ptr [rcx+rdx+10h]
0x140006ae9  add     rcx, 80h
0x140006af0  movntps xmmword ptr [rcx-80h], xmm0
0x140006af4  movntps xmmword ptr [rcx-70h], xmm1
0x140006af8  movups  xmm0, xmmword ptr [rcx+rdx-60h]
0x140006afd  movups  xmm1, xmmword ptr [rcx+rdx-50h]
0x140006b02  dec     r9
0x140006b05  movntps xmmword ptr [rcx-60h], xmm0
0x140006b09  movntps xmmword ptr [rcx-50h], xmm1
0x140006b0d  movups  xmm0, xmmword ptr [rcx+rdx-40h]
0x140006b12  movups  xmm1, xmmword ptr [rcx+rdx-30h]
0x140006b17  prefetchnta byte ptr [rcx+rdx+240h]
0x140006b1f  movntps xmmword ptr [rcx-40h], xmm0
0x140006b23  movntps xmmword ptr [rcx-30h], xmm1
0x140006b27  movups  xmm0, xmmword ptr [rcx+rdx-20h]
0x140006b2c  movups  xmm1, xmmword ptr [rcx+rdx-10h]
0x140006b31  jnz     short loc_140006AD0
0x140006b33  sfence
0x140006b36  jmp     loc_140006A73
0x140006b40  add     rcx, r8
0x140006b43  movups  xmm0, xmmword ptr [rcx+rdx-10h]
0x140006b48  sub     rcx, 10h
0x140006b4c  sub     r8, 10h
0x140006b50  test    cl, 0Fh
0x140006b53  jz      short loc_140006B6C
0x140006b55  mov     rax, rcx
0x140006b58  and     rcx, 0FFFFFFFFFFFFFFF0h
0x140006b5c  movups  xmm1, xmm0
0x140006b5f  movups  xmm0, xmmword ptr [rcx+rdx]
0x140006b63  movups  xmmword ptr [rax], xmm1
0x140006b66  mov     r8, rcx
0x140006b69  sub     r8, r11
0x140006b6c  mov     r9, r8
0x140006b6f  shr     r9, 7
0x140006b73  jz      short loc_140006BDD
0x140006b75  movaps  xmmword ptr [rcx], xmm0
0x140006b78  jmp     short loc_140006B87
0x140006b80  movaps  xmmword ptr [rcx+10h], xmm0
0x140006b84  movaps  xmmword ptr [rcx], xmm1
0x140006b87  movups  xmm0, xmmword ptr [rcx+rdx-10h]
0x140006b8c  movups  xmm1, xmmword ptr [rcx+rdx-20h]
0x140006b91  sub     rcx, 80h
0x140006b98  movaps  xmmword ptr [rcx+70h], xmm0
0x140006b9c  movaps  xmmword ptr [rcx+60h], xmm1
0x140006ba0  movups  xmm0, xmmword ptr [rcx+rdx+50h]
0x140006ba5  movups  xmm1, xmmword ptr [rcx+rdx+40h]
0x140006baa  dec     r9
0x140006bad  movaps  xmmword ptr [rcx+50h], xmm0
0x140006bb1  movaps  xmmword ptr [rcx+40h], xmm1
0x140006bb5  movups  xmm0, xmmword ptr [rcx+rdx+30h]
0x140006bba  movups  xmm1, xmmword ptr [rcx+rdx+20h]
0x140006bbf  movaps  xmmword ptr [rcx+30h], xmm0
0x140006bc3  movaps  xmmword ptr [rcx+20h], xmm1
0x140006bc7  movups  xmm0, xmmword ptr [rcx+rdx+10h]
0x140006bcc  movups  xmm1, xmmword ptr [rcx+rdx]
0x140006bd0  jnz     short loc_140006B80
0x140006bd2  movaps  xmmword ptr [rcx+10h], xmm0
0x140006bd6  and     r8, 7Fh
0x140006bda  movaps  xmm0, xmm1
0x140006bdd  mov     r9, r8
0x140006be0  shr     r9, 4
0x140006be4  jz      short loc_140006C00
0x140006be6  nop     word ptr [rax+rax+00000000h]
0x140006bf0  movups  xmmword ptr [rcx], xmm0
0x140006bf3  sub     rcx, 10h
0x140006bf7  movups  xmm0, xmmword ptr [rcx+rdx]
0x140006bfb  dec     r9
0x140006bfe  jnz     short loc_140006BF0
0x140006c00  and     r8, 0Fh
0x140006c04  jz      short loc_140006C0E
0x140006c06  movups  xmm1, xmmword ptr [r10]
0x140006c0a  movups  xmmword ptr [r11], xmm1
0x140006c0e  movups  xmmword ptr [rcx], xmm0
0x140006c11  mov     rax, r11
0x140006c14  retn

// ===== wcscat_s @ 0x140006c18 =====

0x140006c18  push    rbx
0x140006c1a  sub     rsp, 20h
0x140006c1e  xor     ebx, ebx
0x140006c20  mov     r9, rcx
0x140006c23  test    rcx, rcx
0x140006c26  jz      short loc_140006C35
0x140006c28  test    rdx, rdx
0x140006c2b  jz      short loc_140006C35
0x140006c2d  test    r8, r8
0x140006c30  jnz     short loc_140006C4E
0x140006c32  mov     [rcx], bx
0x140006c35  call    _errno
0x140006c3a  mov     ebx, 16h
0x140006c3f  mov     [rax], ebx
0x140006c41  call    _invalid_parameter_noinfo
0x140006c46  mov     eax, ebx
0x140006c48  add     rsp, 20h
0x140006c4c  pop     rbx
0x140006c4d  retn
0x140006c4e  cmp     [rcx], bx
0x140006c51  jz      short loc_140006C5D
0x140006c53  add     rcx, 2
0x140006c57  sub     rdx, 1
0x140006c5b  jnz     short loc_140006C4E
0x140006c5d  test    rdx, rdx
0x140006c60  jnz     short loc_140006C68
0x140006c62  mov     [r9], bx
0x140006c66  jmp     short loc_140006C35
0x140006c68  sub     r8, rcx
0x140006c6b  movzx   eax, word ptr [r8+rcx]
0x140006c70  mov     [rcx], ax
0x140006c73  lea     rcx, [rcx+2]
0x140006c77  test    ax, ax
0x140006c7a  jz      short loc_140006C82
0x140006c7c  sub     rdx, 1
0x140006c80  jnz     short loc_140006C6B
0x140006c82  test    rdx, rdx
0x140006c85  jnz     short loc_140006C46
0x140006c87  mov     [r9], bx
0x140006c8b  call    _errno
0x140006c90  mov     ebx, 22h ; '"'
0x140006c95  jmp     short loc_140006C3F

// ===== wcscpy_s @ 0x140006c98 =====

0x140006c98  push    rbx
0x140006c9a  sub     rsp, 20h
0x140006c9e  xor     ebx, ebx
0x140006ca0  test    rcx, rcx
0x140006ca3  jz      short loc_140006CB2
0x140006ca5  test    rdx, rdx
0x140006ca8  jz      short loc_140006CB2
0x140006caa  test    r8, r8
0x140006cad  jnz     short loc_140006CCB
0x140006caf  mov     [rcx], bx
0x140006cb2  call    _errno
0x140006cb7  mov     ebx, 16h
0x140006cbc  mov     [rax], ebx
0x140006cbe  call    _invalid_parameter_noinfo
0x140006cc3  mov     eax, ebx
0x140006cc5  add     rsp, 20h
0x140006cc9  pop     rbx
0x140006cca  retn
0x140006ccb  mov     r9, rcx
0x140006cce  sub     r8, rcx
0x140006cd1  movzx   eax, word ptr [r8+r9]
0x140006cd6  mov     [r9], ax
0x140006cda  lea     r9, [r9+2]
0x140006cde  test    ax, ax
0x140006ce1  jz      short loc_140006CE9
0x140006ce3  sub     rdx, 1
0x140006ce7  jnz     short loc_140006CD1
0x140006ce9  test    rdx, rdx
0x140006cec  jnz     short loc_140006CC3
0x140006cee  mov     [rcx], bx
0x140006cf1  call    _errno
0x140006cf6  mov     ebx, 22h ; '"'
0x140006cfb  jmp     short loc_140006CBC

// ===== wcsncpy_s @ 0x140006d00 =====

0x140006d00  mov     [rsp+arg_0], rbx
0x140006d05  push    rdi
0x140006d06  sub     rsp, 20h
0x140006d0a  xor     r10d, r10d
0x140006d0d  mov     r11, rdx
0x140006d10  test    r9, r9
0x140006d13  jnz     short loc_140006D41
0x140006d15  test    rcx, rcx
0x140006d18  jnz     short loc_140006D46
0x140006d1a  test    rdx, rdx
0x140006d1d  jz      short loc_140006D33
0x140006d1f  call    _errno
0x140006d24  mov     ebx, 16h
0x140006d29  mov     [rax], ebx
0x140006d2b  call    _invalid_parameter_noinfo
0x140006d30  mov     r10d, ebx
0x140006d33  mov     eax, r10d
0x140006d36  mov     rbx, [rsp+28h+arg_0]
0x140006d3b  add     rsp, 20h
0x140006d3f  pop     rdi
0x140006d40  retn
0x140006d41  test    rcx, rcx
0x140006d44  jz      short loc_140006D1F
0x140006d46  test    rdx, rdx
0x140006d49  jz      short loc_140006D1F
0x140006d4b  test    r9, r9
0x140006d4e  jnz     short loc_140006D56
0x140006d50  mov     [rcx], r10w
0x140006d54  jmp     short loc_140006D33
0x140006d56  test    r8, r8
0x140006d59  jnz     short loc_140006D61
0x140006d5b  mov     [rcx], r10w
0x140006d5f  jmp     short loc_140006D1F
0x140006d61  sub     r8, rcx
0x140006d64  mov     rdx, rcx
0x140006d67  mov     rbx, r11
0x140006d6a  mov     rdi, r9
0x140006d6d  cmp     r9, 0FFFFFFFFFFFFFFFFh
0x140006d71  jnz     short loc_140006D8C
0x140006d73  movzx   eax, word ptr [r8+rdx]
0x140006d78  mov     [rdx], ax
0x140006d7b  lea     rdx, [rdx+2]
0x140006d7f  test    ax, ax
0x140006d82  jz      short loc_140006DB2
0x140006d84  sub     rbx, 1
0x140006d88  jnz     short loc_140006D73
0x140006d8a  jmp     short loc_140006DB2
0x140006d8c  movzx   eax, word ptr [r8+rdx]
0x140006d91  mov     [rdx], ax
0x140006d94  lea     rdx, [rdx+2]
0x140006d98  test    ax, ax
0x140006d9b  jz      short loc_140006DA9
0x140006d9d  sub     rbx, 1
0x140006da1  jz      short loc_140006DA9
0x140006da3  sub     rdi, 1
0x140006da7  jnz     short loc_140006D8C
0x140006da9  test    rdi, rdi
0x140006dac  jnz     short loc_140006DB2
0x140006dae  mov     [rdx], r10w
0x140006db2  test    rbx, rbx
0x140006db5  jnz     loc_140006D33
0x140006dbb  cmp     r9, 0FFFFFFFFFFFFFFFFh
0x140006dbf  jnz     short loc_140006DD0
0x140006dc1  mov     [rcx+r11*2-2], r10w
0x140006dc7  lea     r10d, [rbx+50h]
0x140006dcb  jmp     loc_140006D33
0x140006dd0  mov     [rcx], r10w
0x140006dd4  call    _errno
0x140006dd9  mov     ebx, 22h ; '"'
0x140006dde  jmp     loc_140006D29

// ===== ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z @ 0x140006de4 =====

0x140006de4  mov     [rsp+arg_0], rbx
0x140006de9  push    rdi
0x140006dea  sub     rsp, 20h
0x140006dee  mov     byte ptr [rcx+18h], 0
0x140006df2  mov     rdi, rcx
0x140006df5  test    rdx, rdx
0x140006df8  jz      short loc_140006DFF
0x140006dfa  movups  xmm0, xmmword ptr [rdx]
0x140006dfd  jmp     short loc_140006E10
0x140006dff  mov     eax, cs:dword_140021774
0x140006e05  test    eax, eax
0x140006e07  jnz     short loc_140006E17
0x140006e09  movups  xmm0, xmmword ptr cs:off_140020418
0x140006e10  movdqu  xmmword ptr [rcx+8], xmm0
0x140006e15  jmp     short loc_140006E66
0x140006e17  call    __acrt_getptd
0x140006e1c  mov     [rdi], rax
0x140006e1f  lea     rdx, [rdi+8]
0x140006e23  mov     rcx, [rax+90h]
0x140006e2a  mov     [rdx], rcx
0x140006e2d  mov     rcx, [rax+88h]
0x140006e34  mov     [rdi+10h], rcx
0x140006e38  mov     rcx, rax
0x140006e3b  call    sub_14000AB8C
0x140006e40  mov     rcx, [rdi]
0x140006e43  lea     rdx, [rdi+10h]
0x140006e47  call    sub_14000ABC0
0x140006e4c  mov     rcx, [rdi]
0x140006e4f  mov     eax, [rcx+3A8h]
0x140006e55  test    al, 2
0x140006e57  jnz     short loc_140006E66
0x140006e59  or      eax, 2
0x140006e5c  mov     [rcx+3A8h], eax
0x140006e62  mov     byte ptr [rdi+18h], 1
0x140006e66  mov     rax, rdi
0x140006e69  mov     rbx, [rsp+28h+arg_0]
0x140006e6e  add     rsp, 20h
0x140006e72  pop     rdi
0x140006e73  retn

// ===== _wcsicmp @ 0x140006e74 =====

0x140006e74  sub     rsp, 28h
0x140006e78  mov     eax, cs:dword_140021774
0x140006e7e  mov     r9, rdx
0x140006e81  mov     r10, rcx
0x140006e84  xor     r8d, r8d; Locale
0x140006e87  test    eax, eax
0x140006e89  jnz     short loc_140006EF0
0x140006e8b  test    rcx, rcx
0x140006e8e  jnz     short loc_140006EAA
0x140006e90  call    _errno
0x140006e95  mov     dword ptr [rax], 16h
0x140006e9b  call    _invalid_parameter_noinfo
0x140006ea0  mov     eax, 7FFFFFFFh
0x140006ea5  add     rsp, 28h
0x140006ea9  retn
0x140006eaa  test    rdx, rdx
0x140006ead  jz      short loc_140006E90
0x140006eaf  sub     r10, rdx
0x140006eb2  movzx   edx, word ptr [r10+r9]
0x140006eb7  lea     eax, [rdx-41h]
0x140006eba  cmp     ax, 19h
0x140006ebe  ja      short loc_140006EC4
0x140006ec0  add     dx, 20h ; ' '; String2
0x140006ec4  movzx   ecx, word ptr [r9]
0x140006ec8  lea     eax, [rcx-41h]
0x140006ecb  cmp     ax, 19h
0x140006ecf  ja      short loc_140006ED5
0x140006ed1  add     cx, 20h ; ' '
0x140006ed5  add     r9, 2
0x140006ed9  test    dx, dx
0x140006edc  jz      short loc_140006EE3
0x140006ede  cmp     dx, cx
0x140006ee1  jz      short loc_140006EB2
0x140006ee3  movzx   ecx, cx; String1
0x140006ee6  movzx   eax, dx
0x140006ee9  sub     eax, ecx
0x140006eeb  add     rsp, 28h
0x140006eef  retn
0x140006ef0  add     rsp, 28h
0x140006ef4  jmp     _wcsicmp_l

// ===== _wcsicmp_l @ 0x140006efc =====

0x140006efc  mov     rax, rsp
0x140006eff  mov     [rax+8], rbx
0x140006f03  mov     [rax+10h], rbp
0x140006f07  mov     [rax+18h], rsi
0x140006f0b  push    rdi
0x140006f0c  sub     rsp, 40h
0x140006f10  mov     rdi, rdx
0x140006f13  mov     rsi, rcx
0x140006f16  mov     rdx, r8; struct __crt_locale_pointers *
0x140006f19  lea     rcx, [rax-28h]; this
0x140006f1d  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x140006f22  xor     ebp, ebp
0x140006f24  test    rsi, rsi
0x140006f27  jz      short loc_140006F2E
0x140006f29  test    rdi, rdi
0x140006f2c  jnz     short loc_140006F45
0x140006f2e  call    _errno
0x140006f33  mov     dword ptr [rax], 16h
0x140006f39  call    _invalid_parameter_noinfo
0x140006f3e  mov     eax, 7FFFFFFFh
0x140006f43  jmp     short loc_140006FC1
0x140006f45  mov     rax, [rsp+48h+Locale.locinfo]
0x140006f4a  cmp     [rax+138h], rbp
0x140006f51  jnz     short loc_140006F87
0x140006f53  sub     rsi, rdi
0x140006f56  movzx   ebx, word ptr [rsi+rdi]
0x140006f5a  lea     eax, [rbx-41h]
0x140006f5d  cmp     ax, 19h
0x140006f61  ja      short loc_140006F67
0x140006f63  add     bx, 20h ; ' '
0x140006f67  movzx   ecx, word ptr [rdi]
0x140006f6a  lea     eax, [rcx-41h]
0x140006f6d  cmp     ax, 19h
0x140006f71  ja      short loc_140006F77
0x140006f73  add     cx, 20h ; ' '
0x140006f77  add     rdi, 2
0x140006f7b  test    bx, bx
0x140006f7e  jz      short loc_140006FB9
0x140006f80  cmp     bx, cx
0x140006f83  jz      short loc_140006F56
0x140006f85  jmp     short loc_140006FB9
0x140006f87  movzx   ecx, word ptr [rsi]; C
0x140006f8a  lea     rdx, [rsp+48h+Locale]; Locale
0x140006f8f  call    _towlower_l
0x140006f94  movzx   ecx, word ptr [rdi]; C
0x140006f97  lea     rdx, [rsp+48h+Locale]; Locale
0x140006f9c  movzx   ebx, ax
0x140006f9f  lea     rsi, [rsi+2]
0x140006fa3  call    _towlower_l
0x140006fa8  lea     rdi, [rdi+2]
0x140006fac  movzx   ecx, ax
0x140006faf  test    bx, bx
0x140006fb2  jz      short loc_140006FB9
0x140006fb4  cmp     bx, ax
0x140006fb7  jz      short loc_140006F87
0x140006fb9  movzx   ecx, cx
0x140006fbc  movzx   eax, bx
0x140006fbf  sub     eax, ecx
0x140006fc1  cmp     [rsp+48h+var_10], bpl
0x140006fc6  jz      short loc_140006FD4
0x140006fc8  mov     rcx, [rsp+48h+var_28]
0x140006fcd  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x140006fd4  mov     rbx, [rsp+48h+arg_0]
0x140006fd9  mov     rbp, [rsp+48h+arg_8]
0x140006fde  mov     rsi, [rsp+48h+arg_10]
0x140006fe3  add     rsp, 40h
0x140006fe7  pop     rdi
0x140006fe8  retn

// ===== sub_140006FEC @ 0x140006fec =====

0x140006fec  mov     [rsp-8+arg_0], rbx
0x140006ff1  mov     [rsp-8+arg_18], rsi
0x140006ff6  push    rbp
0x140006ff7  push    rdi
0x140006ff8  push    r12
0x140006ffa  push    r14
0x140006ffc  push    r15
0x140006ffe  lea     rbp, [rsp-410h]
0x140007006  sub     rsp, 510h
0x14000700d  mov     rax, cs:__security_cookie
0x140007014  xor     rax, rsp
0x140007017  mov     [rbp+430h+var_30], rax
0x14000701e  xor     r12d, r12d
0x140007021  mov     rbx, r9
0x140007024  mov     rdi, r8
0x140007027  mov     rsi, rdx
0x14000702a  mov     r15, rcx
0x14000702d  test    r9, r9
0x140007030  jnz     short loc_14000704A
0x140007032  call    _errno
0x140007037  mov     dword ptr [rax], 16h
0x14000703d  call    _invalid_parameter_noinfo
0x140007042  or      eax, 0FFFFFFFFh
0x140007045  jmp     loc_140007154
0x14000704a  test    r8, r8
0x14000704d  jz      short loc_140007054
0x14000704f  test    rdx, rdx
0x140007052  jz      short loc_140007032
0x140007054  mov     rdx, [rbp+430h+arg_20]; struct __crt_locale_pointers *
0x14000705b  lea     rcx, [rsp+530h+var_4D8]; this
0x140007060  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z; _LocaleUpdate::_LocaleUpdate(__crt_locale_pointers * const)
0x140007065  xor     edx, edx
0x140007067  lea     rcx, [rsp+530h+var_500]
0x14000706c  lea     r8d, [rdx+20h]
0x140007070  call    sub_140005B30
0x140007075  mov     r14, r15
0x140007078  mov     [rsp+530h+var_500], rsi
0x14000707d  mov     [rsp+530h+var_4F8], rdi
0x140007082  mov     [rsp+530h+var_4F0], r12
0x140007087  and     r14d, 2
0x14000708b  jnz     short loc_140007097
0x14000708d  mov     [rsp+530h+var_4E8], r12b
0x140007092  test    rsi, rsi
0x140007095  jnz     short loc_14000709C
0x140007097  mov     [rsp+530h+var_4E8], 1
0x14000709c  lea     rax, [rsp+530h+var_500]
0x1400070a1  mov     r9, rbx
0x1400070a4  mov     [rsp+530h+var_4E0], rax
0x1400070a9  lea     rdx, [rsp+530h+var_4E0]
0x1400070ae  mov     rax, [rbp+430h+arg_28]
0x1400070b5  lea     rcx, [rbp+430h+var_4B0]
0x1400070b9  mov     [rsp+530h+var_508], rax
0x1400070be  mov     r8, r15
0x1400070c1  lea     rax, [rsp+530h+var_4D0]
0x1400070c6  mov     [rsp+530h+var_510], rax
0x1400070cb  call    unknown_libname_7; Microsoft VisualC 64bit universal runtime
0x1400070d0  lea     rcx, [rbp+430h+var_4B0]
0x1400070d4  call    ?process@?$output_processor@_WV?$string_output_adapter@_W@__crt_stdio_output@@V?$format_validation_base@_WV?$string_output_adapter@_W@__crt_stdio_output@@@2@@__crt_stdio_output@@QEAAHXZ; __crt_stdio_output::output_processor<wchar_t,__crt_stdio_output::string_output_adapter<wchar_t>,__crt_stdio_output::format_validation_base<wchar_t,__crt_stdio_output::string_output_adapter<wchar_t>>>::process(void)
0x1400070d9  movsxd  rbx, eax
0x1400070dc  test    rsi, rsi
0x1400070df  jz      short loc_14000712C
0x1400070e1  test    r15b, 1
0x1400070e5  jz      short loc_140007109
0x1400070e7  test    rdi, rdi
0x1400070ea  jnz     short loc_1400070F4
0x1400070ec  test    eax, eax
0x1400070ee  jnz     loc_140007184
0x1400070f4  mov     rax, [rsp+530h+var_4F0]
0x1400070f9  cmp     rax, rdi
0x1400070fc  jnz     short loc_140007127
0x1400070fe  test    ebx, ebx
0x140007100  js      short loc_14000712C
0x140007102  cmp     rbx, rdi
0x140007105  jbe     short loc_14000712C
0x140007107  jmp     short loc_140007184
0x140007109  test    r14, r14
0x14000710c  jz      short loc_14000717F
0x14000710e  test    rdi, rdi
0x140007111  jz      short loc_14000712C
0x140007113  test    eax, eax
0x140007115  jns     short loc_14000711D
0x140007117  mov     [rsi], r12w
0x14000711b  jmp     short loc_14000712C
0x14000711d  mov     rax, [rsp+530h+var_4F0]
0x140007122  cmp     rax, rdi
0x140007125  jz      short loc_140007198
0x140007127  mov     [rsi+rax*2], r12w
0x14000712c  mov     rcx, [rbp+430h+Block]; Block
0x140007133  call    _free_base
0x140007138  mov     [rbp+430h+Block], r12
0x14000713f  cmp     [rsp+530h+var_4C0], r12b
0x140007144  jz      short loc_140007152
0x140007146  mov     rcx, [rsp+530h+var_4D8]
0x14000714b  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x140007152  mov     eax, ebx
0x140007154  mov     rcx, [rbp+430h+var_30]
0x14000715b  xor     rcx, rsp; StackCookie
0x14000715e  call    __security_check_cookie
0x140007163  lea     r11, [rsp+530h+var_20]
0x14000716b  mov     rbx, [r11+30h]
0x14000716f  mov     rsi, [r11+48h]
0x140007173  mov     rsp, r11
0x140007176  pop     r15
0x140007178  pop     r14
0x14000717a  pop     r12
0x14000717c  pop     rdi
0x14000717d  pop     rbp
0x14000717e  retn
0x14000717f  test    rdi, rdi
0x140007182  jnz     short loc_140007189
0x140007184  or      ebx, 0FFFFFFFFh
0x140007187  jmp     short loc_14000712C
0x140007189  mov     rax, [rsp+530h+var_4F0]
0x14000718e  cmp     rax, rdi
0x140007191  jnz     short loc_140007127
0x140007193  mov     ebx, 0FFFFFFFEh
0x140007198  mov     [rsi+rdi*2-2], r12w
0x14000719e  jmp     short loc_14000712C

// ===== ??$ensure_buffer_is_big_enough@D@formatting_buffer@__crt_stdio_output@@QEAA_N_K@Z @ 0x1400071a0 =====

0x1400071a0  mov     [rsp+arg_0], rbx
0x1400071a5  mov     [rsp+arg_8], rbp
0x1400071aa  mov     [rsp+arg_10], rsi
0x1400071af  push    rdi
0x1400071b0  sub     rsp, 20h
0x1400071b4  or      rax, 0FFFFFFFFFFFFFFFFh
0x1400071b8  mov     rsi, rdx
0x1400071bb  xor     edx, edx
0x1400071bd  mov     rbp, rcx
0x1400071c0  div     rsi
0x1400071c3  and     rax, 0FFFFFFFFFFFFFFFEh
0x1400071c7  cmp     rax, 2
0x1400071cb  jnb     short loc_1400071DC
0x1400071cd  call    _errno
0x1400071d2  mov     dword ptr [rax], 0Ch
0x1400071d8  xor     al, al
0x1400071da  jmp     short loc_140007237
0x1400071dc  add     rsi, rsi
0x1400071df  xor     edi, edi
0x1400071e1  cmp     [rcx+408h], rdi
0x1400071e8  jnz     short loc_1400071F7
0x1400071ea  cmp     rsi, 400h
0x1400071f1  ja      short loc_1400071F7
0x1400071f3  mov     al, 1
0x1400071f5  jmp     short loc_140007237
0x1400071f7  cmp     rsi, [rcx+400h]
0x1400071fe  jbe     short loc_1400071F3
0x140007200  mov     rcx, rsi; Size
0x140007203  call    _malloc_base
0x140007208  mov     rbx, rax
0x14000720b  test    rax, rax
0x14000720e  jz      short loc_14000722D
0x140007210  mov     rcx, [rbp+408h]; Block
0x140007217  call    _free_base
0x14000721c  mov     [rbp+408h], rbx
0x140007223  mov     dil, 1
0x140007226  mov     [rbp+400h], rsi
0x14000722d  xor     ecx, ecx; Block
0x14000722f  call    _free_base
0x140007234  mov     al, dil
0x140007237  mov     rbx, [rsp+28h+arg_0]
0x14000723c  mov     rbp, [rsp+28h+arg_8]
0x140007241  mov     rsi, [rsp+28h+arg_10]
0x140007246  add     rsp, 20h
0x14000724a  pop     rdi
0x14000724b  retn

// ===== ??$is_wide_character_specifier@_W@__crt_stdio_output@@YA_N_K_WW4length_modifier@0@@Z @ 0x14000724c =====

0x14000724c  mov     r9d, r8d
0x14000724f  mov     r10, rcx
0x140007252  sub     r9d, 2
0x140007256  jz      short loc_14000728D
0x140007258  sub     r9d, 1
0x14000725c  jz      short loc_14000728A
0x14000725e  cmp     r9d, 9
0x140007262  jz      short loc_14000728A
0x140007264  cmp     r8d, 0Dh
0x140007268  jz      short loc_14000728A
0x14000726a  shr     r10b, 2
0x14000726e  sub     dx, 63h ; 'c'
0x140007272  and     r10b, 1
0x140007276  mov     eax, 0FFEFh
0x14000727b  test    ax, dx
0x14000727e  setz    cl
0x140007281  xor     eax, eax
0x140007283  cmp     r10b, cl
0x140007286  setz    al
0x140007289  retn
0x14000728a  mov     al, 1
0x14000728c  retn
0x14000728d  xor     al, al
0x14000728f  retn

// ===== unknown_libname_5 @ 0x140007290 =====

0x140007290  mov     [rsp+arg_0], rbx
0x140007295  lea     rax, [rcx+58h]
0x140007299  mov     r10, rcx
0x14000729c  mov     rcx, [rax+408h]
0x1400072a3  mov     ebx, r8d
0x1400072a6  test    rcx, rcx
0x1400072a9  mov     r11d, edx
0x1400072ac  cmovz   rcx, rax
0x1400072b0  cmp     qword ptr [rax+408h], 0
0x1400072b8  jnz     short loc_1400072C1
0x1400072ba  mov     eax, 200h
0x1400072bf  jmp     short loc_1400072CB
0x1400072c1  mov     rax, [rax+400h]
0x1400072c8  shr     rax, 1
0x1400072cb  lea     r8, [rcx-1]
0x1400072cf  add     r8, rax
0x1400072d2  mov     [r10+48h], r8
0x1400072d6  mov     eax, [r10+38h]
0x1400072da  test    eax, eax
0x1400072dc  jg      short loc_1400072E3
0x1400072de  test    r11d, r11d
0x1400072e1  jz      short loc_140007319
0x1400072e3  dec     eax
0x1400072e5  xor     edx, edx
0x1400072e7  mov     [r10+38h], eax
0x1400072eb  mov     eax, r11d
0x1400072ee  div     ebx
0x1400072f0  add     dl, 30h ; '0'
0x1400072f3  mov     r11d, eax
0x1400072f6  cmp     dl, 39h ; '9'
0x1400072f9  jle     short loc_14000730D
0x1400072fb  mov     al, r9b
0x1400072fe  neg     al
0x140007300  sbb     cl, cl
0x140007302  and     cl, 0E0h
0x140007305  add     cl, 61h ; 'a'
0x140007308  sub     cl, 3Ah ; ':'
0x14000730b  add     dl, cl
0x14000730d  mov     rax, [r10+48h]
0x140007311  mov     [rax], dl
0x140007313  dec     qword ptr [r10+48h]
0x140007317  jmp     short loc_1400072D6
0x140007319  sub     r8d, [r10+48h]
0x14000731d  inc     qword ptr [r10+48h]
0x140007321  mov     rbx, [rsp+arg_0]
0x140007326  mov     [r10+50h], r8d
0x14000732a  retn

// ===== unknown_libname_6 @ 0x14000732c =====

0x14000732c  mov     [rsp+arg_0], rbx
0x140007331  lea     rax, [rcx+58h]
0x140007335  mov     ebx, r8d
0x140007338  mov     r10, rcx
0x14000733b  mov     r11, rdx
0x14000733e  mov     rcx, [rax+408h]
0x140007345  test    rcx, rcx
0x140007348  cmovz   rcx, rax
0x14000734c  cmp     qword ptr [rax+408h], 0
0x140007354  jnz     short loc_14000735D
0x140007356  mov     eax, 200h
0x14000735b  jmp     short loc_140007367
0x14000735d  mov     rax, [rax+400h]
0x140007364  shr     rax, 1
0x140007367  lea     r8, [rcx-1]
0x14000736b  add     r8, rax
0x14000736e  mov     [r10+48h], r8
0x140007372  mov     eax, [r10+38h]
0x140007376  test    eax, eax
0x140007378  jg      short loc_14000737F
0x14000737a  test    r11, r11
0x14000737d  jz      short loc_1400073B6
0x14000737f  dec     eax
0x140007381  xor     edx, edx
0x140007383  mov     [r10+38h], eax
0x140007387  mov     rax, r11
0x14000738a  div     rbx
0x14000738d  add     dl, 30h ; '0'
0x140007390  mov     r11, rax
0x140007393  cmp     dl, 39h ; '9'
0x140007396  jle     short loc_1400073AA
0x140007398  mov     al, r9b
0x14000739b  neg     al
0x14000739d  sbb     cl, cl
0x14000739f  and     cl, 0E0h
0x1400073a2  add     cl, 61h ; 'a'
0x1400073a5  sub     cl, 3Ah ; ':'
0x1400073a8  add     dl, cl
0x1400073aa  mov     rax, [r10+48h]
0x1400073ae  mov     [rax], dl
0x1400073b0  dec     qword ptr [r10+48h]
0x1400073b4  jmp     short loc_140007372
0x1400073b6  sub     r8d, [r10+48h]
0x1400073ba  inc     qword ptr [r10+48h]
0x1400073be  mov     rbx, [rsp+arg_0]
0x1400073c3  mov     [r10+50h], r8d
0x1400073c7  retn

// ===== ??$write_multiple_characters@V?$string_output_adapter@_W@__crt_stdio_output@@D@__crt_stdio_output@@YAXAEBV?$string_output_adapter@_W@0@DHQEAH@Z @ 0x1400073c8 =====

0x1400073c8  test    r8d, r8d
0x1400073cb  jle     short locret_140007435
0x1400073cd  mov     [rsp+arg_0], rbx
0x1400073d2  mov     [rsp+arg_8], rdi
0x1400073d7  mov     dil, dl
0x1400073da  mov     rbx, rcx
0x1400073dd  xor     r11d, r11d
0x1400073e0  mov     r10, [rbx]
0x1400073e3  mov     rax, [r10+8]
0x1400073e7  cmp     [r10+10h], rax
0x1400073eb  jnz     short loc_1400073FF
0x1400073ed  cmp     byte ptr [r10+18h], 0
0x1400073f2  jz      short loc_1400073F9
0x1400073f4  inc     dword ptr [r9]
0x1400073f7  jmp     short loc_14000741D
0x1400073f9  or      dword ptr [r9], 0FFFFFFFFh
0x1400073fd  jmp     short loc_14000741D
0x1400073ff  inc     dword ptr [r9]
0x140007402  mov     rax, [rbx]
0x140007405  movsx   edx, dil
0x140007409  inc     qword ptr [rax+10h]
0x14000740d  mov     rax, [rbx]
0x140007410  mov     rcx, [rax]
0x140007413  mov     [rcx], dx
0x140007416  mov     rax, [rbx]
0x140007419  add     qword ptr [rax], 2
0x14000741d  cmp     dword ptr [r9], 0FFFFFFFFh
0x140007421  jz      short loc_14000742B
0x140007423  inc     r11d
0x140007426  cmp     r11d, r8d
0x140007429  jl      short loc_1400073E0
0x14000742b  mov     rbx, [rsp+arg_0]
0x140007430  mov     rdi, [rsp+arg_8]
0x140007435  retn

// ===== unknown_libname_7 @ 0x140007438 =====

0x140007438  push    rbx
0x14000743a  sub     rsp, 20h
0x14000743e  mov     rbx, rcx
0x140007441  xor     ecx, ecx
0x140007443  mov     [rbx], rcx
0x140007446  mov     [rbx+8], rcx
0x14000744a  mov     [rbx+18h], rcx
0x14000744e  mov     [rbx+20h], rcx
0x140007452  mov     [rbx+10h], rcx
0x140007456  mov     [rbx+28h], rcx
0x14000745a  mov     [rbx+30h], rcx
0x14000745e  mov     [rbx+38h], ecx
0x140007461  mov     [rbx+40h], cl
0x140007464  mov     [rbx+42h], cx
0x140007468  mov     [rbx+50h], ecx
0x14000746b  mov     [rbx+54h], cl
0x14000746e  mov     [rbx+458h], rcx
0x140007475  mov     [rbx+460h], rcx
0x14000747c  mov     rax, [rdx]
0x14000747f  mov     [rbx+468h], rax
0x140007486  mov     rax, [rsp+28h+arg_20]
0x14000748b  mov     [rbx+8], rax
0x14000748f  mov     rax, [rsp+28h+arg_28]
0x140007494  mov     [rbx+20h], rax
0x140007498  mov     [rbx], r8
0x14000749b  mov     [rbx+18h], r9
0x14000749f  mov     [rbx+470h], ecx
0x1400074a5  call    _errno
0x1400074aa  mov     [rbx+10h], rax
0x1400074ae  mov     rax, rbx
0x1400074b1  add     rsp, 20h
0x1400074b5  pop     rbx
0x1400074b6  retn

// ===== ?force_decimal_point@__crt_stdio_output@@YAXPEADQEAU__crt_locale_pointers@@@Z @ 0x1400074b8 =====

0x1400074b8  mov     [rsp+arg_0], rbx
0x1400074bd  push    rdi
0x1400074be  sub     rsp, 20h
0x1400074c2  mov     rbx, rcx
0x1400074c5  mov     rdi, rdx
0x1400074c8  movsx   ecx, byte ptr [rcx]; C
0x1400074cb  call    tolower
0x1400074d0  cmp     eax, 65h ; 'e'
0x1400074d3  jz      short loc_1400074E4
0x1400074d5  inc     rbx
0x1400074d8  movzx   ecx, byte ptr [rbx]; C
0x1400074db  call    isdigit
0x1400074e0  test    eax, eax
0x1400074e2  jnz     short loc_1400074D5
0x1400074e4  movsx   ecx, byte ptr [rbx]; C
0x1400074e7  call    tolower
0x1400074ec  cmp     eax, 78h ; 'x'
0x1400074ef  jnz     short loc_1400074F5
0x1400074f1  add     rbx, 2
0x1400074f5  mov     rax, [rdi]
0x1400074f8  mov     dl, [rbx]
0x1400074fa  mov     rcx, [rax+0F8h]
0x140007501  mov     rax, [rcx]
0x140007504  mov     cl, [rax]
0x140007506  mov     [rbx], cl
0x140007508  inc     rbx
0x14000750b  mov     al, [rbx]
0x14000750d  mov     [rbx], dl
0x14000750f  mov     dl, al
0x140007511  mov     al, [rbx]
0x140007513  inc     rbx
0x140007516  test    al, al
0x140007518  jnz     short loc_14000750B
0x14000751a  mov     rbx, [rsp+28h+arg_0]
0x14000751f  add     rsp, 20h
0x140007523  pop     rdi
0x140007524  retn

// ===== unknown_libname_8 @ 0x140007528 =====

0x140007528  mov     rax, rsp
0x14000752b  mov     [rax+10h], rbx
0x14000752f  mov     [rax+18h], rbp
0x140007533  mov     [rax+20h], rsi
0x140007537  push    rdi
0x140007538  sub     rsp, 20h
0x14000753c  mov     rsi, [rcx+10h]
0x140007540  mov     rdi, rcx
0x140007543  mov     rbx, rdx
0x140007546  mov     r8d, 0Ah; Radix
0x14000754c  lea     rdx, [rax+8]; EndPtr
0x140007550  mov     ebp, [rsi]
0x140007552  and     dword ptr [rsi], 0
0x140007555  mov     rcx, [rcx+18h]
0x140007559  and     qword ptr [rax+8], 0
0x14000755e  sub     rcx, 2; String
0x140007562  call    wcstol
0x140007567  mov     [rbx], eax
0x140007569  mov     rax, [rdi+10h]
0x14000756d  cmp     dword ptr [rax], 22h ; '"'
0x140007570  jz      short loc_140007585
0x140007572  mov     rax, [rsp+28h+arg_0]
0x140007577  cmp     rax, [rdi+18h]
0x14000757b  jb      short loc_140007585
0x14000757d  mov     [rdi+18h], rax
0x140007581  mov     al, 1
0x140007583  jmp     short loc_140007587
0x140007585  xor     al, al
0x140007587  cmp     dword ptr [rsi], 0
0x14000758a  jnz     short loc_140007592
0x14000758c  test    ebp, ebp
0x14000758e  jz      short loc_140007592
0x140007590  mov     [rsi], ebp
0x140007592  mov     rbx, [rsp+28h+arg_8]
0x140007597  mov     rbp, [rsp+28h+arg_10]
0x14000759c  mov     rsi, [rsp+28h+arg_18]
0x1400075a1  add     rsp, 20h
0x1400075a5  pop     rdi
0x1400075a6  retn

// ===== ?process@?$output_processor@_WV?$string_output_adapter@_W@__crt_stdio_output@@V?$format_validation_base@_WV?$string_output_adapter@_W@__crt_stdio_output@@@2@@__crt_stdio_output@@QEAAHXZ @ 0x1400075a8 =====

0x1400075a8  mov     rax, rsp
0x1400075ab  mov     [rax+8], rbx
0x1400075af  mov     [rax+10h], rbp
0x1400075b3  mov     [rax+18h], rsi
0x1400075b7  mov     [rax+20h], rdi
0x1400075bb  push    r14
0x1400075bd  sub     rsp, 20h
0x1400075c1  xor     esi, esi
0x1400075c3  mov     rbx, rcx
0x1400075c6  cmp     [rcx+468h], rsi
0x1400075cd  jnz     short loc_1400075E7
0x1400075cf  call    _errno
0x1400075d4  mov     dword ptr [rax], 16h
0x1400075da  call    _invalid_parameter_noinfo
0x1400075df  or      eax, 0FFFFFFFFh
0x1400075e2  jmp     loc_1400077FF
0x1400075e7  cmp     [rcx+18h], rsi
0x1400075eb  jz      short loc_1400075CF
0x1400075ed  inc     dword ptr [rcx+470h]
0x1400075f3  cmp     dword ptr [rcx+470h], 2
0x1400075fa  jz      loc_1400077FC
0x140007600  or      edi, 0FFFFFFFFh
0x140007603  lea     r14, byte_140015840
0x14000760a  lea     ebp, [rdi+21h]
0x14000760d  mov     [rbx+50h], esi
0x140007610  mov     [rbx+2Ch], esi
0x140007613  jmp     loc_1400077C5
0x140007618  add     qword ptr [rbx+18h], 2
0x14000761d  cmp     [rbx+28h], esi
0x140007620  jl      loc_1400077DE
0x140007626  movzx   eax, word ptr [rbx+42h]
0x14000762a  mov     edx, [rbx+2Ch]
0x14000762d  sub     ax, bp
0x140007630  cmp     ax, 5Ah ; 'Z'
0x140007634  ja      short loc_140007645
0x140007636  movzx   eax, word ptr [rbx+42h]
0x14000763a  movzx   ecx, byte ptr [rax+r14-20h]
0x140007640  and     ecx, 0Fh
0x140007643  jmp     short loc_140007647
0x140007645  mov     ecx, esi
0x140007647  lea     eax, [rdx+rcx*8]
0x14000764a  add     ecx, eax
0x14000764c  movzx   ecx, byte ptr [rcx+r14]
0x140007651  shr     ecx, 4
0x140007654  mov     [rbx+2Ch], ecx
0x140007657  cmp     ecx, 8
0x14000765a  jz      loc_14000781A
0x140007660  test    ecx, ecx
0x140007662  jz      loc_140007770
0x140007668  sub     ecx, 1
0x14000766b  jz      loc_14000775C
0x140007671  sub     ecx, 1
0x140007674  jz      loc_14000771C
0x14000767a  sub     ecx, 1
0x14000767d  jz      short loc_1400076EA
0x14000767f  sub     ecx, 1
0x140007682  jz      short loc_1400076E2
0x140007684  sub     ecx, 1
0x140007687  jz      short loc_1400076B1
0x140007689  sub     ecx, 1
0x14000768c  jz      short loc_1400076A4
0x14000768e  cmp     ecx, 1
0x140007691  jnz     loc_14000782A
0x140007697  mov     rcx, rbx
0x14000769a  call    sub_1400079D4
0x14000769f  jmp     loc_1400077C1
0x1400076a4  mov     rcx, rbx
0x1400076a7  call    sub_140007830
0x1400076ac  jmp     loc_1400077C1
0x1400076b1  cmp     word ptr [rbx+42h], 2Ah ; '*'
0x1400076b6  jz      short loc_1400076C9
0x1400076b8  lea     rdx, [rbx+38h]
0x1400076bc  mov     rcx, rbx
0x1400076bf  call    unknown_libname_8; Microsoft VisualC 64bit universal runtime
0x1400076c4  jmp     loc_1400077C1
0x1400076c9  add     qword ptr [rbx+20h], 8
0x1400076ce  mov     rax, [rbx+20h]
0x1400076d2  mov     ecx, [rax-8]
0x1400076d5  test    ecx, ecx
0x1400076d7  cmovs   ecx, edi
0x1400076da  mov     [rbx+38h], ecx
0x1400076dd  jmp     loc_1400077BF
0x1400076e2  mov     [rbx+38h], esi
0x1400076e5  jmp     loc_1400077C5
0x1400076ea  cmp     word ptr [rbx+42h], 2Ah ; '*'
0x1400076ef  jz      short loc_1400076F7
0x1400076f1  lea     rdx, [rbx+34h]
0x1400076f5  jmp     short loc_1400076BC
0x1400076f7  add     qword ptr [rbx+20h], 8
0x1400076fc  mov     rax, [rbx+20h]
0x140007700  mov     ecx, [rax-8]
0x140007703  mov     [rbx+34h], ecx
0x140007706  test    ecx, ecx
0x140007708  jns     loc_1400077BF
0x14000770e  or      dword ptr [rbx+30h], 4
0x140007712  neg     ecx
0x140007714  mov     [rbx+34h], ecx
0x140007717  jmp     loc_1400077BF
0x14000771c  movzx   eax, word ptr [rbx+42h]
0x140007720  cmp     eax, ebp
0x140007722  jz      short loc_140007756
0x140007724  cmp     eax, 23h ; '#'
0x140007727  jz      short loc_140007751
0x140007729  cmp     eax, 2Bh ; '+'
0x14000772c  jz      short loc_14000774B
0x14000772e  cmp     eax, 2Dh ; '-'
0x140007731  jz      short loc_140007745
0x140007733  cmp     eax, 30h ; '0'
0x140007736  jnz     loc_1400077C5
0x14000773c  or      dword ptr [rbx+30h], 8
0x140007740  jmp     loc_1400077C5
0x140007745  or      dword ptr [rbx+30h], 4
0x140007749  jmp     short loc_1400077C5
0x14000774b  or      dword ptr [rbx+30h], 1
0x14000774f  jmp     short loc_1400077C5
0x140007751  or      [rbx+30h], ebp
0x140007754  jmp     short loc_1400077C5
0x140007756  or      dword ptr [rbx+30h], 2
0x14000775a  jmp     short loc_1400077C5
0x14000775c  mov     [rbx+30h], rsi
0x140007760  mov     [rbx+40h], sil
0x140007764  mov     [rbx+38h], edi
0x140007767  mov     [rbx+3Ch], esi
0x14000776a  mov     [rbx+54h], sil
0x14000776e  jmp     short loc_1400077C5
0x140007770  movzx   edx, word ptr [rbx+42h]
0x140007774  mov     byte ptr [rbx+54h], 1
0x140007778  mov     rcx, [rbx+468h]
0x14000777f  mov     rax, [rcx+8]
0x140007783  cmp     [rcx+10h], rax
0x140007787  jnz     short loc_140007799
0x140007789  cmp     [rcx+18h], sil
0x14000778d  jz      short loc_140007794
0x14000778f  inc     dword ptr [rbx+28h]
0x140007792  jmp     short loc_1400077BF
0x140007794  mov     [rbx+28h], edi
0x140007797  jmp     short loc_1400077BF
0x140007799  inc     dword ptr [rbx+28h]
0x14000779c  mov     rax, [rbx+468h]
0x1400077a3  inc     qword ptr [rax+10h]
0x1400077a7  mov     rax, [rbx+468h]
0x1400077ae  mov     rcx, [rax]
0x1400077b1  mov     [rcx], dx
0x1400077b4  mov     rax, [rbx+468h]
0x1400077bb  add     qword ptr [rax], 2
0x1400077bf  mov     al, 1
0x1400077c1  test    al, al
0x1400077c3  jz      short loc_14000782A
0x1400077c5  mov     rax, [rbx+18h]
0x1400077c9  movzx   ecx, word ptr [rax]
0x1400077cc  mov     [rbx+42h], cx
0x1400077d0  test    cx, cx
0x1400077d3  jnz     loc_140007618
0x1400077d9  add     qword ptr [rbx+18h], 2
0x1400077de  cmp     [rbx+2Ch], esi
0x1400077e1  jz      short loc_1400077E9
0x1400077e3  cmp     dword ptr [rbx+2Ch], 7
0x1400077e7  jnz     short loc_14000781A
0x1400077e9  inc     dword ptr [rbx+470h]
0x1400077ef  cmp     dword ptr [rbx+470h], 2
0x1400077f6  jnz     loc_14000760D
0x1400077fc  mov     eax, [rbx+28h]
0x1400077ff  mov     rbx, [rsp+28h+arg_0]
0x140007804  mov     rbp, [rsp+28h+arg_8]
0x140007809  mov     rsi, [rsp+28h+arg_10]
0x14000780e  mov     rdi, [rsp+28h+arg_18]
0x140007813  add     rsp, 20h
0x140007817  pop     r14
0x140007819  retn
0x14000781a  call    _errno
0x14000781f  mov     dword ptr [rax], 16h
0x140007825  call    _invalid_parameter_noinfo
0x14000782a  mov     eax, edi
0x14000782c  jmp     short loc_1400077FF

// ===== sub_140007830 @ 0x140007830 =====

0x140007830  sub     rsp, 28h
0x140007834  cmp     word ptr [rcx+42h], 46h ; 'F'
0x140007839  jnz     short loc_140007854
0x14000783b  test    byte ptr [rcx], 8
0x14000783e  jnz     loc_1400079CB
0x140007844  mov     dword ptr [rcx+2Ch], 7
0x14000784b  add     rsp, 28h
0x14000784f  jmp     sub_1400079D4
0x140007854  cmp     word ptr [rcx+42h], 4Eh ; 'N'
0x140007859  jnz     short loc_140007882
0x14000785b  test    byte ptr [rcx], 8
0x14000785e  jnz     loc_1400079CB
0x140007864  mov     dword ptr [rcx+2Ch], 8
0x14000786b  call    _errno
0x140007870  mov     dword ptr [rax], 16h
0x140007876  call    _invalid_parameter_noinfo
0x14000787b  xor     al, al
0x14000787d  jmp     loc_1400079CD
0x140007882  cmp     dword ptr [rcx+3Ch], 0
0x140007886  jnz     short loc_14000786B
0x140007888  movzx   eax, word ptr [rcx+42h]
0x14000788c  cmp     eax, 49h ; 'I'
0x14000788f  jz      loc_140007964
0x140007895  cmp     eax, 4Ch ; 'L'
0x140007898  jz      loc_14000795B
0x14000789e  cmp     eax, 54h ; 'T'
0x1400078a1  jz      loc_140007952
0x1400078a7  mov     edx, 68h ; 'h'
0x1400078ac  cmp     eax, edx
0x1400078ae  jz      short loc_14000792C
0x1400078b0  cmp     eax, 6Ah ; 'j'
0x1400078b3  jz      short loc_140007920
0x1400078b5  mov     edx, 6Ch ; 'l'
0x1400078ba  cmp     eax, edx
0x1400078bc  jz      short loc_1400078F7
0x1400078be  cmp     eax, 74h ; 't'
0x1400078c1  jz      short loc_1400078EB
0x1400078c3  cmp     eax, 77h ; 'w'
0x1400078c6  jz      short loc_1400078DF
0x1400078c8  cmp     eax, 7Ah ; 'z'
0x1400078cb  mov     al, 1
0x1400078cd  jnz     loc_1400079CD
0x1400078d3  mov     dword ptr [rcx+3Ch], 6
0x1400078da  jmp     loc_1400079CD
0x1400078df  mov     dword ptr [rcx+3Ch], 0Ch
0x1400078e6  jmp     loc_1400079CB
0x1400078eb  mov     dword ptr [rcx+3Ch], 7
0x1400078f2  jmp     loc_1400079CB
0x1400078f7  mov     rax, [rcx+18h]
0x1400078fb  cmp     [rax], dx
0x1400078fe  jnz     short loc_140007914
0x140007900  add     rax, 2
0x140007904  mov     dword ptr [rcx+3Ch], 4
0x14000790b  mov     [rcx+18h], rax
0x14000790f  jmp     loc_1400079CB
0x140007914  mov     dword ptr [rcx+3Ch], 3
0x14000791b  jmp     loc_1400079CB
0x140007920  mov     dword ptr [rcx+3Ch], 5
0x140007927  jmp     loc_1400079CB
0x14000792c  mov     rax, [rcx+18h]
0x140007930  cmp     [rax], dx
0x140007933  jnz     short loc_140007949
0x140007935  add     rax, 2
0x140007939  mov     dword ptr [rcx+3Ch], 1
0x140007940  mov     [rcx+18h], rax
0x140007944  jmp     loc_1400079CB
0x140007949  mov     dword ptr [rcx+3Ch], 2
0x140007950  jmp     short loc_1400079CB
0x140007952  mov     dword ptr [rcx+3Ch], 0Dh
0x140007959  jmp     short loc_1400079CB
0x14000795b  mov     dword ptr [rcx+3Ch], 8
0x140007962  jmp     short loc_1400079CB
0x140007964  mov     rdx, [rcx+18h]
0x140007968  movzx   eax, word ptr [rdx]
0x14000796b  cmp     ax, 33h ; '3'
0x14000796f  jnz     short loc_140007989
0x140007971  cmp     word ptr [rdx+2], 32h ; '2'
0x140007976  jnz     short loc_140007989
0x140007978  lea     rax, [rdx+4]
0x14000797c  mov     dword ptr [rcx+3Ch], 0Ah
0x140007983  mov     [rcx+18h], rax
0x140007987  jmp     short loc_1400079CB
0x140007989  cmp     ax, 36h ; '6'
0x14000798d  jnz     short loc_1400079A7
0x14000798f  cmp     word ptr [rdx+2], 34h ; '4'
0x140007994  jnz     short loc_1400079A7
0x140007996  lea     rax, [rdx+4]
0x14000799a  mov     dword ptr [rcx+3Ch], 0Bh
0x1400079a1  mov     [rcx+18h], rax
0x1400079a5  jmp     short loc_1400079CB
0x1400079a7  sub     ax, 58h ; 'X'
0x1400079ab  cmp     ax, 20h ; ' '
0x1400079af  ja      short loc_1400079CB
0x1400079b1  movzx   eax, ax
0x1400079b4  mov     rdx, 120821001h
0x1400079be  bt      rdx, rax
0x1400079c2  jnb     short loc_1400079CB
0x1400079c4  mov     dword ptr [rcx+3Ch], 9
0x1400079cb  mov     al, 1
0x1400079cd  add     rsp, 28h
0x1400079d1  retn

// ===== sub_1400079D4 @ 0x1400079d4 =====

0x1400079d4  mov     [rsp+arg_8], rbx
0x1400079d9  mov     [rsp+arg_10], rbp
0x1400079de  mov     [rsp+arg_18], rsi
0x1400079e3  push    rdi
0x1400079e4  push    r12
0x1400079e6  push    r13
0x1400079e8  push    r14
0x1400079ea  push    r15
0x1400079ec  sub     rsp, 40h
0x1400079f0  mov     rax, cs:__security_cookie
0x1400079f7  xor     rax, rsp
0x1400079fa  mov     [rsp+68h+var_30], rax
0x1400079ff  movzx   eax, word ptr [rcx+42h]
0x140007a03  mov     esi, 58h ; 'X'
0x140007a08  mov     rbx, rcx
0x140007a0b  lea     ebp, [rsi-17h]
0x140007a0e  lea     r15d, [rsi-57h]
0x140007a12  cmp     eax, 64h ; 'd'
0x140007a15  jg      short loc_140007A72
0x140007a17  jz      loc_140007AE3
0x140007a1d  cmp     eax, ebp
0x140007a1f  jz      loc_140007AF6
0x140007a25  cmp     eax, 43h ; 'C'
0x140007a28  jz      short loc_140007A5C
0x140007a2a  cmp     eax, 44h ; 'D'
0x140007a2d  jle     loc_140007AFF
0x140007a33  cmp     eax, 47h ; 'G'
0x140007a36  jle     loc_140007AF6
0x140007a3c  cmp     eax, 53h ; 'S'
0x140007a3f  jz      short loc_140007A9F
0x140007a41  cmp     eax, esi
0x140007a43  jz      short loc_140007AB4
0x140007a45  cmp     eax, 5Ah ; 'Z'
0x140007a48  jz      short loc_140007A68
0x140007a4a  cmp     eax, 61h ; 'a'
0x140007a4d  jz      loc_140007AF6
0x140007a53  cmp     eax, 63h ; 'c'
0x140007a56  jnz     loc_140007AFF
0x140007a5c  xor     edx, edx
0x140007a5e  call    unknown_libname_11; Microsoft VisualC 64bit universal runtime
0x140007a63  jmp     loc_140007AFB
0x140007a68  call    unknown_libname_9; Microsoft VisualC 64bit universal runtime
0x140007a6d  jmp     loc_140007AFB
0x140007a72  cmp     eax, 67h ; 'g'
0x140007a75  jle     short loc_140007AF6
0x140007a77  cmp     eax, 69h ; 'i'
0x140007a7a  jz      short loc_140007AE3
0x140007a7c  cmp     eax, 6Eh ; 'n'
0x140007a7f  jz      short loc_140007ADC
0x140007a81  cmp     eax, 6Fh ; 'o'
0x140007a84  jz      short loc_140007ABE
0x140007a86  cmp     eax, 70h ; 'p'
0x140007a89  jz      short loc_140007AA6
0x140007a8b  cmp     eax, 73h ; 's'
0x140007a8e  jz      short loc_140007A9F
0x140007a90  cmp     eax, 75h ; 'u'
0x140007a93  jz      short loc_140007AE7
0x140007a95  cmp     eax, 78h ; 'x'
0x140007a98  jnz     short loc_140007AFF
0x140007a9a  lea     edx, [rax-68h]
0x140007a9d  jmp     short loc_140007AEC
0x140007a9f  call    unknown_libname_13; Microsoft VisualC 64bit universal runtime
0x140007aa4  jmp     short loc_140007AFB
0x140007aa6  mov     dword ptr [rcx+38h], 10h
0x140007aad  mov     dword ptr [rcx+3Ch], 0Bh
0x140007ab4  mov     r8b, r15b
0x140007ab7  mov     edx, 10h
0x140007abc  jmp     short loc_140007AEF
0x140007abe  mov     ecx, [rcx+30h]
0x140007ac1  mov     eax, ecx
0x140007ac3  shr     eax, 5
0x140007ac6  test    r15b, al
0x140007ac9  jz      short loc_140007AD2
0x140007acb  bts     ecx, 7
0x140007acf  mov     [rbx+30h], ecx
0x140007ad2  mov     edx, 8
0x140007ad7  mov     rcx, rbx
0x140007ada  jmp     short loc_140007AEC
0x140007adc  call    unknown_libname_12; Microsoft VisualC 64bit universal runtime
0x140007ae1  jmp     short loc_140007AFB
0x140007ae3  or      dword ptr [rcx+30h], 10h
0x140007ae7  mov     edx, 0Ah
0x140007aec  xor     r8d, r8d
0x140007aef  call    sub_14000800C
0x140007af4  jmp     short loc_140007AFB
0x140007af6  call    unknown_libname_10; Microsoft VisualC 64bit universal runtime
0x140007afb  test    al, al
0x140007afd  jnz     short loc_140007B06
0x140007aff  xor     al, al
0x140007b01  jmp     loc_140007C72
0x140007b06  cmp     byte ptr [rbx+40h], 0
0x140007b0a  jnz     loc_140007C6F
0x140007b10  mov     edx, [rbx+30h]
0x140007b13  xor     eax, eax
0x140007b15  mov     [rsp+68h+var_38], eax
0x140007b19  xor     edi, edi
0x140007b1b  mov     [rsp+68h+var_34], ax
0x140007b20  mov     eax, edx
0x140007b22  shr     eax, 4
0x140007b25  lea     r13d, [rdi+20h]
0x140007b29  test    r15b, al
0x140007b2c  jz      short loc_140007B60
0x140007b2e  mov     eax, edx
0x140007b30  shr     eax, 6
0x140007b33  test    r15b, al
0x140007b36  jz      short loc_140007B42
0x140007b38  lea     eax, [rdi+2Dh]
0x140007b3b  mov     word ptr [rsp+68h+var_38], ax
0x140007b40  jmp     short loc_140007B5D
0x140007b42  test    r15b, dl
0x140007b45  jz      short loc_140007B4E
0x140007b47  mov     eax, 2Bh ; '+'
0x140007b4c  jmp     short loc_140007B3B
0x140007b4e  mov     eax, edx
0x140007b50  shr     eax, 1
0x140007b52  test    r15b, al
0x140007b55  jz      short loc_140007B60
0x140007b57  mov     word ptr [rsp+68h+var_38], r13w
0x140007b5d  mov     rdi, r15
0x140007b60  movzx   ecx, word ptr [rbx+42h]
0x140007b64  mov     r9d, 0FFDFh
0x140007b6a  movzx   eax, cx
0x140007b6d  sub     ax, si
0x140007b70  test    r9w, ax
0x140007b74  jnz     short loc_140007B85
0x140007b76  mov     eax, edx
0x140007b78  shr     eax, 5
0x140007b7b  test    r15b, al
0x140007b7e  jz      short loc_140007B85
0x140007b80  mov     r8b, r15b
0x140007b83  jmp     short loc_140007B88
0x140007b85  xor     r8b, r8b
0x140007b88  movzx   eax, cx
0x140007b8b  mov     r12d, 30h ; '0'
0x140007b91  sub     ax, bp
0x140007b94  test    r9w, ax
0x140007b98  setz    al
0x140007b9b  test    r8b, r8b
0x140007b9e  jnz     short loc_140007BA4
0x140007ba0  test    al, al
0x140007ba2  jz      short loc_140007BD3
0x140007ba4  mov     word ptr [rsp+rdi*2+68h+var_38], r12w
0x140007baa  add     rdi, r15
0x140007bad  cmp     cx, si
0x140007bb0  jz      short loc_140007BBB
0x140007bb2  cmp     cx, bp
0x140007bb5  jz      short loc_140007BBB
0x140007bb7  xor     al, al
0x140007bb9  jmp     short loc_140007BBE
0x140007bbb  mov     al, r15b
0x140007bbe  neg     al
0x140007bc0  sbb     al, al
0x140007bc2  and     al, 0E0h
0x140007bc4  add     al, 61h ; 'a'
0x140007bc6  add     al, 17h
0x140007bc8  movsx   eax, al
0x140007bcb  mov     word ptr [rsp+rdi*2+68h+var_38], ax
0x140007bd0  add     rdi, r15
0x140007bd3  mov     esi, [rbx+34h]
0x140007bd6  sub     esi, [rbx+50h]
0x140007bd9  sub     esi, edi
0x140007bdb  test    dl, 0Ch
0x140007bde  jnz     short loc_140007BF6
0x140007be0  lea     r9, [rbx+28h]
0x140007be4  mov     r8d, esi
0x140007be7  lea     rcx, [rbx+468h]
0x140007bee  mov     dl, r13b
0x140007bf1  call    ??$write_multiple_characters@V?$string_output_adapter@_W@__crt_stdio_output@@D@__crt_stdio_output@@YAXAEBV?$string_output_adapter@_W@0@DHQEAH@Z; __crt_stdio_output::write_multiple_characters<__crt_stdio_output::string_output_adapter<wchar_t>,char>(__crt_stdio_output::string_output_adapter<wchar_t> const &,char,int,int * const)
0x140007bf6  mov     rax, [rbx+10h]
0x140007bfa  lea     rbp, [rbx+28h]
0x140007bfe  lea     r14, [rbx+468h]
0x140007c05  mov     [rsp+68h+var_48], rax
0x140007c0a  mov     r9, rbp
0x140007c0d  lea     rdx, [rsp+68h+var_38]
0x140007c12  mov     rcx, r14
0x140007c15  mov     r8d, edi
0x140007c18  call    ?write_string@?$string_output_adapter@_W@__crt_stdio_output@@QEBAXQEB_WHQEAH1@Z; __crt_stdio_output::string_output_adapter<wchar_t>::write_string(wchar_t const * const,int,int * const,int * const)
0x140007c1d  mov     ecx, [rbx+30h]
0x140007c20  mov     eax, ecx
0x140007c22  shr     eax, 3
0x140007c25  test    r15b, al
0x140007c28  jz      short loc_140007C43
0x140007c2a  shr     ecx, 2
0x140007c2d  test    r15b, cl
0x140007c30  jnz     short loc_140007C43
0x140007c32  mov     r9, rbp
0x140007c35  mov     r8d, esi
0x140007c38  mov     dl, r12b
0x140007c3b  mov     rcx, r14
0x140007c3e  call    ??$write_multiple_characters@V?$string_output_adapter@_W@__crt_stdio_output@@D@__crt_stdio_output@@YAXAEBV?$string_output_adapter@_W@0@DHQEAH@Z; __crt_stdio_output::write_multiple_characters<__crt_stdio_output::string_output_adapter<wchar_t>,char>(__crt_stdio_output::string_output_adapter<wchar_t> const &,char,int,int * const)
0x140007c43  xor     edx, edx
0x140007c45  mov     rcx, rbx
0x140007c48  call    unknown_libname_14; Microsoft VisualC 64bit universal runtime
0x140007c4d  cmp     dword ptr [rbp+0], 0
0x140007c51  jl      short loc_140007C6F
0x140007c53  mov     eax, [rbx+30h]
0x140007c56  shr     eax, 2
0x140007c59  test    r15b, al
0x140007c5c  jz      short loc_140007C6F
0x140007c5e  mov     r9, rbp
0x140007c61  mov     r8d, esi
0x140007c64  mov     dl, r13b
0x140007c67  mov     rcx, r14
0x140007c6a  call    ??$write_multiple_characters@V?$string_output_adapter@_W@__crt_stdio_output@@D@__crt_stdio_output@@YAXAEBV?$string_output_adapter@_W@0@DHQEAH@Z; __crt_stdio_output::write_multiple_characters<__crt_stdio_output::string_output_adapter<wchar_t>,char>(__crt_stdio_output::string_output_adapter<wchar_t> const &,char,int,int * const)
0x140007c6f  mov     al, r15b
0x140007c72  mov     rcx, [rsp+68h+var_30]
0x140007c77  xor     rcx, rsp; StackCookie
0x140007c7a  call    __security_check_cookie
0x140007c7f  lea     r11, [rsp+68h+var_28]
0x140007c84  mov     rbx, [r11+38h]
0x140007c88  mov     rbp, [r11+40h]
0x140007c8c  mov     rsi, [r11+48h]
0x140007c90  mov     rsp, r11
0x140007c93  pop     r15
0x140007c95  pop     r14
0x140007c97  pop     r13
0x140007c99  pop     r12
0x140007c9b  pop     rdi
0x140007c9c  retn

// ===== unknown_libname_9 @ 0x140007ca0 =====

0x140007ca0  mov     [rsp+arg_0], rbx
0x140007ca5  mov     [rsp+arg_8], rsi
0x140007caa  push    rdi
0x140007cab  sub     rsp, 20h
0x140007caf  add     qword ptr [rcx+20h], 8
0x140007cb4  mov     rbx, rcx
0x140007cb7  mov     rax, [rcx+20h]
0x140007cbb  mov     rdi, [rax-8]
0x140007cbf  test    rdi, rdi
0x140007cc2  jz      short loc_140007CF8
0x140007cc4  mov     rsi, [rdi+8]
0x140007cc8  test    rsi, rsi
0x140007ccb  jz      short loc_140007CF8
0x140007ccd  mov     r8d, [rcx+3Ch]
0x140007cd1  movzx   edx, word ptr [rcx+42h]
0x140007cd5  mov     rcx, [rcx]
0x140007cd8  call    ??$is_wide_character_specifier@_W@__crt_stdio_output@@YA_N_K_WW4length_modifier@0@@Z
0x140007cdd  test    al, al
0x140007cdf  mov     [rbx+48h], rsi
0x140007ce3  movzx   eax, word ptr [rdi]
0x140007ce6  jz      short loc_140007CF3
0x140007ce8  shr     eax, 1
0x140007cea  mov     [rbx+50h], eax
0x140007ced  mov     byte ptr [rbx+54h], 1
0x140007cf1  jmp     short loc_140007D0E
0x140007cf3  mov     [rbx+50h], eax
0x140007cf6  jmp     short loc_140007D0A
0x140007cf8  lea     rcx, aNull
0x140007cff  mov     dword ptr [rbx+50h], 6
0x140007d06  mov     [rbx+48h], rcx
0x140007d0a  mov     byte ptr [rbx+54h], 0
0x140007d0e  mov     rbx, [rsp+28h+arg_0]
0x140007d13  mov     al, 1
0x140007d15  mov     rsi, [rsp+28h+arg_8]
0x140007d1a  add     rsp, 20h
0x140007d1e  pop     rdi
0x140007d1f  retn

// ===== unknown_libname_10 @ 0x140007d20 =====

0x140007d20  mov     [rsp+arg_8], rbx
0x140007d25  mov     [rsp+arg_10], rdi
0x140007d2a  push    r14
0x140007d2c  sub     rsp, 50h
0x140007d30  or      dword ptr [rcx+30h], 10h
0x140007d34  mov     rbx, rcx
0x140007d37  mov     eax, [rcx+38h]
0x140007d3a  mov     r14d, 0FFDFh
0x140007d40  test    eax, eax
0x140007d42  jns     short loc_140007D60
0x140007d44  movzx   eax, word ptr [rcx+42h]
0x140007d48  sub     ax, 41h ; 'A'
0x140007d4c  and     ax, r14w
0x140007d50  neg     ax
0x140007d53  sbb     eax, eax
0x140007d55  and     eax, 0FFFFFFF9h
0x140007d58  add     eax, 0Dh
0x140007d5b  mov     [rcx+38h], eax
0x140007d5e  jmp     short loc_140007D77
0x140007d60  jnz     short loc_140007D77
0x140007d62  movzx   eax, word ptr [rcx+42h]
0x140007d66  sub     ax, 47h ; 'G'
0x140007d6a  test    r14w, ax
0x140007d6e  jnz     short loc_140007D77
0x140007d70  mov     dword ptr [rcx+38h], 1
0x140007d77  mov     eax, [rcx+38h]
0x140007d7a  lea     rdi, [rcx+58h]
0x140007d7e  add     eax, 15Dh
0x140007d83  mov     rcx, rdi
0x140007d86  movsxd  rdx, eax
0x140007d89  call    ??$ensure_buffer_is_big_enough@D@formatting_buffer@__crt_stdio_output@@QEAA_N_K@Z
0x140007d8e  mov     r8d, 200h
0x140007d94  test    al, al
0x140007d96  jnz     short loc_140007DB9
0x140007d98  cmp     qword ptr [rdi+408h], 0
0x140007da0  jnz     short loc_140007DA7
0x140007da2  mov     eax, r8d
0x140007da5  jmp     short loc_140007DB1
0x140007da7  mov     rax, [rdi+400h]
0x140007dae  shr     rax, 1
0x140007db1  add     eax, 0FFFFFEA3h
0x140007db6  mov     [rbx+38h], eax
0x140007db9  mov     rax, [rdi+408h]
0x140007dc0  test    rax, rax
0x140007dc3  cmovz   rax, rdi
0x140007dc7  mov     [rbx+48h], rax
0x140007dcb  xor     eax, eax
0x140007dcd  add     qword ptr [rbx+20h], 8
0x140007dd2  cmp     qword ptr [rdi+408h], 0
0x140007dda  mov     [rsp+58h+arg_0], rax
0x140007ddf  mov     rax, [rbx+20h]
0x140007de3  movsd   xmm0, qword ptr [rax-8]
0x140007de8  movsd   [rsp+58h+arg_0], xmm0
0x140007dee  jnz     short loc_140007DF5
0x140007df0  mov     r9, r8
0x140007df3  jmp     short loc_140007DFF
0x140007df5  mov     r9, [rdi+400h]
0x140007dfc  shr     r9, 1
0x140007dff  mov     rcx, [rdi+408h]
0x140007e06  test    rcx, rcx
0x140007e09  jnz     short loc_140007E14
0x140007e0b  lea     r10, [rdi+200h]
0x140007e12  jmp     short loc_140007E21
0x140007e14  mov     r10, [rdi+400h]
0x140007e1b  shr     r10, 1
0x140007e1e  add     r10, rcx
0x140007e21  cmp     rcx, 0
0x140007e25  jz      short loc_140007E31
0x140007e27  mov     r8, [rdi+400h]
0x140007e2e  shr     r8, 1; unsigned __int64
0x140007e31  mov     rax, [rbx+8]
0x140007e35  mov     rdx, rcx
0x140007e38  mov     [rsp+58h+var_18], rax; struct __crt_locale_pointers *
0x140007e3d  test    rcx, rcx
0x140007e40  mov     rax, [rbx]
0x140007e43  movsx   ecx, byte ptr [rbx+42h]
0x140007e47  cmovz   rdx, rdi; char *
0x140007e4b  mov     [rsp+58h+var_20], rax; __int64
0x140007e50  mov     eax, [rbx+38h]
0x140007e53  mov     [rsp+58h+var_28], eax; int
0x140007e57  mov     [rsp+58h+var_30], ecx; int
0x140007e5b  lea     rcx, [rsp+58h+arg_0]; double *
0x140007e60  mov     [rsp+58h+var_38], r9; unsigned __int64
0x140007e65  mov     r9, r10; char *
0x140007e68  call    __acrt_fp_format
0x140007e6d  mov     eax, [rbx+30h]
0x140007e70  shr     eax, 5
0x140007e73  test    al, 1
0x140007e75  jz      short loc_140007E8A
0x140007e77  cmp     dword ptr [rbx+38h], 0
0x140007e7b  jnz     short loc_140007E8A
0x140007e7d  mov     rdx, [rbx+8]; char *
0x140007e81  mov     rcx, [rbx+48h]; this
0x140007e85  call    ?force_decimal_point@__crt_stdio_output@@YAXPEADQEAU__crt_locale_pointers@@@Z
0x140007e8a  movzx   eax, word ptr [rbx+42h]
0x140007e8e  sub     ax, 47h ; 'G'
0x140007e92  test    r14w, ax
0x140007e96  jnz     short loc_140007F05
0x140007e98  mov     eax, [rbx+30h]
0x140007e9b  shr     eax, 5
0x140007e9e  test    al, 1
0x140007ea0  jnz     short loc_140007F05
0x140007ea2  mov     rax, [rbx+8]
0x140007ea6  mov     rdx, [rbx+48h]
0x140007eaa  mov     rcx, [rax]
0x140007ead  mov     rax, [rcx+0F8h]
0x140007eb4  mov     rcx, [rax]
0x140007eb7  mov     r8b, [rcx]
0x140007eba  jmp     short loc_140007EC4
0x140007ebc  cmp     al, r8b
0x140007ebf  jz      short loc_140007ECA
0x140007ec1  inc     rdx
0x140007ec4  mov     al, [rdx]
0x140007ec6  test    al, al
0x140007ec8  jnz     short loc_140007EBC
0x140007eca  mov     al, [rdx]
0x140007ecc  inc     rdx
0x140007ecf  test    al, al
0x140007ed1  jz      short loc_140007F05
0x140007ed3  jmp     short loc_140007EDE
0x140007ed5  sub     al, 45h ; 'E'
0x140007ed7  test    al, 0DFh
0x140007ed9  jz      short loc_140007EE4
0x140007edb  inc     rdx
0x140007ede  mov     al, [rdx]
0x140007ee0  test    al, al
0x140007ee2  jnz     short loc_140007ED5
0x140007ee4  mov     rcx, rdx
0x140007ee7  dec     rdx
0x140007eea  cmp     byte ptr [rdx], 30h ; '0'
0x140007eed  jz      short loc_140007EE7
0x140007eef  cmp     [rdx], r8b
0x140007ef2  jnz     short loc_140007EF7
0x140007ef4  dec     rdx
0x140007ef7  mov     al, [rcx]
0x140007ef9  inc     rdx
0x140007efc  inc     rcx
0x140007eff  mov     [rdx], al
0x140007f01  test    al, al
0x140007f03  jnz     short loc_140007EF7
0x140007f05  mov     rax, [rbx+48h]
0x140007f09  cmp     byte ptr [rax], 2Dh ; '-'
0x140007f0c  jnz     short loc_140007F19
0x140007f0e  or      dword ptr [rbx+30h], 40h
0x140007f12  inc     rax
0x140007f15  mov     [rbx+48h], rax
0x140007f19  mov     rdx, [rbx+48h]
0x140007f1d  mov     al, [rdx]
0x140007f1f  sub     al, 49h ; 'I'
0x140007f21  cmp     al, 25h ; '%'
0x140007f23  ja      short loc_140007F3E
0x140007f25  mov     rcx, 2100000021h
0x140007f2f  bt      rcx, rax
0x140007f33  jnb     short loc_140007F3E
0x140007f35  mov     eax, 73h ; 's'
0x140007f3a  mov     [rbx+42h], ax
0x140007f3e  or      rcx, 0FFFFFFFFFFFFFFFFh
0x140007f42  inc     rcx
0x140007f45  cmp     byte ptr [rdx+rcx], 0
0x140007f49  jnz     short loc_140007F42
0x140007f4b  mov     rdi, [rsp+58h+arg_10]
0x140007f50  mov     al, 1
0x140007f52  mov     [rbx+50h], ecx
0x140007f55  mov     rbx, [rsp+58h+arg_8]
0x140007f5a  add     rsp, 50h
0x140007f5e  pop     r14
0x140007f60  retn

// ===== unknown_libname_11 @ 0x140007f64 =====

0x140007f64  mov     [rsp+arg_8], rbx
0x140007f69  mov     [rsp+arg_10], rsi
0x140007f6e  push    rdi
0x140007f6f  sub     rsp, 20h
0x140007f73  mov     byte ptr [rcx+54h], 1
0x140007f77  mov     rbx, rcx
0x140007f7a  add     qword ptr [rcx+20h], 8
0x140007f7f  mov     rax, [rcx+20h]
0x140007f83  mov     r8d, [rcx+3Ch]
0x140007f87  movzx   edx, word ptr [rcx+42h]
0x140007f8b  mov     rcx, [rcx]
0x140007f8e  movzx   esi, word ptr [rax-8]
0x140007f92  call    ??$is_wide_character_specifier@_W@__crt_stdio_output@@YA_N_K_WW4length_modifier@0@@Z
0x140007f97  lea     rdi, [rbx+58h]
0x140007f9b  mov     rcx, [rdi+408h]
0x140007fa2  test    al, al
0x140007fa4  jnz     short loc_140007FD5
0x140007fa6  mov     r9, [rbx+8]; Locale
0x140007faa  lea     rdx, [rsp+28h+SrcCh]; SrcCh
0x140007faf  mov     [rsp+28h+SrcCh], sil
0x140007fb4  test    rcx, rcx
0x140007fb7  mov     [rsp+28h+arg_1], al
0x140007fbb  cmovz   rcx, rdi; DstCh
0x140007fbf  mov     rax, [r9]
0x140007fc2  movsxd  r8, dword ptr [rax+8]; SrcSizeInBytes
0x140007fc6  call    _mbtowc_l
0x140007fcb  test    eax, eax
0x140007fcd  jns     short loc_140007FDF
0x140007fcf  mov     byte ptr [rbx+40h], 1
0x140007fd3  jmp     short loc_140007FDF
0x140007fd5  test    rcx, rcx
0x140007fd8  cmovz   rcx, rdi
0x140007fdc  mov     [rcx], si
0x140007fdf  mov     rcx, [rdi+408h]
0x140007fe6  mov     al, 1
0x140007fe8  mov     rsi, [rsp+28h+arg_10]
0x140007fed  test    rcx, rcx
0x140007ff0  mov     dword ptr [rbx+50h], 1
0x140007ff7  cmovz   rcx, rdi
0x140007ffb  mov     [rbx+48h], rcx
0x140007fff  mov     rbx, [rsp+28h+arg_8]
0x140008004  add     rsp, 20h
0x140008008  pop     rdi
0x140008009  retn

// ===== sub_14000800C @ 0x14000800c =====

0x14000800c  push    rbx
0x14000800e  sub     rsp, 20h
0x140008012  mov     r11d, 8
0x140008018  mov     rbx, rcx
0x14000801b  mov     ecx, [rcx+3Ch]
0x14000801e  mov     r9b, r8b
0x140008021  mov     r10d, edx
0x140008024  lea     r8d, [r11-4]
0x140008028  cmp     ecx, 5
0x14000802b  jg      short loc_140008092
0x14000802d  jz      short loc_140008047
0x14000802f  test    ecx, ecx
0x140008031  jz      short loc_14000807F
0x140008033  sub     ecx, 1
0x140008036  jz      short loc_14000808B
0x140008038  sub     ecx, 1
0x14000803b  jz      short loc_140008084
0x14000803d  sub     ecx, 1
0x140008040  jz      short loc_14000807F
0x140008042  cmp     ecx, 1
0x140008045  jnz     short loc_1400080A3
0x140008047  mov     rdx, r11
0x14000804a  mov     rax, rdx
0x14000804d  sub     rax, 1
0x140008051  jz      loc_1400080F9
0x140008057  sub     rax, 1
0x14000805b  jz      short loc_1400080DA
0x14000805d  sub     rax, 2
0x140008061  jz      short loc_1400080BD
0x140008063  cmp     rax, r8
0x140008066  jz      short loc_1400080A7
0x140008068  call    _errno
0x14000806d  mov     dword ptr [rax], 16h
0x140008073  call    _invalid_parameter_noinfo
0x140008078  xor     al, al
0x14000807a  jmp     loc_1400081A5
0x14000807f  mov     rdx, r8
0x140008082  jmp     short loc_14000804A
0x140008084  mov     edx, 2
0x140008089  jmp     short loc_14000804A
0x14000808b  mov     edx, 1
0x140008090  jmp     short loc_14000804A
0x140008092  sub     ecx, 6
0x140008095  jz      short loc_140008047
0x140008097  sub     ecx, 1
0x14000809a  jz      short loc_140008047
0x14000809c  sub     ecx, 2
0x14000809f  jz      short loc_140008047
0x1400080a1  jmp     short loc_14000803D
0x1400080a3  xor     edx, edx
0x1400080a5  jmp     short loc_14000804A
0x1400080a7  mov     eax, [rbx+30h]
0x1400080aa  add     [rbx+20h], r11
0x1400080ae  shr     eax, 4
0x1400080b1  test    al, 1
0x1400080b3  mov     rax, [rbx+20h]
0x1400080b7  mov     rcx, [rax-8]
0x1400080bb  jmp     short loc_140008116
0x1400080bd  mov     eax, [rbx+30h]
0x1400080c0  add     [rbx+20h], r11
0x1400080c4  shr     eax, 4
0x1400080c7  test    al, 1
0x1400080c9  mov     rax, [rbx+20h]
0x1400080cd  jz      short loc_1400080D5
0x1400080cf  movsxd  rcx, dword ptr [rax-8]
0x1400080d3  jmp     short loc_140008116
0x1400080d5  mov     ecx, [rax-8]
0x1400080d8  jmp     short loc_140008116
0x1400080da  mov     eax, [rbx+30h]
0x1400080dd  add     [rbx+20h], r11
0x1400080e1  shr     eax, 4
0x1400080e4  test    al, 1
0x1400080e6  mov     rax, [rbx+20h]
0x1400080ea  jz      short loc_1400080F3
0x1400080ec  movsx   rcx, word ptr [rax-8]
0x1400080f1  jmp     short loc_140008116
0x1400080f3  movzx   ecx, word ptr [rax-8]
0x1400080f7  jmp     short loc_140008116
0x1400080f9  mov     eax, [rbx+30h]
0x1400080fc  add     [rbx+20h], r11
0x140008100  shr     eax, 4
0x140008103  test    al, 1
0x140008105  mov     rax, [rbx+20h]
0x140008109  jz      short loc_140008112
0x14000810b  movsx   rcx, byte ptr [rax-8]
0x140008110  jmp     short loc_140008116
0x140008112  movzx   ecx, byte ptr [rax-8]
0x140008116  mov     r8d, [rbx+30h]
0x14000811a  mov     eax, r8d
0x14000811d  shr     eax, 4
0x140008120  test    al, 1
0x140008122  jz      short loc_140008134
0x140008124  test    rcx, rcx
0x140008127  jns     short loc_140008134
0x140008129  neg     rcx
0x14000812c  or      r8d, 40h
0x140008130  mov     [rbx+30h], r8d
0x140008134  cmp     dword ptr [rbx+38h], 0
0x140008138  jge     short loc_140008143
0x14000813a  mov     dword ptr [rbx+38h], 1
0x140008141  jmp     short loc_140008154
0x140008143  and     dword ptr [rbx+30h], 0FFFFFFF7h
0x140008147  mov     eax, 200h
0x14000814c  cmp     [rbx+38h], eax
0x14000814f  jle     short loc_140008154
0x140008151  mov     [rbx+38h], eax
0x140008154  test    rcx, rcx
0x140008157  jnz     short loc_14000815D
0x140008159  and     dword ptr [rbx+30h], 0FFFFFFDFh
0x14000815d  mov     r8d, r10d
0x140008160  cmp     rdx, r11
0x140008163  jnz     short loc_140008172
0x140008165  mov     rdx, rcx
0x140008168  mov     rcx, rbx
0x14000816b  call    unknown_libname_6; Microsoft VisualC 64bit universal runtime
0x140008170  jmp     short loc_14000817C
0x140008172  mov     edx, ecx
0x140008174  mov     rcx, rbx
0x140008177  call    unknown_libname_5; Microsoft VisualC 64bit universal runtime
0x14000817c  mov     eax, [rbx+30h]
0x14000817f  shr     eax, 7
0x140008182  test    al, 1
0x140008184  jz      short loc_1400081A3
0x140008186  cmp     dword ptr [rbx+50h], 0
0x14000818a  jz      short loc_140008195
0x14000818c  mov     rcx, [rbx+48h]
0x140008190  cmp     byte ptr [rcx], 30h ; '0'
0x140008193  jz      short loc_1400081A3
0x140008195  dec     qword ptr [rbx+48h]
0x140008199  mov     rcx, [rbx+48h]
0x14000819d  mov     byte ptr [rcx], 30h ; '0'
0x1400081a0  inc     dword ptr [rbx+50h]
0x1400081a3  mov     al, 1
0x1400081a5  add     rsp, 20h
0x1400081a9  pop     rbx
0x1400081aa  retn

// ===== unknown_libname_12 @ 0x1400081ac =====

0x1400081ac  mov     [rsp+arg_0], rbx
0x1400081b1  mov     [rsp+arg_8], rsi
0x1400081b6  push    rdi
0x1400081b7  sub     rsp, 20h
0x1400081bb  mov     ebx, 8
0x1400081c0  mov     rdi, rcx
0x1400081c3  add     [rcx+20h], rbx
0x1400081c7  mov     rax, [rcx+20h]
0x1400081cb  mov     rsi, [rax-8]
0x1400081cf  call    _get_printf_count_output
0x1400081d4  test    eax, eax
0x1400081d6  jnz     short loc_1400081EF
0x1400081d8  call    _errno
0x1400081dd  mov     dword ptr [rax], 16h
0x1400081e3  call    _invalid_parameter_noinfo
0x1400081e8  xor     al, al
0x1400081ea  jmp     loc_140008277
0x1400081ef  mov     ecx, [rdi+3Ch]
0x1400081f2  mov     edx, 4
0x1400081f7  cmp     ecx, 5
0x1400081fa  jg      short loc_140008228
0x1400081fc  jz      short loc_14000823C
0x1400081fe  test    ecx, ecx
0x140008200  jz      short loc_140008239
0x140008202  sub     ecx, 1
0x140008205  jz      short loc_140008221
0x140008207  sub     ecx, 1
0x14000820a  jz      short loc_14000821A
0x14000820c  sub     ecx, 1
0x14000820f  jz      short loc_140008239
0x140008211  cmp     ecx, 1
0x140008214  jz      short loc_14000823C
0x140008216  xor     ebx, ebx
0x140008218  jmp     short loc_14000823C
0x14000821a  mov     ebx, 2
0x14000821f  jmp     short loc_14000823C
0x140008221  mov     ebx, 1
0x140008226  jmp     short loc_14000823C
0x140008228  sub     ecx, 6
0x14000822b  jz      short loc_14000823C
0x14000822d  sub     ecx, 1
0x140008230  jz      short loc_14000823C
0x140008232  sub     ecx, 2
0x140008235  jz      short loc_14000823C
0x140008237  jmp     short loc_14000820C
0x140008239  mov     rbx, rdx
0x14000823c  sub     rbx, 1
0x140008240  jz      short loc_14000826C
0x140008242  sub     rbx, 1
0x140008246  jz      short loc_140008263
0x140008248  sub     rbx, 2
0x14000824c  jz      short loc_14000825C
0x14000824e  cmp     rbx, rdx
0x140008251  jnz     short loc_1400081D8
0x140008253  movsxd  rax, dword ptr [rdi+28h]
0x140008257  mov     [rsi], rax
0x14000825a  jmp     short loc_140008271
0x14000825c  mov     eax, [rdi+28h]
0x14000825f  mov     [rsi], eax
0x140008261  jmp     short loc_140008271
0x140008263  movzx   eax, word ptr [rdi+28h]
0x140008267  mov     [rsi], ax
0x14000826a  jmp     short loc_140008271
0x14000826c  mov     cl, [rdi+28h]
0x14000826f  mov     [rsi], cl
0x140008271  mov     byte ptr [rdi+40h], 1
0x140008275  mov     al, 1
0x140008277  mov     rbx, [rsp+28h+arg_0]
0x14000827c  mov     rsi, [rsp+28h+arg_8]
0x140008281  add     rsp, 20h
0x140008285  pop     rdi
0x140008286  retn

// ===== unknown_libname_13 @ 0x140008288 =====

0x140008288  mov     [rsp+arg_0], rbx
0x14000828d  mov     [rsp+arg_8], rsi
0x140008292  push    rdi
0x140008293  sub     rsp, 20h
0x140008297  add     qword ptr [rcx+20h], 8
0x14000829c  mov     rbx, rcx
0x14000829f  mov     rax, [rcx+20h]
0x1400082a3  mov     edi, [rcx+38h]
0x1400082a6  cmp     edi, 0FFFFFFFFh
0x1400082a9  mov     r8d, [rcx+3Ch]
0x1400082ad  movzx   edx, word ptr [rcx+42h]
0x1400082b1  mov     rsi, [rax-8]
0x1400082b5  mov     eax, 7FFFFFFFh
0x1400082ba  mov     [rcx+48h], rsi
0x1400082be  cmovz   edi, eax
0x1400082c1  mov     rcx, [rcx]
0x1400082c4  call    ??$is_wide_character_specifier@_W@__crt_stdio_output@@YA_N_K_WW4length_modifier@0@@Z
0x1400082c9  test    al, al
0x1400082cb  jz      short loc_1400082F0
0x1400082cd  test    rsi, rsi
0x1400082d0  movsxd  rdx, edi; MaxCount
0x1400082d3  lea     rcx, aNull_0
0x1400082da  mov     byte ptr [rbx+54h], 1
0x1400082de  cmovnz  rcx, rsi; Source
0x1400082e2  mov     [rbx+48h], rcx
0x1400082e6  call    wcsnlen
0x1400082eb  mov     [rbx+50h], eax
0x1400082ee  jmp     short loc_14000833C
0x1400082f0  test    rsi, rsi
0x1400082f3  jnz     short loc_140008300
0x1400082f5  lea     rax, aNull
0x1400082fc  mov     [rbx+48h], rax
0x140008300  mov     r8, [rbx+48h]
0x140008304  xor     r9d, r9d
0x140008307  test    edi, edi
0x140008309  jle     short loc_140008338
0x14000830b  cmp     byte ptr [r8], 0
0x14000830f  jz      short loc_140008338
0x140008311  mov     rax, [rbx+8]
0x140008315  movzx   edx, byte ptr [r8]
0x140008319  mov     rcx, [rax]
0x14000831c  mov     rax, [rcx]
0x14000831f  mov     ecx, 8000h
0x140008324  test    [rax+rdx*2], cx
0x140008328  jz      short loc_14000832D
0x14000832a  inc     r8
0x14000832d  inc     r8
0x140008330  inc     r9d
0x140008333  cmp     r9d, edi
0x140008336  jl      short loc_14000830B
0x140008338  mov     [rbx+50h], r9d
0x14000833c  mov     rbx, [rsp+28h+arg_0]
0x140008341  mov     al, 1
0x140008343  mov     rsi, [rsp+28h+arg_8]
0x140008348  add     rsp, 20h
0x14000834c  pop     rdi
0x14000834d  retn

// ===== unknown_libname_14 @ 0x140008350 =====

0x140008350  mov     [rsp+arg_8], rbx
0x140008355  mov     [rsp+arg_10], rbp
0x14000835a  mov     [rsp+arg_18], rsi
0x14000835f  push    rdi
0x140008360  sub     rsp, 30h
0x140008364  xor     ebp, ebp
0x140008366  mov     rbx, rcx
0x140008369  cmp     [rcx+54h], bpl
0x14000836d  jnz     loc_140008405
0x140008373  mov     eax, [rcx+50h]
0x140008376  test    eax, eax
0x140008378  jle     loc_140008405
0x14000837e  mov     rsi, [rcx+48h]
0x140008382  mov     edi, ebp
0x140008384  mov     r9, [rbx+8]; Locale
0x140008388  lea     rcx, [rsp+38h+DstCh]; DstCh
0x14000838d  mov     [rsp+38h+DstCh], bp
0x140008392  mov     rdx, rsi; SrcCh
0x140008395  mov     rax, [r9]
0x140008398  movsxd  r8, dword ptr [rax+8]; SrcSizeInBytes
0x14000839c  call    _mbtowc_l
0x1400083a1  movsxd  rdx, eax
0x1400083a4  test    eax, eax
0x1400083a6  jle     short loc_1400083FF
0x1400083a8  mov     rcx, [rbx+468h]
0x1400083af  movzx   r8d, [rsp+38h+DstCh]
0x1400083b5  mov     rax, [rcx+8]
0x1400083b9  cmp     [rcx+10h], rax
0x1400083bd  jnz     short loc_1400083D0
0x1400083bf  cmp     [rcx+18h], bpl
0x1400083c3  jz      short loc_1400083CA
0x1400083c5  inc     dword ptr [rbx+28h]
0x1400083c8  jmp     short loc_1400083F0
0x1400083ca  or      dword ptr [rbx+28h], 0FFFFFFFFh
0x1400083ce  jmp     short loc_1400083F0
0x1400083d0  inc     dword ptr [rbx+28h]
0x1400083d3  inc     qword ptr [rcx+10h]
0x1400083d7  mov     rax, [rbx+468h]
0x1400083de  mov     rcx, [rax]
0x1400083e1  mov     [rcx], r8w
0x1400083e5  mov     rax, [rbx+468h]
0x1400083ec  add     qword ptr [rax], 2
0x1400083f0  add     rsi, rdx
0x1400083f3  inc     edi
0x1400083f5  mov     rax, rdx
0x1400083f8  cmp     edi, [rbx+50h]
0x1400083fb  jnz     short loc_140008384
0x1400083fd  jmp     short loc_140008426
0x1400083ff  or      dword ptr [rbx+28h], 0FFFFFFFFh
0x140008403  jmp     short loc_140008426
0x140008405  mov     rax, [rbx+10h]
0x140008409  lea     r9, [rcx+28h]
0x14000840d  mov     r8d, [rbx+50h]
0x140008411  add     rcx, 468h
0x140008418  mov     rdx, [rbx+48h]
0x14000841c  mov     [rsp+38h+var_18], rax
0x140008421  call    ?write_string@?$string_output_adapter@_W@__crt_stdio_output@@QEBAXQEB_WHQEAH1@Z
0x140008426  mov     rbx, [rsp+38h+arg_8]
0x14000842b  mov     al, 1
0x14000842d  mov     rbp, [rsp+38h+arg_10]
0x140008432  mov     rsi, [rsp+38h+arg_18]
0x140008437  add     rsp, 30h
0x14000843b  pop     rdi
0x14000843c  retn

// ===== ?write_string@?$string_output_adapter@_W@__crt_stdio_output@@QEBAXQEB_WHQEAH1@Z @ 0x140008440 =====

0x140008440  mov     [rsp+arg_0], rbx
0x140008445  mov     [rsp+arg_8], rbp
0x14000844a  mov     [rsp+arg_10], rsi
0x14000844f  push    rdi
0x140008450  push    r12
0x140008452  push    r13
0x140008454  push    r14
0x140008456  push    r15
0x140008458  sub     rsp, 20h
0x14000845c  mov     rsi, [rsp+48h+arg_20]
0x140008461  mov     r12, rcx
0x140008464  mov     rdi, r9
0x140008467  movsxd  rbp, r8d
0x14000846a  mov     r15d, [rsi]
0x14000846d  and     dword ptr [rsi], 0
0x140008470  mov     rcx, [rcx]
0x140008473  mov     rax, [rcx+8]
0x140008477  cmp     [rcx+10h], rax
0x14000847b  jnz     short loc_14000848E
0x14000847d  cmp     byte ptr [rcx+18h], 0
0x140008481  jz      short loc_140008488
0x140008483  add     [r9], ebp
0x140008486  jmp     short loc_1400084D5
0x140008488  or      dword ptr [r9], 0FFFFFFFFh
0x14000848c  jmp     short loc_1400084D5
0x14000848e  sub     rax, [rcx+10h]
0x140008492  mov     r14, rbp
0x140008495  mov     rcx, [rcx]
0x140008498  cmp     rax, rbp
0x14000849b  cmovb   r14, rax
0x14000849f  lea     rbx, [r14+r14]
0x1400084a3  mov     r8, rbx
0x1400084a6  call    sub_1400067F0
0x1400084ab  mov     rax, [r12]
0x1400084af  add     [rax], rbx
0x1400084b2  mov     rax, [r12]
0x1400084b6  add     [rax+10h], r14
0x1400084ba  mov     rax, [r12]
0x1400084be  cmp     byte ptr [rax+18h], 0
0x1400084c2  jz      short loc_1400084C8
0x1400084c4  add     [rdi], ebp
0x1400084c6  jmp     short loc_1400084D5
0x1400084c8  cmp     r14, rbp
0x1400084cb  jz      short loc_1400084D2
0x1400084cd  or      dword ptr [rdi], 0FFFFFFFFh
0x1400084d0  jmp     short loc_1400084D5
0x1400084d2  add     [rdi], r14d
0x1400084d5  cmp     dword ptr [rsi], 0
0x1400084d8  jnz     short loc_1400084E2
0x1400084da  test    r15d, r15d
0x1400084dd  jz      short loc_1400084E2
0x1400084df  mov     [rsi], r15d
0x1400084e2  mov     rbx, [rsp+48h+arg_0]
0x1400084e7  mov     rbp, [rsp+48h+arg_8]
0x1400084ec  mov     rsi, [rsp+48h+arg_10]
0x1400084f1  add     rsp, 20h
0x1400084f5  pop     r15
0x1400084f7  pop     r14
0x1400084f9  pop     r13
0x1400084fb  pop     r12
0x1400084fd  pop     rdi
0x1400084fe  retn

// ===== unknown_libname_15 @ 0x140008500 =====

0x140008500  mov     [rsp+arg_0], rbx
0x140008505  push    rdi
0x140008506  sub     rsp, 30h
0x14000850a  xor     edi, edi
0x14000850c  mov     rbx, rdx
0x14000850f  test    r9, r9
0x140008512  jz      short loc_140008550
0x140008514  test    rdx, rdx
0x140008517  jz      short loc_140008550
0x140008519  test    r8, r8
0x14000851c  jz      short loc_140008550
0x14000851e  mov     rax, [rsp+38h+arg_28]
0x140008523  mov     [rsp+38h+var_10], rax; __int64
0x140008528  mov     rax, [rsp+38h+arg_20]
0x14000852d  mov     [rsp+38h+var_18], rax; struct __crt_locale_pointers *
0x140008532  call    sub_140006FEC
0x140008537  test    eax, eax
0x140008539  jns     short loc_14000853E
0x14000853b  mov     [rbx], di
0x14000853e  cmp     eax, 0FFFFFFFEh
0x140008541  jnz     short loc_140008563
0x140008543  call    _errno
0x140008548  mov     dword ptr [rax], 22h ; '"'
0x14000854e  jmp     short loc_14000855B
0x140008550  call    _errno
0x140008555  mov     dword ptr [rax], 16h
0x14000855b  call    _invalid_parameter_noinfo
0x140008560  or      eax, 0FFFFFFFFh
0x140008563  mov     rbx, [rsp+38h+arg_0]
0x140008568  add     rsp, 30h
0x14000856c  pop     rdi
0x14000856d  retn

// ===== _seh_filter_exe @ 0x140008570 =====

0x140008570  mov     [rsp+arg_0], rbx
0x140008575  mov     [rsp+arg_8], rbp
0x14000857a  mov     [rsp+arg_10], rsi
0x14000857f  push    rdi
0x140008580  sub     rsp, 20h
0x140008584  mov     rsi, rdx
0x140008587  mov     edi, ecx
0x140008589  call    __acrt_getptd_noexit
0x14000858e  xor     r8d, r8d
0x140008591  mov     rbx, rax
0x140008594  test    rax, rax
0x140008597  jnz     short loc_1400085A0
0x140008599  xor     eax, eax
0x14000859b  jmp     loc_1400086E8
0x1400085a0  mov     rcx, [rax]
0x1400085a3  mov     rax, rcx
0x1400085a6  lea     rdx, [rcx+0C0h]
0x1400085ad  cmp     rcx, rdx
0x1400085b0  jz      short loc_1400085BF
0x1400085b2  cmp     [rax], edi
0x1400085b4  jz      short loc_1400085C2
0x1400085b6  add     rax, 10h
0x1400085ba  cmp     rax, rdx
0x1400085bd  jnz     short loc_1400085B2
0x1400085bf  mov     rax, r8
0x1400085c2  test    rax, rax
0x1400085c5  jz      short loc_140008599
0x1400085c7  mov     rdi, [rax+8]
0x1400085cb  test    rdi, rdi
0x1400085ce  jz      short loc_140008599
0x1400085d0  cmp     rdi, 5
0x1400085d4  jnz     short loc_1400085E2
0x1400085d6  mov     [rax+8], r8
0x1400085da  lea     eax, [rdi-4]
0x1400085dd  jmp     loc_1400086E8
0x1400085e2  cmp     rdi, 1
0x1400085e6  jz      loc_1400086E5
0x1400085ec  mov     rbp, [rbx+8]
0x1400085f0  mov     [rbx+8], rsi
0x1400085f4  mov     esi, [rax+4]
0x1400085f7  cmp     esi, 8
0x1400085fa  jnz     loc_1400086D0
0x140008600  add     rcx, 30h ; '0'
0x140008604  lea     rdx, [rcx+90h]
0x14000860b  jmp     short loc_140008615
0x14000860d  mov     [rcx+8], r8
0x140008611  add     rcx, 10h
0x140008615  cmp     rcx, rdx
0x140008618  jnz     short loc_14000860D
0x14000861a  cmp     dword ptr [rax], 0C000008Dh
0x140008620  mov     esi, [rbx+10h]
0x140008623  jz      loc_1400086B1
0x140008629  cmp     dword ptr [rax], 0C000008Eh
0x14000862f  jz      short loc_1400086A8
0x140008631  cmp     dword ptr [rax], 0C000008Fh
0x140008637  jz      short loc_14000869F
0x140008639  cmp     dword ptr [rax], 0C0000090h
0x14000863f  jz      short loc_140008696
0x140008641  cmp     dword ptr [rax], 0C0000091h
0x140008647  jz      short loc_14000868D
0x140008649  cmp     dword ptr [rax], 0C0000092h
0x14000864f  jz      short loc_140008684
0x140008651  cmp     dword ptr [rax], 0C0000093h
0x140008657  jz      short loc_14000867B
0x140008659  cmp     dword ptr [rax], 0C00002B4h
0x14000865f  jz      short loc_140008672
0x140008661  cmp     dword ptr [rax], 0C00002B5h
0x140008667  jnz     short loc_1400086B8
0x140008669  mov     dword ptr [rbx+10h], 8Dh
0x140008670  jmp     short loc_1400086B8
0x140008672  mov     dword ptr [rbx+10h], 8Eh
0x140008679  jmp     short loc_1400086B8
0x14000867b  mov     dword ptr [rbx+10h], 85h
0x140008682  jmp     short loc_1400086B8
0x140008684  mov     dword ptr [rbx+10h], 8Ah
0x14000868b  jmp     short loc_1400086B8
0x14000868d  mov     dword ptr [rbx+10h], 84h
0x140008694  jmp     short loc_1400086B8
0x140008696  mov     dword ptr [rbx+10h], 81h
0x14000869d  jmp     short loc_1400086B8
0x14000869f  mov     dword ptr [rbx+10h], 86h
0x1400086a6  jmp     short loc_1400086B8
0x1400086a8  mov     dword ptr [rbx+10h], 83h
0x1400086af  jmp     short loc_1400086B8
0x1400086b1  mov     dword ptr [rbx+10h], 82h
0x1400086b8  mov     rcx, rdi
0x1400086bb  call    cs:__guard_check_icall_fptr
0x1400086c1  mov     edx, [rbx+10h]
0x1400086c4  mov     ecx, 8
0x1400086c9  call    rdi
0x1400086cb  mov     [rbx+10h], esi
0x1400086ce  jmp     short loc_1400086E1
0x1400086d0  mov     rcx, rdi
0x1400086d3  mov     [rax+8], r8
0x1400086d7  call    cs:__guard_check_icall_fptr
0x1400086dd  mov     ecx, esi
0x1400086df  call    rdi
0x1400086e1  mov     [rbx+8], rbp
0x1400086e5  or      eax, 0FFFFFFFFh
0x1400086e8  mov     rbx, [rsp+28h+arg_0]
0x1400086ed  mov     rbp, [rsp+28h+arg_8]
0x1400086f2  mov     rsi, [rsp+28h+arg_10]
0x1400086f7  add     rsp, 20h
0x1400086fb  pop     rdi
0x1400086fc  retn

// ===== sub_140008700 @ 0x140008700 =====

0x140008700  mov     eax, cs:dword_140021518
0x140008706  retn

// ===== sub_140008708 @ 0x140008708 =====

0x140008708  mov     cs:dword_140021518, ecx
0x14000870e  retn

// ===== __acrt_has_user_matherr @ 0x140008710 =====

0x140008710  mov     rdx, cs:__security_cookie
0x140008717  mov     ecx, edx
0x140008719  xor     rdx, cs:qword_140021520
0x140008720  and     ecx, 3Fh
0x140008723  ror     rdx, cl
0x140008726  test    rdx, rdx
0x140008729  setnz   al
0x14000872c  retn

// ===== sub_140008730 @ 0x140008730 =====

0x140008730  mov     cs:qword_140021520, rcx
0x140008737  retn

// ===== __acrt_invoke_user_matherr @ 0x140008738 =====

0x140008738  mov     [rsp+arg_0], rbx
0x14000873d  push    rdi
0x14000873e  sub     rsp, 20h
0x140008742  mov     rbx, cs:__security_cookie
0x140008749  mov     rdi, rcx
0x14000874c  mov     ecx, ebx
0x14000874e  xor     rbx, cs:qword_140021520
0x140008755  and     ecx, 3Fh
0x140008758  ror     rbx, cl
0x14000875b  test    rbx, rbx
0x14000875e  jnz     short loc_140008764
0x140008760  xor     eax, eax
0x140008762  jmp     short loc_140008772
0x140008764  mov     rcx, rbx
0x140008767  call    cs:__guard_check_icall_fptr
0x14000876d  mov     rcx, rdi
0x140008770  call    rbx
0x140008772  mov     rbx, [rsp+28h+arg_0]
0x140008777  add     rsp, 20h
0x14000877b  pop     rdi
0x14000877c  retn

// ===== __setusermatherr @ 0x140008780 =====

0x140008780  mov     r8, cs:__security_cookie
0x140008787  mov     r9, rcx
0x14000878a  mov     edx, r8d
0x14000878d  mov     ecx, 40h ; '@'
0x140008792  and     edx, 3Fh
0x140008795  sub     ecx, edx
0x140008797  ror     r9, cl
0x14000879a  xor     r9, r8
0x14000879d  mov     cs:qword_140021520, r9
0x1400087a4  retn

// ===== ??$parse_command_line@_W@@YAXPEA_WPEAPEA_W0PEA_K2@Z @ 0x1400087a8 =====

0x1400087a8  mov     rax, rsp
0x1400087ab  mov     [rax+8], rbx
0x1400087af  mov     [rax+10h], rsi
0x1400087b3  mov     [rax+18h], rdi
0x1400087b7  mov     [rax+20h], r12
0x1400087bb  push    r15
0x1400087bd  mov     r10, [rsp+8+arg_20]
0x1400087c2  xor     esi, esi
0x1400087c4  mov     rbx, r9
0x1400087c7  mov     [r10], rsi
0x1400087ca  mov     qword ptr [r9], 1
0x1400087d1  test    rdx, rdx
0x1400087d4  jz      short loc_1400087DD
0x1400087d6  mov     [rdx], r8
0x1400087d9  add     rdx, 8
0x1400087dd  mov     r9b, sil
0x1400087e0  mov     r12d, 22h ; '"'
0x1400087e6  cmp     [rcx], r12w
0x1400087ea  jnz     short loc_1400087FD
0x1400087ec  test    r9b, r9b
0x1400087ef  movzx   eax, r12w
0x1400087f3  setz    r9b
0x1400087f7  add     rcx, 2
0x1400087fb  jmp     short loc_14000881C
0x1400087fd  inc     qword ptr [r10]
0x140008800  test    r8, r8
0x140008803  jz      short loc_140008810
0x140008805  movzx   eax, word ptr [rcx]
0x140008808  mov     [r8], ax
0x14000880c  add     r8, 2
0x140008810  movzx   eax, word ptr [rcx]
0x140008813  add     rcx, 2
0x140008817  test    ax, ax
0x14000881a  jz      short loc_140008839
0x14000881c  test    r9b, r9b
0x14000881f  jnz     short loc_1400087E6
0x140008821  cmp     ax, 20h ; ' '
0x140008825  jz      short loc_14000882D
0x140008827  cmp     ax, 9
0x14000882b  jnz     short loc_1400087E6
0x14000882d  test    r8, r8
0x140008830  jz      short loc_14000883D
0x140008832  mov     [r8-2], si
0x140008837  jmp     short loc_14000883D
0x140008839  sub     rcx, 2
0x14000883d  mov     dil, sil
0x140008840  mov     r15d, 5Ch ; '\'
0x140008846  cmp     [rcx], si
0x140008849  jz      loc_14000891C
0x14000884f  cmp     word ptr [rcx], 20h ; ' '
0x140008853  jz      short loc_14000885B
0x140008855  cmp     word ptr [rcx], 9
0x140008859  jnz     short loc_140008861
0x14000885b  add     rcx, 2
0x14000885f  jmp     short loc_14000884F
0x140008861  cmp     [rcx], si
0x140008864  jz      loc_14000891C
0x14000886a  test    rdx, rdx
0x14000886d  jz      short loc_140008876
0x14000886f  mov     [rdx], r8
0x140008872  add     rdx, 8
0x140008876  inc     qword ptr [rbx]
0x140008879  mov     r11d, 1
0x14000887f  mov     eax, esi
0x140008881  jmp     short loc_140008889
0x140008883  add     rcx, 2
0x140008887  inc     eax
0x140008889  cmp     [rcx], r15w
0x14000888d  jz      short loc_140008883
0x14000888f  cmp     [rcx], r12w
0x140008893  jnz     short loc_1400088CC
0x140008895  test    r11b, al
0x140008898  jnz     short loc_1400088B6
0x14000889a  test    dil, dil
0x14000889d  jz      short loc_1400088AC
0x14000889f  cmp     [rcx+2], r12w
0x1400088a4  jnz     short loc_1400088AC
0x1400088a6  add     rcx, 2
0x1400088aa  jmp     short loc_1400088B6
0x1400088ac  test    dil, dil
0x1400088af  mov     r11d, esi
0x1400088b2  setz    dil
0x1400088b6  shr     eax, 1
0x1400088b8  jmp     short loc_1400088CC
0x1400088ba  dec     eax
0x1400088bc  test    r8, r8
0x1400088bf  jz      short loc_1400088C9
0x1400088c1  mov     [r8], r15w
0x1400088c5  add     r8, 2
0x1400088c9  inc     qword ptr [r10]
0x1400088cc  test    eax, eax
0x1400088ce  jnz     short loc_1400088BA
0x1400088d0  movzx   eax, word ptr [rcx]
0x1400088d3  test    ax, ax
0x1400088d6  jz      short loc_140008907
0x1400088d8  test    dil, dil
0x1400088db  jnz     short loc_1400088E9
0x1400088dd  cmp     ax, 20h ; ' '
0x1400088e1  jz      short loc_140008907
0x1400088e3  cmp     ax, 9
0x1400088e7  jz      short loc_140008907
0x1400088e9  test    r11d, r11d
0x1400088ec  jz      short loc_1400088FE
0x1400088ee  test    r8, r8
0x1400088f1  jz      short loc_1400088FB
0x1400088f3  mov     [r8], ax
0x1400088f7  add     r8, 2
0x1400088fb  inc     qword ptr [r10]
0x1400088fe  add     rcx, 2
0x140008902  jmp     loc_140008879
0x140008907  test    r8, r8
0x14000890a  jz      short loc_140008914
0x14000890c  mov     [r8], si
0x140008910  add     r8, 2
0x140008914  inc     qword ptr [r10]
0x140008917  jmp     loc_140008846
0x14000891c  test    rdx, rdx
0x14000891f  jz      short loc_140008924
0x140008921  mov     [rdx], rsi
0x140008924  inc     qword ptr [rbx]
0x140008927  mov     rbx, [rsp+8+arg_0]
0x14000892c  mov     rsi, [rsp+8+arg_8]
0x140008931  mov     rdi, [rsp+8+arg_10]
0x140008936  mov     r12, [rsp+8+arg_18]
0x14000893b  pop     r15
0x14000893d  retn

// ===== __acrt_allocate_buffer_for_argv @ 0x140008940 =====

0x140008940  push    rbx
0x140008942  sub     rsp, 20h
0x140008946  mov     rax, 1FFFFFFFFFFFFFFFh
0x140008950  mov     r9, rdx
0x140008953  mov     r10, rcx
0x140008956  cmp     rcx, rax
0x140008959  jb      short loc_14000895F
0x14000895b  xor     eax, eax
0x14000895d  jmp     short loc_14000899B
0x14000895f  or      rcx, 0FFFFFFFFFFFFFFFFh
0x140008963  xor     edx, edx
0x140008965  mov     rax, rcx
0x140008968  div     r8
0x14000896b  cmp     r9, rax
0x14000896e  jnb     short loc_14000895B
0x140008970  shl     r10, 3
0x140008974  imul    r9, r8
0x140008978  sub     rcx, r10
0x14000897b  cmp     rcx, r9
0x14000897e  jbe     short loc_14000895B
0x140008980  lea     rcx, [r9+r10]; Count
0x140008984  mov     edx, 1; Size
0x140008989  call    _calloc_base
0x14000898e  xor     ecx, ecx; Block
0x140008990  mov     rbx, rax
0x140008993  call    _free_base
0x140008998  mov     rax, rbx
0x14000899b  add     rsp, 20h
0x14000899f  pop     rbx
0x1400089a0  retn

// ===== _configure_wide_argv @ 0x1400089a4 =====

0x1400089a4  mov     [rsp-28h+arg_0], rbx
0x1400089a9  push    rbp
0x1400089aa  push    rsi
0x1400089ab  push    rdi
0x1400089ac  push    r14
0x1400089ae  push    r15
0x1400089b0  mov     rbp, rsp
0x1400089b3  sub     rsp, 30h
0x1400089b7  lea     eax, [rcx-1]
0x1400089ba  mov     r14d, ecx
0x1400089bd  cmp     eax, 1
0x1400089c0  jbe     short loc_1400089D8
0x1400089c2  call    _errno
0x1400089c7  mov     edi, 16h
0x1400089cc  mov     [rax], edi
0x1400089ce  call    _invalid_parameter_noinfo
0x1400089d3  jmp     loc_140008B02
0x1400089d8  lea     rbx, Filename
0x1400089df  mov     r8d, 104h; nSize
0x1400089e5  mov     rdx, rbx; lpFilename
0x1400089e8  xor     ecx, ecx; hModule
0x1400089ea  call    cs:GetModuleFileNameW; KERNEL32
0x1400089f0  mov     rsi, cs:qword_140021C38
0x1400089f7  xor     edi, edi
0x1400089f9  mov     cs:qword_140021C40, rbx
0x140008a00  test    rsi, rsi
0x140008a03  jz      short loc_140008A0A
0x140008a05  cmp     [rsi], di
0x140008a08  jnz     short loc_140008A0D
0x140008a0a  mov     rsi, rbx
0x140008a0d  lea     rax, [rbp+arg_18]
0x140008a11  mov     [rbp+arg_10], rdi
0x140008a15  lea     r9, [rbp+arg_10]
0x140008a19  mov     [rsp+30h+var_10], rax
0x140008a1e  xor     r8d, r8d
0x140008a21  mov     [rbp+arg_18], rdi
0x140008a25  xor     edx, edx
0x140008a27  mov     rcx, rsi
0x140008a2a  call    ??$parse_command_line@_W@@YAXPEA_WPEAPEA_W0PEA_K2@Z
0x140008a2f  mov     r15, [rbp+arg_10]
0x140008a33  mov     r8d, 2
0x140008a39  mov     rdx, [rbp+arg_18]
0x140008a3d  mov     rcx, r15
0x140008a40  call    __acrt_allocate_buffer_for_argv
0x140008a45  mov     rbx, rax
0x140008a48  test    rax, rax
0x140008a4b  jnz     short loc_140008A5E
0x140008a4d  call    _errno
0x140008a52  lea     edi, [rbx+0Ch]
0x140008a55  mov     [rax], edi
0x140008a57  xor     ecx, ecx
0x140008a59  jmp     loc_140008AFD
0x140008a5e  lea     r8, [rax+r15*8]
0x140008a62  mov     rdx, rbx
0x140008a65  lea     rax, [rbp+arg_18]
0x140008a69  mov     rcx, rsi
0x140008a6c  lea     r9, [rbp+arg_10]
0x140008a70  mov     [rsp+30h+var_10], rax
0x140008a75  call    ??$parse_command_line@_W@@YAXPEA_WPEAPEA_W0PEA_K2@Z
0x140008a7a  cmp     r14d, 1
0x140008a7e  jnz     short loc_140008A94
0x140008a80  mov     eax, dword ptr [rbp+arg_10]
0x140008a83  dec     eax
0x140008a85  mov     cs:qword_140021C28, rbx
0x140008a8c  mov     cs:dword_140021C1C, eax
0x140008a92  jmp     short loc_140008A57
0x140008a94  lea     rdx, [rbp+Block]
0x140008a98  mov     [rbp+Block], rdi
0x140008a9c  mov     rcx, rbx
0x140008a9f  call    j_??$common_expand_argv_wildcards@_W@@YAHQEAPEA_WQEAPEAPEA_W@Z
0x140008aa4  mov     esi, eax
0x140008aa6  test    eax, eax
0x140008aa8  jz      short loc_140008AC3
0x140008aaa  mov     rcx, [rbp+Block]; Block
0x140008aae  call    _free_base
0x140008ab3  mov     rcx, rbx; Block
0x140008ab6  mov     [rbp+Block], rdi
0x140008aba  call    _free_base
0x140008abf  mov     edi, esi
0x140008ac1  jmp     short loc_140008B02
0x140008ac3  mov     rdx, [rbp+Block]
0x140008ac7  mov     rcx, rdi
0x140008aca  mov     rax, rdx
0x140008acd  cmp     [rdx], rdi
0x140008ad0  jz      short loc_140008ADE
0x140008ad2  lea     rax, [rax+8]
0x140008ad6  inc     rcx
0x140008ad9  cmp     [rax], rdi
0x140008adc  jnz     short loc_140008AD2
0x140008ade  mov     cs:dword_140021C1C, ecx
0x140008ae4  xor     ecx, ecx; Block
0x140008ae6  mov     [rbp+Block], rdi
0x140008aea  mov     cs:qword_140021C28, rdx
0x140008af1  call    _free_base
0x140008af6  mov     rcx, rbx; Block
0x140008af9  mov     [rbp+Block], rdi
0x140008afd  call    _free_base
0x140008b02  mov     eax, edi
0x140008b04  mov     rbx, [rsp+30h+arg_0]
0x140008b09  add     rsp, 30h
0x140008b0d  pop     r15
0x140008b0f  pop     r14
0x140008b11  pop     rdi
0x140008b12  pop     rsi
0x140008b13  pop     rbp
0x140008b14  retn

// ===== ??$common_initialize_environment_nolock@_W@@YAHXZ @ 0x140008b18 =====

0x140008b18  mov     [rsp+arg_0], rbx
0x140008b1d  push    rdi
0x140008b1e  sub     rsp, 20h
0x140008b22  xor     edi, edi
0x140008b24  cmp     cs:qword_140021748, rdi
0x140008b2b  jz      short loc_140008B31
0x140008b2d  xor     eax, eax
0x140008b2f  jmp     short loc_140008B74
0x140008b31  call    __dcrt_get_wide_environment_from_os
0x140008b36  mov     rbx, rax
0x140008b39  test    rax, rax
0x140008b3c  jnz     short loc_140008B43
0x140008b3e  or      edi, 0FFFFFFFFh
0x140008b41  jmp     short loc_140008B6A
0x140008b43  mov     rcx, rax; Source
0x140008b46  call    ??$create_environment@_W@@YAQEAPEA_WQEA_W@Z
0x140008b4b  test    rax, rax
0x140008b4e  jnz     short loc_140008B55
0x140008b50  or      edi, 0FFFFFFFFh
0x140008b53  jmp     short loc_140008B63
0x140008b55  mov     cs:qword_140021750, rax
0x140008b5c  mov     cs:qword_140021748, rax
0x140008b63  xor     ecx, ecx; Block
0x140008b65  call    _free_base
0x140008b6a  mov     rcx, rbx; Block
0x140008b6d  call    _free_base
0x140008b72  mov     eax, edi
0x140008b74  mov     rbx, [rsp+28h+arg_0]
0x140008b79  add     rsp, 20h
0x140008b7d  pop     rdi
0x140008b7e  retn

// ===== ??$create_environment@_W@@YAQEAPEA_WQEA_W@Z @ 0x140008b80 =====

0x140008b80  mov     [rsp+arg_0], rbx
0x140008b85  mov     [rsp+arg_8], rbp
0x140008b8a  mov     [rsp+arg_10], rsi
0x140008b8f  push    rdi
0x140008b90  push    r14
0x140008b92  push    r15
0x140008b94  sub     rsp, 30h
0x140008b98  xor     esi, esi
0x140008b9a  mov     r14, rcx
0x140008b9d  mov     edx, esi
0x140008b9f  jmp     short loc_140008BBF
0x140008ba1  cmp     ax, 3Dh ; '='
0x140008ba5  jz      short loc_140008BAA
0x140008ba7  inc     rdx
0x140008baa  or      rax, 0FFFFFFFFFFFFFFFFh
0x140008bae  inc     rax
0x140008bb1  cmp     [rcx+rax*2], si
0x140008bb5  jnz     short loc_140008BAE
0x140008bb7  lea     rcx, [rcx+rax*2]
0x140008bbb  add     rcx, 2
0x140008bbf  movzx   eax, word ptr [rcx]
0x140008bc2  test    ax, ax
0x140008bc5  jnz     short loc_140008BA1
0x140008bc7  lea     rcx, [rdx+1]; Count
0x140008bcb  mov     edx, 8; Size
0x140008bd0  call    _calloc_base
0x140008bd5  mov     rbx, rax
0x140008bd8  test    rax, rax
0x140008bdb  jz      short loc_140008C4D
0x140008bdd  mov     r15, rax
0x140008be0  cmp     [r14], si
0x140008be4  jz      short loc_140008C4A
0x140008be6  or      rbp, 0FFFFFFFFFFFFFFFFh
0x140008bea  inc     rbp
0x140008bed  cmp     [r14+rbp*2], si
0x140008bf2  jnz     short loc_140008BEA
0x140008bf4  inc     rbp
0x140008bf7  cmp     word ptr [r14], 3Dh ; '='
0x140008bfc  jz      short loc_140008C33
0x140008bfe  mov     edx, 2; Size
0x140008c03  mov     rcx, rbp; Count
0x140008c06  call    _calloc_base
0x140008c0b  mov     rdi, rax
0x140008c0e  test    rax, rax
0x140008c11  jz      short loc_140008C39
0x140008c13  mov     r8, r14; Source
0x140008c16  mov     rdx, rbp; SizeInWords
0x140008c19  mov     rcx, rax; Destination
0x140008c1c  call    wcscpy_s
0x140008c21  xor     ecx, ecx; Block
0x140008c23  test    eax, eax
0x140008c25  jnz     short loc_140008C70
0x140008c27  mov     [r15], rdi
0x140008c2a  add     r15, 8
0x140008c2e  call    _free_base
0x140008c33  lea     r14, [r14+rbp*2]
0x140008c37  jmp     short loc_140008BE0
0x140008c39  mov     rcx, rbx; Block
0x140008c3c  call    unknown_libname_16; Microsoft VisualC 64bit universal runtime
0x140008c41  xor     ecx, ecx; Block
0x140008c43  call    _free_base
0x140008c48  jmp     short loc_140008C4D
0x140008c4a  mov     rsi, rbx
0x140008c4d  xor     ecx, ecx; Block
0x140008c4f  call    _free_base
0x140008c54  mov     rbx, [rsp+48h+arg_0]
0x140008c59  mov     rax, rsi
0x140008c5c  mov     rsi, [rsp+48h+arg_10]
0x140008c61  mov     rbp, [rsp+48h+arg_8]
0x140008c66  add     rsp, 30h
0x140008c6a  pop     r15
0x140008c6c  pop     r14
0x140008c6e  pop     rdi
0x140008c6f  retn
0x140008c70  xor     r9d, r9d; LineNo
0x140008c73  mov     [rsp+48h+Reserved], rsi; Reserved
0x140008c78  xor     r8d, r8d; FileName
0x140008c7b  xor     edx, edx; FunctionName
0x140008c7d  call    _invoke_watson

// ===== unknown_libname_16 @ 0x140008c84 =====

0x140008c84  test    rcx, rcx
0x140008c87  jz      short locret_140008CC4
0x140008c89  mov     [rsp+arg_0], rbx
0x140008c8e  push    rdi
0x140008c8f  sub     rsp, 20h
0x140008c93  mov     rax, [rcx]
0x140008c96  mov     rbx, rcx
0x140008c99  mov     rdi, rcx
0x140008c9c  jmp     short loc_140008CAD
0x140008c9e  mov     rcx, rax; Block
0x140008ca1  call    _free_base
0x140008ca6  lea     rdi, [rdi+8]
0x140008caa  mov     rax, [rdi]
0x140008cad  test    rax, rax
0x140008cb0  jnz     short loc_140008C9E
0x140008cb2  mov     rcx, rbx; Block
0x140008cb5  call    _free_base
0x140008cba  mov     rbx, [rsp+28h+arg_0]
0x140008cbf  add     rsp, 20h
0x140008cc3  pop     rdi
0x140008cc4  retn

// ===== sub_140008CC8 @ 0x140008cc8 =====

0x140008cc8  sub     rsp, 28h
0x140008ccc  mov     rcx, [rcx]; Block
0x140008ccf  cmp     rcx, cs:qword_140021758
0x140008cd6  jz      short loc_140008CDD
0x140008cd8  call    unknown_libname_16; Microsoft VisualC 64bit universal runtime
0x140008cdd  add     rsp, 28h
0x140008ce1  retn

// ===== sub_140008CE4 @ 0x140008ce4 =====

0x140008ce4  sub     rsp, 28h
0x140008ce8  mov     rcx, [rcx]; Block
0x140008ceb  cmp     rcx, cs:qword_140021750
0x140008cf2  jz      short loc_140008CF9
0x140008cf4  call    unknown_libname_16; Microsoft VisualC 64bit universal runtime
0x140008cf9  add     rsp, 28h
0x140008cfd  retn

// ===== __dcrt_uninitialize_environments_nolock @ 0x140008d00 =====

0x140008d00  sub     rsp, 28h
0x140008d04  lea     rcx, qword_140021740
0x140008d0b  call    sub_140008CC8
0x140008d10  lea     rcx, qword_140021748
0x140008d17  call    sub_140008CE4
0x140008d1c  mov     rcx, cs:qword_140021758; Block
0x140008d23  call    unknown_libname_16; Microsoft VisualC 64bit universal runtime
0x140008d28  mov     rcx, cs:qword_140021750; Block
0x140008d2f  add     rsp, 28h
0x140008d33  jmp     unknown_libname_16; Microsoft VisualC 64bit universal runtime

// ===== j_??$common_initialize_environment_nolock@_W@@YAHXZ @ 0x140008d38 =====

0x140008d38  jmp     ??$common_initialize_environment_nolock@_W@@YAHXZ

// ===== _get_wide_winmain_command_line @ 0x140008d40 =====

0x140008d40  mov     rax, cs:qword_140021C38
0x140008d47  lea     rcx, unk_140021760
0x140008d4e  xor     edx, edx
0x140008d50  test    rax, rax
0x140008d53  cmovnz  rcx, rax
0x140008d57  mov     al, dl
0x140008d59  cmp     word ptr [rcx], 20h ; ' '
0x140008d5d  ja      short loc_140008D68
0x140008d5f  cmp     [rcx], dx
0x140008d62  jz      short loc_140008D8B
0x140008d64  test    al, al
0x140008d66  jz      short loc_140008D83
0x140008d68  cmp     word ptr [rcx], 22h ; '"'
0x140008d6c  jnz     short loc_140008D73
0x140008d6e  test    al, al
0x140008d70  setz    al
0x140008d73  add     rcx, 2
0x140008d77  jmp     short loc_140008D59
0x140008d79  cmp     ax, 20h ; ' '
0x140008d7d  ja      short loc_140008D8B
0x140008d7f  add     rcx, 2
0x140008d83  movzx   eax, word ptr [rcx]
0x140008d86  test    ax, ax
0x140008d89  jnz     short loc_140008D79
0x140008d8b  mov     rax, rcx
0x140008d8e  retn

// ===== _initterm @ 0x140008d90 =====

0x140008d90  mov     rax, rsp
0x140008d93  mov     [rax+8], rbx
0x140008d97  mov     [rax+10h], rbp
0x140008d9b  mov     [rax+18h], rsi
0x140008d9f  mov     [rax+20h], rdi
0x140008da3  push    r14
0x140008da5  sub     rsp, 20h
0x140008da9  xor     r14d, r14d
0x140008dac  mov     rdi, rdx
0x140008daf  sub     rdi, rcx
0x140008db2  mov     rbx, rcx
0x140008db5  add     rdi, 7
0x140008db9  mov     ebp, r14d
0x140008dbc  shr     rdi, 3
0x140008dc0  cmp     rcx, rdx
0x140008dc3  cmova   rdi, r14
0x140008dc7  test    rdi, rdi
0x140008dca  jz      short loc_140008DEB
0x140008dcc  mov     rsi, [rbx]
0x140008dcf  test    rsi, rsi
0x140008dd2  jz      short loc_140008DDF
0x140008dd4  mov     rcx, rsi
0x140008dd7  call    cs:__guard_check_icall_fptr
0x140008ddd  call    rsi
0x140008ddf  add     rbx, 8
0x140008de3  inc     rbp
0x140008de6  cmp     rbp, rdi
0x140008de9  jnz     short loc_140008DCC
0x140008deb  mov     rbx, [rsp+28h+arg_0]
0x140008df0  mov     rbp, [rsp+28h+arg_8]
0x140008df5  mov     rsi, [rsp+28h+arg_10]
0x140008dfa  mov     rdi, [rsp+28h+arg_18]
0x140008dff  add     rsp, 20h
0x140008e03  pop     r14
0x140008e05  retn

// ===== _initterm_e @ 0x140008e08 =====

0x140008e08  mov     [rsp+arg_0], rbx
0x140008e0d  mov     [rsp+arg_8], rsi
0x140008e12  push    rdi
0x140008e13  sub     rsp, 20h
0x140008e17  mov     rsi, rdx
0x140008e1a  mov     rbx, rcx
0x140008e1d  cmp     rcx, rdx
0x140008e20  jz      short loc_140008E42
0x140008e22  mov     rdi, [rbx]
0x140008e25  test    rdi, rdi
0x140008e28  jz      short loc_140008E39
0x140008e2a  mov     rcx, rdi
0x140008e2d  call    cs:__guard_check_icall_fptr
0x140008e33  call    rdi
0x140008e35  test    eax, eax
0x140008e37  jnz     short loc_140008E44
0x140008e39  add     rbx, 8
0x140008e3d  cmp     rbx, rsi
0x140008e40  jmp     short loc_140008E20
0x140008e42  xor     eax, eax
0x140008e44  mov     rbx, [rsp+28h+arg_0]
0x140008e49  mov     rsi, [rsp+28h+arg_8]
0x140008e4e  add     rsp, 20h
0x140008e52  pop     rdi
0x140008e53  retn

// ===== dyntls_init_exception_filter @ 0x140008e54 =====

0x140008e54  xor     eax, eax
0x140008e56  cmp     ecx, 0E06D7363h
0x140008e5c  setz    al
0x140008e5f  retn

// ===== ?common_exit@@YAXHW4_crt_exit_cleanup_mode@@W4_crt_exit_return_mode@@@Z @ 0x140008e60 =====

0x140008e60  mov     rax, rsp
0x140008e63  mov     [rax+8], rbx
0x140008e67  mov     [rax+10h], rsi
0x140008e6b  mov     [rax+18h], rdi
0x140008e6f  mov     [rax+20h], r14
0x140008e73  push    r15
0x140008e75  sub     rsp, 20h
0x140008e79  mov     esi, r8d
0x140008e7c  mov     ebx, edx
0x140008e7e  mov     r14d, ecx
0x140008e81  test    r8d, r8d
0x140008e84  jnz     short loc_140008ED0
0x140008e86  xor     ecx, ecx; lpModuleName
0x140008e88  call    cs:GetModuleHandleW; KERNEL32
0x140008e8e  test    rax, rax
0x140008e91  jz      short loc_140008ED0
0x140008e93  mov     ecx, 5A4Dh
0x140008e98  cmp     [rax], cx
0x140008e9b  jnz     short loc_140008ED0
0x140008e9d  movsxd  rcx, dword ptr [rax+3Ch]
0x140008ea1  add     rcx, rax
0x140008ea4  cmp     dword ptr [rcx], 4550h
0x140008eaa  jnz     short loc_140008ED0
0x140008eac  mov     eax, 20Bh
0x140008eb1  cmp     [rcx+18h], ax
0x140008eb5  jnz     short loc_140008ED0
0x140008eb7  cmp     dword ptr [rcx+84h], 0Eh
0x140008ebe  jbe     short loc_140008ED0
0x140008ec0  cmp     [rcx+0F8h], esi
0x140008ec6  jz      short loc_140008ED0
0x140008ec8  mov     ecx, r14d; unsigned int
0x140008ecb  call    ?try_cor_exit_process@@YAXI@Z
0x140008ed0  mov     ecx, 2
0x140008ed5  call    sub_14000D540
0x140008eda  nop
0x140008edb  cmp     cs:byte_140021770, 0
0x140008ee2  jnz     loc_140008F9A
0x140008ee8  mov     r15d, 1
0x140008eee  mov     eax, r15d
0x140008ef1  xchg    eax, cs:dword_140021764
0x140008ef7  test    ebx, ebx
0x140008ef9  jnz     short loc_140008F43
0x140008efb  mov     rdi, cs:__security_cookie
0x140008f02  mov     edx, edi
0x140008f04  and     edx, 3Fh
0x140008f07  lea     ecx, [rbx+40h]
0x140008f0a  sub     ecx, edx
0x140008f0c  xor     eax, eax
0x140008f0e  ror     rax, cl
0x140008f11  xor     rax, rdi
0x140008f14  mov     rcx, cs:qword_140021768
0x140008f1b  cmp     rcx, rax
0x140008f1e  jz      short loc_140008F3A
0x140008f20  xor     rdi, rcx
0x140008f23  mov     ecx, edx
0x140008f25  ror     rdi, cl
0x140008f28  mov     rcx, rdi
0x140008f2b  call    cs:__guard_check_icall_fptr
0x140008f31  xor     r8d, r8d
0x140008f34  xor     edx, edx
0x140008f36  xor     ecx, ecx
0x140008f38  call    rdi
0x140008f3a  lea     rcx, stru_140021788
0x140008f41  jmp     short loc_140008F4F
0x140008f43  cmp     ebx, r15d
0x140008f46  jnz     short loc_140008F55
0x140008f48  lea     rcx, Table; Table
0x140008f4f  call    _execute_onexit_table
0x140008f54  nop
0x140008f55  test    ebx, ebx
0x140008f57  jnz     short loc_140008F6C
0x140008f59  lea     rdx, qword_140014580; Last
0x140008f60  lea     rcx, qword_140014560; First
0x140008f67  call    _initterm
0x140008f6c  lea     rdx, qword_140014590; Last
0x140008f73  lea     rcx, qword_140014588; First
0x140008f7a  call    _initterm
0x140008f7f  movzx   eax, cs:byte_140021770
0x140008f86  test    esi, esi
0x140008f88  cmovz   eax, r15d
0x140008f8c  mov     cs:byte_140021770, al
0x140008f92  jmp     short loc_140008F9A
0x140008f94  call    terminate
0x140008f9a  mov     ecx, 2
0x140008f9f  call    sub_14000D594
0x140008fa4  test    esi, esi
0x140008fa6  jnz     short loc_140008FB1
0x140008fa8  mov     ecx, r14d; unsigned int
0x140008fab  call    ?exit_or_terminate_process@@YAXI@Z
0x140008fb1  mov     rbx, [rsp+28h+arg_0]
0x140008fb6  mov     rsi, [rsp+28h+arg_8]
0x140008fbb  mov     rdi, [rsp+28h+arg_10]
0x140008fc0  mov     r14, [rsp+28h+arg_18]
0x140008fc5  add     rsp, 20h
0x140008fc9  pop     r15
0x140008fcb  retn
0x14001397e  push    rbp
0x140013980  sub     rsp, 20h
0x140013984  mov     rbp, rdx
0x140013987  mov     rax, [rcx]
0x14001398a  mov     ecx, [rax]
0x14001398c  call    dyntls_init_exception_filter
0x140013991  nop
0x140013992  add     rsp, 20h
0x140013996  pop     rbp
0x140013997  retn
0x140013999  push    rbp; Microsoft VisualC 64bit universal runtime
0x14001399b  sub     rsp, 20h
0x14001399f  mov     rbp, rdx
0x1400139a2  mov     ecx, 2
0x1400139a7  add     rsp, 20h
0x1400139ab  pop     rbp
0x1400139ac  jmp     sub_14000D594

// ===== ?exit_or_terminate_process@@YAXI@Z @ 0x140008fcc =====

0x140008fcc  push    rbx
0x140008fce  sub     rsp, 20h
0x140008fd2  mov     ebx, ecx
0x140008fd4  call    __acrt_is_packaged_app
0x140008fd9  test    al, al
0x140008fdb  jz      short loc_140009005
0x140008fdd  mov     rax, gs:60h
0x140008fe6  mov     edx, [rax+0BCh]
0x140008fec  shr     edx, 8
0x140008fef  test    dl, 1
0x140008ff2  jnz     short loc_140009005
0x140008ff4  call    cs:GetCurrentProcess; KERNEL32
0x140008ffa  mov     rcx, rax; hProcess
0x140008ffd  mov     edx, ebx; uExitCode
0x140008fff  call    cs:TerminateProcess; KERNEL32
0x140009005  mov     ecx, ebx; unsigned int
0x140009007  call    ?try_cor_exit_process@@YAXI@Z
0x14000900c  mov     ecx, ebx; uExitCode
0x14000900e  call    cs:ExitProcess; KERNEL32

// ===== ?try_cor_exit_process@@YAXI@Z @ 0x140009018 =====

0x140009018  mov     [rsp+arg_0], rbx
0x14000901d  push    rdi
0x14000901e  sub     rsp, 20h
0x140009022  and     [rsp+28h+phModule], 0
0x140009028  lea     r8, [rsp+28h+phModule]; phModule
0x14000902d  mov     edi, ecx
0x14000902f  lea     rdx, ModuleName
0x140009036  xor     ecx, ecx; dwFlags
0x140009038  call    cs:GetModuleHandleExW; KERNEL32
0x14000903e  test    eax, eax
0x140009040  jz      short loc_140009069
0x140009042  mov     rcx, [rsp+28h+phModule]; hModule
0x140009047  lea     rdx, aCorexitprocess
0x14000904e  call    cs:GetProcAddress; KERNEL32
0x140009054  mov     rbx, rax
0x140009057  test    rax, rax
0x14000905a  jz      short loc_140009069
0x14000905c  mov     rcx, rax
0x14000905f  call    cs:__guard_check_icall_fptr
0x140009065  mov     ecx, edi
0x140009067  call    rbx
0x140009069  mov     rcx, [rsp+28h+phModule]; hLibModule
0x14000906e  test    rcx, rcx
0x140009071  jz      short loc_140009079
0x140009073  call    cs:FreeLibrary; KERNEL32
0x140009079  mov     rbx, [rsp+28h+arg_0]
0x14000907e  add     rsp, 20h
0x140009082  pop     rdi
0x140009083  retn

// ===== sub_140009084 @ 0x140009084 =====

0x140009084  mov     cs:qword_140021768, rcx
0x14000908b  retn

// ===== _c_exit @ 0x14000908c =====

0x14000908c  mov     edx, 2; enum _crt_exit_cleanup_mode
0x140009091  xor     ecx, ecx; unsigned int
0x140009093  lea     r8d, [rdx-1]; enum _crt_exit_return_mode
0x140009097  jmp     ?common_exit@@YAXHW4_crt_exit_cleanup_mode@@W4_crt_exit_return_mode@@@Z

// ===== _cexit @ 0x14000909c =====

0x14000909c  xor     edx, edx; enum _crt_exit_cleanup_mode
0x14000909e  xor     ecx, ecx; unsigned int
0x1400090a0  lea     r8d, [rdx+1]; enum _crt_exit_return_mode
0x1400090a4  jmp     ?common_exit@@YAXHW4_crt_exit_cleanup_mode@@W4_crt_exit_return_mode@@@Z

// ===== _exit @ 0x1400090ac =====

0x1400090ac  xor     r8d, r8d; enum _crt_exit_return_mode
0x1400090af  lea     edx, [r8+2]; enum _crt_exit_cleanup_mode
0x1400090b3  jmp     ?common_exit@@YAXHW4_crt_exit_cleanup_mode@@W4_crt_exit_return_mode@@@Z

// ===== _register_thread_local_exe_atexit_callback @ 0x1400090b8 =====

0x1400090b8  sub     rsp, 28h
0x1400090bc  mov     r8, cs:__security_cookie
0x1400090c3  mov     rdx, rcx
0x1400090c6  mov     eax, r8d
0x1400090c9  mov     ecx, 40h ; '@'
0x1400090ce  and     eax, 3Fh
0x1400090d1  sub     ecx, eax
0x1400090d3  xor     eax, eax
0x1400090d5  ror     rax, cl
0x1400090d8  xor     rax, r8
0x1400090db  cmp     cs:qword_140021768, rax
0x1400090e2  jnz     short loc_1400090F6
0x1400090e4  ror     rdx, cl
0x1400090e7  xor     rdx, r8
0x1400090ea  mov     cs:qword_140021768, rdx
0x1400090f1  add     rsp, 28h
0x1400090f5  retn
0x1400090f6  call    terminate

// ===== exit @ 0x1400090fc =====

0x1400090fc  xor     r8d, r8d; enum _crt_exit_return_mode
0x1400090ff  xor     edx, edx; enum _crt_exit_cleanup_mode
0x140009101  jmp     ?common_exit@@YAXHW4_crt_exit_cleanup_mode@@W4_crt_exit_return_mode@@@Z

// ===== _set_fmode @ 0x140009108 =====

0x140009108  sub     rsp, 28h
0x14000910c  lea     eax, [rcx-4000h]
0x140009112  test    eax, 0FFFF3FFFh
0x140009117  jnz     short loc_14000912B
0x140009119  cmp     ecx, 0C000h
0x14000911f  jz      short loc_14000912B
0x140009121  xchg    ecx, cs:dword_140022004
0x140009127  xor     eax, eax
0x140009129  jmp     short loc_140009140
0x14000912b  call    _errno
0x140009130  mov     dword ptr [rax], 16h
0x140009136  call    _invalid_parameter_noinfo
0x14000913b  mov     eax, 16h
0x140009140  add     rsp, 28h
0x140009144  retn

// ===== __acrt_set_locale_changed @ 0x140009148 =====

0x140009148  mov     eax, 1
0x14000914d  xchg    eax, cs:dword_140021774
0x140009153  retn

// ===== __acrt_uninitialize_locale @ 0x140009154 =====

0x140009154  push    rdi
0x140009156  sub     rsp, 20h
0x14000915a  lea     rdi, off_1400202C0
0x140009161  cmp     cs:qword_1400217C0, rdi
0x140009168  jz      short loc_140009195
0x14000916a  mov     ecx, 4
0x14000916f  call    sub_14000D540
0x140009174  nop
0x140009175  mov     rdx, rdi
0x140009178  lea     rcx, qword_1400217C0
0x14000917f  call    _updatetlocinfoEx_nolock
0x140009184  mov     cs:qword_1400217C0, rax
0x14000918b  mov     ecx, 4
0x140009190  call    sub_14000D594
0x140009195  add     rsp, 20h
0x140009199  pop     rdi
0x14000919a  retn
0x1400139b2  push    rbp; Microsoft VisualC 64bit universal runtime
0x1400139b4  sub     rsp, 20h
0x1400139b8  mov     rbp, rdx
0x1400139bb  mov     ecx, 4
0x1400139c0  add     rsp, 20h
0x1400139c4  pop     rbp
0x1400139c5  jmp     sub_14000D594

// ===== _configthreadlocale @ 0x14000919c =====

0x14000919c  push    rbx
0x14000919e  sub     rsp, 20h
0x1400091a2  mov     ebx, ecx
0x1400091a4  call    __acrt_getptd
0x1400091a9  mov     r8d, [rax+3A8h]
0x1400091b0  mov     edx, r8d
0x1400091b3  and     dl, 2
0x1400091b6  neg     dl
0x1400091b8  sbb     ecx, ecx
0x1400091ba  cmp     ebx, 0FFFFFFFFh
0x1400091bd  jz      short loc_1400091F5
0x1400091bf  test    ebx, ebx
0x1400091c1  jz      short loc_1400091FC
0x1400091c3  cmp     ebx, 1
0x1400091c6  jz      short loc_1400091E8
0x1400091c8  cmp     ebx, 2
0x1400091cb  jz      short loc_1400091E2
0x1400091cd  call    _errno
0x1400091d2  mov     dword ptr [rax], 16h
0x1400091d8  call    _invalid_parameter_noinfo
0x1400091dd  or      eax, 0FFFFFFFFh
0x1400091e0  jmp     short loc_1400091FF
0x1400091e2  and     r8d, 0FFFFFFFDh
0x1400091e6  jmp     short loc_1400091EC
0x1400091e8  or      r8d, 2
0x1400091ec  mov     [rax+3A8h], r8d
0x1400091f3  jmp     short loc_1400091FC
0x1400091f5  or      cs:dword_140020B30, 0FFFFFFFFh
0x1400091fc  lea     eax, [rcx+2]
0x1400091ff  add     rsp, 20h
0x140009203  pop     rbx
0x140009204  retn

// ===== sub_140009208 @ 0x140009208 =====

0x140009208  mov     eax, cs:dword_140021778
0x14000920e  retn

// ===== _set_new_mode @ 0x140009210 =====

0x140009210  sub     rsp, 28h
0x140009214  cmp     ecx, 1
0x140009217  jbe     short loc_14000922E
0x140009219  call    _errno
0x14000921e  mov     dword ptr [rax], 16h
0x140009224  call    _invalid_parameter_noinfo
0x140009229  or      eax, 0FFFFFFFFh
0x14000922c  jmp     short loc_140009236
0x14000922e  xchg    ecx, cs:dword_140021778
0x140009234  mov     eax, ecx
0x140009236  add     rsp, 28h
0x14000923a  retn

// ===== sub_14000923C @ 0x14000923c =====

0x14000923c  lea     rax, unk_14002177C
0x140009243  retn

// ===== j__free_base @ 0x140009244 =====

0x140009244  jmp     _free_base

// ===== sub_14000924C @ 0x14000924c =====

0x14000924c  mov     cs:qword_140021780, rcx
0x140009253  retn

// ===== _callnewh @ 0x140009254 =====

0x140009254  mov     [rsp+arg_0], rbx
0x140009259  push    rdi
0x14000925a  sub     rsp, 20h
0x14000925e  mov     rdi, rcx
0x140009261  call    _query_new_handler
0x140009266  mov     rbx, rax
0x140009269  test    rax, rax
0x14000926c  jz      short loc_140009287
0x14000926e  mov     rcx, rax
0x140009271  call    cs:__guard_check_icall_fptr
0x140009277  mov     rcx, rdi
0x14000927a  call    rbx
0x14000927c  test    eax, eax
0x14000927e  jz      short loc_140009287
0x140009280  mov     eax, 1
0x140009285  jmp     short loc_140009289
0x140009287  xor     eax, eax
0x140009289  mov     rbx, [rsp+28h+arg_0]
0x14000928e  add     rsp, 20h
0x140009292  pop     rdi
0x140009293  retn

// ===== _query_new_handler @ 0x140009294 =====

0x140009294  push    rbx
0x140009296  sub     rsp, 20h
0x14000929a  xor     ecx, ecx
0x14000929c  call    sub_14000D540
0x1400092a1  nop
0x1400092a2  mov     rbx, cs:__security_cookie
0x1400092a9  mov     ecx, ebx
0x1400092ab  and     ecx, 3Fh
0x1400092ae  xor     rbx, cs:qword_140021780
0x1400092b5  ror     rbx, cl
0x1400092b8  xor     ecx, ecx
0x1400092ba  call    sub_14000D594
0x1400092bf  mov     rax, rbx
0x1400092c2  add     rsp, 20h
0x1400092c6  pop     rbx
0x1400092c7  retn
0x1400139cb  push    rbp; Microsoft VisualC v14 64bit runtime
0x1400139cd  sub     rsp, 20h
0x1400139d1  mov     rbp, rdx
0x1400139d4  xor     ecx, ecx
0x1400139d6  add     rsp, 20h
0x1400139da  pop     rbp
0x1400139db  jmp     sub_14000D594

// ===== j__malloc_base @ 0x1400092c8 =====

0x1400092c8  jmp     _malloc_base

// ===== ??$?RV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@V_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@$$QEAV_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@Z @ 0x1400092d0 =====

0x1400092d0  mov     [rsp+arg_0], rbx
0x1400092d5  mov     [rsp+arg_18], r9
0x1400092da  push    rdi
0x1400092db  sub     rsp, 20h
0x1400092df  mov     rbx, r9
0x1400092e2  mov     rdi, r8
0x1400092e5  mov     ecx, [rdx]
0x1400092e7  call    sub_14000D540
0x1400092ec  nop
0x1400092ed  mov     rcx, rdi
0x1400092f0  call    ??R_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@QEBAHXZ
0x1400092f5  mov     edi, eax
0x1400092f7  mov     ecx, [rbx]
0x1400092f9  call    sub_14000D594
0x1400092fe  mov     eax, edi
0x140009300  mov     rbx, [rsp+28h+arg_0]
0x140009305  add     rsp, 20h
0x140009309  pop     rdi
0x14000930a  retn
0x1400139e1  push    rbp
0x1400139e3  sub     rsp, 20h
0x1400139e7  mov     rbp, rdx
0x1400139ea  mov     rax, [rbp+48h]
0x1400139ee  mov     ecx, [rax]
0x1400139f0  add     rsp, 20h
0x1400139f4  pop     rbp
0x1400139f5  jmp     sub_14000D594

// ===== ??$?RV_lambda_e24bbb7b643b32fcea6fa61b31d4c984_@@AEAV_lambda_275893d493268fdec8709772e3fcec0e_@@V_lambda_9d71df4d7cf3f480f8d633942495c3b0_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_e24bbb7b643b32fcea6fa61b31d4c984_@@AEAV_lambda_275893d493268fdec8709772e3fcec0e_@@$$QEAV_lambda_9d71df4d7cf3f480f8d633942495c3b0_@@@Z @ 0x14000930c =====

0x14000930c  mov     [rsp+arg_0], rbx
0x140009311  mov     [rsp+arg_8], rsi
0x140009316  mov     [rsp+arg_18], r9
0x14000931b  push    rdi
0x14000931c  push    r12
0x14000931e  push    r13
0x140009320  push    r14
0x140009322  push    r15
0x140009324  sub     rsp, 40h
0x140009328  mov     rdi, r9
0x14000932b  mov     r15, r8
0x14000932e  mov     ecx, [rdx]
0x140009330  call    sub_14000D540
0x140009335  nop
0x140009336  mov     rax, [r15]
0x140009339  mov     rdx, [rax]
0x14000933c  test    rdx, rdx
0x14000933f  jnz     short loc_14000934A
0x140009341  or      rbx, 0FFFFFFFFFFFFFFFFh
0x140009345  jmp     loc_14000948A
0x14000934a  mov     rsi, cs:__security_cookie
0x140009351  mov     r8d, esi
0x140009354  and     r8d, 3Fh
0x140009358  mov     rdi, rsi
0x14000935b  xor     rdi, [rdx]
0x14000935e  mov     ecx, r8d
0x140009361  ror     rdi, cl
0x140009364  mov     [rsp+68h+var_38], rdi
0x140009369  mov     rbx, rsi
0x14000936c  xor     rbx, [rdx+8]
0x140009370  ror     rbx, cl
0x140009373  mov     [rsp+68h+var_48], rbx
0x140009378  lea     rax, [rdi-1]
0x14000937c  cmp     rax, 0FFFFFFFFFFFFFFFDh
0x140009380  ja      loc_140009480
0x140009386  mov     r12, rdi
0x140009389  mov     [rsp+68h+var_40], rdi
0x14000938e  mov     r14, rbx
0x140009391  mov     [rsp+68h+var_30], rbx
0x140009396  mov     r13d, 40h ; '@'
0x14000939c  mov     ecx, r13d
0x14000939f  sub     ecx, r8d
0x1400093a2  xor     eax, eax
0x1400093a4  ror     rax, cl
0x1400093a7  xor     rax, rsi
0x1400093aa  sub     rbx, 8
0x1400093ae  mov     [rsp+68h+var_48], rbx
0x1400093b3  cmp     rbx, rdi
0x1400093b6  jb      short loc_1400093C4
0x1400093b8  cmp     [rbx], rax
0x1400093bb  jnz     short loc_1400093BF
0x1400093bd  jmp     short loc_1400093AA
0x1400093bf  cmp     rbx, rdi
0x1400093c2  jnb     short loc_14000940E
0x1400093c4  or      rbx, 0FFFFFFFFFFFFFFFFh
0x1400093c8  cmp     rdi, rbx
0x1400093cb  jz      short loc_1400093DC
0x1400093cd  mov     rcx, rdi; Block
0x1400093d0  call    _free_base
0x1400093d5  mov     rsi, cs:__security_cookie
0x1400093dc  mov     eax, esi
0x1400093de  and     eax, 3Fh
0x1400093e1  sub     r13d, eax
0x1400093e4  mov     ecx, r13d
0x1400093e7  xor     edx, edx
0x1400093e9  ror     rdx, cl
0x1400093ec  xor     rdx, rsi
0x1400093ef  mov     rax, [r15]
0x1400093f2  mov     rcx, [rax]
0x1400093f5  mov     [rcx], rdx
0x1400093f8  mov     rax, [r15]
0x1400093fb  mov     rcx, [rax]
0x1400093fe  mov     [rcx+8], rdx
0x140009402  mov     rax, [r15]
0x140009405  mov     rcx, [rax]
0x140009408  mov     [rcx+10h], rdx
0x14000940c  jmp     short loc_140009480
0x14000940e  mov     ecx, esi
0x140009410  and     ecx, 3Fh
0x140009413  xor     rsi, [rbx]
0x140009416  ror     rsi, cl
0x140009419  mov     [rbx], rax
0x14000941c  mov     rcx, rsi
0x14000941f  call    cs:__guard_check_icall_fptr
0x140009425  call    rsi
0x140009427  mov     rax, [r15]
0x14000942a  mov     rdx, [rax]
0x14000942d  mov     rsi, cs:__security_cookie
0x140009434  mov     r8d, esi
0x140009437  and     r8d, 3Fh
0x14000943b  mov     r9, rsi
0x14000943e  xor     r9, [rdx]
0x140009441  mov     ecx, r8d
0x140009444  ror     r9, cl
0x140009447  mov     rax, [rdx+8]
0x14000944b  xor     rax, rsi
0x14000944e  ror     rax, cl
0x140009451  cmp     r9, r12
0x140009454  jnz     short loc_14000945B
0x140009456  cmp     rax, r14
0x140009459  jz      short loc_14000947B
0x14000945b  mov     r12, r9
0x14000945e  mov     [rsp+68h+var_40], r9
0x140009463  mov     rdi, r9
0x140009466  mov     [rsp+68h+var_38], r9
0x14000946b  mov     r14, rax
0x14000946e  mov     [rsp+68h+var_30], rax
0x140009473  mov     rbx, rax
0x140009476  mov     [rsp+68h+var_48], rax
0x14000947b  jmp     loc_14000939C
0x140009480  mov     rdi, [rsp+68h+arg_18]
0x140009488  xor     ebx, ebx
0x14000948a  mov     ecx, [rdi]
0x14000948c  call    sub_14000D594
0x140009491  mov     eax, ebx
0x140009493  mov     rbx, [rsp+68h+arg_0]
0x140009498  mov     rsi, [rsp+68h+arg_8]
0x14000949d  add     rsp, 40h
0x1400094a1  pop     r15
0x1400094a3  pop     r14
0x1400094a5  pop     r13
0x1400094a7  pop     r12
0x1400094a9  pop     rdi
0x1400094aa  retn
0x1400139fb  push    rbp
0x1400139fd  sub     rsp, 20h
0x140013a01  mov     rbp, rdx
0x140013a04  mov     rax, [rbp+88h]
0x140013a0b  mov     ecx, [rax]
0x140013a0d  add     rsp, 20h
0x140013a11  pop     rbp
0x140013a12  jmp     sub_14000D594

// ===== ??R_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@QEBAHXZ @ 0x1400094ac =====

0x1400094ac  mov     rax, rsp
0x1400094af  mov     [rax+8], rbx
0x1400094b3  mov     [rax+10h], rbp
0x1400094b7  mov     [rax+18h], rsi
0x1400094bb  mov     [rax+20h], rdi
0x1400094bf  push    r12
0x1400094c1  push    r14
0x1400094c3  push    r15
0x1400094c5  sub     rsp, 20h
0x1400094c9  mov     rax, [rcx]
0x1400094cc  xor     esi, esi
0x1400094ce  mov     r15, rcx
0x1400094d1  mov     rbx, [rax]
0x1400094d4  test    rbx, rbx
0x1400094d7  jnz     short loc_1400094E1
0x1400094d9  or      eax, 0FFFFFFFFh
0x1400094dc  jmp     loc_140009667
0x1400094e1  mov     r8, cs:__security_cookie
0x1400094e8  mov     r12d, 40h ; '@'
0x1400094ee  mov     rbp, [rbx]
0x1400094f1  mov     ecx, r8d
0x1400094f4  mov     r9, [rbx+8]
0x1400094f8  and     ecx, 3Fh
0x1400094fb  mov     rbx, [rbx+10h]
0x1400094ff  xor     rbp, r8
0x140009502  xor     r9, r8
0x140009505  ror     rbp, cl
0x140009508  xor     rbx, r8
0x14000950b  ror     r9, cl
0x14000950e  ror     rbx, cl
0x140009511  cmp     r9, rbx
0x140009514  jnz     loc_1400095E1
0x14000951a  sub     rbx, rbp
0x14000951d  mov     eax, 200h
0x140009522  sar     rbx, 3
0x140009526  cmp     rbx, rax
0x140009529  mov     rdi, rbx
0x14000952c  cmova   rdi, rax
0x140009530  lea     eax, [r12-20h]
0x140009535  add     rdi, rbx
0x140009538  cmovz   rdi, rax
0x14000953c  cmp     rdi, rbx
0x14000953f  jb      short loc_140009560
0x140009541  lea     r8d, [r12-38h]; Size
0x140009546  mov     rdx, rdi; Count
0x140009549  mov     rcx, rbp; Block
0x14000954c  call    j__recalloc_base
0x140009551  xor     ecx, ecx; Block
0x140009553  mov     r14, rax
0x140009556  call    _free_base
0x14000955b  test    r14, r14
0x14000955e  jnz     short loc_140009588
0x140009560  lea     rdi, [rbx+4]
0x140009564  mov     r8d, 8; Size
0x14000956a  mov     rdx, rdi; Count
0x14000956d  mov     rcx, rbp; Block
0x140009570  call    j__recalloc_base
0x140009575  xor     ecx, ecx; Block
0x140009577  mov     r14, rax
0x14000957a  call    _free_base
0x14000957f  test    r14, r14
0x140009582  jz      loc_1400094D9
0x140009588  mov     r8, cs:__security_cookie
0x14000958f  lea     r9, [r14+rbx*8]
0x140009593  mov     eax, r8d
0x140009596  lea     rbx, [r14+rdi*8]
0x14000959a  and     eax, 3Fh
0x14000959d  mov     ecx, r12d
0x1400095a0  sub     ecx, eax
0x1400095a2  mov     rdx, rsi
0x1400095a5  ror     rdx, cl
0x1400095a8  mov     rax, rbx
0x1400095ab  sub     rax, r9
0x1400095ae  xor     rdx, r8
0x1400095b1  add     rax, 7
0x1400095b5  mov     rbp, r14
0x1400095b8  shr     rax, 3
0x1400095bc  mov     rcx, r9
0x1400095bf  cmp     r9, rbx
0x1400095c2  cmova   rax, rsi
0x1400095c6  test    rax, rax
0x1400095c9  jz      short loc_1400095E1
0x1400095cb  inc     rsi
0x1400095ce  mov     [rcx], rdx
0x1400095d1  lea     rcx, [rcx+8]
0x1400095d5  cmp     rsi, rax
0x1400095d8  jnz     short loc_1400095CB
0x1400095da  mov     r8, cs:__security_cookie
0x1400095e1  mov     eax, r8d
0x1400095e4  mov     ecx, r12d
0x1400095e7  and     eax, 3Fh
0x1400095ea  sub     ecx, eax
0x1400095ec  mov     rax, [r15+8]
0x1400095f0  mov     rdx, [rax]
0x1400095f3  mov     eax, r12d
0x1400095f6  ror     rdx, cl
0x1400095f9  xor     rdx, r8
0x1400095fc  lea     r8, [r9+8]
0x140009600  mov     [r9], rdx
0x140009603  mov     rdx, cs:__security_cookie
0x14000960a  mov     ecx, edx
0x14000960c  and     ecx, 3Fh
0x14000960f  sub     eax, ecx
0x140009611  mov     cl, al
0x140009613  mov     rax, [r15]
0x140009616  ror     rbp, cl
0x140009619  xor     rbp, rdx
0x14000961c  mov     rcx, [rax]
0x14000961f  mov     [rcx], rbp
0x140009622  mov     ecx, r12d
0x140009625  mov     rdx, cs:__security_cookie
0x14000962c  mov     eax, edx
0x14000962e  and     eax, 3Fh
0x140009631  sub     ecx, eax
0x140009633  mov     rax, [r15]
0x140009636  ror     r8, cl
0x140009639  xor     r8, rdx
0x14000963c  mov     rdx, [rax]
0x14000963f  mov     [rdx+8], r8
0x140009643  mov     rdx, cs:__security_cookie
0x14000964a  mov     eax, edx
0x14000964c  and     eax, 3Fh
0x14000964f  sub     r12d, eax
0x140009652  mov     rax, [r15]
0x140009655  mov     cl, r12b
0x140009658  ror     rbx, cl
0x14000965b  xor     rbx, rdx
0x14000965e  mov     rcx, [rax]
0x140009661  xor     eax, eax
0x140009663  mov     [rcx+10h], rbx
0x140009667  mov     rbx, [rsp+38h+arg_0]
0x14000966c  mov     rbp, [rsp+38h+arg_8]
0x140009671  mov     rsi, [rsp+38h+arg_10]
0x140009676  mov     rdi, [rsp+38h+arg_18]
0x14000967b  add     rsp, 20h
0x14000967f  pop     r15
0x140009681  pop     r14
0x140009683  pop     r12
0x140009685  retn

// ===== sub_140009688 @ 0x140009688 =====

0x140009688  mov     rdx, rcx; Function
0x14000968b  lea     rcx, stru_140021788; Table
0x140009692  jmp     _register_onexit_function

// ===== _execute_onexit_table @ 0x140009698 =====

0x140009698  mov     r11, rsp
0x14000969b  mov     [r11+8], rcx
0x14000969f  sub     rsp, 38h
0x1400096a3  lea     rax, [r11+8]
0x1400096a7  mov     [r11-18h], rax
0x1400096ab  lea     r9, [r11+18h]
0x1400096af  mov     eax, 2
0x1400096b4  lea     r8, [r11-18h]
0x1400096b8  lea     rdx, [r11+20h]
0x1400096bc  mov     [rsp+38h+arg_10], eax
0x1400096c0  lea     rcx, [r11+10h]
0x1400096c4  mov     [rsp+38h+arg_18], eax
0x1400096c8  call    ??$?RV_lambda_e24bbb7b643b32fcea6fa61b31d4c984_@@AEAV_lambda_275893d493268fdec8709772e3fcec0e_@@V_lambda_9d71df4d7cf3f480f8d633942495c3b0_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_e24bbb7b643b32fcea6fa61b31d4c984_@@AEAV_lambda_275893d493268fdec8709772e3fcec0e_@@$$QEAV_lambda_9d71df4d7cf3f480f8d633942495c3b0_@@@Z
0x1400096cd  add     rsp, 38h
0x1400096d1  retn

// ===== _initialize_onexit_table @ 0x1400096d4 =====

0x1400096d4  xor     r9d, r9d
0x1400096d7  mov     r8, rcx
0x1400096da  test    rcx, rcx
0x1400096dd  jnz     short loc_1400096E3
0x1400096df  or      eax, 0FFFFFFFFh
0x1400096e2  retn
0x1400096e3  mov     rax, [rcx+10h]
0x1400096e7  cmp     [rcx], rax
0x1400096ea  jnz     short loc_140009710
0x1400096ec  mov     rdx, cs:__security_cookie
0x1400096f3  mov     ecx, 40h ; '@'
0x1400096f8  mov     eax, edx
0x1400096fa  and     eax, 3Fh
0x1400096fd  sub     ecx, eax
0x1400096ff  ror     r9, cl
0x140009702  xor     r9, rdx
0x140009705  mov     [r8], r9
0x140009708  mov     [r8+8], r9
0x14000970c  mov     [r8+10h], r9
0x140009710  xor     eax, eax
0x140009712  retn

// ===== _register_onexit_function @ 0x140009714 =====

0x140009714  mov     [rsp-8+arg_8], rdx
0x140009719  mov     [rsp-8+arg_0], rcx
0x14000971e  push    rbp
0x14000971f  mov     rbp, rsp
0x140009722  sub     rsp, 40h
0x140009726  lea     rax, [rbp+arg_0]
0x14000972a  mov     [rbp+var_18], rax
0x14000972e  lea     r9, [rbp+arg_18]
0x140009732  lea     rax, [rbp+arg_8]
0x140009736  mov     [rbp+var_10], rax
0x14000973a  lea     r8, [rbp+var_18]
0x14000973e  mov     eax, 2
0x140009743  lea     rdx, [rbp+var_20]
0x140009747  lea     rcx, [rbp+arg_10]
0x14000974b  mov     [rbp+arg_18], eax
0x14000974e  mov     [rbp+var_20], eax
0x140009751  call    ??$?RV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@V_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b8c45f8f788dd370798f47cfe8ac3a86_@@AEAV_lambda_4e60a939b0d047cfe11ddc22648dfba9_@@$$QEAV_lambda_332c3edc96d0294ec56c57d38c1cdfd5_@@@Z
0x140009756  add     rsp, 40h
0x14000975a  pop     rbp
0x14000975b  retn

// ===== initialize_global_variables @ 0x14000975c =====

0x14000975c  lea     rax, off_1400202C0
0x140009763  mov     cs:qword_1400217C0, rax
0x14000976a  mov     al, 1
0x14000976c  retn

// ===== initialize_c @ 0x140009770 =====

0x140009770  sub     rsp, 28h
0x140009774  lea     rcx, stru_140021788; Table
0x14000977b  call    _initialize_onexit_table
0x140009780  lea     rcx, Table; Table
0x140009787  call    _initialize_onexit_table
0x14000978c  mov     al, 1
0x14000978e  add     rsp, 28h
0x140009792  retn

// ===== uninitialize_environment @ 0x140009794 =====

0x140009794  sub     rsp, 28h
0x140009798  call    __dcrt_uninitialize_environments_nolock
0x14000979d  mov     al, 1
0x14000979f  add     rsp, 28h
0x1400097a3  retn

// ===== initialize_pointers @ 0x1400097a4 =====

0x1400097a4  push    rbx
0x1400097a6  sub     rsp, 20h
0x1400097aa  mov     rdx, cs:__security_cookie
0x1400097b1  mov     ecx, 40h ; '@'
0x1400097b6  mov     eax, edx
0x1400097b8  xor     ebx, ebx
0x1400097ba  and     eax, 3Fh
0x1400097bd  sub     ecx, eax
0x1400097bf  ror     rbx, cl
0x1400097c2  xor     rbx, rdx
0x1400097c5  mov     rcx, rbx
0x1400097c8  call    sub_14000A3CC
0x1400097cd  mov     rcx, rbx
0x1400097d0  call    sub_14000924C
0x1400097d5  mov     rcx, rbx
0x1400097d8  call    __acrt_initialize_signal_handlers
0x1400097dd  mov     rcx, rbx
0x1400097e0  call    sub_140008730
0x1400097e5  mov     rcx, rbx
0x1400097e8  call    sub_140009084
0x1400097ed  mov     al, 1
0x1400097ef  add     rsp, 20h
0x1400097f3  pop     rbx
0x1400097f4  retn

// ===== sub_1400097F8 @ 0x1400097f8 =====

0x1400097f8  xor     ecx, ecx
0x1400097fa  jmp     __vcrt_uninitialize

// ===== uninitialize_allocated_memory @ 0x140009800 =====

0x140009800  push    rbx
0x140009802  sub     rsp, 20h
0x140009806  mov     rcx, cs:Block
0x14000980d  or      eax, 0FFFFFFFFh
0x140009810  lock xadd [rcx], eax
0x140009814  cmp     eax, 1
0x140009817  jnz     short loc_140009838
0x140009819  mov     rcx, cs:Block; Block
0x140009820  lea     rbx, unk_140020540
0x140009827  cmp     rcx, rbx
0x14000982a  jz      short loc_140009838
0x14000982c  call    _free_base
0x140009831  mov     cs:Block, rbx
0x140009838  mov     rcx, cs:qword_1400217E0; Block
0x14000983f  call    _free_base
0x140009844  mov     rcx, cs:qword_1400217E8; Block
0x14000984b  xor     ebx, ebx
0x14000984d  mov     cs:qword_1400217E0, rbx
0x140009854  call    _free_base
0x140009859  mov     rcx, cs:qword_140021C20; Block
0x140009860  mov     cs:qword_1400217E8, rbx
0x140009867  call    _free_base
0x14000986c  mov     rcx, cs:qword_140021C28; Block
0x140009873  mov     cs:qword_140021C20, rbx
0x14000987a  call    _free_base
0x14000987f  mov     al, 1
0x140009881  mov     cs:qword_140021C28, rbx
0x140009888  add     rsp, 20h
0x14000988c  pop     rbx
0x14000988d  retn

// ===== __acrt_initialize @ 0x140009890 =====

0x140009890  lea     rdx, dword_140015AB0
0x140009897  lea     rcx, off_1400159C0
0x14000989e  jmp     __acrt_execute_initializers

// ===== __acrt_uninitialize @ 0x1400098a4 =====

0x1400098a4  lea     rdx, dword_140015AB0
0x1400098ab  lea     rcx, off_1400159C0
0x1400098b2  jmp     __acrt_execute_uninitializers

// ===== terminate @ 0x1400098b8 =====

0x1400098b8  push    rbx
0x1400098ba  sub     rsp, 20h
0x1400098be  call    __acrt_getptd
0x1400098c3  mov     rbx, [rax+18h]
0x1400098c7  test    rbx, rbx
0x1400098ca  jz      short loc_1400098D9
0x1400098cc  mov     rcx, rbx
0x1400098cf  call    cs:__guard_check_icall_fptr
0x1400098d5  call    rbx
0x1400098d7  jmp     short $+2
0x1400098d9  call    abort

// ===== _fclose_nolock @ 0x1400098e0 =====

0x1400098e0  mov     [rsp+arg_0], rbx
0x1400098e5  push    rdi
0x1400098e6  sub     rsp, 20h
0x1400098ea  mov     rbx, rcx
0x1400098ed  test    rcx, rcx
0x1400098f0  jnz     short loc_140009907
0x1400098f2  call    _errno
0x1400098f7  mov     dword ptr [rax], 16h
0x1400098fd  call    _invalid_parameter_noinfo
0x140009902  or      eax, 0FFFFFFFFh
0x140009905  jmp     short loc_140009958
0x140009907  or      edi, 0FFFFFFFFh
0x14000990a  mov     eax, [rcx+14h]
0x14000990d  shr     eax, 0Dh
0x140009910  test    al, 1
0x140009912  jz      short loc_14000994E
0x140009914  call    __acrt_stdio_flush_nolock
0x140009919  mov     rcx, rbx
0x14000991c  mov     edi, eax
0x14000991e  call    __acrt_stdio_free_buffer_nolock
0x140009923  mov     rcx, rbx; Stream
0x140009926  call    _fileno
0x14000992b  mov     ecx, eax
0x14000992d  call    sub_14000ED48
0x140009932  test    eax, eax
0x140009934  jns     short loc_14000993B
0x140009936  or      edi, 0FFFFFFFFh
0x140009939  jmp     short loc_14000994E
0x14000993b  mov     rcx, [rbx+28h]; Block
0x14000993f  test    rcx, rcx
0x140009942  jz      short loc_14000994E
0x140009944  call    _free_base
0x140009949  and     qword ptr [rbx+28h], 0
0x14000994e  mov     rcx, rbx
0x140009951  call    ?__acrt_stdio_free_stream@@YAXV__crt_stdio_stream@@@Z
0x140009956  mov     eax, edi
0x140009958  mov     rbx, [rsp+28h+arg_0]
0x14000995d  add     rsp, 20h
0x140009961  pop     rdi
0x140009962  retn

// ===== fclose @ 0x140009964 =====

0x140009964  mov     [rsp+arg_8], rbx
0x140009969  mov     [rsp+arg_0], rcx
0x14000996e  push    rdi
0x14000996f  sub     rsp, 20h
0x140009973  mov     rbx, rcx
0x140009976  xor     eax, eax
0x140009978  test    rcx, rcx
0x14000997b  setnz   al
0x14000997e  test    eax, eax
0x140009980  jnz     short loc_140009997
0x140009982  call    _errno
0x140009987  mov     dword ptr [rax], 16h
0x14000998d  call    _invalid_parameter_noinfo
0x140009992  or      eax, 0FFFFFFFFh
0x140009995  jmp     short loc_1400099C2
0x140009997  mov     eax, [rcx+14h]
0x14000999a  shr     eax, 0Ch
0x14000999d  test    al, 1
0x14000999f  jz      short loc_1400099A8
0x1400099a1  call    ?__acrt_stdio_free_stream@@YAXV__crt_stdio_stream@@@Z
0x1400099a6  jmp     short loc_140009992
0x1400099a8  call    sub_14000C0C8
0x1400099ad  nop
0x1400099ae  mov     rcx, rbx; Stream
0x1400099b1  call    _fclose_nolock
0x1400099b6  mov     edi, eax
0x1400099b8  mov     rcx, rbx
0x1400099bb  call    sub_14000C0D4
0x1400099c0  mov     eax, edi
0x1400099c2  mov     rbx, [rsp+28h+arg_8]
0x1400099c7  add     rsp, 20h
0x1400099cb  pop     rdi
0x1400099cc  retn
0x140013a18  push    rbp; Microsoft VisualC 64bit universal runtime
0x140013a1a  sub     rsp, 20h
0x140013a1e  mov     rbp, rdx
0x140013a21  mov     rcx, [rbp+30h]
0x140013a25  add     rsp, 20h
0x140013a29  pop     rbp
0x140013a2a  jmp     sub_14000C0D4

// ===== _fileno @ 0x1400099d0 =====

0x1400099d0  sub     rsp, 28h
0x1400099d4  test    rcx, rcx
0x1400099d7  jnz     short loc_1400099EE
0x1400099d9  call    _errno
0x1400099de  mov     dword ptr [rax], 16h
0x1400099e4  call    _invalid_parameter_noinfo
0x1400099e9  or      eax, 0FFFFFFFFh
0x1400099ec  jmp     short loc_1400099F1
0x1400099ee  mov     eax, [rcx+18h]
0x1400099f1  add     rsp, 28h
0x1400099f5  retn

// ===== strcpy_s @ 0x1400099f8 =====

0x1400099f8  push    rbx
0x1400099fa  sub     rsp, 20h
0x1400099fe  xor     ebx, ebx
0x140009a00  test    rcx, rcx
0x140009a03  jz      short loc_140009A11
0x140009a05  test    rdx, rdx
0x140009a08  jz      short loc_140009A11
0x140009a0a  test    r8, r8
0x140009a0d  jnz     short loc_140009A2A
0x140009a0f  mov     [rcx], bl
0x140009a11  call    _errno
0x140009a16  mov     ebx, 16h
0x140009a1b  mov     [rax], ebx
0x140009a1d  call    _invalid_parameter_noinfo
0x140009a22  mov     eax, ebx
0x140009a24  add     rsp, 20h
0x140009a28  pop     rbx
0x140009a29  retn
0x140009a2a  mov     r9, rcx
0x140009a2d  sub     r8, rcx
0x140009a30  mov     al, [r8+r9]
0x140009a34  mov     [r9], al
0x140009a37  inc     r9
0x140009a3a  test    al, al
0x140009a3c  jz      short loc_140009A44
0x140009a3e  sub     rdx, 1
0x140009a42  jnz     short loc_140009A30
0x140009a44  test    rdx, rdx
0x140009a47  jnz     short loc_140009A22
0x140009a49  mov     [rcx], bl
0x140009a4b  call    _errno
0x140009a50  mov     ebx, 22h ; '"'
0x140009a55  jmp     short loc_140009A1B

// ===== abort @ 0x140009a58 =====

0x140009a58  sub     rsp, 28h
0x140009a5c  call    __acrt_get_sigabrt_handler
0x140009a61  test    rax, rax
0x140009a64  jz      short loc_140009A70
0x140009a66  mov     ecx, 16h; Signal
0x140009a6b  call    raise
0x140009a70  test    cs:byte_1400202A0, 2
0x140009a77  jz      short loc_140009AA2
0x140009a79  mov     ecx, 17h; ProcessorFeature
0x140009a7e  call    IsProcessorFeaturePresent
0x140009a83  test    eax, eax
0x140009a85  jz      short loc_140009A8E
0x140009a87  mov     ecx, 7
0x140009a8c  int     29h; Win8: RtlFailFast(ecx)
0x140009a8e  mov     r8d, 1
0x140009a94  mov     edx, 40000015h
0x140009a99  lea     ecx, [r8+2]
0x140009a9d  call    __acrt_call_reportfault
0x140009aa2  mov     ecx, 3; Code
0x140009aa7  call    _exit

// ===== wcsncmp @ 0x140009ab0 =====

0x140009ab0  test    r8, r8
0x140009ab3  jnz     short loc_140009ACD
0x140009ab5  xor     eax, eax
0x140009ab7  retn
0x140009ab8  movzx   eax, word ptr [rcx]
0x140009abb  test    ax, ax
0x140009abe  jz      short loc_140009AD3
0x140009ac0  cmp     ax, [rdx]
0x140009ac3  jnz     short loc_140009AD3
0x140009ac5  add     rcx, 2
0x140009ac9  add     rdx, 2
0x140009acd  sub     r8, 1
0x140009ad1  jnz     short loc_140009AB8
0x140009ad3  movzx   eax, word ptr [rcx]
0x140009ad6  movzx   ecx, word ptr [rdx]
0x140009ad9  sub     eax, ecx
0x140009adb  retn

// ===== ??$is_overflow_condition@K@__crt_strtox@@YA_NIK@Z @ 0x140009adc =====

0x140009adc  test    cl, 4
0x140009adf  jz      short loc_140009AE4
0x140009ae1  mov     al, 1
0x140009ae3  retn
0x140009ae4  test    cl, 1
0x140009ae7  jz      short loc_140009B02
0x140009ae9  and     ecx, 2
0x140009aec  jz      short loc_140009AF6
0x140009aee  cmp     edx, 80000000h
0x140009af4  ja      short loc_140009AE1
0x140009af6  test    ecx, ecx
0x140009af8  jnz     short loc_140009B02
0x140009afa  cmp     edx, 7FFFFFFFh
0x140009b00  ja      short loc_140009AE1
0x140009b02  xor     al, al
0x140009b04  retn

// ===== ??$parse_integer@KV?$c_string_character_source@_W@__crt_strtox@@@__crt_strtox@@YAKQEAU__crt_locale_pointers@@V?$c_string_character_source@_W@0@H_N@Z @ 0x140009b08 =====

0x140009b08  mov     [rsp+arg_0], rbx
0x140009b0d  mov     [rsp+arg_10], rbp
0x140009b12  mov     [rsp+arg_18], rsi
0x140009b17  push    rdi
0x140009b18  push    r12
0x140009b1a  push    r13
0x140009b1c  push    r14
0x140009b1e  push    r15
0x140009b20  sub     rsp, 50h
0x140009b24  xor     r13d, r13d
0x140009b27  mov     sil, r9b
0x140009b2a  mov     r15d, r8d
0x140009b2d  mov     rdi, rdx
0x140009b30  cmp     [rdx], r13
0x140009b33  jnz     short loc_140009B5B
0x140009b35  call    _errno
0x140009b3a  mov     dword ptr [rax], 16h
0x140009b40  call    _invalid_parameter_noinfo
0x140009b45  mov     rcx, [rdi+8]
0x140009b49  test    rcx, rcx
0x140009b4c  jz      short loc_140009B54
0x140009b4e  mov     rax, [rdi]
0x140009b51  mov     [rcx], rax
0x140009b54  xor     eax, eax
0x140009b56  jmp     loc_14000A1BE
0x140009b5b  test    r8d, r8d
0x140009b5e  jz      short loc_140009B69
0x140009b60  lea     eax, [r8-2]
0x140009b64  cmp     eax, 22h ; '"'
0x140009b67  ja      short loc_140009B35
0x140009b69  mov     rdx, rcx; struct __crt_locale_pointers *
0x140009b6c  lea     rcx, [rsp+78h+var_50]; this
0x140009b71  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x140009b76  mov     r12, [rdi]
0x140009b79  mov     r14d, r13d
0x140009b7c  mov     [rsp+78h+var_58], r12
0x140009b81  mov     ebp, 8
0x140009b86  movzx   ebx, word ptr [r12]
0x140009b8b  lea     rax, [r12+2]
0x140009b90  jmp     short loc_140009B9C
0x140009b92  mov     rax, [rdi]
0x140009b95  movzx   ebx, word ptr [rax]
0x140009b98  add     rax, 2
0x140009b9c  mov     edx, ebp; Type
0x140009b9e  mov     [rdi], rax
0x140009ba1  movzx   ecx, bx; C
0x140009ba4  call    iswctype
0x140009ba9  test    eax, eax
0x140009bab  jnz     short loc_140009B92
0x140009bad  test    sil, sil
0x140009bb0  mov     ebp, r13d
0x140009bb3  setnz   bpl
0x140009bb7  cmp     bx, 2Dh ; '-'
0x140009bbb  jnz     short loc_140009BC2
0x140009bbd  or      ebp, 2
0x140009bc0  jmp     short loc_140009BC8
0x140009bc2  cmp     bx, 2Bh ; '+'
0x140009bc6  jnz     short loc_140009BD5
0x140009bc8  mov     rax, [rdi]
0x140009bcb  movzx   ebx, word ptr [rax]
0x140009bce  add     rax, 2
0x140009bd2  mov     [rdi], rax
0x140009bd5  mov     esi, 9E6h
0x140009bda  mov     [rsp+78h+arg_8], 66Ah
0x140009be5  or      r9d, 0FFFFFFFFh
0x140009be9  mov     ecx, 660h
0x140009bee  mov     r10d, 30h ; '0'
0x140009bf4  mov     r11d, 0FF10h
0x140009bfa  mov     edx, 6F0h
0x140009bff  mov     eax, 0A66h
0x140009c04  lea     r8d, [rsi-80h]
0x140009c08  test    r15d, 0FFFFFFEFh
0x140009c0f  jnz     loc_140009E94
0x140009c15  cmp     bx, r10w
0x140009c19  jb      loc_140009DE9
0x140009c1f  cmp     bx, 3Ah ; ':'
0x140009c23  jnb     short loc_140009C30
0x140009c25  movzx   eax, bx
0x140009c28  sub     eax, r10d
0x140009c2b  jmp     loc_140009DE4
0x140009c30  cmp     bx, r11w
0x140009c34  jnb     loc_140009DCF
0x140009c3a  cmp     bx, cx
0x140009c3d  jb      loc_140009DE9
0x140009c43  cmp     bx, word ptr [rsp+78h+arg_8]
0x140009c4b  jnb     short loc_140009C57
0x140009c4d  movzx   eax, bx
0x140009c50  sub     eax, ecx
0x140009c52  jmp     loc_140009DE4
0x140009c57  cmp     bx, dx
0x140009c5a  jb      loc_140009DE9
0x140009c60  mov     ecx, 6FAh
0x140009c65  cmp     bx, cx
0x140009c68  jnb     short loc_140009C74
0x140009c6a  movzx   eax, bx
0x140009c6d  sub     eax, edx
0x140009c6f  jmp     loc_140009DE4
0x140009c74  cmp     bx, r8w
0x140009c78  jb      loc_140009DE9
0x140009c7e  mov     ecx, 970h
0x140009c83  cmp     bx, cx
0x140009c86  jnb     short loc_140009C93
0x140009c88  movzx   eax, bx
0x140009c8b  sub     eax, r8d
0x140009c8e  jmp     loc_140009DE4
0x140009c93  cmp     bx, si
0x140009c96  jb      loc_140009DE9
0x140009c9c  mov     ecx, 9F0h
0x140009ca1  cmp     bx, cx
0x140009ca4  jnb     short loc_140009CB0
0x140009ca6  movzx   eax, bx
0x140009ca9  sub     eax, esi
0x140009cab  jmp     loc_140009DE4
0x140009cb0  cmp     bx, ax
0x140009cb3  jb      loc_140009DE9
0x140009cb9  mov     eax, 0A70h
0x140009cbe  cmp     bx, ax
0x140009cc1  jnb     short loc_140009CD0
0x140009cc3  movzx   eax, bx
0x140009cc6  sub     eax, 0A66h
0x140009ccb  jmp     loc_140009DE4
0x140009cd0  mov     ecx, 0AE6h
0x140009cd5  cmp     bx, cx
0x140009cd8  jb      loc_140009DE9
0x140009cde  lea     eax, [rcx+0Ah]
0x140009ce1  cmp     bx, ax
0x140009ce4  jb      loc_140009C4D
0x140009cea  lea     ecx, [rax+76h]
0x140009ced  cmp     bx, cx
0x140009cf0  jb      loc_140009DE9
0x140009cf6  lea     eax, [rcx+0Ah]
0x140009cf9  cmp     bx, ax
0x140009cfc  jb      loc_140009C4D
0x140009d02  mov     ecx, 0C66h
0x140009d07  cmp     bx, cx
0x140009d0a  jb      loc_140009DE9
0x140009d10  lea     eax, [rcx+0Ah]
0x140009d13  cmp     bx, ax
0x140009d16  jb      loc_140009C4D
0x140009d1c  lea     ecx, [rax+76h]
0x140009d1f  cmp     bx, cx
0x140009d22  jb      loc_140009DE9
0x140009d28  lea     eax, [rcx+0Ah]
0x140009d2b  cmp     bx, ax
0x140009d2e  jb      loc_140009C4D
0x140009d34  lea     ecx, [rax+76h]
0x140009d37  cmp     bx, cx
0x140009d3a  jb      loc_140009DE9
0x140009d40  lea     eax, [rcx+0Ah]
0x140009d43  cmp     bx, ax
0x140009d46  jb      loc_140009C4D
0x140009d4c  mov     ecx, 0E50h
0x140009d51  cmp     bx, cx
0x140009d54  jb      loc_140009DE9
0x140009d5a  lea     eax, [rcx+0Ah]
0x140009d5d  cmp     bx, ax
0x140009d60  jb      loc_140009C4D
0x140009d66  lea     ecx, [rax+76h]
0x140009d69  cmp     bx, cx
0x140009d6c  jb      short loc_140009DE9
0x140009d6e  lea     eax, [rcx+0Ah]
0x140009d71  cmp     bx, ax
0x140009d74  jb      loc_140009C4D
0x140009d7a  lea     ecx, [rax+46h]
0x140009d7d  cmp     bx, cx
0x140009d80  jb      short loc_140009DE9
0x140009d82  lea     eax, [rcx+0Ah]
0x140009d85  cmp     bx, ax
0x140009d88  jb      loc_140009C4D
0x140009d8e  mov     ecx, 1040h
0x140009d93  cmp     bx, cx
0x140009d96  jb      short loc_140009DE9
0x140009d98  lea     eax, [rcx+0Ah]
0x140009d9b  cmp     bx, ax
0x140009d9e  jb      loc_140009C4D
0x140009da4  mov     ecx, 17E0h
0x140009da9  cmp     bx, cx
0x140009dac  jb      short loc_140009DE9
0x140009dae  lea     eax, [rcx+0Ah]
0x140009db1  cmp     bx, ax
0x140009db4  jb      loc_140009C4D
0x140009dba  lea     ecx, [rax+26h]
0x140009dbd  cmp     bx, cx
0x140009dc0  jb      short loc_140009DE9
0x140009dc2  lea     eax, [rcx+0Ah]
0x140009dc5  cmp     bx, ax
0x140009dc8  jnb     short loc_140009DE9
0x140009dca  jmp     loc_140009C4D
0x140009dcf  mov     eax, 0FF1Ah
0x140009dd4  cmp     bx, ax
0x140009dd7  jnb     short loc_140009DE1
0x140009dd9  movzx   eax, bx
0x140009ddc  sub     eax, r11d
0x140009ddf  jmp     short loc_140009DE4
0x140009de1  or      eax, 0FFFFFFFFh
0x140009de4  cmp     eax, 0FFFFFFFFh
0x140009de7  jnz     short loc_140009E12
0x140009de9  lea     eax, [rbx-41h]
0x140009dec  cmp     ax, 19h
0x140009df0  jbe     short loc_140009E00
0x140009df2  lea     eax, [rbx-61h]
0x140009df5  cmp     ax, 19h
0x140009df9  jbe     short loc_140009E00
0x140009dfb  mov     eax, r9d
0x140009dfe  jmp     short loc_140009E12
0x140009e00  lea     eax, [rbx-61h]
0x140009e03  cmp     ax, 19h
0x140009e07  movzx   eax, bx
0x140009e0a  ja      short loc_140009E0F
0x140009e0c  sub     eax, 20h ; ' '
0x140009e0f  add     eax, 0FFFFFFC9h
0x140009e12  mov     esi, 8
0x140009e17  test    eax, eax
0x140009e19  jz      short loc_140009E26
0x140009e1b  test    r15d, r15d
0x140009e1e  jnz     short loc_140009E99
0x140009e20  lea     r15d, [rsi+2]
0x140009e24  jmp     short loc_140009E99
0x140009e26  mov     rax, [rdi]
0x140009e29  mov     r8d, 0FFDFh
0x140009e2f  movzx   edx, word ptr [rax]
0x140009e32  lea     rcx, [rax+2]
0x140009e36  mov     [rdi], rcx
0x140009e39  lea     eax, [rdx-58h]
0x140009e3c  test    r8w, ax
0x140009e40  jz      short loc_140009E7C
0x140009e42  test    r15d, r15d
0x140009e45  cmovz   r15d, esi
0x140009e49  add     rcx, 0FFFFFFFFFFFFFFFEh
0x140009e4d  mov     [rdi], rcx
0x140009e50  test    dx, dx
0x140009e53  jz      short loc_140009E99
0x140009e55  cmp     [rcx], dx
0x140009e58  jz      short loc_140009E99
0x140009e5a  call    _errno
0x140009e5f  mov     dword ptr [rax], 16h
0x140009e65  call    _invalid_parameter_noinfo
0x140009e6a  or      r9d, 0FFFFFFFFh
0x140009e6e  mov     r10d, 30h ; '0'
0x140009e74  mov     r11d, 0FF10h
0x140009e7a  jmp     short loc_140009E99
0x140009e7c  movzx   ebx, word ptr [rcx]
0x140009e7f  mov     eax, 10h
0x140009e84  test    r15d, r15d
0x140009e87  cmovz   r15d, eax
0x140009e8b  lea     rax, [rcx+2]
0x140009e8f  mov     [rdi], rax
0x140009e92  jmp     short loc_140009E99
0x140009e94  mov     esi, 8
0x140009e99  xor     edx, edx
0x140009e9b  mov     eax, r9d
0x140009e9e  div     r15d
0x140009ea1  mov     r13d, 660h
0x140009ea7  mov     r12d, 6F0h
0x140009ead  mov     r8d, eax
0x140009eb0  cmp     bx, r10w
0x140009eb4  jb      loc_14000A068
0x140009eba  cmp     bx, 3Ah ; ':'
0x140009ebe  jnb     short loc_140009ECB
0x140009ec0  movzx   ecx, bx
0x140009ec3  sub     ecx, r10d
0x140009ec6  jmp     loc_14000A063
0x140009ecb  cmp     bx, r11w
0x140009ecf  jnb     loc_14000A04E
0x140009ed5  cmp     bx, r13w
0x140009ed9  jb      loc_14000A068
0x140009edf  mov     eax, 66Ah
0x140009ee4  cmp     bx, ax
0x140009ee7  jnb     short loc_140009EF4
0x140009ee9  movzx   ecx, bx
0x140009eec  sub     ecx, r13d
0x140009eef  jmp     loc_14000A063
0x140009ef4  cmp     bx, r12w
0x140009ef8  jb      loc_14000A068
0x140009efe  mov     eax, 6FAh
0x140009f03  cmp     bx, ax
0x140009f06  jnb     short loc_140009F13
0x140009f08  movzx   ecx, bx
0x140009f0b  sub     ecx, r12d
0x140009f0e  jmp     loc_14000A063
0x140009f13  mov     eax, 966h
0x140009f18  cmp     bx, ax
0x140009f1b  jb      loc_14000A068
0x140009f21  lea     ecx, [rax+0Ah]
0x140009f24  cmp     bx, cx
0x140009f27  jnb     short loc_140009F33
0x140009f29  movzx   ecx, bx
0x140009f2c  sub     ecx, eax
0x140009f2e  jmp     loc_14000A063
0x140009f33  mov     eax, 9E6h
0x140009f38  cmp     bx, ax
0x140009f3b  jb      loc_14000A068
0x140009f41  lea     ecx, [rax+0Ah]
0x140009f44  cmp     bx, cx
0x140009f47  jb      short loc_140009F29
0x140009f49  lea     eax, [rcx+76h]
0x140009f4c  cmp     bx, ax
0x140009f4f  jb      loc_14000A068
0x140009f55  lea     ecx, [rax+0Ah]
0x140009f58  cmp     bx, cx
0x140009f5b  jb      short loc_140009F29
0x140009f5d  lea     eax, [rcx+76h]
0x140009f60  cmp     bx, ax
0x140009f63  jb      loc_14000A068
0x140009f69  lea     ecx, [rax+0Ah]
0x140009f6c  cmp     bx, cx
0x140009f6f  jb      short loc_140009F29
0x140009f71  lea     eax, [rcx+76h]
0x140009f74  cmp     bx, ax
0x140009f77  jb      loc_14000A068
0x140009f7d  lea     ecx, [rax+0Ah]
0x140009f80  cmp     bx, cx
0x140009f83  jb      short loc_140009F29
0x140009f85  mov     eax, 0C66h
0x140009f8a  cmp     bx, ax
0x140009f8d  jb      loc_14000A068
0x140009f93  lea     ecx, [rax+0Ah]
0x140009f96  cmp     bx, cx
0x140009f99  jb      short loc_140009F29
0x140009f9b  lea     eax, [rcx+76h]
0x140009f9e  cmp     bx, ax
0x140009fa1  jb      loc_14000A068
0x140009fa7  lea     ecx, [rax+0Ah]
0x140009faa  cmp     bx, cx
0x140009fad  jb      loc_140009F29
0x140009fb3  lea     eax, [rcx+76h]
0x140009fb6  cmp     bx, ax
0x140009fb9  jb      loc_14000A068
0x140009fbf  lea     ecx, [rax+0Ah]
0x140009fc2  cmp     bx, cx
0x140009fc5  jb      loc_140009F29
0x140009fcb  mov     eax, 0E50h
0x140009fd0  cmp     bx, ax
0x140009fd3  jb      loc_14000A068
0x140009fd9  lea     ecx, [rax+0Ah]
0x140009fdc  cmp     bx, cx
0x140009fdf  jb      loc_140009F29
0x140009fe5  lea     eax, [rcx+76h]
0x140009fe8  cmp     bx, ax
0x140009feb  jb      short loc_14000A068
0x140009fed  lea     ecx, [rax+0Ah]
0x140009ff0  cmp     bx, cx
0x140009ff3  jb      loc_140009F29
0x140009ff9  lea     eax, [rcx+46h]
0x140009ffc  cmp     bx, ax
0x140009fff  jb      short loc_14000A068
0x14000a001  lea     ecx, [rax+0Ah]
0x14000a004  cmp     bx, cx
0x14000a007  jb      loc_140009F29
0x14000a00d  mov     eax, 1040h
0x14000a012  cmp     bx, ax
0x14000a015  jb      short loc_14000A068
0x14000a017  lea     ecx, [rax+0Ah]
0x14000a01a  cmp     bx, cx
0x14000a01d  jb      loc_140009F29
0x14000a023  mov     eax, 17E0h
0x14000a028  cmp     bx, ax
0x14000a02b  jb      short loc_14000A068
0x14000a02d  lea     ecx, [rax+0Ah]
0x14000a030  cmp     bx, cx
0x14000a033  jb      loc_140009F29
0x14000a039  lea     eax, [rcx+26h]
0x14000a03c  cmp     bx, ax
0x14000a03f  jb      short loc_14000A068
0x14000a041  lea     ecx, [rax+0Ah]
0x14000a044  cmp     bx, cx
0x14000a047  jnb     short loc_14000A068
0x14000a049  jmp     loc_140009F29
0x14000a04e  mov     eax, 0FF1Ah
0x14000a053  cmp     bx, ax
0x14000a056  jnb     short loc_14000A060
0x14000a058  movzx   ecx, bx
0x14000a05b  sub     ecx, r11d
0x14000a05e  jmp     short loc_14000A063
0x14000a060  or      ecx, 0FFFFFFFFh
0x14000a063  cmp     ecx, 0FFFFFFFFh
0x14000a066  jnz     short loc_14000A091
0x14000a068  lea     eax, [rbx-41h]
0x14000a06b  cmp     ax, 19h
0x14000a06f  jbe     short loc_14000A07F
0x14000a071  lea     eax, [rbx-61h]
0x14000a074  cmp     ax, 19h
0x14000a078  jbe     short loc_14000A07F
0x14000a07a  mov     ecx, r9d
0x14000a07d  jmp     short loc_14000A091
0x14000a07f  lea     eax, [rbx-61h]
0x14000a082  movzx   ecx, bx
0x14000a085  cmp     ax, 19h
0x14000a089  ja      short loc_14000A08E
0x14000a08b  sub     ecx, 20h ; ' '
0x14000a08e  add     ecx, 0FFFFFFC9h
0x14000a091  cmp     ecx, r9d
0x14000a094  jz      short loc_14000A0C6
0x14000a096  cmp     ecx, r15d
0x14000a099  jnb     short loc_14000A0C6
0x14000a09b  or      ebp, esi
0x14000a09d  cmp     r14d, r8d
0x14000a0a0  jb      short loc_14000A0AD
0x14000a0a2  jnz     short loc_14000A0A8
0x14000a0a4  cmp     ecx, edx
0x14000a0a6  jbe     short loc_14000A0AD
0x14000a0a8  or      ebp, 4
0x14000a0ab  jmp     short loc_14000A0B4
0x14000a0ad  imul    r14d, r15d
0x14000a0b1  add     r14d, ecx
0x14000a0b4  mov     rax, [rdi]
0x14000a0b7  movzx   ebx, word ptr [rax]
0x14000a0ba  add     rax, 2
0x14000a0be  mov     [rdi], rax
0x14000a0c1  jmp     loc_140009EB0
0x14000a0c6  add     qword ptr [rdi], 0FFFFFFFFFFFFFFFEh
0x14000a0ca  xor     r13d, r13d
0x14000a0cd  mov     rax, [rdi]
0x14000a0d0  mov     r12, [rsp+78h+var_58]
0x14000a0d5  test    bx, bx
0x14000a0d8  jz      short loc_14000A0EF
0x14000a0da  cmp     [rax], bx
0x14000a0dd  jz      short loc_14000A0EF
0x14000a0df  call    _errno
0x14000a0e4  mov     dword ptr [rax], 16h
0x14000a0ea  call    _invalid_parameter_noinfo
0x14000a0ef  test    sil, bpl
0x14000a0f2  jnz     short loc_14000A113
0x14000a0f4  mov     [rdi], r12
0x14000a0f7  cmp     [rsp+78h+var_38], r13b
0x14000a0fc  jz      loc_140009B45
0x14000a102  mov     rax, [rsp+78h+var_50]
0x14000a107  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x14000a10e  jmp     loc_140009B45
0x14000a113  mov     edx, r14d
0x14000a116  mov     ecx, ebp
0x14000a118  call    ??$is_overflow_condition@K@__crt_strtox@@YA_NIK@Z
0x14000a11d  test    al, al
0x14000a11f  jz      short loc_14000A190
0x14000a121  call    _errno
0x14000a126  mov     dword ptr [rax], 22h ; '"'
0x14000a12c  test    bpl, 1
0x14000a130  jnz     short loc_14000A138
0x14000a132  or      r14d, 0FFFFFFFFh
0x14000a136  jmp     short loc_14000A199
0x14000a138  test    bpl, 2
0x14000a13c  jz      short loc_14000A167
0x14000a13e  cmp     [rsp+78h+var_38], r13b
0x14000a143  jz      short loc_14000A151
0x14000a145  mov     rax, [rsp+78h+var_50]
0x14000a14a  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x14000a151  mov     rcx, [rdi+8]
0x14000a155  test    rcx, rcx
0x14000a158  jz      short loc_14000A160
0x14000a15a  mov     rax, [rdi]
0x14000a15d  mov     [rcx], rax
0x14000a160  mov     eax, 80000000h
0x14000a165  jmp     short loc_14000A1BE
0x14000a167  cmp     [rsp+78h+var_38], r13b
0x14000a16c  jz      short loc_14000A17A
0x14000a16e  mov     rax, [rsp+78h+var_50]
0x14000a173  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x14000a17a  mov     rcx, [rdi+8]
0x14000a17e  test    rcx, rcx
0x14000a181  jz      short loc_14000A189
0x14000a183  mov     rax, [rdi]
0x14000a186  mov     [rcx], rax
0x14000a189  mov     eax, 7FFFFFFFh
0x14000a18e  jmp     short loc_14000A1BE
0x14000a190  test    bpl, 2
0x14000a194  jz      short loc_14000A199
0x14000a196  neg     r14d
0x14000a199  cmp     [rsp+78h+var_38], r13b
0x14000a19e  jz      short loc_14000A1AC
0x14000a1a0  mov     rcx, [rsp+78h+var_50]
0x14000a1a5  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x14000a1ac  mov     rdx, [rdi+8]
0x14000a1b0  test    rdx, rdx
0x14000a1b3  jz      short loc_14000A1BB
0x14000a1b5  mov     rcx, [rdi]
0x14000a1b8  mov     [rdx], rcx
0x14000a1bb  mov     eax, r14d
0x14000a1be  lea     r11, [rsp+78h+var_28]
0x14000a1c3  mov     rbx, [r11+30h]
0x14000a1c7  mov     rbp, [r11+40h]
0x14000a1cb  mov     rsi, [r11+48h]
0x14000a1cf  mov     rsp, r11
0x14000a1d2  pop     r15
0x14000a1d4  pop     r14
0x14000a1d6  pop     r13
0x14000a1d8  pop     r12
0x14000a1da  pop     rdi
0x14000a1db  retn

// ===== strncmp @ 0x14000a1f0 =====

0x14000a1f0  sub     rdx, rcx
0x14000a1f3  test    r8, r8
0x14000a1f6  jz      short return_equal
0x14000a1f8  test    ecx, 7
0x14000a1fe  jz      short _qword_loop_enter
0x14000a200  movzx   eax, byte ptr [rcx]
0x14000a203  cmp     al, [rcx+rdx]
0x14000a206  jnz     short return_not_equal
0x14000a208  inc     rcx
0x14000a20b  dec     r8
0x14000a20e  jz      short return_equal
0x14000a210  test    al, al
0x14000a212  jz      short return_equal
0x14000a214  test    rcx, 7
0x14000a21b  jnz     short comp_head_loop_begin
0x14000a21d  mov     r11, 8080808080808080h
0x14000a227  mov     r10, 0FEFEFEFEFEFEFEFFh
0x14000a231  lea     eax, [rcx+rdx]
0x14000a234  and     eax, 0FFFh
0x14000a239  cmp     eax, 0FF8h
0x14000a23e  ja      short comp_head_loop_begin
0x14000a240  mov     rax, [rcx]
0x14000a243  cmp     rax, [rcx+rdx]
0x14000a247  jnz     short comp_head_loop_begin
0x14000a249  add     rcx, 8
0x14000a24d  sub     r8, 8
0x14000a251  jbe     short return_equal
0x14000a253  lea     r9, [rax+r10]
0x14000a257  not     rax
0x14000a25a  and     rax, r9
0x14000a25d  test    r11, rax
0x14000a260  jz      short _qword_loop_begin
0x14000a262  xor     eax, eax
0x14000a264  retn
0x14000a265  sbb     rax, rax
0x14000a268  or      rax, 1
0x14000a26c  retn

// ===== __acrt_call_reportfault @ 0x14000a270 =====

0x14000a270  mov     [rsp-8+arg_8], rbx
0x14000a275  mov     [rsp-8+arg_10], rsi
0x14000a27a  push    rbp
0x14000a27b  push    rdi
0x14000a27c  push    r14
0x14000a27e  lea     rbp, [rsp-4F0h]
0x14000a286  sub     rsp, 5F0h
0x14000a28d  mov     rax, cs:__security_cookie
0x14000a294  xor     rax, rsp
0x14000a297  mov     [rbp+500h+var_20], rax
0x14000a29e  mov     edi, r8d
0x14000a2a1  mov     esi, edx
0x14000a2a3  mov     ebx, ecx
0x14000a2a5  cmp     ecx, 0FFFFFFFFh
0x14000a2a8  jz      short loc_14000A2AF
0x14000a2aa  call    sub_140004788
0x14000a2af  xor     edx, edx
0x14000a2b1  lea     rcx, [rsp+600h+var_590]
0x14000a2b6  mov     r8d, 98h
0x14000a2bc  call    sub_140005B30
0x14000a2c1  xor     edx, edx
0x14000a2c3  lea     rcx, [rbp+500h+ContextRecord]
0x14000a2c7  mov     r8d, 4D0h
0x14000a2cd  call    sub_140005B30
0x14000a2d2  lea     rax, [rsp+600h+var_590]
0x14000a2d7  mov     [rsp+600h+ExceptionInfo.ExceptionRecord], rax
0x14000a2dc  lea     rcx, [rbp+500h+ContextRecord]; ContextRecord
0x14000a2e0  lea     rax, [rbp+500h+ContextRecord]
0x14000a2e4  mov     [rsp+600h+ExceptionInfo.ContextRecord], rax
0x14000a2e9  call    cs:RtlCaptureContext; KERNEL32
0x14000a2ef  mov     r14, [rbp+500h+ContextRecord.Rip]
0x14000a2f6  lea     rdx, [rsp+600h+ImageBase]; ImageBase
0x14000a2fb  mov     rcx, r14; ControlPc
0x14000a2fe  xor     r8d, r8d; HistoryTable
0x14000a301  call    cs:RtlLookupFunctionEntry; KERNEL32
0x14000a307  test    rax, rax
0x14000a30a  jz      short loc_14000A342
0x14000a30c  and     [rsp+600h+var_5C8], 0
0x14000a312  lea     rcx, [rsp+600h+var_5A0]
0x14000a317  mov     rdx, [rsp+600h+ImageBase]; ImageBase
0x14000a31c  mov     r9, rax; FunctionEntry
0x14000a31f  mov     [rsp+600h+EstablisherFrame], rcx; EstablisherFrame
0x14000a324  mov     r8, r14; ControlPc
0x14000a327  lea     rcx, [rsp+600h+var_5A8]
0x14000a32c  mov     [rsp+600h+HandlerData], rcx; HandlerData
0x14000a331  lea     rcx, [rbp+500h+ContextRecord]
0x14000a335  mov     [rsp+600h+var_5E0], rcx; ContextRecord
0x14000a33a  xor     ecx, ecx; HandlerType
0x14000a33c  call    cs:RtlVirtualUnwind; KERNEL32
0x14000a342  mov     rax, [rbp+508h]
0x14000a349  mov     [rbp+500h+ContextRecord.Rip], rax
0x14000a350  lea     rax, [rbp+508h]
0x14000a357  add     rax, 8
0x14000a35b  mov     [rsp+600h+var_590], esi
0x14000a35f  mov     [rbp+500h+ContextRecord.Rsp], rax
0x14000a366  mov     rax, [rbp+508h]
0x14000a36d  mov     [rbp+500h+var_580], rax
0x14000a371  mov     [rsp+600h+var_58C], edi
0x14000a375  call    cs:IsDebuggerPresent; KERNEL32
0x14000a37b  xor     ecx, ecx; lpTopLevelExceptionFilter
0x14000a37d  mov     edi, eax
0x14000a37f  call    cs:SetUnhandledExceptionFilter; KERNEL32
0x14000a385  lea     rcx, [rsp+600h+ExceptionInfo]; ExceptionInfo
0x14000a38a  call    cs:UnhandledExceptionFilter; KERNEL32
0x14000a390  test    eax, eax
0x14000a392  jnz     short loc_14000A3A4
0x14000a394  test    edi, edi
0x14000a396  jnz     short loc_14000A3A4
0x14000a398  cmp     ebx, 0FFFFFFFFh
0x14000a39b  jz      short loc_14000A3A4
0x14000a39d  mov     ecx, ebx
0x14000a39f  call    sub_140004788
0x14000a3a4  mov     rcx, [rbp+500h+var_20]
0x14000a3ab  xor     rcx, rsp; StackCookie
0x14000a3ae  call    __security_check_cookie
0x14000a3b3  lea     r11, [rsp+600h+var_10]
0x14000a3bb  mov     rbx, [r11+28h]
0x14000a3bf  mov     rsi, [r11+30h]
0x14000a3c3  mov     rsp, r11
0x14000a3c6  pop     r14
0x14000a3c8  pop     rdi
0x14000a3c9  pop     rbp
0x14000a3ca  retn

// ===== sub_14000A3CC @ 0x14000a3cc =====

0x14000a3cc  mov     cs:qword_1400217B8, rcx
0x14000a3d3  retn

// ===== _invalid_parameter @ 0x14000a3d4 =====

0x14000a3d4  mov     rax, rsp
0x14000a3d7  mov     [rax+8], rbx
0x14000a3db  mov     [rax+10h], rbp
0x14000a3df  mov     [rax+18h], rsi
0x14000a3e3  mov     [rax+20h], rdi
0x14000a3e7  push    r14
0x14000a3e9  sub     rsp, 30h
0x14000a3ed  mov     edi, r9d
0x14000a3f0  mov     rsi, r8
0x14000a3f3  mov     rbp, rdx
0x14000a3f6  mov     r14, rcx
0x14000a3f9  call    __acrt_getptd_noexit
0x14000a3fe  test    rax, rax
0x14000a401  jz      short loc_14000A444
0x14000a403  mov     rbx, [rax+3B8h]
0x14000a40a  test    rbx, rbx
0x14000a40d  jz      short loc_14000A444
0x14000a40f  mov     rcx, rbx
0x14000a412  call    cs:__guard_check_icall_fptr
0x14000a418  mov     r9d, edi
0x14000a41b  mov     r8, rsi
0x14000a41e  mov     rdx, rbp
0x14000a421  mov     rcx, r14
0x14000a424  mov     rax, rbx
0x14000a427  mov     rbx, [rsp+38h+arg_0]
0x14000a42c  mov     rbp, [rsp+38h+arg_8]
0x14000a431  mov     rsi, [rsp+38h+arg_10]
0x14000a436  mov     rdi, [rsp+38h+arg_18]
0x14000a43b  add     rsp, 30h
0x14000a43f  pop     r14
0x14000a441  jmp     rax
0x14000a444  mov     rbx, cs:__security_cookie
0x14000a44b  mov     ecx, ebx
0x14000a44d  xor     rbx, cs:qword_1400217B8
0x14000a454  and     ecx, 3Fh
0x14000a457  ror     rbx, cl
0x14000a45a  test    rbx, rbx
0x14000a45d  jnz     short loc_14000A40F
0x14000a45f  mov     rax, [rsp+38h+arg_20]
0x14000a464  mov     r9d, edi; LineNo
0x14000a467  mov     r8, rsi; FileName
0x14000a46a  mov     [rsp+38h+Reserved], rax; Reserved
0x14000a46f  mov     rdx, rbp; FunctionName
0x14000a472  mov     rcx, r14; Expression
0x14000a475  call    _invoke_watson

// ===== _invalid_parameter_noinfo @ 0x14000a47c =====

0x14000a47c  sub     rsp, 38h
0x14000a480  and     [rsp+38h+var_18], 0
0x14000a486  xor     r9d, r9d; LineNo
0x14000a489  xor     r8d, r8d; FileName
0x14000a48c  xor     edx, edx; FunctionName
0x14000a48e  xor     ecx, ecx; Expression
0x14000a490  call    _invalid_parameter
0x14000a495  add     rsp, 38h
0x14000a499  retn

// ===== _invoke_watson @ 0x14000a49c =====

0x14000a49c  sub     rsp, 28h
0x14000a4a0  mov     ecx, 17h; ProcessorFeature
0x14000a4a5  call    IsProcessorFeaturePresent
0x14000a4aa  test    eax, eax
0x14000a4ac  jz      short loc_14000A4B5
0x14000a4ae  mov     ecx, 5
0x14000a4b3  int     29h; Win8: RtlFailFast(ecx)
0x14000a4b5  mov     r8d, 1
0x14000a4bb  mov     edx, 0C0000417h
0x14000a4c0  lea     ecx, [r8+1]
0x14000a4c4  call    __acrt_call_reportfault
0x14000a4c9  call    cs:GetCurrentProcess; KERNEL32
0x14000a4cf  mov     rcx, rax
0x14000a4d2  mov     edx, 0C0000417h
0x14000a4d7  add     rsp, 28h
0x14000a4db  jmp     cs:TerminateProcess; KERNEL32

// ===== __acrt_errno_from_os_error @ 0x14000a4e4 =====

0x14000a4e4  xor     eax, eax
0x14000a4e6  lea     r9, dword_140015AB0
0x14000a4ed  mov     rdx, r9
0x14000a4f0  lea     r8d, [rax+8]
0x14000a4f4  cmp     ecx, [rdx]
0x14000a4f6  jz      short loc_14000A523
0x14000a4f8  inc     eax
0x14000a4fa  add     rdx, r8
0x14000a4fd  cmp     eax, 2Dh ; '-'
0x14000a500  jb      short loc_14000A4F4
0x14000a502  lea     eax, [rcx-13h]
0x14000a505  cmp     eax, 11h
0x14000a508  ja      short loc_14000A510
0x14000a50a  mov     eax, 0Dh
0x14000a50f  retn
0x14000a510  add     ecx, 0FFFFFF44h
0x14000a516  mov     eax, 16h
0x14000a51b  cmp     ecx, 0Eh
0x14000a51e  cmovbe  eax, r8d
0x14000a522  retn
0x14000a523  mov     eax, [r9+rax*8+4]
0x14000a528  retn

// ===== __acrt_errno_map_os_error @ 0x14000a52c =====

0x14000a52c  mov     [rsp+arg_0], rbx
0x14000a531  push    rdi
0x14000a532  sub     rsp, 20h
0x14000a536  mov     edi, ecx
0x14000a538  call    __acrt_getptd_noexit
0x14000a53d  test    rax, rax
0x14000a540  jnz     short loc_14000A54B
0x14000a542  lea     rax, unk_1400202B4
0x14000a549  jmp     short loc_14000A54F
0x14000a54b  add     rax, 24h ; '$'
0x14000a54f  mov     [rax], edi
0x14000a551  call    __acrt_getptd_noexit
0x14000a556  lea     rbx, unk_1400202B0
0x14000a55d  test    rax, rax
0x14000a560  jz      short loc_14000A566
0x14000a562  lea     rbx, [rax+20h]
0x14000a566  mov     ecx, edi
0x14000a568  call    __acrt_errno_from_os_error
0x14000a56d  mov     [rbx], eax
0x14000a56f  mov     rbx, [rsp+28h+arg_0]
0x14000a574  add     rsp, 20h
0x14000a578  pop     rdi
0x14000a579  retn

// ===== __doserrno @ 0x14000a57c =====

0x14000a57c  sub     rsp, 28h
0x14000a580  call    __acrt_getptd_noexit
0x14000a585  test    rax, rax
0x14000a588  jnz     short loc_14000A593
0x14000a58a  lea     rax, unk_1400202B4
0x14000a591  jmp     short loc_14000A597
0x14000a593  add     rax, 24h ; '$'
0x14000a597  add     rsp, 28h
0x14000a59b  retn

// ===== _errno @ 0x14000a59c =====

0x14000a59c  sub     rsp, 28h
0x14000a5a0  call    __acrt_getptd_noexit
0x14000a5a5  test    rax, rax
0x14000a5a8  jnz     short loc_14000A5B3
0x14000a5aa  lea     rax, unk_1400202B0
0x14000a5b1  jmp     short loc_14000A5B7
0x14000a5b3  add     rax, 20h ; ' '
0x14000a5b7  add     rsp, 28h
0x14000a5bb  retn

// ===== _towlower_l @ 0x14000a5bc =====

0x14000a5bc  mov     [rsp-8+arg_0], cx
0x14000a5c1  push    rbp
0x14000a5c2  mov     rbp, rsp
0x14000a5c5  sub     rsp, 50h
0x14000a5c9  mov     eax, 0FFFFh
0x14000a5ce  cmp     cx, ax
0x14000a5d1  jz      loc_14000A67A
0x14000a5d7  lea     rcx, [rbp+var_20]; this
0x14000a5db  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000a5e0  mov     rax, [rbp+var_18]
0x14000a5e4  mov     r10, [rax+138h]
0x14000a5eb  test    r10, r10
0x14000a5ee  jnz     short loc_14000A603
0x14000a5f0  movzx   edx, [rbp+arg_0]
0x14000a5f4  lea     eax, [rdx-41h]
0x14000a5f7  cmp     ax, 19h
0x14000a5fb  ja      short loc_14000A666
0x14000a5fd  add     dx, 20h ; ' '
0x14000a601  jmp     short loc_14000A666
0x14000a603  movzx   ecx, [rbp+arg_0]; C
0x14000a607  mov     edx, 100h
0x14000a60c  cmp     cx, dx
0x14000a60f  jnb     short loc_14000A63A
0x14000a611  mov     edx, 1; Type
0x14000a616  call    iswctype
0x14000a61b  test    eax, eax
0x14000a61d  jnz     short loc_14000A625
0x14000a61f  movzx   edx, [rbp+arg_0]
0x14000a623  jmp     short loc_14000A666
0x14000a625  mov     rax, [rbp+var_18]
0x14000a629  movzx   edx, [rbp+arg_0]
0x14000a62d  mov     rcx, [rax+110h]
0x14000a634  movzx   edx, byte ptr [rcx+rdx]
0x14000a638  jmp     short loc_14000A666
0x14000a63a  mov     r9d, 1
0x14000a640  lea     rax, [rbp+arg_10]
0x14000a644  mov     [rsp+50h+var_28], r9d
0x14000a649  lea     r8, [rbp+arg_0]
0x14000a64d  mov     rcx, r10
0x14000a650  mov     [rsp+50h+var_30], rax
0x14000a655  call    __crtLCMapStringW
0x14000a65a  movzx   edx, [rbp+arg_0]
0x14000a65e  test    eax, eax
0x14000a660  jz      short loc_14000A666
0x14000a662  movzx   edx, [rbp+arg_10]
0x14000a666  cmp     [rbp+var_8], 0
0x14000a66a  jz      short loc_14000A677
0x14000a66c  mov     rcx, [rbp+var_20]
0x14000a670  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x14000a677  movzx   eax, dx
0x14000a67a  add     rsp, 50h
0x14000a67e  pop     rbp
0x14000a67f  retn

// ===== ??$?RV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@V_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@$$QEAV_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@Z @ 0x14000a680 =====

0x14000a680  mov     [rsp+arg_0], rbx
0x14000a685  mov     [rsp+arg_18], r9
0x14000a68a  push    rdi
0x14000a68b  sub     rsp, 20h
0x14000a68f  mov     rbx, r9
0x14000a692  mov     rdi, r8
0x14000a695  mov     ecx, [rdx]
0x14000a697  call    sub_14000D540
0x14000a69c  nop
0x14000a69d  mov     rax, [rdi]
0x14000a6a0  mov     rcx, [rax]
0x14000a6a3  mov     rcx, [rcx+88h]; Block
0x14000a6aa  test    rcx, rcx
0x14000a6ad  jz      short loc_14000A6CD
0x14000a6af  or      eax, 0FFFFFFFFh
0x14000a6b2  lock xadd [rcx], eax
0x14000a6b6  cmp     eax, 1
0x14000a6b9  jnz     short loc_14000A6CD
0x14000a6bb  lea     rax, unk_140020540
0x14000a6c2  cmp     rcx, rax
0x14000a6c5  jz      short loc_14000A6CD
0x14000a6c7  call    _free_base
0x14000a6cc  nop
0x14000a6cd  mov     ecx, [rbx]
0x14000a6cf  call    sub_14000D594
0x14000a6d4  mov     rbx, [rsp+28h+arg_0]
0x14000a6d9  add     rsp, 20h
0x14000a6dd  pop     rdi
0x14000a6de  retn
0x1400139e1  push    rbp
0x1400139e3  sub     rsp, 20h
0x1400139e7  mov     rbp, rdx
0x1400139ea  mov     rax, [rbp+48h]
0x1400139ee  mov     ecx, [rax]
0x1400139f0  add     rsp, 20h
0x1400139f4  pop     rbp
0x1400139f5  jmp     sub_14000D594

// ===== ??$?RV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@V_lambda_341c25c0346d94847f1f3c463c57e077_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@$$QEAV_lambda_341c25c0346d94847f1f3c463c57e077_@@@Z @ 0x14000a6e0 =====

0x14000a6e0  mov     [rsp+arg_0], rbx
0x14000a6e5  mov     [rsp+arg_18], r9
0x14000a6ea  push    rdi
0x14000a6eb  sub     rsp, 20h
0x14000a6ef  mov     rbx, r9
0x14000a6f2  mov     rdi, r8
0x14000a6f5  mov     ecx, [rdx]
0x14000a6f7  call    sub_14000D540
0x14000a6fc  nop
0x14000a6fd  mov     rax, [rdi+8]
0x14000a701  mov     rdx, [rax]
0x14000a704  mov     rcx, [rdi]
0x14000a707  mov     rdx, [rdx]; struct __crt_locale_data *
0x14000a70a  mov     rcx, [rcx]; struct __acrt_ptd *
0x14000a70d  call    ?replace_current_thread_locale_nolock@@YAXQEAU__acrt_ptd@@QEAU__crt_locale_data@@@Z
0x14000a712  nop
0x14000a713  mov     ecx, [rbx]
0x14000a715  call    sub_14000D594
0x14000a71a  mov     rbx, [rsp+28h+arg_0]
0x14000a71f  add     rsp, 20h
0x14000a723  pop     rdi
0x14000a724  retn
0x1400139e1  push    rbp
0x1400139e3  sub     rsp, 20h
0x1400139e7  mov     rbp, rdx
0x1400139ea  mov     rax, [rbp+48h]
0x1400139ee  mov     ecx, [rax]
0x1400139f0  add     rsp, 20h
0x1400139f4  pop     rbp
0x1400139f5  jmp     sub_14000D594

// ===== ??$?RV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@V_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@$$QEAV_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@Z @ 0x14000a728 =====

0x14000a728  mov     [rsp+arg_0], rbx
0x14000a72d  mov     [rsp+arg_18], r9
0x14000a732  push    rdi
0x14000a733  sub     rsp, 20h
0x14000a737  mov     rbx, r9
0x14000a73a  mov     rdi, r8
0x14000a73d  mov     ecx, [rdx]
0x14000a73f  call    sub_14000D540
0x14000a744  nop
0x14000a745  mov     rax, [rdi]
0x14000a748  mov     rcx, [rax]
0x14000a74b  mov     rax, [rcx+88h]
0x14000a752  lock inc dword ptr [rax]
0x14000a755  mov     ecx, [rbx]
0x14000a757  call    sub_14000D594
0x14000a75c  mov     rbx, [rsp+28h+arg_0]
0x14000a761  add     rsp, 20h
0x14000a765  pop     rdi
0x14000a766  retn
0x1400139e1  push    rbp
0x1400139e3  sub     rsp, 20h
0x1400139e7  mov     rbp, rdx
0x1400139ea  mov     rax, [rbp+48h]
0x1400139ee  mov     ecx, [rax]
0x1400139f0  add     rsp, 20h
0x1400139f4  pop     rbp
0x1400139f5  jmp     sub_14000D594

// ===== ??$?RV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@V_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@$$QEAV_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@Z @ 0x14000a768 =====

0x14000a768  mov     [rsp+arg_0], rbx
0x14000a76d  mov     [rsp+arg_18], r9
0x14000a772  push    rdi
0x14000a773  sub     rsp, 20h
0x14000a777  mov     rbx, r9
0x14000a77a  mov     rdi, r8
0x14000a77d  mov     ecx, [rdx]
0x14000a77f  call    sub_14000D540
0x14000a784  nop
0x14000a785  mov     rcx, [rdi]
0x14000a788  xor     edx, edx; struct __crt_locale_data *
0x14000a78a  mov     rcx, [rcx]; struct __acrt_ptd *
0x14000a78d  call    ?replace_current_thread_locale_nolock@@YAXQEAU__acrt_ptd@@QEAU__crt_locale_data@@@Z
0x14000a792  nop
0x14000a793  mov     ecx, [rbx]
0x14000a795  call    sub_14000D594
0x14000a79a  mov     rbx, [rsp+28h+arg_0]
0x14000a79f  add     rsp, 20h
0x14000a7a3  pop     rdi
0x14000a7a4  retn
0x1400139e1  push    rbp
0x1400139e3  sub     rsp, 20h
0x1400139e7  mov     rbp, rdx
0x1400139ea  mov     rax, [rbp+48h]
0x1400139ee  mov     ecx, [rax]
0x1400139f0  add     rsp, 20h
0x1400139f4  pop     rbp
0x1400139f5  jmp     sub_14000D594

// ===== ?construct_ptd_array@@YAXQEAU__acrt_ptd@@@Z @ 0x14000a7a8 =====

0x14000a7a8  push    rbp
0x14000a7aa  mov     rbp, rsp
0x14000a7ad  sub     rsp, 50h
0x14000a7b1  mov     [rbp+var_28], rcx
0x14000a7b5  lea     rax, [rbp+var_28]
0x14000a7b9  mov     [rbp+var_18], rax
0x14000a7bd  lea     r9, [rbp+arg_10]
0x14000a7c1  mov     edx, 1
0x14000a7c6  lea     r8, [rbp+var_18]
0x14000a7ca  mov     eax, 5
0x14000a7cf  mov     [rbp+arg_10], eax
0x14000a7d2  mov     [rbp+arg_18], eax
0x14000a7d5  lea     rax, [rbp+var_28]
0x14000a7d9  mov     [rbp+var_10], rax
0x14000a7dd  lea     rax, [rbp+var_20]
0x14000a7e1  mov     [rbp+var_8], rax
0x14000a7e5  mov     eax, 4
0x14000a7ea  mov     [rbp+var_30], eax
0x14000a7ed  mov     [rbp+var_2C], eax
0x14000a7f0  lea     rax, qword_1400217C0
0x14000a7f7  mov     [rbp+var_20], rax
0x14000a7fb  mov     [rcx+28h], edx
0x14000a7fe  lea     rcx, unk_1400158C0
0x14000a805  mov     rax, [rbp+var_28]
0x14000a809  mov     [rax], rcx
0x14000a80c  lea     rcx, unk_140020540
0x14000a813  mov     rax, [rbp+var_28]
0x14000a817  mov     [rax+3A8h], edx
0x14000a81d  mov     rax, [rbp+var_28]
0x14000a821  mov     [rax+88h], rcx
0x14000a828  lea     ecx, [rdx+42h]
0x14000a82b  mov     rax, [rbp+var_28]
0x14000a82f  lea     rdx, [rbp+arg_18]
0x14000a833  mov     [rax+0BCh], cx
0x14000a83a  mov     rax, [rbp+var_28]
0x14000a83e  mov     [rax+1C2h], cx
0x14000a845  lea     rcx, [rbp+arg_8]
0x14000a849  mov     rax, [rbp+var_28]
0x14000a84d  and     qword ptr [rax+3A0h], 0
0x14000a855  call    ??$?RV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@V_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_72d1df2b273a38828b1ce30cbf4cdab5_@@AEAV_lambda_876a65b173b8412d3a47c70a915b0cf4_@@$$QEAV_lambda_41932305e351933ebe8f8be3ed8bb5dc_@@@Z
0x14000a85a  lea     r9, [rbp+var_30]
0x14000a85e  lea     r8, [rbp+var_10]
0x14000a862  lea     rdx, [rbp+var_2C]
0x14000a866  lea     rcx, [rbp+arg_8]
0x14000a86a  call    ??$?RV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@V_lambda_341c25c0346d94847f1f3c463c57e077_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_5e887d1dcbef67a5eb4283622ba103bf_@@AEAV_lambda_4466841279450cc726390878d4a41900_@@$$QEAV_lambda_341c25c0346d94847f1f3c463c57e077_@@@Z
0x14000a86f  add     rsp, 50h
0x14000a873  pop     rbp
0x14000a874  retn

// ===== ?destroy_fls@@YAXPEAX@Z @ 0x14000a878 =====

0x14000a878  test    rcx, rcx
0x14000a87b  jz      short locret_14000A897
0x14000a87d  push    rbx
0x14000a87e  sub     rsp, 20h
0x14000a882  mov     rbx, rcx
0x14000a885  call    ?destroy_ptd_array@@YAXQEAU__acrt_ptd@@@Z
0x14000a88a  mov     rcx, rbx; Block
0x14000a88d  call    _free_base
0x14000a892  add     rsp, 20h
0x14000a896  pop     rbx
0x14000a897  retn

// ===== ?destroy_ptd_array@@YAXQEAU__acrt_ptd@@@Z @ 0x14000a898 =====

0x14000a898  push    rbp
0x14000a89a  mov     rbp, rsp
0x14000a89d  sub     rsp, 40h
0x14000a8a1  lea     rax, [rbp+var_18]
0x14000a8a5  mov     [rbp+var_18], rcx
0x14000a8a9  mov     [rbp+var_10], rax
0x14000a8ad  lea     rdx, unk_1400158C0
0x14000a8b4  mov     eax, 5
0x14000a8b9  mov     [rbp+arg_10], eax
0x14000a8bc  mov     [rbp+arg_18], eax
0x14000a8bf  lea     rax, [rbp+var_18]
0x14000a8c3  mov     [rbp+var_8], rax
0x14000a8c7  mov     eax, 4
0x14000a8cc  mov     [rbp+var_20], eax
0x14000a8cf  mov     [rbp+var_1C], eax
0x14000a8d2  mov     rax, [rcx]
0x14000a8d5  cmp     rax, rdx
0x14000a8d8  jz      short loc_14000A8E6
0x14000a8da  mov     rcx, rax; Block
0x14000a8dd  call    _free_base
0x14000a8e2  mov     rcx, [rbp+var_18]
0x14000a8e6  mov     rcx, [rcx+70h]; Block
0x14000a8ea  call    _free_base
0x14000a8ef  mov     rcx, [rbp+var_18]
0x14000a8f3  mov     rcx, [rcx+58h]; Block
0x14000a8f7  call    _free_base
0x14000a8fc  mov     rcx, [rbp+var_18]
0x14000a900  mov     rcx, [rcx+60h]; Block
0x14000a904  call    _free_base
0x14000a909  mov     rcx, [rbp+var_18]
0x14000a90d  mov     rcx, [rcx+68h]; Block
0x14000a911  call    _free_base
0x14000a916  mov     rcx, [rbp+var_18]
0x14000a91a  mov     rcx, [rcx+48h]; Block
0x14000a91e  call    _free_base
0x14000a923  mov     rcx, [rbp+var_18]
0x14000a927  mov     rcx, [rcx+50h]; Block
0x14000a92b  call    _free_base
0x14000a930  mov     rcx, [rbp+var_18]
0x14000a934  mov     rcx, [rcx+78h]; Block
0x14000a938  call    _free_base
0x14000a93d  mov     rcx, [rbp+var_18]
0x14000a941  mov     rcx, [rcx+80h]; Block
0x14000a948  call    _free_base
0x14000a94d  mov     rcx, [rbp+var_18]
0x14000a951  mov     rcx, [rcx+3C0h]; Block
0x14000a958  call    _free_base
0x14000a95d  lea     r9, [rbp+arg_10]
0x14000a961  lea     r8, [rbp+var_10]
0x14000a965  lea     rdx, [rbp+arg_18]
0x14000a969  lea     rcx, [rbp+arg_8]
0x14000a96d  call    ??$?RV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@V_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_46352004c1216016012b18bd6f87e700_@@AEAV_lambda_3bd07e1a1191394380780325891bf33f_@@$$QEAV_lambda_334532d3f185bcaa59b5be82d7d22bff_@@@Z
0x14000a972  lea     r9, [rbp+var_20]
0x14000a976  lea     r8, [rbp+var_8]
0x14000a97a  lea     rdx, [rbp+var_1C]
0x14000a97e  lea     rcx, [rbp+arg_8]
0x14000a982  call    ??$?RV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@V_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_fb3a7dec4e47f37f22dae91bb15c9095_@@AEAV_lambda_698284760c8add0bfb0756c19673e34b_@@$$QEAV_lambda_dfb8eca1e75fef3034a8fb18dd509707_@@@Z
0x14000a987  add     rsp, 40h
0x14000a98b  pop     rbp
0x14000a98c  retn

// ===== ?replace_current_thread_locale_nolock@@YAXQEAU__acrt_ptd@@QEAU__crt_locale_data@@@Z @ 0x14000a990 =====

0x14000a990  mov     [rsp+arg_0], rbx
0x14000a995  push    rdi
0x14000a996  sub     rsp, 20h
0x14000a99a  mov     rdi, rcx
0x14000a99d  mov     rbx, rdx
0x14000a9a0  mov     rcx, [rcx+90h]
0x14000a9a7  test    rcx, rcx
0x14000a9aa  jz      short loc_14000A9D8
0x14000a9ac  call    __acrt_release_locale_ref
0x14000a9b1  mov     rcx, [rdi+90h]; Block
0x14000a9b8  cmp     rcx, cs:qword_1400217C0
0x14000a9bf  jz      short loc_14000A9D8
0x14000a9c1  lea     rax, off_1400202C0
0x14000a9c8  cmp     rcx, rax
0x14000a9cb  jz      short loc_14000A9D8
0x14000a9cd  cmp     dword ptr [rcx+10h], 0
0x14000a9d1  jnz     short loc_14000A9D8
0x14000a9d3  call    __acrt_free_locale
0x14000a9d8  mov     [rdi+90h], rbx
0x14000a9df  test    rbx, rbx
0x14000a9e2  jz      short loc_14000A9EC
0x14000a9e4  mov     rcx, rbx
0x14000a9e7  call    __acrt_add_locale_ref
0x14000a9ec  mov     rbx, [rsp+28h+arg_0]
0x14000a9f1  add     rsp, 20h
0x14000a9f5  pop     rdi
0x14000a9f6  retn

// ===== __acrt_getptd @ 0x14000a9f8 =====

0x14000a9f8  mov     [rsp+arg_0], rbx
0x14000a9fd  push    rdi
0x14000a9fe  sub     rsp, 20h
0x14000aa02  call    cs:GetLastError; KERNEL32
0x14000aa08  mov     ecx, cs:dwTlsIndex; dwTlsIndex
0x14000aa0e  mov     ebx, eax
0x14000aa10  cmp     ecx, 0FFFFFFFFh
0x14000aa13  jz      short loc_14000AA22
0x14000aa15  call    __vcrt_FlsFree_0
0x14000aa1a  mov     rdi, rax
0x14000aa1d  test    rax, rax
0x14000aa20  jnz     short loc_14000AA63
0x14000aa22  mov     edx, 3C8h; Size
0x14000aa27  mov     ecx, 1; Count
0x14000aa2c  call    _calloc_base
0x14000aa31  mov     rdi, rax
0x14000aa34  test    rax, rax
0x14000aa37  jnz     short loc_14000AA42
0x14000aa39  xor     ecx, ecx; Block
0x14000aa3b  call    _free_base
0x14000aa40  jmp     short loc_14000AA7E
0x14000aa42  mov     ecx, cs:dwTlsIndex; dwTlsIndex
0x14000aa48  mov     rdx, rax; lpTlsValue
0x14000aa4b  call    __acrt_FlsSetValue
0x14000aa50  mov     rcx, rdi; struct __acrt_ptd *
0x14000aa53  test    eax, eax
0x14000aa55  jz      short loc_14000AA3B
0x14000aa57  call    ?construct_ptd_array@@YAXQEAU__acrt_ptd@@@Z
0x14000aa5c  xor     ecx, ecx; Block
0x14000aa5e  call    _free_base
0x14000aa63  test    rdi, rdi
0x14000aa66  jz      short loc_14000AA7E
0x14000aa68  mov     ecx, ebx; dwErrCode
0x14000aa6a  call    cs:SetLastError; KERNEL32
0x14000aa70  mov     rbx, [rsp+28h+arg_0]
0x14000aa75  mov     rax, rdi
0x14000aa78  add     rsp, 20h
0x14000aa7c  pop     rdi
0x14000aa7d  retn
0x14000aa7e  mov     ecx, ebx; dwErrCode
0x14000aa80  call    cs:SetLastError; KERNEL32
0x14000aa86  call    abort

// ===== __acrt_getptd_noexit @ 0x14000aa8c =====

0x14000aa8c  mov     [rsp+arg_0], rbx
0x14000aa91  mov     [rsp+arg_8], rsi
0x14000aa96  push    rdi
0x14000aa97  sub     rsp, 20h
0x14000aa9b  call    cs:GetLastError; KERNEL32
0x14000aaa1  mov     ecx, cs:dwTlsIndex; dwTlsIndex
0x14000aaa7  xor     esi, esi
0x14000aaa9  mov     ebx, eax
0x14000aaab  cmp     ecx, 0FFFFFFFFh
0x14000aaae  jz      short loc_14000AABD
0x14000aab0  call    __vcrt_FlsFree_0
0x14000aab5  mov     rdi, rax
0x14000aab8  test    rax, rax
0x14000aabb  jnz     short loc_14000AAFE
0x14000aabd  mov     edx, 3C8h; Size
0x14000aac2  mov     ecx, 1; Count
0x14000aac7  call    _calloc_base
0x14000aacc  mov     rdi, rax
0x14000aacf  test    rax, rax
0x14000aad2  jnz     short loc_14000AADD
0x14000aad4  xor     ecx, ecx; Block
0x14000aad6  call    _free_base
0x14000aadb  jmp     short loc_14000AB03
0x14000aadd  mov     ecx, cs:dwTlsIndex; dwTlsIndex
0x14000aae3  mov     rdx, rax; lpTlsValue
0x14000aae6  call    __acrt_FlsSetValue
0x14000aaeb  mov     rcx, rdi; struct __acrt_ptd *
0x14000aaee  test    eax, eax
0x14000aaf0  jz      short loc_14000AAD6
0x14000aaf2  call    ?construct_ptd_array@@YAXQEAU__acrt_ptd@@@Z
0x14000aaf7  xor     ecx, ecx; Block
0x14000aaf9  call    _free_base
0x14000aafe  test    rdi, rdi
0x14000ab01  jnz     short loc_14000AB0D
0x14000ab03  mov     ecx, ebx; dwErrCode
0x14000ab05  call    cs:SetLastError; KERNEL32
0x14000ab0b  jmp     short loc_14000AB18
0x14000ab0d  mov     ecx, ebx; dwErrCode
0x14000ab0f  call    cs:SetLastError; KERNEL32
0x14000ab15  mov     rsi, rdi
0x14000ab18  mov     rbx, [rsp+28h+arg_0]
0x14000ab1d  mov     rax, rsi
0x14000ab20  mov     rsi, [rsp+28h+arg_8]
0x14000ab25  add     rsp, 20h
0x14000ab29  pop     rdi
0x14000ab2a  retn

// ===== __acrt_initialize_ptd @ 0x14000ab2c =====

0x14000ab2c  sub     rsp, 28h
0x14000ab30  lea     rcx, ?destroy_fls@@YAXPEAX@Z
0x14000ab37  call    __acrt_FlsAlloc
0x14000ab3c  mov     cs:dwTlsIndex, eax
0x14000ab42  cmp     eax, 0FFFFFFFFh
0x14000ab45  jnz     short loc_14000AB4B
0x14000ab47  xor     al, al
0x14000ab49  jmp     short loc_14000AB60
0x14000ab4b  call    __acrt_getptd_noexit
0x14000ab50  test    rax, rax
0x14000ab53  jnz     short loc_14000AB5E
0x14000ab55  xor     ecx, ecx
0x14000ab57  call    __vcrt_uninitialize_ptd_0
0x14000ab5c  jmp     short loc_14000AB47
0x14000ab5e  mov     al, 1
0x14000ab60  add     rsp, 28h
0x14000ab64  retn

// ===== __vcrt_uninitialize_ptd_0 @ 0x14000ab68 =====

0x14000ab68  sub     rsp, 28h
0x14000ab6c  mov     ecx, cs:dwTlsIndex; dwTlsIndex
0x14000ab72  cmp     ecx, 0FFFFFFFFh
0x14000ab75  jz      short loc_14000AB83
0x14000ab77  call    __acrt_FlsFree
0x14000ab7c  or      cs:dwTlsIndex, 0FFFFFFFFh
0x14000ab83  mov     al, 1
0x14000ab85  add     rsp, 28h
0x14000ab89  retn

// ===== sub_14000AB8C @ 0x14000ab8c =====

0x14000ab8c  push    rbx
0x14000ab8e  sub     rsp, 20h
0x14000ab92  mov     rax, cs:qword_1400217C0
0x14000ab99  mov     rbx, rdx
0x14000ab9c  cmp     [rdx], rax
0x14000ab9f  jz      short loc_14000ABB7
0x14000aba1  mov     eax, [rcx+3A8h]
0x14000aba7  test    cs:dword_140020B30, eax
0x14000abad  jnz     short loc_14000ABB7
0x14000abaf  call    __acrt_update_thread_locale_data
0x14000abb4  mov     [rbx], rax
0x14000abb7  add     rsp, 20h
0x14000abbb  pop     rbx
0x14000abbc  retn

// ===== sub_14000ABC0 @ 0x14000abc0 =====

0x14000abc0  push    rbx
0x14000abc2  sub     rsp, 20h
0x14000abc6  mov     rax, cs:Block
0x14000abcd  mov     rbx, rdx
0x14000abd0  cmp     [rdx], rax
0x14000abd3  jz      short loc_14000ABEB
0x14000abd5  mov     eax, [rcx+3A8h]
0x14000abdb  test    cs:dword_140020B30, eax
0x14000abe1  jnz     short loc_14000ABEB
0x14000abe3  call    __acrt_update_thread_multibyte_data
0x14000abe8  mov     [rbx], rax
0x14000abeb  add     rsp, 20h
0x14000abef  pop     rbx
0x14000abf0  retn

// ===== _free_base @ 0x14000abf4 =====

0x14000abf4  test    rcx, rcx
0x14000abf7  jz      short locret_14000AC30
0x14000abf9  push    rbx
0x14000abfa  sub     rsp, 20h
0x14000abfe  mov     r8, rcx; lpMem
0x14000ac01  xor     edx, edx; dwFlags
0x14000ac03  mov     rcx, cs:hHeap; hHeap
0x14000ac0a  call    cs:HeapFree; KERNEL32
0x14000ac10  test    eax, eax
0x14000ac12  jnz     short loc_14000AC2B
0x14000ac14  call    _errno
0x14000ac19  mov     rbx, rax
0x14000ac1c  call    cs:GetLastError; KERNEL32
0x14000ac22  mov     ecx, eax
0x14000ac24  call    __acrt_errno_from_os_error
0x14000ac29  mov     [rbx], eax
0x14000ac2b  add     rsp, 20h
0x14000ac2f  pop     rbx
0x14000ac30  retn

// ===== _malloc_base @ 0x14000ac34 =====

0x14000ac34  push    rbx
0x14000ac36  sub     rsp, 20h
0x14000ac3a  mov     rbx, rcx
0x14000ac3d  cmp     rcx, 0FFFFFFFFFFFFFFE0h
0x14000ac41  ja      short loc_14000AC7F
0x14000ac43  test    rcx, rcx
0x14000ac46  mov     eax, 1
0x14000ac4b  cmovz   rbx, rax
0x14000ac4f  jmp     short loc_14000AC66
0x14000ac51  call    sub_140009208
0x14000ac56  test    eax, eax
0x14000ac58  jz      short loc_14000AC7F
0x14000ac5a  mov     rcx, rbx; Size
0x14000ac5d  call    _callnewh
0x14000ac62  test    eax, eax
0x14000ac64  jz      short loc_14000AC7F
0x14000ac66  mov     rcx, cs:hHeap; hHeap
0x14000ac6d  mov     r8, rbx; dwBytes
0x14000ac70  xor     edx, edx; dwFlags
0x14000ac72  call    cs:HeapAlloc; KERNEL32
0x14000ac78  test    rax, rax
0x14000ac7b  jz      short loc_14000AC51
0x14000ac7d  jmp     short loc_14000AC8C
0x14000ac7f  call    _errno
0x14000ac84  mov     dword ptr [rax], 0Ch
0x14000ac8a  xor     eax, eax
0x14000ac8c  add     rsp, 20h
0x14000ac90  pop     rbx
0x14000ac91  retn

// ===== wcsnlen @ 0x14000ac94 =====

0x14000ac94  push    rbp
0x14000ac96  sub     rsp, 20h
0x14000ac9a  lea     rbp, [rsp+20h]
0x14000ac9f  and     rbp, 0FFFFFFFFFFFFFFE0h
0x14000aca3  mov     eax, cs:dword_140020018
0x14000aca9  mov     r10, rdx
0x14000acac  mov     r8, rcx
0x14000acaf  cmp     eax, 5
0x14000acb2  jl      loc_14000AD88
0x14000acb8  test    cl, 1
0x14000acbb  jz      short loc_14000ACE8
0x14000acbd  lea     rax, [rcx+rdx*2]
0x14000acc1  mov     rdx, rcx
0x14000acc4  cmp     rcx, rax
0x14000acc7  jz      loc_14000AE75
0x14000accd  xor     r9d, r9d
0x14000acd0  cmp     [rdx], r9w
0x14000acd4  jz      loc_14000AE75
0x14000acda  add     rdx, 2
0x14000acde  cmp     rdx, rax
0x14000ace1  jnz     short loc_14000ACD0
0x14000ace3  jmp     loc_14000AE75
0x14000ace8  and     ecx, 1Fh
0x14000aceb  mov     eax, 20h ; ' '
0x14000acf0  sub     rax, rcx
0x14000acf3  neg     rcx
0x14000acf6  sbb     r11, r11
0x14000acf9  and     r11, rax
0x14000acfc  shr     r11, 1
0x14000acff  cmp     rdx, r11
0x14000ad02  cmovb   r11, rdx
0x14000ad06  xor     r9d, r9d
0x14000ad09  mov     rdx, r8
0x14000ad0c  lea     rax, [r8+r11*2]
0x14000ad10  cmp     r8, rax
0x14000ad13  jz      short loc_14000AD24
0x14000ad15  cmp     [rdx], r9w
0x14000ad19  jz      short loc_14000AD24
0x14000ad1b  add     rdx, 2
0x14000ad1f  cmp     rdx, rax
0x14000ad22  jnz     short loc_14000AD15
0x14000ad24  sub     rdx, r8
0x14000ad27  sar     rdx, 1
0x14000ad2a  cmp     rdx, r11
0x14000ad2d  jnz     loc_14000AE7B
0x14000ad33  mov     rcx, r10
0x14000ad36  lea     rdx, [r8+rdx*2]
0x14000ad3a  sub     rcx, r11
0x14000ad3d  mov     rax, rcx
0x14000ad40  and     eax, 1Fh
0x14000ad43  sub     rcx, rax
0x14000ad46  vxorps  ymm2, ymm2, ymm2
0x14000ad4a  lea     r11, [rdx+rcx*2]
0x14000ad4e  jmp     short loc_14000AD60
0x14000ad50  vpcmpeqw ymm1, ymm2, ymmword ptr [rdx]
0x14000ad54  vpmovmskb eax, ymm1
0x14000ad58  test    eax, eax
0x14000ad5a  jnz     short loc_14000AD65
0x14000ad5c  add     rdx, 20h ; ' '
0x14000ad60  cmp     rdx, r11
0x14000ad63  jnz     short loc_14000AD50
0x14000ad65  lea     rax, [r8+r10*2]
0x14000ad69  jmp     short loc_14000AD75
0x14000ad6b  cmp     [rdx], r9w
0x14000ad6f  jz      short loc_14000AD7A
0x14000ad71  add     rdx, 2
0x14000ad75  cmp     rdx, rax
0x14000ad78  jnz     short loc_14000AD6B
0x14000ad7a  sub     rdx, r8
0x14000ad7d  sar     rdx, 1
0x14000ad80  vzeroupper
0x14000ad83  jmp     loc_14000AE7B
0x14000ad88  cmp     eax, 1
0x14000ad8b  jl      loc_14000AE57
0x14000ad91  test    cl, 1
0x14000ad94  jz      short loc_14000ADC1
0x14000ad96  lea     rax, [rcx+rdx*2]
0x14000ad9a  mov     rdx, rcx
0x14000ad9d  cmp     rcx, rax
0x14000ada0  jz      loc_14000AE75
0x14000ada6  xor     r9d, r9d
0x14000ada9  cmp     [rdx], r9w
0x14000adad  jz      loc_14000AE75
0x14000adb3  add     rdx, 2
0x14000adb7  cmp     rdx, rax
0x14000adba  jnz     short loc_14000ADA9
0x14000adbc  jmp     loc_14000AE75
0x14000adc1  and     ecx, 0Fh
0x14000adc4  mov     eax, 10h
0x14000adc9  sub     rax, rcx
0x14000adcc  neg     rcx
0x14000adcf  sbb     r11, r11
0x14000add2  and     r11, rax
0x14000add5  shr     r11, 1
0x14000add8  cmp     rdx, r11
0x14000addb  cmovb   r11, rdx
0x14000addf  xor     r9d, r9d
0x14000ade2  mov     rdx, r8
0x14000ade5  lea     rax, [r8+r11*2]
0x14000ade9  cmp     r8, rax
0x14000adec  jz      short loc_14000ADFD
0x14000adee  cmp     [rdx], r9w
0x14000adf2  jz      short loc_14000ADFD
0x14000adf4  add     rdx, 2
0x14000adf8  cmp     rdx, rax
0x14000adfb  jnz     short loc_14000ADEE
0x14000adfd  sub     rdx, r8
0x14000ae00  sar     rdx, 1
0x14000ae03  cmp     rdx, r11
0x14000ae06  jnz     short loc_14000AE7B
0x14000ae08  mov     rcx, r10
0x14000ae0b  lea     rdx, [r8+rdx*2]
0x14000ae0f  sub     rcx, r11
0x14000ae12  xorps   xmm1, xmm1
0x14000ae15  mov     rax, rcx
0x14000ae18  and     eax, 0Fh
0x14000ae1b  sub     rcx, rax
0x14000ae1e  lea     r11, [rdx+rcx*2]
0x14000ae22  jmp     short loc_14000AE38
0x14000ae24  movdqa  xmm0, xmm1
0x14000ae28  pcmpeqw xmm0, xmmword ptr [rdx]
0x14000ae2c  pmovmskb eax, xmm0
0x14000ae30  test    eax, eax
0x14000ae32  jnz     short loc_14000AE3D
0x14000ae34  add     rdx, 10h
0x14000ae38  cmp     rdx, r11
0x14000ae3b  jnz     short loc_14000AE24
0x14000ae3d  lea     rax, [r8+r10*2]
0x14000ae41  jmp     short loc_14000AE4D
0x14000ae43  cmp     [rdx], r9w
0x14000ae47  jz      short loc_14000AE52
0x14000ae49  add     rdx, 2
0x14000ae4d  cmp     rdx, rax
0x14000ae50  jnz     short loc_14000AE43
0x14000ae52  sub     rdx, r8
0x14000ae55  jmp     short loc_14000AE78
0x14000ae57  lea     rax, [rcx+rdx*2]
0x14000ae5b  mov     rdx, rcx
0x14000ae5e  cmp     rcx, rax
0x14000ae61  jz      short loc_14000AE75
0x14000ae63  xor     r9d, r9d
0x14000ae66  cmp     [rdx], r9w
0x14000ae6a  jz      short loc_14000AE75
0x14000ae6c  add     rdx, 2
0x14000ae70  cmp     rdx, rax
0x14000ae73  jnz     short loc_14000AE66
0x14000ae75  sub     rdx, rcx
0x14000ae78  sar     rdx, 1
0x14000ae7b  mov     rax, rdx
0x14000ae7e  add     rsp, 20h
0x14000ae82  pop     rbp
0x14000ae83  retn

// ===== __crtLCMapStringW @ 0x14000ae84 =====

0x14000ae84  mov     [rsp+arg_0], rbx
0x14000ae89  mov     [rsp+arg_8], rbp
0x14000ae8e  mov     [rsp+arg_10], rsi
0x14000ae93  push    rdi
0x14000ae94  sub     rsp, 50h
0x14000ae98  movsxd  rbx, r9d
0x14000ae9b  mov     rdi, r8
0x14000ae9e  mov     esi, edx
0x14000aea0  mov     rbp, rcx
0x14000aea3  test    r9d, r9d
0x14000aea6  jle     short loc_14000AEBC
0x14000aea8  mov     rdx, rbx; MaxCount
0x14000aeab  mov     rcx, r8; Source
0x14000aeae  call    wcsnlen
0x14000aeb3  cmp     eax, ebx
0x14000aeb5  lea     ebx, [rax+1]
0x14000aeb8  jl      short loc_14000AEBC
0x14000aeba  mov     ebx, eax
0x14000aebc  and     [rsp+58h+var_18], 0
0x14000aec2  mov     r9d, ebx
0x14000aec5  and     [rsp+58h+var_20], 0
0x14000aecb  mov     r8, rdi
0x14000aece  and     [rsp+58h+var_28], 0
0x14000aed4  mov     edx, esi
0x14000aed6  mov     eax, [rsp+58h+arg_28]
0x14000aedd  mov     rcx, rbp
0x14000aee0  mov     [rsp+58h+var_30], eax
0x14000aee4  mov     rax, [rsp+58h+arg_20]
0x14000aeec  mov     [rsp+58h+var_38], rax
0x14000aef1  call    __acrt_LCMapStringEx
0x14000aef6  mov     rbx, [rsp+58h+arg_0]
0x14000aefb  mov     rbp, [rsp+58h+arg_8]
0x14000af00  mov     rsi, [rsp+58h+arg_10]
0x14000af05  add     rsp, 50h
0x14000af09  pop     rdi
0x14000af0a  retn

// ===== isdigit @ 0x14000af0c =====

0x14000af0c  push    rbx
0x14000af0e  sub     rsp, 40h
0x14000af12  movsxd  rbx, ecx
0x14000af15  mov     eax, cs:dword_140021774
0x14000af1b  test    eax, eax
0x14000af1d  jz      short loc_14000AF6A
0x14000af1f  xor     edx, edx; struct __crt_locale_pointers *
0x14000af21  lea     rcx, [rsp+48h+var_28]; this
0x14000af26  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000af2b  mov     rax, [rsp+48h+Locale.locinfo]
0x14000af30  cmp     dword ptr [rax+8], 1
0x14000af34  jle     short loc_14000AF4B
0x14000af36  lea     r8, [rsp+48h+Locale]; Locale
0x14000af3b  mov     edx, 4; Type
0x14000af40  mov     ecx, ebx; C
0x14000af42  call    _isctype_l
0x14000af47  mov     edx, eax
0x14000af49  jmp     short loc_14000AF55
0x14000af4b  mov     rax, [rax]
0x14000af4e  movzx   edx, word ptr [rax+rbx*2]
0x14000af52  and     edx, 4
0x14000af55  cmp     [rsp+48h+var_10], 0
0x14000af5a  jz      short loc_14000AF78
0x14000af5c  mov     rax, [rsp+48h+var_28]
0x14000af61  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x14000af68  jmp     short loc_14000AF78
0x14000af6a  mov     rax, cs:off_1400202C0
0x14000af71  movzx   edx, word ptr [rax+rbx*2]
0x14000af75  and     edx, 4
0x14000af78  mov     eax, edx
0x14000af7a  add     rsp, 40h
0x14000af7e  pop     rbx
0x14000af7f  retn

// ===== ?internal_isupper_l@@YA_NHQEAU__crt_locale_pointers@@@Z @ 0x14000af80 =====

0x14000af80  mov     [rsp+arg_0], rbx
0x14000af85  push    rdi
0x14000af86  sub     rsp, 20h
0x14000af8a  movsxd  rdi, ecx
0x14000af8d  test    rdx, rdx
0x14000af90  jz      short loc_14000AFB1
0x14000af92  mov     rax, [rdx]
0x14000af95  cmp     dword ptr [rax+8], 1
0x14000af99  jle     short loc_14000AFAC
0x14000af9b  mov     r8, rdx; Locale
0x14000af9e  mov     ecx, edi; C
0x14000afa0  mov     edx, 1; Type
0x14000afa5  call    _isctype_l
0x14000afaa  jmp     short loc_14000AFBD
0x14000afac  mov     rax, [rax]
0x14000afaf  jmp     short loc_14000AFB6
0x14000afb1  call    __pctype_func
0x14000afb6  movzx   eax, word ptr [rax+rdi*2]
0x14000afba  and     eax, 1
0x14000afbd  mov     rbx, [rsp+28h+arg_0]
0x14000afc2  test    eax, eax
0x14000afc4  setnz   al
0x14000afc7  add     rsp, 20h
0x14000afcb  pop     rdi
0x14000afcc  retn

// ===== _tolower_l @ 0x14000afd0 =====

0x14000afd0  mov     [rsp-8+arg_8], rbx
0x14000afd5  mov     [rsp-8+arg_18], rsi
0x14000afda  push    rbp
0x14000afdb  mov     rbp, rsp
0x14000afde  sub     rsp, 70h
0x14000afe2  movsxd  rbx, ecx
0x14000afe5  lea     rcx, [rbp+var_20]; this
0x14000afe9  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000afee  cmp     ebx, 100h
0x14000aff4  jnb     short loc_14000B02E
0x14000aff6  lea     rdx, [rbp+Locale]; struct __crt_locale_pointers *
0x14000affa  mov     ecx, ebx; int
0x14000affc  call    ?internal_isupper_l@@YA_NHQEAU__crt_locale_pointers@@@Z
0x14000b001  test    al, al
0x14000b003  jz      short loc_14000B014
0x14000b005  mov     rax, [rbp+Locale.locinfo]
0x14000b009  mov     rcx, [rax+110h]
0x14000b010  movzx   ebx, byte ptr [rcx+rbx]
0x14000b014  cmp     [rbp+var_8], 0
0x14000b018  jz      loc_14000B0FA
0x14000b01e  mov     rax, [rbp+var_20]
0x14000b022  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x14000b029  jmp     loc_14000B0FA
0x14000b02e  xor     eax, eax
0x14000b030  mov     [rbp+arg_0], ax
0x14000b034  mov     [rbp+arg_2], al
0x14000b037  mov     rax, [rbp+Locale.locinfo]
0x14000b03b  cmp     dword ptr [rax+8], 1
0x14000b03f  jle     short loc_14000B069
0x14000b041  mov     esi, ebx
0x14000b043  lea     rdx, [rbp+Locale]; Locale
0x14000b047  sar     esi, 8
0x14000b04a  movzx   ecx, sil; C
0x14000b04e  call    _isleadbyte_l
0x14000b053  test    eax, eax
0x14000b055  jz      short loc_14000B069
0x14000b057  mov     byte ptr [rbp+arg_0], sil
0x14000b05b  mov     ecx, 2
0x14000b060  mov     byte ptr [rbp+arg_0+1], bl
0x14000b063  mov     [rbp+arg_2], 0
0x14000b067  jmp     short loc_14000B080
0x14000b069  call    _errno
0x14000b06e  mov     ecx, 1
0x14000b073  mov     dword ptr [rax], 2Ah ; '*'
0x14000b079  mov     byte ptr [rbp+arg_0], bl
0x14000b07c  mov     byte ptr [rbp+arg_0+1], 0
0x14000b080  mov     rdx, [rbp+Locale.locinfo]
0x14000b084  lea     r9, [rbp+arg_0]; char *
0x14000b088  xor     eax, eax
0x14000b08a  mov     [rsp+70h+var_30], 1; int
0x14000b092  mov     [rbp+arg_10], ax
0x14000b096  mov     r8d, 100h; unsigned int
0x14000b09c  mov     [rbp+arg_12], al
0x14000b09f  mov     eax, [rdx+0Ch]
0x14000b0a2  mov     rdx, [rdx+138h]; wchar_t *
0x14000b0a9  mov     [rsp+70h+var_38], eax; int
0x14000b0ad  lea     rax, [rbp+arg_10]
0x14000b0b1  mov     [rsp+70h+var_40], 3; int
0x14000b0b9  mov     [rsp+70h+var_48], rax; char *
0x14000b0be  mov     [rsp+70h+var_50], ecx; int
0x14000b0c2  lea     rcx, [rbp+Locale]; struct __crt_locale_pointers *
0x14000b0c6  call    __acrt_LCMapStringA
0x14000b0cb  test    eax, eax
0x14000b0cd  jz      loc_14000B014
0x14000b0d3  movzx   ebx, byte ptr [rbp+arg_10]
0x14000b0d7  cmp     eax, 1
0x14000b0da  jz      loc_14000B014
0x14000b0e0  movzx   ecx, byte ptr [rbp+arg_10+1]
0x14000b0e4  shl     ebx, 8
0x14000b0e7  or      ebx, ecx
0x14000b0e9  cmp     [rbp+var_8], 0
0x14000b0ed  jz      short loc_14000B0FA
0x14000b0ef  mov     rcx, [rbp+var_20]
0x14000b0f3  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x14000b0fa  lea     r11, [rsp+70h+var_s0]
0x14000b0ff  mov     eax, ebx
0x14000b101  mov     rbx, [r11+18h]
0x14000b105  mov     rsi, [r11+28h]
0x14000b109  mov     rsp, r11
0x14000b10c  pop     rbp
0x14000b10d  retn

// ===== tolower @ 0x14000b110 =====

0x14000b110  sub     rsp, 28h
0x14000b114  mov     eax, cs:dword_140021774
0x14000b11a  test    eax, eax
0x14000b11c  jz      short loc_14000B129
0x14000b11e  xor     edx, edx; Locale
0x14000b120  call    _tolower_l
0x14000b125  mov     ecx, eax
0x14000b127  jmp     short loc_14000B134
0x14000b129  lea     eax, [rcx-41h]
0x14000b12c  cmp     eax, 19h
0x14000b12f  ja      short loc_14000B134
0x14000b131  add     ecx, 20h ; ' '
0x14000b134  mov     eax, ecx
0x14000b136  add     rsp, 28h
0x14000b13a  retn

// ===== unknown_libname_17 @ 0x14000b13c =====

0x14000b13c  mov     [rcx], rdx
0x14000b13f  mov     [rcx+8], r8
0x14000b143  test    r8, r8
0x14000b146  jz      short loc_14000B14B
0x14000b148  mov     [r8], rdx
0x14000b14b  mov     rax, rcx
0x14000b14e  retn

// ===== wcstol @ 0x14000b150 =====

0x14000b150  push    rbx
0x14000b152  sub     rsp, 30h
0x14000b156  mov     ebx, r8d
0x14000b159  mov     r8, rdx
0x14000b15c  mov     rdx, rcx
0x14000b15f  lea     rcx, [rsp+38h+var_18]
0x14000b164  call    unknown_libname_17; Microsoft VisualC 64bit universal runtime
0x14000b169  mov     rdx, rax
0x14000b16c  mov     r9b, 1
0x14000b16f  mov     r8d, ebx
0x14000b172  xor     ecx, ecx; struct __crt_locale_pointers *
0x14000b174  call    ??$parse_integer@KV?$c_string_character_source@_W@__crt_strtox@@@__crt_strtox@@YAKQEAU__crt_locale_pointers@@V?$c_string_character_source@_W@0@H_N@Z
0x14000b179  add     rsp, 30h
0x14000b17d  pop     rbx
0x14000b17e  retn

// ===== _mbtowc_l @ 0x14000b180 =====

0x14000b180  mov     rax, rsp
0x14000b183  mov     [rax+8], rbx
0x14000b187  mov     [rax+10h], rbp
0x14000b18b  mov     [rax+18h], rsi
0x14000b18f  mov     [rax+20h], rdi
0x14000b193  push    r14
0x14000b195  sub     rsp, 50h
0x14000b199  xor     r14d, r14d
0x14000b19c  mov     rbp, r8
0x14000b19f  mov     rsi, rdx
0x14000b1a2  mov     rdi, rcx
0x14000b1a5  test    rdx, rdx
0x14000b1a8  jz      short loc_14000B1BD
0x14000b1aa  test    r8, r8
0x14000b1ad  jz      short loc_14000B1BD
0x14000b1af  cmp     [rdx], r14b
0x14000b1b2  jnz     short loc_14000B1DA
0x14000b1b4  test    rcx, rcx
0x14000b1b7  jz      short loc_14000B1BD
0x14000b1b9  mov     [rcx], r14w
0x14000b1bd  xor     eax, eax
0x14000b1bf  mov     rbx, [rsp+58h+arg_0]
0x14000b1c4  mov     rbp, [rsp+58h+arg_8]
0x14000b1c9  mov     rsi, [rsp+58h+arg_10]
0x14000b1ce  mov     rdi, [rsp+58h+arg_18]
0x14000b1d3  add     rsp, 50h
0x14000b1d7  pop     r14
0x14000b1d9  retn
0x14000b1da  mov     rdx, r9; struct __crt_locale_pointers *
0x14000b1dd  lea     rcx, [rsp+58h+var_28]; this
0x14000b1e2  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000b1e7  mov     rax, [rsp+58h+Locale.locinfo]
0x14000b1ec  cmp     [rax+138h], r14
0x14000b1f3  jnz     short loc_14000B20A
0x14000b1f5  test    rdi, rdi
0x14000b1f8  jz      short loc_14000B200
0x14000b1fa  movzx   eax, byte ptr [rsi]
0x14000b1fd  mov     [rdi], ax
0x14000b200  mov     ebx, 1
0x14000b205  jmp     loc_14000B2AE
0x14000b20a  movzx   ecx, byte ptr [rsi]; C
0x14000b20d  lea     rdx, [rsp+58h+Locale]; Locale
0x14000b212  call    _isleadbyte_l
0x14000b217  mov     ebx, 1
0x14000b21c  test    eax, eax
0x14000b21e  jz      short loc_14000B271
0x14000b220  mov     rcx, [rsp+58h+Locale.locinfo]
0x14000b225  mov     r9d, [rcx+8]; cbMultiByte
0x14000b229  cmp     r9d, ebx
0x14000b22c  jle     short loc_14000B25D
0x14000b22e  cmp     ebp, r9d
0x14000b231  jl      short loc_14000B25D
0x14000b233  mov     ecx, [rcx+0Ch]; CodePage
0x14000b236  lea     edx, [rbx+8]; dwFlags
0x14000b239  mov     eax, r14d
0x14000b23c  test    rdi, rdi
0x14000b23f  mov     r8, rsi; lpMultiByteStr
0x14000b242  setnz   al
0x14000b245  mov     [rsp+58h+cchWideChar], eax; cchWideChar
0x14000b249  mov     [rsp+58h+lpWideCharStr], rdi; lpWideCharStr
0x14000b24e  call    cs:MultiByteToWideChar; KERNEL32
0x14000b254  mov     rcx, [rsp+58h+Locale.locinfo]
0x14000b259  test    eax, eax
0x14000b25b  jnz     short loc_14000B26C
0x14000b25d  movsxd  rax, dword ptr [rcx+8]
0x14000b261  cmp     rbp, rax
0x14000b264  jb      short loc_14000B2A0
0x14000b266  cmp     [rsi+1], r14b
0x14000b26a  jz      short loc_14000B2A0
0x14000b26c  mov     ebx, [rcx+8]
0x14000b26f  jmp     short loc_14000B2AE
0x14000b271  mov     eax, r14d
0x14000b274  test    rdi, rdi
0x14000b277  mov     r9d, ebx; cbMultiByte
0x14000b27a  mov     r8, rsi; lpMultiByteStr
0x14000b27d  setnz   al
0x14000b280  mov     edx, 9; dwFlags
0x14000b285  mov     [rsp+58h+cchWideChar], eax; cchWideChar
0x14000b289  mov     rax, [rsp+58h+Locale.locinfo]
0x14000b28e  mov     [rsp+58h+lpWideCharStr], rdi; lpWideCharStr
0x14000b293  mov     ecx, [rax+0Ch]; CodePage
0x14000b296  call    cs:MultiByteToWideChar; KERNEL32
0x14000b29c  test    eax, eax
0x14000b29e  jnz     short loc_14000B2AE
0x14000b2a0  call    _errno
0x14000b2a5  or      ebx, 0FFFFFFFFh
0x14000b2a8  mov     dword ptr [rax], 2Ah ; '*'
0x14000b2ae  cmp     [rsp+58h+var_10], r14b
0x14000b2b3  jz      short loc_14000B2C1
0x14000b2b5  mov     rcx, [rsp+58h+var_28]
0x14000b2ba  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x14000b2c1  mov     eax, ebx
0x14000b2c3  jmp     loc_14000B1BF

// ===== mbtowc @ 0x14000b2c8 =====

0x14000b2c8  xor     r9d, r9d; Locale
0x14000b2cb  jmp     _mbtowc_l

// ===== ?__acrt_fp_classify@@YA?AW4__acrt_fp_class@@AEBN@Z @ 0x14000b2d0 =====

0x14000b2d0  mov     rdx, [rcx]
0x14000b2d3  mov     ecx, 7FFh
0x14000b2d8  mov     rax, rdx
0x14000b2db  shr     rax, 34h
0x14000b2df  and     rax, rcx
0x14000b2e2  cmp     rax, rcx
0x14000b2e5  jz      short loc_14000B2EA
0x14000b2e7  xor     eax, eax
0x14000b2e9  retn
0x14000b2ea  mov     rcx, 0FFFFFFFFFFFFFh
0x14000b2f4  mov     rax, rdx
0x14000b2f7  and     rax, rcx
0x14000b2fa  jnz     short loc_14000B302
0x14000b2fc  mov     eax, 1
0x14000b301  retn
0x14000b302  mov     rcx, 8000000000000000h
0x14000b30c  test    rcx, rdx
0x14000b30f  jz      short loc_14000B326
0x14000b311  mov     rcx, 8000000000000h
0x14000b31b  cmp     rax, rcx
0x14000b31e  jnz     short loc_14000B326
0x14000b320  mov     eax, 4
0x14000b325  retn
0x14000b326  shr     rdx, 33h
0x14000b32a  not     edx
0x14000b32c  and     edx, 1
0x14000b32f  or      edx, 2
0x14000b332  mov     eax, edx
0x14000b334  retn

// ===== ?fp_format_a@@YAHQEBNPEAD_KQEAD2H_NIQEAU__crt_locale_pointers@@@Z @ 0x14000b338 =====

0x14000b338  mov     rax, rsp
0x14000b33b  mov     [rax+8], rbx
0x14000b33f  mov     [rax+10h], rbp
0x14000b343  mov     [rax+18h], rsi
0x14000b347  mov     [rax+20h], rdi
0x14000b34b  push    r12
0x14000b34d  push    r14
0x14000b34f  push    r15
0x14000b351  sub     rsp, 70h
0x14000b355  mov     ebx, [rsp+88h+arg_28]
0x14000b35c  xor     r12d, r12d
0x14000b35f  mov     rdi, rdx
0x14000b362  mov     [rdx], r12b
0x14000b365  mov     rdx, [rsp+88h+arg_40]; struct __crt_locale_pointers *
0x14000b36d  mov     rsi, rcx
0x14000b370  test    ebx, ebx
0x14000b372  lea     rcx, [rax-38h]; this
0x14000b376  mov     r14, r9
0x14000b379  mov     rbp, r8
0x14000b37c  cmovs   ebx, r12d
0x14000b380  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000b385  lea     eax, [rbx+0Bh]
0x14000b388  movsxd  rdx, eax
0x14000b38b  cmp     rbp, rdx
0x14000b38e  ja      short loc_14000B3A6
0x14000b390  call    _errno
0x14000b395  lea     ebx, [r12+22h]
0x14000b39a  mov     [rax], ebx
0x14000b39c  call    _invalid_parameter_noinfo
0x14000b3a1  jmp     loc_14000B661
0x14000b3a6  mov     rax, [rsi]
0x14000b3a9  mov     ecx, 7FFh
0x14000b3ae  shr     rax, 34h
0x14000b3b2  and     rax, rcx
0x14000b3b5  cmp     rax, rcx
0x14000b3b8  jnz     short loc_14000B431
0x14000b3ba  mov     eax, [rsp+88h+arg_38]
0x14000b3c1  mov     r9, r14; char *
0x14000b3c4  mov     [rsp+88h+var_48], r12; struct __crt_locale_pointers *
0x14000b3c9  mov     r8, rbp; unsigned __int64
0x14000b3cc  mov     [rsp+88h+var_50], eax; unsigned int
0x14000b3d0  mov     rdx, rdi; char *
0x14000b3d3  mov     rax, [rsp+88h+arg_20]
0x14000b3db  mov     rcx, rsi; double *
0x14000b3de  mov     [rsp+88h+var_58], r12b; bool
0x14000b3e3  mov     [rsp+88h+var_60], ebx; int
0x14000b3e7  mov     [rsp+88h+var_68], rax; unsigned __int64
0x14000b3ec  call    ?fp_format_e@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z
0x14000b3f1  mov     ebx, eax
0x14000b3f3  test    eax, eax
0x14000b3f5  jz      short loc_14000B3FF
0x14000b3f7  mov     [rdi], r12b
0x14000b3fa  jmp     loc_14000B661
0x14000b3ff  mov     edx, 65h ; 'e'; Ch
0x14000b404  mov     rcx, rdi; Str
0x14000b407  call    strrchr
0x14000b40c  test    rax, rax
0x14000b40f  jz      loc_14000B65E
0x14000b415  mov     cl, [rsp+88h+arg_30]
0x14000b41c  neg     cl
0x14000b41e  sbb     dl, dl
0x14000b420  and     dl, 0E0h
0x14000b423  add     dl, 70h ; 'p'
0x14000b426  mov     [rax], dl
0x14000b428  mov     [rax+3], r12b
0x14000b42c  jmp     loc_14000B65E
0x14000b431  mov     rax, 8000000000000000h
0x14000b43b  test    [rsi], rax
0x14000b43e  jz      short loc_14000B446
0x14000b440  mov     byte ptr [rdi], 2Dh ; '-'
0x14000b443  inc     rdi
0x14000b446  mov     r15b, [rsp+88h+arg_30]
0x14000b44e  mov     ebp, 3FFh
0x14000b453  mov     al, r15b
0x14000b456  mov     r10d, 30h ; '0'
0x14000b45c  neg     al
0x14000b45e  mov     r11, 0FFFFFFFFFFFFFh
0x14000b468  mov     rax, 7FF0000000000000h
0x14000b472  sbb     edx, edx
0x14000b474  and     edx, 0FFFFFFE0h
0x14000b477  sub     edx, 0FFFFFFD9h
0x14000b47a  test    [rsi], rax
0x14000b47d  jnz     short loc_14000B499
0x14000b47f  mov     [rdi], r10b
0x14000b482  inc     rdi
0x14000b485  mov     rax, [rsi]
0x14000b488  and     rax, r11
0x14000b48b  neg     rax
0x14000b48e  sbb     rbp, rbp
0x14000b491  and     ebp, 3FEh
0x14000b497  jmp     short loc_14000B49F
0x14000b499  mov     byte ptr [rdi], 31h ; '1'
0x14000b49c  inc     rdi
0x14000b49f  mov     r14, rdi
0x14000b4a2  inc     rdi
0x14000b4a5  test    ebx, ebx
0x14000b4a7  jnz     short loc_14000B4AE
0x14000b4a9  mov     [r14], r12b
0x14000b4ac  jmp     short loc_14000B4C2
0x14000b4ae  mov     rax, [rsp+88h+var_30]
0x14000b4b3  mov     rcx, [rax+0F8h]
0x14000b4ba  mov     rax, [rcx]
0x14000b4bd  mov     cl, [rax]
0x14000b4bf  mov     [r14], cl
0x14000b4c2  test    [rsi], r11
0x14000b4c5  jbe     loc_14000B555
0x14000b4cb  movzx   r8d, r10w
0x14000b4cf  mov     r9, 0F000000000000h
0x14000b4d9  test    ebx, ebx
0x14000b4db  jle     short loc_14000B50B
0x14000b4dd  mov     rax, [rsi]
0x14000b4e0  mov     cl, r8b
0x14000b4e3  and     rax, r9
0x14000b4e6  and     rax, r11
0x14000b4e9  shr     rax, cl
0x14000b4ec  add     ax, r10w
0x14000b4f0  cmp     ax, 39h ; '9'
0x14000b4f4  jbe     short loc_14000B4F9
0x14000b4f6  add     ax, dx
0x14000b4f9  mov     [rdi], al
0x14000b4fb  dec     ebx
0x14000b4fd  inc     rdi
0x14000b500  shr     r9, 4
0x14000b504  add     r8w, 0FFFCh
0x14000b509  jns     short loc_14000B4D9
0x14000b50b  test    r8w, r8w
0x14000b50f  js      short loc_14000B555
0x14000b511  mov     rax, [rsi]
0x14000b514  mov     cl, r8b
0x14000b517  and     rax, r9
0x14000b51a  and     rax, r11
0x14000b51d  shr     rax, cl
0x14000b520  cmp     ax, 8
0x14000b524  jbe     short loc_14000B555
0x14000b526  lea     rcx, [rdi-1]
0x14000b52a  mov     al, [rcx]
0x14000b52c  sub     al, 46h ; 'F'
0x14000b52e  test    al, 0DFh
0x14000b530  jnz     short loc_14000B53A
0x14000b532  mov     [rcx], r10b
0x14000b535  dec     rcx
0x14000b538  jmp     short loc_14000B52A
0x14000b53a  cmp     rcx, r14
0x14000b53d  jz      short loc_14000B552
0x14000b53f  mov     al, [rcx]
0x14000b541  cmp     al, 39h ; '9'
0x14000b543  jnz     short loc_14000B54C
0x14000b545  add     dl, 3Ah ; ':'
0x14000b548  mov     [rcx], dl
0x14000b54a  jmp     short loc_14000B555
0x14000b54c  inc     al
0x14000b54e  mov     [rcx], al
0x14000b550  jmp     short loc_14000B555
0x14000b552  inc     byte ptr [rcx-1]
0x14000b555  test    ebx, ebx
0x14000b557  jle     short loc_14000B570
0x14000b559  mov     r8, rbx
0x14000b55c  mov     dl, r10b
0x14000b55f  mov     rcx, rdi
0x14000b562  call    sub_140005B30
0x14000b567  add     rdi, rbx
0x14000b56a  mov     r10d, 30h ; '0'
0x14000b570  cmp     [r14], r12b
0x14000b573  cmovz   rdi, r14
0x14000b577  neg     r15b
0x14000b57a  sbb     al, al
0x14000b57c  and     al, 0E0h
0x14000b57e  add     al, 70h ; 'p'
0x14000b580  mov     [rdi], al
0x14000b582  mov     rcx, [rsi]
0x14000b585  shr     rcx, 34h
0x14000b589  and     ecx, 7FFh
0x14000b58f  sub     rcx, rbp
0x14000b592  js      short loc_14000B59E
0x14000b594  mov     byte ptr [rdi+1], 2Bh ; '+'
0x14000b598  add     rdi, 2
0x14000b59c  jmp     short loc_14000B5A9
0x14000b59e  mov     byte ptr [rdi+1], 2Dh ; '-'
0x14000b5a2  add     rdi, 2
0x14000b5a6  neg     rcx
0x14000b5a9  mov     [rdi], r10b
0x14000b5ac  mov     r8, rdi
0x14000b5af  cmp     rcx, 3E8h
0x14000b5b6  jl      short loc_14000B5EB
0x14000b5b8  mov     rax, 20C49BA5E353F7CFh
0x14000b5c2  imul    rcx
0x14000b5c5  sar     rdx, 7
0x14000b5c9  mov     rax, rdx
0x14000b5cc  shr     rax, 3Fh
0x14000b5d0  add     rdx, rax
0x14000b5d3  lea     eax, [r10+rdx]
0x14000b5d7  mov     [rdi], al
0x14000b5d9  inc     rdi
0x14000b5dc  imul    rax, rdx, 0FFFFFFFFFFFFFC18h
0x14000b5e3  add     rcx, rax
0x14000b5e6  cmp     rdi, r8
0x14000b5e9  jnz     short loc_14000B5F1
0x14000b5eb  cmp     rcx, 64h ; 'd'
0x14000b5ef  jl      short loc_14000B61F
0x14000b5f1  mov     rax, 0A3D70A3D70A3D70Bh
0x14000b5fb  imul    rcx
0x14000b5fe  add     rdx, rcx
0x14000b601  sar     rdx, 6
0x14000b605  mov     rax, rdx
0x14000b608  shr     rax, 3Fh
0x14000b60c  add     rdx, rax
0x14000b60f  lea     eax, [r10+rdx]
0x14000b613  mov     [rdi], al
0x14000b615  inc     rdi
0x14000b618  imul    rax, rdx, -64h
0x14000b61c  add     rcx, rax
0x14000b61f  cmp     rdi, r8
0x14000b622  jnz     short loc_14000B62A
0x14000b624  cmp     rcx, 0Ah
0x14000b628  jl      short loc_14000B655
0x14000b62a  mov     rax, 6666666666666667h
0x14000b634  imul    rcx
0x14000b637  sar     rdx, 2
0x14000b63b  mov     rax, rdx
0x14000b63e  shr     rax, 3Fh
0x14000b642  add     rdx, rax
0x14000b645  lea     eax, [r10+rdx]
0x14000b649  mov     [rdi], al
0x14000b64b  inc     rdi
0x14000b64e  imul    rax, rdx, -0Ah
0x14000b652  add     rcx, rax
0x14000b655  add     cl, r10b
0x14000b658  mov     [rdi], cl
0x14000b65a  mov     [rdi+1], r12b
0x14000b65e  mov     ebx, r12d
0x14000b661  cmp     [rsp+88h+var_20], r12b
0x14000b666  jz      short loc_14000B674
0x14000b668  mov     rcx, [rsp+88h+var_38]
0x14000b66d  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x14000b674  lea     r11, [rsp+88h+var_18]
0x14000b679  mov     eax, ebx
0x14000b67b  mov     rbx, [r11+20h]
0x14000b67f  mov     rbp, [r11+28h]
0x14000b683  mov     rsi, [r11+30h]
0x14000b687  mov     rdi, [r11+38h]
0x14000b68b  mov     rsp, r11
0x14000b68e  pop     r15
0x14000b690  pop     r14
0x14000b692  pop     r12
0x14000b694  retn

// ===== ?fp_format_e@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z @ 0x14000b698 =====

0x14000b698  mov     r11, rsp
0x14000b69b  mov     [r11+8], rbx
0x14000b69f  mov     [r11+10h], rbp
0x14000b6a3  mov     [r11+18h], rsi
0x14000b6a7  push    rdi
0x14000b6a8  sub     rsp, 50h
0x14000b6ac  mov     rax, [rsp+58h+arg_20]
0x14000b6b4  mov     rsi, r8
0x14000b6b7  mov     ebp, [rsp+58h+arg_28]
0x14000b6be  lea     r8, [r11-18h]
0x14000b6c2  mov     rcx, [rcx]
0x14000b6c5  mov     rdi, rdx
0x14000b6c8  mov     [r11-38h], rax
0x14000b6cc  lea     edx, [rbp+1]
0x14000b6cf  call    __acrt_fltout
0x14000b6d4  xor     ecx, ecx
0x14000b6d6  lea     r9, [rsp+58h+var_18]
0x14000b6db  cmp     [rsp+58h+var_18], 2Dh ; '-'
0x14000b6e0  lea     r8d, [rbp+1]
0x14000b6e4  mov     rdx, rsi
0x14000b6e7  setz    cl
0x14000b6ea  xor     eax, eax
0x14000b6ec  test    ebp, ebp
0x14000b6ee  setnle  al
0x14000b6f1  sub     rdx, rax
0x14000b6f4  sub     rdx, rcx
0x14000b6f7  cmp     rsi, 0FFFFFFFFFFFFFFFFh
0x14000b6fb  cmovz   rdx, rsi
0x14000b6ff  add     rcx, rax
0x14000b702  add     rcx, rdi
0x14000b705  call    __acrt_fp_strflt_to_string
0x14000b70a  test    eax, eax
0x14000b70c  jz      short loc_14000B713
0x14000b70e  mov     byte ptr [rdi], 0
0x14000b711  jmp     short loc_14000B750
0x14000b713  mov     rax, [rsp+58h+arg_40]
0x14000b71b  mov     r8d, ebp; int
0x14000b71e  mov     r9b, [rsp+58h+arg_30]; bool
0x14000b726  mov     rdx, rsi; unsigned __int64
0x14000b729  mov     [rsp+58h+var_20], rax; struct __crt_locale_pointers *
0x14000b72e  mov     rcx, rdi; char *
0x14000b731  lea     rax, [rsp+58h+var_18]
0x14000b736  mov     [rsp+58h+var_28], 0; bool
0x14000b73b  mov     [rsp+58h+var_30], rax; struct _strflt *
0x14000b740  mov     eax, [rsp+58h+arg_38]
0x14000b747  mov     [rsp+58h+var_38], eax; unsigned int
0x14000b74b  call    ?fp_format_e_internal@@YAHQEAD_KH_NIQEAU_strflt@@2QEAU__crt_locale_pointers@@@Z
0x14000b750  mov     rbx, [rsp+58h+arg_0]
0x14000b755  mov     rbp, [rsp+58h+arg_8]
0x14000b75a  mov     rsi, [rsp+58h+arg_10]
0x14000b75f  add     rsp, 50h
0x14000b763  pop     rdi
0x14000b764  retn

// ===== ?fp_format_e_internal@@YAHQEAD_KH_NIQEAU_strflt@@2QEAU__crt_locale_pointers@@@Z @ 0x14000b768 =====

0x14000b768  mov     rax, rsp
0x14000b76b  mov     [rax+8], rbx
0x14000b76f  mov     [rax+10h], rbp
0x14000b773  mov     [rax+18h], rsi
0x14000b777  mov     [rax+20h], rdi
0x14000b77b  push    r15
0x14000b77d  sub     rsp, 50h
0x14000b781  xor     eax, eax
0x14000b783  movsxd  rbx, r8d
0x14000b786  test    r8d, r8d
0x14000b789  mov     r15b, r9b
0x14000b78c  mov     rbp, rdx
0x14000b78f  mov     rdi, rcx
0x14000b792  cmovg   eax, ebx
0x14000b795  add     eax, 9
0x14000b798  cdqe
0x14000b79a  cmp     rdx, rax
0x14000b79d  ja      short loc_14000B7CD
0x14000b79f  call    _errno
0x14000b7a4  mov     ebx, 22h ; '"'
0x14000b7a9  mov     [rax], ebx
0x14000b7ab  call    _invalid_parameter_noinfo
0x14000b7b0  mov     eax, ebx
0x14000b7b2  mov     rbx, [rsp+58h+arg_0]
0x14000b7b7  mov     rbp, [rsp+58h+arg_8]
0x14000b7bc  mov     rsi, [rsp+58h+arg_10]
0x14000b7c1  mov     rdi, [rsp+58h+arg_18]
0x14000b7c6  add     rsp, 50h
0x14000b7ca  pop     r15
0x14000b7cc  retn
0x14000b7cd  mov     rdx, [rsp+58h+arg_38]; struct __crt_locale_pointers *
0x14000b7d5  lea     rcx, [rsp+58h+var_28]; this
0x14000b7da  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000b7df  cmp     [rsp+58h+arg_30], 0
0x14000b7e7  mov     rsi, [rsp+58h+arg_28]
0x14000b7ef  jz      short loc_14000B823
0x14000b7f1  xor     edx, edx
0x14000b7f3  cmp     dword ptr [rsi], 2Dh ; '-'
0x14000b7f6  setz    dl
0x14000b7f9  xor     eax, eax
0x14000b7fb  add     rdx, rdi
0x14000b7fe  test    ebx, ebx
0x14000b800  setnle  al
0x14000b803  test    eax, eax
0x14000b805  jz      short loc_14000B823
0x14000b807  or      r8, 0FFFFFFFFFFFFFFFFh
0x14000b80b  inc     r8
0x14000b80e  cmp     byte ptr [rdx+r8], 0
0x14000b813  jnz     short loc_14000B80B
0x14000b815  movsxd  rcx, eax
0x14000b818  inc     r8
0x14000b81b  add     rcx, rdx
0x14000b81e  call    sub_1400067F0
0x14000b823  cmp     dword ptr [rsi], 2Dh ; '-'
0x14000b826  mov     rdx, rdi
0x14000b829  jnz     short loc_14000B832
0x14000b82b  mov     byte ptr [rdi], 2Dh ; '-'
0x14000b82e  lea     rdx, [rdi+1]
0x14000b832  test    ebx, ebx
0x14000b834  jle     short loc_14000B851
0x14000b836  mov     al, [rdx+1]
0x14000b839  mov     [rdx], al
0x14000b83b  inc     rdx
0x14000b83e  mov     rax, [rsp+58h+var_20]
0x14000b843  mov     rcx, [rax+0F8h]
0x14000b84a  mov     rax, [rcx]
0x14000b84d  mov     cl, [rax]
0x14000b84f  mov     [rdx], cl
0x14000b851  xor     ecx, ecx
0x14000b853  lea     r8, aE000
0x14000b85a  cmp     [rsp+58h+arg_30], cl
0x14000b861  setz    cl
0x14000b864  add     rbx, rdx
0x14000b867  add     rbx, rcx
0x14000b86a  sub     rdi, rbx
0x14000b86d  mov     rcx, rbx; Destination
0x14000b870  cmp     rbp, 0FFFFFFFFFFFFFFFFh
0x14000b874  lea     rdx, [rdi+rbp]
0x14000b878  cmovz   rdx, rbp; SizeInBytes
0x14000b87c  call    strcpy_s
0x14000b881  test    eax, eax
0x14000b883  jnz     loc_14000B92D
0x14000b889  lea     rcx, [rbx+2]
0x14000b88d  test    r15b, r15b
0x14000b890  jz      short loc_14000B895
0x14000b892  mov     byte ptr [rbx], 45h ; 'E'
0x14000b895  mov     rax, [rsi+8]
0x14000b899  cmp     byte ptr [rax], 30h ; '0'
0x14000b89c  jz      short loc_14000B8F5
0x14000b89e  mov     r8d, [rsi+4]
0x14000b8a2  sub     r8d, 1
0x14000b8a6  jns     short loc_14000B8AF
0x14000b8a8  neg     r8d
0x14000b8ab  mov     byte ptr [rbx+1], 2Dh ; '-'
0x14000b8af  cmp     r8d, 64h ; 'd'
0x14000b8b3  jl      short loc_14000B8D0
0x14000b8b5  mov     eax, 51EB851Fh
0x14000b8ba  imul    r8d
0x14000b8bd  sar     edx, 5
0x14000b8c0  mov     eax, edx
0x14000b8c2  shr     eax, 1Fh
0x14000b8c5  add     edx, eax
0x14000b8c7  add     [rbx+2], dl
0x14000b8ca  imul    eax, edx, -64h
0x14000b8cd  add     r8d, eax
0x14000b8d0  cmp     r8d, 0Ah
0x14000b8d4  jl      short loc_14000B8F1
0x14000b8d6  mov     eax, 66666667h
0x14000b8db  imul    r8d
0x14000b8de  sar     edx, 2
0x14000b8e1  mov     eax, edx
0x14000b8e3  shr     eax, 1Fh
0x14000b8e6  add     edx, eax
0x14000b8e8  add     [rbx+3], dl
0x14000b8eb  imul    eax, edx, -0Ah
0x14000b8ee  add     r8d, eax
0x14000b8f1  add     [rbx+4], r8b
0x14000b8f5  cmp     [rsp+58h+arg_20], 2
0x14000b8fd  jnz     short loc_14000B913
0x14000b8ff  cmp     byte ptr [rcx], 30h ; '0'
0x14000b902  jnz     short loc_14000B913
0x14000b904  lea     rdx, [rcx+1]
0x14000b908  mov     r8d, 3
0x14000b90e  call    sub_1400067F0
0x14000b913  cmp     [rsp+58h+var_10], 0
0x14000b918  jz      short loc_14000B926
0x14000b91a  mov     rax, [rsp+58h+var_28]
0x14000b91f  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x14000b926  xor     eax, eax
0x14000b928  jmp     loc_14000B7B2
0x14000b92d  and     [rsp+58h+var_38], 0
0x14000b933  xor     r9d, r9d; LineNo
0x14000b936  xor     r8d, r8d; FileName
0x14000b939  xor     edx, edx; FunctionName
0x14000b93b  xor     ecx, ecx; Expression
0x14000b93d  call    _invoke_watson

// ===== ?fp_format_f_internal@@YAHQEAD_KHQEAU_strflt@@_NQEAU__crt_locale_pointers@@@Z @ 0x14000b944 =====

0x14000b944  mov     rax, rsp
0x14000b947  mov     [rax+8], rbx
0x14000b94b  mov     [rax+10h], rbp
0x14000b94f  mov     [rax+18h], rsi
0x14000b953  mov     [rax+20h], rdi
0x14000b957  push    r14
0x14000b959  sub     rsp, 40h
0x14000b95d  mov     rdx, [rsp+48h+arg_28]; struct __crt_locale_pointers *
0x14000b962  mov     rbx, rcx
0x14000b965  lea     rcx, [rax-28h]; this
0x14000b969  mov     r14, r9
0x14000b96c  mov     edi, r8d
0x14000b96f  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000b974  mov     ecx, [r14+4]
0x14000b978  dec     ecx
0x14000b97a  cmp     [rsp+48h+arg_20], 0
0x14000b97f  jz      short loc_14000B99A
0x14000b981  cmp     ecx, edi
0x14000b983  jnz     short loc_14000B99A
0x14000b985  xor     eax, eax
0x14000b987  movsxd  rcx, ecx
0x14000b98a  cmp     dword ptr [r14], 2Dh ; '-'
0x14000b98e  setz    al
0x14000b991  add     rax, rbx
0x14000b994  mov     word ptr [rcx+rax], 30h ; '0'
0x14000b99a  cmp     dword ptr [r14], 2Dh ; '-'
0x14000b99e  jnz     short loc_14000B9A6
0x14000b9a0  mov     byte ptr [rbx], 2Dh ; '-'
0x14000b9a3  inc     rbx
0x14000b9a6  or      rsi, 0FFFFFFFFFFFFFFFFh
0x14000b9aa  cmp     dword ptr [r14+4], 0
0x14000b9af  jg      short loc_14000B9D5
0x14000b9b1  mov     r8, rsi
0x14000b9b4  inc     r8
0x14000b9b7  cmp     byte ptr [rbx+r8], 0
0x14000b9bc  jnz     short loc_14000B9B4
0x14000b9be  inc     r8
0x14000b9c1  lea     rcx, [rbx+1]
0x14000b9c5  mov     rdx, rbx
0x14000b9c8  call    sub_1400067F0
0x14000b9cd  mov     byte ptr [rbx], 30h ; '0'
0x14000b9d0  inc     rbx
0x14000b9d3  jmp     short loc_14000B9DC
0x14000b9d5  movsxd  rax, dword ptr [r14+4]
0x14000b9d9  add     rbx, rax
0x14000b9dc  test    edi, edi
0x14000b9de  jle     short loc_14000BA5C
0x14000b9e0  lea     rbp, [rbx+1]
0x14000b9e4  mov     r8, rsi
0x14000b9e7  inc     r8
0x14000b9ea  cmp     byte ptr [rbx+r8], 0
0x14000b9ef  jnz     short loc_14000B9E7
0x14000b9f1  inc     r8
0x14000b9f4  mov     rdx, rbx
0x14000b9f7  mov     rcx, rbp
0x14000b9fa  call    sub_1400067F0
0x14000b9ff  mov     rax, [rsp+48h+var_20]
0x14000ba04  mov     rcx, [rax+0F8h]
0x14000ba0b  mov     rax, [rcx]
0x14000ba0e  mov     cl, [rax]
0x14000ba10  mov     [rbx], cl
0x14000ba12  mov     ecx, [r14+4]
0x14000ba16  test    ecx, ecx
0x14000ba18  jns     short loc_14000BA5C
0x14000ba1a  cmp     [rsp+48h+arg_20], 0
0x14000ba1f  jnz     short loc_14000BA29
0x14000ba21  mov     eax, ecx
0x14000ba23  neg     eax
0x14000ba25  cmp     eax, edi
0x14000ba27  jge     short loc_14000BA2D
0x14000ba29  mov     edi, ecx
0x14000ba2b  neg     edi
0x14000ba2d  test    edi, edi
0x14000ba2f  jz      short loc_14000BA4C
0x14000ba31  inc     rsi
0x14000ba34  cmp     byte ptr [rsi+rbp], 0
0x14000ba38  jnz     short loc_14000BA31
0x14000ba3a  movsxd  rcx, edi
0x14000ba3d  lea     r8, [rsi+1]
0x14000ba41  add     rcx, rbp
0x14000ba44  mov     rdx, rbp
0x14000ba47  call    sub_1400067F0
0x14000ba4c  movsxd  r8, edi
0x14000ba4f  mov     edx, 30h ; '0'
0x14000ba54  mov     rcx, rbp
0x14000ba57  call    sub_140005B30
0x14000ba5c  cmp     [rsp+48h+var_10], 0
0x14000ba61  jz      short loc_14000BA6F
0x14000ba63  mov     rax, [rsp+48h+var_28]
0x14000ba68  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x14000ba6f  mov     rbx, [rsp+48h+arg_0]
0x14000ba74  xor     eax, eax
0x14000ba76  mov     rbp, [rsp+48h+arg_8]
0x14000ba7b  mov     rsi, [rsp+48h+arg_10]
0x14000ba80  mov     rdi, [rsp+48h+arg_18]
0x14000ba85  add     rsp, 40h
0x14000ba89  pop     r14
0x14000ba8b  retn

// ===== ?fp_format_g@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z @ 0x14000ba8c =====

0x14000ba8c  mov     r11, rsp
0x14000ba8f  mov     [r11+8], rbx
0x14000ba93  mov     [r11+10h], rbp
0x14000ba97  mov     [r11+18h], rsi
0x14000ba9b  push    r14
0x14000ba9d  sub     rsp, 50h
0x14000baa1  mov     rcx, [rcx]
0x14000baa4  xor     eax, eax
0x14000baa6  mov     [r11-18h], rax
0x14000baaa  mov     rbp, r8
0x14000baad  mov     [r11-10h], rax
0x14000bab1  lea     r8, [r11-18h]
0x14000bab5  mov     rax, [rsp+58h+arg_20]
0x14000babd  mov     rsi, rdx
0x14000bac0  mov     edx, [rsp+58h+arg_28]
0x14000bac7  mov     [r11-38h], rax
0x14000bacb  call    __acrt_fltout
0x14000bad0  mov     r14d, [rsp+58h+var_14]
0x14000bad5  lea     r9, [rsp+58h+var_18]
0x14000bada  mov     r8d, [rsp+58h+arg_28]
0x14000bae2  xor     ecx, ecx
0x14000bae4  cmp     [rsp+58h+var_18], 2Dh ; '-'
0x14000bae9  mov     rdx, rbp
0x14000baec  setz    cl
0x14000baef  dec     r14d
0x14000baf2  sub     rdx, rcx
0x14000baf5  cmp     rbp, 0FFFFFFFFFFFFFFFFh
0x14000baf9  lea     rbx, [rcx+rsi]
0x14000bafd  cmovz   rdx, rbp
0x14000bb01  mov     rcx, rbx
0x14000bb04  call    __acrt_fp_strflt_to_string
0x14000bb09  test    eax, eax
0x14000bb0b  jz      short loc_14000BB15
0x14000bb0d  mov     byte ptr [rsi], 0
0x14000bb10  jmp     loc_14000BBAD
0x14000bb15  mov     eax, [rsp+58h+var_14]
0x14000bb19  dec     eax
0x14000bb1b  cmp     r14d, eax
0x14000bb1e  setl    cl
0x14000bb21  cmp     eax, 0FFFFFFFCh
0x14000bb24  jl      short loc_14000BB6B
0x14000bb26  cmp     eax, [rsp+58h+arg_28]
0x14000bb2d  jge     short loc_14000BB6B
0x14000bb2f  test    cl, cl
0x14000bb31  jz      short loc_14000BB3F
0x14000bb33  mov     al, [rbx]
0x14000bb35  inc     rbx
0x14000bb38  test    al, al
0x14000bb3a  jnz     short loc_14000BB33
0x14000bb3c  mov     [rbx-2], al
0x14000bb3f  mov     rax, [rsp+58h+arg_40]
0x14000bb47  lea     r9, [rsp+58h+var_18]; struct _strflt *
0x14000bb4c  mov     r8d, [rsp+58h+arg_28]; int
0x14000bb54  mov     rdx, rbp; unsigned __int64
0x14000bb57  mov     [rsp+58h+var_30], rax; struct __crt_locale_pointers *
0x14000bb5c  mov     rcx, rsi; char *
0x14000bb5f  mov     [rsp+58h+var_38], 1; bool
0x14000bb64  call    ?fp_format_f_internal@@YAHQEAD_KHQEAU_strflt@@_NQEAU__crt_locale_pointers@@@Z
0x14000bb69  jmp     short loc_14000BBAD
0x14000bb6b  mov     rax, [rsp+58h+arg_40]
0x14000bb73  mov     rdx, rbp; unsigned __int64
0x14000bb76  mov     r9b, [rsp+58h+arg_30]; bool
0x14000bb7e  mov     rcx, rsi; char *
0x14000bb81  mov     r8d, [rsp+58h+arg_28]; int
0x14000bb89  mov     [rsp+58h+var_20], rax; struct __crt_locale_pointers *
0x14000bb8e  lea     rax, [rsp+58h+var_18]
0x14000bb93  mov     [rsp+58h+var_28], 1; bool
0x14000bb98  mov     [rsp+58h+var_30], rax; struct _strflt *
0x14000bb9d  mov     eax, [rsp+58h+arg_38]
0x14000bba4  mov     dword ptr [rsp+58h+var_38], eax; unsigned int
0x14000bba8  call    ?fp_format_e_internal@@YAHQEAD_KH_NIQEAU_strflt@@2QEAU__crt_locale_pointers@@@Z
0x14000bbad  mov     rbx, [rsp+58h+arg_0]
0x14000bbb2  mov     rbp, [rsp+58h+arg_8]
0x14000bbb7  mov     rsi, [rsp+58h+arg_10]
0x14000bbbc  add     rsp, 50h
0x14000bbc0  pop     r14
0x14000bbc2  retn

// ===== ?fp_format_nan_or_infinity@@YAHW4__acrt_fp_class@@_NPEAD_K1@Z @ 0x14000bbc4 =====

0x14000bbc4  push    rbp
0x14000bbc6  lea     rbp, [rsp-4Fh]
0x14000bbcb  sub     rsp, 0C0h
0x14000bbd2  mov     rax, cs:__security_cookie
0x14000bbd9  xor     rax, rsp
0x14000bbdc  mov     [rbp+4Fh+var_10], rax
0x14000bbe0  mov     r10, r9
0x14000bbe3  movzx   eax, dl
0x14000bbe6  add     rax, 4
0x14000bbea  mov     r9, r8
0x14000bbed  cmp     r10, rax
0x14000bbf0  jnb     short loc_14000BC10
0x14000bbf2  mov     byte ptr [r8], 0
0x14000bbf6  mov     eax, 0Ch
0x14000bbfb  mov     rcx, [rbp+4Fh+var_10]
0x14000bbff  xor     rcx, rsp; StackCookie
0x14000bc02  call    __security_check_cookie
0x14000bc07  add     rsp, 0C0h
0x14000bc0e  pop     rbp
0x14000bc0f  retn
0x14000bc10  test    dl, dl
0x14000bc12  jz      short loc_14000BC22
0x14000bc14  inc     r9
0x14000bc17  mov     byte ptr [r8], 2Dh ; '-'
0x14000bc1b  dec     r10
0x14000bc1e  mov     byte ptr [r9], 0
0x14000bc22  neg     [rbp+4Fh+arg_20]
0x14000bc25  lea     rdx, aNan
0x14000bc2c  lea     r8, aNan_0
0x14000bc33  mov     [rbp+4Fh+var_70], rdx
0x14000bc37  lea     rax, aInf
0x14000bc3e  mov     [rbp+4Fh+var_68], rdx
0x14000bc42  mov     [rbp+4Fh+Source], rax
0x14000bc46  mov     [rbp+4Fh+var_88], rax
0x14000bc4a  lea     rax, aInf_0
0x14000bc51  mov     [rbp+4Fh+var_80], rax
0x14000bc55  mov     [rbp+4Fh+var_78], rax
0x14000bc59  lea     rax, aNanSnan
0x14000bc60  mov     [rbp+4Fh+var_50], rax
0x14000bc64  lea     rax, aNanSnan_0
0x14000bc6b  mov     [rbp+4Fh+var_40], rax
0x14000bc6f  lea     rax, aNanInd
0x14000bc76  mov     [rbp+4Fh+var_30], rax
0x14000bc7a  lea     rax, aNanInd_0
0x14000bc81  mov     [rbp+4Fh+var_20], rax
0x14000bc85  mov     [rbp+4Fh+var_48], rdx
0x14000bc89  mov     [rbp+4Fh+var_28], rdx
0x14000bc8d  lea     edx, [rcx-1]
0x14000bc90  sbb     ecx, ecx
0x14000bc92  mov     [rbp+4Fh+var_60], r8
0x14000bc96  shl     rdx, 2
0x14000bc9a  not     ecx
0x14000bc9c  and     ecx, 2
0x14000bc9f  mov     [rbp+4Fh+var_58], r8
0x14000bca3  mov     eax, ecx
0x14000bca5  add     rax, rdx
0x14000bca8  mov     [rbp+4Fh+var_38], r8
0x14000bcac  mov     [rbp+4Fh+var_18], r8
0x14000bcb0  mov     r8, [rbp+rax*8+4Fh+Source]
0x14000bcb5  or      rax, 0FFFFFFFFFFFFFFFFh
0x14000bcb9  inc     rax
0x14000bcbc  cmp     byte ptr [r8+rax], 0
0x14000bcc1  jnz     short loc_14000BCB9
0x14000bcc3  cmp     r10, rax
0x14000bcc6  setnbe  al
0x14000bcc9  xor     r8d, r8d
0x14000bccc  test    al, al
0x14000bcce  setz    r8b
0x14000bcd2  add     r8d, ecx
0x14000bcd5  mov     rcx, r9; Destination
0x14000bcd8  add     r8, rdx
0x14000bcdb  mov     rdx, r10; SizeInBytes
0x14000bcde  mov     r8, [rbp+r8*8+4Fh+Source]; Source
0x14000bce3  call    strcpy_s
0x14000bce8  test    eax, eax
0x14000bcea  jz      loc_14000BBFB
0x14000bcf0  and     [rsp+0C0h+var_A0], 0
0x14000bcf6  xor     r9d, r9d; LineNo
0x14000bcf9  xor     r8d, r8d; FileName
0x14000bcfc  xor     edx, edx; FunctionName
0x14000bcfe  xor     ecx, ecx; Expression
0x14000bd00  call    _invoke_watson

// ===== __acrt_fp_format @ 0x14000bd08 =====

0x14000bd08  mov     [rsp+arg_0], rbx
0x14000bd0d  mov     [rsp+arg_8], rbp
0x14000bd12  mov     [rsp+arg_10], rsi
0x14000bd17  push    rdi
0x14000bd18  push    r12
0x14000bd1a  push    r13
0x14000bd1c  push    r14
0x14000bd1e  push    r15
0x14000bd20  sub     rsp, 60h
0x14000bd24  mov     r13, r9
0x14000bd27  mov     rbp, r8
0x14000bd2a  mov     rsi, rdx
0x14000bd2d  mov     r15, rcx
0x14000bd30  test    rdx, rdx
0x14000bd33  jnz     short loc_14000BD4D
0x14000bd35  call    _errno
0x14000bd3a  mov     ebx, 16h
0x14000bd3f  mov     [rax], ebx
0x14000bd41  call    _invalid_parameter_noinfo
0x14000bd46  mov     eax, ebx
0x14000bd48  jmp     loc_14000BF2B
0x14000bd4d  test    r8, r8
0x14000bd50  jz      short loc_14000BD35
0x14000bd52  test    r9, r9
0x14000bd55  jz      short loc_14000BD35
0x14000bd57  mov     r12, [rsp+88h+arg_20]
0x14000bd5f  test    r12, r12
0x14000bd62  jz      short loc_14000BD35
0x14000bd64  mov     ebx, [rsp+88h+arg_28]
0x14000bd6b  cmp     ebx, 41h ; 'A'
0x14000bd6e  jz      short loc_14000BD7D
0x14000bd70  lea     eax, [rbx-45h]
0x14000bd73  cmp     eax, 2
0x14000bd76  jbe     short loc_14000BD7D
0x14000bd78  xor     r14b, r14b
0x14000bd7b  jmp     short loc_14000BD80
0x14000bd7d  mov     r14b, 1
0x14000bd80  mov     rdi, [rsp+88h+arg_38]
0x14000bd88  test    dil, 8
0x14000bd8c  jnz     short loc_14000BDB8
0x14000bd8e  call    ?__acrt_fp_classify@@YA?AW4__acrt_fp_class@@AEBN@Z
0x14000bd93  test    eax, eax
0x14000bd95  jz      short loc_14000BDB8
0x14000bd97  mov     rdx, [r15]
0x14000bd9a  mov     r9, rbp
0x14000bd9d  shr     rdx, 3Fh
0x14000bda1  mov     r8, rsi
0x14000bda4  and     dl, 1
0x14000bda7  mov     [rsp+88h+var_68], r14b
0x14000bdac  mov     ecx, eax
0x14000bdae  call    ?fp_format_nan_or_infinity@@YAHW4__acrt_fp_class@@_NPEAD_K1@Z
0x14000bdb3  jmp     loc_14000BF2B
0x14000bdb8  shr     rdi, 4
0x14000bdbc  and     edi, 1
0x14000bdbf  or      edi, 2
0x14000bdc2  sub     ebx, 41h ; 'A'
0x14000bdc5  jz      loc_14000BEF4
0x14000bdcb  sub     ebx, 4
0x14000bdce  jz      loc_14000BEBB
0x14000bdd4  sub     ebx, 1
0x14000bdd7  jz      short loc_14000BE31
0x14000bdd9  sub     ebx, 1
0x14000bddc  jz      short loc_14000BDF5
0x14000bdde  sub     ebx, 1Ah
0x14000bde1  jz      loc_14000BEF4
0x14000bde7  sub     ebx, 4
0x14000bdea  jz      loc_14000BEBB
0x14000bdf0  cmp     ebx, 1
0x14000bdf3  jz      short loc_14000BE31
0x14000bdf5  mov     rax, [rsp+88h+arg_40]
0x14000bdfd  mov     r9, r13; char *
0x14000be00  mov     [rsp+88h+var_48], rax; struct __crt_locale_pointers *
0x14000be05  mov     r8, rbp; unsigned __int64
0x14000be08  mov     eax, [rsp+88h+arg_30]
0x14000be0f  mov     rdx, rsi; char *
0x14000be12  mov     [rsp+88h+var_50], edi; unsigned int
0x14000be16  mov     rcx, r15; double *
0x14000be19  mov     [rsp+88h+var_58], r14b; bool
0x14000be1e  mov     dword ptr [rsp+88h+var_60], eax; int
0x14000be22  mov     qword ptr [rsp+88h+var_68], r12; unsigned __int64
0x14000be27  call    ?fp_format_g@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z
0x14000be2c  jmp     loc_14000BF2B
0x14000be31  mov     ebx, [rsp+88h+arg_30]
0x14000be38  lea     r8, [rsp+88h+var_38]
0x14000be3d  mov     rcx, [r15]
0x14000be40  xor     eax, eax
0x14000be42  mov     edx, ebx
0x14000be44  mov     [rsp+88h+var_38], rax
0x14000be49  mov     r9, r13
0x14000be4c  mov     [rsp+88h+var_30], rax
0x14000be51  mov     qword ptr [rsp+88h+var_68], r12
0x14000be56  call    __acrt_fltout
0x14000be5b  mov     r8d, dword ptr [rsp+88h+var_38+4]
0x14000be60  lea     r9, [rsp+88h+var_38]
0x14000be65  xor     ecx, ecx
0x14000be67  mov     rdx, rbp
0x14000be6a  cmp     dword ptr [rsp+88h+var_38], 2Dh ; '-'
0x14000be6f  setz    cl
0x14000be72  add     r8d, ebx
0x14000be75  sub     rdx, rcx
0x14000be78  cmp     rbp, 0FFFFFFFFFFFFFFFFh
0x14000be7c  cmovz   rdx, rbp
0x14000be80  add     rcx, rsi
0x14000be83  call    __acrt_fp_strflt_to_string
0x14000be88  test    eax, eax
0x14000be8a  jz      short loc_14000BE94
0x14000be8c  mov     byte ptr [rsi], 0
0x14000be8f  jmp     loc_14000BF2B
0x14000be94  mov     rax, [rsp+88h+arg_40]
0x14000be9c  lea     r9, [rsp+88h+var_38]; struct _strflt *
0x14000bea1  mov     [rsp+88h+var_60], rax; struct __crt_locale_pointers *
0x14000bea6  mov     r8d, ebx; int
0x14000bea9  mov     rdx, rbp; unsigned __int64
0x14000beac  mov     [rsp+88h+var_68], 0; bool
0x14000beb1  mov     rcx, rsi; char *
0x14000beb4  call    ?fp_format_f_internal@@YAHQEAD_KHQEAU_strflt@@_NQEAU__crt_locale_pointers@@@Z
0x14000beb9  jmp     short loc_14000BF2B
0x14000bebb  mov     rax, [rsp+88h+arg_40]
0x14000bec3  mov     r9, r13; char *
0x14000bec6  mov     [rsp+88h+var_48], rax; struct __crt_locale_pointers *
0x14000becb  mov     r8, rbp; unsigned __int64
0x14000bece  mov     eax, [rsp+88h+arg_30]
0x14000bed5  mov     rdx, rsi; char *
0x14000bed8  mov     [rsp+88h+var_50], edi; unsigned int
0x14000bedc  mov     rcx, r15; double *
0x14000bedf  mov     [rsp+88h+var_58], r14b; bool
0x14000bee4  mov     dword ptr [rsp+88h+var_60], eax; int
0x14000bee8  mov     qword ptr [rsp+88h+var_68], r12; unsigned __int64
0x14000beed  call    ?fp_format_e@@YAHQEBNQEAD_K12H_NIQEAU__crt_locale_pointers@@@Z
0x14000bef2  jmp     short loc_14000BF2B
0x14000bef4  mov     rax, [rsp+88h+arg_40]
0x14000befc  mov     r9, r13; char *
0x14000beff  mov     [rsp+88h+var_48], rax; struct __crt_locale_pointers *
0x14000bf04  mov     r8, rbp; unsigned __int64
0x14000bf07  mov     eax, [rsp+88h+arg_30]
0x14000bf0e  mov     rdx, rsi; char *
0x14000bf11  mov     [rsp+88h+var_50], edi; unsigned int
0x14000bf15  mov     rcx, r15; double *
0x14000bf18  mov     [rsp+88h+var_58], r14b; bool
0x14000bf1d  mov     dword ptr [rsp+88h+var_60], eax; int
0x14000bf21  mov     qword ptr [rsp+88h+var_68], r12; unsigned __int64
0x14000bf26  call    ?fp_format_a@@YAHQEBNPEAD_KQEAD2H_NIQEAU__crt_locale_pointers@@@Z
0x14000bf2b  lea     r11, [rsp+88h+var_28]
0x14000bf30  mov     rbx, [r11+30h]
0x14000bf34  mov     rbp, [r11+38h]
0x14000bf38  mov     rsi, [r11+40h]
0x14000bf3c  mov     rsp, r11
0x14000bf3f  pop     r15
0x14000bf41  pop     r14
0x14000bf43  pop     r13
0x14000bf45  pop     r12
0x14000bf47  pop     rdi
0x14000bf48  retn

// ===== __acrt_initialize_stdio @ 0x14000bf4c =====

0x14000bf4c  mov     rax, rsp
0x14000bf4f  mov     [rax+8], rbx
0x14000bf53  mov     [rax+10h], rbp
0x14000bf57  mov     [rax+18h], rsi
0x14000bf5b  mov     [rax+20h], rdi
0x14000bf5f  push    r14
0x14000bf61  sub     rsp, 20h
0x14000bf65  mov     eax, cs:dword_1400217C8
0x14000bf6b  xor     ebx, ebx
0x14000bf6d  mov     edi, 3
0x14000bf72  test    eax, eax
0x14000bf74  jnz     short loc_14000BF7D
0x14000bf76  mov     eax, 200h
0x14000bf7b  jmp     short loc_14000BF82
0x14000bf7d  cmp     eax, edi
0x14000bf7f  cmovl   eax, edi
0x14000bf82  movsxd  rcx, eax; Count
0x14000bf85  mov     edx, 8; Size
0x14000bf8a  mov     cs:dword_1400217C8, eax
0x14000bf90  call    _calloc_base
0x14000bf95  xor     ecx, ecx; Block
0x14000bf97  mov     cs:qword_1400217D0, rax
0x14000bf9e  call    _free_base
0x14000bfa3  cmp     cs:qword_1400217D0, rbx
0x14000bfaa  jnz     short loc_14000BFDB
0x14000bfac  mov     edx, 8; Size
0x14000bfb1  mov     cs:dword_1400217C8, edi
0x14000bfb7  mov     rcx, rdi; Count
0x14000bfba  call    _calloc_base
0x14000bfbf  xor     ecx, ecx; Block
0x14000bfc1  mov     cs:qword_1400217D0, rax
0x14000bfc8  call    _free_base
0x14000bfcd  cmp     cs:qword_1400217D0, rbx
0x14000bfd4  jnz     short loc_14000BFDB
0x14000bfd6  or      eax, 0FFFFFFFFh
0x14000bfd9  jmp     short loc_14000C050
0x14000bfdb  mov     r14, rbx
0x14000bfde  lea     rsi, unk_140020448
0x14000bfe5  lea     rbp, unk_140020430
0x14000bfec  lea     rcx, [rbp+30h]; lpCriticalSection
0x14000bff0  xor     r8d, r8d
0x14000bff3  mov     edx, 0FA0h; dwSpinCount
0x14000bff8  call    __acrt_InitializeCriticalSectionEx
0x14000bffd  mov     rax, cs:qword_1400217D0
0x14000c004  lea     rdx, qword_1400217F0
0x14000c00b  mov     rcx, rbx
0x14000c00e  and     ecx, 3Fh
0x14000c011  shl     rcx, 6
0x14000c015  mov     [r14+rax], rbp
0x14000c019  mov     rax, rbx
0x14000c01c  sar     rax, 6
0x14000c020  mov     rax, [rdx+rax*8]
0x14000c024  mov     rcx, [rax+rcx+28h]
0x14000c029  add     rcx, 2
0x14000c02d  cmp     rcx, 2
0x14000c031  ja      short loc_14000C039
0x14000c033  mov     dword ptr [rsi], 0FFFFFFFEh
0x14000c039  inc     rbx
0x14000c03c  add     rbp, 58h ; 'X'
0x14000c040  add     r14, 8
0x14000c044  add     rsi, 58h ; 'X'
0x14000c048  sub     rdi, 1
0x14000c04c  jnz     short loc_14000BFEC
0x14000c04e  xor     eax, eax
0x14000c050  mov     rbx, [rsp+28h+arg_0]
0x14000c055  mov     rbp, [rsp+28h+arg_8]
0x14000c05a  mov     rsi, [rsp+28h+arg_10]
0x14000c05f  mov     rdi, [rsp+28h+arg_18]
0x14000c064  add     rsp, 20h
0x14000c068  pop     r14
0x14000c06a  retn

// ===== __acrt_uninitialize_stdio @ 0x14000c06c =====

0x14000c06c  push    rbx
0x14000c06e  sub     rsp, 20h
0x14000c072  call    _flushall
0x14000c077  call    _fcloseall
0x14000c07c  xor     ebx, ebx
0x14000c07e  mov     rcx, cs:qword_1400217D0
0x14000c085  mov     rcx, [rbx+rcx]
0x14000c089  call    __acrt_stdio_free_buffer_nolock
0x14000c08e  mov     rax, cs:qword_1400217D0
0x14000c095  mov     rcx, [rbx+rax]
0x14000c099  add     rcx, 30h ; '0'; lpCriticalSection
0x14000c09d  call    cs:DeleteCriticalSection; KERNEL32
0x14000c0a3  add     rbx, 8
0x14000c0a7  cmp     rbx, 18h
0x14000c0ab  jnz     short loc_14000C07E
0x14000c0ad  mov     rcx, cs:qword_1400217D0; Block
0x14000c0b4  call    _free_base
0x14000c0b9  and     cs:qword_1400217D0, 0
0x14000c0c1  add     rsp, 20h
0x14000c0c5  pop     rbx
0x14000c0c6  retn

// ===== sub_14000C0C8 @ 0x14000c0c8 =====

0x14000c0c8  add     rcx, 30h ; '0'
0x14000c0cc  jmp     cs:EnterCriticalSection; KERNEL32

// ===== sub_14000C0D4 @ 0x14000c0d4 =====

0x14000c0d4  add     rcx, 30h ; '0'
0x14000c0d8  jmp     cs:LeaveCriticalSection; KERNEL32

// ===== _get_printf_count_output @ 0x14000c0e0 =====

0x14000c0e0  mov     rcx, cs:__security_cookie
0x14000c0e7  xor     eax, eax
0x14000c0e9  or      rcx, 1
0x14000c0ed  cmp     cs:qword_1400217D8, rcx
0x14000c0f4  setz    al
0x14000c0f7  retn

// ===== ?initialize_inherited_file_handles_nolock@@YAXXZ @ 0x14000c0f8 =====

0x14000c0f8  mov     rax, rsp
0x14000c0fb  mov     [rax+8], rbx
0x14000c0ff  mov     [rax+10h], rbp
0x14000c103  mov     [rax+18h], rsi
0x14000c107  mov     [rax+20h], rdi
0x14000c10b  push    r14
0x14000c10d  sub     rsp, 90h
0x14000c114  lea     rcx, [rax-78h]; lpStartupInfo
0x14000c118  call    cs:GetStartupInfoW; KERNEL32
0x14000c11e  xor     r14d, r14d
0x14000c121  cmp     [rsp+98h+var_36], r14w
0x14000c127  jz      loc_14000C1C5
0x14000c12d  mov     rax, [rsp+98h+var_30]
0x14000c132  test    rax, rax
0x14000c135  jz      loc_14000C1C5
0x14000c13b  movsxd  rbx, dword ptr [rax]
0x14000c13e  lea     rsi, [rax+4]
0x14000c142  mov     edi, 2000h
0x14000c147  add     rbx, rsi
0x14000c14a  cmp     [rax], edi
0x14000c14c  cmovl   edi, [rax]
0x14000c14f  mov     ecx, edi
0x14000c151  call    __acrt_lowio_ensure_fh_exists
0x14000c156  cmp     edi, cs:dword_140021BF0
0x14000c15c  cmovg   edi, cs:dword_140021BF0
0x14000c163  test    edi, edi
0x14000c165  jz      short loc_14000C1C5
0x14000c167  mov     ebp, r14d
0x14000c16a  cmp     qword ptr [rbx], 0FFFFFFFFFFFFFFFFh
0x14000c16e  jz      short loc_14000C1B5
0x14000c170  cmp     qword ptr [rbx], 0FFFFFFFFFFFFFFFEh
0x14000c174  jz      short loc_14000C1B5
0x14000c176  test    byte ptr [rsi], 1
0x14000c179  jz      short loc_14000C1B5
0x14000c17b  test    byte ptr [rsi], 8
0x14000c17e  jnz     short loc_14000C18D
0x14000c180  mov     rcx, [rbx]; hFile
0x14000c183  call    cs:GetFileType; KERNEL32
0x14000c189  test    eax, eax
0x14000c18b  jz      short loc_14000C1B5
0x14000c18d  mov     rcx, rbp
0x14000c190  lea     rdx, qword_1400217F0
0x14000c197  and     ecx, 3Fh
0x14000c19a  mov     rax, rbp
0x14000c19d  sar     rax, 6
0x14000c1a1  shl     rcx, 6
0x14000c1a5  add     rcx, [rdx+rax*8]
0x14000c1a9  mov     rax, [rbx]
0x14000c1ac  mov     [rcx+28h], rax
0x14000c1b0  mov     al, [rsi]
0x14000c1b2  mov     [rcx+38h], al
0x14000c1b5  inc     rbp
0x14000c1b8  inc     rsi
0x14000c1bb  add     rbx, 8
0x14000c1bf  sub     rdi, 1
0x14000c1c3  jnz     short loc_14000C16A
0x14000c1c5  lea     r11, [rsp+98h+var_8]
0x14000c1cd  mov     rbx, [r11+10h]
0x14000c1d1  mov     rbp, [r11+18h]
0x14000c1d5  mov     rsi, [r11+20h]
0x14000c1d9  mov     rdi, [r11+28h]
0x14000c1dd  mov     rsp, r11
0x14000c1e0  pop     r14
0x14000c1e2  retn

// ===== ?initialize_stdio_handles_nolock@@YAXXZ @ 0x14000c1e4 =====

0x14000c1e4  mov     [rsp+arg_0], rbx
0x14000c1e9  mov     [rsp+arg_8], rsi
0x14000c1ee  mov     [rsp+arg_10], rdi
0x14000c1f3  push    r14
0x14000c1f5  sub     rsp, 20h
0x14000c1f9  xor     edi, edi
0x14000c1fb  xor     r14d, r14d
0x14000c1fe  movsxd  rbx, edi
0x14000c201  lea     rcx, qword_1400217F0
0x14000c208  mov     rax, rbx
0x14000c20b  and     ebx, 3Fh
0x14000c20e  sar     rax, 6
0x14000c212  shl     rbx, 6
0x14000c216  add     rbx, [rcx+rax*8]
0x14000c21a  mov     rax, [rbx+28h]
0x14000c21e  add     rax, 2
0x14000c222  cmp     rax, 1
0x14000c226  jbe     short loc_14000C231
0x14000c228  or      byte ptr [rbx+38h], 80h
0x14000c22c  jmp     loc_14000C2BA
0x14000c231  mov     byte ptr [rbx+38h], 81h
0x14000c235  mov     ecx, edi
0x14000c237  test    edi, edi
0x14000c239  jz      short loc_14000C251
0x14000c23b  sub     ecx, 1
0x14000c23e  jz      short loc_14000C24A
0x14000c240  cmp     ecx, 1
0x14000c243  mov     ecx, 0FFFFFFF4h
0x14000c248  jmp     short loc_14000C256
0x14000c24a  mov     ecx, 0FFFFFFF5h
0x14000c24f  jmp     short loc_14000C256
0x14000c251  mov     ecx, 0FFFFFFF6h; nStdHandle
0x14000c256  call    cs:GetStdHandle; KERNEL32
0x14000c25c  mov     rsi, rax
0x14000c25f  lea     rcx, [rax+1]
0x14000c263  cmp     rcx, 1
0x14000c267  jbe     short loc_14000C274
0x14000c269  mov     rcx, rax; hFile
0x14000c26c  call    cs:GetFileType; KERNEL32
0x14000c272  jmp     short loc_14000C276
0x14000c274  xor     eax, eax
0x14000c276  test    eax, eax
0x14000c278  jz      short loc_14000C297
0x14000c27a  movzx   ecx, al
0x14000c27d  mov     [rbx+28h], rsi
0x14000c281  cmp     ecx, 2
0x14000c284  jnz     short loc_14000C28C
0x14000c286  or      byte ptr [rbx+38h], 40h
0x14000c28a  jmp     short loc_14000C2BA
0x14000c28c  cmp     ecx, 3
0x14000c28f  jnz     short loc_14000C2BA
0x14000c291  or      byte ptr [rbx+38h], 8
0x14000c295  jmp     short loc_14000C2BA
0x14000c297  or      byte ptr [rbx+38h], 40h
0x14000c29b  mov     qword ptr [rbx+28h], 0FFFFFFFFFFFFFFFEh
0x14000c2a3  mov     rax, cs:qword_1400217D0
0x14000c2aa  test    rax, rax
0x14000c2ad  jz      short loc_14000C2BA
0x14000c2af  mov     rax, [r14+rax]
0x14000c2b3  mov     dword ptr [rax+18h], 0FFFFFFFEh
0x14000c2ba  inc     edi
0x14000c2bc  add     r14, 8
0x14000c2c0  cmp     edi, 3
0x14000c2c3  jnz     loc_14000C1FE
0x14000c2c9  mov     rbx, [rsp+28h+arg_0]
0x14000c2ce  mov     rsi, [rsp+28h+arg_8]
0x14000c2d3  mov     rdi, [rsp+28h+arg_10]
0x14000c2d8  add     rsp, 20h
0x14000c2dc  pop     r14
0x14000c2de  retn

// ===== __acrt_initialize_lowio @ 0x14000c2e0 =====

0x14000c2e0  push    rbx
0x14000c2e2  sub     rsp, 20h
0x14000c2e6  mov     ecx, 7
0x14000c2eb  call    sub_14000D540
0x14000c2f0  xor     ebx, ebx
0x14000c2f2  xor     ecx, ecx
0x14000c2f4  call    __acrt_lowio_ensure_fh_exists
0x14000c2f9  test    eax, eax
0x14000c2fb  jnz     short loc_14000C309
0x14000c2fd  call    ?initialize_inherited_file_handles_nolock@@YAXXZ
0x14000c302  call    ?initialize_stdio_handles_nolock@@YAXXZ
0x14000c307  mov     bl, 1
0x14000c309  mov     ecx, 7
0x14000c30e  call    sub_14000D594
0x14000c313  mov     al, bl
0x14000c315  add     rsp, 20h
0x14000c319  pop     rbx
0x14000c31a  retn
0x140013a30  push    rbp; Microsoft VisualC 64bit universal runtime
0x140013a32  sub     rsp, 20h
0x140013a36  mov     rbp, rdx
0x140013a39  mov     ecx, 7
0x140013a3e  add     rsp, 20h
0x140013a42  pop     rbp
0x140013a43  jmp     sub_14000D594

// ===== __acrt_uninitialize_lowio @ 0x14000c31c =====

0x14000c31c  mov     [rsp+arg_0], rbx
0x14000c321  push    rdi
0x14000c322  sub     rsp, 20h
0x14000c326  xor     ebx, ebx
0x14000c328  lea     rdi, qword_1400217F0
0x14000c32f  mov     rcx, [rbx+rdi]; Block
0x14000c333  test    rcx, rcx
0x14000c336  jz      short loc_14000C342
0x14000c338  call    __acrt_lowio_destroy_handle_array
0x14000c33d  and     qword ptr [rbx+rdi], 0
0x14000c342  add     rbx, 8
0x14000c346  cmp     rbx, 400h
0x14000c34d  jb      short loc_14000C328
0x14000c34f  mov     al, 1
0x14000c351  mov     rbx, [rsp+28h+arg_0]
0x14000c356  add     rsp, 20h
0x14000c35a  pop     rdi
0x14000c35b  retn

// ===== _calloc_base @ 0x14000c35c =====

0x14000c35c  push    rbx
0x14000c35e  sub     rsp, 20h
0x14000c362  mov     r8, rdx
0x14000c365  mov     rbx, rcx
0x14000c368  test    rcx, rcx
0x14000c36b  jz      short loc_14000C37B
0x14000c36d  xor     edx, edx
0x14000c36f  lea     rax, [rdx-20h]
0x14000c373  div     rbx
0x14000c376  cmp     rax, r8
0x14000c379  jb      short loc_14000C3BE
0x14000c37b  imul    rbx, r8
0x14000c37f  mov     eax, 1
0x14000c384  test    rbx, rbx
0x14000c387  cmovz   rbx, rax
0x14000c38b  jmp     short loc_14000C3A2
0x14000c38d  call    sub_140009208
0x14000c392  test    eax, eax
0x14000c394  jz      short loc_14000C3BE
0x14000c396  mov     rcx, rbx; Size
0x14000c399  call    _callnewh
0x14000c39e  test    eax, eax
0x14000c3a0  jz      short loc_14000C3BE
0x14000c3a2  mov     rcx, cs:hHeap; hHeap
0x14000c3a9  mov     r8, rbx; dwBytes
0x14000c3ac  mov     edx, 8; dwFlags
0x14000c3b1  call    cs:HeapAlloc; KERNEL32
0x14000c3b7  test    rax, rax
0x14000c3ba  jz      short loc_14000C38D
0x14000c3bc  jmp     short loc_14000C3CB
0x14000c3be  call    _errno
0x14000c3c3  mov     dword ptr [rax], 0Ch
0x14000c3c9  xor     eax, eax
0x14000c3cb  add     rsp, 20h
0x14000c3cf  pop     rbx
0x14000c3d0  retn

// ===== CompareFunction @ 0x14000c3d4 =====

0x14000c3d4  cmp     rcx, rdx
0x14000c3d7  jnb     short loc_14000C3DD
0x14000c3d9  or      eax, 0FFFFFFFFh
0x14000c3dc  retn
0x14000c3dd  xor     eax, eax
0x14000c3df  cmp     rcx, rdx
0x14000c3e2  setnbe  al
0x14000c3e5  retn

// ===== ??$common_expand_argv_wildcards@_W@@YAHQEAPEA_WQEAPEAPEA_W@Z @ 0x14000c3e8 =====

0x14000c3e8  mov     [rsp-38h+arg_10], rbx
0x14000c3ed  push    rbp
0x14000c3ee  push    rsi
0x14000c3ef  push    rdi
0x14000c3f0  push    r12
0x14000c3f2  push    r13
0x14000c3f4  push    r14
0x14000c3f6  push    r15
0x14000c3f8  mov     rbp, rsp
0x14000c3fb  sub     rsp, 80h
0x14000c402  mov     rax, cs:__security_cookie
0x14000c409  xor     rax, rsp
0x14000c40c  mov     [rbp+var_10], rax
0x14000c410  xor     edi, edi
0x14000c412  mov     [rbp+var_28], rdx
0x14000c416  mov     rbx, rcx
0x14000c419  test    rdx, rdx
0x14000c41c  jnz     short loc_14000C434
0x14000c41e  call    _errno
0x14000c423  lea     ebx, [rdi+16h]
0x14000c426  mov     [rax], ebx
0x14000c428  call    _invalid_parameter_noinfo
0x14000c42d  mov     eax, ebx
0x14000c42f  jmp     loc_14000C5DB
0x14000c434  xorps   xmm0, xmm0
0x14000c437  mov     [rdx], rdi
0x14000c43a  cmp     [rcx], rdi
0x14000c43d  movdqu  xmmword ptr [rbp+Block], xmm0
0x14000c442  mov     [rbp+var_38], rdi
0x14000c446  jz      short loc_14000C4A0
0x14000c448  mov     rcx, [rbx]; String
0x14000c44b  lea     rdx, [rbp+Control]; Control
0x14000c44f  mov     dword ptr [rbp+Control], 3F002Ah
0x14000c456  mov     [rbp+Control+4], di
0x14000c45a  call    wcspbrk
0x14000c45f  mov     rcx, [rbx]; wchar_t *
0x14000c462  test    rax, rax
0x14000c465  jnz     short loc_14000C477
0x14000c467  lea     r9, [rbp+Block]
0x14000c46b  xor     r8d, r8d; MaxCount
0x14000c46e  xor     edx, edx; wchar_t *
0x14000c470  call    ??$copy_and_add_argument_to_buffer@_W@@YAHQEB_W0_KAEAV?$argument_list@_W@?A0x7b96f60e@@@Z
0x14000c475  jmp     short loc_14000C483
0x14000c477  lea     r8, [rbp+Block]
0x14000c47b  mov     rdx, rax
0x14000c47e  call    ??$expand_argument_wildcards@_W@@YAHQEA_W0AEAV?$argument_list@_W@?A0x7b96f60e@@@Z
0x14000c483  mov     r14d, eax
0x14000c486  test    eax, eax
0x14000c488  jnz     short loc_14000C493
0x14000c48a  add     rbx, 8
0x14000c48e  cmp     [rbx], rdi
0x14000c491  jmp     short loc_14000C446
0x14000c493  mov     r12, [rbp+Block+8]
0x14000c497  mov     rsi, [rbp+Block]
0x14000c49b  jmp     loc_14000C59F
0x14000c4a0  mov     rsi, [rbp+Block]
0x14000c4a4  mov     r9, rdi
0x14000c4a7  mov     r12, [rbp+Block+8]
0x14000c4ab  mov     rdx, rsi
0x14000c4ae  mov     rax, r12
0x14000c4b1  mov     qword ptr [rbp+Control], rdi
0x14000c4b5  sub     rax, rsi
0x14000c4b8  mov     r8, rdi
0x14000c4bb  mov     r15, rax
0x14000c4be  sar     r15, 3
0x14000c4c2  inc     r15
0x14000c4c5  lea     rcx, [rax+7]
0x14000c4c9  shr     rcx, 3
0x14000c4cd  cmp     rsi, r12
0x14000c4d0  cmova   rcx, rdi
0x14000c4d4  or      r14, 0FFFFFFFFFFFFFFFFh
0x14000c4d8  test    rcx, rcx
0x14000c4db  jz      short loc_14000C503
0x14000c4dd  mov     r10, [rdx]
0x14000c4e0  mov     rax, r14
0x14000c4e3  inc     rax
0x14000c4e6  cmp     [r10+rax*2], di
0x14000c4eb  jnz     short loc_14000C4E3
0x14000c4ed  inc     r9
0x14000c4f0  add     rdx, 8
0x14000c4f4  add     r9, rax
0x14000c4f7  inc     r8
0x14000c4fa  cmp     r8, rcx
0x14000c4fd  jnz     short loc_14000C4DD
0x14000c4ff  mov     qword ptr [rbp+Control], r9
0x14000c503  mov     r8d, 2
0x14000c509  mov     rdx, r9
0x14000c50c  mov     rcx, r15
0x14000c50f  call    __acrt_allocate_buffer_for_argv
0x14000c514  mov     rbx, rax
0x14000c517  test    rax, rax
0x14000c51a  jz      short loc_14000C598
0x14000c51c  lea     rdx, [rax+r15*8]
0x14000c520  mov     r15, rsi
0x14000c523  mov     [rbp+var_20], rdx
0x14000c527  mov     rcx, rdx; Destination
0x14000c52a  mov     [rbp+var_50], rdx
0x14000c52e  cmp     rsi, r12
0x14000c531  jz      short loc_14000C58E
0x14000c533  sub     rax, rsi
0x14000c536  mov     [rbp+var_30], rax
0x14000c53a  mov     r8, [r15]; Source
0x14000c53d  mov     r13, r14
0x14000c540  inc     r13
0x14000c543  cmp     [r8+r13*2], di
0x14000c548  jnz     short loc_14000C540
0x14000c54a  mov     rax, rcx
0x14000c54d  inc     r13
0x14000c550  sub     rax, rdx
0x14000c553  mov     r9, r13; MaxCount
0x14000c556  mov     rdx, qword ptr [rbp+Control]
0x14000c55a  sar     rax, 1
0x14000c55d  sub     rdx, rax; SizeInWords
0x14000c560  call    wcsncpy_s
0x14000c565  test    eax, eax
0x14000c567  jnz     loc_14000C602
0x14000c56d  mov     rcx, [rbp+var_50]
0x14000c571  mov     rax, [rbp+var_30]
0x14000c575  mov     rdx, [rbp+var_20]
0x14000c579  mov     [rax+r15], rcx
0x14000c57d  add     r15, 8
0x14000c581  lea     rcx, [rcx+r13*2]
0x14000c585  mov     [rbp+var_50], rcx
0x14000c589  cmp     r15, r12
0x14000c58c  jnz     short loc_14000C53A
0x14000c58e  mov     rax, [rbp+var_28]
0x14000c592  mov     r14d, edi
0x14000c595  mov     [rax], rbx
0x14000c598  xor     ecx, ecx; Block
0x14000c59a  call    _free_base
0x14000c59f  mov     rbx, r12
0x14000c5a2  mov     r15, rsi
0x14000c5a5  sub     rbx, rsi
0x14000c5a8  add     rbx, 7
0x14000c5ac  shr     rbx, 3
0x14000c5b0  cmp     rsi, r12
0x14000c5b3  cmova   rbx, rdi
0x14000c5b7  test    rbx, rbx
0x14000c5ba  jz      short loc_14000C5D0
0x14000c5bc  mov     rcx, [r15]; Block
0x14000c5bf  call    _free_base
0x14000c5c4  inc     rdi
0x14000c5c7  lea     r15, [r15+8]
0x14000c5cb  cmp     rdi, rbx
0x14000c5ce  jnz     short loc_14000C5BC
0x14000c5d0  mov     rcx, rsi; Block
0x14000c5d3  call    _free_base
0x14000c5d8  mov     eax, r14d
0x14000c5db  mov     rcx, [rbp+var_10]
0x14000c5df  xor     rcx, rsp; StackCookie
0x14000c5e2  call    __security_check_cookie
0x14000c5e7  mov     rbx, [rsp+80h+arg_10]
0x14000c5ef  add     rsp, 80h
0x14000c5f6  pop     r15
0x14000c5f8  pop     r14
0x14000c5fa  pop     r13
0x14000c5fc  pop     r12
0x14000c5fe  pop     rdi
0x14000c5ff  pop     rsi
0x14000c600  pop     rbp
0x14000c601  retn
0x14000c602  xor     r9d, r9d; LineNo
0x14000c605  mov     [rsp+80h+Reserved], rdi; Reserved
0x14000c60a  xor     r8d, r8d; FileName
0x14000c60d  xor     edx, edx; FunctionName
0x14000c60f  xor     ecx, ecx; Expression
0x14000c611  call    _invoke_watson

// ===== ??$copy_and_add_argument_to_buffer@_W@@YAHQEB_W0_KAEAV?$argument_list@_W@?A0x7b96f60e@@@Z @ 0x14000c618 =====

0x14000c618  mov     [rsp+arg_0], rbx
0x14000c61d  mov     [rsp+arg_8], rbp
0x14000c622  mov     [rsp+arg_10], rsi
0x14000c627  push    rdi
0x14000c628  push    r12
0x14000c62a  push    r13
0x14000c62c  push    r14
0x14000c62e  push    r15
0x14000c630  sub     rsp, 30h
0x14000c634  or      rax, 0FFFFFFFFFFFFFFFFh
0x14000c638  mov     rsi, r9
0x14000c63b  mov     rdi, rax
0x14000c63e  xor     r13d, r13d
0x14000c641  mov     rbp, r8
0x14000c644  mov     r12, rdx
0x14000c647  mov     r15, rcx
0x14000c64a  inc     rdi
0x14000c64d  cmp     [rcx+rdi*2], r13w
0x14000c652  jnz     short loc_14000C64A
0x14000c654  inc     rdi
0x14000c657  sub     rax, r8
0x14000c65a  cmp     rdi, rax
0x14000c65d  jbe     short loc_14000C681
0x14000c65f  mov     eax, 0Ch
0x14000c664  mov     rbx, [rsp+58h+arg_0]
0x14000c669  mov     rbp, [rsp+58h+arg_8]
0x14000c66e  mov     rsi, [rsp+58h+arg_10]
0x14000c673  add     rsp, 30h
0x14000c677  pop     r15
0x14000c679  pop     r14
0x14000c67b  pop     r13
0x14000c67d  pop     r12
0x14000c67f  pop     rdi
0x14000c680  retn
0x14000c681  lea     r14, [r8+1]
0x14000c685  mov     edx, 2; Size
0x14000c68a  add     r14, rdi
0x14000c68d  mov     rcx, r14; Count
0x14000c690  call    _calloc_base
0x14000c695  mov     rbx, rax
0x14000c698  test    rbp, rbp
0x14000c69b  jz      short loc_14000C6B2
0x14000c69d  mov     r9, rbp; MaxCount
0x14000c6a0  mov     r8, r12; Source
0x14000c6a3  mov     rdx, r14; SizeInWords
0x14000c6a6  mov     rcx, rax; Destination
0x14000c6a9  call    wcsncpy_s
0x14000c6ae  test    eax, eax
0x14000c6b0  jnz     short loc_14000C700
0x14000c6b2  sub     r14, rbp
0x14000c6b5  lea     rcx, [rbx+rbp*2]; Destination
0x14000c6b9  mov     rdx, r14; SizeInWords
0x14000c6bc  mov     r9, rdi; MaxCount
0x14000c6bf  mov     r8, r15; Source
0x14000c6c2  call    wcsncpy_s
0x14000c6c7  test    eax, eax
0x14000c6c9  jnz     short loc_14000C715
0x14000c6cb  mov     rcx, rsi
0x14000c6ce  call    unknown_libname_19; Microsoft VisualC 64bit universal runtime
0x14000c6d3  mov     edi, eax
0x14000c6d5  test    eax, eax
0x14000c6d7  jz      short loc_14000C6E3
0x14000c6d9  mov     rcx, rbx; Block
0x14000c6dc  call    _free_base
0x14000c6e1  jmp     short loc_14000C6F2
0x14000c6e3  mov     rax, [rsi+8]
0x14000c6e7  mov     edi, r13d
0x14000c6ea  mov     [rax], rbx
0x14000c6ed  add     qword ptr [rsi+8], 8
0x14000c6f2  xor     ecx, ecx; Block
0x14000c6f4  call    _free_base
0x14000c6f9  mov     eax, edi
0x14000c6fb  jmp     loc_14000C664
0x14000c700  xor     r9d, r9d; LineNo
0x14000c703  mov     [rsp+58h+Reserved], r13; Reserved
0x14000c708  xor     r8d, r8d; FileName
0x14000c70b  xor     edx, edx; FunctionName
0x14000c70d  xor     ecx, ecx; Expression
0x14000c70f  call    _invoke_watson
0x14000c715  xor     r9d, r9d; LineNo
0x14000c718  mov     [rsp+58h+Reserved], r13; Reserved
0x14000c71d  xor     r8d, r8d; FileName
0x14000c720  xor     edx, edx; FunctionName
0x14000c722  xor     ecx, ecx; Expression
0x14000c724  call    _invoke_watson

// ===== ??$expand_argument_wildcards@_W@@YAHQEA_W0AEAV?$argument_list@_W@?A0x7b96f60e@@@Z @ 0x14000c72c =====

0x14000c72c  mov     [rsp+arg_18], rbx
0x14000c731  push    rbp
0x14000c732  push    rsi
0x14000c733  push    rdi
0x14000c734  push    r14
0x14000c736  push    r15
0x14000c738  sub     rsp, 290h
0x14000c73f  mov     rax, cs:__security_cookie
0x14000c746  xor     rax, rsp
0x14000c749  mov     [rsp+2B8h+var_38], rax
0x14000c751  mov     r14, r8
0x14000c754  mov     rbp, rcx
0x14000c757  mov     r8, 200000000801h
0x14000c761  jmp     short loc_14000C77D
0x14000c763  movzx   eax, word ptr [rdx]
0x14000c766  sub     ax, 2Fh ; '/'
0x14000c76a  cmp     ax, 2Dh ; '-'
0x14000c76e  ja      short loc_14000C779
0x14000c770  movzx   eax, ax
0x14000c773  bt      r8, rax
0x14000c777  jb      short loc_14000C782
0x14000c779  sub     rdx, 2
0x14000c77d  cmp     rdx, rcx
0x14000c780  jnz     short loc_14000C763
0x14000c782  movzx   ecx, word ptr [rdx]
0x14000c785  cmp     cx, 3Ah ; ':'
0x14000c789  jnz     short loc_14000C7A9
0x14000c78b  lea     rax, [rbp+2]
0x14000c78f  cmp     rdx, rax
0x14000c792  jz      short loc_14000C7A9
0x14000c794  mov     r9, r14
0x14000c797  xor     r8d, r8d; MaxCount
0x14000c79a  xor     edx, edx; wchar_t *
0x14000c79c  mov     rcx, rbp; Source
0x14000c79f  call    ??$copy_and_add_argument_to_buffer@_W@@YAHQEB_W0_KAEAV?$argument_list@_W@?A0x7b96f60e@@@Z
0x14000c7a4  jmp     loc_14000C82E
0x14000c7a9  sub     cx, 2Fh ; '/'
0x14000c7ad  xor     edi, edi
0x14000c7af  cmp     cx, 2Dh ; '-'
0x14000c7b3  ja      short loc_14000C7C1
0x14000c7b5  movzx   eax, cx
0x14000c7b8  bt      r8, rax
0x14000c7bc  lea     eax, [rdi+1]
0x14000c7bf  jb      short loc_14000C7C3
0x14000c7c1  mov     eax, edi
0x14000c7c3  sub     rdx, rbp
0x14000c7c6  lea     rcx, [rsp+2B8h+FindFileData]
0x14000c7cb  sar     rdx, 1
0x14000c7ce  mov     r8d, 250h
0x14000c7d4  inc     rdx
0x14000c7d7  neg     al
0x14000c7d9  sbb     r15, r15
0x14000c7dc  and     r15, rdx
0x14000c7df  xor     edx, edx
0x14000c7e1  call    sub_140005B30
0x14000c7e6  xor     r9d, r9d; fSearchOp
0x14000c7e9  mov     [rsp+2B8h+dwAdditionalFlags], edi; dwAdditionalFlags
0x14000c7ed  lea     r8, [rsp+2B8h+FindFileData]; lpFindFileData
0x14000c7f2  mov     [rsp+2B8h+lpSearchFilter], rdi; lpSearchFilter
0x14000c7f7  xor     edx, edx; fInfoLevelId
0x14000c7f9  mov     rcx, rbp; lpFileName
0x14000c7fc  call    cs:FindFirstFileExW; KERNEL32
0x14000c802  mov     rbx, rax
0x14000c805  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x14000c809  jnz     short loc_14000C855
0x14000c80b  mov     r9, r14
0x14000c80e  xor     r8d, r8d; MaxCount
0x14000c811  xor     edx, edx; wchar_t *
0x14000c813  mov     rcx, rbp; Source
0x14000c816  call    ??$copy_and_add_argument_to_buffer@_W@@YAHQEB_W0_KAEAV?$argument_list@_W@?A0x7b96f60e@@@Z
0x14000c81b  mov     edi, eax
0x14000c81d  cmp     rbx, 0FFFFFFFFFFFFFFFFh
0x14000c821  jz      short loc_14000C82C
0x14000c823  mov     rcx, rbx; hFindFile
0x14000c826  call    cs:FindClose; KERNEL32
0x14000c82c  mov     eax, edi
0x14000c82e  mov     rcx, [rsp+2B8h+var_38]
0x14000c836  xor     rcx, rsp; StackCookie
0x14000c839  call    __security_check_cookie
0x14000c83e  mov     rbx, [rsp+2B8h+arg_18]
0x14000c846  add     rsp, 290h
0x14000c84d  pop     r15
0x14000c84f  pop     r14
0x14000c851  pop     rdi
0x14000c852  pop     rsi
0x14000c853  pop     rbp
0x14000c854  retn
0x14000c855  mov     rsi, [r14+8]
0x14000c859  sub     rsi, [r14]
0x14000c85c  sar     rsi, 3
0x14000c860  cmp     [rsp+2B8h+Source], 2Eh ; '.'
0x14000c866  jnz     short loc_14000C87E
0x14000c868  cmp     [rsp+2B8h+var_25A], di
0x14000c86d  jz      short loc_14000C895
0x14000c86f  cmp     [rsp+2B8h+var_25A], 2Eh ; '.'
0x14000c875  jnz     short loc_14000C87E
0x14000c877  cmp     [rsp+2B8h+var_258], di
0x14000c87c  jz      short loc_14000C895
0x14000c87e  mov     r9, r14
0x14000c881  lea     rcx, [rsp+2B8h+Source]; Source
0x14000c886  mov     r8, r15; MaxCount
0x14000c889  mov     rdx, rbp; wchar_t *
0x14000c88c  call    ??$copy_and_add_argument_to_buffer@_W@@YAHQEB_W0_KAEAV?$argument_list@_W@?A0x7b96f60e@@@Z
0x14000c891  test    eax, eax
0x14000c893  jnz     short loc_14000C81B
0x14000c895  lea     rdx, [rsp+2B8h+FindFileData]; lpFindFileData
0x14000c89a  mov     rcx, rbx; hFindFile
0x14000c89d  call    cs:FindNextFileW; KERNEL32
0x14000c8a3  test    eax, eax
0x14000c8a5  jnz     short loc_14000C860
0x14000c8a7  mov     rax, [r14]
0x14000c8aa  mov     rdx, [r14+8]
0x14000c8ae  sub     rdx, rax
0x14000c8b1  sar     rdx, 3
0x14000c8b5  cmp     rsi, rdx
0x14000c8b8  jz      loc_14000C81D
0x14000c8be  sub     rdx, rsi; NumOfElements
0x14000c8c1  lea     rcx, [rax+rsi*8]; Base
0x14000c8c5  lea     r9, CompareFunction; CompareFunction
0x14000c8cc  mov     r8d, 8; SizeOfElements
0x14000c8d2  call    qsort
0x14000c8d7  jmp     loc_14000C81D

// ===== unknown_libname_19 @ 0x14000c8dc =====

0x14000c8dc  mov     [rsp+arg_0], rbx
0x14000c8e1  mov     [rsp+arg_8], rbp
0x14000c8e6  mov     [rsp+arg_10], rsi
0x14000c8eb  push    rdi
0x14000c8ec  sub     rsp, 20h
0x14000c8f0  mov     rsi, [rcx+10h]
0x14000c8f4  mov     rdi, rcx
0x14000c8f7  cmp     [rcx+8], rsi
0x14000c8fb  jz      short loc_14000C904
0x14000c8fd  xor     eax, eax
0x14000c8ff  jmp     loc_14000C98E
0x14000c904  xor     ebx, ebx
0x14000c906  cmp     [rcx], rbx
0x14000c909  jnz     short loc_14000C93D
0x14000c90b  lea     edx, [rbx+8]; Size
0x14000c90e  lea     ecx, [rbx+4]; Count
0x14000c911  call    _calloc_base
0x14000c916  xor     ecx, ecx; Block
0x14000c918  mov     [rdi], rax
0x14000c91b  call    _free_base
0x14000c920  mov     rax, [rdi]
0x14000c923  test    rax, rax
0x14000c926  jnz     short loc_14000C92F
0x14000c928  mov     eax, 0Ch
0x14000c92d  jmp     short loc_14000C98E
0x14000c92f  mov     [rdi+8], rax
0x14000c933  add     rax, 20h ; ' '
0x14000c937  mov     [rdi+10h], rax
0x14000c93b  jmp     short loc_14000C8FD
0x14000c93d  sub     rsi, [rcx]
0x14000c940  mov     rax, 7FFFFFFFFFFFFFFFh
0x14000c94a  sar     rsi, 3
0x14000c94e  cmp     rsi, rax
0x14000c951  ja      short loc_14000C928
0x14000c953  mov     rcx, [rcx]; Block
0x14000c956  lea     rbp, [rsi+rsi]
0x14000c95a  mov     rdx, rbp; Count
0x14000c95d  mov     r8d, 8; Size
0x14000c963  call    j__recalloc_base
0x14000c968  test    rax, rax
0x14000c96b  jnz     short loc_14000C972
0x14000c96d  lea     ebx, [rax+0Ch]
0x14000c970  jmp     short loc_14000C985
0x14000c972  lea     rcx, [rax+rsi*8]
0x14000c976  mov     [rdi], rax
0x14000c979  mov     [rdi+8], rcx
0x14000c97d  lea     rcx, [rax+rbp*8]
0x14000c981  mov     [rdi+10h], rcx
0x14000c985  xor     ecx, ecx; Block
0x14000c987  call    _free_base
0x14000c98c  mov     eax, ebx
0x14000c98e  mov     rbx, [rsp+28h+arg_0]
0x14000c993  mov     rbp, [rsp+28h+arg_8]
0x14000c998  mov     rsi, [rsp+28h+arg_10]
0x14000c99d  add     rsp, 20h
0x14000c9a1  pop     rdi
0x14000c9a2  retn

// ===== j_??$common_expand_argv_wildcards@_W@@YAHQEAPEA_WQEAPEAPEA_W@Z @ 0x14000c9a4 =====

0x14000c9a4  jmp     ??$common_expand_argv_wildcards@_W@@YAHQEAPEA_WQEAPEAPEA_W@Z

// ===== ??$?RV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@V_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@$$QEAV_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@Z @ 0x14000c9ac =====

0x14000c9ac  mov     [rsp+arg_0], rbx
0x14000c9b1  mov     [rsp+arg_18], r9
0x14000c9b6  push    rdi
0x14000c9b7  sub     rsp, 20h
0x14000c9bb  mov     rbx, r9
0x14000c9be  mov     rdi, r8
0x14000c9c1  mov     ecx, [rdx]
0x14000c9c3  call    sub_14000D540
0x14000c9c8  nop
0x14000c9c9  mov     rcx, rdi
0x14000c9cc  call    ??R_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@QEBAXXZ
0x14000c9d1  nop
0x14000c9d2  mov     ecx, [rbx]
0x14000c9d4  call    sub_14000D594
0x14000c9d9  mov     rbx, [rsp+28h+arg_0]
0x14000c9de  add     rsp, 20h
0x14000c9e2  pop     rdi
0x14000c9e3  retn
0x1400139e1  push    rbp
0x1400139e3  sub     rsp, 20h
0x1400139e7  mov     rbp, rdx
0x1400139ea  mov     rax, [rbp+48h]
0x1400139ee  mov     ecx, [rax]
0x1400139f0  add     rsp, 20h
0x1400139f4  pop     rbp
0x1400139f5  jmp     sub_14000D594

// ===== ??R_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@QEBAXXZ @ 0x14000c9e4 =====

0x14000c9e4  mov     [rsp+arg_0], rbx
0x14000c9e9  mov     [rsp+arg_8], rsi
0x14000c9ee  push    rdi
0x14000c9ef  sub     rsp, 20h
0x14000c9f3  mov     rax, [rcx]
0x14000c9f6  mov     rbx, rcx
0x14000c9f9  mov     rdx, [rax]
0x14000c9fc  mov     rax, [rdx+88h]
0x14000ca03  mov     edx, [rax+4]
0x14000ca06  mov     cs:dword_140021BF4, edx
0x14000ca0c  mov     rax, [rcx]
0x14000ca0f  mov     rdx, [rax]
0x14000ca12  mov     rax, [rdx+88h]
0x14000ca19  mov     edx, [rax+8]
0x14000ca1c  mov     cs:dword_140021BF8, edx
0x14000ca22  mov     rax, [rcx]
0x14000ca25  mov     rdx, [rax]
0x14000ca28  mov     rax, [rdx+88h]
0x14000ca2f  mov     rcx, [rax+220h]
0x14000ca36  mov     cs:qword_140021C10, rcx
0x14000ca3d  mov     rax, [rbx]
0x14000ca40  mov     rcx, [rax]
0x14000ca43  mov     rax, [rcx+88h]
0x14000ca4a  add     rax, 0Ch
0x14000ca4e  jz      short loc_14000CA67
0x14000ca50  movsd   xmm0, qword ptr [rax]
0x14000ca54  movsd   cs:qword_140021C00, xmm0
0x14000ca5c  mov     eax, [rax+8]
0x14000ca5f  mov     cs:dword_140021C08, eax
0x14000ca65  jmp     short loc_14000CA86
0x14000ca67  xor     eax, eax
0x14000ca69  mov     cs:qword_140021C00, rax
0x14000ca70  mov     cs:dword_140021C08, eax
0x14000ca76  call    _errno
0x14000ca7b  mov     dword ptr [rax], 16h
0x14000ca81  call    _invalid_parameter_noinfo
0x14000ca86  mov     rax, [rbx]
0x14000ca89  mov     edi, 2
0x14000ca8e  mov     rcx, [rax]
0x14000ca91  lea     esi, [rdi+7Eh]
0x14000ca94  mov     rax, [rcx+88h]
0x14000ca9b  lea     rcx, xmmword_140020870
0x14000caa2  add     rax, 18h
0x14000caa6  jz      short loc_14000CAFA
0x14000caa8  mov     edx, edi
0x14000caaa  movups  xmm0, xmmword ptr [rax]
0x14000caad  movups  xmmword ptr [rcx], xmm0
0x14000cab0  movups  xmm1, xmmword ptr [rax+10h]
0x14000cab4  movups  xmmword ptr [rcx+10h], xmm1
0x14000cab8  movups  xmm0, xmmword ptr [rax+20h]
0x14000cabc  movups  xmmword ptr [rcx+20h], xmm0
0x14000cac0  movups  xmm1, xmmword ptr [rax+30h]
0x14000cac4  movups  xmmword ptr [rcx+30h], xmm1
0x14000cac8  movups  xmm0, xmmword ptr [rax+40h]
0x14000cacc  movups  xmmword ptr [rcx+40h], xmm0
0x14000cad0  movups  xmm1, xmmword ptr [rax+50h]
0x14000cad4  movups  xmmword ptr [rcx+50h], xmm1
0x14000cad8  movups  xmm0, xmmword ptr [rax+60h]
0x14000cadc  movups  xmmword ptr [rcx+60h], xmm0
0x14000cae0  add     rcx, rsi
0x14000cae3  movups  xmm1, xmmword ptr [rax+70h]
0x14000cae7  add     rax, rsi
0x14000caea  movups  xmmword ptr [rcx-10h], xmm1
0x14000caee  sub     rdx, 1
0x14000caf2  jnz     short loc_14000CAAA
0x14000caf4  mov     al, [rax]
0x14000caf6  mov     [rcx], al
0x14000caf8  jmp     short loc_14000CB17
0x14000cafa  xor     edx, edx
0x14000cafc  mov     r8d, 101h
0x14000cb02  call    sub_140005B30
0x14000cb07  call    _errno
0x14000cb0c  mov     dword ptr [rax], 16h
0x14000cb12  call    _invalid_parameter_noinfo
0x14000cb17  mov     rax, [rbx]
0x14000cb1a  mov     rcx, [rax]
0x14000cb1d  mov     rax, [rcx+88h]
0x14000cb24  lea     rcx, xmmword_140020980
0x14000cb2b  add     rax, 119h
0x14000cb31  jz      short loc_14000CB7F
0x14000cb33  movups  xmm0, xmmword ptr [rax]
0x14000cb36  movups  xmmword ptr [rcx], xmm0
0x14000cb39  movups  xmm1, xmmword ptr [rax+10h]
0x14000cb3d  movups  xmmword ptr [rcx+10h], xmm1
0x14000cb41  movups  xmm0, xmmword ptr [rax+20h]
0x14000cb45  movups  xmmword ptr [rcx+20h], xmm0
0x14000cb49  movups  xmm1, xmmword ptr [rax+30h]
0x14000cb4d  movups  xmmword ptr [rcx+30h], xmm1
0x14000cb51  movups  xmm0, xmmword ptr [rax+40h]
0x14000cb55  movups  xmmword ptr [rcx+40h], xmm0
0x14000cb59  movups  xmm1, xmmword ptr [rax+50h]
0x14000cb5d  movups  xmmword ptr [rcx+50h], xmm1
0x14000cb61  movups  xmm0, xmmword ptr [rax+60h]
0x14000cb65  movups  xmmword ptr [rcx+60h], xmm0
0x14000cb69  add     rcx, rsi
0x14000cb6c  movups  xmm1, xmmword ptr [rax+70h]
0x14000cb70  add     rax, rsi
0x14000cb73  movups  xmmword ptr [rcx-10h], xmm1
0x14000cb77  sub     rdi, 1
0x14000cb7b  jnz     short loc_14000CB33
0x14000cb7d  jmp     short loc_14000CB9C
0x14000cb7f  xor     edx, edx
0x14000cb81  mov     r8d, 100h
0x14000cb87  call    sub_140005B30
0x14000cb8c  call    _errno
0x14000cb91  mov     dword ptr [rax], 16h
0x14000cb97  call    _invalid_parameter_noinfo
0x14000cb9c  mov     rcx, cs:Block
0x14000cba3  or      eax, 0FFFFFFFFh
0x14000cba6  lock xadd [rcx], eax
0x14000cbaa  cmp     eax, 1
0x14000cbad  jnz     short loc_14000CBC7
0x14000cbaf  mov     rcx, cs:Block; Block
0x14000cbb6  lea     rax, unk_140020540
0x14000cbbd  cmp     rcx, rax
0x14000cbc0  jz      short loc_14000CBC7
0x14000cbc2  call    _free_base
0x14000cbc7  mov     rax, [rbx]
0x14000cbca  mov     rcx, [rax]
0x14000cbcd  mov     rax, [rcx+88h]
0x14000cbd4  mov     cs:Block, rax
0x14000cbdb  mov     rax, [rbx]
0x14000cbde  mov     rcx, [rax]
0x14000cbe1  mov     rax, [rcx+88h]
0x14000cbe8  lock inc dword ptr [rax]
0x14000cbeb  mov     rbx, [rsp+28h+arg_0]
0x14000cbf0  mov     rsi, [rsp+28h+arg_8]
0x14000cbf5  add     rsp, 20h
0x14000cbf9  pop     rdi
0x14000cbfa  retn

// ===== ?getSystemCP@@YAHH@Z @ 0x14000cbfc =====

0x14000cbfc  push    rbx
0x14000cbfe  sub     rsp, 40h
0x14000cc02  mov     ebx, ecx
0x14000cc04  xor     edx, edx; struct __crt_locale_pointers *
0x14000cc06  lea     rcx, [rsp+48h+var_28]; this
0x14000cc0b  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000cc10  and     cs:dword_140021C0C, 0
0x14000cc17  cmp     ebx, 0FFFFFFFEh
0x14000cc1a  jnz     short loc_14000CC2E
0x14000cc1c  mov     cs:dword_140021C0C, 1
0x14000cc26  call    cs:GetOEMCP; KERNEL32
0x14000cc2c  jmp     short loc_14000CC43
0x14000cc2e  cmp     ebx, 0FFFFFFFDh
0x14000cc31  jnz     short loc_14000CC47
0x14000cc33  mov     cs:dword_140021C0C, 1
0x14000cc3d  call    cs:GetACP; KERNEL32
0x14000cc43  mov     ebx, eax
0x14000cc45  jmp     short loc_14000CC5E
0x14000cc47  cmp     ebx, 0FFFFFFFCh
0x14000cc4a  jnz     short loc_14000CC5E
0x14000cc4c  mov     rax, [rsp+48h+var_20]
0x14000cc51  mov     cs:dword_140021C0C, 1
0x14000cc5b  mov     ebx, [rax+0Ch]
0x14000cc5e  cmp     [rsp+48h+var_10], 0
0x14000cc63  jz      short loc_14000CC71
0x14000cc65  mov     rcx, [rsp+48h+var_28]
0x14000cc6a  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x14000cc71  mov     eax, ebx
0x14000cc73  add     rsp, 40h
0x14000cc77  pop     rbx
0x14000cc78  retn

// ===== ?setSBCS@@YAXPEAU__crt_multibyte_data@@@Z @ 0x14000cc7c =====

0x14000cc7c  mov     [rsp+arg_0], rbx
0x14000cc81  mov     [rsp+arg_8], rbp
0x14000cc86  mov     [rsp+arg_10], rsi
0x14000cc8b  push    rdi
0x14000cc8c  sub     rsp, 20h
0x14000cc90  lea     rbx, [rcx+18h]
0x14000cc94  mov     rsi, rcx
0x14000cc97  mov     ebp, 101h
0x14000cc9c  mov     rcx, rbx
0x14000cc9f  mov     r8d, ebp
0x14000cca2  xor     edx, edx
0x14000cca4  call    sub_140005B30
0x14000cca9  xor     eax, eax
0x14000ccab  lea     rdi, [rsi+0Ch]
0x14000ccaf  mov     [rsi+4], rax
0x14000ccb3  mov     ecx, 6
0x14000ccb8  mov     [rsi+220h], rax
0x14000ccbf  movzx   eax, ax
0x14000ccc2  rep stosw
0x14000ccc5  lea     rdi, unk_140020540
0x14000cccc  sub     rdi, rsi
0x14000cccf  mov     al, [rdi+rbx]
0x14000ccd2  mov     [rbx], al
0x14000ccd4  inc     rbx
0x14000ccd7  sub     rbp, 1
0x14000ccdb  jnz     short loc_14000CCCF
0x14000ccdd  lea     rcx, [rsi+119h]
0x14000cce4  mov     edx, 100h
0x14000cce9  mov     al, [rcx+rdi]
0x14000ccec  mov     [rcx], al
0x14000ccee  inc     rcx
0x14000ccf1  sub     rdx, 1
0x14000ccf5  jnz     short loc_14000CCE9
0x14000ccf7  mov     rbx, [rsp+28h+arg_0]
0x14000ccfc  mov     rbp, [rsp+28h+arg_8]
0x14000cd01  mov     rsi, [rsp+28h+arg_10]
0x14000cd06  add     rsp, 20h
0x14000cd0a  pop     rdi
0x14000cd0b  retn

// ===== ?setSBUpLow@@YAXPEAU__crt_multibyte_data@@@Z @ 0x14000cd0c =====

0x14000cd0c  mov     [rsp-8+arg_8], rbx
0x14000cd11  mov     [rsp-8+arg_10], rdi
0x14000cd16  push    rbp
0x14000cd17  lea     rbp, [rsp-680h]
0x14000cd1f  sub     rsp, 780h
0x14000cd26  mov     rax, cs:__security_cookie
0x14000cd2d  xor     rax, rsp
0x14000cd30  mov     [rbp+680h+var_10], rax
0x14000cd37  mov     rdi, rcx
0x14000cd3a  lea     rdx, [rsp+780h+CPInfo]; lpCPInfo
0x14000cd3f  mov     ecx, [rcx+4]; CodePage
0x14000cd42  call    cs:GetCPInfo; KERNEL32
0x14000cd48  mov     ebx, 100h
0x14000cd4d  test    eax, eax
0x14000cd4f  jz      loc_14000CE8B
0x14000cd55  xor     eax, eax
0x14000cd57  lea     rcx, [rsp+780h+MultiByteStr]
0x14000cd5c  mov     [rcx], al
0x14000cd5e  inc     eax
0x14000cd60  inc     rcx
0x14000cd63  cmp     eax, ebx
0x14000cd65  jb      short loc_14000CD5C
0x14000cd67  mov     al, [rsp+780h+CPInfo.LeadByte]
0x14000cd6b  lea     rdx, [rsp+780h+CPInfo.LeadByte]
0x14000cd70  mov     [rsp+780h+MultiByteStr], 20h ; ' '
0x14000cd75  jmp     short loc_14000CD99
0x14000cd77  movzx   r8d, byte ptr [rdx+1]
0x14000cd7c  movzx   ecx, al
0x14000cd7f  jmp     short loc_14000CD8E
0x14000cd81  cmp     ecx, ebx
0x14000cd83  jnb     short loc_14000CD93
0x14000cd85  mov     eax, ecx
0x14000cd87  mov     [rsp+rcx+780h+MultiByteStr], 20h ; ' '
0x14000cd8c  inc     ecx
0x14000cd8e  cmp     ecx, r8d
0x14000cd91  jbe     short loc_14000CD81
0x14000cd93  add     rdx, 2
0x14000cd97  mov     al, [rdx]
0x14000cd99  test    al, al
0x14000cd9b  jnz     short loc_14000CD77
0x14000cd9d  mov     eax, [rdi+4]
0x14000cda0  lea     r8, [rsp+780h+MultiByteStr]; lpMultiByteStr
0x14000cda5  and     [rsp+780h+var_750], 0
0x14000cdaa  mov     r9d, ebx; cbMultiByte
0x14000cdad  mov     [rsp+780h+CodePage], eax; CodePage
0x14000cdb1  mov     edx, 1; dwInfoType
0x14000cdb6  lea     rax, [rbp+680h+CharType]
0x14000cdbd  xor     ecx, ecx; struct __crt_locale_pointers *
0x14000cdbf  mov     [rsp+780h+lpCharType], rax; lpCharType
0x14000cdc4  call    __acrt_GetStringTypeA
0x14000cdc9  and     [rsp+780h+var_740], 0
0x14000cdce  lea     r9, [rsp+780h+MultiByteStr]; char *
0x14000cdd3  mov     eax, [rdi+4]
0x14000cdd6  mov     r8d, ebx; unsigned int
0x14000cdd9  mov     rdx, [rdi+220h]; wchar_t *
0x14000cde0  xor     ecx, ecx; struct __crt_locale_pointers *
0x14000cde2  mov     [rsp+780h+var_748], eax; int
0x14000cde6  lea     rax, [rbp+680h+var_610]
0x14000cdea  mov     [rsp+780h+var_750], ebx; int
0x14000cdee  mov     qword ptr [rsp+780h+CodePage], rax; char *
0x14000cdf3  mov     dword ptr [rsp+780h+lpCharType], ebx; int
0x14000cdf7  call    __acrt_LCMapStringA
0x14000cdfc  and     [rsp+780h+var_740], 0
0x14000ce01  lea     r9, [rsp+780h+MultiByteStr]; char *
0x14000ce06  mov     eax, [rdi+4]
0x14000ce09  mov     r8d, 200h; unsigned int
0x14000ce0f  mov     rdx, [rdi+220h]; wchar_t *
0x14000ce16  xor     ecx, ecx; struct __crt_locale_pointers *
0x14000ce18  mov     [rsp+780h+var_748], eax; int
0x14000ce1c  lea     rax, [rbp+680h+var_510]
0x14000ce23  mov     [rsp+780h+var_750], ebx; int
0x14000ce27  mov     qword ptr [rsp+780h+CodePage], rax; char *
0x14000ce2c  mov     dword ptr [rsp+780h+lpCharType], ebx; int
0x14000ce30  call    __acrt_LCMapStringA
0x14000ce35  lea     r8, [rbp+680h+var_610]
0x14000ce39  sub     r8, rdi
0x14000ce3c  lea     r9, [rbp+680h+var_510]
0x14000ce43  sub     r9, rdi
0x14000ce46  lea     rdx, [rbp+680h+CharType]
0x14000ce4d  lea     rcx, [rdi+19h]
0x14000ce51  test    byte ptr [rdx], 1
0x14000ce54  jz      short loc_14000CE60
0x14000ce56  or      byte ptr [rcx], 10h
0x14000ce59  mov     al, [r8+rcx-19h]
0x14000ce5e  jmp     short loc_14000CE6D
0x14000ce60  test    byte ptr [rdx], 2
0x14000ce63  jz      short loc_14000CE75
0x14000ce65  or      byte ptr [rcx], 20h
0x14000ce68  mov     al, [r9+rcx-19h]
0x14000ce6d  mov     [rcx+100h], al
0x14000ce73  jmp     short loc_14000CE7C
0x14000ce75  mov     byte ptr [rcx+100h], 0
0x14000ce7c  inc     rcx
0x14000ce7f  add     rdx, 2
0x14000ce83  sub     rbx, 1
0x14000ce87  jnz     short loc_14000CE51
0x14000ce89  jmp     short loc_14000CECA
0x14000ce8b  xor     edx, edx
0x14000ce8d  lea     rcx, [rdi+19h]
0x14000ce91  lea     r8d, [rdx-61h]
0x14000ce95  lea     eax, [r8+20h]
0x14000ce99  cmp     eax, 19h
0x14000ce9c  ja      short loc_14000CEA6
0x14000ce9e  or      byte ptr [rcx], 10h
0x14000cea1  lea     eax, [rdx+20h]
0x14000cea4  jmp     short loc_14000CEB2
0x14000cea6  cmp     r8d, 19h
0x14000ceaa  ja      short loc_14000CEBA
0x14000ceac  or      byte ptr [rcx], 20h
0x14000ceaf  lea     eax, [rdx-20h]
0x14000ceb2  mov     [rcx+100h], al
0x14000ceb8  jmp     short loc_14000CEC1
0x14000ceba  mov     byte ptr [rcx+100h], 0
0x14000cec1  inc     edx
0x14000cec3  inc     rcx
0x14000cec6  cmp     edx, ebx
0x14000cec8  jb      short loc_14000CE91
0x14000ceca  mov     rcx, [rbp+680h+var_10]
0x14000ced1  xor     rcx, rsp; StackCookie
0x14000ced4  call    __security_check_cookie
0x14000ced9  lea     r11, [rsp+780h+var_s0]
0x14000cee1  mov     rbx, [r11+18h]
0x14000cee5  mov     rdi, [r11+20h]
0x14000cee9  mov     rsp, r11
0x14000ceec  pop     rbp
0x14000ceed  retn

// ===== ?setmbcp_internal@@YAHH_N@Z @ 0x14000cef0 =====

0x14000cef0  mov     [rsp-18h+arg_0], rbx
0x14000cef5  push    rbp
0x14000cef6  push    rsi
0x14000cef7  push    rdi
0x14000cef8  mov     rbp, rsp
0x14000cefb  sub     rsp, 40h
0x14000ceff  mov     sil, dl
0x14000cf02  mov     ebx, ecx
0x14000cf04  call    __acrt_getptd
0x14000cf09  mov     [rbp+var_18], rax
0x14000cf0d  call    __acrt_update_thread_multibyte_data
0x14000cf12  mov     ecx, ebx; int
0x14000cf14  call    ?getSystemCP@@YAHH@Z
0x14000cf19  mov     rcx, [rbp+var_18]
0x14000cf1d  mov     edi, eax
0x14000cf1f  mov     r8, [rcx+88h]
0x14000cf26  cmp     eax, [r8+4]
0x14000cf2a  jnz     short loc_14000CF33
0x14000cf2c  xor     eax, eax
0x14000cf2e  jmp     loc_14000CFEB
0x14000cf33  mov     ecx, 228h; Size
0x14000cf38  call    _malloc_base
0x14000cf3d  mov     rbx, rax
0x14000cf40  test    rax, rax
0x14000cf43  jz      loc_14000CFDE
0x14000cf49  mov     rax, [rbp+var_18]
0x14000cf4d  mov     edx, 4
0x14000cf52  mov     rcx, rbx
0x14000cf55  mov     rax, [rax+88h]
0x14000cf5c  lea     r8d, [rdx+7Ch]
0x14000cf60  movups  xmm0, xmmword ptr [rax]
0x14000cf63  movups  xmmword ptr [rcx], xmm0
0x14000cf66  movups  xmm1, xmmword ptr [rax+10h]
0x14000cf6a  movups  xmmword ptr [rcx+10h], xmm1
0x14000cf6e  movups  xmm0, xmmword ptr [rax+20h]
0x14000cf72  movups  xmmword ptr [rcx+20h], xmm0
0x14000cf76  movups  xmm1, xmmword ptr [rax+30h]
0x14000cf7a  movups  xmmword ptr [rcx+30h], xmm1
0x14000cf7e  movups  xmm0, xmmword ptr [rax+40h]
0x14000cf82  movups  xmmword ptr [rcx+40h], xmm0
0x14000cf86  movups  xmm1, xmmword ptr [rax+50h]
0x14000cf8a  movups  xmmword ptr [rcx+50h], xmm1
0x14000cf8e  movups  xmm0, xmmword ptr [rax+60h]
0x14000cf92  movups  xmmword ptr [rcx+60h], xmm0
0x14000cf96  add     rcx, r8
0x14000cf99  movups  xmm1, xmmword ptr [rax+70h]
0x14000cf9d  add     rax, r8
0x14000cfa0  movups  xmmword ptr [rcx-10h], xmm1
0x14000cfa4  sub     rdx, 1
0x14000cfa8  jnz     short loc_14000CF60
0x14000cfaa  movups  xmm0, xmmword ptr [rax]
0x14000cfad  movups  xmmword ptr [rcx], xmm0
0x14000cfb0  movups  xmm1, xmmword ptr [rax+10h]
0x14000cfb4  movups  xmmword ptr [rcx+10h], xmm1
0x14000cfb8  mov     rax, [rax+20h]
0x14000cfbc  mov     [rcx+20h], rax
0x14000cfc0  mov     ecx, edi
0x14000cfc2  and     [rbx], edx
0x14000cfc4  mov     rdx, rbx
0x14000cfc7  call    _setmbcp_nolock
0x14000cfcc  mov     edi, eax
0x14000cfce  cmp     eax, 0FFFFFFFFh
0x14000cfd1  jnz     short loc_14000CFF8
0x14000cfd3  call    _errno
0x14000cfd8  mov     dword ptr [rax], 16h
0x14000cfde  or      edi, 0FFFFFFFFh
0x14000cfe1  mov     rcx, rbx; Block
0x14000cfe4  call    _free_base
0x14000cfe9  mov     eax, edi
0x14000cfeb  mov     rbx, [rsp+40h+arg_0]
0x14000cff0  add     rsp, 40h
0x14000cff4  pop     rdi
0x14000cff5  pop     rsi
0x14000cff6  pop     rbp
0x14000cff7  retn
0x14000cff8  test    sil, sil
0x14000cffb  jnz     short loc_14000D002
0x14000cffd  call    __acrt_set_locale_changed
0x14000d002  mov     rax, [rbp+var_18]
0x14000d006  mov     rcx, [rax+88h]
0x14000d00d  or      eax, 0FFFFFFFFh
0x14000d010  lock xadd [rcx], eax
0x14000d014  cmp     eax, 1
0x14000d017  jnz     short loc_14000D035
0x14000d019  mov     rax, [rbp+var_18]
0x14000d01d  mov     rcx, [rax+88h]; Block
0x14000d024  lea     rax, unk_140020540
0x14000d02b  cmp     rcx, rax
0x14000d02e  jz      short loc_14000D035
0x14000d030  call    _free_base
0x14000d035  mov     dword ptr [rbx], 1
0x14000d03b  mov     rcx, rbx
0x14000d03e  mov     rax, [rbp+var_18]
0x14000d042  xor     ebx, ebx
0x14000d044  mov     [rax+88h], rcx
0x14000d04b  mov     rax, [rbp+var_18]
0x14000d04f  test    byte ptr [rax+3A8h], 2
0x14000d056  jnz     short loc_14000CFE1
0x14000d058  test    byte ptr cs:dword_140020B30, 1
0x14000d05f  jnz     short loc_14000CFE1
0x14000d061  lea     rax, [rbp+var_18]
0x14000d065  mov     [rbp+var_10], rax
0x14000d069  lea     r9, [rbp+arg_18]
0x14000d06d  lea     eax, [rbx+5]
0x14000d070  lea     r8, [rbp+var_10]
0x14000d074  mov     [rbp+arg_18], eax
0x14000d077  lea     rdx, [rbp+var_20]
0x14000d07b  mov     [rbp+var_20], eax
0x14000d07e  lea     rcx, [rbp+arg_10]
0x14000d082  call    ??$?RV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@V_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@?$__crt_seh_guarded_call@X@@QEAAX$$QEAV_lambda_99476a1ad63dd22509b5d3e65b0ffc95_@@AEAV_lambda_ad1ced32f4ac17aa236e5ef05d6b3b7c_@@$$QEAV_lambda_f7424dd8d45958661754dc4f2697e9c3_@@@Z
0x14000d087  mov     rax, cs:off_140020420
0x14000d08e  test    sil, sil
0x14000d091  cmovnz  rax, cs:Block
0x14000d099  mov     cs:off_140020420, rax
0x14000d0a0  jmp     loc_14000CFE1

// ===== __acrt_initialize_multibyte @ 0x14000d0a8 =====

0x14000d0a8  sub     rsp, 28h
0x14000d0ac  cmp     cs:byte_140021C18, 0
0x14000d0b3  jnz     short loc_14000D0C8
0x14000d0b5  mov     dl, 1; bool
0x14000d0b7  mov     ecx, 0FFFFFFFDh; int
0x14000d0bc  call    ?setmbcp_internal@@YAHH_N@Z
0x14000d0c1  mov     cs:byte_140021C18, 1
0x14000d0c8  mov     al, 1
0x14000d0ca  add     rsp, 28h
0x14000d0ce  retn

// ===== __acrt_update_thread_multibyte_data @ 0x14000d0d0 =====

0x14000d0d0  mov     [rsp+arg_8], rbx
0x14000d0d5  push    rdi
0x14000d0d6  sub     rsp, 20h
0x14000d0da  call    __acrt_getptd
0x14000d0df  mov     rdi, rax
0x14000d0e2  mov     ecx, cs:dword_140020B30
0x14000d0e8  test    [rax+3A8h], ecx
0x14000d0ee  jz      short loc_14000D103
0x14000d0f0  cmp     qword ptr [rax+90h], 0
0x14000d0f8  jz      short loc_14000D103
0x14000d0fa  mov     rbx, [rax+88h]
0x14000d101  jmp     short loc_14000D176
0x14000d103  mov     ecx, 5
0x14000d108  call    sub_14000D540
0x14000d10d  nop
0x14000d10e  mov     rbx, [rdi+88h]
0x14000d115  mov     [rsp+28h+Block], rbx
0x14000d11a  cmp     rbx, cs:Block
0x14000d121  jz      short loc_14000D16C
0x14000d123  test    rbx, rbx
0x14000d126  jz      short loc_14000D14A
0x14000d128  or      eax, 0FFFFFFFFh
0x14000d12b  lock xadd [rbx], eax
0x14000d12f  cmp     eax, 1
0x14000d132  jnz     short loc_14000D14A
0x14000d134  lea     rax, unk_140020540
0x14000d13b  mov     rcx, [rsp+28h+Block]; Block
0x14000d140  cmp     rcx, rax
0x14000d143  jz      short loc_14000D14A
0x14000d145  call    _free_base
0x14000d14a  mov     rax, cs:Block
0x14000d151  mov     [rdi+88h], rax
0x14000d158  mov     rax, cs:Block
0x14000d15f  mov     [rsp+28h+Block], rax
0x14000d164  lock inc dword ptr [rax]
0x14000d167  mov     rbx, [rsp+28h+Block]
0x14000d16c  mov     ecx, 5
0x14000d171  call    sub_14000D594
0x14000d176  test    rbx, rbx
0x14000d179  jnz     short loc_14000D181
0x14000d17b  call    abort
0x14000d181  mov     rax, rbx
0x14000d184  mov     rbx, [rsp+28h+arg_8]
0x14000d189  add     rsp, 20h
0x14000d18d  pop     rdi
0x14000d18e  retn
0x140013a49  push    rbp
0x140013a4b  sub     rsp, 20h
0x140013a4f  mov     rbp, rdx
0x140013a52  mov     ecx, 5
0x140013a57  add     rsp, 20h
0x140013a5b  pop     rbp
0x140013a5c  jmp     sub_14000D594

// ===== _setmbcp_nolock @ 0x14000d190 =====

0x14000d190  mov     [rsp+arg_10], rbx
0x14000d195  mov     [rsp+arg_18], rbp
0x14000d19a  push    rsi
0x14000d19b  push    rdi
0x14000d19c  push    r12
0x14000d19e  push    r14
0x14000d1a0  push    r15
0x14000d1a2  sub     rsp, 40h
0x14000d1a6  mov     rax, cs:__security_cookie
0x14000d1ad  xor     rax, rsp
0x14000d1b0  mov     [rsp+68h+var_30], rax
0x14000d1b5  mov     rbx, rdx
0x14000d1b8  call    ?getSystemCP@@YAHH@Z
0x14000d1bd  xor     esi, esi
0x14000d1bf  mov     edi, eax
0x14000d1c1  test    eax, eax
0x14000d1c3  jnz     short loc_14000D1D2
0x14000d1c5  mov     rcx, rbx; struct __crt_multibyte_data *
0x14000d1c8  call    ?setSBCS@@YAXPEAU__crt_multibyte_data@@@Z
0x14000d1cd  jmp     loc_14000D40F
0x14000d1d2  lea     r12, unk_140020780
0x14000d1d9  mov     ebp, esi
0x14000d1db  mov     rax, r12
0x14000d1de  mov     r15d, 1
0x14000d1e4  cmp     [rax], edi
0x14000d1e6  jz      loc_14000D31C
0x14000d1ec  add     ebp, r15d
0x14000d1ef  add     rax, 30h ; '0'
0x14000d1f3  cmp     ebp, 5
0x14000d1f6  jb      short loc_14000D1E4
0x14000d1f8  lea     eax, [rdi-0FDE8h]
0x14000d1fe  cmp     eax, r15d
0x14000d201  jbe     loc_14000D314
0x14000d207  movzx   ecx, di; CodePage
0x14000d20a  call    cs:IsValidCodePage; KERNEL32
0x14000d210  test    eax, eax
0x14000d212  jz      loc_14000D314
0x14000d218  lea     rdx, [rsp+68h+CPInfo]; lpCPInfo
0x14000d21d  mov     ecx, edi; CodePage
0x14000d21f  call    cs:GetCPInfo; KERNEL32
0x14000d225  test    eax, eax
0x14000d227  jz      loc_14000D308
0x14000d22d  lea     rcx, [rbx+18h]
0x14000d231  xor     edx, edx
0x14000d233  mov     r8d, 101h
0x14000d239  call    sub_140005B30
0x14000d23e  mov     [rbx+4], edi
0x14000d241  mov     [rbx+220h], rsi
0x14000d248  cmp     [rsp+68h+CPInfo.MaxCharSize], r15d
0x14000d24d  jbe     loc_14000D2F1
0x14000d253  lea     rcx, [rsp+68h+CPInfo.LeadByte]
0x14000d258  cmp     [rsp+68h+CPInfo.LeadByte], sil
0x14000d25d  jz      short loc_14000D28F
0x14000d25f  cmp     [rcx+1], sil
0x14000d263  jz      short loc_14000D28F
0x14000d265  movzx   eax, byte ptr [rcx+1]
0x14000d269  movzx   edx, byte ptr [rcx]
0x14000d26c  cmp     edx, eax
0x14000d26e  ja      short loc_14000D286
0x14000d270  sub     eax, edx
0x14000d272  lea     edi, [rdx+1]
0x14000d275  lea     edx, [r15+rax]
0x14000d279  or      byte ptr [rdi+rbx+18h], 4
0x14000d27e  add     edi, r15d
0x14000d281  sub     rdx, r15
0x14000d284  jnz     short loc_14000D279
0x14000d286  add     rcx, 2
0x14000d28a  cmp     [rcx], sil
0x14000d28d  jnz     short loc_14000D25F
0x14000d28f  lea     rax, [rbx+1Ah]
0x14000d293  mov     ecx, 0FEh
0x14000d298  or      byte ptr [rax], 8
0x14000d29b  add     rax, r15
0x14000d29e  sub     rcx, r15
0x14000d2a1  jnz     short loc_14000D298
0x14000d2a3  mov     ecx, [rbx+4]
0x14000d2a6  sub     ecx, 3A4h
0x14000d2ac  jz      short loc_14000D2DD
0x14000d2ae  sub     ecx, 4
0x14000d2b1  jz      short loc_14000D2D4
0x14000d2b3  sub     ecx, 0Dh
0x14000d2b6  jz      short loc_14000D2CB
0x14000d2b8  cmp     ecx, r15d
0x14000d2bb  jz      short loc_14000D2C2
0x14000d2bd  mov     rax, rsi
0x14000d2c0  jmp     short loc_14000D2E4
0x14000d2c2  mov     rax, cs:off_140016310
0x14000d2c9  jmp     short loc_14000D2E4
0x14000d2cb  mov     rax, cs:off_140016308
0x14000d2d2  jmp     short loc_14000D2E4
0x14000d2d4  mov     rax, cs:off_140016300
0x14000d2db  jmp     short loc_14000D2E4
0x14000d2dd  mov     rax, cs:off_1400162F8
0x14000d2e4  mov     [rbx+220h], rax
0x14000d2eb  mov     [rbx+8], r15d
0x14000d2ef  jmp     short loc_14000D2F4
0x14000d2f1  mov     [rbx+8], esi
0x14000d2f4  lea     rdi, [rbx+0Ch]
0x14000d2f8  movzx   eax, si
0x14000d2fb  mov     ecx, 6
0x14000d300  rep stosw
0x14000d303  jmp     loc_14000D407
0x14000d308  cmp     cs:dword_140021C0C, esi
0x14000d30e  jnz     loc_14000D1C5
0x14000d314  or      eax, 0FFFFFFFFh
0x14000d317  jmp     loc_14000D411
0x14000d31c  lea     rcx, [rbx+18h]
0x14000d320  xor     edx, edx
0x14000d322  mov     r8d, 101h
0x14000d328  call    sub_140005B30
0x14000d32d  mov     eax, ebp
0x14000d32f  lea     r9, [r12+10h]
0x14000d334  lea     r14, unk_140020770
0x14000d33b  mov     ebp, 4
0x14000d340  lea     r11, [rax+rax*2]
0x14000d344  shl     r11, 4
0x14000d348  add     r9, r11
0x14000d34b  mov     rdx, r9
0x14000d34e  cmp     [r9], sil
0x14000d351  jz      short loc_14000D393
0x14000d353  cmp     [rdx+1], sil
0x14000d357  jz      short loc_14000D393
0x14000d359  movzx   r8d, byte ptr [rdx]
0x14000d35d  movzx   eax, byte ptr [rdx+1]
0x14000d361  cmp     r8d, eax
0x14000d364  ja      short loc_14000D38A
0x14000d366  lea     r10d, [r8+1]
0x14000d36a  cmp     r10d, 101h
0x14000d371  jnb     short loc_14000D38A
0x14000d373  mov     al, [r14]
0x14000d376  add     r8d, r15d
0x14000d379  or      [r10+rbx+18h], al
0x14000d37e  add     r10d, r15d
0x14000d381  movzx   eax, byte ptr [rdx+1]
0x14000d385  cmp     r8d, eax
0x14000d388  jbe     short loc_14000D36A
0x14000d38a  add     rdx, 2
0x14000d38e  cmp     [rdx], sil
0x14000d391  jnz     short loc_14000D353
0x14000d393  add     r9, 8
0x14000d397  add     r14, r15
0x14000d39a  sub     rbp, r15
0x14000d39d  jnz     short loc_14000D34B
0x14000d39f  mov     [rbx+4], edi
0x14000d3a2  mov     [rbx+8], r15d
0x14000d3a6  sub     edi, 3A4h
0x14000d3ac  jz      short loc_14000D3D8
0x14000d3ae  sub     edi, 4
0x14000d3b1  jz      short loc_14000D3CF
0x14000d3b3  sub     edi, 0Dh
0x14000d3b6  jz      short loc_14000D3C6
0x14000d3b8  cmp     edi, r15d
0x14000d3bb  jnz     short loc_14000D3DF
0x14000d3bd  mov     rsi, cs:off_140016310
0x14000d3c4  jmp     short loc_14000D3DF
0x14000d3c6  mov     rsi, cs:off_140016308
0x14000d3cd  jmp     short loc_14000D3DF
0x14000d3cf  mov     rsi, cs:off_140016300
0x14000d3d6  jmp     short loc_14000D3DF
0x14000d3d8  mov     rsi, cs:off_1400162F8
0x14000d3df  sub     r11, rbx
0x14000d3e2  mov     [rbx+220h], rsi
0x14000d3e9  lea     rcx, [rbx+0Ch]
0x14000d3ed  mov     edx, 6
0x14000d3f2  lea     rdi, [r11+r12]
0x14000d3f6  movzx   eax, word ptr [rdi+rcx-8]
0x14000d3fb  mov     [rcx], ax
0x14000d3fe  lea     rcx, [rcx+2]
0x14000d402  sub     rdx, r15
0x14000d405  jnz     short loc_14000D3F6
0x14000d407  mov     rcx, rbx; struct __crt_multibyte_data *
0x14000d40a  call    ?setSBUpLow@@YAXPEAU__crt_multibyte_data@@@Z
0x14000d40f  xor     eax, eax
0x14000d411  mov     rcx, [rsp+68h+var_30]
0x14000d416  xor     rcx, rsp; StackCookie
0x14000d419  call    __security_check_cookie
0x14000d41e  lea     r11, [rsp+68h+var_28]
0x14000d423  mov     rbx, [r11+40h]
0x14000d427  mov     rbp, [r11+48h]
0x14000d42b  mov     rsp, r11
0x14000d42e  pop     r15
0x14000d430  pop     r14
0x14000d432  pop     r12
0x14000d434  pop     rdi
0x14000d435  pop     rsi
0x14000d436  retn

// ===== __acrt_initialize_command_line @ 0x14000d438 =====

0x14000d438  sub     rsp, 28h
0x14000d43c  call    cs:GetCommandLineA; KERNEL32
0x14000d442  mov     cs:qword_140021C30, rax
0x14000d449  call    cs:GetCommandLineW; KERNEL32
0x14000d44f  mov     cs:qword_140021C38, rax
0x14000d456  mov     al, 1
0x14000d458  add     rsp, 28h
0x14000d45c  retn

// ===== __dcrt_get_wide_environment_from_os @ 0x14000d460 =====

0x14000d460  mov     [rsp+arg_0], rbx
0x14000d465  mov     [rsp+arg_8], rbp
0x14000d46a  mov     [rsp+arg_10], rsi
0x14000d46f  push    rdi
0x14000d470  sub     rsp, 20h
0x14000d474  call    cs:GetEnvironmentStringsW; KERNEL32
0x14000d47a  xor     esi, esi
0x14000d47c  mov     rbx, rax
0x14000d47f  test    rax, rax
0x14000d482  jz      short loc_14000D4DF
0x14000d484  jmp     short loc_14000D49B
0x14000d486  or      rcx, 0FFFFFFFFFFFFFFFFh
0x14000d48a  inc     rcx
0x14000d48d  cmp     [rax+rcx*2], si
0x14000d491  jnz     short loc_14000D48A
0x14000d493  lea     rax, [rax+rcx*2]
0x14000d497  add     rax, 2
0x14000d49b  cmp     [rax], si
0x14000d49e  jnz     short loc_14000D486
0x14000d4a0  sub     rax, rbx
0x14000d4a3  add     rax, 2
0x14000d4a7  sar     rax, 1
0x14000d4aa  lea     rbp, [rax+rax]
0x14000d4ae  mov     rcx, rbp; Size
0x14000d4b1  call    _malloc_base
0x14000d4b6  mov     rdi, rax
0x14000d4b9  test    rax, rax
0x14000d4bc  jz      short loc_14000D4CF
0x14000d4be  mov     r8, rbp
0x14000d4c1  mov     rdx, rbx
0x14000d4c4  mov     rcx, rax
0x14000d4c7  call    sub_1400067F0
0x14000d4cc  mov     rsi, rdi
0x14000d4cf  xor     ecx, ecx; Block
0x14000d4d1  call    _free_base
0x14000d4d6  mov     rcx, rbx; penv
0x14000d4d9  call    cs:FreeEnvironmentStringsW; KERNEL32
0x14000d4df  mov     rbx, [rsp+28h+arg_0]
0x14000d4e4  mov     rax, rsi
0x14000d4e7  mov     rsi, [rsp+28h+arg_10]
0x14000d4ec  mov     rbp, [rsp+28h+arg_8]
0x14000d4f1  add     rsp, 20h
0x14000d4f5  pop     rdi
0x14000d4f6  retn

// ===== __vcrt_initialize_locks_0 @ 0x14000d4f8 =====

0x14000d4f8  push    rbx
0x14000d4fa  sub     rsp, 20h
0x14000d4fe  xor     ebx, ebx
0x14000d500  lea     rdx, unk_140021C50
0x14000d507  xor     r8d, r8d
0x14000d50a  lea     rcx, [rbx+rbx*4]
0x14000d50e  lea     rcx, [rdx+rcx*8]; lpCriticalSection
0x14000d512  mov     edx, 0FA0h; dwSpinCount
0x14000d517  call    __acrt_InitializeCriticalSectionEx
0x14000d51c  test    eax, eax
0x14000d51e  jz      short loc_14000D531
0x14000d520  inc     cs:dword_140021E58
0x14000d526  inc     ebx
0x14000d528  cmp     ebx, 0Dh
0x14000d52b  jb      short loc_14000D500
0x14000d52d  mov     al, 1
0x14000d52f  jmp     short loc_14000D53A
0x14000d531  xor     ecx, ecx
0x14000d533  call    __vcrt_uninitialize_locks_0
0x14000d538  xor     al, al
0x14000d53a  add     rsp, 20h
0x14000d53e  pop     rbx
0x14000d53f  retn

// ===== sub_14000D540 @ 0x14000d540 =====

0x14000d540  movsxd  rax, ecx
0x14000d543  lea     rcx, [rax+rax*4]
0x14000d547  lea     rax, unk_140021C50
0x14000d54e  lea     rcx, [rax+rcx*8]
0x14000d552  jmp     cs:EnterCriticalSection; KERNEL32

// ===== __vcrt_uninitialize_locks_0 @ 0x14000d55c =====

0x14000d55c  push    rbx
0x14000d55e  sub     rsp, 20h
0x14000d562  mov     ebx, cs:dword_140021E58
0x14000d568  jmp     short loc_14000D587
0x14000d56a  lea     rax, unk_140021C50
0x14000d571  dec     ebx
0x14000d573  lea     rcx, [rbx+rbx*4]
0x14000d577  lea     rcx, [rax+rcx*8]; lpCriticalSection
0x14000d57b  call    cs:DeleteCriticalSection; KERNEL32
0x14000d581  dec     cs:dword_140021E58
0x14000d587  test    ebx, ebx
0x14000d589  jnz     short loc_14000D56A
0x14000d58b  mov     al, 1
0x14000d58d  add     rsp, 20h
0x14000d591  pop     rbx
0x14000d592  retn

// ===== sub_14000D594 @ 0x14000d594 =====

0x14000d594  movsxd  rax, ecx
0x14000d597  lea     rcx, [rax+rax*4]
0x14000d59b  lea     rax, unk_140021C50
0x14000d5a2  lea     rcx, [rax+rcx*8]
0x14000d5a6  jmp     cs:LeaveCriticalSection; KERNEL32

// ===== ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z @ 0x14000d5b0 =====

0x14000d5b0  mov     [rsp+arg_0], rbx
0x14000d5b5  mov     [rsp+arg_8], rbp
0x14000d5ba  mov     [rsp+arg_10], rsi
0x14000d5bf  push    rdi
0x14000d5c0  push    r12
0x14000d5c2  push    r13
0x14000d5c4  push    r14
0x14000d5c6  push    r15
0x14000d5c8  sub     rsp, 20h
0x14000d5cc  mov     r14d, ecx
0x14000d5cf  lea     r15, cs:140000000h
0x14000d5d6  mov     r12, r9
0x14000d5d9  mov     rbp, r8
0x14000d5dc  mov     r13, rdx
0x14000d5df  mov     rcx, rva qword_140021F00[r15+r14*8]
0x14000d5e7  mov     r10, cs:__security_cookie
0x14000d5ee  or      rdi, 0FFFFFFFFFFFFFFFFh
0x14000d5f2  mov     eax, r10d
0x14000d5f5  mov     rdx, r10
0x14000d5f8  xor     rdx, rcx
0x14000d5fb  and     eax, 3Fh
0x14000d5fe  mov     cl, al
0x14000d600  ror     rdx, cl
0x14000d603  cmp     rdx, rdi
0x14000d606  jz      loc_14000D731
0x14000d60c  test    rdx, rdx
0x14000d60f  jz      short loc_14000D619
0x14000d611  mov     rax, rdx
0x14000d614  jmp     loc_14000D733
0x14000d619  cmp     r8, r9
0x14000d61c  jz      loc_14000D6C5
0x14000d622  mov     esi, [rbp+0]
0x14000d625  mov     rbx, rva qword_140021E60[r15+rsi*8]
0x14000d62d  test    rbx, rbx
0x14000d630  jz      short loc_14000D639
0x14000d632  cmp     rbx, rdi
0x14000d635  jz      short loc_14000D6B1
0x14000d637  jmp     short loc_14000D6AC
0x14000d639  mov     r15, ds:rva off_140016360[r15+rsi*8]
0x14000d641  xor     edx, edx; hFile
0x14000d643  mov     rcx, r15; lpLibFileName
0x14000d646  mov     r8d, 800h; dwFlags
0x14000d64c  call    cs:LoadLibraryExW; KERNEL32
0x14000d652  mov     rbx, rax
0x14000d655  test    rax, rax
0x14000d658  jnz     short loc_14000D67A
0x14000d65a  call    cs:GetLastError; KERNEL32
0x14000d660  cmp     eax, 57h ; 'W'
0x14000d663  jnz     short loc_14000D678
0x14000d665  xor     r8d, r8d; dwFlags
0x14000d668  xor     edx, edx; hFile
0x14000d66a  mov     rcx, r15; lpLibFileName
0x14000d66d  call    cs:LoadLibraryExW; KERNEL32
0x14000d673  mov     rbx, rax
0x14000d676  jmp     short loc_14000D67A
0x14000d678  xor     ebx, ebx
0x14000d67a  lea     r15, cs:140000000h
0x14000d681  test    rbx, rbx
0x14000d684  jnz     short loc_14000D693
0x14000d686  mov     rax, rdi
0x14000d689  xchg    rax, rva qword_140021E60[r15+rsi*8]
0x14000d691  jmp     short loc_14000D6B1
0x14000d693  mov     rax, rbx
0x14000d696  xchg    rax, rva qword_140021E60[r15+rsi*8]
0x14000d69e  test    rax, rax
0x14000d6a1  jz      short loc_14000D6AC
0x14000d6a3  mov     rcx, rbx; hLibModule
0x14000d6a6  call    cs:FreeLibrary; KERNEL32
0x14000d6ac  test    rbx, rbx
0x14000d6af  jnz     short loc_14000D706
0x14000d6b1  add     rbp, 4
0x14000d6b5  cmp     rbp, r12
0x14000d6b8  jnz     loc_14000D622
0x14000d6be  mov     r10, cs:__security_cookie
0x14000d6c5  xor     ebx, ebx
0x14000d6c7  test    rbx, rbx
0x14000d6ca  jz      short loc_14000D716
0x14000d6cc  mov     rdx, r13; lpProcName
0x14000d6cf  mov     rcx, rbx; hModule
0x14000d6d2  call    cs:GetProcAddress; KERNEL32
0x14000d6d8  test    rax, rax
0x14000d6db  jz      short loc_14000D70F
0x14000d6dd  mov     r8, cs:__security_cookie
0x14000d6e4  mov     edx, 40h ; '@'
0x14000d6e9  mov     ecx, r8d
0x14000d6ec  and     ecx, 3Fh
0x14000d6ef  sub     edx, ecx
0x14000d6f1  mov     cl, dl
0x14000d6f3  mov     rdx, rax
0x14000d6f6  ror     rdx, cl
0x14000d6f9  xor     rdx, r8
0x14000d6fc  xchg    rdx, rva qword_140021F00[r15+r14*8]
0x14000d704  jmp     short loc_14000D733
0x14000d706  mov     r10, cs:__security_cookie
0x14000d70d  jmp     short loc_14000D6C7
0x14000d70f  mov     r10, cs:__security_cookie
0x14000d716  mov     eax, r10d
0x14000d719  mov     ecx, 40h ; '@'
0x14000d71e  and     eax, 3Fh
0x14000d721  sub     ecx, eax
0x14000d723  ror     rdi, cl
0x14000d726  xor     rdi, r10
0x14000d729  xchg    rdi, rva qword_140021F00[r15+r14*8]
0x14000d731  xor     eax, eax
0x14000d733  mov     rbx, [rsp+48h+arg_0]
0x14000d738  mov     rbp, [rsp+48h+arg_8]
0x14000d73d  mov     rsi, [rsp+48h+arg_10]
0x14000d742  add     rsp, 20h
0x14000d746  pop     r15
0x14000d748  pop     r14
0x14000d74a  pop     r13
0x14000d74c  pop     r12
0x14000d74e  pop     rdi
0x14000d74f  retn

// ===== __acrt_FlsAlloc @ 0x14000d750 =====

0x14000d750  mov     [rsp+arg_0], rbx
0x14000d755  push    rdi
0x14000d756  sub     rsp, 20h
0x14000d75a  mov     rdi, rcx
0x14000d75d  lea     r9, aFlsalloc_0
0x14000d764  mov     ecx, 3
0x14000d769  lea     r8, unk_140016940
0x14000d770  lea     rdx, aFlsalloc_0
0x14000d777  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x14000d77c  mov     rbx, rax
0x14000d77f  test    rax, rax
0x14000d782  jz      short loc_14000D794
0x14000d784  mov     rcx, rax
0x14000d787  call    cs:__guard_check_icall_fptr
0x14000d78d  mov     rcx, rdi
0x14000d790  call    rbx
0x14000d792  jmp     short loc_14000D79A
0x14000d794  call    cs:TlsAlloc; KERNEL32
0x14000d79a  mov     rbx, [rsp+28h+arg_0]
0x14000d79f  add     rsp, 20h
0x14000d7a3  pop     rdi
0x14000d7a4  retn

// ===== __acrt_FlsFree @ 0x14000d7a8 =====

0x14000d7a8  mov     [rsp+arg_0], rbx
0x14000d7ad  push    rdi
0x14000d7ae  sub     rsp, 20h
0x14000d7b2  mov     ebx, ecx
0x14000d7b4  lea     r9, aFlsfree_0
0x14000d7bb  mov     ecx, 4
0x14000d7c0  lea     r8, unk_140016958
0x14000d7c7  lea     rdx, aFlsfree_0
0x14000d7ce  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x14000d7d3  mov     rdi, rax
0x14000d7d6  test    rax, rax
0x14000d7d9  jz      short loc_14000D7EA
0x14000d7db  mov     rcx, rax
0x14000d7de  call    cs:__guard_check_icall_fptr
0x14000d7e4  mov     ecx, ebx
0x14000d7e6  call    rdi
0x14000d7e8  jmp     short loc_14000D7F2
0x14000d7ea  mov     ecx, ebx; dwTlsIndex
0x14000d7ec  call    cs:TlsFree; KERNEL32
0x14000d7f2  mov     rbx, [rsp+28h+arg_0]
0x14000d7f7  add     rsp, 20h
0x14000d7fb  pop     rdi
0x14000d7fc  retn

// ===== __vcrt_FlsFree_0 @ 0x14000d800 =====

0x14000d800  mov     [rsp+arg_0], rbx
0x14000d805  push    rdi
0x14000d806  sub     rsp, 20h
0x14000d80a  mov     ebx, ecx
0x14000d80c  lea     r9, aFlsgetvalue
0x14000d813  mov     ecx, 5
0x14000d818  lea     r8, unk_140016968
0x14000d81f  lea     rdx, aFlsgetvalue
0x14000d826  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x14000d82b  mov     rdi, rax
0x14000d82e  test    rax, rax
0x14000d831  jz      short loc_14000D842
0x14000d833  mov     rcx, rax
0x14000d836  call    cs:__guard_check_icall_fptr
0x14000d83c  mov     ecx, ebx
0x14000d83e  call    rdi
0x14000d840  jmp     short loc_14000D84A
0x14000d842  mov     ecx, ebx; dwTlsIndex
0x14000d844  call    cs:TlsGetValue; KERNEL32
0x14000d84a  mov     rbx, [rsp+28h+arg_0]
0x14000d84f  add     rsp, 20h
0x14000d853  pop     rdi
0x14000d854  retn

// ===== __acrt_FlsSetValue @ 0x14000d858 =====

0x14000d858  mov     [rsp+arg_0], rbx
0x14000d85d  mov     [rsp+arg_8], rsi
0x14000d862  push    rdi
0x14000d863  sub     rsp, 20h
0x14000d867  mov     rbx, rdx
0x14000d86a  lea     r9, aFlssetvalue_0
0x14000d871  mov     edi, ecx
0x14000d873  lea     rdx, aFlssetvalue_0
0x14000d87a  mov     ecx, 6
0x14000d87f  lea     r8, unk_140016980
0x14000d886  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x14000d88b  mov     rsi, rax
0x14000d88e  test    rax, rax
0x14000d891  jz      short loc_14000D8A5
0x14000d893  mov     rcx, rax
0x14000d896  call    cs:__guard_check_icall_fptr
0x14000d89c  mov     rdx, rbx
0x14000d89f  mov     ecx, edi
0x14000d8a1  call    rsi
0x14000d8a3  jmp     short loc_14000D8B0
0x14000d8a5  mov     rdx, rbx; lpTlsValue
0x14000d8a8  mov     ecx, edi; dwTlsIndex
0x14000d8aa  call    cs:TlsSetValue; KERNEL32
0x14000d8b0  mov     rbx, [rsp+28h+arg_0]
0x14000d8b5  mov     rsi, [rsp+28h+arg_8]
0x14000d8ba  add     rsp, 20h
0x14000d8be  pop     rdi
0x14000d8bf  retn

// ===== __acrt_InitializeCriticalSectionEx @ 0x14000d8c0 =====

0x14000d8c0  mov     [rsp+arg_0], rbx
0x14000d8c5  mov     [rsp+arg_8], rbp
0x14000d8ca  mov     [rsp+arg_10], rsi
0x14000d8cf  push    rdi
0x14000d8d0  sub     rsp, 20h
0x14000d8d4  mov     ebp, r8d
0x14000d8d7  lea     r9, aInitializecrit_0
0x14000d8de  mov     ebx, edx
0x14000d8e0  lea     r8, asc_1400169B8
0x14000d8e7  mov     rdi, rcx
0x14000d8ea  lea     rdx, aInitializecrit_0
0x14000d8f1  mov     ecx, 14h
0x14000d8f6  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x14000d8fb  mov     rsi, rax
0x14000d8fe  test    rax, rax
0x14000d901  jz      short loc_14000D918
0x14000d903  mov     rcx, rax
0x14000d906  call    cs:__guard_check_icall_fptr
0x14000d90c  mov     r8d, ebp
0x14000d90f  mov     edx, ebx
0x14000d911  mov     rcx, rdi
0x14000d914  call    rsi
0x14000d916  jmp     short loc_14000D923
0x14000d918  mov     edx, ebx; dwSpinCount
0x14000d91a  mov     rcx, rdi; lpCriticalSection
0x14000d91d  call    cs:InitializeCriticalSectionAndSpinCount; KERNEL32
0x14000d923  mov     rbx, [rsp+28h+arg_0]
0x14000d928  mov     rbp, [rsp+28h+arg_8]
0x14000d92d  mov     rsi, [rsp+28h+arg_10]
0x14000d932  add     rsp, 20h
0x14000d936  pop     rdi
0x14000d937  retn

// ===== __acrt_LCMapStringEx @ 0x14000d938 =====

0x14000d938  mov     rax, rsp
0x14000d93b  mov     [rax+8], rbx
0x14000d93f  mov     [rax+10h], rbp
0x14000d943  mov     [rax+18h], rsi
0x14000d947  mov     [rax+20h], rdi
0x14000d94b  push    r14
0x14000d94d  sub     rsp, 50h
0x14000d951  mov     edi, r9d
0x14000d954  mov     rsi, r8
0x14000d957  mov     ebp, edx
0x14000d959  lea     r9, aLcmapstringex
0x14000d960  mov     r14, rcx
0x14000d963  lea     r8, unk_1400169E0
0x14000d96a  lea     rdx, aLcmapstringex
0x14000d971  mov     ecx, 16h
0x14000d976  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x14000d97b  mov     rbx, rax
0x14000d97e  test    rax, rax
0x14000d981  jz      short loc_14000D9DA
0x14000d983  mov     rcx, rax
0x14000d986  call    cs:__guard_check_icall_fptr
0x14000d98c  mov     rcx, [rsp+58h+arg_40]
0x14000d994  mov     r9d, edi
0x14000d997  mov     rax, [rsp+58h+arg_20]
0x14000d99f  mov     r8, rsi
0x14000d9a2  mov     [rsp+58h+var_18], rcx
0x14000d9a7  mov     edx, ebp
0x14000d9a9  mov     rcx, [rsp+58h+arg_38]
0x14000d9b1  mov     [rsp+58h+var_20], rcx
0x14000d9b6  mov     rcx, [rsp+58h+arg_30]
0x14000d9be  mov     [rsp+58h+var_28], rcx
0x14000d9c3  mov     ecx, [rsp+58h+arg_28]
0x14000d9ca  mov     [rsp+58h+cchDest], ecx
0x14000d9ce  mov     rcx, r14
0x14000d9d1  mov     [rsp+58h+lpDestStr], rax
0x14000d9d6  call    rbx
0x14000d9d8  jmp     short loc_14000DA0C
0x14000d9da  xor     edx, edx
0x14000d9dc  mov     rcx, r14
0x14000d9df  call    __acrt_LocaleNameToLCID
0x14000d9e4  mov     ecx, eax; Locale
0x14000d9e6  mov     r9d, edi; cchSrc
0x14000d9e9  mov     eax, [rsp+58h+arg_28]
0x14000d9f0  mov     r8, rsi; lpSrcStr
0x14000d9f3  mov     [rsp+58h+cchDest], eax; cchDest
0x14000d9f7  mov     edx, ebp; dwMapFlags
0x14000d9f9  mov     rax, [rsp+58h+arg_20]
0x14000da01  mov     [rsp+58h+lpDestStr], rax; lpDestStr
0x14000da06  call    cs:LCMapStringW; KERNEL32
0x14000da0c  mov     rbx, [rsp+58h+arg_0]
0x14000da11  mov     rbp, [rsp+58h+arg_8]
0x14000da16  mov     rsi, [rsp+58h+arg_10]
0x14000da1b  mov     rdi, [rsp+58h+arg_18]
0x14000da20  add     rsp, 50h
0x14000da24  pop     r14
0x14000da26  retn

// ===== __acrt_LocaleNameToLCID @ 0x14000da28 =====

0x14000da28  mov     [rsp+arg_0], rbx
0x14000da2d  mov     [rsp+arg_8], rsi
0x14000da32  push    rdi
0x14000da33  sub     rsp, 20h
0x14000da37  mov     esi, edx
0x14000da39  lea     r9, aLocalenametolc
0x14000da40  mov     rbx, rcx
0x14000da43  lea     rdx, aLocalenametolc
0x14000da4a  mov     ecx, 18h
0x14000da4f  lea     r8, unk_1400169F8
0x14000da56  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x14000da5b  mov     rdi, rax
0x14000da5e  test    rax, rax
0x14000da61  jz      short loc_14000DA75
0x14000da63  mov     rcx, rax
0x14000da66  call    cs:__guard_check_icall_fptr
0x14000da6c  mov     edx, esi
0x14000da6e  mov     rcx, rbx
0x14000da71  call    rdi
0x14000da73  jmp     short loc_14000DA7D
0x14000da75  mov     rcx, rbx
0x14000da78  call    __crtDownlevelLocaleNameToLCID
0x14000da7d  mov     rbx, [rsp+28h+arg_0]
0x14000da82  mov     rsi, [rsp+28h+arg_8]
0x14000da87  add     rsp, 20h
0x14000da8b  pop     rdi
0x14000da8c  retn

// ===== __acrt_initialize_winapi_thunks @ 0x14000da90 =====

0x14000da90  mov     [rsp+arg_0], rdi
0x14000da95  mov     rdx, cs:__security_cookie
0x14000da9c  lea     rdi, qword_140021F00
0x14000daa3  mov     eax, edx
0x14000daa5  mov     ecx, 40h ; '@'
0x14000daaa  and     eax, 3Fh
0x14000daad  sub     ecx, eax
0x14000daaf  xor     eax, eax
0x14000dab1  ror     rax, cl
0x14000dab4  mov     ecx, 20h ; ' '
0x14000dab9  xor     rax, rdx
0x14000dabc  rep stosq
0x14000dabf  mov     rdi, [rsp+arg_0]
0x14000dac4  mov     al, 1
0x14000dac6  retn

// ===== __acrt_is_packaged_app @ 0x14000dac8 =====

0x14000dac8  mov     [rsp+arg_8], rbx
0x14000dacd  push    rdi
0x14000dace  sub     rsp, 20h
0x14000dad2  mov     eax, cs:dword_140022000
0x14000dad8  xor     ebx, ebx
0x14000dada  test    eax, eax
0x14000dadc  jz      short loc_14000DAE6
0x14000dade  cmp     eax, 1
0x14000dae1  setz    al
0x14000dae4  jmp     short loc_14000DB42
0x14000dae6  lea     r9, aGetcurrentpack
0x14000daed  mov     ecx, 8
0x14000daf2  lea     r8, unk_140016998
0x14000daf9  lea     rdx, aGetcurrentpack
0x14000db00  call    ?try_get_function@@YAPEAXW4function_id@?A0x1dd686d3@@QEBDQEBW4module_id@2@2@Z
0x14000db05  mov     rdi, rax
0x14000db08  test    rax, rax
0x14000db0b  jz      short loc_14000DB35
0x14000db0d  mov     rcx, rax
0x14000db10  mov     [rsp+28h+arg_0], ebx
0x14000db14  call    cs:__guard_check_icall_fptr
0x14000db1a  xor     edx, edx
0x14000db1c  lea     rcx, [rsp+28h+arg_0]
0x14000db21  call    rdi
0x14000db23  cmp     eax, 7Ah ; 'z'
0x14000db26  jnz     short loc_14000DB35
0x14000db28  lea     ecx, [rax-79h]
0x14000db2b  mov     al, 1
0x14000db2d  xchg    ecx, cs:dword_140022000
0x14000db33  jmp     short loc_14000DB42
0x14000db35  mov     eax, 2
0x14000db3a  xchg    eax, cs:dword_140022000
0x14000db40  xor     al, al
0x14000db42  mov     rbx, [rsp+28h+arg_8]
0x14000db47  add     rsp, 20h
0x14000db4b  pop     rdi
0x14000db4c  retn

// ===== __acrt_uninitialize_winapi_thunks @ 0x14000db50 =====

0x14000db50  push    rbx
0x14000db52  sub     rsp, 20h
0x14000db56  test    cl, cl
0x14000db58  jnz     short loc_14000DB89
0x14000db5a  lea     rbx, qword_140021E60
0x14000db61  mov     rcx, [rbx]; hLibModule
0x14000db64  test    rcx, rcx
0x14000db67  jz      short loc_14000DB79
0x14000db69  cmp     rcx, 0FFFFFFFFFFFFFFFFh
0x14000db6d  jz      short loc_14000DB75
0x14000db6f  call    cs:FreeLibrary; KERNEL32
0x14000db75  and     qword ptr [rbx], 0
0x14000db79  add     rbx, 8
0x14000db7d  lea     rax, qword_140021F00
0x14000db84  cmp     rbx, rax
0x14000db87  jnz     short loc_14000DB61
0x14000db89  mov     al, 1
0x14000db8b  add     rsp, 20h
0x14000db8f  pop     rbx
0x14000db90  retn

// ===== __acrt_lowio_create_handle_array @ 0x14000db94 =====

0x14000db94  mov     [rsp+arg_0], rbx
0x14000db99  mov     [rsp+arg_8], rbp
0x14000db9e  mov     [rsp+arg_10], rsi
0x14000dba3  push    rdi
0x14000dba4  sub     rsp, 20h
0x14000dba8  mov     edx, 40h ; '@'; Size
0x14000dbad  mov     ecx, edx; Count
0x14000dbaf  call    _calloc_base
0x14000dbb4  xor     esi, esi
0x14000dbb6  mov     rbx, rax
0x14000dbb9  test    rax, rax
0x14000dbbc  jz      short loc_14000DC0A
0x14000dbbe  lea     rbp, [rax+1000h]
0x14000dbc5  cmp     rax, rbp
0x14000dbc8  jz      short loc_14000DC07
0x14000dbca  lea     rdi, [rax+30h]
0x14000dbce  lea     rcx, [rdi-30h]; lpCriticalSection
0x14000dbd2  xor     r8d, r8d
0x14000dbd5  mov     edx, 0FA0h; dwSpinCount
0x14000dbda  call    __acrt_InitializeCriticalSectionEx
0x14000dbdf  or      qword ptr [rdi-8], 0FFFFFFFFFFFFFFFFh
0x14000dbe4  mov     [rdi], rsi
0x14000dbe7  mov     dword ptr [rdi+8], 0A0A0000h
0x14000dbee  mov     byte ptr [rdi+0Ch], 0Ah
0x14000dbf2  and     byte ptr [rdi+0Dh], 0F8h
0x14000dbf6  mov     [rdi+0Eh], sil
0x14000dbfa  lea     rdi, [rdi+40h]
0x14000dbfe  lea     rax, [rdi-30h]
0x14000dc02  cmp     rax, rbp
0x14000dc05  jnz     short loc_14000DBCE
0x14000dc07  mov     rsi, rbx
0x14000dc0a  xor     ecx, ecx; Block
0x14000dc0c  call    _free_base
0x14000dc11  mov     rbx, [rsp+28h+arg_0]
0x14000dc16  mov     rax, rsi
0x14000dc19  mov     rsi, [rsp+28h+arg_10]
0x14000dc1e  mov     rbp, [rsp+28h+arg_8]
0x14000dc23  add     rsp, 20h
0x14000dc27  pop     rdi
0x14000dc28  retn

// ===== __acrt_lowio_destroy_handle_array @ 0x14000dc2c =====

0x14000dc2c  test    rcx, rcx
0x14000dc2f  jz      short locret_14000DC7B
0x14000dc31  mov     [rsp+arg_0], rbx
0x14000dc36  mov     [rsp+arg_8], rsi
0x14000dc3b  push    rdi
0x14000dc3c  sub     rsp, 20h
0x14000dc40  lea     rsi, [rcx+1000h]
0x14000dc47  mov     rbx, rcx
0x14000dc4a  mov     rdi, rcx
0x14000dc4d  cmp     rcx, rsi
0x14000dc50  jz      short loc_14000DC64
0x14000dc52  mov     rcx, rdi; lpCriticalSection
0x14000dc55  call    cs:DeleteCriticalSection; KERNEL32
0x14000dc5b  add     rdi, 40h ; '@'
0x14000dc5f  cmp     rdi, rsi
0x14000dc62  jnz     short loc_14000DC52
0x14000dc64  mov     rcx, rbx; Block
0x14000dc67  call    _free_base
0x14000dc6c  mov     rbx, [rsp+28h+arg_0]
0x14000dc71  mov     rsi, [rsp+28h+arg_8]
0x14000dc76  add     rsp, 20h
0x14000dc7a  pop     rdi
0x14000dc7b  retn

// ===== __acrt_lowio_ensure_fh_exists @ 0x14000dc7c =====

0x14000dc7c  mov     [rsp+arg_0], rbx
0x14000dc81  mov     [rsp+arg_8], rsi
0x14000dc86  mov     [rsp+arg_10], rdi
0x14000dc8b  push    r15
0x14000dc8d  sub     rsp, 30h
0x14000dc91  mov     esi, ecx
0x14000dc93  xor     ebx, ebx
0x14000dc95  mov     eax, ebx
0x14000dc97  cmp     ecx, 2000h
0x14000dc9d  setb    al
0x14000dca0  test    eax, eax
0x14000dca2  jnz     short loc_14000DCB9
0x14000dca4  call    _errno
0x14000dca9  mov     ebx, 9
0x14000dcae  mov     [rax], ebx
0x14000dcb0  call    _invalid_parameter_noinfo
0x14000dcb5  mov     eax, ebx
0x14000dcb7  jmp     short loc_14000DD1D
0x14000dcb9  mov     ecx, 7
0x14000dcbe  call    sub_14000D540
0x14000dcc3  nop
0x14000dcc4  mov     rdi, rbx
0x14000dcc7  mov     [rsp+38h+var_18], rbx
0x14000dccc  mov     eax, cs:dword_140021BF0
0x14000dcd2  cmp     esi, eax
0x14000dcd4  jl      short loc_14000DD11
0x14000dcd6  lea     r15, qword_1400217F0
0x14000dcdd  cmp     [r15+rdi*8], rbx
0x14000dce1  jz      short loc_14000DCE5
0x14000dce3  jmp     short loc_14000DD07
0x14000dce5  call    __acrt_lowio_create_handle_array
0x14000dcea  mov     [r15+rdi*8], rax
0x14000dcee  test    rax, rax
0x14000dcf1  jnz     short loc_14000DCF8
0x14000dcf3  lea     ebx, [rax+0Ch]
0x14000dcf6  jmp     short loc_14000DD11
0x14000dcf8  mov     eax, cs:dword_140021BF0
0x14000dcfe  add     eax, 40h ; '@'
0x14000dd01  mov     cs:dword_140021BF0, eax
0x14000dd07  inc     rdi
0x14000dd0a  mov     [rsp+38h+var_18], rdi
0x14000dd0f  jmp     short loc_14000DCD2
0x14000dd11  mov     ecx, 7
0x14000dd16  call    sub_14000D594
0x14000dd1b  jmp     short loc_14000DCB5
0x14000dd1d  mov     rbx, [rsp+38h+arg_0]
0x14000dd22  mov     rsi, [rsp+38h+arg_8]
0x14000dd27  mov     rdi, [rsp+38h+arg_10]
0x14000dd2c  add     rsp, 30h
0x14000dd30  pop     r15
0x14000dd32  retn
0x140013a30  push    rbp; Microsoft VisualC 64bit universal runtime
0x140013a32  sub     rsp, 20h
0x140013a36  mov     rbp, rdx
0x140013a39  mov     ecx, 7
0x140013a3e  add     rsp, 20h
0x140013a42  pop     rbp
0x140013a43  jmp     sub_14000D594

// ===== sub_14000DD34 @ 0x14000dd34 =====

0x14000dd34  movsxd  rcx, ecx
0x14000dd37  lea     rdx, qword_1400217F0
0x14000dd3e  mov     rax, rcx
0x14000dd41  and     ecx, 3Fh
0x14000dd44  sar     rax, 6
0x14000dd48  shl     rcx, 6
0x14000dd4c  add     rcx, [rdx+rax*8]
0x14000dd50  jmp     cs:EnterCriticalSection; KERNEL32

// ===== sub_14000DD58 @ 0x14000dd58 =====

0x14000dd58  movsxd  rcx, ecx
0x14000dd5b  lea     rdx, qword_1400217F0
0x14000dd62  mov     rax, rcx
0x14000dd65  and     ecx, 3Fh
0x14000dd68  sar     rax, 6
0x14000dd6c  shl     rcx, 6
0x14000dd70  add     rcx, [rdx+rax*8]
0x14000dd74  jmp     cs:LeaveCriticalSection; KERNEL32

// ===== _free_osfhnd @ 0x14000dd7c =====

0x14000dd7c  mov     [rsp+arg_0], rbx
0x14000dd81  mov     [rsp+arg_8], rsi
0x14000dd86  mov     [rsp+arg_10], rdi
0x14000dd8b  push    r14
0x14000dd8d  sub     rsp, 20h
0x14000dd91  movsxd  rbx, ecx
0x14000dd94  test    ecx, ecx
0x14000dd96  js      short loc_14000DE0A
0x14000dd98  cmp     ebx, cs:dword_140021BF0
0x14000dd9e  jnb     short loc_14000DE0A
0x14000dda0  mov     rdi, rbx
0x14000dda3  lea     r14, qword_1400217F0
0x14000ddaa  and     edi, 3Fh
0x14000ddad  mov     rsi, rbx
0x14000ddb0  sar     rsi, 6
0x14000ddb4  shl     rdi, 6
0x14000ddb8  mov     rax, [r14+rsi*8]
0x14000ddbc  test    byte ptr [rax+rdi+38h], 1
0x14000ddc1  jz      short loc_14000DE0A
0x14000ddc3  cmp     qword ptr [rax+rdi+28h], 0FFFFFFFFFFFFFFFFh
0x14000ddc9  jz      short loc_14000DE0A
0x14000ddcb  call    sub_140008700
0x14000ddd0  cmp     eax, 1
0x14000ddd3  jnz     short loc_14000DDFC
0x14000ddd5  test    ebx, ebx
0x14000ddd7  jz      short loc_14000DDEF
0x14000ddd9  sub     ebx, eax
0x14000dddb  jz      short loc_14000DDE8
0x14000dddd  cmp     ebx, eax
0x14000dddf  jnz     short loc_14000DDFC
0x14000dde1  mov     ecx, 0FFFFFFF4h
0x14000dde6  jmp     short loc_14000DDF4
0x14000dde8  mov     ecx, 0FFFFFFF5h
0x14000dded  jmp     short loc_14000DDF4
0x14000ddef  mov     ecx, 0FFFFFFF6h; nStdHandle
0x14000ddf4  xor     edx, edx; hHandle
0x14000ddf6  call    cs:SetStdHandle; KERNEL32
0x14000ddfc  mov     rax, [r14+rsi*8]
0x14000de00  or      qword ptr [rax+rdi+28h], 0FFFFFFFFFFFFFFFFh
0x14000de06  xor     eax, eax
0x14000de08  jmp     short loc_14000DE20
0x14000de0a  call    _errno
0x14000de0f  mov     dword ptr [rax], 9
0x14000de15  call    __doserrno
0x14000de1a  and     dword ptr [rax], 0
0x14000de1d  or      eax, 0FFFFFFFFh
0x14000de20  mov     rbx, [rsp+28h+arg_0]
0x14000de25  mov     rsi, [rsp+28h+arg_8]
0x14000de2a  mov     rdi, [rsp+28h+arg_10]
0x14000de2f  add     rsp, 20h
0x14000de33  pop     r14
0x14000de35  retn

// ===== _get_osfhandle @ 0x14000de38 =====

0x14000de38  sub     rsp, 28h
0x14000de3c  cmp     ecx, 0FFFFFFFEh
0x14000de3f  jnz     short loc_14000DE56
0x14000de41  call    __doserrno
0x14000de46  and     dword ptr [rax], 0
0x14000de49  call    _errno
0x14000de4e  mov     dword ptr [rax], 9
0x14000de54  jmp     short loc_14000DEA4
0x14000de56  test    ecx, ecx
0x14000de58  js      short loc_14000DE8C
0x14000de5a  cmp     ecx, cs:dword_140021BF0
0x14000de60  jnb     short loc_14000DE8C
0x14000de62  movsxd  rdx, ecx
0x14000de65  lea     rcx, qword_1400217F0
0x14000de6c  mov     rax, rdx
0x14000de6f  and     edx, 3Fh
0x14000de72  sar     rax, 6
0x14000de76  shl     rdx, 6
0x14000de7a  mov     rax, [rcx+rax*8]
0x14000de7e  test    byte ptr [rax+rdx+38h], 1
0x14000de83  jz      short loc_14000DE8C
0x14000de85  mov     rax, [rax+rdx+28h]
0x14000de8a  jmp     short loc_14000DEA8
0x14000de8c  call    __doserrno
0x14000de91  and     dword ptr [rax], 0
0x14000de94  call    _errno
0x14000de99  mov     dword ptr [rax], 9
0x14000de9f  call    _invalid_parameter_noinfo
0x14000dea4  or      rax, 0FFFFFFFFFFFFFFFFh
0x14000dea8  add     rsp, 28h
0x14000deac  retn

// ===== __acrt_locale_free_monetary @ 0x14000deb0 =====

0x14000deb0  test    rcx, rcx
0x14000deb3  jz      locret_14000DFB9
0x14000deb9  push    rbx
0x14000deba  sub     rsp, 20h
0x14000debe  mov     rbx, rcx
0x14000dec1  mov     rcx, [rcx+18h]; Block
0x14000dec5  cmp     rcx, cs:off_140020AA8
0x14000decc  jz      short loc_14000DED3
0x14000dece  call    _free_base
0x14000ded3  mov     rcx, [rbx+20h]; Block
0x14000ded7  cmp     rcx, cs:off_140020AB0
0x14000dede  jz      short loc_14000DEE5
0x14000dee0  call    _free_base
0x14000dee5  mov     rcx, [rbx+28h]; Block
0x14000dee9  cmp     rcx, cs:off_140020AB8
0x14000def0  jz      short loc_14000DEF7
0x14000def2  call    _free_base
0x14000def7  mov     rcx, [rbx+30h]; Block
0x14000defb  cmp     rcx, cs:off_140020AC0
0x14000df02  jz      short loc_14000DF09
0x14000df04  call    _free_base
0x14000df09  mov     rcx, [rbx+38h]; Block
0x14000df0d  cmp     rcx, cs:off_140020AC8
0x14000df14  jz      short loc_14000DF1B
0x14000df16  call    _free_base
0x14000df1b  mov     rcx, [rbx+40h]; Block
0x14000df1f  cmp     rcx, cs:off_140020AD0
0x14000df26  jz      short loc_14000DF2D
0x14000df28  call    _free_base
0x14000df2d  mov     rcx, [rbx+48h]; Block
0x14000df31  cmp     rcx, cs:off_140020AD8
0x14000df38  jz      short loc_14000DF3F
0x14000df3a  call    _free_base
0x14000df3f  mov     rcx, [rbx+68h]; Block
0x14000df43  cmp     rcx, cs:off_140020AF8
0x14000df4a  jz      short loc_14000DF51
0x14000df4c  call    _free_base
0x14000df51  mov     rcx, [rbx+70h]; Block
0x14000df55  cmp     rcx, cs:off_140020B00
0x14000df5c  jz      short loc_14000DF63
0x14000df5e  call    _free_base
0x14000df63  mov     rcx, [rbx+78h]; Block
0x14000df67  cmp     rcx, cs:off_140020B08
0x14000df6e  jz      short loc_14000DF75
0x14000df70  call    _free_base
0x14000df75  mov     rcx, [rbx+80h]; Block
0x14000df7c  cmp     rcx, cs:off_140020B10
0x14000df83  jz      short loc_14000DF8A
0x14000df85  call    _free_base
0x14000df8a  mov     rcx, [rbx+88h]; Block
0x14000df91  cmp     rcx, cs:off_140020B18
0x14000df98  jz      short loc_14000DF9F
0x14000df9a  call    _free_base
0x14000df9f  mov     rcx, [rbx+90h]; Block
0x14000dfa6  cmp     rcx, cs:off_140020B20
0x14000dfad  jz      short loc_14000DFB4
0x14000dfaf  call    _free_base
0x14000dfb4  add     rsp, 20h
0x14000dfb8  pop     rbx
0x14000dfb9  retn

// ===== __acrt_locale_free_numeric @ 0x14000dfbc =====

0x14000dfbc  test    rcx, rcx
0x14000dfbf  jz      short locret_14000E027
0x14000dfc1  push    rbx
0x14000dfc2  sub     rsp, 20h
0x14000dfc6  mov     rbx, rcx
0x14000dfc9  mov     rcx, [rcx]; Block
0x14000dfcc  cmp     rcx, cs:off_140020A90
0x14000dfd3  jz      short loc_14000DFDA
0x14000dfd5  call    _free_base
0x14000dfda  mov     rcx, [rbx+8]; Block
0x14000dfde  cmp     rcx, cs:off_140020A98
0x14000dfe5  jz      short loc_14000DFEC
0x14000dfe7  call    _free_base
0x14000dfec  mov     rcx, [rbx+10h]; Block
0x14000dff0  cmp     rcx, cs:off_140020AA0
0x14000dff7  jz      short loc_14000DFFE
0x14000dff9  call    _free_base
0x14000dffe  mov     rcx, [rbx+58h]; Block
0x14000e002  cmp     rcx, cs:off_140020AE8
0x14000e009  jz      short loc_14000E010
0x14000e00b  call    _free_base
0x14000e010  mov     rcx, [rbx+60h]; Block
0x14000e014  cmp     rcx, cs:off_140020AF0
0x14000e01b  jz      short loc_14000E022
0x14000e01d  call    _free_base
0x14000e022  add     rsp, 20h
0x14000e026  pop     rbx
0x14000e027  retn

// ===== ?free_crt_array_internal@@YAXQEAPEBX_K@Z @ 0x14000e028 =====

0x14000e028  mov     [rsp+arg_0], rbx
0x14000e02d  mov     [rsp+arg_8], rsi
0x14000e032  push    rdi
0x14000e033  sub     rsp, 20h
0x14000e037  xor     edi, edi
0x14000e039  lea     rax, [rcx+rdx*8]
0x14000e03d  mov     rsi, rax
0x14000e040  mov     rbx, rcx
0x14000e043  sub     rsi, rcx
0x14000e046  add     rsi, 7
0x14000e04a  shr     rsi, 3
0x14000e04e  cmp     rcx, rax
0x14000e051  cmova   rsi, rdi
0x14000e055  test    rsi, rsi
0x14000e058  jz      short loc_14000E06E
0x14000e05a  mov     rcx, [rbx]; Block
0x14000e05d  call    _free_base
0x14000e062  inc     rdi
0x14000e065  lea     rbx, [rbx+8]
0x14000e069  cmp     rdi, rsi
0x14000e06c  jnz     short loc_14000E05A
0x14000e06e  mov     rbx, [rsp+28h+arg_0]
0x14000e073  mov     rsi, [rsp+28h+arg_8]
0x14000e078  add     rsp, 20h
0x14000e07c  pop     rdi
0x14000e07d  retn

// ===== __acrt_locale_free_time @ 0x14000e080 =====

0x14000e080  test    rcx, rcx
0x14000e083  jz      locret_14000E187
0x14000e089  mov     [rsp+arg_0], rbx
0x14000e08e  mov     [rsp+arg_8], rbp
0x14000e093  push    rsi
0x14000e094  sub     rsp, 20h
0x14000e098  mov     ebp, 7
0x14000e09d  mov     rbx, rcx
0x14000e0a0  mov     edx, ebp; unsigned __int64
0x14000e0a2  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000e0a7  lea     rcx, [rbx+38h]; void **
0x14000e0ab  mov     edx, ebp; unsigned __int64
0x14000e0ad  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000e0b2  lea     esi, [rbp+5]
0x14000e0b5  mov     edx, esi; unsigned __int64
0x14000e0b7  lea     rcx, [rbx+70h]; void **
0x14000e0bb  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000e0c0  lea     rcx, [rbx+0D0h]; void **
0x14000e0c7  mov     edx, esi; unsigned __int64
0x14000e0c9  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000e0ce  lea     rcx, [rbx+130h]; void **
0x14000e0d5  lea     edx, [rbp-5]; unsigned __int64
0x14000e0d8  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000e0dd  mov     rcx, [rbx+140h]; Block
0x14000e0e4  call    _free_base
0x14000e0e9  mov     rcx, [rbx+148h]; Block
0x14000e0f0  call    _free_base
0x14000e0f5  mov     rcx, [rbx+150h]; Block
0x14000e0fc  call    _free_base
0x14000e101  lea     rcx, [rbx+160h]; void **
0x14000e108  mov     edx, ebp; unsigned __int64
0x14000e10a  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000e10f  lea     rcx, [rbx+198h]; void **
0x14000e116  mov     edx, ebp; unsigned __int64
0x14000e118  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000e11d  lea     rcx, [rbx+1D0h]; void **
0x14000e124  mov     edx, esi; unsigned __int64
0x14000e126  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000e12b  lea     rcx, [rbx+230h]; void **
0x14000e132  mov     edx, esi; unsigned __int64
0x14000e134  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000e139  lea     rcx, [rbx+290h]; void **
0x14000e140  lea     edx, [rbp-5]; unsigned __int64
0x14000e143  call    ?free_crt_array_internal@@YAXQEAPEBX_K@Z
0x14000e148  mov     rcx, [rbx+2A0h]; Block
0x14000e14f  call    _free_base
0x14000e154  mov     rcx, [rbx+2A8h]; Block
0x14000e15b  call    _free_base
0x14000e160  mov     rcx, [rbx+2B0h]; Block
0x14000e167  call    _free_base
0x14000e16c  mov     rcx, [rbx+2B8h]; Block
0x14000e173  call    _free_base
0x14000e178  mov     rbx, [rsp+28h+arg_0]
0x14000e17d  mov     rbp, [rsp+28h+arg_8]
0x14000e182  add     rsp, 20h
0x14000e186  pop     rsi
0x14000e187  retn

// ===== __pctype_func @ 0x14000e188 =====

0x14000e188  sub     rsp, 28h
0x14000e18c  call    __acrt_getptd
0x14000e191  lea     rdx, [rsp+28h+arg_0]
0x14000e196  mov     rcx, [rax+90h]
0x14000e19d  mov     [rsp+28h+arg_0], rcx
0x14000e1a2  mov     rcx, rax
0x14000e1a5  call    sub_14000AB8C
0x14000e1aa  mov     rax, [rsp+28h+arg_0]
0x14000e1af  mov     rax, [rax]
0x14000e1b2  add     rsp, 28h
0x14000e1b6  retn

// ===== wcspbrk @ 0x14000e1b8 =====

0x14000e1b8  mov     r8, rdx
0x14000e1bb  xor     r9d, r9d
0x14000e1be  cmp     [rcx], r9w
0x14000e1c2  jz      short loc_14000E1EC
0x14000e1c4  mov     rax, r8
0x14000e1c7  cmp     [r8], r9w
0x14000e1cb  jz      short loc_14000E1E2
0x14000e1cd  movzx   edx, word ptr [r8]
0x14000e1d1  cmp     dx, [rcx]
0x14000e1d4  jz      short loc_14000E1E8
0x14000e1d6  add     rax, 2
0x14000e1da  movzx   edx, word ptr [rax]
0x14000e1dd  test    dx, dx
0x14000e1e0  jnz     short loc_14000E1D1
0x14000e1e2  add     rcx, 2
0x14000e1e6  jmp     short loc_14000E1BE
0x14000e1e8  mov     rax, rcx
0x14000e1eb  retn
0x14000e1ec  xor     eax, eax
0x14000e1ee  retn

// ===== __acrt_GetStringTypeA @ 0x14000e1f0 =====

0x14000e1f0  push    rbp
0x14000e1f2  push    r12
0x14000e1f4  push    r13
0x14000e1f6  push    r14
0x14000e1f8  push    r15
0x14000e1fa  sub     rsp, 60h
0x14000e1fe  lea     rbp, [rsp+30h]
0x14000e203  mov     [rbp+50h+arg_0], rbx
0x14000e207  mov     [rbp+50h+arg_8], rsi
0x14000e20b  mov     [rbp+50h+arg_10], rdi
0x14000e20f  mov     rax, cs:__security_cookie
0x14000e216  xor     rax, rbp
0x14000e219  mov     [rbp+50h+var_30], rax
0x14000e21d  mov     r13d, edx
0x14000e220  mov     r15d, r9d
0x14000e223  mov     rdx, rcx; struct __crt_locale_pointers *
0x14000e226  mov     r12, r8
0x14000e229  lea     rcx, [rbp+50h+var_50]; this
0x14000e22d  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000e232  mov     esi, [rbp+50h+CodePage]
0x14000e238  test    esi, esi
0x14000e23a  jnz     short loc_14000E243
0x14000e23c  mov     rax, [rbp+50h+var_48]
0x14000e240  mov     esi, [rax+0Ch]
0x14000e243  neg     [rbp+50h+arg_30]
0x14000e249  mov     r9d, r15d; cbMultiByte
0x14000e24c  mov     r8, r12; lpMultiByteStr
0x14000e24f  mov     ecx, esi; CodePage
0x14000e251  sbb     edx, edx
0x14000e253  and     [rsp+80h+cchWideChar], 0
0x14000e258  and     [rsp+80h+lpWideCharStr], 0
0x14000e25e  and     edx, 8
0x14000e261  inc     edx; dwFlags
0x14000e263  call    cs:MultiByteToWideChar; KERNEL32
0x14000e269  movsxd  r14, eax
0x14000e26c  test    eax, eax
0x14000e26e  jnz     short loc_14000E277
0x14000e270  xor     edi, edi
0x14000e272  jmp     loc_14000E368
0x14000e277  mov     rdi, r14
0x14000e27a  add     rdi, rdi
0x14000e27d  lea     rcx, [rdi+10h]
0x14000e281  cmp     rdi, rcx
0x14000e284  sbb     rax, rax
0x14000e287  test    rcx, rax
0x14000e28a  jz      short loc_14000E301
0x14000e28c  lea     rcx, [rdi+10h]
0x14000e290  cmp     rdi, rcx
0x14000e293  sbb     rax, rax
0x14000e296  and     rax, rcx
0x14000e299  cmp     rax, 400h
0x14000e29f  lea     rax, [rdi+10h]
0x14000e2a3  ja      short loc_14000E2DF
0x14000e2a5  cmp     rdi, rax
0x14000e2a8  sbb     rcx, rcx
0x14000e2ab  and     rcx, rax
0x14000e2ae  lea     rax, [rcx+0Fh]
0x14000e2b2  cmp     rax, rcx
0x14000e2b5  ja      short loc_14000E2C1
0x14000e2b7  mov     rax, 0FFFFFFFFFFFFFF0h
0x14000e2c1  and     rax, 0FFFFFFFFFFFFFFF0h
0x14000e2c5  call    _alloca_probe
0x14000e2ca  sub     rsp, rax
0x14000e2cd  lea     rbx, [rsp+80h+var_50]
0x14000e2d2  test    rbx, rbx
0x14000e2d5  jz      short loc_14000E350
0x14000e2d7  mov     dword ptr [rbx], 0CCCCh
0x14000e2dd  jmp     short loc_14000E2FB
0x14000e2df  cmp     rdi, rax
0x14000e2e2  sbb     rcx, rcx
0x14000e2e5  and     rcx, rax; Size
0x14000e2e8  call    _malloc_base
0x14000e2ed  mov     rbx, rax
0x14000e2f0  test    rax, rax
0x14000e2f3  jz      short loc_14000E303
0x14000e2f5  mov     dword ptr [rax], 0DDDDh
0x14000e2fb  add     rbx, 10h
0x14000e2ff  jmp     short loc_14000E303
0x14000e301  xor     ebx, ebx
0x14000e303  test    rbx, rbx
0x14000e306  jz      short loc_14000E350
0x14000e308  mov     r8, rdi
0x14000e30b  xor     edx, edx
0x14000e30d  mov     rcx, rbx
0x14000e310  call    sub_140005B30
0x14000e315  mov     r9d, r15d; cbMultiByte
0x14000e318  mov     [rsp+80h+cchWideChar], r14d; cchWideChar
0x14000e31d  mov     r8, r12; lpMultiByteStr
0x14000e320  mov     [rsp+80h+lpWideCharStr], rbx; lpWideCharStr
0x14000e325  mov     edx, 1; dwFlags
0x14000e32a  mov     ecx, esi; CodePage
0x14000e32c  call    cs:MultiByteToWideChar; KERNEL32
0x14000e332  test    eax, eax
0x14000e334  jz      short loc_14000E350
0x14000e336  mov     r9, [rbp+50h+lpCharType]; lpCharType
0x14000e33d  mov     r8d, eax; cchSrc
0x14000e340  mov     rdx, rbx; lpSrcStr
0x14000e343  mov     ecx, r13d; dwInfoType
0x14000e346  call    cs:GetStringTypeW; KERNEL32
0x14000e34c  mov     edi, eax
0x14000e34e  jmp     short loc_14000E352
0x14000e350  xor     edi, edi
0x14000e352  test    rbx, rbx
0x14000e355  jz      short loc_14000E368
0x14000e357  lea     rcx, [rbx-10h]; Block
0x14000e35b  cmp     dword ptr [rcx], 0DDDDh
0x14000e361  jnz     short loc_14000E368
0x14000e363  call    _free_base
0x14000e368  cmp     [rbp+50h+var_38], 0
0x14000e36c  jz      short loc_14000E379
0x14000e36e  mov     rax, [rbp+50h+var_50]
0x14000e372  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x14000e379  mov     eax, edi
0x14000e37b  mov     rcx, [rbp+50h+var_30]
0x14000e37f  xor     rcx, rbp; StackCookie
0x14000e382  call    __security_check_cookie
0x14000e387  mov     rbx, [rbp+50h+arg_0]
0x14000e38b  mov     rsi, [rbp+50h+arg_8]
0x14000e38f  mov     rdi, [rbp+50h+arg_10]
0x14000e393  lea     rsp, [rbp+30h]
0x14000e397  pop     r15
0x14000e399  pop     r14
0x14000e39b  pop     r13
0x14000e39d  pop     r12
0x14000e39f  pop     rbp
0x14000e3a0  retn

// ===== __acrt_add_locale_ref @ 0x14000e3a4 =====

0x14000e3a4  lock inc dword ptr [rcx+10h]
0x14000e3a8  mov     rax, [rcx+0E0h]
0x14000e3af  test    rax, rax
0x14000e3b2  jz      short loc_14000E3B7
0x14000e3b4  lock inc dword ptr [rax]
0x14000e3b7  mov     rax, [rcx+0F0h]
0x14000e3be  test    rax, rax
0x14000e3c1  jz      short loc_14000E3C6
0x14000e3c3  lock inc dword ptr [rax]
0x14000e3c6  mov     rax, [rcx+0E8h]
0x14000e3cd  test    rax, rax
0x14000e3d0  jz      short loc_14000E3D5
0x14000e3d2  lock inc dword ptr [rax]
0x14000e3d5  mov     rax, [rcx+100h]
0x14000e3dc  test    rax, rax
0x14000e3df  jz      short loc_14000E3E4
0x14000e3e1  lock inc dword ptr [rax]
0x14000e3e4  lea     rax, [rcx+38h]
0x14000e3e8  mov     r8d, 6
0x14000e3ee  lea     rdx, unk_140020428
0x14000e3f5  cmp     [rax-10h], rdx
0x14000e3f9  jz      short loc_14000E406
0x14000e3fb  mov     rdx, [rax]
0x14000e3fe  test    rdx, rdx
0x14000e401  jz      short loc_14000E406
0x14000e403  lock inc dword ptr [rdx]
0x14000e406  cmp     qword ptr [rax-18h], 0
0x14000e40b  jz      short loc_14000E419
0x14000e40d  mov     rdx, [rax-8]
0x14000e411  test    rdx, rdx
0x14000e414  jz      short loc_14000E419
0x14000e416  lock inc dword ptr [rdx]
0x14000e419  add     rax, 20h ; ' '
0x14000e41d  sub     r8, 1
0x14000e421  jnz     short loc_14000E3EE
0x14000e423  mov     rcx, [rcx+120h]
0x14000e42a  jmp     __acrt_locale_add_lc_time_reference
0x14000e5a8  test    rcx, rcx
0x14000e5ab  jz      short loc_14000E5C9
0x14000e5ad  lea     rax, off_140015C20
0x14000e5b4  cmp     rcx, rax
0x14000e5b7  jz      short loc_14000E5C9
0x14000e5b9  mov     eax, 1
0x14000e5be  lock xadd [rcx+15Ch], eax
0x14000e5c6  inc     eax
0x14000e5c8  retn
0x14000e5c9  mov     eax, 7FFFFFFFh
0x14000e5ce  retn

// ===== __acrt_free_locale @ 0x14000e430 =====

0x14000e430  mov     [rsp+arg_0], rbx
0x14000e435  mov     [rsp+arg_8], rbp
0x14000e43a  mov     [rsp+arg_10], rsi
0x14000e43f  push    rdi
0x14000e440  sub     rsp, 20h
0x14000e444  mov     rax, [rcx+0F8h]
0x14000e44b  mov     rbx, rcx
0x14000e44e  test    rax, rax
0x14000e451  jz      short loc_14000E4CC
0x14000e453  lea     rcx, off_140020A90
0x14000e45a  cmp     rax, rcx
0x14000e45d  jz      short loc_14000E4CC
0x14000e45f  mov     rax, [rbx+0E0h]
0x14000e466  test    rax, rax
0x14000e469  jz      short loc_14000E4CC
0x14000e46b  cmp     dword ptr [rax], 0
0x14000e46e  jnz     short loc_14000E4CC
0x14000e470  mov     rcx, [rbx+0F0h]; Block
0x14000e477  test    rcx, rcx
0x14000e47a  jz      short loc_14000E492
0x14000e47c  cmp     dword ptr [rcx], 0
0x14000e47f  jnz     short loc_14000E492
0x14000e481  call    _free_base
0x14000e486  mov     rcx, [rbx+0F8h]
0x14000e48d  call    __acrt_locale_free_monetary
0x14000e492  mov     rcx, [rbx+0E8h]; Block
0x14000e499  test    rcx, rcx
0x14000e49c  jz      short loc_14000E4B4
0x14000e49e  cmp     dword ptr [rcx], 0
0x14000e4a1  jnz     short loc_14000E4B4
0x14000e4a3  call    _free_base
0x14000e4a8  mov     rcx, [rbx+0F8h]
0x14000e4af  call    __acrt_locale_free_numeric
0x14000e4b4  mov     rcx, [rbx+0E0h]; Block
0x14000e4bb  call    _free_base
0x14000e4c0  mov     rcx, [rbx+0F8h]; Block
0x14000e4c7  call    _free_base
0x14000e4cc  mov     rax, [rbx+100h]
0x14000e4d3  test    rax, rax
0x14000e4d6  jz      short loc_14000E51F
0x14000e4d8  cmp     dword ptr [rax], 0
0x14000e4db  jnz     short loc_14000E51F
0x14000e4dd  mov     rcx, [rbx+108h]
0x14000e4e4  sub     rcx, 0FEh; Block
0x14000e4eb  call    _free_base
0x14000e4f0  mov     rcx, [rbx+110h]
0x14000e4f7  mov     edi, 80h
0x14000e4fc  sub     rcx, rdi; Block
0x14000e4ff  call    _free_base
0x14000e504  mov     rcx, [rbx+118h]
0x14000e50b  sub     rcx, rdi; Block
0x14000e50e  call    _free_base
0x14000e513  mov     rcx, [rbx+100h]; Block
0x14000e51a  call    _free_base
0x14000e51f  mov     rcx, [rbx+120h]; Block
0x14000e526  call    __acrt_locale_free_lc_time_if_unreferenced
0x14000e52b  lea     rsi, [rbx+128h]
0x14000e532  mov     ebp, 6
0x14000e537  lea     rdi, [rbx+38h]
0x14000e53b  lea     rax, unk_140020428
0x14000e542  cmp     [rdi-10h], rax
0x14000e546  jz      short loc_14000E562
0x14000e548  mov     rcx, [rdi]; Block
0x14000e54b  test    rcx, rcx
0x14000e54e  jz      short loc_14000E562
0x14000e550  cmp     dword ptr [rcx], 0
0x14000e553  jnz     short loc_14000E562
0x14000e555  call    _free_base
0x14000e55a  mov     rcx, [rsi]; Block
0x14000e55d  call    _free_base
0x14000e562  cmp     qword ptr [rdi-18h], 0
0x14000e567  jz      short loc_14000E57C
0x14000e569  mov     rcx, [rdi-8]; Block
0x14000e56d  test    rcx, rcx
0x14000e570  jz      short loc_14000E57C
0x14000e572  cmp     dword ptr [rcx], 0
0x14000e575  jnz     short loc_14000E57C
0x14000e577  call    _free_base
0x14000e57c  add     rsi, 8
0x14000e580  add     rdi, 20h ; ' '
0x14000e584  sub     rbp, 1
0x14000e588  jnz     short loc_14000E53B
0x14000e58a  mov     rcx, rbx; Block
0x14000e58d  mov     rbx, [rsp+28h+arg_0]
0x14000e592  mov     rbp, [rsp+28h+arg_8]
0x14000e597  mov     rsi, [rsp+28h+arg_10]
0x14000e59c  add     rsp, 20h
0x14000e5a0  pop     rdi
0x14000e5a1  jmp     _free_base

// ===== __acrt_locale_free_lc_time_if_unreferenced @ 0x14000e5d0 =====

0x14000e5d0  test    rcx, rcx
0x14000e5d3  jz      short locret_14000E605
0x14000e5d5  push    rbx
0x14000e5d6  sub     rsp, 20h
0x14000e5da  lea     rax, off_140015C20
0x14000e5e1  mov     rbx, rcx
0x14000e5e4  cmp     rcx, rax
0x14000e5e7  jz      short loc_14000E600
0x14000e5e9  mov     eax, [rcx+15Ch]
0x14000e5ef  test    eax, eax
0x14000e5f1  jnz     short loc_14000E600
0x14000e5f3  call    __acrt_locale_free_time
0x14000e5f8  mov     rcx, rbx; Block
0x14000e5fb  call    _free_base
0x14000e600  add     rsp, 20h
0x14000e604  pop     rbx
0x14000e605  retn

// ===== __acrt_locale_release_lc_time_reference @ 0x14000e608 =====

0x14000e608  test    rcx, rcx
0x14000e60b  jz      short loc_14000E627
0x14000e60d  lea     rax, off_140015C20
0x14000e614  cmp     rcx, rax
0x14000e617  jz      short loc_14000E627
0x14000e619  or      eax, 0FFFFFFFFh
0x14000e61c  lock xadd [rcx+15Ch], eax
0x14000e624  dec     eax
0x14000e626  retn
0x14000e627  mov     eax, 7FFFFFFFh
0x14000e62c  retn

// ===== __acrt_release_locale_ref @ 0x14000e630 =====

0x14000e630  sub     rsp, 28h
0x14000e634  test    rcx, rcx
0x14000e637  jz      loc_14000E6D3
0x14000e63d  or      r9d, 0FFFFFFFFh
0x14000e641  lock add [rcx+10h], r9d
0x14000e646  mov     rax, [rcx+0E0h]
0x14000e64d  test    rax, rax
0x14000e650  jz      short loc_14000E656
0x14000e652  lock add [rax], r9d
0x14000e656  mov     rax, [rcx+0F0h]
0x14000e65d  test    rax, rax
0x14000e660  jz      short loc_14000E666
0x14000e662  lock add [rax], r9d
0x14000e666  mov     rax, [rcx+0E8h]
0x14000e66d  test    rax, rax
0x14000e670  jz      short loc_14000E676
0x14000e672  lock add [rax], r9d
0x14000e676  mov     rax, [rcx+100h]
0x14000e67d  test    rax, rax
0x14000e680  jz      short loc_14000E686
0x14000e682  lock add [rax], r9d
0x14000e686  lea     rax, [rcx+38h]
0x14000e68a  mov     r8d, 6
0x14000e690  lea     rdx, unk_140020428
0x14000e697  cmp     [rax-10h], rdx
0x14000e69b  jz      short loc_14000E6A9
0x14000e69d  mov     rdx, [rax]
0x14000e6a0  test    rdx, rdx
0x14000e6a3  jz      short loc_14000E6A9
0x14000e6a5  lock add [rdx], r9d
0x14000e6a9  cmp     qword ptr [rax-18h], 0
0x14000e6ae  jz      short loc_14000E6BD
0x14000e6b0  mov     rdx, [rax-8]
0x14000e6b4  test    rdx, rdx
0x14000e6b7  jz      short loc_14000E6BD
0x14000e6b9  lock add [rdx], r9d
0x14000e6bd  add     rax, 20h ; ' '
0x14000e6c1  sub     r8, 1
0x14000e6c5  jnz     short loc_14000E690
0x14000e6c7  mov     rcx, [rcx+120h]
0x14000e6ce  call    __acrt_locale_release_lc_time_reference
0x14000e6d3  add     rsp, 28h
0x14000e6d7  retn

// ===== __acrt_update_thread_locale_data @ 0x14000e6d8 =====

0x14000e6d8  mov     [rsp+arg_0], rbx
0x14000e6dd  push    rdi
0x14000e6de  sub     rsp, 20h
0x14000e6e2  call    __acrt_getptd
0x14000e6e7  mov     rdi, rax
0x14000e6ea  mov     ecx, cs:dword_140020B30
0x14000e6f0  test    [rax+3A8h], ecx
0x14000e6f6  jz      short loc_14000E704
0x14000e6f8  mov     rbx, [rax+90h]
0x14000e6ff  test    rbx, rbx
0x14000e702  jnz     short loc_14000E73A
0x14000e704  mov     ecx, 4
0x14000e709  call    sub_14000D540
0x14000e70e  nop
0x14000e70f  lea     rcx, [rdi+90h]
0x14000e716  mov     rdx, cs:qword_1400217C0
0x14000e71d  call    _updatetlocinfoEx_nolock
0x14000e722  mov     rbx, rax
0x14000e725  mov     ecx, 4
0x14000e72a  call    sub_14000D594
0x14000e72f  test    rbx, rbx
0x14000e732  jnz     short loc_14000E73A
0x14000e734  call    abort
0x14000e73a  mov     rax, rbx
0x14000e73d  mov     rbx, [rsp+28h+arg_0]
0x14000e742  add     rsp, 20h
0x14000e746  pop     rdi
0x14000e747  retn
0x1400139b2  push    rbp; Microsoft VisualC 64bit universal runtime
0x1400139b4  sub     rsp, 20h
0x1400139b8  mov     rbp, rdx
0x1400139bb  mov     ecx, 4
0x1400139c0  add     rsp, 20h
0x1400139c4  pop     rbp
0x1400139c5  jmp     sub_14000D594

// ===== _updatetlocinfoEx_nolock @ 0x14000e748 =====

0x14000e748  mov     [rsp+arg_0], rbx
0x14000e74d  push    rdi
0x14000e74e  sub     rsp, 20h
0x14000e752  mov     rdi, rdx
0x14000e755  test    rdx, rdx
0x14000e758  jz      short loc_14000E7A3
0x14000e75a  test    rcx, rcx
0x14000e75d  jz      short loc_14000E7A3
0x14000e75f  mov     rbx, [rcx]
0x14000e762  cmp     rbx, rdx
0x14000e765  jnz     short loc_14000E76C
0x14000e767  mov     rax, rdx
0x14000e76a  jmp     short loc_14000E7A5
0x14000e76c  mov     [rcx], rdx
0x14000e76f  mov     rcx, rdx
0x14000e772  call    __acrt_add_locale_ref
0x14000e777  test    rbx, rbx
0x14000e77a  jz      short loc_14000E79E
0x14000e77c  mov     rcx, rbx
0x14000e77f  call    __acrt_release_locale_ref
0x14000e784  cmp     dword ptr [rbx+10h], 0
0x14000e788  jnz     short loc_14000E79E
0x14000e78a  lea     rax, off_1400202C0
0x14000e791  cmp     rbx, rax
0x14000e794  jz      short loc_14000E79E
0x14000e796  mov     rcx, rbx; Block
0x14000e799  call    __acrt_free_locale
0x14000e79e  mov     rax, rdi
0x14000e7a1  jmp     short loc_14000E7A5
0x14000e7a3  xor     eax, eax
0x14000e7a5  mov     rbx, [rsp+28h+arg_0]
0x14000e7aa  add     rsp, 20h
0x14000e7ae  pop     rdi
0x14000e7af  retn

// ===== j__recalloc_base @ 0x14000e7b0 =====

0x14000e7b0  jmp     _recalloc_base

// ===== _recalloc_base @ 0x14000e7b8 =====

0x14000e7b8  mov     [rsp+arg_0], rbx
0x14000e7bd  mov     [rsp+arg_8], rbp
0x14000e7c2  mov     [rsp+arg_10], rsi
0x14000e7c7  push    rdi
0x14000e7c8  sub     rsp, 20h
0x14000e7cc  mov     rbp, r8
0x14000e7cf  mov     rbx, rdx
0x14000e7d2  mov     rsi, rcx
0x14000e7d5  test    rdx, rdx
0x14000e7d8  jz      short loc_14000E7F7
0x14000e7da  xor     edx, edx
0x14000e7dc  lea     rax, [rdx-20h]
0x14000e7e0  div     rbx
0x14000e7e3  cmp     rax, r8
0x14000e7e6  jnb     short loc_14000E7F7
0x14000e7e8  call    _errno
0x14000e7ed  mov     dword ptr [rax], 0Ch
0x14000e7f3  xor     eax, eax
0x14000e7f5  jmp     short loc_14000E838
0x14000e7f7  test    rcx, rcx
0x14000e7fa  jz      short loc_14000E806
0x14000e7fc  call    _msize
0x14000e801  mov     rdi, rax
0x14000e804  jmp     short loc_14000E808
0x14000e806  xor     edi, edi
0x14000e808  imul    rbx, rbp
0x14000e80c  mov     rcx, rsi; Block
0x14000e80f  mov     rdx, rbx; Size
0x14000e812  call    _realloc_base
0x14000e817  mov     rsi, rax
0x14000e81a  test    rax, rax
0x14000e81d  jz      short loc_14000E835
0x14000e81f  cmp     rdi, rbx
0x14000e822  jnb     short loc_14000E835
0x14000e824  sub     rbx, rdi
0x14000e827  lea     rcx, [rax+rdi]
0x14000e82b  mov     r8, rbx
0x14000e82e  xor     edx, edx
0x14000e830  call    sub_140005B30
0x14000e835  mov     rax, rsi
0x14000e838  mov     rbx, [rsp+28h+arg_0]
0x14000e83d  mov     rbp, [rsp+28h+arg_8]
0x14000e842  mov     rsi, [rsp+28h+arg_10]
0x14000e847  add     rsp, 20h
0x14000e84b  pop     rdi
0x14000e84c  retn

// ===== __acrt_initialize_heap @ 0x14000e850 =====

0x14000e850  sub     rsp, 28h
0x14000e854  call    cs:GetProcessHeap; KERNEL32
0x14000e85a  test    rax, rax
0x14000e85d  mov     cs:hHeap, rax
0x14000e864  setnz   al
0x14000e867  add     rsp, 28h
0x14000e86b  retn

// ===== sub_14000E86C @ 0x14000e86c =====

0x14000e86c  and     cs:hHeap, 0
0x14000e874  mov     al, 1
0x14000e876  retn

// ===== __acrt_execute_initializers @ 0x14000e878 =====

0x14000e878  mov     [rsp+arg_0], rbx
0x14000e87d  mov     [rsp+arg_8], rbp
0x14000e882  mov     [rsp+arg_10], rsi
0x14000e887  push    rdi
0x14000e888  sub     rsp, 20h
0x14000e88c  mov     rsi, rdx
0x14000e88f  mov     rdi, rcx
0x14000e892  cmp     rcx, rdx
0x14000e895  jnz     short loc_14000E89B
0x14000e897  mov     al, 1
0x14000e899  jmp     short loc_14000E8F7
0x14000e89b  mov     rbx, rcx
0x14000e89e  mov     rbp, [rbx]
0x14000e8a1  test    rbp, rbp
0x14000e8a4  jz      short loc_14000E8B5
0x14000e8a6  mov     rcx, rbp
0x14000e8a9  call    cs:__guard_check_icall_fptr
0x14000e8af  call    rbp
0x14000e8b1  test    al, al
0x14000e8b3  jz      short loc_14000E8BE
0x14000e8b5  add     rbx, 10h
0x14000e8b9  cmp     rbx, rsi
0x14000e8bc  jnz     short loc_14000E89E
0x14000e8be  cmp     rbx, rsi
0x14000e8c1  jz      short loc_14000E897
0x14000e8c3  cmp     rbx, rdi
0x14000e8c6  jz      short loc_14000E8F5
0x14000e8c8  add     rbx, 0FFFFFFFFFFFFFFF8h
0x14000e8cc  cmp     qword ptr [rbx-8], 0
0x14000e8d1  jz      short loc_14000E8E8
0x14000e8d3  mov     rsi, [rbx]
0x14000e8d6  test    rsi, rsi
0x14000e8d9  jz      short loc_14000E8E8
0x14000e8db  mov     rcx, rsi
0x14000e8de  call    cs:__guard_check_icall_fptr
0x14000e8e4  xor     ecx, ecx
0x14000e8e6  call    rsi
0x14000e8e8  sub     rbx, 10h
0x14000e8ec  lea     rax, [rbx+8]
0x14000e8f0  cmp     rax, rdi
0x14000e8f3  jnz     short loc_14000E8CC
0x14000e8f5  xor     al, al
0x14000e8f7  mov     rbx, [rsp+28h+arg_0]
0x14000e8fc  mov     rbp, [rsp+28h+arg_8]
0x14000e901  mov     rsi, [rsp+28h+arg_10]
0x14000e906  add     rsp, 20h
0x14000e90a  pop     rdi
0x14000e90b  retn

// ===== __acrt_execute_uninitializers @ 0x14000e90c =====

0x14000e90c  mov     [rsp+arg_0], rbx
0x14000e911  mov     [rsp+arg_8], rsi
0x14000e916  push    rdi
0x14000e917  sub     rsp, 20h
0x14000e91b  mov     rsi, rcx
0x14000e91e  cmp     rcx, rdx
0x14000e921  jz      short loc_14000E949
0x14000e923  lea     rbx, [rdx-8]
0x14000e927  mov     rdi, [rbx]
0x14000e92a  test    rdi, rdi
0x14000e92d  jz      short loc_14000E93C
0x14000e92f  mov     rcx, rdi
0x14000e932  call    cs:__guard_check_icall_fptr
0x14000e938  xor     ecx, ecx
0x14000e93a  call    rdi
0x14000e93c  sub     rbx, 10h
0x14000e940  lea     rax, [rbx+8]
0x14000e944  cmp     rax, rsi
0x14000e947  jnz     short loc_14000E927
0x14000e949  mov     rbx, [rsp+28h+arg_0]
0x14000e94e  mov     al, 1
0x14000e950  mov     rsi, [rsp+28h+arg_8]
0x14000e955  add     rsp, 20h
0x14000e959  pop     rdi
0x14000e95a  retn

// ===== ??$?RV_lambda_c36588078e9f5dfd39652860aa6b3aaf_@@AEAV_lambda_ec61778202f4f5fc7e7711acc23c3bca_@@V_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_@@@?$__crt_seh_guarded_call@P6AXH@Z@@QEAAP6AXH@Z$$QEAV_lambda_c36588078e9f5dfd39652860aa6b3aaf_@@AEAV_lambda_ec61778202f4f5fc7e7711acc23c3bca_@@$$QEAV_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_@@@Z @ 0x14000e95c =====

0x14000e95c  mov     [rsp+arg_0], rbx
0x14000e961  mov     [rsp+arg_18], r9
0x14000e966  push    rdi
0x14000e967  sub     rsp, 20h
0x14000e96b  mov     rdi, r9
0x14000e96e  mov     ecx, [rdx]
0x14000e970  call    sub_14000D540
0x14000e975  nop
0x14000e976  mov     rbx, cs:__security_cookie
0x14000e97d  mov     ecx, ebx
0x14000e97f  and     ecx, 3Fh
0x14000e982  xor     rbx, cs:qword_140022028
0x14000e989  ror     rbx, cl
0x14000e98c  mov     ecx, [rdi]
0x14000e98e  call    sub_14000D594
0x14000e993  mov     rax, rbx
0x14000e996  mov     rbx, [rsp+28h+arg_0]
0x14000e99b  add     rsp, 20h
0x14000e99f  pop     rdi
0x14000e9a0  retn
0x1400139e1  push    rbp
0x1400139e3  sub     rsp, 20h
0x1400139e7  mov     rbp, rdx
0x1400139ea  mov     rax, [rbp+48h]
0x1400139ee  mov     ecx, [rax]
0x1400139f0  add     rsp, 20h
0x1400139f4  pop     rbp
0x1400139f5  jmp     sub_14000D594

// ===== __acrt_get_sigabrt_handler @ 0x14000e9a4 =====

0x14000e9a4  mov     r11, rsp
0x14000e9a7  sub     rsp, 28h
0x14000e9ab  mov     eax, 3
0x14000e9b0  lea     r9, [r11+10h]
0x14000e9b4  lea     r8, [r11+8]
0x14000e9b8  mov     [rsp+28h+arg_8], eax
0x14000e9bc  lea     rdx, [r11+18h]
0x14000e9c0  mov     [rsp+28h+arg_10], eax
0x14000e9c4  lea     rcx, [r11+8]
0x14000e9c8  call    ??$?RV_lambda_c36588078e9f5dfd39652860aa6b3aaf_@@AEAV_lambda_ec61778202f4f5fc7e7711acc23c3bca_@@V_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_@@@?$__crt_seh_guarded_call@P6AXH@Z@@QEAAP6AXH@Z$$QEAV_lambda_c36588078e9f5dfd39652860aa6b3aaf_@@AEAV_lambda_ec61778202f4f5fc7e7711acc23c3bca_@@$$QEAV_lambda_dc9d2797ccde5d239b4a0efae8ebd7db_@@@Z
0x14000e9cd  add     rsp, 28h
0x14000e9d1  retn

// ===== __acrt_initialize_signal_handlers @ 0x14000e9d4 =====

0x14000e9d4  mov     cs:qword_140022018, rcx
0x14000e9db  mov     cs:qword_140022020, rcx
0x14000e9e2  mov     cs:qword_140022028, rcx
0x14000e9e9  mov     cs:qword_140022030, rcx
0x14000e9f0  retn

// ===== raise @ 0x14000e9f4 =====

0x14000e9f4  mov     rax, rsp
0x14000e9f7  push    rbx
0x14000e9f8  push    rsi
0x14000e9f9  push    rdi
0x14000e9fa  push    r12
0x14000e9fc  push    r13
0x14000e9fe  push    r15
0x14000ea00  sub     rsp, 48h
0x14000ea04  mov     edi, ecx
0x14000ea06  xor     r13d, r13d
0x14000ea09  and     [rax+18h], r13d
0x14000ea0d  mov     sil, 1
0x14000ea10  mov     [rsp+78h+arg_0], sil
0x14000ea18  cmp     ecx, 2
0x14000ea1b  jz      loc_14000EAAF
0x14000ea21  cmp     ecx, 4
0x14000ea24  jz      short loc_14000EA48
0x14000ea26  cmp     ecx, 6
0x14000ea29  jz      loc_14000EAAF
0x14000ea2f  cmp     ecx, 8
0x14000ea32  jz      short loc_14000EA48
0x14000ea34  cmp     ecx, 0Bh
0x14000ea37  jz      short loc_14000EA48
0x14000ea39  cmp     ecx, 0Fh
0x14000ea3c  jz      short loc_14000EAAF
0x14000ea3e  lea     eax, [rcx-15h]
0x14000ea41  cmp     eax, 1
0x14000ea44  jbe     short loc_14000EAAF
0x14000ea46  jmp     short loc_14000EA8C
0x14000ea48  call    __acrt_getptd_noexit
0x14000ea4d  mov     r13, rax
0x14000ea50  test    rax, rax
0x14000ea53  jnz     short loc_14000EA5D
0x14000ea55  or      eax, 0FFFFFFFFh
0x14000ea58  jmp     loc_14000EC7F
0x14000ea5d  mov     rcx, [rax]
0x14000ea60  mov     rdx, cs:qword_140015980
0x14000ea67  shl     rdx, 4
0x14000ea6b  add     rdx, rcx
0x14000ea6e  jmp     short loc_14000EA79
0x14000ea70  cmp     [rcx+4], edi
0x14000ea73  jz      short loc_14000EA80
0x14000ea75  add     rcx, 10h
0x14000ea79  cmp     rcx, rdx
0x14000ea7c  jnz     short loc_14000EA70
0x14000ea7e  xor     ecx, ecx
0x14000ea80  xor     eax, eax
0x14000ea82  test    rcx, rcx
0x14000ea85  setnz   al
0x14000ea88  test    eax, eax
0x14000ea8a  jnz     short loc_14000EA9E
0x14000ea8c  call    _errno
0x14000ea91  mov     dword ptr [rax], 16h
0x14000ea97  call    _invalid_parameter_noinfo
0x14000ea9c  jmp     short loc_14000EA55
0x14000ea9e  lea     rbx, [rcx+8]
0x14000eaa2  xor     sil, sil
0x14000eaa5  mov     [rsp+78h+arg_0], sil
0x14000eaad  jmp     short loc_14000EAEE
0x14000eaaf  sub     ecx, 2
0x14000eab2  jz      short loc_14000EAE7
0x14000eab4  sub     ecx, 4
0x14000eab7  jz      short loc_14000EACC
0x14000eab9  sub     ecx, 9
0x14000eabc  jz      short loc_14000EADE
0x14000eabe  sub     ecx, 6
0x14000eac1  jz      short loc_14000EAD5
0x14000eac3  cmp     ecx, 1
0x14000eac6  jz      short loc_14000EACC
0x14000eac8  xor     ebx, ebx
0x14000eaca  jmp     short loc_14000EAEE
0x14000eacc  lea     rbx, qword_140022028
0x14000ead3  jmp     short loc_14000EAEE
0x14000ead5  lea     rbx, qword_140022020
0x14000eadc  jmp     short loc_14000EAEE
0x14000eade  lea     rbx, qword_140022030
0x14000eae5  jmp     short loc_14000EAEE
0x14000eae7  lea     rbx, qword_140022018
0x14000eaee  and     [rsp+78h+arg_18], 0
0x14000eaf7  test    sil, sil
0x14000eafa  jz      short loc_14000EB07
0x14000eafc  mov     ecx, 3
0x14000eb01  call    sub_14000D540
0x14000eb06  nop
0x14000eb07  test    sil, sil
0x14000eb0a  jz      short loc_14000EB23
0x14000eb0c  mov     rdx, cs:__security_cookie
0x14000eb13  mov     ecx, edx
0x14000eb15  and     ecx, 3Fh
0x14000eb18  xor     rdx, [rbx]
0x14000eb1b  ror     rdx, cl
0x14000eb1e  mov     r15, rdx
0x14000eb21  jmp     short loc_14000EB26
0x14000eb23  mov     r15, [rbx]
0x14000eb26  cmp     r15, 1
0x14000eb2a  setz    al
0x14000eb2d  mov     [rsp+78h+arg_8], al
0x14000eb34  test    al, al
0x14000eb36  jnz     loc_14000EBFB
0x14000eb3c  test    r15, r15
0x14000eb3f  jnz     short loc_14000EB59
0x14000eb41  test    sil, sil
0x14000eb44  jz      short loc_14000EB4F
0x14000eb46  lea     ecx, [r15+3]
0x14000eb4a  call    sub_14000D594
0x14000eb4f  mov     ecx, 3; Code
0x14000eb54  call    _exit
0x14000eb59  mov     r12d, 910h
0x14000eb5f  cmp     edi, 0Bh
0x14000eb62  ja      short loc_14000EBA4
0x14000eb64  bt      r12d, edi
0x14000eb68  jnb     short loc_14000EBA4
0x14000eb6a  mov     rax, [r13+8]
0x14000eb6e  mov     [rsp+78h+arg_18], rax
0x14000eb76  mov     [rsp+78h+var_48], rax
0x14000eb7b  and     qword ptr [r13+8], 0
0x14000eb80  cmp     edi, 8
0x14000eb83  jnz     short loc_14000EBDB
0x14000eb85  call    __acrt_getptd
0x14000eb8a  mov     eax, [rax+10h]
0x14000eb8d  mov     [rsp+78h+arg_10], eax
0x14000eb94  mov     [rsp+78h+var_58], eax
0x14000eb98  call    __acrt_getptd
0x14000eb9d  mov     dword ptr [rax+10h], 8Ch
0x14000eba4  cmp     edi, 8
0x14000eba7  jnz     short loc_14000EBDB
0x14000eba9  mov     rax, cs:qword_140015988
0x14000ebb0  shl     rax, 4
0x14000ebb4  add     rax, [r13+0]
0x14000ebb8  mov     rcx, cs:qword_140015990
0x14000ebbf  shl     rcx, 4
0x14000ebc3  add     rcx, rax
0x14000ebc6  mov     [rsp+78h+var_50], rax
0x14000ebcb  cmp     rax, rcx
0x14000ebce  jz      short loc_14000EC01
0x14000ebd0  and     qword ptr [rax+8], 0
0x14000ebd5  add     rax, 10h
0x14000ebd9  jmp     short loc_14000EBC6
0x14000ebdb  mov     rdx, cs:__security_cookie
0x14000ebe2  mov     eax, edx
0x14000ebe4  and     eax, 3Fh
0x14000ebe7  mov     ecx, 40h ; '@'
0x14000ebec  sub     ecx, eax
0x14000ebee  xor     eax, eax
0x14000ebf0  ror     rax, cl
0x14000ebf3  xor     rax, rdx
0x14000ebf6  mov     [rbx], rax
0x14000ebf9  jmp     short loc_14000EC01
0x14000ebfb  mov     r12d, 910h
0x14000ec01  test    sil, sil
0x14000ec04  jz      short loc_14000EC10
0x14000ec06  mov     ecx, 3
0x14000ec0b  call    sub_14000D594
0x14000ec10  cmp     [rsp+78h+arg_8], 0
0x14000ec18  jz      short loc_14000EC1E
0x14000ec1a  xor     eax, eax
0x14000ec1c  jmp     short loc_14000EC7F
0x14000ec1e  cmp     edi, 8
0x14000ec21  jnz     short loc_14000EC41
0x14000ec23  call    __acrt_getptd
0x14000ec28  mov     rbx, rax
0x14000ec2b  mov     rcx, r15
0x14000ec2e  mov     rdx, cs:__guard_check_icall_fptr
0x14000ec35  call    rdx ; _guard_check_icall_nop
0x14000ec37  mov     edx, [rbx+10h]
0x14000ec3a  mov     ecx, edi
0x14000ec3c  call    r15
0x14000ec3f  jmp     short loc_14000EC52
0x14000ec41  mov     rcx, r15
0x14000ec44  mov     rax, cs:__guard_check_icall_fptr
0x14000ec4b  call    rax ; _guard_check_icall_nop
0x14000ec4d  mov     ecx, edi
0x14000ec4f  call    r15
0x14000ec52  cmp     edi, 0Bh
0x14000ec55  ja      short loc_14000EC1A
0x14000ec57  bt      r12d, edi
0x14000ec5b  jnb     short loc_14000EC1A
0x14000ec5d  mov     rax, [rsp+78h+arg_18]
0x14000ec65  mov     [r13+8], rax
0x14000ec69  cmp     edi, 8
0x14000ec6c  jnz     short loc_14000EC1A
0x14000ec6e  call    __acrt_getptd
0x14000ec73  mov     ecx, [rsp+78h+arg_10]
0x14000ec7a  mov     [rax+10h], ecx
0x14000ec7d  jmp     short loc_14000EC1A
0x14000ec7f  add     rsp, 48h
0x14000ec83  pop     r15
0x14000ec85  pop     r13
0x14000ec87  pop     r12
0x14000ec89  pop     rdi
0x14000ec8a  pop     rsi
0x14000ec8b  pop     rbx
0x14000ec8c  retn
0x140013a62  push    rbp
0x140013a64  sub     rsp, 20h
0x140013a68  mov     rbp, rdx
0x140013a6b  cmp     byte ptr [rbp+80h], 0
0x140013a72  jz      short loc_140013A7F
0x140013a74  mov     ecx, 3
0x140013a79  call    sub_14000D594
0x140013a7e  nop
0x140013a7f  add     rsp, 20h
0x140013a83  pop     rbp
0x140013a84  retn

// ===== ?__acrt_stdio_free_stream@@YAXV__crt_stdio_stream@@@Z @ 0x14000ec90 =====

0x14000ec90  mov     [rsp+arg_0], rcx
0x14000ec95  mov     r11, rsp
0x14000ec98  xor     edx, edx
0x14000ec9a  mov     [rcx], rdx
0x14000ec9d  mov     rax, [r11+8]
0x14000eca1  mov     [rax+8], rdx
0x14000eca5  mov     rax, [r11+8]
0x14000eca9  mov     [rax+10h], edx
0x14000ecac  mov     rax, [r11+8]
0x14000ecb0  or      dword ptr [rax+18h], 0FFFFFFFFh
0x14000ecb4  mov     rax, [r11+8]
0x14000ecb8  mov     [rax+1Ch], edx
0x14000ecbb  mov     rax, [r11+8]
0x14000ecbf  mov     [rax+20h], edx
0x14000ecc2  mov     rax, [r11+8]
0x14000ecc6  mov     [rax+28h], rdx
0x14000ecca  mov     rax, [r11+8]
0x14000ecce  xchg    edx, [rax+14h]
0x14000ecd1  retn

// ===== ??$?RV_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_@@AEAV_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_@@V_lambda_237c231691f317818eb88cc1d5d642d6_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_@@AEAV_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_@@$$QEAV_lambda_237c231691f317818eb88cc1d5d642d6_@@@Z @ 0x14000ecd4 =====

0x14000ecd4  mov     [rsp+arg_0], rbx
0x14000ecd9  mov     [rsp+arg_18], r9
0x14000ecde  push    rdi
0x14000ecdf  sub     rsp, 20h
0x14000ece3  mov     rdi, r9
0x14000ece6  mov     rbx, r8
0x14000ece9  mov     ecx, [rdx]
0x14000eceb  call    sub_14000DD34
0x14000ecf0  nop
0x14000ecf1  mov     rax, [rbx]
0x14000ecf4  movsxd  rcx, dword ptr [rax]
0x14000ecf7  mov     rdx, rcx
0x14000ecfa  mov     rax, rcx
0x14000ecfd  sar     rax, 6
0x14000ed01  lea     r8, qword_1400217F0
0x14000ed08  and     edx, 3Fh
0x14000ed0b  shl     rdx, 6
0x14000ed0f  mov     rax, [r8+rax*8]
0x14000ed13  test    byte ptr [rax+rdx+38h], 1
0x14000ed18  jz      short loc_14000ED23
0x14000ed1a  call    _close_nolock
0x14000ed1f  mov     ebx, eax
0x14000ed21  jmp     short loc_14000ED31
0x14000ed23  call    _errno
0x14000ed28  mov     dword ptr [rax], 9
0x14000ed2e  or      ebx, 0FFFFFFFFh
0x14000ed31  mov     ecx, [rdi]
0x14000ed33  call    sub_14000DD58
0x14000ed38  mov     eax, ebx
0x14000ed3a  mov     rbx, [rsp+28h+arg_0]
0x14000ed3f  add     rsp, 20h
0x14000ed43  pop     rdi
0x14000ed44  retn
0x140013a86  push    rbp
0x140013a88  sub     rsp, 20h
0x140013a8c  mov     rbp, rdx
0x140013a8f  mov     rax, [rbp+48h]
0x140013a93  mov     ecx, [rax]
0x140013a95  add     rsp, 20h
0x140013a99  pop     rbp
0x140013a9a  jmp     sub_14000DD58

// ===== sub_14000ED48 @ 0x14000ed48 =====

0x14000ed48  mov     [rsp+arg_0], ecx
0x14000ed4c  sub     rsp, 38h
0x14000ed50  movsxd  rdx, ecx
0x14000ed53  cmp     edx, 0FFFFFFFEh
0x14000ed56  jnz     short loc_14000ED6D
0x14000ed58  call    __doserrno
0x14000ed5d  and     dword ptr [rax], 0
0x14000ed60  call    _errno
0x14000ed65  mov     dword ptr [rax], 9
0x14000ed6b  jmp     short loc_14000EDE1
0x14000ed6d  test    ecx, ecx
0x14000ed6f  js      short loc_14000EDC9
0x14000ed71  cmp     edx, cs:dword_140021BF0
0x14000ed77  jnb     short loc_14000EDC9
0x14000ed79  mov     rcx, rdx
0x14000ed7c  lea     r8, qword_1400217F0
0x14000ed83  and     ecx, 3Fh
0x14000ed86  mov     rax, rdx
0x14000ed89  sar     rax, 6
0x14000ed8d  shl     rcx, 6
0x14000ed91  mov     rax, [r8+rax*8]
0x14000ed95  test    byte ptr [rax+rcx+38h], 1
0x14000ed9a  jz      short loc_14000EDC9
0x14000ed9c  lea     rax, [rsp+38h+arg_0]
0x14000eda1  mov     [rsp+38h+arg_10], edx
0x14000eda5  mov     [rsp+38h+arg_18], edx
0x14000eda9  lea     r9, [rsp+38h+arg_10]
0x14000edae  lea     rdx, [rsp+38h+arg_18]
0x14000edb3  mov     [rsp+38h+var_18], rax
0x14000edb8  lea     r8, [rsp+38h+var_18]
0x14000edbd  lea     rcx, [rsp+38h+arg_8]
0x14000edc2  call    ??$?RV_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_@@AEAV_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_@@V_lambda_237c231691f317818eb88cc1d5d642d6_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_@@AEAV_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_@@$$QEAV_lambda_237c231691f317818eb88cc1d5d642d6_@@@Z; __crt_seh_guarded_call<int>::operator()<_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_,_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_ &,_lambda_237c231691f317818eb88cc1d5d642d6_>(_lambda_bfedae4ebbf01fab1bb6dcc6a9e276e0_ &&,_lambda_2fe9b910cf3cbf4a0ab98a02ba45b3ec_ &,_lambda_237c231691f317818eb88cc1d5d642d6_ &&)
0x14000edc7  jmp     short loc_14000EDE4
0x14000edc9  call    __doserrno
0x14000edce  and     dword ptr [rax], 0
0x14000edd1  call    _errno
0x14000edd6  mov     dword ptr [rax], 9
0x14000eddc  call    _invalid_parameter_noinfo
0x14000ede1  or      eax, 0FFFFFFFFh
0x14000ede4  add     rsp, 38h
0x14000ede8  retn

// ===== _close_nolock @ 0x14000edec =====

0x14000edec  mov     [rsp+arg_0], rbx
0x14000edf1  push    rdi
0x14000edf2  sub     rsp, 20h
0x14000edf6  movsxd  rdi, ecx
0x14000edf9  mov     ecx, edi; FileHandle
0x14000edfb  call    _get_osfhandle
0x14000ee00  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x14000ee04  jnz     short loc_14000EE0A
0x14000ee06  xor     ebx, ebx
0x14000ee08  jmp     short loc_14000EE61
0x14000ee0a  mov     rax, cs:qword_1400217F0
0x14000ee11  mov     ecx, 2; FileHandle
0x14000ee16  cmp     edi, 1
0x14000ee19  jnz     short loc_14000EE24
0x14000ee1b  test    [rax+0B8h], dil
0x14000ee22  jnz     short loc_14000EE2E
0x14000ee24  cmp     edi, ecx
0x14000ee26  jnz     short loc_14000EE45
0x14000ee28  test    byte ptr [rax+78h], 1
0x14000ee2c  jz      short loc_14000EE45
0x14000ee2e  call    _get_osfhandle
0x14000ee33  mov     ecx, 1; FileHandle
0x14000ee38  mov     rbx, rax
0x14000ee3b  call    _get_osfhandle
0x14000ee40  cmp     rax, rbx
0x14000ee43  jz      short loc_14000EE06
0x14000ee45  mov     ecx, edi; FileHandle
0x14000ee47  call    _get_osfhandle
0x14000ee4c  mov     rcx, rax; hObject
0x14000ee4f  call    cs:CloseHandle; KERNEL32
0x14000ee55  test    eax, eax
0x14000ee57  jnz     short loc_14000EE06
0x14000ee59  call    cs:GetLastError; KERNEL32
0x14000ee5f  mov     ebx, eax
0x14000ee61  mov     ecx, edi
0x14000ee63  call    _free_osfhnd
0x14000ee68  mov     rdx, rdi
0x14000ee6b  lea     r8, qword_1400217F0
0x14000ee72  and     edx, 3Fh
0x14000ee75  mov     rcx, rdi
0x14000ee78  sar     rcx, 6
0x14000ee7c  shl     rdx, 6
0x14000ee80  mov     rcx, [r8+rcx*8]
0x14000ee84  mov     byte ptr [rcx+rdx+38h], 0
0x14000ee89  test    ebx, ebx
0x14000ee8b  jz      short loc_14000EE99
0x14000ee8d  mov     ecx, ebx
0x14000ee8f  call    __acrt_errno_map_os_error
0x14000ee94  or      eax, 0FFFFFFFFh
0x14000ee97  jmp     short loc_14000EE9B
0x14000ee99  xor     eax, eax
0x14000ee9b  mov     rbx, [rsp+28h+arg_0]
0x14000eea0  add     rsp, 20h
0x14000eea4  pop     rdi
0x14000eea5  retn

// ===== __acrt_stdio_free_buffer_nolock @ 0x14000eea8 =====

0x14000eea8  push    rbx
0x14000eeaa  sub     rsp, 20h
0x14000eeae  mov     rbx, rcx
0x14000eeb1  mov     eax, [rcx+14h]
0x14000eeb4  shr     eax, 0Dh
0x14000eeb7  test    al, 1
0x14000eeb9  jz      short loc_14000EEE2
0x14000eebb  mov     eax, [rcx+14h]
0x14000eebe  shr     eax, 6
0x14000eec1  test    al, 1
0x14000eec3  jz      short loc_14000EEE2
0x14000eec5  mov     rcx, [rcx+8]; Block
0x14000eec9  call    _free_base
0x14000eece  lock and dword ptr [rbx+14h], 0FFFFFEBFh
0x14000eed6  xor     eax, eax
0x14000eed8  mov     [rbx+8], rax
0x14000eedc  mov     [rbx], rax
0x14000eedf  mov     [rbx+10h], eax
0x14000eee2  add     rsp, 20h
0x14000eee6  pop     rbx
0x14000eee7  retn

// ===== __acrt_stdio_flush_nolock @ 0x14000eee8 =====

0x14000eee8  mov     [rsp+arg_0], rbx
0x14000eeed  mov     [rsp+arg_8], rsi
0x14000eef2  push    rdi
0x14000eef3  sub     rsp, 20h
0x14000eef7  mov     rbx, rcx
0x14000eefa  mov     eax, [rcx+14h]
0x14000eefd  and     al, 3
0x14000eeff  cmp     al, 2
0x14000ef01  jnz     short loc_14000EF4D
0x14000ef03  mov     eax, [rcx+14h]
0x14000ef06  test    al, 0C0h
0x14000ef08  jz      short loc_14000EF4D
0x14000ef0a  mov     edi, [rcx]
0x14000ef0c  sub     edi, [rcx+8]
0x14000ef0f  and     dword ptr [rcx+10h], 0
0x14000ef13  mov     rsi, [rcx+8]
0x14000ef17  mov     [rcx], rsi
0x14000ef1a  test    edi, edi
0x14000ef1c  jle     short loc_14000EF4D
0x14000ef1e  call    _fileno
0x14000ef23  mov     ecx, eax; FileHandle
0x14000ef25  mov     r8d, edi; MaxCharCount
0x14000ef28  mov     rdx, rsi; Buf
0x14000ef2b  call    _write
0x14000ef30  cmp     edi, eax
0x14000ef32  jz      short loc_14000EF3E
0x14000ef34  lock or dword ptr [rbx+14h], 10h
0x14000ef39  or      eax, 0FFFFFFFFh
0x14000ef3c  jmp     short loc_14000EF4F
0x14000ef3e  mov     eax, [rbx+14h]
0x14000ef41  shr     eax, 2
0x14000ef44  test    al, 1
0x14000ef46  jz      short loc_14000EF4D
0x14000ef48  lock and dword ptr [rbx+14h], 0FFFFFFFDh
0x14000ef4d  xor     eax, eax
0x14000ef4f  mov     rbx, [rsp+28h+arg_0]
0x14000ef54  mov     rsi, [rsp+28h+arg_8]
0x14000ef59  add     rsp, 20h
0x14000ef5d  pop     rdi
0x14000ef5e  retn

// ===== _fflush_nolock @ 0x14000ef60 =====

0x14000ef60  push    rbx
0x14000ef62  sub     rsp, 20h
0x14000ef66  mov     rbx, rcx
0x14000ef69  test    rcx, rcx
0x14000ef6c  jnz     short loc_14000EF78
0x14000ef6e  add     rsp, 20h
0x14000ef72  pop     rbx
0x14000ef73  jmp     common_flush_all
0x14000ef78  call    __acrt_stdio_flush_nolock
0x14000ef7d  test    eax, eax
0x14000ef7f  jz      short loc_14000EF86
0x14000ef81  or      eax, 0FFFFFFFFh
0x14000ef84  jmp     short loc_14000EFA5
0x14000ef86  mov     eax, [rbx+14h]
0x14000ef89  shr     eax, 0Bh
0x14000ef8c  test    al, 1
0x14000ef8e  jz      short loc_14000EFA3
0x14000ef90  mov     rcx, rbx; Stream
0x14000ef93  call    _fileno
0x14000ef98  mov     ecx, eax; FileHandle
0x14000ef9a  call    _commit
0x14000ef9f  test    eax, eax
0x14000efa1  jnz     short loc_14000EF81
0x14000efa3  xor     eax, eax
0x14000efa5  add     rsp, 20h
0x14000efa9  pop     rbx
0x14000efaa  retn

// ===== _flushall @ 0x14000efac =====

0x14000efac  mov     ecx, 1
0x14000efb1  jmp     common_flush_all

// ===== common_flush_all @ 0x14000efb8 =====

0x14000efb8  mov     rax, rsp
0x14000efbb  mov     [rax+8], rbx
0x14000efbf  mov     [rax+18h], rsi
0x14000efc3  push    rdi
0x14000efc4  push    r14
0x14000efc6  push    r15
0x14000efc8  sub     rsp, 40h
0x14000efcc  mov     esi, ecx
0x14000efce  and     dword ptr [rax-34h], 0
0x14000efd2  and     dword ptr [rax-38h], 0
0x14000efd6  mov     ecx, 8
0x14000efdb  call    sub_14000D540
0x14000efe0  nop
0x14000efe1  mov     rdi, cs:qword_1400217D0
0x14000efe8  movsxd  rax, cs:dword_1400217C8
0x14000efef  lea     r14, [rdi+rax*8]
0x14000eff3  or      r15d, 0FFFFFFFFh
0x14000eff7  mov     [rsp+58h+var_30], rdi
0x14000effc  cmp     rdi, r14
0x14000efff  jz      short loc_14000F072
0x14000f001  mov     rbx, [rdi]
0x14000f004  mov     [rsp+58h+arg_8], rbx
0x14000f009  mov     [rsp+58h+var_28], rbx
0x14000f00e  test    rbx, rbx
0x14000f011  jnz     short loc_14000F015
0x14000f013  jmp     short loc_14000F06C
0x14000f015  mov     rcx, rbx
0x14000f018  call    sub_14000C0C8
0x14000f01d  nop
0x14000f01e  mov     eax, [rbx+14h]
0x14000f021  shr     eax, 0Dh
0x14000f024  test    al, 1
0x14000f026  jz      short loc_14000F064
0x14000f028  cmp     esi, 1
0x14000f02b  jnz     short loc_14000F040
0x14000f02d  mov     rcx, rbx; Stream
0x14000f030  call    _fflush_nolock
0x14000f035  cmp     eax, r15d
0x14000f038  jz      short loc_14000F064
0x14000f03a  inc     [rsp+58h+var_34]
0x14000f03e  jmp     short loc_14000F064
0x14000f040  test    esi, esi
0x14000f042  jnz     short loc_14000F064
0x14000f044  mov     eax, [rbx+14h]
0x14000f047  shr     eax, 1
0x14000f049  test    al, 1
0x14000f04b  jz      short loc_14000F064
0x14000f04d  mov     rcx, rbx; Stream
0x14000f050  call    _fflush_nolock
0x14000f055  mov     edx, [rsp+58h+var_38]
0x14000f059  cmp     eax, r15d
0x14000f05c  cmovz   edx, r15d
0x14000f060  mov     [rsp+58h+var_38], edx
0x14000f064  mov     rcx, rbx
0x14000f067  call    sub_14000C0D4
0x14000f06c  add     rdi, 8
0x14000f070  jmp     short loc_14000EFF7
0x14000f072  mov     ecx, 8
0x14000f077  call    sub_14000D594
0x14000f07c  mov     eax, [rsp+58h+var_38]
0x14000f080  cmp     esi, 1
0x14000f083  cmovz   eax, [rsp+58h+var_34]
0x14000f088  mov     rbx, [rsp+58h+arg_0]
0x14000f08d  mov     rsi, [rsp+58h+arg_10]
0x14000f092  add     rsp, 40h
0x14000f096  pop     r15
0x14000f098  pop     r14
0x14000f09a  pop     rdi
0x14000f09b  retn
0x140013aa0  push    rbp
0x140013aa2  sub     rsp, 20h
0x140013aa6  mov     rbp, rdx
0x140013aa9  mov     rcx, [rbp+68h]
0x140013aad  call    sub_14000C0D4
0x140013ab2  nop
0x140013ab3  add     rsp, 20h
0x140013ab7  pop     rbp
0x140013ab8  retn
0x140013aba  push    rbp
0x140013abc  sub     rsp, 20h
0x140013ac0  mov     rbp, rdx
0x140013ac3  mov     ecx, 8
0x140013ac8  add     rsp, 20h
0x140013acc  pop     rbp
0x140013acd  jmp     sub_14000D594

// ===== ??$common_lseek_nolock@_J@@YA_JH_JH@Z @ 0x14000f09c =====

0x14000f09c  mov     [rsp+arg_0], rbx
0x14000f0a1  mov     [rsp+arg_8], rsi
0x14000f0a6  push    rdi
0x14000f0a7  sub     rsp, 20h
0x14000f0ab  movsxd  rbx, ecx
0x14000f0ae  mov     edi, r8d
0x14000f0b1  mov     ecx, ebx; FileHandle
0x14000f0b3  mov     rsi, rdx
0x14000f0b6  call    _get_osfhandle
0x14000f0bb  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x14000f0bf  jnz     short loc_14000F0D2
0x14000f0c1  call    _errno
0x14000f0c6  mov     dword ptr [rax], 9
0x14000f0cc  or      rax, 0FFFFFFFFFFFFFFFFh
0x14000f0d0  jmp     short loc_14000F125
0x14000f0d2  mov     r9d, edi; dwMoveMethod
0x14000f0d5  lea     r8, [rsp+28h+NewFilePointer]; lpNewFilePointer
0x14000f0da  mov     rdx, rsi; liDistanceToMove
0x14000f0dd  mov     rcx, rax; hFile
0x14000f0e0  call    cs:SetFilePointerEx; KERNEL32
0x14000f0e6  test    eax, eax
0x14000f0e8  jnz     short loc_14000F0F9
0x14000f0ea  call    cs:GetLastError; KERNEL32
0x14000f0f0  mov     ecx, eax
0x14000f0f2  call    __acrt_errno_map_os_error
0x14000f0f7  jmp     short loc_14000F0CC
0x14000f0f9  mov     rax, qword ptr [rsp+28h+NewFilePointer]
0x14000f0fe  cmp     rax, 0FFFFFFFFFFFFFFFFh
0x14000f102  jz      short loc_14000F0CC
0x14000f104  mov     rdx, rbx
0x14000f107  lea     r8, qword_1400217F0
0x14000f10e  and     edx, 3Fh
0x14000f111  mov     rcx, rbx
0x14000f114  sar     rcx, 6
0x14000f118  shl     rdx, 6
0x14000f11c  mov     rcx, [r8+rcx*8]
0x14000f120  and     byte ptr [rcx+rdx+38h], 0FDh
0x14000f125  mov     rbx, [rsp+28h+arg_0]
0x14000f12a  mov     rsi, [rsp+28h+arg_8]
0x14000f12f  add     rsp, 20h
0x14000f133  pop     rdi
0x14000f134  retn

// ===== j_??$common_lseek_nolock@_J@@YA_JH_JH@Z @ 0x14000f138 =====

0x14000f138  jmp     ??$common_lseek_nolock@_J@@YA_JH_JH@Z

// ===== iswctype @ 0x14000f140 =====

0x14000f140  mov     [rsp+arg_8], rbx
0x14000f145  push    rdi
0x14000f146  sub     rsp, 20h
0x14000f14a  mov     eax, 0FFFFh
0x14000f14f  movzx   ebx, dx
0x14000f152  cmp     cx, ax
0x14000f155  jnz     short loc_14000F15B
0x14000f157  xor     eax, eax
0x14000f159  jmp     short loc_14000F1A5
0x14000f15b  mov     eax, 100h
0x14000f160  cmp     cx, ax
0x14000f163  jnb     short loc_14000F175
0x14000f165  mov     rax, cs:off_140020A80
0x14000f16c  movzx   ecx, cx
0x14000f16f  movzx   eax, word ptr [rax+rcx*2]
0x14000f173  jmp     short loc_14000F1A0
0x14000f175  xor     edi, edi
0x14000f177  mov     [rsp+28h+SrcStr], cx
0x14000f17c  lea     r9, [rsp+28h+CharType]; lpCharType
0x14000f181  mov     [rsp+28h+CharType], di
0x14000f186  lea     rdx, [rsp+28h+SrcStr]; lpSrcStr
0x14000f18b  lea     ecx, [rdi+1]; dwInfoType
0x14000f18e  mov     r8d, ecx; cchSrc
0x14000f191  call    cs:GetStringTypeW; KERNEL32
0x14000f197  test    eax, eax
0x14000f199  jz      short loc_14000F157
0x14000f19b  movzx   eax, [rsp+28h+CharType]
0x14000f1a0  movzx   ecx, bx
0x14000f1a3  and     eax, ecx
0x14000f1a5  mov     rbx, [rsp+28h+arg_8]
0x14000f1aa  add     rsp, 20h
0x14000f1ae  pop     rdi
0x14000f1af  retn

// ===== _isctype_l @ 0x14000f1b0 =====

0x14000f1b0  mov     [rsp-8+arg_8], rsi
0x14000f1b5  mov     [rsp-8+arg_10], rdi
0x14000f1ba  mov     [rsp-8+arg_18], r14
0x14000f1bf  push    rbp
0x14000f1c0  mov     rbp, rsp
0x14000f1c3  sub     rsp, 80h
0x14000f1ca  mov     rax, cs:__security_cookie
0x14000f1d1  xor     rax, rsp
0x14000f1d4  mov     [rbp+var_10], rax
0x14000f1d8  mov     r14d, edx
0x14000f1db  movsxd  rdi, ecx
0x14000f1de  mov     rdx, r8; struct __crt_locale_pointers *
0x14000f1e1  lea     rcx, [rbp+var_38]; this
0x14000f1e5  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000f1ea  lea     eax, [rdi+1]
0x14000f1ed  cmp     eax, 100h
0x14000f1f2  ja      short loc_14000F204
0x14000f1f4  mov     rax, [rbp+Locale.locinfo]
0x14000f1f8  mov     rcx, [rax]
0x14000f1fb  movzx   eax, word ptr [rcx+rdi*2]
0x14000f1ff  jmp     loc_14000F286
0x14000f204  mov     esi, edi
0x14000f206  lea     rdx, [rbp+Locale]; Locale
0x14000f20a  sar     esi, 8
0x14000f20d  movzx   ecx, sil; C
0x14000f211  call    _isleadbyte_l
0x14000f216  mov     edx, 1; dwInfoType
0x14000f21b  test    eax, eax
0x14000f21d  jz      short loc_14000F231
0x14000f21f  mov     [rbp+MultiByteStr], sil
0x14000f223  lea     r9d, [rdx+1]
0x14000f227  mov     [rbp+var_3F], dil
0x14000f22b  mov     [rbp+var_3E], 0
0x14000f22f  jmp     short loc_14000F23C
0x14000f231  mov     [rbp+MultiByteStr], dil
0x14000f235  mov     r9d, edx; cbMultiByte
0x14000f238  mov     [rbp+var_3F], 0
0x14000f23c  xor     eax, eax
0x14000f23e  mov     [rsp+80h+var_50], edx; int
0x14000f242  mov     dword ptr [rbp+CharType], eax
0x14000f245  lea     r8, [rbp+MultiByteStr]; lpMultiByteStr
0x14000f249  mov     [rbp+var_14], ax
0x14000f24d  mov     rax, [rbp+Locale.locinfo]
0x14000f251  mov     ecx, [rax+0Ch]
0x14000f254  lea     rax, [rbp+CharType]
0x14000f258  mov     [rsp+80h+CodePage], ecx; CodePage
0x14000f25c  lea     rcx, [rbp+Locale]; struct __crt_locale_pointers *
0x14000f260  mov     [rsp+80h+lpCharType], rax; lpCharType
0x14000f265  call    __acrt_GetStringTypeA
0x14000f26a  test    eax, eax
0x14000f26c  jnz     short loc_14000F282
0x14000f26e  cmp     [rbp+var_20], al
0x14000f271  jz      short loc_14000F27E
0x14000f273  mov     rax, [rbp+var_38]
0x14000f277  and     dword ptr [rax+3A8h], 0FFFFFFFDh
0x14000f27e  xor     eax, eax
0x14000f280  jmp     short loc_14000F29A
0x14000f282  movzx   eax, [rbp+CharType]
0x14000f286  and     eax, r14d
0x14000f289  cmp     [rbp+var_20], 0
0x14000f28d  jz      short loc_14000F29A
0x14000f28f  mov     rcx, [rbp+var_38]
0x14000f293  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x14000f29a  mov     rcx, [rbp+var_10]
0x14000f29e  xor     rcx, rsp; StackCookie
0x14000f2a1  call    __security_check_cookie
0x14000f2a6  lea     r11, [rsp+80h+var_s0]
0x14000f2ae  mov     rsi, [r11+18h]
0x14000f2b2  mov     rdi, [r11+20h]
0x14000f2b6  mov     r14, [r11+28h]
0x14000f2ba  mov     rsp, r11
0x14000f2bd  pop     rbp
0x14000f2be  retn

// ===== _isleadbyte_l @ 0x14000f2c0 =====

0x14000f2c0  push    rbx
0x14000f2c2  sub     rsp, 40h
0x14000f2c6  mov     ebx, ecx
0x14000f2c8  lea     rcx, [rsp+48h+var_28]; this
0x14000f2cd  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000f2d2  mov     rax, [rsp+48h+var_20]
0x14000f2d7  movzx   edx, bl
0x14000f2da  mov     rcx, [rax]
0x14000f2dd  movzx   eax, word ptr [rcx+rdx*2]
0x14000f2e1  and     eax, 8000h
0x14000f2e6  cmp     [rsp+48h+var_10], 0
0x14000f2eb  jz      short loc_14000F2F9
0x14000f2ed  mov     rcx, [rsp+48h+var_28]
0x14000f2f2  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x14000f2f9  add     rsp, 40h
0x14000f2fd  pop     rbx
0x14000f2fe  retn

// ===== ?__acrt_LCMapStringA_stat@@YAHPEAU__crt_locale_pointers@@PEB_WKPEBDHPEADHHH@Z @ 0x14000f300 =====

0x14000f300  push    rbp
0x14000f302  push    r12
0x14000f304  push    r13
0x14000f306  push    r14
0x14000f308  push    r15
0x14000f30a  sub     rsp, 60h
0x14000f30e  lea     rbp, [rsp+50h]
0x14000f313  mov     [rbp+30h+arg_0], rbx
0x14000f317  mov     [rbp+30h+arg_8], rsi
0x14000f31b  mov     [rbp+30h+arg_10], rdi
0x14000f31f  mov     rax, cs:__security_cookie
0x14000f326  xor     rax, rbp
0x14000f329  mov     [rbp+30h+var_28], rax
0x14000f32d  movsxd  rbx, [rbp+30h+arg_20]
0x14000f331  mov     r15, r9
0x14000f334  mov     [rbp+30h+var_30], rdx
0x14000f338  mov     r13d, r8d
0x14000f33b  mov     rdi, rcx
0x14000f33e  test    ebx, ebx
0x14000f340  jle     short loc_14000F356
0x14000f342  mov     rdx, rbx; Count
0x14000f345  mov     rcx, r9; String
0x14000f348  call    __strncnt
0x14000f34d  cmp     eax, ebx
0x14000f34f  lea     ebx, [rax+1]
0x14000f352  jl      short loc_14000F356
0x14000f354  mov     ebx, eax
0x14000f356  mov     r14d, [rbp+30h+CodePage]
0x14000f35a  test    r14d, r14d
0x14000f35d  jnz     short loc_14000F366
0x14000f35f  mov     rax, [rdi]
0x14000f362  mov     r14d, [rax+0Ch]
0x14000f366  neg     [rbp+30h+arg_40]
0x14000f36c  mov     r9d, ebx; cbMultiByte
0x14000f36f  mov     r8, r15; lpMultiByteStr
0x14000f372  mov     ecx, r14d; CodePage
0x14000f375  sbb     edx, edx
0x14000f377  and     [rsp+80h+cchWideChar], 0
0x14000f37c  and     [rsp+80h+lpWideCharStr], 0
0x14000f382  and     edx, 8
0x14000f385  inc     edx; dwFlags
0x14000f387  call    cs:MultiByteToWideChar; KERNEL32
0x14000f38d  movsxd  r12, eax
0x14000f390  test    eax, eax
0x14000f392  jz      loc_14000F613
0x14000f398  mov     rdx, r12
0x14000f39b  mov     r8, 0FFFFFFFFFFFFFF0h
0x14000f3a5  add     rdx, rdx
0x14000f3a8  lea     rcx, [rdx+10h]
0x14000f3ac  cmp     rdx, rcx
0x14000f3af  sbb     rax, rax
0x14000f3b2  test    rcx, rax
0x14000f3b5  jz      short loc_14000F429
0x14000f3b7  lea     rcx, [rdx+10h]
0x14000f3bb  cmp     rdx, rcx
0x14000f3be  sbb     rax, rax
0x14000f3c1  and     rax, rcx
0x14000f3c4  cmp     rax, 400h
0x14000f3ca  lea     rax, [rdx+10h]
0x14000f3ce  ja      short loc_14000F407
0x14000f3d0  cmp     rdx, rax
0x14000f3d3  sbb     rcx, rcx
0x14000f3d6  and     rcx, rax
0x14000f3d9  lea     rax, [rcx+0Fh]
0x14000f3dd  cmp     rax, rcx
0x14000f3e0  ja      short loc_14000F3E5
0x14000f3e2  mov     rax, r8
0x14000f3e5  and     rax, 0FFFFFFFFFFFFFFF0h
0x14000f3e9  call    _alloca_probe
0x14000f3ee  sub     rsp, rax
0x14000f3f1  lea     rsi, [rsp+80h+var_30]
0x14000f3f6  test    rsi, rsi
0x14000f3f9  jz      loc_14000F5F9
0x14000f3ff  mov     dword ptr [rsi], 0CCCCh
0x14000f405  jmp     short loc_14000F423
0x14000f407  cmp     rdx, rax
0x14000f40a  sbb     rcx, rcx
0x14000f40d  and     rcx, rax; Size
0x14000f410  call    _malloc_base
0x14000f415  mov     rsi, rax
0x14000f418  test    rax, rax
0x14000f41b  jz      short loc_14000F42B
0x14000f41d  mov     dword ptr [rax], 0DDDDh
0x14000f423  add     rsi, 10h
0x14000f427  jmp     short loc_14000F42B
0x14000f429  xor     esi, esi
0x14000f42b  test    rsi, rsi
0x14000f42e  jz      loc_14000F5F9
0x14000f434  mov     [rsp+80h+cchWideChar], r12d; cchWideChar
0x14000f439  mov     r9d, ebx; cbMultiByte
0x14000f43c  mov     r8, r15; lpMultiByteStr
0x14000f43f  mov     [rsp+80h+lpWideCharStr], rsi; lpWideCharStr
0x14000f444  mov     edx, 1; dwFlags
0x14000f449  mov     ecx, r14d; CodePage
0x14000f44c  call    cs:MultiByteToWideChar; KERNEL32
0x14000f452  test    eax, eax
0x14000f454  jz      loc_14000F5F9
0x14000f45a  and     [rsp+80h+var_40], 0
0x14000f460  mov     r9d, r12d
0x14000f463  and     [rsp+80h+var_48], 0
0x14000f469  mov     r8, rsi
0x14000f46c  and     [rsp+80h+var_50], 0
0x14000f472  mov     edx, r13d
0x14000f475  mov     r15, [rbp+30h+var_30]
0x14000f479  and     [rsp+80h+cchWideChar], 0
0x14000f47e  mov     rcx, r15
0x14000f481  and     [rsp+80h+lpWideCharStr], 0
0x14000f487  call    __acrt_LCMapStringEx
0x14000f48c  movsxd  rdi, eax
0x14000f48f  test    eax, eax
0x14000f491  jz      loc_14000F5F9
0x14000f497  mov     r8d, 400h
0x14000f49d  test    r8d, r13d
0x14000f4a0  jz      short loc_14000F4F4
0x14000f4a2  mov     eax, [rbp+30h+arg_30]
0x14000f4a5  test    eax, eax
0x14000f4a7  jz      loc_14000F5FB
0x14000f4ad  cmp     edi, eax
0x14000f4af  jg      loc_14000F5F9
0x14000f4b5  and     [rsp+80h+var_40], 0
0x14000f4bb  mov     r9d, r12d
0x14000f4be  and     [rsp+80h+var_48], 0
0x14000f4c4  mov     r8, rsi
0x14000f4c7  and     [rsp+80h+var_50], 0
0x14000f4cd  mov     edx, r13d
0x14000f4d0  mov     [rsp+80h+cchWideChar], eax
0x14000f4d4  mov     rcx, r15
0x14000f4d7  mov     rax, [rbp+30h+arg_28]
0x14000f4db  mov     [rsp+80h+lpWideCharStr], rax
0x14000f4e0  call    __acrt_LCMapStringEx
0x14000f4e5  mov     edi, eax
0x14000f4e7  test    eax, eax
0x14000f4e9  jnz     loc_14000F5FB
0x14000f4ef  jmp     loc_14000F5F9
0x14000f4f4  mov     rdx, rdi
0x14000f4f7  add     rdx, rdx
0x14000f4fa  lea     rcx, [rdx+10h]
0x14000f4fe  cmp     rdx, rcx
0x14000f501  sbb     rax, rax
0x14000f504  test    rcx, rax
0x14000f507  jz      short loc_14000F57F
0x14000f509  lea     rcx, [rdx+10h]
0x14000f50d  cmp     rdx, rcx
0x14000f510  sbb     rax, rax
0x14000f513  and     rax, rcx
0x14000f516  cmp     rax, r8
0x14000f519  lea     rax, [rdx+10h]
0x14000f51d  ja      short loc_14000F55D
0x14000f51f  cmp     rdx, rax
0x14000f522  sbb     rcx, rcx
0x14000f525  and     rcx, rax
0x14000f528  lea     rax, [rcx+0Fh]
0x14000f52c  cmp     rax, rcx
0x14000f52f  ja      short loc_14000F53B
0x14000f531  mov     rax, 0FFFFFFFFFFFFFF0h
0x14000f53b  and     rax, 0FFFFFFFFFFFFFFF0h
0x14000f53f  call    _alloca_probe
0x14000f544  sub     rsp, rax
0x14000f547  lea     rbx, [rsp+80h+var_30]
0x14000f54c  test    rbx, rbx
0x14000f54f  jz      loc_14000F5F9
0x14000f555  mov     dword ptr [rbx], 0CCCCh
0x14000f55b  jmp     short loc_14000F579
0x14000f55d  cmp     rdx, rax
0x14000f560  sbb     rcx, rcx
0x14000f563  and     rcx, rax; Size
0x14000f566  call    _malloc_base
0x14000f56b  mov     rbx, rax
0x14000f56e  test    rax, rax
0x14000f571  jz      short loc_14000F581
0x14000f573  mov     dword ptr [rax], 0DDDDh
0x14000f579  add     rbx, 10h
0x14000f57d  jmp     short loc_14000F581
0x14000f57f  xor     ebx, ebx
0x14000f581  test    rbx, rbx
0x14000f584  jz      short loc_14000F5F9
0x14000f586  and     [rsp+80h+var_40], 0
0x14000f58c  mov     r9d, r12d
0x14000f58f  and     [rsp+80h+var_48], 0
0x14000f595  mov     r8, rsi
0x14000f598  and     [rsp+80h+var_50], 0
0x14000f59e  mov     edx, r13d
0x14000f5a1  mov     [rsp+80h+cchWideChar], edi; cbMultiByte
0x14000f5a5  mov     rcx, r15
0x14000f5a8  mov     [rsp+80h+lpWideCharStr], rbx; lpMultiByteStr
0x14000f5ad  call    __acrt_LCMapStringEx
0x14000f5b2  test    eax, eax
0x14000f5b4  jz      short loc_14000F5E8
0x14000f5b6  and     [rsp+80h+var_48], 0
0x14000f5bc  xor     edx, edx; dwFlags
0x14000f5be  and     [rsp+80h+var_50], rdx
0x14000f5c3  mov     r9d, edi; cchWideChar
0x14000f5c6  mov     eax, [rbp+30h+arg_30]
0x14000f5c9  mov     r8, rbx; lpWideCharStr
0x14000f5cc  mov     ecx, r14d; CodePage
0x14000f5cf  test    eax, eax
0x14000f5d1  jnz     short loc_14000F639
0x14000f5d3  and     [rsp+80h+cchWideChar], edx
0x14000f5d7  and     [rsp+80h+lpWideCharStr], rdx
0x14000f5dc  call    cs:WideCharToMultiByte; KERNEL32
0x14000f5e2  mov     edi, eax
0x14000f5e4  test    eax, eax
0x14000f5e6  jnz     short loc_14000F648
0x14000f5e8  lea     rcx, [rbx-10h]; Block
0x14000f5ec  cmp     dword ptr [rcx], 0DDDDh
0x14000f5f2  jnz     short loc_14000F5F9
0x14000f5f4  call    _free_base
0x14000f5f9  xor     edi, edi
0x14000f5fb  test    rsi, rsi
0x14000f5fe  jz      short loc_14000F611
0x14000f600  lea     rcx, [rsi-10h]; Block
0x14000f604  cmp     dword ptr [rcx], 0DDDDh
0x14000f60a  jnz     short loc_14000F611
0x14000f60c  call    _free_base
0x14000f611  mov     eax, edi
0x14000f613  mov     rcx, [rbp+30h+var_28]
0x14000f617  xor     rcx, rbp; StackCookie
0x14000f61a  call    __security_check_cookie
0x14000f61f  mov     rbx, [rbp+30h+arg_0]
0x14000f623  mov     rsi, [rbp+30h+arg_8]
0x14000f627  mov     rdi, [rbp+30h+arg_10]
0x14000f62b  lea     rsp, [rbp+10h]
0x14000f62f  pop     r15
0x14000f631  pop     r14
0x14000f633  pop     r13
0x14000f635  pop     r12
0x14000f637  pop     rbp
0x14000f638  retn
0x14000f639  mov     [rsp+80h+cchWideChar], eax
0x14000f63d  mov     rax, [rbp+30h+arg_28]
0x14000f641  mov     [rsp+80h+lpWideCharStr], rax
0x14000f646  jmp     short loc_14000F5DC
0x14000f648  lea     rcx, [rbx-10h]; Block
0x14000f64c  cmp     dword ptr [rcx], 0DDDDh
0x14000f652  jnz     short loc_14000F5FB
0x14000f654  call    _free_base
0x14000f659  jmp     short loc_14000F5FB

// ===== __acrt_LCMapStringA @ 0x14000f65c =====

0x14000f65c  mov     [rsp+arg_0], rbx
0x14000f661  mov     [rsp+arg_8], rsi
0x14000f666  push    rdi
0x14000f667  sub     rsp, 70h
0x14000f66b  mov     rsi, rdx
0x14000f66e  mov     rbx, r9
0x14000f671  mov     rdx, rcx; struct __crt_locale_pointers *
0x14000f674  mov     edi, r8d
0x14000f677  lea     rcx, [rsp+78h+var_28]; this
0x14000f67c  call    ??0_LocaleUpdate@@QEAA@QEAU__crt_locale_pointers@@@Z
0x14000f681  mov     eax, [rsp+78h+arg_40]
0x14000f688  lea     rcx, [rsp+78h+var_20]; struct __crt_locale_pointers *
0x14000f68d  mov     [rsp+78h+var_38], eax; int
0x14000f691  mov     r9, rbx; char *
0x14000f694  mov     eax, [rsp+78h+arg_38]
0x14000f69b  mov     r8d, edi; unsigned int
0x14000f69e  mov     [rsp+78h+var_40], eax; int
0x14000f6a2  mov     rdx, rsi; wchar_t *
0x14000f6a5  mov     eax, [rsp+78h+arg_30]
0x14000f6ac  mov     [rsp+78h+var_48], eax; int
0x14000f6b0  mov     rax, [rsp+78h+arg_28]
0x14000f6b8  mov     [rsp+78h+var_50], rax; char *
0x14000f6bd  mov     eax, [rsp+78h+arg_20]
0x14000f6c4  mov     [rsp+78h+var_58], eax; int
0x14000f6c8  call    ?__acrt_LCMapStringA_stat@@YAHPEAU__crt_locale_pointers@@PEB_WKPEBDHPEADHHH@Z
0x14000f6cd  cmp     [rsp+78h+var_10], 0
0x14000f6d2  jz      short loc_14000F6E0
0x14000f6d4  mov     rcx, [rsp+78h+var_28]
0x14000f6d9  and     dword ptr [rcx+3A8h], 0FFFFFFFDh
0x14000f6e0  lea     r11, [rsp+78h+var_8]
0x14000f6e5  mov     rbx, [r11+10h]
0x14000f6e9  mov     rsi, [r11+18h]
0x14000f6ed  mov     rsp, r11
0x14000f6f0  pop     rdi
0x14000f6f1  retn

// ===== __acrt_fp_strflt_to_string @ 0x14000f6f4 =====

0x14000f6f4  push    rbx
0x14000f6f6  sub     rsp, 20h
0x14000f6fa  xor     ebx, ebx
0x14000f6fc  test    rcx, rcx
0x14000f6ff  jnz     short loc_14000F719
0x14000f701  call    _errno
0x14000f706  mov     ebx, 16h
0x14000f70b  mov     [rax], ebx
0x14000f70d  call    _invalid_parameter_noinfo
0x14000f712  mov     eax, ebx
0x14000f714  jmp     loc_14000F7AD
0x14000f719  test    rdx, rdx
0x14000f71c  jz      short loc_14000F701
0x14000f71e  test    r8d, r8d
0x14000f721  mov     [rcx], bl
0x14000f723  mov     eax, ebx
0x14000f725  cmovg   eax, r8d
0x14000f729  inc     eax
0x14000f72b  cdqe
0x14000f72d  cmp     rdx, rax
0x14000f730  ja      short loc_14000F73E
0x14000f732  call    _errno
0x14000f737  mov     ebx, 22h ; '"'
0x14000f73c  jmp     short loc_14000F70B
0x14000f73e  test    r9, r9
0x14000f741  jz      short loc_14000F701
0x14000f743  mov     rdx, [r9+8]
0x14000f747  lea     rax, [rcx+1]
0x14000f74b  mov     byte ptr [rcx], 30h ; '0'
0x14000f74e  jmp     short loc_14000F769
0x14000f750  mov     r10b, [rdx]
0x14000f753  test    r10b, r10b
0x14000f756  jz      short loc_14000F75D
0x14000f758  inc     rdx
0x14000f75b  jmp     short loc_14000F760
0x14000f75d  mov     r10b, 30h ; '0'
0x14000f760  mov     [rax], r10b
0x14000f763  inc     rax
0x14000f766  dec     r8d
0x14000f769  test    r8d, r8d
0x14000f76c  jg      short loc_14000F750
0x14000f76e  mov     [rax], bl
0x14000f770  js      short loc_14000F786
0x14000f772  cmp     byte ptr [rdx], 35h ; '5'
0x14000f775  jl      short loc_14000F786
0x14000f777  jmp     short loc_14000F77C
0x14000f779  mov     byte ptr [rax], 30h ; '0'
0x14000f77c  dec     rax
0x14000f77f  cmp     byte ptr [rax], 39h ; '9'
0x14000f782  jz      short loc_14000F779
0x14000f784  inc     byte ptr [rax]
0x14000f786  cmp     byte ptr [rcx], 31h ; '1'
0x14000f789  jnz     short loc_14000F791
0x14000f78b  inc     dword ptr [r9+4]
0x14000f78f  jmp     short loc_14000F7AB
0x14000f791  or      r8, 0FFFFFFFFFFFFFFFFh
0x14000f795  inc     r8
0x14000f798  cmp     [rcx+r8+1], bl
0x14000f79d  jnz     short loc_14000F795
0x14000f79f  inc     r8
0x14000f7a2  lea     rdx, [rcx+1]
0x14000f7a6  call    sub_1400067F0
0x14000f7ab  xor     eax, eax
0x14000f7ad  add     rsp, 20h
0x14000f7b1  pop     rbx
0x14000f7b2  retn

// ===== ?divide@__crt_strtox@@YA_KAEAUbig_integer@1@AEBU21@@Z @ 0x14000f7c0 =====

0x14000f7c0  mov     [rsp+arg_8], rdx
0x14000f7c5  push    rsi
0x14000f7c6  push    rdi
0x14000f7c7  sub     rsp, 248h
0x14000f7ce  mov     r9d, [rcx]
0x14000f7d1  mov     rdi, rdx
0x14000f7d4  mov     rsi, rcx
0x14000f7d7  test    r9d, r9d
0x14000f7da  jnz     short loc_14000F7E8
0x14000f7dc  xor     eax, eax
0x14000f7de  add     rsp, 248h
0x14000f7e5  pop     rdi
0x14000f7e6  pop     rsi
0x14000f7e7  retn
0x14000f7e8  mov     eax, [rdx]
0x14000f7ea  test    eax, eax
0x14000f7ec  jz      short loc_14000F7DC
0x14000f7ee  mov     [rsp+258h+var_18], rbx
0x14000f7f6  dec     r9d
0x14000f7f9  mov     [rsp+258h+var_20], rbp
0x14000f801  mov     [rsp+258h+var_28], r12
0x14000f809  mov     [rsp+258h+var_38], r14
0x14000f811  mov     [rsp+258h+var_40], r15
0x14000f819  sub     eax, 1
0x14000f81c  jnz     loc_14000F914
0x14000f822  mov     r15d, [rdx+4]
0x14000f826  xor     r14d, r14d
0x14000f829  cmp     r15d, 1
0x14000f82d  jnz     short loc_14000F857
0x14000f82f  mov     ebx, [rcx+4]
0x14000f832  lea     r8, [rsp+258h+Source]; Source
0x14000f837  add     rcx, 4; Destination
0x14000f83b  mov     [rsi], r14d
0x14000f83e  xor     r9d, r9d; SourceSize
0x14000f841  mov     [rsp+258h+var_218], r14d
0x14000f846  mov     edx, 1CCh; DestinationSize
0x14000f84b  call    memcpy_s
0x14000f850  mov     eax, ebx
0x14000f852  jmp     loc_14000FC5C
0x14000f857  test    r9d, r9d
0x14000f85a  jnz     short loc_14000F895
0x14000f85c  mov     ebx, [rcx+4]
0x14000f85f  lea     r8, [rsp+258h+Source]; Source
0x14000f864  mov     [rcx], r14d
0x14000f867  xor     r9d, r9d; SourceSize
0x14000f86a  add     rcx, 4; Destination
0x14000f86e  mov     [rsp+258h+var_218], r14d
0x14000f873  mov     edx, 1CCh; DestinationSize
0x14000f878  call    memcpy_s
0x14000f87d  xor     edx, edx
0x14000f87f  mov     eax, ebx
0x14000f881  div     r15d
0x14000f884  test    edx, edx
0x14000f886  mov     [rsi+4], edx
0x14000f889  setnz   r14b
0x14000f88d  mov     [rsi], r14d
0x14000f890  jmp     loc_14000FC5C
0x14000f895  mov     r12d, 0FFFFFFFFh
0x14000f89b  mov     rdi, r14
0x14000f89e  mov     rbp, r14
0x14000f8a1  cmp     r9d, r12d
0x14000f8a4  jz      short loc_14000F8D5
0x14000f8a6  mov     rcx, r15
0x14000f8a9  nop     dword ptr [rax+00000000h]
0x14000f8b0  mov     eax, [rsi+r9*4+4]
0x14000f8b5  xor     edx, edx
0x14000f8b7  shl     rbp, 20h
0x14000f8bb  add     r9d, r12d
0x14000f8be  or      rax, rbp
0x14000f8c1  shl     rdi, 20h
0x14000f8c5  div     rcx
0x14000f8c8  mov     eax, eax
0x14000f8ca  mov     rbp, rdx
0x14000f8cd  add     rdi, rax
0x14000f8d0  cmp     r9d, r12d
0x14000f8d3  jnz     short loc_14000F8B0
0x14000f8d5  xor     r9d, r9d; SourceSize
0x14000f8d8  mov     [rsp+258h+var_218], r14d
0x14000f8dd  lea     r8, [rsp+258h+Source]; Source
0x14000f8e2  mov     [rsi], r14d
0x14000f8e5  mov     edx, 1CCh; DestinationSize
0x14000f8ea  lea     rcx, [rsi+4]; Destination
0x14000f8ee  call    memcpy_s
0x14000f8f3  mov     rcx, rbp
0x14000f8f6  mov     [rsi+4], ebp
0x14000f8f9  shr     rcx, 20h
0x14000f8fd  mov     rax, rdi
0x14000f900  test    ecx, ecx
0x14000f902  mov     [rsi+8], ecx
0x14000f905  setnz   r14b
0x14000f909  inc     r14d
0x14000f90c  mov     [rsi], r14d
0x14000f90f  jmp     loc_14000FC5C
0x14000f914  cmp     eax, r9d
0x14000f917  jbe     short loc_14000F920
0x14000f919  xor     eax, eax
0x14000f91b  jmp     loc_14000FC5C
0x14000f920  mov     r8d, r9d
0x14000f923  movsxd  rdx, r9d
0x14000f926  sub     r8d, eax
0x14000f929  mov     [rsp+258h+var_30], r13
0x14000f931  movsxd  rbx, r8d
0x14000f934  lea     r13d, [rax+1]
0x14000f938  mov     r10d, r9d
0x14000f93b  cmp     rdx, rbx
0x14000f93e  jl      short loc_14000F98C
0x14000f940  add     rcx, 4
0x14000f944  lea     rax, ds:0[rbx*4]
0x14000f94c  mov     r11, rdi
0x14000f94f  sub     r11, rax
0x14000f952  sub     r11, rsi
0x14000f955  lea     rcx, [rcx+rdx*4]
0x14000f959  nop     dword ptr [rax+00000000h]
0x14000f960  mov     eax, [rcx]
0x14000f962  cmp     [r11+rcx], eax
0x14000f966  jnz     short loc_14000F979
0x14000f968  dec     r10d
0x14000f96b  dec     rdx
0x14000f96e  sub     rcx, 4
0x14000f972  cmp     rdx, rbx
0x14000f975  jge     short loc_14000F960
0x14000f977  jmp     short loc_14000F98C
0x14000f979  movsxd  rax, r10d
0x14000f97c  mov     rcx, rax
0x14000f97f  sub     rcx, rbx
0x14000f982  mov     eax, [rsi+rax*4+4]
0x14000f986  cmp     [rdi+rcx*4+4], eax
0x14000f98a  jnb     short loc_14000F98F
0x14000f98c  inc     r8d
0x14000f98f  test    r8d, r8d
0x14000f992  jnz     short loc_14000F99B
0x14000f994  xor     eax, eax
0x14000f996  jmp     loc_14000FC54
0x14000f99b  lea     eax, [r13-1]
0x14000f99f  mov     r11d, 20h ; ' '
0x14000f9a5  mov     r10d, [rdi+rax*4+4]
0x14000f9aa  lea     eax, [r13-2]
0x14000f9ae  mov     ebx, [rdi+rax*4+4]
0x14000f9b2  bsr     eax, r10d
0x14000f9b6  mov     [rsp+258h+arg_18], ebx
0x14000f9bd  jz      short loc_14000F9C8
0x14000f9bf  mov     edx, 1Fh
0x14000f9c4  sub     edx, eax
0x14000f9c6  jmp     short loc_14000F9CB
0x14000f9c8  mov     edx, r11d
0x14000f9cb  sub     r11d, edx
0x14000f9ce  mov     [rsp+258h+arg_10], edx
0x14000f9d5  mov     dword ptr [rsp+258h+var_238], r11d
0x14000f9da  test    edx, edx
0x14000f9dc  jz      short loc_14000FA1E
0x14000f9de  mov     eax, r10d
0x14000f9e1  mov     edx, ebx
0x14000f9e3  mov     ecx, r11d
0x14000f9e6  shr     edx, cl
0x14000f9e8  mov     ecx, [rsp+258h+arg_10]
0x14000f9ef  mov     r10d, edx
0x14000f9f2  shl     eax, cl
0x14000f9f4  mov     edx, ecx
0x14000f9f6  shl     ebx, cl
0x14000f9f8  or      r10d, eax
0x14000f9fb  mov     [rsp+258h+arg_18], ebx
0x14000fa02  cmp     r13d, 2
0x14000fa06  jbe     short loc_14000FA1E
0x14000fa08  lea     eax, [r13-3]
0x14000fa0c  mov     ecx, r11d
0x14000fa0f  mov     eax, [rdi+rax*4+4]
0x14000fa13  shr     eax, cl
0x14000fa15  or      ebx, eax
0x14000fa17  mov     [rsp+258h+arg_18], ebx
0x14000fa1e  xor     r14d, r14d
0x14000fa21  lea     ebx, [r8-1]
0x14000fa25  mov     [rsp+258h+arg_0], ebx
0x14000fa2c  mov     r15d, r14d
0x14000fa2f  test    ebx, ebx
0x14000fa31  js      loc_14000FC16
0x14000fa37  mov     eax, r11d
0x14000fa3a  lea     edi, [rbx+r13]
0x14000fa3e  mov     r11d, r10d
0x14000fa41  mov     r12d, 0FFFFFFFFh
0x14000fa47  mov     [rsp+258h+var_228], r11
0x14000fa4c  mov     [rsp+258h+var_220], rax
0x14000fa51  cmp     edi, r9d
0x14000fa54  ja      short loc_14000FA5C
0x14000fa56  mov     ebp, [rsi+rdi*4+4]
0x14000fa5a  jmp     short loc_14000FA5F
0x14000fa5c  mov     ebp, r14d
0x14000fa5f  lea     eax, [rdi-1]
0x14000fa62  mov     ecx, [rsi+rax*4+4]
0x14000fa66  lea     eax, [rdi-2]
0x14000fa69  mov     r10d, [rsi+rax*4+4]
0x14000fa6e  mov     [rsp+258h+var_230], rcx
0x14000fa73  mov     dword ptr [rsp+258h+var_230+4], ebp
0x14000fa77  test    edx, edx
0x14000fa79  jz      short loc_14000FAAD
0x14000fa7b  mov     rcx, [rsp+258h+var_220]
0x14000fa80  mov     r8d, r10d
0x14000fa83  mov     rax, [rsp+258h+var_230]
0x14000fa88  shr     r8, cl
0x14000fa8b  mov     ecx, edx
0x14000fa8d  shl     rax, cl
0x14000fa90  or      r8, rax
0x14000fa93  shl     r10d, cl
0x14000fa96  cmp     edi, 3
0x14000fa99  jb      short loc_14000FAB2
0x14000fa9b  mov     ecx, dword ptr [rsp+258h+var_238]
0x14000fa9f  lea     eax, [rdi-3]
0x14000faa2  mov     eax, [rsi+rax*4+4]
0x14000faa6  shr     eax, cl
0x14000faa8  or      r10d, eax
0x14000faab  jmp     short loc_14000FAB2
0x14000faad  mov     r8, [rsp+258h+var_230]
0x14000fab2  xor     edx, edx
0x14000fab4  mov     rax, r8
0x14000fab7  div     r11
0x14000faba  mov     ecx, edx
0x14000fabc  mov     r8, rax
0x14000fabf  cmp     rax, r12
0x14000fac2  jbe     short loc_14000FADB
0x14000fac4  mov     rax, 0FFFFFFFF00000001h
0x14000face  add     rax, r8
0x14000fad1  mov     r8, r12
0x14000fad4  imul    rax, r11
0x14000fad8  add     rcx, rax
0x14000fadb  cmp     rcx, r12
0x14000fade  ja      short loc_14000FB24
0x14000fae0  mov     rbx, [rsp+258h+var_228]
0x14000fae5  mov     r11d, r10d
0x14000fae8  mov     r10d, [rsp+258h+arg_18]
0x14000faf0  mov     edx, r10d
0x14000faf3  imul    rdx, r8
0x14000faf7  neg     r10
0x14000fafa  nop     word ptr [rax+rax+00h]
0x14000fb00  mov     rax, rcx
0x14000fb03  shl     rax, 20h
0x14000fb07  or      rax, r11
0x14000fb0a  cmp     rdx, rax
0x14000fb0d  jbe     short loc_14000FB1D
0x14000fb0f  dec     r8
0x14000fb12  add     rdx, r10
0x14000fb15  add     rcx, rbx
0x14000fb18  cmp     rcx, r12
0x14000fb1b  jbe     short loc_14000FB00
0x14000fb1d  mov     ebx, [rsp+258h+arg_0]
0x14000fb24  test    r8, r8
0x14000fb27  jz      loc_14000FBED
0x14000fb2d  mov     rcx, r14
0x14000fb30  test    r13d, r13d
0x14000fb33  jz      short loc_14000FB8D
0x14000fb35  mov     r9, [rsp+258h+arg_8]
0x14000fb3d  mov     edx, ebx
0x14000fb3f  add     r9, 4
0x14000fb43  mov     ebx, r13d
0x14000fb46  nop     word ptr [rax+rax+00000000h]
0x14000fb50  mov     eax, [r9]
0x14000fb53  imul    rax, r8
0x14000fb57  add     rcx, rax
0x14000fb5a  mov     eax, edx
0x14000fb5c  mov     r10d, ecx
0x14000fb5f  shr     rcx, 20h
0x14000fb63  lea     r11, [rsi+rax*4]
0x14000fb67  mov     eax, [rsi+rax*4+4]
0x14000fb6b  cmp     eax, r10d
0x14000fb6e  jnb     short loc_14000FB73
0x14000fb70  inc     rcx
0x14000fb73  sub     eax, r10d
0x14000fb76  inc     edx
0x14000fb78  add     r9, 4
0x14000fb7c  mov     [r11+4], eax
0x14000fb80  sub     rbx, 1
0x14000fb84  jnz     short loc_14000FB50
0x14000fb86  mov     ebx, [rsp+258h+arg_0]
0x14000fb8d  mov     eax, ebp
0x14000fb8f  cmp     rax, rcx
0x14000fb92  jnb     short loc_14000FBE2
0x14000fb94  mov     r9d, r14d
0x14000fb97  test    r13d, r13d
0x14000fb9a  jz      short loc_14000FBDF
0x14000fb9c  mov     r11, [rsp+258h+arg_8]
0x14000fba4  mov     r10d, ebx
0x14000fba7  add     r11, 4
0x14000fbab  mov     ebx, r13d
0x14000fbae  xchg    ax, ax
0x14000fbb0  mov     eax, r10d
0x14000fbb3  lea     r11, [r11+4]
0x14000fbb7  mov     edx, [rsi+rax*4+4]
0x14000fbbb  lea     rcx, [rsi+rax*4]
0x14000fbbf  mov     eax, [r11-4]
0x14000fbc3  inc     r10d
0x14000fbc6  add     rdx, rax
0x14000fbc9  mov     eax, r9d
0x14000fbcc  add     rdx, rax
0x14000fbcf  mov     r9, rdx
0x14000fbd2  mov     [rcx+4], edx
0x14000fbd5  shr     r9, 20h
0x14000fbd9  sub     rbx, 1
0x14000fbdd  jnz     short loc_14000FBB0
0x14000fbdf  dec     r8
0x14000fbe2  mov     ebx, [rsp+258h+arg_0]
0x14000fbe9  lea     r9d, [rdi-1]
0x14000fbed  mov     r11, [rsp+258h+var_228]
0x14000fbf2  dec     ebx
0x14000fbf4  mov     edx, [rsp+258h+arg_10]
0x14000fbfb  dec     edi
0x14000fbfd  shl     r15, 20h
0x14000fc01  mov     eax, r8d
0x14000fc04  add     r15, rax
0x14000fc07  mov     [rsp+258h+arg_0], ebx
0x14000fc0e  test    ebx, ebx
0x14000fc10  jns     loc_14000FA51
0x14000fc16  inc     r9d
0x14000fc19  mov     ecx, r9d
0x14000fc1c  cmp     r9d, [rsi]
0x14000fc1f  jnb     short loc_14000FC2E
0x14000fc21  mov     eax, ecx
0x14000fc23  inc     ecx
0x14000fc25  mov     [rsi+rax*4+4], r14d
0x14000fc2a  cmp     ecx, [rsi]
0x14000fc2c  jb      short loc_14000FC21
0x14000fc2e  mov     [rsi], r9d
0x14000fc31  test    r9d, r9d
0x14000fc34  jz      short loc_14000FC51
0x14000fc36  nop     word ptr [rax+rax+00000000h]
0x14000fc40  mov     edx, [rsi]
0x14000fc42  dec     edx
0x14000fc44  cmp     [rsi+rdx*4+4], r14d
0x14000fc49  jnz     short loc_14000FC51
0x14000fc4b  mov     [rsi], edx
0x14000fc4d  test    edx, edx
0x14000fc4f  jnz     short loc_14000FC40
0x14000fc51  mov     rax, r15
0x14000fc54  mov     r13, [rsp+258h+var_30]
0x14000fc5c  mov     r14, [rsp+258h+var_38]
0x14000fc64  mov     r12, [rsp+258h+var_28]
0x14000fc6c  mov     rbp, [rsp+258h+var_20]
0x14000fc74  mov     rbx, [rsp+258h+var_18]
0x14000fc7c  mov     r15, [rsp+258h+var_40]
0x14000fc84  add     rsp, 248h
0x14000fc8b  pop     rdi
0x14000fc8c  pop     rsi
0x14000fc8d  retn

// ===== __acrt_fltout @ 0x14000fc90 =====

0x14000fc90  push    rbp
0x14000fc92  push    rbx
0x14000fc93  push    rsi
0x14000fc94  push    rdi
0x14000fc95  push    r12
0x14000fc97  push    r13
0x14000fc99  push    r14
0x14000fc9b  push    r15
0x14000fc9d  lea     rbp, [rsp-6D8h]
0x14000fca5  sub     rsp, 7D8h
0x14000fcac  mov     rax, cs:__security_cookie
0x14000fcb3  xor     rax, rsp
0x14000fcb6  mov     [rbp+710h+var_50], rax
0x14000fcbd  mov     [rsp+810h+X], rcx
0x14000fcc2  mov     r14, r9
0x14000fcc5  lea     rcx, [rsp+810h+Env]; Env
0x14000fcca  mov     [rsp+810h+var_7C0], r9
0x14000fccf  mov     r15, r8
0x14000fcd2  mov     [rsp+810h+var_7A0], r8
0x14000fcd7  mov     esi, edx
0x14000fcd9  call    fegetenv
0x14000fcde  mov     eax, [rsp+810h+Env._Fe_ctl]
0x14000fce2  xor     r13d, r13d
0x14000fce5  and     eax, 1Fh
0x14000fce8  cmp     al, 1Fh
0x14000fcea  jnz     short loc_14000FCF3
0x14000fcec  mov     [rsp+810h+var_7A8], r13b
0x14000fcf1  jmp     short loc_14000FD02
0x14000fcf3  lea     rcx, [rsp+810h+Env]; Env
0x14000fcf8  call    feholdexcept
0x14000fcfd  mov     [rsp+810h+var_7A8], 1
0x14000fd02  mov     rbx, [rsp+810h+X]
0x14000fd07  mov     rcx, 8000000000000000h
0x14000fd11  mov     rax, rbx
0x14000fd14  mov     [r15+8], r14
0x14000fd18  and     rax, rcx
0x14000fd1b  mov     edi, 20h ; ' '
0x14000fd20  neg     rax
0x14000fd23  mov     r12, 0FFFFFFFFFFFFFh
0x14000fd2d  mov     rax, 7FF0000000000000h
0x14000fd37  sbb     ecx, ecx
0x14000fd39  and     ecx, 0Dh
0x14000fd3c  add     ecx, edi
0x14000fd3e  mov     [r15], ecx
0x14000fd41  test    rax, rbx
0x14000fd44  jnz     short loc_14000FD72
0x14000fd46  test    r12, rbx
0x14000fd49  jnz     short loc_14000FD72
0x14000fd4b  mov     rdx, [rbp+710h+SizeInBytes]; SizeInBytes
0x14000fd52  lea     r8, a0
0x14000fd59  mov     rcx, r14; Destination
0x14000fd5c  mov     [r15+4], r13d
0x14000fd60  call    strcpy_s
0x14000fd65  test    eax, eax
0x14000fd67  jz      loc_140010F5E
0x14000fd6d  jmp     loc_140010F92
0x14000fd72  lea     rcx, [rsp+810h+X]
0x14000fd77  call    ?__acrt_fp_classify@@YA?AW4__acrt_fp_class@@AEBN@Z
0x14000fd7c  test    eax, eax
0x14000fd7e  jz      short loc_14000FD88
0x14000fd80  mov     dword ptr [r15+4], 1
0x14000fd88  sub     eax, 1
0x14000fd8b  jz      loc_140010F40
0x14000fd91  sub     eax, 1
0x14000fd94  jz      loc_140010F21
0x14000fd9a  sub     eax, 1
0x14000fd9d  jz      loc_140010F02
0x14000fda3  cmp     eax, 1
0x14000fda6  jz      loc_140010EE3
0x14000fdac  mov     rax, 7FFFFFFFFFFFFFFFh
0x14000fdb6  mov     r9d, 7FFh
0x14000fdbc  and     rbx, rax
0x14000fdbf  inc     esi
0x14000fdc1  mov     [rsp+810h+X], rbx
0x14000fdc6  movsd   xmm0, [rsp+810h+X]; X
0x14000fdcc  movsd   [rsp+810h+var_7B8], xmm0
0x14000fdd2  mov     rdx, [rsp+810h+var_7B8]
0x14000fdd7  mov     r8, rdx
0x14000fdda  mov     [rsp+810h+var_7C4], esi
0x14000fdde  shr     r8, 34h
0x14000fde2  test    r9, r8
0x14000fde5  setz    cl
0x14000fde8  mov     al, cl
0x14000fdea  neg     al
0x14000fdec  mov     rax, 10000000000000h
0x14000fdf6  sbb     r14, r14
0x14000fdf9  and     rdx, r12
0x14000fdfc  not     r14
0x14000fdff  and     r14, rax
0x14000fe02  add     r14, rdx
0x14000fe05  neg     cl
0x14000fe07  sbb     eax, eax
0x14000fe09  and     r8d, r9d
0x14000fe0c  neg     eax
0x14000fe0e  inc     eax
0x14000fe10  lea     ebx, [r8-434h]
0x14000fe17  add     ebx, eax
0x14000fe19  call    log10
0x14000fe1e  call    ceil
0x14000fe23  cvttsd2si ecx, xmm0
0x14000fe27  mov     [rbp+710h+Destination], r14d
0x14000fe2b  mov     r10d, 1
0x14000fe31  lea     eax, [rcx-7FFFFFFFh]
0x14000fe37  and     eax, 0FFFFFFFEh
0x14000fe3a  neg     eax
0x14000fe3c  sbb     r12d, r12d
0x14000fe3f  shr     r14, 20h
0x14000fe43  and     r12d, ecx
0x14000fe46  mov     [rbp+710h+var_788], r14d
0x14000fe4a  mov     eax, r14d
0x14000fe4d  mov     [rsp+810h+var_7E0], r12d
0x14000fe52  neg     eax
0x14000fe54  sbb     edx, edx
0x14000fe56  neg     edx
0x14000fe58  add     edx, r10d
0x14000fe5b  mov     [rbp+710h+var_790], edx
0x14000fe5e  test    ebx, ebx
0x14000fe60  js      loc_14001010F
0x14000fe66  xor     eax, eax
0x14000fe68  mov     [rbp+710h+var_3E8], 100000h
0x14000fe72  mov     [rbp+710h+Source], eax
0x14000fe78  lea     esi, [rax+2]
0x14000fe7b  mov     [rbp+710h+var_3F0], esi
0x14000fe81  cmp     edx, esi
0x14000fe83  jnz     loc_14000FFEA
0x14000fe89  mov     r8d, r13d
0x14000fe8c  mov     ecx, r8d
0x14000fe8f  mov     eax, [rbp+rcx*4+710h+Destination]
0x14000fe93  cmp     [rbp+rcx*4+710h+Source], eax
0x14000fe9a  jnz     loc_14000FFEA
0x14000fea0  add     r8d, r10d
0x14000fea3  cmp     r8d, esi
0x14000fea6  jnz     short loc_14000FE8C
0x14000fea8  lea     r11d, [rbx+2]
0x14000feac  mov     dword ptr [rsp+810h+X], r13d
0x14000feb1  mov     r9d, r11d
0x14000feb4  mov     esi, edi
0x14000feb6  and     r11d, 1Fh
0x14000feba  shr     r9d, 5
0x14000febe  sub     esi, r11d
0x14000fec1  mov     rbx, r10
0x14000fec4  mov     ecx, esi
0x14000fec6  shl     rbx, cl
0x14000fec9  sub     ebx, r10d
0x14000fecc  bsr     eax, r14d
0x14000fed0  mov     r12d, ebx
0x14000fed3  not     r12d
0x14000fed6  jz      short loc_14000FEDC
0x14000fed8  inc     eax
0x14000feda  jmp     short loc_14000FEDF
0x14000fedc  mov     eax, r13d
0x14000fedf  sub     edi, eax
0x14000fee1  lea     eax, [r9+2]
0x14000fee5  cmp     r11d, edi
0x14000fee8  setnbe  r15b
0x14000feec  cmp     eax, 73h ; 's'
0x14000feef  setnbe  r8b
0x14000fef3  cmp     eax, 73h ; 's'
0x14000fef6  jnz     short loc_14000FF00
0x14000fef8  mov     cl, r10b
0x14000fefb  test    r15b, r15b
0x14000fefe  jnz     short loc_14000FF03
0x14000ff00  mov     cl, r13b
0x14000ff03  or      r13d, 0FFFFFFFFh
0x14000ff07  test    r8b, r8b
0x14000ff0a  jnz     loc_14000FFB1
0x14000ff10  test    cl, cl
0x14000ff12  jnz     loc_14000FFB1
0x14000ff18  mov     r14d, 72h ; 'r'
0x14000ff1e  cmp     eax, r14d
0x14000ff21  cmovb   r14d, eax
0x14000ff25  cmp     r14d, r13d
0x14000ff28  jz      short loc_14000FF86
0x14000ff2a  mov     r8d, r14d
0x14000ff2d  sub     r8d, r9d
0x14000ff30  lea     edi, [r8+r9]
0x14000ff34  cmp     edi, r9d
0x14000ff37  jb      short loc_14000FF80
0x14000ff39  cmp     r8d, edx
0x14000ff3c  jnb     short loc_14000FF45
0x14000ff3e  mov     r10d, [rbp+r8*4+710h+Destination]
0x14000ff43  jmp     short loc_14000FF48
0x14000ff45  xor     r10d, r10d
0x14000ff48  lea     eax, [r8-1]
0x14000ff4c  cmp     eax, edx
0x14000ff4e  jnb     short loc_14000FF56
0x14000ff50  mov     edx, [rbp+rax*4+710h+Destination]
0x14000ff54  jmp     short loc_14000FF58
0x14000ff56  xor     edx, edx
0x14000ff58  and     edx, r12d
0x14000ff5b  mov     ecx, esi
0x14000ff5d  shr     edx, cl
0x14000ff5f  add     r8d, r13d
0x14000ff62  and     r10d, ebx
0x14000ff65  mov     ecx, r11d
0x14000ff68  shl     r10d, cl
0x14000ff6b  or      edx, r10d
0x14000ff6e  lea     eax, [r8+r9]
0x14000ff72  mov     [rbp+rdi*4+710h+Destination], edx
0x14000ff76  cmp     eax, r13d
0x14000ff79  jz      short loc_14000FF80
0x14000ff7b  mov     edx, [rbp+710h+var_790]
0x14000ff7e  jmp     short loc_14000FF30
0x14000ff80  mov     r10d, 1
0x14000ff86  xor     r13d, r13d
0x14000ff89  mov     ecx, r13d
0x14000ff8c  test    r9d, r9d
0x14000ff8f  jz      short loc_14000FFA0
0x14000ff91  mov     eax, ecx
0x14000ff93  add     ecx, r10d
0x14000ff96  mov     [rbp+rax*4+710h+Destination], r13d
0x14000ff9b  cmp     ecx, r9d
0x14000ff9e  jnz     short loc_14000FF91
0x14000ffa0  test    r15b, r15b
0x14000ffa3  lea     eax, [r14+1]
0x14000ffa7  cmovnz  r14d, eax
0x14000ffab  mov     [rbp+710h+var_790], r14d
0x14000ffaf  jmp     short loc_14000FFBB
0x14000ffb1  xor     r13d, r13d
0x14000ffb4  mov     r14d, r13d
0x14000ffb7  mov     [rbp+710h+var_790], r13d
0x14000ffbb  mov     dword ptr [rbp+710h+var_5BC], 4
0x14000ffc5  mov     r12d, [rsp+810h+var_7E0]
0x14000ffca  mov     r15d, 1
0x14000ffd0  mov     [rbp+710h+var_5C0], r15d
0x14000ffd7  mov     [rbp+710h+var_3F0], r15d
0x14000ffde  mov     [rbp+710h+var_3E8], r13d
0x14000ffe5  jmp     loc_14001035E
0x14000ffea  and     dword ptr [rsp+810h+X], 0
0x14000ffef  lea     r11d, [rbx+1]
0x14000fff3  mov     r9d, r11d
0x14000fff6  lea     eax, [rdx-1]
0x14000fff9  and     r11d, 1Fh
0x14000fffd  shr     r9d, 5
0x140010001  mov     r15d, edi
0x140010004  mov     rbx, r10
0x140010007  sub     r15d, r11d
0x14001000a  mov     ecx, r15d
0x14001000d  shl     rbx, cl
0x140010010  sub     ebx, r10d
0x140010013  mov     ecx, eax
0x140010015  bsr     eax, [rbp+rax*4+710h+Destination]
0x14001001a  mov     r13d, ebx
0x14001001d  not     r13d
0x140010020  jz      short loc_140010026
0x140010022  inc     eax
0x140010024  jmp     short loc_140010028
0x140010026  xor     eax, eax
0x140010028  sub     edi, eax
0x14001002a  lea     eax, [rdx+r9]
0x14001002e  cmp     r11d, edi
0x140010031  setnbe  r12b
0x140010035  cmp     eax, 73h ; 's'
0x140010038  setnbe  r8b
0x14001003c  cmp     eax, 73h ; 's'
0x14001003f  jnz     short loc_14001004B
0x140010041  test    r12b, r12b
0x140010044  jz      short loc_14001004B
0x140010046  mov     cl, r10b
0x140010049  jmp     short loc_14001004D
0x14001004b  xor     cl, cl
0x14001004d  or      r10d, 0FFFFFFFFh
0x140010051  test    r8b, r8b
0x140010054  jnz     loc_1400100FA
0x14001005a  test    cl, cl
0x14001005c  jnz     loc_1400100FA
0x140010062  mov     r14d, 72h ; 'r'
0x140010068  cmp     eax, r14d
0x14001006b  cmovb   r14d, eax
0x14001006f  cmp     r14d, r10d
0x140010072  jz      short loc_1400100D0
0x140010074  mov     r8d, r14d
0x140010077  sub     r8d, r9d
0x14001007a  lea     edi, [r8+r9]
0x14001007e  cmp     edi, r9d
0x140010081  jb      short loc_1400100D0
0x140010083  cmp     r8d, edx
0x140010086  jnb     short loc_14001008F
0x140010088  mov     r10d, [rbp+r8*4+710h+Destination]
0x14001008d  jmp     short loc_140010092
0x14001008f  xor     r10d, r10d
0x140010092  lea     eax, [r8-1]
0x140010096  cmp     eax, edx
0x140010098  jnb     short loc_1400100A0
0x14001009a  mov     edx, [rbp+rax*4+710h+Destination]
0x14001009e  jmp     short loc_1400100A2
0x1400100a0  xor     edx, edx
0x1400100a2  and     r10d, ebx
0x1400100a5  mov     ecx, r11d
0x1400100a8  shl     r10d, cl
0x1400100ab  and     edx, r13d
0x1400100ae  mov     ecx, r15d
0x1400100b1  shr     edx, cl
0x1400100b3  or      r10d, edx
0x1400100b6  mov     [rbp+rdi*4+710h+Destination], r10d
0x1400100bb  or      r10d, 0FFFFFFFFh
0x1400100bf  add     r8d, r10d
0x1400100c2  lea     eax, [r8+r9]
0x1400100c6  cmp     eax, r10d
0x1400100c9  jz      short loc_1400100D0
0x1400100cb  mov     edx, [rbp+710h+var_790]
0x1400100ce  jmp     short loc_14001007A
0x1400100d0  xor     r13d, r13d
0x1400100d3  mov     ecx, r13d
0x1400100d6  test    r9d, r9d
0x1400100d9  jz      short loc_1400100E9
0x1400100db  mov     eax, ecx
0x1400100dd  inc     ecx
0x1400100df  mov     [rbp+rax*4+710h+Destination], r13d
0x1400100e4  cmp     ecx, r9d
0x1400100e7  jnz     short loc_1400100DB
0x1400100e9  test    r12b, r12b
0x1400100ec  lea     eax, [r14+1]
0x1400100f0  cmovnz  r14d, eax
0x1400100f4  mov     [rbp+710h+var_790], r14d
0x1400100f8  jmp     short loc_140010104
0x1400100fa  xor     r13d, r13d
0x1400100fd  mov     r14d, r13d
0x140010100  mov     [rbp+710h+var_790], r13d
0x140010104  mov     dword ptr [rbp+710h+var_5BC], esi
0x14001010a  jmp     loc_14000FFC5
0x14001010f  cmp     ebx, 0FFFFFC02h
0x140010115  jz      loc_140010247
0x14001011b  xor     eax, eax
0x14001011d  mov     [rbp+710h+var_3E8], 100000h
0x140010127  mov     [rbp+710h+Source], eax
0x14001012d  lea     esi, [rax+2]
0x140010130  mov     [rbp+710h+var_3F0], esi
0x140010136  cmp     edx, esi
0x140010138  jnz     loc_140010247
0x14001013e  mov     r8d, r13d
0x140010141  mov     ecx, r8d
0x140010144  mov     eax, [rbp+rcx*4+710h+Destination]
0x140010148  cmp     [rbp+rcx*4+710h+Source], eax
0x14001014f  jnz     loc_140010247
0x140010155  add     r8d, r10d
0x140010158  cmp     r8d, esi
0x14001015b  jnz     short loc_140010141
0x14001015d  bsr     eax, r14d
0x140010161  mov     dword ptr [rsp+810h+X], r13d
0x140010166  jz      short loc_14001016C
0x140010168  inc     eax
0x14001016a  jmp     short loc_14001016F
0x14001016c  mov     eax, r13d
0x14001016f  sub     edi, eax
0x140010171  mov     ecx, esi
0x140010173  cmp     edi, esi
0x140010175  setb    r9b
0x140010179  or      r13d, 0FFFFFFFFh
0x14001017d  cmp     ecx, edx
0x14001017f  jnb     short loc_14001018A
0x140010181  mov     eax, ecx
0x140010183  mov     r8d, [rbp+rax*4+710h+Destination]
0x140010188  jmp     short loc_14001018D
0x14001018a  xor     r8d, r8d
0x14001018d  lea     eax, [rcx-1]
0x140010190  cmp     eax, edx
0x140010192  jnb     short loc_14001019A
0x140010194  mov     edx, [rbp+rax*4+710h+Destination]
0x140010198  jmp     short loc_14001019C
0x14001019a  xor     edx, edx
0x14001019c  mov     eax, r8d
0x14001019f  shr     edx, 1Eh
0x1400101a2  shl     eax, 2
0x1400101a5  xor     edx, eax
0x1400101a7  mov     eax, ecx
0x1400101a9  add     ecx, r13d
0x1400101ac  mov     [rbp+rax*4+710h+Destination], edx
0x1400101b0  cmp     ecx, r13d
0x1400101b3  jz      short loc_1400101BA
0x1400101b5  mov     edx, [rbp+710h+var_790]
0x1400101b8  jmp     short loc_14001017D
0x1400101ba  neg     r9b
0x1400101bd  lea     rcx, [rbp+710h+Source]
0x1400101c4  sbb     r14d, r14d
0x1400101c7  xor     edx, edx
0x1400101c9  neg     r14d
0x1400101cc  add     r14d, esi
0x1400101cf  sub     esi, ebx
0x1400101d1  mov     edi, esi
0x1400101d3  mov     [rbp+710h+var_790], r14d
0x1400101d7  shr     edi, 5
0x1400101da  mov     ebx, edi
0x1400101dc  shl     rbx, 2
0x1400101e0  mov     r8, rbx
0x1400101e3  call    sub_140005B30
0x1400101e8  and     esi, 1Fh
0x1400101eb  lea     r15d, [rdi+1]
0x1400101ef  mov     cl, sil
0x1400101f2  mov     r8d, r15d
0x1400101f5  mov     eax, 1
0x1400101fa  shl     r8, 2
0x1400101fe  shl     eax, cl
0x140010200  mov     [rbp+rbx+710h+Source], eax
0x140010207  xor     r13d, r13d
0x14001020a  mov     [rbp+710h+var_5C0], r15d
0x140010211  mov     [rbp+710h+var_3F0], r15d
0x140010218  test    r8, r8
0x14001021b  jz      loc_14001035E
0x140010221  mov     ebx, 1CCh
0x140010226  lea     rcx, [rbp+710h+var_5BC]
0x14001022d  cmp     r8, rbx
0x140010230  ja      loc_14001033D
0x140010236  lea     rdx, [rbp+710h+Source]
0x14001023d  call    sub_1400067F0
0x140010242  jmp     loc_140010357
0x140010247  lea     eax, [rdx-1]
0x14001024a  mov     dword ptr [rsp+810h+X], r13d
0x14001024f  mov     ecx, eax
0x140010251  bsr     eax, [rbp+rax*4+710h+Destination]
0x140010256  jz      short loc_14001025C
0x140010258  inc     eax
0x14001025a  jmp     short loc_14001025F
0x14001025c  mov     eax, r13d
0x14001025f  sub     edi, eax
0x140010261  cmp     edi, r10d
0x140010264  setb    r9b
0x140010268  cmp     edx, 73h ; 's'
0x14001026b  setnbe  cl
0x14001026e  cmp     edx, 73h ; 's'
0x140010271  jnz     short loc_14001027B
0x140010273  mov     al, r10b
0x140010276  test    r9b, r9b
0x140010279  jnz     short loc_14001027E
0x14001027b  mov     al, r13b
0x14001027e  or      r13d, 0FFFFFFFFh
0x140010282  test    cl, cl
0x140010284  jnz     short loc_1400102EE
0x140010286  test    al, al
0x140010288  jnz     short loc_1400102EE
0x14001028a  mov     r14d, 72h ; 'r'
0x140010290  cmp     edx, r14d
0x140010293  cmovb   r14d, edx
0x140010297  cmp     r14d, r13d
0x14001029a  jz      short loc_1400102DA
0x14001029c  mov     ecx, r14d
0x14001029f  cmp     ecx, edx
0x1400102a1  jnb     short loc_1400102AC
0x1400102a3  mov     eax, ecx
0x1400102a5  mov     r8d, [rbp+rax*4+710h+Destination]
0x1400102aa  jmp     short loc_1400102AF
0x1400102ac  xor     r8d, r8d
0x1400102af  lea     eax, [rcx-1]
0x1400102b2  cmp     eax, edx
0x1400102b4  jnb     short loc_1400102BC
0x1400102b6  mov     edx, [rbp+rax*4+710h+Destination]
0x1400102ba  jmp     short loc_1400102BE
0x1400102bc  xor     edx, edx
0x1400102be  shr     edx, 1Fh
0x1400102c1  lea     eax, [r8+r8]
0x1400102c5  xor     edx, eax
0x1400102c7  mov     eax, ecx
0x1400102c9  add     ecx, r13d
0x1400102cc  mov     [rbp+rax*4+710h+Destination], edx
0x1400102d0  cmp     ecx, r13d
0x1400102d3  jz      short loc_1400102DA
0x1400102d5  mov     edx, [rbp+710h+var_790]
0x1400102d8  jmp     short loc_14001029F
0x1400102da  xor     r13d, r13d
0x1400102dd  lea     eax, [r14+1]
0x1400102e1  test    r9b, r9b
0x1400102e4  cmovnz  r14d, eax
0x1400102e8  mov     [rbp+710h+var_790], r14d
0x1400102ec  jmp     short loc_1400102F8
0x1400102ee  xor     r13d, r13d
0x1400102f1  mov     r14d, r13d
0x1400102f4  mov     [rbp+710h+var_790], r13d
0x1400102f8  mov     edi, r10d
0x1400102fb  lea     rcx, [rbp+710h+Source]
0x140010302  sub     edi, ebx
0x140010304  xor     edx, edx
0x140010306  mov     esi, edi
0x140010308  shr     esi, 5
0x14001030b  mov     ebx, esi
0x14001030d  shl     rbx, 2
0x140010311  mov     r8, rbx
0x140010314  call    sub_140005B30
0x140010319  and     edi, 1Fh
0x14001031c  lea     r15d, [rsi+1]
0x140010320  mov     cl, dil
0x140010323  mov     r8d, r15d
0x140010326  mov     eax, 1
0x14001032b  shl     eax, cl
0x14001032d  mov     [rbp+rbx+710h+Source], eax
0x140010334  shl     r8, 2
0x140010338  jmp     loc_14001020A
0x14001033d  mov     r8, rbx
0x140010340  xor     edx, edx
0x140010342  call    sub_140005B30
0x140010347  call    _errno
0x14001034c  mov     dword ptr [rax], 22h ; '"'
0x140010352  call    _invalid_parameter_noinfo
0x140010357  mov     r15d, [rbp+710h+var_5C0]
0x14001035e  mov     eax, 0CCCCCCCDh
0x140010363  test    r12d, r12d
0x140010366  js      loc_14001082A
0x14001036c  mul     r12d
0x14001036f  mov     eax, edx
0x140010371  lea     rdx, cs:140000000h
0x140010378  shr     eax, 3
0x14001037b  mov     [rsp+810h+var_7C8], eax
0x14001037f  mov     r12d, eax
0x140010382  mov     [rsp+810h+var_7D0], eax
0x140010386  test    eax, eax
0x140010388  jz      loc_140010761
0x14001038e  mov     eax, 26h ; '&'
0x140010393  mov     r13d, r12d
0x140010396  cmp     r12d, eax
0x140010399  cmova   r13d, eax
0x14001039d  mov     [rsp+810h+var_7CC], r13d
0x1400103a2  lea     eax, [r13-1]
0x1400103a6  movzx   ecx, ds:rva byte_140017B42[rdx+rax*4]
0x1400103ae  movzx   esi, ds:rva byte_140017B43[rdx+rax*4]
0x1400103b6  mov     ebx, ecx
0x1400103b8  mov     edi, eax
0x1400103ba  xor     edx, edx
0x1400103bc  shl     rbx, 2
0x1400103c0  mov     r8, rbx
0x1400103c3  lea     eax, [rsi+rcx]
0x1400103c6  lea     rcx, [rbp+710h+Source]
0x1400103cd  mov     [rbp+710h+var_3F0], eax
0x1400103d3  call    sub_140005B30
0x1400103d8  lea     rcx, cs:140000000h
0x1400103df  shl     rsi, 2
0x1400103e3  movzx   eax, ds:rva word_140017B40[rcx+rdi*4]
0x1400103eb  lea     rdx, rva unk_140017230[rcx]
0x1400103f2  lea     rcx, [rbp+710h+Source]
0x1400103f9  mov     r8, rsi
0x1400103fc  add     rcx, rbx
0x1400103ff  lea     rdx, [rdx+rax*4]
0x140010403  call    sub_1400067F0
0x140010408  mov     r11d, [rbp+710h+var_3F0]
0x14001040f  cmp     r11d, 1
0x140010413  ja      loc_1400104BB
0x140010419  mov     eax, [rbp+710h+Source]
0x14001041f  test    eax, eax
0x140010421  jnz     short loc_140010432
0x140010423  xor     r15d, r15d
0x140010426  mov     [rbp+710h+var_5C0], r15d
0x14001042d  jmp     loc_14001073B
0x140010432  cmp     eax, 1
0x140010435  jz      loc_14001073B
0x14001043b  test    r15d, r15d
0x14001043e  jz      loc_14001073B
0x140010444  xor     r8d, r8d
0x140010447  mov     r10, rax
0x14001044a  xor     r9d, r9d
0x14001044d  mov     ecx, dword ptr [rbp+r9*4+710h+var_5BC]
0x140010455  mov     eax, r8d
0x140010458  imul    rcx, r10
0x14001045c  add     rcx, rax
0x14001045f  mov     r8, rcx
0x140010462  mov     dword ptr [rbp+r9*4+710h+var_5BC], ecx
0x14001046a  shr     r8, 20h
0x14001046e  inc     r9d
0x140010471  cmp     r9d, r15d
0x140010474  jnz     short loc_14001044D
0x140010476  test    r8d, r8d
0x140010479  jz      short loc_1400104AF
0x14001047b  cmp     [rbp+710h+var_5C0], 73h ; 's'
0x140010482  jnb     short loc_14001049E
0x140010484  mov     eax, [rbp+710h+var_5C0]
0x14001048a  mov     dword ptr [rbp+rax*4+710h+var_5BC], r8d
0x140010492  mov     r15d, [rbp+710h+var_5C0]
0x140010499  inc     r15d
0x14001049c  jmp     short loc_140010426
0x14001049e  xor     r15d, r15d
0x1400104a1  mov     [rbp+710h+var_5C0], r15d
0x1400104a8  xor     al, al
0x1400104aa  jmp     loc_14001073D
0x1400104af  mov     r15d, [rbp+710h+var_5C0]
0x1400104b6  jmp     loc_14001073B
0x1400104bb  cmp     r15d, 1
0x1400104bf  ja      loc_140010572
0x1400104c5  mov     ebx, dword ptr [rbp+710h+var_5BC]
0x1400104cb  mov     r8, r11
0x1400104ce  shl     r8, 2
0x1400104d2  mov     r15d, r11d
0x1400104d5  mov     [rbp+710h+var_5C0], r11d
0x1400104dc  test    r8, r8
0x1400104df  jz      short loc_140010521
0x1400104e1  mov     eax, 1CCh
0x1400104e6  lea     rcx, [rbp+710h+var_5BC]
0x1400104ed  cmp     r8, rax
0x1400104f0  ja      short loc_140010500
0x1400104f2  lea     rdx, [rbp+710h+Source]
0x1400104f9  call    sub_1400067F0
0x1400104fe  jmp     short loc_14001051A
0x140010500  mov     r8, rax
0x140010503  xor     edx, edx
0x140010505  call    sub_140005B30
0x14001050a  call    _errno
0x14001050f  mov     dword ptr [rax], 22h ; '"'
0x140010515  call    _invalid_parameter_noinfo
0x14001051a  mov     r15d, [rbp+710h+var_5C0]
0x140010521  test    ebx, ebx
0x140010523  jz      loc_140010423
0x140010529  cmp     ebx, 1
0x14001052c  jz      loc_14001073B
0x140010532  test    r15d, r15d
0x140010535  jz      loc_14001073B
0x14001053b  xor     r8d, r8d
0x14001053e  mov     r10, rbx
0x140010541  xor     r9d, r9d
0x140010544  mov     ecx, dword ptr [rbp+r9*4+710h+var_5BC]
0x14001054c  mov     eax, r8d
0x14001054f  imul    rcx, r10
0x140010553  add     rcx, rax
0x140010556  mov     r8, rcx
0x140010559  mov     dword ptr [rbp+r9*4+710h+var_5BC], ecx
0x140010561  shr     r8, 20h
0x140010565  inc     r9d
0x140010568  cmp     r9d, r15d
0x14001056b  jnz     short loc_140010544
0x14001056d  jmp     loc_140010476
0x140010572  cmp     r11d, r15d
0x140010575  lea     rcx, [rbp+710h+var_5BC]
0x14001057c  mov     r12d, r15d
0x14001057f  lea     r13, [rbp+710h+Source]
0x140010586  setb    al
0x140010589  lea     rdx, [rbp+710h+var_5BC]
0x140010590  test    al, al
0x140010592  cmovz   r13, rcx
0x140010596  cmovnz  r12d, r11d
0x14001059a  cmovnz  r11d, r15d
0x14001059e  lea     rcx, [rbp+710h+Source]
0x1400105a5  cmovz   rdx, rcx
0x1400105a9  xor     r15d, r15d
0x1400105ac  xor     r10d, r10d
0x1400105af  mov     [rsp+810h+X], rdx
0x1400105b4  mov     [rbp+710h+var_220], r15d
0x1400105bb  test    r12d, r12d
0x1400105be  jz      loc_1400106DE
0x1400105c4  mov     esi, [r13+r10*4+0]
0x1400105c9  mov     eax, r10d
0x1400105cc  test    esi, esi
0x1400105ce  jnz     short loc_1400105F1
0x1400105d0  cmp     r10d, r15d
0x1400105d3  jnz     loc_1400106D2
0x1400105d9  and     dword ptr [rbp+r10*4+710h+var_21C], esi
0x1400105e1  lea     r15d, [r10+1]
0x1400105e5  mov     [rbp+710h+var_220], r15d
0x1400105ec  jmp     loc_1400106D2
0x1400105f1  xor     ebx, ebx
0x1400105f3  mov     r9d, r10d
0x1400105f6  test    r11d, r11d
0x1400105f9  jz      loc_1400106C3
0x1400105ff  mov     edi, r10d
0x140010602  neg     edi
0x140010604  cmp     r9d, 73h ; 's'
0x140010608  jz      short loc_140010671
0x14001060a  cmp     r9d, r15d
0x14001060d  jnz     short loc_14001062A
0x14001060f  mov     eax, r9d
0x140010612  lea     ecx, [r10+1]
0x140010616  and     dword ptr [rbp+rax*4+710h+var_21C], 0
0x14001061e  lea     eax, [rdi+r9]
0x140010622  add     ecx, eax
0x140010624  mov     [rbp+710h+var_220], ecx
0x14001062a  lea     eax, [rdi+r9]
0x14001062e  mov     r8d, r9d
0x140010631  mov     edx, [rdx+rax*4]
0x140010634  inc     r9d
0x140010637  mov     eax, ebx
0x140010639  imul    rdx, rsi
0x14001063d  add     rdx, rax
0x140010640  mov     eax, dword ptr [rbp+r8*4+710h+var_21C]
0x140010648  add     rdx, rax
0x14001064b  lea     eax, [rdi+r9]
0x14001064f  mov     rbx, rdx
0x140010652  mov     dword ptr [rbp+r8*4+710h+var_21C], edx
0x14001065a  mov     r15d, [rbp+710h+var_220]
0x140010661  shr     rbx, 20h
0x140010665  cmp     eax, r11d
0x140010668  jz      short loc_140010671
0x14001066a  mov     rdx, [rsp+810h+X]
0x14001066f  jmp     short loc_140010604
0x140010671  test    ebx, ebx
0x140010673  jz      short loc_1400106C3
0x140010675  cmp     r9d, 73h ; 's'
0x140010679  jz      loc_1400107FD
0x14001067f  cmp     r9d, r15d
0x140010682  jnz     short loc_140010699
0x140010684  mov     eax, r9d
0x140010687  and     dword ptr [rbp+rax*4+710h+var_21C], 0
0x14001068f  lea     eax, [r9+1]
0x140010693  mov     [rbp+710h+var_220], eax
0x140010699  mov     ecx, r9d
0x14001069c  inc     r9d
0x14001069f  mov     edx, ebx
0x1400106a1  mov     eax, dword ptr [rbp+rcx*4+710h+var_21C]
0x1400106a8  add     rdx, rax
0x1400106ab  mov     dword ptr [rbp+rcx*4+710h+var_21C], edx
0x1400106b2  mov     r15d, [rbp+710h+var_220]
0x1400106b9  shr     rdx, 20h
0x1400106bd  mov     ebx, edx
0x1400106bf  test    edx, edx
0x1400106c1  jnz     short loc_140010675
0x1400106c3  cmp     r9d, 73h ; 's'
0x1400106c7  jz      loc_1400107FD
0x1400106cd  mov     rdx, [rsp+810h+X]
0x1400106d2  inc     r10d
0x1400106d5  cmp     r10d, r12d
0x1400106d8  jnz     loc_1400105C4
0x1400106de  mov     r8d, r15d
0x1400106e1  shl     r8, 2
0x1400106e5  mov     [rbp+710h+var_5C0], r15d
0x1400106ec  test    r8, r8
0x1400106ef  jz      short loc_140010731
0x1400106f1  mov     eax, 1CCh
0x1400106f6  lea     rcx, [rbp+710h+var_5BC]
0x1400106fd  cmp     r8, rax
0x140010700  ja      short loc_140010710
0x140010702  lea     rdx, [rbp+710h+var_21C]
0x140010709  call    sub_1400067F0
0x14001070e  jmp     short loc_14001072A
0x140010710  mov     r8, rax
0x140010713  xor     edx, edx
0x140010715  call    sub_140005B30
0x14001071a  call    _errno
0x14001071f  mov     dword ptr [rax], 22h ; '"'
0x140010725  call    _invalid_parameter_noinfo
0x14001072a  mov     r15d, [rbp+710h+var_5C0]
0x140010731  mov     r12d, [rsp+810h+var_7D0]
0x140010736  mov     r13d, [rsp+810h+var_7CC]
0x14001073b  mov     al, 1
0x14001073d  test    al, al
0x14001073f  jz      loc_1400107FD
0x140010745  sub     r12d, r13d
0x140010748  lea     rdx, cs:140000000h
0x14001074f  mov     [rsp+810h+var_7D0], r12d
0x140010754  jnz     loc_14001038E
0x14001075a  mov     eax, [rsp+810h+var_7C8]
0x14001075e  xor     r13d, r13d
0x140010761  mov     edi, [rsp+810h+var_7E0]
0x140010765  lea     eax, [rax+rax*4]
0x140010768  add     eax, eax
0x14001076a  mov     ecx, edi
0x14001076c  sub     ecx, eax
0x14001076e  jz      loc_140010C93
0x140010774  lea     eax, [rcx-1]
0x140010777  mov     eax, ds:rva dword_140017BD8[rdx+rax*4]
0x14001077e  test    eax, eax
0x140010780  jz      loc_14001080F
0x140010786  cmp     eax, 1
0x140010789  jz      loc_140010C93
0x14001078f  test    r15d, r15d
0x140010792  jz      loc_140010C93
0x140010798  mov     r8d, r13d
0x14001079b  mov     r9d, r13d
0x14001079e  mov     r10d, eax
0x1400107a1  mov     edx, r9d
0x1400107a4  inc     r9d
0x1400107a7  mov     eax, r8d
0x1400107aa  mov     ecx, dword ptr [rbp+rdx*4+710h+var_5BC]
0x1400107b1  imul    rcx, r10
0x1400107b5  add     rcx, rax
0x1400107b8  mov     r8, rcx
0x1400107bb  mov     dword ptr [rbp+rdx*4+710h+var_5BC], ecx
0x1400107c2  shr     r8, 20h
0x1400107c6  cmp     r9d, r15d
0x1400107c9  jnz     short loc_1400107A1
0x1400107cb  test    r8d, r8d
0x1400107ce  jz      short loc_14001081E
0x1400107d0  cmp     [rbp+710h+var_5C0], 73h ; 's'
0x1400107d7  jnb     short loc_14001080F
0x1400107d9  mov     eax, [rbp+710h+var_5C0]
0x1400107df  mov     dword ptr [rbp+rax*4+710h+var_5BC], r8d
0x1400107e7  mov     r15d, [rbp+710h+var_5C0]
0x1400107ee  inc     r15d
0x1400107f1  mov     [rbp+710h+var_5C0], r15d
0x1400107f8  jmp     loc_140010C93
0x1400107fd  xor     r13d, r13d
0x140010800  mov     r15d, r13d
0x140010803  mov     [rbp+710h+var_5C0], r13d
0x14001080a  jmp     loc_140010C8F
0x14001080f  mov     r15d, r13d
0x140010812  mov     [rbp+710h+var_5C0], r13d
0x140010819  jmp     loc_140010C93
0x14001081e  mov     r15d, [rbp+710h+var_5C0]
0x140010825  jmp     loc_140010C93
0x14001082a  mov     ecx, r12d
0x14001082d  neg     ecx
0x14001082f  mul     ecx
0x140010831  mov     [rsp+810h+var_7CC], ecx
0x140010835  mov     eax, edx
0x140010837  lea     rdx, cs:140000000h
0x14001083e  shr     eax, 3
0x140010841  mov     dword ptr [rsp+810h+X], eax
0x140010845  mov     r12d, eax
0x140010848  mov     [rsp+810h+var_7D0], eax
0x14001084c  test    eax, eax
0x14001084e  jz      loc_140010BEB
0x140010854  mov     eax, 26h ; '&'
0x140010859  mov     r13d, r12d
0x14001085c  cmp     r12d, eax
0x14001085f  cmova   r13d, eax
0x140010863  mov     [rsp+810h+var_7C8], r13d
0x140010868  lea     eax, [r13-1]
0x14001086c  movzx   ecx, ds:rva byte_140017B42[rdx+rax*4]
0x140010874  movzx   esi, ds:rva byte_140017B43[rdx+rax*4]
0x14001087c  mov     ebx, ecx
0x14001087e  mov     edi, eax
0x140010880  xor     edx, edx
0x140010882  shl     rbx, 2
0x140010886  mov     r8, rbx
0x140010889  lea     eax, [rsi+rcx]
0x14001088c  lea     rcx, [rbp+710h+Source]
0x140010893  mov     [rbp+710h+var_3F0], eax
0x140010899  call    sub_140005B30
0x14001089e  lea     rcx, cs:140000000h
0x1400108a5  shl     rsi, 2
0x1400108a9  movzx   eax, ds:rva word_140017B40[rcx+rdi*4]
0x1400108b1  lea     rdx, rva unk_140017230[rcx]
0x1400108b8  lea     rcx, [rbp+710h+Source]
0x1400108bf  mov     r8, rsi
0x1400108c2  add     rcx, rbx
0x1400108c5  lea     rdx, [rdx+rax*4]
0x1400108c9  call    sub_1400067F0
0x1400108ce  mov     edi, [rbp+710h+var_3F0]
0x1400108d4  cmp     edi, 1
0x1400108d7  ja      loc_140010964
0x1400108dd  mov     eax, [rbp+710h+Source]
0x1400108e3  test    eax, eax
0x1400108e5  jnz     short loc_1400108F3
0x1400108e7  xor     r14d, r14d
0x1400108ea  mov     [rbp+710h+var_790], r14d
0x1400108ee  jmp     loc_140010BC1
0x1400108f3  cmp     eax, 1
0x1400108f6  jz      loc_140010BC1
0x1400108fc  test    r14d, r14d
0x1400108ff  jz      loc_140010BC1
0x140010905  xor     r8d, r8d
0x140010908  mov     r10, rax
0x14001090b  xor     r9d, r9d
0x14001090e  mov     ecx, [rbp+r9*4+710h+Destination]
0x140010913  mov     eax, r8d
0x140010916  imul    rcx, r10
0x14001091a  add     rcx, rax
0x14001091d  mov     r8, rcx
0x140010920  mov     [rbp+r9*4+710h+Destination], ecx
0x140010925  shr     r8, 20h
0x140010929  inc     r9d
0x14001092c  cmp     r9d, r14d
0x14001092f  jnz     short loc_14001090E
0x140010931  test    r8d, r8d
0x140010934  jz      short loc_14001095B
0x140010936  cmp     [rbp+710h+var_790], 73h ; 's'
0x14001093a  jnb     short loc_14001094D
0x14001093c  mov     eax, [rbp+710h+var_790]
0x14001093f  mov     [rbp+rax*4+710h+Destination], r8d
0x140010944  mov     r14d, [rbp+710h+var_790]
0x140010948  inc     r14d
0x14001094b  jmp     short loc_1400108EA
0x14001094d  xor     r14d, r14d
0x140010950  mov     [rbp+710h+var_790], r14d
0x140010954  xor     al, al
0x140010956  jmp     loc_140010BC3
0x14001095b  mov     r14d, [rbp+710h+var_790]
0x14001095f  jmp     loc_140010BC1
0x140010964  cmp     r14d, 1
0x140010968  ja      loc_140010A08
0x14001096e  mov     ebx, [rbp+710h+Destination]
0x140010971  mov     r8, rdi
0x140010974  shl     r8, 2
0x140010978  mov     r14d, edi
0x14001097b  mov     [rbp+710h+var_790], edi
0x14001097e  test    r8, r8
0x140010981  jz      short loc_1400109BD
0x140010983  mov     eax, 1CCh
0x140010988  lea     rcx, [rbp+710h+Destination]
0x14001098c  cmp     r8, rax
0x14001098f  ja      short loc_14001099F
0x140010991  lea     rdx, [rbp+710h+Source]
0x140010998  call    sub_1400067F0
0x14001099d  jmp     short loc_1400109B9
0x14001099f  mov     r8, rax
0x1400109a2  xor     edx, edx
0x1400109a4  call    sub_140005B30
0x1400109a9  call    _errno
0x1400109ae  mov     dword ptr [rax], 22h ; '"'
0x1400109b4  call    _invalid_parameter_noinfo
0x1400109b9  mov     r14d, [rbp+710h+var_790]
0x1400109bd  test    ebx, ebx
0x1400109bf  jz      loc_1400108E7
0x1400109c5  cmp     ebx, 1
0x1400109c8  jz      loc_140010BC1
0x1400109ce  test    r14d, r14d
0x1400109d1  jz      loc_140010BC1
0x1400109d7  xor     r8d, r8d
0x1400109da  mov     r10, rbx
0x1400109dd  xor     r9d, r9d
0x1400109e0  mov     ecx, [rbp+r9*4+710h+Destination]
0x1400109e5  mov     eax, r8d
0x1400109e8  imul    rcx, r10
0x1400109ec  add     rcx, rax
0x1400109ef  mov     r8, rcx
0x1400109f2  mov     [rbp+r9*4+710h+Destination], ecx
0x1400109f7  shr     r8, 20h
0x1400109fb  inc     r9d
0x1400109fe  cmp     r9d, r14d
0x140010a01  jnz     short loc_1400109E0
0x140010a03  jmp     loc_140010931
0x140010a08  cmp     edi, r14d
0x140010a0b  lea     rcx, [rbp+710h+Destination]
0x140010a0f  mov     r12d, r14d
0x140010a12  lea     r13, [rbp+710h+Source]
0x140010a19  setb    al
0x140010a1c  lea     rdx, [rbp+710h+Destination]
0x140010a20  test    al, al
0x140010a22  cmovz   r13, rcx
0x140010a26  cmovnz  r12d, edi
0x140010a2a  cmovnz  edi, r14d
0x140010a2e  lea     rcx, [rbp+710h+Source]
0x140010a35  cmovz   rdx, rcx
0x140010a39  xor     r14d, r14d
0x140010a3c  xor     r10d, r10d
0x140010a3f  mov     [rsp+810h+var_7B8], rdx
0x140010a44  mov     [rbp+710h+var_220], r14d
0x140010a4b  test    r12d, r12d
0x140010a4e  jz      loc_140010B6D
0x140010a54  mov     esi, [r13+r10*4+0]
0x140010a59  mov     eax, r10d
0x140010a5c  test    esi, esi
0x140010a5e  jnz     short loc_140010A81
0x140010a60  cmp     r10d, r14d
0x140010a63  jnz     loc_140010B61
0x140010a69  and     dword ptr [rbp+r10*4+710h+var_21C], esi
0x140010a71  lea     r14d, [r10+1]
0x140010a75  mov     [rbp+710h+var_220], r14d
0x140010a7c  jmp     loc_140010B61
0x140010a81  xor     ebx, ebx
0x140010a83  mov     r9d, r10d
0x140010a86  test    edi, edi
0x140010a88  jz      loc_140010B52
0x140010a8e  mov     r11d, r10d
0x140010a91  neg     r11d
0x140010a94  cmp     r9d, 73h ; 's'
0x140010a98  jz      short loc_140010B00
0x140010a9a  cmp     r9d, r14d
0x140010a9d  jnz     short loc_140010ABA
0x140010a9f  mov     eax, r9d
0x140010aa2  lea     ecx, [r9+1]
0x140010aa6  and     dword ptr [rbp+rax*4+710h+var_21C], 0
0x140010aae  lea     eax, [r10+r11]
0x140010ab2  add     ecx, eax
0x140010ab4  mov     [rbp+710h+var_220], ecx
0x140010aba  lea     eax, [r11+r9]
0x140010abe  mov     r8d, r9d
0x140010ac1  mov     edx, [rdx+rax*4]
0x140010ac4  inc     r9d
0x140010ac7  imul    rdx, rsi
0x140010acb  mov     eax, dword ptr [rbp+r8*4+710h+var_21C]
0x140010ad3  add     rdx, rax
0x140010ad6  mov     eax, ebx
0x140010ad8  add     rdx, rax
0x140010adb  lea     eax, [r11+r9]
0x140010adf  mov     rbx, rdx
0x140010ae2  mov     dword ptr [rbp+r8*4+710h+var_21C], edx
0x140010aea  mov     r14d, [rbp+710h+var_220]
0x140010af1  shr     rbx, 20h
0x140010af5  cmp     eax, edi
0x140010af7  jz      short loc_140010B00
0x140010af9  mov     rdx, [rsp+810h+var_7B8]
0x140010afe  jmp     short loc_140010A94
0x140010b00  test    ebx, ebx
0x140010b02  jz      short loc_140010B52
0x140010b04  cmp     r9d, 73h ; 's'
0x140010b08  jz      loc_140010C65
0x140010b0e  cmp     r9d, r14d
0x140010b11  jnz     short loc_140010B28
0x140010b13  mov     eax, r9d
0x140010b16  and     dword ptr [rbp+rax*4+710h+var_21C], 0
0x140010b1e  lea     eax, [r9+1]
0x140010b22  mov     [rbp+710h+var_220], eax
0x140010b28  mov     ecx, r9d
0x140010b2b  inc     r9d
0x140010b2e  mov     eax, ebx
0x140010b30  mov     edx, dword ptr [rbp+rcx*4+710h+var_21C]
0x140010b37  add     rdx, rax
0x140010b3a  mov     dword ptr [rbp+rcx*4+710h+var_21C], edx
0x140010b41  mov     r14d, [rbp+710h+var_220]
0x140010b48  shr     rdx, 20h
0x140010b4c  mov     ebx, edx
0x140010b4e  test    edx, edx
0x140010b50  jnz     short loc_140010B04
0x140010b52  cmp     r9d, 73h ; 's'
0x140010b56  jz      loc_140010C65
0x140010b5c  mov     rdx, [rsp+810h+var_7B8]
0x140010b61  inc     r10d
0x140010b64  cmp     r10d, r12d
0x140010b67  jnz     loc_140010A54
0x140010b6d  mov     r8d, r14d
0x140010b70  shl     r8, 2
0x140010b74  mov     [rbp+710h+var_790], r14d
0x140010b78  test    r8, r8
0x140010b7b  jz      short loc_140010BB7
0x140010b7d  mov     eax, 1CCh
0x140010b82  lea     rcx, [rbp+710h+Destination]
0x140010b86  cmp     r8, rax
0x140010b89  ja      short loc_140010B99
0x140010b8b  lea     rdx, [rbp+710h+var_21C]
0x140010b92  call    sub_1400067F0
0x140010b97  jmp     short loc_140010BB3
0x140010b99  mov     r8, rax
0x140010b9c  xor     edx, edx
0x140010b9e  call    sub_140005B30
0x140010ba3  call    _errno
0x140010ba8  mov     dword ptr [rax], 22h ; '"'
0x140010bae  call    _invalid_parameter_noinfo
0x140010bb3  mov     r14d, [rbp+710h+var_790]
0x140010bb7  mov     r12d, [rsp+810h+var_7D0]
0x140010bbc  mov     r13d, [rsp+810h+var_7C8]
0x140010bc1  mov     al, 1
0x140010bc3  test    al, al
0x140010bc5  jz      loc_140010C65
0x140010bcb  sub     r12d, r13d
0x140010bce  lea     rdx, cs:140000000h
0x140010bd5  mov     [rsp+810h+var_7D0], r12d
0x140010bda  jnz     loc_140010854
0x140010be0  mov     ecx, [rsp+810h+var_7CC]
0x140010be4  xor     r13d, r13d
0x140010be7  mov     eax, dword ptr [rsp+810h+X]
0x140010beb  lea     eax, [rax+rax*4]
0x140010bee  add     eax, eax
0x140010bf0  sub     ecx, eax
0x140010bf2  jz      loc_140010C8F
0x140010bf8  lea     eax, [rcx-1]
0x140010bfb  mov     eax, ds:rva dword_140017BD8[rdx+rax*4]
0x140010c02  test    eax, eax
0x140010c04  jz      short loc_140010C68
0x140010c06  cmp     eax, 1
0x140010c09  jz      loc_140010C8F
0x140010c0f  test    r14d, r14d
0x140010c12  jz      short loc_140010C8F
0x140010c14  mov     r8d, r13d
0x140010c17  mov     r9d, r13d
0x140010c1a  mov     r10d, eax
0x140010c1d  mov     edx, r9d
0x140010c20  inc     r9d
0x140010c23  mov     eax, r8d
0x140010c26  mov     ecx, [rbp+rdx*4+710h+Destination]
0x140010c2a  imul    rcx, r10
0x140010c2e  add     rcx, rax
0x140010c31  mov     r8, rcx
0x140010c34  mov     [rbp+rdx*4+710h+Destination], ecx
0x140010c38  shr     r8, 20h
0x140010c3c  cmp     r9d, r14d
0x140010c3f  jnz     short loc_140010C1D
0x140010c41  test    r8d, r8d
0x140010c44  jz      short loc_140010C8B
0x140010c46  cmp     [rbp+710h+var_790], 73h ; 's'
0x140010c4a  mov     edi, [rsp+810h+var_7E0]
0x140010c4e  jnb     short loc_140010C7D
0x140010c50  mov     eax, [rbp+710h+var_790]
0x140010c53  mov     [rbp+rax*4+710h+Destination], r8d
0x140010c58  mov     r14d, [rbp+710h+var_790]
0x140010c5c  inc     r14d
0x140010c5f  mov     [rbp+710h+var_790], r14d
0x140010c63  jmp     short loc_140010C93
0x140010c65  xor     r13d, r13d
0x140010c68  mov     rsi, [rsp+810h+var_7C0]
0x140010c6d  mov     edi, [rsp+810h+var_7E0]
0x140010c71  mov     rbx, rsi
0x140010c74  mov     [rbp+710h+var_790], r13d
0x140010c78  jmp     loc_140010D04
0x140010c7d  mov     rsi, [rsp+810h+var_7C0]
0x140010c82  mov     rbx, rsi
0x140010c85  mov     [rbp+710h+var_790], r13d
0x140010c89  jmp     short loc_140010D04
0x140010c8b  mov     r14d, [rbp+710h+var_790]
0x140010c8f  mov     edi, [rsp+810h+var_7E0]
0x140010c93  mov     rsi, [rsp+810h+var_7C0]
0x140010c98  mov     rbx, rsi
0x140010c9b  test    r14d, r14d
0x140010c9e  jz      short loc_140010D04
0x140010ca0  mov     r8d, r13d
0x140010ca3  mov     r9d, r13d
0x140010ca6  mov     edx, r9d
0x140010ca9  inc     r9d
0x140010cac  mov     eax, [rbp+rdx*4+710h+Destination]
0x140010cb0  lea     rcx, [rax+rax*4]
0x140010cb4  mov     eax, r8d
0x140010cb7  lea     r8, [rax+rcx*2]
0x140010cbb  mov     [rbp+rdx*4+710h+Destination], r8d
0x140010cc0  shr     r8, 20h
0x140010cc4  cmp     r9d, r14d
0x140010cc7  jnz     short loc_140010CA6
0x140010cc9  test    r8d, r8d
0x140010ccc  jz      short loc_140010D04
0x140010cce  cmp     [rbp+710h+var_790], 73h ; 's'
0x140010cd2  jnb     short loc_140010CE1
0x140010cd4  mov     eax, [rbp+710h+var_790]
0x140010cd7  mov     [rbp+rax*4+710h+Destination], r8d
0x140010cdc  inc     [rbp+710h+var_790]
0x140010cdf  jmp     short loc_140010D04
0x140010ce1  xor     r9d, r9d; SourceSize
0x140010ce4  mov     [rbp+710h+var_3F0], r13d
0x140010ceb  lea     r8, [rbp+710h+Source]; Source
0x140010cf2  mov     [rbp+710h+var_790], r13d
0x140010cf6  mov     edx, 1CCh; DestinationSize
0x140010cfb  lea     rcx, [rbp+710h+Destination]; Destination
0x140010cff  call    memcpy_s
0x140010d04  lea     rdx, [rbp+710h+var_5C0]; struct __crt_strtox::big_integer *
0x140010d0b  lea     rcx, [rbp+710h+var_790]; this
0x140010d0f  call    ?divide@__crt_strtox@@YA_KAEAUbig_integer@1@AEBU21@@Z
0x140010d14  cmp     eax, 0Ah
0x140010d17  jnz     loc_140010DAD
0x140010d1d  inc     edi
0x140010d1f  mov     byte ptr [rsi], 31h ; '1'
0x140010d22  lea     rbx, [rsi+1]
0x140010d26  test    r15d, r15d
0x140010d29  jz      loc_140010DBD
0x140010d2f  mov     r8d, r13d
0x140010d32  mov     r9d, r13d
0x140010d35  mov     edx, r9d
0x140010d38  inc     r9d
0x140010d3b  mov     eax, dword ptr [rbp+rdx*4+710h+var_5BC]
0x140010d42  lea     rcx, [rax+rax*4]
0x140010d46  mov     eax, r8d
0x140010d49  lea     r8, [rax+rcx*2]
0x140010d4d  mov     dword ptr [rbp+rdx*4+710h+var_5BC], r8d
0x140010d55  shr     r8, 20h
0x140010d59  cmp     r9d, r15d
0x140010d5c  jnz     short loc_140010D35
0x140010d5e  test    r8d, r8d
0x140010d61  jz      short loc_140010DBD
0x140010d63  cmp     [rbp+710h+var_5C0], 73h ; 's'
0x140010d6a  jnb     short loc_140010D82
0x140010d6c  mov     eax, [rbp+710h+var_5C0]
0x140010d72  mov     dword ptr [rbp+rax*4+710h+var_5BC], r8d
0x140010d7a  inc     [rbp+710h+var_5C0]
0x140010d80  jmp     short loc_140010DBD
0x140010d82  xor     r9d, r9d; SourceSize
0x140010d85  mov     [rbp+710h+var_3F0], r13d
0x140010d8c  lea     r8, [rbp+710h+Source]; Source
0x140010d93  mov     [rbp+710h+var_5C0], r13d
0x140010d9a  mov     edx, 1CCh; DestinationSize
0x140010d9f  lea     rcx, [rbp+710h+var_5BC]; Destination
0x140010da6  call    memcpy_s
0x140010dab  jmp     short loc_140010DBD
0x140010dad  test    eax, eax
0x140010daf  jnz     short loc_140010DB5
0x140010db1  dec     edi
0x140010db3  jmp     short loc_140010DBD
0x140010db5  add     al, 30h ; '0'
0x140010db7  lea     rbx, [rsi+1]
0x140010dbb  mov     [rsi], al
0x140010dbd  mov     rax, [rsp+810h+var_7A0]
0x140010dc2  mov     ecx, [rsp+810h+var_7C4]
0x140010dc6  mov     [rax+4], edi
0x140010dc9  test    edi, edi
0x140010dcb  js      short loc_140010DD7
0x140010dcd  cmp     ecx, 7FFFFFFFh
0x140010dd3  ja      short loc_140010DD7
0x140010dd5  add     ecx, edi
0x140010dd7  mov     rax, [rbp+710h+SizeInBytes]
0x140010dde  dec     rax
0x140010de1  mov     edi, ecx
0x140010de3  cmp     rax, rdi
0x140010de6  cmovb   rdi, rax
0x140010dea  add     rdi, rsi
0x140010ded  cmp     rbx, rdi
0x140010df0  jz      loc_140010EDE
0x140010df6  mov     r14d, 9
0x140010dfc  or      esi, 0FFFFFFFFh
0x140010dff  mov     r10d, [rbp+710h+var_790]
0x140010e03  test    r10d, r10d
0x140010e06  jz      loc_140010EDE
0x140010e0c  mov     r8d, r13d
0x140010e0f  mov     r9d, r13d
0x140010e12  mov     edx, r9d
0x140010e15  inc     r9d
0x140010e18  mov     eax, [rbp+rdx*4+710h+Destination]
0x140010e1c  imul    rcx, rax, 3B9ACA00h
0x140010e23  mov     eax, r8d
0x140010e26  add     rcx, rax
0x140010e29  mov     r8, rcx
0x140010e2c  mov     [rbp+rdx*4+710h+Destination], ecx
0x140010e30  shr     r8, 20h
0x140010e34  cmp     r9d, r10d
0x140010e37  jnz     short loc_140010E12
0x140010e39  test    r8d, r8d
0x140010e3c  jz      short loc_140010E74
0x140010e3e  cmp     [rbp+710h+var_790], 73h ; 's'
0x140010e42  jnb     short loc_140010E51
0x140010e44  mov     eax, [rbp+710h+var_790]
0x140010e47  mov     [rbp+rax*4+710h+Destination], r8d
0x140010e4c  inc     [rbp+710h+var_790]
0x140010e4f  jmp     short loc_140010E74
0x140010e51  xor     r9d, r9d; SourceSize
0x140010e54  mov     [rbp+710h+var_3F0], r13d
0x140010e5b  lea     r8, [rbp+710h+Source]; Source
0x140010e62  mov     [rbp+710h+var_790], r13d
0x140010e66  mov     edx, 1CCh; DestinationSize
0x140010e6b  lea     rcx, [rbp+710h+Destination]; Destination
0x140010e6f  call    memcpy_s
0x140010e74  lea     rdx, [rbp+710h+var_5C0]; struct __crt_strtox::big_integer *
0x140010e7b  lea     rcx, [rbp+710h+var_790]; this
0x140010e7f  call    ?divide@__crt_strtox@@YA_KAEAUbig_integer@1@AEBU21@@Z
0x140010e84  mov     r10d, edi
0x140010e87  mov     r8, rax
0x140010e8a  sub     r10d, ebx
0x140010e8d  mov     r9d, 8
0x140010e93  mov     eax, 0CCCCCCCDh
0x140010e98  mul     r8d
0x140010e9b  shr     edx, 3
0x140010e9e  mov     cl, dl
0x140010ea0  shl     cl, 2
0x140010ea3  lea     eax, [rcx+rdx]
0x140010ea6  add     al, al
0x140010ea8  sub     r8b, al
0x140010eab  lea     ecx, [r8+30h]
0x140010eaf  mov     r8d, edx
0x140010eb2  cmp     r10d, r9d
0x140010eb5  jb      short loc_140010EBD
0x140010eb7  mov     eax, r9d
0x140010eba  mov     [rax+rbx], cl
0x140010ebd  add     r9d, esi
0x140010ec0  cmp     r9d, esi
0x140010ec3  jnz     short loc_140010E93
0x140010ec5  mov     rax, rdi
0x140010ec8  sub     rax, rbx
0x140010ecb  cmp     rax, r14
0x140010ece  cmovg   rax, r14
0x140010ed2  add     rbx, rax
0x140010ed5  cmp     rbx, rdi
0x140010ed8  jnz     loc_140010DFF
0x140010ede  mov     [rbx], r13b
0x140010ee1  jmp     short loc_140010F5E
0x140010ee3  mov     rdx, [rbp+710h+SizeInBytes]; SizeInBytes
0x140010eea  lea     r8, a1Ind
0x140010ef1  mov     rcx, r14; Destination
0x140010ef4  call    strcpy_s
0x140010ef9  test    eax, eax
0x140010efb  jz      short loc_140010F5E
0x140010efd  jmp     loc_140010FA7
0x140010f02  mov     rdx, [rbp+710h+SizeInBytes]; SizeInBytes
0x140010f09  lea     r8, a1Snan
0x140010f10  mov     rcx, r14; Destination
0x140010f13  call    strcpy_s
0x140010f18  test    eax, eax
0x140010f1a  jz      short loc_140010F5E
0x140010f1c  jmp     loc_140010FBC
0x140010f21  mov     rdx, [rbp+710h+SizeInBytes]; SizeInBytes
0x140010f28  lea     r8, a1Qnan
0x140010f2f  mov     rcx, r14; Destination
0x140010f32  call    strcpy_s
0x140010f37  test    eax, eax
0x140010f39  jz      short loc_140010F5E
0x140010f3b  jmp     loc_140010FD1
0x140010f40  mov     rdx, [rbp+710h+SizeInBytes]; SizeInBytes
0x140010f47  lea     r8, a1Inf
0x140010f4e  mov     rcx, r14; Destination
0x140010f51  call    strcpy_s
0x140010f56  test    eax, eax
0x140010f58  jnz     loc_140010FE6
0x140010f5e  cmp     [rsp+810h+var_7A8], r13b
0x140010f63  jz      short loc_140010F6F
0x140010f65  lea     rcx, [rsp+810h+Env]; Env
0x140010f6a  call    fesetenv
0x140010f6f  mov     rcx, [rbp+710h+var_50]
0x140010f76  xor     rcx, rsp; StackCookie
0x140010f79  call    __security_check_cookie
0x140010f7e  add     rsp, 7D8h
0x140010f85  pop     r15
0x140010f87  pop     r14
0x140010f89  pop     r13
0x140010f8b  pop     r12
0x140010f8d  pop     rdi
0x140010f8e  pop     rsi
0x140010f8f  pop     rbx
0x140010f90  pop     rbp
0x140010f91  retn
0x140010f92  xor     r9d, r9d; LineNo
0x140010f95  mov     [rsp+810h+Reserved], r13; Reserved
0x140010f9a  xor     r8d, r8d; FileName
0x140010f9d  xor     edx, edx; FunctionName
0x140010f9f  xor     ecx, ecx; Expression
0x140010fa1  call    _invoke_watson
0x140010fa7  xor     r9d, r9d; LineNo
0x140010faa  mov     [rsp+810h+Reserved], r13; Reserved
0x140010faf  xor     r8d, r8d; FileName
0x140010fb2  xor     edx, edx; FunctionName
0x140010fb4  xor     ecx, ecx; Expression
0x140010fb6  call    _invoke_watson
0x140010fbc  xor     r9d, r9d; LineNo
0x140010fbf  mov     [rsp+810h+Reserved], r13; Reserved
0x140010fc4  xor     r8d, r8d; FileName
0x140010fc7  xor     edx, edx; FunctionName
0x140010fc9  xor     ecx, ecx; Expression
0x140010fcb  call    _invoke_watson
0x140010fd1  xor     r9d, r9d; LineNo
0x140010fd4  mov     [rsp+810h+Reserved], r13; Reserved
0x140010fd9  xor     r8d, r8d; FileName
0x140010fdc  xor     edx, edx; FunctionName
0x140010fde  xor     ecx, ecx; Expression
0x140010fe0  call    _invoke_watson
0x140010fe6  xor     r9d, r9d; LineNo
0x140010fe9  mov     [rsp+810h+Reserved], r13; Reserved
0x140010fee  xor     r8d, r8d; FileName
0x140010ff1  xor     edx, edx; FunctionName
0x140010ff3  xor     ecx, ecx; Expression
0x140010ff5  call    _invoke_watson

// ===== memcpy_s @ 0x140010ffc =====

0x140010ffc  mov     [rsp+arg_0], rbx
0x140011001  mov     [rsp+arg_8], rsi
0x140011006  push    rdi
0x140011007  sub     rsp, 20h
0x14001100b  mov     rbx, r9
0x14001100e  mov     rsi, r8
0x140011011  mov     rdi, rdx
0x140011014  test    r9, r9
0x140011017  jnz     short loc_14001101D
0x140011019  xor     eax, eax
0x14001101b  jmp     short loc_140011073
0x14001101d  test    rcx, rcx
0x140011020  jnz     short loc_140011037
0x140011022  call    _errno
0x140011027  mov     ebx, 16h
0x14001102c  mov     [rax], ebx
0x14001102e  call    _invalid_parameter_noinfo
0x140011033  mov     eax, ebx
0x140011035  jmp     short loc_140011073
0x140011037  test    r8, r8
0x14001103a  jz      short loc_14001104E
0x14001103c  cmp     rdx, rbx
0x14001103f  jb      short loc_14001104E
0x140011041  mov     r8, rbx
0x140011044  mov     rdx, rsi
0x140011047  call    sub_1400067F0
0x14001104c  jmp     short loc_140011019
0x14001104e  mov     r8, rdx
0x140011051  xor     edx, edx
0x140011053  call    sub_140005B30
0x140011058  test    rsi, rsi
0x14001105b  jz      short loc_140011022
0x14001105d  cmp     rdi, rbx
0x140011060  jnb     short loc_14001106E
0x140011062  call    _errno
0x140011067  mov     ebx, 22h ; '"'
0x14001106c  jmp     short loc_14001102C
0x14001106e  mov     eax, 16h
0x140011073  mov     rbx, [rsp+28h+arg_0]
0x140011078  mov     rsi, [rsp+28h+arg_8]
0x14001107d  add     rsp, 20h
0x140011081  pop     rdi
0x140011082  retn

// ===== _fcloseall @ 0x140011084 =====

0x140011084  mov     [rsp+arg_0], rbx
0x140011089  push    rdi
0x14001108a  sub     rsp, 30h
0x14001108e  and     [rsp+38h+var_18], 0
0x140011093  mov     ecx, 8
0x140011098  call    sub_14000D540
0x14001109d  nop
0x14001109e  mov     ebx, 3
0x1400110a3  mov     [rsp+38h+var_14], ebx
0x1400110a7  cmp     ebx, cs:dword_1400217C8
0x1400110ad  jz      short loc_14001111D
0x1400110af  movsxd  rdi, ebx
0x1400110b2  mov     rax, cs:qword_1400217D0
0x1400110b9  mov     rax, [rax+rdi*8]
0x1400110bd  test    rax, rax
0x1400110c0  jnz     short loc_1400110C4
0x1400110c2  jmp     short loc_140011119
0x1400110c4  mov     ecx, [rax+14h]
0x1400110c7  shr     ecx, 0Dh
0x1400110ca  test    cl, 1
0x1400110cd  jz      short loc_1400110E8
0x1400110cf  mov     rcx, cs:qword_1400217D0
0x1400110d6  mov     rcx, [rcx+rdi*8]; Stream
0x1400110da  call    fclose
0x1400110df  cmp     eax, 0FFFFFFFFh
0x1400110e2  jz      short loc_1400110E8
0x1400110e4  inc     [rsp+38h+var_18]
0x1400110e8  mov     rax, cs:qword_1400217D0
0x1400110ef  mov     rcx, [rax+rdi*8]
0x1400110f3  add     rcx, 30h ; '0'; lpCriticalSection
0x1400110f7  call    cs:DeleteCriticalSection; KERNEL32
0x1400110fd  mov     rcx, cs:qword_1400217D0
0x140011104  mov     rcx, [rcx+rdi*8]; Block
0x140011108  call    _free_base
0x14001110d  mov     rax, cs:qword_1400217D0
0x140011114  and     qword ptr [rax+rdi*8], 0
0x140011119  inc     ebx
0x14001111b  jmp     short loc_1400110A3
0x14001111d  mov     ecx, 8
0x140011122  call    sub_14000D594
0x140011127  mov     eax, [rsp+38h+var_18]
0x14001112b  mov     rbx, [rsp+38h+arg_0]
0x140011130  add     rsp, 30h
0x140011134  pop     rdi
0x140011135  retn
0x140013ad3  push    rbp; Microsoft VisualC 64bit universal runtime
0x140013ad5  sub     rsp, 20h
0x140013ad9  mov     rbp, rdx
0x140013adc  mov     ecx, 8
0x140013ae1  add     rsp, 20h
0x140013ae5  pop     rbp
0x140013ae6  jmp     sub_14000D594

// ===== _isatty @ 0x140011138 =====

0x140011138  sub     rsp, 28h
0x14001113c  cmp     ecx, 0FFFFFFFEh
0x14001113f  jnz     short loc_14001114E
0x140011141  call    _errno
0x140011146  mov     dword ptr [rax], 9
0x14001114c  jmp     short loc_140011190
0x14001114e  test    ecx, ecx
0x140011150  js      short loc_140011180
0x140011152  cmp     ecx, cs:dword_140021BF0
0x140011158  jnb     short loc_140011180
0x14001115a  movsxd  rcx, ecx
0x14001115d  lea     rdx, qword_1400217F0
0x140011164  mov     rax, rcx
0x140011167  and     ecx, 3Fh
0x14001116a  sar     rax, 6
0x14001116e  shl     rcx, 6
0x140011172  mov     rax, [rdx+rax*8]
0x140011176  movzx   eax, byte ptr [rax+rcx+38h]
0x14001117b  and     eax, 40h
0x14001117e  jmp     short loc_140011192
0x140011180  call    _errno
0x140011185  mov     dword ptr [rax], 9
0x14001118b  call    _invalid_parameter_noinfo
0x140011190  xor     eax, eax
0x140011192  add     rsp, 28h
0x140011196  retn

// ===== ?shortsort@@YAXPEAD0_KP6AHPEBX2@Z@Z @ 0x1400111a0 =====

0x1400111a0  cmp     rdx, rcx
0x1400111a3  jbe     locret_14001126B
0x1400111a9  mov     [rsp+arg_18], rbp
0x1400111ae  push    rdi
0x1400111af  push    r14
0x1400111b1  push    r15
0x1400111b3  sub     rsp, 20h
0x1400111b7  mov     [rsp+38h+arg_0], rbx
0x1400111bc  mov     r14, r9
0x1400111bf  mov     [rsp+38h+arg_8], rsi
0x1400111c4  mov     rbp, r8
0x1400111c7  mov     [rsp+38h+arg_10], r12
0x1400111cc  mov     rdi, rdx
0x1400111cf  lea     r12, [rcx+r8]
0x1400111d3  mov     r15, rcx
0x1400111d6  nop     word ptr [rax+rax+00000000h]
0x1400111e0  mov     rbx, r15
0x1400111e3  mov     rsi, r12
0x1400111e6  cmp     r12, rdi
0x1400111e9  ja      short loc_140011210
0x1400111eb  nop     dword ptr [rax+rax+00h]
0x1400111f0  mov     rcx, r14
0x1400111f3  call    cs:__guard_check_icall_fptr
0x1400111f9  mov     rdx, rbx
0x1400111fc  mov     rcx, rsi
0x1400111ff  call    r14
0x140011202  test    eax, eax
0x140011204  cmovg   rbx, rsi
0x140011208  add     rsi, rbp
0x14001120b  cmp     rsi, rdi
0x14001120e  jbe     short loc_1400111F0
0x140011210  mov     r8, rbp
0x140011213  mov     rax, rdi
0x140011216  cmp     rbx, rdi
0x140011219  jz      short loc_140011246
0x14001121b  test    rbp, rbp
0x14001121e  jz      short loc_140011246
0x140011220  sub     rbx, rdi
0x140011223  nop     dword ptr [rax+00h]
0x140011227  nop     word ptr [rax+rax+00000000h]
0x140011230  movzx   ecx, byte ptr [rax]
0x140011233  movzx   edx, byte ptr [rbx+rax]
0x140011237  mov     [rbx+rax], cl
0x14001123a  mov     [rax], dl
0x14001123c  lea     rax, [rax+1]
0x140011240  sub     r8, 1
0x140011244  jnz     short loc_140011230
0x140011246  sub     rdi, rbp
0x140011249  cmp     rdi, r15
0x14001124c  ja      short loc_1400111E0
0x14001124e  mov     r12, [rsp+38h+arg_10]
0x140011253  mov     rsi, [rsp+38h+arg_8]
0x140011258  mov     rbx, [rsp+38h+arg_0]
0x14001125d  mov     rbp, [rsp+38h+arg_18]
0x140011262  add     rsp, 20h
0x140011266  pop     r15
0x140011268  pop     r14
0x14001126a  pop     rdi
0x14001126b  retn

// ===== qsort @ 0x140011270 =====

0x140011270  push    rbp
0x140011272  push    r12
0x140011274  push    r14
0x140011276  sub     rsp, 440h
0x14001127d  mov     rax, cs:__security_cookie
0x140011284  xor     rax, rsp
0x140011287  mov     [rsp+458h+var_58], rax
0x14001128f  mov     r14, r9
0x140011292  mov     rbp, r8
0x140011295  mov     r12, rcx
0x140011298  test    rcx, rcx
0x14001129b  jnz     short loc_1400112B7
0x14001129d  test    rdx, rdx
0x1400112a0  jz      short loc_1400112B7
0x1400112a2  call    _errno
0x1400112a7  mov     dword ptr [rax], 16h
0x1400112ad  call    _invalid_parameter_noinfo
0x1400112b2  jmp     loc_140011587
0x1400112b7  test    r8, r8
0x1400112ba  jz      short loc_1400112A2
0x1400112bc  test    r9, r9
0x1400112bf  jz      short loc_1400112A2
0x1400112c1  cmp     rdx, 2
0x1400112c5  jb      loc_140011587
0x1400112cb  mov     [rsp+458h+var_20], rbx
0x1400112d3  mov     [rsp+458h+var_28], rsi
0x1400112db  mov     [rsp+458h+var_30], rdi
0x1400112e3  mov     [rsp+458h+var_38], r13
0x1400112eb  mov     [rsp+458h+var_40], r15
0x1400112f3  lea     r15, [rdx-1]
0x1400112f7  imul    r15, rbp
0x1400112fb  add     r15, rcx
0x1400112fe  xor     r13d, r13d
0x140011301  xor     edx, edx
0x140011303  mov     rax, r15
0x140011306  sub     rax, r12
0x140011309  div     rbp
0x14001130c  lea     rsi, [rax+1]
0x140011310  cmp     rsi, 8
0x140011314  ja      short loc_140011340
0x140011316  mov     r9, r14; int (*)(const void *, const void *)
0x140011319  mov     r8, rbp; unsigned __int64
0x14001131c  mov     rdx, r15; char *
0x14001131f  mov     rcx, r12; char *
0x140011322  call    ?shortsort@@YAXPEAD0_KP6AHPEBX2@Z@Z
0x140011327  sub     r13, 1
0x14001132b  js      loc_14001155F
0x140011331  mov     r12, [rsp+r13*8+458h+var_438]
0x140011336  mov     r15, [rsp+r13*8+458h+var_248]
0x14001133e  jmp     short $recurse$173
0x140011340  shr     rsi, 1
0x140011343  mov     rcx, r14
0x140011346  imul    rsi, rbp
0x14001134a  add     rsi, r12
0x14001134d  call    cs:__guard_check_icall_fptr
0x140011353  mov     rdx, rsi
0x140011356  mov     rcx, r12
0x140011359  call    r14
0x14001135c  test    eax, eax
0x14001135e  jle     short loc_140011389
0x140011360  mov     r8, rbp
0x140011363  mov     rdx, rsi
0x140011366  cmp     r12, rsi
0x140011369  jz      short loc_140011389
0x14001136b  mov     r9, r12
0x14001136e  sub     r9, rsi
0x140011371  movzx   eax, byte ptr [rdx]
0x140011374  movzx   ecx, byte ptr [r9+rdx]
0x140011379  mov     [r9+rdx], al
0x14001137d  mov     [rdx], cl
0x14001137f  lea     rdx, [rdx+1]
0x140011383  sub     r8, 1
0x140011387  jnz     short loc_140011371
0x140011389  mov     rcx, r14
0x14001138c  call    cs:__guard_check_icall_fptr
0x140011392  mov     rdx, r15
0x140011395  mov     rcx, r12
0x140011398  call    r14
0x14001139b  test    eax, eax
0x14001139d  jle     short loc_1400113C8
0x14001139f  mov     r8, rbp
0x1400113a2  mov     rdx, r15
0x1400113a5  cmp     r12, r15
0x1400113a8  jz      short loc_1400113C8
0x1400113aa  mov     r9, r12
0x1400113ad  sub     r9, r15
0x1400113b0  movzx   eax, byte ptr [rdx]
0x1400113b3  movzx   ecx, byte ptr [r9+rdx]
0x1400113b8  mov     [r9+rdx], al
0x1400113bc  mov     [rdx], cl
0x1400113be  lea     rdx, [rdx+1]
0x1400113c2  sub     r8, 1
0x1400113c6  jnz     short loc_1400113B0
0x1400113c8  mov     rcx, r14
0x1400113cb  call    cs:__guard_check_icall_fptr
0x1400113d1  mov     rdx, r15
0x1400113d4  mov     rcx, rsi
0x1400113d7  call    r14
0x1400113da  test    eax, eax
0x1400113dc  jle     short loc_140011408
0x1400113de  mov     r8, rbp
0x1400113e1  mov     rdx, r15
0x1400113e4  cmp     rsi, r15
0x1400113e7  jz      short loc_140011408
0x1400113e9  mov     r9, rsi
0x1400113ec  sub     r9, r15
0x1400113ef  nop
0x1400113f0  movzx   eax, byte ptr [rdx]
0x1400113f3  movzx   ecx, byte ptr [r9+rdx]
0x1400113f8  mov     [r9+rdx], al
0x1400113fc  mov     [rdx], cl
0x1400113fe  lea     rdx, [rdx+1]
0x140011402  sub     r8, 1
0x140011406  jnz     short loc_1400113F0
0x140011408  mov     rbx, r12
0x14001140b  mov     rdi, r15
0x14001140e  xchg    ax, ax
0x140011410  cmp     rsi, rbx
0x140011413  jbe     short loc_140011438
0x140011415  add     rbx, rbp
0x140011418  cmp     rbx, rsi
0x14001141b  jnb     short loc_140011438
0x14001141d  mov     rcx, r14
0x140011420  call    cs:__guard_check_icall_fptr
0x140011426  mov     rdx, rsi
0x140011429  mov     rcx, rbx
0x14001142c  call    r14
0x14001142f  test    eax, eax
0x140011431  jle     short loc_140011415
0x140011433  cmp     rsi, rbx
0x140011436  ja      short loc_140011456
0x140011438  add     rbx, rbp
0x14001143b  cmp     rbx, r15
0x14001143e  ja      short loc_140011456
0x140011440  mov     rcx, r14
0x140011443  call    cs:__guard_check_icall_fptr
0x140011449  mov     rdx, rsi
0x14001144c  mov     rcx, rbx
0x14001144f  call    r14
0x140011452  test    eax, eax
0x140011454  jle     short loc_140011438
0x140011456  sub     rdi, rbp
0x140011459  cmp     rdi, rsi
0x14001145c  jbe     short loc_140011474
0x14001145e  mov     rcx, r14
0x140011461  call    cs:__guard_check_icall_fptr
0x140011467  mov     rdx, rsi
0x14001146a  mov     rcx, rdi
0x14001146d  call    r14
0x140011470  test    eax, eax
0x140011472  jg      short loc_140011456
0x140011474  cmp     rdi, rbx
0x140011477  jb      short loc_1400114B9
0x140011479  mov     r8, rbp
0x14001147c  mov     rdx, rdi
0x14001147f  cmp     rbx, rdi
0x140011482  jz      short loc_1400114A8
0x140011484  mov     r9, rbx
0x140011487  sub     r9, rdi
0x14001148a  nop     word ptr [rax+rax+00h]
0x140011490  movzx   eax, byte ptr [rdx]
0x140011493  movzx   ecx, byte ptr [r9+rdx]
0x140011498  mov     [r9+rdx], al
0x14001149c  mov     [rdx], cl
0x14001149e  lea     rdx, [rdx+1]
0x1400114a2  sub     r8, 1
0x1400114a6  jnz     short loc_140011490
0x1400114a8  cmp     rsi, rdi
0x1400114ab  jnz     loc_140011410
0x1400114b1  mov     rsi, rbx
0x1400114b4  jmp     loc_140011410
0x1400114b9  add     rdi, rbp
0x1400114bc  cmp     rsi, rdi
0x1400114bf  jnb     short loc_1400114E4
0x1400114c1  sub     rdi, rbp
0x1400114c4  cmp     rdi, rsi
0x1400114c7  jbe     short loc_1400114E4
0x1400114c9  mov     rcx, r14
0x1400114cc  call    cs:__guard_check_icall_fptr
0x1400114d2  mov     rdx, rsi
0x1400114d5  mov     rcx, rdi
0x1400114d8  call    r14
0x1400114db  test    eax, eax
0x1400114dd  jz      short loc_1400114C1
0x1400114df  cmp     rsi, rdi
0x1400114e2  jb      short loc_140011502
0x1400114e4  sub     rdi, rbp
0x1400114e7  cmp     rdi, r12
0x1400114ea  jbe     short loc_140011502
0x1400114ec  mov     rcx, r14
0x1400114ef  call    cs:__guard_check_icall_fptr
0x1400114f5  mov     rdx, rsi
0x1400114f8  mov     rcx, rdi
0x1400114fb  call    r14
0x1400114fe  test    eax, eax
0x140011500  jz      short loc_1400114E4
0x140011502  mov     rcx, r15
0x140011505  mov     rax, rdi
0x140011508  sub     rcx, rbx
0x14001150b  sub     rax, r12
0x14001150e  cmp     rax, rcx
0x140011511  jl      short loc_140011539
0x140011513  cmp     r12, rdi
0x140011516  jnb     short loc_140011528
0x140011518  mov     [rsp+r13*8+458h+var_438], r12
0x14001151d  mov     [rsp+r13*8+458h+var_248], rdi
0x140011525  inc     r13
0x140011528  cmp     rbx, r15
0x14001152b  jnb     loc_140011327
0x140011531  mov     r12, rbx
0x140011534  jmp     $recurse$173
0x140011539  cmp     rbx, r15
0x14001153c  jnb     short loc_14001154E
0x14001153e  mov     [rsp+r13*8+458h+var_438], rbx
0x140011543  mov     [rsp+r13*8+458h+var_248], r15
0x14001154b  inc     r13
0x14001154e  cmp     r12, rdi
0x140011551  jnb     loc_140011327
0x140011557  mov     r15, rdi
0x14001155a  jmp     $recurse$173
0x14001155f  mov     r13, [rsp+458h+var_38]
0x140011567  mov     rdi, [rsp+458h+var_30]
0x14001156f  mov     rsi, [rsp+458h+var_28]
0x140011577  mov     rbx, [rsp+458h+var_20]
0x14001157f  mov     r15, [rsp+458h+var_40]
0x140011587  mov     rcx, [rsp+458h+var_58]
0x14001158f  xor     rcx, rsp; StackCookie
0x140011592  call    __security_check_cookie
0x140011597  add     rsp, 440h
0x14001159e  pop     r14
0x1400115a0  pop     r12
0x1400115a2  pop     rbp
0x1400115a3  retn

// ===== ?initialize_multibyte@@YAHXZ @ 0x1400115a4 =====

0x1400115a4  sub     rsp, 28h
0x1400115a8  call    __acrt_initialize_multibyte
0x1400115ad  xor     ecx, ecx
0x1400115af  test    al, al
0x1400115b1  setz    cl
0x1400115b4  mov     eax, ecx
0x1400115b6  add     rsp, 28h
0x1400115ba  retn

// ===== ?GetTableIndexFromLocaleName@@YAHPEB_W@Z @ 0x1400115bc =====

0x1400115bc  mov     rax, rsp
0x1400115bf  mov     [rax+8], rbx
0x1400115c3  mov     [rax+10h], rbp
0x1400115c7  mov     [rax+18h], rsi
0x1400115cb  mov     [rax+20h], rdi
0x1400115cf  push    r14
0x1400115d1  xor     ebp, ebp
0x1400115d3  lea     r14, off_140019680
0x1400115da  mov     r10d, ebp
0x1400115dd  mov     rsi, rcx
0x1400115e0  mov     r11d, 0E3h
0x1400115e6  lea     eax, [r11+r10]
0x1400115ea  mov     rdi, rsi
0x1400115ed  cdq
0x1400115ee  mov     ebx, 55h ; 'U'
0x1400115f3  sub     eax, edx
0x1400115f5  sar     eax, 1
0x1400115f7  movsxd  r8, eax
0x1400115fa  mov     rcx, r8
0x1400115fd  shl     rcx, 4
0x140011601  mov     r9, [rcx+r14]
0x140011605  sub     rdi, r9
0x140011608  movzx   edx, word ptr [rdi+r9]
0x14001160d  lea     ecx, [rdx-41h]
0x140011610  cmp     cx, 19h
0x140011614  ja      short loc_14001161A
0x140011616  add     dx, 20h ; ' '
0x14001161a  movzx   ecx, word ptr [r9]
0x14001161e  lea     eax, [rcx-41h]
0x140011621  cmp     ax, 19h
0x140011625  ja      short loc_14001162B
0x140011627  add     cx, 20h ; ' '
0x14001162b  add     r9, 2
0x14001162f  sub     rbx, 1
0x140011633  jz      short loc_14001163F
0x140011635  test    dx, dx
0x140011638  jz      short loc_14001163F
0x14001163a  cmp     dx, cx
0x14001163d  jz      short loc_140011608
0x14001163f  movzx   eax, cx
0x140011642  movzx   ecx, dx
0x140011645  sub     ecx, eax
0x140011647  jz      short loc_140011661
0x140011649  test    ecx, ecx
0x14001164b  jns     short loc_140011653
0x14001164d  lea     r11d, [r8-1]
0x140011651  jmp     short loc_140011657
0x140011653  lea     r10d, [r8+1]
0x140011657  cmp     r10d, r11d
0x14001165a  jle     short loc_1400115E6
0x14001165c  or      eax, 0FFFFFFFFh
0x14001165f  jmp     short loc_14001166C
0x140011661  mov     rax, r8
0x140011664  add     rax, rax
0x140011667  mov     eax, [r14+rax*8+8]
0x14001166c  mov     rbx, [rsp+8+arg_0]
0x140011671  mov     rbp, [rsp+8+arg_8]
0x140011676  mov     rsi, [rsp+8+arg_10]
0x14001167b  mov     rdi, [rsp+8+arg_18]
0x140011680  pop     r14
0x140011682  retn

// ===== __crtDownlevelLocaleNameToLCID @ 0x140011684 =====

0x140011684  sub     rsp, 28h
0x140011688  test    rcx, rcx
0x14001168b  jz      short loc_1400116AF
0x14001168d  call    ?GetTableIndexFromLocaleName@@YAHPEB_W@Z
0x140011692  test    eax, eax
0x140011694  js      short loc_1400116AF
0x140011696  cdqe
0x140011698  cmp     rax, 0E4h
0x14001169e  jnb     short loc_1400116AF
0x1400116a0  add     rax, rax
0x1400116a3  lea     rcx, unk_140017C20
0x1400116aa  mov     eax, [rcx+rax*8]
0x1400116ad  jmp     short loc_1400116B1
0x1400116af  xor     eax, eax
0x1400116b1  add     rsp, 28h
0x1400116b5  retn

// ===== _msize @ 0x1400116b8 =====

0x1400116b8  sub     rsp, 28h
0x1400116bc  test    rcx, rcx
0x1400116bf  jnz     short loc_1400116DA
0x1400116c1  call    _errno
0x1400116c6  mov     dword ptr [rax], 16h
0x1400116cc  call    _invalid_parameter_noinfo
0x1400116d1  or      rax, 0FFFFFFFFFFFFFFFFh
0x1400116d5  add     rsp, 28h
0x1400116d9  retn
0x1400116da  mov     r8, rcx
0x1400116dd  xor     edx, edx
0x1400116df  mov     rcx, cs:hHeap
0x1400116e6  add     rsp, 28h
0x1400116ea  jmp     cs:HeapSize; KERNEL32

// ===== _realloc_base @ 0x1400116f4 =====

0x1400116f4  mov     [rsp+arg_0], rbx
0x1400116f9  push    rdi
0x1400116fa  sub     rsp, 20h
0x1400116fe  mov     rbx, rdx
0x140011701  mov     rdi, rcx
0x140011704  test    rcx, rcx
0x140011707  jnz     short loc_140011713
0x140011709  mov     rcx, rdx; Size
0x14001170c  call    _malloc_base
0x140011711  jmp     short loc_14001176B
0x140011713  test    rdx, rdx
0x140011716  jnz     short loc_14001171F
0x140011718  call    _free_base
0x14001171d  jmp     short loc_140011769
0x14001171f  cmp     rdx, 0FFFFFFFFFFFFFFE0h
0x140011723  ja      short loc_14001175E
0x140011725  mov     r9, rdx
0x140011728  mov     r8, rcx
0x14001172b  jmp     short loc_140011748
0x14001172d  call    sub_140009208
0x140011732  test    eax, eax
0x140011734  jz      short loc_14001175E
0x140011736  mov     rcx, rbx; Size
0x140011739  call    _callnewh
0x14001173e  test    eax, eax
0x140011740  jz      short loc_14001175E
0x140011742  mov     r9, rbx; dwBytes
0x140011745  mov     r8, rdi; lpMem
0x140011748  mov     rcx, cs:hHeap; hHeap
0x14001174f  xor     edx, edx; dwFlags
0x140011751  call    cs:HeapReAlloc; KERNEL32
0x140011757  test    rax, rax
0x14001175a  jz      short loc_14001172D
0x14001175c  jmp     short loc_14001176B
0x14001175e  call    _errno
0x140011763  mov     dword ptr [rax], 0Ch
0x140011769  xor     eax, eax
0x14001176b  mov     rbx, [rsp+28h+arg_0]
0x140011770  add     rsp, 20h
0x140011774  pop     rdi
0x140011775  retn

// ===== ??$?RV_lambda_b521505b218e5242e90febf6bfebc422_@@AEAV_lambda_6978c1fb23f02e42e1d9e99668cc68aa_@@V_lambda_314360699dd331753a4119843814e9a7_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b521505b218e5242e90febf6bfebc422_@@AEAV_lambda_6978c1fb23f02e42e1d9e99668cc68aa_@@$$QEAV_lambda_314360699dd331753a4119843814e9a7_@@@Z @ 0x140011778 =====

0x140011778  mov     [rsp+arg_0], rbx
0x14001177d  mov     [rsp+arg_18], r9
0x140011782  push    rdi
0x140011783  sub     rsp, 20h
0x140011787  mov     rdi, r9
0x14001178a  mov     rbx, r8
0x14001178d  mov     ecx, [rdx]
0x14001178f  call    sub_14000DD34
0x140011794  nop
0x140011795  mov     rax, [rbx]
0x140011798  movsxd  rcx, dword ptr [rax]; FileHandle
0x14001179b  mov     rdx, rcx
0x14001179e  mov     rax, rcx
0x1400117a1  sar     rax, 6
0x1400117a5  lea     r8, qword_1400217F0
0x1400117ac  and     edx, 3Fh
0x1400117af  shl     rdx, 6
0x1400117b3  mov     rax, [r8+rax*8]
0x1400117b7  test    byte ptr [rax+rdx+38h], 1
0x1400117bc  jz      short loc_1400117E2
0x1400117be  call    _get_osfhandle
0x1400117c3  mov     rcx, rax; hFile
0x1400117c6  call    cs:FlushFileBuffers; KERNEL32
0x1400117cc  xor     ebx, ebx
0x1400117ce  test    eax, eax
0x1400117d0  jnz     short loc_1400117F0
0x1400117d2  call    __doserrno
0x1400117d7  mov     rbx, rax
0x1400117da  call    cs:GetLastError; KERNEL32
0x1400117e0  mov     [rbx], eax
0x1400117e2  call    _errno
0x1400117e7  mov     dword ptr [rax], 9
0x1400117ed  or      ebx, 0FFFFFFFFh
0x1400117f0  mov     ecx, [rdi]
0x1400117f2  call    sub_14000DD58
0x1400117f7  mov     eax, ebx
0x1400117f9  mov     rbx, [rsp+28h+arg_0]
0x1400117fe  add     rsp, 20h
0x140011802  pop     rdi
0x140011803  retn
0x140013a86  push    rbp
0x140013a88  sub     rsp, 20h
0x140013a8c  mov     rbp, rdx
0x140013a8f  mov     rax, [rbp+48h]
0x140013a93  mov     ecx, [rax]
0x140013a95  add     rsp, 20h
0x140013a99  pop     rbp
0x140013a9a  jmp     sub_14000DD58

// ===== _commit @ 0x140011804 =====

0x140011804  mov     [rsp+arg_0], ecx
0x140011808  sub     rsp, 38h
0x14001180c  movsxd  rdx, ecx
0x14001180f  cmp     edx, 0FFFFFFFEh
0x140011812  jnz     short loc_140011821
0x140011814  call    _errno
0x140011819  mov     dword ptr [rax], 9
0x14001181f  jmp     short loc_14001188D
0x140011821  test    ecx, ecx
0x140011823  js      short loc_14001187D
0x140011825  cmp     edx, cs:dword_140021BF0
0x14001182b  jnb     short loc_14001187D
0x14001182d  mov     rcx, rdx
0x140011830  lea     r8, qword_1400217F0
0x140011837  and     ecx, 3Fh
0x14001183a  mov     rax, rdx
0x14001183d  sar     rax, 6
0x140011841  shl     rcx, 6
0x140011845  mov     rax, [r8+rax*8]
0x140011849  test    byte ptr [rax+rcx+38h], 1
0x14001184e  jz      short loc_14001187D
0x140011850  lea     rax, [rsp+38h+arg_0]
0x140011855  mov     [rsp+38h+arg_10], edx
0x140011859  mov     [rsp+38h+arg_18], edx
0x14001185d  lea     r9, [rsp+38h+arg_10]
0x140011862  lea     rdx, [rsp+38h+arg_18]
0x140011867  mov     [rsp+38h+var_18], rax
0x14001186c  lea     r8, [rsp+38h+var_18]
0x140011871  lea     rcx, [rsp+38h+arg_8]
0x140011876  call    ??$?RV_lambda_b521505b218e5242e90febf6bfebc422_@@AEAV_lambda_6978c1fb23f02e42e1d9e99668cc68aa_@@V_lambda_314360699dd331753a4119843814e9a7_@@@?$__crt_seh_guarded_call@H@@QEAAH$$QEAV_lambda_b521505b218e5242e90febf6bfebc422_@@AEAV_lambda_6978c1fb23f02e42e1d9e99668cc68aa_@@$$QEAV_lambda_314360699dd331753a4119843814e9a7_@@@Z
0x14001187b  jmp     short loc_140011890
0x14001187d  call    _errno
0x140011882  mov     dword ptr [rax], 9
0x140011888  call    _invalid_parameter_noinfo
0x14001188d  or      eax, 0FFFFFFFFh
0x140011890  add     rsp, 38h
0x140011894  retn

// ===== ?write_double_translated_ansi_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x140011898 =====

0x140011898  mov     [rsp-38h+arg_0], rbx
0x14001189d  push    rbp
0x14001189e  push    rsi
0x14001189f  push    rdi
0x1400118a0  push    r12
0x1400118a2  push    r13
0x1400118a4  push    r14
0x1400118a6  push    r15
0x1400118a8  mov     rbp, rsp
0x1400118ab  sub     rsp, 80h
0x1400118b2  mov     rax, cs:__security_cookie
0x1400118b9  xor     rax, rsp
0x1400118bc  mov     [rbp+var_10], rax
0x1400118c0  movsxd  rsi, edx
0x1400118c3  lea     rax, qword_1400217F0
0x1400118ca  mov     r15, rsi
0x1400118cd  mov     r12d, r9d
0x1400118d0  sar     r15, 6
0x1400118d4  and     esi, 3Fh
0x1400118d7  shl     rsi, 6
0x1400118db  mov     r14, r8
0x1400118de  mov     [rbp+var_28], r8
0x1400118e2  mov     rbx, rcx
0x1400118e5  add     r12, r8
0x1400118e8  mov     rax, [rax+r15*8]
0x1400118ec  mov     rax, [rax+rsi+28h]
0x1400118f1  mov     [rbp+hFile], rax
0x1400118f5  call    cs:GetConsoleCP; KERNEL32
0x1400118fb  xor     edx, edx
0x1400118fd  mov     [rbp+CodePage], eax
0x140011900  mov     [rbx], rdx
0x140011903  mov     rdi, r14
0x140011906  mov     [rbx+8], edx
0x140011909  cmp     r14, r12
0x14001190c  jnb     loc_140011A76
0x140011912  mov     r13b, [rdi]
0x140011915  lea     r14, qword_1400217F0
0x14001191c  mov     [rbp+WideCharStr], dx
0x140011920  mov     rdx, [r14+r15*8]
0x140011924  mov     cl, [rdx+rsi+3Dh]
0x140011928  test    cl, 4
0x14001192b  jz      short loc_14001194B
0x14001192d  mov     al, [rdx+rsi+3Eh]
0x140011931  and     cl, 0FBh
0x140011934  mov     [rdx+rsi+3Dh], cl
0x140011938  mov     r8d, 2
0x14001193e  lea     rdx, [rbp+var_20]
0x140011942  mov     [rbp+var_20], al
0x140011945  mov     [rbp+var_1F], r13b
0x140011949  jmp     short loc_140011990
0x14001194b  call    __pctype_func
0x140011950  movzx   ecx, byte ptr [rdi]
0x140011953  mov     edx, 8000h
0x140011958  test    [rax+rcx*2], dx
0x14001195c  jz      short loc_140011987
0x14001195e  cmp     rdi, r12
0x140011961  jnb     loc_140011A56
0x140011967  mov     r8d, 2; SrcSizeInBytes
0x14001196d  lea     rcx, [rbp+WideCharStr]; DstCh
0x140011971  mov     rdx, rdi; SrcCh
0x140011974  call    mbtowc
0x140011979  cmp     eax, 0FFFFFFFFh
0x14001197c  jz      loc_140011A76
0x140011982  inc     rdi
0x140011985  jmp     short loc_1400119A2
0x140011987  mov     r8d, 1; SrcSizeInBytes
0x14001198d  mov     rdx, rdi; SrcCh
0x140011990  lea     rcx, [rbp+WideCharStr]; DstCh
0x140011994  call    mbtowc
0x140011999  cmp     eax, 0FFFFFFFFh
0x14001199c  jz      loc_140011A76
0x1400119a2  and     [rsp+80h+var_48], 0
0x1400119a8  lea     rax, [rbp+MultiByteStr]
0x1400119ac  and     [rsp+80h+var_50], 0
0x1400119b2  lea     r8, [rbp+WideCharStr]; lpWideCharStr
0x1400119b6  mov     ecx, [rbp+CodePage]; CodePage
0x1400119b9  mov     r9d, 1; cchWideChar
0x1400119bf  mov     [rsp+80h+cbMultiByte], 5; cbMultiByte
0x1400119c7  xor     edx, edx; dwFlags
0x1400119c9  mov     [rsp+80h+lpMultiByteStr], rax; lpOverlapped
0x1400119ce  inc     rdi
0x1400119d1  call    cs:WideCharToMultiByte; KERNEL32
0x1400119d7  mov     r14d, eax
0x1400119da  test    eax, eax
0x1400119dc  jz      loc_140011A76
0x1400119e2  mov     rcx, [rbp+hFile]; hFile
0x1400119e6  lea     r9, [rbp+NumberOfBytesWritten]; lpNumberOfBytesWritten
0x1400119ea  and     [rsp+80h+lpMultiByteStr], 0
0x1400119f0  lea     rdx, [rbp+MultiByteStr]; lpBuffer
0x1400119f4  mov     r8d, eax; nNumberOfBytesToWrite
0x1400119f7  call    cs:WriteFile; KERNEL32
0x1400119fd  xor     edx, edx
0x1400119ff  test    eax, eax
0x140011a01  jz      short loc_140011A6E
0x140011a03  mov     ecx, [rbx+8]
0x140011a06  sub     ecx, dword ptr [rbp+var_28]
0x140011a09  add     ecx, edi
0x140011a0b  mov     [rbx+4], ecx
0x140011a0e  cmp     [rbp+NumberOfBytesWritten], r14d
0x140011a12  jb      short loc_140011A76
0x140011a14  cmp     r13b, 0Ah
0x140011a18  jnz     short loc_140011A4E
0x140011a1a  mov     rcx, [rbp+hFile]; hFile
0x140011a1e  lea     eax, [rdx+0Dh]
0x140011a21  mov     [rsp+80h+lpMultiByteStr], rdx; lpOverlapped
0x140011a26  lea     r8d, [rdx+1]; nNumberOfBytesToWrite
0x140011a2a  lea     rdx, [rbp+Buffer]; lpBuffer
0x140011a2e  mov     [rbp+Buffer], ax
0x140011a32  lea     r9, [rbp+NumberOfBytesWritten]; lpNumberOfBytesWritten
0x140011a36  call    cs:WriteFile; KERNEL32
0x140011a3c  xor     edx, edx
0x140011a3e  test    eax, eax
0x140011a40  jz      short loc_140011A6E
0x140011a42  cmp     [rbp+NumberOfBytesWritten], 1
0x140011a46  jb      short loc_140011A76
0x140011a48  inc     dword ptr [rbx+8]
0x140011a4b  inc     dword ptr [rbx+4]
0x140011a4e  cmp     rdi, r12
0x140011a51  jmp     loc_14001190C
0x140011a56  mov     al, [rdi]
0x140011a58  mov     rcx, [r14+r15*8]
0x140011a5c  mov     [rcx+rsi+3Eh], al
0x140011a60  mov     rax, [r14+r15*8]
0x140011a64  or      byte ptr [rax+rsi+3Dh], 4
0x140011a69  inc     dword ptr [rbx+4]
0x140011a6c  jmp     short loc_140011A76
0x140011a6e  call    cs:GetLastError; KERNEL32
0x140011a74  mov     [rbx], eax
0x140011a76  mov     rax, rbx
0x140011a79  mov     rcx, [rbp+var_10]
0x140011a7d  xor     rcx, rsp; StackCookie
0x140011a80  call    __security_check_cookie
0x140011a85  mov     rbx, [rsp+80h+arg_0]
0x140011a8d  add     rsp, 80h
0x140011a94  pop     r15
0x140011a96  pop     r14
0x140011a98  pop     r13
0x140011a9a  pop     r12
0x140011a9c  pop     rdi
0x140011a9d  pop     rsi
0x140011a9e  pop     rbp
0x140011a9f  retn

// ===== ?write_text_ansi_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x140011aa0 =====

0x140011aa0  mov     [rsp+arg_0], rbx; lpOverlapped
0x140011aa5  mov     [rsp+arg_10], rbp
0x140011aaa  push    rsi
0x140011aab  push    rdi
0x140011aac  push    r14
0x140011aae  mov     eax, 1450h
0x140011ab3  call    _alloca_probe
0x140011ab8  sub     rsp, rax
0x140011abb  mov     rax, cs:__security_cookie
0x140011ac2  xor     rax, rsp
0x140011ac5  mov     [rsp+1468h+var_28], rax
0x140011acd  mov     rbx, rcx
0x140011ad0  movsxd  r10, edx
0x140011ad3  mov     rax, r10
0x140011ad6  mov     ebp, r9d
0x140011ad9  sar     rax, 6
0x140011add  lea     rcx, qword_1400217F0
0x140011ae4  and     r10d, 3Fh
0x140011ae8  add     rbp, r8
0x140011aeb  and     dword ptr [rbx], 0
0x140011aee  mov     rsi, r8
0x140011af1  and     dword ptr [rbx+4], 0
0x140011af5  mov     rax, [rcx+rax*8]
0x140011af9  and     dword ptr [rbx+8], 0
0x140011afd  shl     r10, 6
0x140011b01  mov     r14, [rax+r10+28h]
0x140011b06  cmp     r8, rbp
0x140011b09  jnb     short loc_140011B7A
0x140011b0b  lea     rdi, [rsp+1468h+Buffer]
0x140011b10  cmp     rsi, rbp
0x140011b13  jnb     short loc_140011B39
0x140011b15  mov     al, [rsi]
0x140011b17  inc     rsi
0x140011b1a  cmp     al, 0Ah
0x140011b1c  jnz     short loc_140011B27
0x140011b1e  inc     dword ptr [rbx+8]
0x140011b21  mov     byte ptr [rdi], 0Dh
0x140011b24  inc     rdi
0x140011b27  mov     [rdi], al
0x140011b29  inc     rdi
0x140011b2c  lea     rax, [rsp+1468h+var_29]
0x140011b34  cmp     rdi, rax
0x140011b37  jb      short loc_140011B10
0x140011b39  and     [rsp+1468h+var_1448], 0
0x140011b3f  lea     rax, [rsp+1468h+Buffer]
0x140011b44  sub     edi, eax
0x140011b46  lea     r9, [rsp+1468h+NumberOfBytesWritten]; lpNumberOfBytesWritten
0x140011b4b  mov     r8d, edi; nNumberOfBytesToWrite
0x140011b4e  lea     rdx, [rsp+1468h+Buffer]; lpBuffer
0x140011b53  mov     rcx, r14; hFile
0x140011b56  call    cs:WriteFile; KERNEL32
0x140011b5c  test    eax, eax
0x140011b5e  jz      short loc_140011B72
0x140011b60  mov     eax, [rsp+1468h+NumberOfBytesWritten]
0x140011b64  add     [rbx+4], eax
0x140011b67  cmp     eax, edi
0x140011b69  jb      short loc_140011B7A
0x140011b6b  cmp     rsi, rbp
0x140011b6e  jb      short loc_140011B0B
0x140011b70  jmp     short loc_140011B7A
0x140011b72  call    cs:GetLastError; KERNEL32
0x140011b78  mov     [rbx], eax
0x140011b7a  mov     rax, rbx
0x140011b7d  mov     rcx, [rsp+1468h+var_28]
0x140011b85  xor     rcx, rsp; StackCookie
0x140011b88  call    __security_check_cookie
0x140011b8d  lea     r11, [rsp+1468h+var_18]
0x140011b95  mov     rbx, [r11+20h]
0x140011b99  mov     rbp, [r11+30h]
0x140011b9d  mov     rsp, r11
0x140011ba0  pop     r14
0x140011ba2  pop     rdi
0x140011ba3  pop     rsi
0x140011ba4  retn

// ===== ?write_text_utf16le_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x140011ba8 =====

0x140011ba8  mov     [rsp+arg_0], rbx; lpOverlapped
0x140011bad  mov     [rsp+arg_10], rbp
0x140011bb2  push    rsi
0x140011bb3  push    rdi
0x140011bb4  push    r14
0x140011bb6  mov     eax, 1450h
0x140011bbb  call    _alloca_probe
0x140011bc0  sub     rsp, rax
0x140011bc3  mov     rax, cs:__security_cookie
0x140011bca  xor     rax, rsp
0x140011bcd  mov     [rsp+1468h+var_28], rax
0x140011bd5  mov     rdi, rcx
0x140011bd8  movsxd  r10, edx
0x140011bdb  mov     rax, r10
0x140011bde  mov     ebp, r9d
0x140011be1  sar     rax, 6
0x140011be5  lea     rcx, qword_1400217F0
0x140011bec  and     r10d, 3Fh
0x140011bf0  add     rbp, r8
0x140011bf3  and     dword ptr [rdi], 0
0x140011bf6  mov     rsi, r8
0x140011bf9  and     dword ptr [rdi+4], 0
0x140011bfd  mov     rax, [rcx+rax*8]
0x140011c01  and     dword ptr [rdi+8], 0
0x140011c05  shl     r10, 6
0x140011c09  mov     r14, [rax+r10+28h]
0x140011c0e  cmp     r8, rbp
0x140011c11  jnb     loc_140011C99
0x140011c17  lea     rbx, [rsp+1468h+Buffer]
0x140011c1c  cmp     rsi, rbp
0x140011c1f  jnb     short loc_140011C52
0x140011c21  movzx   eax, word ptr [rsi]
0x140011c24  add     rsi, 2
0x140011c28  cmp     ax, 0Ah
0x140011c2c  jnz     short loc_140011C3E
0x140011c2e  add     dword ptr [rdi+8], 2
0x140011c32  mov     ecx, 0Dh
0x140011c37  mov     [rbx], cx
0x140011c3a  add     rbx, 2
0x140011c3e  mov     [rbx], ax
0x140011c41  add     rbx, 2
0x140011c45  lea     rax, [rsp+1468h+var_2A]
0x140011c4d  cmp     rbx, rax
0x140011c50  jb      short loc_140011C1C
0x140011c52  and     [rsp+1468h+var_1448], 0
0x140011c58  lea     rax, [rsp+1468h+Buffer]
0x140011c5d  sub     rbx, rax
0x140011c60  lea     r9, [rsp+1468h+NumberOfBytesWritten]; lpNumberOfBytesWritten
0x140011c65  sar     rbx, 1
0x140011c68  lea     rdx, [rsp+1468h+Buffer]; lpBuffer
0x140011c6d  add     ebx, ebx
0x140011c6f  mov     rcx, r14; hFile
0x140011c72  mov     r8d, ebx; nNumberOfBytesToWrite
0x140011c75  call    cs:WriteFile; KERNEL32
0x140011c7b  test    eax, eax
0x140011c7d  jz      short loc_140011C91
0x140011c7f  mov     eax, [rsp+1468h+NumberOfBytesWritten]
0x140011c83  add     [rdi+4], eax
0x140011c86  cmp     eax, ebx
0x140011c88  jb      short loc_140011C99
0x140011c8a  cmp     rsi, rbp
0x140011c8d  jb      short loc_140011C17
0x140011c8f  jmp     short loc_140011C99
0x140011c91  call    cs:GetLastError; KERNEL32
0x140011c97  mov     [rdi], eax
0x140011c99  mov     rax, rdi
0x140011c9c  mov     rcx, [rsp+1468h+var_28]
0x140011ca4  xor     rcx, rsp; StackCookie
0x140011ca7  call    __security_check_cookie
0x140011cac  lea     r11, [rsp+1468h+var_18]
0x140011cb4  mov     rbx, [r11+20h]
0x140011cb8  mov     rbp, [r11+30h]
0x140011cbc  mov     rsp, r11
0x140011cbf  pop     r14
0x140011cc1  pop     rdi
0x140011cc2  pop     rsi
0x140011cc3  retn

// ===== ?write_text_utf8_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z @ 0x140011cc4 =====

0x140011cc4  mov     [rsp+arg_0], rbx; lpDefaultChar
0x140011cc9  mov     [rsp+arg_10], rbp
0x140011cce  push    rsi
0x140011ccf  push    rdi
0x140011cd0  push    r12
0x140011cd2  push    r14
0x140011cd4  push    r15
0x140011cd6  mov     eax, 1470h
0x140011cdb  call    _alloca_probe
0x140011ce0  sub     rsp, rax
0x140011ce3  mov     rax, cs:__security_cookie
0x140011cea  xor     rax, rsp
0x140011ced  mov     [rsp+1498h+var_38], rax
0x140011cf5  movsxd  r10, edx
0x140011cf8  mov     rbx, rcx
0x140011cfb  mov     rax, r10
0x140011cfe  mov     r14d, r9d
0x140011d01  sar     rax, 6
0x140011d05  lea     rcx, qword_1400217F0
0x140011d0c  and     r10d, 3Fh
0x140011d10  add     r14, r8
0x140011d13  shl     r10, 6
0x140011d17  mov     r15, r8
0x140011d1a  mov     rdi, r8
0x140011d1d  mov     rax, [rcx+rax*8]
0x140011d21  mov     r12, [rax+r10+28h]
0x140011d26  xor     eax, eax
0x140011d28  and     dword ptr [rbx], 0
0x140011d2b  mov     [rbx+4], rax
0x140011d2f  cmp     r8, r14
0x140011d32  jnb     loc_140011E07
0x140011d38  lea     rax, [rsp+1498h+WideCharStr]
0x140011d3d  cmp     rdi, r14
0x140011d40  jnb     short loc_140011D6F
0x140011d42  movzx   ecx, word ptr [rdi]
0x140011d45  add     rdi, 2
0x140011d49  cmp     cx, 0Ah
0x140011d4d  jnz     short loc_140011D5B
0x140011d4f  mov     edx, 0Dh
0x140011d54  mov     [rax], dx
0x140011d57  add     rax, 2
0x140011d5b  mov     [rax], cx
0x140011d5e  add     rax, 2
0x140011d62  lea     rcx, [rsp+1498h+var_DA0]
0x140011d6a  cmp     rax, rcx
0x140011d6d  jb      short loc_140011D3D
0x140011d6f  and     [rsp+1498h+var_1460], 0
0x140011d75  lea     rcx, [rsp+1498h+WideCharStr]
0x140011d7a  and     [rsp+1498h+var_1468], 0
0x140011d80  lea     r8, [rsp+1498h+WideCharStr]; lpWideCharStr
0x140011d85  sub     rax, rcx
0x140011d88  mov     [rsp+1498h+cbMultiByte], 0D55h; cbMultiByte
0x140011d90  lea     rcx, [rsp+1498h+MultiByteStr]
0x140011d98  sar     rax, 1
0x140011d9b  mov     [rsp+1498h+lpMultiByteStr], rcx; lpOverlapped
0x140011da0  mov     r9d, eax; cchWideChar
0x140011da3  mov     ecx, 0FDE9h; CodePage
0x140011da8  xor     edx, edx; dwFlags
0x140011daa  call    cs:WideCharToMultiByte; KERNEL32
0x140011db0  mov     ebp, eax
0x140011db2  test    eax, eax
0x140011db4  jz      short loc_140011DFF
0x140011db6  xor     esi, esi
0x140011db8  test    eax, eax
0x140011dba  jz      short loc_140011DEF
0x140011dbc  and     [rsp+1498h+lpMultiByteStr], 0
0x140011dc2  lea     rdx, [rsp+1498h+MultiByteStr]
0x140011dca  mov     ecx, esi
0x140011dcc  lea     r9, [rsp+1498h+NumberOfBytesWritten]; lpNumberOfBytesWritten
0x140011dd1  mov     r8d, ebp
0x140011dd4  add     rdx, rcx; lpBuffer
0x140011dd7  mov     rcx, r12; hFile
0x140011dda  sub     r8d, esi; nNumberOfBytesToWrite
0x140011ddd  call    cs:WriteFile; KERNEL32
0x140011de3  test    eax, eax
0x140011de5  jz      short loc_140011DFF
0x140011de7  add     esi, [rsp+1498h+NumberOfBytesWritten]
0x140011deb  cmp     esi, ebp
0x140011ded  jb      short loc_140011DBC
0x140011def  mov     eax, edi
0x140011df1  sub     eax, r15d
0x140011df4  mov     [rbx+4], eax
0x140011df7  cmp     rdi, r14
0x140011dfa  jmp     loc_140011D32
0x140011dff  call    cs:GetLastError; KERNEL32
0x140011e05  mov     [rbx], eax
0x140011e07  mov     rax, rbx
0x140011e0a  mov     rcx, [rsp+1498h+var_38]
0x140011e12  xor     rcx, rsp; StackCookie
0x140011e15  call    __security_check_cookie
0x140011e1a  lea     r11, [rsp+1498h+var_28]
0x140011e22  mov     rbx, [r11+30h]
0x140011e26  mov     rbp, [r11+40h]
0x140011e2a  mov     rsp, r11
0x140011e2d  pop     r15
0x140011e2f  pop     r14
0x140011e31  pop     r12
0x140011e33  pop     rdi
0x140011e34  pop     rsi
0x140011e35  retn

// ===== _write @ 0x140011e38 =====

0x140011e38  mov     [rsp+arg_8], rbx
0x140011e3d  mov     [rsp+arg_10], rsi
0x140011e42  mov     [rsp+arg_0], ecx
0x140011e46  push    rdi
0x140011e47  push    r12
0x140011e49  push    r13
0x140011e4b  push    r14
0x140011e4d  push    r15
0x140011e4f  sub     rsp, 20h
0x140011e53  mov     r15d, r8d
0x140011e56  mov     r12, rdx
0x140011e59  movsxd  rbx, ecx
0x140011e5c  cmp     ebx, 0FFFFFFFEh
0x140011e5f  jnz     short loc_140011E79
0x140011e61  call    __doserrno
0x140011e66  and     dword ptr [rax], 0
0x140011e69  call    _errno
0x140011e6e  mov     dword ptr [rax], 9
0x140011e74  jmp     loc_140011F09
0x140011e79  test    ecx, ecx
0x140011e7b  js      short loc_140011EF1
0x140011e7d  cmp     ebx, cs:dword_140021BF0
0x140011e83  jnb     short loc_140011EF1
0x140011e85  mov     rsi, rbx
0x140011e88  mov     r14, rbx
0x140011e8b  sar     r14, 6
0x140011e8f  lea     r13, qword_1400217F0
0x140011e96  and     esi, 3Fh
0x140011e99  shl     rsi, 6
0x140011e9d  mov     rax, [r13+r14*8+0]
0x140011ea2  movzx   ecx, byte ptr [rax+rsi+38h]
0x140011ea7  and     ecx, 1
0x140011eaa  jz      short loc_140011EF1
0x140011eac  mov     ecx, ebx
0x140011eae  call    sub_14000DD34
0x140011eb3  or      edi, 0FFFFFFFFh
0x140011eb6  mov     rax, [r13+r14*8+0]
0x140011ebb  test    byte ptr [rax+rsi+38h], 1
0x140011ec0  jnz     short loc_140011ED7
0x140011ec2  call    _errno
0x140011ec7  mov     dword ptr [rax], 9
0x140011ecd  call    __doserrno
0x140011ed2  and     dword ptr [rax], 0
0x140011ed5  jmp     short loc_140011EE6
0x140011ed7  mov     r8d, r15d
0x140011eda  mov     rdx, r12
0x140011edd  mov     ecx, ebx
0x140011edf  call    _write_nolock
0x140011ee4  mov     edi, eax
0x140011ee6  mov     ecx, ebx
0x140011ee8  call    sub_14000DD58
0x140011eed  mov     eax, edi
0x140011eef  jmp     short loc_140011F0C
0x140011ef1  call    __doserrno
0x140011ef6  and     dword ptr [rax], 0
0x140011ef9  call    _errno
0x140011efe  mov     dword ptr [rax], 9
0x140011f04  call    _invalid_parameter_noinfo
0x140011f09  or      eax, 0FFFFFFFFh
0x140011f0c  mov     rbx, [rsp+48h+arg_8]
0x140011f11  mov     rsi, [rsp+48h+arg_10]
0x140011f16  add     rsp, 20h
0x140011f1a  pop     r15
0x140011f1c  pop     r14
0x140011f1e  pop     r13
0x140011f20  pop     r12
0x140011f22  pop     rdi
0x140011f23  retn
0x140013aec  push    rbp; Microsoft VisualC 64bit universal runtime
0x140013aee  sub     rsp, 20h
0x140013af2  mov     rbp, rdx
0x140013af5  mov     ecx, [rbp+50h]
0x140013af8  add     rsp, 20h
0x140013afc  pop     rbp
0x140013afd  jmp     sub_14000DD58

// ===== _write_nolock @ 0x140011f24 =====

0x140011f24  mov     [rsp-38h+arg_18], rbx
0x140011f29  push    rbp
0x140011f2a  push    rsi
0x140011f2b  push    rdi
0x140011f2c  push    r12
0x140011f2e  push    r13
0x140011f30  push    r14
0x140011f32  push    r15
0x140011f34  mov     rbp, rsp
0x140011f37  sub     rsp, 60h
0x140011f3b  xor     edi, edi
0x140011f3d  mov     r15d, r8d
0x140011f40  movsxd  r12, ecx
0x140011f43  mov     rsi, rdx
0x140011f46  test    r8d, r8d
0x140011f49  jnz     short loc_140011F52
0x140011f4b  xor     eax, eax
0x140011f4d  jmp     loc_1400121ED
0x140011f52  test    rdx, rdx
0x140011f55  jnz     short loc_140011F76
0x140011f57  call    __doserrno
0x140011f5c  mov     [rax], edi
0x140011f5e  call    _errno
0x140011f63  mov     dword ptr [rax], 16h
0x140011f69  call    _invalid_parameter_noinfo
0x140011f6e  or      eax, 0FFFFFFFFh
0x140011f71  jmp     loc_1400121ED
0x140011f76  mov     r14, r12
0x140011f79  lea     rax, qword_1400217F0
0x140011f80  and     r14d, 3Fh
0x140011f84  mov     r13, r12
0x140011f87  sar     r13, 6
0x140011f8b  shl     r14, 6
0x140011f8f  mov     [rbp+var_10], r13
0x140011f93  mov     rcx, [rax+r13*8]
0x140011f97  mov     bl, [rcx+r14+39h]
0x140011f9c  lea     eax, [rbx-1]
0x140011f9f  cmp     al, 1
0x140011fa1  ja      short loc_140011FAC
0x140011fa3  mov     eax, r15d
0x140011fa6  not     eax
0x140011fa8  test    al, 1
0x140011faa  jz      short loc_140011F57
0x140011fac  test    byte ptr [rcx+r14+38h], 20h
0x140011fb2  jz      short loc_140011FC2
0x140011fb4  xor     edx, edx
0x140011fb6  mov     ecx, r12d
0x140011fb9  lea     r8d, [rdx+2]
0x140011fbd  call    j_??$common_lseek_nolock@_J@@YA_JH_JH@Z
0x140011fc2  mov     ecx, r12d; FileHandle
0x140011fc5  mov     [rbp+var_20], rdi
0x140011fc9  call    _isatty
0x140011fce  test    eax, eax
0x140011fd0  jz      loc_1400120D7
0x140011fd6  lea     rax, qword_1400217F0
0x140011fdd  mov     rax, [rax+r13*8]
0x140011fe1  test    byte ptr [rax+r14+38h], 80h
0x140011fe7  jz      loc_1400120D7
0x140011fed  call    __acrt_getptd
0x140011ff2  mov     rcx, [rax+90h]
0x140011ff9  cmp     [rcx+138h], rdi
0x140012000  jnz     short loc_140012018
0x140012002  lea     rax, qword_1400217F0
0x140012009  mov     rax, [rax+r13*8]
0x14001200d  cmp     [rax+r14+39h], dil
0x140012012  jz      loc_1400120D7
0x140012018  lea     rax, qword_1400217F0
0x14001201f  mov     rcx, [rax+r13*8]
0x140012023  lea     rdx, [rbp+Mode]; lpMode
0x140012027  mov     rcx, [rcx+r14+28h]; hConsoleHandle
0x14001202c  call    cs:GetConsoleMode; KERNEL32
0x140012032  test    eax, eax
0x140012034  jz      loc_1400120D7
0x14001203a  test    bl, bl
0x14001203c  jz      short loc_1400120B9
0x14001203e  dec     bl
0x140012040  cmp     bl, 1
0x140012043  ja      loc_140012174
0x140012049  and     [rbp+NumberOfBytesWritten], edi
0x14001204c  lea     r12, [rsi+r15]
0x140012050  xor     ebx, ebx
0x140012052  mov     r15, rsi
0x140012055  mov     [rbp+NumberOfBytesWritten+4], ebx
0x140012058  cmp     rsi, r12
0x14001205b  jnb     loc_14001216A
0x140012061  movzx   r13d, word ptr [r15]
0x140012065  movzx   ecx, r13w; Character
0x140012069  call    _putwch_nolock
0x14001206e  cmp     ax, r13w
0x140012072  jnz     short loc_1400120A7
0x140012074  add     ebx, 2
0x140012077  mov     [rbp+NumberOfBytesWritten+4], ebx
0x14001207a  cmp     r13w, 0Ah
0x14001207f  jnz     short loc_14001209C
0x140012081  mov     r13d, 0Dh
0x140012087  mov     ecx, r13d; Character
0x14001208a  call    _putwch_nolock
0x14001208f  cmp     ax, r13w
0x140012093  jnz     short loc_1400120A7
0x140012095  inc     ebx
0x140012097  mov     [rbp+NumberOfBytesWritten+4], ebx
0x14001209a  inc     edi
0x14001209c  add     r15, 2
0x1400120a0  cmp     r15, r12
0x1400120a3  jnb     short loc_1400120B0
0x1400120a5  jmp     short loc_140012061
0x1400120a7  call    cs:GetLastError; KERNEL32
0x1400120ad  mov     [rbp+NumberOfBytesWritten], eax
0x1400120b0  mov     r13, [rbp+var_10]
0x1400120b4  jmp     loc_14001216A
0x1400120b9  mov     r9d, r15d
0x1400120bc  lea     rcx, [rbp+NumberOfBytesWritten]
0x1400120c0  mov     r8, rsi
0x1400120c3  mov     edx, r12d
0x1400120c6  call    ?write_double_translated_ansi_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z
0x1400120cb  movsd   xmm0, qword ptr [rax]
0x1400120cf  mov     edi, [rax+8]
0x1400120d2  jmp     loc_14001216F
0x1400120d7  lea     rax, qword_1400217F0
0x1400120de  mov     rcx, [rax+r13*8]
0x1400120e2  test    byte ptr [rcx+r14+38h], 80h
0x1400120e8  jz      short loc_140012137
0x1400120ea  movsx   ecx, bl
0x1400120ed  test    bl, bl
0x1400120ef  jz      short loc_140012123
0x1400120f1  sub     ecx, 1
0x1400120f4  jz      short loc_14001210F
0x1400120f6  cmp     ecx, 1
0x1400120f9  jnz     short loc_140012174
0x1400120fb  mov     r9d, r15d
0x1400120fe  lea     rcx, [rbp+NumberOfBytesWritten]
0x140012102  mov     r8, rsi
0x140012105  mov     edx, r12d
0x140012108  call    ?write_text_utf16le_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z
0x14001210d  jmp     short loc_1400120CB
0x14001210f  mov     r9d, r15d
0x140012112  lea     rcx, [rbp+NumberOfBytesWritten]
0x140012116  mov     r8, rsi
0x140012119  mov     edx, r12d
0x14001211c  call    ?write_text_utf8_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z
0x140012121  jmp     short loc_1400120CB
0x140012123  mov     r9d, r15d
0x140012126  lea     rcx, [rbp+NumberOfBytesWritten]
0x14001212a  mov     r8, rsi
0x14001212d  mov     edx, r12d
0x140012130  call    ?write_text_ansi_nolock@@YA?AUwrite_result@?A0x4392dfaa@@HQEBDI@Z
0x140012135  jmp     short loc_1400120CB
0x140012137  mov     rcx, [rcx+r14+28h]; hFile
0x14001213c  lea     r9, [rbp+NumberOfBytesWritten+4]; lpNumberOfBytesWritten
0x140012140  and     [rbp+NumberOfBytesWritten], edi
0x140012143  xor     eax, eax
0x140012145  and     [rsp+60h+var_40], rax
0x14001214a  mov     r8d, r15d; nNumberOfBytesToWrite
0x14001214d  mov     rdx, rsi; lpBuffer
0x140012150  mov     qword ptr [rbp+NumberOfBytesWritten+4], rax
0x140012154  call    cs:WriteFile; KERNEL32
0x14001215a  test    eax, eax
0x14001215c  jnz     short loc_140012167
0x14001215e  call    cs:GetLastError; KERNEL32
0x140012164  mov     [rbp+NumberOfBytesWritten], eax
0x140012167  mov     edi, [rbp+NumberOfBytesWritten+8]
0x14001216a  movsd   xmm0, qword ptr [rbp+NumberOfBytesWritten]
0x14001216f  movsd   [rbp+var_20], xmm0
0x140012174  mov     rax, [rbp+var_20]
0x140012178  shr     rax, 20h
0x14001217c  test    eax, eax
0x14001217e  jnz     short loc_1400121E8
0x140012180  mov     eax, dword ptr [rbp+var_20]
0x140012183  test    eax, eax
0x140012185  jz      short loc_1400121B4
0x140012187  cmp     eax, 5
0x14001218a  jnz     short loc_1400121A7
0x14001218c  call    _errno
0x140012191  mov     dword ptr [rax], 9
0x140012197  call    __doserrno
0x14001219c  mov     dword ptr [rax], 5
0x1400121a2  jmp     loc_140011F6E
0x1400121a7  mov     ecx, dword ptr [rbp+var_20]
0x1400121aa  call    __acrt_errno_map_os_error
0x1400121af  jmp     loc_140011F6E
0x1400121b4  lea     rax, qword_1400217F0
0x1400121bb  mov     rax, [rax+r13*8]
0x1400121bf  test    byte ptr [rax+r14+38h], 40h
0x1400121c5  jz      short loc_1400121D0
0x1400121c7  cmp     byte ptr [rsi], 1Ah
0x1400121ca  jz      loc_140011F4B
0x1400121d0  call    _errno
0x1400121d5  mov     dword ptr [rax], 1Ch
0x1400121db  call    __doserrno
0x1400121e0  and     dword ptr [rax], 0
0x1400121e3  jmp     loc_140011F6E
0x1400121e8  mov     eax, dword ptr [rbp+var_20+4]
0x1400121eb  sub     eax, edi
0x1400121ed  mov     rbx, [rsp+60h+arg_18]
0x1400121f5  add     rsp, 60h
0x1400121f9  pop     r15
0x1400121fb  pop     r14
0x1400121fd  pop     r13
0x1400121ff  pop     r12
0x140012201  pop     rdi
0x140012202  pop     rsi
0x140012203  pop     rbp
0x140012204  retn

// ===== __strncnt @ 0x140012208 =====

0x140012208  xor     eax, eax
0x14001220a  cmp     [rcx], al
0x14001220c  jz      short locret_14001221C
0x14001220e  cmp     rax, rdx
0x140012211  jz      short locret_14001221C
0x140012213  inc     rax
0x140012216  cmp     byte ptr [rax+rcx], 0
0x14001221a  jnz     short loc_14001220E
0x14001221c  retn

// ===== fegetenv @ 0x140012220 =====

0x140012220  push    rbx
0x140012222  sub     rsp, 20h
0x140012226  mov     rbx, rcx
0x140012229  call    _getfpcontrolword
0x14001222e  mov     [rbx], eax
0x140012230  call    _getfpstatusword
0x140012235  mov     [rbx+4], eax
0x140012238  xor     eax, eax
0x14001223a  add     rsp, 20h
0x14001223e  pop     rbx
0x14001223f  retn

// ===== fesetenv @ 0x140012240 =====

0x140012240  push    rbx
0x140012242  sub     rsp, 20h
0x140012246  and     [rsp+28h+Env._Fe_ctl], 0
0x14001224b  mov     rbx, rcx
0x14001224e  mov     ecx, [rcx]
0x140012250  and     [rsp+28h+Env._Fe_stat], 0
0x140012255  call    _setfpcontrolword
0x14001225a  mov     ecx, [rbx+4]
0x14001225d  call    _setfpstatusword
0x140012262  lea     rcx, [rsp+28h+Env]; Env
0x140012267  call    fegetenv
0x14001226c  mov     eax, [rsp+28h+Env._Fe_ctl]
0x140012270  cmp     [rbx], eax
0x140012272  jnz     short loc_140012281
0x140012274  mov     eax, [rsp+28h+Env._Fe_stat]
0x140012278  cmp     [rbx+4], eax
0x14001227b  jnz     short loc_140012281
0x14001227d  xor     eax, eax
0x14001227f  jmp     short loc_140012286
0x140012281  mov     eax, 1
0x140012286  add     rsp, 20h
0x14001228a  pop     rbx
0x14001228b  retn

// ===== feholdexcept @ 0x14001228c =====

0x14001228c  push    rbx
0x14001228e  sub     rsp, 20h
0x140012292  and     [rsp+28h+Env._Fe_ctl], 0
0x140012297  mov     rbx, rcx
0x14001229a  and     [rsp+28h+Env._Fe_stat], 0
0x14001229f  lea     rcx, [rsp+28h+Env]; Env
0x1400122a4  call    fegetenv
0x1400122a9  test    eax, eax
0x1400122ab  jz      short loc_1400122B4
0x1400122ad  mov     eax, 1
0x1400122b2  jmp     short loc_1400122D6
0x1400122b4  mov     rax, qword ptr [rsp+28h+Env._Fe_ctl]
0x1400122b9  lea     rcx, [rsp+28h+Env]; Env
0x1400122be  or      [rsp+28h+Env._Fe_ctl], 1Fh
0x1400122c3  mov     [rbx], rax
0x1400122c6  call    fesetenv
0x1400122cb  test    eax, eax
0x1400122cd  jnz     short loc_1400122AD
0x1400122cf  call    _clearfp
0x1400122d4  xor     eax, eax
0x1400122d6  add     rsp, 20h
0x1400122da  pop     rbx
0x1400122db  retn

// ===== ceil @ 0x1400122dc =====

0x1400122dc  xor     r8d, r8d
0x1400122df  movsd   [rsp+arg_0], xmm0
0x1400122e5  mov     rdx, [rsp+arg_0]
0x1400122ea  mov     rcx, 7FFFFFFFFFFFFFFFh
0x1400122f4  mov     rax, rdx
0x1400122f7  and     rax, rcx
0x1400122fa  mov     rcx, 4340000000000000h
0x140012304  cmp     rdx, rax
0x140012307  setnz   r8b
0x14001230b  cmp     rax, rcx
0x14001230e  jb      short loc_140012327
0x140012310  mov     rcx, 7FF0000000000000h
0x14001231a  cmp     rax, rcx
0x14001231d  jbe     short locret_14001239D
0x14001231f  mov     rcx, rdx
0x140012322  jmp     _handle_nan
0x140012327  mov     rcx, 3FF0000000000000h
0x140012331  cmp     rax, rcx
0x140012334  jnb     short loc_140012361
0x140012336  test    rax, rax
0x140012339  jz      short locret_14001239D
0x14001233b  test    r8, r8
0x14001233e  jz      short loc_140012357
0x140012340  mov     rax, 8000000000000000h
0x14001234a  mov     [rsp+arg_0], rax
0x14001234f  movsd   xmm0, [rsp+arg_0]
0x140012355  jmp     short locret_14001239D
0x140012357  movsd   xmm0, cs:qword_14001AF18
0x14001235f  jmp     short locret_14001239D
0x140012361  mov     rax, rdx
0x140012364  mov     ecx, 33h ; '3'
0x140012369  shr     rax, 34h
0x14001236d  sub     cl, al
0x14001236f  mov     eax, 1
0x140012374  shl     rax, cl
0x140012377  dec     rax
0x14001237a  not     rax
0x14001237d  and     rax, rdx
0x140012380  mov     [rsp+arg_0], rax
0x140012385  movsd   xmm0, [rsp+arg_0]
0x14001238b  test    r8, r8
0x14001238e  jnz     short locret_14001239D
0x140012390  cmp     rax, rdx
0x140012393  jz      short locret_14001239D
0x140012395  addsd   xmm0, cs:qword_14001AF18
0x14001239d  retn
0x140012fbc  mov     rax, 8000000000000h
0x140012fc6  or      rcx, rax
0x140012fc9  mov     [rsp+arg_0], rcx
0x140012fce  movsd   xmm0, [rsp+arg_0]
0x140012fd4  retn

// ===== log10 @ 0x1400123a0 =====

0x1400123a0  sub     rsp, 58h
0x1400123a4  movdqa  [rsp+58h+var_38], xmm6
0x1400123aa  cmp     cs:dword_14002203C, 0
0x1400123b1  jnz     Llog10_fma3
0x1400123b7  movapd  xmm3, xmm0
0x1400123bb  movapd  xmm4, xmm0
0x1400123bf  psrlq   xmm3, 34h ; '4'
0x1400123c4  movq    rax, xmm0
0x1400123c9  psubq   xmm3, cs:xmmword_14001AF60
0x1400123d1  movapd  xmm5, xmm0
0x1400123d5  andpd   xmm5, cs:xmmword_14001AF30
0x1400123dd  comisd  xmm5, qword ptr cs:xmmword_14001AF30
0x1400123e5  jz      Llog10_sse2_x_is_inf_or_nan
0x1400123eb  movapd  xmm2, xmm0
0x1400123ef  cvtdq2pd xmm6, xmm3
0x1400123f3  xorpd   xmm5, xmm5
0x1400123f7  comisd  xmm0, xmm5
0x1400123fb  jbe     Llog10_sse2_x_is_zero_or_neg
0x140012401  pand    xmm2, cs:xmmword_14001AF80
0x140012409  subsd   xmm4, qword ptr cs:xmmword_14001B010
0x140012411  comisd  xmm6, cs:qword_14001B0A0
0x140012419  jz      Llog10_sse2_denormal_adjust
0x14001241f  andpd   xmm4, cs:xmmword_14001B100
0x140012427  mov     r9, rax
0x14001242a  and     rax, qword ptr cs:xmmword_14001AF90
0x140012431  and     r9, qword ptr cs:xmmword_14001AFA0
0x140012438  shl     r9, 1
0x14001243b  add     rax, r9
0x14001243e  movq    xmm1, rax
0x140012443  comisd  xmm4, cs:qword_14001B0C0
0x14001244b  jb      Llog10_sse2_near_one
0x140012451  shr     rax, 2Ch
0x140012455  por     xmm2, cs:xmmword_14001B020
0x14001245d  por     xmm1, cs:xmmword_14001B020
0x140012465  lea     r9, dbl_14001C190
0x14001246c  subsd   xmm1, xmm2
0x140012470  mulsd   xmm1, qword ptr [r9+rax*8]
0x140012476  movapd  xmm2, xmm1
0x14001247a  movapd  xmm0, xmm1
0x14001247e  lea     r9, dbl_14001B170
0x140012485  movsd   xmm3, cs:qword_14001B090
0x14001248d  movsd   xmm1, cs:qword_14001B060
0x140012495  mulsd   xmm3, xmm2
0x140012499  mulsd   xmm1, xmm2
0x14001249d  mulsd   xmm0, xmm2
0x1400124a1  movapd  xmm4, xmm0
0x1400124a5  addsd   xmm3, cs:qword_14001B080
0x1400124ad  addsd   xmm1, cs:qword_14001B050
0x1400124b5  mulsd   xmm4, xmm0
0x1400124b9  mulsd   xmm3, xmm2
0x1400124bd  mulsd   xmm1, xmm0
0x1400124c1  addsd   xmm3, cs:qword_14001B070
0x1400124c9  addsd   xmm1, xmm2
0x1400124cd  mulsd   xmm3, xmm4
0x1400124d1  addsd   xmm1, xmm3
0x1400124d5  movsd   xmm5, cs:qword_14001AFF0
0x1400124dd  mulsd   xmm1, cs:qword_14001AFB0
0x1400124e5  mulsd   xmm5, xmm6
0x1400124e9  subsd   xmm5, xmm1
0x1400124ed  movsd   xmm0, qword ptr [r9+rax*8]
0x1400124f3  lea     rdx, dbl_14001B980
0x1400124fa  movsd   xmm2, qword ptr [rdx+rax*8]
0x1400124ff  movsd   xmm4, cs:qword_14001AFE0
0x140012507  mulsd   xmm4, xmm6
0x14001250b  addsd   xmm0, xmm4
0x14001250f  addsd   xmm2, xmm5
0x140012513  addsd   xmm0, xmm2
0x140012517  movdqa  xmm6, [rsp+58h+var_38]
0x14001251d  add     rsp, 58h
0x140012521  retn
0x140012530  movsd   xmm2, cs:qword_14001B000
0x140012538  subsd   xmm0, qword ptr cs:xmmword_14001B010
0x140012540  addsd   xmm2, xmm0
0x140012544  movapd  xmm1, xmm0
0x140012548  divsd   xmm1, xmm2
0x14001254c  movsd   xmm4, cs:qword_14001B120
0x140012554  movsd   xmm5, cs:qword_14001B140
0x14001255c  movapd  xmm6, xmm0
0x140012560  mulsd   xmm6, xmm1
0x140012564  addsd   xmm1, xmm1
0x140012568  movapd  xmm2, xmm1
0x14001256c  mulsd   xmm2, xmm1
0x140012570  mulsd   xmm4, xmm2
0x140012574  mulsd   xmm5, xmm2
0x140012578  addsd   xmm4, cs:qword_14001B110
0x140012580  addsd   xmm5, cs:qword_14001B130
0x140012588  mulsd   xmm2, xmm1
0x14001258c  mulsd   xmm4, xmm2
0x140012590  mulsd   xmm2, xmm2
0x140012594  mulsd   xmm2, xmm1
0x140012598  mulsd   xmm5, xmm2
0x14001259c  movsd   xmm2, cs:qword_14001AFD0
0x1400125a4  addsd   xmm4, xmm5
0x1400125a8  subsd   xmm4, xmm6
0x1400125ac  movsd   xmm6, cs:qword_14001AFC0
0x1400125b4  movapd  xmm3, xmm0
0x1400125b8  pand    xmm3, cs:xmmword_14001B150
0x1400125c0  subsd   xmm0, xmm3
0x1400125c4  addsd   xmm4, xmm0
0x1400125c8  movapd  xmm0, xmm3
0x1400125cc  movapd  xmm1, xmm4
0x1400125d0  mulsd   xmm4, xmm2
0x1400125d4  mulsd   xmm0, xmm2
0x1400125d8  mulsd   xmm1, xmm6
0x1400125dc  mulsd   xmm3, xmm6
0x1400125e0  addsd   xmm0, xmm4
0x1400125e4  addsd   xmm0, xmm1
0x1400125e8  addsd   xmm0, xmm3
0x1400125ec  movdqa  xmm6, [rsp+58h+var_38]
0x1400125f2  add     rsp, 58h
0x1400125f6  retn
0x1400125f7  por     xmm2, cs:xmmword_14001B010
0x1400125ff  subsd   xmm2, qword ptr cs:xmmword_14001B010
0x140012607  movsd   xmm5, xmm2
0x14001260b  pand    xmm2, cs:xmmword_14001AF80
0x140012613  movq    rax, xmm2
0x140012618  psrlq   xmm5, 34h ; '4'
0x14001261d  psubd   xmm5, cs:xmmword_14001B0B0
0x140012625  cvtdq2pd xmm6, xmm5
0x140012629  jmp     Llog10_sse2_continue_common
0x140012630  jnz     short Llog10_sse2_x_is_neg
0x140012632  movsd   xmm1, cs:qword_14001AF20
0x14001263a  mov     r8d, cs:dword_14001B160
0x140012641  call    _log10_special
0x140012646  jmp     short Llog10_sse2_finish
0x140012650  movsd   xmm1, cs:qword_14001AF40
0x140012658  mov     r8d, cs:dword_14001B164
0x14001265f  call    _log10_special
0x140012664  jmp     short Llog10_sse2_finish
0x140012670  cmp     rax, qword ptr cs:xmmword_14001AF30
0x140012677  jz      short Llog10_sse2_finish
0x140012679  cmp     rax, cs:qword_14001AF20
0x140012680  jz      short Llog10_sse2_x_is_neg
0x140012682  or      rax, cs:qword_14001AF50
0x140012689  movq    xmm0, rax
0x14001268e  xchg    ax, ax
0x140012690  movdqa  xmm6, [rsp+58h+var_38]
0x140012696  add     rsp, 58h
0x14001269a  retn
0x1400126a0  xor     rax, rax
0x1400126a3  vpsrlq  xmm3, xmm0, 34h ; '4'
0x1400126a8  vmovq   rax, xmm0
0x1400126ad  vpsubq  xmm3, xmm3, cs:xmmword_14001AF60
0x1400126b5  vcvtdq2pd xmm6, xmm3
0x1400126b9  vpand   xmm5, xmm0, cs:xmmword_14001AF30
0x1400126c1  vcomisd xmm5, qword ptr cs:xmmword_14001AF30
0x1400126c9  jz      Llog10_fma3_x_is_inf_or_nan
0x1400126cf  vpxor   xmm5, xmm5, xmm5
0x1400126d3  vcomisd xmm0, xmm5
0x1400126d7  jbe     Llog10_fma3_x_is_zero_or_neg
0x1400126dd  vpand   xmm2, xmm0, cs:xmmword_14001AF80
0x1400126e5  vsubsd  xmm4, xmm0, qword ptr cs:xmmword_14001B010
0x1400126ed  vcomisd xmm6, cs:qword_14001B0A0
0x1400126f5  jz      Llog10_fma3_denormal_adjust
0x1400126fb  vpand   xmm1, xmm0, cs:xmmword_14001AF90
0x140012703  vpand   xmm3, xmm0, cs:xmmword_14001AFA0
0x14001270b  vpsllq  xmm3, xmm3, 1
0x140012710  vpaddq  xmm1, xmm3, xmm1
0x140012714  vmovq   rax, xmm1
0x140012719  vpand   xmm4, xmm4, cs:xmmword_14001B100
0x140012721  vcomisd xmm4, cs:qword_14001B0C0
0x140012729  jb      Llog10_fma3_near_one
0x14001272f  shr     rax, 2Ch
0x140012733  vpor    xmm2, xmm2, cs:xmmword_14001B020
0x14001273b  vpor    xmm1, xmm1, cs:xmmword_14001B020
0x140012743  lea     r9, dbl_14001C190
0x14001274a  vsubsd  xmm1, xmm1, xmm2
0x14001274e  vmulsd  xmm1, xmm1, qword ptr [r9+rax*8]
0x140012754  lea     r9, dbl_14001B170
0x14001275b  vmulsd  xmm0, xmm1, xmm1
0x14001275f  vmovsd  xmm3, cs:qword_14001B090
0x140012767  vmovsd  xmm5, cs:qword_14001B060
0x14001276f  vfmadd213sd xmm3, xmm1, cs:qword_14001B080
0x140012778  vfmadd213sd xmm5, xmm1, qword ptr cs:xmmword_14001B020
0x140012781  movsd   xmm4, xmm0
0x140012785  vfmadd213sd xmm3, xmm1, cs:qword_14001B070
0x14001278e  vmulsd  xmm4, xmm0, xmm0
0x140012792  vfmadd231sd xmm1, xmm5, xmm0
0x140012797  vfmadd231sd xmm1, xmm3, xmm4
0x14001279c  vmulsd  xmm1, xmm1, cs:qword_14001AFB0
0x1400127a4  vmovsd  xmm5, cs:qword_14001AFF0
0x1400127ac  vfmsub213sd xmm5, xmm6, xmm1
0x1400127b1  movsd   xmm0, qword ptr [r9+rax*8]
0x1400127b7  lea     rdx, dbl_14001B980
0x1400127be  movsd   xmm2, qword ptr [rdx+rax*8]
0x1400127c3  vaddsd  xmm2, xmm2, xmm5
0x1400127c7  vfmadd231sd xmm0, xmm6, cs:qword_14001AFE0
0x1400127d0  vaddsd  xmm0, xmm0, xmm2
0x1400127d4  vmovdqa xmm6, [rsp+58h+var_38]
0x1400127da  add     rsp, 58h
0x1400127de  retn
0x1400127e0  vmovsd  xmm2, cs:qword_14001B000
0x1400127e8  vsubsd  xmm0, xmm0, qword ptr cs:xmmword_14001B010
0x1400127f0  vaddsd  xmm2, xmm2, xmm0
0x1400127f4  vdivsd  xmm1, xmm0, xmm2
0x1400127f8  vmovsd  xmm4, cs:qword_14001B120
0x140012800  vmovsd  xmm5, cs:qword_14001B140
0x140012808  vmulsd  xmm6, xmm0, xmm1
0x14001280c  vaddsd  xmm1, xmm1, xmm1
0x140012810  vmulsd  xmm2, xmm1, xmm1
0x140012814  vfmadd213sd xmm4, xmm2, cs:qword_14001B110
0x14001281d  vfmadd213sd xmm5, xmm2, cs:qword_14001B130
0x140012826  vmulsd  xmm2, xmm2, xmm1
0x14001282a  vmulsd  xmm4, xmm4, xmm2
0x14001282e  vmulsd  xmm2, xmm2, xmm2
0x140012832  vmulsd  xmm2, xmm2, xmm1
0x140012836  vmulsd  xmm5, xmm5, xmm2
0x14001283a  vaddsd  xmm4, xmm4, xmm5
0x14001283e  vsubsd  xmm4, xmm4, xmm6
0x140012842  vpand   xmm3, xmm0, cs:xmmword_14001B150
0x14001284a  vsubsd  xmm0, xmm0, xmm3
0x14001284e  vaddsd  xmm4, xmm4, xmm0
0x140012852  vmulsd  xmm1, xmm4, cs:qword_14001AFC0
0x14001285a  vmulsd  xmm4, xmm4, cs:qword_14001AFD0
0x140012862  vmulsd  xmm0, xmm3, cs:qword_14001AFD0
0x14001286a  vmulsd  xmm3, xmm3, cs:qword_14001AFC0
0x140012872  vaddsd  xmm0, xmm0, xmm4
0x140012876  vaddsd  xmm0, xmm0, xmm1
0x14001287a  vaddsd  xmm0, xmm0, xmm3
0x14001287e  vmovdqa xmm6, [rsp+58h+var_38]
0x140012884  add     rsp, 58h
0x140012888  retn
0x140012889  vpor    xmm2, xmm2, cs:xmmword_14001B010
0x140012891  vsubsd  xmm2, xmm2, qword ptr cs:xmmword_14001B010
0x140012899  vpsrlq  xmm5, xmm2, 34h ; '4'
0x14001289e  vpand   xmm2, xmm2, cs:xmmword_14001AF80
0x1400128a6  vmovapd xmm0, xmm2
0x1400128aa  vpsubd  xmm5, xmm5, cs:xmmword_14001B0B0
0x1400128b2  vcvtdq2pd xmm6, xmm5
0x1400128b6  jmp     Llog10_fma3_continue_common
0x1400128c0  jnz     short Llog10_fma3_x_is_neg
0x1400128c2  vmovsd  xmm1, cs:qword_14001AF20
0x1400128ca  mov     r8d, cs:dword_14001B160
0x1400128d1  call    _log10_special
0x1400128d6  vmovdqa xmm6, [rsp+58h+var_38]
0x1400128dc  add     rsp, 58h
0x1400128e0  retn
0x1400128f0  vmovsd  xmm1, cs:qword_14001AF40
0x1400128f8  mov     r8d, cs:dword_14001B164
0x1400128ff  call    _log10_special
0x140012904  vmovdqa xmm6, [rsp+58h+var_38]
0x14001290a  add     rsp, 58h
0x14001290e  retn
0x140012910  cmp     rax, qword ptr cs:xmmword_14001AF30
0x140012917  jz      short Llog10_fma3_finish
0x140012919  cmp     rax, cs:qword_14001AF20
0x140012920  jz      short Llog10_fma3_x_is_neg
0x140012922  or      rax, cs:qword_14001AF50
0x140012929  movq    xmm1, rax
0x14001292e  mov     r8d, cs:dword_14001B168
0x140012935  call    _log10_special
0x14001293a  jmp     short Llog10_fma3_finish
0x140012940  vmovdqa xmm6, [rsp+58h+var_38]
0x140012946  add     rsp, 58h
0x14001294a  retn

// ===== _putwch_nolock @ 0x14001294c =====

0x14001294c  mov     [rsp+Buffer], cx
0x140012951  sub     rsp, 38h
0x140012955  mov     rcx, qword ptr cs:unk_140020B50
0x14001295c  cmp     rcx, 0FFFFFFFFFFFFFFFEh
0x140012960  jnz     short loc_14001296E
0x140012962  call    sub_140013108
0x140012967  mov     rcx, qword ptr cs:unk_140020B50; hConsoleOutput
0x14001296e  cmp     rcx, 0FFFFFFFFFFFFFFFFh
0x140012972  jnz     short loc_14001297B
0x140012974  mov     eax, 0FFFFh
0x140012979  jmp     short loc_1400129A0
0x14001297b  and     [rsp+38h+var_18], 0
0x140012981  lea     r9, [rsp+38h+NumberOfCharsWritten]; lpNumberOfCharsWritten
0x140012986  mov     r8d, 1; nNumberOfCharsToWrite
0x14001298c  lea     rdx, [rsp+38h+Buffer]; lpBuffer
0x140012991  call    cs:WriteConsoleW; KERNEL32
0x140012997  test    eax, eax
0x140012999  jz      short loc_140012974
0x14001299b  movzx   eax, [rsp+38h+Buffer]
0x1400129a0  add     rsp, 38h
0x1400129a4  retn

// ===== _getfpcontrolword @ 0x1400129a8 =====

0x1400129a8  sub     rsp, 28h
0x1400129ac  xor     edx, edx; Mask
0x1400129ae  xor     ecx, ecx; NewValue
0x1400129b0  call    _controlfp
0x1400129b5  and     eax, 31Fh
0x1400129ba  add     rsp, 28h
0x1400129be  retn

// ===== _getfpstatusword @ 0x1400129c0 =====

0x1400129c0  sub     rsp, 28h
0x1400129c4  call    _statusfp
0x1400129c9  and     eax, 1Fh
0x1400129cc  add     rsp, 28h
0x1400129d0  retn

// ===== _setfpcontrolword @ 0x1400129d4 =====

0x1400129d4  mov     edx, 8031Fh; Mask
0x1400129d9  jmp     _controlfp

// ===== _setfpstatusword @ 0x1400129e0 =====

0x1400129e0  push    rbx
0x1400129e2  sub     rsp, 20h
0x1400129e6  mov     ebx, ecx
0x1400129e8  call    _get_fpsr
0x1400129ed  and     eax, 0FFFFFFC2h
0x1400129f0  xor     ecx, ecx
0x1400129f2  test    bl, 1Fh
0x1400129f5  jz      short loc_140012A24
0x1400129f7  mov     dl, bl
0x1400129f9  lea     r8d, [rcx+1]
0x1400129fd  and     dl, 10h
0x140012a00  cmovnz  ecx, r8d
0x140012a04  test    bl, 8
0x140012a07  jz      short loc_140012A0C
0x140012a09  or      ecx, 4
0x140012a0c  test    bl, 4
0x140012a0f  jz      short loc_140012A14
0x140012a11  or      ecx, 8
0x140012a14  test    bl, 2
0x140012a17  jz      short loc_140012A1C
0x140012a19  or      ecx, 10h
0x140012a1c  test    r8b, bl
0x140012a1f  jz      short loc_140012A24
0x140012a21  or      ecx, 20h
0x140012a24  or      ecx, eax
0x140012a26  add     rsp, 20h
0x140012a2a  pop     rbx
0x140012a2b  jmp     _set_fpsr

// ===== _clearfp @ 0x140012a30 =====

0x140012a30  push    rbx
0x140012a32  sub     rsp, 20h
0x140012a36  call    _get_fpsr
0x140012a3b  mov     ebx, eax
0x140012a3d  call    _fclrf
0x140012a42  xor     eax, eax
0x140012a44  test    bl, 3Fh
0x140012a47  jz      short loc_140012A7C
0x140012a49  mov     cl, bl
0x140012a4b  lea     edx, [rax+10h]
0x140012a4e  and     cl, 1
0x140012a51  cmovnz  eax, edx
0x140012a54  test    bl, 4
0x140012a57  jz      short loc_140012A5C
0x140012a59  or      eax, 8
0x140012a5c  test    bl, 8
0x140012a5f  jz      short loc_140012A64
0x140012a61  or      eax, 4
0x140012a64  test    dl, bl
0x140012a66  jz      short loc_140012A6B
0x140012a68  or      eax, 2
0x140012a6b  test    bl, 20h
0x140012a6e  jz      short loc_140012A73
0x140012a70  or      eax, 1
0x140012a73  test    bl, 2
0x140012a76  jz      short loc_140012A7C
0x140012a78  bts     eax, 13h
0x140012a7c  add     rsp, 20h
0x140012a80  pop     rbx
0x140012a81  retn

// ===== _controlfp @ 0x140012a84 =====

0x140012a84  btr     edx, 13h
0x140012a88  jmp     common_control87

// ===== _statusfp @ 0x140012a90 =====

0x140012a90  stmxcsr [rsp+arg_0]
0x140012a95  mov     edx, [rsp+arg_0]
0x140012a99  xor     ecx, ecx
0x140012a9b  test    dl, 3Fh
0x140012a9e  jz      short loc_140012AD5
0x140012aa0  mov     al, dl
0x140012aa2  lea     r8d, [rcx+10h]
0x140012aa6  and     al, 1
0x140012aa8  cmovnz  ecx, r8d
0x140012aac  test    dl, 4
0x140012aaf  jz      short loc_140012AB4
0x140012ab1  or      ecx, 8
0x140012ab4  test    dl, 8
0x140012ab7  jz      short loc_140012ABC
0x140012ab9  or      ecx, 4
0x140012abc  test    r8b, dl
0x140012abf  jz      short loc_140012AC4
0x140012ac1  or      ecx, 2
0x140012ac4  test    dl, 20h
0x140012ac7  jz      short loc_140012ACC
0x140012ac9  or      ecx, 1
0x140012acc  test    dl, 2
0x140012acf  jz      short loc_140012AD5
0x140012ad1  bts     ecx, 13h
0x140012ad5  mov     eax, ecx
0x140012ad7  retn

// ===== common_control87 @ 0x140012ad8 =====

0x140012ad8  mov     [rsp+arg_8], rbx
0x140012add  mov     [rsp+arg_10], rsi
0x140012ae2  mov     [rsp+arg_18], rdi
0x140012ae7  push    r12
0x140012ae9  push    r14
0x140012aeb  push    r15
0x140012aed  sub     rsp, 20h
0x140012af1  mov     ebx, edx
0x140012af3  mov     esi, ecx
0x140012af5  and     ebx, 308031Fh
0x140012afb  call    _get_fpsr
0x140012b00  mov     r9d, eax
0x140012b03  xor     edi, edi
0x140012b05  mov     r8b, al
0x140012b08  mov     r11d, 80h
0x140012b0e  mov     eax, edi
0x140012b10  lea     ecx, [rdi+10h]
0x140012b13  and     r8b, r11b
0x140012b16  cmovnz  eax, ecx
0x140012b19  mov     r12d, 200h
0x140012b1f  test    r12d, r9d
0x140012b22  jz      short loc_140012B27
0x140012b24  or      eax, 8
0x140012b27  bt      r9d, 0Ah
0x140012b2c  jnb     short loc_140012B31
0x140012b2e  or      eax, 4
0x140012b31  mov     r8d, 800h
0x140012b37  test    r8d, r9d
0x140012b3a  jz      short loc_140012B3F
0x140012b3c  or      eax, 2
0x140012b3f  mov     r10d, 1000h
0x140012b45  test    r10d, r9d
0x140012b48  jz      short loc_140012B4D
0x140012b4a  or      eax, 1
0x140012b4d  mov     r14d, 100h
0x140012b53  test    r14d, r9d
0x140012b56  jz      short loc_140012B5C
0x140012b58  bts     eax, 13h
0x140012b5c  mov     ecx, r9d
0x140012b5f  mov     r15d, 6000h
0x140012b65  and     ecx, r15d
0x140012b68  jz      short loc_140012B8E
0x140012b6a  cmp     ecx, 2000h
0x140012b70  jz      short loc_140012B8B
0x140012b72  cmp     ecx, 4000h
0x140012b78  jz      short loc_140012B86
0x140012b7a  cmp     ecx, r15d
0x140012b7d  jnz     short loc_140012B8E
0x140012b7f  or      eax, 300h
0x140012b84  jmp     short loc_140012B8E
0x140012b86  or      eax, r12d
0x140012b89  jmp     short loc_140012B8E
0x140012b8b  or      eax, r14d
0x140012b8e  mov     edx, 8040h
0x140012b93  and     r9d, edx
0x140012b96  sub     r9d, 40h ; '@'
0x140012b9a  jz      short loc_140012BB8
0x140012b9c  sub     r9d, 7FC0h
0x140012ba3  jz      short loc_140012BB1
0x140012ba5  cmp     r9d, 40h ; '@'
0x140012ba9  jnz     short loc_140012BBC
0x140012bab  bts     eax, 18h
0x140012baf  jmp     short loc_140012BBC
0x140012bb1  or      eax, 3000000h
0x140012bb6  jmp     short loc_140012BBC
0x140012bb8  bts     eax, 19h
0x140012bbc  mov     ecx, ebx
0x140012bbe  not     ecx
0x140012bc0  and     ecx, eax
0x140012bc2  and     esi, ebx
0x140012bc4  or      ecx, esi
0x140012bc6  cmp     ecx, eax
0x140012bc8  jz      loc_140012D54
0x140012bce  mov     al, cl
0x140012bd0  mov     esi, 10h
0x140012bd5  mov     ebx, edi
0x140012bd7  and     al, sil
0x140012bda  cmovnz  ebx, r11d
0x140012bde  mov     [rsp+38h+arg_0], ebx
0x140012be2  test    cl, 8
0x140012be5  jz      short loc_140012BEE
0x140012be7  or      ebx, r12d
0x140012bea  mov     [rsp+38h+arg_0], ebx
0x140012bee  test    cl, 4
0x140012bf1  jz      short loc_140012BFB
0x140012bf3  bts     ebx, 0Ah
0x140012bf7  mov     [rsp+38h+arg_0], ebx
0x140012bfb  test    cl, 2
0x140012bfe  jz      short loc_140012C07
0x140012c00  or      ebx, r8d
0x140012c03  mov     [rsp+38h+arg_0], ebx
0x140012c07  test    cl, 1
0x140012c0a  jz      short loc_140012C13
0x140012c0c  or      ebx, r10d
0x140012c0f  mov     [rsp+38h+arg_0], ebx
0x140012c13  bt      ecx, 13h
0x140012c17  jnb     short loc_140012C20
0x140012c19  or      ebx, r14d
0x140012c1c  mov     [rsp+38h+arg_0], ebx
0x140012c20  mov     eax, ecx
0x140012c22  and     eax, 300h
0x140012c27  jz      short loc_140012C4D
0x140012c29  cmp     eax, r14d
0x140012c2c  jz      short loc_140012C45
0x140012c2e  cmp     eax, r12d
0x140012c31  jz      short loc_140012C3F
0x140012c33  cmp     eax, 300h
0x140012c38  jnz     short loc_140012C4D
0x140012c3a  or      ebx, r15d
0x140012c3d  jmp     short loc_140012C49
0x140012c3f  bts     ebx, 0Eh
0x140012c43  jmp     short loc_140012C49
0x140012c45  bts     ebx, 0Dh
0x140012c49  mov     [rsp+38h+arg_0], ebx
0x140012c4d  and     ecx, 3000000h
0x140012c53  cmp     ecx, 1000000h
0x140012c59  jz      short loc_140012C76
0x140012c5b  cmp     ecx, 2000000h
0x140012c61  jz      short loc_140012C71
0x140012c63  cmp     ecx, 3000000h
0x140012c69  jnz     short loc_140012C7C
0x140012c6b  bts     ebx, 0Fh
0x140012c6f  jmp     short loc_140012C78
0x140012c71  or      ebx, 40h
0x140012c74  jmp     short loc_140012C78
0x140012c76  or      ebx, edx
0x140012c78  mov     [rsp+38h+arg_0], ebx
0x140012c7c  cmp     cs:byte_140020B40, dil
0x140012c83  jz      short loc_140012CC1
0x140012c85  test    bl, 40h
0x140012c88  jz      short loc_140012CC1
0x140012c8a  mov     ecx, ebx
0x140012c8c  call    _set_fpsr
0x140012c91  jmp     short loc_140012CBF
0x140012c93  mov     cs:byte_140020B40, 0
0x140012c9a  mov     ebx, [rsp+38h+arg_0]
0x140012c9e  and     ebx, 0FFFFFFBFh
0x140012ca1  mov     ecx, ebx
0x140012ca3  call    _set_fpsr
0x140012ca8  xor     edi, edi
0x140012caa  lea     esi, [rdi+10h]
0x140012cad  mov     r12d, 200h
0x140012cb3  mov     r14d, 100h
0x140012cb9  mov     r15d, 6000h
0x140012cbf  jmp     short loc_140012CCB
0x140012cc1  and     ebx, 0FFFFFFBFh
0x140012cc4  mov     ecx, ebx
0x140012cc6  call    _set_fpsr
0x140012ccb  mov     al, bl
0x140012ccd  and     al, 80h
0x140012ccf  cmovnz  edi, esi
0x140012cd2  test    r12d, ebx
0x140012cd5  jz      short loc_140012CDA
0x140012cd7  or      edi, 8
0x140012cda  bt      ebx, 0Ah
0x140012cde  jnb     short loc_140012CE3
0x140012ce0  or      edi, 4
0x140012ce3  bt      ebx, 0Bh
0x140012ce7  jnb     short loc_140012CEC
0x140012ce9  or      edi, 2
0x140012cec  bt      ebx, 0Ch
0x140012cf0  jnb     short loc_140012CF5
0x140012cf2  or      edi, 1
0x140012cf5  test    r14d, ebx
0x140012cf8  jz      short loc_140012CFE
0x140012cfa  bts     edi, 13h
0x140012cfe  mov     eax, ebx
0x140012d00  and     eax, r15d
0x140012d03  jz      short loc_140012D28
0x140012d05  cmp     eax, 2000h
0x140012d0a  jz      short loc_140012D25
0x140012d0c  cmp     eax, 4000h
0x140012d11  jz      short loc_140012D20
0x140012d13  cmp     eax, r15d
0x140012d16  jnz     short loc_140012D28
0x140012d18  or      edi, 300h
0x140012d1e  jmp     short loc_140012D28
0x140012d20  or      edi, r12d
0x140012d23  jmp     short loc_140012D28
0x140012d25  or      edi, r14d
0x140012d28  and     ebx, 8040h
0x140012d2e  sub     ebx, 40h ; '@'
0x140012d31  jz      short loc_140012D4E
0x140012d33  sub     ebx, 7FC0h
0x140012d39  jz      short loc_140012D46
0x140012d3b  cmp     ebx, 40h ; '@'
0x140012d3e  jnz     short loc_140012D52
0x140012d40  bts     edi, 18h
0x140012d44  jmp     short loc_140012D52
0x140012d46  or      edi, 3000000h
0x140012d4c  jmp     short loc_140012D52
0x140012d4e  bts     edi, 19h
0x140012d52  mov     eax, edi
0x140012d54  mov     rbx, [rsp+38h+arg_8]
0x140012d59  mov     rsi, [rsp+38h+arg_10]
0x140012d5e  mov     rdi, [rsp+38h+arg_18]
0x140012d63  add     rsp, 20h
0x140012d67  pop     r15
0x140012d69  pop     r14
0x140012d6b  pop     r12
0x140012d6d  retn
0x140013b03  push    rbp; Microsoft VisualC 64bit universal runtime
0x140013b05  sub     rsp, 20h
0x140013b09  mov     rbp, rdx
0x140013b0c  mov     rax, [rcx]
0x140013b0f  cmp     dword ptr [rax], 0C0000005h
0x140013b15  jz      short loc_140013B23
0x140013b17  cmp     dword ptr [rax], 0C000001Dh
0x140013b1d  jz      short loc_140013B23
0x140013b1f  xor     eax, eax
0x140013b21  jmp     short loc_140013B28
0x140013b23  mov     eax, 1
0x140013b28  add     rsp, 20h
0x140013b2c  pop     rbp
0x140013b2d  retn

// ===== _call_matherr @ 0x140012d70 =====

0x140012d70  mov     rax, rsp
0x140012d73  push    rbx
0x140012d74  sub     rsp, 50h
0x140012d78  movsd   xmm0, [rsp+58h+arg_20]
0x140012d81  mov     ebx, ecx
0x140012d83  movsd   xmm1, [rsp+58h+arg_28]
0x140012d8c  mov     edx, 0FFC0h
0x140012d91  mov     [rax-38h], ecx
0x140012d94  mov     rcx, [rsp+58h+arg_30]
0x140012d9c  movsd   qword ptr [rax-20h], xmm0
0x140012da1  movsd   qword ptr [rax-18h], xmm1
0x140012da6  movsd   qword ptr [rax-28h], xmm3
0x140012dab  mov     [rax-30h], r8
0x140012daf  call    _ctrlfp
0x140012db4  lea     rcx, [rsp+58h+var_38]
0x140012db9  call    __acrt_invoke_user_matherr
0x140012dbe  test    eax, eax
0x140012dc0  jnz     short loc_140012DC9
0x140012dc2  mov     ecx, ebx
0x140012dc4  call    _set_errno_from_matherr
0x140012dc9  movsd   xmm0, [rsp+58h+var_18]
0x140012dcf  add     rsp, 50h
0x140012dd3  pop     rbx
0x140012dd4  retn

// ===== _exception_enabled @ 0x140012dd8 =====

0x140012dd8  mov     [rsp+arg_0], rbx
0x140012ddd  mov     [rsp+arg_8], rsi
0x140012de2  push    rdi
0x140012de3  sub     rsp, 20h
0x140012de7  mov     ebx, ecx
0x140012de9  mov     rsi, rdx
0x140012dec  and     ebx, 1Fh
0x140012def  mov     edi, ecx
0x140012df1  test    cl, 8
0x140012df4  jz      short loc_140012E09
0x140012df6  test    dl, dl
0x140012df8  jns     short loc_140012E09
0x140012dfa  mov     ecx, 1
0x140012dff  call    _set_statfp
0x140012e04  and     ebx, 0FFFFFFF7h
0x140012e07  jmp     short loc_140012E60
0x140012e09  mov     ecx, 4
0x140012e0e  test    cl, dil
0x140012e11  jz      short loc_140012E24
0x140012e13  bt      rdx, 9
0x140012e18  jnb     short loc_140012E24
0x140012e1a  call    _set_statfp
0x140012e1f  and     ebx, 0FFFFFFFBh
0x140012e22  jmp     short loc_140012E60
0x140012e24  test    dil, 1
0x140012e28  jz      short loc_140012E40
0x140012e2a  bt      rdx, 0Ah
0x140012e2f  jnb     short loc_140012E40
0x140012e31  mov     ecx, 8
0x140012e36  call    _set_statfp
0x140012e3b  and     ebx, 0FFFFFFFEh
0x140012e3e  jmp     short loc_140012E60
0x140012e40  test    dil, 2
0x140012e44  jz      short loc_140012E60
0x140012e46  bt      rdx, 0Bh
0x140012e4b  jnb     short loc_140012E60
0x140012e4d  test    dil, 10h
0x140012e51  jz      short loc_140012E5D
0x140012e53  mov     ecx, 10h
0x140012e58  call    _set_statfp
0x140012e5d  and     ebx, 0FFFFFFFDh
0x140012e60  test    dil, 10h
0x140012e64  jz      short loc_140012E7A
0x140012e66  bt      rsi, 0Ch
0x140012e6b  jnb     short loc_140012E7A
0x140012e6d  mov     ecx, 20h ; ' '
0x140012e72  call    _set_statfp
0x140012e77  and     ebx, 0FFFFFFEFh
0x140012e7a  mov     rsi, [rsp+28h+arg_8]
0x140012e7f  xor     eax, eax
0x140012e81  test    ebx, ebx
0x140012e83  mov     rbx, [rsp+28h+arg_0]
0x140012e88  setz    al
0x140012e8b  add     rsp, 20h
0x140012e8f  pop     rdi
0x140012e90  retn

// ===== _handle_error @ 0x140012e94 =====

0x140012e94  mov     rax, rsp
0x140012e97  push    rbp
0x140012e98  push    rbx
0x140012e99  push    rsi
0x140012e9a  push    rdi
0x140012e9b  push    r14
0x140012e9d  lea     rbp, [rax-37h]
0x140012ea1  sub     rsp, 0F0h
0x140012ea8  movaps  xmmword ptr [rax-38h], xmm6
0x140012eac  mov     rax, cs:__security_cookie
0x140012eb3  xor     rax, rsp
0x140012eb6  mov     [rbp+2Fh+var_40], rax
0x140012eba  mov     esi, edx
0x140012ebc  mov     r14, rcx
0x140012ebf  mov     edx, 0FFC0h
0x140012ec4  mov     ecx, 1F80h
0x140012ec9  mov     edi, r9d
0x140012ecc  mov     rbx, r8
0x140012ecf  call    _ctrlfp
0x140012ed4  mov     ecx, [rbp+2Fh+arg_20]
0x140012ed7  mov     [rsp+110h+var_D0], rax
0x140012edc  mov     [rsp+110h+var_C8+8], rbx
0x140012ee1  movsd   xmm0, [rsp+110h+var_C8+8]
0x140012ee7  mov     rdx, [rsp+110h+var_D0]
0x140012eec  movsd   [rsp+110h+var_C8], xmm0
0x140012ef2  call    _exception_enabled
0x140012ef7  movsd   xmm6, [rbp+2Fh+arg_38]
0x140012efc  test    eax, eax
0x140012efe  jnz     short loc_140012F40
0x140012f00  cmp     [rbp+2Fh+arg_40], 2
0x140012f04  jnz     short loc_140012F17
0x140012f06  mov     eax, [rbp+2Fh+var_70]
0x140012f09  and     eax, 0FFFFFFE3h
0x140012f0c  movsd   [rbp+2Fh+var_80], xmm6
0x140012f11  or      eax, 3
0x140012f14  mov     [rbp+2Fh+var_70], eax
0x140012f17  mov     r8d, [rbp+2Fh+arg_20]
0x140012f1b  lea     rax, [rsp+110h+var_C8]
0x140012f20  mov     [rsp+110h+var_E8], rax
0x140012f25  lea     rdx, [rsp+110h+var_D0]
0x140012f2a  lea     rax, [rbp+2Fh+arg_30]
0x140012f2e  mov     r9d, esi
0x140012f31  lea     rcx, [rsp+60h]
0x140012f36  mov     [rsp+110h+var_F0], rax
0x140012f3b  call    _raise_exc
0x140012f40  call    __acrt_has_user_matherr
0x140012f45  test    al, al
0x140012f47  jz      short loc_140012F7D
0x140012f49  test    edi, edi
0x140012f4b  jz      short loc_140012F7D
0x140012f4d  mov     rax, [rsp+110h+var_D0]
0x140012f52  mov     r8, r14
0x140012f55  movsd   xmm0, [rsp+110h+var_C8]
0x140012f5b  mov     ecx, edi
0x140012f5d  movsd   xmm3, [rbp+2Fh+arg_30]
0x140012f62  mov     edx, [rbp+2Fh+arg_28]
0x140012f65  mov     [rsp+30h], rax
0x140012f6a  movsd   [rsp+110h+var_E8], xmm0
0x140012f70  movsd   [rsp+110h+var_F0], xmm6
0x140012f76  call    _call_matherr
0x140012f7b  jmp     short loc_140012F99
0x140012f7d  mov     ecx, edi
0x140012f7f  call    _set_errno_from_matherr
0x140012f84  mov     rcx, [rsp+110h+var_D0]
0x140012f89  mov     edx, 0FFC0h
0x140012f8e  call    _ctrlfp
0x140012f93  movsd   xmm0, [rsp+110h+var_C8]
0x140012f99  mov     rcx, [rbp+2Fh+var_40]
0x140012f9d  xor     rcx, rsp; StackCookie
0x140012fa0  call    __security_check_cookie
0x140012fa5  movaps  xmm6, [rsp+110h+var_38+8]
0x140012fad  add     rsp, 0F0h
0x140012fb4  pop     r14
0x140012fb6  pop     rdi
0x140012fb7  pop     rsi
0x140012fb8  pop     rbx
0x140012fb9  pop     rbp
0x140012fba  retn

// ===== __acrt_initialize_fma3 @ 0x140012fe0 =====

0x140012fe0  push    rbx
0x140012fe2  sub     rsp, 10h
0x140012fe6  xor     r8d, r8d
0x140012fe9  xor     ecx, ecx
0x140012feb  mov     cs:dword_140022038, r8d
0x140012ff2  lea     r9d, [r8+1]
0x140012ff6  mov     eax, r9d
0x140012ff9  cpuid
0x140012ffb  mov     [rsp+18h+var_18], eax
0x140012ffe  mov     eax, 18001000h
0x140013003  mov     [rsp+18h+var_10], ecx
0x140013007  and     ecx, eax
0x140013009  mov     [rsp+18h+var_14], ebx
0x14001300d  mov     [rsp+18h+var_C], edx
0x140013011  cmp     ecx, eax
0x140013013  jnz     short loc_140013041
0x140013015  xor     ecx, ecx
0x140013017  xgetbv
0x14001301a  shl     rdx, 20h
0x14001301e  or      rdx, rax
0x140013021  mov     [rsp+18h+arg_0], rdx
0x140013026  mov     rax, [rsp+18h+arg_0]
0x14001302b  mov     r8d, cs:dword_140022038
0x140013032  and     al, 6
0x140013034  cmp     al, 6
0x140013036  cmovz   r8d, r9d
0x14001303a  mov     cs:dword_140022038, r8d
0x140013041  mov     cs:dword_14002203C, r8d
0x140013048  xor     eax, eax
0x14001304a  add     rsp, 10h
0x14001304e  pop     rbx
0x14001304f  retn

// ===== _log10_special @ 0x140013050 =====

0x140013050  sub     rsp, 38h
0x140013054  lea     rax, aLog10
0x14001305b  mov     r9d, 1Bh
0x140013061  mov     [rsp+38h+var_18], rax
0x140013066  call    _log_special_common
0x14001306b  add     rsp, 38h
0x14001306f  retn

// ===== _log_special_common @ 0x140013070 =====

0x140013070  mov     rax, rsp
0x140013073  sub     rsp, 68h
0x140013077  movaps  xmmword ptr [rax-18h], xmm6
0x14001307b  movaps  xmm6, xmm1
0x14001307e  mov     edx, r9d
0x140013081  movaps  xmm3, xmm0
0x140013084  sub     r8d, 1
0x140013088  jz      short loc_1400130B4
0x14001308a  cmp     r8d, 1
0x14001308e  jnz     short loc_1400130F9
0x140013090  mov     [rax-28h], r8d
0x140013094  xorps   xmm2, xmm2
0x140013097  movsd   qword ptr [rax-30h], xmm2
0x14001309c  mov     r9d, r8d
0x14001309f  movsd   qword ptr [rax-38h], xmm0
0x1400130a4  mov     dword ptr [rax-40h], 21h ; '!'
0x1400130ab  mov     dword ptr [rax-48h], 8
0x1400130b2  jmp     short loc_1400130E1
0x1400130b4  mov     [rsp+68h+var_28], 1
0x1400130bc  xorps   xmm0, xmm0
0x1400130bf  movsd   [rsp+68h+var_30], xmm0
0x1400130c5  mov     r9d, 2
0x1400130cb  movsd   [rsp+68h+var_38], xmm3
0x1400130d1  mov     [rsp+68h+var_40], 22h ; '"'
0x1400130d9  mov     [rsp+68h+var_48], 4
0x1400130e1  mov     rcx, [rsp+68h+arg_20]
0x1400130e9  movsd   [rsp+68h+arg_8], xmm1
0x1400130ef  mov     r8, [rsp+68h+arg_8]
0x1400130f4  call    _handle_error
0x1400130f9  movaps  xmm0, xmm6
0x1400130fc  movaps  xmm6, [rsp+68h+var_18]
0x140013101  add     rsp, 68h
0x140013105  retn

// ===== sub_140013108 @ 0x140013108 =====

0x140013108  sub     rsp, 48h
0x14001310c  and     [rsp+48h+var_18], 0
0x140013112  lea     rcx, aConout; "CONOUT$"
0x140013119  and     [rsp+48h+var_20], 0
0x14001311e  mov     r8d, 3; dwShareMode
0x140013124  xor     r9d, r9d; lpSecurityAttributes
0x140013127  mov     [rsp+48h+dwCreationDisposition], r8d; dwCreationDisposition
0x14001312c  mov     edx, 40000000h; dwDesiredAccess
0x140013131  call    cs:CreateFileW; KERNEL32
0x140013137  mov     qword ptr cs:unk_140020B50, rax
0x14001313e  add     rsp, 48h
0x140013142  retn

// ===== sub_140013144 @ 0x140013144 =====

0x140013144  sub     rsp, 28h
0x140013148  mov     rcx, qword ptr cs:unk_140020B50; hObject
0x14001314f  lea     rax, [rcx+2]
0x140013153  cmp     rax, 1
0x140013157  jbe     short loc_14001315F
0x140013159  call    cs:CloseHandle; KERNEL32
0x14001315f  add     rsp, 28h
0x140013163  retn

// ===== _get_fpsr @ 0x140013180 =====

0x140013180  sub     rsp, 8
0x140013184  stmxcsr [rsp+8+var_8]
0x140013188  mov     eax, [rsp+8+var_8]
0x14001318b  add     rsp, 8
0x14001318f  retn

// ===== _set_fpsr @ 0x140013190 =====

0x140013190  mov     [rsp+arg_0], ecx
0x140013194  ldmxcsr [rsp+arg_0]
0x140013199  retn

// ===== _fclrf @ 0x14001319a =====

0x14001319a  stmxcsr [rsp+arg_0]
0x14001319f  mov     ecx, 0FFFFFFC0h
0x1400131a4  and     [rsp+arg_0], ecx
0x1400131a8  ldmxcsr [rsp+arg_0]
0x1400131ad  retn

// ===== _return @ 0x1400131cc =====

0x1400131cc  retn

// ===== _raise_exc @ 0x1400131d0 =====

0x1400131d0  sub     rsp, 48h
0x1400131d4  and     [rsp+48h+var_18], 0
0x1400131d9  mov     rax, [rsp+48h+arg_28]
0x1400131de  mov     [rsp+48h+var_20], rax
0x1400131e3  mov     rax, [rsp+48h+arg_20]
0x1400131e8  mov     [rsp+48h+var_28], rax
0x1400131ed  call    _raise_exc_ex
0x1400131f2  add     rsp, 48h
0x1400131f6  retn

// ===== _raise_exc_ex @ 0x1400131f8 =====

0x1400131f8  mov     rax, rsp
0x1400131fb  mov     [rax+10h], rbx
0x1400131ff  mov     [rax+18h], rsi
0x140013203  mov     [rax+20h], rdi
0x140013207  mov     [rax+8], rcx
0x14001320b  push    rbp
0x14001320c  mov     rbp, rsp
0x14001320f  sub     rsp, 20h
0x140013213  mov     rbx, rdx
0x140013216  mov     esi, r9d
0x140013219  xor     edx, edx
0x14001321b  mov     edi, 0C000000Dh
0x140013220  mov     [rcx+4], edx
0x140013223  mov     rax, [rbp+Arguments]
0x140013227  mov     [rax+8], edx
0x14001322a  mov     rax, [rbp+Arguments]
0x14001322e  mov     [rax+0Ch], edx
0x140013231  test    r8b, 10h
0x140013235  jz      short loc_140013244
0x140013237  mov     rax, [rbp+Arguments]
0x14001323b  mov     edi, 0C000008Fh
0x140013240  or      dword ptr [rax+4], 1
0x140013244  test    r8b, 2
0x140013248  jz      short loc_140013257
0x14001324a  mov     rax, [rbp+Arguments]
0x14001324e  mov     edi, 0C0000093h
0x140013253  or      dword ptr [rax+4], 2
0x140013257  test    r8b, 1
0x14001325b  jz      short loc_14001326A
0x14001325d  mov     rax, [rbp+Arguments]
0x140013261  mov     edi, 0C0000091h
0x140013266  or      dword ptr [rax+4], 4
0x14001326a  test    r8b, 4
0x14001326e  jz      short loc_14001327D
0x140013270  mov     rax, [rbp+Arguments]
0x140013274  mov     edi, 0C000008Eh
0x140013279  or      dword ptr [rax+4], 8
0x14001327d  test    r8b, 8
0x140013281  jz      short loc_140013290
0x140013283  mov     rax, [rbp+Arguments]
0x140013287  mov     edi, 0C0000090h
0x14001328c  or      dword ptr [rax+4], 10h
0x140013290  mov     rcx, [rbp+Arguments]
0x140013294  mov     rax, [rbx]
0x140013297  shr     rax, 7
0x14001329b  shl     eax, 4
0x14001329e  not     eax
0x1400132a0  xor     eax, [rcx+8]
0x1400132a3  and     eax, 10h
0x1400132a6  xor     [rcx+8], eax
0x1400132a9  mov     rcx, [rbp+Arguments]
0x1400132ad  mov     rax, [rbx]
0x1400132b0  shr     rax, 9
0x1400132b4  shl     eax, 3
0x1400132b7  not     eax
0x1400132b9  xor     eax, [rcx+8]
0x1400132bc  and     eax, 8
0x1400132bf  xor     [rcx+8], eax
0x1400132c2  mov     rcx, [rbp+Arguments]
0x1400132c6  mov     rax, [rbx]
0x1400132c9  shr     rax, 0Ah
0x1400132cd  shl     eax, 2
0x1400132d0  not     eax
0x1400132d2  xor     eax, [rcx+8]
0x1400132d5  and     eax, 4
0x1400132d8  xor     [rcx+8], eax
0x1400132db  mov     rcx, [rbp+Arguments]
0x1400132df  mov     rax, [rbx]
0x1400132e2  shr     rax, 0Bh
0x1400132e6  add     eax, eax
0x1400132e8  not     eax
0x1400132ea  xor     eax, [rcx+8]
0x1400132ed  and     eax, 2
0x1400132f0  xor     [rcx+8], eax
0x1400132f3  mov     eax, [rbx]
0x1400132f5  mov     rcx, [rbp+Arguments]
0x1400132f9  shr     rax, 0Ch
0x1400132fd  not     eax
0x1400132ff  xor     eax, [rcx+8]
0x140013302  and     eax, 1
0x140013305  xor     [rcx+8], eax
0x140013308  call    _statfp
0x14001330d  mov     rdx, rax
0x140013310  test    al, 1
0x140013312  jz      short loc_14001331C
0x140013314  mov     rcx, [rbp+Arguments]
0x140013318  or      dword ptr [rcx+0Ch], 10h
0x14001331c  test    al, 4
0x14001331e  jz      short loc_140013328
0x140013320  mov     rcx, [rbp+Arguments]
0x140013324  or      dword ptr [rcx+0Ch], 8
0x140013328  test    al, 8
0x14001332a  jz      short loc_140013334
0x14001332c  mov     rax, [rbp+Arguments]
0x140013330  or      dword ptr [rax+0Ch], 4
0x140013334  test    dl, 10h
0x140013337  jz      short loc_140013341
0x140013339  mov     rax, [rbp+Arguments]
0x14001333d  or      dword ptr [rax+0Ch], 2
0x140013341  test    dl, 20h
0x140013344  jz      short loc_14001334E
0x140013346  mov     rax, [rbp+Arguments]
0x14001334a  or      dword ptr [rax+0Ch], 1
0x14001334e  mov     eax, [rbx]
0x140013350  mov     ecx, 6000h
0x140013355  and     rax, rcx
0x140013358  jz      short loc_140013398
0x14001335a  cmp     rax, 2000h
0x140013360  jz      short loc_140013388
0x140013362  cmp     rax, 4000h
0x140013368  jz      short loc_140013378
0x14001336a  cmp     rax, rcx
0x14001336d  jnz     short loc_14001339F
0x14001336f  mov     rax, [rbp+Arguments]
0x140013373  or      dword ptr [rax], 3
0x140013376  jmp     short loc_14001339F
0x140013378  mov     rax, [rbp+Arguments]
0x14001337c  and     dword ptr [rax], 0FFFFFFFEh
0x14001337f  mov     rax, [rbp+Arguments]
0x140013383  or      dword ptr [rax], 2
0x140013386  jmp     short loc_14001339F
0x140013388  mov     rax, [rbp+Arguments]
0x14001338c  and     dword ptr [rax], 0FFFFFFFDh
0x14001338f  mov     rax, [rbp+Arguments]
0x140013393  or      dword ptr [rax], 1
0x140013396  jmp     short loc_14001339F
0x140013398  mov     rax, [rbp+Arguments]
0x14001339c  and     dword ptr [rax], 0FFFFFFFCh
0x14001339f  mov     rax, [rbp+Arguments]
0x1400133a3  and     esi, 0FFFh
0x1400133a9  shl     esi, 5
0x1400133ac  and     dword ptr [rax], 0FFFE001Fh
0x1400133b2  mov     rax, [rbp+Arguments]
0x1400133b6  or      [rax], esi
0x1400133b8  mov     rax, [rbp+Arguments]
0x1400133bc  mov     rsi, [rbp+arg_28]
0x1400133c0  or      dword ptr [rax+20h], 1
0x1400133c4  cmp     [rbp+arg_30], 0
0x1400133c8  jz      short loc_1400133FD
0x1400133ca  mov     rax, [rbp+Arguments]
0x1400133ce  mov     edx, 0FFFFFFE1h
0x1400133d3  and     [rax+20h], edx
0x1400133d6  mov     rax, [rbp+arg_20]
0x1400133da  mov     ecx, [rax]
0x1400133dc  mov     rax, [rbp+Arguments]
0x1400133e0  mov     [rax+10h], ecx
0x1400133e3  mov     rax, [rbp+Arguments]
0x1400133e7  or      dword ptr [rax+60h], 1
0x1400133eb  mov     rax, [rbp+Arguments]
0x1400133ef  and     [rax+60h], edx
0x1400133f2  mov     rax, [rbp+Arguments]
0x1400133f6  mov     ecx, [rsi]
0x1400133f8  mov     [rax+50h], ecx
0x1400133fb  jmp     short loc_140013445
0x1400133fd  mov     rcx, [rbp+Arguments]
0x140013401  mov     r8d, 0FFFFFFE3h
0x140013407  mov     eax, [rcx+20h]
0x14001340a  and     eax, r8d
0x14001340d  or      eax, 2
0x140013410  mov     [rcx+20h], eax
0x140013413  mov     rax, [rbp+arg_20]
0x140013417  mov     rcx, [rax]
0x14001341a  mov     rax, [rbp+Arguments]
0x14001341e  mov     [rax+10h], rcx
0x140013422  mov     rax, [rbp+Arguments]
0x140013426  or      dword ptr [rax+60h], 1
0x14001342a  mov     rdx, [rbp+Arguments]
0x14001342e  mov     eax, [rdx+60h]
0x140013431  and     eax, r8d
0x140013434  or      eax, 2
0x140013437  mov     [rdx+60h], eax
0x14001343a  mov     rax, [rbp+Arguments]
0x14001343e  mov     rdx, [rsi]
0x140013441  mov     [rax+50h], rdx
0x140013445  call    _clrfp
0x14001344a  xor     edx, edx; dwExceptionFlags
0x14001344c  lea     r9, [rbp+Arguments]; lpArguments
0x140013450  mov     ecx, edi; dwExceptionCode
0x140013452  lea     r8d, [rdx+1]; nNumberOfArguments
0x140013456  call    cs:RaiseException; KERNEL32
0x14001345c  mov     rcx, [rbp+Arguments]
0x140013460  test    byte ptr [rcx+8], 10h
0x140013464  jz      short loc_14001346B
0x140013466  btr     qword ptr [rbx], 7
0x14001346b  test    byte ptr [rcx+8], 8
0x14001346f  jz      short loc_140013476
0x140013471  btr     qword ptr [rbx], 9
0x140013476  test    byte ptr [rcx+8], 4
0x14001347a  jz      short loc_140013481
0x14001347c  btr     qword ptr [rbx], 0Ah
0x140013481  test    byte ptr [rcx+8], 2
0x140013485  jz      short loc_14001348C
0x140013487  btr     qword ptr [rbx], 0Bh
0x14001348c  test    byte ptr [rcx+8], 1
0x140013490  jz      short loc_140013497
0x140013492  btr     qword ptr [rbx], 0Ch
0x140013497  mov     eax, [rcx]
0x140013499  and     eax, 3
0x14001349c  jz      short loc_1400134CE
0x14001349e  sub     eax, 1
0x1400134a1  jz      short loc_1400134C2
0x1400134a3  sub     eax, 1
0x1400134a6  jz      short loc_1400134B6
0x1400134a8  cmp     eax, 1
0x1400134ab  jnz     short loc_1400134D5
0x1400134ad  or      qword ptr [rbx], 6000h
0x1400134b4  jmp     short loc_1400134D5
0x1400134b6  btr     qword ptr [rbx], 0Dh
0x1400134bb  bts     qword ptr [rbx], 0Eh
0x1400134c0  jmp     short loc_1400134D5
0x1400134c2  btr     qword ptr [rbx], 0Eh
0x1400134c7  bts     qword ptr [rbx], 0Dh
0x1400134cc  jmp     short loc_1400134D5
0x1400134ce  and     qword ptr [rbx], 0FFFFFFFFFFFF9FFFh
0x1400134d5  cmp     [rbp+arg_30], 0
0x1400134d9  jz      short loc_1400134E2
0x1400134db  mov     eax, [rcx+50h]
0x1400134de  mov     [rsi], eax
0x1400134e0  jmp     short loc_1400134E9
0x1400134e2  mov     rax, [rcx+50h]
0x1400134e6  mov     [rsi], rax
0x1400134e9  mov     rbx, [rsp+20h+arg_8]
0x1400134ee  mov     rsi, [rsp+20h+arg_10]
0x1400134f3  mov     rdi, [rsp+20h+arg_18]
0x1400134f8  add     rsp, 20h
0x1400134fc  pop     rbp
0x1400134fd  retn

// ===== _set_errno_from_matherr @ 0x140013500 =====

0x140013500  sub     rsp, 28h
0x140013504  cmp     ecx, 1
0x140013507  jz      short loc_14001351E
0x140013509  lea     eax, [rcx-2]
0x14001350c  cmp     eax, 1
0x14001350f  ja      short loc_140013529
0x140013511  call    _errno
0x140013516  mov     dword ptr [rax], 22h ; '"'
0x14001351c  jmp     short loc_140013529
0x14001351e  call    _errno
0x140013523  mov     dword ptr [rax], 21h ; '!'
0x140013529  add     rsp, 28h
0x14001352d  retn

// ===== _clrfp @ 0x140013530 =====

0x140013530  push    rbx
0x140013532  sub     rsp, 20h
0x140013536  call    _get_fpsr
0x14001353b  mov     ebx, eax
0x14001353d  and     ebx, 3Fh
0x140013540  call    _fclrf
0x140013545  mov     eax, ebx
0x140013547  add     rsp, 20h
0x14001354b  pop     rbx
0x14001354c  retn

// ===== _ctrlfp @ 0x140013550 =====

0x140013550  mov     [rsp+arg_10], rbx
0x140013555  mov     [rsp+arg_18], rsi
0x14001355a  push    rdi
0x14001355b  sub     rsp, 20h
0x14001355f  mov     rbx, rdx
0x140013562  mov     rdi, rcx
0x140013565  call    _get_fpsr
0x14001356a  mov     esi, eax
0x14001356c  mov     [rsp+28h+arg_8], eax
0x140013570  mov     ecx, ebx
0x140013572  not     ecx
0x140013574  or      ecx, 0FFFF807Fh
0x14001357a  and     ecx, eax
0x14001357c  and     edi, ebx
0x14001357e  or      ecx, edi
0x140013580  mov     [rsp+28h+arg_0], ecx
0x140013584  cmp     cs:byte_140020B60, 0
0x14001358b  jz      short loc_1400135B2
0x14001358d  test    cl, 40h
0x140013590  jz      short loc_1400135B2
0x140013592  call    _set_fpsr
0x140013597  jmp     short loc_1400135B0
0x140013599  mov     cs:byte_140020B60, 0
0x1400135a0  mov     ecx, [rsp+28h+arg_0]
0x1400135a4  and     ecx, 0FFFFFFBFh
0x1400135a7  call    _set_fpsr
0x1400135ac  mov     esi, [rsp+28h+arg_8]
0x1400135b0  jmp     short loc_1400135BA
0x1400135b2  and     ecx, 0FFFFFFBFh
0x1400135b5  call    _set_fpsr
0x1400135ba  mov     eax, esi
0x1400135bc  mov     rbx, [rsp+28h+arg_10]
0x1400135c1  mov     rsi, [rsp+28h+arg_18]
0x1400135c6  add     rsp, 20h
0x1400135ca  pop     rdi
0x1400135cb  retn
0x140013b03  push    rbp; Microsoft VisualC 64bit universal runtime
0x140013b05  sub     rsp, 20h
0x140013b09  mov     rbp, rdx
0x140013b0c  mov     rax, [rcx]
0x140013b0f  cmp     dword ptr [rax], 0C0000005h
0x140013b15  jz      short loc_140013B23
0x140013b17  cmp     dword ptr [rax], 0C000001Dh
0x140013b1d  jz      short loc_140013B23
0x140013b1f  xor     eax, eax
0x140013b21  jmp     short loc_140013B28
0x140013b23  mov     eax, 1
0x140013b28  add     rsp, 20h
0x140013b2c  pop     rbp
0x140013b2d  retn

// ===== _set_statfp @ 0x1400135cc =====

0x1400135cc  push    rbx
0x1400135ce  sub     rsp, 20h
0x1400135d2  mov     rbx, rcx
0x1400135d5  call    _get_fpsr
0x1400135da  and     ebx, 3Fh
0x1400135dd  or      eax, ebx
0x1400135df  mov     ecx, eax
0x1400135e1  add     rsp, 20h
0x1400135e5  pop     rbx
0x1400135e6  jmp     _set_fpsr

// ===== _statfp @ 0x1400135ec =====

0x1400135ec  sub     rsp, 28h
0x1400135f0  call    _get_fpsr
0x1400135f5  and     eax, 3Fh
0x1400135f8  add     rsp, 28h
0x1400135fc  retn

// ===== IsProcessorFeaturePresent @ 0x1400135fd =====

0x1400135fd  jmp     cs:__imp_IsProcessorFeaturePresent; KERNEL32

// ===== _FindPESection @ 0x140013610 =====

0x140013610  movsxd  r8, dword ptr [rcx+3Ch]
0x140013614  xor     r9d, r9d
0x140013617  add     r8, rcx
0x14001361a  mov     r10, rdx
0x14001361d  movzx   eax, word ptr [r8+14h]
0x140013622  movzx   r11d, word ptr [r8+6]
0x140013627  add     rax, 18h
0x14001362b  add     rax, r8
0x14001362e  test    r11d, r11d
0x140013631  jz      short loc_140013651
0x140013633  mov     edx, [rax+0Ch]
0x140013636  cmp     r10, rdx
0x140013639  jb      short loc_140013645
0x14001363b  mov     ecx, [rax+8]
0x14001363e  add     ecx, edx
0x140013640  cmp     r10, rcx
0x140013643  jb      short locret_140013653
0x140013645  inc     r9d
0x140013648  add     rax, 28h ; '('
0x14001364c  cmp     r9d, r11d
0x14001364f  jb      short loc_140013633
0x140013651  xor     eax, eax
0x140013653  retn

// ===== _IsNonwritableInCurrentImage @ 0x140013660 =====

0x140013660  mov     [rsp+arg_0], rbx
0x140013665  push    rdi
0x140013666  sub     rsp, 20h
0x14001366a  mov     rbx, rcx
0x14001366d  lea     rdi, cs:140000000h
0x140013674  mov     rcx, rdi
0x140013677  call    _ValidateImageBase
0x14001367c  test    eax, eax
0x14001367e  jz      short loc_1400136A2
0x140013680  sub     rbx, rdi
0x140013683  mov     rdx, rbx
0x140013686  mov     rcx, rdi
0x140013689  call    _FindPESection
0x14001368e  test    rax, rax
0x140013691  jz      short loc_1400136A2
0x140013693  mov     eax, [rax+24h]
0x140013696  shr     eax, 1Fh
0x140013699  not     eax
0x14001369b  and     eax, 1
0x14001369e  jmp     short loc_1400136A2
0x1400136a0  xor     eax, eax
0x1400136a2  mov     rbx, [rsp+28h+arg_0]
0x1400136a7  add     rsp, 20h
0x1400136ab  pop     rdi
0x1400136ac  retn
0x140013b30  push    rbp; Microsoft VisualC v14 64bit runtime
0x140013b32  sub     rsp, 20h
0x140013b36  mov     rbp, rdx
0x140013b39  mov     rax, [rcx]
0x140013b3c  xor     ecx, ecx
0x140013b3e  cmp     dword ptr [rax], 0C0000005h
0x140013b44  setz    cl
0x140013b47  mov     eax, ecx
0x140013b49  add     rsp, 20h
0x140013b4d  pop     rbp
0x140013b4e  retn

// ===== _ValidateImageBase @ 0x1400136b0 =====

0x1400136b0  mov     eax, 5A4Dh
0x1400136b5  cmp     [rcx], ax
0x1400136b8  jnz     short loc_1400136DA
0x1400136ba  movsxd  rax, dword ptr [rcx+3Ch]
0x1400136be  add     rax, rcx
0x1400136c1  cmp     dword ptr [rax], 4550h
0x1400136c7  jnz     short loc_1400136DA
0x1400136c9  mov     ecx, 20Bh
0x1400136ce  cmp     [rax+18h], cx
0x1400136d2  jnz     short loc_1400136DA
0x1400136d4  mov     eax, 1
0x1400136d9  retn
0x1400136da  xor     eax, eax
0x1400136dc  retn

// ===== memcmp @ 0x1400136f0 =====

0x1400136f0  sub     rdx, rcx
0x1400136f3  cmp     r8, 8
0x1400136f7  jb      short mcmp30
0x1400136f9  test    cl, 7
0x1400136fc  jz      short mcmp20
0x1400136fe  xchg    ax, ax
0x140013700  mov     al, [rcx]
0x140013702  cmp     al, [rcx+rdx]
0x140013705  jnz     short mcmp_not_equal
0x140013707  inc     rcx
0x14001370a  dec     r8
0x14001370d  test    cl, 7
0x140013710  jnz     short mcmp10
0x140013712  mov     r9, r8
0x140013715  shr     r9, 3
0x140013719  jnz     short mcmp50
0x14001371b  test    r8, r8
0x14001371e  jz      short mcmp_equal
0x140013720  mov     al, [rcx]
0x140013722  cmp     al, [rcx+rdx]
0x140013725  jnz     short mcmp_not_equal
0x140013727  inc     rcx
0x14001372a  dec     r8
0x14001372d  jnz     short mcmp40
0x14001372f  xor     rax, rax
0x140013732  retn
0x140013733  sbb     eax, eax
0x140013735  sbb     eax, 0FFFFFFFFh
0x140013738  retn
0x14001373a  shr     r9, 2
0x14001373e  jz      short mcmp70
0x140013740  mov     rax, [rcx]
0x140013743  cmp     rax, [rcx+rdx]
0x140013747  jnz     short mcmp_adjust0
0x140013749  mov     rax, [rcx+8]
0x14001374d  cmp     rax, [rcx+rdx+8]
0x140013752  jnz     short mcmp_adjust8
0x140013754  mov     rax, [rcx+10h]
0x140013758  cmp     rax, [rcx+rdx+10h]
0x14001375d  jnz     short mcmp_adjust16
0x14001375f  mov     rax, [rcx+18h]
0x140013763  cmp     rax, [rcx+rdx+18h]
0x140013768  jnz     short mcmp_adjust24
0x14001376a  add     rcx, 20h ; ' '
0x14001376e  dec     r9
0x140013771  jnz     short mcmp60
0x140013773  and     r8, 1Fh
0x140013777  mov     r9, r8
0x14001377a  shr     r9, 3
0x14001377e  jz      short mcmp30
0x140013780  mov     rax, [rcx]
0x140013783  cmp     rax, [rcx+rdx]
0x140013787  jnz     short mcmp_adjust0
0x140013789  add     rcx, 8
0x14001378d  dec     r9
0x140013790  jnz     short mcmp80
0x140013792  and     r8, 7
0x140013796  jmp     short mcmp30
0x140013798  add     rcx, 8
0x14001379c  add     rcx, 8
0x1400137a0  add     rcx, 8
0x1400137a4  mov     rcx, [rdx+rcx]
0x1400137a8  bswap   rax
0x1400137ab  bswap   rcx
0x1400137ae  cmp     rax, rcx
0x1400137b1  sbb     eax, eax
0x1400137b3  sbb     eax, 0FFFFFFFFh
0x1400137b6  retn

// ===== strrchr @ 0x1400137b8 =====

0x1400137b8  sub     rsp, 18h
0x1400137bc  xor     r8d, r8d
0x1400137bf  mov     r9, rcx
0x1400137c2  test    edx, edx
0x1400137c4  jnz     short loc_14001380E
0x1400137c6  and     r9d, 0Fh
0x1400137ca  mov     rdx, rcx
0x1400137cd  and     rdx, 0FFFFFFFFFFFFFFF0h
0x1400137d1  mov     ecx, r9d
0x1400137d4  or      r9d, 0FFFFFFFFh
0x1400137d8  xorps   xmm1, xmm1
0x1400137db  shl     r9d, cl
0x1400137de  movdqu  xmm0, xmmword ptr [rdx]
0x1400137e2  pcmpeqb xmm0, xmm1
0x1400137e6  pmovmskb eax, xmm0
0x1400137ea  and     eax, r9d
0x1400137ed  jnz     short loc_140013803
0x1400137ef  add     rdx, 10h
0x1400137f3  movdqu  xmm0, xmmword ptr [rdx]
0x1400137f7  pcmpeqb xmm0, xmm1
0x1400137fb  pmovmskb eax, xmm0
0x1400137ff  test    eax, eax
0x140013801  jz      short loc_1400137EF
0x140013803  bsf     eax, eax
0x140013806  add     rax, rdx
0x140013809  jmp     loc_1400138B3
0x14001380e  cmp     cs:dword_140020018, 2
0x140013815  jge     loc_1400138D1
0x14001381b  movzx   eax, dl
0x14001381e  mov     r10, r9
0x140013821  and     r9d, 0Fh
0x140013825  and     r10, 0FFFFFFFFFFFFFFF0h
0x140013829  mov     ecx, eax
0x14001382b  xorps   xmm2, xmm2
0x14001382e  shl     ecx, 8
0x140013831  or      ecx, eax
0x140013833  movd    xmm0, ecx
0x140013837  mov     ecx, r9d
0x14001383a  pshuflw xmm1, xmm0, 0
0x14001383f  or      r9d, 0FFFFFFFFh
0x140013843  xorps   xmm0, xmm0
0x140013846  shl     r9d, cl
0x140013849  pcmpeqb xmm0, xmmword ptr [r10]
0x14001384e  pmovmskb ecx, xmm0
0x140013852  pshufd  xmm3, xmm1, 0
0x140013857  movdqa  xmm0, xmm3
0x14001385b  pcmpeqb xmm0, xmmword ptr [r10]
0x140013860  pmovmskb edx, xmm0
0x140013864  and     edx, r9d
0x140013867  and     ecx, r9d
0x14001386a  jnz     short loc_14001389A
0x14001386c  bsr     ecx, edx
0x14001386f  movdqa  xmm1, xmm2
0x140013873  movdqa  xmm0, xmm3
0x140013877  add     rcx, r10
0x14001387a  test    edx, edx
0x14001387c  cmovnz  r8, rcx
0x140013880  add     r10, 10h
0x140013884  pcmpeqb xmm1, xmmword ptr [r10]
0x140013889  pcmpeqb xmm0, xmmword ptr [r10]
0x14001388e  pmovmskb ecx, xmm1
0x140013892  pmovmskb edx, xmm0
0x140013896  test    ecx, ecx
0x140013898  jz      short loc_14001386C
0x14001389a  mov     eax, ecx
0x14001389c  neg     eax
0x14001389e  and     eax, ecx
0x1400138a0  dec     eax
0x1400138a2  and     edx, eax
0x1400138a4  bsr     ecx, edx
0x1400138a7  add     rcx, r10
0x1400138aa  test    edx, edx
0x1400138ac  cmovnz  r8, rcx
0x1400138b0  mov     rax, r8
0x1400138b3  add     rsp, 18h
0x1400138b7  retn
0x1400138b8  movsx   eax, byte ptr [r9]
0x1400138bc  mov     rcx, r9
0x1400138bf  cmp     eax, edx
0x1400138c1  cmovnz  rcx, r8
0x1400138c5  cmp     byte ptr [r9], 0
0x1400138c9  mov     r8, rcx
0x1400138cc  jz      short loc_1400138FC
0x1400138ce  inc     r9
0x1400138d1  test    r9b, 0Fh
0x1400138d5  jnz     short loc_1400138B8
0x1400138d7  movzx   eax, dl
0x1400138da  movd    xmm0, eax
0x1400138de  pcmpistri xmm0, xmmword ptr [r9], 40h ; '@'
0x1400138e5  jnb     short loc_1400138F4
0x1400138e7  movsxd  r8, ecx
0x1400138ea  add     r8, r9
0x1400138ed  pcmpistri xmm0, xmmword ptr [r9], 40h ; '@'
0x1400138f4  jz      short loc_1400138B0
0x1400138f6  add     r9, 10h
0x1400138fa  jmp     short loc_1400138DE
0x1400138fc  mov     rax, rcx
0x1400138ff  jmp     short loc_1400138B3

// ===== _guard_dispatch_icall_nop @ 0x140013920 =====

0x140013920  jmp     rax

// ===== sub_14008DE87 @ 0x14008de87 =====

0x14008de87  pushfq
0x14008de88  push    rax
0x14008de89  push    rcx
0x14008de8a  push    rdx
0x14008de8b  push    rbx
0x14008de8c  push    rbx
0x14008de8d  push    rbp
0x14008de8e  push    rsi
0x14008de8f  push    rdi
0x14008de90  push    r15
0x14008de92  push    r14
0x14008de94  push    r13
0x14008de96  push    r12
0x14008de98  push    r11
0x14008de9a  push    r10
0x14008de9c  push    r9
0x14008de9e  push    r8
0x14008dea0  call    $+5
0x14008dea5  pop     rcx
0x14008dea6  sub     rcx, 1Eh
0x14008deaa  sub     rcx, 8DE87h
0x14008deb1  mov     ebp, 58800h
0x14008deb6  add     rbp, rcx
0x14008deb9  push    rcx
0x14008deba  mov     ecx, 1
0x14008debf  mov     ebx, 4Bh ; 'K'
0x14008dec4  xor     eax, eax
0x14008dec6  lock cmpxchg [rbx+rbp], ecx
0x14008decb  jz      short loc_14008DED1
0x14008decd  pause
0x14008decf  jmp     short loc_14008DEC4
0x14008ded1  pop     rcx
0x14008ded2  mov     ebx, 0E4h
0x14008ded7  mov     [rbx+rbp], rcx
0x14008dedb  mov     ebx, 25h ; '%'
0x14008dee0  mov     rax, [rsp+88h+arg_0]
0x14008dee8  add     rax, rcx
0x14008deeb  mov     [rbx+rbp], rax
0x14008deef  mov     eax, 8DAC7h
0x14008def4  add     rax, rcx
0x14008def7  mov     ebx, 11Bh
0x14008defc  mov     rdx, [rbx+rbp]
0x14008df00  cmp     rdx, rax
0x14008df03  jz      short loc_14008DF25
0x14008df05  push    rbx
0x14008df06  mov     ebx, 3C0h
0x14008df0b  shr     ebx, 3
0x14008df0e  push    rax
0x14008df0f  test    rbx, rbx
0x14008df12  jz      short loc_14008DF1F
0x14008df14  add     [rax], rcx
0x14008df17  add     rax, 8
0x14008df1b  dec     ebx
0x14008df1d  jmp     short loc_14008DF0F
0x14008df1f  pop     rax
0x14008df20  pop     rbx
0x14008df21  mov     [rbx+rbp], rax
0x14008df25  mov     rbx, [rsp+88h]
0x14008df2d  shl     rbx, 3
0x14008df31  add     rax, rbx
0x14008df34  jmp     qword ptr [rax]


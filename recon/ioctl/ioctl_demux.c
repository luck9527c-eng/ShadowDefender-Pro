FUNCTION 0x280063121 .. 0x280063c5d
// positive sp value has been detected, the output may be wrong!
NTSTATUS __fastcall sub_280063121()
{
  __int64 v0; // rbx
  IRP *v1; // rbp
  __int64 v2; // rdi
  __int64 v3; // r12
  int v4; // r13d
  __int64 v5; // r14
  int v6; // eax
  NTSTATUS v7; // esi
  struct _KTHREAD *CurrentThread; // rbx
  PEPROCESS CurrentProcess; // rax
  PEPROCESS v10; // rbx
  unsigned int v11; // ecx
  PEPROCESS *v12; // rdx
  __int64 v13; // rax
  _QWORD *v14; // rcx
  struct _FAST_MUTEX *v15; // rcx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  _QWORD *v24; // rbx
  void *v25; // rcx
  _QWORD *v26; // r11
  struct _KTHREAD *v27; // rbx
  PEPROCESS v28; // rax
  struct _KTHREAD *v29; // rbx
  PEPROCESS v30; // rsi
  __int64 k; // r11
  struct _KTHREAD *v32; // rbx
  PEPROCESS v33; // rax
  struct _KTHREAD *v34; // rbx
  PEPROCESS v35; // rsi
  __int64 m; // r11
  struct _KTHREAD *v37; // rbx
  PEPROCESS v38; // rax
  NTSTATUS v39; // eax
  PVOID v40; // rsi
  PEPROCESS v41; // r12
  char v42; // bl
  __int64 j; // r11
  __int64 i; // rsi
  _QWORD *PoolWithTag; // r15
  _QWORD *v46; // r11
  struct _KTHREAD *v47; // rbx
  PEPROCESS v48; // rax
  int v49; // ecx
  int v50; // eax
  int v51; // r13d
  int v52; // ecx
  __int64 v53; // r12
  struct _DEVICE_OBJECT *v54; // r14
  __int64 v55; // rcx
  IRP *Irp; // rax
  __int64 n; // rdi
  PVOID v59; // [rsp+48h] [rbp-80h] BYREF
  PVOID v60; // [rsp+50h] [rbp-78h] BYREF
  PVOID v61; // [rsp+60h] [rbp-68h] BYREF
  PVOID v62; // [rsp+68h] [rbp-60h] BYREF
  _QWORD v63[11]; // [rsp+70h] [rbp-58h] BYREF
  struct _KTHREAD *v64; // [rsp+D0h] [rbp+8h] BYREF
  int v65; // [rsp+D8h] [rbp+10h]
  PVOID *Object; // [rsp+E8h] [rbp+20h]

  if ( (PDEVICE_OBJECT)v2 == DeviceObject )
  {
    if ( *(_DWORD *)(v5 + 16) != 136 || *(_DWORD *)(v5 + 8) != 136 )
      goto LABEL_124;
    v6 = *(_DWORD *)(v5 + 24);
    switch ( v6 )
    {
      case -2147471204:
        LODWORD(v64) = 0;
        v7 = ((__int64 (__fastcall *)(__int64, struct _KTHREAD **))sub_280051DB4)(-1, &v64);
        if ( v7 >= 0 )
        {
          *(_QWORD *)(*(_QWORD *)(v5 + 48) + 24LL) = 29521;
          CurrentThread = KeGetCurrentThread();
          CurrentProcess = IoGetCurrentProcess();
          ((void (__fastcall *)(PEPROCESS, struct _KTHREAD *, _QWORD))sub_280051F24)(
            CurrentProcess,
            CurrentThread,
            (unsigned int)v64);
        }
        goto LABEL_7;
      case -2147471200:
        memset((void *)(v3 + 8), 0, 0x80u);
        memmove((void *)(v3 + 8), &unk_280075680, 0x80u);
LABEL_10:
        v1->IoStatus.Information = 136;
        v1->IoStatus.Status = 0;
        v7 = 0;
LABEL_127:
        IofCompleteRequest(v1, 0);
        return v7;
      case -2147480364:
        *(_QWORD *)(*(_QWORD *)(v5 + 48) + 24LL) = 29522;
        v10 = IoGetCurrentProcess();
        ExAcquireFastMutex(&stru_280075720);
        v11 = 0;
        v12 = (PEPROCESS *)qword_280074C20;
        do
        {
          if ( *v12 == v10 )
            break;
          ++v11;
          ++v12;
        }
        while ( v11 < 0x20 );
        if ( v11 == 32 )
        {
          v13 = 0;
          v14 = qword_280074C20;
          while ( *v14 != 0 )
          {
            v13 = (unsigned int)(v13 + 1);
            ++v14;
            if ( (unsigned int)v13 >= 0x20 )
              goto LABEL_21;
          }
          qword_280074C20[v13] = v10;
        }
LABEL_21:
        v15 = &stru_280075720;
        goto LABEL_22;
      case -2147480296:
        if ( byte_2800742E8 != 0 )
        {
          byte_2800742E8 = 0;
          sub_28005E7CC(nullptr);
        }
        goto LABEL_116;
      default:
        break;
    }
    if ( v6 != v4 || *(_DWORD *)v3 != 1953524580 )
      goto LABEL_124;
    v16 = *(_DWORD *)(v3 + 4);
    if ( v16 != 0 )
    {
      v17 = v16 - 101;
      if ( v17 == 0 )
      {
        v7 = -1073741811;
        if ( *(_QWORD *)(v3 + 8) == 0 )
        {
LABEL_7:
          v1->IoStatus.Status = v7;
LABEL_126:
          v1->IoStatus.Information = 0;
          goto LABEL_127;
        }
        PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x28u, 0x74706B64u);
        if ( PoolWithTag != nullptr )
        {
          v7 = ObReferenceObjectByHandle(
                 *(HANDLE *)(v3 + 8),
                 0x1F0003u,
                 (POBJECT_TYPE)ExEventObjectType,
                 0,
                 &v62,
                 nullptr);
          if ( v7 < 0 )
          {
            v25 = PoolWithTag;
            goto LABEL_86;
          }
          *((_WORD *)PoolWithTag + 8) = 40;
          *((_WORD *)PoolWithTag + 9) = 0;
          PoolWithTag[3] = v62;
          *((_DWORD *)PoolWithTag + 8) = _InterlockedIncrement(&dword_280074600);
          ExAcquireFastMutex(&stru_280075620);
          v46 = (_QWORD *)qword_280075708;
          PoolWithTag[1] = qword_280075708;
          *PoolWithTag = &qword_280075700;
          *v46 = PoolWithTag;
          qword_280075708 = (__int64)PoolWithTag;
          ExReleaseFastMutex(&stru_280075620);
          *(_QWORD *)(*(_QWORD *)(v5 + 48) + 24LL) = PoolWithTag;
          goto LABEL_88;
        }
LABEL_83:
        v7 = -1073741670;
        goto LABEL_7;
      }
      v18 = v17 - 1;
      if ( v18 == 0 )
      {
        ExAcquireFastMutex(&stru_280075620);
        for ( i = qword_280075700; (__int64 *)i != &qword_280075700; i = *(_QWORD *)i )
          KeSetEvent(*(PRKEVENT *)(i + 24), 0, 0);
        v15 = &stru_280075620;
        goto LABEL_22;
      }
      v19 = v18 - 98;
      if ( v19 == 0 )
      {
        v37 = KeGetCurrentThread();
        v38 = IoGetCurrentProcess();
        if ( (unsigned __int8)((__int64 (__fastcall *)(PEPROCESS, struct _KTHREAD *, _QWORD))sub_2800521C4)(v38, v37, 0) != 0 )
        {
          v39 = ObReferenceObjectByHandle(*(HANDLE *)(v3 + 8), 0x1F0003u, (POBJECT_TYPE)PsThreadType, 0, &v60, nullptr);
          if ( v39 >= 0 )
          {
            ObfDereferenceObject(v60);
            v40 = v60;
            v41 = IoGetCurrentProcess();
            v42 = 0;
            ExAcquireFastMutex(&FastMutex);
            for ( j = qword_280075710; (__int64 *)j != &qword_280075710; j = *(_QWORD *)j )
            {
              if ( *(PEPROCESS *)(j + 16) == v41 )
              {
                *(_QWORD *)(j + 40) = v40;
                *(_DWORD *)(j + 52) = 0;
                v42 = 1;
                break;
              }
            }
            ExReleaseFastMutex(&FastMutex);
            v39 = v42 == 0 ? 0xC0000022 : 0;
          }
          goto LABEL_125;
        }
        goto LABEL_124;
      }
      v20 = v19 - 1;
      if ( v20 != 0 )
      {
        v21 = v20 - 1;
        if ( v21 != 0 )
        {
          v22 = v21 - 98;
          if ( v22 != 0 )
          {
            v23 = v22 - 200;
            if ( v23 == 0 )
            {
              dword_280074EE0 = *(_QWORD *)(v3 + 8) / 1024LL;
              goto LABEL_116;
            }
            if ( v23 == 1 )
            {
              *(_QWORD *)(v3 + 8) = (unsigned __int64)(unsigned int)dword_280074EE0 << 10;
              *(_QWORD *)(v3 + 16) = (unsigned __int64)(unsigned int)dword_280074EE4 << 10;
              goto LABEL_10;
            }
            goto LABEL_124;
          }
          v7 = -1073741811;
          if ( *(_QWORD *)(v3 + 8) == 0 || *(_QWORD *)(v3 + 16) == 0 )
            goto LABEL_7;
          v24 = ExAllocatePoolWithTag(NonPagedPool, 0x28u, 0x74706B64u);
          if ( v24 != nullptr )
          {
            v7 = ObReferenceObjectByHandle(
                   *(HANDLE *)(v3 + 8),
                   0x1F0003u,
                   (POBJECT_TYPE)ExEventObjectType,
                   0,
                   &v59,
                   nullptr);
            if ( v7 < 0 )
            {
LABEL_43:
              v25 = v24;
LABEL_86:
              ExFreePoolWithTag(v25, 0x74706B64u);
              goto LABEL_7;
            }
            v7 = ObReferenceObjectByHandle(
                   *(HANDLE *)(v3 + 16),
                   0x1F0003u,
                   (POBJECT_TYPE)ExEventObjectType,
                   0,
                   &v61,
                   nullptr);
            if ( v7 < 0 )
            {
              ObfDereferenceObject(v59);
              goto LABEL_43;
            }
            *((_WORD *)v24 + 9) = 1;
            *((_WORD *)v24 + 8) = 40;
            v24[3] = v59;
            v24[4] = v61;
            ExAcquireFastMutex(&stru_2800753E0);
            v26 = (_QWORD *)qword_280075398;
            v24[1] = qword_280075398;
            *v24 = &qword_280075390;
            *v26 = v24;
            qword_280075398 = (__int64)v24;
            ExReleaseFastMutex(&stru_2800753E0);
            *(_QWORD *)(*(_QWORD *)(v5 + 48) + 24LL) = v24;
LABEL_88:
            v7 = 0;
            goto LABEL_7;
          }
          goto LABEL_83;
        }
        v27 = KeGetCurrentThread();
        v28 = IoGetCurrentProcess();
        if ( (unsigned __int8)((__int64 (__fastcall *)(PEPROCESS, struct _KTHREAD *, _QWORD))sub_28005214C)(v28, v27, 0) != 0 )
        {
          v29 = KeGetCurrentThread();
          v30 = IoGetCurrentProcess();
          ExAcquireFastMutex(&FastMutex);
          for ( k = qword_280075710; (__int64 *)k != &qword_280075710; k = *(_QWORD *)k )
          {
            if ( *(PEPROCESS *)(k + 16) == v30 )
            {
              if ( *(struct _KTHREAD **)(k + 32) == v29 )
              {
                --*(_DWORD *)(k + 48);
              }
              else if ( *(struct _KTHREAD **)(k + 40) == v29 )
              {
                --*(_DWORD *)(k + 52);
              }
              break;
            }
          }
LABEL_57:
          v15 = &FastMutex;
LABEL_22:
          ExReleaseFastMutex(v15);
LABEL_116:
          v1->IoStatus.Status = 0;
          v7 = 0;
          goto LABEL_126;
        }
      }
      else
      {
        v32 = KeGetCurrentThread();
        v33 = IoGetCurrentProcess();
        if ( (unsigned __int8)((__int64 (__fastcall *)(PEPROCESS, struct _KTHREAD *, _QWORD))sub_28005214C)(v33, v32, 0) != 0 )
        {
          v34 = KeGetCurrentThread();
          v35 = IoGetCurrentProcess();
          ExAcquireFastMutex(&FastMutex);
          for ( m = qword_280075710; (__int64 *)m != &qword_280075710; m = *(_QWORD *)m )
          {
            if ( *(PEPROCESS *)(m + 16) == v35 )
            {
              if ( *(struct _KTHREAD **)(m + 32) == v34 )
              {
                ++*(_DWORD *)(m + 48);
              }
              else if ( *(struct _KTHREAD **)(m + 40) == v34 )
              {
                ++*(_DWORD *)(m + 52);
              }
              goto LABEL_57;
            }
          }
          goto LABEL_57;
        }
      }
    }
    else
    {
      v47 = KeGetCurrentThread();
      v48 = IoGetCurrentProcess();
      if ( (unsigned __int8)((__int64 (__fastcall *)(PEPROCESS, struct _KTHREAD *, __int64))sub_2800521C4)(v48, v47, 2) != 0 )
      {
        sub_28006E964();
        v39 = sub_280065AD0();
LABEL_125:
        v1->IoStatus.Status = v39;
        v7 = v39;
        goto LABEL_126;
      }
    }
LABEL_124:
    v39 = -1073741808;
    goto LABEL_125;
  }
  if ( **(_DWORD **)(v2 + 64) == 7680401 )
  {
    v49 = v65;
    if ( v3 != 0
      && *(_DWORD *)(v5 + 24) == v65
      && *(_DWORD *)(v5 + 16) == 136
      && *(_DWORD *)(v5 + 8) == 136
      && *(_DWORD *)v3 == 1953524580 )
    {
      v50 = *(_DWORD *)(v3 + 4);
      if ( v50 == 400 )
      {
        if ( *(_DWORD *)(v0 + 76) == 2 )
        {
          ((void (__fastcall *)(__int64))sub_28006AE30)(v0 + 56);
          sub_280066DD4(v64);
        }
        goto LABEL_116;
      }
      if ( (unsigned int)(v50 - 1001) <= 1 )
      {
        v51 = sub_2800513D0(*(PDEVICE_OBJECT *)(v0 + 16), v1);
        if ( v51 >= 0 )
        {
          *(_DWORD *)(v0 + 72) = *(_DWORD *)(v3 + 8);
          v52 = *(_DWORD *)(v3 + 12);
          *(_DWORD *)(v0 + 76) = v52;
          if ( v52 == 2 )
          {
            v53 = *(_QWORD *)(v0 + 544);
            if ( v53 != 0 )
            {
              v54 = *(struct _DEVICE_OBJECT **)(v0 + 16);
              Object = nullptr;
              v55 = *(_QWORD *)(*(_QWORD *)(v53 + 24) + 32LL);
              v63[0] = 0;
              v63[1] = v55;
              Irp = IoAllocateIrp(v54->StackSize, 0);
              if ( Irp != nullptr && (int)sub_280066834(v54, (__int64)v63, Irp) >= 0 )
              {
                if ( ExAllocatePoolWithTag(NonPagedPool, 0x88u, 0x74665450u) != nullptr )
                  JUMPOUT(0x2800BBD9BLL);
                ExFreePoolWithTag(Object, 0);
              }
            }
          }
          if ( _bittest((const signed __int32 *)(*(_QWORD *)(v0 + 24) + 48LL), 8u) && *(_DWORD *)(v0 + 76) == 2 )
            ((void (__fastcall *)(_QWORD))sub_28006CAE8)(*(unsigned int *)(v0 + 72));
          ExAcquireFastMutex(&stru_280075620);
          for ( n = qword_280075700; (__int64 *)n != &qword_280075700; n = *(_QWORD *)n )
            KeSetEvent(*(PRKEVENT *)(n + 24), 0, 0);
          ExReleaseFastMutex(&stru_280075620);
        }
        v7 = v51;
        goto LABEL_127;
      }
    }
    if ( *(_DWORD *)(v5 + 24) == -2147472056 )
    {
      v64 = KeGetCurrentThread();
      if ( *(_DWORD *)(v5 + 16) == 136 && *(_DWORD *)(v5 + 8) == 136 )
      {
        if ( *(_BYTE *)(v0 + 552) == 0 && byte_2800742E9 != 0 )
        {
          *(_BYTE *)(v0 + 552) = 1;
          *(_DWORD *)(v5 + 24) = v49;
          JUMPOUT(0x2800BC01ALL);
        }
        *(_BYTE *)(v0 + 552) = 1;
        v7 = 536870913;
        goto LABEL_7;
      }
      goto LABEL_124;
    }
  }
  ++v1->CurrentLocation;
  ++v1->Tail.Overlay.CurrentStackLocation;
  return IofCallDriver(*(PDEVICE_OBJECT *)(v0 + 16), v1);
}


0x280063121  push    rdi
0x280063122  pop     rdi
0x280063123  push    rdx
0x280063124  pop     rdx
0x280063125  push    rdx
0x280063126  pop     rdx
0x280063127  cmp     rdi, cs:DeviceObject
0x28006312e  jnz     loc_280063797
0x280063134  mov     esi, 88h
0x280063139  xor     edi, edi
0x28006313b  cmp     [r14+10h], esi
0x28006313f  jnz     loc_280063C13
0x280063145  cmp     [r14+8], esi
0x280063149  jnz     loc_280063C13
0x28006314f  mov     eax, [r14+18h]
0x280063153  cmp     eax, 8000309Ch
0x280063158  jnz     short loc_2800631AE
0x28006315a  lea     rdx, [rsp+arg_C8]
0x280063162  or      rcx, 0FFFFFFFFFFFFFFFFh
0x280063166  mov     dword ptr [rsp+arg_C8], edi
0x28006316d  call    sub_280051DB4
0x280063172  cmp     eax, edi
0x280063174  mov     esi, eax
0x280063176  jl      short loc_2800631A6
0x280063178  mov     rax, [r14+30h]
0x28006317c  mov     qword ptr [rax+18h], 7351h
0x280063184  mov     rbx, gs:188h
0x28006318d  call    cs:IoGetCurrentProcess; ntoskrnl
0x280063193  mov     r8d, dword ptr [rsp+arg_C8]
0x28006319b  mov     rcx, rax
0x28006319e  mov     rdx, rbx
0x2800631a1  call    sub_280051F24
0x2800631a6  mov     [rbp+30h], esi
0x2800631a9  jmp     loc_280063C1D
0x2800631ae  cmp     eax, 800030A0h
0x2800631b3  jnz     short loc_2800631ED
0x2800631b5  mov     edi, 80h
0x2800631ba  lea     rcx, [r12+8]; Dst
0x2800631bf  xor     edx, edx; Val
0x2800631c1  mov     r8, rdi; Size
0x2800631c4  call    memset
0x2800631c9  lea     rcx, [r12+8]; Dst
0x2800631ce  lea     rdx, unk_280075680; Src
0x2800631d5  mov     r8, rdi; MaxCount
0x2800631d8  call    memmove
0x2800631dd  xor     edi, edi
0x2800631df  mov     [rbp+38h], rsi
0x2800631e3  mov     [rbp+30h], edi
0x2800631e6  mov     esi, edi
0x2800631e8  jmp     loc_280063C21
0x2800631ed  cmp     eax, 80000CD4h
0x2800631f2  jnz     short loc_28006326C
0x2800631f4  mov     rax, [r14+30h]
0x2800631f8  mov     qword ptr [rax+18h], 7352h
0x280063200  call    cs:IoGetCurrentProcess; ntoskrnl
0x280063206  lea     rcx, stru_280075720; FastMutex
0x28006320d  mov     rbx, rax
0x280063210  call    cs:ExAcquireFastMutex; ntoskrnl
0x280063216  lea     r8, qword_280074C20
0x28006321d  mov     ecx, edi
0x28006321f  mov     r13d, 1
0x280063225  mov     rdx, r8
0x280063228  cmp     [rdx], rbx
0x28006322b  jz      short loc_280063239
0x28006322d  add     ecx, r13d
0x280063230  add     rdx, 8
0x280063234  cmp     ecx, 20h ; ' '
0x280063237  jb      short loc_280063228
0x280063239  cmp     ecx, 20h ; ' '
0x28006323c  jnz     short loc_28006325A
0x28006323e  mov     eax, edi
0x280063240  mov     rcx, r8
0x280063243  cmp     [rcx], rdi
0x280063246  jz      short loc_280063256
0x280063248  add     eax, r13d
0x28006324b  add     rcx, 8
0x28006324f  cmp     eax, 20h ; ' '
0x280063252  jb      short loc_280063243
0x280063254  jmp     short loc_28006325A
0x280063256  mov     [r8+rax*8], rbx
0x28006325a  lea     rcx, stru_280075720; FastMutex
0x280063261  call    cs:ExReleaseFastMutex; ntoskrnl
0x280063267  jmp     loc_2800639C1
0x28006326c  cmp     eax, 80000D18h
0x280063271  jnz     short loc_280063293
0x280063273  cmp     cs:byte_2800742E8, dil
0x28006327a  jz      loc_2800639C1
0x280063280  xor     ecx, ecx; P
0x280063282  mov     cs:byte_2800742E8, dil
0x280063289  call    sub_28005E7CC
0x28006328e  jmp     loc_2800639C1
0x280063293  cmp     eax, r13d
0x280063296  jnz     loc_280063C13
0x28006329c  mov     r15d, 74706B64h
0x2800632a2  cmp     [r12], r15d
0x2800632a6  jnz     loc_280063C13
0x2800632ac  mov     eax, [r12+4]
0x2800632b1  cmp     eax, edi
0x2800632b3  jz      loc_28006375F
0x2800632b9  sub     eax, 65h ; 'e'
0x2800632bc  jz      loc_280063672
0x2800632c2  mov     r13d, 1
0x2800632c8  sub     eax, r13d
0x2800632cb  jz      loc_280063632
0x2800632d1  sub     eax, 62h ; 'b'
0x2800632d4  jz      loc_280063567
0x2800632da  sub     eax, r13d
0x2800632dd  jz      loc_2800634E3
0x2800632e3  sub     eax, r13d
0x2800632e6  jz      loc_28006345C
0x2800632ec  sub     eax, 62h ; 'b'
0x2800632ef  jz      short loc_280063343
0x2800632f1  sub     eax, 0C8h
0x2800632f6  jz      short loc_280063324
0x2800632f8  cmp     eax, r13d
0x2800632fb  jnz     loc_280063C13
0x280063301  mov     eax, cs:dword_280074EE0
0x280063307  shl     rax, 0Ah
0x28006330b  mov     [r12+8], rax
0x280063310  mov     eax, cs:dword_280074EE4
0x280063316  shl     rax, 0Ah
0x28006331a  mov     [r12+10h], rax
0x28006331f  jmp     loc_2800631DF
0x280063324  mov     rax, [r12+8]
0x280063329  cqo
0x28006332b  and     edx, 3FFh
0x280063331  add     rax, rdx
0x280063334  sar     rax, 0Ah
0x280063338  mov     cs:dword_280074EE0, eax
0x28006333e  jmp     loc_2800639C1
0x280063343  mov     esi, 0C000000Dh
0x280063348  cmp     [r12+8], rdi
0x28006334d  jz      loc_2800631A6
0x280063353  cmp     [r12+10h], rdi
0x280063358  jz      loc_2800631A6
0x28006335e  mov     r8d, r15d; Tag
0x280063361  mov     edx, 28h ; '('; NumberOfBytes
0x280063366  xor     ecx, ecx; PoolType
0x280063368  call    cs:ExAllocatePoolWithTag; ntoskrnl
0x28006336e  mov     rbx, rax
0x280063371  cmp     rax, rdi
0x280063374  jz      loc_28006369D
0x28006337a  mov     r8, cs:ExEventObjectType; ntoskrnl
0x280063381  mov     rcx, [r12+8]; Handle
0x280063386  lea     rax, [rsp+arg_40]
0x28006338b  mov     r8, [r8]; ObjectType
0x28006338e  xor     r9d, r9d; AccessMode
0x280063391  mov     edx, 1F0003h; DesiredAccess
0x280063396  mov     [rsp+HandleInformation], rdi; HandleInformation
0x28006339b  mov     [rsp+Object], rax; Object
0x2800633a0  call    cs:ObReferenceObjectByHandle; ntoskrnl
0x2800633a6  cmp     eax, edi
0x2800633a8  mov     esi, eax
0x2800633aa  jge     short loc_2800633B7
0x2800633ac  mov     edx, r15d
0x2800633af  mov     rcx, rbx
0x2800633b2  jmp     loc_2800636E1
0x2800633b7  mov     r8, cs:ExEventObjectType; ntoskrnl
0x2800633be  mov     rcx, [r12+10h]; Handle
0x2800633c3  lea     rax, [rsp+arg_58]
0x2800633c8  mov     r8, [r8]; ObjectType
0x2800633cb  xor     r9d, r9d; AccessMode
0x2800633ce  mov     edx, 1F0003h; DesiredAccess
0x2800633d3  mov     [rsp+HandleInformation], rdi; HandleInformation
0x2800633d8  mov     [rsp+Object], rax; Object
0x2800633dd  call    cs:ObReferenceObjectByHandle; ntoskrnl
0x2800633e3  cmp     eax, edi
0x2800633e5  mov     esi, eax
0x2800633e7  jge     short loc_2800633F6
0x2800633e9  mov     rcx, [rsp+arg_40]; Object
0x2800633ee  call    cs:ObfDereferenceObject; ntoskrnl
0x2800633f4  jmp     short loc_2800633AC
0x2800633f6  mov     [rbx+12h], r13w
0x2800633fb  mov     eax, 28h ; '('
0x280063400  lea     rcx, stru_2800753E0; FastMutex
0x280063407  mov     [rbx+10h], ax
0x28006340b  mov     rax, [rsp+arg_40]
0x280063410  mov     [rbx+18h], rax
0x280063414  mov     rax, [rsp+arg_58]
0x280063419  mov     [rbx+20h], rax
0x28006341d  call    cs:ExAcquireFastMutex; ntoskrnl
0x280063423  mov     r11, cs:qword_280075398
0x28006342a  mov     [rbx+8], r11
0x28006342e  lea     rax, qword_280075390
0x280063435  lea     rcx, stru_2800753E0; FastMutex
0x28006343c  mov     [rbx], rax
0x28006343f  mov     [r11], rbx
0x280063442  mov     cs:qword_280075398, rbx
0x280063449  call    cs:ExReleaseFastMutex; ntoskrnl
0x28006344f  mov     r11, [r14+30h]
0x280063453  mov     [r11+18h], rbx
0x280063457  jmp     loc_280063758
0x28006345c  mov     rbx, gs:188h
0x280063465  call    cs:IoGetCurrentProcess; ntoskrnl
0x28006346b  xor     r8d, r8d
0x28006346e  mov     rcx, rax
0x280063471  mov     rdx, rbx
0x280063474  call    sub_28005214C
0x280063479  cmp     al, dil
0x28006347c  jz      loc_280063C13
0x280063482  mov     rbx, gs:188h
0x28006348b  call    cs:IoGetCurrentProcess; ntoskrnl
0x280063491  lea     rcx, FastMutex; FastMutex
0x280063498  mov     rsi, rax
0x28006349b  call    cs:ExAcquireFastMutex; ntoskrnl
0x2800634a1  mov     r11, cs:qword_280075710
0x2800634a8  lea     rcx, qword_280075710
0x2800634af  jmp     short loc_2800634BA
0x2800634b1  cmp     [r11+10h], rsi
0x2800634b5  jz      short loc_2800634C1
0x2800634b7  mov     r11, [r11]
0x2800634ba  cmp     r11, rcx
0x2800634bd  jnz     short loc_2800634B1
0x2800634bf  jmp     short loc_2800634D7
0x2800634c1  cmp     [r11+20h], rbx
0x2800634c5  jnz     short loc_2800634CD
0x2800634c7  dec     dword ptr [r11+30h]
0x2800634cb  jmp     short loc_2800634D7
0x2800634cd  cmp     [r11+28h], rbx
0x2800634d1  jnz     short loc_2800634D7
0x2800634d3  dec     dword ptr [r11+34h]
0x2800634d7  lea     rcx, FastMutex
0x2800634de  jmp     loc_280063261
0x2800634e3  mov     rbx, gs:188h
0x2800634ec  call    cs:IoGetCurrentProcess; ntoskrnl
0x2800634f2  xor     r8d, r8d
0x2800634f5  mov     rcx, rax
0x2800634f8  mov     rdx, rbx
0x2800634fb  call    sub_28005214C
0x280063500  cmp     al, dil
0x280063503  jz      loc_280063C13
0x280063509  mov     rbx, gs:188h
0x280063512  call    cs:IoGetCurrentProcess; ntoskrnl
0x280063518  lea     rcx, FastMutex; FastMutex
0x28006351f  mov     rsi, rax
0x280063522  call    cs:ExAcquireFastMutex; ntoskrnl
0x280063528  mov     r11, cs:qword_280075710
0x28006352f  lea     rcx, qword_280075710
0x280063536  jmp     short loc_280063541
0x280063538  cmp     [r11+10h], rsi
0x28006353c  jz      short loc_280063548
0x28006353e  mov     r11, [r11]
0x280063541  cmp     r11, rcx
0x280063544  jnz     short loc_280063538
0x280063546  jmp     short loc_2800634D7
0x280063548  cmp     [r11+20h], rbx
0x28006354c  jnz     short loc_280063554
0x28006354e  add     [r11+30h], r13d
0x280063552  jmp     short loc_2800634D7
0x280063554  cmp     [r11+28h], rbx
0x280063558  jnz     loc_2800634D7
0x28006355e  add     [r11+34h], r13d
0x280063562  jmp     loc_2800634D7
0x280063567  mov     rbx, gs:188h
0x280063570  call    cs:IoGetCurrentProcess; ntoskrnl
0x280063576  xor     r8d, r8d
0x280063579  mov     rcx, rax
0x28006357c  mov     rdx, rbx
0x28006357f  call    sub_2800521C4
0x280063584  cmp     al, dil
0x280063587  jz      loc_280063C13
0x28006358d  mov     r8, cs:PsThreadType; ntoskrnl
0x280063594  mov     rcx, [r12+8]; Handle
0x280063599  lea     rax, [rsp+arg_48]
0x28006359e  mov     r8, [r8]; ObjectType
0x2800635a1  xor     r9d, r9d; AccessMode
0x2800635a4  mov     edx, 1F0003h; DesiredAccess
0x2800635a9  mov     [rsp+HandleInformation], rdi; HandleInformation
0x2800635ae  mov     [rsp+Object], rax; Object
0x2800635b3  call    cs:ObReferenceObjectByHandle; ntoskrnl
0x2800635b9  cmp     eax, edi
0x2800635bb  jl      loc_280063C18
0x2800635c1  mov     rcx, [rsp+arg_48]; Object
0x2800635c6  call    cs:ObfDereferenceObject; ntoskrnl
0x2800635cc  mov     rsi, [rsp+arg_48]
0x2800635d1  call    cs:IoGetCurrentProcess; ntoskrnl
0x2800635d7  lea     rcx, FastMutex; FastMutex
0x2800635de  mov     r12, rax
0x2800635e1  mov     bl, dil
0x2800635e4  call    cs:ExAcquireFastMutex; ntoskrnl
0x2800635ea  mov     r11, cs:qword_280075710
0x2800635f1  lea     rcx, qword_280075710
0x2800635f8  jmp     short loc_280063603
0x2800635fa  cmp     [r11+10h], r12
0x2800635fe  jz      short loc_28006360A
0x280063600  mov     r11, [r11]
0x280063603  cmp     r11, rcx
0x280063606  jnz     short loc_2800635FA
0x280063608  jmp     short loc_280063615
0x28006360a  mov     [r11+28h], rsi
0x28006360e  mov     [r11+34h], edi
0x280063612  mov     bl, r13b
0x280063615  lea     rcx, FastMutex; FastMutex
0x28006361c  call    cs:ExReleaseFastMutex; ntoskrnl
0x280063622  neg     bl
0x280063624  sbb     eax, eax
0x280063626  not     eax
0x280063628  and     eax, 0C0000022h
0x28006362d  jmp     loc_280063C18
0x280063632  lea     rcx, stru_280075620; FastMutex
0x280063639  call    cs:ExAcquireFastMutex; ntoskrnl
0x28006363f  mov     rsi, cs:qword_280075700
0x280063646  lea     rbx, qword_280075700
0x28006364d  jmp     short loc_280063661
0x28006364f  mov     rcx, [rsi+18h]; Event
0x280063653  xor     r8d, r8d; Wait
0x280063656  xor     edx, edx; Increment
0x280063658  call    cs:KeSetEvent; ntoskrnl
0x28006365e  mov     rsi, [rsi]
0x280063661  cmp     rsi, rbx
0x280063664  jnz     short loc_28006364F
0x280063666  lea     rcx, stru_280075620
0x28006366d  jmp     loc_280063261
0x280063672  mov     esi, 0C000000Dh
0x280063677  cmp     [r12+8], rdi
0x28006367c  jz      loc_2800631A6
0x280063682  mov     ebx, 28h ; '('
0x280063687  mov     r8d, r15d; Tag
0x28006368a  xor     ecx, ecx; PoolType
0x28006368c  mov     rdx, rbx; NumberOfBytes
0x28006368f  call    cs:ExAllocatePoolWithTag; ntoskrnl
0x280063695  mov     r15, rax
0x280063698  cmp     rax, rdi
0x28006369b  jnz     short loc_2800636A7
0x28006369d  mov     esi, 0C000009Ah
0x2800636a2  jmp     loc_2800631A6
0x2800636a7  mov     r8, cs:ExEventObjectType; ntoskrnl
0x2800636ae  mov     rcx, [r12+8]; Handle
0x2800636b3  lea     rax, [rsp+arg_60]
0x2800636b8  mov     r8, [r8]; ObjectType
0x2800636bb  xor     r9d, r9d; AccessMode
0x2800636be  mov     edx, 1F0003h; DesiredAccess
0x2800636c3  mov     [rsp+HandleInformation], rdi; HandleInformation
0x2800636c8  mov     [rsp+Object], rax; Object
0x2800636cd  call    cs:ObReferenceObjectByHandle; ntoskrnl
0x2800636d3  cmp     eax, edi
0x2800636d5  mov     esi, eax
0x2800636d7  jge     short loc_2800636EC
0x2800636d9  mov     edx, 74706B64h; Tag
0x2800636de  mov     rcx, r15; P
0x2800636e1  call    cs:ExFreePoolWithTag; ntoskrnl
0x2800636e7  jmp     loc_2800631A6
0x2800636ec  mov     [r15+10h], bx
0x2800636f1  mov     [r15+12h], di
0x2800636f6  mov     rax, [rsp+arg_60]
0x2800636fb  mov     r13d, 1
0x280063701  mov     [r15+18h], rax
0x280063705  mov     eax, r13d
0x280063708  lock xadd cs:dword_280074600, eax
0x280063710  add     eax, r13d
0x280063713  lea     rcx, stru_280075620; FastMutex
0x28006371a  mov     [r15+20h], eax
0x28006371e  call    cs:ExAcquireFastMutex; ntoskrnl
0x280063724  mov     r11, cs:qword_280075708
0x28006372b  mov     [r15+8], r11
0x28006372f  lea     rbx, qword_280075700
0x280063736  lea     rcx, stru_280075620; FastMutex
0x28006373d  mov     [r15], rbx
0x280063740  mov     [r11], r15
0x280063743  mov     cs:qword_280075708, r15
0x28006374a  call    cs:ExReleaseFastMutex; ntoskrnl
0x280063750  mov     r11, [r14+30h]
0x280063754  mov     [r11+18h], r15
0x280063758  mov     esi, edi
0x28006375a  jmp     loc_2800631A6
0x28006375f  mov     rbx, gs:188h
0x280063768  call    cs:IoGetCurrentProcess; ntoskrnl
0x28006376e  mov     r8d, 2
0x280063774  mov     rcx, rax
0x280063777  mov     rdx, rbx
0x28006377a  call    sub_2800521C4
0x28006377f  cmp     al, dil
0x280063782  jz      loc_280063C13
0x280063788  call    sub_28006E964
0x28006378d  call    sub_280065AD0
0x280063792  jmp     loc_280063C18
0x280063797  mov     rax, [rdi+40h]
0x28006379b  mov     r13d, 1
0x2800637a1  cmp     dword ptr [rax], 753191h
0x2800637a7  jnz     loc_280063C30
0x2800637ad  mov     ecx, [rsp+arg_D0]
0x2800637b4  xor     edi, edi
0x2800637b6  mov     esi, 88h
0x2800637bb  mov     r15d, 74706B64h
0x2800637c1  cmp     r12, rdi
0x2800637c4  jz      loc_2800639CB
0x2800637ca  cmp     [r14+18h], ecx
0x2800637ce  jnz     loc_2800639CB
0x2800637d4  cmp     [r14+10h], esi
0x2800637d8  jnz     loc_2800639CB
0x2800637de  cmp     [r14+8], esi
0x2800637e2  jnz     loc_2800639CB
0x2800637e8  cmp     [r12], r15d
0x2800637ec  jnz     loc_2800639CB
0x2800637f2  mov     eax, [r12+4]
0x2800637f7  cmp     eax, 190h
0x2800637fc  jz      loc_2800639A5
0x280063802  add     eax, 0FFFFFC17h
0x280063807  cmp     eax, r13d
0x28006380a  ja      loc_2800639CB
0x280063810  mov     rcx, [rbx+10h]; DeviceObject
0x280063814  mov     rdx, rbp; Irp
0x280063817  call    sub_2800513D0
0x28006381c  cmp     eax, edi
0x28006381e  mov     r13d, eax
0x280063821  jl      loc_28006399D
0x280063827  mov     ecx, [r12+8]
0x28006382c  mov     [rbx+48h], ecx
0x28006382f  mov     ecx, [r12+0Ch]
0x280063834  mov     [rbx+4Ch], ecx
0x280063837  cmp     ecx, 2
0x28006383a  jnz     loc_280063943
0x280063840  mov     r12, [rbx+220h]
0x280063847  cmp     r12, rdi
0x28006384a  jz      loc_280063943
0x280063850  mov     r14, [rbx+10h]
0x280063854  mov     [rsp+P], rdi
0x28006385c  mov     rax, [r12+18h]
0x280063861  mov     rcx, [rax+20h]
0x280063865  xor     edx, edx; ChargeQuota
0x280063867  mov     [rsp+arg_68], rdi
0x28006386c  mov     [rsp+arg_70], rcx
0x280063871  mov     cl, [r14+4Ch]; StackSize
0x280063875  call    cs:IoAllocateIrp; ntoskrnl
0x28006387b  cmp     rax, rdi
0x28006387e  jz      loc_280063943
0x280063884  mov     [rsp+HandleInformation], rax; Irp
0x280063889  lea     rax, [rsp+arg_68]
0x28006388e  lea     r9, [rsp+P]
0x280063896  lea     r8, [rsp+arg_70]
0x28006389b  mov     rdx, r12
0x28006389e  mov     rcx, r14; DeviceObject
0x2800638a1  mov     [rsp+Object], rax; __int64
0x2800638a6  call    sub_280066834
0x2800638ab  cmp     eax, edi
0x2800638ad  jl      loc_280063943
0x2800638b3  mov     r12d, 74665450h
0x2800638b9  mov     rdx, rsi; NumberOfBytes
0x2800638bc  xor     ecx, ecx; PoolType
0x2800638be  mov     r8d, r12d; Tag
0x2800638c1  call    cs:ExAllocatePoolWithTag; ntoskrnl
0x2800638c7  mov     r14, rax
0x2800638ca  cmp     rax, rdi
0x2800638cd  jz      short loc_280063933
0x2800638cf  jmp     near ptr qword_2800BBB38+263h
0x280063933  mov     rcx, [rsp+P]; P
0x28006393b  xor     edx, edx; Tag
0x28006393d  call    cs:ExFreePoolWithTag; ntoskrnl
0x280063943  mov     rax, [rbx+18h]
0x280063947  bt      dword ptr [rax+30h], 8
0x28006394c  jnb     short loc_28006395C
0x28006394e  cmp     dword ptr [rbx+4Ch], 2
0x280063952  jnz     short loc_28006395C
0x280063954  mov     ecx, [rbx+48h]
0x280063957  call    sub_28006CAE8
0x28006395c  lea     rcx, stru_280075620; FastMutex
0x280063963  call    cs:ExAcquireFastMutex; ntoskrnl
0x280063969  mov     rdi, cs:qword_280075700
0x280063970  lea     rbx, qword_280075700
0x280063977  jmp     short loc_28006398B
0x280063979  mov     rcx, [rdi+18h]; Event
0x28006397d  xor     r8d, r8d; Wait
0x280063980  xor     edx, edx; Increment
0x280063982  call    cs:KeSetEvent; ntoskrnl
0x280063988  mov     rdi, [rdi]
0x28006398b  cmp     rdi, rbx
0x28006398e  jnz     short loc_280063979
0x280063990  lea     rcx, stru_280075620; FastMutex
0x280063997  call    cs:ExReleaseFastMutex; ntoskrnl
0x28006399d  mov     esi, r13d
0x2800639a0  jmp     loc_280063C21
0x2800639a5  cmp     dword ptr [rbx+4Ch], 2
0x2800639a9  jnz     short loc_2800639C1
0x2800639ab  lea     rcx, [rbx+38h]
0x2800639af  call    sub_28006AE30
0x2800639b4  mov     rcx, [rsp+arg_C8]; Object
0x2800639bc  call    sub_280066DD4
0x2800639c1  mov     [rbp+30h], edi
0x2800639c4  mov     esi, edi
0x2800639c6  jmp     loc_280063C1D
0x2800639cb  cmp     dword ptr [r14+18h], 80002D48h
0x2800639d3  jnz     loc_280063C30
0x2800639d9  mov     rax, gs:188h
0x2800639e2  mov     [rsp+arg_C8], rax
0x2800639ea  cmp     [r14+10h], esi
0x2800639ee  jnz     loc_280063C13
0x2800639f4  cmp     [r14+8], esi
0x2800639f8  jnz     loc_280063C13
0x2800639fe  cmp     [rbx+228h], dil
0x280063a05  jnz     loc_280063C02
0x280063a0b  cmp     cs:byte_2800742E9, dil
0x280063a12  jz      loc_280063C02
0x280063a18  mov     [rbx+228h], r13b
0x280063a1f  mov     [r14+18h], ecx
0x280063a23  jmp     near ptr qword_2800BBB38+4E2h
0x280063c02  mov     [rbx+228h], r13b
0x280063c09  mov     esi, 20000001h
0x280063c0e  jmp     loc_2800631A6
0x280063c13  mov     eax, 0C0000010h
0x280063c18  mov     [rbp+30h], eax
0x280063c1b  mov     esi, eax
0x280063c1d  mov     [rbp+38h], rdi
0x280063c21  xor     edx, edx; PriorityBoost
0x280063c23  mov     rcx, rbp; Irp
0x280063c26  call    cs:IofCompleteRequest; ntoskrnl
0x280063c2c  mov     eax, esi
0x280063c2e  jmp     short loc_280063C49
0x280063c30  add     [rbp+43h], r13b
0x280063c34  add     qword ptr [rbp+0B8h], 48h ; 'H'
0x280063c3c  mov     rcx, [rbx+10h]; DeviceObject
0x280063c40  mov     rdx, rbp; Irp
0x280063c43  call    cs:IofCallDriver; ntoskrnl
0x280063c49  add     rsp, 88h
0x280063c50  pop     r15
0x280063c52  pop     r14
0x280063c54  pop     r13
0x280063c56  pop     r12
0x280063c58  pop     rdi
0x280063c59  pop     rsi
0x280063c5a  pop     rbp
0x280063c5b  pop     rbx
0x280063c5c  retn
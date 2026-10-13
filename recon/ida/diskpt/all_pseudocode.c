// ===== sub_280051014 @ 0x280051014 size=0x5c =====
__int64 __fastcall sub_280051014(struct _DEVICE_OBJECT *a1)
{
  _DWORD *DeviceExtension; // rax

  if ( a1 == DeviceObject )
    return sub_28005F5CC();
  DeviceExtension = a1->DeviceExtension;
  if ( *DeviceExtension == 7680401 )
    return sub_28005F5CC();
  if ( *DeviceExtension == 7680405 )
    return sub_2800B7DE9();
  return sub_2800528E0();
}


// ===== sub_280051078 @ 0x280051078 size=0x350 =====
NTSTATUS __fastcall sub_280051078(struct _UNICODE_STRING *a1)
{
  NTSTATUS result; // eax
  NTSTATUS v2; // ebx
  size_t v3; // rbx
  ULONG ResultLength; // [rsp+30h] [rbp-278h] BYREF
  void *KeyHandle; // [rsp+38h] [rbp-270h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-268h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+50h] [rbp-258h] BYREF
  _BYTE KeyValueInformation[12]; // [rsp+80h] [rbp-228h] BYREF
  _BYTE Src[516]; // [rsp+8Ch] [rbp-21Ch] BYREF

  ObjectAttributes.ObjectName = a1;
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 64;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  result = ZwOpenKey(&KeyHandle, 0x20019u, &ObjectAttributes);
  if ( result >= 0 )
  {
    RtlInitUnicodeString(&DestinationString, L"GUID");
    v2 = ZwQueryValueKey(
           KeyHandle,
           &DestinationString,
           KeyValuePartialInformation,
           KeyValueInformation,
           0x210u,
           &ResultLength);
    if ( v2 < 0 )
    {
      ZwClose(KeyHandle);
      return v2;
    }
    else
    {
      v3 = 128;
      memset(&unk_280075680, 0, 0x80u);
      if ( ResultLength <= 0x80 )
        v3 = ResultLength;
      memmove(&unk_280075680, Src, v3);
      return sub_2800B7DE9();
    }
  }
  return result;
}


// ===== sub_2800513D0 @ 0x2800513d0 size=0xa0 =====
NTSTATUS __fastcall sub_2800513D0(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rdx
  struct _IO_STACK_LOCATION *v5; // rbx
  struct _IO_STACK_LOCATION *v6; // rax
  NTSTATUS result; // eax
  struct _KEVENT Event; // [rsp+30h] [rbp-28h] BYREF

  KeInitializeEvent(&Event, NotificationEvent, 0);
  CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
  v5 = CurrentStackLocation - 1;
  memmove(&CurrentStackLocation[-1], CurrentStackLocation, 0x38u);
  v5->Control = 0;
  v6 = Irp->Tail.Overlay.CurrentStackLocation;
  v6[-1].Control = -32;
  v6[-1].CompletionRoutine = (PIO_COMPLETION_ROUTINE)&sub_280051478;
  v6[-1].Context = &Event;
  result = IofCallDriver(DeviceObject, Irp);
  if ( result == 259 )
  {
    KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
    return Irp->IoStatus.Status;
  }
  return result;
}


// ===== sub_280051478 @ 0x280051478 size=0x25 =====
__int64 __fastcall sub_280051478(__int64 a1, __int64 a2, struct _KEVENT *a3)
{
  if ( *(_BYTE *)(a2 + 65) == 1 )
    KeSetEvent(a3, 0, 0);
  return 3221225494LL;
}


// ===== sub_2800514A4 @ 0x2800514a4 size=0xb2 =====
NTSTATUS __fastcall sub_2800514A4(
        PDEVICE_OBJECT DeviceObject,
        ULONG IoControlCode,
        void *a3,
        ULONG a4,
        void *a5,
        ULONG OutputBufferLength)
{
  IRP *v7; // rdi
  NTSTATUS result; // eax
  struct _IO_STATUS_BLOCK v9; // [rsp+50h] [rbp-38h] BYREF
  struct _KEVENT Event; // [rsp+60h] [rbp-28h] BYREF

  v7 = IoBuildDeviceIoControlRequest(IoControlCode, DeviceObject, a3, a4, a5, OutputBufferLength, 0, &Event, &v9);
  if ( v7 == nullptr )
    return -1073741670;
  v9.Status = 0;
  KeInitializeEvent(&Event, NotificationEvent, 0);
  result = IofCallDriver(DeviceObject, v7);
  if ( result == 259 )
  {
    KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
    return v9.Status;
  }
  return result;
}


// ===== sub_28005155C @ 0x28005155c size=0x10a =====
NTSTATUS __fastcall sub_28005155C(
        PDEVICE_OBJECT DeviceObject,
        unsigned __int8 a2,
        void *a3,
        ULONG a4,
        union _LARGE_INTEGER Timeout)
{
  ULONG v5; // r13d
  unsigned int v9; // ebx
  PIRP i; // rax
  unsigned int v11; // eax
  IRP *v12; // rdi
  struct _IO_STACK_LOCATION *CurrentStackLocation; // r11
  NTSTATUS result; // eax
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+30h] [rbp-48h] BYREF
  struct _KEVENT Event; // [rsp+40h] [rbp-38h] BYREF

  v5 = a2;
  v9 = 0;
  for ( i = IoBuildAsynchronousFsdRequest(a2, DeviceObject, a3, a4, &Timeout, &IoStatusBlock);
        ;
        i = IoBuildAsynchronousFsdRequest(v5, DeviceObject, a3, a4, &Timeout, &IoStatusBlock) )
  {
    v12 = i;
    if ( i != nullptr )
      break;
    v11 = v9++;
    if ( v11 >= 0xA )
      return -1073741670;
    KeDelayExecutionThread(0, 0, &Interval);
  }
  i->Flags = i->Flags;
  KeInitializeEvent(&Event, NotificationEvent, 0);
  CurrentStackLocation = v12->Tail.Overlay.CurrentStackLocation;
  CurrentStackLocation[-1].CompletionRoutine = (PIO_COMPLETION_ROUTINE)&sub_28005166C;
  CurrentStackLocation[-1].Control = -32;
  CurrentStackLocation[-1].Context = &Event;
  result = IofCallDriver(DeviceObject, v12);
  if ( result == 259 )
  {
    KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
    return IoStatusBlock.Status;
  }
  return result;
}


// ===== sub_28005166C @ 0x28005166c size=0x98 =====
__int64 __fastcall sub_28005166C(__int64 a1, __int64 a2, struct _KEVENT *a3)
{
  void *v3; // rcx
  struct _MDL *v6; // rbx

  v3 = *(void **)(a2 + 24);
  if ( v3 != nullptr && (*(_BYTE *)(a2 + 16) & 0x20) != 0 )
    ExFreePoolWithTag(v3, 0);
  while ( *(_QWORD *)(a2 + 8) != 0 )
  {
    v6 = *(struct _MDL **)(a2 + 8);
    *(_QWORD *)(a2 + 8) = v6->Next;
    MmUnlockPages(v6);
    IoFreeMdl(v6);
  }
  if ( *(_BYTE *)(a2 + 65) != 0 && a3 != nullptr )
  {
    *(__m128i *)*(_QWORD *)(a2 + 72) = _mm_loadu_si128((const __m128i *)(a2 + 48));
    KeSetEvent(a3, 1, 0);
  }
  IoFreeIrp((PIRP)a2);
  return 3221225494LL;
}


// ===== HandleInformation @ 0x28005170c size=0x8e =====
void __fastcall __noreturn HandleInformation(char *StartContext)
{
  PLIST_ENTRY v2; // rax

  if ( StartContext[33] != 0 )
    sub_280052014(KeGetCurrentThread());
  KeSetPriorityThread(KeGetCurrentThread(), *((_DWORD *)StartContext + 9));
  while ( 1 )
  {
    KeWaitForSingleObject(StartContext + 8, Executive, 0, 0, nullptr);
    while ( 1 )
    {
      v2 = ExInterlockedRemoveHeadList((PLIST_ENTRY)StartContext + 3, (PKSPIN_LOCK)StartContext + 8);
      if ( v2 == nullptr )
        break;
      ((void (__fastcall *)(struct _LIST_ENTRY *))v2[1].Flink)(v2[1].Blink);
    }
    if ( StartContext[32] != 0 )
    {
      sub_2800520DC(KeGetCurrentThread());
      PsTerminateSystemThread(0);
    }
  }
}


// ===== sub_2800517A0 @ 0x2800517a0 size=0x12e =====
__int64 __fastcall sub_2800517A0(_QWORD *a1, __int64 a2, char a3)
{
  char *PoolWithTag; // rax
  char *StartContext; // rbx
  _QWORD *v8; // rax
  NTSTATUS v9; // edi
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+40h] [rbp-38h] BYREF
  void *ThreadHandle; // [rsp+98h] [rbp+20h] BYREF

  PoolWithTag = (char *)ExAllocatePoolWithTag(NonPagedPool, 0x48u, 0x74706B64u);
  StartContext = PoolWithTag;
  if ( PoolWithTag == nullptr )
    return 3221225626LL;
  v8 = PoolWithTag + 48;
  v8[1] = v8;
  *v8 = v8;
  *((_QWORD *)StartContext + 8) = 0;
  KeInitializeEvent((PRKEVENT)(StartContext + 8), SynchronizationEvent, 0);
  *((_DWORD *)StartContext + 9) = 21;
  StartContext[32] = 0;
  StartContext[33] = a3;
  memset(&ObjectAttributes.RootDirectory, 0, 20);
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.Length = 48;
  v9 = PsCreateSystemThread(
         &ThreadHandle,
         0x1FFFFFu,
         &ObjectAttributes,
         nullptr,
         nullptr,
         (PKSTART_ROUTINE)HandleInformation,
         StartContext);
  if ( v9 >= 0 )
  {
    v9 = ObReferenceObjectByHandle(ThreadHandle, 0x1FFFFFu, nullptr, 0, (PVOID *)StartContext, nullptr);
    if ( v9 >= 0 )
    {
      ZwClose(ThreadHandle);
      *a1 = StartContext;
      return (unsigned int)v9;
    }
    ZwClose(ThreadHandle);
  }
  ExFreePoolWithTag(StartContext, 0x74706B64u);
  return (unsigned int)v9;
}


// ===== sub_2800518D4 @ 0x2800518d4 size=0x52 =====
void __fastcall sub_2800518D4(__int64 a1)
{
  *(_BYTE *)(a1 + 32) = 1;
  KeSetEvent((PRKEVENT)(a1 + 8), 1, 0);
  KeWaitForSingleObject(*(PVOID *)a1, Executive, 0, 0, nullptr);
  ObfDereferenceObject(*(PVOID *)a1);
  ExFreePoolWithTag((PVOID)a1, 0x74706B64u);
}


// ===== sub_28005192C @ 0x28005192c size=0x2e =====
LONG __fastcall sub_28005192C(__int64 a1, struct _LIST_ENTRY *a2)
{
  ExInterlockedInsertTailList((PLIST_ENTRY)(a1 + 48), a2, (PKSPIN_LOCK)(a1 + 64));
  return KeSetEvent((PRKEVENT)(a1 + 8), 1, 0);
}


// ===== sub_280051960 @ 0x280051960 size=0x44b =====
NTSTATUS __fastcall sub_280051960(struct _UNICODE_STRING *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  NTSTATUS result; // eax
  NTSTATUS v6; // ebx
  unsigned int v7; // r13d
  unsigned int v8; // esi
  union _LARGE_INTEGER ByteOffset; // [rsp+68h] [rbp-2C0h] BYREF
  void *FileHandle; // [rsp+70h] [rbp-2B8h] BYREF
  HANDLE v11; // [rsp+78h] [rbp-2B0h]
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+80h] [rbp-2A8h] BYREF
  char *v13; // [rsp+90h] [rbp-298h]
  _BYTE FileInformation[8]; // [rsp+98h] [rbp-290h] BYREF
  unsigned __int64 v15; // [rsp+A0h] [rbp-288h]
  struct _OBJECT_ATTRIBUTES v16; // [rsp+B0h] [rbp-278h] BYREF
  char Buffer[6]; // [rsp+E0h] [rbp-248h] BYREF
  unsigned __int16 v18; // [rsp+E6h] [rbp-242h]
  unsigned int v19; // [rsp+F0h] [rbp-238h]
  unsigned int v20; // [rsp+F4h] [rbp-234h]
  int v21; // [rsp+11Ch] [rbp-20Ch]
  char v22; // [rsp+13Ch] [rbp-1ECh]

  *a2 = 0;
  *a3 = 0;
  *a4 = 0;
  v16.Length = 48;
  v16.RootDirectory = nullptr;
  v16.Attributes = 576;
  v16.ObjectName = a1;
  v16.SecurityDescriptor = nullptr;
  v16.SecurityQualityOfService = nullptr;
  result = ZwCreateFile(&FileHandle, 0x100001u, &v16, &IoStatusBlock, nullptr, 0x80u, 1u, 3u, 0x60u, nullptr, 0);
  if ( result >= 0 )
  {
    v6 = ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x18u, FileStandardInformation);
    if ( v6 < 0 )
      goto LABEL_20;
    *a4 = v15;
    ByteOffset.QuadPart = 0;
    v6 = ZwReadFile(FileHandle, nullptr, nullptr, nullptr, &IoStatusBlock, Buffer, 0x200u, &ByteOffset, nullptr);
    if ( v6 < 0 )
      goto LABEL_20;
    if ( *(_WORD *)Buffer != 23117 )
    {
      v6 = -1073741811;
LABEL_20:
      ZwClose(FileHandle);
      return v6;
    }
    ByteOffset.QuadPart = v21;
    v6 = ZwReadFile(FileHandle, nullptr, nullptr, nullptr, &IoStatusBlock, Buffer, 0x200u, &ByteOffset, nullptr);
    if ( v6 < 0 )
      goto LABEL_20;
    if ( *(_DWORD *)Buffer != 17744 )
    {
      v6 = -1073741811;
      goto LABEL_20;
    }
    if ( (v22 & 2) == 0 )
    {
      v6 = -1073741811;
      goto LABEL_20;
    }
    v7 = v18;
    ByteOffset.QuadPart += (unsigned __int16)v20 + 24;
    v6 = ZwReadFile(FileHandle, nullptr, nullptr, nullptr, &IoStatusBlock, Buffer, 0x200u, &ByteOffset, nullptr);
    if ( v6 < 0 )
      goto LABEL_20;
    v13 = Buffer;
    v8 = 0;
    LODWORD(v11) = 0;
    while ( v8 < v7 )
    {
      if ( stricmp(Buffer, ".text") == 0 )
      {
        ByteOffset.QuadPart = v20;
        v15 = v20 + (unsigned __int64)v19;
      }
      else
      {
        ByteOffset.QuadPart += 40LL;
        v6 = ZwReadFile(FileHandle, nullptr, nullptr, nullptr, &IoStatusBlock, Buffer, 0x200u, &ByteOffset, nullptr);
        if ( v6 < 0 )
          goto LABEL_20;
        v13 = Buffer;
      }
      LODWORD(v11) = ++v8;
    }
    v11 = (HANDLE)0x100000001LL;
    return sub_2800B7DE9();
  }
  return result;
}


// ===== sub_280051DB4 @ 0x280051db4 size=0x168 =====
__int64 sub_280051DB4()
{
  return sub_2800B7DE9();
}


// ===== sub_280051F24 @ 0x280051f24 size=0xe9 =====
__int64 __fastcall sub_280051F24(__int64 a1, __int64 a2, int a3)
{
  _QWORD *PoolWithTag; // rax
  _QWORD *v7; // rbx
  __int64 *v9; // rdi
  _QWORD *v10; // rax

  PoolWithTag = ExAllocatePoolWithTag(PagedPool, 0x38u, 0x74706B64u);
  v7 = PoolWithTag;
  if ( PoolWithTag == nullptr )
    return 3221225626LL;
  PoolWithTag[2] = a1;
  ExAcquireFastMutex(&FastMutex);
  v9 = (__int64 *)qword_280075710;
  if ( (__int64 *)qword_280075710 == &qword_280075710 )
    goto LABEL_9;
  while ( v9[2] != v7[2] )
  {
    v9 = (__int64 *)*v9;
    if ( v9 == &qword_280075710 )
      goto LABEL_8;
  }
  ExFreePoolWithTag(v7, 0x74706B64u);
LABEL_8:
  if ( v9 == &qword_280075710 )
  {
LABEL_9:
    v7[5] = 0;
    *((_DWORD *)v7 + 12) = 0;
    *((_DWORD *)v7 + 13) = 0;
    *((_DWORD *)v7 + 6) = a3;
    v7[4] = a2;
    v10 = (_QWORD *)qword_280075718;
    v7[1] = qword_280075718;
    *v7 = &qword_280075710;
    *v10 = v7;
    qword_280075718 = (__int64)v7;
  }
  ExReleaseFastMutex(&FastMutex);
  return 0;
}


// ===== sub_280052014 @ 0x280052014 size=0xc2 =====
__int64 __fastcall sub_280052014(__int64 a1)
{
  __int64 *PoolWithTag; // rax
  __int64 *v3; // rbx
  __int64 v5; // rdi
  __int64 v6; // rax

  PoolWithTag = (__int64 *)ExAllocatePoolWithTag(PagedPool, 0x20u, 0x74706B64u);
  v3 = PoolWithTag;
  if ( PoolWithTag == nullptr )
    return 3221225626LL;
  PoolWithTag[2] = a1;
  ExAcquireFastMutex(&stru_2800757A0);
  v5 = qword_280075660;
  if ( (__int64 *)qword_280075660 == &qword_280075660 )
    goto LABEL_9;
  while ( *(_QWORD *)(v5 + 16) != v3[2] )
  {
    v5 = *(_QWORD *)v5;
    if ( (__int64 *)v5 == &qword_280075660 )
      goto LABEL_8;
  }
  ++*(_DWORD *)(v5 + 24);
  ExFreePoolWithTag(v3, 0x74706B64u);
LABEL_8:
  if ( (__int64 *)v5 == &qword_280075660 )
  {
LABEL_9:
    *((_DWORD *)v3 + 6) = 1;
    v6 = qword_280075660;
    v3[1] = (__int64)&qword_280075660;
    *v3 = v6;
    *(_QWORD *)(v6 + 8) = v3;
    qword_280075660 = (__int64)v3;
  }
  ExReleaseFastMutex(&stru_2800757A0);
  return 0;
}


// ===== sub_2800520DC @ 0x2800520dc size=0x68 =====
void __fastcall sub_2800520DC(__int64 a1)
{
  __int64 *i; // rcx
  __int64 *v4; // rdx
  __int64 *v5; // rax

  ExAcquireFastMutex(&stru_2800757A0);
  for ( i = (__int64 *)qword_280075660; i != &qword_280075660; i = (__int64 *)*i )
  {
    if ( i[2] == a1 )
    {
      if ( (*((_DWORD *)i + 6))-- == 1 )
      {
        v4 = (__int64 *)*i;
        v5 = (__int64 *)i[1];
        *v5 = *i;
        v4[1] = (__int64)v5;
        ExFreePoolWithTag(i, 0x74706B64u);
      }
      break;
    }
  }
  ExReleaseFastMutex(&stru_2800757A0);
}


// ===== sub_28005214C @ 0x28005214c size=0x6f =====
char __fastcall sub_28005214C(__int64 a1, __int64 a2)
{
  char v4; // bl
  __int64 *i; // r11

  v4 = 0;
  ExAcquireFastMutex(&FastMutex);
  for ( i = (__int64 *)qword_280075710; i != &qword_280075710; i = (__int64 *)*i )
  {
    if ( i[2] == a1 && (i[4] == a2 || i[5] == a2) )
    {
      v4 = 1;
      break;
    }
  }
  ExReleaseFastMutex(&FastMutex);
  return v4;
}


// ===== sub_2800521C4 @ 0x2800521c4 size=0x11d =====
char __fastcall sub_2800521C4(__int64 a1, __int64 a2, int a3)
{
  char v3; // bl
  __int64 i; // r11
  __int64 *j; // r11

  v3 = 0;
  if ( a3 == 2 )
    return sub_2800B7DE9();
  ExAcquireFastMutex(&FastMutex);
  for ( i = qword_280075710; (__int64 *)i != &qword_280075710; i = *(_QWORD *)i )
  {
    if ( *(_QWORD *)(i + 16) == a1
      && (a3 & *(_DWORD *)(i + 24)) == a3
      && (*(_QWORD *)(i + 32) == a2 && *(_DWORD *)(i + 48) != 0 || *(_QWORD *)(i + 40) == a2 && *(_DWORD *)(i + 52) != 0) )
    {
      v3 = 1;
      break;
    }
  }
  ExReleaseFastMutex(&FastMutex);
  if ( v3 != 0 )
    return 1;
  if ( a3 != 1 )
    return 0;
  ExAcquireFastMutex(&stru_2800757A0);
  for ( j = (__int64 *)qword_280075660; j != &qword_280075660; j = (__int64 *)*j )
  {
    if ( j[2] == a2 )
    {
      v3 = 1;
      break;
    }
  }
  ExReleaseFastMutex(&stru_2800757A0);
  return v3;
}


// ===== sub_2800522E8 @ 0x2800522e8 size=0x3b =====
__int64 __fastcall sub_2800522E8(__int64 a1, __int64 a2, __int64 a3)
{
  _BYTE v5[1048]; // [rsp+20h] [rbp-418h] BYREF

  sub_28006CA00(v5, a3, 8);
  return sub_28006CA7C(v5, a1, 504);
}


// ===== sub_28005232C @ 0x28005232c size=0x19e =====
__int64 __fastcall sub_28005232C(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
  unsigned int *DeviceExtension; // rbx
  unsigned int v3; // ebp
  unsigned int v7; // eax
  struct _DEVICE_OBJECT *v8; // rcx
  void *v9; // rcx
  void *v10; // rcx
  __int64 v11; // rcx
  wchar_t SourceString[64]; // [rsp+20h] [rbp-A8h] BYREF

  DeviceExtension = (unsigned int *)DeviceObject->DeviceExtension;
  v3 = 0;
  if ( DeviceExtension[52] == 3 )
    return 3221225506LL;
  v7 = DeviceExtension[42];
  v8 = *((struct _DEVICE_OBJECT **)DeviceExtension + 3);
  DeviceExtension[42] = 6;
  DeviceExtension[43] = v7;
  IoDetachDevice(v8);
  v9 = *((void **)DeviceExtension + 27);
  if ( v9 != nullptr )
    ObfDereferenceObject(v9);
  if ( Irp != nullptr )
  {
    ++Irp->CurrentLocation;
    ++Irp->Tail.Overlay.CurrentStackLocation;
    v3 = IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 3), Irp);
  }
  if ( DeviceExtension[52] == 2 && *((_QWORD *)DeviceExtension + 30) != 0 )
  {
    sub_28006BCF4(*((_QWORD *)DeviceExtension + 4));
    if ( *((_QWORD *)DeviceExtension + 2) != 0 )
    {
      swprintf(SourceString, L"\\??\\%s%x\\", aDpshadow, DeviceExtension[58]);
      sub_280052014((__int64)KeGetCurrentThread());
      sub_28005BC58(SourceString);
      sub_2800520DC((__int64)KeGetCurrentThread());
    }
    sub_280056684(*((_QWORD *)DeviceExtension + 30));
    ExFreePoolWithTag(*((PVOID *)DeviceExtension + 30), 0x74706B64u);
  }
  if ( DeviceExtension[52] == 0 )
  {
    v10 = *((void **)DeviceExtension + 95);
    if ( v10 != nullptr )
    {
      ExFreePoolWithTag(v10, 0x74706B64u);
      *((_QWORD *)DeviceExtension + 95) = 0;
      DeviceExtension[192] = 0;
    }
  }
  v11 = *((_QWORD *)DeviceExtension + 28);
  if ( v11 != 0 )
    sub_2800518D4(v11);
  ExAcquireFastMutex(&stru_280075760);
  IoDeleteDevice(DeviceObject);
  ExReleaseFastMutex(&stru_280075760);
  return v3;
}


// ===== sub_2800524D0 @ 0x2800524d0 size=0x40a =====
__int64 __fastcall sub_2800524D0(PDRIVER_OBJECT DriverObject, PDEVICE_OBJECT TargetDevice)
{
  bool v4; // si
  ULONG DeviceType; // ebx
  NTSTATUS v6; // ebx
  char *DeviceExtension; // rbx
  PDEVICE_OBJECT v9; // rax
  PDEVICE_OBJECT v10; // rax
  PVOID PoolWithTag; // rax
  struct _DEVICE_OBJECT *i; // rbx
  struct _DRIVER_OBJECT *v13; // rdx
  __int64 v14; // rax
  __int64 v15; // rax
  struct _DRIVER_OBJECT *v16; // rax
  __int64 DriverStart; // rcx
  __int64 v18; // rax
  struct _DRIVER_OBJECT *v19; // rdx
  __int64 v20; // rcx
  __int64 DriverSize; // rax
  signed __int32 v22; // eax
  __int64 v23; // rax
  PDEVICE_OBJECT SourceDevice; // [rsp+40h] [rbp-158h] BYREF
  ULONG Seed; // [rsp+48h] [rbp-150h] BYREF
  ULONG ResultLength; // [rsp+4Ch] [rbp-14Ch] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+50h] [rbp-148h] BYREF
  wchar_t PropertyBuffer[128]; // [rsp+60h] [rbp-138h] BYREF

  SourceDevice = nullptr;
  v4 = false;
  if ( IoGetDeviceProperty(TargetDevice, DevicePropertyClassGuid, 0x100u, PropertyBuffer, &ResultLength) >= 0 )
    v4 = wcsicmp(L"{4D36E967-E325-11CE-BFC1-08002BE10318}", PropertyBuffer) == 0;
  SourceDevice = IoGetAttachedDeviceReference(TargetDevice);
  DeviceType = SourceDevice->DeviceType;
  ObfDereferenceObject(SourceDevice);
  ExAcquireFastMutex(&stru_280075760);
  v6 = IoCreateDevice(DriverObject, 0x318u, nullptr, DeviceType, 0x100u, 0, &SourceDevice);
  ExReleaseFastMutex(&stru_280075760);
  if ( v6 < 0 )
    return (unsigned int)v6;
  DeviceExtension = (char *)SourceDevice->DeviceExtension;
  v9 = IoAttachDeviceToDeviceStack(SourceDevice, TargetDevice);
  *((_QWORD *)DeviceExtension + 3) = v9;
  if ( v9 != nullptr )
  {
    SourceDevice->Flags |= v9->Flags & 0x2014;
    SourceDevice->DeviceType = *(_DWORD *)(*((_QWORD *)DeviceExtension + 3) + 72LL);
    SourceDevice->Characteristics = *(_DWORD *)(*((_QWORD *)DeviceExtension + 3) + 52LL);
    v10 = SourceDevice;
    *((_QWORD *)DeviceExtension + 2) = 0;
    *((_QWORD *)DeviceExtension + 4) = TargetDevice;
    *((_QWORD *)DeviceExtension + 27) = 0;
    *((_QWORD *)DeviceExtension + 1) = v10;
    IoInitializeRemoveLockEx((PIO_REMOVE_LOCK)(DeviceExtension + 176), 0x6D727064u, 1u, 0x64u, 0x20u);
    *((_DWORD *)DeviceExtension + 42) = 0;
    *((_DWORD *)DeviceExtension + 43) = 0;
    *((_QWORD *)DeviceExtension + 28) = 0;
    sub_2800517A0((_QWORD *)DeviceExtension + 28, 21, 0);
    if ( v4 )
    {
      *((_DWORD *)DeviceExtension + 58) = -1;
      *(_DWORD *)DeviceExtension = 7680403;
      *((_DWORD *)DeviceExtension + 52) = 0;
      *((_DWORD *)DeviceExtension + 59) = 0;
      DeviceExtension[752] = 0;
      DeviceExtension[772] = 0;
      *((_QWORD *)DeviceExtension + 97) = 0;
      *((_QWORD *)DeviceExtension + 98) = 0;
      PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x7E00u, 0x74706B64u);
      *((_QWORD *)DeviceExtension + 95) = PoolWithTag;
      *((_DWORD *)DeviceExtension + 192) = PoolWithTag != nullptr ? 0x7E00 : 0;
      if ( qword_280074D48 == 0 )
      {
        RtlInitUnicodeString(&DestinationString, L"\\Driver\\Disk");
        for ( i = TargetDevice->AttachedDevice; i != nullptr; i = i->AttachedDevice )
        {
          v13 = i->DriverObject;
          if ( v13 != nullptr && RtlCompareUnicodeString(&DestinationString, &v13->DriverName, 1u) == 0 )
          {
            qword_280074D48 = (__int64)i->DriverObject;
            v14 = *(_QWORD *)(qword_280074D48 + 24) + *(unsigned int *)(qword_280074D48 + 32);
            qword_280074D50 = *(_QWORD *)(qword_280074D48 + 24);
            qword_280074D58 = v14;
            qword_280074D88 = (__int64)i->AttachedDevice->DriverObject;
            v15 = *(_QWORD *)(qword_280074D88 + 24) + *(unsigned int *)(qword_280074D88 + 32);
            qword_280074D90 = *(_QWORD *)(qword_280074D88 + 24);
            qword_280074D98 = v15;
            v16 = TargetDevice->DriverObject;
            DriverStart = (__int64)v16->DriverStart;
            qword_280074DB8 = (__int64)v16;
            v18 = DriverStart + v16->DriverSize;
            qword_280074DC0 = DriverStart;
            qword_280074DC8 = v18;
            v19 = TargetDevice->AttachedDevice->DriverObject;
            if ( v19 != (struct _DRIVER_OBJECT *)qword_280074D48 )
            {
              v20 = (__int64)v19->DriverStart;
              DriverSize = v19->DriverSize;
              qword_280074DF0 = (__int64)TargetDevice->AttachedDevice->DriverObject;
              qword_280074DF8 = v20;
              qword_280074E00 = v20 + DriverSize;
            }
            break;
          }
        }
      }
    }
    else
    {
      Seed = dword_280074C1C;
      dword_280074C1C += RtlRandom(&Seed) & 0x100;
      *(_DWORD *)DeviceExtension = 7680402;
      *((_DWORD *)DeviceExtension + 52) = 1;
      *((_DWORD *)DeviceExtension + 58) = _InterlockedIncrement(&dword_280074C1C);
      v22 = _InterlockedIncrement(&dword_280074D20);
      *((_QWORD *)DeviceExtension + 30) = 0;
      *((_QWORD *)DeviceExtension + 31) = 0;
      *((_DWORD *)DeviceExtension + 59) = v22;
      KeInitializeEvent((PRKEVENT)(DeviceExtension + 256), SynchronizationEvent, 1u);
      KeInitializeEvent((PRKEVENT)(DeviceExtension + 280), NotificationEvent, 1u);
      if ( qword_280074E10 == 0 )
      {
        qword_280074E10 = (__int64)TargetDevice->DriverObject;
        v23 = *(unsigned int *)(qword_280074E10 + 32);
        qword_280074E18 = *(_QWORD *)(qword_280074E10 + 24);
        qword_280074E20 = qword_280074E18 + v23;
      }
    }
    SourceDevice->Flags &= ~0x80u;
    return 0;
  }
  else
  {
    ExAcquireFastMutex(&stru_280075760);
    IoDeleteDevice(SourceDevice);
    ExReleaseFastMutex(&stru_280075760);
    return 3221225473LL;
  }
}


// ===== sub_2800528E0 @ 0x2800528e0 size=0x2f7 =====
__int64 __fastcall sub_2800528E0(__int64 a1, IRP *a2)
{
  __int64 v3; // rcx
  __int64 v4; // rdx
  __int64 v5; // r8
  _QWORD *v6; // rax
  __int64 v7; // rax
  struct _DEVICE_OBJECT *v8; // r10
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  char *DeviceExtension; // rbp
  NTSTATUS v12; // eax
  unsigned int v13; // edi

  if ( dword_280074A20 != 0 )
  {
    v3 = qword_280074D48;
    if ( qword_280074D68 != 0 && *(_UNKNOWN **)(qword_280074D48 + 144) != &sub_28005C474 )
      *(_QWORD *)(qword_280074D48 + 144) = &sub_28005C474;
    v4 = qword_280074D88;
    if ( qword_280074DA8 != 0 && *(_UNKNOWN **)(qword_280074D88 + 144) != &sub_28005CCBC )
      *(_QWORD *)(qword_280074D88 + 144) = &sub_28005CCBC;
    v5 = qword_280074DD0;
    v6 = (_QWORD *)qword_280074DB8;
    if ( qword_280074DD0 != 0 )
    {
      if ( *(_UNKNOWN **)(qword_280074DB8 + 232) != &sub_28005D0A0 )
        *(_QWORD *)(qword_280074DB8 + 232) = &sub_28005D0A0;
      if ( (_UNKNOWN *)v6[12] != &sub_28005DC1C )
        v6[12] = &sub_28005DC1C;
    }
    if ( qword_280074D70 != 0 && *(_UNKNOWN **)(v3 + 232) != &sub_28005C7C4 )
      *(_QWORD *)(v3 + 232) = &sub_28005C7C4;
    if ( qword_280074DB0 != 0 && *(_UNKNOWN **)(v4 + 232) != &sub_28005CF18 )
      *(_QWORD *)(v4 + 232) = &sub_28005CF18;
    if ( v5 != 0 && (_UNKNOWN *)v6[29] != &sub_28005D0A0 )
      v6[29] = &sub_28005D0A0;
    if ( qword_280074E08 != 0 && *(_UNKNOWN **)(qword_280074DF0 + 232) != &sub_28005DD58 )
      *(_QWORD *)(qword_280074DF0 + 232) = &sub_28005DD58;
    if ( qword_280074D78 != 0 && *(_UNKNOWN **)(v3 + 224) != &sub_28005CA40 )
      *(_QWORD *)(v3 + 224) = &sub_28005CA40;
    if ( qword_280074DD8 != 0 && (_UNKNOWN *)v6[28] != &sub_28005D718 )
      v6[28] = &sub_28005D718;
    v7 = qword_280074E10;
    if ( qword_280074E30 != 0 )
      *(_QWORD *)(qword_280074E10 + 144) = &sub_28005E0D8;
    if ( qword_280074E38 != 0 )
      *(_QWORD *)(v7 + 224) = &sub_28005E294;
  }
  sub_28006BB34();
  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  switch ( CurrentStackLocation->MajorFunction )
  {
    case 0u:
      return sub_280054618(v8, a2);
    case 3u:
      return sub_2800546EC(v8, a2);
    case 4u:
      return sub_280054AC0(v8, a2);
    case 0xEu:
      return sub_2800533FC(v8, a2);
    case 0xFu:
      return sub_280054E98(v8, a2);
    case 0x10u:
      return sub_280054F70(v8, a2);
    default:
      break;
  }
  if ( CurrentStackLocation->MajorFunction != 18 )
  {
    if ( CurrentStackLocation->MajorFunction == 22 )
      return sub_280053204(v8, a2);
    if ( CurrentStackLocation->MajorFunction == 27 )
      return sub_280052BE0(v8, a2);
  }
  DeviceExtension = (char *)v8->DeviceExtension;
  v12 = IoAcquireRemoveLockEx((PIO_REMOVE_LOCK)(DeviceExtension + 176), a2, &File, 1u, 0x20u);
  v13 = v12;
  if ( v12 >= 0 )
  {
    ++a2->CurrentLocation;
    ++a2->Tail.Overlay.CurrentStackLocation;
    v13 = IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 3), a2);
    IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)(DeviceExtension + 176), a2, 0x20u);
  }
  else
  {
    a2->IoStatus.Status = v12;
    IofCompleteRequest(a2, 0);
  }
  return v13;
}


// ===== sub_280052BE0 @ 0x280052be0 size=0x5d1 =====
NTSTATUS __fastcall sub_280052BE0(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
  char *DeviceExtension; // rdi
  struct _IO_REMOVE_LOCK *v4; // r15
  int v6; // eax
  NTSTATUS Status; // esi
  int v8; // r12d
  int v9; // edx
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  NTSTATUS v11; // ebx
  int v13; // eax
  struct _DEVICE_OBJECT *AttachedDevice; // rax
  struct _IO_STACK_LOCATION *v15; // rdx
  struct _IO_STACK_LOCATION *v16; // rbx
  struct _IO_STACK_LOCATION *v17; // rax
  bool v18; // zf
  int v19; // eax
  int v20; // ecx
  ULONG v21; // r12d
  SIZE_T i; // rdx
  NTSTATUS v23; // r13d
  unsigned int *PoolWithTag; // rax
  unsigned int *v25; // rbx
  _DWORD *v26; // r14
  PDEVICE_OBJECT j; // rdx
  _DWORD *v28; // r9
  unsigned int v29; // r10d
  int v30; // r11d
  _DWORD *v31; // r8
  unsigned int v32; // r15d
  _QWORD *v33; // r12
  _QWORD *v34; // r13
  struct _DEVICE_OBJECT *v35; // rcx
  __int64 v36; // rax
  int v37; // [rsp+40h] [rbp-308h]
  __int64 v38; // [rsp+48h] [rbp-300h] BYREF
  __int64 v39; // [rsp+58h] [rbp-2F0h] BYREF
  ULONG ReturnLength; // [rsp+60h] [rbp-2E8h] BYREF
  int v41; // [rsp+68h] [rbp-2E0h] BYREF
  __int64 v42; // [rsp+70h] [rbp-2D8h]
  wchar_t SourceString[64]; // [rsp+80h] [rbp-2C8h] BYREF
  struct _OBJECT_NAME_INFORMATION ObjectNameInfo[32]; // [rsp+100h] [rbp-248h] BYREF

  DeviceExtension = (char *)DeviceObject->DeviceExtension;
  v4 = (struct _IO_REMOVE_LOCK *)(DeviceExtension + 176);
  v38 = (__int64)(DeviceExtension + 176);
  v6 = IoAcquireRemoveLockEx((PIO_REMOVE_LOCK)(DeviceExtension + 176), Irp, &File, 1u, 0x20u);
  Status = 0;
  v8 = v6;
  if ( v6 < 0 )
  {
    Irp->IoStatus.Status = v6;
LABEL_30:
    IofCompleteRequest(Irp, 0);
    return v8;
  }
  v9 = *((_DWORD *)DeviceExtension + 52);
  CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
  if ( v9 == 3 && CurrentStackLocation->MinorFunction != 22 )
  {
    v11 = -1073741808;
    Irp->IoStatus.Status = -1073741808;
    IofCompleteRequest(Irp, 0);
LABEL_6:
    IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)(DeviceExtension + 176), Irp, 0x20u);
    return v11;
  }
  switch ( CurrentStackLocation->MinorFunction )
  {
    case 0u:
      if ( v9 == 0 )
        *((_QWORD *)DeviceExtension + 27) = IoGetAttachedDeviceReference(DeviceObject);
      v19 = sub_2800513D0(*((PDEVICE_OBJECT *)DeviceExtension + 3), Irp);
      v37 = v19;
      if ( v19 >= 0 )
      {
        v20 = *((_DWORD *)DeviceExtension + 42);
        *((_DWORD *)DeviceExtension + 42) = 1;
        *((_DWORD *)DeviceExtension + 43) = v20;
        if ( (*(_BYTE *)(*((_QWORD *)DeviceExtension + 3) + 52LL) & 1) != 0 )
          DeviceObject->Characteristics |= 1u;
      }
      Irp->IoStatus.Status = v19;
      IofCompleteRequest(Irp, 0);
      memset(ObjectNameInfo, 0, sizeof(ObjectNameInfo));
      if ( ObQueryNameString(*((PVOID *)DeviceExtension + 4), ObjectNameInfo, 0x200u, &ReturnLength) >= 0 )
        memmove(DeviceExtension + 40, ObjectNameInfo[0].Name.Buffer, ObjectNameInfo[0].Name.Length);
      if ( *((_DWORD *)DeviceExtension + 52) != 0 )
      {
        v21 = 32;
        for ( i = 32; ; i = v21 )
        {
          PoolWithTag = (unsigned int *)ExAllocatePoolWithTag(NonPagedPool, i, 0x74706B64u);
          v25 = PoolWithTag;
          if ( PoolWithTag == nullptr )
            break;
          v23 = sub_2800514A4(*((PDEVICE_OBJECT *)DeviceExtension + 3), 0x560000u, nullptr, 0, PoolWithTag, v21);
          if ( v23 >= 0 )
          {
            v26 = ExAllocatePoolWithTag(NonPagedPool, 32LL * *v25 + 40, 0x74706B64u);
            if ( v26 != nullptr )
            {
              ExAcquireFastMutex(&stru_280075760);
              for ( j = DriverObject->DeviceObject; j != nullptr; j = j->NextDevice )
              {
                if ( j != ::DeviceObject )
                {
                  v28 = j->DeviceExtension;
                  if ( *v28 == 7680403 )
                  {
                    v29 = 0;
                    if ( *v25 != 0 )
                    {
                      v30 = v28[58];
                      v31 = v25 + 4;
                      do
                      {
                        if ( *(v31 - 2) == v30 && *(_QWORD *)v31 < (__int64)(unsigned int)v28[192] )
                          v28[192] = *v31;
                        ++v29;
                        v31 += 6;
                      }
                      while ( v29 < *v25 );
                    }
                  }
                }
              }
              ExReleaseFastMutex(&stru_280075760);
              v32 = 0;
              *v26 = *v25;
              if ( *v25 != 0 )
              {
                v33 = v26 + 4;
                v34 = v25 + 4;
                do
                {
                  v35 = *((struct _DEVICE_OBJECT **)DeviceExtension + 3);
                  v41 = *((_DWORD *)v34 - 2);
                  v42 = *v34;
                  if ( sub_2800514A4(v35, 0x560024u, &v41, 0x10u, &v39, 8u) < 0 )
                    break;
                  ++v32;
                  *((_DWORD *)v33 - 2) = *((_DWORD *)v34 - 2);
                  v36 = *v34;
                  v34 += 3;
                  *v33 = v36;
                  v33 += 4;
                  *(v33 - 3) = *(v34 - 2);
                  *(v33 - 2) = v39;
                }
                while ( v32 < *v25 );
              }
              if ( v32 < *v25 )
                ExFreePoolWithTag(v26, 0x74706B64u);
              else
                *((_QWORD *)DeviceExtension + 31) = v26;
              ExFreePoolWithTag(v25, 0x74706B64u);
              v4 = (struct _IO_REMOVE_LOCK *)v38;
            }
            else
            {
              ExFreePoolWithTag(v25, 0x74706B64u);
            }
            break;
          }
          ExFreePoolWithTag(v25, 0x74706B64u);
          if ( v23 != -1073741789 )
            break;
          v21 *= 2;
        }
      }
      else if ( sub_2800514A4(*((PDEVICE_OBJECT *)DeviceExtension + 3), 0x2D1080u, nullptr, 0, &v38, 0xCu) >= 0 )
      {
        *((_DWORD *)DeviceExtension + 58) = HIDWORD(v38);
      }
      IoReleaseRemoveLockEx(v4, Irp, 0x20u);
      return v37;
    case 1u:
      if ( v9 == 2 && *((_QWORD *)DeviceExtension + 30) != 0 )
      {
        sub_28006BCF4(*((_QWORD *)DeviceExtension + 4));
        if ( *((_QWORD *)DeviceExtension + 2) != 0 )
        {
          swprintf(SourceString, L"\\??\\%s%x\\", aDpshadow, *((unsigned int *)DeviceExtension + 58));
          sub_280052014((__int64)KeGetCurrentThread());
          sub_28005BC58(SourceString);
          sub_2800520DC((__int64)KeGetCurrentThread());
        }
      }
      v13 = *((_DWORD *)DeviceExtension + 42);
      *((_DWORD *)DeviceExtension + 42) = 4;
      goto LABEL_37;
    case 2u:
      if ( v9 == 3 )
      {
        v8 = -1073741790;
        Irp->IoStatus.Status = -1073741790;
        goto LABEL_30;
      }
      IoReleaseRemoveLockAndWaitEx((PIO_REMOVE_LOCK)(DeviceExtension + 176), Irp, 0x20u);
      return sub_28005232C(DeviceObject, Irp);
    case 3u:
      v18 = *((_DWORD *)DeviceExtension + 42) == 4;
LABEL_23:
      if ( v18 )
        *((_DWORD *)DeviceExtension + 42) = *((_DWORD *)DeviceExtension + 43);
      goto LABEL_38;
    case 4u:
      v13 = *((_DWORD *)DeviceExtension + 42);
      *((_DWORD *)DeviceExtension + 42) = 3;
      goto LABEL_37;
    case 5u:
      v13 = *((_DWORD *)DeviceExtension + 42);
      *((_DWORD *)DeviceExtension + 42) = 2;
      goto LABEL_37;
    case 6u:
      v18 = *((_DWORD *)DeviceExtension + 42) == 2;
      goto LABEL_23;
    default:
      break;
  }
  if ( CurrentStackLocation->MinorFunction != 22 )
  {
    if ( CurrentStackLocation->MinorFunction != 23 )
    {
      Status = Irp->IoStatus.Status;
LABEL_38:
      ++Irp->CurrentLocation;
      ++Irp->Tail.Overlay.CurrentStackLocation;
      Irp->IoStatus.Status = Status;
      v11 = IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 3), Irp);
      goto LABEL_6;
    }
    v13 = *((_DWORD *)DeviceExtension + 42);
    *((_DWORD *)DeviceExtension + 42) = 5;
LABEL_37:
    *((_DWORD *)DeviceExtension + 43) = v13;
    goto LABEL_38;
  }
  AttachedDevice = DeviceObject->AttachedDevice;
  if ( AttachedDevice == nullptr || _bittest((const signed __int32 *)&AttachedDevice->Flags, 0xDu) )
    DeviceObject->Flags |= 0x2000u;
  v15 = Irp->Tail.Overlay.CurrentStackLocation;
  v16 = v15 - 1;
  memmove(&v15[-1], v15, 0x38u);
  v16->Control = 0;
  v17 = Irp->Tail.Overlay.CurrentStackLocation;
  v17[-1].Context = nullptr;
  v17[-1].Control = -32;
  v17[-1].CompletionRoutine = (PIO_COMPLETION_ROUTINE)sub_2800531B8;
  return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 3), Irp);
}


// ===== sub_2800531B8 @ 0x2800531b8 size=0x43 =====
__int64 __fastcall sub_2800531B8(__int64 a1, __int64 a2)
{
  __int64 v2; // r8

  v2 = *(_QWORD *)(a1 + 64);
  if ( *(_BYTE *)(a2 + 65) != 0 )
    *(_BYTE *)(*(_QWORD *)(a2 + 184) + 3LL) |= 1u;
  if ( !_bittest((const signed __int32 *)(*(_QWORD *)(v2 + 24) + 48LL), 0xDu) )
    *(_DWORD *)(a1 + 48) &= ~0x2000u;
  IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)(v2 + 176), (PVOID)a2, 0x20u);
  return 0;
}


// ===== sub_280053204 @ 0x280053204 size=0x1ef =====
__int64 __fastcall sub_280053204(struct _LIST_ENTRY *Object, IRP *Tag)
{
  struct _LIST_ENTRY *Flink; // rsi
  NTSTATUS v5; // eax
  unsigned int v6; // ebx
  int v7; // edx
  bool v8; // al
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  struct _LIST_ENTRY *v10; // rbx

  PoStartNextPowerIrp(Tag);
  Flink = Object[4].Flink;
  v5 = IoAcquireRemoveLockEx((PIO_REMOVE_LOCK)&Flink[11], Tag, &File, 1u, 0x20u);
  v6 = v5;
  if ( v5 >= 0 )
  {
    v7 = (int)Flink[13].Flink;
    v8 = v7 != 2;
    if ( v7 == 0 && HIDWORD(Flink[14].Blink) != 0 && LOBYTE(Flink[47].Flink) != 0 )
      v8 = false;
    if ( !v8 )
    {
      CurrentStackLocation = Tag->Tail.Overlay.CurrentStackLocation;
      if ( CurrentStackLocation->MinorFunction != 2
        || CurrentStackLocation->Parameters.Create.Options != 0
        || CurrentStackLocation->Parameters.Read.ByteOffset.LowPart != 5
        || CurrentStackLocation->Parameters.Create.EaLength != 3 )
      {
        Tag->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
        goto LABEL_20;
      }
      if ( v7 == 0 || KeReadStateEvent((PRKEVENT)&Flink[17].Blink) == 0 )
      {
        ++dword_280074794;
        v10 = (struct _LIST_ENTRY *)ExpInterlockedPopEntrySList(&ListHead);
        if ( v10 != nullptr
          || (++dword_280074798,
              (v10 = (struct _LIST_ENTRY *)qword_2800747B0(
                                             (unsigned int)dword_2800747A4,
                                             (unsigned int)dword_2800747AC,
                                             (unsigned int)dword_2800747A8)) != nullptr) )
        {
          Tag->Tail.Overlay.CurrentStackLocation->Control |= 1u;
          v10[1].Blink = v10;
          v10[1].Flink = (struct _LIST_ENTRY *)sub_2800552F0;
          v10[2].Flink = Object;
          v10[2].Blink = (struct _LIST_ENTRY *)Tag;
          ObfReferenceObject(Object);
          sub_28005192C((__int64)Flink[14].Flink, v10);
          return 259;
        }
        v6 = -1073741670;
        Tag->IoStatus.Status = -1073741670;
        Tag->IoStatus.Information = 0;
        IofCompleteRequest(Tag, 1);
        goto LABEL_21;
      }
    }
    ++Tag->Tail.Overlay.CurrentStackLocation;
LABEL_20:
    ++Tag->CurrentLocation;
    v6 = PoCallDriver((PDEVICE_OBJECT)Flink[1].Blink, Tag);
LABEL_21:
    IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)&Flink[11], Tag, 0x20u);
    return v6;
  }
  Tag->IoStatus.Status = v5;
  IofCompleteRequest(Tag, 0);
  return v6;
}


// ===== sub_2800533FC @ 0x2800533fc size=0xae4 =====
__int64 sub_2800533FC()
{
  return sub_2800B7DE9();
}


// ===== sub_280053EE8 @ 0x280053ee8 size=0x727 =====
__int64 __fastcall sub_280053EE8(__int64 a1, IRP *a2)
{
  NTSTATUS v3; // eax
  unsigned int v4; // ebx

  v3 = IoAcquireRemoveLockEx((PIO_REMOVE_LOCK)(*(_QWORD *)(a1 + 64) + 176LL), a2, &File, 1u, 0x20u);
  v4 = v3;
  if ( v3 >= 0 )
    return sub_2800B7DE9();
  a2->IoStatus.Status = v3;
  IofCompleteRequest(a2, 0);
  return v4;
}


// ===== sub_280054618 @ 0x280054618 size=0xcd =====
__int64 __fastcall sub_280054618(__int64 a1, IRP *a2)
{
  __int64 v2; // rsi
  NTSTATUS v4; // eax
  unsigned int v5; // edi

  v2 = *(_QWORD *)(a1 + 64);
  v4 = IoAcquireRemoveLockEx((PIO_REMOVE_LOCK)(v2 + 176), a2, &File, 1u, 0x20u);
  v5 = v4;
  if ( v4 >= 0 )
  {
    if ( *(_DWORD *)(v2 + 208) != 3
      || (*(_BYTE *)(a2->Tail.Overlay.CurrentStackLocation->Parameters.WMI.ProviderId + 16) & 3) != 0 )
    {
      ++a2->CurrentLocation;
      ++a2->Tail.Overlay.CurrentStackLocation;
      v5 = IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 24), a2);
    }
    else
    {
      a2->IoStatus.Information = 0;
      v5 = -1073741772;
      a2->IoStatus.Status = -1073741772;
      IofCompleteRequest(a2, 1);
    }
    IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)(v2 + 176), a2, 0x20u);
  }
  else
  {
    a2->IoStatus.Status = v4;
    IofCompleteRequest(a2, 0);
  }
  return v5;
}


// ===== sub_2800546EC @ 0x2800546ec size=0x3cc =====
__int64 __fastcall sub_2800546EC(struct _LIST_ENTRY *Object, IRP *Tag)
{
  struct _LIST_ENTRY *Flink; // rdi
  NTSTATUS v5; // eax
  unsigned int v6; // esi
  struct _IO_STACK_LOCATION *CurrentStackLocation; // r14
  int v9; // eax
  __int64 QuadPart; // r13
  __int64 Blink; // rax
  __int64 v12; // r12
  unsigned __int64 *v13; // rax
  unsigned __int64 *v14; // rdx
  PMDL MdlAddress; // rcx
  char *v16; // rbp
  NTSTATUS v17; // eax
  __int64 Flink_low; // rax
  struct _LIST_ENTRY *v19; // rsi
  unsigned __int64 LowLimit[9]; // [rsp+30h] [rbp-48h] BYREF
  __int64 v21; // [rsp+80h] [rbp+8h] BYREF
  unsigned __int64 *v22; // [rsp+90h] [rbp+18h]
  unsigned __int64 HighLimit; // [rsp+98h] [rbp+20h] BYREF

  Flink = Object[4].Flink;
  v5 = IoAcquireRemoveLockEx((PIO_REMOVE_LOCK)&Flink[11], Tag, &File, 1u, 0x20u);
  v6 = v5;
  if ( v5 < 0 )
  {
    Tag->IoStatus.Status = v5;
    IofCompleteRequest(Tag, 0);
    return v6;
  }
  CurrentStackLocation = Tag->Tail.Overlay.CurrentStackLocation;
  if ( CurrentStackLocation->Parameters.Read.Length == 0 )
  {
    Tag->IoStatus.Status = 0;
    v6 = 0;
LABEL_49:
    Tag->IoStatus.Information = 0;
LABEL_50:
    IofCompleteRequest(Tag, 1);
    goto LABEL_51;
  }
  v9 = (int)Flink[13].Flink;
  if ( v9 != 2 )
  {
    if ( (byte_280074A24 & 0x20) == 0
      && v9 == 0
      && HIDWORD(Flink[14].Blink) != 0
      && Flink[13].Blink == Object
      && BYTE4(Flink[48].Flink) != 0
      && KeGetCurrentIrql() < 2u
      && qword_280074E10 != 0
      && qword_280074E18 != 0
      && qword_280074E20 != 0 )
    {
      QuadPart = CurrentStackLocation->Parameters.Read.ByteOffset.QuadPart;
      Blink = (__int64)Flink[48].Blink;
      v12 = QuadPart + CurrentStackLocation->Parameters.Read.Length;
      if ( QuadPart >= Blink && QuadPart < (__int64)Flink[49].Flink || v12 > Blink && v12 <= (__int64)Flink[49].Flink )
      {
        v13 = (unsigned __int64 *)qword_280074BF8();
        v21 = (__int64)&v21;
        v14 = (unsigned __int64 *)&v21;
        v22 = (unsigned __int64 *)((char *)&v21 + qword_280074518);
        if ( v13 > &STACK[0x880] )
          v13 = &STACK[0x880];
        if ( v22 <= (unsigned __int64 *)&v21 || v22 >= v13 || *v22 <= qword_280074E18 || *v22 >= qword_280074E20 )
        {
          while ( ++v14 < v13 )
          {
            if ( *v14 > qword_280074E18 && *v14 < qword_280074E20 )
            {
              v22 = v14;
              goto LABEL_30;
            }
          }
          v17 = sub_28005E470(Object, Tag, qword_280074E20, qword_280074E18);
          goto LABEL_35;
        }
LABEL_30:
        qword_280074518 = (__int64)v22 - v21;
      }
      if ( QuadPart < LODWORD(Flink[48].Flink) )
      {
        MdlAddress = Tag->MdlAddress;
        v16 = (char *)((MdlAddress->MdlFlags & 5) != 0
                     ? MdlAddress->MappedSystemVa
                     : MmMapLockedPagesSpecifyCache(MdlAddress, 0, MmCached, nullptr, 0, 0x10u));
        if ( v16 != nullptr )
        {
          Flink_low = LODWORD(Flink[48].Flink);
          if ( v12 <= Flink_low )
          {
            memmove(v16, (char *)Flink[47].Blink + QuadPart, CurrentStackLocation->Parameters.Read.Length);
          }
          else
          {
            memmove(v16, (char *)Flink[47].Blink + QuadPart, (unsigned int)(Flink_low - QuadPart));
            v6 = sub_28005155C(
                   (PDEVICE_OBJECT)Flink[1].Blink,
                   3u,
                   &v16[LODWORD(Flink[48].Flink) - (unsigned __int64)(unsigned int)QuadPart],
                   v12 - LODWORD(Flink[48].Flink),
                   (union _LARGE_INTEGER)LODWORD(Flink[48].Flink));
          }
          Tag->IoStatus.Status = v6;
          Tag->IoStatus.Information = CurrentStackLocation->Parameters.Read.Length;
          goto LABEL_50;
        }
      }
    }
    ++Tag->CurrentLocation;
    ++Tag->Tail.Overlay.CurrentStackLocation;
    v17 = IofCallDriver((PDEVICE_OBJECT)Flink[1].Blink, Tag);
LABEL_35:
    v6 = v17;
LABEL_51:
    IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)&Flink[11], Tag, 0x20u);
    return v6;
  }
  if ( KeGetCurrentIrql() < 2u )
  {
    IoGetStackLimits(LowLimit, &HighLimit);
    if ( (unsigned __int64)&HighLimit - LowLimit[0] >= 0x1000 )
      return sub_280056FF4(Object, Tag);
  }
  ++dword_280074794;
  v19 = (struct _LIST_ENTRY *)ExpInterlockedPopEntrySList(&ListHead);
  if ( v19 == nullptr )
  {
    ++dword_280074798;
    v19 = (struct _LIST_ENTRY *)qword_2800747B0(
                                  (unsigned int)dword_2800747A4,
                                  (unsigned int)dword_2800747AC,
                                  (unsigned int)dword_2800747A8);
    if ( v19 == nullptr )
    {
      v6 = -1073741670;
      Tag->IoStatus.Status = -1073741670;
      goto LABEL_49;
    }
  }
  Tag->Tail.Overlay.CurrentStackLocation->Control |= 1u;
  v19[1].Blink = v19;
  v19[1].Flink = (struct _LIST_ENTRY *)sub_2800552F0;
  v19[2].Flink = Object;
  v19[2].Blink = (struct _LIST_ENTRY *)Tag;
  ObfReferenceObject(Object);
  sub_28005192C((__int64)Flink[14].Flink, v19);
  return 259;
}


// ===== sub_280054AC0 @ 0x280054ac0 size=0x3d0 =====
__int64 __fastcall sub_280054AC0(struct _LIST_ENTRY *Object, IRP *Tag)
{
  struct _LIST_ENTRY *Flink; // rdi
  NTSTATUS v5; // eax
  unsigned int v6; // esi
  struct _IO_STACK_LOCATION *CurrentStackLocation; // r14
  int v9; // eax
  __int64 QuadPart; // r13
  __int64 Blink; // rax
  __int64 v12; // r12
  unsigned __int64 *v13; // rax
  unsigned __int64 *v14; // rdx
  PMDL MdlAddress; // rcx
  char *v16; // rbp
  NTSTATUS v17; // eax
  __int64 Flink_low; // rax
  struct _LIST_ENTRY *v19; // rsi
  unsigned __int64 LowLimit[9]; // [rsp+30h] [rbp-48h] BYREF
  __int64 v21; // [rsp+80h] [rbp+8h] BYREF
  unsigned __int64 *v22; // [rsp+90h] [rbp+18h]
  unsigned __int64 HighLimit; // [rsp+98h] [rbp+20h] BYREF

  Flink = Object[4].Flink;
  v5 = IoAcquireRemoveLockEx((PIO_REMOVE_LOCK)&Flink[11], Tag, &File, 1u, 0x20u);
  v6 = v5;
  if ( v5 < 0 )
  {
    Tag->IoStatus.Status = v5;
    IofCompleteRequest(Tag, 0);
    return v6;
  }
  CurrentStackLocation = Tag->Tail.Overlay.CurrentStackLocation;
  if ( CurrentStackLocation->Parameters.Read.Length == 0 )
  {
    Tag->IoStatus.Status = 0;
    v6 = 0;
LABEL_50:
    Tag->IoStatus.Information = 0;
LABEL_51:
    IofCompleteRequest(Tag, 1);
    goto LABEL_52;
  }
  v9 = (int)Flink[13].Flink;
  if ( v9 != 2 && v9 != 3 )
  {
    if ( (byte_280074A24 & 0x20) == 0
      && v9 == 0
      && HIDWORD(Flink[14].Blink) != 0
      && Flink[13].Blink == Object
      && BYTE4(Flink[48].Flink) != 0
      && KeGetCurrentIrql() < 2u
      && qword_280074E10 != 0
      && qword_280074E18 != 0
      && qword_280074E20 != 0 )
    {
      QuadPart = CurrentStackLocation->Parameters.Read.ByteOffset.QuadPart;
      Blink = (__int64)Flink[48].Blink;
      v12 = QuadPart + CurrentStackLocation->Parameters.Read.Length;
      if ( QuadPart >= Blink && QuadPart < (__int64)Flink[49].Flink || v12 > Blink && v12 <= (__int64)Flink[49].Flink )
      {
        v13 = (unsigned __int64 *)qword_280074BF8();
        v21 = (__int64)&v21;
        v14 = (unsigned __int64 *)&v21;
        v22 = (unsigned __int64 *)((char *)&v21 + qword_280074520);
        if ( v13 > &STACK[0x880] )
          v13 = &STACK[0x880];
        if ( v22 <= (unsigned __int64 *)&v21 || v22 >= v13 || *v22 <= qword_280074E18 || *v22 >= qword_280074E20 )
        {
          while ( ++v14 < v13 )
          {
            if ( *v14 > qword_280074E18 && *v14 < qword_280074E20 )
            {
              v22 = v14;
              goto LABEL_31;
            }
          }
          v17 = sub_28005E470(Object, Tag, qword_280074E20, qword_280074E18);
          goto LABEL_36;
        }
LABEL_31:
        qword_280074520 = (__int64)v22 - v21;
      }
      if ( QuadPart < LODWORD(Flink[48].Flink) )
      {
        MdlAddress = Tag->MdlAddress;
        v16 = (char *)((MdlAddress->MdlFlags & 5) != 0
                     ? MdlAddress->MappedSystemVa
                     : MmMapLockedPagesSpecifyCache(MdlAddress, 0, MmCached, nullptr, 0, 0x10u));
        if ( v16 != nullptr )
        {
          Flink_low = LODWORD(Flink[48].Flink);
          if ( v12 <= Flink_low )
          {
            memmove((char *)Flink[47].Blink + QuadPart, v16, CurrentStackLocation->Parameters.Read.Length);
          }
          else
          {
            memmove((char *)Flink[47].Blink + QuadPart, v16, (unsigned int)(Flink_low - QuadPart));
            v6 = sub_28005155C(
                   (PDEVICE_OBJECT)Flink[1].Blink,
                   4u,
                   &v16[LODWORD(Flink[48].Flink) - (unsigned __int64)(unsigned int)QuadPart],
                   v12 - LODWORD(Flink[48].Flink),
                   (union _LARGE_INTEGER)LODWORD(Flink[48].Flink));
          }
          Tag->IoStatus.Status = v6;
          Tag->IoStatus.Information = CurrentStackLocation->Parameters.Read.Length;
          goto LABEL_51;
        }
      }
    }
    ++Tag->CurrentLocation;
    ++Tag->Tail.Overlay.CurrentStackLocation;
    v17 = IofCallDriver((PDEVICE_OBJECT)Flink[1].Blink, Tag);
LABEL_36:
    v6 = v17;
LABEL_52:
    IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)&Flink[11], Tag, 0x20u);
    return v6;
  }
  if ( KeGetCurrentIrql() < 2u )
  {
    IoGetStackLimits(LowLimit, &HighLimit);
    if ( (unsigned __int64)&HighLimit - LowLimit[0] >= 0x1000 )
      return sub_280057368(Object, Tag);
  }
  ++dword_280074794;
  v19 = (struct _LIST_ENTRY *)ExpInterlockedPopEntrySList(&ListHead);
  if ( v19 == nullptr )
  {
    ++dword_280074798;
    v19 = (struct _LIST_ENTRY *)qword_2800747B0(
                                  (unsigned int)dword_2800747A4,
                                  (unsigned int)dword_2800747AC,
                                  (unsigned int)dword_2800747A8);
    if ( v19 == nullptr )
    {
      v6 = -1073741670;
      Tag->IoStatus.Status = -1073741670;
      goto LABEL_50;
    }
  }
  Tag->Tail.Overlay.CurrentStackLocation->Control |= 1u;
  v19[1].Blink = v19;
  v19[1].Flink = (struct _LIST_ENTRY *)sub_2800552F0;
  v19[2].Flink = Object;
  v19[2].Blink = (struct _LIST_ENTRY *)Tag;
  ObfReferenceObject(Object);
  sub_28005192C((__int64)Flink[14].Flink, v19);
  return 259;
}


// ===== sub_280054E98 @ 0x280054e98 size=0xd0 =====
__int64 __fastcall sub_280054E98(__int64 a1, IRP *a2)
{
  __int64 v2; // rsi
  NTSTATUS v4; // eax
  unsigned int v5; // ebx
  int v6; // eax

  v2 = *(_QWORD *)(a1 + 64);
  v4 = IoAcquireRemoveLockEx((PIO_REMOVE_LOCK)(v2 + 176), a2, &File, 1u, 0x20u);
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = *(_DWORD *)(v2 + 208);
    if ( v6 == 2 || v6 == 3 || v6 == 0 && *(_DWORD *)(v2 + 236) != 0 )
    {
      a2->IoStatus.Information = 0;
      v5 = -1073741790;
      a2->IoStatus.Status = -1073741790;
      IofCompleteRequest(a2, 0);
    }
    else
    {
      ++a2->CurrentLocation;
      ++a2->Tail.Overlay.CurrentStackLocation;
      v5 = IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 24), a2);
    }
    IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)(v2 + 176), a2, 0x20u);
  }
  else
  {
    a2->IoStatus.Status = v4;
    IofCompleteRequest(a2, 0);
  }
  return v5;
}


// ===== sub_280054F70 @ 0x280054f70 size=0x37a =====
__int64 __fastcall sub_280054F70(__int64 a1, IRP *a2)
{
  __int64 v2; // rdi
  NTSTATUS v4; // eax
  unsigned int v5; // ebx
  __int64 v6; // rbx
  char *v7; // r9
  unsigned __int8 *v8; // r8
  unsigned int v9; // r11d
  unsigned __int8 *v10; // rdx
  _BYTE *v11; // rcx
  __int64 i; // rdx
  char v13; // al
  __int64 v14; // rdx
  __int64 v15; // rcx
  __int64 v16; // r8
  _QWORD *v17; // rax
  __int64 v18; // rax
  _BYTE *v19; // rdx
  _BYTE v21[512]; // [rsp+30h] [rbp-228h] BYREF

  v2 = *(_QWORD *)(a1 + 64);
  v4 = IoAcquireRemoveLockEx((PIO_REMOVE_LOCK)(v2 + 176), a2, &File, 1u, 0x20u);
  v5 = v4;
  if ( v4 >= 0 )
  {
    if ( *(_DWORD *)(v2 + 208) == 0
      && *(_BYTE *)(v2 + 752) != 0
      && *(_DWORD *)(v2 + 236) != 0
      && KeGetCurrentIrql() < 2u )
    {
      v6 = 512;
      sub_28005155C(*(PDEVICE_OBJECT *)(v2 + 24), 3u, v21, 0x200u, 0);
      v7 = (char *)(v2 + 240);
      v8 = (unsigned __int8 *)(v2 + 240);
      v9 = 0;
      v10 = v21;
      do
      {
        if ( *v10 != ~*v8 )
          break;
        ++v9;
        ++v8;
        ++v10;
      }
      while ( v9 < 0x200 );
      if ( v9 < 0x200 )
      {
        v11 = v21;
        for ( i = 512; i != 0; --i )
        {
          v13 = *v7++;
          *v11++ = ~v13;
        }
        if ( v21[510] == 85 && v21[511] == 0xAA )
        {
          sub_28005155C(*(PDEVICE_OBJECT *)(v2 + 24), 4u, v21, 0x200u, 0);
          if ( dword_280074A20 != 0 )
          {
            v14 = qword_280074D48;
            if ( qword_280074D68 != 0 && *(_UNKNOWN **)(qword_280074D48 + 144) != &sub_28005C474 )
              *(_QWORD *)(qword_280074D48 + 144) = &sub_28005C474;
            v15 = qword_280074D88;
            if ( qword_280074DA8 != 0 && *(_UNKNOWN **)(qword_280074D88 + 144) != &sub_28005CCBC )
              *(_QWORD *)(qword_280074D88 + 144) = &sub_28005CCBC;
            v16 = qword_280074DD0;
            v17 = (_QWORD *)qword_280074DB8;
            if ( qword_280074DD0 != 0 )
            {
              if ( *(_UNKNOWN **)(qword_280074DB8 + 232) != &sub_28005D0A0 )
                *(_QWORD *)(qword_280074DB8 + 232) = &sub_28005D0A0;
              if ( (_UNKNOWN *)v17[12] != &sub_28005DC1C )
                v17[12] = &sub_28005DC1C;
            }
            if ( qword_280074D70 != 0 && *(_UNKNOWN **)(v14 + 232) != &sub_28005C7C4 )
              *(_QWORD *)(v14 + 232) = &sub_28005C7C4;
            if ( qword_280074DB0 != 0 && *(_UNKNOWN **)(v15 + 232) != &sub_28005CF18 )
              *(_QWORD *)(v15 + 232) = &sub_28005CF18;
            if ( v16 != 0 && (_UNKNOWN *)v17[29] != &sub_28005D0A0 )
              v17[29] = &sub_28005D0A0;
            if ( qword_280074E08 != 0 && *(_UNKNOWN **)(qword_280074DF0 + 232) != &sub_28005DD58 )
              *(_QWORD *)(qword_280074DF0 + 232) = &sub_28005DD58;
            if ( qword_280074D78 != 0 && *(_UNKNOWN **)(v14 + 224) != &sub_28005CA40 )
              *(_QWORD *)(v14 + 224) = &sub_28005CA40;
            if ( qword_280074DD8 != 0 && (_UNKNOWN *)v17[28] != &sub_28005D718 )
              v17[28] = &sub_28005D718;
            v18 = qword_280074E10;
            if ( qword_280074E30 != 0 )
              *(_QWORD *)(qword_280074E10 + 144) = &sub_28005E0D8;
            if ( qword_280074E38 != 0 )
              *(_QWORD *)(v18 + 224) = &sub_28005E294;
          }
          sub_28005155C(*(PDEVICE_OBJECT *)(v2 + 32), 4u, v21, 0x200u, 0);
        }
        v19 = v21;
        do
        {
          *v19 = ~*v19;
          ++v19;
          --v6;
        }
        while ( v6 != 0 );
      }
    }
    ++a2->CurrentLocation;
    ++a2->Tail.Overlay.CurrentStackLocation;
    v5 = IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 24), a2);
    IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)(v2 + 176), a2, 0x20u);
  }
  else
  {
    a2->IoStatus.Status = v4;
    IofCompleteRequest(a2, 0);
  }
  return v5;
}


// ===== sub_2800552F0 @ 0x2800552f0 size=0x3f5 =====
void __fastcall sub_2800552F0(PSLIST_ENTRY ListEntry)
{
  struct _SLIST_ENTRY *Next; // rdi
  IRP *v2; // rbp
  struct _SLIST_ENTRY *v4; // r12
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rbx
  __int64 v6; // rbx
  struct _SLIST_ENTRY *v7; // r9
  struct _SLIST_ENTRY *v8; // r8
  unsigned int v9; // r11d
  unsigned __int8 *v10; // rdx
  _BYTE *v11; // rcx
  __int64 i; // rdx
  char v13; // al
  __int64 v14; // rdx
  __int64 v15; // rcx
  __int64 v16; // r8
  _QWORD *v17; // rax
  __int64 v18; // rax
  _BYTE *v19; // rcx
  _BYTE v20[512]; // [rsp+30h] [rbp-228h] BYREF

  Next = ListEntry[2].Next;
  v2 = *((IRP **)&ListEntry[2].Next + 1);
  v4 = Next[4].Next;
  CurrentStackLocation = v2->Tail.Overlay.CurrentStackLocation;
  ObfDereferenceObject(Next);
  ++dword_28007479C;
  if ( ExQueryDepthSList(&ListHead) < (unsigned __int16)word_280074790 )
  {
    ExpInterlockedPushEntrySList(&ListHead, ListEntry);
  }
  else
  {
    ++dword_2800747A0;
    qword_2800747B8(ListEntry);
  }
  switch ( CurrentStackLocation->MajorFunction )
  {
    case 3u:
      sub_280056FF4(Next, v2);
      break;
    case 4u:
      sub_280057368(Next, v2);
      break;
    case 0x16u:
      if ( CurrentStackLocation->MinorFunction == 2
        && CurrentStackLocation->Parameters.Create.Options == 0
        && CurrentStackLocation->Parameters.Read.ByteOffset.LowPart == 5
        && CurrentStackLocation->Parameters.Create.EaLength == 3 )
      {
        if ( LODWORD(v4[13].Next) != 0 )
        {
          KeWaitForSingleObject(&v4[17].Next + 1, Executive, 0, 0, nullptr);
        }
        else if ( LOBYTE(v4[47].Next) != 0 )
        {
          v6 = 512;
          sub_28005155C(*((PDEVICE_OBJECT *)&v4[1].Next + 1), 3u, v20, 0x200u, 0);
          v7 = v4 + 15;
          v8 = v4 + 15;
          v9 = 0;
          v10 = v20;
          do
          {
            if ( *v10 != ~LOBYTE(v8->Next) )
              break;
            ++v9;
            v8 = (struct _SLIST_ENTRY *)((char *)v8 + 1);
            ++v10;
          }
          while ( v9 < 0x200 );
          if ( v9 < 0x200 )
          {
            v11 = v20;
            for ( i = 512; i != 0; --i )
            {
              v13 = (char)v7->Next;
              v7 = (struct _SLIST_ENTRY *)((char *)v7 + 1);
              *v11++ = ~v13;
            }
            if ( v20[510] == 85 && v20[511] == 0xAA )
            {
              sub_28005155C(*((PDEVICE_OBJECT *)&v4[1].Next + 1), 4u, v20, 0x200u, 0);
              if ( dword_280074A20 != 0 )
              {
                v14 = qword_280074D48;
                if ( qword_280074D68 != 0 && *(_UNKNOWN **)(qword_280074D48 + 144) != &sub_28005C474 )
                  *(_QWORD *)(qword_280074D48 + 144) = &sub_28005C474;
                v15 = qword_280074D88;
                if ( qword_280074DA8 != 0 && *(_UNKNOWN **)(qword_280074D88 + 144) != &sub_28005CCBC )
                  *(_QWORD *)(qword_280074D88 + 144) = &sub_28005CCBC;
                v16 = qword_280074DD0;
                v17 = (_QWORD *)qword_280074DB8;
                if ( qword_280074DD0 != 0 )
                {
                  if ( *(_UNKNOWN **)(qword_280074DB8 + 232) != &sub_28005D0A0 )
                    *(_QWORD *)(qword_280074DB8 + 232) = &sub_28005D0A0;
                  if ( (_UNKNOWN *)v17[12] != &sub_28005DC1C )
                    v17[12] = &sub_28005DC1C;
                }
                if ( qword_280074D70 != 0 && *(_UNKNOWN **)(v14 + 232) != &sub_28005C7C4 )
                  *(_QWORD *)(v14 + 232) = &sub_28005C7C4;
                if ( qword_280074DB0 != 0 && *(_UNKNOWN **)(v15 + 232) != &sub_28005CF18 )
                  *(_QWORD *)(v15 + 232) = &sub_28005CF18;
                if ( v16 != 0 && (_UNKNOWN *)v17[29] != &sub_28005D0A0 )
                  v17[29] = &sub_28005D0A0;
                if ( qword_280074E08 != 0 && *(_UNKNOWN **)(qword_280074DF0 + 232) != &sub_28005DD58 )
                  *(_QWORD *)(qword_280074DF0 + 232) = &sub_28005DD58;
                if ( qword_280074D78 != 0 && *(_UNKNOWN **)(v14 + 224) != &sub_28005CA40 )
                  *(_QWORD *)(v14 + 224) = &sub_28005CA40;
                if ( qword_280074DD8 != 0 && (_UNKNOWN *)v17[28] != &sub_28005D718 )
                  v17[28] = &sub_28005D718;
                v18 = qword_280074E10;
                if ( qword_280074E30 != 0 )
                  *(_QWORD *)(qword_280074E10 + 144) = &sub_28005E0D8;
                if ( qword_280074E38 != 0 )
                  *(_QWORD *)(v18 + 224) = &sub_28005E294;
              }
              sub_28005155C((PDEVICE_OBJECT)v4[2].Next, 4u, v20, 0x200u, 0);
            }
            v19 = v20;
            do
            {
              *v19 = ~*v19;
              ++v19;
              --v6;
            }
            while ( v6 != 0 );
          }
        }
      }
      ++v2->CurrentLocation;
      ++v2->Tail.Overlay.CurrentStackLocation;
      PoCallDriver(*((PDEVICE_OBJECT *)&v4[1].Next + 1), v2);
      IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)&v4[11], v2, 0x20u);
      break;
    default:
      break;
  }
}


// ===== sub_2800556EC @ 0x2800556ec size=0xf8f =====
__int64 __fastcall sub_2800556EC(__int64 *a1, char a2)
{
  struct _RTL_GENERIC_TABLE *v4; // rbx
  __int64 i; // rsi
  __int64 v6; // rsi
  NTSTATUS v7; // eax
  unsigned int v8; // ebx
  NTSTATUS v10; // eax
  unsigned __int64 v11; // r11
  SIZE_T v12; // rdx
  PVOID PoolWithTag; // rax
  void *v14; // r13
  NTSTATUS v15; // eax
  __int64 v16; // r8
  int v17; // eax
  PVOID *v18; // rbx
  _QWORD *v19; // rax
  __int64 j; // rcx
  unsigned int v21; // eax
  unsigned int v22; // ebp
  _QWORD *v23; // r12
  PVOID ContiguousMemory; // rax
  PVOID v25; // rax
  unsigned int v26; // ebp
  void *v27; // rcx
  unsigned int v28; // eax
  PVOID v29; // rax
  unsigned int v30; // eax
  PVOID v31; // rax
  __int64 v32; // rcx
  unsigned int v33; // r8d
  __int64 v34; // rax
  __int64 v35; // rdx
  __int64 v36; // rt2
  unsigned int v37; // eax
  unsigned int v38; // r8d
  PVOID v39; // rax
  PVOID v40; // rax
  PVOID v41; // rax
  PVOID v42; // rax
  PVOID v43; // rax
  unsigned int v44; // ebp
  __int64 *v45; // rbx
  PVOID v46; // rax
  PVOID v47; // rax
  NTSTATUS v48; // ebx
  PDEVICE_OBJECT DeviceObject[2]; // [rsp+60h] [rbp-2C8h] BYREF
  __int64 v50; // [rsp+70h] [rbp-2B8h] BYREF
  __int64 v51; // [rsp+78h] [rbp-2B0h]
  SIZE_T NumberOfBytes; // [rsp+80h] [rbp-2A8h]
  struct _UNICODE_STRING DestinationString; // [rsp+88h] [rbp-2A0h] BYREF
  __int64 v54; // [rsp+D8h] [rbp-250h] BYREF
  unsigned __int64 v55; // [rsp+E0h] [rbp-248h]
  struct _UNICODE_STRING v56; // [rsp+F8h] [rbp-230h] BYREF
  __int64 v57[18]; // [rsp+120h] [rbp-208h] BYREF
  _QWORD v58[6]; // [rsp+1B0h] [rbp-178h] BYREF
  wchar_t SourceString[64]; // [rsp+1E0h] [rbp-148h] BYREF
  wchar_t v60[64]; // [rsp+260h] [rbp-C8h] BYREF

  v4 = (struct _RTL_GENERIC_TABLE *)(a1 + 68);
  for ( i = 1024; i != 0; --i )
    RtlInitializeGenericTable(v4++, CompareRoutine, AllocateRoutine, FreeRoutine, nullptr);
  *((_DWORD *)a1 + 18) = 1;
  a1[10] = 0;
  *((_DWORD *)a1 + 22) = 0;
  KeInitializeEvent((PRKEVENT)a1 + 4, SynchronizationEvent, 0);
  v6 = *a1;
  if ( sub_2800514A4(*(PDEVICE_OBJECT *)(*a1 + 24), 0x70000u, nullptr, 0, &v50, 0x18u) < 0 )
  {
    v7 = sub_2800514A4(*(PDEVICE_OBJECT *)(v6 + 24), 0x700A0u, nullptr, 0, v58, 0x28u);
    v8 = v7;
    if ( v7 < 0 )
    {
      DbgPrint("diskpt!StorInitializeVolumeContext: FltDeviceIoControl(IOCTL_DISK_GET_DRIVE_GEOMETRY) failed(%x)\n", v7);
      return v8;
    }
    v50 = v58[0];
    v51 = v58[1];
    NumberOfBytes = v58[2];
  }
  if ( HIDWORD(NumberOfBytes) > 0x1000 )
  {
    DbgPrint("diskpt!StorInitializeVolumeContext: BytesPerSector = %d\n", HIDWORD(NumberOfBytes));
    return 3221225485LL;
  }
  if ( sub_2800514A4(*(PDEVICE_OBJECT *)(v6 + 24), 0x74004u, nullptr, 0, &v54, 0x20u) >= 0 )
  {
    v11 = v55;
  }
  else
  {
    v10 = sub_2800514A4(*(PDEVICE_OBJECT *)(v6 + 24), 0x70048u, nullptr, 0, v57, 0x90u);
    if ( v10 >= 0 )
    {
      v11 = v57[2];
    }
    else
    {
      DbgPrint(
        "diskpt!StorInitializeVolumeContext: FltDeviceIoControl(IOCTL_DISK_GET_PARTITION_INFO) failed(%x)\n",
        v10);
      v11 = v50 * HIDWORD(NumberOfBytes) * (unsigned int)NumberOfBytes * (unsigned __int64)HIDWORD(v51);
    }
    v55 = v11;
  }
  v12 = HIDWORD(NumberOfBytes);
  a1[5] = v11;
  PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, v12, 0x74706B64u);
  v14 = PoolWithTag;
  if ( PoolWithTag == nullptr )
  {
    DbgPrint("diskpt!StorInitializeVolumeContext: ExAllocatePoolWithTag failed\n");
    return 3221225626LL;
  }
  v15 = sub_28005155C(*(PDEVICE_OBJECT *)(v6 + 24), 3u, PoolWithTag, HIDWORD(NumberOfBytes), 0);
  v8 = v15;
  if ( v15 < 0 )
  {
    DbgPrint("diskpt!StorInitializeVolumeContext: FltReadWriteSectors failed(%x)\n", (unsigned int)v15);
LABEL_19:
    ExFreePoolWithTag(v14, 0x74706B64u);
    return v8;
  }
  LOBYTE(v16) = a2;
  v17 = sub_280059FE8(a1, v14, v16);
  v8 = v17;
  if ( v17 < 0 )
  {
    DbgPrint("diskpt!StorInitializeVolumeContext: StorFindMapFile failed(%x)\n", (unsigned int)v17);
    goto LABEL_19;
  }
  if ( 4 * (unsigned __int64)*((unsigned int *)a1 + 17) < HIDWORD(NumberOfBytes) )
  {
    DbgPrint("diskpt!StorInitializeVolumeContext: ERROR MapWindowCapacity = %d\n");
LABEL_29:
    v8 = -1073741811;
    goto LABEL_19;
  }
  v18 = (PVOID *)(a1 + 10310);
  *((_BYTE *)a1 + 90672) = 0;
  v19 = a1 + 10310;
  for ( j = 1024; j != 0; --j )
  {
    *(v19 - 1024) = 0;
    *v19++ = 0;
  }
  if ( dword_280074EE8 == 0 )
  {
    v21 = (unsigned int)(*((_DWORD *)a1 + 18571) + 0x7FFFF) >> 19;
    if ( v21 > 0x400 )
    {
      DbgPrint("diskpt!StorInitializeVolumeContext: ERROR (MapTableSize = %d)\n");
      goto LABEL_29;
    }
    *((_BYTE *)a1 + 90672) = 1;
    v22 = 0;
    if ( v21 != 0 )
    {
      v23 = a1 + 10310;
      while ( 1 )
      {
        ContiguousMemory = MmAllocateContiguousMemory(0x80000u, HighestAcceptableAddress);
        *(v23 - 1024) = ContiguousMemory;
        if ( ContiguousMemory == nullptr )
          break;
        v25 = MmAllocateContiguousMemory(0x80000u, HighestAcceptableAddress);
        *v23 = v25;
        if ( v25 == nullptr )
          break;
        ++v22;
        ++v23;
        if ( v22 >= (unsigned int)(*((_DWORD *)a1 + 18571) + 0x7FFFF) >> 19 )
          goto LABEL_37;
      }
      DbgPrint("diskpt!StorInitializeVolumeContext: MmAllocateContiguousMemory(%d) failed\n", v22);
      *((_BYTE *)a1 + 90672) = 0;
    }
LABEL_37:
    if ( *((_BYTE *)a1 + 90672) == 0 )
    {
      v26 = 0;
      if ( ((*((_DWORD *)a1 + 18571) + 0x7FFFF) & 0xFFF80000) != 0 )
      {
        do
        {
          v27 = *(v18 - 1024);
          if ( v27 != nullptr )
          {
            MmFreeContiguousMemory(v27);
            *(v18 - 1024) = nullptr;
          }
          if ( *v18 != nullptr )
          {
            MmFreeContiguousMemory(*v18);
            *v18 = nullptr;
          }
          ++v26;
          ++v18;
        }
        while ( v26 < (unsigned int)(*((_DWORD *)a1 + 18571) + 0x7FFFF) >> 19 );
      }
    }
  }
  v28 = (((unsigned int)(*((unsigned int *)a1 + 18571) / (4 * (unsigned __int64)*((unsigned int *)a1 + 17))) + 1) >> 3)
      + 1;
  *((_DWORD *)a1 + 82) = v28;
  v29 = ExAllocatePoolWithTag(NonPagedPoolCacheAligned, v28, 0x74706B64u);
  a1[40] = (__int64)v29;
  if ( v29 == nullptr )
    goto LABEL_45;
  v30 = (((unsigned int)(*((unsigned int *)a1 + 18571) / (4 * (unsigned __int64)*((unsigned int *)a1 + 17))) + 1) >> 3)
      + 1;
  *((_DWORD *)a1 + 134) = v30;
  v31 = ExAllocatePoolWithTag(NonPagedPoolCacheAligned, v30, 0x74706B64u);
  a1[66] = (__int64)v31;
  if ( v31 == nullptr )
    goto LABEL_45;
  v32 = *((unsigned int *)a1 + 14);
  v33 = a1[5] / v32 + 8;
  v34 = a1[5] + *((unsigned int *)a1 + 16);
  *((_DWORD *)a1 + 22669) = v33;
  v36 = v34 % v32;
  LODWORD(v34) = v34 / v32;
  v35 = v36;
  *((_DWORD *)a1 + 22682) = v34;
  v37 = v34 - 2;
  *((_DWORD *)a1 + 22684) = v37;
  if ( v37 >= 0x10000 )
    *((_DWORD *)a1 + 22683) = v37 - 0x10000;
  else
    *((_DWORD *)a1 + 22683) = 0;
  v38 = v33 >> 3;
  *((_DWORD *)a1 + 22669) = v38 + 1;
  if ( *((_DWORD *)a1 + 22670) != ((v38 + 4096) & 0x3FFFF000) )
    DbgPrint("diskpt!StorInitializeVolumeContext: AllocateBitmapSize doesn't match!\n", v35);
  v39 = ExAllocatePoolWithTag(NonPagedPoolCacheAligned, *((unsigned int *)a1 + 22670), 0x74706B64u);
  a1[11336] = (__int64)v39;
  if ( v39 == nullptr )
    goto LABEL_45;
  v40 = ExAllocatePoolWithTag(NonPagedPoolCacheAligned, *((unsigned int *)a1 + 22670), 0x74706B64u);
  a1[11337] = (__int64)v40;
  if ( v40 == nullptr )
    goto LABEL_45;
  v41 = ExAllocatePoolWithTag(NonPagedPoolCacheAligned, *((unsigned int *)a1 + 22670), 0x74706B64u);
  a1[11338] = (__int64)v41;
  if ( v41 == nullptr )
    goto LABEL_45;
  v42 = ExAllocatePoolWithTag(NonPagedPoolCacheAligned, *((unsigned int *)a1 + 22670), 0x74706B64u);
  a1[11339] = (__int64)v42;
  if ( v42 == nullptr )
    goto LABEL_45;
  v43 = ExAllocatePoolWithTag(NonPagedPoolCacheAligned, *((unsigned int *)a1 + 22670), 0x74706B64u);
  a1[11340] = (__int64)v43;
  if ( v43 == nullptr )
    goto LABEL_45;
  v44 = 0;
  v45 = a1 + 17;
  do
  {
    v46 = ExAllocatePoolWithTag(NonPagedPoolCacheAligned, 4LL * *((unsigned int *)a1 + 17), 0x74706B64u);
    *(v45 - 1) = (__int64)v46;
    if ( v46 == nullptr )
      break;
    *((_DWORD *)v45 + 2) = 0;
    *(_DWORD *)v45 = -1;
    *((_DWORD *)v45 + 1) = -1;
    v47 = ExAllocatePoolWithTag(NonPagedPoolCacheAligned, 4LL * *((unsigned int *)a1 + 17), 0x74706B64u);
    v45[25] = (__int64)v47;
    if ( v47 == nullptr )
      break;
    ++v44;
    *((_DWORD *)v45 + 54) = 0;
    *((_DWORD *)v45 + 52) = -1;
    *((_DWORD *)v45 + 53) = -1;
    v45 += 3;
  }
  while ( v44 < 8 );
  if ( v44 >= 8 )
  {
    memset((void *)a1[40], 0, *((unsigned int *)a1 + 82));
    memset((void *)a1[66], 0, *((unsigned int *)a1 + 134));
    memset((void *)a1[11336], 0, *((unsigned int *)a1 + 22670));
    memset((void *)a1[11337], 0, *((unsigned int *)a1 + 22670));
    memset((void *)a1[11338], 0, *((unsigned int *)a1 + 22670));
    memset((void *)a1[11339], 0, *((unsigned int *)a1 + 22670));
    memset((void *)a1[11340], 0, *((unsigned int *)a1 + 22670));
    swprintf(SourceString, L"\\Device\\DpShadow%d", *(unsigned int *)(v6 + 236));
    RtlInitUnicodeString(&DestinationString, SourceString);
    ExAcquireFastMutex(&stru_280075760);
    v48 = IoCreateDevice(
            DriverObject,
            0x318u,
            &DestinationString,
            *(_DWORD *)(*(_QWORD *)(v6 + 8) + 72LL),
            0x100u,
            0,
            DeviceObject);
    ExReleaseFastMutex(&stru_280075760);
    if ( v48 >= 0 )
    {
      *(_DWORD *)DeviceObject[0]->DeviceExtension = 7680405;
      DeviceObject[0]->Flags &= ~0x80u;
    }
    swprintf(SourceString, L"\\Device\\%s%x", aDpshadow, *(unsigned int *)(v6 + 232));
    RtlInitUnicodeString(&DestinationString, SourceString);
    swprintf(v60, L"\\DosDevices\\%s%x", aDpshadow, *(unsigned int *)(v6 + 232));
    RtlInitUnicodeString(&v56, v60);
    ExAcquireFastMutex(&stru_280075760);
    v8 = IoCreateDevice(
           DriverObject,
           0x318u,
           &DestinationString,
           *(_DWORD *)(*(_QWORD *)(v6 + 8) + 72LL),
           0x100u,
           0,
           DeviceObject);
    ExReleaseFastMutex(&stru_280075760);
    if ( (v8 & 0x80000000) == 0 )
    {
      ExAcquireFastMutex(&stru_280075760);
      return sub_2800B7DE9();
    }
    DbgPrint("diskpt!StorInitializeVolumeContext: IoCreateDevice failed(%x)\n", v8);
  }
  else
  {
LABEL_45:
    DbgPrint("diskpt!StorInitializeVolumeContext: ExAllocatePoolWithTag failed\n");
    v8 = -1073741670;
  }
  ExFreePoolWithTag(v14, 0x74706B64u);
  sub_280056684(a1);
  return v8;
}


// ===== sub_280056684 @ 0x280056684 size=0x453 =====
void __fastcall sub_280056684(__int64 *a1)
{
  __int64 v1; // rsi
  _DWORD *v3; // rax
  unsigned int v4; // ebx
  __int64 v5; // rbp
  PDEVICE_OBJECT i; // rdx
  PVOID DeviceExtension; // r8
  __int64 v8; // rbx
  __int64 v9; // rbx
  PFILE_OBJECT v10; // rcx
  void *v11; // rcx
  void *v12; // rcx
  void *v13; // rcx
  void *v14; // rcx
  void *v15; // rcx
  void *v16; // rcx
  PVOID *v17; // rbx
  __int64 j; // rsi
  void *v19; // rcx
  PVOID *v20; // rbx
  __int64 k; // rsi
  void *v22; // rcx
  __int64 v23; // rbp
  PVOID *v24; // rbx
  __int64 m; // rsi
  void *v26; // rcx
  struct _RTL_GENERIC_TABLE *v27; // rsi
  PVOID *ElementGenericTable; // rbx
  PFILE_OBJECT FileObject; // [rsp+30h] [rbp-158h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+38h] [rbp-150h] BYREF
  struct _UNICODE_STRING ObjectName; // [rsp+48h] [rbp-140h] BYREF
  PDEVICE_OBJECT DeviceObject; // [rsp+58h] [rbp-130h] BYREF
  wchar_t SourceString[64]; // [rsp+60h] [rbp-128h] BYREF
  wchar_t v34[64]; // [rsp+E0h] [rbp-A8h] BYREF

  v1 = *a1;
  if ( *(_DWORD *)(*a1 + 208) == 2 )
  {
    _InterlockedAdd(&dword_280074A20, 0xFFFFFFFF);
    v3 = *(_DWORD **)(v1 + 248);
    if ( v3 != nullptr )
    {
      v4 = 0;
      if ( *v3 != 0 )
      {
        v5 = 0;
        do
        {
          ExAcquireFastMutex(&stru_280075760);
          for ( i = DriverObject->DeviceObject; i != nullptr; i = i->NextDevice )
          {
            if ( i != ::DeviceObject )
            {
              DeviceExtension = i->DeviceExtension;
              if ( *(_DWORD *)DeviceExtension == 7680403
                && *(_DWORD *)(*(_QWORD *)(v1 + 248) + v5 + 8) == *((_DWORD *)DeviceExtension + 58) )
              {
                if ( _InterlockedAdd((volatile signed __int32 *)DeviceExtension + 59, 0xFFFFFFFF) == 0 )
                  *((_BYTE *)DeviceExtension + 752) = 0;
                break;
              }
            }
          }
          ExReleaseFastMutex(&stru_280075760);
          ++v4;
          v5 += 32;
        }
        while ( v4 < **(_DWORD **)(v1 + 248) );
      }
    }
  }
  *(_DWORD *)(*a1 + 208) = 1;
  v8 = *(_QWORD *)(v1 + 16);
  if ( v8 != 0 )
  {
    v9 = *(_QWORD *)(v8 + 64);
    swprintf(SourceString, L"\\DosDevices\\%s%x", aDpshadow, *(unsigned int *)(v1 + 232));
    RtlInitUnicodeString(&DestinationString, SourceString);
    IoDeleteSymbolicLink(&DestinationString);
    IoAcquireRemoveLockEx((PIO_REMOVE_LOCK)(v9 + 176), nullptr, &File, 1u, 0x20u);
    IoReleaseRemoveLockAndWaitEx((PIO_REMOVE_LOCK)(v9 + 176), nullptr, 0x20u);
    ExAcquireFastMutex(&stru_280075760);
    *(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL) = DriverObject->DeviceObject;
    DriverObject->DeviceObject = *(PDEVICE_OBJECT *)(v1 + 16);
    IoDeleteDevice(*(PDEVICE_OBJECT *)(v1 + 16));
    ExReleaseFastMutex(&stru_280075760);
    swprintf(v34, L"\\Device\\DpShadow%d", *(unsigned int *)(v1 + 236));
    RtlInitUnicodeString(&ObjectName, v34);
    if ( IoGetDeviceObjectPointer(&ObjectName, 0x80u, &FileObject, &DeviceObject) >= 0 )
    {
      v10 = FileObject;
      if ( FileObject->DeviceObject->DriverObject == DriverObject )
      {
        ExAcquireFastMutex(&stru_280075760);
        IoDeleteDevice(FileObject->DeviceObject);
        ExReleaseFastMutex(&stru_280075760);
        v10 = FileObject;
      }
      ObfDereferenceObject(v10);
    }
    *(_QWORD *)(v1 + 16) = 0;
    a1[1] = 0;
  }
  v11 = (void *)a1[11336];
  if ( v11 != nullptr )
  {
    ExFreePoolWithTag(v11, 0x74706B64u);
    a1[11336] = 0;
  }
  v12 = (void *)a1[11337];
  if ( v12 != nullptr )
  {
    ExFreePoolWithTag(v12, 0x74706B64u);
    a1[11337] = 0;
  }
  v13 = (void *)a1[11338];
  if ( v13 != nullptr )
  {
    ExFreePoolWithTag(v13, 0x74706B64u);
    a1[11338] = 0;
  }
  v14 = (void *)a1[11339];
  if ( v14 != nullptr )
  {
    ExFreePoolWithTag(v14, 0x74706B64u);
    a1[11339] = 0;
  }
  v15 = (void *)a1[11340];
  if ( v15 != nullptr )
  {
    ExFreePoolWithTag(v15, 0x74706B64u);
    a1[11340] = 0;
  }
  v16 = (void *)a1[40];
  if ( v16 != nullptr )
  {
    ExFreePoolWithTag(v16, 0x74706B64u);
    a1[40] = 0;
  }
  v17 = (PVOID *)(a1 + 16);
  for ( j = 8; j != 0; --j )
  {
    if ( *v17 != nullptr )
    {
      ExFreePoolWithTag(*v17, 0x74706B64u);
      *v17 = nullptr;
    }
    v17 += 3;
  }
  v19 = (void *)a1[66];
  if ( v19 != nullptr )
  {
    ExFreePoolWithTag(v19, 0x74706B64u);
    a1[66] = 0;
  }
  v20 = (PVOID *)(a1 + 42);
  for ( k = 8; k != 0; --k )
  {
    if ( *v20 != nullptr )
    {
      ExFreePoolWithTag(*v20, 0x74706B64u);
      *v20 = nullptr;
    }
    v20 += 3;
  }
  v22 = (void *)a1[9284];
  if ( v22 != nullptr )
  {
    ExFreePoolWithTag(v22, 0x74706B64u);
    a1[9284] = 0;
  }
  v23 = 1024;
  v24 = (PVOID *)(a1 + 10310);
  for ( m = 1024; m != 0; --m )
  {
    v26 = *(v24 - 1024);
    if ( v26 != nullptr )
    {
      MmFreeContiguousMemory(v26);
      *(v24 - 1024) = nullptr;
    }
    if ( *v24 != nullptr )
    {
      MmFreeContiguousMemory(*v24);
      *v24 = nullptr;
    }
    ++v24;
  }
  ExAcquireFastMutex((PFAST_MUTEX)(a1 + 9));
  v27 = (struct _RTL_GENERIC_TABLE *)(a1 + 68);
  do
  {
    while ( RtlIsGenericTableEmpty(v27) == 0 )
    {
      ElementGenericTable = (PVOID *)RtlGetElementGenericTable(v27, 0);
      MmFreeContiguousMemory(ElementGenericTable[1]);
      RtlDeleteElementGenericTable(v27, ElementGenericTable);
      _InterlockedExchangeAdd(&dword_280074EE4, -(*((_DWORD *)a1 + 14) >> 10));
    }
    ++v27;
    --v23;
  }
  while ( v23 != 0 );
  ExReleaseFastMutex((PFAST_MUTEX)(a1 + 9));
}


// ===== sub_280056AE0 @ 0x280056ae0 size=0x50e =====
NTSTATUS __fastcall sub_280056AE0(
        __int64 a1,
        struct _DEVICE_OBJECT *a2,
        __int64 a3,
        __int64 a4,
        unsigned int MaxCount,
        union _LARGE_INTEGER a6)
{
  __int64 v6; // rbp
  PDEVICE_OBJECT v9; // rbx
  _DWORD *DeviceExtension; // rax
  union _LARGE_INTEGER *v11; // r8
  DWORD v12; // r9d
  union _LARGE_INTEGER *v13; // rdx
  union _LARGE_INTEGER v14; // rcx
  __int64 v15; // rcx
  union _LARGE_INTEGER v16; // rax
  __int64 v17; // rax
  __int64 v18; // rax
  __int64 v19; // r10
  union _LARGE_INTEGER v20; // r9
  unsigned __int8 v21; // dl
  DWORD v22; // eax
  NTSTATUS v23; // ebx
  union _LARGE_INTEGER v25; // rax
  LONGLONG v26; // rcx
  bool v27; // cc
  void *v28; // rcx
  unsigned __int8 v29; // dl
  const void *v31; // rdx
  ULONG v32; // ebp
  union _LARGE_INTEGER Timeout; // [rsp+20h] [rbp-58h]
  __int64 v34; // [rsp+30h] [rbp-48h]
  PDEVICE_OBJECT Object; // [rsp+38h] [rbp-40h]
  char *Objecta; // [rsp+38h] [rbp-40h]
  char *Objectb; // [rsp+38h] [rbp-40h]
  unsigned __int8 *v41; // [rsp+98h] [rbp+20h]
  NTSTATUS MaxCounta; // [rsp+A0h] [rbp+28h]
  union _LARGE_INTEGER v43; // [rsp+A8h] [rbp+30h]
  union _LARGE_INTEGER v44; // [rsp+A8h] [rbp+30h]

  v6 = MaxCount;
  v34 = *(_QWORD *)(a1 + 64);
  v41 = *(unsigned __int8 **)(a3 + 184);
  MaxCounta = 0;
  ExAcquireFastMutex(&stru_280075760);
  v9 = DriverObject->DeviceObject;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v9 == nullptr )
      {
        ExReleaseFastMutex(&stru_280075760);
        goto LABEL_34;
      }
      if ( v9 != DeviceObject )
      {
        DeviceExtension = v9->DeviceExtension;
        v43.QuadPart = (LONGLONG)DeviceExtension;
        if ( *DeviceExtension == 7680402 && DeviceExtension[52] == 2 )
          break;
      }
      v9 = v9->NextDevice;
    }
    Object = v9;
    ObfReferenceObject(v9);
    ExReleaseFastMutex(&stru_280075760);
    v11 = *(union _LARGE_INTEGER **)(v43.QuadPart + 248);
    v44.QuadPart = (LONGLONG)v11;
    if ( v11 != nullptr )
    {
      v12 = 0;
      if ( v11->LowPart != 0 )
        break;
    }
LABEL_15:
    ExAcquireFastMutex(&stru_280075760);
    v9 = v9->NextDevice;
    ObfDereferenceObject(Object);
  }
  v13 = v11 + 2;
  while ( 1 )
  {
    if ( v13[-1].LowPart == *(_DWORD *)(v34 + 232) )
    {
      v14 = *v13;
      if ( a6.QuadPart >= v13->QuadPart )
        goto LABEL_13;
      if ( a6.QuadPart + v6 > v14.QuadPart )
      {
        Objecta = (char *)(32LL * v12);
        MaxCounta = sub_280056AE0(a1, a2, a3, a4, *(DWORD *)((char *)&v11[2].LowPart + (_QWORD)Objecta) - a6.LowPart);
        if ( MaxCounta < 0 )
          goto LABEL_18;
        v15 = *(_DWORD *)&Objecta[v44.QuadPart + 16] - a6.LowPart;
        v6 = (unsigned int)(a6.LowPart - *(_DWORD *)&Objecta[v44.QuadPart + 16] + v6);
        a6 = *(union _LARGE_INTEGER *)&Objecta[v44.QuadPart + 16];
        a4 += v15;
        v16 = *(union _LARGE_INTEGER *)&Objecta[v44.QuadPart + 32];
        if ( v6 + a6.QuadPart <= a6.QuadPart + *(_QWORD *)&Objecta[v44.QuadPart + 24] )
        {
          MaxCounta = sub_28005155C(v9, *v41, (void *)a4, v6, v16);
          if ( MaxCounta < 0 )
            goto LABEL_18;
          a4 += v6;
          goto LABEL_26;
        }
        MaxCounta = sub_28005155C(v9, *v41, (void *)a4, *(_DWORD *)&Objecta[v44.QuadPart + 24], v16);
        if ( MaxCounta >= 0 )
        {
          v17 = *(unsigned int *)&Objecta[v44.QuadPart + 24];
          a4 += v17;
          a6.QuadPart += v17;
          LODWORD(v6) = v6 - v17;
          MaxCounta = sub_280056AE0(a1, a2, a3, a4, v6);
          if ( MaxCounta >= 0 )
          {
            v18 = (unsigned int)v6;
            goto LABEL_25;
          }
        }
        goto LABEL_18;
      }
      if ( a6.QuadPart >= v14.QuadPart )
      {
LABEL_13:
        if ( a6.QuadPart < v13[1].QuadPart + v14.QuadPart )
          break;
      }
    }
    ++v12;
    v13 += 4;
    if ( v12 >= v11->LowPart )
      goto LABEL_15;
  }
  v19 = 4LL * v12;
  Objectb = (char *)(v19 * 8);
  v20 = v11[v19 + 2];
  Timeout.QuadPart = a6.QuadPart + v11[v19 + 4].QuadPart - v20.QuadPart;
  v21 = *v41;
  if ( v6 + a6.QuadPart > v20.QuadPart + v11[v19 + 3].QuadPart )
  {
    MaxCounta = sub_28005155C(v9, v21, (void *)a4, v11[v19 + 2].LowPart + v11[v19 + 3].LowPart - a6.LowPart, Timeout);
    if ( MaxCounta >= 0 )
    {
      v22 = *(_DWORD *)&Objectb[v44.QuadPart + 16] - a6.LowPart;
      v6 = (unsigned int)(a6.LowPart
                        - *(_DWORD *)&Objectb[v44.QuadPart + 16]
                        - *(_DWORD *)&Objectb[v44.QuadPart + 24]
                        + v6);
      a6.QuadPart = *(_QWORD *)&Objectb[v44.QuadPart + 16] + *(_QWORD *)&Objectb[v44.QuadPart + 24];
      a4 += *(_DWORD *)&Objectb[v44.QuadPart + 24] + v22;
      MaxCounta = sub_280056AE0(a1, a2, a3, a4, v6);
      if ( MaxCounta >= 0 )
      {
        a4 += v6;
        goto LABEL_26;
      }
    }
  }
  else
  {
    MaxCounta = sub_28005155C(v9, v21, (void *)a4, v6, Timeout);
    if ( MaxCounta >= 0 )
    {
      v18 = v6;
LABEL_25:
      a4 += v18;
LABEL_26:
      LODWORD(v6) = 0;
    }
  }
LABEL_18:
  ObfDereferenceObject(v9);
LABEL_34:
  v23 = MaxCounta;
  if ( MaxCounta < 0 || (_DWORD)v6 == 0 )
    return v23;
  v25.QuadPart = *(unsigned int *)(v34 + 768);
  v26 = (unsigned int)v6 + a6.QuadPart;
  if ( a6.QuadPart < v25.QuadPart )
  {
    if ( *v41 == 3 )
    {
      v27 = v26 <= v25.QuadPart;
      v28 = (void *)a4;
      if ( !v27 )
      {
        memmove((void *)a4, (const void *)(a6.QuadPart + *(_QWORD *)(v34 + 760)), v25.LowPart - a6.LowPart);
        v29 = 3;
        return sub_28005155C(
                 *(PDEVICE_OBJECT *)(v34 + 24),
                 v29,
                 (void *)(a4 + *(unsigned int *)(v34 + 768) - (unsigned __int64)a6.LowPart),
                 a6.LowPart + v6 - *(_DWORD *)(v34 + 768),
                 (union _LARGE_INTEGER)*(unsigned int *)(v34 + 768));
      }
      v31 = (const void *)(a6.QuadPart + *(_QWORD *)(v34 + 760));
    }
    else
    {
      if ( v26 > v25.QuadPart )
      {
        memmove((void *)(a6.QuadPart + *(_QWORD *)(v34 + 760)), (const void *)a4, v25.LowPart - a6.LowPart);
        v29 = 4;
        return sub_28005155C(
                 *(PDEVICE_OBJECT *)(v34 + 24),
                 v29,
                 (void *)(a4 + *(unsigned int *)(v34 + 768) - (unsigned __int64)a6.LowPart),
                 a6.LowPart + v6 - *(_DWORD *)(v34 + 768),
                 (union _LARGE_INTEGER)*(unsigned int *)(v34 + 768));
      }
      v31 = (const void *)a4;
      v28 = (void *)(a6.QuadPart + *(_QWORD *)(v34 + 760));
    }
    memmove(v28, v31, (unsigned int)v6);
    return v23;
  }
  if ( *v41 == 4 && a6.QuadPart == 0 )
  {
    v32 = v6 - 512;
    if ( v32 == 0 )
      return v23;
    return sub_28005155C(a2, 4u, (void *)(a4 + 512), v32, (union _LARGE_INTEGER)512LL);
  }
  return sub_28005155C(a2, *v41, (void *)a4, v6, a6);
}


// ===== sub_280056FF4 @ 0x280056ff4 size=0x36e =====
__int64 __fastcall sub_280056FF4(struct _SLIST_ENTRY *a1, IRP *a2)
{
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  struct _SLIST_ENTRY *Next; // r15
  unsigned int *v5; // r8
  LARGE_INTEGER ByteOffset; // rcx
  LONGLONG v8; // rbp
  __int64 v9; // rdx
  __int64 v10; // r9
  __int64 v11; // r13
  unsigned int v12; // ebx
  PMDL MdlAddress; // rcx
  char *MappedSystemVa; // r14
  PSLIST_ENTRY v15; // rbx
  LONGLONG v16; // r12
  int v17; // eax
  int v18; // r13d
  char *v19; // r14
  unsigned int v20; // edx
  struct _SLIST_ENTRY *v21; // rcx
  int v22; // eax
  int v23; // eax
  int v25; // eax
  __int64 v26; // [rsp+30h] [rbp-58h]
  __int64 v27; // [rsp+38h] [rbp-50h]
  unsigned int MaxCount; // [rsp+90h] [rbp+8h]
  ULONG Length; // [rsp+98h] [rbp+10h]
  LARGE_INTEGER v30; // [rsp+A0h] [rbp+18h]
  __int64 v31; // [rsp+A8h] [rbp+20h]

  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  Next = a1[4].Next;
  v5 = (unsigned int *)Next[15].Next;
  ByteOffset = CurrentStackLocation->Parameters.Read.ByteOffset;
  Length = CurrentStackLocation->Parameters.Read.Length;
  v8 = ByteOffset.QuadPart + Length;
  v9 = v5[14];
  v30 = ByteOffset;
  MaxCount = v5[14];
  if ( LODWORD(Next[13].Next) != 2 )
  {
    a2->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
    goto LABEL_37;
  }
  v10 = v5[16];
  v11 = v5[14];
  v26 = v10;
  v31 = (v10 + ByteOffset.QuadPart) / v9;
  v27 = (v9 + v10 + v8 - 1) / v11;
  if ( (unsigned int)v27 > 8 * v5[22669] )
  {
    v12 = -1073741803;
LABEL_5:
    a2->IoStatus.Status = v12;
    a2->IoStatus.Information = 0;
    IofCompleteRequest(a2, 1);
    goto LABEL_38;
  }
  MdlAddress = a2->MdlAddress;
  if ( (MdlAddress->MdlFlags & 5) != 0 )
    MappedSystemVa = (char *)MdlAddress->MappedSystemVa;
  else
    MappedSystemVa = (char *)MmMapLockedPagesSpecifyCache(MdlAddress, 0, MmCached, nullptr, 0, 0x10u);
  if ( MappedSystemVa == nullptr
    || (++dword_280074694, (v15 = ExpInterlockedPopEntrySList(&SListHead)) == nullptr)
    && (++dword_280074698,
        (v15 = (PSLIST_ENTRY)qword_2800746B0(
                               (unsigned int)dword_2800746A4,
                               (unsigned int)dword_2800746AC,
                               (unsigned int)dword_2800746A8)) == nullptr) )
  {
    v12 = -1073741670;
    goto LABEL_5;
  }
  a2->Tail.Overlay.CurrentStackLocation->Control |= 1u;
  LODWORD(v15[2].Next) = -1;
  v15->Next = a1;
  LODWORD(v15[1].Next) = Length + 1;
  v16 = v11 * (v31 + 1) - v26;
  *((_QWORD *)&v15->Next + 1) = a2;
  HIDWORD(v15[1].Next) = 0;
  if ( v8 < v16 )
    v16 = v8;
  *((_DWORD *)&v15[1].Next + 2) = 0;
  *((_DWORD *)&v15[3].Next + 2) = 0;
  *((_DWORD *)&v15[3].Next + 3) = 0;
  v15[4].Next = nullptr;
  v17 = sub_280057868((__int64)v15, MappedSystemVa, (unsigned int)(v16 - v30.LowPart));
  v18 = v17;
  if ( v17 < 0 )
  {
    *((_DWORD *)&v15[1].Next + 2) = v17;
    sub_280058764(v15);
  }
  v19 = &MappedSystemVa[v16 - v30.QuadPart];
  if ( v16 >= v8 )
    goto LABEL_30;
  v20 = MaxCount;
  while ( 1 )
  {
    v21 = v15;
    if ( v8 - v16 < v20 )
      break;
    if ( v18 < 0 )
      goto LABEL_23;
    v22 = sub_280057868((__int64)v15, v19, v20);
    v18 = v22;
    if ( v22 < 0 )
    {
      *((_DWORD *)&v15[1].Next + 2) = v22;
      v21 = v15;
LABEL_23:
      sub_280058764(v21);
    }
    v20 = MaxCount;
    v16 += MaxCount;
    v19 += MaxCount;
    if ( v16 >= v8 )
      goto LABEL_30;
  }
  if ( v18 < 0 )
    goto LABEL_29;
  v23 = sub_280057868((__int64)v15, v19, (unsigned int)(v8 - v16));
  v18 = v23;
  if ( v23 < 0 )
  {
    *((_DWORD *)&v15[1].Next + 2) = v23;
    v21 = v15;
LABEL_29:
    sub_280058764(v21);
LABEL_30:
    if ( v18 < 0 )
    {
LABEL_42:
      sub_280058764(v15);
      return 259;
    }
  }
  if ( *((_DWORD *)&v15[3].Next + 3) != (_DWORD)v27 - (_DWORD)v31 || LODWORD(v15[2].Next) != (_DWORD)v31 )
  {
    if ( *((_DWORD *)&v15[3].Next + 3) != 0 )
    {
      v25 = sub_280058838(
              *((PDEVICE_OBJECT *)&Next[1].Next + 1),
              *((PVOID *)&v15[2].Next + 1),
              *((_DWORD *)&v15[3].Next + 2),
              (__int64)v15);
      if ( v25 < 0 )
      {
        *((_DWORD *)&v15[1].Next + 2) = v25;
        sub_280058764(v15);
      }
    }
    goto LABEL_42;
  }
  ++dword_28007469C;
  if ( ExQueryDepthSList(&SListHead) < (unsigned __int16)word_280074690 )
  {
    ExpInterlockedPushEntrySList(&SListHead, v15);
  }
  else
  {
    ++dword_2800746A0;
    qword_2800746B8(v15);
  }
  ++a2->Tail.Overlay.CurrentStackLocation;
LABEL_37:
  ++a2->CurrentLocation;
  v12 = IofCallDriver(*((PDEVICE_OBJECT *)&Next[1].Next + 1), a2);
LABEL_38:
  IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)&Next[11], a2, 0x20u);
  return v12;
}


// ===== sub_280057368 @ 0x280057368 size=0x4f7 =====
__int64 __fastcall sub_280057368(struct _SLIST_ENTRY *a1, IRP *a2)
{
  struct _SLIST_ENTRY *Next; // r15
  struct _IO_STACK_LOCATION *CurrentStackLocation; // r8
  LARGE_INTEGER ByteOffset; // rax
  struct _SLIST_ENTRY *v6; // rbp
  int v7; // r9d
  __int64 v8; // rdx
  SIZE_T Length; // r12
  signed __int64 v10; // r13
  unsigned int v11; // edi
  PMDL MdlAddress; // rcx
  char *MappedSystemVa; // r14
  PSLIST_ENTRY v14; // rdi
  struct _SLIST_ENTRY *PoolWithTag; // rax
  int v16; // eax
  __int64 v17; // r12
  int v18; // eax
  int v19; // ebp
  __int64 v20; // rdx
  char *i; // r14
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v27; // eax
  LARGE_INTEGER v28; // [rsp+30h] [rbp-68h]
  __int64 v29; // [rsp+38h] [rbp-60h]
  __int64 Next_low; // [rsp+40h] [rbp-58h]
  __int64 v31; // [rsp+48h] [rbp-50h]
  unsigned int v33; // [rsp+A8h] [rbp+10h]
  __int64 v34; // [rsp+B8h] [rbp+20h]

  Next = a1[4].Next;
  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  ByteOffset = CurrentStackLocation->Parameters.Read.ByteOffset;
  v6 = Next[15].Next;
  v7 = (int)Next[13].Next;
  v8 = *((unsigned int *)&v6[3].Next + 2);
  v28 = ByteOffset;
  v33 = *((_DWORD *)&v6[3].Next + 2);
  Length = CurrentStackLocation->Parameters.Read.Length;
  v10 = Length + ByteOffset.QuadPart;
  if ( v7 != 2 && v7 != 3 )
    goto LABEL_3;
  v34 = *((unsigned int *)&v6[3].Next + 2);
  Next_low = LODWORD(v6[4].Next);
  v29 = (Next_low + ByteOffset.QuadPart) / v8;
  v31 = (v8 + Next_low + v10 - 1) / v8;
  if ( (unsigned int)v31 > 8 * HIDWORD(v6[5667].Next) )
  {
    v11 = -1073741803;
LABEL_6:
    a2->IoStatus.Status = v11;
    a2->IoStatus.Information = 0;
    IofCompleteRequest(a2, 1);
    goto LABEL_68;
  }
  if ( LODWORD(v6[2].Next) != 0 )
  {
    if ( v7 == 3 )
    {
      a2->IoStatus.Status = 0;
      a2->IoStatus.Information = Length;
      IofCompleteRequest(a2, 1);
      v11 = 0;
      goto LABEL_68;
    }
LABEL_3:
    a2->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
    goto LABEL_67;
  }
  MdlAddress = a2->MdlAddress;
  if ( (MdlAddress->MdlFlags & 5) != 0 )
    MappedSystemVa = (char *)MdlAddress->MappedSystemVa;
  else
    MappedSystemVa = (char *)MmMapLockedPagesSpecifyCache(MdlAddress, 0, MmCached, nullptr, 0, 0x10u);
  if ( MappedSystemVa == nullptr
    || (++dword_280074694, (v14 = ExpInterlockedPopEntrySList(&SListHead)) == nullptr)
    && (++dword_280074698,
        (v14 = (PSLIST_ENTRY)qword_2800746B0(
                               (unsigned int)dword_2800746A4,
                               (unsigned int)dword_2800746AC,
                               (unsigned int)dword_2800746A8)) == nullptr) )
  {
LABEL_14:
    v11 = -1073741670;
    goto LABEL_6;
  }
  a2->Tail.Overlay.CurrentStackLocation->Control |= 1u;
  LODWORD(v14[2].Next) = -1;
  v14->Next = a1;
  *((_QWORD *)&v14->Next + 1) = a2;
  HIDWORD(v14[1].Next) = 0;
  *((_DWORD *)&v14[1].Next + 2) = 0;
  *((_DWORD *)&v14[3].Next + 2) = 0;
  *((_DWORD *)&v14[3].Next + 3) = 0;
  v14[4].Next = nullptr;
  LODWORD(v14[1].Next) = Length + 1;
  if ( *((_BYTE *)&v6[5672].Next + 8) != 0 && LODWORD(Next[13].Next) == 2 )
  {
    PoolWithTag = (struct _SLIST_ENTRY *)ExAllocatePoolWithTag(NonPagedPool, Length, 0x63437064u);
    v14[4].Next = PoolWithTag;
    if ( PoolWithTag == nullptr )
    {
      ++dword_28007469C;
      if ( ExQueryDepthSList(&SListHead) < (unsigned __int16)word_280074690 )
      {
        ExpInterlockedPushEntrySList(&SListHead, v14);
      }
      else
      {
        ++dword_2800746A0;
        qword_2800746B8(v14);
      }
      goto LABEL_14;
    }
    memmove(PoolWithTag, MappedSystemVa, Length);
    sub_28005E524(Next[15].Next, v14[4].Next, (unsigned int)Length);
    MappedSystemVa = (char *)v14[4].Next;
  }
  v16 = (int)v14->Next[4].Next[13].Next;
  v17 = v34 * (v29 + 1) - Next_low;
  if ( v10 < v17 )
    v17 = v10;
  if ( v16 == 2 )
  {
    v18 = sub_280057AB0((__int64)v14);
  }
  else
  {
    if ( v16 != 3 )
    {
      v19 = -1073741823;
      goto LABEL_32;
    }
    v18 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD))sub_280058114)(
            v14,
            MappedSystemVa,
            (unsigned int)(v17 - v28.LowPart),
            (LARGE_INTEGER)v28.QuadPart);
  }
  v19 = v18;
LABEL_32:
  if ( v19 < 0 )
  {
    *((_DWORD *)&v14[1].Next + 2) = v19;
    sub_280058764(v14);
  }
  v20 = v34;
  for ( i = &MappedSystemVa[v17 - v28.QuadPart]; ; i += v20 )
  {
    if ( v17 >= v10 )
      goto LABEL_59;
    if ( v10 - v17 < v20 )
      break;
    if ( v19 >= 0 )
    {
      v22 = (int)v14->Next[4].Next[13].Next;
      if ( v22 == 2 )
      {
        v23 = sub_280057AB0((__int64)v14);
      }
      else
      {
        if ( v22 != 3 )
        {
          v19 = -1073741823;
          goto LABEL_43;
        }
        v23 = sub_280058114(v14, i, v33, v17);
      }
      v20 = v34;
      v19 = v23;
LABEL_43:
      if ( v19 >= 0 )
        goto LABEL_46;
      *((_DWORD *)&v14[1].Next + 2) = v19;
    }
    sub_280058764(v14);
    v20 = v34;
LABEL_46:
    v17 += v20;
  }
  if ( v19 < 0 )
  {
LABEL_58:
    sub_280058764(v14);
LABEL_59:
    if ( v19 >= 0 )
      goto LABEL_60;
LABEL_72:
    sub_280058764(v14);
    return 259;
  }
  v24 = (int)v14->Next[4].Next[13].Next;
  if ( v24 == 2 )
  {
    v25 = sub_280057AB0((__int64)v14);
    goto LABEL_52;
  }
  if ( v24 == 3 )
  {
    v25 = sub_280058114(v14, i, (unsigned int)(v10 - v17), v17);
LABEL_52:
    v19 = v25;
  }
  else
  {
    v19 = -1073741823;
  }
  if ( v19 < 0 )
  {
    *((_DWORD *)&v14[1].Next + 2) = v19;
    goto LABEL_58;
  }
LABEL_60:
  if ( LODWORD(Next[13].Next) != 3
    || *((_DWORD *)&v14[3].Next + 3) != (_DWORD)v31 - (_DWORD)v29
    || LODWORD(v14[2].Next) != (_DWORD)v29 )
  {
    if ( *((_DWORD *)&v14[3].Next + 3) != 0 )
    {
      v27 = sub_280058838(
              *((PDEVICE_OBJECT *)&Next[1].Next + 1),
              *((PVOID *)&v14[2].Next + 1),
              *((_DWORD *)&v14[3].Next + 2),
              (__int64)v14);
      if ( v27 < 0 )
      {
        *((_DWORD *)&v14[1].Next + 2) = v27;
        sub_280058764(v14);
      }
    }
    goto LABEL_72;
  }
  ++dword_28007469C;
  if ( ExQueryDepthSList(&SListHead) < (unsigned __int16)word_280074690 )
  {
    ExpInterlockedPushEntrySList(&SListHead, v14);
  }
  else
  {
    ++dword_2800746A0;
    qword_2800746B8(v14);
  }
  ++a2->Tail.Overlay.CurrentStackLocation;
LABEL_67:
  ++a2->CurrentLocation;
  v11 = IofCallDriver(*((PDEVICE_OBJECT *)&Next[1].Next + 1), a2);
LABEL_68:
  IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)&Next[11], a2, 0x20u);
  return v11;
}


// ===== sub_280057868 @ 0x280057868 size=0x242 =====
__int64 __fastcall sub_280057868(__int64 a1, void *Dst, size_t MaxCount, __int64 a4)
{
  __int64 v6; // rax
  size_t v7; // rsi
  __int64 v9; // rcx
  _QWORD *v10; // r14
  struct _FAST_MUTEX *v11; // r15
  int v12; // ebx
  __int64 v13; // rbp
  int v14; // ebx
  __int64 result; // rax
  int v16; // edx
  __int64 v17; // [rsp+30h] [rbp-58h]
  __int64 v18; // [rsp+38h] [rbp-50h]
  int *v19; // [rsp+40h] [rbp-48h] BYREF
  __int64 v20; // [rsp+48h] [rbp-40h]
  unsigned int v21; // [rsp+90h] [rbp+8h]
  int Buffer; // [rsp+A8h] [rbp+20h] BYREF

  v6 = *(_QWORD *)(*(_QWORD *)a1 + 64LL);
  v7 = (unsigned int)MaxCount;
  v9 = *(_QWORD *)(v6 + 240);
  v18 = v6;
  v10 = nullptr;
  v11 = (struct _FAST_MUTEX *)(v9 + 72);
  v21 = *(_DWORD *)(v9 + 56);
  v20 = *(unsigned int *)(v9 + 64);
  v17 = v9;
  v12 = -1;
  v13 = (v20 + a4) / v21;
  ExAcquireFastMutex((PFAST_MUTEX)(v9 + 72));
  if ( (*(_BYTE *)(((unsigned __int64)(unsigned int)v13 >> 3) + *(_QWORD *)(v17 + 90696))
      & (unsigned __int8)(1 << (v13 & 7))) != 0 )
  {
    Buffer = v13;
    v10 = RtlLookupElementGenericTable((PRTL_GENERIC_TABLE)(v17 + 72 * (v13 & 0x3FF) + 544), &Buffer);
    if ( v10 == nullptr )
    {
      v14 = sub_28005AA20(&v19, v17, 0, (unsigned int)v13);
      if ( v14 < 0 )
      {
        ExReleaseFastMutex(v11);
        return (unsigned int)v14;
      }
      v12 = *v19;
    }
  }
  ExReleaseFastMutex(v11);
  if ( v10 != nullptr )
  {
    if ( *(_DWORD *)(a1 + 32) != -1 )
    {
      result = sub_280058838(*(PDEVICE_OBJECT *)(v18 + 24), *(PVOID *)(a1 + 40), *(_DWORD *)(a1 + 56), a1);
      if ( (int)result < 0 )
        return result;
      *(_DWORD *)(a1 + 60) = 0;
      *(_DWORD *)(a1 + 32) = -1;
    }
    memmove(Dst, (const void *)(v10[1] + (unsigned int)v20 + (_DWORD)a4 - v21 * (_DWORD)v13), v7);
    if ( *(_BYTE *)(v17 + 90760) != 0 )
      sub_28005E600(*(_QWORD *)(v18 + 240), Dst, (unsigned int)v7);
    sub_280058764((PSLIST_ENTRY)a1);
  }
  else
  {
    v16 = *(_DWORD *)(a1 + 32);
    if ( v12 == -1 )
      v12 = v13;
    if ( v16 != -1 && v12 != v16 + *(_DWORD *)(a1 + 60) )
    {
      result = sub_280058838(*(PDEVICE_OBJECT *)(v18 + 24), *(PVOID *)(a1 + 40), *(_DWORD *)(a1 + 56), a1);
      if ( (int)result < 0 )
        return result;
      *(_DWORD *)(a1 + 60) = 0;
      *(_DWORD *)(a1 + 32) = -1;
    }
    if ( *(_DWORD *)(a1 + 32) == -1 )
    {
      *(_DWORD *)(a1 + 28) = v13;
      *(_DWORD *)(a1 + 32) = v12;
      *(_QWORD *)(a1 + 40) = Dst;
      *(_QWORD *)(a1 + 48) = a4;
      *(_DWORD *)(a1 + 56) = v7;
      *(_DWORD *)(a1 + 60) = 1;
    }
    else
    {
      *(_DWORD *)(a1 + 56) += v7;
      ++*(_DWORD *)(a1 + 60);
    }
  }
  return 0;
}


// ===== sub_280057AB0 @ 0x280057ab0 size=0x65d =====
__int64 __fastcall sub_280057AB0(__int64 a1, const void *a2, unsigned int a3, __int64 a4)
{
  __int64 v5; // r13
  __int64 v6; // rsi
  signed __int64 v7; // r14
  size_t v8; // r12
  unsigned int v9; // ebx
  __int64 v10; // r15
  __int64 v11; // rax
  int v12; // ebx
  PVOID ContiguousMemory; // rsi
  unsigned int v14; // eax
  char v15; // r8
  unsigned __int64 v16; // rcx
  int v17; // eax
  __int64 v18; // r8
  unsigned __int64 v19; // rsi
  unsigned __int8 v20; // bp
  char v21; // dl
  unsigned int v22; // r14d
  unsigned int v23; // ebp
  unsigned int v24; // eax
  char *PoolWithTagPriority; // rsi
  __int64 Timeout; // rbp
  ULONG v27; // r9d
  int v28; // r14d
  __int64 v29; // rcx
  struct _DEVICE_OBJECT *v30; // rcx
  NTSTATUS v31; // r14d
  ULONG v32; // r9d
  NTSTATUS v33; // ebp
  __int64 result; // rax
  int v35; // edx
  __int64 v36; // [rsp+30h] [rbp-A8h]
  void *Dst; // [rsp+38h] [rbp-A0h]
  signed __int64 NumberOfBytes; // [rsp+40h] [rbp-98h]
  __int64 v39; // [rsp+48h] [rbp-90h]
  _QWORD *v40; // [rsp+50h] [rbp-88h]
  unsigned int *v41; // [rsp+58h] [rbp-80h] BYREF
  int Buffer; // [rsp+60h] [rbp-78h] BYREF
  int v43; // [rsp+68h] [rbp-70h]
  int v44; // [rsp+6Ch] [rbp-6Ch]
  PFAST_MUTEX FastMutex; // [rsp+70h] [rbp-68h]
  _DWORD *v46; // [rsp+78h] [rbp-60h] BYREF
  __int64 v47; // [rsp+80h] [rbp-58h]
  __int64 v48; // [rsp+88h] [rbp-50h]
  unsigned __int64 v49; // [rsp+90h] [rbp-48h]
  char *v50; // [rsp+98h] [rbp-40h]
  ULONG v51; // [rsp+E0h] [rbp+8h]

  v40 = nullptr;
  Dst = nullptr;
  v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 64LL) + 240LL);
  v36 = *(_QWORD *)(*(_QWORD *)a1 + 64LL);
  v6 = a4;
  v7 = *(unsigned int *)(v5 + 56);
  v8 = a3;
  v39 = *(unsigned int *)(v5 + 64);
  v51 = *(_DWORD *)(v5 + 56);
  v48 = a4 + v39;
  NumberOfBytes = v7;
  v9 = -1;
  v10 = (a4 + v39) / v7;
  FastMutex = (PFAST_MUTEX)(v5 + 72);
  ExAcquireFastMutex((PFAST_MUTEX)(v5 + 72));
  v43 = v10 & 7;
  v11 = *(_QWORD *)(v5 + 90696);
  v49 = (unsigned __int64)(unsigned int)v10 >> 3;
  v47 = (unsigned int)v10;
  v44 = 1 << v43;
  if ( ((unsigned __int8)(1 << v43) & *(_BYTE *)(v49 + v11)) != 0 )
  {
    Buffer = v10;
    v40 = RtlLookupElementGenericTable((PRTL_GENERIC_TABLE)(v5 + 72 * (v10 & 0x3FF) + 544), &Buffer);
    if ( v40 != nullptr )
      goto LABEL_5;
    v12 = sub_28005AA20(&v41, v5, 0, (unsigned int)v10);
    if ( v12 < 0 )
    {
LABEL_47:
      ExReleaseFastMutex(FastMutex);
      return (unsigned int)v12;
    }
    v9 = *v41;
    if ( *v41 != -1 )
    {
LABEL_5:
      ExReleaseFastMutex(FastMutex);
LABEL_57:
      if ( *(_QWORD *)(a1 + 8) == 0 )
        return 0;
      if ( v40 == nullptr )
      {
        v35 = *(_DWORD *)(a1 + 32);
        if ( v35 != -1 && v9 != v35 + *(_DWORD *)(a1 + 60) )
        {
          result = sub_280058838(*(PDEVICE_OBJECT *)(v36 + 24), *(PVOID *)(a1 + 40), *(_DWORD *)(a1 + 56), a1);
          if ( (int)result < 0 )
            return result;
          *(_DWORD *)(a1 + 32) = -1;
        }
        if ( *(_DWORD *)(a1 + 32) == -1 )
        {
          *(_DWORD *)(a1 + 28) = v10;
          *(_DWORD *)(a1 + 32) = v9;
          *(_QWORD *)(a1 + 48) = v6;
          *(_DWORD *)(a1 + 56) = v8;
          *(_DWORD *)(a1 + 60) = 1;
          *(_QWORD *)(a1 + 40) = a2;
        }
        else
        {
          *(_DWORD *)(a1 + 56) += v8;
          ++*(_DWORD *)(a1 + 60);
        }
        return 0;
      }
      if ( *(_DWORD *)(a1 + 32) != -1 )
      {
        result = sub_280058838(*(PDEVICE_OBJECT *)(v36 + 24), *(PVOID *)(a1 + 40), *(_DWORD *)(a1 + 56), a1);
        if ( (int)result < 0 )
          return result;
        *(_DWORD *)(a1 + 60) = 0;
        *(_DWORD *)(a1 + 32) = -1;
      }
      memmove((void *)(v40[1] + (unsigned int)(v39 + v6 - v7 * v10)), a2, v8);
LABEL_55:
      sub_280058764((PSLIST_ENTRY)a1);
      return 0;
    }
  }
  if ( dword_280074EE4 + ((unsigned int)v7 >> 10) <= dword_280074EE0 && *(_QWORD *)(a1 + 8) != 0 )
  {
    ContiguousMemory = MmAllocateContiguousMemory(v7, HighestAcceptableAddress);
    Dst = ContiguousMemory;
  }
  else
  {
LABEL_9:
    ContiguousMemory = nullptr;
  }
  while ( ContiguousMemory != nullptr )
  {
    v40 = (_QWORD *)sub_28005A9C0(v5, (unsigned int)v10, ContiguousMemory);
    if ( v40 != nullptr )
      goto LABEL_15;
    MmFreeContiguousMemory(ContiguousMemory);
    ContiguousMemory = nullptr;
    Dst = nullptr;
  }
  v14 = sub_280059EB0(v5);
  v9 = v14;
  if ( v14 == -1 )
  {
    v12 = -1073741697;
    goto LABEL_47;
  }
  v15 = 1 << (v14 & 7);
  v16 = (unsigned __int64)v14 >> 3;
  *(_BYTE *)(v16 + *(_QWORD *)(v5 + 90704)) |= v15;
  *(_BYTE *)(*(_QWORD *)(v5 + 90720) + v16) |= v15;
  *(_BYTE *)(*(_QWORD *)(v5 + 90712) + v16) |= v15;
  v17 = sub_28005AA20(&v41, v5, 0, (unsigned int)v10);
  if ( v17 < 0 || (LOBYTE(v18) = 1, *v41 = v9, (v17 = sub_28005AA20(&v46, v5, v18, v9)) < 0) )
  {
    v12 = v17;
    goto LABEL_47;
  }
  *v46 = v10;
LABEL_15:
  v19 = v49;
  v20 = v44;
  v21 = 1 << v43;
  *(_BYTE *)(v49 + *(_QWORD *)(v5 + 90704)) |= 1 << v43;
  *(_BYTE *)(v19 + *(_QWORD *)(v5 + 90696)) |= v21;
  if ( (v20 & *(_BYTE *)(v19 + *(_QWORD *)(v5 + 90720))) == 0 )
    *(_BYTE *)(v19 + *(_QWORD *)(v5 + 90712)) &= ~v21;
  ExReleaseFastMutex((PFAST_MUTEX)(v5 + 72));
  if ( (v20 & *(_BYTE *)(v19 + *(_QWORD *)(v5 + 90688))) == 0 || (_DWORD)v8 == (_DWORD)v7 && *(_QWORD *)(a1 + 8) != 0 )
  {
    v6 = a4;
    goto LABEL_57;
  }
  v22 = 0;
  v23 = 0;
  while ( 1 )
  {
    PoolWithTagPriority = (char *)ExAllocatePoolWithTagPriority(
                                    NonPagedPool,
                                    NumberOfBytes,
                                    0x74706B64u,
                                    HighPoolPriority);
    if ( PoolWithTagPriority != nullptr )
      break;
    v24 = v23++;
    if ( v24 >= 0xA )
      return 3221225626LL;
    KeDelayExecutionThread(0, 0, &Interval);
  }
  Timeout = NumberOfBytes * v47 - v39;
  v27 = v51;
  if ( Timeout < 0 )
  {
    v28 = Timeout;
    Timeout = 0;
    v22 = -v28;
    v27 = v51 - v22;
    goto LABEL_33;
  }
  if ( *(_QWORD *)(a1 + 8) != 0 )
  {
    v29 = v51 - 1;
    if ( (v29 & v48) != 0 )
    {
      if ( ((a4 + v39 + v8) & v29) != 0 )
        goto LABEL_33;
    }
    else
    {
      v22 = v8;
      Timeout += v8;
    }
    v27 = v51 - v8;
  }
LABEL_33:
  v30 = *(struct _DEVICE_OBJECT **)(v36 + 24);
  v50 = &PoolWithTagPriority[v22];
  v31 = sub_28005155C(v30, 3u, v50, v27, (union _LARGE_INTEGER)Timeout);
  if ( v31 < 0 )
  {
    if ( *(_QWORD *)(v5 + 40) - Timeout < NumberOfBytes )
    {
      v32 = *(_DWORD *)(v5 + 40) - Timeout;
      if ( v32 == 0 )
        goto LABEL_38;
      v31 = sub_28005155C(*(PDEVICE_OBJECT *)(v36 + 24), 3u, v50, v32, (union _LARGE_INTEGER)Timeout);
    }
    if ( v31 < 0 )
    {
      ExFreePoolWithTag(PoolWithTagPriority, 0x74706B64u);
      return (unsigned int)v31;
    }
  }
LABEL_38:
  LODWORD(v7) = v51;
  if ( *(_BYTE *)(v5 + 90760) != 0 )
    sub_28005E524(*(_QWORD *)(v36 + 240), PoolWithTagPriority, v51);
  memmove(&PoolWithTagPriority[(v51 - 1) & ((_DWORD)a4 + (_DWORD)v39)], a2, v8);
  if ( Dst != nullptr )
  {
    memmove(Dst, PoolWithTagPriority, NumberOfBytes);
LABEL_52:
    ExFreePoolWithTag(PoolWithTagPriority, 0x74706B64u);
    if ( *(_DWORD *)(a1 + 32) != -1 )
    {
      result = sub_280058838(*(PDEVICE_OBJECT *)(v36 + 24), *(PVOID *)(a1 + 40), *(_DWORD *)(a1 + 56), a1);
      if ( (int)result < 0 )
        return result;
      *(_DWORD *)(a1 + 60) = 0;
      *(_DWORD *)(a1 + 32) = -1;
    }
    goto LABEL_55;
  }
  v33 = sub_28005155C(
          *(PDEVICE_OBJECT *)(v36 + 24),
          4u,
          PoolWithTagPriority,
          v51,
          (union _LARGE_INTEGER)(v51 * (unsigned __int64)v9 - v39));
  if ( v33 >= 0 )
    goto LABEL_52;
  ExFreePoolWithTag(PoolWithTagPriority, 0x74706B64u);
  if ( v33 == -1073741761 || v33 == -1073741762 )
  {
    ExAcquireFastMutex((PFAST_MUTEX)(v5 + 72));
    goto LABEL_9;
  }
  return (unsigned int)v33;
}


// ===== sub_280058114 @ 0x280058114 size=0x648 =====
__int64 __fastcall sub_280058114(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  char *ContiguousMemory; // r15
  char v7; // bl
  __int64 v8; // rbp
  __int64 PoolWithTagPriority; // r12
  char v10; // cl
  __int64 v11; // rax
  unsigned __int64 v12; // r14
  __int64 v13; // r8
  __int64 v14; // rdx
  unsigned int v16; // ebx
  unsigned int v17; // edi
  unsigned __int64 v18; // rcx
  int v19; // edi
  char v20; // dl
  int v21; // eax
  __int64 v22; // r8
  __int64 v23; // r8
  char v24; // dl
  unsigned int v25; // r14d
  SIZE_T i; // rdx
  unsigned int v27; // eax
  ULONG v28; // r14d
  __int64 Timeout; // r15
  NTSTATUS v30; // eax
  NTSTATUS v31; // r14d
  unsigned int v32; // [rsp+30h] [rbp-D8h]
  unsigned int v33; // [rsp+34h] [rbp-D4h]
  char v34; // [rsp+38h] [rbp-D0h]
  __int64 v35; // [rsp+40h] [rbp-C8h]
  char *v36; // [rsp+48h] [rbp-C0h]
  unsigned __int8 v37; // [rsp+50h] [rbp-B8h]
  __int64 v38; // [rsp+58h] [rbp-B0h]
  int v39; // [rsp+60h] [rbp-A8h]
  unsigned int *v40; // [rsp+68h] [rbp-A0h] BYREF
  unsigned int *v41; // [rsp+70h] [rbp-98h] BYREF
  unsigned int *v42; // [rsp+78h] [rbp-90h] BYREF
  unsigned int *v43; // [rsp+80h] [rbp-88h] BYREF
  _DWORD *v44; // [rsp+88h] [rbp-80h] BYREF
  __int64 v45; // [rsp+90h] [rbp-78h]
  _DWORD *v46; // [rsp+98h] [rbp-70h] BYREF
  unsigned __int64 v47; // [rsp+A0h] [rbp-68h]
  _DWORD *v48; // [rsp+A8h] [rbp-60h] BYREF
  PFAST_MUTEX FastMutex; // [rsp+B0h] [rbp-58h]
  ULONG NumberOfBytes; // [rsp+110h] [rbp+8h]

  ContiguousMemory = nullptr;
  v7 = 0;
  v8 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 64LL) + 240LL);
  v35 = *(_QWORD *)(*(_QWORD *)a1 + 64LL);
  v36 = nullptr;
  NumberOfBytes = *(_DWORD *)(v8 + 56);
  v38 = *(unsigned int *)(v8 + 64);
  FastMutex = (PFAST_MUTEX)(v8 + 72);
  PoolWithTagPriority = (v38 + a4) / NumberOfBytes;
  v39 = PoolWithTagPriority;
  ExAcquireFastMutex((PFAST_MUTEX)(v8 + 72));
  v10 = PoolWithTagPriority & 7;
  v45 = (unsigned int)PoolWithTagPriority;
  v11 = *(_QWORD *)(v8 + 90712);
  v34 = PoolWithTagPriority & 7;
  v12 = (unsigned __int64)(unsigned int)PoolWithTagPriority >> 3;
  v13 = (unsigned int)(1 << (PoolWithTagPriority & 7));
  v47 = v12;
  v37 = v13;
  if ( ((unsigned __int8)v13 & *(_BYTE *)(v12 + v11)) == 0 )
  {
    v14 = *(_QWORD *)(v8 + 90688);
    if ( ((unsigned __int8)v13 & *(_BYTE *)(v14 + v12)) == 0 )
    {
      *(_BYTE *)(v12 + v14) |= 1 << v10;
      _InterlockedAdd((volatile signed __int32 *)(v8 + 90740), 0xFFFFFFFF);
      v7 = 1;
    }
    *(_BYTE *)(v12 + *(_QWORD *)(v8 + 90704)) |= 1 << v10;
    ExReleaseFastMutex((PFAST_MUTEX)(v8 + 72));
    if ( v7 != 0 )
      sub_28005C180(v8);
    if ( *(_QWORD *)(a1 + 8) != 0 )
    {
      if ( *(_DWORD *)(a1 + 32) != -1 )
      {
        *(_DWORD *)(a1 + 56) += a3;
        goto LABEL_12;
      }
      *(_DWORD *)(a1 + 56) = a3;
      *(_QWORD *)(a1 + 40) = a2;
      *(_QWORD *)(a1 + 48) = a4;
LABEL_10:
      *(_DWORD *)(a1 + 32) = PoolWithTagPriority;
      *(_DWORD *)(a1 + 28) = PoolWithTagPriority;
      *(_DWORD *)(a1 + 60) = 1;
    }
    return 0;
  }
  if ( dword_280074EE4 + (NumberOfBytes >> 10) <= dword_280074EE0 && *(_QWORD *)(a1 + 8) != 0 )
  {
    ContiguousMemory = (char *)MmAllocateContiguousMemory(NumberOfBytes, HighestAcceptableAddress);
    v36 = ContiguousMemory;
  }
  v16 = -1;
  v17 = -1;
  while ( 1 )
  {
LABEL_17:
    if ( ContiguousMemory == nullptr )
      v16 = sub_280059EB0(v8);
    if ( v16 != -1 )
    {
      v13 = 1;
      LOBYTE(v13) = 1 << (v16 & 7);
      v18 = (unsigned __int64)v16 >> 3;
      *(_BYTE *)(v18 + *(_QWORD *)(v8 + 90704)) |= v13;
      *(_BYTE *)(v18 + *(_QWORD *)(v8 + 90720)) |= v13;
      *(_BYTE *)(v18 + *(_QWORD *)(v8 + 90712)) |= v13;
    }
    if ( v17 == -1 )
    {
      if ( (v37 & *(_BYTE *)(v12 + *(_QWORD *)(v8 + 90720))) == 0 )
        goto LABEL_25;
      LOBYTE(v13) = 1;
      v19 = sub_28005AA20(&v40, v8, v13, (unsigned int)PoolWithTagPriority);
      if ( v19 < 0 )
        goto LABEL_74;
      v17 = *v40;
      if ( *v40 == -1 )
      {
LABEL_25:
        *(_BYTE *)(v12 + *(_QWORD *)(v8 + 90704)) |= 1 << v34;
        *(_BYTE *)(v12 + *(_QWORD *)(v8 + 90696)) |= 1 << v34;
        v20 = ~(1 << v34);
        *(_BYTE *)(v12 + *(_QWORD *)(v8 + 90712)) &= v20;
        *(_BYTE *)(v12 + *(_QWORD *)(v8 + 90720)) &= v20;
        if ( ContiguousMemory != nullptr )
        {
          if ( sub_28005A9C0(v8, (unsigned int)PoolWithTagPriority, ContiguousMemory) != 0 )
            goto LABEL_42;
          goto LABEL_36;
        }
        if ( v16 == -1 )
          goto LABEL_42;
        v21 = sub_28005AA20(&v42, v8, 0, (unsigned int)PoolWithTagPriority);
        if ( v21 >= 0 )
        {
          LOBYTE(v22) = 1;
          *v42 = v16;
          v21 = sub_28005AA20(&v46, v8, v22, v16);
          if ( v21 >= 0 )
          {
            *v46 = PoolWithTagPriority;
            goto LABEL_42;
          }
        }
LABEL_73:
        v19 = v21;
LABEL_74:
        ExReleaseFastMutex(FastMutex);
        return (unsigned int)v19;
      }
    }
    LOBYTE(v13) = 1;
    v21 = sub_28005AA20(&v44, v8, v13, (unsigned int)PoolWithTagPriority);
    if ( v21 < 0 )
      goto LABEL_73;
    *v44 = -1;
    if ( ContiguousMemory == nullptr )
      break;
    v21 = sub_28005AA20(&v48, v8, 0, v17);
    if ( v21 < 0 )
      goto LABEL_73;
    *v48 = -1;
    if ( sub_28005A9C0(v8, v17, ContiguousMemory) != 0 )
      goto LABEL_41;
LABEL_36:
    MmFreeContiguousMemory(ContiguousMemory);
    ContiguousMemory = nullptr;
    v36 = nullptr;
  }
  v21 = sub_28005AA20(&v41, v8, 0, v17);
  if ( v21 < 0 )
    goto LABEL_73;
  *v41 = v16;
  if ( v16 != -1 )
  {
    LOBYTE(v23) = 1;
    v21 = sub_28005AA20(&v43, v8, v23, v16);
    if ( v21 < 0 )
      goto LABEL_73;
    *v43 = v17;
  }
LABEL_41:
  *(_BYTE *)(v12 + *(_QWORD *)(v8 + 90704)) |= 1 << v34;
  v24 = ~(1 << v34);
  *(_BYTE *)(v12 + *(_QWORD *)(v8 + 90712)) &= v24;
  *(_BYTE *)(v12 + *(_QWORD *)(v8 + 90720)) &= v24;
LABEL_42:
  ExReleaseFastMutex((PFAST_MUTEX)(v8 + 72));
  if ( ContiguousMemory == nullptr && v16 == -1 )
    goto LABEL_69;
  v32 = 0;
  v25 = 0;
  for ( i = NumberOfBytes; ; i = NumberOfBytes )
  {
    PoolWithTagPriority = (__int64)ExAllocatePoolWithTagPriority(NonPagedPool, i, 0x74706B64u, HighPoolPriority);
    if ( PoolWithTagPriority != 0 )
      break;
    v27 = v25++;
    if ( v27 >= 0xA )
      return 3221225626LL;
    KeDelayExecutionThread(0, 0, &Interval);
  }
  v28 = NumberOfBytes;
  Timeout = NumberOfBytes * v45 - v38;
  if ( Timeout < 0 )
  {
    Timeout = 0;
    v32 = v38 - NumberOfBytes * v45;
    v28 = NumberOfBytes + NumberOfBytes * v45 - v38;
  }
  v30 = sub_28005155C(
          *(PDEVICE_OBJECT *)(v35 + 24),
          3u,
          (void *)PoolWithTagPriority,
          v28,
          (union _LARGE_INTEGER)Timeout);
  v33 = v30;
  if ( v30 < 0 )
  {
    if ( *(_QWORD *)(v8 + 40) - Timeout < NumberOfBytes )
    {
      v28 = *(_DWORD *)(v8 + 40) - Timeout;
      if ( v28 != 0 )
      {
        v30 = sub_28005155C(
                *(PDEVICE_OBJECT *)(v35 + 24),
                3u,
                (void *)PoolWithTagPriority,
                v28,
                (union _LARGE_INTEGER)Timeout);
        v33 = v30;
        goto LABEL_54;
      }
LABEL_68:
      ExFreePoolWithTag((PVOID)PoolWithTagPriority, 0x74706B64u);
      LODWORD(PoolWithTagPriority) = v39;
LABEL_69:
      if ( *(_QWORD *)(a1 + 8) == 0 )
        return 0;
      if ( *(_DWORD *)(a1 + 32) == -1 )
      {
        *(_QWORD *)(a1 + 40) = a2;
        *(_QWORD *)(a1 + 48) = a4;
        *(_DWORD *)(a1 + 56) = a3;
        goto LABEL_10;
      }
      *(_DWORD *)(a1 + 56) += a3;
LABEL_12:
      ++*(_DWORD *)(a1 + 60);
      return 0;
    }
LABEL_54:
    if ( v30 < 0 )
    {
      ExFreePoolWithTag((PVOID)PoolWithTagPriority, 0x74706B64u);
      return v33;
    }
  }
  if ( v28 == 0 )
    goto LABEL_68;
  if ( *(_BYTE *)(v8 + 90760) != 0 && v17 == -1 )
    sub_28005E524(*(_QWORD *)(v35 + 240), PoolWithTagPriority, v28);
  ContiguousMemory = v36;
  if ( v36 != nullptr )
  {
    memmove(&v36[v32], (const void *)PoolWithTagPriority, v28);
    goto LABEL_68;
  }
  v31 = sub_28005155C(
          *(PDEVICE_OBJECT *)(v35 + 24),
          4u,
          (void *)PoolWithTagPriority,
          v28,
          (union _LARGE_INTEGER)(v32 + NumberOfBytes * (unsigned __int64)v16 - v38));
  if ( v31 >= 0 )
    goto LABEL_68;
  ExFreePoolWithTag((PVOID)PoolWithTagPriority, 0x74706B64u);
  if ( v31 == -1073741761 || v31 == -1073741762 )
  {
    ExAcquireFastMutex((PFAST_MUTEX)(v8 + 72));
    LODWORD(PoolWithTagPriority) = v39;
    v12 = v47;
    goto LABEL_17;
  }
  return (unsigned int)v31;
}


// ===== sub_280058764 @ 0x280058764 size=0xce =====
char __fastcall sub_280058764(PSLIST_ENTRY ListEntry, unsigned int a2)
{
  struct _SLIST_ENTRY *Next; // rdi
  signed __int32 v4; // eax
  int v5; // ecx
  __int64 v6; // rax
  struct _SLIST_ENTRY *v7; // rcx

  Next = ListEntry->Next[4].Next;
  v4 = _InterlockedExchangeAdd((volatile signed __int32 *)&ListEntry[1].Next + 1, a2);
  v5 = (int)ListEntry[1].Next;
  if ( a2 + v4 != v5 )
    return 0;
  v6 = *((_QWORD *)&ListEntry->Next + 1);
  if ( *((int *)&ListEntry[1].Next + 2) < 0 )
    *(_QWORD *)(v6 + 56) = 0;
  else
    *(_QWORD *)(v6 + 56) = (unsigned int)(v5 - 1);
  *(_DWORD *)(*((_QWORD *)&ListEntry->Next + 1) + 48LL) = *((_DWORD *)&ListEntry[1].Next + 2);
  IofCompleteRequest(*((PIRP *)&ListEntry->Next + 1), 1);
  IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)&Next[11], *((PVOID *)&ListEntry->Next + 1), 0x20u);
  v7 = ListEntry[4].Next;
  if ( v7 != nullptr )
    ExFreePoolWithTag(v7, 0x63437064u);
  ++dword_28007469C;
  if ( ExQueryDepthSList(&SListHead) < (unsigned __int16)word_280074690 )
  {
    ExpInterlockedPushEntrySList(&SListHead, ListEntry);
  }
  else
  {
    ++dword_2800746A0;
    qword_2800746B8(ListEntry);
  }
  return 1;
}


// ===== sub_280058838 @ 0x280058838 size=0x22d =====
__int64 __fastcall sub_280058838(
        PDEVICE_OBJECT DeviceObject,
        PVOID VirtualAddress,
        ULONG Length,
        LARGE_INTEGER a4,
        struct _SLIST_ENTRY *a5)
{
  ULONG_PTR v7; // r15
  __int64 Next; // rax
  PSLIST_ENTRY v10; // rdi
  unsigned int v12; // ebx
  unsigned int v13; // eax
  PIRP Irp; // rsi
  unsigned int v15; // ebx
  struct _MDL *i; // rax
  unsigned int v17; // eax
  struct _MDL *v18; // r13
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rbx
  UCHAR *v20; // r12
  struct _IO_STACK_LOCATION *v21; // rax
  __int64 v24; // [rsp+90h] [rbp+28h]

  v7 = Length;
  Next = (__int64)a5->Next[4].Next;
  ++dword_280074714;
  v24 = Next;
  v10 = ExpInterlockedPopEntrySList(&stru_280074700);
  if ( v10 != nullptr
    || (++dword_280074718,
        (v10 = (PSLIST_ENTRY)qword_280074730(
                               (unsigned int)dword_280074724,
                               (unsigned int)dword_28007472C,
                               (unsigned int)dword_280074728)) != nullptr) )
  {
    v12 = 0;
    while ( 1 )
    {
      Irp = IoAllocateIrp(DeviceObject->StackSize, 0);
      if ( Irp != nullptr )
      {
        v15 = 0;
        for ( i = IoAllocateMdl(VirtualAddress, v7, 0, 0, nullptr); ; i = IoAllocateMdl(
                                                                            VirtualAddress,
                                                                            v7,
                                                                            0,
                                                                            0,
                                                                            nullptr) )
        {
          v18 = i;
          if ( i != nullptr )
          {
            CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
            v20 = *(UCHAR **)(*((_QWORD *)&a5->Next + 1) + 184LL);
            MmBuildMdlForNonPagedPool(i);
            CurrentStackLocation[-1].Parameters.Read.ByteOffset = a4;
            CurrentStackLocation[-1].Parameters.Read.Length = v7;
            CurrentStackLocation[-1].MajorFunction = *v20;
            Irp->IoStatus.Information = v7;
            Irp->MdlAddress = v18;
            Irp->UserIosb = nullptr;
            *((_QWORD *)&v10->Next + 1) = VirtualAddress;
            v10->Next = a5;
            LODWORD(v10[1].Next) = v7;
            BYTE4(v10[1].Next) = 0;
            if ( *(_BYTE *)(*(_QWORD *)(v24 + 240) + 90760LL) != 0 && *v20 == 3 )
              BYTE4(v10[1].Next) = *((_DWORD *)&a5[1].Next + 3) != LODWORD(a5[2].Next);
            v21 = Irp->Tail.Overlay.CurrentStackLocation;
            v21[-1].CompletionRoutine = (PIO_COMPLETION_ROUTINE)&sub_280058A6C;
            v21[-1].Context = v10;
            v21[-1].Control = -32;
            IofCallDriver(DeviceObject, Irp);
            return 0;
          }
          v17 = v15++;
          if ( v17 >= 0xA )
            break;
          KeDelayExecutionThread(0, 0, &Interval);
        }
        IoFreeIrp(Irp);
        ++dword_28007471C;
        if ( ExQueryDepthSList(&stru_280074700) >= (unsigned __int16)word_280074710 )
          goto LABEL_10;
        goto LABEL_11;
      }
      v13 = v12++;
      if ( v13 >= 0xA )
        break;
      KeDelayExecutionThread(0, 0, &Interval);
    }
    ++dword_28007471C;
    if ( ExQueryDepthSList(&stru_280074700) >= (unsigned __int16)word_280074710 )
    {
LABEL_10:
      ++dword_280074720;
      qword_280074738(v10);
      return 3221225626LL;
    }
LABEL_11:
    ExpInterlockedPushEntrySList(&stru_280074700, v10);
  }
  return 3221225626LL;
}


// ===== sub_280058A6C @ 0x280058a6c size=0xc1 =====
__int64 __fastcall sub_280058A6C(__int64 a1, IRP *a2, struct _SLIST_ENTRY *a3)
{
  struct _SLIST_ENTRY *Next; // rdi
  int Status; // eax

  Next = a3->Next;
  Status = a2->IoStatus.Status;
  if ( Status >= 0 )
  {
    if ( BYTE4(a3[1].Next) != 0 )
      sub_28005E600(a3->Next->Next[4].Next[15].Next, *((_QWORD *)&a3->Next + 1), LODWORD(a3[1].Next));
  }
  else
  {
    *((_DWORD *)&Next[1].Next + 2) = Status;
  }
  if ( a2->PendingReturned != 0 )
    *(_BYTE *)(*(_QWORD *)(*((_QWORD *)&Next->Next + 1) + 184LL) + 3LL) |= 1u;
  IoFreeIrp(a2);
  sub_280058764(Next, (unsigned int)a3[1].Next);
  ++dword_28007471C;
  if ( ExQueryDepthSList(&stru_280074700) < (unsigned __int16)word_280074710 )
  {
    ExpInterlockedPushEntrySList(&stru_280074700, a3);
  }
  else
  {
    ++dword_280074720;
    qword_280074738(a3);
  }
  return 3221225494LL;
}


// ===== sub_280058B34 @ 0x280058b34 size=0x152 =====
bool __fastcall sub_280058B34(__int64 a1)
{
  __int16 v1; // r11
  int v2; // r10d
  __int16 v3; // r8
  char v4; // dl
  unsigned __int8 v5; // al
  __int16 v6; // r9
  char v7; // di

  v1 = *(_WORD *)(a1 + 19);
  v2 = *(_DWORD *)(a1 + 32);
  v3 = *(_WORD *)(a1 + 11);
  v4 = *(_BYTE *)(a1 + 13);
  v5 = *(_BYTE *)(a1 + 21);
  v6 = *(_WORD *)(a1 + 22);
  v7 = 1;
  if ( v1 != 0 )
    v2 = 0;
  if ( *(_BYTE *)a1 != 0xE9 && *(_BYTE *)a1 != 0xEB && *(_BYTE *)a1 != 73
    || v3 != 128 && v3 != 256 && v3 != 512 && v3 != 1024 && v3 != 2048 && v3 != 4096
    || v4 != 1 && v4 != 2 && v4 != 4 && v4 != 8 && v4 != 16 && v4 != 32 && v4 != 64 && v4 != (char)0x80
    || *(_WORD *)(a1 + 14) == 0
    || *(_BYTE *)(a1 + 16) == 0
    || v1 == 0 && v2 == 0
    || v6 == 0 && (*(_DWORD *)(a1 + 36) == 0 || *(_WORD *)(a1 + 42) != 0)
    || v5 != 0xF0
    && v5 != 0xF8
    && v5 != 0xF9
    && v5 != 0xFB
    && v5 != 0xFC
    && v5 != 0xFD
    && v5 != 0xFE
    && v5 != 0xFF
    && v5 >= 2u
    && v5 != 0xFA )
  {
    return false;
  }
  if ( v6 == 0 )
    return (*(_WORD *)(a1 + 40) & 0x80u) == 0;
  if ( *(_WORD *)(a1 + 17) == 0 )
    return false;
  return v7;
}


// ===== sub_280058C8C @ 0x280058c8c size=0x15f =====
bool __fastcall sub_280058C8C(_BYTE *a1)
{
  char v1; // al
  char v2; // al
  char v3; // dl
  bool result; // al

  result = false;
  if ( a1[3] == 78
    && a1[4] == 84
    && a1[5] == 70
    && a1[6] == 83
    && a1[7] == 32
    && a1[8] == 32
    && a1[9] == 32
    && a1[10] == 32
    && a1[11] == 0
    && (unsigned __int8)a1[12] << 8 <= 0x1000u )
  {
    v1 = a1[13];
    if ( (v1 == 1 || v1 == 2 || v1 == 4 || v1 == 8 || v1 == 16 || v1 == 32 || v1 == 64 || v1 == (char)0x80)
      && a1[14] == 0
      && a1[15] == 0
      && a1[16] == 0
      && a1[17] == 0
      && a1[18] == 0
      && a1[19] == 0
      && a1[20] == 0
      && a1[22] == 0
      && a1[23] == 0
      && a1[32] == 0
      && a1[33] == 0
      && a1[34] == 0
      && a1[35] == 0
      && ((v2 = a1[64]) >= -31 && v2 <= -9
       || v2 == 1
       || v2 == 2
       || v2 == 4
       || v2 == 8
       || v2 == 16
       || v2 == 32
       || v2 == 64) )
    {
      v3 = a1[68];
      if ( v3 >= -31 && v3 <= -9 )
        return true;
      if ( v3 == 1 || v3 == 2 || v3 == 4 || v3 == 8 || v3 == 16 || v3 == 32 || v3 == 64 )
        return true;
    }
  }
  return result;
}


// ===== sub_280058DF4 @ 0x280058df4 size=0x1a0 =====
__int64 __fastcall sub_280058DF4(__int64 *a1)
{
  __int64 v1; // rbp
  char *PoolWithTag; // rax
  char *v4; // rbx
  NTSTATUS v6; // esi
  struct _DEVICE_OBJECT *v7; // rcx
  unsigned int v8; // eax
  char v9; // al
  unsigned int v10; // edi
  int Timeout; // [rsp+20h] [rbp-28h]

  v1 = *a1;
  PoolWithTag = (char *)ExAllocatePoolWithTag(NonPagedPool, 0x1000u, 0x74706B64u);
  v4 = PoolWithTag;
  if ( PoolWithTag == nullptr )
  {
    DbgPrint("diskpt!StorInitializeBitmap: ExAllocatePoolWithTag failed\n");
    return 3221225626LL;
  }
  v6 = sub_28005155C(*(PDEVICE_OBJECT *)(v1 + 24), 3u, PoolWithTag, 0x1000u, 0);
  if ( v6 < 0 )
  {
    DbgPrint("diskpt!StorInitializeBitmap: FltReadWriteSectors failed\n");
    ExFreePoolWithTag(v4, 0x74706B64u);
    return (unsigned int)v6;
  }
  if ( sub_280058B34((__int64)v4) )
  {
    v7 = *(struct _DEVICE_OBJECT **)(v1 + 24);
    Timeout = *((_DWORD *)a1 + 16);
    if ( *((_WORD *)v4 + 11) != 0 )
      v8 = sub_280058F9C(v7, Timeout);
    else
      v8 = sub_2800591F4(v7, Timeout);
  }
  else if ( sub_280058C8C(v4) )
  {
    v8 = sub_280059420(*(PDEVICE_OBJECT *)(v1 + 24), *((_DWORD *)a1 + 16));
  }
  else
  {
    v9 = *v4;
    if ( *v4 != -23 && v9 != -21 && v9 != 73
      || v4[3] != 69
      || v4[4] != 88
      || v4[5] != 70
      || v4[6] != 65
      || v4[7] != 84
      || v4[8] != 32
      || v4[9] != 32
      || v4[10] != 32 )
    {
      v10 = -1073741489;
      goto LABEL_25;
    }
    v8 = sub_280059994(*(PDEVICE_OBJECT *)(v1 + 24), *((_DWORD *)a1 + 16));
  }
  v10 = v8;
LABEL_25:
  ExFreePoolWithTag(v4, 0x74706B64u);
  return v10;
}


// ===== sub_280058F9C @ 0x280058f9c size=0x252 =====
__int64 __fastcall sub_280058F9C(PDEVICE_OBJECT DeviceObject, _BYTE *a2, int a3, int a4, int a5)
{
  char *PoolWithTag; // rax
  char *v9; // r14
  NTSTATUS v11; // ebx
  __int64 v12; // rdx
  unsigned int v13; // r15d
  union _LARGE_INTEGER Timeout; // r12
  ULONG v15; // edi
  PVOID v16; // rsi
  unsigned int i; // ebp
  _WORD *v18; // r12
  __int64 v19; // rax
  ULONG v20; // [rsp+40h] [rbp-68h]
  DWORD v21; // [rsp+48h] [rbp-60h]
  unsigned int v22; // [rsp+50h] [rbp-58h]
  union _LARGE_INTEGER v23; // [rsp+58h] [rbp-50h]
  char *v24; // [rsp+68h] [rbp-40h]

  PoolWithTag = (char *)ExAllocatePoolWithTag(NonPagedPool, 0x1000u, 0x74706B64u);
  v9 = PoolWithTag;
  v24 = PoolWithTag;
  if ( PoolWithTag == nullptr )
    return 3221225626LL;
  v11 = sub_28005155C(DeviceObject, 3u, PoolWithTag, 0x1000u, 0);
  if ( v11 >= 0 )
  {
    v12 = *(unsigned __int16 *)(v9 + 11);
    v13 = v12 * *((unsigned __int16 *)v9 + 11);
    Timeout.QuadPart = v12 * *((unsigned __int16 *)v9 + 7);
    v23 = Timeout;
    v21 = Timeout.LowPart + v13 * (unsigned __int8)v9[16] + 32 * *(unsigned __int16 *)(v9 + 17);
    v22 = v13;
    v20 = v12 * (unsigned __int8)v9[13];
    v15 = v20;
    v16 = ExAllocatePoolWithTag(NonPagedPool, v20, 0x74706B64u);
    if ( v16 != nullptr )
    {
      if ( a3 != 0 )
      {
        *a2 |= 1u;
        *a2 |= 2u;
      }
      sub_280059E30((_DWORD)a2, a3, 0, v21, a4, a5);
      for ( i = 0; i < v13; v23 = Timeout )
      {
        if ( i + v15 > v13 )
          v15 = v13 - i;
        v11 = sub_28005155C(DeviceObject, 3u, v16, v15, Timeout);
        if ( v11 < 0 )
          break;
        v18 = v16;
        if ( v15 != 0 )
        {
          do
          {
            if ( *v18 != 0 )
            {
              v19 = ((__int64)v18 + i - (_QWORD)v16) / 2;
              if ( (unsigned __int16)v19 >= 2u )
                sub_280059D98((_DWORD)a2, a3, (unsigned __int16)v19, v21 - 2 * v20, v20, a4, a5);
            }
            ++v18;
          }
          while ( (int)v18 - (int)v16 < v15 );
          v9 = v24;
          v13 = v22;
        }
        i += v15;
        Timeout.QuadPart = v15 + v23.QuadPart;
      }
      ExFreePoolWithTag(v16, 0x74706B64u);
    }
    else
    {
      v11 = -1073741670;
    }
  }
  ExFreePoolWithTag(v9, 0x74706B64u);
  return (unsigned int)v11;
}


// ===== sub_2800591F4 @ 0x2800591f4 size=0x226 =====
__int64 __fastcall sub_2800591F4(PDEVICE_OBJECT DeviceObject, _BYTE *a2, int a3, int a4, int a5)
{
  char *PoolWithTag; // rax
  char *v9; // r14
  NTSTATUS v11; // ebx
  __int64 v12; // rcx
  unsigned int v13; // r15d
  int v14; // r13d
  ULONG v15; // edi
  PVOID v16; // r12
  unsigned int v17; // esi
  union _LARGE_INTEGER Timeout; // rcx
  _DWORD *v19; // r13
  int v20; // eax
  unsigned int v21; // ecx
  ULONG v22; // [rsp+40h] [rbp-68h]
  unsigned int v23; // [rsp+48h] [rbp-60h]
  union _LARGE_INTEGER v24; // [rsp+50h] [rbp-58h]
  ULONG v25; // [rsp+58h] [rbp-50h]
  char *v26; // [rsp+60h] [rbp-48h]

  PoolWithTag = (char *)ExAllocatePoolWithTag(NonPagedPool, 0x1000u, 0x74706B64u);
  v9 = PoolWithTag;
  v26 = PoolWithTag;
  if ( PoolWithTag == nullptr )
    return 3221225626LL;
  v11 = sub_28005155C(DeviceObject, 3u, PoolWithTag, 0x1000u, 0);
  if ( v11 >= 0 )
  {
    v12 = *(unsigned __int16 *)(v9 + 11);
    v13 = v12 * *((_DWORD *)v9 + 9);
    v23 = v13;
    v14 = v12 * *((unsigned __int16 *)v9 + 7) + v13 * (unsigned __int8)v9[16];
    v24.QuadPart = v12 * *((unsigned __int16 *)v9 + 7);
    v22 = v12 * (unsigned __int8)v9[13];
    v15 = v22;
    v25 = v14 - 2 * v22;
    v16 = ExAllocatePoolWithTag(NonPagedPool, v22, 0x74706B64u);
    if ( v16 != nullptr )
    {
      if ( a3 != 0 )
        *a2 |= 3u;
      sub_280059E30((_DWORD)a2, a3, 0, v14, a4, a5);
      v17 = 0;
      if ( v13 != 0 )
      {
        Timeout = v24;
        do
        {
          if ( v17 + v15 > v13 )
            v15 = v13 - v17;
          v11 = sub_28005155C(DeviceObject, 3u, v16, v15, Timeout);
          if ( v11 < 0 )
            break;
          v19 = v16;
          if ( v15 != 0 )
          {
            v20 = 0;
            do
            {
              if ( *v19 != 0 )
              {
                v21 = (v20 + v17) >> 2;
                if ( v21 >= 2 )
                  sub_280059D98((_DWORD)a2, a3, v21, v25, v22, a4, a5);
              }
              v20 = (_DWORD)++v19 - (_DWORD)v16;
            }
            while ( (int)v19 - (int)v16 < v15 );
            v9 = v26;
            v13 = v23;
          }
          v17 += v15;
          Timeout.QuadPart = v15 + v24.QuadPart;
          v24 = Timeout;
        }
        while ( v17 < v13 );
      }
      ExFreePoolWithTag(v16, 0x74706B64u);
    }
    else
    {
      v11 = -1073741670;
    }
  }
  ExFreePoolWithTag(v9, 0x74706B64u);
  return (unsigned int)v11;
}


// ===== sub_280059420 @ 0x280059420 size=0x56b =====
__int64 __fastcall sub_280059420(PDEVICE_OBJECT DeviceObject, _BYTE *a2, int a3, int a4, int a5)
{
  _BYTE *v5; // r14
  unsigned __int8 *PoolWithTag; // rax
  unsigned __int8 *v8; // r12
  NTSTATUS v10; // eax
  unsigned int v11; // ebx
  __int64 v12; // rbp
  __int64 v13; // r13
  union _LARGE_INTEGER Timeout; // rdi
  unsigned int i; // esi
  SIZE_T v16; // rbp
  unsigned __int16 *v17; // rax
  unsigned __int16 *v18; // rsi
  NTSTATUS v19; // eax
  char *j; // rcx
  __int64 v21; // rbx
  char *v22; // rdi
  unsigned __int8 v23; // al
  unsigned int v24; // r8d
  unsigned int v25; // edx
  int v26; // r9d
  int v27; // ecx
  __int64 v28; // r10
  int v29; // eax
  __int64 v30; // r13
  __int64 v31; // r13
  int v32; // ecx
  __int64 v33; // r9
  unsigned __int64 v34; // rax
  unsigned __int64 v35; // r13
  int v36; // r9d
  int v37; // ecx
  __int64 m; // rdx
  int v39; // eax
  __int64 v40; // rdx
  int v41; // ecx
  __int64 k; // r9
  unsigned __int64 v43; // rax
  __int64 v44; // rbp
  PVOID v45; // r15
  union _LARGE_INTEGER v46; // rax
  NTSTATUS v47; // eax
  _BYTE *v48; // r8
  int v49; // r12d
  unsigned int v50; // ebx
  int v51; // r14d
  bool v52; // zf
  char *v53; // [rsp+40h] [rbp-A8h]
  int v54; // [rsp+48h] [rbp-A0h]
  SIZE_T v55; // [rsp+50h] [rbp-98h]
  union _LARGE_INTEGER v56; // [rsp+58h] [rbp-90h]
  __int64 v57; // [rsp+60h] [rbp-88h]
  __int64 v58; // [rsp+68h] [rbp-80h]
  _BYTE *v59; // [rsp+70h] [rbp-78h]
  __int64 v60; // [rsp+78h] [rbp-70h]
  unsigned __int64 v61; // [rsp+80h] [rbp-68h]
  unsigned __int8 *v62; // [rsp+88h] [rbp-60h]
  unsigned __int16 *v63; // [rsp+90h] [rbp-58h]
  PVOID v64; // [rsp+98h] [rbp-50h]

  v5 = a2;
  PoolWithTag = (unsigned __int8 *)ExAllocatePoolWithTag(NonPagedPool, 0x1000u, 0x74706B64u);
  v8 = PoolWithTag;
  v62 = PoolWithTag;
  if ( PoolWithTag == nullptr )
  {
    DbgPrint("diskpt!StorInitNtfsBitmap: ExAllocatePoolWithTag failed\n");
    return 3221225626LL;
  }
  v10 = sub_28005155C(DeviceObject, 3u, PoolWithTag, 0x1000u, 0);
  v11 = v10;
  if ( v10 < 0 )
  {
LABEL_65:
    DbgPrint("diskpt!StorInitNtfsBitmap: FltReadWriteSectors failed(%x)\n", v10);
LABEL_66:
    ExFreePoolWithTag(v8, 0x74706B64u);
    return v11;
  }
  v12 = v8[13];
  v13 = *(unsigned __int16 *)(v8 + 11);
  Timeout.QuadPart = v13 * v12 * *((_QWORD *)v8 + 6);
  for ( i = 0; i < 6; ++i )
  {
    v10 = sub_28005155C(DeviceObject, 3u, v8, 0x1000u, Timeout);
    v11 = v10;
    if ( v10 < 0 )
      goto LABEL_65;
    Timeout.QuadPart += *((unsigned int *)v8 + 7);
  }
  v16 = (unsigned int)(v13 * v12);
  v55 = v16;
  v17 = (unsigned __int16 *)ExAllocatePoolWithTag(NonPagedPool, v16, 0x74706B64u);
  v18 = v17;
  v63 = v17;
  if ( v17 == nullptr )
  {
    DbgPrint("diskpt!StorInitNtfsBitmap: ExAllocatePoolWithTag2 failed\n");
    v11 = -1073741670;
    goto LABEL_66;
  }
  v19 = sub_28005155C(DeviceObject, 3u, v17, v16, Timeout);
  v11 = v19;
  if ( v19 < 0 )
  {
    DbgPrint("diskpt!StorInitNtfsBitmap: FltReadWriteSectors failed(%x)\n", v19);
LABEL_11:
    ExFreePoolWithTag(v18, 0x74706B64u);
    goto LABEL_66;
  }
  for ( j = (char *)v18 + v18[10]; *(_DWORD *)j != -1 && *(_DWORD *)j != 128; j += *((unsigned int *)j + 1) )
    ;
  if ( *(_DWORD *)j != 128 )
  {
    DbgPrint("diskpt!StorInitNtfsBitmap: Can't find NtfsAttributeData\n", 128);
LABEL_18:
    ExFreePoolWithTag(v18, 0x74706B64u);
    v11 = -1073741823;
    goto LABEL_66;
  }
  if ( j[8] != 0 )
  {
    v54 = 0;
    v21 = 0;
    v22 = &j[*((unsigned __int16 *)j + 16)];
    v53 = v22;
    v23 = *v22;
    if ( *v22 != 0 )
    {
      while ( 1 )
      {
        v24 = v23 >> 4;
        v25 = v23 & 0xF;
        if ( v25 > 4 )
        {
          v31 = 0;
          v32 = 0;
          v33 = v23 & 0xF;
          do
          {
            v34 = (unsigned __int64)(unsigned __int8)*++v22 << v32;
            v32 += 8;
            v31 += v34;
            --v33;
          }
          while ( v33 != 0 );
          v53 = v22;
          v30 = v31 << (8 * (8 - (unsigned __int8)v25)) >> (8 * (8 - (unsigned __int8)v25));
        }
        else
        {
          v26 = 0;
          if ( (v23 & 0xF) != 0 )
          {
            v27 = 0;
            v28 = v23 & 0xF;
            do
            {
              v29 = (unsigned __int8)*++v22 << v27;
              v27 += 8;
              v26 += v29;
              --v28;
            }
            while ( v28 != 0 );
            v53 = v22;
          }
          v30 = v26 << (8 * (4 - v25)) >> (8 * (4 - v25));
        }
        v35 = v16 * v30;
        v61 = v35;
        if ( v24 > 4 )
        {
          v40 = 0;
          v41 = 0;
          for ( k = v24; k != 0; --k )
          {
            v43 = (unsigned __int64)(unsigned __int8)*++v22 << v41;
            v41 += 8;
            v40 += v43;
          }
          v53 = v22;
          v21 += v40 << (8 * (8 - (unsigned __int8)v24)) >> (8 * (8 - (unsigned __int8)v24));
        }
        else
        {
          v36 = 0;
          if ( v24 != 0 )
          {
            v37 = 0;
            for ( m = v24; m != 0; --m )
            {
              v39 = (unsigned __int8)*++v22 << v37;
              v37 += 8;
              v36 += v39;
            }
            v53 = v22;
          }
          v21 += (__int64)(v36 << (8 * (4 - v24))) >> (8 * (4 - (unsigned __int8)v24));
        }
        v44 = v35;
        if ( v35 > 0x100000 )
          v44 = 0x100000;
        v58 = v21;
        v57 = v44;
        v45 = ExAllocatePoolWithTag(NonPagedPool, (unsigned int)v44, 0x74706B64u);
        v64 = v45;
        if ( v45 == nullptr )
        {
          DbgPrint("diskpt!StorInitNtfsBitmap: ExAllocatePoolWithTag3 failed\n");
          goto LABEL_18;
        }
        v46.QuadPart = v21 * v55;
        v56.QuadPart = v21 * v55;
        if ( v35 != 0 )
          break;
LABEL_56:
        ExFreePoolWithTag(v45, 0x74706B64u);
        v23 = *++v22;
        v53 = v22;
        if ( *v22 == 0 )
        {
          v5 = a2;
          goto LABEL_60;
        }
        v16 = v55;
      }
      while ( 1 )
      {
        v47 = sub_28005155C(DeviceObject, 3u, v45, v44, v46);
        v11 = v47;
        if ( v47 < 0 )
          break;
        if ( (_DWORD)v44 != 0 )
        {
          v48 = v45;
          v59 = v45;
          v49 = 8 * v54;
          v60 = (unsigned int)v44;
          do
          {
            v50 = 0;
            v51 = 0;
            do
            {
              if ( ((unsigned __int8)(1 << v50) & *v48) != 0 )
              {
                sub_280059D98((_DWORD)a2, a3, v49 + v51, 0, v55, a4, a5);
                v48 = v59;
              }
              ++v50;
              ++v51;
            }
            while ( v50 < 8 );
            ++v48;
            v49 += 8;
            v52 = v60-- == 1;
            v59 = v48;
          }
          while ( !v52 );
          v8 = v62;
          v18 = v63;
          v22 = v53;
          v44 = v57;
          v35 = v61;
          v45 = v64;
        }
        v54 += v44;
        v35 -= v44;
        v46.QuadPart = v44 + v56.QuadPart;
        v44 = v35;
        if ( v35 > 0x100000 )
          v44 = 0x100000;
        v56 = v46;
        v61 = v35;
        v57 = v44;
        if ( v35 == 0 )
        {
          v21 = v58;
          goto LABEL_56;
        }
      }
      DbgPrint("diskpt!StorInitNtfsBitmap: FltReadWriteSectors failed(%x)\n", v47);
      ExFreePoolWithTag(v45, 0x74706B64u);
      goto LABEL_11;
    }
LABEL_60:
    if ( a3 != 0 )
      *v5 |= 3u;
    ExFreePoolWithTag(v18, 0x74706B64u);
    ExFreePoolWithTag(v8, 0x74706B64u);
    return 0;
  }
  else
  {
    DbgPrint("diskpt!StorInitNtfsBitmap: find Resident attribute\n", 128);
    ExFreePoolWithTag(v18, 0x74706B64u);
    ExFreePoolWithTag(v8, 0x74706B64u);
    return 3221225473LL;
  }
}


// ===== sub_280059994 @ 0x280059994 size=0x239 =====
__int64 __fastcall sub_280059994(PDEVICE_OBJECT DeviceObject, _BYTE *a2, int a3, int a4, int a5)
{
  _BYTE *PoolWithTag; // rax
  _BYTE *v9; // r14
  NTSTATUS v11; // ebx
  __int64 v12; // rcx
  int v13; // eax
  unsigned int v14; // r15d
  union _LARGE_INTEGER Timeout; // r13
  ULONG v16; // edi
  PVOID v17; // r12
  unsigned int i; // esi
  _DWORD *v19; // r13
  int v20; // eax
  unsigned int v21; // ecx
  int v22; // [rsp+40h] [rbp-68h]
  int v23; // [rsp+48h] [rbp-60h]
  unsigned int v24; // [rsp+50h] [rbp-58h]
  union _LARGE_INTEGER v25; // [rsp+58h] [rbp-50h]
  int v26; // [rsp+60h] [rbp-48h]
  _BYTE *v27; // [rsp+68h] [rbp-40h]

  PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x1000u, 0x74706B64u);
  v9 = PoolWithTag;
  v27 = PoolWithTag;
  if ( PoolWithTag == nullptr )
    return 3221225626LL;
  v11 = sub_28005155C(DeviceObject, 3u, PoolWithTag, 0x1000u, 0);
  if ( v11 >= 0 )
  {
    v12 = (unsigned int)(1 << v9[108]);
    v13 = 1 << v9[109];
    v14 = v12 * *((_DWORD *)v9 + 21);
    v24 = v14;
    Timeout.QuadPart = v12 * *((unsigned int *)v9 + 20);
    v25 = Timeout;
    v22 = v12 * v13;
    v16 = v12 * v13;
    v23 = v12 * v13 * *((_DWORD *)v9 + 22);
    v26 = v23 - 2 * v12 * v13;
    v17 = ExAllocatePoolWithTag(NonPagedPool, (unsigned int)(v12 * v13), 0x74706B64u);
    if ( v17 != nullptr )
    {
      if ( a3 != 0 )
        *a2 |= 3u;
      sub_280059E30((_DWORD)a2, a3, 0, v23, a4, a5);
      for ( i = 0; i < v14; v25 = Timeout )
      {
        if ( i + v16 > v14 )
          v16 = v14 - i;
        v11 = sub_28005155C(DeviceObject, 3u, v17, v16, Timeout);
        if ( v11 < 0 )
          break;
        v19 = v17;
        if ( v16 != 0 )
        {
          v20 = 0;
          do
          {
            if ( *v19 != 0 )
            {
              v21 = (v20 + i) >> 2;
              if ( v21 >= 2 )
                sub_280059D98((_DWORD)a2, a3, v21, v26, v22, a4, a5);
            }
            v20 = (_DWORD)++v19 - (_DWORD)v17;
          }
          while ( (int)v19 - (int)v17 < v16 );
          v9 = v27;
          v14 = v24;
        }
        i += v16;
        Timeout.QuadPart = v16 + v25.QuadPart;
      }
      ExFreePoolWithTag(v17, 0x74706B64u);
    }
    else
    {
      v11 = -1073741670;
    }
  }
  ExFreePoolWithTag(v9, 0x74706B64u);
  return (unsigned int)v11;
}


// ===== sub_280059BD4 @ 0x280059bd4 size=0x1bb =====
__int64 __fastcall sub_280059BD4(HANDLE FileHandle, _BYTE *a2, int a3, int a4, int a5, int a6, int a7)
{
  HANDLE v9; // rdi
  _QWORD *OutputBuffer; // rbp
  NTSTATUS v12; // eax
  int v13; // edi
  __int64 v14; // r12
  __int64 v15; // rsi
  NTSTATUS v16; // [rsp+50h] [rbp-58h]
  __int64 InputBuffer; // [rsp+58h] [rbp-50h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+60h] [rbp-48h] BYREF

  v9 = FileHandle;
  OutputBuffer = ExAllocatePoolWithTag(NonPagedPool, 0xFA0u, 0x74706B64u);
  if ( OutputBuffer == nullptr )
    return 3221225626LL;
  for ( InputBuffer = 0; ; InputBuffer = *OutputBuffer + 8 * (v14 / 8) )
  {
    v12 = ZwFsControlFile(
            v9,
            nullptr,
            nullptr,
            nullptr,
            &IoStatusBlock,
            0x9006Fu,
            &InputBuffer,
            8u,
            OutputBuffer,
            0xFA0u);
    v13 = v12;
    v16 = v12;
    if ( v12 < 0 && v12 != -2147483643 )
      break;
    v14 = 31872;
    if ( (__int64)OutputBuffer[1] < 31872 )
      v14 = OutputBuffer[1];
    v15 = 0;
    if ( v14 > 0 )
    {
      do
      {
        if ( ((unsigned __int8)(1 << (v15 & 7)) & *((_BYTE *)OutputBuffer + (v15 >> 3) + 16)) != 0 )
          sub_280059D98((_DWORD)a2, a3, v15 + *OutputBuffer, a4, a5, a6, a7);
        ++v15;
      }
      while ( v15 < v14 );
      v13 = v16;
    }
    if ( v13 >= 0 )
    {
      if ( a3 != 0 )
        *a2 |= 3u;
      sub_280059E30((_DWORD)a2, a3, 0, a4 + 2 * a5, a6, a7);
      break;
    }
    if ( InputBuffer >= *OutputBuffer + 8 * (v14 / 8) )
    {
      v13 = -1073741811;
      break;
    }
    v9 = FileHandle;
  }
  ExFreePoolWithTag(OutputBuffer, 0x74706B64u);
  return (unsigned int)v13;
}


// ===== sub_280059D98 @ 0x280059d98 size=0x92 =====
__int64 __fastcall sub_280059D98(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7)
{
  __int64 v7; // r11
  __int64 v8; // rbx
  __int64 result; // rax
  unsigned int v10; // r9d
  unsigned __int64 v11; // r10

  v7 = a4 + a3 * a5;
  v8 = (a7 + v7) / a6;
  result = (__int64)(v7 + a7 + (unsigned __int64)a5) / a6;
  v10 = result;
  if ( ((a6 - 1) & (unsigned int)result) != 0 )
    v10 = result + 1;
  if ( (unsigned int)v8 < v10 )
  {
    v11 = (unsigned int)v8;
    do
    {
      result = (unsigned int)v8 >> 3;
      if ( (unsigned int)result < a2 )
        *(_BYTE *)((v11 >> 3) + a1) |= 1 << (v8 & 7);
      LODWORD(v8) = v8 + 1;
      ++v11;
    }
    while ( (unsigned int)v8 < v10 );
  }
  return result;
}


// ===== sub_280059E30 @ 0x280059e30 size=0x78 =====
__int64 __fastcall sub_280059E30(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, unsigned int a5, unsigned int a6)
{
  __int64 v6; // r11
  __int64 result; // rax
  unsigned int v8; // r9d
  unsigned __int64 v9; // r10

  v6 = a6 / (__int64)a5;
  result = (a6 + a4) / a5;
  v8 = result;
  if ( ((a5 - 1) & (unsigned int)result) != 0 )
    v8 = result + 1;
  if ( (unsigned int)v6 < v8 )
  {
    v9 = (unsigned int)v6;
    do
    {
      result = (unsigned int)v6 >> 3;
      if ( (unsigned int)result < a2 )
        *(_BYTE *)((v9 >> 3) + a1) |= 1 << (v6 & 7);
      LODWORD(v6) = v6 + 1;
      ++v9;
    }
    while ( (unsigned int)v6 < v8 );
  }
  return result;
}


// ===== sub_280059EB0 @ 0x280059eb0 size=0x12f =====
__int64 __fastcall sub_280059EB0(__int64 a1)
{
  unsigned int v1; // ebx
  unsigned int v2; // edi
  unsigned int v3; // r8d
  __int64 v4; // r11
  int v6; // eax
  __int64 v7; // r8

  v1 = 0;
  while ( 1 )
  {
    v2 = *(_DWORD *)(a1 + 90732);
    v3 = *(_DWORD *)(a1 + 90736);
    if ( v2 < v3 )
      break;
LABEL_6:
    if ( v3 <= 0x10000 )
    {
      v6 = *(_DWORD *)(a1 + 90728);
      *(_DWORD *)(a1 + 90732) = 0;
      v6 -= 2;
      *(_DWORD *)(a1 + 90736) = v6;
      if ( v6 == 0 )
        return 0xFFFFFFFFLL;
      v7 = *(_QWORD *)(a1 + 90688);
      while ( ((unsigned __int8)(1 << (v1 & 7)) & *(_BYTE *)(((unsigned __int64)v1 >> 3) + v7)) != 0 )
      {
        ++*(_DWORD *)(a1 + 90732);
        if ( ++v1 >= *(_DWORD *)(a1 + 90736) )
          return 0xFFFFFFFFLL;
      }
      *(_BYTE *)(((unsigned __int64)v1 >> 3) + v7) |= 1 << (v1 & 7);
      _InterlockedAdd((volatile signed __int32 *)(a1 + 90740), 0xFFFFFFFF);
      sub_28005C180(a1);
      return v1;
    }
    *(_DWORD *)(a1 + 90736) = v3 - 0x10000;
    if ( v3 - 0x10000 >= 0x10000 )
      *(_DWORD *)(a1 + 90732) = v3 - 0x20000;
    else
      *(_DWORD *)(a1 + 90732) = 0;
  }
  v4 = *(_QWORD *)(a1 + 90688);
  while ( ((unsigned __int8)(1 << (v2 & 7)) & *(_BYTE *)(((unsigned __int64)v2 >> 3) + v4)) != 0 )
  {
    ++*(_DWORD *)(a1 + 90732);
    if ( ++v2 >= v3 )
      goto LABEL_6;
  }
  *(_BYTE *)(((unsigned __int64)v2 >> 3) + v4) |= 1 << (v2 & 7);
  _InterlockedAdd((volatile signed __int32 *)(a1 + 90740), 0xFFFFFFFF);
  sub_28005C180(a1);
  return v2;
}


// ===== sub_280059FE8 @ 0x280059fe8 size=0x71d =====
__int64 __fastcall sub_280059FE8(__int64 a1, __int64 a2, char a3)
{
  unsigned int v6; // ebx
  NTSTATUS v7; // eax
  unsigned int v8; // edi
  NTSTATUS v10; // eax
  __int64 v11; // r15
  int v12; // ebp
  __int16 v13; // ax
  NTSTATUS v14; // eax
  __int64 v15; // r8
  unsigned int v16; // r9d
  unsigned int *v17; // rdi
  ULONG v18; // r13d
  unsigned int *PoolWithTag; // rax
  NTSTATUS v20; // eax
  int v21; // ebp
  unsigned int v22; // r13d
  unsigned int v23; // r14d
  int v24; // ecx
  unsigned __int64 v25; // rsi
  char v26; // al
  int v27; // eax
  int v28; // eax
  int v29; // ecx
  _DWORD *v30; // r11
  unsigned int v31; // edx
  _QWORD *v32; // rcx
  __int64 v33; // r8
  _QWORD *v34; // r9
  __int64 v35; // rcx
  void *FileHandle; // [rsp+60h] [rbp-7D8h] BYREF
  int v37; // [rsp+68h] [rbp-7D0h]
  int v38; // [rsp+6Ch] [rbp-7CCh]
  int v39; // [rsp+70h] [rbp-7C8h]
  union _LARGE_INTEGER ByteOffset; // [rsp+78h] [rbp-7C0h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+80h] [rbp-7B8h] BYREF
  unsigned __int64 InputBuffer; // [rsp+90h] [rbp-7A8h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+98h] [rbp-7A0h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+C8h] [rbp-770h] BYREF
  _BYTE FileInformation[8]; // [rsp+D8h] [rbp-760h] BYREF
  int v46; // [rsp+E0h] [rbp-758h]
  _BYTE v47[1040]; // [rsp+F0h] [rbp-748h] BYREF
  _BYTE Buffer[4]; // [rsp+500h] [rbp-338h] BYREF
  int v49; // [rsp+504h] [rbp-334h]
  int v50; // [rsp+50Ch] [rbp-32Ch]
  int v51; // [rsp+510h] [rbp-328h]
  unsigned int v52; // [rsp+514h] [rbp-324h]
  int v53; // [rsp+518h] [rbp-320h]
  int v54; // [rsp+51Ch] [rbp-31Ch]
  _BYTE v55[8]; // [rsp+6F8h] [rbp-140h] BYREF
  WCHAR SourceString[128]; // [rsp+700h] [rbp-138h] BYREF

  swprintf(SourceString, L"%s\\diskpt0.sys", *(_QWORD *)a1 + 40LL);
  RtlInitUnicodeString(&DestinationString, SourceString);
  v6 = 0;
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  if ( ZwCreateFile(&FileHandle, 0x100003u, &ObjectAttributes, &IoStatusBlock, nullptr, 0, 0, 1u, 0x60u, nullptr, 0) < 0 )
  {
    v7 = ZwCreateFile(&FileHandle, 0x100001u, &ObjectAttributes, &IoStatusBlock, nullptr, 0, 0, 1u, 0x60u, nullptr, 0);
    v8 = v7;
    if ( v7 < 0 )
    {
      DbgPrint("diskpt!StorFindMapFile: ZwCreateFile(%ws) failed(%x)\n", SourceString, (unsigned int)v7);
      return v8;
    }
  }
  ByteOffset.QuadPart = 0;
  v10 = ZwReadFile(FileHandle, nullptr, nullptr, nullptr, &IoStatusBlock, Buffer, 0x200u, &ByteOffset, nullptr);
  v8 = v10;
  if ( v10 < 0 )
  {
    DbgPrint("diskpt!StorFindMapFile: ZwReadFile(%ws) failed(%x)\n", SourceString, (unsigned int)v10);
LABEL_12:
    ZwClose(FileHandle);
    return v8;
  }
  sub_2800522E8((__int64)Buffer, 504, (__int64)v55);
  if ( v49 == 1953524580 && v50 == 0x10000 )
  {
    if ( a3 != 0 )
    {
      if ( (v51 & 2) == 0 )
      {
LABEL_11:
        v8 = -1073741823;
        goto LABEL_12;
      }
    }
    else if ( (v51 & 1) == 0 )
    {
      goto LABEL_11;
    }
    DbgPrint("diskpt!StorFindMapFile: AllocateBitmapSize = %d\n", v53);
    v11 = v52;
    v12 = v53;
    v39 = v53;
    v38 = v54;
    if ( v52 == 0 || v53 == 0 || v54 == 0 )
      goto LABEL_11;
    v13 = v51;
    if ( (v51 & 0x40000) != 0 )
    {
      v51 &= ~0x40000u;
      sub_28006CA00(v47, v55, 8);
      sub_28006CA7C(v47, Buffer, 504);
      ByteOffset.QuadPart = 0;
      ZwWriteFile(FileHandle, nullptr, nullptr, nullptr, &IoStatusBlock, Buffer, 0x200u, &ByteOffset, nullptr);
      v13 = v51;
    }
    *(_BYTE *)(a1 + 90760) = 0;
    if ( (v13 & 0x100) != 0 )
      *(_BYTE *)(a1 + 90760) = 1;
    v14 = ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x18u, FileStandardInformation);
    v8 = v14;
    if ( v14 < 0 )
    {
      DbgPrint("diskpt!StorFindMapFile: ZwQueryInformationFile(%ws) failed(%x)\n", SourceString, (unsigned int)v14);
      goto LABEL_12;
    }
    v15 = *(_QWORD *)(a1 + 40);
    v37 = 5 * v12;
    v16 = (unsigned int)(v46 - 5 * v12 - 4096) >> 1;
    *(_DWORD *)(a1 + 74284) = v16;
    if ( v16 >> 2 < (unsigned int)(v15 / v11) + 1 )
    {
      DbgPrint("diskpt!StorFindMapFile: map file size(%d) doesn't match volume size(%I64d)\n", v46, v15);
      v8 = -1073741811;
      goto LABEL_12;
    }
    v17 = nullptr;
    v18 = 1024;
    while ( 1 )
    {
      if ( v17 != nullptr )
        ExFreePoolWithTag(v17, 0x74706B64u);
      v18 *= 2;
      PoolWithTag = (unsigned int *)ExAllocatePoolWithTag(NonPagedPool, v18, 0x74706B64u);
      v17 = PoolWithTag;
      if ( PoolWithTag == nullptr )
        break;
      InputBuffer = 0;
      v20 = ZwFsControlFile(
              FileHandle,
              nullptr,
              nullptr,
              nullptr,
              &IoStatusBlock,
              0x90073u,
              &InputBuffer,
              8u,
              PoolWithTag,
              v18);
      v21 = v20;
      if ( v20 >= 0 )
        goto LABEL_34;
      if ( v20 != -2147483643 )
      {
        ExFreePoolWithTag(v17, 0x74706B64u);
        goto LABEL_34;
      }
    }
    DbgPrint("diskpt!StorFindMapFile: ExAllocatePool failed\n");
    v21 = -1073741670;
LABEL_34:
    ZwClose(FileHandle);
    if ( v21 >= 0 )
    {
      v22 = *(unsigned __int16 *)(a2 + 11);
      v23 = *(unsigned __int8 *)(a2 + 13);
      if ( sub_280058B34(a2) )
      {
        v24 = *(unsigned __int8 *)(a2 + 16);
        if ( *(_WORD *)(a2 + 22) != 0 )
          v25 = v22 * (*(unsigned __int16 *)(a2 + 14) + *(unsigned __int16 *)(a2 + 22) * v24)
              + 32 * *(unsigned __int16 *)(a2 + 17);
        else
          v25 = v22 * (*(_DWORD *)(a2 + 36) * v24 + *(unsigned __int16 *)(a2 + 14));
      }
      else if ( sub_280058C8C((_BYTE *)a2) )
      {
        v25 = 0;
      }
      else
      {
        v26 = *(_BYTE *)a2;
        if ( (*(_BYTE *)a2 == 0xE9 || v26 == -21 || v26 == 73)
          && *(_BYTE *)(a2 + 3) == 69
          && *(_BYTE *)(a2 + 4) == 88
          && *(_BYTE *)(a2 + 5) == 70
          && *(_BYTE *)(a2 + 6) == 65
          && *(_BYTE *)(a2 + 7) == 84
          && *(_BYTE *)(a2 + 8) == 32
          && *(_BYTE *)(a2 + 9) == 32
          && *(_BYTE *)(a2 + 10) == 32 )
        {
          v22 = 1 << *(_BYTE *)(a2 + 108);
          v23 = 1 << *(_BYTE *)(a2 + 109);
          v25 = v22 * v23 * (unsigned __int64)*(unsigned int *)(a2 + 88) - 2 * v22 * v23;
        }
        else
        {
          v21 = -1073741489;
          DbgPrint("diskpt!StorFindMapFile: unrecognized volume\n");
          v25 = InputBuffer;
        }
      }
      if ( v21 >= 0 )
      {
        v27 = v39;
        *(_DWORD *)(a1 + 56) = v11;
        *(_DWORD *)(a1 + 90680) = v27;
        v28 = v38;
        *(_QWORD *)(a1 + 48) = v25;
        *(_DWORD *)(a1 + 68) = v28;
        *(_DWORD *)(a1 + 60) = v22 * v23;
        v29 = v11 - (v25 & (v11 - 1));
        *(_DWORD *)(a1 + 64) = v29;
        if ( v29 == (_DWORD)v11 )
          *(_DWORD *)(a1 + 64) = 0;
        v30 = ExAllocatePoolWithTag(NonPagedPool, 16 * *v17 + 20, 0x74706B64u);
        *(_QWORD *)(a1 + 74272) = v30;
        if ( v30 != nullptr )
        {
          v31 = 0;
          if ( *v17 != 0 )
          {
            v32 = v17 + 4;
            while ( (__int64)(*v32 * v23 * (unsigned __int64)v22) < (unsigned int)(*(_DWORD *)(a1 + 74284) + v37 + 4096) )
            {
              ++v31;
              v32 += 2;
              if ( v31 >= *v17 )
                goto LABEL_67;
            }
            *(_DWORD *)(a1 + 74280) = v31;
          }
LABEL_67:
          *v30 = *v17;
          if ( *v17 != 0 )
          {
            v33 = 0;
            v34 = v17 + 6;
            do
            {
              ++v6;
              v33 += 16;
              *(_QWORD *)(*(_QWORD *)(a1 + 74272) + v33 - 12) = v23 * v22 * *(v34 - 1);
              v35 = v22 * *v34;
              v34 += 2;
              *(_QWORD *)(*(_QWORD *)(a1 + 74272) + v33 - 4) = v25 + v23 * v35;
            }
            while ( v6 < *v17 );
          }
        }
        else
        {
          v21 = -1073741670;
        }
      }
      ExFreePoolWithTag(v17, 0x74706B64u);
    }
    else
    {
      DbgPrint("diskpt!StorFindMapFile: ZwFsControlFile(%ws) failed(%x)\n", SourceString, (unsigned int)v21);
    }
    return (unsigned int)v21;
  }
  else
  {
    DbgPrint("diskpt!StorFindMapFile: invalid config info(%x-%x-%x)\n", v49, v50, v51);
    ZwClose(FileHandle);
    return 3221225473LL;
  }
}


// ===== sub_28005A70C @ 0x28005a70c size=0x233 =====
int __fastcall sub_28005A70C(__int64 a1, unsigned __int8 a2, char a3, char *a4, unsigned int MaxCount, __int64 a6)
{
  __int64 v10; // rcx
  __int64 v11; // r9
  char *v12; // rdx
  __int64 v13; // rcx
  char *v14; // rcx
  int result; // eax
  unsigned int *v16; // r15
  signed __int64 v17; // r8
  signed __int64 v18; // rbx
  unsigned int v19; // esi
  struct _DEVICE_OBJECT *v20; // r10
  __int64 v21; // rbp
  union _LARGE_INTEGER *i; // r13
  signed __int64 QuadPart; // r12
  signed __int64 v24; // rcx
  ULONG v25; // r9d
  char *v26; // rdi
  unsigned int v27; // [rsp+30h] [rbp-38h]
  struct _DEVICE_OBJECT *v28; // [rsp+38h] [rbp-30h]
  unsigned int v29; // [rsp+70h] [rbp+8h]

  if ( *(_BYTE *)(a1 + 90672) == 0 )
  {
    v16 = *(unsigned int **)(a1 + 74272);
    v17 = 0;
    v18 = (unsigned int)(5 * *(_DWORD *)(a1 + 90680) + 4096) + a6;
    if ( a3 != 0 )
    {
      v19 = *(_DWORD *)(a1 + 74280);
      v18 += *(unsigned int *)(a1 + 74284);
      if ( v19 != 0 )
        v17 = *(_QWORD *)&v16[4 * v19 - 3];
    }
    else
    {
      v19 = 0;
    }
    v20 = *(struct _DEVICE_OBJECT **)(*(_QWORD *)a1 + 24LL);
    v27 = *v16;
    v28 = v20;
    if ( v19 >= *v16 )
      return 0;
    LODWORD(v21) = MaxCount;
    for ( i = (union _LARGE_INTEGER *)&v16[4 * v19 + 3]; ; i += 2 )
    {
      QuadPart = i[-1].QuadPart;
      if ( v18 < v17 )
        goto LABEL_24;
      if ( v18 + (unsigned int)v21 <= QuadPart )
        return sub_28005155C(v20, a2, a4, v21, (union _LARGE_INTEGER)(v18 + *(_QWORD *)&v16[4 * v19 + 3] - v17));
      if ( v18 >= QuadPart )
      {
LABEL_24:
        v24 = v18 + (unsigned int)v21;
        if ( v24 < v17 || v24 >= QuadPart )
          goto LABEL_29;
        v25 = v21 + v18 - v17;
        v21 = (unsigned int)(v17 - v18);
        v26 = &a4[v21];
        result = sub_28005155C(v20, a2, v26, v25, *i);
        if ( result < 0 )
          return result;
        a4 = &v26[-v21];
      }
      else
      {
        v29 = QuadPart - v18;
        result = sub_28005155C(v20, a2, a4, QuadPart - v18, (union _LARGE_INTEGER)(v18 + i->QuadPart - v17));
        if ( result < 0 )
          return result;
        a4 += v29;
        v18 += v29;
        LODWORD(v21) = v21 - v29;
      }
      v20 = v28;
LABEL_29:
      ++v19;
      v17 = QuadPart;
      if ( v19 >= v27 )
        return 0;
    }
  }
  v10 = a6 / 0x80000;
  v11 = a6 % 0x80000;
  if ( a3 != 0 )
  {
    if ( a2 == 3 )
    {
      v12 = (char *)(a6 % 0x80000 + *(_QWORD *)(a1 + 8LL * (unsigned int)v10 + 82480));
LABEL_12:
      v14 = a4;
      goto LABEL_7;
    }
    v13 = *(_QWORD *)(a1 + 8LL * (unsigned int)v10 + 82480);
  }
  else
  {
    v13 = *(_QWORD *)(a1 + 8LL * (unsigned int)v10 + 74288);
    if ( a2 == 3 )
    {
      v12 = (char *)(v11 + v13);
      goto LABEL_12;
    }
  }
  v14 = (char *)(v11 + v13);
  v12 = a4;
LABEL_7:
  memmove(v14, v12, MaxCount);
  return 0;
}


// ===== CompareRoutine @ 0x28005a948 size=0x10 =====
__int64 __fastcall CompareRoutine(struct _RTL_GENERIC_TABLE *Table, _DWORD *FirstStruct, _DWORD *SecondStruct)
{
  if ( *SecondStruct <= *FirstStruct )
    return 2 - (unsigned int)(*SecondStruct < *FirstStruct);
  else
    return 0;
}


// ===== AllocateRoutine @ 0x28005a960 size=0x3f =====
PVOID __fastcall AllocateRoutine(struct _RTL_GENERIC_TABLE *Table, CLONG ByteSize)
{
  size_t v2; // rdi
  PVOID PoolWithTag; // rax
  PVOID v4; // rbx

  v2 = ByteSize;
  PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, ByteSize, 0x63437064u);
  v4 = PoolWithTag;
  if ( PoolWithTag != nullptr )
    memset(PoolWithTag, 0, v2);
  return v4;
}


// ===== FreeRoutine @ 0x28005a9a8 size=0xf =====
void __fastcall FreeRoutine(struct _RTL_GENERIC_TABLE *Table, PVOID Buffer)
{
  ExFreePoolWithTag(Buffer, 0x63437064u);
}


// ===== sub_28005A9C0 @ 0x28005a9c0 size=0x59 =====
PVOID __fastcall sub_28005A9C0(__int64 a1, int a2, __int64 a3)
{
  PVOID result; // rax
  int Buffer; // [rsp+20h] [rbp-18h] BYREF
  __int64 v6; // [rsp+28h] [rbp-10h]
  unsigned __int8 NewElement; // [rsp+48h] [rbp+10h] BYREF

  Buffer = a2;
  v6 = a3;
  NewElement = 0;
  result = RtlInsertElementGenericTable(
             (PRTL_GENERIC_TABLE)(a1 + 72LL * (a2 & 0x3FF) + 544),
             &Buffer,
             0x10u,
             &NewElement);
  if ( result != nullptr )
    _InterlockedExchangeAdd(&dword_280074EE4, *(_DWORD *)(a1 + 56) >> 10);
  return result;
}


// ===== sub_28005AA20 @ 0x28005aa20 size=0x284 =====
int __fastcall sub_28005AA20(_QWORD *a1, __int64 a2, char a3, unsigned int a4)
{
  __int64 v4; // rsi
  int v8; // r9d
  __int64 v9; // r15
  __int64 v10; // rbx
  unsigned int *v11; // r10
  __int64 v12; // r8
  __int64 v13; // rdi
  __int64 v14; // rax
  int result; // eax
  __int64 v16; // rax
  unsigned int *v17; // rcx
  unsigned int v18; // r14d
  unsigned int v19; // eax
  unsigned int v20; // r11d
  unsigned int *v21; // rcx
  int v22; // ecx
  __int64 v23; // rax
  unsigned int v24; // ecx
  unsigned int *v25; // rdx
  unsigned __int64 v26; // r8
  unsigned int v27; // r10d
  int v28; // eax
  __int64 v29; // rdx
  unsigned int v32; // [rsp+88h] [rbp+20h]

  v4 = 0;
  v8 = 0;
  if ( a3 != 0 )
  {
    v9 = *(_QWORD *)(a2 + 528);
    v10 = a2 + 336;
    v11 = (unsigned int *)(a2 + 540);
  }
  else
  {
    v9 = *(_QWORD *)(a2 + 320);
    v10 = a2 + 128;
    v11 = (unsigned int *)(a2 + 332);
  }
  v12 = *v11;
  v32 = *(_DWORD *)(a2 + 68);
  if ( a4 < *(_DWORD *)(v10 + 24 * v12 + 8) || a4 >= *(_DWORD *)(v10 + 24 * v12 + 12) )
  {
    v16 = 0;
    v17 = (unsigned int *)(v10 + 12);
    do
    {
      if ( a4 >= *(v17 - 1) && a4 < *v17 )
      {
        v22 = dword_280074C18;
        *v11 = v16;
        v23 = 3 * v16;
        ++v22;
        v13 = a4 - *(_DWORD *)(v10 + 8 * v23 + 8);
        *(_DWORD *)(v10 + 8 * v23 + 16) = v22;
        v14 = *(_QWORD *)(v10 + 8 * v23);
        dword_280074C18 = v22;
        goto LABEL_7;
      }
      v16 = (unsigned int)(v16 + 1);
      v17 += 6;
    }
    while ( (unsigned int)v16 < 8 );
    v18 = 0;
    v19 = 0;
    v20 = -1;
    if ( (_DWORD)v12 != 0 )
    {
      v21 = (unsigned int *)(v10 + 16);
      while ( *(v21 - 2) != -1 )
      {
        if ( *v21 < v20 )
        {
          v20 = *v21;
          v18 = v19;
        }
        ++v19;
        v21 += 6;
        if ( v19 >= *v11 )
          goto LABEL_21;
      }
      v18 = v19;
    }
LABEL_21:
    if ( v19 >= (unsigned int)v12 )
    {
      v24 = v12 + 1;
      if ( (unsigned int)(v12 + 1) < 8 )
      {
        v25 = (unsigned int *)(v10 + 24LL * (int)v24 + 16);
        while ( *(v25 - 2) != -1 )
        {
          if ( *v25 < v20 )
          {
            v20 = *v25;
            v18 = v24;
          }
          ++v24;
          v25 += 6;
          if ( v24 >= 8 )
            goto LABEL_30;
        }
        v18 = v24;
      }
    }
LABEL_30:
    *v11 = v18;
    if ( *(_DWORD *)(v10 + 24LL * v18 + 8) == -1
      || (result = sub_28005A70C(
                     a2,
                     4u,
                     a3,
                     *(char **)(v10 + 24LL * v18),
                     4 * v32,
                     4LL * *(unsigned int *)(v10 + 24LL * v18 + 8)),
          v8 = result,
          result >= 0) )
    {
      v26 = (unsigned __int64)(a4 / v32) >> 3;
      v27 = v32 * (a4 / v32);
      *(_DWORD *)(v10 + 24LL * v18 + 8) = v27;
      *(_DWORD *)(v10 + 24LL * v18 + 12) = v27 + v32;
      v28 = dword_280074C18 + 1;
      *(_DWORD *)(v10 + 24LL * v18 + 16) = dword_280074C18 + 1;
      dword_280074C18 = v28;
      if ( ((unsigned __int8)(1 << ((a4 / v32) & 7)) & *(_BYTE *)(v26 + v9)) != 0 )
      {
        result = sub_28005A70C(a2, 3u, a3, *(char **)(v10 + 24LL * v18), 4 * v32, 4LL * v27);
        v8 = result;
        if ( result < 0 )
        {
          *(_DWORD *)(v10 + 24LL * v18 + 8) = -1;
          return result;
        }
      }
      else
      {
        if ( v32 != 0 )
        {
          v29 = v32;
          do
          {
            *(_DWORD *)(v4 + *(_QWORD *)(v10 + 24LL * (int)v18)) = -1;
            v4 += 4;
            --v29;
          }
          while ( v29 != 0 );
        }
        *(_BYTE *)(v26 + v9) |= 1 << ((a4 / v32) & 7);
      }
      *a1 = *(_QWORD *)(v10 + 24LL * v18) + 4LL * (a4 - *(_DWORD *)(v10 + 24LL * v18 + 8));
      return v8;
    }
  }
  else
  {
    v13 = a4 - *(_DWORD *)(v10 + 24 * v12 + 8);
    *(_DWORD *)(v10 + 24 * v12 + 16) = ++dword_280074C18;
    v14 = *(_QWORD *)(v10 + 24 * v12);
LABEL_7:
    *a1 = v14 + 4 * v13;
    return 0;
  }
  return result;
}


// ===== sub_28005ACAC @ 0x28005acac size=0x22a =====
void __fastcall sub_28005ACAC(__int64 a1, __int64 a2)
{
  __int64 *v2; // rbp
  __int64 v3; // r11
  __int64 v4; // rcx
  __int64 v5; // rsi
  __int64 v6; // rax
  __int64 v8; // r10
  __int64 v9; // r12
  __int64 v10; // rbx
  __int64 v11; // r8
  __int64 v12; // r13
  __int64 v13; // rax
  unsigned int v14; // r8d
  unsigned __int64 v15; // r9
  __int64 v16; // r8
  __int64 v17; // r9
  __int64 v18; // rax
  __int64 v19; // rbx
  __int64 v20; // r13
  int v21; // eax
  __int64 v22[17]; // [rsp+20h] [rbp-88h] BYREF
  __int64 v24; // [rsp+B8h] [rbp+10h]
  __int64 v25; // [rsp+C0h] [rbp+18h]

  v2 = *(__int64 **)(a2 + 8);
  v3 = a1;
  v4 = *(_QWORD *)(a1 + 64);
  v5 = *(_QWORD *)(v4 + 240);
  v6 = *v2;
  v8 = *(unsigned int *)(v5 + 64);
  v9 = *(unsigned int *)(v5 + 56);
  v25 = v4;
  v24 = v8;
  if ( *v2 != 0 )
  {
    while ( 1 )
    {
      v10 = v2[1];
      v11 = v6 + v10;
      if ( *(_DWORD *)(a2 + 16) == 2 )
      {
        if ( ((v10 + v8) & (unsigned int)(v9 - 1)) != 0 )
          v10 += v9;
        v12 = (v11 + v8) / v9;
        if ( (unsigned int)v12 > 8 * *(_DWORD *)(v5 + 90676) )
          goto LABEL_27;
        ExAcquireFastMutex((PFAST_MUTEX)(v5 + 72));
        v13 = (v10 + v24) / v9;
        v14 = v13;
        if ( (unsigned int)v13 < (unsigned int)v12 )
        {
          v15 = (unsigned int)v13;
          do
          {
            if ( (*(_BYTE *)((v15 >> 3) + *(_QWORD *)(v5 + 90696)) & (unsigned __int8)(1 << (v14 & 7))) == 0 )
              *(_BYTE *)((v15 >> 3) + *(_QWORD *)(v5 + 90704)) &= ~(1 << (v14 & 7));
            ++v14;
            ++v15;
          }
          while ( v14 < (unsigned int)v12 );
        }
        ExReleaseFastMutex((PFAST_MUTEX)(v5 + 72));
      }
      else
      {
        v16 = v8 + v11;
        v17 = (v10 + v8) / v9;
        v18 = v16 / v9;
        if ( (((_DWORD)v9 - 1) & (unsigned int)v16) != 0 )
          LODWORD(v18) = v18 + 1;
        if ( (unsigned int)v18 > 8 * *(_DWORD *)(v5 + 90676) )
          goto LABEL_27;
        v22[1] = 0;
        v22[0] = v3;
        if ( (unsigned int)v17 >= (unsigned int)v18 )
          goto LABEL_23;
        v19 = v9 * (unsigned int)v17 - v8;
        v20 = (unsigned int)(v18 - v17);
        do
        {
          v21 = *(_DWORD *)(*(_QWORD *)(v22[0] + 64) + 208LL);
          if ( v21 == 2 )
          {
            sub_280057AB0((__int64)v22, nullptr, v9, v19);
          }
          else if ( v21 == 3 )
          {
            sub_280058114((__int64)v22, 0, v9, v19);
          }
          v19 += v9;
          --v20;
        }
        while ( v20 != 0 );
      }
      v3 = a1;
      v8 = v24;
LABEL_23:
      v2 += 2;
      v6 = *v2;
      if ( *v2 == 0 )
      {
        v4 = v25;
        break;
      }
    }
  }
  if ( *(_DWORD *)(a2 + 16) == 1 )
    KeSetEvent((PRKEVENT)(v4 + 280), 0, 0);
LABEL_27:
  ExFreePoolWithTag(*(PVOID *)(a2 + 8), 0x74706B64u);
  IoFreeWorkItem(*(PIO_WORKITEM *)a2);
  ExFreePoolWithTag((PVOID)a2, 0x74706B64u);
}


// ===== sub_28005AEDC @ 0x28005aedc size=0x1ce =====
void __fastcall sub_28005AEDC(__int64 a1, __int64 a2)
{
  IRP *v2; // r12
  int v5; // r13d
  char v6; // r15
  __int64 v7; // rdi
  struct _IRP *MasterIrp; // rsi
  __int64 *v9; // rcx
  __int64 *PoolWithTag; // rax
  __int64 *v11; // rbp
  BOOLEAN v12; // bl
  __int64 v13; // rcx
  __int64 v14; // rax
  __int64 v15; // rcx
  __int64 *v16; // [rsp+60h] [rbp+8h]

  v2 = *(IRP **)(a2 + 8);
  v5 = -1073741823;
  v6 = *(_DWORD *)(a2 + 16) == 1;
  IoFreeWorkItem(*(PIO_WORKITEM *)a2);
  ExFreePoolWithTag((PVOID)a2, 0x74706B64u);
  v7 = *(_QWORD *)(a1 + 64);
  MasterIrp = v2->AssociatedIrp.MasterIrp;
  KeWaitForSingleObject((PVOID)(v7 + 256), Executive, 0, 0, nullptr);
  if ( *(_DWORD *)(v7 + 208) == 1 )
  {
    v9 = *(__int64 **)(v7 + 240);
    if ( v9 != nullptr )
    {
      sub_280056684(v9);
      ExFreePoolWithTag(*(PVOID *)(v7 + 240), 0x74706B64u);
      *(_QWORD *)(v7 + 240) = 0;
    }
    PoolWithTag = (__int64 *)ExAllocatePoolWithTag(NonPagedPool, 0x162B0u, 0x74706B64u);
    v11 = PoolWithTag;
    if ( PoolWithTag != nullptr )
    {
      memset(PoolWithTag, 0, 0x162B0u);
      *v11 = v7;
      *(_QWORD *)(v7 + 240) = v11;
      v12 = IoSetThreadHardErrorMode(0);
      v5 = sub_2800556EC(v11, v6);
      IoSetThreadHardErrorMode(v12);
      if ( v5 < 0 )
      {
        *(_QWORD *)(v7 + 240) = 0;
        ExFreePoolWithTag(v11, 0x74706B64u);
      }
    }
  }
  else
  {
    v11 = v16;
  }
  KeSetEvent((PRKEVENT)(v7 + 256), 0, 0);
  if ( v5 >= 0 )
  {
    v13 = *(_QWORD *)(v7 + 16);
    if ( v13 != 0 )
      sub_28005C050((PCWSTR)(*(_QWORD *)(v13 + 64) + 40LL));
    HIDWORD(MasterIrp->MdlAddress) = *(_DWORD *)(v7 + 208);
    LODWORD(MasterIrp->MdlAddress) = *(_DWORD *)(v7 + 232);
    v14 = *(_QWORD *)(v7 + 240);
    if ( v14 != 0 )
    {
      v15 = *(unsigned int *)(v14 + 90740);
      *(_QWORD *)&MasterIrp->Flags = v15;
      *(_QWORD *)&MasterIrp->Flags = v15 * *((unsigned int *)v11 + 14);
    }
    else
    {
      *(_QWORD *)&MasterIrp->Flags = 0;
    }
  }
  v2->IoStatus.Status = v5;
  v2->IoStatus.Information = 136;
  IofCompleteRequest(v2, 1);
  IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)(v7 + 176), v2, 0x20u);
}


// ===== sub_28005B0B0 @ 0x28005b0b0 size=0x132 =====
void __fastcall sub_28005B0B0(__int64 a1, __int64 a2)
{
  IRP *v2; // r12
  void *v3; // rbp
  bool v5; // si
  __int64 v7; // rbx
  struct _IRP *MasterIrp; // r13
  int v9; // eax

  v2 = *(IRP **)(a2 + 8);
  v3 = *(void **)(a2 + 24);
  v5 = *(_DWORD *)(a2 + 16) == 1;
  IoFreeWorkItem(*(PIO_WORKITEM *)a2);
  ExFreePoolWithTag((PVOID)a2, 0x74706B64u);
  v7 = *(_QWORD *)(a1 + 64);
  MasterIrp = v2->AssociatedIrp.MasterIrp;
  KeWaitForSingleObject((PVOID)(v7 + 256), Executive, 0, 0, nullptr);
  if ( v5 )
    sub_28005B1E8(*(_QWORD *)(v7 + 240), 0, v3);
  if ( v3 != nullptr )
    ObfDereferenceObject(v3);
  sub_280056684(*(__int64 **)(v7 + 240));
  ExFreePoolWithTag(*(PVOID *)(v7 + 240), 0x74706B64u);
  *(_QWORD *)(v7 + 240) = 0;
  *(_DWORD *)(v7 + 208) = 1;
  KeSetEvent((PRKEVENT)(v7 + 256), 0, 0);
  HIDWORD(MasterIrp->MdlAddress) = *(_DWORD *)(v7 + 208);
  v9 = *(_DWORD *)(v7 + 232);
  *(_QWORD *)&MasterIrp->Flags = 0;
  LODWORD(MasterIrp->MdlAddress) = v9;
  v2->IoStatus.Status = 0;
  v2->IoStatus.Information = 136;
  IofCompleteRequest(v2, 1);
  IoReleaseRemoveLockEx((PIO_REMOVE_LOCK)(v7 + 176), v2, 0x20u);
}


// ===== sub_28005B1E8 @ 0x28005b1e8 size=0x85f =====
__int64 __fastcall sub_28005B1E8(__int64 a1, char a2, struct _KEVENT *a3)
{
  SIZE_T v3; // r14
  char v5; // si
  unsigned int v7; // r12d
  __int64 v9; // rcx
  HANDLE CurrentProcessId; // rax
  unsigned int v11; // r15d
  unsigned int v12; // ebx
  unsigned int v13; // r13d
  unsigned __int64 v14; // r14
  int v15; // r13d
  _QWORD *v16; // rbx
  bool v17; // zf
  int v18; // eax
  char *v19; // rbx
  ULONG v20; // r14d
  __int64 v21; // rax
  ULONG v22; // r9d
  union _LARGE_INTEGER v23; // rsi
  __int64 v24; // r14
  _DWORD *v25; // rbx
  unsigned __int64 v26; // rbx
  int v27; // eax
  signed __int64 v28; // r9
  char v29; // cl
  __int64 v30; // r14
  char *v31; // rbx
  ULONG v32; // r9d
  __int64 v33; // rbx
  union _LARGE_INTEGER v34; // rsi
  __int64 v35; // r14
  HANDLE v36; // rax
  unsigned int v38; // [rsp+54h] [rbp-214h]
  PVOID BaseAddress; // [rsp+58h] [rbp-210h] BYREF
  unsigned int v40; // [rsp+60h] [rbp-208h]
  int v41; // [rsp+64h] [rbp-204h]
  void *SectionHandle; // [rsp+68h] [rbp-200h] BYREF
  ULONG v43; // [rsp+70h] [rbp-1F8h]
  int v44; // [rsp+74h] [rbp-1F4h]
  unsigned int v45; // [rsp+78h] [rbp-1F0h]
  PVOID P; // [rsp+80h] [rbp-1E8h]
  __int64 v47; // [rsp+88h] [rbp-1E0h]
  unsigned int v48; // [rsp+90h] [rbp-1D8h] BYREF
  signed __int64 v49; // [rsp+98h] [rbp-1D0h]
  unsigned int Buffer; // [rsp+A0h] [rbp-1C8h] BYREF
  ULONG_PTR ViewSize; // [rsp+A8h] [rbp-1C0h] BYREF
  PVOID v52; // [rsp+B0h] [rbp-1B8h]
  _DWORD *v53; // [rsp+B8h] [rbp-1B0h] BYREF
  PFAST_MUTEX FastMutex; // [rsp+C0h] [rbp-1A8h]
  unsigned int *v55; // [rsp+C8h] [rbp-1A0h] BYREF
  _DWORD *v56; // [rsp+D0h] [rbp-198h] BYREF
  _DWORD *v57; // [rsp+D8h] [rbp-190h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+E0h] [rbp-188h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+110h] [rbp-158h] BYREF
  char Dest[256]; // [rsp+120h] [rbp-148h] BYREF

  v3 = *(unsigned int *)(a1 + 56);
  v5 = a2;
  v7 = 0;
  v47 = *(_QWORD *)a1;
  v43 = v3;
  SectionHandle = nullptr;
  BaseAddress = nullptr;
  v49 = v3;
  P = ExAllocatePoolWithTag(NonPagedPool, v3, 0x74706B64u);
  if ( P == nullptr )
    return 3221225626LL;
  if ( v5 != 0 )
  {
    if ( byte_280074E94 == 0 )
    {
      byte_280074E94 = 1;
      if ( (unsigned __int8)qword_280074B70() != 0 )
      {
        if ( qword_280074BB0 != nullptr )
        {
          LOBYTE(v9) = 1;
          qword_280074BB0(v9);
        }
        if ( qword_280074B78 != nullptr )
          qword_280074B78();
        if ( qword_280074BA8 != nullptr )
          qword_280074BA8();
        if ( qword_280074B88 != nullptr )
          qword_280074B88(0);
        if ( qword_280074BB8 != nullptr )
        {
          LOBYTE(v9) = 1;
          qword_280074BB8(v9);
        }
      }
      qword_280074BC0(
        "\n"
        " Shadow Defender is committing changes. When this operation\n"
        " completes, your computer will restart or shutdown. Please wait...\n");
    }
    sprintf(Dest, "\n Committing %c: ...\n", (char *)&a3[2].Header.WaitListHead.Blink + 3);
    qword_280074BC0(Dest);
  }
  else if ( a3 != nullptr )
  {
    RtlInitUnicodeString(&DestinationString, L"\\BaseNamedObjects\\ShadowDefenderSharedMemory");
    ObjectAttributes.ObjectName = &DestinationString;
    ObjectAttributes.Length = 48;
    ObjectAttributes.RootDirectory = nullptr;
    ObjectAttributes.Attributes = 64;
    ObjectAttributes.SecurityDescriptor = nullptr;
    ObjectAttributes.SecurityQualityOfService = nullptr;
    if ( ZwOpenSection(&SectionHandle, 0xF001Fu, &ObjectAttributes) >= 0 )
    {
      ViewSize = 4096;
      if ( ZwMapViewOfSection(
             SectionHandle,
             (HANDLE)0xFFFFFFFFFFFFFFFFLL,
             &BaseAddress,
             0,
             0x1000u,
             nullptr,
             &ViewSize,
             ViewUnmap,
             0,
             4u) >= 0 )
      {
        if ( ViewSize >= 4 )
          goto LABEL_26;
        CurrentProcessId = PsGetCurrentProcessId();
        ZwUnmapViewOfSection(CurrentProcessId, BaseAddress);
      }
      BaseAddress = nullptr;
      ZwClose(SectionHandle);
    }
    else
    {
      BaseAddress = nullptr;
    }
    SectionHandle = nullptr;
  }
LABEL_26:
  FastMutex = (PFAST_MUTEX)(a1 + 72);
  ExAcquireFastMutex((PFAST_MUTEX)(a1 + 72));
  *(_DWORD *)(a1 + 32) = 1;
  v11 = 0;
  v12 = 0;
  do
  {
    if ( ((unsigned __int8)(1 << (v12 & 7)) & *(_BYTE *)(((unsigned __int64)v12 >> 3) + *(_QWORD *)(a1 + 90696))) != 0 )
    {
      Buffer = v12;
      if ( RtlLookupElementGenericTable((PRTL_GENERIC_TABLE)(a1 + 72LL * (v12 & 0x3FF) + 544), &Buffer) != nullptr
        || sub_28005AA20(&v57, a1, 0, v12) >= 0 && *v57 != -1 )
      {
        ++v11;
      }
    }
    ++v12;
  }
  while ( v12 <= *(_DWORD *)(a1 + 90728) );
  v41 = 0;
  v13 = 0;
  v38 = 0;
  v45 = 0;
  if ( v5 != 0 )
  {
    qword_280074BC0(" 0 percent completed.");
  }
  else if ( a3 != nullptr && BaseAddress != nullptr )
  {
    *(_DWORD *)BaseAddress = 0;
    KeSetEvent(a3, 0, 0);
  }
  if ( v11 != 0 )
  {
    while ( 1 )
    {
      v40 = 100 * v13;
      do
      {
        v14 = (unsigned __int64)v7 >> 3;
        v44 = v7 & 7;
        v15 = 1 << v44;
        if ( ((unsigned __int8)(1 << v44) & *(_BYTE *)(v14 + *(_QWORD *)(a1 + 90696))) == 0 )
        {
LABEL_80:
          v13 = v38;
          goto LABEL_81;
        }
        v48 = v7;
        v16 = RtlLookupElementGenericTable((PRTL_GENERIC_TABLE)(a1 + 72LL * (v7 & 0x3FF) + 544), &v48);
        v52 = v16;
        if ( v16 != nullptr )
        {
          v17 = ((unsigned __int8)v15 & *(_BYTE *)(v14 + *(_QWORD *)(a1 + 90720))) == 0;
          v13 = v38;
          if ( v17 )
          {
            v13 = ++v38;
            v40 += 100;
            v18 = v40 / v11;
            if ( v41 != v40 / v11 )
            {
              v41 = v40 / v11;
              if ( a2 != 0 )
              {
                sprintf(Dest, "\r %d percent completed.", v18);
                qword_280074BC0(Dest);
              }
              else if ( a3 != nullptr && BaseAddress != nullptr )
              {
                *(_DWORD *)BaseAddress = v18;
                KeSetEvent(a3, 0, 0);
              }
            }
            *(_BYTE *)(v14 + *(_QWORD *)(a1 + 90688)) |= 1 << v44;
            v19 = (char *)v16[1];
            v20 = v43;
            if ( *(_BYTE *)(a1 + 90760) != 0 )
              sub_28005E600(a1, v19, v43);
            v21 = *(unsigned int *)(a1 + 64);
            v22 = v20;
            if ( v7 != 0 )
            {
              v23.QuadPart = v20 * (unsigned __int64)v7 - v21;
            }
            else
            {
              v23.QuadPart = 0;
              v22 = v20 - v21;
              v19 += v21;
            }
            v24 = v47;
            if ( sub_28005155C(*(PDEVICE_OBJECT *)(v47 + 24), 4u, v19, v22, v23) < 0
              && *(_QWORD *)(a1 + 40) - v23.QuadPart < v49 )
            {
              sub_28005155C(*(PDEVICE_OBJECT *)(v24 + 24), 4u, v19, *(_DWORD *)(a1 + 40) - v23.LowPart, v23);
            }
            v25 = v52;
            MmFreeContiguousMemory(*((PVOID *)v52 + 1));
            RtlDeleteElementGenericTable((PRTL_GENERIC_TABLE)(a1 + 72LL * (*v25 & 0x3FF) + 544), v25);
            _InterlockedExchangeAdd(&dword_280074EE4, -(*(_DWORD *)(a1 + 56) >> 10));
          }
        }
        else
        {
          if ( sub_28005AA20(&v55, a1, 0, v7) < 0 )
            goto LABEL_80;
          v26 = *v55;
          if ( (_DWORD)v26 == -1 )
            goto LABEL_80;
          v17 = ((unsigned __int8)v15 & *(_BYTE *)(v14 + *(_QWORD *)(a1 + 90720))) == 0;
          v13 = v38;
          if ( v17 )
          {
            v13 = ++v38;
            v40 += 100;
            v27 = v40 / v11;
            if ( v41 != v40 / v11 )
            {
              v41 = v40 / v11;
              if ( a2 != 0 )
              {
                sprintf(Dest, "\r %d percent completed.", v27);
                qword_280074BC0(Dest);
              }
              else if ( a3 != nullptr && BaseAddress != nullptr )
              {
                *(_DWORD *)BaseAddress = v27;
                KeSetEvent(a3, 0, 0);
              }
            }
            if ( sub_28005AA20(&v56, a1, 0, v7) >= 0 )
              *v56 = -1;
            if ( sub_28005AA20(&v53, a1, 1, v26) >= 0 )
              *v53 = -1;
            v28 = v49 * v26;
            v29 = v44;
            *(_BYTE *)((v26 >> 3) + *(_QWORD *)(a1 + 90720)) &= ~(1 << (v26 & 7));
            *(_BYTE *)(v14 + *(_QWORD *)(a1 + 90688)) |= 1 << v29;
            v30 = v43;
            v31 = (char *)P;
            if ( sub_28005155C(
                   *(PDEVICE_OBJECT *)(v47 + 24),
                   3u,
                   P,
                   v43,
                   (union _LARGE_INTEGER)(v28 - *(unsigned int *)(a1 + 64))) >= 0 )
            {
              if ( *(_BYTE *)(a1 + 90760) != 0 )
                sub_28005E600(a1, v31, (unsigned int)v30);
              v32 = v30;
              if ( v7 != 0 )
              {
                v34.QuadPart = v30 * v7 - *(unsigned int *)(a1 + 64);
              }
              else
              {
                v33 = *(unsigned int *)(a1 + 64);
                v34.QuadPart = 0;
                v32 = v30 - v33;
                v31 = (char *)P + v33;
              }
              v35 = v47;
              if ( sub_28005155C(*(PDEVICE_OBJECT *)(v47 + 24), 4u, v31, v32, v34) < 0
                && *(_QWORD *)(a1 + 40) - v34.QuadPart < v49 )
              {
                sub_28005155C(*(PDEVICE_OBJECT *)(v35 + 24), 4u, v31, *(_DWORD *)(a1 + 40) - v34.LowPart, v34);
              }
            }
          }
        }
LABEL_81:
        ++v7;
      }
      while ( v7 <= *(_DWORD *)(a1 + 90728) );
      if ( v45 != v13 )
      {
        v45 = v13;
        v7 = 0;
        if ( v13 < v11 )
          continue;
      }
      v5 = a2;
      break;
    }
  }
  ExReleaseFastMutex(FastMutex);
  ExFreePoolWithTag(P, 0x74706B64u);
  if ( v5 == 0 )
  {
    if ( a3 != nullptr )
    {
      if ( BaseAddress == nullptr )
      {
LABEL_92:
        if ( SectionHandle != nullptr )
          ZwClose(SectionHandle);
        return 0;
      }
      *(_DWORD *)BaseAddress = 100;
      KeSetEvent(a3, 0, 0);
    }
    if ( BaseAddress != nullptr )
    {
      v36 = PsGetCurrentProcessId();
      ZwUnmapViewOfSection(v36, BaseAddress);
    }
    goto LABEL_92;
  }
  strcpy(Dest, "\r 100 percent completed.\n");
  qword_280074BC0(Dest);
  return 0;
}


// ===== sub_28005BA50 @ 0x28005ba50 size=0x1ff =====
NTSTATUS __fastcall sub_28005BA50(PCWSTR SourceString)
{
  NTSTATUS result; // eax
  NTSTATUS Status; // ebx
  struct _DEVICE_OBJECT *RelatedDeviceObject; // rbx
  PIRP v4; // rdx
  struct _KTHREAD *CurrentThread; // rax
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rcx
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+60h] [rbp-78h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+70h] [rbp-68h] BYREF
  struct _KEVENT Event; // [rsp+80h] [rbp-58h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+98h] [rbp-40h] BYREF
  PVOID Object; // [rsp+E8h] [rbp+10h] BYREF
  void *FileHandle; // [rsp+F0h] [rbp+18h] BYREF

  RtlInitUnicodeString(&DestinationString, SourceString);
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  result = ZwCreateFile(
             &FileHandle,
             0x100001u,
             &ObjectAttributes,
             &IoStatusBlock,
             nullptr,
             0x80u,
             3u,
             1u,
             0x20u,
             nullptr,
             0);
  if ( result >= 0 )
  {
    Status = ObReferenceObjectByHandle(FileHandle, 0x80u, nullptr, 0, &Object, nullptr);
    if ( Status >= 0 )
    {
      RelatedDeviceObject = IoGetRelatedDeviceObject((PFILE_OBJECT)Object);
      if ( RelatedDeviceObject != nullptr )
      {
        KeInitializeEvent(&Event, NotificationEvent, 0);
        v4 = IoBuildDeviceIoControlRequest(
               0x53C000u,
               RelatedDeviceObject,
               nullptr,
               0,
               nullptr,
               0,
               0,
               &Event,
               &IoStatusBlock);
        if ( v4 != nullptr )
        {
          CurrentThread = KeGetCurrentThread();
          CurrentStackLocation = v4->Tail.Overlay.CurrentStackLocation;
          v4->RequestorMode = 0;
          v4->Tail.Overlay.Thread = CurrentThread;
          CurrentStackLocation[-1].FileObject = (PFILE_OBJECT)Object;
          Status = IofCallDriver(RelatedDeviceObject, v4);
          if ( Status == 259 )
          {
            KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
            Status = IoStatusBlock.Status;
          }
          ObfDereferenceObject(Object);
        }
        else
        {
          ObfDereferenceObject(Object);
          Status = -1073741670;
        }
      }
      else
      {
        ObfDereferenceObject(Object);
        Status = -1073741811;
      }
    }
    ZwClose(FileHandle);
    return Status;
  }
  return result;
}


// ===== sub_28005BC58 @ 0x28005bc58 size=0x1f4 =====
NTSTATUS __fastcall sub_28005BC58(PCWSTR SourceString)
{
  NTSTATUS result; // eax
  NTSTATUS Status; // ebx
  struct _DEVICE_OBJECT *RelatedDeviceObject; // rbx
  PIRP v4; // rdx
  struct _KTHREAD *CurrentThread; // rax
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rcx
  struct _FILE_OBJECT *v7; // rax
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+60h] [rbp-78h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+70h] [rbp-68h] BYREF
  struct _KEVENT Event; // [rsp+80h] [rbp-58h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+98h] [rbp-40h] BYREF
  PVOID Object; // [rsp+E8h] [rbp+10h] BYREF
  void *FileHandle; // [rsp+F0h] [rbp+18h] BYREF

  RtlInitUnicodeString(&DestinationString, SourceString);
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &DestinationString;
  result = ZwCreateFile(
             &FileHandle,
             0x100080u,
             &ObjectAttributes,
             &IoStatusBlock,
             nullptr,
             0x80u,
             3u,
             1u,
             0x20u,
             nullptr,
             0);
  if ( result >= 0 )
  {
    Status = ObReferenceObjectByHandle(FileHandle, 0x80u, nullptr, 0, &Object, nullptr);
    if ( Status >= 0 )
    {
      RelatedDeviceObject = IoGetRelatedDeviceObject((PFILE_OBJECT)Object);
      if ( RelatedDeviceObject != nullptr )
      {
        KeInitializeEvent(&Event, NotificationEvent, 0);
        v4 = IoBuildSynchronousFsdRequest(9u, RelatedDeviceObject, nullptr, 0, nullptr, &Event, &IoStatusBlock);
        if ( v4 != nullptr )
        {
          CurrentThread = KeGetCurrentThread();
          CurrentStackLocation = v4->Tail.Overlay.CurrentStackLocation;
          v4->RequestorMode = 0;
          v4->Tail.Overlay.Thread = CurrentThread;
          v7 = (struct _FILE_OBJECT *)Object;
          CurrentStackLocation[-1].MajorFunction = 9;
          CurrentStackLocation[-1].FileObject = v7;
          Status = IofCallDriver(RelatedDeviceObject, v4);
          if ( Status == 259 )
          {
            KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
            Status = IoStatusBlock.Status;
          }
          ObfDereferenceObject(Object);
        }
        else
        {
          ObfDereferenceObject(Object);
          Status = -1073741670;
        }
      }
      else
      {
        ObfDereferenceObject(Object);
        Status = -1073741811;
      }
    }
    ZwClose(FileHandle);
    return Status;
  }
  return result;
}


// ===== sub_28005BE54 @ 0x28005be54 size=0x1f4 =====
NTSTATUS __fastcall sub_28005BE54(PCWSTR SourceString)
{
  NTSTATUS result; // eax
  NTSTATUS Status; // ebx
  struct _DEVICE_OBJECT *RelatedDeviceObject; // rbx
  PIRP v4; // rdx
  struct _KTHREAD *CurrentThread; // rax
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rcx
  struct _FILE_OBJECT *v7; // rax
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+60h] [rbp-78h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+70h] [rbp-68h] BYREF
  struct _KEVENT Event; // [rsp+80h] [rbp-58h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+98h] [rbp-40h] BYREF
  PVOID Object; // [rsp+E8h] [rbp+10h] BYREF
  void *FileHandle; // [rsp+F0h] [rbp+18h] BYREF

  RtlInitUnicodeString(&DestinationString, SourceString);
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &DestinationString;
  result = ZwCreateFile(
             &FileHandle,
             0x100001u,
             &ObjectAttributes,
             &IoStatusBlock,
             nullptr,
             0x80u,
             3u,
             1u,
             0x20u,
             nullptr,
             0);
  if ( result >= 0 )
  {
    Status = ObReferenceObjectByHandle(FileHandle, 0x80u, nullptr, 0, &Object, nullptr);
    if ( Status >= 0 )
    {
      RelatedDeviceObject = IoGetRelatedDeviceObject((PFILE_OBJECT)Object);
      if ( RelatedDeviceObject != nullptr )
      {
        KeInitializeEvent(&Event, NotificationEvent, 0);
        v4 = IoBuildSynchronousFsdRequest(9u, RelatedDeviceObject, nullptr, 0, nullptr, &Event, &IoStatusBlock);
        if ( v4 != nullptr )
        {
          CurrentThread = KeGetCurrentThread();
          CurrentStackLocation = v4->Tail.Overlay.CurrentStackLocation;
          v4->RequestorMode = 0;
          v4->Tail.Overlay.Thread = CurrentThread;
          v7 = (struct _FILE_OBJECT *)Object;
          CurrentStackLocation[-1].MajorFunction = 9;
          CurrentStackLocation[-1].FileObject = v7;
          Status = IofCallDriver(RelatedDeviceObject, v4);
          if ( Status == 259 )
          {
            KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
            Status = IoStatusBlock.Status;
          }
          ObfDereferenceObject(Object);
        }
        else
        {
          ObfDereferenceObject(Object);
          Status = -1073741670;
        }
      }
      else
      {
        ObfDereferenceObject(Object);
        Status = -1073741811;
      }
    }
    ZwClose(FileHandle);
    return Status;
  }
  return result;
}


// ===== sub_28005C050 @ 0x28005c050 size=0x12a =====
NTSTATUS __fastcall sub_28005C050(PCWSTR SourceString)
{
  NTSTATUS result; // eax
  NTSTATUS v2; // ebx
  struct _UNICODE_STRING Destination; // [rsp+60h] [rbp-288h] BYREF
  void *FileHandle; // [rsp+70h] [rbp-278h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+78h] [rbp-270h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+A8h] [rbp-240h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+B8h] [rbp-230h] BYREF
  char v8; // [rsp+D0h] [rbp-218h] BYREF

  RtlInitUnicodeString(&DestinationString, SourceString);
  Destination.MaximumLength = 512;
  Destination.Buffer = (PWSTR)&v8;
  Destination.Length = 0;
  RtlCopyUnicodeString(&Destination, &DestinationString);
  RtlAppendUnicodeToString(&Destination, &Source);
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &Destination;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  result = ZwCreateFile(
             &FileHandle,
             0x100080u,
             &ObjectAttributes,
             &IoStatusBlock,
             nullptr,
             0x80u,
             3u,
             1u,
             0x20u,
             nullptr,
             0);
  v2 = result;
  if ( result >= 0 )
  {
    ZwClose(FileHandle);
    return v2;
  }
  return result;
}


// ===== sub_28005C180 @ 0x28005c180 size=0xa2 =====
void __fastcall sub_28005C180(__int64 a1)
{
  unsigned int v1; // esi
  __int64 i; // rdi

  v1 = *(_DWORD *)(a1 + 90744);
  if ( v1 < dword_280074600
    && (signed __int64)(*(unsigned int *)(a1 + 56) * (unsigned __int64)*(unsigned int *)(a1 + 90740)) < *(_QWORD *)(a1 + 90752) )
  {
    ExAcquireFastMutex(&stru_280075620);
    for ( i = qword_280075700; (__int64 *)i != &qword_280075700; i = *(_QWORD *)i )
    {
      if ( v1 < *(_DWORD *)(i + 32) )
      {
        *(_DWORD *)(a1 + 90744) = dword_280074600;
        KeSetEvent(*(PRKEVENT *)(i + 24), 0, 0);
      }
    }
    ExReleaseFastMutex(&stru_280075620);
  }
}


// ===== sub_28005C228 @ 0x28005c228 size=0x10b =====
NTSTATUS __fastcall sub_28005C228(struct _DEVICE_OBJECT *a1, IRP *a2)
{
  __int64 (*v4)(void); // rax
  PDEVICE_OBJECT i; // rbx
  struct _DEVICE_OBJECT *AttachedDevice; // rax

  if ( a2->Tail.Overlay.CurrentStackLocation->Parameters.Read.ByteOffset.LowPart != 5488640 || KeGetCurrentIrql() >= 2u )
  {
    v4 = (__int64 (*)(void))qword_280074D28;
    if ( qword_280074D28 == 0 )
    {
      a2->IoStatus.Status = -1073741808;
LABEL_5:
      IofCompleteRequest(a2, 0);
      return -1073741808;
    }
    return v4();
  }
  ExAcquireFastMutex(&stru_280075760);
  for ( i = DriverObject->DeviceObject; i != nullptr; i = i->NextDevice )
  {
    if ( i != DeviceObject && *(_DWORD *)i->DeviceExtension == 7680402 )
    {
      AttachedDevice = i->AttachedDevice;
      if ( AttachedDevice != nullptr )
      {
        do
        {
          if ( AttachedDevice == a1 )
            break;
          AttachedDevice = AttachedDevice->AttachedDevice;
        }
        while ( AttachedDevice != nullptr );
        if ( AttachedDevice != nullptr )
          break;
      }
    }
  }
  ExReleaseFastMutex(&stru_280075760);
  if ( i == nullptr )
  {
    v4 = (__int64 (*)(void))qword_280074D28;
    if ( qword_280074D28 == 0 )
    {
      a2->IoStatus.Status = -1073741808;
      goto LABEL_5;
    }
    return v4();
  }
  ++a2->CurrentLocation;
  ++a2->Tail.Overlay.CurrentStackLocation;
  return IofCallDriver(i, a2);
}


// ===== sub_28005C33C @ 0x28005c33c size=0x132 =====
char __fastcall sub_28005C33C(__int64 a1, char a2, __int64 a3)
{
  __int64 v6; // rdi
  char v7; // bl
  KIRQL v8; // al
  bool v9; // zf
  KIRQL v10; // si
  volatile __int64 *v11; // r11
  __int64 v12; // rax
  UNICODE_STRING String2; // [rsp+20h] [rbp-18h] BYREF

  RtlInitUnicodeString(&String2, L"\\Driver\\volsnap");
  v6 = *(_QWORD *)(a1 + 24);
  v7 = 0;
  if ( v6 != 0 )
  {
    do
    {
      if ( RtlEqualUnicodeString((PCUNICODE_STRING)(*(_QWORD *)(v6 + 8) + 56LL), &String2, 1u) != 0 )
        break;
      v6 = *(_QWORD *)(v6 + 24);
    }
    while ( v6 != 0 );
    if ( v6 != 0 )
    {
      v8 = KeAcquireSpinLockRaiseToDpc(&SpinLock);
      v9 = a2 == 0;
      v10 = v8;
      if ( v9 )
      {
        if ( --dword_280074D24 == 0 )
        {
          _InterlockedExchange64((volatile __int64 *)(*(_QWORD *)(v6 + 8) + 224LL), a3);
          ObfDereferenceObject(*(PVOID *)(v6 + 8));
        }
      }
      else if ( ++dword_280074D24 == 1 )
      {
        ObfReferenceObject(*(PVOID *)(v6 + 8));
        v11 = *(volatile __int64 **)(v6 + 8);
        if ( sub_28005C228 == *((NTSTATUS (__fastcall **)(struct _DEVICE_OBJECT *, IRP *))v11 + 28) )
        {
          v12 = qword_280074D28;
        }
        else
        {
          v12 = *((_QWORD *)v11 + 28);
          qword_280074D28 = v12;
        }
        if ( v12 == 0 )
        {
          ObfDereferenceObject((PVOID)v11);
          --dword_280074D24;
LABEL_16:
          KeReleaseSpinLock(&SpinLock, v10);
          return v7;
        }
        _InterlockedExchange64(v11 + 28, (__int64)sub_28005C228);
      }
      v7 = 1;
      goto LABEL_16;
    }
  }
  return 0;
}


// ===== sub_28005C474 @ 0x28005c474 size=0x347 =====
__int64 __fastcall sub_28005C474(__int64 a1, IRP *a2)
{
  IRP *v2; // rdi
  __int64 v3; // rsi
  __int64 v5; // rbx
  __int64 v6; // rbx
  unsigned __int64 v7; // r11
  __int64 *v8; // rcx
  __int64 *v9; // r8
  unsigned __int64 v10; // r10
  unsigned __int64 v11; // rdx
  __int64 *v12; // rbx
  unsigned __int64 v13; // rax
  __int64 *v14; // rcx
  __int64 *v15; // r9
  bool i; // cf
  __int64 *v17; // rax
  __int64 *v18; // rcx
  bool j; // cf
  char *DriverStart; // r10
  char *v21; // rdx
  __int64 *v22; // rax
  __int64 *v23; // rcx
  bool k; // cf
  __int64 *v25; // rdx
  __int64 *v26; // rax
  bool m; // cf
  __int64 *v28; // rdx
  __int64 *v29; // rax
  bool n; // cf
  __int64 *v31; // rdx
  __int64 *v32; // rax
  bool ii; // cf
  __int64 v34; // [rsp+48h] [rbp+10h] BYREF
  __int64 v35; // [rsp+50h] [rbp+18h] BYREF
  __int64 *v36; // [rsp+58h] [rbp+20h] BYREF

  v2 = a2;
  v3 = a1;
  if ( a2->Tail.Overlay.CurrentStackLocation->MajorFunction != 4 )
    return qword_280074D60();
  if ( dword_280074A20 == 0 || KeGetCurrentIrql() >= 2u || a1 != qword_280074D30 || *(char *)(a1 + 48) < 0 )
    return qword_280074D68(a1, a2);
  v5 = *(_QWORD *)(a1 + 24);
  if ( v5 == 0 )
    return sub_2800B7DE9();
  v6 = *(_QWORD *)(v5 + 8);
  v7 = qword_280074BF8();
  v8 = &v34;
  if ( &v36 >= (__int64 **)&v34 )
    v8 = (__int64 *)&v36;
  v9 = &v35;
  if ( v8 >= &v35 )
    v9 = v8;
  v36 = v9;
  v10 = *(_QWORD *)(v6 + 24);
  v34 = v10;
  v11 = v10 + *(unsigned int *)(v6 + 32);
  v35 = v11;
  if ( v10 == 0 || v11 == 0 )
  {
LABEL_28:
    a1 = v3;
    a2 = v2;
    return qword_280074D68(a1, a2);
  }
  v12 = v9 + 256;
  v13 = v7;
  v14 = (__int64 *)((char *)v9 + qword_280074528);
  if ( v7 > (unsigned __int64)(v9 + 256) )
    v13 = (unsigned __int64)(v9 + 256);
  if ( v14 > v9 && (unsigned __int64)v14 < v13 && *v14 > v10 && *v14 < v11 )
  {
LABEL_27:
    qword_280074528 = (char *)v14 - (char *)v9;
    goto LABEL_28;
  }
  v15 = v9 + 1;
  v14 = v9 + 1;
  for ( i = (unsigned __int64)(v9 + 1) < v13; i; i = (unsigned __int64)v14 < v13 )
  {
    if ( *v14 > v10 && *v14 < v11 )
      goto LABEL_27;
    ++v14;
  }
  v34 = qword_280074E58;
  v35 = qword_280074E60;
  if ( qword_280074E58 == 0 || qword_280074E60 == 0 )
    goto LABEL_28;
  v17 = (__int64 *)v7;
  v18 = (__int64 *)((char *)v9 + qword_280074530);
  if ( v7 > (unsigned __int64)v12 )
    v17 = v9 + 256;
  if ( v18 > v9 && v18 < v17 && *v18 > (unsigned __int64)qword_280074E58 && *v18 < (unsigned __int64)qword_280074E60 )
  {
LABEL_43:
    qword_280074530 = (char *)v18 - (char *)v9;
    goto LABEL_28;
  }
  v18 = v9 + 1;
  for ( j = v15 < v17; j; j = v18 < v17 )
  {
    if ( *v18 > (unsigned __int64)qword_280074E58 && *v18 < (unsigned __int64)qword_280074E60 )
      goto LABEL_43;
    ++v18;
  }
  DriverStart = (char *)DriverObject->DriverStart;
  v34 = (__int64)DriverStart;
  v21 = &DriverStart[DriverObject->DriverSize];
  v35 = (__int64)v21;
  if ( DriverStart == nullptr || v21 == nullptr )
    goto LABEL_28;
  v22 = (__int64 *)v7;
  v23 = (__int64 *)((char *)v9 + qword_280074538);
  if ( v7 > (unsigned __int64)v12 )
    v22 = v9 + 256;
  if ( v23 > v9 && v23 < v22 && *v23 > (unsigned __int64)DriverStart && *v23 < (unsigned __int64)v21 )
  {
LABEL_57:
    qword_280074538 = (char *)v23 - (char *)v9;
    goto LABEL_28;
  }
  v23 = v9 + 1;
  for ( k = v15 < v22; k; k = v23 < v22 )
  {
    if ( *v23 > (unsigned __int64)DriverStart && *v23 < (unsigned __int64)v21 )
      goto LABEL_57;
    ++v23;
  }
  if ( qword_280074BD8 != 0 )
  {
    v25 = (__int64 *)v7;
    if ( v7 > (unsigned __int64)v12 )
      v25 = v9 + 256;
    v26 = v9 + 1;
    for ( m = v15 < v25; m; m = v26 < v25 )
    {
      if ( *v26 > (unsigned __int64)qword_280074BD8 && *v26 < (unsigned __int64)(qword_280074BD8 + 4096) )
        goto LABEL_28;
      ++v26;
    }
  }
  if ( qword_280074BE0 != 0 )
  {
    v28 = (__int64 *)v7;
    if ( v7 > (unsigned __int64)v12 )
      v28 = v9 + 256;
    v29 = v9 + 1;
    for ( n = v15 < v28; n; n = v29 < v28 )
    {
      if ( *v29 > (unsigned __int64)qword_280074BE0 && *v29 < (unsigned __int64)(qword_280074BE0 + 4096) )
        goto LABEL_28;
      ++v29;
    }
  }
  if ( qword_280074BE8 != 0 )
  {
    v31 = (__int64 *)v7;
    if ( v7 > (unsigned __int64)v12 )
      v31 = v9 + 256;
    v32 = v9 + 1;
    for ( ii = v15 < v31; ii; ii = v32 < v31 )
    {
      if ( *v32 > (unsigned __int64)qword_280074BE8 && *v32 < (unsigned __int64)(qword_280074BE8 + 4096) )
        goto LABEL_28;
      ++v32;
    }
  }
  if ( qword_280074BF0 != 0 )
  {
    if ( v7 > (unsigned __int64)v12 )
      v7 = (unsigned __int64)(v9 + 256);
    while ( (unsigned __int64)v15 < v7 )
    {
      if ( *v15 > (unsigned __int64)qword_280074BF0 && *v15 < (unsigned __int64)(qword_280074BF0 + 4096) )
        goto LABEL_28;
      ++v15;
    }
  }
  qword_280074BC8(3);
  v2->IoStatus.Information = 0;
  v2->IoStatus.Status = -1073741790;
  IofCompleteRequest(v2, 0);
  return 3221225506LL;
}


// ===== sub_28005C7C4 @ 0x28005c7c4 size=0x276 =====
__int64 __fastcall sub_28005C7C4(__int64 a1, IRP *a2)
{
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  IRP *v4; // rdi
  PIO_SECURITY_CONTEXT SecurityContext; // rcx
  char SecurityQos; // al
  __int64 v7; // rbx
  __int64 v8; // rbx
  unsigned __int64 v9; // r11
  __int64 *v10; // rcx
  __int64 *v11; // r8
  unsigned __int64 v12; // r9
  unsigned __int64 v13; // rdx
  __int64 *v14; // r10
  unsigned __int64 v15; // rax
  __int64 *v16; // rcx
  __int64 *v17; // rbx
  bool i; // cf
  __int64 *v19; // rax
  __int64 *v20; // rcx
  bool j; // cf
  char *DriverStart; // r9
  char *v23; // rdx
  __int64 *v24; // rcx
  bool k; // cf
  __int64 v27; // [rsp+48h] [rbp+10h] BYREF
  __int64 v28; // [rsp+50h] [rbp+18h] BYREF
  __int64 *v29; // [rsp+58h] [rbp+20h] BYREF

  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  v4 = a2;
  SecurityContext = CurrentStackLocation->Parameters.Create.SecurityContext;
  if ( CurrentStackLocation->MajorFunction != 15 )
    return qword_280074D70(a1, a2);
  if ( dword_280074A20 == 0 )
    return qword_280074D70(a1, a2);
  if ( KeGetCurrentIrql() >= 2u )
    return qword_280074D70(a1, a2);
  if ( a1 != qword_280074D30 )
    return qword_280074D70(a1, a2);
  if ( *(char *)(a1 + 48) < 0 )
    return qword_280074D70(a1, a2);
  if ( SecurityContext == nullptr )
    return qword_280074D70(a1, a2);
  SecurityQos = (char)SecurityContext[3].SecurityQos;
  if ( SecurityQos != 42 && SecurityQos != 10 && SecurityQos != -86 && SecurityQos != -118 )
    return qword_280074D70(a1, a2);
  v7 = *(_QWORD *)(a1 + 24);
  if ( v7 == 0 )
    return sub_2800B7DE9();
  v8 = *(_QWORD *)(v7 + 8);
  v9 = qword_280074BF8();
  v10 = &v27;
  if ( &v29 >= (__int64 **)&v27 )
    v10 = (__int64 *)&v29;
  v11 = &v28;
  if ( v10 >= &v28 )
    v11 = v10;
  v29 = v11;
  v12 = *(_QWORD *)(v8 + 24);
  v27 = v12;
  v13 = v12 + *(unsigned int *)(v8 + 32);
  v28 = v13;
  if ( v12 == 0 || v13 == 0 )
  {
LABEL_32:
    a2 = v4;
    return qword_280074D70(a1, a2);
  }
  v14 = v11 + 256;
  v15 = v9;
  v16 = (__int64 *)((char *)v11 + qword_280074540);
  if ( v9 > (unsigned __int64)(v11 + 256) )
    v15 = (unsigned __int64)(v11 + 256);
  if ( v16 > v11 && (unsigned __int64)v16 < v15 && *v16 > v12 && *v16 < v13 )
  {
LABEL_31:
    qword_280074540 = (char *)v16 - (char *)v11;
    goto LABEL_32;
  }
  v17 = v11 + 1;
  v16 = v11 + 1;
  for ( i = (unsigned __int64)(v11 + 1) < v15; i; i = (unsigned __int64)v16 < v15 )
  {
    if ( *v16 > v12 && *v16 < v13 )
      goto LABEL_31;
    ++v16;
  }
  v27 = qword_280074E58;
  v28 = qword_280074E60;
  if ( qword_280074E58 == 0 || qword_280074E60 == 0 )
    goto LABEL_32;
  v19 = (__int64 *)v9;
  v20 = (__int64 *)((char *)v11 + qword_280074548);
  if ( v9 > (unsigned __int64)v14 )
    v19 = v11 + 256;
  if ( v20 > v11 && v20 < v19 && *v20 > (unsigned __int64)qword_280074E58 && *v20 < (unsigned __int64)qword_280074E60 )
  {
LABEL_47:
    qword_280074548 = (char *)v20 - (char *)v11;
    goto LABEL_32;
  }
  v20 = v11 + 1;
  for ( j = v17 < v19; j; j = v20 < v19 )
  {
    if ( *v20 > (unsigned __int64)qword_280074E58 && *v20 < (unsigned __int64)qword_280074E60 )
      goto LABEL_47;
    ++v20;
  }
  DriverStart = (char *)DriverObject->DriverStart;
  v27 = (__int64)DriverStart;
  v23 = &DriverStart[DriverObject->DriverSize];
  v28 = (__int64)v23;
  if ( DriverStart == nullptr || v23 == nullptr )
    goto LABEL_32;
  v24 = (__int64 *)((char *)v11 + qword_280074550);
  if ( v9 > (unsigned __int64)v14 )
    v9 = (unsigned __int64)(v11 + 256);
  if ( v24 > v11 && (unsigned __int64)v24 < v9 && *v24 > (unsigned __int64)DriverStart && *v24 < (unsigned __int64)v23 )
  {
LABEL_61:
    qword_280074550 = (char *)v24 - (char *)v11;
    goto LABEL_32;
  }
  v24 = v11 + 1;
  for ( k = (unsigned __int64)v17 < v9; k; k = (unsigned __int64)v24 < v9 )
  {
    if ( *v24 > (unsigned __int64)DriverStart && *v24 < (unsigned __int64)v23 )
      goto LABEL_61;
    ++v24;
  }
  qword_280074BC8(3);
  v4->IoStatus.Information = 0;
  v4->IoStatus.Status = -1073741790;
  IofCompleteRequest(v4, 0);
  return 3221225506LL;
}


// ===== sub_28005CA40 @ 0x28005ca40 size=0x276 =====
__int64 __fastcall sub_28005CA40(__int64 a1, IRP *a2)
{
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rcx
  IRP *v4; // rdi
  __int64 v5; // rbx
  __int64 v6; // rbx
  unsigned __int64 v7; // r11
  __int64 *v8; // rcx
  __int64 *v9; // r8
  unsigned __int64 v10; // r9
  unsigned __int64 v11; // rdx
  __int64 *v12; // r10
  unsigned __int64 v13; // rax
  __int64 *v14; // rcx
  __int64 *v15; // rbx
  bool i; // cf
  __int64 *v17; // rax
  __int64 *v18; // rcx
  bool j; // cf
  char *DriverStart; // r9
  char *v21; // rdx
  __int64 *v22; // rcx
  bool k; // cf
  __int64 v25; // [rsp+48h] [rbp+10h] BYREF
  __int64 v26; // [rsp+50h] [rbp+18h] BYREF
  __int64 *v27; // [rsp+58h] [rbp+20h] BYREF

  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  v4 = a2;
  if ( CurrentStackLocation->MajorFunction != 14
    || dword_280074A20 == 0
    || KeGetCurrentIrql() >= 2u
    || a1 != qword_280074D30
    || *(char *)(a1 + 48) < 0
    || CurrentStackLocation->Parameters.Read.ByteOffset.LowPart != 315396
    && CurrentStackLocation->Parameters.Read.ByteOffset.LowPart != 315412
    && CurrentStackLocation->Parameters.Read.ByteOffset.LowPart != 315436
    && CurrentStackLocation->Parameters.Read.ByteOffset.LowPart != 315440
    && CurrentStackLocation->Parameters.Read.ByteOffset.LowPart != 508004 )
  {
    return qword_280074D78(a1, a2);
  }
  v5 = *(_QWORD *)(a1 + 24);
  if ( v5 == 0 )
    return sub_2800B7DE9();
  v6 = *(_QWORD *)(v5 + 8);
  v7 = qword_280074BF8();
  v8 = &v25;
  if ( &v27 >= (__int64 **)&v25 )
    v8 = (__int64 *)&v27;
  v9 = &v26;
  if ( v8 >= &v26 )
    v9 = v8;
  v27 = v9;
  v10 = *(_QWORD *)(v6 + 24);
  v25 = v10;
  v11 = v10 + *(unsigned int *)(v6 + 32);
  v26 = v11;
  if ( v10 == 0 || v11 == 0 )
  {
LABEL_32:
    a2 = v4;
    return qword_280074D78(a1, a2);
  }
  v12 = v9 + 256;
  v13 = v7;
  v14 = (__int64 *)((char *)v9 + qword_280074558);
  if ( v7 > (unsigned __int64)(v9 + 256) )
    v13 = (unsigned __int64)(v9 + 256);
  if ( v14 > v9 && (unsigned __int64)v14 < v13 && *v14 > v10 && *v14 < v11 )
  {
LABEL_31:
    qword_280074558 = (char *)v14 - (char *)v9;
    goto LABEL_32;
  }
  v15 = v9 + 1;
  v14 = v9 + 1;
  for ( i = (unsigned __int64)(v9 + 1) < v13; i; i = (unsigned __int64)v14 < v13 )
  {
    if ( *v14 > v10 && *v14 < v11 )
      goto LABEL_31;
    ++v14;
  }
  v25 = qword_280074E58;
  v26 = qword_280074E60;
  if ( qword_280074E58 == 0 || qword_280074E60 == 0 )
    goto LABEL_32;
  v17 = (__int64 *)v7;
  v18 = (__int64 *)((char *)v9 + qword_280074560);
  if ( v7 > (unsigned __int64)v12 )
    v17 = v9 + 256;
  if ( v18 > v9 && v18 < v17 && *v18 > (unsigned __int64)qword_280074E58 && *v18 < (unsigned __int64)qword_280074E60 )
  {
LABEL_47:
    qword_280074560 = (char *)v18 - (char *)v9;
    goto LABEL_32;
  }
  v18 = v9 + 1;
  for ( j = v15 < v17; j; j = v18 < v17 )
  {
    if ( *v18 > (unsigned __int64)qword_280074E58 && *v18 < (unsigned __int64)qword_280074E60 )
      goto LABEL_47;
    ++v18;
  }
  DriverStart = (char *)DriverObject->DriverStart;
  v25 = (__int64)DriverStart;
  v21 = &DriverStart[DriverObject->DriverSize];
  v26 = (__int64)v21;
  if ( DriverStart == nullptr || v21 == nullptr )
    goto LABEL_32;
  v22 = (__int64 *)((char *)v9 + qword_280074568);
  if ( v7 > (unsigned __int64)v12 )
    v7 = (unsigned __int64)(v9 + 256);
  if ( v22 > v9 && (unsigned __int64)v22 < v7 && *v22 > (unsigned __int64)DriverStart && *v22 < (unsigned __int64)v21 )
  {
LABEL_61:
    qword_280074568 = (char *)v22 - (char *)v9;
    goto LABEL_32;
  }
  v22 = v9 + 1;
  for ( k = (unsigned __int64)v15 < v7; k; k = (unsigned __int64)v22 < v7 )
  {
    if ( *v22 > (unsigned __int64)DriverStart && *v22 < (unsigned __int64)v21 )
      goto LABEL_61;
    ++v22;
  }
  qword_280074BC8(3);
  v4->IoStatus.Information = 0;
  v4->IoStatus.Status = -1073741790;
  IofCompleteRequest(v4, 0);
  return 3221225506LL;
}


// ===== sub_28005CCBC @ 0x28005ccbc size=0x255 =====
__int64 __fastcall sub_28005CCBC(__int64 a1, IRP *a2)
{
  IRP *v2; // rdi
  __int64 v3; // rsi
  __int64 v5; // rbx
  __int64 v6; // rbx
  unsigned __int64 v7; // r11
  char *v8; // rcx
  char *v9; // r9
  unsigned __int64 v10; // rbp
  unsigned __int64 v11; // r10
  _QWORD *v12; // r8
  unsigned __int64 v13; // rdx
  char *v14; // rcx
  _QWORD *v15; // rax
  bool i; // cf
  unsigned __int64 v17; // r9
  _QWORD *v18; // rcx
  bool j; // cf
  unsigned __int64 v20; // r9
  _QWORD *v21; // rcx
  bool k; // cf
  unsigned __int64 v23; // r9
  _QWORD *v24; // rcx
  bool m; // cf
  char *v26; // [rsp+48h] [rbp+10h] BYREF
  unsigned __int64 v27; // [rsp+50h] [rbp+18h] BYREF
  unsigned __int64 v28; // [rsp+58h] [rbp+20h] BYREF

  v2 = a2;
  v3 = a1;
  if ( a2->Tail.Overlay.CurrentStackLocation->MajorFunction != 4 )
    return qword_280074DA0();
  if ( dword_280074A20 == 0 || KeGetCurrentIrql() >= 2u )
    return qword_280074DA8(a1, a2);
  if ( qword_280074D30 == 0 )
    return qword_280074DB0();
  if ( a1 != *(_QWORD *)(qword_280074D30 + 24) )
    return qword_280074DA8(a1, a2);
  v5 = *(_QWORD *)(a1 + 24);
  if ( v5 == 0 )
    return sub_2800B7DE9();
  v6 = *(_QWORD *)(v5 + 8);
  v7 = qword_280074BF8();
  v8 = (char *)&v27;
  if ( &v26 >= (char **)&v27 )
    v8 = (char *)&v26;
  v9 = (char *)&v28;
  if ( v8 >= (char *)&v28 )
    v9 = v8;
  v26 = v9;
  v10 = *(_QWORD *)(v6 + 24);
  v27 = v10;
  v11 = v10 + *(unsigned int *)(v6 + 32);
  v28 = v11;
  if ( v10 == 0 || v11 == 0 )
  {
LABEL_29:
    a1 = v3;
    a2 = v2;
    return qword_280074DA8(a1, a2);
  }
  v12 = v9 + 2048;
  v13 = v7;
  v14 = &v9[qword_280074570];
  if ( v7 > (unsigned __int64)(v9 + 2048) )
    v13 = (unsigned __int64)(v9 + 2048);
  if ( v14 > v9 && (unsigned __int64)v14 < v13 && *(_QWORD *)v14 > v10 && *(_QWORD *)v14 < v11 )
  {
LABEL_28:
    qword_280074570 = v14 - v9;
    goto LABEL_29;
  }
  v15 = v9 + 8;
  v14 = v9 + 8;
  for ( i = (unsigned __int64)(v9 + 8) < v13; i; i = (unsigned __int64)v14 < v13 )
  {
    if ( *(_QWORD *)v14 > v10 && *(_QWORD *)v14 < v11 )
      goto LABEL_28;
    v14 += 8;
  }
  if ( qword_280074BD8 != 0 )
  {
    v17 = v7;
    if ( v7 > (unsigned __int64)v12 )
      v17 = (unsigned __int64)v12;
    v18 = v15;
    for ( j = (unsigned __int64)v15 < v17; j; j = (unsigned __int64)v18 < v17 )
    {
      if ( *v18 > (unsigned __int64)qword_280074BD8 && *v18 < (unsigned __int64)(qword_280074BD8 + 4096) )
        goto LABEL_29;
      ++v18;
    }
  }
  if ( qword_280074BE0 != 0 )
  {
    v20 = v7;
    if ( v7 > (unsigned __int64)v12 )
      v20 = (unsigned __int64)v12;
    v21 = v15;
    for ( k = (unsigned __int64)v15 < v20; k; k = (unsigned __int64)v21 < v20 )
    {
      if ( *v21 > (unsigned __int64)qword_280074BE0 && *v21 < (unsigned __int64)(qword_280074BE0 + 4096) )
        goto LABEL_29;
      ++v21;
    }
  }
  if ( qword_280074BE8 != 0 )
  {
    v23 = v7;
    if ( v7 > (unsigned __int64)v12 )
      v23 = (unsigned __int64)v12;
    v24 = v15;
    for ( m = (unsigned __int64)v15 < v23; m; m = (unsigned __int64)v24 < v23 )
    {
      if ( *v24 > (unsigned __int64)qword_280074BE8 && *v24 < (unsigned __int64)(qword_280074BE8 + 4096) )
        goto LABEL_29;
      ++v24;
    }
  }
  if ( qword_280074BF0 != 0 )
  {
    if ( v7 > (unsigned __int64)v12 )
      v7 = (unsigned __int64)v12;
    while ( (unsigned __int64)v15 < v7 )
    {
      if ( *v15 > (unsigned __int64)qword_280074BF0 && *v15 < (unsigned __int64)(qword_280074BF0 + 4096) )
        goto LABEL_29;
      ++v15;
    }
  }
  v2->IoStatus.Information = 0;
  v2->IoStatus.Status = -1073741790;
  IofCompleteRequest(v2, 0);
  return 3221225506LL;
}


// ===== sub_28005CF18 @ 0x28005cf18 size=0x180 =====
__int64 __fastcall sub_28005CF18(__int64 a1, IRP *a2)
{
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  IRP *v4; // rdi
  PIO_SECURITY_CONTEXT SecurityContext; // rcx
  char SecurityQos; // al
  __int64 v7; // rbx
  __int64 v8; // rbx
  unsigned __int64 v9; // r11
  char *v10; // rcx
  char *v11; // rdx
  unsigned __int64 v12; // r9
  unsigned __int64 v13; // r8
  char *i; // rcx
  char *v16; // [rsp+48h] [rbp+10h] BYREF
  unsigned __int64 v17; // [rsp+50h] [rbp+18h] BYREF
  unsigned __int64 v18; // [rsp+58h] [rbp+20h] BYREF

  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  v4 = a2;
  SecurityContext = CurrentStackLocation->Parameters.Create.SecurityContext;
  if ( CurrentStackLocation->MajorFunction != 15 )
    return qword_280074DB0(a1, a2);
  if ( dword_280074A20 == 0 )
    return qword_280074DB0(a1, a2);
  if ( KeGetCurrentIrql() >= 2u )
    return qword_280074DB0(a1, a2);
  if ( qword_280074D30 == 0 )
    return qword_280074DB0(a1, a2);
  if ( a1 != *(_QWORD *)(qword_280074D30 + 24) )
    return qword_280074DB0(a1, a2);
  if ( *(char *)(a1 + 48) < 0 )
    return qword_280074DB0(a1, a2);
  if ( SecurityContext == nullptr )
    return qword_280074DB0(a1, a2);
  SecurityQos = (char)SecurityContext[3].SecurityQos;
  if ( SecurityQos != 42 && SecurityQos != 10 && SecurityQos != -86 && SecurityQos != -118 )
    return qword_280074DB0(a1, a2);
  v7 = *(_QWORD *)(a1 + 24);
  if ( v7 == 0 )
    return sub_2800B7DE9();
  v8 = *(_QWORD *)(v7 + 8);
  v9 = qword_280074BF8();
  v10 = (char *)&v17;
  if ( &v16 >= (char **)&v17 )
    v10 = (char *)&v16;
  v11 = (char *)&v18;
  if ( v10 >= (char *)&v18 )
    v11 = v10;
  v16 = v11;
  v12 = *(_QWORD *)(v8 + 24);
  v17 = v12;
  v13 = v12 + *(unsigned int *)(v8 + 32);
  v18 = v13;
  if ( v12 == 0 || v13 == 0 )
  {
LABEL_33:
    a2 = v4;
    return qword_280074DB0(a1, a2);
  }
  i = &v11[qword_280074578];
  if ( v9 > (unsigned __int64)(v11 + 2048) )
    v9 = (unsigned __int64)(v11 + 2048);
  if ( i > v11 && (unsigned __int64)i < v9 && *(_QWORD *)i > v12 && *(_QWORD *)i < v13 )
  {
LABEL_32:
    qword_280074578 = i - v11;
    goto LABEL_33;
  }
  for ( i = v11 + 8; (unsigned __int64)i < v9; i += 8 )
  {
    if ( *(_QWORD *)i > v12 && *(_QWORD *)i < v13 )
      goto LABEL_32;
  }
  v4->IoStatus.Information = 0;
  v4->IoStatus.Status = -1073741790;
  IofCompleteRequest(v4, 0);
  return 3221225506LL;
}


// ===== sub_28005D0A0 @ 0x28005d0a0 size=0x670 =====
__int64 __fastcall sub_28005D0A0(__int64 a1, IRP *a2)
{
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  IRP *v4; // rbp
  PIO_SECURITY_CONTEXT SecurityContext; // rcx
  char SecurityQos; // al
  PSLIST_ENTRY v7; // r12
  __int64 v8; // rdi
  KIRQL v9; // r14
  PSLIST_ENTRY *v10; // rdx
  PSLIST_ENTRY v11; // rcx
  char *v12; // rbx
  __int64 v13; // r12
  _QWORD *v14; // rax
  int v15; // ebx
  __int64 (__fastcall *v16)(_QWORD, _QWORD); // rcx
  int v17; // r8d
  _DWORD *v18; // rdx
  _DWORD *v19; // rcx
  __int64 (__fastcall *v20)(_QWORD, _QWORD); // rcx
  int v21; // r8d
  _DWORD *v22; // rdx
  _DWORD *v23; // rcx
  __int64 (__fastcall *v24)(_QWORD, _QWORD); // rcx
  _DWORD *v25; // rdx
  _DWORD *v26; // rcx
  __int64 (__fastcall *v27)(_QWORD, _QWORD); // rcx
  unsigned __int64 v28; // rcx
  __int64 v29; // rdi
  unsigned __int64 v30; // r11
  __int64 *v31; // rcx
  char *v32; // rdx
  _QWORD *v33; // r9
  unsigned __int64 v34; // rax
  char *v35; // rcx
  char *v36; // rbx
  bool i; // cf
  unsigned __int64 v39; // r10
  unsigned __int64 v40; // r8
  char *v41; // rax
  char *v42; // rcx
  bool j; // cf
  char *v44; // rax
  char *v45; // rcx
  bool k; // cf
  char *v47; // rax
  char *v48; // rcx
  bool m; // cf
  char *v50; // rcx
  bool n; // cf
  __int64 v52; // [rsp+68h] [rbp+10h] BYREF
  __int64 v53; // [rsp+70h] [rbp+18h] BYREF
  char *v54; // [rsp+78h] [rbp+20h] BYREF

  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  v4 = a2;
  SecurityContext = CurrentStackLocation->Parameters.Create.SecurityContext;
  if ( CurrentStackLocation->MajorFunction != 15 )
    return qword_280074DD0(a1, a2);
  if ( *(char *)(a1 + 48) < 0 )
    return qword_280074DD0(a1, a2);
  if ( SecurityContext == nullptr )
    return qword_280074DD0(a1, a2);
  SecurityQos = (char)SecurityContext[3].SecurityQos;
  if ( SecurityQos != 42 && SecurityQos != 10 && SecurityQos != -86 && SecurityQos != -118 )
    return qword_280074DD0(a1, a2);
  ++dword_280074814;
  v7 = ExpInterlockedPopEntrySList(&stru_280074800);
  if ( v7 == nullptr )
  {
    ++dword_280074818;
    v7 = (PSLIST_ENTRY)qword_280074830(
                         (unsigned int)dword_280074824,
                         (unsigned int)dword_28007482C,
                         (unsigned int)dword_280074828);
    if ( v7 == nullptr )
      goto LABEL_79;
  }
  v7[1].Next = (struct _SLIST_ENTRY *)v4;
  v8 = ((unsigned int)v4 >> 8) & 0xF;
  v9 = KeAcquireSpinLockRaiseToDpc(&qword_280075200[v8]);
  v10 = (PSLIST_ENTRY *)((char *)&unk_280075280 + 16 * (unsigned int)v8);
  v11 = *v10;
  *((_QWORD *)&v7->Next + 1) = v10;
  v7->Next = v11;
  *((_QWORD *)&v11->Next + 1) = v7;
  ++dword_280074EA0[v8];
  *v10 = v7;
  if ( (unsigned int)dword_280074EA0[v8] > 0x80 )
  {
    v12 = (char *)&unk_280075280 + 16 * (int)v8;
    do
    {
      v13 = *((_QWORD *)v12 + 1);
      v14 = *(_QWORD **)(v13 + 8);
      *((_QWORD *)v12 + 1) = v14;
      *v14 = v12;
      ++dword_28007481C;
      if ( ExQueryDepthSList(&stru_280074800) < (unsigned __int16)word_280074810 )
      {
        ExpInterlockedPushEntrySList(&stru_280074800, (PSLIST_ENTRY)v13);
      }
      else
      {
        ++dword_280074820;
        qword_280074838(v13);
      }
      --dword_280074EA0[(int)v8];
    }
    while ( (unsigned int)dword_280074EA0[(int)v8] > 0x80 );
  }
  KeReleaseSpinLock(&qword_280075200[v8], v9);
  if ( dword_280074A20 == 0 )
    goto LABEL_79;
  v15 = 2;
  if ( KeGetCurrentIrql() >= 2u || a1 != qword_280074D38 )
    goto LABEL_79;
  if ( qword_280074D68 != nullptr )
  {
    v16 = *(__int64 (__fastcall **)(_QWORD, _QWORD))(qword_280074D48 + 144);
    if ( (unsigned __int64)v16 > qword_280074D50 && (unsigned __int64)v16 < qword_280074D58 || v16 == qword_280074D68 )
      qword_280074BC8(3);
    v17 = 2;
    v18 = &unk_280074E44;
    v19 = &loc_28005C478;
    while ( *v18 == *v19 )
    {
      --v17;
      --v19;
      --v18;
      if ( v17 == 0 )
        goto LABEL_29;
    }
    qword_280074BC8(3);
  }
LABEL_29:
  if ( qword_280074D70 != nullptr )
  {
    v20 = *(__int64 (__fastcall **)(_QWORD, _QWORD))(qword_280074D48 + 232);
    if ( (unsigned __int64)v20 > qword_280074D50 && (unsigned __int64)v20 < qword_280074D58 || v20 == qword_280074D70 )
      qword_280074BC8(3);
    v21 = 2;
    v22 = &unk_280074E4C;
    v23 = &loc_28005C7C8;
    while ( *v22 == *v23 )
    {
      --v21;
      --v23;
      --v22;
      if ( v21 == 0 )
        goto LABEL_39;
    }
    qword_280074BC8(3);
  }
LABEL_39:
  if ( qword_280074D78 != nullptr )
  {
    v24 = *(__int64 (__fastcall **)(_QWORD, _QWORD))(qword_280074D48 + 224);
    if ( (unsigned __int64)v24 > qword_280074D50 && (unsigned __int64)v24 < qword_280074D58 || v24 == qword_280074D78 )
      qword_280074BC8(3);
    v25 = &unk_280074E54;
    v26 = &loc_28005CA44;
    while ( *v25 == *v26 )
    {
      --v15;
      --v26;
      --v25;
      if ( v15 == 0 )
        goto LABEL_49;
    }
    qword_280074BC8(3);
  }
LABEL_49:
  if ( qword_280074DD0 != nullptr
    && ((unsigned __int64)(v27 = *(__int64 (__fastcall **)(_QWORD, _QWORD))(qword_280074DB8 + 232)) > qword_280074DC0
     && (unsigned __int64)v27 < qword_280074DC8
     || v27 == qword_280074DD0) )
  {
    qword_280074BC8(3);
  }
  if ( qword_280074DD8 != 0
    && ((v28 = *(_QWORD *)(qword_280074DB8 + 224)) > qword_280074DC0 && v28 < qword_280074DC8 || v28 == qword_280074DD8) )
  {
    qword_280074BC8(3);
  }
  if ( *(_DWORD *)(a1 + 72) != 7 )
    goto LABEL_79;
  if ( *(_QWORD *)(a1 + 24) != 0 )
  {
    v29 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 8LL);
    v30 = qword_280074BF8();
    v31 = &v52;
    if ( &v54 >= (char **)&v52 )
      v31 = (__int64 *)&v54;
    v32 = (char *)&v53;
    v52 = qword_280074E58;
    if ( v31 >= &v53 )
      v32 = (char *)v31;
    v53 = qword_280074E60;
    v54 = v32;
    if ( qword_280074E58 != 0 && qword_280074E60 != 0 )
    {
      v33 = v32 + 2048;
      v34 = v30;
      v35 = &v32[qword_280074580];
      if ( v30 > (unsigned __int64)(v32 + 2048) )
        v34 = (unsigned __int64)(v32 + 2048);
      if ( v35 > v32
        && (unsigned __int64)v35 < v34
        && *(_QWORD *)v35 > (unsigned __int64)qword_280074E58
        && *(_QWORD *)v35 < (unsigned __int64)qword_280074E60 )
      {
LABEL_78:
        qword_280074580 = v35 - v32;
      }
      else
      {
        v36 = v32 + 8;
        v35 = v32 + 8;
        for ( i = (unsigned __int64)(v32 + 8) < v34; i; i = (unsigned __int64)v35 < v34 )
        {
          if ( *(_QWORD *)v35 > (unsigned __int64)qword_280074E58 && *(_QWORD *)v35 < (unsigned __int64)qword_280074E60 )
            goto LABEL_78;
          v35 += 8;
        }
        v39 = *(_QWORD *)(v29 + 24);
        v52 = v39;
        v40 = v39 + *(unsigned int *)(v29 + 32);
        v53 = v40;
        if ( v39 != 0 && v40 != 0 )
        {
          v41 = (char *)v30;
          v42 = &v32[qword_280074588];
          if ( v30 > (unsigned __int64)v33 )
            v41 = v32 + 2048;
          if ( v42 > v32 && v42 < v41 && *(_QWORD *)v42 > v39 && *(_QWORD *)v42 < v40 )
          {
LABEL_94:
            qword_280074588 = v42 - v32;
          }
          else
          {
            v42 = v32 + 8;
            for ( j = v36 < v41; j; j = v42 < v41 )
            {
              if ( *(_QWORD *)v42 > v39 && *(_QWORD *)v42 < v40 )
                goto LABEL_94;
              v42 += 8;
            }
            v52 = qword_280074DC0;
            v53 = qword_280074DC8;
            if ( qword_280074DC0 != 0 && qword_280074DC8 != 0 )
            {
              v44 = (char *)v30;
              v45 = &v32[qword_280074590];
              if ( v30 > (unsigned __int64)v33 )
                v44 = v32 + 2048;
              if ( v45 > v32
                && v45 < v44
                && *(_QWORD *)v45 > (unsigned __int64)qword_280074DC0
                && *(_QWORD *)v45 < (unsigned __int64)qword_280074DC8 )
              {
LABEL_108:
                qword_280074590 = v45 - v32;
              }
              else
              {
                v45 = v32 + 8;
                for ( k = v36 < v44; k; k = v45 < v44 )
                {
                  if ( *(_QWORD *)v45 > (unsigned __int64)qword_280074DC0
                    && *(_QWORD *)v45 < (unsigned __int64)qword_280074DC8 )
                  {
                    goto LABEL_108;
                  }
                  v45 += 8;
                }
                if ( qword_280074E70 == 0 || qword_280074E78 == 0 )
                  goto LABEL_123;
                v47 = (char *)v30;
                v52 = qword_280074E70;
                v48 = &v32[qword_280074598];
                v53 = qword_280074E78;
                if ( v30 > (unsigned __int64)v33 )
                  v47 = v32 + 2048;
                if ( v48 <= v32
                  || v48 >= v47
                  || *(_QWORD *)v48 <= (unsigned __int64)qword_280074E70
                  || *(_QWORD *)v48 >= (unsigned __int64)qword_280074E78 )
                {
                  v48 = v32 + 8;
                  for ( m = v36 < v47; m; m = v48 < v47 )
                  {
                    if ( *(_QWORD *)v48 > (unsigned __int64)qword_280074E70
                      && *(_QWORD *)v48 < (unsigned __int64)qword_280074E78 )
                    {
                      goto LABEL_122;
                    }
                    v48 += 8;
                  }
LABEL_123:
                  if ( qword_280074E80 == 0 || qword_280074E88 == 0 )
                  {
LABEL_137:
                    v4->IoStatus.Status = -1073741790;
                    v4->IoStatus.Information = 0;
                    IofCompleteRequest(v4, 0);
                    return 3221225506LL;
                  }
                  v52 = qword_280074E80;
                  v53 = qword_280074E88;
                  v50 = &v32[qword_2800745A0];
                  if ( v30 > (unsigned __int64)v33 )
                    v30 = (unsigned __int64)(v32 + 2048);
                  if ( v50 <= v32
                    || (unsigned __int64)v50 >= v30
                    || *(_QWORD *)v50 <= (unsigned __int64)qword_280074E80
                    || *(_QWORD *)v50 >= (unsigned __int64)qword_280074E88 )
                  {
                    v50 = v32 + 8;
                    for ( n = (unsigned __int64)v36 < v30; n; n = (unsigned __int64)v50 < v30 )
                    {
                      if ( *(_QWORD *)v50 > (unsigned __int64)qword_280074E80
                        && *(_QWORD *)v50 < (unsigned __int64)qword_280074E88 )
                      {
                        goto LABEL_136;
                      }
                      v50 += 8;
                    }
                    goto LABEL_137;
                  }
LABEL_136:
                  qword_2800745A0 = v50 - v32;
                  goto LABEL_79;
                }
LABEL_122:
                qword_280074598 = v48 - v32;
              }
            }
          }
        }
      }
    }
LABEL_79:
    a2 = v4;
    return qword_280074DD0(a1, a2);
  }
  return sub_2800B7DE9();
}


// ===== sub_28005D718 @ 0x28005d718 size=0x4fe =====
__int64 __fastcall sub_28005D718(__int64 a1, IRP *a2)
{
  IRP *v2; // rbx
  __int64 v3; // rdi
  int v4; // esi
  __int64 (__fastcall *v5)(_QWORD, _QWORD); // rcx
  int v6; // r8d
  _DWORD *v7; // rdx
  _DWORD *v8; // rcx
  __int64 (__fastcall *v9)(_QWORD, _QWORD); // rcx
  int v10; // r8d
  _DWORD *v11; // rdx
  _DWORD *v12; // rcx
  __int64 (__fastcall *v13)(_QWORD, _QWORD); // rcx
  _DWORD *v14; // rdx
  _DWORD *v15; // rcx
  __int64 (__fastcall *v16)(_QWORD, _QWORD); // rcx
  __int64 (__fastcall *v17)(__int64, IRP *); // r8
  __int64 (__fastcall *v18)(_QWORD, _QWORD); // rcx
  __int64 v20; // rsi
  unsigned __int64 v21; // r11
  __int64 *v22; // rcx
  __int64 *v23; // r8
  __int64 *v24; // rbp
  unsigned __int64 v25; // rax
  __int64 *v26; // rcx
  __int64 *v27; // r10
  bool i; // cf
  unsigned __int64 v29; // r9
  unsigned __int64 v30; // rdx
  __int64 *v31; // rax
  __int64 *v32; // rcx
  bool j; // cf
  __int64 *v34; // rax
  __int64 *v35; // rcx
  bool k; // cf
  __int64 *v37; // rax
  __int64 *v38; // rcx
  bool m; // cf
  __int64 *v40; // rcx
  bool n; // cf
  __int64 v42; // [rsp+48h] [rbp+10h] BYREF
  __int64 v43; // [rsp+50h] [rbp+18h] BYREF
  __int64 *v44; // [rsp+58h] [rbp+20h] BYREF

  v2 = a2;
  v3 = a1;
  if ( a2->Tail.Overlay.CurrentStackLocation->MajorFunction != 14 )
    return qword_280074DD8(a1, a2);
  if ( dword_280074A20 == 0 )
    return qword_280074DD8(a1, a2);
  v4 = 2;
  if ( KeGetCurrentIrql() >= 2u || a1 != qword_280074D38 )
    return qword_280074DD8(a1, a2);
  if ( qword_280074D68 != nullptr )
  {
    v5 = *(__int64 (__fastcall **)(_QWORD, _QWORD))(qword_280074D48 + 144);
    if ( (unsigned __int64)v5 > qword_280074D50 && (unsigned __int64)v5 < qword_280074D58 || v5 == qword_280074D68 )
      qword_280074BC8(3);
    v6 = 2;
    v7 = &unk_280074E44;
    v8 = &loc_28005C478;
    while ( *v7 == *v8 )
    {
      --v8;
      --v7;
      if ( --v6 == 0 )
        goto LABEL_15;
    }
    qword_280074BC8(3);
  }
LABEL_15:
  if ( qword_280074D70 != nullptr )
  {
    v9 = *(__int64 (__fastcall **)(_QWORD, _QWORD))(qword_280074D48 + 232);
    if ( (unsigned __int64)v9 > qword_280074D50 && (unsigned __int64)v9 < qword_280074D58 || v9 == qword_280074D70 )
      qword_280074BC8(3);
    v10 = 2;
    v11 = &unk_280074E4C;
    v12 = &loc_28005C7C8;
    while ( *v11 == *v12 )
    {
      --v12;
      --v11;
      if ( --v10 == 0 )
        goto LABEL_25;
    }
    qword_280074BC8(3);
  }
LABEL_25:
  if ( qword_280074D78 != nullptr )
  {
    v13 = *(__int64 (__fastcall **)(_QWORD, _QWORD))(qword_280074D48 + 224);
    if ( (unsigned __int64)v13 > qword_280074D50 && (unsigned __int64)v13 < qword_280074D58 || v13 == qword_280074D78 )
      qword_280074BC8(3);
    v14 = &unk_280074E54;
    v15 = &loc_28005CA44;
    while ( *v14 == *v15 )
    {
      --v15;
      --v14;
      if ( --v4 == 0 )
        goto LABEL_35;
    }
    qword_280074BC8(3);
  }
LABEL_35:
  if ( qword_280074DD0 != nullptr
    && ((unsigned __int64)(v16 = *(__int64 (__fastcall **)(_QWORD, _QWORD))(qword_280074DB8 + 232)) > qword_280074DC0
     && (unsigned __int64)v16 < qword_280074DC8
     || v16 == qword_280074DD0) )
  {
    qword_280074BC8(3);
  }
  v17 = (__int64 (__fastcall *)(__int64, IRP *))qword_280074DD8;
  if ( qword_280074DD8 != nullptr
    && ((unsigned __int64)(v18 = *(__int64 (__fastcall **)(_QWORD, _QWORD))(qword_280074DB8 + 224)) > qword_280074DC0
     && (unsigned __int64)v18 < qword_280074DC8
     || v18 == qword_280074DD8) )
  {
    qword_280074BC8(3);
    v17 = (__int64 (__fastcall *)(__int64, IRP *))qword_280074DD8;
  }
  if ( *(_DWORD *)(v3 + 72) != 7 )
    return v17(v3, v2);
  if ( *(_QWORD *)(v3 + 24) != 0 )
  {
    v20 = *(_QWORD *)(*(_QWORD *)(v3 + 24) + 8LL);
    v21 = qword_280074BF8();
    v22 = &v42;
    v42 = qword_280074E58;
    if ( &v44 >= (__int64 **)&v42 )
      v22 = (__int64 *)&v44;
    v23 = &v43;
    v43 = qword_280074E60;
    if ( v22 >= &v43 )
      v23 = v22;
    v44 = v23;
    if ( qword_280074E58 != 0 && qword_280074E60 != 0 )
    {
      v24 = v23 + 256;
      v25 = v21;
      v26 = (__int64 *)((char *)v23 + qword_2800745A8);
      if ( v21 > (unsigned __int64)(v23 + 256) )
        v25 = (unsigned __int64)(v23 + 256);
      if ( v26 > v23
        && (unsigned __int64)v26 < v25
        && *v26 > (unsigned __int64)qword_280074E58
        && *v26 < (unsigned __int64)qword_280074E60 )
      {
LABEL_65:
        qword_2800745A8 = (char *)v26 - (char *)v23;
      }
      else
      {
        v27 = v23 + 1;
        v26 = v23 + 1;
        for ( i = (unsigned __int64)(v23 + 1) < v25; i; i = (unsigned __int64)v26 < v25 )
        {
          if ( *v26 > (unsigned __int64)qword_280074E58 && *v26 < (unsigned __int64)qword_280074E60 )
            goto LABEL_65;
          ++v26;
        }
        v29 = *(_QWORD *)(v20 + 24);
        v42 = v29;
        v30 = v29 + *(unsigned int *)(v20 + 32);
        v43 = v30;
        if ( v29 != 0 && v30 != 0 )
        {
          v31 = (__int64 *)v21;
          v32 = (__int64 *)((char *)v23 + qword_2800745B0);
          if ( v21 > (unsigned __int64)v24 )
            v31 = v23 + 256;
          if ( v32 > v23 && v32 < v31 && *v32 > v29 && *v32 < v30 )
          {
LABEL_81:
            qword_2800745B0 = (char *)v32 - (char *)v23;
          }
          else
          {
            v32 = v23 + 1;
            for ( j = v27 < v31; j; j = v32 < v31 )
            {
              if ( *v32 > v29 && *v32 < v30 )
                goto LABEL_81;
              ++v32;
            }
            v42 = qword_280074DC0;
            v43 = qword_280074DC8;
            if ( qword_280074DC0 != 0 && qword_280074DC8 != 0 )
            {
              v34 = (__int64 *)v21;
              v35 = (__int64 *)((char *)v23 + qword_2800745B8);
              if ( v21 > (unsigned __int64)v24 )
                v34 = v23 + 256;
              if ( v35 > v23
                && v35 < v34
                && *v35 > (unsigned __int64)qword_280074DC0
                && *v35 < (unsigned __int64)qword_280074DC8 )
              {
LABEL_95:
                qword_2800745B8 = (char *)v35 - (char *)v23;
              }
              else
              {
                v35 = v23 + 1;
                for ( k = v27 < v34; k; k = v35 < v34 )
                {
                  if ( *v35 > (unsigned __int64)qword_280074DC0 && *v35 < (unsigned __int64)qword_280074DC8 )
                    goto LABEL_95;
                  ++v35;
                }
                if ( qword_280074E70 == 0 || qword_280074E78 == 0 )
                  goto LABEL_110;
                v37 = (__int64 *)v21;
                v42 = qword_280074E70;
                v38 = (__int64 *)((char *)v23 + qword_2800745C0);
                v43 = qword_280074E78;
                if ( v21 > (unsigned __int64)v24 )
                  v37 = v23 + 256;
                if ( v38 <= v23
                  || v38 >= v37
                  || *v38 <= (unsigned __int64)qword_280074E70
                  || *v38 >= (unsigned __int64)qword_280074E78 )
                {
                  v38 = v23 + 1;
                  for ( m = v27 < v37; m; m = v38 < v37 )
                  {
                    if ( *v38 > (unsigned __int64)qword_280074E70 && *v38 < (unsigned __int64)qword_280074E78 )
                      goto LABEL_109;
                    ++v38;
                  }
LABEL_110:
                  if ( qword_280074E80 == 0 || qword_280074E88 == 0 )
                  {
LABEL_124:
                    v2->IoStatus.Information = 0;
                    v2->IoStatus.Status = -1073741790;
                    IofCompleteRequest(v2, 0);
                    return 3221225506LL;
                  }
                  v42 = qword_280074E80;
                  v43 = qword_280074E88;
                  v40 = (__int64 *)((char *)v23 + qword_2800745C8);
                  if ( v21 > (unsigned __int64)v24 )
                    v21 = (unsigned __int64)(v23 + 256);
                  if ( v40 <= v23
                    || (unsigned __int64)v40 >= v21
                    || *v40 <= (unsigned __int64)qword_280074E80
                    || *v40 >= (unsigned __int64)qword_280074E88 )
                  {
                    v40 = v23 + 1;
                    for ( n = (unsigned __int64)v27 < v21; n; n = (unsigned __int64)v40 < v21 )
                    {
                      if ( *v40 > (unsigned __int64)qword_280074E80 && *v40 < (unsigned __int64)qword_280074E88 )
                        goto LABEL_123;
                      ++v40;
                    }
                    goto LABEL_124;
                  }
LABEL_123:
                  qword_2800745C8 = (char *)v40 - (char *)v23;
                  goto LABEL_66;
                }
LABEL_109:
                qword_2800745C0 = (char *)v38 - (char *)v23;
              }
            }
          }
        }
      }
    }
LABEL_66:
    a1 = v3;
    a2 = v2;
    return qword_280074DD8(a1, a2);
  }
  return sub_2800B7DE9();
}


// ===== sub_28005DC1C @ 0x28005dc1c size=0x135 =====
void __fastcall sub_28005DC1C(__int64 a1, IRP *a2)
{
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  PIO_SECURITY_CONTEXT SecurityContext; // rcx
  char SecurityQos; // al
  KSPIN_LOCK *v7; // r12
  struct _SLIST_ENTRY *v8; // rbp
  KIRQL v9; // r13
  struct _SLIST_ENTRY *i; // rbx
  struct _SLIST_ENTRY *Next; // rcx
  struct _SLIST_ENTRY **v12; // rax

  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  SecurityContext = CurrentStackLocation->Parameters.Create.SecurityContext;
  if ( CurrentStackLocation->MajorFunction != 15 )
    goto LABEL_2;
  if ( SecurityContext == nullptr )
    goto LABEL_2;
  SecurityQos = (char)SecurityContext[3].SecurityQos;
  if ( SecurityQos != 42 && SecurityQos != 10 && SecurityQos != -86 && SecurityQos != -118 )
    goto LABEL_2;
  v7 = &qword_280075200[((unsigned int)a2 >> 8) & 0xF];
  v8 = (struct _SLIST_ENTRY *)((char *)&unk_280075280 + 16 * (((unsigned int)a2 >> 8) & 0xF));
  v9 = KeAcquireSpinLockRaiseToDpc(v7);
  for ( i = v8->Next; i != v8; i = i->Next )
  {
    if ( (IRP *)i[1].Next == a2 )
    {
      Next = i->Next;
      v12 = *((struct _SLIST_ENTRY ***)&i->Next + 1);
      *v12 = i->Next;
      *((_QWORD *)&Next->Next + 1) = v12;
      ++dword_28007481C;
      if ( ExQueryDepthSList(&stru_280074800) < (unsigned __int16)word_280074810 )
      {
        ExpInterlockedPushEntrySList(&stru_280074800, i);
      }
      else
      {
        ++dword_280074820;
        qword_280074838(i);
      }
      break;
    }
  }
  KeReleaseSpinLock(v7, v9);
  if ( dword_280074A20 != 0 && i == v8 && *(_DWORD *)(a1 + 72) == 7 )
  {
    a2->IoStatus.Status = 0;
    IofCompleteRequest(a2, 0);
  }
  else
  {
LABEL_2:
    qword_280074DE0(a1);
  }
}


// ===== sub_28005DD58 @ 0x28005dd58 size=0x377 =====
__int64 __fastcall sub_28005DD58(__int64 a1, IRP *a2)
{
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  IRP *v4; // rdi
  PIO_SECURITY_CONTEXT SecurityContext; // rcx
  char SecurityQos; // al
  __int64 v7; // rcx
  __int64 v8; // rax
  bool i; // zf
  __int64 v10; // rsi
  unsigned __int64 v11; // r11
  __int64 *v12; // rcx
  __int64 *v13; // r9
  __int64 *v14; // rbp
  unsigned __int64 v15; // rax
  __int64 *v16; // rcx
  __int64 *v17; // r10
  bool j; // cf
  unsigned __int64 v20; // r8
  unsigned __int64 v21; // rdx
  __int64 *v22; // rax
  __int64 *v23; // rcx
  bool k; // cf
  __int64 *v25; // rax
  __int64 *v26; // rcx
  bool m; // cf
  __int64 *v28; // rax
  __int64 *v29; // rcx
  bool n; // cf
  __int64 *v31; // rcx
  bool ii; // cf
  __int64 v33; // [rsp+48h] [rbp+10h] BYREF
  __int64 v34; // [rsp+50h] [rbp+18h] BYREF
  __int64 *v35; // [rsp+58h] [rbp+20h] BYREF

  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  v4 = a2;
  SecurityContext = CurrentStackLocation->Parameters.Create.SecurityContext;
  if ( CurrentStackLocation->MajorFunction != 15 )
    return qword_280074E08(a1, a2);
  if ( dword_280074A20 == 0 )
    return qword_280074E08(a1, a2);
  if ( KeGetCurrentIrql() >= 2u )
    return qword_280074E08(a1, a2);
  if ( *(_DWORD *)(a1 + 72) != 50 )
    return qword_280074E08(a1, a2);
  if ( *(char *)(a1 + 48) < 0 )
    return qword_280074E08(a1, a2);
  if ( SecurityContext == nullptr )
    return qword_280074E08(a1, a2);
  SecurityQos = (char)SecurityContext[3].SecurityQos;
  if ( SecurityQos != 42 && SecurityQos != 10 && SecurityQos != -86 && SecurityQos != -118 )
    return qword_280074E08(a1, a2);
  if ( *(_QWORD *)(a1 + 24) != 0 )
  {
    v7 = *(_QWORD *)(a1 + 24);
    v8 = v7;
    for ( i = v7 == 0; !i; i = v8 == 0 )
    {
      if ( *(_DWORD *)(v8 + 72) != 50 && *(_DWORD *)(v8 + 72) != 7 )
        goto LABEL_35;
      v8 = *(_QWORD *)(v8 + 24);
    }
    v10 = *(_QWORD *)(v7 + 8);
    v11 = qword_280074BF8();
    v12 = &v33;
    if ( &v35 >= (__int64 **)&v33 )
      v12 = (__int64 *)&v35;
    v13 = &v34;
    v34 = qword_280074E60;
    if ( v12 >= &v34 )
      v13 = v12;
    v33 = qword_280074E58;
    v35 = v13;
    if ( qword_280074E58 != 0 && qword_280074E60 != 0 )
    {
      v14 = v13 + 256;
      v15 = v11;
      v16 = (__int64 *)((char *)v13 + qword_2800745D0);
      if ( v11 > (unsigned __int64)(v13 + 256) )
        v15 = (unsigned __int64)(v13 + 256);
      if ( v16 > v13
        && (unsigned __int64)v16 < v15
        && *v16 > (unsigned __int64)qword_280074E58
        && *v16 < (unsigned __int64)qword_280074E60 )
      {
LABEL_34:
        qword_2800745D0 = (char *)v16 - (char *)v13;
      }
      else
      {
        v17 = v13 + 1;
        v16 = v13 + 1;
        for ( j = (unsigned __int64)(v13 + 1) < v15; j; j = (unsigned __int64)v16 < v15 )
        {
          if ( *v16 > (unsigned __int64)qword_280074E58 && *v16 < (unsigned __int64)qword_280074E60 )
            goto LABEL_34;
          ++v16;
        }
        v20 = *(_QWORD *)(v10 + 24);
        v33 = v20;
        v21 = v20 + *(unsigned int *)(v10 + 32);
        v34 = v21;
        if ( v20 == 0 || v21 == 0 )
          goto LABEL_35;
        v22 = (__int64 *)v11;
        v23 = (__int64 *)((char *)v13 + qword_2800745D8);
        if ( v11 > (unsigned __int64)v14 )
          v22 = v13 + 256;
        if ( v23 > v13 && v23 < v22 && *v23 > v20 && *v23 < v21 )
        {
LABEL_50:
          qword_2800745D8 = (char *)v23 - (char *)v13;
        }
        else
        {
          v23 = v13 + 1;
          for ( k = v17 < v22; k; k = v23 < v22 )
          {
            if ( *v23 > v20 && *v23 < v21 )
              goto LABEL_50;
            ++v23;
          }
          v33 = qword_280074DF8;
          v34 = qword_280074E00;
          if ( qword_280074DF8 == 0 || qword_280074E00 == 0 )
            goto LABEL_35;
          v25 = (__int64 *)v11;
          v26 = (__int64 *)((char *)v13 + qword_2800745E0);
          if ( v11 > (unsigned __int64)v14 )
            v25 = v13 + 256;
          if ( v26 > v13
            && v26 < v25
            && *v26 > (unsigned __int64)qword_280074DF8
            && *v26 < (unsigned __int64)qword_280074E00 )
          {
LABEL_64:
            qword_2800745E0 = (char *)v26 - (char *)v13;
          }
          else
          {
            v26 = v13 + 1;
            for ( m = v17 < v25; m; m = v26 < v25 )
            {
              if ( *v26 > (unsigned __int64)qword_280074DF8 && *v26 < (unsigned __int64)qword_280074E00 )
                goto LABEL_64;
              ++v26;
            }
            if ( qword_280074E70 != 0 && qword_280074E78 != 0 )
            {
              v28 = (__int64 *)v11;
              v33 = qword_280074E70;
              v29 = (__int64 *)((char *)v13 + qword_2800745E8);
              v34 = qword_280074E78;
              if ( v11 > (unsigned __int64)v14 )
                v28 = v13 + 256;
              if ( v29 > v13
                && v29 < v28
                && *v29 > (unsigned __int64)qword_280074E70
                && *v29 < (unsigned __int64)qword_280074E78 )
              {
LABEL_78:
                qword_2800745E8 = (char *)v29 - (char *)v13;
                goto LABEL_35;
              }
              v29 = v13 + 1;
              for ( n = v17 < v28; n; n = v29 < v28 )
              {
                if ( *v29 > (unsigned __int64)qword_280074E70 && *v29 < (unsigned __int64)qword_280074E78 )
                  goto LABEL_78;
                ++v29;
              }
            }
            if ( qword_280074E80 == 0 || qword_280074E88 == 0 )
            {
LABEL_93:
              v4->IoStatus.Information = 0;
              v4->IoStatus.Status = -1073741790;
              IofCompleteRequest(v4, 0);
              return 3221225506LL;
            }
            v33 = qword_280074E80;
            v34 = qword_280074E88;
            v31 = (__int64 *)((char *)v13 + qword_2800745F0);
            if ( v11 > (unsigned __int64)v14 )
              v11 = (unsigned __int64)(v13 + 256);
            if ( v31 <= v13
              || (unsigned __int64)v31 >= v11
              || *v31 <= (unsigned __int64)qword_280074E80
              || *v31 >= (unsigned __int64)qword_280074E88 )
            {
              v31 = v13 + 1;
              for ( ii = (unsigned __int64)v17 < v11; ii; ii = (unsigned __int64)v31 < v11 )
              {
                if ( *v31 > (unsigned __int64)qword_280074E80 && *v31 < (unsigned __int64)qword_280074E88 )
                  goto LABEL_92;
                ++v31;
              }
              goto LABEL_93;
            }
LABEL_92:
            qword_2800745F0 = (char *)v31 - (char *)v13;
          }
        }
      }
    }
LABEL_35:
    a2 = v4;
    return qword_280074E08(a1, a2);
  }
  return sub_2800B7DE9();
}


// ===== sub_28005E0D8 @ 0x28005e0d8 size=0x1b6 =====
__int64 __fastcall sub_28005E0D8(__int64 a1, IRP *a2)
{
  IRP *v2; // rbx
  __int64 v3; // rdi
  __int64 v5; // rdx
  __int64 v6; // rcx
  __int64 v7; // rsi
  unsigned __int64 v8; // r11
  unsigned __int64 v9; // rcx
  char *v10; // rcx
  char *v11; // [rsp+20h] [rbp-28h]
  char *v12; // [rsp+58h] [rbp+10h] BYREF
  unsigned __int64 v13; // [rsp+60h] [rbp+18h] BYREF
  unsigned __int64 v14; // [rsp+68h] [rbp+20h] BYREF

  v2 = a2;
  v3 = a1;
  if ( a2->Tail.Overlay.CurrentStackLocation->MajorFunction != 4 )
    return qword_280074E28();
  if ( dword_280074A20 != 0 && KeGetCurrentIrql() < 2u && a1 == qword_280074D40 )
  {
    v5 = *(_QWORD *)(a1 + 24);
    if ( v5 == 0 )
      return sub_2800B7DE9();
    v6 = *(_QWORD *)(a1 + 24);
    do
    {
      if ( *(PDRIVER_OBJECT *)(v6 + 8) == DriverObject && *(_DWORD *)(*(_QWORD *)(v6 + 64) + 208LL) == 2 )
        break;
      v6 = *(_QWORD *)(v6 + 24);
    }
    while ( v6 != 0 );
    if ( v6 != 0 )
    {
      v7 = *(_QWORD *)(v5 + 8);
      v8 = qword_280074BF8(v6, v5, DriverObject);
      v12 = (char *)&v12;
      if ( &v12 < (char **)&v13 )
        v12 = (char *)&v13;
      if ( v12 < (char *)&v14 )
        v12 = (char *)&v14;
      v13 = *(_QWORD *)(v7 + 24);
      v9 = v13 + *(unsigned int *)(v7 + 32);
      v14 = v9;
      if ( v13 != 0 && v9 != 0 )
      {
        v10 = v12;
        v11 = &v12[qword_280074EF0];
        if ( v8 > (unsigned __int64)(v12 + 2048) )
          v8 = (unsigned __int64)(v12 + 2048);
        if ( v11 <= v12 || (unsigned __int64)v11 >= v8 || *(_QWORD *)v11 <= v13 || *(_QWORD *)v11 >= v14 )
        {
          do
          {
            v10 += 8;
            if ( (unsigned __int64)v10 >= v8 )
            {
              qword_280074BC8(3);
              v2->IoStatus.Information = 0;
              v2->IoStatus.Status = -1073741790;
              IofCompleteRequest(v2, 0);
              return 3221225506LL;
            }
          }
          while ( *(_QWORD *)v10 <= v13 || *(_QWORD *)v10 >= v14 );
          v11 = v10;
        }
        qword_280074EF0 = v11 - v12;
      }
    }
    a1 = v3;
    a2 = v2;
  }
  return qword_280074E30(a1, a2);
}


// ===== sub_28005E294 @ 0x28005e294 size=0x1d3 =====
__int64 __fastcall sub_28005E294(__int64 a1, IRP *a2)
{
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rcx
  IRP *v4; // rbx
  __int64 v5; // rdx
  __int64 v6; // rcx
  __int64 v7; // rsi
  unsigned __int64 v8; // r11
  unsigned __int64 v9; // rcx
  char *v10; // rcx
  char *v12; // [rsp+20h] [rbp-28h]
  char *v13; // [rsp+58h] [rbp+10h] BYREF
  unsigned __int64 v14; // [rsp+60h] [rbp+18h] BYREF
  unsigned __int64 v15; // [rsp+68h] [rbp+20h] BYREF

  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  v4 = a2;
  if ( CurrentStackLocation->MajorFunction == 14
    && dword_280074A20 != 0
    && KeGetCurrentIrql() < 2u
    && a1 == qword_280074D40
    && (CurrentStackLocation->Parameters.Read.ByteOffset.LowPart == 315396
     || CurrentStackLocation->Parameters.Read.ByteOffset.LowPart == 315412
     || CurrentStackLocation->Parameters.Read.ByteOffset.LowPart == 315436
     || CurrentStackLocation->Parameters.Read.ByteOffset.LowPart == 315440
     || CurrentStackLocation->Parameters.Read.ByteOffset.LowPart == 508004) )
  {
    v5 = *(_QWORD *)(a1 + 24);
    if ( v5 == 0 )
      return sub_2800B7DE9();
    v6 = *(_QWORD *)(a1 + 24);
    do
    {
      if ( *(PDRIVER_OBJECT *)(v6 + 8) == DriverObject && *(_DWORD *)(*(_QWORD *)(v6 + 64) + 208LL) == 2 )
        break;
      v6 = *(_QWORD *)(v6 + 24);
    }
    while ( v6 != 0 );
    if ( v6 != 0 )
    {
      v7 = *(_QWORD *)(v5 + 8);
      v8 = qword_280074BF8(v6, v5, DriverObject);
      v13 = (char *)&v13;
      if ( &v13 < (char **)&v14 )
        v13 = (char *)&v14;
      if ( v13 < (char *)&v15 )
        v13 = (char *)&v15;
      v14 = *(_QWORD *)(v7 + 24);
      v9 = v14 + *(unsigned int *)(v7 + 32);
      v15 = v9;
      if ( v14 != 0 && v9 != 0 )
      {
        v10 = v13;
        v12 = &v13[qword_280074EF8];
        if ( v8 > (unsigned __int64)(v13 + 2048) )
          v8 = (unsigned __int64)(v13 + 2048);
        if ( v12 <= v13 || (unsigned __int64)v12 >= v8 || *(_QWORD *)v12 <= v14 || *(_QWORD *)v12 >= v15 )
        {
          do
          {
            v10 += 8;
            if ( (unsigned __int64)v10 >= v8 )
            {
              qword_280074BC8(3);
              v4->IoStatus.Information = 0;
              v4->IoStatus.Status = -1073741790;
              IofCompleteRequest(v4, 0);
              return 3221225506LL;
            }
          }
          while ( *(_QWORD *)v10 <= v14 || *(_QWORD *)v10 >= v15 );
          v12 = v10;
        }
        qword_280074EF8 = v12 - v13;
      }
    }
    a2 = v4;
  }
  return qword_280074E38(a1, a2);
}


// ===== sub_28005E470 @ 0x28005e470 size=0xac =====
__int64 __fastcall sub_28005E470(__int64 a1, IRP *a2)
{
  __int64 v2; // rbp
  union _LARGE_INTEGER *CurrentStackLocation; // rdi
  PMDL MdlAddress; // rcx
  PVOID MappedSystemVa; // rax
  NTSTATUS v8; // esi

  v2 = *(_QWORD *)(a1 + 64);
  CurrentStackLocation = (union _LARGE_INTEGER *)a2->Tail.Overlay.CurrentStackLocation;
  MdlAddress = a2->MdlAddress;
  if ( (MdlAddress->MdlFlags & 5) != 0 )
    MappedSystemVa = MdlAddress->MappedSystemVa;
  else
    MappedSystemVa = MmMapLockedPagesSpecifyCache(MdlAddress, 0, MmCached, nullptr, 0, 0x10u);
  v8 = sub_280056AE0(
         a1,
         *(struct _DEVICE_OBJECT **)(v2 + 24),
         (__int64)a2,
         (__int64)MappedSystemVa,
         CurrentStackLocation[1].LowPart,
         CurrentStackLocation[3]);
  a2->IoStatus.Status = v8;
  if ( v8 < 0 )
    a2->IoStatus.Information = 0;
  else
    a2->IoStatus.Information = CurrentStackLocation[1].LowPart;
  IofCompleteRequest(a2, 1);
  return (unsigned int)v8;
}


// ===== sub_28005E524 @ 0x28005e524 size=0xd5 =====
__int64 __fastcall sub_28005E524(__int64 a1, __int64 a2, int a3)
{
  char *v4; // r12
  __int64 v5; // rsi
  __int64 v6; // rbp
  char *v7; // rcx
  char *v8; // rdx
  __int64 i; // r8
  char v10; // al
  char v11; // r11
  __int64 j; // rbx
  __int64 result; // rax
  char v14[16]; // [rsp+20h] [rbp-98h] BYREF
  _BYTE v15[32]; // [rsp+30h] [rbp-88h] BYREF
  char v16; // [rsp+50h] [rbp-68h] BYREF
  _BYTE v17[32]; // [rsp+70h] [rbp-48h] BYREF

  if ( a3 != 0 )
  {
    v4 = (char *)(a1 + 90761);
    v5 = ((unsigned int)(a3 - 1) >> 9) + 1;
    do
    {
      v6 = a2;
      v14[0] = 1;
      v7 = &v16;
      v8 = v4;
      for ( i = 32; i != 0; --i )
      {
        v10 = *v8++;
        v7[32] = v10;
        *v7++ = v10;
      }
      do
        sub_28006ECC8(v17, v14);
      while ( v11 != 1 );
      for ( j = 32; j != 0; --j )
      {
        result = sub_28006EDAC(v15, v6);
        v6 += 16;
      }
      a2 += 512;
      --v5;
    }
    while ( v5 != 0 );
  }
  return result;
}


// ===== sub_28005E600 @ 0x28005e600 size=0xd5 =====
__int64 __fastcall sub_28005E600(__int64 a1, __int64 a2, int a3)
{
  char *v4; // r12
  __int64 v5; // rsi
  __int64 v6; // rbp
  char *v7; // rcx
  char *v8; // rdx
  __int64 i; // r8
  char v10; // al
  char v11; // r11
  __int64 j; // rbx
  __int64 result; // rax
  char v14[16]; // [rsp+20h] [rbp-98h] BYREF
  _BYTE v15[32]; // [rsp+30h] [rbp-88h] BYREF
  char v16; // [rsp+50h] [rbp-68h] BYREF
  _BYTE v17[32]; // [rsp+70h] [rbp-48h] BYREF

  if ( a3 != 0 )
  {
    v4 = (char *)(a1 + 90761);
    v5 = ((unsigned int)(a3 - 1) >> 9) + 1;
    do
    {
      v6 = a2;
      v14[0] = 1;
      v7 = &v16;
      v8 = v4;
      for ( i = 32; i != 0; --i )
      {
        v10 = *v8++;
        v7[32] = v10;
        *v7++ = v10;
      }
      do
        sub_28006ECC8(v17, v14);
      while ( v11 != 1 );
      for ( j = 32; j != 0; --j )
      {
        result = sub_28006F04C(v15, v6);
        v6 += 16;
      }
      a2 += 512;
      --v5;
    }
    while ( v5 != 0 );
  }
  return result;
}


// ===== sub_28005E6DC @ 0x28005e6dc size=0xe9 =====
NTSTATUS sub_28005E6DC()
{
  NTSTATUS result; // eax
  NTSTATUS v1; // ebx
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-58h] BYREF
  struct _UNICODE_STRING ValueName; // [rsp+50h] [rbp-48h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+60h] [rbp-38h] BYREF
  char Data; // [rsp+A0h] [rbp+8h] BYREF
  void *KeyHandle; // [rsp+A8h] [rbp+10h] BYREF

  RtlInitUnicodeString(
    &DestinationString,
    L"\\REGISTRY\\MACHINE\\BCD00000000\\Objects\\{9dea862c-5cdd-4e70-acc1-f32b344d4795}\\Elements\\26000005");
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 64;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  result = ZwCreateKey(&KeyHandle, 2u, &ObjectAttributes, 0, nullptr, 0, nullptr);
  if ( result >= 0 )
  {
    RtlInitUnicodeString(&ValueName, L"Element");
    Data = 1;
    v1 = ZwSetValueKey(KeyHandle, &ValueName, 0, 3u, &Data, 1u);
    ZwFlushKey(KeyHandle);
    ZwClose(KeyHandle);
    return v1;
  }
  return result;
}


// ===== sub_28005E7CC @ 0x28005e7cc size=0x855 =====
BOOLEAN __fastcall sub_28005E7CC(PVOID P)
{
  bool v2; // bp
  BOOLEAN v3; // r12
  PDEVICE_OBJECT i; // rbx
  WCHAR v5; // di
  __int64 v6; // r11
  wchar_t v7; // ax
  PVOID PoolWithTag; // rax
  __int64 v9; // rcx
  wchar_t v10; // ax
  struct _UNICODE_STRING *p_DosName; // rcx
  const WCHAR *DeviceExtension; // rdx
  PVOID v13; // rax
  PDEVICE_OBJECT j; // rbx
  WCHAR v15; // si
  __int64 v16; // r11
  wchar_t v17; // ax
  __int64 v18; // rcx
  __int16 v19; // ax
  NTSTATUS v20; // edi
  __int64 v21; // rcx
  wchar_t v22; // ax
  struct _UNICODE_STRING *p_Destination; // rcx
  const WCHAR *v24; // rdx
  NTSTATUS v25; // edi
  struct _UNICODE_STRING Destination; // [rsp+68h] [rbp-230h] BYREF
  struct _UNICODE_STRING DosName; // [rsp+78h] [rbp-220h] BYREF
  void *FileHandle; // [rsp+88h] [rbp-210h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+90h] [rbp-208h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+C0h] [rbp-1D8h] BYREF
  _BYTE InputBuffer[144]; // [rsp+D0h] [rbp-1C8h] BYREF
  WCHAR SourceString[128]; // [rsp+160h] [rbp-138h] BYREF

  wcscpy(SourceString, L"\\??\\C:");
  memset(&SourceString[7], 0, 0xF2u);
  v2 = false;
  if ( P != nullptr )
  {
    ExFreePoolWithTag(P, 0x74706B64u);
    if ( qword_280074BD0 != nullptr )
      qword_280074BD0(sub_28005F028);
  }
  v3 = IoSetThreadHardErrorMode(0);
  ExAcquireFastMutex(&stru_280075760);
  for ( i = DriverObject->DeviceObject; i != nullptr; i = i->NextDevice )
  {
    if ( i == DeviceObject || *(_DWORD *)i->DeviceExtension != 7680402 )
      continue;
    ObfReferenceObject(i);
    ExReleaseFastMutex(&stru_280075760);
    if ( IoVolumeDeviceToDosName(i, &DosName) >= 0 )
    {
      if ( DosName.Length >= 4u && DosName.Buffer[1] == 58 )
      {
        v5 = *DosName.Buffer;
        ExFreePoolWithTag(DosName.Buffer, 0);
        v6 = 0;
        do
        {
          v7 = aC0d9db60eB0ea4[v6++];
          *(_WORD *)&InputBuffer[v6 * 2 + 142] = v7;
        }
        while ( v7 != 0 );
        SourceString[4] = v5;
        RtlInitUnicodeString(&DosName, SourceString);
        PoolWithTag = ExAllocatePoolWithTag(PagedPool, DosName.Length + 2LL, 0x626E5450u);
        if ( PoolWithTag != nullptr )
          sub_28006A244(&DosName, PoolWithTag);
        if ( byte_2800742E9 == 0 )
          goto LABEL_27;
        v9 = 0;
        do
        {
          v10 = aCDiskpt0Sys[v9++];
          *(_WORD *)&InputBuffer[v9 * 2 + 142] = v10;
        }
        while ( v10 != 0 );
        SourceString[4] = v5;
        RtlInitUnicodeString(&DosName, SourceString);
        if ( (unsigned int)sub_28006BD6C(&DosName) == 536870914 )
          goto LABEL_27;
        p_DosName = &DosName;
      }
      else
      {
        ExFreePoolWithTag(DosName.Buffer, 0);
        if ( i == DeviceObject )
          goto LABEL_27;
        DeviceExtension = (const WCHAR *)i->DeviceExtension;
        if ( *(_DWORD *)DeviceExtension != 7680402 )
          goto LABEL_27;
        RtlInitUnicodeString(&DosName, DeviceExtension + 20);
        Destination.Buffer = SourceString;
        Destination.Length = 0;
        Destination.MaximumLength = 256;
        RtlAppendUnicodeStringToString(&Destination, &DosName);
        RtlAppendUnicodeToString(&Destination, L"\\{0D9DB60E-B0EA-4d53-A392-A5D274956846}");
        v13 = ExAllocatePoolWithTag(PagedPool, Destination.Length + 2LL, 0x626E5450u);
        if ( v13 != nullptr )
          sub_28006A244(&Destination, v13);
        if ( byte_2800742E9 == 0 )
          goto LABEL_27;
        Destination.Length = 0;
        Destination.MaximumLength = 256;
        Destination.Buffer = SourceString;
        RtlAppendUnicodeStringToString(&Destination, &DosName);
        RtlAppendUnicodeToString(&Destination, &Source);
        RtlAppendUnicodeToString(&Destination, L"diskpt0.sys");
        if ( (unsigned int)sub_28006BD6C(&Destination) == 536870914 )
          goto LABEL_27;
        p_DosName = &Destination;
      }
      sub_28006A044(p_DosName);
    }
LABEL_27:
    ExAcquireFastMutex(&stru_280075760);
    ObfDereferenceObject(i);
  }
  ExReleaseFastMutex(&stru_280075760);
  if ( byte_2800742E9 != 0 )
  {
    ExAcquireFastMutex(&stru_280075760);
    for ( j = DriverObject->DeviceObject; ; j = j->NextDevice )
    {
      if ( j == nullptr )
      {
        ExReleaseFastMutex(&stru_280075760);
        return IoSetThreadHardErrorMode(v3);
      }
      if ( j != DeviceObject && *(_DWORD *)j->DeviceExtension == 7680402 )
        break;
LABEL_59:
      ;
    }
    ObfReferenceObject(j);
    ExReleaseFastMutex(&stru_280075760);
    if ( IoVolumeDeviceToDosName(j, &DosName) >= 0 )
    {
      if ( DosName.Length >= 4u && DosName.Buffer[1] == 58 )
      {
        v15 = *DosName.Buffer;
        ExFreePoolWithTag(DosName.Buffer, 0);
        v16 = 0;
        do
        {
          v17 = aCDiskpt0Sys[v16++];
          *(_WORD *)&InputBuffer[v16 * 2 + 142] = v17;
        }
        while ( v17 != 0 );
        SourceString[4] = v15;
        RtlInitUnicodeString(&DosName, SourceString);
        if ( (unsigned int)sub_28006BD6C(&DosName) != 536870914 )
          goto LABEL_58;
        if ( !v2 && byte_280074A24 >= 0 )
          v2 = sub_28005E6DC() >= 0;
        v18 = 0;
        do
        {
          v19 = *(const wchar_t *)((char *)&qword_280070910 + v18);
          v18 += 2;
          *(_WORD *)&InputBuffer[v18 + 142] = v19;
        }
        while ( v19 != 0 );
        SourceString[4] = v15;
        RtlInitUnicodeString(&DosName, SourceString);
        ObjectAttributes.Length = 48;
        ObjectAttributes.RootDirectory = nullptr;
        ObjectAttributes.Attributes = 576;
        ObjectAttributes.ObjectName = &DosName;
        ObjectAttributes.SecurityDescriptor = nullptr;
        ObjectAttributes.SecurityQualityOfService = nullptr;
        if ( ZwCreateFile(
               &FileHandle,
               0x100001u,
               &ObjectAttributes,
               &IoStatusBlock,
               nullptr,
               0,
               3u,
               1u,
               0x60u,
               nullptr,
               0) < 0 )
          goto LABEL_58;
        v20 = ZwDeviceIoControlFile(
                FileHandle,
                nullptr,
                nullptr,
                nullptr,
                &IoStatusBlock,
                0x80002D48,
                InputBuffer,
                0x88u,
                InputBuffer,
                0x88u);
        ZwClose(FileHandle);
        if ( v20 >= 0 )
          goto LABEL_58;
        v21 = 0;
        do
        {
          v22 = aCDiskpt0Sys[v21++];
          *(_WORD *)&InputBuffer[v21 * 2 + 142] = v22;
        }
        while ( v22 != 0 );
        SourceString[4] = v15;
        RtlInitUnicodeString(&DosName, SourceString);
        p_Destination = &DosName;
      }
      else
      {
        ExFreePoolWithTag(DosName.Buffer, 0);
        if ( j == DeviceObject )
          goto LABEL_58;
        v24 = (const WCHAR *)j->DeviceExtension;
        if ( *(_DWORD *)v24 != 7680402 )
          goto LABEL_58;
        RtlInitUnicodeString(&DosName, v24 + 20);
        Destination.Buffer = SourceString;
        Destination.Length = 0;
        Destination.MaximumLength = 256;
        RtlAppendUnicodeStringToString(&Destination, &DosName);
        RtlAppendUnicodeToString(&Destination, &Source);
        RtlAppendUnicodeToString(&Destination, L"diskpt0.sys");
        if ( (unsigned int)sub_28006BD6C(&Destination) != 536870914 )
          goto LABEL_58;
        if ( !v2 )
          v2 = sub_28005E6DC() >= 0;
        ObjectAttributes.Length = 48;
        ObjectAttributes.RootDirectory = nullptr;
        ObjectAttributes.Attributes = 576;
        ObjectAttributes.ObjectName = &DosName;
        ObjectAttributes.SecurityDescriptor = nullptr;
        ObjectAttributes.SecurityQualityOfService = nullptr;
        if ( ZwCreateFile(
               &FileHandle,
               0x100001u,
               &ObjectAttributes,
               &IoStatusBlock,
               nullptr,
               0,
               3u,
               1u,
               0x60u,
               nullptr,
               0) < 0 )
          goto LABEL_58;
        v25 = ZwDeviceIoControlFile(
                FileHandle,
                nullptr,
                nullptr,
                nullptr,
                &IoStatusBlock,
                0x80002D48,
                InputBuffer,
                0x88u,
                InputBuffer,
                0x88u);
        ZwClose(FileHandle);
        if ( v25 >= 0 )
          goto LABEL_58;
        Destination.Length = 0;
        Destination.MaximumLength = 256;
        Destination.Buffer = SourceString;
        RtlAppendUnicodeStringToString(&Destination, &DosName);
        RtlAppendUnicodeToString(&Destination, &Source);
        RtlAppendUnicodeToString(&Destination, L"diskpt0.sys");
        p_Destination = &Destination;
      }
      sub_28006A044(p_Destination);
    }
LABEL_58:
    ExAcquireFastMutex(&stru_280075760);
    ObfDereferenceObject(j);
    goto LABEL_59;
  }
  return IoSetThreadHardErrorMode(v3);
}


// ===== sub_28005F028 @ 0x28005f028 size=0x4e1 =====
void __fastcall sub_28005F028(__int64 a1)
{
  unsigned __int16 v2; // dx
  __int64 v3; // rcx
  __int64 v4; // rcx
  __int64 v5; // rcx
  __int64 v6; // rcx
  __int64 v7; // rcx
  struct _WORK_QUEUE_ITEM *PoolWithTag; // rax

  if ( byte_2800742E8 == 0 )
    return;
  v2 = *(_WORD *)a1 >> 1;
  if ( (byte_280074A24 & 0x40) == 0 )
    goto LABEL_28;
  if ( v2 > 0xCu )
  {
    v3 = *(_QWORD *)(a1 + 8);
    if ( *(_WORD *)(v3 + 2LL * v2 - 26) == 92
      && (*(_WORD *)(v3 + 2LL * v2 - 2) == 101 || *(_WORD *)(v3 + 2LL * v2 - 2) == 69)
      && (*(_WORD *)(v3 + 2LL * v2 - 4) == 120 || *(_WORD *)(v3 + 2LL * v2 - 4) == 88)
      && (*(_WORD *)(v3 + 2LL * v2 - 6) == 101 || *(_WORD *)(v3 + 2LL * v2 - 6) == 69)
      && *(_WORD *)(v3 + 2LL * v2 - 8) == 46
      && (*(_WORD *)(v3 + 2LL * v2 - 10) == 110 || *(_WORD *)(v3 + 2LL * v2 - 10) == 78)
      && (*(_WORD *)(v3 + 2LL * v2 - 12) == 111 || *(_WORD *)(v3 + 2LL * v2 - 12) == 79)
      && (*(_WORD *)(v3 + 2LL * v2 - 14) == 103 || *(_WORD *)(v3 + 2LL * v2 - 14) == 71)
      && (*(_WORD *)(v3 + 2LL * v2 - 16) == 111 || *(_WORD *)(v3 + 2LL * v2 - 16) == 79)
      && (*(_WORD *)(v3 + 2LL * v2 - 18) == 108 || *(_WORD *)(v3 + 2LL * v2 - 18) == 76)
      && (*(_WORD *)(v3 + 2LL * v2 - 20) == 110 || *(_WORD *)(v3 + 2LL * v2 - 20) == 78)
      && (*(_WORD *)(v3 + 2LL * v2 - 22) == 105 || *(_WORD *)(v3 + 2LL * v2 - 22) == 73)
      && (*(_WORD *)(v3 + 2LL * v2 - 24) == 119 || *(_WORD *)(v3 + 2LL * v2 - 24) == 87) )
    {
      goto LABEL_121;
    }
LABEL_28:
    if ( v2 > 0xCu )
    {
      v4 = *(_QWORD *)(a1 + 8);
      if ( *(_WORD *)(v4 + 2LL * v2 - 26) == 92
        && (*(_WORD *)(v4 + 2LL * v2 - 2) == 101 || *(_WORD *)(v4 + 2LL * v2 - 2) == 69)
        && (*(_WORD *)(v4 + 2LL * v2 - 4) == 120 || *(_WORD *)(v4 + 2LL * v2 - 4) == 88)
        && (*(_WORD *)(v4 + 2LL * v2 - 6) == 101 || *(_WORD *)(v4 + 2LL * v2 - 6) == 69)
        && *(_WORD *)(v4 + 2LL * v2 - 8) == 46
        && (*(_WORD *)(v4 + 2LL * v2 - 10) == 114 || *(_WORD *)(v4 + 2LL * v2 - 10) == 82)
        && (*(_WORD *)(v4 + 2LL * v2 - 12) == 101 || *(_WORD *)(v4 + 2LL * v2 - 12) == 69)
        && (*(_WORD *)(v4 + 2LL * v2 - 14) == 114 || *(_WORD *)(v4 + 2LL * v2 - 14) == 82)
        && (*(_WORD *)(v4 + 2LL * v2 - 16) == 111 || *(_WORD *)(v4 + 2LL * v2 - 16) == 79)
        && (*(_WORD *)(v4 + 2LL * v2 - 18) == 108 || *(_WORD *)(v4 + 2LL * v2 - 18) == 76)
        && (*(_WORD *)(v4 + 2LL * v2 - 20) == 112 || *(_WORD *)(v4 + 2LL * v2 - 20) == 80)
        && (*(_WORD *)(v4 + 2LL * v2 - 22) == 120 || *(_WORD *)(v4 + 2LL * v2 - 22) == 88)
        && (*(_WORD *)(v4 + 2LL * v2 - 24) == 101 || *(_WORD *)(v4 + 2LL * v2 - 24) == 69) )
      {
        byte_280074E95 = 1;
LABEL_121:
        byte_2800742E8 = 0;
        PoolWithTag = (struct _WORK_QUEUE_ITEM *)ExAllocatePoolWithTag(NonPagedPool, 0x20u, 0x74706B64u);
        if ( PoolWithTag != nullptr )
        {
          PoolWithTag->List.Flink = nullptr;
          PoolWithTag->WorkerRoutine = (PWORKER_THREAD_ROUTINE)sub_28005E7CC;
          PoolWithTag->Parameter = PoolWithTag;
          ExQueueWorkItem(PoolWithTag, DelayedWorkQueue);
        }
        else
        {
          sub_28005E7CC(nullptr);
        }
        return;
      }
    }
  }
  if ( v2 > 0xBu )
  {
    v5 = *(_QWORD *)(a1 + 8);
    if ( *(_WORD *)(v5 + 2LL * v2 - 24) == 92
      && (*(_WORD *)(v5 + 2LL * v2 - 2) == 101 || *(_WORD *)(v5 + 2LL * v2 - 2) == 69)
      && (*(_WORD *)(v5 + 2LL * v2 - 4) == 120 || *(_WORD *)(v5 + 2LL * v2 - 4) == 88)
      && (*(_WORD *)(v5 + 2LL * v2 - 6) == 101 || *(_WORD *)(v5 + 2LL * v2 - 6) == 69)
      && *(_WORD *)(v5 + 2LL * v2 - 8) == 46
      && (*(_WORD *)(v5 + 2LL * v2 - 10) == 116 || *(_WORD *)(v5 + 2LL * v2 - 10) == 84)
      && (*(_WORD *)(v5 + 2LL * v2 - 12) == 115 || *(_WORD *)(v5 + 2LL * v2 - 12) == 83)
      && (*(_WORD *)(v5 + 2LL * v2 - 14) == 111 || *(_WORD *)(v5 + 2LL * v2 - 14) == 79)
      && (*(_WORD *)(v5 + 2LL * v2 - 16) == 104 || *(_WORD *)(v5 + 2LL * v2 - 16) == 72)
      && (*(_WORD *)(v5 + 2LL * v2 - 18) == 110 || *(_WORD *)(v5 + 2LL * v2 - 18) == 78)
      && (*(_WORD *)(v5 + 2LL * v2 - 20) == 111 || *(_WORD *)(v5 + 2LL * v2 - 20) == 79)
      && (*(_WORD *)(v5 + 2LL * v2 - 22) == 99 || *(_WORD *)(v5 + 2LL * v2 - 22) == 67) )
    {
      goto LABEL_121;
    }
  }
  if ( v2 > 0xAu )
  {
    v6 = *(_QWORD *)(a1 + 8);
    if ( *(_WORD *)(v6 + 2LL * v2 - 22) == 92
      && (*(_WORD *)(v6 + 2LL * v2 - 2) == 101 || *(_WORD *)(v6 + 2LL * v2 - 2) == 69)
      && (*(_WORD *)(v6 + 2LL * v2 - 4) == 120 || *(_WORD *)(v6 + 2LL * v2 - 4) == 88)
      && (*(_WORD *)(v6 + 2LL * v2 - 6) == 101 || *(_WORD *)(v6 + 2LL * v2 - 6) == 69)
      && *(_WORD *)(v6 + 2LL * v2 - 8) == 46
      && (*(_WORD *)(v6 + 2LL * v2 - 10) == 116 || *(_WORD *)(v6 + 2LL * v2 - 10) == 84)
      && (*(_WORD *)(v6 + 2LL * v2 - 12) == 115 || *(_WORD *)(v6 + 2LL * v2 - 12) == 83)
      && (*(_WORD *)(v6 + 2LL * v2 - 14) == 111 || *(_WORD *)(v6 + 2LL * v2 - 14) == 79)
      && (*(_WORD *)(v6 + 2LL * v2 - 16) == 104 || *(_WORD *)(v6 + 2LL * v2 - 16) == 72)
      && (*(_WORD *)(v6 + 2LL * v2 - 18) == 105 || *(_WORD *)(v6 + 2LL * v2 - 18) == 73)
      && (*(_WORD *)(v6 + 2LL * v2 - 20) == 115 || *(_WORD *)(v6 + 2LL * v2 - 20) == 83) )
    {
      goto LABEL_121;
    }
  }
  if ( v2 > 0xBu )
  {
    v7 = *(_QWORD *)(a1 + 8);
    if ( *(_WORD *)(v7 + 2LL * v2 - 24) == 92
      && (*(_WORD *)(v7 + 2LL * v2 - 2) == 101 || *(_WORD *)(v7 + 2LL * v2 - 2) == 69)
      && (*(_WORD *)(v7 + 2LL * v2 - 4) == 120 || *(_WORD *)(v7 + 2LL * v2 - 4) == 88)
      && (*(_WORD *)(v7 + 2LL * v2 - 6) == 101 || *(_WORD *)(v7 + 2LL * v2 - 6) == 69)
      && *(_WORD *)(v7 + 2LL * v2 - 8) == 46
      && (*(_WORD *)(v7 + 2LL * v2 - 10) == 116 || *(_WORD *)(v7 + 2LL * v2 - 10) == 84)
      && (*(_WORD *)(v7 + 2LL * v2 - 12) == 115 || *(_WORD *)(v7 + 2LL * v2 - 12) == 83)
      && (*(_WORD *)(v7 + 2LL * v2 - 14) == 111 || *(_WORD *)(v7 + 2LL * v2 - 14) == 79)
      && (*(_WORD *)(v7 + 2LL * v2 - 16) == 104 || *(_WORD *)(v7 + 2LL * v2 - 16) == 72)
      && (*(_WORD *)(v7 + 2LL * v2 - 18) == 108 || *(_WORD *)(v7 + 2LL * v2 - 18) == 76)
      && (*(_WORD *)(v7 + 2LL * v2 - 20) == 108 || *(_WORD *)(v7 + 2LL * v2 - 20) == 76)
      && (*(_WORD *)(v7 + 2LL * v2 - 22) == 100 || *(_WORD *)(v7 + 2LL * v2 - 22) == 68) )
    {
      goto LABEL_121;
    }
  }
}


// ===== sub_28005F510 @ 0x28005f510 size=0xb3 =====
struct _SLIST_ENTRY *__fastcall sub_28005F510(PDEVICE_OBJECT TargetDevice, char a2)
{
  PDEVICE_OBJECT v3; // rdi
  struct _SLIST_ENTRY *result; // rax
  struct _SLIST_ENTRY *v5; // rsi
  struct _DEVICE_OBJECT *i; // rbx

  v3 = TargetDevice;
  result = (struct _SLIST_ENTRY *)sub_28006C5B4(TargetDevice);
  v5 = result;
  if ( result != nullptr )
  {
    if ( a2 != 0 )
    {
      sub_2800654DC(v3, result);
    }
    else
    {
      for ( i = v3->AttachedDevice; i != nullptr; i = i->AttachedDevice )
      {
        if ( i != DeviceObject && *(_DWORD *)i->DeviceExtension == 7680401 )
        {
          sub_2800657F4(i);
          IoDetachDevice(v3);
          ExAcquireFastMutex(&stru_280075760);
          IoDeleteDevice(i);
          ExReleaseFastMutex(&stru_280075760);
          return (struct _SLIST_ENTRY *)sub_28006C8A8(v5);
        }
        v3 = i;
      }
    }
    return (struct _SLIST_ENTRY *)sub_28006C8A8(v5);
  }
  return result;
}


// ===== sub_28005F5CC @ 0x28005f5cc size=0x372 =====
NTSTATUS __fastcall sub_28005F5CC(__int64 a1)
{
  __int64 v1; // rbx
  IRP *v2; // r10
  struct _DEVICE_OBJECT *v3; // r11
  __int64 v4; // rdx
  __int64 v5; // rcx
  __int64 (__fastcall *v6)(_QWORD, _QWORD); // r8
  _QWORD *v7; // rax
  __int64 v8; // rax
  struct _IO_STACK_LOCATION *CurrentStackLocation; // r8
  unsigned int MajorFunction; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  PDEVICE_OBJECT *DeviceExtension; // rcx
  IRP *v16; // rdx
  unsigned int v18; // ecx
  unsigned int v19; // ecx
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  int v22; // ebx

  v1 = *(_QWORD *)(a1 + 64);
  sub_28006BB34();
  if ( dword_280074A20 != 0 )
  {
    v4 = qword_280074D48;
    if ( qword_280074D68 != nullptr
      && *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074D48 + 144) != sub_28005C474 )
    {
      *(_QWORD *)(qword_280074D48 + 144) = sub_28005C474;
    }
    v5 = qword_280074D88;
    if ( qword_280074DA8 != nullptr
      && *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074D88 + 144) != sub_28005CCBC )
    {
      *(_QWORD *)(qword_280074D88 + 144) = sub_28005CCBC;
    }
    v6 = qword_280074DD0;
    v7 = (_QWORD *)qword_280074DB8;
    if ( qword_280074DD0 != nullptr )
    {
      if ( *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074DB8 + 232) != sub_28005D0A0 )
        *(_QWORD *)(qword_280074DB8 + 232) = sub_28005D0A0;
      if ( (void (__fastcall *)(__int64, IRP *))v7[12] != sub_28005DC1C )
        v7[12] = sub_28005DC1C;
    }
    if ( qword_280074D70 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(v4 + 232) != sub_28005C7C4 )
      *(_QWORD *)(v4 + 232) = sub_28005C7C4;
    if ( qword_280074DB0 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(v5 + 232) != sub_28005CF18 )
      *(_QWORD *)(v5 + 232) = sub_28005CF18;
    if ( v6 != nullptr && (__int64 (__fastcall *)(__int64, IRP *))v7[29] != sub_28005D0A0 )
      v7[29] = sub_28005D0A0;
    if ( qword_280074E08 != nullptr
      && *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074DF0 + 232) != sub_28005DD58 )
    {
      *(_QWORD *)(qword_280074DF0 + 232) = sub_28005DD58;
    }
    if ( qword_280074D78 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(v4 + 224) != sub_28005CA40 )
      *(_QWORD *)(v4 + 224) = sub_28005CA40;
    if ( qword_280074DD8 != nullptr && (__int64 (__fastcall *)(__int64, IRP *))v7[28] != sub_28005D718 )
      v7[28] = sub_28005D718;
    v8 = qword_280074E10;
    if ( qword_280074E30 != nullptr )
      *(_QWORD *)(qword_280074E10 + 144) = sub_28005E0D8;
    if ( qword_280074E38 != nullptr )
      *(_QWORD *)(v8 + 224) = sub_28005E294;
  }
  CurrentStackLocation = v2->Tail.Overlay.CurrentStackLocation;
  MajorFunction = CurrentStackLocation->MajorFunction;
  if ( MajorFunction > 9 )
  {
    v18 = MajorFunction - 13;
    if ( v18 != 0 )
    {
      v19 = v18 - 1;
      if ( v19 == 0 )
        return sub_2800630D8(v3, v2);
      v20 = v19 - 2;
      if ( v20 == 0 )
        return sub_280062D4C(v3, v2);
      v21 = v20 - 2;
      if ( v21 == 0 )
        return sub_2800600B0(v3, v2);
      if ( v21 == 9 )
        return sub_280063024(v3, v2);
      goto LABEL_55;
    }
    DeviceExtension = (PDEVICE_OBJECT *)v3->DeviceExtension;
    if ( v3 != DeviceObject )
    {
      if ( CurrentStackLocation->MinorFunction == 0 )
        return sub_280063C88(v3, v2);
      if ( CurrentStackLocation->MinorFunction == 1 )
        return sub_280064148(v3, v2);
      v16 = v2;
      if ( CurrentStackLocation->MinorFunction == 3 )
        return sub_280064860(v3, v2);
LABEL_46:
      ++v2->CurrentLocation;
      v2->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
      return IofCallDriver(DeviceExtension[2], v16);
    }
  }
  else
  {
    if ( MajorFunction == 9 )
      return sub_280062B18(v3, v2);
    if ( CurrentStackLocation->MajorFunction == 0 )
      return sub_28005F944(v3, v2);
    v11 = MajorFunction - 2;
    if ( v11 == 0 )
      return sub_280060344(v3, v2);
    v12 = v11 - 1;
    if ( v12 != 0 )
    {
      v13 = v12 - 1;
      if ( v13 == 0 )
        return sub_280062260(v3, v2);
      if ( v13 == 2 )
        return sub_2800606F0(v3, v2);
LABEL_55:
      if ( v3 != DeviceObject )
      {
        ++v2->CurrentLocation;
        v2->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
        return IofCallDriver(*(PDEVICE_OBJECT *)(v1 + 16), v2);
      }
      goto LABEL_62;
    }
    DeviceExtension = (PDEVICE_OBJECT *)v3->DeviceExtension;
    if ( v3 != DeviceObject )
    {
      v16 = v2;
      goto LABEL_46;
    }
  }
LABEL_62:
  v22 = -1073741808;
  v2->IoStatus.Status = -1073741808;
  v2->IoStatus.Information = 0;
  IofCompleteRequest(v2, 0);
  return v22;
}


// ===== sub_28005F944 @ 0x28005f944 size=0x765 =====
NTSTATUS __fastcall sub_28005F944(PDEVICE_OBJECT OwnerId, PIRP Irp)
{
  int v2; // ebx
  PDEVICE_OBJECT *DeviceExtension; // rsi
  struct _IO_STACK_LOCATION *CurrentStackLocation; // r15
  PIRP v5; // rdi
  struct _IO_WORKITEM *WorkItem; // rax
  struct _KTHREAD *CurrentThread; // rbx
  PEPROCESS CurrentProcess; // rax
  PFILE_OBJECT FileObject; // rcx
  int v12; // ebx
  PFILE_OBJECT v13; // rcx
  struct _KTHREAD *v14; // rbx
  PEPROCESS v15; // rax
  PFILE_OBJECT v16; // rcx
  NTSTATUS v17; // eax
  NTSTATUS v18; // esi
  PFILE_OBJECT v19; // rcx
  NTSTATUS v20; // eax
  int v21; // ebp
  struct _DEVICE_OBJECT *v22; // rcx
  bool v23; // r13
  NTSTATUS v24; // eax
  PFILE_OBJECT v25; // rax
  _BYTE *FsContext; // rcx
  PSLIST_ENTRY v27; // r14
  FSRTL_ADVANCED_FCB_HEADER *v28; // r13
  PFSRTL_PER_STREAM_CONTEXT v29; // r12
  NTSTATUS inserted; // ebx
  PFILE_OBJECT v31; // rax
  PSLIST_ENTRY v32; // r14
  PVOID FsContext2; // rbx
  int v34; // eax
  struct _SLIST_ENTRY *v35; // rcx
  bool v36; // bl
  struct _SLIST_ENTRY *Flink; // rcx
  int v38; // r14d
  struct _SLIST_ENTRY *v39; // rbx
  unsigned int v40; // edx
  struct _SLIST_ENTRY *v41; // rcx
  NTSTATUS v42; // [rsp+30h] [rbp-68h]
  int Blink; // [rsp+34h] [rbp-64h]
  bool v44; // [rsp+38h] [rbp-60h]
  PSLIST_ENTRY ListEntry; // [rsp+40h] [rbp-58h] BYREF
  PFAST_MUTEX FastMutex; // [rsp+48h] [rbp-50h]
  bool v47; // [rsp+A0h] [rbp+8h] BYREF
  char v48; // [rsp+A8h] [rbp+10h] BYREF
  unsigned int Blink_high; // [rsp+B0h] [rbp+18h] BYREF
  int v50; // [rsp+B8h] [rbp+20h]

  DeviceExtension = (PDEVICE_OBJECT *)OwnerId->DeviceExtension;
  CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
  LOBYTE(v2) = 0;
  v5 = Irp;
  v50 = v2;
  if ( OwnerId == DeviceObject )
  {
    CurrentStackLocation->FileObject->FsContext = nullptr;
    Irp->IoStatus.Status = 0;
    Irp->IoStatus.Information = 1;
    IofCompleteRequest(Irp, 0);
    return 0;
  }
  if ( DeviceExtension[3] == nullptr )
  {
    ++Irp->CurrentLocation;
    Irp->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
    return IofCallDriver(DeviceExtension[2], Irp);
  }
  if ( _InterlockedCompareExchange(&dword_280074EEC, 1, 0) == 0 )
  {
    WorkItem = IoAllocateWorkItem(OwnerId);
    if ( WorkItem != nullptr )
      IoQueueWorkItem(WorkItem, WorkerRoutine, DelayedWorkQueue, WorkItem);
    else
      WorkerRoutine(OwnerId, nullptr);
  }
  if ( *((_DWORD *)DeviceExtension + 19) == 3 )
  {
    CurrentThread = KeGetCurrentThread();
    CurrentProcess = IoGetCurrentProcess();
    if ( sub_2800521C4((__int64)CurrentProcess, (__int64)CurrentThread, 1) == 0 )
    {
      FileObject = CurrentStackLocation->FileObject;
      if ( FileObject->FileName.Length != 2 || _wcsnicmp(FileObject->FileName.Buffer, L"\\", 1u) != 0 )
      {
        v12 = -1073741772;
LABEL_25:
        v5->IoStatus.Information = 0;
        v5->IoStatus.Status = v12;
        IofCompleteRequest(v5, 0);
        return v12;
      }
    }
    LOBYTE(v2) = v50;
  }
  v13 = CurrentStackLocation->FileObject;
  if ( v13->FileName.Length == 24 && v13->RelatedFileObject == nullptr )
  {
    v2 = (unsigned __int8)v2;
    if ( _wcsnicmp(v13->FileName.Buffer, L"\\diskpt0.sys", 0xCu) == 0 )
      v2 = 1;
    v50 = v2;
  }
  if ( *((_DWORD *)DeviceExtension + 19) != 2 )
    goto LABEL_27;
  if ( (_BYTE)v2 != 0 )
  {
    v14 = KeGetCurrentThread();
    v15 = IoGetCurrentProcess();
    if ( sub_2800521C4((__int64)v15, (__int64)v14, 1) == 0 )
    {
      v12 = -1073741790;
      goto LABEL_25;
    }
  }
  if ( *((_DWORD *)DeviceExtension + 19) != 2 )
  {
LABEL_27:
    if ( *((_DWORD *)DeviceExtension + 19) != 1 )
    {
      ++v5->CurrentLocation;
      ++v5->Tail.Overlay.CurrentStackLocation;
      Irp = v5;
      return IofCallDriver(DeviceExtension[2], Irp);
    }
  }
  if ( !_bittest((const signed __int32 *)&DeviceExtension[3]->Flags, 8u)
    || (v16 = CurrentStackLocation->FileObject)->FileName.Length != 26
    || v16->RelatedFileObject != nullptr
    || _wcsnicmp(v16->FileName.Buffer, L"\\hiberfil.sys", 0xDu) != 0 )
  {
    v19 = CurrentStackLocation->FileObject;
    if ( v19->FileName.Length == 26
      && v19->RelatedFileObject == nullptr
      && _wcsnicmp(v19->FileName.Buffer, L"\\pagefile.sys", 0xDu) == 0 )
    {
      v20 = sub_2800513D0(DeviceExtension[2], v5);
      v21 = v20;
      if ( v20 >= 0 && v20 != 260 )
        DeviceExtension[68] = (PDEVICE_OBJECT)CurrentStackLocation->FileObject;
      IofCompleteRequest(v5, 0);
      if ( v21 >= 0
        && v21 != 260
        && _bittest((const signed __int32 *)&DeviceExtension[3]->Flags, 8u)
        && *((_DWORD *)DeviceExtension + 19) == 2
        && (int)sub_280052014((__int64)KeGetCurrentThread()) >= 0 )
      {
        sub_28006655C(OwnerId);
        sub_2800520DC((__int64)KeGetCurrentThread());
      }
      return v21;
    }
    v22 = DeviceExtension[2];
    v23 = (CurrentStackLocation->Parameters.Create.Options & 0x1000) != 0;
    v44 = (CurrentStackLocation->Parameters.Create.Options & 0x40) == 0;
    v47 = v44;
    v24 = sub_2800513D0(v22, v5);
    v42 = v24;
    if ( v24 < 0 )
      goto LABEL_103;
    if ( v24 == 260 )
      goto LABEL_103;
    v25 = CurrentStackLocation->FileObject;
    ListEntry = nullptr;
    FsContext = v25->FsContext;
    Blink = 0x80000000;
    Blink_high = 0;
    if ( FsContext == nullptr || (FsContext[6] & 2) == 0 )
      goto LABEL_103;
    if ( v23 )
      v25->Flags |= 0x10000u;
    ++dword_280074994;
    v27 = ExpInterlockedPopEntrySList(&stru_280074980);
    if ( v27 == nullptr )
    {
      ++dword_280074998;
      v27 = (PSLIST_ENTRY)qword_2800749B0(
                            (unsigned int)dword_2800749A4,
                            (unsigned int)dword_2800749AC,
                            (unsigned int)dword_2800749A8);
      if ( v27 == nullptr )
      {
LABEL_103:
        IofCompleteRequest(v5, 0);
        return v42;
      }
    }
    LODWORD(v27[3].Next) = 0x80000000;
    v27[1].Next = (struct _SLIST_ENTRY *)OwnerId;
    *((_QWORD *)&v27[1].Next + 1) = 0;
    *((_QWORD *)&v27[2].Next + 1) = 0;
    HIDWORD(v27[3].Next) = 0;
    *((_BYTE *)&v27[3].Next + 8) = 0;
    *((_BYTE *)&v27[3].Next + 9) = 0;
    v27[2].Next = (struct _SLIST_ENTRY *)sub_28006AFF0;
    v28 = (FSRTL_ADVANCED_FCB_HEADER *)CurrentStackLocation->FileObject->FsContext;
    FastMutex = (PFAST_MUTEX)&DeviceExtension[7 * (((unsigned int)v28 >> 8) & 7) + 11];
    ExAcquireFastMutex(FastMutex);
    if ( v28 != nullptr && (v28->Flags2 & 2) != 0 && v28->FilterContexts.Flink != &v28->FilterContexts )
      v29 = FsRtlLookupPerStreamContextInternal(v28, OwnerId, nullptr);
    else
      v29 = nullptr;
    if ( v29 != nullptr )
    {
      ExReleaseFastMutex(FastMutex);
      sub_28006AFFC(v27);
      ExAcquireFastMutex(v28->FastMutex);
      if ( (_BYTE)v50 != 0 )
      {
        LODWORD(v29[1].Links.Blink) = 0x20000;
        Blink = 0x20000;
        goto LABEL_73;
      }
      Blink = (int)v29[1].Links.Blink;
      Blink_high = HIDWORD(v29[1].Links.Blink);
    }
    else
    {
      inserted = FsRtlInsertPerStreamContext(v28, (PFSRTL_PER_STREAM_CONTEXT)v27);
      ExReleaseFastMutex(FastMutex);
      if ( inserted < 0 )
      {
        sub_28006AFFC(v27);
        goto LABEL_103;
      }
      v29 = (PFSRTL_PER_STREAM_CONTEXT)v27;
      ExAcquireFastMutex(v28->FastMutex);
      if ( (_BYTE)v50 != 0 )
      {
        LODWORD(v27[3].Next) = 0x20000;
LABEL_73:
        Blink_high = -1;
      }
    }
    ExReleaseFastMutex(v28->FastMutex);
    if ( (int)sub_28006C80C(&ListEntry, &Lookaside) < 0 )
      goto LABEL_103;
    if ( *((_DWORD *)DeviceExtension + 20) == 2 && MajorVersion == 5 )
    {
      v31 = CurrentStackLocation->FileObject;
      v32 = ListEntry;
      FsContext2 = v31->FsContext2;
      v31->FsContext2 = nullptr;
      v34 = sub_28006C0EC(
              CurrentStackLocation->FileObject,
              (_DWORD)v32,
              (int)DeviceExtension + 8,
              32,
              (unsigned int)&Lookaside,
              (__int64)&v48);
      CurrentStackLocation->FileObject->FsContext2 = FsContext2;
    }
    else
    {
      v32 = ListEntry;
      v34 = sub_28006C0EC(
              CurrentStackLocation->FileObject,
              (_DWORD)ListEntry,
              (int)DeviceExtension + 8,
              32,
              (unsigned int)&Lookaside,
              (__int64)&v48);
    }
    if ( v34 < 0 )
      goto LABEL_81;
    v36 = v44;
    if ( v44 )
    {
      if ( (int)sub_28006B064(CurrentStackLocation->FileObject, DeviceExtension[2], &v47) < 0
        && *((_WORD *)&v32->Next + 4) > 4u )
      {
LABEL_81:
        v35 = v32;
LABEL_102:
        sub_28006C8A8(v35);
        goto LABEL_103;
      }
      v36 = v47;
    }
    ExAcquireFastMutex(v28->FastMutex);
    Flink = (struct _SLIST_ENTRY *)v29[1].Links.Flink;
    v29[1].Links.Flink = (struct _LIST_ENTRY *)v32;
    BYTE1(v29[1].OwnerId) = v36;
    if ( Flink != nullptr )
      sub_28006C8A8(Flink);
    _InterlockedAdd((volatile signed __int32 *)v32, 1u);
    ExReleaseFastMutex(v28->FastMutex);
    if ( *((_DWORD *)DeviceExtension + 19) == 2 )
    {
      v38 = Blink;
      v39 = ListEntry;
      if ( Blink < 0 || Blink_high < dword_2800742E4 )
      {
        v38 = sub_280066C40(ListEntry, 0, &Blink_high);
        ExAcquireFastMutex(v28->FastMutex);
        LODWORD(v29[1].Links.Blink) &= 0xFF0000u;
        v40 = Blink_high;
        LODWORD(v29[1].Links.Blink) |= v38;
        HIDWORD(v29[1].Links.Blink) = v40;
        ExReleaseFastMutex(v28->FastMutex);
      }
      if ( (v38 & 0x10001) == 0 )
      {
        sub_28006C8A8(v39);
        ExAcquireFastMutex(v28->FastMutex);
        v41 = (struct _SLIST_ENTRY *)v29[1].Links.Flink;
        if ( v41 != nullptr )
        {
          sub_28006C8A8(v41);
          v29[1].Links.Flink = nullptr;
        }
        ExReleaseFastMutex(v28->FastMutex);
        goto LABEL_103;
      }
      if ( v5->IoStatus.Information == 1 || v5->IoStatus.Information == 5 )
        goto LABEL_101;
      if ( (int)sub_280052014((__int64)KeGetCurrentThread()) >= 0 )
      {
        sub_2800676BC(DeviceExtension, ListEntry);
        sub_2800520DC((__int64)KeGetCurrentThread());
      }
    }
    v39 = ListEntry;
LABEL_101:
    v35 = v39;
    goto LABEL_102;
  }
  if ( *((_DWORD *)DeviceExtension + 19) == 2 )
  {
    v12 = sub_280052014((__int64)KeGetCurrentThread());
    if ( v12 < 0 )
      goto LABEL_25;
    v12 = sub_280065FC0(OwnerId);
    sub_2800520DC((__int64)KeGetCurrentThread());
    if ( v12 < 0 )
      goto LABEL_25;
  }
  v17 = sub_2800513D0(DeviceExtension[2], v5);
  v18 = v17;
  if ( v17 >= 0 && v17 != 260 )
    qword_280074F00 = (__int64)CurrentStackLocation->FileObject;
  IofCompleteRequest(v5, 0);
  return v18;
}


// ===== sub_2800600B0 @ 0x2800600b0 size=0x28e =====
NTSTATUS __fastcall sub_2800600B0(PDEVICE_OBJECT OwnerId, PIRP Irp)
{
  PVOID DeviceExtension; // rsi
  PIRP v3; // rbx
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rbp
  struct _FILE_OBJECT *v7; // rax
  FSRTL_ADVANCED_FCB_HEADER *FsContext; // rbp
  PFSRTL_PER_STREAM_CONTEXT v9; // r13
  volatile signed __int32 *Flink; // r12
  struct _FAST_MUTEX *FastMutex; // rcx
  int Blink; // r15d
  int v13; // r11d
  struct _SLIST_ENTRY *v14; // rcx
  PFILE_OBJECT FileObject; // rcx
  NTSTATUS v16; // esi
  _BYTE *PoolWithTagPriority; // rax
  unsigned int v18; // [rsp+60h] [rbp+8h] BYREF
  unsigned int Blink_high; // [rsp+70h] [rbp+18h]

  DeviceExtension = OwnerId->DeviceExtension;
  v3 = Irp;
  if ( OwnerId == DeviceObject )
  {
    Irp->IoStatus.Status = 0;
    Irp->IoStatus.Information = 0;
    IofCompleteRequest(Irp, 0);
    return 0;
  }
  if ( *((_QWORD *)DeviceExtension + 3) == 0 || *((_DWORD *)DeviceExtension + 19) != 2 )
  {
    ++Irp->CurrentLocation;
    ++Irp->Tail.Overlay.CurrentStackLocation;
    return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
  }
  CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
  if ( qword_280074F00 != 0 && CurrentStackLocation->FileObject == (PFILE_OBJECT)qword_280074F00
    || (v7 = *((struct _FILE_OBJECT **)DeviceExtension + 68)) != nullptr && CurrentStackLocation->FileObject == v7 )
  {
    ++Irp->CurrentLocation;
    Irp->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
    return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
  }
  if ( qword_280074B68 != nullptr && (unsigned int)qword_280074B68(CurrentStackLocation->FileObject) != 0 )
    goto LABEL_14;
  FsContext = (FSRTL_ADVANCED_FCB_HEADER *)CurrentStackLocation->FileObject->FsContext;
  if ( FsContext != nullptr
    && (FsContext->Flags2 & 2) != 0
    && FsContext->FilterContexts.Flink != &FsContext->FilterContexts )
  {
    v9 = FsRtlLookupPerStreamContextInternal(FsContext, OwnerId, nullptr);
  }
  else
  {
    v9 = nullptr;
  }
  if ( v9 == nullptr )
    goto LABEL_14;
  ExAcquireFastMutex(FsContext->FastMutex);
  Flink = (volatile signed __int32 *)v9[1].Links.Flink;
  if ( Flink != nullptr )
    _InterlockedAdd(Flink, 1u);
  FastMutex = FsContext->FastMutex;
  Blink = (int)v9[1].Links.Blink;
  Blink_high = HIDWORD(v9[1].Links.Blink);
  v18 = Blink_high;
  ExReleaseFastMutex(FastMutex);
  if ( Flink == nullptr )
    goto LABEL_14;
  if ( Blink < 0 || Blink_high < dword_2800742E4 )
  {
    Blink = sub_280066C40(Flink, 0, &v18);
    ExAcquireFastMutex(FsContext->FastMutex);
    v13 = Blink | (__int64)v9[1].Links.Blink & 0xFF0000;
    HIDWORD(v9[1].Links.Blink) = v18;
    LODWORD(v9[1].Links.Blink) = v13;
    ExReleaseFastMutex(FsContext->FastMutex);
  }
  if ( (Blink & 0x10001) == 0 )
  {
    sub_28006C8A8((PSLIST_ENTRY)Flink);
    ExAcquireFastMutex(FsContext->FastMutex);
    v14 = (struct _SLIST_ENTRY *)v9[1].Links.Flink;
    if ( v14 != nullptr )
    {
      sub_28006C8A8(v14);
      v9[1].Links.Flink = nullptr;
    }
    ExReleaseFastMutex(FsContext->FastMutex);
    goto LABEL_14;
  }
  if ( (Blink & 1) == 0
    || (FileObject = v3->Tail.Overlay.CurrentStackLocation->FileObject)->DeletePending == 0
    && (FileObject->Flags & 0x10000) == 0 )
  {
    sub_28006C8A8((PSLIST_ENTRY)Flink);
LABEL_14:
    ++v3->CurrentLocation;
    ++v3->Tail.Overlay.CurrentStackLocation;
    Irp = v3;
    return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
  }
  v16 = sub_2800513D0(*((PDEVICE_OBJECT *)DeviceExtension + 2), v3);
  if ( v16 >= 0 )
  {
    PoolWithTagPriority = ExAllocatePoolWithTagPriority(PagedPool, 1u, 0x626E5450u, HighPoolPriority);
    if ( PoolWithTagPriority != nullptr )
    {
      *PoolWithTagPriority = 1;
      sub_280067350((_DWORD)OwnerId, (_DWORD)Flink, (_DWORD)PoolWithTagPriority, 1, 13);
    }
  }
  sub_28006C8A8((PSLIST_ENTRY)Flink);
  IofCompleteRequest(v3, 0);
  return v16;
}


// ===== sub_280060344 @ 0x280060344 size=0x3a3 =====
NTSTATUS __fastcall sub_280060344(PDEVICE_OBJECT OwnerId, PIRP Irp)
{
  PVOID DeviceExtension; // rbp
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  PIRP v4; // rbx
  PFILE_OBJECT FileObject; // rcx
  unsigned __int64 FsContext; // rbp
  _QWORD *v8; // rax
  __int64 v9; // r11
  struct _FAST_MUTEX *v10; // rcx
  _QWORD *v11; // rax
  __int64 v12; // r11
  PEPROCESS CurrentProcess; // rsi
  __int64 *i; // rcx
  __int64 *v15; // rdx
  __int64 *v16; // rax
  PEPROCESS v17; // rbp
  unsigned int v18; // r11d
  PEPROCESS *v19; // rcx
  struct _FILE_OBJECT *v21; // rcx
  FSRTL_ADVANCED_FCB_HEADER *v22; // r13
  PFSRTL_PER_STREAM_CONTEXT v23; // r12
  volatile signed __int32 *Flink; // r14
  struct _FAST_MUTEX *FastMutex; // rcx
  char v26; // al
  int v27; // r11d
  int Blink; // [rsp+60h] [rbp+8h]
  int v29; // [rsp+60h] [rbp+8h]
  unsigned int v30; // [rsp+68h] [rbp+10h] BYREF
  unsigned int Blink_high; // [rsp+70h] [rbp+18h]

  DeviceExtension = OwnerId->DeviceExtension;
  CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
  v4 = Irp;
  if ( OwnerId == DeviceObject )
  {
    FileObject = CurrentStackLocation->FileObject;
    FsContext = (unsigned __int64)FileObject->FsContext;
    if ( FsContext != 0 )
    {
      if ( FsContext <= 0x8000 )
      {
        if ( FsContext == 29521 )
        {
          CurrentProcess = IoGetCurrentProcess();
          ExAcquireFastMutex(&::FastMutex);
          for ( i = (__int64 *)qword_280075710; i != &qword_280075710; i = (__int64 *)*i )
          {
            if ( (PEPROCESS)i[2] == CurrentProcess )
            {
              v15 = (__int64 *)*i;
              v16 = (__int64 *)i[1];
              *v16 = *i;
              v15[1] = (__int64)v16;
              ExFreePoolWithTag(i, 0x74706B64u);
              break;
            }
          }
          v10 = &::FastMutex;
          goto LABEL_23;
        }
        if ( FsContext == 29522 )
        {
          FileObject->FsContext = nullptr;
          v17 = IoGetCurrentProcess();
          ExAcquireFastMutex(&stru_280075720);
          v18 = 0;
          v19 = (PEPROCESS *)qword_280074C20;
          while ( *v19 != v17 )
          {
            ++v18;
            ++v19;
            if ( v18 >= 0x20 )
              goto LABEL_22;
          }
          qword_280074C20[v18] = 0;
LABEL_22:
          v10 = &stru_280075720;
          goto LABEL_23;
        }
      }
      else
      {
        if ( *(_WORD *)(FsContext + 18) == 0 )
        {
          ExAcquireFastMutex(&stru_280075620);
          ObfDereferenceObject(*(PVOID *)(FsContext + 24));
          v8 = *(_QWORD **)(FsContext + 8);
          v9 = *(_QWORD *)FsContext;
          *v8 = *(_QWORD *)FsContext;
          *(_QWORD *)(v9 + 8) = v8;
          ExFreePoolWithTag((PVOID)FsContext, 0x74706B64u);
          v10 = &stru_280075620;
LABEL_23:
          ExReleaseFastMutex(v10);
          goto LABEL_24;
        }
        if ( *(_WORD *)(FsContext + 18) == 1 )
        {
          ExAcquireFastMutex(&stru_2800753E0);
          ObfDereferenceObject(*(PVOID *)(FsContext + 24));
          ObfDereferenceObject(*(PVOID *)(FsContext + 32));
          v11 = *(_QWORD **)(FsContext + 8);
          v12 = *(_QWORD *)FsContext;
          *v11 = *(_QWORD *)FsContext;
          *(_QWORD *)(v12 + 8) = v11;
          ExFreePoolWithTag((PVOID)FsContext, 0x74706B64u);
          v10 = &stru_2800753E0;
          goto LABEL_23;
        }
      }
    }
LABEL_24:
    v4->IoStatus.Status = 0;
    v4->IoStatus.Information = 0;
    IofCompleteRequest(v4, 0);
    return 0;
  }
  if ( *((_QWORD *)DeviceExtension + 3) == 0 )
    goto LABEL_26;
  if ( qword_280074F00 != 0 && CurrentStackLocation->FileObject == (PFILE_OBJECT)qword_280074F00 )
  {
    if ( (int)sub_280052014((__int64)KeGetCurrentThread()) >= 0 )
    {
      sub_2800660EC(OwnerId);
      sub_2800520DC((__int64)KeGetCurrentThread());
    }
    qword_280074F00 = 0;
LABEL_53:
    ++v4->CurrentLocation;
    ++v4->Tail.Overlay.CurrentStackLocation;
    Irp = v4;
    return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
  }
  v21 = *((struct _FILE_OBJECT **)DeviceExtension + 68);
  if ( v21 != nullptr && CurrentStackLocation->FileObject == v21 )
  {
    *((_QWORD *)DeviceExtension + 68) = 0;
    ++Irp->CurrentLocation;
    ++Irp->Tail.Overlay.CurrentStackLocation;
    return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
  }
  if ( *((_DWORD *)DeviceExtension + 19) == 2 )
  {
    v22 = (FSRTL_ADVANCED_FCB_HEADER *)CurrentStackLocation->FileObject->FsContext;
    if ( v22 != nullptr && (v22->Flags2 & 2) != 0 && v22->FilterContexts.Flink != &v22->FilterContexts )
      v23 = FsRtlLookupPerStreamContextInternal(v22, OwnerId, nullptr);
    else
      v23 = nullptr;
    if ( v23 != nullptr )
    {
      ExAcquireFastMutex(v22->FastMutex);
      Flink = (volatile signed __int32 *)v23[1].Links.Flink;
      if ( Flink != nullptr )
        _InterlockedAdd(Flink, 1u);
      FastMutex = v22->FastMutex;
      Blink = (int)v23[1].Links.Blink;
      Blink_high = HIDWORD(v23[1].Links.Blink);
      v30 = Blink_high;
      ExReleaseFastMutex(FastMutex);
      if ( Flink != nullptr )
      {
        v26 = Blink;
        if ( Blink < 0 || Blink_high < dword_2800742E4 )
        {
          v29 = sub_280066C40(Flink, 0, &v30);
          ExAcquireFastMutex(v22->FastMutex);
          v27 = v29 | (__int64)v23[1].Links.Blink & 0xFF0000;
          HIDWORD(v23[1].Links.Blink) = v30;
          LODWORD(v23[1].Links.Blink) = v27;
          ExReleaseFastMutex(v22->FastMutex);
          v26 = v29;
        }
        if ( (v26 & 1) != 0 && LOBYTE(v23[1].OwnerId) == 1 )
        {
          LOBYTE(v23[1].OwnerId) = 0;
          sub_280067460(OwnerId, Flink);
        }
        sub_28006C8A8((PSLIST_ENTRY)Flink);
      }
    }
    goto LABEL_53;
  }
LABEL_26:
  ++Irp->CurrentLocation;
  Irp->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
  return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
}


// ===== sub_2800606F0 @ 0x2800606f0 size=0x1b7 =====
NTSTATUS __fastcall sub_2800606F0(PDEVICE_OBJECT OwnerId, PIRP Irp)
{
  PVOID DeviceExtension; // rsi
  PIRP v3; // rbx
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rbp
  struct _IRP *MasterIrp; // r12
  int v8; // ebp
  struct _FILE_OBJECT *v9; // rax
  ULONG Options; // eax

  DeviceExtension = OwnerId->DeviceExtension;
  v3 = Irp;
  if ( OwnerId == DeviceObject )
  {
    Irp->IoStatus.Information = 0;
    Irp->IoStatus.Status = -1073741808;
    IofCompleteRequest(Irp, 0);
    return -1073741808;
  }
  if ( *((_QWORD *)DeviceExtension + 3) == 0
    || *((_DWORD *)DeviceExtension + 19) != 2 && *((_DWORD *)DeviceExtension + 19) != 1 )
  {
    ++Irp->CurrentLocation;
    ++Irp->Tail.Overlay.CurrentStackLocation;
    return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
  }
  CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
  if ( qword_280074F00 != 0 && CurrentStackLocation->FileObject == (PFILE_OBJECT)qword_280074F00 )
  {
    if ( CurrentStackLocation->Parameters.Create.Options == 20 && *((_DWORD *)DeviceExtension + 19) == 2 )
    {
      MasterIrp = Irp->AssociatedIrp.MasterIrp;
      v8 = sub_280052014((__int64)KeGetCurrentThread());
      if ( v8 < 0 || (v8 = sub_280066230(OwnerId, MasterIrp), sub_2800520DC((__int64)KeGetCurrentThread()), v8 < 0) )
      {
        v3->IoStatus.Information = 0;
        v3->IoStatus.Status = v8;
        IofCompleteRequest(v3, 0);
        return v8;
      }
    }
    goto LABEL_15;
  }
  v9 = *((struct _FILE_OBJECT **)DeviceExtension + 68);
  if ( v9 != nullptr && CurrentStackLocation->FileObject == v9 )
  {
    ++Irp->CurrentLocation;
    Irp->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
    return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
  }
  if ( qword_280074B68 != nullptr && (unsigned int)qword_280074B68(CurrentStackLocation->FileObject) != 0 )
    goto LABEL_15;
  Options = CurrentStackLocation->Parameters.Create.Options;
  switch ( Options )
  {
    case 4u:
      return sub_280061CEC(OwnerId, v3);
    case 0xAu:
      return sub_2800608B0(OwnerId, v3);
    case 0x14u:
      return sub_280061F68(OwnerId, v3);
    default:
      break;
  }
  if ( Options != 40 )
  {
    if ( Options != 56 && Options != 65 )
    {
LABEL_15:
      ++v3->CurrentLocation;
      ++v3->Tail.Overlay.CurrentStackLocation;
      Irp = v3;
      return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
    }
    return sub_2800608B0(OwnerId, v3);
  }
  return sub_2800613B8(OwnerId, v3);
}


// ===== sub_2800608B0 @ 0x2800608b0 size=0xb00 =====
NTSTATUS __fastcall sub_2800608B0(_QWORD *OwnerId, PIRP Irp)
{
  __int64 v2; // rdi
  FSRTL_ADVANCED_FCB_HEADER *FsContext; // r13
  PFSRTL_PER_STREAM_CONTEXT v5; // rbp
  PSLIST_ENTRY Flink; // r12
  int Blink; // r15d
  unsigned int Blink_high; // ebx
  struct _FAST_MUTEX *FastMutex; // rcx
  NTSTATUS v11; // eax
  NTSTATUS v12; // ebx
  struct _SLIST_ENTRY *v13; // rbx
  struct _SLIST_ENTRY *v14; // rcx
  int v15; // eax
  struct _FAST_MUTEX *v16; // rcx
  int v17; // ebx
  int v18; // edx
  struct _IRP *MasterIrp; // r15
  _WORD *v20; // rax
  _WORD *PoolWithTag; // rbx
  NTSTATUS v22; // r15d
  wchar_t *v23; // rdi
  PMDL MdlAddress; // rcx
  struct _SLIST_ENTRY *v25; // rbx
  PSLIST_ENTRY v26; // rdi
  NTSTATUS v27; // edi
  unsigned __int64 v28; // rax
  unsigned __int16 *v29; // rax
  size_t Flags; // r8
  _WORD *v31; // rax
  _WORD *v32; // rdi
  __int64 v33; // rcx
  bool v34; // zf
  __int64 v35; // rcx
  _WORD *v36; // rdi
  __int64 v37; // rcx
  _WORD *v38; // rdi
  __int64 v39; // rcx
  _WORD *v40; // rdi
  PSLIST_ENTRY v41; // rdi
  __int64 v42; // rdi
  struct _SLIST_ENTRY *v43; // rcx
  volatile signed __int32 *v44; // rax
  int v45; // ebx
  struct _SLIST_ENTRY *v46; // rcx
  int v47; // eax
  unsigned __int16 *v48; // rax
  struct _SLIST_ENTRY *PoolWithTagPriority; // rax
  char *v50; // rbx
  __int64 v51; // rcx
  _WORD *v52; // rdi
  PSLIST_ENTRY v53; // rdx
  unsigned int v54; // r9d
  __int64 v55; // rcx
  _WORD *v56; // rdi
  _BYTE *v57; // rax
  struct _SLIST_ENTRY *v58; // rcx
  int v59; // edx
  PSLIST_ENTRY v60; // rbx
  char v61; // bp
  PSLIST_ENTRY v62; // [rsp+30h] [rbp-A8h] BYREF
  PSLIST_ENTRY ListEntry; // [rsp+38h] [rbp-A0h] BYREF
  int v64; // [rsp+40h] [rbp-98h] BYREF
  unsigned int v65; // [rsp+44h] [rbp-94h] BYREF
  PSLIST_ENTRY v66; // [rsp+48h] [rbp-90h]
  int v67; // [rsp+50h] [rbp-88h]
  PVOID Object; // [rsp+58h] [rbp-80h] BYREF
  struct _IO_STACK_LOCATION *CurrentStackLocation; // [rsp+60h] [rbp-78h]
  PSLIST_ENTRY v70; // [rsp+68h] [rbp-70h] BYREF
  __int64 v71; // [rsp+70h] [rbp-68h]
  struct _UNICODE_STRING DestinationString; // [rsp+78h] [rbp-60h] BYREF
  int v73; // [rsp+E0h] [rbp+8h]
  unsigned int v74; // [rsp+E8h] [rbp+10h] BYREF
  int v75; // [rsp+F0h] [rbp+18h] BYREF
  unsigned __int16 *v76; // [rsp+F8h] [rbp+20h]

  v73 = (int)OwnerId;
  v2 = OwnerId[8];
  CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
  FsContext = (FSRTL_ADVANCED_FCB_HEADER *)CurrentStackLocation->FileObject->FsContext;
  v71 = v2;
  v62 = nullptr;
  LOBYTE(v74) = 0;
  if ( FsContext != nullptr
    && (FsContext->Flags2 & 2) != 0
    && FsContext->FilterContexts.Flink != &FsContext->FilterContexts )
  {
    v5 = FsRtlLookupPerStreamContextInternal(FsContext, OwnerId, nullptr);
  }
  else
  {
    v5 = nullptr;
  }
  if ( v5 == nullptr )
    goto LABEL_7;
  ExAcquireFastMutex(FsContext->FastMutex);
  Flink = (PSLIST_ENTRY)v5[1].Links.Flink;
  ListEntry = Flink;
  if ( Flink != nullptr )
  {
    _InterlockedAdd((volatile signed __int32 *)Flink, 1u);
    Flink = ListEntry;
  }
  Blink = (int)v5[1].Links.Blink;
  Blink_high = HIDWORD(v5[1].Links.Blink);
  FastMutex = FsContext->FastMutex;
  v67 = Blink;
  v65 = Blink_high;
  ExReleaseFastMutex(FastMutex);
  if ( Flink == nullptr )
  {
    v11 = sub_28006C80C(&ListEntry, &Lookaside);
    v12 = v11;
    if ( v11 < 0 )
    {
      Irp->IoStatus.Status = v11;
      Irp->IoStatus.Information = 0;
LABEL_13:
      IofCompleteRequest(Irp, 0);
      return v12;
    }
    v13 = ListEntry;
    if ( (int)sub_28006C0EC(
                CurrentStackLocation->FileObject,
                (_DWORD)ListEntry,
                (int)v2 + 8,
                32,
                (unsigned int)&Lookaside,
                (__int64)&v74) < 0 )
    {
      v14 = v13;
LABEL_16:
      sub_28006C8A8(v14);
LABEL_7:
      ++Irp->CurrentLocation;
      ++Irp->Tail.Overlay.CurrentStackLocation;
      return IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 16), Irp);
    }
    ExAcquireFastMutex(FsContext->FastMutex);
    if ( v5[1].Links.Flink != nullptr )
    {
      sub_28006C8A8(v13);
      v13 = (struct _SLIST_ENTRY *)v5[1].Links.Flink;
      ListEntry = v13;
    }
    else
    {
      v5[1].Links.Flink = (struct _LIST_ENTRY *)v13;
    }
    _InterlockedAdd((volatile signed __int32 *)v13, 1u);
    ExReleaseFastMutex(FsContext->FastMutex);
    Flink = ListEntry;
    Blink_high = v65;
  }
  if ( *(_DWORD *)(v2 + 76) == 2 && (Blink < 0 || Blink_high < dword_2800742E4) )
  {
    v15 = sub_280066C40(Flink, 0, &v65);
    v16 = FsContext->FastMutex;
    v17 = v15;
    v67 = v15;
    ExAcquireFastMutex(v16);
    v18 = (__int64)v5[1].Links.Blink & 0xFF0000;
    HIDWORD(v5[1].Links.Blink) = v65;
    LODWORD(v5[1].Links.Blink) = v17 | v18;
    ExReleaseFastMutex(FsContext->FastMutex);
  }
  MasterIrp = Irp->AssociatedIrp.MasterIrp;
  if ( CurrentStackLocation->Parameters.Read.ByteOffset.QuadPart != 0 )
  {
    MdlAddress = MasterIrp->MdlAddress;
    if ( MdlAddress != nullptr )
    {
      if ( ObReferenceObjectByHandle(MdlAddress, 0xF0000u, nullptr, 0, &Object, nullptr) >= 0 )
      {
        v12 = sub_28006C80C(&v70, &Lookaside);
        if ( v12 < 0 )
        {
          ObfDereferenceObject(Object);
          sub_28006C8A8(Flink);
          Irp->IoStatus.Status = v12;
          Irp->IoStatus.Information = 0;
          goto LABEL_13;
        }
        v25 = v70;
        LODWORD(v76) = sub_28006C0EC(
                         (_DWORD)Object,
                         (_DWORD)v70,
                         (int)v2 + 8,
                         32,
                         (unsigned int)&Lookaside,
                         (__int64)&v74);
        if ( (int)v76 >= 0 )
        {
          ObfDereferenceObject(Object);
          v26 = v70;
          PoolWithTag = ExAllocatePoolWithTag(
                          PagedPool,
                          *((unsigned __int16 *)&v70->Next + 4) + MasterIrp->Flags + 6,
                          0x626E5450u);
          if ( PoolWithTag == nullptr )
          {
            sub_28006C8A8(v26);
            v27 = (int)v76;
            v22 = (int)v76;
LABEL_71:
            sub_28006C8A8(Flink);
            Irp->IoStatus.Status = v27;
            goto LABEL_72;
          }
          memmove(PoolWithTag, v26[1].Next, *((unsigned __int16 *)&v26->Next + 4));
          PoolWithTag[(unsigned __int64)*((unsigned __int16 *)&v26->Next + 4) >> 1] = 0;
          v28 = *((unsigned __int16 *)&v26->Next + 4);
          if ( PoolWithTag[(v28 >> 1) - 1] == 92 )
          {
            v29 = &PoolWithTag[v28 >> 1];
          }
          else
          {
            PoolWithTag[v28 >> 1] = 92;
            PoolWithTag[((unsigned __int64)*((unsigned __int16 *)&v26->Next + 4) >> 1) + 1] = 0;
            v29 = &PoolWithTag[((unsigned __int64)*((unsigned __int16 *)&v26->Next + 4) >> 1) + 1];
          }
          Flags = MasterIrp->Flags;
          v76 = v29;
          memmove(v29, &MasterIrp->Flags + 1, Flags);
          v76[(unsigned __int64)MasterIrp->Flags >> 1] = 0;
          sub_28006C8A8(v26);
          goto LABEL_63;
        }
        sub_28006C8A8(v25);
        ObfDereferenceObject(Object);
      }
      v14 = Flink;
      goto LABEL_16;
    }
    PoolWithTag = ExAllocatePoolWithTag(PagedPool, MasterIrp->Flags + 26, 0x626E5450u);
    if ( PoolWithTag == nullptr )
    {
      sub_28006C8A8(Flink);
      v22 = -1073741670;
      Irp->IoStatus.Status = -1073741670;
LABEL_72:
      Irp->IoStatus.Information = 0;
      goto LABEL_112;
    }
    if ( MasterIrp->Flags <= 8 || _wcsnicmp(L"\\??\\", (const wchar_t *)&MasterIrp->Flags + 2, 4u) != 0 )
    {
      if ( MasterIrp->Flags > 0x18 )
      {
        if ( _wcsnicmp(L"\\DosDevices\\", (const wchar_t *)&MasterIrp->Flags + 2, 0xCu) == 0 )
        {
          memmove(PoolWithTag, (char *)&MasterIrp->ThreadListEntry.Blink + 4, MasterIrp->Flags - 24LL);
          PoolWithTag[((unsigned __int64)MasterIrp->Flags >> 1) - 12] = 0;
          goto LABEL_63;
        }
        if ( MasterIrp->Flags > 0x18 && _wcsnicmp(L"\\SystemRoot\\", (const wchar_t *)&MasterIrp->Flags + 2, 0xCu) == 0 )
        {
          v31 = *(_WORD **)(v2 + 48);
          v32 = &unk_280074F10;
          *PoolWithTag = *v31;
          v33 = -1;
          PoolWithTag[1] = 58;
          do
          {
            if ( v33 == 0 )
              break;
            v34 = *v32++ == 0;
            --v33;
          }
          while ( !v34 );
          memmove(PoolWithTag + 2, &unk_280074F10, 2 * (-v33 - 2));
          v35 = -1;
          v36 = &unk_280074F10;
          do
          {
            if ( v35 == 0 )
              break;
            v34 = *v36++ == 0;
            --v35;
          }
          while ( !v34 );
          memmove(&PoolWithTag[-v35], (char *)&MasterIrp->ThreadListEntry.Blink + 2, MasterIrp->Flags - 22LL);
          v37 = -1;
          v38 = &unk_280074F10;
          do
          {
            if ( v37 == 0 )
              break;
            v34 = *v38++ == 0;
            --v37;
          }
          while ( !v34 );
          PoolWithTag[((unsigned __int64)MasterIrp->Flags >> 1) - 11 - v37] = 0;
          goto LABEL_63;
        }
      }
      *PoolWithTag = **(_WORD **)(v2 + 48);
      PoolWithTag[1] = 58;
      memmove(PoolWithTag + 2, &MasterIrp->Flags + 1, MasterIrp->Flags);
      PoolWithTag[((unsigned __int64)MasterIrp->Flags >> 1) + 2] = 0;
      goto LABEL_63;
    }
    memmove(PoolWithTag, (char *)&MasterIrp->AssociatedIrp.SystemBuffer + 4, MasterIrp->Flags - 8LL);
    PoolWithTag[((unsigned __int64)MasterIrp->Flags >> 1) - 4] = 0;
LABEL_63:
    v22 = sub_28006C80C(&v62, &Lookaside);
    if ( v22 < 0 )
    {
      ExFreePoolWithTag(PoolWithTag, 0x626E5450u);
LABEL_70:
      v27 = v22;
      goto LABEL_71;
    }
    v39 = -1;
    v40 = PoolWithTag;
    do
    {
      if ( v39 == 0 )
        break;
      v34 = *v40++ == 0;
      --v39;
    }
    while ( !v34 );
    v41 = v62;
    v66 = v62;
    v22 = sub_28006C92C(v62, (unsigned int)(2 * (-(int)v39 - 2)));
    if ( v22 < 0 )
    {
      ExFreePoolWithTag(PoolWithTag, 0x626E5450u);
      sub_28006C8A8(v41);
      goto LABEL_70;
    }
    RtlInitUnicodeString(&DestinationString, PoolWithTag);
    v76 = (unsigned __int16 *)(&v41->Next + 1);
    RtlCopyUnicodeString((PUNICODE_STRING)(&v41->Next + 1), &DestinationString);
    ExFreePoolWithTag(PoolWithTag, 0x626E5450u);
    v42 = v71;
    v22 = sub_2800513D0(*(PDEVICE_OBJECT *)(v71 + 16), Irp);
    if ( v22 < 0 )
    {
LABEL_111:
      sub_28006C8A8(v66);
      sub_28006C8A8(Flink);
      goto LABEL_112;
    }
    ExAcquireFastMutex(FsContext->FastMutex);
    v43 = (struct _SLIST_ENTRY *)v5[1].Links.Flink;
    if ( v43 != nullptr )
      sub_28006C8A8(v43);
    v44 = (volatile signed __int32 *)v66;
    v5[1].Links.Flink = (struct _LIST_ENTRY *)v66;
    _InterlockedAdd(v44, 1u);
    ExReleaseFastMutex(FsContext->FastMutex);
    if ( *(_DWORD *)(v42 + 76) != 2 )
      goto LABEL_109;
    v66 = v62;
    v45 = sub_280066C40(v62, 0, &v64);
    v75 = v45;
    if ( (v67 & 0x10001) == 0 && (v45 & 0x10001) == 0 )
    {
      ExAcquireFastMutex(FsContext->FastMutex);
      v46 = (struct _SLIST_ENTRY *)v5[1].Links.Flink;
      if ( v46 != nullptr )
      {
        sub_28006C8A8(v46);
        v5[1].Links.Flink = nullptr;
      }
      LODWORD(v5[1].Links.Blink) &= 0xFF0000u;
      v47 = v64;
      LODWORD(v5[1].Links.Blink) |= v45;
      HIDWORD(v5[1].Links.Blink) = v47;
      ExReleaseFastMutex(FsContext->FastMutex);
      goto LABEL_110;
    }
    if ( (v67 & 0x10001) != 0 )
    {
      if ( (v45 & 0x10001) != 0 )
      {
        v48 = v76;
        LOBYTE(v5[1].OwnerId) = 1;
        v74 = *v48 + 72;
        PoolWithTagPriority = (struct _SLIST_ENTRY *)ExAllocatePoolWithTagPriority(
                                                       PagedPool,
                                                       v74,
                                                       0x626E5450u,
                                                       HighPoolPriority);
        Flink = ListEntry;
        v62 = PoolWithTagPriority;
        if ( PoolWithTagPriority != nullptr )
        {
          memset(PoolWithTagPriority, 0, *v76 + 72LL);
          v50 = (char *)&v62[1].Next + 4;
          swprintf((wchar_t *)&v62[1].Next + 2, L"\\??\\%s%x", aDpshadow, *(unsigned int *)(v42 + 72));
          v51 = -1;
          v52 = v50;
          do
          {
            if ( v51 == 0 )
              break;
            v34 = *v52++ == 0;
            --v51;
          }
          while ( !v34 );
          memmove((char *)&v62[1] - 2 * v51, (char *)&v66[1].Next->Next + 4, *v76 - 4);
          v53 = v62;
          v54 = v74;
          v55 = -1;
          LOBYTE(v62->Next) = 1;
          *((_QWORD *)&v53->Next + 1) = 0;
          v56 = v50;
          do
          {
            if ( v55 == 0 )
              break;
            v34 = *v56++ == 0;
            --v55;
          }
          while ( !v34 );
          LODWORD(v53[1].Next) = 2 * (-(int)v55 - 2);
          sub_280067350(v73, (_DWORD)Flink, (_DWORD)v53, v54, 10);
          v45 = v75;
        }
        ExAcquireFastMutex(FsContext->FastMutex);
        LODWORD(v5[1].Links.Blink) = v45 | (__int64)v5[1].Links.Blink & 0xFF0000;
      }
      else
      {
        Flink = ListEntry;
        if ( (v67 & 1) != 0 )
        {
          v57 = ExAllocatePoolWithTagPriority(PagedPool, 1u, 0x626E5450u, HighPoolPriority);
          if ( v57 != nullptr )
          {
            *v57 = 1;
            sub_280067350(v73, (_DWORD)Flink, (_DWORD)v57, 1, 13);
          }
        }
        ExAcquireFastMutex(FsContext->FastMutex);
        v58 = (struct _SLIST_ENTRY *)v5[1].Links.Flink;
        if ( v58 != nullptr )
        {
          sub_28006C8A8(v58);
          v5[1].Links.Flink = nullptr;
        }
        LODWORD(v5[1].Links.Blink) &= 0xFF0000u;
        LODWORD(v5[1].Links.Blink) |= v45;
      }
      HIDWORD(v5[1].Links.Blink) = v64;
      ExReleaseFastMutex(FsContext->FastMutex);
      goto LABEL_111;
    }
    ExAcquireFastMutex(FsContext->FastMutex);
    v59 = (__int64)v5[1].Links.Blink & 0xFF0000;
    HIDWORD(v5[1].Links.Blink) = v64;
    LODWORD(v5[1].Links.Blink) = v45 | v59;
    ExReleaseFastMutex(FsContext->FastMutex);
    LOBYTE(v5[1].OwnerId) = 1;
    if ( (int)sub_280052014((__int64)KeGetCurrentThread()) < 0 )
    {
LABEL_109:
      v66 = v62;
LABEL_110:
      Flink = ListEntry;
      goto LABEL_111;
    }
    if ( *((__int64 *)CurrentStackLocation->FileObject->FsContext + 4) < 104857600 )
    {
      v60 = v62;
      if ( (unsigned int)sub_2800676BC(v42, v62) != -1073741638 )
        goto LABEL_108;
      LOBYTE(v75) = 0;
      sub_280067E5C(v42, v60, &v75);
      v61 = v75;
      if ( (_BYTE)v75 != 0 )
        sub_28006BC1C();
      sub_2800685B8(v42, v60);
      if ( v61 == 0 )
        goto LABEL_108;
    }
    else
    {
      sub_28006BC1C();
      sub_2800676BC(v42, v62);
    }
    sub_28006BC8C();
LABEL_108:
    sub_2800520DC((__int64)KeGetCurrentThread());
    goto LABEL_109;
  }
  v20 = ExAllocatePoolWithTag(PagedPool, *((unsigned __int16 *)&Flink->Next + 4) + MasterIrp->Flags + 4, 0x626E5450u);
  PoolWithTag = v20;
  if ( v20 != nullptr )
  {
    memmove(v20, Flink[1].Next, *((unsigned __int16 *)&Flink->Next + 4));
    PoolWithTag[(unsigned __int64)*((unsigned __int16 *)&Flink->Next + 4) >> 1] = 0;
    v23 = wcsrchr(PoolWithTag, 0x5Cu);
    memmove(v23 + 1, &MasterIrp->Flags + 1, MasterIrp->Flags);
    v23[((unsigned __int64)MasterIrp->Flags >> 1) + 1] = 0;
    goto LABEL_63;
  }
  sub_28006C8A8(Flink);
  v22 = -1073741670;
  Irp->IoStatus.Information = 0;
  Irp->IoStatus.Status = -1073741670;
LABEL_112:
  IofCompleteRequest(Irp, 0);
  return v22;
}


// ===== sub_2800613B8 @ 0x2800613b8 size=0x92b =====
NTSTATUS __fastcall sub_2800613B8(_QWORD *OwnerId, PIRP Irp)
{
  __int64 v2; // rdi
  FSRTL_ADVANCED_FCB_HEADER *FsContext; // r13
  PFSRTL_PER_STREAM_CONTEXT v5; // rsi
  PSLIST_ENTRY Flink; // r12
  int Blink; // r15d
  unsigned int Blink_high; // ebx
  struct _FAST_MUTEX *FastMutex; // rcx
  NTSTATUS v11; // eax
  NTSTATUS v12; // ebx
  struct _SLIST_ENTRY *v13; // rbx
  int v14; // eax
  struct _FAST_MUTEX *v15; // rcx
  int v16; // r15d
  int v17; // edx
  struct _IRP *MasterIrp; // rbx
  _WORD *v19; // rax
  _WORD *PoolWithTag; // r15
  NTSTATUS v21; // r15d
  wchar_t *v22; // rdi
  NTSTATUS v23; // edi
  _WORD *v24; // rax
  _WORD *v25; // rdi
  __int64 v26; // rcx
  bool v27; // zf
  __int64 v28; // rcx
  _WORD *v29; // rdi
  __int64 v30; // rcx
  _WORD *v31; // rdi
  PSLIST_ENTRY v32; // rbx
  __int64 v33; // rcx
  _WORD *v34; // rdi
  __int64 v35; // rdi
  struct _SLIST_ENTRY *v36; // rcx
  int v37; // r12d
  struct _SLIST_ENTRY *v38; // rcx
  int v39; // eax
  unsigned __int16 *v40; // rax
  struct _SLIST_ENTRY *PoolWithTagPriority; // rax
  char *v42; // rbx
  __int64 v43; // rcx
  _WORD *v44; // rdi
  PSLIST_ENTRY v45; // rdx
  unsigned int v46; // r9d
  __int64 v47; // rcx
  _WORD *v48; // rdi
  _BYTE *v49; // rax
  struct _SLIST_ENTRY *v50; // rcx
  int v51; // eax
  int v52; // edx
  PSLIST_ENTRY v53; // rbx
  char v54; // si
  PSLIST_ENTRY v55; // [rsp+30h] [rbp-98h] BYREF
  PSLIST_ENTRY ListEntry; // [rsp+38h] [rbp-90h] BYREF
  unsigned __int16 *v57; // [rsp+40h] [rbp-88h]
  PSLIST_ENTRY v58; // [rsp+48h] [rbp-80h] BYREF
  int v59; // [rsp+50h] [rbp-78h]
  struct _IO_STACK_LOCATION *CurrentStackLocation; // [rsp+58h] [rbp-70h]
  __int64 v61; // [rsp+60h] [rbp-68h]
  struct _UNICODE_STRING DestinationString; // [rsp+68h] [rbp-60h] BYREF
  int v63; // [rsp+D0h] [rbp+8h]
  int v64; // [rsp+D8h] [rbp+10h] BYREF
  unsigned int v65; // [rsp+E0h] [rbp+18h] BYREF
  int v66; // [rsp+E8h] [rbp+20h] BYREF

  v63 = (int)OwnerId;
  v2 = OwnerId[8];
  CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
  FsContext = (FSRTL_ADVANCED_FCB_HEADER *)CurrentStackLocation->FileObject->FsContext;
  v61 = v2;
  v55 = nullptr;
  LOBYTE(v65) = 0;
  if ( FsContext != nullptr
    && (FsContext->Flags2 & 2) != 0
    && FsContext->FilterContexts.Flink != &FsContext->FilterContexts )
  {
    v5 = FsRtlLookupPerStreamContextInternal(FsContext, OwnerId, nullptr);
  }
  else
  {
    v5 = nullptr;
  }
  if ( v5 == nullptr )
    goto LABEL_7;
  ExAcquireFastMutex(FsContext->FastMutex);
  Flink = (PSLIST_ENTRY)v5[1].Links.Flink;
  ListEntry = Flink;
  if ( Flink != nullptr )
  {
    _InterlockedAdd((volatile signed __int32 *)Flink, 1u);
    Flink = ListEntry;
  }
  Blink = (int)v5[1].Links.Blink;
  Blink_high = HIDWORD(v5[1].Links.Blink);
  FastMutex = FsContext->FastMutex;
  v59 = Blink;
  LODWORD(v58) = Blink_high;
  ExReleaseFastMutex(FastMutex);
  if ( Flink == nullptr )
  {
    v11 = sub_28006C80C(&ListEntry, &Lookaside);
    v12 = v11;
    if ( v11 < 0 )
    {
      Irp->IoStatus.Status = v11;
      Irp->IoStatus.Information = 0;
      IofCompleteRequest(Irp, 0);
      return v12;
    }
    v13 = ListEntry;
    if ( (int)sub_28006C0EC(
                CurrentStackLocation->FileObject,
                (_DWORD)ListEntry,
                (int)v2 + 8,
                32,
                (unsigned int)&Lookaside,
                (__int64)&v65) < 0 )
    {
      sub_28006C8A8(v13);
LABEL_7:
      ++Irp->CurrentLocation;
      ++Irp->Tail.Overlay.CurrentStackLocation;
      return IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 16), Irp);
    }
    ExAcquireFastMutex(FsContext->FastMutex);
    if ( v5[1].Links.Flink != nullptr )
    {
      sub_28006C8A8(v13);
      v13 = (struct _SLIST_ENTRY *)v5[1].Links.Flink;
      ListEntry = v13;
    }
    else
    {
      v5[1].Links.Flink = (struct _LIST_ENTRY *)v13;
    }
    _InterlockedAdd((volatile signed __int32 *)v13, 1u);
    ExReleaseFastMutex(FsContext->FastMutex);
    Flink = ListEntry;
    Blink_high = (unsigned int)v58;
  }
  if ( *(_DWORD *)(v2 + 76) == 2 && (Blink < 0 || Blink_high < dword_2800742E4) )
  {
    v14 = sub_280066C40(Flink, 0, &v58);
    v15 = FsContext->FastMutex;
    v16 = v14;
    v59 = v14;
    ExAcquireFastMutex(v15);
    v17 = (__int64)v5[1].Links.Blink & 0xFF0000;
    HIDWORD(v5[1].Links.Blink) = (_DWORD)v58;
    LODWORD(v5[1].Links.Blink) = v16 | v17;
    ExReleaseFastMutex(FsContext->FastMutex);
  }
  MasterIrp = Irp->AssociatedIrp.MasterIrp;
  if ( CurrentStackLocation->Parameters.Read.ByteOffset.QuadPart != 0 )
  {
    PoolWithTag = ExAllocatePoolWithTag(PagedPool, (unsigned int)(*(_DWORD *)&MasterIrp->Type + 26), 0x626E5450u);
    if ( PoolWithTag == nullptr )
    {
      sub_28006C8A8(Flink);
      v23 = -1073741670;
      LODWORD(v57) = -1073741670;
LABEL_56:
      v21 = (int)v57;
      Irp->IoStatus.Status = v23;
      Irp->IoStatus.Information = 0;
      goto LABEL_96;
    }
    if ( *(_DWORD *)&MasterIrp->Type <= 8u || _wcsnicmp(L"\\??\\", (const wchar_t *)&MasterIrp->Size + 1, 4u) != 0 )
    {
      if ( *(_DWORD *)&MasterIrp->Type > 0x18u )
      {
        if ( _wcsnicmp(L"\\DosDevices\\", (const wchar_t *)&MasterIrp->Size + 1, 0xCu) == 0 )
        {
          memmove(
            PoolWithTag,
            (char *)&MasterIrp->AssociatedIrp.SystemBuffer + 4,
            *(unsigned int *)&MasterIrp->Type - 24LL);
          PoolWithTag[((unsigned __int64)*(unsigned int *)&MasterIrp->Type >> 1) - 12] = 0;
          goto LABEL_48;
        }
        if ( *(_DWORD *)&MasterIrp->Type > 0x18u
          && _wcsnicmp(L"\\SystemRoot\\", (const wchar_t *)&MasterIrp->Size + 1, 0xCu) == 0 )
        {
          v24 = *(_WORD **)(v2 + 48);
          v25 = &unk_280074F10;
          *PoolWithTag = *v24;
          v26 = -1;
          PoolWithTag[1] = 58;
          do
          {
            if ( v26 == 0 )
              break;
            v27 = *v25++ == 0;
            --v26;
          }
          while ( !v27 );
          memmove(PoolWithTag + 2, &unk_280074F10, 2 * (-v26 - 2));
          v28 = -1;
          v29 = &unk_280074F10;
          do
          {
            if ( v28 == 0 )
              break;
            v27 = *v29++ == 0;
            --v28;
          }
          while ( !v27 );
          memmove(&PoolWithTag[-v28], (char *)&MasterIrp->AssociatedIrp + 2, *(unsigned int *)&MasterIrp->Type - 22LL);
          v30 = -1;
          v31 = &unk_280074F10;
          do
          {
            if ( v30 == 0 )
              break;
            v27 = *v31++ == 0;
            --v30;
          }
          while ( !v27 );
          PoolWithTag[((unsigned __int64)*(unsigned int *)&MasterIrp->Type >> 1) - 11 - v30] = 0;
          goto LABEL_48;
        }
      }
      *PoolWithTag = **(_WORD **)(v2 + 48);
      PoolWithTag[1] = 58;
      memmove(PoolWithTag + 2, &MasterIrp->Size + 1, *(unsigned int *)&MasterIrp->Type);
      PoolWithTag[((unsigned __int64)*(unsigned int *)&MasterIrp->Type >> 1) + 2] = 0;
      goto LABEL_48;
    }
    memmove(PoolWithTag, (char *)&MasterIrp->MdlAddress + 4, *(unsigned int *)&MasterIrp->Type - 8LL);
    PoolWithTag[((unsigned __int64)*(unsigned int *)&MasterIrp->Type >> 1) - 4] = 0;
LABEL_48:
    v23 = sub_28006C80C(&v55, &Lookaside);
    LODWORD(v57) = v23;
    if ( v23 < 0 )
    {
      ExFreePoolWithTag(PoolWithTag, 0x626E5450u);
LABEL_55:
      sub_28006C8A8(Flink);
      goto LABEL_56;
    }
    v32 = v55;
    v33 = -1;
    v34 = PoolWithTag;
    do
    {
      if ( v33 == 0 )
        break;
      v27 = *v34++ == 0;
      --v33;
    }
    while ( !v27 );
    v23 = sub_28006C92C(v55, (unsigned int)(2 * (-(int)v33 - 2)));
    LODWORD(v57) = v23;
    if ( v23 < 0 )
    {
      ExFreePoolWithTag(PoolWithTag, 0x626E5450u);
      sub_28006C8A8(v32);
      goto LABEL_55;
    }
    RtlInitUnicodeString(&DestinationString, PoolWithTag);
    v57 = (unsigned __int16 *)(&v32->Next + 1);
    RtlCopyUnicodeString((PUNICODE_STRING)(&v32->Next + 1), &DestinationString);
    ExFreePoolWithTag(PoolWithTag, 0x626E5450u);
    v35 = v61;
    v21 = sub_2800513D0(*(PDEVICE_OBJECT *)(v61 + 16), Irp);
    if ( v21 < 0 )
    {
LABEL_95:
      sub_28006C8A8(v32);
      sub_28006C8A8(Flink);
      goto LABEL_96;
    }
    ExAcquireFastMutex(FsContext->FastMutex);
    v36 = (struct _SLIST_ENTRY *)v5[1].Links.Flink;
    if ( v36 != nullptr )
      sub_28006C8A8(v36);
    v5[1].Links.Flink = (struct _LIST_ENTRY *)v32;
    _InterlockedAdd((volatile signed __int32 *)v32, 1u);
    ExReleaseFastMutex(FsContext->FastMutex);
    if ( *(_DWORD *)(v35 + 76) != 2 )
      goto LABEL_93;
    v32 = v55;
    v58 = v55;
    v37 = sub_280066C40(v55, 0, &v66);
    v64 = v37;
    if ( (v59 & 0x10001) == 0 && (v37 & 0x10001) == 0 )
    {
      ExAcquireFastMutex(FsContext->FastMutex);
      v38 = (struct _SLIST_ENTRY *)v5[1].Links.Flink;
      if ( v38 != nullptr )
      {
        sub_28006C8A8(v38);
        v5[1].Links.Flink = nullptr;
      }
      LODWORD(v5[1].Links.Blink) &= 0xFF0000u;
      v39 = v66;
      LODWORD(v5[1].Links.Blink) |= v37;
      HIDWORD(v5[1].Links.Blink) = v39;
      ExReleaseFastMutex(FsContext->FastMutex);
      goto LABEL_94;
    }
    if ( (v59 & 0x10001) != 0 )
    {
      if ( (v37 & 0x10001) != 0 )
      {
        v40 = v57;
        LOBYTE(v5[1].OwnerId) = 1;
        v65 = *v40 + 72;
        PoolWithTagPriority = (struct _SLIST_ENTRY *)ExAllocatePoolWithTagPriority(
                                                       PagedPool,
                                                       v65,
                                                       0x626E5450u,
                                                       HighPoolPriority);
        Flink = ListEntry;
        v55 = PoolWithTagPriority;
        if ( PoolWithTagPriority != nullptr )
        {
          memset(PoolWithTagPriority, 0, *v57 + 72LL);
          v42 = (char *)&v55[1].Next + 4;
          swprintf((wchar_t *)&v55[1].Next + 2, L"\\??\\%s%x", aDpshadow, *(unsigned int *)(v35 + 72));
          v43 = -1;
          v44 = v42;
          do
          {
            if ( v43 == 0 )
              break;
            v27 = *v44++ == 0;
            --v43;
          }
          while ( !v27 );
          memmove((char *)&v55[1] - 2 * v43, (char *)&v58[1].Next->Next + 4, *v57 - 4);
          v45 = v55;
          v46 = v65;
          v47 = -1;
          LOBYTE(v55->Next) = 1;
          *((_QWORD *)&v45->Next + 1) = 0;
          v48 = v42;
          do
          {
            if ( v47 == 0 )
              break;
            v27 = *v48++ == 0;
            --v47;
          }
          while ( !v27 );
          LODWORD(v45[1].Next) = 2 * (-(int)v47 - 2);
          sub_280067350(v63, (_DWORD)Flink, (_DWORD)v45, v46, 10);
          v32 = v58;
        }
        ExAcquireFastMutex(FsContext->FastMutex);
        LODWORD(v5[1].Links.Blink) = v64 | (__int64)v5[1].Links.Blink & 0xFF0000;
      }
      else
      {
        Flink = ListEntry;
        if ( (v59 & 1) != 0 )
        {
          v49 = ExAllocatePoolWithTagPriority(PagedPool, 1u, 0x626E5450u, HighPoolPriority);
          if ( v49 != nullptr )
          {
            *v49 = 1;
            sub_280067350(v63, (_DWORD)Flink, (_DWORD)v49, 1, 13);
          }
        }
        ExAcquireFastMutex(FsContext->FastMutex);
        v50 = (struct _SLIST_ENTRY *)v5[1].Links.Flink;
        if ( v50 != nullptr )
        {
          sub_28006C8A8(v50);
          v5[1].Links.Flink = nullptr;
        }
        v51 = v64;
        LODWORD(v5[1].Links.Blink) &= 0xFF0000u;
        LODWORD(v5[1].Links.Blink) |= v51;
      }
      HIDWORD(v5[1].Links.Blink) = v66;
      ExReleaseFastMutex(FsContext->FastMutex);
      goto LABEL_95;
    }
    ExAcquireFastMutex(FsContext->FastMutex);
    v52 = (__int64)v5[1].Links.Blink & 0xFF0000;
    HIDWORD(v5[1].Links.Blink) = v66;
    LODWORD(v5[1].Links.Blink) = v37 | v52;
    ExReleaseFastMutex(FsContext->FastMutex);
    LOBYTE(v5[1].OwnerId) = 1;
    if ( (int)sub_280052014((__int64)KeGetCurrentThread()) < 0 )
    {
LABEL_93:
      v32 = v55;
LABEL_94:
      Flink = ListEntry;
      goto LABEL_95;
    }
    if ( *((__int64 *)CurrentStackLocation->FileObject->FsContext + 4) < 104857600 )
    {
      v53 = v55;
      if ( (unsigned int)sub_2800676BC(v35, v55) != -1073741638 )
        goto LABEL_92;
      LOBYTE(v64) = 0;
      sub_280067E5C(v35, v53, &v64);
      v54 = v64;
      if ( (_BYTE)v64 != 0 )
        sub_28006BC1C();
      sub_2800685B8(v35, v53);
      if ( v54 == 0 )
        goto LABEL_92;
    }
    else
    {
      sub_28006BC1C();
      sub_2800676BC(v35, v55);
    }
    sub_28006BC8C();
LABEL_92:
    sub_2800520DC((__int64)KeGetCurrentThread());
    goto LABEL_93;
  }
  v19 = ExAllocatePoolWithTag(
          PagedPool,
          (unsigned int)*((unsigned __int16 *)&Flink->Next + 4) + *(_DWORD *)&MasterIrp->Type + 4,
          0x626E5450u);
  PoolWithTag = v19;
  if ( v19 != nullptr )
  {
    memmove(v19, Flink[1].Next, *((unsigned __int16 *)&Flink->Next + 4));
    PoolWithTag[(unsigned __int64)*((unsigned __int16 *)&Flink->Next + 4) >> 1] = 0;
    v22 = wcsrchr(PoolWithTag, 0x5Cu);
    memmove(v22 + 1, &MasterIrp->Size + 1, *(unsigned int *)&MasterIrp->Type);
    v22[((unsigned __int64)*(unsigned int *)&MasterIrp->Type >> 1) + 1] = 0;
    goto LABEL_48;
  }
  sub_28006C8A8(Flink);
  v21 = -1073741670;
  Irp->IoStatus.Information = 0;
  Irp->IoStatus.Status = -1073741670;
LABEL_96:
  IofCompleteRequest(Irp, 0);
  return v21;
}


// ===== sub_280061CEC @ 0x280061cec size=0x276 =====
NTSTATUS __fastcall sub_280061CEC(_QWORD *OwnerId, PIRP Irp)
{
  __int64 v2; // r13
  struct _IO_STACK_LOCATION *CurrentStackLocation; // r14
  PIRP v4; // rbx
  FSRTL_ADVANCED_FCB_HEADER *FsContext; // rdi
  PFSRTL_PER_STREAM_CONTEXT v6; // rsi
  volatile signed __int32 *Flink; // rbp
  struct _FAST_MUTEX *FastMutex; // rcx
  int Blink; // r15d
  int v10; // r11d
  struct _SLIST_ENTRY *v11; // rcx
  SIZE_T Length; // r15
  int v14; // esi
  PVOID PoolWithTagPriority; // rax
  void *v16; // rdi
  NTSTATUS v17; // esi
  int v18; // [rsp+70h] [rbp+8h]
  unsigned int Options; // [rsp+78h] [rbp+10h] BYREF
  unsigned int Blink_high; // [rsp+80h] [rbp+18h]

  v18 = (int)OwnerId;
  v2 = OwnerId[8];
  CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
  v4 = Irp;
  if ( *(_DWORD *)(v2 + 76) != 2 )
  {
    ++Irp->CurrentLocation;
    Irp->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
    return IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 16), Irp);
  }
  FsContext = (FSRTL_ADVANCED_FCB_HEADER *)CurrentStackLocation->FileObject->FsContext;
  if ( FsContext != nullptr
    && (FsContext->Flags2 & 2) != 0
    && FsContext->FilterContexts.Flink != &FsContext->FilterContexts )
  {
    v6 = FsRtlLookupPerStreamContextInternal(FsContext, OwnerId, nullptr);
  }
  else
  {
    v6 = nullptr;
  }
  if ( v6 == nullptr )
    goto LABEL_19;
  ExAcquireFastMutex(FsContext->FastMutex);
  Flink = (volatile signed __int32 *)v6[1].Links.Flink;
  if ( Flink != nullptr )
    _InterlockedAdd(Flink, 1u);
  FastMutex = FsContext->FastMutex;
  Blink = (int)v6[1].Links.Blink;
  Blink_high = HIDWORD(v6[1].Links.Blink);
  Options = Blink_high;
  ExReleaseFastMutex(FastMutex);
  if ( Flink == nullptr )
  {
LABEL_19:
    ++v4->CurrentLocation;
    ++v4->Tail.Overlay.CurrentStackLocation;
    Irp = v4;
    return IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 16), Irp);
  }
  if ( Blink < 0 || Blink_high < dword_2800742E4 )
  {
    Blink = sub_280066C40(Flink, 0, &Options);
    ExAcquireFastMutex(FsContext->FastMutex);
    v10 = Blink | (__int64)v6[1].Links.Blink & 0xFF0000;
    HIDWORD(v6[1].Links.Blink) = Options;
    LODWORD(v6[1].Links.Blink) = v10;
    ExReleaseFastMutex(FsContext->FastMutex);
  }
  if ( (Blink & 0x10001) == 0 )
  {
    sub_28006C8A8((PSLIST_ENTRY)Flink);
    ExAcquireFastMutex(FsContext->FastMutex);
    v11 = (struct _SLIST_ENTRY *)v6[1].Links.Flink;
    if ( v11 != nullptr )
    {
      sub_28006C8A8(v11);
      v6[1].Links.Flink = nullptr;
    }
    ExReleaseFastMutex(FsContext->FastMutex);
    goto LABEL_19;
  }
  LOBYTE(v6[1].OwnerId) = 1;
  Length = CurrentStackLocation->Parameters.Read.Length;
  Options = CurrentStackLocation->Parameters.Create.Options;
  v14 = 0;
  while ( 1 )
  {
    PoolWithTagPriority = ExAllocatePoolWithTagPriority(PagedPool, Length, 0x74735450u, HighPoolPriority);
    v16 = PoolWithTagPriority;
    if ( PoolWithTagPriority != nullptr )
      break;
    if ( (unsigned int)++v14 >= 0xA )
    {
      sub_28006C8A8((PSLIST_ENTRY)Flink);
      goto LABEL_19;
    }
    KeDelayExecutionThread(0, 0, &Interval);
  }
  memmove(PoolWithTagPriority, v4->AssociatedIrp.MasterIrp, Length);
  v17 = sub_2800513D0(*(PDEVICE_OBJECT *)(v2 + 16), v4);
  if ( v17 >= 0 && (int)sub_280067350(v18, (_DWORD)Flink, (_DWORD)v16, Length, Options) >= 0 )
    v16 = nullptr;
  if ( v16 != nullptr )
    ExFreePoolWithTag(v16, 0x74735450u);
  sub_28006C8A8((PSLIST_ENTRY)Flink);
  IofCompleteRequest(v4, 0);
  return v17;
}


// ===== sub_280061F68 @ 0x280061f68 size=0x2f2 =====
NTSTATUS __fastcall sub_280061F68(_QWORD *OwnerId, PIRP Irp)
{
  __int64 v2; // r13
  struct _IO_STACK_LOCATION *CurrentStackLocation; // r15
  PIRP v4; // rbx
  FSRTL_ADVANCED_FCB_HEADER *FsContext; // rdi
  PFSRTL_PER_STREAM_CONTEXT v6; // rsi
  volatile signed __int32 *Flink; // r12
  struct _FAST_MUTEX *FastMutex; // rcx
  int Blink; // r14d
  int v10; // r11d
  struct _SLIST_ENTRY *v11; // rcx
  ULONG Options; // r14d
  SIZE_T v14; // rdx
  int v15; // esi
  _QWORD *PoolWithTagPriority; // rdi
  NTSTATUS v17; // esi
  char v18; // r13
  PERESOURCE *v19; // rsi
  PERESOURCE v20; // rax
  int v21; // [rsp+80h] [rbp+8h]
  char NumberOfBytes; // [rsp+88h] [rbp+10h]
  ULONG NumberOfBytesa; // [rsp+88h] [rbp+10h]
  NTSTATUS v24; // [rsp+90h] [rbp+18h] BYREF
  unsigned int Blink_high; // [rsp+98h] [rbp+20h]

  v21 = (int)OwnerId;
  v2 = OwnerId[8];
  CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
  v4 = Irp;
  if ( *(_DWORD *)(v2 + 76) != 2 )
  {
    ++Irp->CurrentLocation;
    Irp->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
    return IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 16), Irp);
  }
  FsContext = (FSRTL_ADVANCED_FCB_HEADER *)CurrentStackLocation->FileObject->FsContext;
  if ( FsContext != nullptr
    && (FsContext->Flags2 & 2) != 0
    && FsContext->FilterContexts.Flink != &FsContext->FilterContexts )
  {
    v6 = FsRtlLookupPerStreamContextInternal(FsContext, OwnerId, nullptr);
  }
  else
  {
    v6 = nullptr;
  }
  if ( v6 == nullptr )
    goto LABEL_19;
  ExAcquireFastMutex(FsContext->FastMutex);
  Flink = (volatile signed __int32 *)v6[1].Links.Flink;
  if ( Flink != nullptr )
    _InterlockedAdd(Flink, 1u);
  FastMutex = FsContext->FastMutex;
  Blink = (int)v6[1].Links.Blink;
  Blink_high = HIDWORD(v6[1].Links.Blink);
  v24 = Blink_high;
  NumberOfBytes = BYTE1(v6[1].OwnerId);
  ExReleaseFastMutex(FastMutex);
  if ( Flink == nullptr )
  {
LABEL_19:
    ++v4->CurrentLocation;
    ++v4->Tail.Overlay.CurrentStackLocation;
    Irp = v4;
    return IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 16), Irp);
  }
  if ( Blink < 0 || Blink_high < dword_2800742E4 )
  {
    Blink = sub_280066C40(Flink, 0, &v24);
    ExAcquireFastMutex(FsContext->FastMutex);
    v10 = Blink | (__int64)v6[1].Links.Blink & 0xFF0000;
    HIDWORD(v6[1].Links.Blink) = v24;
    LODWORD(v6[1].Links.Blink) = v10;
    ExReleaseFastMutex(FsContext->FastMutex);
  }
  if ( (Blink & 0x10001) == 0 )
  {
    sub_28006C8A8((PSLIST_ENTRY)Flink);
    ExAcquireFastMutex(FsContext->FastMutex);
    v11 = (struct _SLIST_ENTRY *)v6[1].Links.Flink;
    if ( v11 != nullptr )
    {
      sub_28006C8A8(v11);
      v6[1].Links.Flink = nullptr;
    }
    ExReleaseFastMutex(FsContext->FastMutex);
    goto LABEL_19;
  }
  if ( NumberOfBytes != 0 )
  {
LABEL_22:
    sub_28006C8A8((PSLIST_ENTRY)Flink);
    goto LABEL_19;
  }
  LOBYTE(v6[1].OwnerId) = 1;
  Options = CurrentStackLocation->Parameters.Create.Options;
  NumberOfBytesa = CurrentStackLocation->Parameters.Read.Length;
  v14 = NumberOfBytesa;
  v15 = 0;
  while ( 1 )
  {
    PoolWithTagPriority = ExAllocatePoolWithTagPriority(PagedPool, v14, 0x74735450u, HighPoolPriority);
    if ( PoolWithTagPriority != nullptr )
      break;
    if ( (unsigned int)++v15 >= 0xA )
      goto LABEL_22;
    KeDelayExecutionThread(0, 0, &Interval);
    v14 = NumberOfBytesa;
  }
  v17 = sub_2800513D0(*(PDEVICE_OBJECT *)(v2 + 16), v4);
  v24 = v17;
  if ( v17 >= 0 )
  {
    v18 = v4->Flags & 2;
    v19 = (PERESOURCE *)CurrentStackLocation->FileObject->FsContext;
    if ( v18 == 0 )
    {
      KeEnterCriticalRegion();
      ExAcquireResourceSharedLite(v19[1], 1u);
    }
    switch ( Options )
    {
      case 0x13u:
        v20 = v19[3];
        break;
      case 0x27u:
        v20 = v19[5];
        break;
      case 0x14u:
        v20 = v19[4];
        break;
      default:
LABEL_37:
        if ( (int)sub_280067350(v21, (_DWORD)Flink, (_DWORD)PoolWithTagPriority, NumberOfBytesa, Options) >= 0 )
          PoolWithTagPriority = nullptr;
        if ( v18 == 0 )
        {
          ExReleaseResourceLite(v19[1]);
          KeLeaveCriticalRegion();
        }
        v17 = v24;
        goto LABEL_42;
    }
    *PoolWithTagPriority = v20;
    goto LABEL_37;
  }
LABEL_42:
  if ( PoolWithTagPriority != nullptr )
    ExFreePoolWithTag(PoolWithTagPriority, 0x74735450u);
  sub_28006C8A8((PSLIST_ENTRY)Flink);
  IofCompleteRequest(v4, 0);
  return v17;
}


// ===== sub_280062260 @ 0x280062260 size=0x84e =====
NTSTATUS __fastcall sub_280062260(PDEVICE_OBJECT OwnerId, PIRP Irp)
{
  PVOID DeviceExtension; // r13
  struct _IO_STACK_LOCATION *CurrentStackLocation; // r14
  volatile signed __int32 *Flink; // rbx
  struct _FILE_OBJECT *v7; // rax
  FSRTL_ADVANCED_FCB_HEADER *FsContext; // r15
  PFSRTL_PER_STREAM_CONTEXT v9; // r12
  int v10; // eax
  struct _SLIST_ENTRY *v11; // rcx
  PSLIST_ENTRY v12; // r12
  PVOID PoolWithTag; // r9
  int v14; // r15d
  PMDL MdlAddress; // rcx
  PVOID UserBuffer; // r14
  __int64 i; // rax
  struct _IO_STACK_LOCATION *v18; // rdx
  struct _IO_STACK_LOCATION *v19; // rbx
  struct _IO_STACK_LOCATION *v20; // rax
  PSLIST_ENTRY v21; // [rsp+30h] [rbp-68h] BYREF
  __int64 v22; // [rsp+38h] [rbp-60h]
  volatile signed __int32 *v23; // [rsp+40h] [rbp-58h]
  PVOID v24; // [rsp+48h] [rbp-50h]
  PVOID v25; // [rsp+50h] [rbp-48h]
  struct _DEVICE_OBJECT *v26; // [rsp+A0h] [rbp+8h]
  char v27; // [rsp+B0h] [rbp+18h]
  int v28; // [rsp+B0h] [rbp+18h]
  int v29; // [rsp+B0h] [rbp+18h]
  int P; // [rsp+B8h] [rbp+20h]
  int Pb; // [rsp+B8h] [rbp+20h]
  PVOID Pa; // [rsp+B8h] [rbp+20h]

  v26 = OwnerId;
  DeviceExtension = OwnerId->DeviceExtension;
  v24 = DeviceExtension;
  CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
  if ( OwnerId == DeviceObject )
  {
    Irp->IoStatus.Status = -1073741808;
    Irp->IoStatus.Information = 0;
    IofCompleteRequest(Irp, 0);
    return -1073741808;
  }
  if ( *((_QWORD *)DeviceExtension + 3) != 0 && *((_DWORD *)DeviceExtension + 19) == 2 )
  {
    if ( qword_280074F00 != 0 && CurrentStackLocation->FileObject == (PFILE_OBJECT)qword_280074F00 )
    {
      Flink = nullptr;
      v23 = nullptr;
      goto LABEL_43;
    }
    v7 = *((struct _FILE_OBJECT **)DeviceExtension + 68);
    if ( v7 == nullptr || CurrentStackLocation->FileObject != v7 )
    {
      if ( qword_280074B68 != nullptr )
      {
        if ( (unsigned int)qword_280074B68(CurrentStackLocation->FileObject) != 0 )
        {
LABEL_28:
          ++Irp->CurrentLocation;
          ++Irp->Tail.Overlay.CurrentStackLocation;
          return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
        }
        OwnerId = v26;
      }
      if ( CurrentStackLocation->Parameters.Read.Length == 0 || (CurrentStackLocation->MinorFunction & 6) != 0 )
        goto LABEL_28;
      FsContext = (FSRTL_ADVANCED_FCB_HEADER *)CurrentStackLocation->FileObject->FsContext;
      if ( FsContext != nullptr
        && (FsContext->Flags2 & 2) != 0
        && FsContext->FilterContexts.Flink != &FsContext->FilterContexts )
      {
        v9 = FsRtlLookupPerStreamContextInternal(FsContext, OwnerId, nullptr);
      }
      else
      {
        v9 = nullptr;
      }
      if ( v9 == nullptr )
        goto LABEL_28;
      ExAcquireFastMutex(FsContext->FastMutex);
      Flink = (volatile signed __int32 *)v9[1].Links.Flink;
      v23 = Flink;
      if ( Flink != nullptr )
        _InterlockedAdd(Flink, 1u);
      P = (int)v9[1].Links.Blink;
      LODWORD(v22) = HIDWORD(v9[1].Links.Blink);
      LODWORD(v21) = v22;
      v27 = BYTE1(v9[1].OwnerId);
      ExReleaseFastMutex(FsContext->FastMutex);
      if ( Flink == nullptr )
        goto LABEL_28;
      v10 = P;
      if ( P < 0 || (unsigned int)v22 < dword_2800742E4 )
      {
        Pb = sub_280066C40(Flink, 0, &v21);
        ExAcquireFastMutex(FsContext->FastMutex);
        LODWORD(v9[1].Links.Blink) = Pb | (__int64)v9[1].Links.Blink & 0xFF0000;
        HIDWORD(v9[1].Links.Blink) = (_DWORD)v21;
        ExReleaseFastMutex(FsContext->FastMutex);
        v10 = Pb;
      }
      if ( (v10 & 0x20000) != 0 && CurrentStackLocation->Parameters.Read.ByteOffset.QuadPart >= 4096 )
      {
        sub_28006C8A8((PSLIST_ENTRY)Flink);
        Irp->IoStatus.Status = 0;
        Irp->IoStatus.Information = CurrentStackLocation->Parameters.Read.Length;
        IofCompleteRequest(Irp, 0);
        return 0;
      }
      if ( (v10 & 0x10001) == 0 )
      {
        sub_28006C8A8((PSLIST_ENTRY)Flink);
        ExAcquireFastMutex(FsContext->FastMutex);
        v11 = (struct _SLIST_ENTRY *)v9[1].Links.Flink;
        if ( v11 != nullptr )
        {
          sub_28006C8A8(v11);
          v9[1].Links.Flink = nullptr;
        }
        ExReleaseFastMutex(FsContext->FastMutex);
        ++Irp->CurrentLocation;
        ++Irp->Tail.Overlay.CurrentStackLocation;
        return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
      }
      if ( (Irp->Flags & 0x43) == 0 || v27 != 0 )
      {
        sub_28006C8A8((PSLIST_ENTRY)Flink);
        ++Irp->CurrentLocation;
        ++Irp->Tail.Overlay.CurrentStackLocation;
        return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
      }
      LOBYTE(v9[1].OwnerId) = 1;
LABEL_43:
      v28 = 0;
      v22 = 10;
      while ( 1 )
      {
        ++dword_280074894;
        v12 = ExpInterlockedPopEntrySList(&stru_280074880);
        if ( v12 == nullptr )
        {
          ++dword_280074898;
          v12 = (PSLIST_ENTRY)qword_2800748B0(
                                (unsigned int)dword_2800748A4,
                                (unsigned int)dword_2800748AC,
                                (unsigned int)dword_2800748A8);
        }
        v21 = v12;
        if ( v12 != nullptr )
          break;
        if ( (unsigned int)++v28 >= 0xA )
        {
          if ( Flink != nullptr )
            sub_28006C8A8((PSLIST_ENTRY)Flink);
LABEL_83:
          ++Irp->CurrentLocation;
          ++Irp->Tail.Overlay.CurrentStackLocation;
          return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
        }
        KeDelayExecutionThread(0, 0, &Interval);
      }
      v29 = 0;
      PoolWithTag = ExAllocatePoolWithTag(PagedPool, CurrentStackLocation->Parameters.Read.Length, 0x72775450u);
      Pa = PoolWithTag;
      if ( PoolWithTag == nullptr )
      {
        while ( (unsigned int)++v29 < 0xA )
        {
          KeDelayExecutionThread(0, 0, &Interval);
          PoolWithTag = ExAllocatePoolWithTag(PagedPool, CurrentStackLocation->Parameters.Read.Length, 0x72775450u);
          Pa = PoolWithTag;
          if ( PoolWithTag != nullptr )
            goto LABEL_62;
        }
        ++dword_28007489C;
        if ( ExQueryDepthSList(&stru_280074880) < (unsigned __int16)word_280074890 )
        {
          ExpInterlockedPushEntrySList(&stru_280074880, v12);
        }
        else
        {
          ++dword_2800748A0;
          qword_2800748B8(v12);
        }
        if ( Flink != nullptr )
          sub_28006C8A8((PSLIST_ENTRY)Flink);
        goto LABEL_83;
      }
LABEL_62:
      v12[1].Next = (struct _SLIST_ENTRY *)sub_280066F30;
      *((_QWORD *)&v12[1].Next + 1) = v12;
      LODWORD(v12[2].Next) = 1;
      *((_QWORD *)&v12[2].Next + 1) = v26;
      v12[4].Next = (struct _SLIST_ENTRY *)Flink;
      *((_QWORD *)&v12[4].Next + 1) = PoolWithTag;
      v12[3].Next = (struct _SLIST_ENTRY *)CurrentStackLocation->Parameters.Read.ByteOffset.QuadPart;
      *((_QWORD *)&v12[3].Next + 1) = CurrentStackLocation->Parameters.Read.Length;
      if ( HIDWORD(v12[3].Next) == -1 && LODWORD(v12[3].Next) == -2 )
      {
        v12[3].Next = (struct _SLIST_ENTRY *)CurrentStackLocation->FileObject->CurrentByteOffset.QuadPart;
      }
      else if ( HIDWORD(v12[3].Next) == -1 && LODWORD(v12[3].Next) == -1 )
      {
        v12[3].Next = *((struct _SLIST_ENTRY **)CurrentStackLocation->FileObject->FsContext + 4);
      }
      v14 = 0;
      while ( 1 )
      {
        MdlAddress = Irp->MdlAddress;
        if ( MdlAddress != nullptr )
        {
          UserBuffer = (MdlAddress->MdlFlags & 5) != 0
                     ? MdlAddress->MappedSystemVa
                     : MmMapLockedPagesSpecifyCache(MdlAddress, 0, MmCached, nullptr, 0, 0x10u);
        }
        else
        {
          UserBuffer = Irp->UserBuffer;
          v25 = UserBuffer;
          if ( Irp->RequestorMode == 1 )
            ProbeForRead(UserBuffer, *((unsigned int *)&v12[3].Next + 2), 1u);
        }
        if ( UserBuffer != nullptr )
          break;
        if ( (unsigned int)++v14 >= 0xA )
        {
          ExFreePoolWithTag(Pa, 0x72775450u);
          ++dword_28007489C;
          if ( ExQueryDepthSList(&stru_280074880) < (unsigned __int16)word_280074890 )
          {
            ExpInterlockedPushEntrySList(&stru_280074880, v12);
          }
          else
          {
            ++dword_2800748A0;
            qword_2800748B8(v12);
          }
          if ( Flink != nullptr )
            sub_28006C8A8((PSLIST_ENTRY)Flink);
          goto LABEL_83;
        }
        KeDelayExecutionThread(0, 0, &Interval);
      }
      memmove(Pa, UserBuffer, *((unsigned int *)&v12[3].Next + 2));
      for ( i = 10; i != 0; v22 = i )
      {
        if ( dword_280075124 > 300 )
        {
          KeDelayExecutionThread(0, 0, &Interval);
          i = v22;
        }
        --i;
      }
      v18 = Irp->Tail.Overlay.CurrentStackLocation;
      v19 = v18 - 1;
      memmove(&v18[-1], v18, 0x38u);
      v19->Control = 0;
      v20 = Irp->Tail.Overlay.CurrentStackLocation;
      v20[-1].CompletionRoutine = (PIO_COMPLETION_ROUTINE)sub_280062AB4;
      v20[-1].Context = v12;
      v20[-1].Control = -32;
      return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
    }
  }
  ++Irp->CurrentLocation;
  Irp->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
  return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
}


// ===== sub_280062AB4 @ 0x280062ab4 size=0x5e =====
__int64 __fastcall sub_280062AB4(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rdi
  void *v5; // rcx

  v3 = *(_QWORD *)(a1 + 64);
  if ( *(_BYTE *)(a2 + 65) != 0 )
    *(_BYTE *)(*(_QWORD *)(a2 + 184) + 3LL) |= 1u;
  v5 = *(void **)(a3 + 40);
  *(_DWORD *)(a3 + 60) = *(_DWORD *)(a2 + 48);
  *(_DWORD *)(a3 + 56) = *(_DWORD *)(a2 + 56);
  ObfReferenceObject(v5);
  _InterlockedAdd(&dword_280075124, 1u);
  sub_28005192C(*(_QWORD *)(v3 + 536), (struct _LIST_ENTRY *)a3);
  return 0;
}


// ===== sub_280062B18 @ 0x280062b18 size=0x22e =====
NTSTATUS __fastcall sub_280062B18(PDEVICE_OBJECT OwnerId, PIRP Irp)
{
  PVOID DeviceExtension; // rdi
  PIRP v3; // rbx
  NTSTATUS v5; // edi
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rsi
  struct _FILE_OBJECT *v8; // rax
  FSRTL_ADVANCED_FCB_HEADER *FsContext; // rsi
  PFSRTL_PER_STREAM_CONTEXT v10; // r12
  volatile signed __int32 *Flink; // rbp
  unsigned int Blink_high; // r15d
  struct _FAST_MUTEX *FastMutex; // rcx
  int Blink; // r14d
  int v15; // r11d
  struct _SLIST_ENTRY *v16; // rcx
  unsigned int v17; // [rsp+50h] [rbp+8h] BYREF

  DeviceExtension = OwnerId->DeviceExtension;
  v3 = Irp;
  if ( OwnerId != DeviceObject )
  {
    if ( *((_QWORD *)DeviceExtension + 3) != 0 && *((_DWORD *)DeviceExtension + 19) == 2 )
    {
      CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
      if ( qword_280074F00 != 0 && CurrentStackLocation->FileObject == (PFILE_OBJECT)qword_280074F00
        || (v8 = *((struct _FILE_OBJECT **)DeviceExtension + 68)) != nullptr && CurrentStackLocation->FileObject == v8 )
      {
        ++Irp->CurrentLocation;
        Irp->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
      }
      else
      {
        if ( qword_280074B68 == nullptr || (unsigned int)qword_280074B68(CurrentStackLocation->FileObject) == 0 )
        {
          FsContext = (FSRTL_ADVANCED_FCB_HEADER *)CurrentStackLocation->FileObject->FsContext;
          if ( FsContext != nullptr
            && (FsContext->Flags2 & 2) != 0
            && FsContext->FilterContexts.Flink != &FsContext->FilterContexts )
          {
            v10 = FsRtlLookupPerStreamContextInternal(FsContext, OwnerId, nullptr);
          }
          else
          {
            v10 = nullptr;
          }
          if ( v10 != nullptr )
          {
            ExAcquireFastMutex(FsContext->FastMutex);
            Flink = (volatile signed __int32 *)v10[1].Links.Flink;
            if ( Flink != nullptr )
              _InterlockedAdd(Flink, 1u);
            Blink_high = HIDWORD(v10[1].Links.Blink);
            FastMutex = FsContext->FastMutex;
            Blink = (int)v10[1].Links.Blink;
            v17 = Blink_high;
            ExReleaseFastMutex(FastMutex);
            if ( Flink != nullptr )
            {
              if ( Blink < 0 || Blink_high < dword_2800742E4 )
              {
                Blink = sub_280066C40(Flink, 0, &v17);
                ExAcquireFastMutex(FsContext->FastMutex);
                v15 = Blink | (__int64)v10[1].Links.Blink & 0xFF0000;
                HIDWORD(v10[1].Links.Blink) = v17;
                LODWORD(v10[1].Links.Blink) = v15;
                ExReleaseFastMutex(FsContext->FastMutex);
              }
              if ( (Blink & 0x10001) != 0 )
              {
                v5 = sub_2800513D0(*((PDEVICE_OBJECT *)DeviceExtension + 2), v3);
                if ( v5 >= 0 )
                  sub_28006725C(OwnerId, Flink);
                sub_28006C8A8((PSLIST_ENTRY)Flink);
                goto LABEL_34;
              }
              sub_28006C8A8((PSLIST_ENTRY)Flink);
              ExAcquireFastMutex(FsContext->FastMutex);
              v16 = (struct _SLIST_ENTRY *)v10[1].Links.Flink;
              if ( v16 != nullptr )
              {
                sub_28006C8A8(v16);
                v10[1].Links.Flink = nullptr;
              }
              ExReleaseFastMutex(FsContext->FastMutex);
            }
          }
        }
        ++v3->CurrentLocation;
        ++v3->Tail.Overlay.CurrentStackLocation;
        Irp = v3;
      }
    }
    else
    {
      ++Irp->CurrentLocation;
      ++Irp->Tail.Overlay.CurrentStackLocation;
    }
    return IofCallDriver(*((PDEVICE_OBJECT *)DeviceExtension + 2), Irp);
  }
  Irp->IoStatus.Information = 0;
  v5 = -1073741808;
  Irp->IoStatus.Status = -1073741808;
LABEL_34:
  IofCompleteRequest(v3, 0);
  return v5;
}


// ===== sub_280062D4C @ 0x280062d4c size=0x2d1 =====
NTSTATUS __fastcall sub_280062D4C(struct _DEVICE_OBJECT *a1, IRP *a2)
{
  PDEVICE_OBJECT *DeviceExtension; // r12
  PVOID PoolWithTag; // r14
  PDEVICE_OBJECT i; // r12
  PDEVICE_OBJECT DeviceObject; // rbx
  PDEVICE_OBJECT v7; // rdi
  _QWORD *v8; // rcx
  PDEVICE_OBJECT v9; // rbx
  PDEVICE_OBJECT v10; // rdi
  _QWORD *v11; // rcx

  DeviceExtension = (PDEVICE_OBJECT *)a1->DeviceExtension;
  if ( a1 == ::DeviceObject )
  {
    PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x88u, 0x74665450u);
    if ( PoolWithTag != nullptr )
    {
      ExAcquireFastMutex(&stru_280075760);
      for ( i = DriverObject->DeviceObject; i != nullptr; i = i->NextDevice )
      {
        if ( i != ::DeviceObject && *(_DWORD *)i->DeviceExtension == 7680402 )
        {
          ObfReferenceObject(i);
          ExReleaseFastMutex(&stru_280075760);
          return sub_2800B7DE9();
        }
      }
      ExReleaseFastMutex(&stru_280075760);
      ExFreePoolWithTag(PoolWithTag, 0x74665450u);
    }
    a2->IoStatus.Status = 0;
    a2->IoStatus.Information = 0;
    IofCompleteRequest(a2, 0);
    return 0;
  }
  else
  {
    if ( dword_280074A20 != 0 )
    {
      ExAcquireFastMutex(&stru_280075760);
      DeviceObject = DriverObject->DeviceObject;
      while ( DeviceObject != nullptr )
      {
        if ( DeviceObject == ::DeviceObject || *(_DWORD *)DeviceObject->DeviceExtension != 7680401 )
        {
          DeviceObject = DeviceObject->NextDevice;
        }
        else
        {
          ObfReferenceObject(DeviceObject);
          v7 = DeviceObject;
          ExReleaseFastMutex(&stru_280075760);
          v8 = DeviceObject->DeviceExtension;
          if ( v8[3] != 0 && *((_DWORD *)v8 + 19) == 2 )
            sub_28006AE30(v8 + 7);
          ExAcquireFastMutex(&stru_280075760);
          DeviceObject = DeviceObject->NextDevice;
          ObfDereferenceObject(v7);
        }
      }
      ExReleaseFastMutex(&stru_280075760);
      if ( _InterlockedDecrement(&dword_280075124) > 0 )
        KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
      _InterlockedAdd(&dword_280075124, 1u);
      KeClearEvent(&Event);
      ExAcquireFastMutex(&stru_280075760);
      v9 = DriverObject->DeviceObject;
      while ( v9 != nullptr )
      {
        if ( v9 == ::DeviceObject || *(_DWORD *)v9->DeviceExtension != 7680401 )
        {
          v9 = v9->NextDevice;
        }
        else
        {
          v10 = v9;
          ObfReferenceObject(v9);
          ExReleaseFastMutex(&stru_280075760);
          v11 = v9->DeviceExtension;
          if ( v11[3] != 0 && *((_DWORD *)v11 + 19) == 3 )
            sub_28006AE30(v11 + 7);
          ExAcquireFastMutex(&stru_280075760);
          v9 = v9->NextDevice;
          ObfDereferenceObject(v10);
        }
      }
      ExReleaseFastMutex(&stru_280075760);
    }
    ++a2->CurrentLocation;
    ++a2->Tail.Overlay.CurrentStackLocation;
    return IofCallDriver(DeviceExtension[2], a2);
  }
}


// ===== sub_280063024 @ 0x280063024 size=0xae =====
NTSTATUS __fastcall sub_280063024(PDEVICE_OBJECT Object, PIRP Irp)
{
  PDEVICE_OBJECT *DeviceExtension; // rsi
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  int v7; // esi

  DeviceExtension = (PDEVICE_OBJECT *)Object->DeviceExtension;
  if ( Object == DeviceObject )
  {
    Irp->IoStatus.Information = 0;
    Irp->IoStatus.Status = -1073741808;
    IofCompleteRequest(Irp, 0);
    return -1073741808;
  }
  else
  {
    CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
    if ( CurrentStackLocation->MinorFunction == 1 )
    {
      ObfReferenceObject(Object);
      v7 = sub_2800513D0(DeviceExtension[2], Irp);
      if ( v7 >= 0 )
        sub_280066DD4(Object);
      ObfDereferenceObject(Object);
      Irp->IoStatus.Status = v7;
      IofCompleteRequest(Irp, 0);
      return v7;
    }
    else
    {
      ++Irp->CurrentLocation;
      Irp->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
      return IofCallDriver(DeviceExtension[2], Irp);
    }
  }
}


// ===== sub_2800630D8 @ 0x2800630d8 size=0xb85 =====
__int64 sub_2800630D8()
{
  return sub_2800B7DE9();
}


// ===== sub_280063C64 @ 0x280063c64 size=0x1c =====
__int64 __fastcall sub_280063C64(__int64 a1, __int64 a2, struct _WORK_QUEUE_ITEM *a3)
{
  ExQueueWorkItem(a3, DelayedWorkQueue);
  return 3221225494LL;
}


// ===== sub_280063C88 @ 0x280063c88 size=0x4b7 =====
NTSTATUS __fastcall sub_280063C88(_QWORD *OwnerId, PIRP Irp)
{
  __int64 v2; // rsi
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rbx
  PIRP v4; // rdi
  bool v5; // zf
  DWORD LowPart; // eax
  struct _KTHREAD *CurrentThread; // rbx
  PEPROCESS CurrentProcess; // rax
  int v11; // r12d
  _QWORD *v12; // rbx
  NTSTATUS v13; // eax
  void **UserBuffer; // rcx
  _QWORD *v15; // r13
  unsigned int v16; // edx
  __int64 v17; // r8
  __int64 v18; // rcx
  __int64 v19; // rax
  _DWORD *PoolWithTag; // rax
  void *v21; // rbp
  struct _FILE_OBJECT *v22; // rax
  FSRTL_ADVANCED_FCB_HEADER *FsContext; // rbp
  PFSRTL_PER_STREAM_CONTEXT v24; // r12
  volatile signed __int32 *Flink; // r13
  unsigned int Blink_high; // r15d
  struct _FAST_MUTEX *FastMutex; // rcx
  int Blink; // r14d
  int v29; // r11d
  struct _SLIST_ENTRY *v30; // rcx
  NTSTATUS v31; // esi
  unsigned int v32; // [rsp+40h] [rbp-108h] BYREF
  ULONG_PTR v33; // [rsp+48h] [rbp-100h] BYREF
  _QWORD *v34; // [rsp+50h] [rbp-F8h]
  PFILE_OBJECT FileObject; // [rsp+58h] [rbp-F0h] BYREF
  PDEVICE_OBJECT DeviceObject; // [rsp+60h] [rbp-E8h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+68h] [rbp-E0h] BYREF
  wchar_t SourceString[64]; // [rsp+80h] [rbp-C8h] BYREF

  v2 = OwnerId[8];
  CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
  v4 = Irp;
  v5 = *(_DWORD *)(v2 + 76) == 2;
  v34 = OwnerId;
  if ( !v5 )
    goto LABEL_2;
  LowPart = CurrentStackLocation->Parameters.Read.ByteOffset.LowPart;
  switch ( LowPart )
  {
    case 0x901B0u:
    case 0x900F0u:
      Irp->IoStatus.Information = 0;
      Irp->IoStatus.Status = -1073741790;
LABEL_58:
      IofCompleteRequest(v4, 0);
      return -1073741790;
    case 0x90074u:
      CurrentThread = KeGetCurrentThread();
      CurrentProcess = IoGetCurrentProcess();
      if ( sub_2800521C4((__int64)CurrentProcess, (__int64)CurrentThread, 1) != 0 )
        goto LABEL_8;
      v4->IoStatus.Information = 0;
      v4->IoStatus.Status = -1073741790;
      goto LABEL_58;
    case 0x9003Bu:
      if ( qword_280074F00 == 0 || CurrentStackLocation->FileObject != (PFILE_OBJECT)qword_280074F00 )
      {
LABEL_2:
        ++Irp->CurrentLocation;
        Irp->Tail.Overlay.CurrentStackLocation = CurrentStackLocation + 1;
        return IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 16), Irp);
      }
      v11 = sub_280052014((__int64)KeGetCurrentThread());
      if ( v11 >= 0 )
      {
        v11 = sub_2800663A8(
                OwnerId,
                CurrentStackLocation->Parameters.CreatePipe.Parameters,
                CurrentStackLocation->Parameters.Create.Options,
                v4->UserBuffer,
                CurrentStackLocation->Parameters.Read.Length,
                &v33);
        sub_2800520DC((__int64)KeGetCurrentThread());
        if ( v11 >= 0 )
        {
          v12 = *(_QWORD **)v4->UserBuffer;
          v13 = sub_2800513D0(*(PDEVICE_OBJECT *)(v2 + 16), v4);
          UserBuffer = (void **)v4->UserBuffer;
          v15 = *UserBuffer;
          *UserBuffer = v12;
          if ( v13 >= 0 )
          {
            v16 = 0;
            v17 = 0;
            if ( *v12 != 0 )
            {
              v18 = 0;
              do
              {
                v19 = v15[v18];
                if ( v19 == 0 )
                  break;
                if ( v12[v18] != v19 )
                  break;
                if ( v12[v18 + 1] != v15[v18 + 1] )
                  break;
                ++v17;
                ++v16;
                v18 = 2 * v17;
              }
              while ( v12[2 * v17] != 0 );
            }
            if ( v12[2 * v16] != 0 || v15[2 * v16] != 0 )
            {
              PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x88u, 0x74665450u);
              v21 = PoolWithTag;
              if ( PoolWithTag != nullptr )
              {
                *PoolWithTag = 1953524580;
                PoolWithTag[1] = 2000;
                *((_QWORD *)PoolWithTag + 1) = v12;
                PoolWithTag[4] = 1;
                swprintf(SourceString, L"\\Device\\%s%x", aDpshadow, *(unsigned int *)(v2 + 72));
                RtlInitUnicodeString(&DestinationString, SourceString);
                if ( IoGetDeviceObjectPointer(&DestinationString, 0x80u, &FileObject, &DeviceObject) >= 0 )
                {
                  sub_2800514A4(DeviceObject, dword_280074B30 - 2147473948, v21, 0x88u, v21, 0x88u);
                  ObfDereferenceObject(FileObject);
                }
                ExFreePoolWithTag(v21, 0x74665450u);
              }
            }
            ExFreePoolWithTag(v15, 0);
          }
        }
      }
      v4->IoStatus.Information = v33;
      v4->IoStatus.Status = v11;
      IofCompleteRequest(v4, 0);
      return v11;
    default:
      if ( qword_280074F00 != 0 && CurrentStackLocation->FileObject == (PFILE_OBJECT)qword_280074F00 )
        goto LABEL_2;
      v22 = *(struct _FILE_OBJECT **)(v2 + 544);
      if ( v22 != nullptr && CurrentStackLocation->FileObject == v22 )
        goto LABEL_2;
      if ( qword_280074B68 != nullptr && (unsigned int)qword_280074B68(CurrentStackLocation->FileObject) != 0
        || CurrentStackLocation->Parameters.Read.ByteOffset.LowPart != 639040
        && CurrentStackLocation->Parameters.Read.ByteOffset.LowPart != 622792 )
      {
        goto LABEL_8;
      }
      FsContext = (FSRTL_ADVANCED_FCB_HEADER *)CurrentStackLocation->FileObject->FsContext;
      if ( FsContext != nullptr
        && (FsContext->Flags2 & 2) != 0
        && FsContext->FilterContexts.Flink != &FsContext->FilterContexts )
      {
        v24 = FsRtlLookupPerStreamContextInternal(FsContext, OwnerId, nullptr);
      }
      else
      {
        v24 = nullptr;
      }
      if ( v24 == nullptr )
        goto LABEL_8;
      ExAcquireFastMutex(FsContext->FastMutex);
      Flink = (volatile signed __int32 *)v24[1].Links.Flink;
      if ( Flink != nullptr )
        _InterlockedAdd(Flink, 1u);
      Blink_high = HIDWORD(v24[1].Links.Blink);
      FastMutex = FsContext->FastMutex;
      Blink = (int)v24[1].Links.Blink;
      v32 = Blink_high;
      ExReleaseFastMutex(FastMutex);
      if ( Flink == nullptr )
      {
LABEL_8:
        ++v4->CurrentLocation;
        ++v4->Tail.Overlay.CurrentStackLocation;
        Irp = v4;
        return IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 16), Irp);
      }
      if ( Blink < 0 || Blink_high < dword_2800742E4 )
      {
        Blink = sub_280066C40(Flink, 0, &v32);
        ExAcquireFastMutex(FsContext->FastMutex);
        v29 = Blink | (__int64)v24[1].Links.Blink & 0xFF0000;
        HIDWORD(v24[1].Links.Blink) = v32;
        LODWORD(v24[1].Links.Blink) = v29;
        ExReleaseFastMutex(FsContext->FastMutex);
      }
      if ( (Blink & 0x10001) == 0 )
      {
        sub_28006C8A8((PSLIST_ENTRY)Flink);
        ExAcquireFastMutex(FsContext->FastMutex);
        v30 = (struct _SLIST_ENTRY *)v24[1].Links.Flink;
        if ( v30 != nullptr )
        {
          sub_28006C8A8(v30);
          v24[1].Links.Flink = nullptr;
        }
        ExReleaseFastMutex(FsContext->FastMutex);
        goto LABEL_8;
      }
      v31 = sub_2800513D0(*(PDEVICE_OBJECT *)(v2 + 16), v4);
      if ( v31 >= 0 )
        sub_280067564(
          v34,
          Flink,
          v4->AssociatedIrp.MasterIrp,
          CurrentStackLocation->Parameters.Create.Options,
          CurrentStackLocation->Parameters.Read.ByteOffset.LowPart);
      sub_28006C8A8((PSLIST_ENTRY)Flink);
      v4->IoStatus.Status = v31;
      IofCompleteRequest(v4, 0);
      return v31;
  }
}


// ===== sub_280064148 @ 0x280064148 size=0x448 =====
NTSTATUS __fastcall sub_280064148(__int64 a1, IRP *a2)
{
  __int64 v2; // r13
  __int64 v4; // rbx
  char v6; // si
  void *v7; // rcx
  bool v8; // zf
  IRP *v9; // rax
  NTSTATUS Status; // eax
  char v12; // r12
  NTSTATUS v13; // esi
  char *DeviceExtension; // rbp
  int v15; // eax
  char *v16; // rsi
  __int64 v17; // r12
  PDEVICE_OBJECT v18; // r11
  _QWORD *PoolWithTag; // rsi
  __int64 v20; // rax
  struct _SLIST_ENTRY *v21; // r12
  int v22; // ebx
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rdx
  struct _IO_STACK_LOCATION *v24; // rbx
  struct _IO_STACK_LOCATION *v25; // rcx
  PDEVICE_OBJECT DeviceObject; // [rsp+50h] [rbp-118h] BYREF
  ULONG ReturnLength; // [rsp+58h] [rbp-110h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+60h] [rbp-108h] BYREF
  struct _KEVENT Event; // [rsp+70h] [rbp-F8h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+88h] [rbp-E0h] BYREF
  UNICODE_STRING String1; // [rsp+A0h] [rbp-C8h] BYREF
  __int64 v32; // [rsp+B0h] [rbp-B8h] BYREF

  v2 = *(_QWORD *)(a1 + 64);
  v4 = *(_QWORD *)(a2->Tail.Overlay.CurrentStackLocation->Parameters.WMI.ProviderId + 16);
  v6 = 0;
  if ( MajorVersion != 5 )
    goto LABEL_13;
  if ( MinorVersion == 0 )
    goto LABEL_17;
  if ( MinorVersion == 1 )
  {
    if ( *(_DWORD *)(v4 + 72) != 7 )
      goto LABEL_17;
    v7 = *(void **)(v4 + 8);
    String1.MaximumLength = 112;
    String1.Buffer = (PWSTR)&v32;
    String1.Length = 0;
    if ( ObQueryNameString(v7, (POBJECT_NAME_INFORMATION)&String1, 0x70u, &ReturnLength) < 0 )
      goto LABEL_17;
    RtlInitUnicodeString(&DestinationString, L"\\Driver\\VolSnap");
    v8 = RtlEqualUnicodeString(&String1, &DestinationString, 1u) == 0;
  }
  else
  {
LABEL_13:
    if ( *(_DWORD *)(v4 + 72) != 36 )
      goto LABEL_17;
    KeInitializeEvent(&Event, NotificationEvent, 0);
    v9 = IoBuildDeviceIoControlRequest(0x70024u, (PDEVICE_OBJECT)v4, nullptr, 0, nullptr, 0, 0, &Event, &IoStatusBlock);
    if ( v9 == nullptr )
      goto LABEL_17;
    Status = IofCallDriver((PDEVICE_OBJECT)v4, v9);
    if ( Status == 259 )
    {
      KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
      Status = IoStatusBlock.Status;
    }
    if ( Status == -1073741662 )
    {
      v6 = 1;
      Status = 0;
    }
    if ( Status < 0 )
      goto LABEL_17;
    v8 = v6 == 0;
  }
  if ( !v8 )
  {
    ++a2->CurrentLocation;
    ++a2->Tail.Overlay.CurrentStackLocation;
    return IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 16), a2);
  }
LABEL_17:
  if ( *(PDRIVER_OBJECT *)(v4 + 8) != DriverObject
    || (PDEVICE_OBJECT)v4 == ::DeviceObject
    || (v12 = 1, **(_DWORD **)(v4 + 64) != 7680404) )
  {
    v12 = 0;
  }
  ExAcquireFastMutex(&stru_280075760);
  v13 = IoCreateDevice(DriverObject, 0x230u, nullptr, *(_DWORD *)(a1 + 72), 0, 0, &DeviceObject);
  ExReleaseFastMutex(&stru_280075760);
  if ( v13 < 0 )
  {
    a2->IoStatus.Status = v13;
LABEL_31:
    a2->IoStatus.Information = 0;
    IofCompleteRequest(a2, 0);
    return v13;
  }
  DeviceExtension = (char *)DeviceObject->DeviceExtension;
  *((_DWORD *)DeviceExtension + 18) = -1;
  *(_DWORD *)DeviceExtension = 7680401;
  v15 = -(v12 != 0);
  v16 = DeviceExtension + 104;
  v17 = 8;
  *((_DWORD *)DeviceExtension + 19) = (v15 & 2) + 1;
  *((_DWORD *)DeviceExtension + 20) = *(_DWORD *)(v2 + 80);
  do
  {
    *((_DWORD *)v16 - 4) = 1;
    *((_QWORD *)v16 - 1) = 0;
    *(_DWORD *)v16 = 0;
    KeInitializeEvent((PRKEVENT)(v16 + 8), SynchronizationEvent, 0);
    v16 += 56;
    --v17;
  }
  while ( v17 != 0 );
  sub_2800517A0((_QWORD *)DeviceExtension + 67, 21, 1);
  v18 = DeviceObject;
  *((_QWORD *)DeviceExtension + 2) = 0;
  *((_QWORD *)DeviceExtension + 1) = v18;
  *((_QWORD *)DeviceExtension + 3) = v4;
  *((_QWORD *)DeviceExtension + 4) = 0;
  *((_WORD *)DeviceExtension + 28) = 0;
  *((_WORD *)DeviceExtension + 29) = 0;
  *((_QWORD *)DeviceExtension + 8) = 0;
  *((_WORD *)DeviceExtension + 20) = 0;
  *((_WORD *)DeviceExtension + 21) = 0;
  *((_QWORD *)DeviceExtension + 6) = 0;
  *((_QWORD *)DeviceExtension + 68) = 0;
  DeviceExtension[552] = 0;
  PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x38u, 0x766D5450u);
  if ( PoolWithTag == nullptr )
  {
    ExAcquireFastMutex(&stru_280075760);
    IoDeleteDevice(DeviceObject);
    ExReleaseFastMutex(&stru_280075760);
LABEL_30:
    a2->IoStatus.Status = -1073741670;
    v13 = -1073741670;
    goto LABEL_31;
  }
  v20 = sub_28006C5B4((PVOID)v4);
  v21 = (struct _SLIST_ENTRY *)v20;
  if ( v20 == 0
    || (v22 = sub_28006C784((PUNICODE_STRING)(DeviceExtension + 56), (PCUNICODE_STRING)(v20 + 8)),
        sub_28006C8A8(v21),
        v22 < 0) )
  {
    ExAcquireFastMutex(&stru_280075760);
    IoDeleteDevice(DeviceObject);
    ExReleaseFastMutex(&stru_280075760);
    ExFreePoolWithTag(PoolWithTag, 0x766D5450u);
    goto LABEL_30;
  }
  PoolWithTag[3] = PoolWithTag;
  *PoolWithTag = 0;
  PoolWithTag[4] = a1;
  PoolWithTag[5] = a2;
  PoolWithTag[2] = sub_280064598;
  PoolWithTag[6] = DeviceObject;
  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  v24 = CurrentStackLocation - 1;
  memmove(&CurrentStackLocation[-1], CurrentStackLocation, 0x38u);
  v24->Control = 0;
  v25 = a2->Tail.Overlay.CurrentStackLocation;
  v25[-1].Context = PoolWithTag;
  v25[-1].Control = -32;
  v25[-1].CompletionRoutine = (PIO_COMPLETION_ROUTINE)sub_280063C64;
  a2->Tail.Overlay.CurrentStackLocation->Control |= 1u;
  IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 16), a2);
  return 259;
}


// ===== sub_280064598 @ 0x280064598 size=0x2e =====
void __fastcall sub_280064598(_QWORD *a1)
{
  sub_2800645CC(a1[4], a1[5], a1[6]);
  ExFreePoolWithTag(a1, 0x766D5450u);
}


// ===== sub_2800645CC @ 0x2800645cc size=0x28e =====
__int64 __fastcall sub_2800645CC(__int64 a1, IRP *a2, struct _DEVICE_OBJECT *a3)
{
  char *DeviceExtension; // rsi
  __int64 v6; // r12
  char v7; // r15
  __int64 v8; // r13
  char *v9; // rax
  int v10; // edi
  char *v11; // r14
  struct _WORK_QUEUE_ITEM *PoolWithTag; // rdi
  _DWORD *v13; // rax
  _DWORD *v14; // rdi
  int v15; // ebx
  struct _DEVICE_OBJECT *AttachedDevice; // rax
  unsigned int Status; // ebx
  PVOID Object; // [rsp+78h] [rbp+10h]

  DeviceExtension = (char *)a3->DeviceExtension;
  v6 = *(_QWORD *)(*((_QWORD *)DeviceExtension + 3) + 56LL);
  v7 = 0;
  if ( a2->IoStatus.Status < 0 )
  {
    sub_2800657F4(a3);
    ExAcquireFastMutex(&stru_280075760);
    IoDeleteDevice(a3);
    ExReleaseFastMutex(&stru_280075760);
  }
  else
  {
    ExAcquireFastMutex(&stru_2800751C0);
    if ( (unsigned __int8)sub_280065850(*(PVOID *)(v6 + 8)) != 0 )
    {
      sub_2800657F4(a3);
      ExAcquireFastMutex(&stru_280075760);
      IoDeleteDevice(a3);
      ExReleaseFastMutex(&stru_280075760);
      ObfDereferenceObject(Object);
    }
    else
    {
      v8 = *(_QWORD *)(v6 + 8);
      v9 = (char *)a3->DeviceExtension;
      if ( (*(_BYTE *)(v8 + 48) & 4) != 0 )
        a3->Flags |= 4u;
      if ( (*(_BYTE *)(v8 + 48) & 0x10) != 0 )
        a3->Flags |= 0x10u;
      v10 = 0;
      v11 = v9 + 16;
      while ( (int)sub_28006548C(a3, v8, v11) < 0 )
      {
        KeDelayExecutionThread(0, 0, &Interval);
        if ( (unsigned int)++v10 >= 8 )
        {
          sub_2800657F4(a3);
          ExAcquireFastMutex(&stru_280075760);
          IoDeleteDevice(a3);
          ExReleaseFastMutex(&stru_280075760);
          goto LABEL_14;
        }
      }
      a3->Flags &= ~0x80u;
      v7 = 1;
      *((_QWORD *)DeviceExtension + 4) = *(_QWORD *)(v6 + 8);
    }
LABEL_14:
    ExReleaseFastMutex(&stru_2800751C0);
    if ( v7 != 0 && *((_QWORD *)DeviceExtension + 3) != 0 && *((_DWORD *)DeviceExtension + 19) != 3 )
    {
      PoolWithTag = (struct _WORK_QUEUE_ITEM *)ExAllocatePoolWithTag(NonPagedPool, 0x30u, 0x74506C4Eu);
      if ( PoolWithTag != nullptr )
      {
        PoolWithTag->Parameter = PoolWithTag;
        PoolWithTag->WorkerRoutine = (PWORKER_THREAD_ROUTINE)sub_28006C6C0;
        PoolWithTag->List.Flink = nullptr;
        ObfReferenceObject(a3);
        PoolWithTag[1].List.Flink = (struct _LIST_ENTRY *)a3;
        PoolWithTag[1].List.Blink = (struct _LIST_ENTRY *)(DeviceExtension + 8);
        ExQueueWorkItem(PoolWithTag, DelayedWorkQueue);
      }
      else
      {
        *((_WORD *)DeviceExtension + 20) = 0;
      }
      v13 = ExAllocatePoolWithTag(NonPagedPool, 0x88u, 0x74665450u);
      v14 = v13;
      if ( v13 != nullptr )
      {
        v15 = dword_280074B30;
        *v13 = 1953524580;
        v13[1] = 1000;
        AttachedDevice = IoGetAttachedDevice(*((PDEVICE_OBJECT *)DeviceExtension + 3));
        if ( sub_2800514A4(AttachedDevice, v15 - 2147473948, v14, 0x88u, v14, 0x88u) >= 0 )
        {
          *((_DWORD *)DeviceExtension + 18) = v14[2];
          *((_DWORD *)DeviceExtension + 19) = v14[3];
        }
        ExFreePoolWithTag(v14, 0x74665450u);
      }
    }
  }
  Status = a2->IoStatus.Status;
  IofCompleteRequest(a2, 0);
  return Status;
}


// ===== sub_280064860 @ 0x280064860 size=0xe8 =====
__int64 __fastcall sub_280064860(__int64 a1, IRP *a2)
{
  __int64 v2; // rbp
  _QWORD *PoolWithTag; // rax
  _QWORD *v6; // rsi
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rdx
  struct _IO_STACK_LOCATION *v9; // rbx
  struct _IO_STACK_LOCATION *v10; // rax

  v2 = *(_QWORD *)(a1 + 64);
  PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x38u, 0x666C5450u);
  v6 = PoolWithTag;
  if ( PoolWithTag != nullptr )
  {
    *PoolWithTag = 0;
    PoolWithTag[6] = 0;
    PoolWithTag[4] = a1;
    PoolWithTag[3] = PoolWithTag;
    PoolWithTag[5] = a2;
    PoolWithTag[2] = sub_280064950;
    CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
    v9 = CurrentStackLocation - 1;
    memmove(&CurrentStackLocation[-1], CurrentStackLocation, 0x38u);
    v9->Control = 0;
    v10 = a2->Tail.Overlay.CurrentStackLocation;
    v10[-1].Context = v6;
    v10[-1].Control = -32;
    v10[-1].CompletionRoutine = (PIO_COMPLETION_ROUTINE)sub_280063C64;
    IoDetachDevice(*(PDEVICE_OBJECT *)(v2 + 16));
    a2->Tail.Overlay.CurrentStackLocation->Control |= 1u;
    IofCallDriver(*(PDEVICE_OBJECT *)(v2 + 16), a2);
    return 259;
  }
  else
  {
    a2->IoStatus.Information = 0;
    a2->IoStatus.Status = -1073741670;
    IofCompleteRequest(a2, 0);
    return 3221225626LL;
  }
}


// ===== sub_280064950 @ 0x280064950 size=0x93 =====
void __fastcall sub_280064950(_QWORD *a1)
{
  IRP *v1; // rsi
  struct _DEVICE_OBJECT *v2; // rdi

  v1 = (IRP *)a1[5];
  v2 = (struct _DEVICE_OBJECT *)a1[4];
  if ( v1->IoStatus.Status >= 0 || v1->IoStatus.Status == -1073741554 )
  {
    sub_2800657F4(a1[4]);
    ExAcquireFastMutex(&stru_280075760);
    IoDeleteDevice(v2);
    ExReleaseFastMutex(&stru_280075760);
  }
  else
  {
    sub_28006548C(a1[4], *((_QWORD *)v2->DeviceExtension + 2), (char *)v2->DeviceExtension + 16);
  }
  IofCompleteRequest(v1, 0);
  ExFreePoolWithTag(a1, 0x666C5450u);
}


// ===== sub_2800649EC @ 0x2800649ec size=0x87 =====
char __fastcall sub_2800649EC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        char a6,
        __int64 a7,
        struct _DEVICE_OBJECT *a8)
{
  _QWORD *DeviceExtension; // rax
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 (__fastcall *v13)(__int64, __int64); // r10

  DeviceExtension = a8->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a8 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v11 = DeviceExtension[2]) != 0
    && (v12 = *(_QWORD *)(*(_QWORD *)(v11 + 8) + 80LL)) != 0
    && *(_DWORD *)v12 >= 0x10u
    && (v13 = *(__int64 (__fastcall **)(__int64, __int64))(v12 + 8)) != nullptr )
  {
    return v13(a1, a2);
  }
  else
  {
    return 0;
  }
}


// ===== sub_280064A7C @ 0x280064a7c size=0x89 =====
char __fastcall sub_280064A7C(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        __int64 a6,
        __int64 a7,
        struct _DEVICE_OBJECT *a8)
{
  _QWORD *DeviceExtension; // rax
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 (__fastcall *v13)(__int64, __int64); // r10

  DeviceExtension = a8->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a8 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v11 = DeviceExtension[2]) != 0
    && (v12 = *(_QWORD *)(*(_QWORD *)(v11 + 8) + 80LL)) != 0
    && *(_DWORD *)v12 >= 0x18u
    && (v13 = *(__int64 (__fastcall **)(__int64, __int64))(v12 + 16)) != nullptr )
  {
    return v13(a1, a2);
  }
  else
  {
    return 0;
  }
}


// ===== sub_280064B0C @ 0x280064b0c size=0x89 =====
char __fastcall sub_280064B0C(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        __int64 a6,
        __int64 a7,
        struct _DEVICE_OBJECT *a8)
{
  _QWORD *DeviceExtension; // rax
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 (__fastcall *v13)(__int64, __int64); // r10

  DeviceExtension = a8->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a8 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v11 = DeviceExtension[2]) != 0
    && (v12 = *(_QWORD *)(*(_QWORD *)(v11 + 8) + 80LL)) != 0
    && *(_DWORD *)v12 >= 0x20u
    && (v13 = *(__int64 (__fastcall **)(__int64, __int64))(v12 + 24)) != nullptr )
  {
    return v13(a1, a2);
  }
  else
  {
    return 0;
  }
}


// ===== sub_280064B9C @ 0x280064b9c size=0x66 =====
char __fastcall sub_280064B9C(__int64 a1, char a2, __int64 a3, __int64 a4, struct _DEVICE_OBJECT *a5)
{
  _QWORD *DeviceExtension; // rax
  __int64 v8; // rdx
  __int64 v9; // rcx
  __int64 (__fastcall *v10)(__int64, __int64); // rax

  DeviceExtension = a5->DeviceExtension;
  if ( DeviceExtension == nullptr )
    return 0;
  if ( a5 == DeviceObject )
    return 0;
  if ( *(_DWORD *)DeviceExtension != 7680401 )
    return 0;
  v8 = DeviceExtension[2];
  if ( v8 == 0 )
    return 0;
  v9 = *(_QWORD *)(*(_QWORD *)(v8 + 8) + 80LL);
  if ( v9 == 0 )
    return 0;
  if ( *(_DWORD *)v9 < 0x28u )
    return 0;
  v10 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 32);
  if ( v10 == nullptr )
    return 0;
  LOBYTE(v8) = a2;
  return v10(a1, v8);
}


// ===== sub_280064C08 @ 0x280064c08 size=0x66 =====
char __fastcall sub_280064C08(__int64 a1, char a2, __int64 a3, __int64 a4, struct _DEVICE_OBJECT *a5)
{
  _QWORD *DeviceExtension; // rax
  __int64 v8; // rdx
  __int64 v9; // rcx
  __int64 (__fastcall *v10)(__int64, __int64); // rax

  DeviceExtension = a5->DeviceExtension;
  if ( DeviceExtension == nullptr )
    return 0;
  if ( a5 == DeviceObject )
    return 0;
  if ( *(_DWORD *)DeviceExtension != 7680401 )
    return 0;
  v8 = DeviceExtension[2];
  if ( v8 == 0 )
    return 0;
  v9 = *(_QWORD *)(*(_QWORD *)(v8 + 8) + 80LL);
  if ( v9 == 0 )
    return 0;
  if ( *(_DWORD *)v9 < 0x30u )
    return 0;
  v10 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 40);
  if ( v10 == nullptr )
    return 0;
  LOBYTE(v8) = a2;
  return v10(a1, v8);
}


// ===== sub_280064C74 @ 0x280064c74 size=0x98 =====
char __fastcall sub_280064C74(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        char a6,
        char a7,
        __int64 a8,
        struct _DEVICE_OBJECT *a9)
{
  _QWORD *DeviceExtension; // rax
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 (__fastcall *v14)(__int64, __int64); // r10

  DeviceExtension = a9->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a9 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v12 = DeviceExtension[2]) != 0
    && (v13 = *(_QWORD *)(*(_QWORD *)(v12 + 8) + 80LL)) != 0
    && *(_DWORD *)v13 >= 0x38u
    && (v14 = *(__int64 (__fastcall **)(__int64, __int64))(v13 + 48)) != nullptr )
  {
    return v14(a1, a2);
  }
  else
  {
    return 0;
  }
}


// ===== sub_280064D14 @ 0x280064d14 size=0x7c =====
char __fastcall sub_280064D14(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        __int64 a6,
        struct _DEVICE_OBJECT *a7)
{
  _QWORD *DeviceExtension; // rax
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 (__fastcall *v12)(__int64, __int64); // r10

  DeviceExtension = a7->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a7 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v10 = DeviceExtension[2]) != 0
    && (v11 = *(_QWORD *)(*(_QWORD *)(v10 + 8) + 80LL)) != 0
    && *(_DWORD *)v11 >= 0x40u
    && (v12 = *(__int64 (__fastcall **)(__int64, __int64))(v11 + 56)) != nullptr )
  {
    return v12(a1, a2);
  }
  else
  {
    return 0;
  }
}


// ===== sub_280064D98 @ 0x280064d98 size=0x57 =====
char __fastcall sub_280064D98(__int64 a1, __int64 a2, __int64 a3, struct _DEVICE_OBJECT *a4)
{
  _QWORD *DeviceExtension; // r9
  __int64 v7; // r9
  __int64 v8; // rcx
  __int64 (__fastcall *v9)(__int64); // rax

  DeviceExtension = a4->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a4 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v7 = DeviceExtension[2]) != 0
    && (v8 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 80LL)) != 0
    && *(_DWORD *)v8 >= 0x48u
    && (v9 = *(__int64 (__fastcall **)(__int64))(v8 + 64)) != nullptr )
  {
    return v9(a1);
  }
  else
  {
    return 0;
  }
}


// ===== sub_280064DF8 @ 0x280064df8 size=0x66 =====
char __fastcall sub_280064DF8(__int64 a1, __int64 a2, __int64 a3, __int64 a4, struct _DEVICE_OBJECT *a5)
{
  _QWORD *DeviceExtension; // rax
  __int64 v8; // rdx
  __int64 v9; // rcx
  __int64 (__fastcall *v10)(__int64, __int64); // rax

  DeviceExtension = a5->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a5 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v8 = DeviceExtension[2]) != 0
    && (v9 = *(_QWORD *)(*(_QWORD *)(v8 + 8) + 80LL)) != 0
    && *(_DWORD *)v9 >= 0x50u
    && (v10 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 72)) != nullptr )
  {
    return v10(a1, a2);
  }
  else
  {
    return 0;
  }
}


// ===== sub_280064E64 @ 0x280064e64 size=0x9a =====
char __fastcall sub_280064E64(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        __int64 a8,
        struct _DEVICE_OBJECT *a9)
{
  _QWORD *DeviceExtension; // rax
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 (__fastcall *v14)(__int64, __int64); // r10

  DeviceExtension = a9->DeviceExtension;
  if ( DeviceExtension == nullptr )
    return 0;
  if ( a9 == DeviceObject )
    return 0;
  if ( *(_DWORD *)DeviceExtension != 7680401 )
    return 0;
  v12 = DeviceExtension[2];
  if ( v12 == 0 )
    return 0;
  v13 = *(_QWORD *)(*(_QWORD *)(v12 + 8) + 80LL);
  if ( v13 == 0 )
    return 0;
  if ( *(_DWORD *)v13 < 0x58u )
    return 0;
  v14 = *(__int64 (__fastcall **)(__int64, __int64))(v13 + 80);
  if ( v14 == nullptr )
    return 0;
  LOBYTE(v12) = a2;
  return v14(a1, v12);
}


// ===== sub_280064F04 @ 0x280064f04 size=0x77 =====
void __fastcall sub_280064F04(PDEVICE_OBJECT DeviceObject, PDEVICE_OBJECT TargetDevice)
{
  _DWORD *DeviceExtension; // rax

  DeviceExtension = DeviceObject->DeviceExtension;
  if ( DeviceExtension != nullptr && DeviceObject != ::DeviceObject && *DeviceExtension == 7680401 )
  {
    sub_280066DD4(DeviceObject);
    IoDetachDevice(TargetDevice);
    sub_2800657F4(DeviceObject);
    ExAcquireFastMutex(&stru_280075760);
    IoDeleteDevice(DeviceObject);
    ExReleaseFastMutex(&stru_280075760);
  }
  else
  {
    sub_28005232C(DeviceObject, nullptr);
  }
}


// ===== sub_280064F84 @ 0x280064f84 size=0x66 =====
char __fastcall sub_280064F84(__int64 a1, char a2, __int64 a3, __int64 a4, struct _DEVICE_OBJECT *a5)
{
  _QWORD *DeviceExtension; // rax
  __int64 v8; // rdx
  __int64 v9; // rcx
  __int64 (__fastcall *v10)(__int64, __int64); // rax

  DeviceExtension = a5->DeviceExtension;
  if ( DeviceExtension == nullptr )
    return 0;
  if ( a5 == DeviceObject )
    return 0;
  if ( *(_DWORD *)DeviceExtension != 7680401 )
    return 0;
  v8 = DeviceExtension[2];
  if ( v8 == 0 )
    return 0;
  v9 = *(_QWORD *)(*(_QWORD *)(v8 + 8) + 80LL);
  if ( v9 == 0 )
    return 0;
  if ( *(_DWORD *)v9 < 0x78u )
    return 0;
  v10 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 112);
  if ( v10 == nullptr )
    return 0;
  LOBYTE(v8) = a2;
  return v10(a1, v8);
}


// ===== sub_280064FF0 @ 0x280064ff0 size=0x84 =====
char __fastcall sub_280064FF0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        struct _DEVICE_OBJECT *a7)
{
  _QWORD *DeviceExtension; // rax
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 (__fastcall *v12)(__int64, __int64); // r10

  DeviceExtension = a7->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a7 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v10 = DeviceExtension[2]) != 0
    && (v11 = *(_QWORD *)(*(_QWORD *)(v10 + 8) + 80LL)) != 0
    && *(_DWORD *)v11 >= 0x88u
    && (v12 = *(__int64 (__fastcall **)(__int64, __int64))(v11 + 128)) != nullptr )
  {
    return v12(a1, a2);
  }
  else
  {
    return 0;
  }
}


// ===== sub_28006507C @ 0x28006507c size=0x59 =====
char __fastcall sub_28006507C(__int64 a1, __int64 a2, struct _DEVICE_OBJECT *a3)
{
  _QWORD *DeviceExtension; // rax
  __int64 v5; // r8
  __int64 v6; // rcx
  __int64 (__fastcall *v7)(__int64); // rax

  DeviceExtension = a3->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a3 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v5 = DeviceExtension[2]) != 0
    && (v6 = *(_QWORD *)(*(_QWORD *)(v5 + 8) + 80LL)) != 0
    && *(_DWORD *)v6 >= 0x90u
    && (v7 = *(__int64 (__fastcall **)(__int64))(v6 + 136)) != nullptr )
  {
    return v7(a1);
  }
  else
  {
    return 0;
  }
}


// ===== sub_2800650DC @ 0x2800650dc size=0x84 =====
char __fastcall sub_2800650DC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        struct _DEVICE_OBJECT *a7)
{
  _QWORD *DeviceExtension; // rax
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 (__fastcall *v12)(__int64, __int64); // r10

  DeviceExtension = a7->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a7 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v10 = DeviceExtension[2]) != 0
    && (v11 = *(_QWORD *)(*(_QWORD *)(v10 + 8) + 80LL)) != 0
    && *(_DWORD *)v11 >= 0x98u
    && (v12 = *(__int64 (__fastcall **)(__int64, __int64))(v11 + 144)) != nullptr )
  {
    return v12(a1, a2);
  }
  else
  {
    return 0;
  }
}


// ===== sub_280065168 @ 0x280065168 size=0x5d =====
char __fastcall sub_280065168(__int64 a1, __int64 a2, __int64 a3, struct _DEVICE_OBJECT *a4)
{
  _QWORD *DeviceExtension; // r9
  __int64 v7; // r9
  __int64 v8; // rcx
  __int64 (__fastcall *v9)(__int64); // rax

  DeviceExtension = a4->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a4 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v7 = DeviceExtension[2]) != 0
    && (v8 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 80LL)) != 0
    && *(_DWORD *)v8 >= 0xA0u
    && (v9 = *(__int64 (__fastcall **)(__int64))(v8 + 152)) != nullptr )
  {
    return v9(a1);
  }
  else
  {
    return 0;
  }
}


// ===== sub_2800651CC @ 0x2800651cc size=0xb7 =====
char __fastcall sub_2800651CC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        int a9,
        struct _DEVICE_OBJECT *a10)
{
  _QWORD *DeviceExtension; // rax
  __int64 v13; // rdx
  __int64 v14; // rcx
  __int64 (__fastcall *v15)(__int64, __int64); // r10

  DeviceExtension = a10->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a10 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v13 = DeviceExtension[2]) != 0
    && (v14 = *(_QWORD *)(*(_QWORD *)(v13 + 8) + 80LL)) != 0
    && *(_DWORD *)v14 >= 0xA8u
    && (v15 = *(__int64 (__fastcall **)(__int64, __int64))(v14 + 160)) != nullptr )
  {
    return v15(a1, a2);
  }
  else
  {
    return 0;
  }
}


// ===== sub_28006528C @ 0x28006528c size=0xb7 =====
char __fastcall sub_28006528C(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        int a9,
        struct _DEVICE_OBJECT *a10)
{
  _QWORD *DeviceExtension; // rax
  __int64 v13; // rdx
  __int64 v14; // rcx
  __int64 (__fastcall *v15)(__int64, __int64); // r10

  DeviceExtension = a10->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a10 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v13 = DeviceExtension[2]) != 0
    && (v14 = *(_QWORD *)(*(_QWORD *)(v13 + 8) + 80LL)) != 0
    && *(_DWORD *)v14 >= 0xB0u
    && (v15 = *(__int64 (__fastcall **)(__int64, __int64))(v14 + 168)) != nullptr )
  {
    return v15(a1, a2);
  }
  else
  {
    return 0;
  }
}


// ===== sub_28006534C @ 0x28006534c size=0x59 =====
char __fastcall sub_28006534C(__int64 a1, __int64 a2, struct _DEVICE_OBJECT *a3)
{
  _QWORD *DeviceExtension; // rax
  __int64 v5; // r8
  __int64 v6; // rcx
  __int64 (__fastcall *v7)(__int64); // rax

  DeviceExtension = a3->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a3 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v5 = DeviceExtension[2]) != 0
    && (v6 = *(_QWORD *)(*(_QWORD *)(v5 + 8) + 80LL)) != 0
    && *(_DWORD *)v6 >= 0xB8u
    && (v7 = *(__int64 (__fastcall **)(__int64))(v6 + 176)) != nullptr )
  {
    return v7(a1);
  }
  else
  {
    return 0;
  }
}


// ===== sub_2800653AC @ 0x2800653ac size=0x5d =====
char __fastcall sub_2800653AC(__int64 a1, __int64 a2, __int64 a3, struct _DEVICE_OBJECT *a4)
{
  _QWORD *DeviceExtension; // r9
  __int64 v7; // r9
  __int64 v8; // rcx
  __int64 (__fastcall *v9)(__int64); // rax

  DeviceExtension = a4->DeviceExtension;
  if ( DeviceExtension != nullptr
    && a4 != DeviceObject
    && *(_DWORD *)DeviceExtension == 7680401
    && (v7 = DeviceExtension[2]) != 0
    && (v8 = *(_QWORD *)(*(_QWORD *)(v7 + 8) + 80LL)) != 0
    && *(_DWORD *)v8 >= 0xC0u
    && (v9 = *(__int64 (__fastcall **)(__int64))(v8 + 184)) != nullptr )
  {
    return v9(a1);
  }
  else
  {
    return 0;
  }
}


// ===== sub_280065410 @ 0x280065410 size=0x75 =====
char __fastcall sub_280065410(__int64 a1, __int64 a2, struct _DEVICE_OBJECT *a3)
{
  _QWORD *DeviceExtension; // rax
  __int64 v5; // r8
  __int64 v6; // r9
  __int64 v7; // rbx
  char result; // al

  DeviceExtension = a3->DeviceExtension;
  if ( DeviceExtension == nullptr )
    return 0;
  if ( a3 == DeviceObject )
    return 0;
  if ( *(_DWORD *)DeviceExtension != 7680401 )
    return 0;
  v5 = DeviceExtension[2];
  if ( v5 == 0 )
    return 0;
  v6 = *(_QWORD *)(*(_QWORD *)(v5 + 8) + 80LL);
  if ( v6 == 0 || *(_DWORD *)v6 < 0xC8u || *(_QWORD *)(v6 + 192) == 0 )
    return 0;
  v7 = *(_QWORD *)(a1 + 184);
  *(_QWORD *)(v7 + 40) = v5;
  result = (*(__int64 (**)(void))(v6 + 192))();
  *(_QWORD *)(v7 + 40) = a3;
  return result;
}


// ===== sub_28006548C @ 0x28006548c size=0x47 =====
__int64 __fastcall sub_28006548C(struct _DEVICE_OBJECT *a1, struct _DEVICE_OBJECT *a2, struct _DEVICE_OBJECT **a3)
{
  bool v4; // cc
  PDEVICE_OBJECT v6; // rax

  v4 = MajorVersion <= 5;
  if ( MajorVersion == 5 )
  {
    if ( MinorVersion != 0 )
      return qword_280074B40();
    v4 = true;
  }
  if ( !v4 )
    return qword_280074B40();
  *a3 = a2;
  v6 = IoAttachDeviceToDeviceStack(a1, a2);
  *a3 = v6;
  return v6 == nullptr ? 0xC000000E : 0;
}


// ===== sub_2800654DC @ 0x2800654dc size=0x311 =====
__int64 __fastcall sub_2800654DC(__int64 a1, __int64 a2)
{
  __int64 v2; // rbp
  int v5; // esi
  __int64 v6; // rax
  __int64 v7; // r12
  __int64 v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rax
  NTSTATUS v17; // ebx
  char *DeviceExtension; // rbx
  char *v20; // rsi
  PDEVICE_OBJECT v21; // rax
  int v22; // esi
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-58h] BYREF
  UNICODE_STRING String2; // [rsp+50h] [rbp-48h] BYREF
  UNICODE_STRING v25; // [rsp+60h] [rbp-38h] BYREF
  PDEVICE_OBJECT DeviceObject; // [rsp+A0h] [rbp+8h] BYREF

  v2 = 8;
  if ( *(_DWORD *)(a1 + 72) != 8 )
    return 0;
  RtlInitUnicodeString(&DestinationString, L"\\FileSystem\\Fastfat");
  RtlInitUnicodeString(&String2, L"\\FileSystem\\Ntfs");
  RtlInitUnicodeString(&v25, L"\\FileSystem\\exFat");
  v5 = 0;
  v6 = sub_28006C5B4(*(PVOID *)(a1 + 8));
  v7 = v6;
  if ( v6 == 0 )
    return 0;
  if ( RtlCompareUnicodeString((PCUNICODE_STRING)(v6 + 8), &DestinationString, 1u) != 0 )
  {
    if ( RtlCompareUnicodeString((PCUNICODE_STRING)(v7 + 8), &String2, 1u) != 0 )
    {
      if ( RtlCompareUnicodeString((PCUNICODE_STRING)(v7 + 8), &v25, 1u) == 0 )
      {
        v14 = *(_QWORD *)(a1 + 8);
        v5 = 3;
        v15 = *(_QWORD *)(v14 + 24);
        qword_280074FA0 = v14;
        v16 = *(unsigned int *)(v14 + 32);
        qword_280074FF0 = v15;
        qword_280074FF8 = v15 + v16;
      }
    }
    else
    {
      v11 = *(_QWORD *)(a1 + 8);
      v5 = 2;
      v12 = *(_QWORD *)(v11 + 24);
      qword_280074F98 = v11;
      v13 = *(unsigned int *)(v11 + 32);
      qword_280074FE0 = v12;
      qword_280074FE8 = v12 + v13;
    }
  }
  else
  {
    v8 = *(_QWORD *)(a1 + 8);
    v5 = 1;
    v9 = *(_QWORD *)(v8 + 24);
    qword_280074F90 = v8;
    v10 = *(unsigned int *)(v8 + 32);
    qword_280074FD0 = v9;
    qword_280074FD8 = v9 + v10;
  }
  sub_28006C8A8((PSLIST_ENTRY)v7);
  if ( v5 == 0 )
    return 0;
  ExAcquireFastMutex(&stru_280075760);
  v17 = IoCreateDevice(DriverObject, 0x230u, nullptr, *(_DWORD *)(a1 + 72), 0, 0, &DeviceObject);
  ExReleaseFastMutex(&stru_280075760);
  if ( v17 < 0 )
    return (unsigned int)v17;
  if ( (*(_BYTE *)(a1 + 48) & 4) != 0 )
    DeviceObject->Flags |= 4u;
  if ( (*(_BYTE *)(a1 + 48) & 0x10) != 0 )
    DeviceObject->Flags |= 0x10u;
  if ( _bittest((const signed __int32 *)(a1 + 52), 8u) )
    DeviceObject->Characteristics |= 0x100u;
  DeviceExtension = (char *)DeviceObject->DeviceExtension;
  *((_DWORD *)DeviceExtension + 18) = -1;
  *((_DWORD *)DeviceExtension + 20) = v5;
  *(_DWORD *)DeviceExtension = 7680401;
  v20 = DeviceExtension + 104;
  *((_DWORD *)DeviceExtension + 19) = 1;
  do
  {
    *((_DWORD *)v20 - 4) = 1;
    *((_QWORD *)v20 - 1) = 0;
    *(_DWORD *)v20 = 0;
    KeInitializeEvent((PRKEVENT)(v20 + 8), SynchronizationEvent, 0);
    v20 += 56;
    --v2;
  }
  while ( v2 != 0 );
  *((_QWORD *)DeviceExtension + 67) = 0;
  v21 = DeviceObject;
  *((_QWORD *)DeviceExtension + 2) = 0;
  *((_QWORD *)DeviceExtension + 3) = 0;
  *((_QWORD *)DeviceExtension + 4) = 0;
  *((_QWORD *)DeviceExtension + 1) = v21;
  *((_WORD *)DeviceExtension + 28) = 0;
  *((_WORD *)DeviceExtension + 29) = 0;
  *((_QWORD *)DeviceExtension + 8) = 0;
  *((_WORD *)DeviceExtension + 20) = 0;
  *((_WORD *)DeviceExtension + 21) = 0;
  *((_QWORD *)DeviceExtension + 6) = 0;
  *((_QWORD *)DeviceExtension + 68) = 0;
  DeviceExtension[552] = 0;
  v22 = sub_28006C784((PUNICODE_STRING)(DeviceExtension + 56), (PCUNICODE_STRING)(a2 + 8));
  if ( v22 >= 0 )
  {
    v22 = sub_28006548C(DeviceObject, (struct _DEVICE_OBJECT *)a1, (struct _DEVICE_OBJECT **)DeviceExtension + 2);
    if ( v22 >= 0 )
    {
      DeviceObject->Flags &= ~0x80u;
      return 0;
    }
  }
  sub_2800657F4(DeviceObject);
  ExAcquireFastMutex(&stru_280075760);
  IoDeleteDevice(DeviceObject);
  ExReleaseFastMutex(&stru_280075760);
  return (unsigned int)v22;
}


// ===== sub_2800657F4 @ 0x2800657f4 size=0x55 =====
void __fastcall sub_2800657F4(__int64 a1)
{
  _QWORD *v1; // rbx
  void *v2; // rcx
  void *v3; // rcx
  __int64 v4; // rcx

  v1 = *(_QWORD **)(a1 + 64);
  v2 = (void *)v1[6];
  if ( v2 != nullptr )
  {
    ExFreePoolWithTag(v2, 0);
    v1[6] = 0;
  }
  v3 = (void *)v1[8];
  if ( v3 != nullptr )
  {
    ExFreePoolWithTag(v3, 0);
    v1[8] = 0;
  }
  v4 = v1[67];
  if ( v4 != 0 )
  {
    v1[67] = 0;
    sub_2800518D4(v4);
  }
}


// ===== sub_280065850 @ 0x280065850 size=0xea =====
char __fastcall sub_280065850(struct _DEVICE_OBJECT *Object, __int64 *a2)
{
  PDEVICE_OBJECT v3; // rbx
  char v4; // si
  bool v5; // cc
  __int64 v6; // rbp
  __int64 v7; // rbx
  bool i; // zf

  v3 = Object;
  v4 = 1;
  v5 = MajorVersion <= 5;
  if ( MajorVersion == 5 )
  {
    if ( MinorVersion != 0 )
      goto LABEL_5;
    v5 = true;
  }
  if ( !v5 )
  {
LABEL_5:
    v6 = qword_280074B60();
    do
    {
      if ( (PDEVICE_OBJECT)v6 != DeviceObject && **(_DWORD **)(v6 + 64) == 7680401 )
      {
        if ( a2 != nullptr )
          *a2 = v6;
        else
          ObfDereferenceObject((PVOID)v6);
        return v4;
      }
      v7 = qword_280074B48(v6);
      ObfDereferenceObject((PVOID)v6);
      v6 = v7;
    }
    while ( v7 != 0 );
    if ( a2 != nullptr )
      *a2 = 0;
    return 0;
  }
  for ( i = Object == nullptr; !i; i = v3 == nullptr )
  {
    if ( v3 != DeviceObject && *(_DWORD *)v3->DeviceExtension == 7680401 )
    {
      if ( a2 != nullptr )
      {
        ObfReferenceObject(v3);
        *a2 = (__int64)v3;
      }
      return v4;
    }
    v3 = v3->AttachedDevice;
  }
  if ( a2 != nullptr )
    *a2 = 0;
  return 0;
}


// ===== WorkerRoutine @ 0x280065940 size=0x187 =====
void __fastcall WorkerRoutine(PDEVICE_OBJECT DeviceObject, struct _IO_WORKITEM *Context)
{
  bool v2; // bl
  void *FileHandle; // [rsp+60h] [rbp-188h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+68h] [rbp-180h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+78h] [rbp-170h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+A8h] [rbp-140h] BYREF
  _DWORD FileInformation[68]; // [rsp+C0h] [rbp-128h] BYREF

  if ( Context != nullptr )
    IoFreeWorkItem(Context);
  memset(FileInformation, 0, 260);
  RtlInitUnicodeString(&DestinationString, L"\\SystemRoot");
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 64;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  if ( ZwCreateFile(
         &FileHandle,
         0x100080u,
         &ObjectAttributes,
         &IoStatusBlock,
         nullptr,
         0x80u,
         1u,
         1u,
         0x21u,
         nullptr,
         0) < 0
    || IoStatusBlock.Status < 0 )
  {
    v2 = false;
  }
  else
  {
    v2 = ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x104u, FileNameInformation) >= 0;
    ZwClose(FileHandle);
    if ( !v2 )
      goto LABEL_10;
    memmove(&unk_280074F10, &FileInformation[1], FileInformation[0]);
  }
  if ( v2 )
  {
    sub_28006E964();
    sub_280065AD0();
    sub_280065DD4();
    return;
  }
LABEL_10:
  dword_280074EEC = 0;
}


// ===== sub_280065AD0 @ 0x280065ad0 size=0x2fb =====
__int64 sub_280065AD0()
{
  WCHAR *PoolWithTagPriority; // rax
  WCHAR *v1; // r12
  __int64 v3; // rbp
  _DWORD *v4; // rax
  _DWORD *v5; // rbx
  _WORD *v6; // rax
  unsigned __int16 *v7; // rdx
  __int64 i; // r8
  unsigned __int16 v9; // cx
  struct _UNICODE_STRING Destination; // [rsp+60h] [rbp-98h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+70h] [rbp-88h] BYREF
  _BYTE FileInformation[8]; // [rsp+80h] [rbp-78h] BYREF
  ULONG Length; // [rsp+88h] [rbp-70h]
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+98h] [rbp-60h] BYREF
  void *FileHandle; // [rsp+100h] [rbp+8h] BYREF

  FileHandle = nullptr;
  PoolWithTagPriority = (WCHAR *)ExAllocatePoolWithTagPriority(PagedPool, 0x3E8u, 0x626E5450u, HighPoolPriority);
  v1 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  memset(PoolWithTagPriority, 0, 0x3E8u);
  Destination.Length = 0;
  Destination.MaximumLength = 1000;
  Destination.Buffer = v1;
  RtlAppendUnicodeToString(&Destination, L"\\SystemRoot\\diskpt.dat");
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &Destination;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  if ( ZwCreateFile(
         &FileHandle,
         0x100001u,
         &ObjectAttributes,
         &IoStatusBlock,
         nullptr,
         0x80u,
         1u,
         3u,
         0x28u,
         nullptr,
         0) >= 0
    && ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x18u, FileStandardInformation) >= 0 )
  {
    v3 = Length;
    if ( Length != 0 && Length == 1004 * (Length / 0x3ECuLL) )
    {
      v4 = ExAllocatePoolWithTagPriority(PagedPool, Length + 1004LL, 0x74665450u, HighPoolPriority);
      v5 = v4;
      if ( v4 != nullptr )
      {
        if ( ZwReadFile(FileHandle, nullptr, nullptr, nullptr, &IoStatusBlock, v4, v3, nullptr, nullptr) >= 0
          && IoStatusBlock.Information == v3 )
        {
          *(_DWORD *)((char *)v5 + v3) = -1;
          if ( *v5 != -1 )
          {
            v6 = (_WORD *)v5 + 501;
            do
            {
              v7 = v6 - 499;
              for ( i = 500; i != 0; --i )
              {
                v9 = *v7;
                if ( *v7 >= 0x61u && v9 <= 0x7Au )
                  *v7 = v9 - 32;
                ++v7;
              }
              *v6 = 0;
              v6 += 502;
            }
            while ( *(_DWORD *)(v6 - 501) != -1 );
          }
        }
        else
        {
          ExFreePoolWithTag(v5, 0x74665450u);
        }
      }
    }
  }
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&Resource, 1u);
  return sub_2800B7DE9();
}


// ===== sub_280065DD4 @ 0x280065dd4 size=0x1e4 =====
__int64 sub_280065DD4()
{
  WCHAR *PoolWithTagPriority; // rax
  WCHAR *v1; // rdi
  NTSTATUS v3; // ebx
  struct _UNICODE_STRING Destination; // [rsp+60h] [rbp-78h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+70h] [rbp-68h] BYREF
  _BYTE FileInformation[8]; // [rsp+80h] [rbp-58h] BYREF
  int v7; // [rsp+88h] [rbp-50h]
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+98h] [rbp-40h] BYREF
  void *FileHandle; // [rsp+E0h] [rbp+8h] BYREF

  FileHandle = nullptr;
  PoolWithTagPriority = (WCHAR *)ExAllocatePoolWithTagPriority(PagedPool, 0x3E8u, 0x626E5450u, HighPoolPriority);
  v1 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  memset(PoolWithTagPriority, 0, 0x3E8u);
  Destination.Length = 0;
  Destination.MaximumLength = 1000;
  Destination.Buffer = v1;
  RtlAppendUnicodeToString(&Destination, L"\\SystemRoot\\diskpt.crt");
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &Destination;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v3 = ZwCreateFile(
         &FileHandle,
         0x100001u,
         &ObjectAttributes,
         &IoStatusBlock,
         nullptr,
         0x80u,
         1u,
         3u,
         0x28u,
         nullptr,
         0);
  if ( v3 >= 0 )
  {
    v3 = ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x18u, FileStandardInformation);
    if ( v3 >= 0 )
    {
      if ( v7 != 0 )
        return sub_2800B7DE9();
      v3 = 0;
    }
  }
  if ( FileHandle != nullptr )
    ZwClose(FileHandle);
  ExFreePoolWithTag(v1, 0x626E5450u);
  return (unsigned int)v3;
}


// ===== sub_280065FC0 @ 0x280065fc0 size=0x126 =====
__int64 __fastcall sub_280065FC0(__int64 a1)
{
  __int64 v1; // rbx
  wchar_t *PoolWithTagPriority; // rax
  WCHAR *v3; // rdi
  NTSTATUS v5; // ebx
  struct _UNICODE_STRING DestinationString; // [rsp+60h] [rbp-58h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+70h] [rbp-48h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+80h] [rbp-38h] BYREF
  void *FileHandle; // [rsp+C0h] [rbp+8h] BYREF

  v1 = *(_QWORD *)(a1 + 64);
  PoolWithTagPriority = (wchar_t *)ExAllocatePoolWithTagPriority(PagedPool, 0x100u, 0x626E5450u, HighPoolPriority);
  v3 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  swprintf(PoolWithTagPriority, L"\\Device\\%s%x\\hiberfil.sys", aDpshadow, *(unsigned int *)(v1 + 72));
  RtlInitUnicodeString(&DestinationString, v3);
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  v5 = ZwCreateFile(&FileHandle, 0x100001u, &ObjectAttributes, &IoStatusBlock, nullptr, 6u, 3u, 3u, 0x60u, nullptr, 0);
  ExFreePoolWithTag(v3, 0x626E5450u);
  if ( v5 >= 0 )
    ZwClose(FileHandle);
  return (unsigned int)v5;
}


// ===== sub_2800660EC @ 0x2800660ec size=0x13c =====
__int64 __fastcall sub_2800660EC(__int64 a1)
{
  __int64 v1; // rbx
  wchar_t *PoolWithTagPriority; // rax
  WCHAR *v3; // rdi
  NTSTATUS v5; // ebx
  struct _UNICODE_STRING DestinationString; // [rsp+70h] [rbp-58h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+80h] [rbp-48h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+90h] [rbp-38h] BYREF
  void *FileHandle; // [rsp+D0h] [rbp+8h] BYREF

  v1 = *(_QWORD *)(a1 + 64);
  PoolWithTagPriority = (wchar_t *)ExAllocatePoolWithTagPriority(PagedPool, 0x100u, 0x626E5450u, HighPoolPriority);
  v3 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  swprintf(PoolWithTagPriority, L"\\Device\\%s%x\\hiberfil.sys", aDpshadow, *(unsigned int *)(v1 + 72));
  RtlInitUnicodeString(&DestinationString, v3);
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  v5 = IoCreateFile(
         &FileHandle,
         0x100001u,
         &ObjectAttributes,
         &IoStatusBlock,
         nullptr,
         6u,
         3u,
         3u,
         0x1060u,
         nullptr,
         0,
         CreateFileTypeNone,
         nullptr,
         0x102u);
  ExFreePoolWithTag(v3, 0x626E5450u);
  if ( v5 >= 0 )
    ZwClose(FileHandle);
  return (unsigned int)v5;
}


// ===== sub_280066230 @ 0x280066230 size=0x171 =====
__int64 __fastcall sub_280066230(__int64 a1, void *a2)
{
  __int64 v2; // rbx
  wchar_t *PoolWithTagPriority; // rax
  WCHAR *v5; // rdi
  NTSTATUS v7; // ebx
  struct _UNICODE_STRING DestinationString; // [rsp+70h] [rbp-58h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+80h] [rbp-48h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+90h] [rbp-38h] BYREF
  void *FileHandle; // [rsp+D0h] [rbp+8h] BYREF

  v2 = *(_QWORD *)(a1 + 64);
  PoolWithTagPriority = (wchar_t *)ExAllocatePoolWithTagPriority(PagedPool, 0x100u, 0x626E5450u, HighPoolPriority);
  v5 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  swprintf(PoolWithTagPriority, L"\\Device\\%s%x\\hiberfil.sys", aDpshadow, *(unsigned int *)(v2 + 72));
  RtlInitUnicodeString(&DestinationString, v5);
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  v7 = IoCreateFile(
         &FileHandle,
         0x100003u,
         &ObjectAttributes,
         &IoStatusBlock,
         nullptr,
         6u,
         3u,
         3u,
         0x60u,
         nullptr,
         0,
         CreateFileTypeNone,
         nullptr,
         0x102u);
  ExFreePoolWithTag(v5, 0x626E5450u);
  if ( v7 >= 0 )
  {
    v7 = ZwSetInformationFile(FileHandle, &IoStatusBlock, a2, 8u, FileEndOfFileInformation);
    ZwClose(FileHandle);
  }
  return (unsigned int)v7;
}


// ===== sub_2800663A8 @ 0x2800663a8 size=0x1ae =====
__int64 __fastcall sub_2800663A8(__int64 a1, void *a2, ULONG a3, void *a4, ULONG OutputBufferLength, ULONG_PTR *a6)
{
  __int64 v6; // rbx
  wchar_t *PoolWithTagPriority; // rax
  WCHAR *v11; // rdi
  NTSTATUS v13; // ebx
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+70h] [rbp-68h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+80h] [rbp-58h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+90h] [rbp-48h] BYREF
  void *FileHandle; // [rsp+E0h] [rbp+8h] BYREF

  v6 = *(_QWORD *)(a1 + 64);
  PoolWithTagPriority = (wchar_t *)ExAllocatePoolWithTagPriority(PagedPool, 0x100u, 0x626E5450u, HighPoolPriority);
  v11 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  swprintf(PoolWithTagPriority, L"\\Device\\%s%x\\hiberfil.sys", aDpshadow, *(unsigned int *)(v6 + 72));
  RtlInitUnicodeString(&DestinationString, v11);
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  v13 = IoCreateFile(
          &FileHandle,
          0x100001u,
          &ObjectAttributes,
          &IoStatusBlock,
          nullptr,
          6u,
          3u,
          3u,
          0x60u,
          nullptr,
          0,
          CreateFileTypeNone,
          nullptr,
          0x102u);
  ExFreePoolWithTag(v11, 0x626E5450u);
  if ( v13 >= 0 )
  {
    v13 = ZwFsControlFile(
            FileHandle,
            nullptr,
            nullptr,
            nullptr,
            &IoStatusBlock,
            0x9003Bu,
            a2,
            a3,
            a4,
            OutputBufferLength);
    if ( v13 >= 0 )
      *a6 = IoStatusBlock.Information;
    ZwClose(FileHandle);
  }
  return (unsigned int)v13;
}


// ===== sub_28006655C @ 0x28006655c size=0x2d2 =====
__int64 __fastcall sub_28006655C(__int64 a1)
{
  __int64 v1; // rbx
  PVOID PoolWithTagPriority; // rax
  void *v3; // rsi
  wchar_t *v5; // rax
  WCHAR *v6; // rdi
  NTSTATUS Status; // ebx
  void *v8; // rcx
  struct _MDL *Mdl; // rax
  struct _MDL *v10; // rdi
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+70h] [rbp-A8h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+80h] [rbp-98h] BYREF
  struct _KEVENT Event; // [rsp+B0h] [rbp-68h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+C8h] [rbp-50h] BYREF
  _BYTE FileInformation[8]; // [rsp+D8h] [rbp-40h] BYREF
  __int64 v16; // [rsp+E0h] [rbp-38h]
  void *FileHandle; // [rsp+120h] [rbp+8h] BYREF
  PVOID Object; // [rsp+128h] [rbp+10h] BYREF
  union _LARGE_INTEGER StartingOffset; // [rsp+130h] [rbp+18h] BYREF

  v1 = *(_QWORD *)(a1 + 64);
  PoolWithTagPriority = ExAllocatePoolWithTagPriority(NonPagedPool, 0x1000u, 0x74665450u, HighPoolPriority);
  v3 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  memset(PoolWithTagPriority, 0, 0x1000u);
  v5 = (wchar_t *)ExAllocatePoolWithTagPriority(PagedPool, 0x100u, 0x626E5450u, HighPoolPriority);
  v6 = v5;
  if ( v5 == nullptr )
    goto LABEL_10;
  swprintf(v5, L"\\Device\\%s%x\\pagefile.sys", aDpshadow, *(unsigned int *)(v1 + 72));
  RtlInitUnicodeString(&DestinationString, v6);
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  Status = IoCreateFile(
             &FileHandle,
             0x100002u,
             &ObjectAttributes,
             &IoStatusBlock,
             nullptr,
             6u,
             3u,
             1u,
             0x60u,
             nullptr,
             0,
             CreateFileTypeNone,
             nullptr,
             0x102u);
  ExFreePoolWithTag(v6, 0x626E5450u);
  if ( Status >= 0 )
  {
    Status = ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x18u, FileStandardInformation);
    if ( Status >= 0 )
    {
      v8 = FileHandle;
      if ( v16 < 4096 )
      {
LABEL_15:
        ZwClose(v8);
        goto LABEL_16;
      }
      Status = ObReferenceObjectByHandle(FileHandle, 0, (POBJECT_TYPE)IoFileObjectType, 0, &Object, nullptr);
      if ( Status >= 0 )
      {
        StartingOffset.QuadPart = 0;
        Mdl = IoAllocateMdl(v3, 0x200u, 0, 0, nullptr);
        v10 = Mdl;
        if ( Mdl == nullptr )
        {
          ObfDereferenceObject(Object);
          ZwClose(FileHandle);
LABEL_10:
          Status = -1073741670;
          goto LABEL_16;
        }
        MmBuildMdlForNonPagedPool(Mdl);
        KeInitializeEvent(&Event, NotificationEvent, 0);
        Status = IoSynchronousPageWrite((PFILE_OBJECT)Object, v10, &StartingOffset, &Event, &IoStatusBlock);
        if ( Status == 259 )
        {
          KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
          Status = IoStatusBlock.Status;
        }
        IoFreeMdl(v10);
        ObfDereferenceObject(Object);
      }
    }
    v8 = FileHandle;
    goto LABEL_15;
  }
LABEL_16:
  ExFreePoolWithTag(v3, 0x74665450u);
  return (unsigned int)Status;
}


// ===== sub_280066834 @ 0x280066834 size=0x107 =====
__int64 __fastcall sub_280066834(
        PDEVICE_OBJECT DeviceObject,
        struct _FILE_OBJECT *a2,
        struct _NAMED_PIPE_CREATE_PARAMETERS *a3,
        void *a4,
        _QWORD *a5,
        PIRP Irp)
{
  struct _KTHREAD *CurrentThread; // rax
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  struct _IO_STACK_LOCATION *v9; // r11
  unsigned int v10; // r11d
  unsigned int v12; // [rsp+30h] [rbp-38h] BYREF
  __int64 v13; // [rsp+38h] [rbp-30h]
  struct _KEVENT Object; // [rsp+40h] [rbp-28h] BYREF

  v12 = 0;
  v13 = 0;
  Irp->AssociatedIrp.MasterIrp = nullptr;
  CurrentThread = KeGetCurrentThread();
  Irp->UserEvent = nullptr;
  Irp->Tail.Overlay.Thread = CurrentThread;
  Irp->Tail.Overlay.OriginalFileObject = a2;
  Irp->RequestorMode = 0;
  Irp->Flags = 4;
  Irp->UserBuffer = a4;
  Irp->UserIosb = (PIO_STATUS_BLOCK)&v12;
  CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
  CurrentStackLocation[-1].DeviceObject = DeviceObject;
  CurrentStackLocation[-1].FileObject = a2;
  CurrentStackLocation[-1].Parameters.Create.Options = 8;
  CurrentStackLocation[-1].Parameters.Read.Length = 8;
  CurrentStackLocation[-1].Parameters.CreatePipe.Parameters = a3;
  CurrentStackLocation[-1].MajorFunction = 13;
  CurrentStackLocation[-1].MinorFunction = 0;
  CurrentStackLocation[-1].Parameters.Read.ByteOffset.LowPart = 589883;
  KeInitializeEvent(&Object, NotificationEvent, 0);
  v9 = Irp->Tail.Overlay.CurrentStackLocation;
  v9[-1].CompletionRoutine = (PIO_COMPLETION_ROUTINE)&sub_28006C574;
  v9[-1].Control = -32;
  v9[-1].Context = &Object;
  v10 = IofCallDriver(DeviceObject, Irp);
  if ( v10 == 259 )
  {
    KeWaitForSingleObject(&Object, Executive, 0, 0, nullptr);
    v10 = v12;
  }
  *a5 = v13;
  return v10;
}


// ===== sub_280066944 @ 0x280066944 size=0x1df =====
__int64 __fastcall sub_280066944(_QWORD *InputBuffer, PVOID OutputBuffer, ULONG_PTR *a3, __int64 a4, WCHAR *FileHandle)
{
  WCHAR *v5; // rbx
  NTSTATUS v9; // edi
  NTSTATUS v11; // eax
  WCHAR *v12; // rcx
  NTSTATUS v13; // ebx
  struct _UNICODE_STRING Destination; // [rsp+70h] [rbp-88h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+80h] [rbp-78h] BYREF
  _BYTE FileInformation[8]; // [rsp+90h] [rbp-68h] BYREF
  __int64 v17; // [rsp+98h] [rbp-60h]
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+A8h] [rbp-50h] BYREF

  v5 = FileHandle;
  Destination.Length = 0;
  Destination.MaximumLength = 256;
  Destination.Buffer = FileHandle;
  RtlAppendUnicodeStringToString(&Destination, (PCUNICODE_STRING)(a4 + 56));
  RtlAppendUnicodeToString(&Destination, L"\\pagefile.sys");
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &Destination;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v9 = IoCreateFile(
         (PHANDLE)&FileHandle,
         0x100001u,
         &ObjectAttributes,
         &IoStatusBlock,
         nullptr,
         6u,
         3u,
         1u,
         0x60u,
         nullptr,
         0,
         CreateFileTypeNone,
         nullptr,
         0x102u);
  ExFreePoolWithTag(v5, 0x626E5450u);
  if ( v9 < 0 )
    return (unsigned int)v9;
  v11 = ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x18u, FileStandardInformation);
  v12 = FileHandle;
  v13 = v11;
  if ( v11 >= 0 )
  {
    *InputBuffer = v17;
    v13 = ZwFsControlFile(v12, nullptr, nullptr, nullptr, &IoStatusBlock, 0x9003Bu, InputBuffer, 8u, OutputBuffer, 8u);
    if ( v13 >= 0 )
      *a3 = IoStatusBlock.Information;
    v12 = FileHandle;
  }
  ZwClose(v12);
  return (unsigned int)v13;
}


// ===== sub_280066B2C @ 0x280066b2c size=0x10b =====
bool __fastcall sub_280066B2C(_WORD *a1, unsigned __int16 *a2)
{
  char v2; // bl
  unsigned __int16 *v3; // rsi
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // ax

  v2 = 0;
  v3 = a2;
  if ( a2 != nullptr )
  {
    while ( 1 )
    {
      if ( a1 == nullptr )
        return false;
      if ( *a1 == 0 )
        return *v3 == 0;
      v5 = *v3;
      if ( *v3 == 0 )
      {
        while ( *a1 != 0 )
        {
          if ( *a1 != 42 )
            return v2;
          ++a1;
        }
        return true;
      }
      if ( *a1 == 42 )
        break;
      do
      {
        if ( *a1 == 42 )
          break;
        if ( v5 >= 0x61u && v5 <= 0x7Au )
          v5 -= 32;
        if ( *a1 != v5 && *a1 != 63 )
          return false;
        ++v3;
        ++a1;
        v5 = *v3;
      }
      while ( *v3 != 0 );
      if ( *v3 == 0 )
      {
        while ( *a1 != 0 )
        {
          if ( *a1 != 42 )
            return v2;
          ++a1;
        }
        return true;
      }
    }
    do
      ++a1;
    while ( *a1 == 42 );
    if ( *a1 == 0 )
      return true;
    while ( 1 )
    {
      v6 = *v3;
      if ( *v3 == 0 )
        break;
      if ( v6 >= 0x61u && v6 <= 0x7Au )
        v6 -= 32;
      if ( (*a1 == v6 || *a1 == 63) && (unsigned __int8)sub_280066B2C(a1 + 1, v3 + 1) != 0 )
        return true;
      ++v3;
    }
  }
  return false;
}


// ===== sub_280066C40 @ 0x280066c40 size=0x18c =====
__int64 __fastcall sub_280066C40(__int64 a1, __int64 a2, _DWORD *a3)
{
  SIZE_T v5; // r12
  PVOID PoolWithTagPriority; // rax
  void *v7; // rsi
  unsigned __int64 v9; // r11

  v5 = (unsigned int)*(unsigned __int16 *)(a1 + 8) + 2;
  PoolWithTagPriority = ExAllocatePoolWithTagPriority(PagedPool, v5, 0x626E5450u, HighPoolPriority);
  v7 = PoolWithTagPriority;
  if ( PoolWithTagPriority != nullptr )
  {
    memset(PoolWithTagPriority, 0, v5);
    memmove(v7, *(const void **)(a1 + 16), *(unsigned __int16 *)(a1 + 8));
    v9 = (unsigned __int64)*(unsigned __int16 *)(a1 + 8) >> 1;
    if ( *((_WORD *)v7 + v9 - 1) == 92 )
      *((_WORD *)v7 + v9 - 1) = 0;
    KeEnterCriticalRegion();
    ExAcquireResourceSharedLite(&Resource, 1u);
    *a3 = dword_2800742E4;
    return sub_2800B7DE9();
  }
  else
  {
    *a3 = dword_2800742E4;
    return 0;
  }
}


// ===== sub_280066DD4 @ 0x280066dd4 size=0x156 =====
NTSTATUS __fastcall sub_280066DD4(_QWORD *Object)
{
  __int64 v1; // rsi
  PSLIST_ENTRY v3; // rbx
  __int64 v5; // rcx
  struct _KEVENT Event; // [rsp+30h] [rbp-28h] BYREF

  v1 = Object[8];
  ++dword_280074894;
  v3 = ExpInterlockedPopEntrySList(&stru_280074880);
  if ( v3 == nullptr )
  {
    ++dword_280074898;
    v3 = (PSLIST_ENTRY)qword_2800748B0(
                         (unsigned int)dword_2800748A4,
                         (unsigned int)dword_2800748AC,
                         (unsigned int)dword_2800748A8);
    if ( v3 == nullptr )
      return -1073741670;
  }
  KeInitializeEvent(&Event, NotificationEvent, 0);
  *((_QWORD *)&v3[4].Next + 1) = 0;
  *((_DWORD *)&v3[3].Next + 3) = 0;
  *((_QWORD *)&v3[1].Next + 1) = v3;
  LODWORD(v3[2].Next) = 0x10000;
  *((_QWORD *)&v3[2].Next + 1) = Object;
  v3[1].Next = (struct _SLIST_ENTRY *)sub_280066F30;
  v3[4].Next = (struct _SLIST_ENTRY *)&Event;
  ObfReferenceObject(Object);
  _InterlockedAdd(&dword_280075124, 1u);
  v5 = *(_QWORD *)(v1 + 536);
  if ( v5 != 0 )
  {
    sub_28005192C(v5, (struct _LIST_ENTRY *)v3);
    return KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
  }
  else
  {
    if ( _InterlockedAdd(&dword_280075124, 0xFFFFFFFF) == 0 )
      KeSetEvent(&::Event, 0, 0);
    ObfDereferenceObject(*((PVOID *)&v3[2].Next + 1));
    ++dword_28007489C;
    if ( ExQueryDepthSList(&stru_280074880) < (unsigned __int16)word_280074890 )
    {
      ExpInterlockedPushEntrySList(&stru_280074880, v3);
    }
    else
    {
      ++dword_2800748A0;
      qword_2800748B8(v3);
    }
    return -1073741811;
  }
}


// ===== sub_280066F30 @ 0x280066f30 size=0x325 =====
PSLIST_ENTRY __fastcall sub_280066F30(PSLIST_ENTRY ListEntry)
{
  __int64 v2; // rbp
  struct _SLIST_ENTRY *Next; // rdi
  int v4; // eax
  struct _SLIST_ENTRY *v5; // rbx
  void *v6; // rdi
  struct _SLIST_ENTRY *v7; // rcx
  struct _SLIST_ENTRY *v8; // r12
  void *v9; // r14
  int v10; // edi
  int v11; // eax
  wchar_t *PoolWithTagPriority; // rax
  wchar_t *v13; // rbx
  unsigned __int64 v14; // rdi
  int v15; // eax
  PSLIST_ENTRY v16; // r13
  __int64 v17; // rcx
  wchar_t *v18; // rdi
  bool v19; // zf
  int v20; // eax
  void *v21; // rbx
  struct _UNICODE_STRING DestinationString; // [rsp+30h] [rbp-38h] BYREF
  PSLIST_ENTRY ListEntrya; // [rsp+70h] [rbp+8h] BYREF

  v2 = *(_QWORD *)(*((_QWORD *)&ListEntry[2].Next + 1) + 64LL);
  if ( LODWORD(ListEntry[2].Next) != 1 )
  {
    if ( LODWORD(ListEntry[2].Next) == 2 )
    {
      Next = ListEntry[4].Next;
      v4 = sub_2800699C0(*(_QWORD *)(*((_QWORD *)&ListEntry[2].Next + 1) + 64LL), Next);
    }
    else
    {
      if ( LODWORD(ListEntry[2].Next) == 3 )
      {
        v8 = ListEntry[4].Next;
        v9 = *((void **)&ListEntry[4].Next + 1);
        v10 = (int)ListEntry[5].Next;
        v11 = sub_280068CE8(
                *(_QWORD *)(*((_QWORD *)&ListEntry[2].Next + 1) + 64LL),
                &v8->Next + 1,
                v9,
                *((unsigned int *)&ListEntry[3].Next + 2),
                v10);
        *((_DWORD *)&ListEntry[3].Next + 3) = v11;
        if ( v11 < 0 && v10 == 13 )
        {
          if ( v11 == -1073741567 )
            *((_DWORD *)&ListEntry[3].Next + 3) = sub_28006A918(v2, v8);
          if ( *((int *)&ListEntry[3].Next + 3) < 0 )
          {
            PoolWithTagPriority = (wchar_t *)ExAllocatePoolWithTagPriority(
                                               PagedPool,
                                               0x9Eu,
                                               0x626E5450u,
                                               HighPoolPriority);
            v13 = PoolWithTagPriority;
            if ( PoolWithTagPriority != nullptr )
            {
              v14 = MEMORY[0xFFFFF78000000014];
              memset(PoolWithTagPriority, 0, 0x9Eu);
              swprintf(v13, L"X:\\{0D9DB60E-B0EA-4d53-A392-A5D274956846}\\%08x%08x", HIDWORD(v14), (unsigned int)v14);
              *v13 = **(_WORD **)(v2 + 48);
              v15 = sub_28006C80C(&ListEntrya, &Lookaside);
              *((_DWORD *)&ListEntry[3].Next + 3) = v15;
              if ( v15 >= 0 )
              {
                v16 = ListEntrya;
                v17 = -1;
                v18 = v13;
                do
                {
                  if ( v17 == 0 )
                    break;
                  v19 = *v18++ == 0;
                  --v17;
                }
                while ( !v19 );
                v20 = sub_28006C92C(ListEntrya, (unsigned int)(2 * ~(_DWORD)v17 - 2));
                *((_DWORD *)&ListEntry[3].Next + 3) = v20;
                if ( v20 >= 0 )
                {
                  RtlInitUnicodeString(&DestinationString, v13);
                  RtlCopyUnicodeString((PUNICODE_STRING)(&v16->Next + 1), &DestinationString);
                  swprintf(
                    v13,
                    L"\\??\\%s%x\\{0D9DB60E-B0EA-4d53-A392-A5D274956846}\\",
                    aDpshadow,
                    *(unsigned int *)(v2 + 72));
                  sub_28006AD18(v13);
                  *((_DWORD *)&ListEntry[3].Next + 3) = sub_280069110(v2, &v8->Next + 1, &v16->Next + 1);
                }
                sub_28006C8A8(v16);
              }
              ExFreePoolWithTag(v13, 0x626E5450u);
            }
          }
        }
        ExFreePoolWithTag(v9, 0x74735450u);
        v7 = v8;
        goto LABEL_32;
      }
      if ( LODWORD(ListEntry[2].Next) == 4 )
      {
        v5 = ListEntry[4].Next;
        v6 = *((void **)&ListEntry[4].Next + 1);
        *((_DWORD *)&ListEntry[3].Next + 3) = sub_28006AA20(
                                                *(_QWORD *)(*((_QWORD *)&ListEntry[2].Next + 1) + 64LL),
                                                v5,
                                                v6,
                                                *((unsigned int *)&ListEntry[3].Next + 2),
                                                ListEntry[5].Next);
        ExFreePoolWithTag(v6, 0x74635450u);
        v7 = v5;
LABEL_32:
        sub_28006C8A8(v7);
        goto LABEL_33;
      }
      if ( LODWORD(ListEntry[2].Next) != 5 )
      {
        if ( LODWORD(ListEntry[2].Next) == 0x10000 )
          KeSetEvent((PRKEVENT)ListEntry[4].Next, 0, 0);
        goto LABEL_33;
      }
      Next = ListEntry[4].Next;
      v4 = sub_280069D4C(*(_QWORD *)(*((_QWORD *)&ListEntry[2].Next + 1) + 64LL), Next);
    }
    *((_DWORD *)&ListEntry[3].Next + 3) = v4;
LABEL_31:
    v7 = Next;
    goto LABEL_32;
  }
  Next = ListEntry[4].Next;
  v21 = *((void **)&ListEntry[4].Next + 1);
  if ( *((int *)&ListEntry[3].Next + 3) >= 0 && *((_DWORD *)&ListEntry[3].Next + 2) != 0 )
    *((_DWORD *)&ListEntry[3].Next + 3) = sub_28006951C(
                                            *(_QWORD *)(*((_QWORD *)&ListEntry[2].Next + 1) + 64LL),
                                            ListEntry[4].Next,
                                            *((_QWORD *)&ListEntry[4].Next + 1));
  ExFreePoolWithTag(v21, 0x72775450u);
  if ( Next != nullptr )
    goto LABEL_31;
LABEL_33:
  if ( _InterlockedAdd(&dword_280075124, 0xFFFFFFFF) == 0 )
    KeSetEvent(&Event, 0, 0);
  ObfDereferenceObject(*((PVOID *)&ListEntry[2].Next + 1));
  ++dword_28007489C;
  if ( ExQueryDepthSList(&stru_280074880) < (unsigned __int16)word_280074890 )
    return ExpInterlockedPushEntrySList(&stru_280074880, ListEntry);
  ++dword_2800748A0;
  return (PSLIST_ENTRY)qword_2800748B8(ListEntry);
}


// ===== sub_28006725C @ 0x28006725c size=0xee =====
__int64 __fastcall sub_28006725C(__int64 a1, volatile signed __int32 *a2)
{
  __int64 v2; // r12
  int v5; // ebx
  PSLIST_ENTRY v6; // rdi

  v2 = *(_QWORD *)(a1 + 64);
  v5 = 0;
  while ( 1 )
  {
    ++dword_280074894;
    v6 = ExpInterlockedPopEntrySList(&stru_280074880);
    if ( v6 != nullptr )
      break;
    ++dword_280074898;
    v6 = (PSLIST_ENTRY)qword_2800748B0(
                         (unsigned int)dword_2800748A4,
                         (unsigned int)dword_2800748AC,
                         (unsigned int)dword_2800748A8);
    if ( v6 != nullptr )
      break;
    if ( (unsigned int)++v5 >= 0xA )
      return 3221225626LL;
    KeDelayExecutionThread(0, 0, &Interval);
  }
  *((_DWORD *)&v6[3].Next + 3) = 0;
  *((_QWORD *)&v6[1].Next + 1) = v6;
  v6[1].Next = (struct _SLIST_ENTRY *)sub_280066F30;
  LODWORD(v6[2].Next) = 2;
  *((_QWORD *)&v6[2].Next + 1) = a1;
  v6[4].Next = (struct _SLIST_ENTRY *)a2;
  _InterlockedAdd(a2, 1u);
  ObfReferenceObject(*((PVOID *)&v6[2].Next + 1));
  _InterlockedAdd(&dword_280075124, 1u);
  sub_28005192C(*(_QWORD *)(v2 + 536), (struct _LIST_ENTRY *)v6);
  return 0;
}


// ===== sub_280067350 @ 0x280067350 size=0x10a =====
__int64 __fastcall sub_280067350(__int64 a1, volatile signed __int32 *a2, __int64 a3, int a4, int a5)
{
  __int64 v5; // r14
  int v10; // edi
  PSLIST_ENTRY v11; // rbx

  v5 = *(_QWORD *)(a1 + 64);
  v10 = 0;
  while ( 1 )
  {
    ++dword_280074894;
    v11 = ExpInterlockedPopEntrySList(&stru_280074880);
    if ( v11 != nullptr )
      break;
    ++dword_280074898;
    v11 = (PSLIST_ENTRY)qword_2800748B0(
                          (unsigned int)dword_2800748A4,
                          (unsigned int)dword_2800748AC,
                          (unsigned int)dword_2800748A8);
    if ( v11 != nullptr )
      break;
    if ( (unsigned int)++v10 >= 0xA )
      return 3221225626LL;
    KeDelayExecutionThread(0, 0, &Interval);
  }
  *((_DWORD *)&v11[3].Next + 3) = 0;
  *((_QWORD *)&v11[1].Next + 1) = v11;
  v11[1].Next = (struct _SLIST_ENTRY *)sub_280066F30;
  LODWORD(v11[2].Next) = 3;
  *((_QWORD *)&v11[2].Next + 1) = a1;
  v11[4].Next = (struct _SLIST_ENTRY *)a2;
  *((_QWORD *)&v11[4].Next + 1) = a3;
  LODWORD(v11[5].Next) = a5;
  *((_DWORD *)&v11[3].Next + 2) = a4;
  _InterlockedAdd(a2, 1u);
  ObfReferenceObject(*((PVOID *)&v11[2].Next + 1));
  _InterlockedAdd(&dword_280075124, 1u);
  sub_28005192C(*(_QWORD *)(v5 + 536), (struct _LIST_ENTRY *)v11);
  return 0;
}


// ===== sub_280067460 @ 0x280067460 size=0xfb =====
__int64 __fastcall sub_280067460(__int64 a1, volatile signed __int32 *a2)
{
  __int64 v2; // r12
  int v5; // edi
  PSLIST_ENTRY v6; // rbx

  v2 = *(_QWORD *)(a1 + 64);
  v5 = 0;
  while ( 1 )
  {
    ++dword_280074894;
    v6 = ExpInterlockedPopEntrySList(&stru_280074880);
    if ( v6 != nullptr )
      break;
    ++dword_280074898;
    v6 = (PSLIST_ENTRY)qword_2800748B0(
                         (unsigned int)dword_2800748A4,
                         (unsigned int)dword_2800748AC,
                         (unsigned int)dword_2800748A8);
    if ( v6 != nullptr )
      break;
    if ( (unsigned int)++v5 >= 0xA )
      return 3221225626LL;
    KeDelayExecutionThread(0, 0, &Interval);
  }
  *((_QWORD *)&v6[4].Next + 1) = 0;
  LODWORD(v6[5].Next) = 0;
  *((_DWORD *)&v6[3].Next + 2) = 0;
  *((_DWORD *)&v6[3].Next + 3) = 0;
  *((_QWORD *)&v6[1].Next + 1) = v6;
  v6[1].Next = (struct _SLIST_ENTRY *)sub_280066F30;
  LODWORD(v6[2].Next) = 5;
  *((_QWORD *)&v6[2].Next + 1) = a1;
  v6[4].Next = (struct _SLIST_ENTRY *)a2;
  _InterlockedAdd(a2, 1u);
  ObfReferenceObject(*((PVOID *)&v6[2].Next + 1));
  _InterlockedAdd(&dword_280075124, 1u);
  sub_28005192C(*(_QWORD *)(v2 + 536), (struct _LIST_ENTRY *)v6);
  return 0;
}


// ===== sub_280067564 @ 0x280067564 size=0x14f =====
__int64 __fastcall sub_280067564(__int64 a1, volatile signed __int32 *a2, const void *a3, unsigned int a4, int a5)
{
  __int64 v5; // r14
  size_t v6; // r12
  PVOID PoolWithTagPriority; // rax
  void *v11; // rsi
  int v13; // edi
  PSLIST_ENTRY v14; // rbx

  v5 = *(_QWORD *)(a1 + 64);
  v6 = a4;
  PoolWithTagPriority = ExAllocatePoolWithTagPriority(PagedPool, a4, 0x74635450u, HighPoolPriority);
  v11 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  memmove(PoolWithTagPriority, a3, v6);
  v13 = 0;
  while ( 1 )
  {
    ++dword_280074894;
    v14 = ExpInterlockedPopEntrySList(&stru_280074880);
    if ( v14 != nullptr )
      break;
    ++dword_280074898;
    v14 = (PSLIST_ENTRY)qword_2800748B0(
                          (unsigned int)dword_2800748A4,
                          (unsigned int)dword_2800748AC,
                          (unsigned int)dword_2800748A8);
    if ( v14 != nullptr )
      break;
    if ( (unsigned int)++v13 >= 0xA )
    {
      ExFreePoolWithTag(v11, 0x74635450u);
      return 3221225626LL;
    }
    KeDelayExecutionThread(0, 0, &Interval);
  }
  *((_DWORD *)&v14[3].Next + 3) = 0;
  *((_QWORD *)&v14[1].Next + 1) = v14;
  v14[1].Next = (struct _SLIST_ENTRY *)sub_280066F30;
  LODWORD(v14[2].Next) = 4;
  *((_QWORD *)&v14[2].Next + 1) = a1;
  v14[4].Next = (struct _SLIST_ENTRY *)a2;
  *((_QWORD *)&v14[4].Next + 1) = v11;
  LODWORD(v14[5].Next) = a5;
  *((_DWORD *)&v14[3].Next + 2) = v6;
  _InterlockedAdd(a2, 1u);
  ObfReferenceObject(*((PVOID *)&v14[2].Next + 1));
  _InterlockedAdd(&dword_280075124, 1u);
  sub_28005192C(*(_QWORD *)(v5 + 536), (struct _LIST_ENTRY *)v14);
  return 0;
}


// ===== sub_2800676BC @ 0x2800676bc size=0x79a =====
__int64 __fastcall sub_2800676BC(__int64 a1, __int64 a2)
{
  WCHAR *PoolWithTagPriority; // rax
  WCHAR *v5; // rsi
  USHORT v7; // ax
  NTSTATUS v8; // ebx
  NTSTATUS v9; // eax
  void *v10; // rcx
  __int64 v11; // rcx
  WCHAR *v12; // rdi
  bool v13; // zf
  NTSTATUS v14; // eax
  NTSTATUS v15; // edi
  int v16; // edi
  NTSTATUS v17; // eax
  union _LARGE_INTEGER v18; // rax
  union _LARGE_INTEGER v19; // rdi
  ULONG_PTR v20; // rax
  ULONG_PTR ViewSize; // [rsp+60h] [rbp-158h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+68h] [rbp-150h] BYREF
  union _LARGE_INTEGER SectionOffset; // [rsp+78h] [rbp-140h] BYREF
  struct _UNICODE_STRING Destination; // [rsp+80h] [rbp-138h] BYREF
  PVOID BaseAddress; // [rsp+90h] [rbp-128h] BYREF
  _BYTE v26[8]; // [rsp+98h] [rbp-120h] BYREF
  union _LARGE_INTEGER MaximumSize; // [rsp+A0h] [rbp-118h] BYREF
  char v28; // [rsp+ACh] [rbp-10Ch]
  char v29; // [rsp+ADh] [rbp-10Bh]
  void *SectionHandle; // [rsp+B0h] [rbp-108h] BYREF
  struct _OBJECT_ATTRIBUTES v31; // [rsp+B8h] [rbp-100h] BYREF
  _BYTE FileInformation[16]; // [rsp+E8h] [rbp-D0h] BYREF
  __int64 v33; // [rsp+F8h] [rbp-C0h]
  int v34; // [rsp+108h] [rbp-B0h]
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+110h] [rbp-A8h] BYREF
  _BYTE v36[8]; // [rsp+140h] [rbp-78h] BYREF
  __int64 v37; // [rsp+148h] [rbp-70h]
  _BYTE v38[16]; // [rsp+158h] [rbp-60h] BYREF
  __int64 v39; // [rsp+168h] [rbp-50h]
  union _LARGE_INTEGER v40; // [rsp+1C8h] [rbp+10h] BYREF
  HANDLE Handle; // [rsp+1D0h] [rbp+18h] BYREF
  void *FileHandle; // [rsp+1D8h] [rbp+20h] BYREF

  PoolWithTagPriority = (WCHAR *)ExAllocatePoolWithTagPriority(
                                   PagedPool,
                                   *(unsigned __int16 *)(a2 + 8) + 46LL,
                                   0x626E5450u,
                                   HighPoolPriority);
  v5 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  memset(PoolWithTagPriority, 0, *(unsigned __int16 *)(a2 + 8) + 46LL);
  v7 = *(_WORD *)(a2 + 8) + 46;
  Destination.Length = 0;
  Destination.MaximumLength = v7;
  Destination.Buffer = v5;
  RtlAppendUnicodeToString(&Destination, L"\\??\\");
  RtlAppendUnicodeStringToString(&Destination, (PCUNICODE_STRING)(a2 + 8));
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 512;
  ObjectAttributes.ObjectName = &Destination;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  if ( ZwCreateFile(
         &FileHandle,
         0x100081u,
         &ObjectAttributes,
         &IoStatusBlock,
         nullptr,
         0x80u,
         7u,
         1u,
         0x20u,
         nullptr,
         0) < 0 )
  {
    v8 = ZwCreateFile(
           &FileHandle,
           0x100080u,
           &ObjectAttributes,
           &IoStatusBlock,
           nullptr,
           0x80u,
           7u,
           1u,
           0x20u,
           nullptr,
           0);
    if ( v8 < 0 )
      goto LABEL_48;
  }
  v9 = ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
  v10 = FileHandle;
  v8 = v9;
  if ( v9 >= 0 )
  {
    v8 = ZwQueryInformationFile(FileHandle, &IoStatusBlock, v26, 0x18u, FileStandardInformation);
    if ( v8 < 0 )
    {
LABEL_46:
      v10 = FileHandle;
      goto LABEL_47;
    }
    memset(v5, 0, *(unsigned __int16 *)(a2 + 8) + 46LL);
    swprintf(v5, L"\\??\\%s%x", aDpshadow, *(unsigned int *)(a1 + 72));
    v11 = -1;
    v12 = v5;
    do
    {
      if ( v11 == 0 )
        break;
      v13 = *v12++ == 0;
      --v11;
    }
    while ( !v13 );
    memmove(&v5[-(int)v11 - 2], (const void *)(*(_QWORD *)(a2 + 16) + 4LL), *(unsigned __int16 *)(a2 + 8) - 4);
    RtlInitUnicodeString(&Destination, v5);
    v31.ObjectName = &Destination;
    v31.Length = 48;
    v31.RootDirectory = nullptr;
    v31.Attributes = 576;
    v31.SecurityDescriptor = nullptr;
    v31.SecurityQualityOfService = nullptr;
    v14 = ZwCreateFile(
            &Handle,
            0x100002u,
            &v31,
            &IoStatusBlock,
            nullptr,
            0x80u,
            3u,
            3u,
            (v29 != 0 ? 1 : 64) | 0x20,
            nullptr,
            0);
    v15 = v14;
    if ( v14 < 0 )
    {
      if ( v14 == -1073741766 )
      {
        sub_28006AD18(v5);
        v15 = ZwCreateFile(
                &Handle,
                0x100002u,
                &v31,
                &IoStatusBlock,
                nullptr,
                0x80u,
                3u,
                3u,
                (v29 != 0 ? 1 : 64) | 0x20,
                nullptr,
                0);
      }
      if ( v15 == -1073741790 )
      {
        v15 = ZwCreateFile(
                &Handle,
                0x100001u,
                &v31,
                &IoStatusBlock,
                nullptr,
                0x80u,
                3u,
                1u,
                (v29 != 0 ? 1 : 64) | 0x20,
                nullptr,
                0);
        if ( v15 < 0 )
        {
LABEL_17:
          ZwClose(FileHandle);
          ExFreePoolWithTag(v5, 0x626E5450u);
          return (unsigned int)v15;
        }
        v16 = v34;
        v34 = 128;
        ZwSetInformationFile(Handle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
        v34 = v16;
        ZwClose(Handle);
        v15 = ZwCreateFile(
                &Handle,
                0x100002u,
                &v31,
                &IoStatusBlock,
                nullptr,
                0x80u,
                3u,
                v29 != 0 ? 3 : 0,
                (v29 != 0 ? 1 : 64) | 0x20,
                nullptr,
                0);
      }
      if ( v15 < 0 )
        goto LABEL_17;
    }
    if ( v28 != 0 )
    {
      LOBYTE(v40.LowPart) = 1;
      v17 = ZwSetInformationFile(Handle, &IoStatusBlock, &v40, 1u, FileDispositionInformation);
LABEL_44:
      v8 = v17;
      goto LABEL_45;
    }
    if ( v29 != 0 )
    {
      v8 = -1073741638;
    }
    else
    {
      v17 = ZwQueryInformationFile(Handle, &IoStatusBlock, v36, 0x18u, FileStandardInformation);
      if ( v17 < 0 )
        goto LABEL_44;
      v8 = ZwQueryInformationFile(Handle, &IoStatusBlock, v38, 0x28u, FileBasicInformation);
      if ( v8 < 0 || MaximumSize.QuadPart == v37 && v33 == v39 )
        goto LABEL_45;
      v18.QuadPart = 0;
      SectionOffset.QuadPart = 0;
      if ( MaximumSize.QuadPart > 0 )
      {
        v8 = ZwCreateSection(&SectionHandle, 5u, nullptr, &MaximumSize, 2u, 0x8000000u, FileHandle);
        if ( v8 < 0 )
          goto LABEL_45;
        v19 = MaximumSize;
        for ( SectionOffset.QuadPart = 0; v19.QuadPart > 0; v19.QuadPart -= ViewSize )
        {
          if ( v19.QuadPart >= 0x10000 )
            ViewSize = 0x10000;
          else
            ViewSize = v19.LowPart;
          BaseAddress = nullptr;
          v8 = ZwMapViewOfSection(
                 SectionHandle,
                 (HANDLE)0xFFFFFFFFFFFFFFFFLL,
                 &BaseAddress,
                 0,
                 0,
                 &SectionOffset,
                 &ViewSize,
                 ViewShare,
                 0,
                 2u);
          if ( v8 < 0 )
            break;
          v20 = ViewSize;
          if ( v19.QuadPart >= 0x10000 )
          {
            if ( ViewSize > 0x10000 )
              v20 = 0x10000;
            ViewSize = v20;
          }
          else if ( ViewSize > v19.LowPart )
          {
            LODWORD(v20) = v19.LowPart;
            ViewSize = v19.LowPart;
          }
          v8 = ZwWriteFile(Handle, nullptr, nullptr, nullptr, &IoStatusBlock, BaseAddress, v20, &SectionOffset, nullptr);
          ZwUnmapViewOfSection((HANDLE)0xFFFFFFFFFFFFFFFFLL, BaseAddress);
          if ( v8 < 0 )
            break;
          SectionOffset.QuadPart += ViewSize;
        }
        ZwClose(SectionHandle);
        v18 = SectionOffset;
      }
      if ( v8 >= 0 )
      {
        v40 = v18;
        ZwSetInformationFile(Handle, &IoStatusBlock, &v40, 8u, FileEndOfFileInformation);
        v17 = ZwSetInformationFile(Handle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
        goto LABEL_44;
      }
    }
LABEL_45:
    ZwClose(Handle);
    goto LABEL_46;
  }
LABEL_47:
  ZwClose(v10);
LABEL_48:
  ExFreePoolWithTag(v5, 0x626E5450u);
  return (unsigned int)v8;
}


// ===== sub_280067E5C @ 0x280067e5c size=0x756 =====
__int64 __fastcall sub_280067E5C(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 v4; // rdx
  PVOID *v5; // r14
  char *PoolWithTag; // rdi
  PVOID *v8; // rsi
  const wchar_t *v9; // r11
  wchar_t v10; // ax
  unsigned __int64 v11; // rdx
  __int64 v12; // rbx
  _QWORD *v13; // rax
  _QWORD *v14; // rax
  NTSTATUS v15; // eax
  NTSTATUS i; // ebp
  BOOLEAN v17; // r13
  unsigned int *v18; // r12
  ULONG v19; // edi
  PVOID v20; // rax
  _WORD *v21; // rdi
  __int64 v22; // rcx
  bool v23; // zf
  _DWORD *v24; // r14
  unsigned int *v25; // r15
  SIZE_T v26; // rdx
  char *v27; // r13
  _WORD *v28; // rdi
  __int64 v29; // rcx
  __int16 *v30; // rdx
  _WORD *v31; // rcx
  __int16 v32; // ax
  _WORD *v33; // rdi
  __int64 v34; // rcx
  __int64 v35; // rcx
  _WORD *v36; // rdi
  unsigned int *v37; // rdi
  _QWORD *Pool; // rax
  _QWORD *v39; // rcx
  unsigned int v40; // r14d
  __int64 v41; // rcx
  unsigned int *v42; // rdi
  _WORD *v43; // rdi
  _BYTE *v44; // r13
  unsigned int *v45; // rcx
  _QWORD *v46; // rcx
  PVOID *v47; // rax
  PVOID P[2]; // [rsp+60h] [rbp-D8h] BYREF
  void *FileHandle; // [rsp+70h] [rbp-C8h] BYREF
  unsigned int *v50; // [rsp+78h] [rbp-C0h]
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+80h] [rbp-B8h] BYREF
  PVOID *v52; // [rsp+90h] [rbp-A8h]
  struct _UNICODE_STRING DestinationString; // [rsp+98h] [rbp-A0h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+A8h] [rbp-90h] BYREF
  _DWORD FileInformation[24]; // [rsp+D8h] [rbp-60h] BYREF
  int v57; // [rsp+158h] [rbp+20h]

  v4 = *(unsigned __int16 *)(a2 + 8);
  *a3 = 0;
  v5 = nullptr;
  v57 = 0;
  PoolWithTag = (char *)ExAllocatePoolWithTag(PagedPool, v4 + 12, 0x626E5450u);
  if ( PoolWithTag == nullptr )
    return 3221225626LL;
  v8 = (PVOID *)ExAllocatePoolWithTag(PagedPool, 0x18u, 0x74665450u);
  if ( v8 == nullptr )
  {
    ExFreePoolWithTag(PoolWithTag, 0x626E5450u);
    return 3221225626LL;
  }
  memset(PoolWithTag, 0, *(unsigned __int16 *)(a2 + 8) + 12LL);
  v9 = L"\\??\\";
  do
  {
    v10 = *v9;
    *(const wchar_t *)((char *)v9 + PoolWithTag - (char *)L"\\??\\") = *v9;
    ++v9;
  }
  while ( v10 != 0 );
  memmove(PoolWithTag + 8, *(const void **)(a2 + 16), *(unsigned __int16 *)(a2 + 8));
  v11 = (unsigned __int64)*(unsigned __int16 *)(a2 + 8) >> 1;
  v12 = 0;
  *(_WORD *)&PoolWithTag[2 * v11 + 8] = 0;
  P[1] = P;
  P[0] = P;
  v8[2] = PoolWithTag;
  v13 = P[0];
  *v8 = P[0];
  v8[1] = P;
  v13[1] = v8;
  P[0] = v8;
  if ( v8 == P )
  {
    return (unsigned int)a3;
  }
  else
  {
    while ( 1 )
    {
      P[0] = *v8;
      *((_QWORD *)P[0] + 1) = P;
      if ( v5 == v8 )
        break;
      v14 = P[0];
      v52 = v8;
      v8[1] = P;
      *v8 = v14;
      v14[1] = v8;
      P[0] = v8;
      RtlInitUnicodeString(&DestinationString, (PCWSTR)v8[2]);
      ObjectAttributes.Length = 48;
      ObjectAttributes.RootDirectory = nullptr;
      ObjectAttributes.Attributes = 64;
      ObjectAttributes.ObjectName = &DestinationString;
      ObjectAttributes.SecurityDescriptor = nullptr;
      ObjectAttributes.SecurityQualityOfService = nullptr;
      v15 = ZwCreateFile(
              &FileHandle,
              0x1F01FFu,
              &ObjectAttributes,
              &IoStatusBlock,
              nullptr,
              0x80u,
              7u,
              1u,
              0x20u,
              nullptr,
              0);
      i = v15;
      if ( v15 < 0 )
      {
        if ( v15 == -1073741790 )
        {
          i = ZwCreateFile(
                &FileHandle,
                0x100180u,
                &ObjectAttributes,
                &IoStatusBlock,
                nullptr,
                0x80u,
                7u,
                1u,
                0x20u,
                nullptr,
                0);
          if ( i < 0 )
            goto LABEL_73;
          memset(FileInformation, 0, 40);
          ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
          FileInformation[8] = 128;
          ZwSetInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
          ZwClose(FileHandle);
          i = ZwCreateFile(
                &FileHandle,
                0x1F01FFu,
                &ObjectAttributes,
                &IoStatusBlock,
                nullptr,
                0x80u,
                7u,
                1u,
                0x20u,
                nullptr,
                0);
        }
        if ( i < 0 )
          goto LABEL_73;
      }
      v17 = 1;
LABEL_15:
      v18 = nullptr;
      v19 = 64;
      for ( i = -2147483643;
            i == -2147483643 || i == -1073741820;
            i = ZwQueryDirectoryFile(
                  FileHandle,
                  nullptr,
                  nullptr,
                  nullptr,
                  &IoStatusBlock,
                  v20,
                  v19,
                  FileDirectoryInformation,
                  0,
                  nullptr,
                  v17) )
      {
        if ( v18 != nullptr )
          ExFreePoolWithTag(v18, 0x626E5450u);
        v19 *= 2;
        v20 = ExAllocatePoolWithTag(PagedPool, v19, 0x626E5450u);
        v18 = (unsigned int *)v20;
        if ( v20 == nullptr )
        {
          i = -1073741670;
          break;
        }
      }
      if ( i == -2147483642 )
      {
        ExFreePoolWithTag(v18, 0x626E5450u);
        i = 0;
      }
      else if ( i < 0 )
      {
        if ( v18 != nullptr )
          ExFreePoolWithTag(v18, 0x626E5450u);
      }
      else
      {
        v21 = v8[2];
        v22 = -1;
        do
        {
          if ( v22 == 0 )
            break;
          v23 = *v21++ == 0;
          --v22;
        }
        while ( !v23 );
        v24 = v18 + 15;
        v25 = v18;
        v26 = v18[15] + 2 * ~v22 + 2;
        v50 = v18;
        v27 = (char *)ExAllocatePoolWithTag(PagedPool, v26, 0x626E5450u);
        if ( v27 != nullptr )
        {
          while ( 1 )
          {
            v28 = v8[2];
            v29 = -1;
            do
            {
              if ( v29 == 0 )
                break;
              v23 = *v28++ == 0;
              --v29;
            }
            while ( !v23 );
            memset(v27, 0, (unsigned int)*v24 + 2 * ~v29 + 2);
            v30 = (__int16 *)v8[2];
            v31 = v27;
            do
            {
              v32 = *v30++;
              *v31++ = v32;
            }
            while ( v32 != 0 );
            v33 = v27;
            v34 = -1;
            do
            {
              if ( v34 == 0 )
                break;
              v23 = *v33++ == 0;
              --v34;
            }
            while ( !v23 );
            v35 = -1;
            wcscpy(v33 - 1, L"\\");
            v36 = v27;
            do
            {
              if ( v35 == 0 )
                break;
              v23 = *v36++ == 0;
              --v35;
            }
            while ( !v23 );
            memmove(&v27[2 * ~v35 - 2], v25 + 16, (unsigned int)*v24);
            RtlInitUnicodeString(&DestinationString, (PCWSTR)v27);
            v37 = v50;
            if ( (v50[14] & 0x10) != 0 )
            {
              if ( (*v24 != 2 || *((_WORD *)v25 + 32) != 46)
                && (*v24 != 4 || *((_WORD *)v25 + 32) != 46 || *((_WORD *)v50 + 33) != 46) )
              {
                Pool = ExAllocatePool(PagedPool, 0x18u);
                if ( Pool == nullptr )
                {
                  ExFreePoolWithTag(v18, 0x626E5450u);
                  v45 = (unsigned int *)v27;
                  goto LABEL_62;
                }
                Pool[2] = v27;
                v39 = P[0];
                Pool[1] = P;
                *Pool = v39;
                v39[1] = Pool;
                P[0] = Pool;
                v27 = nullptr;
              }
            }
            else
            {
              v12 += *((_QWORD *)v50 + 5);
              v40 = ++v57;
              if ( v12 >= 104857600 || v40 >= 0x64 )
              {
                *a3 = 1;
                ExFreePoolWithTag(v18, 0x626E5450u);
                ExFreePoolWithTag(v27, 0x626E5450u);
LABEL_59:
                v44 = a3;
                if ( *a3 != 0 )
                  goto LABEL_68;
                ExFreePoolWithTag(v18, 0x626E5450u);
                v17 = 0;
                goto LABEL_15;
              }
            }
            if ( v27 != nullptr )
              ExFreePoolWithTag(v27, 0x626E5450u);
            if ( *v37 == 0 )
              goto LABEL_59;
            v41 = -1;
            v42 = (unsigned int *)((char *)v37 + *v37);
            v24 = v42 + 15;
            v50 = v42;
            v43 = v8[2];
            do
            {
              if ( v41 == 0 )
                break;
              v23 = *v43++ == 0;
              --v41;
            }
            while ( !v23 );
            v27 = (char *)ExAllocatePoolWithTag(PagedPool, (unsigned int)*v24 + 2 * ~v41 + 2, 0x626E5450u);
            if ( v27 == nullptr )
              break;
            v25 = v50;
          }
        }
        v45 = v18;
LABEL_62:
        ExFreePoolWithTag(v45, 0x626E5450u);
        i = -1073741670;
      }
      v44 = a3;
LABEL_68:
      ZwClose(FileHandle);
      if ( i < 0 )
        goto LABEL_73;
      v46 = *v8;
      v47 = (PVOID *)v8[1];
      *v47 = *v8;
      v46[1] = v47;
      ExFreePoolWithTag(v8[2], 0x626E5450u);
      ExFreePoolWithTag(v8, 0x74665450u);
      if ( *v44 != 0 )
        goto LABEL_73;
      v8 = (PVOID *)P[0];
      v5 = v52;
      if ( P[0] == P )
        goto LABEL_74;
    }
    ExFreePoolWithTag(v8[2], 0x626E5450u);
    ExFreePoolWithTag(v8, 0x74665450u);
    i = -1073741567;
LABEL_73:
    v8 = (PVOID *)P[0];
LABEL_74:
    if ( v8 != P )
    {
      do
      {
        P[0] = *v8;
        *((_QWORD *)P[0] + 1) = P;
        ExFreePoolWithTag(v8[2], 0x626E5450u);
        ExFreePoolWithTag(v8, 0x74665450u);
        v8 = (PVOID *)P[0];
      }
      while ( P[0] != P );
    }
  }
  return (unsigned int)i;
}


// ===== sub_2800685B8 @ 0x2800685b8 size=0x727 =====
__int64 __fastcall sub_2800685B8(__int64 a1, __int64 a2)
{
  __int64 v3; // rdx
  PVOID *v4; // r13
  char *PoolWithTag; // rdi
  PVOID *v7; // rbx
  const wchar_t *v8; // r11
  wchar_t v9; // ax
  _QWORD *v10; // rax
  _QWORD *v11; // rax
  NTSTATUS v12; // eax
  int i; // esi
  BOOLEAN v14; // r12
  unsigned int *v15; // rbp
  ULONG v16; // edi
  unsigned int *v17; // rax
  unsigned int *v18; // r15
  _DWORD *j; // r13
  _WORD *v20; // rdi
  __int64 v21; // rcx
  bool v22; // zf
  char *v23; // r12
  _WORD *v24; // rdi
  __int64 v25; // rcx
  __int16 *v26; // rdx
  _WORD *v27; // rcx
  __int16 v28; // ax
  _WORD *v29; // rdi
  __int64 v30; // rcx
  __int64 v31; // rcx
  _WORD *v32; // rdi
  _QWORD *Pool; // rax
  _QWORD *v34; // rcx
  void *v35; // rcx
  _QWORD *v36; // rcx
  PVOID *v37; // rax
  PVOID P[2]; // [rsp+68h] [rbp-210h] BYREF
  void *FileHandle; // [rsp+78h] [rbp-200h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+80h] [rbp-1F8h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+90h] [rbp-1E8h] BYREF
  PVOID *v42; // [rsp+A0h] [rbp-1D8h]
  __int64 v43; // [rsp+A8h] [rbp-1D0h]
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+B0h] [rbp-1C8h] BYREF
  _DWORD FileInformation[10]; // [rsp+E0h] [rbp-198h] BYREF
  char v46[8]; // [rsp+108h] [rbp-170h] BYREF
  __int16 v47; // [rsp+110h] [rbp-168h]
  __int16 v48; // [rsp+112h] [rbp-166h]
  PWSTR v49; // [rsp+118h] [rbp-160h]

  v3 = *(unsigned __int16 *)(a2 + 8);
  v43 = a1;
  v4 = nullptr;
  PoolWithTag = (char *)ExAllocatePoolWithTag(PagedPool, v3 + 12, 0x626E5450u);
  if ( PoolWithTag == nullptr )
    return 3221225626LL;
  v7 = (PVOID *)ExAllocatePoolWithTag(PagedPool, 0x18u, 0x74665450u);
  if ( v7 == nullptr )
  {
    ExFreePoolWithTag(PoolWithTag, 0x626E5450u);
    return 3221225626LL;
  }
  memset(PoolWithTag, 0, *(unsigned __int16 *)(a2 + 8) + 12LL);
  v8 = L"\\??\\";
  do
  {
    v9 = *v8;
    *(const wchar_t *)((char *)v8 + PoolWithTag - (char *)L"\\??\\") = *v8;
    ++v8;
  }
  while ( v9 != 0 );
  memmove(PoolWithTag + 8, *(const void **)(a2 + 16), *(unsigned __int16 *)(a2 + 8));
  *(_WORD *)&PoolWithTag[2 * ((unsigned __int64)*(unsigned __int16 *)(a2 + 8) >> 1) + 8] = 0;
  P[1] = P;
  P[0] = P;
  v7[2] = PoolWithTag;
  v10 = P[0];
  *v7 = P[0];
  v7[1] = P;
  v10[1] = v7;
  P[0] = v7;
  if ( v7 == P )
  {
    return (unsigned int)FileHandle;
  }
  else
  {
    while ( 1 )
    {
      P[0] = *v7;
      *((_QWORD *)P[0] + 1) = P;
      if ( v4 == v7 )
        break;
      v11 = P[0];
      v42 = v7;
      v7[1] = P;
      *v7 = v11;
      v11[1] = v7;
      P[0] = v7;
      RtlInitUnicodeString(&DestinationString, (PCWSTR)v7[2]);
      ObjectAttributes.Length = 48;
      ObjectAttributes.RootDirectory = nullptr;
      ObjectAttributes.Attributes = 64;
      ObjectAttributes.ObjectName = &DestinationString;
      ObjectAttributes.SecurityDescriptor = nullptr;
      ObjectAttributes.SecurityQualityOfService = nullptr;
      v12 = ZwCreateFile(
              &FileHandle,
              0x1F01FFu,
              &ObjectAttributes,
              &IoStatusBlock,
              nullptr,
              0x80u,
              7u,
              1u,
              0x20u,
              nullptr,
              0);
      i = v12;
      if ( v12 < 0 )
      {
        if ( v12 == -1073741790 )
        {
          i = ZwCreateFile(
                &FileHandle,
                0x100180u,
                &ObjectAttributes,
                &IoStatusBlock,
                nullptr,
                0x80u,
                7u,
                1u,
                0x20u,
                nullptr,
                0);
          if ( i < 0 )
            goto LABEL_68;
          memset(FileInformation, 0, sizeof(FileInformation));
          ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
          FileInformation[8] = 128;
          ZwSetInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
          ZwClose(FileHandle);
          i = ZwCreateFile(
                &FileHandle,
                0x1F01FFu,
                &ObjectAttributes,
                &IoStatusBlock,
                nullptr,
                0x80u,
                7u,
                1u,
                0x20u,
                nullptr,
                0);
        }
        if ( i < 0 )
          goto LABEL_68;
      }
      v14 = 1;
LABEL_15:
      v15 = nullptr;
      v16 = 256;
      for ( i = -2147483643;
            i == -2147483643 || i == -1073741820;
            i = ZwQueryDirectoryFile(
                  FileHandle,
                  nullptr,
                  nullptr,
                  nullptr,
                  &IoStatusBlock,
                  v17,
                  v16,
                  FileDirectoryInformation,
                  0,
                  nullptr,
                  v14) )
      {
        if ( v15 != nullptr )
          ExFreePoolWithTag(v15, 0x626E5450u);
        v16 *= 2;
        v17 = (unsigned int *)ExAllocatePoolWithTag(PagedPool, v16, 0x626E5450u);
        v15 = v17;
        if ( v17 == nullptr )
        {
          i = -1073741670;
          break;
        }
      }
      if ( i == -2147483642 )
      {
        ExFreePoolWithTag(v15, 0x626E5450u);
        i = 0;
      }
      else
      {
        if ( i >= 0 )
        {
          v18 = v15;
          for ( j = v15 + 15; ; j = v18 + 15 )
          {
            v20 = v7[2];
            v21 = -1;
            do
            {
              if ( v21 == 0 )
                break;
              v22 = *v20++ == 0;
              --v21;
            }
            while ( !v22 );
            v23 = (char *)ExAllocatePoolWithTag(PagedPool, (unsigned int)*j + 2 * ~v21 + 2, 0x626E5450u);
            if ( v23 == nullptr )
              break;
            v24 = v7[2];
            v25 = -1;
            do
            {
              if ( v25 == 0 )
                break;
              v22 = *v24++ == 0;
              --v25;
            }
            while ( !v22 );
            memset(v23, 0, (unsigned int)*j + 2 * ~v25 + 2);
            v26 = (__int16 *)v7[2];
            v27 = v23;
            do
            {
              v28 = *v26++;
              *v27++ = v28;
            }
            while ( v28 != 0 );
            v29 = v23;
            v30 = -1;
            do
            {
              if ( v30 == 0 )
                break;
              v22 = *v29++ == 0;
              --v30;
            }
            while ( !v22 );
            v31 = -1;
            wcscpy(v29 - 1, L"\\");
            v32 = v23;
            do
            {
              if ( v31 == 0 )
                break;
              v22 = *v32++ == 0;
              --v31;
            }
            while ( !v22 );
            memmove(&v23[2 * ~v31 - 2], v18 + 16, (unsigned int)*j);
            RtlInitUnicodeString(&DestinationString, (PCWSTR)v23);
            if ( (v18[14] & 0x10) != 0 )
            {
              if ( (*j != 2 || *((_WORD *)v18 + 32) != 46)
                && (*j != 4 || *((_WORD *)v18 + 32) != 46 || *((_WORD *)v18 + 33) != 46) )
              {
                Pool = ExAllocatePool(PagedPool, 0x18u);
                if ( Pool == nullptr )
                {
                  ExFreePoolWithTag(v15, 0x626E5450u);
                  v35 = v23;
LABEL_59:
                  ExFreePoolWithTag(v35, 0x626E5450u);
                  i = -1073741670;
                  goto LABEL_63;
                }
                Pool[2] = v23;
                v34 = P[0];
                Pool[1] = P;
                *Pool = v34;
                v34[1] = Pool;
                P[0] = Pool;
                v23 = nullptr;
              }
            }
            else
            {
              v47 = DestinationString.Length - 8;
              v48 = DestinationString.MaximumLength - 8;
              v49 = DestinationString.Buffer + 4;
              i = sub_2800676BC(v43, (__int64)v46);
              if ( i < 0 )
              {
                ExFreePoolWithTag(v15, 0x626E5450u);
                ExFreePoolWithTag(v23, 0x626E5450u);
LABEL_55:
                if ( i < 0 )
                  goto LABEL_63;
                ExFreePoolWithTag(v15, 0x626E5450u);
                v14 = 0;
                goto LABEL_15;
              }
            }
            if ( v23 != nullptr )
              ExFreePoolWithTag(v23, 0x626E5450u);
            if ( *v18 == 0 )
              goto LABEL_55;
            v18 = (unsigned int *)((char *)v18 + *v18);
          }
          v35 = v15;
          goto LABEL_59;
        }
        if ( v15 != nullptr )
          ExFreePoolWithTag(v15, 0x626E5450u);
      }
LABEL_63:
      ZwClose(FileHandle);
      if ( i >= 0 )
      {
        v36 = *v7;
        v37 = (PVOID *)v7[1];
        *v37 = *v7;
        v36[1] = v37;
        ExFreePoolWithTag(v7[2], 0x626E5450u);
        ExFreePoolWithTag(v7, 0x74665450u);
      }
      v7 = (PVOID *)P[0];
      if ( P[0] == P )
        goto LABEL_69;
      v4 = v42;
    }
    ExFreePoolWithTag(v7[2], 0x626E5450u);
    ExFreePoolWithTag(v7, 0x74665450u);
    i = -1073741567;
LABEL_68:
    v7 = (PVOID *)P[0];
LABEL_69:
    if ( v7 != P )
    {
      do
      {
        P[0] = *v7;
        *((_QWORD *)P[0] + 1) = P;
        ExFreePoolWithTag(v7[2], 0x626E5450u);
        ExFreePoolWithTag(v7, 0x74665450u);
        v7 = (PVOID *)P[0];
      }
      while ( P[0] != P );
    }
  }
  return (unsigned int)i;
}


// ===== sub_280068CE8 @ 0x280068ce8 size=0x420 =====
__int64 __fastcall sub_280068CE8(
        __int64 a1,
        const UNICODE_STRING *a2,
        void *a3,
        ULONG a4,
        FILE_INFORMATION_CLASS FileInformationClass)
{
  bool v9; // si
  WCHAR *PoolWithTagPriority; // rax
  WCHAR *v11; // rbx
  USHORT v13; // ax
  __int64 v14; // rcx
  size_t v15; // r8
  PWSTR Buffer; // rdx
  WCHAR *v17; // rdi
  bool v18; // zf
  NTSTATUS v19; // eax
  NTSTATUS v20; // edi
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+60h] [rbp-108h] BYREF
  struct _UNICODE_STRING Destination; // [rsp+70h] [rbp-F8h] BYREF
  void *FileHandle; // [rsp+80h] [rbp-E8h] BYREF
  struct _OBJECT_ATTRIBUTES v24; // [rsp+88h] [rbp-E0h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+B8h] [rbp-B0h] BYREF
  _BYTE v26[32]; // [rsp+E8h] [rbp-80h] BYREF
  int v27; // [rsp+108h] [rbp-60h]
  _BYTE FileInformation[48]; // [rsp+110h] [rbp-58h] BYREF
  HANDLE Handle; // [rsp+178h] [rbp+10h] BYREF

  v9 = false;
  PoolWithTagPriority = (WCHAR *)ExAllocatePoolWithTagPriority(
                                   PagedPool,
                                   a2->Length + 46LL,
                                   0x626E5450u,
                                   HighPoolPriority);
  v11 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  memset(PoolWithTagPriority, 0, a2->Length + 46LL);
  v13 = a2->Length + 46;
  Destination.Length = 0;
  Destination.MaximumLength = v13;
  Destination.Buffer = v11;
  RtlAppendUnicodeToString(&Destination, L"\\??\\");
  RtlAppendUnicodeStringToString(&Destination, a2);
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 512;
  ObjectAttributes.ObjectName = &Destination;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  if ( ZwCreateFile(
         &FileHandle,
         0x100080u,
         &ObjectAttributes,
         &IoStatusBlock,
         nullptr,
         0x80u,
         7u,
         1u,
         0x20u,
         nullptr,
         0) >= 0 )
  {
    v9 = ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation) >= 0;
    ZwClose(FileHandle);
  }
  memset(v11, 0, a2->Length + 46LL);
  swprintf(v11, L"\\??\\%s%x", aDpshadow, *(unsigned int *)(a1 + 72));
  v14 = -1;
  v15 = a2->Length - 4;
  Buffer = a2->Buffer;
  v17 = v11;
  do
  {
    if ( v14 == 0 )
      break;
    v18 = *v17++ == 0;
    --v14;
  }
  while ( !v18 );
  memmove(&v11[-v14 - 2], Buffer + 2, v15);
  RtlInitUnicodeString(&Destination, v11);
  v24.Length = 48;
  v24.RootDirectory = nullptr;
  v24.Attributes = 576;
  v24.ObjectName = &Destination;
  v24.SecurityDescriptor = nullptr;
  v24.SecurityQualityOfService = nullptr;
  v19 = ZwCreateFile(&Handle, 0x110002u, &v24, &IoStatusBlock, nullptr, 0x80u, 7u, 1u, 0x20u, nullptr, 0);
  v20 = v19;
  if ( v19 >= 0 )
    goto LABEL_13;
  if ( v19 == -1073741790 )
  {
    v20 = ZwCreateFile(&Handle, 0x100180u, &v24, &IoStatusBlock, nullptr, 0x80u, 7u, 1u, 0x20u, nullptr, 0);
    if ( v20 < 0 )
      goto LABEL_16;
    ZwQueryInformationFile(Handle, &IoStatusBlock, v26, 0x28u, FileBasicInformation);
    v27 = 128;
    ZwSetInformationFile(Handle, &IoStatusBlock, v26, 0x28u, FileBasicInformation);
    ZwClose(Handle);
    v20 = ZwCreateFile(&Handle, 0x110002u, &v24, &IoStatusBlock, nullptr, 0x80u, 7u, 1u, 0x20u, nullptr, 0);
  }
  if ( v20 >= 0 )
  {
LABEL_13:
    v20 = ZwSetInformationFile(Handle, &IoStatusBlock, a3, a4, FileInformationClass);
    if ( v9 )
      v20 = ZwSetInformationFile(Handle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
    ZwClose(Handle);
  }
LABEL_16:
  ExFreePoolWithTag(v11, 0x626E5450u);
  return (unsigned int)v20;
}


// ===== sub_280069110 @ 0x280069110 size=0x404 =====
__int64 __fastcall sub_280069110(__int64 a1, unsigned __int16 *a2, unsigned __int16 *a3)
{
  wchar_t *PoolWithTagPriority; // rax
  wchar_t *v7; // rsi
  __int64 v9; // rcx
  size_t v10; // r8
  __int64 v11; // rdx
  wchar_t *v12; // rdi
  bool v13; // zf
  ULONG v14; // r12d
  wchar_t *v15; // rax
  wchar_t *v16; // rbp
  __int64 v17; // rcx
  _WORD *v18; // rdi
  __int64 v19; // rcx
  _WORD *v20; // rdi
  NTSTATUS v21; // eax
  NTSTATUS v22; // edi
  int v23; // edi
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+60h] [rbp-A8h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+70h] [rbp-98h] BYREF
  _DWORD FileInformation[10]; // [rsp+80h] [rbp-88h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+A8h] [rbp-60h] BYREF
  void *FileHandle; // [rsp+118h] [rbp+10h] BYREF

  memset(FileInformation, 0, sizeof(FileInformation));
  PoolWithTagPriority = (wchar_t *)ExAllocatePoolWithTagPriority(PagedPool, *a2 + 46LL, 0x626E5450u, HighPoolPriority);
  v7 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  memset(PoolWithTagPriority, 0, *a2 + 46LL);
  swprintf(v7, L"\\??\\%s%x", aDpshadow, *(unsigned int *)(a1 + 72));
  v9 = -1;
  v10 = *a2 - 4;
  v11 = *((_QWORD *)a2 + 1);
  v12 = v7;
  do
  {
    if ( v9 == 0 )
      break;
    v13 = *v12++ == 0;
    --v9;
  }
  while ( !v13 );
  memmove(&v7[~v9 - 1], (const void *)(v11 + 4), v10);
  v14 = *a3 + 72;
  v15 = (wchar_t *)ExAllocatePoolWithTagPriority(PagedPool, v14, 0x626E5450u, HighPoolPriority);
  v16 = v15;
  if ( v15 == nullptr )
  {
    ExFreePoolWithTag(v7, 0x626E5450u);
    return 3221225626LL;
  }
  memset(v15, 0, *a3 + 72LL);
  swprintf(v16 + 10, L"\\??\\%s%x", aDpshadow, *(unsigned int *)(a1 + 72));
  v17 = -1;
  v18 = v16 + 10;
  do
  {
    if ( v17 == 0 )
      break;
    v13 = *v18++ == 0;
    --v17;
  }
  while ( !v13 );
  memmove(&v16[-v17 + 8], (const void *)(*((_QWORD *)a3 + 1) + 4LL), *a3 - 4);
  v19 = -1;
  *(_BYTE *)v16 = 1;
  *((_QWORD *)v16 + 1) = 0;
  v20 = v16 + 10;
  do
  {
    if ( v19 == 0 )
      break;
    v13 = *v20++ == 0;
    --v19;
  }
  while ( !v13 );
  *((_DWORD *)v16 + 4) = 2 * (-(int)v19 - 2);
  RtlInitUnicodeString(&DestinationString, v7);
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v21 = ZwCreateFile(
          &FileHandle,
          0x100002u,
          &ObjectAttributes,
          &IoStatusBlock,
          nullptr,
          0x80u,
          3u,
          1u,
          0x20u,
          nullptr,
          0);
  v22 = v21;
  if ( v21 >= 0 )
  {
    ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
LABEL_21:
    v22 = ZwSetInformationFile(FileHandle, &IoStatusBlock, v16, v14, FileRenameInformation);
    ZwSetInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
    ZwClose(FileHandle);
    goto LABEL_22;
  }
  if ( v21 != -1073741790 )
  {
LABEL_18:
    if ( v22 < 0 )
      goto LABEL_22;
    goto LABEL_21;
  }
  v22 = ZwCreateFile(
          &FileHandle,
          0x100180u,
          &ObjectAttributes,
          &IoStatusBlock,
          nullptr,
          0x80u,
          3u,
          1u,
          0x20u,
          nullptr,
          0);
  if ( v22 >= 0 )
  {
    ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
    v23 = FileInformation[8];
    FileInformation[8] = 128;
    ZwSetInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
    FileInformation[8] = v23;
    ZwClose(FileHandle);
    v22 = ZwCreateFile(
            &FileHandle,
            0x100002u,
            &ObjectAttributes,
            &IoStatusBlock,
            nullptr,
            0x80u,
            3u,
            1u,
            0x20u,
            nullptr,
            0);
    goto LABEL_18;
  }
LABEL_22:
  ExFreePoolWithTag(v7, 0x626E5450u);
  ExFreePoolWithTag(v16, 0x626E5450u);
  return (unsigned int)v22;
}


// ===== sub_28006951C @ 0x28006951c size=0x49e =====
__int64 __fastcall sub_28006951C(__int64 a1, __int64 a2, void *a3, ULONG a4, PLARGE_INTEGER ByteOffset)
{
  wchar_t *PoolWithTagPriority; // rax
  wchar_t *v10; // rbx
  __int64 v12; // rcx
  wchar_t *v13; // rdi
  bool v14; // zf
  wchar_t *v15; // rax
  NTSTATUS Status; // edi
  struct _MDL *Mdl; // rax
  struct _MDL *v18; // rbp
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+70h] [rbp-B8h] BYREF
  PVOID Object; // [rsp+80h] [rbp-A8h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+88h] [rbp-A0h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+B8h] [rbp-70h] BYREF
  struct _KEVENT Event; // [rsp+C8h] [rbp-60h] BYREF
  _BYTE FileInformation[32]; // [rsp+E0h] [rbp-48h] BYREF
  int v25; // [rsp+100h] [rbp-28h]
  void *FileHandle; // [rsp+138h] [rbp+10h] BYREF

  if ( a2 != 0 )
  {
    PoolWithTagPriority = (wchar_t *)ExAllocatePoolWithTagPriority(
                                       PagedPool,
                                       *(unsigned __int16 *)(a2 + 8) + 46LL,
                                       0x626E5450u,
                                       HighPoolPriority);
    v10 = PoolWithTagPriority;
    if ( PoolWithTagPriority == nullptr )
      return 3221225626LL;
    memset(PoolWithTagPriority, 0, *(unsigned __int16 *)(a2 + 8) + 46LL);
    swprintf(v10, L"\\??\\%s%x", aDpshadow, *(unsigned int *)(a1 + 72));
    v12 = -1;
    v13 = v10;
    do
    {
      if ( v12 == 0 )
        break;
      v14 = *v13++ == 0;
      --v12;
    }
    while ( !v14 );
    memmove(&v10[-(int)v12 - 2], (const void *)(*(_QWORD *)(a2 + 16) + 4LL), *(unsigned __int16 *)(a2 + 8) - 4);
  }
  else
  {
    v15 = (wchar_t *)ExAllocatePoolWithTagPriority(PagedPool, 0x48u, 0x626E5450u, HighPoolPriority);
    v10 = v15;
    if ( v15 == nullptr )
      return 3221225626LL;
    memset(v15, 0, 0x48u);
    swprintf(v10, L"\\??\\%s%x\\hiberfil.sys", aDpshadow, *(unsigned int *)(a1 + 72));
  }
  RtlInitUnicodeString(&DestinationString, v10);
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &DestinationString;
  if ( a2 != 0 )
  {
    Status = ZwCreateFile(
               &FileHandle,
               0x100002u,
               &ObjectAttributes,
               &IoStatusBlock,
               nullptr,
               0x80u,
               7u,
               1u,
               0x68u,
               nullptr,
               0);
    if ( Status >= 0 )
    {
LABEL_16:
      IoStatusBlock.Status = 0;
      IoStatusBlock.Information = 0;
      Status = ZwWriteFile(FileHandle, nullptr, nullptr, nullptr, &IoStatusBlock, a3, a4, ByteOffset, nullptr);
LABEL_24:
      ZwClose(FileHandle);
      goto LABEL_25;
    }
    if ( Status == -1073741790 )
    {
      Status = ZwCreateFile(
                 &FileHandle,
                 0x100180u,
                 &ObjectAttributes,
                 &IoStatusBlock,
                 nullptr,
                 0x80u,
                 7u,
                 1u,
                 0x60u,
                 nullptr,
                 0);
      if ( Status < 0 )
        goto LABEL_25;
      ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
      v25 = 128;
      ZwSetInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
      ZwClose(FileHandle);
      Status = ZwCreateFile(
                 &FileHandle,
                 0x100002u,
                 &ObjectAttributes,
                 &IoStatusBlock,
                 nullptr,
                 0x80u,
                 7u,
                 1u,
                 0x68u,
                 nullptr,
                 0);
    }
    if ( Status >= 0 )
      goto LABEL_16;
  }
  else
  {
    Status = IoCreateFile(
               &FileHandle,
               0x100002u,
               &ObjectAttributes,
               &IoStatusBlock,
               nullptr,
               0x80u,
               7u,
               1u,
               0x60u,
               nullptr,
               0,
               CreateFileTypeNone,
               nullptr,
               0x102u);
    if ( Status >= 0 )
    {
      Status = ObReferenceObjectByHandle(FileHandle, 0, (POBJECT_TYPE)IoFileObjectType, 0, &Object, nullptr);
      if ( Status >= 0 )
      {
        Mdl = IoAllocateMdl(a3, a4, 0, 0, nullptr);
        v18 = Mdl;
        if ( Mdl != nullptr )
        {
          MmBuildMdlForNonPagedPool(Mdl);
          KeInitializeEvent(&Event, NotificationEvent, 0);
          Status = IoSynchronousPageWrite((PFILE_OBJECT)Object, v18, ByteOffset, &Event, &IoStatusBlock);
          if ( Status == 259 )
          {
            KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
            Status = IoStatusBlock.Status;
          }
          IoFreeMdl(v18);
          ObfDereferenceObject(Object);
        }
        else
        {
          ObfDereferenceObject(Object);
          Status = -1073741670;
        }
      }
      goto LABEL_24;
    }
  }
LABEL_25:
  ExFreePoolWithTag(v10, 0x626E5450u);
  return (unsigned int)Status;
}


// ===== sub_2800699C0 @ 0x2800699c0 size=0x383 =====
__int64 __fastcall sub_2800699C0(__int64 a1, __int64 a2)
{
  wchar_t *PoolWithTagPriority; // rax
  wchar_t *v5; // rbx
  __int64 v7; // rcx
  size_t v8; // r8
  __int64 v9; // rdx
  wchar_t *v10; // rdi
  bool v11; // zf
  NTSTATUS v12; // eax
  NTSTATUS Status; // edi
  struct _DEVICE_OBJECT *RelatedDeviceObject; // rdi
  PIRP v15; // rsi
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rdx
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+60h] [rbp-A8h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+70h] [rbp-98h] BYREF
  struct _KEVENT Event; // [rsp+A0h] [rbp-68h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+B8h] [rbp-50h] BYREF
  _BYTE FileInformation[32]; // [rsp+C8h] [rbp-40h] BYREF
  int v22; // [rsp+E8h] [rbp-20h]
  void *FileHandle; // [rsp+118h] [rbp+10h] BYREF
  PVOID Object; // [rsp+120h] [rbp+18h] BYREF

  PoolWithTagPriority = (wchar_t *)ExAllocatePoolWithTagPriority(
                                     PagedPool,
                                     *(unsigned __int16 *)(a2 + 8) + 46LL,
                                     0x626E5450u,
                                     HighPoolPriority);
  v5 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  memset(PoolWithTagPriority, 0, *(unsigned __int16 *)(a2 + 8) + 46LL);
  swprintf(v5, L"\\??\\%s%x", aDpshadow, *(unsigned int *)(a1 + 72));
  v7 = -1;
  v8 = *(unsigned __int16 *)(a2 + 8) - 4;
  v9 = *(_QWORD *)(a2 + 16);
  v10 = v5;
  do
  {
    if ( v7 == 0 )
      break;
    v11 = *v10++ == 0;
    --v7;
  }
  while ( !v11 );
  memmove(&v5[-(int)v7 - 2], (const void *)(v9 + 4), v8);
  RtlInitUnicodeString(&DestinationString, v5);
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v12 = ZwCreateFile(
          &FileHandle,
          0x100002u,
          &ObjectAttributes,
          &IoStatusBlock,
          nullptr,
          0x80u,
          7u,
          1u,
          0x60u,
          nullptr,
          0);
  Status = v12;
  if ( v12 >= 0 )
    goto LABEL_11;
  if ( v12 == -1073741790 )
  {
    Status = ZwCreateFile(
               &FileHandle,
               0x100180u,
               &ObjectAttributes,
               &IoStatusBlock,
               nullptr,
               0x80u,
               7u,
               1u,
               0x60u,
               nullptr,
               0);
    if ( Status < 0 )
      goto LABEL_18;
    ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
    v22 = 128;
    ZwSetInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
    ZwClose(FileHandle);
    Status = ZwCreateFile(
               &FileHandle,
               0x100002u,
               &ObjectAttributes,
               &IoStatusBlock,
               nullptr,
               0x80u,
               7u,
               1u,
               0x60u,
               nullptr,
               0);
  }
  if ( Status >= 0 )
  {
LABEL_11:
    Status = ObReferenceObjectByHandle(FileHandle, 0x1F01FFu, (POBJECT_TYPE)IoFileObjectType, 0, &Object, nullptr);
    if ( Status >= 0 )
    {
      RelatedDeviceObject = IoGetRelatedDeviceObject((PFILE_OBJECT)Object);
      v15 = IoBuildSynchronousFsdRequest(9u, RelatedDeviceObject, nullptr, 0, nullptr, &Event, &IoStatusBlock);
      if ( v15 != nullptr )
      {
        IoStatusBlock.Status = 0;
        KeInitializeEvent(&Event, NotificationEvent, 0);
        CurrentStackLocation = v15->Tail.Overlay.CurrentStackLocation;
        CurrentStackLocation[-1].MajorFunction = 9;
        CurrentStackLocation[-1].DeviceObject = RelatedDeviceObject;
        CurrentStackLocation[-1].FileObject = (PFILE_OBJECT)Object;
        Status = IofCallDriver(RelatedDeviceObject, v15);
        if ( Status == 259 )
        {
          KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
          Status = IoStatusBlock.Status;
        }
      }
      else
      {
        Status = -1073741670;
      }
      ObfDereferenceObject(Object);
    }
    ZwClose(FileHandle);
  }
LABEL_18:
  ExFreePoolWithTag(v5, 0x626E5450u);
  return (unsigned int)Status;
}


// ===== sub_280069D4C @ 0x280069d4c size=0x2ef =====
__int64 __fastcall sub_280069D4C(__int64 a1, __int64 a2)
{
  WCHAR *PoolWithTagPriority; // rax
  WCHAR *v5; // rbx
  USHORT v7; // ax
  NTSTATUS v8; // esi
  __int64 v9; // rcx
  WCHAR *v10; // rdi
  bool v11; // zf
  NTSTATUS v12; // edi
  struct _UNICODE_STRING Destination; // [rsp+60h] [rbp-E8h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+70h] [rbp-D8h] BYREF
  struct _OBJECT_ATTRIBUTES v15; // [rsp+80h] [rbp-C8h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+B0h] [rbp-98h] BYREF
  _BYTE FileInformation[104]; // [rsp+E0h] [rbp-68h] BYREF
  void *FileHandle; // [rsp+158h] [rbp+10h] BYREF
  HANDLE Handle; // [rsp+160h] [rbp+18h] BYREF

  PoolWithTagPriority = (WCHAR *)ExAllocatePoolWithTagPriority(
                                   PagedPool,
                                   *(unsigned __int16 *)(a2 + 8) + 46LL,
                                   0x626E5450u,
                                   HighPoolPriority);
  v5 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  memset(PoolWithTagPriority, 0, *(unsigned __int16 *)(a2 + 8) + 46LL);
  v7 = *(_WORD *)(a2 + 8) + 46;
  Destination.Length = 0;
  Destination.MaximumLength = v7;
  Destination.Buffer = v5;
  RtlAppendUnicodeToString(&Destination, L"\\??\\");
  RtlAppendUnicodeStringToString(&Destination, (PCUNICODE_STRING)(a2 + 8));
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 512;
  ObjectAttributes.ObjectName = &Destination;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v8 = ZwCreateFile(
         &FileHandle,
         0x100080u,
         &ObjectAttributes,
         &IoStatusBlock,
         nullptr,
         0x80u,
         7u,
         1u,
         0x20u,
         nullptr,
         0);
  if ( v8 < 0 )
    goto LABEL_4;
  v8 = ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
  if ( v8 < 0 )
  {
    ZwClose(FileHandle);
LABEL_4:
    ExFreePoolWithTag(v5, 0x626E5450u);
    return (unsigned int)v8;
  }
  memset(v5, 0, *(unsigned __int16 *)(a2 + 8) + 46LL);
  swprintf(v5, L"\\??\\%s%x", aDpshadow, *(unsigned int *)(a1 + 72));
  v9 = -1;
  v10 = v5;
  do
  {
    if ( v9 == 0 )
      break;
    v11 = *v10++ == 0;
    --v9;
  }
  while ( !v11 );
  memmove(&v5[-(int)v9 - 2], (const void *)(*(_QWORD *)(a2 + 16) + 4LL), *(unsigned __int16 *)(a2 + 8) - 4);
  RtlInitUnicodeString(&Destination, v5);
  v15.Length = 48;
  v15.RootDirectory = nullptr;
  v15.Attributes = 576;
  v15.ObjectName = &Destination;
  v15.SecurityDescriptor = nullptr;
  v15.SecurityQualityOfService = nullptr;
  v12 = ZwCreateFile(&Handle, 0x100100u, &v15, &IoStatusBlock, nullptr, 0x80u, 3u, 1u, 0x20u, nullptr, 0);
  if ( v12 >= 0 )
  {
    v12 = ZwSetInformationFile(Handle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
    ZwClose(Handle);
  }
  ZwClose(FileHandle);
  ExFreePoolWithTag(v5, 0x626E5450u);
  return (unsigned int)v12;
}


// ===== sub_28006A044 @ 0x28006a044 size=0x1f9 =====
NTSTATUS __fastcall sub_28006A044(struct _UNICODE_STRING *a1)
{
  NTSTATUS result; // eax
  NTSTATUS v2; // ebx
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+60h] [rbp-78h] BYREF
  _DWORD FileInformation[10]; // [rsp+70h] [rbp-68h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+98h] [rbp-40h] BYREF
  char v6; // [rsp+E0h] [rbp+8h] BYREF
  void *FileHandle; // [rsp+E8h] [rbp+10h] BYREF

  ObjectAttributes.ObjectName = a1;
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  result = ZwCreateFile(
             &FileHandle,
             0x110002u,
             &ObjectAttributes,
             &IoStatusBlock,
             nullptr,
             0x80u,
             7u,
             1u,
             0x1020u,
             nullptr,
             0);
  if ( result >= 0 )
    goto LABEL_6;
  if ( result == -1073741790 )
  {
    result = ZwCreateFile(
               &FileHandle,
               0x100180u,
               &ObjectAttributes,
               &IoStatusBlock,
               nullptr,
               0x80u,
               7u,
               1u,
               0x20u,
               nullptr,
               0);
    if ( result < 0 )
      return result;
    memset(FileInformation, 0, sizeof(FileInformation));
    ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
    FileInformation[8] = 128;
    ZwSetInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
    ZwClose(FileHandle);
    result = ZwCreateFile(
               &FileHandle,
               0x110002u,
               &ObjectAttributes,
               &IoStatusBlock,
               nullptr,
               0x80u,
               7u,
               1u,
               0x1020u,
               nullptr,
               0);
  }
  if ( result >= 0 )
  {
LABEL_6:
    v6 = 1;
    v2 = ZwSetInformationFile(FileHandle, &IoStatusBlock, &v6, 1u, FileDispositionInformation);
    ZwClose(FileHandle);
    return v2;
  }
  return result;
}


// ===== sub_28006A244 @ 0x28006a244 size=0x6cc =====
__int64 __fastcall sub_28006A244(const void **a1, void *a2)
{
  PVOID *v4; // r14
  PVOID *PoolWithTag; // rbx
  _QWORD *v7; // rax
  _QWORD *v8; // rax
  NTSTATUS v9; // eax
  NTSTATUS i; // esi
  BOOLEAN v11; // r13
  unsigned int *v12; // r12
  ULONG v13; // edi
  PVOID v14; // rax
  _WORD *v15; // rdi
  __int64 v16; // rcx
  bool v17; // zf
  _DWORD *v18; // r14
  unsigned int *v19; // r15
  SIZE_T v20; // rdx
  char *v21; // r13
  _WORD *v22; // rdi
  __int64 v23; // rcx
  __int16 *v24; // rdx
  _WORD *v25; // rcx
  __int16 v26; // ax
  _WORD *v27; // rdi
  __int64 v28; // rcx
  __int64 v29; // rcx
  _WORD *v30; // rdi
  unsigned int *v31; // rdi
  _QWORD *Pool; // rax
  _QWORD *v33; // rcx
  NTSTATUS v34; // eax
  __int64 v35; // rcx
  unsigned int *v36; // rdi
  _WORD *v37; // rdi
  unsigned int *v38; // rcx
  _QWORD *v39; // rcx
  PVOID *v40; // rax
  PVOID P[2]; // [rsp+60h] [rbp-D8h] BYREF
  void *FileHandle; // [rsp+70h] [rbp-C8h] BYREF
  unsigned int *v43; // [rsp+78h] [rbp-C0h]
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+80h] [rbp-B8h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+90h] [rbp-A8h] BYREF
  PVOID *v46; // [rsp+A0h] [rbp-98h]
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+A8h] [rbp-90h] BYREF
  _DWORD FileInformation[24]; // [rsp+D8h] [rbp-60h] BYREF
  unsigned int v49; // [rsp+150h] [rbp+18h]
  char v50; // [rsp+158h] [rbp+20h] BYREF

  v4 = nullptr;
  PoolWithTag = (PVOID *)ExAllocatePoolWithTag(PagedPool, 0x18u, 0x74665450u);
  if ( PoolWithTag != nullptr )
  {
    memmove(a2, a1[1], *(unsigned __int16 *)a1);
    *((_WORD *)a2 + ((unsigned __int64)*(unsigned __int16 *)a1 >> 1)) = 0;
    P[1] = P;
    P[0] = P;
    PoolWithTag[2] = a2;
    v7 = P[0];
    *PoolWithTag = P[0];
    PoolWithTag[1] = P;
    v7[1] = PoolWithTag;
    P[0] = PoolWithTag;
    if ( PoolWithTag == P )
    {
      return v49;
    }
    else
    {
      while ( 1 )
      {
        P[0] = *PoolWithTag;
        *((_QWORD *)P[0] + 1) = P;
        if ( v4 == PoolWithTag )
          break;
        v8 = P[0];
        v46 = PoolWithTag;
        PoolWithTag[1] = P;
        *PoolWithTag = v8;
        v8[1] = PoolWithTag;
        P[0] = PoolWithTag;
        RtlInitUnicodeString(&DestinationString, (PCWSTR)PoolWithTag[2]);
        ObjectAttributes.Length = 48;
        ObjectAttributes.RootDirectory = nullptr;
        ObjectAttributes.Attributes = 64;
        ObjectAttributes.ObjectName = &DestinationString;
        ObjectAttributes.SecurityDescriptor = nullptr;
        ObjectAttributes.SecurityQualityOfService = nullptr;
        v9 = ZwCreateFile(
               &FileHandle,
               0x1F01FFu,
               &ObjectAttributes,
               &IoStatusBlock,
               nullptr,
               0x80u,
               7u,
               1u,
               0x20u,
               nullptr,
               0);
        i = v9;
        if ( v9 < 0 )
        {
          if ( v9 == -1073741790 )
          {
            i = ZwCreateFile(
                  &FileHandle,
                  0x100180u,
                  &ObjectAttributes,
                  &IoStatusBlock,
                  nullptr,
                  0x80u,
                  7u,
                  1u,
                  0x20u,
                  nullptr,
                  0);
            if ( i < 0 )
              goto LABEL_71;
            memset(FileInformation, 0, 40);
            ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
            FileInformation[8] = 128;
            ZwSetInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
            ZwClose(FileHandle);
            i = ZwCreateFile(
                  &FileHandle,
                  0x1F01FFu,
                  &ObjectAttributes,
                  &IoStatusBlock,
                  nullptr,
                  0x80u,
                  7u,
                  1u,
                  0x20u,
                  nullptr,
                  0);
          }
          if ( i < 0 )
            goto LABEL_71;
        }
        v11 = 1;
LABEL_11:
        v12 = nullptr;
        v13 = 256;
        for ( i = -2147483643;
              i == -2147483643 || i == -1073741820;
              i = ZwQueryDirectoryFile(
                    FileHandle,
                    nullptr,
                    nullptr,
                    nullptr,
                    &IoStatusBlock,
                    v14,
                    v13,
                    FileDirectoryInformation,
                    0,
                    nullptr,
                    v11) )
        {
          if ( v12 != nullptr )
            ExFreePoolWithTag(v12, 0x626E5450u);
          v13 *= 2;
          v14 = ExAllocatePoolWithTag(PagedPool, v13, 0x626E5450u);
          v12 = (unsigned int *)v14;
          if ( v14 == nullptr )
          {
            i = -1073741670;
            break;
          }
        }
        if ( i == -2147483642 )
        {
          if ( v12 != nullptr )
            ExFreePoolWithTag(v12, 0x626E5450u);
          v50 = 1;
          i = ZwSetInformationFile(FileHandle, &IoStatusBlock, &v50, 1u, FileDispositionInformation);
        }
        else if ( i < 0 )
        {
          if ( v12 != nullptr )
            ExFreePoolWithTag(v12, 0x626E5450u);
        }
        else
        {
          v15 = PoolWithTag[2];
          v16 = -1;
          do
          {
            if ( v16 == 0 )
              break;
            v17 = *v15++ == 0;
            --v16;
          }
          while ( !v17 );
          v18 = v12 + 15;
          v19 = v12;
          v20 = v12[15] + 2 * ~v16 + 2;
          v43 = v12;
          v21 = (char *)ExAllocatePoolWithTag(PagedPool, v20, 0x626E5450u);
          if ( v21 != nullptr )
          {
            while ( 1 )
            {
              v22 = PoolWithTag[2];
              v23 = -1;
              do
              {
                if ( v23 == 0 )
                  break;
                v17 = *v22++ == 0;
                --v23;
              }
              while ( !v17 );
              memset(v21, 0, (unsigned int)*v18 + 2 * ~v23 + 2);
              v24 = (__int16 *)PoolWithTag[2];
              v25 = v21;
              do
              {
                v26 = *v24++;
                *v25++ = v26;
              }
              while ( v26 != 0 );
              v27 = v21;
              v28 = -1;
              do
              {
                if ( v28 == 0 )
                  break;
                v17 = *v27++ == 0;
                --v28;
              }
              while ( !v17 );
              v29 = -1;
              wcscpy(v27 - 1, L"\\");
              v30 = v21;
              do
              {
                if ( v29 == 0 )
                  break;
                v17 = *v30++ == 0;
                --v29;
              }
              while ( !v17 );
              memmove(&v21[2 * ~v29 - 2], v19 + 16, (unsigned int)*v18);
              RtlInitUnicodeString(&DestinationString, (PCWSTR)v21);
              v31 = v43;
              if ( (v43[14] & 0x10) != 0 )
              {
                if ( (*v18 != 2 || *((_WORD *)v19 + 32) != 46)
                  && (*v18 != 4 || *((_WORD *)v19 + 32) != 46 || *((_WORD *)v43 + 33) != 46) )
                {
                  Pool = ExAllocatePool(PagedPool, 0x18u);
                  if ( Pool == nullptr )
                  {
                    ExFreePoolWithTag(v12, 0x626E5450u);
                    v38 = (unsigned int *)v21;
                    goto LABEL_60;
                  }
                  Pool[2] = v21;
                  v33 = P[0];
                  Pool[1] = P;
                  *Pool = v33;
                  v33[1] = Pool;
                  P[0] = Pool;
                  v21 = nullptr;
                }
              }
              else
              {
                v34 = sub_28006A044(&DestinationString);
                i = v34;
                if ( v34 < 0 && v34 != -1073741773 && v34 != -1073741772 )
                {
                  ExFreePoolWithTag(v12, 0x626E5450u);
                  ExFreePoolWithTag(v21, 0x626E5450u);
LABEL_48:
                  if ( i < 0 )
                    goto LABEL_66;
                  ExFreePoolWithTag(v12, 0x626E5450u);
                  v11 = 0;
                  goto LABEL_11;
                }
              }
              if ( v21 != nullptr )
                ExFreePoolWithTag(v21, 0x626E5450u);
              if ( *v31 == 0 )
                goto LABEL_48;
              v35 = -1;
              v36 = (unsigned int *)((char *)v31 + *v31);
              v18 = v36 + 15;
              v43 = v36;
              v37 = PoolWithTag[2];
              do
              {
                if ( v35 == 0 )
                  break;
                v17 = *v37++ == 0;
                --v35;
              }
              while ( !v17 );
              v21 = (char *)ExAllocatePoolWithTag(PagedPool, (unsigned int)*v18 + 2 * ~v35 + 2, 0x626E5450u);
              if ( v21 == nullptr )
                break;
              v19 = v43;
            }
          }
          v38 = v12;
LABEL_60:
          ExFreePoolWithTag(v38, 0x626E5450u);
          i = -1073741670;
        }
LABEL_66:
        ZwClose(FileHandle);
        if ( i >= 0 )
        {
          v39 = *PoolWithTag;
          v40 = (PVOID *)PoolWithTag[1];
          *v40 = *PoolWithTag;
          v39[1] = v40;
          ExFreePoolWithTag(PoolWithTag[2], 0x626E5450u);
          ExFreePoolWithTag(PoolWithTag, 0x74665450u);
        }
        PoolWithTag = (PVOID *)P[0];
        if ( P[0] == P )
          goto LABEL_72;
        v4 = v46;
      }
      ExFreePoolWithTag(PoolWithTag[2], 0x626E5450u);
      ExFreePoolWithTag(PoolWithTag, 0x74665450u);
      i = -1073741567;
LABEL_71:
      PoolWithTag = (PVOID *)P[0];
LABEL_72:
      if ( PoolWithTag != P )
      {
        do
        {
          P[0] = *PoolWithTag;
          *((_QWORD *)P[0] + 1) = P;
          ExFreePoolWithTag(PoolWithTag[2], 0x626E5450u);
          ExFreePoolWithTag(PoolWithTag, 0x74665450u);
          PoolWithTag = (PVOID *)P[0];
        }
        while ( P[0] != P );
      }
    }
    return (unsigned int)i;
  }
  else
  {
    ExFreePoolWithTag(a2, 0x626E5450u);
    return 3221225626LL;
  }
}


// ===== sub_28006A918 @ 0x28006a918 size=0xff =====
__int64 __fastcall sub_28006A918(__int64 a1, __int64 a2)
{
  wchar_t *PoolWithTagPriority; // rax
  wchar_t *v5; // rbx
  __int64 v7; // rcx
  size_t v8; // r8
  __int64 v9; // rdx
  wchar_t *v10; // rdi
  bool v11; // zf
  PVOID PoolWithTag; // rax
  unsigned int v13; // edi
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-18h] BYREF

  PoolWithTagPriority = (wchar_t *)ExAllocatePoolWithTagPriority(
                                     PagedPool,
                                     *(unsigned __int16 *)(a2 + 8) + 46LL,
                                     0x626E5450u,
                                     HighPoolPriority);
  v5 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  memset(PoolWithTagPriority, 0, *(unsigned __int16 *)(a2 + 8) + 46LL);
  swprintf(v5, L"\\??\\%s%x", aDpshadow, *(unsigned int *)(a1 + 72));
  v7 = -1;
  v8 = *(unsigned __int16 *)(a2 + 8) - 4;
  v9 = *(_QWORD *)(a2 + 16);
  v10 = v5;
  do
  {
    if ( v7 == 0 )
      break;
    v11 = *v10++ == 0;
    --v7;
  }
  while ( !v11 );
  memmove(&v5[~v7 - 1], (const void *)(v9 + 4), v8);
  RtlInitUnicodeString(&DestinationString, v5);
  PoolWithTag = ExAllocatePoolWithTag(PagedPool, DestinationString.Length + 2LL, 0x626E5450u);
  if ( PoolWithTag != nullptr )
    v13 = sub_28006A244((const void **)&DestinationString, PoolWithTag);
  else
    v13 = -1073741670;
  ExFreePoolWithTag(v5, 0x626E5450u);
  return v13;
}


// ===== sub_28006AA20 @ 0x28006aa20 size=0x2f2 =====
__int64 __fastcall sub_28006AA20(__int64 a1, __int64 a2, void *a3, ULONG a4, ULONG FsControlCode)
{
  wchar_t *PoolWithTagPriority; // rax
  wchar_t *v10; // rbx
  __int64 v12; // rcx
  size_t v13; // r8
  __int64 v14; // rdx
  wchar_t *v15; // rdi
  bool v16; // zf
  NTSTATUS v17; // eax
  NTSTATUS v18; // edi
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+60h] [rbp-98h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+70h] [rbp-88h] BYREF
  _BYTE FileInformation[32]; // [rsp+80h] [rbp-78h] BYREF
  int v22; // [rsp+A0h] [rbp-58h]
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+A8h] [rbp-50h] BYREF
  void *FileHandle; // [rsp+108h] [rbp+10h] BYREF

  PoolWithTagPriority = (wchar_t *)ExAllocatePoolWithTagPriority(
                                     PagedPool,
                                     *(unsigned __int16 *)(a2 + 8) + 46LL,
                                     0x626E5450u,
                                     HighPoolPriority);
  v10 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  memset(PoolWithTagPriority, 0, *(unsigned __int16 *)(a2 + 8) + 46LL);
  swprintf(v10, L"\\??\\%s%x", aDpshadow, *(unsigned int *)(a1 + 72));
  v12 = -1;
  v13 = *(unsigned __int16 *)(a2 + 8) - 4;
  v14 = *(_QWORD *)(a2 + 16);
  v15 = v10;
  do
  {
    if ( v12 == 0 )
      break;
    v16 = *v15++ == 0;
    --v12;
  }
  while ( !v16 );
  memmove(&v10[~v12 - 1], (const void *)(v14 + 4), v13);
  RtlInitUnicodeString(&DestinationString, v10);
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v17 = ZwCreateFile(
          &FileHandle,
          0x100002u,
          &ObjectAttributes,
          &IoStatusBlock,
          nullptr,
          0x80u,
          7u,
          1u,
          0x20u,
          nullptr,
          0);
  v18 = v17;
  if ( v17 >= 0 )
    goto LABEL_11;
  if ( v17 == -1073741790 )
  {
    v18 = ZwCreateFile(
            &FileHandle,
            0x100001u,
            &ObjectAttributes,
            &IoStatusBlock,
            nullptr,
            0x80u,
            7u,
            1u,
            0x20u,
            nullptr,
            0);
    if ( v18 < 0 )
      goto LABEL_12;
    ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
    v22 = 128;
    ZwSetInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x28u, FileBasicInformation);
    ZwClose(FileHandle);
    v18 = ZwCreateFile(
            &FileHandle,
            0x100002u,
            &ObjectAttributes,
            &IoStatusBlock,
            nullptr,
            0x80u,
            7u,
            1u,
            0x20u,
            nullptr,
            0);
  }
  if ( v18 >= 0 )
  {
LABEL_11:
    v18 = ZwFsControlFile(FileHandle, nullptr, nullptr, nullptr, &IoStatusBlock, FsControlCode, a3, a4, nullptr, 0);
    ZwClose(FileHandle);
  }
LABEL_12:
  ExFreePoolWithTag(v10, 0x626E5450u);
  return (unsigned int)v18;
}


// ===== sub_28006AD18 @ 0x28006ad18 size=0x10f =====
__int64 __fastcall sub_28006AD18(WCHAR *SourceString)
{
  WCHAR *v2; // rbx
  NTSTATUS v3; // esi
  struct _UNICODE_STRING DestinationString; // [rsp+60h] [rbp-68h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+70h] [rbp-58h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+80h] [rbp-48h] BYREF
  void *FileHandle; // [rsp+D0h] [rbp+8h] BYREF

  v2 = SourceString;
  v3 = 0;
  while ( *v2 != 0 )
  {
    if ( *++v2 == 92 )
    {
      *v2 = 0;
      RtlInitUnicodeString(&DestinationString, SourceString);
      ObjectAttributes.Length = 48;
      ObjectAttributes.RootDirectory = nullptr;
      ObjectAttributes.Attributes = 576;
      ObjectAttributes.ObjectName = &DestinationString;
      ObjectAttributes.SecurityDescriptor = nullptr;
      ObjectAttributes.SecurityQualityOfService = nullptr;
      v3 = ZwCreateFile(
             &FileHandle,
             0x100001u,
             &ObjectAttributes,
             &IoStatusBlock,
             nullptr,
             0x80u,
             3u,
             3u,
             0x21u,
             nullptr,
             0);
      if ( v3 >= 0 )
        ZwClose(FileHandle);
      *v2 = 92;
    }
  }
  return (unsigned int)v3;
}


// ===== sub_28006AE30 @ 0x28006ae30 size=0x1b7 =====
NTSTATUS __fastcall sub_28006AE30(struct _UNICODE_STRING *a1)
{
  NTSTATUS result; // eax
  NTSTATUS Status; // ebx
  struct _DEVICE_OBJECT *RelatedDeviceObject; // rbx
  PIRP v4; // rdx
  struct _KTHREAD *CurrentThread; // rax
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rcx
  struct _FILE_OBJECT *v7; // rax
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+60h] [rbp-68h] BYREF
  struct _KEVENT Event; // [rsp+70h] [rbp-58h] BYREF
  struct _OBJECT_ATTRIBUTES v10; // [rsp+88h] [rbp-40h] BYREF
  PVOID Object; // [rsp+D0h] [rbp+8h] BYREF
  HANDLE Handle; // [rsp+D8h] [rbp+10h] BYREF

  v10.RootDirectory = nullptr;
  v10.SecurityDescriptor = nullptr;
  v10.SecurityQualityOfService = nullptr;
  v10.ObjectName = a1;
  v10.Length = 48;
  v10.Attributes = 576;
  result = ZwCreateFile(&Handle, 0x100001u, &v10, &IoStatusBlock, nullptr, 0x80u, 7u, 1u, 0x20u, nullptr, 0);
  if ( result >= 0 )
  {
    Status = ObReferenceObjectByHandle(Handle, 0x80u, nullptr, 0, &Object, nullptr);
    if ( Status >= 0 )
    {
      RelatedDeviceObject = IoGetRelatedDeviceObject((PFILE_OBJECT)Object);
      if ( RelatedDeviceObject != nullptr )
      {
        KeInitializeEvent(&Event, NotificationEvent, 0);
        v4 = IoBuildSynchronousFsdRequest(9u, RelatedDeviceObject, nullptr, 0, nullptr, &Event, &IoStatusBlock);
        if ( v4 != nullptr )
        {
          CurrentThread = KeGetCurrentThread();
          CurrentStackLocation = v4->Tail.Overlay.CurrentStackLocation;
          v4->RequestorMode = 0;
          v4->Tail.Overlay.Thread = CurrentThread;
          v7 = (struct _FILE_OBJECT *)Object;
          CurrentStackLocation[-1].MajorFunction = 9;
          CurrentStackLocation[-1].FileObject = v7;
          Status = IofCallDriver(RelatedDeviceObject, v4);
          if ( Status == 259 )
          {
            KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
            Status = IoStatusBlock.Status;
          }
          ObfDereferenceObject(Object);
        }
        else
        {
          ObfDereferenceObject(Object);
          Status = -1073741670;
        }
      }
      else
      {
        ObfDereferenceObject(Object);
        Status = -1073741811;
      }
    }
    ZwClose(Handle);
    return Status;
  }
  return result;
}


// ===== sub_28006AFF0 @ 0x28006aff0 size=0x5 =====
// attributes: thunk
__int64 __fastcall sub_28006AFF0(PSLIST_ENTRY ListEntry)
{
  return sub_28006AFFC(ListEntry);
}


// ===== sub_28006AFFC @ 0x28006affc size=0x61 =====
PSLIST_ENTRY __fastcall sub_28006AFFC(PSLIST_ENTRY ListEntry)
{
  struct _SLIST_ENTRY *v2; // rcx

  v2 = *(&ListEntry[2].Next + 1);
  if ( v2 != nullptr )
    sub_28006C8A8(v2);
  ++dword_28007499C;
  if ( ExQueryDepthSList(&stru_280074980) < (unsigned __int16)word_280074990 )
    return ExpInterlockedPushEntrySList(&stru_280074980, ListEntry);
  ++dword_2800749A0;
  return (PSLIST_ENTRY)qword_2800749B8(ListEntry);
}


// ===== sub_28006B064 @ 0x28006b064 size=0x181 =====
__int64 __fastcall sub_28006B064(struct _FILE_OBJECT *a1, struct _DEVICE_OBJECT *a2, _BYTE *a3)
{
  struct _IRP *PoolWithTag; // rsi
  unsigned int v7; // ebx
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rax
  struct _IO_STACK_LOCATION *v9; // r11
  int v11; // [rsp+38h] [rbp-40h] BYREF
  __int64 v12; // [rsp+40h] [rbp-38h]
  struct _KEVENT Event; // [rsp+48h] [rbp-30h] BYREF
  PIRP Irp; // [rsp+98h] [rbp+20h]

  PoolWithTag = (struct _IRP *)ExAllocatePoolWithTag(PagedPool, 0x18u, 0x74665450u);
  if ( PoolWithTag != nullptr )
  {
    Irp = IoAllocateIrp(a2->StackSize, 0);
    if ( Irp != nullptr )
    {
      Irp->Tail.Overlay.Thread = KeGetCurrentThread();
      Irp->RequestorMode = 0;
      v11 = 0;
      v12 = 0;
      Irp->UserIosb = (PIO_STATUS_BLOCK)&v11;
      Irp->UserEvent = nullptr;
      Irp->Flags = 4;
      CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
      CurrentStackLocation[-1].MajorFunction = 5;
      CurrentStackLocation[-1].FileObject = a1;
      Irp->AssociatedIrp.MasterIrp = PoolWithTag;
      CurrentStackLocation[-1].Parameters.Read.Length = 256;
      CurrentStackLocation[-1].Parameters.Create.Options = 5;
      KeInitializeEvent(&Event, NotificationEvent, 0);
      v9 = Irp->Tail.Overlay.CurrentStackLocation;
      v9[-1].CompletionRoutine = (PIO_COMPLETION_ROUTINE)&sub_28006C574;
      v9[-1].Context = &Event;
      v9[-1].Control = 0;
      v9[-1].Control = 64;
      v9[-1].Control = -64;
      v9[-1].Control = -32;
      v7 = IofCallDriver(a2, Irp);
      if ( v7 == 259 )
        KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
      if ( v11 < 0 )
        v7 = v11;
      else
        *a3 = *((_BYTE *)&PoolWithTag->Flags + 5);
    }
    else
    {
      v7 = -1073741670;
    }
  }
  else
  {
    v7 = -1073741670;
  }
  if ( PoolWithTag != nullptr )
    ExFreePoolWithTag(PoolWithTag, 0x74665450u);
  return v7;
}


// ===== sub_28006B1EC @ 0x28006b1ec size=0x23c =====
__int64 __fastcall sub_28006B1EC(__int64 a1, IRP *a2)
{
  __int64 v4; // r8
  __int64 v5; // rcx
  __int64 (__fastcall *v6)(_QWORD, _QWORD); // rdx
  _QWORD *v7; // rax
  __int64 v8; // rax
  __int64 v9; // r8
  struct _KTHREAD *CurrentThread; // rbx
  PEPROCESS CurrentProcess; // rax

  sub_28006BB34();
  if ( dword_280074A20 == 0 )
    return qword_280074FB8(a1, a2);
  v4 = qword_280074D48;
  if ( qword_280074D68 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074D48 + 144) != sub_28005C474 )
    *(_QWORD *)(qword_280074D48 + 144) = sub_28005C474;
  v5 = qword_280074D88;
  if ( qword_280074DA8 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074D88 + 144) != sub_28005CCBC )
    *(_QWORD *)(qword_280074D88 + 144) = sub_28005CCBC;
  v6 = qword_280074DD0;
  v7 = (_QWORD *)qword_280074DB8;
  if ( qword_280074DD0 != nullptr )
  {
    if ( *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074DB8 + 232) != sub_28005D0A0 )
      *(_QWORD *)(qword_280074DB8 + 232) = sub_28005D0A0;
    if ( (void (__fastcall *)(__int64, IRP *))v7[12] != sub_28005DC1C )
      v7[12] = sub_28005DC1C;
  }
  if ( qword_280074D70 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(v4 + 232) != sub_28005C7C4 )
    *(_QWORD *)(v4 + 232) = sub_28005C7C4;
  if ( qword_280074DB0 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(v5 + 232) != sub_28005CF18 )
    *(_QWORD *)(v5 + 232) = sub_28005CF18;
  if ( v6 != nullptr && (__int64 (__fastcall *)(__int64, IRP *))v7[29] != sub_28005D0A0 )
    v7[29] = sub_28005D0A0;
  if ( qword_280074E08 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074DF0 + 232) != sub_28005DD58 )
    *(_QWORD *)(qword_280074DF0 + 232) = sub_28005DD58;
  if ( qword_280074D78 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(v4 + 224) != sub_28005CA40 )
    *(_QWORD *)(v4 + 224) = sub_28005CA40;
  if ( qword_280074DD8 != nullptr && (__int64 (__fastcall *)(__int64, IRP *))v7[28] != sub_28005D718 )
    v7[28] = sub_28005D718;
  v8 = qword_280074E10;
  v9 = qword_280074E18;
  if ( qword_280074E30 != nullptr )
    *(_QWORD *)(qword_280074E10 + 144) = sub_28005E0D8;
  if ( qword_280074E38 != nullptr )
    *(_QWORD *)(v8 + 224) = sub_28005E294;
  if ( dword_280074A20 == 0 )
    return qword_280074FB8(a1, a2);
  if ( (unsigned __int8)sub_28006B9E0(a1, a2, v9, sub_28005D0A0) == 0 )
    return qword_280074FB8(a1, a2);
  CurrentThread = KeGetCurrentThread();
  CurrentProcess = IoGetCurrentProcess();
  if ( sub_2800521C4((__int64)CurrentProcess, (__int64)CurrentThread, 1) != 0 )
    return qword_280074FB8(a1, a2);
  a2->IoStatus.Status = -1073741772;
  a2->IoStatus.Information = 0;
  IofCompleteRequest(a2, 0);
  return 3221225524LL;
}


// ===== sub_28006B430 @ 0x28006b430 size=0x2d2 =====
__int64 __fastcall sub_28006B430(__int64 a1, IRP *a2)
{
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rsi
  void *v5; // r9
  __int64 v6; // r8
  __int64 v7; // rcx
  __int64 (__fastcall *v8)(_QWORD, _QWORD); // rdx
  _QWORD *v9; // rax
  __int64 v10; // rax
  __int64 v11; // r8
  struct _KTHREAD *CurrentThread; // rbx
  PEPROCESS CurrentProcess; // rax
  PFILE_OBJECT FileObject; // rcx
  PFILE_OBJECT v15; // rcx
  PFILE_OBJECT v16; // rcx

  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  sub_28006BB34();
  if ( dword_280074A20 == 0 )
    return qword_280074FC0(a1, a2);
  v6 = qword_280074D48;
  if ( qword_280074D68 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074D48 + 144) != sub_28005C474 )
    *(_QWORD *)(qword_280074D48 + 144) = sub_28005C474;
  v7 = qword_280074D88;
  if ( qword_280074DA8 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074D88 + 144) != sub_28005CCBC )
    *(_QWORD *)(qword_280074D88 + 144) = sub_28005CCBC;
  v8 = qword_280074DD0;
  v9 = (_QWORD *)qword_280074DB8;
  if ( qword_280074DD0 != nullptr )
  {
    if ( *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074DB8 + 232) != sub_28005D0A0 )
      *(_QWORD *)(qword_280074DB8 + 232) = sub_28005D0A0;
    v5 = sub_28005DC1C;
    if ( (void (__fastcall *)(__int64, IRP *))v9[12] != sub_28005DC1C )
      v9[12] = sub_28005DC1C;
  }
  if ( qword_280074D70 != nullptr )
  {
    v5 = sub_28005C7C4;
    if ( *(__int64 (__fastcall **)(__int64, IRP *))(v6 + 232) != sub_28005C7C4 )
      *(_QWORD *)(v6 + 232) = sub_28005C7C4;
  }
  if ( qword_280074DB0 != nullptr )
  {
    v5 = sub_28005CF18;
    if ( *(__int64 (__fastcall **)(__int64, IRP *))(v7 + 232) != sub_28005CF18 )
      *(_QWORD *)(v7 + 232) = sub_28005CF18;
  }
  if ( v8 != nullptr && (__int64 (__fastcall *)(__int64, IRP *))v9[29] != sub_28005D0A0 )
    v9[29] = sub_28005D0A0;
  if ( qword_280074E08 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074DF0 + 232) != sub_28005DD58 )
    *(_QWORD *)(qword_280074DF0 + 232) = sub_28005DD58;
  if ( qword_280074D78 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(v6 + 224) != sub_28005CA40 )
    *(_QWORD *)(v6 + 224) = sub_28005CA40;
  if ( qword_280074DD8 != nullptr && (__int64 (__fastcall *)(__int64, IRP *))v9[28] != sub_28005D718 )
    v9[28] = sub_28005D718;
  v10 = qword_280074E10;
  v11 = qword_280074E18;
  if ( qword_280074E30 != nullptr )
    *(_QWORD *)(qword_280074E10 + 144) = sub_28005E0D8;
  if ( qword_280074E38 != nullptr )
    *(_QWORD *)(v10 + 224) = sub_28005E294;
  if ( dword_280074A20 == 0 )
    return qword_280074FC0(a1, a2);
  if ( (unsigned __int8)sub_28006B9E0(a1, a2, v11, v5) == 0 )
    return qword_280074FC0(a1, a2);
  CurrentThread = KeGetCurrentThread();
  CurrentProcess = IoGetCurrentProcess();
  if ( sub_2800521C4((__int64)CurrentProcess, (__int64)CurrentThread, 1) != 0 )
    return qword_280074FC0(a1, a2);
  FileObject = CurrentStackLocation->FileObject;
  if ( FileObject->FileName.Length == 2 && _wcsnicmp(FileObject->FileName.Buffer, L"\\", 1u) == 0 )
    return qword_280074FC0(a1, a2);
  v15 = CurrentStackLocation->FileObject;
  if ( v15->FileName.Length == 16 && _wcsnicmp(v15->FileName.Buffer, L"\\$Extend", 8u) == 0 )
    return qword_280074FC0(a1, a2);
  v16 = CurrentStackLocation->FileObject;
  if ( v16->FileName.Length >= 0x12u && _wcsnicmp(v16->FileName.Buffer, L"\\$Extend\\", 9u) == 0 )
    return qword_280074FC0(a1, a2);
  a2->IoStatus.Status = -1073741772;
  a2->IoStatus.Information = 0;
  IofCompleteRequest(a2, 0);
  return 3221225524LL;
}


// ===== sub_28006B708 @ 0x28006b708 size=0x2d2 =====
__int64 __fastcall sub_28006B708(__int64 a1, IRP *a2)
{
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rsi
  void *v5; // r9
  __int64 v6; // r8
  __int64 v7; // rcx
  __int64 (__fastcall *v8)(_QWORD, _QWORD); // rdx
  _QWORD *v9; // rax
  __int64 v10; // rax
  __int64 v11; // r8
  struct _KTHREAD *CurrentThread; // rbx
  PEPROCESS CurrentProcess; // rax
  PFILE_OBJECT FileObject; // rcx
  PFILE_OBJECT v15; // rcx
  PFILE_OBJECT v16; // rcx

  CurrentStackLocation = a2->Tail.Overlay.CurrentStackLocation;
  sub_28006BB34();
  if ( dword_280074A20 == 0 )
    return qword_280074FC8(a1, a2);
  v6 = qword_280074D48;
  if ( qword_280074D68 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074D48 + 144) != sub_28005C474 )
    *(_QWORD *)(qword_280074D48 + 144) = sub_28005C474;
  v7 = qword_280074D88;
  if ( qword_280074DA8 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074D88 + 144) != sub_28005CCBC )
    *(_QWORD *)(qword_280074D88 + 144) = sub_28005CCBC;
  v8 = qword_280074DD0;
  v9 = (_QWORD *)qword_280074DB8;
  if ( qword_280074DD0 != nullptr )
  {
    if ( *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074DB8 + 232) != sub_28005D0A0 )
      *(_QWORD *)(qword_280074DB8 + 232) = sub_28005D0A0;
    v5 = sub_28005DC1C;
    if ( (void (__fastcall *)(__int64, IRP *))v9[12] != sub_28005DC1C )
      v9[12] = sub_28005DC1C;
  }
  if ( qword_280074D70 != nullptr )
  {
    v5 = sub_28005C7C4;
    if ( *(__int64 (__fastcall **)(__int64, IRP *))(v6 + 232) != sub_28005C7C4 )
      *(_QWORD *)(v6 + 232) = sub_28005C7C4;
  }
  if ( qword_280074DB0 != nullptr )
  {
    v5 = sub_28005CF18;
    if ( *(__int64 (__fastcall **)(__int64, IRP *))(v7 + 232) != sub_28005CF18 )
      *(_QWORD *)(v7 + 232) = sub_28005CF18;
  }
  if ( v8 != nullptr && (__int64 (__fastcall *)(__int64, IRP *))v9[29] != sub_28005D0A0 )
    v9[29] = sub_28005D0A0;
  if ( qword_280074E08 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(qword_280074DF0 + 232) != sub_28005DD58 )
    *(_QWORD *)(qword_280074DF0 + 232) = sub_28005DD58;
  if ( qword_280074D78 != nullptr && *(__int64 (__fastcall **)(__int64, IRP *))(v6 + 224) != sub_28005CA40 )
    *(_QWORD *)(v6 + 224) = sub_28005CA40;
  if ( qword_280074DD8 != nullptr && (__int64 (__fastcall *)(__int64, IRP *))v9[28] != sub_28005D718 )
    v9[28] = sub_28005D718;
  v10 = qword_280074E10;
  v11 = qword_280074E18;
  if ( qword_280074E30 != nullptr )
    *(_QWORD *)(qword_280074E10 + 144) = sub_28005E0D8;
  if ( qword_280074E38 != nullptr )
    *(_QWORD *)(v10 + 224) = sub_28005E294;
  if ( dword_280074A20 == 0 )
    return qword_280074FC8(a1, a2);
  if ( (unsigned __int8)sub_28006B9E0(a1, a2, v11, v5) == 0 )
    return qword_280074FC8(a1, a2);
  CurrentThread = KeGetCurrentThread();
  CurrentProcess = IoGetCurrentProcess();
  if ( sub_2800521C4((__int64)CurrentProcess, (__int64)CurrentThread, 1) != 0 )
    return qword_280074FC8(a1, a2);
  FileObject = CurrentStackLocation->FileObject;
  if ( FileObject->FileName.Length == 2 && _wcsnicmp(FileObject->FileName.Buffer, L"\\", 1u) == 0 )
    return qword_280074FC8(a1, a2);
  v15 = CurrentStackLocation->FileObject;
  if ( v15->FileName.Length == 16 && _wcsnicmp(v15->FileName.Buffer, L"\\$Extend", 8u) == 0 )
    return qword_280074FC8(a1, a2);
  v16 = CurrentStackLocation->FileObject;
  if ( v16->FileName.Length >= 0x12u && _wcsnicmp(v16->FileName.Buffer, L"\\$Extend\\", 9u) == 0 )
    return qword_280074FC8(a1, a2);
  a2->IoStatus.Status = -1073741772;
  a2->IoStatus.Information = 0;
  IofCompleteRequest(a2, 0);
  return 3221225524LL;
}


// ===== sub_28006B9E0 @ 0x28006b9e0 size=0x5b =====
bool __fastcall sub_28006B9E0(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  char v3; // cl
  __int64 v5; // rax
  __int64 v6; // rdx
  __int64 v7; // rdx
  __int64 v8; // rdx

  v2 = *(_QWORD *)(a2 + 184);
  v3 = 0;
  if ( *(_BYTE *)v2 != 0 )
    return false;
  v5 = *(_QWORD *)(v2 + 48);
  if ( v5 == 0 )
    return false;
  v6 = *(_QWORD *)(v5 + 8);
  if ( v6 == 0 )
    return false;
  v7 = *(_QWORD *)(v6 + 56);
  if ( v7 == 0 )
    return false;
  v8 = *(_QWORD *)(v7 + 16);
  if ( v8 == 0 )
    return false;
  if ( *(PDRIVER_OBJECT *)(v8 + 8) == DriverObject && (PDEVICE_OBJECT)v8 != DeviceObject )
    return **(_DWORD **)(v8 + 64) == 7680404;
  return v3;
}


// ===== sub_28006BB34 @ 0x28006bb34 size=0xe1 =====
void sub_28006BB34()
{
  __int64 (__fastcall *v0)(_QWORD, _QWORD); // rax
  unsigned __int64 v1; // rdx
  __int64 (__fastcall *v2)(_QWORD, _QWORD); // rax
  unsigned __int64 v3; // rdx
  __int64 (__fastcall *v4)(_QWORD, _QWORD); // rax

  if ( dword_280074A20 != 0 )
  {
    v0 = qword_280074FB8;
    if ( qword_280074FB8 != nullptr && qword_280074F90 != 0 )
    {
      v1 = *(_QWORD *)(qword_280074F90 + 112);
      if ( v1 >= qword_280074FD0 && v1 < qword_280074FD8 )
        v0 = *(__int64 (__fastcall **)(_QWORD, _QWORD))(qword_280074F90 + 112);
      _InterlockedCompareExchange64(
        (volatile signed __int64 *)(qword_280074F90 + 112),
        (signed __int64)sub_28006B1EC,
        (signed __int64)v0);
    }
    if ( dword_280074A20 != 0 )
    {
      v2 = qword_280074FC0;
      if ( qword_280074FC0 != nullptr && qword_280074F98 != 0 )
      {
        v3 = *(_QWORD *)(qword_280074F98 + 112);
        if ( v3 >= qword_280074FE0 && v3 < qword_280074FE8 )
          v2 = *(__int64 (__fastcall **)(_QWORD, _QWORD))(qword_280074F98 + 112);
        _InterlockedCompareExchange64(
          (volatile signed __int64 *)(qword_280074F98 + 112),
          (signed __int64)sub_28006B430,
          (signed __int64)v2);
      }
      if ( dword_280074A20 != 0 && qword_280074FC8 != nullptr && qword_280074FA0 != 0 )
      {
        v4 = *(__int64 (__fastcall **)(_QWORD, _QWORD))(qword_280074FA0 + 112);
        if ( (unsigned __int64)v4 < qword_280074FF0 || (unsigned __int64)v4 >= qword_280074FF8 )
          v4 = qword_280074FC8;
        _InterlockedCompareExchange64(
          (volatile signed __int64 *)(qword_280074FA0 + 112),
          (signed __int64)sub_28006B708,
          (signed __int64)v4);
      }
    }
  }
}


// ===== sub_28006BC1C @ 0x28006bc1c size=0x6a =====
void sub_28006BC1C()
{
  __int64 i; // rbx

  if ( _InterlockedIncrement(&dword_280074B3C) == 1 )
  {
    ExAcquireFastMutex(&stru_2800753E0);
    for ( i = qword_280075390; (__int64 *)i != &qword_280075390; i = *(_QWORD *)i )
      KeSetEvent(*(PRKEVENT *)(i + 24), 0, 0);
    ExReleaseFastMutex(&stru_2800753E0);
  }
}


// ===== sub_28006BC8C @ 0x28006bc8c size=0x60 =====
void sub_28006BC8C()
{
  __int64 i; // rbx

  if ( _InterlockedAdd(&dword_280074B3C, 0xFFFFFFFF) == 0 )
  {
    ExAcquireFastMutex(&stru_2800753E0);
    for ( i = qword_280075390; (__int64 *)i != &qword_280075390; i = *(_QWORD *)i )
      KeSetEvent(*(PRKEVENT *)(i + 32), 0, 0);
    ExReleaseFastMutex(&stru_2800753E0);
  }
}


// ===== sub_28006BCF4 @ 0x28006bcf4 size=0x70 =====
void __fastcall sub_28006BCF4(__int64 a1)
{
  PDEVICE_OBJECT i; // rbx
  _QWORD *DeviceExtension; // rax

  ExAcquireFastMutex(&stru_280075760);
  for ( i = DriverObject->DeviceObject; i != nullptr; i = i->NextDevice )
  {
    if ( i != DeviceObject )
    {
      DeviceExtension = i->DeviceExtension;
      if ( *(_DWORD *)DeviceExtension == 7680401 && DeviceExtension[3] == a1 )
        break;
    }
  }
  ExReleaseFastMutex(&stru_280075760);
  if ( i != nullptr )
    sub_280066DD4(i);
}


// ===== sub_28006BD6C @ 0x28006bd6c size=0x1b0 =====
__int64 __fastcall sub_28006BD6C(struct _UNICODE_STRING *a1)
{
  NTSTATUS v2; // eax
  unsigned int v3; // ebx
  void *FileHandle; // [rsp+60h] [rbp-268h] BYREF
  union _LARGE_INTEGER ByteOffset; // [rsp+68h] [rbp-260h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+70h] [rbp-258h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+A0h] [rbp-228h] BYREF
  _BYTE Buffer[4]; // [rsp+B0h] [rbp-218h] BYREF
  int v10; // [rsp+B4h] [rbp-214h]
  int v11; // [rsp+BCh] [rbp-20Ch]
  int v12; // [rsp+C0h] [rbp-208h]
  _BYTE v13[8]; // [rsp+2A8h] [rbp-20h] BYREF

  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.ObjectName = a1;
  v2 = ZwCreateFile(&FileHandle, 0x100001u, &ObjectAttributes, &IoStatusBlock, nullptr, 0, 0, 1u, 0x60u, nullptr, 0);
  v3 = v2;
  if ( v2 < 0 )
  {
    DbgPrint("diskpt!FsfTestVolume: ZwCreateFile(%wZ) failed(%x)\n", a1, (unsigned int)v2);
    return v3;
  }
  ByteOffset.QuadPart = 0;
  v3 = ZwReadFile(FileHandle, nullptr, nullptr, nullptr, &IoStatusBlock, Buffer, 0x200u, &ByteOffset, nullptr);
  ZwClose(FileHandle);
  if ( (v3 & 0x80000000) != 0 )
  {
    DbgPrint("diskpt!FsfTestVolume: ZwReadFile(%wZ) failed(%x)\n", a1, v3);
    return v3;
  }
  sub_2800522E8((__int64)Buffer, 504, (__int64)v13);
  if ( v10 == 1953524580 && v11 == 0x10000 )
    return (v12 & 1) != 0 ? 0x20000002 : 0;
  DbgPrint("diskpt!FsfTestVolume: invalid config info(%x-%x-%x)\n", v10, v11, v12);
  return 3221225473LL;
}


// ===== sub_28006BF24 @ 0x28006bf24 size=0x1c1 =====
__int64 __fastcall sub_28006BF24(PCUNICODE_STRING String2, __int64 a2)
{
  WCHAR v4; // di
  NTSTATUS v5; // ebx
  _WORD *Pool; // rax
  void *LinkHandle; // [rsp+20h] [rbp-C8h] BYREF
  struct _UNICODE_STRING LinkTarget; // [rsp+28h] [rbp-C0h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+38h] [rbp-B0h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+48h] [rbp-A0h] BYREF
  wchar_t SourceString[32]; // [rsp+78h] [rbp-70h] BYREF

  swprintf(SourceString, asc_280070910);
  RtlInitUnicodeString(&DestinationString, SourceString);
  v4 = 65;
  while ( 1 )
  {
    DestinationString.Buffer[4] = v4;
    ObjectAttributes.Length = 48;
    ObjectAttributes.RootDirectory = nullptr;
    ObjectAttributes.Attributes = 64;
    ObjectAttributes.ObjectName = &DestinationString;
    ObjectAttributes.SecurityDescriptor = nullptr;
    ObjectAttributes.SecurityQualityOfService = nullptr;
    if ( ZwOpenSymbolicLinkObject(&LinkHandle, 0x80000000, &ObjectAttributes) >= 0 )
      break;
LABEL_8:
    if ( ++v4 > 0x5Au )
      return 3221225473LL;
  }
  LinkTarget.MaximumLength = 400;
  LinkTarget.Length = 0;
  LinkTarget.Buffer = (PWSTR)ExAllocatePool(PagedPool, 0x190u);
  if ( LinkTarget.Buffer == nullptr )
  {
    ZwClose(LinkHandle);
    goto LABEL_8;
  }
  v5 = ZwQuerySymbolicLinkObject(LinkHandle, &LinkTarget, nullptr);
  ZwClose(LinkHandle);
  if ( v5 < 0 || RtlEqualUnicodeString(&LinkTarget, String2, 1u) == 0 )
  {
    ExFreePoolWithTag(LinkTarget.Buffer, 0);
    goto LABEL_8;
  }
  ExFreePoolWithTag(LinkTarget.Buffer, 0);
  Pool = ExAllocatePool(PagedPool, 6u);
  *(_QWORD *)(a2 + 8) = Pool;
  if ( Pool == nullptr )
    return 3221225626LL;
  *(_WORD *)(a2 + 2) = 6;
  *(_WORD *)a2 = 4;
  *Pool = v4;
  *(_WORD *)(*(_QWORD *)(a2 + 8) + 2LL) = 58;
  *(_WORD *)(*(_QWORD *)(a2 + 8) + 4LL) = 0;
  return 0;
}


// ===== sub_28006C0EC @ 0x28006c0ec size=0x28a =====
__int64 __fastcall sub_28006C0EC(__int64 a1, __int64 a2, const UNICODE_STRING *a3, __int64 a4, int a5, _BYTE *a6)
{
  int v9; // esi
  __int64 result; // rax
  __int64 v11; // rdx
  const UNICODE_STRING *v12; // rdx
  __int64 Length; // rdx
  unsigned __int16 *v14; // rbx
  const WCHAR *v15; // rdx
  PSLIST_ENTRY v16; // rbp
  int v17; // eax
  unsigned __int16 v18; // ax
  __int64 v19; // rdx
  unsigned __int64 v20; // rcx
  int v21; // eax
  PSLIST_ENTRY ListEntry; // [rsp+20h] [rbp-48h] BYREF

  v9 = 0;
  if ( a3[2].Length == 0 )
  {
    result = sub_28006BF24(a3 + 3, (__int64)&a3[2]);
    v9 = result;
    if ( (int)result < 0 )
    {
      a3[2].Length = 0;
      return result;
    }
  }
  if ( *(_DWORD *)(*(_QWORD *)&a3->Length + 72LL) == 20 || (_WORD)(v11 = a3[2].Length) == 0 )
  {
    Length = a3[3].Length;
    if ( _bittest((const signed __int32 *)(a1 + 80), 0xBu) )
    {
      if ( (int)sub_28006C92C(a2, Length) < 0 )
        goto LABEL_26;
      RtlCopyUnicodeString((PUNICODE_STRING)(a2 + 8), a3 + 3);
      goto LABEL_11;
    }
    if ( (int)sub_28006C92C(a2, Length) < 0 )
      goto LABEL_26;
    v12 = a3 + 3;
  }
  else
  {
    if ( (int)sub_28006C92C(a2, v11) < 0 )
      goto LABEL_26;
    v12 = a3 + 2;
  }
  v14 = (unsigned __int16 *)(a2 + 8);
  RtlCopyUnicodeString((PUNICODE_STRING)(a2 + 8), v12);
  if ( KeGetCurrentIrql() > 1u )
  {
    sub_28006C92C(a2, (unsigned __int16)(*v14 + 38));
    v15 = L"[-=At DPC Level=-]";
LABEL_16:
    RtlAppendUnicodeToString((PUNICODE_STRING)(a2 + 8), v15);
    *a6 = 0;
    return 3221225473LL;
  }
  if ( IoGetTopLevelIrp() == nullptr )
  {
    if ( !_bittest((const signed __int32 *)(a1 + 80), 0x16u) )
    {
      v9 = sub_28006C80C(&ListEntry, &Lookaside);
      if ( v9 < 0 )
        goto LABEL_26;
      v16 = ListEntry;
      v17 = sub_28006C37C(a1, a3->Buffer, ListEntry);
      v9 = v17;
      if ( v17 < 0 )
      {
        v21 = _snwprintf(
                (wchar_t *)v16[1].Next,
                LODWORD(v16[2].Next),
                L"[-=Error 0x%x Getting Name=-]",
                (unsigned int)v17);
        if ( v21 < 0 )
          LOWORD(v21) = 0;
        *((_WORD *)&v16->Next + 4) = v21;
        if ( (int)sub_28006C92C(a2, (unsigned __int16)(*v14 + v21)) >= 0 )
        {
          RtlAppendUnicodeStringToString((PUNICODE_STRING)(a2 + 8), (PCUNICODE_STRING)(&v16->Next + 1));
          sub_28006C8A8(v16);
          return 3221225473LL;
        }
        goto LABEL_25;
      }
      if ( (int)sub_28006C92C(a2, (unsigned __int16)(*v14 + *((_WORD *)&v16->Next + 4))) < 0 )
      {
LABEL_25:
        sub_28006C8A8(v16);
        goto LABEL_26;
      }
      RtlAppendUnicodeStringToString((PUNICODE_STRING)(a2 + 8), (PCUNICODE_STRING)(&v16->Next + 1));
      sub_28006C8A8(v16);
    }
    v18 = *v14;
    if ( *v14 >= 4u )
    {
      v19 = *(_QWORD *)(a2 + 16);
      v20 = (unsigned __int64)v18 >> 1;
      if ( *(_WORD *)(v19 + 2 * v20 - 2) == 92 && *(_WORD *)(v19 + 2 * v20 - 4) != 58 )
        *v14 = v18 - 2;
    }
LABEL_11:
    *a6 = 1;
    return 0;
  }
  if ( (int)sub_28006C92C(a2, (unsigned __int16)(*v14 + 46)) >= 0 )
  {
    v15 = L"[-=Nested Operation=-]";
    goto LABEL_16;
  }
LABEL_26:
  *(_WORD *)(a2 + 8) = 0;
  return (unsigned int)v9;
}


// ===== sub_28006C37C @ 0x28006c37c size=0x1ef =====
__int64 __fastcall sub_28006C37C(struct _FILE_OBJECT *a1, struct _DEVICE_OBJECT *a2, __int64 a3)
{
  struct _IRP *PoolWithTag; // rdi
  int v7; // ebx
  struct _IO_STACK_LOCATION *CurrentStackLocation; // rcx
  struct _IO_STACK_LOCATION *v9; // r11
  unsigned int v10; // ebx
  struct _IRP *P; // [rsp+30h] [rbp-58h]
  PIRP Irp; // [rsp+38h] [rbp-50h]
  int v14; // [rsp+40h] [rbp-48h] BYREF
  __int64 v15; // [rsp+48h] [rbp-40h]
  struct _KEVENT Event; // [rsp+50h] [rbp-38h] BYREF
  int v17; // [rsp+A8h] [rbp+20h]

  v17 = 256;
  PoolWithTag = (struct _IRP *)ExAllocatePoolWithTag(PagedPool, 0x100u, 0x74506C4Eu);
  P = PoolWithTag;
  if ( PoolWithTag != nullptr )
  {
    while ( 1 )
    {
      Irp = IoAllocateIrp(a2->StackSize, 0);
      if ( Irp == nullptr )
      {
        v7 = -1073741670;
        goto LABEL_14;
      }
      Irp->Tail.Overlay.Thread = KeGetCurrentThread();
      Irp->RequestorMode = 0;
      v14 = 0;
      v15 = 0;
      Irp->UserIosb = (PIO_STATUS_BLOCK)&v14;
      Irp->UserEvent = nullptr;
      Irp->Flags = 4;
      CurrentStackLocation = Irp->Tail.Overlay.CurrentStackLocation;
      CurrentStackLocation[-1].MajorFunction = 5;
      CurrentStackLocation[-1].FileObject = a1;
      PoolWithTag = P;
      Irp->AssociatedIrp.MasterIrp = P;
      CurrentStackLocation[-1].Parameters.Read.Length = v17;
      CurrentStackLocation[-1].Parameters.Create.Options = 9;
      KeInitializeEvent(&Event, NotificationEvent, 0);
      v9 = Irp->Tail.Overlay.CurrentStackLocation;
      v9[-1].CompletionRoutine = (PIO_COMPLETION_ROUTINE)&sub_28006C574;
      v9[-1].Context = &Event;
      v9[-1].Control = 0;
      v9[-1].Control = 64;
      v9[-1].Control = -64;
      v9[-1].Control = -32;
      if ( IofCallDriver(a2, Irp) == 259 )
        KeWaitForSingleObject(&Event, Executive, 0, 0, nullptr);
      v7 = v14;
      if ( v14 >= 0 )
        break;
      if ( v14 != -2147483643 )
        goto LABEL_14;
      v10 = (unsigned __int16)P->Type + 4;
      v17 = v10;
      ExFreePoolWithTag(P, 0x74506C4Eu);
      PoolWithTag = (struct _IRP *)ExAllocatePoolWithTag(PagedPool, v10, 0x74506C4Eu);
      P = PoolWithTag;
      if ( PoolWithTag == nullptr )
      {
        v7 = -1073741670;
        goto LABEL_14;
      }
    }
    v7 = sub_28006C92C(a3, (unsigned __int16)P->Type);
    if ( v7 >= 0 )
    {
      memmove(*(void **)(a3 + 16), &P->Size + 1, *(unsigned int *)&P->Type);
      *(_WORD *)(a3 + 8) = P->Type;
    }
  }
  else
  {
    v7 = -1073741670;
  }
LABEL_14:
  if ( PoolWithTag != nullptr )
    ExFreePoolWithTag(PoolWithTag, 0x74506C4Eu);
  return (unsigned int)v7;
}


// ===== sub_28006C574 @ 0x28006c574 size=0x38 =====
__int64 __fastcall sub_28006C574(__int64 a1, __int64 a2, struct _KEVENT *a3)
{
  *(__m128i *)*(_QWORD *)(a2 + 72) = _mm_loadu_si128((const __m128i *)(a2 + 48));
  KeSetEvent(a3, 0, 0);
  IoFreeIrp((PIRP)a2);
  return 3221225494LL;
}


// ===== sub_28006C5B4 @ 0x28006c5b4 size=0x36 =====
__int64 __fastcall sub_28006C5B4(PVOID Object)
{
  __int64 v3; // [rsp+40h] [rbp+18h] BYREF

  if ( (int)sub_28006C80C(&v3, &Lookaside) >= 0 )
    sub_28006C5F0(Object);
  return v3;
}


// ===== sub_28006C5F0 @ 0x28006c5f0 size=0xc9 =====
__int64 __fastcall sub_28006C5F0(PVOID Object, __int64 a2)
{
  struct _OBJECT_NAME_INFORMATION *v2; // rsi
  ULONG v3; // r8d
  NTSTATUS v6; // edi
  __int64 result; // rax
  void *v8; // rcx
  int v9; // eax
  size_t Length; // rax
  ULONG ReturnLength; // [rsp+48h] [rbp+10h] BYREF

  v2 = *(struct _OBJECT_NAME_INFORMATION **)(a2 + 16);
  v3 = *(unsigned __int16 *)(a2 + 10);
  ReturnLength = 0;
  v6 = ObQueryNameString(Object, v2, v3, &ReturnLength);
  if ( v6 == -1073741820 )
  {
    result = sub_28006C960(a2, ReturnLength, 0);
    if ( (int)result < 0 )
    {
      *(_WORD *)(a2 + 8) = 0;
      return result;
    }
    v2 = *(struct _OBJECT_NAME_INFORMATION **)(a2 + 16);
    v6 = ObQueryNameString(Object, v2, *(unsigned __int16 *)(a2 + 10), &ReturnLength);
  }
  v8 = *(void **)(a2 + 16);
  if ( v6 >= 0 )
  {
    Length = v2->Name.Length;
    *(_WORD *)(a2 + 8) = Length;
    memmove(v8, v2->Name.Buffer, Length);
  }
  else
  {
    v9 = _snwprintf((wchar_t *)v8, *(unsigned __int16 *)(a2 + 10), L"[-=Error 0x%x Getting Name=-]", (unsigned int)v6);
    if ( v9 < 0 )
      LOWORD(v9) = 0;
    *(_WORD *)(a2 + 8) = v9;
  }
  return (unsigned int)v6;
}


// ===== sub_28006C6C0 @ 0x28006c6c0 size=0xbb =====
void __fastcall sub_28006C6C0(PVOID P)
{
  __int64 v1; // rdi
  void *v3; // rcx
  _WORD *v4; // rcx

  v1 = *((_QWORD *)P + 5);
  v3 = *(void **)(v1 + 16);
  if ( v3 != nullptr )
  {
    if ( RtlVolumeDeviceToDosName(v3, (PUNICODE_STRING)(v1 + 32)) >= 0 )
    {
      if ( *(_WORD *)(v1 + 32) > 4u )
      {
        v4 = *(_WORD **)(v1 + 40);
        if ( *v4 == 92 && v4[1] == 92 && v4[2] == 63 && v4[3] == 92 )
        {
          *(_WORD *)(v1 + 32) = 0;
          ExFreePoolWithTag(v4, 0);
          *(_QWORD *)(v1 + 40) = 0;
        }
      }
    }
    else
    {
      *(_WORD *)(v1 + 32) = 0;
    }
    ObfDereferenceObject(*((PVOID *)P + 4));
    ExFreePoolWithTag(P, 0x74506C4Eu);
  }
  else
  {
    ObfDereferenceObject(*((PVOID *)P + 4));
    ExFreePoolWithTag(P, 0x74506C4Eu);
    *(_WORD *)(v1 + 32) = 0;
  }
}


// ===== sub_28006C784 @ 0x28006c784 size=0x80 =====
__int64 __fastcall sub_28006C784(PUNICODE_STRING DestinationString, PCUNICODE_STRING SourceString)
{
  SIZE_T Length; // rdi
  WCHAR *PoolWithTag; // rax

  Length = SourceString->Length;
  if ( SourceString->Length != 0 )
  {
    PoolWithTag = (WCHAR *)ExAllocatePoolWithTag(PagedPool, Length, 0x6E765450u);
    DestinationString->Length = 0;
    DestinationString->MaximumLength = Length;
    if ( PoolWithTag == nullptr )
    {
      DestinationString->Buffer = nullptr;
      return 3221225626LL;
    }
    DestinationString->Buffer = PoolWithTag;
    RtlCopyUnicodeString(DestinationString, SourceString);
  }
  else
  {
    DestinationString->Length = 0;
    DestinationString->MaximumLength = Length;
    DestinationString->Buffer = nullptr;
  }
  return 0;
}


// ===== sub_28006C80C @ 0x28006c80c size=0x95 =====
__int64 __fastcall sub_28006C80C(PSLIST_ENTRY *a1)
{
  PSLIST_ENTRY v2; // r11
  __int16 Next; // ax

  ++dword_280074914;
  v2 = ExpInterlockedPopEntrySList(&Lookaside);
  if ( v2 != nullptr
    || (++dword_280074918,
        (v2 = (PSLIST_ENTRY)qword_280074930(
                              (unsigned int)dword_280074924,
                              (unsigned int)dword_28007492C,
                              (unsigned int)dword_280074928)) != nullptr) )
  {
    LODWORD(v2[2].Next) = 254;
    Next = (__int16)v2[2].Next;
    LODWORD(v2->Next) = 1;
    *((_QWORD *)&v2[1].Next + 1) = 0;
    *((_WORD *)&v2->Next + 5) = Next;
    v2[1].Next = (PSLIST_ENTRY)((char *)v2 + 40);
    *((_WORD *)&v2->Next + 4) = 0;
    *a1 = v2;
    return 0;
  }
  else
  {
    *a1 = nullptr;
    return 3221225626LL;
  }
}


// ===== sub_28006C8A8 @ 0x28006c8a8 size=0x7c =====
char __fastcall sub_28006C8A8(volatile signed __int32 *ListEntry)
{
  void *v2; // rcx

  if ( ListEntry == nullptr || _InterlockedExchangeAdd(ListEntry, 0xFFFFFFFF) != 1 )
    return 0;
  v2 = *((void **)ListEntry + 3);
  if ( v2 != nullptr )
  {
    ExFreePoolWithTag(v2, 0x74506C4Eu);
    *((_QWORD *)ListEntry + 3) = 0;
  }
  ++dword_28007491C;
  if ( ExQueryDepthSList(&Lookaside) < (unsigned __int16)word_280074910 )
  {
    ExpInterlockedPushEntrySList(&Lookaside, (PSLIST_ENTRY)ListEntry);
  }
  else
  {
    ++dword_280074920;
    qword_280074938(ListEntry);
  }
  return 1;
}


// ===== sub_28006C92C @ 0x28006c92c size=0x2b =====
__int64 __fastcall sub_28006C92C(__int64 a1, unsigned __int16 a2)
{
  if ( a2 <= (unsigned __int64)*(unsigned int *)(a1 + 32) - 2 )
    return 0;
  else
    return sub_28006C960(a1, (unsigned int)a2 + 2, 0);
}


// ===== sub_28006C960 @ 0x28006c960 size=0x99 =====
__int64 __fastcall sub_28006C960(__int64 a1, unsigned int a2)
{
  unsigned int v2; // edi
  PVOID PoolWithTag; // rax
  PVOID v5; // rsi
  void *v7; // rcx

  v2 = a2;
  PoolWithTag = ExAllocatePoolWithTag(PagedPool, a2, 0x74506C4Eu);
  v5 = PoolWithTag;
  if ( PoolWithTag == nullptr )
    return 3221225626LL;
  if ( *(_WORD *)(a1 + 8) != 0 )
    memmove(PoolWithTag, *(const void **)(a1 + 16), *(unsigned __int16 *)(a1 + 8));
  v7 = *(void **)(a1 + 24);
  if ( v7 != nullptr )
    ExFreePoolWithTag(v7, 0x74506C4Eu);
  *(_DWORD *)(a1 + 32) = v2;
  *(_QWORD *)(a1 + 24) = v5;
  *(_QWORD *)(a1 + 16) = v5;
  if ( v2 > 0xFFF0 )
    LOWORD(v2) = -16;
  *(_WORD *)(a1 + 10) = v2;
  return 0;
}


// ===== sub_28006CA00 @ 0x28006ca00 size=0x74 =====
__int64 __fastcall sub_28006CA00(_DWORD *a1, __int64 a2)
{
  _DWORD *v2; // r9
  int *v4; // rcx
  int i; // eax
  __int64 v6; // r11
  __int64 v7; // r10
  __int64 v8; // r8
  char v9; // al
  int v10; // edx
  unsigned __int8 v11; // al
  __int64 result; // rax

  v2 = a1 + 2;
  *a1 = 0;
  a1[1] = 0;
  v4 = a1 + 2;
  for ( i = 0; i < 256; ++i )
    *v4++ = i;
  LOBYTE(v6) = 0;
  v7 = 0;
  v8 = 0;
  do
  {
    v9 = *(_BYTE *)(v8 + a2);
    v10 = v2[v7];
    ++v8;
    v11 = v10 + v6 + v9;
    v6 = v11;
    if ( v8 >= 8 )
      v8 = 0;
    result = (unsigned int)v2[v11];
    v2[v7++] = result;
    v2[v6] = v10;
  }
  while ( v7 < 256 );
  return result;
}


// ===== sub_28006CA7C @ 0x28006ca7c size=0x64 =====
__int64 __fastcall sub_28006CA7C(_DWORD *a1, __int64 a2)
{
  __int64 v2; // r10
  __int64 v3; // r11
  __int64 i; // rbx
  int v6; // r8d
  int v7; // ecx
  __int64 result; // rax

  LODWORD(v2) = *a1;
  LODWORD(v3) = a1[1];
  for ( i = 0; i < 504; ++i )
  {
    v2 = (unsigned __int8)(v2 + 1);
    v6 = a1[v2 + 2];
    v3 = (unsigned __int8)(v6 + v3);
    v7 = a1[v3 + 2];
    a1[v2 + 2] = v7;
    a1[v3 + 2] = v6;
    result = (unsigned __int8)(v6 + v7);
    *(_BYTE *)(i + a2) ^= LOBYTE(a1[result + 2]);
  }
  *a1 = v2;
  a1[1] = v3;
  return result;
}


// ===== sub_28006CAE8 @ 0x28006cae8 size=0x110 =====
__int64 __fastcall sub_28006CAE8(int a1)
{
  if ( dword_280075008 != 0 )
    return 3221225473LL;
  dword_280075008 = 1;
  if ( dword_280074FB4 == 0 || qword_280074C00 == nullptr || qword_280074C08 == 0 || qword_280074C10 == 0 )
    return 3221225473LL;
  RtlInitUnicodeString(&DestinationString, aRegistryMachin_0);
  RtlInitUnicodeString(&stru_280075040, aRegistryMachin_1);
  RtlInitUnicodeString(&stru_280075080, aRegistryMachin_2);
  RtlInitUnicodeString(&stru_280075050, aRegistryMachin_3);
  RtlInitUnicodeString(&stru_280075030, aRegistryUser);
  qword_280075028 = (__int64)&P;
  P = &P;
  dword_28007500C = a1;
  ExInitializeResourceLite(&stru_2800750A0);
  sub_28006D600(&qword_280075000);
  qword_280074C00(sub_28006CC00, 0, &unk_280075060);
  return 0;
}


// ===== sub_28006CC00 @ 0x28006cc00 size=0x7b8 =====
__int64 __fastcall sub_28006CC00(__int64 a1, int a2, __int64 a3)
{
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  PVOID v11; // rdi
  char v12; // al
  __int64 v13; // rax
  struct _SINGLE_LIST_ENTRY *v14; // rdi
  struct _SINGLE_LIST_ENTRY *v15; // rcx
  void *v16; // rdi
  char v17; // al
  PVOID v18; // rdi
  __int64 v19; // rcx
  char v20; // al
  __int64 v21; // rax
  __int64 v22; // rdi
  PVOID v23; // rdi
  char v24; // al
  __int64 v25; // rax
  __int64 v26; // rdi
  PVOID v27; // rdi
  char v28; // al
  int v29; // edi
  int v30; // edi
  int v31; // edi
  int v32; // edi
  PVOID v33; // rdi
  char v34; // al
  __int64 v35; // r12
  PVOID v36; // rdi
  char v37; // al
  PVOID v38; // rdi
  char v39; // al
  unsigned int v40; // [rsp+20h] [rbp-68h]
  UNICODE_STRING SourceString; // [rsp+28h] [rbp-60h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+38h] [rbp-50h] BYREF
  struct _UNICODE_STRING Expression; // [rsp+48h] [rbp-40h] BYREF
  struct _UNICODE_STRING v44; // [rsp+58h] [rbp-30h] BYREF
  struct _UNICODE_STRING v45; // [rsp+68h] [rbp-20h] BYREF

  v40 = 0;
  SourceString.Length = 0;
  SourceString.MaximumLength = 1024;
  SourceString.Buffer = (PWSTR)ExAllocatePoolWithTag(NonPagedPool, 0x400u, 0x67725450u);
  if ( SourceString.Buffer == nullptr )
    return 0;
  if ( a2 <= 17 )
  {
    if ( a2 == 17 )
    {
      if ( *(int *)(a3 + 8) < 0 )
        goto LABEL_111;
      v27 = *(PVOID *)a3;
      v28 = MmIsAddressValid(*(PVOID *)a3) != 0 ? sub_28006D3C0(&SourceString, v27) : 0;
      if ( v28 == 0 )
        goto LABEL_111;
      KeEnterCriticalRegion();
      ExAcquireResourceSharedLite(&stru_2800750A0, 1u);
      if ( qword_280075010 == 0 )
        goto LABEL_107;
      if ( (unsigned __int8)sub_28006DED0(&SourceString) != 0 )
      {
        v13 = sub_28006D718(0);
        v14 = (struct _SINGLE_LIST_ENTRY *)v13;
        if ( v13 != 0 )
          goto LABEL_110;
      }
    }
    else
    {
      if ( a2 == 0 )
      {
        v23 = *(PVOID *)a3;
        if ( MmIsAddressValid(*(PVOID *)a3) != 0 )
          v24 = sub_28006D3C0(&SourceString, v23);
        else
          v24 = 0;
        if ( v24 == 0 )
          goto LABEL_111;
        KeEnterCriticalRegion();
        ExAcquireResourceSharedLite(&stru_2800750A0, 1u);
        if ( qword_280075010 != 0 )
        {
          if ( (unsigned __int8)sub_28006DED0(&SourceString) != 0 )
          {
            v25 = sub_28006D718(0);
            v26 = v25;
            if ( v25 != 0 )
            {
              RtlCopyUnicodeString((PUNICODE_STRING)(v25 + 24), &SourceString);
              *(_QWORD *)(a3 + 8) = v26;
            }
          }
          goto LABEL_111;
        }
        goto LABEL_107;
      }
      v6 = a2 - 4;
      if ( v6 == 0 )
      {
        v18 = *(PVOID *)a3;
        if ( MmIsAddressValid(*(PVOID *)a3) != 0 )
          v20 = sub_28006D3C0(&SourceString, v18);
        else
          v20 = 0;
        if ( v20 != 0 )
        {
          LOBYTE(v19) = 1;
          v21 = sub_28006D718(v19);
          v22 = v21;
          if ( v21 != 0 )
          {
            RtlCopyUnicodeString((PUNICODE_STRING)(v21 + 8), &SourceString);
            *(_QWORD *)(a3 + 16) = v22;
          }
        }
        goto LABEL_111;
      }
      v7 = v6 - 6;
      if ( v7 == 0 )
      {
        RtlInitUnicodeString(&Expression, L"*\\REGISTRY.SD.*");
        if ( FsRtlIsNameInExpression(&Expression, *(PUNICODE_STRING *)a3, 1u, nullptr) != 0
          && KeGetCurrentThread() != *(struct _KTHREAD **)qword_280075000 )
        {
          v40 = -1073741790;
        }
        goto LABEL_111;
      }
      v8 = v7 - 1;
      if ( v8 != 0 )
      {
        v9 = v8 - 1;
        if ( v9 == 0 )
        {
          RtlInitUnicodeString(&DestinationString, L"*\\REGISTRY.SD.*");
          if ( FsRtlIsNameInExpression(&DestinationString, *(PUNICODE_STRING *)a3, 1u, nullptr) != 0
            && KeGetCurrentThread() != *(struct _KTHREAD **)qword_280075000 )
          {
            v40 = -1073741790;
          }
          goto LABEL_111;
        }
        v10 = v9 - 3;
        if ( v10 == 0 )
        {
          v15 = *(struct _SINGLE_LIST_ENTRY **)(a3 + 32);
          if ( v15 != nullptr )
          {
            *(_QWORD *)(a3 + 32) = 0;
            if ( *(int *)(a3 + 8) < 0 )
              sub_28006D7B4(v15);
            else
              sub_28006D800(v15);
          }
          goto LABEL_111;
        }
        if ( v10 == 1 && *(int *)(a3 + 8) >= 0 )
        {
          v11 = *(PVOID *)a3;
          v12 = MmIsAddressValid(*(PVOID *)a3) != 0 ? sub_28006D3C0(&SourceString, v11) : 0;
          if ( v12 != 0 )
          {
            KeEnterCriticalRegion();
            ExAcquireResourceSharedLite(&stru_2800750A0, 1u);
            if ( qword_280075010 == 0 )
              goto LABEL_107;
            if ( (unsigned __int8)sub_28006DED0(&SourceString) != 0 )
            {
              v13 = sub_28006D718(0);
              v14 = (struct _SINGLE_LIST_ENTRY *)v13;
              if ( v13 != 0 )
                goto LABEL_110;
            }
          }
        }
      }
      else
      {
        if ( *(int *)(a3 + 16) < 0 )
          goto LABEL_111;
        v16 = *(void **)(a3 + 8);
        v17 = MmIsAddressValid(v16) != 0 ? sub_28006D3C0(&SourceString, v16) : 0;
        if ( v17 == 0 )
          goto LABEL_111;
        KeEnterCriticalRegion();
        ExAcquireResourceSharedLite(&stru_2800750A0, 1u);
        if ( qword_280075010 == 0 )
          goto LABEL_107;
        if ( (unsigned __int8)sub_28006DED0(&SourceString) != 0 )
        {
          v13 = sub_28006D718(0);
          v14 = (struct _SINGLE_LIST_ENTRY *)v13;
          if ( v13 != 0 )
            goto LABEL_110;
        }
      }
    }
    goto LABEL_111;
  }
  v29 = a2 - 18;
  if ( v29 == 0 )
  {
    if ( *(int *)(a3 + 8) < 0 )
      goto LABEL_111;
    v38 = *(PVOID *)a3;
    v39 = MmIsAddressValid(*(PVOID *)a3) != 0 ? sub_28006D3C0(&SourceString, v38) : 0;
    if ( v39 == 0 )
      goto LABEL_111;
    KeEnterCriticalRegion();
    ExAcquireResourceSharedLite(&stru_2800750A0, 1u);
    if ( qword_280075010 == 0 )
      goto LABEL_107;
    if ( (unsigned __int8)sub_28006DED0(&SourceString) != 0 )
    {
      v13 = sub_28006D718(0);
      v14 = (struct _SINGLE_LIST_ENTRY *)v13;
      if ( v13 != 0 )
        goto LABEL_110;
    }
    goto LABEL_111;
  }
  v30 = v29 - 1;
  if ( v30 == 0 )
  {
    v35 = *(_QWORD *)(a3 + 32);
    if ( v35 == 0 )
      goto LABEL_111;
    *(_QWORD *)(a3 + 32) = 0;
    if ( *(int *)(a3 + 8) < 0 )
    {
      sub_28006D7B4(v35);
      goto LABEL_111;
    }
    v36 = *(PVOID *)a3;
    if ( MmIsAddressValid(*(PVOID *)a3) != 0 )
      v37 = sub_28006D3C0(&SourceString, v36);
    else
      v37 = 0;
    if ( v37 == 0 )
    {
LABEL_97:
      sub_28006D7B4(v35);
      goto LABEL_111;
    }
    KeEnterCriticalRegion();
    ExAcquireResourceSharedLite(&stru_2800750A0, 1u);
    if ( qword_280075010 != 0 )
    {
      if ( (unsigned __int8)sub_28006DED0((PUNICODE_STRING)(v35 + 8)) != 0 )
        goto LABEL_98;
    }
    else
    {
      ExReleaseResourceLite(&stru_2800750A0);
      KeLeaveCriticalRegion();
    }
    KeEnterCriticalRegion();
    ExAcquireResourceSharedLite(&stru_2800750A0, 1u);
    if ( qword_280075010 == 0 )
    {
      ExReleaseResourceLite(&stru_2800750A0);
      KeLeaveCriticalRegion();
      goto LABEL_97;
    }
    if ( (unsigned __int8)sub_28006DED0(&SourceString) == 0 )
      goto LABEL_97;
LABEL_98:
    RtlCopyUnicodeString((PUNICODE_STRING)(v35 + 24), &SourceString);
    sub_28006D800((PSINGLE_LIST_ENTRY)v35);
    goto LABEL_111;
  }
  v31 = v30 - 7;
  if ( v31 == 0 )
  {
    RtlInitUnicodeString(&v45, L"REGISTRY.SD.*");
    if ( FsRtlIsNameInExpression(&v45, *(PUNICODE_STRING *)a3, 1u, nullptr) != 0
      && KeGetCurrentThread() != *(struct _KTHREAD **)qword_280075000 )
    {
      v40 = -1073741790;
    }
    goto LABEL_111;
  }
  v32 = v31 - 1;
  if ( v32 != 0 )
  {
    if ( v32 == 1 )
    {
      RtlInitUnicodeString(&v44, L"REGISTRY.SD.*");
      if ( FsRtlIsNameInExpression(&v44, *(PUNICODE_STRING *)a3, 1u, nullptr) != 0
        && KeGetCurrentThread() != *(struct _KTHREAD **)qword_280075000 )
      {
        v40 = -1073741790;
      }
    }
    goto LABEL_111;
  }
  if ( *(_DWORD *)(a3 + 8) == 0 )
  {
    v33 = *(PVOID *)a3;
    v34 = MmIsAddressValid(*(PVOID *)a3) != 0 ? sub_28006D3C0(&SourceString, v33) : 0;
    if ( v34 != 0 )
    {
      KeEnterCriticalRegion();
      ExAcquireResourceSharedLite(&stru_2800750A0, 1u);
      if ( qword_280075010 == 0 )
      {
LABEL_107:
        ExReleaseResourceLite(&stru_2800750A0);
        KeLeaveCriticalRegion();
        goto LABEL_111;
      }
      if ( (unsigned __int8)sub_28006DED0(&SourceString) != 0 )
      {
        v13 = sub_28006D718(0);
        v14 = (struct _SINGLE_LIST_ENTRY *)v13;
        if ( v13 != 0 )
        {
LABEL_110:
          RtlCopyUnicodeString((PUNICODE_STRING)(v13 + 24), &SourceString);
          sub_28006D800(v14);
        }
      }
    }
  }
LABEL_111:
  if ( SourceString.Buffer != nullptr )
    ExFreePoolWithTag(SourceString.Buffer, 0x67725450u);
  return v40;
}


// ===== sub_28006D3C0 @ 0x28006d3c0 size=0xaa =====
char __fastcall sub_28006D3C0(PUNICODE_STRING DestinationString, PVOID Object)
{
  char v2; // bl
  struct _OBJECT_NAME_INFORMATION *PoolWithTag; // rax
  UNICODE_STRING *p_Name; // rdi
  ULONG ReturnLength; // [rsp+38h] [rbp+10h] BYREF

  v2 = 0;
  if ( Object == nullptr )
    return 0;
  ReturnLength = 0;
  if ( ObQueryNameString(Object, nullptr, 0, &ReturnLength) == -1073741820 )
  {
    PoolWithTag = (struct _OBJECT_NAME_INFORMATION *)ExAllocatePoolWithTag(NonPagedPool, ReturnLength, 0x67725450u);
    p_Name = &PoolWithTag->Name;
    if ( PoolWithTag == nullptr )
      return 0;
    if ( ObQueryNameString(Object, PoolWithTag, ReturnLength, &ReturnLength) >= 0 )
    {
      RtlCopyUnicodeString(DestinationString, p_Name);
      v2 = 1;
    }
    ExFreePoolWithTag(p_Name, 0x67725450u);
  }
  return v2;
}


// ===== StartRoutine @ 0x28006d470 size=0x189 =====
void __fastcall StartRoutine(char *StartContext)
{
  PSINGLE_LIST_ENTRY v2; // rax
  PSINGLE_LIST_ENTRY v3; // rdi
  char *i; // rbx
  void *v5; // rcx
  struct _OBJECT_ATTRIBUTES KeyObjectAttributes; // [rsp+30h] [rbp-48h] BYREF
  __int64 v7; // [rsp+80h] [rbp+8h] BYREF
  __int64 v8; // [rsp+88h] [rbp+10h] BYREF

  v8 = 0;
  v7 = 0;
  KeSetPriorityThread(KeGetCurrentThread(), 16);
  sub_280052014((__int64)KeGetCurrentThread());
  do
  {
    KeWaitForSingleObject(StartContext + 8, Executive, 0, 0, nullptr);
    while ( 1 )
    {
      v2 = ExInterlockedPopEntryList((PSINGLE_LIST_ENTRY)StartContext + 5, (PKSPIN_LOCK)StartContext + 6);
      v3 = v2;
      if ( v2 == nullptr )
        break;
      if ( (int)sub_28006E208(&v2[3], &v8, &v7) >= 0 )
        sub_28006D8C4(v3, v8, v7);
      sub_28006D7B4(v3);
    }
  }
  while ( StartContext[32] == 0 );
  for ( i = (char *)P; P != &P; i = (char *)P )
  {
    P = *(PVOID *)i;
    *((_QWORD *)P + 1) = &P;
    if ( i[64] != 0 )
    {
      KeyObjectAttributes.RootDirectory = nullptr;
      KeyObjectAttributes.SecurityDescriptor = nullptr;
      KeyObjectAttributes.SecurityQualityOfService = nullptr;
      KeyObjectAttributes.Length = 48;
      KeyObjectAttributes.ObjectName = (PUNICODE_STRING)(i + 48);
      KeyObjectAttributes.Attributes = 512;
      ZwUnloadKey(&KeyObjectAttributes);
    }
    v5 = *((void **)i + 3);
    if ( v5 != nullptr )
      ExFreePoolWithTag(v5, 0x67725450u);
    ExFreePoolWithTag(*((PVOID *)i + 5), 0x67725450u);
    ExFreePoolWithTag(*((PVOID *)i + 7), 0x67725450u);
    ExFreePoolWithTag(i, 0x67725450u);
  }
  sub_2800520DC((__int64)KeGetCurrentThread());
  PsTerminateSystemThread(0);
}


// ===== sub_28006D600 @ 0x28006d600 size=0x112 =====
__int64 sub_28006D600()
{
  char *PoolWithTag; // rax
  _BYTE *StartContext; // rbx
  NTSTATUS v3; // edi
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+40h] [rbp-38h] BYREF
  void *ThreadHandle; // [rsp+88h] [rbp+10h] BYREF

  PoolWithTag = (char *)ExAllocatePoolWithTag(NonPagedPool, 0x38u, 0x67725450u);
  StartContext = PoolWithTag;
  if ( PoolWithTag == nullptr )
    return 3221225626LL;
  *((_QWORD *)PoolWithTag + 5) = 0;
  *((_QWORD *)PoolWithTag + 6) = 0;
  KeInitializeEvent((PRKEVENT)(PoolWithTag + 8), SynchronizationEvent, 0);
  StartContext[32] = 0;
  memset(&ObjectAttributes.RootDirectory, 0, 20);
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.Length = 48;
  v3 = PsCreateSystemThread(
         &ThreadHandle,
         0x1FFFFFu,
         &ObjectAttributes,
         nullptr,
         nullptr,
         (PKSTART_ROUTINE)StartRoutine,
         StartContext);
  if ( v3 >= 0 )
  {
    v3 = ObReferenceObjectByHandle(ThreadHandle, 0x1FFFFFu, nullptr, 0, (PVOID *)StartContext, nullptr);
    if ( v3 >= 0 )
    {
      ZwClose(ThreadHandle);
      qword_280075000 = (__int64)StartContext;
      return (unsigned int)v3;
    }
    ZwClose(ThreadHandle);
  }
  ExFreePoolWithTag(StartContext, 0x67725450u);
  return (unsigned int)v3;
}


// ===== sub_28006D718 @ 0x28006d718 size=0x96 =====
_WORD *__fastcall sub_28006D718(char a1)
{
  _WORD *PoolWithTag; // rbx

  PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x28u, 0x67725450u);
  if ( PoolWithTag != nullptr )
  {
    PoolWithTag[4] = 0;
    PoolWithTag[5] = 0;
    *((_QWORD *)PoolWithTag + 2) = 0;
    PoolWithTag[12] = 0;
    PoolWithTag[13] = 0;
    *((_QWORD *)PoolWithTag + 4) = 0;
    if ( a1 != 0 )
    {
      PoolWithTag[5] = 1024;
      *((_QWORD *)PoolWithTag + 2) = ExAllocatePoolWithTag(NonPagedPool, 0x400u, 0x67725450u);
    }
    PoolWithTag[13] = 1024;
    *((_QWORD *)PoolWithTag + 4) = ExAllocatePoolWithTag(NonPagedPool, 0x400u, 0x67725450u);
  }
  return PoolWithTag;
}


// ===== sub_28006D7B4 @ 0x28006d7b4 size=0x45 =====
void __fastcall sub_28006D7B4(_QWORD *a1)
{
  void *v2; // rcx
  void *v3; // rcx

  v2 = (void *)a1[2];
  if ( v2 != nullptr )
    ExFreePoolWithTag(v2, 0x67725450u);
  v3 = (void *)a1[4];
  if ( v3 != nullptr )
    ExFreePoolWithTag(v3, 0x67725450u);
  ExFreePoolWithTag(a1, 0x67725450u);
}


// ===== sub_28006D800 @ 0x28006d800 size=0x39 =====
LONG __fastcall sub_28006D800(PSINGLE_LIST_ENTRY ListEntry)
{
  ExInterlockedPushEntryList((PSINGLE_LIST_ENTRY)(qword_280075000 + 40), ListEntry, (PKSPIN_LOCK)(qword_280075000 + 48));
  return KeSetEvent((PRKEVENT)(qword_280075000 + 8), 1, 0);
}


// ===== sub_28006D840 @ 0x28006d840 size=0x7b =====
bool __fastcall sub_28006D840(unsigned __int16 *a1, unsigned __int16 *a2)
{
  unsigned int v3; // r10d
  __int64 v4; // r8
  unsigned int v7; // ecx
  _WORD *v8; // rdx
  __int64 v9; // rbx
  int v10; // r9d

  v3 = *a1 >> 1;
  v4 = *a2 >> 1;
  if ( v3 < (unsigned int)v4 )
    return false;
  v7 = 0;
  if ( (_DWORD)v4 != 0 )
  {
    v8 = *((_WORD **)a1 + 1);
    v9 = *((_QWORD *)a2 + 1) - (_QWORD)v8;
    do
    {
      v10 = *v8 < 0x61u || *v8 > 0x7Au ? (unsigned __int16)*v8 : (unsigned __int16)*v8 - 32;
      if ( v10 != *(unsigned __int16 *)((char *)v8 + v9) )
        return false;
      ++v7;
      ++v8;
    }
    while ( v7 < (unsigned int)v4 );
  }
  return v3 <= (unsigned int)v4 || *(_WORD *)(*((_QWORD *)a1 + 1) + 2 * v4) == 92;
}


// ===== sub_28006D8C4 @ 0x28006d8c4 size=0x606 =====
__int64 __fastcall sub_28006D8C4(__int64 a1, unsigned __int16 *a2, const UNICODE_STRING *a3)
{
  unsigned int v3; // ebx
  char *PoolWithTag; // rdi
  ULONG v8; // esi
  unsigned __int64 v10; // rcx
  unsigned __int64 v11; // rcx
  NTSTATUS v12; // eax
  HANDLE v13; // rcx
  NTSTATUS v14; // eax
  ULONG i; // ebp
  NTSTATUS v16; // eax
  NTSTATUS v17; // eax
  NTSTATUS v18; // eax
  NTSTATUS v19; // eax
  NTSTATUS v20; // eax
  void *KeyHandle; // [rsp+40h] [rbp-B8h] BYREF
  HANDLE Handle; // [rsp+48h] [rbp-B0h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+50h] [rbp-A8h] BYREF
  struct _UNICODE_STRING Destination; // [rsp+80h] [rbp-78h] BYREF
  struct _UNICODE_STRING ValueName; // [rsp+90h] [rbp-68h] BYREF
  struct _UNICODE_STRING v26; // [rsp+A0h] [rbp-58h] BYREF
  UNICODE_STRING Source; // [rsp+B0h] [rbp-48h] BYREF
  UNICODE_STRING v28; // [rsp+C0h] [rbp-38h] BYREF
  ULONG ResultLength; // [rsp+118h] [rbp+20h] BYREF

  v3 = 0;
  PoolWithTag = nullptr;
  v8 = 32;
  Destination.Length = 0;
  Destination.MaximumLength = 1024;
  Destination.Buffer = (PWSTR)ExAllocatePoolWithTag(NonPagedPool, 0x400u, 0x67725450u);
  if ( Destination.Buffer == nullptr )
    return 3221225626LL;
  v10 = *a2;
  Source.Length = *(_WORD *)(a1 + 24) - v10;
  Source.MaximumLength = Source.Length;
  Source.Buffer = (PWSTR)(*(_QWORD *)(a1 + 32) + 2 * (v10 >> 1));
  RtlAppendUnicodeStringToString(&Destination, a3);
  RtlAppendUnicodeStringToString(&Destination, &Source);
  if ( *(_WORD *)(a1 + 8) != 0 )
  {
    v26.MaximumLength = 1024;
    v26.Length = 0;
    v26.Buffer = (PWSTR)ExAllocatePoolWithTag(NonPagedPool, 0x400u, 0x67725450u);
    if ( v26.Buffer == nullptr )
    {
      v3 = -1073741670;
      goto LABEL_55;
    }
    v11 = *a2;
    v28.Length = *(_WORD *)(a1 + 8) - v11;
    v28.MaximumLength = v28.Length;
    v28.Buffer = (PWSTR)(*(_QWORD *)(a1 + 16) + 2 * (v11 >> 1));
    RtlAppendUnicodeStringToString(&v26, a3);
    RtlAppendUnicodeStringToString(&v26, &v28);
    ObjectAttributes.Length = 48;
    ObjectAttributes.RootDirectory = nullptr;
    ObjectAttributes.Attributes = 64;
    ObjectAttributes.ObjectName = &v26;
    ObjectAttributes.SecurityDescriptor = nullptr;
    ObjectAttributes.SecurityQualityOfService = nullptr;
    if ( ZwOpenKey(&KeyHandle, 0x20006u, &ObjectAttributes) >= 0 )
    {
      ZwDeleteKey(KeyHandle);
      ZwClose(KeyHandle);
    }
    ExFreePoolWithTag(v26.Buffer, 0x67725450u);
  }
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 64;
  ObjectAttributes.ObjectName = (PUNICODE_STRING)(a1 + 24);
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  v12 = ZwOpenKey(&Handle, 0x1020019u, &ObjectAttributes);
  if ( v12 == -1073741444 || v12 == -1073741772 )
  {
    ObjectAttributes.Length = 48;
    ObjectAttributes.RootDirectory = nullptr;
    ObjectAttributes.ObjectName = &Destination;
    ObjectAttributes.Attributes = 64;
    ObjectAttributes.SecurityDescriptor = nullptr;
    ObjectAttributes.SecurityQualityOfService = nullptr;
    if ( ZwOpenKey(&KeyHandle, 0x20006u, &ObjectAttributes) >= 0 )
    {
      ZwDeleteKey(KeyHandle);
      goto LABEL_53;
    }
    goto LABEL_55;
  }
  if ( v12 < 0 )
    goto LABEL_55;
  ObjectAttributes.ObjectName = &Destination;
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 64;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  if ( ZwCreateKey(&KeyHandle, 0x10E0006u, &ObjectAttributes, 0, nullptr, 0, nullptr) < 0 )
  {
    v13 = Handle;
    goto LABEL_54;
  }
  while ( 1 )
  {
    if ( PoolWithTag == nullptr )
      goto LABEL_15;
    while ( 2 )
    {
      v14 = ZwEnumerateValueKey(KeyHandle, 0, KeyValueBasicInformation, PoolWithTag, v8, &ResultLength);
      if ( v14 == -2147483643 || v14 == -1073741789 )
      {
        ExFreePoolWithTag(PoolWithTag, 0x67725450u);
LABEL_15:
        v8 *= 2;
        PoolWithTag = (char *)ExAllocatePoolWithTag(NonPagedPool, v8, 0x67725450u);
        continue;
      }
      break;
    }
    if ( v14 < 0 )
      break;
    ValueName.Length = *((_WORD *)PoolWithTag + 4);
    ValueName.MaximumLength = *((_WORD *)PoolWithTag + 4);
    ValueName.Buffer = (PWSTR)(PoolWithTag + 12);
    ZwDeleteValueKey(KeyHandle, &ValueName);
  }
  for ( i = 0; ; ++i )
  {
    if ( PoolWithTag == nullptr )
      goto LABEL_23;
    while ( 2 )
    {
      v16 = ZwEnumerateValueKey(Handle, i, KeyValueFullInformation, PoolWithTag, v8, &ResultLength);
      if ( v16 == -2147483643 || v16 == -1073741789 )
      {
        ExFreePoolWithTag(PoolWithTag, 0x67725450u);
LABEL_23:
        v8 *= 2;
        PoolWithTag = (char *)ExAllocatePoolWithTag(NonPagedPool, v8, 0x67725450u);
        continue;
      }
      break;
    }
    if ( v16 < 0 )
      break;
    ValueName.Length = *((_WORD *)PoolWithTag + 8);
    ValueName.MaximumLength = *((_WORD *)PoolWithTag + 8);
    ValueName.Buffer = (PWSTR)(PoolWithTag + 20);
    ZwSetValueKey(
      KeyHandle,
      &ValueName,
      0,
      *((_DWORD *)PoolWithTag + 1),
      &PoolWithTag[*((unsigned int *)PoolWithTag + 2)],
      *((_DWORD *)PoolWithTag + 3));
  }
  while ( 1 )
  {
    v17 = ZwQuerySecurityObject(Handle, 4u, PoolWithTag, v8, &ResultLength);
    if ( v17 != -1073741789 )
      break;
    ExFreePoolWithTag(PoolWithTag, 0x67725450u);
    v8 *= 2;
    PoolWithTag = (char *)ExAllocatePoolWithTag(NonPagedPool, v8, 0x67725450u);
  }
  if ( v17 >= 0 )
    ZwSetSecurityObject(KeyHandle, 4u, PoolWithTag);
  while ( 1 )
  {
    v18 = ZwQuerySecurityObject(Handle, 2u, PoolWithTag, v8, &ResultLength);
    if ( v18 != -1073741789 )
      break;
    ExFreePoolWithTag(PoolWithTag, 0x67725450u);
    v8 *= 2;
    PoolWithTag = (char *)ExAllocatePoolWithTag(NonPagedPool, v8, 0x67725450u);
  }
  if ( v18 >= 0 )
    ZwSetSecurityObject(KeyHandle, 2u, PoolWithTag);
  while ( 1 )
  {
    v19 = ZwQuerySecurityObject(Handle, 1u, PoolWithTag, v8, &ResultLength);
    if ( v19 != -1073741789 )
      break;
    ExFreePoolWithTag(PoolWithTag, 0x67725450u);
    v8 *= 2;
    PoolWithTag = (char *)ExAllocatePoolWithTag(NonPagedPool, v8, 0x67725450u);
  }
  if ( v19 >= 0 )
    ZwSetSecurityObject(KeyHandle, 1u, PoolWithTag);
  while ( 1 )
  {
    v20 = ZwQuerySecurityObject(Handle, 8u, PoolWithTag, v8, &ResultLength);
    if ( v20 != -1073741789 )
      break;
    ExFreePoolWithTag(PoolWithTag, 0x67725450u);
    v8 *= 2;
    PoolWithTag = (char *)ExAllocatePoolWithTag(NonPagedPool, v8, 0x67725450u);
  }
  if ( v20 >= 0 )
    ZwSetSecurityObject(KeyHandle, 8u, PoolWithTag);
  if ( PoolWithTag != nullptr )
    ExFreePoolWithTag(PoolWithTag, 0x67725450u);
  ZwFlushKey(KeyHandle);
  ZwClose(Handle);
LABEL_53:
  v13 = KeyHandle;
LABEL_54:
  ZwClose(v13);
LABEL_55:
  ExFreePoolWithTag(Destination.Buffer, 0x67725450u);
  return v3;
}


// ===== sub_28006DED0 @ 0x28006ded0 size=0x7c =====
char __fastcall sub_28006DED0(PUNICODE_STRING Name, const WCHAR *a2)
{
  char v2; // di
  const WCHAR *v3; // rbx
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-18h] BYREF

  v2 = 0;
  v3 = a2;
  if ( *(_DWORD *)a2 != -1 )
  {
    while ( 1 )
    {
      RtlInitUnicodeString(&DestinationString, v3 + 2);
      if ( FsRtlIsNameInExpression(&DestinationString, Name, 1u, nullptr) != 0 )
        break;
      v3 += 502;
      if ( *(_DWORD *)v3 == -1 )
        goto LABEL_6;
    }
    v2 = 1;
  }
LABEL_6:
  ExReleaseResourceLite(&stru_2800750A0);
  KeLeaveCriticalRegion();
  return v2;
}


// ===== sub_28006DF54 @ 0x28006df54 size=0x2ac =====
__int64 __fastcall sub_28006DF54(PCUNICODE_STRING Source, struct _UNICODE_STRING *a2)
{
  WCHAR *PoolWithTag; // rbp
  NTSTATUS v5; // ebx
  USHORT v6; // ax
  _DWORD *v7; // rax
  _DWORD *v8; // rdi
  wchar_t *v9; // rsi
  struct _UNICODE_STRING Destination; // [rsp+30h] [rbp-E8h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+40h] [rbp-D8h] BYREF
  struct _OBJECT_ATTRIBUTES KeyObjectAttributes; // [rsp+70h] [rbp-A8h] BYREF
  struct _OBJECT_ATTRIBUTES FileObjectAttributes; // [rsp+A0h] [rbp-78h] BYREF
  struct _UNICODE_STRING v15; // [rsp+D0h] [rbp-48h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+E0h] [rbp-38h] BYREF
  ULONG ResultLength; // [rsp+120h] [rbp+8h] BYREF
  void *KeyHandle; // [rsp+130h] [rbp+18h] BYREF

  KeyHandle = nullptr;
  PoolWithTag = (WCHAR *)ExAllocatePoolWithTag(NonPagedPool, Source->Length + 156, 0x67725450u);
  if ( PoolWithTag != nullptr )
  {
    v6 = Source->Length + 156;
    Destination.Length = 0;
    Destination.Buffer = PoolWithTag;
    Destination.MaximumLength = v6;
    RtlAppendUnicodeToString(
      &Destination,
      L"\\REGISTRY\\MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\ProfileList\\");
    RtlAppendUnicodeStringToString(&Destination, Source);
    ObjectAttributes.ObjectName = &Destination;
    ObjectAttributes.Length = 48;
    ObjectAttributes.RootDirectory = nullptr;
    ObjectAttributes.Attributes = 64;
    ObjectAttributes.SecurityDescriptor = nullptr;
    ObjectAttributes.SecurityQualityOfService = nullptr;
    v5 = ZwOpenKey(&KeyHandle, 0x20019u, &ObjectAttributes);
    if ( v5 >= 0 )
    {
      RtlInitUnicodeString(&DestinationString, L"ProfileImagePath");
      v7 = ExAllocatePoolWithTag(NonPagedPool, 0x210u, 0x67725450u);
      v8 = v7;
      if ( v7 != nullptr )
      {
        memset(v7, 0, 0x210u);
        v5 = ZwQueryValueKey(KeyHandle, &DestinationString, KeyValuePartialInformation, v8, 0x210u, &ResultLength);
        ZwClose(KeyHandle);
        if ( v5 >= 0 && (v8[1] == 1 || v8[1] == 2) )
        {
          v9 = (wchar_t *)ExAllocatePoolWithTag(NonPagedPool, (unsigned int)(v8[2] + 64), 0x67725450u);
          if ( v9 != nullptr )
          {
            swprintf(v9, L"\\Device\\%s%x\\%s\\NTUSER.DAT", aDpshadow, (unsigned int)dword_28007500C, (char *)v8 + 18);
            RtlInitUnicodeString(&v15, v9);
            FileObjectAttributes.Attributes = 512;
            KeyObjectAttributes.Attributes = 512;
            FileObjectAttributes.Length = 48;
            FileObjectAttributes.RootDirectory = nullptr;
            FileObjectAttributes.ObjectName = &v15;
            FileObjectAttributes.SecurityDescriptor = nullptr;
            FileObjectAttributes.SecurityQualityOfService = nullptr;
            KeyObjectAttributes.Length = 48;
            KeyObjectAttributes.RootDirectory = nullptr;
            KeyObjectAttributes.ObjectName = a2;
            KeyObjectAttributes.SecurityDescriptor = nullptr;
            KeyObjectAttributes.SecurityQualityOfService = nullptr;
            v5 = ZwLoadKey(&KeyObjectAttributes, &FileObjectAttributes);
          }
          else
          {
            v5 = -1073741670;
          }
          if ( v9 != nullptr )
            ExFreePoolWithTag(v9, 0x67725450u);
        }
      }
      else
      {
        ZwClose(KeyHandle);
        v5 = -1073741670;
      }
      if ( v8 != nullptr )
        ExFreePoolWithTag(v8, 0x67725450u);
    }
    ExFreePoolWithTag(PoolWithTag, 0x67725450u);
  }
  else
  {
    return (unsigned int)-1073741670;
  }
  return (unsigned int)v5;
}


// ===== sub_28006E208 @ 0x28006e208 size=0x753 =====
__int64 __fastcall sub_28006E208(unsigned __int16 *a1, struct _UNICODE_STRING **a2, struct _UNICODE_STRING **a3)
{
  unsigned __int16 *v3; // rsi
  WCHAR *v7; // r15
  PVOID v8; // rdi
  WCHAR *v9; // r12
  int Key; // ebx
  struct _UNICODE_STRING *PoolWithTag; // rax
  struct _UNICODE_STRING *v12; // rsi
  PVOID v14; // rax
  struct _UNICODE_STRING *v15; // rbp
  struct _UNICODE_STRING *v16; // r14
  wchar_t *PoolWithTagPriority; // rax
  WCHAR *v18; // rdi
  struct _OBJECT_ATTRIBUTES *p_KeyObjectAttributes; // rdx
  struct _OBJECT_ATTRIBUTES *p_FileObjectAttributes; // rcx
  PVOID v21; // rax
  wchar_t *v22; // rax
  PVOID v23; // rax
  wchar_t *v24; // rax
  PVOID v25; // rax
  wchar_t *v26; // rax
  unsigned __int64 v27; // rdx
  unsigned int v28; // ebx
  _WORD *v29; // rcx
  __int64 v30; // rbx
  const WCHAR *v31; // rax
  WCHAR *v32; // rdx
  __int64 i; // r8
  USHORT v34; // ax
  _QWORD *v35; // rax
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-A8h] BYREF
  struct _OBJECT_ATTRIBUTES KeyObjectAttributes; // [rsp+30h] [rbp-98h] BYREF
  struct _OBJECT_ATTRIBUTES FileObjectAttributes; // [rsp+60h] [rbp-68h] BYREF
  const WCHAR *SourceString; // [rsp+E8h] [rbp+20h]
  const WCHAR *SourceStringa; // [rsp+E8h] [rbp+20h]

  v3 = (unsigned __int16 *)P;
  v7 = nullptr;
  v8 = nullptr;
  v9 = nullptr;
  Key = 0;
  while ( 1 )
  {
    if ( v3 == (unsigned __int16 *)&P )
    {
      PoolWithTag = (struct _UNICODE_STRING *)ExAllocatePoolWithTag(NonPagedPool, 0x48u, 0x67725450u);
      v12 = PoolWithTag;
      if ( PoolWithTag == nullptr )
        return (unsigned int)-1073741670;
      memset(PoolWithTag, 0, 0x48u);
      if ( sub_28006D840(a1, &::DestinationString.Length) )
      {
        v14 = ExAllocatePoolWithTag(NonPagedPool, 0x40u, 0x67725450u);
        v8 = v14;
        if ( v14 == nullptr )
        {
LABEL_12:
          Key = -1073741670;
LABEL_52:
          if ( v8 != nullptr )
            ExFreePoolWithTag(v8, 0x67725450u);
          goto LABEL_54;
        }
        v15 = v12 + 2;
        v12[2].Length = 0;
        v12[2].MaximumLength = 64;
        v12[2].Buffer = (PWSTR)v14;
        RtlAppendUnicodeToString(v12 + 2, L"\\REGISTRY\\MACHINE\\SYSTEM");
        v9 = (WCHAR *)ExAllocatePoolWithTag(NonPagedPool, 0x80u, 0x67725450u);
        if ( v9 == nullptr )
          goto LABEL_14;
        v16 = v12 + 3;
        v12[3].Length = 0;
        v12[3].MaximumLength = 128;
        v12[3].Buffer = v9;
        RtlAppendUnicodeToString(v12 + 3, L"\\REGISTRY\\MACHINE\\REGISTRY.SD.SYSTEM");
        PoolWithTagPriority = (wchar_t *)ExAllocatePoolWithTagPriority(PagedPool, 0x200u, 0x67725450u, HighPoolPriority);
        SourceString = PoolWithTagPriority;
        if ( PoolWithTagPriority != nullptr )
        {
          swprintf(
            PoolWithTagPriority,
            L"\\Device\\%s%x\\Windows\\System32\\Config\\SYSTEM",
            aDpshadow,
            (unsigned int)dword_28007500C);
          v18 = (WCHAR *)SourceString;
          RtlInitUnicodeString(&DestinationString, SourceString);
          FileObjectAttributes.ObjectName = v12 + 3;
          KeyObjectAttributes.ObjectName = &DestinationString;
          p_KeyObjectAttributes = &KeyObjectAttributes;
          p_FileObjectAttributes = &FileObjectAttributes;
LABEL_33:
          KeyObjectAttributes.Attributes = 512;
          FileObjectAttributes.Attributes = 512;
          KeyObjectAttributes.SecurityQualityOfService = nullptr;
          KeyObjectAttributes.SecurityDescriptor = nullptr;
          KeyObjectAttributes.RootDirectory = nullptr;
          FileObjectAttributes.SecurityQualityOfService = nullptr;
          FileObjectAttributes.SecurityDescriptor = nullptr;
          KeyObjectAttributes.Length = 48;
          FileObjectAttributes.Length = 48;
          FileObjectAttributes.RootDirectory = nullptr;
          Key = ZwLoadKey(p_FileObjectAttributes, p_KeyObjectAttributes);
          LOBYTE(v12[4].Length) = Key >= 0;
          ExFreePoolWithTag(v18, 0x67725450u);
LABEL_48:
          v35 = P;
          *(_QWORD *)&v12->Length = P;
          v12->Buffer = (PWSTR)&P;
          v35[1] = v12;
          P = v12;
          *a2 = v15;
          *a3 = v16;
          return (unsigned int)Key;
        }
LABEL_50:
        if ( v9 != nullptr )
          ExFreePoolWithTag(v9, 0x67725450u);
        goto LABEL_52;
      }
      if ( sub_28006D840(a1, &stru_280075040.Length) )
      {
        v21 = ExAllocatePoolWithTag(NonPagedPool, 0x40u, 0x67725450u);
        v8 = v21;
        if ( v21 == nullptr )
          goto LABEL_12;
        v15 = v12 + 2;
        v12[2].Length = 0;
        v12[2].MaximumLength = 64;
        v12[2].Buffer = (PWSTR)v21;
        RtlAppendUnicodeToString(v12 + 2, L"\\REGISTRY\\MACHINE\\SOFTWARE");
        v9 = (WCHAR *)ExAllocatePoolWithTag(NonPagedPool, 0x80u, 0x67725450u);
        if ( v9 != nullptr )
        {
          v16 = v12 + 3;
          v12[3].Length = 0;
          v12[3].MaximumLength = 128;
          v12[3].Buffer = v9;
          RtlAppendUnicodeToString(v12 + 3, L"\\REGISTRY\\MACHINE\\REGISTRY.SD.SOFTWARE");
          v22 = (wchar_t *)ExAllocatePoolWithTagPriority(PagedPool, 0x200u, 0x67725450u, HighPoolPriority);
          SourceStringa = v22;
          if ( v22 == nullptr )
            goto LABEL_50;
          swprintf(
            v22,
            L"\\Device\\%s%x\\Windows\\System32\\Config\\SOFTWARE",
            aDpshadow,
            (unsigned int)dword_28007500C);
          goto LABEL_32;
        }
LABEL_14:
        Key = -1073741670;
        goto LABEL_50;
      }
      if ( sub_28006D840(a1, &stru_280075080.Length) )
      {
        v23 = ExAllocatePoolWithTag(NonPagedPool, 0x40u, 0x67725450u);
        v8 = v23;
        if ( v23 == nullptr )
          goto LABEL_12;
        v15 = v12 + 2;
        v12[2].Length = 0;
        v12[2].MaximumLength = 64;
        v12[2].Buffer = (PWSTR)v23;
        RtlAppendUnicodeToString(v12 + 2, L"\\REGISTRY\\MACHINE\\SAM");
        v9 = (WCHAR *)ExAllocatePoolWithTag(NonPagedPool, 0x80u, 0x67725450u);
        if ( v9 == nullptr )
          goto LABEL_14;
        v16 = v12 + 3;
        v12[3].Length = 0;
        v12[3].MaximumLength = 128;
        v12[3].Buffer = v9;
        RtlAppendUnicodeToString(v12 + 3, L"\\REGISTRY\\MACHINE\\REGISTRY.SD.SAM");
        v24 = (wchar_t *)ExAllocatePoolWithTagPriority(PagedPool, 0x200u, 0x67725450u, HighPoolPriority);
        SourceStringa = v24;
        if ( v24 == nullptr )
          goto LABEL_50;
        swprintf(v24, L"\\Device\\%s%x\\Windows\\System32\\Config\\SAM", aDpshadow, (unsigned int)dword_28007500C);
      }
      else
      {
        if ( !sub_28006D840(a1, &stru_280075050.Length) )
        {
          if ( !sub_28006D840(a1, &stru_280075030.Length) )
          {
            Key = -1073741772;
            goto LABEL_50;
          }
          v27 = *a1;
          v28 = 15;
          if ( v27 <= 0x1E )
            goto LABEL_39;
          v29 = (_WORD *)(*((_QWORD *)a1 + 1) + 30LL);
          while ( *v29 != 92 )
          {
            ++v28;
            ++v29;
            if ( 2 * (unsigned __int64)v28 >= v27 )
              goto LABEL_39;
          }
          v30 = v28 - 15;
          if ( (_DWORD)v30 == 0 )
          {
LABEL_39:
            Key = -1073741772;
LABEL_56:
            ExFreePoolWithTag(v12, 0x67725450u);
            return (unsigned int)Key;
          }
          v31 = (const WCHAR *)ExAllocatePoolWithTag(NonPagedPool, 2LL * (unsigned int)(v30 + 1), 0x67725450u);
          v7 = (WCHAR *)v31;
          if ( v31 == nullptr )
          {
            Key = -1073741670;
LABEL_54:
            if ( v7 != nullptr )
              ExFreePoolWithTag(v7, 0x67725450u);
            goto LABEL_56;
          }
          v32 = (WCHAR *)v31;
          for ( i = (unsigned int)v30; i != 0; --i )
          {
            *v32 = *(WCHAR *)((char *)v32 + 30LL - (_QWORD)v31 + *((_QWORD *)a1 + 1));
            ++v32;
          }
          v31[v30] = 0;
          RtlInitUnicodeString(v12 + 1, v31);
          v8 = ExAllocatePoolWithTag(NonPagedPool, 2LL * (unsigned int)(v30 + 18), 0x67725450u);
          if ( v8 == nullptr )
            goto LABEL_12;
          v15 = v12 + 2;
          v12[2].Length = 0;
          v12[2].MaximumLength = 2 * (v30 + 18);
          v12[2].Buffer = (PWSTR)v8;
          RtlAppendUnicodeToString(v12 + 2, L"\\REGISTRY\\USER\\");
          RtlAppendUnicodeStringToString(v12 + 2, v12 + 1);
          v9 = (WCHAR *)ExAllocatePoolWithTag(NonPagedPool, v12[1].Length + 128LL, 0x67725450u);
          if ( v9 != nullptr )
          {
            v16 = v12 + 3;
            v34 = v12[1].Length + 128;
            v12[3].Length = 0;
            v12[3].MaximumLength = v34;
            v12[3].Buffer = v9;
            RtlAppendUnicodeToString(v12 + 3, L"\\REGISTRY\\MACHINE\\REGISTRY.SD.USER.");
            RtlAppendUnicodeStringToString(v12 + 3, v12 + 1);
            Key = sub_28006DF54(v12 + 1, v12 + 3);
            LOBYTE(v12[4].Length) = Key >= 0;
            goto LABEL_48;
          }
          goto LABEL_14;
        }
        v25 = ExAllocatePoolWithTag(NonPagedPool, 0x80u, 0x67725450u);
        v8 = v25;
        if ( v25 == nullptr )
          goto LABEL_12;
        v15 = v12 + 2;
        v12[2].Length = 0;
        v12[2].MaximumLength = 128;
        v12[2].Buffer = (PWSTR)v25;
        RtlAppendUnicodeToString(v12 + 2, L"\\REGISTRY\\MACHINE\\SECURITY");
        v9 = (WCHAR *)ExAllocatePoolWithTag(NonPagedPool, 0x80u, 0x67725450u);
        if ( v9 == nullptr )
          goto LABEL_14;
        v16 = v12 + 3;
        v12[3].Length = 0;
        v12[3].MaximumLength = 128;
        v12[3].Buffer = v9;
        RtlAppendUnicodeToString(v12 + 3, L"\\REGISTRY\\MACHINE\\REGISTRY.SD.SECURITY");
        v26 = (wchar_t *)ExAllocatePoolWithTagPriority(PagedPool, 0x200u, 0x67725450u, HighPoolPriority);
        SourceStringa = v26;
        if ( v26 == nullptr )
          goto LABEL_50;
        swprintf(v26, L"\\Device\\%s%x\\Windows\\System32\\Config\\SECURITY", aDpshadow, (unsigned int)dword_28007500C);
      }
LABEL_32:
      v18 = (WCHAR *)SourceStringa;
      RtlInitUnicodeString(&DestinationString, SourceStringa);
      KeyObjectAttributes.ObjectName = v16;
      FileObjectAttributes.ObjectName = &DestinationString;
      p_KeyObjectAttributes = &FileObjectAttributes;
      p_FileObjectAttributes = &KeyObjectAttributes;
      goto LABEL_33;
    }
    if ( sub_28006D840(a1, v3 + 16) )
      break;
    v3 = *(unsigned __int16 **)v3;
  }
  if ( *((_BYTE *)v3 + 64) == 0 )
    return 3221225473LL;
  *a2 = (struct _UNICODE_STRING *)(v3 + 16);
  *a3 = (struct _UNICODE_STRING *)(v3 + 24);
  return 0;
}


// ===== sub_28006E964 @ 0x28006e964 size=0x35b =====
__int64 sub_28006E964()
{
  WCHAR *PoolWithTagPriority; // rax
  WCHAR *v1; // r12
  __int64 v3; // rbp
  int *v4; // rax
  int *v5; // rbx
  _WORD *v6; // rax
  unsigned __int16 *v7; // rdx
  __int64 i; // r8
  unsigned __int16 v9; // cx
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+60h] [rbp-98h] BYREF
  struct _UNICODE_STRING Destination; // [rsp+70h] [rbp-88h] BYREF
  char FileInformation[8]; // [rsp+80h] [rbp-78h] BYREF
  unsigned int v13; // [rsp+88h] [rbp-70h]
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+98h] [rbp-60h] BYREF
  void *FileHandle; // [rsp+100h] [rbp+8h] BYREF

  FileHandle = nullptr;
  PoolWithTagPriority = (WCHAR *)ExAllocatePoolWithTagPriority(PagedPool, 0x3E8u, 0x67725450u, HighPoolPriority);
  v1 = PoolWithTagPriority;
  if ( PoolWithTagPriority == nullptr )
    return 3221225626LL;
  memset(PoolWithTagPriority, 0, 0x3E8u);
  Destination.Length = 0;
  Destination.MaximumLength = 1000;
  Destination.Buffer = v1;
  RtlAppendUnicodeToString(&Destination, L"\\SystemRoot\\diskptex.dat");
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &Destination;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  if ( ZwCreateFile(
         &FileHandle,
         0x100001u,
         &ObjectAttributes,
         &IoStatusBlock,
         nullptr,
         0x80u,
         1u,
         3u,
         0x28u,
         nullptr,
         0) >= 0
    && ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x18u, FileStandardInformation) >= 0 )
  {
    v3 = v13;
    if ( v13 != 0 && v13 == 1004 * (v13 / 0x3ECuLL) + 4 )
    {
      v4 = (int *)ExAllocatePoolWithTagPriority(PagedPool, v13 + 1004LL, 0x67725450u, HighPoolPriority);
      v5 = v4;
      if ( v4 != nullptr )
      {
        if ( ZwReadFile(FileHandle, nullptr, nullptr, nullptr, &IoStatusBlock, v4, 4u, nullptr, nullptr) >= 0
          && IoStatusBlock.Information == 4
          && (dword_280074FB4 = *v5,
              ZwReadFile(FileHandle, nullptr, nullptr, nullptr, &IoStatusBlock, v5, v3 - 4, nullptr, nullptr) >= 0)
          && IoStatusBlock.Information == v3 - 4 )
        {
          *(int *)((char *)v5 + v3 - 4) = -1;
          if ( *v5 != -1 )
          {
            v6 = (_WORD *)v5 + 501;
            do
            {
              v7 = v6 - 499;
              for ( i = 500; i != 0; --i )
              {
                v9 = *v7;
                if ( *v7 >= 0x61u && v9 <= 0x7Au )
                  *v7 = v9 - 32;
                ++v7;
              }
              *v6 = 0;
              v6 += 502;
            }
            while ( *(_DWORD *)(v6 - 501) != -1 );
          }
        }
        else
        {
          ExFreePoolWithTag(v5, 0x67725450u);
        }
      }
    }
  }
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&stru_2800750A0, 1u);
  return sub_2800B7DE9();
}


// ===== sub_28006ECC8 @ 0x28006ecc8 size=0xdb =====
char __fastcall sub_28006ECC8(_BYTE *a1, char *a2)
{
  char v2; // r8
  char v4; // cl
  __int64 v5; // rdx
  _BYTE *v6; // rcx
  __int64 i; // r8
  char v8; // al
  _BYTE *v9; // rcx
  char v10; // al
  char result; // al

  v2 = *a2;
  *a1 ^= *a2 ^ byte_280072800[(unsigned __int8)a1[29]];
  a1[1] ^= byte_280072800[(unsigned __int8)a1[30]];
  a1[2] ^= byte_280072800[(unsigned __int8)a1[31]];
  a1[3] ^= byte_280072800[(unsigned __int8)a1[28]];
  v4 = 2 * v2;
  if ( v2 < 0 )
    v4 = (2 * v2) ^ 0x1B;
  *a2 = v4;
  v5 = 3;
  v6 = a1 + 5;
  for ( i = 3; i != 0; --i )
  {
    *(v6 - 1) ^= *(v6 - 5);
    *v6 ^= *(v6 - 4);
    v8 = *(v6 - 3);
    v6 += 4;
    *(v6 - 3) ^= v8;
    *(v6 - 2) ^= *(v6 - 6);
  }
  v9 = a1 + 21;
  a1[16] ^= byte_280072800[(unsigned __int8)a1[12]];
  a1[17] ^= byte_280072800[(unsigned __int8)a1[13]];
  a1[18] ^= byte_280072800[(unsigned __int8)a1[14]];
  a1[19] ^= byte_280072800[(unsigned __int8)a1[15]];
  do
  {
    *(v9 - 1) ^= *(v9 - 5);
    *v9 ^= *(v9 - 4);
    v10 = *(v9 - 3);
    v9 += 4;
    *(v9 - 3) ^= v10;
    result = *(v9 - 6);
    *(v9 - 2) ^= result;
    --v5;
  }
  while ( v5 != 0 );
  return result;
}


// ===== sub_28006EDAC @ 0x28006edac size=0x297 =====
char __fastcall sub_28006EDAC(_BYTE *a1, _BYTE *a2)
{
  _BYTE *v3; // rsi
  _BYTE *v5; // r10
  char v6; // bp
  _BYTE *v7; // rcx
  _BYTE *v8; // rdx
  __int64 v9; // r10
  char v10; // r8
  char v11; // al
  bool v12; // zf
  char v13; // r14
  _BYTE *v14; // r15
  char v15; // dl
  _BYTE *v16; // rcx
  char v17; // cl
  _BYTE *v18; // r13
  char v19; // al
  char v20; // cl
  char v21; // al
  char v22; // cl
  char v23; // al
  char v24; // cl
  __int64 i; // r15
  char v26; // r9
  char v27; // r11
  char v28; // r10
  char v29; // bl
  char v30; // dl
  char v31; // r8
  char v32; // dl
  char v33; // al
  char v34; // r8
  char v35; // dl
  char v36; // r8
  char v37; // dl
  char v38; // dl
  _BYTE *v39; // rcx
  _BYTE *v40; // r8
  char v41; // r11
  _BYTE *v42; // rcx
  char v43; // dl
  _BYTE *v44; // rcx
  char v45; // cl
  char v46; // al
  char v47; // cl
  char v48; // al
  char v49; // cl
  char v50; // al
  char v51; // cl
  char v52; // al
  __int64 v53; // r12
  char result; // al
  char v55; // [rsp+50h] [rbp+8h] BYREF

  v3 = a2 + 16;
  v5 = a1 + 32;
  v6 = 16;
  v7 = a2 + 16;
  v8 = a1 + 32;
  v9 = v5 - a2;
  v10 = 16;
  do
  {
    --v8;
    --v7;
    v11 = v7[v9];
    *(v8 - 16) = v11;
    *v7 ^= v11;
    v12 = v10-- == 1;
    *v8 = v8[32];
  }
  while ( !v12 );
  v13 = 1;
  v14 = a2 + 2;
  v55 = 1;
  do
  {
    v15 = 16;
    v16 = v3;
    do
    {
      --v16;
      v12 = v15-- == 1;
      *v16 = byte_280072800[(unsigned __int8)*v16];
    }
    while ( !v12 );
    v17 = a2[1];
    v18 = v14;
    a2[1] = a2[5];
    a2[5] = a2[9];
    v19 = a2[13];
    a2[13] = v17;
    v20 = a2[10];
    a2[9] = v19;
    a2[10] = *v14;
    v21 = a2[15];
    *v14 = v20;
    v22 = a2[3];
    a2[3] = v21;
    a2[15] = a2[11];
    v23 = a2[7];
    a2[7] = v22;
    v24 = a2[14];
    a2[11] = v23;
    a2[14] = a2[6];
    a2[6] = v24;
    for ( i = 4; i != 0; --i )
    {
      v26 = *(v18 - 1);
      v27 = *(v18 - 2);
      v28 = *v18 ^ v18[1];
      v29 = v27 ^ v26 ^ v28;
      v30 = 2 * (v27 ^ v26);
      if ( ((v27 ^ v26) & 0x80u) != 0 )
        v30 ^= 0x1Bu;
      v31 = v26 ^ *v18;
      *(v18 - 2) = v29 ^ v27 ^ v30;
      v32 = 2 * v31;
      v33 = (2 * v31) ^ 0x1B;
      v12 = v31 >= 0;
      v34 = v18[1];
      if ( !v12 )
        v32 = v33;
      *(v18 - 1) = v29 ^ v26 ^ v32;
      v35 = 2 * v28;
      if ( v28 < 0 )
        v35 = (2 * v28) ^ 0x1B;
      v36 = v27 ^ v34;
      *v18 ^= v29 ^ v35;
      v37 = 2 * v36;
      if ( v36 < 0 )
        v37 = (2 * v36) ^ 0x1B;
      v18 += 4;
      *(v18 - 3) ^= v29 ^ v37;
    }
    if ( (v13 & 1) != 0 )
    {
      v38 = 16;
      v39 = v3;
      v40 = a1 + 32;
      do
      {
        *--v39 ^= *--v40;
        --v38;
      }
      while ( v38 != 0 );
    }
    else
    {
      sub_28006ECC8(a1, &v55);
      v41 = 16;
      v42 = v3;
      do
      {
        --v42;
        *v42 ^= v42[a1 - a2];
        --v41;
      }
      while ( v41 != 0 );
    }
    ++v13;
    v14 = a2 + 2;
  }
  while ( (unsigned __int8)v13 < 0xEu );
  v43 = 16;
  v44 = v3;
  do
  {
    --v44;
    v12 = v43-- == 1;
    *v44 = byte_280072800[(unsigned __int8)*v44];
  }
  while ( !v12 );
  v45 = a2[1];
  a2[1] = a2[5];
  a2[5] = a2[9];
  v46 = a2[13];
  a2[13] = v45;
  v47 = a2[10];
  a2[9] = v46;
  a2[10] = *v14;
  v48 = a2[15];
  *v14 = v47;
  v49 = a2[3];
  a2[3] = v48;
  a2[15] = a2[11];
  v50 = a2[7];
  a2[7] = v49;
  v51 = a2[14];
  a2[11] = v50;
  v52 = a2[6];
  a2[6] = v51;
  a2[14] = v52;
  sub_28006ECC8(a1, &v55);
  v53 = a1 - a2;
  do
  {
    result = (--v3)[v53];
    *v3 ^= result;
    --v6;
  }
  while ( v6 != 0 );
  return result;
}


// ===== sub_28006F04C @ 0x28006f04c size=0x473 =====
char __fastcall sub_28006F04C(_BYTE *a1, _BYTE *a2)
{
  _BYTE *v2; // r13
  _BYTE *v3; // r8
  _BYTE *v4; // r14
  _BYTE *v6; // r11
  _BYTE *v7; // rcx
  _BYTE *v8; // rdx
  __int64 v9; // r8
  char v10; // r9
  char v11; // al
  bool v12; // zf
  char v13; // cl
  _BYTE *v14; // rdx
  char v15; // r8
  char v16; // al
  char v17; // cl
  char v18; // al
  char v19; // cl
  char v20; // al
  char v21; // cl
  char v22; // al
  _BYTE *v23; // rcx
  unsigned __int8 v24; // r8
  char v25; // al
  _BYTE *v26; // rcx
  __int64 i; // r9
  char v28; // al
  unsigned __int8 v29; // r9
  _BYTE *v30; // r9
  __int64 v31; // rax
  char v32; // r8
  _BYTE *v33; // rcx
  char v34; // r8
  _BYTE *v35; // rcx
  _BYTE *v36; // r13
  __int64 j; // r15
  unsigned __int8 v38; // si
  unsigned __int8 v39; // bl
  unsigned __int8 v40; // bp
  char v41; // di
  char v42; // r10
  char v43; // r9
  char v44; // r8
  char v45; // r11
  char v46; // r9
  char v47; // r11
  char v48; // dl
  char v49; // r9
  char v50; // r9
  char v51; // dl
  char v52; // r8
  char v53; // dl
  char v54; // dl
  char v55; // dl
  char v56; // cl
  char v57; // al
  char v58; // cl
  char v59; // al
  char v60; // cl
  char v61; // al
  char v62; // cl
  char v63; // al
  char v64; // r15
  _BYTE *v65; // rcx
  char v66; // r8
  char result; // al
  char v69; // [rsp+48h] [rbp+10h]
  char v70; // [rsp+50h] [rbp+18h]

  v2 = a1;
  v3 = a1 + 64;
  v4 = a2 + 16;
  v6 = a1 + 32;
  v7 = a2 + 16;
  v8 = v6;
  v9 = v3 - a2;
  v10 = 16;
  do
  {
    --v8;
    --v7;
    v11 = v7[v9];
    *(v8 - 16) = v11;
    *v7 ^= v11;
    v12 = v10-- == 1;
    *v8 = v8[64];
  }
  while ( !v12 );
  v13 = a2[1];
  v14 = a2 + 2;
  a2[1] = a2[13];
  v15 = 16;
  a2[13] = a2[9];
  v16 = a2[5];
  a2[5] = v13;
  v17 = a2[2];
  a2[9] = v16;
  a2[2] = a2[10];
  v18 = a2[7];
  a2[10] = v17;
  v19 = a2[3];
  a2[3] = v18;
  a2[7] = a2[11];
  v20 = a2[15];
  a2[15] = v19;
  v21 = a2[6];
  a2[11] = v20;
  v22 = a2[14];
  a2[14] = v21;
  a2[6] = v22;
  v23 = v4;
  do
  {
    --v23;
    v12 = v15-- == 1;
    *v23 = byte_280072800[(unsigned __int8)*v23 + 256];
  }
  while ( !v12 );
  v24 = 0x80;
  v25 = 13;
  v70 = 0x80;
  v69 = 13;
  do
  {
    if ( (v25 & 1) != 0 )
    {
      v26 = v2 + 29;
      for ( i = 3; i != 0; --i )
      {
        *(v26 - 1) ^= *(v26 - 5);
        *v26 ^= *(v26 - 4);
        v28 = *(v26 - 3);
        v26 -= 4;
        v26[5] ^= v28;
        v26[6] ^= v26[2];
      }
      v29 = 12;
      v2[16] ^= byte_280072800[(unsigned __int8)v2[12]];
      v2[17] ^= byte_280072800[(unsigned __int8)v2[13]];
      v2[18] ^= byte_280072800[(unsigned __int8)v2[14]];
      v2[19] ^= byte_280072800[(unsigned __int8)v2[15]];
      do
      {
        v2[v29] ^= v2[v29 - 4];
        v2[v29 + 1] ^= v2[v29 - 3];
        v2[v29 + 2] ^= v2[v29 - 2];
        v2[v29 + 3] ^= v2[v29 - 1];
        v29 -= 4;
      }
      while ( v29 != 0 );
      v30 = v6;
      v31 = (unsigned __int8)v2[30];
      v70 = (v24 >> 1) ^ ((v24 & 1) != 0 ? 0x8D : 0);
      v32 = 16;
      *v2 ^= v70 ^ byte_280072800[(unsigned __int8)v2[29]];
      v33 = v4;
      v2[1] ^= byte_280072800[v31];
      v2[2] ^= byte_280072800[(unsigned __int8)v2[31]];
      v2[3] ^= byte_280072800[(unsigned __int8)v2[28]];
      do
      {
        *--v33 ^= *--v30;
        --v32;
      }
      while ( v32 != 0 );
    }
    else
    {
      v34 = 16;
      v35 = v4;
      do
      {
        --v35;
        *v35 ^= v35[v2 - a2];
        --v34;
      }
      while ( v34 != 0 );
    }
    v36 = v14;
    for ( j = 4; j != 0; --j )
    {
      v38 = *(v36 - 2);
      v39 = *(v36 - 1);
      v40 = v36[1];
      v41 = *v36 ^ v40;
      v42 = v38 ^ v39 ^ v41;
      v43 = 2 * v42;
      if ( v42 < 0 )
        v43 = (2 * v42) ^ 0x1B;
      v44 = 2 * (v38 ^ *v36 ^ v43);
      if ( ((v38 ^ (unsigned __int8)(*v36 ^ v43)) & 0x80) != 0 )
        v44 ^= 0x1Bu;
      v45 = 2 * v44;
      if ( v44 < 0 )
        v45 = (2 * v44) ^ 0x1B;
      v46 = v39 ^ v40 ^ v43;
      v47 = v42 ^ v45;
      v48 = 2 * v46;
      if ( v46 < 0 )
        v48 = (2 * v46) ^ 0x1B;
      v49 = 2 * v48;
      if ( v48 < 0 )
        v49 = (2 * v48) ^ 0x1B;
      v50 = v42 ^ v49;
      v51 = 2 * (v38 ^ v39);
      if ( ((v38 ^ v39) & 0x80) != 0 )
        v51 = (2 * (v38 ^ v39)) ^ 0x1B;
      v52 = v39 ^ *v36;
      *(v36 - 2) = v47 ^ v38 ^ v51;
      v53 = 2 * v52;
      if ( v52 < 0 )
        v53 = (2 * v52) ^ 0x1B;
      *(v36 - 1) = v50 ^ v39 ^ v53;
      v54 = 2 * v41;
      if ( v41 < 0 )
        v54 = (2 * v41) ^ 0x1B;
      *v36 ^= v47 ^ v54;
      v55 = 2 * (v38 ^ v40);
      if ( ((v38 ^ v40) & 0x80) != 0 )
        v55 = (2 * (v38 ^ v40)) ^ 0x1B;
      v36 += 4;
      *(v36 - 3) = v50 ^ v40 ^ v55;
    }
    v56 = a2[1];
    v2 = a1;
    a2[1] = a2[13];
    v14 = a2 + 2;
    a2[13] = a2[9];
    v57 = a2[5];
    a2[5] = v56;
    v58 = a2[2];
    a2[9] = v57;
    a2[2] = a2[10];
    v59 = a2[7];
    a2[10] = v58;
    v60 = a2[3];
    a2[3] = v59;
    a2[7] = a2[11];
    v61 = a2[15];
    a2[15] = v60;
    v62 = a2[6];
    a2[11] = v61;
    v63 = a2[14];
    v64 = 16;
    a2[14] = v62;
    a2[6] = v63;
    v65 = v4;
    v66 = 16;
    do
    {
      --v65;
      v12 = v66-- == 1;
      *v65 = byte_280072800[(unsigned __int8)*v65 + 256];
    }
    while ( !v12 );
    v24 = v70;
    v6 = a1 + 32;
    v12 = v69 == 1;
    v25 = --v69;
  }
  while ( !v12 );
  do
  {
    --v4;
    result = v4[a1 - a2];
    *v4 ^= result;
    --v64;
  }
  while ( v64 != 0 );
  return result;
}


// ===== __security_check_cookie @ 0x28006f4d0 size=0x20 =====
void __cdecl _security_check_cookie(uintptr_t StackCookie)
{
  __int64 v1; // rcx

  if ( StackCookie != BugCheckParameter2 )
ReportFailure:
    _report_gsfailure(StackCookie);
  v1 = __ROL8__(StackCookie, 16);
  if ( (_WORD)v1 != 0 )
  {
    StackCookie = __ROR8__(v1, 16);
    goto ReportFailure;
  }
}


// ===== __report_gsfailure @ 0x28006f4f8 size=0x27 =====
void __cdecl __noreturn _report_gsfailure(uintptr_t StackCookie)
{
  KeBugCheckEx(0xF7u, StackCookie, BugCheckParameter2, BugCheckParameter3, 0);
}


// ===== ZwQueryInformationProcess @ 0x28006f526 size=0x6 =====
// attributes: thunk
NTSTATUS __stdcall ZwQueryInformationProcess(
        HANDLE ProcessHandle,
        PROCESSINFOCLASS ProcessInformationClass,
        PVOID ProcessInformation,
        ULONG ProcessInformationLength,
        PULONG ReturnLength)
{
  return __imp_ZwQueryInformationProcess(
           ProcessHandle,
           ProcessInformationClass,
           ProcessInformation,
           ProcessInformationLength,
           ReturnLength);
}


// ===== sprintf @ 0x28006f532 size=0x6 =====
// attributes: thunk
int sprintf(char *Dest, const char *Format, ...)
{
  return __imp_sprintf(Dest, Format);
}


// ===== swprintf @ 0x28006f53e size=0x6 =====
// attributes: thunk
int swprintf(wchar_t *a1, const wchar_t *a2, ...)
{
  return __imp_swprintf(a1, a2);
}


// ===== DbgPrint @ 0x28006f54a size=0x6 =====
// attributes: thunk
ULONG DbgPrint(PCSTR Format, ...)
{
  return __imp_DbgPrint(Format);
}


// ===== wcschr @ 0x28006f556 size=0x6 =====
// attributes: thunk
wchar_t *__cdecl wcschr(const wchar_t *Str, wchar_t Ch)
{
  return __imp_wcschr(Str, Ch);
}


// ===== _wcsnicmp @ 0x28006f562 size=0x6 =====
// attributes: thunk
int __cdecl wcsnicmp(const wchar_t *Str1, const wchar_t *Str2, size_t MaxCount)
{
  return _wcsnicmp(Str1, Str2, MaxCount);
}


// ===== memmove @ 0x28006f580 size=0x334 =====
void *__cdecl memmove(void *Dst, const void *Src, size_t MaxCount)
{
  void *v3; // r11
  bool v4; // cf
  unsigned __int64 v5; // rdx
  size_t v6; // r9
  size_t v7; // r9
  __int64 v9; // rax
  __int64 v10; // r10
  __int64 v11; // r10
  int k; // eax
  int m; // eax
  __int64 v14; // r10
  __int64 v15; // r10
  __int64 v16; // r9
  __int64 v17; // r10
  __int64 v18; // r10
  int *v19; // rcx
  size_t v20; // r9
  size_t v21; // r9
  __int64 v22; // rax
  __int64 v23; // r10
  __int64 v24; // r10
  int i; // eax
  int j; // eax
  __int64 v27; // r10
  __int64 v28; // r10
  __int64 v29; // r9
  __int64 v30; // r10
  __int64 v31; // r10
  _UNKNOWN *retaddr; // [rsp+0h] [rbp+0h] BYREF

  v3 = Dst;
  v4 = Src < Dst;
  v5 = (_BYTE *)Src - (_BYTE *)Dst;
  if ( v4 )
  {
    v19 = (int *)((char *)Dst + MaxCount);
    if ( MaxCount >= 8 )
    {
      if ( ((unsigned __int8)v19 & 7) != 0 )
      {
        if ( ((unsigned __int8)v19 & 1) != 0 )
        {
          v19 = (int *)((char *)v19 - 1);
          --MaxCount;
          *(_BYTE *)v19 = *((_BYTE *)v19 + v5);
        }
        if ( ((unsigned __int8)v19 & 2) != 0 )
        {
          v19 = (int *)((char *)v19 - 2);
          MaxCount -= 2LL;
          *(_WORD *)v19 = *(_WORD *)((char *)v19 + v5);
        }
        if ( ((unsigned __int8)v19 & 4) != 0 )
        {
          --v19;
          MaxCount -= 4LL;
          *v19 = *(int *)((char *)v19 + v5);
        }
      }
      while ( 1 )
      {
        v20 = MaxCount >> 5;
        if ( MaxCount >> 5 == 0 )
          break;
        if ( v20 < 0x2000 || v5 > 0xFFFFFFFFFFFFF000uLL )
        {
          do
          {
            v22 = *(_QWORD *)((char *)v19 + v5 - 8);
            v23 = *(_QWORD *)((char *)v19 + v5 - 16);
            v19 -= 8;
            *((_QWORD *)v19 + 3) = v22;
            *((_QWORD *)v19 + 2) = v23;
            v24 = *(_QWORD *)((char *)v19 + v5);
            --v20;
            *((_QWORD *)v19 + 1) = *(_QWORD *)((char *)v19 + v5 + 8);
            *(_QWORD *)v19 = v24;
          }
          while ( v20 != 0 );
          MaxCount &= 0x1Fu;
          break;
        }
        do
        {
          for ( i = 32; i != 0; --i )
          {
            v19 -= 32;
            _mm_prefetch((const char *)v19 + v5, 0);
            _mm_prefetch((const char *)v19 + v5 + 64, 0);
          }
          v19 += 1024;
          for ( j = 64; j != 0; --j )
          {
            v27 = *(_QWORD *)((char *)v19 + v5 - 16);
            _mm_stream_si32(v19 - 2, *(_QWORD *)((char *)v19 + v5 - 8));
            _mm_stream_si32(v19 - 4, v27);
            v28 = *(_QWORD *)((char *)v19 + v5 - 32);
            _mm_stream_si32(v19 - 6, *(_QWORD *)((char *)v19 + v5 - 24));
            _mm_stream_si32(v19 - 8, v28);
            v29 = *(_QWORD *)((char *)v19 + v5 - 40);
            v30 = *(_QWORD *)((char *)v19 + v5 - 48);
            v19 -= 16;
            _mm_stream_si32(v19 + 6, v29);
            _mm_stream_si32(v19 + 4, v30);
            v31 = *(_QWORD *)((char *)v19 + v5);
            _mm_stream_si32(v19 + 2, *(_QWORD *)((char *)v19 + v5 + 8));
            _mm_stream_si32(v19, v31);
          }
          MaxCount -= 4096LL;
        }
        while ( MaxCount >= 0x1000 );
        _InterlockedOr8((volatile signed __int8 *)&retaddr, 0);
      }
      v21 = MaxCount >> 3;
      if ( MaxCount >> 3 != 0 )
      {
        do
        {
          v19 -= 2;
          --v21;
          *(_QWORD *)v19 = *(_QWORD *)((char *)v19 + v5);
        }
        while ( v21 != 0 );
        MaxCount &= 7u;
      }
    }
    if ( MaxCount != 0 )
    {
      do
      {
        v19 = (int *)((char *)v19 - 1);
        --MaxCount;
        *(_BYTE *)v19 = *((_BYTE *)v19 + v5);
      }
      while ( MaxCount != 0 );
      return v3;
    }
    else
    {
      return v3;
    }
  }
  else
  {
    if ( MaxCount >= 8 )
    {
      if ( ((unsigned __int8)Dst & 7) != 0 )
      {
        if ( ((unsigned __int8)Dst & 1) != 0 )
        {
          --MaxCount;
          *(_BYTE *)Dst = *((_BYTE *)Dst + v5);
          Dst = (char *)Dst + 1;
        }
        if ( ((unsigned __int8)Dst & 2) != 0 )
        {
          MaxCount -= 2LL;
          *(_WORD *)Dst = *(_WORD *)((char *)Dst + v5);
          Dst = (char *)Dst + 2;
        }
        if ( ((unsigned __int8)Dst & 4) != 0 )
        {
          MaxCount -= 4LL;
          *(_DWORD *)Dst = *(_DWORD *)((char *)Dst + v5);
          Dst = (char *)Dst + 4;
        }
      }
      while ( 1 )
      {
        v6 = MaxCount >> 5;
        if ( MaxCount >> 5 == 0 )
          break;
        if ( v6 < 0x2000 || v5 < 0x1000 )
        {
          do
          {
            v9 = *(_QWORD *)((char *)Dst + v5);
            v10 = *(_QWORD *)((char *)Dst + v5 + 8);
            Dst = (char *)Dst + 32;
            *((_QWORD *)Dst - 4) = v9;
            *((_QWORD *)Dst - 3) = v10;
            v11 = *(_QWORD *)((char *)Dst + v5 - 8);
            --v6;
            *((_QWORD *)Dst - 2) = *(_QWORD *)((char *)Dst + v5 - 16);
            *((_QWORD *)Dst - 1) = v11;
          }
          while ( v6 != 0 );
          MaxCount &= 0x1Fu;
          break;
        }
        do
        {
          for ( k = 32; k != 0; --k )
          {
            _mm_prefetch((const char *)Dst + v5, 0);
            _mm_prefetch((const char *)Dst + v5 + 64, 0);
            Dst = (char *)Dst + 128;
          }
          Dst = (char *)Dst - 4096;
          for ( m = 64; m != 0; --m )
          {
            v14 = *(_QWORD *)((char *)Dst + v5 + 8);
            _mm_stream_si32((int *)Dst, *(_QWORD *)((char *)Dst + v5));
            _mm_stream_si32((int *)Dst + 2, v14);
            v15 = *(_QWORD *)((char *)Dst + v5 + 24);
            _mm_stream_si32((int *)Dst + 4, *(_QWORD *)((char *)Dst + v5 + 16));
            _mm_stream_si32((int *)Dst + 6, v15);
            v16 = *(_QWORD *)((char *)Dst + v5 + 32);
            v17 = *(_QWORD *)((char *)Dst + v5 + 40);
            Dst = (char *)Dst + 64;
            _mm_stream_si32((int *)Dst - 8, v16);
            _mm_stream_si32((int *)Dst - 6, v17);
            v18 = *(_QWORD *)((char *)Dst + v5 - 8);
            _mm_stream_si32((int *)Dst - 4, *(_QWORD *)((char *)Dst + v5 - 16));
            _mm_stream_si32((int *)Dst - 2, v18);
          }
          MaxCount -= 4096LL;
        }
        while ( MaxCount >= 0x1000 );
        _InterlockedOr8((volatile signed __int8 *)&retaddr, 0);
      }
      v7 = MaxCount >> 3;
      if ( MaxCount >> 3 != 0 )
      {
        do
        {
          *(_QWORD *)Dst = *(_QWORD *)((char *)Dst + v5);
          Dst = (char *)Dst + 8;
          --v7;
        }
        while ( v7 != 0 );
        MaxCount &= 7u;
      }
    }
    if ( MaxCount != 0 )
    {
      do
      {
        *(_BYTE *)Dst = *((_BYTE *)Dst + v5);
        Dst = (char *)Dst + 1;
        --MaxCount;
      }
      while ( MaxCount != 0 );
      return v3;
    }
    else
    {
      return v3;
    }
  }
}


// ===== _snwprintf @ 0x28006f8ba size=0x6 =====
// attributes: thunk
int snwprintf(wchar_t *Dest, size_t Count, const wchar_t *Format, ...)
{
  return _snwprintf(Dest, Count, Format);
}


// ===== ZwUnloadKey @ 0x28006f8c6 size=0x6 =====
// attributes: thunk
NTSTATUS __stdcall ZwUnloadKey(POBJECT_ATTRIBUTES KeyObjectAttributes)
{
  return __imp_ZwUnloadKey(KeyObjectAttributes);
}


// ===== ZwLoadKey @ 0x28006f8d2 size=0x6 =====
// attributes: thunk
NTSTATUS __stdcall ZwLoadKey(POBJECT_ATTRIBUTES KeyObjectAttributes, POBJECT_ATTRIBUTES FileObjectAttributes)
{
  return __imp_ZwLoadKey(KeyObjectAttributes, FileObjectAttributes);
}


// ===== WdmlibRtlInitUnicodeStringEx @ 0x28006f8e0 size=0x59 =====
NTSTATUS __stdcall WdmlibRtlInitUnicodeStringEx(PUNICODE_STRING DestinationString, PCWSTR SourceString)
{
  __int64 v3; // rcx
  PCWSTR v4; // rdi
  bool v5; // zf
  unsigned __int64 v6; // rcx

  if ( SourceString != nullptr )
  {
    v3 = -1;
    v4 = SourceString;
    do
    {
      if ( v3 == 0 )
        break;
      v5 = *v4++ == 0;
      --v3;
    }
    while ( !v5 );
    v6 = -v3 - 2;
    if ( v6 > 0x7FFE )
      return -1073741562;
    DestinationString->Buffer = (PWSTR)SourceString;
    DestinationString->Length = 2 * v6;
    DestinationString->MaximumLength = 2 * v6 + 2;
  }
  else
  {
    DestinationString->Length = 0;
    DestinationString->MaximumLength = 0;
    DestinationString->Buffer = nullptr;
  }
  return 0;
}


// ===== __GSHandlerCheckCommon @ 0x28006f940 size=0x63 =====
__int64 __fastcall _GSHandlerCheckCommon(__int64 a1, __int64 a2)
{
  __int64 result; // rax
  __int64 v3; // rcx

  result = *(_QWORD *)(a2 + 16);
  v3 = *(_QWORD *)(a2 + 8) + *(unsigned int *)(result + 8);
  if ( (*(_BYTE *)(v3 + 3) & 0xF) != 0 )
    return *(_BYTE *)(v3 + 3) & 0xF0;
  return result;
}


// ===== __GSHandlerCheck @ 0x28006f9ac size=0x1d =====
__int64 __fastcall _GSHandlerCheck(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _GSHandlerCheckCommon(a2, a4);
  return 1;
}


// ===== memset @ 0x28006f9e0 size=0xea =====
// local variable allocation has failed, the output may be wrong!
void *__cdecl memset(void *Dst, int Val, size_t Size)
{
  void *result; // rax
  unsigned int v4; // ecx
  size_t v5; // r9
  unsigned __int64 v6; // r9
  size_t v7; // r9
  size_t i; // r9
  _UNKNOWN *retaddr; // [rsp+0h] [rbp+0h] BYREF

  result = Dst;
  if ( Size >= 8 )
  {
    *(_QWORD *)&Val = 0x101010101010101LL * (unsigned __int8)Val;
    if ( Size >= 0x40 )
    {
      v4 = -(int)Dst & 7;
      if ( v4 != 0 )
      {
        Size -= v4;
        *(_QWORD *)result = *(_QWORD *)&Val;
      }
      Dst = (char *)result + v4;
      v5 = Size;
      Size &= 0x3Fu;
      v6 = v5 >> 6;
      if ( v6 != 0 )
      {
        if ( v6 >= 0x1C00 )
        {
          do
          {
            _mm_stream_si32((int *)Dst, Val);
            _mm_stream_si32((int *)Dst + 2, Val);
            _mm_stream_si32((int *)Dst + 4, Val);
            Dst = (char *)Dst + 64;
            _mm_stream_si32((int *)Dst - 10, Val);
            _mm_stream_si32((int *)Dst - 8, Val);
            --v6;
            _mm_stream_si32((int *)Dst - 6, Val);
            _mm_stream_si32((int *)Dst - 4, Val);
            _mm_stream_si32((int *)Dst - 2, Val);
          }
          while ( v6 != 0 );
          _InterlockedOr8((volatile signed __int8 *)&retaddr, 0);
        }
        else
        {
          do
          {
            *(_QWORD *)Dst = *(_QWORD *)&Val;
            *((_QWORD *)Dst + 1) = *(_QWORD *)&Val;
            *((_QWORD *)Dst + 2) = *(_QWORD *)&Val;
            Dst = (char *)Dst + 64;
            *((_QWORD *)Dst - 5) = *(_QWORD *)&Val;
            *((_QWORD *)Dst - 4) = *(_QWORD *)&Val;
            --v6;
            *((_QWORD *)Dst - 3) = *(_QWORD *)&Val;
            *((_QWORD *)Dst - 2) = *(_QWORD *)&Val;
            *((_QWORD *)Dst - 1) = *(_QWORD *)&Val;
          }
          while ( v6 != 0 );
        }
      }
    }
    v7 = Size;
    Size &= 7u;
    for ( i = v7 >> 3; i != 0; --i )
    {
      *(_QWORD *)Dst = *(_QWORD *)&Val;
      Dst = (char *)Dst + 8;
    }
  }
  for ( ; Size != 0; --Size )
  {
    *(_BYTE *)Dst = Val;
    Dst = (char *)Dst + 1;
  }
  return result;
}


// ===== __GSHandlerCheck_SEH @ 0x28006fad0 size=0x94 =====
__int64 __fastcall _GSHandlerCheck_SEH(
        struct _EXCEPTION_RECORD *ExceptionRecord,
        void *EstablisherFrame,
        struct _CONTEXT *ContextRecord,
        struct _DISPATCHER_CONTEXT *DispatcherContext)
{
  _DWORD *v8; // rbx
  int v9; // r11d
  unsigned int v10; // edx

  v8 = (char *)DispatcherContext->HandlerData + 16 * *(unsigned int *)DispatcherContext->HandlerData + 4;
  _GSHandlerCheckCommon((__int64)EstablisherFrame, (__int64)DispatcherContext);
  v9 = *v8 & 2;
  v10 = 1;
  if ( (ExceptionRecord->ExceptionFlags & 0x66) == 0 )
    v9 = *v8 & 1;
  if ( v9 != 0 )
    return (unsigned int)_C_specific_handler(ExceptionRecord, EstablisherFrame, ContextRecord, DispatcherContext);
  return v10;
}


// ===== __C_specific_handler @ 0x28006fb6a size=0x6 =====
// attributes: thunk
EXCEPTION_DISPOSITION __cdecl _C_specific_handler(
        struct _EXCEPTION_RECORD *ExceptionRecord,
        void *EstablisherFrame,
        struct _CONTEXT *ContextRecord,
        struct _DISPATCHER_CONTEXT *DispatcherContext)
{
  return __C_specific_handler(ExceptionRecord, EstablisherFrame, ContextRecord, DispatcherContext);
}


// ===== WdmlibInit @ 0x280077008 size=0x66 =====
PVOID WdmlibInit()
{
  __int64 (__usercall *SystemRoutineAddress)@<rax>(PDRIVER_OBJECT@<rcx>, ULONG@<edx>, PUNICODE_STRING@<r8>, int, char, __int64, __int64, PDEVICE_OBJECT); // rax
  PVOID result; // rax
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-18h] BYREF

  RtlInitUnicodeString(&DestinationString, L"IoCreateDeviceSecure");
  SystemRoutineAddress = (__int64 (__usercall *)@<rax>(PDRIVER_OBJECT@<rcx>, ULONG@<edx>, PUNICODE_STRING@<r8>, int, char, __int64, __int64, PDEVICE_OBJECT))MmGetSystemRoutineAddress(&DestinationString);
  if ( SystemRoutineAddress == nullptr )
    SystemRoutineAddress = IoDevObjCreateDeviceSecure;
  qword_280074648 = (__int64)SystemRoutineAddress;
  RtlInitUnicodeString(&DestinationString, L"IoValidateDeviceIoControlAccess");
  result = MmGetSystemRoutineAddress(&DestinationString);
  byte_280074640 = 1;
  qword_280074650 = (__int64)result;
  return result;
}


// ===== WdmlibIoCreateDeviceSecure @ 0x280077074 size=0x90 =====
NTSTATUS __stdcall WdmlibIoCreateDeviceSecure(
        PDRIVER_OBJECT DriverObject,
        ULONG DeviceExtensionSize,
        PUNICODE_STRING DeviceName,
        ULONG DeviceType,
        ULONG DeviceCharacteristics,
        BOOLEAN Exclusive,
        PCUNICODE_STRING DefaultSDDLString,
        LPCGUID DeviceClassGuid,
        PDEVICE_OBJECT *DeviceObject)
{
  if ( byte_280074640 == 0 )
    WdmlibInit();
  return qword_280074648(
           DriverObject,
           DeviceExtensionSize,
           DeviceName,
           DeviceType,
           DeviceCharacteristics,
           Exclusive,
           DefaultSDDLString,
           DeviceClassGuid,
           DeviceObject);
}


// ===== IopDevObjApplyPostCreationSettings @ 0x28007710c size=0xa3 =====
NTSTATUS __fastcall IopDevObjApplyPostCreationSettings(PVOID Object, __int64 a2)
{
  NTSTATUS result; // eax
  NTSTATUS v5; // ebx
  HANDLE Handle; // [rsp+40h] [rbp-18h] BYREF
  SECURITY_INFORMATION SecurityInformation; // [rsp+70h] [rbp+18h]
  ACCESS_MASK DesiredAccess; // [rsp+78h] [rbp+20h] BYREF

  if ( (*(_BYTE *)a2 & 2) == 0 )
    return 0;
  result = SeUtilSecurityInfoFromSecurityDescriptor(*(PSECURITY_DESCRIPTOR *)(a2 + 8));
  if ( result >= 0 )
  {
    SeSetSecurityAccessMask(SecurityInformation, &DesiredAccess);
    result = ObOpenObjectByPointer(Object, 0x200u, nullptr, DesiredAccess, IoDeviceObjectType, 0, &Handle);
    if ( result >= 0 )
    {
      v5 = ZwSetSecurityObject(Handle, SecurityInformation, *(PSECURITY_DESCRIPTOR *)(a2 + 8));
      ZwClose(Handle);
      return v5;
    }
  }
  return result;
}


// ===== IoDevObjCreateDeviceSecure @ 0x2800771b8 size=0x1af =====
__int64 __fastcall IoDevObjCreateDeviceSecure(
        PDRIVER_OBJECT DriverObject,
        ULONG DeviceExtensionSize,
        PUNICODE_STRING DeviceName,
        ULONG a4,
        ULONG a5,
        BOOLEAN a6,
        __int64 a7,
        __int64 a8,
        PDEVICE_OBJECT DeviceObject)
{
  PDEVICE_OBJECT v9; // rsi
  ULONG DeviceCharacteristics; // ebp
  __int64 result; // rax
  char v16; // al
  NTSTATUS updated; // ebx
  BOOLEAN Exclusive; // cl
  ULONG v19[5]; // [rsp+40h] [rbp-58h] BYREF
  BOOLEAN v20; // [rsp+54h] [rbp-44h]
  _BYTE v21[24]; // [rsp+58h] [rbp-40h] BYREF
  __int64 v22; // [rsp+B0h] [rbp+18h] BYREF

  v9 = DeviceObject;
  DeviceObject = nullptr;
  DeviceCharacteristics = a5;
  *(_QWORD *)&v9->Type = 0;
  if ( DeviceName == nullptr && (DeviceCharacteristics & 0x80u) == 0 )
    return 3221225485LL;
  if ( a8 == 0 )
  {
    PpRegStateInitEmptyCreationSettings(v19);
LABEL_8:
    v16 = v19[0];
    if ( (v19[0] & 2) == 0 )
    {
      updated = SeSddlSecurityDescriptorFromSDDL(a7, 1, &v22);
      if ( updated < 0
        || (PpRegStateLoadSecurityDescriptor(v22, v19), a8 != 0)
        && (PpRegStateInitEmptyCreationSettings(v21),
            PpRegStateLoadSecurityDescriptor(v22, v21),
            (updated = PpRegStateUpdateStackCreationSettings(a8, v21)) < 0) )
      {
$Exit$30769:
        PpRegStateFreeStackCreationSettings(v19);
        return (unsigned int)updated;
      }
      v16 = v19[0];
    }
    Exclusive = a6;
    if ( (v16 & 1) != 0 )
      a4 = v19[1];
    if ( (v16 & 4) != 0 )
      DeviceCharacteristics = v19[4];
    if ( (v16 & 8) != 0 )
      Exclusive = v20;
    updated = IoCreateDevice(
                DriverObject,
                DeviceExtensionSize,
                DeviceName,
                a4,
                DeviceCharacteristics,
                Exclusive,
                &DeviceObject);
    if ( updated >= 0 )
    {
      updated = IopDevObjApplyPostCreationSettings(DeviceObject, (__int64)v19);
      if ( updated >= 0 )
        *(_QWORD *)&v9->Type = DeviceObject;
      else
        IoDeleteDevice(DeviceObject);
    }
    goto $Exit$30769;
  }
  result = PpRegStateReadCreateClassCreationSettings(a8, DriverObject, v19);
  if ( (int)result >= 0 )
    goto LABEL_8;
  return result;
}


// ===== PpRegStateLoadSecurityDescriptor @ 0x280077370 size=0xb =====
void __fastcall PpRegStateLoadSecurityDescriptor(__int64 a1, __int64 a2)
{
  *(_DWORD *)a2 = 2;
  *(_QWORD *)(a2 + 8) = a1;
}


// ===== PpRegStateFreeStackCreationSettings @ 0x280077384 size=0x1a =====
void __fastcall PpRegStateFreeStackCreationSettings(__int64 a1)
{
  if ( (*(_BYTE *)a1 & 2) != 0 )
    ExFreePoolWithTag(*(PVOID *)(a1 + 8), 0);
}


// ===== PiRegStateOpenClassKey @ 0x2800773a4 size=0x196 =====
__int64 __fastcall PiRegStateOpenClassKey(unsigned int *a1, unsigned int a2, int a3, int *a4, _QWORD *a5)
{
  __int64 result; // rax
  int WstrKey; // eax
  int v11; // ebx
  int v12; // [rsp+70h] [rbp-B8h] BYREF
  HANDLE Handle; // [rsp+78h] [rbp-B0h] BYREF
  _QWORD v14[2]; // [rsp+80h] [rbp-A8h] BYREF
  wchar_t Dest[40]; // [rsp+90h] [rbp-98h] BYREF

  *a5 = 0;
  if ( a4 != nullptr )
    *a4 = 0;
  result = CmRegUtilOpenExistingWstrKey(
             0,
             L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Class",
             131097,
             &Handle);
  if ( (int)result >= 0 )
  {
    snwprintf(
      Dest,
      0x27u,
      L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
      *a1,
      *((unsigned __int16 *)a1 + 2),
      *((unsigned __int16 *)a1 + 3),
      *((unsigned __int8 *)a1 + 8),
      *((unsigned __int8 *)a1 + 9),
      *((unsigned __int8 *)a1 + 10),
      *((unsigned __int8 *)a1 + 11),
      *((unsigned __int8 *)a1 + 12),
      *((unsigned __int8 *)a1 + 13),
      *((unsigned __int8 *)a1 + 14),
      *((unsigned __int8 *)a1 + 15));
    Dest[38] = 0;
    if ( a3 != 0 )
    {
      WstrKey = CmRegUtilCreateWstrKey((_DWORD)Handle, (unsigned int)Dest, a2, 0, 0, (__int64)&v12, (__int64)v14);
    }
    else
    {
      WstrKey = CmRegUtilOpenExistingWstrKey(Handle, Dest, a2, v14);
      v12 = 2;
    }
    v11 = WstrKey;
    ZwClose(Handle);
    if ( v11 >= 0 )
    {
      *a5 = v14[0];
      if ( a4 != nullptr )
        *a4 = v12;
    }
    return (unsigned int)v11;
  }
  return result;
}


// ===== PpRegStateInitEmptyCreationSettings @ 0x280077540 size=0x12 =====
__int64 __fastcall PpRegStateInitEmptyCreationSettings(__int64 a1)
{
  *(_DWORD *)a1 = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  return 0;
}


// ===== PiRegStateReadStackCreationSettingsFromKey @ 0x280077558 size=0x1c4 =====
__int64 __fastcall PiRegStateReadStackCreationSettingsFromKey(void *a1, __int64 a2)
{
  int FullBuffer; // eax
  __int64 v5; // r9
  int v6; // ebx
  PVOID v7; // rax
  int Dword; // eax
  int v9; // eax
  int v10; // eax
  void *v11; // rcx
  PVOID P[9]; // [rsp+30h] [rbp-48h] BYREF
  char v14; // [rsp+88h] [rbp+10h]
  PVOID SecurityDescriptor; // [rsp+98h] [rbp+20h] BYREF

  *(_DWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  P[0] = nullptr;
  FullBuffer = CmRegUtilWstrValueGetFullBuffer(a1, (__int64)P);
  v6 = FullBuffer;
  if ( FullBuffer < 0 )
  {
    if ( FullBuffer == -1073741772 )
    {
      SecurityDescriptor = nullptr;
      v6 = 0;
    }
  }
  else
  {
    LOBYTE(v5) = 1;
    v6 = SeCaptureSecurityDescriptor((char *)P[0] + *((unsigned int *)P[0] + 2), 0, 1, v5, &SecurityDescriptor);
  }
  if ( P[0] != nullptr )
    ExFreePoolWithTag(P[0], 0);
  if ( v6 < 0 )
    goto $ErrorExit$30792;
  if ( SecurityDescriptor != nullptr )
  {
    v6 = SeUtilSecurityInfoFromSecurityDescriptor(SecurityDescriptor);
    if ( v6 < 0 )
      goto $ErrorExit$30792;
    if ( v14 != 0 )
    {
      ExFreePoolWithTag(SecurityDescriptor, 0);
    }
    else
    {
      v7 = SecurityDescriptor;
      *(_DWORD *)a2 |= 2u;
      *(_QWORD *)(a2 + 8) = v7;
    }
  }
  Dword = CmRegUtilWstrValueGetDword(a1, L"DeviceType", 0, a2 + 4);
  v6 = Dword;
  if ( Dword < 0 )
  {
    if ( Dword != -1073741772 )
      goto $ErrorExit$30792;
  }
  else
  {
    *(_DWORD *)a2 |= 1u;
  }
  v9 = CmRegUtilWstrValueGetDword(a1, L"DeviceCharacteristics", 0, a2 + 16);
  v6 = v9;
  if ( v9 < 0 )
  {
    if ( v9 != -1073741772 )
      goto $ErrorExit$30792;
  }
  else
  {
    *(_DWORD *)a2 |= 4u;
  }
  v10 = CmRegUtilWstrValueGetDword(a1, L"Exclusive", 0, a2 + 20);
  v6 = v10;
  if ( v10 >= 0 )
  {
    *(_DWORD *)a2 |= 8u;
    return (unsigned int)v6;
  }
  if ( v10 == -1073741772 )
    return 0;
$ErrorExit$30792:
  v11 = *(void **)(a2 + 8);
  if ( v11 != nullptr )
    ExFreePoolWithTag(v11, 0);
  *(_DWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  return (unsigned int)v6;
}


// ===== PpRegStateReadCreateClassCreationSettings @ 0x280077724 size=0x127 =====
__int64 __fastcall PpRegStateReadCreateClassCreationSettings(unsigned int *a1, __int64 a2, __int64 a3)
{
  __int64 result; // rax
  int v6; // ebx
  int StackCreationSettingsFromKey; // eax
  void *v8; // rcx
  HANDLE v9; // rdi
  void *v10; // [rsp+30h] [rbp-18h] BYREF
  _BYTE v11[8]; // [rsp+60h] [rbp+18h] BYREF
  HANDLE Handle; // [rsp+68h] [rbp+20h] BYREF

  *(_DWORD *)a3 = 0;
  *(_QWORD *)(a3 + 8) = 0;
  *(_DWORD *)(a3 + 4) = 0;
  *(_DWORD *)(a3 + 16) = 0;
  *(_DWORD *)(a3 + 20) = 0;
  Handle = nullptr;
  v10 = nullptr;
  result = PiRegStateOpenClassKey(a1, 0xF003Fu, 1, (int *)v11, &Handle);
  if ( (int)result >= 0 )
  {
    if ( *(_DWORD *)v11 == 2 )
    {
      v6 = CmRegUtilOpenExistingWstrKey(Handle, L"Properties", 131097, &v10);
      ZwClose(Handle);
      if ( v6 < 0 )
      {
        if ( v6 == -1073741772 )
          return 0;
        return (unsigned int)v6;
      }
      StackCreationSettingsFromKey = PiRegStateReadStackCreationSettingsFromKey(v10, a3);
      v8 = v10;
      v6 = StackCreationSettingsFromKey;
    }
    else
    {
      v9 = Handle;
      if ( *(_QWORD *)(a2 + 48) == -24 )
      {
        v6 = -1073741670;
      }
      else
      {
        v6 = CmRegUtilWstrValueSetUcString(Handle);
        if ( v6 >= 0 )
        {
          wcscpy((wchar_t *)v11, L"1");
          v6 = CmRegUtilWstrValueSetWstrString(v9, L"NoDisplayClass", (PCWSTR)v11);
          if ( v6 >= 0 )
            v6 = CmRegUtilWstrValueSetWstrString(v9, L"NoUseClass", (PCWSTR)v11);
        }
      }
      v8 = v9;
    }
    ZwClose(v8);
    return (unsigned int)v6;
  }
  return result;
}


// ===== PpRegStateUpdateStackCreationSettings @ 0x280077854 size=0x123 =====
__int64 __fastcall PpRegStateUpdateStackCreationSettings(unsigned int *a1, __int64 a2)
{
  __int64 result; // rax
  __int64 v4; // r9
  int v5; // eax
  void *v6; // rbx
  int WstrKey; // ebx
  ULONG v8; // eax
  HANDLE KeyHandle[3]; // [rsp+40h] [rbp-18h] BYREF
  PVOID P; // [rsp+70h] [rbp+18h] BYREF
  HANDLE Handle; // [rsp+78h] [rbp+20h] BYREF

  result = PiRegStateOpenClassKey(a1, 0xF003Fu, 0, nullptr, &Handle);
  if ( (int)result >= 0 )
  {
    v5 = dword_280074658;
    v6 = &unk_280074110;
    if ( dword_280074658 == 0 )
    {
      LOBYTE(v4) = 1;
      if ( (int)SeCaptureSecurityDescriptor(&unk_280074110, 0, 1, v4, &P) < 0 )
      {
        v5 = 2;
        dword_280074658 = 2;
      }
      else
      {
        dword_280074658 = 1;
        ExFreePoolWithTag(P, 0);
        v5 = dword_280074658;
      }
    }
    if ( v5 != 1 )
      v6 = nullptr;
    P = v6;
    WstrKey = CmRegUtilCreateWstrKey(
                (_DWORD)Handle,
                (unsigned int)L"Properties",
                983103,
                0,
                (__int64)v6,
                0,
                (__int64)KeyHandle);
    ZwClose(Handle);
    if ( WstrKey >= 0 )
    {
      v8 = RtlLengthSecurityDescriptor(*(PSECURITY_DESCRIPTOR *)(a2 + 8));
      WstrKey = CmRegUtilWstrValueSetFullBuffer(KeyHandle[0], v8);
      ZwClose(KeyHandle[0]);
    }
    return (unsigned int)WstrKey;
  }
  return result;
}


// ===== SepSddlParseWideStringUlong @ 0x280077980 size=0xda =====
__int64 __fastcall SepSddlParseWideStringUlong(unsigned __int16 *a1, unsigned __int16 **a2, unsigned int *a3)
{
  unsigned __int16 *v5; // r10
  unsigned __int16 *v6; // r9
  bool v7; // cf
  int v8; // edx
  unsigned int v9; // r8d
  int v10; // ecx
  unsigned __int16 v11; // ax

  *a3 = 0;
  *a2 = a1;
  v5 = a1;
  v6 = a1;
  v7 = *a1 < 0x30u;
  if ( *a1 != 48 )
  {
LABEL_6:
    if ( !v7 )
    {
      v8 = 10;
      if ( *a1 <= 0x39u )
        goto LABEL_9;
    }
    goto LABEL_8;
  }
  if ( a1[1] != 120 && a1[1] != 88 )
  {
    v7 = *a1 < 0x30u;
    goto LABEL_6;
  }
  v5 = a1 + 2;
  v6 = a1 + 2;
LABEL_8:
  v8 = 16;
LABEL_9:
  v9 = 0;
  while ( 1 )
  {
    v11 = *v6;
    if ( *v6 == 0 )
      break;
    if ( v11 < 0x30u || v11 > 0x39u )
    {
      if ( v8 != 16 )
        break;
      if ( v11 < 0x41u || v11 > 0x46u )
      {
        if ( v11 < 0x61u || v11 > 0x66u )
          break;
        v10 = v11 - 87;
      }
      else
      {
        v10 = v11 - 55;
      }
    }
    else
    {
      v10 = v11 - 48;
    }
    if ( v10 + v8 * v9 < v9 )
      return 0;
    v9 = v10 + v8 * v9;
    ++v6;
  }
  if ( v6 != v5 )
  {
    *a2 = v6;
    *a3 = v9;
    return 1;
  }
  return 0;
}


// ===== SepSddlAddAceToAcl @ 0x280077a60 size=0xdf =====
NTSTATUS __fastcall SepSddlAddAceToAcl(
        const void **a1,
        _DWORD *a2,
        __int64 a3,
        __int64 a4,
        ACCESS_MASK AccessMask,
        int a6,
        PSID Sid)
{
  struct _ACL *v7; // rdi
  size_t v8; // r12
  ULONG v11; // ebx
  int v12; // ebp
  unsigned int v13; // ebx
  struct _ACL *PoolWithTag; // rax
  struct _ACL *v15; // r13

  v7 = (struct _ACL *)*a1;
  v8 = (unsigned int)*a2;
  v11 = RtlLengthSid(Sid) + 8;
  v12 = v11 + v8;
  if ( v11 + (unsigned int)v8 > v7->AclSize )
  {
    v13 = v8 + a6 * v11;
    PoolWithTag = (struct _ACL *)ExAllocatePoolWithTag(PagedPool, v13, 0x6C416553u);
    v15 = PoolWithTag;
    if ( PoolWithTag == nullptr )
      return -1073741670;
    memset(PoolWithTag, 0, v13);
    memmove(v15, *a1, v8);
    v15->AclSize = v13;
    ExFreePoolWithTag(v7, 0);
    *a1 = v15;
    v7 = v15;
  }
  *a2 = v12;
  return RtlAddAccessAllowedAce(v7, 2u, AccessMask, Sid);
}


// ===== SepSddlLookupAccessMaskInTable @ 0x280077b48 size=0x91 =====
__int64 __fastcall SepSddlLookupAccessMaskInTable(wchar_t *Str1, _DWORD *a2, _QWORD *a3)
{
  unsigned int v6; // ebx
  wchar_t **i; // rdi

  v6 = 0;
  for ( i = &off_280074260; wcsnicmp(Str1, *i, *((unsigned int *)i + 2)) != 0; i += 2 )
  {
    if ( ++v6 >= 8 )
    {
      *a2 = 0;
      *a3 = Str1;
      return 0;
    }
  }
  *a2 = *((_DWORD *)&off_280074260 + 4 * v6 + 3);
  *a3 = &Str1[*((unsigned int *)&off_280074260 + 4 * v6 + 2)];
  return 1;
}


// ===== SepSddlGetSidForString @ 0x280077be0 size=0xbe =====
__int64 __fastcall SepSddlGetSidForString(wchar_t *Str1, _QWORD *a2, _QWORD *a3)
{
  __int64 v6; // rdi
  unsigned int *i; // rsi
  __int64 v9; // rdi

  v6 = 0;
  for ( i = (unsigned int *)&unk_280074154; wcsnicmp(Str1, (const wchar_t *)&unk_280074140 + 12 * v6 + 6, *i) != 0; i += 6 )
  {
    v6 = (unsigned int)(v6 + 1);
    if ( (unsigned int)v6 >= 0xC )
    {
      *a2 = 0;
      return 3221225587LL;
    }
  }
  v9 = 3 * v6;
  *a3 = &Str1[*((unsigned int *)&unk_280074140 + 2 * v9 + 5)];
  if ( *((_DWORD *)&unk_280074140 + 2 * v9 + 2) != 1 || IoIsWdmVersionAvailable(1u, 0x20u) != 0 )
    *a2 = *(LUID *)((char *)&SeExports->SeCreateTokenPrivilege + *((_QWORD *)&unk_280074140 + v9));
  else
    *a2 = 0;
  return 0;
}


// ===== SepSddlGetAclForString @ 0x280077ca4 size=0x3b9 =====
__int64 __fastcall SepSddlGetAclForString(wchar_t *Str1, const void **a2, wchar_t **a3)
{
  wchar_t *v5; // rbx
  unsigned int SidForString; // esi
  unsigned int v7; // r12d
  wchar_t *v8; // rax
  __int64 v10; // rcx
  wchar_t *v11; // rdi
  bool v12; // zf
  wchar_t *v13; // rax
  int v14; // edi
  wchar_t *i; // rax
  unsigned int v16; // r14d
  _QWORD *PoolWithTag; // rax
  unsigned int v18; // ebp
  PVOID v19; // rax
  int v20; // r12d
  ACCESS_MASK AccessMask; // ebp
  unsigned __int16 *j; // rbx
  __int64 k; // rax
  unsigned __int16 *v24; // rax
  _WORD *v25; // rbx
  _WORD *v26; // [rsp+40h] [rbp-58h] BYREF
  PSID Sid[10]; // [rsp+48h] [rbp-50h] BYREF
  ACCESS_MASK v28; // [rsp+A0h] [rbp+8h] BYREF
  int v29; // [rsp+A8h] [rbp+10h] BYREF
  int v30; // [rsp+B0h] [rbp+18h] BYREF
  unsigned __int16 *v31; // [rsp+B8h] [rbp+20h] BYREF

  *a2 = nullptr;
  v5 = Str1;
  SidForString = 0;
  v7 = 0;
  Sid[0] = nullptr;
  v8 = wcschr(Str1, 0x3Au);
  *a3 = v8;
  if ( v8 == v5 )
    return 3221225485LL;
  if ( v8 != nullptr )
  {
    v13 = v8 - 1;
  }
  else
  {
    v10 = -1;
    v11 = v5;
    do
    {
      if ( v10 == 0 )
        break;
      v12 = *v11++ == 0;
      --v10;
    }
    while ( !v12 );
    v13 = &v5[-v10 - 2];
  }
  *a3 = v13;
  v14 = 0;
  for ( i = v5; i < *a3; ++i )
  {
    if ( *i == 59 )
    {
      ++v7;
    }
    else if ( *i != 32 )
    {
      v14 = 1;
    }
  }
  v16 = v7 / 5;
  if ( v7 != 5 * (v7 / 5) || v7 == 0 && v14 != 0 )
    return (unsigned int)-1073741811;
  if ( v16 == 0 )
  {
    PoolWithTag = ExAllocatePoolWithTag(PagedPool, 8u, 0x6C416553u);
    *a2 = PoolWithTag;
    if ( PoolWithTag != nullptr )
    {
      *PoolWithTag = 0;
      *(_BYTE *)*a2 = 2;
      *((_BYTE *)*a2 + 1) = 0;
      *((_WORD *)*a2 + 1) = 8;
      *((_WORD *)*a2 + 2) = 0;
      *((_WORD *)*a2 + 3) = 0;
      return SidForString;
    }
    return (unsigned int)-1073741670;
  }
  v18 = 48 * v16 + 8;
  if ( v18 > 0xFFFF )
    v18 = 0xFFFF;
  v19 = ExAllocatePoolWithTag(PagedPool, v18, 0x6C416553u);
  *a2 = v19;
  if ( v19 == nullptr )
    return (unsigned int)-1073741670;
  v29 = 8;
  memset(v19, 0, v18);
  *(_BYTE *)*a2 = 2;
  v20 = 0;
  *((_BYTE *)*a2 + 1) = 0;
  *((_WORD *)*a2 + 1) = v18;
  *((_WORD *)*a2 + 2) = 0;
  *((_WORD *)*a2 + 3) = 0;
  while ( 1 )
  {
    AccessMask = 0;
    v28 = 0;
    while ( *v5 == 32 )
      ++v5;
    if ( *v5 == 40 )
LABEL_30:
      ++v5;
    if ( *v5 == 32 )
      goto LABEL_30;
    if ( wcsnicmp(v5, L"A", 1u) != 0 )
      break;
    for ( j = v5 + 2; *j == 32; ++j )
      ;
    if ( *j != 59 )
    {
      SidForString = -1073741811;
      goto LABEL_75;
    }
    do
      ++j;
    while ( *j == 32 );
    if ( *j != 59 )
    {
      do
      {
        while ( *j == 32 )
          ++j;
        if ( (unsigned int)SepSddlLookupAccessMaskInTable(j, &v30, &v31) != 0 )
        {
          AccessMask |= v30;
          v24 = v31;
          v28 = AccessMask;
        }
        else
        {
          SepSddlParseWideStringUlong(j, &v31, &v28);
          v24 = v31;
          AccessMask = v28;
          if ( v31 == j )
          {
            SidForString = -1073741811;
            goto LABEL_40;
          }
        }
        j = v24;
      }
      while ( *v24 != 59 );
    }
    ++j;
LABEL_40:
    if ( SidForString != 0 )
      goto LABEL_75;
    for ( k = 2; k != 0; --k )
    {
      while ( *j == 32 )
        ++j;
      if ( *j != 59 )
        SidForString = -1073741811;
      ++j;
    }
    if ( SidForString != 0 )
      goto LABEL_75;
    while ( *j == 32 )
      ++j;
    SidForString = SepSddlGetSidForString(j, Sid, &v26);
    if ( SidForString != 0 )
      goto LABEL_75;
    v25 = v26;
    if ( v26 == nullptr )
      goto LABEL_71;
    if ( *v26 == 32 )
    {
      do
        ++v25;
      while ( *v25 == 32 );
      v26 = v25;
    }
    if ( *v25 != 41 )
    {
LABEL_71:
      SidForString = -1073741705;
      goto LABEL_75;
    }
    v5 = v25 + 1;
    if ( Sid[0] != nullptr )
    {
      SidForString = SepSddlAddAceToAcl(a2, &v29, 0, 0, AccessMask, v16 - v20, Sid[0]);
      if ( SidForString != 0 )
        goto LABEL_75;
    }
    if ( *v5 == 40 )
      ++v5;
    if ( ++v20 >= v16 )
      goto LABEL_74;
  }
  SidForString = -1073741811;
LABEL_74:
  if ( SidForString != 0 )
  {
LABEL_75:
    ExFreePoolWithTag((PVOID)*a2, 0);
    *a2 = nullptr;
  }
  else
  {
    *((_WORD *)*a2 + 1) = v29;
  }
  return SidForString;
}


// ===== SepSddlDaclFromSDDLString @ 0x280078064 size=0xc0 =====
__int64 __fastcall SepSddlDaclFromSDDLString(_WORD *a1, int a2, int *a3, PVOID *a4)
{
  wchar_t *v7; // rcx
  int v8; // edi
  unsigned int AclForString; // ebx
  wchar_t *i; // rax
  PVOID P; // [rsp+40h] [rbp+8h] BYREF
  wchar_t *v12; // [rsp+50h] [rbp+18h] BYREF

  *a4 = nullptr;
  *a3 = 0;
  while ( *a1 == 32 )
    ++a1;
  if ( *a1 != 68 || a1[1] != 58 )
    return 3221225485LL;
  v7 = a1 + 2;
  v8 = a2 != 0 ? 8 : 0;
  if ( *v7 == 80 )
  {
    ++v7;
    v8 |= 0x1000u;
  }
  AclForString = SepSddlGetAclForString(v7, (const void **)&P, &v12);
  if ( AclForString != 0 )
    goto LABEL_15;
  for ( i = v12; *i == 32; ++i )
    ;
  if ( *i != 0 )
  {
    AclForString = -1073741811;
LABEL_15:
    if ( P != nullptr )
      ExFreePoolWithTag(P, 0);
    return AclForString;
  }
  *a4 = P;
  *a3 = v8;
  return AclForString;
}


// ===== SepSddlSecurityDescriptorFromSDDLString @ 0x28007812c size=0xf9 =====
__int64 __fastcall SepSddlSecurityDescriptorFromSDDLString(_WORD *a1, int a2, _QWORD *a3)
{
  void *v4; // rdi
  int v5; // ebx
  PVOID PoolWithTag; // rax
  PACL Dacl; // [rsp+20h] [rbp-38h] BYREF
  _BYTE SecurityDescriptor[2]; // [rsp+28h] [rbp-30h] BYREF
  __int16 v10; // [rsp+2Ah] [rbp-2Eh]
  ULONG BufferLength; // [rsp+70h] [rbp+18h] BYREF
  int v12; // [rsp+78h] [rbp+20h] BYREF

  Dacl = nullptr;
  v4 = nullptr;
  *a3 = 0;
  v5 = SepSddlDaclFromSDDLString(a1, a2, &v12, (PVOID *)&Dacl);
  if ( v5 >= 0 )
  {
    RtlCreateSecurityDescriptor(SecurityDescriptor, 1u);
    RtlSetDaclSecurityDescriptor(SecurityDescriptor, 1u, Dacl, 0);
    BufferLength = 0;
    v10 |= v12;
    RtlAbsoluteToSelfRelativeSD(SecurityDescriptor, nullptr, &BufferLength);
    PoolWithTag = ExAllocatePoolWithTag(PagedPool, BufferLength, 0x64536553u);
    v4 = PoolWithTag;
    if ( PoolWithTag != nullptr )
    {
      v5 = RtlAbsoluteToSelfRelativeSD(SecurityDescriptor, PoolWithTag, &BufferLength);
      if ( v5 >= 0 )
      {
        ExFreePoolWithTag(Dacl, 0);
        *a3 = v4;
        return (unsigned int)v5;
      }
    }
    else
    {
      v5 = -1073741670;
    }
  }
  if ( Dacl != nullptr )
    ExFreePoolWithTag(Dacl, 0);
  if ( v4 != nullptr )
    ExFreePoolWithTag(v4, 0);
  return (unsigned int)v5;
}


// ===== SeSddlSecurityDescriptorFromSDDL @ 0x28007822c size=0xc2 =====
__int64 __fastcall SeSddlSecurityDescriptorFromSDDL(unsigned __int16 *a1, int a2, _QWORD *a3)
{
  unsigned __int64 v3; // r9
  _WORD *v7; // rcx
  _WORD *PoolWithTag; // rax
  _WORD *v10; // rsi
  unsigned int v11; // ebx

  v3 = *a1;
  if ( a1[1] == v3 + 2 )
  {
    v7 = *((_WORD **)a1 + 1);
    if ( v7[v3 >> 1] == 0 )
      return SepSddlSecurityDescriptorFromSDDLString(v7, a2, a3);
  }
  PoolWithTag = ExAllocatePoolWithTag(PagedPool, v3 + 2, 0x73546553u);
  v10 = PoolWithTag;
  if ( PoolWithTag != nullptr )
  {
    memmove(PoolWithTag, *((const void **)a1 + 1), *a1);
    v10[(unsigned __int64)*a1 >> 1] = 0;
    v11 = SepSddlSecurityDescriptorFromSDDLString(v10, a2, a3);
    ExFreePoolWithTag(v10, 0);
    return v11;
  }
  else
  {
    *a3 = 0;
    return 3221225626LL;
  }
}


// ===== SeSetSecurityAccessMask @ 0x2800782f4 size=0x26 =====
void __fastcall SeSetSecurityAccessMask(char a1, _DWORD *a2)
{
  *a2 = 0;
  if ( (a1 & 1) != 0 || (a1 & 2) != 0 )
    *a2 = 0x80000;
  if ( (a1 & 4) != 0 )
    *a2 |= 0x40000u;
  if ( (a1 & 8) != 0 )
    *a2 |= 0x1000000u;
}


// ===== SeUtilSecurityInfoFromSecurityDescriptor @ 0x280078320 size=0xc8 =====
NTSTATUS __fastcall SeUtilSecurityInfoFromSecurityDescriptor(
        PSECURITY_DESCRIPTOR SecurityDescriptor,
        unsigned __int8 *a2,
        _DWORD *a3)
{
  NTSTATUS result; // eax
  int v7; // ebx
  PSID Owner; // [rsp+20h] [rbp-28h] BYREF
  PACL Sacl[4]; // [rsp+28h] [rbp-20h] BYREF
  unsigned __int8 OwnerDefaulted; // [rsp+58h] [rbp+10h] BYREF
  unsigned __int8 SaclPresent; // [rsp+68h] [rbp+20h] BYREF

  *a2 = 0;
  *a3 = 0;
  result = RtlGetOwnerSecurityDescriptor(SecurityDescriptor, &Owner, &OwnerDefaulted);
  if ( result >= 0 )
  {
    v7 = Owner != nullptr;
    result = RtlGetGroupSecurityDescriptor(SecurityDescriptor, &Owner, &OwnerDefaulted);
    if ( result >= 0 )
    {
      if ( Owner != nullptr )
        v7 |= 2u;
      result = RtlGetSaclSecurityDescriptor(SecurityDescriptor, &SaclPresent, Sacl, &OwnerDefaulted);
      if ( result >= 0 )
      {
        if ( SaclPresent != 0 )
          v7 |= 8u;
        result = RtlGetDaclSecurityDescriptor(SecurityDescriptor, &SaclPresent, Sacl, &OwnerDefaulted);
        if ( result >= 0 )
        {
          if ( SaclPresent != 0 )
            v7 |= 4u;
          *a2 = OwnerDefaulted;
          *a3 = v7;
          return 0;
        }
      }
    }
  }
  return result;
}


// ===== CmpRegUtilAllocateUnicodeString @ 0x2800783f0 size=0x45 =====
__int64 __fastcall CmpRegUtilAllocateUnicodeString(__int64 a1, unsigned __int16 a2)
{
  PVOID PoolWithTag; // rax

  *(_WORD *)a1 = 0;
  *(_WORD *)(a1 + 2) = a2 + 2;
  PoolWithTag = ExAllocatePoolWithTag(PagedPool, a2 + 2LL, 0x63557050u);
  *(_QWORD *)(a1 + 8) = PoolWithTag;
  return PoolWithTag == nullptr ? 0xC000009A : 0;
}


// ===== CmRegUtilUcValueSetUcString @ 0x28007843c size=0xfa =====
__int64 __fastcall CmRegUtilUcValueSetUcString(HANDLE KeyHandle, PUNICODE_STRING ValueName, unsigned __int16 *a3)
{
  unsigned __int64 v4; // rdx
  int v7; // ebx
  const void *v8; // rdx
  struct _UNICODE_STRING UnicodeString; // [rsp+30h] [rbp-18h] BYREF

  v4 = *a3;
  if ( a3[1] - (unsigned int)v4 < 2 )
  {
    v7 = CmpRegUtilAllocateUnicodeString((__int64)&UnicodeString, v4);
    if ( v7 >= 0 )
    {
      v8 = *((const void **)a3 + 1);
      UnicodeString.Length = *a3;
      memmove(UnicodeString.Buffer, v8, UnicodeString.Length);
      UnicodeString.Buffer[(unsigned __int64)UnicodeString.Length >> 1] = 0;
      v7 = ZwSetValueKey(KeyHandle, ValueName, 0, 1u, UnicodeString.Buffer, UnicodeString.Length + 2);
      RtlFreeUnicodeString(&UnicodeString);
    }
  }
  else
  {
    *(_WORD *)(*((_QWORD *)a3 + 1) + 2 * (v4 >> 1)) = 0;
    return (unsigned int)ZwSetValueKey(KeyHandle, ValueName, 0, 1u, *((PVOID *)a3 + 1), *a3 + 2);
  }
  return (unsigned int)v7;
}


// ===== CmRegUtilUcValueGetDword @ 0x28007853c size=0x71 =====
NTSTATUS __fastcall CmRegUtilUcValueGetDword(void *a1, struct _UNICODE_STRING *a2, int a3, _DWORD *a4)
{
  NTSTATUS result; // eax
  ULONG v7; // [rsp+30h] [rbp-28h] BYREF
  _DWORD v8[4]; // [rsp+38h] [rbp-20h] BYREF

  result = ZwQueryValueKey(a1, a2, KeyValuePartialInformation, v8, 0x10u, &v7);
  if ( result >= 0 )
  {
    if ( v8[1] == 4 )
      a3 = v8[3];
    else
      result = -1073741788;
  }
  *a4 = a3;
  return result;
}


// ===== CmRegUtilCreateUcKey @ 0x2800785b4 size=0x96 =====
__int64 __fastcall CmRegUtilCreateUcKey(
        void *a1,
        struct _UNICODE_STRING *a2,
        ACCESS_MASK a3,
        ULONG a4,
        void *a5,
        _DWORD *a6,
        _QWORD *a7)
{
  NTSTATUS v7; // r11d
  void *v8; // rdx
  int v9; // ecx
  struct _OBJECT_ATTRIBUTES v11; // [rsp+40h] [rbp-38h] BYREF
  void *v12; // [rsp+80h] [rbp+8h] BYREF

  v11.Length = 48;
  v11.RootDirectory = a1;
  v11.Attributes = 576;
  v11.SecurityQualityOfService = nullptr;
  v11.SecurityDescriptor = a5;
  v11.ObjectName = a2;
  v7 = ZwCreateKey(&v12, a3, &v11, 0, nullptr, a4, (PULONG)&a5);
  if ( v7 >= 0 )
  {
    v9 = (int)a5;
    v8 = v12;
  }
  else
  {
    v8 = nullptr;
    v9 = 0;
  }
  *a7 = v8;
  if ( a6 != nullptr )
    *a6 = v9;
  return (unsigned int)v7;
}


// ===== CmRegUtilOpenExistingUcKey @ 0x280078650 size=0x56 =====
NTSTATUS __fastcall CmRegUtilOpenExistingUcKey(void *a1, struct _UNICODE_STRING *a2, ACCESS_MASK a3, _QWORD *a4)
{
  NTSTATUS result; // eax
  struct _OBJECT_ATTRIBUTES v6; // [rsp+20h] [rbp-38h] BYREF
  void *v7; // [rsp+60h] [rbp+8h] BYREF

  *a4 = 0;
  v6.Length = 48;
  v6.RootDirectory = a1;
  v6.Attributes = 576;
  v6.SecurityDescriptor = nullptr;
  v6.SecurityQualityOfService = nullptr;
  v6.ObjectName = a2;
  result = ZwOpenKey(&v7, a3, &v6);
  if ( result >= 0 )
    *a4 = v7;
  return result;
}


// ===== CmRegUtilWstrValueSetWstrString @ 0x2800786ac size=0x4f =====
NTSTATUS __fastcall CmRegUtilWstrValueSetWstrString(HANDLE KeyHandle, PCWSTR SourceString, PCWSTR a3)
{
  NTSTATUS result; // eax
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-28h] BYREF
  struct _UNICODE_STRING ValueName; // [rsp+30h] [rbp-18h] BYREF

  result = WdmlibRtlInitUnicodeStringEx(&DestinationString, a3);
  if ( result >= 0 )
  {
    result = WdmlibRtlInitUnicodeStringEx(&ValueName, SourceString);
    if ( result >= 0 )
      return CmRegUtilUcValueSetUcString(KeyHandle, &ValueName, &DestinationString.Length);
  }
  return result;
}


// ===== CmRegUtilWstrValueSetUcString @ 0x280078704 size=0x39 =====
NTSTATUS __fastcall CmRegUtilWstrValueSetUcString(HANDLE KeyHandle, const WCHAR *a2, unsigned __int16 *a3)
{
  NTSTATUS result; // eax
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-18h] BYREF

  result = WdmlibRtlInitUnicodeStringEx(&DestinationString, a2);
  if ( result >= 0 )
    return CmRegUtilUcValueSetUcString(KeyHandle, &DestinationString, a3);
  return result;
}


// ===== CmRegUtilWstrValueSetFullBuffer @ 0x280078744 size=0x57 =====
int __fastcall CmRegUtilWstrValueSetFullBuffer(HANDLE KeyHandle, const WCHAR *a2, ULONG a3, void *a4, ULONG DataSize)
{
  int result; // eax
  struct _UNICODE_STRING ValueName; // [rsp+30h] [rbp-18h] BYREF

  result = WdmlibRtlInitUnicodeStringEx(&ValueName, a2);
  if ( result >= 0 )
    return ZwSetValueKey(KeyHandle, &ValueName, 0, a3, a4, DataSize);
  return result;
}


// ===== CmRegUtilWstrValueGetDword @ 0x2800787a4 size=0x49 =====
int __fastcall CmRegUtilWstrValueGetDword(void *a1, const WCHAR *a2, int a3, _DWORD *a4)
{
  int result; // eax
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-18h] BYREF

  result = WdmlibRtlInitUnicodeStringEx(&DestinationString, a2);
  if ( result >= 0 )
    return CmRegUtilUcValueGetDword(a1, &DestinationString, a3, a4);
  return result;
}


// ===== CmRegUtilCreateWstrKey @ 0x2800787f4 size=0x70 =====
NTSTATUS __fastcall CmRegUtilCreateWstrKey(
        void *a1,
        const WCHAR *a2,
        ACCESS_MASK a3,
        ULONG a4,
        void *a5,
        _DWORD *a6,
        _QWORD *a7)
{
  NTSTATUS result; // eax
  struct _UNICODE_STRING DestinationString; // [rsp+40h] [rbp-18h] BYREF

  result = WdmlibRtlInitUnicodeStringEx(&DestinationString, a2);
  if ( result >= 0 )
    return CmRegUtilCreateUcKey(a1, &DestinationString, a3, a4, a5, a6, a7);
  return result;
}


// ===== CmRegUtilOpenExistingWstrKey @ 0x28007886c size=0x49 =====
int __fastcall CmRegUtilOpenExistingWstrKey(void *a1, const WCHAR *a2, ACCESS_MASK a3, _QWORD *a4)
{
  int result; // eax
  struct _UNICODE_STRING DestinationString; // [rsp+20h] [rbp-18h] BYREF

  result = WdmlibRtlInitUnicodeStringEx(&DestinationString, a2);
  if ( result >= 0 )
    return CmRegUtilOpenExistingUcKey(a1, &DestinationString, a3, a4);
  return result;
}


// ===== CmRegUtilUcValueGetFullBuffer @ 0x2800788bc size=0x132 =====
__int64 __fastcall CmRegUtilUcValueGetFullBuffer(
        HANDLE KeyHandle,
        PUNICODE_STRING ValueName,
        int a3,
        int a4,
        _QWORD *a5)
{
  _QWORD *v5; // rbp
  unsigned int v9; // eax
  ULONG Length; // edi
  _DWORD *PoolWithTag; // rbx
  NTSTATUS v13; // edi
  _DWORD *v14; // rax
  ULONG ResultLength; // [rsp+68h] [rbp+20h] BYREF

  v5 = a5;
  *a5 = 0;
  v9 = (ValueName->Length + 31) & 0x1FFF8;
  Length = v9 + a4;
  if ( v9 + a4 < v9 )
    return 3221225621LL;
  PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, Length, 0x62527050u);
  if ( PoolWithTag == nullptr )
    return 3221225626LL;
  v13 = ZwQueryValueKey(KeyHandle, ValueName, KeyValueFullInformation, PoolWithTag, Length, &ResultLength);
  if ( v13 < 0 )
  {
    ExFreePoolWithTag(PoolWithTag, 0);
    if ( v13 != -2147483643 && v13 != -1073741789 )
      return (unsigned int)v13;
    v14 = ExAllocatePoolWithTag(NonPagedPool, ResultLength, 0x62527050u);
    PoolWithTag = v14;
    if ( v14 == nullptr )
      return 3221225626LL;
    v13 = ZwQueryValueKey(KeyHandle, ValueName, KeyValueFullInformation, v14, ResultLength, &ResultLength);
    if ( v13 < 0 )
    {
LABEL_13:
      ExFreePoolWithTag(PoolWithTag, 0);
      return (unsigned int)v13;
    }
  }
  if ( a3 != 0 && PoolWithTag[1] != a3 )
  {
    v13 = -1073741788;
    goto LABEL_13;
  }
  *v5 = PoolWithTag;
  return 0;
}


// ===== CmRegUtilWstrValueGetFullBuffer @ 0x2800789f4 size=0x53 =====
NTSTATUS __fastcall CmRegUtilWstrValueGetFullBuffer(HANDLE KeyHandle, const WCHAR *a2, int a3, int a4, _QWORD *a5)
{
  NTSTATUS result; // eax
  struct _UNICODE_STRING DestinationString; // [rsp+30h] [rbp-18h] BYREF

  result = WdmlibRtlInitUnicodeStringEx(&DestinationString, a2);
  if ( result >= 0 )
    return CmRegUtilUcValueGetFullBuffer(KeyHandle, &DestinationString, a3, a4, a5);
  return result;
}


// ===== DriverEntry @ 0x280079008 size=0x3f6 =====
NTSTATUS __stdcall DriverEntry(_DRIVER_OBJECT *DriverObject, PUNICODE_STRING RegistryPath)
{
  SIZE_T MaximumLength; // rdx
  PVOID PoolWithTag; // rax
  NTSTATUS result; // eax
  USHORT v7; // ax
  int v8; // edi
  struct _UNICODE_STRING DeviceName; // [rsp+50h] [rbp-38h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+60h] [rbp-28h] BYREF
  struct _UNICODE_STRING SymbolicLinkName; // [rsp+70h] [rbp-18h] BYREF

  MaximumLength = RegistryPath->MaximumLength;
  ::DriverObject = DriverObject;
  PoolWithTag = ExAllocatePoolWithTag(PagedPool, MaximumLength, 0x74706B64u);
  qword_280074A18 = (__int64)PoolWithTag;
  if ( PoolWithTag == nullptr )
    return -1073741670;
  memmove(PoolWithTag, RegistryPath->Buffer, RegistryPath->MaximumLength);
  v7 = RegistryPath->MaximumLength;
  word_280074A10 = RegistryPath->Length;
  word_280074A12 = v7;
  sub_280051078(RegistryPath);
  PsGetVersion(&MajorVersion, &MinorVersion, nullptr, nullptr);
  sub_280079604();
  RtlInitUnicodeString(&DestinationString, aDPAGaSyAGaLsAG);
  RtlInitUnicodeString(&DeviceName, aFilesystemFilt);
  result = WdmlibIoCreateDeviceSecure(
             DriverObject,
             0,
             &DeviceName,
             8u,
             0x100u,
             0,
             &DestinationString,
             nullptr,
             &DeviceObject);
  if ( result == -1073741766 )
  {
    RtlInitUnicodeString(&DeviceName, aFilesystemDpco);
    result = WdmlibIoCreateDeviceSecure(
               DriverObject,
               0,
               &DeviceName,
               8u,
               0x100u,
               0,
               &DestinationString,
               nullptr,
               &DeviceObject);
  }
  if ( result >= 0 )
  {
    RtlInitUnicodeString(&SymbolicLinkName, aDosdevicesDpco);
    v8 = IoCreateSymbolicLink(&SymbolicLinkName, &DeviceName);
    if ( v8 >= 0 )
    {
      return sub_2800B7DE9();
    }
    else
    {
      IoDeleteDevice(DeviceObject);
      return v8;
    }
  }
  return result;
}


// ===== sub_280079404 @ 0x280079404 size=0x1f7 =====
NTSTATUS sub_280079404()
{
  wchar_t *PoolWithTagPriority; // rbp
  ULONG Length; // edi
  NTSTATUS result; // eax
  NTSTATUS v3; // eax
  int v4; // ebx
  bool v5; // zf
  wchar_t *v6; // rdi
  _WORD *v7; // rsi
  __int64 v8; // rcx
  wchar_t *v9; // rax
  bool v10; // cf
  bool v11; // zf
  int v12; // edx
  wchar_t *v13; // rdi
  wchar_t *v14; // rsi
  __int64 v15; // rcx
  struct _UNICODE_STRING DestinationString; // [rsp+30h] [rbp-68h] BYREF
  struct _UNICODE_STRING ValueName; // [rsp+40h] [rbp-58h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+50h] [rbp-48h] BYREF
  ULONG ResultLength; // [rsp+A8h] [rbp+10h] BYREF
  void *KeyHandle; // [rsp+B0h] [rbp+18h] BYREF

  PoolWithTagPriority = nullptr;
  Length = 528;
  RtlInitUnicodeString(&DestinationString, aRegistryMachin_15);
  ObjectAttributes.RootDirectory = nullptr;
  ObjectAttributes.SecurityDescriptor = nullptr;
  ObjectAttributes.SecurityQualityOfService = nullptr;
  ObjectAttributes.ObjectName = &DestinationString;
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 64;
  result = ZwOpenKey(&KeyHandle, 0x20019u, &ObjectAttributes);
  if ( result >= 0 )
  {
    RtlInitUnicodeString(&ValueName, aSystemstartopt);
    do
    {
      if ( PoolWithTagPriority != nullptr )
        ExFreePoolWithTag(PoolWithTagPriority, 0x74706B64u);
      Length *= 2;
      PoolWithTagPriority = (wchar_t *)ExAllocatePoolWithTagPriority(PagedPool, Length, 0x74706B64u, HighPoolPriority);
      if ( PoolWithTagPriority == nullptr )
      {
        v4 = -1073741670;
        goto LABEL_26;
      }
      v3 = ZwQueryValueKey(
             KeyHandle,
             &ValueName,
             KeyValuePartialInformation,
             PoolWithTagPriority,
             Length,
             &ResultLength);
      v4 = v3;
    }
    while ( v3 == -2147483643 || v3 == -1073741789 );
    if ( v3 < 0 )
    {
      ExFreePoolWithTag(PoolWithTagPriority, 0x74706B64u);
LABEL_26:
      ZwClose(KeyHandle);
      return v4;
    }
    ZwClose(KeyHandle);
    wcsupr(PoolWithTagPriority + 6);
    v6 = aDissm;
    v7 = PoolWithTagPriority + 6;
    v8 = 6;
    byte_2800742E9 = 1;
    do
    {
      if ( v8 == 0 )
        break;
      v5 = *v7++ == *v6++;
      --v8;
    }
    while ( v5 );
    if ( v5
      || wcsstr(PoolWithTagPriority + 6, L" DISSM ") != nullptr
      || wcsstr(PoolWithTagPriority + 6, L"DISSM ") == PoolWithTagPriority + 6 )
    {
      byte_2800742E9 = 0;
    }
    else
    {
      v9 = wcsrchr(PoolWithTagPriority + 6, 0x20u);
      if ( v9 != nullptr )
      {
        v10 = false;
        v11 = true;
        v12 = 0;
        v13 = aDissm_2;
        v14 = v9;
        v15 = 7;
        do
        {
          if ( v15 == 0 )
            break;
          v10 = *v14 < *v13;
          v11 = *v14++ == *v13++;
          --v15;
        }
        while ( v11 );
        if ( !v11 )
          v12 = -v10 - (v10 - 1);
        byte_2800742E9 &= -(v12 != 0);
      }
    }
    ExFreePoolWithTag(PoolWithTagPriority, 0x74706B64u);
    return v4;
  }
  return result;
}


// ===== sub_280079604 @ 0x280079604 size=0x3fc =====
__int64 sub_280079604()
{
  return sub_2800B7DE9();
}


// ===== sub_280079A08 @ 0x280079a08 size=0x138 =====
__int64 sub_280079A08()
{
  LARGE_INTEGER Seed; // [rsp+50h] [rbp+8h] BYREF

  Seed = KeQueryPerformanceCounter(nullptr);
  RtlRandom((PULONG)&Seed);
  return sub_2800B7DE9();
}


// ===== sub_280079B48 @ 0x280079b48 size=0x124 =====
char (__fastcall *__fastcall sub_280079B48(_QWORD *a1))(__int64 a1, __int64 a2, struct _DEVICE_OBJECT *a3)
{
  memset(a1, 0, 0xE0u);
  *(_DWORD *)a1 = 224;
  a1[1] = sub_2800649EC;
  a1[2] = sub_280064A7C;
  a1[3] = sub_280064B0C;
  a1[4] = sub_280064B9C;
  a1[5] = sub_280064C08;
  a1[6] = sub_280064C74;
  a1[7] = sub_280064D14;
  a1[8] = sub_280064D98;
  a1[9] = sub_280064DF8;
  a1[10] = sub_280064E64;
  a1[13] = sub_280064F04;
  a1[14] = sub_280064F84;
  a1[16] = sub_280064FF0;
  a1[17] = sub_28006507C;
  a1[18] = sub_2800650DC;
  a1[19] = sub_280065168;
  a1[20] = sub_2800651CC;
  a1[21] = sub_28006528C;
  a1[22] = sub_28006534C;
  a1[23] = sub_2800653AC;
  a1[24] = sub_280065410;
  return sub_280065410;
}


// ===== sub_280079C74 @ 0x280079c74 size=0xf0 =====
NTSTATUS sub_280079C74()
{
  stru_2800751C0.Count = 1;
  stru_2800751C0.Owner = nullptr;
  stru_2800751C0.Contention = 0;
  KeInitializeEvent(&stru_2800751C0.Event, SynchronizationEvent, 0);
  dword_280075124 = 1;
  KeInitializeEvent(&Event, SynchronizationEvent, 0);
  ExInitializeResourceLite(&Resource);
  ExInitializePagedLookasideList((PPAGED_LOOKASIDE_LIST)&Lookaside, nullptr, nullptr, 0, 0x128u, 0x636E5450u, 0);
  ExInitializePagedLookasideList((PPAGED_LOOKASIDE_LIST)&stru_280074980, nullptr, nullptr, 0, 0x40u, 0x63735450u, 0);
  ExInitializeNPagedLookasideList((PNPAGED_LOOKASIDE_LIST)&stru_280074880, nullptr, nullptr, 0, 0x58u, 0x69775450u, 0);
  return PsSetLoadImageNotifyRoutine((PLOAD_IMAGE_NOTIFY_ROUTINE)sub_28005F028);
}


// ===== __security_init_cookie @ 0x280079d6c size=0x55 =====
void __cdecl _security_init_cookie()
{
  unsigned __int64 v0; // rax

  v0 = BugCheckParameter2;
  if ( BugCheckParameter2 == 0 || BugCheckParameter2 == 0x2B992DDFA232LL )
  {
    v0 = ((unsigned __int64)&BugCheckParameter2 ^ MEMORY[0xFFFFF78000000320]) & 0xFFFFFFFFFFFFLL;
    if ( v0 == 0 )
      v0 = 0x2B992DDFA232LL;
    BugCheckParameter2 = v0;
  }
  BugCheckParameter3 = ~v0;
}


// ===== start @ 0x280079dc8 size=0x1e =====
NTSTATUS __stdcall start(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
  PUNICODE_STRING v2; // r8
  _DRIVER_OBJECT *v3; // r9

  _security_init_cookie();
  return DriverEntry(v3, v2);
}


// ===== sub_2800B7DE9 @ 0x2800b7de9 size=0xaf =====
void sub_2800B7DE9()
{
  _QWORD *v0; // rax
  __int64 i; // rbx
  __int64 v3; // [rsp+8h] [rbp+8h]

  __getcallerseflags();
  while ( _InterlockedCompareExchange((volatile signed __int32 *)((char *)&qword_28007D250[18] + 7), 1, 0) != 0 )
    _mm_pause();
  *(__int64 *)((char *)&qword_28007D250[19] + 7) = 0x280050000LL;
  *(__int64 *)((char *)&qword_28007D250[21] + 3) = v3 + 0x280050000LL;
  v0 = (__int64 *)((char *)&qword_2800B7350[203] + 1);
  if ( *(__int64 **)((char *)qword_28007D250 + 4) != (__int64 *)((char *)&qword_2800B7350[203] + 1) )
  {
    for ( i = 136; i != 0; i = (unsigned int)(i - 1) )
      *v0++ += 0x280050000LL;
    *(__int64 *)((char *)qword_28007D250 + 4) = (__int64)&qword_2800B7350[203] + 1;
  }
  __asm { jmp     qword ptr [rax] }
}


// ===== sub_2800C5020 @ 0x2800c5020 size=0x3 =====
void sub_2800C5020()
{
  ;
}



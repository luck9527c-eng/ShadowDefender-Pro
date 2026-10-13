// ===== Dp_H000_2d353 @ 0x28007d353 size=0x202 =====
__int64 __fastcall Dp_H000_2d353(__int64 a1, __int64 a2)
{
  __int64 v2; // rbp
  __int64 v3; // r8
  __int64 (__fastcall *v4)(_QWORD, __int64, __int64, __int64); // rbx
  __int64 v5; // rsi

  v3 = 8LL * **(unsigned __int16 **)(v2 + 251);
  v4 = *(__int64 (__fastcall **)(_QWORD, __int64, __int64, __int64))(v3 + *(_QWORD *)(v2 + 84));
  v5 = *(unsigned int *)(*(_QWORD *)(v2 + 251) + 4LL);
  if ( (int)v5 >= 0 )
    *(_QWORD *)(v2 + 251) += v5;
  else
    *(_QWORD *)(v2 + 251) -= v5 & 0x7FFFFFFF;
  return v4((unsigned int)v5 & 0x80000000, a2, v3, 0x80000000LL);
}


// ===== Dp_H001_2d555 @ 0x28007d555 size=0xa0 =====
__int64 __fastcall Dp_H001_2d555()
{
  __int64 v0; // rbp
  __int64 v1; // r13
  __int64 v2; // rbx
  int v3; // r12d
  __int64 (*v4)(void); // r13

  *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251)) = *(_QWORD *)(v0 + 166);
  v2 = *(_QWORD *)(v0 + 84);
  v3 = *(_DWORD *)(v0 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL);
  *(_QWORD *)(v0 + 158) += v1 ^ (v0 + 105);
  *(_DWORD *)(v0 + 105) |= v3;
  v4 = *(__int64 (**)(void))(8LL * (unsigned __int16)v3 + v2);
  *(_QWORD *)(v0 + 251) += 4LL;
  return v4();
}


// ===== Dp_H002_2d5f5 @ 0x28007d5f5 size=0x1ae =====
__int64 __fastcall Dp_H002_2d5f5()
{
  __int64 v0; // rbp
  unsigned __int64 v1; // kr00_8
  _QWORD *v2; // rdi
  _QWORD *v3; // rdx
  int v4; // r12d
  __int64 v5; // rdx
  __int64 (*v6)(void); // rdi

  v1 = __readeflags();
  v2 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 8LL));
  v3 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) & 0x400LL) != 0 )
  {
    *v2 -= 8LL;
    *v3 -= 8LL;
  }
  else
  {
    *v2 += 8LL;
    *v3 += 8LL;
  }
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 10LL) != 0 )
    *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) = v1;
  v4 = **(unsigned __int16 **)(v0 + 251);
  v5 = *(_QWORD *)(v0 + 84);
  *(_QWORD *)(v0 + 158) -= v0 + 105;
  v4 ^= 0x986D6C1u;
  *(_DWORD *)(v0 + 105) ^= v4;
  v6 = *(__int64 (**)(void))(8LL * (unsigned __int16)v4 + v5);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v6();
}


// ===== Dp_H003_2d7a3 @ 0x28007d7a3 size=0x1a0 =====
__int64 __fastcall Dp_H003_2d7a3()
{
  __int64 v0; // rbp
  _QWORD *v1; // rcx
  unsigned __int64 v2; // kr00_8
  _QWORD *v3; // rdi
  __int64 v4; // rbx
  int v5; // r14d
  __int64 (*v6)(void); // r10

  v1 = *(_QWORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 8LL));
  *v1 -= *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
  v2 = __readeflags();
  v3 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 8LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL)) & 0x400LL) != 0 )
    *v3 -= 8LL;
  else
    *v3 += 8LL;
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 10LL) != 0 )
    *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251)) = v2;
  v4 = *(_QWORD *)(v0 + 84);
  v5 = *(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL);
  *(_QWORD *)(v0 + 158) -= v2;
  v5 += 1036032465;
  *(_DWORD *)(v0 + 105) &= v5;
  v6 = *(__int64 (**)(void))(8LL * (unsigned __int16)v5 + v4);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v6();
}


// ===== Dp_H004_2d943 @ 0x28007d943 size=0x1f2 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H004_2d943()
{
  __int64 v0; // rbp
  char v1; // r10
  __int64 v2; // r10
  _QWORD *v3; // r12
  _QWORD *v4; // r12
  __int64 result; // rax
  _BYTE v6[128]; // [rsp-80h] [rbp-80h]

  v1 = **(_BYTE **)(v0 + 251);
  if ( (v1 == 1 || v1 == 2)
    && *(_QWORD *)(*(_QWORD *)(v0 + 239)
                 + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 7LL)
                 + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 1LL)) != *(_QWORD *)(v0 + 239)
                                                                       + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 3LL) )
  {
    v2 = *(_QWORD *)(v0 + 239);
    v3 = (_QWORD *)(v2
                  + *(_DWORD *)(*(_QWORD *)(v0 + 251) + 7LL)
                  + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 1LL));
    *v3 -= *(_QWORD *)(v0 + 297);
    *v3 += *(_QWORD *)(v0 + 239);
    if ( **(_BYTE **)(v0 + 251) == 2 )
    {
      v4 = (_QWORD *)(v2
                    + *(_DWORD *)(*(_QWORD *)(v0 + 251) + 7LL)
                    + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 2LL));
      *v4 -= *(_QWORD *)(v0 + 297);
      *v4 += *(_QWORD *)(v0 + 239);
    }
  }
  *(_QWORD *)&v6[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 11LL)] = *(_QWORD *)(v0 + 239)
                                                                      + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 7LL);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v6[112];
  __writeeflags(*(unsigned __int64 *)&v6[120]);
  return result;
}


// ===== Dp_H005_2db35 @ 0x28007db35 size=0x7b =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H005_2db35()
{
  __int64 v0; // rbp
  __int64 result; // rax
  _BYTE v2[128]; // [rsp-80h] [rbp-80h]

  *(_QWORD *)&v2[**(unsigned __int16 **)(v0 + 251)] = *(_QWORD *)(v0 + 239)
                                                    + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 2LL);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v2[112];
  __writeeflags(*(unsigned __int64 *)&v2[120]);
  return result;
}


// ===== Dp_H006_2dbb0 @ 0x28007dbb0 size=0x1f6 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H006_2dbb0(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 v4; // rax
  __int64 v5; // rbp
  __int64 v6; // rsi
  __int64 v7; // r10
  __int64 v8; // r12
  char v9; // r14
  __int64 v10; // rdx
  _QWORD *v11; // r11
  _QWORD *v12; // r10
  __int64 v13; // r14
  __int64 v14; // r8
  __int64 v15; // rbx
  int v16; // esi
  __int64 (__fastcall *v17)(__int64, __int64, __int64, __int64); // r12
  __int64 v19; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v5 + 247) |= 0x721383CAu;
  v10 = (v7 - 6) | 0xAC;
  v11 = (_QWORD *)(v5 + *(unsigned __int16 *)(*(_QWORD *)(v5 + 251) + 2LL));
  v12 = (_QWORD *)(v5 + *(unsigned __int16 *)(*(_QWORD *)(v5 + 251) + 4LL));
  v13 = (a4 + 1 - (_BYTE)v8 + v9 + 115) & 0x40;
  *v12 += 8LL;
  *v11 = v19;
  v14 = (v4 | v6) + 2147483596;
  v15 = *(_QWORD *)(v5 + 84);
  v16 = *(_DWORD *)(v5 + 105) + **(unsigned __int16 **)(v5 + 251);
  *(_QWORD *)(v5 + 158) ^= v13 ^ v8;
  *(_DWORD *)(v5 + 105) ^= v16;
  v17 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(8LL * (unsigned __int16)v16 + v15);
  *(_QWORD *)(v5 + 251) += 6LL;
  return v17(
           v5 + 251,
           v10 | 0x8F,
           v13 ^ (((v14 - 40) ^ 0x4F9) + 2048),
           (v13 ^ (((v14 - 40) ^ 0x4F9) + 2048)) + (v13 | 0x400));
}


// ===== Dp_H007_2dda6 @ 0x28007dda6 size=0x4b5 =====
__int64 __fastcall Dp_H007_2dda6()
{
  __int64 v0; // rbp
  __int64 v1; // r13
  _DWORD *v2; // rsi
  unsigned __int64 v3; // kr00_8
  __int64 v4; // rcx
  _QWORD *v5; // rdx
  unsigned __int64 *v6; // r10
  int v7; // ebx
  __int64 v8; // rdx
  __int64 v9; // r8
  __int64 (__fastcall **v10)(__int64, _QWORD, __int64, __int64); // rdx
  __int64 (__fastcall *v11)(__int64, _QWORD, __int64, __int64); // rbx

  *(_DWORD *)(v0 + 285) -= 1495087724;
  *(_DWORD *)(v0 + 105) -= 58517615;
  *(_DWORD *)(v0 + 307) |= 0x37CE86Fu;
  v1 = *(_QWORD *)(v0 + 251);
  *(_DWORD *)(v0 + 285) &= 0x352505A1u;
  v2 = *(_DWORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL));
  *v2 -= *(_QWORD *)(v0 + *(unsigned __int16 *)(v1 + 2));
  v3 = __readeflags();
  v4 = *(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) & 0x400LL;
  v5 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL));
  if ( v4 != 0 )
    *v5 -= 4LL;
  else
    *v5 += 4LL;
  *(_DWORD *)(v0 + 247) |= 0xFA1BC94u;
  v6 = (unsigned __int64 *)*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 8LL);
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 8LL) != 0 )
  {
    v6 = (unsigned __int64 *)(v0 + **(unsigned __int16 **)(v0 + 251));
    *v6 = v3;
  }
  v7 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL);
  v8 = *(_QWORD *)(v0 + 84);
  v9 = v8 + (((_BYTE)v6 + (((((unsigned __int8)(v0 + 29) | 1) - 45) & 0x89 | 4) ^ 0xD3 | 0xB7)) & 0x28);
  *(_DWORD *)(v0 + 105) &= v7;
  v10 = (__int64 (__fastcall **)(__int64, _QWORD, __int64, __int64))(8LL * (unsigned __int16)v7 + v8);
  v11 = *v10;
  *(_QWORD *)(v0 + 251) += 11LL;
  return v11(v4 - (_QWORD)v6, v10, v9, ((v4 - (_QWORD)v6) & 0x480 | 0x75) + 249);
}


// ===== Dp_H008_2e25b @ 0x28007e25b size=0x162 =====
__int64 __fastcall Dp_H008_2e25b()
{
  __int64 v0; // rbp
  _QWORD *v1; // r10
  _QWORD *v2; // r15
  __int64 v3; // r8
  int v4; // esi
  __int64 (__fastcall *v5)(__int64); // r13

  **(_QWORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) = **(_QWORD **)(v0
                                                                                       + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  v1 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  v2 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251)) & 0x400LL) != 0 )
  {
    *v1 -= 8LL;
    *v2 -= 8LL;
  }
  else
  {
    *v1 += 8LL;
    *v2 += 8LL;
  }
  v3 = *(_QWORD *)(v0 + 84);
  v4 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL) - *(_DWORD *)(v0 + 105) + 1099583391;
  *(_DWORD *)(v0 + 105) -= v4;
  v5 = *(__int64 (__fastcall **)(__int64))(8LL * (unsigned __int16)v4 + v3);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v5(v0 + 158);
}


// ===== Dp_H009_2e3bd @ 0x28007e3bd size=0x141 =====
__int64 __fastcall Dp_H009_2e3bd()
{
  __int64 v0; // rbp
  __int64 v1; // r14
  int v2; // esi
  __int64 v3; // rsi
  __int64 v4; // rsi
  _QWORD *v5; // rdx
  __int64 v6; // r15
  int v7; // eax
  __int64 (*v8)(void); // r10

  v2 = *(_DWORD *)(v0 + 307) + (*(_DWORD *)(v0 + 105) ^ **(_DWORD **)(v0 + 251));
  *(_DWORD *)(v0 + 105) &= v2;
  *(_DWORD *)(v0 + 335) -= 1693283671;
  v3 = (unsigned int)(v2 - *(_DWORD *)(v0 + 285));
  *(_DWORD *)(v0 + 285) ^= 0x4351A7C1u;
  v4 = *(_QWORD *)(v0 + 158) ^ (v3 + 1199625454);
  *(_QWORD *)(v0 + 259) = v4;
  v5 = (_QWORD *)(v0 + (unsigned __int16)((*(_WORD *)(v0 + 158) ^ *(_WORD *)(v0 + 259)) + 11026));
  *v5 += *(_QWORD *)(v0 + 239);
  v6 = *(_QWORD *)(v0 + 84);
  v7 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) += v4 ^ v1;
  v7 += 1677453145;
  *(_DWORD *)(v0 + 105) &= v7;
  v8 = *(__int64 (**)(void))(8LL * (unsigned __int16)v7 + v6);
  *(_QWORD *)(v0 + 251) += 6LL;
  return v8();
}


// ===== Dp_H010_2e4fe @ 0x28007e4fe size=0x69 =====
__int64 __fastcall Dp_H010_2e4fe()
{
  __int64 v0; // rbp
  __int64 (*v1)(void); // rsi
  _UNKNOWN *retaddr; // [rsp+0h] [rbp+0h] BYREF

  *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) = &retaddr;
  v1 = *(__int64 (**)(void))(8LL * **(unsigned __int16 **)(v0 + 251) + *(_QWORD *)(v0 + 84));
  *(_QWORD *)(v0 + 251) += 4LL;
  return v1();
}


// ===== Dp_H011_2e567 @ 0x28007e567 size=0x301 =====
__int64 __fastcall Dp_H011_2e567()
{
  __int64 v0; // rbp
  unsigned __int64 v1; // kr00_8
  _QWORD *v2; // rdi
  _QWORD *v3; // r8
  __int64 v4; // rdi
  int v5; // r10d
  __int64 (*v6)(void); // r14

  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) += 1921265502;
  v1 = __readeflags();
  v2 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 7LL));
  v3 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 5LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL)) & 0x400LL) != 0 )
  {
    *v2 -= 4LL;
    *v3 -= 4LL;
  }
  else
  {
    *v2 += 4LL;
    *v3 += 4LL;
  }
  *(_DWORD *)(v0 + 105) &= 0x63182B3Bu;
  if ( **(_BYTE **)(v0 + 251) != 0 )
    *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 3LL)) = v1;
  *(_DWORD *)(v0 + 105) &= 0x51F4FA99u;
  v4 = *(_QWORD *)(v0 + 84);
  v5 = *(_DWORD *)(v0 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 1LL);
  *(_QWORD *)(v0 + 158) += v0 + 105;
  *(_DWORD *)(v0 + 105) &= v5;
  v6 = *(__int64 (**)(void))(8LL * (unsigned __int16)v5 + v4);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v6();
}


// ===== Dp_H012_2e868 @ 0x28007e868 size=0xcb =====
__int64 __fastcall Dp_H012_2e868()
{
  __int64 v0; // rbp
  __int64 (*v1)(void); // r10

  *(_DWORD *)(v0 + 105) = 0;
  *(_DWORD *)(v0 + 335) = 0;
  *(_DWORD *)(v0 + 285) = 0;
  *(_DWORD *)(v0 + 307) = 0;
  *(_DWORD *)(v0 + 247) = 0;
  *(_WORD *)(v0 + 283) = 0;
  *(_BYTE *)(v0 + 157) = 0;
  *(_DWORD *)(v0 + 174) = 0;
  v1 = *(__int64 (**)(void))(8LL * **(unsigned __int16 **)(v0 + 251) + *(_QWORD *)(v0 + 84));
  *(_QWORD *)(v0 + 251) += 2LL;
  return v1();
}


// ===== Dp_H013_2e933 @ 0x28007e933 size=0x4db =====
__int64 __fastcall Dp_H013_2e933()
{
  __int64 v0; // rbp
  _WORD *v1; // r10
  unsigned __int64 v2; // kr00_8
  _QWORD *v3; // r8
  __int64 v4; // r13
  __int64 v5; // rbx
  __int64 v6; // r13
  __int64 v7; // rcx
  __int64 v8; // rdx
  unsigned __int64 *v9; // rcx
  unsigned __int16 *v10; // r10
  __int64 v11; // r8
  int v12; // edi
  __int64 v13; // rbx
  __int64 (__fastcall **v14)(unsigned __int64, __int64, _QWORD, __int64); // r8
  __int64 (__fastcall *v15)(unsigned __int64, __int64, _QWORD, __int64); // r10

  v1 = *(_WORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  *v1 -= *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  v2 = __readeflags();
  v3 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  v4 = 844;
  v5 = v0 + **(unsigned __int16 **)(v0 + 251);
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL)) & 0x400LL) != 0 )
  {
    *v3 -= 2LL;
  }
  else
  {
    *v3 += 2LL;
    v4 = (v0 + 28) | 0x34C;
  }
  v6 = v4 | 0xD7;
  v7 = *(_QWORD *)(v0 + 251);
  v8 = 0;
  *(_DWORD *)(v0 + 105) += 557192975;
  v9 = (unsigned __int64 *)*(unsigned __int8 *)(v7 + 4);
  if ( v9 != nullptr )
  {
    v10 = (unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 7LL);
    v9 = (unsigned __int64 *)(v0 + *v10);
    v8 = 0x1FFFFFFFFFFFFFEBLL;
    *v9 = v2;
    v6 = (unsigned __int8)v10 & 0xB7;
  }
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) |= 0x3C10B467u;
  v11 = *(_QWORD *)(v0 + 84);
  v12 = *(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 5LL);
  v13 = v6 + v5;
  *(_QWORD *)(v0 + 158) -= v13;
  v12 += 499535101;
  *(_DWORD *)(v0 + 105) += v12;
  v14 = (__int64 (__fastcall **)(unsigned __int64, __int64, _QWORD, __int64))(8LL * (unsigned __int16)v12 + v11);
  v15 = *v14;
  *(_QWORD *)(v0 + 251) += 11LL;
  return v15(((v13 | ((v6 | ((unsigned __int64)&v9[v8 - 40] - 2)) - 214)) - 4) | 0xE2, -4, v14, 165);
}


// ===== Dp_H014_2ee0e @ 0x28007ee0e size=0x3f4f =====
void __fastcall Dp_H014_2ee0e()
{
  __int64 v0; // rbp
  int v1; // edx
  int v2; // r15d
  int v3; // r15d
  int v4; // esi
  int v5; // esi
  __int64 v6; // r13
  __int64 v7; // rax
  __int64 v8; // r15
  unsigned __int64 v9; // rcx
  int v10; // r10d
  unsigned __int8 v11; // r14
  char v12; // bl
  unsigned __int64 v13; // r9
  char v14; // r11
  unsigned __int64 v15; // r15
  __int64 v16; // r11
  char v17; // di
  char v18; // bl
  __int64 v19; // rdx
  __int64 v20; // rdx
  __int64 v21; // r10
  char v22; // si
  char v23; // cl
  char v26; // r11
  char v27; // al
  __int64 v28; // r13
  char v31; // dl
  __int64 v32; // rsi
  __int64 v33; // r9
  __int64 v34; // rdi
  char v35; // si
  __int64 v36; // r12
  __int64 v37; // rbx
  char v38; // r15
  __int64 v39; // rbx
  char v40; // r11
  __int64 v41; // rsi
  __int64 v42; // r12
  char v43; // r15
  __int64 v44; // r9
  unsigned __int64 v45; // r12
  char v46; // r15
  char v47; // di
  __int64 v48; // rdx
  unsigned __int64 v49; // kr140_8
  char v50; // dl
  _BYTE *v51; // r9
  __int64 v52; // r8
  __int64 v53; // rbx
  int v54; // r9d
  __int64 v55; // r10
  unsigned __int64 v56; // [rsp-148h] [rbp-148h]

  v1 = *(_DWORD *)(v0 + 105) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 12LL);
  *(_DWORD *)(v0 + 105) &= v1;
  *(_DWORD *)(v0 + 285) += 1699084377;
  *(_BYTE *)(v0 + 57) = ((unsigned __int8)(v1 & 0xF0) >> 4) ^ 0xB9;
  *(_BYTE *)(v0 + 218) = v1 & 0xF ^ 0xB5;
  v2 = *(_DWORD *)(v0 + 335) + *(_DWORD *)(v0 + 105) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 11LL);
  *(_DWORD *)(v0 + 105) -= v2;
  *(_DWORD *)(v0 + 335) &= 0x67B822C8u;
  v3 = *(_DWORD *)(v0 + 285) + v2;
  *(_DWORD *)(v0 + 285) += 1778778365;
  *(_BYTE *)(v0 + 83) = ((unsigned __int8)(v3 & 0xF0) >> 4) ^ 0xE6;
  *(_BYTE *)(v0 + 104) = v3 & 0xF ^ 0xF3;
  v4 = *(_DWORD *)(v0 + 174) ^ (*(_DWORD *)(v0 + 335) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 13LL));
  *(_DWORD *)(v0 + 105) -= v4;
  *(_DWORD *)(v0 + 335) += 1373623825;
  v5 = *(_DWORD *)(v0 + 285) + v4;
  *(_DWORD *)(v0 + 285) ^= 0x3FD4C3BDu;
  *(_BYTE *)(v0 + 157) ^= v5;
  v6 = *(unsigned int *)(*(_QWORD *)(v0 + 251) + 6LL);
  *(_DWORD *)(v0 + 105) &= v6;
  *(_DWORD *)(v0 + 335) += 450054396;
  *(_DWORD *)(v0 + 285) &= 0x190FDE32u;
  *(_QWORD *)(v0 + 210) = (*(_QWORD *)(v0 + 158) ^ v6) + 1520976769;
  v7 = (unsigned int)(**(_DWORD **)(v0 + 251) - *(_DWORD *)(v0 + 307));
  *(_DWORD *)(v0 + 105) |= v7;
  *(_DWORD *)(v0 + 335) &= 0x7D7F05CFu;
  *(_DWORD *)(v0 + 285) -= 607602228;
  *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) ^ v7 ^ 0x10827371;
  *(_BYTE *)(v0 + 74) = 0;
  v8 = *(_QWORD *)(v0 + 251);
  if ( (*(_BYTE *)(v0 + 83) ^ 0xE6) == 1 )
  {
    v9 = v0 + ((unsigned __int16)(*(_WORD *)(v0 + 158) ^ *(_WORD *)(v0 + 259)) ^ 0x7371u);
    *(_QWORD *)(v0 + 149) = v9 ^ 0x494FC150;
    *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)v9 ^ 0x10827371LL;
    if ( ((unsigned __int8)*(_QWORD *)(v0 + 104) ^ 0xF3) == 3 )
      *(_BYTE *)(v0 + 74) = (v0 + 29) | 3;
  }
  v10 = *(_DWORD *)(v8 + 16);
  if ( v10 != 0 )
    *(_QWORD *)(v0 + 210) = (*(_QWORD *)(v0 + 158)
                           ^ (*(_QWORD *)(v0 + 158) ^ (*(_QWORD *)(v0 + 210) - 1520976769LL)
                            | ((unsigned __int64)(v10 - (unsigned int)*(_QWORD *)(v0 + 105)) << 32)))
                          + 1520976769;
  v11 = *(_BYTE *)(v0 + 83);
  if ( (*(_BYTE *)(v0 + 57) ^ 0xB9) == 1 )
    *(_QWORD *)(v0 + 210) = (*(_QWORD *)(v0 + 158)
                           ^ *(_QWORD *)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 158) ^ (*(_WORD *)(v0 + 210) - 17281))))
                          + 1520976769LL;
  if ( (v11 ^ 0xE6) == 2 )
  {
    v12 = *(_BYTE *)(v0 + 104) ^ 0xF3;
    v13 = *(_QWORD *)(v0 + ((unsigned __int16)(*(_WORD *)(v0 + 158) ^ *(_WORD *)(v0 + 259)) ^ 0x7371u));
    *(_QWORD *)(v0 + 149) = v13 ^ 0x494FC150;
    if ( v12 == 1 )
      LOBYTE(v13) = *(_BYTE *)v13;
    if ( v12 == 2 )
      LOWORD(v13) = *(_WORD *)v13;
    if ( v12 == 3 )
      v13 = *(unsigned int *)v13;
    if ( v12 == 4 )
      v13 = *(_QWORD *)v13;
    *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) ^ v13 ^ 0x10827371;
  }
  if ( (*(_BYTE *)(v0 + 57) ^ 0xB9) == 2 )
  {
    v14 = *(_BYTE *)(v0 + 218) ^ 0xB5;
    v15 = *(_QWORD *)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 158) ^ (*(_WORD *)(v0 + 210) - 17281)));
    if ( v14 == 1 )
      LOBYTE(v15) = *(_BYTE *)v15;
    if ( v14 == 2 )
      LOWORD(v15) = *(_WORD *)v15;
    if ( v14 == 3 )
      v15 = *(unsigned int *)v15;
    if ( v14 == 4 )
      v15 = *(_QWORD *)v15;
    *(_QWORD *)(v0 + 210) = (*(_QWORD *)(v0 + 158) ^ v15) + 1520976769;
  }
  if ( *(_BYTE *)(v0 + 157) == 0xDC )
  {
    v16 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259) ^ 0x10827371LL;
    v17 = *(_BYTE *)(v0 + 104) ^ 0xF3;
    if ( v17 == 1 )
    {
      LOBYTE(v16) = __ROR1__(v16, *(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127));
      __readeflags();
    }
    if ( v17 == 2 )
    {
      LOWORD(v16) = __ROR2__(v16, *(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127));
      __readeflags();
    }
    if ( v17 == 3 )
    {
      v16 = (unsigned int)__ROR4__(v16, *(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127));
      __readeflags();
    }
    if ( v17 == 4 )
    {
      v16 = __ROR8__(v16, *(_BYTE *)(v0 + 158) ^ (unsigned __int8)(*(_BYTE *)(v0 + 210) + 127));
      __readeflags();
    }
    *(_QWORD *)(v0 + 327) = v16 ^ 0x5AA84381;
  }
  if ( *(_BYTE *)(v0 + 157) == 0xAD )
  {
    v18 = *(_BYTE *)(v0 + 104) ^ 0xF3;
    if ( v18 == 1 )
      __readeflags();
    if ( v18 == 2 )
      __readeflags();
    if ( v18 == 3 )
      __readeflags();
    if ( v18 == 4 )
      __readeflags();
    *(_QWORD *)(v0 + 327) = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259) ^ 0x4A2A30F0LL;
  }
  if ( *(_BYTE *)(v0 + 157) == 0xF3 )
  {
    v19 = *(_QWORD *)(v0 + 158)
        ^ (*(_QWORD *)(v0 + 210) - 1520976769LL)
        ^ *(_QWORD *)(v0 + 158)
        ^ *(_QWORD *)(v0 + 259)
        ^ 0x10827371LL;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v19 ^ 0x5AA84381;
  }
  if ( *(_BYTE *)(v0 + 157) == 2 )
  {
    v20 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259) ^ 0x10827371LL;
    v21 = *(_QWORD *)(v0 + 158) ^ (*(_QWORD *)(v0 + 210) - 1520976769LL);
    v22 = *(_BYTE *)(v0 + 218) ^ 0xB5;
    if ( v22 == 1 )
      v20 = (unsigned __int8)(*(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127));
    if ( v22 == 2 )
      v20 = (unsigned __int16)v21;
    if ( v22 == 3 )
      v20 = (unsigned int)v21;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v20 ^ 0x5AA84381;
  }
  if ( *(_BYTE *)(v0 + 157) == 0x88 )
  {
    v23 = *(_BYTE *)(v0 + 104) ^ 0xF3;
    if ( v23 == 1 )
      __readeflags();
    if ( v23 == 2 )
      __readeflags();
    if ( v23 == 3 )
      __readeflags();
    if ( v23 == 4 )
      __readeflags();
    *(_QWORD *)(v0 + 327) = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259) ^ 0x4A2A30F0LL;
  }
  if ( *(_BYTE *)(v0 + 157) == 4 )
  {
    _R8 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259) ^ 0x10827371LL;
    _RCX = *(_QWORD *)(v0 + 158) ^ (*(_QWORD *)(v0 + 210) - 1520976769LL);
    v26 = *(_BYTE *)(v0 + 104) ^ 0xF3;
    if ( v26 == 1 )
    {
      __asm { rcl     r8b, cl }
      __readeflags();
    }
    if ( v26 == 2 )
    {
      __asm { rcl     r8w, cl }
      __readeflags();
    }
    if ( v26 == 3 )
    {
      __asm { rcl     r8d, cl }
      __readeflags();
    }
    if ( v26 == 4 )
    {
      __asm { rcl     r8, cl }
      __readeflags();
    }
    *(_QWORD *)(v0 + 327) = _R8 ^ 0x5AA84381;
  }
  v27 = *(_BYTE *)(v0 + 157);
  *(_DWORD *)(v0 + 247) |= 0x71D60ACCu;
  if ( v27 == -17 )
  {
    v28 = *(_QWORD *)(v0 + 158) ^ (*(_QWORD *)(v0 + 210) - 1520976769LL)
        | *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259) ^ 0x10827371LL;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v28 ^ 0x5AA84381;
  }
  if ( *(_BYTE *)(v0 + 157) == 0xC0 )
  {
    _RAX = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259) ^ 0x10827371LL;
    _RCX = *(_QWORD *)(v0 + 158) ^ (*(_QWORD *)(v0 + 210) - 1520976769LL);
    v31 = *(_BYTE *)(v0 + 104) ^ 0xF3;
    if ( v31 == 1 )
    {
      __asm { rcr     al, cl }
      __readeflags();
    }
    if ( v31 == 2 )
    {
      __asm { rcr     ax, cl }
      __readeflags();
    }
    if ( v31 == 3 )
    {
      __asm { rcr     eax, cl }
      __readeflags();
    }
    if ( v31 == 4 )
    {
      __asm { rcr     rax, cl }
      __readeflags();
    }
    *(_QWORD *)(v0 + 327) = _RAX ^ 0x5AA84381;
  }
  if ( *(_BYTE *)(v0 + 157) == 0x85 )
  {
    v32 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259);
    v33 = *(_QWORD *)(v0 + 158) ^ (*(_QWORD *)(v0 + 210) - 1520976769LL);
    __readeflags();
    *(_QWORD *)(v0 + 327) = (v33 + (v32 ^ 0x10827371)) ^ 0x5AA84381;
  }
  if ( *(_BYTE *)(v0 + 157) == 98 )
  {
    v34 = (*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259) ^ 0x10827371LL)
        - (*(_QWORD *)(v0 + 158) ^ (*(_QWORD *)(v0 + 210) - 1520976769LL));
    __readeflags();
    *(_QWORD *)(v0 + 327) = v34 ^ 0x5AA84381;
  }
  v35 = *(_BYTE *)(v0 + 157) - 113;
  *(_DWORD *)(v0 + 105) += 1207507475;
  if ( v35 == 0 )
  {
    v36 = (*(_QWORD *)(v0 + 158)
         ^ (*(_QWORD *)(v0 + 210) - 1520976769LL))
        & (*(_QWORD *)(v0 + 158)
         ^ *(_QWORD *)(v0 + 259)
         ^ 0x10827371LL);
    __readeflags();
    *(_QWORD *)(v0 + 327) = v36 ^ 0x5AA84381;
  }
  if ( *(_BYTE *)(v0 + 157) == 18 )
  {
    v37 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259) ^ 0x10827371LL;
    v38 = *(_BYTE *)(v0 + 104) ^ 0xF3;
    if ( v38 == 1 )
    {
      LOBYTE(v37) = (_BYTE)v37 << (*(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127));
      __readeflags();
    }
    if ( v38 == 2 )
    {
      LOWORD(v37) = (_WORD)v37 << (*(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127));
      __readeflags();
    }
    if ( v38 == 3 )
    {
      v37 = (unsigned int)((_DWORD)v37 << (*(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127)));
      __readeflags();
    }
    if ( v38 == 4 )
    {
      v37 <<= *(_BYTE *)(v0 + 158) ^ (unsigned __int8)(*(_BYTE *)(v0 + 210) + 127);
      __readeflags();
    }
    *(_QWORD *)(v0 + 327) = v37 ^ 0x5AA84381;
  }
  if ( *(_BYTE *)(v0 + 157) == 28 )
  {
    v39 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259) ^ 0x10827371LL;
    v40 = *(_BYTE *)(v0 + 104) ^ 0xF3;
    if ( v40 == 1 )
    {
      LOBYTE(v39) = __ROL1__(v39, *(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127));
      __readeflags();
    }
    if ( v40 == 2 )
    {
      LOWORD(v39) = __ROL2__(v39, *(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127));
      __readeflags();
    }
    if ( v40 == 3 )
    {
      v39 = (unsigned int)__ROL4__(v39, *(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127));
      __readeflags();
    }
    if ( v40 == 4 )
    {
      v39 = __ROL8__(v39, *(_BYTE *)(v0 + 158) ^ (unsigned __int8)(*(_BYTE *)(v0 + 210) + 127));
      __readeflags();
    }
    *(_QWORD *)(v0 + 327) = v39 ^ 0x5AA84381;
  }
  if ( *(_BYTE *)(v0 + 157) == 0x8F )
  {
    v41 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259) ^ 0x10827371LL;
    v42 = *(_QWORD *)(v0 + 158) ^ (*(_QWORD *)(v0 + 210) - 1520976769LL);
    v43 = *(_BYTE *)(v0 + 218) ^ 0xB5;
    if ( v43 == 1 )
      v41 = (char)(*(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127));
    if ( v43 == 2 )
      v41 = (__int16)v42;
    if ( v43 == 3 )
      v41 = (unsigned int)v42;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v41 ^ 0x5AA84381;
  }
  if ( *(_BYTE *)(v0 + 157) == 70 )
  {
    v44 = *(_QWORD *)(v0 + 158) ^ (*(_QWORD *)(v0 + 210) - 1520976769LL);
    __readeflags();
    *(_QWORD *)(v0 + 327) = v44 ^ 0x5AA84381;
  }
  if ( *(_BYTE *)(v0 + 157) == 82 )
  {
    v45 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259) ^ 0x10827371LL;
    v46 = *(_BYTE *)(v0 + 104) ^ 0xF3;
    if ( v46 == 1 )
    {
      LOBYTE(v45) = (unsigned __int8)v45 >> (*(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127));
      __readeflags();
    }
    if ( v46 == 2 )
    {
      LOWORD(v45) = (unsigned __int16)v45 >> (*(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127));
      __readeflags();
    }
    if ( v46 == 3 )
    {
      v45 = (unsigned int)v45 >> (*(_BYTE *)(v0 + 158) ^ (*(_BYTE *)(v0 + 210) + 127));
      __readeflags();
    }
    if ( v46 == 4 )
    {
      v45 >>= *(_BYTE *)(v0 + 158) ^ (unsigned __int8)(*(_BYTE *)(v0 + 210) + 127);
      __readeflags();
    }
    *(_QWORD *)(v0 + 327) = v45 ^ 0x5AA84381;
  }
  v47 = *(_BYTE *)(v0 + 157);
  *(_DWORD *)(v0 + 307) &= 0x37DA702Bu;
  if ( v47 == -71 )
  {
    v48 = (*(_QWORD *)(v0 + 158) ^ (*(_QWORD *)(v0 + 210) - 1520976769LL))
        * (*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259) ^ 0x10827371LL);
    v49 = __readeflags();
    v56 = v49;
    *(_QWORD *)(v0 + 327) = v48 ^ 0x5AA84381;
  }
  *(_DWORD *)(v0 + 174) += *(_DWORD *)(v0 + 105);
  *(_DWORD *)(v0 + 285) &= 0x26669546u;
  if ( *(_BYTE *)(v0 + 157) != 0x88 && *(_BYTE *)(v0 + 157) != 0xAD )
  {
    v50 = *(_BYTE *)(v0 + 104) ^ 0xF3;
    v51 = (_BYTE *)(*(_QWORD *)(v0 + 149) ^ 0x494FC150LL);
    v52 = *(_QWORD *)(v0 + 327) ^ 0x5AA84381LL;
    if ( v50 == 1 )
      *v51 = v52;
    if ( v50 == 2 )
      *(_WORD *)v51 = v52;
    if ( v50 == 3 )
    {
      *(_DWORD *)v51 = v52;
      LOBYTE(v52) = *(_BYTE *)(v0 + 74);
      if ( (_BYTE)v52 != 0 )
      {
        v51 += 4;
        *(_DWORD *)v51 = 0;
      }
    }
    if ( v50 == 4 )
      *(_QWORD *)v51 = v52;
  }
  *(_DWORD *)(v0 + 247) |= 0x5C8A468Bu;
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 10LL) != 0 )
    *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 14LL)) = v56;
  v53 = *(_QWORD *)(v0 + 84);
  v54 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) ^= (((_BYTE)v0 + 29) & 0x75 ^ 0x4DLL) - 242 - (v0 + 307);
  v54 += 219323096;
  *(_DWORD *)(v0 + 105) ^= v54;
  v55 = *(_QWORD *)(8LL * (unsigned __int16)v54 + v53);
  *(_QWORD *)(v0 + 251) += 20LL;
  __asm { jmp     r10 }
}


// ===== Dp_H015_32d5d @ 0x280082d5d size=0x518 =====
__int64 __fastcall Dp_H015_32d5d()
{
  __int64 v0; // rbp
  __int64 v1; // r13
  __int64 v2; // r9
  unsigned __int64 v3; // kr00_8
  _QWORD *v4; // rsi
  _QWORD *v5; // r15
  unsigned __int16 *v6; // r13
  __int64 v7; // r12
  char v8; // r15
  __int64 v9; // rcx
  __int64 v10; // r10
  __int64 (__fastcall *v11)(__int64, __int64, _QWORD, __int64); // r8

  v2 = v0 + 335;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) |= 0x13349F24u;
  v3 = __readeflags();
  v4 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  v5 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) & 0x400LL) != 0 )
  {
    v2 = v0 + **(unsigned __int16 **)(v0 + 251);
    v6 = (unsigned __int16 *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
    --*v4;
    --*v5;
  }
  else
  {
    ++*v4;
    ++*v5;
    v6 = (unsigned __int16 *)(v1 - 172);
  }
  v7 = *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 10LL);
  v8 = v3 & (((((unsigned __int8)v5 ^ 0x90) - 14) ^ 0xB7) + 19) ^ 0xE2;
  v9 = 0x100000309LL;
  *(_DWORD *)(v0 + 247) &= 0x5BF097BFu;
  if ( v7 != 0 )
  {
    v6 = (unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL);
    *(_QWORD *)(v0 + *v6) = v3;
    v9 = 2 * (((v8 & 0x4D) - 115LL) ^ 0x2A);
  }
  v10 = (unsigned __int16)(*(_WORD *)(*(_QWORD *)(v0 + 251) + 8LL) - *(_WORD *)(v0 + 105));
  v11 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64))(8 * v10 + *(_QWORD *)(v0 + 84));
  *(_QWORD *)(v0 + 251) += 11LL;
  return v11(v9 - 2147483758LL, v0 + 105, v11, v10 & (((v2 + 86 - (_QWORD)v6 + 4) ^ 0x800) - 77));
}


// ===== Dp_H016_33275 @ 0x280083275 size=0x366 =====
__int64 __fastcall Dp_H016_33275(__int64 a1)
{
  __int64 v1; // rbp
  unsigned __int64 v2; // kr00_8
  _QWORD *v3; // r11
  _QWORD *v4; // r10
  __int64 v5; // r15
  __int64 v6; // r13
  int v7; // r12d
  __int64 (__fastcall *v8)(__int64, _QWORD, __int64, __int64); // rdx

  *(_DWORD *)(v1 + 105) |= 0x35BCF04u;
  *(_DWORD *)(v1 + 105) &= 0x328793D5u;
  *(_DWORD *)(v1 + 335) += 897920955;
  if ( (*(_DWORD *)(v1 + 335) & 1) != 0 )
  {
    a1 = v1 + 335;
    *(_DWORD *)(v1 + 335) &= 0x1A964F98u;
  }
  v2 = __readeflags();
  v3 = (_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 7LL));
  v4 = (_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 5LL));
  if ( (*(_DWORD *)(v1 + 28) & 0x400LL | *(_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 9LL)) & 0x400LL) != 0 )
  {
    *v4 -= 4LL;
    *v3 -= 4LL;
  }
  else
  {
    *v4 += 4LL;
    *v3 += 4LL;
  }
  v5 = a1 - v2;
  if ( *(_BYTE *)(*(_QWORD *)(v1 + 251) + 4LL) != 0 )
  {
    *(_QWORD *)(v1 + **(unsigned __int16 **)(v1 + 251)) = v2;
    v5 = 0;
  }
  v6 = *(_QWORD *)(v1 + 84);
  v7 = *(_DWORD *)(v1 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 2LL);
  *(_QWORD *)(v1 + 158) ^= v5 - (v1 - 121);
  v8 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, __int64))(8LL * (unsigned __int16)(v7 + 26365) + v6);
  *(_QWORD *)(v1 + 251) += 11LL;
  return v8(v1 + 251, v8, v1 + 105, (v6 + 224) ^ 0x53);
}


// ===== Dp_H017_335db @ 0x2800835db size=0x1873 =====
void __fastcall Dp_H017_335db()
{
  __int64 v0; // rbp
  int v1; // r9d
  char v2; // di
  int v3; // r9d
  __int64 v4; // r12
  char v5; // r15
  _BYTE *v6; // rbx
  _QWORD *v7; // r12
  __int64 v8; // rdi
  char v9; // r10
  __int64 v10; // r11
  __int64 v11; // r8
  char v12; // si
  __int64 v13; // r11
  unsigned __int64 v14; // rdx
  __int64 v15; // r8
  unsigned __int64 v16; // kr18_8
  unsigned __int64 *v17; // r10
  __int64 v18; // r13
  __int64 v19; // rdi
  __int64 v20; // rdx
  char v21; // r13
  char v22; // al
  char v23; // r13
  __int64 v24; // r9
  int v25; // esi
  __int64 v26; // rdi
  unsigned __int64 v27; // [rsp-20h] [rbp-20h]

  v1 = (*(_DWORD *)(v0 + 105) ^ *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 3LL)) - *(_DWORD *)(v0 + 335);
  *(_DWORD *)(v0 + 105) -= v1;
  *(_DWORD *)(v0 + 335) -= 1735735214;
  v2 = *(_BYTE *)(v0 + 285) ^ v1;
  *(_BYTE *)(v0 + 83) = ((unsigned __int8)(v2 & 0xF0) >> 4) + 126;
  *(_BYTE *)(v0 + 104) = (v2 & 0xF) + 90;
  *(_DWORD *)(v0 + 285) ^= 0x429F7D7Cu;
  v3 = *(_DWORD *)(v0 + 335) ^ (*(_DWORD *)(v0 + 105) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 4LL));
  *(_DWORD *)(v0 + 105) &= v3;
  *(_DWORD *)(v0 + 335) ^= 0xE8A6EBAu;
  *(_DWORD *)(v0 + 285) -= 1939651081;
  *(_BYTE *)(v0 + 157) ^= v3;
  v4 = (unsigned int)(*(_DWORD *)(v0 + 105) ^ *(_DWORD *)(*(_QWORD *)(v0 + 251) + 5LL));
  *(_DWORD *)(v0 + 335) ^= 0x49EE2512u;
  *(_DWORD *)(v0 + 285) ^= 0x13533550u;
  *(_QWORD *)(v0 + 259) = v4 + 561641170 - *(_QWORD *)(v0 + 158);
  if ( *(_BYTE *)(v0 + 83) == 0x80 )
  {
    v5 = *(_BYTE *)(v0 + 104) - 90;
    v6 = *(_BYTE **)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259) + 2350));
    *(_QWORD *)(v0 + 149) = v6 - 731994695;
    if ( v5 == 1 )
      LOBYTE(v6) = *v6;
    if ( v5 == 2 )
      LOWORD(v6) = *(_WORD *)v6;
    if ( v5 == 3 )
      v6 = (_BYTE *)*(unsigned int *)v6;
    if ( v5 == 4 )
      v6 = *(_BYTE **)v6;
    *(_QWORD *)(v0 + 259) = &v6[-*(_QWORD *)(v0 + 158) + 561641170];
  }
  *(_BYTE *)(v0 + 74) = 0;
  if ( *(_BYTE *)(v0 + 83) == 127 )
  {
    v7 = (_QWORD *)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259) + 2350));
    *(_QWORD *)(v0 + 149) = (char *)v7 - 731994695;
    *(_QWORD *)(v0 + 259) = *v7 + 561641170LL - *(_QWORD *)(v0 + 158);
    if ( (unsigned __int8)*(_QWORD *)(v0 + 104) == 93 )
      *(_BYTE *)(v0 + 74) = 11;
  }
  if ( (*(_BYTE *)(v0 + 157) ^ 0x6E) == 0xDA )
  {
    v8 = 561641170LL - (*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259));
    __readeflags();
    *(_QWORD *)(v0 + 327) = v8 - 999947668;
  }
  v9 = (*(_BYTE *)(v0 + 157) ^ 0x6E) - 98;
  *(_DWORD *)(v0 + 105) += 959382175;
  if ( v9 == 0 )
  {
    v10 = *(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259) - 561641171LL;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v10 - 999947668;
  }
  *(_DWORD *)(v0 + 307) &= 0x392F029Fu;
  *(_DWORD *)(v0 + 247) &= 0x43541DA7u;
  *(_DWORD *)(v0 + 285) &= 0x7D68094Du;
  LOBYTE(v11) = 27;
  v12 = (*(_BYTE *)(v0 + 157) ^ 0x6E) - 46 + 109;
  *(_DWORD *)(v0 + 105) &= 0x7F7E661Bu;
  if ( v12 == 0 )
  {
    v13 = *(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259) - 561641170LL + 1;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v13 - 999947668;
  }
  *(_DWORD *)(v0 + 307) &= 0x7F7E661Bu;
  v14 = 512;
  if ( (*(_BYTE *)(v0 + 157) ^ 0x6E) == 0x20 )
  {
    v15 = ~(*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259) - 561641170LL);
    v16 = __readeflags();
    v27 = v16;
    v11 = v15 - 999947668;
    v14 = (v0 + 327) & (((((_BYTE)v0 - 40) & 1) - 64LL) ^ 0xFFFFFFFF80000000uLL);
    *(_QWORD *)(v0 + 327) = v11;
  }
  LOBYTE(v17) = **(_BYTE **)(v0 + 251);
  LOBYTE(v14) = (*(_BYTE *)(v0 + 157) ^ 0x6E) - 46;
  if ( (_BYTE)v17 != 0 )
  {
    v11 = *(_QWORD *)(v0 + 251) + 9LL;
    v17 = (unsigned __int64 *)(v0 + *(unsigned __int16 *)v11);
    *v17 = v27;
  }
  LOBYTE(v14) = v14 + 7;
  v18 = ((((unsigned __int8)(v0 - 99) | (unsigned __int8)(v11 + 84)) & 0xF) - v14) ^ 0x9C | 0x80;
  if ( (_BYTE)v14 != 0 && (*(_BYTE *)(v0 + 157) ^ 0x6E) != 0x4C )
  {
    v19 = *(_QWORD *)(v0 + 149) + 731994695LL;
    v20 = *(_QWORD *)(v0 + 327) + 999947668LL;
    v21 = v11 & (((v0 + 104) & 0xF ^ 0x1C | 0xF) - v19 + 125) | 0x93;
    v22 = *(_BYTE *)(v0 + 104) - 90;
    if ( *(_BYTE *)(v0 + 104) == 91 )
    {
      v21 = -111;
      *(_BYTE *)v19 = *(_BYTE *)(v0 + 327) - 108;
    }
    if ( v22 == 2 )
    {
      *(_WORD *)v19 = v20;
      v21 = (v0 - 99 - (_BYTE)v17) & 0x75;
    }
    if ( v22 == 3 )
    {
      *(_DWORD *)v19 = v20;
      v23 = 2 * ((v11 + 30) ^ 0x4D) - 49;
      LOBYTE(v20) = *(_BYTE *)(v0 + 74);
      if ( (_BYTE)v20 != 0 )
      {
        v19 += 4;
        *(_DWORD *)v19 = 0;
        v23 = v11 ^ (((v23 ^ 0xD3) - (_BYTE)v17) & 3 | 0xAC);
      }
      v21 = ((v19 ^ v23) & 1) + 109;
    }
    if ( v22 == 4 )
    {
      *(_QWORD *)v19 = v20;
      v21 = 0;
    }
    v18 = ((unsigned __int8)v21 & 0xB7) - v27 - 100;
  }
  v24 = *(_QWORD *)(v0 + 84);
  v25 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 1LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) += v18;
  v25 -= 1352203478;
  *(_DWORD *)(v0 + 105) |= v25;
  v26 = *(_QWORD *)(8LL * (unsigned __int16)v25 + v24);
  *(_QWORD *)(v0 + 251) += 11LL;
  __asm { jmp     rdi }
}


// ===== Dp_H018_34e4e @ 0x280084e4e size=0x136 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H018_34e4e()
{
  __int64 v0; // rbp
  _QWORD *v1; // r14
  char v2; // bl
  __int64 v3; // r15
  _QWORD *v4; // r15
  __int64 result; // rax
  _BYTE v6[128]; // [rsp-80h] [rbp-80h] BYREF

  v2 = *(_BYTE *)(*(_QWORD *)(v0 + 251) + 10LL);
  v3 = 0;
  if ( v2 == -33 )
  {
    v3 = *(_QWORD *)(v0 + 239) + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 6LL);
    v1 = &v6[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)];
    *v1 = v3;
  }
  if ( v2 == 111 || v2 == 82 )
  {
    LOWORD(v3) = *(_WORD *)(*(_QWORD *)(v0 + 251) + 6LL);
    v4 = *(_QWORD **)(v0 + v3);
    if ( v2 == 82 )
      v4 = (_QWORD *)*v4;
    v1 = &v6[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)];
    *v1 = v4;
  }
  v1[1] = *(_QWORD *)(v0 + 239) + **(unsigned int **)(v0 + 251);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v6[112];
  __writeeflags(*(unsigned __int64 *)&v6[120]);
  return result;
}


// ===== Dp_H019_34f84 @ 0x280084f84 size=0x344 =====
__int64 __fastcall Dp_H019_34f84(__int64 a1, char a2)
{
  __int64 v2; // rbp
  __int64 v3; // rbx
  __int64 v4; // rdx
  __int64 v5; // r10
  int v6; // esi
  __int64 v7; // rdx
  __int64 (__fastcall *v8)(__int64, __int64, __int64, __int64); // r11
  _QWORD *v10; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v2 + 247) &= 0x477A4CE2u;
  if ( (*(_DWORD *)(v2 + 335) & 1) != 0 )
    *(_DWORD *)(v2 + 335) -= 91659108;
  *(_DWORD *)(v2 + 285) -= 1224535841;
  v3 = *(unsigned __int16 *)(*(_QWORD *)(v2 + 251) + 4LL);
  v10 = (_QWORD *)(v2 + v3);
  *(_BYTE *)(v2 + **(unsigned __int16 **)(v2 + 251)) = **(_BYTE **)(v2 + v3);
  v4 = a1 | (v2 + 285 + ((((unsigned __int8)v3 & (a2 & 4 | 0x60)) - 6) & 0x34)) ^ 4;
  if ( (*(_QWORD *)(v2 + *(unsigned __int16 *)(*(_QWORD *)(v2 + 251) + 2LL)) & 0x400LL) != 0 )
  {
    --*v10;
  }
  else
  {
    ++*v10;
    v4 = (v4 - 15) ^ 0x93;
  }
  v5 = *(_QWORD *)(v2 + 84);
  v6 = *(_DWORD *)(v2 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v2 + 251) + 6LL);
  v7 = (v2 + 285) ^ v4;
  *(_QWORD *)(v2 + 158) ^= v7;
  v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(8LL * (unsigned __int16)(v6 - 26025) + v5);
  *(_QWORD *)(v2 + 251) += 8LL;
  return v8(-v7 ^ 0xFFFF, v7, v2 + 158, 2680);
}


// ===== Dp_H020_352c8 @ 0x2800852c8 size=0x77 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H020_352c8()
{
  __int64 v0; // rbp
  __int64 result; // rax
  _BYTE v2[128]; // [rsp-80h] [rbp-80h]

  *(_QWORD *)&v2[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)] = **(_QWORD **)(v0
                                                                                   + **(unsigned __int16 **)(v0 + 251));
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v2[112];
  __writeeflags(*(unsigned __int64 *)&v2[120]);
  return result;
}


// ===== Dp_H022_35529 @ 0x280085529 size=0x3af =====
__int64 __fastcall Dp_H022_35529()
{
  __int64 v0; // rbp
  _QWORD *v1; // r8
  _WORD **v2; // r11
  __int64 v3; // r8
  int v4; // r9d
  __int64 (*v5)(void); // r15

  v1 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  v2 = (_WORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) ^= 0x5AED4962u;
  **v2 = *v1;
  if ( (*(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) & 0x400LL) != 0 )
    --*v2;
  else
    ++*v2;
  *(_DWORD *)(v0 + 105) ^= 0x230BA1CFu;
  *(_DWORD *)(v0 + 335) |= 0x4C38A347u;
  *(_DWORD *)(v0 + 307) -= 2030693683;
  *(_DWORD *)(v0 + 105) -= 1956512330;
  *(_DWORD *)(v0 + 307) |= 0x749E024Au;
  v3 = *(_QWORD *)(v0 + 84);
  v4 = (*(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL)) + 340131999;
  *(_DWORD *)(v0 + 105) |= v4;
  v5 = *(__int64 (**)(void))(8LL * (unsigned __int16)v4 + v3);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v5();
}


// ===== Dp_H023_358d8 @ 0x2800858d8 size=0x3f5 =====
__int64 __fastcall Dp_H023_358d8()
{
  __int64 v0; // rbp
  unsigned __int64 v1; // kr00_8
  _QWORD *v2; // rbx
  _QWORD *v3; // r13
  unsigned __int64 v4; // rdi
  __int64 v5; // r10
  __int64 v6; // rcx
  __int64 v7; // r13
  int v8; // r15d
  __int64 (__fastcall *v9)(__int64, __int64, unsigned __int64); // r14

  *(_DWORD *)(v0 + 247) -= 1646122530;
  *(_DWORD *)(v0 + 105) += 1526907273;
  v1 = __readeflags();
  v2 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  v3 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 7LL)) & 0x400LL) != 0 )
  {
    --*v3;
    --*v2;
  }
  else
  {
    ++*v3;
    ++*v2;
  }
  v4 = v1;
  v5 = 235;
  v6 = *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 6LL);
  *(_DWORD *)(v0 + 335) |= 0x4EB38B7u;
  if ( v6 != 0 )
  {
    v5 = 120;
    *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) = v1;
    v4 = 0;
  }
  v7 = *(_QWORD *)(v0 + 84);
  v8 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) ^= v5;
  v8 -= 1741296346;
  *(_DWORD *)(v0 + 105) |= v8;
  v9 = *(__int64 (__fastcall **)(__int64, __int64, unsigned __int64))(8LL * (unsigned __int16)v8 + v7);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v9(v0 + 251, 512, (v4 | 0x8D) - 8);
}


// ===== Dp_H025_36a13 @ 0x280086a13 size=0x51e =====
__int64 __fastcall Dp_H025_36a13()
{
  __int64 v0; // rbp
  unsigned __int8 **v1; // r14
  unsigned __int8 v2; // dl
  unsigned __int64 v3; // kr00_8
  __int64 v4; // r9
  _QWORD *v5; // r14
  _QWORD *v6; // r10
  __int64 v7; // rdx
  __int64 v8; // r14
  unsigned __int64 *v9; // rbx
  int v10; // r15d
  __int64 v11; // r11
  __int64 (*v12)(void); // rcx

  *(_DWORD *)(v0 + 247) ^= 0x3D8D2547u;
  v1 = (unsigned __int8 **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 5LL));
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) ^= 0x6977C3F1u;
  v2 = **v1;
  v3 = __readeflags();
  v4 = *(_DWORD *)(v0 + 28) & 0x400LL;
  v5 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 7LL));
  v6 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 5LL));
  if ( (v4 | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL)) & 0x400LL) != 0 )
  {
    --*v5;
    --*v6;
  }
  else
  {
    ++*v5;
    ++*v6;
  }
  v7 = v2 & 0x8D;
  v8 = 77;
  v9 = (unsigned __int64 *)*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 2LL);
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 2LL) != 0 )
  {
    v9 = (unsigned __int64 *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 3LL));
    *v9 = v3;
    v7 = (v4 - 77 + 86) | v7 & 4 | 0xD3 | 0xF0;
    v8 = -15;
  }
  *(_DWORD *)(v0 + 105) |= 0x57F02AAAu;
  v10 = **(unsigned __int16 **)(v0 + 251);
  v11 = *(_QWORD *)(v0 + 84);
  *(_QWORD *)(v0 + 158) -= (char *)v9 + ((v8 - 128) ^ v7);
  v10 += 1579879926;
  *(_DWORD *)(v0 + 105) |= v10;
  v12 = *(__int64 (**)(void))(8LL * (unsigned __int16)v10 + v11);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v12();
}


// ===== Dp_H026_36f31 @ 0x280086f31 size=0x587 =====
__int64 __fastcall Dp_H026_36f31()
{
  __int64 v0; // rbp
  unsigned __int64 v1; // kr00_8
  __int64 v2; // rbx
  _QWORD *v3; // r15
  __int64 v4; // rcx
  _QWORD *v5; // rbx
  __int64 v6; // rcx
  _BYTE *v7; // rdi
  __int64 v8; // r13
  __int64 v9; // r10
  int v10; // r8d
  __int64 v11; // r8
  __int64 (__fastcall *v12)(__int64, __int64, __int64, __int64); // rbx

  *(_DWORD *)(v0 + 285) |= 0x72A77AF1u;
  v1 = __readeflags();
  v2 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL);
  v3 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
  v4 = v2 | 0x7B4;
  v5 = (_QWORD *)(v0 + v2);
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 7LL)) & 0x400LL) != 0 )
  {
    v6 = v4 | 0x93;
    *v5 -= 2LL;
    *v3 -= 2LL;
  }
  else
  {
    *v5 += 2LL;
    *v3 += 2LL;
    v6 = v4 ^ 0xAC;
  }
  *(_DWORD *)(v0 + 105) += 1280866867;
  *(_DWORD *)(v0 + 285) += 1773786268;
  *(_DWORD *)(v0 + 105) ^= 0x4B73573u;
  v7 = (_BYTE *)(*(_QWORD *)(v0 + 251) + 6LL);
  *(_DWORD *)(v0 + 335) |= 0x4C79A9BFu;
  v8 = 18;
  if ( *v7 != 0 )
  {
    v8 = 190;
    *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) = v1;
  }
  v9 = *(_QWORD *)(v0 + 84);
  v10 = **(unsigned __int16 **)(v0 + 251);
  *(_QWORD *)(v0 + 158) ^= v6 ^ v8;
  v10 ^= 0x2E7BDED6u;
  *(_DWORD *)(v0 + 105) -= v10;
  v11 = 8LL * (unsigned __int16)v10;
  v12 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v11 + v9);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v12(v6, v0 + 105, v11, ((v0 + 105) ^ 0x90) - 4);
}


// ===== Dp_H027_374b8 @ 0x2800874b8 size=0xfe =====
__int64 __fastcall Dp_H027_374b8()
{
  __int64 v0; // rbp
  __int64 v1; // r13
  int v2; // r10d
  __int64 (*v3)(void); // rax
  _QWORD **v5; // [rsp-8h] [rbp-8h]

  v5 = (_QWORD **)(v0 + **(unsigned __int16 **)(v0 + 251));
  *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) = **v5;
  if ( (*(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL)) & 0x400LL) != 0 )
    --*v5;
  else
    ++*v5;
  v1 = *(_QWORD *)(v0 + 84);
  v2 = (*(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) + 276373418;
  *(_DWORD *)(v0 + 105) -= v2;
  v3 = *(__int64 (**)(void))(8LL * (unsigned __int16)v2 + v1);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v3();
}


// ===== Dp_H028_375b6 @ 0x2800875b6 size=0x32d =====
__int64 __fastcall Dp_H028_375b6()
{
  __int64 v0; // rbp
  char v1; // r13
  _WORD *v2; // rbx
  __int64 v3; // r12
  __int64 v4; // r14
  __int64 v5; // r11
  __int64 v6; // r10
  unsigned __int64 v7; // r12
  __int64 v8; // r13
  int v9; // r15d
  __int64 (__fastcall *v10)(unsigned __int64, _QWORD, __int64); // rdx
  _QWORD *v12; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v0 + 247) ^= 0x4105B101u;
  *(_DWORD *)(v0 + 105) ^= 0x6BCDDCF9u;
  *(_DWORD *)(v0 + 335) &= 0x71C1AC1Bu;
  *(_DWORD *)(v0 + 105) += 1038637094;
  *(_DWORD *)(v0 + 307) ^= 0x3DE85826u;
  v12 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  v2 = (_WORD *)*v12;
  v3 = *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  *(_WORD *)*v12 = v3;
  v4 = (((v1 & ((unsigned __int8)(v0 + 51) | 8) | 0xE2) + 1) & 0x4D) - 98LL;
  v5 = *(_QWORD *)(v0 + 251) + 2LL;
  v6 = *(_QWORD *)(v0 + *(unsigned __int16 *)v5) & 0x400LL;
  v7 = (v3 + 0x80000000LL) ^ 0xFFFFFFFF800000F9uLL;
  if ( v6 != 0 )
  {
    *v12 -= 2LL;
  }
  else
  {
    *v12 += 2LL;
    v7 = v5 & ((unsigned __int64)v2 + v7);
  }
  v8 = *(_QWORD *)(v0 + 84);
  v9 = *(_DWORD *)(v0 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL);
  *(_QWORD *)(v0 + 158) -= v7 + v4;
  v9 -= 1974666855;
  *(_DWORD *)(v0 + 105) ^= v9;
  v10 = *(__int64 (__fastcall **)(unsigned __int64, _QWORD, __int64))(8LL * (unsigned __int16)v9 + v8);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v10(
           v0 | (512 - ((((((((v6 - 1) ^ 0xDC) - 30) | 0x90) - v7 - 512) ^ 0x4D) + 172) | 0xF9)),
           v10,
           v8 & ((v0 + 158) ^ 0xA0));
}


// ===== Dp_H029_378e3 @ 0x2800878e3 size=0x4ae =====
__int64 __fastcall Dp_H029_378e3()
{
  __int64 v0; // rbp
  unsigned __int64 v1; // kr00_8
  _QWORD *v2; // r15
  __int64 v3; // rdx
  _QWORD *v4; // r13
  __int64 v5; // r12
  unsigned __int64 *v6; // r12
  unsigned __int64 v7; // r12
  __int16 v8; // si
  __int64 v9; // r9
  __int64 v10; // rdx
  __int64 (__fastcall *v11)(_QWORD, __int64, unsigned __int64); // r11

  *(_DWORD *)(v0 + 247) &= 0x285C3260u;
  *(_DWORD *)(v0 + 285) &= 0x5304B4C1u;
  *(_DWORD *)(v0 + 105) += 1300458300;
  v1 = __readeflags();
  v2 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
  v3 = -2147483887LL;
  v4 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL)) & 0x400LL) != 0 )
  {
    *v4 -= 2LL;
    *v2 -= 2LL;
  }
  else
  {
    *v4 += 2LL;
    *v2 += 2LL;
    v3 = 16;
  }
  *(_DWORD *)(v0 + 105) -= 1672805535;
  *(_DWORD *)(v0 + 307) |= 0x63B4FC9Fu;
  v5 = *(_QWORD *)(v0 + 251);
  *(_DWORD *)(v0 + 105) &= 0x48424441u;
  v6 = (unsigned __int64 *)*(unsigned __int8 *)(v5 + 8);
  if ( v6 != nullptr )
  {
    v6 = (unsigned __int64 *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
    *v6 = v1;
  }
  v7 = (unsigned __int64)v6 + v3 - 0x7FFFFFFF;
  v8 = *(_WORD *)(*(_QWORD *)(v0 + 251) + 2LL);
  v9 = *(_QWORD *)(v0 + 84);
  v10 = v7 ^ v3;
  *(_QWORD *)(v0 + 158) ^= v10;
  v11 = *(__int64 (__fastcall **)(_QWORD, __int64, unsigned __int64))(8LL * (unsigned __int16)(v8 + 22055) + v9);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v11(0, v10, (2 * (v7 & 0x800 ^ 0x31)) | 0xF9);
}


// ===== Dp_H030_37d91 @ 0x280087d91 size=0x4f4 =====
__int64 __fastcall Dp_H030_37d91(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rax
  int v5; // ebx
  __int64 v6; // rbp
  int v7; // r12d
  int v8; // ebx
  _WORD *v9; // r13
  unsigned __int64 v10; // kr00_8
  _QWORD *v11; // rdi
  char v12; // r12
  __int64 v13; // rbx
  __int64 v14; // r12
  __int64 v15; // r10
  __int64 v16; // rsi
  int v17; // edi
  __int64 (__fastcall *v18)(__int64, _QWORD, __int64, __int64); // rdx

  v8 = a1 + (v7 ^ v5 | 0x83);
  v9 = *(_WORD **)(v6 + *(unsigned __int16 *)(*(_QWORD *)(v6 + 251) + 9LL));
  *v9 -= *(_QWORD *)(v6 + **(unsigned __int16 **)(v6 + 251));
  v10 = __readeflags();
  v11 = (_QWORD *)(v6 + *(unsigned __int16 *)(*(_QWORD *)(v6 + 251) + 9LL));
  v12 = (v6 + 28) & 0xA;
  if ( (*(_DWORD *)(v6 + 28) & 0x400LL | *(_QWORD *)(v6 + *(unsigned __int16 *)(*(_QWORD *)(v6 + 251) + 7LL)) & 0x400LL) != 0 )
  {
    *v11 -= 2LL;
  }
  else
  {
    *v11 += 2LL;
    v12 = 19;
  }
  v13 = ((v8 & 0x7FFFFFFF) - a4) ^ 8;
  v14 = ((unsigned __int8)v12 & 0xF6) - 289LL;
  v15 = *(unsigned __int8 *)(*(_QWORD *)(v6 + 251) + 6LL);
  *(_DWORD *)(v6 + 105) += 67579902;
  if ( v15 != 0 )
  {
    *(_QWORD *)(v6 + *(unsigned __int16 *)(*(_QWORD *)(v6 + 251) + 4LL)) = v10;
    v14 = (v13 + ((a1 + 228) & v14) - 181 + 100) ^ 0xF0;
  }
  *(_DWORD *)(v6 + 335) ^= 0x74133623u;
  *(_DWORD *)(v6 + 247) &= 0x46E59BBu;
  *(_DWORD *)(v6 + 285) &= 0xCE4A7C3u;
  v16 = *(_QWORD *)(v6 + 84);
  v17 = *(_DWORD *)(v6 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v6 + 251) + 2LL);
  *(_QWORD *)(v6 + 158) -= (v14 | 0x1F) + 131 + v4;
  v17 -= 415985978;
  *(_DWORD *)(v6 + 105) += v17;
  v18 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, __int64))(8LL * (unsigned __int16)v17 + v16);
  *(_QWORD *)(v6 + 251) += 11LL;
  return v18(
           (v6 + 158) ^ 0xE4,
           v18,
           v6 + 158,
           (((v16 + 2 * (v16 + ((v6 + 335) ^ 0x406 | 6)) - 147) | 0x2A) ^ 0x7FFFFFFF) - 30);
}


// ===== Dp_H031_38285 @ 0x280088285 size=0x78 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H031_38285()
{
  __int64 v0; // rbp
  __int64 result; // rax
  _BYTE v2[128]; // [rsp-80h] [rbp-80h]

  *(_QWORD *)&v2[**(unsigned __int16 **)(v0 + 251)] = *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v2[112];
  __writeeflags(*(unsigned __int64 *)&v2[120]);
  return result;
}


// ===== Dp_H032_382fd @ 0x2800882fd size=0x102 =====
__int64 __fastcall Dp_H032_382fd(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rax
  __int64 v5; // rbp
  __int64 v6; // r10
  int v7; // r11d
  __int64 (__fastcall *v8)(__int64, __int64, _QWORD **); // r15
  _QWORD **v10; // [rsp-8h] [rbp-8h]

  v10 = (_QWORD **)(v5 + *(unsigned __int16 *)(*(_QWORD *)(v5 + 251) + 6LL));
  **v10 = *(_QWORD *)(v5 + **(unsigned __int16 **)(v5 + 251));
  if ( (*(_QWORD *)(v5 + *(unsigned __int16 *)(*(_QWORD *)(v5 + 251) + 2LL)) & 0x400LL) != 0 )
    --*v10;
  else
    ++*v10;
  v6 = *(_QWORD *)(v5 + 84);
  v7 = *(unsigned __int16 *)(*(_QWORD *)(v5 + 251) + 4LL);
  *(_QWORD *)(v5 + 158) ^= v4 - a4;
  v7 ^= 0x308D7A71u;
  *(_DWORD *)(v5 + 105) &= v7;
  v8 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD **))(8LL * (unsigned __int16)v7 + v6);
  *(_QWORD *)(v5 + 251) += 8LL;
  return v8(v5 + 158, v5 + 105, v10);
}


// ===== Dp_H033_383ff @ 0x2800883ff size=0x76 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H033_383ff()
{
  __int64 v0; // rbp
  __int64 result; // rax
  _BYTE v2[128]; // [rsp-80h] [rbp-80h]

  *(_QWORD *)&v2[**(unsigned __int16 **)(v0 + 251)] = *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v2[112];
  __writeeflags(*(unsigned __int64 *)&v2[120]);
  return result;
}


// ===== Dp_H034_38475 @ 0x280088475 size=0x4f5 =====
__int64 __fastcall Dp_H034_38475()
{
  __int64 v0; // rbp
  unsigned __int64 v1; // kr00_8
  _QWORD *v2; // r14
  _QWORD *v3; // r11
  unsigned __int64 v4; // rcx
  __int64 v5; // r12
  int v6; // ebx
  __int64 (__fastcall *v7)(unsigned __int64, unsigned __int64); // r9

  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) ^= 0x7AD76802u;
  *(_DWORD *)(v0 + 105) += 209110577;
  *(_DWORD *)(v0 + 335) += 1006263760;
  v1 = __readeflags();
  v2 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  v3 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) & 0x400LL) != 0 )
  {
    --*v2;
    --*v3;
  }
  else
  {
    ++*v2;
    ++*v3;
  }
  v4 = *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 8LL);
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 8LL) != 0 )
  {
    v4 = v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL);
    *(_QWORD *)v4 = v1;
  }
  v5 = *(_QWORD *)(v0 + 84);
  v6 = *(_DWORD *)(v0 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL);
  *(_QWORD *)(v0 + 158) ^= v4;
  v6 -= 45255094;
  *(_DWORD *)(v0 + 105) -= v6;
  v7 = *(__int64 (__fastcall **)(unsigned __int64, unsigned __int64))(8LL * (unsigned __int16)v6 + v5);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v7(v4, 1266 - v4);
}


// ===== Dp_H035_3896a @ 0x28008896a size=0x218 =====
__int64 __fastcall Dp_H035_3896a()
{
  __int64 v0; // rbp
  __int64 v1; // rdi
  __int64 v2; // r10
  int v3; // r11d
  __int64 (*v4)(void); // r15
  _WORD **v6; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v0 + 105) += 920168190;
  *(_DWORD *)(v0 + 247) += 305892700;
  *(_DWORD *)(v0 + 335) &= 0x27EC5662u;
  *(_DWORD *)(v0 + 285) |= 0x603620B6u;
  *(_DWORD *)(v0 + 105) |= 0x71B5C8E2u;
  *(_DWORD *)(v0 + 335) |= 0x603620B6u;
  *(_DWORD *)(v0 + 105) += 913047591;
  v6 = (_WORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  **v6 = *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  if ( (*(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) & 0x400LL) != 0 )
    --*v6;
  else
    ++*v6;
  v2 = *(_QWORD *)(v0 + 84);
  v3 = *(_DWORD *)(v0 + 105) ^ **(unsigned __int16 **)(v0 + 251);
  *(_QWORD *)(v0 + 158) -= v1;
  v4 = *(__int64 (**)(void))(8LL * (unsigned __int16)(v3 - 31084) + v2);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v4();
}


// ===== Dp_H036_38b82 @ 0x280088b82 size=0x7c =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H036_38b82()
{
  __int64 v0; // rbp
  __int64 result; // rax
  _BYTE v2[128]; // [rsp-80h] [rbp-80h]

  *(_QWORD *)&v2[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)] = *(_QWORD *)(v0 + 239)
                                                                     + **(unsigned int **)(v0 + 251);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v2[112];
  __writeeflags(*(unsigned __int64 *)&v2[120]);
  return result;
}


// ===== Dp_H037_38bfe @ 0x280088bfe size=0x16b1 =====
void __fastcall Dp_H037_38bfe()
{
  __int64 v0; // rbp
  int v1; // r10d
  int v2; // r10d
  int v3; // r12d
  int v4; // esi
  __int64 v5; // rsi
  _QWORD *v6; // r15
  char v7; // al
  __int64 v8; // r8
  char v9; // r9
  char v10; // di
  char v11; // r12
  char v12; // al
  _BYTE *v13; // r8
  char v14; // r9
  char v15; // r11
  char v16; // r15
  __int64 v17; // r11
  __int64 v18; // r10
  __int64 v19; // r15
  unsigned __int8 v20; // r15
  __int64 v21; // rbx
  __int64 v22; // r11
  unsigned __int64 v23; // kr18_8
  char v24; // di
  char v25; // al
  __int64 v26; // rdi
  _BYTE *v27; // r15
  __int64 v28; // rax
  __int64 v29; // r11
  int v30; // ecx
  __int64 v31; // r13
  unsigned __int64 v32; // [rsp-20h] [rbp-20h]

  v1 = *(_DWORD *)(v0 + 335) + (*(_DWORD *)(v0 + 105) ^ *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 8LL));
  *(_DWORD *)(v0 + 105) &= v1;
  *(_DWORD *)(v0 + 335) -= 2138676549;
  v2 = *(_DWORD *)(v0 + 285) ^ v1;
  *(_DWORD *)(v0 + 285) -= 1987190318;
  *(_BYTE *)(v0 + 83) = ((unsigned __int8)(v2 & 0xF0) >> 4) + 110;
  *(_BYTE *)(v0 + 104) = (v2 & 0xF) - 97;
  v3 = *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 7LL) - *(_DWORD *)(v0 + 105) - *(_DWORD *)(v0 + 335);
  *(_DWORD *)(v0 + 105) |= v3;
  *(_DWORD *)(v0 + 335) -= 402171950;
  *(_BYTE *)(v0 + 157) += v3 - *(_BYTE *)(v0 + 285);
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) -= 521585037;
  v4 = *(_DWORD *)(v0 + 307) + (*(_DWORD *)(v0 + 105) ^ *(_DWORD *)(*(_QWORD *)(v0 + 251) + 2LL));
  *(_DWORD *)(v0 + 105) ^= v4;
  *(_DWORD *)(v0 + 335) += 1712223735;
  v5 = (unsigned int)(*(_DWORD *)(v0 + 285) + v4);
  BYTE1(v6) = 0;
  *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) + v5 - 2057701924;
  v7 = (v0 + 45) ^ 0x83;
  if ( *(_BYTE *)(v0 + 83) == 112 )
  {
    v8 = *(_QWORD *)(v0 + 259) - *(_QWORD *)(v0 + 158);
    v9 = v8 + 116 - ((v0 + 3) & 0x34);
    v10 = (v0
         - 98
         + (((v0 & 0x20 ^ 0x91) - 117) & ((v0 & 0xA0 ^ 0x64) & 0x73 ^ 4) & 0x72 | v5)
         + 121
         - (*(_BYTE *)(v0 + 83)
          - 110)
         + 94)
        | 0x60;
    v11 = *(_BYTE *)(v0 + 104) + 97;
    v12 = (((v7 + 8) ^ 0x80) & 0x43 | 0x80) + 121;
    v13 = *(_BYTE **)(v0 + (unsigned __int16)(v8 + 2596));
    v14 = v9 - (_BYTE)v13;
    v15 = (_BYTE)v13 + 121;
    *(_QWORD *)(v0 + 149) = v13 - 1146566023;
    if ( v11 == 1 )
    {
      LOBYTE(v13) = *v13;
      v10 = v15 ^ (v10 + 40) | 0xF0;
    }
    if ( v11 == 2 )
    {
      LOWORD(v13) = *(_WORD *)v13;
      v12 &= v14;
      v10 = (v10 - 4) & 0x34;
    }
    if ( v11 == 3 )
    {
      v13 = (_BYTE *)*(unsigned int *)v13;
      v10 |= v12 | 0x75;
      v12 |= 0xF5u;
    }
    if ( v11 == 4 )
      v13 = *(_BYTE **)v13;
    v7 = v10 & ((v12 | 0xD3) ^ 0xE2 | 6);
    *(_QWORD *)(v0 + 259) = &v13[*(_QWORD *)(v0 + 158) - 2057701924];
  }
  *(_BYTE *)(v0 + 74) = 0;
  *(_DWORD *)(v0 + 105) ^= 0x567B45ABu;
  v16 = *(_BYTE *)(v0 + 83);
  *(_DWORD *)(v0 + 335) -= 124268835;
  LOBYTE(v6) = v16 - 110;
  if ( (_BYTE)v6 == 1 )
  {
    v6 = (_QWORD *)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 259) - *(_WORD *)(v0 + 158) + 2596));
    *(_QWORD *)(v0 + 149) = (char *)v6 - 1146566023;
    *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) + *v6 - 2057701924LL;
    if ( (unsigned __int8)*(_QWORD *)(v0 + 104) == 0xA2 )
      *(_BYTE *)(v0 + 74) = v7 | 3;
  }
  if ( ((unsigned __int8)(*(_BYTE *)(v0 + 157) - 119) ^ 0x24) == 0x34 )
  {
    v17 = *(_QWORD *)(v0 + 259) - *(_QWORD *)(v0 + 158) + 2057701923LL;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v17 + 185995217;
  }
  *(_DWORD *)(v0 + 307) += 15194728;
  v18 = (-2147483533 - (v0 + 105)) | (unsigned __int16)v6 & 0x283;
  if ( ((unsigned __int8)(*(_BYTE *)(v0 + 157) - 119) ^ 0x24) == 0xAC )
  {
    v19 = -(*(_QWORD *)(v0 + 259) - *(_QWORD *)(v0 + 158) + 2057701924LL);
    __readeflags();
    *(_QWORD *)(v0 + 327) = v19 + 185995217;
    v18 = 2147483767LL;
  }
  v20 = *(_BYTE *)(v0 + 157) - 119;
  *(_DWORD *)(v0 + 335) += 66782808;
  if ( (v20 ^ 0x24) == 0xF2 )
  {
    v21 = ~(*(_QWORD *)(v0 + 259) - *(_QWORD *)(v0 + 158) + 2057701924LL);
    __readeflags();
    *(_QWORD *)(v0 + 327) = v21 + 185995217;
  }
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) += 1029737779;
  if ( ((unsigned __int8)(*(_BYTE *)(v0 + 157) - 119) ^ 0x24) == 0x93 )
  {
    v22 = *(_QWORD *)(v0 + 259) - *(_QWORD *)(v0 + 158) + 2057701925LL;
    v23 = __readeflags();
    v32 = v23;
    *(_QWORD *)(v0 + 327) = v22 + 185995217;
  }
  *(_DWORD *)(v0 + 105) |= 0x1592C8D3u;
  v24 = (*(_BYTE *)(v0 + 157) - 119) ^ 0x24;
  *(_DWORD *)(v0 + 307) &= 0x1592C8D3u;
  if ( v24 != -7 && ((unsigned __int8)(*(_BYTE *)(v0 + 157) - 119) ^ 0x24) != 0x1E )
  {
    v25 = *(_BYTE *)(v0 + 104) + 97;
    v26 = *(_QWORD *)(v0 + 327) - 185995217LL;
    v27 = (_BYTE *)(*(_QWORD *)(v0 + 149) + 1146566023LL);
    if ( *(_BYTE *)(v0 + 104) == 0xA0 )
      *v27 = *(_BYTE *)(v0 + 327) + 47;
    if ( v25 == 2 )
      *(_WORD *)v27 = v26;
    if ( v25 == 3 )
    {
      *(_DWORD *)v27 = v26;
      LOBYTE(v26) = *(_BYTE *)(v0 + 74);
      if ( (_BYTE)v26 != 0 )
      {
        v27 += 4;
        *(_DWORD *)v27 = 0;
      }
    }
    if ( v25 == 4 )
      *(_QWORD *)v27 = v26;
  }
  *(_DWORD *)(v0 + 105) |= 0x651E4DA2u;
  *(_DWORD *)(v0 + 285) |= 0x77AFE7D1u;
  *(_DWORD *)(v0 + 335) &= 0x77AFE7D1u;
  v28 = 629;
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 6LL) != 0 )
  {
    *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251)) = v32;
    v28 = 0;
  }
  v29 = *(_QWORD *)(v0 + 84);
  v30 = *(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL);
  *(_QWORD *)(v0 + 158) += v28 ^ v18;
  v30 -= 1001534241;
  *(_DWORD *)(v0 + 105) += v30;
  v31 = *(_QWORD *)(8LL * (unsigned __int16)v30 + v29);
  *(_QWORD *)(v0 + 251) += 11LL;
  __asm { jmp     r13 }
}


// ===== Dp_H038_3a2af @ 0x28008a2af size=0x7a =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H038_3a2af()
{
  __int64 v0; // rbp
  __int64 result; // rax
  _BYTE v2[128]; // [rsp-80h] [rbp-80h]

  *(_QWORD *)&v2[**(unsigned __int16 **)(v0 + 251)] = **(_QWORD **)(v0
                                                                  + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v2[112];
  __writeeflags(*(unsigned __int64 *)&v2[120]);
  return result;
}


// ===== Dp_H039_3a329 @ 0x28008a329 size=0x1f2 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H039_3a329()
{
  __int64 v0; // rbp
  char v1; // r9
  __int64 v2; // r9
  _QWORD *v3; // r12
  _QWORD *v4; // r12
  __int64 result; // rax
  _BYTE v6[128]; // [rsp-80h] [rbp-80h]

  v1 = **(_BYTE **)(v0 + 251);
  if ( (v1 == 1 || v1 == 2)
    && *(_QWORD *)(*(_QWORD *)(v0 + 239)
                 + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 7LL)
                 + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 1LL)) != *(_QWORD *)(v0 + 239)
                                                                       + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 3LL) )
  {
    v2 = *(_QWORD *)(v0 + 239);
    v3 = (_QWORD *)(v2
                  + *(_DWORD *)(*(_QWORD *)(v0 + 251) + 7LL)
                  + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 1LL));
    *v3 -= *(_QWORD *)(v0 + 297);
    *v3 += *(_QWORD *)(v0 + 239);
    if ( **(_BYTE **)(v0 + 251) == 2 )
    {
      v4 = (_QWORD *)(v2
                    + *(_DWORD *)(*(_QWORD *)(v0 + 251) + 7LL)
                    + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 2LL));
      *v4 -= *(_QWORD *)(v0 + 297);
      *v4 += *(_QWORD *)(v0 + 239);
    }
  }
  *(_QWORD *)&v6[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 11LL)] = *(_QWORD *)(v0 + 239)
                                                                      + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 7LL);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v6[112];
  __writeeflags(*(unsigned __int64 *)&v6[120]);
  return result;
}


// ===== Dp_H040_3a51b @ 0x28008a51b size=0x364 =====
__int64 __fastcall Dp_H040_3a51b(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // al
  __int64 v3; // rbp
  __int64 v4; // r11
  __int64 v5; // r12
  __int64 v6; // r8
  int v7; // eax
  __int64 v8; // rcx
  __int64 (__fastcall **v9)(_QWORD, __int64, __int64, __int64); // rcx
  __int64 (__fastcall *v10)(_QWORD, __int64, __int64, __int64); // r11
  _BYTE **v12; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v3 + 105) &= 0x4182B31Bu;
  *(_DWORD *)(v3 + 247) &= 0x12616FB5u;
  *(_DWORD *)(v3 + 335) &= 0x312C39A6u;
  v4 = *(_DWORD *)(v3 + 335) & 1;
  v5 = *(unsigned __int16 *)(*(_QWORD *)(v3 + 251) + 2LL);
  if ( (_DWORD)v4 != 0 )
    *(_DWORD *)(v3 + 335) &= 0x1F8770A5u;
  v12 = (_BYTE **)(v3 + *(unsigned __int16 *)(*(_QWORD *)(v3 + 251) + 4LL));
  v6 = (v2 ^ 1) & 0x75;
  *(_BYTE *)(v3 + v5) = **v12;
  if ( (*(_QWORD *)(v3 + *(unsigned __int16 *)(*(_QWORD *)(v3 + 251) + 6LL)) & 0x400LL) != 0 )
    --*v12;
  else
    ++*v12;
  v7 = **(unsigned __int16 **)(v3 + 251);
  v8 = *(_QWORD *)(v3 + 84);
  *(_QWORD *)(v3 + 158) += a2 ^ v4;
  v7 -= 1151781122;
  *(_DWORD *)(v3 + 105) |= v7;
  v9 = (__int64 (__fastcall **)(_QWORD, __int64, __int64, __int64))(8LL * (unsigned __int16)v7 + v8);
  v10 = *v9;
  *(_QWORD *)(v3 + 251) += 8LL;
  return v10(v9, a2, v6, 702);
}


// ===== Dp_H041_3a87f @ 0x28008a87f size=0x33a =====
__int64 __fastcall Dp_H041_3a87f()
{
  __int64 v0; // rbp
  __int64 v1; // rcx
  char *v2; // rcx
  int v3; // edi
  __int64 v4; // r8
  int v5; // r12d
  __int64 (__fastcall *v6)(char *); // r12
  _WORD **v8; // [rsp-8h] [rbp-8h]

  v1 = *(_QWORD *)(v0 + 251);
  *(_DWORD *)(v0 + 105) += 233718888;
  v2 = (char *)(v0 + *(unsigned __int16 *)(v1 + 6));
  v8 = (_WORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  *(_WORD *)v2 = **v8;
  if ( (*(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251)) & 0x400LL) != 0 )
    --*v8;
  else
    ++*v8;
  *(_DWORD *)(v0 + 105) &= 0x13AAFAB0u;
  v3 = *(_DWORD *)(v0 + 335);
  *(_DWORD *)(v0 + 307) ^= 0x13AAFAB0u;
  if ( (v3 & 1) != 0 )
    *(_DWORD *)(v0 + 335) ^= 0x13AAFAB0u;
  v4 = *(_QWORD *)(v0 + 84);
  v5 = (*(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) + 867255658;
  *(_DWORD *)(v0 + 105) -= v5;
  v6 = *(__int64 (__fastcall **)(char *))(8LL * (unsigned __int16)v5 + v4);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v6(v2 - 1);
}


// ===== Dp_H042_3abb9 @ 0x28008abb9 size=0x24e =====
__int64 __fastcall Dp_H042_3abb9(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // rbp
  __int64 v4; // rsi
  unsigned __int64 v5; // r10
  __int64 v6; // r15
  __int64 v7; // rcx
  __int64 v8; // rsi
  __int64 v9; // r9
  __int64 v10; // rcx
  __int64 v11; // r9
  __int64 (__fastcall *v12)(__int64, _QWORD, unsigned __int64, __int64); // rdx
  unsigned __int64 *v14; // [rsp-8h] [rbp-8h]

  if ( (*(_DWORD *)(v3 + 335) & 1) != 0 )
    *(_DWORD *)(v3 + 335) &= 0x2083D2FAu;
  v14 = (unsigned __int64 *)(v3 + **(unsigned __int16 **)(v3 + 251));
  v5 = *v14;
  *(_BYTE *)*v14 = *(_QWORD *)(v3 + *(unsigned __int16 *)(*(_QWORD *)(v3 + 251) + 4LL));
  if ( (*(_QWORD *)(v3 + *(unsigned __int16 *)(*(_QWORD *)(v3 + 251) + 2LL)) & 0x400LL) != 0 )
    --*v14;
  else
    ++*v14;
  *(_DWORD *)(v3 + 105) ^= 0x52715831u;
  *(_DWORD *)(v3 + 285) ^= 0x6C871B74u;
  *(_DWORD *)(v3 + 307) |= 0x52715831u;
  v6 = *(_QWORD *)(v3 + 84);
  v7 = *(_DWORD *)(v3 + 105) ^ (unsigned int)*(unsigned __int16 *)(*(_QWORD *)(v3 + 251) + 6LL);
  v8 = v4 - v5;
  *(_QWORD *)(v3 + 158) ^= v8;
  v9 = v7 & v3 ^ 0x83;
  v10 = (unsigned __int16)(v7 + 12440);
  v11 = v10 + (v6 | ((v6 ^ v9) - 100));
  v10 *= 8;
  v12 = *(__int64 (__fastcall **)(__int64, _QWORD, unsigned __int64, __int64))(v10 + v6);
  *(_QWORD *)(v3 + 251) += 8LL;
  return v12(
           v10,
           v12,
           v5
         ^ (unsigned __int8)v8
         & ((unsigned __int8)((((a3 ^ 0x31) + 15) & 0x88 | 0x64) - 30 - (v3 + 105) + 77 - v3) | 0x80)
         & 0x64,
           v11 - 1024);
}


// ===== Dp_H043_3ae07 @ 0x28008ae07 size=0x2cd =====
__int64 __fastcall Dp_H043_3ae07()
{
  __int64 v0; // rbp
  __int64 v1; // rbx
  unsigned __int64 v2; // kr00_8
  _QWORD *v3; // rbx
  int v4; // r8d
  __int64 v5; // rcx
  __int64 (*v6)(void); // rdx

  *(_DWORD *)(v0 + 105) += 2140895002;
  v1 = **(unsigned __int16 **)(v0 + 251);
  *(_DWORD *)(v0 + 335) += 1720219450;
  **(_BYTE **)(v0 + v1) -= *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL));
  v2 = __readeflags();
  v3 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 3LL)) & 0x400LL) != 0 )
    --*v3;
  else
    ++*v3;
  *(_DWORD *)(v0 + 105) ^= 0x2C9D8E6Eu;
  *(_DWORD *)(v0 + 285) ^= 0x28D3EC82u;
  *(_DWORD *)(v0 + 307) |= 0x2C9D8E6Eu;
  *(_DWORD *)(v0 + 105) -= 1244168528;
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 2LL) != 0 )
    *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 7LL)) = v2;
  v4 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 5LL);
  v5 = *(_QWORD *)(v0 + 84);
  *(_QWORD *)(v0 + 158) -= v0 + 335 + v0 + 105;
  v4 -= 417436277;
  *(_DWORD *)(v0 + 105) ^= v4;
  v6 = *(__int64 (**)(void))(8LL * (unsigned __int16)v4 + v5);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v6();
}


// ===== Dp_H044_3b0d4 @ 0x28008b0d4 size=0x378 =====
__int64 __fastcall Dp_H044_3b0d4()
{
  char v0; // bl
  __int64 v1; // rbp
  __int16 v2; // r13
  unsigned __int8 v3; // r14
  __int64 v4; // r8
  int v5; // eax
  __int64 v6; // r13
  __int64 (__fastcall *v7)(__int64, _QWORD); // rdx
  _DWORD **v9; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v1 + 105) -= 1868144406;
  *(_DWORD *)(v1 + 105) -= 1305809915;
  *(_DWORD *)(v1 + 335) -= 1565035363;
  *(_DWORD *)(v1 + 105) ^= 0x61ECD076u;
  *(_DWORD *)(v1 + 307) |= 0x61ECD076u;
  *(_DWORD *)(v1 + 105) -= 1055720639;
  *(_DWORD *)(v1 + 247) -= 975139793;
  v9 = (_DWORD **)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 6LL));
  **v9 = *(_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 2LL));
  v4 = ((((unsigned __int16)((((v3 | 0xF6) + 115 - v0) & 0x78 ^ v2) + 15) | 4) ^ 0x72) & 0x400) - 249LL;
  if ( (*(_QWORD *)(v1 + **(unsigned __int16 **)(v1 + 251)) & 0x400LL) != 0 )
    --*v9;
  else
    ++*v9;
  v5 = *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 4LL);
  v6 = *(_QWORD *)(v1 + 84);
  *(_QWORD *)(v1 + 158) ^= (unsigned __int64)v9 + (v1 | ((v4 ^ 0x78) + 144));
  v5 ^= 0x7C523AD8u;
  *(_DWORD *)(v1 + 105) |= v5;
  v7 = *(__int64 (__fastcall **)(__int64, _QWORD))(8LL * (unsigned __int16)v5 + v6);
  *(_QWORD *)(v1 + 251) += 8LL;
  return v7((v1 + 158) & 0x14 | 0xC3, v7);
}


// ===== Dp_H045_3b44c @ 0x28008b44c size=0x41ca =====
void __fastcall Dp_H045_3b44c()
{
  __int64 v0; // rbp
  int v1; // esi
  int v2; // esi
  int v3; // edi
  __int64 v4; // rdi
  int v5; // r10d
  int v6; // r10d
  int v7; // r15d
  __int64 v8; // r15
  int v9; // eax
  int v10; // eax
  unsigned __int8 v11; // si
  _DWORD *v12; // rcx
  char v13; // r10
  unsigned __int64 v14; // rbx
  char v15; // r13
  _QWORD *v16; // r13
  unsigned __int64 v17; // rsi
  __int64 v18; // r14
  __int64 v19; // r15
  __int64 v20; // rsi
  __int64 v21; // rcx
  __int64 v22; // rax
  __int64 v23; // rdx
  __int64 v24; // r15
  __int64 v25; // rsi
  unsigned __int64 v26; // r12
  __int64 v27; // rcx
  __int64 v28; // rdx
  __int64 v33; // rdx
  __int64 v34; // rcx
  __int64 v35; // r10
  __int64 v36; // r11
  __int64 v37; // rax
  __int64 v38; // r11
  __int64 v39; // rax
  __int64 v40; // rdx
  __int64 v41; // r13
  __int64 v42; // rcx
  unsigned __int64 v43; // kr140_8
  char v44; // r14
  char v45; // di
  __int64 v46; // r14
  _BYTE *v47; // r13
  __int64 v48; // r14
  int v49; // r10d
  __int64 v50; // r15
  unsigned __int64 v51; // [rsp-148h] [rbp-148h]

  v1 = *(_DWORD *)(v0 + 335) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 19LL) - *(_DWORD *)(v0 + 105);
  *(_DWORD *)(v0 + 105) += v1;
  *(_DWORD *)(v0 + 335) &= 0x5D3335CFu;
  v2 = *(_DWORD *)(v0 + 285) + v1;
  *(_DWORD *)(v0 + 285) ^= 0xE749081u;
  *(_BYTE *)(v0 + 83) = ((unsigned __int8)(v2 & 0xF0) >> 4) ^ 0x80;
  *(_BYTE *)(v0 + 104) = (v2 & 0xF) + 20;
  v3 = *(_DWORD *)(v0 + 105) ^ *(_DWORD *)(*(_QWORD *)(v0 + 251) + 8LL);
  *(_DWORD *)(v0 + 105) = *(_DWORD *)(*(_QWORD *)(v0 + 251) + 8LL);
  *(_DWORD *)(v0 + 335) ^= 0x4D3D5CCFu;
  v4 = (unsigned int)(v3 - *(_DWORD *)(v0 + 285));
  *(_DWORD *)(v0 + 285) ^= 0x61DDDF74u;
  *(_QWORD *)(v0 + 210) = *(_QWORD *)(v0 + 158) ^ v4;
  v5 = *(_DWORD *)(v0 + 335) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 12LL);
  *(_DWORD *)(v0 + 105) |= v5;
  *(_DWORD *)(v0 + 335) -= 98644138;
  v6 = v5 - *(_DWORD *)(v0 + 285);
  *(_DWORD *)(v0 + 285) &= 0x16545DBDu;
  *(_BYTE *)(v0 + 57) = ((unsigned __int8)(v6 & 0xF0) >> 4) - 22;
  *(_BYTE *)(v0 + 218) = (v6 & 0xF) + 76;
  *(_DWORD *)(v0 + 105) &= 0x262DEAB9u;
  v7 = *(_DWORD *)(v0 + 105) + **(_DWORD **)(v0 + 251) - *(_DWORD *)(v0 + 307);
  *(_DWORD *)(v0 + 105) |= v7;
  v8 = (unsigned int)(v7 - *(_DWORD *)(v0 + 285));
  *(_DWORD *)(v0 + 285) |= 0x380B1D07u;
  *(_QWORD *)(v0 + 259) = (v8 ^ 0x29479CBE) - *(_QWORD *)(v0 + 158);
  v9 = *(_DWORD *)(v0 + 335) ^ (*(_DWORD *)(v0 + 105) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 4LL));
  *(_DWORD *)(v0 + 105) &= v9;
  v10 = *(_DWORD *)(v0 + 285) ^ v9;
  *(_DWORD *)(v0 + 285) -= 531933832;
  *(_BYTE *)(v0 + 157) -= v10;
  v11 = *(_BYTE *)(v0 + 83);
  v12 = (_DWORD *)(*(_QWORD *)(v0 + 251) + 15LL);
  if ( *v12 != 0 )
    *(_QWORD *)(v0 + 210) = *(_QWORD *)(v0 + 158)
                          ^ (*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210)
                           | ((unsigned __int64)(*v12 - (unsigned int)*(_QWORD *)(v0 + 105)) << 32));
  if ( (v11 ^ 0x80) == 2 )
  {
    v13 = *(_BYTE *)(v0 + 104) - 20;
    v14 = *(_QWORD *)(v0 + ((unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259)) ^ 0x9CBEu));
    *(_QWORD *)(v0 + 149) = v14 - 1135479014;
    if ( v13 == 1 )
      LOBYTE(v14) = *(_BYTE *)v14;
    if ( v13 == 2 )
      LOWORD(v14) = *(_WORD *)v14;
    if ( v13 == 3 )
      v14 = *(unsigned int *)v14;
    if ( v13 == 4 )
      v14 = *(_QWORD *)v14;
    *(_QWORD *)(v0 + 259) = (v14 ^ 0x29479CBE) - *(_QWORD *)(v0 + 158);
  }
  *(_BYTE *)(v0 + 74) = 0;
  v15 = *(_BYTE *)(v0 + 83) ^ 0x80;
  if ( *(_BYTE *)(v0 + 57) == 0xEB )
    *(_QWORD *)(v0 + 210) = *(_QWORD *)(v0 + 158)
                          ^ *(_QWORD *)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 158) ^ *(_WORD *)(v0 + 210)));
  if ( v15 == 1 )
  {
    v16 = (_QWORD *)(v0 + ((unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259)) ^ 0x9CBEu));
    *(_QWORD *)(v0 + 149) = (char *)v16 - 1135479014;
    *(_QWORD *)(v0 + 259) = (*v16 ^ 0x29479CBELL) - *(_QWORD *)(v0 + 158);
    if ( (unsigned __int8)*(_QWORD *)(v0 + 104) == 23 )
      *(_BYTE *)(v0 + 74) = (v0 + 29) | 3;
  }
  if ( *(_BYTE *)(v0 + 57) == 0xEC )
  {
    v17 = *(_QWORD *)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 158) ^ *(_WORD *)(v0 + 210)));
    if ( *(_BYTE *)(v0 + 218) == 77 )
      LOBYTE(v17) = *(_BYTE *)v17;
    if ( *(_BYTE *)(v0 + 218) == 78 )
      LOWORD(v17) = *(_WORD *)v17;
    if ( *(_BYTE *)(v0 + 218) == 79 )
      v17 = *(unsigned int *)v17;
    if ( *(_BYTE *)(v0 + 218) == 80 )
      v17 = *(_QWORD *)v17;
    *(_QWORD *)(v0 + 210) = *(_QWORD *)(v0 + 158) ^ v17;
  }
  if ( *(_BYTE *)(v0 + 157) == 0x8D )
  {
    v18 = (*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL;
    v19 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210);
    if ( *(_BYTE *)(v0 + 104) == 21 )
    {
      LOBYTE(v18) = __ROL1__(v18, v19);
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 22 )
    {
      LOWORD(v18) = __ROL2__(v18, v19);
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 23 )
    {
      v18 = (unsigned int)__ROL4__(v18, v19);
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 24 )
    {
      v18 = __ROL8__(v18, v19);
      __readeflags();
    }
    *(_QWORD *)(v0 + 327) = v18 - 154283354;
  }
  *(_DWORD *)(v0 + 105) += 625945366;
  *(_DWORD *)(v0 + 335) ^= 0x1995D6D9u;
  if ( *(_BYTE *)(v0 + 157) == 0xB7 )
  {
    v20 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210);
    __readeflags();
    *(_QWORD *)(v0 + 327) = v20 - 154283354;
  }
  *(_DWORD *)(v0 + 307) |= 0x6281EEB1u;
  *(_DWORD *)(v0 + 174) -= *(_DWORD *)(v0 + 105);
  if ( *(_BYTE *)(v0 + 157) == 0xF9 )
  {
    if ( *(_BYTE *)(v0 + 104) == 21 )
      __readeflags();
    if ( *(_BYTE *)(v0 + 104) == 22 )
      __readeflags();
    if ( *(_BYTE *)(v0 + 104) == 23 )
      __readeflags();
    if ( *(_BYTE *)(v0 + 104) == 24 )
      __readeflags();
    *(_QWORD *)(v0 + 327) = ((*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL) - 154283354;
  }
  if ( *(_BYTE *)(v0 + 157) == 0 )
  {
    v21 = (*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL;
    v22 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210);
    if ( *(_BYTE *)(v0 + 218) == 77 )
      v21 = (char)v22;
    if ( *(_BYTE *)(v0 + 218) == 78 )
      v21 = (__int16)v22;
    if ( *(_BYTE *)(v0 + 218) == 79 )
      v21 = (unsigned int)v22;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v21 - 154283354;
  }
  if ( *(_BYTE *)(v0 + 157) == 96 )
  {
    v23 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210) | (*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v23 - 154283354;
  }
  if ( *(_BYTE *)(v0 + 157) == 115 )
  {
    v24 = (*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL;
    v25 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210);
    if ( *(_BYTE *)(v0 + 218) == 77 )
      v24 = (unsigned __int8)v25;
    if ( *(_BYTE *)(v0 + 218) == 78 )
      v24 = (unsigned __int16)v25;
    if ( *(_BYTE *)(v0 + 218) == 79 )
      v24 = (unsigned int)v25;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v24 - 154283354;
  }
  if ( *(_BYTE *)(v0 + 157) == 0xC3 )
  {
    v26 = (*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL;
    v27 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210);
    if ( *(_BYTE *)(v0 + 104) == 21 )
    {
      LOBYTE(v26) = (unsigned __int8)v26 >> v27;
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 22 )
    {
      LOWORD(v26) = (unsigned __int16)v26 >> v27;
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 23 )
    {
      v26 = (unsigned int)v26 >> v27;
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 24 )
    {
      v26 >>= v27;
      __readeflags();
    }
    *(_QWORD *)(v0 + 327) = v26 - 154283354;
  }
  if ( *(_BYTE *)(v0 + 157) == 30 )
  {
    if ( *(_BYTE *)(v0 + 104) == 21 )
      __readeflags();
    if ( *(_BYTE *)(v0 + 104) == 22 )
      __readeflags();
    if ( *(_BYTE *)(v0 + 104) == 23 )
      __readeflags();
    if ( *(_BYTE *)(v0 + 104) == 24 )
      __readeflags();
    *(_QWORD *)(v0 + 327) = ((*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL) - 154283354;
  }
  *(_DWORD *)(v0 + 285) ^= 0x3E65ACD0u;
  if ( *(_BYTE *)(v0 + 157) == 0xF6 )
  {
    v28 = (*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210))
        + ((*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL);
    __readeflags();
    *(_QWORD *)(v0 + 327) = v28 - 154283354;
  }
  if ( *(_BYTE *)(v0 + 157) == 49 )
  {
    _R9 = (*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL;
    _RCX = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210);
    if ( *(_BYTE *)(v0 + 104) == 21 )
    {
      __asm { rcr     r9b, cl }
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 22 )
    {
      __asm { rcr     r9w, cl }
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 23 )
    {
      __asm { rcr     r9d, cl }
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 24 )
    {
      __asm { rcr     r9, cl }
      __readeflags();
    }
    *(_QWORD *)(v0 + 327) = _R9 - 154283354;
  }
  *(_DWORD *)(v0 + 285) ^= 0x199E070Bu;
  if ( *(_BYTE *)(v0 + 157) == 117 )
  {
    _R14 = (*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL;
    _RCX = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210);
    if ( *(_BYTE *)(v0 + 104) == 21 )
    {
      __asm { rcl     r14b, cl }
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 22 )
    {
      __asm { rcl     r14w, cl }
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 23 )
    {
      __asm { rcl     r14d, cl }
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 24 )
    {
      __asm { rcl     r14, cl }
      __readeflags();
    }
    *(_QWORD *)(v0 + 327) = _R14 - 154283354;
  }
  if ( *(_BYTE *)(v0 + 157) == 77 )
  {
    v33 = (*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL;
    v34 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210);
    if ( *(_BYTE *)(v0 + 104) == 21 )
    {
      LOBYTE(v33) = __ROR1__(v33, v34);
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 22 )
    {
      LOWORD(v33) = __ROR2__(v33, v34);
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 23 )
    {
      v33 = (unsigned int)__ROR4__(v33, v34);
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 24 )
    {
      v33 = __ROR8__(v33, v34);
      __readeflags();
    }
    *(_QWORD *)(v0 + 327) = v33 - 154283354;
  }
  *(_DWORD *)(v0 + 285) -= 563074259;
  if ( *(_BYTE *)(v0 + 157) == 0xE2 )
  {
    v35 = (*(_QWORD *)(v0 + 158)
         ^ *(_QWORD *)(v0 + 210))
        & ((*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259))
         ^ 0x29479CBELL);
    __readeflags();
    *(_QWORD *)(v0 + 327) = v35 - 154283354;
  }
  if ( *(_BYTE *)(v0 + 157) == 42 )
  {
    v36 = (*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL;
    v37 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210);
    __readeflags();
    *(_QWORD *)(v0 + 327) = v37 * v36 - 154283354;
  }
  if ( *(_BYTE *)(v0 + 157) == 100 )
  {
    v38 = (*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL;
    v39 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210);
    __readeflags();
    *(_QWORD *)(v0 + 327) = (v39 ^ v38) - 154283354;
  }
  if ( *(_BYTE *)(v0 + 157) == 0xD3 )
  {
    v40 = ((*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL)
        - (*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210));
    __readeflags();
    *(_QWORD *)(v0 + 327) = v40 - 154283354;
  }
  if ( *(_BYTE *)(v0 + 157) == 0x83 )
  {
    v41 = (*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x29479CBELL;
    v42 = *(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 210);
    if ( *(_BYTE *)(v0 + 104) == 21 )
    {
      LOBYTE(v41) = (_BYTE)v41 << v42;
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 22 )
    {
      LOWORD(v41) = (_WORD)v41 << v42;
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 23 )
    {
      v41 = (unsigned int)((_DWORD)v41 << v42);
      __readeflags();
    }
    if ( *(_BYTE *)(v0 + 104) == 24 )
    {
      v41 <<= v42;
      v43 = __readeflags();
      v51 = v43;
    }
    *(_QWORD *)(v0 + 327) = v41 - 154283354;
  }
  v44 = *(_BYTE *)(v0 + 157);
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 7LL) != 0 )
    *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 5LL)) = v51;
  if ( v44 != -7 && *(_BYTE *)(v0 + 157) != 30 )
  {
    v45 = *(_BYTE *)(v0 + 104) - 20;
    v46 = *(_QWORD *)(v0 + 327) + 154283354LL;
    v47 = (_BYTE *)(*(_QWORD *)(v0 + 149) + 1135479014LL);
    if ( *(_BYTE *)(v0 + 104) == 21 )
      *v47 = v46;
    if ( v45 == 2 )
      *(_WORD *)v47 = v46;
    if ( v45 == 3 )
    {
      *(_DWORD *)v47 = v46;
      LOBYTE(v46) = *(_BYTE *)(v0 + 74);
      if ( (_BYTE)v46 != 0 )
      {
        v47 += 4;
        *(_DWORD *)v47 = 0;
      }
    }
    if ( v45 == 4 )
      *(_QWORD *)v47 = v46;
  }
  *(_DWORD *)(v0 + 247) |= 0x65C695ADu;
  *(_DWORD *)(v0 + 105) |= 0x2220E5ADu;
  v48 = *(_QWORD *)(v0 + 84);
  v49 = *(_DWORD *)(v0 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 13LL);
  *(_QWORD *)(v0 + 158) += v0 + 307;
  *(_DWORD *)(v0 + 105) &= v49;
  v50 = *(_QWORD *)(8LL * (unsigned __int16)v49 + v48);
  *(_QWORD *)(v0 + 251) += 20LL;
  __asm { jmp     r15 }
}


// ===== Dp_H046_3f616 @ 0x28008f616 size=0xac =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H046_3f616()
{
  __int64 v0; // rbp
  _QWORD *v1; // rsi
  _QWORD *v2; // rdi
  int v3; // ecx
  __int64 result; // rax
  __int64 v5; // [rsp-90h] [rbp-90h]
  __int64 v6; // [rsp-18h] [rbp-18h]
  unsigned __int64 v7; // [rsp-10h] [rbp-10h]
  _UNKNOWN *retaddr; // [rsp+0h] [rbp+0h] BYREF

  v5 = **(unsigned int **)(v0 + 251);
  v1 = &retaddr;
  v2 = (_UNKNOWN **)((char *)&retaddr + v5);
  v3 = **(_DWORD **)(v0 + 251);
  if ( (_DWORD)v5 != 0 )
    v3 = 18;
  while ( v3 != 0 )
  {
    *v2++ = *v1++;
    --v3;
  }
  *(_DWORD *)(v0 + 231) = 0;
  result = v6;
  __writeeflags(v7);
  __writeeflags(v7);
  return result;
}


// ===== Dp_H047_3f6c2 @ 0x28008f6c2 size=0xed6 =====
__int64 __fastcall Dp_H047_3f6c2()
{
  __int64 v0; // rbp
  int v1; // r15d
  char v2; // r12
  char v3; // r10
  char v4; // r10
  int v5; // r10d
  int v6; // r10d
  int v7; // r10d
  int v8; // r10d
  unsigned __int16 *v9; // r14
  __int64 (__fastcall *v10)(_QWORD *, __int64, __int64, __int64); // rdi
  __int64 v11; // r10
  __int64 v12; // rdx
  __int64 v13; // r9
  _QWORD *v14; // rcx
  __int64 v15; // r9
  __int64 v16; // r8
  __int64 v18; // r12
  int v19; // r9d
  __int64 (__fastcall *v20)(__int64); // rdi
  int v21; // [rsp-8h] [rbp-8h]

  *(_BYTE *)(v0 + 56) = 0;
  v1 = *(_DWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 8LL));
  v2 = *(_BYTE *)(*(_QWORD *)(v0 + 251) + 10LL);
  if ( v2 == 64 || v2 == -38 )
  {
    v21 = *(_DWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 8LL));
    if ( (v1 & 0x40) != 0 )
      *(_BYTE *)(v0 + 56) = 1;
    LOWORD(v1) = v21;
  }
  if ( v2 == 38 )
  {
    v1 &= 0x40u;
    if ( v1 == 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == 105 )
  {
    v3 = v1;
    v1 &= 0x40u;
    if ( v1 == 0 && (v3 & 1) == 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == 113 )
  {
    v1 &= 1u;
    if ( v1 == 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == 3 )
  {
    v1 &= 1u;
    if ( v1 != 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == 40 )
  {
    v4 = v1;
    v1 &= 0x40u;
    if ( v1 != 0 )
      *(_BYTE *)(v0 + 56) = 1;
    if ( (v4 & 1) != 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == -93 && (v1 & 0x40) == 0 )
  {
    v5 = (v1 & 0x800) != 0;
    v1 = (v1 & 0x80) != 0;
    if ( v1 == v5 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == -120 )
  {
    v6 = (v1 & 0x800) != 0;
    v1 = (v1 & 0x80) != 0;
    if ( v1 == v6 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == 78 )
  {
    v7 = (v1 & 0x800) != 0;
    v1 = (v1 & 0x80) != 0;
    if ( v1 != v7 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == -38 )
  {
    if ( (v1 & 0x40) != 0 )
      *(_BYTE *)(v0 + 56) = 1;
    v8 = (v1 & 0x800) != 0;
    v1 = (v1 & 0x80) != 0;
    if ( v1 != v8 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == -127 )
  {
    v1 &= 0x800u;
    if ( v1 == 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == -76 )
  {
    v1 &= 4u;
    if ( v1 == 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == -122 )
  {
    v1 &= 0x80u;
    if ( v1 == 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == 118 )
  {
    v1 &= 0x800u;
    if ( v1 != 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == -27 )
  {
    v1 &= 4u;
    if ( v1 != 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v2 == -113 && (v1 & 0x80) != 0 )
    *(_BYTE *)(v0 + 56) = 1;
  v9 = *(unsigned __int16 **)(v0 + 251);
  v14 = (_QWORD *)(8LL * *v9 + *(_QWORD *)(v0 + 84));
  v10 = (__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64))*v14;
  v11 = *((unsigned int *)v9 + 1);
  v12 = (unsigned int)v11 & 0x80000000;
  v13 = *v14 | (unsigned __int64)(v9 + 454);
  LOBYTE(v14) = *(_BYTE *)(v0 + 56);
  if ( (_BYTE)v14 != 0 )
  {
    if ( (_DWORD)v12 != 0 )
    {
      v15 = v13 - (_QWORD)v10 - 77;
      v16 = v0 + 251;
      *(_QWORD *)(v0 + 251) -= v11 & 0x7FFFFFFF;
    }
    else
    {
      v16 = v0 + 251;
      v15 = 64;
      *(_QWORD *)(v0 + 251) += v11;
    }
    return v10(v14, v12, v16, v15);
  }
  else
  {
    v18 = *(_QWORD *)(v0 + 84);
    v19 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 11LL);
    *(_QWORD *)(v0 + 158) -= v9;
    v19 += 680238896;
    *(_DWORD *)(v0 + 105) &= v19;
    v20 = *(__int64 (__fastcall **)(__int64))(8LL * (unsigned __int16)v19 + v18);
    *(_QWORD *)(v0 + 251) += 13LL;
    return v20(1024);
  }
}


// ===== Dp_H048_40598 @ 0x280090598 size=0x12f =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H048_40598()
{
  __int64 v0; // rbp
  _QWORD *v1; // r14
  char v2; // di
  __int64 v3; // rdx
  _QWORD *v4; // rdx
  __int64 result; // rax
  _BYTE v6[128]; // [rsp-80h] [rbp-80h] BYREF

  v2 = *(_BYTE *)(*(_QWORD *)(v0 + 251) + 10LL);
  v3 = 0;
  if ( v2 == -33 )
  {
    v3 = *(_QWORD *)(v0 + 239) + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 6LL);
    v1 = &v6[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)];
    *v1 = v3;
  }
  if ( v2 == 111 || v2 == 82 )
  {
    LOWORD(v3) = *(_WORD *)(*(_QWORD *)(v0 + 251) + 6LL);
    v4 = *(_QWORD **)(v0 + v3);
    if ( v2 == 82 )
      v4 = (_QWORD *)*v4;
    v1 = &v6[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)];
    *v1 = v4;
  }
  v1[1] = *(_QWORD *)(v0 + 239) + **(unsigned int **)(v0 + 251);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v6[112];
  __writeeflags(*(unsigned __int64 *)&v6[120]);
  return result;
}


// ===== Dp_H049_406c7 @ 0x2800906c7 size=0x3a9 =====
__int64 __fastcall Dp_H049_406c7()
{
  __int64 v0; // rbp
  _WORD *v1; // r10
  unsigned __int64 v2; // kr00_8
  _QWORD *v3; // r10
  char v4; // r12
  unsigned __int16 *v5; // rsi
  char v6; // r9
  __int64 v7; // r10
  int v8; // r11d
  __int64 (__fastcall *v9)(__int64, _QWORD, __int64, __int64); // rdx

  *(_DWORD *)(v0 + 247) |= 0x6364FB9u;
  *(_DWORD *)(v0 + 105) |= 0x220B57B1u;
  *(_DWORD *)(v0 + 307) &= 0x220B57B1u;
  v1 = *(_WORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 5LL));
  *v1 -= *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  v2 = __readeflags();
  v3 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 5LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 7LL)) & 0x400LL) != 0 )
    *v3 -= 2LL;
  else
    *v3 += 2LL;
  v4 = v0 + 79;
  LODWORD(v5) = *(_DWORD *)(v0 + 335) & 1;
  if ( (_DWORD)v5 != 0 )
    v4 = v0 + 79;
  v6 = 0;
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 2LL) != 0 )
  {
    v5 = (unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 3LL);
    v6 = 1;
    *(_QWORD *)(v0 + *v5) = v2;
  }
  v7 = *(_QWORD *)(v0 + 84);
  v8 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) += v2 ^ 0xFFFFFFFF80000008uLL;
  v8 -= 486200145;
  *(_DWORD *)(v0 + 105) &= v8;
  v9 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, __int64))(8LL * (unsigned __int16)v8 + v7);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v9(
           -2147483640,
           v9,
           ((2 * (((((unsigned __int8)((_BYTE)v5 + v0 + 105 - 115) ^ 0xD3) - 86) & 0x93) + 96 - (_BYTE)v8)) & 0x60)
         + 52LL,
           (((((unsigned __int8)(((((v4 ^ v6 | 0x93) + 92) | 0xC3) ^ 1) + 45) | 0x34) - 100 + 1) & 0x56 ^ 0x64) & 0x34)
         + 0x80000000LL);
}


// ===== Dp_H050_40a70 @ 0x280090a70 size=0x95 =====
__int64 __fastcall Dp_H050_40a70()
{
  __int64 v0; // rbp
  __int64 v1; // rdx
  int v2; // esi
  __int64 (*v3)(void); // rdi

  v1 = *(_QWORD *)(v0 + 84);
  v2 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) += *(_QWORD *)(v0 + 251);
  v2 += 1652475378;
  *(_DWORD *)(v0 + 105) -= v2;
  v3 = *(__int64 (**)(void))(8LL * (unsigned __int16)v2 + v1);
  *(_QWORD *)(v0 + 251) += 4LL;
  return v3();
}


// ===== Dp_H051_40b05 @ 0x280090b05 size=0x285 =====
__int64 __fastcall Dp_H051_40b05()
{
  __int64 v0; // rbp
  char v1; // r13
  __int64 v2; // r9
  _DWORD *v3; // r8
  _QWORD *v4; // rdi
  _QWORD *v5; // r15
  __int64 v6; // r12
  int v7; // esi
  __int64 (__fastcall *v8)(__int64, _QWORD, _DWORD *, __int64); // r10

  *(_DWORD *)(v0 + 105) += 189805839;
  *(_DWORD *)(v0 + 247) += 1538119020;
  *(_DWORD *)(v0 + 335) &= 0x2C9439AFu;
  v2 = *(_QWORD *)(v0 + 251);
  *(_DWORD *)(v0 + 285) ^= 0x1EB70E35u;
  v3 = *(_DWORD **)(v0 + **(unsigned __int16 **)(v0 + 251));
  **(_DWORD **)(v0 + *(unsigned __int16 *)(v2 + 4)) = *v3;
  v4 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
  v5 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL)) & 0x400LL) != 0 )
  {
    *v4 -= 4LL;
    *v5 -= 4LL;
  }
  else
  {
    *v4 += 4LL;
    *v5 += 4LL;
  }
  v6 = *(_QWORD *)(v0 + 84);
  v7 = *(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL);
  *(_QWORD *)(v0 + 158) ^= (((unsigned __int8)v4 | 0x28) - v1) & 0x56 ^ 0xF9LL;
  v7 ^= 0x1F2B2662u;
  *(_DWORD *)(v0 + 105) += v7;
  v8 = *(__int64 (__fastcall **)(__int64, _QWORD, _DWORD *, __int64))(8LL * (unsigned __int16)v7 + v6);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v8(
           v0 + 105,
           ((_DWORD)v0 + 105) & (((((_DWORD)v0 - 36 + 0x80000000) | 0x7FFFFFFF) - 186) | 0x75) & 0x7FFFFFFF,
           v3,
           512);
}


// ===== Dp_H052_40d8a @ 0x280090d8a size=0x79 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H052_40d8a()
{
  __int64 v0; // rbp
  __int64 result; // rax
  _BYTE v2[128]; // [rsp-80h] [rbp-80h]

  *(_QWORD *)&v2[**(unsigned __int16 **)(v0 + 251)] = **(_QWORD **)(v0
                                                                  + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v2[112];
  __writeeflags(*(unsigned __int64 *)&v2[120]);
  return result;
}


// ===== Dp_H053_40e03 @ 0x280090e03 size=0x1317 =====
// positive sp value has been detected, the output may be wrong!
void __fastcall Dp_H053_40e03()
{
  __int64 v0; // rbp
  int v1; // r15d
  int v2; // r15d
  int v3; // r14d
  _DWORD *v4; // rsi
  int v5; // r15d
  __int64 v6; // r15
  unsigned __int64 v7; // r11
  char v8; // al
  unsigned __int64 v9; // rsi
  char v10; // r10
  _WORD *v11; // rsi
  unsigned __int16 *v12; // r11
  _QWORD *v13; // r11
  __int64 v14; // r15
  _BYTE v15[14]; // [rsp-Eh] [rbp-Eh]

  v1 = *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 9LL);
  *(_DWORD *)(v0 + 105) += v1;
  *(_DWORD *)(v0 + 335) |= 0x63B9047Au;
  v2 = v1 - *(_DWORD *)(v0 + 285);
  *(_DWORD *)(v0 + 285) ^= 0x6E6FD57Fu;
  *(_BYTE *)(v0 + 83) = ((unsigned __int8)(v2 & 0xF0) >> 4) - 64;
  *(_BYTE *)(v0 + 104) = (v2 & 0xF) + 84;
  v3 = *(_DWORD *)(v0 + 105) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 2LL) - *(_DWORD *)(v0 + 335);
  *(_DWORD *)(v0 + 105) += v3;
  *(_BYTE *)(v0 + 157) ^= v3;
  *(_DWORD *)(v0 + 247) &= 0x66DC7814u;
  v4 = (_DWORD *)(*(_QWORD *)(v0 + 251) + 5LL);
  *(_DWORD *)(v0 + 247) ^= 0x51F86161u;
  v5 = *(_DWORD *)(v0 + 307) + *(_DWORD *)(v0 + 105) + *v4;
  *(_DWORD *)(v0 + 105) += v5;
  *(_DWORD *)(v0 + 335) ^= 0x3F465051u;
  v6 = (unsigned int)(*(_DWORD *)(v0 + 285) + v5);
  *(_DWORD *)(v0 + 285) |= 0x3EB9D264u;
  *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) ^ (v6 - 1061910074);
  *(_BYTE *)(v0 + 74) = 0;
  if ( *(_BYTE *)(v0 + 83) == 0xC1 )
  {
    v7 = v0 + (unsigned __int16)((*(_WORD *)(v0 + 158) ^ *(_WORD *)(v0 + 259)) + 30266);
    *(_QWORD *)(v0 + 149) = v7 ^ 0x3888416B;
    *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) ^ (*(_QWORD *)v7 - 1061910074LL);
    if ( (unsigned __int8)*(_QWORD *)(v0 + 104) == 87 )
      *(_BYTE *)(v0 + 74) = (v0 + 74) | 3;
  }
  if ( *(_BYTE *)(v0 + 83) == 0xC2 )
  {
    v8 = *(_BYTE *)(v0 + 104) - 84;
    v9 = *(_QWORD *)(v0 + (unsigned __int16)((*(_WORD *)(v0 + 158) ^ *(_WORD *)(v0 + 259)) + 30266));
    *(_QWORD *)(v0 + 149) = v9 ^ 0x3888416B;
    if ( v8 == 1 )
      LOBYTE(v9) = *(_BYTE *)v9;
    if ( v8 == 2 )
      LOWORD(v9) = *(_WORD *)v9;
    if ( v8 == 3 )
      v9 = *(unsigned int *)v9;
    if ( v8 == 4 )
      v9 = *(_QWORD *)v9;
    *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) ^ (v9 - 1061910074);
  }
  v10 = (*(_BYTE *)(v0 + 104) - 84) & 0xF;
  if ( *(_BYTE *)(v0 + 157) == 6 )
  {
    if ( v10 == 2 )
      *(_WORD *)&v15[6] = (*(_WORD *)(v0 + 158) ^ *(_WORD *)(v0 + 259)) + 30266;
    else
      *(_QWORD *)v15 = (*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259)) + 1061910074LL;
  }
  if ( *(_BYTE *)(v0 + 157) == 86 )
  {
    v11 = (_WORD *)(*(_QWORD *)(v0 + 149) ^ 0x3888416BLL);
    if ( v10 == 2 )
      *v11 = *(_WORD *)&v15[6];
    else
      *(_QWORD *)v11 = *(_QWORD *)&v15[6];
  }
  v12 = *(unsigned __int16 **)(v0 + 251);
  *(_DWORD *)(v0 + 105) ^= 0x158B6CEFu;
  v13 = (_QWORD *)(v0 + *v12);
  if ( *(_BYTE *)(v0 + 157) == 6 )
  {
    if ( ((*(_BYTE *)(v0 + 104) - 84) & 0xF) == 2 )
      *v13 -= 2LL;
    else
      *v13 -= 8LL;
  }
  if ( *(_BYTE *)(v0 + 157) == 86 && (_QWORD *)(*(_QWORD *)(v0 + 149) ^ 0x3888416BLL) != v13 )
    *v13 += 8LL;
  v14 = *(_QWORD *)(8LL * (unsigned __int16)(*(_WORD *)(*(_QWORD *)(v0 + 251) + 3LL) - *(_WORD *)(v0 + 105) + 460)
                  + *(_QWORD *)(v0 + 84));
  *(_QWORD *)(v0 + 251) += 10LL;
  __asm { jmp     r15 }
}


// ===== Dp_H054_4211a @ 0x28009211a size=0x363 =====
__int64 __fastcall Dp_H054_4211a()
{
  __int64 v0; // rbx
  __int64 v1; // rbp
  _QWORD *v2; // rdi
  _QWORD *v3; // rax
  __int64 v4; // rdx
  int v5; // r8d
  __int64 (*v6)(void); // r11

  **(_DWORD **)(v1 + **(unsigned __int16 **)(v1 + 251)) = **(_DWORD **)(v1
                                                                      + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 2LL));
  v2 = (_QWORD *)(v1 + **(unsigned __int16 **)(v1 + 251));
  v3 = (_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 2LL));
  if ( (*(_DWORD *)(v1 + 28) & 0x400LL | *(_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 6LL)) & 0x400LL) != 0 )
  {
    *v2 -= 4LL;
    *v3 -= 4LL;
  }
  else
  {
    *v2 += 4LL;
    *v3 += 4LL;
  }
  *(_DWORD *)(v1 + 105) |= 0xB19030Au;
  v4 = *(_QWORD *)(v1 + 84);
  v5 = *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 4LL);
  *(_QWORD *)(v1 + 158) ^= v1 + 28 - v0;
  v5 -= 581237471;
  *(_DWORD *)(v1 + 105) += v5;
  v6 = *(__int64 (**)(void))(8LL * (unsigned __int16)v5 + v4);
  *(_QWORD *)(v1 + 251) += 8LL;
  return v6();
}


// ===== Dp_H055_4247d @ 0x28009247d size=0x2fc =====
__int64 __fastcall Dp_H055_4247d()
{
  __int64 v0; // rbp
  unsigned __int16 *v1; // rdi
  __int64 v2; // r15
  _QWORD *v3; // r13
  _QWORD *v4; // rdx
  int v5; // esi
  __int64 v6; // r9
  __int64 (__fastcall *v7)(__int64); // r15

  v1 = *(unsigned __int16 **)(v0 + 251);
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) |= 0x414825DAu;
  **(_WORD **)(v0 + *v1) = **(_WORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  v2 = *(_DWORD *)(v0 + 28) & 0x400LL;
  v3 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  v4 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  if ( (v2 | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) & 0x400LL) != 0 )
  {
    *v3 -= 2LL;
    *v4 -= 2LL;
  }
  else
  {
    *v3 += 2LL;
    *v4 += 2LL;
  }
  *(_DWORD *)(v0 + 285) -= 747481060;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) ^= 0x36922DDCu;
  v5 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL);
  v6 = *(_QWORD *)(v0 + 84);
  *(_QWORD *)(v0 + 158) -= (v0 + 285) ^ v2;
  v5 ^= 0x2C8A4AAAu;
  *(_DWORD *)(v0 + 105) += v5;
  v7 = *(__int64 (__fastcall **)(__int64))(8LL * (unsigned __int16)v5 + v6);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v7(65876);
}


// ===== Dp_H056_42779 @ 0x280092779 size=0x274 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H056_42779()
{
  __int64 v0; // rax
  __int64 v1; // rbp
  __int64 v2; // r10
  int v3; // edx
  __int64 v4; // rcx
  _QWORD *v5; // r13
  int v6; // edi
  __int64 v7; // r15
  __int64 v8; // r15
  __int64 (__fastcall *v9)(__int64, __int64, __int64); // r13
  __int64 v11; // [rsp-8h] [rbp-8h]

  v3 = *(_DWORD *)(v1 + 335) & 1;
  *(_DWORD *)(v1 + 285) ^= 0x690F376u;
  if ( v3 != 0 )
    *(_DWORD *)(v1 + 335) ^= 0x37E74577u;
  *(_DWORD *)(v1 + 105) |= 0x17659F3Bu;
  v4 = *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 2LL);
  v5 = (_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 4LL));
  *(_QWORD *)(v1 + v4) += 8LL;
  *v5 = v11;
  *(_DWORD *)(v1 + 307) |= 0x43830CA9u;
  v6 = **(unsigned __int16 **)(v1 + 251);
  v7 = *(_QWORD *)(v1 + 84);
  *(_QWORD *)(v1 + 158) += (v0 ^ v2) - 1 + 1024 - v4;
  v6 -= 1738996738;
  *(_DWORD *)(v1 + 105) &= v6;
  v8 = 8LL * (unsigned __int16)v6 + v7;
  v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64))v8;
  *(_QWORD *)(v1 + 251) += 6LL;
  return v9(v1 + 251, 1132661929, -v8);
}


// ===== Dp_H058_46bf6 @ 0x280096bf6 size=0x36e =====
__int64 __fastcall Dp_H058_46bf6(__int64 a1)
{
  __int64 v1; // rbp
  unsigned __int64 v2; // kr00_8
  __int64 v3; // r12
  _QWORD *v4; // r15
  _QWORD *v5; // r11
  __int64 v6; // r9
  int v7; // r15d
  __int64 (__fastcall *v8)(__int64, __int64); // r14

  *(_DWORD *)(v1 + 105) ^= 0x45623426u;
  *(_DWORD *)(v1 + 307) -= 1164063782;
  *(_DWORD *)(v1 + 105) += 1585038054;
  *(_DWORD *)(v1 + 335) &= 0xE7C3F4Fu;
  *(_DWORD *)(v1 + 285) |= 0x57EF85DFu;
  v2 = __readeflags();
  v3 = *(_DWORD *)(v1 + 28) & 0x400LL;
  v4 = (_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 3LL));
  v5 = (_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 5LL));
  if ( (v3 | *(_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 7LL)) & 0x400LL) != 0 )
  {
    --*v5;
    --*v4;
  }
  else
  {
    ++*v5;
    ++*v4;
  }
  if ( **(_BYTE **)(v1 + 251) != 0 )
    *(_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 1LL)) = v2;
  v6 = *(_QWORD *)(v1 + 84);
  v7 = *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 9LL);
  *(_QWORD *)(v1 + 158) ^= a1 ^ ((v3 + 272) | 0x60) ^ 0x60;
  v7 += 1598247275;
  *(_DWORD *)(v1 + 105) &= v7;
  v8 = *(__int64 (__fastcall **)(__int64, __int64))(8LL * (unsigned __int16)v7 + v6);
  *(_QWORD *)(v1 + 251) += 11LL;
  return v8(a1, v1 + 105);
}


// ===== Dp_H059_46f64 @ 0x280096f64 size=0x78 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H059_46f64()
{
  __int64 v0; // rbp
  __int64 result; // rax
  _BYTE v2[128]; // [rsp-80h] [rbp-80h]

  *(_QWORD *)&v2[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)] = *(_QWORD *)(v0 + 239)
                                                                     + **(unsigned int **)(v0 + 251);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v2[112];
  __writeeflags(*(unsigned __int64 *)&v2[120]);
  return result;
}


// ===== Dp_H060_46fdc @ 0x280096fdc size=0xb0 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H060_46fdc()
{
  __int64 v0; // rbp
  _QWORD *v1; // rsi
  _QWORD *v2; // rdi
  int v3; // ecx
  __int64 result; // rax
  __int64 v5; // [rsp-90h] [rbp-90h]
  __int64 v6; // [rsp-18h] [rbp-18h]
  unsigned __int64 v7; // [rsp-10h] [rbp-10h]
  _UNKNOWN *retaddr; // [rsp+0h] [rbp+0h] BYREF

  v5 = **(unsigned int **)(v0 + 251);
  v1 = &retaddr;
  v2 = (_UNKNOWN **)((char *)&retaddr + v5);
  v3 = **(_DWORD **)(v0 + 251);
  if ( (_DWORD)v5 != 0 )
    v3 = 18;
  while ( v3 != 0 )
  {
    *v2++ = *v1++;
    --v3;
  }
  *(_DWORD *)(v0 + 231) = 0;
  result = v6;
  __writeeflags(v7);
  __writeeflags(v7);
  return result;
}


// ===== Dp_H061_4708c @ 0x28009708c size=0xfa3 =====
__int64 __fastcall Dp_H061_4708c()
{
  __int64 v0; // rbp
  int v1; // r14d
  char *v2; // r13
  char v3; // r12
  char v4; // si
  char v5; // si
  int v6; // esi
  int v7; // esi
  int v8; // esi
  int v9; // esi
  char v10; // r9
  __int64 (__fastcall **v11)(__int64, _QWORD, __int64, __int64); // rsi
  char v12; // di
  __int64 (__fastcall *v13)(__int64, _QWORD, __int64, __int64); // rdx
  __int64 v14; // r14
  __int64 v15; // r9
  __int64 v16; // rdi
  __int64 v17; // r9
  __int64 v19; // rdx
  int v20; // r8d
  __int64 (__fastcall *v21)(__int64); // r15
  int v22; // [rsp-8h] [rbp-8h]

  *(_BYTE *)(v0 + 56) = 0;
  v1 = *(_DWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 8LL));
  v2 = (char *)(*(_QWORD *)(v0 + 251) + 10LL);
  v3 = *v2;
  if ( *v2 == 64 || v3 == -38 )
  {
    v22 = *(_DWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 8LL));
    if ( (v1 & 0x40) != 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
    LOWORD(v1) = v22;
  }
  if ( v3 == 38 )
  {
    v1 &= 0x40u;
    if ( v1 == 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == 105 )
  {
    v4 = v1;
    v1 &= 0x40u;
    if ( v1 == 0 && (v4 & 1) == 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == 113 )
  {
    v1 &= 1u;
    if ( v1 == 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == 3 )
  {
    v1 &= 1u;
    if ( v1 != 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == 40 )
  {
    v5 = v1;
    v1 &= 0x40u;
    if ( v1 != 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
    if ( (v5 & 1) != 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == -93 && (v1 & 0x40) == 0 )
  {
    v6 = (v1 & 0x800) != 0;
    v1 = (v1 & 0x80) != 0;
    if ( v1 == v6 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == -120 )
  {
    v7 = (v1 & 0x800) != 0;
    v1 = (v1 & 0x80) != 0;
    if ( v1 == v7 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == 78 )
  {
    v8 = (v1 & 0x800) != 0;
    v1 = (v1 & 0x80) != 0;
    if ( v1 != v8 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == -38 )
  {
    if ( (v1 & 0x40) != 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
    v9 = (v1 & 0x800) != 0;
    v1 = (v1 & 0x80) != 0;
    if ( v1 != v9 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == -127 )
  {
    v1 &= 0x800u;
    if ( v1 == 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == -76 )
  {
    v1 &= 4u;
    if ( v1 == 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == -122 )
  {
    v1 &= 0x80u;
    if ( v1 == 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == 118 )
  {
    v1 &= 0x800u;
    if ( v1 != 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == -27 )
  {
    v1 &= 4u;
    if ( v1 != 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  if ( v3 == -113 )
  {
    v1 &= 0x80u;
    if ( v1 != 0 )
    {
      LOBYTE(v2) = v0 + 56;
      *(_BYTE *)(v0 + 56) = 1;
    }
  }
  v10 = ((_BYTE)v2 + ((((((v1 & 0xAC) - 120) & 0x60) - 4) | 0x40) ^ 0xF6)) | 0xF2;
  v11 = (__int64 (__fastcall **)(__int64, _QWORD, __int64, __int64))(8LL * **(unsigned __int16 **)(v0 + 251)
                                                                   + *(_QWORD *)(v0 + 84));
  v12 = v1 ^ 0x31;
  v13 = *v11;
  v14 = *(unsigned int *)(*(_QWORD *)(v0 + 251) + 4LL);
  v15 = (v14 & (((unsigned __int8)((v10 ^ 0xF2) - 45) & 0xAC) - 2048LL)) - 30;
  v16 = ((((unsigned __int8)v11 ^ (unsigned __int8)((unsigned __int8)*v11 + ((v12 + 118) & 0x90)) ^ 0x75) & 0x28) + 120LL)
      ^ 0x28;
  if ( *(_BYTE *)(v0 + 56) != 0 )
  {
    if ( (v14 & 0x80000000) != 0 )
    {
      v17 = (v15 - (v16 ^ 0x80)) ^ 0x86;
      *(_QWORD *)(v0 + 251) -= v14 & 0x7FFFFFFF;
    }
    else
    {
      v17 = ((unsigned __int8)v15 & 0xF9) - 1LL;
      *(_QWORD *)(v0 + 251) += v14;
    }
    return v13(1, v13, 366, v17);
  }
  else
  {
    v19 = *(_QWORD *)(v0 + 84);
    v20 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 11LL) - *(_DWORD *)(v0 + 105) + 1457795070;
    *(_DWORD *)(v0 + 105) += v20;
    v21 = *(__int64 (__fastcall **)(__int64))(8LL * (unsigned __int16)v20 + v19);
    *(_QWORD *)(v0 + 251) += 13LL;
    return v21(v0 + 158);
  }
}


// ===== Dp_H064_4c933 @ 0x28009c933 size=0x2c9 =====
void __fastcall Dp_H064_4c933()
{
  __int64 v0; // rbp
  __int64 v1; // r13
  _QWORD *v2; // rcx
  __int64 v3; // rdx
  int v4; // r12d
  __int64 v5; // r13

  *(_DWORD *)(v0 + 285) ^= 0x2406917Fu;
  *(_DWORD *)(v0 + 105) ^= 0x87D8147u;
  *(_DWORD *)(v0 + 105) |= 0x1ACB0851u;
  v2 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  *v2 -= 8LL;
  *(_DWORD *)(v0 + 285) -= 1483055250;
  v3 = *(_QWORD *)(v0 + 84);
  v4 = *(_DWORD *)(v0 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL);
  *(_QWORD *)(v0 + 158) += v1 ^ (unsigned int)((_DWORD)v2 - 377245039);
  v4 ^= 0x743CDA5Fu;
  *(_DWORD *)(v0 + 105) &= v4;
  v5 = *(_QWORD *)(8LL * (unsigned __int16)v4 + v3);
  *(_QWORD *)(v0 + 251) += 6LL;
  __asm { jmp     r13 }
}


// ===== Dp_H065_4cbfc @ 0x28009cbfc size=0x75 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H065_4cbfc()
{
  __int64 v0; // rbp
  __int64 result; // rax
  _BYTE v2[128]; // [rsp-80h] [rbp-80h]

  *(_QWORD *)&v2[**(unsigned __int16 **)(v0 + 251)] = *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v2[112];
  __writeeflags(*(unsigned __int64 *)&v2[120]);
  return result;
}


// ===== Dp_H066_4cc71 @ 0x28009cc71 size=0xddc =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H066_4cc71(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  char v4; // bl
  __int64 v5; // rbp
  char v6; // di
  __int64 v7; // r10
  __int64 v8; // r14
  __int64 v9; // rcx
  __int64 v10; // r11
  __int64 v11; // r15
  __int64 v12; // r14
  __int64 v13; // rdx
  __int64 v14; // rbx
  __int64 v15; // rcx
  __int64 v16; // r11
  __int64 v17; // rcx
  unsigned int v18; // r15d
  __int64 v19; // r11
  __int64 v20; // r9
  __int64 v21; // rcx
  __int64 v22; // rcx
  __int64 v23; // r11
  __int64 v24; // rbx
  __int64 v25; // rcx
  __int64 v26; // rcx
  __int64 result; // rax
  __int64 v28; // r8
  int v29; // r15d
  __int64 v30; // r8
  __int64 (__fastcall *v31)(_QWORD, __int64, __int64, __int64); // rcx
  __int64 v32; // [rsp-90h] [rbp-90h]
  _BYTE v33[136]; // [rsp-88h] [rbp-88h]

  *(_BYTE *)(v5 + 56) = 0;
  v8 = *(_QWORD *)(v5 + 251) + 6LL;
  v9 = (((_BYTE)v5 + 6) & 0x78) - v8 + 40;
  v10 = v8 & 0x400;
  v11 = *(unsigned int *)(v5 + *(unsigned __int16 *)v8);
  v12 = 1;
  v13 = *(_QWORD *)(v5 + 251) + 8LL;
  v14 = (v10 | ((((unsigned __int8)v7 & (unsigned __int8)((v6 ^ v4 ^ 0x80) + 60) & 0xF ^ 0x33) & 0x13) + 120LL)) ^ 0x31;
  v15 = ((v9 | 0x93) - 115) ^ 6;
  v16 = (v10 - 226) ^ 0x93;
  LOBYTE(v7) = *(_BYTE *)v13;
  if ( *(_BYTE *)v13 == 64 || (_BYTE)v7 == 0xDA )
  {
    v17 = v15 & 0x78;
    v32 = v11;
    v18 = v11 & 0x40;
    if ( v18 != 0 )
    {
      v16 = v18;
      v13 = v5 + 56;
      *(_BYTE *)(v5 + 56) = 1;
      v17 = -225;
    }
    v14 = v18 ^ (unsigned __int64)(v18 & (unsigned int)a4);
    v11 = v32;
    v12 = 80;
    v15 = ((v7 + v17) ^ 8) - 147;
  }
  if ( (_BYTE)v7 == 38 )
  {
    v11 &= 0x40u;
    if ( (_DWORD)v11 == 0 )
    {
      v15 ^= v11;
      v13 = v5 + 56;
      *(_BYTE *)(v5 + 56) = 1;
      v12 = v12 - 144 + 30;
    }
    v16 &= v12;
    v14 = v13;
  }
  if ( (_BYTE)v7 == 105 )
  {
    v15 += 96;
    a4 = v11;
    v11 &= 0x40u;
    if ( (_DWORD)v11 == 0 )
    {
      a4 &= 1u;
      if ( (_DWORD)a4 == 0 )
      {
        LOBYTE(v12) = (v12 ^ 0x8D) & 4;
        v14 |= 0x86uLL;
        v13 = v5 + 56;
        *(_BYTE *)(v5 + 56) = 1;
      }
    }
    v16 = 0;
    LOBYTE(v12) = v12 - 6;
  }
  if ( (_BYTE)v7 == 113 )
  {
    v11 &= 1u;
    if ( (_DWORD)v11 == 0 )
    {
      LOBYTE(v12) = 40;
      v14 += 172;
      v19 = v15 + v16;
      v13 = v5 + 56;
      v15 = ((v15 | 0x28) ^ 0xF2) + 240;
      *(_BYTE *)(v5 + 56) = 1;
      v16 = (v19 - 4) ^ 0x34;
    }
    v16 += 0x7FFFFFFF;
  }
  if ( (_BYTE)v7 == 3 )
  {
    v11 &= 1u;
    if ( (_DWORD)v11 != 0 )
    {
      v13 = v5 + 56;
      v15 = (v7 ^ v15 ^ 0xF) + 100;
      *(_BYTE *)(v5 + 56) = 1;
      v14 = v14 - 117 + 100;
      v16 = 1;
      LOBYTE(v12) = v11;
    }
    v14 |= 0x7FFFFFFFuLL;
    v15 = (v15 - 30) | 0xF2;
  }
  if ( (_BYTE)v7 == 40 )
  {
    v20 = v11;
    LODWORD(v11) = v11 & 0x40;
    if ( (_DWORD)v11 != 0 )
    {
      v13 = v5 + 56;
      LOBYTE(v12) = (v12 & 0xB7 | 8) + 1;
      *(_BYTE *)(v5 + 56) = 1;
      v14 = 0;
      v16 |= v20 | 0xF0;
    }
    a4 = v20 & 1;
    if ( (_DWORD)a4 != 0 )
    {
      v16 += (unsigned int)a4 + 0xFFFFLL;
      v14 = (v14 + 77) | 0xD3;
      v13 = v5 + 56;
      *(_BYTE *)(v5 + 56) = 1;
      LOBYTE(v12) = ((((v12 | 0x83) + 96) ^ 0x31) - 73) & 0x40;
    }
    v15 = 512;
    v16 |= v14;
  }
  if ( (_BYTE)v7 == 0xA3 )
  {
    v14 = 1024;
    v21 = v15 & 0x400;
    v16 ^= 0x93uLL;
    a4 = v11 & 0x40;
    if ( (v11 & 0x40) == 0 )
    {
      a4 = (v11 & 0x800) != 0;
      v16 = 512 - v7;
      v21 = 1024;
      LOBYTE(v12) = -38;
      v14 = v7 + 1165;
      LODWORD(v11) = (v11 & 0x80) != 0;
      if ( (_DWORD)v11 == (_DWORD)a4 )
      {
        LOBYTE(v12) = 0;
        v13 = v5 + 56;
        v16 = 18;
        v14 = a4 | ((unsigned __int8)(v7 + 111) ^ 0xA3) & 6;
        v21 = 1235;
        *(_BYTE *)(v5 + 56) = 1;
      }
    }
    v15 = v21 - 55;
  }
  if ( (_BYTE)v7 == 0x88 )
  {
    v15 = (v15 | 0x73) + 171;
    a4 = (v11 & 0x800) != 0;
    v16 = !(v12 & 1);
    v14 = v13 ^ 0x413;
    LODWORD(v11) = (v11 & 0x80) != 0;
    if ( (_DWORD)v11 == (_DWORD)a4 )
    {
      v13 = v5 + 56;
      v15 &= 4u;
      v16 = 0;
      *(_BYTE *)(v5 + 56) = 1;
      v14 &= 4u;
    }
  }
  if ( (_BYTE)v7 == 78 )
  {
    v14 = (v13 ^ v14) - 30;
    a4 = (v11 & 0x800) != 0;
    v16 = (v16 + 0x80000000LL) ^ 0xF9;
    v22 = (v13 + v15) ^ 0x400;
    LODWORD(v11) = (v11 & 0x80) != 0;
    if ( (_DWORD)v11 != (_DWORD)a4 )
    {
      v13 = v5 + 56;
      *(_BYTE *)(v5 + 56) = 1;
      v14 = (v14 & 0x4D) - 6;
      v16 = 0;
      v22 = 0;
    }
    v15 = v22 + 141;
  }
  if ( (_BYTE)v7 == 0xDA )
  {
    v23 = v16 | 0xFFFF;
    if ( (v11 & 0x40) != 0 )
    {
      v14 -= 240;
      LOBYTE(v15) = v15 ^ 0x80;
      v13 = v5 + 56;
      *(_BYTE *)(v5 + 56) = 1;
      v23 = 1024;
    }
    v24 = v14 | 0xF9;
    a4 = (v11 & 0x800) != 0;
    v25 = (v15 & 0xF0 ^ 0xB7) & 0x80;
    v16 = v23 - 226 + 0x7FFFFFFF;
    LODWORD(v11) = (v11 & 0x80) != 0;
    if ( (_DWORD)v11 != (_DWORD)a4 )
    {
      v13 = v5 + 56;
      *(_BYTE *)(v5 + 56) = 1;
      v16 = -(v25 + 0x7FFFFFFF);
      v24 = (v24 ^ 0xFA) - a4 - 67;
    }
    v14 = v24 + 52;
    v15 = 18;
  }
  if ( (_BYTE)v7 == 0x81 )
  {
    LODWORD(v11) = v11 & 0x800;
    if ( (_DWORD)v11 == 0 )
    {
      v16 = 0;
      v13 = v5 + 56;
      *(_BYTE *)(v5 + 56) = 1;
      v15 = v15 & 0xE | 0x10;
      v14 = 1023;
    }
    v16 |= v14 | 0x800;
    v15 -= 211;
  }
  if ( (_BYTE)v7 == 0xB4 )
  {
    LODWORD(v11) = v11 & 4;
    if ( (_DWORD)v11 == 0 )
    {
      v26 = v16 ^ v15;
      v13 = v5 + 56;
      LOBYTE(v16) = v16 ^ 0xF0;
      *(_BYTE *)(v5 + 56) = 1;
      v14 ^= v26 ^ 4;
    }
    v16 &= 8u;
    v14 -= v13;
  }
  if ( (_BYTE)v7 == 0x86 )
  {
    LODWORD(v11) = v11 & 0x80;
    if ( (_DWORD)v11 == 0 )
    {
      v16 += 128;
      v13 = v5 + 56;
      v14 = 18;
      *(_BYTE *)(v5 + 56) = 1;
    }
    v14 -= v16;
  }
  if ( (_BYTE)v7 == 118 )
  {
    LODWORD(v11) = v11 & 0x800;
    if ( (_DWORD)v11 != 0 )
    {
      v13 = v5 + 56;
      *(_BYTE *)(v5 + 56) = 1;
      v16 = 0;
      v14 = ((v14 ^ 4) - 141) ^ 0xF0 | 0x2A;
    }
  }
  if ( (_BYTE)v7 == 0xE5 )
  {
    LODWORD(v11) = v11 & 4;
    if ( (_DWORD)v11 != 0 )
    {
      v13 = v5 + 56;
      v14 |= a4 ^ v16 | v7 | 0x90;
      *(_BYTE *)(v5 + 56) = 1;
    }
    v14 ^= 0xF9uLL;
  }
  if ( (_BYTE)v7 == 0x8F && (v11 & 0x80) != 0 )
  {
    v14 ^= 0xFuLL;
    v13 = v5 + 56;
    *(_BYTE *)(v5 + 56) = 1;
  }
  if ( *(_BYTE *)(v5 + 56) != 0 )
  {
    *(_QWORD *)&v33[*(unsigned __int16 *)(*(_QWORD *)(v5 + 251) + 4LL)] = *(_QWORD *)(v5 + 239)
                                                                        + **(unsigned int **)(v5 + 251);
    *(_DWORD *)(v5 + 231) = 0;
    result = *(_QWORD *)&v33[112];
    __writeeflags(*(unsigned __int64 *)&v33[120]);
  }
  else
  {
    *(_QWORD *)(v5 + *(unsigned __int16 *)(*(_QWORD *)(v5 + 251) + 9LL)) += 136LL;
    v28 = *(_QWORD *)(v5 + 84);
    v29 = *(_DWORD *)(v5 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v5 + 251) + 11LL);
    *(_QWORD *)(v5 + 158) -= v14 + 2147485018LL;
    *(_DWORD *)(v5 + 105) &= v29;
    v30 = 8LL * (unsigned __int16)v29 + v28;
    v31 = *(__int64 (__fastcall **)(_QWORD, __int64, __int64, __int64))v30;
    *(_QWORD *)(v5 + 251) += 13LL;
    return v31(v31, v13, v30, (v30 ^ 1 | 0xAC) - 183);
  }
  return result;
}


// ===== Dp_H067_4da4d @ 0x28009da4d size=0x5b4 =====
__int64 __fastcall Dp_H067_4da4d()
{
  __int64 v0; // rbp
  __int64 v1; // rdx
  _BYTE *v2; // rbx
  unsigned __int64 v3; // kr00_8
  __int64 v4; // r12
  _QWORD *v5; // rax
  int v6; // edi
  char v7; // si
  unsigned __int8 v8; // si
  __int64 v9; // r9
  __int64 v10; // rdx
  int v11; // edi
  __int64 (__fastcall *v12)(__int64, __int64); // rsi

  *(_DWORD *)(v0 + 105) += 114097563;
  *(_DWORD *)(v0 + 335) ^= 0x335CA79Au;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) -= 27188350;
  v1 = *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  v2 = *(_BYTE **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 5LL));
  *v2 -= v1;
  v3 = __readeflags();
  v4 = ((((v1 & 0x1006D ^ (unsigned __int8)(v1 + 18) & 0x91 ^ 0xF9) - 1024) ^ 0xF | 0x400) ^ 0x64) - 52;
  v5 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 5LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL)) & 0x400LL) != 0 )
    --*v5;
  else
    ++*v5;
  v6 = *(_DWORD *)(v0 + 335) & 1;
  v7 = 0;
  if ( v6 != 0 )
  {
    v7 = 79;
    *(_DWORD *)(v0 + 335) -= 1979254117;
  }
  v8 = (v6 ^ (v7 + 4)) - 4;
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 4LL) != 0 )
  {
    v8 = ((((v8 + 16) ^ 0xF2) - 4) | 0xAC) - 40;
    v4 = v0 + **(unsigned __int16 **)(v0 + 251);
    *(_QWORD *)v4 = v3;
  }
  *(_DWORD *)(v0 + 247) += 1985988241;
  v9 = *(_QWORD *)(v0 + 84);
  v10 = (v0 & (v3 & v8 & 0xF9 ^ 0x7FFFFFFF) | 0xF6) & ((v3 | 0x2A) + 264) ^ 0x60;
  v11 = *(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 7LL);
  *(_QWORD *)(v0 + 158) += v4;
  *(_DWORD *)(v0 + 105) &= v11;
  v12 = *(__int64 (__fastcall **)(__int64, __int64))(8LL * (unsigned __int16)v11 + v9);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v12(v0 + 105, v10);
}


// ===== Dp_H068_4e001 @ 0x28009e001 size=0x589 =====
__int64 __fastcall Dp_H068_4e001()
{
  __int64 v0; // rbp
  _BYTE *v1; // r15
  unsigned __int64 v2; // kr00_8
  _QWORD *v3; // r15
  unsigned __int64 *v4; // rdx
  int v5; // r10d
  __int64 v6; // r10
  __int64 v7; // r12
  __int64 v8; // rcx
  int v9; // r14d
  __int64 (__fastcall *v10)(__int64, _QWORD, __int64); // rdx

  v1 = *(_BYTE **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 7LL));
  *v1 -= *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 5LL));
  v2 = __readeflags();
  v3 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 7LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL)) & 0x400LL) != 0 )
    --*v3;
  else
    ++*v3;
  v4 = (unsigned __int64 *)(v0 + 335);
  v5 = *(_DWORD *)(v0 + 335);
  if ( **(_BYTE **)(v0 + 251) != 0 )
  {
    v4 = (unsigned __int64 *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 1LL));
    *v4 = v2;
  }
  v6 = v5 & 1;
  if ( (_DWORD)v6 != 0 )
    *(_DWORD *)(v0 + 335) &= 0xA204049u;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) += 1646491480;
  *(_DWORD *)(v0 + 335) += 521123158;
  *(_DWORD *)(v0 + 285) &= 0x441D5FF7u;
  v7 = *(_QWORD *)(v0 + 84);
  v8 = (((unsigned __int8)v4 ^ 0x3A) + 30) & 0x64;
  v9 = *(_DWORD *)(v0 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 3LL);
  *(_QWORD *)(v0 + 158) -= (char *)v4 + v6;
  v9 -= 1709849844;
  *(_DWORD *)(v0 + 105) ^= v9;
  v10 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64))(8LL * (unsigned __int16)v9 + v7);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v10(v8, v10, v0 + 105);
}


// ===== Dp_H069_4e58a @ 0x28009e58a size=0x4be =====
__int64 __fastcall Dp_H069_4e58a()
{
  __int64 v0; // rbp
  _DWORD *v1; // r14
  unsigned __int64 v2; // kr00_8
  _QWORD *v3; // rdx
  __int64 v4; // r10
  int v5; // eax
  __int64 (*v6)(void); // rdi

  *(_DWORD *)(v0 + 247) ^= 0xAE27BAu;
  v1 = *(_DWORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 7LL));
  *v1 -= *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 3LL));
  v2 = __readeflags();
  v3 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 7LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 5LL)) & 0x400LL) != 0 )
    *v3 -= 4LL;
  else
    *v3 += 4LL;
  *(_DWORD *)(v0 + 105) |= 0xECDA434u;
  *(_DWORD *)(v0 + 307) -= 248357940;
  if ( **(_BYTE **)(v0 + 251) != 0 )
    *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL)) = v2;
  *(_DWORD *)(v0 + 247) -= 1111896657;
  v4 = *(_QWORD *)(v0 + 84);
  v5 = *(_DWORD *)(v0 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 1LL);
  *(_QWORD *)(v0 + 158) -= 248357940LL;
  *(_DWORD *)(v0 + 105) += v5;
  v6 = *(__int64 (**)(void))(8LL * (unsigned __int16)v5 + v4);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v6();
}


// ===== Dp_H070_4ea48 @ 0x28009ea48 size=0x2fe =====
__int64 __fastcall Dp_H070_4ea48()
{
  __int64 v0; // rbp
  int v1; // ebx
  _BYTE *v2; // rax
  __int64 v3; // rcx
  __int64 v4; // r12
  _QWORD *v5; // r13
  _QWORD *v6; // r14
  __int64 v7; // r8
  int v8; // r10d
  unsigned __int16 v9; // r12
  __int64 (__fastcall **v10)(__int64, __int64, _QWORD, _QWORD); // r8
  __int64 (__fastcall *v11)(__int64, __int64, _QWORD, _QWORD); // rax

  *(_DWORD *)(v0 + 285) -= 841044473;
  *(_DWORD *)(v0 + 105) -= 1432658207;
  *(_DWORD *)(v0 + 307) &= 0x5564A11Fu;
  v1 = *(_DWORD *)(v0 + 335) & 1;
  *(_DWORD *)(v0 + 105) &= 0x203B4CE6u;
  if ( v1 != 0 )
    *(_DWORD *)(v0 + 335) ^= 0x203B4CE6u;
  *(_DWORD *)(v0 + 307) ^= 0x203B4CE6u;
  v2 = *(_BYTE **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  **(_BYTE **)(v0 + **(unsigned __int16 **)(v0 + 251)) = *v2;
  v3 = *(_DWORD *)(v0 + 28) & 0x400LL;
  v4 = v3 | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) & 0x400LL;
  v5 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  v6 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  if ( v4 != 0 )
  {
    --*v5;
    --*v6;
  }
  else
  {
    ++*v5;
    ++*v6;
  }
  v7 = *(_QWORD *)(v0 + 84);
  v8 = *(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL);
  v9 = (v7 | (((unsigned __int16)v2 | (v4 - 183)) - (((_BYTE)v0 + 105) & 0x75) - v7 + 52) | 0xAC) - v8;
  v8 += 1799469167;
  *(_DWORD *)(v0 + 105) ^= v8;
  v10 = (__int64 (__fastcall **)(__int64, __int64, _QWORD, _QWORD))(8LL * (unsigned __int16)v8 + v7);
  v11 = *v10;
  *(_QWORD *)(v0 + 251) += 8LL;
  return v11(v3, 115, v10, v9);
}


// ===== Dp_H071_4ed46 @ 0x28009ed46 size=0x25f =====
__int64 __fastcall Dp_H071_4ed46(__int64 a1)
{
  __int64 v1; // rbp
  __int64 (__fastcall *v2)(__int64, __int64, _QWORD, __int64); // r8
  __int64 v3; // r9
  __int64 v4; // r10
  __int64 v5; // rdx

  v2 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64))(8LL * **(unsigned __int16 **)(v1 + 251)
                                                                   + *(_QWORD *)(v1 + 84));
  v3 = 1024;
  v4 = *(unsigned int *)(*(_QWORD *)(v1 + 251) + 4LL);
  if ( (int)v4 >= 0 )
  {
    v5 = v1 + 251;
    *(_QWORD *)(v1 + 251) += v4;
  }
  else
  {
    v3 = 1155;
    v5 = v1 + 251;
    *(_QWORD *)(v1 + 251) -= v4 & 0x7FFFFFFF;
  }
  return v2(a1, v5, v2, v3);
}


// ===== Dp_H072_4efa5 @ 0x28009efa5 size=0x1cd =====
void __fastcall Dp_H072_4efa5()
{
  __int64 v0; // rbp
  __int64 v1; // r10
  unsigned __int16 *v2; // r15
  __int64 v3; // r14
  int v4; // ebx
  __int64 v5; // r11

  *(_DWORD *)(v0 + 285) ^= 0x23CF1109u;
  *(_DWORD *)(v0 + 247) ^= 0x688605CBu;
  v2 = (unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL);
  *(_DWORD *)(v0 + 247) += 1576208588;
  *(_QWORD *)(v0 + *v2) -= 8LL;
  v3 = *(_QWORD *)(v0 + 84);
  v4 = **(unsigned __int16 **)(v0 + 251) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) ^= v0 + 105 + v1;
  v5 = *(_QWORD *)(8LL * (unsigned __int16)(v4 - 18706) + v3);
  *(_QWORD *)(v0 + 251) += 6LL;
  __asm { jmp     r11 }
}


// ===== Dp_H073_4f172 @ 0x28009f172 size=0x55f =====
__int64 __fastcall Dp_H073_4f172()
{
  __int64 v0; // rbp
  _DWORD *v1; // rax
  unsigned __int64 v2; // kr00_8
  _QWORD *v3; // r10
  __int64 v4; // rax
  __int64 v5; // rcx
  int v6; // r12d
  __int64 (__fastcall **v7)(_QWORD, __int64, __int64, _QWORD); // rcx
  __int64 (__fastcall *v8)(_QWORD, __int64, __int64, _QWORD); // r9

  v1 = *(_DWORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  *v1 -= *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  v2 = __readeflags();
  v3 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 8LL)) & 0x400LL) != 0 )
    *v3 -= 4LL;
  else
    *v3 += 4LL;
  v4 = 128;
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 10LL) != 0 )
  {
    v4 = 209;
    *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) = v2;
  }
  *(_DWORD *)(v0 + 105) |= 0x32DF2052u;
  *(_DWORD *)(v0 + 105) += 136756312;
  *(_DWORD *)(v0 + 307) -= 136756312;
  *(_DWORD *)(v0 + 247) += 64936603;
  v5 = *(_QWORD *)(v0 + 84);
  v6 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL);
  *(_QWORD *)(v0 + 158) ^= ((((v0 + 251) & ((v0 + 105) ^ (v0 + 247))) - 40) ^ 0x8D) - 128 + v4;
  v6 += 600952361;
  *(_DWORD *)(v0 + 105) |= v6;
  v7 = (__int64 (__fastcall **)(_QWORD, __int64, __int64, _QWORD))(8LL * (unsigned __int16)v6 + v5);
  v8 = *v7;
  *(_QWORD *)(v0 + 251) += 11LL;
  return v8(v7, (((v0 + 105) | 0x4F) + 172) ^ 0x64, 253, v8);
}


// ===== Dp_H074_4f6d1 @ 0x28009f6d1 size=0x493 =====
__int64 __fastcall Dp_H074_4f6d1()
{
  __int64 v0; // rbp
  _QWORD *v1; // r8
  _QWORD *v2; // rdi
  char v3; // dl
  __int64 v4; // rdx
  __int64 v5; // r8
  int v6; // r15d
  __int64 (__fastcall **v7)(__int64, __int64, _QWORD, __int64); // r8
  __int64 (__fastcall *v8)(__int64, __int64, _QWORD, __int64); // r15

  *(_DWORD *)(v0 + 307) -= 1076089546;
  **(_DWORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) = **(_DWORD **)(v0
                                                                                       + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  v1 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  v2 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) & 0x400LL) != 0 )
  {
    v3 = 0;
    *v1 -= 4LL;
    *v2 -= 4LL;
  }
  else
  {
    *v1 += 4LL;
    v3 = (v0 + 105 + ((v0 + 105) | (unsigned __int8)v2 ^ 0xF3)) & 0xE2;
    *v2 += 4LL;
  }
  v4 = (unsigned __int8)(v3 + 61) & 0xE2;
  v5 = *(_QWORD *)(v0 + 84);
  v6 = **(unsigned __int16 **)(v0 + 251);
  *(_QWORD *)(v0 + 158) -= v4 ^ 0x400;
  *(_DWORD *)(v0 + 105) |= v6;
  v7 = (__int64 (__fastcall **)(__int64, __int64, _QWORD, __int64))(8LL * (unsigned __int16)v6 + v5);
  v8 = *v7;
  *(_QWORD *)(v0 + 251) += 8LL;
  return v8(v0 + 251, v4, v7, v4);
}


// ===== Dp_H075_4fb64 @ 0x28009fb64 size=0x1677 =====
// positive sp value has been detected, the output may be wrong!
void __fastcall Dp_H075_4fb64()
{
  __int64 v0; // rbp
  int v1; // r12d
  int v2; // r12d
  int v3; // r10d
  int v4; // esi
  __int64 v5; // rsi
  char v6; // r11
  char v7; // r10
  _BYTE *v8; // rdx
  _QWORD *v9; // r8
  char v10; // r10
  _WORD *v11; // rdi
  _QWORD *v12; // rdx
  __int64 v13; // rsi
  int v14; // r9d
  __int64 v15; // r12
  _BYTE v16[14]; // [rsp-Eh] [rbp-Eh]

  v1 = *(_DWORD *)(v0 + 335) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 5LL);
  *(_DWORD *)(v0 + 335) &= 0xAD1C980u;
  v2 = v1 - *(_DWORD *)(v0 + 285);
  *(_DWORD *)(v0 + 285) -= 286390794;
  *(_BYTE *)(v0 + 83) = ((unsigned __int8)(v2 & 0xF0) >> 4) - 45;
  *(_BYTE *)(v0 + 104) = (v2 & 0xF) + 25;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) &= 0x6C7E9145u;
  *(_DWORD *)(v0 + 105) += 1469112754;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) += 1469112754;
  *(_DWORD *)(v0 + 307) += 1469112754;
  v3 = *(_DWORD *)(v0 + 105) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 4LL) - *(_DWORD *)(v0 + 174);
  *(_DWORD *)(v0 + 335) += 2122708275;
  *(_BYTE *)(v0 + 157) += v3 - *(_BYTE *)(v0 + 285);
  v4 = *(_DWORD *)(v0 + 105) + *(_DWORD *)(*(_QWORD *)(v0 + 251) + 6LL);
  *(_DWORD *)(v0 + 105) |= v4;
  *(_DWORD *)(v0 + 335) ^= 0x7B10A39Au;
  v5 = (unsigned int)(*(_DWORD *)(v0 + 285) + v4);
  *(_DWORD *)(v0 + 285) |= 0x2EC6BA73u;
  *(_QWORD *)(v0 + 259) = v5 + 1913304530 - *(_QWORD *)(v0 + 158);
  v6 = (v0 + 3) | ((((v0 + 29) | 0xF6) ^ 0x73) - 70) | 0x56;
  if ( *(_BYTE *)(v0 + 83) == 0xD5 )
  {
    v7 = *(_BYTE *)(v0 + 104) - 25;
    v8 = *(_BYTE **)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259) + 18990));
    *(_QWORD *)(v0 + 149) = v8 + 711091250;
    if ( v7 == 1 )
      LOBYTE(v8) = *v8;
    if ( v7 == 2 )
      LOWORD(v8) = *(_WORD *)v8;
    if ( v7 == 3 )
      v8 = (_BYTE *)*(unsigned int *)v8;
    if ( v7 == 4 )
      v8 = *(_BYTE **)v8;
    v6 = -67;
    *(_QWORD *)(v0 + 259) = &v8[-*(_QWORD *)(v0 + 158) + 1913304530];
  }
  *(_BYTE *)(v0 + 74) = 0;
  *(_DWORD *)(v0 + 247) &= 0x54E89B4u;
  if ( *(_BYTE *)(v0 + 83) == 0xD4 )
  {
    v9 = (_QWORD *)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259) + 18990));
    *(_QWORD *)(v0 + 149) = (char *)v9 + 711091250;
    *(_QWORD *)(v0 + 259) = *v9 + 1913304530LL - *(_QWORD *)(v0 + 158);
    if ( (unsigned __int8)*(_QWORD *)(v0 + 104) == 28 )
      *(_BYTE *)(v0 + 74) = v6 | 3;
  }
  *(_DWORD *)(v0 + 105) ^= 0x326C89DCu;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) &= 0x326C89DCu;
  *(_DWORD *)(v0 + 307) &= 0x326C89DCu;
  *(_DWORD *)(v0 + 247) += 1680179462;
  *(_DWORD *)(v0 + 285) += 1540686895;
  v10 = (*(_BYTE *)(v0 + 104) - 25) & 0xF;
  if ( ((unsigned __int8)(*(_BYTE *)(v0 + 157) - 47) ^ 0xD2) == 6 )
  {
    if ( v10 == 2 )
      *(_WORD *)&v16[6] = *(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259) + 18990;
    else
      *(_QWORD *)v16 = *(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259) - 1913304530LL;
  }
  if ( ((unsigned __int8)(*(_BYTE *)(v0 + 157) - 47) ^ 0xD2) == 0x56 )
  {
    v11 = (_WORD *)(*(_QWORD *)(v0 + 149) - 711091250LL);
    if ( v10 == 2 )
      *v11 = *(_WORD *)&v16[6];
    else
      *(_QWORD *)v11 = *(_QWORD *)&v16[6];
  }
  v12 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  if ( ((unsigned __int8)(*(_BYTE *)(v0 + 157) - 47) ^ 0xD2) == 6 )
  {
    if ( ((*(_BYTE *)(v0 + 104) - 25) & 0xF) == 2 )
      *v12 -= 2LL;
    else
      *v12 -= 8LL;
  }
  if ( ((unsigned __int8)(*(_BYTE *)(v0 + 157) - 47) ^ 0xD2) == 0x56
    && (_QWORD *)(*(_QWORD *)(v0 + 149) - 711091250LL) != v12 )
  {
    *v12 += 8LL;
  }
  v13 = *(_QWORD *)(v0 + 84);
  v14 = *(_DWORD *)(v0 + 105) ^ **(unsigned __int16 **)(v0 + 251);
  *(_QWORD *)(v0 + 158) += v12;
  v14 += 1238598186;
  *(_DWORD *)(v0 + 105) ^= v14;
  v15 = *(_QWORD *)(8LL * (unsigned __int16)v14 + v13);
  *(_QWORD *)(v0 + 251) += 10LL;
  __asm { jmp     r12 }
}


// ===== Dp_H076_511db @ 0x2800a11db size=0x7c =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H076_511db()
{
  __int64 v0; // rbp
  __int64 result; // rax
  _BYTE v2[128]; // [rsp-80h] [rbp-80h]

  *(_QWORD *)&v2[**(unsigned __int16 **)(v0 + 251)] = *(_QWORD *)(v0 + 239)
                                                    + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 2LL);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v2[112];
  __writeeflags(*(unsigned __int64 *)&v2[120]);
  return result;
}


// ===== Dp_H077_51257 @ 0x2800a1257 size=0x29a =====
__int64 __fastcall Dp_H077_51257()
{
  __int64 v0; // rbp
  __int64 v1; // rdi
  __int64 v2; // rbx
  __int64 v3; // rcx
  __int64 v4; // r9
  __int64 v5; // rdx
  _QWORD *v6; // r15
  _QWORD *v7; // rax
  __int64 v8; // r14
  int v9; // r8d
  __int64 v10; // r8
  __int64 (__fastcall *v11)(_QWORD, __int64, __int64, __int64); // r15

  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) |= 0xC599E14u;
  v2 = **(unsigned __int16 **)(v0 + 251);
  v3 = *(_QWORD *)(v0 + 251);
  *(_DWORD *)(v0 + 335) &= 0x71E44C02u;
  **(_BYTE **)(v0 + v2) = **(_BYTE **)(v0 + *(unsigned __int16 *)(v3 + 4));
  v4 = *(_DWORD *)(v0 + 28) & 0x400LL;
  v5 = v4 | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) & 0x400LL;
  v6 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  v7 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
  if ( v5 != 0 )
  {
    --*v6;
    --*v7;
  }
  else
  {
    ++*v6;
    ++*v7;
  }
  *(_DWORD *)(v0 + 285) -= 107019217;
  v8 = *(_QWORD *)(v0 + 84);
  v9 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL);
  *(_QWORD *)(v0 + 158) += v1;
  v9 += 1577053648;
  *(_DWORD *)(v0 + 105) += v9;
  v10 = 8LL * (unsigned __int16)v9;
  v11 = *(__int64 (__fastcall **)(_QWORD, __int64, __int64, __int64))(v10 + v8);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v11(
           (unsigned __int8)(v0 + 106) & 0xF0,
           v5,
           v10,
           ((v0 + 251) ^ ((unsigned __int8)(v4 + 45) ^ 1) & 0x4D) - 0xFFFF);
}


// ===== Dp_H078_514f1 @ 0x2800a14f1 size=0x28b =====
__int64 __fastcall Dp_H078_514f1()
{
  __int64 v0; // rbp
  __int64 v1; // r11
  int v2; // r12d
  __int64 (__fastcall *v3)(__int64, _QWORD); // rdi
  _DWORD **v5; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v0 + 105) += 1170217248;
  v5 = (_DWORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
  **v5 = *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  if ( (*(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL)) & 0x400LL) != 0 )
    --*v5;
  else
    ++*v5;
  *(_DWORD *)(v0 + 105) -= 787259934;
  *(_DWORD *)(v0 + 307) &= 0x2EECA21Eu;
  *(_DWORD *)(v0 + 105) -= 1684613220;
  *(_DWORD *)(v0 + 335) ^= 0x2BB2D1A1u;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) += 2004409583;
  v1 = *(_QWORD *)(v0 + 84);
  v2 = *(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL);
  *(_QWORD *)(v0 + 158) += v5;
  v3 = *(__int64 (__fastcall **)(__int64, _QWORD))(8LL * ((unsigned __int16)v2 ^ 0x45D1u) + v1);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v3(
           (((unsigned __int8)(((unsigned __int8)v5 ^ ((unsigned __int8)v5 | 0xFA) ^ 4) + 79) & 0x80)
          - 0x80000000LL
          + 144)
         | 0x7FFFFFFF,
           0);
}


// ===== Dp_H079_5177c @ 0x2800a177c size=0x59 =====
__int64 __fastcall Dp_H079_5177c()
{
  __int64 v0; // rbp
  __int64 (*v1)(void); // r11

  *(_DWORD *)(v0 + 28) = 0;
  v1 = *(__int64 (**)(void))(8LL * **(unsigned __int16 **)(v0 + 251) + *(_QWORD *)(v0 + 84));
  *(_QWORD *)(v0 + 251) += 4LL;
  return v1();
}


// ===== Dp_H080_517d5 @ 0x2800a17d5 size=0x4ce =====
__int64 __fastcall Dp_H080_517d5()
{
  __int64 v0; // rbp
  __int64 v1; // r8
  __int64 v2; // r13
  unsigned __int64 v3; // rcx
  __int64 v4; // r11
  _QWORD *v5; // rcx
  _QWORD *v6; // rax
  __int64 v7; // r13
  int v8; // ebx
  __int64 (__fastcall *v9)(__int64, __int64, __int64, __int64); // r15

  *(_DWORD *)(v0 + 105) -= 367442703;
  *(_DWORD *)(v0 + 285) -= 1991841314;
  *(_DWORD *)(v0 + 335) += 1991841314;
  v1 = **(unsigned __int16 **)(v0 + 251);
  *(_DWORD *)(v0 + 247) += 1998785031;
  **(_WORD **)(v0 + v1) = **(_WORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  v2 = *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) & 0x400LL;
  v3 = *(_QWORD *)(v0 + 251);
  v4 = (v3 | (44 - v2 - 86) ^ 0x61) ^ 0x4D;
  v5 = (_QWORD *)(v0 + *(unsigned __int16 *)v3);
  v6 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | v2) != 0 )
  {
    *v5 -= 2LL;
    *v6 -= 2LL;
  }
  else
  {
    *v5 += 2LL;
    *v6 += 2LL;
  }
  *(_DWORD *)(v0 + 105) -= 1148049072;
  *(_DWORD *)(v0 + 307) += 1148049072;
  *(_DWORD *)(v0 + 105) ^= 0x346F8BB4u;
  *(_DWORD *)(v0 + 307) ^= 0x346F8BB4u;
  v7 = *(_QWORD *)(v0 + 84);
  v8 = *(_DWORD *)(v0 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL);
  *(_QWORD *)(v0 + 158) += v4 ^ 0x346F8BB4;
  v8 += 1594824423;
  *(_DWORD *)(v0 + 105) &= v8;
  v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(8LL * (unsigned __int16)v8 + v7);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v9(((2 * (_BYTE)v8) & 0x2A) + 242LL, ((v4 ^ 0x346F8BB4 | 0x37F) + 2048) ^ 0xF | 0xAC, 44, 18);
}


// ===== Dp_H081_51ca3 @ 0x2800a1ca3 size=0xfcc =====
__int64 __fastcall Dp_H081_51ca3(__int64 a1)
{
  __int64 v1; // rbp
  __int64 v2; // rcx
  unsigned __int16 *v3; // rsi
  int v4; // r8d
  char v5; // r15
  char v6; // r12
  char v7; // r12
  int v8; // r12d
  int v9; // r12d
  int v10; // r12d
  int v11; // r12d
  __int64 v12; // rsi
  __int64 *v13; // r12
  __int64 (__fastcall *v14)(__int64, __int64, _QWORD, __int64); // r8
  _DWORD *v15; // r11
  __int64 v16; // r9
  __int64 v17; // r15
  __int64 v18; // rdx
  __int64 v20; // r14
  int v21; // edx
  __int64 (__fastcall *v22)(_QWORD); // r8
  int v23; // [rsp-8h] [rbp-8h]

  *(_BYTE *)(v1 + 56) = 0;
  v2 = a1 - 242 + 4;
  v3 = (unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 8LL);
  v4 = *(_DWORD *)(v1 + *v3);
  v5 = *(_BYTE *)(*(_QWORD *)(v1 + 251) + 10LL);
  if ( v5 == 64 || v5 == -38 )
  {
    v23 = *(_DWORD *)(v1 + *v3);
    if ( (v4 & 0x40) != 0 )
      *(_BYTE *)(v1 + 56) = 1;
    LOWORD(v4) = v23;
  }
  if ( v5 == 38 )
  {
    v4 &= 0x40u;
    if ( v4 == 0 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == 105 )
  {
    v6 = v4;
    v4 &= 0x40u;
    if ( v4 == 0 && (v6 & 1) == 0 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == 113 )
  {
    v4 &= 1u;
    if ( v4 == 0 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == 3 )
  {
    v4 &= 1u;
    if ( v4 != 0 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == 40 )
  {
    v7 = v4;
    v4 &= 0x40u;
    if ( v4 != 0 )
      *(_BYTE *)(v1 + 56) = 1;
    if ( (v7 & 1) != 0 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == -93 && (v4 & 0x40) == 0 )
  {
    v8 = (v4 & 0x800) != 0;
    v4 = (v4 & 0x80) != 0;
    if ( v4 == v8 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == -120 )
  {
    v9 = (v4 & 0x800) != 0;
    v4 = (v4 & 0x80) != 0;
    if ( v4 == v9 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == 78 )
  {
    v10 = (v4 & 0x800) != 0;
    v4 = (v4 & 0x80) != 0;
    if ( v4 != v10 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == -38 )
  {
    if ( (v4 & 0x40) != 0 )
      *(_BYTE *)(v1 + 56) = 1;
    v11 = (v4 & 0x800) != 0;
    v4 = (v4 & 0x80) != 0;
    if ( v4 != v11 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == -127 )
  {
    v4 &= 0x800u;
    if ( v4 == 0 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == -76 )
  {
    v4 &= 4u;
    if ( v4 == 0 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == -122 )
  {
    v4 &= 0x80u;
    if ( v4 == 0 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == 118 )
  {
    v4 &= 0x800u;
    if ( v4 != 0 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == -27 )
  {
    v4 &= 4u;
    if ( v4 != 0 )
      *(_BYTE *)(v1 + 56) = 1;
  }
  if ( v5 == -113 && (v4 & 0x80) != 0 )
    *(_BYTE *)(v1 + 56) = 1;
  v12 = 8LL * **(unsigned __int16 **)(v1 + 251);
  v13 = (__int64 *)(v12 + *(_QWORD *)(v1 + 84));
  v14 = (__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))*v13;
  v15 = (_DWORD *)(*(_QWORD *)(v1 + 251) + 4LL);
  v16 = *v13 + ((((_BYTE)v12 + *(_BYTE *)(v1 + 84)) & 2 | 0x28u) ^ 0x8DLL | 4);
  v17 = (unsigned int)*v15;
  v18 = *v15 & 0x80000000;
  if ( *(_BYTE *)(v1 + 56) != 0 )
  {
    if ( (_DWORD)v18 != 0 )
      *(_QWORD *)(v1 + 251) -= v17 & 0x7FFFFFFF;
    else
      *(_QWORD *)(v1 + 251) += v17;
    return v14(v2, v18, v14, v16);
  }
  else
  {
    v20 = *(_QWORD *)(v1 + 84);
    v21 = *(_DWORD *)(v1 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 11LL);
    *(_QWORD *)(v1 + 158) ^= v16;
    v21 -= 1122399018;
    *(_DWORD *)(v1 + 105) &= v21;
    v22 = *(__int64 (__fastcall **)(_QWORD))(8LL * (unsigned __int16)v21 + v20);
    *(_QWORD *)(v1 + 251) += 13LL;
    return v22(0);
  }
}


// ===== Dp_H082_52c6f @ 0x2800a2c6f size=0x260 =====
__int64 __fastcall Dp_H082_52c6f()
{
  __int64 v0; // rbp
  __int64 v1; // rdi
  unsigned __int16 *v2; // rcx
  __int64 v3; // rbx
  int v4; // r9d
  __int64 v5; // r13
  __int64 (__fastcall *v6)(_QWORD, __int64, __int64, __int64); // r11
  _QWORD *v8; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v0 + 285) += 1981014766;
  *(_DWORD *)(v0 + 105) += 691632532;
  v2 = (unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL);
  v3 = **(unsigned __int16 **)(v0 + 251);
  *(_DWORD *)(v0 + 105) += 1838969343;
  v8 = (_QWORD *)(v0 + v3);
  *(_WORD *)(v0 + *v2) = **(_WORD **)(v0 + v3);
  if ( (*(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) & 0x400LL) != 0 )
    *v8 -= 2LL;
  else
    *v8 += 2LL;
  v4 = *(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL);
  v5 = *(_QWORD *)(v0 + 84);
  *(_QWORD *)(v0 + 158) -= v1 + v0 + 105;
  v4 ^= 0x974C55Bu;
  *(_DWORD *)(v0 + 105) |= v4;
  v6 = *(__int64 (__fastcall **)(_QWORD, __int64, __int64, __int64))(8LL * (unsigned __int16)v4 + v5);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v6(0, v0 + 105, 512, -2041);
}


// ===== Dp_H083_52ecf @ 0x2800a2ecf size=0xd01 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H083_52ecf(__int64 a1, char a2, char a3)
{
  char v3; // al
  char v4; // bl
  __int64 v5; // rbp
  char v6; // dl
  char v7; // al
  int v8; // ecx
  int v9; // r10d
  char v10; // al
  char v11; // dl
  __int64 v12; // r14
  char v13; // di
  char v14; // r13
  char v15; // r8
  char v16; // r13
  char v17; // cl
  char v18; // al
  char v19; // r13
  char v20; // al
  char v21; // dl
  char v22; // r13
  char v23; // al
  char v24; // al
  char v25; // r13
  char v26; // di
  char v27; // dl
  char v28; // r13
  char v29; // r13
  char v30; // di
  __int64 result; // rax
  unsigned __int16 *v32; // r13
  __int64 v33; // r12
  int v34; // esi
  __int64 (__fastcall *v35)(__int64, __int64, __int64); // rbx
  int v36; // [rsp-90h] [rbp-90h]
  _BYTE v37[136]; // [rsp-88h] [rbp-88h]

  v6 = (v5 + 56) | (v3 + (a3 ^ a2));
  *(_BYTE *)(v5 + 56) = 0;
  v7 = ((v3 - 14) ^ 0xF0) - 4;
  LOBYTE(v8) = v7 - 17;
  v9 = *(_DWORD *)(v5 + *(unsigned __int16 *)(*(_QWORD *)(v5 + 251) + 6LL));
  v10 = v9 ^ (v7 - 73);
  v11 = 2 * (((v5 - 5) | ((v4 | 8) - 1) & v6 ^ 0x80) - 109) + 8;
  v12 = *(_QWORD *)(v5 + 251) + 8LL;
  v13 = 0;
  v14 = v9;
  v15 = *(_BYTE *)v12;
  if ( *(_BYTE *)v12 == 64 || v15 == -38 )
  {
    v11 = v9 | 0x73;
    v10 = 0;
    v36 = *(_DWORD *)(v5 + *(unsigned __int16 *)(*(_QWORD *)(v5 + 251) + 6LL));
    if ( (v9 & 0x40) != 0 )
    {
      LOBYTE(v12) = v5 + 56;
      *(_BYTE *)(v5 + 56) = 1;
      v10 = v8 | 0x8F;
      v11 = v15;
      v13 = 68;
    }
    LOWORD(v9) = v36;
    v14 = 1;
  }
  if ( v15 == 38 )
  {
    v9 &= 0x40u;
    if ( v9 == 0 )
    {
      v11 += 49;
      v13 -= 109;
      v14 ^= 0x75u;
      LOBYTE(v12) = v5 + 56;
      *(_BYTE *)(v5 + 56) = 1;
      v10 = (v10 ^ 0x31) + 115;
    }
    v10 = ~v10;
    v13 += 7;
  }
  if ( v15 == 105 )
  {
    v16 = v14 + 1;
    v11 += v13;
    LOBYTE(v8) = v9;
    v9 &= 0x40u;
    if ( v9 == 0 )
    {
      v8 &= 1u;
      if ( v8 == 0 )
      {
        v11 -= 14;
        LOBYTE(v12) = v5 + 56;
        v13 -= 65;
        *(_BYTE *)(v5 + 56) = 1;
        v10 = 0;
        v16 = 0;
      }
    }
    v14 = v16 - 30;
    v13 = ((v13 + 1) & 0x28) + 42;
  }
  if ( v15 == 113 )
  {
    v9 &= 1u;
    if ( v9 == 0 )
    {
      v11 = (v11 | 0x34) - 42;
      v14 = v5 ^ ((v14 ^ 0xAC) - 30);
      LOBYTE(v12) = v5 + 56;
      *(_BYTE *)(v5 + 56) = 1;
      v13 = 0;
    }
    v10 = (v14 + v10 + 0x80) & 0xF0;
    v11 = (v9 ^ v11) & 0x93;
  }
  if ( v15 == 3 )
  {
    v9 &= 1u;
    if ( v9 != 0 )
    {
      v13 = v12;
      v11 = (v11 - 49) & 0x31;
      LOBYTE(v12) = v5 + 56;
      v14 |= 0xC3u;
      *(_BYTE *)(v5 + 56) = 1;
    }
    v10 |= 8u;
    v13 |= 0x56u;
    v11 = 2 * (v11 & 0x60);
  }
  if ( v15 == 40 )
  {
    v17 = v9;
    v9 &= 0x40u;
    if ( v9 != 0 )
    {
      v10 -= 73;
      LOBYTE(v12) = v5 + 56;
      v13 = 18;
      *(_BYTE *)(v5 + 56) = 1;
    }
    v8 = v17 & 1;
    if ( v8 != 0 )
    {
      v10 ^= v15;
      LOBYTE(v12) = v5 + 56;
      v13 ^= 0x80u;
      *(_BYTE *)(v5 + 56) = 1;
      v14 |= 0xD3u;
    }
    v11 = 0;
    v14 -= 77;
    v13 += 84;
  }
  if ( v15 == -93 )
  {
    v18 = v10 - 93;
    v13 = 0;
    v19 = 0;
    LOBYTE(v8) = v9 & 0x40;
    if ( (v9 & 0x40) == 0 )
    {
      v20 = (v18 | 0xF) ^ 0xF1;
      v21 = (v11 + 1) | 6;
      v8 = (v9 & 0x800) != 0;
      v13 = v20 & 0x40;
      v18 = v21 | v20;
      v19 = 95;
      v11 = (v21 | 0xD3) + 1;
      v9 = (v9 & 0x80) != 0;
      if ( v9 == v8 )
      {
        LOBYTE(v12) = v5 + 56;
        v13 = 0;
        v19 = v9 + ((18 - v5) ^ 0xA3) + 112;
        *(_BYTE *)(v5 + 56) = 1;
        v18 = ((v18 ^ 8) & 6) - 61;
      }
    }
    v14 = v19 & 0x40;
    v11 ^= 4u;
    v10 = v18 | 0x4D;
  }
  if ( v15 == -120 )
  {
    v22 = v14 - 120;
    v8 = (v9 & 0x800) != 0;
    v23 = v10 | 0xF9;
    v13 = -1;
    v11 = v22 & ((v11 | 0x2A) ^ 0x75);
    v9 = (v9 & 0x80) != 0;
    if ( v9 == v8 )
    {
      LOBYTE(v12) = v5 + 56;
      v11 ^= v9;
      v23 = 0;
      *(_BYTE *)(v5 + 56) = 1;
      v22 = (v5 + 56) | v22 ^ 0x75;
    }
    v10 = v23 + 1;
    v14 = (v22 - 8) ^ 0x56;
  }
  if ( v15 == 78 )
  {
    v11 = 0;
    v8 = (v9 & 0x800) != 0;
    v24 = v10 | 0x75;
    v13 = 30;
    v25 = ((((v14 + 40) ^ 0x4E) + 40) | 0xAC) - 1 - v24;
    v9 = (v9 & 0x80) != 0;
    if ( v9 != v8 )
    {
      LOBYTE(v12) = v5 + 56;
      *(_BYTE *)(v5 + 56) = 1;
      v11 = -4;
      v13 = v5 + 56;
      v25 = 16;
    }
    v14 = v25 - 14;
    v10 = v24 - 30;
  }
  if ( v15 == -38 )
  {
    v26 = v13 + 38;
    if ( (v9 & 0x40) != 0 )
    {
      v26 ^= 0xFu;
      LOBYTE(v12) = v5 + 56;
      *(_BYTE *)(v5 + 56) = 1;
    }
    v13 = v26 & 0x80;
    v27 = -v10;
    v8 = (v9 & 0x800) != 0;
    v14 = 6;
    v9 = (v9 & 0x80) != 0;
    if ( v9 != v8 )
    {
      LOBYTE(v12) = v5 + 56;
      v13 = 77;
      v27 = -9;
      *(_BYTE *)(v5 + 56) = 1;
      v14 = 102;
    }
    v11 = v27 & 4;
    v10 = v11 | v9;
  }
  if ( v15 == -127 )
  {
    v9 &= 0x800u;
    if ( v9 == 0 )
    {
      LOBYTE(v12) = v5 + 56;
      v11 = (v11 - 73) & 0x28;
      v28 = v14 + 115;
      *(_BYTE *)(v5 + 56) = 1;
      v13 = v28 ^ (v10 | (v13 + 22)) & 8;
      v14 = v8 + v28;
    }
    v11 = 2 * v11 + 61;
  }
  if ( v15 == -76 )
  {
    v9 &= 4u;
    if ( v9 == 0 )
    {
      LOBYTE(v12) = v5 + 56;
      v13 -= 6;
      v10 = (v5 + 56) ^ v11;
      *(_BYTE *)(v5 + 56) = 1;
      v14 = ((v8 | v14) - 24) | 0xF0;
    }
    v10 |= v8;
    v13 += v12;
    v11 = 29;
  }
  if ( v15 == -122 )
  {
    v9 &= 0x80u;
    if ( v9 == 0 )
    {
      v13 = (v13 | 0x3F) - 14;
      *(_BYTE *)(v5 + 56) = 1;
      v10 = -62;
      v11 += 117;
    }
    v13 += 84;
    v10 -= 8;
    v11 += 14;
  }
  if ( v15 == 118 )
  {
    v9 &= 0x800u;
    if ( v9 != 0 )
    {
      v29 = v14 + 15;
      v10 = v11 ^ 0xF6;
      v30 = (v29 | v13) - 120;
      *(_BYTE *)(v5 + 56) = 1;
      v14 = v29 + 119;
      v11 = v30;
    }
    v14 &= 8u;
  }
  if ( v15 == -27 )
  {
    v9 &= 4u;
    if ( v9 != 0 )
    {
      v14 = 1;
      v10 = v11 & 2 | 0x90;
      *(_BYTE *)(v5 + 56) = 1;
    }
  }
  if ( v15 == -113 && (v9 & 0x80) != 0 )
  {
    v10 = (v10 + v14) & 0xF9;
    *(_BYTE *)(v5 + 56) = 1;
  }
  if ( *(_BYTE *)(v5 + 56) != 0 )
  {
    *(_QWORD *)&v37[*(unsigned __int16 *)(*(_QWORD *)(v5 + 251) + 4LL)] = *(_QWORD *)(v5 + 239)
                                                                        + **(unsigned int **)(v5 + 251);
    *(_DWORD *)(v5 + 231) = 0;
    result = *(_QWORD *)&v37[112];
    __writeeflags(*(unsigned __int64 *)&v37[120]);
  }
  else
  {
    v32 = (unsigned __int16 *)(*(_QWORD *)(v5 + 251) + 9LL);
    *(_QWORD *)(v5 + *v32) += 136LL;
    v33 = *(_QWORD *)(v5 + 84);
    v34 = *(_DWORD *)(v5 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v5 + 251) + 11LL) - 1403336316;
    *(_DWORD *)(v5 + 105) &= v34;
    v35 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(8LL * (unsigned __int16)v34 + v33);
    *(_QWORD *)(v5 + 251) += 13LL;
    return v35(
             v5 + 105,
             v5 + 105,
             ((((((unsigned __int8)v33 | (unsigned __int8)v10 ^ 0x8D) - (_BYTE)v32 + 115) & 0x40 | 0x30u) + 65303LL)
            | 0xF2)
           + 120);
  }
  return result;
}


// ===== Dp_H084_53bd0 @ 0x2800a3bd0 size=0x1a35 =====
void __fastcall Dp_H084_53bd0()
{
  __int64 v0; // rbp
  int v1; // r11d
  int v2; // r11d
  int v3; // r12d
  int v4; // edi
  char v5; // r8
  char v6; // r11
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // rcx
  __int64 v9; // r9
  __int64 v10; // r11
  __int64 v11; // rax
  __int64 v12; // rbx
  unsigned __int64 v13; // kr18_8
  char v14; // r11
  __int64 v15; // r11
  char v16; // dl
  _BYTE *v17; // rcx
  __int64 v18; // rax
  int v19; // r10d
  __int64 v20; // r8
  unsigned __int64 v21; // [rsp-20h] [rbp-20h]

  *(_DWORD *)(v0 + 105) &= 0x6F81FCF2u;
  v1 = *(_DWORD *)(v0 + 105) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 2LL);
  *(_DWORD *)(v0 + 105) ^= v1;
  *(_DWORD *)(v0 + 335) ^= 0x2F363ACCu;
  v2 = *(_DWORD *)(v0 + 285) ^ v1;
  *(_DWORD *)(v0 + 285) |= 0x56AD056Fu;
  *(_BYTE *)(v0 + 83) = ((unsigned __int8)(v2 & 0xF0) >> 4) ^ 0xDD;
  *(_BYTE *)(v0 + 104) = v2 & 0xF ^ 0xFB;
  v3 = *(_DWORD *)(v0 + 307) ^ *(_DWORD *)(*(_QWORD *)(v0 + 251) + 3LL);
  *(_DWORD *)(v0 + 105) -= v3;
  *(_DWORD *)(v0 + 335) += 669519017;
  *(_QWORD *)(v0 + 259) = (*(_DWORD *)(v0 + 285) ^ (unsigned int)v3 ^ 0x19E34E06LL) - *(_QWORD *)(v0 + 158);
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) ^= 0x7CB0473Bu;
  v4 = *(_DWORD *)(v0 + 285)
     ^ (*(_DWORD *)(v0 + 105) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 7LL) - *(_DWORD *)(v0 + 335));
  *(_DWORD *)(v0 + 285) += 1552680810;
  *(_BYTE *)(v0 + 157) += v4;
  *(_DWORD *)(v0 + 105) &= 0x4DD7A985u;
  *(_DWORD *)(v0 + 247) &= 0x701117FFu;
  v5 = *(_BYTE *)(v0 + 83) ^ 0xDD;
  if ( v5 == 2 )
  {
    v6 = *(_BYTE *)(v0 + 104) ^ 0xFB;
    v7 = *(_QWORD *)(v0 + ((unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259)) ^ 0x4E06u));
    v5 = v7 ^ 0x7F;
    *(_QWORD *)(v0 + 149) = v7 ^ 0x6402C77F;
    if ( v6 == 1 )
      LOBYTE(v7) = *(_BYTE *)v7;
    if ( v6 == 2 )
      LOWORD(v7) = *(_WORD *)v7;
    if ( v6 == 3 )
      v7 = *(unsigned int *)v7;
    if ( v6 == 4 )
      v7 = *(_QWORD *)v7;
    *(_QWORD *)(v0 + 259) = (v7 ^ 0x19E34E06) - *(_QWORD *)(v0 + 158);
  }
  *(_BYTE *)(v0 + 74) = 0;
  if ( (*(_BYTE *)(v0 + 83) ^ 0xDD) == 1 )
  {
    v8 = v0 + ((unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259)) ^ 0x4E06u);
    *(_QWORD *)(v0 + 149) = v8 ^ 0x6402C77F;
    *(_QWORD *)(v0 + 259) = (*(_QWORD *)v8 ^ 0x19E34E06LL) - *(_QWORD *)(v0 + 158);
    if ( ((unsigned __int8)*(_QWORD *)(v0 + 104) ^ 0xFB) == 3 )
      *(_BYTE *)(v0 + 74) = v5 | 3;
  }
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) ^= 0x4EBCFA2Cu;
  if ( *(_BYTE *)(v0 + 157) == 0xFD )
  {
    v9 = ((*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x19E34E06LL) - 1;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v9 - 414342885;
  }
  if ( *(_BYTE *)(v0 + 157) == 117 )
  {
    v10 = -((*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x19E34E06LL);
    __readeflags();
    *(_QWORD *)(v0 + 327) = v10 - 414342885;
  }
  if ( *(_BYTE *)(v0 + 157) == 92 )
  {
    v11 = ((*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x19E34E06LL) + 1;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v11 - 414342885;
  }
  if ( *(_BYTE *)(v0 + 157) == 0xBB )
  {
    v12 = ~((*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x19E34E06LL);
    v13 = __readeflags();
    v21 = v13;
    *(_QWORD *)(v0 + 327) = v12 - 414342885;
  }
  v14 = *(_BYTE *)(v0 + 157) + 55;
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 8LL) != 0 )
    *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251)) = v21;
  if ( v14 != -7 && *(_BYTE *)(v0 + 157) != 0xE7 )
  {
    v15 = *(_QWORD *)(v0 + 327) + 414342885LL;
    v16 = *(_BYTE *)(v0 + 104) ^ 0xFB;
    v17 = (_BYTE *)(*(_QWORD *)(v0 + 149) ^ 0x6402C77FLL);
    if ( v16 == 1 )
      *v17 = *(_BYTE *)(v0 + 327) - 27;
    if ( v16 == 2 )
      *(_WORD *)v17 = v15;
    if ( v16 == 3 )
    {
      *(_DWORD *)v17 = v15;
      LOBYTE(v15) = *(_BYTE *)(v0 + 74);
      if ( (_BYTE)v15 != 0 )
      {
        v17 += 4;
        *(_DWORD *)v17 = 0;
      }
    }
    if ( v16 == 4 )
      *(_QWORD *)v17 = v15;
  }
  v18 = *(_QWORD *)(v0 + 84);
  v19 = *(_DWORD *)(v0 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL);
  *(_DWORD *)(v0 + 105) ^= v19;
  v20 = *(_QWORD *)(8LL * (unsigned __int16)v19 + v18);
  *(_QWORD *)(v0 + 251) += 11LL;
  __asm { jmp     r8 }
}


// ===== Dp_H085_55605 @ 0x2800a5605 size=0x211 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H085_55605()
{
  __int64 v0; // rbx
  __int64 v1; // rbp
  unsigned __int16 *v2; // r13
  unsigned __int16 *v3; // rdx
  __int64 v4; // r14
  int v5; // r11d
  __int64 (*v6)(void); // rcx
  __int64 v8; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v1 + 247) |= 0xE82D721u;
  *(_DWORD *)(v1 + 105) |= 0x5E390E7Du;
  v2 = (unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 2LL);
  *(_DWORD *)(v1 + 105) |= 0x7EF1B48Au;
  *(_DWORD *)(v1 + 335) -= 208604713;
  v3 = (unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 4LL);
  *(_QWORD *)(v1 + *v2) = v8;
  *(_QWORD *)(v1 + *v3) += 8LL;
  *(_DWORD *)(v1 + 285) ^= 0xF8F0169u;
  v4 = *(_QWORD *)(v1 + 84);
  v5 = *(_DWORD *)(v1 + 105) + **(unsigned __int16 **)(v1 + 251);
  *(_QWORD *)(v1 + 158) ^= v1 + 335 + v0;
  v6 = *(__int64 (**)(void))(8LL * ((unsigned __int16)v5 ^ 0x3B59u) + v4);
  *(_QWORD *)(v1 + 251) += 6LL;
  return v6();
}


// ===== Dp_H086_55816 @ 0x2800a5816 size=0x344 =====
__int64 __fastcall Dp_H086_55816()
{
  __int64 v0; // rbp
  __int64 v1; // r11
  __int64 v2; // r11
  unsigned __int16 *v3; // r15
  __int64 v4; // r12
  int v5; // r14d
  __int64 (*v6)(void); // rbx
  _WORD **v8; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v0 + 105) -= 1363787381;
  v2 = ((v0 + 251 + v1) | 0x93) - 1024;
  v3 = *(unsigned __int16 **)(v0 + 251);
  *(_DWORD *)(v0 + 335) ^= 0x757659F2u;
  v8 = (_WORD **)(v0 + v3[1]);
  **v8 = *(_QWORD *)(v0 + *v3);
  if ( (*(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL)) & 0x400LL) != 0 )
    --*v8;
  else
    ++*v8;
  *(_DWORD *)(v0 + 247) -= 1515686297;
  v4 = *(_QWORD *)(v0 + 84);
  v5 = *(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL);
  *(_QWORD *)(v0 + 158) -= v2 ^ 0xFFFFFFFFFFFFFFFAuLL;
  v5 += 1443811989;
  *(_DWORD *)(v0 + 105) += v5;
  v6 = *(__int64 (**)(void))(8LL * (unsigned __int16)v5 + v4);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v6();
}


// ===== Dp_H087_55b5a @ 0x2800a5b5a size=0x19f =====
__int64 __fastcall Dp_H087_55b5a(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rbp
  _DWORD *v5; // r11
  char v6; // r10
  __int64 v7; // r14
  int v8; // edi
  __int64 (*v9)(void); // rax

  v5 = (_DWORD *)(v4 + **(unsigned __int16 **)(v4 + 251));
  v6 = *(_BYTE *)(*(_QWORD *)(v4 + 251) + 4LL);
  if ( v6 == -104 )
    *v5 &= ~1u;
  if ( v6 == -15 )
  {
    *v5 &= ~0x400u;
    *(_DWORD *)(v4 + 28) &= ~0x400u;
  }
  if ( v6 == 80 )
  {
    *v5 &= ~0x200u;
    *(_DWORD *)(v4 + 28) &= ~0x200u;
  }
  if ( v6 == -66 )
  {
    if ( (*v5 & 1) != 0 )
      *v5 &= ~1u;
    else
      *v5 |= 1u;
  }
  if ( v6 == 71 )
    *v5 |= 1u;
  if ( v6 == 116 )
  {
    *v5 |= 0x400u;
    *(_DWORD *)(v4 + 28) |= 0x400u;
  }
  if ( v6 == -40 )
  {
    *v5 |= 0x200u;
    *(_DWORD *)(v4 + 28) |= 0x200u;
  }
  v7 = *(_QWORD *)(v4 + 84);
  v8 = *(_DWORD *)(v4 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v4 + 251) + 2LL);
  *(_QWORD *)(v4 + 158) ^= a4 ^ (v4 + 105);
  *(_DWORD *)(v4 + 105) ^= v8;
  v9 = *(__int64 (**)(void))(8LL * (unsigned __int16)v8 + v7);
  *(_QWORD *)(v4 + 251) += 5LL;
  return v9();
}


// ===== Dp_H088_55cf9 @ 0x2800a5cf9 size=0x13b =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H088_55cf9()
{
  __int64 v0; // rbp
  _QWORD *v1; // rdi
  char v2; // cl
  __int64 v3; // r12
  _QWORD *v4; // r12
  __int64 result; // rax
  _BYTE v6[128]; // [rsp-80h] [rbp-80h] BYREF

  v2 = *(_BYTE *)(*(_QWORD *)(v0 + 251) + 10LL);
  v3 = 0;
  if ( v2 == -33 )
  {
    v3 = *(_QWORD *)(v0 + 239) + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 6LL);
    v1 = &v6[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)];
    *v1 = v3;
  }
  if ( v2 == 111 || v2 == 82 )
  {
    LOWORD(v3) = *(_WORD *)(*(_QWORD *)(v0 + 251) + 6LL);
    v4 = *(_QWORD **)(v0 + v3);
    if ( v2 == 82 )
      v4 = (_QWORD *)*v4;
    v1 = &v6[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)];
    *v1 = v4;
  }
  v1[1] = *(_QWORD *)(v0 + 239) + **(unsigned int **)(v0 + 251);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v6[112];
  __writeeflags(*(unsigned __int64 *)&v6[120]);
  return result;
}


// ===== Dp_H089_55e34 @ 0x2800a5e34 size=0x76 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H089_55e34()
{
  __int64 v0; // rbp
  __int64 result; // rax
  _BYTE v2[128]; // [rsp-80h] [rbp-80h]

  *(_QWORD *)&v2[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)] = *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v2[112];
  __writeeflags(*(unsigned __int64 *)&v2[120]);
  return result;
}


// ===== Dp_H090_55eaa @ 0x2800a5eaa size=0x1293 =====
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall Dp_H090_55eaa()
{
  __int64 v0; // rbp
  unsigned int v1; // r10d
  __int64 v2; // r10
  int v3; // ebx
  int v4; // edi
  int v5; // r14d
  __int64 v6; // r14
  char v7; // r11
  unsigned __int64 v8; // r14
  unsigned __int64 v9; // r13
  char v10; // r14
  _WORD *v11; // r13
  _QWORD *v12; // r8
  __int64 v13; // r12
  __int64 v14; // r9
  int v15; // r10d
  __int64 (__fastcall *v16)(_QWORD, __int64, _QWORD *); // r12
  __int64 v18; // kr00_8
  __int64 v19; // [rsp-8h] [rbp-8h]
  _UNKNOWN *retaddr; // [rsp+0h] [rbp+0h]

  v1 = *(_DWORD *)(*(_QWORD *)(v0 + 251) + 5LL);
  *(_DWORD *)(v0 + 105) &= v1;
  *(_DWORD *)(v0 + 335) ^= 0x41A806DFu;
  v2 = *(_DWORD *)(v0 + 285) ^ v1;
  *(_DWORD *)(v0 + 285) -= 1860272641;
  *(_QWORD *)(v0 + 259) = v2 + 1320112762 - *(_QWORD *)(v0 + 158);
  v3 = *(_DWORD *)(v0 + 335) ^ (*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 2LL) - *(_DWORD *)(v0 + 105));
  *(_DWORD *)(v0 + 105) |= v3;
  *(_BYTE *)(v0 + 83) = ((unsigned __int8)(v3 & 0xF0) >> 4) - 74;
  *(_BYTE *)(v0 + 104) = (v3 & 0xF) + 47;
  v4 = *(_DWORD *)(v0 + 335);
  *(_DWORD *)(v0 + 105) |= 0x4B35F53Cu;
  *(_DWORD *)(v0 + 307) += 1261827388;
  if ( (v4 & 1) != 0 )
    *(_DWORD *)(v0 + 335) += 1261827388;
  *(_DWORD *)(v0 + 335) -= 1914125495;
  v5 = *(_DWORD *)(v0 + 335) ^ (*(_DWORD *)(v0 + 105) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 9LL));
  *(_DWORD *)(v0 + 105) ^= v5;
  *(_DWORD *)(v0 + 335) -= 466216531;
  LODWORD(v6) = v5 - *(_DWORD *)(v0 + 285);
  *(_DWORD *)(v0 + 285) |= 0x3E0736EDu;
  *(_BYTE *)(v0 + 157) += v6;
  if ( *(_BYTE *)(v0 + 83) == 0xB8 )
  {
    v7 = *(_BYTE *)(v0 + 104) - 47;
    v8 = *(_QWORD *)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259) - 21114));
    *(_QWORD *)(v0 + 149) = v8 ^ 0x71F1ABE0;
    if ( v7 == 1 )
      LOBYTE(v8) = *(_BYTE *)v8;
    if ( v7 == 2 )
      LOWORD(v8) = *(_WORD *)v8;
    if ( v7 == 3 )
      v8 = *(unsigned int *)v8;
    if ( v7 == 4 )
      v8 = *(_QWORD *)v8;
    v6 = v8 + 1320112762 - *(_QWORD *)(v0 + 158);
    *(_QWORD *)(v0 + 259) = v6;
  }
  *(_BYTE *)(v0 + 74) = 0;
  if ( *(_BYTE *)(v0 + 83) == 0xB7 )
  {
    v9 = v0 + (unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259) - 21114);
    *(_QWORD *)(v0 + 149) = v9 ^ 0x71F1ABE0;
    *(_QWORD *)(v0 + 259) = *(_QWORD *)v9 + 1320112762LL - *(_QWORD *)(v0 + 158);
    if ( (unsigned __int8)*(_QWORD *)(v0 + 104) == 50 )
      *(_BYTE *)(v0 + 74) = v6 | 3;
  }
  v10 = (*(_BYTE *)(v0 + 104) - 47) & 0xF;
  if ( ((unsigned __int8)(*(_BYTE *)(v0 + 157) + 15) ^ 0x7A) == 6 )
  {
    if ( v10 == 2 )
      HIWORD(v19) = *(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259) - 21114;
    else
      v19 = *(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259) - 1320112762LL;
  }
  if ( ((unsigned __int8)(*(_BYTE *)(v0 + 157) + 15) ^ 0x7A) == 0x56 )
  {
    v11 = (_WORD *)(*(_QWORD *)(v0 + 149) ^ 0x71F1ABE0LL);
    if ( v10 == 2 )
    {
      *v11 = HIWORD(v19);
    }
    else
    {
      LOWORD(v18) = HIWORD(v19);
      *(_DWORD *)((char *)&v18 + 2) = (_DWORD)retaddr;
      HIWORD(v18) = WORD2(retaddr);
      *(_QWORD *)v11 = v18;
    }
  }
  v12 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  if ( ((unsigned __int8)(*(_BYTE *)(v0 + 157) + 15) ^ 0x7A) == 6 )
  {
    if ( ((*(_BYTE *)(v0 + 104) - 47) & 0xF) == 2 )
      *v12 -= 2LL;
    else
      *v12 -= 8LL;
  }
  v13 = 512;
  if ( ((unsigned __int8)(*(_BYTE *)(v0 + 157) + 15) ^ 0x7A) == 0x56 )
  {
    if ( (_QWORD *)(*(_QWORD *)(v0 + 149) ^ 0x71F1ABE0LL) != v12 )
      *v12 += 8LL;
    v13 = 18;
  }
  v14 = *(_QWORD *)(v0 + 84);
  v15 = *(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 3LL);
  *(_QWORD *)(v0 + 158) += v13;
  v15 -= 2004416714;
  *(_DWORD *)(v0 + 105) ^= v15;
  v16 = *(__int64 (__fastcall **)(_QWORD, __int64, _QWORD *))(8LL * (unsigned __int16)v15 + v14);
  *(_QWORD *)(v0 + 251) += 10LL;
  return v16(0, 289, v12);
}


// ===== Dp_H091_5713d @ 0x2800a713d size=0xb0 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H091_5713d()
{
  __int64 v0; // rbp
  _QWORD *v1; // rsi
  _QWORD *v2; // rdi
  int v3; // ecx
  __int64 result; // rax
  __int64 v5; // [rsp-90h] [rbp-90h]
  __int64 v6; // [rsp-18h] [rbp-18h]
  unsigned __int64 v7; // [rsp-10h] [rbp-10h]
  _UNKNOWN *retaddr; // [rsp+0h] [rbp+0h] BYREF

  v5 = **(unsigned int **)(v0 + 251);
  v1 = &retaddr;
  v2 = (_UNKNOWN **)((char *)&retaddr + v5);
  v3 = **(_DWORD **)(v0 + 251);
  if ( (_DWORD)v5 != 0 )
    v3 = 18;
  while ( v3 != 0 )
  {
    *v2++ = *v1++;
    --v3;
  }
  *(_DWORD *)(v0 + 231) = 0;
  result = v6;
  __writeeflags(v7);
  __writeeflags(v7);
  return result;
}


// ===== Dp_H092_571ed @ 0x2800a71ed size=0x1066 =====
// positive sp value has been detected, the output may be wrong!
void __fastcall Dp_H092_571ed()
{
  __int64 v0; // rbp
  int v1; // esi
  int v2; // esi
  int v3; // r8d
  int v4; // esi
  __int64 v5; // rsi
  char v6; // r9
  unsigned __int64 v7; // r14
  _QWORD *v8; // r8
  char v9; // r12
  _WORD *v10; // r9
  __int64 v11; // rax
  _QWORD *v12; // rcx
  __int64 v13; // r12
  __int64 v14; // r12
  __int64 v15; // r12
  __int64 v16; // r13
  int v17; // r8d
  __int64 v18; // r9
  _BYTE v19[14]; // [rsp-Eh] [rbp-Eh]

  *(_DWORD *)(v0 + 285) |= 0x7F84E62Au;
  v1 = *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 8LL) - *(_DWORD *)(v0 + 105) - *(_DWORD *)(v0 + 335);
  *(_DWORD *)(v0 + 105) &= v1;
  *(_DWORD *)(v0 + 335) -= 430705116;
  v2 = v1 - *(_DWORD *)(v0 + 285);
  *(_DWORD *)(v0 + 285) += 1370921919;
  *(_BYTE *)(v0 + 83) = ((unsigned __int8)(v2 & 0xF0) >> 4) ^ 0x27;
  *(_BYTE *)(v0 + 104) = (v2 & 0xF) + 112;
  v3 = *(_DWORD *)(v0 + 174)
     ^ *(_DWORD *)(v0 + 335)
     ^ (*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 9LL) - *(_DWORD *)(v0 + 105));
  *(_DWORD *)(v0 + 105) += v3;
  *(_DWORD *)(v0 + 335) ^= 0x6275B827u;
  *(_BYTE *)(v0 + 157) ^= *(_BYTE *)(v0 + 285) ^ (unsigned __int8)v3;
  *(_DWORD *)(v0 + 247) += 47602873;
  v4 = (*(_DWORD *)(v0 + 105) ^ **(_DWORD **)(v0 + 251)) - *(_DWORD *)(v0 + 307);
  *(_DWORD *)(v0 + 105) += v4;
  *(_DWORD *)(v0 + 335) += 1100449770;
  v5 = *(_DWORD *)(v0 + 285) ^ (unsigned int)v4;
  *(_DWORD *)(v0 + 285) ^= 0x2974FBC5u;
  *(_QWORD *)(v0 + 259) = (v5 ^ 0x19BCADC6) - *(_QWORD *)(v0 + 158);
  if ( (*(_BYTE *)(v0 + 83) ^ 0x27) == 2 )
  {
    v6 = *(_BYTE *)(v0 + 104) - 112;
    v7 = *(_QWORD *)(v0 + ((unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259)) ^ 0xADC6u));
    *(_QWORD *)(v0 + 149) = v7 - 802808641;
    if ( v6 == 1 )
      LOBYTE(v7) = *(_BYTE *)v7;
    if ( v6 == 2 )
      LOWORD(v7) = *(_WORD *)v7;
    if ( v6 == 3 )
      v7 = *(unsigned int *)v7;
    if ( v6 == 4 )
      v7 = *(_QWORD *)v7;
    *(_QWORD *)(v0 + 259) = (v7 ^ 0x19BCADC6) - *(_QWORD *)(v0 + 158);
  }
  *(_BYTE *)(v0 + 74) = 0;
  *(_DWORD *)(v0 + 105) -= 915432128;
  if ( (*(_BYTE *)(v0 + 83) ^ 0x27) == 1 )
  {
    v8 = (_QWORD *)(v0 + ((unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259)) ^ 0xADC6u));
    *(_QWORD *)(v0 + 149) = (char *)v8 - 802808641;
    *(_QWORD *)(v0 + 259) = (*v8 ^ 0x19BCADC6LL) - *(_QWORD *)(v0 + 158);
    if ( (unsigned __int8)*(_QWORD *)(v0 + 104) == 115 )
      *(_BYTE *)(v0 + 74) = (v0 + 105) | 3;
  }
  *(_DWORD *)(v0 + 307) ^= 0x369062C0u;
  v9 = (*(_BYTE *)(v0 + 104) - 112) & 0xF;
  if ( *(_BYTE *)(v0 + 157) == 0xDA )
  {
    if ( v9 == 2 )
      *(_WORD *)&v19[6] = (*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259)) ^ 0xADC6;
    else
      *(_QWORD *)v19 = (*(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259)) ^ 0x19BCADC6LL;
  }
  if ( *(_BYTE *)(v0 + 157) == 42 )
  {
    v10 = (_WORD *)(*(_QWORD *)(v0 + 149) + 802808641LL);
    if ( v9 == 2 )
      *v10 = *(_WORD *)&v19[6];
    else
      *(_QWORD *)v10 = *(_QWORD *)&v19[6];
  }
  v11 = v0 + 104;
  LOBYTE(v11) = (*(_BYTE *)(v0 + 104) - 112) & 0xF;
  v12 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
  v13 = 1;
  if ( *(_BYTE *)(v0 + 157) == 0xDA )
  {
    if ( (_BYTE)v11 == 2 )
    {
      *v12 -= 2LL;
    }
    else
    {
      v13 = 19;
      *v12 -= 8LL;
    }
  }
  v14 = (v13 + 86) | 0x90;
  if ( *(_BYTE *)(v0 + 157) == 42 )
  {
    v15 = v11 & v14;
    if ( (_QWORD *)(*(_QWORD *)(v0 + 149) + 802808641LL) != v12 )
    {
      v15 ^= 0xD3uLL;
      *v12 += 8LL;
    }
    v14 = v15 - 183;
  }
  v16 = *(_QWORD *)(v0 + 84);
  v17 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) -= v0 + 104 + v14;
  v17 ^= 0x3EDAA3D8u;
  *(_DWORD *)(v0 + 105) &= v17;
  v18 = *(_QWORD *)(8LL * (unsigned __int16)v17 + v16);
  *(_QWORD *)(v0 + 251) += 10LL;
  __asm { jmp     r9 }
}


// ===== Dp_H093_58253 @ 0x2800a8253 size=0x1e6 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H093_58253()
{
  __int64 v0; // rbp
  char v1; // r10
  __int64 v2; // r10
  _QWORD *v3; // rax
  _QWORD *v4; // rax
  __int64 result; // rax
  _BYTE v6[128]; // [rsp-80h] [rbp-80h]

  v1 = **(_BYTE **)(v0 + 251);
  if ( (v1 == 1 || v1 == 2)
    && *(_QWORD *)(*(_QWORD *)(v0 + 239)
                 + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 7LL)
                 + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 1LL)) != *(_QWORD *)(v0 + 239)
                                                                       + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 3LL) )
  {
    v2 = *(_QWORD *)(v0 + 239);
    v3 = (_QWORD *)(v2
                  + *(_DWORD *)(*(_QWORD *)(v0 + 251) + 7LL)
                  + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 1LL));
    *v3 -= *(_QWORD *)(v0 + 297);
    *v3 += *(_QWORD *)(v0 + 239);
    if ( **(_BYTE **)(v0 + 251) == 2 )
    {
      v4 = (_QWORD *)(v2
                    + *(_DWORD *)(*(_QWORD *)(v0 + 251) + 7LL)
                    + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 2LL));
      *v4 -= *(_QWORD *)(v0 + 297);
      *v4 += *(_QWORD *)(v0 + 239);
    }
  }
  *(_QWORD *)&v6[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 11LL)] = *(_QWORD *)(v0 + 239)
                                                                      + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 7LL);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v6[112];
  __writeeflags(*(unsigned __int64 *)&v6[120]);
  return result;
}


// ===== Dp_H094_58439 @ 0x2800a8439 size=0xb1 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H094_58439()
{
  __int64 v0; // rbp
  _QWORD *v1; // rsi
  _QWORD *v2; // rdi
  int v3; // ecx
  __int64 result; // rax
  __int64 v5; // [rsp-90h] [rbp-90h]
  __int64 v6; // [rsp-18h] [rbp-18h]
  unsigned __int64 v7; // [rsp-10h] [rbp-10h]
  _UNKNOWN *retaddr; // [rsp+0h] [rbp+0h] BYREF

  v5 = **(unsigned int **)(v0 + 251);
  v1 = &retaddr;
  v2 = (_UNKNOWN **)((char *)&retaddr + v5);
  v3 = **(_DWORD **)(v0 + 251);
  if ( (_DWORD)v5 != 0 )
    v3 = 18;
  while ( v3 != 0 )
  {
    *v2++ = *v1++;
    --v3;
  }
  *(_DWORD *)(v0 + 231) = 0;
  result = v6;
  __writeeflags(v7);
  __writeeflags(v7);
  return result;
}


// ===== Dp_H095_584ea @ 0x2800a84ea size=0x139 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H095_584ea()
{
  __int64 v0; // rbp
  _QWORD *v1; // rsi
  char v2; // r11
  __int64 v3; // r15
  _QWORD *v4; // r15
  __int64 result; // rax
  _BYTE v6[128]; // [rsp-80h] [rbp-80h] BYREF

  v2 = *(_BYTE *)(*(_QWORD *)(v0 + 251) + 10LL);
  v3 = 0;
  if ( v2 == -33 )
  {
    v3 = *(_QWORD *)(v0 + 239) + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 6LL);
    v1 = &v6[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)];
    *v1 = v3;
  }
  if ( v2 == 111 || v2 == 82 )
  {
    LOWORD(v3) = *(_WORD *)(*(_QWORD *)(v0 + 251) + 6LL);
    v4 = *(_QWORD **)(v0 + v3);
    if ( v2 == 82 )
      v4 = (_QWORD *)*v4;
    v1 = &v6[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)];
    *v1 = v4;
  }
  v1[1] = *(_QWORD *)(v0 + 239) + **(unsigned int **)(v0 + 251);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v6[112];
  __writeeflags(*(unsigned __int64 *)&v6[120]);
  return result;
}


// ===== Dp_H096_58623 @ 0x2800a8623 size=0x15ab =====
void __fastcall Dp_H096_58623()
{
  __int64 v0; // rbp
  char v1; // di
  char v2; // r11
  int v3; // r13d
  char v4; // di
  int v5; // r13d
  __int64 v6; // r13
  char v7; // cl
  int v8; // r10d
  int v9; // r10d
  char v10; // si
  char v11; // r12
  int v12; // edx
  char v13; // r11
  int v14; // edx
  char v15; // r9
  char v16; // r11
  unsigned __int64 v17; // r12
  unsigned __int64 v18; // rax
  __int64 v19; // rdi
  __int64 v20; // r15
  __int64 v21; // rbx
  __int64 v22; // rax
  unsigned __int64 v23; // kr18_8
  __int64 v24; // rcx
  char v25; // r11
  _BYTE *v26; // r11
  __int64 v27; // r15
  char v28; // r8
  __int64 v29; // rdi
  int v30; // r10d
  __int64 v31; // r8
  unsigned __int64 v32; // [rsp-20h] [rbp-20h]

  v3 = *(_DWORD *)(*(_QWORD *)(v0 + 251) + 6LL);
  v4 = v3 | v1 & 0x49 | 4;
  v5 = *(_DWORD *)(v0 + 307) ^ v3;
  *(_DWORD *)(v0 + 105) -= v5;
  *(_DWORD *)(v0 + 335) ^= 0x7F3A1EC6u;
  v6 = (unsigned int)(*(_DWORD *)(v0 + 285) + v5);
  *(_DWORD *)(v0 + 285) -= 768751587;
  v7 = ((((v4 ^ 0x8D | 0x20) + (v2 & 4) - 42) & 6) - 16) | 0xFC;
  *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) ^ (v6 - 1271167363);
  *(_DWORD *)(v0 + 247) ^= 0x6D448AF3u;
  v8 = *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 5LL) - *(_DWORD *)(v0 + 105);
  *(_DWORD *)(v0 + 105) |= v8;
  *(_DWORD *)(v0 + 335) ^= 0x7D2BAE91u;
  v9 = *(_DWORD *)(v0 + 285) ^ v8;
  *(_DWORD *)(v0 + 285) += 1295806791;
  v10 = v9;
  LOBYTE(v9) = ((unsigned __int8)(v9 & 0xF0) >> 4) + 102;
  *(_BYTE *)(v0 + 83) = v9;
  *(_BYTE *)(v0 + 104) = v10 & 0xF ^ 0x78;
  v11 = ((v0 + 83) & (v9 ^ 0x28) & 0xF0) + 0x80;
  v12 = *(_DWORD *)(v0 + 335) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 10LL) - *(_DWORD *)(v0 + 105);
  v13 = v12 & 0x40 | 0x36;
  v14 = *(_DWORD *)(v0 + 174) + v12;
  *(_DWORD *)(v0 + 105) ^= v14;
  *(_DWORD *)(v0 + 335) &= 0x220D8361u;
  LODWORD(v6) = *(_DWORD *)(v0 + 285) ^ v14;
  v15 = ((((v0 + 79) | (-17 - v11) & 0x90) - 86) & 0x12)
      + 100
      - (((v7 + 2) | 0xF7) ^ 0xD)
      + 14
      + (~(((v11 | 0x28) + 86) | 0x34) & ((~(((v11 | 0x28) + 86) | 0x34) | v13) + 49))
      + 18;
  *(_DWORD *)(v0 + 285) ^= 0x55E6441Fu;
  *(_BYTE *)(v0 + 157) -= v6;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) += 880881652;
  if ( *(_BYTE *)(v0 + 83) == 104 )
  {
    v16 = *(_BYTE *)(v0 + 104) ^ 0x78;
    v17 = *(_QWORD *)(v0 + (unsigned __int16)((*(_WORD *)(v0 + 158) ^ *(_WORD *)(v0 + 259)) + 31107));
    *(_QWORD *)(v0 + 149) = v17 ^ 0x83A3C75;
    if ( v16 == 1 )
      LOBYTE(v17) = *(_BYTE *)v17;
    if ( v16 == 2 )
      LOWORD(v17) = *(_WORD *)v17;
    if ( v16 == 3 )
      v17 = *(unsigned int *)v17;
    if ( v16 == 4 )
      v17 = *(_QWORD *)v17;
    *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) ^ (v17 - 1271167363);
  }
  *(_BYTE *)(v0 + 74) = 0;
  *(_DWORD *)(v0 + 105) += 1399264661;
  *(_DWORD *)(v0 + 307) -= 1399264661;
  if ( *(_BYTE *)(v0 + 83) == 103 )
  {
    v18 = v0 + (unsigned __int16)((*(_WORD *)(v0 + 158) ^ *(_WORD *)(v0 + 259)) + 31107);
    *(_QWORD *)(v0 + 149) = v18 ^ 0x83A3C75;
    *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) ^ (*(_QWORD *)v18 - 1271167363LL);
    if ( ((unsigned __int8)*(_QWORD *)(v0 + 104) ^ 0x78) == 3 )
      *(_BYTE *)(v0 + 74) = v15 | 3;
  }
  if ( *(_BYTE *)(v0 + 157) == 84 )
  {
    v19 = -((*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259)) + 1271167363LL);
    __readeflags();
    *(_QWORD *)(v0 + 327) = v19 ^ 0x22D9AD41;
  }
  *(_DWORD *)(v0 + 247) ^= 0x7EFAA09Bu;
  *(_DWORD *)(v0 + 105) ^= 0x5365BA32u;
  *(_DWORD *)(v0 + 105) -= 395908873;
  if ( *(_BYTE *)(v0 + 157) == 59 )
  {
    v20 = (*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259)) + 1271167364LL;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v20 ^ 0x22D9AD41;
  }
  if ( *(_BYTE *)(v0 + 157) == 0xDC )
  {
    v21 = (*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259)) + 1271167362LL;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v21 ^ 0x22D9AD41;
  }
  if ( *(_BYTE *)(v0 + 157) == 0x9A )
  {
    v22 = ~((*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259)) + 1271167363LL);
    v23 = __readeflags();
    v32 = v23;
    *(_QWORD *)(v0 + 327) = v22 ^ 0x22D9AD41;
  }
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 4LL) != 0 )
    *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251)) = v32;
  *(_DWORD *)(v0 + 105) ^= 0x21FDE6D2u;
  *(_DWORD *)(v0 + 335) -= 486547954;
  v24 = *(_DWORD *)(v0 + 335) & 1;
  v25 = *(_BYTE *)(v0 + 157) - 43;
  if ( (_DWORD)v24 != 0 )
    *(_DWORD *)(v0 + 335) |= 0x76855776u;
  if ( v25 != 118 && *(_BYTE *)(v0 + 157) != 0xC6 )
  {
    v26 = (_BYTE *)(*(_QWORD *)(v0 + 149) ^ 0x83A3C75LL);
    v27 = *(_QWORD *)(v0 + 327) ^ 0x22D9AD41LL;
    v28 = *(_BYTE *)(v0 + 104) ^ 0x78;
    if ( v28 == 1 )
      *v26 = v27;
    if ( v28 == 2 )
      *(_WORD *)v26 = v27;
    if ( v28 == 3 )
    {
      *(_DWORD *)v26 = v27;
      v24 = v0 + 74;
      LOBYTE(v27) = *(_BYTE *)(v0 + 74);
      if ( (_BYTE)v27 != 0 )
      {
        v26 += 4;
        *(_DWORD *)v26 = 0;
      }
    }
    if ( v28 == 4 )
      *(_QWORD *)v26 = v27;
  }
  v29 = *(_QWORD *)(v0 + 84);
  v30 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) += v24 + 1168;
  v30 ^= 0x5FF08C6Bu;
  *(_DWORD *)(v0 + 105) ^= v30;
  v31 = *(_QWORD *)(8LL * (unsigned __int16)v30 + v29);
  *(_QWORD *)(v0 + 251) += 11LL;
  __asm { jmp     r8 }
}


// ===== Dp_H097_59bce @ 0x2800a9bce size=0xb0 =====
__int64 __fastcall Dp_H097_59bce()
{
  __int64 v0; // rbp
  _QWORD *v1; // r11
  __int64 v2; // rdx
  int v3; // r9d
  __int64 (*v4)(void); // rdi

  v1 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 1LL));
  *v1 += **(unsigned __int8 **)(v0 + 251);
  v2 = *(_QWORD *)(v0 + 84);
  v3 = (*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 3LL) - *(_DWORD *)(v0 + 105)) ^ 0x27D983E0;
  *(_DWORD *)(v0 + 105) |= v3;
  v4 = *(__int64 (**)(void))(8LL * (unsigned __int16)v3 + v2);
  *(_QWORD *)(v0 + 251) += 5LL;
  return v4();
}


// ===== Dp_H098_59c7e @ 0x2800a9c7e size=0x39d =====
__int64 __fastcall Dp_H098_59c7e()
{
  __int64 v0; // rbp
  unsigned __int64 v1; // kr00_8
  _QWORD *v2; // rdx
  _QWORD *v3; // r9
  unsigned __int64 *v4; // rsi
  __int64 v5; // rbx
  int v6; // edx
  __int64 v7; // rdx
  __int64 (__fastcall *v8)(_QWORD, __int64, __int64); // rcx

  *(_DWORD *)(v0 + 105) &= 0x364FEE30u;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) |= 0x364FEE30u;
  *(_DWORD *)(v0 + 105) += 507848402;
  *(_DWORD *)(v0 + 335) &= 0x35775243u;
  *(_DWORD *)(v0 + 105) -= 499828232;
  v1 = __readeflags();
  v2 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL));
  v3 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) & 0x400LL) != 0 )
  {
    *v3 -= 2LL;
    *v2 -= 2LL;
  }
  else
  {
    *v3 += 2LL;
    *v2 += 2LL;
  }
  v4 = (unsigned __int64 *)*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 6LL);
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 6LL) != 0 )
  {
    v4 = (unsigned __int64 *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
    *v4 = v1;
  }
  v5 = *(_QWORD *)(v0 + 84);
  v6 = *(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 7LL);
  *(_QWORD *)(v0 + 158) ^= (unsigned __int64)v4 - ((v0 + 84) | 0x90);
  v6 -= 846871297;
  *(_DWORD *)(v0 + 105) |= v6;
  v7 = 8LL * (unsigned __int16)v6;
  v8 = *(__int64 (__fastcall **)(_QWORD, __int64, __int64))(v7 + v5);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v8(v8, v7, 131);
}


// ===== Dp_H099_5a01b @ 0x2800aa01b size=0x251 =====
__int64 __fastcall Dp_H099_5a01b()
{
  __int64 v0; // rbp
  __int64 v1; // r12
  unsigned __int16 *v2; // r14
  _QWORD *v3; // r10
  _QWORD *v4; // rdi
  __int64 v5; // rdi
  int v6; // r14d
  __int64 (__fastcall *v7)(__int64, __int64, __int64, __int64); // rax

  *(_DWORD *)(v0 + 105) |= 0x39C9D8A8u;
  *(_DWORD *)(v0 + 307) ^= 0x39C9D8A8u;
  v2 = *(unsigned __int16 **)(v0 + 251);
  *(_DWORD *)(v0 + 105) &= 0x2A269D3Au;
  **(_DWORD **)(v0 + *v2) = **(_DWORD **)(v0 + v2[2]);
  v3 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  v4 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) & 0x400LL) != 0 )
  {
    *v3 -= 4LL;
    *v4 -= 4LL;
  }
  else
  {
    *v3 += 4LL;
    *v4 += 4LL;
  }
  v5 = *(_QWORD *)(v0 + 84);
  v6 = (*(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL)) + 1155619332;
  *(_DWORD *)(v0 + 105) += v6;
  v7 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(8LL * (unsigned __int16)v6 + v5);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v7(v0 + 158, v1, -146, (((unsigned __int16)v5 ^ 0xF) & 0x400) - v1);
}


// ===== Dp_H101_5a4d8 @ 0x2800aa4d8 size=0x4ce =====
__int64 __fastcall Dp_H101_5a4d8()
{
  __int64 v0; // rbp
  __int64 v1; // r8
  __int64 v2; // r15
  __int64 v3; // rdx
  _QWORD *v4; // rax
  __int64 v5; // rbx
  unsigned __int16 v6; // r15
  __int64 v7; // rbx
  _QWORD *v8; // r12
  __int64 v9; // rbx
  __int64 v10; // r14
  int v11; // r12d
  __int64 v12; // rdx
  __int64 (__fastcall *v13)(__int64, __int64, __int64); // rax
  __int64 v14; // rcx

  *(_DWORD *)(v0 + 247) ^= 0x2279DB12u;
  *(_DWORD *)(v0 + 105) ^= 0x3206D5B7u;
  *(_DWORD *)(v0 + 307) |= 0x3206D5B7u;
  **(_DWORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) = **(_DWORD **)(v0
                                                                                       + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
  v1 = *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL)) & 0x400LL;
  v2 = (30 - v1 - 366) | 0x78;
  v3 = v2 - 1;
  v4 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  v5 = v2 + (v0 ^ 0x56);
  v6 = v2 ^ 0x73;
  v7 = v5 - 144;
  v8 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | v1) != 0 )
  {
    *v4 -= 4LL;
    *v8 -= 4LL;
  }
  else
  {
    v9 = v7 | 0xFFFF;
    *v4 += 4LL;
    *v8 += 4LL;
    v6 = (unsigned __int16)v4 | ((_BYTE)v6 - (_BYTE)v9) & 0x90;
    v7 = v9 - 131;
  }
  v10 = *(_QWORD *)(v0 + 84);
  v11 = *(_DWORD *)(v0 + 105) + **(unsigned __int16 **)(v0 + 251);
  v12 = v7 + v3;
  *(_QWORD *)(v0 + 158) -= v12;
  v11 ^= 0x71573C87u;
  *(_DWORD *)(v0 + 105) -= v11;
  v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(8LL * (unsigned __int16)v11 + v10);
  v14 = ((((v0 + 105) & 0x74) - 131) | 6) ^ 0xFFFF;
  *(_QWORD *)(v0 + 251) += 8LL;
  return v13(v14, v12, (((v6 | 1) - 240) & 0x800 ^ 0x44LL) - 22 - v14);
}


// ===== Dp_H102_5a9a6 @ 0x2800aa9a6 size=0x43d =====
__int64 __fastcall Dp_H102_5a9a6()
{
  __int64 v0; // rbp
  __int64 v1; // r13
  __int64 v2; // r12
  __int16 v3; // ax
  _WORD *v4; // r12
  unsigned __int16 *v5; // r14
  __int64 v6; // rdi
  __int16 v7; // ax
  _QWORD *v8; // r14
  _QWORD *v9; // r8
  __int64 v10; // rax
  __int64 v11; // r8
  int v12; // edi
  __int64 (__fastcall *v13)(_QWORD); // r13

  *(_DWORD *)(v0 + 105) &= 0x175900AAu;
  v2 = *(_QWORD *)(v0 + 251);
  *(_DWORD *)(v0 + 307) += 391708842;
  v3 = v2 + 2;
  v4 = *(_WORD **)(v0 + *(unsigned __int16 *)(v2 + 2));
  LOWORD(v1) = *v4;
  **(_WORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL)) = *v4;
  v5 = *(unsigned __int16 **)(v0 + 251);
  v6 = *(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *v5) & 0x400LL;
  v7 = (v0 + 307)
     & (unsigned __int16)v5
     & ((v0 + 251)
      ^ (v0 + 307)
      & (((((((unsigned __int16)v5 & (((v3 ^ 0xF2) - 30) | 0xD3) ^ 0xF) & 2 | 0xA8) + 7) ^ 0x83) - (_WORD)v4) | 0xF9)
      ^ 0xF);
  v8 = (_QWORD *)(v0 + v5[3]);
  v9 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  if ( v6 != 0 )
  {
    v10 = (unsigned __int8)v7 & 0x93;
    *v8 -= 2LL;
    *v9 -= 2LL;
  }
  else
  {
    *v8 += 2LL;
    v10 = (v0 + 28) ^ ((unsigned __int16)(v7 - 86) - 4LL);
    *v9 += 2LL;
  }
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) -= 2040725601;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) &= 0x241C72ABu;
  v11 = *(_QWORD *)(v0 + 84);
  v12 = *(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL);
  *(_QWORD *)(v0 + 158) ^= 2 * v1 - (v10 | 0x800);
  v12 += 1066313297;
  *(_DWORD *)(v0 + 105) += v12;
  v13 = *(__int64 (__fastcall **)(_QWORD))(8LL * (unsigned __int16)v12 + v11);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v13(((_BYTE)v0 - 98 + 26) & 0x2A);
}


// ===== Dp_H103_5ade3 @ 0x2800aade3 size=0x1f8 =====
__int64 __fastcall Dp_H103_5ade3(__int64 a1, __int64 a2, __int64 a3)
{
  char v3; // bl
  __int64 v4; // rbp
  char v5; // r13
  __int64 v6; // rcx
  __int64 (__fastcall *v7)(__int64, __int64, __int64, __int64); // r12
  char v8; // r13
  __int64 v9; // rsi
  __int64 v10; // r9

  v6 = 8LL * **(unsigned __int16 **)(v4 + 251) + *(_QWORD *)(v4 + 84);
  v7 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))v6;
  v8 = ((((v3 & a3 & v5) - 86 - (a3 + 117) - 4 + 82) & 0xC2 | 0x20) - v6 - 15) | 0x31;
  v9 = *(unsigned int *)(*(_QWORD *)(v4 + 251) + 4LL);
  if ( (int)v9 >= 0 )
  {
    v10 = (v8 & 0x84 | 0x33u)
        - 30LL
        + (((((((v6 | 0x83) + 0xFFFF) | 0x83) + 1024) ^ 0xF9) + 242 - *(_QWORD *)v6) | (*(_QWORD *)v6 | 1LL) ^ 0xF2)
        - (_QWORD)v7;
    *(_QWORD *)(v4 + 251) += v9;
  }
  else
  {
    v10 = v4;
    *(_QWORD *)(v4 + 251) -= v9 & 0x7FFFFFFF;
  }
  return v7(v6, a2, a3, v10);
}


// ===== Dp_H104_5afdb @ 0x2800aafdb size=0xb1 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H104_5afdb()
{
  __int64 v0; // rbp
  _QWORD *v1; // rsi
  _QWORD *v2; // rdi
  int v3; // ecx
  __int64 result; // rax
  __int64 v5; // [rsp-90h] [rbp-90h]
  __int64 v6; // [rsp-18h] [rbp-18h]
  unsigned __int64 v7; // [rsp-10h] [rbp-10h]
  _UNKNOWN *retaddr; // [rsp+0h] [rbp+0h] BYREF

  v5 = **(unsigned int **)(v0 + 251);
  v1 = &retaddr;
  v2 = (_UNKNOWN **)((char *)&retaddr + v5);
  v3 = **(_DWORD **)(v0 + 251);
  if ( (_DWORD)v5 != 0 )
    v3 = 18;
  while ( v3 != 0 )
  {
    *v2++ = *v1++;
    --v3;
  }
  *(_DWORD *)(v0 + 231) = 0;
  result = v6;
  __writeeflags(v7);
  __writeeflags(v7);
  return result;
}


// ===== Dp_H105_5b08c @ 0x2800ab08c size=0x28a =====
__int64 __fastcall Dp_H105_5b08c()
{
  __int64 v0; // rbx
  __int64 v1; // rbp
  __int64 v2; // r13
  __int64 v3; // rdx
  __int64 v4; // rdx
  _QWORD *v5; // rdi
  _QWORD *v6; // r15
  __int64 v7; // rdi
  int v8; // ecx
  __int64 v9; // rcx
  __int64 (__fastcall *v10)(__int64, __int64, _QWORD); // r12

  v3 = *(_QWORD *)(v1 + 251);
  if ( (*(_DWORD *)(v1 + 335) & 1) != 0 )
    *(_DWORD *)(v1 + 335) ^= 0x34E5154Cu;
  LOWORD(v2) = **(_WORD **)(v1 + *(unsigned __int16 *)(v3 + 2));
  **(_WORD **)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 6LL)) = v2;
  v4 = *(_DWORD *)(v1 + 28) & 0x400LL;
  v5 = (_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 2LL));
  v6 = (_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 6LL));
  if ( (v4 | *(_QWORD *)(v1 + **(unsigned __int16 **)(v1 + 251)) & 0x400LL) != 0 )
  {
    *v6 -= 2LL;
    *v5 -= 2LL;
  }
  else
  {
    *v6 += 2LL;
    *v5 += 2LL;
  }
  *(_DWORD *)(v1 + 105) &= 0xBE3E5EDu;
  v7 = *(_QWORD *)(v1 + 84);
  v8 = *(_DWORD *)(v1 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 4LL);
  *(_QWORD *)(v1 + 158) -= v2 - v0;
  v8 ^= 0x11308BA9u;
  *(_DWORD *)(v1 + 105) -= v8;
  v9 = 8LL * (unsigned __int16)v8;
  v10 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD))(v9 + v7);
  *(_QWORD *)(v1 + 251) += 8LL;
  return v10(v9, v4, 0);
}


// ===== Dp_H106_5b316 @ 0x2800ab316 size=0x20b =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H106_5b316(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rbp
  __int64 v4; // r9
  __int64 v5; // r9
  unsigned __int16 *v6; // rax
  __int64 v7; // r14
  int v8; // r10d
  __int64 (__fastcall *v9)(__int64, __int64); // r11
  __int64 v11; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v3 + 247) |= 0x35DBEE75u;
  v4 = *(_QWORD *)(v3 + 251);
  *(_DWORD *)(v3 + 105) |= 0x4FAFE5B0u;
  v5 = *(unsigned __int16 *)(v4 + 2);
  v6 = *(unsigned __int16 **)(v3 + 251);
  *(_DWORD *)(v3 + 307) &= 0x4FAFE5B0u;
  *(_QWORD *)(v3 + *v6) = v11;
  *(_QWORD *)(v3 + v5) += 8LL;
  *(_DWORD *)(v3 + 247) ^= 0x194B7493u;
  v7 = *(_QWORD *)(v3 + 84);
  v8 = *(_DWORD *)(v3 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v3 + 251) + 4LL);
  *(_QWORD *)(v3 + 158) += (v3 + 105) ^ a3;
  v8 ^= 0x4ADE694Au;
  *(_DWORD *)(v3 + 105) -= v8;
  v9 = *(__int64 (__fastcall **)(__int64, __int64))(8LL * (unsigned __int16)v8 + v7);
  *(_QWORD *)(v3 + 251) += 6LL;
  return v9(
           (((v7 & 0x10) - 7) & 0x34) + 64,
           ((((((unsigned int)v7 ^ ((_DWORD)v3 + 105) & 0x200) & 0x7FFFFFFF) - 64LL) ^ 0x1E) + 1024) | 0xD3);
}


// ===== Dp_H107_5b521 @ 0x2800ab521 size=0x268 =====
void __fastcall Dp_H107_5b521()
{
  __int64 v0; // rbp
  _QWORD *v1; // r9
  __int64 v2; // rdi
  int v3; // r14d
  __int64 v4; // rdx

  *(_DWORD *)(v0 + 105) += 1246870156;
  v1 = (_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  *v1 -= 8LL;
  *(_DWORD *)(v0 + 285) |= 0x3873D721u;
  *(_DWORD *)(v0 + 105) |= 0x7C11CDD5u;
  *(_DWORD *)(v0 + 247) &= 0x144650C9u;
  v2 = *(_QWORD *)(v0 + 84);
  v3 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) += v0 + 105;
  v3 += 105319052;
  *(_DWORD *)(v0 + 105) &= v3;
  v4 = *(_QWORD *)(8LL * (unsigned __int16)v3 + v2);
  *(_QWORD *)(v0 + 251) += 6LL;
  __asm { jmp     rdx }
}


// ===== Dp_H108_5b789 @ 0x2800ab789 size=0x78 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H108_5b789()
{
  __int64 v0; // rbp
  __int64 result; // rax
  _BYTE v2[128]; // [rsp-80h] [rbp-80h]

  *(_QWORD *)&v2[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)] = **(_QWORD **)(v0
                                                                                   + **(unsigned __int16 **)(v0 + 251));
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v2[112];
  __writeeflags(*(unsigned __int64 *)&v2[120]);
  return result;
}


// ===== Dp_H110_5c6ff @ 0x2800ac6ff size=0x1e7 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H110_5c6ff()
{
  __int64 v0; // rbp
  char v1; // al
  __int64 v2; // rax
  _QWORD *v3; // rbx
  _QWORD *v4; // rbx
  __int64 result; // rax
  _BYTE v6[128]; // [rsp-80h] [rbp-80h]

  v1 = **(_BYTE **)(v0 + 251);
  if ( (v1 == 1 || v1 == 2)
    && *(_QWORD *)(*(_QWORD *)(v0 + 239)
                 + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 7LL)
                 + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 1LL)) != *(_QWORD *)(v0 + 239)
                                                                       + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 3LL) )
  {
    v2 = *(_QWORD *)(v0 + 239);
    v3 = (_QWORD *)(v2
                  + *(_DWORD *)(*(_QWORD *)(v0 + 251) + 7LL)
                  + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 1LL));
    *v3 -= *(_QWORD *)(v0 + 297);
    *v3 += *(_QWORD *)(v0 + 239);
    if ( **(_BYTE **)(v0 + 251) == 2 )
    {
      v4 = (_QWORD *)(v2
                    + *(_DWORD *)(*(_QWORD *)(v0 + 251) + 7LL)
                    + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 2LL));
      *v4 -= *(_QWORD *)(v0 + 297);
      *v4 += *(_QWORD *)(v0 + 239);
    }
  }
  *(_QWORD *)&v6[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 11LL)] = *(_QWORD *)(v0 + 239)
                                                                      + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 7LL);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v6[112];
  __writeeflags(*(unsigned __int64 *)&v6[120]);
  return result;
}


// ===== Dp_H111_5c8e6 @ 0x2800ac8e6 size=0x4b3 =====
__int64 __fastcall Dp_H111_5c8e6()
{
  __int64 v0; // rbp
  _WORD *v1; // r13
  __int64 v2; // rsi
  unsigned __int64 v3; // kr00_8
  _QWORD *v4; // rax
  int v5; // ebx
  __int64 v6; // r13
  __int64 v7; // rbx
  __int64 (__fastcall *v8)(__int64, __int64, __int64); // r15

  *(_DWORD *)(v0 + 285) -= 788484711;
  *(_DWORD *)(v0 + 105) -= 2006981248;
  *(_DWORD *)(v0 + 335) &= 0x2EFF5267u;
  v1 = *(_WORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  v2 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL);
  *v1 -= *(_QWORD *)(v0 + v2);
  v3 = __readeflags();
  v4 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) & 0x400LL) != 0 )
    *v4 -= 2LL;
  else
    *v4 += 2LL;
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 8LL) != 0 )
    *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 9LL)) = v3;
  v5 = **(unsigned __int16 **)(v0 + 251);
  v6 = *(_QWORD *)(v0 + 84);
  *(_QWORD *)(v0 + 158) += ((v0 + 105) | 4) ^ (v2 | 0x7FFFFFFD) ^ 0xFDFF;
  v5 += 1101042951;
  *(_DWORD *)(v0 + 105) -= v5;
  v7 = 8LL * (unsigned __int16)v5;
  v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v7 + v6);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v8(((v0 + 44) | 0x800) ^ 0x34, v0 + 105, 128 - v7);
}


// ===== Dp_H112_5cd99 @ 0x2800acd99 size=0x394 =====
__int64 __fastcall Dp_H112_5cd99(__int64 a1, __int64 a2, __int64 a3, __int16 a4)
{
  __int64 v4; // rbp
  __int16 v5; // r9
  __int64 v6; // r14
  __int64 v7; // r8
  int v8; // ebx
  unsigned __int8 v9; // dl
  __int64 (__fastcall **v10)(_QWORD, __int64, _QWORD, _QWORD); // r8
  __int64 (__fastcall *v11)(_QWORD, __int64, _QWORD, _QWORD); // r10
  _WORD **v13; // [rsp-8h] [rbp-8h]

  v5 = a4 | 0x5CBB;
  if ( (*(_DWORD *)(v4 + 335) & 1) != 0 )
    *(_DWORD *)(v4 + 335) ^= 0x70E2E31u;
  *(_DWORD *)(v4 + 105) ^= 0x70E2E31u;
  v13 = (_WORD **)(v4 + *(unsigned __int16 *)(*(_QWORD *)(v4 + 251) + 6LL));
  **v13 = *(_QWORD *)(v4 + **(unsigned __int16 **)(v4 + 251));
  v6 = 0;
  if ( (*(_QWORD *)(v4 + *(unsigned __int16 *)(*(_QWORD *)(v4 + 251) + 2LL)) & 0x400LL) != 0 )
  {
    --*v13;
  }
  else
  {
    ++*v13;
    v6 = 226;
  }
  v7 = *(_QWORD *)(v4 + 84);
  v8 = *(unsigned __int16 *)(*(_QWORD *)(v4 + 251) + 4LL);
  v9 = v8 + v7;
  *(_QWORD *)(v4 + 158) += v6 ^ 0xF;
  *(_DWORD *)(v4 + 105) += v8;
  v10 = (__int64 (__fastcall **)(_QWORD, __int64, _QWORD, _QWORD))(8LL * (unsigned __int16)v8 + v7);
  v11 = *v10;
  *(_QWORD *)(v4 + 251) += 8LL;
  return v11(0, (((v9 & 0xD3) + 155LL) | 0x60) + 242, v10, (unsigned __int16)(((v5 - 323) ^ 0xB7) + 2052) ^ 0xC3u);
}


// ===== Dp_H113_5d12d @ 0x2800ad12d size=0x312 =====
__int64 __fastcall Dp_H113_5d12d()
{
  __int64 v0; // rbp
  _BYTE **v1; // rdx
  __int64 v2; // rdi
  unsigned __int64 v3; // rdx
  unsigned __int64 v4; // r12
  __int64 v5; // rdi
  int v6; // ecx
  __int64 v7; // rcx
  __int64 (__fastcall *v8)(__int64, __int64, __int64, __int64); // r12
  _QWORD *v10; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v0 + 285) += 1539536179;
  *(_DWORD *)(v0 + 105) += 79865802;
  *(_DWORD *)(v0 + 307) ^= 0x4C2A7CAu;
  *(_DWORD *)(v0 + 105) &= 0x6771CC37u;
  *(_DWORD *)(v0 + 307) |= 0x6771CC37u;
  *(_DWORD *)(v0 + 105) ^= 0x49B5B390u;
  *(_DWORD *)(v0 + 247) ^= 0x14F80501u;
  v1 = (_BYTE **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  v2 = (unsigned __int16)v1 & 0x3F1;
  v10 = v1;
  v3 = (unsigned __int64)*v1;
  LOBYTE(v3) = *(_BYTE *)v3;
  *(_BYTE *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) = v3;
  v4 = (((v3 & (v2 ^ 8)) - 163) ^ 0xFFFFFFFFFFFFFF5DuLL) + 100;
  if ( (*(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL)) & 0x400LL) != 0 )
    --*v10;
  else
    ++*v10;
  v5 = *(_QWORD *)(v0 + 84);
  v6 = **(unsigned __int16 **)(v0 + 251);
  *(_QWORD *)(v0 + 158) ^= ((v0 + v0 + 307 - 4) ^ 0x801 | 0x800) ^ v4;
  v6 += 1376083519;
  *(_DWORD *)(v0 + 105) ^= v6;
  v7 = 8LL * (unsigned __int16)v6;
  v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v7 + v5);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v8(v7, v0 + 105, (v5 | 0x2A) + 195, 2545);
}


// ===== Dp_H114_5d43f @ 0x2800ad43f size=0x66a =====
__int64 __fastcall Dp_H114_5d43f()
{
  __int64 v0; // rbp
  int v1; // r15d
  __int64 v2; // r15
  int v3; // edx
  __int64 v4; // rdx
  int v5; // esi
  int v6; // esi
  int v7; // ecx
  char v8; // r15
  _BYTE *v9; // rdi
  char v10; // di
  _BYTE *v11; // rbx
  _BYTE *v12; // r8
  _QWORD *v13; // rdi
  _QWORD *v14; // r13
  __int64 v15; // r10
  _BYTE *v16; // rcx
  char v17; // di
  __int64 v18; // r10
  _BYTE *v19; // r14
  __int64 v20; // rsi
  int v21; // ebx
  __int64 (__fastcall *v22)(_BYTE *, __int64, _BYTE *); // rax

  v1 = *(_DWORD *)(*(_QWORD *)(v0 + 251) + 6LL) - *(_DWORD *)(v0 + 105) - *(_DWORD *)(v0 + 335);
  *(_DWORD *)(v0 + 105) += v1;
  *(_DWORD *)(v0 + 335) |= 0x764AA5BAu;
  v2 = *(_DWORD *)(v0 + 285) ^ (unsigned int)v1;
  *(_DWORD *)(v0 + 285) ^= 0x7CE20F80u;
  *(_QWORD *)(v0 + 210) = *(_QWORD *)(v0 + 158) + v2 + 501456899;
  v3 = *(_DWORD *)(v0 + 307) + (*(_DWORD *)(v0 + 105) ^ *(_DWORD *)(*(_QWORD *)(v0 + 251) + 2LL));
  *(_DWORD *)(v0 + 105) -= v3;
  *(_DWORD *)(v0 + 335) += 237926266;
  v4 = *(_DWORD *)(v0 + 285) ^ (unsigned int)v3;
  *(_DWORD *)(v0 + 285) ^= 0x256E1F3Bu;
  *(_QWORD *)(v0 + 259) = v4 + 1454123907 - *(_QWORD *)(v0 + 158);
  v5 = *(_DWORD *)(v0 + 105) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 11LL) - *(_DWORD *)(v0 + 335);
  *(_DWORD *)(v0 + 105) -= v5;
  *(_DWORD *)(v0 + 335) -= 1530513161;
  v6 = *(_DWORD *)(v0 + 285) + v5;
  *(_DWORD *)(v0 + 285) ^= 0x6303A84Bu;
  *(_BYTE *)(v0 + 57) = ((unsigned __int8)(v6 & 0xF0) >> 4) - 7;
  *(_BYTE *)(v0 + 218) = (v6 & 0xF) + 105;
  v7 = *(_DWORD *)(v0 + 335) ^ (*(_DWORD *)(v0 + 105) + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 10LL));
  *(_DWORD *)(v0 + 105) ^= v7;
  *(_DWORD *)(v0 + 335) -= 1491997877;
  *(_DWORD *)(v0 + 285) &= 0x2EBA04EBu;
  *(_BYTE *)(v0 + 83) = ((unsigned __int8)(v7 & 0xF0) >> 4) - 66;
  *(_BYTE *)(v0 + 104) = (v7 & 0xF) - 54;
  if ( *(_BYTE *)(v0 + 83) == 0xC0 )
  {
    v8 = *(_BYTE *)(v0 + 104) + 54;
    v9 = *(_BYTE **)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259) - 11139));
    *(_QWORD *)(v0 + 149) = v9 - 15932777;
    if ( v8 == 1 )
      LOBYTE(v9) = *v9;
    if ( v8 == 2 )
      LOWORD(v9) = *(_WORD *)v9;
    if ( v8 == 3 )
      v9 = (_BYTE *)*(unsigned int *)v9;
    if ( v8 == 4 )
      v9 = *(_BYTE **)v9;
    *(_QWORD *)(v0 + 259) = &v9[-*(_QWORD *)(v0 + 158) + 1454123907];
  }
  if ( *(_BYTE *)(v0 + 57) == 0xFB )
  {
    v10 = *(_BYTE *)(v0 + 218) - 105;
    v11 = *(_BYTE **)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 210) + 24573 - *(_WORD *)(v0 + 158)));
    *(_QWORD *)(v0 + 141) = v11 - 15932777;
    if ( v10 == 1 )
      LOBYTE(v11) = *v11;
    if ( v10 == 2 )
      LOWORD(v11) = *(_WORD *)v11;
    if ( v10 == 3 )
      v11 = (_BYTE *)*(unsigned int *)v11;
    if ( v10 == 4 )
      v11 = *(_BYTE **)v11;
    *(_QWORD *)(v0 + 210) = &v11[*(_QWORD *)(v0 + 158) + 501456899];
  }
  *(_BYTE *)(v0 + 74) = 0;
  v12 = (_BYTE *)(v0 + 83);
  if ( *(_BYTE *)(v0 + 57) == 0xFA )
  {
    v13 = (_QWORD *)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 210) + 24573 - *(_WORD *)(v0 + 158)));
    *(_QWORD *)(v0 + 141) = (char *)v13 - 15932777;
    *(_QWORD *)(v0 + 210) = *(_QWORD *)(v0 + 158) + *v13 + 501456899LL;
  }
  if ( *v12 == 0xBF )
  {
    v14 = (_QWORD *)(v0 + (unsigned __int16)(*(_WORD *)(v0 + 158) + *(_WORD *)(v0 + 259) - 11139));
    *(_QWORD *)(v0 + 149) = (char *)v14 - 15932777;
    *(_QWORD *)(v0 + 259) = *v14 + 1454123907LL - *(_QWORD *)(v0 + 158);
    v12 = (_BYTE *)(v0 + 104);
    if ( (unsigned __int8)*(_QWORD *)(v0 + 104) == 0xCD )
    {
      v12 = (_BYTE *)(v0 + 74);
      *(_BYTE *)(v0 + 74) = (v0 + 74) | 3;
    }
  }
  v15 = *(_QWORD *)(v0 + 158) + *(_QWORD *)(v0 + 259) - 1454123907LL;
  v16 = (_BYTE *)(*(_QWORD *)(v0 + 141) + 15932777LL);
  v17 = *(_BYTE *)(v0 + 104) + 54;
  if ( *(_BYTE *)(v0 + 104) == 0xCB )
    *v16 = *(_BYTE *)(v0 + 158) + *(_BYTE *)(v0 + 259) + 125;
  if ( v17 == 2 )
    *(_WORD *)v16 = v15;
  if ( v17 == 3 )
    *(_DWORD *)v16 = v15;
  if ( v17 == 4 )
    *(_QWORD *)v16 = v15;
  v18 = *(_QWORD *)(v0 + 210) - 501456899LL - *(_QWORD *)(v0 + 158);
  v19 = (_BYTE *)(*(_QWORD *)(v0 + 149) + 15932777LL);
  if ( v17 == 1 )
    *v19 = v18;
  if ( v17 == 2 )
    *(_WORD *)v19 = v18;
  if ( v17 == 3 )
    *(_DWORD *)v19 = v18;
  if ( v17 == 4 )
    *(_QWORD *)v19 = v18;
  v20 = *(_QWORD *)(v0 + 84);
  v21 = (*(_DWORD *)(v0 + 105) ^ **(unsigned __int16 **)(v0 + 251)) + 378845015;
  *(_DWORD *)(v0 + 105) -= v21;
  v22 = *(__int64 (__fastcall **)(_BYTE *, __int64, _BYTE *))(8LL * (unsigned __int16)v21 + v20);
  *(_QWORD *)(v0 + 251) += 12LL;
  return v22(v16, v0 + 149, &v12[-v18]);
}


// ===== Dp_H115_5daa9 @ 0x2800adaa9 size=0x523 =====
__int64 __fastcall Dp_H115_5daa9()
{
  __int64 v0; // rbp
  __int64 v1; // rdx
  __int16 v2; // dx
  unsigned __int64 v3; // kr00_8
  _QWORD *v4; // rcx
  _QWORD *v5; // r8
  _BYTE *v6; // r10
  __int64 v7; // r15
  int v8; // r11d
  __int64 (__fastcall *v9)(__int64); // r8

  v1 = *(_QWORD *)(v0 + 251);
  *(_DWORD *)(v0 + 247) += 508822945;
  v2 = *(_WORD *)(v1 + 2);
  v3 = __readeflags();
  v4 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
  v5 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 8LL)) & 0x400LL) != 0 )
  {
    --*v5;
    --*v4;
  }
  else
  {
    ++*v5;
    ++*v4;
  }
  v6 = (_BYTE *)(*(_QWORD *)(v0 + 251) + 10LL);
  *(_DWORD *)(v0 + 105) -= 1003430100;
  if ( *v6 != 0 )
    *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251)) = v3;
  *(_DWORD *)(v0 + 307) &= 0x3BCF20D4u;
  *(_DWORD *)(v0 + 105) ^= 0x6CC15706u;
  *(_DWORD *)(v0 + 335) += 632981484;
  *(_DWORD *)(v0 + 285) ^= 0x25BA87ECu;
  v7 = *(_QWORD *)(v0 + 84);
  v8 = *(_DWORD *)(v0 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL);
  *(_QWORD *)(v0 + 158) ^= 1003430100LL - ((unsigned __int8)(-12 - v2 - 96 + 16) & 0x90);
  v8 += 1678295551;
  *(_DWORD *)(v0 + 105) ^= v8;
  v9 = *(__int64 (__fastcall **)(__int64))(8LL * (unsigned __int16)v8 + v7);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v9((v0 + 105) & 1);
}


// ===== Dp_H116_5dfcc @ 0x2800adfcc size=0x7e =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H116_5dfcc()
{
  __int64 v0; // rbp
  __int64 result; // rax
  _BYTE v2[128]; // [rsp-80h] [rbp-80h]

  *(_QWORD *)&v2[**(unsigned __int16 **)(v0 + 251)] = *(_QWORD *)(v0 + 239)
                                                    + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 2LL);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v2[112];
  __writeeflags(*(unsigned __int64 *)&v2[120]);
  return result;
}


// ===== Dp_H117_5e04a @ 0x2800ae04a size=0x1845 =====
void __fastcall Dp_H117_5e04a()
{
  __int64 v0; // rbp
  int v1; // edx
  int v2; // edx
  int v3; // esi
  int v4; // esi
  int v5; // r12d
  __int64 v6; // r12
  unsigned __int64 v7; // rcx
  char v8; // dl
  char v9; // r14
  unsigned __int64 v10; // r12
  char v11; // r15
  __int64 v12; // r10
  __int64 v13; // r12
  __int64 v14; // rdx
  __int64 v15; // r13
  __int64 v16; // rax
  __int64 v17; // rcx
  __int64 v18; // r12
  char v19; // r13
  __int64 v20; // rax
  char v21; // r13
  __int64 v22; // r8
  unsigned __int16 *v23; // rcx
  __int64 v24; // r10
  __int64 v25; // r9
  unsigned __int64 v26; // kr18_8
  _BYTE *v27; // rsi
  unsigned __int64 *v28; // r14
  __int64 v29; // r15
  __int64 v30; // rbx
  char v31; // r13
  char v32; // r15
  char v33; // r15
  __int64 v34; // r13
  int v35; // r11d
  __int64 v36; // r12
  unsigned __int64 v37; // [rsp-20h] [rbp-20h]

  *(_DWORD *)(v0 + 105) -= 592462728;
  *(_DWORD *)(v0 + 307) ^= 0x23504388u;
  *(_DWORD *)(v0 + 285) -= 430678307;
  v1 = *(_DWORD *)(v0 + 335)
     + (*(_DWORD *)(v0 + 105) ^ *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 5LL))
     - *(_DWORD *)(v0 + 174);
  *(_DWORD *)(v0 + 105) |= v1;
  *(_DWORD *)(v0 + 335) += 1480711052;
  v2 = *(_DWORD *)(v0 + 285) + v1;
  *(_DWORD *)(v0 + 285) &= 0x1E212AAu;
  *(_BYTE *)(v0 + 157) += v2;
  v3 = (*(_DWORD *)(v0 + 105) ^ *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 10LL)) - *(_DWORD *)(v0 + 335);
  *(_DWORD *)(v0 + 105) &= v3;
  *(_DWORD *)(v0 + 335) |= 0xD7A1026u;
  v4 = *(_DWORD *)(v0 + 285) ^ v3;
  *(_DWORD *)(v0 + 285) ^= 0x7DD9B62u;
  *(_BYTE *)(v0 + 83) = ((unsigned __int8)(v4 & 0xF0) >> 4) - 125;
  *(_BYTE *)(v0 + 104) = v4 & 0xF ^ 0x1C;
  *(_DWORD *)(v0 + 285) ^= 0xD1524DBu;
  v5 = **(_DWORD **)(v0 + 251) - *(_DWORD *)(v0 + 105) - *(_DWORD *)(v0 + 307);
  *(_DWORD *)(v0 + 335) -= 206466321;
  v6 = (unsigned int)(*(_DWORD *)(v0 + 285) + v5);
  *(_DWORD *)(v0 + 285) &= 0x64309240u;
  *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) ^ (v6 + 123672037);
  *(_BYTE *)(v0 + 74) = 0;
  if ( *(_BYTE *)(v0 + 83) == 0x84 )
  {
    v7 = v0 + (unsigned __int16)((*(_WORD *)(v0 + 158) ^ *(_WORD *)(v0 + 259)) - 5605);
    *(_QWORD *)(v0 + 149) = v7 ^ 0x70F7253B;
    *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) ^ (*(_QWORD *)v7 + 123672037LL);
    if ( ((unsigned __int8)*(_QWORD *)(v0 + 104) ^ 0x1C) == 3 )
      *(_BYTE *)(v0 + 74) = (v0 + 83) & 0xC0 | 3;
  }
  v8 = *(_BYTE *)(v0 + 83);
  *(_DWORD *)(v0 + 105) += 8764939;
  if ( v8 == -123 )
  {
    v9 = *(_BYTE *)(v0 + 104) ^ 0x1C;
    v10 = *(_QWORD *)(v0 + (unsigned __int16)((*(_WORD *)(v0 + 158) ^ *(_WORD *)(v0 + 259)) - 5605));
    *(_QWORD *)(v0 + 149) = v10 ^ 0x70F7253B;
    if ( v9 == 1 )
      LOBYTE(v10) = *(_BYTE *)v10;
    if ( v9 == 2 )
      LOWORD(v10) = *(_WORD *)v10;
    if ( v9 == 3 )
      v10 = *(unsigned int *)v10;
    if ( v9 == 4 )
      v10 = *(_QWORD *)v10;
    *(_QWORD *)(v0 + 259) = *(_QWORD *)(v0 + 158) ^ (v10 + 123672037);
  }
  v11 = *(_BYTE *)(v0 + 157);
  *(_DWORD *)(v0 + 105) ^= 0x21D4C406u;
  if ( v11 == 13 )
  {
    v12 = ~((*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259)) - 123672037LL);
    __readeflags();
    *(_QWORD *)(v0 + 327) = v12 ^ 0x1D417221;
  }
  v13 = 1024;
  if ( *(_BYTE *)(v0 + 157) == 79 )
  {
    v14 = (*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259)) - 123672038LL;
    __readeflags();
    *(_QWORD *)(v0 + 327) = v14 ^ 0x1D417221;
    v13 = v14 ^ 0x1D417221 ^ (((unsigned __int8)((v0 - 98) ^ (v0 - 9) ^ 0x21) & 0x93) - 1024LL + 183);
  }
  v15 = v0 + 335;
  v16 = *(_DWORD *)(v0 + 335) & 1;
  *(_DWORD *)(v0 + 247) -= 1269856227;
  if ( (_DWORD)v16 != 0 )
  {
    v15 = v0 + 335;
    *(_DWORD *)(v0 + 335) &= 0x521F9633u;
  }
  v17 = (v16 + 49) | 0x93;
  v18 = ((v0 + 157) | v17 & (v15 + 172)) & ((((v16 + 49) | (((v16 + 49) ^ (v13 - 0x80000000LL)) - 86)) ^ 0x60) - 120);
  v19 = (v0 - 99 + ((v0 - 99) | v17 & (v15 - 84)) - 61) & 6;
  if ( *(_BYTE *)(v0 + 157) == 0xC7 )
  {
    v20 = 123672037LL - (*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259));
    __readeflags();
    v19 = -73;
    v18 = v20 ^ 0x1D417221;
    *(_QWORD *)(v0 + 327) = v20 ^ 0x1D417221;
  }
  v24 = 1;
  v21 = v19 + 16;
  v22 = v0 + 157;
  LOBYTE(v23) = 0;
  LOBYTE(v24) = *(_BYTE *)(v0 + 157) - 27 + 109;
  if ( *(_BYTE *)(v0 + 157) == 0xAE )
  {
    v25 = (*(_QWORD *)(v0 + 158) ^ *(_QWORD *)(v0 + 259)) - 123672037LL + 1;
    v26 = __readeflags();
    v37 = v26;
    LOBYTE(v23) = -8;
    *(_QWORD *)(v0 + 327) = v25 ^ 0x1D417221;
    v22 = (v24 + (v22 ^ 0xF6) - 4) | 4;
    v21 = v0 + 71;
  }
  v27 = (_BYTE *)(v0 + 157);
  LOBYTE(v28) = *(_BYTE *)(*(_QWORD *)(v0 + 251) + 4LL);
  if ( (_BYTE)v28 != 0 )
  {
    v23 = (unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 8LL);
    v28 = (unsigned __int64 *)(v0 + *v23);
    *v28 = v37;
  }
  LOBYTE(v22) = *v27 - 27 + 7;
  v29 = (((unsigned __int8)v23 | (unsigned __int8)((v21 & 0x8D ^ 4) + 7)) & 0x2A) + 15LL;
  if ( *v27 != 20 && *(_BYTE *)(v0 + 157) != 57 )
  {
    v30 = *(_QWORD *)(v0 + 149) ^ 0x70F7253BLL;
    v31 = *(_BYTE *)(v0 + 104) ^ 0x1C;
    v32 = (((v0 - 99) ^ ~((v37 & 0x44 | 0x31) - (_BYTE)v28) ^ 0x1E) - v31) | 0x64;
    v22 = *(_QWORD *)(v0 + 327) ^ 0x1D417221LL;
    if ( v31 == 1 )
    {
      *(_BYTE *)v30 = v22;
      v32 = v37 & 0xEC;
    }
    if ( v31 == 2 )
      *(_WORD *)v30 = v22;
    if ( v31 == 3 )
    {
      *(_DWORD *)v30 = v22;
      v33 = 13;
      LOBYTE(v22) = *(_BYTE *)(v0 + 74);
      if ( (_BYTE)v22 != 0 )
      {
        v30 += 4;
        *(_DWORD *)v30 = 0;
        v33 = 42;
      }
      v32 = (v0 + 74) | v30 & (29 - v33);
    }
    if ( v31 == 4 )
    {
      *(_QWORD *)v30 = v22;
      v32 = -14;
    }
    v29 = ((unsigned __int8)v32 ^ 0xF2) & 0x20 | 0xD2u;
  }
  v34 = *(_QWORD *)(v0 + 84);
  v35 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL);
  *(_QWORD *)(v0 + 158) ^= v22 + 40 - (v29 & (v24 ^ 0xA3)) + v18;
  *(_DWORD *)(v0 + 105) &= v35;
  v36 = *(_QWORD *)(8LL * (unsigned __int16)v35 + v34);
  *(_QWORD *)(v0 + 251) += 11LL;
  __asm { jmp     r12 }
}


// ===== Dp_H118_5f88f @ 0x2800af88f size=0x1f0 =====
__int64 __fastcall Dp_H118_5f88f(__int64 a1, __int64 a2)
{
  __int64 v2; // rbp
  __int64 v3; // r8
  int v4; // ebx
  __int64 v5; // rdx
  __int64 v6; // rdx
  __int64 (__fastcall **v7)(__int64, __int64, _QWORD, _QWORD); // r8
  __int64 (__fastcall *v8)(__int64, __int64, _QWORD, _QWORD); // r14
  _DWORD **v10; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v2 + 105) |= 0x764BB4E7u;
  *(_DWORD *)(v2 + 307) -= 1984672999;
  *(_DWORD *)(v2 + 105) += 606338886;
  *(_DWORD *)(v2 + 105) &= 0x2036B4C7u;
  v10 = (_DWORD **)(v2 + *(unsigned __int16 *)(*(_QWORD *)(v2 + 251) + 2LL));
  *(_DWORD *)(v2 + **(unsigned __int16 **)(v2 + 251)) = **v10;
  if ( (*(_QWORD *)(v2 + *(unsigned __int16 *)(*(_QWORD *)(v2 + 251) + 4LL)) & 0x400LL) != 0 )
    --*v10;
  else
    ++*v10;
  v3 = *(_QWORD *)(v2 + 84);
  v4 = *(unsigned __int16 *)(*(_QWORD *)(v2 + 251) + 6LL);
  v5 = ((v2 + (a2 | 0x12) + 80) | 0xC3) - 49;
  v6 = (((unsigned __int8)(a1 ^ v5) & 0xB7 ^ 0x75LL | 0xC3) ^ 4) - ((v3 ^ 0x400) - v5);
  *(_DWORD *)(v2 + 105) &= v4;
  v7 = (__int64 (__fastcall **)(__int64, __int64, _QWORD, _QWORD))(8LL * (unsigned __int16)v4 + v3);
  v8 = *v7;
  *(_QWORD *)(v2 + 251) += 8LL;
  return v8(a1, v6 - 77, v7, 0);
}


// ===== Dp_H119_5fa7f @ 0x2800afa7f size=0x229 =====
__int64 __fastcall Dp_H119_5fa7f()
{
  __int64 v0; // rbp
  __int64 v1; // r15
  __int64 v2; // r11
  int v3; // edi
  __int64 (__fastcall *v4)(__int64, __int64, _QWORD); // r9
  _DWORD **v6; // [rsp-8h] [rbp-8h]

  v6 = (_DWORD **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  *(_DWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL)) = **v6;
  if ( (*(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251)) & 0x400LL) != 0 )
    --*v6;
  else
    ++*v6;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) |= 0x2FEECB78u;
  v2 = *(_QWORD *)(v0 + 84);
  v3 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) ^= v1 ^ (v0 + 105);
  v3 += 1776353764;
  *(_DWORD *)(v0 + 105) |= v3;
  v4 = *(__int64 (__fastcall **)(__int64, __int64, _QWORD))(8LL * (unsigned __int16)v3 + v2);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v4(v0 + 158, v0 + 105, (unsigned __int8)(v1 & ((v0 - 9) ^ 1)) & 0xD3);
}


// ===== Dp_H120_5fca8 @ 0x2800afca8 size=0x3f0 =====
__int64 __fastcall Dp_H120_5fca8(__int64 a1)
{
  __int64 v1; // rbp
  __int64 v2; // rcx
  int v3; // esi
  _DWORD *v4; // r11
  unsigned __int8 v5; // bl
  __int16 v6; // bx
  __int64 v7; // r11
  int v8; // r8d
  __int64 (__fastcall *v9)(__int64, __int64, __int64, _QWORD); // r15
  _DWORD **v11; // [rsp-8h] [rbp-8h]

  v2 = (a1 ^ 0xB7) + 249;
  v3 = *(_DWORD *)(v1 + 335) & 1;
  if ( v3 != 0 )
    *(_DWORD *)(v1 + 335) |= 0x39D3DA61u;
  v11 = (_DWORD **)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 2LL));
  v4 = *v11;
  v5 = (unsigned __int8)*v11 & v3;
  *v4 = *(_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 6LL));
  v6 = (_WORD)v4 + ((((unsigned __int8)v1 | v5 ^ 0x93) + 10) & 0x93);
  if ( (*(_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 4LL)) & 0x400LL) != 0 )
    --*v11;
  else
    ++*v11;
  *(_DWORD *)(v1 + 247) -= 1884533175;
  if ( (*(_DWORD *)(v1 + 335) & 1) != 0 )
    *(_DWORD *)(v1 + 335) |= 0x439DB8EDu;
  v7 = *(_QWORD *)(v1 + 84);
  v8 = **(unsigned __int16 **)(v1 + 251) - *(_DWORD *)(v1 + 105);
  *(_QWORD *)(v1 + 158) -= v2;
  v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD))(8LL * ((unsigned __int16)v8 ^ 0x6E9Du) + v7);
  *(_QWORD *)(v1 + 251) += 8LL;
  return v9(
           v2,
           v1 + 158,
           128,
           (unsigned __int16)((v7 ^ 0x12) + 131)
         & (unsigned __int16)((v2 & ((((v6 ^ 0x75 | 6) - 71) | 0x64) ^ 0x2A)) - 2078)
         & 0x400);
}


// ===== Dp_H121_60098 @ 0x2800b0098 size=0x1e1 =====
void __fastcall Dp_H121_60098(__int64 a1)
{
  __int64 v1; // rbp
  _QWORD *v2; // r15
  __int64 v3; // rbx
  int v4; // r14d
  __int64 v5; // rsi

  *(_DWORD *)(v1 + 105) &= 0x2E6166B2u;
  v2 = (_QWORD *)(v1 + **(unsigned __int16 **)(v1 + 251));
  *v2 -= 8LL;
  v3 = *(_QWORD *)(v1 + 84);
  v4 = *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 2LL) - *(_DWORD *)(v1 + 105);
  *(_QWORD *)(v1 + 158) ^= a1;
  *(_DWORD *)(v1 + 105) += v4;
  v5 = *(_QWORD *)(8LL * (unsigned __int16)v4 + v3);
  *(_QWORD *)(v1 + 251) += 6LL;
  __asm { jmp     rsi }
}


// ===== Dp_H123_604f7 @ 0x2800b04f7 size=0x35b =====
__int64 __fastcall Dp_H123_604f7()
{
  __int64 v0; // rbp
  unsigned __int16 *v1; // rcx
  __int64 v2; // rdx
  __int64 v3; // r9
  int v4; // edi
  __int64 (*v5)(void); // r12
  _WORD **v7; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v0 + 247) ^= 0x94FEE40u;
  *(_DWORD *)(v0 + 285) ^= 0x28C16A22u;
  v1 = (unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL);
  v2 = **(unsigned __int16 **)(v0 + 251);
  *(_DWORD *)(v0 + 105) += 657230016;
  v7 = (_WORD **)(v0 + *v1);
  *(_WORD *)(v0 + v2) = **v7;
  if ( (*(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) & 0x400LL) != 0 )
    --*v7;
  else
    ++*v7;
  *(_DWORD *)(v0 + 105) -= 306796555;
  *(_DWORD *)(v0 + 247) -= 479790766;
  *(_DWORD *)(v0 + 307) &= 0x1249580Bu;
  v3 = *(_QWORD *)(v0 + 84);
  v4 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) += (v0 + 307) ^ (v0 + 105);
  v5 = *(__int64 (**)(void))(8LL * (unsigned __int16)v4 + v3);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v5();
}


// ===== Dp_H124_60852 @ 0x2800b0852 size=0x37b =====
__int64 __fastcall Dp_H124_60852()
{
  __int64 v0; // rbp
  char v1; // si
  _DWORD *v2; // rdi
  __int64 v3; // r14
  int v4; // edx
  __int64 (__fastcall *v5)(_QWORD *, __int64, __int64); // r9
  _QWORD *v7; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v0 + 105) += 1986325858;
  v7 = (_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL));
  v2 = (_DWORD *)*v7;
  *(_DWORD *)*v7 = *(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251));
  if ( (*(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL)) & 0x400LL) != 0 )
    *v7 -= 4LL;
  else
    *v7 += 4LL;
  v3 = *(_QWORD *)(v0 + 84);
  v4 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) -= (unsigned __int8)(v0 + v1 + 118) & 0x80;
  v5 = *(__int64 (__fastcall **)(_QWORD *, __int64, __int64))(8LL * (unsigned __int16)(v4 - 25717) + v3);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v5(
           v7,
           v0 + 251,
           (v0 + 105)
         & (((unsigned __int8)((((v0 + 105) | (((unsigned __int8)v2 & ((unsigned __int8)v2 ^ v0)) + 30)) & 6) - 48)
           ^ 0x90)
          - 4)
         & 0x1E);
}


// ===== Dp_H126_64662 @ 0x2800b4662 size=0x1e2 =====
__int64 __fastcall Dp_H126_64662()
{
  __int64 v0; // rbp
  __int64 v1; // r15
  __int64 v2; // rbx
  int v3; // edi
  __int64 (__fastcall *v4)(__int64, __int64, __int64); // r11
  _BYTE **v6; // [rsp-8h] [rbp-8h]

  *(_DWORD *)(v0 + 285) -= 1934610303;
  v6 = (_BYTE **)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL));
  **v6 = *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL));
  if ( (*(_QWORD *)(v0 + **(unsigned __int16 **)(v0 + 251)) & 0x400LL) != 0 )
    --*v6;
  else
    ++*v6;
  *(_DWORD *)(v0 + 247) |= 0x6721ACCBu;
  v2 = *(_QWORD *)(v0 + 84);
  v3 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 6LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) += v0 + 247 - v1;
  v3 ^= 0x7D151A9Bu;
  *(_DWORD *)(v0 + 105) |= v3;
  v4 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(8LL * (unsigned __int16)v3 + v2);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v4(v0 + 105, v0 + 251, 0x7FFFFFFF);
}


// ===== Dp_H127_64844 @ 0x2800b4844 size=0x1e5 =====
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Dp_H127_64844()
{
  __int64 v0; // rbp
  char v1; // bl
  __int64 v2; // rbx
  _QWORD *v3; // rax
  _QWORD *v4; // rax
  __int64 result; // rax
  _BYTE v6[128]; // [rsp-80h] [rbp-80h]

  v1 = **(_BYTE **)(v0 + 251);
  if ( (v1 == 1 || v1 == 2)
    && *(_QWORD *)(*(_QWORD *)(v0 + 239)
                 + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 7LL)
                 + *(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 1LL)) != *(_QWORD *)(v0 + 239)
                                                                       + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 3LL) )
  {
    v2 = *(_QWORD *)(v0 + 239);
    v3 = (_QWORD *)(v2
                  + *(_DWORD *)(*(_QWORD *)(v0 + 251) + 7LL)
                  + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 1LL));
    *v3 -= *(_QWORD *)(v0 + 297);
    *v3 += *(_QWORD *)(v0 + 239);
    if ( **(_BYTE **)(v0 + 251) == 2 )
    {
      v4 = (_QWORD *)(v2
                    + *(_DWORD *)(*(_QWORD *)(v0 + 251) + 7LL)
                    + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v0 + 251) + 2LL));
      *v4 -= *(_QWORD *)(v0 + 297);
      *v4 += *(_QWORD *)(v0 + 239);
    }
  }
  *(_QWORD *)&v6[*(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 11LL)] = *(_QWORD *)(v0 + 239)
                                                                      + *(unsigned int *)(*(_QWORD *)(v0 + 251) + 7LL);
  *(_DWORD *)(v0 + 231) = 0;
  result = *(_QWORD *)&v6[112];
  __writeeflags(*(unsigned __int64 *)&v6[120]);
  return result;
}


// ===== Dp_H128_64a29 @ 0x2800b4a29 size=0xe4f =====
__int64 __fastcall Dp_H128_64a29()
{
  __int64 v0; // rbp
  unsigned __int16 *v1; // rbx
  int v2; // r12d
  char v3; // r15
  char v4; // r8
  char v5; // r8
  int v6; // r8d
  int v7; // r8d
  int v8; // r8d
  int v9; // r8d
  unsigned __int16 *v10; // r15
  __int64 v11; // rbx
  __int64 (__fastcall *v12)(__int64, __int64); // rax
  __int64 v13; // r12
  __int64 v14; // rdx
  __int64 v15; // rbx
  __int64 v16; // rdx
  __int64 v18; // r13
  int v19; // r14d
  __int64 (__fastcall *v20)(__int64, __int64, __int64, _QWORD); // r15
  int v21; // [rsp-8h] [rbp-8h]

  *(_BYTE *)(v0 + 56) = 0;
  v1 = (unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 8LL);
  v2 = *(_DWORD *)(v0 + *v1);
  v3 = *(_BYTE *)(*(_QWORD *)(v0 + 251) + 10LL);
  if ( v3 == 64 || v3 == -38 )
  {
    v21 = *(_DWORD *)(v0 + *v1);
    if ( (v2 & 0x40) != 0 )
      *(_BYTE *)(v0 + 56) = 1;
    LOWORD(v2) = v21;
  }
  if ( v3 == 38 )
  {
    v2 &= 0x40u;
    if ( v2 == 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == 105 )
  {
    v4 = v2;
    v2 &= 0x40u;
    if ( v2 == 0 && (v4 & 1) == 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == 113 )
  {
    v2 &= 1u;
    if ( v2 == 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == 3 )
  {
    v2 &= 1u;
    if ( v2 != 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == 40 )
  {
    v5 = v2;
    v2 &= 0x40u;
    if ( v2 != 0 )
      *(_BYTE *)(v0 + 56) = 1;
    if ( (v5 & 1) != 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == -93 && (v2 & 0x40) == 0 )
  {
    v6 = (v2 & 0x800) != 0;
    v2 = (v2 & 0x80) != 0;
    if ( v2 == v6 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == -120 )
  {
    v7 = (v2 & 0x800) != 0;
    v2 = (v2 & 0x80) != 0;
    if ( v2 == v7 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == 78 )
  {
    v8 = (v2 & 0x800) != 0;
    v2 = (v2 & 0x80) != 0;
    if ( v2 != v8 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == -38 )
  {
    if ( (v2 & 0x40) != 0 )
      *(_BYTE *)(v0 + 56) = 1;
    v9 = (v2 & 0x800) != 0;
    v2 = (v2 & 0x80) != 0;
    if ( v2 != v9 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == -127 )
  {
    v2 &= 0x800u;
    if ( v2 == 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == -76 )
  {
    v2 &= 4u;
    if ( v2 == 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == -122 )
  {
    v2 &= 0x80u;
    if ( v2 == 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == 118 )
  {
    v2 &= 0x800u;
    if ( v2 != 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == -27 )
  {
    v2 &= 4u;
    if ( v2 != 0 )
      *(_BYTE *)(v0 + 56) = 1;
  }
  if ( v3 == -113 && (v2 & 0x80) != 0 )
    *(_BYTE *)(v0 + 56) = 1;
  v10 = *(unsigned __int16 **)(v0 + 251);
  v11 = 8LL * *v10;
  v12 = *(__int64 (__fastcall **)(__int64, __int64))(v11 + *(_QWORD *)(v0 + 84));
  v13 = *((unsigned int *)v10 + 1);
  v14 = (((((((100 - v11) | 0xC3) ^ 0x4AC) - 0xFFFF) ^ 0xF6) + 42) ^ 0x78) - 246;
  v15 = (unsigned int)v13 & 0x80000000;
  if ( *(_BYTE *)(v0 + 56) != 0 )
  {
    if ( (_DWORD)v15 != 0 )
    {
      v16 = (v15 | v14) + 86;
      *(_QWORD *)(v0 + 251) -= v13 & 0x7FFFFFFF;
    }
    else
    {
      v16 = ((_WORD)v14 + 172) & 0x800;
      *(_QWORD *)(v0 + 251) += v13;
    }
    return v12(1, v16);
  }
  else
  {
    v18 = *(_QWORD *)(v0 + 84);
    v19 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 11LL) - *(_DWORD *)(v0 + 105);
    *(_QWORD *)(v0 + 158) -= (char *)v10 - v15;
    v20 = *(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD))(8LL * (unsigned __int16)v19 + v18);
    *(_QWORD *)(v0 + 251) += 13LL;
    return v20(v15 | (1173 - v15), (((v14 ^ 0x40) - 141) | 0xF9) - 2147483761LL, (v0 + 84) | 0x31, v19 & 2);
  }
}


// ===== Dp_H129_65878 @ 0x2800b5878 size=0x1f6 =====
__int64 __fastcall Dp_H129_65878()
{
  __int64 v0; // rbp
  __int64 v1; // r9
  __int64 v2; // r10
  int v3; // r14d
  __int64 (__fastcall *v4)(__int64, _QWORD, __int64, _WORD **); // rdx
  _WORD **v6; // [rsp-8h] [rbp-8h]

  v1 = *(_QWORD *)(v0 + 251);
  *(_DWORD *)(v0 + 105) ^= 0x310F9771u;
  v6 = (_WORD **)(v0 + *(unsigned __int16 *)(v1 + 6));
  *(_WORD *)(v0 + **(unsigned __int16 **)(v0 + 251)) = **v6;
  if ( (*(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 4LL)) & 0x400LL) != 0 )
    --*v6;
  else
    ++*v6;
  v2 = *(_QWORD *)(v0 + 84);
  v3 = *(_DWORD *)(v0 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL) - 1880440853;
  *(_DWORD *)(v0 + 105) -= v3;
  v4 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _WORD **))(8LL * (unsigned __int16)v3 + v2);
  *(_QWORD *)(v0 + 251) += 8LL;
  return v4(v0 + 251, v4, (unsigned __int16)(((v0 + 158) | 0x252) - v3 - 42) | 0x40LL, v6);
}


// ===== Dp_H130_65a6e @ 0x2800b5a6e size=0x217 =====
__int64 __fastcall Dp_H130_65a6e(__int64 a1, __int64 a2)
{
  __int64 v2; // rbp
  unsigned __int16 *v3; // rcx
  __int64 v4; // r8
  __int64 v5; // rdi
  __int64 v6; // r10
  int v7; // r11d
  __int64 (__fastcall *v8)(__int64, __int64, __int64, __int64); // rsi
  _QWORD *v10; // [rsp-8h] [rbp-8h]

  v3 = *(unsigned __int16 **)(v2 + 251);
  v4 = v3[1];
  *(_DWORD *)(v2 + 247) += 1237282567;
  v10 = (_QWORD *)(v2 + v4);
  *(_BYTE *)(v2 + *v3) = **(_BYTE **)(v2 + v4);
  v5 = *(_QWORD *)(v2 + 251) + 6LL;
  if ( (*(_QWORD *)(v2 + *(unsigned __int16 *)v5) & 0x400LL) != 0 )
    --*v10;
  else
    ++*v10;
  v6 = *(_QWORD *)(v2 + 84);
  v7 = *(_DWORD *)(v2 + 105) + *(unsigned __int16 *)(*(_QWORD *)(v2 + 251) + 4LL);
  *(_QWORD *)(v2 + 158) += v5;
  v7 ^= 0x227E5D17u;
  *(_DWORD *)(v2 + 105) |= v7;
  v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(8LL * (unsigned __int16)v7 + v6);
  *(_QWORD *)(v2 + 251) += 8LL;
  return v8(v2 + 105, a2, 42, 659);
}


// ===== Dp_H131_65c85 @ 0x2800b5c85 size=0x57c =====
__int64 __fastcall Dp_H131_65c85()
{
  __int64 v0; // rbp
  unsigned __int64 v1; // kr00_8
  unsigned __int16 *v2; // rdx
  _QWORD *v3; // r15
  _QWORD *v4; // r8
  __int64 v5; // r14
  int v6; // esi
  __int64 (*v7)(void); // r15

  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) ^= 0x1205FFF7u;
  v1 = __readeflags();
  v2 = *(unsigned __int16 **)(v0 + 251);
  v3 = (_QWORD *)(v0 + *(unsigned __int16 *)((char *)v2 + 7));
  v4 = (_QWORD *)(v0 + *(unsigned __int16 *)((char *)v2 + 9));
  if ( (*(_DWORD *)(v0 + 28) & 0x400LL | *(_QWORD *)(v0 + *v2) & 0x400LL) != 0 )
  {
    *v4 -= 2LL;
    *v3 -= 2LL;
  }
  else
  {
    *v4 += 2LL;
    *v3 += 2LL;
  }
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
    *(_DWORD *)(v0 + 335) += 506656234;
  if ( *(_BYTE *)(*(_QWORD *)(v0 + 251) + 2LL) != 0 )
    *(_QWORD *)(v0 + *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 5LL)) = v1;
  v5 = *(_QWORD *)(v0 + 84);
  v6 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 3LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) -= (char *)v2 - v0 - 105;
  v6 ^= 0x68743F56u;
  *(_DWORD *)(v0 + 105) -= v6;
  v7 = *(__int64 (**)(void))(8LL * (unsigned __int16)v6 + v5);
  *(_QWORD *)(v0 + 251) += 11LL;
  return v7();
}


// ===== Dp_H133_66711 @ 0x2800b6711 size=0x255 =====
void __fastcall Dp_H133_66711()
{
  __int64 v0; // rbx
  __int64 v1; // rbp
  __int64 v2; // r12
  _QWORD *v3; // rdx
  __int64 v4; // rdx
  int v5; // ecx
  __int64 v6; // r13

  *(_DWORD *)(v1 + 307) += 1039418184;
  v3 = (_QWORD *)(v1 + *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 2LL));
  *v3 -= 8LL;
  v4 = *(_QWORD *)(v1 + 84);
  v5 = *(_DWORD *)(v1 + 105) ^ *(unsigned __int16 *)(*(_QWORD *)(v1 + 251) + 4LL);
  *(_QWORD *)(v1 + 158) -= v0 - v2;
  v5 -= 1923744743;
  *(_DWORD *)(v1 + 105) ^= v5;
  v6 = *(_QWORD *)(8LL * (unsigned __int16)v5 + v4);
  *(_QWORD *)(v1 + 251) += 6LL;
  __asm { jmp     r13 }
}


// ===== Dp_H134_66966 @ 0x2800b6966 size=0x2eb =====
void __fastcall Dp_H134_66966()
{
  __int64 v0; // rbp
  char v1; // r11
  unsigned __int16 *v2; // rax
  unsigned __int64 v3; // r12
  _QWORD *v4; // rax
  __int64 v5; // r12
  char v6; // r8
  __int64 v7; // r15
  int v8; // r9d
  __int64 v9; // rdx

  v2 = *(unsigned __int16 **)(v0 + 251);
  v3 = (unsigned __int64)(v2 + 256);
  v4 = (_QWORD *)(v0 + *v2);
  v5 = (v0 + 335) ^ v3 ^ 0x28;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
  {
    v5 -= 141;
    *(_DWORD *)(v0 + 335) &= 0x184FD2C1u;
  }
  *v4 -= 8LL;
  v6 = v0 + 79;
  if ( (*(_DWORD *)(v0 + 335) & 1) != 0 )
  {
    v6 = v0 + 79;
    *(_DWORD *)(v0 + 335) &= 0x129524ECu;
  }
  v7 = *(_QWORD *)(v0 + 84);
  v8 = *(unsigned __int16 *)(*(_QWORD *)(v0 + 251) + 2LL) - *(_DWORD *)(v0 + 105);
  *(_QWORD *)(v0 + 158) -= (((unsigned __int8)(((v1 + (v6 | v5) - 1) ^ v5 & ((v1 - (v6 & 8)) | 8)) + 120)
                           | (unsigned __int8)(v1 + (v6 | v5) - 1) ^ 8)
                          & 0x28)
                         + v5;
  v9 = *(_QWORD *)(8LL * ((unsigned __int16)v8 ^ 0xB298u) + v7);
  *(_QWORD *)(v0 + 251) += 6LL;
  __asm { jmp     rdx }
}


// ===== sub_2800B7DE9 @ 0x2800b7de9 size=0xaf =====
// write access to const memory has been detected, the output may be wrong!
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
  v0 = &unk_2800B79A9;
  for ( i = 136; i != 0; i = (unsigned int)(i - 1) )
    *v0++ += 0x280050000LL;
  *(__int64 *)((char *)qword_28007D250 + 4) = (__int64)&unk_2800B79A9;
  __asm { jmp     qword ptr [rax] }
}


// ===== sub_2800C5020 @ 0x2800c5020 size=0x3 =====
void sub_2800C5020()
{
  ;
}



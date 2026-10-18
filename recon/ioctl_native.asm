0x0280063106  mov       cl, 0x87
0x0280063108  jb        0x280063152
0x028006310a  and       dword ptr [rcx], 0xe03d973a
0x0280063110  sbb       al, 0x3a
0x0280063112  loope     0x280063189
0x0280063114  mov       ah, 0x3c
0x0280063116  sbb       ah, bh
0x0280063118  mov       esp, 0x95d220db
0x028006311d  popfq     
0x028006311e  int3      
0x028006311f  adc       dh, byte ptr [rax]
0x0280063121  push      rdi
0x0280063122  pop       rdi
0x0280063123  push      rdx
0x0280063124  pop       rdx
0x0280063125  push      rdx
0x0280063126  pop       rdx
0x0280063127  cmp       rdi, qword ptr [rip + 0x118da]
0x028006312e  jne       0x280063797
0x0280063134  mov       esi, 0x88
0x0280063139  xor       edi, edi
0x028006313b  cmp       dword ptr [r14 + 0x10], esi
0x028006313f  jne       0x280063c13
0x0280063145  cmp       dword ptr [r14 + 8], esi
0x0280063149  jne       0x280063c13
0x028006314f  mov       eax, dword ptr [r14 + 0x18]
0x0280063153  cmp       eax, 0x8000309c
0x0280063158  jne       0x2800631ae
0x028006315a  lea       rdx, [rsp + 0xd0]
0x0280063162  or        rcx, 0xffffffffffffffff
0x0280063166  mov       dword ptr [rsp + 0xd0], edi
0x028006316d  call      0x280051db4
0x0280063172  cmp       eax, edi
0x0280063174  mov       esi, eax
0x0280063176  jl        0x2800631a6
0x0280063178  mov       rax, qword ptr [r14 + 0x30]
0x028006317c  mov       qword ptr [rax + 0x18], 0x7351
0x0280063184  mov       rbx, qword ptr gs:[0x188]
0x028006318d  call      qword ptr [rip + 0xf0c5]
0x0280063193  mov       r8d, dword ptr [rsp + 0xd0]
0x028006319b  mov       rcx, rax
0x028006319e  mov       rdx, rbx
0x02800631a1  call      0x280051f24
0x02800631a6  mov       dword ptr [rbp + 0x30], esi
0x02800631a9  jmp       0x280063c1d
0x02800631ae  cmp       eax, 0x800030a0
0x02800631b3  jne       0x2800631ed
0x02800631b5  mov       edi, 0x80
0x02800631ba  lea       rcx, [r12 + 8]
0x02800631bf  xor       edx, edx
0x02800631c1  mov       r8, rdi
0x02800631c4  call      0x28006f9e0
0x02800631c9  lea       rcx, [r12 + 8]
0x02800631ce  lea       rdx, [rip + 0x124ab]
0x02800631d5  mov       r8, rdi
0x02800631d8  call      0x28006f580
0x02800631dd  xor       edi, edi
0x02800631df  mov       qword ptr [rbp + 0x38], rsi
0x02800631e3  mov       dword ptr [rbp + 0x30], edi
0x02800631e6  mov       esi, edi
0x02800631e8  jmp       0x280063c21
0x02800631ed  cmp       eax, 0x80000cd4
0x02800631f2  jne       0x28006326c
0x02800631f4  mov       rax, qword ptr [r14 + 0x30]
0x02800631f8  mov       qword ptr [rax + 0x18], 0x7352
0x0280063200  call      qword ptr [rip + 0xf052]
0x0280063206  lea       rcx, [rip + 0x12513]
0x028006320d  mov       rbx, rax
0x0280063210  call      qword ptr [rip + 0xee1a]
0x0280063216  lea       r8, [rip + 0x11a03]
0x028006321d  mov       ecx, edi
0x028006321f  mov       r13d, 1
0x0280063225  mov       rdx, r8
0x0280063228  cmp       qword ptr [rdx], rbx
0x028006322b  je        0x280063239
0x028006322d  add       ecx, r13d
0x0280063230  add       rdx, 8
0x0280063234  cmp       ecx, 0x20
0x0280063237  jb        0x280063228
0x0280063239  cmp       ecx, 0x20
0x028006323c  jne       0x28006325a
0x028006323e  mov       eax, edi
0x0280063240  mov       rcx, r8
0x0280063243  cmp       qword ptr [rcx], rdi
0x0280063246  je        0x280063256
0x0280063248  add       eax, r13d
0x028006324b  add       rcx, 8
0x028006324f  cmp       eax, 0x20
0x0280063252  jb        0x280063243
0x0280063254  jmp       0x28006325a
0x0280063256  mov       qword ptr [r8 + rax*8], rbx
0x028006325a  lea       rcx, [rip + 0x124bf]
0x0280063261  call      qword ptr [rip + 0xedc1]
0x0280063267  jmp       0x2800639c1
0x028006326c  cmp       eax, 0x80000d18
0x0280063271  jne       0x280063293
0x0280063273  cmp       byte ptr [rip + 0x1106e], dil
0x028006327a  je        0x2800639c1
0x0280063280  xor       ecx, ecx
0x0280063282  mov       byte ptr [rip + 0x1105f], dil
0x0280063289  call      0x28005e7cc
0x028006328e  jmp       0x2800639c1
0x0280063293  cmp       eax, r13d
0x0280063296  jne       0x280063c13
0x028006329c  mov       r15d, 0x74706b64
0x02800632a2  cmp       dword ptr [r12], r15d
0x02800632a6  jne       0x280063c13
0x02800632ac  mov       eax, dword ptr [r12 + 4]
0x02800632b1  cmp       eax, edi
0x02800632b3  je        0x28006375f
0x02800632b9  sub       eax, 0x65
0x02800632bc  je        0x280063672
0x02800632c2  mov       r13d, 1
0x02800632c8  sub       eax, r13d
0x02800632cb  je        0x280063632
0x02800632d1  sub       eax, 0x62
0x02800632d4  je        0x280063567
0x02800632da  sub       eax, r13d
0x02800632dd  je        0x2800634e3
0x02800632e3  sub       eax, r13d
0x02800632e6  je        0x28006345c
0x02800632ec  sub       eax, 0x62
0x02800632ef  je        0x280063343
0x02800632f1  sub       eax, 0xc8
0x02800632f6  je        0x280063324
0x02800632f8  cmp       eax, r13d
0x02800632fb  jne       0x280063c13
0x0280063301  mov       eax, dword ptr [rip + 0x11bd9]
0x0280063307  shl       rax, 0xa
0x028006330b  mov       qword ptr [r12 + 8], rax
0x0280063310  mov       eax, dword ptr [rip + 0x11bce]
0x0280063316  shl       rax, 0xa
0x028006331a  mov       qword ptr [r12 + 0x10], rax
0x028006331f  jmp       0x2800631df
0x0280063324  mov       rax, qword ptr [r12 + 8]
0x0280063329  cqo       
0x028006332b  and       edx, 0x3ff
0x0280063331  add       rax, rdx
0x0280063334  sar       rax, 0xa
0x0280063338  mov       dword ptr [rip + 0x11ba2], eax
0x028006333e  jmp       0x2800639c1
0x0280063343  mov       esi, 0xc000000d
0x0280063348  cmp       qword ptr [r12 + 8], rdi
0x028006334d  je        0x2800631a6
0x0280063353  cmp       qword ptr [r12 + 0x10], rdi
0x0280063358  je        0x2800631a6
0x028006335e  mov       r8d, r15d
0x0280063361  mov       edx, 0x28
0x0280063366  xor       ecx, ecx
0x0280063368  call      qword ptr [rip + 0xf1ca]
0x028006336e  mov       rbx, rax
0x0280063371  cmp       rax, rdi
0x0280063374  je        0x28006369d
0x028006337a  mov       r8, qword ptr [rip + 0xeedf]
0x0280063381  mov       rcx, qword ptr [r12 + 8]
0x0280063386  lea       rax, [rsp + 0x48]
0x028006338b  mov       r8, qword ptr [r8]
0x028006338e  xor       r9d, r9d
0x0280063391  mov       edx, 0x1f0003
0x0280063396  mov       qword ptr [rsp + 0x28], rdi
0x028006339b  mov       qword ptr [rsp + 0x20], rax
0x02800633a0  call      qword ptr [rip + 0xed4a]
0x02800633a6  cmp       eax, edi
0x02800633a8  mov       esi, eax
0x02800633aa  jge       0x2800633b7
0x02800633ac  mov       edx, r15d
0x02800633af  mov       rcx, rbx
0x02800633b2  jmp       0x2800636e1
0x02800633b7  mov       r8, qword ptr [rip + 0xeea2]
0x02800633be  mov       rcx, qword ptr [r12 + 0x10]
0x02800633c3  lea       rax, [rsp + 0x60]
0x02800633c8  mov       r8, qword ptr [r8]
0x02800633cb  xor       r9d, r9d
0x02800633ce  mov       edx, 0x1f0003
0x02800633d3  mov       qword ptr [rsp + 0x28], rdi
0x02800633d8  mov       qword ptr [rsp + 0x20], rax
0x02800633dd  call      qword ptr [rip + 0xed0d]
0x02800633e3  cmp       eax, edi
0x02800633e5  mov       esi, eax
0x02800633e7  jge       0x2800633f6
0x02800633e9  mov       rcx, qword ptr [rsp + 0x48]
0x02800633ee  call      qword ptr [rip + 0xed4c]
0x02800633f4  jmp       0x2800633ac
0x02800633f6  mov       word ptr [rbx + 0x12], r13w
0x02800633fb  mov       eax, 0x28
0x0280063400  lea       rcx, [rip + 0x11fd9]
0x0280063407  mov       word ptr [rbx + 0x10], ax
0x028006340b  mov       rax, qword ptr [rsp + 0x48]
0x0280063410  mov       qword ptr [rbx + 0x18], rax
0x0280063414  mov       rax, qword ptr [rsp + 0x60]
0x0280063419  mov       qword ptr [rbx + 0x20], rax
0x028006341d  call      qword ptr [rip + 0xec0d]
0x0280063423  mov       r11, qword ptr [rip + 0x11f6e]
0x028006342a  mov       qword ptr [rbx + 8], r11
0x028006342e  lea       rax, [rip + 0x11f5b]
0x0280063435  lea       rcx, [rip + 0x11fa4]
0x028006343c  mov       qword ptr [rbx], rax
0x028006343f  mov       qword ptr [r11], rbx
0x0280063442  mov       qword ptr [rip + 0x11f4f], rbx
0x0280063449  call      qword ptr [rip + 0xebd9]
0x028006344f  mov       r11, qword ptr [r14 + 0x30]
0x0280063453  mov       qword ptr [r11 + 0x18], rbx
0x0280063457  jmp       0x280063758
0x028006345c  mov       rbx, qword ptr gs:[0x188]
0x0280063465  call      qword ptr [rip + 0xeded]
0x028006346b  xor       r8d, r8d
0x028006346e  mov       rcx, rax
0x0280063471  mov       rdx, rbx
0x0280063474  call      0x28005214c
0x0280063479  cmp       al, dil
0x028006347c  je        0x280063c13
0x0280063482  mov       rbx, qword ptr gs:[0x188]
0x028006348b  call      qword ptr [rip + 0xedc7]
0x0280063491  lea       rcx, [rip + 0x11f08]
0x0280063498  mov       rsi, rax
0x028006349b  call      qword ptr [rip + 0xeb8f]
0x02800634a1  mov       r11, qword ptr [rip + 0x12268]
0x02800634a8  lea       rcx, [rip + 0x12261]
0x02800634af  jmp       0x2800634ba
0x02800634b1  cmp       qword ptr [r11 + 0x10], rsi
0x02800634b5  je        0x2800634c1
0x02800634b7  mov       r11, qword ptr [r11]
0x02800634ba  cmp       r11, rcx
0x02800634bd  jne       0x2800634b1
0x02800634bf  jmp       0x2800634d7
0x02800634c1  cmp       qword ptr [r11 + 0x20], rbx
0x02800634c5  jne       0x2800634cd
0x02800634c7  dec       dword ptr [r11 + 0x30]
0x02800634cb  jmp       0x2800634d7
0x02800634cd  cmp       qword ptr [r11 + 0x28], rbx
0x02800634d1  jne       0x2800634d7
0x02800634d3  dec       dword ptr [r11 + 0x34]
0x02800634d7  lea       rcx, [rip + 0x11ec2]
0x02800634de  jmp       0x280063261
0x02800634e3  mov       rbx, qword ptr gs:[0x188]
0x02800634ec  call      qword ptr [rip + 0xed66]
0x02800634f2  xor       r8d, r8d
0x02800634f5  mov       rcx, rax
0x02800634f8  mov       rdx, rbx
0x02800634fb  call      0x28005214c
0x0280063500  cmp       al, dil
0x0280063503  je        0x280063c13
0x0280063509  mov       rbx, qword ptr gs:[0x188]
0x0280063512  call      qword ptr [rip + 0xed40]
0x0280063518  lea       rcx, [rip + 0x11e81]
0x028006351f  mov       rsi, rax
0x0280063522  call      qword ptr [rip + 0xeb08]
0x0280063528  mov       r11, qword ptr [rip + 0x121e1]
0x028006352f  lea       rcx, [rip + 0x121da]
0x0280063536  jmp       0x280063541
0x0280063538  cmp       qword ptr [r11 + 0x10], rsi
0x028006353c  je        0x280063548
0x028006353e  mov       r11, qword ptr [r11]
0x0280063541  cmp       r11, rcx
0x0280063544  jne       0x280063538
0x0280063546  jmp       0x2800634d7
0x0280063548  cmp       qword ptr [r11 + 0x20], rbx
0x028006354c  jne       0x280063554
0x028006354e  add       dword ptr [r11 + 0x30], r13d
0x0280063552  jmp       0x2800634d7
0x0280063554  cmp       qword ptr [r11 + 0x28], rbx
0x0280063558  jne       0x2800634d7
0x028006355e  add       dword ptr [r11 + 0x34], r13d
0x0280063562  jmp       0x2800634d7
0x0280063567  mov       rbx, qword ptr gs:[0x188]
0x0280063570  call      qword ptr [rip + 0xece2]
0x0280063576  xor       r8d, r8d
0x0280063579  mov       rcx, rax
0x028006357c  mov       rdx, rbx
0x028006357f  call      0x2800521c4
0x0280063584  cmp       al, dil
0x0280063587  je        0x280063c13
0x028006358d  mov       r8, qword ptr [rip + 0xee64]
0x0280063594  mov       rcx, qword ptr [r12 + 8]
0x0280063599  lea       rax, [rsp + 0x50]
0x028006359e  mov       r8, qword ptr [r8]
0x02800635a1  xor       r9d, r9d
0x02800635a4  mov       edx, 0x1f0003
0x02800635a9  mov       qword ptr [rsp + 0x28], rdi
0x02800635ae  mov       qword ptr [rsp + 0x20], rax
0x02800635b3  call      qword ptr [rip + 0xeb37]
0x02800635b9  cmp       eax, edi
0x02800635bb  jl        0x280063c18
0x02800635c1  mov       rcx, qword ptr [rsp + 0x50]
0x02800635c6  call      qword ptr [rip + 0xeb74]
0x02800635cc  mov       rsi, qword ptr [rsp + 0x50]
0x02800635d1  call      qword ptr [rip + 0xec81]
0x02800635d7  lea       rcx, [rip + 0x11dc2]
0x02800635de  mov       r12, rax
0x02800635e1  mov       bl, dil
0x02800635e4  call      qword ptr [rip + 0xea46]
0x02800635ea  mov       r11, qword ptr [rip + 0x1211f]
0x02800635f1  lea       rcx, [rip + 0x12118]
0x02800635f8  jmp       0x280063603
0x02800635fa  cmp       qword ptr [r11 + 0x10], r12
0x02800635fe  je        0x28006360a
0x0280063600  mov       r11, qword ptr [r11]
0x0280063603  cmp       r11, rcx
0x0280063606  jne       0x2800635fa
0x0280063608  jmp       0x280063615
0x028006360a  mov       qword ptr [r11 + 0x28], rsi
0x028006360e  mov       dword ptr [r11 + 0x34], edi
0x0280063612  mov       bl, r13b
0x0280063615  lea       rcx, [rip + 0x11d84]
0x028006361c  call      qword ptr [rip + 0xea06]
0x0280063622  neg       bl
0x0280063624  sbb       eax, eax
0x0280063626  not       eax
0x0280063628  and       eax, 0xc0000022
0x028006362d  jmp       0x280063c18
0x0280063632  lea       rcx, [rip + 0x11fe7]
0x0280063639  call      qword ptr [rip + 0xe9f1]
0x028006363f  mov       rsi, qword ptr [rip + 0x120ba]
0x0280063646  lea       rbx, [rip + 0x120b3]
0x028006364d  jmp       0x280063661
0x028006364f  mov       rcx, qword ptr [rsi + 0x18]
0x0280063653  xor       r8d, r8d
0x0280063656  xor       edx, edx
0x0280063658  call      qword ptr [rip + 0xe9fa]
0x028006365e  mov       rsi, qword ptr [rsi]
0x0280063661  cmp       rsi, rbx
0x0280063664  jne       0x28006364f
0x0280063666  lea       rcx, [rip + 0x11fb3]
0x028006366d  jmp       0x280063261
0x0280063672  mov       esi, 0xc000000d
0x0280063677  cmp       qword ptr [r12 + 8], rdi
0x028006367c  je        0x2800631a6
0x0280063682  mov       ebx, 0x28
0x0280063687  mov       r8d, r15d
0x028006368a  xor       ecx, ecx
0x028006368c  mov       rdx, rbx
0x028006368f  call      qword ptr [rip + 0xeea3]
0x0280063695  mov       r15, rax
0x0280063698  cmp       rax, rdi
0x028006369b  jne       0x2800636a7
0x028006369d  mov       esi, 0xc000009a
0x02800636a2  jmp       0x2800631a6
0x02800636a7  mov       r8, qword ptr [rip + 0xebb2]
0x02800636ae  mov       rcx, qword ptr [r12 + 8]
0x02800636b3  lea       rax, [rsp + 0x68]
0x02800636b8  mov       r8, qword ptr [r8]
0x02800636bb  xor       r9d, r9d
0x02800636be  mov       edx, 0x1f0003
0x02800636c3  mov       qword ptr [rsp + 0x28], rdi
0x02800636c8  mov       qword ptr [rsp + 0x20], rax
0x02800636cd  call      qword ptr [rip + 0xea1d]
0x02800636d3  cmp       eax, edi
0x02800636d5  mov       esi, eax
0x02800636d7  jge       0x2800636ec
0x02800636d9  mov       edx, 0x74706b64
0x02800636de  mov       rcx, r15
0x02800636e1  call      qword ptr [rip + 0xebc9]
0x02800636e7  jmp       0x2800631a6
0x02800636ec  mov       word ptr [r15 + 0x10], bx
0x02800636f1  mov       word ptr [r15 + 0x12], di
0x02800636f6  mov       rax, qword ptr [rsp + 0x68]
0x02800636fb  mov       r13d, 1
0x0280063701  mov       qword ptr [r15 + 0x18], rax
0x0280063705  mov       eax, r13d
0x0280063708  lock xadd dword ptr [rip + 0x10ef0], eax
0x0280063710  add       eax, r13d
0x0280063713  lea       rcx, [rip + 0x11f06]
0x028006371a  mov       dword ptr [r15 + 0x20], eax
0x028006371e  call      qword ptr [rip + 0xe90c]
0x0280063724  mov       r11, qword ptr [rip + 0x11fdd]
0x028006372b  mov       qword ptr [r15 + 8], r11
0x028006372f  lea       rbx, [rip + 0x11fca]
0x0280063736  lea       rcx, [rip + 0x11ee3]
0x028006373d  mov       qword ptr [r15], rbx
0x0280063740  mov       qword ptr [r11], r15
0x0280063743  mov       qword ptr [rip + 0x11fbe], r15
0x028006374a  call      qword ptr [rip + 0xe8d8]
0x0280063750  mov       r11, qword ptr [r14 + 0x30]
0x0280063754  mov       qword ptr [r11 + 0x18], r15
0x0280063758  mov       esi, edi
0x028006375a  jmp       0x2800631a6
0x028006375f  mov       rbx, qword ptr gs:[0x188]
0x0280063768  call      qword ptr [rip + 0xeaea]
0x028006376e  mov       r8d, 2
0x0280063774  mov       rcx, rax
0x0280063777  mov       rdx, rbx
0x028006377a  call      0x2800521c4
0x028006377f  cmp       al, dil
0x0280063782  je        0x280063c13
0x0280063788  call      0x28006e964
0x028006378d  call      0x280065ad0
0x0280063792  jmp       0x280063c18
0x0280063797  mov       rax, qword ptr [rdi + 0x40]
0x028006379b  mov       r13d, 1
0x02800637a1  cmp       dword ptr [rax], 0x753191
0x02800637a7  jne       0x280063c30
0x02800637ad  mov       ecx, dword ptr [rsp + 0xd8]
0x02800637b4  xor       edi, edi
0x02800637b6  mov       esi, 0x88
0x02800637bb  mov       r15d, 0x74706b64
0x02800637c1  cmp       r12, rdi
0x02800637c4  je        0x2800639cb
0x02800637ca  cmp       dword ptr [r14 + 0x18], ecx
0x02800637ce  jne       0x2800639cb
0x02800637d4  cmp       dword ptr [r14 + 0x10], esi
0x02800637d8  jne       0x2800639cb
0x02800637de  cmp       dword ptr [r14 + 8], esi
0x02800637e2  jne       0x2800639cb
0x02800637e8  cmp       dword ptr [r12], r15d
0x02800637ec  jne       0x2800639cb
0x02800637f2  mov       eax, dword ptr [r12 + 4]
0x02800637f7  cmp       eax, 0x190
0x02800637fc  je        0x2800639a5
0x0280063802  add       eax, 0xfffffc17
0x0280063807  cmp       eax, r13d
0x028006380a  ja        0x2800639cb
0x0280063810  mov       rcx, qword ptr [rbx + 0x10]
0x0280063814  mov       rdx, rbp
0x0280063817  call      0x2800513d0
0x028006381c  cmp       eax, edi
0x028006381e  mov       r13d, eax
0x0280063821  jl        0x28006399d
0x0280063827  mov       ecx, dword ptr [r12 + 8]
0x028006382c  mov       dword ptr [rbx + 0x48], ecx
0x028006382f  mov       ecx, dword ptr [r12 + 0xc]
0x0280063834  mov       dword ptr [rbx + 0x4c], ecx
0x0280063837  cmp       ecx, 2
0x028006383a  jne       0x280063943
0x0280063840  mov       r12, qword ptr [rbx + 0x220]
0x0280063847  cmp       r12, rdi
0x028006384a  je        0x280063943
0x0280063850  mov       r14, qword ptr [rbx + 0x10]
0x0280063854  mov       qword ptr [rsp + 0xe8], rdi
0x028006385c  mov       rax, qword ptr [r12 + 0x18]
0x0280063861  mov       rcx, qword ptr [rax + 0x20]
0x0280063865  xor       edx, edx
0x0280063867  mov       qword ptr [rsp + 0x70], rdi
0x028006386c  mov       qword ptr [rsp + 0x78], rcx
0x0280063871  mov       cl, byte ptr [r14 + 0x4c]
0x0280063875  call      qword ptr [rip + 0xea3d]
0x028006387b  cmp       rax, rdi
0x028006387e  je        0x280063943
0x0280063884  mov       qword ptr [rsp + 0x28], rax
0x0280063889  lea       rax, [rsp + 0x70]
0x028006388e  lea       r9, [rsp + 0xe8]
0x0280063896  lea       r8, [rsp + 0x78]
0x028006389b  mov       rdx, r12
0x028006389e  mov       rcx, r14
0x02800638a1  mov       qword ptr [rsp + 0x20], rax
0x02800638a6  call      0x280066834
0x02800638ab  cmp       eax, edi
0x02800638ad  jl        0x280063943
0x02800638b3  mov       r12d, 0x74665450
0x02800638b9  mov       rdx, rsi
0x02800638bc  xor       ecx, ecx
0x02800638be  mov       r8d, r12d
0x02800638c1  call      qword ptr [rip + 0xec71]
0x02800638c7  mov       r14, rax
0x02800638ca  cmp       rax, rdi
0x02800638cd  je        0x280063933
0x02800638cf  jmp       0x2800bbd9b
0x02800638d4  outsb     dx, byte ptr [rsi]
0x02800638d5  test      al, 0xdb
0x02800638d7  ret       
0x02800638d8  add       byte ptr [rbx + 0x2d56873d], 0xde
0x02800638df  jle       0x2800638a9
0x02800638e1  adc       eax, dword ptr [rcx]
0x02800638e3  cmc       
0x02800638e4  jne       0x28006390e
0x02800638e6  mov       edi, 0xe437ad66
0x02800638eb  and       esp, eax
0x02800638ed  push      -1
0x02800638ef  ficomp    dword ptr [rdi + 6]
0x02800638f2  pop       rbx
0x02800638f3  jne       0x280063945
0x02800638f5  pop       rax
0x02800638f6  push      rcx
0x02800638f7  pop       rcx
0x02800638f8  push      rax
0x02800638f9  pop       rax
0x02800638fa  mov       rcx, qword ptr [rbx + 0x18]
0x02800638fe  call      qword ptr [rip + 0xea6c]
0x0280063904  mov       edx, dword ptr [rsp + 0xd8]
0x028006390b  mov       byte ptr [rsp + 0x30], dil
0x0280063910  mov       rcx, rax
0x0280063913  mov       r9d, esi
0x0280063916  mov       r8, r14
0x0280063919  mov       dword ptr [rsp + 0x28], esi
0x028006391d  mov       qword ptr [rsp + 0x20], r14
0x0280063922  call      0x2800514a4
0x0280063927  mov       edx, r12d
0x028006392a  mov       rcx, r14
0x028006392d  call      qword ptr [rip + 0xe97d]
0x0280063933  mov       rcx, qword ptr [rsp + 0xe8]
0x028006393b  xor       edx, edx
0x028006393d  call      qword ptr [rip + 0xe96d]
0x0280063943  mov       rax, qword ptr [rbx + 0x18]
0x0280063947  bt        dword ptr [rax + 0x30], 8
0x028006394c  jae       0x28006395c
0x028006394e  cmp       dword ptr [rbx + 0x4c], 2
0x0280063952  jne       0x28006395c
0x0280063954  mov       ecx, dword ptr [rbx + 0x48]
0x0280063957  call      0x28006cae8
0x028006395c  lea       rcx, [rip + 0x11cbd]
0x0280063963  call      qword ptr [rip + 0xe6c7]
0x0280063969  mov       rdi, qword ptr [rip + 0x11d90]
0x0280063970  lea       rbx, [rip + 0x11d89]
0x0280063977  jmp       0x28006398b
0x0280063979  mov       rcx, qword ptr [rdi + 0x18]
0x028006397d  xor       r8d, r8d
0x0280063980  xor       edx, edx
0x0280063982  call      qword ptr [rip + 0xe6d0]
0x0280063988  mov       rdi, qword ptr [rdi]
0x028006398b  cmp       rdi, rbx
0x028006398e  jne       0x280063979
0x0280063990  lea       rcx, [rip + 0x11c89]
0x0280063997  call      qword ptr [rip + 0xe68b]
0x028006399d  mov       esi, r13d
0x02800639a0  jmp       0x280063c21
0x02800639a5  cmp       dword ptr [rbx + 0x4c], 2
0x02800639a9  jne       0x2800639c1
0x02800639ab  lea       rcx, [rbx + 0x38]
0x02800639af  call      0x28006ae30
0x02800639b4  mov       rcx, qword ptr [rsp + 0xd0]
0x02800639bc  call      0x280066dd4
0x02800639c1  mov       dword ptr [rbp + 0x30], edi
0x02800639c4  mov       esi, edi
0x02800639c6  jmp       0x280063c1d
0x02800639cb  cmp       dword ptr [r14 + 0x18], 0x80002d48
0x02800639d3  jne       0x280063c30
0x02800639d9  mov       rax, qword ptr gs:[0x188]
0x02800639e2  mov       qword ptr [rsp + 0xd0], rax
0x02800639ea  cmp       dword ptr [r14 + 0x10], esi
0x02800639ee  jne       0x280063c13
0x02800639f4  cmp       dword ptr [r14 + 8], esi
0x02800639f8  jne       0x280063c13
0x02800639fe  cmp       byte ptr [rbx + 0x228], dil
0x0280063a05  jne       0x280063c02
0x0280063a0b  cmp       byte ptr [rip + 0x108d7], dil
0x0280063a12  je        0x280063c02
0x0280063a18  mov       byte ptr [rbx + 0x228], r13b
0x0280063a1f  mov       dword ptr [r14 + 0x18], ecx
0x0280063a23  jmp       0x2800bc01a
0x0280063a28  xchg      edx, eax
0x0280063a29  sub       al, 0x4b
0x0280063a2b  test      dword ptr [rsi], 0x8b73eb3e
0x0280063a31  test      eax, 0xcaf60022
0x0280063a36  cmp       dword ptr [rdi - 0x1b], 0xf07579f8

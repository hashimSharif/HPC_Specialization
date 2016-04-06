/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* * SystemZ Disassembler                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#include "llvm/MC/MCInst.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/DataTypes.h"
#include "llvm/Support/LEB128.h"
#include "llvm/Support/raw_ostream.h"
#include <assert.h>

namespace llvm {

// Helper function for extracting fields from encoded instructions.
template<typename InsnType>
static InsnType fieldFromInstruction(InsnType insn, unsigned startBit,
                                     unsigned numBits) {
    assert(startBit + numBits <= (sizeof(InsnType)*8) &&
           "Instruction field out of bounds!");
    InsnType fieldMask;
    if (numBits == sizeof(InsnType)*8)
      fieldMask = (InsnType)(-1LL);
    else
      fieldMask = (((InsnType)1 << numBits) - 1) << startBit;
    return (insn & fieldMask) >> startBit;
}

static const uint8_t DecoderTable16[] = {
/* 0 */       MCD::OPC_ExtractField, 8, 8,  // Inst{15-8} ...
/* 3 */       MCD::OPC_FilterValue, 7, 127, 0, // Skip to: 134
/* 7 */       MCD::OPC_ExtractField, 4, 4,  // Inst{7-4} ...
/* 10 */      MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 18
/* 14 */      MCD::OPC_Decode, 241, 2, 0, // Opcode: AsmOBR
/* 18 */      MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 26
/* 22 */      MCD::OPC_Decode, 161, 1, 0, // Opcode: AsmHBR
/* 26 */      MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 34
/* 30 */      MCD::OPC_Decode, 206, 2, 0, // Opcode: AsmNLEBR
/* 34 */      MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 42
/* 38 */      MCD::OPC_Decode, 147, 2, 0, // Opcode: AsmLBR
/* 42 */      MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 50
/* 46 */      MCD::OPC_Decode, 188, 2, 0, // Opcode: AsmNHEBR
/* 50 */      MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 58
/* 54 */      MCD::OPC_Decode, 157, 2, 0, // Opcode: AsmLHBR
/* 58 */      MCD::OPC_FilterValue, 7, 4, 0, // Skip to: 66
/* 62 */      MCD::OPC_Decode, 178, 2, 0, // Opcode: AsmNEBR
/* 66 */      MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 74
/* 70 */      MCD::OPC_Decode, 152, 1, 0, // Opcode: AsmEBR
/* 74 */      MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 82
/* 78 */      MCD::OPC_Decode, 215, 2, 0, // Opcode: AsmNLHBR
/* 82 */      MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 90
/* 86 */      MCD::OPC_Decode, 162, 1, 0, // Opcode: AsmHEBR
/* 90 */      MCD::OPC_FilterValue, 11, 4, 0, // Skip to: 98
/* 94 */      MCD::OPC_Decode, 205, 2, 0, // Opcode: AsmNLBR
/* 98 */      MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 106
/* 102 */     MCD::OPC_Decode, 148, 2, 0, // Opcode: AsmLEBR
/* 106 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 114
/* 110 */     MCD::OPC_Decode, 187, 2, 0, // Opcode: AsmNHBR
/* 114 */     MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 122
/* 118 */     MCD::OPC_Decode, 232, 2, 0, // Opcode: AsmNOBR
/* 122 */     MCD::OPC_FilterValue, 15, 4, 0, // Skip to: 130
/* 126 */     MCD::OPC_Decode, 253, 2, 0, // Opcode: BR
/* 130 */     MCD::OPC_Decode, 141, 1, 1, // Opcode: AsmBCR
/* 134 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 142
/* 138 */     MCD::OPC_Decode, 252, 2, 2, // Opcode: BASR
/* 142 */     MCD::OPC_FilterValue, 16, 4, 0, // Skip to: 150
/* 146 */     MCD::OPC_Decode, 244, 4, 3, // Opcode: LPR
/* 150 */     MCD::OPC_FilterValue, 17, 4, 0, // Skip to: 158
/* 154 */     MCD::OPC_Decode, 234, 4, 3, // Opcode: LNR
/* 158 */     MCD::OPC_FilterValue, 18, 4, 0, // Skip to: 166
/* 162 */     MCD::OPC_Decode, 134, 5, 3, // Opcode: LTR
/* 166 */     MCD::OPC_FilterValue, 19, 4, 0, // Skip to: 174
/* 170 */     MCD::OPC_Decode, 166, 4, 3, // Opcode: LCR
/* 174 */     MCD::OPC_FilterValue, 20, 4, 0, // Skip to: 182
/* 178 */     MCD::OPC_Decode, 213, 5, 4, // Opcode: NR
/* 182 */     MCD::OPC_FilterValue, 21, 4, 0, // Skip to: 190
/* 186 */     MCD::OPC_Decode, 197, 3, 3, // Opcode: CLR
/* 190 */     MCD::OPC_FilterValue, 22, 4, 0, // Skip to: 198
/* 194 */     MCD::OPC_Decode, 240, 5, 4, // Opcode: OR
/* 198 */     MCD::OPC_FilterValue, 23, 4, 0, // Skip to: 206
/* 202 */     MCD::OPC_Decode, 238, 6, 4, // Opcode: XR
/* 206 */     MCD::OPC_FilterValue, 24, 4, 0, // Skip to: 214
/* 210 */     MCD::OPC_Decode, 246, 4, 3, // Opcode: LR
/* 214 */     MCD::OPC_FilterValue, 25, 4, 0, // Skip to: 222
/* 218 */     MCD::OPC_Decode, 208, 3, 3, // Opcode: CR
/* 222 */     MCD::OPC_FilterValue, 26, 3, 0, // Skip to: 229
/* 226 */     MCD::OPC_Decode, 63, 4, // Opcode: AR
/* 229 */     MCD::OPC_FilterValue, 27, 4, 0, // Skip to: 237
/* 233 */     MCD::OPC_Decode, 167, 6, 4, // Opcode: SR
/* 237 */     MCD::OPC_FilterValue, 30, 3, 0, // Skip to: 244
/* 241 */     MCD::OPC_Decode, 60, 4, // Opcode: ALR
/* 244 */     MCD::OPC_FilterValue, 31, 4, 0, // Skip to: 252
/* 248 */     MCD::OPC_Decode, 159, 6, 4, // Opcode: SLR
/* 252 */     MCD::OPC_FilterValue, 40, 4, 0, // Skip to: 260
/* 256 */     MCD::OPC_Decode, 172, 4, 5, // Opcode: LDR
/* 260 */     MCD::OPC_FilterValue, 56, 4, 0, // Skip to: 268
/* 264 */     MCD::OPC_Decode, 177, 4, 6, // Opcode: LER
/* 268 */     MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTable32[] = {
/* 0 */       MCD::OPC_ExtractField, 24, 8,  // Inst{31-24} ...
/* 3 */       MCD::OPC_FilterValue, 64, 4, 0, // Skip to: 11
/* 7 */       MCD::OPC_Decode, 190, 6, 7, // Opcode: STH
/* 11 */      MCD::OPC_FilterValue, 65, 4, 0, // Skip to: 19
/* 15 */      MCD::OPC_Decode, 155, 4, 8, // Opcode: LA
/* 19 */      MCD::OPC_FilterValue, 66, 4, 0, // Skip to: 27
/* 23 */      MCD::OPC_Decode, 179, 6, 7, // Opcode: STC
/* 27 */      MCD::OPC_FilterValue, 67, 4, 0, // Skip to: 35
/* 31 */      MCD::OPC_Decode, 131, 4, 9, // Opcode: IC
/* 35 */      MCD::OPC_FilterValue, 72, 4, 0, // Skip to: 43
/* 39 */      MCD::OPC_Decode, 195, 4, 7, // Opcode: LH
/* 43 */      MCD::OPC_FilterValue, 73, 4, 0, // Skip to: 51
/* 47 */      MCD::OPC_Decode, 162, 3, 7, // Opcode: CH
/* 51 */      MCD::OPC_FilterValue, 74, 3, 0, // Skip to: 58
/* 55 */      MCD::OPC_Decode, 39, 10, // Opcode: AH
/* 58 */      MCD::OPC_FilterValue, 75, 4, 0, // Skip to: 66
/* 62 */      MCD::OPC_Decode, 142, 6, 10, // Opcode: SH
/* 66 */      MCD::OPC_FilterValue, 76, 4, 0, // Skip to: 74
/* 70 */      MCD::OPC_Decode, 158, 5, 10, // Opcode: MH
/* 74 */      MCD::OPC_FilterValue, 80, 4, 0, // Skip to: 82
/* 78 */      MCD::OPC_Decode, 177, 6, 7, // Opcode: ST
/* 82 */      MCD::OPC_FilterValue, 84, 4, 0, // Skip to: 90
/* 86 */      MCD::OPC_Decode, 189, 5, 10, // Opcode: N
/* 90 */      MCD::OPC_FilterValue, 85, 4, 0, // Skip to: 98
/* 94 */      MCD::OPC_Decode, 171, 3, 7, // Opcode: CL
/* 98 */      MCD::OPC_FilterValue, 86, 4, 0, // Skip to: 106
/* 102 */     MCD::OPC_Decode, 216, 5, 10, // Opcode: O
/* 106 */     MCD::OPC_FilterValue, 87, 4, 0, // Skip to: 114
/* 110 */     MCD::OPC_Decode, 224, 6, 10, // Opcode: X
/* 114 */     MCD::OPC_FilterValue, 88, 4, 0, // Skip to: 122
/* 118 */     MCD::OPC_Decode, 153, 4, 7, // Opcode: L
/* 122 */     MCD::OPC_FilterValue, 89, 4, 0, // Skip to: 130
/* 126 */     MCD::OPC_Decode, 132, 3, 7, // Opcode: C
/* 130 */     MCD::OPC_FilterValue, 90, 3, 0, // Skip to: 137
/* 134 */     MCD::OPC_Decode, 19, 10, // Opcode: A
/* 137 */     MCD::OPC_FilterValue, 91, 4, 0, // Skip to: 145
/* 141 */     MCD::OPC_Decode, 132, 6, 10, // Opcode: S
/* 145 */     MCD::OPC_FilterValue, 94, 3, 0, // Skip to: 152
/* 149 */     MCD::OPC_Decode, 46, 10, // Opcode: AL
/* 152 */     MCD::OPC_FilterValue, 95, 4, 0, // Skip to: 160
/* 156 */     MCD::OPC_Decode, 144, 6, 10, // Opcode: SL
/* 160 */     MCD::OPC_FilterValue, 96, 4, 0, // Skip to: 168
/* 164 */     MCD::OPC_Decode, 183, 6, 11, // Opcode: STD
/* 168 */     MCD::OPC_FilterValue, 104, 4, 0, // Skip to: 176
/* 172 */     MCD::OPC_Decode, 168, 4, 11, // Opcode: LD
/* 176 */     MCD::OPC_FilterValue, 112, 4, 0, // Skip to: 184
/* 180 */     MCD::OPC_Decode, 185, 6, 12, // Opcode: STE
/* 184 */     MCD::OPC_FilterValue, 113, 4, 0, // Skip to: 192
/* 188 */     MCD::OPC_Decode, 163, 5, 10, // Opcode: MS
/* 192 */     MCD::OPC_FilterValue, 120, 4, 0, // Skip to: 200
/* 196 */     MCD::OPC_Decode, 175, 4, 12, // Opcode: LE
/* 200 */     MCD::OPC_FilterValue, 136, 1, 10, 0, // Skip to: 215
/* 205 */     MCD::OPC_CheckField, 16, 4, 0, 38, 11, // Skip to: 3065
/* 211 */     MCD::OPC_Decode, 172, 6, 13, // Opcode: SRL
/* 215 */     MCD::OPC_FilterValue, 137, 1, 10, 0, // Skip to: 230
/* 220 */     MCD::OPC_CheckField, 16, 4, 0, 23, 11, // Skip to: 3065
/* 226 */     MCD::OPC_Decode, 156, 6, 13, // Opcode: SLL
/* 230 */     MCD::OPC_FilterValue, 138, 1, 10, 0, // Skip to: 245
/* 235 */     MCD::OPC_CheckField, 16, 4, 0, 8, 11, // Skip to: 3065
/* 241 */     MCD::OPC_Decode, 168, 6, 13, // Opcode: SRA
/* 245 */     MCD::OPC_FilterValue, 145, 1, 4, 0, // Skip to: 254
/* 250 */     MCD::OPC_Decode, 212, 6, 14, // Opcode: TM
/* 254 */     MCD::OPC_FilterValue, 146, 1, 4, 0, // Skip to: 263
/* 259 */     MCD::OPC_Decode, 182, 5, 14, // Opcode: MVI
/* 263 */     MCD::OPC_FilterValue, 148, 1, 4, 0, // Skip to: 272
/* 268 */     MCD::OPC_Decode, 196, 5, 14, // Opcode: NI
/* 272 */     MCD::OPC_FilterValue, 149, 1, 4, 0, // Skip to: 281
/* 277 */     MCD::OPC_Decode, 192, 3, 14, // Opcode: CLI
/* 281 */     MCD::OPC_FilterValue, 150, 1, 4, 0, // Skip to: 290
/* 286 */     MCD::OPC_Decode, 223, 5, 14, // Opcode: OI
/* 290 */     MCD::OPC_FilterValue, 151, 1, 4, 0, // Skip to: 299
/* 295 */     MCD::OPC_Decode, 231, 6, 14, // Opcode: XI
/* 299 */     MCD::OPC_FilterValue, 165, 1, 131, 0, // Skip to: 435
/* 304 */     MCD::OPC_ExtractField, 16, 4,  // Inst{19-16} ...
/* 307 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 315
/* 311 */     MCD::OPC_Decode, 138, 4, 15, // Opcode: IIHH
/* 315 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 323
/* 319 */     MCD::OPC_Decode, 140, 4, 15, // Opcode: IIHL
/* 323 */     MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 331
/* 327 */     MCD::OPC_Decode, 145, 4, 16, // Opcode: IILH
/* 331 */     MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 339
/* 335 */     MCD::OPC_Decode, 147, 4, 16, // Opcode: IILL
/* 339 */     MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 347
/* 343 */     MCD::OPC_Decode, 200, 5, 15, // Opcode: NIHH
/* 347 */     MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 355
/* 351 */     MCD::OPC_Decode, 202, 5, 15, // Opcode: NIHL
/* 355 */     MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 363
/* 359 */     MCD::OPC_Decode, 207, 5, 16, // Opcode: NILH
/* 363 */     MCD::OPC_FilterValue, 7, 4, 0, // Skip to: 371
/* 367 */     MCD::OPC_Decode, 209, 5, 16, // Opcode: NILL
/* 371 */     MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 379
/* 375 */     MCD::OPC_Decode, 227, 5, 15, // Opcode: OIHH
/* 379 */     MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 387
/* 383 */     MCD::OPC_Decode, 229, 5, 15, // Opcode: OIHL
/* 387 */     MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 395
/* 391 */     MCD::OPC_Decode, 234, 5, 16, // Opcode: OILH
/* 395 */     MCD::OPC_FilterValue, 11, 4, 0, // Skip to: 403
/* 399 */     MCD::OPC_Decode, 236, 5, 16, // Opcode: OILL
/* 403 */     MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 411
/* 407 */     MCD::OPC_Decode, 223, 4, 17, // Opcode: LLIHH
/* 411 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 419
/* 415 */     MCD::OPC_Decode, 224, 4, 17, // Opcode: LLIHL
/* 419 */     MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 427
/* 423 */     MCD::OPC_Decode, 226, 4, 17, // Opcode: LLILH
/* 427 */     MCD::OPC_FilterValue, 15, 74, 10, // Skip to: 3065
/* 431 */     MCD::OPC_Decode, 227, 4, 17, // Opcode: LLILL
/* 435 */     MCD::OPC_FilterValue, 167, 1, 252, 0, // Skip to: 692
/* 440 */     MCD::OPC_ExtractField, 16, 4,  // Inst{19-16} ...
/* 443 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 451
/* 447 */     MCD::OPC_Decode, 218, 6, 18, // Opcode: TMLH
/* 451 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 459
/* 455 */     MCD::OPC_Decode, 220, 6, 18, // Opcode: TMLL
/* 459 */     MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 467
/* 463 */     MCD::OPC_Decode, 213, 6, 19, // Opcode: TMHH
/* 467 */     MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 475
/* 471 */     MCD::OPC_Decode, 215, 6, 19, // Opcode: TMHL
/* 475 */     MCD::OPC_FilterValue, 4, 127, 0, // Skip to: 606
/* 479 */     MCD::OPC_ExtractField, 20, 4,  // Inst{23-20} ...
/* 482 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 490
/* 486 */     MCD::OPC_Decode, 242, 2, 20, // Opcode: AsmOJ
/* 490 */     MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 498
/* 494 */     MCD::OPC_Decode, 171, 1, 20, // Opcode: AsmHJ
/* 498 */     MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 506
/* 502 */     MCD::OPC_Decode, 207, 2, 20, // Opcode: AsmNLEJ
/* 506 */     MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 514
/* 510 */     MCD::OPC_Decode, 166, 2, 20, // Opcode: AsmLJ
/* 514 */     MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 522
/* 518 */     MCD::OPC_Decode, 189, 2, 20, // Opcode: AsmNHEJ
/* 522 */     MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 530
/* 526 */     MCD::OPC_Decode, 158, 2, 20, // Opcode: AsmLHJ
/* 530 */     MCD::OPC_FilterValue, 7, 4, 0, // Skip to: 538
/* 534 */     MCD::OPC_Decode, 179, 2, 20, // Opcode: AsmNEJ
/* 538 */     MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 546
/* 542 */     MCD::OPC_Decode, 153, 1, 20, // Opcode: AsmEJ
/* 546 */     MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 554
/* 550 */     MCD::OPC_Decode, 216, 2, 20, // Opcode: AsmNLHJ
/* 554 */     MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 562
/* 558 */     MCD::OPC_Decode, 163, 1, 20, // Opcode: AsmHEJ
/* 562 */     MCD::OPC_FilterValue, 11, 4, 0, // Skip to: 570
/* 566 */     MCD::OPC_Decode, 224, 2, 20, // Opcode: AsmNLJ
/* 570 */     MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 578
/* 574 */     MCD::OPC_Decode, 149, 2, 20, // Opcode: AsmLEJ
/* 578 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 586
/* 582 */     MCD::OPC_Decode, 197, 2, 20, // Opcode: AsmNHJ
/* 586 */     MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 594
/* 590 */     MCD::OPC_Decode, 233, 2, 20, // Opcode: AsmNOJ
/* 594 */     MCD::OPC_FilterValue, 15, 4, 0, // Skip to: 602
/* 598 */     MCD::OPC_Decode, 151, 4, 20, // Opcode: J
/* 602 */     MCD::OPC_Decode, 142, 1, 21, // Opcode: AsmBRC
/* 606 */     MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 614
/* 610 */     MCD::OPC_Decode, 254, 2, 22, // Opcode: BRAS
/* 614 */     MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 622
/* 618 */     MCD::OPC_Decode, 130, 3, 23, // Opcode: BRCT
/* 622 */     MCD::OPC_FilterValue, 7, 4, 0, // Skip to: 630
/* 626 */     MCD::OPC_Decode, 131, 3, 24, // Opcode: BRCTG
/* 630 */     MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 638
/* 634 */     MCD::OPC_Decode, 197, 4, 25, // Opcode: LHI
/* 638 */     MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 646
/* 642 */     MCD::OPC_Decode, 190, 4, 26, // Opcode: LGHI
/* 646 */     MCD::OPC_FilterValue, 10, 3, 0, // Skip to: 653
/* 650 */     MCD::OPC_Decode, 40, 27, // Opcode: AHI
/* 653 */     MCD::OPC_FilterValue, 11, 3, 0, // Skip to: 660
/* 657 */     MCD::OPC_Decode, 34, 28, // Opcode: AGHI
/* 660 */     MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 668
/* 664 */     MCD::OPC_Decode, 159, 5, 27, // Opcode: MHI
/* 668 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 676
/* 672 */     MCD::OPC_Decode, 157, 5, 28, // Opcode: MGHI
/* 676 */     MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 684
/* 680 */     MCD::OPC_Decode, 165, 3, 25, // Opcode: CHI
/* 684 */     MCD::OPC_FilterValue, 15, 73, 9, // Skip to: 3065
/* 688 */     MCD::OPC_Decode, 154, 3, 26, // Opcode: CGHI
/* 692 */     MCD::OPC_FilterValue, 178, 1, 68, 0, // Skip to: 765
/* 697 */     MCD::OPC_ExtractField, 8, 16,  // Inst{23-8} ...
/* 700 */     MCD::OPC_FilterValue, 128, 68, 10, 0, // Skip to: 715
/* 705 */     MCD::OPC_CheckField, 0, 4, 0, 50, 9, // Skip to: 3065
/* 711 */     MCD::OPC_Decode, 150, 4, 29, // Opcode: IPM
/* 715 */     MCD::OPC_FilterValue, 128, 158, 1, 4, 0, // Skip to: 725
/* 721 */     MCD::OPC_Decode, 251, 3, 30, // Opcode: EAR
/* 725 */     MCD::OPC_FilterValue, 128, 164, 1, 4, 0, // Skip to: 735
/* 731 */     MCD::OPC_Decode, 174, 5, 4, // Opcode: MSR
/* 735 */     MCD::OPC_FilterValue, 128, 170, 1, 4, 0, // Skip to: 745
/* 741 */     MCD::OPC_Decode, 184, 5, 31, // Opcode: MVST
/* 745 */     MCD::OPC_FilterValue, 128, 186, 1, 4, 0, // Skip to: 755
/* 751 */     MCD::OPC_Decode, 200, 3, 31, // Opcode: CLST
/* 755 */     MCD::OPC_FilterValue, 128, 188, 1, 0, 9, // Skip to: 3065
/* 761 */     MCD::OPC_Decode, 175, 6, 31, // Opcode: SRST
/* 765 */     MCD::OPC_FilterValue, 179, 1, 185, 3, // Skip to: 1723
/* 770 */     MCD::OPC_ExtractField, 16, 8,  // Inst{23-16} ...
/* 773 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 787
/* 777 */     MCD::OPC_CheckField, 8, 8, 0, 234, 8, // Skip to: 3065
/* 783 */     MCD::OPC_Decode, 241, 4, 6, // Opcode: LPEBR
/* 787 */     MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 801
/* 791 */     MCD::OPC_CheckField, 8, 8, 0, 220, 8, // Skip to: 3065
/* 797 */     MCD::OPC_Decode, 231, 4, 6, // Opcode: LNEBR
/* 801 */     MCD::OPC_FilterValue, 2, 10, 0, // Skip to: 815
/* 805 */     MCD::OPC_CheckField, 8, 8, 0, 206, 8, // Skip to: 3065
/* 811 */     MCD::OPC_Decode, 128, 5, 6, // Opcode: LTEBR
/* 815 */     MCD::OPC_FilterValue, 3, 10, 0, // Skip to: 829
/* 819 */     MCD::OPC_CheckField, 8, 8, 0, 192, 8, // Skip to: 3065
/* 825 */     MCD::OPC_Decode, 163, 4, 6, // Opcode: LCEBR
/* 829 */     MCD::OPC_FilterValue, 4, 10, 0, // Skip to: 843
/* 833 */     MCD::OPC_CheckField, 8, 8, 0, 178, 8, // Skip to: 3065
/* 839 */     MCD::OPC_Decode, 170, 4, 32, // Opcode: LDEBR
/* 843 */     MCD::OPC_FilterValue, 5, 10, 0, // Skip to: 857
/* 847 */     MCD::OPC_CheckField, 8, 8, 0, 164, 8, // Skip to: 3065
/* 853 */     MCD::OPC_Decode, 139, 5, 33, // Opcode: LXDBR
/* 857 */     MCD::OPC_FilterValue, 6, 10, 0, // Skip to: 871
/* 861 */     MCD::OPC_CheckField, 8, 8, 0, 150, 8, // Skip to: 3065
/* 867 */     MCD::OPC_Decode, 141, 5, 34, // Opcode: LXEBR
/* 871 */     MCD::OPC_FilterValue, 7, 10, 0, // Skip to: 885
/* 875 */     MCD::OPC_CheckField, 8, 8, 0, 136, 8, // Skip to: 3065
/* 881 */     MCD::OPC_Decode, 188, 5, 35, // Opcode: MXDBR
/* 885 */     MCD::OPC_FilterValue, 9, 10, 0, // Skip to: 899
/* 889 */     MCD::OPC_CheckField, 8, 8, 0, 122, 8, // Skip to: 3065
/* 895 */     MCD::OPC_Decode, 138, 3, 6, // Opcode: CEBR
/* 899 */     MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 912
/* 903 */     MCD::OPC_CheckField, 8, 8, 0, 108, 8, // Skip to: 3065
/* 909 */     MCD::OPC_Decode, 26, 36, // Opcode: AEBR
/* 912 */     MCD::OPC_FilterValue, 11, 10, 0, // Skip to: 926
/* 916 */     MCD::OPC_CheckField, 8, 8, 0, 95, 8, // Skip to: 3065
/* 922 */     MCD::OPC_Decode, 136, 6, 36, // Opcode: SEBR
/* 926 */     MCD::OPC_FilterValue, 12, 10, 0, // Skip to: 940
/* 930 */     MCD::OPC_CheckField, 8, 8, 0, 81, 8, // Skip to: 3065
/* 936 */     MCD::OPC_Decode, 154, 5, 37, // Opcode: MDEBR
/* 940 */     MCD::OPC_FilterValue, 13, 10, 0, // Skip to: 954
/* 944 */     MCD::OPC_CheckField, 8, 8, 0, 67, 8, // Skip to: 3065
/* 950 */     MCD::OPC_Decode, 241, 3, 36, // Opcode: DEBR
/* 954 */     MCD::OPC_FilterValue, 14, 10, 0, // Skip to: 968
/* 958 */     MCD::OPC_CheckField, 8, 4, 0, 53, 8, // Skip to: 3065
/* 964 */     MCD::OPC_Decode, 150, 5, 38, // Opcode: MAEBR
/* 968 */     MCD::OPC_FilterValue, 15, 10, 0, // Skip to: 982
/* 972 */     MCD::OPC_CheckField, 8, 4, 0, 39, 8, // Skip to: 3065
/* 978 */     MCD::OPC_Decode, 167, 5, 38, // Opcode: MSEBR
/* 982 */     MCD::OPC_FilterValue, 16, 10, 0, // Skip to: 996
/* 986 */     MCD::OPC_CheckField, 8, 8, 0, 25, 8, // Skip to: 3065
/* 992 */     MCD::OPC_Decode, 240, 4, 5, // Opcode: LPDBR
/* 996 */     MCD::OPC_FilterValue, 17, 10, 0, // Skip to: 1010
/* 1000 */    MCD::OPC_CheckField, 8, 8, 0, 11, 8, // Skip to: 3065
/* 1006 */    MCD::OPC_Decode, 230, 4, 5, // Opcode: LNDBR
/* 1010 */    MCD::OPC_FilterValue, 18, 10, 0, // Skip to: 1024
/* 1014 */    MCD::OPC_CheckField, 8, 8, 0, 253, 7, // Skip to: 3065
/* 1020 */    MCD::OPC_Decode, 254, 4, 5, // Opcode: LTDBR
/* 1024 */    MCD::OPC_FilterValue, 19, 10, 0, // Skip to: 1038
/* 1028 */    MCD::OPC_CheckField, 8, 8, 0, 239, 7, // Skip to: 3065
/* 1034 */    MCD::OPC_Decode, 162, 4, 5, // Opcode: LCDBR
/* 1038 */    MCD::OPC_FilterValue, 20, 10, 0, // Skip to: 1052
/* 1042 */    MCD::OPC_CheckField, 8, 8, 0, 225, 7, // Skip to: 3065
/* 1048 */    MCD::OPC_Decode, 165, 6, 6, // Opcode: SQEBR
/* 1052 */    MCD::OPC_FilterValue, 21, 10, 0, // Skip to: 1066
/* 1056 */    MCD::OPC_CheckField, 8, 8, 0, 211, 7, // Skip to: 3065
/* 1062 */    MCD::OPC_Decode, 163, 6, 5, // Opcode: SQDBR
/* 1066 */    MCD::OPC_FilterValue, 22, 10, 0, // Skip to: 1080
/* 1070 */    MCD::OPC_CheckField, 8, 8, 0, 197, 7, // Skip to: 3065
/* 1076 */    MCD::OPC_Decode, 166, 6, 39, // Opcode: SQXBR
/* 1080 */    MCD::OPC_FilterValue, 23, 10, 0, // Skip to: 1094
/* 1084 */    MCD::OPC_CheckField, 8, 8, 0, 183, 7, // Skip to: 3065
/* 1090 */    MCD::OPC_Decode, 156, 5, 36, // Opcode: MEEBR
/* 1094 */    MCD::OPC_FilterValue, 25, 10, 0, // Skip to: 1108
/* 1098 */    MCD::OPC_CheckField, 8, 8, 0, 169, 7, // Skip to: 3065
/* 1104 */    MCD::OPC_Decode, 134, 3, 5, // Opcode: CDBR
/* 1108 */    MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 1121
/* 1112 */    MCD::OPC_CheckField, 8, 8, 0, 155, 7, // Skip to: 3065
/* 1118 */    MCD::OPC_Decode, 21, 40, // Opcode: ADBR
/* 1121 */    MCD::OPC_FilterValue, 27, 10, 0, // Skip to: 1135
/* 1125 */    MCD::OPC_CheckField, 8, 8, 0, 142, 7, // Skip to: 3065
/* 1131 */    MCD::OPC_Decode, 134, 6, 40, // Opcode: SDBR
/* 1135 */    MCD::OPC_FilterValue, 28, 10, 0, // Skip to: 1149
/* 1139 */    MCD::OPC_CheckField, 8, 8, 0, 128, 7, // Skip to: 3065
/* 1145 */    MCD::OPC_Decode, 152, 5, 40, // Opcode: MDBR
/* 1149 */    MCD::OPC_FilterValue, 29, 10, 0, // Skip to: 1163
/* 1153 */    MCD::OPC_CheckField, 8, 8, 0, 114, 7, // Skip to: 3065
/* 1159 */    MCD::OPC_Decode, 239, 3, 40, // Opcode: DDBR
/* 1163 */    MCD::OPC_FilterValue, 30, 10, 0, // Skip to: 1177
/* 1167 */    MCD::OPC_CheckField, 8, 4, 0, 100, 7, // Skip to: 3065
/* 1173 */    MCD::OPC_Decode, 148, 5, 41, // Opcode: MADBR
/* 1177 */    MCD::OPC_FilterValue, 31, 10, 0, // Skip to: 1191
/* 1181 */    MCD::OPC_CheckField, 8, 4, 0, 86, 7, // Skip to: 3065
/* 1187 */    MCD::OPC_Decode, 165, 5, 41, // Opcode: MSDBR
/* 1191 */    MCD::OPC_FilterValue, 64, 10, 0, // Skip to: 1205
/* 1195 */    MCD::OPC_CheckField, 8, 8, 0, 72, 7, // Skip to: 3065
/* 1201 */    MCD::OPC_Decode, 245, 4, 39, // Opcode: LPXBR
/* 1205 */    MCD::OPC_FilterValue, 65, 10, 0, // Skip to: 1219
/* 1209 */    MCD::OPC_CheckField, 8, 8, 0, 58, 7, // Skip to: 3065
/* 1215 */    MCD::OPC_Decode, 235, 4, 39, // Opcode: LNXBR
/* 1219 */    MCD::OPC_FilterValue, 66, 10, 0, // Skip to: 1233
/* 1223 */    MCD::OPC_CheckField, 8, 8, 0, 44, 7, // Skip to: 3065
/* 1229 */    MCD::OPC_Decode, 135, 5, 39, // Opcode: LTXBR
/* 1233 */    MCD::OPC_FilterValue, 67, 10, 0, // Skip to: 1247
/* 1237 */    MCD::OPC_CheckField, 8, 8, 0, 30, 7, // Skip to: 3065
/* 1243 */    MCD::OPC_Decode, 167, 4, 39, // Opcode: LCXBR
/* 1247 */    MCD::OPC_FilterValue, 68, 10, 0, // Skip to: 1261
/* 1251 */    MCD::OPC_CheckField, 8, 8, 0, 16, 7, // Skip to: 3065
/* 1257 */    MCD::OPC_Decode, 176, 4, 42, // Opcode: LEDBR
/* 1261 */    MCD::OPC_FilterValue, 69, 10, 0, // Skip to: 1275
/* 1265 */    MCD::OPC_CheckField, 8, 8, 0, 2, 7, // Skip to: 3065
/* 1271 */    MCD::OPC_Decode, 173, 4, 39, // Opcode: LDXBR
/* 1275 */    MCD::OPC_FilterValue, 70, 10, 0, // Skip to: 1289
/* 1279 */    MCD::OPC_CheckField, 8, 8, 0, 244, 6, // Skip to: 3065
/* 1285 */    MCD::OPC_Decode, 178, 4, 39, // Opcode: LEXBR
/* 1289 */    MCD::OPC_FilterValue, 71, 18, 0, // Skip to: 1311
/* 1293 */    MCD::OPC_CheckField, 8, 4, 0, 4, 0, // Skip to: 1303
/* 1299 */    MCD::OPC_Decode, 128, 4, 43, // Opcode: FIXBR
/* 1303 */    MCD::OPC_CheckPredicate, 0, 222, 6, // Skip to: 3065
/* 1307 */    MCD::OPC_Decode, 129, 4, 44, // Opcode: FIXBRA
/* 1311 */    MCD::OPC_FilterValue, 73, 10, 0, // Skip to: 1325
/* 1315 */    MCD::OPC_CheckField, 8, 8, 0, 208, 6, // Skip to: 3065
/* 1321 */    MCD::OPC_Decode, 214, 3, 39, // Opcode: CXBR
/* 1325 */    MCD::OPC_FilterValue, 74, 10, 0, // Skip to: 1339
/* 1329 */    MCD::OPC_CheckField, 8, 8, 0, 194, 6, // Skip to: 3065
/* 1335 */    MCD::OPC_Decode, 139, 1, 45, // Opcode: AXBR
/* 1339 */    MCD::OPC_FilterValue, 75, 10, 0, // Skip to: 1353
/* 1343 */    MCD::OPC_CheckField, 8, 8, 0, 180, 6, // Skip to: 3065
/* 1349 */    MCD::OPC_Decode, 204, 6, 45, // Opcode: SXBR
/* 1353 */    MCD::OPC_FilterValue, 76, 10, 0, // Skip to: 1367
/* 1357 */    MCD::OPC_CheckField, 8, 8, 0, 166, 6, // Skip to: 3065
/* 1363 */    MCD::OPC_Decode, 186, 5, 45, // Opcode: MXBR
/* 1367 */    MCD::OPC_FilterValue, 77, 10, 0, // Skip to: 1381
/* 1371 */    MCD::OPC_CheckField, 8, 8, 0, 152, 6, // Skip to: 3065
/* 1377 */    MCD::OPC_Decode, 250, 3, 45, // Opcode: DXBR
/* 1381 */    MCD::OPC_FilterValue, 87, 18, 0, // Skip to: 1403
/* 1385 */    MCD::OPC_CheckField, 8, 4, 0, 4, 0, // Skip to: 1395
/* 1391 */    MCD::OPC_Decode, 254, 3, 46, // Opcode: FIEBR
/* 1395 */    MCD::OPC_CheckPredicate, 0, 130, 6, // Skip to: 3065
/* 1399 */    MCD::OPC_Decode, 255, 3, 47, // Opcode: FIEBRA
/* 1403 */    MCD::OPC_FilterValue, 95, 18, 0, // Skip to: 1425
/* 1407 */    MCD::OPC_CheckField, 8, 4, 0, 4, 0, // Skip to: 1417
/* 1413 */    MCD::OPC_Decode, 252, 3, 48, // Opcode: FIDBR
/* 1417 */    MCD::OPC_CheckPredicate, 0, 108, 6, // Skip to: 3065
/* 1421 */    MCD::OPC_Decode, 253, 3, 49, // Opcode: FIDBRA
/* 1425 */    MCD::OPC_FilterValue, 101, 10, 0, // Skip to: 1439
/* 1429 */    MCD::OPC_CheckField, 8, 8, 0, 94, 6, // Skip to: 3065
/* 1435 */    MCD::OPC_Decode, 142, 5, 39, // Opcode: LXR
/* 1439 */    MCD::OPC_FilterValue, 114, 10, 0, // Skip to: 1453
/* 1443 */    MCD::OPC_CheckField, 8, 4, 0, 80, 6, // Skip to: 3065
/* 1449 */    MCD::OPC_Decode, 204, 3, 50, // Opcode: CPSDRdd
/* 1453 */    MCD::OPC_FilterValue, 116, 16, 0, // Skip to: 1473
/* 1457 */    MCD::OPC_CheckField, 8, 8, 0, 66, 6, // Skip to: 3065
/* 1463 */    MCD::OPC_CheckField, 0, 4, 0, 60, 6, // Skip to: 3065
/* 1469 */    MCD::OPC_Decode, 145, 5, 51, // Opcode: LZER
/* 1473 */    MCD::OPC_FilterValue, 117, 16, 0, // Skip to: 1493
/* 1477 */    MCD::OPC_CheckField, 8, 8, 0, 46, 6, // Skip to: 3065
/* 1483 */    MCD::OPC_CheckField, 0, 4, 0, 40, 6, // Skip to: 3065
/* 1489 */    MCD::OPC_Decode, 144, 5, 52, // Opcode: LZDR
/* 1493 */    MCD::OPC_FilterValue, 118, 16, 0, // Skip to: 1513
/* 1497 */    MCD::OPC_CheckField, 8, 8, 0, 26, 6, // Skip to: 3065
/* 1503 */    MCD::OPC_CheckField, 0, 4, 0, 20, 6, // Skip to: 3065
/* 1509 */    MCD::OPC_Decode, 146, 5, 53, // Opcode: LZXR
/* 1513 */    MCD::OPC_FilterValue, 148, 1, 10, 0, // Skip to: 1528
/* 1518 */    MCD::OPC_CheckField, 8, 8, 0, 5, 6, // Skip to: 3065
/* 1524 */    MCD::OPC_Decode, 139, 3, 54, // Opcode: CEFBR
/* 1528 */    MCD::OPC_FilterValue, 149, 1, 10, 0, // Skip to: 1543
/* 1533 */    MCD::OPC_CheckField, 8, 8, 0, 246, 5, // Skip to: 3065
/* 1539 */    MCD::OPC_Decode, 135, 3, 55, // Opcode: CDFBR
/* 1543 */    MCD::OPC_FilterValue, 150, 1, 10, 0, // Skip to: 1558
/* 1548 */    MCD::OPC_CheckField, 8, 8, 0, 231, 5, // Skip to: 3065
/* 1554 */    MCD::OPC_Decode, 215, 3, 56, // Opcode: CXFBR
/* 1558 */    MCD::OPC_FilterValue, 152, 1, 10, 0, // Skip to: 1573
/* 1563 */    MCD::OPC_CheckField, 8, 4, 0, 216, 5, // Skip to: 3065
/* 1569 */    MCD::OPC_Decode, 142, 3, 57, // Opcode: CFEBR
/* 1573 */    MCD::OPC_FilterValue, 153, 1, 10, 0, // Skip to: 1588
/* 1578 */    MCD::OPC_CheckField, 8, 4, 0, 201, 5, // Skip to: 3065
/* 1584 */    MCD::OPC_Decode, 141, 3, 58, // Opcode: CFDBR
/* 1588 */    MCD::OPC_FilterValue, 154, 1, 10, 0, // Skip to: 1603
/* 1593 */    MCD::OPC_CheckField, 8, 4, 0, 186, 5, // Skip to: 3065
/* 1599 */    MCD::OPC_Decode, 145, 3, 59, // Opcode: CFXBR
/* 1603 */    MCD::OPC_FilterValue, 164, 1, 10, 0, // Skip to: 1618
/* 1608 */    MCD::OPC_CheckField, 8, 8, 0, 171, 5, // Skip to: 3065
/* 1614 */    MCD::OPC_Decode, 140, 3, 60, // Opcode: CEGBR
/* 1618 */    MCD::OPC_FilterValue, 165, 1, 10, 0, // Skip to: 1633
/* 1623 */    MCD::OPC_CheckField, 8, 8, 0, 156, 5, // Skip to: 3065
/* 1629 */    MCD::OPC_Decode, 136, 3, 61, // Opcode: CDGBR
/* 1633 */    MCD::OPC_FilterValue, 166, 1, 10, 0, // Skip to: 1648
/* 1638 */    MCD::OPC_CheckField, 8, 8, 0, 141, 5, // Skip to: 3065
/* 1644 */    MCD::OPC_Decode, 216, 3, 62, // Opcode: CXGBR
/* 1648 */    MCD::OPC_FilterValue, 168, 1, 10, 0, // Skip to: 1663
/* 1653 */    MCD::OPC_CheckField, 8, 4, 0, 126, 5, // Skip to: 3065
/* 1659 */    MCD::OPC_Decode, 148, 3, 63, // Opcode: CGEBR
/* 1663 */    MCD::OPC_FilterValue, 169, 1, 10, 0, // Skip to: 1678
/* 1668 */    MCD::OPC_CheckField, 8, 4, 0, 111, 5, // Skip to: 3065
/* 1674 */    MCD::OPC_Decode, 147, 3, 64, // Opcode: CGDBR
/* 1678 */    MCD::OPC_FilterValue, 170, 1, 10, 0, // Skip to: 1693
/* 1683 */    MCD::OPC_CheckField, 8, 4, 0, 96, 5, // Skip to: 3065
/* 1689 */    MCD::OPC_Decode, 161, 3, 65, // Opcode: CGXBR
/* 1693 */    MCD::OPC_FilterValue, 193, 1, 10, 0, // Skip to: 1708
/* 1698 */    MCD::OPC_CheckField, 8, 8, 0, 81, 5, // Skip to: 3065
/* 1704 */    MCD::OPC_Decode, 171, 4, 61, // Opcode: LDGR
/* 1708 */    MCD::OPC_FilterValue, 205, 1, 72, 5, // Skip to: 3065
/* 1713 */    MCD::OPC_CheckField, 8, 8, 0, 66, 5, // Skip to: 3065
/* 1719 */    MCD::OPC_Decode, 184, 4, 66, // Opcode: LGDR
/* 1723 */    MCD::OPC_FilterValue, 185, 1, 48, 5, // Skip to: 3056
/* 1728 */    MCD::OPC_ExtractField, 16, 8,  // Inst{23-16} ...
/* 1731 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1745
/* 1735 */    MCD::OPC_CheckField, 8, 8, 0, 44, 5, // Skip to: 3065
/* 1741 */    MCD::OPC_Decode, 243, 4, 67, // Opcode: LPGR
/* 1745 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 1759
/* 1749 */    MCD::OPC_CheckField, 8, 8, 0, 30, 5, // Skip to: 3065
/* 1755 */    MCD::OPC_Decode, 233, 4, 67, // Opcode: LNGR
/* 1759 */    MCD::OPC_FilterValue, 2, 10, 0, // Skip to: 1773
/* 1763 */    MCD::OPC_CheckField, 8, 8, 0, 16, 5, // Skip to: 3065
/* 1769 */    MCD::OPC_Decode, 133, 5, 67, // Opcode: LTGR
/* 1773 */    MCD::OPC_FilterValue, 3, 10, 0, // Skip to: 1787
/* 1777 */    MCD::OPC_CheckField, 8, 8, 0, 2, 5, // Skip to: 3065
/* 1783 */    MCD::OPC_Decode, 165, 4, 67, // Opcode: LCGR
/* 1787 */    MCD::OPC_FilterValue, 4, 10, 0, // Skip to: 1801
/* 1791 */    MCD::OPC_CheckField, 8, 8, 0, 244, 4, // Skip to: 3065
/* 1797 */    MCD::OPC_Decode, 193, 4, 67, // Opcode: LGR
/* 1801 */    MCD::OPC_FilterValue, 6, 10, 0, // Skip to: 1815
/* 1805 */    MCD::OPC_CheckField, 8, 8, 0, 230, 4, // Skip to: 3065
/* 1811 */    MCD::OPC_Decode, 183, 4, 67, // Opcode: LGBR
/* 1815 */    MCD::OPC_FilterValue, 7, 10, 0, // Skip to: 1829
/* 1819 */    MCD::OPC_CheckField, 8, 8, 0, 216, 4, // Skip to: 3065
/* 1825 */    MCD::OPC_Decode, 191, 4, 67, // Opcode: LGHR
/* 1829 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 1842
/* 1833 */    MCD::OPC_CheckField, 8, 8, 0, 202, 4, // Skip to: 3065
/* 1839 */    MCD::OPC_Decode, 36, 68, // Opcode: AGR
/* 1842 */    MCD::OPC_FilterValue, 9, 10, 0, // Skip to: 1856
/* 1846 */    MCD::OPC_CheckField, 8, 8, 0, 189, 4, // Skip to: 3065
/* 1852 */    MCD::OPC_Decode, 140, 6, 68, // Opcode: SGR
/* 1856 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 1869
/* 1860 */    MCD::OPC_CheckField, 8, 8, 0, 175, 4, // Skip to: 3065
/* 1866 */    MCD::OPC_Decode, 57, 68, // Opcode: ALGR
/* 1869 */    MCD::OPC_FilterValue, 11, 10, 0, // Skip to: 1883
/* 1873 */    MCD::OPC_CheckField, 8, 8, 0, 162, 4, // Skip to: 3065
/* 1879 */    MCD::OPC_Decode, 154, 6, 68, // Opcode: SLGR
/* 1883 */    MCD::OPC_FilterValue, 12, 10, 0, // Skip to: 1897
/* 1887 */    MCD::OPC_CheckField, 8, 8, 0, 148, 4, // Skip to: 3065
/* 1893 */    MCD::OPC_Decode, 173, 5, 68, // Opcode: MSGR
/* 1897 */    MCD::OPC_FilterValue, 13, 10, 0, // Skip to: 1911
/* 1901 */    MCD::OPC_CheckField, 8, 8, 0, 134, 4, // Skip to: 3065
/* 1907 */    MCD::OPC_Decode, 249, 3, 69, // Opcode: DSGR
/* 1911 */    MCD::OPC_FilterValue, 15, 10, 0, // Skip to: 1925
/* 1915 */    MCD::OPC_CheckField, 8, 8, 0, 120, 4, // Skip to: 3065
/* 1921 */    MCD::OPC_Decode, 251, 4, 67, // Opcode: LRVGR
/* 1925 */    MCD::OPC_FilterValue, 16, 10, 0, // Skip to: 1939
/* 1929 */    MCD::OPC_CheckField, 8, 8, 0, 106, 4, // Skip to: 3065
/* 1935 */    MCD::OPC_Decode, 242, 4, 70, // Opcode: LPGFR
/* 1939 */    MCD::OPC_FilterValue, 17, 10, 0, // Skip to: 1953
/* 1943 */    MCD::OPC_CheckField, 8, 8, 0, 92, 4, // Skip to: 3065
/* 1949 */    MCD::OPC_Decode, 232, 4, 70, // Opcode: LNGFR
/* 1953 */    MCD::OPC_FilterValue, 18, 10, 0, // Skip to: 1967
/* 1957 */    MCD::OPC_CheckField, 8, 8, 0, 78, 4, // Skip to: 3065
/* 1963 */    MCD::OPC_Decode, 132, 5, 67, // Opcode: LTGFR
/* 1967 */    MCD::OPC_FilterValue, 19, 10, 0, // Skip to: 1981
/* 1971 */    MCD::OPC_CheckField, 8, 8, 0, 64, 4, // Skip to: 3065
/* 1977 */    MCD::OPC_Decode, 164, 4, 70, // Opcode: LCGFR
/* 1981 */    MCD::OPC_FilterValue, 20, 10, 0, // Skip to: 1995
/* 1985 */    MCD::OPC_CheckField, 8, 8, 0, 50, 4, // Skip to: 3065
/* 1991 */    MCD::OPC_Decode, 187, 4, 70, // Opcode: LGFR
/* 1995 */    MCD::OPC_FilterValue, 22, 10, 0, // Skip to: 2009
/* 1999 */    MCD::OPC_CheckField, 8, 8, 0, 36, 4, // Skip to: 3065
/* 2005 */    MCD::OPC_Decode, 211, 4, 70, // Opcode: LLGFR
/* 2009 */    MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 2022
/* 2013 */    MCD::OPC_CheckField, 8, 8, 0, 22, 4, // Skip to: 3065
/* 2019 */    MCD::OPC_Decode, 33, 71, // Opcode: AGFR
/* 2022 */    MCD::OPC_FilterValue, 25, 10, 0, // Skip to: 2036
/* 2026 */    MCD::OPC_CheckField, 8, 8, 0, 9, 4, // Skip to: 3065
/* 2032 */    MCD::OPC_Decode, 139, 6, 71, // Opcode: SGFR
/* 2036 */    MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 2049
/* 2040 */    MCD::OPC_CheckField, 8, 8, 0, 251, 3, // Skip to: 3065
/* 2046 */    MCD::OPC_Decode, 55, 71, // Opcode: ALGFR
/* 2049 */    MCD::OPC_FilterValue, 27, 10, 0, // Skip to: 2063
/* 2053 */    MCD::OPC_CheckField, 8, 8, 0, 238, 3, // Skip to: 3065
/* 2059 */    MCD::OPC_Decode, 153, 6, 71, // Opcode: SLGFR
/* 2063 */    MCD::OPC_FilterValue, 28, 10, 0, // Skip to: 2077
/* 2067 */    MCD::OPC_CheckField, 8, 8, 0, 224, 3, // Skip to: 3065
/* 2073 */    MCD::OPC_Decode, 172, 5, 71, // Opcode: MSGFR
/* 2077 */    MCD::OPC_FilterValue, 29, 10, 0, // Skip to: 2091
/* 2081 */    MCD::OPC_CheckField, 8, 8, 0, 210, 3, // Skip to: 3065
/* 2087 */    MCD::OPC_Decode, 248, 3, 72, // Opcode: DSGFR
/* 2091 */    MCD::OPC_FilterValue, 31, 10, 0, // Skip to: 2105
/* 2095 */    MCD::OPC_CheckField, 8, 8, 0, 196, 3, // Skip to: 3065
/* 2101 */    MCD::OPC_Decode, 252, 4, 3, // Opcode: LRVR
/* 2105 */    MCD::OPC_FilterValue, 32, 10, 0, // Skip to: 2119
/* 2109 */    MCD::OPC_CheckField, 8, 8, 0, 182, 3, // Skip to: 3065
/* 2115 */    MCD::OPC_Decode, 158, 3, 67, // Opcode: CGR
/* 2119 */    MCD::OPC_FilterValue, 33, 10, 0, // Skip to: 2133
/* 2123 */    MCD::OPC_CheckField, 8, 8, 0, 168, 3, // Skip to: 3065
/* 2129 */    MCD::OPC_Decode, 186, 3, 67, // Opcode: CLGR
/* 2133 */    MCD::OPC_FilterValue, 38, 10, 0, // Skip to: 2147
/* 2137 */    MCD::OPC_CheckField, 8, 8, 0, 154, 3, // Skip to: 3065
/* 2143 */    MCD::OPC_Decode, 161, 4, 3, // Opcode: LBR
/* 2147 */    MCD::OPC_FilterValue, 39, 10, 0, // Skip to: 2161
/* 2151 */    MCD::OPC_CheckField, 8, 8, 0, 140, 3, // Skip to: 3065
/* 2157 */    MCD::OPC_Decode, 200, 4, 3, // Opcode: LHR
/* 2161 */    MCD::OPC_FilterValue, 48, 10, 0, // Skip to: 2175
/* 2165 */    MCD::OPC_CheckField, 8, 8, 0, 126, 3, // Skip to: 3065
/* 2171 */    MCD::OPC_Decode, 151, 3, 70, // Opcode: CGFR
/* 2175 */    MCD::OPC_FilterValue, 49, 10, 0, // Skip to: 2189
/* 2179 */    MCD::OPC_CheckField, 8, 8, 0, 112, 3, // Skip to: 3065
/* 2185 */    MCD::OPC_Decode, 181, 3, 70, // Opcode: CLGFR
/* 2189 */    MCD::OPC_FilterValue, 128, 1, 10, 0, // Skip to: 2204
/* 2194 */    MCD::OPC_CheckField, 8, 8, 0, 97, 3, // Skip to: 3065
/* 2200 */    MCD::OPC_Decode, 194, 5, 68, // Opcode: NGR
/* 2204 */    MCD::OPC_FilterValue, 129, 1, 10, 0, // Skip to: 2219
/* 2209 */    MCD::OPC_CheckField, 8, 8, 0, 82, 3, // Skip to: 3065
/* 2215 */    MCD::OPC_Decode, 221, 5, 68, // Opcode: OGR
/* 2219 */    MCD::OPC_FilterValue, 130, 1, 10, 0, // Skip to: 2234
/* 2224 */    MCD::OPC_CheckField, 8, 8, 0, 67, 3, // Skip to: 3065
/* 2230 */    MCD::OPC_Decode, 229, 6, 68, // Opcode: XGR
/* 2234 */    MCD::OPC_FilterValue, 131, 1, 10, 0, // Skip to: 2249
/* 2239 */    MCD::OPC_CheckField, 8, 8, 0, 52, 3, // Skip to: 3065
/* 2245 */    MCD::OPC_Decode, 130, 4, 73, // Opcode: FLOGR
/* 2249 */    MCD::OPC_FilterValue, 132, 1, 10, 0, // Skip to: 2264
/* 2254 */    MCD::OPC_CheckField, 8, 8, 0, 37, 3, // Skip to: 3065
/* 2260 */    MCD::OPC_Decode, 209, 4, 67, // Opcode: LLGCR
/* 2264 */    MCD::OPC_FilterValue, 133, 1, 10, 0, // Skip to: 2279
/* 2269 */    MCD::OPC_CheckField, 8, 8, 0, 22, 3, // Skip to: 3065
/* 2275 */    MCD::OPC_Decode, 214, 4, 67, // Opcode: LLGHR
/* 2279 */    MCD::OPC_FilterValue, 134, 1, 10, 0, // Skip to: 2294
/* 2284 */    MCD::OPC_CheckField, 8, 8, 0, 7, 3, // Skip to: 3065
/* 2290 */    MCD::OPC_Decode, 162, 5, 69, // Opcode: MLGR
/* 2294 */    MCD::OPC_FilterValue, 135, 1, 10, 0, // Skip to: 2309
/* 2299 */    MCD::OPC_CheckField, 8, 8, 0, 248, 2, // Skip to: 3065
/* 2305 */    MCD::OPC_Decode, 244, 3, 69, // Opcode: DLGR
/* 2309 */    MCD::OPC_FilterValue, 136, 1, 9, 0, // Skip to: 2323
/* 2314 */    MCD::OPC_CheckField, 8, 8, 0, 233, 2, // Skip to: 3065
/* 2320 */    MCD::OPC_Decode, 49, 68, // Opcode: ALCGR
/* 2323 */    MCD::OPC_FilterValue, 137, 1, 10, 0, // Skip to: 2338
/* 2328 */    MCD::OPC_CheckField, 8, 8, 0, 219, 2, // Skip to: 3065
/* 2334 */    MCD::OPC_Decode, 150, 6, 68, // Opcode: SLGBR
/* 2338 */    MCD::OPC_FilterValue, 148, 1, 10, 0, // Skip to: 2353
/* 2343 */    MCD::OPC_CheckField, 8, 8, 0, 204, 2, // Skip to: 3065
/* 2349 */    MCD::OPC_Decode, 206, 4, 3, // Opcode: LLCR
/* 2353 */    MCD::OPC_FilterValue, 149, 1, 10, 0, // Skip to: 2368
/* 2358 */    MCD::OPC_CheckField, 8, 8, 0, 189, 2, // Skip to: 3065
/* 2364 */    MCD::OPC_Decode, 219, 4, 3, // Opcode: LLHR
/* 2368 */    MCD::OPC_FilterValue, 151, 1, 10, 0, // Skip to: 2383
/* 2373 */    MCD::OPC_CheckField, 8, 8, 0, 174, 2, // Skip to: 3065
/* 2379 */    MCD::OPC_Decode, 245, 3, 72, // Opcode: DLR
/* 2383 */    MCD::OPC_FilterValue, 152, 1, 9, 0, // Skip to: 2397
/* 2388 */    MCD::OPC_CheckField, 8, 8, 0, 159, 2, // Skip to: 3065
/* 2394 */    MCD::OPC_Decode, 50, 4, // Opcode: ALCR
/* 2397 */    MCD::OPC_FilterValue, 153, 1, 10, 0, // Skip to: 2412
/* 2402 */    MCD::OPC_CheckField, 8, 8, 0, 145, 2, // Skip to: 3065
/* 2408 */    MCD::OPC_Decode, 147, 6, 4, // Opcode: SLBR
/* 2412 */    MCD::OPC_FilterValue, 226, 1, 186, 0, // Skip to: 2603
/* 2417 */    MCD::OPC_ExtractField, 8, 4,  // Inst{11-8} ...
/* 2420 */    MCD::OPC_FilterValue, 0, 129, 2, // Skip to: 3065
/* 2424 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 2427 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 2439
/* 2431 */    MCD::OPC_CheckPredicate, 1, 160, 0, // Skip to: 2595
/* 2435 */    MCD::OPC_Decode, 246, 2, 68, // Opcode: AsmOLOCGR
/* 2439 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2451
/* 2443 */    MCD::OPC_CheckPredicate, 1, 148, 0, // Skip to: 2595
/* 2447 */    MCD::OPC_Decode, 175, 1, 68, // Opcode: AsmHLOCGR
/* 2451 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 2463
/* 2455 */    MCD::OPC_CheckPredicate, 1, 136, 0, // Skip to: 2595
/* 2459 */    MCD::OPC_Decode, 211, 2, 68, // Opcode: AsmNLELOCGR
/* 2463 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 2475
/* 2467 */    MCD::OPC_CheckPredicate, 1, 124, 0, // Skip to: 2595
/* 2471 */    MCD::OPC_Decode, 170, 2, 68, // Opcode: AsmLLOCGR
/* 2475 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 2487
/* 2479 */    MCD::OPC_CheckPredicate, 1, 112, 0, // Skip to: 2595
/* 2483 */    MCD::OPC_Decode, 193, 2, 68, // Opcode: AsmNHELOCGR
/* 2487 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 2499
/* 2491 */    MCD::OPC_CheckPredicate, 1, 100, 0, // Skip to: 2595
/* 2495 */    MCD::OPC_Decode, 162, 2, 68, // Opcode: AsmLHLOCGR
/* 2499 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 2511
/* 2503 */    MCD::OPC_CheckPredicate, 1, 88, 0, // Skip to: 2595
/* 2507 */    MCD::OPC_Decode, 183, 2, 68, // Opcode: AsmNELOCGR
/* 2511 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 2523
/* 2515 */    MCD::OPC_CheckPredicate, 1, 76, 0, // Skip to: 2595
/* 2519 */    MCD::OPC_Decode, 157, 1, 68, // Opcode: AsmELOCGR
/* 2523 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 2535
/* 2527 */    MCD::OPC_CheckPredicate, 1, 64, 0, // Skip to: 2595
/* 2531 */    MCD::OPC_Decode, 220, 2, 68, // Opcode: AsmNLHLOCGR
/* 2535 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 2547
/* 2539 */    MCD::OPC_CheckPredicate, 1, 52, 0, // Skip to: 2595
/* 2543 */    MCD::OPC_Decode, 167, 1, 68, // Opcode: AsmHELOCGR
/* 2547 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 2559
/* 2551 */    MCD::OPC_CheckPredicate, 1, 40, 0, // Skip to: 2595
/* 2555 */    MCD::OPC_Decode, 228, 2, 68, // Opcode: AsmNLLOCGR
/* 2559 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 2571
/* 2563 */    MCD::OPC_CheckPredicate, 1, 28, 0, // Skip to: 2595
/* 2567 */    MCD::OPC_Decode, 153, 2, 68, // Opcode: AsmLELOCGR
/* 2571 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 2583
/* 2575 */    MCD::OPC_CheckPredicate, 1, 16, 0, // Skip to: 2595
/* 2579 */    MCD::OPC_Decode, 201, 2, 68, // Opcode: AsmNHLOCGR
/* 2583 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 2595
/* 2587 */    MCD::OPC_CheckPredicate, 1, 4, 0, // Skip to: 2595
/* 2591 */    MCD::OPC_Decode, 237, 2, 68, // Opcode: AsmNOLOCGR
/* 2595 */    MCD::OPC_CheckPredicate, 1, 210, 1, // Skip to: 3065
/* 2599 */    MCD::OPC_Decode, 174, 2, 74, // Opcode: AsmLOCGR
/* 2603 */    MCD::OPC_FilterValue, 228, 1, 14, 0, // Skip to: 2622
/* 2608 */    MCD::OPC_CheckPredicate, 2, 197, 1, // Skip to: 3065
/* 2612 */    MCD::OPC_CheckField, 8, 4, 0, 191, 1, // Skip to: 3065
/* 2618 */    MCD::OPC_Decode, 195, 5, 75, // Opcode: NGRK
/* 2622 */    MCD::OPC_FilterValue, 230, 1, 14, 0, // Skip to: 2641
/* 2627 */    MCD::OPC_CheckPredicate, 2, 178, 1, // Skip to: 3065
/* 2631 */    MCD::OPC_CheckField, 8, 4, 0, 172, 1, // Skip to: 3065
/* 2637 */    MCD::OPC_Decode, 222, 5, 75, // Opcode: OGRK
/* 2641 */    MCD::OPC_FilterValue, 231, 1, 14, 0, // Skip to: 2660
/* 2646 */    MCD::OPC_CheckPredicate, 2, 159, 1, // Skip to: 3065
/* 2650 */    MCD::OPC_CheckField, 8, 4, 0, 153, 1, // Skip to: 3065
/* 2656 */    MCD::OPC_Decode, 230, 6, 75, // Opcode: XGRK
/* 2660 */    MCD::OPC_FilterValue, 232, 1, 13, 0, // Skip to: 2678
/* 2665 */    MCD::OPC_CheckPredicate, 2, 140, 1, // Skip to: 3065
/* 2669 */    MCD::OPC_CheckField, 8, 4, 0, 134, 1, // Skip to: 3065
/* 2675 */    MCD::OPC_Decode, 37, 75, // Opcode: AGRK
/* 2678 */    MCD::OPC_FilterValue, 233, 1, 14, 0, // Skip to: 2697
/* 2683 */    MCD::OPC_CheckPredicate, 2, 122, 1, // Skip to: 3065
/* 2687 */    MCD::OPC_CheckField, 8, 4, 0, 116, 1, // Skip to: 3065
/* 2693 */    MCD::OPC_Decode, 141, 6, 75, // Opcode: SGRK
/* 2697 */    MCD::OPC_FilterValue, 234, 1, 13, 0, // Skip to: 2715
/* 2702 */    MCD::OPC_CheckPredicate, 2, 103, 1, // Skip to: 3065
/* 2706 */    MCD::OPC_CheckField, 8, 4, 0, 97, 1, // Skip to: 3065
/* 2712 */    MCD::OPC_Decode, 58, 75, // Opcode: ALGRK
/* 2715 */    MCD::OPC_FilterValue, 235, 1, 14, 0, // Skip to: 2734
/* 2720 */    MCD::OPC_CheckPredicate, 2, 85, 1, // Skip to: 3065
/* 2724 */    MCD::OPC_CheckField, 8, 4, 0, 79, 1, // Skip to: 3065
/* 2730 */    MCD::OPC_Decode, 155, 6, 75, // Opcode: SLGRK
/* 2734 */    MCD::OPC_FilterValue, 242, 1, 186, 0, // Skip to: 2925
/* 2739 */    MCD::OPC_ExtractField, 8, 4,  // Inst{11-8} ...
/* 2742 */    MCD::OPC_FilterValue, 0, 63, 1, // Skip to: 3065
/* 2746 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 2749 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 2761
/* 2753 */    MCD::OPC_CheckPredicate, 1, 160, 0, // Skip to: 2917
/* 2757 */    MCD::OPC_Decode, 247, 2, 4, // Opcode: AsmOLOCR
/* 2761 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2773
/* 2765 */    MCD::OPC_CheckPredicate, 1, 148, 0, // Skip to: 2917
/* 2769 */    MCD::OPC_Decode, 176, 1, 4, // Opcode: AsmHLOCR
/* 2773 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 2785
/* 2777 */    MCD::OPC_CheckPredicate, 1, 136, 0, // Skip to: 2917
/* 2781 */    MCD::OPC_Decode, 212, 2, 4, // Opcode: AsmNLELOCR
/* 2785 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 2797
/* 2789 */    MCD::OPC_CheckPredicate, 1, 124, 0, // Skip to: 2917
/* 2793 */    MCD::OPC_Decode, 171, 2, 4, // Opcode: AsmLLOCR
/* 2797 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 2809
/* 2801 */    MCD::OPC_CheckPredicate, 1, 112, 0, // Skip to: 2917
/* 2805 */    MCD::OPC_Decode, 194, 2, 4, // Opcode: AsmNHELOCR
/* 2809 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 2821
/* 2813 */    MCD::OPC_CheckPredicate, 1, 100, 0, // Skip to: 2917
/* 2817 */    MCD::OPC_Decode, 163, 2, 4, // Opcode: AsmLHLOCR
/* 2821 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 2833
/* 2825 */    MCD::OPC_CheckPredicate, 1, 88, 0, // Skip to: 2917
/* 2829 */    MCD::OPC_Decode, 184, 2, 4, // Opcode: AsmNELOCR
/* 2833 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 2845
/* 2837 */    MCD::OPC_CheckPredicate, 1, 76, 0, // Skip to: 2917
/* 2841 */    MCD::OPC_Decode, 158, 1, 4, // Opcode: AsmELOCR
/* 2845 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 2857
/* 2849 */    MCD::OPC_CheckPredicate, 1, 64, 0, // Skip to: 2917
/* 2853 */    MCD::OPC_Decode, 221, 2, 4, // Opcode: AsmNLHLOCR
/* 2857 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 2869
/* 2861 */    MCD::OPC_CheckPredicate, 1, 52, 0, // Skip to: 2917
/* 2865 */    MCD::OPC_Decode, 168, 1, 4, // Opcode: AsmHELOCR
/* 2869 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 2881
/* 2873 */    MCD::OPC_CheckPredicate, 1, 40, 0, // Skip to: 2917
/* 2877 */    MCD::OPC_Decode, 229, 2, 4, // Opcode: AsmNLLOCR
/* 2881 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 2893
/* 2885 */    MCD::OPC_CheckPredicate, 1, 28, 0, // Skip to: 2917
/* 2889 */    MCD::OPC_Decode, 154, 2, 4, // Opcode: AsmLELOCR
/* 2893 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 2905
/* 2897 */    MCD::OPC_CheckPredicate, 1, 16, 0, // Skip to: 2917
/* 2901 */    MCD::OPC_Decode, 202, 2, 4, // Opcode: AsmNHLOCR
/* 2905 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 2917
/* 2909 */    MCD::OPC_CheckPredicate, 1, 4, 0, // Skip to: 2917
/* 2913 */    MCD::OPC_Decode, 238, 2, 4, // Opcode: AsmNOLOCR
/* 2917 */    MCD::OPC_CheckPredicate, 1, 144, 0, // Skip to: 3065
/* 2921 */    MCD::OPC_Decode, 175, 2, 76, // Opcode: AsmLOCR
/* 2925 */    MCD::OPC_FilterValue, 244, 1, 14, 0, // Skip to: 2944
/* 2930 */    MCD::OPC_CheckPredicate, 2, 131, 0, // Skip to: 3065
/* 2934 */    MCD::OPC_CheckField, 8, 4, 0, 125, 0, // Skip to: 3065
/* 2940 */    MCD::OPC_Decode, 214, 5, 77, // Opcode: NRK
/* 2944 */    MCD::OPC_FilterValue, 246, 1, 14, 0, // Skip to: 2963
/* 2949 */    MCD::OPC_CheckPredicate, 2, 112, 0, // Skip to: 3065
/* 2953 */    MCD::OPC_CheckField, 8, 4, 0, 106, 0, // Skip to: 3065
/* 2959 */    MCD::OPC_Decode, 241, 5, 77, // Opcode: ORK
/* 2963 */    MCD::OPC_FilterValue, 247, 1, 14, 0, // Skip to: 2982
/* 2968 */    MCD::OPC_CheckPredicate, 2, 93, 0, // Skip to: 3065
/* 2972 */    MCD::OPC_CheckField, 8, 4, 0, 87, 0, // Skip to: 3065
/* 2978 */    MCD::OPC_Decode, 239, 6, 77, // Opcode: XRK
/* 2982 */    MCD::OPC_FilterValue, 248, 1, 13, 0, // Skip to: 3000
/* 2987 */    MCD::OPC_CheckPredicate, 2, 74, 0, // Skip to: 3065
/* 2991 */    MCD::OPC_CheckField, 8, 4, 0, 68, 0, // Skip to: 3065
/* 2997 */    MCD::OPC_Decode, 64, 77, // Opcode: ARK
/* 3000 */    MCD::OPC_FilterValue, 249, 1, 14, 0, // Skip to: 3019
/* 3005 */    MCD::OPC_CheckPredicate, 2, 56, 0, // Skip to: 3065
/* 3009 */    MCD::OPC_CheckField, 8, 4, 0, 50, 0, // Skip to: 3065
/* 3015 */    MCD::OPC_Decode, 171, 6, 77, // Opcode: SRK
/* 3019 */    MCD::OPC_FilterValue, 250, 1, 13, 0, // Skip to: 3037
/* 3024 */    MCD::OPC_CheckPredicate, 2, 37, 0, // Skip to: 3065
/* 3028 */    MCD::OPC_CheckField, 8, 4, 0, 31, 0, // Skip to: 3065
/* 3034 */    MCD::OPC_Decode, 61, 77, // Opcode: ALRK
/* 3037 */    MCD::OPC_FilterValue, 251, 1, 23, 0, // Skip to: 3065
/* 3042 */    MCD::OPC_CheckPredicate, 2, 19, 0, // Skip to: 3065
/* 3046 */    MCD::OPC_CheckField, 8, 4, 0, 13, 0, // Skip to: 3065
/* 3052 */    MCD::OPC_Decode, 160, 6, 77, // Opcode: SLRK
/* 3056 */    MCD::OPC_FilterValue, 186, 1, 4, 0, // Skip to: 3065
/* 3061 */    MCD::OPC_Decode, 211, 3, 78, // Opcode: CS
/* 3065 */    MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTable48[] = {
/* 0 */       MCD::OPC_ExtractField, 40, 8,  // Inst{47-40} ...
/* 3 */       MCD::OPC_FilterValue, 192, 1, 238, 0, // Skip to: 246
/* 8 */       MCD::OPC_ExtractField, 32, 4,  // Inst{35-32} ...
/* 11 */      MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 19
/* 15 */      MCD::OPC_Decode, 156, 4, 79, // Opcode: LARL
/* 19 */      MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 27
/* 23 */      MCD::OPC_Decode, 186, 4, 80, // Opcode: LGFI
/* 27 */      MCD::OPC_FilterValue, 4, 127, 0, // Skip to: 158
/* 31 */      MCD::OPC_ExtractField, 36, 4,  // Inst{39-36} ...
/* 34 */      MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 42
/* 38 */      MCD::OPC_Decode, 243, 2, 81, // Opcode: AsmOJG
/* 42 */      MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 50
/* 46 */      MCD::OPC_Decode, 172, 1, 81, // Opcode: AsmHJG
/* 50 */      MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 58
/* 54 */      MCD::OPC_Decode, 208, 2, 81, // Opcode: AsmNLEJG
/* 58 */      MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 66
/* 62 */      MCD::OPC_Decode, 167, 2, 81, // Opcode: AsmLJG
/* 66 */      MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 74
/* 70 */      MCD::OPC_Decode, 190, 2, 81, // Opcode: AsmNHEJG
/* 74 */      MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 82
/* 78 */      MCD::OPC_Decode, 159, 2, 81, // Opcode: AsmLHJG
/* 82 */      MCD::OPC_FilterValue, 7, 4, 0, // Skip to: 90
/* 86 */      MCD::OPC_Decode, 180, 2, 81, // Opcode: AsmNEJG
/* 90 */      MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 98
/* 94 */      MCD::OPC_Decode, 154, 1, 81, // Opcode: AsmEJG
/* 98 */      MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 106
/* 102 */     MCD::OPC_Decode, 217, 2, 81, // Opcode: AsmNLHJG
/* 106 */     MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 114
/* 110 */     MCD::OPC_Decode, 164, 1, 81, // Opcode: AsmHEJG
/* 114 */     MCD::OPC_FilterValue, 11, 4, 0, // Skip to: 122
/* 118 */     MCD::OPC_Decode, 225, 2, 81, // Opcode: AsmNLJG
/* 122 */     MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 130
/* 126 */     MCD::OPC_Decode, 150, 2, 81, // Opcode: AsmLEJG
/* 130 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 138
/* 134 */     MCD::OPC_Decode, 198, 2, 81, // Opcode: AsmNHJG
/* 138 */     MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 146
/* 142 */     MCD::OPC_Decode, 234, 2, 81, // Opcode: AsmNOJG
/* 146 */     MCD::OPC_FilterValue, 15, 4, 0, // Skip to: 154
/* 150 */     MCD::OPC_Decode, 152, 4, 81, // Opcode: JG
/* 154 */     MCD::OPC_Decode, 143, 1, 82, // Opcode: AsmBRCL
/* 158 */     MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 166
/* 162 */     MCD::OPC_Decode, 255, 2, 79, // Opcode: BRASL
/* 166 */     MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 174
/* 170 */     MCD::OPC_Decode, 233, 6, 83, // Opcode: XIHF
/* 174 */     MCD::OPC_FilterValue, 7, 4, 0, // Skip to: 182
/* 178 */     MCD::OPC_Decode, 235, 6, 84, // Opcode: XILF
/* 182 */     MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 190
/* 186 */     MCD::OPC_Decode, 136, 4, 85, // Opcode: IIHF
/* 190 */     MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 198
/* 194 */     MCD::OPC_Decode, 143, 4, 86, // Opcode: IILF
/* 198 */     MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 206
/* 202 */     MCD::OPC_Decode, 198, 5, 83, // Opcode: NIHF
/* 206 */     MCD::OPC_FilterValue, 11, 4, 0, // Skip to: 214
/* 210 */     MCD::OPC_Decode, 205, 5, 84, // Opcode: NILF
/* 214 */     MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 222
/* 218 */     MCD::OPC_Decode, 225, 5, 83, // Opcode: OIHF
/* 222 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 230
/* 226 */     MCD::OPC_Decode, 232, 5, 84, // Opcode: OILF
/* 230 */     MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 238
/* 234 */     MCD::OPC_Decode, 222, 4, 87, // Opcode: LLIHF
/* 238 */     MCD::OPC_FilterValue, 15, 8, 12, // Skip to: 3322
/* 242 */     MCD::OPC_Decode, 225, 4, 87, // Opcode: LLILF
/* 246 */     MCD::OPC_FilterValue, 194, 1, 95, 0, // Skip to: 346
/* 251 */     MCD::OPC_ExtractField, 32, 4,  // Inst{35-32} ...
/* 254 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 262
/* 258 */     MCD::OPC_Decode, 171, 5, 88, // Opcode: MSGFI
/* 262 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 270
/* 266 */     MCD::OPC_Decode, 168, 5, 89, // Opcode: MSFI
/* 270 */     MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 278
/* 274 */     MCD::OPC_Decode, 152, 6, 90, // Opcode: SLGFI
/* 278 */     MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 286
/* 282 */     MCD::OPC_Decode, 148, 6, 84, // Opcode: SLFI
/* 286 */     MCD::OPC_FilterValue, 8, 3, 0, // Skip to: 293
/* 290 */     MCD::OPC_Decode, 32, 88, // Opcode: AGFI
/* 293 */     MCD::OPC_FilterValue, 9, 3, 0, // Skip to: 300
/* 297 */     MCD::OPC_Decode, 28, 89, // Opcode: AFI
/* 300 */     MCD::OPC_FilterValue, 10, 3, 0, // Skip to: 307
/* 304 */     MCD::OPC_Decode, 54, 90, // Opcode: ALGFI
/* 307 */     MCD::OPC_FilterValue, 11, 3, 0, // Skip to: 314
/* 311 */     MCD::OPC_Decode, 51, 84, // Opcode: ALFI
/* 314 */     MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 322
/* 318 */     MCD::OPC_Decode, 150, 3, 80, // Opcode: CGFI
/* 322 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 330
/* 326 */     MCD::OPC_Decode, 143, 3, 91, // Opcode: CFI
/* 330 */     MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 338
/* 334 */     MCD::OPC_Decode, 180, 3, 87, // Opcode: CLGFI
/* 338 */     MCD::OPC_FilterValue, 15, 164, 11, // Skip to: 3322
/* 342 */     MCD::OPC_Decode, 176, 3, 86, // Opcode: CLFI
/* 346 */     MCD::OPC_FilterValue, 196, 1, 91, 0, // Skip to: 442
/* 351 */     MCD::OPC_ExtractField, 32, 4,  // Inst{35-32} ...
/* 354 */     MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 362
/* 358 */     MCD::OPC_Decode, 220, 4, 92, // Opcode: LLHRL
/* 362 */     MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 370
/* 366 */     MCD::OPC_Decode, 192, 4, 79, // Opcode: LGHRL
/* 370 */     MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 378
/* 374 */     MCD::OPC_Decode, 201, 4, 92, // Opcode: LHRL
/* 378 */     MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 386
/* 382 */     MCD::OPC_Decode, 215, 4, 79, // Opcode: LLGHRL
/* 386 */     MCD::OPC_FilterValue, 7, 4, 0, // Skip to: 394
/* 390 */     MCD::OPC_Decode, 193, 6, 92, // Opcode: STHRL
/* 394 */     MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 402
/* 398 */     MCD::OPC_Decode, 194, 4, 79, // Opcode: LGRL
/* 402 */     MCD::OPC_FilterValue, 11, 4, 0, // Skip to: 410
/* 406 */     MCD::OPC_Decode, 189, 6, 79, // Opcode: STGRL
/* 410 */     MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 418
/* 414 */     MCD::OPC_Decode, 188, 4, 79, // Opcode: LGFRL
/* 418 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 426
/* 422 */     MCD::OPC_Decode, 247, 4, 92, // Opcode: LRL
/* 426 */     MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 434
/* 430 */     MCD::OPC_Decode, 212, 4, 79, // Opcode: LLGFRL
/* 434 */     MCD::OPC_FilterValue, 15, 68, 11, // Skip to: 3322
/* 438 */     MCD::OPC_Decode, 199, 6, 92, // Opcode: STRL
/* 442 */     MCD::OPC_FilterValue, 198, 1, 91, 0, // Skip to: 538
/* 447 */     MCD::OPC_ExtractField, 32, 4,  // Inst{35-32} ...
/* 450 */     MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 458
/* 454 */     MCD::OPC_Decode, 244, 5, 82, // Opcode: PFDRL
/* 458 */     MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 466
/* 462 */     MCD::OPC_Decode, 155, 3, 79, // Opcode: CGHRL
/* 466 */     MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 474
/* 470 */     MCD::OPC_Decode, 166, 3, 92, // Opcode: CHRL
/* 474 */     MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 482
/* 478 */     MCD::OPC_Decode, 183, 3, 79, // Opcode: CLGHRL
/* 482 */     MCD::OPC_FilterValue, 7, 4, 0, // Skip to: 490
/* 486 */     MCD::OPC_Decode, 191, 3, 92, // Opcode: CLHRL
/* 490 */     MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 498
/* 494 */     MCD::OPC_Decode, 160, 3, 79, // Opcode: CGRL
/* 498 */     MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 506
/* 502 */     MCD::OPC_Decode, 188, 3, 79, // Opcode: CLGRL
/* 506 */     MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 514
/* 510 */     MCD::OPC_Decode, 152, 3, 79, // Opcode: CGFRL
/* 514 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 522
/* 518 */     MCD::OPC_Decode, 210, 3, 92, // Opcode: CRL
/* 522 */     MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 530
/* 526 */     MCD::OPC_Decode, 182, 3, 79, // Opcode: CLGFRL
/* 530 */     MCD::OPC_FilterValue, 15, 228, 10, // Skip to: 3322
/* 534 */     MCD::OPC_Decode, 199, 3, 92, // Opcode: CLRL
/* 538 */     MCD::OPC_FilterValue, 204, 1, 38, 0, // Skip to: 581
/* 543 */     MCD::OPC_ExtractField, 32, 4,  // Inst{35-32} ...
/* 546 */     MCD::OPC_FilterValue, 8, 7, 0, // Skip to: 557
/* 550 */     MCD::OPC_CheckPredicate, 3, 208, 10, // Skip to: 3322
/* 554 */     MCD::OPC_Decode, 45, 93, // Opcode: AIH
/* 557 */     MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 569
/* 561 */     MCD::OPC_CheckPredicate, 3, 197, 10, // Skip to: 3322
/* 565 */     MCD::OPC_Decode, 169, 3, 94, // Opcode: CIH
/* 569 */     MCD::OPC_FilterValue, 15, 189, 10, // Skip to: 3322
/* 573 */     MCD::OPC_CheckPredicate, 3, 185, 10, // Skip to: 3322
/* 577 */     MCD::OPC_Decode, 193, 3, 86, // Opcode: CLIH
/* 581 */     MCD::OPC_FilterValue, 210, 1, 4, 0, // Skip to: 590
/* 586 */     MCD::OPC_Decode, 176, 5, 95, // Opcode: MVC
/* 590 */     MCD::OPC_FilterValue, 212, 1, 4, 0, // Skip to: 599
/* 595 */     MCD::OPC_Decode, 190, 5, 95, // Opcode: NC
/* 599 */     MCD::OPC_FilterValue, 213, 1, 4, 0, // Skip to: 608
/* 604 */     MCD::OPC_Decode, 172, 3, 95, // Opcode: CLC
/* 608 */     MCD::OPC_FilterValue, 214, 1, 4, 0, // Skip to: 617
/* 613 */     MCD::OPC_Decode, 217, 5, 95, // Opcode: OC
/* 617 */     MCD::OPC_FilterValue, 215, 1, 4, 0, // Skip to: 626
/* 622 */     MCD::OPC_Decode, 225, 6, 95, // Opcode: XC
/* 626 */     MCD::OPC_FilterValue, 227, 1, 163, 2, // Skip to: 1306
/* 631 */     MCD::OPC_ExtractField, 0, 8,  // Inst{7-0} ...
/* 634 */     MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 642
/* 638 */     MCD::OPC_Decode, 130, 5, 96, // Opcode: LTG
/* 642 */     MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 650
/* 646 */     MCD::OPC_Decode, 181, 4, 96, // Opcode: LG
/* 650 */     MCD::OPC_FilterValue, 8, 3, 0, // Skip to: 657
/* 654 */     MCD::OPC_Decode, 30, 97, // Opcode: AG
/* 657 */     MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 665
/* 661 */     MCD::OPC_Decode, 137, 6, 97, // Opcode: SG
/* 665 */     MCD::OPC_FilterValue, 10, 3, 0, // Skip to: 672
/* 669 */     MCD::OPC_Decode, 52, 97, // Opcode: ALG
/* 672 */     MCD::OPC_FilterValue, 11, 4, 0, // Skip to: 680
/* 676 */     MCD::OPC_Decode, 149, 6, 97, // Opcode: SLG
/* 680 */     MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 688
/* 684 */     MCD::OPC_Decode, 169, 5, 97, // Opcode: MSG
/* 688 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 696
/* 692 */     MCD::OPC_Decode, 246, 3, 98, // Opcode: DSG
/* 696 */     MCD::OPC_FilterValue, 15, 4, 0, // Skip to: 704
/* 700 */     MCD::OPC_Decode, 250, 4, 96, // Opcode: LRVG
/* 704 */     MCD::OPC_FilterValue, 18, 4, 0, // Skip to: 712
/* 708 */     MCD::OPC_Decode, 253, 4, 99, // Opcode: LT
/* 712 */     MCD::OPC_FilterValue, 20, 4, 0, // Skip to: 720
/* 716 */     MCD::OPC_Decode, 185, 4, 96, // Opcode: LGF
/* 720 */     MCD::OPC_FilterValue, 21, 4, 0, // Skip to: 728
/* 724 */     MCD::OPC_Decode, 189, 4, 96, // Opcode: LGH
/* 728 */     MCD::OPC_FilterValue, 22, 4, 0, // Skip to: 736
/* 732 */     MCD::OPC_Decode, 210, 4, 96, // Opcode: LLGF
/* 736 */     MCD::OPC_FilterValue, 24, 3, 0, // Skip to: 743
/* 740 */     MCD::OPC_Decode, 31, 97, // Opcode: AGF
/* 743 */     MCD::OPC_FilterValue, 25, 4, 0, // Skip to: 751
/* 747 */     MCD::OPC_Decode, 138, 6, 97, // Opcode: SGF
/* 751 */     MCD::OPC_FilterValue, 26, 3, 0, // Skip to: 758
/* 755 */     MCD::OPC_Decode, 53, 97, // Opcode: ALGF
/* 758 */     MCD::OPC_FilterValue, 27, 4, 0, // Skip to: 766
/* 762 */     MCD::OPC_Decode, 151, 6, 97, // Opcode: SLGF
/* 766 */     MCD::OPC_FilterValue, 28, 4, 0, // Skip to: 774
/* 770 */     MCD::OPC_Decode, 170, 5, 97, // Opcode: MSGF
/* 774 */     MCD::OPC_FilterValue, 29, 4, 0, // Skip to: 782
/* 778 */     MCD::OPC_Decode, 247, 3, 98, // Opcode: DSGF
/* 782 */     MCD::OPC_FilterValue, 30, 4, 0, // Skip to: 790
/* 786 */     MCD::OPC_Decode, 249, 4, 99, // Opcode: LRV
/* 790 */     MCD::OPC_FilterValue, 32, 4, 0, // Skip to: 798
/* 794 */     MCD::OPC_Decode, 146, 3, 96, // Opcode: CG
/* 798 */     MCD::OPC_FilterValue, 33, 4, 0, // Skip to: 806
/* 802 */     MCD::OPC_Decode, 178, 3, 96, // Opcode: CLG
/* 806 */     MCD::OPC_FilterValue, 36, 4, 0, // Skip to: 814
/* 810 */     MCD::OPC_Decode, 188, 6, 96, // Opcode: STG
/* 814 */     MCD::OPC_FilterValue, 47, 4, 0, // Skip to: 822
/* 818 */     MCD::OPC_Decode, 201, 6, 96, // Opcode: STRVG
/* 822 */     MCD::OPC_FilterValue, 48, 4, 0, // Skip to: 830
/* 826 */     MCD::OPC_Decode, 149, 3, 96, // Opcode: CGF
/* 830 */     MCD::OPC_FilterValue, 49, 4, 0, // Skip to: 838
/* 834 */     MCD::OPC_Decode, 179, 3, 96, // Opcode: CLGF
/* 838 */     MCD::OPC_FilterValue, 50, 4, 0, // Skip to: 846
/* 842 */     MCD::OPC_Decode, 131, 5, 96, // Opcode: LTGF
/* 846 */     MCD::OPC_FilterValue, 52, 4, 0, // Skip to: 854
/* 850 */     MCD::OPC_Decode, 153, 3, 96, // Opcode: CGH
/* 854 */     MCD::OPC_FilterValue, 54, 4, 0, // Skip to: 862
/* 858 */     MCD::OPC_Decode, 243, 5, 100, // Opcode: PFD
/* 862 */     MCD::OPC_FilterValue, 62, 4, 0, // Skip to: 870
/* 866 */     MCD::OPC_Decode, 200, 6, 99, // Opcode: STRV
/* 870 */     MCD::OPC_FilterValue, 80, 4, 0, // Skip to: 878
/* 874 */     MCD::OPC_Decode, 203, 6, 99, // Opcode: STY
/* 878 */     MCD::OPC_FilterValue, 81, 4, 0, // Skip to: 886
/* 882 */     MCD::OPC_Decode, 175, 5, 101, // Opcode: MSY
/* 886 */     MCD::OPC_FilterValue, 84, 4, 0, // Skip to: 894
/* 890 */     MCD::OPC_Decode, 215, 5, 101, // Opcode: NY
/* 894 */     MCD::OPC_FilterValue, 85, 4, 0, // Skip to: 902
/* 898 */     MCD::OPC_Decode, 202, 3, 99, // Opcode: CLY
/* 902 */     MCD::OPC_FilterValue, 86, 4, 0, // Skip to: 910
/* 906 */     MCD::OPC_Decode, 242, 5, 101, // Opcode: OY
/* 910 */     MCD::OPC_FilterValue, 87, 4, 0, // Skip to: 918
/* 914 */     MCD::OPC_Decode, 240, 6, 101, // Opcode: XY
/* 918 */     MCD::OPC_FilterValue, 88, 4, 0, // Skip to: 926
/* 922 */     MCD::OPC_Decode, 143, 5, 99, // Opcode: LY
/* 926 */     MCD::OPC_FilterValue, 89, 4, 0, // Skip to: 934
/* 930 */     MCD::OPC_Decode, 217, 3, 99, // Opcode: CY
/* 934 */     MCD::OPC_FilterValue, 90, 4, 0, // Skip to: 942
/* 938 */     MCD::OPC_Decode, 140, 1, 101, // Opcode: AY
/* 942 */     MCD::OPC_FilterValue, 91, 4, 0, // Skip to: 950
/* 946 */     MCD::OPC_Decode, 205, 6, 101, // Opcode: SY
/* 950 */     MCD::OPC_FilterValue, 94, 3, 0, // Skip to: 957
/* 954 */     MCD::OPC_Decode, 62, 101, // Opcode: ALY
/* 957 */     MCD::OPC_FilterValue, 95, 4, 0, // Skip to: 965
/* 961 */     MCD::OPC_Decode, 161, 6, 101, // Opcode: SLY
/* 965 */     MCD::OPC_FilterValue, 112, 4, 0, // Skip to: 973
/* 969 */     MCD::OPC_Decode, 194, 6, 99, // Opcode: STHY
/* 973 */     MCD::OPC_FilterValue, 113, 4, 0, // Skip to: 981
/* 977 */     MCD::OPC_Decode, 157, 4, 96, // Opcode: LAY
/* 981 */     MCD::OPC_FilterValue, 114, 4, 0, // Skip to: 989
/* 985 */     MCD::OPC_Decode, 182, 6, 99, // Opcode: STCY
/* 989 */     MCD::OPC_FilterValue, 115, 4, 0, // Skip to: 997
/* 993 */     MCD::OPC_Decode, 134, 4, 97, // Opcode: ICY
/* 997 */     MCD::OPC_FilterValue, 118, 4, 0, // Skip to: 1005
/* 1001 */    MCD::OPC_Decode, 158, 4, 99, // Opcode: LB
/* 1005 */    MCD::OPC_FilterValue, 119, 4, 0, // Skip to: 1013
/* 1009 */    MCD::OPC_Decode, 182, 4, 96, // Opcode: LGB
/* 1013 */    MCD::OPC_FilterValue, 120, 4, 0, // Skip to: 1021
/* 1017 */    MCD::OPC_Decode, 202, 4, 99, // Opcode: LHY
/* 1021 */    MCD::OPC_FilterValue, 121, 4, 0, // Skip to: 1029
/* 1025 */    MCD::OPC_Decode, 168, 3, 99, // Opcode: CHY
/* 1029 */    MCD::OPC_FilterValue, 122, 3, 0, // Skip to: 1036
/* 1033 */    MCD::OPC_Decode, 44, 101, // Opcode: AHY
/* 1036 */    MCD::OPC_FilterValue, 123, 4, 0, // Skip to: 1044
/* 1040 */    MCD::OPC_Decode, 143, 6, 101, // Opcode: SHY
/* 1044 */    MCD::OPC_FilterValue, 124, 4, 0, // Skip to: 1052
/* 1048 */    MCD::OPC_Decode, 160, 5, 101, // Opcode: MHY
/* 1052 */    MCD::OPC_FilterValue, 128, 1, 4, 0, // Skip to: 1061
/* 1057 */    MCD::OPC_Decode, 193, 5, 97, // Opcode: NG
/* 1061 */    MCD::OPC_FilterValue, 129, 1, 4, 0, // Skip to: 1070
/* 1066 */    MCD::OPC_Decode, 220, 5, 97, // Opcode: OG
/* 1070 */    MCD::OPC_FilterValue, 130, 1, 4, 0, // Skip to: 1079
/* 1075 */    MCD::OPC_Decode, 228, 6, 97, // Opcode: XG
/* 1079 */    MCD::OPC_FilterValue, 134, 1, 4, 0, // Skip to: 1088
/* 1084 */    MCD::OPC_Decode, 161, 5, 98, // Opcode: MLG
/* 1088 */    MCD::OPC_FilterValue, 135, 1, 4, 0, // Skip to: 1097
/* 1093 */    MCD::OPC_Decode, 243, 3, 98, // Opcode: DLG
/* 1097 */    MCD::OPC_FilterValue, 136, 1, 3, 0, // Skip to: 1105
/* 1102 */    MCD::OPC_Decode, 48, 97, // Opcode: ALCG
/* 1105 */    MCD::OPC_FilterValue, 137, 1, 4, 0, // Skip to: 1114
/* 1110 */    MCD::OPC_Decode, 146, 6, 97, // Opcode: SLBG
/* 1114 */    MCD::OPC_FilterValue, 144, 1, 4, 0, // Skip to: 1123
/* 1119 */    MCD::OPC_Decode, 208, 4, 96, // Opcode: LLGC
/* 1123 */    MCD::OPC_FilterValue, 145, 1, 4, 0, // Skip to: 1132
/* 1128 */    MCD::OPC_Decode, 213, 4, 96, // Opcode: LLGH
/* 1132 */    MCD::OPC_FilterValue, 148, 1, 4, 0, // Skip to: 1141
/* 1137 */    MCD::OPC_Decode, 203, 4, 99, // Opcode: LLC
/* 1141 */    MCD::OPC_FilterValue, 149, 1, 4, 0, // Skip to: 1150
/* 1146 */    MCD::OPC_Decode, 216, 4, 99, // Opcode: LLH
/* 1150 */    MCD::OPC_FilterValue, 151, 1, 4, 0, // Skip to: 1159
/* 1155 */    MCD::OPC_Decode, 242, 3, 98, // Opcode: DL
/* 1159 */    MCD::OPC_FilterValue, 152, 1, 3, 0, // Skip to: 1167
/* 1164 */    MCD::OPC_Decode, 47, 101, // Opcode: ALC
/* 1167 */    MCD::OPC_FilterValue, 153, 1, 4, 0, // Skip to: 1176
/* 1172 */    MCD::OPC_Decode, 145, 6, 101, // Opcode: SLB
/* 1176 */    MCD::OPC_FilterValue, 192, 1, 8, 0, // Skip to: 1189
/* 1181 */    MCD::OPC_CheckPredicate, 3, 89, 8, // Skip to: 3322
/* 1185 */    MCD::OPC_Decode, 159, 4, 102, // Opcode: LBH
/* 1189 */    MCD::OPC_FilterValue, 194, 1, 8, 0, // Skip to: 1202
/* 1194 */    MCD::OPC_CheckPredicate, 3, 76, 8, // Skip to: 3322
/* 1198 */    MCD::OPC_Decode, 204, 4, 99, // Opcode: LLCH
/* 1202 */    MCD::OPC_FilterValue, 195, 1, 8, 0, // Skip to: 1215
/* 1207 */    MCD::OPC_CheckPredicate, 3, 63, 8, // Skip to: 3322
/* 1211 */    MCD::OPC_Decode, 180, 6, 102, // Opcode: STCH
/* 1215 */    MCD::OPC_FilterValue, 196, 1, 8, 0, // Skip to: 1228
/* 1220 */    MCD::OPC_CheckPredicate, 3, 50, 8, // Skip to: 3322
/* 1224 */    MCD::OPC_Decode, 196, 4, 102, // Opcode: LHH
/* 1228 */    MCD::OPC_FilterValue, 198, 1, 8, 0, // Skip to: 1241
/* 1233 */    MCD::OPC_CheckPredicate, 3, 37, 8, // Skip to: 3322
/* 1237 */    MCD::OPC_Decode, 217, 4, 99, // Opcode: LLHH
/* 1241 */    MCD::OPC_FilterValue, 199, 1, 8, 0, // Skip to: 1254
/* 1246 */    MCD::OPC_CheckPredicate, 3, 24, 8, // Skip to: 3322
/* 1250 */    MCD::OPC_Decode, 191, 6, 102, // Opcode: STHH
/* 1254 */    MCD::OPC_FilterValue, 202, 1, 8, 0, // Skip to: 1267
/* 1259 */    MCD::OPC_CheckPredicate, 3, 11, 8, // Skip to: 3322
/* 1263 */    MCD::OPC_Decode, 180, 4, 102, // Opcode: LFH
/* 1267 */    MCD::OPC_FilterValue, 203, 1, 8, 0, // Skip to: 1280
/* 1272 */    MCD::OPC_CheckPredicate, 3, 254, 7, // Skip to: 3322
/* 1276 */    MCD::OPC_Decode, 187, 6, 102, // Opcode: STFH
/* 1280 */    MCD::OPC_FilterValue, 205, 1, 8, 0, // Skip to: 1293
/* 1285 */    MCD::OPC_CheckPredicate, 3, 241, 7, // Skip to: 3322
/* 1289 */    MCD::OPC_Decode, 163, 3, 102, // Opcode: CHF
/* 1293 */    MCD::OPC_FilterValue, 207, 1, 232, 7, // Skip to: 3322
/* 1298 */    MCD::OPC_CheckPredicate, 3, 228, 7, // Skip to: 3322
/* 1302 */    MCD::OPC_Decode, 189, 3, 102, // Opcode: CLHF
/* 1306 */    MCD::OPC_FilterValue, 229, 1, 75, 0, // Skip to: 1386
/* 1311 */    MCD::OPC_ExtractField, 32, 8,  // Inst{39-32} ...
/* 1314 */    MCD::OPC_FilterValue, 68, 4, 0, // Skip to: 1322
/* 1318 */    MCD::OPC_Decode, 180, 5, 103, // Opcode: MVHHI
/* 1322 */    MCD::OPC_FilterValue, 72, 4, 0, // Skip to: 1330
/* 1326 */    MCD::OPC_Decode, 179, 5, 103, // Opcode: MVGHI
/* 1330 */    MCD::OPC_FilterValue, 76, 4, 0, // Skip to: 1338
/* 1334 */    MCD::OPC_Decode, 181, 5, 103, // Opcode: MVHI
/* 1338 */    MCD::OPC_FilterValue, 84, 4, 0, // Skip to: 1346
/* 1342 */    MCD::OPC_Decode, 164, 3, 103, // Opcode: CHHSI
/* 1346 */    MCD::OPC_FilterValue, 85, 4, 0, // Skip to: 1354
/* 1350 */    MCD::OPC_Decode, 190, 3, 104, // Opcode: CLHHSI
/* 1354 */    MCD::OPC_FilterValue, 88, 4, 0, // Skip to: 1362
/* 1358 */    MCD::OPC_Decode, 156, 3, 103, // Opcode: CGHSI
/* 1362 */    MCD::OPC_FilterValue, 89, 4, 0, // Skip to: 1370
/* 1366 */    MCD::OPC_Decode, 184, 3, 104, // Opcode: CLGHSI
/* 1370 */    MCD::OPC_FilterValue, 92, 4, 0, // Skip to: 1378
/* 1374 */    MCD::OPC_Decode, 167, 3, 103, // Opcode: CHSI
/* 1378 */    MCD::OPC_FilterValue, 93, 148, 7, // Skip to: 3322
/* 1382 */    MCD::OPC_Decode, 175, 3, 104, // Opcode: CLFHSI
/* 1386 */    MCD::OPC_FilterValue, 235, 1, 144, 3, // Skip to: 2303
/* 1391 */    MCD::OPC_ExtractField, 0, 8,  // Inst{7-0} ...
/* 1394 */    MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 1402
/* 1398 */    MCD::OPC_Decode, 228, 4, 105, // Opcode: LMG
/* 1402 */    MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 1410
/* 1406 */    MCD::OPC_Decode, 169, 6, 106, // Opcode: SRAG
/* 1410 */    MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 1418
/* 1414 */    MCD::OPC_Decode, 173, 6, 106, // Opcode: SRLG
/* 1418 */    MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 1426
/* 1422 */    MCD::OPC_Decode, 157, 6, 106, // Opcode: SLLG
/* 1426 */    MCD::OPC_FilterValue, 20, 4, 0, // Skip to: 1434
/* 1430 */    MCD::OPC_Decode, 213, 3, 107, // Opcode: CSY
/* 1434 */    MCD::OPC_FilterValue, 28, 4, 0, // Skip to: 1442
/* 1438 */    MCD::OPC_Decode, 255, 5, 106, // Opcode: RLLG
/* 1442 */    MCD::OPC_FilterValue, 29, 4, 0, // Skip to: 1450
/* 1446 */    MCD::OPC_Decode, 254, 5, 108, // Opcode: RLL
/* 1450 */    MCD::OPC_FilterValue, 36, 4, 0, // Skip to: 1458
/* 1454 */    MCD::OPC_Decode, 195, 6, 105, // Opcode: STMG
/* 1458 */    MCD::OPC_FilterValue, 48, 4, 0, // Skip to: 1466
/* 1462 */    MCD::OPC_Decode, 212, 3, 109, // Opcode: CSG
/* 1466 */    MCD::OPC_FilterValue, 81, 4, 0, // Skip to: 1474
/* 1470 */    MCD::OPC_Decode, 223, 6, 110, // Opcode: TMY
/* 1474 */    MCD::OPC_FilterValue, 82, 4, 0, // Skip to: 1482
/* 1478 */    MCD::OPC_Decode, 183, 5, 110, // Opcode: MVIY
/* 1482 */    MCD::OPC_FilterValue, 84, 4, 0, // Skip to: 1490
/* 1486 */    MCD::OPC_Decode, 212, 5, 110, // Opcode: NIY
/* 1490 */    MCD::OPC_FilterValue, 85, 4, 0, // Skip to: 1498
/* 1494 */    MCD::OPC_Decode, 195, 3, 110, // Opcode: CLIY
/* 1498 */    MCD::OPC_FilterValue, 86, 4, 0, // Skip to: 1506
/* 1502 */    MCD::OPC_Decode, 239, 5, 110, // Opcode: OIY
/* 1506 */    MCD::OPC_FilterValue, 87, 4, 0, // Skip to: 1514
/* 1510 */    MCD::OPC_Decode, 237, 6, 110, // Opcode: XIY
/* 1514 */    MCD::OPC_FilterValue, 106, 3, 0, // Skip to: 1521
/* 1518 */    MCD::OPC_Decode, 65, 111, // Opcode: ASI
/* 1521 */    MCD::OPC_FilterValue, 122, 3, 0, // Skip to: 1528
/* 1525 */    MCD::OPC_Decode, 38, 111, // Opcode: AGSI
/* 1528 */    MCD::OPC_FilterValue, 220, 1, 8, 0, // Skip to: 1541
/* 1533 */    MCD::OPC_CheckPredicate, 2, 249, 6, // Skip to: 3322
/* 1537 */    MCD::OPC_Decode, 170, 6, 108, // Opcode: SRAK
/* 1541 */    MCD::OPC_FilterValue, 222, 1, 8, 0, // Skip to: 1554
/* 1546 */    MCD::OPC_CheckPredicate, 2, 236, 6, // Skip to: 3322
/* 1550 */    MCD::OPC_Decode, 174, 6, 108, // Opcode: SRLK
/* 1554 */    MCD::OPC_FilterValue, 223, 1, 8, 0, // Skip to: 1567
/* 1559 */    MCD::OPC_CheckPredicate, 2, 223, 6, // Skip to: 3322
/* 1563 */    MCD::OPC_Decode, 158, 6, 108, // Opcode: SLLK
/* 1567 */    MCD::OPC_FilterValue, 226, 1, 179, 0, // Skip to: 1751
/* 1572 */    MCD::OPC_ExtractField, 32, 4,  // Inst{35-32} ...
/* 1575 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1587
/* 1579 */    MCD::OPC_CheckPredicate, 1, 160, 0, // Skip to: 1743
/* 1583 */    MCD::OPC_Decode, 245, 2, 112, // Opcode: AsmOLOCG
/* 1587 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1599
/* 1591 */    MCD::OPC_CheckPredicate, 1, 148, 0, // Skip to: 1743
/* 1595 */    MCD::OPC_Decode, 174, 1, 112, // Opcode: AsmHLOCG
/* 1599 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 1611
/* 1603 */    MCD::OPC_CheckPredicate, 1, 136, 0, // Skip to: 1743
/* 1607 */    MCD::OPC_Decode, 210, 2, 112, // Opcode: AsmNLELOCG
/* 1611 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 1623
/* 1615 */    MCD::OPC_CheckPredicate, 1, 124, 0, // Skip to: 1743
/* 1619 */    MCD::OPC_Decode, 169, 2, 112, // Opcode: AsmLLOCG
/* 1623 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 1635
/* 1627 */    MCD::OPC_CheckPredicate, 1, 112, 0, // Skip to: 1743
/* 1631 */    MCD::OPC_Decode, 192, 2, 112, // Opcode: AsmNHELOCG
/* 1635 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 1647
/* 1639 */    MCD::OPC_CheckPredicate, 1, 100, 0, // Skip to: 1743
/* 1643 */    MCD::OPC_Decode, 161, 2, 112, // Opcode: AsmLHLOCG
/* 1647 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 1659
/* 1651 */    MCD::OPC_CheckPredicate, 1, 88, 0, // Skip to: 1743
/* 1655 */    MCD::OPC_Decode, 182, 2, 112, // Opcode: AsmNELOCG
/* 1659 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 1671
/* 1663 */    MCD::OPC_CheckPredicate, 1, 76, 0, // Skip to: 1743
/* 1667 */    MCD::OPC_Decode, 156, 1, 112, // Opcode: AsmELOCG
/* 1671 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 1683
/* 1675 */    MCD::OPC_CheckPredicate, 1, 64, 0, // Skip to: 1743
/* 1679 */    MCD::OPC_Decode, 219, 2, 112, // Opcode: AsmNLHLOCG
/* 1683 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 1695
/* 1687 */    MCD::OPC_CheckPredicate, 1, 52, 0, // Skip to: 1743
/* 1691 */    MCD::OPC_Decode, 166, 1, 112, // Opcode: AsmHELOCG
/* 1695 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 1707
/* 1699 */    MCD::OPC_CheckPredicate, 1, 40, 0, // Skip to: 1743
/* 1703 */    MCD::OPC_Decode, 227, 2, 112, // Opcode: AsmNLLOCG
/* 1707 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 1719
/* 1711 */    MCD::OPC_CheckPredicate, 1, 28, 0, // Skip to: 1743
/* 1715 */    MCD::OPC_Decode, 152, 2, 112, // Opcode: AsmLELOCG
/* 1719 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 1731
/* 1723 */    MCD::OPC_CheckPredicate, 1, 16, 0, // Skip to: 1743
/* 1727 */    MCD::OPC_Decode, 200, 2, 112, // Opcode: AsmNHLOCG
/* 1731 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 1743
/* 1735 */    MCD::OPC_CheckPredicate, 1, 4, 0, // Skip to: 1743
/* 1739 */    MCD::OPC_Decode, 236, 2, 112, // Opcode: AsmNOLOCG
/* 1743 */    MCD::OPC_CheckPredicate, 1, 39, 6, // Skip to: 3322
/* 1747 */    MCD::OPC_Decode, 173, 2, 113, // Opcode: AsmLOCG
/* 1751 */    MCD::OPC_FilterValue, 227, 1, 179, 0, // Skip to: 1935
/* 1756 */    MCD::OPC_ExtractField, 32, 4,  // Inst{35-32} ...
/* 1759 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1771
/* 1763 */    MCD::OPC_CheckPredicate, 1, 160, 0, // Skip to: 1927
/* 1767 */    MCD::OPC_Decode, 249, 2, 114, // Opcode: AsmOSTOCG
/* 1771 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1783
/* 1775 */    MCD::OPC_CheckPredicate, 1, 148, 0, // Skip to: 1927
/* 1779 */    MCD::OPC_Decode, 178, 1, 114, // Opcode: AsmHSTOCG
/* 1783 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 1795
/* 1787 */    MCD::OPC_CheckPredicate, 1, 136, 0, // Skip to: 1927
/* 1791 */    MCD::OPC_Decode, 214, 2, 114, // Opcode: AsmNLESTOCG
/* 1795 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 1807
/* 1799 */    MCD::OPC_CheckPredicate, 1, 124, 0, // Skip to: 1927
/* 1803 */    MCD::OPC_Decode, 177, 2, 114, // Opcode: AsmLSTOCG
/* 1807 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 1819
/* 1811 */    MCD::OPC_CheckPredicate, 1, 112, 0, // Skip to: 1927
/* 1815 */    MCD::OPC_Decode, 196, 2, 114, // Opcode: AsmNHESTOCG
/* 1819 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 1831
/* 1823 */    MCD::OPC_CheckPredicate, 1, 100, 0, // Skip to: 1927
/* 1827 */    MCD::OPC_Decode, 165, 2, 114, // Opcode: AsmLHSTOCG
/* 1831 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 1843
/* 1835 */    MCD::OPC_CheckPredicate, 1, 88, 0, // Skip to: 1927
/* 1839 */    MCD::OPC_Decode, 186, 2, 114, // Opcode: AsmNESTOCG
/* 1843 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 1855
/* 1847 */    MCD::OPC_CheckPredicate, 1, 76, 0, // Skip to: 1927
/* 1851 */    MCD::OPC_Decode, 160, 1, 114, // Opcode: AsmESTOCG
/* 1855 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 1867
/* 1859 */    MCD::OPC_CheckPredicate, 1, 64, 0, // Skip to: 1927
/* 1863 */    MCD::OPC_Decode, 223, 2, 114, // Opcode: AsmNLHSTOCG
/* 1867 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 1879
/* 1871 */    MCD::OPC_CheckPredicate, 1, 52, 0, // Skip to: 1927
/* 1875 */    MCD::OPC_Decode, 170, 1, 114, // Opcode: AsmHESTOCG
/* 1879 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 1891
/* 1883 */    MCD::OPC_CheckPredicate, 1, 40, 0, // Skip to: 1927
/* 1887 */    MCD::OPC_Decode, 231, 2, 114, // Opcode: AsmNLSTOCG
/* 1891 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 1903
/* 1895 */    MCD::OPC_CheckPredicate, 1, 28, 0, // Skip to: 1927
/* 1899 */    MCD::OPC_Decode, 156, 2, 114, // Opcode: AsmLESTOCG
/* 1903 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 1915
/* 1907 */    MCD::OPC_CheckPredicate, 1, 16, 0, // Skip to: 1927
/* 1911 */    MCD::OPC_Decode, 204, 2, 114, // Opcode: AsmNHSTOCG
/* 1915 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 1927
/* 1919 */    MCD::OPC_CheckPredicate, 1, 4, 0, // Skip to: 1927
/* 1923 */    MCD::OPC_Decode, 240, 2, 114, // Opcode: AsmNOSTOCG
/* 1927 */    MCD::OPC_CheckPredicate, 1, 111, 5, // Skip to: 3322
/* 1931 */    MCD::OPC_Decode, 251, 2, 115, // Opcode: AsmSTOCG
/* 1935 */    MCD::OPC_FilterValue, 242, 1, 179, 0, // Skip to: 2119
/* 1940 */    MCD::OPC_ExtractField, 32, 4,  // Inst{35-32} ...
/* 1943 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1955
/* 1947 */    MCD::OPC_CheckPredicate, 1, 160, 0, // Skip to: 2111
/* 1951 */    MCD::OPC_Decode, 244, 2, 116, // Opcode: AsmOLOC
/* 1955 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1967
/* 1959 */    MCD::OPC_CheckPredicate, 1, 148, 0, // Skip to: 2111
/* 1963 */    MCD::OPC_Decode, 173, 1, 116, // Opcode: AsmHLOC
/* 1967 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 1979
/* 1971 */    MCD::OPC_CheckPredicate, 1, 136, 0, // Skip to: 2111
/* 1975 */    MCD::OPC_Decode, 209, 2, 116, // Opcode: AsmNLELOC
/* 1979 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 1991
/* 1983 */    MCD::OPC_CheckPredicate, 1, 124, 0, // Skip to: 2111
/* 1987 */    MCD::OPC_Decode, 168, 2, 116, // Opcode: AsmLLOC
/* 1991 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 2003
/* 1995 */    MCD::OPC_CheckPredicate, 1, 112, 0, // Skip to: 2111
/* 1999 */    MCD::OPC_Decode, 191, 2, 116, // Opcode: AsmNHELOC
/* 2003 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 2015
/* 2007 */    MCD::OPC_CheckPredicate, 1, 100, 0, // Skip to: 2111
/* 2011 */    MCD::OPC_Decode, 160, 2, 116, // Opcode: AsmLHLOC
/* 2015 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 2027
/* 2019 */    MCD::OPC_CheckPredicate, 1, 88, 0, // Skip to: 2111
/* 2023 */    MCD::OPC_Decode, 181, 2, 116, // Opcode: AsmNELOC
/* 2027 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 2039
/* 2031 */    MCD::OPC_CheckPredicate, 1, 76, 0, // Skip to: 2111
/* 2035 */    MCD::OPC_Decode, 155, 1, 116, // Opcode: AsmELOC
/* 2039 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 2051
/* 2043 */    MCD::OPC_CheckPredicate, 1, 64, 0, // Skip to: 2111
/* 2047 */    MCD::OPC_Decode, 218, 2, 116, // Opcode: AsmNLHLOC
/* 2051 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 2063
/* 2055 */    MCD::OPC_CheckPredicate, 1, 52, 0, // Skip to: 2111
/* 2059 */    MCD::OPC_Decode, 165, 1, 116, // Opcode: AsmHELOC
/* 2063 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 2075
/* 2067 */    MCD::OPC_CheckPredicate, 1, 40, 0, // Skip to: 2111
/* 2071 */    MCD::OPC_Decode, 226, 2, 116, // Opcode: AsmNLLOC
/* 2075 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 2087
/* 2079 */    MCD::OPC_CheckPredicate, 1, 28, 0, // Skip to: 2111
/* 2083 */    MCD::OPC_Decode, 151, 2, 116, // Opcode: AsmLELOC
/* 2087 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 2099
/* 2091 */    MCD::OPC_CheckPredicate, 1, 16, 0, // Skip to: 2111
/* 2095 */    MCD::OPC_Decode, 199, 2, 116, // Opcode: AsmNHLOC
/* 2099 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 2111
/* 2103 */    MCD::OPC_CheckPredicate, 1, 4, 0, // Skip to: 2111
/* 2107 */    MCD::OPC_Decode, 235, 2, 116, // Opcode: AsmNOLOC
/* 2111 */    MCD::OPC_CheckPredicate, 1, 183, 4, // Skip to: 3322
/* 2115 */    MCD::OPC_Decode, 172, 2, 117, // Opcode: AsmLOC
/* 2119 */    MCD::OPC_FilterValue, 243, 1, 174, 4, // Skip to: 3322
/* 2124 */    MCD::OPC_ExtractField, 32, 4,  // Inst{35-32} ...
/* 2127 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 2139
/* 2131 */    MCD::OPC_CheckPredicate, 1, 160, 0, // Skip to: 2295
/* 2135 */    MCD::OPC_Decode, 248, 2, 118, // Opcode: AsmOSTOC
/* 2139 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2151
/* 2143 */    MCD::OPC_CheckPredicate, 1, 148, 0, // Skip to: 2295
/* 2147 */    MCD::OPC_Decode, 177, 1, 118, // Opcode: AsmHSTOC
/* 2151 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 2163
/* 2155 */    MCD::OPC_CheckPredicate, 1, 136, 0, // Skip to: 2295
/* 2159 */    MCD::OPC_Decode, 213, 2, 118, // Opcode: AsmNLESTOC
/* 2163 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 2175
/* 2167 */    MCD::OPC_CheckPredicate, 1, 124, 0, // Skip to: 2295
/* 2171 */    MCD::OPC_Decode, 176, 2, 118, // Opcode: AsmLSTOC
/* 2175 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 2187
/* 2179 */    MCD::OPC_CheckPredicate, 1, 112, 0, // Skip to: 2295
/* 2183 */    MCD::OPC_Decode, 195, 2, 118, // Opcode: AsmNHESTOC
/* 2187 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 2199
/* 2191 */    MCD::OPC_CheckPredicate, 1, 100, 0, // Skip to: 2295
/* 2195 */    MCD::OPC_Decode, 164, 2, 118, // Opcode: AsmLHSTOC
/* 2199 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 2211
/* 2203 */    MCD::OPC_CheckPredicate, 1, 88, 0, // Skip to: 2295
/* 2207 */    MCD::OPC_Decode, 185, 2, 118, // Opcode: AsmNESTOC
/* 2211 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 2223
/* 2215 */    MCD::OPC_CheckPredicate, 1, 76, 0, // Skip to: 2295
/* 2219 */    MCD::OPC_Decode, 159, 1, 118, // Opcode: AsmESTOC
/* 2223 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 2235
/* 2227 */    MCD::OPC_CheckPredicate, 1, 64, 0, // Skip to: 2295
/* 2231 */    MCD::OPC_Decode, 222, 2, 118, // Opcode: AsmNLHSTOC
/* 2235 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 2247
/* 2239 */    MCD::OPC_CheckPredicate, 1, 52, 0, // Skip to: 2295
/* 2243 */    MCD::OPC_Decode, 169, 1, 118, // Opcode: AsmHESTOC
/* 2247 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 2259
/* 2251 */    MCD::OPC_CheckPredicate, 1, 40, 0, // Skip to: 2295
/* 2255 */    MCD::OPC_Decode, 230, 2, 118, // Opcode: AsmNLSTOC
/* 2259 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 2271
/* 2263 */    MCD::OPC_CheckPredicate, 1, 28, 0, // Skip to: 2295
/* 2267 */    MCD::OPC_Decode, 155, 2, 118, // Opcode: AsmLESTOC
/* 2271 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 2283
/* 2275 */    MCD::OPC_CheckPredicate, 1, 16, 0, // Skip to: 2295
/* 2279 */    MCD::OPC_Decode, 203, 2, 118, // Opcode: AsmNHSTOC
/* 2283 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 2295
/* 2287 */    MCD::OPC_CheckPredicate, 1, 4, 0, // Skip to: 2295
/* 2291 */    MCD::OPC_Decode, 239, 2, 118, // Opcode: AsmNOSTOC
/* 2295 */    MCD::OPC_CheckPredicate, 1, 255, 3, // Skip to: 3322
/* 2299 */    MCD::OPC_Decode, 250, 2, 119, // Opcode: AsmSTOC
/* 2303 */    MCD::OPC_FilterValue, 236, 1, 145, 2, // Skip to: 2965
/* 2308 */    MCD::OPC_ExtractField, 0, 8,  // Inst{7-0} ...
/* 2311 */    MCD::OPC_FilterValue, 81, 8, 0, // Skip to: 2323
/* 2315 */    MCD::OPC_CheckPredicate, 3, 235, 3, // Skip to: 3322
/* 2319 */    MCD::OPC_Decode, 250, 5, 120, // Opcode: RISBLG
/* 2323 */    MCD::OPC_FilterValue, 84, 4, 0, // Skip to: 2331
/* 2327 */    MCD::OPC_Decode, 128, 6, 121, // Opcode: RNSBG
/* 2331 */    MCD::OPC_FilterValue, 85, 4, 0, // Skip to: 2339
/* 2335 */    MCD::OPC_Decode, 245, 5, 121, // Opcode: RISBG
/* 2339 */    MCD::OPC_FilterValue, 86, 4, 0, // Skip to: 2347
/* 2343 */    MCD::OPC_Decode, 129, 6, 121, // Opcode: ROSBG
/* 2347 */    MCD::OPC_FilterValue, 87, 4, 0, // Skip to: 2355
/* 2351 */    MCD::OPC_Decode, 130, 6, 121, // Opcode: RXSBG
/* 2355 */    MCD::OPC_FilterValue, 93, 8, 0, // Skip to: 2367
/* 2359 */    MCD::OPC_CheckPredicate, 3, 191, 3, // Skip to: 3322
/* 2363 */    MCD::OPC_Decode, 247, 5, 122, // Opcode: RISBHG
/* 2367 */    MCD::OPC_FilterValue, 100, 62, 0, // Skip to: 2433
/* 2371 */    MCD::OPC_ExtractField, 8, 4,  // Inst{11-8} ...
/* 2374 */    MCD::OPC_FilterValue, 0, 176, 3, // Skip to: 3322
/* 2378 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 2381 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 2389
/* 2385 */    MCD::OPC_Decode, 204, 1, 123, // Opcode: AsmJHCGR
/* 2389 */    MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 2397
/* 2393 */    MCD::OPC_Decode, 236, 1, 123, // Opcode: AsmJLCGR
/* 2397 */    MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 2405
/* 2401 */    MCD::OPC_Decode, 140, 2, 123, // Opcode: AsmJLHCGR
/* 2405 */    MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 2413
/* 2409 */    MCD::OPC_Decode, 188, 1, 123, // Opcode: AsmJECGR
/* 2413 */    MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 2421
/* 2417 */    MCD::OPC_Decode, 220, 1, 123, // Opcode: AsmJHECGR
/* 2421 */    MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 2429
/* 2425 */    MCD::OPC_Decode, 252, 1, 123, // Opcode: AsmJLECGR
/* 2429 */    MCD::OPC_Decode, 145, 1, 124, // Opcode: AsmCGRJ
/* 2433 */    MCD::OPC_FilterValue, 101, 62, 0, // Skip to: 2499
/* 2437 */    MCD::OPC_ExtractField, 8, 4,  // Inst{11-8} ...
/* 2440 */    MCD::OPC_FilterValue, 0, 110, 3, // Skip to: 3322
/* 2444 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 2447 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 2455
/* 2451 */    MCD::OPC_Decode, 207, 1, 123, // Opcode: AsmJHCLGR
/* 2455 */    MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 2463
/* 2459 */    MCD::OPC_Decode, 239, 1, 123, // Opcode: AsmJLCLGR
/* 2463 */    MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 2471
/* 2467 */    MCD::OPC_Decode, 143, 2, 123, // Opcode: AsmJLHCLGR
/* 2471 */    MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 2479
/* 2475 */    MCD::OPC_Decode, 191, 1, 123, // Opcode: AsmJECLGR
/* 2479 */    MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 2487
/* 2483 */    MCD::OPC_Decode, 223, 1, 123, // Opcode: AsmJHECLGR
/* 2487 */    MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 2495
/* 2491 */    MCD::OPC_Decode, 255, 1, 123, // Opcode: AsmJLECLGR
/* 2495 */    MCD::OPC_Decode, 148, 1, 124, // Opcode: AsmCLGRJ
/* 2499 */    MCD::OPC_FilterValue, 118, 62, 0, // Skip to: 2565
/* 2503 */    MCD::OPC_ExtractField, 8, 4,  // Inst{11-8} ...
/* 2506 */    MCD::OPC_FilterValue, 0, 44, 3, // Skip to: 3322
/* 2510 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 2513 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 2521
/* 2517 */    MCD::OPC_Decode, 210, 1, 125, // Opcode: AsmJHCR
/* 2521 */    MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 2529
/* 2525 */    MCD::OPC_Decode, 242, 1, 125, // Opcode: AsmJLCR
/* 2529 */    MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 2537
/* 2533 */    MCD::OPC_Decode, 146, 2, 125, // Opcode: AsmJLHCR
/* 2537 */    MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 2545
/* 2541 */    MCD::OPC_Decode, 194, 1, 125, // Opcode: AsmJECR
/* 2545 */    MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 2553
/* 2549 */    MCD::OPC_Decode, 226, 1, 125, // Opcode: AsmJHECR
/* 2553 */    MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 2561
/* 2557 */    MCD::OPC_Decode, 130, 2, 125, // Opcode: AsmJLECR
/* 2561 */    MCD::OPC_Decode, 151, 1, 126, // Opcode: AsmCRJ
/* 2565 */    MCD::OPC_FilterValue, 119, 62, 0, // Skip to: 2631
/* 2569 */    MCD::OPC_ExtractField, 8, 4,  // Inst{11-8} ...
/* 2572 */    MCD::OPC_FilterValue, 0, 234, 2, // Skip to: 3322
/* 2576 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 2579 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 2587
/* 2583 */    MCD::OPC_Decode, 209, 1, 125, // Opcode: AsmJHCLR
/* 2587 */    MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 2595
/* 2591 */    MCD::OPC_Decode, 241, 1, 125, // Opcode: AsmJLCLR
/* 2595 */    MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 2603
/* 2599 */    MCD::OPC_Decode, 145, 2, 125, // Opcode: AsmJLHCLR
/* 2603 */    MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 2611
/* 2607 */    MCD::OPC_Decode, 193, 1, 125, // Opcode: AsmJECLR
/* 2611 */    MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 2619
/* 2615 */    MCD::OPC_Decode, 225, 1, 125, // Opcode: AsmJHECLR
/* 2619 */    MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 2627
/* 2623 */    MCD::OPC_Decode, 129, 2, 125, // Opcode: AsmJLECLR
/* 2627 */    MCD::OPC_Decode, 150, 1, 126, // Opcode: AsmCLRJ
/* 2631 */    MCD::OPC_FilterValue, 124, 56, 0, // Skip to: 2691
/* 2635 */    MCD::OPC_ExtractField, 32, 4,  // Inst{35-32} ...
/* 2638 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 2646
/* 2642 */    MCD::OPC_Decode, 203, 1, 127, // Opcode: AsmJHCGI
/* 2646 */    MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 2654
/* 2650 */    MCD::OPC_Decode, 235, 1, 127, // Opcode: AsmJLCGI
/* 2654 */    MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 2662
/* 2658 */    MCD::OPC_Decode, 139, 2, 127, // Opcode: AsmJLHCGI
/* 2662 */    MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 2670
/* 2666 */    MCD::OPC_Decode, 187, 1, 127, // Opcode: AsmJECGI
/* 2670 */    MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 2678
/* 2674 */    MCD::OPC_Decode, 219, 1, 127, // Opcode: AsmJHECGI
/* 2678 */    MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 2686
/* 2682 */    MCD::OPC_Decode, 251, 1, 127, // Opcode: AsmJLECGI
/* 2686 */    MCD::OPC_Decode, 144, 1, 128, 1, // Opcode: AsmCGIJ
/* 2691 */    MCD::OPC_FilterValue, 125, 62, 0, // Skip to: 2757
/* 2695 */    MCD::OPC_ExtractField, 32, 4,  // Inst{35-32} ...
/* 2698 */    MCD::OPC_FilterValue, 2, 5, 0, // Skip to: 2707
/* 2702 */    MCD::OPC_Decode, 206, 1, 129, 1, // Opcode: AsmJHCLGI
/* 2707 */    MCD::OPC_FilterValue, 4, 5, 0, // Skip to: 2716
/* 2711 */    MCD::OPC_Decode, 238, 1, 129, 1, // Opcode: AsmJLCLGI
/* 2716 */    MCD::OPC_FilterValue, 6, 5, 0, // Skip to: 2725
/* 2720 */    MCD::OPC_Decode, 142, 2, 129, 1, // Opcode: AsmJLHCLGI
/* 2725 */    MCD::OPC_FilterValue, 8, 5, 0, // Skip to: 2734
/* 2729 */    MCD::OPC_Decode, 190, 1, 129, 1, // Opcode: AsmJECLGI
/* 2734 */    MCD::OPC_FilterValue, 10, 5, 0, // Skip to: 2743
/* 2738 */    MCD::OPC_Decode, 222, 1, 129, 1, // Opcode: AsmJHECLGI
/* 2743 */    MCD::OPC_FilterValue, 12, 5, 0, // Skip to: 2752
/* 2747 */    MCD::OPC_Decode, 254, 1, 129, 1, // Opcode: AsmJLECLGI
/* 2752 */    MCD::OPC_Decode, 147, 1, 130, 1, // Opcode: AsmCLGIJ
/* 2757 */    MCD::OPC_FilterValue, 126, 62, 0, // Skip to: 2823
/* 2761 */    MCD::OPC_ExtractField, 32, 4,  // Inst{35-32} ...
/* 2764 */    MCD::OPC_FilterValue, 2, 5, 0, // Skip to: 2773
/* 2768 */    MCD::OPC_Decode, 205, 1, 131, 1, // Opcode: AsmJHCI
/* 2773 */    MCD::OPC_FilterValue, 4, 5, 0, // Skip to: 2782
/* 2777 */    MCD::OPC_Decode, 237, 1, 131, 1, // Opcode: AsmJLCI
/* 2782 */    MCD::OPC_FilterValue, 6, 5, 0, // Skip to: 2791
/* 2786 */    MCD::OPC_Decode, 141, 2, 131, 1, // Opcode: AsmJLHCI
/* 2791 */    MCD::OPC_FilterValue, 8, 5, 0, // Skip to: 2800
/* 2795 */    MCD::OPC_Decode, 189, 1, 131, 1, // Opcode: AsmJECI
/* 2800 */    MCD::OPC_FilterValue, 10, 5, 0, // Skip to: 2809
/* 2804 */    MCD::OPC_Decode, 221, 1, 131, 1, // Opcode: AsmJHECI
/* 2809 */    MCD::OPC_FilterValue, 12, 5, 0, // Skip to: 2818
/* 2813 */    MCD::OPC_Decode, 253, 1, 131, 1, // Opcode: AsmJLECI
/* 2818 */    MCD::OPC_Decode, 146, 1, 132, 1, // Opcode: AsmCIJ
/* 2823 */    MCD::OPC_FilterValue, 127, 62, 0, // Skip to: 2889
/* 2827 */    MCD::OPC_ExtractField, 32, 4,  // Inst{35-32} ...
/* 2830 */    MCD::OPC_FilterValue, 2, 5, 0, // Skip to: 2839
/* 2834 */    MCD::OPC_Decode, 208, 1, 133, 1, // Opcode: AsmJHCLI
/* 2839 */    MCD::OPC_FilterValue, 4, 5, 0, // Skip to: 2848
/* 2843 */    MCD::OPC_Decode, 240, 1, 133, 1, // Opcode: AsmJLCLI
/* 2848 */    MCD::OPC_FilterValue, 6, 5, 0, // Skip to: 2857
/* 2852 */    MCD::OPC_Decode, 144, 2, 133, 1, // Opcode: AsmJLHCLI
/* 2857 */    MCD::OPC_FilterValue, 8, 5, 0, // Skip to: 2866
/* 2861 */    MCD::OPC_Decode, 192, 1, 133, 1, // Opcode: AsmJECLI
/* 2866 */    MCD::OPC_FilterValue, 10, 5, 0, // Skip to: 2875
/* 2870 */    MCD::OPC_Decode, 224, 1, 133, 1, // Opcode: AsmJHECLI
/* 2875 */    MCD::OPC_FilterValue, 12, 5, 0, // Skip to: 2884
/* 2879 */    MCD::OPC_Decode, 128, 2, 133, 1, // Opcode: AsmJLECLI
/* 2884 */    MCD::OPC_Decode, 149, 1, 134, 1, // Opcode: AsmCLIJ
/* 2889 */    MCD::OPC_FilterValue, 216, 1, 14, 0, // Skip to: 2908
/* 2894 */    MCD::OPC_CheckPredicate, 2, 168, 1, // Skip to: 3322
/* 2898 */    MCD::OPC_CheckField, 8, 8, 0, 162, 1, // Skip to: 3322
/* 2904 */    MCD::OPC_Decode, 41, 135, 1, // Opcode: AHIK
/* 2908 */    MCD::OPC_FilterValue, 217, 1, 14, 0, // Skip to: 2927
/* 2913 */    MCD::OPC_CheckPredicate, 2, 149, 1, // Skip to: 3322
/* 2917 */    MCD::OPC_CheckField, 8, 8, 0, 143, 1, // Skip to: 3322
/* 2923 */    MCD::OPC_Decode, 35, 136, 1, // Opcode: AGHIK
/* 2927 */    MCD::OPC_FilterValue, 218, 1, 14, 0, // Skip to: 2946
/* 2932 */    MCD::OPC_CheckPredicate, 2, 130, 1, // Skip to: 3322
/* 2936 */    MCD::OPC_CheckField, 8, 8, 0, 124, 1, // Skip to: 3322
/* 2942 */    MCD::OPC_Decode, 59, 135, 1, // Opcode: ALHSIK
/* 2946 */    MCD::OPC_FilterValue, 219, 1, 115, 1, // Skip to: 3322
/* 2951 */    MCD::OPC_CheckPredicate, 2, 111, 1, // Skip to: 3322
/* 2955 */    MCD::OPC_CheckField, 8, 8, 0, 105, 1, // Skip to: 3322
/* 2961 */    MCD::OPC_Decode, 56, 136, 1, // Opcode: ALGHSIK
/* 2965 */    MCD::OPC_FilterValue, 237, 1, 96, 1, // Skip to: 3322
/* 2970 */    MCD::OPC_ExtractField, 0, 8,  // Inst{7-0} ...
/* 2973 */    MCD::OPC_FilterValue, 4, 11, 0, // Skip to: 2988
/* 2977 */    MCD::OPC_CheckField, 8, 8, 0, 83, 1, // Skip to: 3322
/* 2983 */    MCD::OPC_Decode, 169, 4, 137, 1, // Opcode: LDEB
/* 2988 */    MCD::OPC_FilterValue, 5, 11, 0, // Skip to: 3003
/* 2992 */    MCD::OPC_CheckField, 8, 8, 0, 68, 1, // Skip to: 3322
/* 2998 */    MCD::OPC_Decode, 138, 5, 138, 1, // Opcode: LXDB
/* 3003 */    MCD::OPC_FilterValue, 6, 11, 0, // Skip to: 3018
/* 3007 */    MCD::OPC_CheckField, 8, 8, 0, 53, 1, // Skip to: 3322
/* 3013 */    MCD::OPC_Decode, 140, 5, 138, 1, // Opcode: LXEB
/* 3018 */    MCD::OPC_FilterValue, 7, 11, 0, // Skip to: 3033
/* 3022 */    MCD::OPC_CheckField, 8, 8, 0, 38, 1, // Skip to: 3322
/* 3028 */    MCD::OPC_Decode, 187, 5, 139, 1, // Opcode: MXDB
/* 3033 */    MCD::OPC_FilterValue, 9, 11, 0, // Skip to: 3048
/* 3037 */    MCD::OPC_CheckField, 8, 8, 0, 23, 1, // Skip to: 3322
/* 3043 */    MCD::OPC_Decode, 137, 3, 140, 1, // Opcode: CEB
/* 3048 */    MCD::OPC_FilterValue, 10, 10, 0, // Skip to: 3062
/* 3052 */    MCD::OPC_CheckField, 8, 8, 0, 8, 1, // Skip to: 3322
/* 3058 */    MCD::OPC_Decode, 25, 141, 1, // Opcode: AEB
/* 3062 */    MCD::OPC_FilterValue, 11, 11, 0, // Skip to: 3077
/* 3066 */    MCD::OPC_CheckField, 8, 8, 0, 250, 0, // Skip to: 3322
/* 3072 */    MCD::OPC_Decode, 135, 6, 141, 1, // Opcode: SEB
/* 3077 */    MCD::OPC_FilterValue, 12, 11, 0, // Skip to: 3092
/* 3081 */    MCD::OPC_CheckField, 8, 8, 0, 235, 0, // Skip to: 3322
/* 3087 */    MCD::OPC_Decode, 153, 5, 142, 1, // Opcode: MDEB
/* 3092 */    MCD::OPC_FilterValue, 13, 11, 0, // Skip to: 3107
/* 3096 */    MCD::OPC_CheckField, 8, 8, 0, 220, 0, // Skip to: 3322
/* 3102 */    MCD::OPC_Decode, 240, 3, 141, 1, // Opcode: DEB
/* 3107 */    MCD::OPC_FilterValue, 14, 11, 0, // Skip to: 3122
/* 3111 */    MCD::OPC_CheckField, 8, 4, 0, 205, 0, // Skip to: 3322
/* 3117 */    MCD::OPC_Decode, 149, 5, 143, 1, // Opcode: MAEB
/* 3122 */    MCD::OPC_FilterValue, 15, 11, 0, // Skip to: 3137
/* 3126 */    MCD::OPC_CheckField, 8, 4, 0, 190, 0, // Skip to: 3322
/* 3132 */    MCD::OPC_Decode, 166, 5, 143, 1, // Opcode: MSEB
/* 3137 */    MCD::OPC_FilterValue, 20, 11, 0, // Skip to: 3152
/* 3141 */    MCD::OPC_CheckField, 8, 8, 0, 175, 0, // Skip to: 3322
/* 3147 */    MCD::OPC_Decode, 164, 6, 140, 1, // Opcode: SQEB
/* 3152 */    MCD::OPC_FilterValue, 21, 11, 0, // Skip to: 3167
/* 3156 */    MCD::OPC_CheckField, 8, 8, 0, 160, 0, // Skip to: 3322
/* 3162 */    MCD::OPC_Decode, 162, 6, 137, 1, // Opcode: SQDB
/* 3167 */    MCD::OPC_FilterValue, 23, 11, 0, // Skip to: 3182
/* 3171 */    MCD::OPC_CheckField, 8, 8, 0, 145, 0, // Skip to: 3322
/* 3177 */    MCD::OPC_Decode, 155, 5, 141, 1, // Opcode: MEEB
/* 3182 */    MCD::OPC_FilterValue, 25, 11, 0, // Skip to: 3197
/* 3186 */    MCD::OPC_CheckField, 8, 8, 0, 130, 0, // Skip to: 3322
/* 3192 */    MCD::OPC_Decode, 133, 3, 137, 1, // Opcode: CDB
/* 3197 */    MCD::OPC_FilterValue, 26, 10, 0, // Skip to: 3211
/* 3201 */    MCD::OPC_CheckField, 8, 8, 0, 115, 0, // Skip to: 3322
/* 3207 */    MCD::OPC_Decode, 20, 142, 1, // Opcode: ADB
/* 3211 */    MCD::OPC_FilterValue, 27, 11, 0, // Skip to: 3226
/* 3215 */    MCD::OPC_CheckField, 8, 8, 0, 101, 0, // Skip to: 3322
/* 3221 */    MCD::OPC_Decode, 133, 6, 142, 1, // Opcode: SDB
/* 3226 */    MCD::OPC_FilterValue, 28, 11, 0, // Skip to: 3241
/* 3230 */    MCD::OPC_CheckField, 8, 8, 0, 86, 0, // Skip to: 3322
/* 3236 */    MCD::OPC_Decode, 151, 5, 142, 1, // Opcode: MDB
/* 3241 */    MCD::OPC_FilterValue, 29, 11, 0, // Skip to: 3256
/* 3245 */    MCD::OPC_CheckField, 8, 8, 0, 71, 0, // Skip to: 3322
/* 3251 */    MCD::OPC_Decode, 238, 3, 142, 1, // Opcode: DDB
/* 3256 */    MCD::OPC_FilterValue, 30, 11, 0, // Skip to: 3271
/* 3260 */    MCD::OPC_CheckField, 8, 4, 0, 56, 0, // Skip to: 3322
/* 3266 */    MCD::OPC_Decode, 147, 5, 144, 1, // Opcode: MADB
/* 3271 */    MCD::OPC_FilterValue, 31, 11, 0, // Skip to: 3286
/* 3275 */    MCD::OPC_CheckField, 8, 4, 0, 41, 0, // Skip to: 3322
/* 3281 */    MCD::OPC_Decode, 164, 5, 144, 1, // Opcode: MSDB
/* 3286 */    MCD::OPC_FilterValue, 100, 5, 0, // Skip to: 3295
/* 3290 */    MCD::OPC_Decode, 179, 4, 145, 1, // Opcode: LEY
/* 3295 */    MCD::OPC_FilterValue, 101, 5, 0, // Skip to: 3304
/* 3299 */    MCD::OPC_Decode, 174, 4, 146, 1, // Opcode: LDY
/* 3304 */    MCD::OPC_FilterValue, 102, 5, 0, // Skip to: 3313
/* 3308 */    MCD::OPC_Decode, 186, 6, 145, 1, // Opcode: STEY
/* 3313 */    MCD::OPC_FilterValue, 103, 5, 0, // Skip to: 3322
/* 3317 */    MCD::OPC_Decode, 184, 6, 146, 1, // Opcode: STDY
/* 3322 */    MCD::OPC_Fail,
  0
};

static bool checkDecoderPredicate(unsigned Idx, uint64_t Bits) {
  switch (Idx) {
  default: llvm_unreachable("Invalid index!");
  case 0:
    return ((Bits & SystemZ::FeatureFPExtension));
  case 1:
    return ((Bits & SystemZ::FeatureLoadStoreOnCond));
  case 2:
    return ((Bits & SystemZ::FeatureDistinctOps));
  case 3:
    return ((Bits & SystemZ::FeatureHighWord));
  }
}

template<typename InsnType>
static DecodeStatus decodeToMCInst(DecodeStatus S, unsigned Idx, InsnType insn, MCInst &MI,
                                   uint64_t Address, const void *Decoder) {
  InsnType tmp;
  switch (Idx) {
  default: llvm_unreachable("Invalid index!");
  case 0:
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeADDR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 1:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 2:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeADDR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 3:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 4:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 5:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 6:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 7:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 8:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 9:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 10:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 11:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 12:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 13:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeBDAddr32Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 14:
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeBDAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 8);
    if (decodeU8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 15:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGRH32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGRH32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeU16ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 16:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeU16ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 17:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeU16ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 18:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeU16ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 19:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGRH32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeU16ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 20:
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 21:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 22:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 23:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 24:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 25:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeS16ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 26:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeS16ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 27:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeS16ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 28:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeS16ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 29:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 30:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (decodeAccessRegOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 31:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 32:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 33:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 34:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 35:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 36:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 37:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 38:
    tmp = fieldFromInstruction(insn, 12, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 39:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 40:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 41:
    tmp = fieldFromInstruction(insn, 12, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 42:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 43:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 44:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 45:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 46:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 47:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 48:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 49:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 50:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 51:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 52:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 53:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 54:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 55:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 56:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 57:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 58:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 59:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 60:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 61:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 62:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 63:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 64:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 65:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 66:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 67:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 68:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 69:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 70:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 71:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 72:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 73:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 74:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 75:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 76:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 77:
    tmp = fieldFromInstruction(insn, 4, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 78:
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 20, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeBDAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 79:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodePC32DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 80:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodeS32ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 81:
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodePC32DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 82:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodePC32DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 83:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGRH32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGRH32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodeU32ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 84:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodeU32ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 85:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGRH32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodeU32ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 86:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodeU32ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 87:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodeU32ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 88:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodeS32ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 89:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodeS32ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 90:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodeU32ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 91:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodeS32ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 92:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodePC32DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 93:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGRH32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGRH32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodeS32ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 94:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGRH32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 32);
    if (decodeS32ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 95:
    tmp = fieldFromInstruction(insn, 16, 24);
    if (decodeBDLAddr64Disp12Len8Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeBDAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 96:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 28);
    if (decodeBDXAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 97:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 28);
    if (decodeBDXAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 98:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 28);
    if (decodeBDXAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 99:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 28);
    if (decodeBDXAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 100:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 28);
    if (decodeBDXAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 101:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 28);
    if (decodeBDXAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 102:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGRH32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 28);
    if (decodeBDXAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 103:
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodeBDAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeS16ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 104:
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodeBDAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeU16ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 105:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 106:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr32Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 107:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 108:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr32Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 109:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 110:
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 8);
    if (decodeU8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 111:
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 8);
    if (decodeS8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 112:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 113:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 114:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 115:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 116:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 117:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 118:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 119:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 24);
    if (decodeBDAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 120:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 24, 8);
    if (decodeU8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 8);
    if (decodeU8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 8);
    if (decodeU6ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 121:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 24, 8);
    if (decodeU8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 8);
    if (decodeU8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 8);
    if (decodeU6ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 122:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGRH32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGRH32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 24, 8);
    if (decodeU8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 8);
    if (decodeU8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 8);
    if (decodeU6ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 123:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 124:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 125:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 126:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 127:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 8);
    if (decodeS8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 128:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 8);
    if (decodeS8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 129:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 8);
    if (decodeU8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 130:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 8);
    if (decodeU8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 131:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 8);
    if (decodeS8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 132:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 8);
    if (decodeS8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 133:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 8);
    if (decodeU8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 134:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 8);
    if (decodeU8ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (decodeU4ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodePC16DBLOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 135:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodeS16ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 136:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 32, 4);
    if (DecodeGR64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 16);
    if (decodeS16ImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 137:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 138:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 139:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeFP128BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 140:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 141:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 142:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 143:
    tmp = fieldFromInstruction(insn, 12, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 144:
    tmp = fieldFromInstruction(insn, 12, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 12, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 16, 20);
    if (decodeBDXAddr64Disp12Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 145:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeFP32BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 28);
    if (decodeBDXAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  case 146:
    tmp = fieldFromInstruction(insn, 36, 4);
    if (DecodeFP64BitRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    tmp = fieldFromInstruction(insn, 8, 28);
    if (decodeBDXAddr64Disp20Operand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) return MCDisassembler::Fail;
    return S;
  }
}

template<typename InsnType>
static DecodeStatus decodeInstruction(const uint8_t DecodeTable[], MCInst &MI,
                                      InsnType insn, uint64_t Address,
                                      const void *DisAsm,
                                      const MCSubtargetInfo &STI) {
  uint64_t Bits = STI.getFeatureBits();

  const uint8_t *Ptr = DecodeTable;
  uint32_t CurFieldValue = 0;
  DecodeStatus S = MCDisassembler::Success;
  for (;;) {
    ptrdiff_t Loc = Ptr - DecodeTable;
    switch (*Ptr) {
    default:
      errs() << Loc << ": Unexpected decode table opcode!\n";
      return MCDisassembler::Fail;
    case MCD::OPC_ExtractField: {
      unsigned Start = *++Ptr;
      unsigned Len = *++Ptr;
      ++Ptr;
      CurFieldValue = fieldFromInstruction(insn, Start, Len);
      DEBUG(dbgs() << Loc << ": OPC_ExtractField(" << Start << ", "
                   << Len << "): " << CurFieldValue << "\n");
      break;
    }
    case MCD::OPC_FilterValue: {
      // Decode the field value.
      unsigned Len;
      InsnType Val = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      // NumToSkip is a plain 16-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;

      // Perform the filter operation.
      if (Val != CurFieldValue)
        Ptr += NumToSkip;
      DEBUG(dbgs() << Loc << ": OPC_FilterValue(" << Val << ", " << NumToSkip
                   << "): " << ((Val != CurFieldValue) ? "FAIL:" : "PASS:")
                   << " continuing at " << (Ptr - DecodeTable) << "\n");

      break;
    }
    case MCD::OPC_CheckField: {
      unsigned Start = *++Ptr;
      unsigned Len = *++Ptr;
      InsnType FieldValue = fieldFromInstruction(insn, Start, Len);
      // Decode the field value.
      uint32_t ExpectedValue = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      // NumToSkip is a plain 16-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;

      // If the actual and expected values don't match, skip.
      if (ExpectedValue != FieldValue)
        Ptr += NumToSkip;
      DEBUG(dbgs() << Loc << ": OPC_CheckField(" << Start << ", "
                   << Len << ", " << ExpectedValue << ", " << NumToSkip
                   << "): FieldValue = " << FieldValue << ", ExpectedValue = "
                   << ExpectedValue << ": "
                   << ((ExpectedValue == FieldValue) ? "PASS\n" : "FAIL\n"));
      break;
    }
    case MCD::OPC_CheckPredicate: {
      unsigned Len;
      // Decode the Predicate Index value.
      unsigned PIdx = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      // NumToSkip is a plain 16-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;
      // Check the predicate.
      bool Pred;
      if (!(Pred = checkDecoderPredicate(PIdx, Bits)))
        Ptr += NumToSkip;
      (void)Pred;
      DEBUG(dbgs() << Loc << ": OPC_CheckPredicate(" << PIdx << "): "
            << (Pred ? "PASS\n" : "FAIL\n"));

      break;
    }
    case MCD::OPC_Decode: {
      unsigned Len;
      // Decode the Opcode value.
      unsigned Opc = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      unsigned DecodeIdx = decodeULEB128(Ptr, &Len);
      Ptr += Len;
      DEBUG(dbgs() << Loc << ": OPC_Decode: opcode " << Opc
                   << ", using decoder " << DecodeIdx << "\n" );
      DEBUG(dbgs() << "----- DECODE SUCCESSFUL -----\n");

      MI.setOpcode(Opc);
      return decodeToMCInst(S, DecodeIdx, insn, MI, Address, DisAsm);
    }
    case MCD::OPC_SoftFail: {
      // Decode the mask values.
      unsigned Len;
      InsnType PositiveMask = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      InsnType NegativeMask = decodeULEB128(Ptr, &Len);
      Ptr += Len;
      bool Fail = (insn & PositiveMask) || (~insn & NegativeMask);
      if (Fail)
        S = MCDisassembler::SoftFail;
      DEBUG(dbgs() << Loc << ": OPC_SoftFail: " << (Fail ? "FAIL\n":"PASS\n"));
      break;
    }
    case MCD::OPC_Fail: {
      DEBUG(dbgs() << Loc << ": OPC_Fail\n");
      return MCDisassembler::Fail;
    }
    }
  }
  llvm_unreachable("bogosity detected in disassembler state machine!");
}


} // End llvm namespace

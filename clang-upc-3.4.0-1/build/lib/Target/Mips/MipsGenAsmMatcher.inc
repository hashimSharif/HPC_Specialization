/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Assembly Matcher Source Fragment                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_ASSEMBLER_HEADER
#undef GET_ASSEMBLER_HEADER
  // This should be included into the middle of the declaration of
  // your subclasses implementation of MCTargetAsmParser.
  unsigned ComputeAvailableFeatures(uint64_t FeatureBits) const;
  void convertToMCInst(unsigned Kind, MCInst &Inst, unsigned Opcode,
                       const SmallVectorImpl<MCParsedAsmOperand*> &Operands);
  void convertToMapAndConstraints(unsigned Kind,
                           const SmallVectorImpl<MCParsedAsmOperand*> &Operands);
  bool mnemonicIsValid(StringRef Mnemonic, unsigned VariantID);
  unsigned MatchInstructionImpl(
                           const SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                                MCInst &Inst,
                                unsigned &ErrorInfo, bool matchingInlineAsm,
                                unsigned VariantID = 0);

  enum OperandMatchResultTy {
    MatchOperand_Success,    // operand matched successfully
    MatchOperand_NoMatch,    // operand did not match
    MatchOperand_ParseFail   // operand matched but had errors
  };
  OperandMatchResultTy MatchOperandParserImpl(
    SmallVectorImpl<MCParsedAsmOperand*> &Operands,
    StringRef Mnemonic);
  OperandMatchResultTy tryCustomParseOperand(
    SmallVectorImpl<MCParsedAsmOperand*> &Operands,
    unsigned MCK);

#endif // GET_ASSEMBLER_HEADER_INFO


#ifdef GET_OPERAND_DIAGNOSTIC_TYPES
#undef GET_OPERAND_DIAGNOSTIC_TYPES

#endif // GET_OPERAND_DIAGNOSTIC_TYPES


#ifdef GET_REGISTER_MATCHER
#undef GET_REGISTER_MATCHER

// Flags for subtarget features that participate in instruction matching.
enum SubtargetFeatureFlag {
  Feature_HasSEInReg = (1 << 10),
  Feature_HasBitCount = (1 << 0),
  Feature_HasSwap = (1 << 12),
  Feature_HasCondMov = (1 << 1),
  Feature_HasFPIdx = (1 << 4),
  Feature_HasMips32 = (1 << 6),
  Feature_HasMips32r2 = (1 << 7),
  Feature_HasMips64 = (1 << 8),
  Feature_NotMips64 = (1 << 22),
  Feature_HasMips64r2 = (1 << 9),
  Feature_IsN64 = (1 << 16),
  Feature_NotN64 = (1 << 23),
  Feature_InMips16Mode = (1 << 14),
  Feature_RelocStatic = (1 << 25),
  Feature_RelocPIC = (1 << 24),
  Feature_NoNaNsFPMath = (1 << 19),
  Feature_HasStdEnc = (1 << 11),
  Feature_InMicroMips = (1 << 13),
  Feature_NotInMicroMips = (1 << 21),
  Feature_IsFP64bit = (1 << 15),
  Feature_NotFP64bit = (1 << 20),
  Feature_IsSingleFloat = (1 << 18),
  Feature_IsNotSingleFloat = (1 << 17),
  Feature_HasDSP = (1 << 2),
  Feature_HasDSPR2 = (1 << 3),
  Feature_HasMSA = (1 << 5),
  Feature_None = 0
};

#endif // GET_REGISTER_MATCHER


#ifdef GET_SUBTARGET_FEATURE_NAME
#undef GET_SUBTARGET_FEATURE_NAME

// User-level names for subtarget features that participate in
// instruction matching.
static const char *getSubtargetFeatureName(unsigned Val) {
  switch(Val) {
  case Feature_HasSEInReg: return "";
  case Feature_HasBitCount: return "";
  case Feature_HasSwap: return "";
  case Feature_HasCondMov: return "";
  case Feature_HasFPIdx: return "";
  case Feature_HasMips32: return "";
  case Feature_HasMips32r2: return "";
  case Feature_HasMips64: return "";
  case Feature_NotMips64: return "";
  case Feature_HasMips64r2: return "";
  case Feature_IsN64: return "";
  case Feature_NotN64: return "";
  case Feature_InMips16Mode: return "";
  case Feature_RelocStatic: return "";
  case Feature_RelocPIC: return "";
  case Feature_NoNaNsFPMath: return "";
  case Feature_HasStdEnc: return "";
  case Feature_InMicroMips: return "";
  case Feature_NotInMicroMips: return "";
  case Feature_IsFP64bit: return "";
  case Feature_NotFP64bit: return "";
  case Feature_IsSingleFloat: return "";
  case Feature_IsNotSingleFloat: return "";
  case Feature_HasDSP: return "";
  case Feature_HasDSPR2: return "";
  case Feature_HasMSA: return "";
  default: return "(unknown)";
  }
}

#endif // GET_SUBTARGET_FEATURE_NAME


#ifdef GET_MATCHER_IMPLEMENTATION
#undef GET_MATCHER_IMPLEMENTATION

namespace {
enum OperatorConversionKind {
  CVT_Done,
  CVT_Reg,
  CVT_Tied,
  CVT_95_addRegAsmOperands,
  CVT_95_addImmOperands,
  CVT_95_Reg,
  CVT_regZERO,
  CVT_regFCC0,
  CVT_imm_0,
  CVT_regRA,
  CVT_95_addMemOperands,
  CVT_95_addPtrRegOperands,
  CVT_regZERO_64,
  CVT_NUM_CONVERTERS
};

enum InstructionConversionKind {
  Convert__AFGR64Asm1_0__AFGR64Asm1_1,
  Convert__FGR64Asm1_0__FGR64Asm1_1,
  Convert__FGR32Asm1_0__FGR32Asm1_1,
  Convert__GPR32Asm1_0__GPR32Asm1_1,
  Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2,
  Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2,
  Convert__AFGR64Asm1_0__AFGR64Asm1_1__AFGR64Asm1_2,
  Convert__FGR64Asm1_0__FGR64Asm1_1__FGR64Asm1_2,
  Convert__FGR32Asm1_0__FGR32Asm1_1__FGR32Asm1_2,
  Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2,
  Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2,
  Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2,
  Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2,
  Convert__GPR32Asm1_0__GPR32Asm1_0__Imm1_1,
  Convert__Reg1_0__Imm1_1,
  Convert__Imm1_1,
  Convert__Reg1_0__Reg1_1__Imm1_2,
  Convert__Reg1_0__Imm1_2,
  Convert__Reg1_0__Tie0__Imm1_1,
  Convert__Reg1_0__Reg1_1__Reg1_2,
  Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2,
  Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2,
  Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2,
  Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2,
  Convert__Reg1_0__Tie0__Reg1_1,
  Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Tie0,
  Convert__Imm1_0,
  Convert__regZERO__regZERO__Imm1_0,
  Convert__regZERO__Imm1_0,
  Convert__regFCC0__Imm1_0,
  Convert__FCCRegsAsm1_0__Imm1_1,
  Convert__GPR32Asm1_0__regZERO__Imm1_1,
  Convert__GPR32Asm1_0__Imm1_1,
  Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2,
  Convert__MSA128DAsm1_0__Tie0__MSA128DAsm1_1__MSA128DAsm1_2,
  Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2,
  Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2,
  Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__Imm1_2,
  Convert__MSA128DAsm1_0__Tie0__MSA128DAsm1_1__Imm1_2,
  Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__Imm1_2,
  Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__Imm1_2,
  Convert__MSA128BAsm1_0__Imm1_1,
  Convert__MSA128DAsm1_0__Imm1_1,
  Convert__MSA128HAsm1_0__Imm1_1,
  Convert__MSA128WAsm1_0__Imm1_1,
  Convert__imm_0__imm_0,
  Convert_NoOperands,
  Convert__Imm1_0__imm_0,
  Convert__Imm1_0__Imm1_1,
  Convert__FGR64Asm1_0__FGR32Asm1_1,
  Convert__FGR32Asm1_0__AFGR64Asm1_1,
  Convert__FGR32Asm1_0__FGR64Asm1_1,
  Convert__GPR32Asm1_0__CCRAsm1_1,
  Convert__GPR32Asm1_0__MSA128CRAsm1_1,
  Convert__Reg1_0__Reg1_1,
  Convert__GPR32Asm1_0__MSA128BAsm1_1__Imm1_3,
  Convert__GPR32Asm1_0__MSA128HAsm1_1__Imm1_3,
  Convert__GPR32Asm1_0__MSA128WAsm1_1__Imm1_3,
  Convert__CCRAsm1_1__GPR32Asm1_0,
  Convert__MSA128CRAsm1_0__GPR32Asm1_1,
  Convert__AFGR64Asm1_0__FGR32Asm1_1,
  Convert__GPR64Asm1_0__GPR64Asm1_1__GPR64Asm1_2,
  Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2,
  Convert__GPR64Asm1_0__GPR64Asm1_0__Imm1_1,
  Convert__GPR64Asm1_0__GPR64Asm1_1,
  Convert__GPR64Asm1_1__GPR64Asm1_2,
  Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2__Imm1_3,
  Convert__regZERO,
  Convert__GPR32Asm1_0,
  Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2__Imm1_3__Tie0,
  Convert__Reg1_1__Reg1_2,
  Convert__GPR32Asm1_1__GPR32Asm1_2,
  Convert__GPR64Asm1_0__GPR64Asm1_1__imm_0,
  Convert__GPR64Asm1_0__FGR64Asm1_1,
  Convert__FGR64Asm1_1__GPR64Asm1_0,
  Convert__MSA128DAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2,
  Convert__MSA128HAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2,
  Convert__MSA128WAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2,
  Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0,
  Convert__MSA128DAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2,
  Convert__MSA128HAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2,
  Convert__MSA128WAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2,
  Convert__GPR64Asm1_0__GPR64Asm1_1__GPR32Asm1_2,
  Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Imm1_3,
  Convert__GPR32Asm1_0__ACC64DSPAsm1_1__Imm1_2,
  Convert__GPR32Asm1_0__ACC64DSPAsm1_1__GPR32Asm1_2,
  Convert__MSA128DAsm1_0__MSA128DAsm1_1,
  Convert__MSA128WAsm1_0__MSA128WAsm1_1,
  Convert__MSA128HAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2,
  Convert__MSA128WAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2,
  Convert__MSA128DAsm1_0__MSA128WAsm1_1,
  Convert__MSA128WAsm1_0__MSA128HAsm1_1,
  Convert__MSA128BAsm1_0__GPR32Asm1_1,
  Convert__MSA128HAsm1_0__GPR32Asm1_1,
  Convert__MSA128WAsm1_0__GPR32Asm1_1,
  Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Imm1_3__Tie0,
  Convert__MSA128BAsm1_0__Tie0__GPR32Asm1_4__Imm1_2,
  Convert__MSA128HAsm1_0__Tie0__GPR32Asm1_4__Imm1_2,
  Convert__MSA128WAsm1_0__Tie0__GPR32Asm1_4__Imm1_2,
  Convert__GPR32Asm1_0__Tie0__GPR32Asm1_1,
  Convert__MSA128BAsm1_0__Tie0__Imm1_2__MSA128BAsm1_4,
  Convert__MSA128DAsm1_0__Tie0__Imm1_2__MSA128DAsm1_4,
  Convert__MSA128HAsm1_0__Tie0__Imm1_2__MSA128HAsm1_4,
  Convert__MSA128WAsm1_0__Tie0__Imm1_2__MSA128WAsm1_4,
  Convert__regRA__GPR32Asm1_0,
  Convert__Reg1_0,
  Convert__GPR32Asm1_0__Mem2_1,
  Convert__GPR32Asm1_0__PtrReg1_3__PtrReg1_1,
  Convert__GPR64Asm1_0__Mem2_1,
  Convert__MSA128BAsm1_0__Mem2_1,
  Convert__MSA128DAsm1_0__Mem2_1,
  Convert__MSA128HAsm1_0__Mem2_1,
  Convert__MSA128WAsm1_0__Mem2_1,
  Convert__AFGR64Asm1_0__Mem2_1,
  Convert__FGR64Asm1_0__Mem2_1,
  Convert__COP2Asm1_0__Mem2_1,
  Convert__GPR64Asm1_0__Mem2_1__Tie0,
  Convert__AFGR64Asm1_0__PtrReg1_3__PtrReg1_1,
  Convert__FGR64Asm1_0__PtrReg1_3__PtrReg1_1,
  Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2__LSAImm1_3,
  Convert__Reg1_0__Imm1_1__imm_0,
  Convert__Reg1_0__Reg1_3__Imm1_1,
  Convert__FGR32Asm1_0__Mem2_1,
  Convert__GPR32Asm1_0__Mem2_1__Tie0,
  Convert__FGR32Asm1_0__PtrReg1_3__PtrReg1_1,
  Convert__AFGR64Asm1_0__AFGR64Asm1_1__AFGR64Asm1_2__AFGR64Asm1_3,
  Convert__FGR32Asm1_0__FGR32Asm1_1__FGR32Asm1_2__FGR32Asm1_3,
  Convert__GPR32Asm1_0__GPR32Asm1_1__imm_0,
  Convert__GPR32Asm1_0__FGR32Asm1_1,
  Convert__GPR32Asm1_0__FGRH32Asm1_1,
  Convert__GPR32Asm1_0__ACC64DSPAsm1_1,
  Convert__GPR32Asm1_0__GPR32Asm1_1__regZERO,
  Convert__GPR64Asm1_0__GPR64Asm1_1__regZERO_64,
  Convert__MSA128BAsm1_0__MSA128BAsm1_1,
  Convert__GPR32Asm1_0__GPR32Asm1_1__FCCRegsAsm1_2__Tie0,
  Convert__AFGR64Asm1_0__AFGR64Asm1_1__FCCRegsAsm1_2__Tie0,
  Convert__FGR64Asm1_0__FGR64Asm1_1__FCCRegsAsm1_2__Tie0,
  Convert__FGR32Asm1_0__FGR32Asm1_1__FCCRegsAsm1_2__Tie0,
  Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0,
  Convert__AFGR64Asm1_0__AFGR64Asm1_1__GPR32Asm1_2__Tie0,
  Convert__FGR64Asm1_0__FGR64Asm1_1__GPR32Asm1_2__Tie0,
  Convert__FGR32Asm1_0__FGR32Asm1_1__GPR32Asm1_2__Tie0,
  Convert__FGR32Asm1_1__GPR32Asm1_0,
  Convert__FGRH32Asm1_1__GPR32Asm1_0,
  Convert__HI32DSPAsm1_1__GPR32Asm1_0,
  Convert__ACC64DSPAsm1_1__GPR32Asm1_0__Tie0,
  Convert__LO32DSPAsm1_1__GPR32Asm1_0,
  Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2,
  Convert__GPR32Asm1_0__regZERO__GPR32Asm1_1,
  Convert__MSA128HAsm1_0__MSA128HAsm1_1,
  Convert__regZERO__regZERO__imm_0,
  Convert__GPR32Asm1_0__HWRegsAsm1_1,
  Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3,
  Convert__GPR32Asm1_0__Tie0__Mem2_1,
  Convert__GPR64Asm1_0__Tie0__Mem2_1,
  Convert__Reg1_0__Tie0,
  Convert__ACC64DSPAsm1_0__Imm1_1__Tie0,
  Convert__ACC64DSPAsm1_0__GPR32Asm1_1__Tie0,
  Convert__MSA128BAsm1_0__MSA128BAsm1_1__Reg1_3,
  Convert__MSA128DAsm1_0__MSA128DAsm1_1__Reg1_3,
  Convert__MSA128HAsm1_0__MSA128HAsm1_1__Reg1_3,
  Convert__MSA128WAsm1_0__MSA128WAsm1_1__Reg1_3,
  Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_3,
  Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_3,
  Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_3,
  Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_3,
  Convert__GPR32Asm1_0__GPR32Asm1_1__InvNum1_2,
  Convert__imm_0,
  CVT_NUM_SIGNATURES
};

} // end anonymous namespace

static const uint8_t ConversionTable[CVT_NUM_SIGNATURES][11] = {
  // Convert__AFGR64Asm1_0__AFGR64Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__FGR64Asm1_0__FGR64Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__FGR32Asm1_0__FGR32Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__GPR32Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__AFGR64Asm1_0__AFGR64Asm1_1__AFGR64Asm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__FGR64Asm1_0__FGR64Asm1_1__FGR64Asm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__FGR32Asm1_0__FGR32Asm1_1__FGR32Asm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__GPR32Asm1_0__GPR32Asm1_0__Imm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__Imm1_1
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Imm1_1
  { CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Imm1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Imm1_2
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Tie0__Imm1_1
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Done },
  // Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Tied, 0, CVT_Done },
  // Convert__Imm1_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__regZERO__regZERO__Imm1_0
  { CVT_regZERO, 0, CVT_regZERO, 0, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__regZERO__Imm1_0
  { CVT_regZERO, 0, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__regFCC0__Imm1_0
  { CVT_regFCC0, 0, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__FCCRegsAsm1_0__Imm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__regZERO__Imm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_regZERO, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__Imm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128DAsm1_0__Tie0__MSA128DAsm1_1__MSA128DAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__MSA128DAsm1_0__Tie0__MSA128DAsm1_1__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__MSA128BAsm1_0__Imm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__MSA128DAsm1_0__Imm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__MSA128HAsm1_0__Imm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__MSA128WAsm1_0__Imm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__imm_0__imm_0
  { CVT_imm_0, 0, CVT_imm_0, 0, CVT_Done },
  // Convert_NoOperands
  { CVT_Done },
  // Convert__Imm1_0__imm_0
  { CVT_95_addImmOperands, 1, CVT_imm_0, 0, CVT_Done },
  // Convert__Imm1_0__Imm1_1
  { CVT_95_addImmOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__FGR64Asm1_0__FGR32Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__FGR32Asm1_0__AFGR64Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__FGR32Asm1_0__FGR64Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__CCRAsm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__MSA128CRAsm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_1
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__GPR32Asm1_0__MSA128BAsm1_1__Imm1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__GPR32Asm1_0__MSA128HAsm1_1__Imm1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__GPR32Asm1_0__MSA128WAsm1_1__Imm1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__CCRAsm1_1__GPR32Asm1_0
  { CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 1, CVT_Done },
  // Convert__MSA128CRAsm1_0__GPR32Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__AFGR64Asm1_0__FGR32Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__GPR64Asm1_0__GPR64Asm1_1__GPR64Asm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__GPR64Asm1_0__GPR64Asm1_0__Imm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GPR64Asm1_0__GPR64Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__GPR64Asm1_1__GPR64Asm1_2
  { CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2__Imm1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__regZERO
  { CVT_regZERO, 0, CVT_Done },
  // Convert__GPR32Asm1_0
  { CVT_95_addRegAsmOperands, 1, CVT_Done },
  // Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2__Imm1_3__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Tied, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_2
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Done },
  // Convert__GPR32Asm1_1__GPR32Asm1_2
  { CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__GPR64Asm1_0__GPR64Asm1_1__imm_0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_imm_0, 0, CVT_Done },
  // Convert__GPR64Asm1_0__FGR64Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__FGR64Asm1_1__GPR64Asm1_0
  { CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 1, CVT_Done },
  // Convert__MSA128DAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128HAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128WAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Tied, 0, CVT_Done },
  // Convert__MSA128DAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128HAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128WAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__GPR64Asm1_0__GPR64Asm1_1__GPR32Asm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Imm1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__GPR32Asm1_0__ACC64DSPAsm1_1__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__GPR32Asm1_0__ACC64DSPAsm1_1__GPR32Asm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128DAsm1_0__MSA128DAsm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__MSA128WAsm1_0__MSA128WAsm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__MSA128HAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128WAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__MSA128DAsm1_0__MSA128WAsm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__MSA128WAsm1_0__MSA128HAsm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__MSA128BAsm1_0__GPR32Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__MSA128HAsm1_0__GPR32Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__MSA128WAsm1_0__GPR32Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Imm1_3__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Tied, 0, CVT_Done },
  // Convert__MSA128BAsm1_0__Tie0__GPR32Asm1_4__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 5, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__MSA128HAsm1_0__Tie0__GPR32Asm1_4__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 5, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__MSA128WAsm1_0__Tie0__GPR32Asm1_4__Imm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 5, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__GPR32Asm1_0__Tie0__GPR32Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__MSA128BAsm1_0__Tie0__Imm1_2__MSA128BAsm1_4
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_95_addRegAsmOperands, 5, CVT_Done },
  // Convert__MSA128DAsm1_0__Tie0__Imm1_2__MSA128DAsm1_4
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_95_addRegAsmOperands, 5, CVT_Done },
  // Convert__MSA128HAsm1_0__Tie0__Imm1_2__MSA128HAsm1_4
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_95_addRegAsmOperands, 5, CVT_Done },
  // Convert__MSA128WAsm1_0__Tie0__Imm1_2__MSA128WAsm1_4
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_95_addRegAsmOperands, 5, CVT_Done },
  // Convert__regRA__GPR32Asm1_0
  { CVT_regRA, 0, CVT_95_addRegAsmOperands, 1, CVT_Done },
  // Convert__Reg1_0
  { CVT_95_Reg, 1, CVT_Done },
  // Convert__GPR32Asm1_0__Mem2_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__PtrReg1_3__PtrReg1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addPtrRegOperands, 4, CVT_95_addPtrRegOperands, 2, CVT_Done },
  // Convert__GPR64Asm1_0__Mem2_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__MSA128BAsm1_0__Mem2_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__MSA128DAsm1_0__Mem2_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__MSA128HAsm1_0__Mem2_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__MSA128WAsm1_0__Mem2_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__AFGR64Asm1_0__Mem2_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__FGR64Asm1_0__Mem2_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__COP2Asm1_0__Mem2_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__GPR64Asm1_0__Mem2_1__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Tied, 0, CVT_Done },
  // Convert__AFGR64Asm1_0__PtrReg1_3__PtrReg1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addPtrRegOperands, 4, CVT_95_addPtrRegOperands, 2, CVT_Done },
  // Convert__FGR64Asm1_0__PtrReg1_3__PtrReg1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addPtrRegOperands, 4, CVT_95_addPtrRegOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2__LSAImm1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_0__Imm1_1__imm_0
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_imm_0, 0, CVT_Done },
  // Convert__Reg1_0__Reg1_3__Imm1_1
  { CVT_95_Reg, 1, CVT_95_Reg, 4, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__FGR32Asm1_0__Mem2_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__Mem2_1__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addMemOperands, 2, CVT_Tied, 0, CVT_Done },
  // Convert__FGR32Asm1_0__PtrReg1_3__PtrReg1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addPtrRegOperands, 4, CVT_95_addPtrRegOperands, 2, CVT_Done },
  // Convert__AFGR64Asm1_0__AFGR64Asm1_1__AFGR64Asm1_2__AFGR64Asm1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_95_addRegAsmOperands, 4, CVT_Done },
  // Convert__FGR32Asm1_0__FGR32Asm1_1__FGR32Asm1_2__FGR32Asm1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_95_addRegAsmOperands, 4, CVT_Done },
  // Convert__GPR32Asm1_0__GPR32Asm1_1__imm_0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_imm_0, 0, CVT_Done },
  // Convert__GPR32Asm1_0__FGR32Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__FGRH32Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__ACC64DSPAsm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__GPR32Asm1_1__regZERO
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_regZERO, 0, CVT_Done },
  // Convert__GPR64Asm1_0__GPR64Asm1_1__regZERO_64
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_regZERO_64, 0, CVT_Done },
  // Convert__MSA128BAsm1_0__MSA128BAsm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__GPR32Asm1_0__GPR32Asm1_1__FCCRegsAsm1_2__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Tied, 0, CVT_Done },
  // Convert__AFGR64Asm1_0__AFGR64Asm1_1__FCCRegsAsm1_2__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Tied, 0, CVT_Done },
  // Convert__FGR64Asm1_0__FGR64Asm1_1__FCCRegsAsm1_2__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Tied, 0, CVT_Done },
  // Convert__FGR32Asm1_0__FGR32Asm1_1__FCCRegsAsm1_2__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Tied, 0, CVT_Done },
  // Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Tied, 0, CVT_Done },
  // Convert__AFGR64Asm1_0__AFGR64Asm1_1__GPR32Asm1_2__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Tied, 0, CVT_Done },
  // Convert__FGR64Asm1_0__FGR64Asm1_1__GPR32Asm1_2__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Tied, 0, CVT_Done },
  // Convert__FGR32Asm1_0__FGR32Asm1_1__GPR32Asm1_2__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Tied, 0, CVT_Done },
  // Convert__FGR32Asm1_1__GPR32Asm1_0
  { CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 1, CVT_Done },
  // Convert__FGRH32Asm1_1__GPR32Asm1_0
  { CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 1, CVT_Done },
  // Convert__HI32DSPAsm1_1__GPR32Asm1_0
  { CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 1, CVT_Done },
  // Convert__ACC64DSPAsm1_1__GPR32Asm1_0__Tie0
  { CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_Done },
  // Convert__LO32DSPAsm1_1__GPR32Asm1_0
  { CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 1, CVT_Done },
  // Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addRegAsmOperands, 3, CVT_Done },
  // Convert__GPR32Asm1_0__regZERO__GPR32Asm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_regZERO, 0, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__MSA128HAsm1_0__MSA128HAsm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__regZERO__regZERO__imm_0
  { CVT_regZERO, 0, CVT_regZERO, 0, CVT_imm_0, 0, CVT_Done },
  // Convert__GPR32Asm1_0__HWRegsAsm1_1
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__GPR32Asm1_0__Tie0__Mem2_1
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__GPR64Asm1_0__Tie0__Mem2_1
  { CVT_95_addRegAsmOperands, 1, CVT_Tied, 0, CVT_95_addMemOperands, 2, CVT_Done },
  // Convert__Reg1_0__Tie0
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_Done },
  // Convert__ACC64DSPAsm1_0__Imm1_1__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_Done },
  // Convert__ACC64DSPAsm1_0__GPR32Asm1_1__Tie0
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_Tied, 0, CVT_Done },
  // Convert__MSA128BAsm1_0__MSA128BAsm1_1__Reg1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_Reg, 4, CVT_Done },
  // Convert__MSA128DAsm1_0__MSA128DAsm1_1__Reg1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_Reg, 4, CVT_Done },
  // Convert__MSA128HAsm1_0__MSA128HAsm1_1__Reg1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_Reg, 4, CVT_Done },
  // Convert__MSA128WAsm1_0__MSA128WAsm1_1__Reg1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_Reg, 4, CVT_Done },
  // Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_3
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__GPR32Asm1_0__GPR32Asm1_1__InvNum1_2
  { CVT_95_addRegAsmOperands, 1, CVT_95_addRegAsmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__imm_0
  { CVT_imm_0, 0, CVT_Done },
};

void MipsAsmParser::
convertToMCInst(unsigned Kind, MCInst &Inst, unsigned Opcode,
                const SmallVectorImpl<MCParsedAsmOperand*> &Operands) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  const uint8_t *Converter = ConversionTable[Kind];
  Inst.setOpcode(Opcode);
  for (const uint8_t *p = Converter; *p; p+= 2) {
    switch (*p) {
    default: llvm_unreachable("invalid conversion entry!");
    case CVT_Reg:
      static_cast<MipsOperand*>(Operands[*(p + 1)])->addRegOperands(Inst, 1);
      break;
    case CVT_Tied:
      Inst.addOperand(Inst.getOperand(*(p + 1)));
      break;
    case CVT_95_addRegAsmOperands:
      static_cast<MipsOperand*>(Operands[*(p + 1)])->addRegAsmOperands(Inst, 1);
      break;
    case CVT_95_addImmOperands:
      static_cast<MipsOperand*>(Operands[*(p + 1)])->addImmOperands(Inst, 1);
      break;
    case CVT_95_Reg:
      static_cast<MipsOperand*>(Operands[*(p + 1)])->addRegOperands(Inst, 1);
      break;
    case CVT_regZERO:
      Inst.addOperand(MCOperand::CreateReg(Mips::ZERO));
      break;
    case CVT_regFCC0:
      Inst.addOperand(MCOperand::CreateReg(Mips::FCC0));
      break;
    case CVT_imm_0:
      Inst.addOperand(MCOperand::CreateImm(0));
      break;
    case CVT_regRA:
      Inst.addOperand(MCOperand::CreateReg(Mips::RA));
      break;
    case CVT_95_addMemOperands:
      static_cast<MipsOperand*>(Operands[*(p + 1)])->addMemOperands(Inst, 2);
      break;
    case CVT_95_addPtrRegOperands:
      static_cast<MipsOperand*>(Operands[*(p + 1)])->addPtrRegOperands(Inst, 1);
      break;
    case CVT_regZERO_64:
      Inst.addOperand(MCOperand::CreateReg(Mips::ZERO_64));
      break;
    }
  }
}

void MipsAsmParser::
convertToMapAndConstraints(unsigned Kind,
                           const SmallVectorImpl<MCParsedAsmOperand*> &Operands) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  unsigned NumMCOperands = 0;
  const uint8_t *Converter = ConversionTable[Kind];
  for (const uint8_t *p = Converter; *p; p+= 2) {
    switch (*p) {
    default: llvm_unreachable("invalid conversion entry!");
    case CVT_Reg:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("r");
      ++NumMCOperands;
      break;
    case CVT_Tied:
      ++NumMCOperands;
      break;
    case CVT_95_addRegAsmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_Reg:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("r");
      NumMCOperands += 1;
      break;
    case CVT_regZERO:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_regFCC0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_imm_0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_regRA:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_95_addMemOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addPtrRegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_regZERO_64:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    }
  }
}

namespace {

/// MatchClassKind - The kinds of classes which participate in
/// instruction matching.
enum MatchClassKind {
  InvalidMatchClass = 0,
  MCK__35_, // '#'
  MCK__40_, // '('
  MCK__41_, // ')'
  MCK__41__59_, // ');'
  MCK_0, // '0'
  MCK_16, // '16'
  MCK__91_, // '['
  MCK__93_, // ']'
  MCK_bit, // 'bit'
  MCK_inst, // 'inst'
  MCK_ZERO, // register class 'ZERO'
  MCK_CPU16Regs, // register class 'CPU16Regs'
  MCK_CPUSPReg, // register class 'CPUSPReg,SP'
  MCK_CPU16RegsPlusSP, // register class 'CPU16RegsPlusSP'
  MCK_CPURAReg, // register class 'CPURAReg,RA'
  MCK_DSPR, // register class 'DSPR,GPR32'
  MCK_Reg7, // derived register class
  MCK_Reg9, // derived register class
  MCK_Reg8, // derived register class
  MCK_Reg10, // derived register class
  MCK_GPR64, // register class 'GPR64'
  MCK_FGR32, // register class 'FGR32'
  MCK_FGRH32, // register class 'FGRH32'
  MCK_AFGR64, // register class 'AFGR64'
  MCK_FGR64, // register class 'FGR64'
  MCK_MSA128B, // register class 'MSA128B,MSA128D,MSA128H,MSA128W'
  MCK_HI32, // register class 'HI32'
  MCK_HI32DSP, // register class 'HI32DSP'
  MCK_LO32, // register class 'LO32'
  MCK_LO32DSP, // register class 'LO32DSP'
  MCK_HI64, // register class 'HI64'
  MCK_LO64, // register class 'LO64'
  MCK_CCR, // register class 'CCR'
  MCK_FCC, // register class 'FCC'
  MCK_COP2, // register class 'COP2'
  MCK_PC, // register class 'PC'
  MCK_HWRegs, // register class 'HWRegs'
  MCK_ACC64, // register class 'ACC64'
  MCK_ACC64DSP, // register class 'ACC64DSP'
  MCK_ACC128, // register class 'ACC128'
  MCK_DSPCC, // register class 'DSPCC'
  MCK_MSACtrl, // register class 'MSACtrl'
  MCK_ACC64DSPAsm, // user defined class 'ACC64DSPAsmOperand'
  MCK_AFGR64Asm, // user defined class 'AFGR64AsmOperand'
  MCK_CCRAsm, // user defined class 'CCRAsmOperand'
  MCK_COP2Asm, // user defined class 'COP2AsmOperand'
  MCK_FCCRegsAsm, // user defined class 'FCCRegsAsmOperand'
  MCK_FGR32Asm, // user defined class 'FGR32AsmOperand'
  MCK_FGR64Asm, // user defined class 'FGR64AsmOperand'
  MCK_FGRH32Asm, // user defined class 'FGRH32AsmOperand'
  MCK_GPR32Asm, // user defined class 'GPR32AsmOperand'
  MCK_GPR64Asm, // user defined class 'GPR64AsmOperand'
  MCK_HI32DSPAsm, // user defined class 'HI32DSPAsmOperand'
  MCK_HWRegsAsm, // user defined class 'HWRegsAsmOperand'
  MCK_Imm, // user defined class 'ImmAsmOperand'
  MCK_LO32DSPAsm, // user defined class 'LO32DSPAsmOperand'
  MCK_MSA128BAsm, // user defined class 'MSA128BAsmOperand'
  MCK_MSA128CRAsm, // user defined class 'MSA128CRAsmOperand'
  MCK_MSA128DAsm, // user defined class 'MSA128DAsmOperand'
  MCK_MSA128HAsm, // user defined class 'MSA128HAsmOperand'
  MCK_MSA128WAsm, // user defined class 'MSA128WAsmOperand'
  MCK_InvNum, // user defined class 'MipsInvertedImmoperand'
  MCK_Mem, // user defined class 'MipsMemAsmOperand'
  MCK_PtrReg, // user defined class 'PtrRegAsmOperand'
  MCK_LSAImm, // user defined class 'uimm2LSAAsmOperand'
  NumMatchClassKinds
};

}

static MatchClassKind matchTokenString(StringRef Name) {
  switch (Name.size()) {
  default: break;
  case 1:	 // 6 strings to match.
    switch (Name[0]) {
    default: break;
    case '#':	 // 1 string to match.
      return MCK__35_;	 // "#"
    case '(':	 // 1 string to match.
      return MCK__40_;	 // "("
    case ')':	 // 1 string to match.
      return MCK__41_;	 // ")"
    case '0':	 // 1 string to match.
      return MCK_0;	 // "0"
    case '[':	 // 1 string to match.
      return MCK__91_;	 // "["
    case ']':	 // 1 string to match.
      return MCK__93_;	 // "]"
    }
    break;
  case 2:	 // 2 strings to match.
    switch (Name[0]) {
    default: break;
    case ')':	 // 1 string to match.
      if (Name[1] != ';')
        break;
      return MCK__41__59_;	 // ");"
    case '1':	 // 1 string to match.
      if (Name[1] != '6')
        break;
      return MCK_16;	 // "16"
    }
    break;
  case 3:	 // 1 string to match.
    if (memcmp(Name.data()+0, "bit", 3))
      break;
    return MCK_bit;	 // "bit"
  case 4:	 // 1 string to match.
    if (memcmp(Name.data()+0, "inst", 4))
      break;
    return MCK_inst;	 // "inst"
  }
  return InvalidMatchClass;
}

/// isSubclass - Compute whether \p A is a subclass of \p B.
static bool isSubclass(MatchClassKind A, MatchClassKind B) {
  if (A == B)
    return true;

  switch (A) {
  default:
    return false;

  case MCK_ZERO:
    return B == MCK_DSPR;

  case MCK_CPU16Regs:
    switch (B) {
    default: return false;
    case MCK_CPU16RegsPlusSP: return true;
    case MCK_DSPR: return true;
    }

  case MCK_CPUSPReg:
    switch (B) {
    default: return false;
    case MCK_CPU16RegsPlusSP: return true;
    case MCK_DSPR: return true;
    }

  case MCK_CPU16RegsPlusSP:
    return B == MCK_DSPR;

  case MCK_CPURAReg:
    return B == MCK_DSPR;

  case MCK_Reg7:
    switch (B) {
    default: return false;
    case MCK_Reg8: return true;
    case MCK_GPR64: return true;
    }

  case MCK_Reg9:
    switch (B) {
    default: return false;
    case MCK_Reg8: return true;
    case MCK_GPR64: return true;
    }

  case MCK_Reg8:
    return B == MCK_GPR64;

  case MCK_Reg10:
    return B == MCK_GPR64;

  case MCK_HI32:
    return B == MCK_HI32DSP;

  case MCK_LO32:
    return B == MCK_LO32DSP;

  case MCK_ACC64:
    return B == MCK_ACC64DSP;
  }
}

static unsigned validateOperandClass(MCParsedAsmOperand *GOp, MatchClassKind Kind) {
  MipsOperand &Operand = *(MipsOperand*)GOp;
  if (Kind == InvalidMatchClass)
    return MCTargetAsmParser::Match_InvalidOperand;

  if (Operand.isToken())
    return isSubclass(matchTokenString(Operand.getToken()), Kind) ?
             MCTargetAsmParser::Match_Success :
             MCTargetAsmParser::Match_InvalidOperand;

  // 'ACC64DSPAsm' class
  if (Kind == MCK_ACC64DSPAsm) {
    if (Operand.isACC64DSPAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'AFGR64Asm' class
  if (Kind == MCK_AFGR64Asm) {
    if (Operand.isAFGR64Asm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'CCRAsm' class
  if (Kind == MCK_CCRAsm) {
    if (Operand.isCCRAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'COP2Asm' class
  if (Kind == MCK_COP2Asm) {
    if (Operand.isCOP2Asm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'FCCRegsAsm' class
  if (Kind == MCK_FCCRegsAsm) {
    if (Operand.isFCCRegsAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'FGR32Asm' class
  if (Kind == MCK_FGR32Asm) {
    if (Operand.isFGR32Asm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'FGR64Asm' class
  if (Kind == MCK_FGR64Asm) {
    if (Operand.isFGR64Asm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'FGRH32Asm' class
  if (Kind == MCK_FGRH32Asm) {
    if (Operand.isFGRH32Asm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'GPR32Asm' class
  if (Kind == MCK_GPR32Asm) {
    if (Operand.isGPR32Asm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'GPR64Asm' class
  if (Kind == MCK_GPR64Asm) {
    if (Operand.isGPR64Asm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'HI32DSPAsm' class
  if (Kind == MCK_HI32DSPAsm) {
    if (Operand.isHI32DSPAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'HWRegsAsm' class
  if (Kind == MCK_HWRegsAsm) {
    if (Operand.isHWRegsAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm' class
  if (Kind == MCK_Imm) {
    if (Operand.isImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'LO32DSPAsm' class
  if (Kind == MCK_LO32DSPAsm) {
    if (Operand.isLO32DSPAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MSA128BAsm' class
  if (Kind == MCK_MSA128BAsm) {
    if (Operand.isMSA128BAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MSA128CRAsm' class
  if (Kind == MCK_MSA128CRAsm) {
    if (Operand.isMSA128CRAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MSA128DAsm' class
  if (Kind == MCK_MSA128DAsm) {
    if (Operand.isMSA128DAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MSA128HAsm' class
  if (Kind == MCK_MSA128HAsm) {
    if (Operand.isMSA128HAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MSA128WAsm' class
  if (Kind == MCK_MSA128WAsm) {
    if (Operand.isMSA128WAsm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'InvNum' class
  if (Kind == MCK_InvNum) {
    if (Operand.isInvNum())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Mem' class
  if (Kind == MCK_Mem) {
    if (Operand.isMem())
      return MCTargetAsmParser::Match_Success;
  }

  // 'PtrReg' class
  if (Kind == MCK_PtrReg) {
    if (Operand.isPtrReg())
      return MCTargetAsmParser::Match_Success;
  }

  // 'LSAImm' class
  if (Kind == MCK_LSAImm) {
    if (Operand.isLSAImm())
      return MCTargetAsmParser::Match_Success;
  }

  if (Operand.isReg()) {
    MatchClassKind OpKind;
    switch (Operand.getReg()) {
    default: OpKind = InvalidMatchClass; break;
    case Mips::ZERO: OpKind = MCK_ZERO; break;
    case Mips::AT: OpKind = MCK_DSPR; break;
    case Mips::V0: OpKind = MCK_CPU16Regs; break;
    case Mips::V1: OpKind = MCK_CPU16Regs; break;
    case Mips::A0: OpKind = MCK_CPU16Regs; break;
    case Mips::A1: OpKind = MCK_CPU16Regs; break;
    case Mips::A2: OpKind = MCK_CPU16Regs; break;
    case Mips::A3: OpKind = MCK_CPU16Regs; break;
    case Mips::T0: OpKind = MCK_DSPR; break;
    case Mips::T1: OpKind = MCK_DSPR; break;
    case Mips::T2: OpKind = MCK_DSPR; break;
    case Mips::T3: OpKind = MCK_DSPR; break;
    case Mips::T4: OpKind = MCK_DSPR; break;
    case Mips::T5: OpKind = MCK_DSPR; break;
    case Mips::T6: OpKind = MCK_DSPR; break;
    case Mips::T7: OpKind = MCK_DSPR; break;
    case Mips::S0: OpKind = MCK_CPU16Regs; break;
    case Mips::S1: OpKind = MCK_CPU16Regs; break;
    case Mips::S2: OpKind = MCK_DSPR; break;
    case Mips::S3: OpKind = MCK_DSPR; break;
    case Mips::S4: OpKind = MCK_DSPR; break;
    case Mips::S5: OpKind = MCK_DSPR; break;
    case Mips::S6: OpKind = MCK_DSPR; break;
    case Mips::S7: OpKind = MCK_DSPR; break;
    case Mips::T8: OpKind = MCK_DSPR; break;
    case Mips::T9: OpKind = MCK_DSPR; break;
    case Mips::K0: OpKind = MCK_DSPR; break;
    case Mips::K1: OpKind = MCK_DSPR; break;
    case Mips::GP: OpKind = MCK_DSPR; break;
    case Mips::SP: OpKind = MCK_CPUSPReg; break;
    case Mips::FP: OpKind = MCK_DSPR; break;
    case Mips::RA: OpKind = MCK_CPURAReg; break;
    case Mips::ZERO_64: OpKind = MCK_GPR64; break;
    case Mips::AT_64: OpKind = MCK_GPR64; break;
    case Mips::V0_64: OpKind = MCK_Reg7; break;
    case Mips::V1_64: OpKind = MCK_Reg7; break;
    case Mips::A0_64: OpKind = MCK_Reg7; break;
    case Mips::A1_64: OpKind = MCK_Reg7; break;
    case Mips::A2_64: OpKind = MCK_Reg7; break;
    case Mips::A3_64: OpKind = MCK_Reg7; break;
    case Mips::T0_64: OpKind = MCK_GPR64; break;
    case Mips::T1_64: OpKind = MCK_GPR64; break;
    case Mips::T2_64: OpKind = MCK_GPR64; break;
    case Mips::T3_64: OpKind = MCK_GPR64; break;
    case Mips::T4_64: OpKind = MCK_GPR64; break;
    case Mips::T5_64: OpKind = MCK_GPR64; break;
    case Mips::T6_64: OpKind = MCK_GPR64; break;
    case Mips::T7_64: OpKind = MCK_GPR64; break;
    case Mips::S0_64: OpKind = MCK_Reg7; break;
    case Mips::S1_64: OpKind = MCK_Reg7; break;
    case Mips::S2_64: OpKind = MCK_GPR64; break;
    case Mips::S3_64: OpKind = MCK_GPR64; break;
    case Mips::S4_64: OpKind = MCK_GPR64; break;
    case Mips::S5_64: OpKind = MCK_GPR64; break;
    case Mips::S6_64: OpKind = MCK_GPR64; break;
    case Mips::S7_64: OpKind = MCK_GPR64; break;
    case Mips::T8_64: OpKind = MCK_GPR64; break;
    case Mips::T9_64: OpKind = MCK_GPR64; break;
    case Mips::K0_64: OpKind = MCK_GPR64; break;
    case Mips::K1_64: OpKind = MCK_GPR64; break;
    case Mips::GP_64: OpKind = MCK_GPR64; break;
    case Mips::SP_64: OpKind = MCK_Reg9; break;
    case Mips::FP_64: OpKind = MCK_GPR64; break;
    case Mips::RA_64: OpKind = MCK_Reg10; break;
    case Mips::F0: OpKind = MCK_FGR32; break;
    case Mips::F1: OpKind = MCK_FGR32; break;
    case Mips::F2: OpKind = MCK_FGR32; break;
    case Mips::F3: OpKind = MCK_FGR32; break;
    case Mips::F4: OpKind = MCK_FGR32; break;
    case Mips::F5: OpKind = MCK_FGR32; break;
    case Mips::F6: OpKind = MCK_FGR32; break;
    case Mips::F7: OpKind = MCK_FGR32; break;
    case Mips::F8: OpKind = MCK_FGR32; break;
    case Mips::F9: OpKind = MCK_FGR32; break;
    case Mips::F10: OpKind = MCK_FGR32; break;
    case Mips::F11: OpKind = MCK_FGR32; break;
    case Mips::F12: OpKind = MCK_FGR32; break;
    case Mips::F13: OpKind = MCK_FGR32; break;
    case Mips::F14: OpKind = MCK_FGR32; break;
    case Mips::F15: OpKind = MCK_FGR32; break;
    case Mips::F16: OpKind = MCK_FGR32; break;
    case Mips::F17: OpKind = MCK_FGR32; break;
    case Mips::F18: OpKind = MCK_FGR32; break;
    case Mips::F19: OpKind = MCK_FGR32; break;
    case Mips::F20: OpKind = MCK_FGR32; break;
    case Mips::F21: OpKind = MCK_FGR32; break;
    case Mips::F22: OpKind = MCK_FGR32; break;
    case Mips::F23: OpKind = MCK_FGR32; break;
    case Mips::F24: OpKind = MCK_FGR32; break;
    case Mips::F25: OpKind = MCK_FGR32; break;
    case Mips::F26: OpKind = MCK_FGR32; break;
    case Mips::F27: OpKind = MCK_FGR32; break;
    case Mips::F28: OpKind = MCK_FGR32; break;
    case Mips::F29: OpKind = MCK_FGR32; break;
    case Mips::F30: OpKind = MCK_FGR32; break;
    case Mips::F31: OpKind = MCK_FGR32; break;
    case Mips::F_HI0: OpKind = MCK_FGRH32; break;
    case Mips::F_HI1: OpKind = MCK_FGRH32; break;
    case Mips::F_HI2: OpKind = MCK_FGRH32; break;
    case Mips::F_HI3: OpKind = MCK_FGRH32; break;
    case Mips::F_HI4: OpKind = MCK_FGRH32; break;
    case Mips::F_HI5: OpKind = MCK_FGRH32; break;
    case Mips::F_HI6: OpKind = MCK_FGRH32; break;
    case Mips::F_HI7: OpKind = MCK_FGRH32; break;
    case Mips::F_HI8: OpKind = MCK_FGRH32; break;
    case Mips::F_HI9: OpKind = MCK_FGRH32; break;
    case Mips::F_HI10: OpKind = MCK_FGRH32; break;
    case Mips::F_HI11: OpKind = MCK_FGRH32; break;
    case Mips::F_HI12: OpKind = MCK_FGRH32; break;
    case Mips::F_HI13: OpKind = MCK_FGRH32; break;
    case Mips::F_HI14: OpKind = MCK_FGRH32; break;
    case Mips::F_HI15: OpKind = MCK_FGRH32; break;
    case Mips::F_HI16: OpKind = MCK_FGRH32; break;
    case Mips::F_HI17: OpKind = MCK_FGRH32; break;
    case Mips::F_HI18: OpKind = MCK_FGRH32; break;
    case Mips::F_HI19: OpKind = MCK_FGRH32; break;
    case Mips::F_HI20: OpKind = MCK_FGRH32; break;
    case Mips::F_HI21: OpKind = MCK_FGRH32; break;
    case Mips::F_HI22: OpKind = MCK_FGRH32; break;
    case Mips::F_HI23: OpKind = MCK_FGRH32; break;
    case Mips::F_HI24: OpKind = MCK_FGRH32; break;
    case Mips::F_HI25: OpKind = MCK_FGRH32; break;
    case Mips::F_HI26: OpKind = MCK_FGRH32; break;
    case Mips::F_HI27: OpKind = MCK_FGRH32; break;
    case Mips::F_HI28: OpKind = MCK_FGRH32; break;
    case Mips::F_HI29: OpKind = MCK_FGRH32; break;
    case Mips::F_HI30: OpKind = MCK_FGRH32; break;
    case Mips::F_HI31: OpKind = MCK_FGRH32; break;
    case Mips::D0: OpKind = MCK_AFGR64; break;
    case Mips::D1: OpKind = MCK_AFGR64; break;
    case Mips::D2: OpKind = MCK_AFGR64; break;
    case Mips::D3: OpKind = MCK_AFGR64; break;
    case Mips::D4: OpKind = MCK_AFGR64; break;
    case Mips::D5: OpKind = MCK_AFGR64; break;
    case Mips::D6: OpKind = MCK_AFGR64; break;
    case Mips::D7: OpKind = MCK_AFGR64; break;
    case Mips::D8: OpKind = MCK_AFGR64; break;
    case Mips::D9: OpKind = MCK_AFGR64; break;
    case Mips::D10: OpKind = MCK_AFGR64; break;
    case Mips::D11: OpKind = MCK_AFGR64; break;
    case Mips::D12: OpKind = MCK_AFGR64; break;
    case Mips::D13: OpKind = MCK_AFGR64; break;
    case Mips::D14: OpKind = MCK_AFGR64; break;
    case Mips::D15: OpKind = MCK_AFGR64; break;
    case Mips::D0_64: OpKind = MCK_FGR64; break;
    case Mips::D1_64: OpKind = MCK_FGR64; break;
    case Mips::D2_64: OpKind = MCK_FGR64; break;
    case Mips::D3_64: OpKind = MCK_FGR64; break;
    case Mips::D4_64: OpKind = MCK_FGR64; break;
    case Mips::D5_64: OpKind = MCK_FGR64; break;
    case Mips::D6_64: OpKind = MCK_FGR64; break;
    case Mips::D7_64: OpKind = MCK_FGR64; break;
    case Mips::D8_64: OpKind = MCK_FGR64; break;
    case Mips::D9_64: OpKind = MCK_FGR64; break;
    case Mips::D10_64: OpKind = MCK_FGR64; break;
    case Mips::D11_64: OpKind = MCK_FGR64; break;
    case Mips::D12_64: OpKind = MCK_FGR64; break;
    case Mips::D13_64: OpKind = MCK_FGR64; break;
    case Mips::D14_64: OpKind = MCK_FGR64; break;
    case Mips::D15_64: OpKind = MCK_FGR64; break;
    case Mips::D16_64: OpKind = MCK_FGR64; break;
    case Mips::D17_64: OpKind = MCK_FGR64; break;
    case Mips::D18_64: OpKind = MCK_FGR64; break;
    case Mips::D19_64: OpKind = MCK_FGR64; break;
    case Mips::D20_64: OpKind = MCK_FGR64; break;
    case Mips::D21_64: OpKind = MCK_FGR64; break;
    case Mips::D22_64: OpKind = MCK_FGR64; break;
    case Mips::D23_64: OpKind = MCK_FGR64; break;
    case Mips::D24_64: OpKind = MCK_FGR64; break;
    case Mips::D25_64: OpKind = MCK_FGR64; break;
    case Mips::D26_64: OpKind = MCK_FGR64; break;
    case Mips::D27_64: OpKind = MCK_FGR64; break;
    case Mips::D28_64: OpKind = MCK_FGR64; break;
    case Mips::D29_64: OpKind = MCK_FGR64; break;
    case Mips::D30_64: OpKind = MCK_FGR64; break;
    case Mips::D31_64: OpKind = MCK_FGR64; break;
    case Mips::W0: OpKind = MCK_MSA128B; break;
    case Mips::W1: OpKind = MCK_MSA128B; break;
    case Mips::W2: OpKind = MCK_MSA128B; break;
    case Mips::W3: OpKind = MCK_MSA128B; break;
    case Mips::W4: OpKind = MCK_MSA128B; break;
    case Mips::W5: OpKind = MCK_MSA128B; break;
    case Mips::W6: OpKind = MCK_MSA128B; break;
    case Mips::W7: OpKind = MCK_MSA128B; break;
    case Mips::W8: OpKind = MCK_MSA128B; break;
    case Mips::W9: OpKind = MCK_MSA128B; break;
    case Mips::W10: OpKind = MCK_MSA128B; break;
    case Mips::W11: OpKind = MCK_MSA128B; break;
    case Mips::W12: OpKind = MCK_MSA128B; break;
    case Mips::W13: OpKind = MCK_MSA128B; break;
    case Mips::W14: OpKind = MCK_MSA128B; break;
    case Mips::W15: OpKind = MCK_MSA128B; break;
    case Mips::W16: OpKind = MCK_MSA128B; break;
    case Mips::W17: OpKind = MCK_MSA128B; break;
    case Mips::W18: OpKind = MCK_MSA128B; break;
    case Mips::W19: OpKind = MCK_MSA128B; break;
    case Mips::W20: OpKind = MCK_MSA128B; break;
    case Mips::W21: OpKind = MCK_MSA128B; break;
    case Mips::W22: OpKind = MCK_MSA128B; break;
    case Mips::W23: OpKind = MCK_MSA128B; break;
    case Mips::W24: OpKind = MCK_MSA128B; break;
    case Mips::W25: OpKind = MCK_MSA128B; break;
    case Mips::W26: OpKind = MCK_MSA128B; break;
    case Mips::W27: OpKind = MCK_MSA128B; break;
    case Mips::W28: OpKind = MCK_MSA128B; break;
    case Mips::W29: OpKind = MCK_MSA128B; break;
    case Mips::W30: OpKind = MCK_MSA128B; break;
    case Mips::W31: OpKind = MCK_MSA128B; break;
    case Mips::HI0: OpKind = MCK_HI32; break;
    case Mips::HI1: OpKind = MCK_HI32DSP; break;
    case Mips::HI2: OpKind = MCK_HI32DSP; break;
    case Mips::HI3: OpKind = MCK_HI32DSP; break;
    case Mips::LO0: OpKind = MCK_LO32; break;
    case Mips::LO1: OpKind = MCK_LO32DSP; break;
    case Mips::LO2: OpKind = MCK_LO32DSP; break;
    case Mips::LO3: OpKind = MCK_LO32DSP; break;
    case Mips::HI0_64: OpKind = MCK_HI64; break;
    case Mips::LO0_64: OpKind = MCK_LO64; break;
    case Mips::FCR0: OpKind = MCK_CCR; break;
    case Mips::FCR1: OpKind = MCK_CCR; break;
    case Mips::FCR2: OpKind = MCK_CCR; break;
    case Mips::FCR3: OpKind = MCK_CCR; break;
    case Mips::FCR4: OpKind = MCK_CCR; break;
    case Mips::FCR5: OpKind = MCK_CCR; break;
    case Mips::FCR6: OpKind = MCK_CCR; break;
    case Mips::FCR7: OpKind = MCK_CCR; break;
    case Mips::FCR8: OpKind = MCK_CCR; break;
    case Mips::FCR9: OpKind = MCK_CCR; break;
    case Mips::FCR10: OpKind = MCK_CCR; break;
    case Mips::FCR11: OpKind = MCK_CCR; break;
    case Mips::FCR12: OpKind = MCK_CCR; break;
    case Mips::FCR13: OpKind = MCK_CCR; break;
    case Mips::FCR14: OpKind = MCK_CCR; break;
    case Mips::FCR15: OpKind = MCK_CCR; break;
    case Mips::FCR16: OpKind = MCK_CCR; break;
    case Mips::FCR17: OpKind = MCK_CCR; break;
    case Mips::FCR18: OpKind = MCK_CCR; break;
    case Mips::FCR19: OpKind = MCK_CCR; break;
    case Mips::FCR20: OpKind = MCK_CCR; break;
    case Mips::FCR21: OpKind = MCK_CCR; break;
    case Mips::FCR22: OpKind = MCK_CCR; break;
    case Mips::FCR23: OpKind = MCK_CCR; break;
    case Mips::FCR24: OpKind = MCK_CCR; break;
    case Mips::FCR25: OpKind = MCK_CCR; break;
    case Mips::FCR26: OpKind = MCK_CCR; break;
    case Mips::FCR27: OpKind = MCK_CCR; break;
    case Mips::FCR28: OpKind = MCK_CCR; break;
    case Mips::FCR29: OpKind = MCK_CCR; break;
    case Mips::FCR30: OpKind = MCK_CCR; break;
    case Mips::FCR31: OpKind = MCK_CCR; break;
    case Mips::FCC0: OpKind = MCK_FCC; break;
    case Mips::FCC1: OpKind = MCK_FCC; break;
    case Mips::FCC2: OpKind = MCK_FCC; break;
    case Mips::FCC3: OpKind = MCK_FCC; break;
    case Mips::FCC4: OpKind = MCK_FCC; break;
    case Mips::FCC5: OpKind = MCK_FCC; break;
    case Mips::FCC6: OpKind = MCK_FCC; break;
    case Mips::FCC7: OpKind = MCK_FCC; break;
    case Mips::COP20: OpKind = MCK_COP2; break;
    case Mips::COP21: OpKind = MCK_COP2; break;
    case Mips::COP22: OpKind = MCK_COP2; break;
    case Mips::COP23: OpKind = MCK_COP2; break;
    case Mips::COP24: OpKind = MCK_COP2; break;
    case Mips::COP25: OpKind = MCK_COP2; break;
    case Mips::COP26: OpKind = MCK_COP2; break;
    case Mips::COP27: OpKind = MCK_COP2; break;
    case Mips::COP28: OpKind = MCK_COP2; break;
    case Mips::COP29: OpKind = MCK_COP2; break;
    case Mips::COP210: OpKind = MCK_COP2; break;
    case Mips::COP211: OpKind = MCK_COP2; break;
    case Mips::COP212: OpKind = MCK_COP2; break;
    case Mips::COP213: OpKind = MCK_COP2; break;
    case Mips::COP214: OpKind = MCK_COP2; break;
    case Mips::COP215: OpKind = MCK_COP2; break;
    case Mips::COP216: OpKind = MCK_COP2; break;
    case Mips::COP217: OpKind = MCK_COP2; break;
    case Mips::COP218: OpKind = MCK_COP2; break;
    case Mips::COP219: OpKind = MCK_COP2; break;
    case Mips::COP220: OpKind = MCK_COP2; break;
    case Mips::COP221: OpKind = MCK_COP2; break;
    case Mips::COP222: OpKind = MCK_COP2; break;
    case Mips::COP223: OpKind = MCK_COP2; break;
    case Mips::COP224: OpKind = MCK_COP2; break;
    case Mips::COP225: OpKind = MCK_COP2; break;
    case Mips::COP226: OpKind = MCK_COP2; break;
    case Mips::COP227: OpKind = MCK_COP2; break;
    case Mips::COP228: OpKind = MCK_COP2; break;
    case Mips::COP229: OpKind = MCK_COP2; break;
    case Mips::COP230: OpKind = MCK_COP2; break;
    case Mips::COP231: OpKind = MCK_COP2; break;
    case Mips::PC: OpKind = MCK_PC; break;
    case Mips::HWR29: OpKind = MCK_HWRegs; break;
    case Mips::AC0: OpKind = MCK_ACC64; break;
    case Mips::AC1: OpKind = MCK_ACC64DSP; break;
    case Mips::AC2: OpKind = MCK_ACC64DSP; break;
    case Mips::AC3: OpKind = MCK_ACC64DSP; break;
    case Mips::AC0_64: OpKind = MCK_ACC128; break;
    case Mips::DSPCCond: OpKind = MCK_DSPCC; break;
    case Mips::MSAIR: OpKind = MCK_MSACtrl; break;
    case Mips::MSACSR: OpKind = MCK_MSACtrl; break;
    case Mips::MSAAccess: OpKind = MCK_MSACtrl; break;
    case Mips::MSASave: OpKind = MCK_MSACtrl; break;
    case Mips::MSAModify: OpKind = MCK_MSACtrl; break;
    case Mips::MSARequest: OpKind = MCK_MSACtrl; break;
    case Mips::MSAMap: OpKind = MCK_MSACtrl; break;
    case Mips::MSAUnmap: OpKind = MCK_MSACtrl; break;
    }
    return isSubclass(OpKind, Kind) ? MCTargetAsmParser::Match_Success :
                                      MCTargetAsmParser::Match_InvalidOperand;
  }

  return MCTargetAsmParser::Match_InvalidOperand;
}

unsigned MipsAsmParser::
ComputeAvailableFeatures(uint64_t FB) const {
  unsigned Features = 0;
  if (((FB & Mips::FeatureSEInReg) != 0))
    Features |= Feature_HasSEInReg;
  if (((FB & Mips::FeatureBitCount) != 0))
    Features |= Feature_HasBitCount;
  if (((FB & Mips::FeatureSwap) != 0))
    Features |= Feature_HasSwap;
  if (((FB & Mips::FeatureCondMov) != 0))
    Features |= Feature_HasCondMov;
  if (((FB & Mips::FeatureFPIdx) != 0))
    Features |= Feature_HasFPIdx;
  if (((FB & Mips::FeatureMips32) != 0))
    Features |= Feature_HasMips32;
  if (((FB & Mips::FeatureMips32r2) != 0))
    Features |= Feature_HasMips32r2;
  if (((FB & Mips::FeatureMips64) != 0))
    Features |= Feature_HasMips64;
  if (((FB & Mips::FeatureMips64) == 0))
    Features |= Feature_NotMips64;
  if (((FB & Mips::FeatureMips64r2) != 0))
    Features |= Feature_HasMips64r2;
  if (((FB & Mips::FeatureN64) != 0))
    Features |= Feature_IsN64;
  if (((FB & Mips::FeatureN64) == 0))
    Features |= Feature_NotN64;
  if (((FB & Mips::FeatureMips16) != 0))
    Features |= Feature_InMips16Mode;
  if (((FB & Mips::FeatureMips32) != 0))
    Features |= Feature_RelocStatic;
  if (((FB & Mips::FeatureMips32) != 0))
    Features |= Feature_RelocPIC;
  if (((FB & Mips::FeatureMips32) != 0))
    Features |= Feature_NoNaNsFPMath;
  if (((FB & Mips::FeatureMips16) == 0))
    Features |= Feature_HasStdEnc;
  if (((FB & Mips::FeatureMicroMips) != 0))
    Features |= Feature_InMicroMips;
  if (((FB & Mips::FeatureMicroMips) == 0))
    Features |= Feature_NotInMicroMips;
  if (((FB & Mips::FeatureFP64Bit) != 0))
    Features |= Feature_IsFP64bit;
  if (((FB & Mips::FeatureFP64Bit) == 0))
    Features |= Feature_NotFP64bit;
  if (((FB & Mips::FeatureSingleFloat) != 0))
    Features |= Feature_IsSingleFloat;
  if (((FB & Mips::FeatureSingleFloat) == 0))
    Features |= Feature_IsNotSingleFloat;
  if (((FB & Mips::FeatureDSP) != 0))
    Features |= Feature_HasDSP;
  if (((FB & Mips::FeatureDSPR2) != 0))
    Features |= Feature_HasDSPR2;
  if (((FB & Mips::FeatureMSA) != 0))
    Features |= Feature_HasMSA;
  return Features;
}

static const char *const MnemonicTable =
    "\005abs.d\005abs.s\tabsq_s.ph\tabsq_s.qb\010absq_s.w\003add\005add.d\005"
    "add.s\007add_a.b\007add_a.d\007add_a.h\007add_a.w\004addi\005addiu\007a"
    "ddq.ph\taddq_s.ph\010addq_s.w\010addqh.ph\007addqh.w\naddqh_r.ph\taddqh"
    "_r.w\010adds_a.b\010adds_a.d\010adds_a.h\010adds_a.w\010adds_s.b\010add"
    "s_s.d\010adds_s.h\010adds_s.w\010adds_u.b\010adds_u.d\010adds_u.h\010ad"
    "ds_u.w\005addsc\004addu\007addu.ph\007addu.qb\taddu_s.ph\taddu_s.qb\010"
    "adduh.qb\nadduh_r.qb\006addv.b\006addv.d\006addv.h\006addv.w\007addvi.b"
    "\007addvi.d\007addvi.h\007addvi.w\005addwc\003and\005and.v\004andi\006a"
    "ndi.b\006append\010asub_s.b\010asub_s.d\010asub_s.h\010asub_s.w\010asub"
    "_u.b\010asub_u.d\010asub_u.h\010asub_u.w\007ave_s.b\007ave_s.d\007ave_s"
    ".h\007ave_s.w\007ave_u.b\007ave_u.d\007ave_u.h\007ave_u.w\010aver_s.b\010"
    "aver_s.d\010aver_s.h\010aver_s.w\010aver_u.b\010aver_u.d\010aver_u.h\010"
    "aver_u.w\001b\003bal\006balign\004bc1f\004bc1t\006bclr.b\006bclr.d\006b"
    "clr.h\006bclr.w\007bclri.b\007bclri.d\007bclri.h\007bclri.w\003beq\004b"
    "eqz\004bgez\006bgezal\004bgtz\007binsl.b\007binsl.d\007binsl.h\007binsl"
    ".w\010binsli.b\010binsli.d\010binsli.h\010binsli.w\007binsr.b\007binsr."
    "d\007binsr.h\007binsr.w\010binsri.b\010binsri.d\010binsri.h\010binsri.w"
    "\006bitrev\004blez\004bltz\006bltzal\006bmnz.v\007bmnzi.b\005bmz.v\006b"
    "mzi.b\003bne\006bneg.b\006bneg.d\006bneg.h\006bneg.w\007bnegi.b\007bneg"
    "i.d\007bnegi.h\007bnegi.w\004bnez\005bnz.b\005bnz.d\005bnz.h\005bnz.v\005"
    "bnz.w\010bposge32\005break\006bsel.v\007bseli.b\006bset.b\006bset.d\006"
    "bset.h\006bset.w\007bseti.b\007bseti.d\007bseti.h\007bseti.w\005bteqz\005"
    "btnez\004bz.b\004bz.d\004bz.h\004bz.v\004bz.w\006c.eq.d\006c.eq.s\005c."
    "f.d\005c.f.s\006c.le.d\006c.le.s\006c.lt.d\006c.lt.s\007c.nge.d\007c.ng"
    "e.s\007c.ngl.d\007c.ngl.s\010c.ngle.d\010c.ngle.s\007c.ngt.d\007c.ngt.s"
    "\007c.ole.d\007c.ole.s\007c.olt.d\007c.olt.s\007c.seq.d\007c.seq.s\006c"
    ".sf.d\006c.sf.s\007c.ueq.d\007c.ueq.s\007c.ule.d\007c.ule.s\007c.ult.d\007"
    "c.ult.s\006c.un.d\006c.un.s\010ceil.l.d\010ceil.l.s\010ceil.w.d\010ceil"
    ".w.s\005ceq.b\005ceq.d\005ceq.h\005ceq.w\006ceqi.b\006ceqi.d\006ceqi.h\006"
    "ceqi.w\004cfc1\006cfcmsa\007cle_s.b\007cle_s.d\007cle_s.h\007cle_s.w\007"
    "cle_u.b\007cle_u.d\007cle_u.h\007cle_u.w\010clei_s.b\010clei_s.d\010cle"
    "i_s.h\010clei_s.w\010clei_u.b\010clei_u.d\010clei_u.h\010clei_u.w\003cl"
    "o\007clt_s.b\007clt_s.d\007clt_s.h\007clt_s.w\007clt_u.b\007clt_u.d\007"
    "clt_u.h\007clt_u.w\010clti_s.b\010clti_s.d\010clti_s.h\010clti_s.w\010c"
    "lti_u.b\010clti_u.d\010clti_u.h\010clti_u.w\003clz\003cmp\tcmp.eq.ph\tc"
    "mp.le.ph\tcmp.lt.ph\014cmpgdu.eq.qb\014cmpgdu.le.qb\014cmpgdu.lt.qb\013"
    "cmpgu.eq.qb\013cmpgu.le.qb\013cmpgu.lt.qb\004cmpi\ncmpu.eq.qb\ncmpu.le."
    "qb\ncmpu.lt.qb\010copy_s.b\010copy_s.h\010copy_s.w\010copy_u.b\010copy_"
    "u.h\010copy_u.w\004ctc1\006ctcmsa\007cvt.d.l\007cvt.d.s\007cvt.d.w\007c"
    "vt.l.d\007cvt.l.s\007cvt.s.d\007cvt.s.l\007cvt.s.w\007cvt.w.d\007cvt.w."
    "s\004dadd\005daddi\006daddiu\005daddu\004dclo\004dclz\004ddiv\005ddivu\005"
    "deret\004dext\005dextm\005dextu\002di\004dins\005dinsm\005dinsu\003div\005"
    "div.d\005div.s\007div_s.b\007div_s.d\007div_s.h\007div_s.w\007div_u.b\007"
    "div_u.d\007div_u.h\007div_u.w\004divu\005dmfc0\005dmfc1\005dmfc2\005dmt"
    "c0\005dmtc1\005dmtc2\005dmult\006dmultu\010dotp_s.d\010dotp_s.h\010dotp"
    "_s.w\010dotp_u.d\010dotp_u.h\010dotp_u.w\010dpa.w.ph\tdpadd_s.d\tdpadd_"
    "s.h\tdpadd_s.w\tdpadd_u.d\tdpadd_u.h\tdpadd_u.w\013dpaq_s.w.ph\013dpaq_"
    "sa.l.w\014dpaqx_s.w.ph\015dpaqx_sa.w.ph\ndpau.h.qbl\ndpau.h.qbr\tdpax.w"
    ".ph\010dps.w.ph\013dpsq_s.w.ph\013dpsq_sa.l.w\014dpsqx_s.w.ph\015dpsqx_"
    "sa.w.ph\ndpsu.h.qbl\ndpsu.h.qbr\tdpsub_s.d\tdpsub_s.h\tdpsub_s.w\tdpsub"
    "_u.d\tdpsub_u.h\tdpsub_u.w\tdpsx.w.ph\005drotr\007drotr32\006drotrv\004"
    "dsbh\004dshd\004dsll\006dsll32\005dsllv\004dsra\006dsra32\005dsrav\004d"
    "srl\006dsrl32\005dsrlv\005dsubu\002ei\004eret\003ext\004extp\006extpdp\007"
    "extpdpv\005extpv\006extr.w\010extr_r.w\textr_rs.w\010extr_s.h\007extrv."
    "w\textrv_r.w\nextrv_rs.w\textrv_s.h\006fadd.d\006fadd.w\006fcaf.d\006fc"
    "af.w\006fceq.d\006fceq.w\010fclass.d\010fclass.w\006fcle.d\006fcle.w\006"
    "fclt.d\006fclt.w\006fcne.d\006fcne.w\006fcor.d\006fcor.w\007fcueq.d\007"
    "fcueq.w\007fcule.d\007fcule.w\007fcult.d\007fcult.w\006fcun.d\006fcun.w"
    "\007fcune.d\007fcune.w\006fdiv.d\006fdiv.w\007fexdo.h\007fexdo.w\007fex"
    "p2.d\007fexp2.w\010fexupl.d\010fexupl.w\010fexupr.d\010fexupr.w\tffint_"
    "s.d\tffint_s.w\tffint_u.d\tffint_u.w\006ffql.d\006ffql.w\006ffqr.d\006f"
    "fqr.w\006fill.b\006fill.h\006fill.w\007flog2.d\007flog2.w\tfloor.l.d\tf"
    "loor.l.s\tfloor.w.d\tfloor.w.s\007fmadd.d\007fmadd.w\006fmax.d\006fmax."
    "w\010fmax_a.d\010fmax_a.w\006fmin.d\006fmin.w\010fmin_a.d\010fmin_a.w\007"
    "fmsub.d\007fmsub.w\006fmul.d\006fmul.w\006frcp.d\006frcp.w\007frint.d\007"
    "frint.w\010frsqrt.d\010frsqrt.w\006fsaf.d\006fsaf.w\006fseq.d\006fseq.w"
    "\006fsle.d\006fsle.w\006fslt.d\006fslt.w\006fsne.d\006fsne.w\006fsor.d\006"
    "fsor.w\007fsqrt.d\007fsqrt.w\006fsub.d\006fsub.w\007fsueq.d\007fsueq.w\007"
    "fsule.d\007fsule.w\007fsult.d\007fsult.w\006fsun.d\006fsun.w\007fsune.d"
    "\007fsune.w\tftint_s.d\tftint_s.w\tftint_u.d\tftint_u.w\005ftq.h\005ftq"
    ".w\nftrunc_s.d\nftrunc_s.w\nftrunc_u.d\nftrunc_u.w\010hadd_s.d\010hadd_"
    "s.h\010hadd_s.w\010hadd_u.d\010hadd_u.h\010hadd_u.w\010hsub_s.d\010hsub"
    "_s.h\010hsub_s.w\010hsub_u.d\010hsub_u.h\010hsub_u.w\007ilvev.b\007ilve"
    "v.d\007ilvev.h\007ilvev.w\006ilvl.b\006ilvl.d\006ilvl.h\006ilvl.w\007il"
    "vod.b\007ilvod.d\007ilvod.h\007ilvod.w\006ilvr.b\006ilvr.d\006ilvr.h\006"
    "ilvr.w\003ins\010insert.b\010insert.h\010insert.w\004insv\007insve.b\007"
    "insve.d\007insve.h\007insve.w\001j\003jal\004jalr\005jalrc\002jr\003jrc"
    "\002la\002lb\003lbu\004lbux\002ld\004ld.b\004ld.d\004ld.h\004ld.w\004ld"
    "c1\004ldc2\005ldi.b\005ldi.d\005ldi.h\005ldi.w\003ldl\003ldr\005ldxc1\002"
    "lh\003lhu\003lhx\002li\002ll\003lld\003lsa\003lui\005luxc1\002lw\004lwc"
    "1\004lwc2\003lwl\003lwr\003lwu\003lwx\005lwxc1\004madd\006madd.d\006mad"
    "d.s\010madd_q.h\010madd_q.w\tmaddr_q.h\tmaddr_q.w\005maddu\007maddv.b\007"
    "maddv.d\007maddv.h\007maddv.w\013maq_s.w.phl\013maq_s.w.phr\014maq_sa.w"
    ".phl\014maq_sa.w.phr\007max_a.b\007max_a.d\007max_a.h\007max_a.w\007max"
    "_s.b\007max_s.d\007max_s.h\007max_s.w\007max_u.b\007max_u.d\007max_u.h\007"
    "max_u.w\010maxi_s.b\010maxi_s.d\010maxi_s.h\010maxi_s.w\010maxi_u.b\010"
    "maxi_u.d\010maxi_u.h\010maxi_u.w\004mfc0\004mfc1\004mfc2\005mfhc1\004mf"
    "hi\004mflo\007min_a.b\007min_a.d\007min_a.h\007min_a.w\007min_s.b\007mi"
    "n_s.d\007min_s.h\007min_s.w\007min_u.b\007min_u.d\007min_u.h\007min_u.w"
    "\010mini_s.b\010mini_s.d\010mini_s.h\010mini_s.w\010mini_u.b\010mini_u."
    "d\010mini_u.h\010mini_u.w\007mod_s.b\007mod_s.d\007mod_s.h\007mod_s.w\007"
    "mod_u.b\007mod_u.d\007mod_u.h\007mod_u.w\006modsub\005mov.d\005mov.s\004"
    "move\006move.v\004movf\006movf.d\006movf.s\004movn\006movn.d\006movn.s\004"
    "movt\006movt.d\006movt.s\004movz\006movz.d\006movz.s\004msub\006msub.d\006"
    "msub.s\010msub_q.h\010msub_q.w\tmsubr_q.h\tmsubr_q.w\005msubu\007msubv."
    "b\007msubv.d\007msubv.h\007msubv.w\004mtc0\004mtc1\004mtc2\005mthc1\004"
    "mthi\006mthlip\004mtlo\003mul\005mul.d\006mul.ph\005mul.s\007mul_q.h\007"
    "mul_q.w\010mul_s.ph\015muleq_s.w.phl\015muleq_s.w.phr\016muleu_s.ph.qbl"
    "\016muleu_s.ph.qbr\nmulq_rs.ph\tmulq_rs.w\tmulq_s.ph\010mulq_s.w\010mul"
    "r_q.h\010mulr_q.w\nmulsa.w.ph\015mulsaq_s.w.ph\004mult\005multu\006mulv"
    ".b\006mulv.d\006mulv.h\006mulv.w\003neg\005neg.d\005neg.s\004negu\006nl"
    "oc.b\006nloc.d\006nloc.h\006nloc.w\006nlzc.b\006nlzc.d\006nlzc.h\006nlz"
    "c.w\007nmadd.d\007nmadd.s\007nmsub.d\007nmsub.s\003nop\003nor\005nor.v\006"
    "nori.b\003not\002or\004or.v\003ori\005ori.b\tpackrl.ph\007pckev.b\007pc"
    "kev.d\007pckev.h\007pckev.w\007pckod.b\007pckod.d\007pckod.h\007pckod.w"
    "\006pcnt.b\006pcnt.d\006pcnt.h\006pcnt.w\007pick.ph\007pick.qb\014prece"
    "q.w.phl\014preceq.w.phr\016precequ.ph.qbl\017precequ.ph.qbla\016precequ"
    ".ph.qbr\017precequ.ph.qbra\015preceu.ph.qbl\016preceu.ph.qbla\015preceu"
    ".ph.qbr\016preceu.ph.qbra\013precr.qb.ph\016precr_sra.ph.w\020precr_sra"
    "_r.ph.w\013precrq.ph.w\014precrq.qb.ph\016precrq_rs.ph.w\017precrqu_s.q"
    "b.ph\007prepend\nraddu.w.qb\005rddsp\005rdhwr\007repl.ph\007repl.qb\010"
    "replv.ph\010replv.qb\004rotr\005rotrv\tround.l.d\tround.l.s\tround.w.d\t"
    "round.w.s\007sat_s.b\007sat_s.d\007sat_s.h\007sat_s.w\007sat_u.b\007sat"
    "_u.d\007sat_u.h\007sat_u.w\002sb\002sc\003scd\002sd\004sdc1\004sdc2\003"
    "sdl\003sdr\005sdxc1\003seb\003seh\002sh\005shf.b\005shf.h\005shf.w\005s"
    "hilo\006shilov\007shll.ph\007shll.qb\tshll_s.ph\010shll_s.w\010shllv.ph"
    "\010shllv.qb\nshllv_s.ph\tshllv_s.w\007shra.ph\007shra.qb\tshra_r.ph\ts"
    "hra_r.qb\010shra_r.w\010shrav.ph\010shrav.qb\nshrav_r.ph\nshrav_r.qb\ts"
    "hrav_r.w\007shrl.ph\007shrl.qb\010shrlv.ph\010shrlv.qb\005sld.b\005sld."
    "d\005sld.h\005sld.w\006sldi.b\006sldi.d\006sldi.h\006sldi.w\003sll\005s"
    "ll.b\005sll.d\005sll.h\005sll.w\006slli.b\006slli.d\006slli.h\006slli.w"
    "\004sllv\003slt\004slti\005sltiu\004sltu\007splat.b\007splat.d\007splat"
    ".h\007splat.w\010splati.b\010splati.d\010splati.h\010splati.w\006sqrt.d"
    "\006sqrt.s\003sra\005sra.b\005sra.d\005sra.h\005sra.w\006srai.b\006srai"
    ".d\006srai.h\006srai.w\006srar.b\006srar.d\006srar.h\006srar.w\007srari"
    ".b\007srari.d\007srari.h\007srari.w\004srav\003srl\005srl.b\005srl.d\005"
    "srl.h\005srl.w\006srli.b\006srli.d\006srli.h\006srli.w\006srlr.b\006srl"
    "r.d\006srlr.h\006srlr.w\007srlri.b\007srlri.d\007srlri.h\007srlri.w\004"
    "srlv\004st.b\004st.d\004st.h\004st.w\003sub\005sub.d\005sub.s\007subq.p"
    "h\tsubq_s.ph\010subq_s.w\010subqh.ph\007subqh.w\nsubqh_r.ph\tsubqh_r.w\010"
    "subs_s.b\010subs_s.d\010subs_s.h\010subs_s.w\010subs_u.b\010subs_u.d\010"
    "subs_u.h\010subs_u.w\nsubsus_u.b\nsubsus_u.d\nsubsus_u.h\nsubsus_u.w\ns"
    "ubsuu_s.b\nsubsuu_s.d\nsubsuu_s.h\nsubsuu_s.w\004subu\007subu.ph\007sub"
    "u.qb\tsubu_s.ph\tsubu_s.qb\010subuh.qb\nsubuh_r.qb\006subv.b\006subv.d\006"
    "subv.h\006subv.w\007subvi.b\007subvi.d\007subvi.h\007subvi.w\005suxc1\002"
    "sw\004swc1\004swc2\003swl\003swr\005swxc1\004sync\007syscall\003teq\004"
    "teqi\003tge\004tgei\005tgeiu\004tgeu\003tlt\004tlti\005tltiu\004tltu\003"
    "tne\004tnei\ttrunc.l.d\ttrunc.l.s\ttrunc.w.d\ttrunc.w.s\006vshf.b\006vs"
    "hf.d\006vshf.h\006vshf.w\004wait\005wrdsp\004wsbh\003xor\005xor.v\004xo"
    "ri\006xori.b";

namespace {
  struct MatchEntry {
    uint16_t Mnemonic;
    uint16_t Opcode;
    uint16_t ConvertFn;
    uint32_t RequiredFeatures;
    uint8_t Classes[8];
    StringRef getMnemonic() const {
      return StringRef(MnemonicTable + Mnemonic + 1,
                       MnemonicTable[Mnemonic]);
    }
  };

  // Predicate for searching for an opcode.
  struct LessOpcode {
    bool operator()(const MatchEntry &LHS, StringRef RHS) {
      return LHS.getMnemonic() < RHS;
    }
    bool operator()(StringRef LHS, const MatchEntry &RHS) {
      return LHS < RHS.getMnemonic();
    }
    bool operator()(const MatchEntry &LHS, const MatchEntry &RHS) {
      return LHS.getMnemonic() < RHS.getMnemonic();
    }
  };
} // end anonymous namespace.

static const MatchEntry MatchTable0[] = {
  { 0 /* abs.d */, Mips::FABS_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 0 /* abs.d */, Mips::FABS_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 6 /* abs.s */, Mips::FABS_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 12 /* absq_s.ph */, Mips::ABSQ_S_PH, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 22 /* absq_s.qb */, Mips::ABSQ_S_QB, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 32 /* absq_s.w */, Mips::ABSQ_S_W, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 41 /* add */, Mips::ADD, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 41 /* add */, Mips::ADD_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 41 /* add */, Mips::ADDi, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, 0, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 45 /* add.d */, Mips::FADD_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1__AFGR64Asm1_2, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 45 /* add.d */, Mips::FADD_D64, Convert__FGR64Asm1_0__FGR64Asm1_1__FGR64Asm1_2, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 51 /* add.s */, Mips::FADD_S, Convert__FGR32Asm1_0__FGR32Asm1_1__FGR32Asm1_2, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 57 /* add_a.b */, Mips::ADD_A_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 65 /* add_a.d */, Mips::ADD_A_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 73 /* add_a.h */, Mips::ADD_A_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 81 /* add_a.w */, Mips::ADD_A_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 89 /* addi */, Mips::ADDi, Convert__GPR32Asm1_0__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 89 /* addi */, Mips::ADDi_MM, Convert__GPR32Asm1_0__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 89 /* addi */, Mips::ADDi, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 89 /* addi */, Mips::ADDi_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 94 /* addiu */, Mips::AddiuRxImmX16, Convert__Reg1_0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm }, },
  { 94 /* addiu */, Mips::AddiuSpImmX16, Convert__Imm1_1, Feature_InMips16Mode, { MCK_CPUSPReg, MCK_Imm }, },
  { 94 /* addiu */, Mips::ADDiu, Convert__GPR32Asm1_0__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 94 /* addiu */, Mips::ADDiu_MM, Convert__GPR32Asm1_0__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 94 /* addiu */, Mips::AddiuRxRyOffMemX16, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16RegsPlusSP, MCK_Imm }, },
  { 94 /* addiu */, Mips::AddiuRxPcImmX16, Convert__Reg1_0__Imm1_2, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_PC, MCK_Imm }, },
  { 94 /* addiu */, Mips::ADDiu, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 94 /* addiu */, Mips::ADDiu_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 94 /* addiu */, Mips::AddiuRxRxImm16, Convert__Reg1_0__Tie0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm, MCK__35_, MCK_16, MCK_bit, MCK_inst }, },
  { 94 /* addiu */, Mips::AddiuSpImm16, Convert__Imm1_1, Feature_InMips16Mode, { MCK_CPUSPReg, MCK_Imm, MCK__35_, MCK_16, MCK_bit, MCK_inst }, },
  { 100 /* addq.ph */, Mips::ADDQ_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 108 /* addq_s.ph */, Mips::ADDQ_S_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 118 /* addq_s.w */, Mips::ADDQ_S_W, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 127 /* addqh.ph */, Mips::ADDQH_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 136 /* addqh.w */, Mips::ADDQH_W, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 144 /* addqh_r.ph */, Mips::ADDQH_R_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 155 /* addqh_r.w */, Mips::ADDQH_R_W, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 165 /* adds_a.b */, Mips::ADDS_A_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 174 /* adds_a.d */, Mips::ADDS_A_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 183 /* adds_a.h */, Mips::ADDS_A_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 192 /* adds_a.w */, Mips::ADDS_A_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 201 /* adds_s.b */, Mips::ADDS_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 210 /* adds_s.d */, Mips::ADDS_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 219 /* adds_s.h */, Mips::ADDS_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 228 /* adds_s.w */, Mips::ADDS_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 237 /* adds_u.b */, Mips::ADDS_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 246 /* adds_u.d */, Mips::ADDS_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 255 /* adds_u.h */, Mips::ADDS_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 264 /* adds_u.w */, Mips::ADDS_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 273 /* addsc */, Mips::ADDSC, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 279 /* addu */, Mips::AdduRxRyRz16, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 279 /* addu */, Mips::ADDu, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 279 /* addu */, Mips::ADDu_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 279 /* addu */, Mips::ADDiu, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, 0, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 284 /* addu.ph */, Mips::ADDU_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 292 /* addu.qb */, Mips::ADDU_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 300 /* addu_s.ph */, Mips::ADDU_S_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 310 /* addu_s.qb */, Mips::ADDU_S_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 320 /* adduh.qb */, Mips::ADDUH_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 329 /* adduh_r.qb */, Mips::ADDUH_R_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 340 /* addv.b */, Mips::ADDV_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 347 /* addv.d */, Mips::ADDV_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 354 /* addv.h */, Mips::ADDV_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 361 /* addv.w */, Mips::ADDV_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 368 /* addvi.b */, Mips::ADDVI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 376 /* addvi.d */, Mips::ADDVI_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 384 /* addvi.h */, Mips::ADDVI_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 392 /* addvi.w */, Mips::ADDVI_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 400 /* addwc */, Mips::ADDWC, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 406 /* and */, Mips::AndRxRxRy16, Convert__Reg1_0__Tie0__Reg1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 406 /* and */, Mips::AND, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 406 /* and */, Mips::AND_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 406 /* and */, Mips::ANDi, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, 0, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 410 /* and.v */, Mips::AND_V, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 416 /* andi */, Mips::ANDi, Convert__GPR32Asm1_0__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 416 /* andi */, Mips::ANDi_MM, Convert__GPR32Asm1_0__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 416 /* andi */, Mips::ANDi, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 416 /* andi */, Mips::ANDi_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 421 /* andi.b */, Mips::ANDI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 428 /* append */, Mips::APPEND, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Tie0, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 435 /* asub_s.b */, Mips::ASUB_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 444 /* asub_s.d */, Mips::ASUB_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 453 /* asub_s.h */, Mips::ASUB_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 462 /* asub_s.w */, Mips::ASUB_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 471 /* asub_u.b */, Mips::ASUB_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 480 /* asub_u.d */, Mips::ASUB_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 489 /* asub_u.h */, Mips::ASUB_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 498 /* asub_u.w */, Mips::ASUB_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 507 /* ave_s.b */, Mips::AVE_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 515 /* ave_s.d */, Mips::AVE_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 523 /* ave_s.h */, Mips::AVE_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 531 /* ave_s.w */, Mips::AVE_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 539 /* ave_u.b */, Mips::AVE_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 547 /* ave_u.d */, Mips::AVE_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 555 /* ave_u.h */, Mips::AVE_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 563 /* ave_u.w */, Mips::AVE_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 571 /* aver_s.b */, Mips::AVER_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 580 /* aver_s.d */, Mips::AVER_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 589 /* aver_s.h */, Mips::AVER_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 598 /* aver_s.w */, Mips::AVER_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 607 /* aver_u.b */, Mips::AVER_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 616 /* aver_u.d */, Mips::AVER_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 625 /* aver_u.h */, Mips::AVER_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 634 /* aver_u.w */, Mips::AVER_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 643 /* b */, Mips::BimmX16, Convert__Imm1_0, Feature_InMips16Mode, { MCK_Imm }, },
  { 643 /* b */, Mips::BEQ, Convert__regZERO__regZERO__Imm1_0, 0, { MCK_Imm }, },
  { 643 /* b */, Mips::Bimm16, Convert__Imm1_0, Feature_InMips16Mode, { MCK_Imm, MCK__35_, MCK_16, MCK_bit, MCK_inst }, },
  { 645 /* bal */, Mips::BGEZAL, Convert__regZERO__Imm1_0, 0, { MCK_Imm }, },
  { 649 /* balign */, Mips::BALIGN, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Tie0, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 656 /* bc1f */, Mips::BC1F, Convert__regFCC0__Imm1_0, 0, { MCK_Imm }, },
  { 656 /* bc1f */, Mips::BC1F, Convert__FCCRegsAsm1_0__Imm1_1, Feature_HasStdEnc, { MCK_FCCRegsAsm, MCK_Imm }, },
  { 661 /* bc1t */, Mips::BC1T, Convert__regFCC0__Imm1_0, 0, { MCK_Imm }, },
  { 661 /* bc1t */, Mips::BC1T, Convert__FCCRegsAsm1_0__Imm1_1, Feature_HasStdEnc, { MCK_FCCRegsAsm, MCK_Imm }, },
  { 666 /* bclr.b */, Mips::BCLR_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 673 /* bclr.d */, Mips::BCLR_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 680 /* bclr.h */, Mips::BCLR_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 687 /* bclr.w */, Mips::BCLR_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 694 /* bclri.b */, Mips::BCLRI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 702 /* bclri.d */, Mips::BCLRI_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 710 /* bclri.h */, Mips::BCLRI_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 718 /* bclri.w */, Mips::BCLRI_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 726 /* beq */, Mips::BEQ, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 726 /* beq */, Mips::BEQ_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 730 /* beqz */, Mips::BeqzRxImmX16, Convert__Reg1_0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm }, },
  { 730 /* beqz */, Mips::BEQ, Convert__GPR32Asm1_0__regZERO__Imm1_1, 0, { MCK_GPR32Asm, MCK_Imm }, },
  { 730 /* beqz */, Mips::BeqzRxImm16, Convert__Reg1_0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm, MCK__35_, MCK_16, MCK_bit, MCK_inst }, },
  { 735 /* bgez */, Mips::BGEZ, Convert__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 735 /* bgez */, Mips::BGEZ_MM, Convert__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 740 /* bgezal */, Mips::BGEZAL, Convert__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 740 /* bgezal */, Mips::BGEZAL_MM, Convert__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 747 /* bgtz */, Mips::BGTZ, Convert__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 747 /* bgtz */, Mips::BGTZ_MM, Convert__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 752 /* binsl.b */, Mips::BINSL_B, Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 760 /* binsl.d */, Mips::BINSL_D, Convert__MSA128DAsm1_0__Tie0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 768 /* binsl.h */, Mips::BINSL_H, Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 776 /* binsl.w */, Mips::BINSL_W, Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 784 /* binsli.b */, Mips::BINSLI_B, Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 793 /* binsli.d */, Mips::BINSLI_D, Convert__MSA128DAsm1_0__Tie0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 802 /* binsli.h */, Mips::BINSLI_H, Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 811 /* binsli.w */, Mips::BINSLI_W, Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 820 /* binsr.b */, Mips::BINSR_B, Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 828 /* binsr.d */, Mips::BINSR_D, Convert__MSA128DAsm1_0__Tie0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 836 /* binsr.h */, Mips::BINSR_H, Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 844 /* binsr.w */, Mips::BINSR_W, Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 852 /* binsri.b */, Mips::BINSRI_B, Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 861 /* binsri.d */, Mips::BINSRI_D, Convert__MSA128DAsm1_0__Tie0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 870 /* binsri.h */, Mips::BINSRI_H, Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 879 /* binsri.w */, Mips::BINSRI_W, Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 888 /* bitrev */, Mips::BITREV, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 895 /* blez */, Mips::BLEZ, Convert__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 895 /* blez */, Mips::BLEZ_MM, Convert__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 900 /* bltz */, Mips::BLTZ, Convert__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 900 /* bltz */, Mips::BLTZ_MM, Convert__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 905 /* bltzal */, Mips::BLTZAL, Convert__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 905 /* bltzal */, Mips::BLTZAL_MM, Convert__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 912 /* bmnz.v */, Mips::BMNZ_V, Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 919 /* bmnzi.b */, Mips::BMNZI_B, Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 927 /* bmz.v */, Mips::BMZ_V, Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 933 /* bmzi.b */, Mips::BMZI_B, Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 940 /* bne */, Mips::BNE, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 940 /* bne */, Mips::BNE_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 944 /* bneg.b */, Mips::BNEG_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 951 /* bneg.d */, Mips::BNEG_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 958 /* bneg.h */, Mips::BNEG_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 965 /* bneg.w */, Mips::BNEG_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 972 /* bnegi.b */, Mips::BNEGI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 980 /* bnegi.d */, Mips::BNEGI_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 988 /* bnegi.h */, Mips::BNEGI_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 996 /* bnegi.w */, Mips::BNEGI_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 1004 /* bnez */, Mips::BnezRxImmX16, Convert__Reg1_0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm }, },
  { 1004 /* bnez */, Mips::BNE, Convert__GPR32Asm1_0__regZERO__Imm1_1, 0, { MCK_GPR32Asm, MCK_Imm }, },
  { 1004 /* bnez */, Mips::BnezRxImm16, Convert__Reg1_0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm, MCK__35_, MCK_16, MCK_bit, MCK_inst }, },
  { 1009 /* bnz.b */, Mips::BNZ_B, Convert__MSA128BAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128BAsm, MCK_Imm }, },
  { 1015 /* bnz.d */, Mips::BNZ_D, Convert__MSA128DAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_Imm }, },
  { 1021 /* bnz.h */, Mips::BNZ_H, Convert__MSA128HAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128HAsm, MCK_Imm }, },
  { 1027 /* bnz.v */, Mips::BNZ_V, Convert__MSA128BAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128BAsm, MCK_Imm }, },
  { 1033 /* bnz.w */, Mips::BNZ_W, Convert__MSA128WAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_Imm }, },
  { 1039 /* bposge32 */, Mips::BPOSGE32, Convert__Imm1_0, Feature_HasDSP, { MCK_Imm }, },
  { 1048 /* break */, Mips::BREAK, Convert__imm_0__imm_0, 0, {  }, },
  { 1048 /* break */, Mips::Break16, Convert_NoOperands, Feature_InMips16Mode, { MCK_0 }, },
  { 1048 /* break */, Mips::BREAK, Convert__Imm1_0__imm_0, 0, { MCK_Imm }, },
  { 1048 /* break */, Mips::BREAK, Convert__Imm1_0__Imm1_1, Feature_HasStdEnc, { MCK_Imm, MCK_Imm }, },
  { 1054 /* bsel.v */, Mips::BSEL_V, Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 1061 /* bseli.b */, Mips::BSELI_B, Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 1069 /* bset.b */, Mips::BSET_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 1076 /* bset.d */, Mips::BSET_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 1083 /* bset.h */, Mips::BSET_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 1090 /* bset.w */, Mips::BSET_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 1097 /* bseti.b */, Mips::BSETI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 1105 /* bseti.d */, Mips::BSETI_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 1113 /* bseti.h */, Mips::BSETI_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 1121 /* bseti.w */, Mips::BSETI_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 1129 /* bteqz */, Mips::BteqzX16, Convert__Imm1_0, Feature_InMips16Mode, { MCK_Imm }, },
  { 1129 /* bteqz */, Mips::Bteqz16, Convert__Imm1_0, Feature_InMips16Mode, { MCK_Imm, MCK__35_, MCK_16, MCK_bit, MCK_inst }, },
  { 1135 /* btnez */, Mips::BtnezX16, Convert__Imm1_0, Feature_InMips16Mode, { MCK_Imm }, },
  { 1135 /* btnez */, Mips::Btnez16, Convert__Imm1_0, Feature_InMips16Mode, { MCK_Imm, MCK__35_, MCK_16, MCK_bit, MCK_inst }, },
  { 1141 /* bz.b */, Mips::BZ_B, Convert__MSA128BAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128BAsm, MCK_Imm }, },
  { 1146 /* bz.d */, Mips::BZ_D, Convert__MSA128DAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_Imm }, },
  { 1151 /* bz.h */, Mips::BZ_H, Convert__MSA128HAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128HAsm, MCK_Imm }, },
  { 1156 /* bz.v */, Mips::BZ_V, Convert__MSA128BAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128BAsm, MCK_Imm }, },
  { 1161 /* bz.w */, Mips::BZ_W, Convert__MSA128WAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_Imm }, },
  { 1166 /* c.eq.d */, Mips::C_EQ_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1166 /* c.eq.d */, Mips::C_EQ_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1173 /* c.eq.s */, Mips::C_EQ_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1180 /* c.f.d */, Mips::C_F_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1180 /* c.f.d */, Mips::C_F_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1186 /* c.f.s */, Mips::C_F_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1192 /* c.le.d */, Mips::C_LE_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1192 /* c.le.d */, Mips::C_LE_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1199 /* c.le.s */, Mips::C_LE_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1206 /* c.lt.d */, Mips::C_LT_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1206 /* c.lt.d */, Mips::C_LT_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1213 /* c.lt.s */, Mips::C_LT_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1220 /* c.nge.d */, Mips::C_NGE_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1220 /* c.nge.d */, Mips::C_NGE_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1228 /* c.nge.s */, Mips::C_NGE_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1236 /* c.ngl.d */, Mips::C_NGL_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1236 /* c.ngl.d */, Mips::C_NGL_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1244 /* c.ngl.s */, Mips::C_NGL_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1252 /* c.ngle.d */, Mips::C_NGLE_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1252 /* c.ngle.d */, Mips::C_NGLE_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1261 /* c.ngle.s */, Mips::C_NGLE_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1270 /* c.ngt.d */, Mips::C_NGT_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1270 /* c.ngt.d */, Mips::C_NGT_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1278 /* c.ngt.s */, Mips::C_NGT_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1286 /* c.ole.d */, Mips::C_OLE_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1286 /* c.ole.d */, Mips::C_OLE_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1294 /* c.ole.s */, Mips::C_OLE_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1302 /* c.olt.d */, Mips::C_OLT_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1302 /* c.olt.d */, Mips::C_OLT_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1310 /* c.olt.s */, Mips::C_OLT_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1318 /* c.seq.d */, Mips::C_SEQ_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1318 /* c.seq.d */, Mips::C_SEQ_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1326 /* c.seq.s */, Mips::C_SEQ_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1334 /* c.sf.d */, Mips::C_SF_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1334 /* c.sf.d */, Mips::C_SF_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1341 /* c.sf.s */, Mips::C_SF_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1348 /* c.ueq.d */, Mips::C_UEQ_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1348 /* c.ueq.d */, Mips::C_UEQ_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1356 /* c.ueq.s */, Mips::C_UEQ_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1364 /* c.ule.d */, Mips::C_ULE_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1364 /* c.ule.d */, Mips::C_ULE_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1372 /* c.ule.s */, Mips::C_ULE_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1380 /* c.ult.d */, Mips::C_ULT_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1380 /* c.ult.d */, Mips::C_ULT_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1388 /* c.ult.s */, Mips::C_ULT_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1396 /* c.un.d */, Mips::C_UN_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 1396 /* c.un.d */, Mips::C_UN_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1403 /* c.un.s */, Mips::C_UN_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1410 /* ceil.l.d */, Mips::CEIL_L_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 1419 /* ceil.l.s */, Mips::CEIL_L_S, Convert__FGR64Asm1_0__FGR32Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR32Asm }, },
  { 1428 /* ceil.w.d */, Mips::CEIL_W_D32, Convert__FGR32Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_AFGR64Asm }, },
  { 1428 /* ceil.w.d */, Mips::CEIL_W_D64, Convert__FGR32Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR64Asm }, },
  { 1437 /* ceil.w.s */, Mips::CEIL_W_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 1446 /* ceq.b */, Mips::CEQ_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 1452 /* ceq.d */, Mips::CEQ_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 1458 /* ceq.h */, Mips::CEQ_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 1464 /* ceq.w */, Mips::CEQ_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 1470 /* ceqi.b */, Mips::CEQI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 1477 /* ceqi.d */, Mips::CEQI_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 1484 /* ceqi.h */, Mips::CEQI_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 1491 /* ceqi.w */, Mips::CEQI_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 1498 /* cfc1 */, Mips::CFC1, Convert__GPR32Asm1_0__CCRAsm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_CCRAsm }, },
  { 1503 /* cfcmsa */, Mips::CFCMSA, Convert__GPR32Asm1_0__MSA128CRAsm1_1, Feature_HasMSA, { MCK_GPR32Asm, MCK_MSA128CRAsm }, },
  { 1510 /* cle_s.b */, Mips::CLE_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 1518 /* cle_s.d */, Mips::CLE_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 1526 /* cle_s.h */, Mips::CLE_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 1534 /* cle_s.w */, Mips::CLE_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 1542 /* cle_u.b */, Mips::CLE_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 1550 /* cle_u.d */, Mips::CLE_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 1558 /* cle_u.h */, Mips::CLE_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 1566 /* cle_u.w */, Mips::CLE_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 1574 /* clei_s.b */, Mips::CLEI_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 1583 /* clei_s.d */, Mips::CLEI_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 1592 /* clei_s.h */, Mips::CLEI_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 1601 /* clei_s.w */, Mips::CLEI_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 1610 /* clei_u.b */, Mips::CLEI_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 1619 /* clei_u.d */, Mips::CLEI_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 1628 /* clei_u.h */, Mips::CLEI_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 1637 /* clei_u.w */, Mips::CLEI_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 1646 /* clo */, Mips::CLO, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasBitCount|Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1646 /* clo */, Mips::CLO_MM, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1650 /* clt_s.b */, Mips::CLT_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 1658 /* clt_s.d */, Mips::CLT_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 1666 /* clt_s.h */, Mips::CLT_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 1674 /* clt_s.w */, Mips::CLT_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 1682 /* clt_u.b */, Mips::CLT_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 1690 /* clt_u.d */, Mips::CLT_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 1698 /* clt_u.h */, Mips::CLT_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 1706 /* clt_u.w */, Mips::CLT_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 1714 /* clti_s.b */, Mips::CLTI_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 1723 /* clti_s.d */, Mips::CLTI_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 1732 /* clti_s.h */, Mips::CLTI_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 1741 /* clti_s.w */, Mips::CLTI_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 1750 /* clti_u.b */, Mips::CLTI_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 1759 /* clti_u.d */, Mips::CLTI_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 1768 /* clti_u.h */, Mips::CLTI_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 1777 /* clti_u.w */, Mips::CLTI_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 1786 /* clz */, Mips::CLZ, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasBitCount|Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1786 /* clz */, Mips::CLZ_MM, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1790 /* cmp */, Mips::CmpRxRy16, Convert__Reg1_0__Reg1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 1794 /* cmp.eq.ph */, Mips::CMP_EQ_PH, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1804 /* cmp.le.ph */, Mips::CMP_LE_PH, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1814 /* cmp.lt.ph */, Mips::CMP_LT_PH, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1824 /* cmpgdu.eq.qb */, Mips::CMPGDU_EQ_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1837 /* cmpgdu.le.qb */, Mips::CMPGDU_LE_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1850 /* cmpgdu.lt.qb */, Mips::CMPGDU_LT_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1863 /* cmpgu.eq.qb */, Mips::CMPGU_EQ_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1875 /* cmpgu.le.qb */, Mips::CMPGU_LE_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1887 /* cmpgu.lt.qb */, Mips::CMPGU_LT_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1899 /* cmpi */, Mips::CmpiRxImmX16, Convert__Reg1_0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm }, },
  { 1899 /* cmpi */, Mips::CmpiRxImm16, Convert__Reg1_0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm, MCK__35_, MCK_16, MCK_bit, MCK_inst }, },
  { 1904 /* cmpu.eq.qb */, Mips::CMPU_EQ_QB, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1915 /* cmpu.le.qb */, Mips::CMPU_LE_QB, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1926 /* cmpu.lt.qb */, Mips::CMPU_LT_QB, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 1937 /* copy_s.b */, Mips::COPY_S_B, Convert__GPR32Asm1_0__MSA128BAsm1_1__Imm1_3, Feature_HasMSA, { MCK_GPR32Asm, MCK_MSA128BAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 1946 /* copy_s.h */, Mips::COPY_S_H, Convert__GPR32Asm1_0__MSA128HAsm1_1__Imm1_3, Feature_HasMSA, { MCK_GPR32Asm, MCK_MSA128HAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 1955 /* copy_s.w */, Mips::COPY_S_W, Convert__GPR32Asm1_0__MSA128WAsm1_1__Imm1_3, Feature_HasMSA, { MCK_GPR32Asm, MCK_MSA128WAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 1964 /* copy_u.b */, Mips::COPY_U_B, Convert__GPR32Asm1_0__MSA128BAsm1_1__Imm1_3, Feature_HasMSA, { MCK_GPR32Asm, MCK_MSA128BAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 1973 /* copy_u.h */, Mips::COPY_U_H, Convert__GPR32Asm1_0__MSA128HAsm1_1__Imm1_3, Feature_HasMSA, { MCK_GPR32Asm, MCK_MSA128HAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 1982 /* copy_u.w */, Mips::COPY_U_W, Convert__GPR32Asm1_0__MSA128WAsm1_1__Imm1_3, Feature_HasMSA, { MCK_GPR32Asm, MCK_MSA128WAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 1991 /* ctc1 */, Mips::CTC1, Convert__CCRAsm1_1__GPR32Asm1_0, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_CCRAsm }, },
  { 1996 /* ctcmsa */, Mips::CTCMSA, Convert__MSA128CRAsm1_0__GPR32Asm1_1, Feature_HasMSA, { MCK_MSA128CRAsm, MCK_GPR32Asm }, },
  { 2003 /* cvt.d.l */, Mips::CVT_D64_L, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 2011 /* cvt.d.s */, Mips::CVT_D32_S, Convert__AFGR64Asm1_0__FGR32Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_FGR32Asm }, },
  { 2011 /* cvt.d.s */, Mips::CVT_D64_S, Convert__FGR64Asm1_0__FGR32Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR32Asm }, },
  { 2019 /* cvt.d.w */, Mips::CVT_D32_W, Convert__AFGR64Asm1_0__FGR32Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_FGR32Asm }, },
  { 2019 /* cvt.d.w */, Mips::CVT_D64_W, Convert__FGR64Asm1_0__FGR32Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR32Asm }, },
  { 2027 /* cvt.l.d */, Mips::CVT_L_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 2035 /* cvt.l.s */, Mips::CVT_L_S, Convert__FGR64Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR32Asm }, },
  { 2043 /* cvt.s.d */, Mips::CVT_S_D32, Convert__FGR32Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_AFGR64Asm }, },
  { 2043 /* cvt.s.d */, Mips::CVT_S_D64, Convert__FGR32Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR64Asm }, },
  { 2051 /* cvt.s.l */, Mips::CVT_S_L, Convert__FGR32Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR64Asm }, },
  { 2059 /* cvt.s.w */, Mips::CVT_S_W, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 2067 /* cvt.w.d */, Mips::CVT_W_D32, Convert__FGR32Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_AFGR64Asm }, },
  { 2067 /* cvt.w.d */, Mips::CVT_W_D64, Convert__FGR32Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR64Asm }, },
  { 2075 /* cvt.w.s */, Mips::CVT_W_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 2083 /* dadd */, Mips::DADD, Convert__GPR64Asm1_0__GPR64Asm1_1__GPR64Asm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2083 /* dadd */, Mips::DADDi, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, 0, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2088 /* daddi */, Mips::DADDi, Convert__GPR64Asm1_0__GPR64Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_Imm }, },
  { 2088 /* daddi */, Mips::DADDi, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2094 /* daddiu */, Mips::DADDiu, Convert__GPR64Asm1_0__GPR64Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_Imm }, },
  { 2094 /* daddiu */, Mips::DADDiu, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2101 /* daddu */, Mips::DADDu, Convert__GPR64Asm1_0__GPR64Asm1_1__GPR64Asm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2101 /* daddu */, Mips::DADDiu, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, 0, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2107 /* dclo */, Mips::DCLO, Convert__GPR64Asm1_0__GPR64Asm1_1, Feature_HasBitCount|Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2112 /* dclz */, Mips::DCLZ, Convert__GPR64Asm1_0__GPR64Asm1_1, Feature_HasBitCount|Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2117 /* ddiv */, Mips::DSDIV, Convert__GPR64Asm1_1__GPR64Asm1_2, Feature_HasStdEnc, { MCK_ZERO, MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2122 /* ddivu */, Mips::DUDIV, Convert__GPR64Asm1_1__GPR64Asm1_2, Feature_HasStdEnc, { MCK_ZERO, MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2128 /* deret */, Mips::DERET, Convert_NoOperands, Feature_HasStdEnc, {  }, },
  { 2134 /* dext */, Mips::DEXT, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2__Imm1_3, Feature_HasMips32r2|Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm, MCK_Imm }, },
  { 2139 /* dextm */, Mips::DEXTM, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2__Imm1_3, Feature_HasMips32r2|Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm, MCK_Imm }, },
  { 2145 /* dextu */, Mips::DEXTU, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2__Imm1_3, Feature_HasMips32r2|Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm, MCK_Imm }, },
  { 2151 /* di */, Mips::DI, Convert__regZERO, 0, {  }, },
  { 2151 /* di */, Mips::DI, Convert__GPR32Asm1_0, Feature_HasStdEnc, { MCK_GPR32Asm }, },
  { 2154 /* dins */, Mips::DINS, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2__Imm1_3__Tie0, Feature_HasMips32r2|Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm, MCK_Imm }, },
  { 2159 /* dinsm */, Mips::DINSM, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2__Imm1_3__Tie0, Feature_HasMips32r2|Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm, MCK_Imm }, },
  { 2165 /* dinsu */, Mips::DINSU, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2__Imm1_3__Tie0, Feature_HasMips32r2|Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm, MCK_Imm }, },
  { 2171 /* div */, Mips::DivRxRy16, Convert__Reg1_1__Reg1_2, Feature_InMips16Mode, { MCK_ZERO, MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 2171 /* div */, Mips::SDIV, Convert__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_ZERO, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2171 /* div */, Mips::SDIV_MM, Convert__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_ZERO, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2175 /* div.d */, Mips::FDIV_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1__AFGR64Asm1_2, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 2175 /* div.d */, Mips::FDIV_D64, Convert__FGR64Asm1_0__FGR64Asm1_1__FGR64Asm1_2, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 2181 /* div.s */, Mips::FDIV_S, Convert__FGR32Asm1_0__FGR32Asm1_1__FGR32Asm1_2, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 2187 /* div_s.b */, Mips::DIV_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 2195 /* div_s.d */, Mips::DIV_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 2203 /* div_s.h */, Mips::DIV_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 2211 /* div_s.w */, Mips::DIV_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2219 /* div_u.b */, Mips::DIV_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 2227 /* div_u.d */, Mips::DIV_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 2235 /* div_u.h */, Mips::DIV_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 2243 /* div_u.w */, Mips::DIV_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2251 /* divu */, Mips::DivuRxRy16, Convert__Reg1_1__Reg1_2, Feature_InMips16Mode, { MCK_ZERO, MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 2251 /* divu */, Mips::UDIV, Convert__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_ZERO, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2251 /* divu */, Mips::UDIV_MM, Convert__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_ZERO, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2256 /* dmfc0 */, Mips::DMFC0, Convert__GPR64Asm1_0__GPR64Asm1_1__imm_0, 0, { MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2256 /* dmfc0 */, Mips::DMFC0, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasMips64, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2262 /* dmfc1 */, Mips::DMFC1, Convert__GPR64Asm1_0__FGR64Asm1_1, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_FGR64Asm }, },
  { 2268 /* dmfc2 */, Mips::DMFC2, Convert__GPR64Asm1_0__GPR64Asm1_1__imm_0, 0, { MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2268 /* dmfc2 */, Mips::DMFC2, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasMips64, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2274 /* dmtc0 */, Mips::DMTC0, Convert__GPR64Asm1_0__GPR64Asm1_1__imm_0, 0, { MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2274 /* dmtc0 */, Mips::DMTC0, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasMips64, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2280 /* dmtc1 */, Mips::DMTC1, Convert__FGR64Asm1_1__GPR64Asm1_0, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_FGR64Asm }, },
  { 2286 /* dmtc2 */, Mips::DMTC2, Convert__GPR64Asm1_0__GPR64Asm1_1__imm_0, 0, { MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2286 /* dmtc2 */, Mips::DMTC2, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasMips64, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2292 /* dmult */, Mips::DMULT, Convert__GPR64Asm1_0__GPR64Asm1_1, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2298 /* dmultu */, Mips::DMULTu, Convert__GPR64Asm1_0__GPR64Asm1_1, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2305 /* dotp_s.d */, Mips::DOTP_S_D, Convert__MSA128DAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2314 /* dotp_s.h */, Mips::DOTP_S_H, Convert__MSA128HAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 2323 /* dotp_s.w */, Mips::DOTP_S_W, Convert__MSA128WAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 2332 /* dotp_u.d */, Mips::DOTP_U_D, Convert__MSA128DAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2341 /* dotp_u.h */, Mips::DOTP_U_H, Convert__MSA128HAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 2350 /* dotp_u.w */, Mips::DOTP_U_W, Convert__MSA128WAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 2359 /* dpa.w.ph */, Mips::DPA_W_PH, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSPR2, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2368 /* dpadd_s.d */, Mips::DPADD_S_D, Convert__MSA128DAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2378 /* dpadd_s.h */, Mips::DPADD_S_H, Convert__MSA128HAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 2388 /* dpadd_s.w */, Mips::DPADD_S_W, Convert__MSA128WAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 2398 /* dpadd_u.d */, Mips::DPADD_U_D, Convert__MSA128DAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2408 /* dpadd_u.h */, Mips::DPADD_U_H, Convert__MSA128HAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 2418 /* dpadd_u.w */, Mips::DPADD_U_W, Convert__MSA128WAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 2428 /* dpaq_s.w.ph */, Mips::DPAQ_S_W_PH, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2440 /* dpaq_sa.l.w */, Mips::DPAQ_SA_L_W, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2452 /* dpaqx_s.w.ph */, Mips::DPAQX_S_W_PH, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSPR2, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2465 /* dpaqx_sa.w.ph */, Mips::DPAQX_SA_W_PH, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSPR2, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2479 /* dpau.h.qbl */, Mips::DPAU_H_QBL, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2490 /* dpau.h.qbr */, Mips::DPAU_H_QBR, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2501 /* dpax.w.ph */, Mips::DPAX_W_PH, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSPR2, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2511 /* dps.w.ph */, Mips::DPS_W_PH, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSPR2, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2520 /* dpsq_s.w.ph */, Mips::DPSQ_S_W_PH, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2532 /* dpsq_sa.l.w */, Mips::DPSQ_SA_L_W, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2544 /* dpsqx_s.w.ph */, Mips::DPSQX_S_W_PH, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSPR2, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2557 /* dpsqx_sa.w.ph */, Mips::DPSQX_SA_W_PH, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSPR2, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2571 /* dpsu.h.qbl */, Mips::DPSU_H_QBL, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2582 /* dpsu.h.qbr */, Mips::DPSU_H_QBR, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2593 /* dpsub_s.d */, Mips::DPSUB_S_D, Convert__MSA128DAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2603 /* dpsub_s.h */, Mips::DPSUB_S_H, Convert__MSA128HAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 2613 /* dpsub_s.w */, Mips::DPSUB_S_W, Convert__MSA128WAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 2623 /* dpsub_u.d */, Mips::DPSUB_U_D, Convert__MSA128DAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2633 /* dpsub_u.h */, Mips::DPSUB_U_H, Convert__MSA128HAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 2643 /* dpsub_u.w */, Mips::DPSUB_U_W, Convert__MSA128WAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 2653 /* dpsx.w.ph */, Mips::DPSX_W_PH, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSPR2, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 2663 /* drotr */, Mips::DROTR, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasMips64r2|Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2669 /* drotr32 */, Mips::DROTR32, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasMips64r2|Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2677 /* drotrv */, Mips::DROTRV, Convert__GPR64Asm1_0__GPR64Asm1_1__GPR32Asm1_2, Feature_HasMips64r2|Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_GPR32Asm }, },
  { 2684 /* dsbh */, Mips::DSBH, Convert__GPR64Asm1_0__GPR64Asm1_1, Feature_HasSwap|Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2689 /* dshd */, Mips::DSHD, Convert__GPR64Asm1_0__GPR64Asm1_1, Feature_HasSwap|Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2694 /* dsll */, Mips::DSLL, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2699 /* dsll32 */, Mips::DSLL32, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2706 /* dsllv */, Mips::DSLLV, Convert__GPR64Asm1_0__GPR64Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_GPR32Asm }, },
  { 2712 /* dsra */, Mips::DSRA, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2717 /* dsra32 */, Mips::DSRA32, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2724 /* dsrav */, Mips::DSRAV, Convert__GPR64Asm1_0__GPR64Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_GPR32Asm }, },
  { 2730 /* dsrl */, Mips::DSRL, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2735 /* dsrl32 */, Mips::DSRL32, Convert__GPR64Asm1_0__GPR64Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_Imm }, },
  { 2742 /* dsrlv */, Mips::DSRLV, Convert__GPR64Asm1_0__GPR64Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_GPR32Asm }, },
  { 2748 /* dsubu */, Mips::DSUBu, Convert__GPR64Asm1_0__GPR64Asm1_1__GPR64Asm1_2, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 2754 /* ei */, Mips::EI, Convert__regZERO, 0, {  }, },
  { 2754 /* ei */, Mips::EI, Convert__GPR32Asm1_0, Feature_HasStdEnc, { MCK_GPR32Asm }, },
  { 2757 /* eret */, Mips::ERET, Convert_NoOperands, Feature_HasStdEnc, {  }, },
  { 2762 /* ext */, Mips::EXT, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Imm1_3, Feature_HasMips32r2|Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm, MCK_Imm }, },
  { 2762 /* ext */, Mips::EXT_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Imm1_3, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm, MCK_Imm }, },
  { 2766 /* extp */, Mips::EXTP, Convert__GPR32Asm1_0__ACC64DSPAsm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm, MCK_Imm }, },
  { 2771 /* extpdp */, Mips::EXTPDP, Convert__GPR32Asm1_0__ACC64DSPAsm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm, MCK_Imm }, },
  { 2778 /* extpdpv */, Mips::EXTPDPV, Convert__GPR32Asm1_0__ACC64DSPAsm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm, MCK_GPR32Asm }, },
  { 2786 /* extpv */, Mips::EXTPV, Convert__GPR32Asm1_0__ACC64DSPAsm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm, MCK_GPR32Asm }, },
  { 2792 /* extr.w */, Mips::EXTR_W, Convert__GPR32Asm1_0__ACC64DSPAsm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm, MCK_Imm }, },
  { 2799 /* extr_r.w */, Mips::EXTR_R_W, Convert__GPR32Asm1_0__ACC64DSPAsm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm, MCK_Imm }, },
  { 2808 /* extr_rs.w */, Mips::EXTR_RS_W, Convert__GPR32Asm1_0__ACC64DSPAsm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm, MCK_Imm }, },
  { 2818 /* extr_s.h */, Mips::EXTR_S_H, Convert__GPR32Asm1_0__ACC64DSPAsm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm, MCK_Imm }, },
  { 2827 /* extrv.w */, Mips::EXTRV_W, Convert__GPR32Asm1_0__ACC64DSPAsm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm, MCK_GPR32Asm }, },
  { 2835 /* extrv_r.w */, Mips::EXTRV_R_W, Convert__GPR32Asm1_0__ACC64DSPAsm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm, MCK_GPR32Asm }, },
  { 2845 /* extrv_rs.w */, Mips::EXTRV_RS_W, Convert__GPR32Asm1_0__ACC64DSPAsm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm, MCK_GPR32Asm }, },
  { 2856 /* extrv_s.h */, Mips::EXTRV_S_H, Convert__GPR32Asm1_0__ACC64DSPAsm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm, MCK_GPR32Asm }, },
  { 2866 /* fadd.d */, Mips::FADD_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 2873 /* fadd.w */, Mips::FADD_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2880 /* fcaf.d */, Mips::FCAF_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 2887 /* fcaf.w */, Mips::FCAF_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2894 /* fceq.d */, Mips::FCEQ_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 2901 /* fceq.w */, Mips::FCEQ_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2908 /* fclass.d */, Mips::FCLASS_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 2917 /* fclass.w */, Mips::FCLASS_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2926 /* fcle.d */, Mips::FCLE_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 2933 /* fcle.w */, Mips::FCLE_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2940 /* fclt.d */, Mips::FCLT_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 2947 /* fclt.w */, Mips::FCLT_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2954 /* fcne.d */, Mips::FCNE_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 2961 /* fcne.w */, Mips::FCNE_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2968 /* fcor.d */, Mips::FCOR_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 2975 /* fcor.w */, Mips::FCOR_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2982 /* fcueq.d */, Mips::FCUEQ_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 2990 /* fcueq.w */, Mips::FCUEQ_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 2998 /* fcule.d */, Mips::FCULE_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3006 /* fcule.w */, Mips::FCULE_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3014 /* fcult.d */, Mips::FCULT_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3022 /* fcult.w */, Mips::FCULT_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3030 /* fcun.d */, Mips::FCUN_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3037 /* fcun.w */, Mips::FCUN_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3044 /* fcune.d */, Mips::FCUNE_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3052 /* fcune.w */, Mips::FCUNE_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3060 /* fdiv.d */, Mips::FDIV_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3067 /* fdiv.w */, Mips::FDIV_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3074 /* fexdo.h */, Mips::FEXDO_H, Convert__MSA128HAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3082 /* fexdo.w */, Mips::FEXDO_W, Convert__MSA128WAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3090 /* fexp2.d */, Mips::FEXP2_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3098 /* fexp2.w */, Mips::FEXP2_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3106 /* fexupl.d */, Mips::FEXUPL_D, Convert__MSA128DAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm }, },
  { 3115 /* fexupl.w */, Mips::FEXUPL_W, Convert__MSA128WAsm1_0__MSA128HAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm }, },
  { 3124 /* fexupr.d */, Mips::FEXUPR_D, Convert__MSA128DAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm }, },
  { 3133 /* fexupr.w */, Mips::FEXUPR_W, Convert__MSA128WAsm1_0__MSA128HAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm }, },
  { 3142 /* ffint_s.d */, Mips::FFINT_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3152 /* ffint_s.w */, Mips::FFINT_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3162 /* ffint_u.d */, Mips::FFINT_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3172 /* ffint_u.w */, Mips::FFINT_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3182 /* ffql.d */, Mips::FFQL_D, Convert__MSA128DAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm }, },
  { 3189 /* ffql.w */, Mips::FFQL_W, Convert__MSA128WAsm1_0__MSA128HAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm }, },
  { 3196 /* ffqr.d */, Mips::FFQR_D, Convert__MSA128DAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm }, },
  { 3203 /* ffqr.w */, Mips::FFQR_W, Convert__MSA128WAsm1_0__MSA128HAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm }, },
  { 3210 /* fill.b */, Mips::FILL_B, Convert__MSA128BAsm1_0__GPR32Asm1_1, Feature_HasMSA, { MCK_MSA128BAsm, MCK_GPR32Asm }, },
  { 3217 /* fill.h */, Mips::FILL_H, Convert__MSA128HAsm1_0__GPR32Asm1_1, Feature_HasMSA, { MCK_MSA128HAsm, MCK_GPR32Asm }, },
  { 3224 /* fill.w */, Mips::FILL_W, Convert__MSA128WAsm1_0__GPR32Asm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_GPR32Asm }, },
  { 3231 /* flog2.d */, Mips::FLOG2_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3239 /* flog2.w */, Mips::FLOG2_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3247 /* floor.l.d */, Mips::FLOOR_L_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 3257 /* floor.l.s */, Mips::FLOOR_L_S, Convert__FGR64Asm1_0__FGR32Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR32Asm }, },
  { 3267 /* floor.w.d */, Mips::FLOOR_W_D32, Convert__FGR32Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_AFGR64Asm }, },
  { 3267 /* floor.w.d */, Mips::FLOOR_W_D64, Convert__FGR32Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR64Asm }, },
  { 3277 /* floor.w.s */, Mips::FLOOR_W_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 3287 /* fmadd.d */, Mips::FMADD_D, Convert__MSA128DAsm1_0__Tie0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3295 /* fmadd.w */, Mips::FMADD_W, Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3303 /* fmax.d */, Mips::FMAX_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3310 /* fmax.w */, Mips::FMAX_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3317 /* fmax_a.d */, Mips::FMAX_A_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3326 /* fmax_a.w */, Mips::FMAX_A_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3335 /* fmin.d */, Mips::FMIN_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3342 /* fmin.w */, Mips::FMIN_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3349 /* fmin_a.d */, Mips::FMIN_A_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3358 /* fmin_a.w */, Mips::FMIN_A_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3367 /* fmsub.d */, Mips::FMSUB_D, Convert__MSA128DAsm1_0__Tie0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3375 /* fmsub.w */, Mips::FMSUB_W, Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3383 /* fmul.d */, Mips::FMUL_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3390 /* fmul.w */, Mips::FMUL_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3397 /* frcp.d */, Mips::FRCP_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3404 /* frcp.w */, Mips::FRCP_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3411 /* frint.d */, Mips::FRINT_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3419 /* frint.w */, Mips::FRINT_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3427 /* frsqrt.d */, Mips::FRSQRT_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3436 /* frsqrt.w */, Mips::FRSQRT_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3445 /* fsaf.d */, Mips::FSAF_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3452 /* fsaf.w */, Mips::FSAF_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3459 /* fseq.d */, Mips::FSEQ_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3466 /* fseq.w */, Mips::FSEQ_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3473 /* fsle.d */, Mips::FSLE_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3480 /* fsle.w */, Mips::FSLE_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3487 /* fslt.d */, Mips::FSLT_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3494 /* fslt.w */, Mips::FSLT_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3501 /* fsne.d */, Mips::FSNE_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3508 /* fsne.w */, Mips::FSNE_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3515 /* fsor.d */, Mips::FSOR_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3522 /* fsor.w */, Mips::FSOR_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3529 /* fsqrt.d */, Mips::FSQRT_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3537 /* fsqrt.w */, Mips::FSQRT_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3545 /* fsub.d */, Mips::FSUB_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3552 /* fsub.w */, Mips::FSUB_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3559 /* fsueq.d */, Mips::FSUEQ_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3567 /* fsueq.w */, Mips::FSUEQ_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3575 /* fsule.d */, Mips::FSULE_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3583 /* fsule.w */, Mips::FSULE_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3591 /* fsult.d */, Mips::FSULT_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3599 /* fsult.w */, Mips::FSULT_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3607 /* fsun.d */, Mips::FSUN_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3614 /* fsun.w */, Mips::FSUN_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3621 /* fsune.d */, Mips::FSUNE_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3629 /* fsune.w */, Mips::FSUNE_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3637 /* ftint_s.d */, Mips::FTINT_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3647 /* ftint_s.w */, Mips::FTINT_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3657 /* ftint_u.d */, Mips::FTINT_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3667 /* ftint_u.w */, Mips::FTINT_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3677 /* ftq.h */, Mips::FTQ_H, Convert__MSA128HAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3683 /* ftq.w */, Mips::FTQ_W, Convert__MSA128WAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3689 /* ftrunc_s.d */, Mips::FTRUNC_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3700 /* ftrunc_s.w */, Mips::FTRUNC_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3711 /* ftrunc_u.d */, Mips::FTRUNC_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3722 /* ftrunc_u.w */, Mips::FTRUNC_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3733 /* hadd_s.d */, Mips::HADD_S_D, Convert__MSA128DAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3742 /* hadd_s.h */, Mips::HADD_S_H, Convert__MSA128HAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 3751 /* hadd_s.w */, Mips::HADD_S_W, Convert__MSA128WAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 3760 /* hadd_u.d */, Mips::HADD_U_D, Convert__MSA128DAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3769 /* hadd_u.h */, Mips::HADD_U_H, Convert__MSA128HAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 3778 /* hadd_u.w */, Mips::HADD_U_W, Convert__MSA128WAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 3787 /* hsub_s.d */, Mips::HSUB_S_D, Convert__MSA128DAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3796 /* hsub_s.h */, Mips::HSUB_S_H, Convert__MSA128HAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 3805 /* hsub_s.w */, Mips::HSUB_S_W, Convert__MSA128WAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 3814 /* hsub_u.d */, Mips::HSUB_U_D, Convert__MSA128DAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3823 /* hsub_u.h */, Mips::HSUB_U_H, Convert__MSA128HAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 3832 /* hsub_u.w */, Mips::HSUB_U_W, Convert__MSA128WAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 3841 /* ilvev.b */, Mips::ILVEV_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 3849 /* ilvev.d */, Mips::ILVEV_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3857 /* ilvev.h */, Mips::ILVEV_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 3865 /* ilvev.w */, Mips::ILVEV_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3873 /* ilvl.b */, Mips::ILVL_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 3880 /* ilvl.d */, Mips::ILVL_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3887 /* ilvl.h */, Mips::ILVL_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 3894 /* ilvl.w */, Mips::ILVL_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3901 /* ilvod.b */, Mips::ILVOD_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 3909 /* ilvod.d */, Mips::ILVOD_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3917 /* ilvod.h */, Mips::ILVOD_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 3925 /* ilvod.w */, Mips::ILVOD_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3933 /* ilvr.b */, Mips::ILVR_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 3940 /* ilvr.d */, Mips::ILVR_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 3947 /* ilvr.h */, Mips::ILVR_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 3954 /* ilvr.w */, Mips::ILVR_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 3961 /* ins */, Mips::INS, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Imm1_3__Tie0, Feature_HasMips32r2|Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm, MCK_Imm }, },
  { 3961 /* ins */, Mips::INS_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Imm1_3__Tie0, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm, MCK_Imm }, },
  { 3965 /* insert.b */, Mips::INSERT_B, Convert__MSA128BAsm1_0__Tie0__GPR32Asm1_4__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK__91_, MCK_Imm, MCK__93_, MCK_GPR32Asm }, },
  { 3974 /* insert.h */, Mips::INSERT_H, Convert__MSA128HAsm1_0__Tie0__GPR32Asm1_4__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK__91_, MCK_Imm, MCK__93_, MCK_GPR32Asm }, },
  { 3983 /* insert.w */, Mips::INSERT_W, Convert__MSA128WAsm1_0__Tie0__GPR32Asm1_4__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK__91_, MCK_Imm, MCK__93_, MCK_GPR32Asm }, },
  { 3992 /* insv */, Mips::INSV, Convert__GPR32Asm1_0__Tie0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 3997 /* insve.b */, Mips::INSVE_B, Convert__MSA128BAsm1_0__Tie0__Imm1_2__MSA128BAsm1_4, Feature_HasMSA, { MCK_MSA128BAsm, MCK__91_, MCK_Imm, MCK__93_, MCK_MSA128BAsm, MCK__91_, MCK_0, MCK__93_ }, },
  { 4005 /* insve.d */, Mips::INSVE_D, Convert__MSA128DAsm1_0__Tie0__Imm1_2__MSA128DAsm1_4, Feature_HasMSA, { MCK_MSA128DAsm, MCK__91_, MCK_Imm, MCK__93_, MCK_MSA128DAsm, MCK__91_, MCK_0, MCK__93_ }, },
  { 4013 /* insve.h */, Mips::INSVE_H, Convert__MSA128HAsm1_0__Tie0__Imm1_2__MSA128HAsm1_4, Feature_HasMSA, { MCK_MSA128HAsm, MCK__91_, MCK_Imm, MCK__93_, MCK_MSA128HAsm, MCK__91_, MCK_0, MCK__93_ }, },
  { 4021 /* insve.w */, Mips::INSVE_W, Convert__MSA128WAsm1_0__Tie0__Imm1_2__MSA128WAsm1_4, Feature_HasMSA, { MCK_MSA128WAsm, MCK__91_, MCK_Imm, MCK__93_, MCK_MSA128WAsm, MCK__91_, MCK_0, MCK__93_ }, },
  { 4029 /* j */, Mips::JR, Convert__GPR32Asm1_0, 0, { MCK_GPR32Asm }, },
  { 4029 /* j */, Mips::J, Convert__Imm1_0, Feature_RelocStatic|Feature_HasStdEnc, { MCK_Imm }, },
  { 4029 /* j */, Mips::J_MM, Convert__Imm1_0, Feature_InMicroMips, { MCK_Imm }, },
  { 4031 /* jal */, Mips::JALR, Convert__regRA__GPR32Asm1_0, 0, { MCK_GPR32Asm }, },
  { 4031 /* jal */, Mips::JAL, Convert__Imm1_0, Feature_HasStdEnc, { MCK_Imm }, },
  { 4031 /* jal */, Mips::JAL_MM, Convert__Imm1_0, Feature_InMicroMips, { MCK_Imm }, },
  { 4031 /* jal */, Mips::JALR, Convert__GPR32Asm1_0__GPR32Asm1_1, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4035 /* jalr */, Mips::JALR, Convert__regRA__GPR32Asm1_0, 0, { MCK_GPR32Asm }, },
  { 4035 /* jalr */, Mips::JALR, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4035 /* jalr */, Mips::JALR_MM, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4040 /* jalrc */, Mips::JumpLinkReg16, Convert__Reg1_0, Feature_InMips16Mode, { MCK_CPU16Regs }, },
  { 4046 /* jr */, Mips::JrRa16, Convert_NoOperands, Feature_InMips16Mode, { MCK_CPURAReg }, },
  { 4046 /* jr */, Mips::JR, Convert__GPR32Asm1_0, Feature_HasStdEnc, { MCK_GPR32Asm }, },
  { 4046 /* jr */, Mips::JR_MM, Convert__GPR32Asm1_0, Feature_InMicroMips, { MCK_GPR32Asm }, },
  { 4049 /* jrc */, Mips::JrcRx16, Convert__Reg1_0, Feature_InMips16Mode, { MCK_CPU16Regs }, },
  { 4049 /* jrc */, Mips::JrcRa16, Convert_NoOperands, Feature_InMips16Mode, { MCK_CPURAReg }, },
  { 4053 /* la */, Mips::LoadAddr32Imm, Convert__GPR32Asm1_0__Imm1_1, 0, { MCK_GPR32Asm, MCK_Imm }, },
  { 4053 /* la */, Mips::LoadAddr32Reg, Convert__GPR32Asm1_0__Mem2_1, 0, { MCK_GPR32Asm, MCK_Mem }, },
  { 4056 /* lb */, Mips::LB, Convert__GPR32Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Mem }, },
  { 4056 /* lb */, Mips::LB_MM, Convert__GPR32Asm1_0__Mem2_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 4059 /* lbu */, Mips::LBu, Convert__GPR32Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Mem }, },
  { 4059 /* lbu */, Mips::LBu_MM, Convert__GPR32Asm1_0__Mem2_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 4063 /* lbux */, Mips::LBUX, Convert__GPR32Asm1_0__PtrReg1_3__PtrReg1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_PtrReg, MCK__40_, MCK_PtrReg, MCK__41_ }, },
  { 4068 /* ld */, Mips::LD, Convert__GPR64Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_Mem }, },
  { 4071 /* ld.b */, Mips::LD_B, Convert__MSA128BAsm1_0__Mem2_1, Feature_HasMSA, { MCK_MSA128BAsm, MCK_Mem }, },
  { 4076 /* ld.d */, Mips::LD_D, Convert__MSA128DAsm1_0__Mem2_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_Mem }, },
  { 4081 /* ld.h */, Mips::LD_H, Convert__MSA128HAsm1_0__Mem2_1, Feature_HasMSA, { MCK_MSA128HAsm, MCK_Mem }, },
  { 4086 /* ld.w */, Mips::LD_W, Convert__MSA128WAsm1_0__Mem2_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_Mem }, },
  { 4091 /* ldc1 */, Mips::LDC1, Convert__AFGR64Asm1_0__Mem2_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_Mem }, },
  { 4091 /* ldc1 */, Mips::LDC164, Convert__FGR64Asm1_0__Mem2_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_Mem }, },
  { 4096 /* ldc2 */, Mips::LDC2, Convert__COP2Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_COP2Asm, MCK_Mem }, },
  { 4101 /* ldi.b */, Mips::LDI_B, Convert__MSA128BAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128BAsm, MCK_Imm }, },
  { 4107 /* ldi.d */, Mips::LDI_D, Convert__MSA128DAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_Imm }, },
  { 4113 /* ldi.h */, Mips::LDI_H, Convert__MSA128HAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128HAsm, MCK_Imm }, },
  { 4119 /* ldi.w */, Mips::LDI_W, Convert__MSA128WAsm1_0__Imm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_Imm }, },
  { 4125 /* ldl */, Mips::LDL, Convert__GPR64Asm1_0__Mem2_1__Tie0, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_Mem }, },
  { 4129 /* ldr */, Mips::LDR, Convert__GPR64Asm1_0__Mem2_1__Tie0, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_Mem }, },
  { 4133 /* ldxc1 */, Mips::LDXC1, Convert__AFGR64Asm1_0__PtrReg1_3__PtrReg1_1, Feature_HasFPIdx|Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_PtrReg, MCK__40_, MCK_PtrReg, MCK__41_ }, },
  { 4133 /* ldxc1 */, Mips::LDXC164, Convert__FGR64Asm1_0__PtrReg1_3__PtrReg1_1, Feature_HasFPIdx|Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_PtrReg, MCK__40_, MCK_PtrReg, MCK__41_ }, },
  { 4139 /* lh */, Mips::LH, Convert__GPR32Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Mem }, },
  { 4139 /* lh */, Mips::LH_MM, Convert__GPR32Asm1_0__Mem2_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 4142 /* lhu */, Mips::LHu, Convert__GPR32Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Mem }, },
  { 4142 /* lhu */, Mips::LHu_MM, Convert__GPR32Asm1_0__Mem2_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 4146 /* lhx */, Mips::LHX, Convert__GPR32Asm1_0__PtrReg1_3__PtrReg1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_PtrReg, MCK__40_, MCK_PtrReg, MCK__41_ }, },
  { 4150 /* li */, Mips::LiRxImmX16, Convert__Reg1_0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm }, },
  { 4150 /* li */, Mips::LoadImm32Reg, Convert__GPR32Asm1_0__Imm1_1, 0, { MCK_GPR32Asm, MCK_Imm }, },
  { 4150 /* li */, Mips::LiRxImm16, Convert__Reg1_0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm, MCK__35_, MCK_16, MCK_bit, MCK_inst }, },
  { 4153 /* ll */, Mips::LL, Convert__GPR32Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Mem }, },
  { 4156 /* lld */, Mips::LLD, Convert__GPR64Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_Mem }, },
  { 4160 /* lsa */, Mips::LSA, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2__LSAImm1_3, Feature_HasMSA, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm, MCK_LSAImm }, },
  { 4164 /* lui */, Mips::LUi, Convert__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 4164 /* lui */, Mips::LUi_MM, Convert__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 4168 /* luxc1 */, Mips::LUXC1, Convert__AFGR64Asm1_0__PtrReg1_3__PtrReg1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_PtrReg, MCK__40_, MCK_PtrReg, MCK__41_ }, },
  { 4168 /* luxc1 */, Mips::LUXC164, Convert__FGR64Asm1_0__PtrReg1_3__PtrReg1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_PtrReg, MCK__40_, MCK_PtrReg, MCK__41_ }, },
  { 4174 /* lw */, Mips::LwRxPcTcpX16, Convert__Reg1_0__Imm1_1__imm_0, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm }, },
  { 4174 /* lw */, Mips::LW, Convert__GPR32Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Mem }, },
  { 4174 /* lw */, Mips::LW_MM, Convert__GPR32Asm1_0__Mem2_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 4174 /* lw */, Mips::LwRxSpImmX16, Convert__Reg1_0__Reg1_3__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm, MCK__40_, MCK_CPUSPReg, MCK__41__59_ }, },
  { 4174 /* lw */, Mips::LwRxPcTcp16, Convert__Reg1_0__Imm1_1__imm_0, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm, MCK__35_, MCK_16, MCK_bit, MCK_inst }, },
  { 4177 /* lwc1 */, Mips::LWC1, Convert__FGR32Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_Mem }, },
  { 4182 /* lwc2 */, Mips::LWC2, Convert__COP2Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_COP2Asm, MCK_Mem }, },
  { 4187 /* lwl */, Mips::LWL, Convert__GPR32Asm1_0__Mem2_1__Tie0, Feature_NotInMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 4187 /* lwl */, Mips::LWL_MM, Convert__GPR32Asm1_0__Mem2_1__Tie0, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 4191 /* lwr */, Mips::LWR, Convert__GPR32Asm1_0__Mem2_1__Tie0, Feature_NotInMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 4191 /* lwr */, Mips::LWR_MM, Convert__GPR32Asm1_0__Mem2_1__Tie0, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 4195 /* lwu */, Mips::LWu, Convert__GPR64Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_Mem }, },
  { 4199 /* lwx */, Mips::LWX, Convert__GPR32Asm1_0__PtrReg1_3__PtrReg1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_PtrReg, MCK__40_, MCK_PtrReg, MCK__41_ }, },
  { 4203 /* lwxc1 */, Mips::LWXC1, Convert__FGR32Asm1_0__PtrReg1_3__PtrReg1_1, Feature_HasFPIdx|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_PtrReg, MCK__40_, MCK_PtrReg, MCK__41_ }, },
  { 4209 /* madd */, Mips::MADD, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4209 /* madd */, Mips::MADD_MM, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4209 /* madd */, Mips::MADD_DSP, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4214 /* madd.d */, Mips::MADD_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1__AFGR64Asm1_2__AFGR64Asm1_3, Feature_HasMips32r2|Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 4221 /* madd.s */, Mips::MADD_S, Convert__FGR32Asm1_0__FGR32Asm1_1__FGR32Asm1_2__FGR32Asm1_3, Feature_HasMips32r2|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm, MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 4228 /* madd_q.h */, Mips::MADD_Q_H, Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4237 /* madd_q.w */, Mips::MADD_Q_W, Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4246 /* maddr_q.h */, Mips::MADDR_Q_H, Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4256 /* maddr_q.w */, Mips::MADDR_Q_W, Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4266 /* maddu */, Mips::MADDU, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4266 /* maddu */, Mips::MADDU_MM, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4266 /* maddu */, Mips::MADDU_DSP, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4272 /* maddv.b */, Mips::MADDV_B, Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 4280 /* maddv.d */, Mips::MADDV_D, Convert__MSA128DAsm1_0__Tie0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 4288 /* maddv.h */, Mips::MADDV_H, Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4296 /* maddv.w */, Mips::MADDV_W, Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4304 /* maq_s.w.phl */, Mips::MAQ_S_W_PHL, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4316 /* maq_s.w.phr */, Mips::MAQ_S_W_PHR, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4328 /* maq_sa.w.phl */, Mips::MAQ_SA_W_PHL, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4341 /* maq_sa.w.phr */, Mips::MAQ_SA_W_PHR, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4354 /* max_a.b */, Mips::MAX_A_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 4362 /* max_a.d */, Mips::MAX_A_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 4370 /* max_a.h */, Mips::MAX_A_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4378 /* max_a.w */, Mips::MAX_A_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4386 /* max_s.b */, Mips::MAX_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 4394 /* max_s.d */, Mips::MAX_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 4402 /* max_s.h */, Mips::MAX_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4410 /* max_s.w */, Mips::MAX_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4418 /* max_u.b */, Mips::MAX_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 4426 /* max_u.d */, Mips::MAX_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 4434 /* max_u.h */, Mips::MAX_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4442 /* max_u.w */, Mips::MAX_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4450 /* maxi_s.b */, Mips::MAXI_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 4459 /* maxi_s.d */, Mips::MAXI_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 4468 /* maxi_s.h */, Mips::MAXI_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 4477 /* maxi_s.w */, Mips::MAXI_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 4486 /* maxi_u.b */, Mips::MAXI_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 4495 /* maxi_u.d */, Mips::MAXI_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 4504 /* maxi_u.h */, Mips::MAXI_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 4513 /* maxi_u.w */, Mips::MAXI_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 4522 /* mfc0 */, Mips::MFC0, Convert__GPR32Asm1_0__GPR32Asm1_1__imm_0, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4522 /* mfc0 */, Mips::MFC0, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 4527 /* mfc1 */, Mips::MFC1, Convert__GPR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_FGR32Asm }, },
  { 4532 /* mfc2 */, Mips::MFC2, Convert__GPR32Asm1_0__GPR32Asm1_1__imm_0, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4532 /* mfc2 */, Mips::MFC2, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 4537 /* mfhc1 */, Mips::MFHC1, Convert__GPR32Asm1_0__FGRH32Asm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_FGRH32Asm }, },
  { 4543 /* mfhi */, Mips::Mfhi16, Convert__Reg1_0, Feature_InMips16Mode, { MCK_CPU16Regs }, },
  { 4543 /* mfhi */, Mips::MFHI, Convert__GPR32Asm1_0, Feature_HasStdEnc, { MCK_GPR32Asm }, },
  { 4543 /* mfhi */, Mips::MFHI_MM, Convert__GPR32Asm1_0, Feature_InMicroMips, { MCK_GPR32Asm }, },
  { 4543 /* mfhi */, Mips::MFHI_DSP, Convert__GPR32Asm1_0__ACC64DSPAsm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm }, },
  { 4548 /* mflo */, Mips::Mflo16, Convert__Reg1_0, Feature_InMips16Mode, { MCK_CPU16Regs }, },
  { 4548 /* mflo */, Mips::MFLO, Convert__GPR32Asm1_0, Feature_HasStdEnc, { MCK_GPR32Asm }, },
  { 4548 /* mflo */, Mips::MFLO_MM, Convert__GPR32Asm1_0, Feature_InMicroMips, { MCK_GPR32Asm }, },
  { 4548 /* mflo */, Mips::MFLO_DSP, Convert__GPR32Asm1_0__ACC64DSPAsm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm }, },
  { 4553 /* min_a.b */, Mips::MIN_A_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 4561 /* min_a.d */, Mips::MIN_A_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 4569 /* min_a.h */, Mips::MIN_A_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4577 /* min_a.w */, Mips::MIN_A_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4585 /* min_s.b */, Mips::MIN_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 4593 /* min_s.d */, Mips::MIN_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 4601 /* min_s.h */, Mips::MIN_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4609 /* min_s.w */, Mips::MIN_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4617 /* min_u.b */, Mips::MIN_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 4625 /* min_u.d */, Mips::MIN_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 4633 /* min_u.h */, Mips::MIN_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4641 /* min_u.w */, Mips::MIN_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4649 /* mini_s.b */, Mips::MINI_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 4658 /* mini_s.d */, Mips::MINI_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 4667 /* mini_s.h */, Mips::MINI_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 4676 /* mini_s.w */, Mips::MINI_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 4685 /* mini_u.b */, Mips::MINI_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 4694 /* mini_u.d */, Mips::MINI_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 4703 /* mini_u.h */, Mips::MINI_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 4712 /* mini_u.w */, Mips::MINI_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 4721 /* mod_s.b */, Mips::MOD_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 4729 /* mod_s.d */, Mips::MOD_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 4737 /* mod_s.h */, Mips::MOD_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4745 /* mod_s.w */, Mips::MOD_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4753 /* mod_u.b */, Mips::MOD_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 4761 /* mod_u.d */, Mips::MOD_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 4769 /* mod_u.h */, Mips::MOD_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4777 /* mod_u.w */, Mips::MOD_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4785 /* modsub */, Mips::MODSUB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4792 /* mov.d */, Mips::FMOV_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 4792 /* mov.d */, Mips::FMOV_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 4798 /* mov.s */, Mips::FMOV_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 4804 /* move */, Mips::MoveR3216, Convert__Reg1_0__Reg1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_DSPR }, },
  { 4804 /* move */, Mips::Move32R16, Convert__Reg1_0__Reg1_1, Feature_InMips16Mode, { MCK_DSPR, MCK_CPU16Regs }, },
  { 4804 /* move */, Mips::ADDu, Convert__GPR32Asm1_0__GPR32Asm1_1__regZERO, Feature_NotMips64, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4804 /* move */, Mips::DADDu, Convert__GPR64Asm1_0__GPR64Asm1_1__regZERO_64, Feature_HasMips64, { MCK_GPR64Asm, MCK_GPR64Asm }, },
  { 4809 /* move.v */, Mips::MOVE_V, Convert__MSA128BAsm1_0__MSA128BAsm1_1, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 4816 /* movf */, Mips::MOVF_I, Convert__GPR32Asm1_0__GPR32Asm1_1__FCCRegsAsm1_2__Tie0, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_FCCRegsAsm }, },
  { 4816 /* movf */, Mips::MOVF_I_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__FCCRegsAsm1_2__Tie0, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_FCCRegsAsm }, },
  { 4821 /* movf.d */, Mips::MOVF_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1__FCCRegsAsm1_2__Tie0, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_FCCRegsAsm }, },
  { 4821 /* movf.d */, Mips::MOVF_D64, Convert__FGR64Asm1_0__FGR64Asm1_1__FCCRegsAsm1_2__Tie0, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm, MCK_FCCRegsAsm }, },
  { 4828 /* movf.s */, Mips::MOVF_S, Convert__FGR32Asm1_0__FGR32Asm1_1__FCCRegsAsm1_2__Tie0, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm, MCK_FCCRegsAsm }, },
  { 4835 /* movn */, Mips::MOVN_I_I, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4835 /* movn */, Mips::MOVN_I_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4840 /* movn.d */, Mips::MOVN_I_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1__GPR32Asm1_2__Tie0, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_GPR32Asm }, },
  { 4840 /* movn.d */, Mips::MOVN_I_D64, Convert__FGR64Asm1_0__FGR64Asm1_1__GPR32Asm1_2__Tie0, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm, MCK_GPR32Asm }, },
  { 4847 /* movn.s */, Mips::MOVN_I_S, Convert__FGR32Asm1_0__FGR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm, MCK_GPR32Asm }, },
  { 4854 /* movt */, Mips::MOVT_I, Convert__GPR32Asm1_0__GPR32Asm1_1__FCCRegsAsm1_2__Tie0, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_FCCRegsAsm }, },
  { 4854 /* movt */, Mips::MOVT_I_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__FCCRegsAsm1_2__Tie0, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_FCCRegsAsm }, },
  { 4859 /* movt.d */, Mips::MOVT_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1__FCCRegsAsm1_2__Tie0, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_FCCRegsAsm }, },
  { 4859 /* movt.d */, Mips::MOVT_D64, Convert__FGR64Asm1_0__FGR64Asm1_1__FCCRegsAsm1_2__Tie0, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm, MCK_FCCRegsAsm }, },
  { 4866 /* movt.s */, Mips::MOVT_S, Convert__FGR32Asm1_0__FGR32Asm1_1__FCCRegsAsm1_2__Tie0, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm, MCK_FCCRegsAsm }, },
  { 4873 /* movz */, Mips::MOVZ_I_I, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4873 /* movz */, Mips::MOVZ_I_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4878 /* movz.d */, Mips::MOVZ_I_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1__GPR32Asm1_2__Tie0, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_GPR32Asm }, },
  { 4878 /* movz.d */, Mips::MOVZ_I_D64, Convert__FGR64Asm1_0__FGR64Asm1_1__GPR32Asm1_2__Tie0, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm, MCK_GPR32Asm }, },
  { 4885 /* movz.s */, Mips::MOVZ_I_S, Convert__FGR32Asm1_0__FGR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm, MCK_GPR32Asm }, },
  { 4892 /* msub */, Mips::MSUB, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4892 /* msub */, Mips::MSUB_MM, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4892 /* msub */, Mips::MSUB_DSP, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4897 /* msub.d */, Mips::MSUB_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1__AFGR64Asm1_2__AFGR64Asm1_3, Feature_HasMips32r2|Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 4904 /* msub.s */, Mips::MSUB_S, Convert__FGR32Asm1_0__FGR32Asm1_1__FGR32Asm1_2__FGR32Asm1_3, Feature_HasMips32r2|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm, MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 4911 /* msub_q.h */, Mips::MSUB_Q_H, Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4920 /* msub_q.w */, Mips::MSUB_Q_W, Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4929 /* msubr_q.h */, Mips::MSUBR_Q_H, Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4939 /* msubr_q.w */, Mips::MSUBR_Q_W, Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4949 /* msubu */, Mips::MSUBU, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4949 /* msubu */, Mips::MSUBU_MM, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4949 /* msubu */, Mips::MSUBU_DSP, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4955 /* msubv.b */, Mips::MSUBV_B, Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 4963 /* msubv.d */, Mips::MSUBV_D, Convert__MSA128DAsm1_0__Tie0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 4971 /* msubv.h */, Mips::MSUBV_H, Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 4979 /* msubv.w */, Mips::MSUBV_W, Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 4987 /* mtc0 */, Mips::MTC0, Convert__GPR32Asm1_0__GPR32Asm1_1__imm_0, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4987 /* mtc0 */, Mips::MTC0, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 4992 /* mtc1 */, Mips::MTC1, Convert__FGR32Asm1_1__GPR32Asm1_0, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_FGR32Asm }, },
  { 4997 /* mtc2 */, Mips::MTC2, Convert__GPR32Asm1_0__GPR32Asm1_1__imm_0, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 4997 /* mtc2 */, Mips::MTC2, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 5002 /* mthc1 */, Mips::MTHC1, Convert__FGRH32Asm1_1__GPR32Asm1_0, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_FGRH32Asm }, },
  { 5008 /* mthi */, Mips::MTHI, Convert__GPR32Asm1_0, Feature_HasStdEnc, { MCK_GPR32Asm }, },
  { 5008 /* mthi */, Mips::MTHI_MM, Convert__GPR32Asm1_0, Feature_InMicroMips, { MCK_GPR32Asm }, },
  { 5008 /* mthi */, Mips::MTHI_DSP, Convert__HI32DSPAsm1_1__GPR32Asm1_0, Feature_HasDSP, { MCK_GPR32Asm, MCK_HI32DSPAsm }, },
  { 5013 /* mthlip */, Mips::MTHLIP, Convert__ACC64DSPAsm1_1__GPR32Asm1_0__Tie0, Feature_HasDSP, { MCK_GPR32Asm, MCK_ACC64DSPAsm }, },
  { 5020 /* mtlo */, Mips::MTLO, Convert__GPR32Asm1_0, Feature_HasStdEnc, { MCK_GPR32Asm }, },
  { 5020 /* mtlo */, Mips::MTLO_MM, Convert__GPR32Asm1_0, Feature_InMicroMips, { MCK_GPR32Asm }, },
  { 5020 /* mtlo */, Mips::MTLO_DSP, Convert__LO32DSPAsm1_1__GPR32Asm1_0, Feature_HasDSP, { MCK_GPR32Asm, MCK_LO32DSPAsm }, },
  { 5025 /* mul */, Mips::MUL, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5025 /* mul */, Mips::MUL_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5029 /* mul.d */, Mips::FMUL_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1__AFGR64Asm1_2, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 5029 /* mul.d */, Mips::FMUL_D64, Convert__FGR64Asm1_0__FGR64Asm1_1__FGR64Asm1_2, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 5035 /* mul.ph */, Mips::MUL_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5042 /* mul.s */, Mips::FMUL_S, Convert__FGR32Asm1_0__FGR32Asm1_1__FGR32Asm1_2, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 5048 /* mul_q.h */, Mips::MUL_Q_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 5056 /* mul_q.w */, Mips::MUL_Q_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 5064 /* mul_s.ph */, Mips::MUL_S_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5073 /* muleq_s.w.phl */, Mips::MULEQ_S_W_PHL, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5087 /* muleq_s.w.phr */, Mips::MULEQ_S_W_PHR, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5101 /* muleu_s.ph.qbl */, Mips::MULEU_S_PH_QBL, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5116 /* muleu_s.ph.qbr */, Mips::MULEU_S_PH_QBR, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5131 /* mulq_rs.ph */, Mips::MULQ_RS_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5142 /* mulq_rs.w */, Mips::MULQ_RS_W, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5152 /* mulq_s.ph */, Mips::MULQ_S_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5162 /* mulq_s.w */, Mips::MULQ_S_W, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5171 /* mulr_q.h */, Mips::MULR_Q_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 5180 /* mulr_q.w */, Mips::MULR_Q_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 5189 /* mulsa.w.ph */, Mips::MULSA_W_PH, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSPR2, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5200 /* mulsaq_s.w.ph */, Mips::MULSAQ_S_W_PH, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5214 /* mult */, Mips::MULT, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5214 /* mult */, Mips::MULT_MM, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5214 /* mult */, Mips::MULT_DSP, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5219 /* multu */, Mips::MULTu, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5219 /* multu */, Mips::MULTu_MM, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5219 /* multu */, Mips::MULTU_DSP, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5225 /* mulv.b */, Mips::MULV_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 5232 /* mulv.d */, Mips::MULV_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 5239 /* mulv.h */, Mips::MULV_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 5246 /* mulv.w */, Mips::MULV_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 5253 /* neg */, Mips::NegRxRy16, Convert__Reg1_0__Reg1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 5253 /* neg */, Mips::SUB, Convert__GPR32Asm1_0__regZERO__GPR32Asm1_1, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5257 /* neg.d */, Mips::FNEG_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 5257 /* neg.d */, Mips::FNEG_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 5263 /* neg.s */, Mips::FNEG_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 5269 /* negu */, Mips::SUBu, Convert__GPR32Asm1_0__regZERO__GPR32Asm1_1, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5274 /* nloc.b */, Mips::NLOC_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 5281 /* nloc.d */, Mips::NLOC_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 5288 /* nloc.h */, Mips::NLOC_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 5295 /* nloc.w */, Mips::NLOC_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 5302 /* nlzc.b */, Mips::NLZC_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 5309 /* nlzc.d */, Mips::NLZC_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 5316 /* nlzc.h */, Mips::NLZC_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 5323 /* nlzc.w */, Mips::NLZC_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 5330 /* nmadd.d */, Mips::NMADD_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1__AFGR64Asm1_2__AFGR64Asm1_3, Feature_HasMips32r2|Feature_NotFP64bit|Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 5338 /* nmadd.s */, Mips::NMADD_S, Convert__FGR32Asm1_0__FGR32Asm1_1__FGR32Asm1_2__FGR32Asm1_3, Feature_HasMips32r2|Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm, MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 5346 /* nmsub.d */, Mips::NMSUB_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1__AFGR64Asm1_2__AFGR64Asm1_3, Feature_HasMips32r2|Feature_NotFP64bit|Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 5354 /* nmsub.s */, Mips::NMSUB_S, Convert__FGR32Asm1_0__FGR32Asm1_1__FGR32Asm1_2__FGR32Asm1_3, Feature_HasMips32r2|Feature_NoNaNsFPMath|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm, MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 5362 /* nop */, Mips::SLL, Convert__regZERO__regZERO__imm_0, 0, {  }, },
  { 5366 /* nor */, Mips::NOR, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5366 /* nor */, Mips::NOR_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5370 /* nor.v */, Mips::NOR_V, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 5376 /* nori.b */, Mips::NORI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 5383 /* not */, Mips::NotRxRy16, Convert__Reg1_0__Reg1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 5383 /* not */, Mips::NOR, Convert__GPR32Asm1_0__GPR32Asm1_1__regZERO, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5387 /* or */, Mips::OrRxRxRy16, Convert__Reg1_0__Tie0__Reg1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 5387 /* or */, Mips::OR, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5387 /* or */, Mips::OR_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5387 /* or */, Mips::ORi, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, 0, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 5390 /* or.v */, Mips::OR_V, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 5395 /* ori */, Mips::ORi, Convert__GPR32Asm1_0__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 5395 /* ori */, Mips::ORi_MM, Convert__GPR32Asm1_0__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 5395 /* ori */, Mips::ORi, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 5395 /* ori */, Mips::ORi_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 5399 /* ori.b */, Mips::ORI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 5405 /* packrl.ph */, Mips::PACKRL_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5415 /* pckev.b */, Mips::PCKEV_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 5423 /* pckev.d */, Mips::PCKEV_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 5431 /* pckev.h */, Mips::PCKEV_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 5439 /* pckev.w */, Mips::PCKEV_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 5447 /* pckod.b */, Mips::PCKOD_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 5455 /* pckod.d */, Mips::PCKOD_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 5463 /* pckod.h */, Mips::PCKOD_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 5471 /* pckod.w */, Mips::PCKOD_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 5479 /* pcnt.b */, Mips::PCNT_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 5486 /* pcnt.d */, Mips::PCNT_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 5493 /* pcnt.h */, Mips::PCNT_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 5500 /* pcnt.w */, Mips::PCNT_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 5507 /* pick.ph */, Mips::PICK_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5515 /* pick.qb */, Mips::PICK_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5523 /* preceq.w.phl */, Mips::PRECEQ_W_PHL, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5536 /* preceq.w.phr */, Mips::PRECEQ_W_PHR, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5549 /* precequ.ph.qbl */, Mips::PRECEQU_PH_QBL, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5564 /* precequ.ph.qbla */, Mips::PRECEQU_PH_QBLA, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5580 /* precequ.ph.qbr */, Mips::PRECEQU_PH_QBR, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5595 /* precequ.ph.qbra */, Mips::PRECEQU_PH_QBRA, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5611 /* preceu.ph.qbl */, Mips::PRECEU_PH_QBL, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5625 /* preceu.ph.qbla */, Mips::PRECEU_PH_QBLA, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5640 /* preceu.ph.qbr */, Mips::PRECEU_PH_QBR, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5654 /* preceu.ph.qbra */, Mips::PRECEU_PH_QBRA, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5669 /* precr.qb.ph */, Mips::PRECR_QB_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5681 /* precr_sra.ph.w */, Mips::PRECR_SRA_PH_W, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Tie0, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 5696 /* precr_sra_r.ph.w */, Mips::PRECR_SRA_R_PH_W, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Tie0, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 5713 /* precrq.ph.w */, Mips::PRECRQ_PH_W, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5725 /* precrq.qb.ph */, Mips::PRECRQ_QB_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5738 /* precrq_rs.ph.w */, Mips::PRECRQ_RS_PH_W, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5753 /* precrqu_s.qb.ph */, Mips::PRECRQU_S_QB_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5769 /* prepend */, Mips::PREPEND, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2__Tie0, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 5777 /* raddu.w.qb */, Mips::RADDU_W_QB, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5788 /* rddsp */, Mips::RDDSP, Convert__GPR32Asm1_0__Imm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_Imm }, },
  { 5794 /* rdhwr */, Mips::RDHWR, Convert__GPR32Asm1_0__HWRegsAsm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_HWRegsAsm }, },
  { 5800 /* repl.ph */, Mips::REPL_PH, Convert__GPR32Asm1_0__Imm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_Imm }, },
  { 5808 /* repl.qb */, Mips::REPL_QB, Convert__GPR32Asm1_0__Imm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_Imm }, },
  { 5816 /* replv.ph */, Mips::REPLV_PH, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5825 /* replv.qb */, Mips::REPLV_QB, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5834 /* rotr */, Mips::ROTR, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasMips32r2|Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 5834 /* rotr */, Mips::ROTR_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 5839 /* rotrv */, Mips::ROTRV, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasMips32r2|Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5839 /* rotrv */, Mips::ROTRV_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5845 /* round.l.d */, Mips::ROUND_L_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 5855 /* round.l.s */, Mips::ROUND_L_S, Convert__FGR64Asm1_0__FGR32Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR32Asm }, },
  { 5865 /* round.w.d */, Mips::ROUND_W_D32, Convert__FGR32Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_AFGR64Asm }, },
  { 5865 /* round.w.d */, Mips::ROUND_W_D64, Convert__FGR32Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR64Asm }, },
  { 5875 /* round.w.s */, Mips::ROUND_W_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 5885 /* sat_s.b */, Mips::SAT_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 5893 /* sat_s.d */, Mips::SAT_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 5901 /* sat_s.h */, Mips::SAT_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 5909 /* sat_s.w */, Mips::SAT_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 5917 /* sat_u.b */, Mips::SAT_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 5925 /* sat_u.d */, Mips::SAT_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 5933 /* sat_u.h */, Mips::SAT_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 5941 /* sat_u.w */, Mips::SAT_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 5949 /* sb */, Mips::SB, Convert__GPR32Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Mem }, },
  { 5949 /* sb */, Mips::SB_MM, Convert__GPR32Asm1_0__Mem2_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 5949 /* sb */, Mips::SbRxRyOffMemX16, Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm, MCK_CPU16RegsPlusSP }, },
  { 5952 /* sc */, Mips::SC, Convert__GPR32Asm1_0__Tie0__Mem2_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Mem }, },
  { 5955 /* scd */, Mips::SCD, Convert__GPR64Asm1_0__Tie0__Mem2_1, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_Mem }, },
  { 5959 /* sd */, Mips::SD, Convert__GPR64Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_Mem }, },
  { 5962 /* sdc1 */, Mips::SDC1, Convert__AFGR64Asm1_0__Mem2_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_Mem }, },
  { 5962 /* sdc1 */, Mips::SDC164, Convert__FGR64Asm1_0__Mem2_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_Mem }, },
  { 5967 /* sdc2 */, Mips::SDC2, Convert__COP2Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_COP2Asm, MCK_Mem }, },
  { 5972 /* sdl */, Mips::SDL, Convert__GPR64Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_Mem }, },
  { 5976 /* sdr */, Mips::SDR, Convert__GPR64Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR64Asm, MCK_Mem }, },
  { 5980 /* sdxc1 */, Mips::SDXC1, Convert__AFGR64Asm1_0__PtrReg1_3__PtrReg1_1, Feature_HasFPIdx|Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_PtrReg, MCK__40_, MCK_PtrReg, MCK__41_ }, },
  { 5980 /* sdxc1 */, Mips::SDXC164, Convert__FGR64Asm1_0__PtrReg1_3__PtrReg1_1, Feature_HasFPIdx|Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_PtrReg, MCK__40_, MCK_PtrReg, MCK__41_ }, },
  { 5986 /* seb */, Mips::SebRx16, Convert__Reg1_0__Tie0, Feature_InMips16Mode, { MCK_CPU16Regs }, },
  { 5986 /* seb */, Mips::SEB, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasSEInReg|Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5986 /* seb */, Mips::SEB_MM, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5990 /* seh */, Mips::SehRx16, Convert__Reg1_0__Tie0, Feature_InMips16Mode, { MCK_CPU16Regs }, },
  { 5990 /* seh */, Mips::SEH, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasSEInReg|Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5990 /* seh */, Mips::SEH_MM, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 5994 /* sh */, Mips::SH, Convert__GPR32Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Mem }, },
  { 5994 /* sh */, Mips::SH_MM, Convert__GPR32Asm1_0__Mem2_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 5994 /* sh */, Mips::ShRxRyOffMemX16, Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm, MCK_CPU16RegsPlusSP }, },
  { 5997 /* shf.b */, Mips::SHF_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 6003 /* shf.h */, Mips::SHF_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 6009 /* shf.w */, Mips::SHF_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 6015 /* shilo */, Mips::SHILO, Convert__ACC64DSPAsm1_0__Imm1_1__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_Imm }, },
  { 6021 /* shilov */, Mips::SHILOV, Convert__ACC64DSPAsm1_0__GPR32Asm1_1__Tie0, Feature_HasDSP, { MCK_ACC64DSPAsm, MCK_GPR32Asm }, },
  { 6028 /* shll.ph */, Mips::SHLL_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6036 /* shll.qb */, Mips::SHLL_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6044 /* shll_s.ph */, Mips::SHLL_S_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6054 /* shll_s.w */, Mips::SHLL_S_W, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6063 /* shllv.ph */, Mips::SHLLV_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6072 /* shllv.qb */, Mips::SHLLV_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6081 /* shllv_s.ph */, Mips::SHLLV_S_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6092 /* shllv_s.w */, Mips::SHLLV_S_W, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6102 /* shra.ph */, Mips::SHRA_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6110 /* shra.qb */, Mips::SHRA_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6118 /* shra_r.ph */, Mips::SHRA_R_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6128 /* shra_r.qb */, Mips::SHRA_R_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6138 /* shra_r.w */, Mips::SHRA_R_W, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6147 /* shrav.ph */, Mips::SHRAV_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6156 /* shrav.qb */, Mips::SHRAV_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6165 /* shrav_r.ph */, Mips::SHRAV_R_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6176 /* shrav_r.qb */, Mips::SHRAV_R_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6187 /* shrav_r.w */, Mips::SHRAV_R_W, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6197 /* shrl.ph */, Mips::SHRL_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6205 /* shrl.qb */, Mips::SHRL_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6213 /* shrlv.ph */, Mips::SHRLV_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6222 /* shrlv.qb */, Mips::SHRLV_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6231 /* sld.b */, Mips::SLD_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Reg1_3, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK__91_, MCK_DSPR, MCK__93_ }, },
  { 6237 /* sld.d */, Mips::SLD_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Reg1_3, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK__91_, MCK_DSPR, MCK__93_ }, },
  { 6243 /* sld.h */, Mips::SLD_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Reg1_3, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK__91_, MCK_DSPR, MCK__93_ }, },
  { 6249 /* sld.w */, Mips::SLD_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Reg1_3, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK__91_, MCK_DSPR, MCK__93_ }, },
  { 6255 /* sldi.b */, Mips::SLDI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_3, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 6262 /* sldi.d */, Mips::SLDI_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_3, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 6269 /* sldi.h */, Mips::SLDI_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_3, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 6276 /* sldi.w */, Mips::SLDI_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_3, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 6283 /* sll */, Mips::SllX16, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm }, },
  { 6283 /* sll */, Mips::SLL, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6283 /* sll */, Mips::SLL_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6287 /* sll.b */, Mips::SLL_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 6293 /* sll.d */, Mips::SLL_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 6299 /* sll.h */, Mips::SLL_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 6305 /* sll.w */, Mips::SLL_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 6311 /* slli.b */, Mips::SLLI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 6318 /* slli.d */, Mips::SLLI_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 6325 /* slli.h */, Mips::SLLI_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 6332 /* slli.w */, Mips::SLLI_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 6339 /* sllv */, Mips::SllvRxRy16, Convert__Reg1_0__Tie0__Reg1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 6339 /* sllv */, Mips::SLLV, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6339 /* sllv */, Mips::SLLV_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6344 /* slt */, Mips::SltRxRy16, Convert__Reg1_0__Reg1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 6344 /* slt */, Mips::SLT, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6344 /* slt */, Mips::SLT_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6344 /* slt */, Mips::SLTi, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, 0, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6348 /* slti */, Mips::SltiRxImmX16, Convert__Reg1_0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm }, },
  { 6348 /* slti */, Mips::SLTi, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6348 /* slti */, Mips::SLTi_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6348 /* slti */, Mips::SltiRxImm16, Convert__Reg1_0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm, MCK__35_, MCK_16, MCK_bit, MCK_inst }, },
  { 6353 /* sltiu */, Mips::SltiuRxImmX16, Convert__Reg1_0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm }, },
  { 6353 /* sltiu */, Mips::SLTiu, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6353 /* sltiu */, Mips::SLTiu_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6353 /* sltiu */, Mips::SltiuRxImm16, Convert__Reg1_0__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm, MCK__35_, MCK_16, MCK_bit, MCK_inst }, },
  { 6359 /* sltu */, Mips::SltuRxRy16, Convert__Reg1_0__Reg1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 6359 /* sltu */, Mips::SLTu, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6359 /* sltu */, Mips::SLTu_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6364 /* splat.b */, Mips::SPLAT_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Reg1_3, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK__91_, MCK_DSPR, MCK__93_ }, },
  { 6372 /* splat.d */, Mips::SPLAT_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Reg1_3, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK__91_, MCK_DSPR, MCK__93_ }, },
  { 6380 /* splat.h */, Mips::SPLAT_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Reg1_3, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK__91_, MCK_DSPR, MCK__93_ }, },
  { 6388 /* splat.w */, Mips::SPLAT_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Reg1_3, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK__91_, MCK_DSPR, MCK__93_ }, },
  { 6396 /* splati.b */, Mips::SPLATI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_3, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 6405 /* splati.d */, Mips::SPLATI_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_3, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 6414 /* splati.h */, Mips::SPLATI_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_3, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 6423 /* splati.w */, Mips::SPLATI_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_3, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK__91_, MCK_Imm, MCK__93_ }, },
  { 6432 /* sqrt.d */, Mips::FSQRT_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 6432 /* sqrt.d */, Mips::FSQRT_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 6439 /* sqrt.s */, Mips::FSQRT_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 6446 /* sra */, Mips::SraX16, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm }, },
  { 6446 /* sra */, Mips::SRA, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6446 /* sra */, Mips::SRA_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6450 /* sra.b */, Mips::SRA_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 6456 /* sra.d */, Mips::SRA_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 6462 /* sra.h */, Mips::SRA_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 6468 /* sra.w */, Mips::SRA_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 6474 /* srai.b */, Mips::SRAI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 6481 /* srai.d */, Mips::SRAI_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 6488 /* srai.h */, Mips::SRAI_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 6495 /* srai.w */, Mips::SRAI_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 6502 /* srar.b */, Mips::SRAR_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 6509 /* srar.d */, Mips::SRAR_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 6516 /* srar.h */, Mips::SRAR_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 6523 /* srar.w */, Mips::SRAR_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 6530 /* srari.b */, Mips::SRARI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 6538 /* srari.d */, Mips::SRARI_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 6546 /* srari.h */, Mips::SRARI_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 6554 /* srari.w */, Mips::SRARI_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 6562 /* srav */, Mips::SravRxRy16, Convert__Reg1_0__Tie0__Reg1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 6562 /* srav */, Mips::SRAV, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6562 /* srav */, Mips::SRAV_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6567 /* srl */, Mips::SrlX16, Convert__Reg1_0__Reg1_1__Imm1_2, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm }, },
  { 6567 /* srl */, Mips::SRL, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6567 /* srl */, Mips::SRL_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 6571 /* srl.b */, Mips::SRL_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 6577 /* srl.d */, Mips::SRL_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 6583 /* srl.h */, Mips::SRL_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 6589 /* srl.w */, Mips::SRL_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 6595 /* srli.b */, Mips::SRLI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 6602 /* srli.d */, Mips::SRLI_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 6609 /* srli.h */, Mips::SRLI_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 6616 /* srli.w */, Mips::SRLI_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 6623 /* srlr.b */, Mips::SRLR_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 6630 /* srlr.d */, Mips::SRLR_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 6637 /* srlr.h */, Mips::SRLR_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 6644 /* srlr.w */, Mips::SRLR_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 6651 /* srlri.b */, Mips::SRLRI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 6659 /* srlri.d */, Mips::SRLRI_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 6667 /* srlri.h */, Mips::SRLRI_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 6675 /* srlri.w */, Mips::SRLRI_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 6683 /* srlv */, Mips::SrlvRxRy16, Convert__Reg1_0__Tie0__Reg1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 6683 /* srlv */, Mips::SRLV, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6683 /* srlv */, Mips::SRLV_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6688 /* st.b */, Mips::ST_B, Convert__MSA128BAsm1_0__Mem2_1, Feature_HasMSA, { MCK_MSA128BAsm, MCK_Mem }, },
  { 6693 /* st.d */, Mips::ST_D, Convert__MSA128DAsm1_0__Mem2_1, Feature_HasMSA, { MCK_MSA128DAsm, MCK_Mem }, },
  { 6698 /* st.h */, Mips::ST_H, Convert__MSA128HAsm1_0__Mem2_1, Feature_HasMSA, { MCK_MSA128HAsm, MCK_Mem }, },
  { 6703 /* st.w */, Mips::ST_W, Convert__MSA128WAsm1_0__Mem2_1, Feature_HasMSA, { MCK_MSA128WAsm, MCK_Mem }, },
  { 6708 /* sub */, Mips::SUB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6708 /* sub */, Mips::SUB_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6708 /* sub */, Mips::ADDi, Convert__GPR32Asm1_0__GPR32Asm1_1__InvNum1_2, 0, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_InvNum }, },
  { 6712 /* sub.d */, Mips::FSUB_D32, Convert__AFGR64Asm1_0__AFGR64Asm1_1__AFGR64Asm1_2, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_AFGR64Asm, MCK_AFGR64Asm }, },
  { 6712 /* sub.d */, Mips::FSUB_D64, Convert__FGR64Asm1_0__FGR64Asm1_1__FGR64Asm1_2, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 6718 /* sub.s */, Mips::FSUB_S, Convert__FGR32Asm1_0__FGR32Asm1_1__FGR32Asm1_2, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 6724 /* subq.ph */, Mips::SUBQ_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6732 /* subq_s.ph */, Mips::SUBQ_S_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6742 /* subq_s.w */, Mips::SUBQ_S_W, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6751 /* subqh.ph */, Mips::SUBQH_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6760 /* subqh.w */, Mips::SUBQH_W, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6768 /* subqh_r.ph */, Mips::SUBQH_R_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6779 /* subqh_r.w */, Mips::SUBQH_R_W, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6789 /* subs_s.b */, Mips::SUBS_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 6798 /* subs_s.d */, Mips::SUBS_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 6807 /* subs_s.h */, Mips::SUBS_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 6816 /* subs_s.w */, Mips::SUBS_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 6825 /* subs_u.b */, Mips::SUBS_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 6834 /* subs_u.d */, Mips::SUBS_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 6843 /* subs_u.h */, Mips::SUBS_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 6852 /* subs_u.w */, Mips::SUBS_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 6861 /* subsus_u.b */, Mips::SUBSUS_U_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 6872 /* subsus_u.d */, Mips::SUBSUS_U_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 6883 /* subsus_u.h */, Mips::SUBSUS_U_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 6894 /* subsus_u.w */, Mips::SUBSUS_U_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 6905 /* subsuu_s.b */, Mips::SUBSUU_S_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 6916 /* subsuu_s.d */, Mips::SUBSUU_S_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 6927 /* subsuu_s.h */, Mips::SUBSUU_S_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 6938 /* subsuu_s.w */, Mips::SUBSUU_S_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 6949 /* subu */, Mips::SubuRxRyRz16, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 6949 /* subu */, Mips::SUBu, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6949 /* subu */, Mips::SUBu_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6949 /* subu */, Mips::ADDiu, Convert__GPR32Asm1_0__GPR32Asm1_1__InvNum1_2, 0, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_InvNum }, },
  { 6954 /* subu.ph */, Mips::SUBU_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6962 /* subu.qb */, Mips::SUBU_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6970 /* subu_s.ph */, Mips::SUBU_S_PH, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6980 /* subu_s.qb */, Mips::SUBU_S_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSP, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6990 /* subuh.qb */, Mips::SUBUH_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 6999 /* subuh_r.qb */, Mips::SUBUH_R_QB, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasDSPR2, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 7010 /* subv.b */, Mips::SUBV_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 7017 /* subv.d */, Mips::SUBV_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 7024 /* subv.h */, Mips::SUBV_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 7031 /* subv.w */, Mips::SUBV_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 7038 /* subvi.b */, Mips::SUBVI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
  { 7046 /* subvi.d */, Mips::SUBVI_D, Convert__MSA128DAsm1_0__MSA128DAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_Imm }, },
  { 7054 /* subvi.h */, Mips::SUBVI_H, Convert__MSA128HAsm1_0__MSA128HAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_Imm }, },
  { 7062 /* subvi.w */, Mips::SUBVI_W, Convert__MSA128WAsm1_0__MSA128WAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_Imm }, },
  { 7070 /* suxc1 */, Mips::SUXC1, Convert__AFGR64Asm1_0__PtrReg1_3__PtrReg1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_AFGR64Asm, MCK_PtrReg, MCK__40_, MCK_PtrReg, MCK__41_ }, },
  { 7070 /* suxc1 */, Mips::SUXC164, Convert__FGR64Asm1_0__PtrReg1_3__PtrReg1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_PtrReg, MCK__40_, MCK_PtrReg, MCK__41_ }, },
  { 7076 /* sw */, Mips::SW, Convert__GPR32Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Mem }, },
  { 7076 /* sw */, Mips::SW_MM, Convert__GPR32Asm1_0__Mem2_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 7076 /* sw */, Mips::SwRxRyOffMemX16, Convert__Reg1_0__Reg1_1__Imm1_2__Reg1_3, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs, MCK_Imm, MCK_CPU16RegsPlusSP }, },
  { 7076 /* sw */, Mips::SwRxSpImmX16, Convert__Reg1_0__Reg1_3__Imm1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_Imm, MCK__40_, MCK_CPUSPReg, MCK__41__59_ }, },
  { 7079 /* swc1 */, Mips::SWC1, Convert__FGR32Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_Mem }, },
  { 7084 /* swc2 */, Mips::SWC2, Convert__COP2Asm1_0__Mem2_1, Feature_HasStdEnc, { MCK_COP2Asm, MCK_Mem }, },
  { 7089 /* swl */, Mips::SWL, Convert__GPR32Asm1_0__Mem2_1, Feature_NotInMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 7089 /* swl */, Mips::SWL_MM, Convert__GPR32Asm1_0__Mem2_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 7093 /* swr */, Mips::SWR, Convert__GPR32Asm1_0__Mem2_1, Feature_NotInMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 7093 /* swr */, Mips::SWR_MM, Convert__GPR32Asm1_0__Mem2_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Mem }, },
  { 7097 /* swxc1 */, Mips::SWXC1, Convert__FGR32Asm1_0__PtrReg1_3__PtrReg1_1, Feature_HasFPIdx|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_PtrReg, MCK__40_, MCK_PtrReg, MCK__41_ }, },
  { 7103 /* sync */, Mips::SYNC, Convert__Imm1_0, Feature_HasStdEnc, { MCK_Imm }, },
  { 7108 /* syscall */, Mips::SYSCALL, Convert__imm_0, 0, {  }, },
  { 7108 /* syscall */, Mips::SYSCALL, Convert__Imm1_0, Feature_HasStdEnc, { MCK_Imm }, },
  { 7116 /* teq */, Mips::TEQ, Convert__GPR32Asm1_0__GPR32Asm1_1__imm_0, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 7116 /* teq */, Mips::TEQ, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7116 /* teq */, Mips::TEQ_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7120 /* teqi */, Mips::TEQI, Convert__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 7120 /* teqi */, Mips::TEQI_MM, Convert__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 7125 /* tge */, Mips::TGE, Convert__GPR32Asm1_0__GPR32Asm1_1__imm_0, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 7125 /* tge */, Mips::TGE, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7125 /* tge */, Mips::TGE_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7129 /* tgei */, Mips::TGEI, Convert__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 7129 /* tgei */, Mips::TGEI_MM, Convert__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 7134 /* tgeiu */, Mips::TGEIU, Convert__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 7134 /* tgeiu */, Mips::TGEIU_MM, Convert__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 7140 /* tgeu */, Mips::TGEU, Convert__GPR32Asm1_0__GPR32Asm1_1__imm_0, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 7140 /* tgeu */, Mips::TGEU, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7140 /* tgeu */, Mips::TGEU_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7145 /* tlt */, Mips::TLT, Convert__GPR32Asm1_0__GPR32Asm1_1__imm_0, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 7145 /* tlt */, Mips::TLT, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7145 /* tlt */, Mips::TLT_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7149 /* tlti */, Mips::TLTI, Convert__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 7149 /* tlti */, Mips::TLTI_MM, Convert__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 7154 /* tltiu */, Mips::TLTIU_MM, Convert__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 7154 /* tltiu */, Mips::TTLTIU, Convert__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 7160 /* tltu */, Mips::TLTU, Convert__GPR32Asm1_0__GPR32Asm1_1__imm_0, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 7160 /* tltu */, Mips::TLTU, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7160 /* tltu */, Mips::TLTU_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7165 /* tne */, Mips::TNE, Convert__GPR32Asm1_0__GPR32Asm1_1__imm_0, 0, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 7165 /* tne */, Mips::TNE, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7165 /* tne */, Mips::TNE_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7169 /* tnei */, Mips::TNEI, Convert__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 7169 /* tnei */, Mips::TNEI_MM, Convert__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 7174 /* trunc.l.d */, Mips::TRUNC_L_D64, Convert__FGR64Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR64Asm }, },
  { 7184 /* trunc.l.s */, Mips::TRUNC_L_S, Convert__FGR64Asm1_0__FGR32Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR64Asm, MCK_FGR32Asm }, },
  { 7194 /* trunc.w.d */, Mips::TRUNC_W_D32, Convert__FGR32Asm1_0__AFGR64Asm1_1, Feature_NotFP64bit|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_AFGR64Asm }, },
  { 7194 /* trunc.w.d */, Mips::TRUNC_W_D64, Convert__FGR32Asm1_0__FGR64Asm1_1, Feature_IsFP64bit|Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR64Asm }, },
  { 7204 /* trunc.w.s */, Mips::TRUNC_W_S, Convert__FGR32Asm1_0__FGR32Asm1_1, Feature_HasStdEnc, { MCK_FGR32Asm, MCK_FGR32Asm }, },
  { 7214 /* vshf.b */, Mips::VSHF_B, Convert__MSA128BAsm1_0__Tie0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 7221 /* vshf.d */, Mips::VSHF_D, Convert__MSA128DAsm1_0__Tie0__MSA128DAsm1_1__MSA128DAsm1_2, Feature_HasMSA, { MCK_MSA128DAsm, MCK_MSA128DAsm, MCK_MSA128DAsm }, },
  { 7228 /* vshf.h */, Mips::VSHF_H, Convert__MSA128HAsm1_0__Tie0__MSA128HAsm1_1__MSA128HAsm1_2, Feature_HasMSA, { MCK_MSA128HAsm, MCK_MSA128HAsm, MCK_MSA128HAsm }, },
  { 7235 /* vshf.w */, Mips::VSHF_W, Convert__MSA128WAsm1_0__Tie0__MSA128WAsm1_1__MSA128WAsm1_2, Feature_HasMSA, { MCK_MSA128WAsm, MCK_MSA128WAsm, MCK_MSA128WAsm }, },
  { 7242 /* wait */, Mips::WAIT, Convert_NoOperands, Feature_HasStdEnc, {  }, },
  { 7247 /* wrdsp */, Mips::WRDSP, Convert__GPR32Asm1_0__Imm1_1, Feature_HasDSP, { MCK_GPR32Asm, MCK_Imm }, },
  { 7253 /* wsbh */, Mips::WSBH, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_HasSwap|Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 7253 /* wsbh */, Mips::WSBH_MM, Convert__GPR32Asm1_0__GPR32Asm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 7258 /* xor */, Mips::XorRxRxRy16, Convert__Reg1_0__Tie0__Reg1_1, Feature_InMips16Mode, { MCK_CPU16Regs, MCK_CPU16Regs }, },
  { 7258 /* xor */, Mips::XOR, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 7258 /* xor */, Mips::XOR_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__GPR32Asm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_GPR32Asm }, },
  { 7258 /* xor */, Mips::XORi, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, 0, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7262 /* xor.v */, Mips::XOR_V, Convert__MSA128BAsm1_0__MSA128BAsm1_1__MSA128BAsm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_MSA128BAsm }, },
  { 7268 /* xori */, Mips::XORi, Convert__GPR32Asm1_0__GPR32Asm1_0__Imm1_1, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_Imm }, },
  { 7268 /* xori */, Mips::XORi_MM, Convert__GPR32Asm1_0__GPR32Asm1_0__Imm1_1, Feature_InMicroMips, { MCK_GPR32Asm, MCK_Imm }, },
  { 7268 /* xori */, Mips::XORi, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_HasStdEnc, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7268 /* xori */, Mips::XORi_MM, Convert__GPR32Asm1_0__GPR32Asm1_1__Imm1_2, Feature_InMicroMips, { MCK_GPR32Asm, MCK_GPR32Asm, MCK_Imm }, },
  { 7273 /* xori.b */, Mips::XORI_B, Convert__MSA128BAsm1_0__MSA128BAsm1_1__Imm1_2, Feature_HasMSA, { MCK_MSA128BAsm, MCK_MSA128BAsm, MCK_Imm }, },
};

bool MipsAsmParser::
mnemonicIsValid(StringRef Mnemonic, unsigned VariantID) {
  // Find the appropriate table for this asm variant.
  const MatchEntry *Start, *End;
  switch (VariantID) {
  default: // unreachable
  case 0: Start = MatchTable0; End = array_endof(MatchTable0); break;
  }
  // Search the table.
  std::pair<const MatchEntry*, const MatchEntry*> MnemonicRange =
    std::equal_range(Start, End, Mnemonic, LessOpcode());
  return MnemonicRange.first != MnemonicRange.second;
}

unsigned MipsAsmParser::
MatchInstructionImpl(const SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                     MCInst &Inst,
unsigned &ErrorInfo, bool matchingInlineAsm, unsigned VariantID) {
  // Eliminate obvious mismatches.
  if (Operands.size() > 9) {
    ErrorInfo = 9;
    return Match_InvalidOperand;
  }

  // Get the current feature set.
  unsigned AvailableFeatures = getAvailableFeatures();

  // Get the instruction mnemonic, which is the first token.
  StringRef Mnemonic = ((MipsOperand*)Operands[0])->getToken();

  // Some state to try to produce better error messages.
  bool HadMatchOtherThanFeatures = false;
  bool HadMatchOtherThanPredicate = false;
  unsigned RetCode = Match_InvalidOperand;
  unsigned MissingFeatures = ~0U;
  // Set ErrorInfo to the operand that mismatches if it is
  // wrong for all instances of the instruction.
  ErrorInfo = ~0U;
  // Find the appropriate table for this asm variant.
  const MatchEntry *Start, *End;
  switch (VariantID) {
  default: // unreachable
  case 0: Start = MatchTable0; End = array_endof(MatchTable0); break;
  }
  // Search the table.
  std::pair<const MatchEntry*, const MatchEntry*> MnemonicRange =
    std::equal_range(Start, End, Mnemonic, LessOpcode());

  // Return a more specific error code if no mnemonics match.
  if (MnemonicRange.first == MnemonicRange.second)
    return Match_MnemonicFail;

  for (const MatchEntry *it = MnemonicRange.first, *ie = MnemonicRange.second;
       it != ie; ++it) {
    // equal_range guarantees that instruction mnemonic matches.
    assert(Mnemonic == it->getMnemonic());
    bool OperandsValid = true;
    for (unsigned i = 0; i != 8; ++i) {
      if (i + 1 >= Operands.size()) {
        OperandsValid = (it->Classes[i] == InvalidMatchClass);
        if (!OperandsValid) ErrorInfo = i + 1;
        break;
      }
      unsigned Diag = validateOperandClass(Operands[i+1],
                                           (MatchClassKind)it->Classes[i]);
      if (Diag == Match_Success)
        continue;
      // If the generic handler indicates an invalid operand
      // failure, check for a special case.
      if (Diag == Match_InvalidOperand) {
        Diag = validateTargetOperandClass(Operands[i+1],
                                           (MatchClassKind)it->Classes[i]);
        if (Diag == Match_Success)
          continue;
      }
      // If this operand is broken for all of the instances of this
      // mnemonic, keep track of it so we can report loc info.
      // If we already had a match that only failed due to a
      // target predicate, that diagnostic is preferred.
      if (!HadMatchOtherThanPredicate &&
          (it == MnemonicRange.first || ErrorInfo <= i+1)) {
        ErrorInfo = i+1;
        // InvalidOperand is the default. Prefer specificity.
        if (Diag != Match_InvalidOperand)
          RetCode = Diag;
      }
      // Otherwise, just reject this instance of the mnemonic.
      OperandsValid = false;
      break;
    }

    if (!OperandsValid) continue;
    if ((AvailableFeatures & it->RequiredFeatures) != it->RequiredFeatures) {
      HadMatchOtherThanFeatures = true;
      unsigned NewMissingFeatures = it->RequiredFeatures & ~AvailableFeatures;
      if (CountPopulation_32(NewMissingFeatures) <=
          CountPopulation_32(MissingFeatures))
        MissingFeatures = NewMissingFeatures;
      continue;
    }

    if (matchingInlineAsm) {
      Inst.setOpcode(it->Opcode);
      convertToMapAndConstraints(it->ConvertFn, Operands);
      return Match_Success;
    }

    // We have selected a definite instruction, convert the parsed
    // operands into the appropriate MCInst.
    convertToMCInst(it->ConvertFn, Inst, it->Opcode, Operands);

    // We have a potential match. Check the target predicate to
    // handle any context sensitive constraints.
    unsigned MatchResult;
    if ((MatchResult = checkTargetMatchPredicate(Inst)) != Match_Success) {
      Inst.clear();
      RetCode = MatchResult;
      HadMatchOtherThanPredicate = true;
      continue;
    }

    return Match_Success;
  }

  // Okay, we had no match.  Try to return a useful error code.
  if (HadMatchOtherThanPredicate || !HadMatchOtherThanFeatures)
    return RetCode;

  // Missing feature matches return which features were missing
  ErrorInfo = MissingFeatures;
  return Match_MissingFeature;
}

namespace {
  struct OperandMatchEntry {
    uint32_t RequiredFeatures;
    uint16_t Mnemonic;
    uint8_t Class;
    uint8_t OperandMask;

    StringRef getMnemonic() const {
      return StringRef(MnemonicTable + Mnemonic + 1,
                       MnemonicTable[Mnemonic]);
    }
  };

  // Predicate for searching for an opcode.
  struct LessOpcodeOperand {
    bool operator()(const OperandMatchEntry &LHS, StringRef RHS) {
      return LHS.getMnemonic()  < RHS;
    }
    bool operator()(StringRef LHS, const OperandMatchEntry &RHS) {
      return LHS < RHS.getMnemonic();
    }
    bool operator()(const OperandMatchEntry &LHS, const OperandMatchEntry &RHS) {
      return LHS.getMnemonic() < RHS.getMnemonic();
    }
  };
} // end anonymous namespace.

static const OperandMatchEntry OperandMatchTable[1335] = {
  /* Operand List Mask, Mnemonic, Operand Class, Features */
  { Feature_NoNaNsFPMath|Feature_HasStdEnc, 0 /* abs.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_NoNaNsFPMath|Feature_HasStdEnc, 0 /* abs.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_NoNaNsFPMath|Feature_HasStdEnc, 6 /* abs.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 12 /* absq_s.ph */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSPR2, 22 /* absq_s.qb */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 32 /* absq_s.w */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 41 /* add */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 41 /* add */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { 0, 41 /* add */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 45 /* add.d */, MCK_AFGR64Asm, 7 /* 0, 1, 2 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 45 /* add.d */, MCK_FGR64Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 51 /* add.s */, MCK_FGR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 57 /* add_a.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 65 /* add_a.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 73 /* add_a.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 81 /* add_a.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 89 /* addi */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 89 /* addi */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 89 /* addi */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 89 /* addi */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 94 /* addiu */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 94 /* addiu */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 94 /* addiu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 94 /* addiu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 100 /* addq.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 108 /* addq_s.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 118 /* addq_s.w */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 127 /* addqh.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 136 /* addqh.w */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 144 /* addqh_r.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 155 /* addqh_r.w */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 165 /* adds_a.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 174 /* adds_a.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 183 /* adds_a.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 192 /* adds_a.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 201 /* adds_s.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 210 /* adds_s.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 219 /* adds_s.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 228 /* adds_s.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 237 /* adds_u.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 246 /* adds_u.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 255 /* adds_u.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 264 /* adds_u.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 273 /* addsc */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 279 /* addu */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 279 /* addu */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { 0, 279 /* addu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSPR2, 284 /* addu.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 292 /* addu.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 300 /* addu_s.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 310 /* addu_s.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 320 /* adduh.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 329 /* adduh_r.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 340 /* addv.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 347 /* addv.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 354 /* addv.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 361 /* addv.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 368 /* addvi.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 376 /* addvi.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 384 /* addvi.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 392 /* addvi.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 400 /* addwc */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 406 /* and */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 406 /* and */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { 0, 406 /* and */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 410 /* and.v */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 416 /* andi */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 416 /* andi */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 416 /* andi */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 416 /* andi */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 421 /* andi.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasDSPR2, 428 /* append */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 435 /* asub_s.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 444 /* asub_s.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 453 /* asub_s.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 462 /* asub_s.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 471 /* asub_u.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 480 /* asub_u.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 489 /* asub_u.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 498 /* asub_u.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 507 /* ave_s.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 515 /* ave_s.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 523 /* ave_s.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 531 /* ave_s.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 539 /* ave_u.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 547 /* ave_u.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 555 /* ave_u.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 563 /* ave_u.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 571 /* aver_s.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 580 /* aver_s.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 589 /* aver_s.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 598 /* aver_s.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 607 /* aver_u.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 616 /* aver_u.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 625 /* aver_u.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 634 /* aver_u.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 649 /* balign */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 656 /* bc1f */, MCK_FCCRegsAsm, 1 /* 0 */ },
  { Feature_HasStdEnc, 661 /* bc1t */, MCK_FCCRegsAsm, 1 /* 0 */ },
  { Feature_HasMSA, 666 /* bclr.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 673 /* bclr.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 680 /* bclr.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 687 /* bclr.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 694 /* bclri.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 702 /* bclri.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 710 /* bclri.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 718 /* bclri.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 726 /* beq */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 726 /* beq */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { 0, 730 /* beqz */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 735 /* bgez */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 735 /* bgez */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 740 /* bgezal */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 740 /* bgezal */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 747 /* bgtz */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 747 /* bgtz */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMSA, 752 /* binsl.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 760 /* binsl.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 768 /* binsl.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 776 /* binsl.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 784 /* binsli.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 793 /* binsli.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 802 /* binsli.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 811 /* binsli.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 820 /* binsr.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 828 /* binsr.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 836 /* binsr.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 844 /* binsr.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 852 /* binsri.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 861 /* binsri.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 870 /* binsri.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 879 /* binsri.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 888 /* bitrev */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 895 /* blez */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 895 /* blez */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 900 /* bltz */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 900 /* bltz */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 905 /* bltzal */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 905 /* bltzal */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMSA, 912 /* bmnz.v */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 919 /* bmnzi.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 927 /* bmz.v */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 933 /* bmzi.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 940 /* bne */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 940 /* bne */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 944 /* bneg.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 951 /* bneg.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 958 /* bneg.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 965 /* bneg.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 972 /* bnegi.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 980 /* bnegi.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 988 /* bnegi.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 996 /* bnegi.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { 0, 1004 /* bnez */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMSA, 1009 /* bnz.b */, MCK_MSA128BAsm, 1 /* 0 */ },
  { Feature_HasMSA, 1015 /* bnz.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 1021 /* bnz.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 1027 /* bnz.v */, MCK_MSA128BAsm, 1 /* 0 */ },
  { Feature_HasMSA, 1033 /* bnz.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 1054 /* bsel.v */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1061 /* bseli.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1069 /* bset.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1076 /* bset.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1083 /* bset.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1090 /* bset.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1097 /* bseti.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1105 /* bseti.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1113 /* bseti.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1121 /* bseti.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1141 /* bz.b */, MCK_MSA128BAsm, 1 /* 0 */ },
  { Feature_HasMSA, 1146 /* bz.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 1151 /* bz.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 1156 /* bz.v */, MCK_MSA128BAsm, 1 /* 0 */ },
  { Feature_HasMSA, 1161 /* bz.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1166 /* c.eq.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1166 /* c.eq.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1173 /* c.eq.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1180 /* c.f.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1180 /* c.f.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1186 /* c.f.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1192 /* c.le.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1192 /* c.le.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1199 /* c.le.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1206 /* c.lt.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1206 /* c.lt.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1213 /* c.lt.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1220 /* c.nge.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1220 /* c.nge.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1228 /* c.nge.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1236 /* c.ngl.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1236 /* c.ngl.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1244 /* c.ngl.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1252 /* c.ngle.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1252 /* c.ngle.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1261 /* c.ngle.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1270 /* c.ngt.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1270 /* c.ngt.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1278 /* c.ngt.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1286 /* c.ole.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1286 /* c.ole.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1294 /* c.ole.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1302 /* c.olt.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1302 /* c.olt.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1310 /* c.olt.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1318 /* c.seq.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1318 /* c.seq.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1326 /* c.seq.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1334 /* c.sf.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1334 /* c.sf.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1341 /* c.sf.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1348 /* c.ueq.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1348 /* c.ueq.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1356 /* c.ueq.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1364 /* c.ule.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1364 /* c.ule.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1372 /* c.ule.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1380 /* c.ult.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1380 /* c.ult.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1388 /* c.ult.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1396 /* c.un.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1396 /* c.un.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1403 /* c.un.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1410 /* ceil.l.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1419 /* ceil.l.s */, MCK_FGR32Asm, 2 /* 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1419 /* ceil.l.s */, MCK_FGR64Asm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1428 /* ceil.w.d */, MCK_AFGR64Asm, 2 /* 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 1428 /* ceil.w.d */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1428 /* ceil.w.d */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 1428 /* ceil.w.d */, MCK_FGR64Asm, 2 /* 1 */ },
  { Feature_HasStdEnc, 1437 /* ceil.w.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1446 /* ceq.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1452 /* ceq.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1458 /* ceq.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1464 /* ceq.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1470 /* ceqi.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1477 /* ceqi.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1484 /* ceqi.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1491 /* ceqi.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 1498 /* cfc1 */, MCK_CCRAsm, 2 /* 1 */ },
  { Feature_HasStdEnc, 1498 /* cfc1 */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMSA, 1503 /* cfcmsa */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMSA, 1503 /* cfcmsa */, MCK_MSA128CRAsm, 2 /* 1 */ },
  { Feature_HasMSA, 1510 /* cle_s.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1518 /* cle_s.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1526 /* cle_s.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1534 /* cle_s.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1542 /* cle_u.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1550 /* cle_u.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1558 /* cle_u.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1566 /* cle_u.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1574 /* clei_s.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1583 /* clei_s.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1592 /* clei_s.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1601 /* clei_s.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1610 /* clei_u.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1619 /* clei_u.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1628 /* clei_u.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1637 /* clei_u.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasBitCount|Feature_HasStdEnc, 1646 /* clo */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 1646 /* clo */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1650 /* clt_s.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1658 /* clt_s.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1666 /* clt_s.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1674 /* clt_s.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1682 /* clt_u.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1690 /* clt_u.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1698 /* clt_u.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1706 /* clt_u.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 1714 /* clti_s.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1723 /* clti_s.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1732 /* clti_s.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1741 /* clti_s.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1750 /* clti_u.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1759 /* clti_u.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1768 /* clti_u.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1777 /* clti_u.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasBitCount|Feature_HasStdEnc, 1786 /* clz */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 1786 /* clz */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 1794 /* cmp.eq.ph */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 1804 /* cmp.le.ph */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 1814 /* cmp.lt.ph */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSPR2, 1824 /* cmpgdu.eq.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 1837 /* cmpgdu.le.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 1850 /* cmpgdu.lt.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 1863 /* cmpgu.eq.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 1875 /* cmpgu.le.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 1887 /* cmpgu.lt.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 1904 /* cmpu.eq.qb */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 1915 /* cmpu.le.qb */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 1926 /* cmpu.lt.qb */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 1937 /* copy_s.b */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMSA, 1937 /* copy_s.b */, MCK_MSA128BAsm, 2 /* 1 */ },
  { Feature_HasMSA, 1946 /* copy_s.h */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMSA, 1946 /* copy_s.h */, MCK_MSA128HAsm, 2 /* 1 */ },
  { Feature_HasMSA, 1955 /* copy_s.w */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMSA, 1955 /* copy_s.w */, MCK_MSA128WAsm, 2 /* 1 */ },
  { Feature_HasMSA, 1964 /* copy_u.b */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMSA, 1964 /* copy_u.b */, MCK_MSA128BAsm, 2 /* 1 */ },
  { Feature_HasMSA, 1973 /* copy_u.h */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMSA, 1973 /* copy_u.h */, MCK_MSA128HAsm, 2 /* 1 */ },
  { Feature_HasMSA, 1982 /* copy_u.w */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMSA, 1982 /* copy_u.w */, MCK_MSA128WAsm, 2 /* 1 */ },
  { Feature_HasStdEnc, 1991 /* ctc1 */, MCK_CCRAsm, 2 /* 1 */ },
  { Feature_HasStdEnc, 1991 /* ctc1 */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMSA, 1996 /* ctcmsa */, MCK_GPR32Asm, 2 /* 1 */ },
  { Feature_HasMSA, 1996 /* ctcmsa */, MCK_MSA128CRAsm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 2003 /* cvt.d.l */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 2011 /* cvt.d.s */, MCK_AFGR64Asm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 2011 /* cvt.d.s */, MCK_FGR32Asm, 2 /* 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 2011 /* cvt.d.s */, MCK_FGR32Asm, 2 /* 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 2011 /* cvt.d.s */, MCK_FGR64Asm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 2019 /* cvt.d.w */, MCK_AFGR64Asm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 2019 /* cvt.d.w */, MCK_FGR32Asm, 2 /* 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 2019 /* cvt.d.w */, MCK_FGR32Asm, 2 /* 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 2019 /* cvt.d.w */, MCK_FGR64Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 2027 /* cvt.l.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2035 /* cvt.l.s */, MCK_FGR32Asm, 2 /* 1 */ },
  { Feature_HasStdEnc, 2035 /* cvt.l.s */, MCK_FGR64Asm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 2043 /* cvt.s.d */, MCK_AFGR64Asm, 2 /* 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 2043 /* cvt.s.d */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 2043 /* cvt.s.d */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 2043 /* cvt.s.d */, MCK_FGR64Asm, 2 /* 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 2051 /* cvt.s.l */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 2051 /* cvt.s.l */, MCK_FGR64Asm, 2 /* 1 */ },
  { Feature_HasStdEnc, 2059 /* cvt.s.w */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 2067 /* cvt.w.d */, MCK_AFGR64Asm, 2 /* 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 2067 /* cvt.w.d */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 2067 /* cvt.w.d */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 2067 /* cvt.w.d */, MCK_FGR64Asm, 2 /* 1 */ },
  { Feature_HasStdEnc, 2075 /* cvt.w.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2083 /* dadd */, MCK_GPR64Asm, 7 /* 0, 1, 2 */ },
  { 0, 2083 /* dadd */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2088 /* daddi */, MCK_GPR64Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 2088 /* daddi */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2094 /* daddiu */, MCK_GPR64Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 2094 /* daddiu */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2101 /* daddu */, MCK_GPR64Asm, 7 /* 0, 1, 2 */ },
  { 0, 2101 /* daddu */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasBitCount|Feature_HasStdEnc, 2107 /* dclo */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasBitCount|Feature_HasStdEnc, 2112 /* dclz */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2117 /* ddiv */, MCK_GPR64Asm, 6 /* 1, 2 */ },
  { Feature_HasStdEnc, 2122 /* ddivu */, MCK_GPR64Asm, 6 /* 1, 2 */ },
  { Feature_HasMips32r2|Feature_HasStdEnc, 2134 /* dext */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasMips32r2|Feature_HasStdEnc, 2139 /* dextm */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasMips32r2|Feature_HasStdEnc, 2145 /* dextu */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2151 /* di */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMips32r2|Feature_HasStdEnc, 2154 /* dins */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasMips32r2|Feature_HasStdEnc, 2159 /* dinsm */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasMips32r2|Feature_HasStdEnc, 2165 /* dinsu */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2171 /* div */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_InMicroMips, 2171 /* div */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 2175 /* div.d */, MCK_AFGR64Asm, 7 /* 0, 1, 2 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 2175 /* div.d */, MCK_FGR64Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 2181 /* div.s */, MCK_FGR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2187 /* div_s.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2195 /* div_s.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2203 /* div_s.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2211 /* div_s.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2219 /* div_u.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2227 /* div_u.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2235 /* div_u.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2243 /* div_u.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 2251 /* divu */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_InMicroMips, 2251 /* divu */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { 0, 2256 /* dmfc0 */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasMips64, 2256 /* dmfc0 */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2262 /* dmfc1 */, MCK_FGR64Asm, 2 /* 1 */ },
  { Feature_HasStdEnc, 2262 /* dmfc1 */, MCK_GPR64Asm, 1 /* 0 */ },
  { 0, 2268 /* dmfc2 */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasMips64, 2268 /* dmfc2 */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { 0, 2274 /* dmtc0 */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasMips64, 2274 /* dmtc0 */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2280 /* dmtc1 */, MCK_FGR64Asm, 2 /* 1 */ },
  { Feature_HasStdEnc, 2280 /* dmtc1 */, MCK_GPR64Asm, 1 /* 0 */ },
  { 0, 2286 /* dmtc2 */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasMips64, 2286 /* dmtc2 */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2292 /* dmult */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2298 /* dmultu */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 2305 /* dotp_s.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2305 /* dotp_s.d */, MCK_MSA128WAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2314 /* dotp_s.h */, MCK_MSA128BAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2314 /* dotp_s.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2323 /* dotp_s.w */, MCK_MSA128HAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2323 /* dotp_s.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2332 /* dotp_u.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2332 /* dotp_u.d */, MCK_MSA128WAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2341 /* dotp_u.h */, MCK_MSA128BAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2341 /* dotp_u.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2350 /* dotp_u.w */, MCK_MSA128HAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2350 /* dotp_u.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasDSPR2, 2359 /* dpa.w.ph */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSPR2, 2359 /* dpa.w.ph */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2368 /* dpadd_s.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2368 /* dpadd_s.d */, MCK_MSA128WAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2378 /* dpadd_s.h */, MCK_MSA128BAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2378 /* dpadd_s.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2388 /* dpadd_s.w */, MCK_MSA128HAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2388 /* dpadd_s.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2398 /* dpadd_u.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2398 /* dpadd_u.d */, MCK_MSA128WAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2408 /* dpadd_u.h */, MCK_MSA128BAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2408 /* dpadd_u.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2418 /* dpadd_u.w */, MCK_MSA128HAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2418 /* dpadd_u.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasDSP, 2428 /* dpaq_s.w.ph */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 2428 /* dpaq_s.w.ph */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSP, 2440 /* dpaq_sa.l.w */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 2440 /* dpaq_sa.l.w */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSPR2, 2452 /* dpaqx_s.w.ph */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSPR2, 2452 /* dpaqx_s.w.ph */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSPR2, 2465 /* dpaqx_sa.w.ph */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSPR2, 2465 /* dpaqx_sa.w.ph */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSP, 2479 /* dpau.h.qbl */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 2479 /* dpau.h.qbl */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSP, 2490 /* dpau.h.qbr */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 2490 /* dpau.h.qbr */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSPR2, 2501 /* dpax.w.ph */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSPR2, 2501 /* dpax.w.ph */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSPR2, 2511 /* dps.w.ph */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSPR2, 2511 /* dps.w.ph */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSP, 2520 /* dpsq_s.w.ph */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 2520 /* dpsq_s.w.ph */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSP, 2532 /* dpsq_sa.l.w */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 2532 /* dpsq_sa.l.w */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSPR2, 2544 /* dpsqx_s.w.ph */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSPR2, 2544 /* dpsqx_s.w.ph */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSPR2, 2557 /* dpsqx_sa.w.ph */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSPR2, 2557 /* dpsqx_sa.w.ph */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSP, 2571 /* dpsu.h.qbl */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 2571 /* dpsu.h.qbl */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSP, 2582 /* dpsu.h.qbr */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 2582 /* dpsu.h.qbr */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2593 /* dpsub_s.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2593 /* dpsub_s.d */, MCK_MSA128WAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2603 /* dpsub_s.h */, MCK_MSA128BAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2603 /* dpsub_s.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2613 /* dpsub_s.w */, MCK_MSA128HAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2613 /* dpsub_s.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2623 /* dpsub_u.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2623 /* dpsub_u.d */, MCK_MSA128WAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2633 /* dpsub_u.h */, MCK_MSA128BAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2633 /* dpsub_u.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 2643 /* dpsub_u.w */, MCK_MSA128HAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 2643 /* dpsub_u.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasDSPR2, 2653 /* dpsx.w.ph */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSPR2, 2653 /* dpsx.w.ph */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasMips64r2|Feature_HasStdEnc, 2663 /* drotr */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasMips64r2|Feature_HasStdEnc, 2669 /* drotr32 */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasMips64r2|Feature_HasStdEnc, 2677 /* drotrv */, MCK_GPR32Asm, 4 /* 2 */ },
  { Feature_HasMips64r2|Feature_HasStdEnc, 2677 /* drotrv */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasSwap|Feature_HasStdEnc, 2684 /* dsbh */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasSwap|Feature_HasStdEnc, 2689 /* dshd */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2694 /* dsll */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2699 /* dsll32 */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2706 /* dsllv */, MCK_GPR32Asm, 4 /* 2 */ },
  { Feature_HasStdEnc, 2706 /* dsllv */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2712 /* dsra */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2717 /* dsra32 */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2724 /* dsrav */, MCK_GPR32Asm, 4 /* 2 */ },
  { Feature_HasStdEnc, 2724 /* dsrav */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2730 /* dsrl */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2735 /* dsrl32 */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2742 /* dsrlv */, MCK_GPR32Asm, 4 /* 2 */ },
  { Feature_HasStdEnc, 2742 /* dsrlv */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 2748 /* dsubu */, MCK_GPR64Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 2754 /* ei */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMips32r2|Feature_HasStdEnc, 2762 /* ext */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 2762 /* ext */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 2766 /* extp */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 2766 /* extp */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 2771 /* extpdp */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 2771 /* extpdp */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 2778 /* extpdpv */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 2778 /* extpdpv */, MCK_GPR32Asm, 5 /* 0, 2 */ },
  { Feature_HasDSP, 2786 /* extpv */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 2786 /* extpv */, MCK_GPR32Asm, 5 /* 0, 2 */ },
  { Feature_HasDSP, 2792 /* extr.w */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 2792 /* extr.w */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 2799 /* extr_r.w */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 2799 /* extr_r.w */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 2808 /* extr_rs.w */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 2808 /* extr_rs.w */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 2818 /* extr_s.h */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 2818 /* extr_s.h */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 2827 /* extrv.w */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 2827 /* extrv.w */, MCK_GPR32Asm, 5 /* 0, 2 */ },
  { Feature_HasDSP, 2835 /* extrv_r.w */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 2835 /* extrv_r.w */, MCK_GPR32Asm, 5 /* 0, 2 */ },
  { Feature_HasDSP, 2845 /* extrv_rs.w */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 2845 /* extrv_rs.w */, MCK_GPR32Asm, 5 /* 0, 2 */ },
  { Feature_HasDSP, 2856 /* extrv_s.h */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 2856 /* extrv_s.h */, MCK_GPR32Asm, 5 /* 0, 2 */ },
  { Feature_HasMSA, 2866 /* fadd.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2873 /* fadd.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2880 /* fcaf.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2887 /* fcaf.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2894 /* fceq.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2901 /* fceq.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2908 /* fclass.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 2917 /* fclass.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 2926 /* fcle.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2933 /* fcle.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2940 /* fclt.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2947 /* fclt.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2954 /* fcne.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2961 /* fcne.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2968 /* fcor.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2975 /* fcor.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2982 /* fcueq.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2990 /* fcueq.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 2998 /* fcule.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3006 /* fcule.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3014 /* fcult.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3022 /* fcult.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3030 /* fcun.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3037 /* fcun.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3044 /* fcune.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3052 /* fcune.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3060 /* fdiv.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3067 /* fdiv.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3074 /* fexdo.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3074 /* fexdo.h */, MCK_MSA128WAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3082 /* fexdo.w */, MCK_MSA128DAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3082 /* fexdo.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3090 /* fexp2.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3098 /* fexp2.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3106 /* fexupl.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3106 /* fexupl.d */, MCK_MSA128WAsm, 2 /* 1 */ },
  { Feature_HasMSA, 3115 /* fexupl.w */, MCK_MSA128HAsm, 2 /* 1 */ },
  { Feature_HasMSA, 3115 /* fexupl.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3124 /* fexupr.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3124 /* fexupr.d */, MCK_MSA128WAsm, 2 /* 1 */ },
  { Feature_HasMSA, 3133 /* fexupr.w */, MCK_MSA128HAsm, 2 /* 1 */ },
  { Feature_HasMSA, 3133 /* fexupr.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3142 /* ffint_s.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3152 /* ffint_s.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3162 /* ffint_u.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3172 /* ffint_u.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3182 /* ffql.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3182 /* ffql.d */, MCK_MSA128WAsm, 2 /* 1 */ },
  { Feature_HasMSA, 3189 /* ffql.w */, MCK_MSA128HAsm, 2 /* 1 */ },
  { Feature_HasMSA, 3189 /* ffql.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3196 /* ffqr.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3196 /* ffqr.d */, MCK_MSA128WAsm, 2 /* 1 */ },
  { Feature_HasMSA, 3203 /* ffqr.w */, MCK_MSA128HAsm, 2 /* 1 */ },
  { Feature_HasMSA, 3203 /* ffqr.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3210 /* fill.b */, MCK_GPR32Asm, 2 /* 1 */ },
  { Feature_HasMSA, 3210 /* fill.b */, MCK_MSA128BAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3217 /* fill.h */, MCK_GPR32Asm, 2 /* 1 */ },
  { Feature_HasMSA, 3217 /* fill.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3224 /* fill.w */, MCK_GPR32Asm, 2 /* 1 */ },
  { Feature_HasMSA, 3224 /* fill.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3231 /* flog2.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3239 /* flog2.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 3247 /* floor.l.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 3257 /* floor.l.s */, MCK_FGR32Asm, 2 /* 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 3257 /* floor.l.s */, MCK_FGR64Asm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 3267 /* floor.w.d */, MCK_AFGR64Asm, 2 /* 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 3267 /* floor.w.d */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 3267 /* floor.w.d */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 3267 /* floor.w.d */, MCK_FGR64Asm, 2 /* 1 */ },
  { Feature_HasStdEnc, 3277 /* floor.w.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3287 /* fmadd.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3295 /* fmadd.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3303 /* fmax.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3310 /* fmax.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3317 /* fmax_a.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3326 /* fmax_a.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3335 /* fmin.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3342 /* fmin.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3349 /* fmin_a.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3358 /* fmin_a.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3367 /* fmsub.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3375 /* fmsub.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3383 /* fmul.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3390 /* fmul.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3397 /* frcp.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3404 /* frcp.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3411 /* frint.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3419 /* frint.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3427 /* frsqrt.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3436 /* frsqrt.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3445 /* fsaf.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3452 /* fsaf.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3459 /* fseq.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3466 /* fseq.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3473 /* fsle.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3480 /* fsle.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3487 /* fslt.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3494 /* fslt.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3501 /* fsne.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3508 /* fsne.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3515 /* fsor.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3522 /* fsor.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3529 /* fsqrt.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3537 /* fsqrt.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3545 /* fsub.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3552 /* fsub.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3559 /* fsueq.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3567 /* fsueq.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3575 /* fsule.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3583 /* fsule.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3591 /* fsult.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3599 /* fsult.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3607 /* fsun.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3614 /* fsun.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3621 /* fsune.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3629 /* fsune.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3637 /* ftint_s.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3647 /* ftint_s.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3657 /* ftint_u.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3667 /* ftint_u.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3677 /* ftq.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3677 /* ftq.h */, MCK_MSA128WAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3683 /* ftq.w */, MCK_MSA128DAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3683 /* ftq.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3689 /* ftrunc_s.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3700 /* ftrunc_s.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3711 /* ftrunc_u.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3722 /* ftrunc_u.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3733 /* hadd_s.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3733 /* hadd_s.d */, MCK_MSA128WAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3742 /* hadd_s.h */, MCK_MSA128BAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3742 /* hadd_s.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3751 /* hadd_s.w */, MCK_MSA128HAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3751 /* hadd_s.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3760 /* hadd_u.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3760 /* hadd_u.d */, MCK_MSA128WAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3769 /* hadd_u.h */, MCK_MSA128BAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3769 /* hadd_u.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3778 /* hadd_u.w */, MCK_MSA128HAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3778 /* hadd_u.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3787 /* hsub_s.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3787 /* hsub_s.d */, MCK_MSA128WAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3796 /* hsub_s.h */, MCK_MSA128BAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3796 /* hsub_s.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3805 /* hsub_s.w */, MCK_MSA128HAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3805 /* hsub_s.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3814 /* hsub_u.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3814 /* hsub_u.d */, MCK_MSA128WAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3823 /* hsub_u.h */, MCK_MSA128BAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3823 /* hsub_u.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3832 /* hsub_u.w */, MCK_MSA128HAsm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 3832 /* hsub_u.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3841 /* ilvev.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3849 /* ilvev.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3857 /* ilvev.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3865 /* ilvev.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3873 /* ilvl.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3880 /* ilvl.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3887 /* ilvl.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3894 /* ilvl.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3901 /* ilvod.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3909 /* ilvod.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3917 /* ilvod.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3925 /* ilvod.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3933 /* ilvr.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3940 /* ilvr.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3947 /* ilvr.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 3954 /* ilvr.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMips32r2|Feature_HasStdEnc, 3961 /* ins */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 3961 /* ins */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3965 /* insert.b */, MCK_GPR32Asm, 16 /* 4 */ },
  { Feature_HasMSA, 3965 /* insert.b */, MCK_MSA128BAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3974 /* insert.h */, MCK_GPR32Asm, 16 /* 4 */ },
  { Feature_HasMSA, 3974 /* insert.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 3983 /* insert.w */, MCK_GPR32Asm, 16 /* 4 */ },
  { Feature_HasMSA, 3983 /* insert.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasDSP, 3992 /* insv */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 3997 /* insve.b */, MCK_MSA128BAsm, 17 /* 0, 4 */ },
  { Feature_HasMSA, 4005 /* insve.d */, MCK_MSA128DAsm, 17 /* 0, 4 */ },
  { Feature_HasMSA, 4013 /* insve.h */, MCK_MSA128HAsm, 17 /* 0, 4 */ },
  { Feature_HasMSA, 4021 /* insve.w */, MCK_MSA128WAsm, 17 /* 0, 4 */ },
  { 0, 4029 /* j */, MCK_GPR32Asm, 1 /* 0 */ },
  { 0, 4031 /* jal */, MCK_GPR32Asm, 1 /* 0 */ },
  { 0, 4031 /* jal */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { 0, 4035 /* jalr */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4035 /* jalr */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 4035 /* jalr */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4046 /* jr */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 4046 /* jr */, MCK_GPR32Asm, 1 /* 0 */ },
  { 0, 4053 /* la */, MCK_GPR32Asm, 1 /* 0 */ },
  { 0, 4053 /* la */, MCK_GPR32Asm, 1 /* 0 */ },
  { 0, 4053 /* la */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 4056 /* lb */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4056 /* lb */, MCK_Mem, 2 /* 1 */ },
  { Feature_InMicroMips, 4056 /* lb */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 4056 /* lb */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 4059 /* lbu */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4059 /* lbu */, MCK_Mem, 2 /* 1 */ },
  { Feature_InMicroMips, 4059 /* lbu */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 4059 /* lbu */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasDSP, 4063 /* lbux */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 4063 /* lbux */, MCK_PtrReg, 10 /* 1, 3 */ },
  { Feature_HasStdEnc, 4068 /* ld */, MCK_GPR64Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4068 /* ld */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasMSA, 4071 /* ld.b */, MCK_MSA128BAsm, 1 /* 0 */ },
  { Feature_HasMSA, 4071 /* ld.b */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasMSA, 4076 /* ld.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 4076 /* ld.d */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasMSA, 4081 /* ld.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 4081 /* ld.h */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasMSA, 4086 /* ld.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 4086 /* ld.w */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 4091 /* ldc1 */, MCK_AFGR64Asm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 4091 /* ldc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 4091 /* ldc1 */, MCK_FGR64Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 4091 /* ldc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 4096 /* ldc2 */, MCK_COP2Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4096 /* ldc2 */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasMSA, 4101 /* ldi.b */, MCK_MSA128BAsm, 1 /* 0 */ },
  { Feature_HasMSA, 4107 /* ldi.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 4113 /* ldi.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 4119 /* ldi.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4125 /* ldl */, MCK_GPR64Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4125 /* ldl */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 4129 /* ldr */, MCK_GPR64Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4129 /* ldr */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasFPIdx|Feature_NotFP64bit|Feature_HasStdEnc, 4133 /* ldxc1 */, MCK_AFGR64Asm, 1 /* 0 */ },
  { Feature_HasFPIdx|Feature_NotFP64bit|Feature_HasStdEnc, 4133 /* ldxc1 */, MCK_PtrReg, 10 /* 1, 3 */ },
  { Feature_HasFPIdx|Feature_IsFP64bit|Feature_HasStdEnc, 4133 /* ldxc1 */, MCK_FGR64Asm, 1 /* 0 */ },
  { Feature_HasFPIdx|Feature_IsFP64bit|Feature_HasStdEnc, 4133 /* ldxc1 */, MCK_PtrReg, 10 /* 1, 3 */ },
  { Feature_HasStdEnc, 4139 /* lh */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4139 /* lh */, MCK_Mem, 2 /* 1 */ },
  { Feature_InMicroMips, 4139 /* lh */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 4139 /* lh */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 4142 /* lhu */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4142 /* lhu */, MCK_Mem, 2 /* 1 */ },
  { Feature_InMicroMips, 4142 /* lhu */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 4142 /* lhu */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasDSP, 4146 /* lhx */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 4146 /* lhx */, MCK_PtrReg, 10 /* 1, 3 */ },
  { 0, 4150 /* li */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4153 /* ll */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4153 /* ll */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 4156 /* lld */, MCK_GPR64Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4156 /* lld */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasMSA, 4160 /* lsa */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4160 /* lsa */, MCK_LSAImm, 8 /* 3 */ },
  { Feature_HasStdEnc, 4164 /* lui */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 4164 /* lui */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 4168 /* luxc1 */, MCK_AFGR64Asm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 4168 /* luxc1 */, MCK_PtrReg, 10 /* 1, 3 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 4168 /* luxc1 */, MCK_FGR64Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 4168 /* luxc1 */, MCK_PtrReg, 10 /* 1, 3 */ },
  { Feature_HasStdEnc, 4174 /* lw */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4174 /* lw */, MCK_Mem, 2 /* 1 */ },
  { Feature_InMicroMips, 4174 /* lw */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 4174 /* lw */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 4177 /* lwc1 */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4177 /* lwc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 4182 /* lwc2 */, MCK_COP2Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4182 /* lwc2 */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotInMicroMips, 4187 /* lwl */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_NotInMicroMips, 4187 /* lwl */, MCK_Mem, 2 /* 1 */ },
  { Feature_InMicroMips, 4187 /* lwl */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 4187 /* lwl */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotInMicroMips, 4191 /* lwr */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_NotInMicroMips, 4191 /* lwr */, MCK_Mem, 2 /* 1 */ },
  { Feature_InMicroMips, 4191 /* lwr */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 4191 /* lwr */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 4195 /* lwu */, MCK_GPR64Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4195 /* lwu */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasDSP, 4199 /* lwx */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 4199 /* lwx */, MCK_PtrReg, 10 /* 1, 3 */ },
  { Feature_HasFPIdx|Feature_HasStdEnc, 4203 /* lwxc1 */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_HasFPIdx|Feature_HasStdEnc, 4203 /* lwxc1 */, MCK_PtrReg, 10 /* 1, 3 */ },
  { Feature_HasStdEnc, 4209 /* madd */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 4209 /* madd */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 4209 /* madd */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 4209 /* madd */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasMips32r2|Feature_NotFP64bit|Feature_HasStdEnc, 4214 /* madd.d */, MCK_AFGR64Asm, 15 /* 0, 1, 2, 3 */ },
  { Feature_HasMips32r2|Feature_HasStdEnc, 4221 /* madd.s */, MCK_FGR32Asm, 15 /* 0, 1, 2, 3 */ },
  { Feature_HasMSA, 4228 /* madd_q.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4237 /* madd_q.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4246 /* maddr_q.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4256 /* maddr_q.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 4266 /* maddu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 4266 /* maddu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 4266 /* maddu */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 4266 /* maddu */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 4272 /* maddv.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4280 /* maddv.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4288 /* maddv.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4296 /* maddv.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 4304 /* maq_s.w.phl */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 4304 /* maq_s.w.phl */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSP, 4316 /* maq_s.w.phr */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 4316 /* maq_s.w.phr */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSP, 4328 /* maq_sa.w.phl */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 4328 /* maq_sa.w.phl */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSP, 4341 /* maq_sa.w.phr */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 4341 /* maq_sa.w.phr */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 4354 /* max_a.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4362 /* max_a.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4370 /* max_a.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4378 /* max_a.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4386 /* max_s.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4394 /* max_s.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4402 /* max_s.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4410 /* max_s.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4418 /* max_u.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4426 /* max_u.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4434 /* max_u.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4442 /* max_u.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4450 /* maxi_s.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4459 /* maxi_s.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4468 /* maxi_s.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4477 /* maxi_s.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4486 /* maxi_u.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4495 /* maxi_u.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4504 /* maxi_u.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4513 /* maxi_u.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { 0, 4522 /* mfc0 */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4522 /* mfc0 */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4527 /* mfc1 */, MCK_FGR32Asm, 2 /* 1 */ },
  { Feature_HasStdEnc, 4527 /* mfc1 */, MCK_GPR32Asm, 1 /* 0 */ },
  { 0, 4532 /* mfc2 */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4532 /* mfc2 */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4537 /* mfhc1 */, MCK_FGRH32Asm, 2 /* 1 */ },
  { Feature_HasStdEnc, 4537 /* mfhc1 */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4543 /* mfhi */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 4543 /* mfhi */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 4543 /* mfhi */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 4543 /* mfhi */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 4548 /* mflo */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 4548 /* mflo */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 4548 /* mflo */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 4548 /* mflo */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasMSA, 4553 /* min_a.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4561 /* min_a.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4569 /* min_a.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4577 /* min_a.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4585 /* min_s.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4593 /* min_s.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4601 /* min_s.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4609 /* min_s.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4617 /* min_u.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4625 /* min_u.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4633 /* min_u.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4641 /* min_u.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4649 /* mini_s.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4658 /* mini_s.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4667 /* mini_s.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4676 /* mini_s.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4685 /* mini_u.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4694 /* mini_u.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4703 /* mini_u.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4712 /* mini_u.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4721 /* mod_s.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4729 /* mod_s.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4737 /* mod_s.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4745 /* mod_s.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4753 /* mod_u.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4761 /* mod_u.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4769 /* mod_u.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4777 /* mod_u.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 4785 /* modsub */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 4792 /* mov.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 4792 /* mov.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4798 /* mov.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_NotMips64, 4804 /* move */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMips64, 4804 /* move */, MCK_GPR64Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 4809 /* move.v */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4816 /* movf */, MCK_FCCRegsAsm, 4 /* 2 */ },
  { Feature_HasStdEnc, 4816 /* movf */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 4816 /* movf */, MCK_FCCRegsAsm, 4 /* 2 */ },
  { Feature_InMicroMips, 4816 /* movf */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 4821 /* movf.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 4821 /* movf.d */, MCK_FCCRegsAsm, 4 /* 2 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 4821 /* movf.d */, MCK_FCCRegsAsm, 4 /* 2 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 4821 /* movf.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4828 /* movf.s */, MCK_FCCRegsAsm, 4 /* 2 */ },
  { Feature_HasStdEnc, 4828 /* movf.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4835 /* movn */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 4835 /* movn */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 4840 /* movn.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 4840 /* movn.d */, MCK_GPR32Asm, 4 /* 2 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 4840 /* movn.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 4840 /* movn.d */, MCK_GPR32Asm, 4 /* 2 */ },
  { Feature_HasStdEnc, 4847 /* movn.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4847 /* movn.s */, MCK_GPR32Asm, 4 /* 2 */ },
  { Feature_HasStdEnc, 4854 /* movt */, MCK_FCCRegsAsm, 4 /* 2 */ },
  { Feature_HasStdEnc, 4854 /* movt */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 4854 /* movt */, MCK_FCCRegsAsm, 4 /* 2 */ },
  { Feature_InMicroMips, 4854 /* movt */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 4859 /* movt.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 4859 /* movt.d */, MCK_FCCRegsAsm, 4 /* 2 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 4859 /* movt.d */, MCK_FCCRegsAsm, 4 /* 2 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 4859 /* movt.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4866 /* movt.s */, MCK_FCCRegsAsm, 4 /* 2 */ },
  { Feature_HasStdEnc, 4866 /* movt.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4873 /* movz */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 4873 /* movz */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 4878 /* movz.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 4878 /* movz.d */, MCK_GPR32Asm, 4 /* 2 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 4878 /* movz.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 4878 /* movz.d */, MCK_GPR32Asm, 4 /* 2 */ },
  { Feature_HasStdEnc, 4885 /* movz.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4885 /* movz.s */, MCK_GPR32Asm, 4 /* 2 */ },
  { Feature_HasStdEnc, 4892 /* msub */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 4892 /* msub */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 4892 /* msub */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 4892 /* msub */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasMips32r2|Feature_NotFP64bit|Feature_HasStdEnc, 4897 /* msub.d */, MCK_AFGR64Asm, 15 /* 0, 1, 2, 3 */ },
  { Feature_HasMips32r2|Feature_HasStdEnc, 4904 /* msub.s */, MCK_FGR32Asm, 15 /* 0, 1, 2, 3 */ },
  { Feature_HasMSA, 4911 /* msub_q.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4920 /* msub_q.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4929 /* msubr_q.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4939 /* msubr_q.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 4949 /* msubu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 4949 /* msubu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 4949 /* msubu */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 4949 /* msubu */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 4955 /* msubv.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4963 /* msubv.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4971 /* msubv.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 4979 /* msubv.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { 0, 4987 /* mtc0 */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4987 /* mtc0 */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4992 /* mtc1 */, MCK_FGR32Asm, 2 /* 1 */ },
  { Feature_HasStdEnc, 4992 /* mtc1 */, MCK_GPR32Asm, 1 /* 0 */ },
  { 0, 4997 /* mtc2 */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 4997 /* mtc2 */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 5002 /* mthc1 */, MCK_FGRH32Asm, 2 /* 1 */ },
  { Feature_HasStdEnc, 5002 /* mthc1 */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 5008 /* mthi */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 5008 /* mthi */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 5008 /* mthi */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 5008 /* mthi */, MCK_HI32DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 5013 /* mthlip */, MCK_ACC64DSPAsm, 2 /* 1 */ },
  { Feature_HasDSP, 5013 /* mthlip */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 5020 /* mtlo */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 5020 /* mtlo */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 5020 /* mtlo */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 5020 /* mtlo */, MCK_LO32DSPAsm, 2 /* 1 */ },
  { Feature_HasStdEnc, 5025 /* mul */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 5025 /* mul */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 5029 /* mul.d */, MCK_AFGR64Asm, 7 /* 0, 1, 2 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 5029 /* mul.d */, MCK_FGR64Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 5035 /* mul.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 5042 /* mul.s */, MCK_FGR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5048 /* mul_q.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5056 /* mul_q.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 5064 /* mul_s.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 5073 /* muleq_s.w.phl */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 5087 /* muleq_s.w.phr */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 5101 /* muleu_s.ph.qbl */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 5116 /* muleu_s.ph.qbr */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 5131 /* mulq_rs.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 5142 /* mulq_rs.w */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 5152 /* mulq_s.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 5162 /* mulq_s.w */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5171 /* mulr_q.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5180 /* mulr_q.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 5189 /* mulsa.w.ph */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSPR2, 5189 /* mulsa.w.ph */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasDSP, 5200 /* mulsaq_s.w.ph */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 5200 /* mulsaq_s.w.ph */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasStdEnc, 5214 /* mult */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 5214 /* mult */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5214 /* mult */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 5214 /* mult */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasStdEnc, 5219 /* multu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 5219 /* multu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5219 /* multu */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 5219 /* multu */, MCK_GPR32Asm, 6 /* 1, 2 */ },
  { Feature_HasMSA, 5225 /* mulv.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5232 /* mulv.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5239 /* mulv.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5246 /* mulv.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { 0, 5253 /* neg */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_NoNaNsFPMath|Feature_HasStdEnc, 5257 /* neg.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_NoNaNsFPMath|Feature_HasStdEnc, 5257 /* neg.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_NoNaNsFPMath|Feature_HasStdEnc, 5263 /* neg.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { 0, 5269 /* negu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5274 /* nloc.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5281 /* nloc.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5288 /* nloc.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5295 /* nloc.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5302 /* nlzc.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5309 /* nlzc.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5316 /* nlzc.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5323 /* nlzc.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMips32r2|Feature_NotFP64bit|Feature_NoNaNsFPMath|Feature_HasStdEnc, 5330 /* nmadd.d */, MCK_AFGR64Asm, 15 /* 0, 1, 2, 3 */ },
  { Feature_HasMips32r2|Feature_NoNaNsFPMath|Feature_HasStdEnc, 5338 /* nmadd.s */, MCK_FGR32Asm, 15 /* 0, 1, 2, 3 */ },
  { Feature_HasMips32r2|Feature_NotFP64bit|Feature_NoNaNsFPMath|Feature_HasStdEnc, 5346 /* nmsub.d */, MCK_AFGR64Asm, 15 /* 0, 1, 2, 3 */ },
  { Feature_HasMips32r2|Feature_NoNaNsFPMath|Feature_HasStdEnc, 5354 /* nmsub.s */, MCK_FGR32Asm, 15 /* 0, 1, 2, 3 */ },
  { Feature_HasStdEnc, 5366 /* nor */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 5366 /* nor */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5370 /* nor.v */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5376 /* nori.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { 0, 5383 /* not */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 5387 /* or */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 5387 /* or */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { 0, 5387 /* or */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5390 /* or.v */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 5395 /* ori */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 5395 /* ori */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 5395 /* ori */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 5395 /* ori */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5399 /* ori.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5405 /* packrl.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5415 /* pckev.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5423 /* pckev.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5431 /* pckev.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5439 /* pckev.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5447 /* pckod.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5455 /* pckod.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5463 /* pckod.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5471 /* pckod.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 5479 /* pcnt.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5486 /* pcnt.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5493 /* pcnt.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5500 /* pcnt.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5507 /* pick.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 5515 /* pick.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 5523 /* preceq.w.phl */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5536 /* preceq.w.phr */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5549 /* precequ.ph.qbl */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5564 /* precequ.ph.qbla */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5580 /* precequ.ph.qbr */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5595 /* precequ.ph.qbra */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5611 /* preceu.ph.qbl */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5625 /* preceu.ph.qbla */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5640 /* preceu.ph.qbr */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5654 /* preceu.ph.qbra */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSPR2, 5669 /* precr.qb.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 5681 /* precr_sra.ph.w */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSPR2, 5696 /* precr_sra_r.ph.w */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5713 /* precrq.ph.w */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 5725 /* precrq.qb.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 5738 /* precrq_rs.ph.w */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 5753 /* precrqu_s.qb.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 5769 /* prepend */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5777 /* raddu.w.qb */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5788 /* rddsp */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 5794 /* rdhwr */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 5794 /* rdhwr */, MCK_HWRegsAsm, 2 /* 1 */ },
  { Feature_HasDSP, 5800 /* repl.ph */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 5808 /* repl.qb */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasDSP, 5816 /* replv.ph */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 5825 /* replv.qb */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMips32r2|Feature_HasStdEnc, 5834 /* rotr */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 5834 /* rotr */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMips32r2|Feature_HasStdEnc, 5839 /* rotrv */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 5839 /* rotrv */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 5845 /* round.l.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 5855 /* round.l.s */, MCK_FGR32Asm, 2 /* 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 5855 /* round.l.s */, MCK_FGR64Asm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 5865 /* round.w.d */, MCK_AFGR64Asm, 2 /* 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 5865 /* round.w.d */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 5865 /* round.w.d */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 5865 /* round.w.d */, MCK_FGR64Asm, 2 /* 1 */ },
  { Feature_HasStdEnc, 5875 /* round.w.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5885 /* sat_s.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5893 /* sat_s.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5901 /* sat_s.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5909 /* sat_s.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5917 /* sat_u.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5925 /* sat_u.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5933 /* sat_u.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 5941 /* sat_u.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 5949 /* sb */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 5949 /* sb */, MCK_Mem, 2 /* 1 */ },
  { Feature_InMicroMips, 5949 /* sb */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 5949 /* sb */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 5952 /* sc */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 5952 /* sc */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 5955 /* scd */, MCK_GPR64Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 5955 /* scd */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 5959 /* sd */, MCK_GPR64Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 5959 /* sd */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 5962 /* sdc1 */, MCK_AFGR64Asm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 5962 /* sdc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 5962 /* sdc1 */, MCK_FGR64Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 5962 /* sdc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 5967 /* sdc2 */, MCK_COP2Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 5967 /* sdc2 */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 5972 /* sdl */, MCK_GPR64Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 5972 /* sdl */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 5976 /* sdr */, MCK_GPR64Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 5976 /* sdr */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasFPIdx|Feature_NotFP64bit|Feature_HasStdEnc, 5980 /* sdxc1 */, MCK_AFGR64Asm, 1 /* 0 */ },
  { Feature_HasFPIdx|Feature_NotFP64bit|Feature_HasStdEnc, 5980 /* sdxc1 */, MCK_PtrReg, 10 /* 1, 3 */ },
  { Feature_HasFPIdx|Feature_IsFP64bit|Feature_HasStdEnc, 5980 /* sdxc1 */, MCK_FGR64Asm, 1 /* 0 */ },
  { Feature_HasFPIdx|Feature_IsFP64bit|Feature_HasStdEnc, 5980 /* sdxc1 */, MCK_PtrReg, 10 /* 1, 3 */ },
  { Feature_HasSEInReg|Feature_HasStdEnc, 5986 /* seb */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 5986 /* seb */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasSEInReg|Feature_HasStdEnc, 5990 /* seh */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 5990 /* seh */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 5994 /* sh */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 5994 /* sh */, MCK_Mem, 2 /* 1 */ },
  { Feature_InMicroMips, 5994 /* sh */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 5994 /* sh */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasMSA, 5997 /* shf.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6003 /* shf.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6009 /* shf.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 6015 /* shilo */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 6021 /* shilov */, MCK_ACC64DSPAsm, 1 /* 0 */ },
  { Feature_HasDSP, 6021 /* shilov */, MCK_GPR32Asm, 2 /* 1 */ },
  { Feature_HasDSP, 6028 /* shll.ph */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 6036 /* shll.qb */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 6044 /* shll_s.ph */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 6054 /* shll_s.w */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 6063 /* shllv.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 6072 /* shllv.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 6081 /* shllv_s.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 6092 /* shllv_s.w */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 6102 /* shra.ph */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSPR2, 6110 /* shra.qb */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 6118 /* shra_r.ph */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSPR2, 6128 /* shra_r.qb */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 6138 /* shra_r.w */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 6147 /* shrav.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 6156 /* shrav.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 6165 /* shrav_r.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 6176 /* shrav_r.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 6187 /* shrav_r.w */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 6197 /* shrl.ph */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSP, 6205 /* shrl.qb */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasDSPR2, 6213 /* shrlv.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 6222 /* shrlv.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6231 /* sld.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6237 /* sld.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6243 /* sld.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6249 /* sld.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6255 /* sldi.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6262 /* sldi.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6269 /* sldi.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6276 /* sldi.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 6283 /* sll */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 6283 /* sll */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6287 /* sll.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6293 /* sll.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6299 /* sll.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6305 /* sll.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6311 /* slli.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6318 /* slli.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6325 /* slli.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6332 /* slli.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 6339 /* sllv */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 6339 /* sllv */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 6344 /* slt */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 6344 /* slt */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { 0, 6344 /* slt */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 6348 /* slti */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 6348 /* slti */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 6353 /* sltiu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 6353 /* sltiu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 6359 /* sltu */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 6359 /* sltu */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6364 /* splat.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6372 /* splat.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6380 /* splat.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6388 /* splat.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6396 /* splati.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6405 /* splati.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6414 /* splati.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6423 /* splati.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 6432 /* sqrt.d */, MCK_AFGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 6432 /* sqrt.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 6439 /* sqrt.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 6446 /* sra */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 6446 /* sra */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6450 /* sra.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6456 /* sra.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6462 /* sra.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6468 /* sra.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6474 /* srai.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6481 /* srai.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6488 /* srai.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6495 /* srai.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6502 /* srar.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6509 /* srar.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6516 /* srar.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6523 /* srar.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6530 /* srari.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6538 /* srari.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6546 /* srari.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6554 /* srari.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 6562 /* srav */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 6562 /* srav */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 6567 /* srl */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 6567 /* srl */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6571 /* srl.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6577 /* srl.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6583 /* srl.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6589 /* srl.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6595 /* srli.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6602 /* srli.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6609 /* srli.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6616 /* srli.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6623 /* srlr.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6630 /* srlr.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6637 /* srlr.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6644 /* srlr.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6651 /* srlri.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6659 /* srlri.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6667 /* srlri.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 6675 /* srlri.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 6683 /* srlv */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 6683 /* srlv */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6688 /* st.b */, MCK_MSA128BAsm, 1 /* 0 */ },
  { Feature_HasMSA, 6688 /* st.b */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasMSA, 6693 /* st.d */, MCK_MSA128DAsm, 1 /* 0 */ },
  { Feature_HasMSA, 6693 /* st.d */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasMSA, 6698 /* st.h */, MCK_MSA128HAsm, 1 /* 0 */ },
  { Feature_HasMSA, 6698 /* st.h */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasMSA, 6703 /* st.w */, MCK_MSA128WAsm, 1 /* 0 */ },
  { Feature_HasMSA, 6703 /* st.w */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 6708 /* sub */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 6708 /* sub */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { 0, 6708 /* sub */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { 0, 6708 /* sub */, MCK_InvNum, 4 /* 2 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 6712 /* sub.d */, MCK_AFGR64Asm, 7 /* 0, 1, 2 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 6712 /* sub.d */, MCK_FGR64Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 6718 /* sub.s */, MCK_FGR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 6724 /* subq.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 6732 /* subq_s.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 6742 /* subq_s.w */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 6751 /* subqh.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 6760 /* subqh.w */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 6768 /* subqh_r.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 6779 /* subqh_r.w */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6789 /* subs_s.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6798 /* subs_s.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6807 /* subs_s.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6816 /* subs_s.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6825 /* subs_u.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6834 /* subs_u.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6843 /* subs_u.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6852 /* subs_u.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6861 /* subsus_u.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6872 /* subsus_u.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6883 /* subsus_u.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6894 /* subsus_u.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6905 /* subsuu_s.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6916 /* subsuu_s.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6927 /* subsuu_s.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 6938 /* subsuu_s.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 6949 /* subu */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 6949 /* subu */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { 0, 6949 /* subu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { 0, 6949 /* subu */, MCK_InvNum, 4 /* 2 */ },
  { Feature_HasDSPR2, 6954 /* subu.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 6962 /* subu.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 6970 /* subu_s.ph */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 6980 /* subu_s.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 6990 /* subuh.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSPR2, 6999 /* subuh_r.qb */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 7010 /* subv.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 7017 /* subv.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 7024 /* subv.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 7031 /* subv.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 7038 /* subvi.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 7046 /* subvi.d */, MCK_MSA128DAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 7054 /* subvi.h */, MCK_MSA128HAsm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 7062 /* subvi.w */, MCK_MSA128WAsm, 3 /* 0, 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 7070 /* suxc1 */, MCK_AFGR64Asm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 7070 /* suxc1 */, MCK_PtrReg, 10 /* 1, 3 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 7070 /* suxc1 */, MCK_FGR64Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 7070 /* suxc1 */, MCK_PtrReg, 10 /* 1, 3 */ },
  { Feature_HasStdEnc, 7076 /* sw */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 7076 /* sw */, MCK_Mem, 2 /* 1 */ },
  { Feature_InMicroMips, 7076 /* sw */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 7076 /* sw */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 7079 /* swc1 */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 7079 /* swc1 */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasStdEnc, 7084 /* swc2 */, MCK_COP2Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 7084 /* swc2 */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotInMicroMips, 7089 /* swl */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_NotInMicroMips, 7089 /* swl */, MCK_Mem, 2 /* 1 */ },
  { Feature_InMicroMips, 7089 /* swl */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 7089 /* swl */, MCK_Mem, 2 /* 1 */ },
  { Feature_NotInMicroMips, 7093 /* swr */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_NotInMicroMips, 7093 /* swr */, MCK_Mem, 2 /* 1 */ },
  { Feature_InMicroMips, 7093 /* swr */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 7093 /* swr */, MCK_Mem, 2 /* 1 */ },
  { Feature_HasFPIdx|Feature_HasStdEnc, 7097 /* swxc1 */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_HasFPIdx|Feature_HasStdEnc, 7097 /* swxc1 */, MCK_PtrReg, 10 /* 1, 3 */ },
  { 0, 7116 /* teq */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 7116 /* teq */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 7116 /* teq */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 7120 /* teqi */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 7120 /* teqi */, MCK_GPR32Asm, 1 /* 0 */ },
  { 0, 7125 /* tge */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 7125 /* tge */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 7125 /* tge */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 7129 /* tgei */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 7129 /* tgei */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 7134 /* tgeiu */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 7134 /* tgeiu */, MCK_GPR32Asm, 1 /* 0 */ },
  { 0, 7140 /* tgeu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 7140 /* tgeu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 7140 /* tgeu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { 0, 7145 /* tlt */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 7145 /* tlt */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 7145 /* tlt */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 7149 /* tlti */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 7149 /* tlti */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 7154 /* tltiu */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 7154 /* tltiu */, MCK_GPR32Asm, 1 /* 0 */ },
  { 0, 7160 /* tltu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 7160 /* tltu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 7160 /* tltu */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { 0, 7165 /* tne */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 7165 /* tne */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 7165 /* tne */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 7169 /* tnei */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 7169 /* tnei */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 7174 /* trunc.l.d */, MCK_FGR64Asm, 3 /* 0, 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 7184 /* trunc.l.s */, MCK_FGR32Asm, 2 /* 1 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 7184 /* trunc.l.s */, MCK_FGR64Asm, 1 /* 0 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 7194 /* trunc.w.d */, MCK_AFGR64Asm, 2 /* 1 */ },
  { Feature_NotFP64bit|Feature_HasStdEnc, 7194 /* trunc.w.d */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 7194 /* trunc.w.d */, MCK_FGR32Asm, 1 /* 0 */ },
  { Feature_IsFP64bit|Feature_HasStdEnc, 7194 /* trunc.w.d */, MCK_FGR64Asm, 2 /* 1 */ },
  { Feature_HasStdEnc, 7204 /* trunc.w.s */, MCK_FGR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 7214 /* vshf.b */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 7221 /* vshf.d */, MCK_MSA128DAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 7228 /* vshf.h */, MCK_MSA128HAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasMSA, 7235 /* vshf.w */, MCK_MSA128WAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasDSP, 7247 /* wrdsp */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasSwap|Feature_HasStdEnc, 7253 /* wsbh */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 7253 /* wsbh */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasStdEnc, 7258 /* xor */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { Feature_InMicroMips, 7258 /* xor */, MCK_GPR32Asm, 7 /* 0, 1, 2 */ },
  { 0, 7258 /* xor */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 7262 /* xor.v */, MCK_MSA128BAsm, 7 /* 0, 1, 2 */ },
  { Feature_HasStdEnc, 7268 /* xori */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_InMicroMips, 7268 /* xori */, MCK_GPR32Asm, 1 /* 0 */ },
  { Feature_HasStdEnc, 7268 /* xori */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_InMicroMips, 7268 /* xori */, MCK_GPR32Asm, 3 /* 0, 1 */ },
  { Feature_HasMSA, 7273 /* xori.b */, MCK_MSA128BAsm, 3 /* 0, 1 */ },
};

MipsAsmParser::OperandMatchResultTy MipsAsmParser::
tryCustomParseOperand(SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                      unsigned MCK) {

  switch(MCK) {
  case MCK_ACC64DSPAsm:
    return parseACC64DSP(Operands);
  case MCK_AFGR64Asm:
    return parseAFGR64Regs(Operands);
  case MCK_CCRAsm:
    return parseCCRRegs(Operands);
  case MCK_COP2Asm:
    return parseCOP2(Operands);
  case MCK_FCCRegsAsm:
    return parseFCCRegs(Operands);
  case MCK_FGR32Asm:
    return parseFGR32Regs(Operands);
  case MCK_FGR64Asm:
    return parseFGR64Regs(Operands);
  case MCK_FGRH32Asm:
    return parseFGRH32Regs(Operands);
  case MCK_GPR32Asm:
    return parseGPR32(Operands);
  case MCK_GPR64Asm:
    return parseGPR64(Operands);
  case MCK_HI32DSPAsm:
    return parseHI32DSP(Operands);
  case MCK_HWRegsAsm:
    return parseHWRegs(Operands);
  case MCK_LO32DSPAsm:
    return parseLO32DSP(Operands);
  case MCK_MSA128BAsm:
    return parseMSA128BRegs(Operands);
  case MCK_MSA128CRAsm:
    return parseMSA128CtrlRegs(Operands);
  case MCK_MSA128DAsm:
    return parseMSA128DRegs(Operands);
  case MCK_MSA128HAsm:
    return parseMSA128HRegs(Operands);
  case MCK_MSA128WAsm:
    return parseMSA128WRegs(Operands);
  case MCK_InvNum:
    return parseInvNum(Operands);
  case MCK_Mem:
    return parseMemOperand(Operands);
  case MCK_PtrReg:
    return parsePtrReg(Operands);
  case MCK_LSAImm:
    return parseLSAImm(Operands);
  default:
    return MatchOperand_NoMatch;
  }
  return MatchOperand_NoMatch;
}

MipsAsmParser::OperandMatchResultTy MipsAsmParser::
MatchOperandParserImpl(SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                       StringRef Mnemonic) {
  // Get the current feature set.
  unsigned AvailableFeatures = getAvailableFeatures();

  // Get the next operand index.
  unsigned NextOpNum = Operands.size()-1;
  // Search the table.
  std::pair<const OperandMatchEntry*, const OperandMatchEntry*> MnemonicRange =
    std::equal_range(OperandMatchTable, OperandMatchTable+1335, Mnemonic,
                     LessOpcodeOperand());

  if (MnemonicRange.first == MnemonicRange.second)
    return MatchOperand_NoMatch;

  for (const OperandMatchEntry *it = MnemonicRange.first,
       *ie = MnemonicRange.second; it != ie; ++it) {
    // equal_range guarantees that instruction mnemonic matches.
    assert(Mnemonic == it->getMnemonic());

    // check if the available features match
    if ((AvailableFeatures & it->RequiredFeatures) != it->RequiredFeatures) {
      continue;
    }

    // check if the operand in question has a custom parser.
    if (!(it->OperandMask & (1 << NextOpNum)))
      continue;

    // call custom parse method to handle the operand
    OperandMatchResultTy Result = tryCustomParseOperand(Operands, it->Class);
    if (Result != MatchOperand_NoMatch)
      return Result;
  }

  // Okay, we had no match.
  return MatchOperand_NoMatch;
}

#endif // GET_MATCHER_IMPLEMENTATION


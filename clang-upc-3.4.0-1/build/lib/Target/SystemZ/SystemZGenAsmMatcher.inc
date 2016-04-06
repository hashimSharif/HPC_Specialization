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
  Feature_FeatureDistinctOps = (1 << 0),
  Feature_FeatureLoadStoreOnCond = (1 << 3),
  Feature_FeatureHighWord = (1 << 2),
  Feature_FeatureFPExtension = (1 << 1),
  Feature_None = 0
};

#endif // GET_REGISTER_MATCHER


#ifdef GET_SUBTARGET_FEATURE_NAME
#undef GET_SUBTARGET_FEATURE_NAME

// User-level names for subtarget features that participate in
// instruction matching.
static const char *getSubtargetFeatureName(unsigned Val) {
  switch(Val) {
  case Feature_FeatureDistinctOps: return "distinct-ops";
  case Feature_FeatureLoadStoreOnCond: return "load-store-on-cond";
  case Feature_FeatureHighWord: return "high-word";
  case Feature_FeatureFPExtension: return "fp-extension";
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
  CVT_95_addRegOperands,
  CVT_95_addBDXAddrOperands,
  CVT_95_addImmOperands,
  CVT_95_addBDAddrOperands,
  CVT_95_addBDLAddrOperands,
  CVT_95_addAccessRegOperands,
  CVT_NUM_CONVERTERS
};

enum InstructionConversionKind {
  Convert__GR321_0__Tie0__BDXAddr64Disp123_1,
  Convert__FP641_0__Tie0__BDXAddr64Disp123_1,
  Convert__FP641_0__Tie0__FP641_1,
  Convert__FP321_0__Tie0__BDXAddr64Disp123_1,
  Convert__FP321_0__Tie0__FP321_1,
  Convert__GR321_0__Tie0__S32Imm1_1,
  Convert__GR641_0__Tie0__BDXAddr64Disp203_1,
  Convert__GR641_0__Tie0__S32Imm1_1,
  Convert__GR641_0__Tie0__GR321_1,
  Convert__GR641_0__Tie0__S16Imm1_1,
  Convert__GR641_0__GR641_1__S16Imm1_2,
  Convert__GR641_0__Tie0__GR641_1,
  Convert__GR641_0__GR641_1__GR641_2,
  Convert__BDAddr64Disp202_0__S8Imm1_1,
  Convert__GR321_0__Tie0__S16Imm1_1,
  Convert__GR321_0__GR321_1__S16Imm1_2,
  Convert__GR321_0__Tie0__BDXAddr64Disp203_1,
  Convert__GRH321_0__Tie0__S32Imm1_1,
  Convert__GR321_0__Tie0__GR321_1,
  Convert__GR321_0__Tie0__U32Imm1_1,
  Convert__GR641_0__Tie0__U32Imm1_1,
  Convert__GR321_0__GR321_1__GR321_2,
  Convert__FP1281_0__Tie0__FP1281_1,
  Convert__GR641_0__ADDR641_1,
  Convert__U4Imm1_0__GR641_1,
  Convert__ADDR641_0,
  Convert__GR641_0__PCRel161_1,
  Convert__GR641_0__PCRel321_1,
  Convert__U4Imm1_0__PCRel161_1,
  Convert__U4Imm1_0__PCRel321_1,
  Convert__GR321_0__Tie0__PCRel161_1,
  Convert__GR641_0__Tie0__PCRel161_1,
  Convert__GR321_0__BDXAddr64Disp123_1,
  Convert__FP641_0__BDXAddr64Disp123_1,
  Convert__FP641_0__FP641_1,
  Convert__FP641_0__GR321_1,
  Convert__FP641_0__GR641_1,
  Convert__FP321_0__BDXAddr64Disp123_1,
  Convert__FP321_0__FP321_1,
  Convert__FP321_0__GR321_1,
  Convert__FP321_0__GR641_1,
  Convert__GR321_0__U4Imm1_1__FP641_2,
  Convert__GR321_0__U4Imm1_1__FP321_2,
  Convert__GR321_0__S32Imm1_1,
  Convert__GR321_0__U4Imm1_1__FP1281_2,
  Convert__GR641_0__BDXAddr64Disp203_1,
  Convert__GR641_0__U4Imm1_1__FP641_2,
  Convert__GR641_0__U4Imm1_1__FP321_2,
  Convert__GR641_0__S32Imm1_1,
  Convert__GR641_0__GR321_1,
  Convert__GR641_0__S16Imm1_1,
  Convert__BDAddr64Disp122_0__S16Imm1_1,
  Convert__GR641_0__S8Imm1_1__U4Imm1_2__PCRel161_3,
  Convert__GR641_0__S8Imm1_1__PCRel161_2,
  Convert__GR641_0__GR641_1,
  Convert__GR641_0__GR641_1__U4Imm1_2__PCRel161_3,
  Convert__GR641_0__GR641_1__PCRel161_2,
  Convert__GR641_0__U4Imm1_1__FP1281_2,
  Convert__GRH321_0__BDXAddr64Disp203_1,
  Convert__GR321_0__S16Imm1_1,
  Convert__GR321_0__PCRel321_1,
  Convert__GR321_0__BDXAddr64Disp203_1,
  Convert__GRH321_0__S32Imm1_1,
  Convert__GR321_0__S8Imm1_1__U4Imm1_2__PCRel161_3,
  Convert__GR321_0__S8Imm1_1__PCRel161_2,
  Convert__BDLAddr64Disp12Len83_0__BDAddr64Disp122_1,
  Convert__BDAddr64Disp122_0__U16Imm1_1,
  Convert__GR321_0__U32Imm1_1,
  Convert__GR641_0__U32Imm1_1,
  Convert__GR641_0__U8Imm1_1__U4Imm1_2__PCRel161_3,
  Convert__GR641_0__U8Imm1_1__PCRel161_2,
  Convert__BDAddr64Disp122_0__U8Imm1_1,
  Convert__GR321_0__U8Imm1_1__U4Imm1_2__PCRel161_3,
  Convert__GR321_0__U8Imm1_1__PCRel161_2,
  Convert__BDAddr64Disp202_0__U8Imm1_1,
  Convert__GR321_0__GR321_1,
  Convert__GR321_0__GR321_1__U4Imm1_2__PCRel161_3,
  Convert__GR321_0__GR321_1__PCRel161_2,
  Convert__GR641_0__GR641_1__Tie0__Tie1,
  Convert__FP641_0__FP641_1__FP641_2,
  Convert__GR321_0__Tie0__GR321_1__BDAddr64Disp122_2,
  Convert__GR641_0__Tie0__GR641_1__BDAddr64Disp202_2,
  Convert__GR321_0__Tie0__GR321_1__BDAddr64Disp202_2,
  Convert__FP1281_0__FP1281_1,
  Convert__FP1281_0__GR321_1,
  Convert__FP1281_0__GR641_1,
  Convert__GR1281_0__Tie0__BDXAddr64Disp203_1,
  Convert__GR1281_0__Tie0__GR641_1,
  Convert__GR1281_0__Tie0__GR321_1,
  Convert__GR321_0__AccessReg1_1,
  Convert__FP641_0__U4Imm1_1__FP641_2,
  Convert__FP641_0__U4Imm1_1__FP641_2__U4Imm1_3,
  Convert__FP321_0__U4Imm1_1__FP321_2,
  Convert__FP321_0__U4Imm1_1__FP321_2__U4Imm1_3,
  Convert__FP1281_0__U4Imm1_1__FP1281_2,
  Convert__FP1281_0__U4Imm1_1__FP1281_2__U4Imm1_3,
  Convert__GR1281_0__GR641_1,
  Convert__GR641_0__Tie0__BDXAddr64Disp123_1,
  Convert__GRH321_0__U32Imm1_1,
  Convert__GRH321_0__Tie0__U16Imm1_1,
  Convert__GR321_0__Tie0__U16Imm1_1,
  Convert__GR321_0,
  Convert__PCRel161_0,
  Convert__PCRel321_0,
  Convert__GR641_0__BDXAddr64Disp123_1,
  Convert__FP641_0__FP321_1,
  Convert__FP641_0__BDXAddr64Disp203_1,
  Convert__FP321_0__FP641_1,
  Convert__FP321_0__BDXAddr64Disp203_1,
  Convert__GR641_0__FP641_1,
  Convert__GR641_0__U16Imm1_1,
  Convert__GR641_0__GR641_1__BDAddr64Disp202_2,
  Convert__GR321_0__Tie0__BDAddr64Disp202_1__U4Imm1_2,
  Convert__GR321_0__Tie0__BDAddr64Disp202_1,
  Convert__GR641_0__Tie0__BDAddr64Disp202_1__U4Imm1_2,
  Convert__GR641_0__Tie0__BDAddr64Disp202_1,
  Convert__GR641_0__Tie0__GR641_1__U4Imm1_2,
  Convert__GR321_0__Tie0__GR321_1__U4Imm1_2,
  Convert__FP1281_0__BDXAddr64Disp123_1,
  Convert__FP1281_0__FP641_1,
  Convert__FP1281_0__FP321_1,
  Convert__FP641_0,
  Convert__FP321_0,
  Convert__FP1281_0,
  Convert__FP641_0__Tie0__FP641_1__BDXAddr64Disp123_2,
  Convert__FP641_0__Tie0__FP641_1__FP641_2,
  Convert__FP321_0__Tie0__FP321_1__BDXAddr64Disp123_2,
  Convert__FP321_0__Tie0__FP321_1__FP321_2,
  Convert__FP641_0__Tie0__FP321_1,
  Convert__FP1281_0__Tie0__BDXAddr64Disp123_1,
  Convert__FP1281_0__Tie0__FP641_1,
  Convert__GRH321_0__Tie0__U32Imm1_1,
  Convert__U4Imm1_0__BDXAddr64Disp203_1,
  Convert__GR641_0__Tie0__GR641_1__U8Imm1_2__U8Imm1_3__U6Imm1_4,
  Convert__GRH321_0__Tie0__GR641_1__U8Imm1_2__U8Imm1_3__U6Imm1_4,
  Convert__GR321_0__Tie0__GR641_1__U8Imm1_2__U8Imm1_3__U6Imm1_4,
  Convert__GR321_0__GR321_1__BDAddr32Disp202_2,
  Convert__GR641_0__GR641_1__BDAddr32Disp202_2,
  Convert__GR321_0__Tie0__BDAddr32Disp122_1,
  Convert__GR321_0__BDAddr64Disp202_1__U4Imm1_2,
  Convert__GR321_0__BDAddr64Disp202_1,
  Convert__GR641_0__BDAddr64Disp202_1__U4Imm1_2,
  Convert__GR641_0__BDAddr64Disp202_1,
  Convert__GRH321_0__U16Imm1_1,
  Convert__GR321_0__U16Imm1_1,
  CVT_NUM_SIGNATURES
};

} // end anonymous namespace

static const uint8_t ConversionTable[CVT_NUM_SIGNATURES][13] = {
  // Convert__GR321_0__Tie0__BDXAddr64Disp123_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__FP641_0__Tie0__BDXAddr64Disp123_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__FP641_0__Tie0__FP641_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__FP321_0__Tie0__BDXAddr64Disp123_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__FP321_0__Tie0__FP321_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR321_0__Tie0__S32Imm1_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR641_0__Tie0__BDXAddr64Disp203_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__GR641_0__Tie0__S32Imm1_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR641_0__Tie0__GR321_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR641_0__Tie0__S16Imm1_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR641_0__GR641_1__S16Imm1_2
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__GR641_0__Tie0__GR641_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR641_0__GR641_1__GR641_2
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__BDAddr64Disp202_0__S8Imm1_1
  { CVT_95_addBDAddrOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__Tie0__S16Imm1_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__GR321_1__S16Imm1_2
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__GR321_0__Tie0__BDXAddr64Disp203_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__GRH321_0__Tie0__S32Imm1_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__Tie0__GR321_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR321_0__Tie0__U32Imm1_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR641_0__Tie0__U32Imm1_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__GR321_1__GR321_2
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__FP1281_0__Tie0__FP1281_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR641_0__ADDR641_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__U4Imm1_0__GR641_1
  { CVT_95_addImmOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__ADDR641_0
  { CVT_95_addRegOperands, 1, CVT_Done },
  // Convert__GR641_0__PCRel161_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR641_0__PCRel321_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__U4Imm1_0__PCRel161_1
  { CVT_95_addImmOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__U4Imm1_0__PCRel321_1
  { CVT_95_addImmOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__Tie0__PCRel161_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR641_0__Tie0__PCRel161_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__BDXAddr64Disp123_1
  { CVT_95_addRegOperands, 1, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__FP641_0__BDXAddr64Disp123_1
  { CVT_95_addRegOperands, 1, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__FP641_0__FP641_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__FP641_0__GR321_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__FP641_0__GR641_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__FP321_0__BDXAddr64Disp123_1
  { CVT_95_addRegOperands, 1, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__FP321_0__FP321_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__FP321_0__GR321_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__FP321_0__GR641_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR321_0__U4Imm1_1__FP641_2
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__GR321_0__U4Imm1_1__FP321_2
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__GR321_0__S32Imm1_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__U4Imm1_1__FP1281_2
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__GR641_0__BDXAddr64Disp203_1
  { CVT_95_addRegOperands, 1, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__GR641_0__U4Imm1_1__FP641_2
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__GR641_0__U4Imm1_1__FP321_2
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__GR641_0__S32Imm1_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR641_0__GR321_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR641_0__S16Imm1_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__BDAddr64Disp122_0__S16Imm1_1
  { CVT_95_addBDAddrOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR641_0__S8Imm1_1__U4Imm1_2__PCRel161_3
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__GR641_0__S8Imm1_1__PCRel161_2
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__GR641_0__GR641_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR641_0__GR641_1__U4Imm1_2__PCRel161_3
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__GR641_0__GR641_1__PCRel161_2
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__GR641_0__U4Imm1_1__FP1281_2
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__GRH321_0__BDXAddr64Disp203_1
  { CVT_95_addRegOperands, 1, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__GR321_0__S16Imm1_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__PCRel321_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__BDXAddr64Disp203_1
  { CVT_95_addRegOperands, 1, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__GRH321_0__S32Imm1_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__S8Imm1_1__U4Imm1_2__PCRel161_3
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__GR321_0__S8Imm1_1__PCRel161_2
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__BDLAddr64Disp12Len83_0__BDAddr64Disp122_1
  { CVT_95_addBDLAddrOperands, 1, CVT_95_addBDAddrOperands, 2, CVT_Done },
  // Convert__BDAddr64Disp122_0__U16Imm1_1
  { CVT_95_addBDAddrOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__U32Imm1_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR641_0__U32Imm1_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR641_0__U8Imm1_1__U4Imm1_2__PCRel161_3
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__GR641_0__U8Imm1_1__PCRel161_2
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__BDAddr64Disp122_0__U8Imm1_1
  { CVT_95_addBDAddrOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__U8Imm1_1__U4Imm1_2__PCRel161_3
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__GR321_0__U8Imm1_1__PCRel161_2
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__BDAddr64Disp202_0__U8Imm1_1
  { CVT_95_addBDAddrOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__GR321_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR321_0__GR321_1__U4Imm1_2__PCRel161_3
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__GR321_0__GR321_1__PCRel161_2
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__GR641_0__GR641_1__Tie0__Tie1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Tied, 0, CVT_Tied, 1, CVT_Done },
  // Convert__FP641_0__FP641_1__FP641_2
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__GR321_0__Tie0__GR321_1__BDAddr64Disp122_2
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_95_addBDAddrOperands, 3, CVT_Done },
  // Convert__GR641_0__Tie0__GR641_1__BDAddr64Disp202_2
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_95_addBDAddrOperands, 3, CVT_Done },
  // Convert__GR321_0__Tie0__GR321_1__BDAddr64Disp202_2
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_95_addBDAddrOperands, 3, CVT_Done },
  // Convert__FP1281_0__FP1281_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__FP1281_0__GR321_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__FP1281_0__GR641_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR1281_0__Tie0__BDXAddr64Disp203_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__GR1281_0__Tie0__GR641_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR1281_0__Tie0__GR321_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR321_0__AccessReg1_1
  { CVT_95_addRegOperands, 1, CVT_95_addAccessRegOperands, 2, CVT_Done },
  // Convert__FP641_0__U4Imm1_1__FP641_2
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__FP641_0__U4Imm1_1__FP641_2__U4Imm1_3
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__FP321_0__U4Imm1_1__FP321_2
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__FP321_0__U4Imm1_1__FP321_2__U4Imm1_3
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__FP1281_0__U4Imm1_1__FP1281_2
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__FP1281_0__U4Imm1_1__FP1281_2__U4Imm1_3
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__GR1281_0__GR641_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR641_0__Tie0__BDXAddr64Disp123_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__GRH321_0__U32Imm1_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GRH321_0__Tie0__U16Imm1_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__Tie0__U16Imm1_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0
  { CVT_95_addRegOperands, 1, CVT_Done },
  // Convert__PCRel161_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__PCRel321_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__GR641_0__BDXAddr64Disp123_1
  { CVT_95_addRegOperands, 1, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__FP641_0__FP321_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__FP641_0__BDXAddr64Disp203_1
  { CVT_95_addRegOperands, 1, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__FP321_0__FP641_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__FP321_0__BDXAddr64Disp203_1
  { CVT_95_addRegOperands, 1, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__GR641_0__FP641_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GR641_0__U16Imm1_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR641_0__GR641_1__BDAddr64Disp202_2
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_95_addBDAddrOperands, 3, CVT_Done },
  // Convert__GR321_0__Tie0__BDAddr64Disp202_1__U4Imm1_2
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addBDAddrOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__GR321_0__Tie0__BDAddr64Disp202_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addBDAddrOperands, 2, CVT_Done },
  // Convert__GR641_0__Tie0__BDAddr64Disp202_1__U4Imm1_2
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addBDAddrOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__GR641_0__Tie0__BDAddr64Disp202_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addBDAddrOperands, 2, CVT_Done },
  // Convert__GR641_0__Tie0__GR641_1__U4Imm1_2
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__GR321_0__Tie0__GR321_1__U4Imm1_2
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__FP1281_0__BDXAddr64Disp123_1
  { CVT_95_addRegOperands, 1, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__FP1281_0__FP641_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__FP1281_0__FP321_1
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__FP641_0
  { CVT_95_addRegOperands, 1, CVT_Done },
  // Convert__FP321_0
  { CVT_95_addRegOperands, 1, CVT_Done },
  // Convert__FP1281_0
  { CVT_95_addRegOperands, 1, CVT_Done },
  // Convert__FP641_0__Tie0__FP641_1__BDXAddr64Disp123_2
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_95_addBDXAddrOperands, 3, CVT_Done },
  // Convert__FP641_0__Tie0__FP641_1__FP641_2
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__FP321_0__Tie0__FP321_1__BDXAddr64Disp123_2
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_95_addBDXAddrOperands, 3, CVT_Done },
  // Convert__FP321_0__Tie0__FP321_1__FP321_2
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__FP641_0__Tie0__FP321_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__FP1281_0__Tie0__BDXAddr64Disp123_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__FP1281_0__Tie0__FP641_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_Done },
  // Convert__GRH321_0__Tie0__U32Imm1_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__U4Imm1_0__BDXAddr64Disp203_1
  { CVT_95_addImmOperands, 1, CVT_95_addBDXAddrOperands, 2, CVT_Done },
  // Convert__GR641_0__Tie0__GR641_1__U8Imm1_2__U8Imm1_3__U6Imm1_4
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__GRH321_0__Tie0__GR641_1__U8Imm1_2__U8Imm1_3__U6Imm1_4
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__GR321_0__Tie0__GR641_1__U8Imm1_2__U8Imm1_3__U6Imm1_4
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addRegOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__GR321_0__GR321_1__BDAddr32Disp202_2
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_95_addBDAddrOperands, 3, CVT_Done },
  // Convert__GR641_0__GR641_1__BDAddr32Disp202_2
  { CVT_95_addRegOperands, 1, CVT_95_addRegOperands, 2, CVT_95_addBDAddrOperands, 3, CVT_Done },
  // Convert__GR321_0__Tie0__BDAddr32Disp122_1
  { CVT_95_addRegOperands, 1, CVT_Tied, 0, CVT_95_addBDAddrOperands, 2, CVT_Done },
  // Convert__GR321_0__BDAddr64Disp202_1__U4Imm1_2
  { CVT_95_addRegOperands, 1, CVT_95_addBDAddrOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__GR321_0__BDAddr64Disp202_1
  { CVT_95_addRegOperands, 1, CVT_95_addBDAddrOperands, 2, CVT_Done },
  // Convert__GR641_0__BDAddr64Disp202_1__U4Imm1_2
  { CVT_95_addRegOperands, 1, CVT_95_addBDAddrOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__GR641_0__BDAddr64Disp202_1
  { CVT_95_addRegOperands, 1, CVT_95_addBDAddrOperands, 2, CVT_Done },
  // Convert__GRH321_0__U16Imm1_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__GR321_0__U16Imm1_1
  { CVT_95_addRegOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
};

void SystemZAsmParser::
convertToMCInst(unsigned Kind, MCInst &Inst, unsigned Opcode,
                const SmallVectorImpl<MCParsedAsmOperand*> &Operands) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  const uint8_t *Converter = ConversionTable[Kind];
  Inst.setOpcode(Opcode);
  for (const uint8_t *p = Converter; *p; p+= 2) {
    switch (*p) {
    default: llvm_unreachable("invalid conversion entry!");
    case CVT_Reg:
      static_cast<SystemZOperand*>(Operands[*(p + 1)])->addRegOperands(Inst, 1);
      break;
    case CVT_Tied:
      Inst.addOperand(Inst.getOperand(*(p + 1)));
      break;
    case CVT_95_addRegOperands:
      static_cast<SystemZOperand*>(Operands[*(p + 1)])->addRegOperands(Inst, 1);
      break;
    case CVT_95_addBDXAddrOperands:
      static_cast<SystemZOperand*>(Operands[*(p + 1)])->addBDXAddrOperands(Inst, 3);
      break;
    case CVT_95_addImmOperands:
      static_cast<SystemZOperand*>(Operands[*(p + 1)])->addImmOperands(Inst, 1);
      break;
    case CVT_95_addBDAddrOperands:
      static_cast<SystemZOperand*>(Operands[*(p + 1)])->addBDAddrOperands(Inst, 2);
      break;
    case CVT_95_addBDLAddrOperands:
      static_cast<SystemZOperand*>(Operands[*(p + 1)])->addBDLAddrOperands(Inst, 3);
      break;
    case CVT_95_addAccessRegOperands:
      static_cast<SystemZOperand*>(Operands[*(p + 1)])->addAccessRegOperands(Inst, 1);
      break;
    }
  }
}

void SystemZAsmParser::
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
    case CVT_95_addRegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addBDXAddrOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 3;
      break;
    case CVT_95_addImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addBDAddrOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addBDLAddrOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 3;
      break;
    case CVT_95_addAccessRegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    }
  }
}

namespace {

/// MatchClassKind - The kinds of classes which participate in
/// instruction matching.
enum MatchClassKind {
  InvalidMatchClass = 0,
  MCK_ADDR32Bit, // register class 'ADDR32Bit'
  MCK_GR32Bit, // register class 'GR32Bit'
  MCK_GRH32Bit, // register class 'GRH32Bit'
  MCK_GRX32Bit, // register class 'GRX32Bit'
  MCK_ADDR64Bit, // register class 'ADDR64Bit'
  MCK_GR64Bit, // register class 'GR64Bit'
  MCK_ADDR128Bit, // register class 'ADDR128Bit'
  MCK_GR128Bit, // register class 'GR128Bit'
  MCK_FP32Bit, // register class 'FP32Bit'
  MCK_FP64Bit, // register class 'FP64Bit'
  MCK_FP128Bit, // register class 'FP128Bit'
  MCK_CCRegs, // register class 'CCRegs'
  MCK_ADDR128, // user defined class 'ADDR128AsmOperand'
  MCK_ADDR32, // user defined class 'ADDR32AsmOperand'
  MCK_ADDR64, // user defined class 'ADDR64AsmOperand'
  MCK_AccessReg, // user defined class 'AccessReg'
  MCK_BDAddr32Disp12, // user defined class 'BDAddr32Disp12'
  MCK_BDAddr32Disp20, // user defined class 'BDAddr32Disp20'
  MCK_BDAddr64Disp12, // user defined class 'BDAddr64Disp12'
  MCK_BDAddr64Disp20, // user defined class 'BDAddr64Disp20'
  MCK_BDLAddr64Disp12Len8, // user defined class 'BDLAddr64Disp12Len8'
  MCK_BDXAddr64Disp12, // user defined class 'BDXAddr64Disp12'
  MCK_BDXAddr64Disp20, // user defined class 'BDXAddr64Disp20'
  MCK_FP128, // user defined class 'FP128AsmOperand'
  MCK_FP32, // user defined class 'FP32AsmOperand'
  MCK_FP64, // user defined class 'FP64AsmOperand'
  MCK_GR128, // user defined class 'GR128AsmOperand'
  MCK_GR32, // user defined class 'GR32AsmOperand'
  MCK_GR64, // user defined class 'GR64AsmOperand'
  MCK_GRH32, // user defined class 'GRH32AsmOperand'
  MCK_GRX32, // user defined class 'GRX32AsmOperand'
  MCK_Imm, // user defined class 'ImmAsmOperand'
  MCK_PCRel16, // user defined class 'PCRel16'
  MCK_PCRel32, // user defined class 'PCRel32'
  MCK_S16Imm, // user defined class 'S16Imm'
  MCK_S32Imm, // user defined class 'S32Imm'
  MCK_S8Imm, // user defined class 'S8Imm'
  MCK_U16Imm, // user defined class 'U16Imm'
  MCK_U32Imm, // user defined class 'U32Imm'
  MCK_U4Imm, // user defined class 'U4Imm'
  MCK_U6Imm, // user defined class 'U6Imm'
  MCK_U8Imm, // user defined class 'U8Imm'
  NumMatchClassKinds
};

}

static MatchClassKind matchTokenString(StringRef Name) {
  return InvalidMatchClass;
}

/// isSubclass - Compute whether \p A is a subclass of \p B.
static bool isSubclass(MatchClassKind A, MatchClassKind B) {
  if (A == B)
    return true;

  switch (A) {
  default:
    return false;

  case MCK_ADDR32Bit:
    switch (B) {
    default: return false;
    case MCK_GR32Bit: return true;
    case MCK_GRX32Bit: return true;
    }

  case MCK_GR32Bit:
    return B == MCK_GRX32Bit;

  case MCK_GRH32Bit:
    return B == MCK_GRX32Bit;

  case MCK_ADDR64Bit:
    return B == MCK_GR64Bit;

  case MCK_ADDR128Bit:
    return B == MCK_GR128Bit;
  }
}

static unsigned validateOperandClass(MCParsedAsmOperand *GOp, MatchClassKind Kind) {
  SystemZOperand &Operand = *(SystemZOperand*)GOp;
  if (Kind == InvalidMatchClass)
    return MCTargetAsmParser::Match_InvalidOperand;

  if (Operand.isToken())
    return isSubclass(matchTokenString(Operand.getToken()), Kind) ?
             MCTargetAsmParser::Match_Success :
             MCTargetAsmParser::Match_InvalidOperand;

  // 'ADDR128' class
  if (Kind == MCK_ADDR128) {
    if (Operand.isADDR128())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ADDR32' class
  if (Kind == MCK_ADDR32) {
    if (Operand.isADDR32())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ADDR64' class
  if (Kind == MCK_ADDR64) {
    if (Operand.isADDR64())
      return MCTargetAsmParser::Match_Success;
  }

  // 'AccessReg' class
  if (Kind == MCK_AccessReg) {
    if (Operand.isAccessReg())
      return MCTargetAsmParser::Match_Success;
  }

  // 'BDAddr32Disp12' class
  if (Kind == MCK_BDAddr32Disp12) {
    if (Operand.isBDAddr32Disp12())
      return MCTargetAsmParser::Match_Success;
  }

  // 'BDAddr32Disp20' class
  if (Kind == MCK_BDAddr32Disp20) {
    if (Operand.isBDAddr32Disp20())
      return MCTargetAsmParser::Match_Success;
  }

  // 'BDAddr64Disp12' class
  if (Kind == MCK_BDAddr64Disp12) {
    if (Operand.isBDAddr64Disp12())
      return MCTargetAsmParser::Match_Success;
  }

  // 'BDAddr64Disp20' class
  if (Kind == MCK_BDAddr64Disp20) {
    if (Operand.isBDAddr64Disp20())
      return MCTargetAsmParser::Match_Success;
  }

  // 'BDLAddr64Disp12Len8' class
  if (Kind == MCK_BDLAddr64Disp12Len8) {
    if (Operand.isBDLAddr64Disp12Len8())
      return MCTargetAsmParser::Match_Success;
  }

  // 'BDXAddr64Disp12' class
  if (Kind == MCK_BDXAddr64Disp12) {
    if (Operand.isBDXAddr64Disp12())
      return MCTargetAsmParser::Match_Success;
  }

  // 'BDXAddr64Disp20' class
  if (Kind == MCK_BDXAddr64Disp20) {
    if (Operand.isBDXAddr64Disp20())
      return MCTargetAsmParser::Match_Success;
  }

  // 'FP128' class
  if (Kind == MCK_FP128) {
    if (Operand.isFP128())
      return MCTargetAsmParser::Match_Success;
  }

  // 'FP32' class
  if (Kind == MCK_FP32) {
    if (Operand.isFP32())
      return MCTargetAsmParser::Match_Success;
  }

  // 'FP64' class
  if (Kind == MCK_FP64) {
    if (Operand.isFP64())
      return MCTargetAsmParser::Match_Success;
  }

  // 'GR128' class
  if (Kind == MCK_GR128) {
    if (Operand.isGR128())
      return MCTargetAsmParser::Match_Success;
  }

  // 'GR32' class
  if (Kind == MCK_GR32) {
    if (Operand.isGR32())
      return MCTargetAsmParser::Match_Success;
  }

  // 'GR64' class
  if (Kind == MCK_GR64) {
    if (Operand.isGR64())
      return MCTargetAsmParser::Match_Success;
  }

  // 'GRH32' class
  if (Kind == MCK_GRH32) {
    if (Operand.isGRH32())
      return MCTargetAsmParser::Match_Success;
  }

  // 'GRX32' class
  if (Kind == MCK_GRX32) {
    if (Operand.isGRX32())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm' class
  if (Kind == MCK_Imm) {
    if (Operand.isImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'PCRel16' class
  if (Kind == MCK_PCRel16) {
    if (Operand.isImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'PCRel32' class
  if (Kind == MCK_PCRel32) {
    if (Operand.isImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'S16Imm' class
  if (Kind == MCK_S16Imm) {
    if (Operand.isS16Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'S32Imm' class
  if (Kind == MCK_S32Imm) {
    if (Operand.isS32Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'S8Imm' class
  if (Kind == MCK_S8Imm) {
    if (Operand.isS8Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U16Imm' class
  if (Kind == MCK_U16Imm) {
    if (Operand.isU16Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U32Imm' class
  if (Kind == MCK_U32Imm) {
    if (Operand.isU32Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U4Imm' class
  if (Kind == MCK_U4Imm) {
    if (Operand.isU4Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U6Imm' class
  if (Kind == MCK_U6Imm) {
    if (Operand.isU6Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U8Imm' class
  if (Kind == MCK_U8Imm) {
    if (Operand.isU8Imm())
      return MCTargetAsmParser::Match_Success;
  }

  if (Operand.isReg()) {
    MatchClassKind OpKind;
    switch (Operand.getReg()) {
    default: OpKind = InvalidMatchClass; break;
    case SystemZ::R0L: OpKind = MCK_GR32Bit; break;
    case SystemZ::R1L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R2L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R3L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R4L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R5L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R6L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R7L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R8L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R9L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R10L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R11L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R12L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R13L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R14L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R15L: OpKind = MCK_ADDR32Bit; break;
    case SystemZ::R0H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R1H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R2H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R3H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R4H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R5H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R6H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R7H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R8H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R9H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R10H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R11H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R12H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R13H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R14H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R15H: OpKind = MCK_GRH32Bit; break;
    case SystemZ::R0D: OpKind = MCK_GR64Bit; break;
    case SystemZ::R1D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R2D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R3D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R4D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R5D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R6D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R7D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R8D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R9D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R10D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R11D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R12D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R13D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R14D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R15D: OpKind = MCK_ADDR64Bit; break;
    case SystemZ::R0Q: OpKind = MCK_GR128Bit; break;
    case SystemZ::R2Q: OpKind = MCK_ADDR128Bit; break;
    case SystemZ::R4Q: OpKind = MCK_ADDR128Bit; break;
    case SystemZ::R6Q: OpKind = MCK_ADDR128Bit; break;
    case SystemZ::R8Q: OpKind = MCK_ADDR128Bit; break;
    case SystemZ::R10Q: OpKind = MCK_ADDR128Bit; break;
    case SystemZ::R12Q: OpKind = MCK_ADDR128Bit; break;
    case SystemZ::R14Q: OpKind = MCK_ADDR128Bit; break;
    case SystemZ::F0S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F1S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F2S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F3S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F4S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F5S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F6S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F7S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F8S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F9S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F10S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F11S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F12S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F13S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F14S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F15S: OpKind = MCK_FP32Bit; break;
    case SystemZ::F0D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F1D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F2D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F3D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F4D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F5D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F6D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F7D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F8D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F9D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F10D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F11D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F12D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F13D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F14D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F15D: OpKind = MCK_FP64Bit; break;
    case SystemZ::F0Q: OpKind = MCK_FP128Bit; break;
    case SystemZ::F1Q: OpKind = MCK_FP128Bit; break;
    case SystemZ::F4Q: OpKind = MCK_FP128Bit; break;
    case SystemZ::F5Q: OpKind = MCK_FP128Bit; break;
    case SystemZ::F8Q: OpKind = MCK_FP128Bit; break;
    case SystemZ::F9Q: OpKind = MCK_FP128Bit; break;
    case SystemZ::F12Q: OpKind = MCK_FP128Bit; break;
    case SystemZ::F13Q: OpKind = MCK_FP128Bit; break;
    case SystemZ::CC: OpKind = MCK_CCRegs; break;
    }
    return isSubclass(OpKind, Kind) ? MCTargetAsmParser::Match_Success :
                                      MCTargetAsmParser::Match_InvalidOperand;
  }

  return MCTargetAsmParser::Match_InvalidOperand;
}

unsigned SystemZAsmParser::
ComputeAvailableFeatures(uint64_t FB) const {
  unsigned Features = 0;
  if (((FB & SystemZ::FeatureDistinctOps) != 0))
    Features |= Feature_FeatureDistinctOps;
  if (((FB & SystemZ::FeatureLoadStoreOnCond) != 0))
    Features |= Feature_FeatureLoadStoreOnCond;
  if (((FB & SystemZ::FeatureHighWord) != 0))
    Features |= Feature_FeatureHighWord;
  if (((FB & SystemZ::FeatureFPExtension) != 0))
    Features |= Feature_FeatureFPExtension;
  return Features;
}

static const char *const MnemonicTable =
    "\001a\003adb\004adbr\003aeb\004aebr\003afi\002ag\003agf\004agfi\004agfr"
    "\004aghi\005aghik\003agr\004agrk\004agsi\002ah\003ahi\004ahik\003ahy\003"
    "aih\002al\003alc\004alcg\005alcgr\004alcr\004alfi\003alg\004algf\005alg"
    "fi\005algfr\007alghsik\004algr\005algrk\006alhsik\003alr\004alrk\003aly"
    "\002ar\003ark\003asi\004axbr\002ay\004basr\003bcr\003ber\004bher\003bhr"
    "\004bler\004blhr\003blr\004bner\005bnher\004bnhr\005bnler\005bnlhr\004b"
    "nlr\004bnor\003bor\002br\004bras\005brasl\003brc\004brcl\004brct\005brc"
    "tg\001c\003cdb\004cdbr\005cdfbr\005cdgbr\003ceb\004cebr\005cefbr\005ceg"
    "br\005cfdbr\005cfebr\003cfi\005cfxbr\002cg\005cgdbr\005cgebr\003cgf\004"
    "cgfi\004cgfr\005cgfrl\003cgh\004cghi\005cghrl\005cghsi\004cgij\005cgije"
    "\005cgijh\006cgijhe\005cgijl\006cgijle\006cgijlh\006cgijne\006cgijnh\007"
    "cgijnhe\006cgijnl\007cgijnle\007cgijnlh\003cgr\004cgrj\005cgrje\005cgrj"
    "h\006cgrjhe\005cgrjl\006cgrjle\006cgrjlh\006cgrjne\006cgrjnh\007cgrjnhe"
    "\006cgrjnl\007cgrjnle\007cgrjnlh\004cgrl\005cgxbr\002ch\003chf\005chhsi"
    "\003chi\004chrl\004chsi\003chy\003cih\003cij\004cije\004cijh\005cijhe\004"
    "cijl\005cijle\005cijlh\005cijne\005cijnh\006cijnhe\005cijnl\006cijnle\006"
    "cijnlh\002cl\003clc\006clfhsi\004clfi\003clg\004clgf\005clgfi\005clgfr\006"
    "clgfrl\006clghrl\006clghsi\005clgij\006clgije\006clgijh\007clgijhe\006c"
    "lgijl\007clgijle\007clgijlh\007clgijne\007clgijnh\010clgijnhe\007clgijn"
    "l\010clgijnle\010clgijnlh\004clgr\005clgrj\006clgrje\006clgrjh\007clgrj"
    "he\006clgrjl\007clgrjle\007clgrjlh\007clgrjne\007clgrjnh\010clgrjnhe\007"
    "clgrjnl\010clgrjnle\010clgrjnlh\005clgrl\004clhf\006clhhsi\005clhrl\003"
    "cli\004clih\004clij\005clije\005clijh\006clijhe\005clijl\006clijle\006c"
    "lijlh\006clijne\006clijnh\007clijnhe\006clijnl\007clijnle\007clijnlh\004"
    "cliy\003clr\004clrj\005clrje\005clrjh\006clrjhe\005clrjl\006clrjle\006c"
    "lrjlh\006clrjne\006clrjnh\007clrjnhe\006clrjnl\007clrjnle\007clrjnlh\004"
    "clrl\004clst\003cly\005cpsdr\002cr\003crj\004crje\004crjh\005crjhe\004c"
    "rjl\005crjle\005crjlh\005crjne\005crjnh\006crjnhe\005crjnl\006crjnle\006"
    "crjnlh\003crl\002cs\003csg\003csy\004cxbr\005cxfbr\005cxgbr\002cy\003dd"
    "b\004ddbr\003deb\004debr\002dl\003dlg\004dlgr\003dlr\003dsg\004dsgf\005"
    "dsgfr\004dsgr\004dxbr\003ear\005fidbr\006fidbra\005fiebr\006fiebra\005f"
    "ixbr\006fixbra\005flogr\002ic\003icy\004iihf\004iihh\004iihl\004iilf\004"
    "iilh\004iill\003ipm\001j\002je\002jg\003jge\003jgh\004jghe\003jgl\004jg"
    "le\004jglh\004jgne\004jgnh\005jgnhe\004jgnl\005jgnle\005jgnlh\004jgno\003"
    "jgo\002jh\003jhe\002jl\003jle\003jlh\003jne\003jnh\004jnhe\003jnl\004jn"
    "le\004jnlh\003jno\002jo\001l\002la\004larl\003lay\002lb\003lbh\003lbr\005"
    "lcdbr\005lcebr\005lcgfr\004lcgr\003lcr\005lcxbr\002ld\004ldeb\005ldebr\004"
    "ldgr\003ldr\005ldxbr\003ldy\002le\005ledbr\003ler\005lexbr\003ley\003lf"
    "h\002lg\003lgb\004lgbr\004lgdr\003lgf\004lgfi\004lgfr\005lgfrl\003lgh\004"
    "lghi\004lghr\005lghrl\003lgr\004lgrl\002lh\003lhh\003lhi\003lhr\004lhrl"
    "\003lhy\003llc\004llch\004llcr\004llgc\005llgcr\004llgf\005llgfr\006llg"
    "frl\004llgh\005llghr\006llghrl\003llh\004llhh\004llhr\005llhrl\005llihf"
    "\005llihh\005llihl\005llilf\005llilh\005llill\003lmg\005lndbr\005lnebr\005"
    "lngfr\004lngr\003lnr\005lnxbr\003loc\004loce\004locg\005locge\005locgh\006"
    "locghe\005locgl\006locgle\006locglh\006locgne\006locgnh\007locgnhe\006l"
    "ocgnl\007locgnle\007locgnlh\006locgno\005locgo\005locgr\006locgre\006lo"
    "cgrh\007locgrhe\006locgrl\007locgrle\007locgrlh\007locgrne\007locgrnh\010"
    "locgrnhe\007locgrnl\010locgrnle\010locgrnlh\007locgrno\006locgro\004loc"
    "h\005loche\004locl\005locle\005loclh\005locne\005locnh\006locnhe\005loc"
    "nl\006locnle\006locnlh\005locno\004loco\004locr\005locre\005locrh\006lo"
    "crhe\005locrl\006locrle\006locrlh\006locrne\006locrnh\007locrnhe\006loc"
    "rnl\007locrnle\007locrnlh\006locrno\005locro\005lpdbr\005lpebr\005lpgfr"
    "\004lpgr\003lpr\005lpxbr\002lr\003lrl\003lrv\004lrvg\005lrvgr\004lrvr\002"
    "lt\005ltdbr\005ltebr\003ltg\004ltgf\005ltgfr\004ltgr\003ltr\005ltxbr\004"
    "lxdb\005lxdbr\004lxeb\005lxebr\003lxr\002ly\004lzdr\004lzer\004lzxr\004"
    "madb\005madbr\004maeb\005maebr\003mdb\004mdbr\004mdeb\005mdebr\004meeb\005"
    "meebr\004mghi\002mh\003mhi\003mhy\003mlg\004mlgr\002ms\004msdb\005msdbr"
    "\004mseb\005msebr\004msfi\003msg\004msgf\005msgfi\005msgfr\004msgr\003m"
    "sr\003msy\003mvc\005mvghi\005mvhhi\004mvhi\003mvi\004mviy\004mvst\004mx"
    "br\004mxdb\005mxdbr\001n\002nc\002ng\003ngr\004ngrk\002ni\004nihf\004ni"
    "hh\004nihl\004nilf\004nilh\004nill\003niy\002nr\003nrk\002ny\001o\002oc"
    "\002og\003ogr\004ogrk\002oi\004oihf\004oihh\004oihl\004oilf\004oilh\004"
    "oill\003oiy\002or\003ork\002oy\003pfd\005pfdrl\005risbg\006risbhg\006ri"
    "sblg\003rll\004rllg\005rnsbg\005rosbg\005rxsbg\001s\003sdb\004sdbr\003s"
    "eb\004sebr\002sg\003sgf\004sgfr\003sgr\004sgrk\002sh\003shy\002sl\003sl"
    "b\004slbg\005slbgr\004slbr\004slfi\003slg\004slgf\005slgfi\005slgfr\004"
    "slgr\005slgrk\003sll\004sllg\004sllk\003slr\004slrk\003sly\004sqdb\005s"
    "qdbr\004sqeb\005sqebr\005sqxbr\002sr\003sra\004srag\004srak\003srk\003s"
    "rl\004srlg\004srlk\004srst\002st\003stc\004stch\004stcy\003std\004stdy\003"
    "ste\004stey\004stfh\003stg\005stgrl\003sth\004sthh\005sthrl\004sthy\004"
    "stmg\004stoc\005stoce\005stocg\006stocge\006stocgh\007stocghe\006stocgl"
    "\007stocgle\007stocglh\007stocgne\007stocgnh\010stocgnhe\007stocgnl\010"
    "stocgnle\010stocgnlh\007stocgno\006stocgo\005stoch\006stoche\005stocl\006"
    "stocle\006stoclh\006stocne\006stocnh\007stocnhe\006stocnl\007stocnle\007"
    "stocnlh\006stocno\005stoco\004strl\004strv\005strvg\003sty\004sxbr\002s"
    "y\002tm\004tmhh\004tmhl\004tmlh\004tmll\003tmy\001x\002xc\002xg\003xgr\004"
    "xgrk\002xi\004xihf\004xilf\003xiy\002xr\003xrk\002xy";

namespace {
  struct MatchEntry {
    uint16_t Mnemonic;
    uint16_t Opcode;
    uint16_t ConvertFn;
    uint8_t RequiredFeatures;
    uint8_t Classes[5];
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
  { 0 /* a */, SystemZ::A, Convert__GR321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 2 /* adb */, SystemZ::ADB, Convert__FP641_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_FP64, MCK_BDXAddr64Disp12 }, },
  { 6 /* adbr */, SystemZ::ADBR, Convert__FP641_0__Tie0__FP641_1, 0, { MCK_FP64, MCK_FP64 }, },
  { 11 /* aeb */, SystemZ::AEB, Convert__FP321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_FP32, MCK_BDXAddr64Disp12 }, },
  { 15 /* aebr */, SystemZ::AEBR, Convert__FP321_0__Tie0__FP321_1, 0, { MCK_FP32, MCK_FP32 }, },
  { 20 /* afi */, SystemZ::AFI, Convert__GR321_0__Tie0__S32Imm1_1, 0, { MCK_GR32, MCK_S32Imm }, },
  { 24 /* ag */, SystemZ::AG, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 27 /* agf */, SystemZ::AGF, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 31 /* agfi */, SystemZ::AGFI, Convert__GR641_0__Tie0__S32Imm1_1, 0, { MCK_GR64, MCK_S32Imm }, },
  { 36 /* agfr */, SystemZ::AGFR, Convert__GR641_0__Tie0__GR321_1, 0, { MCK_GR64, MCK_GR32 }, },
  { 41 /* aghi */, SystemZ::AGHI, Convert__GR641_0__Tie0__S16Imm1_1, 0, { MCK_GR64, MCK_S16Imm }, },
  { 46 /* aghik */, SystemZ::AGHIK, Convert__GR641_0__GR641_1__S16Imm1_2, Feature_FeatureDistinctOps, { MCK_GR64, MCK_GR64, MCK_S16Imm }, },
  { 52 /* agr */, SystemZ::AGR, Convert__GR641_0__Tie0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 56 /* agrk */, SystemZ::AGRK, Convert__GR641_0__GR641_1__GR641_2, Feature_FeatureDistinctOps, { MCK_GR64, MCK_GR64, MCK_GR64 }, },
  { 61 /* agsi */, SystemZ::AGSI, Convert__BDAddr64Disp202_0__S8Imm1_1, 0, { MCK_BDAddr64Disp20, MCK_S8Imm }, },
  { 66 /* ah */, SystemZ::AH, Convert__GR321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 69 /* ahi */, SystemZ::AHI, Convert__GR321_0__Tie0__S16Imm1_1, 0, { MCK_GR32, MCK_S16Imm }, },
  { 73 /* ahik */, SystemZ::AHIK, Convert__GR321_0__GR321_1__S16Imm1_2, Feature_FeatureDistinctOps, { MCK_GR32, MCK_GR32, MCK_S16Imm }, },
  { 78 /* ahy */, SystemZ::AHY, Convert__GR321_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 82 /* aih */, SystemZ::AIH, Convert__GRH321_0__Tie0__S32Imm1_1, Feature_FeatureHighWord, { MCK_GRH32, MCK_S32Imm }, },
  { 86 /* al */, SystemZ::AL, Convert__GR321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 89 /* alc */, SystemZ::ALC, Convert__GR321_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 93 /* alcg */, SystemZ::ALCG, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 98 /* alcgr */, SystemZ::ALCGR, Convert__GR641_0__Tie0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 104 /* alcr */, SystemZ::ALCR, Convert__GR321_0__Tie0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 109 /* alfi */, SystemZ::ALFI, Convert__GR321_0__Tie0__U32Imm1_1, 0, { MCK_GR32, MCK_U32Imm }, },
  { 114 /* alg */, SystemZ::ALG, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 118 /* algf */, SystemZ::ALGF, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 123 /* algfi */, SystemZ::ALGFI, Convert__GR641_0__Tie0__U32Imm1_1, 0, { MCK_GR64, MCK_U32Imm }, },
  { 129 /* algfr */, SystemZ::ALGFR, Convert__GR641_0__Tie0__GR321_1, 0, { MCK_GR64, MCK_GR32 }, },
  { 135 /* alghsik */, SystemZ::ALGHSIK, Convert__GR641_0__GR641_1__S16Imm1_2, Feature_FeatureDistinctOps, { MCK_GR64, MCK_GR64, MCK_S16Imm }, },
  { 143 /* algr */, SystemZ::ALGR, Convert__GR641_0__Tie0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 148 /* algrk */, SystemZ::ALGRK, Convert__GR641_0__GR641_1__GR641_2, Feature_FeatureDistinctOps, { MCK_GR64, MCK_GR64, MCK_GR64 }, },
  { 154 /* alhsik */, SystemZ::ALHSIK, Convert__GR321_0__GR321_1__S16Imm1_2, Feature_FeatureDistinctOps, { MCK_GR32, MCK_GR32, MCK_S16Imm }, },
  { 161 /* alr */, SystemZ::ALR, Convert__GR321_0__Tie0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 165 /* alrk */, SystemZ::ALRK, Convert__GR321_0__GR321_1__GR321_2, Feature_FeatureDistinctOps, { MCK_GR32, MCK_GR32, MCK_GR32 }, },
  { 170 /* aly */, SystemZ::ALY, Convert__GR321_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 174 /* ar */, SystemZ::AR, Convert__GR321_0__Tie0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 177 /* ark */, SystemZ::ARK, Convert__GR321_0__GR321_1__GR321_2, Feature_FeatureDistinctOps, { MCK_GR32, MCK_GR32, MCK_GR32 }, },
  { 181 /* asi */, SystemZ::ASI, Convert__BDAddr64Disp202_0__S8Imm1_1, 0, { MCK_BDAddr64Disp20, MCK_S8Imm }, },
  { 185 /* axbr */, SystemZ::AXBR, Convert__FP1281_0__Tie0__FP1281_1, 0, { MCK_FP128, MCK_FP128 }, },
  { 190 /* ay */, SystemZ::AY, Convert__GR321_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 193 /* basr */, SystemZ::BASR, Convert__GR641_0__ADDR641_1, 0, { MCK_GR64, MCK_ADDR64 }, },
  { 198 /* bcr */, SystemZ::AsmBCR, Convert__U4Imm1_0__GR641_1, 0, { MCK_U4Imm, MCK_GR64 }, },
  { 202 /* ber */, SystemZ::AsmEBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 206 /* bher */, SystemZ::AsmHEBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 211 /* bhr */, SystemZ::AsmHBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 215 /* bler */, SystemZ::AsmLEBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 220 /* blhr */, SystemZ::AsmLHBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 225 /* blr */, SystemZ::AsmLBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 229 /* bner */, SystemZ::AsmNEBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 234 /* bnher */, SystemZ::AsmNHEBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 240 /* bnhr */, SystemZ::AsmNHBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 245 /* bnler */, SystemZ::AsmNLEBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 251 /* bnlhr */, SystemZ::AsmNLHBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 257 /* bnlr */, SystemZ::AsmNLBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 262 /* bnor */, SystemZ::AsmNOBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 267 /* bor */, SystemZ::AsmOBR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 271 /* br */, SystemZ::BR, Convert__ADDR641_0, 0, { MCK_ADDR64 }, },
  { 274 /* bras */, SystemZ::BRAS, Convert__GR641_0__PCRel161_1, 0, { MCK_GR64, MCK_PCRel16 }, },
  { 279 /* brasl */, SystemZ::BRASL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 285 /* brc */, SystemZ::AsmBRC, Convert__U4Imm1_0__PCRel161_1, 0, { MCK_U4Imm, MCK_PCRel16 }, },
  { 289 /* brcl */, SystemZ::AsmBRCL, Convert__U4Imm1_0__PCRel321_1, 0, { MCK_U4Imm, MCK_PCRel32 }, },
  { 294 /* brct */, SystemZ::BRCT, Convert__GR321_0__Tie0__PCRel161_1, 0, { MCK_GR32, MCK_PCRel16 }, },
  { 299 /* brctg */, SystemZ::BRCTG, Convert__GR641_0__Tie0__PCRel161_1, 0, { MCK_GR64, MCK_PCRel16 }, },
  { 305 /* c */, SystemZ::C, Convert__GR321_0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 307 /* cdb */, SystemZ::CDB, Convert__FP641_0__BDXAddr64Disp123_1, 0, { MCK_FP64, MCK_BDXAddr64Disp12 }, },
  { 311 /* cdbr */, SystemZ::CDBR, Convert__FP641_0__FP641_1, 0, { MCK_FP64, MCK_FP64 }, },
  { 316 /* cdfbr */, SystemZ::CDFBR, Convert__FP641_0__GR321_1, 0, { MCK_FP64, MCK_GR32 }, },
  { 322 /* cdgbr */, SystemZ::CDGBR, Convert__FP641_0__GR641_1, 0, { MCK_FP64, MCK_GR64 }, },
  { 328 /* ceb */, SystemZ::CEB, Convert__FP321_0__BDXAddr64Disp123_1, 0, { MCK_FP32, MCK_BDXAddr64Disp12 }, },
  { 332 /* cebr */, SystemZ::CEBR, Convert__FP321_0__FP321_1, 0, { MCK_FP32, MCK_FP32 }, },
  { 337 /* cefbr */, SystemZ::CEFBR, Convert__FP321_0__GR321_1, 0, { MCK_FP32, MCK_GR32 }, },
  { 343 /* cegbr */, SystemZ::CEGBR, Convert__FP321_0__GR641_1, 0, { MCK_FP32, MCK_GR64 }, },
  { 349 /* cfdbr */, SystemZ::CFDBR, Convert__GR321_0__U4Imm1_1__FP641_2, 0, { MCK_GR32, MCK_U4Imm, MCK_FP64 }, },
  { 355 /* cfebr */, SystemZ::CFEBR, Convert__GR321_0__U4Imm1_1__FP321_2, 0, { MCK_GR32, MCK_U4Imm, MCK_FP32 }, },
  { 361 /* cfi */, SystemZ::CFI, Convert__GR321_0__S32Imm1_1, 0, { MCK_GR32, MCK_S32Imm }, },
  { 365 /* cfxbr */, SystemZ::CFXBR, Convert__GR321_0__U4Imm1_1__FP1281_2, 0, { MCK_GR32, MCK_U4Imm, MCK_FP128 }, },
  { 371 /* cg */, SystemZ::CG, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 374 /* cgdbr */, SystemZ::CGDBR, Convert__GR641_0__U4Imm1_1__FP641_2, 0, { MCK_GR64, MCK_U4Imm, MCK_FP64 }, },
  { 380 /* cgebr */, SystemZ::CGEBR, Convert__GR641_0__U4Imm1_1__FP321_2, 0, { MCK_GR64, MCK_U4Imm, MCK_FP32 }, },
  { 386 /* cgf */, SystemZ::CGF, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 390 /* cgfi */, SystemZ::CGFI, Convert__GR641_0__S32Imm1_1, 0, { MCK_GR64, MCK_S32Imm }, },
  { 395 /* cgfr */, SystemZ::CGFR, Convert__GR641_0__GR321_1, 0, { MCK_GR64, MCK_GR32 }, },
  { 400 /* cgfrl */, SystemZ::CGFRL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 406 /* cgh */, SystemZ::CGH, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 410 /* cghi */, SystemZ::CGHI, Convert__GR641_0__S16Imm1_1, 0, { MCK_GR64, MCK_S16Imm }, },
  { 415 /* cghrl */, SystemZ::CGHRL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 421 /* cghsi */, SystemZ::CGHSI, Convert__BDAddr64Disp122_0__S16Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_S16Imm }, },
  { 427 /* cgij */, SystemZ::AsmCGIJ, Convert__GR641_0__S8Imm1_1__U4Imm1_2__PCRel161_3, 0, { MCK_GR64, MCK_S8Imm, MCK_U4Imm, MCK_PCRel16 }, },
  { 432 /* cgije */, SystemZ::AsmJECGI, Convert__GR641_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_S8Imm, MCK_PCRel16 }, },
  { 438 /* cgijh */, SystemZ::AsmJHCGI, Convert__GR641_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_S8Imm, MCK_PCRel16 }, },
  { 444 /* cgijhe */, SystemZ::AsmJHECGI, Convert__GR641_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_S8Imm, MCK_PCRel16 }, },
  { 451 /* cgijl */, SystemZ::AsmJLCGI, Convert__GR641_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_S8Imm, MCK_PCRel16 }, },
  { 457 /* cgijle */, SystemZ::AsmJLECGI, Convert__GR641_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_S8Imm, MCK_PCRel16 }, },
  { 464 /* cgijlh */, SystemZ::AsmJLHCGI, Convert__GR641_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_S8Imm, MCK_PCRel16 }, },
  { 471 /* cgijne */, SystemZ::AsmJLHAltCGI, Convert__GR641_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_S8Imm, MCK_PCRel16 }, },
  { 478 /* cgijnh */, SystemZ::AsmJLEAltCGI, Convert__GR641_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_S8Imm, MCK_PCRel16 }, },
  { 485 /* cgijnhe */, SystemZ::AsmJLAltCGI, Convert__GR641_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_S8Imm, MCK_PCRel16 }, },
  { 493 /* cgijnl */, SystemZ::AsmJHEAltCGI, Convert__GR641_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_S8Imm, MCK_PCRel16 }, },
  { 500 /* cgijnle */, SystemZ::AsmJHAltCGI, Convert__GR641_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_S8Imm, MCK_PCRel16 }, },
  { 508 /* cgijnlh */, SystemZ::AsmJEAltCGI, Convert__GR641_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_S8Imm, MCK_PCRel16 }, },
  { 516 /* cgr */, SystemZ::CGR, Convert__GR641_0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 520 /* cgrj */, SystemZ::AsmCGRJ, Convert__GR641_0__GR641_1__U4Imm1_2__PCRel161_3, 0, { MCK_GR64, MCK_GR64, MCK_U4Imm, MCK_PCRel16 }, },
  { 525 /* cgrje */, SystemZ::AsmJECGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 531 /* cgrjh */, SystemZ::AsmJHCGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 537 /* cgrjhe */, SystemZ::AsmJHECGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 544 /* cgrjl */, SystemZ::AsmJLCGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 550 /* cgrjle */, SystemZ::AsmJLECGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 557 /* cgrjlh */, SystemZ::AsmJLHCGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 564 /* cgrjne */, SystemZ::AsmJLHAltCGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 571 /* cgrjnh */, SystemZ::AsmJLEAltCGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 578 /* cgrjnhe */, SystemZ::AsmJLAltCGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 586 /* cgrjnl */, SystemZ::AsmJHEAltCGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 593 /* cgrjnle */, SystemZ::AsmJHAltCGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 601 /* cgrjnlh */, SystemZ::AsmJEAltCGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 609 /* cgrl */, SystemZ::CGRL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 614 /* cgxbr */, SystemZ::CGXBR, Convert__GR641_0__U4Imm1_1__FP1281_2, 0, { MCK_GR64, MCK_U4Imm, MCK_FP128 }, },
  { 620 /* ch */, SystemZ::CH, Convert__GR321_0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 623 /* chf */, SystemZ::CHF, Convert__GRH321_0__BDXAddr64Disp203_1, Feature_FeatureHighWord, { MCK_GRH32, MCK_BDXAddr64Disp20 }, },
  { 627 /* chhsi */, SystemZ::CHHSI, Convert__BDAddr64Disp122_0__S16Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_S16Imm }, },
  { 633 /* chi */, SystemZ::CHI, Convert__GR321_0__S16Imm1_1, 0, { MCK_GR32, MCK_S16Imm }, },
  { 637 /* chrl */, SystemZ::CHRL, Convert__GR321_0__PCRel321_1, 0, { MCK_GR32, MCK_PCRel32 }, },
  { 642 /* chsi */, SystemZ::CHSI, Convert__BDAddr64Disp122_0__S16Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_S16Imm }, },
  { 647 /* chy */, SystemZ::CHY, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 651 /* cih */, SystemZ::CIH, Convert__GRH321_0__S32Imm1_1, Feature_FeatureHighWord, { MCK_GRH32, MCK_S32Imm }, },
  { 655 /* cij */, SystemZ::AsmCIJ, Convert__GR321_0__S8Imm1_1__U4Imm1_2__PCRel161_3, 0, { MCK_GR32, MCK_S8Imm, MCK_U4Imm, MCK_PCRel16 }, },
  { 659 /* cije */, SystemZ::AsmJECI, Convert__GR321_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_S8Imm, MCK_PCRel16 }, },
  { 664 /* cijh */, SystemZ::AsmJHCI, Convert__GR321_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_S8Imm, MCK_PCRel16 }, },
  { 669 /* cijhe */, SystemZ::AsmJHECI, Convert__GR321_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_S8Imm, MCK_PCRel16 }, },
  { 675 /* cijl */, SystemZ::AsmJLCI, Convert__GR321_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_S8Imm, MCK_PCRel16 }, },
  { 680 /* cijle */, SystemZ::AsmJLECI, Convert__GR321_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_S8Imm, MCK_PCRel16 }, },
  { 686 /* cijlh */, SystemZ::AsmJLHCI, Convert__GR321_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_S8Imm, MCK_PCRel16 }, },
  { 692 /* cijne */, SystemZ::AsmJLHAltCI, Convert__GR321_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_S8Imm, MCK_PCRel16 }, },
  { 698 /* cijnh */, SystemZ::AsmJLEAltCI, Convert__GR321_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_S8Imm, MCK_PCRel16 }, },
  { 704 /* cijnhe */, SystemZ::AsmJLAltCI, Convert__GR321_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_S8Imm, MCK_PCRel16 }, },
  { 711 /* cijnl */, SystemZ::AsmJHEAltCI, Convert__GR321_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_S8Imm, MCK_PCRel16 }, },
  { 717 /* cijnle */, SystemZ::AsmJHAltCI, Convert__GR321_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_S8Imm, MCK_PCRel16 }, },
  { 724 /* cijnlh */, SystemZ::AsmJEAltCI, Convert__GR321_0__S8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_S8Imm, MCK_PCRel16 }, },
  { 731 /* cl */, SystemZ::CL, Convert__GR321_0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 734 /* clc */, SystemZ::CLC, Convert__BDLAddr64Disp12Len83_0__BDAddr64Disp122_1, 0, { MCK_BDLAddr64Disp12Len8, MCK_BDAddr64Disp12 }, },
  { 738 /* clfhsi */, SystemZ::CLFHSI, Convert__BDAddr64Disp122_0__U16Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_U16Imm }, },
  { 745 /* clfi */, SystemZ::CLFI, Convert__GR321_0__U32Imm1_1, 0, { MCK_GR32, MCK_U32Imm }, },
  { 750 /* clg */, SystemZ::CLG, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 754 /* clgf */, SystemZ::CLGF, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 759 /* clgfi */, SystemZ::CLGFI, Convert__GR641_0__U32Imm1_1, 0, { MCK_GR64, MCK_U32Imm }, },
  { 765 /* clgfr */, SystemZ::CLGFR, Convert__GR641_0__GR321_1, 0, { MCK_GR64, MCK_GR32 }, },
  { 771 /* clgfrl */, SystemZ::CLGFRL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 778 /* clghrl */, SystemZ::CLGHRL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 785 /* clghsi */, SystemZ::CLGHSI, Convert__BDAddr64Disp122_0__U16Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_U16Imm }, },
  { 792 /* clgij */, SystemZ::AsmCLGIJ, Convert__GR641_0__U8Imm1_1__U4Imm1_2__PCRel161_3, 0, { MCK_GR64, MCK_U8Imm, MCK_U4Imm, MCK_PCRel16 }, },
  { 798 /* clgije */, SystemZ::AsmJECLGI, Convert__GR641_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_U8Imm, MCK_PCRel16 }, },
  { 805 /* clgijh */, SystemZ::AsmJHCLGI, Convert__GR641_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_U8Imm, MCK_PCRel16 }, },
  { 812 /* clgijhe */, SystemZ::AsmJHECLGI, Convert__GR641_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_U8Imm, MCK_PCRel16 }, },
  { 820 /* clgijl */, SystemZ::AsmJLCLGI, Convert__GR641_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_U8Imm, MCK_PCRel16 }, },
  { 827 /* clgijle */, SystemZ::AsmJLECLGI, Convert__GR641_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_U8Imm, MCK_PCRel16 }, },
  { 835 /* clgijlh */, SystemZ::AsmJLHCLGI, Convert__GR641_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_U8Imm, MCK_PCRel16 }, },
  { 843 /* clgijne */, SystemZ::AsmJLHAltCLGI, Convert__GR641_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_U8Imm, MCK_PCRel16 }, },
  { 851 /* clgijnh */, SystemZ::AsmJLEAltCLGI, Convert__GR641_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_U8Imm, MCK_PCRel16 }, },
  { 859 /* clgijnhe */, SystemZ::AsmJLAltCLGI, Convert__GR641_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_U8Imm, MCK_PCRel16 }, },
  { 868 /* clgijnl */, SystemZ::AsmJHEAltCLGI, Convert__GR641_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_U8Imm, MCK_PCRel16 }, },
  { 876 /* clgijnle */, SystemZ::AsmJHAltCLGI, Convert__GR641_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_U8Imm, MCK_PCRel16 }, },
  { 885 /* clgijnlh */, SystemZ::AsmJEAltCLGI, Convert__GR641_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR64, MCK_U8Imm, MCK_PCRel16 }, },
  { 894 /* clgr */, SystemZ::CLGR, Convert__GR641_0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 899 /* clgrj */, SystemZ::AsmCLGRJ, Convert__GR641_0__GR641_1__U4Imm1_2__PCRel161_3, 0, { MCK_GR64, MCK_GR64, MCK_U4Imm, MCK_PCRel16 }, },
  { 905 /* clgrje */, SystemZ::AsmJECLGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 912 /* clgrjh */, SystemZ::AsmJHCLGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 919 /* clgrjhe */, SystemZ::AsmJHECLGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 927 /* clgrjl */, SystemZ::AsmJLCLGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 934 /* clgrjle */, SystemZ::AsmJLECLGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 942 /* clgrjlh */, SystemZ::AsmJLHCLGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 950 /* clgrjne */, SystemZ::AsmJLHAltCLGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 958 /* clgrjnh */, SystemZ::AsmJLEAltCLGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 966 /* clgrjnhe */, SystemZ::AsmJLAltCLGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 975 /* clgrjnl */, SystemZ::AsmJHEAltCLGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 983 /* clgrjnle */, SystemZ::AsmJHAltCLGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 992 /* clgrjnlh */, SystemZ::AsmJEAltCLGR, Convert__GR641_0__GR641_1__PCRel161_2, 0, { MCK_GR64, MCK_GR64, MCK_PCRel16 }, },
  { 1001 /* clgrl */, SystemZ::CLGRL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 1007 /* clhf */, SystemZ::CLHF, Convert__GRH321_0__BDXAddr64Disp203_1, Feature_FeatureHighWord, { MCK_GRH32, MCK_BDXAddr64Disp20 }, },
  { 1012 /* clhhsi */, SystemZ::CLHHSI, Convert__BDAddr64Disp122_0__U16Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_U16Imm }, },
  { 1019 /* clhrl */, SystemZ::CLHRL, Convert__GR321_0__PCRel321_1, 0, { MCK_GR32, MCK_PCRel32 }, },
  { 1025 /* cli */, SystemZ::CLI, Convert__BDAddr64Disp122_0__U8Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_U8Imm }, },
  { 1029 /* clih */, SystemZ::CLIH, Convert__GR321_0__U32Imm1_1, Feature_FeatureHighWord, { MCK_GR32, MCK_U32Imm }, },
  { 1034 /* clij */, SystemZ::AsmCLIJ, Convert__GR321_0__U8Imm1_1__U4Imm1_2__PCRel161_3, 0, { MCK_GR32, MCK_U8Imm, MCK_U4Imm, MCK_PCRel16 }, },
  { 1039 /* clije */, SystemZ::AsmJECLI, Convert__GR321_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_U8Imm, MCK_PCRel16 }, },
  { 1045 /* clijh */, SystemZ::AsmJHCLI, Convert__GR321_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_U8Imm, MCK_PCRel16 }, },
  { 1051 /* clijhe */, SystemZ::AsmJHECLI, Convert__GR321_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_U8Imm, MCK_PCRel16 }, },
  { 1058 /* clijl */, SystemZ::AsmJLCLI, Convert__GR321_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_U8Imm, MCK_PCRel16 }, },
  { 1064 /* clijle */, SystemZ::AsmJLECLI, Convert__GR321_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_U8Imm, MCK_PCRel16 }, },
  { 1071 /* clijlh */, SystemZ::AsmJLHCLI, Convert__GR321_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_U8Imm, MCK_PCRel16 }, },
  { 1078 /* clijne */, SystemZ::AsmJLHAltCLI, Convert__GR321_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_U8Imm, MCK_PCRel16 }, },
  { 1085 /* clijnh */, SystemZ::AsmJLEAltCLI, Convert__GR321_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_U8Imm, MCK_PCRel16 }, },
  { 1092 /* clijnhe */, SystemZ::AsmJLAltCLI, Convert__GR321_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_U8Imm, MCK_PCRel16 }, },
  { 1100 /* clijnl */, SystemZ::AsmJHEAltCLI, Convert__GR321_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_U8Imm, MCK_PCRel16 }, },
  { 1107 /* clijnle */, SystemZ::AsmJHAltCLI, Convert__GR321_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_U8Imm, MCK_PCRel16 }, },
  { 1115 /* clijnlh */, SystemZ::AsmJEAltCLI, Convert__GR321_0__U8Imm1_1__PCRel161_2, 0, { MCK_GR32, MCK_U8Imm, MCK_PCRel16 }, },
  { 1123 /* cliy */, SystemZ::CLIY, Convert__BDAddr64Disp202_0__U8Imm1_1, 0, { MCK_BDAddr64Disp20, MCK_U8Imm }, },
  { 1128 /* clr */, SystemZ::CLR, Convert__GR321_0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 1132 /* clrj */, SystemZ::AsmCLRJ, Convert__GR321_0__GR321_1__U4Imm1_2__PCRel161_3, 0, { MCK_GR32, MCK_GR32, MCK_U4Imm, MCK_PCRel16 }, },
  { 1137 /* clrje */, SystemZ::AsmJECLR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1143 /* clrjh */, SystemZ::AsmJHCLR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1149 /* clrjhe */, SystemZ::AsmJHECLR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1156 /* clrjl */, SystemZ::AsmJLCLR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1162 /* clrjle */, SystemZ::AsmJLECLR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1169 /* clrjlh */, SystemZ::AsmJLHCLR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1176 /* clrjne */, SystemZ::AsmJLHAltCLR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1183 /* clrjnh */, SystemZ::AsmJLEAltCLR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1190 /* clrjnhe */, SystemZ::AsmJLAltCLR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1198 /* clrjnl */, SystemZ::AsmJHEAltCLR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1205 /* clrjnle */, SystemZ::AsmJHAltCLR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1213 /* clrjnlh */, SystemZ::AsmJEAltCLR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1221 /* clrl */, SystemZ::CLRL, Convert__GR321_0__PCRel321_1, 0, { MCK_GR32, MCK_PCRel32 }, },
  { 1226 /* clst */, SystemZ::CLST, Convert__GR641_0__GR641_1__Tie0__Tie1, 0, { MCK_GR64, MCK_GR64 }, },
  { 1231 /* cly */, SystemZ::CLY, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 1235 /* cpsdr */, SystemZ::CPSDRdd, Convert__FP641_0__FP641_1__FP641_2, 0, { MCK_FP64, MCK_FP64, MCK_FP64 }, },
  { 1241 /* cr */, SystemZ::CR, Convert__GR321_0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 1244 /* crj */, SystemZ::AsmCRJ, Convert__GR321_0__GR321_1__U4Imm1_2__PCRel161_3, 0, { MCK_GR32, MCK_GR32, MCK_U4Imm, MCK_PCRel16 }, },
  { 1248 /* crje */, SystemZ::AsmJECR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1253 /* crjh */, SystemZ::AsmJHCR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1258 /* crjhe */, SystemZ::AsmJHECR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1264 /* crjl */, SystemZ::AsmJLCR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1269 /* crjle */, SystemZ::AsmJLECR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1275 /* crjlh */, SystemZ::AsmJLHCR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1281 /* crjne */, SystemZ::AsmJLHAltCR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1287 /* crjnh */, SystemZ::AsmJLEAltCR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1293 /* crjnhe */, SystemZ::AsmJLAltCR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1300 /* crjnl */, SystemZ::AsmJHEAltCR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1306 /* crjnle */, SystemZ::AsmJHAltCR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1313 /* crjnlh */, SystemZ::AsmJEAltCR, Convert__GR321_0__GR321_1__PCRel161_2, 0, { MCK_GR32, MCK_GR32, MCK_PCRel16 }, },
  { 1320 /* crl */, SystemZ::CRL, Convert__GR321_0__PCRel321_1, 0, { MCK_GR32, MCK_PCRel32 }, },
  { 1324 /* cs */, SystemZ::CS, Convert__GR321_0__Tie0__GR321_1__BDAddr64Disp122_2, 0, { MCK_GR32, MCK_GR32, MCK_BDAddr64Disp12 }, },
  { 1327 /* csg */, SystemZ::CSG, Convert__GR641_0__Tie0__GR641_1__BDAddr64Disp202_2, 0, { MCK_GR64, MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 1331 /* csy */, SystemZ::CSY, Convert__GR321_0__Tie0__GR321_1__BDAddr64Disp202_2, 0, { MCK_GR32, MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 1335 /* cxbr */, SystemZ::CXBR, Convert__FP1281_0__FP1281_1, 0, { MCK_FP128, MCK_FP128 }, },
  { 1340 /* cxfbr */, SystemZ::CXFBR, Convert__FP1281_0__GR321_1, 0, { MCK_FP128, MCK_GR32 }, },
  { 1346 /* cxgbr */, SystemZ::CXGBR, Convert__FP1281_0__GR641_1, 0, { MCK_FP128, MCK_GR64 }, },
  { 1352 /* cy */, SystemZ::CY, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 1355 /* ddb */, SystemZ::DDB, Convert__FP641_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_FP64, MCK_BDXAddr64Disp12 }, },
  { 1359 /* ddbr */, SystemZ::DDBR, Convert__FP641_0__Tie0__FP641_1, 0, { MCK_FP64, MCK_FP64 }, },
  { 1364 /* deb */, SystemZ::DEB, Convert__FP321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_FP32, MCK_BDXAddr64Disp12 }, },
  { 1368 /* debr */, SystemZ::DEBR, Convert__FP321_0__Tie0__FP321_1, 0, { MCK_FP32, MCK_FP32 }, },
  { 1373 /* dl */, SystemZ::DL, Convert__GR1281_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR128, MCK_BDXAddr64Disp20 }, },
  { 1376 /* dlg */, SystemZ::DLG, Convert__GR1281_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR128, MCK_BDXAddr64Disp20 }, },
  { 1380 /* dlgr */, SystemZ::DLGR, Convert__GR1281_0__Tie0__GR641_1, 0, { MCK_GR128, MCK_GR64 }, },
  { 1385 /* dlr */, SystemZ::DLR, Convert__GR1281_0__Tie0__GR321_1, 0, { MCK_GR128, MCK_GR32 }, },
  { 1389 /* dsg */, SystemZ::DSG, Convert__GR1281_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR128, MCK_BDXAddr64Disp20 }, },
  { 1393 /* dsgf */, SystemZ::DSGF, Convert__GR1281_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR128, MCK_BDXAddr64Disp20 }, },
  { 1398 /* dsgfr */, SystemZ::DSGFR, Convert__GR1281_0__Tie0__GR321_1, 0, { MCK_GR128, MCK_GR32 }, },
  { 1404 /* dsgr */, SystemZ::DSGR, Convert__GR1281_0__Tie0__GR641_1, 0, { MCK_GR128, MCK_GR64 }, },
  { 1409 /* dxbr */, SystemZ::DXBR, Convert__FP1281_0__Tie0__FP1281_1, 0, { MCK_FP128, MCK_FP128 }, },
  { 1414 /* ear */, SystemZ::EAR, Convert__GR321_0__AccessReg1_1, 0, { MCK_GR32, MCK_AccessReg }, },
  { 1418 /* fidbr */, SystemZ::FIDBR, Convert__FP641_0__U4Imm1_1__FP641_2, 0, { MCK_FP64, MCK_U4Imm, MCK_FP64 }, },
  { 1424 /* fidbra */, SystemZ::FIDBRA, Convert__FP641_0__U4Imm1_1__FP641_2__U4Imm1_3, Feature_FeatureFPExtension, { MCK_FP64, MCK_U4Imm, MCK_FP64, MCK_U4Imm }, },
  { 1431 /* fiebr */, SystemZ::FIEBR, Convert__FP321_0__U4Imm1_1__FP321_2, 0, { MCK_FP32, MCK_U4Imm, MCK_FP32 }, },
  { 1437 /* fiebra */, SystemZ::FIEBRA, Convert__FP321_0__U4Imm1_1__FP321_2__U4Imm1_3, Feature_FeatureFPExtension, { MCK_FP32, MCK_U4Imm, MCK_FP32, MCK_U4Imm }, },
  { 1444 /* fixbr */, SystemZ::FIXBR, Convert__FP1281_0__U4Imm1_1__FP1281_2, 0, { MCK_FP128, MCK_U4Imm, MCK_FP128 }, },
  { 1450 /* fixbra */, SystemZ::FIXBRA, Convert__FP1281_0__U4Imm1_1__FP1281_2__U4Imm1_3, Feature_FeatureFPExtension, { MCK_FP128, MCK_U4Imm, MCK_FP128, MCK_U4Imm }, },
  { 1457 /* flogr */, SystemZ::FLOGR, Convert__GR1281_0__GR641_1, 0, { MCK_GR128, MCK_GR64 }, },
  { 1463 /* ic */, SystemZ::IC, Convert__GR641_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_GR64, MCK_BDXAddr64Disp12 }, },
  { 1466 /* icy */, SystemZ::ICY, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 1470 /* iihf */, SystemZ::IIHF, Convert__GRH321_0__U32Imm1_1, 0, { MCK_GRH32, MCK_U32Imm }, },
  { 1475 /* iihh */, SystemZ::IIHH, Convert__GRH321_0__Tie0__U16Imm1_1, 0, { MCK_GRH32, MCK_U16Imm }, },
  { 1480 /* iihl */, SystemZ::IIHL, Convert__GRH321_0__Tie0__U16Imm1_1, 0, { MCK_GRH32, MCK_U16Imm }, },
  { 1485 /* iilf */, SystemZ::IILF, Convert__GR321_0__U32Imm1_1, 0, { MCK_GR32, MCK_U32Imm }, },
  { 1490 /* iilh */, SystemZ::IILH, Convert__GR321_0__Tie0__U16Imm1_1, 0, { MCK_GR32, MCK_U16Imm }, },
  { 1495 /* iill */, SystemZ::IILL, Convert__GR321_0__Tie0__U16Imm1_1, 0, { MCK_GR32, MCK_U16Imm }, },
  { 1500 /* ipm */, SystemZ::IPM, Convert__GR321_0, 0, { MCK_GR32 }, },
  { 1504 /* j */, SystemZ::J, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1506 /* je */, SystemZ::AsmEJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1509 /* jg */, SystemZ::JG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1512 /* jge */, SystemZ::AsmEJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1516 /* jgh */, SystemZ::AsmHJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1520 /* jghe */, SystemZ::AsmHEJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1525 /* jgl */, SystemZ::AsmLJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1529 /* jgle */, SystemZ::AsmLEJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1534 /* jglh */, SystemZ::AsmLHJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1539 /* jgne */, SystemZ::AsmNEJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1544 /* jgnh */, SystemZ::AsmNHJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1549 /* jgnhe */, SystemZ::AsmNHEJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1555 /* jgnl */, SystemZ::AsmNLJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1560 /* jgnle */, SystemZ::AsmNLEJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1566 /* jgnlh */, SystemZ::AsmNLHJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1572 /* jgno */, SystemZ::AsmNOJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1577 /* jgo */, SystemZ::AsmOJG, Convert__PCRel321_0, 0, { MCK_PCRel32 }, },
  { 1581 /* jh */, SystemZ::AsmHJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1584 /* jhe */, SystemZ::AsmHEJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1588 /* jl */, SystemZ::AsmLJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1591 /* jle */, SystemZ::AsmLEJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1595 /* jlh */, SystemZ::AsmLHJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1599 /* jne */, SystemZ::AsmNEJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1603 /* jnh */, SystemZ::AsmNHJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1607 /* jnhe */, SystemZ::AsmNHEJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1612 /* jnl */, SystemZ::AsmNLJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1616 /* jnle */, SystemZ::AsmNLEJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1621 /* jnlh */, SystemZ::AsmNLHJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1626 /* jno */, SystemZ::AsmNOJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1630 /* jo */, SystemZ::AsmOJ, Convert__PCRel161_0, 0, { MCK_PCRel16 }, },
  { 1633 /* l */, SystemZ::L, Convert__GR321_0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 1635 /* la */, SystemZ::LA, Convert__GR641_0__BDXAddr64Disp123_1, 0, { MCK_GR64, MCK_BDXAddr64Disp12 }, },
  { 1638 /* larl */, SystemZ::LARL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 1643 /* lay */, SystemZ::LAY, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 1647 /* lb */, SystemZ::LB, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 1650 /* lbh */, SystemZ::LBH, Convert__GRH321_0__BDXAddr64Disp203_1, Feature_FeatureHighWord, { MCK_GRH32, MCK_BDXAddr64Disp20 }, },
  { 1654 /* lbr */, SystemZ::LBR, Convert__GR321_0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 1658 /* lcdbr */, SystemZ::LCDBR, Convert__FP641_0__FP641_1, 0, { MCK_FP64, MCK_FP64 }, },
  { 1664 /* lcebr */, SystemZ::LCEBR, Convert__FP321_0__FP321_1, 0, { MCK_FP32, MCK_FP32 }, },
  { 1670 /* lcgfr */, SystemZ::LCGFR, Convert__GR641_0__GR321_1, 0, { MCK_GR64, MCK_GR32 }, },
  { 1676 /* lcgr */, SystemZ::LCGR, Convert__GR641_0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 1681 /* lcr */, SystemZ::LCR, Convert__GR321_0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 1685 /* lcxbr */, SystemZ::LCXBR, Convert__FP1281_0__FP1281_1, 0, { MCK_FP128, MCK_FP128 }, },
  { 1691 /* ld */, SystemZ::LD, Convert__FP641_0__BDXAddr64Disp123_1, 0, { MCK_FP64, MCK_BDXAddr64Disp12 }, },
  { 1694 /* ldeb */, SystemZ::LDEB, Convert__FP641_0__BDXAddr64Disp123_1, 0, { MCK_FP64, MCK_BDXAddr64Disp12 }, },
  { 1699 /* ldebr */, SystemZ::LDEBR, Convert__FP641_0__FP321_1, 0, { MCK_FP64, MCK_FP32 }, },
  { 1705 /* ldgr */, SystemZ::LDGR, Convert__FP641_0__GR641_1, 0, { MCK_FP64, MCK_GR64 }, },
  { 1710 /* ldr */, SystemZ::LDR, Convert__FP641_0__FP641_1, 0, { MCK_FP64, MCK_FP64 }, },
  { 1714 /* ldxbr */, SystemZ::LDXBR, Convert__FP1281_0__FP1281_1, 0, { MCK_FP128, MCK_FP128 }, },
  { 1720 /* ldy */, SystemZ::LDY, Convert__FP641_0__BDXAddr64Disp203_1, 0, { MCK_FP64, MCK_BDXAddr64Disp20 }, },
  { 1724 /* le */, SystemZ::LE, Convert__FP321_0__BDXAddr64Disp123_1, 0, { MCK_FP32, MCK_BDXAddr64Disp12 }, },
  { 1727 /* ledbr */, SystemZ::LEDBR, Convert__FP321_0__FP641_1, 0, { MCK_FP32, MCK_FP64 }, },
  { 1733 /* ler */, SystemZ::LER, Convert__FP321_0__FP321_1, 0, { MCK_FP32, MCK_FP32 }, },
  { 1737 /* lexbr */, SystemZ::LEXBR, Convert__FP1281_0__FP1281_1, 0, { MCK_FP128, MCK_FP128 }, },
  { 1743 /* ley */, SystemZ::LEY, Convert__FP321_0__BDXAddr64Disp203_1, 0, { MCK_FP32, MCK_BDXAddr64Disp20 }, },
  { 1747 /* lfh */, SystemZ::LFH, Convert__GRH321_0__BDXAddr64Disp203_1, Feature_FeatureHighWord, { MCK_GRH32, MCK_BDXAddr64Disp20 }, },
  { 1751 /* lg */, SystemZ::LG, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 1754 /* lgb */, SystemZ::LGB, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 1758 /* lgbr */, SystemZ::LGBR, Convert__GR641_0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 1763 /* lgdr */, SystemZ::LGDR, Convert__GR641_0__FP641_1, 0, { MCK_GR64, MCK_FP64 }, },
  { 1768 /* lgf */, SystemZ::LGF, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 1772 /* lgfi */, SystemZ::LGFI, Convert__GR641_0__S32Imm1_1, 0, { MCK_GR64, MCK_S32Imm }, },
  { 1777 /* lgfr */, SystemZ::LGFR, Convert__GR641_0__GR321_1, 0, { MCK_GR64, MCK_GR32 }, },
  { 1782 /* lgfrl */, SystemZ::LGFRL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 1788 /* lgh */, SystemZ::LGH, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 1792 /* lghi */, SystemZ::LGHI, Convert__GR641_0__S16Imm1_1, 0, { MCK_GR64, MCK_S16Imm }, },
  { 1797 /* lghr */, SystemZ::LGHR, Convert__GR641_0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 1802 /* lghrl */, SystemZ::LGHRL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 1808 /* lgr */, SystemZ::LGR, Convert__GR641_0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 1812 /* lgrl */, SystemZ::LGRL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 1817 /* lh */, SystemZ::LH, Convert__GR321_0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 1820 /* lhh */, SystemZ::LHH, Convert__GRH321_0__BDXAddr64Disp203_1, Feature_FeatureHighWord, { MCK_GRH32, MCK_BDXAddr64Disp20 }, },
  { 1824 /* lhi */, SystemZ::LHI, Convert__GR321_0__S16Imm1_1, 0, { MCK_GR32, MCK_S16Imm }, },
  { 1828 /* lhr */, SystemZ::LHR, Convert__GR321_0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 1832 /* lhrl */, SystemZ::LHRL, Convert__GR321_0__PCRel321_1, 0, { MCK_GR32, MCK_PCRel32 }, },
  { 1837 /* lhy */, SystemZ::LHY, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 1841 /* llc */, SystemZ::LLC, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 1845 /* llch */, SystemZ::LLCH, Convert__GR321_0__BDXAddr64Disp203_1, Feature_FeatureHighWord, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 1850 /* llcr */, SystemZ::LLCR, Convert__GR321_0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 1855 /* llgc */, SystemZ::LLGC, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 1860 /* llgcr */, SystemZ::LLGCR, Convert__GR641_0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 1866 /* llgf */, SystemZ::LLGF, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 1871 /* llgfr */, SystemZ::LLGFR, Convert__GR641_0__GR321_1, 0, { MCK_GR64, MCK_GR32 }, },
  { 1877 /* llgfrl */, SystemZ::LLGFRL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 1884 /* llgh */, SystemZ::LLGH, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 1889 /* llghr */, SystemZ::LLGHR, Convert__GR641_0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 1895 /* llghrl */, SystemZ::LLGHRL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 1902 /* llh */, SystemZ::LLH, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 1906 /* llhh */, SystemZ::LLHH, Convert__GR321_0__BDXAddr64Disp203_1, Feature_FeatureHighWord, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 1911 /* llhr */, SystemZ::LLHR, Convert__GR321_0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 1916 /* llhrl */, SystemZ::LLHRL, Convert__GR321_0__PCRel321_1, 0, { MCK_GR32, MCK_PCRel32 }, },
  { 1922 /* llihf */, SystemZ::LLIHF, Convert__GR641_0__U32Imm1_1, 0, { MCK_GR64, MCK_U32Imm }, },
  { 1928 /* llihh */, SystemZ::LLIHH, Convert__GR641_0__U16Imm1_1, 0, { MCK_GR64, MCK_U16Imm }, },
  { 1934 /* llihl */, SystemZ::LLIHL, Convert__GR641_0__U16Imm1_1, 0, { MCK_GR64, MCK_U16Imm }, },
  { 1940 /* llilf */, SystemZ::LLILF, Convert__GR641_0__U32Imm1_1, 0, { MCK_GR64, MCK_U32Imm }, },
  { 1946 /* llilh */, SystemZ::LLILH, Convert__GR641_0__U16Imm1_1, 0, { MCK_GR64, MCK_U16Imm }, },
  { 1952 /* llill */, SystemZ::LLILL, Convert__GR641_0__U16Imm1_1, 0, { MCK_GR64, MCK_U16Imm }, },
  { 1958 /* lmg */, SystemZ::LMG, Convert__GR641_0__GR641_1__BDAddr64Disp202_2, 0, { MCK_GR64, MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 1962 /* lndbr */, SystemZ::LNDBR, Convert__FP641_0__FP641_1, 0, { MCK_FP64, MCK_FP64 }, },
  { 1968 /* lnebr */, SystemZ::LNEBR, Convert__FP321_0__FP321_1, 0, { MCK_FP32, MCK_FP32 }, },
  { 1974 /* lngfr */, SystemZ::LNGFR, Convert__GR641_0__GR321_1, 0, { MCK_GR64, MCK_GR32 }, },
  { 1980 /* lngr */, SystemZ::LNGR, Convert__GR641_0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 1985 /* lnr */, SystemZ::LNR, Convert__GR321_0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 1989 /* lnxbr */, SystemZ::LNXBR, Convert__FP1281_0__FP1281_1, 0, { MCK_FP128, MCK_FP128 }, },
  { 1995 /* loc */, SystemZ::AsmLOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1__U4Imm1_2, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20, MCK_U4Imm }, },
  { 1999 /* loce */, SystemZ::AsmELOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2004 /* locg */, SystemZ::AsmLOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1__U4Imm1_2, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20, MCK_U4Imm }, },
  { 2009 /* locge */, SystemZ::AsmELOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2015 /* locgh */, SystemZ::AsmHLOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2021 /* locghe */, SystemZ::AsmHELOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2028 /* locgl */, SystemZ::AsmLLOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2034 /* locgle */, SystemZ::AsmLELOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2041 /* locglh */, SystemZ::AsmLHLOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2048 /* locgne */, SystemZ::AsmNELOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2055 /* locgnh */, SystemZ::AsmNHLOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2062 /* locgnhe */, SystemZ::AsmNHELOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2070 /* locgnl */, SystemZ::AsmNLLOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2077 /* locgnle */, SystemZ::AsmNLELOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2085 /* locgnlh */, SystemZ::AsmNLHLOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2093 /* locgno */, SystemZ::AsmNOLOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2100 /* locgo */, SystemZ::AsmOLOCG, Convert__GR641_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 2106 /* locgr */, SystemZ::AsmLOCGR, Convert__GR641_0__Tie0__GR641_1__U4Imm1_2, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64, MCK_U4Imm }, },
  { 2112 /* locgre */, SystemZ::AsmELOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2119 /* locgrh */, SystemZ::AsmHLOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2126 /* locgrhe */, SystemZ::AsmHELOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2134 /* locgrl */, SystemZ::AsmLLOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2141 /* locgrle */, SystemZ::AsmLELOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2149 /* locgrlh */, SystemZ::AsmLHLOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2157 /* locgrne */, SystemZ::AsmNELOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2165 /* locgrnh */, SystemZ::AsmNHLOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2173 /* locgrnhe */, SystemZ::AsmNHELOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2182 /* locgrnl */, SystemZ::AsmNLLOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2190 /* locgrnle */, SystemZ::AsmNLELOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2199 /* locgrnlh */, SystemZ::AsmNLHLOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2208 /* locgrno */, SystemZ::AsmNOLOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2216 /* locgro */, SystemZ::AsmOLOCGR, Convert__GR641_0__Tie0__GR641_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_GR64 }, },
  { 2223 /* loch */, SystemZ::AsmHLOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2228 /* loche */, SystemZ::AsmHELOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2234 /* locl */, SystemZ::AsmLLOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2239 /* locle */, SystemZ::AsmLELOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2245 /* loclh */, SystemZ::AsmLHLOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2251 /* locne */, SystemZ::AsmNELOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2257 /* locnh */, SystemZ::AsmNHLOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2263 /* locnhe */, SystemZ::AsmNHELOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2270 /* locnl */, SystemZ::AsmNLLOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2276 /* locnle */, SystemZ::AsmNLELOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2283 /* locnlh */, SystemZ::AsmNLHLOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2290 /* locno */, SystemZ::AsmNOLOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2296 /* loco */, SystemZ::AsmOLOC, Convert__GR321_0__Tie0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 2301 /* locr */, SystemZ::AsmLOCR, Convert__GR321_0__Tie0__GR321_1__U4Imm1_2, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32, MCK_U4Imm }, },
  { 2306 /* locre */, SystemZ::AsmELOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2312 /* locrh */, SystemZ::AsmHLOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2318 /* locrhe */, SystemZ::AsmHELOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2325 /* locrl */, SystemZ::AsmLLOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2331 /* locrle */, SystemZ::AsmLELOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2338 /* locrlh */, SystemZ::AsmLHLOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2345 /* locrne */, SystemZ::AsmNELOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2352 /* locrnh */, SystemZ::AsmNHLOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2359 /* locrnhe */, SystemZ::AsmNHELOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2367 /* locrnl */, SystemZ::AsmNLLOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2374 /* locrnle */, SystemZ::AsmNLELOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2382 /* locrnlh */, SystemZ::AsmNLHLOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2390 /* locrno */, SystemZ::AsmNOLOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2397 /* locro */, SystemZ::AsmOLOCR, Convert__GR321_0__Tie0__GR321_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_GR32 }, },
  { 2403 /* lpdbr */, SystemZ::LPDBR, Convert__FP641_0__FP641_1, 0, { MCK_FP64, MCK_FP64 }, },
  { 2409 /* lpebr */, SystemZ::LPEBR, Convert__FP321_0__FP321_1, 0, { MCK_FP32, MCK_FP32 }, },
  { 2415 /* lpgfr */, SystemZ::LPGFR, Convert__GR641_0__GR321_1, 0, { MCK_GR64, MCK_GR32 }, },
  { 2421 /* lpgr */, SystemZ::LPGR, Convert__GR641_0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 2426 /* lpr */, SystemZ::LPR, Convert__GR321_0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 2430 /* lpxbr */, SystemZ::LPXBR, Convert__FP1281_0__FP1281_1, 0, { MCK_FP128, MCK_FP128 }, },
  { 2436 /* lr */, SystemZ::LR, Convert__GR321_0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 2439 /* lrl */, SystemZ::LRL, Convert__GR321_0__PCRel321_1, 0, { MCK_GR32, MCK_PCRel32 }, },
  { 2443 /* lrv */, SystemZ::LRV, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 2447 /* lrvg */, SystemZ::LRVG, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 2452 /* lrvgr */, SystemZ::LRVGR, Convert__GR641_0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 2458 /* lrvr */, SystemZ::LRVR, Convert__GR321_0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 2463 /* lt */, SystemZ::LT, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 2466 /* ltdbr */, SystemZ::LTDBR, Convert__FP641_0__FP641_1, 0, { MCK_FP64, MCK_FP64 }, },
  { 2472 /* ltebr */, SystemZ::LTEBR, Convert__FP321_0__FP321_1, 0, { MCK_FP32, MCK_FP32 }, },
  { 2478 /* ltg */, SystemZ::LTG, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 2482 /* ltgf */, SystemZ::LTGF, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 2487 /* ltgfr */, SystemZ::LTGFR, Convert__GR641_0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 2493 /* ltgr */, SystemZ::LTGR, Convert__GR641_0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 2498 /* ltr */, SystemZ::LTR, Convert__GR321_0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 2502 /* ltxbr */, SystemZ::LTXBR, Convert__FP1281_0__FP1281_1, 0, { MCK_FP128, MCK_FP128 }, },
  { 2508 /* lxdb */, SystemZ::LXDB, Convert__FP1281_0__BDXAddr64Disp123_1, 0, { MCK_FP128, MCK_BDXAddr64Disp12 }, },
  { 2513 /* lxdbr */, SystemZ::LXDBR, Convert__FP1281_0__FP641_1, 0, { MCK_FP128, MCK_FP64 }, },
  { 2519 /* lxeb */, SystemZ::LXEB, Convert__FP1281_0__BDXAddr64Disp123_1, 0, { MCK_FP128, MCK_BDXAddr64Disp12 }, },
  { 2524 /* lxebr */, SystemZ::LXEBR, Convert__FP1281_0__FP321_1, 0, { MCK_FP128, MCK_FP32 }, },
  { 2530 /* lxr */, SystemZ::LXR, Convert__FP1281_0__FP1281_1, 0, { MCK_FP128, MCK_FP128 }, },
  { 2534 /* ly */, SystemZ::LY, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 2537 /* lzdr */, SystemZ::LZDR, Convert__FP641_0, 0, { MCK_FP64 }, },
  { 2542 /* lzer */, SystemZ::LZER, Convert__FP321_0, 0, { MCK_FP32 }, },
  { 2547 /* lzxr */, SystemZ::LZXR, Convert__FP1281_0, 0, { MCK_FP128 }, },
  { 2552 /* madb */, SystemZ::MADB, Convert__FP641_0__Tie0__FP641_1__BDXAddr64Disp123_2, 0, { MCK_FP64, MCK_FP64, MCK_BDXAddr64Disp12 }, },
  { 2557 /* madbr */, SystemZ::MADBR, Convert__FP641_0__Tie0__FP641_1__FP641_2, 0, { MCK_FP64, MCK_FP64, MCK_FP64 }, },
  { 2563 /* maeb */, SystemZ::MAEB, Convert__FP321_0__Tie0__FP321_1__BDXAddr64Disp123_2, 0, { MCK_FP32, MCK_FP32, MCK_BDXAddr64Disp12 }, },
  { 2568 /* maebr */, SystemZ::MAEBR, Convert__FP321_0__Tie0__FP321_1__FP321_2, 0, { MCK_FP32, MCK_FP32, MCK_FP32 }, },
  { 2574 /* mdb */, SystemZ::MDB, Convert__FP641_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_FP64, MCK_BDXAddr64Disp12 }, },
  { 2578 /* mdbr */, SystemZ::MDBR, Convert__FP641_0__Tie0__FP641_1, 0, { MCK_FP64, MCK_FP64 }, },
  { 2583 /* mdeb */, SystemZ::MDEB, Convert__FP641_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_FP64, MCK_BDXAddr64Disp12 }, },
  { 2588 /* mdebr */, SystemZ::MDEBR, Convert__FP641_0__Tie0__FP321_1, 0, { MCK_FP64, MCK_FP32 }, },
  { 2594 /* meeb */, SystemZ::MEEB, Convert__FP321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_FP32, MCK_BDXAddr64Disp12 }, },
  { 2599 /* meebr */, SystemZ::MEEBR, Convert__FP321_0__Tie0__FP321_1, 0, { MCK_FP32, MCK_FP32 }, },
  { 2605 /* mghi */, SystemZ::MGHI, Convert__GR641_0__Tie0__S16Imm1_1, 0, { MCK_GR64, MCK_S16Imm }, },
  { 2610 /* mh */, SystemZ::MH, Convert__GR321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 2613 /* mhi */, SystemZ::MHI, Convert__GR321_0__Tie0__S16Imm1_1, 0, { MCK_GR32, MCK_S16Imm }, },
  { 2617 /* mhy */, SystemZ::MHY, Convert__GR321_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 2621 /* mlg */, SystemZ::MLG, Convert__GR1281_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR128, MCK_BDXAddr64Disp20 }, },
  { 2625 /* mlgr */, SystemZ::MLGR, Convert__GR1281_0__Tie0__GR641_1, 0, { MCK_GR128, MCK_GR64 }, },
  { 2630 /* ms */, SystemZ::MS, Convert__GR321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 2633 /* msdb */, SystemZ::MSDB, Convert__FP641_0__Tie0__FP641_1__BDXAddr64Disp123_2, 0, { MCK_FP64, MCK_FP64, MCK_BDXAddr64Disp12 }, },
  { 2638 /* msdbr */, SystemZ::MSDBR, Convert__FP641_0__Tie0__FP641_1__FP641_2, 0, { MCK_FP64, MCK_FP64, MCK_FP64 }, },
  { 2644 /* mseb */, SystemZ::MSEB, Convert__FP321_0__Tie0__FP321_1__BDXAddr64Disp123_2, 0, { MCK_FP32, MCK_FP32, MCK_BDXAddr64Disp12 }, },
  { 2649 /* msebr */, SystemZ::MSEBR, Convert__FP321_0__Tie0__FP321_1__FP321_2, 0, { MCK_FP32, MCK_FP32, MCK_FP32 }, },
  { 2655 /* msfi */, SystemZ::MSFI, Convert__GR321_0__Tie0__S32Imm1_1, 0, { MCK_GR32, MCK_S32Imm }, },
  { 2660 /* msg */, SystemZ::MSG, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 2664 /* msgf */, SystemZ::MSGF, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 2669 /* msgfi */, SystemZ::MSGFI, Convert__GR641_0__Tie0__S32Imm1_1, 0, { MCK_GR64, MCK_S32Imm }, },
  { 2675 /* msgfr */, SystemZ::MSGFR, Convert__GR641_0__Tie0__GR321_1, 0, { MCK_GR64, MCK_GR32 }, },
  { 2681 /* msgr */, SystemZ::MSGR, Convert__GR641_0__Tie0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 2686 /* msr */, SystemZ::MSR, Convert__GR321_0__Tie0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 2690 /* msy */, SystemZ::MSY, Convert__GR321_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 2694 /* mvc */, SystemZ::MVC, Convert__BDLAddr64Disp12Len83_0__BDAddr64Disp122_1, 0, { MCK_BDLAddr64Disp12Len8, MCK_BDAddr64Disp12 }, },
  { 2698 /* mvghi */, SystemZ::MVGHI, Convert__BDAddr64Disp122_0__S16Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_S16Imm }, },
  { 2704 /* mvhhi */, SystemZ::MVHHI, Convert__BDAddr64Disp122_0__S16Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_S16Imm }, },
  { 2710 /* mvhi */, SystemZ::MVHI, Convert__BDAddr64Disp122_0__S16Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_S16Imm }, },
  { 2715 /* mvi */, SystemZ::MVI, Convert__BDAddr64Disp122_0__U8Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_U8Imm }, },
  { 2719 /* mviy */, SystemZ::MVIY, Convert__BDAddr64Disp202_0__U8Imm1_1, 0, { MCK_BDAddr64Disp20, MCK_U8Imm }, },
  { 2724 /* mvst */, SystemZ::MVST, Convert__GR641_0__GR641_1__Tie0__Tie1, 0, { MCK_GR64, MCK_GR64 }, },
  { 2729 /* mxbr */, SystemZ::MXBR, Convert__FP1281_0__Tie0__FP1281_1, 0, { MCK_FP128, MCK_FP128 }, },
  { 2734 /* mxdb */, SystemZ::MXDB, Convert__FP1281_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_FP128, MCK_BDXAddr64Disp12 }, },
  { 2739 /* mxdbr */, SystemZ::MXDBR, Convert__FP1281_0__Tie0__FP641_1, 0, { MCK_FP128, MCK_FP64 }, },
  { 2745 /* n */, SystemZ::N, Convert__GR321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 2747 /* nc */, SystemZ::NC, Convert__BDLAddr64Disp12Len83_0__BDAddr64Disp122_1, 0, { MCK_BDLAddr64Disp12Len8, MCK_BDAddr64Disp12 }, },
  { 2750 /* ng */, SystemZ::NG, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 2753 /* ngr */, SystemZ::NGR, Convert__GR641_0__Tie0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 2757 /* ngrk */, SystemZ::NGRK, Convert__GR641_0__GR641_1__GR641_2, Feature_FeatureDistinctOps, { MCK_GR64, MCK_GR64, MCK_GR64 }, },
  { 2762 /* ni */, SystemZ::NI, Convert__BDAddr64Disp122_0__U8Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_U8Imm }, },
  { 2765 /* nihf */, SystemZ::NIHF, Convert__GRH321_0__Tie0__U32Imm1_1, 0, { MCK_GRH32, MCK_U32Imm }, },
  { 2770 /* nihh */, SystemZ::NIHH, Convert__GRH321_0__Tie0__U16Imm1_1, 0, { MCK_GRH32, MCK_U16Imm }, },
  { 2775 /* nihl */, SystemZ::NIHL, Convert__GRH321_0__Tie0__U16Imm1_1, 0, { MCK_GRH32, MCK_U16Imm }, },
  { 2780 /* nilf */, SystemZ::NILF, Convert__GR321_0__Tie0__U32Imm1_1, 0, { MCK_GR32, MCK_U32Imm }, },
  { 2785 /* nilh */, SystemZ::NILH, Convert__GR321_0__Tie0__U16Imm1_1, 0, { MCK_GR32, MCK_U16Imm }, },
  { 2790 /* nill */, SystemZ::NILL, Convert__GR321_0__Tie0__U16Imm1_1, 0, { MCK_GR32, MCK_U16Imm }, },
  { 2795 /* niy */, SystemZ::NIY, Convert__BDAddr64Disp202_0__U8Imm1_1, 0, { MCK_BDAddr64Disp20, MCK_U8Imm }, },
  { 2799 /* nr */, SystemZ::NR, Convert__GR321_0__Tie0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 2802 /* nrk */, SystemZ::NRK, Convert__GR321_0__GR321_1__GR321_2, Feature_FeatureDistinctOps, { MCK_GR32, MCK_GR32, MCK_GR32 }, },
  { 2806 /* ny */, SystemZ::NY, Convert__GR321_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 2809 /* o */, SystemZ::O, Convert__GR321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 2811 /* oc */, SystemZ::OC, Convert__BDLAddr64Disp12Len83_0__BDAddr64Disp122_1, 0, { MCK_BDLAddr64Disp12Len8, MCK_BDAddr64Disp12 }, },
  { 2814 /* og */, SystemZ::OG, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 2817 /* ogr */, SystemZ::OGR, Convert__GR641_0__Tie0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 2821 /* ogrk */, SystemZ::OGRK, Convert__GR641_0__GR641_1__GR641_2, Feature_FeatureDistinctOps, { MCK_GR64, MCK_GR64, MCK_GR64 }, },
  { 2826 /* oi */, SystemZ::OI, Convert__BDAddr64Disp122_0__U8Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_U8Imm }, },
  { 2829 /* oihf */, SystemZ::OIHF, Convert__GRH321_0__Tie0__U32Imm1_1, 0, { MCK_GRH32, MCK_U32Imm }, },
  { 2834 /* oihh */, SystemZ::OIHH, Convert__GRH321_0__Tie0__U16Imm1_1, 0, { MCK_GRH32, MCK_U16Imm }, },
  { 2839 /* oihl */, SystemZ::OIHL, Convert__GRH321_0__Tie0__U16Imm1_1, 0, { MCK_GRH32, MCK_U16Imm }, },
  { 2844 /* oilf */, SystemZ::OILF, Convert__GR321_0__Tie0__U32Imm1_1, 0, { MCK_GR32, MCK_U32Imm }, },
  { 2849 /* oilh */, SystemZ::OILH, Convert__GR321_0__Tie0__U16Imm1_1, 0, { MCK_GR32, MCK_U16Imm }, },
  { 2854 /* oill */, SystemZ::OILL, Convert__GR321_0__Tie0__U16Imm1_1, 0, { MCK_GR32, MCK_U16Imm }, },
  { 2859 /* oiy */, SystemZ::OIY, Convert__BDAddr64Disp202_0__U8Imm1_1, 0, { MCK_BDAddr64Disp20, MCK_U8Imm }, },
  { 2863 /* or */, SystemZ::OR, Convert__GR321_0__Tie0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 2866 /* ork */, SystemZ::ORK, Convert__GR321_0__GR321_1__GR321_2, Feature_FeatureDistinctOps, { MCK_GR32, MCK_GR32, MCK_GR32 }, },
  { 2870 /* oy */, SystemZ::OY, Convert__GR321_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 2873 /* pfd */, SystemZ::PFD, Convert__U4Imm1_0__BDXAddr64Disp203_1, 0, { MCK_U4Imm, MCK_BDXAddr64Disp20 }, },
  { 2877 /* pfdrl */, SystemZ::PFDRL, Convert__U4Imm1_0__PCRel321_1, 0, { MCK_U4Imm, MCK_PCRel32 }, },
  { 2883 /* risbg */, SystemZ::RISBG, Convert__GR641_0__Tie0__GR641_1__U8Imm1_2__U8Imm1_3__U6Imm1_4, 0, { MCK_GR64, MCK_GR64, MCK_U8Imm, MCK_U8Imm, MCK_U6Imm }, },
  { 2889 /* risbhg */, SystemZ::RISBHG, Convert__GRH321_0__Tie0__GR641_1__U8Imm1_2__U8Imm1_3__U6Imm1_4, Feature_FeatureHighWord, { MCK_GRH32, MCK_GR64, MCK_U8Imm, MCK_U8Imm, MCK_U6Imm }, },
  { 2896 /* risblg */, SystemZ::RISBLG, Convert__GR321_0__Tie0__GR641_1__U8Imm1_2__U8Imm1_3__U6Imm1_4, Feature_FeatureHighWord, { MCK_GR32, MCK_GR64, MCK_U8Imm, MCK_U8Imm, MCK_U6Imm }, },
  { 2903 /* rll */, SystemZ::RLL, Convert__GR321_0__GR321_1__BDAddr32Disp202_2, 0, { MCK_GR32, MCK_GR32, MCK_BDAddr32Disp20 }, },
  { 2907 /* rllg */, SystemZ::RLLG, Convert__GR641_0__GR641_1__BDAddr32Disp202_2, 0, { MCK_GR64, MCK_GR64, MCK_BDAddr32Disp20 }, },
  { 2912 /* rnsbg */, SystemZ::RNSBG, Convert__GR641_0__Tie0__GR641_1__U8Imm1_2__U8Imm1_3__U6Imm1_4, 0, { MCK_GR64, MCK_GR64, MCK_U8Imm, MCK_U8Imm, MCK_U6Imm }, },
  { 2918 /* rosbg */, SystemZ::ROSBG, Convert__GR641_0__Tie0__GR641_1__U8Imm1_2__U8Imm1_3__U6Imm1_4, 0, { MCK_GR64, MCK_GR64, MCK_U8Imm, MCK_U8Imm, MCK_U6Imm }, },
  { 2924 /* rxsbg */, SystemZ::RXSBG, Convert__GR641_0__Tie0__GR641_1__U8Imm1_2__U8Imm1_3__U6Imm1_4, 0, { MCK_GR64, MCK_GR64, MCK_U8Imm, MCK_U8Imm, MCK_U6Imm }, },
  { 2930 /* s */, SystemZ::S, Convert__GR321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 2932 /* sdb */, SystemZ::SDB, Convert__FP641_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_FP64, MCK_BDXAddr64Disp12 }, },
  { 2936 /* sdbr */, SystemZ::SDBR, Convert__FP641_0__Tie0__FP641_1, 0, { MCK_FP64, MCK_FP64 }, },
  { 2941 /* seb */, SystemZ::SEB, Convert__FP321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_FP32, MCK_BDXAddr64Disp12 }, },
  { 2945 /* sebr */, SystemZ::SEBR, Convert__FP321_0__Tie0__FP321_1, 0, { MCK_FP32, MCK_FP32 }, },
  { 2950 /* sg */, SystemZ::SG, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 2953 /* sgf */, SystemZ::SGF, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 2957 /* sgfr */, SystemZ::SGFR, Convert__GR641_0__Tie0__GR321_1, 0, { MCK_GR64, MCK_GR32 }, },
  { 2962 /* sgr */, SystemZ::SGR, Convert__GR641_0__Tie0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 2966 /* sgrk */, SystemZ::SGRK, Convert__GR641_0__GR641_1__GR641_2, Feature_FeatureDistinctOps, { MCK_GR64, MCK_GR64, MCK_GR64 }, },
  { 2971 /* sh */, SystemZ::SH, Convert__GR321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 2974 /* shy */, SystemZ::SHY, Convert__GR321_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 2978 /* sl */, SystemZ::SL, Convert__GR321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 2981 /* slb */, SystemZ::SLB, Convert__GR321_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 2985 /* slbg */, SystemZ::SLBG, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 2990 /* slbgr */, SystemZ::SLGBR, Convert__GR641_0__Tie0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 2996 /* slbr */, SystemZ::SLBR, Convert__GR321_0__Tie0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 3001 /* slfi */, SystemZ::SLFI, Convert__GR321_0__Tie0__U32Imm1_1, 0, { MCK_GR32, MCK_U32Imm }, },
  { 3006 /* slg */, SystemZ::SLG, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 3010 /* slgf */, SystemZ::SLGF, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 3015 /* slgfi */, SystemZ::SLGFI, Convert__GR641_0__Tie0__U32Imm1_1, 0, { MCK_GR64, MCK_U32Imm }, },
  { 3021 /* slgfr */, SystemZ::SLGFR, Convert__GR641_0__Tie0__GR321_1, 0, { MCK_GR64, MCK_GR32 }, },
  { 3027 /* slgr */, SystemZ::SLGR, Convert__GR641_0__Tie0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 3032 /* slgrk */, SystemZ::SLGRK, Convert__GR641_0__GR641_1__GR641_2, Feature_FeatureDistinctOps, { MCK_GR64, MCK_GR64, MCK_GR64 }, },
  { 3038 /* sll */, SystemZ::SLL, Convert__GR321_0__Tie0__BDAddr32Disp122_1, 0, { MCK_GR32, MCK_BDAddr32Disp12 }, },
  { 3042 /* sllg */, SystemZ::SLLG, Convert__GR641_0__GR641_1__BDAddr32Disp202_2, 0, { MCK_GR64, MCK_GR64, MCK_BDAddr32Disp20 }, },
  { 3047 /* sllk */, SystemZ::SLLK, Convert__GR321_0__GR321_1__BDAddr32Disp202_2, Feature_FeatureDistinctOps, { MCK_GR32, MCK_GR32, MCK_BDAddr32Disp20 }, },
  { 3052 /* slr */, SystemZ::SLR, Convert__GR321_0__Tie0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 3056 /* slrk */, SystemZ::SLRK, Convert__GR321_0__GR321_1__GR321_2, Feature_FeatureDistinctOps, { MCK_GR32, MCK_GR32, MCK_GR32 }, },
  { 3061 /* sly */, SystemZ::SLY, Convert__GR321_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 3065 /* sqdb */, SystemZ::SQDB, Convert__FP641_0__BDXAddr64Disp123_1, 0, { MCK_FP64, MCK_BDXAddr64Disp12 }, },
  { 3070 /* sqdbr */, SystemZ::SQDBR, Convert__FP641_0__FP641_1, 0, { MCK_FP64, MCK_FP64 }, },
  { 3076 /* sqeb */, SystemZ::SQEB, Convert__FP321_0__BDXAddr64Disp123_1, 0, { MCK_FP32, MCK_BDXAddr64Disp12 }, },
  { 3081 /* sqebr */, SystemZ::SQEBR, Convert__FP321_0__FP321_1, 0, { MCK_FP32, MCK_FP32 }, },
  { 3087 /* sqxbr */, SystemZ::SQXBR, Convert__FP1281_0__FP1281_1, 0, { MCK_FP128, MCK_FP128 }, },
  { 3093 /* sr */, SystemZ::SR, Convert__GR321_0__Tie0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 3096 /* sra */, SystemZ::SRA, Convert__GR321_0__Tie0__BDAddr32Disp122_1, 0, { MCK_GR32, MCK_BDAddr32Disp12 }, },
  { 3100 /* srag */, SystemZ::SRAG, Convert__GR641_0__GR641_1__BDAddr32Disp202_2, 0, { MCK_GR64, MCK_GR64, MCK_BDAddr32Disp20 }, },
  { 3105 /* srak */, SystemZ::SRAK, Convert__GR321_0__GR321_1__BDAddr32Disp202_2, Feature_FeatureDistinctOps, { MCK_GR32, MCK_GR32, MCK_BDAddr32Disp20 }, },
  { 3110 /* srk */, SystemZ::SRK, Convert__GR321_0__GR321_1__GR321_2, Feature_FeatureDistinctOps, { MCK_GR32, MCK_GR32, MCK_GR32 }, },
  { 3114 /* srl */, SystemZ::SRL, Convert__GR321_0__Tie0__BDAddr32Disp122_1, 0, { MCK_GR32, MCK_BDAddr32Disp12 }, },
  { 3118 /* srlg */, SystemZ::SRLG, Convert__GR641_0__GR641_1__BDAddr32Disp202_2, 0, { MCK_GR64, MCK_GR64, MCK_BDAddr32Disp20 }, },
  { 3123 /* srlk */, SystemZ::SRLK, Convert__GR321_0__GR321_1__BDAddr32Disp202_2, Feature_FeatureDistinctOps, { MCK_GR32, MCK_GR32, MCK_BDAddr32Disp20 }, },
  { 3128 /* srst */, SystemZ::SRST, Convert__GR641_0__GR641_1__Tie0__Tie1, 0, { MCK_GR64, MCK_GR64 }, },
  { 3133 /* st */, SystemZ::ST, Convert__GR321_0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 3136 /* stc */, SystemZ::STC, Convert__GR321_0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 3140 /* stch */, SystemZ::STCH, Convert__GRH321_0__BDXAddr64Disp203_1, Feature_FeatureHighWord, { MCK_GRH32, MCK_BDXAddr64Disp20 }, },
  { 3145 /* stcy */, SystemZ::STCY, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 3150 /* std */, SystemZ::STD, Convert__FP641_0__BDXAddr64Disp123_1, 0, { MCK_FP64, MCK_BDXAddr64Disp12 }, },
  { 3154 /* stdy */, SystemZ::STDY, Convert__FP641_0__BDXAddr64Disp203_1, 0, { MCK_FP64, MCK_BDXAddr64Disp20 }, },
  { 3159 /* ste */, SystemZ::STE, Convert__FP321_0__BDXAddr64Disp123_1, 0, { MCK_FP32, MCK_BDXAddr64Disp12 }, },
  { 3163 /* stey */, SystemZ::STEY, Convert__FP321_0__BDXAddr64Disp203_1, 0, { MCK_FP32, MCK_BDXAddr64Disp20 }, },
  { 3168 /* stfh */, SystemZ::STFH, Convert__GRH321_0__BDXAddr64Disp203_1, Feature_FeatureHighWord, { MCK_GRH32, MCK_BDXAddr64Disp20 }, },
  { 3173 /* stg */, SystemZ::STG, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 3177 /* stgrl */, SystemZ::STGRL, Convert__GR641_0__PCRel321_1, 0, { MCK_GR64, MCK_PCRel32 }, },
  { 3183 /* sth */, SystemZ::STH, Convert__GR321_0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 3187 /* sthh */, SystemZ::STHH, Convert__GRH321_0__BDXAddr64Disp203_1, Feature_FeatureHighWord, { MCK_GRH32, MCK_BDXAddr64Disp20 }, },
  { 3192 /* sthrl */, SystemZ::STHRL, Convert__GR321_0__PCRel321_1, 0, { MCK_GR32, MCK_PCRel32 }, },
  { 3198 /* sthy */, SystemZ::STHY, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 3203 /* stmg */, SystemZ::STMG, Convert__GR641_0__GR641_1__BDAddr64Disp202_2, 0, { MCK_GR64, MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3208 /* stoc */, SystemZ::AsmSTOC, Convert__GR321_0__BDAddr64Disp202_1__U4Imm1_2, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20, MCK_U4Imm }, },
  { 3213 /* stoce */, SystemZ::AsmESTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3219 /* stocg */, SystemZ::AsmSTOCG, Convert__GR641_0__BDAddr64Disp202_1__U4Imm1_2, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20, MCK_U4Imm }, },
  { 3225 /* stocge */, SystemZ::AsmESTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3232 /* stocgh */, SystemZ::AsmHSTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3239 /* stocghe */, SystemZ::AsmHESTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3247 /* stocgl */, SystemZ::AsmLSTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3254 /* stocgle */, SystemZ::AsmLESTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3262 /* stocglh */, SystemZ::AsmLHSTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3270 /* stocgne */, SystemZ::AsmNESTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3278 /* stocgnh */, SystemZ::AsmNHSTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3286 /* stocgnhe */, SystemZ::AsmNHESTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3295 /* stocgnl */, SystemZ::AsmNLSTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3303 /* stocgnle */, SystemZ::AsmNLESTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3312 /* stocgnlh */, SystemZ::AsmNLHSTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3321 /* stocgno */, SystemZ::AsmNOSTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3329 /* stocgo */, SystemZ::AsmOSTOCG, Convert__GR641_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR64, MCK_BDAddr64Disp20 }, },
  { 3336 /* stoch */, SystemZ::AsmHSTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3342 /* stoche */, SystemZ::AsmHESTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3349 /* stocl */, SystemZ::AsmLSTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3355 /* stocle */, SystemZ::AsmLESTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3362 /* stoclh */, SystemZ::AsmLHSTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3369 /* stocne */, SystemZ::AsmNESTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3376 /* stocnh */, SystemZ::AsmNHSTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3383 /* stocnhe */, SystemZ::AsmNHESTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3391 /* stocnl */, SystemZ::AsmNLSTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3398 /* stocnle */, SystemZ::AsmNLESTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3406 /* stocnlh */, SystemZ::AsmNLHSTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3414 /* stocno */, SystemZ::AsmNOSTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3421 /* stoco */, SystemZ::AsmOSTOC, Convert__GR321_0__BDAddr64Disp202_1, Feature_FeatureLoadStoreOnCond, { MCK_GR32, MCK_BDAddr64Disp20 }, },
  { 3427 /* strl */, SystemZ::STRL, Convert__GR321_0__PCRel321_1, 0, { MCK_GR32, MCK_PCRel32 }, },
  { 3432 /* strv */, SystemZ::STRV, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 3437 /* strvg */, SystemZ::STRVG, Convert__GR641_0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 3443 /* sty */, SystemZ::STY, Convert__GR321_0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 3447 /* sxbr */, SystemZ::SXBR, Convert__FP1281_0__Tie0__FP1281_1, 0, { MCK_FP128, MCK_FP128 }, },
  { 3452 /* sy */, SystemZ::SY, Convert__GR321_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
  { 3455 /* tm */, SystemZ::TM, Convert__BDAddr64Disp122_0__U8Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_U8Imm }, },
  { 3458 /* tmhh */, SystemZ::TMHH, Convert__GRH321_0__U16Imm1_1, 0, { MCK_GRH32, MCK_U16Imm }, },
  { 3463 /* tmhl */, SystemZ::TMHL, Convert__GRH321_0__U16Imm1_1, 0, { MCK_GRH32, MCK_U16Imm }, },
  { 3468 /* tmlh */, SystemZ::TMLH, Convert__GR321_0__U16Imm1_1, 0, { MCK_GR32, MCK_U16Imm }, },
  { 3473 /* tmll */, SystemZ::TMLL, Convert__GR321_0__U16Imm1_1, 0, { MCK_GR32, MCK_U16Imm }, },
  { 3478 /* tmy */, SystemZ::TMY, Convert__BDAddr64Disp202_0__U8Imm1_1, 0, { MCK_BDAddr64Disp20, MCK_U8Imm }, },
  { 3482 /* x */, SystemZ::X, Convert__GR321_0__Tie0__BDXAddr64Disp123_1, 0, { MCK_GR32, MCK_BDXAddr64Disp12 }, },
  { 3484 /* xc */, SystemZ::XC, Convert__BDLAddr64Disp12Len83_0__BDAddr64Disp122_1, 0, { MCK_BDLAddr64Disp12Len8, MCK_BDAddr64Disp12 }, },
  { 3487 /* xg */, SystemZ::XG, Convert__GR641_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR64, MCK_BDXAddr64Disp20 }, },
  { 3490 /* xgr */, SystemZ::XGR, Convert__GR641_0__Tie0__GR641_1, 0, { MCK_GR64, MCK_GR64 }, },
  { 3494 /* xgrk */, SystemZ::XGRK, Convert__GR641_0__GR641_1__GR641_2, Feature_FeatureDistinctOps, { MCK_GR64, MCK_GR64, MCK_GR64 }, },
  { 3499 /* xi */, SystemZ::XI, Convert__BDAddr64Disp122_0__U8Imm1_1, 0, { MCK_BDAddr64Disp12, MCK_U8Imm }, },
  { 3502 /* xihf */, SystemZ::XIHF, Convert__GRH321_0__Tie0__U32Imm1_1, 0, { MCK_GRH32, MCK_U32Imm }, },
  { 3507 /* xilf */, SystemZ::XILF, Convert__GR321_0__Tie0__U32Imm1_1, 0, { MCK_GR32, MCK_U32Imm }, },
  { 3512 /* xiy */, SystemZ::XIY, Convert__BDAddr64Disp202_0__U8Imm1_1, 0, { MCK_BDAddr64Disp20, MCK_U8Imm }, },
  { 3516 /* xr */, SystemZ::XR, Convert__GR321_0__Tie0__GR321_1, 0, { MCK_GR32, MCK_GR32 }, },
  { 3519 /* xrk */, SystemZ::XRK, Convert__GR321_0__GR321_1__GR321_2, Feature_FeatureDistinctOps, { MCK_GR32, MCK_GR32, MCK_GR32 }, },
  { 3523 /* xy */, SystemZ::XY, Convert__GR321_0__Tie0__BDXAddr64Disp203_1, 0, { MCK_GR32, MCK_BDXAddr64Disp20 }, },
};

bool SystemZAsmParser::
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

unsigned SystemZAsmParser::
MatchInstructionImpl(const SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                     MCInst &Inst,
unsigned &ErrorInfo, bool matchingInlineAsm, unsigned VariantID) {
  // Eliminate obvious mismatches.
  if (Operands.size() > 6) {
    ErrorInfo = 6;
    return Match_InvalidOperand;
  }

  // Get the current feature set.
  unsigned AvailableFeatures = getAvailableFeatures();

  // Get the instruction mnemonic, which is the first token.
  StringRef Mnemonic = ((SystemZOperand*)Operands[0])->getToken();

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
    for (unsigned i = 0; i != 5; ++i) {
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
    uint8_t RequiredFeatures;
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

static const OperandMatchEntry OperandMatchTable[1035] = {
  /* Operand List Mask, Mnemonic, Operand Class, Features */
  { 0, 0 /* a */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 0 /* a */, MCK_GR32, 1 /* 0 */ },
  { 0, 2 /* adb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2 /* adb */, MCK_FP64, 1 /* 0 */ },
  { 0, 6 /* adbr */, MCK_FP64, 3 /* 0, 1 */ },
  { 0, 11 /* aeb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 11 /* aeb */, MCK_FP32, 1 /* 0 */ },
  { 0, 15 /* aebr */, MCK_FP32, 3 /* 0, 1 */ },
  { 0, 20 /* afi */, MCK_GR32, 1 /* 0 */ },
  { 0, 24 /* ag */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 24 /* ag */, MCK_GR64, 1 /* 0 */ },
  { 0, 27 /* agf */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 27 /* agf */, MCK_GR64, 1 /* 0 */ },
  { 0, 31 /* agfi */, MCK_GR64, 1 /* 0 */ },
  { 0, 36 /* agfr */, MCK_GR32, 2 /* 1 */ },
  { 0, 36 /* agfr */, MCK_GR64, 1 /* 0 */ },
  { 0, 41 /* aghi */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureDistinctOps, 46 /* aghik */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 52 /* agr */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 56 /* agrk */, MCK_GR64, 7 /* 0, 1, 2 */ },
  { 0, 61 /* agsi */, MCK_BDAddr64Disp20, 1 /* 0 */ },
  { 0, 66 /* ah */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 66 /* ah */, MCK_GR32, 1 /* 0 */ },
  { 0, 69 /* ahi */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureDistinctOps, 73 /* ahik */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 78 /* ahy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 78 /* ahy */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureHighWord, 82 /* aih */, MCK_GRH32, 1 /* 0 */ },
  { 0, 86 /* al */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 86 /* al */, MCK_GR32, 1 /* 0 */ },
  { 0, 89 /* alc */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 89 /* alc */, MCK_GR32, 1 /* 0 */ },
  { 0, 93 /* alcg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 93 /* alcg */, MCK_GR64, 1 /* 0 */ },
  { 0, 98 /* alcgr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 104 /* alcr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 109 /* alfi */, MCK_GR32, 1 /* 0 */ },
  { 0, 114 /* alg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 114 /* alg */, MCK_GR64, 1 /* 0 */ },
  { 0, 118 /* algf */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 118 /* algf */, MCK_GR64, 1 /* 0 */ },
  { 0, 123 /* algfi */, MCK_GR64, 1 /* 0 */ },
  { 0, 129 /* algfr */, MCK_GR32, 2 /* 1 */ },
  { 0, 129 /* algfr */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureDistinctOps, 135 /* alghsik */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 143 /* algr */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 148 /* algrk */, MCK_GR64, 7 /* 0, 1, 2 */ },
  { Feature_FeatureDistinctOps, 154 /* alhsik */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 161 /* alr */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 165 /* alrk */, MCK_GR32, 7 /* 0, 1, 2 */ },
  { 0, 170 /* aly */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 170 /* aly */, MCK_GR32, 1 /* 0 */ },
  { 0, 174 /* ar */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 177 /* ark */, MCK_GR32, 7 /* 0, 1, 2 */ },
  { 0, 181 /* asi */, MCK_BDAddr64Disp20, 1 /* 0 */ },
  { 0, 185 /* axbr */, MCK_FP128, 3 /* 0, 1 */ },
  { 0, 190 /* ay */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 190 /* ay */, MCK_GR32, 1 /* 0 */ },
  { 0, 193 /* basr */, MCK_ADDR64, 2 /* 1 */ },
  { 0, 193 /* basr */, MCK_GR64, 1 /* 0 */ },
  { 0, 198 /* bcr */, MCK_GR64, 2 /* 1 */ },
  { 0, 202 /* ber */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 206 /* bher */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 211 /* bhr */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 215 /* bler */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 220 /* blhr */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 225 /* blr */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 229 /* bner */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 234 /* bnher */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 240 /* bnhr */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 245 /* bnler */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 251 /* bnlhr */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 257 /* bnlr */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 262 /* bnor */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 267 /* bor */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 271 /* br */, MCK_ADDR64, 1 /* 0 */ },
  { 0, 274 /* bras */, MCK_GR64, 1 /* 0 */ },
  { 0, 274 /* bras */, MCK_PCRel16, 2 /* 1 */ },
  { 0, 279 /* brasl */, MCK_GR64, 1 /* 0 */ },
  { 0, 279 /* brasl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 285 /* brc */, MCK_PCRel16, 2 /* 1 */ },
  { 0, 289 /* brcl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 294 /* brct */, MCK_GR32, 1 /* 0 */ },
  { 0, 294 /* brct */, MCK_PCRel16, 2 /* 1 */ },
  { 0, 299 /* brctg */, MCK_GR64, 1 /* 0 */ },
  { 0, 299 /* brctg */, MCK_PCRel16, 2 /* 1 */ },
  { 0, 305 /* c */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 305 /* c */, MCK_GR32, 1 /* 0 */ },
  { 0, 307 /* cdb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 307 /* cdb */, MCK_FP64, 1 /* 0 */ },
  { 0, 311 /* cdbr */, MCK_FP64, 3 /* 0, 1 */ },
  { 0, 316 /* cdfbr */, MCK_FP64, 1 /* 0 */ },
  { 0, 316 /* cdfbr */, MCK_GR32, 2 /* 1 */ },
  { 0, 322 /* cdgbr */, MCK_FP64, 1 /* 0 */ },
  { 0, 322 /* cdgbr */, MCK_GR64, 2 /* 1 */ },
  { 0, 328 /* ceb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 328 /* ceb */, MCK_FP32, 1 /* 0 */ },
  { 0, 332 /* cebr */, MCK_FP32, 3 /* 0, 1 */ },
  { 0, 337 /* cefbr */, MCK_FP32, 1 /* 0 */ },
  { 0, 337 /* cefbr */, MCK_GR32, 2 /* 1 */ },
  { 0, 343 /* cegbr */, MCK_FP32, 1 /* 0 */ },
  { 0, 343 /* cegbr */, MCK_GR64, 2 /* 1 */ },
  { 0, 349 /* cfdbr */, MCK_FP64, 4 /* 2 */ },
  { 0, 349 /* cfdbr */, MCK_GR32, 1 /* 0 */ },
  { 0, 355 /* cfebr */, MCK_FP32, 4 /* 2 */ },
  { 0, 355 /* cfebr */, MCK_GR32, 1 /* 0 */ },
  { 0, 361 /* cfi */, MCK_GR32, 1 /* 0 */ },
  { 0, 365 /* cfxbr */, MCK_FP128, 4 /* 2 */ },
  { 0, 365 /* cfxbr */, MCK_GR32, 1 /* 0 */ },
  { 0, 371 /* cg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 371 /* cg */, MCK_GR64, 1 /* 0 */ },
  { 0, 374 /* cgdbr */, MCK_FP64, 4 /* 2 */ },
  { 0, 374 /* cgdbr */, MCK_GR64, 1 /* 0 */ },
  { 0, 380 /* cgebr */, MCK_FP32, 4 /* 2 */ },
  { 0, 380 /* cgebr */, MCK_GR64, 1 /* 0 */ },
  { 0, 386 /* cgf */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 386 /* cgf */, MCK_GR64, 1 /* 0 */ },
  { 0, 390 /* cgfi */, MCK_GR64, 1 /* 0 */ },
  { 0, 395 /* cgfr */, MCK_GR32, 2 /* 1 */ },
  { 0, 395 /* cgfr */, MCK_GR64, 1 /* 0 */ },
  { 0, 400 /* cgfrl */, MCK_GR64, 1 /* 0 */ },
  { 0, 400 /* cgfrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 406 /* cgh */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 406 /* cgh */, MCK_GR64, 1 /* 0 */ },
  { 0, 410 /* cghi */, MCK_GR64, 1 /* 0 */ },
  { 0, 415 /* cghrl */, MCK_GR64, 1 /* 0 */ },
  { 0, 415 /* cghrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 421 /* cghsi */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 427 /* cgij */, MCK_GR64, 1 /* 0 */ },
  { 0, 427 /* cgij */, MCK_PCRel16, 8 /* 3 */ },
  { 0, 432 /* cgije */, MCK_GR64, 1 /* 0 */ },
  { 0, 432 /* cgije */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 438 /* cgijh */, MCK_GR64, 1 /* 0 */ },
  { 0, 438 /* cgijh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 444 /* cgijhe */, MCK_GR64, 1 /* 0 */ },
  { 0, 444 /* cgijhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 451 /* cgijl */, MCK_GR64, 1 /* 0 */ },
  { 0, 451 /* cgijl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 457 /* cgijle */, MCK_GR64, 1 /* 0 */ },
  { 0, 457 /* cgijle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 464 /* cgijlh */, MCK_GR64, 1 /* 0 */ },
  { 0, 464 /* cgijlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 471 /* cgijne */, MCK_GR64, 1 /* 0 */ },
  { 0, 471 /* cgijne */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 478 /* cgijnh */, MCK_GR64, 1 /* 0 */ },
  { 0, 478 /* cgijnh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 485 /* cgijnhe */, MCK_GR64, 1 /* 0 */ },
  { 0, 485 /* cgijnhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 493 /* cgijnl */, MCK_GR64, 1 /* 0 */ },
  { 0, 493 /* cgijnl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 500 /* cgijnle */, MCK_GR64, 1 /* 0 */ },
  { 0, 500 /* cgijnle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 508 /* cgijnlh */, MCK_GR64, 1 /* 0 */ },
  { 0, 508 /* cgijnlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 516 /* cgr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 520 /* cgrj */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 520 /* cgrj */, MCK_PCRel16, 8 /* 3 */ },
  { 0, 525 /* cgrje */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 525 /* cgrje */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 531 /* cgrjh */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 531 /* cgrjh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 537 /* cgrjhe */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 537 /* cgrjhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 544 /* cgrjl */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 544 /* cgrjl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 550 /* cgrjle */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 550 /* cgrjle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 557 /* cgrjlh */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 557 /* cgrjlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 564 /* cgrjne */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 564 /* cgrjne */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 571 /* cgrjnh */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 571 /* cgrjnh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 578 /* cgrjnhe */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 578 /* cgrjnhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 586 /* cgrjnl */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 586 /* cgrjnl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 593 /* cgrjnle */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 593 /* cgrjnle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 601 /* cgrjnlh */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 601 /* cgrjnlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 609 /* cgrl */, MCK_GR64, 1 /* 0 */ },
  { 0, 609 /* cgrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 614 /* cgxbr */, MCK_FP128, 4 /* 2 */ },
  { 0, 614 /* cgxbr */, MCK_GR64, 1 /* 0 */ },
  { 0, 620 /* ch */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 620 /* ch */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureHighWord, 623 /* chf */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureHighWord, 623 /* chf */, MCK_GRH32, 1 /* 0 */ },
  { 0, 627 /* chhsi */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 633 /* chi */, MCK_GR32, 1 /* 0 */ },
  { 0, 637 /* chrl */, MCK_GR32, 1 /* 0 */ },
  { 0, 637 /* chrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 642 /* chsi */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 647 /* chy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 647 /* chy */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureHighWord, 651 /* cih */, MCK_GRH32, 1 /* 0 */ },
  { 0, 655 /* cij */, MCK_GR32, 1 /* 0 */ },
  { 0, 655 /* cij */, MCK_PCRel16, 8 /* 3 */ },
  { 0, 659 /* cije */, MCK_GR32, 1 /* 0 */ },
  { 0, 659 /* cije */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 664 /* cijh */, MCK_GR32, 1 /* 0 */ },
  { 0, 664 /* cijh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 669 /* cijhe */, MCK_GR32, 1 /* 0 */ },
  { 0, 669 /* cijhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 675 /* cijl */, MCK_GR32, 1 /* 0 */ },
  { 0, 675 /* cijl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 680 /* cijle */, MCK_GR32, 1 /* 0 */ },
  { 0, 680 /* cijle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 686 /* cijlh */, MCK_GR32, 1 /* 0 */ },
  { 0, 686 /* cijlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 692 /* cijne */, MCK_GR32, 1 /* 0 */ },
  { 0, 692 /* cijne */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 698 /* cijnh */, MCK_GR32, 1 /* 0 */ },
  { 0, 698 /* cijnh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 704 /* cijnhe */, MCK_GR32, 1 /* 0 */ },
  { 0, 704 /* cijnhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 711 /* cijnl */, MCK_GR32, 1 /* 0 */ },
  { 0, 711 /* cijnl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 717 /* cijnle */, MCK_GR32, 1 /* 0 */ },
  { 0, 717 /* cijnle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 724 /* cijnlh */, MCK_GR32, 1 /* 0 */ },
  { 0, 724 /* cijnlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 731 /* cl */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 731 /* cl */, MCK_GR32, 1 /* 0 */ },
  { 0, 734 /* clc */, MCK_BDAddr64Disp12, 2 /* 1 */ },
  { 0, 734 /* clc */, MCK_BDLAddr64Disp12Len8, 1 /* 0 */ },
  { 0, 738 /* clfhsi */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 745 /* clfi */, MCK_GR32, 1 /* 0 */ },
  { 0, 750 /* clg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 750 /* clg */, MCK_GR64, 1 /* 0 */ },
  { 0, 754 /* clgf */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 754 /* clgf */, MCK_GR64, 1 /* 0 */ },
  { 0, 759 /* clgfi */, MCK_GR64, 1 /* 0 */ },
  { 0, 765 /* clgfr */, MCK_GR32, 2 /* 1 */ },
  { 0, 765 /* clgfr */, MCK_GR64, 1 /* 0 */ },
  { 0, 771 /* clgfrl */, MCK_GR64, 1 /* 0 */ },
  { 0, 771 /* clgfrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 778 /* clghrl */, MCK_GR64, 1 /* 0 */ },
  { 0, 778 /* clghrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 785 /* clghsi */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 792 /* clgij */, MCK_GR64, 1 /* 0 */ },
  { 0, 792 /* clgij */, MCK_PCRel16, 8 /* 3 */ },
  { 0, 798 /* clgije */, MCK_GR64, 1 /* 0 */ },
  { 0, 798 /* clgije */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 805 /* clgijh */, MCK_GR64, 1 /* 0 */ },
  { 0, 805 /* clgijh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 812 /* clgijhe */, MCK_GR64, 1 /* 0 */ },
  { 0, 812 /* clgijhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 820 /* clgijl */, MCK_GR64, 1 /* 0 */ },
  { 0, 820 /* clgijl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 827 /* clgijle */, MCK_GR64, 1 /* 0 */ },
  { 0, 827 /* clgijle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 835 /* clgijlh */, MCK_GR64, 1 /* 0 */ },
  { 0, 835 /* clgijlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 843 /* clgijne */, MCK_GR64, 1 /* 0 */ },
  { 0, 843 /* clgijne */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 851 /* clgijnh */, MCK_GR64, 1 /* 0 */ },
  { 0, 851 /* clgijnh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 859 /* clgijnhe */, MCK_GR64, 1 /* 0 */ },
  { 0, 859 /* clgijnhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 868 /* clgijnl */, MCK_GR64, 1 /* 0 */ },
  { 0, 868 /* clgijnl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 876 /* clgijnle */, MCK_GR64, 1 /* 0 */ },
  { 0, 876 /* clgijnle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 885 /* clgijnlh */, MCK_GR64, 1 /* 0 */ },
  { 0, 885 /* clgijnlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 894 /* clgr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 899 /* clgrj */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 899 /* clgrj */, MCK_PCRel16, 8 /* 3 */ },
  { 0, 905 /* clgrje */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 905 /* clgrje */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 912 /* clgrjh */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 912 /* clgrjh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 919 /* clgrjhe */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 919 /* clgrjhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 927 /* clgrjl */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 927 /* clgrjl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 934 /* clgrjle */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 934 /* clgrjle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 942 /* clgrjlh */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 942 /* clgrjlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 950 /* clgrjne */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 950 /* clgrjne */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 958 /* clgrjnh */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 958 /* clgrjnh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 966 /* clgrjnhe */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 966 /* clgrjnhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 975 /* clgrjnl */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 975 /* clgrjnl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 983 /* clgrjnle */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 983 /* clgrjnle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 992 /* clgrjnlh */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 992 /* clgrjnlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1001 /* clgrl */, MCK_GR64, 1 /* 0 */ },
  { 0, 1001 /* clgrl */, MCK_PCRel32, 2 /* 1 */ },
  { Feature_FeatureHighWord, 1007 /* clhf */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureHighWord, 1007 /* clhf */, MCK_GRH32, 1 /* 0 */ },
  { 0, 1012 /* clhhsi */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 1019 /* clhrl */, MCK_GR32, 1 /* 0 */ },
  { 0, 1019 /* clhrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 1025 /* cli */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { Feature_FeatureHighWord, 1029 /* clih */, MCK_GR32, 1 /* 0 */ },
  { 0, 1034 /* clij */, MCK_GR32, 1 /* 0 */ },
  { 0, 1034 /* clij */, MCK_PCRel16, 8 /* 3 */ },
  { 0, 1039 /* clije */, MCK_GR32, 1 /* 0 */ },
  { 0, 1039 /* clije */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1045 /* clijh */, MCK_GR32, 1 /* 0 */ },
  { 0, 1045 /* clijh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1051 /* clijhe */, MCK_GR32, 1 /* 0 */ },
  { 0, 1051 /* clijhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1058 /* clijl */, MCK_GR32, 1 /* 0 */ },
  { 0, 1058 /* clijl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1064 /* clijle */, MCK_GR32, 1 /* 0 */ },
  { 0, 1064 /* clijle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1071 /* clijlh */, MCK_GR32, 1 /* 0 */ },
  { 0, 1071 /* clijlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1078 /* clijne */, MCK_GR32, 1 /* 0 */ },
  { 0, 1078 /* clijne */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1085 /* clijnh */, MCK_GR32, 1 /* 0 */ },
  { 0, 1085 /* clijnh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1092 /* clijnhe */, MCK_GR32, 1 /* 0 */ },
  { 0, 1092 /* clijnhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1100 /* clijnl */, MCK_GR32, 1 /* 0 */ },
  { 0, 1100 /* clijnl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1107 /* clijnle */, MCK_GR32, 1 /* 0 */ },
  { 0, 1107 /* clijnle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1115 /* clijnlh */, MCK_GR32, 1 /* 0 */ },
  { 0, 1115 /* clijnlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1123 /* cliy */, MCK_BDAddr64Disp20, 1 /* 0 */ },
  { 0, 1128 /* clr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1132 /* clrj */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1132 /* clrj */, MCK_PCRel16, 8 /* 3 */ },
  { 0, 1137 /* clrje */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1137 /* clrje */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1143 /* clrjh */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1143 /* clrjh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1149 /* clrjhe */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1149 /* clrjhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1156 /* clrjl */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1156 /* clrjl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1162 /* clrjle */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1162 /* clrjle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1169 /* clrjlh */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1169 /* clrjlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1176 /* clrjne */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1176 /* clrjne */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1183 /* clrjnh */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1183 /* clrjnh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1190 /* clrjnhe */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1190 /* clrjnhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1198 /* clrjnl */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1198 /* clrjnl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1205 /* clrjnle */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1205 /* clrjnle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1213 /* clrjnlh */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1213 /* clrjnlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1221 /* clrl */, MCK_GR32, 1 /* 0 */ },
  { 0, 1221 /* clrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 1226 /* clst */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 1231 /* cly */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1231 /* cly */, MCK_GR32, 1 /* 0 */ },
  { 0, 1235 /* cpsdr */, MCK_FP64, 7 /* 0, 1, 2 */ },
  { 0, 1241 /* cr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1244 /* crj */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1244 /* crj */, MCK_PCRel16, 8 /* 3 */ },
  { 0, 1248 /* crje */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1248 /* crje */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1253 /* crjh */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1253 /* crjh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1258 /* crjhe */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1258 /* crjhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1264 /* crjl */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1264 /* crjl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1269 /* crjle */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1269 /* crjle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1275 /* crjlh */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1275 /* crjlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1281 /* crjne */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1281 /* crjne */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1287 /* crjnh */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1287 /* crjnh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1293 /* crjnhe */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1293 /* crjnhe */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1300 /* crjnl */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1300 /* crjnl */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1306 /* crjnle */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1306 /* crjnle */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1313 /* crjnlh */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1313 /* crjnlh */, MCK_PCRel16, 4 /* 2 */ },
  { 0, 1320 /* crl */, MCK_GR32, 1 /* 0 */ },
  { 0, 1320 /* crl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 1324 /* cs */, MCK_BDAddr64Disp12, 4 /* 2 */ },
  { 0, 1324 /* cs */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1327 /* csg */, MCK_BDAddr64Disp20, 4 /* 2 */ },
  { 0, 1327 /* csg */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 1331 /* csy */, MCK_BDAddr64Disp20, 4 /* 2 */ },
  { 0, 1331 /* csy */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1335 /* cxbr */, MCK_FP128, 3 /* 0, 1 */ },
  { 0, 1340 /* cxfbr */, MCK_FP128, 1 /* 0 */ },
  { 0, 1340 /* cxfbr */, MCK_GR32, 2 /* 1 */ },
  { 0, 1346 /* cxgbr */, MCK_FP128, 1 /* 0 */ },
  { 0, 1346 /* cxgbr */, MCK_GR64, 2 /* 1 */ },
  { 0, 1352 /* cy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1352 /* cy */, MCK_GR32, 1 /* 0 */ },
  { 0, 1355 /* ddb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 1355 /* ddb */, MCK_FP64, 1 /* 0 */ },
  { 0, 1359 /* ddbr */, MCK_FP64, 3 /* 0, 1 */ },
  { 0, 1364 /* deb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 1364 /* deb */, MCK_FP32, 1 /* 0 */ },
  { 0, 1368 /* debr */, MCK_FP32, 3 /* 0, 1 */ },
  { 0, 1373 /* dl */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1373 /* dl */, MCK_GR128, 1 /* 0 */ },
  { 0, 1376 /* dlg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1376 /* dlg */, MCK_GR128, 1 /* 0 */ },
  { 0, 1380 /* dlgr */, MCK_GR128, 1 /* 0 */ },
  { 0, 1380 /* dlgr */, MCK_GR64, 2 /* 1 */ },
  { 0, 1385 /* dlr */, MCK_GR128, 1 /* 0 */ },
  { 0, 1385 /* dlr */, MCK_GR32, 2 /* 1 */ },
  { 0, 1389 /* dsg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1389 /* dsg */, MCK_GR128, 1 /* 0 */ },
  { 0, 1393 /* dsgf */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1393 /* dsgf */, MCK_GR128, 1 /* 0 */ },
  { 0, 1398 /* dsgfr */, MCK_GR128, 1 /* 0 */ },
  { 0, 1398 /* dsgfr */, MCK_GR32, 2 /* 1 */ },
  { 0, 1404 /* dsgr */, MCK_GR128, 1 /* 0 */ },
  { 0, 1404 /* dsgr */, MCK_GR64, 2 /* 1 */ },
  { 0, 1409 /* dxbr */, MCK_FP128, 3 /* 0, 1 */ },
  { 0, 1414 /* ear */, MCK_AccessReg, 2 /* 1 */ },
  { 0, 1414 /* ear */, MCK_GR32, 1 /* 0 */ },
  { 0, 1418 /* fidbr */, MCK_FP64, 5 /* 0, 2 */ },
  { Feature_FeatureFPExtension, 1424 /* fidbra */, MCK_FP64, 5 /* 0, 2 */ },
  { 0, 1431 /* fiebr */, MCK_FP32, 5 /* 0, 2 */ },
  { Feature_FeatureFPExtension, 1437 /* fiebra */, MCK_FP32, 5 /* 0, 2 */ },
  { 0, 1444 /* fixbr */, MCK_FP128, 5 /* 0, 2 */ },
  { Feature_FeatureFPExtension, 1450 /* fixbra */, MCK_FP128, 5 /* 0, 2 */ },
  { 0, 1457 /* flogr */, MCK_GR128, 1 /* 0 */ },
  { 0, 1457 /* flogr */, MCK_GR64, 2 /* 1 */ },
  { 0, 1463 /* ic */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 1463 /* ic */, MCK_GR64, 1 /* 0 */ },
  { 0, 1466 /* icy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1466 /* icy */, MCK_GR64, 1 /* 0 */ },
  { 0, 1470 /* iihf */, MCK_GRH32, 1 /* 0 */ },
  { 0, 1475 /* iihh */, MCK_GRH32, 1 /* 0 */ },
  { 0, 1480 /* iihl */, MCK_GRH32, 1 /* 0 */ },
  { 0, 1485 /* iilf */, MCK_GR32, 1 /* 0 */ },
  { 0, 1490 /* iilh */, MCK_GR32, 1 /* 0 */ },
  { 0, 1495 /* iill */, MCK_GR32, 1 /* 0 */ },
  { 0, 1500 /* ipm */, MCK_GR32, 1 /* 0 */ },
  { 0, 1504 /* j */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1506 /* je */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1509 /* jg */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1512 /* jge */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1516 /* jgh */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1520 /* jghe */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1525 /* jgl */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1529 /* jgle */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1534 /* jglh */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1539 /* jgne */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1544 /* jgnh */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1549 /* jgnhe */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1555 /* jgnl */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1560 /* jgnle */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1566 /* jgnlh */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1572 /* jgno */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1577 /* jgo */, MCK_PCRel32, 1 /* 0 */ },
  { 0, 1581 /* jh */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1584 /* jhe */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1588 /* jl */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1591 /* jle */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1595 /* jlh */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1599 /* jne */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1603 /* jnh */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1607 /* jnhe */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1612 /* jnl */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1616 /* jnle */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1621 /* jnlh */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1626 /* jno */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1630 /* jo */, MCK_PCRel16, 1 /* 0 */ },
  { 0, 1633 /* l */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 1633 /* l */, MCK_GR32, 1 /* 0 */ },
  { 0, 1635 /* la */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 1635 /* la */, MCK_GR64, 1 /* 0 */ },
  { 0, 1638 /* larl */, MCK_GR64, 1 /* 0 */ },
  { 0, 1638 /* larl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 1643 /* lay */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1643 /* lay */, MCK_GR64, 1 /* 0 */ },
  { 0, 1647 /* lb */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1647 /* lb */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureHighWord, 1650 /* lbh */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureHighWord, 1650 /* lbh */, MCK_GRH32, 1 /* 0 */ },
  { 0, 1654 /* lbr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1658 /* lcdbr */, MCK_FP64, 3 /* 0, 1 */ },
  { 0, 1664 /* lcebr */, MCK_FP32, 3 /* 0, 1 */ },
  { 0, 1670 /* lcgfr */, MCK_GR32, 2 /* 1 */ },
  { 0, 1670 /* lcgfr */, MCK_GR64, 1 /* 0 */ },
  { 0, 1676 /* lcgr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 1681 /* lcr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1685 /* lcxbr */, MCK_FP128, 3 /* 0, 1 */ },
  { 0, 1691 /* ld */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 1691 /* ld */, MCK_FP64, 1 /* 0 */ },
  { 0, 1694 /* ldeb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 1694 /* ldeb */, MCK_FP64, 1 /* 0 */ },
  { 0, 1699 /* ldebr */, MCK_FP32, 2 /* 1 */ },
  { 0, 1699 /* ldebr */, MCK_FP64, 1 /* 0 */ },
  { 0, 1705 /* ldgr */, MCK_FP64, 1 /* 0 */ },
  { 0, 1705 /* ldgr */, MCK_GR64, 2 /* 1 */ },
  { 0, 1710 /* ldr */, MCK_FP64, 3 /* 0, 1 */ },
  { 0, 1714 /* ldxbr */, MCK_FP128, 3 /* 0, 1 */ },
  { 0, 1720 /* ldy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1720 /* ldy */, MCK_FP64, 1 /* 0 */ },
  { 0, 1724 /* le */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 1724 /* le */, MCK_FP32, 1 /* 0 */ },
  { 0, 1727 /* ledbr */, MCK_FP32, 1 /* 0 */ },
  { 0, 1727 /* ledbr */, MCK_FP64, 2 /* 1 */ },
  { 0, 1733 /* ler */, MCK_FP32, 3 /* 0, 1 */ },
  { 0, 1737 /* lexbr */, MCK_FP128, 3 /* 0, 1 */ },
  { 0, 1743 /* ley */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1743 /* ley */, MCK_FP32, 1 /* 0 */ },
  { Feature_FeatureHighWord, 1747 /* lfh */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureHighWord, 1747 /* lfh */, MCK_GRH32, 1 /* 0 */ },
  { 0, 1751 /* lg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1751 /* lg */, MCK_GR64, 1 /* 0 */ },
  { 0, 1754 /* lgb */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1754 /* lgb */, MCK_GR64, 1 /* 0 */ },
  { 0, 1758 /* lgbr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 1763 /* lgdr */, MCK_FP64, 2 /* 1 */ },
  { 0, 1763 /* lgdr */, MCK_GR64, 1 /* 0 */ },
  { 0, 1768 /* lgf */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1768 /* lgf */, MCK_GR64, 1 /* 0 */ },
  { 0, 1772 /* lgfi */, MCK_GR64, 1 /* 0 */ },
  { 0, 1777 /* lgfr */, MCK_GR32, 2 /* 1 */ },
  { 0, 1777 /* lgfr */, MCK_GR64, 1 /* 0 */ },
  { 0, 1782 /* lgfrl */, MCK_GR64, 1 /* 0 */ },
  { 0, 1782 /* lgfrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 1788 /* lgh */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1788 /* lgh */, MCK_GR64, 1 /* 0 */ },
  { 0, 1792 /* lghi */, MCK_GR64, 1 /* 0 */ },
  { 0, 1797 /* lghr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 1802 /* lghrl */, MCK_GR64, 1 /* 0 */ },
  { 0, 1802 /* lghrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 1808 /* lgr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 1812 /* lgrl */, MCK_GR64, 1 /* 0 */ },
  { 0, 1812 /* lgrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 1817 /* lh */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 1817 /* lh */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureHighWord, 1820 /* lhh */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureHighWord, 1820 /* lhh */, MCK_GRH32, 1 /* 0 */ },
  { 0, 1824 /* lhi */, MCK_GR32, 1 /* 0 */ },
  { 0, 1828 /* lhr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1832 /* lhrl */, MCK_GR32, 1 /* 0 */ },
  { 0, 1832 /* lhrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 1837 /* lhy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1837 /* lhy */, MCK_GR32, 1 /* 0 */ },
  { 0, 1841 /* llc */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1841 /* llc */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureHighWord, 1845 /* llch */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureHighWord, 1845 /* llch */, MCK_GR32, 1 /* 0 */ },
  { 0, 1850 /* llcr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1855 /* llgc */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1855 /* llgc */, MCK_GR64, 1 /* 0 */ },
  { 0, 1860 /* llgcr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 1866 /* llgf */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1866 /* llgf */, MCK_GR64, 1 /* 0 */ },
  { 0, 1871 /* llgfr */, MCK_GR32, 2 /* 1 */ },
  { 0, 1871 /* llgfr */, MCK_GR64, 1 /* 0 */ },
  { 0, 1877 /* llgfrl */, MCK_GR64, 1 /* 0 */ },
  { 0, 1877 /* llgfrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 1884 /* llgh */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1884 /* llgh */, MCK_GR64, 1 /* 0 */ },
  { 0, 1889 /* llghr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 1895 /* llghrl */, MCK_GR64, 1 /* 0 */ },
  { 0, 1895 /* llghrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 1902 /* llh */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 1902 /* llh */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureHighWord, 1906 /* llhh */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureHighWord, 1906 /* llhh */, MCK_GR32, 1 /* 0 */ },
  { 0, 1911 /* llhr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1916 /* llhrl */, MCK_GR32, 1 /* 0 */ },
  { 0, 1916 /* llhrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 1922 /* llihf */, MCK_GR64, 1 /* 0 */ },
  { 0, 1928 /* llihh */, MCK_GR64, 1 /* 0 */ },
  { 0, 1934 /* llihl */, MCK_GR64, 1 /* 0 */ },
  { 0, 1940 /* llilf */, MCK_GR64, 1 /* 0 */ },
  { 0, 1946 /* llilh */, MCK_GR64, 1 /* 0 */ },
  { 0, 1952 /* llill */, MCK_GR64, 1 /* 0 */ },
  { 0, 1958 /* lmg */, MCK_BDAddr64Disp20, 4 /* 2 */ },
  { 0, 1958 /* lmg */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 1962 /* lndbr */, MCK_FP64, 3 /* 0, 1 */ },
  { 0, 1968 /* lnebr */, MCK_FP32, 3 /* 0, 1 */ },
  { 0, 1974 /* lngfr */, MCK_GR32, 2 /* 1 */ },
  { 0, 1974 /* lngfr */, MCK_GR64, 1 /* 0 */ },
  { 0, 1980 /* lngr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 1985 /* lnr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 1989 /* lnxbr */, MCK_FP128, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 1995 /* loc */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 1995 /* loc */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 1999 /* loce */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 1999 /* loce */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2004 /* locg */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2004 /* locg */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2009 /* locge */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2009 /* locge */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2015 /* locgh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2015 /* locgh */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2021 /* locghe */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2021 /* locghe */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2028 /* locgl */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2028 /* locgl */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2034 /* locgle */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2034 /* locgle */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2041 /* locglh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2041 /* locglh */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2048 /* locgne */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2048 /* locgne */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2055 /* locgnh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2055 /* locgnh */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2062 /* locgnhe */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2062 /* locgnhe */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2070 /* locgnl */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2070 /* locgnl */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2077 /* locgnle */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2077 /* locgnle */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2085 /* locgnlh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2085 /* locgnlh */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2093 /* locgno */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2093 /* locgno */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2100 /* locgo */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2100 /* locgo */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2106 /* locgr */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2112 /* locgre */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2119 /* locgrh */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2126 /* locgrhe */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2134 /* locgrl */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2141 /* locgrle */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2149 /* locgrlh */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2157 /* locgrne */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2165 /* locgrnh */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2173 /* locgrnhe */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2182 /* locgrnl */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2190 /* locgrnle */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2199 /* locgrnlh */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2208 /* locgrno */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2216 /* locgro */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2223 /* loch */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2223 /* loch */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2228 /* loche */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2228 /* loche */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2234 /* locl */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2234 /* locl */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2239 /* locle */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2239 /* locle */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2245 /* loclh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2245 /* loclh */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2251 /* locne */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2251 /* locne */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2257 /* locnh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2257 /* locnh */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2263 /* locnhe */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2263 /* locnhe */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2270 /* locnl */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2270 /* locnl */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2276 /* locnle */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2276 /* locnle */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2283 /* locnlh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2283 /* locnlh */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2290 /* locno */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2290 /* locno */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2296 /* loco */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2296 /* loco */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 2301 /* locr */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2306 /* locre */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2312 /* locrh */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2318 /* locrhe */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2325 /* locrl */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2331 /* locrle */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2338 /* locrlh */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2345 /* locrne */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2352 /* locrnh */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2359 /* locrnhe */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2367 /* locrnl */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2374 /* locrnle */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2382 /* locrnlh */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2390 /* locrno */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 2397 /* locro */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 2403 /* lpdbr */, MCK_FP64, 3 /* 0, 1 */ },
  { 0, 2409 /* lpebr */, MCK_FP32, 3 /* 0, 1 */ },
  { 0, 2415 /* lpgfr */, MCK_GR32, 2 /* 1 */ },
  { 0, 2415 /* lpgfr */, MCK_GR64, 1 /* 0 */ },
  { 0, 2421 /* lpgr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 2426 /* lpr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 2430 /* lpxbr */, MCK_FP128, 3 /* 0, 1 */ },
  { 0, 2436 /* lr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 2439 /* lrl */, MCK_GR32, 1 /* 0 */ },
  { 0, 2439 /* lrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 2443 /* lrv */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2443 /* lrv */, MCK_GR32, 1 /* 0 */ },
  { 0, 2447 /* lrvg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2447 /* lrvg */, MCK_GR64, 1 /* 0 */ },
  { 0, 2452 /* lrvgr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 2458 /* lrvr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 2463 /* lt */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2463 /* lt */, MCK_GR32, 1 /* 0 */ },
  { 0, 2466 /* ltdbr */, MCK_FP64, 3 /* 0, 1 */ },
  { 0, 2472 /* ltebr */, MCK_FP32, 3 /* 0, 1 */ },
  { 0, 2478 /* ltg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2478 /* ltg */, MCK_GR64, 1 /* 0 */ },
  { 0, 2482 /* ltgf */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2482 /* ltgf */, MCK_GR64, 1 /* 0 */ },
  { 0, 2487 /* ltgfr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 2493 /* ltgr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 2498 /* ltr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 2502 /* ltxbr */, MCK_FP128, 3 /* 0, 1 */ },
  { 0, 2508 /* lxdb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2508 /* lxdb */, MCK_FP128, 1 /* 0 */ },
  { 0, 2513 /* lxdbr */, MCK_FP128, 1 /* 0 */ },
  { 0, 2513 /* lxdbr */, MCK_FP64, 2 /* 1 */ },
  { 0, 2519 /* lxeb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2519 /* lxeb */, MCK_FP128, 1 /* 0 */ },
  { 0, 2524 /* lxebr */, MCK_FP128, 1 /* 0 */ },
  { 0, 2524 /* lxebr */, MCK_FP32, 2 /* 1 */ },
  { 0, 2530 /* lxr */, MCK_FP128, 3 /* 0, 1 */ },
  { 0, 2534 /* ly */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2534 /* ly */, MCK_GR32, 1 /* 0 */ },
  { 0, 2537 /* lzdr */, MCK_FP64, 1 /* 0 */ },
  { 0, 2542 /* lzer */, MCK_FP32, 1 /* 0 */ },
  { 0, 2547 /* lzxr */, MCK_FP128, 1 /* 0 */ },
  { 0, 2552 /* madb */, MCK_BDXAddr64Disp12, 4 /* 2 */ },
  { 0, 2552 /* madb */, MCK_FP64, 3 /* 0, 1 */ },
  { 0, 2557 /* madbr */, MCK_FP64, 7 /* 0, 1, 2 */ },
  { 0, 2563 /* maeb */, MCK_BDXAddr64Disp12, 4 /* 2 */ },
  { 0, 2563 /* maeb */, MCK_FP32, 3 /* 0, 1 */ },
  { 0, 2568 /* maebr */, MCK_FP32, 7 /* 0, 1, 2 */ },
  { 0, 2574 /* mdb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2574 /* mdb */, MCK_FP64, 1 /* 0 */ },
  { 0, 2578 /* mdbr */, MCK_FP64, 3 /* 0, 1 */ },
  { 0, 2583 /* mdeb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2583 /* mdeb */, MCK_FP64, 1 /* 0 */ },
  { 0, 2588 /* mdebr */, MCK_FP32, 2 /* 1 */ },
  { 0, 2588 /* mdebr */, MCK_FP64, 1 /* 0 */ },
  { 0, 2594 /* meeb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2594 /* meeb */, MCK_FP32, 1 /* 0 */ },
  { 0, 2599 /* meebr */, MCK_FP32, 3 /* 0, 1 */ },
  { 0, 2605 /* mghi */, MCK_GR64, 1 /* 0 */ },
  { 0, 2610 /* mh */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2610 /* mh */, MCK_GR32, 1 /* 0 */ },
  { 0, 2613 /* mhi */, MCK_GR32, 1 /* 0 */ },
  { 0, 2617 /* mhy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2617 /* mhy */, MCK_GR32, 1 /* 0 */ },
  { 0, 2621 /* mlg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2621 /* mlg */, MCK_GR128, 1 /* 0 */ },
  { 0, 2625 /* mlgr */, MCK_GR128, 1 /* 0 */ },
  { 0, 2625 /* mlgr */, MCK_GR64, 2 /* 1 */ },
  { 0, 2630 /* ms */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2630 /* ms */, MCK_GR32, 1 /* 0 */ },
  { 0, 2633 /* msdb */, MCK_BDXAddr64Disp12, 4 /* 2 */ },
  { 0, 2633 /* msdb */, MCK_FP64, 3 /* 0, 1 */ },
  { 0, 2638 /* msdbr */, MCK_FP64, 7 /* 0, 1, 2 */ },
  { 0, 2644 /* mseb */, MCK_BDXAddr64Disp12, 4 /* 2 */ },
  { 0, 2644 /* mseb */, MCK_FP32, 3 /* 0, 1 */ },
  { 0, 2649 /* msebr */, MCK_FP32, 7 /* 0, 1, 2 */ },
  { 0, 2655 /* msfi */, MCK_GR32, 1 /* 0 */ },
  { 0, 2660 /* msg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2660 /* msg */, MCK_GR64, 1 /* 0 */ },
  { 0, 2664 /* msgf */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2664 /* msgf */, MCK_GR64, 1 /* 0 */ },
  { 0, 2669 /* msgfi */, MCK_GR64, 1 /* 0 */ },
  { 0, 2675 /* msgfr */, MCK_GR32, 2 /* 1 */ },
  { 0, 2675 /* msgfr */, MCK_GR64, 1 /* 0 */ },
  { 0, 2681 /* msgr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 2686 /* msr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 2690 /* msy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2690 /* msy */, MCK_GR32, 1 /* 0 */ },
  { 0, 2694 /* mvc */, MCK_BDAddr64Disp12, 2 /* 1 */ },
  { 0, 2694 /* mvc */, MCK_BDLAddr64Disp12Len8, 1 /* 0 */ },
  { 0, 2698 /* mvghi */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 2704 /* mvhhi */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 2710 /* mvhi */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 2715 /* mvi */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 2719 /* mviy */, MCK_BDAddr64Disp20, 1 /* 0 */ },
  { 0, 2724 /* mvst */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 2729 /* mxbr */, MCK_FP128, 3 /* 0, 1 */ },
  { 0, 2734 /* mxdb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2734 /* mxdb */, MCK_FP128, 1 /* 0 */ },
  { 0, 2739 /* mxdbr */, MCK_FP128, 1 /* 0 */ },
  { 0, 2739 /* mxdbr */, MCK_FP64, 2 /* 1 */ },
  { 0, 2745 /* n */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2745 /* n */, MCK_GR32, 1 /* 0 */ },
  { 0, 2747 /* nc */, MCK_BDAddr64Disp12, 2 /* 1 */ },
  { 0, 2747 /* nc */, MCK_BDLAddr64Disp12Len8, 1 /* 0 */ },
  { 0, 2750 /* ng */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2750 /* ng */, MCK_GR64, 1 /* 0 */ },
  { 0, 2753 /* ngr */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 2757 /* ngrk */, MCK_GR64, 7 /* 0, 1, 2 */ },
  { 0, 2762 /* ni */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 2765 /* nihf */, MCK_GRH32, 1 /* 0 */ },
  { 0, 2770 /* nihh */, MCK_GRH32, 1 /* 0 */ },
  { 0, 2775 /* nihl */, MCK_GRH32, 1 /* 0 */ },
  { 0, 2780 /* nilf */, MCK_GR32, 1 /* 0 */ },
  { 0, 2785 /* nilh */, MCK_GR32, 1 /* 0 */ },
  { 0, 2790 /* nill */, MCK_GR32, 1 /* 0 */ },
  { 0, 2795 /* niy */, MCK_BDAddr64Disp20, 1 /* 0 */ },
  { 0, 2799 /* nr */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 2802 /* nrk */, MCK_GR32, 7 /* 0, 1, 2 */ },
  { 0, 2806 /* ny */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2806 /* ny */, MCK_GR32, 1 /* 0 */ },
  { 0, 2809 /* o */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2809 /* o */, MCK_GR32, 1 /* 0 */ },
  { 0, 2811 /* oc */, MCK_BDAddr64Disp12, 2 /* 1 */ },
  { 0, 2811 /* oc */, MCK_BDLAddr64Disp12Len8, 1 /* 0 */ },
  { 0, 2814 /* og */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2814 /* og */, MCK_GR64, 1 /* 0 */ },
  { 0, 2817 /* ogr */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 2821 /* ogrk */, MCK_GR64, 7 /* 0, 1, 2 */ },
  { 0, 2826 /* oi */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 2829 /* oihf */, MCK_GRH32, 1 /* 0 */ },
  { 0, 2834 /* oihh */, MCK_GRH32, 1 /* 0 */ },
  { 0, 2839 /* oihl */, MCK_GRH32, 1 /* 0 */ },
  { 0, 2844 /* oilf */, MCK_GR32, 1 /* 0 */ },
  { 0, 2849 /* oilh */, MCK_GR32, 1 /* 0 */ },
  { 0, 2854 /* oill */, MCK_GR32, 1 /* 0 */ },
  { 0, 2859 /* oiy */, MCK_BDAddr64Disp20, 1 /* 0 */ },
  { 0, 2863 /* or */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 2866 /* ork */, MCK_GR32, 7 /* 0, 1, 2 */ },
  { 0, 2870 /* oy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2870 /* oy */, MCK_GR32, 1 /* 0 */ },
  { 0, 2873 /* pfd */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2877 /* pfdrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 2883 /* risbg */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureHighWord, 2889 /* risbhg */, MCK_GR64, 2 /* 1 */ },
  { Feature_FeatureHighWord, 2889 /* risbhg */, MCK_GRH32, 1 /* 0 */ },
  { Feature_FeatureHighWord, 2896 /* risblg */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureHighWord, 2896 /* risblg */, MCK_GR64, 2 /* 1 */ },
  { 0, 2903 /* rll */, MCK_BDAddr32Disp20, 4 /* 2 */ },
  { 0, 2903 /* rll */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 2907 /* rllg */, MCK_BDAddr32Disp20, 4 /* 2 */ },
  { 0, 2907 /* rllg */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 2912 /* rnsbg */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 2918 /* rosbg */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 2924 /* rxsbg */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 2930 /* s */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2930 /* s */, MCK_GR32, 1 /* 0 */ },
  { 0, 2932 /* sdb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2932 /* sdb */, MCK_FP64, 1 /* 0 */ },
  { 0, 2936 /* sdbr */, MCK_FP64, 3 /* 0, 1 */ },
  { 0, 2941 /* seb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2941 /* seb */, MCK_FP32, 1 /* 0 */ },
  { 0, 2945 /* sebr */, MCK_FP32, 3 /* 0, 1 */ },
  { 0, 2950 /* sg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2950 /* sg */, MCK_GR64, 1 /* 0 */ },
  { 0, 2953 /* sgf */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2953 /* sgf */, MCK_GR64, 1 /* 0 */ },
  { 0, 2957 /* sgfr */, MCK_GR32, 2 /* 1 */ },
  { 0, 2957 /* sgfr */, MCK_GR64, 1 /* 0 */ },
  { 0, 2962 /* sgr */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 2966 /* sgrk */, MCK_GR64, 7 /* 0, 1, 2 */ },
  { 0, 2971 /* sh */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2971 /* sh */, MCK_GR32, 1 /* 0 */ },
  { 0, 2974 /* shy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2974 /* shy */, MCK_GR32, 1 /* 0 */ },
  { 0, 2978 /* sl */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 2978 /* sl */, MCK_GR32, 1 /* 0 */ },
  { 0, 2981 /* slb */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2981 /* slb */, MCK_GR32, 1 /* 0 */ },
  { 0, 2985 /* slbg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 2985 /* slbg */, MCK_GR64, 1 /* 0 */ },
  { 0, 2990 /* slbgr */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 2996 /* slbr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 3001 /* slfi */, MCK_GR32, 1 /* 0 */ },
  { 0, 3006 /* slg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3006 /* slg */, MCK_GR64, 1 /* 0 */ },
  { 0, 3010 /* slgf */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3010 /* slgf */, MCK_GR64, 1 /* 0 */ },
  { 0, 3015 /* slgfi */, MCK_GR64, 1 /* 0 */ },
  { 0, 3021 /* slgfr */, MCK_GR32, 2 /* 1 */ },
  { 0, 3021 /* slgfr */, MCK_GR64, 1 /* 0 */ },
  { 0, 3027 /* slgr */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 3032 /* slgrk */, MCK_GR64, 7 /* 0, 1, 2 */ },
  { 0, 3038 /* sll */, MCK_BDAddr32Disp12, 2 /* 1 */ },
  { 0, 3038 /* sll */, MCK_GR32, 1 /* 0 */ },
  { 0, 3042 /* sllg */, MCK_BDAddr32Disp20, 4 /* 2 */ },
  { 0, 3042 /* sllg */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 3047 /* sllk */, MCK_BDAddr32Disp20, 4 /* 2 */ },
  { Feature_FeatureDistinctOps, 3047 /* sllk */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 3052 /* slr */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 3056 /* slrk */, MCK_GR32, 7 /* 0, 1, 2 */ },
  { 0, 3061 /* sly */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3061 /* sly */, MCK_GR32, 1 /* 0 */ },
  { 0, 3065 /* sqdb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 3065 /* sqdb */, MCK_FP64, 1 /* 0 */ },
  { 0, 3070 /* sqdbr */, MCK_FP64, 3 /* 0, 1 */ },
  { 0, 3076 /* sqeb */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 3076 /* sqeb */, MCK_FP32, 1 /* 0 */ },
  { 0, 3081 /* sqebr */, MCK_FP32, 3 /* 0, 1 */ },
  { 0, 3087 /* sqxbr */, MCK_FP128, 3 /* 0, 1 */ },
  { 0, 3093 /* sr */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 3096 /* sra */, MCK_BDAddr32Disp12, 2 /* 1 */ },
  { 0, 3096 /* sra */, MCK_GR32, 1 /* 0 */ },
  { 0, 3100 /* srag */, MCK_BDAddr32Disp20, 4 /* 2 */ },
  { 0, 3100 /* srag */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 3105 /* srak */, MCK_BDAddr32Disp20, 4 /* 2 */ },
  { Feature_FeatureDistinctOps, 3105 /* srak */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 3110 /* srk */, MCK_GR32, 7 /* 0, 1, 2 */ },
  { 0, 3114 /* srl */, MCK_BDAddr32Disp12, 2 /* 1 */ },
  { 0, 3114 /* srl */, MCK_GR32, 1 /* 0 */ },
  { 0, 3118 /* srlg */, MCK_BDAddr32Disp20, 4 /* 2 */ },
  { 0, 3118 /* srlg */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 3123 /* srlk */, MCK_BDAddr32Disp20, 4 /* 2 */ },
  { Feature_FeatureDistinctOps, 3123 /* srlk */, MCK_GR32, 3 /* 0, 1 */ },
  { 0, 3128 /* srst */, MCK_GR64, 3 /* 0, 1 */ },
  { 0, 3133 /* st */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 3133 /* st */, MCK_GR32, 1 /* 0 */ },
  { 0, 3136 /* stc */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 3136 /* stc */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureHighWord, 3140 /* stch */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureHighWord, 3140 /* stch */, MCK_GRH32, 1 /* 0 */ },
  { 0, 3145 /* stcy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3145 /* stcy */, MCK_GR32, 1 /* 0 */ },
  { 0, 3150 /* std */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 3150 /* std */, MCK_FP64, 1 /* 0 */ },
  { 0, 3154 /* stdy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3154 /* stdy */, MCK_FP64, 1 /* 0 */ },
  { 0, 3159 /* ste */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 3159 /* ste */, MCK_FP32, 1 /* 0 */ },
  { 0, 3163 /* stey */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3163 /* stey */, MCK_FP32, 1 /* 0 */ },
  { Feature_FeatureHighWord, 3168 /* stfh */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureHighWord, 3168 /* stfh */, MCK_GRH32, 1 /* 0 */ },
  { 0, 3173 /* stg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3173 /* stg */, MCK_GR64, 1 /* 0 */ },
  { 0, 3177 /* stgrl */, MCK_GR64, 1 /* 0 */ },
  { 0, 3177 /* stgrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 3183 /* sth */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 3183 /* sth */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureHighWord, 3187 /* sthh */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureHighWord, 3187 /* sthh */, MCK_GRH32, 1 /* 0 */ },
  { 0, 3192 /* sthrl */, MCK_GR32, 1 /* 0 */ },
  { 0, 3192 /* sthrl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 3198 /* sthy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3198 /* sthy */, MCK_GR32, 1 /* 0 */ },
  { 0, 3203 /* stmg */, MCK_BDAddr64Disp20, 4 /* 2 */ },
  { 0, 3203 /* stmg */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3208 /* stoc */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3208 /* stoc */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3213 /* stoce */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3213 /* stoce */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3219 /* stocg */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3219 /* stocg */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3225 /* stocge */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3225 /* stocge */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3232 /* stocgh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3232 /* stocgh */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3239 /* stocghe */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3239 /* stocghe */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3247 /* stocgl */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3247 /* stocgl */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3254 /* stocgle */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3254 /* stocgle */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3262 /* stocglh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3262 /* stocglh */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3270 /* stocgne */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3270 /* stocgne */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3278 /* stocgnh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3278 /* stocgnh */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3286 /* stocgnhe */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3286 /* stocgnhe */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3295 /* stocgnl */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3295 /* stocgnl */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3303 /* stocgnle */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3303 /* stocgnle */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3312 /* stocgnlh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3312 /* stocgnlh */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3321 /* stocgno */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3321 /* stocgno */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3329 /* stocgo */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3329 /* stocgo */, MCK_GR64, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3336 /* stoch */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3336 /* stoch */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3342 /* stoche */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3342 /* stoche */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3349 /* stocl */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3349 /* stocl */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3355 /* stocle */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3355 /* stocle */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3362 /* stoclh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3362 /* stoclh */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3369 /* stocne */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3369 /* stocne */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3376 /* stocnh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3376 /* stocnh */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3383 /* stocnhe */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3383 /* stocnhe */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3391 /* stocnl */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3391 /* stocnl */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3398 /* stocnle */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3398 /* stocnle */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3406 /* stocnlh */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3406 /* stocnlh */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3414 /* stocno */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3414 /* stocno */, MCK_GR32, 1 /* 0 */ },
  { Feature_FeatureLoadStoreOnCond, 3421 /* stoco */, MCK_BDAddr64Disp20, 2 /* 1 */ },
  { Feature_FeatureLoadStoreOnCond, 3421 /* stoco */, MCK_GR32, 1 /* 0 */ },
  { 0, 3427 /* strl */, MCK_GR32, 1 /* 0 */ },
  { 0, 3427 /* strl */, MCK_PCRel32, 2 /* 1 */ },
  { 0, 3432 /* strv */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3432 /* strv */, MCK_GR32, 1 /* 0 */ },
  { 0, 3437 /* strvg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3437 /* strvg */, MCK_GR64, 1 /* 0 */ },
  { 0, 3443 /* sty */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3443 /* sty */, MCK_GR32, 1 /* 0 */ },
  { 0, 3447 /* sxbr */, MCK_FP128, 3 /* 0, 1 */ },
  { 0, 3452 /* sy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3452 /* sy */, MCK_GR32, 1 /* 0 */ },
  { 0, 3455 /* tm */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 3458 /* tmhh */, MCK_GRH32, 1 /* 0 */ },
  { 0, 3463 /* tmhl */, MCK_GRH32, 1 /* 0 */ },
  { 0, 3468 /* tmlh */, MCK_GR32, 1 /* 0 */ },
  { 0, 3473 /* tmll */, MCK_GR32, 1 /* 0 */ },
  { 0, 3478 /* tmy */, MCK_BDAddr64Disp20, 1 /* 0 */ },
  { 0, 3482 /* x */, MCK_BDXAddr64Disp12, 2 /* 1 */ },
  { 0, 3482 /* x */, MCK_GR32, 1 /* 0 */ },
  { 0, 3484 /* xc */, MCK_BDAddr64Disp12, 2 /* 1 */ },
  { 0, 3484 /* xc */, MCK_BDLAddr64Disp12Len8, 1 /* 0 */ },
  { 0, 3487 /* xg */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3487 /* xg */, MCK_GR64, 1 /* 0 */ },
  { 0, 3490 /* xgr */, MCK_GR64, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 3494 /* xgrk */, MCK_GR64, 7 /* 0, 1, 2 */ },
  { 0, 3499 /* xi */, MCK_BDAddr64Disp12, 1 /* 0 */ },
  { 0, 3502 /* xihf */, MCK_GRH32, 1 /* 0 */ },
  { 0, 3507 /* xilf */, MCK_GR32, 1 /* 0 */ },
  { 0, 3512 /* xiy */, MCK_BDAddr64Disp20, 1 /* 0 */ },
  { 0, 3516 /* xr */, MCK_GR32, 3 /* 0, 1 */ },
  { Feature_FeatureDistinctOps, 3519 /* xrk */, MCK_GR32, 7 /* 0, 1, 2 */ },
  { 0, 3523 /* xy */, MCK_BDXAddr64Disp20, 2 /* 1 */ },
  { 0, 3523 /* xy */, MCK_GR32, 1 /* 0 */ },
};

SystemZAsmParser::OperandMatchResultTy SystemZAsmParser::
tryCustomParseOperand(SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                      unsigned MCK) {

  switch(MCK) {
  case MCK_ADDR128:
    return parseADDR128(Operands);
  case MCK_ADDR32:
    return parseADDR32(Operands);
  case MCK_ADDR64:
    return parseADDR64(Operands);
  case MCK_AccessReg:
    return parseAccessReg(Operands);
  case MCK_BDAddr32Disp12:
    return parseBDAddr32(Operands);
  case MCK_BDAddr32Disp20:
    return parseBDAddr32(Operands);
  case MCK_BDAddr64Disp12:
    return parseBDAddr64(Operands);
  case MCK_BDAddr64Disp20:
    return parseBDAddr64(Operands);
  case MCK_BDLAddr64Disp12Len8:
    return parseBDLAddr64(Operands);
  case MCK_BDXAddr64Disp12:
    return parseBDXAddr64(Operands);
  case MCK_BDXAddr64Disp20:
    return parseBDXAddr64(Operands);
  case MCK_FP128:
    return parseFP128(Operands);
  case MCK_FP32:
    return parseFP32(Operands);
  case MCK_FP64:
    return parseFP64(Operands);
  case MCK_GR128:
    return parseGR128(Operands);
  case MCK_GR32:
    return parseGR32(Operands);
  case MCK_GR64:
    return parseGR64(Operands);
  case MCK_GRH32:
    return parseGRH32(Operands);
  case MCK_GRX32:
    return parseGRX32(Operands);
  case MCK_PCRel16:
    return parsePCRel16(Operands);
  case MCK_PCRel32:
    return parsePCRel32(Operands);
  default:
    return MatchOperand_NoMatch;
  }
  return MatchOperand_NoMatch;
}

SystemZAsmParser::OperandMatchResultTy SystemZAsmParser::
MatchOperandParserImpl(SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                       StringRef Mnemonic) {
  // Get the current feature set.
  unsigned AvailableFeatures = getAvailableFeatures();

  // Get the next operand index.
  unsigned NextOpNum = Operands.size()-1;
  // Search the table.
  std::pair<const OperandMatchEntry*, const OperandMatchEntry*> MnemonicRange =
    std::equal_range(OperandMatchTable, OperandMatchTable+1035, Mnemonic,
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


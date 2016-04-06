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

  Match_AddSubRegExtendLarge,
  Match_AddSubRegExtendSmall,
  Match_AddSubRegShift32,
  Match_AddSubRegShift64,
  Match_AddSubSecondSource,
  Match_CVTFixedPos32,
  Match_CVTFixedPos64,
  Match_CondCode,
  Match_FPImm,
  Match_FPZero,
  Match_Label,
  Match_Lane1,
  Match_LoadStoreExtend32_1,
  Match_LoadStoreExtend32_16,
  Match_LoadStoreExtend32_2,
  Match_LoadStoreExtend32_4,
  Match_LoadStoreExtend32_8,
  Match_LoadStoreExtend64_1,
  Match_LoadStoreExtend64_16,
  Match_LoadStoreExtend64_2,
  Match_LoadStoreExtend64_4,
  Match_LoadStoreExtend64_8,
  Match_LoadStoreSImm7_16,
  Match_LoadStoreSImm7_4,
  Match_LoadStoreSImm7_8,
  Match_LoadStoreSImm9,
  Match_LoadStoreUImm12_1,
  Match_LoadStoreUImm12_16,
  Match_LoadStoreUImm12_2,
  Match_LoadStoreUImm12_4,
  Match_LoadStoreUImm12_8,
  Match_LogicalSecondSource,
  Match_MOVWUImm16,
  Match_MRS,
  Match_MSR,
  Match_NamedImm_at,
  Match_NamedImm_dbarrier,
  Match_NamedImm_dc,
  Match_NamedImm_ic,
  Match_NamedImm_isb,
  Match_NamedImm_prefetch,
  Match_NamedImm_tlbi,
  Match_ShlImm16,
  Match_ShlImm32,
  Match_ShlImm64,
  Match_ShlImm8,
  Match_ShrImm16,
  Match_ShrImm32,
  Match_ShrImm64,
  Match_ShrImm8,
  Match_UImm16,
  Match_UImm3,
  Match_UImm4,
  Match_UImm5,
  Match_UImm6,
  Match_UImm7,
  Match_Width32,
  Match_Width64,
  END_OPERAND_DIAGNOSTIC_TYPES
#endif // GET_OPERAND_DIAGNOSTIC_TYPES


#ifdef GET_REGISTER_MATCHER
#undef GET_REGISTER_MATCHER

// Flags for subtarget features that participate in instruction matching.
enum SubtargetFeatureFlag {
  Feature_HasFPARMv8 = (1 << 1),
  Feature_HasNEON = (1 << 2),
  Feature_HasCrypto = (1 << 0),
  Feature_None = 0
};

static unsigned MatchRegisterName(StringRef Name) {
  switch (Name.size()) {
  default: break;
  case 2:	 // 71 strings to match.
    switch (Name[0]) {
    default: break;
    case 'b':	 // 10 strings to match.
      switch (Name[1]) {
      default: break;
      case '0':	 // 1 string to match.
        return 6;	 // "b0"
      case '1':	 // 1 string to match.
        return 7;	 // "b1"
      case '2':	 // 1 string to match.
        return 8;	 // "b2"
      case '3':	 // 1 string to match.
        return 9;	 // "b3"
      case '4':	 // 1 string to match.
        return 10;	 // "b4"
      case '5':	 // 1 string to match.
        return 11;	 // "b5"
      case '6':	 // 1 string to match.
        return 12;	 // "b6"
      case '7':	 // 1 string to match.
        return 13;	 // "b7"
      case '8':	 // 1 string to match.
        return 14;	 // "b8"
      case '9':	 // 1 string to match.
        return 15;	 // "b9"
      }
      break;
    case 'd':	 // 10 strings to match.
      switch (Name[1]) {
      default: break;
      case '0':	 // 1 string to match.
        return 38;	 // "d0"
      case '1':	 // 1 string to match.
        return 39;	 // "d1"
      case '2':	 // 1 string to match.
        return 40;	 // "d2"
      case '3':	 // 1 string to match.
        return 41;	 // "d3"
      case '4':	 // 1 string to match.
        return 42;	 // "d4"
      case '5':	 // 1 string to match.
        return 43;	 // "d5"
      case '6':	 // 1 string to match.
        return 44;	 // "d6"
      case '7':	 // 1 string to match.
        return 45;	 // "d7"
      case '8':	 // 1 string to match.
        return 46;	 // "d8"
      case '9':	 // 1 string to match.
        return 47;	 // "d9"
      }
      break;
    case 'h':	 // 10 strings to match.
      switch (Name[1]) {
      default: break;
      case '0':	 // 1 string to match.
        return 70;	 // "h0"
      case '1':	 // 1 string to match.
        return 71;	 // "h1"
      case '2':	 // 1 string to match.
        return 72;	 // "h2"
      case '3':	 // 1 string to match.
        return 73;	 // "h3"
      case '4':	 // 1 string to match.
        return 74;	 // "h4"
      case '5':	 // 1 string to match.
        return 75;	 // "h5"
      case '6':	 // 1 string to match.
        return 76;	 // "h6"
      case '7':	 // 1 string to match.
        return 77;	 // "h7"
      case '8':	 // 1 string to match.
        return 78;	 // "h8"
      case '9':	 // 1 string to match.
        return 79;	 // "h9"
      }
      break;
    case 'q':	 // 10 strings to match.
      switch (Name[1]) {
      default: break;
      case '0':	 // 1 string to match.
        return 102;	 // "q0"
      case '1':	 // 1 string to match.
        return 103;	 // "q1"
      case '2':	 // 1 string to match.
        return 104;	 // "q2"
      case '3':	 // 1 string to match.
        return 105;	 // "q3"
      case '4':	 // 1 string to match.
        return 106;	 // "q4"
      case '5':	 // 1 string to match.
        return 107;	 // "q5"
      case '6':	 // 1 string to match.
        return 108;	 // "q6"
      case '7':	 // 1 string to match.
        return 109;	 // "q7"
      case '8':	 // 1 string to match.
        return 110;	 // "q8"
      case '9':	 // 1 string to match.
        return 111;	 // "q9"
      }
      break;
    case 's':	 // 11 strings to match.
      switch (Name[1]) {
      default: break;
      case '0':	 // 1 string to match.
        return 134;	 // "s0"
      case '1':	 // 1 string to match.
        return 135;	 // "s1"
      case '2':	 // 1 string to match.
        return 136;	 // "s2"
      case '3':	 // 1 string to match.
        return 137;	 // "s3"
      case '4':	 // 1 string to match.
        return 138;	 // "s4"
      case '5':	 // 1 string to match.
        return 139;	 // "s5"
      case '6':	 // 1 string to match.
        return 140;	 // "s6"
      case '7':	 // 1 string to match.
        return 141;	 // "s7"
      case '8':	 // 1 string to match.
        return 142;	 // "s8"
      case '9':	 // 1 string to match.
        return 143;	 // "s9"
      case 'p':	 // 1 string to match.
        return 4;	 // "sp"
      }
      break;
    case 'w':	 // 10 strings to match.
      switch (Name[1]) {
      default: break;
      case '0':	 // 1 string to match.
        return 166;	 // "w0"
      case '1':	 // 1 string to match.
        return 167;	 // "w1"
      case '2':	 // 1 string to match.
        return 168;	 // "w2"
      case '3':	 // 1 string to match.
        return 169;	 // "w3"
      case '4':	 // 1 string to match.
        return 170;	 // "w4"
      case '5':	 // 1 string to match.
        return 171;	 // "w5"
      case '6':	 // 1 string to match.
        return 172;	 // "w6"
      case '7':	 // 1 string to match.
        return 173;	 // "w7"
      case '8':	 // 1 string to match.
        return 174;	 // "w8"
      case '9':	 // 1 string to match.
        return 175;	 // "w9"
      }
      break;
    case 'x':	 // 10 strings to match.
      switch (Name[1]) {
      default: break;
      case '0':	 // 1 string to match.
        return 197;	 // "x0"
      case '1':	 // 1 string to match.
        return 198;	 // "x1"
      case '2':	 // 1 string to match.
        return 199;	 // "x2"
      case '3':	 // 1 string to match.
        return 200;	 // "x3"
      case '4':	 // 1 string to match.
        return 201;	 // "x4"
      case '5':	 // 1 string to match.
        return 202;	 // "x5"
      case '6':	 // 1 string to match.
        return 203;	 // "x6"
      case '7':	 // 1 string to match.
        return 204;	 // "x7"
      case '8':	 // 1 string to match.
        return 205;	 // "x8"
      case '9':	 // 1 string to match.
        return 206;	 // "x9"
      }
      break;
    }
    break;
  case 3:	 // 155 strings to match.
    switch (Name[0]) {
    default: break;
    case 'b':	 // 22 strings to match.
      switch (Name[1]) {
      default: break;
      case '1':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 16;	 // "b10"
        case '1':	 // 1 string to match.
          return 17;	 // "b11"
        case '2':	 // 1 string to match.
          return 18;	 // "b12"
        case '3':	 // 1 string to match.
          return 19;	 // "b13"
        case '4':	 // 1 string to match.
          return 20;	 // "b14"
        case '5':	 // 1 string to match.
          return 21;	 // "b15"
        case '6':	 // 1 string to match.
          return 22;	 // "b16"
        case '7':	 // 1 string to match.
          return 23;	 // "b17"
        case '8':	 // 1 string to match.
          return 24;	 // "b18"
        case '9':	 // 1 string to match.
          return 25;	 // "b19"
        }
        break;
      case '2':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 26;	 // "b20"
        case '1':	 // 1 string to match.
          return 27;	 // "b21"
        case '2':	 // 1 string to match.
          return 28;	 // "b22"
        case '3':	 // 1 string to match.
          return 29;	 // "b23"
        case '4':	 // 1 string to match.
          return 30;	 // "b24"
        case '5':	 // 1 string to match.
          return 31;	 // "b25"
        case '6':	 // 1 string to match.
          return 32;	 // "b26"
        case '7':	 // 1 string to match.
          return 33;	 // "b27"
        case '8':	 // 1 string to match.
          return 34;	 // "b28"
        case '9':	 // 1 string to match.
          return 35;	 // "b29"
        }
        break;
      case '3':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 36;	 // "b30"
        case '1':	 // 1 string to match.
          return 37;	 // "b31"
        }
        break;
      }
      break;
    case 'd':	 // 22 strings to match.
      switch (Name[1]) {
      default: break;
      case '1':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 48;	 // "d10"
        case '1':	 // 1 string to match.
          return 49;	 // "d11"
        case '2':	 // 1 string to match.
          return 50;	 // "d12"
        case '3':	 // 1 string to match.
          return 51;	 // "d13"
        case '4':	 // 1 string to match.
          return 52;	 // "d14"
        case '5':	 // 1 string to match.
          return 53;	 // "d15"
        case '6':	 // 1 string to match.
          return 54;	 // "d16"
        case '7':	 // 1 string to match.
          return 55;	 // "d17"
        case '8':	 // 1 string to match.
          return 56;	 // "d18"
        case '9':	 // 1 string to match.
          return 57;	 // "d19"
        }
        break;
      case '2':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 58;	 // "d20"
        case '1':	 // 1 string to match.
          return 59;	 // "d21"
        case '2':	 // 1 string to match.
          return 60;	 // "d22"
        case '3':	 // 1 string to match.
          return 61;	 // "d23"
        case '4':	 // 1 string to match.
          return 62;	 // "d24"
        case '5':	 // 1 string to match.
          return 63;	 // "d25"
        case '6':	 // 1 string to match.
          return 64;	 // "d26"
        case '7':	 // 1 string to match.
          return 65;	 // "d27"
        case '8':	 // 1 string to match.
          return 66;	 // "d28"
        case '9':	 // 1 string to match.
          return 67;	 // "d29"
        }
        break;
      case '3':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 68;	 // "d30"
        case '1':	 // 1 string to match.
          return 69;	 // "d31"
        }
        break;
      }
      break;
    case 'h':	 // 22 strings to match.
      switch (Name[1]) {
      default: break;
      case '1':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 80;	 // "h10"
        case '1':	 // 1 string to match.
          return 81;	 // "h11"
        case '2':	 // 1 string to match.
          return 82;	 // "h12"
        case '3':	 // 1 string to match.
          return 83;	 // "h13"
        case '4':	 // 1 string to match.
          return 84;	 // "h14"
        case '5':	 // 1 string to match.
          return 85;	 // "h15"
        case '6':	 // 1 string to match.
          return 86;	 // "h16"
        case '7':	 // 1 string to match.
          return 87;	 // "h17"
        case '8':	 // 1 string to match.
          return 88;	 // "h18"
        case '9':	 // 1 string to match.
          return 89;	 // "h19"
        }
        break;
      case '2':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 90;	 // "h20"
        case '1':	 // 1 string to match.
          return 91;	 // "h21"
        case '2':	 // 1 string to match.
          return 92;	 // "h22"
        case '3':	 // 1 string to match.
          return 93;	 // "h23"
        case '4':	 // 1 string to match.
          return 94;	 // "h24"
        case '5':	 // 1 string to match.
          return 95;	 // "h25"
        case '6':	 // 1 string to match.
          return 96;	 // "h26"
        case '7':	 // 1 string to match.
          return 97;	 // "h27"
        case '8':	 // 1 string to match.
          return 98;	 // "h28"
        case '9':	 // 1 string to match.
          return 99;	 // "h29"
        }
        break;
      case '3':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 100;	 // "h30"
        case '1':	 // 1 string to match.
          return 101;	 // "h31"
        }
        break;
      }
      break;
    case 'q':	 // 22 strings to match.
      switch (Name[1]) {
      default: break;
      case '1':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 112;	 // "q10"
        case '1':	 // 1 string to match.
          return 113;	 // "q11"
        case '2':	 // 1 string to match.
          return 114;	 // "q12"
        case '3':	 // 1 string to match.
          return 115;	 // "q13"
        case '4':	 // 1 string to match.
          return 116;	 // "q14"
        case '5':	 // 1 string to match.
          return 117;	 // "q15"
        case '6':	 // 1 string to match.
          return 118;	 // "q16"
        case '7':	 // 1 string to match.
          return 119;	 // "q17"
        case '8':	 // 1 string to match.
          return 120;	 // "q18"
        case '9':	 // 1 string to match.
          return 121;	 // "q19"
        }
        break;
      case '2':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 122;	 // "q20"
        case '1':	 // 1 string to match.
          return 123;	 // "q21"
        case '2':	 // 1 string to match.
          return 124;	 // "q22"
        case '3':	 // 1 string to match.
          return 125;	 // "q23"
        case '4':	 // 1 string to match.
          return 126;	 // "q24"
        case '5':	 // 1 string to match.
          return 127;	 // "q25"
        case '6':	 // 1 string to match.
          return 128;	 // "q26"
        case '7':	 // 1 string to match.
          return 129;	 // "q27"
        case '8':	 // 1 string to match.
          return 130;	 // "q28"
        case '9':	 // 1 string to match.
          return 131;	 // "q29"
        }
        break;
      case '3':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 132;	 // "q30"
        case '1':	 // 1 string to match.
          return 133;	 // "q31"
        }
        break;
      }
      break;
    case 's':	 // 22 strings to match.
      switch (Name[1]) {
      default: break;
      case '1':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 144;	 // "s10"
        case '1':	 // 1 string to match.
          return 145;	 // "s11"
        case '2':	 // 1 string to match.
          return 146;	 // "s12"
        case '3':	 // 1 string to match.
          return 147;	 // "s13"
        case '4':	 // 1 string to match.
          return 148;	 // "s14"
        case '5':	 // 1 string to match.
          return 149;	 // "s15"
        case '6':	 // 1 string to match.
          return 150;	 // "s16"
        case '7':	 // 1 string to match.
          return 151;	 // "s17"
        case '8':	 // 1 string to match.
          return 152;	 // "s18"
        case '9':	 // 1 string to match.
          return 153;	 // "s19"
        }
        break;
      case '2':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 154;	 // "s20"
        case '1':	 // 1 string to match.
          return 155;	 // "s21"
        case '2':	 // 1 string to match.
          return 156;	 // "s22"
        case '3':	 // 1 string to match.
          return 157;	 // "s23"
        case '4':	 // 1 string to match.
          return 158;	 // "s24"
        case '5':	 // 1 string to match.
          return 159;	 // "s25"
        case '6':	 // 1 string to match.
          return 160;	 // "s26"
        case '7':	 // 1 string to match.
          return 161;	 // "s27"
        case '8':	 // 1 string to match.
          return 162;	 // "s28"
        case '9':	 // 1 string to match.
          return 163;	 // "s29"
        }
        break;
      case '3':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 164;	 // "s30"
        case '1':	 // 1 string to match.
          return 165;	 // "s31"
        }
        break;
      }
      break;
    case 'w':	 // 23 strings to match.
      switch (Name[1]) {
      default: break;
      case '1':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 176;	 // "w10"
        case '1':	 // 1 string to match.
          return 177;	 // "w11"
        case '2':	 // 1 string to match.
          return 178;	 // "w12"
        case '3':	 // 1 string to match.
          return 179;	 // "w13"
        case '4':	 // 1 string to match.
          return 180;	 // "w14"
        case '5':	 // 1 string to match.
          return 181;	 // "w15"
        case '6':	 // 1 string to match.
          return 182;	 // "w16"
        case '7':	 // 1 string to match.
          return 183;	 // "w17"
        case '8':	 // 1 string to match.
          return 184;	 // "w18"
        case '9':	 // 1 string to match.
          return 185;	 // "w19"
        }
        break;
      case '2':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 186;	 // "w20"
        case '1':	 // 1 string to match.
          return 187;	 // "w21"
        case '2':	 // 1 string to match.
          return 188;	 // "w22"
        case '3':	 // 1 string to match.
          return 189;	 // "w23"
        case '4':	 // 1 string to match.
          return 190;	 // "w24"
        case '5':	 // 1 string to match.
          return 191;	 // "w25"
        case '6':	 // 1 string to match.
          return 192;	 // "w26"
        case '7':	 // 1 string to match.
          return 193;	 // "w27"
        case '8':	 // 1 string to match.
          return 194;	 // "w28"
        case '9':	 // 1 string to match.
          return 195;	 // "w29"
        }
        break;
      case '3':	 // 1 string to match.
        if (Name[2] != '0')
          break;
        return 196;	 // "w30"
      case 's':	 // 1 string to match.
        if (Name[2] != 'p')
          break;
        return 2;	 // "wsp"
      case 'z':	 // 1 string to match.
        if (Name[2] != 'r')
          break;
        return 3;	 // "wzr"
      }
      break;
    case 'x':	 // 22 strings to match.
      switch (Name[1]) {
      default: break;
      case '1':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 207;	 // "x10"
        case '1':	 // 1 string to match.
          return 208;	 // "x11"
        case '2':	 // 1 string to match.
          return 209;	 // "x12"
        case '3':	 // 1 string to match.
          return 210;	 // "x13"
        case '4':	 // 1 string to match.
          return 211;	 // "x14"
        case '5':	 // 1 string to match.
          return 212;	 // "x15"
        case '6':	 // 1 string to match.
          return 213;	 // "x16"
        case '7':	 // 1 string to match.
          return 214;	 // "x17"
        case '8':	 // 1 string to match.
          return 215;	 // "x18"
        case '9':	 // 1 string to match.
          return 216;	 // "x19"
        }
        break;
      case '2':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 217;	 // "x20"
        case '1':	 // 1 string to match.
          return 218;	 // "x21"
        case '2':	 // 1 string to match.
          return 219;	 // "x22"
        case '3':	 // 1 string to match.
          return 220;	 // "x23"
        case '4':	 // 1 string to match.
          return 221;	 // "x24"
        case '5':	 // 1 string to match.
          return 222;	 // "x25"
        case '6':	 // 1 string to match.
          return 223;	 // "x26"
        case '7':	 // 1 string to match.
          return 224;	 // "x27"
        case '8':	 // 1 string to match.
          return 225;	 // "x28"
        case '9':	 // 1 string to match.
          return 226;	 // "x29"
        }
        break;
      case '3':	 // 1 string to match.
        if (Name[2] != '0')
          break;
        return 227;	 // "x30"
      case 'z':	 // 1 string to match.
        if (Name[2] != 'r')
          break;
        return 5;	 // "xzr"
      }
      break;
    }
    break;
  case 4:	 // 1 string to match.
    if (memcmp(Name.data()+0, "nzcv", 4))
      break;
    return 1;	 // "nzcv"
  }
  return 0;
}

#endif // GET_REGISTER_MATCHER


#ifdef GET_SUBTARGET_FEATURE_NAME
#undef GET_SUBTARGET_FEATURE_NAME

// User-level names for subtarget features that participate in
// instruction matching.
static const char *getSubtargetFeatureName(unsigned Val) {
  switch(Val) {
  case Feature_HasFPARMv8: return "fp-armv8";
  case Feature_HasNEON: return "neon";
  case Feature_HasCrypto: return "crypto";
  default: return "(unknown)";
  }
}

#endif // GET_SUBTARGET_FEATURE_NAME


#ifdef GET_MATCHER_IMPLEMENTATION
#undef GET_MATCHER_IMPLEMENTATION

static void applyMnemonicAliases(StringRef &Mnemonic, unsigned Features, unsigned VariantID) {
  switch (VariantID) {
    case 0:
      switch (Mnemonic.size()) {
      default: break;
      case 4:	 // 4 strings to match.
        switch (Mnemonic[0]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+1, "srv", 3))
            break;
          Mnemonic = "asr";	 // "asrv"
          return;
        case 'l':	 // 2 strings to match.
          if (Mnemonic[1] != 's')
            break;
          switch (Mnemonic[2]) {
          default: break;
          case 'l':	 // 1 string to match.
            if (Mnemonic[3] != 'v')
              break;
            Mnemonic = "lsl";	 // "lslv"
            return;
          case 'r':	 // 1 string to match.
            if (Mnemonic[3] != 'v')
              break;
            Mnemonic = "lsr";	 // "lsrv"
            return;
          }
          break;
        case 'r':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+1, "orv", 3))
            break;
          Mnemonic = "ror";	 // "rorv"
          return;
        }
        break;
      }
    break;
  }
  switch (Mnemonic.size()) {
  default: break;
  case 4:	 // 4 strings to match.
    switch (Mnemonic[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Mnemonic.data()+1, "srv", 3))
        break;
      Mnemonic = "asr";	 // "asrv"
      return;
    case 'l':	 // 2 strings to match.
      if (Mnemonic[1] != 's')
        break;
      switch (Mnemonic[2]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (Mnemonic[3] != 'v')
          break;
        Mnemonic = "lsl";	 // "lslv"
        return;
      case 'r':	 // 1 string to match.
        if (Mnemonic[3] != 'v')
          break;
        Mnemonic = "lsr";	 // "lsrv"
        return;
      }
      break;
    case 'r':	 // 1 string to match.
      if (memcmp(Mnemonic.data()+1, "orv", 3))
        break;
      Mnemonic = "ror";	 // "rorv"
      return;
    }
    break;
  }
}

namespace {
enum OperatorConversionKind {
  CVT_Done,
  CVT_Reg,
  CVT_Tied,
  CVT_95_Reg,
  CVT_imm_0,
  CVT_95_addImmWithLSLOperands,
  CVT_95_addShiftOperands,
  CVT_95_addRegExtendOperands,
  CVT_95_addLabelOperands_LT_21_44__32_1_GT_,
  CVT_95_addLabelOperands_LT_21_44__32_4096_GT_,
  CVT_95_addLogicalImmOperands_LT_32_GT_,
  CVT_95_addLogicalImmOperands_LT_64_GT_,
  CVT_95_addImmOperands,
  CVT_95_addLabelOperands_LT_26_44__32_4_GT_,
  CVT_95_addCondCodeOperands,
  CVT_95_addLabelOperands_LT_19_44__32_4_GT_,
  CVT_95_addBFILSBOperands_LT_32_GT_,
  CVT_95_addBFIWidthOperands,
  CVT_95_addBFILSBOperands_LT_64_GT_,
  CVT_95_addBFXWidthOperands,
  CVT_95_addNeonMovImmShiftLSLOperands,
  CVT_95_addNeonMovImmShiftLSLHOperands,
  CVT_95_addInvCondCodeOperands,
  CVT_imm_15,
  CVT_regWZR,
  CVT_regXZR,
  CVT_95_addFPZeroOperands,
  CVT_95_addCVTFixedPosOperands,
  CVT_95_addFMOVImmOperands,
  CVT_95_addVectorListOperands,
  CVT_95_addRegOperands,
  CVT_95_addSImm7ScaledOperands_LT_4_GT_,
  CVT_95_addSImm7ScaledOperands_LT_8_GT_,
  CVT_95_addSImm7ScaledOperands_LT_16_GT_,
  CVT_95_addSImmOperands_LT_9_GT_,
  CVT_imm_2,
  CVT_95_addOffsetUImm12Operands_LT_4_GT_,
  CVT_95_addOffsetUImm12Operands_LT_8_GT_,
  CVT_95_addOffsetUImm12Operands_LT_1_GT_,
  CVT_95_addOffsetUImm12Operands_LT_2_GT_,
  CVT_95_addOffsetUImm12Operands_LT_16_GT_,
  CVT_95_addAddrRegExtendOperands_LT_4_GT_,
  CVT_95_addAddrRegExtendOperands_LT_8_GT_,
  CVT_95_addAddrRegExtendOperands_LT_1_GT_,
  CVT_95_addAddrRegExtendOperands_LT_2_GT_,
  CVT_95_addAddrRegExtendOperands_LT_16_GT_,
  CVT_95_addMoveWideMovAliasOperands_LT_32_44__32_A64Imms_COLON__COLON_isOnlyMOVNImm_GT_,
  CVT_95_addMoveWideMovAliasOperands_LT_32_44__32_A64Imms_COLON__COLON_isMOVZImm_GT_,
  CVT_95_addMoveWideMovAliasOperands_LT_64_44__32_A64Imms_COLON__COLON_isOnlyMOVNImm_GT_,
  CVT_95_addMoveWideMovAliasOperands_LT_64_44__32_A64Imms_COLON__COLON_isMOVZImm_GT_,
  CVT_95_addNeonUImm64MaskOperands,
  CVT_95_addNeonMovImmShiftMSLOperands,
  CVT_95_addMoveWideImmOperands,
  CVT_95_addMRSOperands,
  CVT_95_addMSRWithRegOperands,
  CVT_95_addMSRPStateOperands,
  CVT_regX30,
  CVT_imm_4,
  CVT_imm_5,
  CVT_95_addLabelOperands_LT_14_44__32_4_GT_,
  CVT_imm_3,
  CVT_imm_1,
  CVT_NUM_CONVERTERS
};

enum InstructionConversionKind {
  Convert__Reg1_0__Reg1_1,
  Convert__Reg1_0__Reg1_2,
  Convert__Reg1_0__Reg1_1__Reg1_2,
  Convert__Reg1_0__Reg1_1__Reg1_2__imm_0,
  Convert__Reg1_0__Reg1_1__AddSubImmLSL01_2,
  Convert__Reg1_0__Reg1_1__AddSubImmLSL121_2,
  Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__SXTB1_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__SXTH1_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__SXTW1_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__SXTX1_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__UXTB1_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__UXTH1_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__UXTW1_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__UXTX1_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3,
  Convert__Reg1_0__Reg1_2__Reg1_4,
  Convert__Reg1_0__Tie0__Reg1_2__Reg1_4,
  Convert__Reg1_0__Label21_11_1,
  Convert__Reg1_0__AdrpLabel1_1,
  Convert__Reg1_0__Tie0__Reg1_2,
  Convert__Reg1_0__Reg1_1__LogicalImm321_2,
  Convert__Reg1_0__Reg1_1__LogicalImm641_2,
  Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi321_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi641_3,
  Convert__Reg1_0__Reg1_1__UImm51_2,
  Convert__Reg1_0__Reg1_1__UImm61_2,
  Convert__NamedImmat1_0__Reg1_1,
  Convert__Label26_41_0,
  Convert__CondCode1_1__Label19_41_2,
  Convert__Reg1_0__Tie0__Reg1_1__BFI32LSB1_2__BFI32Width1_3,
  Convert__Reg1_0__Tie0__Reg1_1__BFI64LSB1_2__BFI64Width1_3,
  Convert__Reg1_0__Tie0__Reg1_1__UImm51_2__UImm51_3,
  Convert__Reg1_0__Tie0__Reg1_1__UImm61_2__UImm61_3,
  Convert__Reg1_0__Tie0__Reg1_1__UImm51_2__BFX32Width1_3,
  Convert__Reg1_0__Tie0__Reg1_1__UImm61_2__BFX64Width1_3,
  Convert__Reg1_0__Tie0__UImm81_2__imm_0,
  Convert__Reg1_0__Tie0__UImm81_2__NeonMovImmShiftLSL1_3,
  Convert__Reg1_0__Tie0__UImm81_2__NeonMovImmShiftLSLH1_3,
  Convert__Reg1_0,
  Convert__UImm161_0,
  Convert__Reg1_0__Label19_41_1,
  Convert__Reg1_0__Reg1_1__UImm41_2__CondCodeOp1_3,
  Convert__Reg1_0__UImm51_1__UImm41_2__CondCodeOp1_3,
  Convert__Reg1_0__Reg1_1__Reg1_1__InvCondCodeOp1_2,
  Convert__imm_15,
  Convert__UImm41_0,
  Convert__Reg1_0__Reg1_1__UImm01_2,
  Convert__Reg1_0__Reg1_2__UImm01_4,
  Convert__Reg1_0__Reg1_4__Reg1_2,
  Convert__Reg1_0__Reg1_1__imm_0,
  Convert__Reg1_0__AddSubImmLSL01_1,
  Convert__Reg1_0__AddSubImmLSL121_1,
  Convert__Reg1_0__Reg1_1__ShiftASRi321_2,
  Convert__Reg1_0__Reg1_1__ShiftLSLi321_2,
  Convert__Reg1_0__Reg1_1__ShiftLSRi321_2,
  Convert__Reg1_0__Reg1_1__RegExtendLSL1_2,
  Convert__Reg1_0__Reg1_1__SXTB1_2,
  Convert__Reg1_0__Reg1_1__SXTH1_2,
  Convert__Reg1_0__Reg1_1__SXTW1_2,
  Convert__Reg1_0__Reg1_1__SXTX1_2,
  Convert__Reg1_0__Reg1_1__UXTB1_2,
  Convert__Reg1_0__Reg1_1__UXTH1_2,
  Convert__Reg1_0__Reg1_1__UXTW1_2,
  Convert__Reg1_0__Reg1_1__UXTX1_2,
  Convert__Reg1_0__Reg1_1__ShiftASRi641_2,
  Convert__Reg1_0__Reg1_1__ShiftLSLi641_2,
  Convert__Reg1_0__Reg1_1__ShiftLSRi641_2,
  Convert__Reg1_0__Reg1_1__Reg1_2__CondCodeOp1_3,
  Convert__Reg1_0__regWZR__regWZR__InvCondCodeOp1_1,
  Convert__Reg1_0__regXZR__regXZR__InvCondCodeOp1_1,
  Convert__NamedImmdc1_0__Reg1_1,
  Convert__imm_0,
  Convert__NamedImmdbarrier1_0,
  Convert_NoOperands,
  Convert__Reg1_0__Reg1_1__UImm41_4,
  Convert__Reg1_0__Reg1_1__UImm31_4,
  Convert__Reg1_0__Reg1_1__UImm21_4,
  Convert__Reg1_0__Reg1_1__UImm11_4,
  Convert__Reg1_0__Reg1_2__UImm21_5,
  Convert__Reg1_0__Reg1_2__UImm31_5,
  Convert__Reg1_0__Reg1_2__UImm41_5,
  Convert__Reg1_0__Reg1_2__UImm11_5,
  Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_6,
  Convert__Reg1_0__Reg1_2__Reg1_4__UImm41_6,
  Convert__Reg1_0__Reg1_1__Reg1_2__UImm51_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__UImm61_3,
  Convert__Reg1_0__Reg1_1__FPZero1_2,
  Convert__Reg1_0__Reg1_2__FPZero1_4,
  Convert__Reg1_0__FPZero1_1,
  Convert__Reg1_0__Reg1_1__CVTFixedPos321_2,
  Convert__Reg1_0__Reg1_1__CVTFixedPos641_2,
  Convert__Reg1_0__Reg1_1__ShrImm321_2,
  Convert__Reg1_0__Reg1_1__ShrImm641_2,
  Convert__Reg1_0__Reg1_2__ShrImm321_4,
  Convert__Reg1_0__Reg1_2__ShrImm641_4,
  Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3,
  Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm21_5,
  Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm11_5,
  Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7,
  Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm11_7,
  Convert__Reg1_0__FMOVImm1_1,
  Convert__Reg1_0__FMOVImm1_2,
  Convert__Reg1_0__Reg1_1__Lane11_4,
  Convert__Reg1_0__Reg1_5__Lane11_3,
  Convert__Reg1_0__Reg1_1__Reg1_2__UImm21_5,
  Convert__Reg1_0__Reg1_1__Reg1_2__UImm11_5,
  Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7,
  Convert__Reg1_0__Reg1_2__Reg1_4__UImm11_7,
  Convert__UImm71_0,
  Convert__NamedImmic1_0,
  Convert__NamedImmic1_0__Reg1_1,
  Convert__Reg1_0__Tie0__Reg1_5__UImm41_3,
  Convert__Reg1_0__Tie0__Reg1_5__UImm11_3,
  Convert__Reg1_0__Tie0__Reg1_5__UImm31_3,
  Convert__Reg1_0__Tie0__Reg1_5__UImm21_3,
  Convert__Reg1_0__Tie0__Reg1_5__UImm41_3__UImm41_8,
  Convert__Reg1_0__Tie0__Reg1_5__UImm11_3__UImm11_8,
  Convert__Reg1_0__Tie0__Reg1_5__UImm31_3__UImm31_8,
  Convert__Reg1_0__Tie0__Reg1_5__UImm21_3__UImm21_8,
  Convert__NamedImmisb1_0,
  Convert__VOne16B11_0__Reg1_2,
  Convert__VOne1D11_0__Reg1_2,
  Convert__VOne2D11_0__Reg1_2,
  Convert__VOne2S11_0__Reg1_2,
  Convert__VOne4H11_0__Reg1_2,
  Convert__VOne4S11_0__Reg1_2,
  Convert__VOne8B11_0__Reg1_2,
  Convert__VOne8H11_0__Reg1_2,
  Convert__VPair16B21_0__Reg1_2,
  Convert__VPair1D21_0__Reg1_2,
  Convert__VPair2D21_0__Reg1_2,
  Convert__VPair2S21_0__Reg1_2,
  Convert__VPair4H21_0__Reg1_2,
  Convert__VPair4S21_0__Reg1_2,
  Convert__VPair8B21_0__Reg1_2,
  Convert__VPair8H21_0__Reg1_2,
  Convert__VQuad16B41_0__Reg1_2,
  Convert__VQuad1D41_0__Reg1_2,
  Convert__VQuad2D41_0__Reg1_2,
  Convert__VQuad2S41_0__Reg1_2,
  Convert__VQuad4H41_0__Reg1_2,
  Convert__VQuad4S41_0__Reg1_2,
  Convert__VQuad8B41_0__Reg1_2,
  Convert__VQuad8H41_0__Reg1_2,
  Convert__VTriple16B31_0__Reg1_2,
  Convert__VTriple1D31_0__Reg1_2,
  Convert__VTriple2D31_0__Reg1_2,
  Convert__VTriple2S31_0__Reg1_2,
  Convert__VTriple4H31_0__Reg1_2,
  Convert__VTriple4S31_0__Reg1_2,
  Convert__VTriple8B31_0__Reg1_2,
  Convert__VTriple8H31_0__Reg1_2,
  Convert__VOne16B11_0__Reg1_2__Tie1__Reg1_4,
  Convert__VOne16B11_0__Reg1_2__Tie1__Exact161_4,
  Convert__VOne1D11_0__Reg1_2__Tie1__Reg1_4,
  Convert__VOne1D11_0__Reg1_2__Tie1__Exact81_4,
  Convert__VOne2D11_0__Reg1_2__Tie1__Reg1_4,
  Convert__VOne2D11_0__Reg1_2__Tie1__Exact161_4,
  Convert__VOne2S11_0__Reg1_2__Tie1__Reg1_4,
  Convert__VOne2S11_0__Reg1_2__Tie1__Exact81_4,
  Convert__VOne4H11_0__Reg1_2__Tie1__Reg1_4,
  Convert__VOne4H11_0__Reg1_2__Tie1__Exact81_4,
  Convert__VOne4S11_0__Reg1_2__Tie1__Reg1_4,
  Convert__VOne4S11_0__Reg1_2__Tie1__Exact161_4,
  Convert__VOne8B11_0__Reg1_2__Tie1__Reg1_4,
  Convert__VOne8B11_0__Reg1_2__Tie1__Exact81_4,
  Convert__VOne8H11_0__Reg1_2__Tie1__Reg1_4,
  Convert__VOne8H11_0__Reg1_2__Tie1__Exact161_4,
  Convert__VPair16B21_0__Reg1_2__Tie1__Reg1_4,
  Convert__VPair16B21_0__Reg1_2__Tie1__Exact321_4,
  Convert__VPair1D21_0__Reg1_2__Tie1__Reg1_4,
  Convert__VPair1D21_0__Reg1_2__Tie1__Exact161_4,
  Convert__VPair2D21_0__Reg1_2__Tie1__Reg1_4,
  Convert__VPair2D21_0__Reg1_2__Tie1__Exact321_4,
  Convert__VPair2S21_0__Reg1_2__Tie1__Reg1_4,
  Convert__VPair2S21_0__Reg1_2__Tie1__Exact161_4,
  Convert__VPair4H21_0__Reg1_2__Tie1__Reg1_4,
  Convert__VPair4H21_0__Reg1_2__Tie1__Exact161_4,
  Convert__VPair4S21_0__Reg1_2__Tie1__Reg1_4,
  Convert__VPair4S21_0__Reg1_2__Tie1__Exact321_4,
  Convert__VPair8B21_0__Reg1_2__Tie1__Reg1_4,
  Convert__VPair8B21_0__Reg1_2__Tie1__Exact161_4,
  Convert__VPair8H21_0__Reg1_2__Tie1__Reg1_4,
  Convert__VPair8H21_0__Reg1_2__Tie1__Exact321_4,
  Convert__VQuad16B41_0__Reg1_2__Tie1__Reg1_4,
  Convert__VQuad16B41_0__Reg1_2__Tie1__Exact641_4,
  Convert__VQuad1D41_0__Reg1_2__Tie1__Reg1_4,
  Convert__VQuad1D41_0__Reg1_2__Tie1__Exact321_4,
  Convert__VQuad2D41_0__Reg1_2__Tie1__Reg1_4,
  Convert__VQuad2D41_0__Reg1_2__Tie1__Exact641_4,
  Convert__VQuad2S41_0__Reg1_2__Tie1__Reg1_4,
  Convert__VQuad2S41_0__Reg1_2__Tie1__Exact321_4,
  Convert__VQuad4H41_0__Reg1_2__Tie1__Reg1_4,
  Convert__VQuad4H41_0__Reg1_2__Tie1__Exact321_4,
  Convert__VQuad4S41_0__Reg1_2__Tie1__Reg1_4,
  Convert__VQuad4S41_0__Reg1_2__Tie1__Exact641_4,
  Convert__VQuad8B41_0__Reg1_2__Tie1__Reg1_4,
  Convert__VQuad8B41_0__Reg1_2__Tie1__Exact321_4,
  Convert__VQuad8H41_0__Reg1_2__Tie1__Reg1_4,
  Convert__VQuad8H41_0__Reg1_2__Tie1__Exact641_4,
  Convert__VTriple16B31_0__Reg1_2__Tie1__Reg1_4,
  Convert__VTriple16B31_0__Reg1_2__Tie1__Exact481_4,
  Convert__VTriple1D31_0__Reg1_2__Tie1__Reg1_4,
  Convert__VTriple1D31_0__Reg1_2__Tie1__Exact241_4,
  Convert__VTriple2D31_0__Reg1_2__Tie1__Reg1_4,
  Convert__VTriple2D31_0__Reg1_2__Tie1__Exact481_4,
  Convert__VTriple2S31_0__Reg1_2__Tie1__Reg1_4,
  Convert__VTriple2S31_0__Reg1_2__Tie1__Exact241_4,
  Convert__VTriple4H31_0__Reg1_2__Tie1__Reg1_4,
  Convert__VTriple4H31_0__Reg1_2__Tie1__Exact241_4,
  Convert__VTriple4S31_0__Reg1_2__Tie1__Reg1_4,
  Convert__VTriple4S31_0__Reg1_2__Tie1__Exact481_4,
  Convert__VTriple8B31_0__Reg1_2__Tie1__Reg1_4,
  Convert__VTriple8B31_0__Reg1_2__Tie1__Exact241_4,
  Convert__VTriple8H31_0__Reg1_2__Tie1__Reg1_4,
  Convert__VTriple8H31_0__Reg1_2__Tie1__Exact481_4,
  Convert__VOneB11_0__Reg1_5__Tie0__UImm41_2,
  Convert__VOneD11_0__Reg1_5__Tie0__UImm11_2,
  Convert__VOneH11_0__Reg1_5__Tie0__UImm31_2,
  Convert__VOneS11_0__Reg1_5__Tie0__UImm21_2,
  Convert__VOneB11_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm41_2,
  Convert__VOneB11_0__Reg1_5__Tie1__Exact11_7__Tie0__UImm41_2,
  Convert__VOneD11_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm11_2,
  Convert__VOneD11_0__Reg1_5__Tie1__Exact81_7__Tie0__UImm11_2,
  Convert__VOneH11_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm31_2,
  Convert__VOneH11_0__Reg1_5__Tie1__Exact21_7__Tie0__UImm31_2,
  Convert__VOneS11_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm21_2,
  Convert__VOneS11_0__Reg1_5__Tie1__Exact41_7__Tie0__UImm21_2,
  Convert__VOne16B11_0__Reg1_2__Tie1__Exact11_4,
  Convert__VOne2D11_0__Reg1_2__Tie1__Exact81_4,
  Convert__VOne2S11_0__Reg1_2__Tie1__Exact41_4,
  Convert__VOne4H11_0__Reg1_2__Tie1__Exact21_4,
  Convert__VOne4S11_0__Reg1_2__Tie1__Exact41_4,
  Convert__VOne8B11_0__Reg1_2__Tie1__Exact11_4,
  Convert__VOne8H11_0__Reg1_2__Tie1__Exact21_4,
  Convert__VPairB21_0__Reg1_5__Tie0__UImm41_2,
  Convert__VPairD21_0__Reg1_5__Tie0__UImm11_2,
  Convert__VPairH21_0__Reg1_5__Tie0__UImm31_2,
  Convert__VPairS21_0__Reg1_5__Tie0__UImm21_2,
  Convert__VPairB21_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm41_2,
  Convert__VPairB21_0__Reg1_5__Tie1__Exact21_7__Tie0__UImm41_2,
  Convert__VPairD21_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm11_2,
  Convert__VPairD21_0__Reg1_5__Tie1__Exact161_7__Tie0__UImm11_2,
  Convert__VPairH21_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm31_2,
  Convert__VPairH21_0__Reg1_5__Tie1__Exact41_7__Tie0__UImm31_2,
  Convert__VPairS21_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm21_2,
  Convert__VPairS21_0__Reg1_5__Tie1__Exact81_7__Tie0__UImm21_2,
  Convert__VPair16B21_0__Reg1_2__Tie1__Exact21_4,
  Convert__VPair2D21_0__Reg1_2__Tie1__Exact161_4,
  Convert__VPair2S21_0__Reg1_2__Tie1__Exact81_4,
  Convert__VPair4H21_0__Reg1_2__Tie1__Exact41_4,
  Convert__VPair4S21_0__Reg1_2__Tie1__Exact81_4,
  Convert__VPair8B21_0__Reg1_2__Tie1__Exact21_4,
  Convert__VPair8H21_0__Reg1_2__Tie1__Exact41_4,
  Convert__VTripleB31_0__Reg1_5__Tie0__UImm41_2,
  Convert__VTripleD31_0__Reg1_5__Tie0__UImm11_2,
  Convert__VTripleH31_0__Reg1_5__Tie0__UImm31_2,
  Convert__VTripleS31_0__Reg1_5__Tie0__UImm21_2,
  Convert__VTripleB31_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm41_2,
  Convert__VTripleB31_0__Reg1_5__Tie1__Exact31_7__Tie0__UImm41_2,
  Convert__VTripleD31_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm11_2,
  Convert__VTripleD31_0__Reg1_5__Tie1__Exact241_7__Tie0__UImm11_2,
  Convert__VTripleH31_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm31_2,
  Convert__VTripleH31_0__Reg1_5__Tie1__Exact61_7__Tie0__UImm31_2,
  Convert__VTripleS31_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm21_2,
  Convert__VTripleS31_0__Reg1_5__Tie1__Exact121_7__Tie0__UImm21_2,
  Convert__VTriple16B31_0__Reg1_2__Tie1__Exact31_4,
  Convert__VTriple2D31_0__Reg1_2__Tie1__Exact241_4,
  Convert__VTriple2S31_0__Reg1_2__Tie1__Exact121_4,
  Convert__VTriple4H31_0__Reg1_2__Tie1__Exact61_4,
  Convert__VTriple4S31_0__Reg1_2__Tie1__Exact121_4,
  Convert__VTriple8B31_0__Reg1_2__Tie1__Exact31_4,
  Convert__VTriple8H31_0__Reg1_2__Tie1__Exact61_4,
  Convert__VQuadB41_0__Reg1_5__Tie0__UImm41_2,
  Convert__VQuadD41_0__Reg1_5__Tie0__UImm11_2,
  Convert__VQuadH41_0__Reg1_5__Tie0__UImm31_2,
  Convert__VQuadS41_0__Reg1_5__Tie0__UImm21_2,
  Convert__VQuadB41_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm41_2,
  Convert__VQuadB41_0__Reg1_5__Tie1__Exact41_7__Tie0__UImm41_2,
  Convert__VQuadD41_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm11_2,
  Convert__VQuadD41_0__Reg1_5__Tie1__Exact321_7__Tie0__UImm11_2,
  Convert__VQuadH41_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm31_2,
  Convert__VQuadH41_0__Reg1_5__Tie1__Exact81_7__Tie0__UImm31_2,
  Convert__VQuadS41_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm21_2,
  Convert__VQuadS41_0__Reg1_5__Tie1__Exact161_7__Tie0__UImm21_2,
  Convert__VQuad16B41_0__Reg1_2__Tie1__Exact41_4,
  Convert__VQuad2D41_0__Reg1_2__Tie1__Exact321_4,
  Convert__VQuad2S41_0__Reg1_2__Tie1__Exact161_4,
  Convert__VQuad4H41_0__Reg1_2__Tie1__Exact81_4,
  Convert__VQuad4S41_0__Reg1_2__Tie1__Exact161_4,
  Convert__VQuad8B41_0__Reg1_2__Tie1__Exact41_4,
  Convert__VQuad8H41_0__Reg1_2__Tie1__Exact81_4,
  Convert__Reg1_0__GPR64xsp01_2,
  Convert__Reg1_0__Reg1_1__GPR64xsp01_3,
  Convert__Reg1_0__Reg1_1__Reg1_3__imm_0,
  Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled41_4,
  Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled81_4,
  Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled161_4,
  Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled41_5,
  Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled81_5,
  Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled161_5,
  Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled41_4,
  Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled81_4,
  Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled161_4,
  Convert__Reg1_0__LoadLitLabel1_1,
  Convert__Reg1_0__Reg1_2__imm_0,
  Convert__Reg1_0__Reg1_2__Tie1__SImm91_4,
  Convert__Reg1_0__Reg1_2__Reg1_3__imm_2,
  Convert__Reg1_0__Reg1_2__OffsetUImm12_41_3,
  Convert__Reg1_0__Reg1_2__OffsetUImm12_81_3,
  Convert__Reg1_0__Reg1_2__OffsetUImm12_11_3,
  Convert__Reg1_0__Reg1_2__OffsetUImm12_21_3,
  Convert__Reg1_0__Reg1_2__OffsetUImm12_161_3,
  Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Wm1_4,
  Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Xm1_4,
  Convert__Reg1_0__Reg1_2__Tie1__SImm91_3,
  Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Wm1_4,
  Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Xm1_4,
  Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Wm1_4,
  Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Xm1_4,
  Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Wm1_4,
  Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Xm1_4,
  Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_16_Wm1_4,
  Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_16_Xm1_4,
  Convert__Reg1_0__Reg1_2__SImm91_3,
  Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7,
  Convert__Reg1_0__Reg1_1__Reg1_2__regWZR,
  Convert__Reg1_0__Reg1_1__Reg1_2__regXZR,
  Convert__Reg1_0__regWZR__Reg1_1__imm_0,
  Convert__Reg1_0__MOVN32MovAlias2_1,
  Convert__Reg1_0__MOVZ32MovAlias2_1,
  Convert__Reg1_0__regWZR__LogicalImmMOV321_1,
  Convert__Reg1_0__regXZR__Reg1_1__imm_0,
  Convert__Reg1_0__MOVN64MovAlias2_1,
  Convert__Reg1_0__MOVZ64MovAlias2_1,
  Convert__Reg1_0__regXZR__LogicalImmMOV641_1,
  Convert__Reg1_0__Reg1_2__Reg1_2,
  Convert__Reg1_0__NeonUImm64Mask1_1,
  Convert__Reg1_0__UImm81_2__imm_0,
  Convert__Reg1_0__UImm81_2,
  Convert__Reg1_0__NeonUImm64Mask1_2,
  Convert__Reg1_0__UImm81_2__NeonMovImmShiftLSL1_3,
  Convert__Reg1_0__UImm81_2__NeonMovImmShiftMSL1_3,
  Convert__Reg1_0__UImm81_2__NeonMovImmShiftLSLH1_3,
  Convert__Reg1_0__Tie0__MOVK32Shiftedshift2_1,
  Convert__Reg1_0__Tie0__MOVK64Shiftedshift2_1,
  Convert__Reg1_0__MOVN32Shiftedshift2_1,
  Convert__Reg1_0__MOVN64Shiftedshift2_1,
  Convert__Reg1_0__MOVZ32Shiftedshift2_1,
  Convert__Reg1_0__MOVZ64Shiftedshift2_1,
  Convert__Reg1_0__MRS1_1,
  Convert__MSRWithReg1_0__Reg1_1,
  Convert__MSRPState1_0__UImm41_1,
  Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7,
  Convert__Reg1_0__Reg1_1__ShiftRORi321_2,
  Convert__Reg1_0__Reg1_1__ShiftRORi641_2,
  Convert__Reg1_0__regWZR__Reg1_1__ShiftASRi321_2,
  Convert__Reg1_0__regWZR__Reg1_1__ShiftLSLi321_2,
  Convert__Reg1_0__regWZR__Reg1_1__ShiftLSRi321_2,
  Convert__Reg1_0__regXZR__Reg1_1__ShiftASRi641_2,
  Convert__Reg1_0__regXZR__Reg1_1__ShiftLSLi641_2,
  Convert__Reg1_0__regXZR__Reg1_1__ShiftLSRi641_2,
  Convert__Reg1_0__regWZR__Reg1_1,
  Convert__Reg1_0__regXZR__Reg1_1,
  Convert__NamedImmprefetch1_0__LoadLitLabel1_1,
  Convert__NamedImmprefetch1_0__Reg1_2__imm_0,
  Convert__NamedImmprefetch1_0__Reg1_2__Reg1_3__imm_2,
  Convert__NamedImmprefetch1_0__Reg1_2__OffsetUImm12_81_3,
  Convert__NamedImmprefetch1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Wm1_4,
  Convert__NamedImmprefetch1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Xm1_4,
  Convert__NamedImmprefetch1_0__Reg1_2__SImm91_3,
  Convert__regX30,
  Convert__Reg1_0__Reg1_1__Reg1_1__UImm51_2,
  Convert__Reg1_0__Reg1_1__Reg1_1__UImm61_2,
  Convert__Reg1_0__Reg1_2__ShrImm161_4,
  Convert__Reg1_0__Reg1_2__ShrImm81_4,
  Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4,
  Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4,
  Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4,
  Convert__Reg1_0__Reg1_1__BFI32LSB1_2__BFI32Width1_3,
  Convert__Reg1_0__Reg1_1__BFI64LSB1_2__BFI64Width1_3,
  Convert__Reg1_0__Reg1_1__UImm51_2__UImm51_3,
  Convert__Reg1_0__Reg1_1__UImm61_2__UImm61_3,
  Convert__Reg1_0__Reg1_1__UImm51_2__BFX32Width1_3,
  Convert__Reg1_0__Reg1_1__UImm61_2__BFX64Width1_3,
  Convert__imm_4,
  Convert__imm_5,
  Convert__Reg1_0__Tie0__Reg1_1__Reg1_2,
  Convert__Reg1_0__Reg1_1__ShlImm641_2,
  Convert__Reg1_0__Reg1_2__ShlImm321_4,
  Convert__Reg1_0__Reg1_2__ShlImm161_4,
  Convert__Reg1_0__Reg1_2__ShlImm81_4,
  Convert__Reg1_0__Reg1_2__ShlImm641_4,
  Convert__Reg1_0__Reg1_2__Exact321_4,
  Convert__Reg1_0__Reg1_2__Exact161_4,
  Convert__Reg1_0__Reg1_2__Exact81_4,
  Convert__Reg1_0__Tie0__Reg1_1__ShlImm641_2,
  Convert__Reg1_0__Tie0__Reg1_2__ShlImm321_4,
  Convert__Reg1_0__Tie0__Reg1_2__ShlImm161_4,
  Convert__Reg1_0__Tie0__Reg1_2__ShlImm81_4,
  Convert__Reg1_0__Tie0__Reg1_2__ShlImm641_4,
  Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm31_5,
  Convert__Reg1_0__Reg1_1__Reg1_2__UImm31_5,
  Convert__Reg1_0__Reg1_1__ShrImm81_2,
  Convert__Reg1_0__Reg1_1__ShrImm161_2,
  Convert__Reg1_0__Reg1_1__ShlImm81_2,
  Convert__Reg1_0__Reg1_1__ShlImm161_2,
  Convert__Reg1_0__Reg1_1__ShlImm321_2,
  Convert__Reg1_0__Tie0__Reg1_1__ShrImm641_2,
  Convert__Reg1_0__Tie0__Reg1_2__ShrImm641_4,
  Convert__Reg1_2__VOne16B11_0,
  Convert__Reg1_2__VOne1D11_0,
  Convert__Reg1_2__VOne2D11_0,
  Convert__Reg1_2__VOne2S11_0,
  Convert__Reg1_2__VOne4H11_0,
  Convert__Reg1_2__VOne4S11_0,
  Convert__Reg1_2__VOne8B11_0,
  Convert__Reg1_2__VOne8H11_0,
  Convert__Reg1_2__VPair16B21_0,
  Convert__Reg1_2__VPair1D21_0,
  Convert__Reg1_2__VPair2D21_0,
  Convert__Reg1_2__VPair2S21_0,
  Convert__Reg1_2__VPair4H21_0,
  Convert__Reg1_2__VPair4S21_0,
  Convert__Reg1_2__VPair8B21_0,
  Convert__Reg1_2__VPair8H21_0,
  Convert__Reg1_2__VQuad16B41_0,
  Convert__Reg1_2__VQuad1D41_0,
  Convert__Reg1_2__VQuad2D41_0,
  Convert__Reg1_2__VQuad2S41_0,
  Convert__Reg1_2__VQuad4H41_0,
  Convert__Reg1_2__VQuad4S41_0,
  Convert__Reg1_2__VQuad8B41_0,
  Convert__Reg1_2__VQuad8H41_0,
  Convert__Reg1_2__VTriple16B31_0,
  Convert__Reg1_2__VTriple1D31_0,
  Convert__Reg1_2__VTriple2D31_0,
  Convert__Reg1_2__VTriple2S31_0,
  Convert__Reg1_2__VTriple4H31_0,
  Convert__Reg1_2__VTriple4S31_0,
  Convert__Reg1_2__VTriple8B31_0,
  Convert__Reg1_2__VTriple8H31_0,
  Convert__Reg1_2__Tie0__Reg1_4__VOne16B11_0,
  Convert__Reg1_2__Tie0__Exact161_4__VOne16B11_0,
  Convert__Reg1_2__Tie0__Reg1_4__VOne1D11_0,
  Convert__Reg1_2__Tie0__Exact81_4__VOne1D11_0,
  Convert__Reg1_2__Tie0__Reg1_4__VOne2D11_0,
  Convert__Reg1_2__Tie0__Exact161_4__VOne2D11_0,
  Convert__Reg1_2__Tie0__Reg1_4__VOne2S11_0,
  Convert__Reg1_2__Tie0__Exact81_4__VOne2S11_0,
  Convert__Reg1_2__Tie0__Reg1_4__VOne4H11_0,
  Convert__Reg1_2__Tie0__Exact81_4__VOne4H11_0,
  Convert__Reg1_2__Tie0__Reg1_4__VOne4S11_0,
  Convert__Reg1_2__Tie0__Exact161_4__VOne4S11_0,
  Convert__Reg1_2__Tie0__Reg1_4__VOne8B11_0,
  Convert__Reg1_2__Tie0__Exact81_4__VOne8B11_0,
  Convert__Reg1_2__Tie0__Reg1_4__VOne8H11_0,
  Convert__Reg1_2__Tie0__Exact161_4__VOne8H11_0,
  Convert__Reg1_2__Tie0__Reg1_4__VPair16B21_0,
  Convert__Reg1_2__Tie0__Exact321_4__VPair16B21_0,
  Convert__Reg1_2__Tie0__Reg1_4__VPair1D21_0,
  Convert__Reg1_2__Tie0__Exact161_4__VPair1D21_0,
  Convert__Reg1_2__Tie0__Reg1_4__VPair2D21_0,
  Convert__Reg1_2__Tie0__Exact321_4__VPair2D21_0,
  Convert__Reg1_2__Tie0__Reg1_4__VPair2S21_0,
  Convert__Reg1_2__Tie0__Exact161_4__VPair2S21_0,
  Convert__Reg1_2__Tie0__Reg1_4__VPair4H21_0,
  Convert__Reg1_2__Tie0__Exact161_4__VPair4H21_0,
  Convert__Reg1_2__Tie0__Reg1_4__VPair4S21_0,
  Convert__Reg1_2__Tie0__Exact321_4__VPair4S21_0,
  Convert__Reg1_2__Tie0__Reg1_4__VPair8B21_0,
  Convert__Reg1_2__Tie0__Exact161_4__VPair8B21_0,
  Convert__Reg1_2__Tie0__Reg1_4__VPair8H21_0,
  Convert__Reg1_2__Tie0__Exact321_4__VPair8H21_0,
  Convert__Reg1_2__Tie0__Reg1_4__VQuad16B41_0,
  Convert__Reg1_2__Tie0__Exact641_4__VQuad16B41_0,
  Convert__Reg1_2__Tie0__Reg1_4__VQuad1D41_0,
  Convert__Reg1_2__Tie0__Exact321_4__VQuad1D41_0,
  Convert__Reg1_2__Tie0__Reg1_4__VQuad2D41_0,
  Convert__Reg1_2__Tie0__Exact641_4__VQuad2D41_0,
  Convert__Reg1_2__Tie0__Reg1_4__VQuad2S41_0,
  Convert__Reg1_2__Tie0__Exact321_4__VQuad2S41_0,
  Convert__Reg1_2__Tie0__Reg1_4__VQuad4H41_0,
  Convert__Reg1_2__Tie0__Exact321_4__VQuad4H41_0,
  Convert__Reg1_2__Tie0__Reg1_4__VQuad4S41_0,
  Convert__Reg1_2__Tie0__Exact641_4__VQuad4S41_0,
  Convert__Reg1_2__Tie0__Reg1_4__VQuad8B41_0,
  Convert__Reg1_2__Tie0__Exact321_4__VQuad8B41_0,
  Convert__Reg1_2__Tie0__Reg1_4__VQuad8H41_0,
  Convert__Reg1_2__Tie0__Exact641_4__VQuad8H41_0,
  Convert__Reg1_2__Tie0__Reg1_4__VTriple16B31_0,
  Convert__Reg1_2__Tie0__Exact481_4__VTriple16B31_0,
  Convert__Reg1_2__Tie0__Reg1_4__VTriple1D31_0,
  Convert__Reg1_2__Tie0__Exact241_4__VTriple1D31_0,
  Convert__Reg1_2__Tie0__Reg1_4__VTriple2D31_0,
  Convert__Reg1_2__Tie0__Exact481_4__VTriple2D31_0,
  Convert__Reg1_2__Tie0__Reg1_4__VTriple2S31_0,
  Convert__Reg1_2__Tie0__Exact241_4__VTriple2S31_0,
  Convert__Reg1_2__Tie0__Reg1_4__VTriple4H31_0,
  Convert__Reg1_2__Tie0__Exact241_4__VTriple4H31_0,
  Convert__Reg1_2__Tie0__Reg1_4__VTriple4S31_0,
  Convert__Reg1_2__Tie0__Exact481_4__VTriple4S31_0,
  Convert__Reg1_2__Tie0__Reg1_4__VTriple8B31_0,
  Convert__Reg1_2__Tie0__Exact241_4__VTriple8B31_0,
  Convert__Reg1_2__Tie0__Reg1_4__VTriple8H31_0,
  Convert__Reg1_2__Tie0__Exact481_4__VTriple8H31_0,
  Convert__Reg1_5__VOneB11_0__UImm41_2,
  Convert__Reg1_5__VOneD11_0__UImm11_2,
  Convert__Reg1_5__VOneH11_0__UImm31_2,
  Convert__Reg1_5__VOneS11_0__UImm21_2,
  Convert__Reg1_5__Tie0__Reg1_7__VOneB11_0__UImm41_2,
  Convert__Reg1_5__Tie0__Exact11_7__VOneB11_0__UImm41_2,
  Convert__Reg1_5__Tie0__Reg1_7__VOneD11_0__UImm11_2,
  Convert__Reg1_5__Tie0__Exact81_7__VOneD11_0__UImm11_2,
  Convert__Reg1_5__Tie0__Reg1_7__VOneH11_0__UImm31_2,
  Convert__Reg1_5__Tie0__Exact21_7__VOneH11_0__UImm31_2,
  Convert__Reg1_5__Tie0__Reg1_7__VOneS11_0__UImm21_2,
  Convert__Reg1_5__Tie0__Exact41_7__VOneS11_0__UImm21_2,
  Convert__Reg1_5__VPairB21_0__UImm41_2,
  Convert__Reg1_5__VPairD21_0__UImm11_2,
  Convert__Reg1_5__VPairH21_0__UImm31_2,
  Convert__Reg1_5__VPairS21_0__UImm21_2,
  Convert__Reg1_5__Tie0__Reg1_7__VPairB21_0__UImm41_2,
  Convert__Reg1_5__Tie0__Exact21_7__VPairB21_0__UImm41_2,
  Convert__Reg1_5__Tie0__Reg1_7__VPairD21_0__UImm11_2,
  Convert__Reg1_5__Tie0__Exact161_7__VPairD21_0__UImm11_2,
  Convert__Reg1_5__Tie0__Reg1_7__VPairH21_0__UImm31_2,
  Convert__Reg1_5__Tie0__Exact41_7__VPairH21_0__UImm31_2,
  Convert__Reg1_5__Tie0__Reg1_7__VPairS21_0__UImm21_2,
  Convert__Reg1_5__Tie0__Exact81_7__VPairS21_0__UImm21_2,
  Convert__Reg1_5__VTripleB31_0__UImm41_2,
  Convert__Reg1_5__VTripleD31_0__UImm11_2,
  Convert__Reg1_5__VTripleH31_0__UImm31_2,
  Convert__Reg1_5__VTripleS31_0__UImm21_2,
  Convert__Reg1_5__Tie0__Reg1_7__VTripleB31_0__UImm41_2,
  Convert__Reg1_5__Tie0__Exact31_7__VTripleB31_0__UImm41_2,
  Convert__Reg1_5__Tie0__Reg1_7__VTripleD31_0__UImm11_2,
  Convert__Reg1_5__Tie0__Exact241_7__VTripleD31_0__UImm11_2,
  Convert__Reg1_5__Tie0__Reg1_7__VTripleH31_0__UImm31_2,
  Convert__Reg1_5__Tie0__Exact61_7__VTripleH31_0__UImm31_2,
  Convert__Reg1_5__Tie0__Reg1_7__VTripleS31_0__UImm21_2,
  Convert__Reg1_5__Tie0__Exact121_7__VTripleS31_0__UImm21_2,
  Convert__Reg1_5__VQuadB41_0__UImm41_2,
  Convert__Reg1_5__VQuadD41_0__UImm11_2,
  Convert__Reg1_5__VQuadH41_0__UImm31_2,
  Convert__Reg1_5__VQuadS41_0__UImm21_2,
  Convert__Reg1_5__Tie0__Reg1_7__VQuadB41_0__UImm41_2,
  Convert__Reg1_5__Tie0__Exact41_7__VQuadB41_0__UImm41_2,
  Convert__Reg1_5__Tie0__Reg1_7__VQuadD41_0__UImm11_2,
  Convert__Reg1_5__Tie0__Exact321_7__VQuadD41_0__UImm11_2,
  Convert__Reg1_5__Tie0__Reg1_7__VQuadH41_0__UImm31_2,
  Convert__Reg1_5__Tie0__Exact81_7__VQuadH41_0__UImm31_2,
  Convert__Reg1_5__Tie0__Reg1_7__VQuadS41_0__UImm21_2,
  Convert__Reg1_5__Tie0__Exact161_7__VQuadS41_0__UImm21_2,
  Convert__Reg1_0__Reg1_1__Reg1_2__GPR64xsp01_4,
  Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled41_5,
  Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled81_5,
  Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled161_5,
  Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled41_4,
  Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled81_4,
  Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled161_4,
  Convert__Reg1_2__Reg1_0__Tie0__SImm91_4,
  Convert__Reg1_2__Reg1_0__Tie0__SImm91_3,
  Convert__Reg1_0__Tie0__Reg1_1,
  Convert__UImm31_0__CRx1_1__CRx1_2__UImm31_3__regXZR,
  Convert__UImm31_0__CRx1_1__CRx1_2__UImm31_3__Reg1_4,
  Convert__Reg1_0__UImm31_1__CRx1_2__CRx1_3__UImm31_4,
  Convert__Reg1_0__VOne16B11_2__Reg1_3,
  Convert__Reg1_0__VPair16B21_2__Reg1_3,
  Convert__Reg1_0__VQuad16B41_2__Reg1_3,
  Convert__Reg1_0__VTriple16B31_2__Reg1_3,
  Convert__Reg1_0__UImm51_1__Label14_41_2,
  Convert__Reg1_0__UImm61_1__Label14_41_2,
  Convert__Reg1_0__Tie0__VOne16B11_2__Reg1_3,
  Convert__Reg1_0__Tie0__VPair16B21_2__Reg1_3,
  Convert__Reg1_0__Tie0__VQuad16B41_2__Reg1_3,
  Convert__Reg1_0__Tie0__VTriple16B31_2__Reg1_3,
  Convert__NamedImmtlbi1_0,
  Convert__NamedImmtlbi1_0__Reg1_1,
  Convert__regWZR__Reg1_0__LogicalImm321_1,
  Convert__regXZR__Reg1_0__LogicalImm641_1,
  Convert__imm_2,
  Convert__imm_3,
  Convert__imm_1,
  CVT_NUM_SIGNATURES
};

} // end anonymous namespace

static const uint8_t ConversionTable[CVT_NUM_SIGNATURES][13] = {
  // Convert__Reg1_0__Reg1_1
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__imm_0
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_imm_0, 0, CVT_Done },
  // Convert__Reg1_0__Reg1_1__AddSubImmLSL01_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmWithLSLOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__AddSubImmLSL121_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmWithLSLOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addShiftOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addShiftOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addShiftOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addRegExtendOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__SXTB1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addRegExtendOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__SXTH1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addRegExtendOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__SXTW1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addRegExtendOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__SXTX1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addRegExtendOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__UXTB1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addRegExtendOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__UXTH1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addRegExtendOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__UXTW1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addRegExtendOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__UXTX1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addRegExtendOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addShiftOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addShiftOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addShiftOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_2__Reg1_4
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_Done },
  // Convert__Reg1_0__Label21_11_1
  { CVT_95_Reg, 1, CVT_95_addLabelOperands_LT_21_44__32_1_GT_, 2, CVT_Done },
  // Convert__Reg1_0__AdrpLabel1_1
  { CVT_95_Reg, 1, CVT_95_addLabelOperands_LT_21_44__32_4096_GT_, 2, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_2
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__LogicalImm321_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addLogicalImmOperands_LT_32_GT_, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__LogicalImm641_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addLogicalImmOperands_LT_64_GT_, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi321_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addShiftOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi641_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addShiftOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UImm51_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UImm61_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__NamedImmat1_0__Reg1_1
  { CVT_95_addImmOperands, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__Label26_41_0
  { CVT_95_addLabelOperands_LT_26_44__32_4_GT_, 1, CVT_Done },
  // Convert__CondCode1_1__Label19_41_2
  { CVT_95_addCondCodeOperands, 2, CVT_95_addLabelOperands_LT_19_44__32_4_GT_, 3, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1__BFI32LSB1_2__BFI32Width1_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_95_addBFILSBOperands_LT_32_GT_, 3, CVT_95_addBFIWidthOperands, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1__BFI64LSB1_2__BFI64Width1_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_95_addBFILSBOperands_LT_64_GT_, 3, CVT_95_addBFIWidthOperands, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1__UImm51_2__UImm51_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1__UImm61_2__UImm61_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1__UImm51_2__BFX32Width1_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addBFXWidthOperands, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1__UImm61_2__BFX64Width1_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addBFXWidthOperands, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__UImm81_2__imm_0
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_imm_0, 0, CVT_Done },
  // Convert__Reg1_0__Tie0__UImm81_2__NeonMovImmShiftLSL1_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_95_addNeonMovImmShiftLSLOperands, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__UImm81_2__NeonMovImmShiftLSLH1_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_95_addNeonMovImmShiftLSLHOperands, 4, CVT_Done },
  // Convert__Reg1_0
  { CVT_95_Reg, 1, CVT_Done },
  // Convert__UImm161_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Reg1_0__Label19_41_1
  { CVT_95_Reg, 1, CVT_95_addLabelOperands_LT_19_44__32_4_GT_, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UImm41_2__CondCodeOp1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 4, CVT_Done },
  // Convert__Reg1_0__UImm51_1__UImm41_2__CondCodeOp1_3
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_1__InvCondCodeOp1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 2, CVT_95_addInvCondCodeOperands, 3, CVT_Done },
  // Convert__imm_15
  { CVT_imm_15, 0, CVT_Done },
  // Convert__UImm41_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UImm01_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_2__UImm01_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_4__Reg1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 5, CVT_95_Reg, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__imm_0
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_imm_0, 0, CVT_Done },
  // Convert__Reg1_0__AddSubImmLSL01_1
  { CVT_95_Reg, 1, CVT_95_addImmWithLSLOperands, 2, CVT_Done },
  // Convert__Reg1_0__AddSubImmLSL121_1
  { CVT_95_Reg, 1, CVT_95_addImmWithLSLOperands, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShiftASRi321_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShiftLSLi321_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShiftLSRi321_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__RegExtendLSL1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addRegExtendOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__SXTB1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addRegExtendOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__SXTH1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addRegExtendOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__SXTW1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addRegExtendOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__SXTX1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addRegExtendOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UXTB1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addRegExtendOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UXTH1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addRegExtendOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UXTW1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addRegExtendOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UXTX1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addRegExtendOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShiftASRi641_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShiftLSLi641_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShiftLSRi641_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__CondCodeOp1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addCondCodeOperands, 4, CVT_Done },
  // Convert__Reg1_0__regWZR__regWZR__InvCondCodeOp1_1
  { CVT_95_Reg, 1, CVT_regWZR, 0, CVT_regWZR, 0, CVT_95_addInvCondCodeOperands, 2, CVT_Done },
  // Convert__Reg1_0__regXZR__regXZR__InvCondCodeOp1_1
  { CVT_95_Reg, 1, CVT_regXZR, 0, CVT_regXZR, 0, CVT_95_addInvCondCodeOperands, 2, CVT_Done },
  // Convert__NamedImmdc1_0__Reg1_1
  { CVT_95_addImmOperands, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__imm_0
  { CVT_imm_0, 0, CVT_Done },
  // Convert__NamedImmdbarrier1_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert_NoOperands
  { CVT_Done },
  // Convert__Reg1_0__Reg1_1__UImm41_4
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UImm31_4
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UImm21_4
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UImm11_4
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__UImm21_5
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__Reg1_0__Reg1_2__UImm31_5
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__Reg1_0__Reg1_2__UImm41_5
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__Reg1_0__Reg1_2__UImm11_5
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_6
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_95_addImmOperands, 7, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_4__UImm41_6
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_95_addImmOperands, 7, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__UImm51_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__UImm61_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__FPZero1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addFPZeroOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_2__FPZero1_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addFPZeroOperands, 5, CVT_Done },
  // Convert__Reg1_0__FPZero1_1
  { CVT_95_Reg, 1, CVT_95_addFPZeroOperands, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_1__CVTFixedPos321_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addCVTFixedPosOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__CVTFixedPos641_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addCVTFixedPosOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShrImm321_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShrImm641_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_2__ShrImm321_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__ShrImm641_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm21_5
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm11_5
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_95_addImmOperands, 8, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm11_7
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_95_addImmOperands, 8, CVT_Done },
  // Convert__Reg1_0__FMOVImm1_1
  { CVT_95_Reg, 1, CVT_95_addFMOVImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__FMOVImm1_2
  { CVT_95_Reg, 1, CVT_95_addFMOVImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Lane11_4
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_5__Lane11_3
  { CVT_95_Reg, 1, CVT_95_Reg, 6, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__UImm21_5
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__UImm11_5
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_95_addImmOperands, 8, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_4__UImm11_7
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_95_addImmOperands, 8, CVT_Done },
  // Convert__UImm71_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__NamedImmic1_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__NamedImmic1_0__Reg1_1
  { CVT_95_addImmOperands, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_5__UImm41_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 6, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_5__UImm11_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 6, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_5__UImm31_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 6, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_5__UImm21_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 6, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_5__UImm41_3__UImm41_8
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 6, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 9, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_5__UImm11_3__UImm11_8
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 6, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 9, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_5__UImm31_3__UImm31_8
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 6, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 9, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_5__UImm21_3__UImm21_8
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 6, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 9, CVT_Done },
  // Convert__NamedImmisb1_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__VOne16B11_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VOne1D11_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VOne2D11_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VOne2S11_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VOne4H11_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VOne4S11_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VOne8B11_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VOne8H11_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VPair16B21_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VPair1D21_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VPair2D21_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VPair2S21_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VPair4H21_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VPair4S21_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VPair8B21_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VPair8H21_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VQuad16B41_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VQuad1D41_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VQuad2D41_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VQuad2S41_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VQuad4H41_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VQuad4S41_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VQuad8B41_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VQuad8H41_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VTriple16B31_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VTriple1D31_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VTriple2D31_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VTriple2S31_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VTriple4H31_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VTriple4S31_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VTriple8B31_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VTriple8H31_0__Reg1_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__VOne16B11_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VOne16B11_0__Reg1_2__Tie1__Exact161_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOne1D11_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VOne1D11_0__Reg1_2__Tie1__Exact81_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOne2D11_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VOne2D11_0__Reg1_2__Tie1__Exact161_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOne2S11_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VOne2S11_0__Reg1_2__Tie1__Exact81_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOne4H11_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VOne4H11_0__Reg1_2__Tie1__Exact81_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOne4S11_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VOne4S11_0__Reg1_2__Tie1__Exact161_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOne8B11_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VOne8B11_0__Reg1_2__Tie1__Exact81_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOne8H11_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VOne8H11_0__Reg1_2__Tie1__Exact161_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair16B21_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VPair16B21_0__Reg1_2__Tie1__Exact321_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair1D21_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VPair1D21_0__Reg1_2__Tie1__Exact161_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair2D21_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VPair2D21_0__Reg1_2__Tie1__Exact321_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair2S21_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VPair2S21_0__Reg1_2__Tie1__Exact161_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair4H21_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VPair4H21_0__Reg1_2__Tie1__Exact161_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair4S21_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VPair4S21_0__Reg1_2__Tie1__Exact321_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair8B21_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VPair8B21_0__Reg1_2__Tie1__Exact161_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair8H21_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VPair8H21_0__Reg1_2__Tie1__Exact321_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad16B41_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VQuad16B41_0__Reg1_2__Tie1__Exact641_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad1D41_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VQuad1D41_0__Reg1_2__Tie1__Exact321_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad2D41_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VQuad2D41_0__Reg1_2__Tie1__Exact641_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad2S41_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VQuad2S41_0__Reg1_2__Tie1__Exact321_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad4H41_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VQuad4H41_0__Reg1_2__Tie1__Exact321_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad4S41_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VQuad4S41_0__Reg1_2__Tie1__Exact641_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad8B41_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VQuad8B41_0__Reg1_2__Tie1__Exact321_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad8H41_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VQuad8H41_0__Reg1_2__Tie1__Exact641_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple16B31_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VTriple16B31_0__Reg1_2__Tie1__Exact481_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple1D31_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VTriple1D31_0__Reg1_2__Tie1__Exact241_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple2D31_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VTriple2D31_0__Reg1_2__Tie1__Exact481_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple2S31_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VTriple2S31_0__Reg1_2__Tie1__Exact241_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple4H31_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VTriple4H31_0__Reg1_2__Tie1__Exact241_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple4S31_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VTriple4S31_0__Reg1_2__Tie1__Exact481_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple8B31_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VTriple8B31_0__Reg1_2__Tie1__Exact241_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple8H31_0__Reg1_2__Tie1__Reg1_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_Reg, 5, CVT_Done },
  // Convert__VTriple8H31_0__Reg1_2__Tie1__Exact481_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOneB11_0__Reg1_5__Tie0__UImm41_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VOneD11_0__Reg1_5__Tie0__UImm11_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VOneH11_0__Reg1_5__Tie0__UImm31_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VOneS11_0__Reg1_5__Tie0__UImm21_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VOneB11_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm41_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VOneB11_0__Reg1_5__Tie1__Exact11_7__Tie0__UImm41_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VOneD11_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm11_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VOneD11_0__Reg1_5__Tie1__Exact81_7__Tie0__UImm11_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VOneH11_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm31_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VOneH11_0__Reg1_5__Tie1__Exact21_7__Tie0__UImm31_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VOneS11_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm21_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VOneS11_0__Reg1_5__Tie1__Exact41_7__Tie0__UImm21_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VOne16B11_0__Reg1_2__Tie1__Exact11_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOne2D11_0__Reg1_2__Tie1__Exact81_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOne2S11_0__Reg1_2__Tie1__Exact41_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOne4H11_0__Reg1_2__Tie1__Exact21_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOne4S11_0__Reg1_2__Tie1__Exact41_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOne8B11_0__Reg1_2__Tie1__Exact11_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VOne8H11_0__Reg1_2__Tie1__Exact21_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPairB21_0__Reg1_5__Tie0__UImm41_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VPairD21_0__Reg1_5__Tie0__UImm11_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VPairH21_0__Reg1_5__Tie0__UImm31_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VPairS21_0__Reg1_5__Tie0__UImm21_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VPairB21_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm41_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VPairB21_0__Reg1_5__Tie1__Exact21_7__Tie0__UImm41_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VPairD21_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm11_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VPairD21_0__Reg1_5__Tie1__Exact161_7__Tie0__UImm11_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VPairH21_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm31_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VPairH21_0__Reg1_5__Tie1__Exact41_7__Tie0__UImm31_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VPairS21_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm21_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VPairS21_0__Reg1_5__Tie1__Exact81_7__Tie0__UImm21_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VPair16B21_0__Reg1_2__Tie1__Exact21_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair2D21_0__Reg1_2__Tie1__Exact161_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair2S21_0__Reg1_2__Tie1__Exact81_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair4H21_0__Reg1_2__Tie1__Exact41_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair4S21_0__Reg1_2__Tie1__Exact81_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair8B21_0__Reg1_2__Tie1__Exact21_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VPair8H21_0__Reg1_2__Tie1__Exact41_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTripleB31_0__Reg1_5__Tie0__UImm41_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VTripleD31_0__Reg1_5__Tie0__UImm11_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VTripleH31_0__Reg1_5__Tie0__UImm31_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VTripleS31_0__Reg1_5__Tie0__UImm21_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VTripleB31_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm41_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VTripleB31_0__Reg1_5__Tie1__Exact31_7__Tie0__UImm41_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VTripleD31_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm11_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VTripleD31_0__Reg1_5__Tie1__Exact241_7__Tie0__UImm11_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VTripleH31_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm31_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VTripleH31_0__Reg1_5__Tie1__Exact61_7__Tie0__UImm31_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VTripleS31_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm21_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VTripleS31_0__Reg1_5__Tie1__Exact121_7__Tie0__UImm21_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VTriple16B31_0__Reg1_2__Tie1__Exact31_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple2D31_0__Reg1_2__Tie1__Exact241_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple2S31_0__Reg1_2__Tie1__Exact121_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple4H31_0__Reg1_2__Tie1__Exact61_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple4S31_0__Reg1_2__Tie1__Exact121_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple8B31_0__Reg1_2__Tie1__Exact31_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VTriple8H31_0__Reg1_2__Tie1__Exact61_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuadB41_0__Reg1_5__Tie0__UImm41_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VQuadD41_0__Reg1_5__Tie0__UImm11_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VQuadH41_0__Reg1_5__Tie0__UImm31_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VQuadS41_0__Reg1_5__Tie0__UImm21_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VQuadB41_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm41_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VQuadB41_0__Reg1_5__Tie1__Exact41_7__Tie0__UImm41_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VQuadD41_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm11_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VQuadD41_0__Reg1_5__Tie1__Exact321_7__Tie0__UImm11_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VQuadH41_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm31_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VQuadH41_0__Reg1_5__Tie1__Exact81_7__Tie0__UImm31_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VQuadS41_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm21_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_Reg, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VQuadS41_0__Reg1_5__Tie1__Exact161_7__Tie0__UImm21_2
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 6, CVT_Tied, 1, CVT_95_addImmOperands, 8, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__VQuad16B41_0__Reg1_2__Tie1__Exact41_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad2D41_0__Reg1_2__Tie1__Exact321_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad2S41_0__Reg1_2__Tie1__Exact161_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad4H41_0__Reg1_2__Tie1__Exact81_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad4S41_0__Reg1_2__Tie1__Exact161_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad8B41_0__Reg1_2__Tie1__Exact41_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__VQuad8H41_0__Reg1_2__Tie1__Exact81_4
  { CVT_95_addVectorListOperands, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__GPR64xsp01_2
  { CVT_95_Reg, 1, CVT_95_addRegOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__GPR64xsp01_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addRegOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_3__imm_0
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_0, 0, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled41_4
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_95_addSImm7ScaledOperands_LT_4_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled81_4
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_95_addSImm7ScaledOperands_LT_8_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled161_4
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_95_addSImm7ScaledOperands_LT_16_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled41_5
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_Tied, 2, CVT_95_addSImm7ScaledOperands_LT_4_GT_, 6, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled81_5
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_Tied, 2, CVT_95_addSImm7ScaledOperands_LT_8_GT_, 6, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled161_5
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_Tied, 2, CVT_95_addSImm7ScaledOperands_LT_16_GT_, 6, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled41_4
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_Tied, 2, CVT_95_addSImm7ScaledOperands_LT_4_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled81_4
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_Tied, 2, CVT_95_addSImm7ScaledOperands_LT_8_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled161_4
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_Tied, 2, CVT_95_addSImm7ScaledOperands_LT_16_GT_, 5, CVT_Done },
  // Convert__Reg1_0__LoadLitLabel1_1
  { CVT_95_Reg, 1, CVT_95_addLabelOperands_LT_19_44__32_4_GT_, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_2__imm_0
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_0, 0, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Tie1__SImm91_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addSImmOperands_LT_9_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_3__imm_2
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_imm_2, 0, CVT_Done },
  // Convert__Reg1_0__Reg1_2__OffsetUImm12_41_3
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addOffsetUImm12Operands_LT_4_GT_, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_2__OffsetUImm12_81_3
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addOffsetUImm12Operands_LT_8_GT_, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_2__OffsetUImm12_11_3
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addOffsetUImm12Operands_LT_1_GT_, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_2__OffsetUImm12_21_3
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addOffsetUImm12Operands_LT_2_GT_, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_2__OffsetUImm12_161_3
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addOffsetUImm12Operands_LT_16_GT_, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Wm1_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addAddrRegExtendOperands_LT_4_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Xm1_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addAddrRegExtendOperands_LT_4_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Tie1__SImm91_3
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_Tied, 1, CVT_95_addSImmOperands_LT_9_GT_, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Wm1_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addAddrRegExtendOperands_LT_8_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Xm1_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addAddrRegExtendOperands_LT_8_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Wm1_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addAddrRegExtendOperands_LT_1_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Xm1_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addAddrRegExtendOperands_LT_1_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Wm1_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addAddrRegExtendOperands_LT_2_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Xm1_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addAddrRegExtendOperands_LT_2_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_16_Wm1_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addAddrRegExtendOperands_LT_16_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_16_Xm1_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addAddrRegExtendOperands_LT_16_GT_, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__SImm91_3
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addSImmOperands_LT_9_GT_, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_95_addImmOperands, 8, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__regWZR
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_regWZR, 0, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__regXZR
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_regXZR, 0, CVT_Done },
  // Convert__Reg1_0__regWZR__Reg1_1__imm_0
  { CVT_95_Reg, 1, CVT_regWZR, 0, CVT_95_Reg, 2, CVT_imm_0, 0, CVT_Done },
  // Convert__Reg1_0__MOVN32MovAlias2_1
  { CVT_95_Reg, 1, CVT_95_addMoveWideMovAliasOperands_LT_32_44__32_A64Imms_COLON__COLON_isOnlyMOVNImm_GT_, 2, CVT_Done },
  // Convert__Reg1_0__MOVZ32MovAlias2_1
  { CVT_95_Reg, 1, CVT_95_addMoveWideMovAliasOperands_LT_32_44__32_A64Imms_COLON__COLON_isMOVZImm_GT_, 2, CVT_Done },
  // Convert__Reg1_0__regWZR__LogicalImmMOV321_1
  { CVT_95_Reg, 1, CVT_regWZR, 0, CVT_95_addLogicalImmOperands_LT_32_GT_, 2, CVT_Done },
  // Convert__Reg1_0__regXZR__Reg1_1__imm_0
  { CVT_95_Reg, 1, CVT_regXZR, 0, CVT_95_Reg, 2, CVT_imm_0, 0, CVT_Done },
  // Convert__Reg1_0__MOVN64MovAlias2_1
  { CVT_95_Reg, 1, CVT_95_addMoveWideMovAliasOperands_LT_64_44__32_A64Imms_COLON__COLON_isOnlyMOVNImm_GT_, 2, CVT_Done },
  // Convert__Reg1_0__MOVZ64MovAlias2_1
  { CVT_95_Reg, 1, CVT_95_addMoveWideMovAliasOperands_LT_64_44__32_A64Imms_COLON__COLON_isMOVZImm_GT_, 2, CVT_Done },
  // Convert__Reg1_0__regXZR__LogicalImmMOV641_1
  { CVT_95_Reg, 1, CVT_regXZR, 0, CVT_95_addLogicalImmOperands_LT_64_GT_, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_Done },
  // Convert__Reg1_0__NeonUImm64Mask1_1
  { CVT_95_Reg, 1, CVT_95_addNeonUImm64MaskOperands, 2, CVT_Done },
  // Convert__Reg1_0__UImm81_2__imm_0
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_0, 0, CVT_Done },
  // Convert__Reg1_0__UImm81_2
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__NeonUImm64Mask1_2
  { CVT_95_Reg, 1, CVT_95_addNeonUImm64MaskOperands, 3, CVT_Done },
  // Convert__Reg1_0__UImm81_2__NeonMovImmShiftLSL1_3
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_95_addNeonMovImmShiftLSLOperands, 4, CVT_Done },
  // Convert__Reg1_0__UImm81_2__NeonMovImmShiftMSL1_3
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_95_addNeonMovImmShiftMSLOperands, 4, CVT_Done },
  // Convert__Reg1_0__UImm81_2__NeonMovImmShiftLSLH1_3
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_95_addNeonMovImmShiftLSLHOperands, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__MOVK32Shiftedshift2_1
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addMoveWideImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__Tie0__MOVK64Shiftedshift2_1
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addMoveWideImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__MOVN32Shiftedshift2_1
  { CVT_95_Reg, 1, CVT_95_addMoveWideImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__MOVN64Shiftedshift2_1
  { CVT_95_Reg, 1, CVT_95_addMoveWideImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__MOVZ32Shiftedshift2_1
  { CVT_95_Reg, 1, CVT_95_addMoveWideImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__MOVZ64Shiftedshift2_1
  { CVT_95_Reg, 1, CVT_95_addMoveWideImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__MRS1_1
  { CVT_95_Reg, 1, CVT_95_addMRSOperands, 2, CVT_Done },
  // Convert__MSRWithReg1_0__Reg1_1
  { CVT_95_addMSRWithRegOperands, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__MSRPState1_0__UImm41_1
  { CVT_95_addMSRPStateOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_95_addImmOperands, 8, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShiftRORi321_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShiftRORi641_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__regWZR__Reg1_1__ShiftASRi321_2
  { CVT_95_Reg, 1, CVT_regWZR, 0, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__regWZR__Reg1_1__ShiftLSLi321_2
  { CVT_95_Reg, 1, CVT_regWZR, 0, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__regWZR__Reg1_1__ShiftLSRi321_2
  { CVT_95_Reg, 1, CVT_regWZR, 0, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__regXZR__Reg1_1__ShiftASRi641_2
  { CVT_95_Reg, 1, CVT_regXZR, 0, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__regXZR__Reg1_1__ShiftLSLi641_2
  { CVT_95_Reg, 1, CVT_regXZR, 0, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__regXZR__Reg1_1__ShiftLSRi641_2
  { CVT_95_Reg, 1, CVT_regXZR, 0, CVT_95_Reg, 2, CVT_95_addShiftOperands, 3, CVT_Done },
  // Convert__Reg1_0__regWZR__Reg1_1
  { CVT_95_Reg, 1, CVT_regWZR, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Reg1_0__regXZR__Reg1_1
  { CVT_95_Reg, 1, CVT_regXZR, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__NamedImmprefetch1_0__LoadLitLabel1_1
  { CVT_95_addImmOperands, 1, CVT_95_addLabelOperands_LT_19_44__32_4_GT_, 2, CVT_Done },
  // Convert__NamedImmprefetch1_0__Reg1_2__imm_0
  { CVT_95_addImmOperands, 1, CVT_95_Reg, 3, CVT_imm_0, 0, CVT_Done },
  // Convert__NamedImmprefetch1_0__Reg1_2__Reg1_3__imm_2
  { CVT_95_addImmOperands, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_imm_2, 0, CVT_Done },
  // Convert__NamedImmprefetch1_0__Reg1_2__OffsetUImm12_81_3
  { CVT_95_addImmOperands, 1, CVT_95_Reg, 3, CVT_95_addOffsetUImm12Operands_LT_8_GT_, 4, CVT_Done },
  // Convert__NamedImmprefetch1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Wm1_4
  { CVT_95_addImmOperands, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addAddrRegExtendOperands_LT_8_GT_, 5, CVT_Done },
  // Convert__NamedImmprefetch1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Xm1_4
  { CVT_95_addImmOperands, 1, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addAddrRegExtendOperands_LT_8_GT_, 5, CVT_Done },
  // Convert__NamedImmprefetch1_0__Reg1_2__SImm91_3
  { CVT_95_addImmOperands, 1, CVT_95_Reg, 3, CVT_95_addSImmOperands_LT_9_GT_, 4, CVT_Done },
  // Convert__regX30
  { CVT_regX30, 0, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_1__UImm51_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_1__UImm61_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_2__ShrImm161_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__ShrImm81_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_1__BFI32LSB1_2__BFI32Width1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addBFILSBOperands_LT_32_GT_, 3, CVT_95_addBFIWidthOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__BFI64LSB1_2__BFI64Width1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addBFILSBOperands_LT_64_GT_, 3, CVT_95_addBFIWidthOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UImm51_2__UImm51_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UImm61_2__UImm61_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UImm51_2__BFX32Width1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addBFXWidthOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__UImm61_2__BFX64Width1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addBFXWidthOperands, 4, CVT_Done },
  // Convert__imm_4
  { CVT_imm_4, 0, CVT_Done },
  // Convert__imm_5
  { CVT_imm_5, 0, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1__Reg1_2
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShlImm641_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_2__ShlImm321_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__ShlImm161_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__ShlImm81_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__ShlImm641_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Exact321_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Exact161_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Reg1_2__Exact81_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1__ShlImm641_2
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_2__ShlImm321_4
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_2__ShlImm161_4
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_2__ShlImm81_4
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_2__ShlImm641_4
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm31_5
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__UImm31_5
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShrImm81_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShrImm161_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShlImm81_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShlImm161_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__ShlImm321_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1__ShrImm641_2
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_2__ShrImm641_4
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_2__VOne16B11_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VOne1D11_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VOne2D11_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VOne2S11_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VOne4H11_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VOne4S11_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VOne8B11_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VOne8H11_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VPair16B21_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VPair1D21_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VPair2D21_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VPair2S21_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VPair4H21_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VPair4S21_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VPair8B21_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VPair8H21_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VQuad16B41_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VQuad1D41_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VQuad2D41_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VQuad2S41_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VQuad4H41_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VQuad4S41_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VQuad8B41_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VQuad8H41_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VTriple16B31_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VTriple1D31_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VTriple2D31_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VTriple2S31_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VTriple4H31_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VTriple4S31_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VTriple8B31_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__VTriple8H31_0
  { CVT_95_Reg, 3, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VOne16B11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact161_4__VOne16B11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VOne1D11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact81_4__VOne1D11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VOne2D11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact161_4__VOne2D11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VOne2S11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact81_4__VOne2S11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VOne4H11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact81_4__VOne4H11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VOne4S11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact161_4__VOne4S11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VOne8B11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact81_4__VOne8B11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VOne8H11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact161_4__VOne8H11_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VPair16B21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact321_4__VPair16B21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VPair1D21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact161_4__VPair1D21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VPair2D21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact321_4__VPair2D21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VPair2S21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact161_4__VPair2S21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VPair4H21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact161_4__VPair4H21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VPair4S21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact321_4__VPair4S21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VPair8B21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact161_4__VPair8B21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VPair8H21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact321_4__VPair8H21_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VQuad16B41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact641_4__VQuad16B41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VQuad1D41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact321_4__VQuad1D41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VQuad2D41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact641_4__VQuad2D41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VQuad2S41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact321_4__VQuad2S41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VQuad4H41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact321_4__VQuad4H41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VQuad4S41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact641_4__VQuad4S41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VQuad8B41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact321_4__VQuad8B41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VQuad8H41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact641_4__VQuad8H41_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VTriple16B31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact481_4__VTriple16B31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VTriple1D31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact241_4__VTriple1D31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VTriple2D31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact481_4__VTriple2D31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VTriple2S31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact241_4__VTriple2S31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VTriple4H31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact241_4__VTriple4H31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VTriple4S31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact481_4__VTriple4S31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VTriple8B31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact241_4__VTriple8B31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VTriple8H31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Exact481_4__VTriple8H31_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addVectorListOperands, 1, CVT_Done },
  // Convert__Reg1_5__VOneB11_0__UImm41_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VOneD11_0__UImm11_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VOneH11_0__UImm31_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VOneS11_0__UImm21_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VOneB11_0__UImm41_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact11_7__VOneB11_0__UImm41_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VOneD11_0__UImm11_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact81_7__VOneD11_0__UImm11_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VOneH11_0__UImm31_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact21_7__VOneH11_0__UImm31_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VOneS11_0__UImm21_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact41_7__VOneS11_0__UImm21_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VPairB21_0__UImm41_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VPairD21_0__UImm11_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VPairH21_0__UImm31_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VPairS21_0__UImm21_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VPairB21_0__UImm41_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact21_7__VPairB21_0__UImm41_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VPairD21_0__UImm11_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact161_7__VPairD21_0__UImm11_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VPairH21_0__UImm31_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact41_7__VPairH21_0__UImm31_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VPairS21_0__UImm21_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact81_7__VPairS21_0__UImm21_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VTripleB31_0__UImm41_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VTripleD31_0__UImm11_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VTripleH31_0__UImm31_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VTripleS31_0__UImm21_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VTripleB31_0__UImm41_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact31_7__VTripleB31_0__UImm41_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VTripleD31_0__UImm11_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact241_7__VTripleD31_0__UImm11_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VTripleH31_0__UImm31_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact61_7__VTripleH31_0__UImm31_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VTripleS31_0__UImm21_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact121_7__VTripleS31_0__UImm21_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VQuadB41_0__UImm41_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VQuadD41_0__UImm11_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VQuadH41_0__UImm31_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__VQuadS41_0__UImm21_2
  { CVT_95_Reg, 6, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VQuadB41_0__UImm41_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact41_7__VQuadB41_0__UImm41_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VQuadD41_0__UImm11_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact321_7__VQuadD41_0__UImm11_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VQuadH41_0__UImm31_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact81_7__VQuadH41_0__UImm31_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Reg1_7__VQuadS41_0__UImm21_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_Reg, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_5__Tie0__Exact161_7__VQuadS41_0__UImm21_2
  { CVT_95_Reg, 6, CVT_Tied, 0, CVT_95_addImmOperands, 8, CVT_95_addVectorListOperands, 1, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2__GPR64xsp01_4
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addRegOperands, 5, CVT_Done },
  // Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled41_5
  { CVT_95_Reg, 4, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addSImm7ScaledOperands_LT_4_GT_, 6, CVT_Done },
  // Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled81_5
  { CVT_95_Reg, 4, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addSImm7ScaledOperands_LT_8_GT_, 6, CVT_Done },
  // Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled161_5
  { CVT_95_Reg, 4, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addSImm7ScaledOperands_LT_16_GT_, 6, CVT_Done },
  // Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled41_4
  { CVT_95_Reg, 4, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addSImm7ScaledOperands_LT_4_GT_, 5, CVT_Done },
  // Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled81_4
  { CVT_95_Reg, 4, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addSImm7ScaledOperands_LT_8_GT_, 5, CVT_Done },
  // Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled161_4
  { CVT_95_Reg, 4, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addSImm7ScaledOperands_LT_16_GT_, 5, CVT_Done },
  // Convert__Reg1_2__Reg1_0__Tie0__SImm91_4
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addSImmOperands_LT_9_GT_, 5, CVT_Done },
  // Convert__Reg1_2__Reg1_0__Tie0__SImm91_3
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addSImmOperands_LT_9_GT_, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__Reg1_1
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__UImm31_0__CRx1_1__CRx1_2__UImm31_3__regXZR
  { CVT_95_addImmOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_regXZR, 0, CVT_Done },
  // Convert__UImm31_0__CRx1_1__CRx1_2__UImm31_3__Reg1_4
  { CVT_95_addImmOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_95_Reg, 5, CVT_Done },
  // Convert__Reg1_0__UImm31_1__CRx1_2__CRx1_3__UImm31_4
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_0__VOne16B11_2__Reg1_3
  { CVT_95_Reg, 1, CVT_95_addVectorListOperands, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_0__VPair16B21_2__Reg1_3
  { CVT_95_Reg, 1, CVT_95_addVectorListOperands, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_0__VQuad16B41_2__Reg1_3
  { CVT_95_Reg, 1, CVT_95_addVectorListOperands, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_0__VTriple16B31_2__Reg1_3
  { CVT_95_Reg, 1, CVT_95_addVectorListOperands, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_0__UImm51_1__Label14_41_2
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_95_addLabelOperands_LT_14_44__32_4_GT_, 3, CVT_Done },
  // Convert__Reg1_0__UImm61_1__Label14_41_2
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_95_addLabelOperands_LT_14_44__32_4_GT_, 3, CVT_Done },
  // Convert__Reg1_0__Tie0__VOne16B11_2__Reg1_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addVectorListOperands, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__VPair16B21_2__Reg1_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addVectorListOperands, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__VQuad16B41_2__Reg1_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addVectorListOperands, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_0__Tie0__VTriple16B31_2__Reg1_3
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addVectorListOperands, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__NamedImmtlbi1_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__NamedImmtlbi1_0__Reg1_1
  { CVT_95_addImmOperands, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__regWZR__Reg1_0__LogicalImm321_1
  { CVT_regWZR, 0, CVT_95_Reg, 1, CVT_95_addLogicalImmOperands_LT_32_GT_, 2, CVT_Done },
  // Convert__regXZR__Reg1_0__LogicalImm641_1
  { CVT_regXZR, 0, CVT_95_Reg, 1, CVT_95_addLogicalImmOperands_LT_64_GT_, 2, CVT_Done },
  // Convert__imm_2
  { CVT_imm_2, 0, CVT_Done },
  // Convert__imm_3
  { CVT_imm_3, 0, CVT_Done },
  // Convert__imm_1
  { CVT_imm_1, 0, CVT_Done },
};

void AArch64AsmParser::
convertToMCInst(unsigned Kind, MCInst &Inst, unsigned Opcode,
                const SmallVectorImpl<MCParsedAsmOperand*> &Operands) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  const uint8_t *Converter = ConversionTable[Kind];
  Inst.setOpcode(Opcode);
  for (const uint8_t *p = Converter; *p; p+= 2) {
    switch (*p) {
    default: llvm_unreachable("invalid conversion entry!");
    case CVT_Reg:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addRegOperands(Inst, 1);
      break;
    case CVT_Tied:
      Inst.addOperand(Inst.getOperand(*(p + 1)));
      break;
    case CVT_95_Reg:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addRegOperands(Inst, 1);
      break;
    case CVT_imm_0:
      Inst.addOperand(MCOperand::CreateImm(0));
      break;
    case CVT_95_addImmWithLSLOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addImmWithLSLOperands(Inst, 1);
      break;
    case CVT_95_addShiftOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addShiftOperands(Inst, 1);
      break;
    case CVT_95_addRegExtendOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addRegExtendOperands(Inst, 1);
      break;
    case CVT_95_addLabelOperands_LT_21_44__32_1_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addLabelOperands<21, 1>(Inst, 1);
      break;
    case CVT_95_addLabelOperands_LT_21_44__32_4096_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addLabelOperands<21, 4096>(Inst, 1);
      break;
    case CVT_95_addLogicalImmOperands_LT_32_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addLogicalImmOperands<32>(Inst, 1);
      break;
    case CVT_95_addLogicalImmOperands_LT_64_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addLogicalImmOperands<64>(Inst, 1);
      break;
    case CVT_95_addImmOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addImmOperands(Inst, 1);
      break;
    case CVT_95_addLabelOperands_LT_26_44__32_4_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addLabelOperands<26, 4>(Inst, 1);
      break;
    case CVT_95_addCondCodeOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addCondCodeOperands(Inst, 1);
      break;
    case CVT_95_addLabelOperands_LT_19_44__32_4_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addLabelOperands<19, 4>(Inst, 1);
      break;
    case CVT_95_addBFILSBOperands_LT_32_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addBFILSBOperands<32>(Inst, 1);
      break;
    case CVT_95_addBFIWidthOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addBFIWidthOperands(Inst, 1);
      break;
    case CVT_95_addBFILSBOperands_LT_64_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addBFILSBOperands<64>(Inst, 1);
      break;
    case CVT_95_addBFXWidthOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addBFXWidthOperands(Inst, 1);
      break;
    case CVT_95_addNeonMovImmShiftLSLOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addNeonMovImmShiftLSLOperands(Inst, 1);
      break;
    case CVT_95_addNeonMovImmShiftLSLHOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addNeonMovImmShiftLSLHOperands(Inst, 1);
      break;
    case CVT_95_addInvCondCodeOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addInvCondCodeOperands(Inst, 1);
      break;
    case CVT_imm_15:
      Inst.addOperand(MCOperand::CreateImm(15));
      break;
    case CVT_regWZR:
      Inst.addOperand(MCOperand::CreateReg(AArch64::WZR));
      break;
    case CVT_regXZR:
      Inst.addOperand(MCOperand::CreateReg(AArch64::XZR));
      break;
    case CVT_95_addFPZeroOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addFPZeroOperands(Inst, 1);
      break;
    case CVT_95_addCVTFixedPosOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addCVTFixedPosOperands(Inst, 1);
      break;
    case CVT_95_addFMOVImmOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addFMOVImmOperands(Inst, 1);
      break;
    case CVT_95_addVectorListOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addVectorListOperands(Inst, 1);
      break;
    case CVT_95_addRegOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addRegOperands(Inst, 1);
      break;
    case CVT_95_addSImm7ScaledOperands_LT_4_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addSImm7ScaledOperands<4>(Inst, 1);
      break;
    case CVT_95_addSImm7ScaledOperands_LT_8_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addSImm7ScaledOperands<8>(Inst, 1);
      break;
    case CVT_95_addSImm7ScaledOperands_LT_16_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addSImm7ScaledOperands<16>(Inst, 1);
      break;
    case CVT_95_addSImmOperands_LT_9_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addSImmOperands<9>(Inst, 1);
      break;
    case CVT_imm_2:
      Inst.addOperand(MCOperand::CreateImm(2));
      break;
    case CVT_95_addOffsetUImm12Operands_LT_4_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addOffsetUImm12Operands<4>(Inst, 1);
      break;
    case CVT_95_addOffsetUImm12Operands_LT_8_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addOffsetUImm12Operands<8>(Inst, 1);
      break;
    case CVT_95_addOffsetUImm12Operands_LT_1_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addOffsetUImm12Operands<1>(Inst, 1);
      break;
    case CVT_95_addOffsetUImm12Operands_LT_2_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addOffsetUImm12Operands<2>(Inst, 1);
      break;
    case CVT_95_addOffsetUImm12Operands_LT_16_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addOffsetUImm12Operands<16>(Inst, 1);
      break;
    case CVT_95_addAddrRegExtendOperands_LT_4_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addAddrRegExtendOperands<4>(Inst, 1);
      break;
    case CVT_95_addAddrRegExtendOperands_LT_8_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addAddrRegExtendOperands<8>(Inst, 1);
      break;
    case CVT_95_addAddrRegExtendOperands_LT_1_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addAddrRegExtendOperands<1>(Inst, 1);
      break;
    case CVT_95_addAddrRegExtendOperands_LT_2_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addAddrRegExtendOperands<2>(Inst, 1);
      break;
    case CVT_95_addAddrRegExtendOperands_LT_16_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addAddrRegExtendOperands<16>(Inst, 1);
      break;
    case CVT_95_addMoveWideMovAliasOperands_LT_32_44__32_A64Imms_COLON__COLON_isOnlyMOVNImm_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addMoveWideMovAliasOperands<32, A64Imms::isOnlyMOVNImm>(Inst, 2);
      break;
    case CVT_95_addMoveWideMovAliasOperands_LT_32_44__32_A64Imms_COLON__COLON_isMOVZImm_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addMoveWideMovAliasOperands<32, A64Imms::isMOVZImm>(Inst, 2);
      break;
    case CVT_95_addMoveWideMovAliasOperands_LT_64_44__32_A64Imms_COLON__COLON_isOnlyMOVNImm_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addMoveWideMovAliasOperands<64, A64Imms::isOnlyMOVNImm>(Inst, 2);
      break;
    case CVT_95_addMoveWideMovAliasOperands_LT_64_44__32_A64Imms_COLON__COLON_isMOVZImm_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addMoveWideMovAliasOperands<64, A64Imms::isMOVZImm>(Inst, 2);
      break;
    case CVT_95_addNeonUImm64MaskOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addNeonUImm64MaskOperands(Inst, 1);
      break;
    case CVT_95_addNeonMovImmShiftMSLOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addNeonMovImmShiftMSLOperands(Inst, 1);
      break;
    case CVT_95_addMoveWideImmOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addMoveWideImmOperands(Inst, 2);
      break;
    case CVT_95_addMRSOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addMRSOperands(Inst, 1);
      break;
    case CVT_95_addMSRWithRegOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addMSRWithRegOperands(Inst, 1);
      break;
    case CVT_95_addMSRPStateOperands:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addMSRPStateOperands(Inst, 1);
      break;
    case CVT_regX30:
      Inst.addOperand(MCOperand::CreateReg(AArch64::X30));
      break;
    case CVT_imm_4:
      Inst.addOperand(MCOperand::CreateImm(4));
      break;
    case CVT_imm_5:
      Inst.addOperand(MCOperand::CreateImm(5));
      break;
    case CVT_95_addLabelOperands_LT_14_44__32_4_GT_:
      static_cast<AArch64Operand*>(Operands[*(p + 1)])->addLabelOperands<14, 4>(Inst, 1);
      break;
    case CVT_imm_3:
      Inst.addOperand(MCOperand::CreateImm(3));
      break;
    case CVT_imm_1:
      Inst.addOperand(MCOperand::CreateImm(1));
      break;
    }
  }
}

void AArch64AsmParser::
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
    case CVT_95_Reg:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("r");
      NumMCOperands += 1;
      break;
    case CVT_imm_0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addImmWithLSLOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addShiftOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegExtendOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addLabelOperands_LT_21_44__32_1_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addLabelOperands_LT_21_44__32_4096_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addLogicalImmOperands_LT_32_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addLogicalImmOperands_LT_64_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addLabelOperands_LT_26_44__32_4_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addCondCodeOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addLabelOperands_LT_19_44__32_4_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addBFILSBOperands_LT_32_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addBFIWidthOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addBFILSBOperands_LT_64_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addBFXWidthOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addNeonMovImmShiftLSLOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addNeonMovImmShiftLSLHOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addInvCondCodeOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_15:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_regWZR:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_regXZR:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_95_addFPZeroOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addCVTFixedPosOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addFMOVImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addVectorListOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addSImm7ScaledOperands_LT_4_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addSImm7ScaledOperands_LT_8_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addSImm7ScaledOperands_LT_16_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addSImmOperands_LT_9_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_2:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addOffsetUImm12Operands_LT_4_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addOffsetUImm12Operands_LT_8_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addOffsetUImm12Operands_LT_1_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addOffsetUImm12Operands_LT_2_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addOffsetUImm12Operands_LT_16_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addAddrRegExtendOperands_LT_4_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addAddrRegExtendOperands_LT_8_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addAddrRegExtendOperands_LT_1_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addAddrRegExtendOperands_LT_2_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addAddrRegExtendOperands_LT_16_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addMoveWideMovAliasOperands_LT_32_44__32_A64Imms_COLON__COLON_isOnlyMOVNImm_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMoveWideMovAliasOperands_LT_32_44__32_A64Imms_COLON__COLON_isMOVZImm_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMoveWideMovAliasOperands_LT_64_44__32_A64Imms_COLON__COLON_isOnlyMOVNImm_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMoveWideMovAliasOperands_LT_64_44__32_A64Imms_COLON__COLON_isMOVZImm_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addNeonUImm64MaskOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addNeonMovImmShiftMSLOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addMoveWideImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMRSOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addMSRWithRegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addMSRPStateOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_regX30:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_imm_4:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_5:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addLabelOperands_LT_14_44__32_4_GT_:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_3:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_1:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
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
  MCK__EXCLAIM_, // '!'
  MCK__DOT_, // '.'
  MCK__DOT_16b, // '.16b'
  MCK__DOT_1d, // '.1d'
  MCK__DOT_1q, // '.1q'
  MCK__DOT_2d, // '.2d'
  MCK__DOT_2s, // '.2s'
  MCK__DOT_4h, // '.4h'
  MCK__DOT_4s, // '.4s'
  MCK__DOT_8b, // '.8b'
  MCK__DOT_8h, // '.8h'
  MCK__DOT_b, // '.b'
  MCK__DOT_d, // '.d'
  MCK__DOT_h, // '.h'
  MCK__DOT_s, // '.s'
  MCK__91_, // '['
  MCK__93_, // ']'
  MCK_GPR32nowzr, // register class 'GPR32nowzr'
  MCK_GPR32, // register class 'GPR32'
  MCK_Rwsp, // register class 'Rwsp'
  MCK_GPR32wsp, // register class 'GPR32wsp'
  MCK_tcGPR64, // register class 'tcGPR64'
  MCK_GPR64noxzr, // register class 'GPR64noxzr'
  MCK_GPR64, // register class 'GPR64'
  MCK_Rxsp, // register class 'Rxsp'
  MCK_GPR64xsp, // register class 'GPR64xsp'
  MCK_FPR8, // register class 'FPR8'
  MCK_FPR16, // register class 'FPR16'
  MCK_FPR32, // register class 'FPR32'
  MCK_FPR64Lo, // register class 'FPR64Lo'
  MCK_FPR64, // register class 'FPR64'
  MCK_FPR128Lo, // register class 'FPR128Lo'
  MCK_FPR128, // register class 'FPR128'
  MCK_FlagClass, // register class 'FlagClass'
  MCK_Reg17, // derived register class
  MCK_Reg20, // derived register class
  MCK_Reg18, // derived register class
  MCK_DPair, // register class 'DPair'
  MCK_Reg21, // derived register class
  MCK_Reg22, // derived register class
  MCK_Reg24, // derived register class
  MCK_QPair, // register class 'QPair'
  MCK_Reg25, // derived register class
  MCK_Reg26, // derived register class
  MCK_Reg27, // derived register class
  MCK_Reg31, // derived register class
  MCK_Reg29, // derived register class
  MCK_Reg30, // derived register class
  MCK_DTriple, // register class 'DTriple'
  MCK_Reg32, // derived register class
  MCK_Reg38, // derived register class
  MCK_Reg33, // derived register class
  MCK_Reg34, // derived register class
  MCK_Reg36, // derived register class
  MCK_Reg37, // derived register class
  MCK_QTriple, // register class 'QTriple'
  MCK_Reg39, // derived register class
  MCK_Reg40, // derived register class
  MCK_Reg41, // derived register class
  MCK_Reg42, // derived register class
  MCK_Reg49, // derived register class
  MCK_Reg46, // derived register class
  MCK_Reg44, // derived register class
  MCK_Reg48, // derived register class
  MCK_Reg45, // derived register class
  MCK_Reg47, // derived register class
  MCK_DQuad, // register class 'DQuad'
  MCK_Reg50, // derived register class
  MCK_Reg60, // derived register class
  MCK_Reg51, // derived register class
  MCK_Reg52, // derived register class
  MCK_Reg53, // derived register class
  MCK_Reg59, // derived register class
  MCK_Reg58, // derived register class
  MCK_Reg57, // derived register class
  MCK_Reg56, // derived register class
  MCK_Reg55, // derived register class
  MCK_QQuad, // register class 'QQuad'
  MCK_CRx, // user defined class 'CRx_asmoperand'
  MCK_GPR64xsp0, // user defined class 'GPR64xsp0_asmoperand'
  MCK_Imm, // user defined class 'ImmAsmOperand'
  MCK_RegExtendLSL, // user defined class 'LSL_extasmoperand'
  MCK_SXTB, // user defined class 'SXTB_asmoperand'
  MCK_SXTH, // user defined class 'SXTH_asmoperand'
  MCK_SXTW, // user defined class 'SXTW_asmoperand'
  MCK_SXTX, // user defined class 'SXTX_asmoperand'
  MCK_UXTB, // user defined class 'UXTB_asmoperand'
  MCK_UXTH, // user defined class 'UXTH_asmoperand'
  MCK_UXTW, // user defined class 'UXTW_asmoperand'
  MCK_UXTX, // user defined class 'UXTX_asmoperand'
  MCK_VOne16B1, // user defined class 'VOne16B_asmoperand'
  MCK_VOne1D1, // user defined class 'VOne1D_asmoperand'
  MCK_VOne2D1, // user defined class 'VOne2D_asmoperand'
  MCK_VOne2S1, // user defined class 'VOne2S_asmoperand'
  MCK_VOne4H1, // user defined class 'VOne4H_asmoperand'
  MCK_VOne4S1, // user defined class 'VOne4S_asmoperand'
  MCK_VOne8B1, // user defined class 'VOne8B_asmoperand'
  MCK_VOne8H1, // user defined class 'VOne8H_asmoperand'
  MCK_VOneB1, // user defined class 'VOneB_asmoperand'
  MCK_VOneD1, // user defined class 'VOneD_asmoperand'
  MCK_VOneH1, // user defined class 'VOneH_asmoperand'
  MCK_VOneS1, // user defined class 'VOneS_asmoperand'
  MCK_VPR, // user defined class 'VPR64AsmOperand'
  MCK_VPair16B2, // user defined class 'VPair16B_asmoperand'
  MCK_VPair1D2, // user defined class 'VPair1D_asmoperand'
  MCK_VPair2D2, // user defined class 'VPair2D_asmoperand'
  MCK_VPair2S2, // user defined class 'VPair2S_asmoperand'
  MCK_VPair4H2, // user defined class 'VPair4H_asmoperand'
  MCK_VPair4S2, // user defined class 'VPair4S_asmoperand'
  MCK_VPair8B2, // user defined class 'VPair8B_asmoperand'
  MCK_VPair8H2, // user defined class 'VPair8H_asmoperand'
  MCK_VPairB2, // user defined class 'VPairB_asmoperand'
  MCK_VPairD2, // user defined class 'VPairD_asmoperand'
  MCK_VPairH2, // user defined class 'VPairH_asmoperand'
  MCK_VPairS2, // user defined class 'VPairS_asmoperand'
  MCK_VQuad16B4, // user defined class 'VQuad16B_asmoperand'
  MCK_VQuad1D4, // user defined class 'VQuad1D_asmoperand'
  MCK_VQuad2D4, // user defined class 'VQuad2D_asmoperand'
  MCK_VQuad2S4, // user defined class 'VQuad2S_asmoperand'
  MCK_VQuad4H4, // user defined class 'VQuad4H_asmoperand'
  MCK_VQuad4S4, // user defined class 'VQuad4S_asmoperand'
  MCK_VQuad8B4, // user defined class 'VQuad8B_asmoperand'
  MCK_VQuad8H4, // user defined class 'VQuad8H_asmoperand'
  MCK_VQuadB4, // user defined class 'VQuadB_asmoperand'
  MCK_VQuadD4, // user defined class 'VQuadD_asmoperand'
  MCK_VQuadH4, // user defined class 'VQuadH_asmoperand'
  MCK_VQuadS4, // user defined class 'VQuadS_asmoperand'
  MCK_VTriple16B3, // user defined class 'VTriple16B_asmoperand'
  MCK_VTriple1D3, // user defined class 'VTriple1D_asmoperand'
  MCK_VTriple2D3, // user defined class 'VTriple2D_asmoperand'
  MCK_VTriple2S3, // user defined class 'VTriple2S_asmoperand'
  MCK_VTriple4H3, // user defined class 'VTriple4H_asmoperand'
  MCK_VTriple4S3, // user defined class 'VTriple4S_asmoperand'
  MCK_VTriple8B3, // user defined class 'VTriple8B_asmoperand'
  MCK_VTriple8H3, // user defined class 'VTriple8H_asmoperand'
  MCK_VTripleB3, // user defined class 'VTripleB_asmoperand'
  MCK_VTripleD3, // user defined class 'VTripleD_asmoperand'
  MCK_VTripleH3, // user defined class 'VTripleH_asmoperand'
  MCK_VTripleS3, // user defined class 'VTripleS_asmoperand'
  MCK_AddSubImmLSL0, // user defined class 'addsubimm_lsl0_asmoperand'
  MCK_AddSubImmLSL12, // user defined class 'addsubimm_lsl12_asmoperand'
  MCK_AdrpLabel, // user defined class 'adrp_label_asmoperand'
  MCK_Label21_1, // user defined class 'anonymous.val.466'
  MCK_ShiftASRi32, // user defined class 'asr_operand_asmoperand_i32'
  MCK_ShiftASRi64, // user defined class 'asr_operand_asmoperand_i64'
  MCK_NamedImmat, // user defined class 'at_asmoperand'
  MCK_BFI32LSB, // user defined class 'bfi32_lsb_asmoperand'
  MCK_BFI32Width, // user defined class 'bfi32_width_asmoperand'
  MCK_BFI64LSB, // user defined class 'bfi64_lsb_asmoperand'
  MCK_BFI64Width, // user defined class 'bfi64_width_asmoperand'
  MCK_BFX32Width, // user defined class 'bfx32_width_asmoperand'
  MCK_BFX64Width, // user defined class 'bfx64_width_asmoperand'
  MCK_AddrRegExtend_1_Wm, // user defined class 'byte_Wm_regext_asmoperand'
  MCK_AddrRegExtend_1_Xm, // user defined class 'byte_Xm_regext_asmoperand'
  MCK_OffsetUImm12_1, // user defined class 'byte_uimm12_asmoperand'
  MCK_CondCode, // user defined class 'cond_code_asmoperand'
  MCK_CondCodeOp, // user defined class 'cond_code_op_asmoperand'
  MCK_NamedImmdbarrier, // user defined class 'dbarrier_asmoperand'
  MCK_NamedImmdc, // user defined class 'dc_asmoperand'
  MCK_AddrRegExtend_8_Wm, // user defined class 'dword_Wm_regext_asmoperand'
  MCK_AddrRegExtend_8_Xm, // user defined class 'dword_Xm_regext_asmoperand'
  MCK_SImm7_Scaled8, // user defined class 'dword_simm7_asmoperand'
  MCK_OffsetUImm12_8, // user defined class 'dword_uimm12_asmoperand'
  MCK_Exact12, // user defined class 'exact12_asmoperand'
  MCK_Exact16, // user defined class 'exact16_asmoperand'
  MCK_Exact1, // user defined class 'exact1_asmoperand'
  MCK_Exact24, // user defined class 'exact24_asmoperand'
  MCK_Exact2, // user defined class 'exact2_asmoperand'
  MCK_Exact32, // user defined class 'exact32_asmoperand'
  MCK_Exact3, // user defined class 'exact3_asmoperand'
  MCK_Exact48, // user defined class 'exact48_asmoperand'
  MCK_Exact4, // user defined class 'exact4_asmoperand'
  MCK_Exact64, // user defined class 'exact64_asmoperand'
  MCK_Exact6, // user defined class 'exact6_asmoperand'
  MCK_Exact8, // user defined class 'exact8_asmoperand'
  MCK_CVTFixedPos32, // user defined class 'fixedpos_asmoperand_i32'
  MCK_CVTFixedPos64, // user defined class 'fixedpos_asmoperand_i64'
  MCK_FMOVImm, // user defined class 'fpimm_asmoperand'
  MCK_FPZero, // user defined class 'fpzero_asmoperand'
  MCK_AddrRegExtend_2_Wm, // user defined class 'hword_Wm_regext_asmoperand'
  MCK_AddrRegExtend_2_Xm, // user defined class 'hword_Xm_regext_asmoperand'
  MCK_OffsetUImm12_2, // user defined class 'hword_uimm12_asmoperand'
  MCK_NamedImmic, // user defined class 'ic_asmoperand'
  MCK_InvCondCodeOp, // user defined class 'inv_cond_code_op_asmoperand'
  MCK_NamedImmisb, // user defined class 'isb_asmoperand'
  MCK_Label14_4, // user defined class 'label_wid14_scal4_asmoperand'
  MCK_Label19_4, // user defined class 'label_wid19_scal4_asmoperand'
  MCK_Label26_4, // user defined class 'label_wid26_scal4_asmoperand'
  MCK_Lane1, // user defined class 'lane1_asmoperand'
  MCK_LoadLitLabel, // user defined class 'ldrlit_label_asmoperand'
  MCK_LogicalImm32, // user defined class 'logical_imm32_asmoperand'
  MCK_LogicalImmMOV32, // user defined class 'logical_imm32_mov_asmoperand'
  MCK_LogicalImm64, // user defined class 'logical_imm64_asmoperand'
  MCK_LogicalImmMOV64, // user defined class 'logical_imm64_mov_asmoperand'
  MCK_ShiftLSLi32, // user defined class 'lsl_operand_asmoperand_i32'
  MCK_ShiftLSLi64, // user defined class 'lsl_operand_asmoperand_i64'
  MCK_ShiftLSRi32, // user defined class 'lsr_operand_asmoperand_i32'
  MCK_ShiftLSRi64, // user defined class 'lsr_operand_asmoperand_i64'
  MCK_MOVK32Shiftedshift, // user defined class 'movk32_imm_asmoperand'
  MCK_MOVK64Shiftedshift, // user defined class 'movk64_imm_asmoperand'
  MCK_MOVN32MovAlias, // user defined class 'movn32_asmoperand'
  MCK_MOVN32Shiftedshift, // user defined class 'movn32_imm_asmoperand'
  MCK_MOVN64MovAlias, // user defined class 'movn64_asmoperand'
  MCK_MOVN64Shiftedshift, // user defined class 'movn64_imm_asmoperand'
  MCK_MOVZ32MovAlias, // user defined class 'movz32_asmoperand'
  MCK_MOVZ32Shiftedshift, // user defined class 'movz32_imm_asmoperand'
  MCK_MOVZ64MovAlias, // user defined class 'movz64_asmoperand'
  MCK_MOVZ64Shiftedshift, // user defined class 'movz64_imm_asmoperand'
  MCK_MRS, // user defined class 'mrs_asmoperand'
  MCK_MSRWithReg, // user defined class 'msr_asmoperand'
  MCK_NeonMovImmShiftLSLH, // user defined class 'neon_mov_imm_LSLH_asmoperand'
  MCK_NeonMovImmShiftLSL, // user defined class 'neon_mov_imm_LSL_asmoperand'
  MCK_NeonMovImmShiftMSL, // user defined class 'neon_mov_imm_MSL_asmoperand'
  MCK_UImm0, // user defined class 'neon_uimm0_asmoperand'
  MCK_UImm1, // user defined class 'neon_uimm1_asmoperand'
  MCK_UImm2, // user defined class 'neon_uimm2_asmoperand'
  MCK_NeonUImm64Mask, // user defined class 'neon_uimm64_mask_asmoperand'
  MCK_UImm8, // user defined class 'neon_uimm8_asmoperand'
  MCK_NamedImmprefetch, // user defined class 'prefetch_asmoperand'
  MCK_MSRPState, // user defined class 'pstate_asmoperand'
  MCK_AddrRegExtend_16_Wm, // user defined class 'qword_Wm_regext_asmoperand'
  MCK_AddrRegExtend_16_Xm, // user defined class 'qword_Xm_regext_asmoperand'
  MCK_SImm7_Scaled16, // user defined class 'qword_simm7_asmoperand'
  MCK_OffsetUImm12_16, // user defined class 'qword_uimm12_asmoperand'
  MCK_ShiftRORi32, // user defined class 'ror_operand_asmoperand_i32'
  MCK_ShiftRORi64, // user defined class 'ror_operand_asmoperand_i64'
  MCK_ShlImm16, // user defined class 'shl_imm16_asmoperand'
  MCK_ShlImm32, // user defined class 'shl_imm32_asmoperand'
  MCK_ShlImm64, // user defined class 'shl_imm64_asmoperand'
  MCK_ShlImm8, // user defined class 'shl_imm8_asmoperand'
  MCK_ShrImm16, // user defined class 'shr_imm16_asmoperand'
  MCK_ShrImm32, // user defined class 'shr_imm32_asmoperand'
  MCK_ShrImm64, // user defined class 'shr_imm64_asmoperand'
  MCK_ShrImm8, // user defined class 'shr_imm8_asmoperand'
  MCK_SImm9, // user defined class 'simm9_asmoperand'
  MCK_NamedImmtlbi, // user defined class 'tlbi_asmoperand'
  MCK_UImm16, // user defined class 'uimm16_asmoperand'
  MCK_UImm3, // user defined class 'uimm3_asmoperand'
  MCK_UImm4, // user defined class 'uimm4_asmoperand'
  MCK_UImm5, // user defined class 'uimm5_asmoperand'
  MCK_UImm6, // user defined class 'uimm6_asmoperand'
  MCK_UImm7, // user defined class 'uimm7_asmoperand'
  MCK_AddrRegExtend_4_Wm, // user defined class 'word_Wm_regext_asmoperand'
  MCK_AddrRegExtend_4_Xm, // user defined class 'word_Xm_regext_asmoperand'
  MCK_SImm7_Scaled4, // user defined class 'word_simm7_asmoperand'
  MCK_OffsetUImm12_4, // user defined class 'word_uimm12_asmoperand'
  NumMatchClassKinds
};

}

static MatchClassKind matchTokenString(StringRef Name) {
  switch (Name.size()) {
  default: break;
  case 1:	 // 4 strings to match.
    switch (Name[0]) {
    default: break;
    case '!':	 // 1 string to match.
      return MCK__EXCLAIM_;	 // "!"
    case '.':	 // 1 string to match.
      return MCK__DOT_;	 // "."
    case '[':	 // 1 string to match.
      return MCK__91_;	 // "["
    case ']':	 // 1 string to match.
      return MCK__93_;	 // "]"
    }
    break;
  case 2:	 // 4 strings to match.
    if (Name[0] != '.')
      break;
    switch (Name[1]) {
    default: break;
    case 'b':	 // 1 string to match.
      return MCK__DOT_b;	 // ".b"
    case 'd':	 // 1 string to match.
      return MCK__DOT_d;	 // ".d"
    case 'h':	 // 1 string to match.
      return MCK__DOT_h;	 // ".h"
    case 's':	 // 1 string to match.
      return MCK__DOT_s;	 // ".s"
    }
    break;
  case 3:	 // 8 strings to match.
    if (Name[0] != '.')
      break;
    switch (Name[1]) {
    default: break;
    case '1':	 // 2 strings to match.
      switch (Name[2]) {
      default: break;
      case 'd':	 // 1 string to match.
        return MCK__DOT_1d;	 // ".1d"
      case 'q':	 // 1 string to match.
        return MCK__DOT_1q;	 // ".1q"
      }
      break;
    case '2':	 // 2 strings to match.
      switch (Name[2]) {
      default: break;
      case 'd':	 // 1 string to match.
        return MCK__DOT_2d;	 // ".2d"
      case 's':	 // 1 string to match.
        return MCK__DOT_2s;	 // ".2s"
      }
      break;
    case '4':	 // 2 strings to match.
      switch (Name[2]) {
      default: break;
      case 'h':	 // 1 string to match.
        return MCK__DOT_4h;	 // ".4h"
      case 's':	 // 1 string to match.
        return MCK__DOT_4s;	 // ".4s"
      }
      break;
    case '8':	 // 2 strings to match.
      switch (Name[2]) {
      default: break;
      case 'b':	 // 1 string to match.
        return MCK__DOT_8b;	 // ".8b"
      case 'h':	 // 1 string to match.
        return MCK__DOT_8h;	 // ".8h"
      }
      break;
    }
    break;
  case 4:	 // 1 string to match.
    if (memcmp(Name.data()+0, ".16b", 4))
      break;
    return MCK__DOT_16b;	 // ".16b"
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

  case MCK_GPR32nowzr:
    switch (B) {
    default: return false;
    case MCK_GPR32: return true;
    case MCK_GPR32wsp: return true;
    }

  case MCK_Rwsp:
    return B == MCK_GPR32wsp;

  case MCK_tcGPR64:
    switch (B) {
    default: return false;
    case MCK_GPR64noxzr: return true;
    case MCK_GPR64: return true;
    case MCK_GPR64xsp: return true;
    }

  case MCK_GPR64noxzr:
    switch (B) {
    default: return false;
    case MCK_GPR64: return true;
    case MCK_GPR64xsp: return true;
    }

  case MCK_Rxsp:
    return B == MCK_GPR64xsp;

  case MCK_FPR64Lo:
    return B == MCK_FPR64;

  case MCK_FPR128Lo:
    return B == MCK_FPR128;

  case MCK_Reg17:
    switch (B) {
    default: return false;
    case MCK_Reg20: return true;
    case MCK_Reg18: return true;
    case MCK_DPair: return true;
    }

  case MCK_Reg20:
    return B == MCK_DPair;

  case MCK_Reg18:
    return B == MCK_DPair;

  case MCK_Reg21:
    switch (B) {
    default: return false;
    case MCK_Reg22: return true;
    case MCK_Reg24: return true;
    case MCK_QPair: return true;
    }

  case MCK_Reg22:
    return B == MCK_QPair;

  case MCK_Reg24:
    return B == MCK_QPair;

  case MCK_Reg25:
    switch (B) {
    default: return false;
    case MCK_Reg26: return true;
    case MCK_Reg27: return true;
    case MCK_Reg31: return true;
    case MCK_Reg29: return true;
    case MCK_Reg30: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg26:
    switch (B) {
    default: return false;
    case MCK_Reg27: return true;
    case MCK_Reg29: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg27:
    return B == MCK_DTriple;

  case MCK_Reg31:
    switch (B) {
    default: return false;
    case MCK_Reg29: return true;
    case MCK_Reg30: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg29:
    return B == MCK_DTriple;

  case MCK_Reg30:
    return B == MCK_DTriple;

  case MCK_Reg32:
    switch (B) {
    default: return false;
    case MCK_Reg38: return true;
    case MCK_Reg33: return true;
    case MCK_Reg34: return true;
    case MCK_Reg36: return true;
    case MCK_Reg37: return true;
    case MCK_QTriple: return true;
    }

  case MCK_Reg38:
    switch (B) {
    default: return false;
    case MCK_Reg36: return true;
    case MCK_Reg37: return true;
    case MCK_QTriple: return true;
    }

  case MCK_Reg33:
    switch (B) {
    default: return false;
    case MCK_Reg34: return true;
    case MCK_Reg36: return true;
    case MCK_QTriple: return true;
    }

  case MCK_Reg34:
    return B == MCK_QTriple;

  case MCK_Reg36:
    return B == MCK_QTriple;

  case MCK_Reg37:
    return B == MCK_QTriple;

  case MCK_Reg39:
    switch (B) {
    default: return false;
    case MCK_Reg40: return true;
    case MCK_Reg41: return true;
    case MCK_Reg42: return true;
    case MCK_Reg49: return true;
    case MCK_Reg46: return true;
    case MCK_Reg44: return true;
    case MCK_Reg48: return true;
    case MCK_Reg45: return true;
    case MCK_Reg47: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg40:
    switch (B) {
    default: return false;
    case MCK_Reg41: return true;
    case MCK_Reg42: return true;
    case MCK_Reg46: return true;
    case MCK_Reg44: return true;
    case MCK_Reg45: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg41:
    switch (B) {
    default: return false;
    case MCK_Reg42: return true;
    case MCK_Reg44: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg42:
    return B == MCK_DQuad;

  case MCK_Reg49:
    switch (B) {
    default: return false;
    case MCK_Reg46: return true;
    case MCK_Reg44: return true;
    case MCK_Reg48: return true;
    case MCK_Reg45: return true;
    case MCK_Reg47: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg46:
    switch (B) {
    default: return false;
    case MCK_Reg44: return true;
    case MCK_Reg45: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg44:
    return B == MCK_DQuad;

  case MCK_Reg48:
    switch (B) {
    default: return false;
    case MCK_Reg45: return true;
    case MCK_Reg47: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg45:
    return B == MCK_DQuad;

  case MCK_Reg47:
    return B == MCK_DQuad;

  case MCK_Reg50:
    switch (B) {
    default: return false;
    case MCK_Reg60: return true;
    case MCK_Reg51: return true;
    case MCK_Reg52: return true;
    case MCK_Reg53: return true;
    case MCK_Reg59: return true;
    case MCK_Reg58: return true;
    case MCK_Reg57: return true;
    case MCK_Reg56: return true;
    case MCK_Reg55: return true;
    case MCK_QQuad: return true;
    }

  case MCK_Reg60:
    switch (B) {
    default: return false;
    case MCK_Reg59: return true;
    case MCK_Reg58: return true;
    case MCK_Reg57: return true;
    case MCK_Reg56: return true;
    case MCK_Reg55: return true;
    case MCK_QQuad: return true;
    }

  case MCK_Reg51:
    switch (B) {
    default: return false;
    case MCK_Reg52: return true;
    case MCK_Reg53: return true;
    case MCK_Reg57: return true;
    case MCK_Reg56: return true;
    case MCK_Reg55: return true;
    case MCK_QQuad: return true;
    }

  case MCK_Reg52:
    switch (B) {
    default: return false;
    case MCK_Reg53: return true;
    case MCK_Reg55: return true;
    case MCK_QQuad: return true;
    }

  case MCK_Reg53:
    return B == MCK_QQuad;

  case MCK_Reg59:
    switch (B) {
    default: return false;
    case MCK_Reg58: return true;
    case MCK_Reg56: return true;
    case MCK_QQuad: return true;
    }

  case MCK_Reg58:
    return B == MCK_QQuad;

  case MCK_Reg57:
    switch (B) {
    default: return false;
    case MCK_Reg56: return true;
    case MCK_Reg55: return true;
    case MCK_QQuad: return true;
    }

  case MCK_Reg56:
    return B == MCK_QQuad;

  case MCK_Reg55:
    return B == MCK_QQuad;
  }
}

static unsigned validateOperandClass(MCParsedAsmOperand *GOp, MatchClassKind Kind) {
  AArch64Operand &Operand = *(AArch64Operand*)GOp;
  if (Kind == InvalidMatchClass)
    return MCTargetAsmParser::Match_InvalidOperand;

  if (Operand.isToken())
    return isSubclass(matchTokenString(Operand.getToken()), Kind) ?
             MCTargetAsmParser::Match_Success :
             MCTargetAsmParser::Match_InvalidOperand;

  // 'CRx' class
  if (Kind == MCK_CRx) {
    if (Operand.isUImm<4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'GPR64xsp0' class
  if (Kind == MCK_GPR64xsp0) {
    if (Operand.isWrappedReg())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm' class
  if (Kind == MCK_Imm) {
    if (Operand.isImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegExtendLSL' class
  if (Kind == MCK_RegExtendLSL) {
    if (Operand.isRegExtendLSL())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegExtendLarge;
  }

  // 'SXTB' class
  if (Kind == MCK_SXTB) {
    if (Operand.isRegExtend<A64SE::SXTB>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegExtendSmall;
  }

  // 'SXTH' class
  if (Kind == MCK_SXTH) {
    if (Operand.isRegExtend<A64SE::SXTH>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegExtendSmall;
  }

  // 'SXTW' class
  if (Kind == MCK_SXTW) {
    if (Operand.isRegExtend<A64SE::SXTW>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegExtendSmall;
  }

  // 'SXTX' class
  if (Kind == MCK_SXTX) {
    if (Operand.isRegExtend<A64SE::SXTX>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegExtendLarge;
  }

  // 'UXTB' class
  if (Kind == MCK_UXTB) {
    if (Operand.isRegExtend<A64SE::UXTB>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegExtendSmall;
  }

  // 'UXTH' class
  if (Kind == MCK_UXTH) {
    if (Operand.isRegExtend<A64SE::UXTH>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegExtendSmall;
  }

  // 'UXTW' class
  if (Kind == MCK_UXTW) {
    if (Operand.isRegExtend<A64SE::UXTW>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegExtendSmall;
  }

  // 'UXTX' class
  if (Kind == MCK_UXTX) {
    if (Operand.isRegExtend<A64SE::UXTX>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegExtendLarge;
  }

  // 'VOne16B1' class
  if (Kind == MCK_VOne16B1) {
    if (Operand.isVectorList<A64Layout::VL_16B, 1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VOne1D1' class
  if (Kind == MCK_VOne1D1) {
    if (Operand.isVectorList<A64Layout::VL_1D, 1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VOne2D1' class
  if (Kind == MCK_VOne2D1) {
    if (Operand.isVectorList<A64Layout::VL_2D, 1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VOne2S1' class
  if (Kind == MCK_VOne2S1) {
    if (Operand.isVectorList<A64Layout::VL_2S, 1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VOne4H1' class
  if (Kind == MCK_VOne4H1) {
    if (Operand.isVectorList<A64Layout::VL_4H, 1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VOne4S1' class
  if (Kind == MCK_VOne4S1) {
    if (Operand.isVectorList<A64Layout::VL_4S, 1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VOne8B1' class
  if (Kind == MCK_VOne8B1) {
    if (Operand.isVectorList<A64Layout::VL_8B, 1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VOne8H1' class
  if (Kind == MCK_VOne8H1) {
    if (Operand.isVectorList<A64Layout::VL_8H, 1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VOneB1' class
  if (Kind == MCK_VOneB1) {
    if (Operand.isVectorList<A64Layout::VL_B, 1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VOneD1' class
  if (Kind == MCK_VOneD1) {
    if (Operand.isVectorList<A64Layout::VL_D, 1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VOneH1' class
  if (Kind == MCK_VOneH1) {
    if (Operand.isVectorList<A64Layout::VL_H, 1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VOneS1' class
  if (Kind == MCK_VOneS1) {
    if (Operand.isVectorList<A64Layout::VL_S, 1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VPR' class
  if (Kind == MCK_VPR) {
    if (Operand.isReg())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VPair16B2' class
  if (Kind == MCK_VPair16B2) {
    if (Operand.isVectorList<A64Layout::VL_16B, 2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VPair1D2' class
  if (Kind == MCK_VPair1D2) {
    if (Operand.isVectorList<A64Layout::VL_1D, 2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VPair2D2' class
  if (Kind == MCK_VPair2D2) {
    if (Operand.isVectorList<A64Layout::VL_2D, 2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VPair2S2' class
  if (Kind == MCK_VPair2S2) {
    if (Operand.isVectorList<A64Layout::VL_2S, 2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VPair4H2' class
  if (Kind == MCK_VPair4H2) {
    if (Operand.isVectorList<A64Layout::VL_4H, 2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VPair4S2' class
  if (Kind == MCK_VPair4S2) {
    if (Operand.isVectorList<A64Layout::VL_4S, 2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VPair8B2' class
  if (Kind == MCK_VPair8B2) {
    if (Operand.isVectorList<A64Layout::VL_8B, 2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VPair8H2' class
  if (Kind == MCK_VPair8H2) {
    if (Operand.isVectorList<A64Layout::VL_8H, 2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VPairB2' class
  if (Kind == MCK_VPairB2) {
    if (Operand.isVectorList<A64Layout::VL_B, 2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VPairD2' class
  if (Kind == MCK_VPairD2) {
    if (Operand.isVectorList<A64Layout::VL_D, 2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VPairH2' class
  if (Kind == MCK_VPairH2) {
    if (Operand.isVectorList<A64Layout::VL_H, 2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VPairS2' class
  if (Kind == MCK_VPairS2) {
    if (Operand.isVectorList<A64Layout::VL_S, 2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VQuad16B4' class
  if (Kind == MCK_VQuad16B4) {
    if (Operand.isVectorList<A64Layout::VL_16B, 4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VQuad1D4' class
  if (Kind == MCK_VQuad1D4) {
    if (Operand.isVectorList<A64Layout::VL_1D, 4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VQuad2D4' class
  if (Kind == MCK_VQuad2D4) {
    if (Operand.isVectorList<A64Layout::VL_2D, 4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VQuad2S4' class
  if (Kind == MCK_VQuad2S4) {
    if (Operand.isVectorList<A64Layout::VL_2S, 4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VQuad4H4' class
  if (Kind == MCK_VQuad4H4) {
    if (Operand.isVectorList<A64Layout::VL_4H, 4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VQuad4S4' class
  if (Kind == MCK_VQuad4S4) {
    if (Operand.isVectorList<A64Layout::VL_4S, 4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VQuad8B4' class
  if (Kind == MCK_VQuad8B4) {
    if (Operand.isVectorList<A64Layout::VL_8B, 4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VQuad8H4' class
  if (Kind == MCK_VQuad8H4) {
    if (Operand.isVectorList<A64Layout::VL_8H, 4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VQuadB4' class
  if (Kind == MCK_VQuadB4) {
    if (Operand.isVectorList<A64Layout::VL_B, 4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VQuadD4' class
  if (Kind == MCK_VQuadD4) {
    if (Operand.isVectorList<A64Layout::VL_D, 4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VQuadH4' class
  if (Kind == MCK_VQuadH4) {
    if (Operand.isVectorList<A64Layout::VL_H, 4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VQuadS4' class
  if (Kind == MCK_VQuadS4) {
    if (Operand.isVectorList<A64Layout::VL_S, 4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VTriple16B3' class
  if (Kind == MCK_VTriple16B3) {
    if (Operand.isVectorList<A64Layout::VL_16B, 3>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VTriple1D3' class
  if (Kind == MCK_VTriple1D3) {
    if (Operand.isVectorList<A64Layout::VL_1D, 3>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VTriple2D3' class
  if (Kind == MCK_VTriple2D3) {
    if (Operand.isVectorList<A64Layout::VL_2D, 3>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VTriple2S3' class
  if (Kind == MCK_VTriple2S3) {
    if (Operand.isVectorList<A64Layout::VL_2S, 3>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VTriple4H3' class
  if (Kind == MCK_VTriple4H3) {
    if (Operand.isVectorList<A64Layout::VL_4H, 3>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VTriple4S3' class
  if (Kind == MCK_VTriple4S3) {
    if (Operand.isVectorList<A64Layout::VL_4S, 3>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VTriple8B3' class
  if (Kind == MCK_VTriple8B3) {
    if (Operand.isVectorList<A64Layout::VL_8B, 3>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VTriple8H3' class
  if (Kind == MCK_VTriple8H3) {
    if (Operand.isVectorList<A64Layout::VL_8H, 3>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VTripleB3' class
  if (Kind == MCK_VTripleB3) {
    if (Operand.isVectorList<A64Layout::VL_B, 3>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VTripleD3' class
  if (Kind == MCK_VTripleD3) {
    if (Operand.isVectorList<A64Layout::VL_D, 3>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VTripleH3' class
  if (Kind == MCK_VTripleH3) {
    if (Operand.isVectorList<A64Layout::VL_H, 3>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VTripleS3' class
  if (Kind == MCK_VTripleS3) {
    if (Operand.isVectorList<A64Layout::VL_S, 3>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'AddSubImmLSL0' class
  if (Kind == MCK_AddSubImmLSL0) {
    if (Operand.isAddSubImmLSL0())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubSecondSource;
  }

  // 'AddSubImmLSL12' class
  if (Kind == MCK_AddSubImmLSL12) {
    if (Operand.isAddSubImmLSL12())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubSecondSource;
  }

  // 'AdrpLabel' class
  if (Kind == MCK_AdrpLabel) {
    if (Operand.isAdrpLabel())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_Label;
  }

  // 'Label21_1' class
  if (Kind == MCK_Label21_1) {
    if (Operand.isLabel<21,1>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_Label;
  }

  // 'ShiftASRi32' class
  if (Kind == MCK_ShiftASRi32) {
    if (Operand.isShift<A64SE::ASR, false>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegShift32;
  }

  // 'ShiftASRi64' class
  if (Kind == MCK_ShiftASRi64) {
    if (Operand.isShift<A64SE::ASR, true>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegShift64;
  }

  // 'NamedImmat' class
  if (Kind == MCK_NamedImmat) {
    if (Operand.isUImm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_NamedImm_at;
  }

  // 'BFI32LSB' class
  if (Kind == MCK_BFI32LSB) {
    if (Operand.isUImm<5>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_UImm5;
  }

  // 'BFI32Width' class
  if (Kind == MCK_BFI32Width) {
    if (Operand.isBitfieldWidth<32>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_Width32;
  }

  // 'BFI64LSB' class
  if (Kind == MCK_BFI64LSB) {
    if (Operand.isUImm<6>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_UImm6;
  }

  // 'BFI64Width' class
  if (Kind == MCK_BFI64Width) {
    if (Operand.isBitfieldWidth<64>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_Width64;
  }

  // 'BFX32Width' class
  if (Kind == MCK_BFX32Width) {
    if (Operand.isBitfieldWidth<32>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_Width32;
  }

  // 'BFX64Width' class
  if (Kind == MCK_BFX64Width) {
    if (Operand.isBitfieldWidth<64>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_Width64;
  }

  // 'AddrRegExtend_1_Wm' class
  if (Kind == MCK_AddrRegExtend_1_Wm) {
    if (Operand.isAddrRegExtend<1,32>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreExtend32_1;
  }

  // 'AddrRegExtend_1_Xm' class
  if (Kind == MCK_AddrRegExtend_1_Xm) {
    if (Operand.isAddrRegExtend<1,64>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreExtend64_1;
  }

  // 'OffsetUImm12_1' class
  if (Kind == MCK_OffsetUImm12_1) {
    if (Operand.isOffsetUImm12<1>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreUImm12_1;
  }

  // 'CondCode' class
  if (Kind == MCK_CondCode) {
    if (Operand.isCondCode())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_CondCode;
  }

  // 'CondCodeOp' class
  if (Kind == MCK_CondCodeOp) {
    if (Operand.isCondCode())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_CondCode;
  }

  // 'NamedImmdbarrier' class
  if (Kind == MCK_NamedImmdbarrier) {
    if (Operand.isUImm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_NamedImm_dbarrier;
  }

  // 'NamedImmdc' class
  if (Kind == MCK_NamedImmdc) {
    if (Operand.isUImm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_NamedImm_dc;
  }

  // 'AddrRegExtend_8_Wm' class
  if (Kind == MCK_AddrRegExtend_8_Wm) {
    if (Operand.isAddrRegExtend<8,32>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreExtend32_8;
  }

  // 'AddrRegExtend_8_Xm' class
  if (Kind == MCK_AddrRegExtend_8_Xm) {
    if (Operand.isAddrRegExtend<8,64>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreExtend64_8;
  }

  // 'SImm7_Scaled8' class
  if (Kind == MCK_SImm7_Scaled8) {
    if (Operand.isSImm7Scaled<8>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreSImm7_8;
  }

  // 'OffsetUImm12_8' class
  if (Kind == MCK_OffsetUImm12_8) {
    if (Operand.isOffsetUImm12<8>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreUImm12_8;
  }

  // 'Exact12' class
  if (Kind == MCK_Exact12) {
    if (Operand.isExactImm<12>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Exact16' class
  if (Kind == MCK_Exact16) {
    if (Operand.isExactImm<16>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Exact1' class
  if (Kind == MCK_Exact1) {
    if (Operand.isExactImm<1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Exact24' class
  if (Kind == MCK_Exact24) {
    if (Operand.isExactImm<24>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Exact2' class
  if (Kind == MCK_Exact2) {
    if (Operand.isExactImm<2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Exact32' class
  if (Kind == MCK_Exact32) {
    if (Operand.isExactImm<32>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Exact3' class
  if (Kind == MCK_Exact3) {
    if (Operand.isExactImm<3>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Exact48' class
  if (Kind == MCK_Exact48) {
    if (Operand.isExactImm<48>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Exact4' class
  if (Kind == MCK_Exact4) {
    if (Operand.isExactImm<4>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Exact64' class
  if (Kind == MCK_Exact64) {
    if (Operand.isExactImm<64>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Exact6' class
  if (Kind == MCK_Exact6) {
    if (Operand.isExactImm<6>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Exact8' class
  if (Kind == MCK_Exact8) {
    if (Operand.isExactImm<8>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'CVTFixedPos32' class
  if (Kind == MCK_CVTFixedPos32) {
    if (Operand.isCVTFixedPos<32>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_CVTFixedPos32;
  }

  // 'CVTFixedPos64' class
  if (Kind == MCK_CVTFixedPos64) {
    if (Operand.isCVTFixedPos<64>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_CVTFixedPos64;
  }

  // 'FMOVImm' class
  if (Kind == MCK_FMOVImm) {
    if (Operand.isFMOVImm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_FPImm;
  }

  // 'FPZero' class
  if (Kind == MCK_FPZero) {
    if (Operand.isFPZero())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_FPZero;
  }

  // 'AddrRegExtend_2_Wm' class
  if (Kind == MCK_AddrRegExtend_2_Wm) {
    if (Operand.isAddrRegExtend<2,32>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreExtend32_2;
  }

  // 'AddrRegExtend_2_Xm' class
  if (Kind == MCK_AddrRegExtend_2_Xm) {
    if (Operand.isAddrRegExtend<2,64>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreExtend64_2;
  }

  // 'OffsetUImm12_2' class
  if (Kind == MCK_OffsetUImm12_2) {
    if (Operand.isOffsetUImm12<2>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreUImm12_2;
  }

  // 'NamedImmic' class
  if (Kind == MCK_NamedImmic) {
    if (Operand.isUImm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_NamedImm_ic;
  }

  // 'InvCondCodeOp' class
  if (Kind == MCK_InvCondCodeOp) {
    if (Operand.isCondCode())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_CondCode;
  }

  // 'NamedImmisb' class
  if (Kind == MCK_NamedImmisb) {
    if (Operand.isUImm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_NamedImm_isb;
  }

  // 'Label14_4' class
  if (Kind == MCK_Label14_4) {
    if (Operand.isLabel<14,4>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_Label;
  }

  // 'Label19_4' class
  if (Kind == MCK_Label19_4) {
    if (Operand.isLabel<19,4>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_Label;
  }

  // 'Label26_4' class
  if (Kind == MCK_Label26_4) {
    if (Operand.isLabel<26,4>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_Label;
  }

  // 'Lane1' class
  if (Kind == MCK_Lane1) {
    if (Operand.isLane1())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_Lane1;
  }

  // 'LoadLitLabel' class
  if (Kind == MCK_LoadLitLabel) {
    if (Operand.isLoadLitLabel())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_Label;
  }

  // 'LogicalImm32' class
  if (Kind == MCK_LogicalImm32) {
    if (Operand.isLogicalImm<32>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LogicalSecondSource;
  }

  // 'LogicalImmMOV32' class
  if (Kind == MCK_LogicalImmMOV32) {
    if (Operand.isLogicalImmMOV<32>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LogicalSecondSource;
  }

  // 'LogicalImm64' class
  if (Kind == MCK_LogicalImm64) {
    if (Operand.isLogicalImm<64>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LogicalSecondSource;
  }

  // 'LogicalImmMOV64' class
  if (Kind == MCK_LogicalImmMOV64) {
    if (Operand.isLogicalImmMOV<64>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LogicalSecondSource;
  }

  // 'ShiftLSLi32' class
  if (Kind == MCK_ShiftLSLi32) {
    if (Operand.isShift<A64SE::LSL, false>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegShift32;
  }

  // 'ShiftLSLi64' class
  if (Kind == MCK_ShiftLSLi64) {
    if (Operand.isShift<A64SE::LSL, true>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegShift64;
  }

  // 'ShiftLSRi32' class
  if (Kind == MCK_ShiftLSRi32) {
    if (Operand.isShift<A64SE::LSR, false>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegShift32;
  }

  // 'ShiftLSRi64' class
  if (Kind == MCK_ShiftLSRi64) {
    if (Operand.isShift<A64SE::LSR, true>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegShift64;
  }

  // 'MOVK32Shiftedshift' class
  if (Kind == MCK_MOVK32Shiftedshift) {
    if (Operand.isMOVK32Imm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_MOVWUImm16;
  }

  // 'MOVK64Shiftedshift' class
  if (Kind == MCK_MOVK64Shiftedshift) {
    if (Operand.isMOVK64Imm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_MOVWUImm16;
  }

  // 'MOVN32MovAlias' class
  if (Kind == MCK_MOVN32MovAlias) {
    if (Operand.isMoveWideMovAlias<32, A64Imms::isOnlyMOVNImm>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MOVN32Shiftedshift' class
  if (Kind == MCK_MOVN32Shiftedshift) {
    if (Operand.isMOVN32Imm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_MOVWUImm16;
  }

  // 'MOVN64MovAlias' class
  if (Kind == MCK_MOVN64MovAlias) {
    if (Operand.isMoveWideMovAlias<64, A64Imms::isOnlyMOVNImm>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MOVN64Shiftedshift' class
  if (Kind == MCK_MOVN64Shiftedshift) {
    if (Operand.isMOVN64Imm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_MOVWUImm16;
  }

  // 'MOVZ32MovAlias' class
  if (Kind == MCK_MOVZ32MovAlias) {
    if (Operand.isMoveWideMovAlias<32, A64Imms::isMOVZImm>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MOVZ32Shiftedshift' class
  if (Kind == MCK_MOVZ32Shiftedshift) {
    if (Operand.isMOVZ32Imm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_MOVWUImm16;
  }

  // 'MOVZ64MovAlias' class
  if (Kind == MCK_MOVZ64MovAlias) {
    if (Operand.isMoveWideMovAlias<64, A64Imms::isMOVZImm>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MOVZ64Shiftedshift' class
  if (Kind == MCK_MOVZ64Shiftedshift) {
    if (Operand.isMOVZ64Imm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_MOVWUImm16;
  }

  // 'MRS' class
  if (Kind == MCK_MRS) {
    if (Operand.isMRS())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_MRS;
  }

  // 'MSRWithReg' class
  if (Kind == MCK_MSRWithReg) {
    if (Operand.isMSRWithReg())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_MSR;
  }

  // 'NeonMovImmShiftLSLH' class
  if (Kind == MCK_NeonMovImmShiftLSLH) {
    if (Operand.isNeonMovImmShiftLSLH())
      return MCTargetAsmParser::Match_Success;
  }

  // 'NeonMovImmShiftLSL' class
  if (Kind == MCK_NeonMovImmShiftLSL) {
    if (Operand.isNeonMovImmShiftLSL())
      return MCTargetAsmParser::Match_Success;
  }

  // 'NeonMovImmShiftMSL' class
  if (Kind == MCK_NeonMovImmShiftMSL) {
    if (Operand.isNeonMovImmShiftMSL())
      return MCTargetAsmParser::Match_Success;
  }

  // 'UImm0' class
  if (Kind == MCK_UImm0) {
    if (Operand.isUImm<0>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'UImm1' class
  if (Kind == MCK_UImm1) {
    if (Operand.isUImm<1>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'UImm2' class
  if (Kind == MCK_UImm2) {
    if (Operand.isUImm<2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'NeonUImm64Mask' class
  if (Kind == MCK_NeonUImm64Mask) {
    if (Operand.isNeonUImm64Mask())
      return MCTargetAsmParser::Match_Success;
  }

  // 'UImm8' class
  if (Kind == MCK_UImm8) {
    if (Operand.isUImm<8>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'NamedImmprefetch' class
  if (Kind == MCK_NamedImmprefetch) {
    if (Operand.isUImm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_NamedImm_prefetch;
  }

  // 'MSRPState' class
  if (Kind == MCK_MSRPState) {
    if (Operand.isMSRPState())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_MSR;
  }

  // 'AddrRegExtend_16_Wm' class
  if (Kind == MCK_AddrRegExtend_16_Wm) {
    if (Operand.isAddrRegExtend<16,32>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreExtend32_16;
  }

  // 'AddrRegExtend_16_Xm' class
  if (Kind == MCK_AddrRegExtend_16_Xm) {
    if (Operand.isAddrRegExtend<16,64>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreExtend64_16;
  }

  // 'SImm7_Scaled16' class
  if (Kind == MCK_SImm7_Scaled16) {
    if (Operand.isSImm7Scaled<16>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreSImm7_16;
  }

  // 'OffsetUImm12_16' class
  if (Kind == MCK_OffsetUImm12_16) {
    if (Operand.isOffsetUImm12<16>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreUImm12_16;
  }

  // 'ShiftRORi32' class
  if (Kind == MCK_ShiftRORi32) {
    if (Operand.isShift<A64SE::ROR, false>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegShift32;
  }

  // 'ShiftRORi64' class
  if (Kind == MCK_ShiftRORi64) {
    if (Operand.isShift<A64SE::ROR, true>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_AddSubRegShift64;
  }

  // 'ShlImm16' class
  if (Kind == MCK_ShlImm16) {
    if (Operand.isShlImm16())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_ShlImm16;
  }

  // 'ShlImm32' class
  if (Kind == MCK_ShlImm32) {
    if (Operand.isShlImm32())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_ShlImm32;
  }

  // 'ShlImm64' class
  if (Kind == MCK_ShlImm64) {
    if (Operand.isShlImm64())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_ShlImm64;
  }

  // 'ShlImm8' class
  if (Kind == MCK_ShlImm8) {
    if (Operand.isShlImm8())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_ShlImm8;
  }

  // 'ShrImm16' class
  if (Kind == MCK_ShrImm16) {
    if (Operand.isShrImm16())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_ShrImm16;
  }

  // 'ShrImm32' class
  if (Kind == MCK_ShrImm32) {
    if (Operand.isShrImm32())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_ShrImm32;
  }

  // 'ShrImm64' class
  if (Kind == MCK_ShrImm64) {
    if (Operand.isShrImm64())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_ShrImm64;
  }

  // 'ShrImm8' class
  if (Kind == MCK_ShrImm8) {
    if (Operand.isShrImm8())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_ShrImm8;
  }

  // 'SImm9' class
  if (Kind == MCK_SImm9) {
    if (Operand.isSImm<9>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreSImm9;
  }

  // 'NamedImmtlbi' class
  if (Kind == MCK_NamedImmtlbi) {
    if (Operand.isUImm())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_NamedImm_tlbi;
  }

  // 'UImm16' class
  if (Kind == MCK_UImm16) {
    if (Operand.isUImm<16>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_UImm16;
  }

  // 'UImm3' class
  if (Kind == MCK_UImm3) {
    if (Operand.isUImm<3>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_UImm3;
  }

  // 'UImm4' class
  if (Kind == MCK_UImm4) {
    if (Operand.isUImm<4>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_UImm4;
  }

  // 'UImm5' class
  if (Kind == MCK_UImm5) {
    if (Operand.isUImm<5>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_UImm5;
  }

  // 'UImm6' class
  if (Kind == MCK_UImm6) {
    if (Operand.isUImm<6>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_UImm6;
  }

  // 'UImm7' class
  if (Kind == MCK_UImm7) {
    if (Operand.isUImm<7>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_UImm7;
  }

  // 'AddrRegExtend_4_Wm' class
  if (Kind == MCK_AddrRegExtend_4_Wm) {
    if (Operand.isAddrRegExtend<4,32>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreExtend32_4;
  }

  // 'AddrRegExtend_4_Xm' class
  if (Kind == MCK_AddrRegExtend_4_Xm) {
    if (Operand.isAddrRegExtend<4,64>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreExtend64_4;
  }

  // 'SImm7_Scaled4' class
  if (Kind == MCK_SImm7_Scaled4) {
    if (Operand.isSImm7Scaled<4>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreSImm7_4;
  }

  // 'OffsetUImm12_4' class
  if (Kind == MCK_OffsetUImm12_4) {
    if (Operand.isOffsetUImm12<4>())
      return MCTargetAsmParser::Match_Success;
    return AArch64AsmParser::Match_LoadStoreUImm12_4;
  }

  if (Operand.isReg()) {
    MatchClassKind OpKind;
    switch (Operand.getReg()) {
    default: OpKind = InvalidMatchClass; break;
    case AArch64::W0: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W1: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W2: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W3: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W4: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W5: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W6: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W7: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W8: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W9: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W10: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W11: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W12: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W13: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W14: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W15: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W16: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W17: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W18: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W19: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W20: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W21: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W22: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W23: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W24: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W25: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W26: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W27: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W28: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W29: OpKind = MCK_GPR32nowzr; break;
    case AArch64::W30: OpKind = MCK_GPR32nowzr; break;
    case AArch64::WSP: OpKind = MCK_Rwsp; break;
    case AArch64::WZR: OpKind = MCK_GPR32; break;
    case AArch64::X0: OpKind = MCK_tcGPR64; break;
    case AArch64::X1: OpKind = MCK_tcGPR64; break;
    case AArch64::X2: OpKind = MCK_tcGPR64; break;
    case AArch64::X3: OpKind = MCK_tcGPR64; break;
    case AArch64::X4: OpKind = MCK_tcGPR64; break;
    case AArch64::X5: OpKind = MCK_tcGPR64; break;
    case AArch64::X6: OpKind = MCK_tcGPR64; break;
    case AArch64::X7: OpKind = MCK_tcGPR64; break;
    case AArch64::X8: OpKind = MCK_GPR64noxzr; break;
    case AArch64::X9: OpKind = MCK_tcGPR64; break;
    case AArch64::X10: OpKind = MCK_tcGPR64; break;
    case AArch64::X11: OpKind = MCK_tcGPR64; break;
    case AArch64::X12: OpKind = MCK_tcGPR64; break;
    case AArch64::X13: OpKind = MCK_tcGPR64; break;
    case AArch64::X14: OpKind = MCK_tcGPR64; break;
    case AArch64::X15: OpKind = MCK_tcGPR64; break;
    case AArch64::X16: OpKind = MCK_tcGPR64; break;
    case AArch64::X17: OpKind = MCK_tcGPR64; break;
    case AArch64::X18: OpKind = MCK_tcGPR64; break;
    case AArch64::X19: OpKind = MCK_GPR64noxzr; break;
    case AArch64::X20: OpKind = MCK_GPR64noxzr; break;
    case AArch64::X21: OpKind = MCK_GPR64noxzr; break;
    case AArch64::X22: OpKind = MCK_GPR64noxzr; break;
    case AArch64::X23: OpKind = MCK_GPR64noxzr; break;
    case AArch64::X24: OpKind = MCK_GPR64noxzr; break;
    case AArch64::X25: OpKind = MCK_GPR64noxzr; break;
    case AArch64::X26: OpKind = MCK_GPR64noxzr; break;
    case AArch64::X27: OpKind = MCK_GPR64noxzr; break;
    case AArch64::X28: OpKind = MCK_GPR64noxzr; break;
    case AArch64::X29: OpKind = MCK_GPR64noxzr; break;
    case AArch64::X30: OpKind = MCK_GPR64noxzr; break;
    case AArch64::XSP: OpKind = MCK_Rxsp; break;
    case AArch64::XZR: OpKind = MCK_GPR64; break;
    case AArch64::B0: OpKind = MCK_FPR8; break;
    case AArch64::B1: OpKind = MCK_FPR8; break;
    case AArch64::B2: OpKind = MCK_FPR8; break;
    case AArch64::B3: OpKind = MCK_FPR8; break;
    case AArch64::B4: OpKind = MCK_FPR8; break;
    case AArch64::B5: OpKind = MCK_FPR8; break;
    case AArch64::B6: OpKind = MCK_FPR8; break;
    case AArch64::B7: OpKind = MCK_FPR8; break;
    case AArch64::B8: OpKind = MCK_FPR8; break;
    case AArch64::B9: OpKind = MCK_FPR8; break;
    case AArch64::B10: OpKind = MCK_FPR8; break;
    case AArch64::B11: OpKind = MCK_FPR8; break;
    case AArch64::B12: OpKind = MCK_FPR8; break;
    case AArch64::B13: OpKind = MCK_FPR8; break;
    case AArch64::B14: OpKind = MCK_FPR8; break;
    case AArch64::B15: OpKind = MCK_FPR8; break;
    case AArch64::B16: OpKind = MCK_FPR8; break;
    case AArch64::B17: OpKind = MCK_FPR8; break;
    case AArch64::B18: OpKind = MCK_FPR8; break;
    case AArch64::B19: OpKind = MCK_FPR8; break;
    case AArch64::B20: OpKind = MCK_FPR8; break;
    case AArch64::B21: OpKind = MCK_FPR8; break;
    case AArch64::B22: OpKind = MCK_FPR8; break;
    case AArch64::B23: OpKind = MCK_FPR8; break;
    case AArch64::B24: OpKind = MCK_FPR8; break;
    case AArch64::B25: OpKind = MCK_FPR8; break;
    case AArch64::B26: OpKind = MCK_FPR8; break;
    case AArch64::B27: OpKind = MCK_FPR8; break;
    case AArch64::B28: OpKind = MCK_FPR8; break;
    case AArch64::B29: OpKind = MCK_FPR8; break;
    case AArch64::B30: OpKind = MCK_FPR8; break;
    case AArch64::B31: OpKind = MCK_FPR8; break;
    case AArch64::H0: OpKind = MCK_FPR16; break;
    case AArch64::H1: OpKind = MCK_FPR16; break;
    case AArch64::H2: OpKind = MCK_FPR16; break;
    case AArch64::H3: OpKind = MCK_FPR16; break;
    case AArch64::H4: OpKind = MCK_FPR16; break;
    case AArch64::H5: OpKind = MCK_FPR16; break;
    case AArch64::H6: OpKind = MCK_FPR16; break;
    case AArch64::H7: OpKind = MCK_FPR16; break;
    case AArch64::H8: OpKind = MCK_FPR16; break;
    case AArch64::H9: OpKind = MCK_FPR16; break;
    case AArch64::H10: OpKind = MCK_FPR16; break;
    case AArch64::H11: OpKind = MCK_FPR16; break;
    case AArch64::H12: OpKind = MCK_FPR16; break;
    case AArch64::H13: OpKind = MCK_FPR16; break;
    case AArch64::H14: OpKind = MCK_FPR16; break;
    case AArch64::H15: OpKind = MCK_FPR16; break;
    case AArch64::H16: OpKind = MCK_FPR16; break;
    case AArch64::H17: OpKind = MCK_FPR16; break;
    case AArch64::H18: OpKind = MCK_FPR16; break;
    case AArch64::H19: OpKind = MCK_FPR16; break;
    case AArch64::H20: OpKind = MCK_FPR16; break;
    case AArch64::H21: OpKind = MCK_FPR16; break;
    case AArch64::H22: OpKind = MCK_FPR16; break;
    case AArch64::H23: OpKind = MCK_FPR16; break;
    case AArch64::H24: OpKind = MCK_FPR16; break;
    case AArch64::H25: OpKind = MCK_FPR16; break;
    case AArch64::H26: OpKind = MCK_FPR16; break;
    case AArch64::H27: OpKind = MCK_FPR16; break;
    case AArch64::H28: OpKind = MCK_FPR16; break;
    case AArch64::H29: OpKind = MCK_FPR16; break;
    case AArch64::H30: OpKind = MCK_FPR16; break;
    case AArch64::H31: OpKind = MCK_FPR16; break;
    case AArch64::S0: OpKind = MCK_FPR32; break;
    case AArch64::S1: OpKind = MCK_FPR32; break;
    case AArch64::S2: OpKind = MCK_FPR32; break;
    case AArch64::S3: OpKind = MCK_FPR32; break;
    case AArch64::S4: OpKind = MCK_FPR32; break;
    case AArch64::S5: OpKind = MCK_FPR32; break;
    case AArch64::S6: OpKind = MCK_FPR32; break;
    case AArch64::S7: OpKind = MCK_FPR32; break;
    case AArch64::S8: OpKind = MCK_FPR32; break;
    case AArch64::S9: OpKind = MCK_FPR32; break;
    case AArch64::S10: OpKind = MCK_FPR32; break;
    case AArch64::S11: OpKind = MCK_FPR32; break;
    case AArch64::S12: OpKind = MCK_FPR32; break;
    case AArch64::S13: OpKind = MCK_FPR32; break;
    case AArch64::S14: OpKind = MCK_FPR32; break;
    case AArch64::S15: OpKind = MCK_FPR32; break;
    case AArch64::S16: OpKind = MCK_FPR32; break;
    case AArch64::S17: OpKind = MCK_FPR32; break;
    case AArch64::S18: OpKind = MCK_FPR32; break;
    case AArch64::S19: OpKind = MCK_FPR32; break;
    case AArch64::S20: OpKind = MCK_FPR32; break;
    case AArch64::S21: OpKind = MCK_FPR32; break;
    case AArch64::S22: OpKind = MCK_FPR32; break;
    case AArch64::S23: OpKind = MCK_FPR32; break;
    case AArch64::S24: OpKind = MCK_FPR32; break;
    case AArch64::S25: OpKind = MCK_FPR32; break;
    case AArch64::S26: OpKind = MCK_FPR32; break;
    case AArch64::S27: OpKind = MCK_FPR32; break;
    case AArch64::S28: OpKind = MCK_FPR32; break;
    case AArch64::S29: OpKind = MCK_FPR32; break;
    case AArch64::S30: OpKind = MCK_FPR32; break;
    case AArch64::S31: OpKind = MCK_FPR32; break;
    case AArch64::D0: OpKind = MCK_FPR64Lo; break;
    case AArch64::D1: OpKind = MCK_FPR64Lo; break;
    case AArch64::D2: OpKind = MCK_FPR64Lo; break;
    case AArch64::D3: OpKind = MCK_FPR64Lo; break;
    case AArch64::D4: OpKind = MCK_FPR64Lo; break;
    case AArch64::D5: OpKind = MCK_FPR64Lo; break;
    case AArch64::D6: OpKind = MCK_FPR64Lo; break;
    case AArch64::D7: OpKind = MCK_FPR64Lo; break;
    case AArch64::D8: OpKind = MCK_FPR64Lo; break;
    case AArch64::D9: OpKind = MCK_FPR64Lo; break;
    case AArch64::D10: OpKind = MCK_FPR64Lo; break;
    case AArch64::D11: OpKind = MCK_FPR64Lo; break;
    case AArch64::D12: OpKind = MCK_FPR64Lo; break;
    case AArch64::D13: OpKind = MCK_FPR64Lo; break;
    case AArch64::D14: OpKind = MCK_FPR64Lo; break;
    case AArch64::D15: OpKind = MCK_FPR64Lo; break;
    case AArch64::D16: OpKind = MCK_FPR64; break;
    case AArch64::D17: OpKind = MCK_FPR64; break;
    case AArch64::D18: OpKind = MCK_FPR64; break;
    case AArch64::D19: OpKind = MCK_FPR64; break;
    case AArch64::D20: OpKind = MCK_FPR64; break;
    case AArch64::D21: OpKind = MCK_FPR64; break;
    case AArch64::D22: OpKind = MCK_FPR64; break;
    case AArch64::D23: OpKind = MCK_FPR64; break;
    case AArch64::D24: OpKind = MCK_FPR64; break;
    case AArch64::D25: OpKind = MCK_FPR64; break;
    case AArch64::D26: OpKind = MCK_FPR64; break;
    case AArch64::D27: OpKind = MCK_FPR64; break;
    case AArch64::D28: OpKind = MCK_FPR64; break;
    case AArch64::D29: OpKind = MCK_FPR64; break;
    case AArch64::D30: OpKind = MCK_FPR64; break;
    case AArch64::D31: OpKind = MCK_FPR64; break;
    case AArch64::Q0: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q1: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q2: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q3: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q4: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q5: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q6: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q7: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q8: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q9: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q10: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q11: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q12: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q13: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q14: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q15: OpKind = MCK_FPR128Lo; break;
    case AArch64::Q16: OpKind = MCK_FPR128; break;
    case AArch64::Q17: OpKind = MCK_FPR128; break;
    case AArch64::Q18: OpKind = MCK_FPR128; break;
    case AArch64::Q19: OpKind = MCK_FPR128; break;
    case AArch64::Q20: OpKind = MCK_FPR128; break;
    case AArch64::Q21: OpKind = MCK_FPR128; break;
    case AArch64::Q22: OpKind = MCK_FPR128; break;
    case AArch64::Q23: OpKind = MCK_FPR128; break;
    case AArch64::Q24: OpKind = MCK_FPR128; break;
    case AArch64::Q25: OpKind = MCK_FPR128; break;
    case AArch64::Q26: OpKind = MCK_FPR128; break;
    case AArch64::Q27: OpKind = MCK_FPR128; break;
    case AArch64::Q28: OpKind = MCK_FPR128; break;
    case AArch64::Q29: OpKind = MCK_FPR128; break;
    case AArch64::Q30: OpKind = MCK_FPR128; break;
    case AArch64::Q31: OpKind = MCK_FPR128; break;
    case AArch64::NZCV: OpKind = MCK_FlagClass; break;
    case AArch64::D0_D1: OpKind = MCK_Reg17; break;
    case AArch64::D1_D2: OpKind = MCK_Reg17; break;
    case AArch64::D2_D3: OpKind = MCK_Reg17; break;
    case AArch64::D3_D4: OpKind = MCK_Reg17; break;
    case AArch64::D4_D5: OpKind = MCK_Reg17; break;
    case AArch64::D5_D6: OpKind = MCK_Reg17; break;
    case AArch64::D6_D7: OpKind = MCK_Reg17; break;
    case AArch64::D7_D8: OpKind = MCK_Reg17; break;
    case AArch64::D8_D9: OpKind = MCK_Reg17; break;
    case AArch64::D9_D10: OpKind = MCK_Reg17; break;
    case AArch64::D10_D11: OpKind = MCK_Reg17; break;
    case AArch64::D11_D12: OpKind = MCK_Reg17; break;
    case AArch64::D12_D13: OpKind = MCK_Reg17; break;
    case AArch64::D13_D14: OpKind = MCK_Reg17; break;
    case AArch64::D14_D15: OpKind = MCK_Reg17; break;
    case AArch64::D15_D16: OpKind = MCK_Reg18; break;
    case AArch64::D16_D17: OpKind = MCK_DPair; break;
    case AArch64::D17_D18: OpKind = MCK_DPair; break;
    case AArch64::D18_D19: OpKind = MCK_DPair; break;
    case AArch64::D19_D20: OpKind = MCK_DPair; break;
    case AArch64::D20_D21: OpKind = MCK_DPair; break;
    case AArch64::D21_D22: OpKind = MCK_DPair; break;
    case AArch64::D22_D23: OpKind = MCK_DPair; break;
    case AArch64::D23_D24: OpKind = MCK_DPair; break;
    case AArch64::D24_D25: OpKind = MCK_DPair; break;
    case AArch64::D25_D26: OpKind = MCK_DPair; break;
    case AArch64::D26_D27: OpKind = MCK_DPair; break;
    case AArch64::D27_D28: OpKind = MCK_DPair; break;
    case AArch64::D28_D29: OpKind = MCK_DPair; break;
    case AArch64::D29_D30: OpKind = MCK_DPair; break;
    case AArch64::D30_D31: OpKind = MCK_DPair; break;
    case AArch64::D31_D0: OpKind = MCK_Reg20; break;
    case AArch64::Q0_Q1: OpKind = MCK_Reg21; break;
    case AArch64::Q1_Q2: OpKind = MCK_Reg21; break;
    case AArch64::Q2_Q3: OpKind = MCK_Reg21; break;
    case AArch64::Q3_Q4: OpKind = MCK_Reg21; break;
    case AArch64::Q4_Q5: OpKind = MCK_Reg21; break;
    case AArch64::Q5_Q6: OpKind = MCK_Reg21; break;
    case AArch64::Q6_Q7: OpKind = MCK_Reg21; break;
    case AArch64::Q7_Q8: OpKind = MCK_Reg21; break;
    case AArch64::Q8_Q9: OpKind = MCK_Reg21; break;
    case AArch64::Q9_Q10: OpKind = MCK_Reg21; break;
    case AArch64::Q10_Q11: OpKind = MCK_Reg21; break;
    case AArch64::Q11_Q12: OpKind = MCK_Reg21; break;
    case AArch64::Q12_Q13: OpKind = MCK_Reg21; break;
    case AArch64::Q13_Q14: OpKind = MCK_Reg21; break;
    case AArch64::Q14_Q15: OpKind = MCK_Reg21; break;
    case AArch64::Q15_Q16: OpKind = MCK_Reg22; break;
    case AArch64::Q16_Q17: OpKind = MCK_QPair; break;
    case AArch64::Q17_Q18: OpKind = MCK_QPair; break;
    case AArch64::Q18_Q19: OpKind = MCK_QPair; break;
    case AArch64::Q19_Q20: OpKind = MCK_QPair; break;
    case AArch64::Q20_Q21: OpKind = MCK_QPair; break;
    case AArch64::Q21_Q22: OpKind = MCK_QPair; break;
    case AArch64::Q22_Q23: OpKind = MCK_QPair; break;
    case AArch64::Q23_Q24: OpKind = MCK_QPair; break;
    case AArch64::Q24_Q25: OpKind = MCK_QPair; break;
    case AArch64::Q25_Q26: OpKind = MCK_QPair; break;
    case AArch64::Q26_Q27: OpKind = MCK_QPair; break;
    case AArch64::Q27_Q28: OpKind = MCK_QPair; break;
    case AArch64::Q28_Q29: OpKind = MCK_QPair; break;
    case AArch64::Q29_Q30: OpKind = MCK_QPair; break;
    case AArch64::Q30_Q31: OpKind = MCK_QPair; break;
    case AArch64::Q31_Q0: OpKind = MCK_Reg24; break;
    case AArch64::D0_D1_D2: OpKind = MCK_Reg25; break;
    case AArch64::D1_D2_D3: OpKind = MCK_Reg25; break;
    case AArch64::D2_D3_D4: OpKind = MCK_Reg25; break;
    case AArch64::D3_D4_D5: OpKind = MCK_Reg25; break;
    case AArch64::D4_D5_D6: OpKind = MCK_Reg25; break;
    case AArch64::D5_D6_D7: OpKind = MCK_Reg25; break;
    case AArch64::D6_D7_D8: OpKind = MCK_Reg25; break;
    case AArch64::D7_D8_D9: OpKind = MCK_Reg25; break;
    case AArch64::D8_D9_D10: OpKind = MCK_Reg25; break;
    case AArch64::D9_D10_D11: OpKind = MCK_Reg25; break;
    case AArch64::D10_D11_D12: OpKind = MCK_Reg25; break;
    case AArch64::D11_D12_D13: OpKind = MCK_Reg25; break;
    case AArch64::D12_D13_D14: OpKind = MCK_Reg25; break;
    case AArch64::D13_D14_D15: OpKind = MCK_Reg25; break;
    case AArch64::D14_D15_D16: OpKind = MCK_Reg26; break;
    case AArch64::D15_D16_D17: OpKind = MCK_Reg27; break;
    case AArch64::D16_D17_D18: OpKind = MCK_DTriple; break;
    case AArch64::D17_D18_D19: OpKind = MCK_DTriple; break;
    case AArch64::D18_D19_D20: OpKind = MCK_DTriple; break;
    case AArch64::D19_D20_D21: OpKind = MCK_DTriple; break;
    case AArch64::D20_D21_D22: OpKind = MCK_DTriple; break;
    case AArch64::D21_D22_D23: OpKind = MCK_DTriple; break;
    case AArch64::D22_D23_D24: OpKind = MCK_DTriple; break;
    case AArch64::D23_D24_D25: OpKind = MCK_DTriple; break;
    case AArch64::D24_D25_D26: OpKind = MCK_DTriple; break;
    case AArch64::D25_D26_D27: OpKind = MCK_DTriple; break;
    case AArch64::D26_D27_D28: OpKind = MCK_DTriple; break;
    case AArch64::D27_D28_D29: OpKind = MCK_DTriple; break;
    case AArch64::D28_D29_D30: OpKind = MCK_DTriple; break;
    case AArch64::D29_D30_D31: OpKind = MCK_DTriple; break;
    case AArch64::D30_D31_D0: OpKind = MCK_Reg30; break;
    case AArch64::D31_D0_D1: OpKind = MCK_Reg31; break;
    case AArch64::Q0_Q1_Q2: OpKind = MCK_Reg32; break;
    case AArch64::Q1_Q2_Q3: OpKind = MCK_Reg32; break;
    case AArch64::Q2_Q3_Q4: OpKind = MCK_Reg32; break;
    case AArch64::Q3_Q4_Q5: OpKind = MCK_Reg32; break;
    case AArch64::Q4_Q5_Q6: OpKind = MCK_Reg32; break;
    case AArch64::Q5_Q6_Q7: OpKind = MCK_Reg32; break;
    case AArch64::Q6_Q7_Q8: OpKind = MCK_Reg32; break;
    case AArch64::Q7_Q8_Q9: OpKind = MCK_Reg32; break;
    case AArch64::Q8_Q9_Q10: OpKind = MCK_Reg32; break;
    case AArch64::Q9_Q10_Q11: OpKind = MCK_Reg32; break;
    case AArch64::Q10_Q11_Q12: OpKind = MCK_Reg32; break;
    case AArch64::Q11_Q12_Q13: OpKind = MCK_Reg32; break;
    case AArch64::Q12_Q13_Q14: OpKind = MCK_Reg32; break;
    case AArch64::Q13_Q14_Q15: OpKind = MCK_Reg32; break;
    case AArch64::Q14_Q15_Q16: OpKind = MCK_Reg33; break;
    case AArch64::Q15_Q16_Q17: OpKind = MCK_Reg34; break;
    case AArch64::Q16_Q17_Q18: OpKind = MCK_QTriple; break;
    case AArch64::Q17_Q18_Q19: OpKind = MCK_QTriple; break;
    case AArch64::Q18_Q19_Q20: OpKind = MCK_QTriple; break;
    case AArch64::Q19_Q20_Q21: OpKind = MCK_QTriple; break;
    case AArch64::Q20_Q21_Q22: OpKind = MCK_QTriple; break;
    case AArch64::Q21_Q22_Q23: OpKind = MCK_QTriple; break;
    case AArch64::Q22_Q23_Q24: OpKind = MCK_QTriple; break;
    case AArch64::Q23_Q24_Q25: OpKind = MCK_QTriple; break;
    case AArch64::Q24_Q25_Q26: OpKind = MCK_QTriple; break;
    case AArch64::Q25_Q26_Q27: OpKind = MCK_QTriple; break;
    case AArch64::Q26_Q27_Q28: OpKind = MCK_QTriple; break;
    case AArch64::Q27_Q28_Q29: OpKind = MCK_QTriple; break;
    case AArch64::Q28_Q29_Q30: OpKind = MCK_QTriple; break;
    case AArch64::Q29_Q30_Q31: OpKind = MCK_QTriple; break;
    case AArch64::Q30_Q31_Q0: OpKind = MCK_Reg37; break;
    case AArch64::Q31_Q0_Q1: OpKind = MCK_Reg38; break;
    case AArch64::D0_D1_D2_D3: OpKind = MCK_Reg39; break;
    case AArch64::D1_D2_D3_D4: OpKind = MCK_Reg39; break;
    case AArch64::D2_D3_D4_D5: OpKind = MCK_Reg39; break;
    case AArch64::D3_D4_D5_D6: OpKind = MCK_Reg39; break;
    case AArch64::D4_D5_D6_D7: OpKind = MCK_Reg39; break;
    case AArch64::D5_D6_D7_D8: OpKind = MCK_Reg39; break;
    case AArch64::D6_D7_D8_D9: OpKind = MCK_Reg39; break;
    case AArch64::D7_D8_D9_D10: OpKind = MCK_Reg39; break;
    case AArch64::D8_D9_D10_D11: OpKind = MCK_Reg39; break;
    case AArch64::D9_D10_D11_D12: OpKind = MCK_Reg39; break;
    case AArch64::D10_D11_D12_D13: OpKind = MCK_Reg39; break;
    case AArch64::D11_D12_D13_D14: OpKind = MCK_Reg39; break;
    case AArch64::D12_D13_D14_D15: OpKind = MCK_Reg39; break;
    case AArch64::D13_D14_D15_D16: OpKind = MCK_Reg40; break;
    case AArch64::D14_D15_D16_D17: OpKind = MCK_Reg41; break;
    case AArch64::D15_D16_D17_D18: OpKind = MCK_Reg42; break;
    case AArch64::D16_D17_D18_D19: OpKind = MCK_DQuad; break;
    case AArch64::D17_D18_D19_D20: OpKind = MCK_DQuad; break;
    case AArch64::D18_D19_D20_D21: OpKind = MCK_DQuad; break;
    case AArch64::D19_D20_D21_D22: OpKind = MCK_DQuad; break;
    case AArch64::D20_D21_D22_D23: OpKind = MCK_DQuad; break;
    case AArch64::D21_D22_D23_D24: OpKind = MCK_DQuad; break;
    case AArch64::D22_D23_D24_D25: OpKind = MCK_DQuad; break;
    case AArch64::D23_D24_D25_D26: OpKind = MCK_DQuad; break;
    case AArch64::D24_D25_D26_D27: OpKind = MCK_DQuad; break;
    case AArch64::D25_D26_D27_D28: OpKind = MCK_DQuad; break;
    case AArch64::D26_D27_D28_D29: OpKind = MCK_DQuad; break;
    case AArch64::D27_D28_D29_D30: OpKind = MCK_DQuad; break;
    case AArch64::D28_D29_D30_D31: OpKind = MCK_DQuad; break;
    case AArch64::D29_D30_D31_D0: OpKind = MCK_Reg47; break;
    case AArch64::D30_D31_D0_D1: OpKind = MCK_Reg48; break;
    case AArch64::D31_D0_D1_D2: OpKind = MCK_Reg49; break;
    case AArch64::Q0_Q1_Q2_Q3: OpKind = MCK_Reg50; break;
    case AArch64::Q1_Q2_Q3_Q4: OpKind = MCK_Reg50; break;
    case AArch64::Q2_Q3_Q4_Q5: OpKind = MCK_Reg50; break;
    case AArch64::Q3_Q4_Q5_Q6: OpKind = MCK_Reg50; break;
    case AArch64::Q4_Q5_Q6_Q7: OpKind = MCK_Reg50; break;
    case AArch64::Q5_Q6_Q7_Q8: OpKind = MCK_Reg50; break;
    case AArch64::Q6_Q7_Q8_Q9: OpKind = MCK_Reg50; break;
    case AArch64::Q7_Q8_Q9_Q10: OpKind = MCK_Reg50; break;
    case AArch64::Q8_Q9_Q10_Q11: OpKind = MCK_Reg50; break;
    case AArch64::Q9_Q10_Q11_Q12: OpKind = MCK_Reg50; break;
    case AArch64::Q10_Q11_Q12_Q13: OpKind = MCK_Reg50; break;
    case AArch64::Q11_Q12_Q13_Q14: OpKind = MCK_Reg50; break;
    case AArch64::Q12_Q13_Q14_Q15: OpKind = MCK_Reg50; break;
    case AArch64::Q13_Q14_Q15_Q16: OpKind = MCK_Reg51; break;
    case AArch64::Q14_Q15_Q16_Q17: OpKind = MCK_Reg52; break;
    case AArch64::Q15_Q16_Q17_Q18: OpKind = MCK_Reg53; break;
    case AArch64::Q16_Q17_Q18_Q19: OpKind = MCK_QQuad; break;
    case AArch64::Q17_Q18_Q19_Q20: OpKind = MCK_QQuad; break;
    case AArch64::Q18_Q19_Q20_Q21: OpKind = MCK_QQuad; break;
    case AArch64::Q19_Q20_Q21_Q22: OpKind = MCK_QQuad; break;
    case AArch64::Q20_Q21_Q22_Q23: OpKind = MCK_QQuad; break;
    case AArch64::Q21_Q22_Q23_Q24: OpKind = MCK_QQuad; break;
    case AArch64::Q22_Q23_Q24_Q25: OpKind = MCK_QQuad; break;
    case AArch64::Q23_Q24_Q25_Q26: OpKind = MCK_QQuad; break;
    case AArch64::Q24_Q25_Q26_Q27: OpKind = MCK_QQuad; break;
    case AArch64::Q25_Q26_Q27_Q28: OpKind = MCK_QQuad; break;
    case AArch64::Q26_Q27_Q28_Q29: OpKind = MCK_QQuad; break;
    case AArch64::Q27_Q28_Q29_Q30: OpKind = MCK_QQuad; break;
    case AArch64::Q28_Q29_Q30_Q31: OpKind = MCK_QQuad; break;
    case AArch64::Q29_Q30_Q31_Q0: OpKind = MCK_Reg58; break;
    case AArch64::Q30_Q31_Q0_Q1: OpKind = MCK_Reg59; break;
    case AArch64::Q31_Q0_Q1_Q2: OpKind = MCK_Reg60; break;
    }
    return isSubclass(OpKind, Kind) ? MCTargetAsmParser::Match_Success :
                                      MCTargetAsmParser::Match_InvalidOperand;
  }

  return MCTargetAsmParser::Match_InvalidOperand;
}

unsigned AArch64AsmParser::
ComputeAvailableFeatures(uint64_t FB) const {
  unsigned Features = 0;
  if (((FB & AArch64::FeatureFPARMv8) != 0))
    Features |= Feature_HasFPARMv8;
  if (((FB & AArch64::FeatureNEON) != 0))
    Features |= Feature_HasNEON;
  if (((FB & AArch64::FeatureCrypto) != 0))
    Features |= Feature_HasCrypto;
  return Features;
}

static const char *const MnemonicTable =
    "\003abs\003adc\004adcs\003add\005addhn\006addhn2\004addp\004adds\004add"
    "v\003adr\004adrp\004aesd\004aese\006aesimc\005aesmc\003and\004ands\003a"
    "sr\002at\001b\003bfi\003bfm\005bfxil\003bic\004bics\003bif\003bit\002bl"
    "\003blr\002br\003brk\003bsl\004cbnz\003cbz\004ccmn\004ccmp\004cinc\004c"
    "inv\005clrex\003cls\003clz\004cmeq\004cmge\004cmgt\004cmhi\004cmhs\004c"
    "mle\004cmlo\004cmls\004cmlt\003cmn\003cmp\005cmtst\004cneg\003cnt\006cr"
    "c32b\007crc32cb\007crc32ch\007crc32cw\007crc32cx\006crc32h\006crc32w\006"
    "crc32x\004csel\004cset\005csetm\005csinc\005csinv\005csneg\002dc\005dcp"
    "s1\005dcps2\005dcps3\003dmb\004drps\003dsb\003dup\003eon\003eor\004eret"
    "\003ext\004extr\004fabd\004fabs\005facge\005facgt\005facle\005faclt\004"
    "fadd\005faddp\005fccmp\006fccmpe\005fcmeq\005fcmge\005fcmgt\005fcmle\005"
    "fcmlt\004fcmp\005fcmpe\005fcsel\004fcvt\006fcvtas\006fcvtau\005fcvtl\006"
    "fcvtl2\006fcvtms\006fcvtmu\005fcvtn\006fcvtn2\006fcvtns\006fcvtnu\006fc"
    "vtps\006fcvtpu\006fcvtxn\007fcvtxn2\006fcvtzs\006fcvtzu\004fdiv\005fmad"
    "d\004fmax\006fmaxnm\007fmaxnmp\007fmaxnmv\005fmaxp\005fmaxv\004fmin\006"
    "fminnm\007fminnmp\007fminnmv\005fminp\005fminv\004fmla\004fmls\004fmov\005"
    "fmsub\004fmul\005fmulx\004fneg\006fnmadd\006fnmsub\005fnmul\006frecpe\006"
    "frecps\006frecpx\006frinta\006frinti\006frintm\006frintn\006frintp\006f"
    "rintx\006frintz\007frsqrte\007frsqrts\005fsqrt\004fsub\004hint\003hlt\003"
    "hvc\002ic\003ins\003isb\003ld1\004ld1r\003ld2\004ld2r\003ld3\004ld3r\003"
    "ld4\004ld4r\004ldar\005ldarb\005ldarh\005ldaxp\005ldaxr\006ldaxrb\006ld"
    "axrh\004ldnp\003ldp\005ldpsw\003ldr\004ldrb\004ldrh\005ldrsb\005ldrsh\005"
    "ldrsw\004ldtr\005ldtrb\005ldtrh\006ldtrsb\006ldtrsh\006ldtrsw\004ldur\005"
    "ldurb\005ldurh\006ldursb\006ldursh\006ldursw\004ldxp\004ldxr\005ldxrb\005"
    "ldxrh\003lsl\003lsr\004madd\003mla\003mls\004mneg\003mov\004movi\004mov"
    "k\004movn\004movz\003mrs\003msr\004msub\003mul\003mvn\004mvni\003neg\004"
    "negs\003ngc\004ngcs\003nop\003not\003orn\003orr\004pmul\005pmull\006pmu"
    "ll2\004prfm\005prfum\006raddhn\007raddhn2\004rbit\003ret\003rev\005rev1"
    "6\005rev32\005rev64\003ror\005rshrn\006rshrn2\006rsubhn\007rsubhn2\004s"
    "aba\005sabal\006sabal2\004sabd\005sabdl\006sabdl2\006sadalp\005saddl\006"
    "saddl2\006saddlp\006saddlv\005saddw\006saddw2\003sbc\004sbcs\005sbfiz\004"
    "sbfm\004sbfx\005scvtf\004sdiv\003sev\004sevl\005sha1c\005sha1h\005sha1m"
    "\005sha1p\007sha1su0\007sha1su1\007sha256h\010sha256h2\tsha256su0\tsha2"
    "56su1\005shadd\003shl\004shll\005shll2\004shrn\005shrn2\005shsub\003sli"
    "\006smaddl\004smax\005smaxp\005smaxv\003smc\004smin\005sminp\005sminv\005"
    "smlal\006smlal2\005smlsl\006smlsl2\006smnegl\004smov\006smsubl\005smulh"
    "\005smull\006smull2\005sqabs\005sqadd\007sqdmlal\010sqdmlal2\007sqdmlsl"
    "\010sqdmlsl2\007sqdmulh\007sqdmull\010sqdmull2\005sqneg\010sqrdmulh\006"
    "sqrshl\007sqrshrn\010sqrshrn2\010sqrshrun\tsqrshrun2\005sqshl\006sqshlu"
    "\006sqshrn\007sqshrn2\007sqshrun\010sqshrun2\005sqsub\005sqxtn\006sqxtn"
    "2\006sqxtun\007sqxtun2\006srhadd\003sri\005srshl\005srshr\005srsra\004s"
    "shl\005sshll\006sshll2\004sshr\004ssra\005ssubl\006ssubl2\005ssubw\006s"
    "subw2\003st1\003st2\003st3\003st4\004stlr\005stlrb\005stlrh\005stlxp\005"
    "stlxr\006stlxrb\006stlxrh\004stnp\003stp\003str\004strb\004strh\004sttr"
    "\005sttrb\005sttrh\004stur\005sturb\005sturh\004stxp\004stxr\005stxrb\005"
    "stxrh\003sub\005subhn\006subhn2\004subs\006suqadd\003svc\004sxtb\004sxt"
    "h\004sxtw\003sys\004sysl\003tbl\004tbnz\003tbx\003tbz\004tlbi\004trn1\004"
    "trn2\003tst\004uaba\005uabal\006uabal2\004uabd\005uabdl\006uabdl2\006ua"
    "dalp\005uaddl\006uaddl2\006uaddlp\006uaddlv\005uaddw\006uaddw2\005ubfiz"
    "\004ubfm\004ubfx\005ucvtf\004udiv\005uhadd\005uhsub\006umaddl\004umax\005"
    "umaxp\005umaxv\004umin\005uminp\005uminv\005umlal\006umlal2\005umlsl\006"
    "umlsl2\006umnegl\004umov\006umsubl\005umulh\005umull\006umull2\005uqadd"
    "\006uqrshl\007uqrshrn\010uqrshrn2\005uqshl\006uqshrn\007uqshrn2\005uqsu"
    "b\005uqxtn\006uqxtn2\006urecpe\006urhadd\005urshl\005urshr\007ursqrte\005"
    "ursra\004ushl\005ushll\006ushll2\004ushr\006usqadd\004usra\005usubl\006"
    "usubl2\005usubw\006usubw2\004uxtb\004uxth\004uzp1\004uzp2\003wfe\003wfi"
    "\003xtn\004xtn2\005yield\004zip1\004zip2";

namespace {
  struct MatchEntry {
    uint16_t Mnemonic;
    uint16_t Opcode;
    uint16_t ConvertFn;
    uint8_t RequiredFeatures;
    uint8_t Classes[10];
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
  { 0 /* abs */, AArch64::ABSdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 0 /* abs */, AArch64::ABS2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 0 /* abs */, AArch64::ABS4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 0 /* abs */, AArch64::ABS8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 0 /* abs */, AArch64::ABS16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 0 /* abs */, AArch64::ABS2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 0 /* abs */, AArch64::ABS4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 0 /* abs */, AArch64::ABS8h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 4 /* adc */, AArch64::ADCwww, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 4 /* adc */, AArch64::ADCxxx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 8 /* adcs */, AArch64::ADCSwww, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 8 /* adcs */, AArch64::ADCSxxx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 13 /* add */, AArch64::ADDwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 13 /* add */, AArch64::ADDwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_Rwsp, MCK_GPR32wsp, MCK_GPR32 }, },
  { 13 /* add */, AArch64::ADDwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32wsp, MCK_Rwsp, MCK_GPR32 }, },
  { 13 /* add */, AArch64::ADDwwi_lsl0_s, Convert__Reg1_0__Reg1_1__AddSubImmLSL01_2, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_AddSubImmLSL0 }, },
  { 13 /* add */, AArch64::ADDwwi_lsl12_s, Convert__Reg1_0__Reg1_1__AddSubImmLSL121_2, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_AddSubImmLSL12 }, },
  { 13 /* add */, AArch64::ADDxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 13 /* add */, AArch64::ADDxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_Rxsp, MCK_GPR64xsp, MCK_GPR64 }, },
  { 13 /* add */, AArch64::ADDxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64xsp, MCK_Rxsp, MCK_GPR64 }, },
  { 13 /* add */, AArch64::ADDxxi_lsl0_s, Convert__Reg1_0__Reg1_1__AddSubImmLSL01_2, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_AddSubImmLSL0 }, },
  { 13 /* add */, AArch64::ADDxxi_lsl12_s, Convert__Reg1_0__Reg1_1__AddSubImmLSL121_2, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_AddSubImmLSL12 }, },
  { 13 /* add */, AArch64::ADDddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 13 /* add */, AArch64::ADDwww_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 13 /* add */, AArch64::ADDwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 13 /* add */, AArch64::ADDwww_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 13 /* add */, AArch64::ADDwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3, 0, { MCK_Rwsp, MCK_GPR32wsp, MCK_GPR32, MCK_RegExtendLSL }, },
  { 13 /* add */, AArch64::ADDwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3, 0, { MCK_GPR32wsp, MCK_Rwsp, MCK_GPR32, MCK_RegExtendLSL }, },
  { 13 /* add */, AArch64::ADDwww_sxtb, Convert__Reg1_0__Reg1_1__Reg1_2__SXTB1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_SXTB }, },
  { 13 /* add */, AArch64::ADDwww_sxth, Convert__Reg1_0__Reg1_1__Reg1_2__SXTH1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_SXTH }, },
  { 13 /* add */, AArch64::ADDwww_sxtw, Convert__Reg1_0__Reg1_1__Reg1_2__SXTW1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_SXTW }, },
  { 13 /* add */, AArch64::ADDwww_sxtx, Convert__Reg1_0__Reg1_1__Reg1_2__SXTX1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_SXTX }, },
  { 13 /* add */, AArch64::ADDwww_uxtb, Convert__Reg1_0__Reg1_1__Reg1_2__UXTB1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_UXTB }, },
  { 13 /* add */, AArch64::ADDwww_uxth, Convert__Reg1_0__Reg1_1__Reg1_2__UXTH1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_UXTH }, },
  { 13 /* add */, AArch64::ADDwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__UXTW1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_UXTW }, },
  { 13 /* add */, AArch64::ADDwww_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__UXTX1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_UXTX }, },
  { 13 /* add */, AArch64::ADDxxx_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 13 /* add */, AArch64::ADDxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 13 /* add */, AArch64::ADDxxx_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 13 /* add */, AArch64::ADDxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3, 0, { MCK_Rxsp, MCK_GPR64xsp, MCK_GPR64, MCK_RegExtendLSL }, },
  { 13 /* add */, AArch64::ADDxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3, 0, { MCK_GPR64xsp, MCK_Rxsp, MCK_GPR64, MCK_RegExtendLSL }, },
  { 13 /* add */, AArch64::ADDxxw_sxtb, Convert__Reg1_0__Reg1_1__Reg1_2__SXTB1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR32, MCK_SXTB }, },
  { 13 /* add */, AArch64::ADDxxw_sxth, Convert__Reg1_0__Reg1_1__Reg1_2__SXTH1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR32, MCK_SXTH }, },
  { 13 /* add */, AArch64::ADDxxw_sxtw, Convert__Reg1_0__Reg1_1__Reg1_2__SXTW1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR32, MCK_SXTW }, },
  { 13 /* add */, AArch64::ADDxxw_uxtb, Convert__Reg1_0__Reg1_1__Reg1_2__UXTB1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR32, MCK_UXTB }, },
  { 13 /* add */, AArch64::ADDxxw_uxth, Convert__Reg1_0__Reg1_1__Reg1_2__UXTH1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR32, MCK_UXTH }, },
  { 13 /* add */, AArch64::ADDxxw_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__UXTW1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR32, MCK_UXTW }, },
  { 13 /* add */, AArch64::ADDxxx_sxtx, Convert__Reg1_0__Reg1_1__Reg1_2__SXTX1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR64, MCK_SXTX }, },
  { 13 /* add */, AArch64::ADDxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__UXTX1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR64, MCK_UXTX }, },
  { 13 /* add */, AArch64::ADDvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 13 /* add */, AArch64::ADDvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 13 /* add */, AArch64::ADDvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 13 /* add */, AArch64::ADDvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 13 /* add */, AArch64::ADDvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 13 /* add */, AArch64::ADDvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 13 /* add */, AArch64::ADDvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 17 /* addhn */, AArch64::ADDHNvvv_2s2d, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 17 /* addhn */, AArch64::ADDHNvvv_4h4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 17 /* addhn */, AArch64::ADDHNvvv_8b8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 23 /* addhn2 */, AArch64::ADDHN2vvv_16b8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 23 /* addhn2 */, AArch64::ADDHN2vvv_4s2d, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 23 /* addhn2 */, AArch64::ADDHN2vvv_8h4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 30 /* addp */, AArch64::ADDPvv_D_2D, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR128, MCK__DOT_2d }, },
  { 30 /* addp */, AArch64::ADDP_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 30 /* addp */, AArch64::ADDP_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 30 /* addp */, AArch64::ADDP_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 30 /* addp */, AArch64::ADDP_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 30 /* addp */, AArch64::ADDP_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 30 /* addp */, AArch64::ADDP_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 30 /* addp */, AArch64::ADDP_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 35 /* adds */, AArch64::ADDSwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 35 /* adds */, AArch64::ADDSwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_Rwsp, MCK_GPR32 }, },
  { 35 /* adds */, AArch64::ADDwwi_lsl0_S, Convert__Reg1_0__Reg1_1__AddSubImmLSL01_2, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_AddSubImmLSL0 }, },
  { 35 /* adds */, AArch64::ADDwwi_lsl12_S, Convert__Reg1_0__Reg1_1__AddSubImmLSL121_2, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_AddSubImmLSL12 }, },
  { 35 /* adds */, AArch64::ADDSxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 35 /* adds */, AArch64::ADDSxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_Rxsp, MCK_GPR64 }, },
  { 35 /* adds */, AArch64::ADDxxi_lsl0_S, Convert__Reg1_0__Reg1_1__AddSubImmLSL01_2, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_AddSubImmLSL0 }, },
  { 35 /* adds */, AArch64::ADDxxi_lsl12_S, Convert__Reg1_0__Reg1_1__AddSubImmLSL121_2, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_AddSubImmLSL12 }, },
  { 35 /* adds */, AArch64::ADDSwww_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 35 /* adds */, AArch64::ADDSwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 35 /* adds */, AArch64::ADDSwww_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 35 /* adds */, AArch64::ADDSwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3, 0, { MCK_GPR32, MCK_Rwsp, MCK_GPR32, MCK_RegExtendLSL }, },
  { 35 /* adds */, AArch64::ADDSwww_sxtb, Convert__Reg1_0__Reg1_1__Reg1_2__SXTB1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_SXTB }, },
  { 35 /* adds */, AArch64::ADDSwww_sxth, Convert__Reg1_0__Reg1_1__Reg1_2__SXTH1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_SXTH }, },
  { 35 /* adds */, AArch64::ADDSwww_sxtw, Convert__Reg1_0__Reg1_1__Reg1_2__SXTW1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_SXTW }, },
  { 35 /* adds */, AArch64::ADDSwww_sxtx, Convert__Reg1_0__Reg1_1__Reg1_2__SXTX1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_SXTX }, },
  { 35 /* adds */, AArch64::ADDSwww_uxtb, Convert__Reg1_0__Reg1_1__Reg1_2__UXTB1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_UXTB }, },
  { 35 /* adds */, AArch64::ADDSwww_uxth, Convert__Reg1_0__Reg1_1__Reg1_2__UXTH1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_UXTH }, },
  { 35 /* adds */, AArch64::ADDSwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__UXTW1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_UXTW }, },
  { 35 /* adds */, AArch64::ADDSwww_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__UXTX1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_UXTX }, },
  { 35 /* adds */, AArch64::ADDSxxx_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 35 /* adds */, AArch64::ADDSxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 35 /* adds */, AArch64::ADDSxxx_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 35 /* adds */, AArch64::ADDSxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3, 0, { MCK_GPR64, MCK_Rxsp, MCK_GPR64, MCK_RegExtendLSL }, },
  { 35 /* adds */, AArch64::ADDSxxw_sxtb, Convert__Reg1_0__Reg1_1__Reg1_2__SXTB1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR32, MCK_SXTB }, },
  { 35 /* adds */, AArch64::ADDSxxw_sxth, Convert__Reg1_0__Reg1_1__Reg1_2__SXTH1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR32, MCK_SXTH }, },
  { 35 /* adds */, AArch64::ADDSxxw_sxtw, Convert__Reg1_0__Reg1_1__Reg1_2__SXTW1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR32, MCK_SXTW }, },
  { 35 /* adds */, AArch64::ADDSxxw_uxtb, Convert__Reg1_0__Reg1_1__Reg1_2__UXTB1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR32, MCK_UXTB }, },
  { 35 /* adds */, AArch64::ADDSxxw_uxth, Convert__Reg1_0__Reg1_1__Reg1_2__UXTH1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR32, MCK_UXTH }, },
  { 35 /* adds */, AArch64::ADDSxxw_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__UXTW1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR32, MCK_UXTW }, },
  { 35 /* adds */, AArch64::ADDSxxx_sxtx, Convert__Reg1_0__Reg1_1__Reg1_2__SXTX1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR64, MCK_SXTX }, },
  { 35 /* adds */, AArch64::ADDSxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__UXTX1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR64, MCK_UXTX }, },
  { 40 /* addv */, AArch64::ADDV_1b8b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR64, MCK__DOT_8b }, },
  { 40 /* addv */, AArch64::ADDV_1b16b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR128, MCK__DOT_16b }, },
  { 40 /* addv */, AArch64::ADDV_1h4h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR64, MCK__DOT_4h }, },
  { 40 /* addv */, AArch64::ADDV_1h8h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR128, MCK__DOT_8h }, },
  { 40 /* addv */, AArch64::ADDV_1s4s, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR128, MCK__DOT_4s }, },
  { 45 /* adr */, AArch64::ADRxi, Convert__Reg1_0__Label21_11_1, 0, { MCK_GPR64, MCK_Label21_1 }, },
  { 49 /* adrp */, AArch64::ADRPxi, Convert__Reg1_0__AdrpLabel1_1, 0, { MCK_GPR64, MCK_AdrpLabel }, },
  { 54 /* aesd */, AArch64::AESD, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON|Feature_HasCrypto, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 59 /* aese */, AArch64::AESE, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON|Feature_HasCrypto, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 64 /* aesimc */, AArch64::AESIMC, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 71 /* aesmc */, AArch64::AESMC, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 77 /* and */, AArch64::ANDwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 77 /* and */, AArch64::ANDwwi, Convert__Reg1_0__Reg1_1__LogicalImm321_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_LogicalImm32 }, },
  { 77 /* and */, AArch64::ANDxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 77 /* and */, AArch64::ANDxxi, Convert__Reg1_0__Reg1_1__LogicalImm641_2, 0, { MCK_GPR64xsp, MCK_GPR64, MCK_LogicalImm64 }, },
  { 77 /* and */, AArch64::ANDwww_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 77 /* and */, AArch64::ANDwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 77 /* and */, AArch64::ANDwww_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 77 /* and */, AArch64::ANDwww_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftRORi32 }, },
  { 77 /* and */, AArch64::ANDxxx_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 77 /* and */, AArch64::ANDxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 77 /* and */, AArch64::ANDxxx_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 77 /* and */, AArch64::ANDxxx_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftRORi64 }, },
  { 77 /* and */, AArch64::ANDvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 77 /* and */, AArch64::ANDvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 81 /* ands */, AArch64::ANDSwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 81 /* ands */, AArch64::ANDSwwi, Convert__Reg1_0__Reg1_1__LogicalImm321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_LogicalImm32 }, },
  { 81 /* ands */, AArch64::ANDSxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 81 /* ands */, AArch64::ANDSxxi, Convert__Reg1_0__Reg1_1__LogicalImm641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_LogicalImm64 }, },
  { 81 /* ands */, AArch64::ANDSwww_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 81 /* ands */, AArch64::ANDSwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 81 /* ands */, AArch64::ANDSwww_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 81 /* ands */, AArch64::ANDSwww_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftRORi32 }, },
  { 81 /* ands */, AArch64::ANDSxxx_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 81 /* ands */, AArch64::ANDSxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 81 /* ands */, AArch64::ANDSxxx_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 81 /* ands */, AArch64::ANDSxxx_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftRORi64 }, },
  { 86 /* asr */, AArch64::ASRVwww, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 86 /* asr */, AArch64::ASRwwi, Convert__Reg1_0__Reg1_1__UImm51_2, 0, { MCK_GPR32, MCK_GPR32, MCK_UImm5 }, },
  { 86 /* asr */, AArch64::ASRVxxx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 86 /* asr */, AArch64::ASRxxi, Convert__Reg1_0__Reg1_1__UImm61_2, 0, { MCK_GPR64, MCK_GPR64, MCK_UImm6 }, },
  { 90 /* at */, AArch64::ATix, Convert__NamedImmat1_0__Reg1_1, 0, { MCK_NamedImmat, MCK_GPR64 }, },
  { 93 /* b */, AArch64::Bimm, Convert__Label26_41_0, 0, { MCK_Label26_4 }, },
  { 93 /* b */, AArch64::Bcc, Convert__CondCode1_1__Label19_41_2, 0, { MCK__DOT_, MCK_CondCode, MCK_Label19_4 }, },
  { 95 /* bfi */, AArch64::BFIwwii, Convert__Reg1_0__Tie0__Reg1_1__BFI32LSB1_2__BFI32Width1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_BFI32LSB, MCK_BFI32Width }, },
  { 95 /* bfi */, AArch64::BFIxxii, Convert__Reg1_0__Tie0__Reg1_1__BFI64LSB1_2__BFI64Width1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_BFI64LSB, MCK_BFI64Width }, },
  { 99 /* bfm */, AArch64::BFMwwii, Convert__Reg1_0__Tie0__Reg1_1__UImm51_2__UImm51_3, 0, { MCK_GPR32, MCK_GPR32, MCK_UImm5, MCK_UImm5 }, },
  { 99 /* bfm */, AArch64::BFMxxii, Convert__Reg1_0__Tie0__Reg1_1__UImm61_2__UImm61_3, 0, { MCK_GPR64, MCK_GPR64, MCK_UImm6, MCK_UImm6 }, },
  { 103 /* bfxil */, AArch64::BFXILwwii, Convert__Reg1_0__Tie0__Reg1_1__UImm51_2__BFX32Width1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_UImm5, MCK_BFX32Width }, },
  { 103 /* bfxil */, AArch64::BFXILxxii, Convert__Reg1_0__Tie0__Reg1_1__UImm61_2__BFX64Width1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_UImm6, MCK_BFX64Width }, },
  { 109 /* bic */, AArch64::BICwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 109 /* bic */, AArch64::BICxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 109 /* bic */, AArch64::BICvi_lsl_2S, Convert__Reg1_0__Tie0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_UImm8 }, },
  { 109 /* bic */, AArch64::BICvi_lsl_4H, Convert__Reg1_0__Tie0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_UImm8 }, },
  { 109 /* bic */, AArch64::BICvi_lsl_4S, Convert__Reg1_0__Tie0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_UImm8 }, },
  { 109 /* bic */, AArch64::BICvi_lsl_8H, Convert__Reg1_0__Tie0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_UImm8 }, },
  { 109 /* bic */, AArch64::BICwww_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 109 /* bic */, AArch64::BICwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 109 /* bic */, AArch64::BICwww_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 109 /* bic */, AArch64::BICwww_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftRORi32 }, },
  { 109 /* bic */, AArch64::BICxxx_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 109 /* bic */, AArch64::BICxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 109 /* bic */, AArch64::BICxxx_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 109 /* bic */, AArch64::BICxxx_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftRORi64 }, },
  { 109 /* bic */, AArch64::BICvi_lsl_2S, Convert__Reg1_0__Tie0__UImm81_2__NeonMovImmShiftLSL1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_UImm8, MCK_NeonMovImmShiftLSL }, },
  { 109 /* bic */, AArch64::BICvi_lsl_4H, Convert__Reg1_0__Tie0__UImm81_2__NeonMovImmShiftLSLH1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_UImm8, MCK_NeonMovImmShiftLSLH }, },
  { 109 /* bic */, AArch64::BICvi_lsl_4S, Convert__Reg1_0__Tie0__UImm81_2__NeonMovImmShiftLSL1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_UImm8, MCK_NeonMovImmShiftLSL }, },
  { 109 /* bic */, AArch64::BICvi_lsl_8H, Convert__Reg1_0__Tie0__UImm81_2__NeonMovImmShiftLSLH1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_UImm8, MCK_NeonMovImmShiftLSLH }, },
  { 109 /* bic */, AArch64::BICvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 109 /* bic */, AArch64::BICvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 113 /* bics */, AArch64::BICSwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 113 /* bics */, AArch64::BICSxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 113 /* bics */, AArch64::BICSwww_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 113 /* bics */, AArch64::BICSwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 113 /* bics */, AArch64::BICSwww_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 113 /* bics */, AArch64::BICSwww_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftRORi32 }, },
  { 113 /* bics */, AArch64::BICSxxx_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 113 /* bics */, AArch64::BICSxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 113 /* bics */, AArch64::BICSxxx_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 113 /* bics */, AArch64::BICSxxx_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftRORi64 }, },
  { 118 /* bif */, AArch64::BIFvvv_8B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 118 /* bif */, AArch64::BIFvvv_16B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 122 /* bit */, AArch64::BITvvv_8B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 122 /* bit */, AArch64::BITvvv_16B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 126 /* bl */, AArch64::BLimm, Convert__Label26_41_0, 0, { MCK_Label26_4 }, },
  { 129 /* blr */, AArch64::BLRx, Convert__Reg1_0, 0, { MCK_GPR64 }, },
  { 133 /* br */, AArch64::BRx, Convert__Reg1_0, 0, { MCK_GPR64 }, },
  { 136 /* brk */, AArch64::BRKi, Convert__UImm161_0, 0, { MCK_UImm16 }, },
  { 140 /* bsl */, AArch64::BSLvvv_8B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 140 /* bsl */, AArch64::BSLvvv_16B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 144 /* cbnz */, AArch64::CBNZw, Convert__Reg1_0__Label19_41_1, 0, { MCK_GPR32, MCK_Label19_4 }, },
  { 144 /* cbnz */, AArch64::CBNZx, Convert__Reg1_0__Label19_41_1, 0, { MCK_GPR64, MCK_Label19_4 }, },
  { 149 /* cbz */, AArch64::CBZw, Convert__Reg1_0__Label19_41_1, 0, { MCK_GPR32, MCK_Label19_4 }, },
  { 149 /* cbz */, AArch64::CBZx, Convert__Reg1_0__Label19_41_1, 0, { MCK_GPR64, MCK_Label19_4 }, },
  { 153 /* ccmn */, AArch64::CCMNww, Convert__Reg1_0__Reg1_1__UImm41_2__CondCodeOp1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_UImm4, MCK_CondCodeOp }, },
  { 153 /* ccmn */, AArch64::CCMNwi, Convert__Reg1_0__UImm51_1__UImm41_2__CondCodeOp1_3, 0, { MCK_GPR32, MCK_UImm5, MCK_UImm4, MCK_CondCodeOp }, },
  { 153 /* ccmn */, AArch64::CCMNxx, Convert__Reg1_0__Reg1_1__UImm41_2__CondCodeOp1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_UImm4, MCK_CondCodeOp }, },
  { 153 /* ccmn */, AArch64::CCMNxi, Convert__Reg1_0__UImm51_1__UImm41_2__CondCodeOp1_3, 0, { MCK_GPR64, MCK_UImm5, MCK_UImm4, MCK_CondCodeOp }, },
  { 158 /* ccmp */, AArch64::CCMPww, Convert__Reg1_0__Reg1_1__UImm41_2__CondCodeOp1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_UImm4, MCK_CondCodeOp }, },
  { 158 /* ccmp */, AArch64::CCMPwi, Convert__Reg1_0__UImm51_1__UImm41_2__CondCodeOp1_3, 0, { MCK_GPR32, MCK_UImm5, MCK_UImm4, MCK_CondCodeOp }, },
  { 158 /* ccmp */, AArch64::CCMPxx, Convert__Reg1_0__Reg1_1__UImm41_2__CondCodeOp1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_UImm4, MCK_CondCodeOp }, },
  { 158 /* ccmp */, AArch64::CCMPxi, Convert__Reg1_0__UImm51_1__UImm41_2__CondCodeOp1_3, 0, { MCK_GPR64, MCK_UImm5, MCK_UImm4, MCK_CondCodeOp }, },
  { 163 /* cinc */, AArch64::CSINCwwwc, Convert__Reg1_0__Reg1_1__Reg1_1__InvCondCodeOp1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_InvCondCodeOp }, },
  { 163 /* cinc */, AArch64::CSINCxxxc, Convert__Reg1_0__Reg1_1__Reg1_1__InvCondCodeOp1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_InvCondCodeOp }, },
  { 168 /* cinv */, AArch64::CSINVwwwc, Convert__Reg1_0__Reg1_1__Reg1_1__InvCondCodeOp1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_InvCondCodeOp }, },
  { 168 /* cinv */, AArch64::CSINVxxxc, Convert__Reg1_0__Reg1_1__Reg1_1__InvCondCodeOp1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_InvCondCodeOp }, },
  { 173 /* clrex */, AArch64::CLREXi, Convert__imm_15, 0, {  }, },
  { 173 /* clrex */, AArch64::CLREXi, Convert__UImm41_0, 0, { MCK_UImm4 }, },
  { 179 /* cls */, AArch64::CLSww, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 179 /* cls */, AArch64::CLSxx, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 179 /* cls */, AArch64::CLS2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 179 /* cls */, AArch64::CLS4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 179 /* cls */, AArch64::CLS8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 179 /* cls */, AArch64::CLS16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 179 /* cls */, AArch64::CLS4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 179 /* cls */, AArch64::CLS8h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 183 /* clz */, AArch64::CLZww, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 183 /* clz */, AArch64::CLZxx, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 183 /* clz */, AArch64::CLZ2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 183 /* clz */, AArch64::CLZ4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 183 /* clz */, AArch64::CLZ8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 183 /* clz */, AArch64::CLZ16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 183 /* clz */, AArch64::CLZ4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 183 /* clz */, AArch64::CLZ8h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 187 /* cmeq */, AArch64::CMEQddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 187 /* cmeq */, AArch64::CMEQddi, Convert__Reg1_0__Reg1_1__UImm01_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_UImm0 }, },
  { 187 /* cmeq */, AArch64::CMEQvvi_2S, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_UImm0 }, },
  { 187 /* cmeq */, AArch64::CMEQvvi_4H, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_UImm0 }, },
  { 187 /* cmeq */, AArch64::CMEQvvi_8B, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_UImm0 }, },
  { 187 /* cmeq */, AArch64::CMEQvvi_16B, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_UImm0 }, },
  { 187 /* cmeq */, AArch64::CMEQvvi_2D, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_UImm0 }, },
  { 187 /* cmeq */, AArch64::CMEQvvi_4S, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_UImm0 }, },
  { 187 /* cmeq */, AArch64::CMEQvvi_8H, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_UImm0 }, },
  { 187 /* cmeq */, AArch64::CMEQvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 187 /* cmeq */, AArch64::CMEQvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 187 /* cmeq */, AArch64::CMEQvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 187 /* cmeq */, AArch64::CMEQvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 187 /* cmeq */, AArch64::CMEQvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 187 /* cmeq */, AArch64::CMEQvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 187 /* cmeq */, AArch64::CMEQvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 192 /* cmge */, AArch64::CMGEddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 192 /* cmge */, AArch64::CMGEddi, Convert__Reg1_0__Reg1_1__UImm01_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_UImm0 }, },
  { 192 /* cmge */, AArch64::CMGEvvi_2S, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_UImm0 }, },
  { 192 /* cmge */, AArch64::CMGEvvi_4H, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_UImm0 }, },
  { 192 /* cmge */, AArch64::CMGEvvi_8B, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_UImm0 }, },
  { 192 /* cmge */, AArch64::CMGEvvi_16B, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_UImm0 }, },
  { 192 /* cmge */, AArch64::CMGEvvi_2D, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_UImm0 }, },
  { 192 /* cmge */, AArch64::CMGEvvi_4S, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_UImm0 }, },
  { 192 /* cmge */, AArch64::CMGEvvi_8H, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_UImm0 }, },
  { 192 /* cmge */, AArch64::CMGEvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 192 /* cmge */, AArch64::CMGEvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 192 /* cmge */, AArch64::CMGEvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 192 /* cmge */, AArch64::CMGEvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 192 /* cmge */, AArch64::CMGEvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 192 /* cmge */, AArch64::CMGEvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 192 /* cmge */, AArch64::CMGEvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 197 /* cmgt */, AArch64::CMGTddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 197 /* cmgt */, AArch64::CMGTddi, Convert__Reg1_0__Reg1_1__UImm01_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_UImm0 }, },
  { 197 /* cmgt */, AArch64::CMGTvvi_2S, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_UImm0 }, },
  { 197 /* cmgt */, AArch64::CMGTvvi_4H, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_UImm0 }, },
  { 197 /* cmgt */, AArch64::CMGTvvi_8B, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_UImm0 }, },
  { 197 /* cmgt */, AArch64::CMGTvvi_16B, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_UImm0 }, },
  { 197 /* cmgt */, AArch64::CMGTvvi_2D, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_UImm0 }, },
  { 197 /* cmgt */, AArch64::CMGTvvi_4S, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_UImm0 }, },
  { 197 /* cmgt */, AArch64::CMGTvvi_8H, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_UImm0 }, },
  { 197 /* cmgt */, AArch64::CMGTvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 197 /* cmgt */, AArch64::CMGTvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 197 /* cmgt */, AArch64::CMGTvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 197 /* cmgt */, AArch64::CMGTvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 197 /* cmgt */, AArch64::CMGTvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 197 /* cmgt */, AArch64::CMGTvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 197 /* cmgt */, AArch64::CMGTvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 202 /* cmhi */, AArch64::CMHIddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 202 /* cmhi */, AArch64::CMHIvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 202 /* cmhi */, AArch64::CMHIvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 202 /* cmhi */, AArch64::CMHIvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 202 /* cmhi */, AArch64::CMHIvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 202 /* cmhi */, AArch64::CMHIvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 202 /* cmhi */, AArch64::CMHIvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 202 /* cmhi */, AArch64::CMHIvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 207 /* cmhs */, AArch64::CMHSddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 207 /* cmhs */, AArch64::CMHSvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 207 /* cmhs */, AArch64::CMHSvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 207 /* cmhs */, AArch64::CMHSvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 207 /* cmhs */, AArch64::CMHSvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 207 /* cmhs */, AArch64::CMHSvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 207 /* cmhs */, AArch64::CMHSvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 207 /* cmhs */, AArch64::CMHSvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 212 /* cmle */, AArch64::CMLEddi, Convert__Reg1_0__Reg1_1__UImm01_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_UImm0 }, },
  { 212 /* cmle */, AArch64::CMLEvvi_2S, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_UImm0 }, },
  { 212 /* cmle */, AArch64::CMLEvvi_4H, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_UImm0 }, },
  { 212 /* cmle */, AArch64::CMLEvvi_8B, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_UImm0 }, },
  { 212 /* cmle */, AArch64::CMLEvvi_16B, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_UImm0 }, },
  { 212 /* cmle */, AArch64::CMLEvvi_2D, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_UImm0 }, },
  { 212 /* cmle */, AArch64::CMLEvvi_4S, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_UImm0 }, },
  { 212 /* cmle */, AArch64::CMLEvvi_8H, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_UImm0 }, },
  { 212 /* cmle */, AArch64::CMGEvvv_2S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 212 /* cmle */, AArch64::CMGEvvv_4H, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 212 /* cmle */, AArch64::CMGEvvv_8B, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 212 /* cmle */, AArch64::CMGEvvv_16B, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 212 /* cmle */, AArch64::CMGEvvv_2D, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 212 /* cmle */, AArch64::CMGEvvv_4S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 212 /* cmle */, AArch64::CMGEvvv_8H, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 217 /* cmlo */, AArch64::CMHIvvv_2S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 217 /* cmlo */, AArch64::CMHIvvv_4H, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 217 /* cmlo */, AArch64::CMHIvvv_8B, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 217 /* cmlo */, AArch64::CMHIvvv_16B, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 217 /* cmlo */, AArch64::CMHIvvv_2D, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 217 /* cmlo */, AArch64::CMHIvvv_4S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 217 /* cmlo */, AArch64::CMHIvvv_8H, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 222 /* cmls */, AArch64::CMHSvvv_2S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 222 /* cmls */, AArch64::CMHSvvv_4H, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 222 /* cmls */, AArch64::CMHSvvv_8B, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 222 /* cmls */, AArch64::CMHSvvv_16B, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 222 /* cmls */, AArch64::CMHSvvv_2D, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 222 /* cmls */, AArch64::CMHSvvv_4S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 222 /* cmls */, AArch64::CMHSvvv_8H, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 227 /* cmlt */, AArch64::CMLTddi, Convert__Reg1_0__Reg1_1__UImm01_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_UImm0 }, },
  { 227 /* cmlt */, AArch64::CMLTvvi_2S, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_UImm0 }, },
  { 227 /* cmlt */, AArch64::CMLTvvi_4H, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_UImm0 }, },
  { 227 /* cmlt */, AArch64::CMLTvvi_8B, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_UImm0 }, },
  { 227 /* cmlt */, AArch64::CMLTvvi_16B, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_UImm0 }, },
  { 227 /* cmlt */, AArch64::CMLTvvi_2D, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_UImm0 }, },
  { 227 /* cmlt */, AArch64::CMLTvvi_4S, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_UImm0 }, },
  { 227 /* cmlt */, AArch64::CMLTvvi_8H, Convert__Reg1_0__Reg1_2__UImm01_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_UImm0 }, },
  { 227 /* cmlt */, AArch64::CMGTvvv_2S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 227 /* cmlt */, AArch64::CMGTvvv_4H, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 227 /* cmlt */, AArch64::CMGTvvv_8B, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 227 /* cmlt */, AArch64::CMGTvvv_16B, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 227 /* cmlt */, AArch64::CMGTvvv_2D, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 227 /* cmlt */, AArch64::CMGTvvv_4S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 227 /* cmlt */, AArch64::CMGTvvv_8H, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 232 /* cmn */, AArch64::CMNww_lsl, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 232 /* cmn */, AArch64::CMNww_uxtw, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_Rwsp, MCK_GPR32 }, },
  { 232 /* cmn */, AArch64::ADDwwi_lsl0_cmp, Convert__Reg1_0__AddSubImmLSL01_1, 0, { MCK_GPR32wsp, MCK_AddSubImmLSL0 }, },
  { 232 /* cmn */, AArch64::ADDwwi_lsl12_cmp, Convert__Reg1_0__AddSubImmLSL121_1, 0, { MCK_GPR32wsp, MCK_AddSubImmLSL12 }, },
  { 232 /* cmn */, AArch64::CMNxx_lsl, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 232 /* cmn */, AArch64::CMNxx_uxtx, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_Rxsp, MCK_GPR64 }, },
  { 232 /* cmn */, AArch64::ADDxxi_lsl0_cmp, Convert__Reg1_0__AddSubImmLSL01_1, 0, { MCK_GPR64xsp, MCK_AddSubImmLSL0 }, },
  { 232 /* cmn */, AArch64::ADDxxi_lsl12_cmp, Convert__Reg1_0__AddSubImmLSL121_1, 0, { MCK_GPR64xsp, MCK_AddSubImmLSL12 }, },
  { 232 /* cmn */, AArch64::CMNww_asr, Convert__Reg1_0__Reg1_1__ShiftASRi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 232 /* cmn */, AArch64::CMNww_lsl, Convert__Reg1_0__Reg1_1__ShiftLSLi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 232 /* cmn */, AArch64::CMNww_lsr, Convert__Reg1_0__Reg1_1__ShiftLSRi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 232 /* cmn */, AArch64::CMNww_uxtw, Convert__Reg1_0__Reg1_1__RegExtendLSL1_2, 0, { MCK_Rwsp, MCK_GPR32, MCK_RegExtendLSL }, },
  { 232 /* cmn */, AArch64::CMNww_sxtb, Convert__Reg1_0__Reg1_1__SXTB1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_SXTB }, },
  { 232 /* cmn */, AArch64::CMNww_sxth, Convert__Reg1_0__Reg1_1__SXTH1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_SXTH }, },
  { 232 /* cmn */, AArch64::CMNww_sxtw, Convert__Reg1_0__Reg1_1__SXTW1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_SXTW }, },
  { 232 /* cmn */, AArch64::CMNww_sxtx, Convert__Reg1_0__Reg1_1__SXTX1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_SXTX }, },
  { 232 /* cmn */, AArch64::CMNww_uxtb, Convert__Reg1_0__Reg1_1__UXTB1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_UXTB }, },
  { 232 /* cmn */, AArch64::CMNww_uxth, Convert__Reg1_0__Reg1_1__UXTH1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_UXTH }, },
  { 232 /* cmn */, AArch64::CMNww_uxtw, Convert__Reg1_0__Reg1_1__UXTW1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_UXTW }, },
  { 232 /* cmn */, AArch64::CMNww_uxtx, Convert__Reg1_0__Reg1_1__UXTX1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_UXTX }, },
  { 232 /* cmn */, AArch64::CMNxx_asr, Convert__Reg1_0__Reg1_1__ShiftASRi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 232 /* cmn */, AArch64::CMNxx_lsl, Convert__Reg1_0__Reg1_1__ShiftLSLi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 232 /* cmn */, AArch64::CMNxx_lsr, Convert__Reg1_0__Reg1_1__ShiftLSRi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 232 /* cmn */, AArch64::CMNxx_uxtx, Convert__Reg1_0__Reg1_1__RegExtendLSL1_2, 0, { MCK_Rxsp, MCK_GPR64, MCK_RegExtendLSL }, },
  { 232 /* cmn */, AArch64::CMNxw_sxtb, Convert__Reg1_0__Reg1_1__SXTB1_2, 0, { MCK_GPR64xsp, MCK_GPR32, MCK_SXTB }, },
  { 232 /* cmn */, AArch64::CMNxw_sxth, Convert__Reg1_0__Reg1_1__SXTH1_2, 0, { MCK_GPR64xsp, MCK_GPR32, MCK_SXTH }, },
  { 232 /* cmn */, AArch64::CMNxw_sxtw, Convert__Reg1_0__Reg1_1__SXTW1_2, 0, { MCK_GPR64xsp, MCK_GPR32, MCK_SXTW }, },
  { 232 /* cmn */, AArch64::CMNxw_uxtb, Convert__Reg1_0__Reg1_1__UXTB1_2, 0, { MCK_GPR64xsp, MCK_GPR32, MCK_UXTB }, },
  { 232 /* cmn */, AArch64::CMNxw_uxth, Convert__Reg1_0__Reg1_1__UXTH1_2, 0, { MCK_GPR64xsp, MCK_GPR32, MCK_UXTH }, },
  { 232 /* cmn */, AArch64::CMNxw_uxtw, Convert__Reg1_0__Reg1_1__UXTW1_2, 0, { MCK_GPR64xsp, MCK_GPR32, MCK_UXTW }, },
  { 232 /* cmn */, AArch64::CMNxx_sxtx, Convert__Reg1_0__Reg1_1__SXTX1_2, 0, { MCK_GPR64xsp, MCK_GPR64, MCK_SXTX }, },
  { 232 /* cmn */, AArch64::CMNxx_uxtx, Convert__Reg1_0__Reg1_1__UXTX1_2, 0, { MCK_GPR64xsp, MCK_GPR64, MCK_UXTX }, },
  { 236 /* cmp */, AArch64::CMPww_lsl, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 236 /* cmp */, AArch64::CMPww_uxtw, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_Rwsp, MCK_GPR32 }, },
  { 236 /* cmp */, AArch64::SUBwwi_lsl0_cmp, Convert__Reg1_0__AddSubImmLSL01_1, 0, { MCK_GPR32wsp, MCK_AddSubImmLSL0 }, },
  { 236 /* cmp */, AArch64::SUBwwi_lsl12_cmp, Convert__Reg1_0__AddSubImmLSL121_1, 0, { MCK_GPR32wsp, MCK_AddSubImmLSL12 }, },
  { 236 /* cmp */, AArch64::CMPxx_lsl, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 236 /* cmp */, AArch64::CMPxx_uxtx, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_Rxsp, MCK_GPR64 }, },
  { 236 /* cmp */, AArch64::SUBxxi_lsl0_cmp, Convert__Reg1_0__AddSubImmLSL01_1, 0, { MCK_GPR64xsp, MCK_AddSubImmLSL0 }, },
  { 236 /* cmp */, AArch64::SUBxxi_lsl12_cmp, Convert__Reg1_0__AddSubImmLSL121_1, 0, { MCK_GPR64xsp, MCK_AddSubImmLSL12 }, },
  { 236 /* cmp */, AArch64::CMPww_asr, Convert__Reg1_0__Reg1_1__ShiftASRi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 236 /* cmp */, AArch64::CMPww_lsl, Convert__Reg1_0__Reg1_1__ShiftLSLi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 236 /* cmp */, AArch64::CMPww_lsr, Convert__Reg1_0__Reg1_1__ShiftLSRi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 236 /* cmp */, AArch64::CMPww_uxtw, Convert__Reg1_0__Reg1_1__RegExtendLSL1_2, 0, { MCK_Rwsp, MCK_GPR32, MCK_RegExtendLSL }, },
  { 236 /* cmp */, AArch64::CMPww_sxtb, Convert__Reg1_0__Reg1_1__SXTB1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_SXTB }, },
  { 236 /* cmp */, AArch64::CMPww_sxth, Convert__Reg1_0__Reg1_1__SXTH1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_SXTH }, },
  { 236 /* cmp */, AArch64::CMPww_sxtw, Convert__Reg1_0__Reg1_1__SXTW1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_SXTW }, },
  { 236 /* cmp */, AArch64::CMPww_sxtx, Convert__Reg1_0__Reg1_1__SXTX1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_SXTX }, },
  { 236 /* cmp */, AArch64::CMPww_uxtb, Convert__Reg1_0__Reg1_1__UXTB1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_UXTB }, },
  { 236 /* cmp */, AArch64::CMPww_uxth, Convert__Reg1_0__Reg1_1__UXTH1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_UXTH }, },
  { 236 /* cmp */, AArch64::CMPww_uxtw, Convert__Reg1_0__Reg1_1__UXTW1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_UXTW }, },
  { 236 /* cmp */, AArch64::CMPww_uxtx, Convert__Reg1_0__Reg1_1__UXTX1_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_UXTX }, },
  { 236 /* cmp */, AArch64::CMPxx_asr, Convert__Reg1_0__Reg1_1__ShiftASRi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 236 /* cmp */, AArch64::CMPxx_lsl, Convert__Reg1_0__Reg1_1__ShiftLSLi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 236 /* cmp */, AArch64::CMPxx_lsr, Convert__Reg1_0__Reg1_1__ShiftLSRi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 236 /* cmp */, AArch64::CMPxx_uxtx, Convert__Reg1_0__Reg1_1__RegExtendLSL1_2, 0, { MCK_Rxsp, MCK_GPR64, MCK_RegExtendLSL }, },
  { 236 /* cmp */, AArch64::CMPxw_sxtb, Convert__Reg1_0__Reg1_1__SXTB1_2, 0, { MCK_GPR64xsp, MCK_GPR32, MCK_SXTB }, },
  { 236 /* cmp */, AArch64::CMPxw_sxth, Convert__Reg1_0__Reg1_1__SXTH1_2, 0, { MCK_GPR64xsp, MCK_GPR32, MCK_SXTH }, },
  { 236 /* cmp */, AArch64::CMPxw_sxtw, Convert__Reg1_0__Reg1_1__SXTW1_2, 0, { MCK_GPR64xsp, MCK_GPR32, MCK_SXTW }, },
  { 236 /* cmp */, AArch64::CMPxw_uxtb, Convert__Reg1_0__Reg1_1__UXTB1_2, 0, { MCK_GPR64xsp, MCK_GPR32, MCK_UXTB }, },
  { 236 /* cmp */, AArch64::CMPxw_uxth, Convert__Reg1_0__Reg1_1__UXTH1_2, 0, { MCK_GPR64xsp, MCK_GPR32, MCK_UXTH }, },
  { 236 /* cmp */, AArch64::CMPxw_uxtw, Convert__Reg1_0__Reg1_1__UXTW1_2, 0, { MCK_GPR64xsp, MCK_GPR32, MCK_UXTW }, },
  { 236 /* cmp */, AArch64::CMPxx_sxtx, Convert__Reg1_0__Reg1_1__SXTX1_2, 0, { MCK_GPR64xsp, MCK_GPR64, MCK_SXTX }, },
  { 236 /* cmp */, AArch64::CMPxx_uxtx, Convert__Reg1_0__Reg1_1__UXTX1_2, 0, { MCK_GPR64xsp, MCK_GPR64, MCK_UXTX }, },
  { 240 /* cmtst */, AArch64::CMTSTddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 240 /* cmtst */, AArch64::CMTSTvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 240 /* cmtst */, AArch64::CMTSTvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 240 /* cmtst */, AArch64::CMTSTvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 240 /* cmtst */, AArch64::CMTSTvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 240 /* cmtst */, AArch64::CMTSTvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 240 /* cmtst */, AArch64::CMTSTvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 240 /* cmtst */, AArch64::CMTSTvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 246 /* cneg */, AArch64::CSNEGwwwc, Convert__Reg1_0__Reg1_1__Reg1_1__InvCondCodeOp1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_InvCondCodeOp }, },
  { 246 /* cneg */, AArch64::CSNEGxxxc, Convert__Reg1_0__Reg1_1__Reg1_1__InvCondCodeOp1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_InvCondCodeOp }, },
  { 251 /* cnt */, AArch64::CNT8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 251 /* cnt */, AArch64::CNT16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 255 /* crc32b */, AArch64::CRC32B_www, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 262 /* crc32cb */, AArch64::CRC32CB_www, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 270 /* crc32ch */, AArch64::CRC32CH_www, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 278 /* crc32cw */, AArch64::CRC32CW_www, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 286 /* crc32cx */, AArch64::CRC32CX_wwx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR64 }, },
  { 294 /* crc32h */, AArch64::CRC32H_www, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 301 /* crc32w */, AArch64::CRC32W_www, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 308 /* crc32x */, AArch64::CRC32X_wwx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR64 }, },
  { 315 /* csel */, AArch64::CSELwwwc, Convert__Reg1_0__Reg1_1__Reg1_2__CondCodeOp1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_CondCodeOp }, },
  { 315 /* csel */, AArch64::CSELxxxc, Convert__Reg1_0__Reg1_1__Reg1_2__CondCodeOp1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_CondCodeOp }, },
  { 320 /* cset */, AArch64::CSINCwwwc, Convert__Reg1_0__regWZR__regWZR__InvCondCodeOp1_1, 0, { MCK_GPR32, MCK_InvCondCodeOp }, },
  { 320 /* cset */, AArch64::CSINCxxxc, Convert__Reg1_0__regXZR__regXZR__InvCondCodeOp1_1, 0, { MCK_GPR64, MCK_InvCondCodeOp }, },
  { 325 /* csetm */, AArch64::CSINVwwwc, Convert__Reg1_0__regWZR__regWZR__InvCondCodeOp1_1, 0, { MCK_GPR32, MCK_InvCondCodeOp }, },
  { 325 /* csetm */, AArch64::CSINVxxxc, Convert__Reg1_0__regXZR__regXZR__InvCondCodeOp1_1, 0, { MCK_GPR64, MCK_InvCondCodeOp }, },
  { 331 /* csinc */, AArch64::CSINCwwwc, Convert__Reg1_0__Reg1_1__Reg1_2__CondCodeOp1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_CondCodeOp }, },
  { 331 /* csinc */, AArch64::CSINCxxxc, Convert__Reg1_0__Reg1_1__Reg1_2__CondCodeOp1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_CondCodeOp }, },
  { 337 /* csinv */, AArch64::CSINVwwwc, Convert__Reg1_0__Reg1_1__Reg1_2__CondCodeOp1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_CondCodeOp }, },
  { 337 /* csinv */, AArch64::CSINVxxxc, Convert__Reg1_0__Reg1_1__Reg1_2__CondCodeOp1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_CondCodeOp }, },
  { 343 /* csneg */, AArch64::CSNEGwwwc, Convert__Reg1_0__Reg1_1__Reg1_2__CondCodeOp1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_CondCodeOp }, },
  { 343 /* csneg */, AArch64::CSNEGxxxc, Convert__Reg1_0__Reg1_1__Reg1_2__CondCodeOp1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_CondCodeOp }, },
  { 349 /* dc */, AArch64::DCix, Convert__NamedImmdc1_0__Reg1_1, 0, { MCK_NamedImmdc, MCK_GPR64 }, },
  { 352 /* dcps1 */, AArch64::DCPS1i, Convert__imm_0, 0, {  }, },
  { 352 /* dcps1 */, AArch64::DCPS1i, Convert__UImm161_0, 0, { MCK_UImm16 }, },
  { 358 /* dcps2 */, AArch64::DCPS2i, Convert__imm_0, 0, {  }, },
  { 358 /* dcps2 */, AArch64::DCPS2i, Convert__UImm161_0, 0, { MCK_UImm16 }, },
  { 364 /* dcps3 */, AArch64::DCPS3i, Convert__imm_0, 0, {  }, },
  { 364 /* dcps3 */, AArch64::DCPS3i, Convert__UImm161_0, 0, { MCK_UImm16 }, },
  { 370 /* dmb */, AArch64::DMBi, Convert__NamedImmdbarrier1_0, 0, { MCK_NamedImmdbarrier }, },
  { 374 /* drps */, AArch64::DRPS, Convert_NoOperands, 0, {  }, },
  { 379 /* dsb */, AArch64::DSBi, Convert__NamedImmdbarrier1_0, 0, { MCK_NamedImmdbarrier }, },
  { 383 /* dup */, AArch64::DUP2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_GPR32 }, },
  { 383 /* dup */, AArch64::DUP4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_GPR32 }, },
  { 383 /* dup */, AArch64::DUP8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_GPR32 }, },
  { 383 /* dup */, AArch64::DUP16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_GPR32 }, },
  { 383 /* dup */, AArch64::DUP2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_GPR64 }, },
  { 383 /* dup */, AArch64::DUP4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_GPR32 }, },
  { 383 /* dup */, AArch64::DUP8h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_GPR32 }, },
  { 383 /* dup */, AArch64::DUPbv_B, Convert__Reg1_0__Reg1_1__UImm41_4, Feature_HasNEON, { MCK_FPR8, MCK_FPR128, MCK__DOT_b, MCK__91_, MCK_UImm4, MCK__93_ }, },
  { 383 /* dup */, AArch64::DUPhv_H, Convert__Reg1_0__Reg1_1__UImm31_4, Feature_HasNEON, { MCK_FPR16, MCK_FPR128, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 383 /* dup */, AArch64::DUPsv_S, Convert__Reg1_0__Reg1_1__UImm21_4, Feature_HasNEON, { MCK_FPR32, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 383 /* dup */, AArch64::DUPdv_D, Convert__Reg1_0__Reg1_1__UImm11_4, Feature_HasNEON, { MCK_FPR64, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 383 /* dup */, AArch64::DUPELT2s, Convert__Reg1_0__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 383 /* dup */, AArch64::DUPELT4h, Convert__Reg1_0__Reg1_2__UImm31_5, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 383 /* dup */, AArch64::DUPELT8b, Convert__Reg1_0__Reg1_2__UImm41_5, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_b, MCK__91_, MCK_UImm4, MCK__93_ }, },
  { 383 /* dup */, AArch64::DUPELT16b, Convert__Reg1_0__Reg1_2__UImm41_5, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_b, MCK__91_, MCK_UImm4, MCK__93_ }, },
  { 383 /* dup */, AArch64::DUPELT2d, Convert__Reg1_0__Reg1_2__UImm11_5, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 383 /* dup */, AArch64::DUPELT4s, Convert__Reg1_0__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 383 /* dup */, AArch64::DUPELT8h, Convert__Reg1_0__Reg1_2__UImm31_5, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 387 /* eon */, AArch64::EONwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 387 /* eon */, AArch64::EONxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 387 /* eon */, AArch64::EONwww_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 387 /* eon */, AArch64::EONwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 387 /* eon */, AArch64::EONwww_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 387 /* eon */, AArch64::EONwww_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftRORi32 }, },
  { 387 /* eon */, AArch64::EONxxx_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 387 /* eon */, AArch64::EONxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 387 /* eon */, AArch64::EONxxx_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 387 /* eon */, AArch64::EONxxx_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftRORi64 }, },
  { 391 /* eor */, AArch64::EORwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 391 /* eor */, AArch64::EORwwi, Convert__Reg1_0__Reg1_1__LogicalImm321_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_LogicalImm32 }, },
  { 391 /* eor */, AArch64::EORxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 391 /* eor */, AArch64::EORxxi, Convert__Reg1_0__Reg1_1__LogicalImm641_2, 0, { MCK_GPR64xsp, MCK_GPR64, MCK_LogicalImm64 }, },
  { 391 /* eor */, AArch64::EORwww_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 391 /* eor */, AArch64::EORwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 391 /* eor */, AArch64::EORwww_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 391 /* eor */, AArch64::EORwww_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftRORi32 }, },
  { 391 /* eor */, AArch64::EORxxx_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 391 /* eor */, AArch64::EORxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 391 /* eor */, AArch64::EORxxx_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 391 /* eor */, AArch64::EORxxx_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftRORi64 }, },
  { 391 /* eor */, AArch64::EORvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 391 /* eor */, AArch64::EORvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 395 /* eret */, AArch64::ERET, Convert_NoOperands, 0, {  }, },
  { 400 /* ext */, AArch64::EXTvvvi_8b, Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_6, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_UImm3 }, },
  { 400 /* ext */, AArch64::EXTvvvi_16b, Convert__Reg1_0__Reg1_2__Reg1_4__UImm41_6, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_UImm4 }, },
  { 404 /* extr */, AArch64::EXTRwwwi, Convert__Reg1_0__Reg1_1__Reg1_2__UImm51_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_UImm5 }, },
  { 404 /* extr */, AArch64::EXTRxxxi, Convert__Reg1_0__Reg1_1__Reg1_2__UImm61_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_UImm6 }, },
  { 409 /* fabd */, AArch64::FABDsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 409 /* fabd */, AArch64::FABDddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 409 /* fabd */, AArch64::FABDvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 409 /* fabd */, AArch64::FABDvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 409 /* fabd */, AArch64::FABDvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 414 /* fabs */, AArch64::FABSss, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32 }, },
  { 414 /* fabs */, AArch64::FABSdd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64 }, },
  { 414 /* fabs */, AArch64::FABS2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 414 /* fabs */, AArch64::FABS2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 414 /* fabs */, AArch64::FABS4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 419 /* facge */, AArch64::FACGEsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 419 /* facge */, AArch64::FACGEddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 419 /* facge */, AArch64::FACGEvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 419 /* facge */, AArch64::FACGEvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 419 /* facge */, AArch64::FACGEvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 425 /* facgt */, AArch64::FACGTsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 425 /* facgt */, AArch64::FACGTddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 425 /* facgt */, AArch64::FACGTvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 425 /* facgt */, AArch64::FACGTvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 425 /* facgt */, AArch64::FACGTvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 431 /* facle */, AArch64::FACGEvvv_2S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 431 /* facle */, AArch64::FACGEvvv_2D, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 431 /* facle */, AArch64::FACGEvvv_4S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 437 /* faclt */, AArch64::FACGTvvv_2S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 437 /* faclt */, AArch64::FACGTvvv_2D, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 437 /* faclt */, AArch64::FACGTvvv_4S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 443 /* fadd */, AArch64::FADDsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 443 /* fadd */, AArch64::FADDddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 443 /* fadd */, AArch64::FADDvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 443 /* fadd */, AArch64::FADDvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 443 /* fadd */, AArch64::FADDvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 448 /* faddp */, AArch64::FADDPvv_S_2S, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR64, MCK__DOT_2s }, },
  { 448 /* faddp */, AArch64::FADDPvv_D_2D, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR128, MCK__DOT_2d }, },
  { 448 /* faddp */, AArch64::FADDP_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 448 /* faddp */, AArch64::FADDP_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 448 /* faddp */, AArch64::FADDP_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 454 /* fccmp */, AArch64::FCCMPss, Convert__Reg1_0__Reg1_1__UImm41_2__CondCodeOp1_3, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_UImm4, MCK_CondCodeOp }, },
  { 454 /* fccmp */, AArch64::FCCMPdd, Convert__Reg1_0__Reg1_1__UImm41_2__CondCodeOp1_3, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_UImm4, MCK_CondCodeOp }, },
  { 460 /* fccmpe */, AArch64::FCCMPEss, Convert__Reg1_0__Reg1_1__UImm41_2__CondCodeOp1_3, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_UImm4, MCK_CondCodeOp }, },
  { 460 /* fccmpe */, AArch64::FCCMPEdd, Convert__Reg1_0__Reg1_1__UImm41_2__CondCodeOp1_3, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_UImm4, MCK_CondCodeOp }, },
  { 467 /* fcmeq */, AArch64::FCMEQsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 467 /* fcmeq */, AArch64::FCMEQZssi, Convert__Reg1_0__Reg1_1__FPZero1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPZero }, },
  { 467 /* fcmeq */, AArch64::FCMEQddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 467 /* fcmeq */, AArch64::FCMEQZddi, Convert__Reg1_0__Reg1_1__FPZero1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPZero }, },
  { 467 /* fcmeq */, AArch64::FCMEQvvi_2S, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPZero }, },
  { 467 /* fcmeq */, AArch64::FCMEQvvi_2D, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPZero }, },
  { 467 /* fcmeq */, AArch64::FCMEQvvi_4S, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPZero }, },
  { 467 /* fcmeq */, AArch64::FCMEQvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 467 /* fcmeq */, AArch64::FCMEQvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 467 /* fcmeq */, AArch64::FCMEQvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 473 /* fcmge */, AArch64::FCMGEsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 473 /* fcmge */, AArch64::FCMGEZssi, Convert__Reg1_0__Reg1_1__FPZero1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPZero }, },
  { 473 /* fcmge */, AArch64::FCMGEddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 473 /* fcmge */, AArch64::FCMGEZddi, Convert__Reg1_0__Reg1_1__FPZero1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPZero }, },
  { 473 /* fcmge */, AArch64::FCMGEvvi_2S, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPZero }, },
  { 473 /* fcmge */, AArch64::FCMGEvvi_2D, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPZero }, },
  { 473 /* fcmge */, AArch64::FCMGEvvi_4S, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPZero }, },
  { 473 /* fcmge */, AArch64::FCMGEvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 473 /* fcmge */, AArch64::FCMGEvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 473 /* fcmge */, AArch64::FCMGEvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 479 /* fcmgt */, AArch64::FCMGTsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 479 /* fcmgt */, AArch64::FCMGTZssi, Convert__Reg1_0__Reg1_1__FPZero1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPZero }, },
  { 479 /* fcmgt */, AArch64::FCMGTddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 479 /* fcmgt */, AArch64::FCMGTZddi, Convert__Reg1_0__Reg1_1__FPZero1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPZero }, },
  { 479 /* fcmgt */, AArch64::FCMGTvvi_2S, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPZero }, },
  { 479 /* fcmgt */, AArch64::FCMGTvvi_2D, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPZero }, },
  { 479 /* fcmgt */, AArch64::FCMGTvvi_4S, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPZero }, },
  { 479 /* fcmgt */, AArch64::FCMGTvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 479 /* fcmgt */, AArch64::FCMGTvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 479 /* fcmgt */, AArch64::FCMGTvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 485 /* fcmle */, AArch64::FCMLEZssi, Convert__Reg1_0__Reg1_1__FPZero1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPZero }, },
  { 485 /* fcmle */, AArch64::FCMLEZddi, Convert__Reg1_0__Reg1_1__FPZero1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPZero }, },
  { 485 /* fcmle */, AArch64::FCMLEvvi_2S, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPZero }, },
  { 485 /* fcmle */, AArch64::FCMLEvvi_2D, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPZero }, },
  { 485 /* fcmle */, AArch64::FCMLEvvi_4S, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPZero }, },
  { 485 /* fcmle */, AArch64::FCMGEvvv_2S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 485 /* fcmle */, AArch64::FCMGEvvv_2D, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 485 /* fcmle */, AArch64::FCMGEvvv_4S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 491 /* fcmlt */, AArch64::FCMLTZssi, Convert__Reg1_0__Reg1_1__FPZero1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPZero }, },
  { 491 /* fcmlt */, AArch64::FCMLTZddi, Convert__Reg1_0__Reg1_1__FPZero1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPZero }, },
  { 491 /* fcmlt */, AArch64::FCMLTvvi_2S, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPZero }, },
  { 491 /* fcmlt */, AArch64::FCMLTvvi_2D, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPZero }, },
  { 491 /* fcmlt */, AArch64::FCMLTvvi_4S, Convert__Reg1_0__Reg1_2__FPZero1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPZero }, },
  { 491 /* fcmlt */, AArch64::FCMGTvvv_2S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 491 /* fcmlt */, AArch64::FCMGTvvv_2D, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 491 /* fcmlt */, AArch64::FCMGTvvv_4S, Convert__Reg1_0__Reg1_4__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 497 /* fcmp */, AArch64::FCMPss_quiet, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32 }, },
  { 497 /* fcmp */, AArch64::FCMPsi_quiet, Convert__Reg1_0__FPZero1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPZero }, },
  { 497 /* fcmp */, AArch64::FCMPdd_quiet, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64 }, },
  { 497 /* fcmp */, AArch64::FCMPdi_quiet, Convert__Reg1_0__FPZero1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPZero }, },
  { 502 /* fcmpe */, AArch64::FCMPss_sig, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32 }, },
  { 502 /* fcmpe */, AArch64::FCMPsi_sig, Convert__Reg1_0__FPZero1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPZero }, },
  { 502 /* fcmpe */, AArch64::FCMPdd_sig, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64 }, },
  { 502 /* fcmpe */, AArch64::FCMPdi_sig, Convert__Reg1_0__FPZero1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPZero }, },
  { 508 /* fcsel */, AArch64::FCSELsssc, Convert__Reg1_0__Reg1_1__Reg1_2__CondCodeOp1_3, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32, MCK_CondCodeOp }, },
  { 508 /* fcsel */, AArch64::FCSELdddc, Convert__Reg1_0__Reg1_1__Reg1_2__CondCodeOp1_3, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64, MCK_CondCodeOp }, },
  { 514 /* fcvt */, AArch64::FCVThs, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR16, MCK_FPR32 }, },
  { 514 /* fcvt */, AArch64::FCVThd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR16, MCK_FPR64 }, },
  { 514 /* fcvt */, AArch64::FCVTsh, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR16 }, },
  { 514 /* fcvt */, AArch64::FCVTsd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR64 }, },
  { 514 /* fcvt */, AArch64::FCVTdh, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR16 }, },
  { 514 /* fcvt */, AArch64::FCVTds, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR32 }, },
  { 519 /* fcvtas */, AArch64::FCVTASws, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR32 }, },
  { 519 /* fcvtas */, AArch64::FCVTASwd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR64 }, },
  { 519 /* fcvtas */, AArch64::FCVTASxs, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR32 }, },
  { 519 /* fcvtas */, AArch64::FCVTASxd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR64 }, },
  { 519 /* fcvtas */, AArch64::FCVTASss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 519 /* fcvtas */, AArch64::FCVTASdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 519 /* fcvtas */, AArch64::FCVTAS_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 519 /* fcvtas */, AArch64::FCVTAS_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 519 /* fcvtas */, AArch64::FCVTAS_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 526 /* fcvtau */, AArch64::FCVTAUws, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR32 }, },
  { 526 /* fcvtau */, AArch64::FCVTAUwd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR64 }, },
  { 526 /* fcvtau */, AArch64::FCVTAUxs, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR32 }, },
  { 526 /* fcvtau */, AArch64::FCVTAUxd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR64 }, },
  { 526 /* fcvtau */, AArch64::FCVTAUss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 526 /* fcvtau */, AArch64::FCVTAUdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 526 /* fcvtau */, AArch64::FCVTAU_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 526 /* fcvtau */, AArch64::FCVTAU_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 526 /* fcvtau */, AArch64::FCVTAU_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 533 /* fcvtl */, AArch64::FCVTL2s2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s }, },
  { 533 /* fcvtl */, AArch64::FCVTL4h4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h }, },
  { 539 /* fcvtl2 */, AArch64::FCVTL4s2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s }, },
  { 539 /* fcvtl2 */, AArch64::FCVTL8h4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h }, },
  { 546 /* fcvtms */, AArch64::FCVTMSws, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR32 }, },
  { 546 /* fcvtms */, AArch64::FCVTMSwd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR64 }, },
  { 546 /* fcvtms */, AArch64::FCVTMSxs, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR32 }, },
  { 546 /* fcvtms */, AArch64::FCVTMSxd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR64 }, },
  { 546 /* fcvtms */, AArch64::FCVTMSss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 546 /* fcvtms */, AArch64::FCVTMSdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 546 /* fcvtms */, AArch64::FCVTMS_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 546 /* fcvtms */, AArch64::FCVTMS_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 546 /* fcvtms */, AArch64::FCVTMS_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 553 /* fcvtmu */, AArch64::FCVTMUws, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR32 }, },
  { 553 /* fcvtmu */, AArch64::FCVTMUwd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR64 }, },
  { 553 /* fcvtmu */, AArch64::FCVTMUxs, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR32 }, },
  { 553 /* fcvtmu */, AArch64::FCVTMUxd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR64 }, },
  { 553 /* fcvtmu */, AArch64::FCVTMUss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 553 /* fcvtmu */, AArch64::FCVTMUdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 553 /* fcvtmu */, AArch64::FCVTMU_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 553 /* fcvtmu */, AArch64::FCVTMU_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 553 /* fcvtmu */, AArch64::FCVTMU_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 560 /* fcvtn */, AArch64::FCVTN2d2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d }, },
  { 560 /* fcvtn */, AArch64::FCVTN4s4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s }, },
  { 566 /* fcvtn2 */, AArch64::FCVTN2d4s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d }, },
  { 566 /* fcvtn2 */, AArch64::FCVTN4s8h, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s }, },
  { 573 /* fcvtns */, AArch64::FCVTNSws, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR32 }, },
  { 573 /* fcvtns */, AArch64::FCVTNSwd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR64 }, },
  { 573 /* fcvtns */, AArch64::FCVTNSxs, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR32 }, },
  { 573 /* fcvtns */, AArch64::FCVTNSxd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR64 }, },
  { 573 /* fcvtns */, AArch64::FCVTNSss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 573 /* fcvtns */, AArch64::FCVTNSdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 573 /* fcvtns */, AArch64::FCVTNS_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 573 /* fcvtns */, AArch64::FCVTNS_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 573 /* fcvtns */, AArch64::FCVTNS_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 580 /* fcvtnu */, AArch64::FCVTNUws, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR32 }, },
  { 580 /* fcvtnu */, AArch64::FCVTNUwd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR64 }, },
  { 580 /* fcvtnu */, AArch64::FCVTNUxs, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR32 }, },
  { 580 /* fcvtnu */, AArch64::FCVTNUxd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR64 }, },
  { 580 /* fcvtnu */, AArch64::FCVTNUss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 580 /* fcvtnu */, AArch64::FCVTNUdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 580 /* fcvtnu */, AArch64::FCVTNU_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 580 /* fcvtnu */, AArch64::FCVTNU_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 580 /* fcvtnu */, AArch64::FCVTNU_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 587 /* fcvtps */, AArch64::FCVTPSws, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR32 }, },
  { 587 /* fcvtps */, AArch64::FCVTPSwd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR64 }, },
  { 587 /* fcvtps */, AArch64::FCVTPSxs, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR32 }, },
  { 587 /* fcvtps */, AArch64::FCVTPSxd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR64 }, },
  { 587 /* fcvtps */, AArch64::FCVTPSss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 587 /* fcvtps */, AArch64::FCVTPSdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 587 /* fcvtps */, AArch64::FCVTPS_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 587 /* fcvtps */, AArch64::FCVTPS_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 587 /* fcvtps */, AArch64::FCVTPS_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 594 /* fcvtpu */, AArch64::FCVTPUws, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR32 }, },
  { 594 /* fcvtpu */, AArch64::FCVTPUwd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR64 }, },
  { 594 /* fcvtpu */, AArch64::FCVTPUxs, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR32 }, },
  { 594 /* fcvtpu */, AArch64::FCVTPUxd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR64 }, },
  { 594 /* fcvtpu */, AArch64::FCVTPUss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 594 /* fcvtpu */, AArch64::FCVTPUdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 594 /* fcvtpu */, AArch64::FCVTPU_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 594 /* fcvtpu */, AArch64::FCVTPU_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 594 /* fcvtpu */, AArch64::FCVTPU_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 601 /* fcvtxn */, AArch64::FCVTXN, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR64 }, },
  { 601 /* fcvtxn */, AArch64::FCVTXN2d2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d }, },
  { 608 /* fcvtxn2 */, AArch64::FCVTXN2d4s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d }, },
  { 616 /* fcvtzs */, AArch64::FCVTZSws, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR32 }, },
  { 616 /* fcvtzs */, AArch64::FCVTZSwd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR64 }, },
  { 616 /* fcvtzs */, AArch64::FCVTZSxs, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR32 }, },
  { 616 /* fcvtzs */, AArch64::FCVTZSxd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR64 }, },
  { 616 /* fcvtzs */, AArch64::FCVTZSss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 616 /* fcvtzs */, AArch64::FCVTZSdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 616 /* fcvtzs */, AArch64::FCVTZSwsi, Convert__Reg1_0__Reg1_1__CVTFixedPos321_2, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR32, MCK_CVTFixedPos32 }, },
  { 616 /* fcvtzs */, AArch64::FCVTZSwdi, Convert__Reg1_0__Reg1_1__CVTFixedPos321_2, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR64, MCK_CVTFixedPos32 }, },
  { 616 /* fcvtzs */, AArch64::FCVTZSxsi, Convert__Reg1_0__Reg1_1__CVTFixedPos641_2, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR32, MCK_CVTFixedPos64 }, },
  { 616 /* fcvtzs */, AArch64::FCVTZSxdi, Convert__Reg1_0__Reg1_1__CVTFixedPos641_2, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR64, MCK_CVTFixedPos64 }, },
  { 616 /* fcvtzs */, AArch64::FCVTZS_Nssi, Convert__Reg1_0__Reg1_1__ShrImm321_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_ShrImm32 }, },
  { 616 /* fcvtzs */, AArch64::FCVTZS_Nddi, Convert__Reg1_0__Reg1_1__ShrImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShrImm64 }, },
  { 616 /* fcvtzs */, AArch64::FCVTZS_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 616 /* fcvtzs */, AArch64::FCVTZS_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 616 /* fcvtzs */, AArch64::FCVTZS_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 616 /* fcvtzs */, AArch64::VCVTf2xs_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShrImm32 }, },
  { 616 /* fcvtzs */, AArch64::VCVTf2xs_2D, Convert__Reg1_0__Reg1_2__ShrImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm64 }, },
  { 616 /* fcvtzs */, AArch64::VCVTf2xs_4S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm32 }, },
  { 623 /* fcvtzu */, AArch64::FCVTZUws, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR32 }, },
  { 623 /* fcvtzu */, AArch64::FCVTZUwd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR64 }, },
  { 623 /* fcvtzu */, AArch64::FCVTZUxs, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR32 }, },
  { 623 /* fcvtzu */, AArch64::FCVTZUxd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR64 }, },
  { 623 /* fcvtzu */, AArch64::FCVTZUss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 623 /* fcvtzu */, AArch64::FCVTZUdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 623 /* fcvtzu */, AArch64::FCVTZUwsi, Convert__Reg1_0__Reg1_1__CVTFixedPos321_2, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR32, MCK_CVTFixedPos32 }, },
  { 623 /* fcvtzu */, AArch64::FCVTZUwdi, Convert__Reg1_0__Reg1_1__CVTFixedPos321_2, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR64, MCK_CVTFixedPos32 }, },
  { 623 /* fcvtzu */, AArch64::FCVTZUxsi, Convert__Reg1_0__Reg1_1__CVTFixedPos641_2, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR32, MCK_CVTFixedPos64 }, },
  { 623 /* fcvtzu */, AArch64::FCVTZUxdi, Convert__Reg1_0__Reg1_1__CVTFixedPos641_2, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR64, MCK_CVTFixedPos64 }, },
  { 623 /* fcvtzu */, AArch64::FCVTZU_Nssi, Convert__Reg1_0__Reg1_1__ShrImm321_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_ShrImm32 }, },
  { 623 /* fcvtzu */, AArch64::FCVTZU_Nddi, Convert__Reg1_0__Reg1_1__ShrImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShrImm64 }, },
  { 623 /* fcvtzu */, AArch64::FCVTZU_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 623 /* fcvtzu */, AArch64::FCVTZU_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 623 /* fcvtzu */, AArch64::FCVTZU_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 623 /* fcvtzu */, AArch64::VCVTf2xu_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShrImm32 }, },
  { 623 /* fcvtzu */, AArch64::VCVTf2xu_2D, Convert__Reg1_0__Reg1_2__ShrImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm64 }, },
  { 623 /* fcvtzu */, AArch64::VCVTf2xu_4S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm32 }, },
  { 630 /* fdiv */, AArch64::FDIVsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 630 /* fdiv */, AArch64::FDIVddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 630 /* fdiv */, AArch64::FDIVvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 630 /* fdiv */, AArch64::FDIVvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 630 /* fdiv */, AArch64::FDIVvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 635 /* fmadd */, AArch64::FMADDssss, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 635 /* fmadd */, AArch64::FMADDdddd, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 641 /* fmax */, AArch64::FMAXsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 641 /* fmax */, AArch64::FMAXddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 641 /* fmax */, AArch64::FMAXvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 641 /* fmax */, AArch64::FMAXvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 641 /* fmax */, AArch64::FMAXvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 646 /* fmaxnm */, AArch64::FMAXNMsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 646 /* fmaxnm */, AArch64::FMAXNMddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 646 /* fmaxnm */, AArch64::FMAXNMvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 646 /* fmaxnm */, AArch64::FMAXNMvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 646 /* fmaxnm */, AArch64::FMAXNMvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 653 /* fmaxnmp */, AArch64::FMAXNMPvv_S_2S, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR64, MCK__DOT_2s }, },
  { 653 /* fmaxnmp */, AArch64::FMAXNMPvv_D_2D, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR128, MCK__DOT_2d }, },
  { 653 /* fmaxnmp */, AArch64::FMAXNMPvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 653 /* fmaxnmp */, AArch64::FMAXNMPvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 653 /* fmaxnmp */, AArch64::FMAXNMPvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 661 /* fmaxnmv */, AArch64::FMAXNMV_1s4s, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR128, MCK__DOT_4s }, },
  { 669 /* fmaxp */, AArch64::FMAXPvv_S_2S, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR64, MCK__DOT_2s }, },
  { 669 /* fmaxp */, AArch64::FMAXPvv_D_2D, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR128, MCK__DOT_2d }, },
  { 669 /* fmaxp */, AArch64::FMAXPvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 669 /* fmaxp */, AArch64::FMAXPvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 669 /* fmaxp */, AArch64::FMAXPvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 675 /* fmaxv */, AArch64::FMAXV_1s4s, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR128, MCK__DOT_4s }, },
  { 681 /* fmin */, AArch64::FMINsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 681 /* fmin */, AArch64::FMINddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 681 /* fmin */, AArch64::FMINvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 681 /* fmin */, AArch64::FMINvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 681 /* fmin */, AArch64::FMINvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 686 /* fminnm */, AArch64::FMINNMsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 686 /* fminnm */, AArch64::FMINNMddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 686 /* fminnm */, AArch64::FMINNMvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 686 /* fminnm */, AArch64::FMINNMvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 686 /* fminnm */, AArch64::FMINNMvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 693 /* fminnmp */, AArch64::FMINNMPvv_S_2S, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR64, MCK__DOT_2s }, },
  { 693 /* fminnmp */, AArch64::FMINNMPvv_D_2D, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR128, MCK__DOT_2d }, },
  { 693 /* fminnmp */, AArch64::FMINNMPvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 693 /* fminnmp */, AArch64::FMINNMPvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 693 /* fminnmp */, AArch64::FMINNMPvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 701 /* fminnmv */, AArch64::FMINNMV_1s4s, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR128, MCK__DOT_4s }, },
  { 709 /* fminp */, AArch64::FMINPvv_S_2S, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR64, MCK__DOT_2s }, },
  { 709 /* fminp */, AArch64::FMINPvv_D_2D, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR128, MCK__DOT_2d }, },
  { 709 /* fminp */, AArch64::FMINPvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 709 /* fminp */, AArch64::FMINPvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 709 /* fminp */, AArch64::FMINPvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 715 /* fminv */, AArch64::FMINV_1s4s, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR128, MCK__DOT_4s }, },
  { 721 /* fmla */, AArch64::FMLAvvv_2S, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 721 /* fmla */, AArch64::FMLAvvv_2D, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 721 /* fmla */, AArch64::FMLAvvv_4S, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 721 /* fmla */, AArch64::FMLAssv_4S, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 721 /* fmla */, AArch64::FMLAddv_2D, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm11_5, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 721 /* fmla */, AArch64::FMLAvve_2s4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 721 /* fmla */, AArch64::FMLAvve_2d2d, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm11_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 721 /* fmla */, AArch64::FMLAvve_4s4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 726 /* fmls */, AArch64::FMLSvvv_2S, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 726 /* fmls */, AArch64::FMLSvvv_2D, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 726 /* fmls */, AArch64::FMLSvvv_4S, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 726 /* fmls */, AArch64::FMLSssv_4S, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 726 /* fmls */, AArch64::FMLSddv_2D, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm11_5, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 726 /* fmls */, AArch64::FMLSvve_2s4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 726 /* fmls */, AArch64::FMLSvve_2d2d, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm11_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 726 /* fmls */, AArch64::FMLSvve_4s4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 731 /* fmov */, AArch64::FMOVws, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR32, MCK_FPR32 }, },
  { 731 /* fmov */, AArch64::FMOVxd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR64 }, },
  { 731 /* fmov */, AArch64::FMOVsw, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_GPR32 }, },
  { 731 /* fmov */, AArch64::FMOVss, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32 }, },
  { 731 /* fmov */, AArch64::FMOVsi, Convert__Reg1_0__FMOVImm1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FMOVImm }, },
  { 731 /* fmov */, AArch64::FMOVdx, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_GPR64 }, },
  { 731 /* fmov */, AArch64::FMOVdd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64 }, },
  { 731 /* fmov */, AArch64::FMOVdi, Convert__Reg1_0__FMOVImm1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FMOVImm }, },
  { 731 /* fmov */, AArch64::FMOVvi_2S, Convert__Reg1_0__FMOVImm1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FMOVImm }, },
  { 731 /* fmov */, AArch64::FMOVvi_2D, Convert__Reg1_0__FMOVImm1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FMOVImm }, },
  { 731 /* fmov */, AArch64::FMOVvi_4S, Convert__Reg1_0__FMOVImm1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FMOVImm }, },
  { 731 /* fmov */, AArch64::FMOVxv, Convert__Reg1_0__Reg1_1__Lane11_4, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR128, MCK__DOT_2d, MCK__91_, MCK_Lane1, MCK__93_ }, },
  { 731 /* fmov */, AArch64::FMOVxv, Convert__Reg1_0__Reg1_1__Lane11_4, Feature_HasFPARMv8, { MCK_GPR64, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_Lane1, MCK__93_ }, },
  { 731 /* fmov */, AArch64::FMOVvx, Convert__Reg1_0__Reg1_5__Lane11_3, Feature_HasFPARMv8, { MCK_FPR128, MCK__DOT_2d, MCK__91_, MCK_Lane1, MCK__93_, MCK_GPR64 }, },
  { 731 /* fmov */, AArch64::FMOVvx, Convert__Reg1_0__Reg1_5__Lane11_3, Feature_HasFPARMv8, { MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_Lane1, MCK__93_, MCK_GPR64 }, },
  { 736 /* fmsub */, AArch64::FMSUBssss, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 736 /* fmsub */, AArch64::FMSUBdddd, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 742 /* fmul */, AArch64::FMULsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 742 /* fmul */, AArch64::FMULddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 742 /* fmul */, AArch64::FMULvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 742 /* fmul */, AArch64::FMULvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 742 /* fmul */, AArch64::FMULvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 742 /* fmul */, AArch64::FMULssv_4S, Convert__Reg1_0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 742 /* fmul */, AArch64::FMULddv_2D, Convert__Reg1_0__Reg1_1__Reg1_2__UImm11_5, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 742 /* fmul */, AArch64::FMULve_2s4s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 742 /* fmul */, AArch64::FMULve_2d2d, Convert__Reg1_0__Reg1_2__Reg1_4__UImm11_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 742 /* fmul */, AArch64::FMULve_4s4s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 747 /* fmulx */, AArch64::FMULXsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 747 /* fmulx */, AArch64::FMULXddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 747 /* fmulx */, AArch64::FMULXvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 747 /* fmulx */, AArch64::FMULXvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 747 /* fmulx */, AArch64::FMULXvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 747 /* fmulx */, AArch64::FMULXssv_4S, Convert__Reg1_0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 747 /* fmulx */, AArch64::FMULXddv_2D, Convert__Reg1_0__Reg1_1__Reg1_2__UImm11_5, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 747 /* fmulx */, AArch64::FMULXve_2s4s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 747 /* fmulx */, AArch64::FMULXve_2d2d, Convert__Reg1_0__Reg1_2__Reg1_4__UImm11_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 747 /* fmulx */, AArch64::FMULXve_4s4s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 753 /* fneg */, AArch64::FNEGss, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32 }, },
  { 753 /* fneg */, AArch64::FNEGdd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64 }, },
  { 753 /* fneg */, AArch64::FNEG2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 753 /* fneg */, AArch64::FNEG2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 753 /* fneg */, AArch64::FNEG4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 758 /* fnmadd */, AArch64::FNMADDssss, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 758 /* fnmadd */, AArch64::FNMADDdddd, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 765 /* fnmsub */, AArch64::FNMSUBssss, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 765 /* fnmsub */, AArch64::FNMSUBdddd, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 772 /* fnmul */, AArch64::FNMULsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 772 /* fnmul */, AArch64::FNMULddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 778 /* frecpe */, AArch64::FRECPEss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 778 /* frecpe */, AArch64::FRECPEdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 778 /* frecpe */, AArch64::FRECPE_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 778 /* frecpe */, AArch64::FRECPE_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 778 /* frecpe */, AArch64::FRECPE_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 785 /* frecps */, AArch64::FRECPSsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 785 /* frecps */, AArch64::FRECPSddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 785 /* frecps */, AArch64::FRECPSvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 785 /* frecps */, AArch64::FRECPSvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 785 /* frecps */, AArch64::FRECPSvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 792 /* frecpx */, AArch64::FRECPXss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 792 /* frecpx */, AArch64::FRECPXdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 799 /* frinta */, AArch64::FRINTAss, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32 }, },
  { 799 /* frinta */, AArch64::FRINTAdd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64 }, },
  { 799 /* frinta */, AArch64::FRINTA_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 799 /* frinta */, AArch64::FRINTA_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 799 /* frinta */, AArch64::FRINTA_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 806 /* frinti */, AArch64::FRINTIss, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32 }, },
  { 806 /* frinti */, AArch64::FRINTIdd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64 }, },
  { 806 /* frinti */, AArch64::FRINTI_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 806 /* frinti */, AArch64::FRINTI_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 806 /* frinti */, AArch64::FRINTI_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 813 /* frintm */, AArch64::FRINTMss, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32 }, },
  { 813 /* frintm */, AArch64::FRINTMdd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64 }, },
  { 813 /* frintm */, AArch64::FRINTM_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 813 /* frintm */, AArch64::FRINTM_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 813 /* frintm */, AArch64::FRINTM_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 820 /* frintn */, AArch64::FRINTNss, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32 }, },
  { 820 /* frintn */, AArch64::FRINTNdd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64 }, },
  { 820 /* frintn */, AArch64::FRINTN_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 820 /* frintn */, AArch64::FRINTN_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 820 /* frintn */, AArch64::FRINTN_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 827 /* frintp */, AArch64::FRINTPss, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32 }, },
  { 827 /* frintp */, AArch64::FRINTPdd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64 }, },
  { 827 /* frintp */, AArch64::FRINTP_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 827 /* frintp */, AArch64::FRINTP_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 827 /* frintp */, AArch64::FRINTP_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 834 /* frintx */, AArch64::FRINTXss, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32 }, },
  { 834 /* frintx */, AArch64::FRINTXdd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64 }, },
  { 834 /* frintx */, AArch64::FRINTX_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 834 /* frintx */, AArch64::FRINTX_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 834 /* frintx */, AArch64::FRINTX_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 841 /* frintz */, AArch64::FRINTZss, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32 }, },
  { 841 /* frintz */, AArch64::FRINTZdd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64 }, },
  { 841 /* frintz */, AArch64::FRINTZ_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 841 /* frintz */, AArch64::FRINTZ_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 841 /* frintz */, AArch64::FRINTZ_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 848 /* frsqrte */, AArch64::FRSQRTEss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 848 /* frsqrte */, AArch64::FRSQRTEdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 848 /* frsqrte */, AArch64::FRSQRTE_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 848 /* frsqrte */, AArch64::FRSQRTE_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 848 /* frsqrte */, AArch64::FRSQRTE_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 856 /* frsqrts */, AArch64::FRSQRTSsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 856 /* frsqrts */, AArch64::FRSQRTSddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 856 /* frsqrts */, AArch64::FRSQRTSvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 856 /* frsqrts */, AArch64::FRSQRTSvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 856 /* frsqrts */, AArch64::FRSQRTSvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 864 /* fsqrt */, AArch64::FSQRTss, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32 }, },
  { 864 /* fsqrt */, AArch64::FSQRTdd, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64 }, },
  { 864 /* fsqrt */, AArch64::FSQRT_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 864 /* fsqrt */, AArch64::FSQRT_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 864 /* fsqrt */, AArch64::FSQRT_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 870 /* fsub */, AArch64::FSUBsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 870 /* fsub */, AArch64::FSUBddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 870 /* fsub */, AArch64::FSUBvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 870 /* fsub */, AArch64::FSUBvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 870 /* fsub */, AArch64::FSUBvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 875 /* hint */, AArch64::HINTi, Convert__UImm71_0, 0, { MCK_UImm7 }, },
  { 880 /* hlt */, AArch64::HLTi, Convert__UImm161_0, 0, { MCK_UImm16 }, },
  { 884 /* hvc */, AArch64::HVCi, Convert__UImm161_0, 0, { MCK_UImm16 }, },
  { 888 /* ic */, AArch64::ICi, Convert__NamedImmic1_0, 0, { MCK_NamedImmic }, },
  { 888 /* ic */, AArch64::ICix, Convert__NamedImmic1_0__Reg1_1, 0, { MCK_NamedImmic, MCK_GPR64 }, },
  { 891 /* ins */, AArch64::INSbw, Convert__Reg1_0__Tie0__Reg1_5__UImm41_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_b, MCK__91_, MCK_UImm4, MCK__93_, MCK_GPR32 }, },
  { 891 /* ins */, AArch64::INSdx, Convert__Reg1_0__Tie0__Reg1_5__UImm11_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_, MCK_GPR64 }, },
  { 891 /* ins */, AArch64::INShw, Convert__Reg1_0__Tie0__Reg1_5__UImm31_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_, MCK_GPR32 }, },
  { 891 /* ins */, AArch64::INSsw, Convert__Reg1_0__Tie0__Reg1_5__UImm21_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_, MCK_GPR32 }, },
  { 891 /* ins */, AArch64::INSELb, Convert__Reg1_0__Tie0__Reg1_5__UImm41_3__UImm41_8, Feature_HasNEON, { MCK_FPR128, MCK__DOT_b, MCK__91_, MCK_UImm4, MCK__93_, MCK_FPR128, MCK__DOT_b, MCK__91_, MCK_UImm4, MCK__93_ }, },
  { 891 /* ins */, AArch64::INSELd, Convert__Reg1_0__Tie0__Reg1_5__UImm11_3__UImm11_8, Feature_HasNEON, { MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 891 /* ins */, AArch64::INSELh, Convert__Reg1_0__Tie0__Reg1_5__UImm31_3__UImm31_8, Feature_HasNEON, { MCK_FPR128, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_, MCK_FPR128, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 891 /* ins */, AArch64::INSELs, Convert__Reg1_0__Tie0__Reg1_5__UImm21_3__UImm21_8, Feature_HasNEON, { MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 895 /* isb */, AArch64::ISBi, Convert__imm_15, 0, {  }, },
  { 895 /* isb */, AArch64::ISBi, Convert__NamedImmisb1_0, 0, { MCK_NamedImmisb }, },
  { 899 /* ld1 */, AArch64::LD1_16B, Convert__VOne16B11_0__Reg1_2, Feature_HasNEON, { MCK_VOne16B1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1_1D, Convert__VOne1D11_0__Reg1_2, Feature_HasNEON, { MCK_VOne1D1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1_2D, Convert__VOne2D11_0__Reg1_2, Feature_HasNEON, { MCK_VOne2D1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1_2S, Convert__VOne2S11_0__Reg1_2, Feature_HasNEON, { MCK_VOne2S1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1_4H, Convert__VOne4H11_0__Reg1_2, Feature_HasNEON, { MCK_VOne4H1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1_4S, Convert__VOne4S11_0__Reg1_2, Feature_HasNEON, { MCK_VOne4S1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1_8B, Convert__VOne8B11_0__Reg1_2, Feature_HasNEON, { MCK_VOne8B1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1_8H, Convert__VOne8H11_0__Reg1_2, Feature_HasNEON, { MCK_VOne8H1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x2_16B, Convert__VPair16B21_0__Reg1_2, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x2_1D, Convert__VPair1D21_0__Reg1_2, Feature_HasNEON, { MCK_VPair1D2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x2_2D, Convert__VPair2D21_0__Reg1_2, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x2_2S, Convert__VPair2S21_0__Reg1_2, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x2_4H, Convert__VPair4H21_0__Reg1_2, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x2_4S, Convert__VPair4S21_0__Reg1_2, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x2_8B, Convert__VPair8B21_0__Reg1_2, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x2_8H, Convert__VPair8H21_0__Reg1_2, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x4_16B, Convert__VQuad16B41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x4_1D, Convert__VQuad1D41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad1D4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x4_2D, Convert__VQuad2D41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x4_2S, Convert__VQuad2S41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x4_4H, Convert__VQuad4H41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x4_4S, Convert__VQuad4S41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x4_8B, Convert__VQuad8B41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x4_8H, Convert__VQuad8H41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x3_16B, Convert__VTriple16B31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x3_1D, Convert__VTriple1D31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple1D3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x3_2D, Convert__VTriple2D31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x3_2S, Convert__VTriple2S31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x3_4H, Convert__VTriple4H31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x3_4S, Convert__VTriple4S31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x3_8B, Convert__VTriple8B31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1x3_8H, Convert__VTriple8H31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1WB_16B_register, Convert__VOne16B11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne16B1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1WB_16B_fixed, Convert__VOne16B11_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VOne16B1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 899 /* ld1 */, AArch64::LD1WB_1D_register, Convert__VOne1D11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne1D1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1WB_1D_fixed, Convert__VOne1D11_0__Reg1_2__Tie1__Exact81_4, Feature_HasNEON, { MCK_VOne1D1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 899 /* ld1 */, AArch64::LD1WB_2D_register, Convert__VOne2D11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne2D1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1WB_2D_fixed, Convert__VOne2D11_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VOne2D1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 899 /* ld1 */, AArch64::LD1WB_2S_register, Convert__VOne2S11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne2S1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1WB_2S_fixed, Convert__VOne2S11_0__Reg1_2__Tie1__Exact81_4, Feature_HasNEON, { MCK_VOne2S1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 899 /* ld1 */, AArch64::LD1WB_4H_register, Convert__VOne4H11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne4H1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1WB_4H_fixed, Convert__VOne4H11_0__Reg1_2__Tie1__Exact81_4, Feature_HasNEON, { MCK_VOne4H1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 899 /* ld1 */, AArch64::LD1WB_4S_register, Convert__VOne4S11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne4S1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1WB_4S_fixed, Convert__VOne4S11_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VOne4S1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 899 /* ld1 */, AArch64::LD1WB_8B_register, Convert__VOne8B11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne8B1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1WB_8B_fixed, Convert__VOne8B11_0__Reg1_2__Tie1__Exact81_4, Feature_HasNEON, { MCK_VOne8B1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 899 /* ld1 */, AArch64::LD1WB_8H_register, Convert__VOne8H11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne8H1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1WB_8H_fixed, Convert__VOne8H11_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VOne8H1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_16B_register, Convert__VPair16B21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_16B_fixed, Convert__VPair16B21_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_1D_register, Convert__VPair1D21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair1D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_1D_fixed, Convert__VPair1D21_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VPair1D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_2D_register, Convert__VPair2D21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_2D_fixed, Convert__VPair2D21_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_2S_register, Convert__VPair2S21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_2S_fixed, Convert__VPair2S21_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_4H_register, Convert__VPair4H21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_4H_fixed, Convert__VPair4H21_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_4S_register, Convert__VPair4S21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_4S_fixed, Convert__VPair4S21_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_8B_register, Convert__VPair8B21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_8B_fixed, Convert__VPair8B21_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_8H_register, Convert__VPair8H21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x2WB_8H_fixed, Convert__VPair8H21_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_16B_register, Convert__VQuad16B41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_16B_fixed, Convert__VQuad16B41_0__Reg1_2__Tie1__Exact641_4, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_1D_register, Convert__VQuad1D41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad1D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_1D_fixed, Convert__VQuad1D41_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VQuad1D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_2D_register, Convert__VQuad2D41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_2D_fixed, Convert__VQuad2D41_0__Reg1_2__Tie1__Exact641_4, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_2S_register, Convert__VQuad2S41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_2S_fixed, Convert__VQuad2S41_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_4H_register, Convert__VQuad4H41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_4H_fixed, Convert__VQuad4H41_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_4S_register, Convert__VQuad4S41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_4S_fixed, Convert__VQuad4S41_0__Reg1_2__Tie1__Exact641_4, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_8B_register, Convert__VQuad8B41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_8B_fixed, Convert__VQuad8B41_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_8H_register, Convert__VQuad8H41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x4WB_8H_fixed, Convert__VQuad8H41_0__Reg1_2__Tie1__Exact641_4, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_16B_register, Convert__VTriple16B31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_16B_fixed, Convert__VTriple16B31_0__Reg1_2__Tie1__Exact481_4, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_1D_register, Convert__VTriple1D31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple1D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_1D_fixed, Convert__VTriple1D31_0__Reg1_2__Tie1__Exact241_4, Feature_HasNEON, { MCK_VTriple1D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_2D_register, Convert__VTriple2D31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_2D_fixed, Convert__VTriple2D31_0__Reg1_2__Tie1__Exact481_4, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_2S_register, Convert__VTriple2S31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_2S_fixed, Convert__VTriple2S31_0__Reg1_2__Tie1__Exact241_4, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_4H_register, Convert__VTriple4H31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_4H_fixed, Convert__VTriple4H31_0__Reg1_2__Tie1__Exact241_4, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_4S_register, Convert__VTriple4S31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_4S_fixed, Convert__VTriple4S31_0__Reg1_2__Tie1__Exact481_4, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_8B_register, Convert__VTriple8B31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_8B_fixed, Convert__VTriple8B31_0__Reg1_2__Tie1__Exact241_4, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_8H_register, Convert__VTriple8H31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1x3WB_8H_fixed, Convert__VTriple8H31_0__Reg1_2__Tie1__Exact481_4, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 899 /* ld1 */, AArch64::LD1LN_B, Convert__VOneB11_0__Reg1_5__Tie0__UImm41_2, Feature_HasNEON, { MCK_VOneB1, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1LN_D, Convert__VOneD11_0__Reg1_5__Tie0__UImm11_2, Feature_HasNEON, { MCK_VOneD1, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1LN_H, Convert__VOneH11_0__Reg1_5__Tie0__UImm31_2, Feature_HasNEON, { MCK_VOneH1, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1LN_S, Convert__VOneS11_0__Reg1_5__Tie0__UImm21_2, Feature_HasNEON, { MCK_VOneS1, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 899 /* ld1 */, AArch64::LD1LN_WB_B_register, Convert__VOneB11_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm41_2, Feature_HasNEON, { MCK_VOneB1, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1LN_WB_B_fixed, Convert__VOneB11_0__Reg1_5__Tie1__Exact11_7__Tie0__UImm41_2, Feature_HasNEON, { MCK_VOneB1, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact1 }, },
  { 899 /* ld1 */, AArch64::LD1LN_WB_D_register, Convert__VOneD11_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm11_2, Feature_HasNEON, { MCK_VOneD1, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1LN_WB_D_fixed, Convert__VOneD11_0__Reg1_5__Tie1__Exact81_7__Tie0__UImm11_2, Feature_HasNEON, { MCK_VOneD1, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 899 /* ld1 */, AArch64::LD1LN_WB_H_register, Convert__VOneH11_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm31_2, Feature_HasNEON, { MCK_VOneH1, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1LN_WB_H_fixed, Convert__VOneH11_0__Reg1_5__Tie1__Exact21_7__Tie0__UImm31_2, Feature_HasNEON, { MCK_VOneH1, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact2 }, },
  { 899 /* ld1 */, AArch64::LD1LN_WB_S_register, Convert__VOneS11_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm21_2, Feature_HasNEON, { MCK_VOneS1, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 899 /* ld1 */, AArch64::LD1LN_WB_S_fixed, Convert__VOneS11_0__Reg1_5__Tie1__Exact41_7__Tie0__UImm21_2, Feature_HasNEON, { MCK_VOneS1, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact4 }, },
  { 903 /* ld1r */, AArch64::LD1R_16B, Convert__VOne16B11_0__Reg1_2, Feature_HasNEON, { MCK_VOne16B1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 903 /* ld1r */, AArch64::LD1R_1D, Convert__VOne1D11_0__Reg1_2, Feature_HasNEON, { MCK_VOne1D1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 903 /* ld1r */, AArch64::LD1R_2D, Convert__VOne2D11_0__Reg1_2, Feature_HasNEON, { MCK_VOne2D1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 903 /* ld1r */, AArch64::LD1R_2S, Convert__VOne2S11_0__Reg1_2, Feature_HasNEON, { MCK_VOne2S1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 903 /* ld1r */, AArch64::LD1R_4H, Convert__VOne4H11_0__Reg1_2, Feature_HasNEON, { MCK_VOne4H1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 903 /* ld1r */, AArch64::LD1R_4S, Convert__VOne4S11_0__Reg1_2, Feature_HasNEON, { MCK_VOne4S1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 903 /* ld1r */, AArch64::LD1R_8B, Convert__VOne8B11_0__Reg1_2, Feature_HasNEON, { MCK_VOne8B1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 903 /* ld1r */, AArch64::LD1R_8H, Convert__VOne8H11_0__Reg1_2, Feature_HasNEON, { MCK_VOne8H1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_16B_register, Convert__VOne16B11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne16B1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_16B_fixed, Convert__VOne16B11_0__Reg1_2__Tie1__Exact11_4, Feature_HasNEON, { MCK_VOne16B1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact1 }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_1D_register, Convert__VOne1D11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne1D1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_1D_fixed, Convert__VOne1D11_0__Reg1_2__Tie1__Exact81_4, Feature_HasNEON, { MCK_VOne1D1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_2D_register, Convert__VOne2D11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne2D1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_2D_fixed, Convert__VOne2D11_0__Reg1_2__Tie1__Exact81_4, Feature_HasNEON, { MCK_VOne2D1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_2S_register, Convert__VOne2S11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne2S1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_2S_fixed, Convert__VOne2S11_0__Reg1_2__Tie1__Exact41_4, Feature_HasNEON, { MCK_VOne2S1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact4 }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_4H_register, Convert__VOne4H11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne4H1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_4H_fixed, Convert__VOne4H11_0__Reg1_2__Tie1__Exact21_4, Feature_HasNEON, { MCK_VOne4H1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact2 }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_4S_register, Convert__VOne4S11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne4S1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_4S_fixed, Convert__VOne4S11_0__Reg1_2__Tie1__Exact41_4, Feature_HasNEON, { MCK_VOne4S1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact4 }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_8B_register, Convert__VOne8B11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne8B1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_8B_fixed, Convert__VOne8B11_0__Reg1_2__Tie1__Exact11_4, Feature_HasNEON, { MCK_VOne8B1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact1 }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_8H_register, Convert__VOne8H11_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VOne8H1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 903 /* ld1r */, AArch64::LD1R_WB_8H_fixed, Convert__VOne8H11_0__Reg1_2__Tie1__Exact21_4, Feature_HasNEON, { MCK_VOne8H1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact2 }, },
  { 908 /* ld2 */, AArch64::LD2_16B, Convert__VPair16B21_0__Reg1_2, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 908 /* ld2 */, AArch64::LD2_2D, Convert__VPair2D21_0__Reg1_2, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 908 /* ld2 */, AArch64::LD2_2S, Convert__VPair2S21_0__Reg1_2, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 908 /* ld2 */, AArch64::LD2_4H, Convert__VPair4H21_0__Reg1_2, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 908 /* ld2 */, AArch64::LD2_4S, Convert__VPair4S21_0__Reg1_2, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 908 /* ld2 */, AArch64::LD2_8B, Convert__VPair8B21_0__Reg1_2, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 908 /* ld2 */, AArch64::LD2_8H, Convert__VPair8H21_0__Reg1_2, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 908 /* ld2 */, AArch64::LD2WB_16B_register, Convert__VPair16B21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 908 /* ld2 */, AArch64::LD2WB_16B_fixed, Convert__VPair16B21_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 908 /* ld2 */, AArch64::LD2WB_2D_register, Convert__VPair2D21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 908 /* ld2 */, AArch64::LD2WB_2D_fixed, Convert__VPair2D21_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 908 /* ld2 */, AArch64::LD2WB_2S_register, Convert__VPair2S21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 908 /* ld2 */, AArch64::LD2WB_2S_fixed, Convert__VPair2S21_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 908 /* ld2 */, AArch64::LD2WB_4H_register, Convert__VPair4H21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 908 /* ld2 */, AArch64::LD2WB_4H_fixed, Convert__VPair4H21_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 908 /* ld2 */, AArch64::LD2WB_4S_register, Convert__VPair4S21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 908 /* ld2 */, AArch64::LD2WB_4S_fixed, Convert__VPair4S21_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 908 /* ld2 */, AArch64::LD2WB_8B_register, Convert__VPair8B21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 908 /* ld2 */, AArch64::LD2WB_8B_fixed, Convert__VPair8B21_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 908 /* ld2 */, AArch64::LD2WB_8H_register, Convert__VPair8H21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 908 /* ld2 */, AArch64::LD2WB_8H_fixed, Convert__VPair8H21_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 908 /* ld2 */, AArch64::LD2LN_B, Convert__VPairB21_0__Reg1_5__Tie0__UImm41_2, Feature_HasNEON, { MCK_VPairB2, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 908 /* ld2 */, AArch64::LD2LN_D, Convert__VPairD21_0__Reg1_5__Tie0__UImm11_2, Feature_HasNEON, { MCK_VPairD2, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 908 /* ld2 */, AArch64::LD2LN_H, Convert__VPairH21_0__Reg1_5__Tie0__UImm31_2, Feature_HasNEON, { MCK_VPairH2, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 908 /* ld2 */, AArch64::LD2LN_S, Convert__VPairS21_0__Reg1_5__Tie0__UImm21_2, Feature_HasNEON, { MCK_VPairS2, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 908 /* ld2 */, AArch64::LD2LN_WB_B_register, Convert__VPairB21_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm41_2, Feature_HasNEON, { MCK_VPairB2, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 908 /* ld2 */, AArch64::LD2LN_WB_B_fixed, Convert__VPairB21_0__Reg1_5__Tie1__Exact21_7__Tie0__UImm41_2, Feature_HasNEON, { MCK_VPairB2, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact2 }, },
  { 908 /* ld2 */, AArch64::LD2LN_WB_D_register, Convert__VPairD21_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm11_2, Feature_HasNEON, { MCK_VPairD2, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 908 /* ld2 */, AArch64::LD2LN_WB_D_fixed, Convert__VPairD21_0__Reg1_5__Tie1__Exact161_7__Tie0__UImm11_2, Feature_HasNEON, { MCK_VPairD2, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 908 /* ld2 */, AArch64::LD2LN_WB_H_register, Convert__VPairH21_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm31_2, Feature_HasNEON, { MCK_VPairH2, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 908 /* ld2 */, AArch64::LD2LN_WB_H_fixed, Convert__VPairH21_0__Reg1_5__Tie1__Exact41_7__Tie0__UImm31_2, Feature_HasNEON, { MCK_VPairH2, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact4 }, },
  { 908 /* ld2 */, AArch64::LD2LN_WB_S_register, Convert__VPairS21_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm21_2, Feature_HasNEON, { MCK_VPairS2, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 908 /* ld2 */, AArch64::LD2LN_WB_S_fixed, Convert__VPairS21_0__Reg1_5__Tie1__Exact81_7__Tie0__UImm21_2, Feature_HasNEON, { MCK_VPairS2, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 912 /* ld2r */, AArch64::LD2R_16B, Convert__VPair16B21_0__Reg1_2, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 912 /* ld2r */, AArch64::LD2R_1D, Convert__VPair1D21_0__Reg1_2, Feature_HasNEON, { MCK_VPair1D2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 912 /* ld2r */, AArch64::LD2R_2D, Convert__VPair2D21_0__Reg1_2, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 912 /* ld2r */, AArch64::LD2R_2S, Convert__VPair2S21_0__Reg1_2, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 912 /* ld2r */, AArch64::LD2R_4H, Convert__VPair4H21_0__Reg1_2, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 912 /* ld2r */, AArch64::LD2R_4S, Convert__VPair4S21_0__Reg1_2, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 912 /* ld2r */, AArch64::LD2R_8B, Convert__VPair8B21_0__Reg1_2, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 912 /* ld2r */, AArch64::LD2R_8H, Convert__VPair8H21_0__Reg1_2, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_16B_register, Convert__VPair16B21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_16B_fixed, Convert__VPair16B21_0__Reg1_2__Tie1__Exact21_4, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact2 }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_1D_register, Convert__VPair1D21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair1D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_1D_fixed, Convert__VPair1D21_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VPair1D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_2D_register, Convert__VPair2D21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_2D_fixed, Convert__VPair2D21_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_2S_register, Convert__VPair2S21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_2S_fixed, Convert__VPair2S21_0__Reg1_2__Tie1__Exact81_4, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_4H_register, Convert__VPair4H21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_4H_fixed, Convert__VPair4H21_0__Reg1_2__Tie1__Exact41_4, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact4 }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_4S_register, Convert__VPair4S21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_4S_fixed, Convert__VPair4S21_0__Reg1_2__Tie1__Exact81_4, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_8B_register, Convert__VPair8B21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_8B_fixed, Convert__VPair8B21_0__Reg1_2__Tie1__Exact21_4, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact2 }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_8H_register, Convert__VPair8H21_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 912 /* ld2r */, AArch64::LD2R_WB_8H_fixed, Convert__VPair8H21_0__Reg1_2__Tie1__Exact41_4, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact4 }, },
  { 917 /* ld3 */, AArch64::LD3_16B, Convert__VTriple16B31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 917 /* ld3 */, AArch64::LD3_2D, Convert__VTriple2D31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 917 /* ld3 */, AArch64::LD3_2S, Convert__VTriple2S31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 917 /* ld3 */, AArch64::LD3_4H, Convert__VTriple4H31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 917 /* ld3 */, AArch64::LD3_4S, Convert__VTriple4S31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 917 /* ld3 */, AArch64::LD3_8B, Convert__VTriple8B31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 917 /* ld3 */, AArch64::LD3_8H, Convert__VTriple8H31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 917 /* ld3 */, AArch64::LD3WB_16B_register, Convert__VTriple16B31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 917 /* ld3 */, AArch64::LD3WB_16B_fixed, Convert__VTriple16B31_0__Reg1_2__Tie1__Exact481_4, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 917 /* ld3 */, AArch64::LD3WB_2D_register, Convert__VTriple2D31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 917 /* ld3 */, AArch64::LD3WB_2D_fixed, Convert__VTriple2D31_0__Reg1_2__Tie1__Exact481_4, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 917 /* ld3 */, AArch64::LD3WB_2S_register, Convert__VTriple2S31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 917 /* ld3 */, AArch64::LD3WB_2S_fixed, Convert__VTriple2S31_0__Reg1_2__Tie1__Exact241_4, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 917 /* ld3 */, AArch64::LD3WB_4H_register, Convert__VTriple4H31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 917 /* ld3 */, AArch64::LD3WB_4H_fixed, Convert__VTriple4H31_0__Reg1_2__Tie1__Exact241_4, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 917 /* ld3 */, AArch64::LD3WB_4S_register, Convert__VTriple4S31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 917 /* ld3 */, AArch64::LD3WB_4S_fixed, Convert__VTriple4S31_0__Reg1_2__Tie1__Exact481_4, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 917 /* ld3 */, AArch64::LD3WB_8B_register, Convert__VTriple8B31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 917 /* ld3 */, AArch64::LD3WB_8B_fixed, Convert__VTriple8B31_0__Reg1_2__Tie1__Exact241_4, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 917 /* ld3 */, AArch64::LD3WB_8H_register, Convert__VTriple8H31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 917 /* ld3 */, AArch64::LD3WB_8H_fixed, Convert__VTriple8H31_0__Reg1_2__Tie1__Exact481_4, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 917 /* ld3 */, AArch64::LD3LN_B, Convert__VTripleB31_0__Reg1_5__Tie0__UImm41_2, Feature_HasNEON, { MCK_VTripleB3, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 917 /* ld3 */, AArch64::LD3LN_D, Convert__VTripleD31_0__Reg1_5__Tie0__UImm11_2, Feature_HasNEON, { MCK_VTripleD3, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 917 /* ld3 */, AArch64::LD3LN_H, Convert__VTripleH31_0__Reg1_5__Tie0__UImm31_2, Feature_HasNEON, { MCK_VTripleH3, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 917 /* ld3 */, AArch64::LD3LN_S, Convert__VTripleS31_0__Reg1_5__Tie0__UImm21_2, Feature_HasNEON, { MCK_VTripleS3, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 917 /* ld3 */, AArch64::LD3LN_WB_B_register, Convert__VTripleB31_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm41_2, Feature_HasNEON, { MCK_VTripleB3, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 917 /* ld3 */, AArch64::LD3LN_WB_B_fixed, Convert__VTripleB31_0__Reg1_5__Tie1__Exact31_7__Tie0__UImm41_2, Feature_HasNEON, { MCK_VTripleB3, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact3 }, },
  { 917 /* ld3 */, AArch64::LD3LN_WB_D_register, Convert__VTripleD31_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm11_2, Feature_HasNEON, { MCK_VTripleD3, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 917 /* ld3 */, AArch64::LD3LN_WB_D_fixed, Convert__VTripleD31_0__Reg1_5__Tie1__Exact241_7__Tie0__UImm11_2, Feature_HasNEON, { MCK_VTripleD3, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 917 /* ld3 */, AArch64::LD3LN_WB_H_register, Convert__VTripleH31_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm31_2, Feature_HasNEON, { MCK_VTripleH3, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 917 /* ld3 */, AArch64::LD3LN_WB_H_fixed, Convert__VTripleH31_0__Reg1_5__Tie1__Exact61_7__Tie0__UImm31_2, Feature_HasNEON, { MCK_VTripleH3, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact6 }, },
  { 917 /* ld3 */, AArch64::LD3LN_WB_S_register, Convert__VTripleS31_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm21_2, Feature_HasNEON, { MCK_VTripleS3, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 917 /* ld3 */, AArch64::LD3LN_WB_S_fixed, Convert__VTripleS31_0__Reg1_5__Tie1__Exact121_7__Tie0__UImm21_2, Feature_HasNEON, { MCK_VTripleS3, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact12 }, },
  { 921 /* ld3r */, AArch64::LD3R_16B, Convert__VTriple16B31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 921 /* ld3r */, AArch64::LD3R_1D, Convert__VTriple1D31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple1D3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 921 /* ld3r */, AArch64::LD3R_2D, Convert__VTriple2D31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 921 /* ld3r */, AArch64::LD3R_2S, Convert__VTriple2S31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 921 /* ld3r */, AArch64::LD3R_4H, Convert__VTriple4H31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 921 /* ld3r */, AArch64::LD3R_4S, Convert__VTriple4S31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 921 /* ld3r */, AArch64::LD3R_8B, Convert__VTriple8B31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 921 /* ld3r */, AArch64::LD3R_8H, Convert__VTriple8H31_0__Reg1_2, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_16B_register, Convert__VTriple16B31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_16B_fixed, Convert__VTriple16B31_0__Reg1_2__Tie1__Exact31_4, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact3 }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_1D_register, Convert__VTriple1D31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple1D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_1D_fixed, Convert__VTriple1D31_0__Reg1_2__Tie1__Exact241_4, Feature_HasNEON, { MCK_VTriple1D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_2D_register, Convert__VTriple2D31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_2D_fixed, Convert__VTriple2D31_0__Reg1_2__Tie1__Exact241_4, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_2S_register, Convert__VTriple2S31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_2S_fixed, Convert__VTriple2S31_0__Reg1_2__Tie1__Exact121_4, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact12 }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_4H_register, Convert__VTriple4H31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_4H_fixed, Convert__VTriple4H31_0__Reg1_2__Tie1__Exact61_4, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact6 }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_4S_register, Convert__VTriple4S31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_4S_fixed, Convert__VTriple4S31_0__Reg1_2__Tie1__Exact121_4, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact12 }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_8B_register, Convert__VTriple8B31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_8B_fixed, Convert__VTriple8B31_0__Reg1_2__Tie1__Exact31_4, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact3 }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_8H_register, Convert__VTriple8H31_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 921 /* ld3r */, AArch64::LD3R_WB_8H_fixed, Convert__VTriple8H31_0__Reg1_2__Tie1__Exact61_4, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact6 }, },
  { 926 /* ld4 */, AArch64::LD4_16B, Convert__VQuad16B41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 926 /* ld4 */, AArch64::LD4_2D, Convert__VQuad2D41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 926 /* ld4 */, AArch64::LD4_2S, Convert__VQuad2S41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 926 /* ld4 */, AArch64::LD4_4H, Convert__VQuad4H41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 926 /* ld4 */, AArch64::LD4_4S, Convert__VQuad4S41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 926 /* ld4 */, AArch64::LD4_8B, Convert__VQuad8B41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 926 /* ld4 */, AArch64::LD4_8H, Convert__VQuad8H41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 926 /* ld4 */, AArch64::LD4WB_16B_register, Convert__VQuad16B41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 926 /* ld4 */, AArch64::LD4WB_16B_fixed, Convert__VQuad16B41_0__Reg1_2__Tie1__Exact641_4, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 926 /* ld4 */, AArch64::LD4WB_2D_register, Convert__VQuad2D41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 926 /* ld4 */, AArch64::LD4WB_2D_fixed, Convert__VQuad2D41_0__Reg1_2__Tie1__Exact641_4, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 926 /* ld4 */, AArch64::LD4WB_2S_register, Convert__VQuad2S41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 926 /* ld4 */, AArch64::LD4WB_2S_fixed, Convert__VQuad2S41_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 926 /* ld4 */, AArch64::LD4WB_4H_register, Convert__VQuad4H41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 926 /* ld4 */, AArch64::LD4WB_4H_fixed, Convert__VQuad4H41_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 926 /* ld4 */, AArch64::LD4WB_4S_register, Convert__VQuad4S41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 926 /* ld4 */, AArch64::LD4WB_4S_fixed, Convert__VQuad4S41_0__Reg1_2__Tie1__Exact641_4, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 926 /* ld4 */, AArch64::LD4WB_8B_register, Convert__VQuad8B41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 926 /* ld4 */, AArch64::LD4WB_8B_fixed, Convert__VQuad8B41_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 926 /* ld4 */, AArch64::LD4WB_8H_register, Convert__VQuad8H41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 926 /* ld4 */, AArch64::LD4WB_8H_fixed, Convert__VQuad8H41_0__Reg1_2__Tie1__Exact641_4, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 926 /* ld4 */, AArch64::LD4LN_B, Convert__VQuadB41_0__Reg1_5__Tie0__UImm41_2, Feature_HasNEON, { MCK_VQuadB4, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 926 /* ld4 */, AArch64::LD4LN_D, Convert__VQuadD41_0__Reg1_5__Tie0__UImm11_2, Feature_HasNEON, { MCK_VQuadD4, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 926 /* ld4 */, AArch64::LD4LN_H, Convert__VQuadH41_0__Reg1_5__Tie0__UImm31_2, Feature_HasNEON, { MCK_VQuadH4, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 926 /* ld4 */, AArch64::LD4LN_S, Convert__VQuadS41_0__Reg1_5__Tie0__UImm21_2, Feature_HasNEON, { MCK_VQuadS4, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 926 /* ld4 */, AArch64::LD4LN_WB_B_register, Convert__VQuadB41_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm41_2, Feature_HasNEON, { MCK_VQuadB4, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 926 /* ld4 */, AArch64::LD4LN_WB_B_fixed, Convert__VQuadB41_0__Reg1_5__Tie1__Exact41_7__Tie0__UImm41_2, Feature_HasNEON, { MCK_VQuadB4, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact4 }, },
  { 926 /* ld4 */, AArch64::LD4LN_WB_D_register, Convert__VQuadD41_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm11_2, Feature_HasNEON, { MCK_VQuadD4, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 926 /* ld4 */, AArch64::LD4LN_WB_D_fixed, Convert__VQuadD41_0__Reg1_5__Tie1__Exact321_7__Tie0__UImm11_2, Feature_HasNEON, { MCK_VQuadD4, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 926 /* ld4 */, AArch64::LD4LN_WB_H_register, Convert__VQuadH41_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm31_2, Feature_HasNEON, { MCK_VQuadH4, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 926 /* ld4 */, AArch64::LD4LN_WB_H_fixed, Convert__VQuadH41_0__Reg1_5__Tie1__Exact81_7__Tie0__UImm31_2, Feature_HasNEON, { MCK_VQuadH4, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 926 /* ld4 */, AArch64::LD4LN_WB_S_register, Convert__VQuadS41_0__Reg1_5__Tie1__Reg1_7__Tie0__UImm21_2, Feature_HasNEON, { MCK_VQuadS4, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 926 /* ld4 */, AArch64::LD4LN_WB_S_fixed, Convert__VQuadS41_0__Reg1_5__Tie1__Exact161_7__Tie0__UImm21_2, Feature_HasNEON, { MCK_VQuadS4, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 930 /* ld4r */, AArch64::LD4R_16B, Convert__VQuad16B41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 930 /* ld4r */, AArch64::LD4R_1D, Convert__VQuad1D41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad1D4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 930 /* ld4r */, AArch64::LD4R_2D, Convert__VQuad2D41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 930 /* ld4r */, AArch64::LD4R_2S, Convert__VQuad2S41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 930 /* ld4r */, AArch64::LD4R_4H, Convert__VQuad4H41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 930 /* ld4r */, AArch64::LD4R_4S, Convert__VQuad4S41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 930 /* ld4r */, AArch64::LD4R_8B, Convert__VQuad8B41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 930 /* ld4r */, AArch64::LD4R_8H, Convert__VQuad8H41_0__Reg1_2, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_16B_register, Convert__VQuad16B41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_16B_fixed, Convert__VQuad16B41_0__Reg1_2__Tie1__Exact41_4, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact4 }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_1D_register, Convert__VQuad1D41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad1D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_1D_fixed, Convert__VQuad1D41_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VQuad1D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_2D_register, Convert__VQuad2D41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_2D_fixed, Convert__VQuad2D41_0__Reg1_2__Tie1__Exact321_4, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_2S_register, Convert__VQuad2S41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_2S_fixed, Convert__VQuad2S41_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_4H_register, Convert__VQuad4H41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_4H_fixed, Convert__VQuad4H41_0__Reg1_2__Tie1__Exact81_4, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_4S_register, Convert__VQuad4S41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_4S_fixed, Convert__VQuad4S41_0__Reg1_2__Tie1__Exact161_4, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_8B_register, Convert__VQuad8B41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_8B_fixed, Convert__VQuad8B41_0__Reg1_2__Tie1__Exact41_4, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact4 }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_8H_register, Convert__VQuad8H41_0__Reg1_2__Tie1__Reg1_4, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 930 /* ld4r */, AArch64::LD4R_WB_8H_fixed, Convert__VQuad8H41_0__Reg1_2__Tie1__Exact81_4, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 935 /* ldar */, AArch64::LDAR_word, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 935 /* ldar */, AArch64::LDAR_dword, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 940 /* ldarb */, AArch64::LDAR_byte, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 946 /* ldarh */, AArch64::LDAR_hword, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 952 /* ldaxp */, AArch64::LDAXP_word, Convert__Reg1_0__Reg1_1__GPR64xsp01_3, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 952 /* ldaxp */, AArch64::LDAXP_dword, Convert__Reg1_0__Reg1_1__GPR64xsp01_3, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 958 /* ldaxr */, AArch64::LDAXR_word, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 958 /* ldaxr */, AArch64::LDAXR_dword, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 964 /* ldaxrb */, AArch64::LDAXR_byte, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 971 /* ldaxrh */, AArch64::LDAXR_hword, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 978 /* ldnp */, AArch64::LSPair32_NonTemp_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 978 /* ldnp */, AArch64::LSPair64_NonTemp_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 978 /* ldnp */, AArch64::LSFPPair32_NonTemp_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 978 /* ldnp */, AArch64::LSFPPair64_NonTemp_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 978 /* ldnp */, AArch64::LSFPPair128_NonTemp_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, Feature_HasFPARMv8, { MCK_FPR128, MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 978 /* ldnp */, AArch64::LSPair32_NonTemp_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled41_4, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_ }, },
  { 978 /* ldnp */, AArch64::LSPair64_NonTemp_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled81_4, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled8, MCK__93_ }, },
  { 978 /* ldnp */, AArch64::LSFPPair32_NonTemp_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled41_4, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_ }, },
  { 978 /* ldnp */, AArch64::LSFPPair64_NonTemp_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled81_4, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled8, MCK__93_ }, },
  { 978 /* ldnp */, AArch64::LSFPPair128_NonTemp_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled161_4, Feature_HasFPARMv8, { MCK_FPR128, MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled16, MCK__93_ }, },
  { 983 /* ldp */, AArch64::LSPair32_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 983 /* ldp */, AArch64::LSPair64_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 983 /* ldp */, AArch64::LSFPPair32_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 983 /* ldp */, AArch64::LSFPPair64_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 983 /* ldp */, AArch64::LSFPPair128_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, Feature_HasFPARMv8, { MCK_FPR128, MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 983 /* ldp */, AArch64::LSPair32_PostInd_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled41_5, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm7_Scaled4 }, },
  { 983 /* ldp */, AArch64::LSPair32_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled41_4, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_ }, },
  { 983 /* ldp */, AArch64::LSPair64_PostInd_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled81_5, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm7_Scaled8 }, },
  { 983 /* ldp */, AArch64::LSPair64_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled81_4, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled8, MCK__93_ }, },
  { 983 /* ldp */, AArch64::LSFPPair32_PostInd_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled41_5, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm7_Scaled4 }, },
  { 983 /* ldp */, AArch64::LSFPPair32_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled41_4, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_ }, },
  { 983 /* ldp */, AArch64::LSFPPair64_PostInd_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled81_5, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm7_Scaled8 }, },
  { 983 /* ldp */, AArch64::LSFPPair64_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled81_4, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled8, MCK__93_ }, },
  { 983 /* ldp */, AArch64::LSFPPair128_PostInd_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled161_5, Feature_HasFPARMv8, { MCK_FPR128, MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm7_Scaled16 }, },
  { 983 /* ldp */, AArch64::LSFPPair128_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled161_4, Feature_HasFPARMv8, { MCK_FPR128, MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled16, MCK__93_ }, },
  { 983 /* ldp */, AArch64::LSPair32_PreInd_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled41_4, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_, MCK__EXCLAIM_ }, },
  { 983 /* ldp */, AArch64::LSPair64_PreInd_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled81_4, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled8, MCK__93_, MCK__EXCLAIM_ }, },
  { 983 /* ldp */, AArch64::LSFPPair32_PreInd_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled41_4, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_, MCK__EXCLAIM_ }, },
  { 983 /* ldp */, AArch64::LSFPPair64_PreInd_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled81_4, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled8, MCK__93_, MCK__EXCLAIM_ }, },
  { 983 /* ldp */, AArch64::LSFPPair128_PreInd_LDR, Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled161_4, Feature_HasFPARMv8, { MCK_FPR128, MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled16, MCK__93_, MCK__EXCLAIM_ }, },
  { 987 /* ldpsw */, AArch64::LDPSWx, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 987 /* ldpsw */, AArch64::LDPSWx_PostInd, Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled41_5, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm7_Scaled4 }, },
  { 987 /* ldpsw */, AArch64::LDPSWx, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled41_4, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_ }, },
  { 987 /* ldpsw */, AArch64::LDPSWx_PreInd, Convert__Reg1_0__Reg1_1__Reg1_3__Tie2__SImm7_Scaled41_4, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_, MCK__EXCLAIM_ }, },
  { 993 /* ldr */, AArch64::LDRw_lit, Convert__Reg1_0__LoadLitLabel1_1, 0, { MCK_GPR32, MCK_LoadLitLabel }, },
  { 993 /* ldr */, AArch64::LDRx_lit, Convert__Reg1_0__LoadLitLabel1_1, 0, { MCK_GPR64, MCK_LoadLitLabel }, },
  { 993 /* ldr */, AArch64::LDRs_lit, Convert__Reg1_0__LoadLitLabel1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_LoadLitLabel }, },
  { 993 /* ldr */, AArch64::LDRd_lit, Convert__Reg1_0__LoadLitLabel1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_LoadLitLabel }, },
  { 993 /* ldr */, AArch64::LDRq_lit, Convert__Reg1_0__LoadLitLabel1_1, Feature_HasFPARMv8, { MCK_FPR128, MCK_LoadLitLabel }, },
  { 993 /* ldr */, AArch64::LS32_LDR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LS64_LDR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP8_LDR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP16_LDR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP32_LDR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP64_LDR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP128_LDR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LS32_PostInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 993 /* ldr */, AArch64::LS32_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LS32_LDR, Convert__Reg1_0__Reg1_2__OffsetUImm12_41_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_4, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LS64_PostInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 993 /* ldr */, AArch64::LS64_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LS64_LDR, Convert__Reg1_0__Reg1_2__OffsetUImm12_81_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_8, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP8_PostInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 993 /* ldr */, AArch64::LSFP8_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP8_LDR, Convert__Reg1_0__Reg1_2__OffsetUImm12_11_3, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_1, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP16_PostInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 993 /* ldr */, AArch64::LSFP16_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP16_LDR, Convert__Reg1_0__Reg1_2__OffsetUImm12_21_3, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_2, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP32_PostInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 993 /* ldr */, AArch64::LSFP32_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP32_LDR, Convert__Reg1_0__Reg1_2__OffsetUImm12_41_3, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_4, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP64_PostInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 993 /* ldr */, AArch64::LSFP64_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP64_LDR, Convert__Reg1_0__Reg1_2__OffsetUImm12_81_3, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_8, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP128_PostInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 993 /* ldr */, AArch64::LSFP128_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP128_LDR, Convert__Reg1_0__Reg1_2__OffsetUImm12_161_3, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_16, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LS32_Wm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Wm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_4_Wm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LS32_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Xm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_4_Xm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LS32_PreInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 993 /* ldr */, AArch64::LS64_Wm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Wm1_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_8_Wm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LS64_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Xm1_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_8_Xm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LS64_PreInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 993 /* ldr */, AArch64::LSFP8_Wm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Wm1_4, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_1_Wm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP8_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Xm1_4, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_1_Xm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP8_PreInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 993 /* ldr */, AArch64::LSFP16_Wm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Wm1_4, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_2_Wm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP16_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Xm1_4, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_2_Xm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP16_PreInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 993 /* ldr */, AArch64::LSFP32_Wm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Wm1_4, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_4_Wm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP32_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Xm1_4, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_4_Xm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP32_PreInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 993 /* ldr */, AArch64::LSFP64_Wm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Wm1_4, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_8_Wm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP64_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Xm1_4, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_8_Xm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP64_PreInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 993 /* ldr */, AArch64::LSFP128_Wm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_16_Wm1_4, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_16_Wm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP128_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_16_Xm1_4, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_16_Xm, MCK__93_ }, },
  { 993 /* ldr */, AArch64::LSFP128_PreInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 997 /* ldrb */, AArch64::LS8_LDR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 997 /* ldrb */, AArch64::LS8_PostInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 997 /* ldrb */, AArch64::LS8_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 997 /* ldrb */, AArch64::LS8_LDR, Convert__Reg1_0__Reg1_2__OffsetUImm12_11_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_1, MCK__93_ }, },
  { 997 /* ldrb */, AArch64::LS8_Wm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Wm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_1_Wm, MCK__93_ }, },
  { 997 /* ldrb */, AArch64::LS8_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Xm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_1_Xm, MCK__93_ }, },
  { 997 /* ldrb */, AArch64::LS8_PreInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 1002 /* ldrh */, AArch64::LS16_LDR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1002 /* ldrh */, AArch64::LS16_PostInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 1002 /* ldrh */, AArch64::LS16_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 1002 /* ldrh */, AArch64::LS16_LDR, Convert__Reg1_0__Reg1_2__OffsetUImm12_21_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_2, MCK__93_ }, },
  { 1002 /* ldrh */, AArch64::LS16_Wm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Wm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_2_Wm, MCK__93_ }, },
  { 1002 /* ldrh */, AArch64::LS16_Xm_RegOffset_LDR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Xm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_2_Xm, MCK__93_ }, },
  { 1002 /* ldrh */, AArch64::LS16_PreInd_LDR, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 1007 /* ldrsb */, AArch64::LDRSBw, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1007 /* ldrsb */, AArch64::LDRSBx, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1007 /* ldrsb */, AArch64::LDRSBw_PostInd, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 1007 /* ldrsb */, AArch64::LDRSBw_Xm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 1007 /* ldrsb */, AArch64::LDRSBw, Convert__Reg1_0__Reg1_2__OffsetUImm12_11_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_1, MCK__93_ }, },
  { 1007 /* ldrsb */, AArch64::LDRSBx_PostInd, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 1007 /* ldrsb */, AArch64::LDRSBx_Xm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 1007 /* ldrsb */, AArch64::LDRSBx, Convert__Reg1_0__Reg1_2__OffsetUImm12_11_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_1, MCK__93_ }, },
  { 1007 /* ldrsb */, AArch64::LDRSBw_Wm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Wm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_1_Wm, MCK__93_ }, },
  { 1007 /* ldrsb */, AArch64::LDRSBw_Xm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Xm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_1_Xm, MCK__93_ }, },
  { 1007 /* ldrsb */, AArch64::LDRSBw_PreInd, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 1007 /* ldrsb */, AArch64::LDRSBx_Wm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Wm1_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_1_Wm, MCK__93_ }, },
  { 1007 /* ldrsb */, AArch64::LDRSBx_Xm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Xm1_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_1_Xm, MCK__93_ }, },
  { 1007 /* ldrsb */, AArch64::LDRSBx_PreInd, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 1013 /* ldrsh */, AArch64::LDRSHw, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1013 /* ldrsh */, AArch64::LDRSHx, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1013 /* ldrsh */, AArch64::LDRSHw_PostInd, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 1013 /* ldrsh */, AArch64::LDRSHw_Xm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 1013 /* ldrsh */, AArch64::LDRSHw, Convert__Reg1_0__Reg1_2__OffsetUImm12_21_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_2, MCK__93_ }, },
  { 1013 /* ldrsh */, AArch64::LDRSHx_PostInd, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 1013 /* ldrsh */, AArch64::LDRSHx_Xm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 1013 /* ldrsh */, AArch64::LDRSHx, Convert__Reg1_0__Reg1_2__OffsetUImm12_21_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_2, MCK__93_ }, },
  { 1013 /* ldrsh */, AArch64::LDRSHw_Wm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Wm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_2_Wm, MCK__93_ }, },
  { 1013 /* ldrsh */, AArch64::LDRSHw_Xm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Xm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_2_Xm, MCK__93_ }, },
  { 1013 /* ldrsh */, AArch64::LDRSHw_PreInd, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 1013 /* ldrsh */, AArch64::LDRSHx_Wm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Wm1_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_2_Wm, MCK__93_ }, },
  { 1013 /* ldrsh */, AArch64::LDRSHx_Xm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Xm1_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_2_Xm, MCK__93_ }, },
  { 1013 /* ldrsh */, AArch64::LDRSHx_PreInd, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 1019 /* ldrsw */, AArch64::LDRSWx_lit, Convert__Reg1_0__LoadLitLabel1_1, 0, { MCK_GPR64, MCK_LoadLitLabel }, },
  { 1019 /* ldrsw */, AArch64::LDRSWx, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1019 /* ldrsw */, AArch64::LDRSWx_PostInd, Convert__Reg1_0__Reg1_2__Tie1__SImm91_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 1019 /* ldrsw */, AArch64::LDRSWx_Xm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 1019 /* ldrsw */, AArch64::LDRSWx, Convert__Reg1_0__Reg1_2__OffsetUImm12_41_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_4, MCK__93_ }, },
  { 1019 /* ldrsw */, AArch64::LDRSWx_Wm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Wm1_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_4_Wm, MCK__93_ }, },
  { 1019 /* ldrsw */, AArch64::LDRSWx_Xm_RegOffset, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Xm1_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_4_Xm, MCK__93_ }, },
  { 1019 /* ldrsw */, AArch64::LDRSWx_PreInd, Convert__Reg1_0__Reg1_2__Tie1__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 1025 /* ldtr */, AArch64::LS32_UnPriv_LDR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1025 /* ldtr */, AArch64::LS64_UnPriv_LDR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1025 /* ldtr */, AArch64::LS32_UnPriv_LDR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1025 /* ldtr */, AArch64::LS64_UnPriv_LDR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1030 /* ldtrb */, AArch64::LS8_UnPriv_LDR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1030 /* ldtrb */, AArch64::LS8_UnPriv_LDR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1036 /* ldtrh */, AArch64::LS16_UnPriv_LDR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1036 /* ldtrh */, AArch64::LS16_UnPriv_LDR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1042 /* ldtrsb */, AArch64::LDTRSBw, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1042 /* ldtrsb */, AArch64::LDTRSBx, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1042 /* ldtrsb */, AArch64::LDTRSBw, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1042 /* ldtrsb */, AArch64::LDTRSBx, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1049 /* ldtrsh */, AArch64::LDTRSHw, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1049 /* ldtrsh */, AArch64::LDTRSHx, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1049 /* ldtrsh */, AArch64::LDTRSHw, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1049 /* ldtrsh */, AArch64::LDTRSHx, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1056 /* ldtrsw */, AArch64::LDTRSWx, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1056 /* ldtrsw */, AArch64::LDTRSWx, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LS32_LDUR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LS64_LDUR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LSFP8_LDUR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LSFP16_LDUR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LSFP32_LDUR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LSFP64_LDUR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LSFP128_LDUR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LS32_LDUR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LS64_LDUR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LSFP8_LDUR, Convert__Reg1_0__Reg1_2__SImm91_3, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LSFP16_LDUR, Convert__Reg1_0__Reg1_2__SImm91_3, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LSFP32_LDUR, Convert__Reg1_0__Reg1_2__SImm91_3, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LSFP64_LDUR, Convert__Reg1_0__Reg1_2__SImm91_3, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1063 /* ldur */, AArch64::LSFP128_LDUR, Convert__Reg1_0__Reg1_2__SImm91_3, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1068 /* ldurb */, AArch64::LS8_LDUR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1068 /* ldurb */, AArch64::LS8_LDUR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1074 /* ldurh */, AArch64::LS16_LDUR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1074 /* ldurh */, AArch64::LS16_LDUR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1080 /* ldursb */, AArch64::LDRSBw_U, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1080 /* ldursb */, AArch64::LDRSBx_U, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1087 /* ldursh */, AArch64::LDRSHw_U, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1087 /* ldursh */, AArch64::LDRSHx_U, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1094 /* ldursw */, AArch64::LDURSWx, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1094 /* ldursw */, AArch64::LDURSWx, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1101 /* ldxp */, AArch64::LDXP_word, Convert__Reg1_0__Reg1_1__GPR64xsp01_3, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 1101 /* ldxp */, AArch64::LDXP_dword, Convert__Reg1_0__Reg1_1__GPR64xsp01_3, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 1106 /* ldxr */, AArch64::LDXR_word, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 1106 /* ldxr */, AArch64::LDXR_dword, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 1111 /* ldxrb */, AArch64::LDXR_byte, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 1117 /* ldxrh */, AArch64::LDXR_hword, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 1123 /* lsl */, AArch64::LSLVwww, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 1123 /* lsl */, AArch64::LSLwwi, Convert__Reg1_0__Reg1_1__UImm51_2, 0, { MCK_GPR32, MCK_GPR32, MCK_UImm5 }, },
  { 1123 /* lsl */, AArch64::LSLVxxx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 1123 /* lsl */, AArch64::LSLxxi, Convert__Reg1_0__Reg1_1__UImm61_2, 0, { MCK_GPR64, MCK_GPR64, MCK_UImm6 }, },
  { 1127 /* lsr */, AArch64::LSRVwww, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 1127 /* lsr */, AArch64::LSRwwi, Convert__Reg1_0__Reg1_1__UImm51_2, 0, { MCK_GPR32, MCK_GPR32, MCK_UImm5 }, },
  { 1127 /* lsr */, AArch64::LSRVxxx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 1127 /* lsr */, AArch64::LSRxxi, Convert__Reg1_0__Reg1_1__UImm61_2, 0, { MCK_GPR64, MCK_GPR64, MCK_UImm6 }, },
  { 1131 /* madd */, AArch64::MADDwwww, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 1131 /* madd */, AArch64::MADDxxxx, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 1136 /* mla */, AArch64::MLAvvv_2S, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1136 /* mla */, AArch64::MLAvvv_4H, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1136 /* mla */, AArch64::MLAvvv_8B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1136 /* mla */, AArch64::MLAvvv_16B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1136 /* mla */, AArch64::MLAvvv_4S, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1136 /* mla */, AArch64::MLAvvv_8H, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1136 /* mla */, AArch64::MLAvve_2s4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1136 /* mla */, AArch64::MLAvve_4h8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1136 /* mla */, AArch64::MLAvve_4s4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1136 /* mla */, AArch64::MLAvve_8h8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1140 /* mls */, AArch64::MLSvvv_2S, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1140 /* mls */, AArch64::MLSvvv_4H, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1140 /* mls */, AArch64::MLSvvv_8B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1140 /* mls */, AArch64::MLSvvv_16B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1140 /* mls */, AArch64::MLSvvv_4S, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1140 /* mls */, AArch64::MLSvvv_8H, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1140 /* mls */, AArch64::MLSvve_2s4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1140 /* mls */, AArch64::MLSvve_4h8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1140 /* mls */, AArch64::MLSvve_4s4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1140 /* mls */, AArch64::MLSvve_8h8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1144 /* mneg */, AArch64::MSUBwwww, Convert__Reg1_0__Reg1_1__Reg1_2__regWZR, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 1144 /* mneg */, AArch64::MSUBxxxx, Convert__Reg1_0__Reg1_1__Reg1_2__regXZR, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 1149 /* mov */, AArch64::ORRwww_lsl, Convert__Reg1_0__regWZR__Reg1_1__imm_0, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 1149 /* mov */, AArch64::MOVNwii, Convert__Reg1_0__MOVN32MovAlias2_1, 0, { MCK_GPR32, MCK_MOVN32MovAlias }, },
  { 1149 /* mov */, AArch64::MOVZwii, Convert__Reg1_0__MOVZ32MovAlias2_1, 0, { MCK_GPR32, MCK_MOVZ32MovAlias }, },
  { 1149 /* mov */, AArch64::ADDwwi_lsl0_s, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_Rwsp, MCK_GPR32wsp }, },
  { 1149 /* mov */, AArch64::ADDwwi_lsl0_s, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_GPR32wsp, MCK_Rwsp }, },
  { 1149 /* mov */, AArch64::ORRwwi, Convert__Reg1_0__regWZR__LogicalImmMOV321_1, 0, { MCK_GPR32wsp, MCK_LogicalImmMOV32 }, },
  { 1149 /* mov */, AArch64::ORRxxx_lsl, Convert__Reg1_0__regXZR__Reg1_1__imm_0, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 1149 /* mov */, AArch64::MOVNxii, Convert__Reg1_0__MOVN64MovAlias2_1, 0, { MCK_GPR64, MCK_MOVN64MovAlias }, },
  { 1149 /* mov */, AArch64::MOVZxii, Convert__Reg1_0__MOVZ64MovAlias2_1, 0, { MCK_GPR64, MCK_MOVZ64MovAlias }, },
  { 1149 /* mov */, AArch64::ADDxxi_lsl0_s, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_Rxsp, MCK_GPR64xsp }, },
  { 1149 /* mov */, AArch64::ADDxxi_lsl0_s, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_GPR64xsp, MCK_Rxsp }, },
  { 1149 /* mov */, AArch64::ORRxxi, Convert__Reg1_0__regXZR__LogicalImmMOV641_1, 0, { MCK_GPR64xsp, MCK_LogicalImmMOV64 }, },
  { 1149 /* mov */, AArch64::ORRvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1149 /* mov */, AArch64::ORRvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1149 /* mov */, AArch64::UMOVws, Convert__Reg1_0__Reg1_1__UImm21_4, Feature_HasNEON, { MCK_GPR32, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1149 /* mov */, AArch64::UMOVxd, Convert__Reg1_0__Reg1_1__UImm11_4, Feature_HasNEON, { MCK_GPR64, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 1149 /* mov */, AArch64::DUPbv_B, Convert__Reg1_0__Reg1_1__UImm41_4, Feature_HasNEON, { MCK_FPR8, MCK_FPR128, MCK__DOT_b, MCK__91_, MCK_UImm4, MCK__93_ }, },
  { 1149 /* mov */, AArch64::DUPhv_H, Convert__Reg1_0__Reg1_1__UImm31_4, Feature_HasNEON, { MCK_FPR16, MCK_FPR128, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1149 /* mov */, AArch64::DUPsv_S, Convert__Reg1_0__Reg1_1__UImm21_4, Feature_HasNEON, { MCK_FPR32, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1149 /* mov */, AArch64::DUPdv_D, Convert__Reg1_0__Reg1_1__UImm11_4, Feature_HasNEON, { MCK_FPR64, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 1149 /* mov */, AArch64::INSbw, Convert__Reg1_0__Tie0__Reg1_5__UImm41_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_b, MCK__91_, MCK_UImm4, MCK__93_, MCK_GPR32 }, },
  { 1149 /* mov */, AArch64::INSdx, Convert__Reg1_0__Tie0__Reg1_5__UImm11_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_, MCK_GPR64 }, },
  { 1149 /* mov */, AArch64::INShw, Convert__Reg1_0__Tie0__Reg1_5__UImm31_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_, MCK_GPR32 }, },
  { 1149 /* mov */, AArch64::INSsw, Convert__Reg1_0__Tie0__Reg1_5__UImm21_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_, MCK_GPR32 }, },
  { 1149 /* mov */, AArch64::INSELb, Convert__Reg1_0__Tie0__Reg1_5__UImm41_3__UImm41_8, Feature_HasNEON, { MCK_FPR128, MCK__DOT_b, MCK__91_, MCK_UImm4, MCK__93_, MCK_FPR128, MCK__DOT_b, MCK__91_, MCK_UImm4, MCK__93_ }, },
  { 1149 /* mov */, AArch64::INSELd, Convert__Reg1_0__Tie0__Reg1_5__UImm11_3__UImm11_8, Feature_HasNEON, { MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 1149 /* mov */, AArch64::INSELh, Convert__Reg1_0__Tie0__Reg1_5__UImm31_3__UImm31_8, Feature_HasNEON, { MCK_FPR128, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_, MCK_FPR128, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1149 /* mov */, AArch64::INSELs, Convert__Reg1_0__Tie0__Reg1_5__UImm21_3__UImm21_8, Feature_HasNEON, { MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1153 /* movi */, AArch64::MOVIdi, Convert__Reg1_0__NeonUImm64Mask1_1, Feature_HasNEON, { MCK_FPR64, MCK_NeonUImm64Mask }, },
  { 1153 /* movi */, AArch64::MOVIvi_lsl_2S, Convert__Reg1_0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_UImm8 }, },
  { 1153 /* movi */, AArch64::MOVIvi_lsl_4H, Convert__Reg1_0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_UImm8 }, },
  { 1153 /* movi */, AArch64::MOVIvi_8B, Convert__Reg1_0__UImm81_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_UImm8 }, },
  { 1153 /* movi */, AArch64::MOVIvi_16B, Convert__Reg1_0__UImm81_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_UImm8 }, },
  { 1153 /* movi */, AArch64::MOVIvi_2D, Convert__Reg1_0__NeonUImm64Mask1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_NeonUImm64Mask }, },
  { 1153 /* movi */, AArch64::MOVIvi_lsl_4S, Convert__Reg1_0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_UImm8 }, },
  { 1153 /* movi */, AArch64::MOVIvi_lsl_8H, Convert__Reg1_0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_UImm8 }, },
  { 1153 /* movi */, AArch64::MOVIvi_lsl_2S, Convert__Reg1_0__UImm81_2__NeonMovImmShiftLSL1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_UImm8, MCK_NeonMovImmShiftLSL }, },
  { 1153 /* movi */, AArch64::MOVIvi_msl_2S, Convert__Reg1_0__UImm81_2__NeonMovImmShiftMSL1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_UImm8, MCK_NeonMovImmShiftMSL }, },
  { 1153 /* movi */, AArch64::MOVIvi_lsl_4H, Convert__Reg1_0__UImm81_2__NeonMovImmShiftLSLH1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_UImm8, MCK_NeonMovImmShiftLSLH }, },
  { 1153 /* movi */, AArch64::MOVIvi_lsl_4S, Convert__Reg1_0__UImm81_2__NeonMovImmShiftLSL1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_UImm8, MCK_NeonMovImmShiftLSL }, },
  { 1153 /* movi */, AArch64::MOVIvi_msl_4S, Convert__Reg1_0__UImm81_2__NeonMovImmShiftMSL1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_UImm8, MCK_NeonMovImmShiftMSL }, },
  { 1153 /* movi */, AArch64::MOVIvi_lsl_8H, Convert__Reg1_0__UImm81_2__NeonMovImmShiftLSLH1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_UImm8, MCK_NeonMovImmShiftLSLH }, },
  { 1158 /* movk */, AArch64::MOVKwii, Convert__Reg1_0__Tie0__MOVK32Shiftedshift2_1, 0, { MCK_GPR32, MCK_MOVK32Shiftedshift }, },
  { 1158 /* movk */, AArch64::MOVKxii, Convert__Reg1_0__Tie0__MOVK64Shiftedshift2_1, 0, { MCK_GPR64, MCK_MOVK64Shiftedshift }, },
  { 1163 /* movn */, AArch64::MOVNwii, Convert__Reg1_0__MOVN32Shiftedshift2_1, 0, { MCK_GPR32, MCK_MOVN32Shiftedshift }, },
  { 1163 /* movn */, AArch64::MOVNxii, Convert__Reg1_0__MOVN64Shiftedshift2_1, 0, { MCK_GPR64, MCK_MOVN64Shiftedshift }, },
  { 1168 /* movz */, AArch64::MOVZwii, Convert__Reg1_0__MOVZ32Shiftedshift2_1, 0, { MCK_GPR32, MCK_MOVZ32Shiftedshift }, },
  { 1168 /* movz */, AArch64::MOVZxii, Convert__Reg1_0__MOVZ64Shiftedshift2_1, 0, { MCK_GPR64, MCK_MOVZ64Shiftedshift }, },
  { 1173 /* mrs */, AArch64::MRSxi, Convert__Reg1_0__MRS1_1, 0, { MCK_GPR64, MCK_MRS }, },
  { 1177 /* msr */, AArch64::MSRix, Convert__MSRWithReg1_0__Reg1_1, 0, { MCK_MSRWithReg, MCK_GPR64 }, },
  { 1177 /* msr */, AArch64::MSRii, Convert__MSRPState1_0__UImm41_1, 0, { MCK_MSRPState, MCK_UImm4 }, },
  { 1181 /* msub */, AArch64::MSUBwwww, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 1181 /* msub */, AArch64::MSUBxxxx, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 1186 /* mul */, AArch64::MADDwwww, Convert__Reg1_0__Reg1_1__Reg1_2__regWZR, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 1186 /* mul */, AArch64::MADDxxxx, Convert__Reg1_0__Reg1_1__Reg1_2__regXZR, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 1186 /* mul */, AArch64::MULvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1186 /* mul */, AArch64::MULvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1186 /* mul */, AArch64::MULvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1186 /* mul */, AArch64::MULvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1186 /* mul */, AArch64::MULvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1186 /* mul */, AArch64::MULvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1186 /* mul */, AArch64::MULve_2s4s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1186 /* mul */, AArch64::MULve_4h8h, Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1186 /* mul */, AArch64::MULve_4s4s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1186 /* mul */, AArch64::MULve_8h8h, Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1190 /* mvn */, AArch64::MVNww_lsl, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 1190 /* mvn */, AArch64::MVNxx_lsl, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 1190 /* mvn */, AArch64::MVNww_asr, Convert__Reg1_0__Reg1_1__ShiftASRi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 1190 /* mvn */, AArch64::MVNww_lsl, Convert__Reg1_0__Reg1_1__ShiftLSLi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 1190 /* mvn */, AArch64::MVNww_lsr, Convert__Reg1_0__Reg1_1__ShiftLSRi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 1190 /* mvn */, AArch64::MVNww_ror, Convert__Reg1_0__Reg1_1__ShiftRORi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftRORi32 }, },
  { 1190 /* mvn */, AArch64::MVNxx_asr, Convert__Reg1_0__Reg1_1__ShiftASRi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 1190 /* mvn */, AArch64::MVNxx_lsl, Convert__Reg1_0__Reg1_1__ShiftLSLi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 1190 /* mvn */, AArch64::MVNxx_lsr, Convert__Reg1_0__Reg1_1__ShiftLSRi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 1190 /* mvn */, AArch64::MVNxx_ror, Convert__Reg1_0__Reg1_1__ShiftRORi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftRORi64 }, },
  { 1190 /* mvn */, AArch64::NOT8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1190 /* mvn */, AArch64::NOT16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1194 /* mvni */, AArch64::MVNIvi_lsl_2S, Convert__Reg1_0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_UImm8 }, },
  { 1194 /* mvni */, AArch64::MVNIvi_lsl_4H, Convert__Reg1_0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_UImm8 }, },
  { 1194 /* mvni */, AArch64::MVNIvi_lsl_4S, Convert__Reg1_0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_UImm8 }, },
  { 1194 /* mvni */, AArch64::MVNIvi_lsl_8H, Convert__Reg1_0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_UImm8 }, },
  { 1194 /* mvni */, AArch64::MVNIvi_lsl_2S, Convert__Reg1_0__UImm81_2__NeonMovImmShiftLSL1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_UImm8, MCK_NeonMovImmShiftLSL }, },
  { 1194 /* mvni */, AArch64::MVNIvi_msl_2S, Convert__Reg1_0__UImm81_2__NeonMovImmShiftMSL1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_UImm8, MCK_NeonMovImmShiftMSL }, },
  { 1194 /* mvni */, AArch64::MVNIvi_lsl_4H, Convert__Reg1_0__UImm81_2__NeonMovImmShiftLSLH1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_UImm8, MCK_NeonMovImmShiftLSLH }, },
  { 1194 /* mvni */, AArch64::MVNIvi_lsl_4S, Convert__Reg1_0__UImm81_2__NeonMovImmShiftLSL1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_UImm8, MCK_NeonMovImmShiftLSL }, },
  { 1194 /* mvni */, AArch64::MVNIvi_msl_4S, Convert__Reg1_0__UImm81_2__NeonMovImmShiftMSL1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_UImm8, MCK_NeonMovImmShiftMSL }, },
  { 1194 /* mvni */, AArch64::MVNIvi_lsl_8H, Convert__Reg1_0__UImm81_2__NeonMovImmShiftLSLH1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_UImm8, MCK_NeonMovImmShiftLSLH }, },
  { 1199 /* neg */, AArch64::SUBwww_lsl, Convert__Reg1_0__regWZR__Reg1_1__imm_0, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 1199 /* neg */, AArch64::SUBxxx_lsl, Convert__Reg1_0__regXZR__Reg1_1__imm_0, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 1199 /* neg */, AArch64::NEGdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 1199 /* neg */, AArch64::SUBwww_asr, Convert__Reg1_0__regWZR__Reg1_1__ShiftASRi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 1199 /* neg */, AArch64::SUBwww_lsl, Convert__Reg1_0__regWZR__Reg1_1__ShiftLSLi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 1199 /* neg */, AArch64::SUBwww_lsr, Convert__Reg1_0__regWZR__Reg1_1__ShiftLSRi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 1199 /* neg */, AArch64::SUBxxx_asr, Convert__Reg1_0__regXZR__Reg1_1__ShiftASRi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 1199 /* neg */, AArch64::SUBxxx_lsl, Convert__Reg1_0__regXZR__Reg1_1__ShiftLSLi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 1199 /* neg */, AArch64::SUBxxx_lsr, Convert__Reg1_0__regXZR__Reg1_1__ShiftLSRi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 1199 /* neg */, AArch64::NEG2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1199 /* neg */, AArch64::NEG4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1199 /* neg */, AArch64::NEG8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1199 /* neg */, AArch64::NEG16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1199 /* neg */, AArch64::NEG2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1199 /* neg */, AArch64::NEG4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1199 /* neg */, AArch64::NEG8h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1203 /* negs */, AArch64::SUBSwww_lsl, Convert__Reg1_0__regWZR__Reg1_1__imm_0, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 1203 /* negs */, AArch64::SUBSxxx_lsl, Convert__Reg1_0__regXZR__Reg1_1__imm_0, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 1203 /* negs */, AArch64::SUBSwww_asr, Convert__Reg1_0__regWZR__Reg1_1__ShiftASRi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 1203 /* negs */, AArch64::SUBSwww_lsl, Convert__Reg1_0__regWZR__Reg1_1__ShiftLSLi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 1203 /* negs */, AArch64::SUBSwww_lsr, Convert__Reg1_0__regWZR__Reg1_1__ShiftLSRi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 1203 /* negs */, AArch64::SUBSxxx_asr, Convert__Reg1_0__regXZR__Reg1_1__ShiftASRi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 1203 /* negs */, AArch64::SUBSxxx_lsl, Convert__Reg1_0__regXZR__Reg1_1__ShiftLSLi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 1203 /* negs */, AArch64::SUBSxxx_lsr, Convert__Reg1_0__regXZR__Reg1_1__ShiftLSRi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 1208 /* ngc */, AArch64::SBCwww, Convert__Reg1_0__regWZR__Reg1_1, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 1208 /* ngc */, AArch64::SBCxxx, Convert__Reg1_0__regXZR__Reg1_1, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 1212 /* ngcs */, AArch64::SBCSwww, Convert__Reg1_0__regWZR__Reg1_1, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 1212 /* ngcs */, AArch64::SBCSxxx, Convert__Reg1_0__regXZR__Reg1_1, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 1217 /* nop */, AArch64::HINTi, Convert__imm_0, 0, {  }, },
  { 1221 /* not */, AArch64::NOT8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1221 /* not */, AArch64::NOT16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1225 /* orn */, AArch64::ORNwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 1225 /* orn */, AArch64::ORNxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 1225 /* orn */, AArch64::ORNwww_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 1225 /* orn */, AArch64::ORNwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 1225 /* orn */, AArch64::ORNwww_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 1225 /* orn */, AArch64::ORNwww_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftRORi32 }, },
  { 1225 /* orn */, AArch64::ORNxxx_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 1225 /* orn */, AArch64::ORNxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 1225 /* orn */, AArch64::ORNxxx_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 1225 /* orn */, AArch64::ORNxxx_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftRORi64 }, },
  { 1225 /* orn */, AArch64::ORNvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1225 /* orn */, AArch64::ORNvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1229 /* orr */, AArch64::ORRwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 1229 /* orr */, AArch64::ORRwwi, Convert__Reg1_0__Reg1_1__LogicalImm321_2, 0, { MCK_GPR32wsp, MCK_GPR32, MCK_LogicalImm32 }, },
  { 1229 /* orr */, AArch64::ORRxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 1229 /* orr */, AArch64::ORRxxi, Convert__Reg1_0__Reg1_1__LogicalImm641_2, 0, { MCK_GPR64xsp, MCK_GPR64, MCK_LogicalImm64 }, },
  { 1229 /* orr */, AArch64::ORRvi_lsl_2S, Convert__Reg1_0__Tie0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_UImm8 }, },
  { 1229 /* orr */, AArch64::ORRvi_lsl_4H, Convert__Reg1_0__Tie0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_UImm8 }, },
  { 1229 /* orr */, AArch64::ORRvi_lsl_4S, Convert__Reg1_0__Tie0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_UImm8 }, },
  { 1229 /* orr */, AArch64::ORRvi_lsl_8H, Convert__Reg1_0__Tie0__UImm81_2__imm_0, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_UImm8 }, },
  { 1229 /* orr */, AArch64::ORRwww_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 1229 /* orr */, AArch64::ORRwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 1229 /* orr */, AArch64::ORRwww_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 1229 /* orr */, AArch64::ORRwww_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftRORi32 }, },
  { 1229 /* orr */, AArch64::ORRxxx_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 1229 /* orr */, AArch64::ORRxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 1229 /* orr */, AArch64::ORRxxx_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 1229 /* orr */, AArch64::ORRxxx_ror, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftRORi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftRORi64 }, },
  { 1229 /* orr */, AArch64::ORRvi_lsl_2S, Convert__Reg1_0__Tie0__UImm81_2__NeonMovImmShiftLSL1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_UImm8, MCK_NeonMovImmShiftLSL }, },
  { 1229 /* orr */, AArch64::ORRvi_lsl_4H, Convert__Reg1_0__Tie0__UImm81_2__NeonMovImmShiftLSLH1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_UImm8, MCK_NeonMovImmShiftLSLH }, },
  { 1229 /* orr */, AArch64::ORRvi_lsl_4S, Convert__Reg1_0__Tie0__UImm81_2__NeonMovImmShiftLSL1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_UImm8, MCK_NeonMovImmShiftLSL }, },
  { 1229 /* orr */, AArch64::ORRvi_lsl_8H, Convert__Reg1_0__Tie0__UImm81_2__NeonMovImmShiftLSLH1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_UImm8, MCK_NeonMovImmShiftLSLH }, },
  { 1229 /* orr */, AArch64::ORRvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1229 /* orr */, AArch64::ORRvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1233 /* pmul */, AArch64::PMULvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1233 /* pmul */, AArch64::PMULvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1238 /* pmull */, AArch64::PMULLvvv_1q1d, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_1q, MCK_FPR64, MCK__DOT_1d, MCK_FPR64, MCK__DOT_1d }, },
  { 1238 /* pmull */, AArch64::PMULLvvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1244 /* pmull2 */, AArch64::PMULL2vvv_1q2d, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_1q, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1244 /* pmull2 */, AArch64::PMULL2vvv_8h16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1251 /* prfm */, AArch64::PRFM_lit, Convert__NamedImmprefetch1_0__LoadLitLabel1_1, 0, { MCK_NamedImmprefetch, MCK_LoadLitLabel }, },
  { 1251 /* prfm */, AArch64::PRFM, Convert__NamedImmprefetch1_0__Reg1_2__imm_0, 0, { MCK_NamedImmprefetch, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1251 /* prfm */, AArch64::PRFM_Xm_RegOffset, Convert__NamedImmprefetch1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_NamedImmprefetch, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 1251 /* prfm */, AArch64::PRFM, Convert__NamedImmprefetch1_0__Reg1_2__OffsetUImm12_81_3, 0, { MCK_NamedImmprefetch, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_8, MCK__93_ }, },
  { 1251 /* prfm */, AArch64::PRFM_Wm_RegOffset, Convert__NamedImmprefetch1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Wm1_4, 0, { MCK_NamedImmprefetch, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_8_Wm, MCK__93_ }, },
  { 1251 /* prfm */, AArch64::PRFM_Xm_RegOffset, Convert__NamedImmprefetch1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Xm1_4, 0, { MCK_NamedImmprefetch, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_8_Xm, MCK__93_ }, },
  { 1256 /* prfum */, AArch64::PRFUM, Convert__NamedImmprefetch1_0__Reg1_2__imm_0, 0, { MCK_NamedImmprefetch, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1256 /* prfum */, AArch64::PRFUM, Convert__NamedImmprefetch1_0__Reg1_2__SImm91_3, 0, { MCK_NamedImmprefetch, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 1262 /* raddhn */, AArch64::RADDHNvvv_2s2d, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1262 /* raddhn */, AArch64::RADDHNvvv_4h4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1262 /* raddhn */, AArch64::RADDHNvvv_8b8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1269 /* raddhn2 */, AArch64::RADDHN2vvv_16b8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1269 /* raddhn2 */, AArch64::RADDHN2vvv_4s2d, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1269 /* raddhn2 */, AArch64::RADDHN2vvv_8h4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1277 /* rbit */, AArch64::RBITww, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 1277 /* rbit */, AArch64::RBITxx, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 1277 /* rbit */, AArch64::RBIT8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1277 /* rbit */, AArch64::RBIT16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1282 /* ret */, AArch64::RETx, Convert__regX30, 0, {  }, },
  { 1282 /* ret */, AArch64::RETx, Convert__Reg1_0, 0, { MCK_GPR64 }, },
  { 1286 /* rev */, AArch64::REVww, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 1286 /* rev */, AArch64::REVxx, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 1290 /* rev16 */, AArch64::REV16ww, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 1290 /* rev16 */, AArch64::REV16xx, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 1290 /* rev16 */, AArch64::REV16_8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1290 /* rev16 */, AArch64::REV16_16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1296 /* rev32 */, AArch64::REV32xx, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 1296 /* rev32 */, AArch64::REV32_4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1296 /* rev32 */, AArch64::REV32_8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1296 /* rev32 */, AArch64::REV32_16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1296 /* rev32 */, AArch64::REV32_8h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1302 /* rev64 */, AArch64::REV64_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1302 /* rev64 */, AArch64::REV64_4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1302 /* rev64 */, AArch64::REV64_8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1302 /* rev64 */, AArch64::REV64_16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1302 /* rev64 */, AArch64::REV64_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1302 /* rev64 */, AArch64::REV64_8h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1308 /* ror */, AArch64::RORVwww, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 1308 /* ror */, AArch64::EXTRwwwi, Convert__Reg1_0__Reg1_1__Reg1_1__UImm51_2, 0, { MCK_GPR32, MCK_GPR32, MCK_UImm5 }, },
  { 1308 /* ror */, AArch64::RORVxxx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 1308 /* ror */, AArch64::EXTRxxxi, Convert__Reg1_0__Reg1_1__Reg1_1__UImm61_2, 0, { MCK_GPR64, MCK_GPR64, MCK_UImm6 }, },
  { 1312 /* rshrn */, AArch64::RSHRNvvi_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 1312 /* rshrn */, AArch64::RSHRNvvi_4H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 1312 /* rshrn */, AArch64::RSHRNvvi_8B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 1318 /* rshrn2 */, AArch64::RSHRNvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 1318 /* rshrn2 */, AArch64::RSHRNvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 1318 /* rshrn2 */, AArch64::RSHRNvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 1325 /* rsubhn */, AArch64::RSUBHNvvv_2s2d, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1325 /* rsubhn */, AArch64::RSUBHNvvv_4h4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1325 /* rsubhn */, AArch64::RSUBHNvvv_8b8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1332 /* rsubhn2 */, AArch64::RSUBHN2vvv_16b8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1332 /* rsubhn2 */, AArch64::RSUBHN2vvv_4s2d, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1332 /* rsubhn2 */, AArch64::RSUBHN2vvv_8h4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1340 /* saba */, AArch64::SABAvvv_2S, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1340 /* saba */, AArch64::SABAvvv_4H, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1340 /* saba */, AArch64::SABAvvv_8B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1340 /* saba */, AArch64::SABAvvv_16B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1340 /* saba */, AArch64::SABAvvv_4S, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1340 /* saba */, AArch64::SABAvvv_8H, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1345 /* sabal */, AArch64::SABALvvv_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1345 /* sabal */, AArch64::SABALvvv_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1345 /* sabal */, AArch64::SABALvvv_8h8b, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1351 /* sabal2 */, AArch64::SABAL2vvv_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1351 /* sabal2 */, AArch64::SABAL2vvv_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1351 /* sabal2 */, AArch64::SABAL2vvv_8h8b, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1358 /* sabd */, AArch64::SABDvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1358 /* sabd */, AArch64::SABDvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1358 /* sabd */, AArch64::SABDvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1358 /* sabd */, AArch64::SABDvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1358 /* sabd */, AArch64::SABDvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1358 /* sabd */, AArch64::SABDvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1363 /* sabdl */, AArch64::SABDLvvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1363 /* sabdl */, AArch64::SABDLvvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1363 /* sabdl */, AArch64::SABDLvvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1369 /* sabdl2 */, AArch64::SABDL2vvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1369 /* sabdl2 */, AArch64::SABDL2vvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1369 /* sabdl2 */, AArch64::SABDL2vvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1376 /* sadalp */, AArch64::SADALP2s1d, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_1d, MCK_FPR64, MCK__DOT_2s }, },
  { 1376 /* sadalp */, AArch64::SADALP4h2s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_4h }, },
  { 1376 /* sadalp */, AArch64::SADALP8b4h, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_8b }, },
  { 1376 /* sadalp */, AArch64::SADALP4s2d, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s }, },
  { 1376 /* sadalp */, AArch64::SADALP8h4s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h }, },
  { 1376 /* sadalp */, AArch64::SADALP16b8h, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b }, },
  { 1383 /* saddl */, AArch64::SADDLvvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1383 /* saddl */, AArch64::SADDLvvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1383 /* saddl */, AArch64::SADDLvvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1389 /* saddl2 */, AArch64::SADDL2vvv_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1389 /* saddl2 */, AArch64::SADDL2vvv_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1389 /* saddl2 */, AArch64::SADDL2vvv_8h16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1396 /* saddlp */, AArch64::SADDLP2s1d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_1d, MCK_FPR64, MCK__DOT_2s }, },
  { 1396 /* saddlp */, AArch64::SADDLP4h2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_4h }, },
  { 1396 /* saddlp */, AArch64::SADDLP8b4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_8b }, },
  { 1396 /* saddlp */, AArch64::SADDLP4s2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s }, },
  { 1396 /* saddlp */, AArch64::SADDLP8h4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h }, },
  { 1396 /* saddlp */, AArch64::SADDLP16b8h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b }, },
  { 1403 /* saddlv */, AArch64::SADDLV_1h8b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR64, MCK__DOT_8b }, },
  { 1403 /* saddlv */, AArch64::SADDLV_1h16b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR128, MCK__DOT_16b }, },
  { 1403 /* saddlv */, AArch64::SADDLV_1s4h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR64, MCK__DOT_4h }, },
  { 1403 /* saddlv */, AArch64::SADDLV_1s8h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR128, MCK__DOT_8h }, },
  { 1403 /* saddlv */, AArch64::SADDLV_1d4s, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR128, MCK__DOT_4s }, },
  { 1410 /* saddw */, AArch64::SADDWvvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s }, },
  { 1410 /* saddw */, AArch64::SADDWvvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h }, },
  { 1410 /* saddw */, AArch64::SADDWvvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b }, },
  { 1416 /* saddw2 */, AArch64::SADDW2vvv_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s }, },
  { 1416 /* saddw2 */, AArch64::SADDW2vvv_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h }, },
  { 1416 /* saddw2 */, AArch64::SADDW2vvv_8h16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b }, },
  { 1423 /* sbc */, AArch64::SBCwww, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 1423 /* sbc */, AArch64::SBCxxx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 1427 /* sbcs */, AArch64::SBCSwww, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 1427 /* sbcs */, AArch64::SBCSxxx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 1432 /* sbfiz */, AArch64::SBFIZwwii, Convert__Reg1_0__Reg1_1__BFI32LSB1_2__BFI32Width1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_BFI32LSB, MCK_BFI32Width }, },
  { 1432 /* sbfiz */, AArch64::SBFIZxxii, Convert__Reg1_0__Reg1_1__BFI64LSB1_2__BFI64Width1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_BFI64LSB, MCK_BFI64Width }, },
  { 1438 /* sbfm */, AArch64::SBFMwwii, Convert__Reg1_0__Reg1_1__UImm51_2__UImm51_3, 0, { MCK_GPR32, MCK_GPR32, MCK_UImm5, MCK_UImm5 }, },
  { 1438 /* sbfm */, AArch64::SBFMxxii, Convert__Reg1_0__Reg1_1__UImm61_2__UImm61_3, 0, { MCK_GPR64, MCK_GPR64, MCK_UImm6, MCK_UImm6 }, },
  { 1443 /* sbfx */, AArch64::SBFXwwii, Convert__Reg1_0__Reg1_1__UImm51_2__BFX32Width1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_UImm5, MCK_BFX32Width }, },
  { 1443 /* sbfx */, AArch64::SBFXxxii, Convert__Reg1_0__Reg1_1__UImm61_2__BFX64Width1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_UImm6, MCK_BFX64Width }, },
  { 1448 /* scvtf */, AArch64::SCVTFsw, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_GPR32 }, },
  { 1448 /* scvtf */, AArch64::SCVTFsx, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_GPR64 }, },
  { 1448 /* scvtf */, AArch64::SCVTFss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 1448 /* scvtf */, AArch64::SCVTFdw, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_GPR32 }, },
  { 1448 /* scvtf */, AArch64::SCVTFdx, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_GPR64 }, },
  { 1448 /* scvtf */, AArch64::SCVTFdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 1448 /* scvtf */, AArch64::SCVTFswi, Convert__Reg1_0__Reg1_1__CVTFixedPos321_2, Feature_HasFPARMv8, { MCK_FPR32, MCK_GPR32, MCK_CVTFixedPos32 }, },
  { 1448 /* scvtf */, AArch64::SCVTFsxi, Convert__Reg1_0__Reg1_1__CVTFixedPos641_2, Feature_HasFPARMv8, { MCK_FPR32, MCK_GPR64, MCK_CVTFixedPos64 }, },
  { 1448 /* scvtf */, AArch64::SCVTF_Nssi, Convert__Reg1_0__Reg1_1__ShrImm321_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_ShrImm32 }, },
  { 1448 /* scvtf */, AArch64::SCVTFdwi, Convert__Reg1_0__Reg1_1__CVTFixedPos321_2, Feature_HasFPARMv8, { MCK_FPR64, MCK_GPR32, MCK_CVTFixedPos32 }, },
  { 1448 /* scvtf */, AArch64::SCVTFdxi, Convert__Reg1_0__Reg1_1__CVTFixedPos641_2, Feature_HasFPARMv8, { MCK_FPR64, MCK_GPR64, MCK_CVTFixedPos64 }, },
  { 1448 /* scvtf */, AArch64::SCVTF_Nddi, Convert__Reg1_0__Reg1_1__ShrImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShrImm64 }, },
  { 1448 /* scvtf */, AArch64::SCVTF_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1448 /* scvtf */, AArch64::SCVTF_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1448 /* scvtf */, AArch64::SCVTF_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1448 /* scvtf */, AArch64::VCVTxs2f_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShrImm32 }, },
  { 1448 /* scvtf */, AArch64::VCVTxs2f_2D, Convert__Reg1_0__Reg1_2__ShrImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm64 }, },
  { 1448 /* scvtf */, AArch64::VCVTxs2f_4S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm32 }, },
  { 1454 /* sdiv */, AArch64::SDIVwww, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 1454 /* sdiv */, AArch64::SDIVxxx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 1459 /* sev */, AArch64::HINTi, Convert__imm_4, 0, {  }, },
  { 1463 /* sevl */, AArch64::HINTi, Convert__imm_5, 0, {  }, },
  { 1468 /* sha1c */, AArch64::SHA1C, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2, Feature_HasNEON|Feature_HasCrypto, { MCK_FPR128, MCK_FPR32, MCK_FPR128, MCK__DOT_4s }, },
  { 1474 /* sha1h */, AArch64::SHA1H, Convert__Reg1_0__Reg1_1, Feature_HasNEON|Feature_HasCrypto, { MCK_FPR32, MCK_FPR32 }, },
  { 1480 /* sha1m */, AArch64::SHA1M, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2, Feature_HasNEON|Feature_HasCrypto, { MCK_FPR128, MCK_FPR32, MCK_FPR128, MCK__DOT_4s }, },
  { 1486 /* sha1p */, AArch64::SHA1P, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2, Feature_HasNEON|Feature_HasCrypto, { MCK_FPR128, MCK_FPR32, MCK_FPR128, MCK__DOT_4s }, },
  { 1492 /* sha1su0 */, AArch64::SHA1SU0, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON|Feature_HasCrypto, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1500 /* sha1su1 */, AArch64::SHA1SU1, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON|Feature_HasCrypto, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1508 /* sha256h */, AArch64::SHA256H, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2, Feature_HasNEON|Feature_HasCrypto, { MCK_FPR128, MCK_FPR128, MCK_FPR128, MCK__DOT_4s }, },
  { 1516 /* sha256h2 */, AArch64::SHA256H2, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2, Feature_HasNEON|Feature_HasCrypto, { MCK_FPR128, MCK_FPR128, MCK_FPR128, MCK__DOT_4s }, },
  { 1525 /* sha256su0 */, AArch64::SHA256SU0, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON|Feature_HasCrypto, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1535 /* sha256su1 */, AArch64::SHA256SU1, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON|Feature_HasCrypto, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1545 /* shadd */, AArch64::SHADDvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1545 /* shadd */, AArch64::SHADDvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1545 /* shadd */, AArch64::SHADDvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1545 /* shadd */, AArch64::SHADDvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1545 /* shadd */, AArch64::SHADDvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1545 /* shadd */, AArch64::SHADDvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1551 /* shl */, AArch64::SHLddi, Convert__Reg1_0__Reg1_1__ShlImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShlImm64 }, },
  { 1551 /* shl */, AArch64::SHLvvi_2S, Convert__Reg1_0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShlImm32 }, },
  { 1551 /* shl */, AArch64::SHLvvi_4H, Convert__Reg1_0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShlImm16 }, },
  { 1551 /* shl */, AArch64::SHLvvi_8B, Convert__Reg1_0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShlImm8 }, },
  { 1551 /* shl */, AArch64::SHLvvi_16B, Convert__Reg1_0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShlImm8 }, },
  { 1551 /* shl */, AArch64::SHLvvi_2D, Convert__Reg1_0__Reg1_2__ShlImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShlImm64 }, },
  { 1551 /* shl */, AArch64::SHLvvi_4S, Convert__Reg1_0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShlImm32 }, },
  { 1551 /* shl */, AArch64::SHLvvi_8H, Convert__Reg1_0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShlImm16 }, },
  { 1555 /* shll */, AArch64::SHLL2s2d, Convert__Reg1_0__Reg1_2__Exact321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_Exact32 }, },
  { 1555 /* shll */, AArch64::SHLL4h4s, Convert__Reg1_0__Reg1_2__Exact161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_Exact16 }, },
  { 1555 /* shll */, AArch64::SHLL8b8h, Convert__Reg1_0__Reg1_2__Exact81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_Exact8 }, },
  { 1560 /* shll2 */, AArch64::SHLL4s2d, Convert__Reg1_0__Reg1_2__Exact321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_Exact32 }, },
  { 1560 /* shll2 */, AArch64::SHLL8h4s, Convert__Reg1_0__Reg1_2__Exact161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_Exact16 }, },
  { 1560 /* shll2 */, AArch64::SHLL16b8h, Convert__Reg1_0__Reg1_2__Exact81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_Exact8 }, },
  { 1566 /* shrn */, AArch64::SHRNvvi_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 1566 /* shrn */, AArch64::SHRNvvi_4H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 1566 /* shrn */, AArch64::SHRNvvi_8B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 1571 /* shrn2 */, AArch64::SHRNvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 1571 /* shrn2 */, AArch64::SHRNvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 1571 /* shrn2 */, AArch64::SHRNvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 1577 /* shsub */, AArch64::SHSUBvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1577 /* shsub */, AArch64::SHSUBvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1577 /* shsub */, AArch64::SHSUBvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1577 /* shsub */, AArch64::SHSUBvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1577 /* shsub */, AArch64::SHSUBvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1577 /* shsub */, AArch64::SHSUBvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1583 /* sli */, AArch64::SLI, Convert__Reg1_0__Tie0__Reg1_1__ShlImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShlImm64 }, },
  { 1583 /* sli */, AArch64::SLIvvi_2S, Convert__Reg1_0__Tie0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShlImm32 }, },
  { 1583 /* sli */, AArch64::SLIvvi_4H, Convert__Reg1_0__Tie0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShlImm16 }, },
  { 1583 /* sli */, AArch64::SLIvvi_8B, Convert__Reg1_0__Tie0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShlImm8 }, },
  { 1583 /* sli */, AArch64::SLIvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShlImm8 }, },
  { 1583 /* sli */, AArch64::SLIvvi_2D, Convert__Reg1_0__Tie0__Reg1_2__ShlImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShlImm64 }, },
  { 1583 /* sli */, AArch64::SLIvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShlImm32 }, },
  { 1583 /* sli */, AArch64::SLIvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShlImm16 }, },
  { 1587 /* smaddl */, AArch64::SMADDLxwwx, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_GPR64, MCK_GPR32, MCK_GPR32, MCK_GPR64 }, },
  { 1594 /* smax */, AArch64::SMAXvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1594 /* smax */, AArch64::SMAXvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1594 /* smax */, AArch64::SMAXvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1594 /* smax */, AArch64::SMAXvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1594 /* smax */, AArch64::SMAXvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1594 /* smax */, AArch64::SMAXvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1599 /* smaxp */, AArch64::SMAXPvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1599 /* smaxp */, AArch64::SMAXPvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1599 /* smaxp */, AArch64::SMAXPvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1599 /* smaxp */, AArch64::SMAXPvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1599 /* smaxp */, AArch64::SMAXPvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1599 /* smaxp */, AArch64::SMAXPvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1605 /* smaxv */, AArch64::SMAXV_1b8b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR64, MCK__DOT_8b }, },
  { 1605 /* smaxv */, AArch64::SMAXV_1b16b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR128, MCK__DOT_16b }, },
  { 1605 /* smaxv */, AArch64::SMAXV_1h4h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR64, MCK__DOT_4h }, },
  { 1605 /* smaxv */, AArch64::SMAXV_1h8h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR128, MCK__DOT_8h }, },
  { 1605 /* smaxv */, AArch64::SMAXV_1s4s, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR128, MCK__DOT_4s }, },
  { 1611 /* smc */, AArch64::SMCi, Convert__UImm161_0, 0, { MCK_UImm16 }, },
  { 1615 /* smin */, AArch64::SMINvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1615 /* smin */, AArch64::SMINvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1615 /* smin */, AArch64::SMINvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1615 /* smin */, AArch64::SMINvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1615 /* smin */, AArch64::SMINvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1615 /* smin */, AArch64::SMINvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1620 /* sminp */, AArch64::SMINPvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1620 /* sminp */, AArch64::SMINPvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1620 /* sminp */, AArch64::SMINPvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1620 /* sminp */, AArch64::SMINPvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1620 /* sminp */, AArch64::SMINPvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1620 /* sminp */, AArch64::SMINPvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1626 /* sminv */, AArch64::SMINV_1b8b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR64, MCK__DOT_8b }, },
  { 1626 /* sminv */, AArch64::SMINV_1b16b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR128, MCK__DOT_16b }, },
  { 1626 /* sminv */, AArch64::SMINV_1h4h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR64, MCK__DOT_4h }, },
  { 1626 /* sminv */, AArch64::SMINV_1h8h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR128, MCK__DOT_8h }, },
  { 1626 /* sminv */, AArch64::SMINV_1s4s, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR128, MCK__DOT_4s }, },
  { 1632 /* smlal */, AArch64::SMLALvvv_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1632 /* smlal */, AArch64::SMLALvvv_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1632 /* smlal */, AArch64::SMLALvvv_8h8b, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1632 /* smlal */, AArch64::SMLALvve_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1632 /* smlal */, AArch64::SMLALvve_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1638 /* smlal2 */, AArch64::SMLAL2vvv_2d4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1638 /* smlal2 */, AArch64::SMLAL2vvv_4s8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1638 /* smlal2 */, AArch64::SMLAL2vvv_8h16b, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1638 /* smlal2 */, AArch64::SMLALvve_2d4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1638 /* smlal2 */, AArch64::SMLALvve_4s8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1645 /* smlsl */, AArch64::SMLSLvvv_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1645 /* smlsl */, AArch64::SMLSLvvv_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1645 /* smlsl */, AArch64::SMLSLvvv_8h8b, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1645 /* smlsl */, AArch64::SMLSLvve_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1645 /* smlsl */, AArch64::SMLSLvve_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1651 /* smlsl2 */, AArch64::SMLSL2vvv_2d4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1651 /* smlsl2 */, AArch64::SMLSL2vvv_4s8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1651 /* smlsl2 */, AArch64::SMLSL2vvv_8h16b, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1651 /* smlsl2 */, AArch64::SMLSLvve_2d4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1651 /* smlsl2 */, AArch64::SMLSLvve_4s8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1658 /* smnegl */, AArch64::SMSUBLxwwx, Convert__Reg1_0__Reg1_1__Reg1_2__regXZR, 0, { MCK_GPR64, MCK_GPR32, MCK_GPR32 }, },
  { 1665 /* smov */, AArch64::SMOVwb, Convert__Reg1_0__Reg1_1__UImm41_4, Feature_HasNEON, { MCK_GPR32, MCK_FPR128, MCK__DOT_b, MCK__91_, MCK_UImm4, MCK__93_ }, },
  { 1665 /* smov */, AArch64::SMOVwh, Convert__Reg1_0__Reg1_1__UImm31_4, Feature_HasNEON, { MCK_GPR32, MCK_FPR128, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1665 /* smov */, AArch64::SMOVxb, Convert__Reg1_0__Reg1_1__UImm41_4, Feature_HasNEON, { MCK_GPR64, MCK_FPR128, MCK__DOT_b, MCK__91_, MCK_UImm4, MCK__93_ }, },
  { 1665 /* smov */, AArch64::SMOVxh, Convert__Reg1_0__Reg1_1__UImm31_4, Feature_HasNEON, { MCK_GPR64, MCK_FPR128, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1665 /* smov */, AArch64::SMOVxs, Convert__Reg1_0__Reg1_1__UImm21_4, Feature_HasNEON, { MCK_GPR64, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1670 /* smsubl */, AArch64::SMSUBLxwwx, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_GPR64, MCK_GPR32, MCK_GPR32, MCK_GPR64 }, },
  { 1677 /* smulh */, AArch64::SMULHxxx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 1683 /* smull */, AArch64::SMADDLxwwx, Convert__Reg1_0__Reg1_1__Reg1_2__regXZR, 0, { MCK_GPR64, MCK_GPR32, MCK_GPR32 }, },
  { 1683 /* smull */, AArch64::SMULLvvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1683 /* smull */, AArch64::SMULLvvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1683 /* smull */, AArch64::SMULLvvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1683 /* smull */, AArch64::SMULLve_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1683 /* smull */, AArch64::SMULLve_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1689 /* smull2 */, AArch64::SMULL2vvv_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1689 /* smull2 */, AArch64::SMULL2vvv_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1689 /* smull2 */, AArch64::SMULL2vvv_8h16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1689 /* smull2 */, AArch64::SMULLve_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1689 /* smull2 */, AArch64::SMULLve_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1696 /* sqabs */, AArch64::SQABSbb, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR8 }, },
  { 1696 /* sqabs */, AArch64::SQABShh, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR16 }, },
  { 1696 /* sqabs */, AArch64::SQABSss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 1696 /* sqabs */, AArch64::SQABSdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 1696 /* sqabs */, AArch64::SQABS2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1696 /* sqabs */, AArch64::SQABS4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1696 /* sqabs */, AArch64::SQABS8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1696 /* sqabs */, AArch64::SQABS16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1696 /* sqabs */, AArch64::SQABS2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1696 /* sqabs */, AArch64::SQABS4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1696 /* sqabs */, AArch64::SQABS8h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1702 /* sqadd */, AArch64::SQADDbbb, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR8, MCK_FPR8 }, },
  { 1702 /* sqadd */, AArch64::SQADDhhh, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR16 }, },
  { 1702 /* sqadd */, AArch64::SQADDsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 1702 /* sqadd */, AArch64::SQADDddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 1702 /* sqadd */, AArch64::SQADDvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1702 /* sqadd */, AArch64::SQADDvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1702 /* sqadd */, AArch64::SQADDvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1702 /* sqadd */, AArch64::SQADDvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1702 /* sqadd */, AArch64::SQADDvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1702 /* sqadd */, AArch64::SQADDvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1702 /* sqadd */, AArch64::SQADDvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1708 /* sqdmlal */, AArch64::SQDMLALshh, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR16, MCK_FPR16 }, },
  { 1708 /* sqdmlal */, AArch64::SQDMLALdss, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR32, MCK_FPR32 }, },
  { 1708 /* sqdmlal */, AArch64::SQDMLALvvv_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1708 /* sqdmlal */, AArch64::SQDMLALvvv_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1708 /* sqdmlal */, AArch64::SQDMLALshv_4H, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR16, MCK_FPR64Lo, MCK__DOT_h, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1708 /* sqdmlal */, AArch64::SQDMLALshv_8H, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm31_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR16, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1708 /* sqdmlal */, AArch64::SQDMLALdsv_2S, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm11_5, Feature_HasNEON, { MCK_FPR64, MCK_FPR32, MCK_FPR64, MCK__DOT_s, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 1708 /* sqdmlal */, AArch64::SQDMLALdsv_4S, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR64, MCK_FPR32, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1708 /* sqdmlal */, AArch64::SQDMLALvve_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1708 /* sqdmlal */, AArch64::SQDMLALvve_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1716 /* sqdmlal2 */, AArch64::SQDMLAL2vvv_2d4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1716 /* sqdmlal2 */, AArch64::SQDMLAL2vvv_4s8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1716 /* sqdmlal2 */, AArch64::SQDMLALvve_2d4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1716 /* sqdmlal2 */, AArch64::SQDMLALvve_4s8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1725 /* sqdmlsl */, AArch64::SQDMLSLshh, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR16, MCK_FPR16 }, },
  { 1725 /* sqdmlsl */, AArch64::SQDMLSLdss, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR32, MCK_FPR32 }, },
  { 1725 /* sqdmlsl */, AArch64::SQDMLSLvvv_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1725 /* sqdmlsl */, AArch64::SQDMLSLvvv_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1725 /* sqdmlsl */, AArch64::SQDMLSLshv_4H, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR16, MCK_FPR64Lo, MCK__DOT_h, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1725 /* sqdmlsl */, AArch64::SQDMLSLshv_8H, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm31_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR16, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1725 /* sqdmlsl */, AArch64::SQDMLSLdsv_2S, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm11_5, Feature_HasNEON, { MCK_FPR64, MCK_FPR32, MCK_FPR64, MCK__DOT_s, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 1725 /* sqdmlsl */, AArch64::SQDMLSLdsv_4S, Convert__Reg1_0__Tie0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR64, MCK_FPR32, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1725 /* sqdmlsl */, AArch64::SQDMLSLvve_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1725 /* sqdmlsl */, AArch64::SQDMLSLvve_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1733 /* sqdmlsl2 */, AArch64::SQDMLSL2vvv_2d4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1733 /* sqdmlsl2 */, AArch64::SQDMLSL2vvv_4s8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1733 /* sqdmlsl2 */, AArch64::SQDMLSLvve_2d4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1733 /* sqdmlsl2 */, AArch64::SQDMLSLvve_4s8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHhhh, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR16 }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHhhv_4H, Convert__Reg1_0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR64Lo, MCK__DOT_h, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHhhv_8H, Convert__Reg1_0__Reg1_1__Reg1_2__UImm31_5, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHssv_2S, Convert__Reg1_0__Reg1_1__Reg1_2__UImm11_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR64, MCK__DOT_s, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHssv_4S, Convert__Reg1_0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHve_2s4s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHve_4h8h, Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHve_4s4s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1742 /* sqdmulh */, AArch64::SQDMULHve_8h8h, Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1750 /* sqdmull */, AArch64::SQDMULLshh, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR16, MCK_FPR16 }, },
  { 1750 /* sqdmull */, AArch64::SQDMULLdss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR32, MCK_FPR32 }, },
  { 1750 /* sqdmull */, AArch64::SQDMULLvvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1750 /* sqdmull */, AArch64::SQDMULLvvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1750 /* sqdmull */, AArch64::SQDMULLshv_4H, Convert__Reg1_0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR16, MCK_FPR64Lo, MCK__DOT_h, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1750 /* sqdmull */, AArch64::SQDMULLshv_8H, Convert__Reg1_0__Reg1_1__Reg1_2__UImm31_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR16, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1750 /* sqdmull */, AArch64::SQDMULLdsv_2S, Convert__Reg1_0__Reg1_1__Reg1_2__UImm11_5, Feature_HasNEON, { MCK_FPR64, MCK_FPR32, MCK_FPR64, MCK__DOT_s, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 1750 /* sqdmull */, AArch64::SQDMULLdsv_4S, Convert__Reg1_0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR64, MCK_FPR32, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1750 /* sqdmull */, AArch64::SQDMULLve_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1750 /* sqdmull */, AArch64::SQDMULLve_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1758 /* sqdmull2 */, AArch64::SQDMULL2vvv_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1758 /* sqdmull2 */, AArch64::SQDMULL2vvv_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1758 /* sqdmull2 */, AArch64::SQDMULLve_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1758 /* sqdmull2 */, AArch64::SQDMULLve_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1767 /* sqneg */, AArch64::SQNEGbb, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR8 }, },
  { 1767 /* sqneg */, AArch64::SQNEGhh, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR16 }, },
  { 1767 /* sqneg */, AArch64::SQNEGss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 1767 /* sqneg */, AArch64::SQNEGdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 1767 /* sqneg */, AArch64::SQNEG2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1767 /* sqneg */, AArch64::SQNEG4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1767 /* sqneg */, AArch64::SQNEG8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1767 /* sqneg */, AArch64::SQNEG16b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1767 /* sqneg */, AArch64::SQNEG2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1767 /* sqneg */, AArch64::SQNEG4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1767 /* sqneg */, AArch64::SQNEG8h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHhhh, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR16 }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHhhv_4H, Convert__Reg1_0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR64Lo, MCK__DOT_h, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHhhv_8H, Convert__Reg1_0__Reg1_1__Reg1_2__UImm31_5, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHssv_2S, Convert__Reg1_0__Reg1_1__Reg1_2__UImm11_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR64, MCK__DOT_s, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHssv_4S, Convert__Reg1_0__Reg1_1__Reg1_2__UImm21_5, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHve_2s4s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHve_4h8h, Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHve_4s4s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 1773 /* sqrdmulh */, AArch64::SQRDMULHve_8h8h, Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 1782 /* sqrshl */, AArch64::SQRSHLbbb, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR8, MCK_FPR8 }, },
  { 1782 /* sqrshl */, AArch64::SQRSHLhhh, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR16 }, },
  { 1782 /* sqrshl */, AArch64::SQRSHLsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 1782 /* sqrshl */, AArch64::SQRSHLddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 1782 /* sqrshl */, AArch64::SQRSHLvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1782 /* sqrshl */, AArch64::SQRSHLvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1782 /* sqrshl */, AArch64::SQRSHLvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1782 /* sqrshl */, AArch64::SQRSHLvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1782 /* sqrshl */, AArch64::SQRSHLvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1782 /* sqrshl */, AArch64::SQRSHLvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1782 /* sqrshl */, AArch64::SQRSHLvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1789 /* sqrshrn */, AArch64::SQRSHRNbhi, Convert__Reg1_0__Reg1_1__ShrImm81_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR16, MCK_ShrImm8 }, },
  { 1789 /* sqrshrn */, AArch64::SQRSHRNhsi, Convert__Reg1_0__Reg1_1__ShrImm161_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR32, MCK_ShrImm16 }, },
  { 1789 /* sqrshrn */, AArch64::SQRSHRNsdi, Convert__Reg1_0__Reg1_1__ShrImm321_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR64, MCK_ShrImm32 }, },
  { 1789 /* sqrshrn */, AArch64::SQRSHRNvvi_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 1789 /* sqrshrn */, AArch64::SQRSHRNvvi_4H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 1789 /* sqrshrn */, AArch64::SQRSHRNvvi_8B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 1797 /* sqrshrn2 */, AArch64::SQRSHRNvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 1797 /* sqrshrn2 */, AArch64::SQRSHRNvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 1797 /* sqrshrn2 */, AArch64::SQRSHRNvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 1806 /* sqrshrun */, AArch64::SQRSHRUNbhi, Convert__Reg1_0__Reg1_1__ShrImm81_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR16, MCK_ShrImm8 }, },
  { 1806 /* sqrshrun */, AArch64::SQRSHRUNhsi, Convert__Reg1_0__Reg1_1__ShrImm161_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR32, MCK_ShrImm16 }, },
  { 1806 /* sqrshrun */, AArch64::SQRSHRUNsdi, Convert__Reg1_0__Reg1_1__ShrImm321_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR64, MCK_ShrImm32 }, },
  { 1806 /* sqrshrun */, AArch64::QRSHRUNvvi_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 1806 /* sqrshrun */, AArch64::QRSHRUNvvi_4H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 1806 /* sqrshrun */, AArch64::QRSHRUNvvi_8B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 1815 /* sqrshrun2 */, AArch64::QRSHRUNvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 1815 /* sqrshrun2 */, AArch64::QRSHRUNvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 1815 /* sqrshrun2 */, AArch64::QRSHRUNvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 1825 /* sqshl */, AArch64::SQSHLbbb, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR8, MCK_FPR8 }, },
  { 1825 /* sqshl */, AArch64::SQSHLbbi, Convert__Reg1_0__Reg1_1__ShlImm81_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR8, MCK_ShlImm8 }, },
  { 1825 /* sqshl */, AArch64::SQSHLhhh, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR16 }, },
  { 1825 /* sqshl */, AArch64::SQSHLhhi, Convert__Reg1_0__Reg1_1__ShlImm161_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_ShlImm16 }, },
  { 1825 /* sqshl */, AArch64::SQSHLsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 1825 /* sqshl */, AArch64::SQSHLssi, Convert__Reg1_0__Reg1_1__ShlImm321_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_ShlImm32 }, },
  { 1825 /* sqshl */, AArch64::SQSHLddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 1825 /* sqshl */, AArch64::SQSHLddi, Convert__Reg1_0__Reg1_1__ShlImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShlImm64 }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvi_2S, Convert__Reg1_0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShlImm32 }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvi_4H, Convert__Reg1_0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShlImm16 }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvi_8B, Convert__Reg1_0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShlImm8 }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvi_16B, Convert__Reg1_0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShlImm8 }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvi_2D, Convert__Reg1_0__Reg1_2__ShlImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShlImm64 }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvi_4S, Convert__Reg1_0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShlImm32 }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvi_8H, Convert__Reg1_0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShlImm16 }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1825 /* sqshl */, AArch64::SQSHLvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1831 /* sqshlu */, AArch64::SQSHLUbbi, Convert__Reg1_0__Reg1_1__ShlImm81_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR8, MCK_ShlImm8 }, },
  { 1831 /* sqshlu */, AArch64::SQSHLUhhi, Convert__Reg1_0__Reg1_1__ShlImm161_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_ShlImm16 }, },
  { 1831 /* sqshlu */, AArch64::SQSHLUssi, Convert__Reg1_0__Reg1_1__ShlImm321_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_ShlImm32 }, },
  { 1831 /* sqshlu */, AArch64::SQSHLUddi, Convert__Reg1_0__Reg1_1__ShlImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShlImm64 }, },
  { 1831 /* sqshlu */, AArch64::SQSHLUvvi_2S, Convert__Reg1_0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShlImm32 }, },
  { 1831 /* sqshlu */, AArch64::SQSHLUvvi_4H, Convert__Reg1_0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShlImm16 }, },
  { 1831 /* sqshlu */, AArch64::SQSHLUvvi_8B, Convert__Reg1_0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShlImm8 }, },
  { 1831 /* sqshlu */, AArch64::SQSHLUvvi_16B, Convert__Reg1_0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShlImm8 }, },
  { 1831 /* sqshlu */, AArch64::SQSHLUvvi_2D, Convert__Reg1_0__Reg1_2__ShlImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShlImm64 }, },
  { 1831 /* sqshlu */, AArch64::SQSHLUvvi_4S, Convert__Reg1_0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShlImm32 }, },
  { 1831 /* sqshlu */, AArch64::SQSHLUvvi_8H, Convert__Reg1_0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShlImm16 }, },
  { 1838 /* sqshrn */, AArch64::SQSHRNbhi, Convert__Reg1_0__Reg1_1__ShrImm81_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR16, MCK_ShrImm8 }, },
  { 1838 /* sqshrn */, AArch64::SQSHRNhsi, Convert__Reg1_0__Reg1_1__ShrImm161_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR32, MCK_ShrImm16 }, },
  { 1838 /* sqshrn */, AArch64::SQSHRNsdi, Convert__Reg1_0__Reg1_1__ShrImm321_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR64, MCK_ShrImm32 }, },
  { 1838 /* sqshrn */, AArch64::SQSHRNvvi_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 1838 /* sqshrn */, AArch64::SQSHRNvvi_4H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 1838 /* sqshrn */, AArch64::SQSHRNvvi_8B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 1845 /* sqshrn2 */, AArch64::SQSHRNvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 1845 /* sqshrn2 */, AArch64::SQSHRNvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 1845 /* sqshrn2 */, AArch64::SQSHRNvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 1853 /* sqshrun */, AArch64::SQSHRUNbhi, Convert__Reg1_0__Reg1_1__ShrImm81_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR16, MCK_ShrImm8 }, },
  { 1853 /* sqshrun */, AArch64::SQSHRUNhsi, Convert__Reg1_0__Reg1_1__ShrImm161_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR32, MCK_ShrImm16 }, },
  { 1853 /* sqshrun */, AArch64::SQSHRUNsdi, Convert__Reg1_0__Reg1_1__ShrImm321_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR64, MCK_ShrImm32 }, },
  { 1853 /* sqshrun */, AArch64::QSHRUNvvi_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 1853 /* sqshrun */, AArch64::QSHRUNvvi_4H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 1853 /* sqshrun */, AArch64::QSHRUNvvi_8B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 1861 /* sqshrun2 */, AArch64::QSHRUNvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 1861 /* sqshrun2 */, AArch64::QSHRUNvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 1861 /* sqshrun2 */, AArch64::QSHRUNvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 1870 /* sqsub */, AArch64::SQSUBbbb, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR8, MCK_FPR8 }, },
  { 1870 /* sqsub */, AArch64::SQSUBhhh, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR16 }, },
  { 1870 /* sqsub */, AArch64::SQSUBsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 1870 /* sqsub */, AArch64::SQSUBddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 1870 /* sqsub */, AArch64::SQSUBvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1870 /* sqsub */, AArch64::SQSUBvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1870 /* sqsub */, AArch64::SQSUBvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1870 /* sqsub */, AArch64::SQSUBvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1870 /* sqsub */, AArch64::SQSUBvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1870 /* sqsub */, AArch64::SQSUBvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1870 /* sqsub */, AArch64::SQSUBvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1876 /* sqxtn */, AArch64::SQXTNbh, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR16 }, },
  { 1876 /* sqxtn */, AArch64::SQXTNhs, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR32 }, },
  { 1876 /* sqxtn */, AArch64::SQXTNsd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR64 }, },
  { 1876 /* sqxtn */, AArch64::SQXTN2d2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d }, },
  { 1876 /* sqxtn */, AArch64::SQXTN4s4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s }, },
  { 1876 /* sqxtn */, AArch64::SQXTN8h8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h }, },
  { 1882 /* sqxtn2 */, AArch64::SQXTN8h16b, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h }, },
  { 1882 /* sqxtn2 */, AArch64::SQXTN2d4s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d }, },
  { 1882 /* sqxtn2 */, AArch64::SQXTN4s8h, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s }, },
  { 1889 /* sqxtun */, AArch64::SQXTUNbh, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR16 }, },
  { 1889 /* sqxtun */, AArch64::SQXTUNhs, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR32 }, },
  { 1889 /* sqxtun */, AArch64::SQXTUNsd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR64 }, },
  { 1889 /* sqxtun */, AArch64::SQXTUN2d2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d }, },
  { 1889 /* sqxtun */, AArch64::SQXTUN4s4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s }, },
  { 1889 /* sqxtun */, AArch64::SQXTUN8h8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h }, },
  { 1896 /* sqxtun2 */, AArch64::SQXTUN8h16b, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h }, },
  { 1896 /* sqxtun2 */, AArch64::SQXTUN2d4s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d }, },
  { 1896 /* sqxtun2 */, AArch64::SQXTUN4s8h, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s }, },
  { 1904 /* srhadd */, AArch64::SRHADDvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1904 /* srhadd */, AArch64::SRHADDvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1904 /* srhadd */, AArch64::SRHADDvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1904 /* srhadd */, AArch64::SRHADDvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1904 /* srhadd */, AArch64::SRHADDvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1904 /* srhadd */, AArch64::SRHADDvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1911 /* sri */, AArch64::SRI, Convert__Reg1_0__Tie0__Reg1_1__ShrImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShrImm64 }, },
  { 1911 /* sri */, AArch64::SRIvvi_2S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShrImm32 }, },
  { 1911 /* sri */, AArch64::SRIvvi_4H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShrImm16 }, },
  { 1911 /* sri */, AArch64::SRIvvi_8B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShrImm8 }, },
  { 1911 /* sri */, AArch64::SRIvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShrImm8 }, },
  { 1911 /* sri */, AArch64::SRIvvi_2D, Convert__Reg1_0__Tie0__Reg1_2__ShrImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm64 }, },
  { 1911 /* sri */, AArch64::SRIvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm32 }, },
  { 1911 /* sri */, AArch64::SRIvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm16 }, },
  { 1915 /* srshl */, AArch64::SRSHLddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 1915 /* srshl */, AArch64::SRSHLvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1915 /* srshl */, AArch64::SRSHLvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1915 /* srshl */, AArch64::SRSHLvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1915 /* srshl */, AArch64::SRSHLvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1915 /* srshl */, AArch64::SRSHLvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1915 /* srshl */, AArch64::SRSHLvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1915 /* srshl */, AArch64::SRSHLvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1921 /* srshr */, AArch64::SRSHRddi, Convert__Reg1_0__Reg1_1__ShrImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShrImm64 }, },
  { 1921 /* srshr */, AArch64::SRSHRvvi_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShrImm32 }, },
  { 1921 /* srshr */, AArch64::SRSHRvvi_4H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShrImm16 }, },
  { 1921 /* srshr */, AArch64::SRSHRvvi_8B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShrImm8 }, },
  { 1921 /* srshr */, AArch64::SRSHRvvi_16B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShrImm8 }, },
  { 1921 /* srshr */, AArch64::SRSHRvvi_2D, Convert__Reg1_0__Reg1_2__ShrImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm64 }, },
  { 1921 /* srshr */, AArch64::SRSHRvvi_4S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm32 }, },
  { 1921 /* srshr */, AArch64::SRSHRvvi_8H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm16 }, },
  { 1927 /* srsra */, AArch64::SRSRA, Convert__Reg1_0__Tie0__Reg1_1__ShrImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShrImm64 }, },
  { 1927 /* srsra */, AArch64::SRSRAvvi_2S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShrImm32 }, },
  { 1927 /* srsra */, AArch64::SRSRAvvi_4H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShrImm16 }, },
  { 1927 /* srsra */, AArch64::SRSRAvvi_8B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShrImm8 }, },
  { 1927 /* srsra */, AArch64::SRSRAvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShrImm8 }, },
  { 1927 /* srsra */, AArch64::SRSRAvvi_2D, Convert__Reg1_0__Tie0__Reg1_2__ShrImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm64 }, },
  { 1927 /* srsra */, AArch64::SRSRAvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm32 }, },
  { 1927 /* srsra */, AArch64::SRSRAvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm16 }, },
  { 1933 /* sshl */, AArch64::SSHLddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 1933 /* sshl */, AArch64::SSHLvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1933 /* sshl */, AArch64::SSHLvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1933 /* sshl */, AArch64::SSHLvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1933 /* sshl */, AArch64::SSHLvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1933 /* sshl */, AArch64::SSHLvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 1933 /* sshl */, AArch64::SSHLvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1933 /* sshl */, AArch64::SSHLvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1938 /* sshll */, AArch64::SSHLLvvi_2S, Convert__Reg1_0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_ShlImm32 }, },
  { 1938 /* sshll */, AArch64::SSHLLvvi_4H, Convert__Reg1_0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_ShlImm16 }, },
  { 1938 /* sshll */, AArch64::SSHLLvvi_8B, Convert__Reg1_0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_ShlImm8 }, },
  { 1944 /* sshll2 */, AArch64::SSHLLvvi_4S, Convert__Reg1_0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_ShlImm32 }, },
  { 1944 /* sshll2 */, AArch64::SSHLLvvi_8H, Convert__Reg1_0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_ShlImm16 }, },
  { 1944 /* sshll2 */, AArch64::SSHLLvvi_16B, Convert__Reg1_0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_ShlImm8 }, },
  { 1951 /* sshr */, AArch64::SSHRddi, Convert__Reg1_0__Reg1_1__ShrImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShrImm64 }, },
  { 1951 /* sshr */, AArch64::SSHRvvi_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShrImm32 }, },
  { 1951 /* sshr */, AArch64::SSHRvvi_4H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShrImm16 }, },
  { 1951 /* sshr */, AArch64::SSHRvvi_8B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShrImm8 }, },
  { 1951 /* sshr */, AArch64::SSHRvvi_16B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShrImm8 }, },
  { 1951 /* sshr */, AArch64::SSHRvvi_2D, Convert__Reg1_0__Reg1_2__ShrImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm64 }, },
  { 1951 /* sshr */, AArch64::SSHRvvi_4S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm32 }, },
  { 1951 /* sshr */, AArch64::SSHRvvi_8H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm16 }, },
  { 1956 /* ssra */, AArch64::SSRA, Convert__Reg1_0__Tie0__Reg1_1__ShrImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShrImm64 }, },
  { 1956 /* ssra */, AArch64::SSRAvvi_2S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShrImm32 }, },
  { 1956 /* ssra */, AArch64::SSRAvvi_4H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShrImm16 }, },
  { 1956 /* ssra */, AArch64::SSRAvvi_8B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShrImm8 }, },
  { 1956 /* ssra */, AArch64::SSRAvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShrImm8 }, },
  { 1956 /* ssra */, AArch64::SSRAvvi_2D, Convert__Reg1_0__Tie0__Reg1_2__ShrImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm64 }, },
  { 1956 /* ssra */, AArch64::SSRAvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm32 }, },
  { 1956 /* ssra */, AArch64::SSRAvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm16 }, },
  { 1961 /* ssubl */, AArch64::SSUBLvvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 1961 /* ssubl */, AArch64::SSUBLvvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 1961 /* ssubl */, AArch64::SSUBLvvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 1967 /* ssubl2 */, AArch64::SSUBL2vvv_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 1967 /* ssubl2 */, AArch64::SSUBL2vvv_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 1967 /* ssubl2 */, AArch64::SSUBL2vvv_8h16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 1974 /* ssubw */, AArch64::SSUBWvvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s }, },
  { 1974 /* ssubw */, AArch64::SSUBWvvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h }, },
  { 1974 /* ssubw */, AArch64::SSUBWvvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b }, },
  { 1980 /* ssubw2 */, AArch64::SSUBW2vvv_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s }, },
  { 1980 /* ssubw2 */, AArch64::SSUBW2vvv_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h }, },
  { 1980 /* ssubw2 */, AArch64::SSUBW2vvv_8h16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b }, },
  { 1987 /* st1 */, AArch64::ST1_16B, Convert__Reg1_2__VOne16B11_0, Feature_HasNEON, { MCK_VOne16B1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1_1D, Convert__Reg1_2__VOne1D11_0, Feature_HasNEON, { MCK_VOne1D1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1_2D, Convert__Reg1_2__VOne2D11_0, Feature_HasNEON, { MCK_VOne2D1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1_2S, Convert__Reg1_2__VOne2S11_0, Feature_HasNEON, { MCK_VOne2S1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1_4H, Convert__Reg1_2__VOne4H11_0, Feature_HasNEON, { MCK_VOne4H1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1_4S, Convert__Reg1_2__VOne4S11_0, Feature_HasNEON, { MCK_VOne4S1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1_8B, Convert__Reg1_2__VOne8B11_0, Feature_HasNEON, { MCK_VOne8B1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1_8H, Convert__Reg1_2__VOne8H11_0, Feature_HasNEON, { MCK_VOne8H1, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x2_16B, Convert__Reg1_2__VPair16B21_0, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x2_1D, Convert__Reg1_2__VPair1D21_0, Feature_HasNEON, { MCK_VPair1D2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x2_2D, Convert__Reg1_2__VPair2D21_0, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x2_2S, Convert__Reg1_2__VPair2S21_0, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x2_4H, Convert__Reg1_2__VPair4H21_0, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x2_4S, Convert__Reg1_2__VPair4S21_0, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x2_8B, Convert__Reg1_2__VPair8B21_0, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x2_8H, Convert__Reg1_2__VPair8H21_0, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x4_16B, Convert__Reg1_2__VQuad16B41_0, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x4_1D, Convert__Reg1_2__VQuad1D41_0, Feature_HasNEON, { MCK_VQuad1D4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x4_2D, Convert__Reg1_2__VQuad2D41_0, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x4_2S, Convert__Reg1_2__VQuad2S41_0, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x4_4H, Convert__Reg1_2__VQuad4H41_0, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x4_4S, Convert__Reg1_2__VQuad4S41_0, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x4_8B, Convert__Reg1_2__VQuad8B41_0, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x4_8H, Convert__Reg1_2__VQuad8H41_0, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x3_16B, Convert__Reg1_2__VTriple16B31_0, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x3_1D, Convert__Reg1_2__VTriple1D31_0, Feature_HasNEON, { MCK_VTriple1D3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x3_2D, Convert__Reg1_2__VTriple2D31_0, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x3_2S, Convert__Reg1_2__VTriple2S31_0, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x3_4H, Convert__Reg1_2__VTriple4H31_0, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x3_4S, Convert__Reg1_2__VTriple4S31_0, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x3_8B, Convert__Reg1_2__VTriple8B31_0, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1x3_8H, Convert__Reg1_2__VTriple8H31_0, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1WB_16B_register, Convert__Reg1_2__Tie0__Reg1_4__VOne16B11_0, Feature_HasNEON, { MCK_VOne16B1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1WB_16B_fixed, Convert__Reg1_2__Tie0__Exact161_4__VOne16B11_0, Feature_HasNEON, { MCK_VOne16B1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 1987 /* st1 */, AArch64::ST1WB_1D_register, Convert__Reg1_2__Tie0__Reg1_4__VOne1D11_0, Feature_HasNEON, { MCK_VOne1D1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1WB_1D_fixed, Convert__Reg1_2__Tie0__Exact81_4__VOne1D11_0, Feature_HasNEON, { MCK_VOne1D1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 1987 /* st1 */, AArch64::ST1WB_2D_register, Convert__Reg1_2__Tie0__Reg1_4__VOne2D11_0, Feature_HasNEON, { MCK_VOne2D1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1WB_2D_fixed, Convert__Reg1_2__Tie0__Exact161_4__VOne2D11_0, Feature_HasNEON, { MCK_VOne2D1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 1987 /* st1 */, AArch64::ST1WB_2S_register, Convert__Reg1_2__Tie0__Reg1_4__VOne2S11_0, Feature_HasNEON, { MCK_VOne2S1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1WB_2S_fixed, Convert__Reg1_2__Tie0__Exact81_4__VOne2S11_0, Feature_HasNEON, { MCK_VOne2S1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 1987 /* st1 */, AArch64::ST1WB_4H_register, Convert__Reg1_2__Tie0__Reg1_4__VOne4H11_0, Feature_HasNEON, { MCK_VOne4H1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1WB_4H_fixed, Convert__Reg1_2__Tie0__Exact81_4__VOne4H11_0, Feature_HasNEON, { MCK_VOne4H1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 1987 /* st1 */, AArch64::ST1WB_4S_register, Convert__Reg1_2__Tie0__Reg1_4__VOne4S11_0, Feature_HasNEON, { MCK_VOne4S1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1WB_4S_fixed, Convert__Reg1_2__Tie0__Exact161_4__VOne4S11_0, Feature_HasNEON, { MCK_VOne4S1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 1987 /* st1 */, AArch64::ST1WB_8B_register, Convert__Reg1_2__Tie0__Reg1_4__VOne8B11_0, Feature_HasNEON, { MCK_VOne8B1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1WB_8B_fixed, Convert__Reg1_2__Tie0__Exact81_4__VOne8B11_0, Feature_HasNEON, { MCK_VOne8B1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 1987 /* st1 */, AArch64::ST1WB_8H_register, Convert__Reg1_2__Tie0__Reg1_4__VOne8H11_0, Feature_HasNEON, { MCK_VOne8H1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1WB_8H_fixed, Convert__Reg1_2__Tie0__Exact161_4__VOne8H11_0, Feature_HasNEON, { MCK_VOne8H1, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_16B_register, Convert__Reg1_2__Tie0__Reg1_4__VPair16B21_0, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_16B_fixed, Convert__Reg1_2__Tie0__Exact321_4__VPair16B21_0, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_1D_register, Convert__Reg1_2__Tie0__Reg1_4__VPair1D21_0, Feature_HasNEON, { MCK_VPair1D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_1D_fixed, Convert__Reg1_2__Tie0__Exact161_4__VPair1D21_0, Feature_HasNEON, { MCK_VPair1D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_2D_register, Convert__Reg1_2__Tie0__Reg1_4__VPair2D21_0, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_2D_fixed, Convert__Reg1_2__Tie0__Exact321_4__VPair2D21_0, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_2S_register, Convert__Reg1_2__Tie0__Reg1_4__VPair2S21_0, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_2S_fixed, Convert__Reg1_2__Tie0__Exact161_4__VPair2S21_0, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_4H_register, Convert__Reg1_2__Tie0__Reg1_4__VPair4H21_0, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_4H_fixed, Convert__Reg1_2__Tie0__Exact161_4__VPair4H21_0, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_4S_register, Convert__Reg1_2__Tie0__Reg1_4__VPair4S21_0, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_4S_fixed, Convert__Reg1_2__Tie0__Exact321_4__VPair4S21_0, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_8B_register, Convert__Reg1_2__Tie0__Reg1_4__VPair8B21_0, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_8B_fixed, Convert__Reg1_2__Tie0__Exact161_4__VPair8B21_0, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_8H_register, Convert__Reg1_2__Tie0__Reg1_4__VPair8H21_0, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x2WB_8H_fixed, Convert__Reg1_2__Tie0__Exact321_4__VPair8H21_0, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_16B_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad16B41_0, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_16B_fixed, Convert__Reg1_2__Tie0__Exact641_4__VQuad16B41_0, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_1D_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad1D41_0, Feature_HasNEON, { MCK_VQuad1D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_1D_fixed, Convert__Reg1_2__Tie0__Exact321_4__VQuad1D41_0, Feature_HasNEON, { MCK_VQuad1D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_2D_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad2D41_0, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_2D_fixed, Convert__Reg1_2__Tie0__Exact641_4__VQuad2D41_0, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_2S_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad2S41_0, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_2S_fixed, Convert__Reg1_2__Tie0__Exact321_4__VQuad2S41_0, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_4H_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad4H41_0, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_4H_fixed, Convert__Reg1_2__Tie0__Exact321_4__VQuad4H41_0, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_4S_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad4S41_0, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_4S_fixed, Convert__Reg1_2__Tie0__Exact641_4__VQuad4S41_0, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_8B_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad8B41_0, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_8B_fixed, Convert__Reg1_2__Tie0__Exact321_4__VQuad8B41_0, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_8H_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad8H41_0, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x4WB_8H_fixed, Convert__Reg1_2__Tie0__Exact641_4__VQuad8H41_0, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_16B_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple16B31_0, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_16B_fixed, Convert__Reg1_2__Tie0__Exact481_4__VTriple16B31_0, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_1D_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple1D31_0, Feature_HasNEON, { MCK_VTriple1D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_1D_fixed, Convert__Reg1_2__Tie0__Exact241_4__VTriple1D31_0, Feature_HasNEON, { MCK_VTriple1D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_2D_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple2D31_0, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_2D_fixed, Convert__Reg1_2__Tie0__Exact481_4__VTriple2D31_0, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_2S_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple2S31_0, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_2S_fixed, Convert__Reg1_2__Tie0__Exact241_4__VTriple2S31_0, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_4H_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple4H31_0, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_4H_fixed, Convert__Reg1_2__Tie0__Exact241_4__VTriple4H31_0, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_4S_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple4S31_0, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_4S_fixed, Convert__Reg1_2__Tie0__Exact481_4__VTriple4S31_0, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_8B_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple8B31_0, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_8B_fixed, Convert__Reg1_2__Tie0__Exact241_4__VTriple8B31_0, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_8H_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple8H31_0, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1x3WB_8H_fixed, Convert__Reg1_2__Tie0__Exact481_4__VTriple8H31_0, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 1987 /* st1 */, AArch64::ST1LN_B, Convert__Reg1_5__VOneB11_0__UImm41_2, Feature_HasNEON, { MCK_VOneB1, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1LN_D, Convert__Reg1_5__VOneD11_0__UImm11_2, Feature_HasNEON, { MCK_VOneD1, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1LN_H, Convert__Reg1_5__VOneH11_0__UImm31_2, Feature_HasNEON, { MCK_VOneH1, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1LN_S, Convert__Reg1_5__VOneS11_0__UImm21_2, Feature_HasNEON, { MCK_VOneS1, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1987 /* st1 */, AArch64::ST1LN_WB_B_register, Convert__Reg1_5__Tie0__Reg1_7__VOneB11_0__UImm41_2, Feature_HasNEON, { MCK_VOneB1, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1LN_WB_B_fixed, Convert__Reg1_5__Tie0__Exact11_7__VOneB11_0__UImm41_2, Feature_HasNEON, { MCK_VOneB1, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact1 }, },
  { 1987 /* st1 */, AArch64::ST1LN_WB_D_register, Convert__Reg1_5__Tie0__Reg1_7__VOneD11_0__UImm11_2, Feature_HasNEON, { MCK_VOneD1, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1LN_WB_D_fixed, Convert__Reg1_5__Tie0__Exact81_7__VOneD11_0__UImm11_2, Feature_HasNEON, { MCK_VOneD1, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 1987 /* st1 */, AArch64::ST1LN_WB_H_register, Convert__Reg1_5__Tie0__Reg1_7__VOneH11_0__UImm31_2, Feature_HasNEON, { MCK_VOneH1, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1LN_WB_H_fixed, Convert__Reg1_5__Tie0__Exact21_7__VOneH11_0__UImm31_2, Feature_HasNEON, { MCK_VOneH1, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact2 }, },
  { 1987 /* st1 */, AArch64::ST1LN_WB_S_register, Convert__Reg1_5__Tie0__Reg1_7__VOneS11_0__UImm21_2, Feature_HasNEON, { MCK_VOneS1, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1987 /* st1 */, AArch64::ST1LN_WB_S_fixed, Convert__Reg1_5__Tie0__Exact41_7__VOneS11_0__UImm21_2, Feature_HasNEON, { MCK_VOneS1, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact4 }, },
  { 1991 /* st2 */, AArch64::ST2_16B, Convert__Reg1_2__VPair16B21_0, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1991 /* st2 */, AArch64::ST2_2D, Convert__Reg1_2__VPair2D21_0, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1991 /* st2 */, AArch64::ST2_2S, Convert__Reg1_2__VPair2S21_0, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1991 /* st2 */, AArch64::ST2_4H, Convert__Reg1_2__VPair4H21_0, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1991 /* st2 */, AArch64::ST2_4S, Convert__Reg1_2__VPair4S21_0, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1991 /* st2 */, AArch64::ST2_8B, Convert__Reg1_2__VPair8B21_0, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1991 /* st2 */, AArch64::ST2_8H, Convert__Reg1_2__VPair8H21_0, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1991 /* st2 */, AArch64::ST2WB_16B_register, Convert__Reg1_2__Tie0__Reg1_4__VPair16B21_0, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1991 /* st2 */, AArch64::ST2WB_16B_fixed, Convert__Reg1_2__Tie0__Exact321_4__VPair16B21_0, Feature_HasNEON, { MCK_VPair16B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1991 /* st2 */, AArch64::ST2WB_2D_register, Convert__Reg1_2__Tie0__Reg1_4__VPair2D21_0, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1991 /* st2 */, AArch64::ST2WB_2D_fixed, Convert__Reg1_2__Tie0__Exact321_4__VPair2D21_0, Feature_HasNEON, { MCK_VPair2D2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1991 /* st2 */, AArch64::ST2WB_2S_register, Convert__Reg1_2__Tie0__Reg1_4__VPair2S21_0, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1991 /* st2 */, AArch64::ST2WB_2S_fixed, Convert__Reg1_2__Tie0__Exact161_4__VPair2S21_0, Feature_HasNEON, { MCK_VPair2S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 1991 /* st2 */, AArch64::ST2WB_4H_register, Convert__Reg1_2__Tie0__Reg1_4__VPair4H21_0, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1991 /* st2 */, AArch64::ST2WB_4H_fixed, Convert__Reg1_2__Tie0__Exact161_4__VPair4H21_0, Feature_HasNEON, { MCK_VPair4H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 1991 /* st2 */, AArch64::ST2WB_4S_register, Convert__Reg1_2__Tie0__Reg1_4__VPair4S21_0, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1991 /* st2 */, AArch64::ST2WB_4S_fixed, Convert__Reg1_2__Tie0__Exact321_4__VPair4S21_0, Feature_HasNEON, { MCK_VPair4S2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1991 /* st2 */, AArch64::ST2WB_8B_register, Convert__Reg1_2__Tie0__Reg1_4__VPair8B21_0, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1991 /* st2 */, AArch64::ST2WB_8B_fixed, Convert__Reg1_2__Tie0__Exact161_4__VPair8B21_0, Feature_HasNEON, { MCK_VPair8B2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 1991 /* st2 */, AArch64::ST2WB_8H_register, Convert__Reg1_2__Tie0__Reg1_4__VPair8H21_0, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1991 /* st2 */, AArch64::ST2WB_8H_fixed, Convert__Reg1_2__Tie0__Exact321_4__VPair8H21_0, Feature_HasNEON, { MCK_VPair8H2, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1991 /* st2 */, AArch64::ST2LN_B, Convert__Reg1_5__VPairB21_0__UImm41_2, Feature_HasNEON, { MCK_VPairB2, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1991 /* st2 */, AArch64::ST2LN_D, Convert__Reg1_5__VPairD21_0__UImm11_2, Feature_HasNEON, { MCK_VPairD2, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1991 /* st2 */, AArch64::ST2LN_H, Convert__Reg1_5__VPairH21_0__UImm31_2, Feature_HasNEON, { MCK_VPairH2, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1991 /* st2 */, AArch64::ST2LN_S, Convert__Reg1_5__VPairS21_0__UImm21_2, Feature_HasNEON, { MCK_VPairS2, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1991 /* st2 */, AArch64::ST2LN_WB_B_register, Convert__Reg1_5__Tie0__Reg1_7__VPairB21_0__UImm41_2, Feature_HasNEON, { MCK_VPairB2, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1991 /* st2 */, AArch64::ST2LN_WB_B_fixed, Convert__Reg1_5__Tie0__Exact21_7__VPairB21_0__UImm41_2, Feature_HasNEON, { MCK_VPairB2, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact2 }, },
  { 1991 /* st2 */, AArch64::ST2LN_WB_D_register, Convert__Reg1_5__Tie0__Reg1_7__VPairD21_0__UImm11_2, Feature_HasNEON, { MCK_VPairD2, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1991 /* st2 */, AArch64::ST2LN_WB_D_fixed, Convert__Reg1_5__Tie0__Exact161_7__VPairD21_0__UImm11_2, Feature_HasNEON, { MCK_VPairD2, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 1991 /* st2 */, AArch64::ST2LN_WB_H_register, Convert__Reg1_5__Tie0__Reg1_7__VPairH21_0__UImm31_2, Feature_HasNEON, { MCK_VPairH2, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1991 /* st2 */, AArch64::ST2LN_WB_H_fixed, Convert__Reg1_5__Tie0__Exact41_7__VPairH21_0__UImm31_2, Feature_HasNEON, { MCK_VPairH2, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact4 }, },
  { 1991 /* st2 */, AArch64::ST2LN_WB_S_register, Convert__Reg1_5__Tie0__Reg1_7__VPairS21_0__UImm21_2, Feature_HasNEON, { MCK_VPairS2, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1991 /* st2 */, AArch64::ST2LN_WB_S_fixed, Convert__Reg1_5__Tie0__Exact81_7__VPairS21_0__UImm21_2, Feature_HasNEON, { MCK_VPairS2, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 1995 /* st3 */, AArch64::ST3_16B, Convert__Reg1_2__VTriple16B31_0, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1995 /* st3 */, AArch64::ST3_2D, Convert__Reg1_2__VTriple2D31_0, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1995 /* st3 */, AArch64::ST3_2S, Convert__Reg1_2__VTriple2S31_0, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1995 /* st3 */, AArch64::ST3_4H, Convert__Reg1_2__VTriple4H31_0, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1995 /* st3 */, AArch64::ST3_4S, Convert__Reg1_2__VTriple4S31_0, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1995 /* st3 */, AArch64::ST3_8B, Convert__Reg1_2__VTriple8B31_0, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1995 /* st3 */, AArch64::ST3_8H, Convert__Reg1_2__VTriple8H31_0, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1995 /* st3 */, AArch64::ST3WB_16B_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple16B31_0, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1995 /* st3 */, AArch64::ST3WB_16B_fixed, Convert__Reg1_2__Tie0__Exact481_4__VTriple16B31_0, Feature_HasNEON, { MCK_VTriple16B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 1995 /* st3 */, AArch64::ST3WB_2D_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple2D31_0, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1995 /* st3 */, AArch64::ST3WB_2D_fixed, Convert__Reg1_2__Tie0__Exact481_4__VTriple2D31_0, Feature_HasNEON, { MCK_VTriple2D3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 1995 /* st3 */, AArch64::ST3WB_2S_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple2S31_0, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1995 /* st3 */, AArch64::ST3WB_2S_fixed, Convert__Reg1_2__Tie0__Exact241_4__VTriple2S31_0, Feature_HasNEON, { MCK_VTriple2S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 1995 /* st3 */, AArch64::ST3WB_4H_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple4H31_0, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1995 /* st3 */, AArch64::ST3WB_4H_fixed, Convert__Reg1_2__Tie0__Exact241_4__VTriple4H31_0, Feature_HasNEON, { MCK_VTriple4H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 1995 /* st3 */, AArch64::ST3WB_4S_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple4S31_0, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1995 /* st3 */, AArch64::ST3WB_4S_fixed, Convert__Reg1_2__Tie0__Exact481_4__VTriple4S31_0, Feature_HasNEON, { MCK_VTriple4S3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 1995 /* st3 */, AArch64::ST3WB_8B_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple8B31_0, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1995 /* st3 */, AArch64::ST3WB_8B_fixed, Convert__Reg1_2__Tie0__Exact241_4__VTriple8B31_0, Feature_HasNEON, { MCK_VTriple8B3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 1995 /* st3 */, AArch64::ST3WB_8H_register, Convert__Reg1_2__Tie0__Reg1_4__VTriple8H31_0, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1995 /* st3 */, AArch64::ST3WB_8H_fixed, Convert__Reg1_2__Tie0__Exact481_4__VTriple8H31_0, Feature_HasNEON, { MCK_VTriple8H3, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact48 }, },
  { 1995 /* st3 */, AArch64::ST3LN_B, Convert__Reg1_5__VTripleB31_0__UImm41_2, Feature_HasNEON, { MCK_VTripleB3, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1995 /* st3 */, AArch64::ST3LN_D, Convert__Reg1_5__VTripleD31_0__UImm11_2, Feature_HasNEON, { MCK_VTripleD3, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1995 /* st3 */, AArch64::ST3LN_H, Convert__Reg1_5__VTripleH31_0__UImm31_2, Feature_HasNEON, { MCK_VTripleH3, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1995 /* st3 */, AArch64::ST3LN_S, Convert__Reg1_5__VTripleS31_0__UImm21_2, Feature_HasNEON, { MCK_VTripleS3, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1995 /* st3 */, AArch64::ST3LN_WB_B_register, Convert__Reg1_5__Tie0__Reg1_7__VTripleB31_0__UImm41_2, Feature_HasNEON, { MCK_VTripleB3, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1995 /* st3 */, AArch64::ST3LN_WB_B_fixed, Convert__Reg1_5__Tie0__Exact31_7__VTripleB31_0__UImm41_2, Feature_HasNEON, { MCK_VTripleB3, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact3 }, },
  { 1995 /* st3 */, AArch64::ST3LN_WB_D_register, Convert__Reg1_5__Tie0__Reg1_7__VTripleD31_0__UImm11_2, Feature_HasNEON, { MCK_VTripleD3, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1995 /* st3 */, AArch64::ST3LN_WB_D_fixed, Convert__Reg1_5__Tie0__Exact241_7__VTripleD31_0__UImm11_2, Feature_HasNEON, { MCK_VTripleD3, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact24 }, },
  { 1995 /* st3 */, AArch64::ST3LN_WB_H_register, Convert__Reg1_5__Tie0__Reg1_7__VTripleH31_0__UImm31_2, Feature_HasNEON, { MCK_VTripleH3, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1995 /* st3 */, AArch64::ST3LN_WB_H_fixed, Convert__Reg1_5__Tie0__Exact61_7__VTripleH31_0__UImm31_2, Feature_HasNEON, { MCK_VTripleH3, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact6 }, },
  { 1995 /* st3 */, AArch64::ST3LN_WB_S_register, Convert__Reg1_5__Tie0__Reg1_7__VTripleS31_0__UImm21_2, Feature_HasNEON, { MCK_VTripleS3, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1995 /* st3 */, AArch64::ST3LN_WB_S_fixed, Convert__Reg1_5__Tie0__Exact121_7__VTripleS31_0__UImm21_2, Feature_HasNEON, { MCK_VTripleS3, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact12 }, },
  { 1999 /* st4 */, AArch64::ST4_16B, Convert__Reg1_2__VQuad16B41_0, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1999 /* st4 */, AArch64::ST4_2D, Convert__Reg1_2__VQuad2D41_0, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1999 /* st4 */, AArch64::ST4_2S, Convert__Reg1_2__VQuad2S41_0, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1999 /* st4 */, AArch64::ST4_4H, Convert__Reg1_2__VQuad4H41_0, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1999 /* st4 */, AArch64::ST4_4S, Convert__Reg1_2__VQuad4S41_0, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1999 /* st4 */, AArch64::ST4_8B, Convert__Reg1_2__VQuad8B41_0, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1999 /* st4 */, AArch64::ST4_8H, Convert__Reg1_2__VQuad8H41_0, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1999 /* st4 */, AArch64::ST4WB_16B_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad16B41_0, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1999 /* st4 */, AArch64::ST4WB_16B_fixed, Convert__Reg1_2__Tie0__Exact641_4__VQuad16B41_0, Feature_HasNEON, { MCK_VQuad16B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 1999 /* st4 */, AArch64::ST4WB_2D_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad2D41_0, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1999 /* st4 */, AArch64::ST4WB_2D_fixed, Convert__Reg1_2__Tie0__Exact641_4__VQuad2D41_0, Feature_HasNEON, { MCK_VQuad2D4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 1999 /* st4 */, AArch64::ST4WB_2S_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad2S41_0, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1999 /* st4 */, AArch64::ST4WB_2S_fixed, Convert__Reg1_2__Tie0__Exact321_4__VQuad2S41_0, Feature_HasNEON, { MCK_VQuad2S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1999 /* st4 */, AArch64::ST4WB_4H_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad4H41_0, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1999 /* st4 */, AArch64::ST4WB_4H_fixed, Convert__Reg1_2__Tie0__Exact321_4__VQuad4H41_0, Feature_HasNEON, { MCK_VQuad4H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1999 /* st4 */, AArch64::ST4WB_4S_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad4S41_0, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1999 /* st4 */, AArch64::ST4WB_4S_fixed, Convert__Reg1_2__Tie0__Exact641_4__VQuad4S41_0, Feature_HasNEON, { MCK_VQuad4S4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 1999 /* st4 */, AArch64::ST4WB_8B_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad8B41_0, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1999 /* st4 */, AArch64::ST4WB_8B_fixed, Convert__Reg1_2__Tie0__Exact321_4__VQuad8B41_0, Feature_HasNEON, { MCK_VQuad8B4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1999 /* st4 */, AArch64::ST4WB_8H_register, Convert__Reg1_2__Tie0__Reg1_4__VQuad8H41_0, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1999 /* st4 */, AArch64::ST4WB_8H_fixed, Convert__Reg1_2__Tie0__Exact641_4__VQuad8H41_0, Feature_HasNEON, { MCK_VQuad8H4, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact64 }, },
  { 1999 /* st4 */, AArch64::ST4LN_B, Convert__Reg1_5__VQuadB41_0__UImm41_2, Feature_HasNEON, { MCK_VQuadB4, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1999 /* st4 */, AArch64::ST4LN_D, Convert__Reg1_5__VQuadD41_0__UImm11_2, Feature_HasNEON, { MCK_VQuadD4, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1999 /* st4 */, AArch64::ST4LN_H, Convert__Reg1_5__VQuadH41_0__UImm31_2, Feature_HasNEON, { MCK_VQuadH4, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1999 /* st4 */, AArch64::ST4LN_S, Convert__Reg1_5__VQuadS41_0__UImm21_2, Feature_HasNEON, { MCK_VQuadS4, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 1999 /* st4 */, AArch64::ST4LN_WB_B_register, Convert__Reg1_5__Tie0__Reg1_7__VQuadB41_0__UImm41_2, Feature_HasNEON, { MCK_VQuadB4, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1999 /* st4 */, AArch64::ST4LN_WB_B_fixed, Convert__Reg1_5__Tie0__Exact41_7__VQuadB41_0__UImm41_2, Feature_HasNEON, { MCK_VQuadB4, MCK__91_, MCK_UImm4, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact4 }, },
  { 1999 /* st4 */, AArch64::ST4LN_WB_D_register, Convert__Reg1_5__Tie0__Reg1_7__VQuadD41_0__UImm11_2, Feature_HasNEON, { MCK_VQuadD4, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1999 /* st4 */, AArch64::ST4LN_WB_D_fixed, Convert__Reg1_5__Tie0__Exact321_7__VQuadD41_0__UImm11_2, Feature_HasNEON, { MCK_VQuadD4, MCK__91_, MCK_UImm1, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact32 }, },
  { 1999 /* st4 */, AArch64::ST4LN_WB_H_register, Convert__Reg1_5__Tie0__Reg1_7__VQuadH41_0__UImm31_2, Feature_HasNEON, { MCK_VQuadH4, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1999 /* st4 */, AArch64::ST4LN_WB_H_fixed, Convert__Reg1_5__Tie0__Exact81_7__VQuadH41_0__UImm31_2, Feature_HasNEON, { MCK_VQuadH4, MCK__91_, MCK_UImm3, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact8 }, },
  { 1999 /* st4 */, AArch64::ST4LN_WB_S_register, Convert__Reg1_5__Tie0__Reg1_7__VQuadS41_0__UImm21_2, Feature_HasNEON, { MCK_VQuadS4, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_GPR64noxzr }, },
  { 1999 /* st4 */, AArch64::ST4LN_WB_S_fixed, Convert__Reg1_5__Tie0__Exact161_7__VQuadS41_0__UImm21_2, Feature_HasNEON, { MCK_VQuadS4, MCK__91_, MCK_UImm2, MCK__93_, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_Exact16 }, },
  { 2003 /* stlr */, AArch64::STLR_word, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2003 /* stlr */, AArch64::STLR_dword, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2008 /* stlrb */, AArch64::STLR_byte, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2014 /* stlrh */, AArch64::STLR_hword, Convert__Reg1_0__GPR64xsp01_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2020 /* stlxp */, AArch64::STLXP_word, Convert__Reg1_0__Reg1_1__Reg1_2__GPR64xsp01_4, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2020 /* stlxp */, AArch64::STLXP_dword, Convert__Reg1_0__Reg1_1__Reg1_2__GPR64xsp01_4, 0, { MCK_GPR32, MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2026 /* stlxr */, AArch64::STLXR_word, Convert__Reg1_0__Reg1_1__GPR64xsp01_3, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2026 /* stlxr */, AArch64::STLXR_dword, Convert__Reg1_0__Reg1_1__GPR64xsp01_3, 0, { MCK_GPR32, MCK_GPR64, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2032 /* stlxrb */, AArch64::STLXR_byte, Convert__Reg1_0__Reg1_1__GPR64xsp01_3, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2039 /* stlxrh */, AArch64::STLXR_hword, Convert__Reg1_0__Reg1_1__GPR64xsp01_3, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2046 /* stnp */, AArch64::LSPair32_NonTemp_STR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2046 /* stnp */, AArch64::LSPair64_NonTemp_STR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2046 /* stnp */, AArch64::LSFPPair32_NonTemp_STR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2046 /* stnp */, AArch64::LSFPPair64_NonTemp_STR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2046 /* stnp */, AArch64::LSFPPair128_NonTemp_STR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, Feature_HasFPARMv8, { MCK_FPR128, MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2046 /* stnp */, AArch64::LSPair32_NonTemp_STR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled41_4, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_ }, },
  { 2046 /* stnp */, AArch64::LSPair64_NonTemp_STR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled81_4, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled8, MCK__93_ }, },
  { 2046 /* stnp */, AArch64::LSFPPair32_NonTemp_STR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled41_4, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_ }, },
  { 2046 /* stnp */, AArch64::LSFPPair64_NonTemp_STR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled81_4, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled8, MCK__93_ }, },
  { 2046 /* stnp */, AArch64::LSFPPair128_NonTemp_STR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled161_4, Feature_HasFPARMv8, { MCK_FPR128, MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled16, MCK__93_ }, },
  { 2051 /* stp */, AArch64::LSPair32_STR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2051 /* stp */, AArch64::LSPair64_STR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2051 /* stp */, AArch64::LSFPPair32_STR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2051 /* stp */, AArch64::LSFPPair64_STR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2051 /* stp */, AArch64::LSFPPair128_STR, Convert__Reg1_0__Reg1_1__Reg1_3__imm_0, Feature_HasFPARMv8, { MCK_FPR128, MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2051 /* stp */, AArch64::LSPair32_PostInd_STR, Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled41_5, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm7_Scaled4 }, },
  { 2051 /* stp */, AArch64::LSPair32_STR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled41_4, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_ }, },
  { 2051 /* stp */, AArch64::LSPair64_PostInd_STR, Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled81_5, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm7_Scaled8 }, },
  { 2051 /* stp */, AArch64::LSPair64_STR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled81_4, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled8, MCK__93_ }, },
  { 2051 /* stp */, AArch64::LSFPPair32_PostInd_STR, Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled41_5, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm7_Scaled4 }, },
  { 2051 /* stp */, AArch64::LSFPPair32_STR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled41_4, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_ }, },
  { 2051 /* stp */, AArch64::LSFPPair64_PostInd_STR, Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled81_5, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm7_Scaled8 }, },
  { 2051 /* stp */, AArch64::LSFPPair64_STR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled81_4, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled8, MCK__93_ }, },
  { 2051 /* stp */, AArch64::LSFPPair128_PostInd_STR, Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled161_5, Feature_HasFPARMv8, { MCK_FPR128, MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm7_Scaled16 }, },
  { 2051 /* stp */, AArch64::LSFPPair128_STR, Convert__Reg1_0__Reg1_1__Reg1_3__SImm7_Scaled161_4, Feature_HasFPARMv8, { MCK_FPR128, MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled16, MCK__93_ }, },
  { 2051 /* stp */, AArch64::LSPair32_PreInd_STR, Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled41_4, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_, MCK__EXCLAIM_ }, },
  { 2051 /* stp */, AArch64::LSPair64_PreInd_STR, Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled81_4, 0, { MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled8, MCK__93_, MCK__EXCLAIM_ }, },
  { 2051 /* stp */, AArch64::LSFPPair32_PreInd_STR, Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled41_4, Feature_HasFPARMv8, { MCK_FPR32, MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled4, MCK__93_, MCK__EXCLAIM_ }, },
  { 2051 /* stp */, AArch64::LSFPPair64_PreInd_STR, Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled81_4, Feature_HasFPARMv8, { MCK_FPR64, MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled8, MCK__93_, MCK__EXCLAIM_ }, },
  { 2051 /* stp */, AArch64::LSFPPair128_PreInd_STR, Convert__Reg1_3__Reg1_0__Reg1_1__Tie0__SImm7_Scaled161_4, Feature_HasFPARMv8, { MCK_FPR128, MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_SImm7_Scaled16, MCK__93_, MCK__EXCLAIM_ }, },
  { 2055 /* str */, AArch64::LS32_STR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2055 /* str */, AArch64::LS64_STR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP8_STR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP16_STR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP32_STR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP64_STR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP128_STR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2055 /* str */, AArch64::LS32_PostInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 2055 /* str */, AArch64::LS32_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 2055 /* str */, AArch64::LS32_STR, Convert__Reg1_0__Reg1_2__OffsetUImm12_41_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_4, MCK__93_ }, },
  { 2055 /* str */, AArch64::LS64_PostInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 2055 /* str */, AArch64::LS64_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 2055 /* str */, AArch64::LS64_STR, Convert__Reg1_0__Reg1_2__OffsetUImm12_81_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_8, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP8_PostInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_4, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 2055 /* str */, AArch64::LSFP8_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP8_STR, Convert__Reg1_0__Reg1_2__OffsetUImm12_11_3, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_1, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP16_PostInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_4, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 2055 /* str */, AArch64::LSFP16_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP16_STR, Convert__Reg1_0__Reg1_2__OffsetUImm12_21_3, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_2, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP32_PostInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_4, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 2055 /* str */, AArch64::LSFP32_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP32_STR, Convert__Reg1_0__Reg1_2__OffsetUImm12_41_3, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_4, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP64_PostInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_4, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 2055 /* str */, AArch64::LSFP64_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP64_STR, Convert__Reg1_0__Reg1_2__OffsetUImm12_81_3, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_8, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP128_PostInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_4, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 2055 /* str */, AArch64::LSFP128_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP128_STR, Convert__Reg1_0__Reg1_2__OffsetUImm12_161_3, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_16, MCK__93_ }, },
  { 2055 /* str */, AArch64::LS32_Wm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Wm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_4_Wm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LS32_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Xm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_4_Xm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LS32_PreInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 2055 /* str */, AArch64::LS64_Wm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Wm1_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_8_Wm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LS64_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Xm1_4, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_8_Xm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LS64_PreInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 2055 /* str */, AArch64::LSFP8_Wm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Wm1_4, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_1_Wm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP8_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Xm1_4, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_1_Xm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP8_PreInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_3, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 2055 /* str */, AArch64::LSFP16_Wm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Wm1_4, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_2_Wm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP16_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Xm1_4, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_2_Xm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP16_PreInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_3, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 2055 /* str */, AArch64::LSFP32_Wm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Wm1_4, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_4_Wm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP32_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_4_Xm1_4, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_4_Xm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP32_PreInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_3, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 2055 /* str */, AArch64::LSFP64_Wm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Wm1_4, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_8_Wm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP64_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_8_Xm1_4, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_8_Xm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP64_PreInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_3, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 2055 /* str */, AArch64::LSFP128_Wm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_16_Wm1_4, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_16_Wm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP128_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_16_Xm1_4, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_16_Xm, MCK__93_ }, },
  { 2055 /* str */, AArch64::LSFP128_PreInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_3, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 2059 /* strb */, AArch64::LS8_STR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2059 /* strb */, AArch64::LS8_PostInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 2059 /* strb */, AArch64::LS8_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 2059 /* strb */, AArch64::LS8_STR, Convert__Reg1_0__Reg1_2__OffsetUImm12_11_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_1, MCK__93_ }, },
  { 2059 /* strb */, AArch64::LS8_Wm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Wm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_1_Wm, MCK__93_ }, },
  { 2059 /* strb */, AArch64::LS8_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_1_Xm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_1_Xm, MCK__93_ }, },
  { 2059 /* strb */, AArch64::LS8_PreInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 2064 /* strh */, AArch64::LS16_STR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2064 /* strh */, AArch64::LS16_PostInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_, MCK_SImm9 }, },
  { 2064 /* strh */, AArch64::LS16_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__imm_2, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK__93_ }, },
  { 2064 /* strh */, AArch64::LS16_STR, Convert__Reg1_0__Reg1_2__OffsetUImm12_21_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_OffsetUImm12_2, MCK__93_ }, },
  { 2064 /* strh */, AArch64::LS16_Wm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Wm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR32, MCK_AddrRegExtend_2_Wm, MCK__93_ }, },
  { 2064 /* strh */, AArch64::LS16_Xm_RegOffset_STR, Convert__Reg1_0__Reg1_2__Reg1_3__AddrRegExtend_2_Xm1_4, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_GPR64, MCK_AddrRegExtend_2_Xm, MCK__93_ }, },
  { 2064 /* strh */, AArch64::LS16_PreInd_STR, Convert__Reg1_2__Reg1_0__Tie0__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_, MCK__EXCLAIM_ }, },
  { 2069 /* sttr */, AArch64::LS32_UnPriv_STR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2069 /* sttr */, AArch64::LS64_UnPriv_STR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2069 /* sttr */, AArch64::LS32_UnPriv_STR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 2069 /* sttr */, AArch64::LS64_UnPriv_STR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 2074 /* sttrb */, AArch64::LS8_UnPriv_STR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2074 /* sttrb */, AArch64::LS8_UnPriv_STR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 2080 /* sttrh */, AArch64::LS16_UnPriv_STR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2080 /* sttrh */, AArch64::LS16_UnPriv_STR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LS32_STUR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LS64_STUR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LSFP8_STUR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LSFP16_STUR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LSFP32_STUR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LSFP64_STUR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LSFP128_STUR, Convert__Reg1_0__Reg1_2__imm_0, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LS32_STUR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LS64_STUR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LSFP8_STUR, Convert__Reg1_0__Reg1_2__SImm91_3, Feature_HasFPARMv8, { MCK_FPR8, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LSFP16_STUR, Convert__Reg1_0__Reg1_2__SImm91_3, Feature_HasFPARMv8, { MCK_FPR16, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LSFP32_STUR, Convert__Reg1_0__Reg1_2__SImm91_3, Feature_HasFPARMv8, { MCK_FPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LSFP64_STUR, Convert__Reg1_0__Reg1_2__SImm91_3, Feature_HasFPARMv8, { MCK_FPR64, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 2086 /* stur */, AArch64::LSFP128_STUR, Convert__Reg1_0__Reg1_2__SImm91_3, Feature_HasFPARMv8, { MCK_FPR128, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 2091 /* sturb */, AArch64::LS8_STUR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2091 /* sturb */, AArch64::LS8_STUR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 2097 /* sturh */, AArch64::LS16_STUR, Convert__Reg1_0__Reg1_2__imm_0, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK__93_ }, },
  { 2097 /* sturh */, AArch64::LS16_STUR, Convert__Reg1_0__Reg1_2__SImm91_3, 0, { MCK_GPR32, MCK__91_, MCK_GPR64xsp, MCK_SImm9, MCK__93_ }, },
  { 2103 /* stxp */, AArch64::STXP_word, Convert__Reg1_0__Reg1_1__Reg1_2__GPR64xsp01_4, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2103 /* stxp */, AArch64::STXP_dword, Convert__Reg1_0__Reg1_1__Reg1_2__GPR64xsp01_4, 0, { MCK_GPR32, MCK_GPR64, MCK_GPR64, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2108 /* stxr */, AArch64::STXR_word, Convert__Reg1_0__Reg1_1__GPR64xsp01_3, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2108 /* stxr */, AArch64::STXR_dword, Convert__Reg1_0__Reg1_1__GPR64xsp01_3, 0, { MCK_GPR32, MCK_GPR64, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2113 /* stxrb */, AArch64::STXR_byte, Convert__Reg1_0__Reg1_1__GPR64xsp01_3, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2119 /* stxrh */, AArch64::STXR_hword, Convert__Reg1_0__Reg1_1__GPR64xsp01_3, 0, { MCK_GPR32, MCK_GPR32, MCK__91_, MCK_GPR64xsp0, MCK__93_ }, },
  { 2125 /* sub */, AArch64::SUBwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 2125 /* sub */, AArch64::SUBwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_Rwsp, MCK_GPR32wsp, MCK_GPR32 }, },
  { 2125 /* sub */, AArch64::SUBwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32wsp, MCK_Rwsp, MCK_GPR32 }, },
  { 2125 /* sub */, AArch64::SUBwwi_lsl0_s, Convert__Reg1_0__Reg1_1__AddSubImmLSL01_2, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_AddSubImmLSL0 }, },
  { 2125 /* sub */, AArch64::SUBwwi_lsl12_s, Convert__Reg1_0__Reg1_1__AddSubImmLSL121_2, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_AddSubImmLSL12 }, },
  { 2125 /* sub */, AArch64::SUBxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 2125 /* sub */, AArch64::SUBxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_Rxsp, MCK_GPR64xsp, MCK_GPR64 }, },
  { 2125 /* sub */, AArch64::SUBxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64xsp, MCK_Rxsp, MCK_GPR64 }, },
  { 2125 /* sub */, AArch64::SUBxxi_lsl0_s, Convert__Reg1_0__Reg1_1__AddSubImmLSL01_2, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_AddSubImmLSL0 }, },
  { 2125 /* sub */, AArch64::SUBxxi_lsl12_s, Convert__Reg1_0__Reg1_1__AddSubImmLSL121_2, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_AddSubImmLSL12 }, },
  { 2125 /* sub */, AArch64::SUBddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 2125 /* sub */, AArch64::SUBwww_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 2125 /* sub */, AArch64::SUBwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 2125 /* sub */, AArch64::SUBwww_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 2125 /* sub */, AArch64::SUBwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3, 0, { MCK_Rwsp, MCK_GPR32wsp, MCK_GPR32, MCK_RegExtendLSL }, },
  { 2125 /* sub */, AArch64::SUBwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3, 0, { MCK_GPR32wsp, MCK_Rwsp, MCK_GPR32, MCK_RegExtendLSL }, },
  { 2125 /* sub */, AArch64::SUBwww_sxtb, Convert__Reg1_0__Reg1_1__Reg1_2__SXTB1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_SXTB }, },
  { 2125 /* sub */, AArch64::SUBwww_sxth, Convert__Reg1_0__Reg1_1__Reg1_2__SXTH1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_SXTH }, },
  { 2125 /* sub */, AArch64::SUBwww_sxtw, Convert__Reg1_0__Reg1_1__Reg1_2__SXTW1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_SXTW }, },
  { 2125 /* sub */, AArch64::SUBwww_sxtx, Convert__Reg1_0__Reg1_1__Reg1_2__SXTX1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_SXTX }, },
  { 2125 /* sub */, AArch64::SUBwww_uxtb, Convert__Reg1_0__Reg1_1__Reg1_2__UXTB1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_UXTB }, },
  { 2125 /* sub */, AArch64::SUBwww_uxth, Convert__Reg1_0__Reg1_1__Reg1_2__UXTH1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_UXTH }, },
  { 2125 /* sub */, AArch64::SUBwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__UXTW1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_UXTW }, },
  { 2125 /* sub */, AArch64::SUBwww_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__UXTX1_3, 0, { MCK_GPR32wsp, MCK_GPR32wsp, MCK_GPR32, MCK_UXTX }, },
  { 2125 /* sub */, AArch64::SUBxxx_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 2125 /* sub */, AArch64::SUBxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 2125 /* sub */, AArch64::SUBxxx_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 2125 /* sub */, AArch64::SUBxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3, 0, { MCK_Rxsp, MCK_GPR64xsp, MCK_GPR64, MCK_RegExtendLSL }, },
  { 2125 /* sub */, AArch64::SUBxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3, 0, { MCK_GPR64xsp, MCK_Rxsp, MCK_GPR64, MCK_RegExtendLSL }, },
  { 2125 /* sub */, AArch64::SUBxxw_sxtb, Convert__Reg1_0__Reg1_1__Reg1_2__SXTB1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR32, MCK_SXTB }, },
  { 2125 /* sub */, AArch64::SUBxxw_sxth, Convert__Reg1_0__Reg1_1__Reg1_2__SXTH1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR32, MCK_SXTH }, },
  { 2125 /* sub */, AArch64::SUBxxw_sxtw, Convert__Reg1_0__Reg1_1__Reg1_2__SXTW1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR32, MCK_SXTW }, },
  { 2125 /* sub */, AArch64::SUBxxw_uxtb, Convert__Reg1_0__Reg1_1__Reg1_2__UXTB1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR32, MCK_UXTB }, },
  { 2125 /* sub */, AArch64::SUBxxw_uxth, Convert__Reg1_0__Reg1_1__Reg1_2__UXTH1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR32, MCK_UXTH }, },
  { 2125 /* sub */, AArch64::SUBxxw_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__UXTW1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR32, MCK_UXTW }, },
  { 2125 /* sub */, AArch64::SUBxxx_sxtx, Convert__Reg1_0__Reg1_1__Reg1_2__SXTX1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR64, MCK_SXTX }, },
  { 2125 /* sub */, AArch64::SUBxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__UXTX1_3, 0, { MCK_GPR64xsp, MCK_GPR64xsp, MCK_GPR64, MCK_UXTX }, },
  { 2125 /* sub */, AArch64::SUBvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2125 /* sub */, AArch64::SUBvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2125 /* sub */, AArch64::SUBvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2125 /* sub */, AArch64::SUBvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2125 /* sub */, AArch64::SUBvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2125 /* sub */, AArch64::SUBvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2125 /* sub */, AArch64::SUBvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2129 /* subhn */, AArch64::SUBHNvvv_2s2d, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2129 /* subhn */, AArch64::SUBHNvvv_4h4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2129 /* subhn */, AArch64::SUBHNvvv_8b8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2135 /* subhn2 */, AArch64::SUBHN2vvv_16b8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2135 /* subhn2 */, AArch64::SUBHN2vvv_4s2d, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2135 /* subhn2 */, AArch64::SUBHN2vvv_8h4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2142 /* subs */, AArch64::SUBSwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 2142 /* subs */, AArch64::SUBSwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR32, MCK_Rwsp, MCK_GPR32 }, },
  { 2142 /* subs */, AArch64::SUBwwi_lsl0_S, Convert__Reg1_0__Reg1_1__AddSubImmLSL01_2, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_AddSubImmLSL0 }, },
  { 2142 /* subs */, AArch64::SUBwwi_lsl12_S, Convert__Reg1_0__Reg1_1__AddSubImmLSL121_2, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_AddSubImmLSL12 }, },
  { 2142 /* subs */, AArch64::SUBSxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 2142 /* subs */, AArch64::SUBSxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__imm_0, 0, { MCK_GPR64, MCK_Rxsp, MCK_GPR64 }, },
  { 2142 /* subs */, AArch64::SUBxxi_lsl0_S, Convert__Reg1_0__Reg1_1__AddSubImmLSL01_2, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_AddSubImmLSL0 }, },
  { 2142 /* subs */, AArch64::SUBxxi_lsl12_S, Convert__Reg1_0__Reg1_1__AddSubImmLSL121_2, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_AddSubImmLSL12 }, },
  { 2142 /* subs */, AArch64::SUBSwww_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 2142 /* subs */, AArch64::SUBSwww_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 2142 /* subs */, AArch64::SUBSwww_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi321_3, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 2142 /* subs */, AArch64::SUBSwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3, 0, { MCK_GPR32, MCK_Rwsp, MCK_GPR32, MCK_RegExtendLSL }, },
  { 2142 /* subs */, AArch64::SUBSwww_sxtb, Convert__Reg1_0__Reg1_1__Reg1_2__SXTB1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_SXTB }, },
  { 2142 /* subs */, AArch64::SUBSwww_sxth, Convert__Reg1_0__Reg1_1__Reg1_2__SXTH1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_SXTH }, },
  { 2142 /* subs */, AArch64::SUBSwww_sxtw, Convert__Reg1_0__Reg1_1__Reg1_2__SXTW1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_SXTW }, },
  { 2142 /* subs */, AArch64::SUBSwww_sxtx, Convert__Reg1_0__Reg1_1__Reg1_2__SXTX1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_SXTX }, },
  { 2142 /* subs */, AArch64::SUBSwww_uxtb, Convert__Reg1_0__Reg1_1__Reg1_2__UXTB1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_UXTB }, },
  { 2142 /* subs */, AArch64::SUBSwww_uxth, Convert__Reg1_0__Reg1_1__Reg1_2__UXTH1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_UXTH }, },
  { 2142 /* subs */, AArch64::SUBSwww_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__UXTW1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_UXTW }, },
  { 2142 /* subs */, AArch64::SUBSwww_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__UXTX1_3, 0, { MCK_GPR32, MCK_GPR32wsp, MCK_GPR32, MCK_UXTX }, },
  { 2142 /* subs */, AArch64::SUBSxxx_asr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftASRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 2142 /* subs */, AArch64::SUBSxxx_lsl, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSLi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 2142 /* subs */, AArch64::SUBSxxx_lsr, Convert__Reg1_0__Reg1_1__Reg1_2__ShiftLSRi641_3, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 2142 /* subs */, AArch64::SUBSxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__RegExtendLSL1_3, 0, { MCK_GPR64, MCK_Rxsp, MCK_GPR64, MCK_RegExtendLSL }, },
  { 2142 /* subs */, AArch64::SUBSxxw_sxtb, Convert__Reg1_0__Reg1_1__Reg1_2__SXTB1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR32, MCK_SXTB }, },
  { 2142 /* subs */, AArch64::SUBSxxw_sxth, Convert__Reg1_0__Reg1_1__Reg1_2__SXTH1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR32, MCK_SXTH }, },
  { 2142 /* subs */, AArch64::SUBSxxw_sxtw, Convert__Reg1_0__Reg1_1__Reg1_2__SXTW1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR32, MCK_SXTW }, },
  { 2142 /* subs */, AArch64::SUBSxxw_uxtb, Convert__Reg1_0__Reg1_1__Reg1_2__UXTB1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR32, MCK_UXTB }, },
  { 2142 /* subs */, AArch64::SUBSxxw_uxth, Convert__Reg1_0__Reg1_1__Reg1_2__UXTH1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR32, MCK_UXTH }, },
  { 2142 /* subs */, AArch64::SUBSxxw_uxtw, Convert__Reg1_0__Reg1_1__Reg1_2__UXTW1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR32, MCK_UXTW }, },
  { 2142 /* subs */, AArch64::SUBSxxx_sxtx, Convert__Reg1_0__Reg1_1__Reg1_2__SXTX1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR64, MCK_SXTX }, },
  { 2142 /* subs */, AArch64::SUBSxxx_uxtx, Convert__Reg1_0__Reg1_1__Reg1_2__UXTX1_3, 0, { MCK_GPR64, MCK_GPR64xsp, MCK_GPR64, MCK_UXTX }, },
  { 2147 /* suqadd */, AArch64::SUQADDbb, Convert__Reg1_0__Tie0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR8 }, },
  { 2147 /* suqadd */, AArch64::SUQADDhh, Convert__Reg1_0__Tie0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR16 }, },
  { 2147 /* suqadd */, AArch64::SUQADDss, Convert__Reg1_0__Tie0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 2147 /* suqadd */, AArch64::SUQADDdd, Convert__Reg1_0__Tie0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 2147 /* suqadd */, AArch64::SUQADD2s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2147 /* suqadd */, AArch64::SUQADD4h, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2147 /* suqadd */, AArch64::SUQADD8b, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2147 /* suqadd */, AArch64::SUQADD16b, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2147 /* suqadd */, AArch64::SUQADD2d, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2147 /* suqadd */, AArch64::SUQADD4s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2147 /* suqadd */, AArch64::SUQADD8h, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2154 /* svc */, AArch64::SVCi, Convert__UImm161_0, 0, { MCK_UImm16 }, },
  { 2158 /* sxtb */, AArch64::SXTBww, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 2158 /* sxtb */, AArch64::SXTBxw, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR64, MCK_GPR32 }, },
  { 2163 /* sxth */, AArch64::SXTHww, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 2163 /* sxth */, AArch64::SXTHxw, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR64, MCK_GPR32 }, },
  { 2168 /* sxtw */, AArch64::SXTWxw, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR64, MCK_GPR32 }, },
  { 2173 /* sys */, AArch64::SYSiccix, Convert__UImm31_0__CRx1_1__CRx1_2__UImm31_3__regXZR, 0, { MCK_UImm3, MCK_CRx, MCK_CRx, MCK_UImm3 }, },
  { 2173 /* sys */, AArch64::SYSiccix, Convert__UImm31_0__CRx1_1__CRx1_2__UImm31_3__Reg1_4, 0, { MCK_UImm3, MCK_CRx, MCK_CRx, MCK_UImm3, MCK_GPR64 }, },
  { 2177 /* sysl */, AArch64::SYSLxicci, Convert__Reg1_0__UImm31_1__CRx1_2__CRx1_3__UImm31_4, 0, { MCK_GPR64, MCK_UImm3, MCK_CRx, MCK_CRx, MCK_UImm3 }, },
  { 2182 /* tbl */, AArch64::TBL1_8b, Convert__Reg1_0__VOne16B11_2__Reg1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_VOne16B1, MCK_FPR64, MCK__DOT_8b }, },
  { 2182 /* tbl */, AArch64::TBL2_8b, Convert__Reg1_0__VPair16B21_2__Reg1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_VPair16B2, MCK_FPR64, MCK__DOT_8b }, },
  { 2182 /* tbl */, AArch64::TBL4_8b, Convert__Reg1_0__VQuad16B41_2__Reg1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_VQuad16B4, MCK_FPR64, MCK__DOT_8b }, },
  { 2182 /* tbl */, AArch64::TBL3_8b, Convert__Reg1_0__VTriple16B31_2__Reg1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_VTriple16B3, MCK_FPR64, MCK__DOT_8b }, },
  { 2182 /* tbl */, AArch64::TBL1_16b, Convert__Reg1_0__VOne16B11_2__Reg1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_VOne16B1, MCK_FPR128, MCK__DOT_16b }, },
  { 2182 /* tbl */, AArch64::TBL2_16b, Convert__Reg1_0__VPair16B21_2__Reg1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_VPair16B2, MCK_FPR128, MCK__DOT_16b }, },
  { 2182 /* tbl */, AArch64::TBL4_16b, Convert__Reg1_0__VQuad16B41_2__Reg1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_VQuad16B4, MCK_FPR128, MCK__DOT_16b }, },
  { 2182 /* tbl */, AArch64::TBL3_16b, Convert__Reg1_0__VTriple16B31_2__Reg1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_VTriple16B3, MCK_FPR128, MCK__DOT_16b }, },
  { 2186 /* tbnz */, AArch64::TBNZwii, Convert__Reg1_0__UImm51_1__Label14_41_2, 0, { MCK_GPR32, MCK_UImm5, MCK_Label14_4 }, },
  { 2186 /* tbnz */, AArch64::TBNZxii, Convert__Reg1_0__UImm61_1__Label14_41_2, 0, { MCK_GPR64, MCK_UImm6, MCK_Label14_4 }, },
  { 2191 /* tbx */, AArch64::TBX1_8b, Convert__Reg1_0__Tie0__VOne16B11_2__Reg1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_VOne16B1, MCK_FPR64, MCK__DOT_8b }, },
  { 2191 /* tbx */, AArch64::TBX2_8b, Convert__Reg1_0__Tie0__VPair16B21_2__Reg1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_VPair16B2, MCK_FPR64, MCK__DOT_8b }, },
  { 2191 /* tbx */, AArch64::TBX4_8b, Convert__Reg1_0__Tie0__VQuad16B41_2__Reg1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_VQuad16B4, MCK_FPR64, MCK__DOT_8b }, },
  { 2191 /* tbx */, AArch64::TBX3_8b, Convert__Reg1_0__Tie0__VTriple16B31_2__Reg1_3, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_VTriple16B3, MCK_FPR64, MCK__DOT_8b }, },
  { 2191 /* tbx */, AArch64::TBX1_16b, Convert__Reg1_0__Tie0__VOne16B11_2__Reg1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_VOne16B1, MCK_FPR128, MCK__DOT_16b }, },
  { 2191 /* tbx */, AArch64::TBX2_16b, Convert__Reg1_0__Tie0__VPair16B21_2__Reg1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_VPair16B2, MCK_FPR128, MCK__DOT_16b }, },
  { 2191 /* tbx */, AArch64::TBX4_16b, Convert__Reg1_0__Tie0__VQuad16B41_2__Reg1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_VQuad16B4, MCK_FPR128, MCK__DOT_16b }, },
  { 2191 /* tbx */, AArch64::TBX3_16b, Convert__Reg1_0__Tie0__VTriple16B31_2__Reg1_3, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_VTriple16B3, MCK_FPR128, MCK__DOT_16b }, },
  { 2195 /* tbz */, AArch64::TBZwii, Convert__Reg1_0__UImm51_1__Label14_41_2, 0, { MCK_GPR32, MCK_UImm5, MCK_Label14_4 }, },
  { 2195 /* tbz */, AArch64::TBZxii, Convert__Reg1_0__UImm61_1__Label14_41_2, 0, { MCK_GPR64, MCK_UImm6, MCK_Label14_4 }, },
  { 2199 /* tlbi */, AArch64::TLBIi, Convert__NamedImmtlbi1_0, 0, { MCK_NamedImmtlbi }, },
  { 2199 /* tlbi */, AArch64::TLBIix, Convert__NamedImmtlbi1_0__Reg1_1, 0, { MCK_NamedImmtlbi, MCK_GPR64 }, },
  { 2204 /* trn1 */, AArch64::TRN1vvv_2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2204 /* trn1 */, AArch64::TRN1vvv_4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2204 /* trn1 */, AArch64::TRN1vvv_8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2204 /* trn1 */, AArch64::TRN1vvv_16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2204 /* trn1 */, AArch64::TRN1vvv_2d, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2204 /* trn1 */, AArch64::TRN1vvv_4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2204 /* trn1 */, AArch64::TRN1vvv_8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2209 /* trn2 */, AArch64::TRN2vvv_2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2209 /* trn2 */, AArch64::TRN2vvv_4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2209 /* trn2 */, AArch64::TRN2vvv_8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2209 /* trn2 */, AArch64::TRN2vvv_16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2209 /* trn2 */, AArch64::TRN2vvv_2d, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2209 /* trn2 */, AArch64::TRN2vvv_4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2209 /* trn2 */, AArch64::TRN2vvv_8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2214 /* tst */, AArch64::TSTww_lsl, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 2214 /* tst */, AArch64::ANDSwwi, Convert__regWZR__Reg1_0__LogicalImm321_1, 0, { MCK_GPR32, MCK_LogicalImm32 }, },
  { 2214 /* tst */, AArch64::TSTxx_lsl, Convert__Reg1_0__Reg1_1__imm_0, 0, { MCK_GPR64, MCK_GPR64 }, },
  { 2214 /* tst */, AArch64::ANDSxxi, Convert__regXZR__Reg1_0__LogicalImm641_1, 0, { MCK_GPR64, MCK_LogicalImm64 }, },
  { 2214 /* tst */, AArch64::TSTww_asr, Convert__Reg1_0__Reg1_1__ShiftASRi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftASRi32 }, },
  { 2214 /* tst */, AArch64::TSTww_lsl, Convert__Reg1_0__Reg1_1__ShiftLSLi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftLSLi32 }, },
  { 2214 /* tst */, AArch64::TSTww_lsr, Convert__Reg1_0__Reg1_1__ShiftLSRi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftLSRi32 }, },
  { 2214 /* tst */, AArch64::TSTww_ror, Convert__Reg1_0__Reg1_1__ShiftRORi321_2, 0, { MCK_GPR32, MCK_GPR32, MCK_ShiftRORi32 }, },
  { 2214 /* tst */, AArch64::TSTxx_asr, Convert__Reg1_0__Reg1_1__ShiftASRi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftASRi64 }, },
  { 2214 /* tst */, AArch64::TSTxx_lsl, Convert__Reg1_0__Reg1_1__ShiftLSLi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftLSLi64 }, },
  { 2214 /* tst */, AArch64::TSTxx_lsr, Convert__Reg1_0__Reg1_1__ShiftLSRi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftLSRi64 }, },
  { 2214 /* tst */, AArch64::TSTxx_ror, Convert__Reg1_0__Reg1_1__ShiftRORi641_2, 0, { MCK_GPR64, MCK_GPR64, MCK_ShiftRORi64 }, },
  { 2218 /* uaba */, AArch64::UABAvvv_2S, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2218 /* uaba */, AArch64::UABAvvv_4H, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2218 /* uaba */, AArch64::UABAvvv_8B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2218 /* uaba */, AArch64::UABAvvv_16B, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2218 /* uaba */, AArch64::UABAvvv_4S, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2218 /* uaba */, AArch64::UABAvvv_8H, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2223 /* uabal */, AArch64::UABALvvv_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2223 /* uabal */, AArch64::UABALvvv_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2223 /* uabal */, AArch64::UABALvvv_8h8b, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2229 /* uabal2 */, AArch64::UABAL2vvv_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2229 /* uabal2 */, AArch64::UABAL2vvv_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2229 /* uabal2 */, AArch64::UABAL2vvv_8h8b, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2236 /* uabd */, AArch64::UABDvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2236 /* uabd */, AArch64::UABDvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2236 /* uabd */, AArch64::UABDvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2236 /* uabd */, AArch64::UABDvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2236 /* uabd */, AArch64::UABDvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2236 /* uabd */, AArch64::UABDvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2241 /* uabdl */, AArch64::UABDLvvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2241 /* uabdl */, AArch64::UABDLvvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2241 /* uabdl */, AArch64::UABDLvvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2247 /* uabdl2 */, AArch64::UABDL2vvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2247 /* uabdl2 */, AArch64::UABDL2vvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2247 /* uabdl2 */, AArch64::UABDL2vvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2254 /* uadalp */, AArch64::UADALP2s1d, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_1d, MCK_FPR64, MCK__DOT_2s }, },
  { 2254 /* uadalp */, AArch64::UADALP4h2s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_4h }, },
  { 2254 /* uadalp */, AArch64::UADALP8b4h, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_8b }, },
  { 2254 /* uadalp */, AArch64::UADALP4s2d, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s }, },
  { 2254 /* uadalp */, AArch64::UADALP8h4s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h }, },
  { 2254 /* uadalp */, AArch64::UADALP16b8h, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b }, },
  { 2261 /* uaddl */, AArch64::UADDLvvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2261 /* uaddl */, AArch64::UADDLvvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2261 /* uaddl */, AArch64::UADDLvvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2267 /* uaddl2 */, AArch64::UADDL2vvv_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2267 /* uaddl2 */, AArch64::UADDL2vvv_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2267 /* uaddl2 */, AArch64::UADDL2vvv_8h16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2274 /* uaddlp */, AArch64::UADDLP2s1d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_1d, MCK_FPR64, MCK__DOT_2s }, },
  { 2274 /* uaddlp */, AArch64::UADDLP4h2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_4h }, },
  { 2274 /* uaddlp */, AArch64::UADDLP8b4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_8b }, },
  { 2274 /* uaddlp */, AArch64::UADDLP4s2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s }, },
  { 2274 /* uaddlp */, AArch64::UADDLP8h4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h }, },
  { 2274 /* uaddlp */, AArch64::UADDLP16b8h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b }, },
  { 2281 /* uaddlv */, AArch64::UADDLV_1h8b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR64, MCK__DOT_8b }, },
  { 2281 /* uaddlv */, AArch64::UADDLV_1h16b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR128, MCK__DOT_16b }, },
  { 2281 /* uaddlv */, AArch64::UADDLV_1s4h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR64, MCK__DOT_4h }, },
  { 2281 /* uaddlv */, AArch64::UADDLV_1s8h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR128, MCK__DOT_8h }, },
  { 2281 /* uaddlv */, AArch64::UADDLV_1d4s, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR128, MCK__DOT_4s }, },
  { 2288 /* uaddw */, AArch64::UADDWvvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s }, },
  { 2288 /* uaddw */, AArch64::UADDWvvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h }, },
  { 2288 /* uaddw */, AArch64::UADDWvvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b }, },
  { 2294 /* uaddw2 */, AArch64::UADDW2vvv_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s }, },
  { 2294 /* uaddw2 */, AArch64::UADDW2vvv_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h }, },
  { 2294 /* uaddw2 */, AArch64::UADDW2vvv_8h16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b }, },
  { 2301 /* ubfiz */, AArch64::UBFIZwwii, Convert__Reg1_0__Reg1_1__BFI32LSB1_2__BFI32Width1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_BFI32LSB, MCK_BFI32Width }, },
  { 2301 /* ubfiz */, AArch64::UBFIZxxii, Convert__Reg1_0__Reg1_1__BFI64LSB1_2__BFI64Width1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_BFI64LSB, MCK_BFI64Width }, },
  { 2307 /* ubfm */, AArch64::UBFMwwii, Convert__Reg1_0__Reg1_1__UImm51_2__UImm51_3, 0, { MCK_GPR32, MCK_GPR32, MCK_UImm5, MCK_UImm5 }, },
  { 2307 /* ubfm */, AArch64::UBFMxxii, Convert__Reg1_0__Reg1_1__UImm61_2__UImm61_3, 0, { MCK_GPR64, MCK_GPR64, MCK_UImm6, MCK_UImm6 }, },
  { 2312 /* ubfx */, AArch64::UBFXwwii, Convert__Reg1_0__Reg1_1__UImm51_2__BFX32Width1_3, 0, { MCK_GPR32, MCK_GPR32, MCK_UImm5, MCK_BFX32Width }, },
  { 2312 /* ubfx */, AArch64::UBFXxxii, Convert__Reg1_0__Reg1_1__UImm61_2__BFX64Width1_3, 0, { MCK_GPR64, MCK_GPR64, MCK_UImm6, MCK_BFX64Width }, },
  { 2317 /* ucvtf */, AArch64::UCVTFsw, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_GPR32 }, },
  { 2317 /* ucvtf */, AArch64::UCVTFsx, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR32, MCK_GPR64 }, },
  { 2317 /* ucvtf */, AArch64::UCVTFss, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 2317 /* ucvtf */, AArch64::UCVTFdw, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_GPR32 }, },
  { 2317 /* ucvtf */, AArch64::UCVTFdx, Convert__Reg1_0__Reg1_1, Feature_HasFPARMv8, { MCK_FPR64, MCK_GPR64 }, },
  { 2317 /* ucvtf */, AArch64::UCVTFdd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 2317 /* ucvtf */, AArch64::UCVTFswi, Convert__Reg1_0__Reg1_1__CVTFixedPos321_2, Feature_HasFPARMv8, { MCK_FPR32, MCK_GPR32, MCK_CVTFixedPos32 }, },
  { 2317 /* ucvtf */, AArch64::UCVTFsxi, Convert__Reg1_0__Reg1_1__CVTFixedPos641_2, Feature_HasFPARMv8, { MCK_FPR32, MCK_GPR64, MCK_CVTFixedPos64 }, },
  { 2317 /* ucvtf */, AArch64::UCVTF_Nssi, Convert__Reg1_0__Reg1_1__ShrImm321_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_ShrImm32 }, },
  { 2317 /* ucvtf */, AArch64::UCVTFdwi, Convert__Reg1_0__Reg1_1__CVTFixedPos321_2, Feature_HasFPARMv8, { MCK_FPR64, MCK_GPR32, MCK_CVTFixedPos32 }, },
  { 2317 /* ucvtf */, AArch64::UCVTFdxi, Convert__Reg1_0__Reg1_1__CVTFixedPos641_2, Feature_HasFPARMv8, { MCK_FPR64, MCK_GPR64, MCK_CVTFixedPos64 }, },
  { 2317 /* ucvtf */, AArch64::UCVTF_Nddi, Convert__Reg1_0__Reg1_1__ShrImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShrImm64 }, },
  { 2317 /* ucvtf */, AArch64::UCVTF_2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2317 /* ucvtf */, AArch64::UCVTF_2d, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2317 /* ucvtf */, AArch64::UCVTF_4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2317 /* ucvtf */, AArch64::VCVTxu2f_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShrImm32 }, },
  { 2317 /* ucvtf */, AArch64::VCVTxu2f_2D, Convert__Reg1_0__Reg1_2__ShrImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm64 }, },
  { 2317 /* ucvtf */, AArch64::VCVTxu2f_4S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm32 }, },
  { 2323 /* udiv */, AArch64::UDIVwww, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR32, MCK_GPR32, MCK_GPR32 }, },
  { 2323 /* udiv */, AArch64::UDIVxxx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 2328 /* uhadd */, AArch64::UHADDvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2328 /* uhadd */, AArch64::UHADDvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2328 /* uhadd */, AArch64::UHADDvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2328 /* uhadd */, AArch64::UHADDvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2328 /* uhadd */, AArch64::UHADDvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2328 /* uhadd */, AArch64::UHADDvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2334 /* uhsub */, AArch64::UHSUBvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2334 /* uhsub */, AArch64::UHSUBvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2334 /* uhsub */, AArch64::UHSUBvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2334 /* uhsub */, AArch64::UHSUBvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2334 /* uhsub */, AArch64::UHSUBvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2334 /* uhsub */, AArch64::UHSUBvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2340 /* umaddl */, AArch64::UMADDLxwwx, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_GPR64, MCK_GPR32, MCK_GPR32, MCK_GPR64 }, },
  { 2347 /* umax */, AArch64::UMAXvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2347 /* umax */, AArch64::UMAXvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2347 /* umax */, AArch64::UMAXvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2347 /* umax */, AArch64::UMAXvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2347 /* umax */, AArch64::UMAXvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2347 /* umax */, AArch64::UMAXvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2352 /* umaxp */, AArch64::UMAXPvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2352 /* umaxp */, AArch64::UMAXPvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2352 /* umaxp */, AArch64::UMAXPvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2352 /* umaxp */, AArch64::UMAXPvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2352 /* umaxp */, AArch64::UMAXPvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2352 /* umaxp */, AArch64::UMAXPvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2358 /* umaxv */, AArch64::UMAXV_1b8b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR64, MCK__DOT_8b }, },
  { 2358 /* umaxv */, AArch64::UMAXV_1b16b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR128, MCK__DOT_16b }, },
  { 2358 /* umaxv */, AArch64::UMAXV_1h4h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR64, MCK__DOT_4h }, },
  { 2358 /* umaxv */, AArch64::UMAXV_1h8h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR128, MCK__DOT_8h }, },
  { 2358 /* umaxv */, AArch64::UMAXV_1s4s, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR128, MCK__DOT_4s }, },
  { 2364 /* umin */, AArch64::UMINvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2364 /* umin */, AArch64::UMINvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2364 /* umin */, AArch64::UMINvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2364 /* umin */, AArch64::UMINvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2364 /* umin */, AArch64::UMINvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2364 /* umin */, AArch64::UMINvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2369 /* uminp */, AArch64::UMINPvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2369 /* uminp */, AArch64::UMINPvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2369 /* uminp */, AArch64::UMINPvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2369 /* uminp */, AArch64::UMINPvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2369 /* uminp */, AArch64::UMINPvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2369 /* uminp */, AArch64::UMINPvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2375 /* uminv */, AArch64::UMINV_1b8b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR64, MCK__DOT_8b }, },
  { 2375 /* uminv */, AArch64::UMINV_1b16b, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR128, MCK__DOT_16b }, },
  { 2375 /* uminv */, AArch64::UMINV_1h4h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR64, MCK__DOT_4h }, },
  { 2375 /* uminv */, AArch64::UMINV_1h8h, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR128, MCK__DOT_8h }, },
  { 2375 /* uminv */, AArch64::UMINV_1s4s, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR128, MCK__DOT_4s }, },
  { 2381 /* umlal */, AArch64::UMLALvvv_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2381 /* umlal */, AArch64::UMLALvvv_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2381 /* umlal */, AArch64::UMLALvvv_8h8b, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2381 /* umlal */, AArch64::UMLALvve_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 2381 /* umlal */, AArch64::UMLALvve_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 2387 /* umlal2 */, AArch64::UMLAL2vvv_2d4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2387 /* umlal2 */, AArch64::UMLAL2vvv_4s8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2387 /* umlal2 */, AArch64::UMLAL2vvv_8h16b, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2387 /* umlal2 */, AArch64::UMLALvve_2d4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 2387 /* umlal2 */, AArch64::UMLALvve_4s8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 2394 /* umlsl */, AArch64::UMLSLvvv_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2394 /* umlsl */, AArch64::UMLSLvvv_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2394 /* umlsl */, AArch64::UMLSLvvv_8h8b, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2394 /* umlsl */, AArch64::UMLSLvve_2d2s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 2394 /* umlsl */, AArch64::UMLSLvve_4s4h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 2400 /* umlsl2 */, AArch64::UMLSL2vvv_2d4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2400 /* umlsl2 */, AArch64::UMLSL2vvv_4s8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2400 /* umlsl2 */, AArch64::UMLSL2vvv_8h16b, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2400 /* umlsl2 */, AArch64::UMLSLvve_2d4s, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 2400 /* umlsl2 */, AArch64::UMLSLvve_4s8h, Convert__Reg1_0__Tie0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 2407 /* umnegl */, AArch64::UMSUBLxwwx, Convert__Reg1_0__Reg1_1__Reg1_2__regXZR, 0, { MCK_GPR64, MCK_GPR32, MCK_GPR32 }, },
  { 2414 /* umov */, AArch64::UMOVwb, Convert__Reg1_0__Reg1_1__UImm41_4, Feature_HasNEON, { MCK_GPR32, MCK_FPR128, MCK__DOT_b, MCK__91_, MCK_UImm4, MCK__93_ }, },
  { 2414 /* umov */, AArch64::UMOVwh, Convert__Reg1_0__Reg1_1__UImm31_4, Feature_HasNEON, { MCK_GPR32, MCK_FPR128, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 2414 /* umov */, AArch64::UMOVws, Convert__Reg1_0__Reg1_1__UImm21_4, Feature_HasNEON, { MCK_GPR32, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 2414 /* umov */, AArch64::UMOVxd, Convert__Reg1_0__Reg1_1__UImm11_4, Feature_HasNEON, { MCK_GPR64, MCK_FPR128, MCK__DOT_d, MCK__91_, MCK_UImm1, MCK__93_ }, },
  { 2419 /* umsubl */, AArch64::UMSUBLxwwx, Convert__Reg1_0__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_GPR64, MCK_GPR32, MCK_GPR32, MCK_GPR64 }, },
  { 2426 /* umulh */, AArch64::UMULHxxx, Convert__Reg1_0__Reg1_1__Reg1_2, 0, { MCK_GPR64, MCK_GPR64, MCK_GPR64 }, },
  { 2432 /* umull */, AArch64::UMADDLxwwx, Convert__Reg1_0__Reg1_1__Reg1_2__regXZR, 0, { MCK_GPR64, MCK_GPR32, MCK_GPR32 }, },
  { 2432 /* umull */, AArch64::UMULLvvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2432 /* umull */, AArch64::UMULLvvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2432 /* umull */, AArch64::UMULLvvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2432 /* umull */, AArch64::UMULLve_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 2432 /* umull */, AArch64::UMULLve_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 2438 /* umull2 */, AArch64::UMULL2vvv_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2438 /* umull2 */, AArch64::UMULL2vvv_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2438 /* umull2 */, AArch64::UMULL2vvv_8h16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2438 /* umull2 */, AArch64::UMULLve_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4__UImm21_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_s, MCK__91_, MCK_UImm2, MCK__93_ }, },
  { 2438 /* umull2 */, AArch64::UMULLve_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4__UImm31_7, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128Lo, MCK__DOT_h, MCK__91_, MCK_UImm3, MCK__93_ }, },
  { 2445 /* uqadd */, AArch64::UQADDbbb, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR8, MCK_FPR8 }, },
  { 2445 /* uqadd */, AArch64::UQADDhhh, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR16 }, },
  { 2445 /* uqadd */, AArch64::UQADDsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 2445 /* uqadd */, AArch64::UQADDddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 2445 /* uqadd */, AArch64::UQADDvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2445 /* uqadd */, AArch64::UQADDvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2445 /* uqadd */, AArch64::UQADDvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2445 /* uqadd */, AArch64::UQADDvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2445 /* uqadd */, AArch64::UQADDvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2445 /* uqadd */, AArch64::UQADDvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2445 /* uqadd */, AArch64::UQADDvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2451 /* uqrshl */, AArch64::UQRSHLbbb, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR8, MCK_FPR8 }, },
  { 2451 /* uqrshl */, AArch64::UQRSHLhhh, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR16 }, },
  { 2451 /* uqrshl */, AArch64::UQRSHLsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 2451 /* uqrshl */, AArch64::UQRSHLddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 2451 /* uqrshl */, AArch64::UQRSHLvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2451 /* uqrshl */, AArch64::UQRSHLvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2451 /* uqrshl */, AArch64::UQRSHLvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2451 /* uqrshl */, AArch64::UQRSHLvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2451 /* uqrshl */, AArch64::UQRSHLvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2451 /* uqrshl */, AArch64::UQRSHLvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2451 /* uqrshl */, AArch64::UQRSHLvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2458 /* uqrshrn */, AArch64::UQRSHRNbhi, Convert__Reg1_0__Reg1_1__ShrImm81_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR16, MCK_ShrImm8 }, },
  { 2458 /* uqrshrn */, AArch64::UQRSHRNhsi, Convert__Reg1_0__Reg1_1__ShrImm161_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR32, MCK_ShrImm16 }, },
  { 2458 /* uqrshrn */, AArch64::UQRSHRNsdi, Convert__Reg1_0__Reg1_1__ShrImm321_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR64, MCK_ShrImm32 }, },
  { 2458 /* uqrshrn */, AArch64::UQRSHRNvvi_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 2458 /* uqrshrn */, AArch64::UQRSHRNvvi_4H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 2458 /* uqrshrn */, AArch64::UQRSHRNvvi_8B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 2466 /* uqrshrn2 */, AArch64::UQRSHRNvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 2466 /* uqrshrn2 */, AArch64::UQRSHRNvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 2466 /* uqrshrn2 */, AArch64::UQRSHRNvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 2475 /* uqshl */, AArch64::UQSHLbbb, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR8, MCK_FPR8 }, },
  { 2475 /* uqshl */, AArch64::UQSHLbbi, Convert__Reg1_0__Reg1_1__ShlImm81_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR8, MCK_ShlImm8 }, },
  { 2475 /* uqshl */, AArch64::UQSHLhhh, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR16 }, },
  { 2475 /* uqshl */, AArch64::UQSHLhhi, Convert__Reg1_0__Reg1_1__ShlImm161_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_ShlImm16 }, },
  { 2475 /* uqshl */, AArch64::UQSHLsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 2475 /* uqshl */, AArch64::UQSHLssi, Convert__Reg1_0__Reg1_1__ShlImm321_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_ShlImm32 }, },
  { 2475 /* uqshl */, AArch64::UQSHLddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 2475 /* uqshl */, AArch64::UQSHLddi, Convert__Reg1_0__Reg1_1__ShlImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShlImm64 }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvi_2S, Convert__Reg1_0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShlImm32 }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvi_4H, Convert__Reg1_0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShlImm16 }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvi_8B, Convert__Reg1_0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShlImm8 }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvi_16B, Convert__Reg1_0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShlImm8 }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvi_2D, Convert__Reg1_0__Reg1_2__ShlImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShlImm64 }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvi_4S, Convert__Reg1_0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShlImm32 }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvi_8H, Convert__Reg1_0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShlImm16 }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2475 /* uqshl */, AArch64::UQSHLvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2481 /* uqshrn */, AArch64::UQSHRNbhi, Convert__Reg1_0__Reg1_1__ShrImm81_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR16, MCK_ShrImm8 }, },
  { 2481 /* uqshrn */, AArch64::UQSHRNhsi, Convert__Reg1_0__Reg1_1__ShrImm161_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR32, MCK_ShrImm16 }, },
  { 2481 /* uqshrn */, AArch64::UQSHRNsdi, Convert__Reg1_0__Reg1_1__ShrImm321_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR64, MCK_ShrImm32 }, },
  { 2481 /* uqshrn */, AArch64::UQSHRNvvi_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 2481 /* uqshrn */, AArch64::UQSHRNvvi_4H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 2481 /* uqshrn */, AArch64::UQSHRNvvi_8B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 2488 /* uqshrn2 */, AArch64::UQSHRNvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm8 }, },
  { 2488 /* uqshrn2 */, AArch64::UQSHRNvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm32 }, },
  { 2488 /* uqshrn2 */, AArch64::UQSHRNvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm16 }, },
  { 2496 /* uqsub */, AArch64::UQSUBbbb, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR8, MCK_FPR8, MCK_FPR8 }, },
  { 2496 /* uqsub */, AArch64::UQSUBhhh, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR16, MCK_FPR16, MCK_FPR16 }, },
  { 2496 /* uqsub */, AArch64::UQSUBsss, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR32, MCK_FPR32, MCK_FPR32 }, },
  { 2496 /* uqsub */, AArch64::UQSUBddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 2496 /* uqsub */, AArch64::UQSUBvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2496 /* uqsub */, AArch64::UQSUBvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2496 /* uqsub */, AArch64::UQSUBvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2496 /* uqsub */, AArch64::UQSUBvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2496 /* uqsub */, AArch64::UQSUBvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2496 /* uqsub */, AArch64::UQSUBvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2496 /* uqsub */, AArch64::UQSUBvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2502 /* uqxtn */, AArch64::UQXTNbh, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR16 }, },
  { 2502 /* uqxtn */, AArch64::UQXTNhs, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR32 }, },
  { 2502 /* uqxtn */, AArch64::UQXTNsd, Convert__Reg1_0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR64 }, },
  { 2502 /* uqxtn */, AArch64::UQXTN2d2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d }, },
  { 2502 /* uqxtn */, AArch64::UQXTN4s4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s }, },
  { 2502 /* uqxtn */, AArch64::UQXTN8h8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h }, },
  { 2508 /* uqxtn2 */, AArch64::UQXTN8h16b, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h }, },
  { 2508 /* uqxtn2 */, AArch64::UQXTN2d4s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d }, },
  { 2508 /* uqxtn2 */, AArch64::UQXTN4s8h, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s }, },
  { 2515 /* urecpe */, AArch64::URECPE2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2515 /* urecpe */, AArch64::URECPE4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2522 /* urhadd */, AArch64::URHADDvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2522 /* urhadd */, AArch64::URHADDvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2522 /* urhadd */, AArch64::URHADDvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2522 /* urhadd */, AArch64::URHADDvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2522 /* urhadd */, AArch64::URHADDvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2522 /* urhadd */, AArch64::URHADDvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2529 /* urshl */, AArch64::URSHLddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 2529 /* urshl */, AArch64::URSHLvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2529 /* urshl */, AArch64::URSHLvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2529 /* urshl */, AArch64::URSHLvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2529 /* urshl */, AArch64::URSHLvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2529 /* urshl */, AArch64::URSHLvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2529 /* urshl */, AArch64::URSHLvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2529 /* urshl */, AArch64::URSHLvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2535 /* urshr */, AArch64::URSHRddi, Convert__Reg1_0__Reg1_1__ShrImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShrImm64 }, },
  { 2535 /* urshr */, AArch64::URSHRvvi_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShrImm32 }, },
  { 2535 /* urshr */, AArch64::URSHRvvi_4H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShrImm16 }, },
  { 2535 /* urshr */, AArch64::URSHRvvi_8B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShrImm8 }, },
  { 2535 /* urshr */, AArch64::URSHRvvi_16B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShrImm8 }, },
  { 2535 /* urshr */, AArch64::URSHRvvi_2D, Convert__Reg1_0__Reg1_2__ShrImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm64 }, },
  { 2535 /* urshr */, AArch64::URSHRvvi_4S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm32 }, },
  { 2535 /* urshr */, AArch64::URSHRvvi_8H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm16 }, },
  { 2541 /* ursqrte */, AArch64::URSQRTE2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2541 /* ursqrte */, AArch64::URSQRTE4s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2549 /* ursra */, AArch64::URSRA, Convert__Reg1_0__Tie0__Reg1_1__ShrImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShrImm64 }, },
  { 2549 /* ursra */, AArch64::URSRAvvi_2S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShrImm32 }, },
  { 2549 /* ursra */, AArch64::URSRAvvi_4H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShrImm16 }, },
  { 2549 /* ursra */, AArch64::URSRAvvi_8B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShrImm8 }, },
  { 2549 /* ursra */, AArch64::URSRAvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShrImm8 }, },
  { 2549 /* ursra */, AArch64::URSRAvvi_2D, Convert__Reg1_0__Tie0__Reg1_2__ShrImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm64 }, },
  { 2549 /* ursra */, AArch64::URSRAvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm32 }, },
  { 2549 /* ursra */, AArch64::URSRAvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm16 }, },
  { 2555 /* ushl */, AArch64::USHLddd, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_FPR64 }, },
  { 2555 /* ushl */, AArch64::USHLvvv_2S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2555 /* ushl */, AArch64::USHLvvv_4H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2555 /* ushl */, AArch64::USHLvvv_8B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2555 /* ushl */, AArch64::USHLvvv_16B, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2555 /* ushl */, AArch64::USHLvvv_2D, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2555 /* ushl */, AArch64::USHLvvv_4S, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2555 /* ushl */, AArch64::USHLvvv_8H, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2560 /* ushll */, AArch64::USHLLvvi_2S, Convert__Reg1_0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_ShlImm32 }, },
  { 2560 /* ushll */, AArch64::USHLLvvi_4H, Convert__Reg1_0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_ShlImm16 }, },
  { 2560 /* ushll */, AArch64::USHLLvvi_8B, Convert__Reg1_0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_ShlImm8 }, },
  { 2566 /* ushll2 */, AArch64::USHLLvvi_4S, Convert__Reg1_0__Reg1_2__ShlImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_ShlImm32 }, },
  { 2566 /* ushll2 */, AArch64::USHLLvvi_8H, Convert__Reg1_0__Reg1_2__ShlImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_ShlImm16 }, },
  { 2566 /* ushll2 */, AArch64::USHLLvvi_16B, Convert__Reg1_0__Reg1_2__ShlImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_ShlImm8 }, },
  { 2573 /* ushr */, AArch64::USHRddi, Convert__Reg1_0__Reg1_1__ShrImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShrImm64 }, },
  { 2573 /* ushr */, AArch64::USHRvvi_2S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShrImm32 }, },
  { 2573 /* ushr */, AArch64::USHRvvi_4H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShrImm16 }, },
  { 2573 /* ushr */, AArch64::USHRvvi_8B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShrImm8 }, },
  { 2573 /* ushr */, AArch64::USHRvvi_16B, Convert__Reg1_0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShrImm8 }, },
  { 2573 /* ushr */, AArch64::USHRvvi_2D, Convert__Reg1_0__Reg1_2__ShrImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm64 }, },
  { 2573 /* ushr */, AArch64::USHRvvi_4S, Convert__Reg1_0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm32 }, },
  { 2573 /* ushr */, AArch64::USHRvvi_8H, Convert__Reg1_0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm16 }, },
  { 2578 /* usqadd */, AArch64::USQADDbb, Convert__Reg1_0__Tie0__Reg1_1, Feature_HasNEON, { MCK_FPR8, MCK_FPR8 }, },
  { 2578 /* usqadd */, AArch64::USQADDhh, Convert__Reg1_0__Tie0__Reg1_1, Feature_HasNEON, { MCK_FPR16, MCK_FPR16 }, },
  { 2578 /* usqadd */, AArch64::USQADDss, Convert__Reg1_0__Tie0__Reg1_1, Feature_HasNEON, { MCK_FPR32, MCK_FPR32 }, },
  { 2578 /* usqadd */, AArch64::USQADDdd, Convert__Reg1_0__Tie0__Reg1_1, Feature_HasNEON, { MCK_FPR64, MCK_FPR64 }, },
  { 2578 /* usqadd */, AArch64::USQADD2s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2578 /* usqadd */, AArch64::USQADD4h, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2578 /* usqadd */, AArch64::USQADD8b, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2578 /* usqadd */, AArch64::USQADD16b, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2578 /* usqadd */, AArch64::USQADD2d, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2578 /* usqadd */, AArch64::USQADD4s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2578 /* usqadd */, AArch64::USQADD8h, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2585 /* usra */, AArch64::USRA, Convert__Reg1_0__Tie0__Reg1_1__ShrImm641_2, Feature_HasNEON, { MCK_FPR64, MCK_FPR64, MCK_ShrImm64 }, },
  { 2585 /* usra */, AArch64::USRAvvi_2S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_ShrImm32 }, },
  { 2585 /* usra */, AArch64::USRAvvi_4H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_ShrImm16 }, },
  { 2585 /* usra */, AArch64::USRAvvi_8B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_ShrImm8 }, },
  { 2585 /* usra */, AArch64::USRAvvi_16B, Convert__Reg1_0__Tie0__Reg1_2__ShrImm81_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_ShrImm8 }, },
  { 2585 /* usra */, AArch64::USRAvvi_2D, Convert__Reg1_0__Tie0__Reg1_2__ShrImm641_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_ShrImm64 }, },
  { 2585 /* usra */, AArch64::USRAvvi_4S, Convert__Reg1_0__Tie0__Reg1_2__ShrImm321_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_ShrImm32 }, },
  { 2585 /* usra */, AArch64::USRAvvi_8H, Convert__Reg1_0__Tie0__Reg1_2__ShrImm161_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_ShrImm16 }, },
  { 2590 /* usubl */, AArch64::USUBLvvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2590 /* usubl */, AArch64::USUBLvvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2590 /* usubl */, AArch64::USUBLvvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2596 /* usubl2 */, AArch64::USUBL2vvv_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2596 /* usubl2 */, AArch64::USUBL2vvv_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2596 /* usubl2 */, AArch64::USUBL2vvv_8h16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2603 /* usubw */, AArch64::USUBWvvv_2d2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR64, MCK__DOT_2s }, },
  { 2603 /* usubw */, AArch64::USUBWvvv_4s4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR64, MCK__DOT_4h }, },
  { 2603 /* usubw */, AArch64::USUBWvvv_8h8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR64, MCK__DOT_8b }, },
  { 2609 /* usubw2 */, AArch64::USUBW2vvv_2d4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_4s }, },
  { 2609 /* usubw2 */, AArch64::USUBW2vvv_4s8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_8h }, },
  { 2609 /* usubw2 */, AArch64::USUBW2vvv_8h16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_16b }, },
  { 2616 /* uxtb */, AArch64::UXTBww, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 2616 /* uxtb */, AArch64::UXTBxw, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR64, MCK_GPR32 }, },
  { 2621 /* uxth */, AArch64::UXTHww, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR32, MCK_GPR32 }, },
  { 2621 /* uxth */, AArch64::UXTHxw, Convert__Reg1_0__Reg1_1, 0, { MCK_GPR64, MCK_GPR32 }, },
  { 2626 /* uzp1 */, AArch64::UZP1vvv_2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2626 /* uzp1 */, AArch64::UZP1vvv_4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2626 /* uzp1 */, AArch64::UZP1vvv_8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2626 /* uzp1 */, AArch64::UZP1vvv_16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2626 /* uzp1 */, AArch64::UZP1vvv_2d, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2626 /* uzp1 */, AArch64::UZP1vvv_4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2626 /* uzp1 */, AArch64::UZP1vvv_8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2631 /* uzp2 */, AArch64::UZP2vvv_2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2631 /* uzp2 */, AArch64::UZP2vvv_4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2631 /* uzp2 */, AArch64::UZP2vvv_8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2631 /* uzp2 */, AArch64::UZP2vvv_16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2631 /* uzp2 */, AArch64::UZP2vvv_2d, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2631 /* uzp2 */, AArch64::UZP2vvv_4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2631 /* uzp2 */, AArch64::UZP2vvv_8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2636 /* wfe */, AArch64::HINTi, Convert__imm_2, 0, {  }, },
  { 2640 /* wfi */, AArch64::HINTi, Convert__imm_3, 0, {  }, },
  { 2644 /* xtn */, AArch64::XTN2d2s, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR128, MCK__DOT_2d }, },
  { 2644 /* xtn */, AArch64::XTN4s4h, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR128, MCK__DOT_4s }, },
  { 2644 /* xtn */, AArch64::XTN8h8b, Convert__Reg1_0__Reg1_2, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR128, MCK__DOT_8h }, },
  { 2648 /* xtn2 */, AArch64::XTN8h16b, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_8h }, },
  { 2648 /* xtn2 */, AArch64::XTN2d4s, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_2d }, },
  { 2648 /* xtn2 */, AArch64::XTN4s8h, Convert__Reg1_0__Tie0__Reg1_2, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_4s }, },
  { 2653 /* yield */, AArch64::HINTi, Convert__imm_1, 0, {  }, },
  { 2659 /* zip1 */, AArch64::ZIP1vvv_2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2659 /* zip1 */, AArch64::ZIP1vvv_4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2659 /* zip1 */, AArch64::ZIP1vvv_8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2659 /* zip1 */, AArch64::ZIP1vvv_16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2659 /* zip1 */, AArch64::ZIP1vvv_2d, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2659 /* zip1 */, AArch64::ZIP1vvv_4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2659 /* zip1 */, AArch64::ZIP1vvv_8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
  { 2664 /* zip2 */, AArch64::ZIP2vvv_2s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s, MCK_FPR64, MCK__DOT_2s }, },
  { 2664 /* zip2 */, AArch64::ZIP2vvv_4h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h, MCK_FPR64, MCK__DOT_4h }, },
  { 2664 /* zip2 */, AArch64::ZIP2vvv_8b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b, MCK_FPR64, MCK__DOT_8b }, },
  { 2664 /* zip2 */, AArch64::ZIP2vvv_16b, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b, MCK_FPR128, MCK__DOT_16b }, },
  { 2664 /* zip2 */, AArch64::ZIP2vvv_2d, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d, MCK_FPR128, MCK__DOT_2d }, },
  { 2664 /* zip2 */, AArch64::ZIP2vvv_4s, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s, MCK_FPR128, MCK__DOT_4s }, },
  { 2664 /* zip2 */, AArch64::ZIP2vvv_8h, Convert__Reg1_0__Reg1_2__Reg1_4, Feature_HasNEON, { MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h, MCK_FPR128, MCK__DOT_8h }, },
};

bool AArch64AsmParser::
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

unsigned AArch64AsmParser::
MatchInstructionImpl(const SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                     MCInst &Inst,
unsigned &ErrorInfo, bool matchingInlineAsm, unsigned VariantID) {
  // Eliminate obvious mismatches.
  if (Operands.size() > 11) {
    ErrorInfo = 11;
    return Match_InvalidOperand;
  }

  // Get the current feature set.
  unsigned AvailableFeatures = getAvailableFeatures();

  // Get the instruction mnemonic, which is the first token.
  StringRef Mnemonic = ((AArch64Operand*)Operands[0])->getToken();

  // Process all MnemonicAliases to remap the mnemonic.
  applyMnemonicAliases(Mnemonic, AvailableFeatures, VariantID);

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
    for (unsigned i = 0; i != 10; ++i) {
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

static const OperandMatchEntry OperandMatchTable[677] = {
  /* Operand List Mask, Mnemonic, Operand Class, Features */
  { 0, 13 /* add */, MCK_AddSubImmLSL0, 4 /* 2 */ },
  { 0, 13 /* add */, MCK_AddSubImmLSL12, 4 /* 2 */ },
  { 0, 13 /* add */, MCK_AddSubImmLSL0, 4 /* 2 */ },
  { 0, 13 /* add */, MCK_AddSubImmLSL12, 4 /* 2 */ },
  { 0, 35 /* adds */, MCK_AddSubImmLSL0, 4 /* 2 */ },
  { 0, 35 /* adds */, MCK_AddSubImmLSL12, 4 /* 2 */ },
  { 0, 35 /* adds */, MCK_AddSubImmLSL0, 4 /* 2 */ },
  { 0, 35 /* adds */, MCK_AddSubImmLSL12, 4 /* 2 */ },
  { 0, 90 /* at */, MCK_NamedImmat, 1 /* 0 */ },
  { 0, 153 /* ccmn */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 153 /* ccmn */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 153 /* ccmn */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 153 /* ccmn */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 158 /* ccmp */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 158 /* ccmp */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 158 /* ccmp */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 158 /* ccmp */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 163 /* cinc */, MCK_InvCondCodeOp, 4 /* 2 */ },
  { 0, 163 /* cinc */, MCK_InvCondCodeOp, 4 /* 2 */ },
  { 0, 168 /* cinv */, MCK_InvCondCodeOp, 4 /* 2 */ },
  { 0, 168 /* cinv */, MCK_InvCondCodeOp, 4 /* 2 */ },
  { 0, 232 /* cmn */, MCK_AddSubImmLSL0, 2 /* 1 */ },
  { 0, 232 /* cmn */, MCK_AddSubImmLSL12, 2 /* 1 */ },
  { 0, 232 /* cmn */, MCK_AddSubImmLSL0, 2 /* 1 */ },
  { 0, 232 /* cmn */, MCK_AddSubImmLSL12, 2 /* 1 */ },
  { 0, 236 /* cmp */, MCK_AddSubImmLSL0, 2 /* 1 */ },
  { 0, 236 /* cmp */, MCK_AddSubImmLSL12, 2 /* 1 */ },
  { 0, 236 /* cmp */, MCK_AddSubImmLSL0, 2 /* 1 */ },
  { 0, 236 /* cmp */, MCK_AddSubImmLSL12, 2 /* 1 */ },
  { 0, 246 /* cneg */, MCK_InvCondCodeOp, 4 /* 2 */ },
  { 0, 246 /* cneg */, MCK_InvCondCodeOp, 4 /* 2 */ },
  { 0, 315 /* csel */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 315 /* csel */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 320 /* cset */, MCK_InvCondCodeOp, 2 /* 1 */ },
  { 0, 320 /* cset */, MCK_InvCondCodeOp, 2 /* 1 */ },
  { 0, 325 /* csetm */, MCK_InvCondCodeOp, 2 /* 1 */ },
  { 0, 325 /* csetm */, MCK_InvCondCodeOp, 2 /* 1 */ },
  { 0, 331 /* csinc */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 331 /* csinc */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 337 /* csinv */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 337 /* csinv */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 343 /* csneg */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 343 /* csneg */, MCK_CondCodeOp, 8 /* 3 */ },
  { 0, 349 /* dc */, MCK_NamedImmdc, 1 /* 0 */ },
  { 0, 370 /* dmb */, MCK_NamedImmdbarrier, 1 /* 0 */ },
  { 0, 379 /* dsb */, MCK_NamedImmdbarrier, 1 /* 0 */ },
  { Feature_HasFPARMv8, 454 /* fccmp */, MCK_CondCodeOp, 8 /* 3 */ },
  { Feature_HasFPARMv8, 454 /* fccmp */, MCK_CondCodeOp, 8 /* 3 */ },
  { Feature_HasFPARMv8, 460 /* fccmpe */, MCK_CondCodeOp, 8 /* 3 */ },
  { Feature_HasFPARMv8, 460 /* fccmpe */, MCK_CondCodeOp, 8 /* 3 */ },
  { Feature_HasNEON, 467 /* fcmeq */, MCK_FPZero, 4 /* 2 */ },
  { Feature_HasNEON, 467 /* fcmeq */, MCK_FPZero, 4 /* 2 */ },
  { Feature_HasNEON, 467 /* fcmeq */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 467 /* fcmeq */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 467 /* fcmeq */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 473 /* fcmge */, MCK_FPZero, 4 /* 2 */ },
  { Feature_HasNEON, 473 /* fcmge */, MCK_FPZero, 4 /* 2 */ },
  { Feature_HasNEON, 473 /* fcmge */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 473 /* fcmge */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 473 /* fcmge */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 479 /* fcmgt */, MCK_FPZero, 4 /* 2 */ },
  { Feature_HasNEON, 479 /* fcmgt */, MCK_FPZero, 4 /* 2 */ },
  { Feature_HasNEON, 479 /* fcmgt */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 479 /* fcmgt */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 479 /* fcmgt */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 485 /* fcmle */, MCK_FPZero, 4 /* 2 */ },
  { Feature_HasNEON, 485 /* fcmle */, MCK_FPZero, 4 /* 2 */ },
  { Feature_HasNEON, 485 /* fcmle */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 485 /* fcmle */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 485 /* fcmle */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 491 /* fcmlt */, MCK_FPZero, 4 /* 2 */ },
  { Feature_HasNEON, 491 /* fcmlt */, MCK_FPZero, 4 /* 2 */ },
  { Feature_HasNEON, 491 /* fcmlt */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 491 /* fcmlt */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasNEON, 491 /* fcmlt */, MCK_FPZero, 16 /* 4 */ },
  { Feature_HasFPARMv8, 497 /* fcmp */, MCK_FPZero, 2 /* 1 */ },
  { Feature_HasFPARMv8, 497 /* fcmp */, MCK_FPZero, 2 /* 1 */ },
  { Feature_HasFPARMv8, 502 /* fcmpe */, MCK_FPZero, 2 /* 1 */ },
  { Feature_HasFPARMv8, 502 /* fcmpe */, MCK_FPZero, 2 /* 1 */ },
  { Feature_HasFPARMv8, 508 /* fcsel */, MCK_CondCodeOp, 8 /* 3 */ },
  { Feature_HasFPARMv8, 508 /* fcsel */, MCK_CondCodeOp, 8 /* 3 */ },
  { Feature_HasFPARMv8, 731 /* fmov */, MCK_FMOVImm, 2 /* 1 */ },
  { Feature_HasFPARMv8, 731 /* fmov */, MCK_FMOVImm, 2 /* 1 */ },
  { Feature_HasNEON, 731 /* fmov */, MCK_FMOVImm, 4 /* 2 */ },
  { Feature_HasNEON, 731 /* fmov */, MCK_FMOVImm, 4 /* 2 */ },
  { Feature_HasNEON, 731 /* fmov */, MCK_FMOVImm, 4 /* 2 */ },
  { 0, 888 /* ic */, MCK_NamedImmic, 1 /* 0 */ },
  { 0, 888 /* ic */, MCK_NamedImmic, 1 /* 0 */ },
  { 0, 895 /* isb */, MCK_NamedImmisb, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne16B1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne1D1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne2D1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne2S1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne4H1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne4S1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne8B1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne8H1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair1D2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad1D4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple1D3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne16B1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne16B1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne1D1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne1D1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne2D1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne2D1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne2S1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne2S1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne4H1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne4H1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne4S1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne4S1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne8B1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne8B1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne8H1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOne8H1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair1D2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair1D2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad1D4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad1D4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple1D3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple1D3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOneB1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOneD1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOneH1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOneS1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOneB1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOneB1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOneD1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOneD1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOneH1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOneH1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOneS1, 1 /* 0 */ },
  { Feature_HasNEON, 899 /* ld1 */, MCK_VOneS1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne16B1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne1D1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne2D1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne2S1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne4H1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne4S1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne8B1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne8H1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne16B1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne16B1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne1D1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne1D1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne2D1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne2D1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne2S1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne2S1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne4H1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne4H1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne4S1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne4S1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne8B1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne8B1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne8H1, 1 /* 0 */ },
  { Feature_HasNEON, 903 /* ld1r */, MCK_VOne8H1, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPairB2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPairD2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPairH2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPairS2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPairB2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPairB2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPairD2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPairD2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPairH2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPairH2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPairS2, 1 /* 0 */ },
  { Feature_HasNEON, 908 /* ld2 */, MCK_VPairS2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair1D2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair1D2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair1D2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 912 /* ld2r */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTripleB3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTripleD3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTripleH3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTripleS3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTripleB3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTripleB3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTripleD3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTripleD3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTripleH3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTripleH3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTripleS3, 1 /* 0 */ },
  { Feature_HasNEON, 917 /* ld3 */, MCK_VTripleS3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple1D3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple1D3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple1D3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 921 /* ld3r */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuadB4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuadD4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuadH4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuadS4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuadB4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuadB4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuadD4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuadD4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuadH4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuadH4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuadS4, 1 /* 0 */ },
  { Feature_HasNEON, 926 /* ld4 */, MCK_VQuadS4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad1D4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad1D4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad1D4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 930 /* ld4r */, MCK_VQuad8H4, 1 /* 0 */ },
  { 0, 935 /* ldar */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 935 /* ldar */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 940 /* ldarb */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 946 /* ldarh */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 952 /* ldaxp */, MCK_GPR64xsp0, 8 /* 3 */ },
  { 0, 952 /* ldaxp */, MCK_GPR64xsp0, 8 /* 3 */ },
  { 0, 958 /* ldaxr */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 958 /* ldaxr */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 964 /* ldaxrb */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 971 /* ldaxrh */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 1101 /* ldxp */, MCK_GPR64xsp0, 8 /* 3 */ },
  { 0, 1101 /* ldxp */, MCK_GPR64xsp0, 8 /* 3 */ },
  { 0, 1106 /* ldxr */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 1106 /* ldxr */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 1111 /* ldxrb */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 1117 /* ldxrh */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 1158 /* movk */, MCK_MOVK32Shiftedshift, 2 /* 1 */ },
  { 0, 1158 /* movk */, MCK_MOVK64Shiftedshift, 2 /* 1 */ },
  { 0, 1163 /* movn */, MCK_MOVN32Shiftedshift, 2 /* 1 */ },
  { 0, 1163 /* movn */, MCK_MOVN64Shiftedshift, 2 /* 1 */ },
  { 0, 1168 /* movz */, MCK_MOVZ32Shiftedshift, 2 /* 1 */ },
  { 0, 1168 /* movz */, MCK_MOVZ64Shiftedshift, 2 /* 1 */ },
  { 0, 1173 /* mrs */, MCK_MRS, 2 /* 1 */ },
  { 0, 1177 /* msr */, MCK_MSRWithReg, 1 /* 0 */ },
  { 0, 1177 /* msr */, MCK_MSRPState, 1 /* 0 */ },
  { 0, 1251 /* prfm */, MCK_NamedImmprefetch, 1 /* 0 */ },
  { 0, 1251 /* prfm */, MCK_NamedImmprefetch, 1 /* 0 */ },
  { 0, 1251 /* prfm */, MCK_NamedImmprefetch, 1 /* 0 */ },
  { 0, 1251 /* prfm */, MCK_NamedImmprefetch, 1 /* 0 */ },
  { 0, 1251 /* prfm */, MCK_NamedImmprefetch, 1 /* 0 */ },
  { 0, 1251 /* prfm */, MCK_NamedImmprefetch, 1 /* 0 */ },
  { 0, 1256 /* prfum */, MCK_NamedImmprefetch, 1 /* 0 */ },
  { 0, 1256 /* prfum */, MCK_NamedImmprefetch, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne16B1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne1D1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne2D1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne2S1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne4H1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne4S1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne8B1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne8H1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair1D2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad1D4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple1D3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne16B1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne16B1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne1D1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne1D1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne2D1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne2D1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne2S1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne2S1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne4H1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne4H1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne4S1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne4S1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne8B1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne8B1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne8H1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOne8H1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair1D2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair1D2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad1D4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad1D4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple1D3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple1D3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOneB1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOneD1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOneH1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOneS1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOneB1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOneB1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOneD1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOneD1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOneH1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOneH1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOneS1, 1 /* 0 */ },
  { Feature_HasNEON, 1987 /* st1 */, MCK_VOneS1, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair16B2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair2D2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair2S2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair4H2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair4S2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair8B2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPair8H2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPairB2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPairD2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPairH2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPairS2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPairB2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPairB2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPairD2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPairD2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPairH2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPairH2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPairS2, 1 /* 0 */ },
  { Feature_HasNEON, 1991 /* st2 */, MCK_VPairS2, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple16B3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple2D3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple2S3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple4H3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple4S3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple8B3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTriple8H3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTripleB3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTripleD3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTripleH3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTripleS3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTripleB3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTripleB3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTripleD3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTripleD3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTripleH3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTripleH3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTripleS3, 1 /* 0 */ },
  { Feature_HasNEON, 1995 /* st3 */, MCK_VTripleS3, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad16B4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad2D4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad2S4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad4H4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad4S4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad8B4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuad8H4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuadB4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuadD4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuadH4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuadS4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuadB4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuadB4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuadD4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuadD4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuadH4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuadH4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuadS4, 1 /* 0 */ },
  { Feature_HasNEON, 1999 /* st4 */, MCK_VQuadS4, 1 /* 0 */ },
  { 0, 2003 /* stlr */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 2003 /* stlr */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 2008 /* stlrb */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 2014 /* stlrh */, MCK_GPR64xsp0, 4 /* 2 */ },
  { 0, 2020 /* stlxp */, MCK_GPR64xsp0, 16 /* 4 */ },
  { 0, 2020 /* stlxp */, MCK_GPR64xsp0, 16 /* 4 */ },
  { 0, 2026 /* stlxr */, MCK_GPR64xsp0, 8 /* 3 */ },
  { 0, 2026 /* stlxr */, MCK_GPR64xsp0, 8 /* 3 */ },
  { 0, 2032 /* stlxrb */, MCK_GPR64xsp0, 8 /* 3 */ },
  { 0, 2039 /* stlxrh */, MCK_GPR64xsp0, 8 /* 3 */ },
  { 0, 2103 /* stxp */, MCK_GPR64xsp0, 16 /* 4 */ },
  { 0, 2103 /* stxp */, MCK_GPR64xsp0, 16 /* 4 */ },
  { 0, 2108 /* stxr */, MCK_GPR64xsp0, 8 /* 3 */ },
  { 0, 2108 /* stxr */, MCK_GPR64xsp0, 8 /* 3 */ },
  { 0, 2113 /* stxrb */, MCK_GPR64xsp0, 8 /* 3 */ },
  { 0, 2119 /* stxrh */, MCK_GPR64xsp0, 8 /* 3 */ },
  { 0, 2125 /* sub */, MCK_AddSubImmLSL0, 4 /* 2 */ },
  { 0, 2125 /* sub */, MCK_AddSubImmLSL12, 4 /* 2 */ },
  { 0, 2125 /* sub */, MCK_AddSubImmLSL0, 4 /* 2 */ },
  { 0, 2125 /* sub */, MCK_AddSubImmLSL12, 4 /* 2 */ },
  { 0, 2142 /* subs */, MCK_AddSubImmLSL0, 4 /* 2 */ },
  { 0, 2142 /* subs */, MCK_AddSubImmLSL12, 4 /* 2 */ },
  { 0, 2142 /* subs */, MCK_AddSubImmLSL0, 4 /* 2 */ },
  { 0, 2142 /* subs */, MCK_AddSubImmLSL12, 4 /* 2 */ },
  { 0, 2173 /* sys */, MCK_CRx, 6 /* 1, 2 */ },
  { 0, 2173 /* sys */, MCK_CRx, 6 /* 1, 2 */ },
  { 0, 2177 /* sysl */, MCK_CRx, 12 /* 2, 3 */ },
  { Feature_HasNEON, 2182 /* tbl */, MCK_VOne16B1, 4 /* 2 */ },
  { Feature_HasNEON, 2182 /* tbl */, MCK_VPair16B2, 4 /* 2 */ },
  { Feature_HasNEON, 2182 /* tbl */, MCK_VQuad16B4, 4 /* 2 */ },
  { Feature_HasNEON, 2182 /* tbl */, MCK_VTriple16B3, 4 /* 2 */ },
  { Feature_HasNEON, 2182 /* tbl */, MCK_VOne16B1, 4 /* 2 */ },
  { Feature_HasNEON, 2182 /* tbl */, MCK_VPair16B2, 4 /* 2 */ },
  { Feature_HasNEON, 2182 /* tbl */, MCK_VQuad16B4, 4 /* 2 */ },
  { Feature_HasNEON, 2182 /* tbl */, MCK_VTriple16B3, 4 /* 2 */ },
  { Feature_HasNEON, 2191 /* tbx */, MCK_VOne16B1, 4 /* 2 */ },
  { Feature_HasNEON, 2191 /* tbx */, MCK_VPair16B2, 4 /* 2 */ },
  { Feature_HasNEON, 2191 /* tbx */, MCK_VQuad16B4, 4 /* 2 */ },
  { Feature_HasNEON, 2191 /* tbx */, MCK_VTriple16B3, 4 /* 2 */ },
  { Feature_HasNEON, 2191 /* tbx */, MCK_VOne16B1, 4 /* 2 */ },
  { Feature_HasNEON, 2191 /* tbx */, MCK_VPair16B2, 4 /* 2 */ },
  { Feature_HasNEON, 2191 /* tbx */, MCK_VQuad16B4, 4 /* 2 */ },
  { Feature_HasNEON, 2191 /* tbx */, MCK_VTriple16B3, 4 /* 2 */ },
  { 0, 2199 /* tlbi */, MCK_NamedImmtlbi, 1 /* 0 */ },
  { 0, 2199 /* tlbi */, MCK_NamedImmtlbi, 1 /* 0 */ },
};

AArch64AsmParser::OperandMatchResultTy AArch64AsmParser::
tryCustomParseOperand(SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                      unsigned MCK) {

  switch(MCK) {
  case MCK_CRx:
    return ParseCRxOperand(Operands);
  case MCK_GPR64xsp0:
    return ParseLSXAddressOperand(Operands);
  case MCK_VOne16B1:
    return ParseVectorList(Operands);
  case MCK_VOne1D1:
    return ParseVectorList(Operands);
  case MCK_VOne2D1:
    return ParseVectorList(Operands);
  case MCK_VOne2S1:
    return ParseVectorList(Operands);
  case MCK_VOne4H1:
    return ParseVectorList(Operands);
  case MCK_VOne4S1:
    return ParseVectorList(Operands);
  case MCK_VOne8B1:
    return ParseVectorList(Operands);
  case MCK_VOne8H1:
    return ParseVectorList(Operands);
  case MCK_VOneB1:
    return ParseVectorList(Operands);
  case MCK_VOneD1:
    return ParseVectorList(Operands);
  case MCK_VOneH1:
    return ParseVectorList(Operands);
  case MCK_VOneS1:
    return ParseVectorList(Operands);
  case MCK_VPair16B2:
    return ParseVectorList(Operands);
  case MCK_VPair1D2:
    return ParseVectorList(Operands);
  case MCK_VPair2D2:
    return ParseVectorList(Operands);
  case MCK_VPair2S2:
    return ParseVectorList(Operands);
  case MCK_VPair4H2:
    return ParseVectorList(Operands);
  case MCK_VPair4S2:
    return ParseVectorList(Operands);
  case MCK_VPair8B2:
    return ParseVectorList(Operands);
  case MCK_VPair8H2:
    return ParseVectorList(Operands);
  case MCK_VPairB2:
    return ParseVectorList(Operands);
  case MCK_VPairD2:
    return ParseVectorList(Operands);
  case MCK_VPairH2:
    return ParseVectorList(Operands);
  case MCK_VPairS2:
    return ParseVectorList(Operands);
  case MCK_VQuad16B4:
    return ParseVectorList(Operands);
  case MCK_VQuad1D4:
    return ParseVectorList(Operands);
  case MCK_VQuad2D4:
    return ParseVectorList(Operands);
  case MCK_VQuad2S4:
    return ParseVectorList(Operands);
  case MCK_VQuad4H4:
    return ParseVectorList(Operands);
  case MCK_VQuad4S4:
    return ParseVectorList(Operands);
  case MCK_VQuad8B4:
    return ParseVectorList(Operands);
  case MCK_VQuad8H4:
    return ParseVectorList(Operands);
  case MCK_VQuadB4:
    return ParseVectorList(Operands);
  case MCK_VQuadD4:
    return ParseVectorList(Operands);
  case MCK_VQuadH4:
    return ParseVectorList(Operands);
  case MCK_VQuadS4:
    return ParseVectorList(Operands);
  case MCK_VTriple16B3:
    return ParseVectorList(Operands);
  case MCK_VTriple1D3:
    return ParseVectorList(Operands);
  case MCK_VTriple2D3:
    return ParseVectorList(Operands);
  case MCK_VTriple2S3:
    return ParseVectorList(Operands);
  case MCK_VTriple4H3:
    return ParseVectorList(Operands);
  case MCK_VTriple4S3:
    return ParseVectorList(Operands);
  case MCK_VTriple8B3:
    return ParseVectorList(Operands);
  case MCK_VTriple8H3:
    return ParseVectorList(Operands);
  case MCK_VTripleB3:
    return ParseVectorList(Operands);
  case MCK_VTripleD3:
    return ParseVectorList(Operands);
  case MCK_VTripleH3:
    return ParseVectorList(Operands);
  case MCK_VTripleS3:
    return ParseVectorList(Operands);
  case MCK_AddSubImmLSL0:
    return ParseImmWithLSLOperand(Operands);
  case MCK_AddSubImmLSL12:
    return ParseImmWithLSLOperand(Operands);
  case MCK_NamedImmat:
    return ParseNamedImmOperand<A64AT::ATMapper>(Operands);
  case MCK_CondCodeOp:
    return ParseCondCodeOperand(Operands);
  case MCK_NamedImmdbarrier:
    return ParseNamedImmOperand<A64DB::DBarrierMapper>(Operands);
  case MCK_NamedImmdc:
    return ParseNamedImmOperand<A64DC::DCMapper>(Operands);
  case MCK_FMOVImm:
    return ParseFPImmOperand(Operands);
  case MCK_FPZero:
    return ParseFPImmOperand(Operands);
  case MCK_NamedImmic:
    return ParseNamedImmOperand<A64IC::ICMapper>(Operands);
  case MCK_InvCondCodeOp:
    return ParseCondCodeOperand(Operands);
  case MCK_NamedImmisb:
    return ParseNamedImmOperand<A64ISB::ISBMapper>(Operands);
  case MCK_MOVK32Shiftedshift:
    return ParseImmWithLSLOperand(Operands);
  case MCK_MOVK64Shiftedshift:
    return ParseImmWithLSLOperand(Operands);
  case MCK_MOVN32Shiftedshift:
    return ParseImmWithLSLOperand(Operands);
  case MCK_MOVN64Shiftedshift:
    return ParseImmWithLSLOperand(Operands);
  case MCK_MOVZ32Shiftedshift:
    return ParseImmWithLSLOperand(Operands);
  case MCK_MOVZ64Shiftedshift:
    return ParseImmWithLSLOperand(Operands);
  case MCK_MRS:
    return ParseSysRegOperand(Operands);
  case MCK_MSRWithReg:
    return ParseSysRegOperand(Operands);
  case MCK_NamedImmprefetch:
    return ParseNamedImmOperand<A64PRFM::PRFMMapper>(Operands);
  case MCK_MSRPState:
    return ParseSysRegOperand(Operands);
  case MCK_NamedImmtlbi:
    return ParseNamedImmOperand<A64TLBI::TLBIMapper>(Operands);
  default:
    return MatchOperand_NoMatch;
  }
  return MatchOperand_NoMatch;
}

AArch64AsmParser::OperandMatchResultTy AArch64AsmParser::
MatchOperandParserImpl(SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                       StringRef Mnemonic) {
  // Get the current feature set.
  unsigned AvailableFeatures = getAvailableFeatures();

  // Get the next operand index.
  unsigned NextOpNum = Operands.size()-1;
  // Search the table.
  std::pair<const OperandMatchEntry*, const OperandMatchEntry*> MnemonicRange =
    std::equal_range(OperandMatchTable, OperandMatchTable+677, Mnemonic,
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


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

  Match_ImmRange0_15,
  Match_ImmRange0_239,
  END_OPERAND_DIAGNOSTIC_TYPES
#endif // GET_OPERAND_DIAGNOSTIC_TYPES


#ifdef GET_REGISTER_MATCHER
#undef GET_REGISTER_MATCHER

// Flags for subtarget features that participate in instruction matching.
enum SubtargetFeatureFlag {
  Feature_HasV4T = (1 << 13),
  Feature_HasV5TE = (1 << 14),
  Feature_HasV6 = (1 << 15),
  Feature_HasV6M = (1 << 16),
  Feature_HasV6T2 = (1 << 17),
  Feature_HasV7 = (1 << 18),
  Feature_HasV8 = (1 << 19),
  Feature_PreV8 = (1 << 28),
  Feature_HasVFP2 = (1 << 20),
  Feature_HasVFP3 = (1 << 21),
  Feature_HasVFP4 = (1 << 22),
  Feature_HasDPVFP = (1 << 3),
  Feature_HasFPARMv8 = (1 << 7),
  Feature_HasNEON = (1 << 9),
  Feature_HasCrypto = (1 << 1),
  Feature_HasCRC = (1 << 0),
  Feature_HasFP16 = (1 << 6),
  Feature_HasDivide = (1 << 4),
  Feature_HasDivideInARM = (1 << 5),
  Feature_HasT2ExtractPack = (1 << 10),
  Feature_HasThumb2DSP = (1 << 11),
  Feature_HasDB = (1 << 2),
  Feature_HasMP = (1 << 8),
  Feature_HasTrustZone = (1 << 12),
  Feature_IsThumb = (1 << 26),
  Feature_IsThumb2 = (1 << 27),
  Feature_IsMClass = (1 << 24),
  Feature_IsNotMClass = (1 << 25),
  Feature_IsARM = (1 << 23),
  Feature_UseNaClTrap = (1 << 29),
  Feature_None = 0
};

static unsigned MatchRegisterName(StringRef Name) {
  switch (Name.size()) {
  default: break;
  case 2:	 // 43 strings to match.
    switch (Name[0]) {
    default: break;
    case 'd':	 // 10 strings to match.
      switch (Name[1]) {
      default: break;
      case '0':	 // 1 string to match.
        return 14;	 // "d0"
      case '1':	 // 1 string to match.
        return 15;	 // "d1"
      case '2':	 // 1 string to match.
        return 16;	 // "d2"
      case '3':	 // 1 string to match.
        return 17;	 // "d3"
      case '4':	 // 1 string to match.
        return 18;	 // "d4"
      case '5':	 // 1 string to match.
        return 19;	 // "d5"
      case '6':	 // 1 string to match.
        return 20;	 // "d6"
      case '7':	 // 1 string to match.
        return 21;	 // "d7"
      case '8':	 // 1 string to match.
        return 22;	 // "d8"
      case '9':	 // 1 string to match.
        return 23;	 // "d9"
      }
      break;
    case 'l':	 // 1 string to match.
      if (Name[1] != 'r')
        break;
      return 10;	 // "lr"
    case 'p':	 // 1 string to match.
      if (Name[1] != 'c')
        break;
      return 11;	 // "pc"
    case 'q':	 // 10 strings to match.
      switch (Name[1]) {
      default: break;
      case '0':	 // 1 string to match.
        return 50;	 // "q0"
      case '1':	 // 1 string to match.
        return 51;	 // "q1"
      case '2':	 // 1 string to match.
        return 52;	 // "q2"
      case '3':	 // 1 string to match.
        return 53;	 // "q3"
      case '4':	 // 1 string to match.
        return 54;	 // "q4"
      case '5':	 // 1 string to match.
        return 55;	 // "q5"
      case '6':	 // 1 string to match.
        return 56;	 // "q6"
      case '7':	 // 1 string to match.
        return 57;	 // "q7"
      case '8':	 // 1 string to match.
        return 58;	 // "q8"
      case '9':	 // 1 string to match.
        return 59;	 // "q9"
      }
      break;
    case 'r':	 // 10 strings to match.
      switch (Name[1]) {
      default: break;
      case '0':	 // 1 string to match.
        return 66;	 // "r0"
      case '1':	 // 1 string to match.
        return 67;	 // "r1"
      case '2':	 // 1 string to match.
        return 68;	 // "r2"
      case '3':	 // 1 string to match.
        return 69;	 // "r3"
      case '4':	 // 1 string to match.
        return 70;	 // "r4"
      case '5':	 // 1 string to match.
        return 71;	 // "r5"
      case '6':	 // 1 string to match.
        return 72;	 // "r6"
      case '7':	 // 1 string to match.
        return 73;	 // "r7"
      case '8':	 // 1 string to match.
        return 74;	 // "r8"
      case '9':	 // 1 string to match.
        return 75;	 // "r9"
      }
      break;
    case 's':	 // 11 strings to match.
      switch (Name[1]) {
      default: break;
      case '0':	 // 1 string to match.
        return 79;	 // "s0"
      case '1':	 // 1 string to match.
        return 80;	 // "s1"
      case '2':	 // 1 string to match.
        return 81;	 // "s2"
      case '3':	 // 1 string to match.
        return 82;	 // "s3"
      case '4':	 // 1 string to match.
        return 83;	 // "s4"
      case '5':	 // 1 string to match.
        return 84;	 // "s5"
      case '6':	 // 1 string to match.
        return 85;	 // "s6"
      case '7':	 // 1 string to match.
        return 86;	 // "s7"
      case '8':	 // 1 string to match.
        return 87;	 // "s8"
      case '9':	 // 1 string to match.
        return 88;	 // "s9"
      case 'p':	 // 1 string to match.
        return 12;	 // "sp"
      }
      break;
    }
    break;
  case 3:	 // 53 strings to match.
    switch (Name[0]) {
    default: break;
    case 'd':	 // 22 strings to match.
      switch (Name[1]) {
      default: break;
      case '1':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 24;	 // "d10"
        case '1':	 // 1 string to match.
          return 25;	 // "d11"
        case '2':	 // 1 string to match.
          return 26;	 // "d12"
        case '3':	 // 1 string to match.
          return 27;	 // "d13"
        case '4':	 // 1 string to match.
          return 28;	 // "d14"
        case '5':	 // 1 string to match.
          return 29;	 // "d15"
        case '6':	 // 1 string to match.
          return 30;	 // "d16"
        case '7':	 // 1 string to match.
          return 31;	 // "d17"
        case '8':	 // 1 string to match.
          return 32;	 // "d18"
        case '9':	 // 1 string to match.
          return 33;	 // "d19"
        }
        break;
      case '2':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 34;	 // "d20"
        case '1':	 // 1 string to match.
          return 35;	 // "d21"
        case '2':	 // 1 string to match.
          return 36;	 // "d22"
        case '3':	 // 1 string to match.
          return 37;	 // "d23"
        case '4':	 // 1 string to match.
          return 38;	 // "d24"
        case '5':	 // 1 string to match.
          return 39;	 // "d25"
        case '6':	 // 1 string to match.
          return 40;	 // "d26"
        case '7':	 // 1 string to match.
          return 41;	 // "d27"
        case '8':	 // 1 string to match.
          return 42;	 // "d28"
        case '9':	 // 1 string to match.
          return 43;	 // "d29"
        }
        break;
      case '3':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 44;	 // "d30"
        case '1':	 // 1 string to match.
          return 45;	 // "d31"
        }
        break;
      }
      break;
    case 'q':	 // 6 strings to match.
      if (Name[1] != '1')
        break;
      switch (Name[2]) {
      default: break;
      case '0':	 // 1 string to match.
        return 60;	 // "q10"
      case '1':	 // 1 string to match.
        return 61;	 // "q11"
      case '2':	 // 1 string to match.
        return 62;	 // "q12"
      case '3':	 // 1 string to match.
        return 63;	 // "q13"
      case '4':	 // 1 string to match.
        return 64;	 // "q14"
      case '5':	 // 1 string to match.
        return 65;	 // "q15"
      }
      break;
    case 'r':	 // 3 strings to match.
      if (Name[1] != '1')
        break;
      switch (Name[2]) {
      default: break;
      case '0':	 // 1 string to match.
        return 76;	 // "r10"
      case '1':	 // 1 string to match.
        return 77;	 // "r11"
      case '2':	 // 1 string to match.
        return 78;	 // "r12"
      }
      break;
    case 's':	 // 22 strings to match.
      switch (Name[1]) {
      default: break;
      case '1':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 89;	 // "s10"
        case '1':	 // 1 string to match.
          return 90;	 // "s11"
        case '2':	 // 1 string to match.
          return 91;	 // "s12"
        case '3':	 // 1 string to match.
          return 92;	 // "s13"
        case '4':	 // 1 string to match.
          return 93;	 // "s14"
        case '5':	 // 1 string to match.
          return 94;	 // "s15"
        case '6':	 // 1 string to match.
          return 95;	 // "s16"
        case '7':	 // 1 string to match.
          return 96;	 // "s17"
        case '8':	 // 1 string to match.
          return 97;	 // "s18"
        case '9':	 // 1 string to match.
          return 98;	 // "s19"
        }
        break;
      case '2':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 99;	 // "s20"
        case '1':	 // 1 string to match.
          return 100;	 // "s21"
        case '2':	 // 1 string to match.
          return 101;	 // "s22"
        case '3':	 // 1 string to match.
          return 102;	 // "s23"
        case '4':	 // 1 string to match.
          return 103;	 // "s24"
        case '5':	 // 1 string to match.
          return 104;	 // "s25"
        case '6':	 // 1 string to match.
          return 105;	 // "s26"
        case '7':	 // 1 string to match.
          return 106;	 // "s27"
        case '8':	 // 1 string to match.
          return 107;	 // "s28"
        case '9':	 // 1 string to match.
          return 108;	 // "s29"
        }
        break;
      case '3':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case '0':	 // 1 string to match.
          return 109;	 // "s30"
        case '1':	 // 1 string to match.
          return 110;	 // "s31"
        }
        break;
      }
      break;
    }
    break;
  case 4:	 // 3 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+1, "psr", 3))
        break;
      return 1;	 // "apsr"
    case 'c':	 // 1 string to match.
      if (memcmp(Name.data()+1, "psr", 3))
        break;
      return 3;	 // "cpsr"
    case 's':	 // 1 string to match.
      if (memcmp(Name.data()+1, "psr", 3))
        break;
      return 13;	 // "spsr"
    }
    break;
  case 5:	 // 6 strings to match.
    switch (Name[0]) {
    default: break;
    case 'f':	 // 3 strings to match.
      if (Name[1] != 'p')
        break;
      switch (Name[2]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+3, "xc", 2))
          break;
        return 4;	 // "fpexc"
      case 's':	 // 2 strings to match.
        switch (Name[3]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (Name[4] != 'r')
            break;
          return 6;	 // "fpscr"
        case 'i':	 // 1 string to match.
          if (Name[4] != 'd')
            break;
          return 8;	 // "fpsid"
        }
        break;
      }
      break;
    case 'm':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "vfr", 3))
        break;
      switch (Name[4]) {
      default: break;
      case '0':	 // 1 string to match.
        return 47;	 // "mvfr0"
      case '1':	 // 1 string to match.
        return 48;	 // "mvfr1"
      case '2':	 // 1 string to match.
        return 49;	 // "mvfr2"
      }
      break;
    }
    break;
  case 6:	 // 1 string to match.
    if (memcmp(Name.data()+0, "fpinst", 6))
      break;
    return 5;	 // "fpinst"
  case 7:	 // 2 strings to match.
    switch (Name[0]) {
    default: break;
    case 'f':	 // 1 string to match.
      if (memcmp(Name.data()+1, "pinst2", 6))
        break;
      return 46;	 // "fpinst2"
    case 'i':	 // 1 string to match.
      if (memcmp(Name.data()+1, "tstate", 6))
        break;
      return 9;	 // "itstate"
    }
    break;
  case 9:	 // 1 string to match.
    if (memcmp(Name.data()+0, "apsr_nzcv", 9))
      break;
    return 2;	 // "apsr_nzcv"
  case 10:	 // 1 string to match.
    if (memcmp(Name.data()+0, "fpscr_nzcv", 10))
      break;
    return 7;	 // "fpscr_nzcv"
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
  case Feature_HasV4T: return "armv4t";
  case Feature_HasV5TE: return "armv5te";
  case Feature_HasV6: return "armv6";
  case Feature_HasV6M: return "armv6m or armv6t2";
  case Feature_HasV6T2: return "armv6t2";
  case Feature_HasV7: return "armv7";
  case Feature_HasV8: return "armv8";
  case Feature_PreV8: return "armv7 or earlier";
  case Feature_HasVFP2: return "VFP2";
  case Feature_HasVFP3: return "VFP3";
  case Feature_HasVFP4: return "VFP4";
  case Feature_HasDPVFP: return "double precision VFP";
  case Feature_HasFPARMv8: return "FPARMv8";
  case Feature_HasNEON: return "NEON";
  case Feature_HasCrypto: return "crypto";
  case Feature_HasCRC: return "crc";
  case Feature_HasFP16: return "half-float";
  case Feature_HasDivide: return "divide in THUMB";
  case Feature_HasDivideInARM: return "divide in ARM";
  case Feature_HasT2ExtractPack: return "pack/extract";
  case Feature_HasThumb2DSP: return "thumb2-dsp";
  case Feature_HasDB: return "data-barriers";
  case Feature_HasMP: return "mp-extensions";
  case Feature_HasTrustZone: return "TrustZone";
  case Feature_IsThumb: return "thumb";
  case Feature_IsThumb2: return "thumb2";
  case Feature_IsMClass: return "armv*m";
  case Feature_IsNotMClass: return "!armv*m";
  case Feature_IsARM: return "arm-mode";
  case Feature_UseNaClTrap: return "NaCl";
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
      case 3:	 // 3 strings to match.
        switch (Mnemonic[0]) {
        default: break;
        case 'r':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+1, "fe", 2))
            break;
          Mnemonic = "rfeia";	 // "rfe"
          return;
        case 's':	 // 2 strings to match.
          switch (Mnemonic[1]) {
          default: break;
          case 'r':	 // 1 string to match.
            if (Mnemonic[2] != 's')
              break;
            Mnemonic = "srsia";	 // "srs"
            return;
          case 'w':	 // 1 string to match.
            if (Mnemonic[2] != 'i')
              break;
            Mnemonic = "svc";	 // "swi"
            return;
          }
          break;
        }
        break;
      case 4:	 // 10 strings to match.
        switch (Mnemonic[0]) {
        default: break;
        case 'f':	 // 8 strings to match.
          switch (Mnemonic[1]) {
          default: break;
          case 'l':	 // 2 strings to match.
            if (Mnemonic[2] != 'd')
              break;
            switch (Mnemonic[3]) {
            default: break;
            case 'd':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fldd"
                Mnemonic = "vldr";
              return;
            case 's':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "flds"
                Mnemonic = "vldr";
              return;
            }
            break;
          case 'm':	 // 4 strings to match.
            switch (Mnemonic[2]) {
            default: break;
            case 'r':	 // 2 strings to match.
              switch (Mnemonic[3]) {
              default: break;
              case 's':	 // 1 string to match.
                if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmrs"
                  Mnemonic = "vmov";
                return;
              case 'x':	 // 1 string to match.
                if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmrx"
                  Mnemonic = "vmrs";
                return;
              }
              break;
            case 's':	 // 1 string to match.
              if (Mnemonic[3] != 'r')
                break;
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmsr"
                Mnemonic = "vmov";
              return;
            case 'x':	 // 1 string to match.
              if (Mnemonic[3] != 'r')
                break;
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmxr"
                Mnemonic = "vmsr";
              return;
            }
            break;
          case 's':	 // 2 strings to match.
            if (Mnemonic[2] != 't')
              break;
            switch (Mnemonic[3]) {
            default: break;
            case 'd':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fstd"
                Mnemonic = "vstr";
              return;
            case 's':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fsts"
                Mnemonic = "vstr";
              return;
            }
            break;
          }
          break;
        case 'v':	 // 2 strings to match.
          switch (Mnemonic[1]) {
          default: break;
          case 'l':	 // 1 string to match.
            if (memcmp(Mnemonic.data()+2, "dm", 2))
              break;
            Mnemonic = "vldmia";	 // "vldm"
            return;
          case 's':	 // 1 string to match.
            if (memcmp(Mnemonic.data()+2, "tm", 2))
              break;
            Mnemonic = "vstmia";	 // "vstm"
            return;
          }
          break;
        }
        break;
      case 5:	 // 51 strings to match.
        switch (Mnemonic[0]) {
        default: break;
        case 'f':	 // 18 strings to match.
          switch (Mnemonic[1]) {
          default: break;
          case 'a':	 // 2 strings to match.
            if (memcmp(Mnemonic.data()+2, "dd", 2))
              break;
            switch (Mnemonic[4]) {
            default: break;
            case 'd':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "faddd"
                Mnemonic = "vadd.f64";
              return;
            case 's':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fadds"
                Mnemonic = "vadd.f32";
              return;
            }
            break;
          case 'c':	 // 4 strings to match.
            switch (Mnemonic[2]) {
            default: break;
            case 'm':	 // 2 strings to match.
              if (Mnemonic[3] != 'p')
                break;
              switch (Mnemonic[4]) {
              default: break;
              case 'd':	 // 1 string to match.
                if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fcmpd"
                  Mnemonic = "vcmp.f64";
                return;
              case 's':	 // 1 string to match.
                if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fcmps"
                  Mnemonic = "vcmp.f32";
                return;
              }
              break;
            case 'p':	 // 2 strings to match.
              if (Mnemonic[3] != 'y')
                break;
              switch (Mnemonic[4]) {
              default: break;
              case 'd':	 // 1 string to match.
                if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fcpyd"
                  Mnemonic = "vmov.f64";
                return;
              case 's':	 // 1 string to match.
                if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fcpys"
                  Mnemonic = "vmov.f32";
                return;
              }
              break;
            }
            break;
          case 'd':	 // 2 strings to match.
            if (memcmp(Mnemonic.data()+2, "iv", 2))
              break;
            switch (Mnemonic[4]) {
            default: break;
            case 'd':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fdivd"
                Mnemonic = "vdiv.f64";
              return;
            case 's':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fdivs"
                Mnemonic = "vdiv.f32";
              return;
            }
            break;
          case 'm':	 // 8 strings to match.
            switch (Mnemonic[2]) {
            default: break;
            case 'a':	 // 2 strings to match.
              if (Mnemonic[3] != 'c')
                break;
              switch (Mnemonic[4]) {
              default: break;
              case 'd':	 // 1 string to match.
                if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmacd"
                  Mnemonic = "vmla.f64";
                return;
              case 's':	 // 1 string to match.
                if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmacs"
                  Mnemonic = "vmla.f32";
                return;
              }
              break;
            case 'd':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "rr", 2))
                break;
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmdrr"
                Mnemonic = "vmov";
              return;
            case 'r':	 // 3 strings to match.
              switch (Mnemonic[3]) {
              default: break;
              case 'd':	 // 2 strings to match.
                switch (Mnemonic[4]) {
                default: break;
                case 'd':	 // 1 string to match.
                  if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmrdd"
                    Mnemonic = "vmov";
                  return;
                case 's':	 // 1 string to match.
                  if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmrds"
                    Mnemonic = "vmov";
                  return;
                }
                break;
              case 'r':	 // 1 string to match.
                if (Mnemonic[4] != 'd')
                  break;
                if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmrrd"
                  Mnemonic = "vmov";
                return;
              }
              break;
            case 'u':	 // 2 strings to match.
              if (Mnemonic[3] != 'l')
                break;
              switch (Mnemonic[4]) {
              default: break;
              case 'd':	 // 1 string to match.
                if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmuld"
                  Mnemonic = "vmul.f64";
                return;
              case 's':	 // 1 string to match.
                if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmuls"
                  Mnemonic = "vmul.f32";
                return;
              }
              break;
            }
            break;
          case 'n':	 // 2 strings to match.
            if (memcmp(Mnemonic.data()+2, "eg", 2))
              break;
            switch (Mnemonic[4]) {
            default: break;
            case 'd':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fnegd"
                Mnemonic = "vneg.f64";
              return;
            case 's':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fnegs"
                Mnemonic = "vneg.f32";
              return;
            }
            break;
          }
          break;
        case 'l':	 // 3 strings to match.
          if (memcmp(Mnemonic.data()+1, "dm", 2))
            break;
          switch (Mnemonic[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Mnemonic[4] != 'a')
              break;
            Mnemonic = "ldmdb";	 // "ldmea"
            return;
          case 'f':	 // 1 string to match.
            if (Mnemonic[4] != 'd')
              break;
            Mnemonic = "ldm";	 // "ldmfd"
            return;
          case 'i':	 // 1 string to match.
            if (Mnemonic[4] != 'a')
              break;
            Mnemonic = "ldm";	 // "ldmia"
            return;
          }
          break;
        case 'r':	 // 4 strings to match.
          if (memcmp(Mnemonic.data()+1, "fe", 2))
            break;
          switch (Mnemonic[3]) {
          default: break;
          case 'e':	 // 2 strings to match.
            switch (Mnemonic[4]) {
            default: break;
            case 'a':	 // 1 string to match.
              Mnemonic = "rfedb";	 // "rfeea"
              return;
            case 'd':	 // 1 string to match.
              Mnemonic = "rfeib";	 // "rfeed"
              return;
            }
            break;
          case 'f':	 // 2 strings to match.
            switch (Mnemonic[4]) {
            default: break;
            case 'a':	 // 1 string to match.
              Mnemonic = "rfeda";	 // "rfefa"
              return;
            case 'd':	 // 1 string to match.
              Mnemonic = "rfeia";	 // "rfefd"
              return;
            }
            break;
          }
          break;
        case 's':	 // 7 strings to match.
          switch (Mnemonic[1]) {
          default: break;
          case 'r':	 // 4 strings to match.
            if (Mnemonic[2] != 's')
              break;
            switch (Mnemonic[3]) {
            default: break;
            case 'e':	 // 2 strings to match.
              switch (Mnemonic[4]) {
              default: break;
              case 'a':	 // 1 string to match.
                Mnemonic = "srsia";	 // "srsea"
                return;
              case 'd':	 // 1 string to match.
                Mnemonic = "srsda";	 // "srsed"
                return;
              }
              break;
            case 'f':	 // 2 strings to match.
              switch (Mnemonic[4]) {
              default: break;
              case 'a':	 // 1 string to match.
                Mnemonic = "srsib";	 // "srsfa"
                return;
              case 'd':	 // 1 string to match.
                Mnemonic = "srsdb";	 // "srsfd"
                return;
              }
              break;
            }
            break;
          case 't':	 // 3 strings to match.
            if (Mnemonic[2] != 'm')
              break;
            switch (Mnemonic[3]) {
            default: break;
            case 'e':	 // 1 string to match.
              if (Mnemonic[4] != 'a')
                break;
              Mnemonic = "stm";	 // "stmea"
              return;
            case 'f':	 // 1 string to match.
              if (Mnemonic[4] != 'd')
                break;
              Mnemonic = "stmdb";	 // "stmfd"
              return;
            case 'i':	 // 1 string to match.
              if (Mnemonic[4] != 'a')
                break;
              Mnemonic = "stm";	 // "stmia"
              return;
            }
            break;
          }
          break;
        case 'v':	 // 19 strings to match.
          switch (Mnemonic[1]) {
          default: break;
          case 'a':	 // 3 strings to match.
            switch (Mnemonic[2]) {
            default: break;
            case 'b':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "sq", 2))
                break;
              if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vabsq"
                Mnemonic = "vabs";
              return;
            case 'd':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "dq", 2))
                break;
              if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vaddq"
                Mnemonic = "vadd";
              return;
            case 'n':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "dq", 2))
                break;
              if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vandq"
                Mnemonic = "vand";
              return;
            }
            break;
          case 'b':	 // 1 string to match.
            if (memcmp(Mnemonic.data()+2, "icq", 3))
              break;
            if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vbicq"
              Mnemonic = "vbic";
            return;
          case 'c':	 // 3 strings to match.
            switch (Mnemonic[2]) {
            default: break;
            case 'e':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "qq", 2))
                break;
              if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vceqq"
                Mnemonic = "vceq";
              return;
            case 'l':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "eq", 2))
                break;
              if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vcleq"
                Mnemonic = "vcle";
              return;
            case 'v':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "tq", 2))
                break;
              if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vcvtq"
                Mnemonic = "vcvt";
              return;
            }
            break;
          case 'e':	 // 1 string to match.
            if (memcmp(Mnemonic.data()+2, "orq", 3))
              break;
            if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "veorq"
              Mnemonic = "veor";
            return;
          case 'm':	 // 5 strings to match.
            switch (Mnemonic[2]) {
            default: break;
            case 'a':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "xq", 2))
                break;
              if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vmaxq"
                Mnemonic = "vmax";
              return;
            case 'i':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "nq", 2))
                break;
              if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vminq"
                Mnemonic = "vmin";
              return;
            case 'o':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "vq", 2))
                break;
              if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vmovq"
                Mnemonic = "vmov";
              return;
            case 'u':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "lq", 2))
                break;
              if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vmulq"
                Mnemonic = "vmul";
              return;
            case 'v':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "nq", 2))
                break;
              if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vmvnq"
                Mnemonic = "vmvn";
              return;
            }
            break;
          case 'o':	 // 1 string to match.
            if (memcmp(Mnemonic.data()+2, "rrq", 3))
              break;
            if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vorrq"
              Mnemonic = "vorr";
            return;
          case 's':	 // 4 strings to match.
            switch (Mnemonic[2]) {
            default: break;
            case 'h':	 // 2 strings to match.
              switch (Mnemonic[3]) {
              default: break;
              case 'l':	 // 1 string to match.
                if (Mnemonic[4] != 'q')
                  break;
                if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vshlq"
                  Mnemonic = "vshl";
                return;
              case 'r':	 // 1 string to match.
                if (Mnemonic[4] != 'q')
                  break;
                if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vshrq"
                  Mnemonic = "vshr";
                return;
              }
              break;
            case 'u':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "bq", 2))
                break;
              if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vsubq"
                Mnemonic = "vsub";
              return;
            case 'w':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "pq", 2))
                break;
              if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vswpq"
                Mnemonic = "vswp";
              return;
            }
            break;
          case 'z':	 // 1 string to match.
            if (memcmp(Mnemonic.data()+2, "ipq", 3))
              break;
            if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vzipq"
              Mnemonic = "vzip";
            return;
          }
          break;
        }
        break;
      case 6:	 // 10 strings to match.
        if (Mnemonic[0] != 'f')
          break;
        switch (Mnemonic[1]) {
        default: break;
        case 's':	 // 4 strings to match.
          switch (Mnemonic[2]) {
          default: break;
          case 'i':	 // 2 strings to match.
            if (memcmp(Mnemonic.data()+3, "to", 2))
              break;
            switch (Mnemonic[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fsitod"
                Mnemonic = "vcvt.f64.s32";
              return;
            case 's':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fsitos"
                Mnemonic = "vcvt.f32.s32";
              return;
            }
            break;
          case 'q':	 // 2 strings to match.
            if (memcmp(Mnemonic.data()+3, "rt", 2))
              break;
            switch (Mnemonic[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fsqrtd"
                Mnemonic = "vsqrt";
              return;
            case 's':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fsqrts"
                Mnemonic = "vsqrt";
              return;
            }
            break;
          }
          break;
        case 't':	 // 4 strings to match.
          if (Mnemonic[2] != 'o')
            break;
          switch (Mnemonic[3]) {
          default: break;
          case 's':	 // 2 strings to match.
            if (Mnemonic[4] != 'i')
              break;
            switch (Mnemonic[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftosid"
                Mnemonic = "vcvtr.s32.f64";
              return;
            case 's':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftosis"
                Mnemonic = "vcvtr.s32.f32";
              return;
            }
            break;
          case 'u':	 // 2 strings to match.
            if (Mnemonic[4] != 'i')
              break;
            switch (Mnemonic[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftouid"
                Mnemonic = "vcvtr.u32.f64";
              return;
            case 's':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftouis"
                Mnemonic = "vcvtr.u32.f32";
              return;
            }
            break;
          }
          break;
        case 'u':	 // 2 strings to match.
          if (memcmp(Mnemonic.data()+2, "ito", 3))
            break;
          switch (Mnemonic[5]) {
          default: break;
          case 'd':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fuitod"
              Mnemonic = "vcvt.f64.u32";
            return;
          case 's':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fuitos"
              Mnemonic = "vcvt.f32.u32";
            return;
          }
          break;
        }
        break;
      case 7:	 // 4 strings to match.
        if (memcmp(Mnemonic.data()+0, "fto", 3))
          break;
        switch (Mnemonic[3]) {
        default: break;
        case 's':	 // 2 strings to match.
          if (memcmp(Mnemonic.data()+4, "iz", 2))
            break;
          switch (Mnemonic[6]) {
          default: break;
          case 'd':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftosizd"
              Mnemonic = "vcvt.s32.f64";
            return;
          case 's':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftosizs"
              Mnemonic = "vcvt.s32.f32";
            return;
          }
          break;
        case 'u':	 // 2 strings to match.
          if (memcmp(Mnemonic.data()+4, "iz", 2))
            break;
          switch (Mnemonic[6]) {
          default: break;
          case 'd':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftouizd"
              Mnemonic = "vcvt.u32.f64";
            return;
          case 's':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftouizs"
              Mnemonic = "vcvt.u32.f32";
            return;
          }
          break;
        }
        break;
      case 8:	 // 5 strings to match.
        switch (Mnemonic[0]) {
        default: break;
        case 'q':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+1, "subaddx", 7))
            break;
          Mnemonic = "qsax";	 // "qsubaddx"
          return;
        case 's':	 // 2 strings to match.
          switch (Mnemonic[1]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (memcmp(Mnemonic.data()+2, "ddsubx", 6))
              break;
            Mnemonic = "sasx";	 // "saddsubx"
            return;
          case 's':	 // 1 string to match.
            if (memcmp(Mnemonic.data()+2, "ubaddx", 6))
              break;
            Mnemonic = "ssax";	 // "ssubaddx"
            return;
          }
          break;
        case 'u':	 // 2 strings to match.
          switch (Mnemonic[1]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (memcmp(Mnemonic.data()+2, "ddsubx", 6))
              break;
            Mnemonic = "uasx";	 // "uaddsubx"
            return;
          case 's':	 // 1 string to match.
            if (memcmp(Mnemonic.data()+2, "ubaddx", 6))
              break;
            Mnemonic = "usax";	 // "usubaddx"
            return;
          }
          break;
        }
        break;
      case 9:	 // 8 strings to match.
        switch (Mnemonic[0]) {
        default: break;
        case 's':	 // 2 strings to match.
          if (Mnemonic[1] != 'h')
            break;
          switch (Mnemonic[2]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (memcmp(Mnemonic.data()+3, "ddsubx", 6))
              break;
            Mnemonic = "shasx";	 // "shaddsubx"
            return;
          case 's':	 // 1 string to match.
            if (memcmp(Mnemonic.data()+3, "ubaddx", 6))
              break;
            Mnemonic = "shsax";	 // "shsubaddx"
            return;
          }
          break;
        case 'u':	 // 4 strings to match.
          switch (Mnemonic[1]) {
          default: break;
          case 'h':	 // 2 strings to match.
            switch (Mnemonic[2]) {
            default: break;
            case 'a':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "ddsubx", 6))
                break;
              Mnemonic = "uhasx";	 // "uhaddsubx"
              return;
            case 's':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "ubaddx", 6))
                break;
              Mnemonic = "uhsax";	 // "uhsubaddx"
              return;
            }
            break;
          case 'q':	 // 2 strings to match.
            switch (Mnemonic[2]) {
            default: break;
            case 'a':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "ddsubx", 6))
                break;
              Mnemonic = "uqasx";	 // "uqaddsubx"
              return;
            case 's':	 // 1 string to match.
              if (memcmp(Mnemonic.data()+3, "ubaddx", 6))
                break;
              Mnemonic = "uqsax";	 // "uqsubaddx"
              return;
            }
            break;
          }
          break;
        case 'v':	 // 2 strings to match.
          if (memcmp(Mnemonic.data()+1, "movq.f", 6))
            break;
          switch (Mnemonic[7]) {
          default: break;
          case '3':	 // 1 string to match.
            if (Mnemonic[8] != '2')
              break;
            if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vmovq.f32"
              Mnemonic = "vmov.f32";
            return;
          case '6':	 // 1 string to match.
            if (Mnemonic[8] != '4')
              break;
            if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vmovq.f64"
              Mnemonic = "vmov.f64";
            return;
          }
          break;
        }
        break;
      case 11:	 // 2 strings to match.
        if (memcmp(Mnemonic.data()+0, "vrecpeq.", 8))
          break;
        switch (Mnemonic[8]) {
        default: break;
        case 'f':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+9, "32", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vrecpeq.f32"
            Mnemonic = "vrecpe.f32";
          return;
        case 'u':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+9, "32", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vrecpeq.u32"
            Mnemonic = "vrecpe.u32";
          return;
        }
        break;
      }
    break;
  }
  switch (Mnemonic.size()) {
  default: break;
  case 3:	 // 3 strings to match.
    switch (Mnemonic[0]) {
    default: break;
    case 'r':	 // 1 string to match.
      if (memcmp(Mnemonic.data()+1, "fe", 2))
        break;
      Mnemonic = "rfeia";	 // "rfe"
      return;
    case 's':	 // 2 strings to match.
      switch (Mnemonic[1]) {
      default: break;
      case 'r':	 // 1 string to match.
        if (Mnemonic[2] != 's')
          break;
        Mnemonic = "srsia";	 // "srs"
        return;
      case 'w':	 // 1 string to match.
        if (Mnemonic[2] != 'i')
          break;
        Mnemonic = "svc";	 // "swi"
        return;
      }
      break;
    }
    break;
  case 4:	 // 10 strings to match.
    switch (Mnemonic[0]) {
    default: break;
    case 'f':	 // 8 strings to match.
      switch (Mnemonic[1]) {
      default: break;
      case 'l':	 // 2 strings to match.
        if (Mnemonic[2] != 'd')
          break;
        switch (Mnemonic[3]) {
        default: break;
        case 'd':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fldd"
            Mnemonic = "vldr";
          return;
        case 's':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "flds"
            Mnemonic = "vldr";
          return;
        }
        break;
      case 'm':	 // 4 strings to match.
        switch (Mnemonic[2]) {
        default: break;
        case 'r':	 // 2 strings to match.
          switch (Mnemonic[3]) {
          default: break;
          case 's':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmrs"
              Mnemonic = "vmov";
            return;
          case 'x':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmrx"
              Mnemonic = "vmrs";
            return;
          }
          break;
        case 's':	 // 1 string to match.
          if (Mnemonic[3] != 'r')
            break;
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmsr"
            Mnemonic = "vmov";
          return;
        case 'x':	 // 1 string to match.
          if (Mnemonic[3] != 'r')
            break;
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmxr"
            Mnemonic = "vmsr";
          return;
        }
        break;
      case 's':	 // 2 strings to match.
        if (Mnemonic[2] != 't')
          break;
        switch (Mnemonic[3]) {
        default: break;
        case 'd':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fstd"
            Mnemonic = "vstr";
          return;
        case 's':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fsts"
            Mnemonic = "vstr";
          return;
        }
        break;
      }
      break;
    case 'v':	 // 2 strings to match.
      switch (Mnemonic[1]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (memcmp(Mnemonic.data()+2, "dm", 2))
          break;
        Mnemonic = "vldmia";	 // "vldm"
        return;
      case 's':	 // 1 string to match.
        if (memcmp(Mnemonic.data()+2, "tm", 2))
          break;
        Mnemonic = "vstmia";	 // "vstm"
        return;
      }
      break;
    }
    break;
  case 5:	 // 51 strings to match.
    switch (Mnemonic[0]) {
    default: break;
    case 'f':	 // 18 strings to match.
      switch (Mnemonic[1]) {
      default: break;
      case 'a':	 // 2 strings to match.
        if (memcmp(Mnemonic.data()+2, "dd", 2))
          break;
        switch (Mnemonic[4]) {
        default: break;
        case 'd':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "faddd"
            Mnemonic = "vadd.f64";
          return;
        case 's':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fadds"
            Mnemonic = "vadd.f32";
          return;
        }
        break;
      case 'c':	 // 4 strings to match.
        switch (Mnemonic[2]) {
        default: break;
        case 'm':	 // 2 strings to match.
          if (Mnemonic[3] != 'p')
            break;
          switch (Mnemonic[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fcmpd"
              Mnemonic = "vcmp.f64";
            return;
          case 's':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fcmps"
              Mnemonic = "vcmp.f32";
            return;
          }
          break;
        case 'p':	 // 2 strings to match.
          if (Mnemonic[3] != 'y')
            break;
          switch (Mnemonic[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fcpyd"
              Mnemonic = "vmov.f64";
            return;
          case 's':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fcpys"
              Mnemonic = "vmov.f32";
            return;
          }
          break;
        }
        break;
      case 'd':	 // 2 strings to match.
        if (memcmp(Mnemonic.data()+2, "iv", 2))
          break;
        switch (Mnemonic[4]) {
        default: break;
        case 'd':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fdivd"
            Mnemonic = "vdiv.f64";
          return;
        case 's':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fdivs"
            Mnemonic = "vdiv.f32";
          return;
        }
        break;
      case 'm':	 // 8 strings to match.
        switch (Mnemonic[2]) {
        default: break;
        case 'a':	 // 2 strings to match.
          if (Mnemonic[3] != 'c')
            break;
          switch (Mnemonic[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmacd"
              Mnemonic = "vmla.f64";
            return;
          case 's':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmacs"
              Mnemonic = "vmla.f32";
            return;
          }
          break;
        case 'd':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "rr", 2))
            break;
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmdrr"
            Mnemonic = "vmov";
          return;
        case 'r':	 // 3 strings to match.
          switch (Mnemonic[3]) {
          default: break;
          case 'd':	 // 2 strings to match.
            switch (Mnemonic[4]) {
            default: break;
            case 'd':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmrdd"
                Mnemonic = "vmov";
              return;
            case 's':	 // 1 string to match.
              if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmrds"
                Mnemonic = "vmov";
              return;
            }
            break;
          case 'r':	 // 1 string to match.
            if (Mnemonic[4] != 'd')
              break;
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmrrd"
              Mnemonic = "vmov";
            return;
          }
          break;
        case 'u':	 // 2 strings to match.
          if (Mnemonic[3] != 'l')
            break;
          switch (Mnemonic[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmuld"
              Mnemonic = "vmul.f64";
            return;
          case 's':	 // 1 string to match.
            if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fmuls"
              Mnemonic = "vmul.f32";
            return;
          }
          break;
        }
        break;
      case 'n':	 // 2 strings to match.
        if (memcmp(Mnemonic.data()+2, "eg", 2))
          break;
        switch (Mnemonic[4]) {
        default: break;
        case 'd':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fnegd"
            Mnemonic = "vneg.f64";
          return;
        case 's':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fnegs"
            Mnemonic = "vneg.f32";
          return;
        }
        break;
      }
      break;
    case 'l':	 // 3 strings to match.
      if (memcmp(Mnemonic.data()+1, "dm", 2))
        break;
      switch (Mnemonic[3]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (Mnemonic[4] != 'a')
          break;
        Mnemonic = "ldmdb";	 // "ldmea"
        return;
      case 'f':	 // 1 string to match.
        if (Mnemonic[4] != 'd')
          break;
        Mnemonic = "ldm";	 // "ldmfd"
        return;
      case 'i':	 // 1 string to match.
        if (Mnemonic[4] != 'a')
          break;
        Mnemonic = "ldm";	 // "ldmia"
        return;
      }
      break;
    case 'r':	 // 4 strings to match.
      if (memcmp(Mnemonic.data()+1, "fe", 2))
        break;
      switch (Mnemonic[3]) {
      default: break;
      case 'e':	 // 2 strings to match.
        switch (Mnemonic[4]) {
        default: break;
        case 'a':	 // 1 string to match.
          Mnemonic = "rfedb";	 // "rfeea"
          return;
        case 'd':	 // 1 string to match.
          Mnemonic = "rfeib";	 // "rfeed"
          return;
        }
        break;
      case 'f':	 // 2 strings to match.
        switch (Mnemonic[4]) {
        default: break;
        case 'a':	 // 1 string to match.
          Mnemonic = "rfeda";	 // "rfefa"
          return;
        case 'd':	 // 1 string to match.
          Mnemonic = "rfeia";	 // "rfefd"
          return;
        }
        break;
      }
      break;
    case 's':	 // 7 strings to match.
      switch (Mnemonic[1]) {
      default: break;
      case 'r':	 // 4 strings to match.
        if (Mnemonic[2] != 's')
          break;
        switch (Mnemonic[3]) {
        default: break;
        case 'e':	 // 2 strings to match.
          switch (Mnemonic[4]) {
          default: break;
          case 'a':	 // 1 string to match.
            Mnemonic = "srsia";	 // "srsea"
            return;
          case 'd':	 // 1 string to match.
            Mnemonic = "srsda";	 // "srsed"
            return;
          }
          break;
        case 'f':	 // 2 strings to match.
          switch (Mnemonic[4]) {
          default: break;
          case 'a':	 // 1 string to match.
            Mnemonic = "srsib";	 // "srsfa"
            return;
          case 'd':	 // 1 string to match.
            Mnemonic = "srsdb";	 // "srsfd"
            return;
          }
          break;
        }
        break;
      case 't':	 // 3 strings to match.
        if (Mnemonic[2] != 'm')
          break;
        switch (Mnemonic[3]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (Mnemonic[4] != 'a')
            break;
          Mnemonic = "stm";	 // "stmea"
          return;
        case 'f':	 // 1 string to match.
          if (Mnemonic[4] != 'd')
            break;
          Mnemonic = "stmdb";	 // "stmfd"
          return;
        case 'i':	 // 1 string to match.
          if (Mnemonic[4] != 'a')
            break;
          Mnemonic = "stm";	 // "stmia"
          return;
        }
        break;
      }
      break;
    case 'v':	 // 19 strings to match.
      switch (Mnemonic[1]) {
      default: break;
      case 'a':	 // 3 strings to match.
        switch (Mnemonic[2]) {
        default: break;
        case 'b':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "sq", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vabsq"
            Mnemonic = "vabs";
          return;
        case 'd':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "dq", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vaddq"
            Mnemonic = "vadd";
          return;
        case 'n':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "dq", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vandq"
            Mnemonic = "vand";
          return;
        }
        break;
      case 'b':	 // 1 string to match.
        if (memcmp(Mnemonic.data()+2, "icq", 3))
          break;
        if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vbicq"
          Mnemonic = "vbic";
        return;
      case 'c':	 // 3 strings to match.
        switch (Mnemonic[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "qq", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vceqq"
            Mnemonic = "vceq";
          return;
        case 'l':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "eq", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vcleq"
            Mnemonic = "vcle";
          return;
        case 'v':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "tq", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vcvtq"
            Mnemonic = "vcvt";
          return;
        }
        break;
      case 'e':	 // 1 string to match.
        if (memcmp(Mnemonic.data()+2, "orq", 3))
          break;
        if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "veorq"
          Mnemonic = "veor";
        return;
      case 'm':	 // 5 strings to match.
        switch (Mnemonic[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "xq", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vmaxq"
            Mnemonic = "vmax";
          return;
        case 'i':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "nq", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vminq"
            Mnemonic = "vmin";
          return;
        case 'o':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "vq", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vmovq"
            Mnemonic = "vmov";
          return;
        case 'u':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "lq", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vmulq"
            Mnemonic = "vmul";
          return;
        case 'v':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "nq", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vmvnq"
            Mnemonic = "vmvn";
          return;
        }
        break;
      case 'o':	 // 1 string to match.
        if (memcmp(Mnemonic.data()+2, "rrq", 3))
          break;
        if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vorrq"
          Mnemonic = "vorr";
        return;
      case 's':	 // 4 strings to match.
        switch (Mnemonic[2]) {
        default: break;
        case 'h':	 // 2 strings to match.
          switch (Mnemonic[3]) {
          default: break;
          case 'l':	 // 1 string to match.
            if (Mnemonic[4] != 'q')
              break;
            if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vshlq"
              Mnemonic = "vshl";
            return;
          case 'r':	 // 1 string to match.
            if (Mnemonic[4] != 'q')
              break;
            if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vshrq"
              Mnemonic = "vshr";
            return;
          }
          break;
        case 'u':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "bq", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vsubq"
            Mnemonic = "vsub";
          return;
        case 'w':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "pq", 2))
            break;
          if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vswpq"
            Mnemonic = "vswp";
          return;
        }
        break;
      case 'z':	 // 1 string to match.
        if (memcmp(Mnemonic.data()+2, "ipq", 3))
          break;
        if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vzipq"
          Mnemonic = "vzip";
        return;
      }
      break;
    }
    break;
  case 6:	 // 10 strings to match.
    if (Mnemonic[0] != 'f')
      break;
    switch (Mnemonic[1]) {
    default: break;
    case 's':	 // 4 strings to match.
      switch (Mnemonic[2]) {
      default: break;
      case 'i':	 // 2 strings to match.
        if (memcmp(Mnemonic.data()+3, "to", 2))
          break;
        switch (Mnemonic[5]) {
        default: break;
        case 'd':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fsitod"
            Mnemonic = "vcvt.f64.s32";
          return;
        case 's':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fsitos"
            Mnemonic = "vcvt.f32.s32";
          return;
        }
        break;
      case 'q':	 // 2 strings to match.
        if (memcmp(Mnemonic.data()+3, "rt", 2))
          break;
        switch (Mnemonic[5]) {
        default: break;
        case 'd':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fsqrtd"
            Mnemonic = "vsqrt";
          return;
        case 's':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fsqrts"
            Mnemonic = "vsqrt";
          return;
        }
        break;
      }
      break;
    case 't':	 // 4 strings to match.
      if (Mnemonic[2] != 'o')
        break;
      switch (Mnemonic[3]) {
      default: break;
      case 's':	 // 2 strings to match.
        if (Mnemonic[4] != 'i')
          break;
        switch (Mnemonic[5]) {
        default: break;
        case 'd':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftosid"
            Mnemonic = "vcvtr.s32.f64";
          return;
        case 's':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftosis"
            Mnemonic = "vcvtr.s32.f32";
          return;
        }
        break;
      case 'u':	 // 2 strings to match.
        if (Mnemonic[4] != 'i')
          break;
        switch (Mnemonic[5]) {
        default: break;
        case 'd':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftouid"
            Mnemonic = "vcvtr.u32.f64";
          return;
        case 's':	 // 1 string to match.
          if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftouis"
            Mnemonic = "vcvtr.u32.f32";
          return;
        }
        break;
      }
      break;
    case 'u':	 // 2 strings to match.
      if (memcmp(Mnemonic.data()+2, "ito", 3))
        break;
      switch (Mnemonic[5]) {
      default: break;
      case 'd':	 // 1 string to match.
        if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fuitod"
          Mnemonic = "vcvt.f64.u32";
        return;
      case 's':	 // 1 string to match.
        if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "fuitos"
          Mnemonic = "vcvt.f32.u32";
        return;
      }
      break;
    }
    break;
  case 7:	 // 4 strings to match.
    if (memcmp(Mnemonic.data()+0, "fto", 3))
      break;
    switch (Mnemonic[3]) {
    default: break;
    case 's':	 // 2 strings to match.
      if (memcmp(Mnemonic.data()+4, "iz", 2))
        break;
      switch (Mnemonic[6]) {
      default: break;
      case 'd':	 // 1 string to match.
        if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftosizd"
          Mnemonic = "vcvt.s32.f64";
        return;
      case 's':	 // 1 string to match.
        if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftosizs"
          Mnemonic = "vcvt.s32.f32";
        return;
      }
      break;
    case 'u':	 // 2 strings to match.
      if (memcmp(Mnemonic.data()+4, "iz", 2))
        break;
      switch (Mnemonic[6]) {
      default: break;
      case 'd':	 // 1 string to match.
        if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftouizd"
          Mnemonic = "vcvt.u32.f64";
        return;
      case 's':	 // 1 string to match.
        if ((Features & Feature_HasVFP2) == Feature_HasVFP2)	 // "ftouizs"
          Mnemonic = "vcvt.u32.f32";
        return;
      }
      break;
    }
    break;
  case 8:	 // 5 strings to match.
    switch (Mnemonic[0]) {
    default: break;
    case 'q':	 // 1 string to match.
      if (memcmp(Mnemonic.data()+1, "subaddx", 7))
        break;
      Mnemonic = "qsax";	 // "qsubaddx"
      return;
    case 's':	 // 2 strings to match.
      switch (Mnemonic[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Mnemonic.data()+2, "ddsubx", 6))
          break;
        Mnemonic = "sasx";	 // "saddsubx"
        return;
      case 's':	 // 1 string to match.
        if (memcmp(Mnemonic.data()+2, "ubaddx", 6))
          break;
        Mnemonic = "ssax";	 // "ssubaddx"
        return;
      }
      break;
    case 'u':	 // 2 strings to match.
      switch (Mnemonic[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Mnemonic.data()+2, "ddsubx", 6))
          break;
        Mnemonic = "uasx";	 // "uaddsubx"
        return;
      case 's':	 // 1 string to match.
        if (memcmp(Mnemonic.data()+2, "ubaddx", 6))
          break;
        Mnemonic = "usax";	 // "usubaddx"
        return;
      }
      break;
    }
    break;
  case 9:	 // 8 strings to match.
    switch (Mnemonic[0]) {
    default: break;
    case 's':	 // 2 strings to match.
      if (Mnemonic[1] != 'h')
        break;
      switch (Mnemonic[2]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Mnemonic.data()+3, "ddsubx", 6))
          break;
        Mnemonic = "shasx";	 // "shaddsubx"
        return;
      case 's':	 // 1 string to match.
        if (memcmp(Mnemonic.data()+3, "ubaddx", 6))
          break;
        Mnemonic = "shsax";	 // "shsubaddx"
        return;
      }
      break;
    case 'u':	 // 4 strings to match.
      switch (Mnemonic[1]) {
      default: break;
      case 'h':	 // 2 strings to match.
        switch (Mnemonic[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "ddsubx", 6))
            break;
          Mnemonic = "uhasx";	 // "uhaddsubx"
          return;
        case 's':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "ubaddx", 6))
            break;
          Mnemonic = "uhsax";	 // "uhsubaddx"
          return;
        }
        break;
      case 'q':	 // 2 strings to match.
        switch (Mnemonic[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "ddsubx", 6))
            break;
          Mnemonic = "uqasx";	 // "uqaddsubx"
          return;
        case 's':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+3, "ubaddx", 6))
            break;
          Mnemonic = "uqsax";	 // "uqsubaddx"
          return;
        }
        break;
      }
      break;
    case 'v':	 // 2 strings to match.
      if (memcmp(Mnemonic.data()+1, "movq.f", 6))
        break;
      switch (Mnemonic[7]) {
      default: break;
      case '3':	 // 1 string to match.
        if (Mnemonic[8] != '2')
          break;
        if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vmovq.f32"
          Mnemonic = "vmov.f32";
        return;
      case '6':	 // 1 string to match.
        if (Mnemonic[8] != '4')
          break;
        if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vmovq.f64"
          Mnemonic = "vmov.f64";
        return;
      }
      break;
    }
    break;
  case 11:	 // 2 strings to match.
    if (memcmp(Mnemonic.data()+0, "vrecpeq.", 8))
      break;
    switch (Mnemonic[8]) {
    default: break;
    case 'f':	 // 1 string to match.
      if (memcmp(Mnemonic.data()+9, "32", 2))
        break;
      if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vrecpeq.f32"
        Mnemonic = "vrecpe.f32";
      return;
    case 'u':	 // 1 string to match.
      if (memcmp(Mnemonic.data()+9, "32", 2))
        break;
      if ((Features & Feature_HasNEON) == Feature_HasNEON)	 // "vrecpeq.u32"
        Mnemonic = "vrecpe.u32";
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
  CVT_95_addCCOutOperands,
  CVT_95_addCondCodeOperands,
  CVT_95_addRegShiftedRegOperands,
  CVT_95_addImmOperands,
  CVT_95_addRegShiftedImmOperands,
  CVT_95_addImm0_95_508s4Operands,
  CVT_regSP,
  CVT_95_addImm0_95_508s4NegOperands,
  CVT_95_addImm0_95_4095NegOperands,
  CVT_95_addT2SOImmNegOperands,
  CVT_95_addARMSOImmNegOperands,
  CVT_95_addImm0_95_1020s4Operands,
  CVT_95_addUnsignedOffset_95_b8s2Operands,
  CVT_95_addAdrLabelOperands,
  CVT_95_addARMSOImmNotOperands,
  CVT_95_addT2SOImmNotOperands,
  CVT_95_addImmThumbSROperands,
  CVT_cvtThumbBranches,
  CVT_95_addBitfieldOperands,
  CVT_95_addCoprocNumOperands,
  CVT_95_addCoprocRegOperands,
  CVT_imm_0,
  CVT_95_addProcIFlagsOperands,
  CVT_imm_15,
  CVT_95_addMemBarrierOptOperands,
  CVT_95_addDPRRegListOperands,
  CVT_imm_1,
  CVT_95_addInstSyncBarrierOptOperands,
  CVT_95_addITCondCodeOperands,
  CVT_95_addITMaskOperands,
  CVT_95_addMemNoOffsetOperands,
  CVT_95_addAddrMode5Operands,
  CVT_95_addCoprocOptionOperands,
  CVT_95_addPostIdxImm8s4Operands,
  CVT_95_addRegListOperands,
  CVT_95_addThumbMemPCOperands,
  CVT_95_addMemThumbRIs4Operands,
  CVT_95_addMemThumbRROperands,
  CVT_95_addMemThumbSPIOperands,
  CVT_95_addMemImm12OffsetOperands,
  CVT_95_addMemNegImm8OffsetOperands,
  CVT_95_addMemRegOffsetOperands,
  CVT_95_addMemUImm12OffsetOperands,
  CVT_95_addT2MemRegOffsetOperands,
  CVT_95_addMemPCRelImm12Operands,
  CVT_95_addMemImm8OffsetOperands,
  CVT_95_addAM2OffsetImmOperands,
  CVT_95_addPostIdxRegShiftedOperands,
  CVT_95_addMemThumbRIs1Operands,
  CVT_95_addMemPosImm8OffsetOperands,
  CVT_95_addMemImm8s4OffsetOperands,
  CVT_95_addAddrMode3Operands,
  CVT_95_addAM3OffsetOperands,
  CVT_95_addMemImm0_95_1020s4OffsetOperands,
  CVT_95_addMemThumbRIs2Operands,
  CVT_95_addPostIdxRegOperands,
  CVT_95_addPostIdxImm8Operands,
  CVT_reg0,
  CVT_regCPSR,
  CVT_imm_14,
  CVT_95_addMSRMaskOperands,
  CVT_cvtThumbMultiply,
  CVT_regR8,
  CVT_regR0,
  CVT_95_addPKHASRImmOperands,
  CVT_95_addImm1_95_32Operands,
  CVT_imm_4,
  CVT_imm_5,
  CVT_95_addShifterImmOperands,
  CVT_95_addImm1_95_16Operands,
  CVT_95_addRotImmOperands,
  CVT_95_addMemTBBOperands,
  CVT_95_addMemTBHOperands,
  CVT_95_addNEONi16splatOperands,
  CVT_95_addNEONi32splatOperands,
  CVT_95_addFBits16Operands,
  CVT_95_addFBits32Operands,
  CVT_95_addVectorIndex16Operands,
  CVT_95_addVectorIndex32Operands,
  CVT_95_addVectorIndex8Operands,
  CVT_95_addVecListOperands,
  CVT_95_addAlignedMemoryOperands,
  CVT_95_addVecListIndexedOperands,
  CVT_95_addSPRRegListOperands,
  CVT_95_addFPImmOperands,
  CVT_95_addNEONi32vmovOperands,
  CVT_95_addNEONi32vmovNegOperands,
  CVT_95_addNEONi64splatOperands,
  CVT_95_addNEONi8splatOperands,
  CVT_imm_2,
  CVT_imm_3,
  CVT_NUM_CONVERTERS
};

enum InstructionConversionKind {
  Convert__Reg1_2__CCOut1_0__Tie0__Reg1_3__CondCode2_1,
  Convert__Reg1_2__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_3__RegShiftedReg3_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_3__ARMSOImm1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0,
  Convert__Reg1_3__Reg1_4__RegShiftedImm2_5__CondCode2_1__CCOut1_0,
  Convert__Reg1_1__Tie0__Reg1_2__CondCode2_0,
  Convert__Reg1_1__Tie0__Imm0_508s41_2__CondCode2_0,
  Convert__regSP__Tie0__Imm0_508s4Neg1_2__CondCode2_0,
  Convert__Reg1_1__Reg1_1__Imm0_40951_2__CondCode2_0,
  Convert__Reg1_1__Reg1_1__Imm0_4095Neg1_2__CondCode2_0,
  Convert__Reg1_2__CCOut1_0__Tie0__Imm0_2551_3__CondCode2_1,
  Convert__Reg1_2__Reg1_2__T2SOImm1_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_2__T2SOImmNeg1_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_2__ARMSOImmNeg1_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_1__Reg1_2__Imm0_1020s41_3__CondCode2_0,
  Convert__Reg1_1__Imm0_40951_3__CondCode2_0,
  Convert__regSP__Tie0__Imm0_508s41_3__CondCode2_0,
  Convert__regSP__Tie0__Imm0_508s4Neg1_3__CondCode2_0,
  Convert__Reg1_1__Reg1_2__Imm0_40951_3__CondCode2_0,
  Convert__Reg1_1__Reg1_2__Imm0_4095Neg1_3__CondCode2_0,
  Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0,
  Convert__Reg1_3__Reg1_3__T2SOImmNeg1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__CCOut1_0__Reg1_3__Reg1_4__CondCode2_1,
  Convert__Reg1_2__CCOut1_0__Reg1_3__Imm0_71_4__CondCode2_1,
  Convert__Reg1_2__Reg1_3__T2SOImmNeg1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_3__ARMSOImmNeg1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_3__Reg1_4__T2SOImm1_5__CondCode2_1__CCOut1_0,
  Convert__Reg1_3__Reg1_4__T2SOImmNeg1_5__CondCode2_1__CCOut1_0,
  Convert__Reg1_1__UnsignedOffset_b8s21_2__CondCode2_0,
  Convert__Reg1_1__Imm1_2__CondCode2_0,
  Convert__Reg1_1__AdrLabel1_2__CondCode2_0,
  Convert__Reg1_2__Imm1_3__CondCode2_0,
  Convert__Reg1_1__Tie0__Reg1_2,
  Convert__Reg1_1__Reg1_2,
  Convert__Reg1_2__Reg1_2__ARMSOImmNot1_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_2__T2SOImmNot1_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_3__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_3__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_3__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_3__ARMSOImmNot1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_3__T2SOImmNot1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__CCOut1_0__Reg1_2__ImmThumbSR1_3__CondCode2_1,
  Convert__Reg1_2__Reg1_2__ImmThumbSR1_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_2__Imm0_321_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_3__Reg1_3__ImmThumbSR1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__CCOut1_0__Reg1_3__ImmThumbSR1_4__CondCode2_1,
  Convert__Reg1_2__Reg1_3__ImmThumbSR1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_3__Imm0_321_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_3__Reg1_4__ImmThumbSR1_5__CondCode2_1__CCOut1_0,
  Convert__Imm1_1__CondCode2_0,
  ConvertCustom_cvtThumbBranches,
  Convert__Reg1_1__Tie0__Bitfield1_2__CondCode2_0,
  Convert__Reg1_1__Tie0__Reg1_2__Bitfield1_3__CondCode2_0,
  Convert__Imm0_2551_0,
  Convert__Imm0_655351_0,
  Convert__Imm1_0,
  Convert__CondCode2_0__Imm1_1,
  Convert__Reg1_0,
  Convert__Reg1_1__CondCode2_0,
  Convert__CondCode2_0__Reg1_1,
  Convert__CondCode2_0,
  Convert__Reg1_0__Imm1_1,
  Convert__CoprocNum1_1__Imm0_151_2__CoprocReg1_3__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0,
  Convert__CoprocNum1_0__Imm0_151_1__CoprocReg1_2__CoprocReg1_3__CoprocReg1_4__Imm0_71_5,
  Convert_NoOperands,
  Convert__Reg1_1__Reg1_2__CondCode2_0,
  Convert__Reg1_1__ARMSOImmNeg1_2__CondCode2_0,
  Convert__Reg1_1__T2SOImmNeg1_2__CondCode2_0,
  Convert__Reg1_1__RegShiftedImm2_2__CondCode2_0,
  Convert__Reg1_1__RegShiftedReg3_2__CondCode2_0,
  Convert__Reg1_1__T2SOImm1_2__CondCode2_0,
  Convert__Reg1_1__ARMSOImm1_2__CondCode2_0,
  Convert__Reg1_2__Reg1_3__CondCode2_0,
  Convert__Reg1_2__RegShiftedImm2_3__CondCode2_0,
  Convert__Reg1_2__T2SOImm1_3__CondCode2_0,
  Convert__Reg1_1__Imm0_2551_2__CondCode2_0,
  Convert__Imm0_311_0,
  Convert__Imm1_0__imm_0,
  Convert__Imm0_311_1,
  Convert__Imm1_0__ProcIFlags1_1,
  Convert__Imm1_0__ProcIFlags1_2,
  Convert__Imm1_0__ProcIFlags1_1__Imm0_311_2,
  Convert__Imm1_0__ProcIFlags1_1__Imm1_2,
  Convert__Imm1_0__ProcIFlags1_2__Imm1_3,
  Convert__Reg1_0__Reg1_1__Reg1_2,
  Convert__Imm0_151_1__CondCode2_0,
  Convert__imm_15,
  Convert__imm_15__CondCode2_0,
  Convert__MemBarrierOpt1_0,
  Convert__MemBarrierOpt1_1__CondCode2_0,
  Convert__Reg1_1__Tie0__CondCode2_0__DPRRegList1_3,
  Convert__Reg1_1__CondCode2_0__DPRRegList1_2,
  Convert__Reg1_1__Tie0__Reg1_2__imm_1__CondCode2_0,
  Convert__Reg1_1__Tie0__Reg1_2__imm_0__CondCode2_0,
  Convert__Imm0_2391_1__CondCode2_0,
  Convert__Imm0_2391_2__CondCode2_0,
  Convert__Imm0_631_0,
  Convert__InstSyncBarrierOpt1_0,
  Convert__InstSyncBarrierOpt1_1__CondCode2_0,
  Convert__ITCondCode1_1__ITMask1_0,
  Convert__Reg1_1__MemNoOffset1_2__CondCode2_0,
  Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0,
  Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0,
  Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0,
  Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0,
  Convert__CoprocNum1_0__CoprocReg1_1__AddrMode52_2,
  Convert__CoprocNum1_0__CoprocReg1_1__MemNoOffset1_2__CoprocOption1_3,
  Convert__CoprocNum1_0__CoprocReg1_1__MemNoOffset1_2__PostIdxImm8s41_3,
  Convert__Reg1_1__CondCode2_0__RegList1_2,
  Convert__Reg1_2__CondCode2_0__RegList1_3,
  Convert__Reg1_1__CondCode2_0__RegList1_3,
  Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3,
  Convert__Reg1_2__Tie0__CondCode2_0__RegList1_4,
  Convert__Reg1_1__ThumbMemPC1_2__CondCode2_0,
  Convert__Reg1_1__MemThumbRIs42_2__CondCode2_0,
  Convert__Reg1_1__MemThumbRR2_2__CondCode2_0,
  Convert__Reg1_1__MemThumbSPI2_2__CondCode2_0,
  Convert__Reg1_1__MemImm12Offset2_2__CondCode2_0,
  Convert__Reg1_1__MemNegImm8Offset2_2__CondCode2_0,
  Convert__Reg1_1__MemRegOffset3_2__CondCode2_0,
  Convert__Reg1_1__MemUImm12Offset2_2__CondCode2_0,
  Convert__Reg1_1__T2MemRegOffset3_2__CondCode2_0,
  Convert__Reg1_1__MemPCRelImm121_2__CondCode2_0,
  Convert__Reg1_2__MemUImm12Offset2_3__CondCode2_0,
  Convert__Reg1_2__T2MemRegOffset3_3__CondCode2_0,
  Convert__Reg1_2__MemPCRelImm121_3__CondCode2_0,
  Convert__Reg1_1__imm_0__MemImm12Offset2_2__CondCode2_0,
  Convert__Reg1_1__imm_0__MemImm8Offset2_2__CondCode2_0,
  Convert__Reg1_1__MemNoOffset1_2__Tie1__AM2OffsetImm2_3__CondCode2_0,
  Convert__Reg1_1__MemNoOffset1_2__Tie1__Imm1_3__CondCode2_0,
  Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxRegShifted2_3__CondCode2_0,
  Convert__Reg1_1__imm_0__MemRegOffset3_2__CondCode2_0,
  Convert__Reg1_1__MemThumbRIs12_2__CondCode2_0,
  Convert__Reg1_1__MemPosImm8Offset2_2__CondCode2_0,
  Convert__Reg1_1__Reg1_2__MemImm8s4Offset2_3__CondCode2_0,
  Convert__Reg1_1__Reg1_2__AddrMode33_3__CondCode2_0,
  Convert__Reg1_1__Reg1_2__imm_0__MemImm8s4Offset2_3__CondCode2_0,
  Convert__Reg1_1__Reg1_2__MemNoOffset1_3__Tie2__Imm1_4__CondCode2_0,
  Convert__Reg1_1__Reg1_2__imm_0__AddrMode33_3__CondCode2_0,
  Convert__Reg1_1__Reg1_2__MemNoOffset1_3__Tie2__AM3Offset2_4__CondCode2_0,
  Convert__Reg1_1__MemImm0_1020s4Offset2_2__CondCode2_0,
  Convert__Reg1_1__MemThumbRIs22_2__CondCode2_0,
  Convert__Reg1_1__AddrMode33_2__CondCode2_0,
  Convert__Reg1_1__imm_0__AddrMode33_2__CondCode2_0,
  Convert__Reg1_1__MemNoOffset1_2__Tie1__AM3Offset2_3__CondCode2_0,
  Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxReg2_3__CondCode2_0,
  Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxImm81_3__CondCode2_0,
  Convert__Reg1_2__CCOut1_0__Reg1_2__Imm0_311_3__CondCode2_1,
  Convert__Reg1_2__Reg1_2__Imm0_311_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_3__Reg1_3__Imm0_311_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__CCOut1_0__Reg1_3__Imm0_311_4__CondCode2_1,
  Convert__Reg1_2__Reg1_3__Imm0_311_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_3__Reg1_4__Imm0_311_5__CondCode2_1__CCOut1_0,
  Convert__CoprocNum1_1__Imm0_71_2__Reg1_3__CoprocReg1_4__CoprocReg1_5__imm_0__CondCode2_0,
  Convert__CoprocNum1_1__Imm0_71_2__Reg1_3__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0,
  Convert__CoprocNum1_0__Imm0_71_1__Reg1_2__CoprocReg1_3__CoprocReg1_4__imm_0,
  Convert__CoprocNum1_0__Imm0_71_1__Reg1_2__CoprocReg1_3__CoprocReg1_4__Imm0_71_5,
  Convert__CoprocNum1_1__Imm0_151_2__Reg1_3__Reg1_4__CoprocReg1_5__CondCode2_0,
  Convert__CoprocNum1_0__Imm0_151_1__Reg1_2__Reg1_3__CoprocReg1_4,
  Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0,
  Convert__Reg1_1__Imm256_65535Expr1_2__CondCode2_0,
  Convert__Reg1_1__T2SOImm1_2__CondCode2_0__reg0,
  Convert__Reg1_1__T2SOImmNot1_2__CondCode2_0__reg0,
  Convert__Reg1_1__Imm0_65535Expr1_2__CondCode2_0,
  Convert__Reg1_2__CCOut1_0__Imm0_2551_3__CondCode2_1,
  Convert__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__ARMSOImmNot1_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__T2SOImm1_3__CondCode2_0__reg0,
  Convert__Reg1_2__Reg1_3__CondCode2_0__reg0,
  Convert__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_0__Reg1_1,
  Convert__Reg1_0__regCPSR__Imm0_2551_1__imm_14__imm_0,
  Convert__Reg1_1__T2SOImm1_2__CondCode2_0__regCPSR,
  Convert__Reg1_1__Reg1_2__CondCode2_0__regCPSR,
  Convert__Reg1_2__T2SOImm1_3__CondCode2_0__regCPSR,
  Convert__Reg1_2__Reg1_3__CondCode2_0__regCPSR,
  Convert__Reg1_1__Tie0__Imm0_65535Expr1_2__CondCode2_0,
  Convert__Reg1_3__CoprocNum1_1__Imm0_71_2__CoprocReg1_4__CoprocReg1_5__imm_0__CondCode2_0,
  Convert__Reg1_3__CoprocNum1_1__Imm0_71_2__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0,
  Convert__Reg1_2__CoprocNum1_0__Imm0_71_1__CoprocReg1_3__CoprocReg1_4__imm_0,
  Convert__Reg1_2__CoprocNum1_0__Imm0_71_1__CoprocReg1_3__CoprocReg1_4__Imm0_71_5,
  Convert__Reg1_1__MSRMask1_2__CondCode2_0,
  Convert__MSRMask1_1__Reg1_2__CondCode2_0,
  Convert__MSRMask1_1__ARMSOImm1_2__CondCode2_0,
  Convert__Reg1_1__Reg1_2__Reg1_1__CondCode2_0,
  ConvertCustom_cvtThumbMultiply,
  Convert__Reg1_2__CCOut1_0__Reg1_3__CondCode2_1,
  Convert__Reg1_2__T2SOImm1_3__CondCode2_1__CCOut1_0,
  Convert__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0,
  Convert__Reg1_2__Reg1_3__imm_0__CondCode2_1__CCOut1_0,
  Convert__regR8__regR8__imm_14__imm_0,
  Convert__imm_0__CondCode2_0,
  Convert__regR0__regR0__CondCode2_0__reg0,
  Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0,
  Convert__Reg1_1__Reg1_2__Reg1_3__PKHLSLImm1_4__CondCode2_0,
  Convert__Reg1_1__Reg1_2__Reg1_3__PKHASRImm1_4__CondCode2_0,
  Convert__MemImm12Offset2_0,
  Convert__MemRegOffset3_0,
  Convert__MemNegImm8Offset2_1__CondCode2_0,
  Convert__MemUImm12Offset2_1__CondCode2_0,
  Convert__T2MemRegOffset3_1__CondCode2_0,
  Convert__MemPCRelImm121_1__CondCode2_0,
  Convert__CondCode2_0__RegList1_1,
  Convert__regSP__Tie0__CondCode2_0__RegList1_1,
  Convert__regSP__Tie0__CondCode2_0__RegList1_2,
  Convert__Reg1_1__Reg1_2__Imm0_311_3__Imm1_321_4__CondCode2_0,
  Convert__SetEndImm1_0,
  Convert__imm_4__CondCode2_0,
  Convert__imm_5__CondCode2_0,
  Convert__Reg1_1__Tie0__Reg1_2__Reg1_3,
  Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__Tie0__Tie1__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Reg1_4__Reg1_5__Tie0__Tie1__CondCode2_1__CCOut1_0,
  Convert__Reg1_1__Reg1_2__Reg1_4__Reg1_3__CondCode2_0,
  Convert__Imm0_311_2,
  Convert__Imm0_311_1__CondCode2_0,
  Convert__Imm0_311_2__CondCode2_0,
  Convert__Imm0_311_3__CondCode2_0,
  Convert__Reg1_1__Imm1_321_2__Reg1_3__imm_0__CondCode2_0,
  Convert__Reg1_1__Imm1_321_2__Reg1_3__ShifterImm1_4__CondCode2_0,
  Convert__Reg1_1__Imm1_161_2__Reg1_3__CondCode2_0,
  Convert__Reg1_1__Reg1_2__Reg1_3__MemNoOffset1_4__CondCode2_0,
  Convert__imm_0__Reg1_1__MemImm8Offset2_2__CondCode2_0,
  Convert__MemNoOffset1_2__Reg1_1__Tie0__Imm1_3__CondCode2_0,
  Convert__imm_0__Reg1_1__MemImm12Offset2_2__CondCode2_0,
  Convert__MemNoOffset1_2__Reg1_1__Tie0__AM2OffsetImm2_3__CondCode2_0,
  Convert__MemNoOffset1_2__Reg1_1__Tie0__PostIdxRegShifted2_3__CondCode2_0,
  Convert__imm_0__Reg1_1__MemRegOffset3_2__CondCode2_0,
  Convert__Reg1_1__MemImm8Offset2_2__CondCode2_0,
  Convert__imm_0__Reg1_1__Reg1_2__MemImm8s4Offset2_3__CondCode2_0,
  Convert__MemNoOffset1_3__Reg1_1__Reg1_2__Tie0__Imm1_4__CondCode2_0,
  Convert__imm_0__Reg1_1__Reg1_2__AddrMode33_3__CondCode2_0,
  Convert__MemNoOffset1_3__Reg1_1__Reg1_2__Tie0__AM3Offset2_4__CondCode2_0,
  Convert__Reg1_1__Reg1_2__MemImm0_1020s4Offset2_3__CondCode2_0,
  Convert__imm_0__Reg1_1__AddrMode33_2__CondCode2_0,
  Convert__MemNoOffset1_2__Reg1_1__Tie0__AM3Offset2_3__CondCode2_0,
  Convert__MemNoOffset1_2__Reg1_1__Tie0__PostIdxImm81_3__CondCode2_0,
  Convert__MemNoOffset1_2__Reg1_1__Tie0__PostIdxReg2_3__CondCode2_0,
  Convert__Imm0_2551_3__CondCode2_0,
  Convert__Imm0_2551_1__CondCode2_0,
  Convert__Imm24bit1_1__CondCode2_0,
  Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0,
  Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0,
  Convert__Reg1_2__Reg1_3__imm_0__CondCode2_0,
  Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0,
  Convert__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0,
  Convert__MemTBB2_1__CondCode2_0,
  Convert__MemTBH2_1__CondCode2_0,
  Convert__Reg1_1__Imm0_311_2__Reg1_3__imm_0__CondCode2_0,
  Convert__Reg1_1__Imm0_311_2__Reg1_3__ShifterImm1_4__CondCode2_0,
  Convert__Reg1_1__Imm0_151_2__Reg1_3__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0,
  Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Reg1_2__CondCode2_0,
  Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0,
  Convert__Reg1_1__Reg1_1__Reg1_2__CondCode2_0,
  Convert__Reg1_2__NEONi16splat1_3__Tie0__CondCode2_0,
  Convert__Reg1_2__NEONi32splat1_3__Tie0__CondCode2_0,
  Convert__Reg1_1__Tie0__Reg1_2__Reg1_3__CondCode2_0,
  Convert__Reg1_2__Reg1_2__CondCode2_0,
  Convert__Reg1_2__CondCode2_0,
  Convert__Reg1_3__Reg1_4__CondCode2_0,
  Convert__Reg1_3__Tie0__FBits161_5__CondCode2_0,
  Convert__Reg1_3__Tie0__FBits321_5__CondCode2_0,
  Convert__Reg1_3__Reg1_4__Imm1_5__CondCode2_0,
  Convert__Reg1_2__Reg1_3,
  Convert__Reg1_2__Reg1_3__VectorIndex161_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__VectorIndex321_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__VectorIndex81_4__CondCode2_0,
  Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_31_4__CondCode2_0,
  Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_151_4__CondCode2_0,
  Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_11_4__CondCode2_0,
  Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_71_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_31_5__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_151_5__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_11_5__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_71_5__CondCode2_0,
  Convert__VecListDPairAllLanes1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListDPair1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListOneDAllLanes1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListOneD1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListOneDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListOneDWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListOneDByteIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0,
  Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__CondCode2_0,
  Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__CondCode2_0,
  Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListOneDAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0,
  Convert__VecListOneDAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListOneD1_2__imm_0__AlignedMemory2_3__CondCode2_0,
  Convert__VecListOneD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListOneDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListThreeD1_2__imm_0__AlignedMemory2_3__CondCode2_0,
  Convert__VecListThreeD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListOneDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListOneDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__Reg1_3__AlignedMemory2_8__Tie0__Imm1_5__CondCode2_0,
  Convert__Reg1_3__imm_0__AlignedMemory2_8__Imm1_9__Tie0__Imm1_5__CondCode2_0,
  Convert__Reg1_3__Reg1_8__Imm1_9__Tie0__Imm1_5__CondCode2_0,
  Convert__VecListDPairSpacedAllLanes1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListDPairSpaced1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListTwoDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListTwoQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListTwoDWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListTwoQWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListTwoDByteIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListDPairSpacedAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0,
  Convert__VecListDPairSpacedAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListDPairSpaced1_2__imm_0__AlignedMemory2_3__CondCode2_0,
  Convert__VecListDPairSpaced1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListTwoDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListTwoQHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListTwoDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListTwoQWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListTwoDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListThreeDAllLanes1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListThreeDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListThreeQAllLanes1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListThreeQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListThreeDWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListThreeQWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListThreeDByteIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListThreeDAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListThreeD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListThreeDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListThreeQAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListThreeQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListThreeQHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListThreeDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListThreeQWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListThreeDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__Reg1_3__Reg1_4__Reg1_5__AlignedMemory2_7__CondCode2_0,
  Convert__Reg1_3__Reg1_4__Reg1_5__imm_0__AlignedMemory2_7__Imm1_8__CondCode2_0,
  Convert__Reg1_3__Reg1_6__Reg1_9__AlignedMemory2_13__CondCode2_0,
  Convert__Reg1_3__Reg1_6__Reg1_9__imm_0__AlignedMemory2_13__Imm1_14__CondCode2_0,
  Convert__VecListFourDAllLanes1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListFourDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListFourQAllLanes1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListFourQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListFourDWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListFourQWordIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListFourDByteIndexed2_2__AlignedMemory2_3__CondCode2_0,
  Convert__VecListFourDAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListFourD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListFourDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListFourQAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListFourQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListFourQHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListFourDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListFourQWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__VecListFourDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0,
  Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__AlignedMemory2_8__CondCode2_0,
  Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__imm_0__AlignedMemory2_8__Imm1_9__CondCode2_0,
  Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__AlignedMemory2_16__CondCode2_0,
  Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__imm_0__AlignedMemory2_16__Imm1_17__CondCode2_0,
  Convert__Reg1_1__Tie0__CondCode2_0__SPRRegList1_3,
  Convert__Reg1_1__CondCode2_0__SPRRegList1_2,
  Convert__Reg1_1__AddrMode52_2__CondCode2_0,
  Convert__Reg1_2__AddrMode52_3__CondCode2_0,
  Convert__Reg1_1__Reg1_2__Reg1_3,
  Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0,
  Convert__Reg1_1__Reg1_2__Reg1_2__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Reg1_3__CondCode2_0,
  Convert__Reg1_2__FPImm1_3__CondCode2_0,
  Convert__Reg1_2__NEONi32vmov1_3__CondCode2_0,
  Convert__Reg1_2__NEONi16splat1_3__CondCode2_0,
  Convert__Reg1_2__NEONi32vmovNeg1_3__CondCode2_0,
  Convert__Reg1_2__NEONi64splat1_3__CondCode2_0,
  Convert__Reg1_2__NEONi8splat1_3__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_4__VectorIndex161_3__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_4__VectorIndex321_3__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_4__VectorIndex81_3__CondCode2_0,
  Convert__Reg1_2__Reg1_2__Reg1_3__VectorIndex321_4__CondCode2_0,
  Convert__Reg1_2__Reg1_2__Reg1_3__VectorIndex161_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0,
  Convert__regSP__Tie0__CondCode2_0__DPRRegList1_1,
  Convert__regSP__Tie0__CondCode2_0__SPRRegList1_1,
  Convert__regSP__Tie0__CondCode2_0__DPRRegList1_2,
  Convert__regSP__Tie0__CondCode2_0__SPRRegList1_2,
  Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0,
  Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0,
  Convert__Reg1_2__Reg1_2__ShrImm161_3__CondCode2_0,
  Convert__Reg1_2__Reg1_2__ShrImm321_3__CondCode2_0,
  Convert__Reg1_2__Reg1_2__ShrImm641_3__CondCode2_0,
  Convert__Reg1_2__Reg1_2__ShrImm81_3__CondCode2_0,
  Convert__Reg1_2__Reg1_3__ShrImm641_4__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_2__ShrImm161_3__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_2__ShrImm321_3__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_2__ShrImm641_3__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_2__ShrImm81_3__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_3__ShrImm161_4__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_3__ShrImm321_4__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_3__ShrImm641_4__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_3__ShrImm81_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Imm1_151_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Imm161_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Imm321_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Imm1_71_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Imm81_4__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Imm1_311_4__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_2__Imm1_3__CondCode2_0,
  Convert__Reg1_2__Tie0__Reg1_3__Imm1_4__CondCode2_0,
  Convert__AlignedMemory2_3__VecListDPair1_2__CondCode2_0,
  Convert__AlignedMemory2_3__VecListFourD1_2__CondCode2_0,
  Convert__AlignedMemory2_3__VecListOneD1_2__CondCode2_0,
  Convert__AlignedMemory2_3__VecListThreeD1_2__CondCode2_0,
  Convert__imm_0__AlignedMemory2_3__VecListDPair1_2__CondCode2_0,
  Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPair1_2__CondCode2_0,
  Convert__imm_0__AlignedMemory2_3__VecListFourD1_2__CondCode2_0,
  Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListFourD1_2__CondCode2_0,
  Convert__imm_0__AlignedMemory2_3__VecListOneD1_2__CondCode2_0,
  Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListOneD1_2__CondCode2_0,
  Convert__imm_0__AlignedMemory2_3__VecListThreeD1_2__CondCode2_0,
  Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListThreeD1_2__CondCode2_0,
  Convert__AlignedMemory2_8__Reg1_3__Imm1_5__CondCode2_0,
  Convert__imm_0__AlignedMemory2_8__Imm1_9__Reg1_3__Imm1_5__CondCode2_0,
  Convert__Reg1_8__Imm1_9__Reg1_3__Imm1_5__CondCode2_0,
  Convert__imm_0__Reg1_8__Imm1_9__Imm1_10__Reg1_3__Imm1_5__CondCode2_0,
  Convert__AlignedMemory2_3__VecListDPairSpaced1_2__CondCode2_0,
  Convert__imm_0__AlignedMemory2_3__VecListDPairSpaced1_2__CondCode2_0,
  Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPairSpaced1_2__CondCode2_0,
  Convert__AlignedMemory2_7__Reg1_3__Reg1_4__Reg1_5__CondCode2_0,
  Convert__imm_0__AlignedMemory2_7__Imm1_8__Reg1_3__Reg1_4__Reg1_5__CondCode2_0,
  Convert__AlignedMemory2_8__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0,
  Convert__imm_0__AlignedMemory2_8__Imm1_9__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0,
  Convert__Reg1_1__Reg1_2__Tie0__Tie1__CondCode2_0,
  Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0,
  Convert__Reg1_2__VecListDPair1_3__Reg1_4__CondCode2_0,
  Convert__Reg1_2__VecListFourD1_3__Reg1_4__CondCode2_0,
  Convert__Reg1_2__VecListOneD1_3__Reg1_4__CondCode2_0,
  Convert__Reg1_2__VecListThreeD1_3__Reg1_4__CondCode2_0,
  Convert__Reg1_2__Tie0__VecListDPair1_3__Reg1_4__CondCode2_0,
  Convert__Reg1_2__Tie0__VecListFourD1_3__Reg1_4__CondCode2_0,
  Convert__Reg1_2__Tie0__VecListOneD1_3__Reg1_4__CondCode2_0,
  Convert__Reg1_2__Tie0__VecListThreeD1_3__Reg1_4__CondCode2_0,
  Convert__imm_2__CondCode2_0,
  Convert__imm_3__CondCode2_0,
  Convert__imm_1__CondCode2_0,
  CVT_NUM_SIGNATURES
};

} // end anonymous namespace

static const uint8_t ConversionTable[CVT_NUM_SIGNATURES][17] = {
  // Convert__Reg1_2__CCOut1_0__Tie0__Reg1_3__CondCode2_1
  { CVT_95_Reg, 3, CVT_95_addCCOutOperands, 1, CVT_Tied, 0, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 2, CVT_Done },
  // Convert__Reg1_2__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addRegShiftedRegOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addRegShiftedImmOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addRegShiftedImmOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__RegShiftedReg3_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addRegShiftedRegOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__ARMSOImm1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_Reg, 6, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_4__RegShiftedImm2_5__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addRegShiftedImmOperands, 6, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_1__Tie0__Reg1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Tie0__Imm0_508s41_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addImm0_95_508s4Operands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__regSP__Tie0__Imm0_508s4Neg1_2__CondCode2_0
  { CVT_regSP, 0, CVT_Tied, 0, CVT_95_addImm0_95_508s4NegOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_1__Imm0_40951_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_1__Imm0_4095Neg1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 2, CVT_95_addImm0_95_4095NegOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__CCOut1_0__Tie0__Imm0_2551_3__CondCode2_1
  { CVT_95_Reg, 3, CVT_95_addCCOutOperands, 1, CVT_Tied, 0, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_Done },
  // Convert__Reg1_2__Reg1_2__T2SOImm1_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__T2SOImmNeg1_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addT2SOImmNegOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__ARMSOImmNeg1_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addARMSOImmNegOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Imm0_1020s41_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addImm0_95_1020s4Operands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Imm0_40951_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__regSP__Tie0__Imm0_508s41_3__CondCode2_0
  { CVT_regSP, 0, CVT_Tied, 0, CVT_95_addImm0_95_508s4Operands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__regSP__Tie0__Imm0_508s4Neg1_3__CondCode2_0
  { CVT_regSP, 0, CVT_Tied, 0, CVT_95_addImm0_95_508s4NegOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Imm0_40951_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Imm0_4095Neg1_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addImm0_95_4095NegOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_3__T2SOImmNeg1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_Reg, 4, CVT_95_addT2SOImmNegOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__CCOut1_0__Reg1_3__Reg1_4__CondCode2_1
  { CVT_95_Reg, 3, CVT_95_addCCOutOperands, 1, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 2, CVT_Done },
  // Convert__Reg1_2__CCOut1_0__Reg1_3__Imm0_71_4__CondCode2_1
  { CVT_95_Reg, 3, CVT_95_addCCOutOperands, 1, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_Done },
  // Convert__Reg1_2__Reg1_3__T2SOImmNeg1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addT2SOImmNegOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__ARMSOImmNeg1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addARMSOImmNegOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_4__T2SOImm1_5__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_4__T2SOImmNeg1_5__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addT2SOImmNegOperands, 6, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_1__UnsignedOffset_b8s21_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addUnsignedOffset_95_b8s2Operands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Imm1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__AdrLabel1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addAdrLabelOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Imm1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Tie0__Reg1_2
  { CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Reg1_1__Reg1_2
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Done },
  // Convert__Reg1_2__Reg1_2__ARMSOImmNot1_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addARMSOImmNotOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__T2SOImmNot1_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addT2SOImmNotOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_Reg, 4, CVT_95_addRegShiftedImmOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__ARMSOImmNot1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addARMSOImmNotOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__T2SOImmNot1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addT2SOImmNotOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__CCOut1_0__Reg1_2__ImmThumbSR1_3__CondCode2_1
  { CVT_95_Reg, 3, CVT_95_addCCOutOperands, 1, CVT_95_Reg, 3, CVT_95_addImmThumbSROperands, 4, CVT_95_addCondCodeOperands, 2, CVT_Done },
  // Convert__Reg1_2__Reg1_2__ImmThumbSR1_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addImmThumbSROperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__Imm0_321_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_3__ImmThumbSR1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_Reg, 4, CVT_95_addImmThumbSROperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__CCOut1_0__Reg1_3__ImmThumbSR1_4__CondCode2_1
  { CVT_95_Reg, 3, CVT_95_addCCOutOperands, 1, CVT_95_Reg, 4, CVT_95_addImmThumbSROperands, 5, CVT_95_addCondCodeOperands, 2, CVT_Done },
  // Convert__Reg1_2__Reg1_3__ImmThumbSR1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmThumbSROperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Imm0_321_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_4__ImmThumbSR1_5__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addImmThumbSROperands, 6, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Imm1_1__CondCode2_0
  { CVT_95_addImmOperands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // ConvertCustom_cvtThumbBranches
  { CVT_cvtThumbBranches, 0, CVT_Done },
  // Convert__Reg1_1__Tie0__Bitfield1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addBitfieldOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Tie0__Reg1_2__Bitfield1_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addBitfieldOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Imm0_2551_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Imm0_655351_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Imm1_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__CondCode2_0__Imm1_1
  { CVT_95_addCondCodeOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_0
  { CVT_95_Reg, 1, CVT_Done },
  // Convert__Reg1_1__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__CondCode2_0__Reg1_1
  { CVT_95_addCondCodeOperands, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__CondCode2_0
  { CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_0__Imm1_1
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__CoprocNum1_1__Imm0_151_2__CoprocReg1_3__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0
  { CVT_95_addCoprocNumOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addCoprocRegOperands, 4, CVT_95_addCoprocRegOperands, 5, CVT_95_addCoprocRegOperands, 6, CVT_95_addImmOperands, 7, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__CoprocNum1_0__Imm0_151_1__CoprocReg1_2__CoprocReg1_3__CoprocReg1_4__Imm0_71_5
  { CVT_95_addCoprocNumOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addCoprocRegOperands, 3, CVT_95_addCoprocRegOperands, 4, CVT_95_addCoprocRegOperands, 5, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert_NoOperands
  { CVT_Done },
  // Convert__Reg1_1__Reg1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__ARMSOImmNeg1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addARMSOImmNegOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__T2SOImmNeg1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addT2SOImmNegOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__RegShiftedImm2_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addRegShiftedImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__RegShiftedReg3_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addRegShiftedRegOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__T2SOImm1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__ARMSOImm1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__RegShiftedImm2_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addRegShiftedImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__T2SOImm1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Imm0_2551_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Imm0_311_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Imm1_0__imm_0
  { CVT_95_addImmOperands, 1, CVT_imm_0, 0, CVT_Done },
  // Convert__Imm0_311_1
  { CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Imm1_0__ProcIFlags1_1
  { CVT_95_addImmOperands, 1, CVT_95_addProcIFlagsOperands, 2, CVT_Done },
  // Convert__Imm1_0__ProcIFlags1_2
  { CVT_95_addImmOperands, 1, CVT_95_addProcIFlagsOperands, 3, CVT_Done },
  // Convert__Imm1_0__ProcIFlags1_1__Imm0_311_2
  { CVT_95_addImmOperands, 1, CVT_95_addProcIFlagsOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Imm1_0__ProcIFlags1_1__Imm1_2
  { CVT_95_addImmOperands, 1, CVT_95_addProcIFlagsOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Imm1_0__ProcIFlags1_2__Imm1_3
  { CVT_95_addImmOperands, 1, CVT_95_addProcIFlagsOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_0__Reg1_1__Reg1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm0_151_1__CondCode2_0
  { CVT_95_addImmOperands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_15
  { CVT_imm_15, 0, CVT_Done },
  // Convert__imm_15__CondCode2_0
  { CVT_imm_15, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemBarrierOpt1_0
  { CVT_95_addMemBarrierOptOperands, 1, CVT_Done },
  // Convert__MemBarrierOpt1_1__CondCode2_0
  { CVT_95_addMemBarrierOptOperands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Tie0__CondCode2_0__DPRRegList1_3
  { CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addCondCodeOperands, 1, CVT_95_addDPRRegListOperands, 4, CVT_Done },
  // Convert__Reg1_1__CondCode2_0__DPRRegList1_2
  { CVT_95_Reg, 2, CVT_95_addCondCodeOperands, 1, CVT_95_addDPRRegListOperands, 3, CVT_Done },
  // Convert__Reg1_1__Tie0__Reg1_2__imm_1__CondCode2_0
  { CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_Reg, 3, CVT_imm_1, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Tie0__Reg1_2__imm_0__CondCode2_0
  { CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_Reg, 3, CVT_imm_0, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Imm0_2391_1__CondCode2_0
  { CVT_95_addImmOperands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Imm0_2391_2__CondCode2_0
  { CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Imm0_631_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__InstSyncBarrierOpt1_0
  { CVT_95_addInstSyncBarrierOptOperands, 1, CVT_Done },
  // Convert__InstSyncBarrierOpt1_1__CondCode2_0
  { CVT_95_addInstSyncBarrierOptOperands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__ITCondCode1_1__ITMask1_0
  { CVT_95_addITCondCodeOperands, 2, CVT_95_addITMaskOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemNoOffset1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemNoOffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addMemNoOffsetOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0
  { CVT_95_addCoprocNumOperands, 2, CVT_95_addCoprocRegOperands, 3, CVT_95_addAddrMode5Operands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0
  { CVT_95_addCoprocNumOperands, 2, CVT_95_addCoprocRegOperands, 3, CVT_95_addMemNoOffsetOperands, 4, CVT_95_addCoprocOptionOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0
  { CVT_95_addCoprocNumOperands, 2, CVT_95_addCoprocRegOperands, 3, CVT_95_addMemNoOffsetOperands, 4, CVT_95_addPostIdxImm8s4Operands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__CoprocNum1_0__CoprocReg1_1__AddrMode52_2
  { CVT_95_addCoprocNumOperands, 1, CVT_95_addCoprocRegOperands, 2, CVT_95_addAddrMode5Operands, 3, CVT_Done },
  // Convert__CoprocNum1_0__CoprocReg1_1__MemNoOffset1_2__CoprocOption1_3
  { CVT_95_addCoprocNumOperands, 1, CVT_95_addCoprocRegOperands, 2, CVT_95_addMemNoOffsetOperands, 3, CVT_95_addCoprocOptionOperands, 4, CVT_Done },
  // Convert__CoprocNum1_0__CoprocReg1_1__MemNoOffset1_2__PostIdxImm8s41_3
  { CVT_95_addCoprocNumOperands, 1, CVT_95_addCoprocRegOperands, 2, CVT_95_addMemNoOffsetOperands, 3, CVT_95_addPostIdxImm8s4Operands, 4, CVT_Done },
  // Convert__Reg1_1__CondCode2_0__RegList1_2
  { CVT_95_Reg, 2, CVT_95_addCondCodeOperands, 1, CVT_95_addRegListOperands, 3, CVT_Done },
  // Convert__Reg1_2__CondCode2_0__RegList1_3
  { CVT_95_Reg, 3, CVT_95_addCondCodeOperands, 1, CVT_95_addRegListOperands, 4, CVT_Done },
  // Convert__Reg1_1__CondCode2_0__RegList1_3
  { CVT_95_Reg, 2, CVT_95_addCondCodeOperands, 1, CVT_95_addRegListOperands, 4, CVT_Done },
  // Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3
  { CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addCondCodeOperands, 1, CVT_95_addRegListOperands, 4, CVT_Done },
  // Convert__Reg1_2__Tie0__CondCode2_0__RegList1_4
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addCondCodeOperands, 1, CVT_95_addRegListOperands, 5, CVT_Done },
  // Convert__Reg1_1__ThumbMemPC1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addThumbMemPCOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemThumbRIs42_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemThumbRIs4Operands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemThumbRR2_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemThumbRROperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemThumbSPI2_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemThumbSPIOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemImm12Offset2_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemImm12OffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemNegImm8Offset2_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemNegImm8OffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemRegOffset3_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemRegOffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemUImm12Offset2_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemUImm12OffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__T2MemRegOffset3_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addT2MemRegOffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemPCRelImm121_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemPCRelImm12Operands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__MemUImm12Offset2_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addMemUImm12OffsetOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__T2MemRegOffset3_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addT2MemRegOffsetOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__MemPCRelImm121_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addMemPCRelImm12Operands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__imm_0__MemImm12Offset2_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_imm_0, 0, CVT_95_addMemImm12OffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__imm_0__MemImm8Offset2_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_imm_0, 0, CVT_95_addMemImm8OffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemNoOffset1_2__Tie1__AM2OffsetImm2_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemNoOffsetOperands, 3, CVT_Tied, 1, CVT_95_addAM2OffsetImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemNoOffset1_2__Tie1__Imm1_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemNoOffsetOperands, 3, CVT_Tied, 1, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxRegShifted2_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemNoOffsetOperands, 3, CVT_Tied, 1, CVT_95_addPostIdxRegShiftedOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__imm_0__MemRegOffset3_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_imm_0, 0, CVT_95_addMemRegOffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemThumbRIs12_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemThumbRIs1Operands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemPosImm8Offset2_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemPosImm8OffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__MemImm8s4Offset2_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addMemImm8s4OffsetOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__AddrMode33_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addAddrMode3Operands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__imm_0__MemImm8s4Offset2_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_imm_0, 0, CVT_95_addMemImm8s4OffsetOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__MemNoOffset1_3__Tie2__Imm1_4__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addMemNoOffsetOperands, 4, CVT_Tied, 2, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__imm_0__AddrMode33_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_imm_0, 0, CVT_95_addAddrMode3Operands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__MemNoOffset1_3__Tie2__AM3Offset2_4__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addMemNoOffsetOperands, 4, CVT_Tied, 2, CVT_95_addAM3OffsetOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemImm0_1020s4Offset2_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemImm0_95_1020s4OffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemThumbRIs22_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemThumbRIs2Operands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__AddrMode33_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addAddrMode3Operands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__imm_0__AddrMode33_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_imm_0, 0, CVT_95_addAddrMode3Operands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemNoOffset1_2__Tie1__AM3Offset2_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemNoOffsetOperands, 3, CVT_Tied, 1, CVT_95_addAM3OffsetOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxReg2_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemNoOffsetOperands, 3, CVT_Tied, 1, CVT_95_addPostIdxRegOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxImm81_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemNoOffsetOperands, 3, CVT_Tied, 1, CVT_95_addPostIdxImm8Operands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__CCOut1_0__Reg1_2__Imm0_311_3__CondCode2_1
  { CVT_95_Reg, 3, CVT_95_addCCOutOperands, 1, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_Done },
  // Convert__Reg1_2__Reg1_2__Imm0_311_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_3__Imm0_311_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__CCOut1_0__Reg1_3__Imm0_311_4__CondCode2_1
  { CVT_95_Reg, 3, CVT_95_addCCOutOperands, 1, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Imm0_311_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_4__Imm0_311_5__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__CoprocNum1_1__Imm0_71_2__Reg1_3__CoprocReg1_4__CoprocReg1_5__imm_0__CondCode2_0
  { CVT_95_addCoprocNumOperands, 2, CVT_95_addImmOperands, 3, CVT_95_Reg, 4, CVT_95_addCoprocRegOperands, 5, CVT_95_addCoprocRegOperands, 6, CVT_imm_0, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__CoprocNum1_1__Imm0_71_2__Reg1_3__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0
  { CVT_95_addCoprocNumOperands, 2, CVT_95_addImmOperands, 3, CVT_95_Reg, 4, CVT_95_addCoprocRegOperands, 5, CVT_95_addCoprocRegOperands, 6, CVT_95_addImmOperands, 7, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__CoprocNum1_0__Imm0_71_1__Reg1_2__CoprocReg1_3__CoprocReg1_4__imm_0
  { CVT_95_addCoprocNumOperands, 1, CVT_95_addImmOperands, 2, CVT_95_Reg, 3, CVT_95_addCoprocRegOperands, 4, CVT_95_addCoprocRegOperands, 5, CVT_imm_0, 0, CVT_Done },
  // Convert__CoprocNum1_0__Imm0_71_1__Reg1_2__CoprocReg1_3__CoprocReg1_4__Imm0_71_5
  { CVT_95_addCoprocNumOperands, 1, CVT_95_addImmOperands, 2, CVT_95_Reg, 3, CVT_95_addCoprocRegOperands, 4, CVT_95_addCoprocRegOperands, 5, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__CoprocNum1_1__Imm0_151_2__Reg1_3__Reg1_4__CoprocReg1_5__CondCode2_0
  { CVT_95_addCoprocNumOperands, 2, CVT_95_addImmOperands, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addCoprocRegOperands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__CoprocNum1_0__Imm0_151_1__Reg1_2__Reg1_3__CoprocReg1_4
  { CVT_95_addCoprocNumOperands, 1, CVT_95_addImmOperands, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addCoprocRegOperands, 5, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_Reg, 6, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_1__Imm256_65535Expr1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__T2SOImm1_2__CondCode2_0__reg0
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_reg0, 0, CVT_Done },
  // Convert__Reg1_1__T2SOImmNot1_2__CondCode2_0__reg0
  { CVT_95_Reg, 2, CVT_95_addT2SOImmNotOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_reg0, 0, CVT_Done },
  // Convert__Reg1_1__Imm0_65535Expr1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__CCOut1_0__Imm0_2551_3__CondCode2_1
  { CVT_95_Reg, 3, CVT_95_addCCOutOperands, 1, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_Done },
  // Convert__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__ARMSOImmNot1_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_addARMSOImmNotOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_addRegShiftedRegOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_addRegShiftedImmOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__T2SOImm1_3__CondCode2_0__reg0
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_reg0, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_3__CondCode2_0__reg0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 1, CVT_reg0, 0, CVT_Done },
  // Convert__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_0__Reg1_1
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__Reg1_0__regCPSR__Imm0_2551_1__imm_14__imm_0
  { CVT_95_Reg, 1, CVT_regCPSR, 0, CVT_95_addImmOperands, 2, CVT_imm_14, 0, CVT_imm_0, 0, CVT_Done },
  // Convert__Reg1_1__T2SOImm1_2__CondCode2_0__regCPSR
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_regCPSR, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_2__CondCode2_0__regCPSR
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addCondCodeOperands, 1, CVT_regCPSR, 0, CVT_Done },
  // Convert__Reg1_2__T2SOImm1_3__CondCode2_0__regCPSR
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_regCPSR, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_3__CondCode2_0__regCPSR
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 1, CVT_regCPSR, 0, CVT_Done },
  // Convert__Reg1_1__Tie0__Imm0_65535Expr1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__CoprocNum1_1__Imm0_71_2__CoprocReg1_4__CoprocReg1_5__imm_0__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_addCoprocNumOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addCoprocRegOperands, 5, CVT_95_addCoprocRegOperands, 6, CVT_imm_0, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__CoprocNum1_1__Imm0_71_2__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_addCoprocNumOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addCoprocRegOperands, 5, CVT_95_addCoprocRegOperands, 6, CVT_95_addImmOperands, 7, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__CoprocNum1_0__Imm0_71_1__CoprocReg1_3__CoprocReg1_4__imm_0
  { CVT_95_Reg, 3, CVT_95_addCoprocNumOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addCoprocRegOperands, 4, CVT_95_addCoprocRegOperands, 5, CVT_imm_0, 0, CVT_Done },
  // Convert__Reg1_2__CoprocNum1_0__Imm0_71_1__CoprocReg1_3__CoprocReg1_4__Imm0_71_5
  { CVT_95_Reg, 3, CVT_95_addCoprocNumOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addCoprocRegOperands, 4, CVT_95_addCoprocRegOperands, 5, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__Reg1_1__MSRMask1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMSRMaskOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MSRMask1_1__Reg1_2__CondCode2_0
  { CVT_95_addMSRMaskOperands, 2, CVT_95_Reg, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MSRMask1_1__ARMSOImm1_2__CondCode2_0
  { CVT_95_addMSRMaskOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_1__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // ConvertCustom_cvtThumbMultiply
  { CVT_cvtThumbMultiply, 0, CVT_Done },
  // Convert__Reg1_2__CCOut1_0__Reg1_3__CondCode2_1
  { CVT_95_Reg, 3, CVT_95_addCCOutOperands, 1, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 2, CVT_Done },
  // Convert__Reg1_2__T2SOImm1_3__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 4, CVT_95_addRegShiftedImmOperands, 5, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__imm_0__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_imm_0, 0, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__regR8__regR8__imm_14__imm_0
  { CVT_regR8, 0, CVT_regR8, 0, CVT_imm_14, 0, CVT_imm_0, 0, CVT_Done },
  // Convert__imm_0__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__regR0__regR0__CondCode2_0__reg0
  { CVT_regR0, 0, CVT_regR0, 0, CVT_95_addCondCodeOperands, 1, CVT_reg0, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_imm_0, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_3__PKHLSLImm1_4__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_3__PKHASRImm1_4__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addPKHASRImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemImm12Offset2_0
  { CVT_95_addMemImm12OffsetOperands, 1, CVT_Done },
  // Convert__MemRegOffset3_0
  { CVT_95_addMemRegOffsetOperands, 1, CVT_Done },
  // Convert__MemNegImm8Offset2_1__CondCode2_0
  { CVT_95_addMemNegImm8OffsetOperands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemUImm12Offset2_1__CondCode2_0
  { CVT_95_addMemUImm12OffsetOperands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__T2MemRegOffset3_1__CondCode2_0
  { CVT_95_addT2MemRegOffsetOperands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemPCRelImm121_1__CondCode2_0
  { CVT_95_addMemPCRelImm12Operands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__CondCode2_0__RegList1_1
  { CVT_95_addCondCodeOperands, 1, CVT_95_addRegListOperands, 2, CVT_Done },
  // Convert__regSP__Tie0__CondCode2_0__RegList1_1
  { CVT_regSP, 0, CVT_Tied, 0, CVT_95_addCondCodeOperands, 1, CVT_95_addRegListOperands, 2, CVT_Done },
  // Convert__regSP__Tie0__CondCode2_0__RegList1_2
  { CVT_regSP, 0, CVT_Tied, 0, CVT_95_addCondCodeOperands, 1, CVT_95_addRegListOperands, 3, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Imm0_311_3__Imm1_321_4__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addImm1_95_32Operands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__SetEndImm1_0
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__imm_4__CondCode2_0
  { CVT_imm_4, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_5__CondCode2_0
  { CVT_imm_5, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Tie0__Reg1_2__Reg1_3
  { CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__Tie0__Tie1__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_Tied, 0, CVT_Tied, 1, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Reg1_4__Reg1_5__Tie0__Tie1__CondCode2_1__CCOut1_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_Reg, 6, CVT_Tied, 0, CVT_Tied, 1, CVT_95_addCondCodeOperands, 2, CVT_95_addCCOutOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_4__Reg1_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Imm0_311_2
  { CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Imm0_311_1__CondCode2_0
  { CVT_95_addImmOperands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Imm0_311_2__CondCode2_0
  { CVT_95_addImmOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Imm0_311_3__CondCode2_0
  { CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Imm1_321_2__Reg1_3__imm_0__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addImm1_95_32Operands, 3, CVT_95_Reg, 4, CVT_imm_0, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Imm1_321_2__Reg1_3__ShifterImm1_4__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addImm1_95_32Operands, 3, CVT_95_Reg, 4, CVT_95_addShifterImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Imm1_161_2__Reg1_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addImm1_95_16Operands, 3, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_3__MemNoOffset1_4__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addMemNoOffsetOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__Reg1_1__MemImm8Offset2_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_Reg, 2, CVT_95_addMemImm8OffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemNoOffset1_2__Reg1_1__Tie0__Imm1_3__CondCode2_0
  { CVT_95_addMemNoOffsetOperands, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__Reg1_1__MemImm12Offset2_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_Reg, 2, CVT_95_addMemImm12OffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemNoOffset1_2__Reg1_1__Tie0__AM2OffsetImm2_3__CondCode2_0
  { CVT_95_addMemNoOffsetOperands, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addAM2OffsetImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemNoOffset1_2__Reg1_1__Tie0__PostIdxRegShifted2_3__CondCode2_0
  { CVT_95_addMemNoOffsetOperands, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addPostIdxRegShiftedOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__Reg1_1__MemRegOffset3_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_Reg, 2, CVT_95_addMemRegOffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__MemImm8Offset2_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addMemImm8OffsetOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__Reg1_1__Reg1_2__MemImm8s4Offset2_3__CondCode2_0
  { CVT_imm_0, 0, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addMemImm8s4OffsetOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemNoOffset1_3__Reg1_1__Reg1_2__Tie0__Imm1_4__CondCode2_0
  { CVT_95_addMemNoOffsetOperands, 4, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__Reg1_1__Reg1_2__AddrMode33_3__CondCode2_0
  { CVT_imm_0, 0, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addAddrMode3Operands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemNoOffset1_3__Reg1_1__Reg1_2__Tie0__AM3Offset2_4__CondCode2_0
  { CVT_95_addMemNoOffsetOperands, 4, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addAM3OffsetOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__MemImm0_1020s4Offset2_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addMemImm0_95_1020s4OffsetOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__Reg1_1__AddrMode33_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_Reg, 2, CVT_95_addAddrMode3Operands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemNoOffset1_2__Reg1_1__Tie0__AM3Offset2_3__CondCode2_0
  { CVT_95_addMemNoOffsetOperands, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addAM3OffsetOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemNoOffset1_2__Reg1_1__Tie0__PostIdxImm81_3__CondCode2_0
  { CVT_95_addMemNoOffsetOperands, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addPostIdxImm8Operands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemNoOffset1_2__Reg1_1__Tie0__PostIdxReg2_3__CondCode2_0
  { CVT_95_addMemNoOffsetOperands, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addPostIdxRegOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Imm0_2551_3__CondCode2_0
  { CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Imm0_2551_1__CondCode2_0
  { CVT_95_addImmOperands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Imm24bit1_1__CondCode2_0
  { CVT_95_addImmOperands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addRotImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_imm_0, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__imm_0__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_imm_0, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addRotImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addRotImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemTBB2_1__CondCode2_0
  { CVT_95_addMemTBBOperands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__MemTBH2_1__CondCode2_0
  { CVT_95_addMemTBHOperands, 2, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Imm0_311_2__Reg1_3__imm_0__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_Reg, 4, CVT_imm_0, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Imm0_311_2__Reg1_3__ShifterImm1_4__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_Reg, 4, CVT_95_addShifterImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Imm0_151_2__Reg1_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Reg1_2__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_1__Reg1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__NEONi16splat1_3__Tie0__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addNEONi16splatOperands, 4, CVT_Tied, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__NEONi32splat1_3__Tie0__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addNEONi32splatOperands, 4, CVT_Tied, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Tie0__Reg1_2__Reg1_3__CondCode2_0
  { CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_4__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Tie0__FBits161_5__CondCode2_0
  { CVT_95_Reg, 4, CVT_Tied, 0, CVT_95_addFBits16Operands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Tie0__FBits321_5__CondCode2_0
  { CVT_95_Reg, 4, CVT_Tied, 0, CVT_95_addFBits32Operands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_4__Imm1_5__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_2__Reg1_3__VectorIndex161_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addVectorIndex16Operands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__VectorIndex321_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addVectorIndex32Operands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__VectorIndex81_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addVectorIndex8Operands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_31_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_151_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_11_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_71_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_31_5__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_151_5__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_11_5__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_71_5__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListDPairAllLanes1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListDPair1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListOneDAllLanes1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListOneD1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListOneDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListOneDWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListOneDByteIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListOneDAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListOneDAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListOneD1_2__imm_0__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListOneD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListOneDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeD1_2__imm_0__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListOneDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListOneDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__AlignedMemory2_8__Tie0__Imm1_5__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_addAlignedMemoryOperands, 9, CVT_Tied, 0, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__imm_0__AlignedMemory2_8__Imm1_9__Tie0__Imm1_5__CondCode2_0
  { CVT_95_Reg, 4, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 9, CVT_95_addImmOperands, 10, CVT_Tied, 0, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_8__Imm1_9__Tie0__Imm1_5__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_Reg, 9, CVT_95_addImmOperands, 10, CVT_Tied, 0, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListDPairSpacedAllLanes1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListDPairSpaced1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListTwoDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListTwoQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListTwoDWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListTwoQWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListTwoDByteIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListDPairSpacedAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListDPairSpacedAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListDPairSpaced1_2__imm_0__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListDPairSpaced1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListTwoDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListTwoQHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListTwoDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListTwoQWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListTwoDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeDAllLanes1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeQAllLanes1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeDWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeQWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeDByteIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeDAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeQAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeQHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeQWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListThreeDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_4__Reg1_5__AlignedMemory2_7__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_Reg, 6, CVT_95_addAlignedMemoryOperands, 8, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_4__Reg1_5__imm_0__AlignedMemory2_7__Imm1_8__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_Reg, 6, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 8, CVT_95_addImmOperands, 9, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_6__Reg1_9__AlignedMemory2_13__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_Reg, 7, CVT_95_Reg, 10, CVT_95_addAlignedMemoryOperands, 14, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_6__Reg1_9__imm_0__AlignedMemory2_13__Imm1_14__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_Reg, 7, CVT_95_Reg, 10, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 14, CVT_95_addImmOperands, 15, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourDAllLanes1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourQAllLanes1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourDWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourQWordIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourDByteIndexed2_2__AlignedMemory2_3__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourDAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourQAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourQHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourQWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__VecListFourDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0
  { CVT_95_addVecListIndexedOperands, 3, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__AlignedMemory2_8__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_Reg, 6, CVT_95_Reg, 7, CVT_95_addAlignedMemoryOperands, 9, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__imm_0__AlignedMemory2_8__Imm1_9__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_Reg, 6, CVT_95_Reg, 7, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 9, CVT_95_addImmOperands, 10, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__AlignedMemory2_16__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_Reg, 7, CVT_95_Reg, 10, CVT_95_Reg, 13, CVT_95_addAlignedMemoryOperands, 17, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__imm_0__AlignedMemory2_16__Imm1_17__CondCode2_0
  { CVT_95_Reg, 4, CVT_95_Reg, 7, CVT_95_Reg, 10, CVT_95_Reg, 13, CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 17, CVT_95_addImmOperands, 18, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Tie0__CondCode2_0__SPRRegList1_3
  { CVT_95_Reg, 2, CVT_Tied, 0, CVT_95_addCondCodeOperands, 1, CVT_95_addSPRRegListOperands, 4, CVT_Done },
  // Convert__Reg1_1__CondCode2_0__SPRRegList1_2
  { CVT_95_Reg, 2, CVT_95_addCondCodeOperands, 1, CVT_95_addSPRRegListOperands, 3, CVT_Done },
  // Convert__Reg1_1__AddrMode52_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_addAddrMode5Operands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__AddrMode52_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addAddrMode5Operands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_3
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addVectorIndex32Operands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addVectorIndex16Operands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_2__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Reg1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__FPImm1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addFPImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__NEONi32vmov1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addNEONi32vmovOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__NEONi16splat1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addNEONi16splatOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__NEONi32vmovNeg1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addNEONi32vmovNegOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__NEONi64splat1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addNEONi64splatOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__NEONi8splat1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addNEONi8splatOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VectorIndex161_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorIndex16Operands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VectorIndex321_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorIndex32Operands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_4__VectorIndex81_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 5, CVT_95_addVectorIndex8Operands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__Reg1_3__VectorIndex321_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addVectorIndex32Operands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__Reg1_3__VectorIndex161_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addVectorIndex16Operands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addVectorIndex32Operands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_addVectorIndex16Operands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__regSP__Tie0__CondCode2_0__DPRRegList1_1
  { CVT_regSP, 0, CVT_Tied, 0, CVT_95_addCondCodeOperands, 1, CVT_95_addDPRRegListOperands, 2, CVT_Done },
  // Convert__regSP__Tie0__CondCode2_0__SPRRegList1_1
  { CVT_regSP, 0, CVT_Tied, 0, CVT_95_addCondCodeOperands, 1, CVT_95_addSPRRegListOperands, 2, CVT_Done },
  // Convert__regSP__Tie0__CondCode2_0__DPRRegList1_2
  { CVT_regSP, 0, CVT_Tied, 0, CVT_95_addCondCodeOperands, 1, CVT_95_addDPRRegListOperands, 3, CVT_Done },
  // Convert__regSP__Tie0__CondCode2_0__SPRRegList1_2
  { CVT_regSP, 0, CVT_Tied, 0, CVT_95_addCondCodeOperands, 1, CVT_95_addSPRRegListOperands, 3, CVT_Done },
  // Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__ShrImm161_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__ShrImm321_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__ShrImm641_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__ShrImm81_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__ShrImm641_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_2__ShrImm161_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_2__ShrImm321_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_2__ShrImm641_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_2__ShrImm81_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_3__ShrImm161_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_3__ShrImm321_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_3__ShrImm641_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_3__ShrImm81_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Imm1_151_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Imm161_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Imm321_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Imm1_71_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Imm81_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Imm1_311_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_2__Imm1_3__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__Reg1_3__Imm1_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_Reg, 4, CVT_95_addImmOperands, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__AlignedMemory2_3__VecListDPair1_2__CondCode2_0
  { CVT_95_addAlignedMemoryOperands, 4, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__AlignedMemory2_3__VecListFourD1_2__CondCode2_0
  { CVT_95_addAlignedMemoryOperands, 4, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__AlignedMemory2_3__VecListOneD1_2__CondCode2_0
  { CVT_95_addAlignedMemoryOperands, 4, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__AlignedMemory2_3__VecListThreeD1_2__CondCode2_0
  { CVT_95_addAlignedMemoryOperands, 4, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__AlignedMemory2_3__VecListDPair1_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPair1_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__AlignedMemory2_3__VecListFourD1_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListFourD1_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__AlignedMemory2_3__VecListOneD1_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListOneD1_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__AlignedMemory2_3__VecListThreeD1_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListThreeD1_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__AlignedMemory2_8__Reg1_3__Imm1_5__CondCode2_0
  { CVT_95_addAlignedMemoryOperands, 9, CVT_95_Reg, 4, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__AlignedMemory2_8__Imm1_9__Reg1_3__Imm1_5__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 9, CVT_95_addImmOperands, 10, CVT_95_Reg, 4, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_8__Imm1_9__Reg1_3__Imm1_5__CondCode2_0
  { CVT_95_Reg, 9, CVT_95_addImmOperands, 10, CVT_95_Reg, 4, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__Reg1_8__Imm1_9__Imm1_10__Reg1_3__Imm1_5__CondCode2_0
  { CVT_imm_0, 0, CVT_95_Reg, 9, CVT_95_addImmOperands, 10, CVT_95_addImmOperands, 11, CVT_95_Reg, 4, CVT_95_addImmOperands, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__AlignedMemory2_3__VecListDPairSpaced1_2__CondCode2_0
  { CVT_95_addAlignedMemoryOperands, 4, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__AlignedMemory2_3__VecListDPairSpaced1_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPairSpaced1_2__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 4, CVT_95_Reg, 5, CVT_95_addVecListOperands, 3, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__AlignedMemory2_7__Reg1_3__Reg1_4__Reg1_5__CondCode2_0
  { CVT_95_addAlignedMemoryOperands, 8, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_Reg, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__AlignedMemory2_7__Imm1_8__Reg1_3__Reg1_4__Reg1_5__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 8, CVT_95_addImmOperands, 9, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_Reg, 6, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__AlignedMemory2_8__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0
  { CVT_95_addAlignedMemoryOperands, 9, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_Reg, 6, CVT_95_Reg, 7, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_0__AlignedMemory2_8__Imm1_9__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0
  { CVT_imm_0, 0, CVT_95_addAlignedMemoryOperands, 9, CVT_95_addImmOperands, 10, CVT_95_Reg, 4, CVT_95_Reg, 5, CVT_95_Reg, 6, CVT_95_Reg, 7, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Tie0__Tie1__CondCode2_0
  { CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Tied, 0, CVT_Tied, 1, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_Reg, 4, CVT_Tied, 0, CVT_Tied, 1, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__VecListDPair1_3__Reg1_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addVecListOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__VecListFourD1_3__Reg1_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addVecListOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__VecListOneD1_3__Reg1_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addVecListOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__VecListThreeD1_3__Reg1_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_95_addVecListOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__VecListDPair1_3__Reg1_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addVecListOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__VecListFourD1_3__Reg1_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addVecListOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__VecListOneD1_3__Reg1_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addVecListOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__Reg1_2__Tie0__VecListThreeD1_3__Reg1_4__CondCode2_0
  { CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addVecListOperands, 4, CVT_95_Reg, 5, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_2__CondCode2_0
  { CVT_imm_2, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_3__CondCode2_0
  { CVT_imm_3, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
  // Convert__imm_1__CondCode2_0
  { CVT_imm_1, 0, CVT_95_addCondCodeOperands, 1, CVT_Done },
};

void ARMAsmParser::
convertToMCInst(unsigned Kind, MCInst &Inst, unsigned Opcode,
                const SmallVectorImpl<MCParsedAsmOperand*> &Operands) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  const uint8_t *Converter = ConversionTable[Kind];
  Inst.setOpcode(Opcode);
  for (const uint8_t *p = Converter; *p; p+= 2) {
    switch (*p) {
    default: llvm_unreachable("invalid conversion entry!");
    case CVT_Reg:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addRegOperands(Inst, 1);
      break;
    case CVT_Tied:
      Inst.addOperand(Inst.getOperand(*(p + 1)));
      break;
    case CVT_95_Reg:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addRegOperands(Inst, 1);
      break;
    case CVT_95_addCCOutOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addCCOutOperands(Inst, 1);
      break;
    case CVT_95_addCondCodeOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addCondCodeOperands(Inst, 2);
      break;
    case CVT_95_addRegShiftedRegOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addRegShiftedRegOperands(Inst, 3);
      break;
    case CVT_95_addImmOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addImmOperands(Inst, 1);
      break;
    case CVT_95_addRegShiftedImmOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addRegShiftedImmOperands(Inst, 2);
      break;
    case CVT_95_addImm0_95_508s4Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addImm0_508s4Operands(Inst, 1);
      break;
    case CVT_regSP:
      Inst.addOperand(MCOperand::CreateReg(ARM::SP));
      break;
    case CVT_95_addImm0_95_508s4NegOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addImm0_508s4NegOperands(Inst, 1);
      break;
    case CVT_95_addImm0_95_4095NegOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addImm0_4095NegOperands(Inst, 1);
      break;
    case CVT_95_addT2SOImmNegOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addT2SOImmNegOperands(Inst, 1);
      break;
    case CVT_95_addARMSOImmNegOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addARMSOImmNegOperands(Inst, 1);
      break;
    case CVT_95_addImm0_95_1020s4Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addImm0_1020s4Operands(Inst, 1);
      break;
    case CVT_95_addUnsignedOffset_95_b8s2Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addUnsignedOffset_b8s2Operands(Inst, 1);
      break;
    case CVT_95_addAdrLabelOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addAdrLabelOperands(Inst, 1);
      break;
    case CVT_95_addARMSOImmNotOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addARMSOImmNotOperands(Inst, 1);
      break;
    case CVT_95_addT2SOImmNotOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addT2SOImmNotOperands(Inst, 1);
      break;
    case CVT_95_addImmThumbSROperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addImmThumbSROperands(Inst, 1);
      break;
    case CVT_cvtThumbBranches:
      cvtThumbBranches(Inst, Operands);
      break;
    case CVT_95_addBitfieldOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addBitfieldOperands(Inst, 1);
      break;
    case CVT_95_addCoprocNumOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addCoprocNumOperands(Inst, 1);
      break;
    case CVT_95_addCoprocRegOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addCoprocRegOperands(Inst, 1);
      break;
    case CVT_imm_0:
      Inst.addOperand(MCOperand::CreateImm(0));
      break;
    case CVT_95_addProcIFlagsOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addProcIFlagsOperands(Inst, 1);
      break;
    case CVT_imm_15:
      Inst.addOperand(MCOperand::CreateImm(15));
      break;
    case CVT_95_addMemBarrierOptOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemBarrierOptOperands(Inst, 1);
      break;
    case CVT_95_addDPRRegListOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addDPRRegListOperands(Inst, 1);
      break;
    case CVT_imm_1:
      Inst.addOperand(MCOperand::CreateImm(1));
      break;
    case CVT_95_addInstSyncBarrierOptOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addInstSyncBarrierOptOperands(Inst, 1);
      break;
    case CVT_95_addITCondCodeOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addITCondCodeOperands(Inst, 1);
      break;
    case CVT_95_addITMaskOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addITMaskOperands(Inst, 1);
      break;
    case CVT_95_addMemNoOffsetOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemNoOffsetOperands(Inst, 1);
      break;
    case CVT_95_addAddrMode5Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addAddrMode5Operands(Inst, 2);
      break;
    case CVT_95_addCoprocOptionOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addCoprocOptionOperands(Inst, 1);
      break;
    case CVT_95_addPostIdxImm8s4Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addPostIdxImm8s4Operands(Inst, 1);
      break;
    case CVT_95_addRegListOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addRegListOperands(Inst, 1);
      break;
    case CVT_95_addThumbMemPCOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addThumbMemPCOperands(Inst, 1);
      break;
    case CVT_95_addMemThumbRIs4Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemThumbRIs4Operands(Inst, 2);
      break;
    case CVT_95_addMemThumbRROperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemThumbRROperands(Inst, 2);
      break;
    case CVT_95_addMemThumbSPIOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemThumbSPIOperands(Inst, 2);
      break;
    case CVT_95_addMemImm12OffsetOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemImm12OffsetOperands(Inst, 2);
      break;
    case CVT_95_addMemNegImm8OffsetOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemNegImm8OffsetOperands(Inst, 2);
      break;
    case CVT_95_addMemRegOffsetOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemRegOffsetOperands(Inst, 3);
      break;
    case CVT_95_addMemUImm12OffsetOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemUImm12OffsetOperands(Inst, 2);
      break;
    case CVT_95_addT2MemRegOffsetOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addT2MemRegOffsetOperands(Inst, 3);
      break;
    case CVT_95_addMemPCRelImm12Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemPCRelImm12Operands(Inst, 1);
      break;
    case CVT_95_addMemImm8OffsetOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemImm8OffsetOperands(Inst, 2);
      break;
    case CVT_95_addAM2OffsetImmOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addAM2OffsetImmOperands(Inst, 2);
      break;
    case CVT_95_addPostIdxRegShiftedOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addPostIdxRegShiftedOperands(Inst, 2);
      break;
    case CVT_95_addMemThumbRIs1Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemThumbRIs1Operands(Inst, 2);
      break;
    case CVT_95_addMemPosImm8OffsetOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemPosImm8OffsetOperands(Inst, 2);
      break;
    case CVT_95_addMemImm8s4OffsetOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemImm8s4OffsetOperands(Inst, 2);
      break;
    case CVT_95_addAddrMode3Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addAddrMode3Operands(Inst, 3);
      break;
    case CVT_95_addAM3OffsetOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addAM3OffsetOperands(Inst, 2);
      break;
    case CVT_95_addMemImm0_95_1020s4OffsetOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemImm0_1020s4OffsetOperands(Inst, 2);
      break;
    case CVT_95_addMemThumbRIs2Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemThumbRIs2Operands(Inst, 2);
      break;
    case CVT_95_addPostIdxRegOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addPostIdxRegOperands(Inst, 2);
      break;
    case CVT_95_addPostIdxImm8Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addPostIdxImm8Operands(Inst, 1);
      break;
    case CVT_reg0:
      Inst.addOperand(MCOperand::CreateReg(0));
      break;
    case CVT_regCPSR:
      Inst.addOperand(MCOperand::CreateReg(ARM::CPSR));
      break;
    case CVT_imm_14:
      Inst.addOperand(MCOperand::CreateImm(14));
      break;
    case CVT_95_addMSRMaskOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMSRMaskOperands(Inst, 1);
      break;
    case CVT_cvtThumbMultiply:
      cvtThumbMultiply(Inst, Operands);
      break;
    case CVT_regR8:
      Inst.addOperand(MCOperand::CreateReg(ARM::R8));
      break;
    case CVT_regR0:
      Inst.addOperand(MCOperand::CreateReg(ARM::R0));
      break;
    case CVT_95_addPKHASRImmOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addPKHASRImmOperands(Inst, 1);
      break;
    case CVT_95_addImm1_95_32Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addImm1_32Operands(Inst, 1);
      break;
    case CVT_imm_4:
      Inst.addOperand(MCOperand::CreateImm(4));
      break;
    case CVT_imm_5:
      Inst.addOperand(MCOperand::CreateImm(5));
      break;
    case CVT_95_addShifterImmOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addShifterImmOperands(Inst, 1);
      break;
    case CVT_95_addImm1_95_16Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addImm1_16Operands(Inst, 1);
      break;
    case CVT_95_addRotImmOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addRotImmOperands(Inst, 1);
      break;
    case CVT_95_addMemTBBOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemTBBOperands(Inst, 2);
      break;
    case CVT_95_addMemTBHOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addMemTBHOperands(Inst, 2);
      break;
    case CVT_95_addNEONi16splatOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addNEONi16splatOperands(Inst, 1);
      break;
    case CVT_95_addNEONi32splatOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addNEONi32splatOperands(Inst, 1);
      break;
    case CVT_95_addFBits16Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addFBits16Operands(Inst, 1);
      break;
    case CVT_95_addFBits32Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addFBits32Operands(Inst, 1);
      break;
    case CVT_95_addVectorIndex16Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addVectorIndex16Operands(Inst, 1);
      break;
    case CVT_95_addVectorIndex32Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addVectorIndex32Operands(Inst, 1);
      break;
    case CVT_95_addVectorIndex8Operands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addVectorIndex8Operands(Inst, 1);
      break;
    case CVT_95_addVecListOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addVecListOperands(Inst, 1);
      break;
    case CVT_95_addAlignedMemoryOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addAlignedMemoryOperands(Inst, 2);
      break;
    case CVT_95_addVecListIndexedOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addVecListIndexedOperands(Inst, 2);
      break;
    case CVT_95_addSPRRegListOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addSPRRegListOperands(Inst, 1);
      break;
    case CVT_95_addFPImmOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addFPImmOperands(Inst, 1);
      break;
    case CVT_95_addNEONi32vmovOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addNEONi32vmovOperands(Inst, 1);
      break;
    case CVT_95_addNEONi32vmovNegOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addNEONi32vmovNegOperands(Inst, 1);
      break;
    case CVT_95_addNEONi64splatOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addNEONi64splatOperands(Inst, 1);
      break;
    case CVT_95_addNEONi8splatOperands:
      static_cast<ARMOperand*>(Operands[*(p + 1)])->addNEONi8splatOperands(Inst, 1);
      break;
    case CVT_imm_2:
      Inst.addOperand(MCOperand::CreateImm(2));
      break;
    case CVT_imm_3:
      Inst.addOperand(MCOperand::CreateImm(3));
      break;
    }
  }
}

void ARMAsmParser::
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
    case CVT_95_addCCOutOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addCondCodeOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addRegShiftedRegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 3;
      break;
    case CVT_95_addImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegShiftedImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addImm0_95_508s4Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_regSP:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_95_addImm0_95_508s4NegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addImm0_95_4095NegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addT2SOImmNegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addARMSOImmNegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addImm0_95_1020s4Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addUnsignedOffset_95_b8s2Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addAdrLabelOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addARMSOImmNotOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addT2SOImmNotOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addImmThumbSROperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addBitfieldOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addCoprocNumOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addCoprocRegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addProcIFlagsOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_15:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addMemBarrierOptOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addDPRRegListOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_1:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addInstSyncBarrierOptOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addITCondCodeOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addITMaskOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addMemNoOffsetOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addAddrMode5Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addCoprocOptionOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addPostIdxImm8s4Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegListOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addThumbMemPCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addMemThumbRIs4Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMemThumbRROperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMemThumbSPIOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMemImm12OffsetOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMemNegImm8OffsetOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMemRegOffsetOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 3;
      break;
    case CVT_95_addMemUImm12OffsetOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addT2MemRegOffsetOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 3;
      break;
    case CVT_95_addMemPCRelImm12Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addMemImm8OffsetOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addAM2OffsetImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addPostIdxRegShiftedOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMemThumbRIs1Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMemPosImm8OffsetOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMemImm8s4OffsetOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addAddrMode3Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 3;
      break;
    case CVT_95_addAM3OffsetOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMemImm0_95_1020s4OffsetOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMemThumbRIs2Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addPostIdxRegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addPostIdxImm8Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_reg0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_regCPSR:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_imm_14:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addMSRMaskOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_regR8:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_regR0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_95_addPKHASRImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addImm1_95_32Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
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
    case CVT_95_addShifterImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addImm1_95_16Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRotImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addMemTBBOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMemTBHOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addNEONi16splatOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addNEONi32splatOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addFBits16Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addFBits32Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addVectorIndex16Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addVectorIndex32Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addVectorIndex8Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addVecListOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addAlignedMemoryOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addVecListIndexedOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addSPRRegListOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addFPImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addNEONi32vmovOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addNEONi32vmovNegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addNEONi64splatOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addNEONi8splatOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_2:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_3:
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
  MCK__35_0, // '#0'
  MCK__DOT_16, // '.16'
  MCK__DOT_8, // '.8'
  MCK__DOT_d, // '.d'
  MCK__DOT_f, // '.f'
  MCK__DOT_32, // '.32'
  MCK__DOT_64, // '.64'
  MCK__DOT_f16, // '.f16'
  MCK__DOT_f32, // '.f32'
  MCK__DOT_f64, // '.f64'
  MCK__DOT_i16, // '.i16'
  MCK__DOT_i32, // '.i32'
  MCK__DOT_i64, // '.i64'
  MCK__DOT_i8, // '.i8'
  MCK__DOT_p16, // '.p16'
  MCK__DOT_p64, // '.p64'
  MCK__DOT_p8, // '.p8'
  MCK__DOT_s16, // '.s16'
  MCK__DOT_s32, // '.s32'
  MCK__DOT_s64, // '.s64'
  MCK__DOT_s8, // '.s8'
  MCK__DOT_u16, // '.u16'
  MCK__DOT_u32, // '.u32'
  MCK__DOT_u64, // '.u64'
  MCK__DOT_u8, // '.u8'
  MCK__DOT_w, // '.w'
  MCK__91_, // '['
  MCK__93_, // ']'
  MCK__94_, // '^'
  MCK__123_, // '{'
  MCK__125_, // '}'
  MCK_Reg0, // derived register class
  MCK_tGPR, // register class 'tGPR'
  MCK_Reg10, // derived register class
  MCK_Reg9, // derived register class
  MCK_Reg7, // derived register class
  MCK_tcGPR, // register class 'tcGPR'
  MCK_rGPR, // register class 'rGPR'
  MCK_GPRsp, // register class 'GPRsp,SP'
  MCK_LR, // register class 'LR'
  MCK_GPRnopc, // register class 'GPRnopc'
  MCK_PC, // register class 'PC'
  MCK_hGPR, // register class 'hGPR'
  MCK_GPR, // register class 'GPR'
  MCK_SPR_8, // register class 'SPR_8'
  MCK_SPR, // register class 'SPR'
  MCK_DPR_8, // register class 'DPR_8'
  MCK_DPR_VFP2, // register class 'DPR_VFP2'
  MCK_DPR, // register class 'DPR'
  MCK_QPR_8, // register class 'QPR_8'
  MCK_Reg25, // derived register class
  MCK_Reg26, // derived register class
  MCK_QPR_VFP2, // register class 'QPR_VFP2'
  MCK_Reg23, // derived register class
  MCK_Reg24, // derived register class
  MCK_QPR, // register class 'QPR'
  MCK_DPair, // register class 'DPair'
  MCK_CCR, // register class 'CCR,CPSR'
  MCK_APSR, // register class 'APSR'
  MCK_APSR_NZCV, // register class 'APSR_NZCV'
  MCK_GPRwithAPSR, // register class 'GPRwithAPSR'
  MCK_SPSR, // register class 'SPSR'
  MCK_FPSCR, // register class 'FPSCR'
  MCK_FPSID, // register class 'FPSID'
  MCK_MVFR2, // register class 'MVFR2'
  MCK_MVFR1, // register class 'MVFR1'
  MCK_MVFR0, // register class 'MVFR0'
  MCK_FPEXC, // register class 'FPEXC'
  MCK_FPINST, // register class 'FPINST'
  MCK_FPINST2, // register class 'FPINST2'
  MCK_Reg39, // derived register class
  MCK_Reg40, // derived register class
  MCK_Reg41, // derived register class
  MCK_Reg42, // derived register class
  MCK_DPairSpc, // register class 'DPairSpc'
  MCK_Reg44, // derived register class
  MCK_Reg57, // derived register class
  MCK_Reg47, // derived register class
  MCK_Reg56, // derived register class
  MCK_Reg45, // derived register class
  MCK_Reg46, // derived register class
  MCK_Reg54, // derived register class
  MCK_Reg55, // derived register class
  MCK_Reg52, // derived register class
  MCK_Reg53, // derived register class
  MCK_Reg50, // derived register class
  MCK_Reg51, // derived register class
  MCK_QQPR, // register class 'QQPR'
  MCK_DQuad, // register class 'DQuad'
  MCK_Reg58, // derived register class
  MCK_Reg59, // derived register class
  MCK_Reg60, // derived register class
  MCK_Reg61, // derived register class
  MCK_Reg62, // derived register class
  MCK_Reg63, // derived register class
  MCK_Reg64, // derived register class
  MCK_Reg65, // derived register class
  MCK_QQQQPR, // register class 'QQQQPR'
  MCK_Reg67, // derived register class
  MCK_Reg68, // derived register class
  MCK_Reg72, // derived register class
  MCK_Reg69, // derived register class
  MCK_Reg74, // derived register class
  MCK_Reg71, // derived register class
  MCK_Reg73, // derived register class
  MCK_GPRPair, // register class 'GPRPair'
  MCK_Reg82, // derived register class
  MCK_Reg87, // derived register class
  MCK_Reg75, // derived register class
  MCK_Reg83, // derived register class
  MCK_Reg76, // derived register class
  MCK_Reg77, // derived register class
  MCK_Reg84, // derived register class
  MCK_Reg78, // derived register class
  MCK_Reg85, // derived register class
  MCK_Reg88, // derived register class
  MCK_Reg89, // derived register class
  MCK_Reg79, // derived register class
  MCK_Reg90, // derived register class
  MCK_Reg80, // derived register class
  MCK_Reg86, // derived register class
  MCK_Reg91, // derived register class
  MCK_DTriple, // register class 'DTriple'
  MCK_Reg92, // derived register class
  MCK_Reg93, // derived register class
  MCK_Reg94, // derived register class
  MCK_Reg95, // derived register class
  MCK_Reg96, // derived register class
  MCK_Reg97, // derived register class
  MCK_DTripleSpc, // register class 'DTripleSpc,DQuadSpc'
  MCK_Reg99, // derived register class
  MCK_Reg100, // derived register class
  MCK_Reg101, // derived register class
  MCK_Reg102, // derived register class
  MCK_Reg103, // derived register class
  MCK_Reg104, // derived register class
  MCK_Reg105, // derived register class
  MCK_AM2OffsetImm, // user defined class 'AM2OffsetImmAsmOperand'
  MCK_AM3Offset, // user defined class 'AM3OffsetAsmOperand'
  MCK_AddrMode2, // user defined class 'AddrMode2AsmOperand'
  MCK_AddrMode3, // user defined class 'AddrMode3AsmOperand'
  MCK_AddrMode5, // user defined class 'AddrMode5AsmOperand'
  MCK_AlignedMemory, // user defined class 'AddrMode6AsmOperand'
  MCK_AdrLabel, // user defined class 'AdrLabelAsmOperand'
  MCK_Bitfield, // user defined class 'BitfieldAsmOperand'
  MCK_CCOut, // user defined class 'CCOutOperand'
  MCK_CondCode, // user defined class 'CondCodeOperand'
  MCK_CoprocNum, // user defined class 'CoprocNumAsmOperand'
  MCK_CoprocOption, // user defined class 'CoprocOptionAsmOperand'
  MCK_CoprocReg, // user defined class 'CoprocRegAsmOperand'
  MCK_DPRRegList, // user defined class 'DPRRegListAsmOperand'
  MCK_FPImm, // user defined class 'FPImmOperand'
  MCK_Imm0_15, // user defined class 'Imm0_15AsmOperand'
  MCK_Imm0_1, // user defined class 'Imm0_1AsmOperand'
  MCK_Imm0_239, // user defined class 'Imm0_239AsmOperand'
  MCK_Imm0_255, // user defined class 'Imm0_255AsmOperand'
  MCK_Imm0_31, // user defined class 'Imm0_31AsmOperand'
  MCK_Imm0_32, // user defined class 'Imm0_32AsmOperand'
  MCK_Imm0_3, // user defined class 'Imm0_3AsmOperand'
  MCK_Imm0_63, // user defined class 'Imm0_63AsmOperand'
  MCK_Imm0_65535, // user defined class 'Imm0_65535AsmOperand'
  MCK_Imm0_65535Expr, // user defined class 'Imm0_65535ExprAsmOperand'
  MCK_Imm0_7, // user defined class 'Imm0_7AsmOperand'
  MCK_Imm16, // user defined class 'Imm16AsmOperand'
  MCK_Imm1_15, // user defined class 'Imm1_15AsmOperand'
  MCK_Imm1_16, // user defined class 'Imm1_16AsmOperand'
  MCK_Imm1_31, // user defined class 'Imm1_31AsmOperand'
  MCK_Imm1_32, // user defined class 'Imm1_32AsmOperand'
  MCK_Imm1_7, // user defined class 'Imm1_7AsmOperand'
  MCK_Imm24bit, // user defined class 'Imm24bitAsmOperand'
  MCK_Imm256_65535Expr, // user defined class 'Imm256_65535ExprAsmOperand'
  MCK_Imm32, // user defined class 'Imm32AsmOperand'
  MCK_Imm8, // user defined class 'Imm8AsmOperand'
  MCK_Imm, // user defined class 'ImmAsmOperand'
  MCK_InstSyncBarrierOpt, // user defined class 'InstSyncBarrierOptOperand'
  MCK_MSRMask, // user defined class 'MSRMaskOperand'
  MCK_MemBarrierOpt, // user defined class 'MemBarrierOptOperand'
  MCK_MemImm0_1020s4Offset, // user defined class 'MemImm0_1020s4OffsetAsmOperand'
  MCK_MemImm12Offset, // user defined class 'MemImm12OffsetAsmOperand'
  MCK_MemImm8Offset, // user defined class 'MemImm8OffsetAsmOperand'
  MCK_MemImm8s4Offset, // user defined class 'MemImm8s4OffsetAsmOperand'
  MCK_MemNegImm8Offset, // user defined class 'MemNegImm8OffsetAsmOperand'
  MCK_MemNoOffset, // user defined class 'MemNoOffsetAsmOperand'
  MCK_MemPosImm8Offset, // user defined class 'MemPosImm8OffsetAsmOperand'
  MCK_MemRegOffset, // user defined class 'MemRegOffsetAsmOperand'
  MCK_PKHASRImm, // user defined class 'PKHASRAsmOperand'
  MCK_PKHLSLImm, // user defined class 'PKHLSLAsmOperand'
  MCK_PostIdxImm8, // user defined class 'PostIdxImm8AsmOperand'
  MCK_PostIdxImm8s4, // user defined class 'PostIdxImm8s4AsmOperand'
  MCK_PostIdxReg, // user defined class 'PostIdxRegAsmOperand'
  MCK_PostIdxRegShifted, // user defined class 'PostIdxRegShiftedAsmOperand'
  MCK_ProcIFlags, // user defined class 'ProcIFlagsOperand'
  MCK_RegList, // user defined class 'RegListAsmOperand'
  MCK_RotImm, // user defined class 'RotImmAsmOperand'
  MCK_ARMSOImm, // user defined class 'SOImmAsmOperand'
  MCK_SPRRegList, // user defined class 'SPRRegListAsmOperand'
  MCK_SetEndImm, // user defined class 'SetEndAsmOperand'
  MCK_RegShiftedImm, // user defined class 'ShiftedImmAsmOperand'
  MCK_RegShiftedReg, // user defined class 'ShiftedRegAsmOperand'
  MCK_ShifterImm, // user defined class 'ShifterImmAsmOperand'
  MCK_ThumbMemPC, // user defined class 'ThumbMemPC'
  MCK_ImmThumbSR, // user defined class 'ThumbSRImmAsmOperand'
  MCK_UnsignedOffset_b8s2, // user defined class 'UnsignedOffset_b8s2'
  MCK_VecListDPairAllLanes, // user defined class 'VecListDPairAllLanesAsmOperand'
  MCK_VecListDPair, // user defined class 'VecListDPairAsmOperand'
  MCK_VecListDPairSpacedAllLanes, // user defined class 'VecListDPairSpacedAllLanesAsmOperand'
  MCK_VecListDPairSpaced, // user defined class 'VecListDPairSpacedAsmOperand'
  MCK_VecListFourDAllLanes, // user defined class 'VecListFourDAllLanesAsmOperand'
  MCK_VecListFourD, // user defined class 'VecListFourDAsmOperand'
  MCK_VecListFourDByteIndexed, // user defined class 'VecListFourDByteIndexAsmOperand'
  MCK_VecListFourDHWordIndexed, // user defined class 'VecListFourDHWordIndexAsmOperand'
  MCK_VecListFourDWordIndexed, // user defined class 'VecListFourDWordIndexAsmOperand'
  MCK_VecListFourQAllLanes, // user defined class 'VecListFourQAllLanesAsmOperand'
  MCK_VecListFourQ, // user defined class 'VecListFourQAsmOperand'
  MCK_VecListFourQHWordIndexed, // user defined class 'VecListFourQHWordIndexAsmOperand'
  MCK_VecListFourQWordIndexed, // user defined class 'VecListFourQWordIndexAsmOperand'
  MCK_VecListOneDAllLanes, // user defined class 'VecListOneDAllLanesAsmOperand'
  MCK_VecListOneD, // user defined class 'VecListOneDAsmOperand'
  MCK_VecListOneDByteIndexed, // user defined class 'VecListOneDByteIndexAsmOperand'
  MCK_VecListOneDHWordIndexed, // user defined class 'VecListOneDHWordIndexAsmOperand'
  MCK_VecListOneDWordIndexed, // user defined class 'VecListOneDWordIndexAsmOperand'
  MCK_VecListThreeDAllLanes, // user defined class 'VecListThreeDAllLanesAsmOperand'
  MCK_VecListThreeD, // user defined class 'VecListThreeDAsmOperand'
  MCK_VecListThreeDByteIndexed, // user defined class 'VecListThreeDByteIndexAsmOperand'
  MCK_VecListThreeDHWordIndexed, // user defined class 'VecListThreeDHWordIndexAsmOperand'
  MCK_VecListThreeDWordIndexed, // user defined class 'VecListThreeDWordIndexAsmOperand'
  MCK_VecListThreeQAllLanes, // user defined class 'VecListThreeQAllLanesAsmOperand'
  MCK_VecListThreeQ, // user defined class 'VecListThreeQAsmOperand'
  MCK_VecListThreeQHWordIndexed, // user defined class 'VecListThreeQHWordIndexAsmOperand'
  MCK_VecListThreeQWordIndexed, // user defined class 'VecListThreeQWordIndexAsmOperand'
  MCK_VecListTwoDByteIndexed, // user defined class 'VecListTwoDByteIndexAsmOperand'
  MCK_VecListTwoDHWordIndexed, // user defined class 'VecListTwoDHWordIndexAsmOperand'
  MCK_VecListTwoDWordIndexed, // user defined class 'VecListTwoDWordIndexAsmOperand'
  MCK_VecListTwoQHWordIndexed, // user defined class 'VecListTwoQHWordIndexAsmOperand'
  MCK_VecListTwoQWordIndexed, // user defined class 'VecListTwoQWordIndexAsmOperand'
  MCK_VectorIndex16, // user defined class 'VectorIndex16Operand'
  MCK_VectorIndex32, // user defined class 'VectorIndex32Operand'
  MCK_VectorIndex8, // user defined class 'VectorIndex8Operand'
  MCK_MemTBB, // user defined class 'addrmode_tbb_asmoperand'
  MCK_MemTBH, // user defined class 'addrmode_tbh_asmoperand'
  MCK_FBits16, // user defined class 'fbits16_asm_operand'
  MCK_FBits32, // user defined class 'fbits32_asm_operand'
  MCK_Imm0_4095, // user defined class 'imm0_4095_asmoperand'
  MCK_Imm0_4095Neg, // user defined class 'imm0_4095_neg_asmoperand'
  MCK_ITMask, // user defined class 'it_mask_asmoperand'
  MCK_ITCondCode, // user defined class 'it_pred_asmoperand'
  MCK_NEONi16splat, // user defined class 'nImmSplatI16AsmOperand'
  MCK_NEONi32splat, // user defined class 'nImmSplatI32AsmOperand'
  MCK_NEONi64splat, // user defined class 'nImmSplatI64AsmOperand'
  MCK_NEONi8splat, // user defined class 'nImmSplatI8AsmOperand'
  MCK_NEONi32vmov, // user defined class 'nImmVMOVI32AsmOperand'
  MCK_NEONi32vmovNeg, // user defined class 'nImmVMOVI32NegAsmOperand'
  MCK_ShrImm16, // user defined class 'shr_imm16_asm_operand'
  MCK_ShrImm32, // user defined class 'shr_imm32_asm_operand'
  MCK_ShrImm64, // user defined class 'shr_imm64_asm_operand'
  MCK_ShrImm8, // user defined class 'shr_imm8_asm_operand'
  MCK_ARMSOImmNeg, // user defined class 'so_imm_neg_asmoperand'
  MCK_ARMSOImmNot, // user defined class 'so_imm_not_asmoperand'
  MCK_T2SOImm, // user defined class 't2_so_imm_asmoperand'
  MCK_T2SOImmNeg, // user defined class 't2_so_imm_neg_asmoperand'
  MCK_T2SOImmNot, // user defined class 't2_so_imm_not_asmoperand'
  MCK_MemUImm12Offset, // user defined class 't2addrmode_imm12_asmoperand'
  MCK_T2MemRegOffset, // user defined class 't2addrmode_so_reg_asmoperand'
  MCK_Imm8s4, // user defined class 't2am_imm8s4_offset_asmoperand'
  MCK_MemPCRelImm12, // user defined class 't2ldr_pcrel_imm12_asmoperand'
  MCK_MemThumbRIs1, // user defined class 't_addrmode_is1_asm_operand'
  MCK_MemThumbRIs2, // user defined class 't_addrmode_is2_asm_operand'
  MCK_MemThumbRIs4, // user defined class 't_addrmode_is4_asm_operand'
  MCK_MemThumbRR, // user defined class 't_addrmode_rr_asm_operand'
  MCK_MemThumbSPI, // user defined class 't_addrmode_sp_asm_operand'
  MCK_Imm0_1020s4, // user defined class 't_imm0_1020s4_asmoperand'
  MCK_Imm0_508s4, // user defined class 't_imm0_508s4_asmoperand'
  MCK_Imm0_508s4Neg, // user defined class 't_imm0_508s4_neg_asmoperand'
  NumMatchClassKinds
};

}

static MatchClassKind matchTokenString(StringRef Name) {
  switch (Name.size()) {
  default: break;
  case 1:	 // 6 strings to match.
    switch (Name[0]) {
    default: break;
    case '!':	 // 1 string to match.
      return MCK__EXCLAIM_;	 // "!"
    case '[':	 // 1 string to match.
      return MCK__91_;	 // "["
    case ']':	 // 1 string to match.
      return MCK__93_;	 // "]"
    case '^':	 // 1 string to match.
      return MCK__94_;	 // "^"
    case '{':	 // 1 string to match.
      return MCK__123_;	 // "{"
    case '}':	 // 1 string to match.
      return MCK__125_;	 // "}"
    }
    break;
  case 2:	 // 5 strings to match.
    switch (Name[0]) {
    default: break;
    case '#':	 // 1 string to match.
      if (Name[1] != '0')
        break;
      return MCK__35_0;	 // "#0"
    case '.':	 // 4 strings to match.
      switch (Name[1]) {
      default: break;
      case '8':	 // 1 string to match.
        return MCK__DOT_8;	 // ".8"
      case 'd':	 // 1 string to match.
        return MCK__DOT_d;	 // ".d"
      case 'f':	 // 1 string to match.
        return MCK__DOT_f;	 // ".f"
      case 'w':	 // 1 string to match.
        return MCK__DOT_w;	 // ".w"
      }
      break;
    }
    break;
  case 3:	 // 7 strings to match.
    if (Name[0] != '.')
      break;
    switch (Name[1]) {
    default: break;
    case '1':	 // 1 string to match.
      if (Name[2] != '6')
        break;
      return MCK__DOT_16;	 // ".16"
    case '3':	 // 1 string to match.
      if (Name[2] != '2')
        break;
      return MCK__DOT_32;	 // ".32"
    case '6':	 // 1 string to match.
      if (Name[2] != '4')
        break;
      return MCK__DOT_64;	 // ".64"
    case 'i':	 // 1 string to match.
      if (Name[2] != '8')
        break;
      return MCK__DOT_i8;	 // ".i8"
    case 'p':	 // 1 string to match.
      if (Name[2] != '8')
        break;
      return MCK__DOT_p8;	 // ".p8"
    case 's':	 // 1 string to match.
      if (Name[2] != '8')
        break;
      return MCK__DOT_s8;	 // ".s8"
    case 'u':	 // 1 string to match.
      if (Name[2] != '8')
        break;
      return MCK__DOT_u8;	 // ".u8"
    }
    break;
  case 4:	 // 14 strings to match.
    if (Name[0] != '.')
      break;
    switch (Name[1]) {
    default: break;
    case 'f':	 // 3 strings to match.
      switch (Name[2]) {
      default: break;
      case '1':	 // 1 string to match.
        if (Name[3] != '6')
          break;
        return MCK__DOT_f16;	 // ".f16"
      case '3':	 // 1 string to match.
        if (Name[3] != '2')
          break;
        return MCK__DOT_f32;	 // ".f32"
      case '6':	 // 1 string to match.
        if (Name[3] != '4')
          break;
        return MCK__DOT_f64;	 // ".f64"
      }
      break;
    case 'i':	 // 3 strings to match.
      switch (Name[2]) {
      default: break;
      case '1':	 // 1 string to match.
        if (Name[3] != '6')
          break;
        return MCK__DOT_i16;	 // ".i16"
      case '3':	 // 1 string to match.
        if (Name[3] != '2')
          break;
        return MCK__DOT_i32;	 // ".i32"
      case '6':	 // 1 string to match.
        if (Name[3] != '4')
          break;
        return MCK__DOT_i64;	 // ".i64"
      }
      break;
    case 'p':	 // 2 strings to match.
      switch (Name[2]) {
      default: break;
      case '1':	 // 1 string to match.
        if (Name[3] != '6')
          break;
        return MCK__DOT_p16;	 // ".p16"
      case '6':	 // 1 string to match.
        if (Name[3] != '4')
          break;
        return MCK__DOT_p64;	 // ".p64"
      }
      break;
    case 's':	 // 3 strings to match.
      switch (Name[2]) {
      default: break;
      case '1':	 // 1 string to match.
        if (Name[3] != '6')
          break;
        return MCK__DOT_s16;	 // ".s16"
      case '3':	 // 1 string to match.
        if (Name[3] != '2')
          break;
        return MCK__DOT_s32;	 // ".s32"
      case '6':	 // 1 string to match.
        if (Name[3] != '4')
          break;
        return MCK__DOT_s64;	 // ".s64"
      }
      break;
    case 'u':	 // 3 strings to match.
      switch (Name[2]) {
      default: break;
      case '1':	 // 1 string to match.
        if (Name[3] != '6')
          break;
        return MCK__DOT_u16;	 // ".u16"
      case '3':	 // 1 string to match.
        if (Name[3] != '2')
          break;
        return MCK__DOT_u32;	 // ".u32"
      case '6':	 // 1 string to match.
        if (Name[3] != '4')
          break;
        return MCK__DOT_u64;	 // ".u64"
      }
      break;
    }
    break;
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

  case MCK__DOT_d:
    switch (B) {
    default: return false;
    case MCK__DOT_64: return true;
    case MCK__DOT_f64: return true;
    }

  case MCK__DOT_f:
    switch (B) {
    default: return false;
    case MCK__DOT_32: return true;
    case MCK__DOT_f32: return true;
    }

  case MCK__DOT_f32:
    return B == MCK__DOT_32;

  case MCK__DOT_f64:
    return B == MCK__DOT_64;

  case MCK__DOT_i16:
    return B == MCK__DOT_16;

  case MCK__DOT_i32:
    return B == MCK__DOT_32;

  case MCK__DOT_i64:
    return B == MCK__DOT_64;

  case MCK__DOT_i8:
    return B == MCK__DOT_8;

  case MCK__DOT_p16:
    return B == MCK__DOT_16;

  case MCK__DOT_p8:
    return B == MCK__DOT_8;

  case MCK__DOT_s16:
    switch (B) {
    default: return false;
    case MCK__DOT_16: return true;
    case MCK__DOT_i16: return true;
    }

  case MCK__DOT_s32:
    switch (B) {
    default: return false;
    case MCK__DOT_32: return true;
    case MCK__DOT_i32: return true;
    }

  case MCK__DOT_s64:
    switch (B) {
    default: return false;
    case MCK__DOT_64: return true;
    case MCK__DOT_i64: return true;
    }

  case MCK__DOT_s8:
    switch (B) {
    default: return false;
    case MCK__DOT_8: return true;
    case MCK__DOT_i8: return true;
    }

  case MCK__DOT_u16:
    switch (B) {
    default: return false;
    case MCK__DOT_16: return true;
    case MCK__DOT_i16: return true;
    }

  case MCK__DOT_u32:
    switch (B) {
    default: return false;
    case MCK__DOT_32: return true;
    case MCK__DOT_i32: return true;
    }

  case MCK__DOT_u64:
    switch (B) {
    default: return false;
    case MCK__DOT_64: return true;
    case MCK__DOT_i64: return true;
    }

  case MCK__DOT_u8:
    switch (B) {
    default: return false;
    case MCK__DOT_8: return true;
    case MCK__DOT_i8: return true;
    }

  case MCK_Reg0:
    switch (B) {
    default: return false;
    case MCK_tGPR: return true;
    case MCK_tcGPR: return true;
    case MCK_rGPR: return true;
    case MCK_GPRnopc: return true;
    case MCK_GPR: return true;
    case MCK_GPRwithAPSR: return true;
    }

  case MCK_tGPR:
    switch (B) {
    default: return false;
    case MCK_rGPR: return true;
    case MCK_GPRnopc: return true;
    case MCK_GPR: return true;
    case MCK_GPRwithAPSR: return true;
    }

  case MCK_Reg10:
    switch (B) {
    default: return false;
    case MCK_Reg9: return true;
    case MCK_Reg7: return true;
    case MCK_tcGPR: return true;
    case MCK_rGPR: return true;
    case MCK_GPRnopc: return true;
    case MCK_hGPR: return true;
    case MCK_GPR: return true;
    case MCK_GPRwithAPSR: return true;
    }

  case MCK_Reg9:
    switch (B) {
    default: return false;
    case MCK_Reg7: return true;
    case MCK_rGPR: return true;
    case MCK_GPRnopc: return true;
    case MCK_hGPR: return true;
    case MCK_GPR: return true;
    case MCK_GPRwithAPSR: return true;
    }

  case MCK_Reg7:
    switch (B) {
    default: return false;
    case MCK_GPRnopc: return true;
    case MCK_hGPR: return true;
    case MCK_GPR: return true;
    case MCK_GPRwithAPSR: return true;
    }

  case MCK_tcGPR:
    switch (B) {
    default: return false;
    case MCK_rGPR: return true;
    case MCK_GPRnopc: return true;
    case MCK_GPR: return true;
    case MCK_GPRwithAPSR: return true;
    }

  case MCK_rGPR:
    switch (B) {
    default: return false;
    case MCK_GPRnopc: return true;
    case MCK_GPR: return true;
    case MCK_GPRwithAPSR: return true;
    }

  case MCK_GPRsp:
    switch (B) {
    default: return false;
    case MCK_Reg7: return true;
    case MCK_GPRnopc: return true;
    case MCK_hGPR: return true;
    case MCK_GPR: return true;
    case MCK_GPRwithAPSR: return true;
    }

  case MCK_LR:
    switch (B) {
    default: return false;
    case MCK_Reg9: return true;
    case MCK_Reg7: return true;
    case MCK_rGPR: return true;
    case MCK_GPRnopc: return true;
    case MCK_hGPR: return true;
    case MCK_GPR: return true;
    case MCK_GPRwithAPSR: return true;
    }

  case MCK_GPRnopc:
    switch (B) {
    default: return false;
    case MCK_GPR: return true;
    case MCK_GPRwithAPSR: return true;
    }

  case MCK_PC:
    switch (B) {
    default: return false;
    case MCK_hGPR: return true;
    case MCK_GPR: return true;
    }

  case MCK_hGPR:
    return B == MCK_GPR;

  case MCK_SPR_8:
    return B == MCK_SPR;

  case MCK_DPR_8:
    switch (B) {
    default: return false;
    case MCK_DPR_VFP2: return true;
    case MCK_DPR: return true;
    }

  case MCK_DPR_VFP2:
    return B == MCK_DPR;

  case MCK_QPR_8:
    switch (B) {
    default: return false;
    case MCK_Reg25: return true;
    case MCK_Reg26: return true;
    case MCK_QPR_VFP2: return true;
    case MCK_Reg23: return true;
    case MCK_Reg24: return true;
    case MCK_QPR: return true;
    case MCK_DPair: return true;
    }

  case MCK_Reg25:
    switch (B) {
    default: return false;
    case MCK_Reg26: return true;
    case MCK_Reg23: return true;
    case MCK_Reg24: return true;
    case MCK_DPair: return true;
    }

  case MCK_Reg26:
    switch (B) {
    default: return false;
    case MCK_Reg23: return true;
    case MCK_Reg24: return true;
    case MCK_DPair: return true;
    }

  case MCK_QPR_VFP2:
    switch (B) {
    default: return false;
    case MCK_Reg23: return true;
    case MCK_Reg24: return true;
    case MCK_QPR: return true;
    case MCK_DPair: return true;
    }

  case MCK_Reg23:
    switch (B) {
    default: return false;
    case MCK_Reg24: return true;
    case MCK_DPair: return true;
    }

  case MCK_Reg24:
    return B == MCK_DPair;

  case MCK_QPR:
    return B == MCK_DPair;

  case MCK_APSR_NZCV:
    return B == MCK_GPRwithAPSR;

  case MCK_Reg39:
    switch (B) {
    default: return false;
    case MCK_Reg40: return true;
    case MCK_Reg41: return true;
    case MCK_Reg42: return true;
    case MCK_DPairSpc: return true;
    }

  case MCK_Reg40:
    switch (B) {
    default: return false;
    case MCK_Reg41: return true;
    case MCK_Reg42: return true;
    case MCK_DPairSpc: return true;
    }

  case MCK_Reg41:
    switch (B) {
    default: return false;
    case MCK_Reg42: return true;
    case MCK_DPairSpc: return true;
    }

  case MCK_Reg42:
    return B == MCK_DPairSpc;

  case MCK_Reg44:
    switch (B) {
    default: return false;
    case MCK_Reg57: return true;
    case MCK_Reg47: return true;
    case MCK_Reg56: return true;
    case MCK_Reg45: return true;
    case MCK_Reg46: return true;
    case MCK_Reg54: return true;
    case MCK_Reg55: return true;
    case MCK_Reg52: return true;
    case MCK_Reg53: return true;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_QQPR: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg57:
    switch (B) {
    default: return false;
    case MCK_Reg54: return true;
    case MCK_Reg55: return true;
    case MCK_Reg52: return true;
    case MCK_Reg53: return true;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg47:
    switch (B) {
    default: return false;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_QQPR: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg56:
    switch (B) {
    default: return false;
    case MCK_Reg57: return true;
    case MCK_Reg54: return true;
    case MCK_Reg55: return true;
    case MCK_Reg52: return true;
    case MCK_Reg53: return true;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg45:
    switch (B) {
    default: return false;
    case MCK_Reg47: return true;
    case MCK_Reg46: return true;
    case MCK_Reg54: return true;
    case MCK_Reg55: return true;
    case MCK_Reg52: return true;
    case MCK_Reg53: return true;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_QQPR: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg46:
    switch (B) {
    default: return false;
    case MCK_Reg47: return true;
    case MCK_Reg52: return true;
    case MCK_Reg53: return true;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_QQPR: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg54:
    switch (B) {
    default: return false;
    case MCK_Reg55: return true;
    case MCK_Reg52: return true;
    case MCK_Reg53: return true;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg55:
    switch (B) {
    default: return false;
    case MCK_Reg52: return true;
    case MCK_Reg53: return true;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg52:
    switch (B) {
    default: return false;
    case MCK_Reg53: return true;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg53:
    switch (B) {
    default: return false;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg50:
    switch (B) {
    default: return false;
    case MCK_Reg51: return true;
    case MCK_DQuad: return true;
    }

  case MCK_Reg51:
    return B == MCK_DQuad;

  case MCK_QQPR:
    return B == MCK_DQuad;

  case MCK_Reg58:
    switch (B) {
    default: return false;
    case MCK_Reg59: return true;
    case MCK_Reg60: return true;
    case MCK_Reg61: return true;
    case MCK_Reg62: return true;
    case MCK_Reg63: return true;
    case MCK_Reg64: return true;
    case MCK_Reg65: return true;
    case MCK_QQQQPR: return true;
    }

  case MCK_Reg59:
    switch (B) {
    default: return false;
    case MCK_Reg60: return true;
    case MCK_Reg61: return true;
    case MCK_Reg62: return true;
    case MCK_Reg63: return true;
    case MCK_Reg64: return true;
    case MCK_Reg65: return true;
    case MCK_QQQQPR: return true;
    }

  case MCK_Reg60:
    switch (B) {
    default: return false;
    case MCK_Reg61: return true;
    case MCK_Reg62: return true;
    case MCK_Reg63: return true;
    case MCK_Reg64: return true;
    case MCK_Reg65: return true;
    case MCK_QQQQPR: return true;
    }

  case MCK_Reg61:
    switch (B) {
    default: return false;
    case MCK_Reg62: return true;
    case MCK_Reg63: return true;
    case MCK_Reg64: return true;
    case MCK_Reg65: return true;
    case MCK_QQQQPR: return true;
    }

  case MCK_Reg62:
    switch (B) {
    default: return false;
    case MCK_Reg63: return true;
    case MCK_Reg64: return true;
    case MCK_Reg65: return true;
    case MCK_QQQQPR: return true;
    }

  case MCK_Reg63:
    switch (B) {
    default: return false;
    case MCK_Reg64: return true;
    case MCK_Reg65: return true;
    case MCK_QQQQPR: return true;
    }

  case MCK_Reg64:
    switch (B) {
    default: return false;
    case MCK_Reg65: return true;
    case MCK_QQQQPR: return true;
    }

  case MCK_Reg65:
    return B == MCK_QQQQPR;

  case MCK_Reg67:
    switch (B) {
    default: return false;
    case MCK_Reg68: return true;
    case MCK_Reg69: return true;
    case MCK_Reg71: return true;
    case MCK_GPRPair: return true;
    }

  case MCK_Reg68:
    switch (B) {
    default: return false;
    case MCK_Reg69: return true;
    case MCK_GPRPair: return true;
    }

  case MCK_Reg72:
    switch (B) {
    default: return false;
    case MCK_Reg69: return true;
    case MCK_Reg73: return true;
    case MCK_GPRPair: return true;
    }

  case MCK_Reg69:
    return B == MCK_GPRPair;

  case MCK_Reg74:
    switch (B) {
    default: return false;
    case MCK_Reg71: return true;
    case MCK_Reg73: return true;
    case MCK_GPRPair: return true;
    }

  case MCK_Reg71:
    return B == MCK_GPRPair;

  case MCK_Reg73:
    return B == MCK_GPRPair;

  case MCK_Reg82:
    switch (B) {
    default: return false;
    case MCK_Reg75: return true;
    case MCK_Reg83: return true;
    case MCK_Reg76: return true;
    case MCK_Reg77: return true;
    case MCK_Reg84: return true;
    case MCK_Reg78: return true;
    case MCK_Reg85: return true;
    case MCK_Reg79: return true;
    case MCK_Reg80: return true;
    case MCK_Reg86: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg87:
    switch (B) {
    default: return false;
    case MCK_Reg75: return true;
    case MCK_Reg76: return true;
    case MCK_Reg77: return true;
    case MCK_Reg78: return true;
    case MCK_Reg88: return true;
    case MCK_Reg89: return true;
    case MCK_Reg79: return true;
    case MCK_Reg90: return true;
    case MCK_Reg80: return true;
    case MCK_Reg91: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg75:
    switch (B) {
    default: return false;
    case MCK_Reg76: return true;
    case MCK_Reg77: return true;
    case MCK_Reg78: return true;
    case MCK_Reg79: return true;
    case MCK_Reg80: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg83:
    switch (B) {
    default: return false;
    case MCK_Reg76: return true;
    case MCK_Reg77: return true;
    case MCK_Reg84: return true;
    case MCK_Reg78: return true;
    case MCK_Reg85: return true;
    case MCK_Reg79: return true;
    case MCK_Reg80: return true;
    case MCK_Reg86: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg76:
    switch (B) {
    default: return false;
    case MCK_Reg77: return true;
    case MCK_Reg78: return true;
    case MCK_Reg79: return true;
    case MCK_Reg80: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg77:
    switch (B) {
    default: return false;
    case MCK_Reg78: return true;
    case MCK_Reg79: return true;
    case MCK_Reg80: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg84:
    switch (B) {
    default: return false;
    case MCK_Reg78: return true;
    case MCK_Reg85: return true;
    case MCK_Reg79: return true;
    case MCK_Reg80: return true;
    case MCK_Reg86: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg78:
    switch (B) {
    default: return false;
    case MCK_Reg79: return true;
    case MCK_Reg80: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg85:
    switch (B) {
    default: return false;
    case MCK_Reg79: return true;
    case MCK_Reg80: return true;
    case MCK_Reg86: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg88:
    switch (B) {
    default: return false;
    case MCK_Reg77: return true;
    case MCK_Reg78: return true;
    case MCK_Reg89: return true;
    case MCK_Reg79: return true;
    case MCK_Reg90: return true;
    case MCK_Reg80: return true;
    case MCK_Reg91: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg89:
    switch (B) {
    default: return false;
    case MCK_Reg78: return true;
    case MCK_Reg79: return true;
    case MCK_Reg90: return true;
    case MCK_Reg80: return true;
    case MCK_Reg91: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg79:
    switch (B) {
    default: return false;
    case MCK_Reg80: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg90:
    switch (B) {
    default: return false;
    case MCK_Reg80: return true;
    case MCK_Reg91: return true;
    case MCK_DTriple: return true;
    }

  case MCK_Reg80:
    return B == MCK_DTriple;

  case MCK_Reg86:
    return B == MCK_DTriple;

  case MCK_Reg91:
    return B == MCK_DTriple;

  case MCK_Reg92:
    switch (B) {
    default: return false;
    case MCK_Reg93: return true;
    case MCK_Reg94: return true;
    case MCK_Reg95: return true;
    case MCK_Reg96: return true;
    case MCK_Reg97: return true;
    case MCK_DTripleSpc: return true;
    }

  case MCK_Reg93:
    switch (B) {
    default: return false;
    case MCK_Reg94: return true;
    case MCK_Reg95: return true;
    case MCK_Reg96: return true;
    case MCK_Reg97: return true;
    case MCK_DTripleSpc: return true;
    }

  case MCK_Reg94:
    switch (B) {
    default: return false;
    case MCK_Reg95: return true;
    case MCK_Reg96: return true;
    case MCK_Reg97: return true;
    case MCK_DTripleSpc: return true;
    }

  case MCK_Reg95:
    switch (B) {
    default: return false;
    case MCK_Reg96: return true;
    case MCK_Reg97: return true;
    case MCK_DTripleSpc: return true;
    }

  case MCK_Reg96:
    switch (B) {
    default: return false;
    case MCK_Reg97: return true;
    case MCK_DTripleSpc: return true;
    }

  case MCK_Reg97:
    return B == MCK_DTripleSpc;

  case MCK_Reg99:
    switch (B) {
    default: return false;
    case MCK_Reg57: return true;
    case MCK_Reg56: return true;
    case MCK_Reg54: return true;
    case MCK_Reg55: return true;
    case MCK_Reg52: return true;
    case MCK_Reg53: return true;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_DQuad: return true;
    case MCK_Reg100: return true;
    case MCK_Reg101: return true;
    case MCK_Reg102: return true;
    case MCK_Reg103: return true;
    case MCK_Reg104: return true;
    case MCK_Reg105: return true;
    }

  case MCK_Reg100:
    switch (B) {
    default: return false;
    case MCK_Reg57: return true;
    case MCK_Reg54: return true;
    case MCK_Reg55: return true;
    case MCK_Reg52: return true;
    case MCK_Reg53: return true;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_DQuad: return true;
    case MCK_Reg101: return true;
    case MCK_Reg102: return true;
    case MCK_Reg103: return true;
    case MCK_Reg104: return true;
    case MCK_Reg105: return true;
    }

  case MCK_Reg101:
    switch (B) {
    default: return false;
    case MCK_Reg55: return true;
    case MCK_Reg52: return true;
    case MCK_Reg53: return true;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_DQuad: return true;
    case MCK_Reg102: return true;
    case MCK_Reg103: return true;
    case MCK_Reg104: return true;
    case MCK_Reg105: return true;
    }

  case MCK_Reg102:
    switch (B) {
    default: return false;
    case MCK_Reg52: return true;
    case MCK_Reg53: return true;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_DQuad: return true;
    case MCK_Reg103: return true;
    case MCK_Reg104: return true;
    case MCK_Reg105: return true;
    }

  case MCK_Reg103:
    switch (B) {
    default: return false;
    case MCK_Reg53: return true;
    case MCK_Reg50: return true;
    case MCK_Reg51: return true;
    case MCK_DQuad: return true;
    case MCK_Reg104: return true;
    case MCK_Reg105: return true;
    }

  case MCK_Reg104:
    switch (B) {
    default: return false;
    case MCK_Reg51: return true;
    case MCK_DQuad: return true;
    case MCK_Reg105: return true;
    }

  case MCK_Reg105:
    return B == MCK_DQuad;
  }
}

static unsigned validateOperandClass(MCParsedAsmOperand *GOp, MatchClassKind Kind) {
  ARMOperand &Operand = *(ARMOperand*)GOp;
  if (Kind == InvalidMatchClass)
    return MCTargetAsmParser::Match_InvalidOperand;

  if (Operand.isToken())
    return isSubclass(matchTokenString(Operand.getToken()), Kind) ?
             MCTargetAsmParser::Match_Success :
             MCTargetAsmParser::Match_InvalidOperand;

  // 'AM2OffsetImm' class
  if (Kind == MCK_AM2OffsetImm) {
    if (Operand.isAM2OffsetImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'AM3Offset' class
  if (Kind == MCK_AM3Offset) {
    if (Operand.isAM3Offset())
      return MCTargetAsmParser::Match_Success;
  }

  // 'AddrMode2' class
  if (Kind == MCK_AddrMode2) {
    if (Operand.isAddrMode2())
      return MCTargetAsmParser::Match_Success;
  }

  // 'AddrMode3' class
  if (Kind == MCK_AddrMode3) {
    if (Operand.isAddrMode3())
      return MCTargetAsmParser::Match_Success;
  }

  // 'AddrMode5' class
  if (Kind == MCK_AddrMode5) {
    if (Operand.isAddrMode5())
      return MCTargetAsmParser::Match_Success;
  }

  // 'AlignedMemory' class
  if (Kind == MCK_AlignedMemory) {
    if (Operand.isAlignedMemory())
      return MCTargetAsmParser::Match_Success;
  }

  // 'AdrLabel' class
  if (Kind == MCK_AdrLabel) {
    if (Operand.isAdrLabel())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Bitfield' class
  if (Kind == MCK_Bitfield) {
    if (Operand.isBitfield())
      return MCTargetAsmParser::Match_Success;
  }

  // 'CCOut' class
  if (Kind == MCK_CCOut) {
    if (Operand.isCCOut())
      return MCTargetAsmParser::Match_Success;
  }

  // 'CondCode' class
  if (Kind == MCK_CondCode) {
    if (Operand.isCondCode())
      return MCTargetAsmParser::Match_Success;
  }

  // 'CoprocNum' class
  if (Kind == MCK_CoprocNum) {
    if (Operand.isCoprocNum())
      return MCTargetAsmParser::Match_Success;
  }

  // 'CoprocOption' class
  if (Kind == MCK_CoprocOption) {
    if (Operand.isCoprocOption())
      return MCTargetAsmParser::Match_Success;
  }

  // 'CoprocReg' class
  if (Kind == MCK_CoprocReg) {
    if (Operand.isCoprocReg())
      return MCTargetAsmParser::Match_Success;
  }

  // 'DPRRegList' class
  if (Kind == MCK_DPRRegList) {
    if (Operand.isDPRRegList())
      return MCTargetAsmParser::Match_Success;
  }

  // 'FPImm' class
  if (Kind == MCK_FPImm) {
    if (Operand.isFPImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_15' class
  if (Kind == MCK_Imm0_15) {
    if (Operand.isImm0_15())
      return MCTargetAsmParser::Match_Success;
    return ARMAsmParser::Match_ImmRange0_15;
  }

  // 'Imm0_1' class
  if (Kind == MCK_Imm0_1) {
    if (Operand.isImm0_1())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_239' class
  if (Kind == MCK_Imm0_239) {
    if (Operand.isImm0_239())
      return MCTargetAsmParser::Match_Success;
    return ARMAsmParser::Match_ImmRange0_239;
  }

  // 'Imm0_255' class
  if (Kind == MCK_Imm0_255) {
    if (Operand.isImm0_255())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_31' class
  if (Kind == MCK_Imm0_31) {
    if (Operand.isImm0_31())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_32' class
  if (Kind == MCK_Imm0_32) {
    if (Operand.isImm0_32())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_3' class
  if (Kind == MCK_Imm0_3) {
    if (Operand.isImm0_3())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_63' class
  if (Kind == MCK_Imm0_63) {
    if (Operand.isImm0_63())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_65535' class
  if (Kind == MCK_Imm0_65535) {
    if (Operand.isImm0_65535())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_65535Expr' class
  if (Kind == MCK_Imm0_65535Expr) {
    if (Operand.isImm0_65535Expr())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_7' class
  if (Kind == MCK_Imm0_7) {
    if (Operand.isImm0_7())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm16' class
  if (Kind == MCK_Imm16) {
    if (Operand.isImm16())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm1_15' class
  if (Kind == MCK_Imm1_15) {
    if (Operand.isImm1_15())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm1_16' class
  if (Kind == MCK_Imm1_16) {
    if (Operand.isImm1_16())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm1_31' class
  if (Kind == MCK_Imm1_31) {
    if (Operand.isImm1_31())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm1_32' class
  if (Kind == MCK_Imm1_32) {
    if (Operand.isImm1_32())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm1_7' class
  if (Kind == MCK_Imm1_7) {
    if (Operand.isImm1_7())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm24bit' class
  if (Kind == MCK_Imm24bit) {
    if (Operand.isImm24bit())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm256_65535Expr' class
  if (Kind == MCK_Imm256_65535Expr) {
    if (Operand.isImm256_65535Expr())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm32' class
  if (Kind == MCK_Imm32) {
    if (Operand.isImm32())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm8' class
  if (Kind == MCK_Imm8) {
    if (Operand.isImm8())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm' class
  if (Kind == MCK_Imm) {
    if (Operand.isImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'InstSyncBarrierOpt' class
  if (Kind == MCK_InstSyncBarrierOpt) {
    if (Operand.isInstSyncBarrierOpt())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MSRMask' class
  if (Kind == MCK_MSRMask) {
    if (Operand.isMSRMask())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemBarrierOpt' class
  if (Kind == MCK_MemBarrierOpt) {
    if (Operand.isMemBarrierOpt())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemImm0_1020s4Offset' class
  if (Kind == MCK_MemImm0_1020s4Offset) {
    if (Operand.isMemImm0_1020s4Offset())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemImm12Offset' class
  if (Kind == MCK_MemImm12Offset) {
    if (Operand.isMemImm12Offset())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemImm8Offset' class
  if (Kind == MCK_MemImm8Offset) {
    if (Operand.isMemImm8Offset())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemImm8s4Offset' class
  if (Kind == MCK_MemImm8s4Offset) {
    if (Operand.isMemImm8s4Offset())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemNegImm8Offset' class
  if (Kind == MCK_MemNegImm8Offset) {
    if (Operand.isMemNegImm8Offset())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemNoOffset' class
  if (Kind == MCK_MemNoOffset) {
    if (Operand.isMemNoOffset())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemPosImm8Offset' class
  if (Kind == MCK_MemPosImm8Offset) {
    if (Operand.isMemPosImm8Offset())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemRegOffset' class
  if (Kind == MCK_MemRegOffset) {
    if (Operand.isMemRegOffset())
      return MCTargetAsmParser::Match_Success;
  }

  // 'PKHASRImm' class
  if (Kind == MCK_PKHASRImm) {
    if (Operand.isPKHASRImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'PKHLSLImm' class
  if (Kind == MCK_PKHLSLImm) {
    if (Operand.isPKHLSLImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'PostIdxImm8' class
  if (Kind == MCK_PostIdxImm8) {
    if (Operand.isPostIdxImm8())
      return MCTargetAsmParser::Match_Success;
  }

  // 'PostIdxImm8s4' class
  if (Kind == MCK_PostIdxImm8s4) {
    if (Operand.isPostIdxImm8s4())
      return MCTargetAsmParser::Match_Success;
  }

  // 'PostIdxReg' class
  if (Kind == MCK_PostIdxReg) {
    if (Operand.isPostIdxReg())
      return MCTargetAsmParser::Match_Success;
  }

  // 'PostIdxRegShifted' class
  if (Kind == MCK_PostIdxRegShifted) {
    if (Operand.isPostIdxRegShifted())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ProcIFlags' class
  if (Kind == MCK_ProcIFlags) {
    if (Operand.isProcIFlags())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegList' class
  if (Kind == MCK_RegList) {
    if (Operand.isRegList())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RotImm' class
  if (Kind == MCK_RotImm) {
    if (Operand.isRotImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ARMSOImm' class
  if (Kind == MCK_ARMSOImm) {
    if (Operand.isARMSOImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'SPRRegList' class
  if (Kind == MCK_SPRRegList) {
    if (Operand.isSPRRegList())
      return MCTargetAsmParser::Match_Success;
  }

  // 'SetEndImm' class
  if (Kind == MCK_SetEndImm) {
    if (Operand.isSetEndImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegShiftedImm' class
  if (Kind == MCK_RegShiftedImm) {
    if (Operand.isRegShiftedImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegShiftedReg' class
  if (Kind == MCK_RegShiftedReg) {
    if (Operand.isRegShiftedReg())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ShifterImm' class
  if (Kind == MCK_ShifterImm) {
    if (Operand.isShifterImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ThumbMemPC' class
  if (Kind == MCK_ThumbMemPC) {
    if (Operand.isThumbMemPC())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ImmThumbSR' class
  if (Kind == MCK_ImmThumbSR) {
    if (Operand.isImmThumbSR())
      return MCTargetAsmParser::Match_Success;
  }

  // 'UnsignedOffset_b8s2' class
  if (Kind == MCK_UnsignedOffset_b8s2) {
    if (Operand.isUnsignedOffset<8, 2>())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListDPairAllLanes' class
  if (Kind == MCK_VecListDPairAllLanes) {
    if (Operand.isVecListDPairAllLanes())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListDPair' class
  if (Kind == MCK_VecListDPair) {
    if (Operand.isVecListDPair())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListDPairSpacedAllLanes' class
  if (Kind == MCK_VecListDPairSpacedAllLanes) {
    if (Operand.isVecListDPairSpacedAllLanes())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListDPairSpaced' class
  if (Kind == MCK_VecListDPairSpaced) {
    if (Operand.isVecListDPairSpaced())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListFourDAllLanes' class
  if (Kind == MCK_VecListFourDAllLanes) {
    if (Operand.isVecListFourDAllLanes())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListFourD' class
  if (Kind == MCK_VecListFourD) {
    if (Operand.isVecListFourD())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListFourDByteIndexed' class
  if (Kind == MCK_VecListFourDByteIndexed) {
    if (Operand.isVecListFourDByteIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListFourDHWordIndexed' class
  if (Kind == MCK_VecListFourDHWordIndexed) {
    if (Operand.isVecListFourDHWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListFourDWordIndexed' class
  if (Kind == MCK_VecListFourDWordIndexed) {
    if (Operand.isVecListFourDWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListFourQAllLanes' class
  if (Kind == MCK_VecListFourQAllLanes) {
    if (Operand.isVecListFourQAllLanes())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListFourQ' class
  if (Kind == MCK_VecListFourQ) {
    if (Operand.isVecListFourQ())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListFourQHWordIndexed' class
  if (Kind == MCK_VecListFourQHWordIndexed) {
    if (Operand.isVecListFourQHWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListFourQWordIndexed' class
  if (Kind == MCK_VecListFourQWordIndexed) {
    if (Operand.isVecListFourQWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListOneDAllLanes' class
  if (Kind == MCK_VecListOneDAllLanes) {
    if (Operand.isVecListOneDAllLanes())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListOneD' class
  if (Kind == MCK_VecListOneD) {
    if (Operand.isVecListOneD())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListOneDByteIndexed' class
  if (Kind == MCK_VecListOneDByteIndexed) {
    if (Operand.isVecListOneDByteIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListOneDHWordIndexed' class
  if (Kind == MCK_VecListOneDHWordIndexed) {
    if (Operand.isVecListOneDHWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListOneDWordIndexed' class
  if (Kind == MCK_VecListOneDWordIndexed) {
    if (Operand.isVecListOneDWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListThreeDAllLanes' class
  if (Kind == MCK_VecListThreeDAllLanes) {
    if (Operand.isVecListThreeDAllLanes())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListThreeD' class
  if (Kind == MCK_VecListThreeD) {
    if (Operand.isVecListThreeD())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListThreeDByteIndexed' class
  if (Kind == MCK_VecListThreeDByteIndexed) {
    if (Operand.isVecListThreeDByteIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListThreeDHWordIndexed' class
  if (Kind == MCK_VecListThreeDHWordIndexed) {
    if (Operand.isVecListThreeDHWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListThreeDWordIndexed' class
  if (Kind == MCK_VecListThreeDWordIndexed) {
    if (Operand.isVecListThreeDWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListThreeQAllLanes' class
  if (Kind == MCK_VecListThreeQAllLanes) {
    if (Operand.isVecListThreeQAllLanes())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListThreeQ' class
  if (Kind == MCK_VecListThreeQ) {
    if (Operand.isVecListThreeQ())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListThreeQHWordIndexed' class
  if (Kind == MCK_VecListThreeQHWordIndexed) {
    if (Operand.isVecListThreeQHWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListThreeQWordIndexed' class
  if (Kind == MCK_VecListThreeQWordIndexed) {
    if (Operand.isVecListThreeQWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListTwoDByteIndexed' class
  if (Kind == MCK_VecListTwoDByteIndexed) {
    if (Operand.isVecListTwoDByteIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListTwoDHWordIndexed' class
  if (Kind == MCK_VecListTwoDHWordIndexed) {
    if (Operand.isVecListTwoDHWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListTwoDWordIndexed' class
  if (Kind == MCK_VecListTwoDWordIndexed) {
    if (Operand.isVecListTwoDWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListTwoQHWordIndexed' class
  if (Kind == MCK_VecListTwoQHWordIndexed) {
    if (Operand.isVecListTwoQHWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VecListTwoQWordIndexed' class
  if (Kind == MCK_VecListTwoQWordIndexed) {
    if (Operand.isVecListTwoQWordIndexed())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VectorIndex16' class
  if (Kind == MCK_VectorIndex16) {
    if (Operand.isVectorIndex16())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VectorIndex32' class
  if (Kind == MCK_VectorIndex32) {
    if (Operand.isVectorIndex32())
      return MCTargetAsmParser::Match_Success;
  }

  // 'VectorIndex8' class
  if (Kind == MCK_VectorIndex8) {
    if (Operand.isVectorIndex8())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemTBB' class
  if (Kind == MCK_MemTBB) {
    if (Operand.isMemTBB())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemTBH' class
  if (Kind == MCK_MemTBH) {
    if (Operand.isMemTBH())
      return MCTargetAsmParser::Match_Success;
  }

  // 'FBits16' class
  if (Kind == MCK_FBits16) {
    if (Operand.isFBits16())
      return MCTargetAsmParser::Match_Success;
  }

  // 'FBits32' class
  if (Kind == MCK_FBits32) {
    if (Operand.isFBits32())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_4095' class
  if (Kind == MCK_Imm0_4095) {
    if (Operand.isImm0_4095())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_4095Neg' class
  if (Kind == MCK_Imm0_4095Neg) {
    if (Operand.isImm0_4095Neg())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ITMask' class
  if (Kind == MCK_ITMask) {
    if (Operand.isITMask())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ITCondCode' class
  if (Kind == MCK_ITCondCode) {
    if (Operand.isITCondCode())
      return MCTargetAsmParser::Match_Success;
  }

  // 'NEONi16splat' class
  if (Kind == MCK_NEONi16splat) {
    if (Operand.isNEONi16splat())
      return MCTargetAsmParser::Match_Success;
  }

  // 'NEONi32splat' class
  if (Kind == MCK_NEONi32splat) {
    if (Operand.isNEONi32splat())
      return MCTargetAsmParser::Match_Success;
  }

  // 'NEONi64splat' class
  if (Kind == MCK_NEONi64splat) {
    if (Operand.isNEONi64splat())
      return MCTargetAsmParser::Match_Success;
  }

  // 'NEONi8splat' class
  if (Kind == MCK_NEONi8splat) {
    if (Operand.isNEONi8splat())
      return MCTargetAsmParser::Match_Success;
  }

  // 'NEONi32vmov' class
  if (Kind == MCK_NEONi32vmov) {
    if (Operand.isNEONi32vmov())
      return MCTargetAsmParser::Match_Success;
  }

  // 'NEONi32vmovNeg' class
  if (Kind == MCK_NEONi32vmovNeg) {
    if (Operand.isNEONi32vmovNeg())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ShrImm16' class
  if (Kind == MCK_ShrImm16) {
    if (Operand.isShrImm16())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ShrImm32' class
  if (Kind == MCK_ShrImm32) {
    if (Operand.isShrImm32())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ShrImm64' class
  if (Kind == MCK_ShrImm64) {
    if (Operand.isShrImm64())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ShrImm8' class
  if (Kind == MCK_ShrImm8) {
    if (Operand.isShrImm8())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ARMSOImmNeg' class
  if (Kind == MCK_ARMSOImmNeg) {
    if (Operand.isARMSOImmNeg())
      return MCTargetAsmParser::Match_Success;
  }

  // 'ARMSOImmNot' class
  if (Kind == MCK_ARMSOImmNot) {
    if (Operand.isARMSOImmNot())
      return MCTargetAsmParser::Match_Success;
  }

  // 'T2SOImm' class
  if (Kind == MCK_T2SOImm) {
    if (Operand.isT2SOImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'T2SOImmNeg' class
  if (Kind == MCK_T2SOImmNeg) {
    if (Operand.isT2SOImmNeg())
      return MCTargetAsmParser::Match_Success;
  }

  // 'T2SOImmNot' class
  if (Kind == MCK_T2SOImmNot) {
    if (Operand.isT2SOImmNot())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemUImm12Offset' class
  if (Kind == MCK_MemUImm12Offset) {
    if (Operand.isMemUImm12Offset())
      return MCTargetAsmParser::Match_Success;
  }

  // 'T2MemRegOffset' class
  if (Kind == MCK_T2MemRegOffset) {
    if (Operand.isT2MemRegOffset())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm8s4' class
  if (Kind == MCK_Imm8s4) {
    if (Operand.isImm8s4())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemPCRelImm12' class
  if (Kind == MCK_MemPCRelImm12) {
    if (Operand.isMemPCRelImm12())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemThumbRIs1' class
  if (Kind == MCK_MemThumbRIs1) {
    if (Operand.isMemThumbRIs1())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemThumbRIs2' class
  if (Kind == MCK_MemThumbRIs2) {
    if (Operand.isMemThumbRIs2())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemThumbRIs4' class
  if (Kind == MCK_MemThumbRIs4) {
    if (Operand.isMemThumbRIs4())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemThumbRR' class
  if (Kind == MCK_MemThumbRR) {
    if (Operand.isMemThumbRR())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MemThumbSPI' class
  if (Kind == MCK_MemThumbSPI) {
    if (Operand.isMemThumbSPI())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_1020s4' class
  if (Kind == MCK_Imm0_1020s4) {
    if (Operand.isImm0_1020s4())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_508s4' class
  if (Kind == MCK_Imm0_508s4) {
    if (Operand.isImm0_508s4())
      return MCTargetAsmParser::Match_Success;
  }

  // 'Imm0_508s4Neg' class
  if (Kind == MCK_Imm0_508s4Neg) {
    if (Operand.isImm0_508s4Neg())
      return MCTargetAsmParser::Match_Success;
  }

  if (Operand.isReg()) {
    MatchClassKind OpKind;
    switch (Operand.getReg()) {
    default: OpKind = InvalidMatchClass; break;
    case ARM::R0: OpKind = MCK_Reg0; break;
    case ARM::R1: OpKind = MCK_Reg0; break;
    case ARM::R2: OpKind = MCK_Reg0; break;
    case ARM::R3: OpKind = MCK_Reg0; break;
    case ARM::R4: OpKind = MCK_tGPR; break;
    case ARM::R5: OpKind = MCK_tGPR; break;
    case ARM::R6: OpKind = MCK_tGPR; break;
    case ARM::R7: OpKind = MCK_tGPR; break;
    case ARM::R8: OpKind = MCK_Reg9; break;
    case ARM::R9: OpKind = MCK_Reg9; break;
    case ARM::R10: OpKind = MCK_Reg9; break;
    case ARM::R11: OpKind = MCK_Reg9; break;
    case ARM::R12: OpKind = MCK_Reg10; break;
    case ARM::SP: OpKind = MCK_GPRsp; break;
    case ARM::LR: OpKind = MCK_LR; break;
    case ARM::PC: OpKind = MCK_PC; break;
    case ARM::S0: OpKind = MCK_SPR_8; break;
    case ARM::S1: OpKind = MCK_SPR_8; break;
    case ARM::S2: OpKind = MCK_SPR_8; break;
    case ARM::S3: OpKind = MCK_SPR_8; break;
    case ARM::S4: OpKind = MCK_SPR_8; break;
    case ARM::S5: OpKind = MCK_SPR_8; break;
    case ARM::S6: OpKind = MCK_SPR_8; break;
    case ARM::S7: OpKind = MCK_SPR_8; break;
    case ARM::S8: OpKind = MCK_SPR_8; break;
    case ARM::S9: OpKind = MCK_SPR_8; break;
    case ARM::S10: OpKind = MCK_SPR_8; break;
    case ARM::S11: OpKind = MCK_SPR_8; break;
    case ARM::S12: OpKind = MCK_SPR_8; break;
    case ARM::S13: OpKind = MCK_SPR_8; break;
    case ARM::S14: OpKind = MCK_SPR_8; break;
    case ARM::S15: OpKind = MCK_SPR_8; break;
    case ARM::S16: OpKind = MCK_SPR; break;
    case ARM::S17: OpKind = MCK_SPR; break;
    case ARM::S18: OpKind = MCK_SPR; break;
    case ARM::S19: OpKind = MCK_SPR; break;
    case ARM::S20: OpKind = MCK_SPR; break;
    case ARM::S21: OpKind = MCK_SPR; break;
    case ARM::S22: OpKind = MCK_SPR; break;
    case ARM::S23: OpKind = MCK_SPR; break;
    case ARM::S24: OpKind = MCK_SPR; break;
    case ARM::S25: OpKind = MCK_SPR; break;
    case ARM::S26: OpKind = MCK_SPR; break;
    case ARM::S27: OpKind = MCK_SPR; break;
    case ARM::S28: OpKind = MCK_SPR; break;
    case ARM::S29: OpKind = MCK_SPR; break;
    case ARM::S30: OpKind = MCK_SPR; break;
    case ARM::S31: OpKind = MCK_SPR; break;
    case ARM::D0: OpKind = MCK_DPR_8; break;
    case ARM::D1: OpKind = MCK_DPR_8; break;
    case ARM::D2: OpKind = MCK_DPR_8; break;
    case ARM::D3: OpKind = MCK_DPR_8; break;
    case ARM::D4: OpKind = MCK_DPR_8; break;
    case ARM::D5: OpKind = MCK_DPR_8; break;
    case ARM::D6: OpKind = MCK_DPR_8; break;
    case ARM::D7: OpKind = MCK_DPR_8; break;
    case ARM::D8: OpKind = MCK_DPR_VFP2; break;
    case ARM::D9: OpKind = MCK_DPR_VFP2; break;
    case ARM::D10: OpKind = MCK_DPR_VFP2; break;
    case ARM::D11: OpKind = MCK_DPR_VFP2; break;
    case ARM::D12: OpKind = MCK_DPR_VFP2; break;
    case ARM::D13: OpKind = MCK_DPR_VFP2; break;
    case ARM::D14: OpKind = MCK_DPR_VFP2; break;
    case ARM::D15: OpKind = MCK_DPR_VFP2; break;
    case ARM::D16: OpKind = MCK_DPR; break;
    case ARM::D17: OpKind = MCK_DPR; break;
    case ARM::D18: OpKind = MCK_DPR; break;
    case ARM::D19: OpKind = MCK_DPR; break;
    case ARM::D20: OpKind = MCK_DPR; break;
    case ARM::D21: OpKind = MCK_DPR; break;
    case ARM::D22: OpKind = MCK_DPR; break;
    case ARM::D23: OpKind = MCK_DPR; break;
    case ARM::D24: OpKind = MCK_DPR; break;
    case ARM::D25: OpKind = MCK_DPR; break;
    case ARM::D26: OpKind = MCK_DPR; break;
    case ARM::D27: OpKind = MCK_DPR; break;
    case ARM::D28: OpKind = MCK_DPR; break;
    case ARM::D29: OpKind = MCK_DPR; break;
    case ARM::D30: OpKind = MCK_DPR; break;
    case ARM::D31: OpKind = MCK_DPR; break;
    case ARM::Q0: OpKind = MCK_QPR_8; break;
    case ARM::Q1: OpKind = MCK_QPR_8; break;
    case ARM::Q2: OpKind = MCK_QPR_8; break;
    case ARM::Q3: OpKind = MCK_QPR_8; break;
    case ARM::Q4: OpKind = MCK_QPR_VFP2; break;
    case ARM::Q5: OpKind = MCK_QPR_VFP2; break;
    case ARM::Q6: OpKind = MCK_QPR_VFP2; break;
    case ARM::Q7: OpKind = MCK_QPR_VFP2; break;
    case ARM::Q8: OpKind = MCK_QPR; break;
    case ARM::Q9: OpKind = MCK_QPR; break;
    case ARM::Q10: OpKind = MCK_QPR; break;
    case ARM::Q11: OpKind = MCK_QPR; break;
    case ARM::Q12: OpKind = MCK_QPR; break;
    case ARM::Q13: OpKind = MCK_QPR; break;
    case ARM::Q14: OpKind = MCK_QPR; break;
    case ARM::Q15: OpKind = MCK_QPR; break;
    case ARM::CPSR: OpKind = MCK_CCR; break;
    case ARM::APSR: OpKind = MCK_APSR; break;
    case ARM::APSR_NZCV: OpKind = MCK_APSR_NZCV; break;
    case ARM::SPSR: OpKind = MCK_SPSR; break;
    case ARM::FPSCR: OpKind = MCK_FPSCR; break;
    case ARM::FPSID: OpKind = MCK_FPSID; break;
    case ARM::MVFR2: OpKind = MCK_MVFR2; break;
    case ARM::MVFR1: OpKind = MCK_MVFR1; break;
    case ARM::MVFR0: OpKind = MCK_MVFR0; break;
    case ARM::FPEXC: OpKind = MCK_FPEXC; break;
    case ARM::FPINST: OpKind = MCK_FPINST; break;
    case ARM::FPINST2: OpKind = MCK_FPINST2; break;
    case ARM::D0_D2: OpKind = MCK_Reg39; break;
    case ARM::D1_D3: OpKind = MCK_Reg39; break;
    case ARM::D2_D4: OpKind = MCK_Reg39; break;
    case ARM::D3_D5: OpKind = MCK_Reg39; break;
    case ARM::D4_D6: OpKind = MCK_Reg39; break;
    case ARM::D5_D7: OpKind = MCK_Reg39; break;
    case ARM::D6_D8: OpKind = MCK_Reg40; break;
    case ARM::D7_D9: OpKind = MCK_Reg40; break;
    case ARM::D8_D10: OpKind = MCK_Reg41; break;
    case ARM::D9_D11: OpKind = MCK_Reg41; break;
    case ARM::D10_D12: OpKind = MCK_Reg41; break;
    case ARM::D11_D13: OpKind = MCK_Reg41; break;
    case ARM::D12_D14: OpKind = MCK_Reg41; break;
    case ARM::D13_D15: OpKind = MCK_Reg41; break;
    case ARM::D14_D16: OpKind = MCK_Reg42; break;
    case ARM::D15_D17: OpKind = MCK_Reg42; break;
    case ARM::D16_D18: OpKind = MCK_DPairSpc; break;
    case ARM::D17_D19: OpKind = MCK_DPairSpc; break;
    case ARM::D18_D20: OpKind = MCK_DPairSpc; break;
    case ARM::D19_D21: OpKind = MCK_DPairSpc; break;
    case ARM::D20_D22: OpKind = MCK_DPairSpc; break;
    case ARM::D21_D23: OpKind = MCK_DPairSpc; break;
    case ARM::D22_D24: OpKind = MCK_DPairSpc; break;
    case ARM::D23_D25: OpKind = MCK_DPairSpc; break;
    case ARM::D24_D26: OpKind = MCK_DPairSpc; break;
    case ARM::D25_D27: OpKind = MCK_DPairSpc; break;
    case ARM::D26_D28: OpKind = MCK_DPairSpc; break;
    case ARM::D27_D29: OpKind = MCK_DPairSpc; break;
    case ARM::D28_D30: OpKind = MCK_DPairSpc; break;
    case ARM::D29_D31: OpKind = MCK_DPairSpc; break;
    case ARM::Q0_Q1: OpKind = MCK_Reg44; break;
    case ARM::Q1_Q2: OpKind = MCK_Reg44; break;
    case ARM::Q2_Q3: OpKind = MCK_Reg44; break;
    case ARM::Q3_Q4: OpKind = MCK_Reg45; break;
    case ARM::Q4_Q5: OpKind = MCK_Reg46; break;
    case ARM::Q5_Q6: OpKind = MCK_Reg46; break;
    case ARM::Q6_Q7: OpKind = MCK_Reg46; break;
    case ARM::Q7_Q8: OpKind = MCK_Reg47; break;
    case ARM::Q8_Q9: OpKind = MCK_QQPR; break;
    case ARM::Q9_Q10: OpKind = MCK_QQPR; break;
    case ARM::Q10_Q11: OpKind = MCK_QQPR; break;
    case ARM::Q11_Q12: OpKind = MCK_QQPR; break;
    case ARM::Q12_Q13: OpKind = MCK_QQPR; break;
    case ARM::Q13_Q14: OpKind = MCK_QQPR; break;
    case ARM::Q14_Q15: OpKind = MCK_QQPR; break;
    case ARM::Q0_Q1_Q2_Q3: OpKind = MCK_Reg58; break;
    case ARM::Q1_Q2_Q3_Q4: OpKind = MCK_Reg59; break;
    case ARM::Q2_Q3_Q4_Q5: OpKind = MCK_Reg60; break;
    case ARM::Q3_Q4_Q5_Q6: OpKind = MCK_Reg61; break;
    case ARM::Q4_Q5_Q6_Q7: OpKind = MCK_Reg62; break;
    case ARM::Q5_Q6_Q7_Q8: OpKind = MCK_Reg63; break;
    case ARM::Q6_Q7_Q8_Q9: OpKind = MCK_Reg64; break;
    case ARM::Q7_Q8_Q9_Q10: OpKind = MCK_Reg65; break;
    case ARM::Q8_Q9_Q10_Q11: OpKind = MCK_QQQQPR; break;
    case ARM::Q9_Q10_Q11_Q12: OpKind = MCK_QQQQPR; break;
    case ARM::Q10_Q11_Q12_Q13: OpKind = MCK_QQQQPR; break;
    case ARM::Q11_Q12_Q13_Q14: OpKind = MCK_QQQQPR; break;
    case ARM::Q12_Q13_Q14_Q15: OpKind = MCK_QQQQPR; break;
    case ARM::R0_R1: OpKind = MCK_Reg67; break;
    case ARM::R2_R3: OpKind = MCK_Reg67; break;
    case ARM::R4_R5: OpKind = MCK_Reg68; break;
    case ARM::R6_R7: OpKind = MCK_Reg68; break;
    case ARM::R8_R9: OpKind = MCK_Reg72; break;
    case ARM::R10_R11: OpKind = MCK_Reg72; break;
    case ARM::R12_SP: OpKind = MCK_Reg74; break;
    case ARM::D0_D1_D2: OpKind = MCK_Reg82; break;
    case ARM::D1_D2_D3: OpKind = MCK_Reg87; break;
    case ARM::D2_D3_D4: OpKind = MCK_Reg82; break;
    case ARM::D3_D4_D5: OpKind = MCK_Reg87; break;
    case ARM::D4_D5_D6: OpKind = MCK_Reg82; break;
    case ARM::D5_D6_D7: OpKind = MCK_Reg87; break;
    case ARM::D6_D7_D8: OpKind = MCK_Reg83; break;
    case ARM::D7_D8_D9: OpKind = MCK_Reg88; break;
    case ARM::D8_D9_D10: OpKind = MCK_Reg84; break;
    case ARM::D9_D10_D11: OpKind = MCK_Reg89; break;
    case ARM::D10_D11_D12: OpKind = MCK_Reg84; break;
    case ARM::D11_D12_D13: OpKind = MCK_Reg89; break;
    case ARM::D12_D13_D14: OpKind = MCK_Reg84; break;
    case ARM::D13_D14_D15: OpKind = MCK_Reg89; break;
    case ARM::D14_D15_D16: OpKind = MCK_Reg85; break;
    case ARM::D15_D16_D17: OpKind = MCK_Reg90; break;
    case ARM::D16_D17_D18: OpKind = MCK_Reg86; break;
    case ARM::D17_D18_D19: OpKind = MCK_Reg91; break;
    case ARM::D18_D19_D20: OpKind = MCK_Reg86; break;
    case ARM::D19_D20_D21: OpKind = MCK_Reg91; break;
    case ARM::D20_D21_D22: OpKind = MCK_Reg86; break;
    case ARM::D21_D22_D23: OpKind = MCK_Reg91; break;
    case ARM::D22_D23_D24: OpKind = MCK_Reg86; break;
    case ARM::D23_D24_D25: OpKind = MCK_Reg91; break;
    case ARM::D24_D25_D26: OpKind = MCK_Reg86; break;
    case ARM::D25_D26_D27: OpKind = MCK_Reg91; break;
    case ARM::D26_D27_D28: OpKind = MCK_Reg86; break;
    case ARM::D27_D28_D29: OpKind = MCK_Reg91; break;
    case ARM::D28_D29_D30: OpKind = MCK_Reg86; break;
    case ARM::D29_D30_D31: OpKind = MCK_Reg91; break;
    case ARM::D0_D2_D4: OpKind = MCK_Reg92; break;
    case ARM::D1_D3_D5: OpKind = MCK_Reg92; break;
    case ARM::D2_D4_D6: OpKind = MCK_Reg92; break;
    case ARM::D3_D5_D7: OpKind = MCK_Reg92; break;
    case ARM::D4_D6_D8: OpKind = MCK_Reg93; break;
    case ARM::D5_D7_D9: OpKind = MCK_Reg93; break;
    case ARM::D6_D8_D10: OpKind = MCK_Reg94; break;
    case ARM::D7_D9_D11: OpKind = MCK_Reg94; break;
    case ARM::D8_D10_D12: OpKind = MCK_Reg95; break;
    case ARM::D9_D11_D13: OpKind = MCK_Reg95; break;
    case ARM::D10_D12_D14: OpKind = MCK_Reg95; break;
    case ARM::D11_D13_D15: OpKind = MCK_Reg95; break;
    case ARM::D12_D14_D16: OpKind = MCK_Reg96; break;
    case ARM::D13_D15_D17: OpKind = MCK_Reg96; break;
    case ARM::D14_D16_D18: OpKind = MCK_Reg97; break;
    case ARM::D15_D17_D19: OpKind = MCK_Reg97; break;
    case ARM::D16_D18_D20: OpKind = MCK_DTripleSpc; break;
    case ARM::D17_D19_D21: OpKind = MCK_DTripleSpc; break;
    case ARM::D18_D20_D22: OpKind = MCK_DTripleSpc; break;
    case ARM::D19_D21_D23: OpKind = MCK_DTripleSpc; break;
    case ARM::D20_D22_D24: OpKind = MCK_DTripleSpc; break;
    case ARM::D21_D23_D25: OpKind = MCK_DTripleSpc; break;
    case ARM::D22_D24_D26: OpKind = MCK_DTripleSpc; break;
    case ARM::D23_D25_D27: OpKind = MCK_DTripleSpc; break;
    case ARM::D24_D26_D28: OpKind = MCK_DTripleSpc; break;
    case ARM::D25_D27_D29: OpKind = MCK_DTripleSpc; break;
    case ARM::D26_D28_D30: OpKind = MCK_DTripleSpc; break;
    case ARM::D27_D29_D31: OpKind = MCK_DTripleSpc; break;
    case ARM::D1_D2: OpKind = MCK_Reg25; break;
    case ARM::D3_D4: OpKind = MCK_Reg25; break;
    case ARM::D5_D6: OpKind = MCK_Reg25; break;
    case ARM::D7_D8: OpKind = MCK_Reg26; break;
    case ARM::D9_D10: OpKind = MCK_Reg23; break;
    case ARM::D11_D12: OpKind = MCK_Reg23; break;
    case ARM::D13_D14: OpKind = MCK_Reg23; break;
    case ARM::D15_D16: OpKind = MCK_Reg24; break;
    case ARM::D17_D18: OpKind = MCK_DPair; break;
    case ARM::D19_D20: OpKind = MCK_DPair; break;
    case ARM::D21_D22: OpKind = MCK_DPair; break;
    case ARM::D23_D24: OpKind = MCK_DPair; break;
    case ARM::D25_D26: OpKind = MCK_DPair; break;
    case ARM::D27_D28: OpKind = MCK_DPair; break;
    case ARM::D29_D30: OpKind = MCK_DPair; break;
    case ARM::D1_D2_D3_D4: OpKind = MCK_Reg99; break;
    case ARM::D3_D4_D5_D6: OpKind = MCK_Reg99; break;
    case ARM::D5_D6_D7_D8: OpKind = MCK_Reg100; break;
    case ARM::D7_D8_D9_D10: OpKind = MCK_Reg101; break;
    case ARM::D9_D10_D11_D12: OpKind = MCK_Reg102; break;
    case ARM::D11_D12_D13_D14: OpKind = MCK_Reg102; break;
    case ARM::D13_D14_D15_D16: OpKind = MCK_Reg103; break;
    case ARM::D15_D16_D17_D18: OpKind = MCK_Reg104; break;
    case ARM::D17_D18_D19_D20: OpKind = MCK_Reg105; break;
    case ARM::D19_D20_D21_D22: OpKind = MCK_Reg105; break;
    case ARM::D21_D22_D23_D24: OpKind = MCK_Reg105; break;
    case ARM::D23_D24_D25_D26: OpKind = MCK_Reg105; break;
    case ARM::D25_D26_D27_D28: OpKind = MCK_Reg105; break;
    case ARM::D27_D28_D29_D30: OpKind = MCK_Reg105; break;
    }
    return isSubclass(OpKind, Kind) ? MCTargetAsmParser::Match_Success :
                                      MCTargetAsmParser::Match_InvalidOperand;
  }

  return MCTargetAsmParser::Match_InvalidOperand;
}

unsigned ARMAsmParser::
ComputeAvailableFeatures(uint64_t FB) const {
  unsigned Features = 0;
  if (((FB & ARM::HasV4TOps) != 0))
    Features |= Feature_HasV4T;
  if (((FB & ARM::HasV5TEOps) != 0))
    Features |= Feature_HasV5TE;
  if (((FB & ARM::HasV6Ops) != 0))
    Features |= Feature_HasV6;
  if (((FB & ARM::HasV6MOps) != 0))
    Features |= Feature_HasV6M;
  if (((FB & ARM::HasV6T2Ops) != 0))
    Features |= Feature_HasV6T2;
  if (((FB & ARM::HasV7Ops) != 0))
    Features |= Feature_HasV7;
  if (((FB & ARM::HasV8Ops) != 0))
    Features |= Feature_HasV8;
  if (((FB & ARM::HasV8Ops) == 0))
    Features |= Feature_PreV8;
  if (((FB & ARM::FeatureVFP2) != 0))
    Features |= Feature_HasVFP2;
  if (((FB & ARM::FeatureVFP3) != 0))
    Features |= Feature_HasVFP3;
  if (((FB & ARM::FeatureVFP4) != 0))
    Features |= Feature_HasVFP4;
  if (((FB & ARM::FeatureVFPOnlySP) == 0))
    Features |= Feature_HasDPVFP;
  if (((FB & ARM::FeatureFPARMv8) != 0))
    Features |= Feature_HasFPARMv8;
  if (((FB & ARM::FeatureNEON) != 0))
    Features |= Feature_HasNEON;
  if (((FB & ARM::FeatureCrypto) != 0))
    Features |= Feature_HasCrypto;
  if (((FB & ARM::FeatureCRC) != 0))
    Features |= Feature_HasCRC;
  if (((FB & ARM::FeatureFP16) != 0))
    Features |= Feature_HasFP16;
  if (((FB & ARM::FeatureHWDiv) != 0))
    Features |= Feature_HasDivide;
  if (((FB & ARM::FeatureHWDivARM) != 0))
    Features |= Feature_HasDivideInARM;
  if (((FB & ARM::FeatureT2XtPk) != 0))
    Features |= Feature_HasT2ExtractPack;
  if (((FB & ARM::FeatureDSPThumb2) != 0))
    Features |= Feature_HasThumb2DSP;
  if (((FB & ARM::FeatureDB) != 0))
    Features |= Feature_HasDB;
  if (((FB & ARM::FeatureMP) != 0))
    Features |= Feature_HasMP;
  if (((FB & ARM::FeatureTrustZone) != 0))
    Features |= Feature_HasTrustZone;
  if (((FB & ARM::ModeThumb) != 0))
    Features |= Feature_IsThumb;
  if (((FB & ARM::ModeThumb) != 0) && ((FB & ARM::FeatureThumb2) != 0))
    Features |= Feature_IsThumb2;
  if (((FB & ARM::FeatureMClass) != 0))
    Features |= Feature_IsMClass;
  if (((FB & ARM::FeatureMClass) == 0))
    Features |= Feature_IsNotMClass;
  if (((FB & ARM::ModeThumb) == 0))
    Features |= Feature_IsARM;
  if (((FB & ARM::FeatureNaClTrap) != 0))
    Features |= Feature_UseNaClTrap;
  return Features;
}

static const char *const MnemonicTable =
    "\003adc\003add\004addw\003adr\004aesd\004aese\006aesimc\005aesmc\003and"
    "\003asr\001b\003bfc\003bfi\003bic\004bkpt\002bl\003blx\002bx\003bxj\004"
    "cbnz\003cbz\003cdp\004cdp2\005clrex\003clz\003cmn\003cmp\003cps\006crc3"
    "2b\007crc32cb\007crc32ch\007crc32cw\006crc32h\006crc32w\003dbg\005dcps1"
    "\005dcps2\005dcps3\003dmb\003dsb\003eor\005faddd\005fadds\006fcmpzd\006"
    "fcmpzs\007fldmdbx\007fldmiax\005fmdhr\005fmdlr\006fmstat\007fstmdbx\007"
    "fstmiax\005fsubd\005fsubs\004hint\003hlt\003isb\002it\003lda\004ldab\005"
    "ldaex\006ldaexb\006ldaexd\006ldaexh\004ldah\003ldc\004ldc2\005ldc2l\004"
    "ldcl\003ldm\005ldmda\005ldmdb\005ldmib\003ldr\004ldrb\005ldrbt\004ldrd\005"
    "ldrex\006ldrexb\006ldrexd\006ldrexh\004ldrh\005ldrht\005ldrsb\006ldrsbt"
    "\005ldrsh\006ldrsht\004ldrt\003lsl\003lsr\003mcr\004mcr2\004mcrr\005mcr"
    "r2\003mla\003mls\003mov\004movs\004movt\004movw\003mrc\004mrc2\004mrrc\005"
    "mrrc2\003mrs\003msr\003mul\003mvn\003neg\003nop\003orn\003orr\005pkhbt\005"
    "pkhtb\003pld\004pldw\003pli\003pop\004push\004qadd\006qadd16\005qadd8\004"
    "qasx\005qdadd\005qdsub\004qsax\004qsub\006qsub16\005qsub8\004rbit\003re"
    "v\005rev16\005revsh\005rfeda\005rfedb\005rfeia\005rfeib\003ror\003rrx\003"
    "rsb\003rsc\006sadd16\005sadd8\004sasx\003sbc\004sbfx\004sdiv\003sel\006"
    "setend\003sev\004sevl\005sha1c\005sha1h\005sha1m\005sha1p\007sha1su0\007"
    "sha1su1\007sha256h\010sha256h2\tsha256su0\tsha256su1\007shadd16\006shad"
    "d8\005shasx\005shsax\007shsub16\006shsub8\003smc\006smlabb\006smlabt\005"
    "smlad\006smladx\005smlal\007smlalbb\007smlalbt\006smlald\007smlaldx\007"
    "smlaltb\007smlaltt\006smlatb\006smlatt\006smlawb\006smlawt\005smlsd\006"
    "smlsdx\006smlsld\007smlsldx\005smmla\006smmlar\005smmls\006smmlsr\005sm"
    "mul\006smmulr\005smuad\006smuadx\006smulbb\006smulbt\005smull\006smultb"
    "\006smultt\006smulwb\006smulwt\005smusd\006smusdx\005srsda\005srsdb\005"
    "srsia\005srsib\004ssat\006ssat16\004ssax\006ssub16\005ssub8\003stc\004s"
    "tc2\005stc2l\004stcl\003stl\004stlb\005stlex\006stlexb\006stlexd\006stl"
    "exh\004stlh\003stm\005stmda\005stmdb\005stmib\003str\004strb\005strbt\004"
    "strd\005strex\006strexb\006strexd\006strexh\004strh\005strht\004strt\003"
    "sub\004subs\004subw\003svc\003swp\004swpb\005sxtab\007sxtab16\005sxtah\004"
    "sxtb\006sxtb16\004sxth\003tbb\003tbh\003teq\004trap\003tst\006uadd16\005"
    "uadd8\004uasx\004ubfx\004udiv\007uhadd16\006uhadd8\005uhasx\005uhsax\007"
    "uhsub16\006uhsub8\005umaal\005umlal\005umull\007uqadd16\006uqadd8\005uq"
    "asx\005uqsax\007uqsub16\006uqsub8\005usad8\006usada8\004usat\006usat16\004"
    "usax\006usub16\005usub8\005uxtab\007uxtab16\005uxtah\004uxtb\006uxtb16\004"
    "uxth\004vaba\005vabal\004vabd\005vabdl\004vabs\005vacge\005vacgt\005vac"
    "le\005vaclt\004vadd\006vaddhn\005vaddl\005vaddw\004vand\004vbic\004vbif"
    "\004vbit\004vbsl\004vceq\004vcge\004vcgt\004vcle\004vcls\004vclt\004vcl"
    "z\004vcmp\005vcmpe\004vcnt\004vcvt\005vcvta\005vcvtb\005vcvtm\005vcvtn\005"
    "vcvtp\005vcvtr\005vcvtt\004vdiv\004vdup\004veor\004vext\004vfma\004vfms"
    "\005vfnma\005vfnms\005vhadd\005vhsub\004vld1\004vld2\004vld3\004vld4\006"
    "vldmdb\006vldmia\004vldr\004vmax\006vmaxnm\004vmin\006vminnm\004vmla\005"
    "vmlal\004vmls\005vmlsl\004vmov\005vmovl\005vmovn\004vmrs\004vmsr\004vmu"
    "l\005vmull\004vmvn\004vneg\005vnmla\005vnmls\005vnmul\004vorn\004vorr\006"
    "vpadal\005vpadd\006vpaddl\005vpmax\005vpmin\004vpop\005vpush\005vqabs\005"
    "vqadd\007vqdmlal\007vqdmlsl\007vqdmulh\007vqdmull\006vqmovn\007vqmovun\005"
    "vqneg\010vqrdmulh\006vqrshl\007vqrshrn\010vqrshrun\005vqshl\006vqshlu\006"
    "vqshrn\007vqshrun\005vqsub\007vraddhn\006vrecpe\006vrecps\006vrev16\006"
    "vrev32\006vrev64\006vrhadd\006vrinta\006vrintm\006vrintn\006vrintp\006v"
    "rintr\006vrintx\006vrintz\005vrshl\005vrshr\006vrshrn\007vrsqrte\007vrs"
    "qrts\005vrsra\007vrsubhn\006vseleq\006vselge\006vselgt\006vselvs\004vsh"
    "l\005vshll\004vshr\005vshrn\004vsli\005vsqrt\004vsra\004vsri\004vst1\004"
    "vst2\004vst3\004vst4\006vstmdb\006vstmia\004vstr\004vsub\006vsubhn\005v"
    "subl\005vsubw\004vswp\004vtbl\004vtbx\004vtrn\004vtst\004vuzp\004vzip\003"
    "wfe\003wfi\005yield";

namespace {
  struct MatchEntry {
    uint16_t Mnemonic;
    uint16_t Opcode;
    uint16_t ConvertFn;
    uint32_t RequiredFeatures;
    uint16_t Classes[18];
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
  { 0 /* adc */, ARM::tADC, Convert__Reg1_2__CCOut1_0__Tie0__Reg1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 0 /* adc */, ARM::ADCrsr, Convert__Reg1_2__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_RegShiftedReg }, },
  { 0 /* adc */, ARM::ADCrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 0 /* adc */, ARM::ADCri, Convert__Reg1_2__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 0 /* adc */, ARM::ADCrsi, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 0 /* adc */, ARM::t2ADCrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 0 /* adc */, ARM::t2ADCrs, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 0 /* adc */, ARM::t2ADCri, Convert__Reg1_2__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_T2SOImm }, },
  { 0 /* adc */, ARM::ADCrsr, Convert__Reg1_2__Reg1_3__RegShiftedReg3_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_RegShiftedReg }, },
  { 0 /* adc */, ARM::ADCrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 0 /* adc */, ARM::ADCri, Convert__Reg1_2__Reg1_3__ARMSOImm1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_ARMSOImm }, },
  { 0 /* adc */, ARM::ADCrsi, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedImm }, },
  { 0 /* adc */, ARM::t2ADCrr, Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 0 /* adc */, ARM::t2ADCrs, Convert__Reg1_3__Reg1_4__RegShiftedImm2_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 4 /* add */, ARM::tADDspr, Convert__Reg1_1__Tie0__Reg1_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_GPRsp, MCK_GPR }, },
  { 4 /* add */, ARM::tADDspi, Convert__Reg1_1__Tie0__Imm0_508s41_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_GPRsp, MCK_Imm0_508s4 }, },
  { 4 /* add */, ARM::tSUBspi, Convert__regSP__Tie0__Imm0_508s4Neg1_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_GPRsp, MCK_Imm0_508s4Neg }, },
  { 4 /* add */, ARM::t2ADDri12, Convert__Reg1_1__Reg1_1__Imm0_40951_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_Imm0_4095 }, },
  { 4 /* add */, ARM::t2SUBri12, Convert__Reg1_1__Reg1_1__Imm0_4095Neg1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_Imm0_4095Neg }, },
  { 4 /* add */, ARM::tADDhirr, Convert__Reg1_1__Tie0__Reg1_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 4 /* add */, ARM::tADDi8, Convert__Reg1_2__CCOut1_0__Tie0__Imm0_2551_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_Imm0_255 }, },
  { 4 /* add */, ARM::t2ADDrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_rGPR }, },
  { 4 /* add */, ARM::t2ADDrs, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 4 /* add */, ARM::t2ADDri, Convert__Reg1_2__Reg1_2__T2SOImm1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_T2SOImm }, },
  { 4 /* add */, ARM::t2SUBri, Convert__Reg1_2__Reg1_2__T2SOImmNeg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_T2SOImmNeg }, },
  { 4 /* add */, ARM::t2SUBri, Convert__Reg1_2__Reg1_2__T2SOImmNeg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_T2SOImmNeg }, },
  { 4 /* add */, ARM::ADDrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 4 /* add */, ARM::ADDri, Convert__Reg1_2__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 4 /* add */, ARM::ADDrsi, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 4 /* add */, ARM::ADDrsr, Convert__Reg1_2__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedReg }, },
  { 4 /* add */, ARM::SUBri, Convert__Reg1_2__Reg1_2__ARMSOImmNeg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_ARMSOImmNeg }, },
  { 4 /* add */, ARM::tADDrSPi, Convert__Reg1_1__Reg1_2__Imm0_1020s41_3__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_GPRsp, MCK_Imm0_1020s4 }, },
  { 4 /* add */, ARM::t2ADR, Convert__Reg1_1__Imm0_40951_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_PC, MCK_Imm0_4095 }, },
  { 4 /* add */, ARM::tADDspi, Convert__regSP__Tie0__Imm0_508s41_3__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_GPRsp, MCK_GPRsp, MCK_Imm0_508s4 }, },
  { 4 /* add */, ARM::tSUBspi, Convert__regSP__Tie0__Imm0_508s4Neg1_3__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_GPRsp, MCK_GPRsp, MCK_Imm0_508s4Neg }, },
  { 4 /* add */, ARM::t2ADDri12, Convert__Reg1_1__Reg1_2__Imm0_40951_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_Imm0_4095 }, },
  { 4 /* add */, ARM::t2SUBri12, Convert__Reg1_1__Reg1_2__Imm0_4095Neg1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_Imm0_4095Neg }, },
  { 4 /* add */, ARM::tADDrSP, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_GPR, MCK_GPRsp, MCK_GPR }, },
  { 4 /* add */, ARM::t2SUBri, Convert__Reg1_3__Reg1_3__T2SOImmNeg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_T2SOImmNeg }, },
  { 4 /* add */, ARM::tADDrr, Convert__Reg1_2__CCOut1_0__Reg1_3__Reg1_4__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR, MCK_tGPR }, },
  { 4 /* add */, ARM::tADDi3, Convert__Reg1_2__CCOut1_0__Reg1_3__Imm0_71_4__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR, MCK_Imm0_7 }, },
  { 4 /* add */, ARM::t2ADDrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_rGPR }, },
  { 4 /* add */, ARM::t2ADDrs, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 4 /* add */, ARM::t2ADDri, Convert__Reg1_2__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_T2SOImm }, },
  { 4 /* add */, ARM::t2SUBri, Convert__Reg1_2__Reg1_3__T2SOImmNeg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_T2SOImmNeg }, },
  { 4 /* add */, ARM::t2SUBri, Convert__Reg1_2__Reg1_3__T2SOImmNeg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_T2SOImmNeg }, },
  { 4 /* add */, ARM::ADDrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 4 /* add */, ARM::ADDri, Convert__Reg1_2__Reg1_3__ARMSOImm1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_ARMSOImm }, },
  { 4 /* add */, ARM::ADDrsi, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedImm }, },
  { 4 /* add */, ARM::ADDrsr, Convert__Reg1_2__Reg1_3__RegShiftedReg3_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedReg }, },
  { 4 /* add */, ARM::SUBri, Convert__Reg1_2__Reg1_3__ARMSOImmNeg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_ARMSOImmNeg }, },
  { 4 /* add */, ARM::t2ADDrr, Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_GPRnopc, MCK_rGPR }, },
  { 4 /* add */, ARM::t2ADDrs, Convert__Reg1_3__Reg1_4__RegShiftedImm2_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 4 /* add */, ARM::t2ADDri, Convert__Reg1_3__Reg1_4__T2SOImm1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_GPRnopc, MCK_T2SOImm }, },
  { 4 /* add */, ARM::t2SUBri, Convert__Reg1_3__Reg1_4__T2SOImmNeg1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_GPRnopc, MCK_T2SOImmNeg }, },
  { 8 /* addw */, ARM::t2SUBri12, Convert__Reg1_1__Reg1_1__Imm0_4095Neg1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_Imm0_4095Neg }, },
  { 8 /* addw */, ARM::t2ADDri12, Convert__Reg1_1__Reg1_2__Imm0_40951_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_Imm0_4095 }, },
  { 8 /* addw */, ARM::t2SUBri12, Convert__Reg1_1__Reg1_2__Imm0_4095Neg1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_Imm0_4095Neg }, },
  { 13 /* adr */, ARM::tADR, Convert__Reg1_1__UnsignedOffset_b8s21_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_UnsignedOffset_b8s2 }, },
  { 13 /* adr */, ARM::t2ADR, Convert__Reg1_1__Imm1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Imm }, },
  { 13 /* adr */, ARM::ADR, Convert__Reg1_1__AdrLabel1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_AdrLabel }, },
  { 13 /* adr */, ARM::t2ADR, Convert__Reg1_2__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_Imm }, },
  { 17 /* aesd */, ARM::AESD, Convert__Reg1_1__Tie0__Reg1_2, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 22 /* aese */, ARM::AESE, Convert__Reg1_1__Tie0__Reg1_2, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 27 /* aesimc */, ARM::AESIMC, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 34 /* aesmc */, ARM::AESMC, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 40 /* and */, ARM::tAND, Convert__Reg1_2__CCOut1_0__Tie0__Reg1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 40 /* and */, ARM::t2ANDrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 40 /* and */, ARM::t2ANDrs, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_RegShiftedImm }, },
  { 40 /* and */, ARM::BICri, Convert__Reg1_2__Reg1_2__ARMSOImmNot1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_ARMSOImmNot }, },
  { 40 /* and */, ARM::t2ANDri, Convert__Reg1_2__Reg1_2__T2SOImm1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_T2SOImm }, },
  { 40 /* and */, ARM::t2BICri, Convert__Reg1_2__Reg1_2__T2SOImmNot1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_T2SOImmNot }, },
  { 40 /* and */, ARM::ANDrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 40 /* and */, ARM::ANDri, Convert__Reg1_2__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 40 /* and */, ARM::ANDrsi, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 40 /* and */, ARM::ANDrsr, Convert__Reg1_2__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedReg }, },
  { 40 /* and */, ARM::t2ANDrr, Convert__Reg1_3__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 40 /* and */, ARM::t2ANDrs, Convert__Reg1_3__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_RegShiftedImm }, },
  { 40 /* and */, ARM::t2ANDri, Convert__Reg1_3__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_T2SOImm }, },
  { 40 /* and */, ARM::t2ANDrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 40 /* and */, ARM::t2ANDrs, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 40 /* and */, ARM::BICri, Convert__Reg1_2__Reg1_3__ARMSOImmNot1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_ARMSOImmNot }, },
  { 40 /* and */, ARM::t2ANDri, Convert__Reg1_2__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_T2SOImm }, },
  { 40 /* and */, ARM::t2BICri, Convert__Reg1_2__Reg1_3__T2SOImmNot1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_T2SOImmNot }, },
  { 40 /* and */, ARM::ANDrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 40 /* and */, ARM::ANDri, Convert__Reg1_2__Reg1_3__ARMSOImm1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_ARMSOImm }, },
  { 40 /* and */, ARM::ANDrsi, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedImm }, },
  { 40 /* and */, ARM::ANDrsr, Convert__Reg1_2__Reg1_3__RegShiftedReg3_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedReg }, },
  { 40 /* and */, ARM::t2ANDrr, Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 40 /* and */, ARM::t2ANDrs, Convert__Reg1_3__Reg1_4__RegShiftedImm2_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 40 /* and */, ARM::t2ANDri, Convert__Reg1_3__Reg1_4__T2SOImm1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_T2SOImm }, },
  { 44 /* asr */, ARM::tASRrr, Convert__Reg1_2__CCOut1_0__Tie0__Reg1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 44 /* asr */, ARM::tASRri, Convert__Reg1_2__CCOut1_0__Reg1_2__ImmThumbSR1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_ImmThumbSR }, },
  { 44 /* asr */, ARM::t2ASRrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 44 /* asr */, ARM::t2ASRri, Convert__Reg1_2__Reg1_2__ImmThumbSR1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_ImmThumbSR }, },
  { 44 /* asr */, ARM::ASRr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc }, },
  { 44 /* asr */, ARM::ASRi, Convert__Reg1_2__Reg1_2__Imm0_321_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_Imm0_32 }, },
  { 44 /* asr */, ARM::t2ASRrr, Convert__Reg1_3__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 44 /* asr */, ARM::t2ASRri, Convert__Reg1_3__Reg1_3__ImmThumbSR1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_ImmThumbSR }, },
  { 44 /* asr */, ARM::tASRri, Convert__Reg1_2__CCOut1_0__Reg1_3__ImmThumbSR1_4__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR, MCK_ImmThumbSR }, },
  { 44 /* asr */, ARM::t2ASRrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 44 /* asr */, ARM::t2ASRri, Convert__Reg1_2__Reg1_3__ImmThumbSR1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_ImmThumbSR }, },
  { 44 /* asr */, ARM::ASRr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 44 /* asr */, ARM::ASRi, Convert__Reg1_2__Reg1_3__Imm0_321_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_Imm0_32 }, },
  { 44 /* asr */, ARM::t2ASRrr, Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 44 /* asr */, ARM::t2ASRri, Convert__Reg1_3__Reg1_4__ImmThumbSR1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_ImmThumbSR }, },
  { 48 /* b */, ARM::Bcc, Convert__Imm1_1__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_Imm }, },
  { 48 /* b */, ARM::tB, ConvertCustom_cvtThumbBranches, Feature_IsThumb, { MCK_CondCode, MCK_Imm }, },
  { 48 /* b */, ARM::tBcc, ConvertCustom_cvtThumbBranches, Feature_IsThumb, { MCK_CondCode, MCK_Imm }, },
  { 48 /* b */, ARM::t2B, ConvertCustom_cvtThumbBranches, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_Imm }, },
  { 48 /* b */, ARM::t2Bcc, ConvertCustom_cvtThumbBranches, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_Imm }, },
  { 50 /* bfc */, ARM::t2BFC, Convert__Reg1_1__Tie0__Bitfield1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Bitfield }, },
  { 50 /* bfc */, ARM::BFC, Convert__Reg1_1__Tie0__Bitfield1_2__CondCode2_0, Feature_IsARM|Feature_HasV6T2, { MCK_CondCode, MCK_GPR, MCK_Bitfield }, },
  { 54 /* bfi */, ARM::t2BFI, Convert__Reg1_1__Tie0__Reg1_2__Bitfield1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_Bitfield }, },
  { 54 /* bfi */, ARM::BFI, Convert__Reg1_1__Tie0__Reg1_2__Bitfield1_3__CondCode2_0, Feature_IsARM|Feature_HasV6T2, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_Bitfield }, },
  { 58 /* bic */, ARM::tBIC, Convert__Reg1_2__CCOut1_0__Tie0__Reg1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 58 /* bic */, ARM::t2BICrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 58 /* bic */, ARM::t2BICrs, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_RegShiftedImm }, },
  { 58 /* bic */, ARM::ANDri, Convert__Reg1_2__Reg1_2__ARMSOImmNot1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_ARMSOImmNot }, },
  { 58 /* bic */, ARM::t2BICri, Convert__Reg1_2__Reg1_2__T2SOImm1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_T2SOImm }, },
  { 58 /* bic */, ARM::t2ANDri, Convert__Reg1_2__Reg1_2__T2SOImmNot1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_T2SOImmNot }, },
  { 58 /* bic */, ARM::BICrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 58 /* bic */, ARM::BICri, Convert__Reg1_2__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 58 /* bic */, ARM::BICrsi, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 58 /* bic */, ARM::BICrsr, Convert__Reg1_2__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedReg }, },
  { 58 /* bic */, ARM::t2BICrr, Convert__Reg1_3__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 58 /* bic */, ARM::t2BICrs, Convert__Reg1_3__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_RegShiftedImm }, },
  { 58 /* bic */, ARM::t2BICri, Convert__Reg1_3__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_T2SOImm }, },
  { 58 /* bic */, ARM::t2BICrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 58 /* bic */, ARM::t2BICrs, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 58 /* bic */, ARM::ANDri, Convert__Reg1_2__Reg1_3__ARMSOImmNot1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_ARMSOImmNot }, },
  { 58 /* bic */, ARM::t2BICri, Convert__Reg1_2__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_T2SOImm }, },
  { 58 /* bic */, ARM::t2ANDri, Convert__Reg1_2__Reg1_3__T2SOImmNot1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_T2SOImmNot }, },
  { 58 /* bic */, ARM::BICrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 58 /* bic */, ARM::BICri, Convert__Reg1_2__Reg1_3__ARMSOImm1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_ARMSOImm }, },
  { 58 /* bic */, ARM::BICrsi, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedImm }, },
  { 58 /* bic */, ARM::BICrsr, Convert__Reg1_2__Reg1_3__RegShiftedReg3_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedReg }, },
  { 58 /* bic */, ARM::t2BICrr, Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 58 /* bic */, ARM::t2BICrs, Convert__Reg1_3__Reg1_4__RegShiftedImm2_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 58 /* bic */, ARM::t2BICri, Convert__Reg1_3__Reg1_4__T2SOImm1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_T2SOImm }, },
  { 62 /* bkpt */, ARM::tBKPT, Convert__Imm0_2551_0, Feature_IsThumb, { MCK_Imm0_255 }, },
  { 62 /* bkpt */, ARM::BKPT, Convert__Imm0_655351_0, Feature_IsARM, { MCK_Imm0_65535 }, },
  { 67 /* bl */, ARM::BL, Convert__Imm1_0, Feature_IsARM, { MCK_Imm }, },
  { 67 /* bl */, ARM::BL_pred, Convert__Imm1_1__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_Imm }, },
  { 67 /* bl */, ARM::tBL, Convert__CondCode2_0__Imm1_1, Feature_IsThumb, { MCK_CondCode, MCK_Imm }, },
  { 70 /* blx */, ARM::BLX, Convert__Reg1_0, Feature_IsARM, { MCK_GPR }, },
  { 70 /* blx */, ARM::BLXi, Convert__Imm1_0, Feature_IsARM, { MCK_Imm }, },
  { 70 /* blx */, ARM::BLX_pred, Convert__Reg1_1__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR }, },
  { 70 /* blx */, ARM::tBLXr, Convert__CondCode2_0__Reg1_1, Feature_IsThumb, { MCK_CondCode, MCK_GPR }, },
  { 70 /* blx */, ARM::tBLXi, Convert__CondCode2_0__Imm1_1, Feature_IsThumb, { MCK_CondCode, MCK_Imm }, },
  { 74 /* bx */, ARM::BX, Convert__Reg1_0, Feature_IsARM|Feature_HasV4T, { MCK_GPR }, },
  { 74 /* bx */, ARM::BX_RET, Convert__CondCode2_0, Feature_IsARM|Feature_HasV4T, { MCK_CondCode, MCK_LR }, },
  { 74 /* bx */, ARM::BX_pred, Convert__Reg1_1__CondCode2_0, Feature_IsARM|Feature_HasV4T, { MCK_CondCode, MCK_GPR }, },
  { 74 /* bx */, ARM::tBX, Convert__Reg1_1__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_GPR }, },
  { 77 /* bxj */, ARM::t2BXJ, Convert__Reg1_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR }, },
  { 77 /* bxj */, ARM::BXJ, Convert__Reg1_1__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR }, },
  { 81 /* cbnz */, ARM::tCBNZ, Convert__Reg1_0__Imm1_1, Feature_IsThumb2, { MCK_tGPR, MCK_Imm }, },
  { 86 /* cbz */, ARM::tCBZ, Convert__Reg1_0__Imm1_1, Feature_IsThumb2, { MCK_tGPR, MCK_Imm }, },
  { 90 /* cdp */, ARM::t2CDP, Convert__CoprocNum1_1__Imm0_151_2__CoprocReg1_3__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0, Feature_IsThumb2|Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_15, MCK_CoprocReg, MCK_CoprocReg, MCK_CoprocReg, MCK_Imm0_7 }, },
  { 90 /* cdp */, ARM::CDP, Convert__CoprocNum1_1__Imm0_151_2__CoprocReg1_3__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_15, MCK_CoprocReg, MCK_CoprocReg, MCK_CoprocReg, MCK_Imm0_7 }, },
  { 94 /* cdp2 */, ARM::CDP2, Convert__CoprocNum1_0__Imm0_151_1__CoprocReg1_2__CoprocReg1_3__CoprocReg1_4__Imm0_71_5, Feature_PreV8, { MCK_CoprocNum, MCK_Imm0_15, MCK_CoprocReg, MCK_CoprocReg, MCK_CoprocReg, MCK_Imm0_7 }, },
  { 94 /* cdp2 */, ARM::t2CDP2, Convert__CoprocNum1_1__Imm0_151_2__CoprocReg1_3__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0, Feature_IsThumb2|Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_15, MCK_CoprocReg, MCK_CoprocReg, MCK_CoprocReg, MCK_Imm0_7 }, },
  { 99 /* clrex */, ARM::CLREX, Convert_NoOperands, Feature_IsARM|Feature_HasV7, {  }, },
  { 99 /* clrex */, ARM::t2CLREX, Convert__CondCode2_0, Feature_IsThumb2|Feature_HasV7, { MCK_CondCode }, },
  { 105 /* clz */, ARM::t2CLZ, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 105 /* clz */, ARM::CLZ, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 109 /* cmn */, ARM::tCMNz, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 109 /* cmn */, ARM::CMPri, Convert__Reg1_1__ARMSOImmNeg1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_rGPR, MCK_ARMSOImmNeg }, },
  { 109 /* cmn */, ARM::t2CMPri, Convert__Reg1_1__T2SOImmNeg1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_T2SOImmNeg }, },
  { 109 /* cmn */, ARM::t2CMNzrr, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_rGPR }, },
  { 109 /* cmn */, ARM::t2CMNzrs, Convert__Reg1_1__RegShiftedImm2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 109 /* cmn */, ARM::CMNzrsr, Convert__Reg1_1__RegShiftedReg3_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_RegShiftedReg }, },
  { 109 /* cmn */, ARM::t2CMNri, Convert__Reg1_1__T2SOImm1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_T2SOImm }, },
  { 109 /* cmn */, ARM::CMNzrr, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 109 /* cmn */, ARM::CMNri, Convert__Reg1_1__ARMSOImm1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 109 /* cmn */, ARM::CMNzrsi, Convert__Reg1_1__RegShiftedImm2_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 109 /* cmn */, ARM::t2CMNzrr, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_rGPR }, },
  { 109 /* cmn */, ARM::t2CMNzrs, Convert__Reg1_2__RegShiftedImm2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 109 /* cmn */, ARM::t2CMNri, Convert__Reg1_2__T2SOImm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_T2SOImm }, },
  { 113 /* cmp */, ARM::tCMPr, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 113 /* cmp */, ARM::tCMPi8, Convert__Reg1_1__Imm0_2551_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_Imm0_255 }, },
  { 113 /* cmp */, ARM::CMNri, Convert__Reg1_1__ARMSOImmNeg1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_rGPR, MCK_ARMSOImmNeg }, },
  { 113 /* cmp */, ARM::t2CMNri, Convert__Reg1_1__T2SOImmNeg1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_T2SOImmNeg }, },
  { 113 /* cmp */, ARM::t2CMPrs, Convert__Reg1_1__RegShiftedImm2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 113 /* cmp */, ARM::CMPrsr, Convert__Reg1_1__RegShiftedReg3_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_RegShiftedReg }, },
  { 113 /* cmp */, ARM::t2CMPri, Convert__Reg1_1__T2SOImm1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_T2SOImm }, },
  { 113 /* cmp */, ARM::CMPrr, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 113 /* cmp */, ARM::tCMPhir, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 113 /* cmp */, ARM::CMPri, Convert__Reg1_1__ARMSOImm1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 113 /* cmp */, ARM::CMPrsi, Convert__Reg1_1__RegShiftedImm2_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 113 /* cmp */, ARM::t2CMPrr, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_rGPR }, },
  { 113 /* cmp */, ARM::t2CMPrs, Convert__Reg1_2__RegShiftedImm2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 113 /* cmp */, ARM::t2CMPri, Convert__Reg1_2__T2SOImm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_T2SOImm }, },
  { 117 /* cps */, ARM::CPS1p, Convert__Imm0_311_0, Feature_IsARM, { MCK_Imm0_31 }, },
  { 117 /* cps */, ARM::t2CPS1p, Convert__Imm0_311_0, Feature_IsThumb2, { MCK_Imm0_31 }, },
  { 117 /* cps */, ARM::tCPS, Convert__Imm1_0__imm_0, Feature_IsThumb, { MCK_Imm }, },
  { 117 /* cps */, ARM::tCPS, Convert__Imm1_0__imm_0, Feature_IsThumb, { MCK_Imm }, },
  { 117 /* cps */, ARM::t2CPS1p, Convert__Imm0_311_1, Feature_IsThumb2, { MCK__DOT_w, MCK_Imm0_31 }, },
  { 117 /* cps */, ARM::CPS2p, Convert__Imm1_0__ProcIFlags1_1, Feature_IsARM, { MCK_Imm, MCK_ProcIFlags }, },
  { 117 /* cps */, ARM::tCPS, Convert__Imm1_0__ProcIFlags1_1, Feature_IsThumb, { MCK_Imm, MCK_ProcIFlags }, },
  { 117 /* cps */, ARM::t2CPS2p, Convert__Imm1_0__ProcIFlags1_2, Feature_IsThumb2, { MCK_Imm, MCK__DOT_w, MCK_ProcIFlags }, },
  { 117 /* cps */, ARM::CPS3p, Convert__Imm1_0__ProcIFlags1_1__Imm0_311_2, Feature_IsARM, { MCK_Imm, MCK_ProcIFlags, MCK_Imm0_31 }, },
  { 117 /* cps */, ARM::t2CPS3p, Convert__Imm1_0__ProcIFlags1_1__Imm1_2, Feature_IsThumb2, { MCK_Imm, MCK_ProcIFlags, MCK_Imm }, },
  { 117 /* cps */, ARM::t2CPS3p, Convert__Imm1_0__ProcIFlags1_2__Imm1_3, Feature_IsThumb2, { MCK_Imm, MCK__DOT_w, MCK_ProcIFlags, MCK_Imm }, },
  { 121 /* crc32b */, ARM::t2CRC32B, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_IsThumb2|Feature_HasV8|Feature_HasCRC, { MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 121 /* crc32b */, ARM::CRC32B, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_IsARM|Feature_HasV8|Feature_HasCRC, { MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 128 /* crc32cb */, ARM::t2CRC32CB, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_IsThumb2|Feature_HasV8|Feature_HasCRC, { MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 128 /* crc32cb */, ARM::CRC32CB, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_IsARM|Feature_HasV8|Feature_HasCRC, { MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 136 /* crc32ch */, ARM::t2CRC32CH, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_IsThumb2|Feature_HasV8|Feature_HasCRC, { MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 136 /* crc32ch */, ARM::CRC32CH, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_IsARM|Feature_HasV8|Feature_HasCRC, { MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 144 /* crc32cw */, ARM::t2CRC32CW, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_IsThumb2|Feature_HasV8|Feature_HasCRC, { MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 144 /* crc32cw */, ARM::CRC32CW, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_IsARM|Feature_HasV8|Feature_HasCRC, { MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 152 /* crc32h */, ARM::t2CRC32H, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_IsThumb2|Feature_HasV8|Feature_HasCRC, { MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 152 /* crc32h */, ARM::CRC32H, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_IsARM|Feature_HasV8|Feature_HasCRC, { MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 159 /* crc32w */, ARM::t2CRC32W, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_IsThumb2|Feature_HasV8|Feature_HasCRC, { MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 159 /* crc32w */, ARM::CRC32W, Convert__Reg1_0__Reg1_1__Reg1_2, Feature_IsARM|Feature_HasV8|Feature_HasCRC, { MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 166 /* dbg */, ARM::DBG, Convert__Imm0_151_1__CondCode2_0, Feature_IsARM|Feature_HasV7, { MCK_CondCode, MCK_Imm0_15 }, },
  { 166 /* dbg */, ARM::t2DBG, Convert__Imm0_151_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_Imm0_15 }, },
  { 170 /* dcps1 */, ARM::t2DCPS1, Convert__CondCode2_0, Feature_IsThumb2|Feature_HasV8, { MCK_CondCode }, },
  { 176 /* dcps2 */, ARM::t2DCPS2, Convert__CondCode2_0, Feature_IsThumb2|Feature_HasV8, { MCK_CondCode }, },
  { 182 /* dcps3 */, ARM::t2DCPS3, Convert__CondCode2_0, Feature_IsThumb2|Feature_HasV8, { MCK_CondCode }, },
  { 188 /* dmb */, ARM::DMB, Convert__imm_15, Feature_IsARM|Feature_HasDB, {  }, },
  { 188 /* dmb */, ARM::t2DMB, Convert__imm_15__CondCode2_0, Feature_HasDB, { MCK_CondCode }, },
  { 188 /* dmb */, ARM::DMB, Convert__MemBarrierOpt1_0, Feature_IsARM|Feature_HasDB, { MCK_MemBarrierOpt }, },
  { 188 /* dmb */, ARM::t2DMB, Convert__MemBarrierOpt1_1__CondCode2_0, Feature_HasDB, { MCK_CondCode, MCK_MemBarrierOpt }, },
  { 192 /* dsb */, ARM::DSB, Convert__imm_15, Feature_IsARM|Feature_HasDB, {  }, },
  { 192 /* dsb */, ARM::t2DSB, Convert__imm_15__CondCode2_0, Feature_HasDB, { MCK_CondCode }, },
  { 192 /* dsb */, ARM::DSB, Convert__MemBarrierOpt1_0, Feature_IsARM|Feature_HasDB, { MCK_MemBarrierOpt }, },
  { 192 /* dsb */, ARM::t2DSB, Convert__MemBarrierOpt1_1__CondCode2_0, Feature_HasDB, { MCK_CondCode, MCK_MemBarrierOpt }, },
  { 196 /* eor */, ARM::tEOR, Convert__Reg1_2__CCOut1_0__Tie0__Reg1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 196 /* eor */, ARM::t2EORrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 196 /* eor */, ARM::t2EORrs, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_RegShiftedImm }, },
  { 196 /* eor */, ARM::t2EORri, Convert__Reg1_2__Reg1_2__T2SOImm1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_T2SOImm }, },
  { 196 /* eor */, ARM::EORrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 196 /* eor */, ARM::EORri, Convert__Reg1_2__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 196 /* eor */, ARM::EORrsi, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 196 /* eor */, ARM::EORrsr, Convert__Reg1_2__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedReg }, },
  { 196 /* eor */, ARM::t2EORrr, Convert__Reg1_3__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 196 /* eor */, ARM::t2EORrs, Convert__Reg1_3__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_RegShiftedImm }, },
  { 196 /* eor */, ARM::t2EORri, Convert__Reg1_3__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_T2SOImm }, },
  { 196 /* eor */, ARM::t2EORrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 196 /* eor */, ARM::t2EORrs, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 196 /* eor */, ARM::t2EORri, Convert__Reg1_2__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_T2SOImm }, },
  { 196 /* eor */, ARM::EORrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 196 /* eor */, ARM::EORri, Convert__Reg1_2__Reg1_3__ARMSOImm1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_ARMSOImm }, },
  { 196 /* eor */, ARM::EORrsi, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedImm }, },
  { 196 /* eor */, ARM::EORrsr, Convert__Reg1_2__Reg1_3__RegShiftedReg3_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedReg }, },
  { 196 /* eor */, ARM::t2EORrr, Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 196 /* eor */, ARM::t2EORrs, Convert__Reg1_3__Reg1_4__RegShiftedImm2_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 196 /* eor */, ARM::t2EORri, Convert__Reg1_3__Reg1_4__T2SOImm1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_T2SOImm }, },
  { 200 /* faddd */, ARM::VADDD, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 206 /* fadds */, ARM::VADDS, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 212 /* fcmpzd */, ARM::VCMPZD, Convert__Reg1_1__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK_DPR }, },
  { 219 /* fcmpzs */, ARM::VCMPZS, Convert__Reg1_1__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_SPR }, },
  { 226 /* fldmdbx */, ARM::FLDMXDB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__DPRRegList1_3, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_DPRRegList }, },
  { 234 /* fldmiax */, ARM::FLDMXIA, Convert__Reg1_1__CondCode2_0__DPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_DPRRegList }, },
  { 234 /* fldmiax */, ARM::FLDMXIA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__DPRRegList1_3, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_DPRRegList }, },
  { 242 /* fmdhr */, ARM::VSETLNi32, Convert__Reg1_1__Tie0__Reg1_2__imm_1__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_DPR, MCK_GPR }, },
  { 248 /* fmdlr */, ARM::VSETLNi32, Convert__Reg1_1__Tie0__Reg1_2__imm_0__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_DPR, MCK_GPR }, },
  { 254 /* fmstat */, ARM::FMSTAT, Convert__CondCode2_0, Feature_HasVFP2, { MCK_CondCode }, },
  { 261 /* fstmdbx */, ARM::FSTMXDB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__DPRRegList1_3, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_DPRRegList }, },
  { 269 /* fstmiax */, ARM::FSTMXIA, Convert__Reg1_1__CondCode2_0__DPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_DPRRegList }, },
  { 269 /* fstmiax */, ARM::FSTMXIA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__DPRRegList1_3, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_DPRRegList }, },
  { 277 /* fsubd */, ARM::VSUBD, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 283 /* fsubs */, ARM::VSUBS, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 289 /* hint */, ARM::tHINT, Convert__Imm0_151_1__CondCode2_0, Feature_IsThumb|Feature_HasV6M, { MCK_CondCode, MCK_Imm0_15 }, },
  { 289 /* hint */, ARM::HINT, Convert__Imm0_2391_1__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_Imm0_239 }, },
  { 289 /* hint */, ARM::t2HINT, Convert__Imm0_2391_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_Imm0_239 }, },
  { 289 /* hint */, ARM::t2HINT, Convert__Imm0_2391_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_Imm0_239 }, },
  { 294 /* hlt */, ARM::tHLT, Convert__Imm0_631_0, Feature_IsThumb|Feature_HasV8, { MCK_Imm0_63 }, },
  { 294 /* hlt */, ARM::HLT, Convert__Imm0_655351_0, Feature_IsARM|Feature_HasV8, { MCK_Imm0_65535 }, },
  { 298 /* isb */, ARM::ISB, Convert__imm_15, Feature_IsARM|Feature_HasDB, {  }, },
  { 298 /* isb */, ARM::t2ISB, Convert__imm_15__CondCode2_0, Feature_HasDB, { MCK_CondCode }, },
  { 298 /* isb */, ARM::ISB, Convert__InstSyncBarrierOpt1_0, Feature_IsARM|Feature_HasDB, { MCK_InstSyncBarrierOpt }, },
  { 298 /* isb */, ARM::t2ISB, Convert__InstSyncBarrierOpt1_1__CondCode2_0, Feature_HasDB, { MCK_CondCode, MCK_InstSyncBarrierOpt }, },
  { 302 /* it */, ARM::ITasm, Convert__ITCondCode1_1__ITMask1_0, Feature_IsARM, { MCK_ITMask, MCK_ITCondCode }, },
  { 302 /* it */, ARM::t2IT, Convert__ITCondCode1_1__ITMask1_0, Feature_IsThumb2, { MCK_ITMask, MCK_ITCondCode }, },
  { 305 /* lda */, ARM::t2LDA, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_MemNoOffset }, },
  { 305 /* lda */, ARM::LDA, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset }, },
  { 309 /* ldab */, ARM::t2LDAB, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_MemNoOffset }, },
  { 309 /* ldab */, ARM::LDAB, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset }, },
  { 314 /* ldaex */, ARM::t2LDAEX, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_MemNoOffset }, },
  { 314 /* ldaex */, ARM::LDAEX, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset }, },
  { 320 /* ldaexb */, ARM::t2LDAEXB, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_MemNoOffset }, },
  { 320 /* ldaexb */, ARM::LDAEXB, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset }, },
  { 327 /* ldaexd */, ARM::LDAEXD, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPRPair, MCK_MemNoOffset }, },
  { 327 /* ldaexd */, ARM::t2LDAEXD, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_MemNoOffset }, },
  { 334 /* ldaexh */, ARM::t2LDAEXH, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_MemNoOffset }, },
  { 334 /* ldaexh */, ARM::LDAEXH, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset }, },
  { 341 /* ldah */, ARM::t2LDAH, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_MemNoOffset }, },
  { 341 /* ldah */, ARM::LDAH, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset }, },
  { 346 /* ldc */, ARM::LDC_OFFSET, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 346 /* ldc */, ARM::t2LDC_OFFSET, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 346 /* ldc */, ARM::LDC_PRE, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 346 /* ldc */, ARM::t2LDC_PRE, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 346 /* ldc */, ARM::LDC_OPTION, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 346 /* ldc */, ARM::t2LDC_OPTION, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 346 /* ldc */, ARM::LDC_POST, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 346 /* ldc */, ARM::t2LDC_POST, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 350 /* ldc2 */, ARM::LDC2_OFFSET, Convert__CoprocNum1_0__CoprocReg1_1__AddrMode52_2, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 350 /* ldc2 */, ARM::t2LDC2_OFFSET, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 350 /* ldc2 */, ARM::LDC2_PRE, Convert__CoprocNum1_0__CoprocReg1_1__AddrMode52_2, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 350 /* ldc2 */, ARM::LDC2_OPTION, Convert__CoprocNum1_0__CoprocReg1_1__MemNoOffset1_2__CoprocOption1_3, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 350 /* ldc2 */, ARM::LDC2_POST, Convert__CoprocNum1_0__CoprocReg1_1__MemNoOffset1_2__PostIdxImm8s41_3, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 350 /* ldc2 */, ARM::t2LDC2_PRE, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 350 /* ldc2 */, ARM::t2LDC2_OPTION, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 350 /* ldc2 */, ARM::t2LDC2_POST, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 355 /* ldc2l */, ARM::LDC2L_OFFSET, Convert__CoprocNum1_0__CoprocReg1_1__AddrMode52_2, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 355 /* ldc2l */, ARM::t2LDC2L_OFFSET, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 355 /* ldc2l */, ARM::LDC2L_PRE, Convert__CoprocNum1_0__CoprocReg1_1__AddrMode52_2, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 355 /* ldc2l */, ARM::LDC2L_OPTION, Convert__CoprocNum1_0__CoprocReg1_1__MemNoOffset1_2__CoprocOption1_3, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 355 /* ldc2l */, ARM::LDC2L_POST, Convert__CoprocNum1_0__CoprocReg1_1__MemNoOffset1_2__PostIdxImm8s41_3, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 355 /* ldc2l */, ARM::t2LDC2L_PRE, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 355 /* ldc2l */, ARM::t2LDC2L_OPTION, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 355 /* ldc2l */, ARM::t2LDC2L_POST, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 361 /* ldcl */, ARM::LDCL_OFFSET, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 361 /* ldcl */, ARM::t2LDCL_OFFSET, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 361 /* ldcl */, ARM::LDCL_PRE, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 361 /* ldcl */, ARM::t2LDCL_PRE, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 361 /* ldcl */, ARM::LDCL_OPTION, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 361 /* ldcl */, ARM::t2LDCL_OPTION, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 361 /* ldcl */, ARM::LDCL_POST, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 361 /* ldcl */, ARM::t2LDCL_POST, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 366 /* ldm */, ARM::tLDMIA, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_RegList }, },
  { 366 /* ldm */, ARM::LDMIA, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList }, },
  { 366 /* ldm */, ARM::t2LDMIA, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_RegList }, },
  { 366 /* ldm */, ARM::t2LDMIA, Convert__Reg1_2__CondCode2_0__RegList1_3, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_RegList }, },
  { 366 /* ldm */, ARM::tLDMIA, Convert__Reg1_1__CondCode2_0__RegList1_3, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 366 /* ldm */, ARM::LDMIA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 366 /* ldm */, ARM::t2LDMIA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 366 /* ldm */, ARM::sysLDMIA, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList, MCK__94_ }, },
  { 366 /* ldm */, ARM::t2LDMIA_UPD, Convert__Reg1_2__Tie0__CondCode2_0__RegList1_4, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 366 /* ldm */, ARM::sysLDMIA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList, MCK__94_ }, },
  { 370 /* ldmda */, ARM::LDMDA, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList }, },
  { 370 /* ldmda */, ARM::LDMDA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 370 /* ldmda */, ARM::sysLDMDA, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList, MCK__94_ }, },
  { 370 /* ldmda */, ARM::sysLDMDA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList, MCK__94_ }, },
  { 376 /* ldmdb */, ARM::LDMDB, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList }, },
  { 376 /* ldmdb */, ARM::t2LDMDB, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_RegList }, },
  { 376 /* ldmdb */, ARM::t2LDMDB, Convert__Reg1_2__CondCode2_0__RegList1_3, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_RegList }, },
  { 376 /* ldmdb */, ARM::LDMDB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 376 /* ldmdb */, ARM::t2LDMDB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 376 /* ldmdb */, ARM::sysLDMDB, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList, MCK__94_ }, },
  { 376 /* ldmdb */, ARM::t2LDMDB_UPD, Convert__Reg1_2__Tie0__CondCode2_0__RegList1_4, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 376 /* ldmdb */, ARM::sysLDMDB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList, MCK__94_ }, },
  { 382 /* ldmib */, ARM::LDMIB, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList }, },
  { 382 /* ldmib */, ARM::LDMIB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 382 /* ldmib */, ARM::sysLDMIB, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList, MCK__94_ }, },
  { 382 /* ldmib */, ARM::sysLDMIB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList, MCK__94_ }, },
  { 388 /* ldr */, ARM::tLDRpci, Convert__Reg1_1__ThumbMemPC1_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_ThumbMemPC }, },
  { 388 /* ldr */, ARM::tLDRi, Convert__Reg1_1__MemThumbRIs42_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRIs4 }, },
  { 388 /* ldr */, ARM::tLDRr, Convert__Reg1_1__MemThumbRR2_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRR }, },
  { 388 /* ldr */, ARM::tLDRspi, Convert__Reg1_1__MemThumbSPI2_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbSPI }, },
  { 388 /* ldr */, ARM::t2LDRpci, Convert__Reg1_1__Imm1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Imm }, },
  { 388 /* ldr */, ARM::LDRi12, Convert__Reg1_1__MemImm12Offset2_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemImm12Offset }, },
  { 388 /* ldr */, ARM::t2LDRi8, Convert__Reg1_1__MemNegImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemNegImm8Offset }, },
  { 388 /* ldr */, ARM::LDRrs, Convert__Reg1_1__MemRegOffset3_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemRegOffset }, },
  { 388 /* ldr */, ARM::t2LDRi12, Convert__Reg1_1__MemUImm12Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemUImm12Offset }, },
  { 388 /* ldr */, ARM::t2LDRs, Convert__Reg1_1__T2MemRegOffset3_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_T2MemRegOffset }, },
  { 388 /* ldr */, ARM::t2LDRpcrel, Convert__Reg1_1__MemPCRelImm121_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemPCRelImm12 }, },
  { 388 /* ldr */, ARM::t2LDRpci, Convert__Reg1_2__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_Imm }, },
  { 388 /* ldr */, ARM::t2LDRi12, Convert__Reg1_2__MemUImm12Offset2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_MemUImm12Offset }, },
  { 388 /* ldr */, ARM::t2LDRs, Convert__Reg1_2__T2MemRegOffset3_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_T2MemRegOffset }, },
  { 388 /* ldr */, ARM::t2LDRpcrel, Convert__Reg1_2__MemPCRelImm121_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_MemPCRelImm12 }, },
  { 388 /* ldr */, ARM::LDR_PRE_IMM, Convert__Reg1_1__imm_0__MemImm12Offset2_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemImm12Offset, MCK__EXCLAIM_ }, },
  { 388 /* ldr */, ARM::t2LDR_PRE, Convert__Reg1_1__imm_0__MemImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemImm8Offset, MCK__EXCLAIM_ }, },
  { 388 /* ldr */, ARM::LDR_POST_IMM, Convert__Reg1_1__MemNoOffset1_2__Tie1__AM2OffsetImm2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_AM2OffsetImm }, },
  { 388 /* ldr */, ARM::t2LDR_POST, Convert__Reg1_1__MemNoOffset1_2__Tie1__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_Imm }, },
  { 388 /* ldr */, ARM::LDR_POST_REG, Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxRegShifted2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_PostIdxRegShifted }, },
  { 388 /* ldr */, ARM::LDR_PRE_REG, Convert__Reg1_1__imm_0__MemRegOffset3_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemRegOffset, MCK__EXCLAIM_ }, },
  { 392 /* ldrb */, ARM::tLDRBi, Convert__Reg1_1__MemThumbRIs12_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRIs1 }, },
  { 392 /* ldrb */, ARM::tLDRBr, Convert__Reg1_1__MemThumbRR2_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRR }, },
  { 392 /* ldrb */, ARM::t2LDRBpci, Convert__Reg1_1__Imm1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Imm }, },
  { 392 /* ldrb */, ARM::t2LDRBi12, Convert__Reg1_1__MemUImm12Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemUImm12Offset }, },
  { 392 /* ldrb */, ARM::t2LDRBs, Convert__Reg1_1__T2MemRegOffset3_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_T2MemRegOffset }, },
  { 392 /* ldrb */, ARM::LDRBi12, Convert__Reg1_1__MemImm12Offset2_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_MemImm12Offset }, },
  { 392 /* ldrb */, ARM::LDRBrs, Convert__Reg1_1__MemRegOffset3_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_MemRegOffset }, },
  { 392 /* ldrb */, ARM::t2LDRBpcrel, Convert__Reg1_1__MemPCRelImm121_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_MemPCRelImm12 }, },
  { 392 /* ldrb */, ARM::t2LDRBi8, Convert__Reg1_1__MemNegImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemNegImm8Offset }, },
  { 392 /* ldrb */, ARM::t2LDRBpcrel, Convert__Reg1_2__MemPCRelImm121_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_MemPCRelImm12 }, },
  { 392 /* ldrb */, ARM::t2LDRBpci, Convert__Reg1_2__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_Imm }, },
  { 392 /* ldrb */, ARM::t2LDRBi12, Convert__Reg1_2__MemUImm12Offset2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_MemUImm12Offset }, },
  { 392 /* ldrb */, ARM::t2LDRBs, Convert__Reg1_2__T2MemRegOffset3_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_T2MemRegOffset }, },
  { 392 /* ldrb */, ARM::LDRB_PRE_IMM, Convert__Reg1_1__imm_0__MemImm12Offset2_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemImm12Offset, MCK__EXCLAIM_ }, },
  { 392 /* ldrb */, ARM::t2LDRB_PRE, Convert__Reg1_1__imm_0__MemImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemImm8Offset, MCK__EXCLAIM_ }, },
  { 392 /* ldrb */, ARM::LDRB_POST_IMM, Convert__Reg1_1__MemNoOffset1_2__Tie1__AM2OffsetImm2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_AM2OffsetImm }, },
  { 392 /* ldrb */, ARM::t2LDRB_POST, Convert__Reg1_1__MemNoOffset1_2__Tie1__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_Imm }, },
  { 392 /* ldrb */, ARM::LDRB_POST_REG, Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxRegShifted2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_PostIdxRegShifted }, },
  { 392 /* ldrb */, ARM::LDRB_PRE_REG, Convert__Reg1_1__imm_0__MemRegOffset3_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemRegOffset, MCK__EXCLAIM_ }, },
  { 397 /* ldrbt */, ARM::t2LDRBT, Convert__Reg1_1__MemPosImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemPosImm8Offset }, },
  { 397 /* ldrbt */, ARM::LDRBT_POST_IMM, Convert__Reg1_1__MemNoOffset1_2__Tie1__AM2OffsetImm2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_AM2OffsetImm }, },
  { 397 /* ldrbt */, ARM::LDRBT_POST_REG, Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxRegShifted2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_PostIdxRegShifted }, },
  { 403 /* ldrd */, ARM::t2LDRDi8, Convert__Reg1_1__Reg1_2__MemImm8s4Offset2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_MemImm8s4Offset }, },
  { 403 /* ldrd */, ARM::LDRD, Convert__Reg1_1__Reg1_2__AddrMode33_3__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_AddrMode3 }, },
  { 403 /* ldrd */, ARM::t2LDRD_PRE, Convert__Reg1_1__Reg1_2__imm_0__MemImm8s4Offset2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_MemImm8s4Offset, MCK__EXCLAIM_ }, },
  { 403 /* ldrd */, ARM::t2LDRD_POST, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__Tie2__Imm1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_MemNoOffset, MCK_Imm }, },
  { 403 /* ldrd */, ARM::LDRD_PRE, Convert__Reg1_1__Reg1_2__imm_0__AddrMode33_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_AddrMode3, MCK__EXCLAIM_ }, },
  { 403 /* ldrd */, ARM::LDRD_POST, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__Tie2__AM3Offset2_4__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_MemNoOffset, MCK_AM3Offset }, },
  { 408 /* ldrex */, ARM::t2LDREX, Convert__Reg1_1__MemImm0_1020s4Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemImm0_1020s4Offset }, },
  { 408 /* ldrex */, ARM::LDREX, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset }, },
  { 414 /* ldrexb */, ARM::t2LDREXB, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemNoOffset }, },
  { 414 /* ldrexb */, ARM::LDREXB, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset }, },
  { 421 /* ldrexd */, ARM::LDREXD, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRPair, MCK_MemNoOffset }, },
  { 421 /* ldrexd */, ARM::t2LDREXD, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_MemNoOffset }, },
  { 428 /* ldrexh */, ARM::t2LDREXH, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemNoOffset }, },
  { 428 /* ldrexh */, ARM::LDREXH, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset }, },
  { 435 /* ldrh */, ARM::tLDRHi, Convert__Reg1_1__MemThumbRIs22_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRIs2 }, },
  { 435 /* ldrh */, ARM::tLDRHr, Convert__Reg1_1__MemThumbRR2_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRR }, },
  { 435 /* ldrh */, ARM::t2LDRHpci, Convert__Reg1_1__Imm1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Imm }, },
  { 435 /* ldrh */, ARM::t2LDRHi12, Convert__Reg1_1__MemUImm12Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemUImm12Offset }, },
  { 435 /* ldrh */, ARM::t2LDRHs, Convert__Reg1_1__T2MemRegOffset3_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_T2MemRegOffset }, },
  { 435 /* ldrh */, ARM::t2LDRHpcrel, Convert__Reg1_1__MemPCRelImm121_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_MemPCRelImm12 }, },
  { 435 /* ldrh */, ARM::LDRH, Convert__Reg1_1__AddrMode33_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_AddrMode3 }, },
  { 435 /* ldrh */, ARM::t2LDRHi8, Convert__Reg1_1__MemNegImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemNegImm8Offset }, },
  { 435 /* ldrh */, ARM::t2LDRHpcrel, Convert__Reg1_2__MemPCRelImm121_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_MemPCRelImm12 }, },
  { 435 /* ldrh */, ARM::t2LDRHpci, Convert__Reg1_2__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_Imm }, },
  { 435 /* ldrh */, ARM::t2LDRHi12, Convert__Reg1_2__MemUImm12Offset2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_MemUImm12Offset }, },
  { 435 /* ldrh */, ARM::t2LDRHs, Convert__Reg1_2__T2MemRegOffset3_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_T2MemRegOffset }, },
  { 435 /* ldrh */, ARM::LDRH_PRE, Convert__Reg1_1__imm_0__AddrMode33_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_AddrMode3, MCK__EXCLAIM_ }, },
  { 435 /* ldrh */, ARM::t2LDRH_PRE, Convert__Reg1_1__imm_0__MemImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemImm8Offset, MCK__EXCLAIM_ }, },
  { 435 /* ldrh */, ARM::LDRH_POST, Convert__Reg1_1__MemNoOffset1_2__Tie1__AM3Offset2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_AM3Offset }, },
  { 435 /* ldrh */, ARM::t2LDRH_POST, Convert__Reg1_1__MemNoOffset1_2__Tie1__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_Imm }, },
  { 440 /* ldrht */, ARM::t2LDRHT, Convert__Reg1_1__MemPosImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemPosImm8Offset }, },
  { 440 /* ldrht */, ARM::LDRHTr, Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxReg2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_MemNoOffset, MCK_PostIdxReg }, },
  { 440 /* ldrht */, ARM::LDRHTi, Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxImm81_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_PostIdxImm8 }, },
  { 446 /* ldrsb */, ARM::tLDRSB, Convert__Reg1_1__MemThumbRR2_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRR }, },
  { 446 /* ldrsb */, ARM::t2LDRSBpci, Convert__Reg1_1__Imm1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Imm }, },
  { 446 /* ldrsb */, ARM::t2LDRSBi12, Convert__Reg1_1__MemUImm12Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemUImm12Offset }, },
  { 446 /* ldrsb */, ARM::t2LDRSBs, Convert__Reg1_1__T2MemRegOffset3_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_T2MemRegOffset }, },
  { 446 /* ldrsb */, ARM::t2LDRSBpcrel, Convert__Reg1_1__MemPCRelImm121_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_MemPCRelImm12 }, },
  { 446 /* ldrsb */, ARM::LDRSB, Convert__Reg1_1__AddrMode33_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_AddrMode3 }, },
  { 446 /* ldrsb */, ARM::t2LDRSBi8, Convert__Reg1_1__MemNegImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemNegImm8Offset }, },
  { 446 /* ldrsb */, ARM::t2LDRSBpcrel, Convert__Reg1_2__MemPCRelImm121_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_MemPCRelImm12 }, },
  { 446 /* ldrsb */, ARM::t2LDRSBpci, Convert__Reg1_2__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_Imm }, },
  { 446 /* ldrsb */, ARM::t2LDRSBi12, Convert__Reg1_2__MemUImm12Offset2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_MemUImm12Offset }, },
  { 446 /* ldrsb */, ARM::t2LDRSBs, Convert__Reg1_2__T2MemRegOffset3_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_T2MemRegOffset }, },
  { 446 /* ldrsb */, ARM::LDRSB_PRE, Convert__Reg1_1__imm_0__AddrMode33_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_AddrMode3, MCK__EXCLAIM_ }, },
  { 446 /* ldrsb */, ARM::t2LDRSB_PRE, Convert__Reg1_1__imm_0__MemImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemImm8Offset, MCK__EXCLAIM_ }, },
  { 446 /* ldrsb */, ARM::LDRSB_POST, Convert__Reg1_1__MemNoOffset1_2__Tie1__AM3Offset2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_AM3Offset }, },
  { 446 /* ldrsb */, ARM::t2LDRSB_POST, Convert__Reg1_1__MemNoOffset1_2__Tie1__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_Imm }, },
  { 452 /* ldrsbt */, ARM::t2LDRSBT, Convert__Reg1_1__MemPosImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemPosImm8Offset }, },
  { 452 /* ldrsbt */, ARM::LDRSBTr, Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxReg2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_MemNoOffset, MCK_PostIdxReg }, },
  { 452 /* ldrsbt */, ARM::LDRSBTi, Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxImm81_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_PostIdxImm8 }, },
  { 459 /* ldrsh */, ARM::tLDRSH, Convert__Reg1_1__MemThumbRR2_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRR }, },
  { 459 /* ldrsh */, ARM::t2LDRSHpci, Convert__Reg1_1__Imm1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Imm }, },
  { 459 /* ldrsh */, ARM::t2LDRSHi12, Convert__Reg1_1__MemUImm12Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemUImm12Offset }, },
  { 459 /* ldrsh */, ARM::t2LDRSHs, Convert__Reg1_1__T2MemRegOffset3_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_T2MemRegOffset }, },
  { 459 /* ldrsh */, ARM::t2LDRSHpcrel, Convert__Reg1_1__MemPCRelImm121_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_MemPCRelImm12 }, },
  { 459 /* ldrsh */, ARM::LDRSH, Convert__Reg1_1__AddrMode33_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_AddrMode3 }, },
  { 459 /* ldrsh */, ARM::t2LDRSHi8, Convert__Reg1_1__MemNegImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemNegImm8Offset }, },
  { 459 /* ldrsh */, ARM::t2LDRSHpcrel, Convert__Reg1_2__MemPCRelImm121_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_MemPCRelImm12 }, },
  { 459 /* ldrsh */, ARM::t2LDRSHpci, Convert__Reg1_2__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_Imm }, },
  { 459 /* ldrsh */, ARM::t2LDRSHi12, Convert__Reg1_2__MemUImm12Offset2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_MemUImm12Offset }, },
  { 459 /* ldrsh */, ARM::t2LDRSHs, Convert__Reg1_2__T2MemRegOffset3_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_T2MemRegOffset }, },
  { 459 /* ldrsh */, ARM::LDRSH_PRE, Convert__Reg1_1__imm_0__AddrMode33_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_AddrMode3, MCK__EXCLAIM_ }, },
  { 459 /* ldrsh */, ARM::t2LDRSH_PRE, Convert__Reg1_1__imm_0__MemImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemImm8Offset, MCK__EXCLAIM_ }, },
  { 459 /* ldrsh */, ARM::LDRSH_POST, Convert__Reg1_1__MemNoOffset1_2__Tie1__AM3Offset2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_AM3Offset }, },
  { 459 /* ldrsh */, ARM::t2LDRSH_POST, Convert__Reg1_1__MemNoOffset1_2__Tie1__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_Imm }, },
  { 465 /* ldrsht */, ARM::t2LDRSHT, Convert__Reg1_1__MemPosImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemPosImm8Offset }, },
  { 465 /* ldrsht */, ARM::LDRSHTr, Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxReg2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_MemNoOffset, MCK_PostIdxReg }, },
  { 465 /* ldrsht */, ARM::LDRSHTi, Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxImm81_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_PostIdxImm8 }, },
  { 472 /* ldrt */, ARM::t2LDRT, Convert__Reg1_1__MemPosImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemPosImm8Offset }, },
  { 472 /* ldrt */, ARM::LDRT_POST_IMM, Convert__Reg1_1__MemNoOffset1_2__Tie1__AM2OffsetImm2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_AM2OffsetImm }, },
  { 472 /* ldrt */, ARM::LDRT_POST_REG, Convert__Reg1_1__MemNoOffset1_2__Tie1__PostIdxRegShifted2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_PostIdxRegShifted }, },
  { 477 /* lsl */, ARM::tLSLrr, Convert__Reg1_2__CCOut1_0__Tie0__Reg1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 477 /* lsl */, ARM::tLSLri, Convert__Reg1_2__CCOut1_0__Reg1_2__Imm0_311_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_Imm0_31 }, },
  { 477 /* lsl */, ARM::t2LSLrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 477 /* lsl */, ARM::t2LSLri, Convert__Reg1_2__Reg1_2__Imm0_311_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_Imm0_31 }, },
  { 477 /* lsl */, ARM::LSLr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc }, },
  { 477 /* lsl */, ARM::LSLi, Convert__Reg1_2__Reg1_2__Imm0_311_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_Imm0_31 }, },
  { 477 /* lsl */, ARM::t2LSLrr, Convert__Reg1_3__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 477 /* lsl */, ARM::t2LSLri, Convert__Reg1_3__Reg1_3__Imm0_311_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_Imm0_31 }, },
  { 477 /* lsl */, ARM::tLSLri, Convert__Reg1_2__CCOut1_0__Reg1_3__Imm0_311_4__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR, MCK_Imm0_31 }, },
  { 477 /* lsl */, ARM::t2LSLrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 477 /* lsl */, ARM::t2LSLri, Convert__Reg1_2__Reg1_3__Imm0_311_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_Imm0_31 }, },
  { 477 /* lsl */, ARM::LSLr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 477 /* lsl */, ARM::LSLi, Convert__Reg1_2__Reg1_3__Imm0_311_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_Imm0_31 }, },
  { 477 /* lsl */, ARM::t2LSLrr, Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 477 /* lsl */, ARM::t2LSLri, Convert__Reg1_3__Reg1_4__Imm0_311_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_Imm0_31 }, },
  { 481 /* lsr */, ARM::tLSRrr, Convert__Reg1_2__CCOut1_0__Tie0__Reg1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 481 /* lsr */, ARM::tLSRri, Convert__Reg1_2__CCOut1_0__Reg1_2__ImmThumbSR1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_ImmThumbSR }, },
  { 481 /* lsr */, ARM::t2LSRrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 481 /* lsr */, ARM::t2LSRri, Convert__Reg1_2__Reg1_2__ImmThumbSR1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_ImmThumbSR }, },
  { 481 /* lsr */, ARM::LSRr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc }, },
  { 481 /* lsr */, ARM::LSRi, Convert__Reg1_2__Reg1_2__Imm0_321_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_Imm0_32 }, },
  { 481 /* lsr */, ARM::t2LSRrr, Convert__Reg1_3__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 481 /* lsr */, ARM::t2LSRri, Convert__Reg1_3__Reg1_3__ImmThumbSR1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_ImmThumbSR }, },
  { 481 /* lsr */, ARM::tLSRri, Convert__Reg1_2__CCOut1_0__Reg1_3__ImmThumbSR1_4__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR, MCK_ImmThumbSR }, },
  { 481 /* lsr */, ARM::t2LSRrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 481 /* lsr */, ARM::t2LSRri, Convert__Reg1_2__Reg1_3__ImmThumbSR1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_ImmThumbSR }, },
  { 481 /* lsr */, ARM::LSRr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 481 /* lsr */, ARM::LSRi, Convert__Reg1_2__Reg1_3__Imm0_321_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_Imm0_32 }, },
  { 481 /* lsr */, ARM::t2LSRrr, Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 481 /* lsr */, ARM::t2LSRri, Convert__Reg1_3__Reg1_4__ImmThumbSR1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_ImmThumbSR }, },
  { 485 /* mcr */, ARM::MCR, Convert__CoprocNum1_1__Imm0_71_2__Reg1_3__CoprocReg1_4__CoprocReg1_5__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_7, MCK_GPR, MCK_CoprocReg, MCK_CoprocReg }, },
  { 485 /* mcr */, ARM::t2MCR, Convert__CoprocNum1_1__Imm0_71_2__Reg1_3__CoprocReg1_4__CoprocReg1_5__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_7, MCK_GPR, MCK_CoprocReg, MCK_CoprocReg }, },
  { 485 /* mcr */, ARM::MCR, Convert__CoprocNum1_1__Imm0_71_2__Reg1_3__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_7, MCK_GPR, MCK_CoprocReg, MCK_CoprocReg, MCK_Imm0_7 }, },
  { 485 /* mcr */, ARM::t2MCR, Convert__CoprocNum1_1__Imm0_71_2__Reg1_3__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_7, MCK_GPR, MCK_CoprocReg, MCK_CoprocReg, MCK_Imm0_7 }, },
  { 489 /* mcr2 */, ARM::MCR2, Convert__CoprocNum1_0__Imm0_71_1__Reg1_2__CoprocReg1_3__CoprocReg1_4__imm_0, Feature_IsARM, { MCK_CoprocNum, MCK_Imm0_7, MCK_GPR, MCK_CoprocReg, MCK_CoprocReg }, },
  { 489 /* mcr2 */, ARM::t2MCR2, Convert__CoprocNum1_1__Imm0_71_2__Reg1_3__CoprocReg1_4__CoprocReg1_5__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_7, MCK_GPR, MCK_CoprocReg, MCK_CoprocReg }, },
  { 489 /* mcr2 */, ARM::MCR2, Convert__CoprocNum1_0__Imm0_71_1__Reg1_2__CoprocReg1_3__CoprocReg1_4__Imm0_71_5, Feature_PreV8, { MCK_CoprocNum, MCK_Imm0_7, MCK_GPR, MCK_CoprocReg, MCK_CoprocReg, MCK_Imm0_7 }, },
  { 489 /* mcr2 */, ARM::t2MCR2, Convert__CoprocNum1_1__Imm0_71_2__Reg1_3__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0, Feature_IsThumb2|Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_7, MCK_GPR, MCK_CoprocReg, MCK_CoprocReg, MCK_Imm0_7 }, },
  { 494 /* mcrr */, ARM::MCRR, Convert__CoprocNum1_1__Imm0_151_2__Reg1_3__Reg1_4__CoprocReg1_5__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_15, MCK_GPRnopc, MCK_GPRnopc, MCK_CoprocReg }, },
  { 494 /* mcrr */, ARM::t2MCRR, Convert__CoprocNum1_1__Imm0_151_2__Reg1_3__Reg1_4__CoprocReg1_5__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_15, MCK_GPR, MCK_GPR, MCK_CoprocReg }, },
  { 499 /* mcrr2 */, ARM::MCRR2, Convert__CoprocNum1_0__Imm0_151_1__Reg1_2__Reg1_3__CoprocReg1_4, Feature_PreV8, { MCK_CoprocNum, MCK_Imm0_15, MCK_GPRnopc, MCK_GPRnopc, MCK_CoprocReg }, },
  { 499 /* mcrr2 */, ARM::t2MCRR2, Convert__CoprocNum1_1__Imm0_151_2__Reg1_3__Reg1_4__CoprocReg1_5__CondCode2_0, Feature_IsThumb2|Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_15, MCK_GPR, MCK_GPR, MCK_CoprocReg }, },
  { 505 /* mla */, ARM::t2MLA, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 505 /* mla */, ARM::MLA, Convert__Reg1_2__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsARM|Feature_HasV6, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 509 /* mls */, ARM::t2MLS, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 509 /* mls */, ARM::MLS, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6T2, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 513 /* mov */, ARM::t2MOVi16, Convert__Reg1_1__Imm256_65535Expr1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Imm256_65535Expr }, },
  { 513 /* mov */, ARM::t2MOVsi, Convert__Reg1_1__RegShiftedImm2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_RegShiftedImm }, },
  { 513 /* mov */, ARM::t2MOVsr, Convert__Reg1_1__RegShiftedReg3_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_RegShiftedReg }, },
  { 513 /* mov */, ARM::t2MOVi, Convert__Reg1_1__T2SOImm1_2__CondCode2_0__reg0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_T2SOImm }, },
  { 513 /* mov */, ARM::t2MVNi, Convert__Reg1_1__T2SOImmNot1_2__CondCode2_0__reg0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_T2SOImmNot }, },
  { 513 /* mov */, ARM::MOVPCLR, Convert__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_PC, MCK_LR }, },
  { 513 /* mov */, ARM::tMOVr, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 513 /* mov */, ARM::MOVi16, Convert__Reg1_1__Imm0_65535Expr1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_Imm0_65535Expr }, },
  { 513 /* mov */, ARM::tMOVi8, Convert__Reg1_2__CCOut1_0__Imm0_2551_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_Imm0_255 }, },
  { 513 /* mov */, ARM::MOVr_TC, Convert__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_tcGPR, MCK_tcGPR }, },
  { 513 /* mov */, ARM::MVNi, Convert__Reg1_2__ARMSOImmNot1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_ARMSOImmNot }, },
  { 513 /* mov */, ARM::MOVsr, Convert__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_RegShiftedReg }, },
  { 513 /* mov */, ARM::MOVr, Convert__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 513 /* mov */, ARM::MOVi, Convert__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 513 /* mov */, ARM::MOVsi, Convert__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 513 /* mov */, ARM::t2MOVi, Convert__Reg1_2__T2SOImm1_3__CondCode2_0__reg0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_T2SOImm }, },
  { 513 /* mov */, ARM::t2MOVr, Convert__Reg1_2__Reg1_3__CondCode2_0__reg0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_GPR }, },
  { 513 /* mov */, ARM::t2MOVi, Convert__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_T2SOImm }, },
  { 513 /* mov */, ARM::t2MOVr, Convert__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_GPR }, },
  { 517 /* movs */, ARM::tMOVSr, Convert__Reg1_0__Reg1_1, Feature_IsThumb, { MCK_tGPR, MCK_tGPR }, },
  { 517 /* movs */, ARM::tMOVi8, Convert__Reg1_0__regCPSR__Imm0_2551_1__imm_14__imm_0, Feature_IsThumb, { MCK_tGPR, MCK_Imm0_255 }, },
  { 517 /* movs */, ARM::t2MOVSsi, Convert__Reg1_1__RegShiftedImm2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_RegShiftedImm }, },
  { 517 /* movs */, ARM::t2MOVSsr, Convert__Reg1_1__RegShiftedReg3_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_RegShiftedReg }, },
  { 517 /* movs */, ARM::t2MOVi, Convert__Reg1_1__T2SOImm1_2__CondCode2_0__regCPSR, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_T2SOImm }, },
  { 517 /* movs */, ARM::t2MOVr, Convert__Reg1_1__Reg1_2__CondCode2_0__regCPSR, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_GPR }, },
  { 517 /* movs */, ARM::t2MOVi, Convert__Reg1_2__T2SOImm1_3__CondCode2_0__regCPSR, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_T2SOImm }, },
  { 517 /* movs */, ARM::t2MOVr, Convert__Reg1_2__Reg1_3__CondCode2_0__regCPSR, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_GPR }, },
  { 522 /* movt */, ARM::t2MOVTi16, Convert__Reg1_1__Tie0__Imm0_65535Expr1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Imm0_65535Expr }, },
  { 522 /* movt */, ARM::MOVTi16, Convert__Reg1_1__Tie0__Imm0_65535Expr1_2__CondCode2_0, Feature_IsARM|Feature_HasV6T2, { MCK_CondCode, MCK_GPRnopc, MCK_Imm0_65535Expr }, },
  { 527 /* movw */, ARM::t2MOVi16, Convert__Reg1_1__Imm0_65535Expr1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Imm0_65535Expr }, },
  { 527 /* movw */, ARM::MOVi16, Convert__Reg1_1__Imm0_65535Expr1_2__CondCode2_0, Feature_IsARM|Feature_HasV6T2, { MCK_CondCode, MCK_GPR, MCK_Imm0_65535Expr }, },
  { 532 /* mrc */, ARM::MRC, Convert__Reg1_3__CoprocNum1_1__Imm0_71_2__CoprocReg1_4__CoprocReg1_5__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_7, MCK_GPRwithAPSR, MCK_CoprocReg, MCK_CoprocReg }, },
  { 532 /* mrc */, ARM::t2MRC, Convert__Reg1_3__CoprocNum1_1__Imm0_71_2__CoprocReg1_4__CoprocReg1_5__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_7, MCK_GPRwithAPSR, MCK_CoprocReg, MCK_CoprocReg }, },
  { 532 /* mrc */, ARM::MRC, Convert__Reg1_3__CoprocNum1_1__Imm0_71_2__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_7, MCK_GPRwithAPSR, MCK_CoprocReg, MCK_CoprocReg, MCK_Imm0_7 }, },
  { 532 /* mrc */, ARM::t2MRC, Convert__Reg1_3__CoprocNum1_1__Imm0_71_2__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_7, MCK_GPRwithAPSR, MCK_CoprocReg, MCK_CoprocReg, MCK_Imm0_7 }, },
  { 536 /* mrc2 */, ARM::MRC2, Convert__Reg1_2__CoprocNum1_0__Imm0_71_1__CoprocReg1_3__CoprocReg1_4__imm_0, Feature_IsARM, { MCK_CoprocNum, MCK_Imm0_7, MCK_GPRwithAPSR, MCK_CoprocReg, MCK_CoprocReg }, },
  { 536 /* mrc2 */, ARM::t2MRC2, Convert__Reg1_3__CoprocNum1_1__Imm0_71_2__CoprocReg1_4__CoprocReg1_5__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_7, MCK_GPRwithAPSR, MCK_CoprocReg, MCK_CoprocReg }, },
  { 536 /* mrc2 */, ARM::MRC2, Convert__Reg1_2__CoprocNum1_0__Imm0_71_1__CoprocReg1_3__CoprocReg1_4__Imm0_71_5, Feature_PreV8, { MCK_CoprocNum, MCK_Imm0_7, MCK_GPRwithAPSR, MCK_CoprocReg, MCK_CoprocReg, MCK_Imm0_7 }, },
  { 536 /* mrc2 */, ARM::t2MRC2, Convert__Reg1_3__CoprocNum1_1__Imm0_71_2__CoprocReg1_4__CoprocReg1_5__Imm0_71_6__CondCode2_0, Feature_IsThumb2|Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_7, MCK_GPRwithAPSR, MCK_CoprocReg, MCK_CoprocReg, MCK_Imm0_7 }, },
  { 541 /* mrrc */, ARM::MRRC, Convert__CoprocNum1_1__Imm0_151_2__Reg1_3__Reg1_4__CoprocReg1_5__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_15, MCK_GPRnopc, MCK_GPRnopc, MCK_CoprocReg }, },
  { 541 /* mrrc */, ARM::t2MRRC, Convert__CoprocNum1_1__Imm0_151_2__Reg1_3__Reg1_4__CoprocReg1_5__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_15, MCK_GPR, MCK_GPR, MCK_CoprocReg }, },
  { 546 /* mrrc2 */, ARM::MRRC2, Convert__CoprocNum1_0__Imm0_151_1__Reg1_2__Reg1_3__CoprocReg1_4, Feature_PreV8, { MCK_CoprocNum, MCK_Imm0_15, MCK_GPRnopc, MCK_GPRnopc, MCK_CoprocReg }, },
  { 546 /* mrrc2 */, ARM::t2MRRC2, Convert__CoprocNum1_1__Imm0_151_2__Reg1_3__Reg1_4__CoprocReg1_5__CondCode2_0, Feature_IsThumb2|Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_Imm0_15, MCK_GPR, MCK_GPR, MCK_CoprocReg }, },
  { 552 /* mrs */, ARM::t2MRS_M, Convert__Reg1_1__MSRMask1_2__CondCode2_0, Feature_IsThumb|Feature_IsMClass, { MCK_CondCode, MCK_rGPR, MCK_MSRMask }, },
  { 552 /* mrs */, ARM::MRS, Convert__Reg1_1__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_CCR }, },
  { 552 /* mrs */, ARM::MRS, Convert__Reg1_1__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_APSR }, },
  { 552 /* mrs */, ARM::MRSsys, Convert__Reg1_1__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_SPSR }, },
  { 552 /* mrs */, ARM::t2MRS_AR, Convert__Reg1_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_CCR }, },
  { 552 /* mrs */, ARM::t2MRS_AR, Convert__Reg1_1__CondCode2_0, Feature_IsThumb2|Feature_IsNotMClass, { MCK_CondCode, MCK_GPR, MCK_APSR }, },
  { 552 /* mrs */, ARM::t2MRSsys_AR, Convert__Reg1_1__CondCode2_0, Feature_IsThumb2|Feature_IsNotMClass, { MCK_CondCode, MCK_GPR, MCK_SPSR }, },
  { 556 /* msr */, ARM::t2MSR_AR, Convert__MSRMask1_1__Reg1_2__CondCode2_0, Feature_IsThumb2|Feature_IsNotMClass, { MCK_CondCode, MCK_MSRMask, MCK_rGPR }, },
  { 556 /* msr */, ARM::t2MSR_M, Convert__MSRMask1_1__Reg1_2__CondCode2_0, Feature_IsThumb|Feature_IsMClass, { MCK_CondCode, MCK_MSRMask, MCK_rGPR }, },
  { 556 /* msr */, ARM::MSR, Convert__MSRMask1_1__Reg1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_MSRMask, MCK_GPR }, },
  { 556 /* msr */, ARM::MSRi, Convert__MSRMask1_1__ARMSOImm1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_MSRMask, MCK_ARMSOImm }, },
  { 560 /* mul */, ARM::t2MUL, Convert__Reg1_1__Reg1_2__Reg1_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 560 /* mul */, ARM::tMUL, ConvertCustom_cvtThumbMultiply, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 560 /* mul */, ARM::MUL, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM|Feature_HasV6, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc }, },
  { 560 /* mul */, ARM::t2MUL, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 560 /* mul */, ARM::tMUL, ConvertCustom_cvtThumbMultiply, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR, MCK_tGPR }, },
  { 560 /* mul */, ARM::MUL, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM|Feature_HasV6, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 564 /* mvn */, ARM::t2MOVi, Convert__Reg1_1__T2SOImmNot1_2__CondCode2_0__reg0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_T2SOImmNot }, },
  { 564 /* mvn */, ARM::tMVN, Convert__Reg1_2__CCOut1_0__Reg1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 564 /* mvn */, ARM::t2MVNr, Convert__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 564 /* mvn */, ARM::t2MVNs, Convert__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_RegShiftedImm }, },
  { 564 /* mvn */, ARM::MOVi, Convert__Reg1_2__ARMSOImmNot1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_ARMSOImmNot }, },
  { 564 /* mvn */, ARM::t2MVNi, Convert__Reg1_2__T2SOImm1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_T2SOImm }, },
  { 564 /* mvn */, ARM::MVNr, Convert__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 564 /* mvn */, ARM::MVNi, Convert__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 564 /* mvn */, ARM::MVNsi, Convert__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 564 /* mvn */, ARM::MVNsr, Convert__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedReg }, },
  { 564 /* mvn */, ARM::t2MVNr, Convert__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 564 /* mvn */, ARM::t2MVNs, Convert__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_RegShiftedImm }, },
  { 564 /* mvn */, ARM::t2MVNi, Convert__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_T2SOImm }, },
  { 568 /* neg */, ARM::tRSB, Convert__Reg1_2__CCOut1_0__Reg1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 568 /* neg */, ARM::t2RSBri, Convert__Reg1_2__Reg1_3__imm_0__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 568 /* neg */, ARM::RSBri, Convert__Reg1_2__Reg1_3__imm_0__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 572 /* nop */, ARM::tMOVr, Convert__regR8__regR8__imm_14__imm_0, Feature_IsThumb, {  }, },
  { 572 /* nop */, ARM::HINT, Convert__imm_0__CondCode2_0, Feature_IsARM|Feature_HasV6T2, { MCK_CondCode }, },
  { 572 /* nop */, ARM::tHINT, Convert__imm_0__CondCode2_0, Feature_IsThumb|Feature_HasV6M, { MCK_CondCode }, },
  { 572 /* nop */, ARM::MOVr, Convert__regR0__regR0__CondCode2_0__reg0, Feature_IsARM, { MCK_CondCode }, },
  { 572 /* nop */, ARM::t2HINT, Convert__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w }, },
  { 576 /* orn */, ARM::t2ORNrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 576 /* orn */, ARM::t2ORNrs, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_RegShiftedImm }, },
  { 576 /* orn */, ARM::t2ORNri, Convert__Reg1_2__Reg1_2__T2SOImm1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_T2SOImm }, },
  { 576 /* orn */, ARM::t2ORNrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 576 /* orn */, ARM::t2ORNrs, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 576 /* orn */, ARM::t2ORNri, Convert__Reg1_2__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_T2SOImm }, },
  { 580 /* orr */, ARM::tORR, Convert__Reg1_2__CCOut1_0__Tie0__Reg1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 580 /* orr */, ARM::t2ORRrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 580 /* orr */, ARM::t2ORRrs, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_RegShiftedImm }, },
  { 580 /* orr */, ARM::t2ORRri, Convert__Reg1_2__Reg1_2__T2SOImm1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_T2SOImm }, },
  { 580 /* orr */, ARM::ORRrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 580 /* orr */, ARM::ORRri, Convert__Reg1_2__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 580 /* orr */, ARM::ORRrsi, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 580 /* orr */, ARM::ORRrsr, Convert__Reg1_2__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedReg }, },
  { 580 /* orr */, ARM::t2ORRrr, Convert__Reg1_3__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 580 /* orr */, ARM::t2ORRrs, Convert__Reg1_3__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_RegShiftedImm }, },
  { 580 /* orr */, ARM::t2ORRri, Convert__Reg1_3__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_T2SOImm }, },
  { 580 /* orr */, ARM::t2ORRrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 580 /* orr */, ARM::t2ORRrs, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 580 /* orr */, ARM::t2ORRri, Convert__Reg1_2__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_T2SOImm }, },
  { 580 /* orr */, ARM::ORRrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 580 /* orr */, ARM::ORRri, Convert__Reg1_2__Reg1_3__ARMSOImm1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_ARMSOImm }, },
  { 580 /* orr */, ARM::ORRrsi, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedImm }, },
  { 580 /* orr */, ARM::ORRrsr, Convert__Reg1_2__Reg1_3__RegShiftedReg3_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedReg }, },
  { 580 /* orr */, ARM::t2ORRrr, Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 580 /* orr */, ARM::t2ORRrs, Convert__Reg1_3__Reg1_4__RegShiftedImm2_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 580 /* orr */, ARM::t2ORRri, Convert__Reg1_3__Reg1_4__T2SOImm1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_T2SOImm }, },
  { 584 /* pkhbt */, ARM::t2PKHBT, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_HasT2ExtractPack|Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 584 /* pkhbt */, ARM::PKHBT, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 584 /* pkhbt */, ARM::t2PKHBT, Convert__Reg1_1__Reg1_2__Reg1_3__PKHLSLImm1_4__CondCode2_0, Feature_HasT2ExtractPack|Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_PKHLSLImm }, },
  { 584 /* pkhbt */, ARM::PKHBT, Convert__Reg1_1__Reg1_2__Reg1_3__PKHLSLImm1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_PKHLSLImm }, },
  { 590 /* pkhtb */, ARM::t2PKHBT, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_HasT2ExtractPack|Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 590 /* pkhtb */, ARM::PKHBT, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 590 /* pkhtb */, ARM::t2PKHTB, Convert__Reg1_1__Reg1_2__Reg1_3__PKHASRImm1_4__CondCode2_0, Feature_HasT2ExtractPack|Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_PKHASRImm }, },
  { 590 /* pkhtb */, ARM::PKHTB, Convert__Reg1_1__Reg1_2__Reg1_3__PKHASRImm1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_PKHASRImm }, },
  { 596 /* pld */, ARM::PLDi12, Convert__MemImm12Offset2_0, Feature_IsARM, { MCK_MemImm12Offset }, },
  { 596 /* pld */, ARM::PLDrs, Convert__MemRegOffset3_0, Feature_IsARM, { MCK_MemRegOffset }, },
  { 596 /* pld */, ARM::t2PLDpci, Convert__Imm1_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_Imm }, },
  { 596 /* pld */, ARM::t2PLDi8, Convert__MemNegImm8Offset2_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_MemNegImm8Offset }, },
  { 596 /* pld */, ARM::t2PLDi12, Convert__MemUImm12Offset2_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_MemUImm12Offset }, },
  { 596 /* pld */, ARM::t2PLDs, Convert__T2MemRegOffset3_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_T2MemRegOffset }, },
  { 596 /* pld */, ARM::t2PLDpci, Convert__MemPCRelImm121_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_MemPCRelImm12 }, },
  { 600 /* pldw */, ARM::PLDWi12, Convert__MemImm12Offset2_0, Feature_IsARM|Feature_HasV7|Feature_HasMP, { MCK_MemImm12Offset }, },
  { 600 /* pldw */, ARM::PLDWrs, Convert__MemRegOffset3_0, Feature_IsARM|Feature_HasV7|Feature_HasMP, { MCK_MemRegOffset }, },
  { 600 /* pldw */, ARM::t2PLDWi8, Convert__MemNegImm8Offset2_1__CondCode2_0, Feature_IsThumb2|Feature_HasV7|Feature_HasMP, { MCK_CondCode, MCK_MemNegImm8Offset }, },
  { 600 /* pldw */, ARM::t2PLDWi12, Convert__MemUImm12Offset2_1__CondCode2_0, Feature_IsThumb2|Feature_HasV7|Feature_HasMP, { MCK_CondCode, MCK_MemUImm12Offset }, },
  { 600 /* pldw */, ARM::t2PLDWs, Convert__T2MemRegOffset3_1__CondCode2_0, Feature_IsThumb2|Feature_HasV7|Feature_HasMP, { MCK_CondCode, MCK_T2MemRegOffset }, },
  { 605 /* pli */, ARM::PLIi12, Convert__MemImm12Offset2_0, Feature_IsARM|Feature_HasV7, { MCK_MemImm12Offset }, },
  { 605 /* pli */, ARM::PLIrs, Convert__MemRegOffset3_0, Feature_IsARM|Feature_HasV7, { MCK_MemRegOffset }, },
  { 605 /* pli */, ARM::t2PLIpci, Convert__Imm1_1__CondCode2_0, Feature_IsThumb2|Feature_HasV7, { MCK_CondCode, MCK_Imm }, },
  { 605 /* pli */, ARM::t2PLIi8, Convert__MemNegImm8Offset2_1__CondCode2_0, Feature_IsThumb2|Feature_HasV7, { MCK_CondCode, MCK_MemNegImm8Offset }, },
  { 605 /* pli */, ARM::t2PLIi12, Convert__MemUImm12Offset2_1__CondCode2_0, Feature_IsThumb2|Feature_HasV7, { MCK_CondCode, MCK_MemUImm12Offset }, },
  { 605 /* pli */, ARM::t2PLIs, Convert__T2MemRegOffset3_1__CondCode2_0, Feature_IsThumb2|Feature_HasV7, { MCK_CondCode, MCK_T2MemRegOffset }, },
  { 605 /* pli */, ARM::t2PLIpci, Convert__MemPCRelImm121_1__CondCode2_0, Feature_IsThumb2|Feature_HasV7, { MCK_CondCode, MCK_MemPCRelImm12 }, },
  { 609 /* pop */, ARM::tPOP, Convert__CondCode2_0__RegList1_1, Feature_IsThumb, { MCK_CondCode, MCK_RegList }, },
  { 609 /* pop */, ARM::LDMIA_UPD, Convert__regSP__Tie0__CondCode2_0__RegList1_1, Feature_IsARM, { MCK_CondCode, MCK_RegList }, },
  { 609 /* pop */, ARM::t2LDMIA_UPD, Convert__regSP__Tie0__CondCode2_0__RegList1_1, Feature_IsThumb2, { MCK_CondCode, MCK_RegList }, },
  { 609 /* pop */, ARM::t2LDMIA_UPD, Convert__regSP__Tie0__CondCode2_0__RegList1_2, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_RegList }, },
  { 613 /* push */, ARM::tPUSH, Convert__CondCode2_0__RegList1_1, Feature_IsThumb, { MCK_CondCode, MCK_RegList }, },
  { 613 /* push */, ARM::STMDB_UPD, Convert__regSP__Tie0__CondCode2_0__RegList1_1, Feature_IsARM, { MCK_CondCode, MCK_RegList }, },
  { 613 /* push */, ARM::t2STMDB_UPD, Convert__regSP__Tie0__CondCode2_0__RegList1_1, Feature_IsThumb2, { MCK_CondCode, MCK_RegList }, },
  { 613 /* push */, ARM::t2STMDB_UPD, Convert__regSP__Tie0__CondCode2_0__RegList1_2, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_RegList }, },
  { 618 /* qadd */, ARM::t2QADD, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 618 /* qadd */, ARM::QADD, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 623 /* qadd16 */, ARM::t2QADD16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 623 /* qadd16 */, ARM::QADD16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 630 /* qadd8 */, ARM::t2QADD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 630 /* qadd8 */, ARM::QADD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 636 /* qasx */, ARM::t2QASX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 636 /* qasx */, ARM::QASX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 641 /* qdadd */, ARM::t2QDADD, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 641 /* qdadd */, ARM::QDADD, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 647 /* qdsub */, ARM::t2QDSUB, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 647 /* qdsub */, ARM::QDSUB, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 653 /* qsax */, ARM::t2QSAX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 653 /* qsax */, ARM::QSAX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 658 /* qsub */, ARM::t2QSUB, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 658 /* qsub */, ARM::QSUB, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 663 /* qsub16 */, ARM::t2QSUB16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 663 /* qsub16 */, ARM::QSUB16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 670 /* qsub8 */, ARM::t2QSUB8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 670 /* qsub8 */, ARM::QSUB8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 676 /* rbit */, ARM::t2RBIT, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 676 /* rbit */, ARM::RBIT, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsARM|Feature_HasV6T2, { MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 681 /* rev */, ARM::tREV, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb|Feature_HasV6, { MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 681 /* rev */, ARM::t2REV, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 681 /* rev */, ARM::REV, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 681 /* rev */, ARM::t2REV, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 685 /* rev16 */, ARM::tREV16, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb|Feature_HasV6, { MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 685 /* rev16 */, ARM::t2REV16, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 685 /* rev16 */, ARM::REV16, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 685 /* rev16 */, ARM::t2REV16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 691 /* revsh */, ARM::tREVSH, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb|Feature_HasV6, { MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 691 /* revsh */, ARM::t2REVSH, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 691 /* revsh */, ARM::REVSH, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 691 /* revsh */, ARM::t2REVSH, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 697 /* rfeda */, ARM::RFEDA, Convert__Reg1_0, Feature_IsARM, { MCK_GPR }, },
  { 697 /* rfeda */, ARM::RFEDA_UPD, Convert__Reg1_0, Feature_IsARM, { MCK_GPR, MCK__EXCLAIM_ }, },
  { 703 /* rfedb */, ARM::RFEDB, Convert__Reg1_0, Feature_IsARM, { MCK_GPR }, },
  { 703 /* rfedb */, ARM::RFEDB_UPD, Convert__Reg1_0, Feature_IsARM, { MCK_GPR, MCK__EXCLAIM_ }, },
  { 703 /* rfedb */, ARM::t2RFEDB, Convert__Reg1_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR }, },
  { 703 /* rfedb */, ARM::t2RFEDBW, Convert__Reg1_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_ }, },
  { 709 /* rfeia */, ARM::RFEIA, Convert__Reg1_0, Feature_IsARM, { MCK_GPR }, },
  { 709 /* rfeia */, ARM::RFEIA_UPD, Convert__Reg1_0, Feature_IsARM, { MCK_GPR, MCK__EXCLAIM_ }, },
  { 709 /* rfeia */, ARM::t2RFEIA, Convert__Reg1_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR }, },
  { 709 /* rfeia */, ARM::t2RFEIAW, Convert__Reg1_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_ }, },
  { 715 /* rfeib */, ARM::RFEIB, Convert__Reg1_0, Feature_IsARM, { MCK_GPR }, },
  { 715 /* rfeib */, ARM::RFEIB_UPD, Convert__Reg1_0, Feature_IsARM, { MCK_GPR, MCK__EXCLAIM_ }, },
  { 721 /* ror */, ARM::tROR, Convert__Reg1_2__CCOut1_0__Tie0__Reg1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 721 /* ror */, ARM::t2RORrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 721 /* ror */, ARM::t2RORri, Convert__Reg1_2__Reg1_2__Imm0_311_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_Imm0_31 }, },
  { 721 /* ror */, ARM::RORr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc }, },
  { 721 /* ror */, ARM::RORi, Convert__Reg1_2__Reg1_2__Imm0_311_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_Imm0_31 }, },
  { 721 /* ror */, ARM::t2RORrr, Convert__Reg1_3__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 721 /* ror */, ARM::t2RORri, Convert__Reg1_3__Reg1_3__Imm0_311_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_Imm0_31 }, },
  { 721 /* ror */, ARM::t2RORrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 721 /* ror */, ARM::t2RORri, Convert__Reg1_2__Reg1_3__Imm0_311_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_Imm0_31 }, },
  { 721 /* ror */, ARM::RORr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 721 /* ror */, ARM::RORi, Convert__Reg1_2__Reg1_3__Imm0_311_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_Imm0_31 }, },
  { 721 /* ror */, ARM::t2RORrr, Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 721 /* ror */, ARM::t2RORri, Convert__Reg1_3__Reg1_4__Imm0_311_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_Imm0_31 }, },
  { 725 /* rrx */, ARM::t2RRX, Convert__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 725 /* rrx */, ARM::RRXi, Convert__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 729 /* rsb */, ARM::t2RSBrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 729 /* rsb */, ARM::t2RSBrs, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_RegShiftedImm }, },
  { 729 /* rsb */, ARM::t2RSBri, Convert__Reg1_2__Reg1_2__T2SOImm1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_T2SOImm }, },
  { 729 /* rsb */, ARM::RSBrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 729 /* rsb */, ARM::RSBri, Convert__Reg1_2__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 729 /* rsb */, ARM::RSBrsi, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 729 /* rsb */, ARM::RSBrsr, Convert__Reg1_2__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedReg }, },
  { 729 /* rsb */, ARM::tRSB, Convert__Reg1_2__CCOut1_0__Reg1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR, MCK__35_0 }, },
  { 729 /* rsb */, ARM::t2RSBrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 729 /* rsb */, ARM::t2RSBrs, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 729 /* rsb */, ARM::t2RSBri, Convert__Reg1_2__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_T2SOImm }, },
  { 729 /* rsb */, ARM::RSBrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 729 /* rsb */, ARM::RSBri, Convert__Reg1_2__Reg1_3__ARMSOImm1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_ARMSOImm }, },
  { 729 /* rsb */, ARM::RSBrsi, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedImm }, },
  { 729 /* rsb */, ARM::RSBrsr, Convert__Reg1_2__Reg1_3__RegShiftedReg3_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedReg }, },
  { 729 /* rsb */, ARM::t2RSBri, Convert__Reg1_3__Reg1_4__T2SOImm1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_T2SOImm }, },
  { 733 /* rsc */, ARM::RSCrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 733 /* rsc */, ARM::RSCri, Convert__Reg1_2__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 733 /* rsc */, ARM::RSCrsi, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 733 /* rsc */, ARM::RSCrsr, Convert__Reg1_2__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedReg }, },
  { 733 /* rsc */, ARM::RSCrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 733 /* rsc */, ARM::RSCri, Convert__Reg1_2__Reg1_3__ARMSOImm1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_ARMSOImm }, },
  { 733 /* rsc */, ARM::RSCrsi, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedImm }, },
  { 733 /* rsc */, ARM::RSCrsr, Convert__Reg1_2__Reg1_3__RegShiftedReg3_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedReg }, },
  { 737 /* sadd16 */, ARM::t2SADD16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 737 /* sadd16 */, ARM::SADD16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 744 /* sadd8 */, ARM::t2SADD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 744 /* sadd8 */, ARM::SADD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 750 /* sasx */, ARM::t2SASX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 750 /* sasx */, ARM::SASX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 755 /* sbc */, ARM::tSBC, Convert__Reg1_2__CCOut1_0__Tie0__Reg1_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 755 /* sbc */, ARM::SBCrsr, Convert__Reg1_2__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_RegShiftedReg }, },
  { 755 /* sbc */, ARM::SBCrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 755 /* sbc */, ARM::SBCri, Convert__Reg1_2__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 755 /* sbc */, ARM::SBCrsi, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 755 /* sbc */, ARM::t2SBCrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 755 /* sbc */, ARM::t2SBCrs, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 755 /* sbc */, ARM::t2SBCri, Convert__Reg1_2__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_T2SOImm }, },
  { 755 /* sbc */, ARM::SBCrsr, Convert__Reg1_2__Reg1_3__RegShiftedReg3_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_RegShiftedReg }, },
  { 755 /* sbc */, ARM::SBCrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 755 /* sbc */, ARM::SBCri, Convert__Reg1_2__Reg1_3__ARMSOImm1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_ARMSOImm }, },
  { 755 /* sbc */, ARM::SBCrsi, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedImm }, },
  { 755 /* sbc */, ARM::t2SBCrr, Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 755 /* sbc */, ARM::t2SBCrs, Convert__Reg1_3__Reg1_4__RegShiftedImm2_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_RegShiftedImm }, },
  { 759 /* sbfx */, ARM::t2SBFX, Convert__Reg1_1__Reg1_2__Imm0_311_3__Imm1_321_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_Imm0_31, MCK_Imm1_32 }, },
  { 759 /* sbfx */, ARM::SBFX, Convert__Reg1_1__Reg1_2__Imm0_311_3__Imm1_321_4__CondCode2_0, Feature_IsARM|Feature_HasV6T2, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_Imm0_31, MCK_Imm1_32 }, },
  { 764 /* sdiv */, ARM::t2SDIV, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasDivide|Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 764 /* sdiv */, ARM::SDIV, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasDivideInARM, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 769 /* sel */, ARM::SEL, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 769 /* sel */, ARM::t2SEL, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 773 /* setend */, ARM::SETEND, Convert__SetEndImm1_0, Feature_IsARM, { MCK_SetEndImm }, },
  { 773 /* setend */, ARM::tSETEND, Convert__SetEndImm1_0, Feature_IsThumb, { MCK_SetEndImm }, },
  { 780 /* sev */, ARM::HINT, Convert__imm_4__CondCode2_0, Feature_IsARM|Feature_HasV6T2, { MCK_CondCode }, },
  { 780 /* sev */, ARM::tHINT, Convert__imm_4__CondCode2_0, Feature_IsThumb|Feature_HasV6M, { MCK_CondCode }, },
  { 780 /* sev */, ARM::t2HINT, Convert__imm_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w }, },
  { 784 /* sevl */, ARM::HINT, Convert__imm_5__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode }, },
  { 784 /* sevl */, ARM::tHINT, Convert__imm_5__CondCode2_0, Feature_IsThumb2|Feature_HasV8, { MCK_CondCode }, },
  { 784 /* sevl */, ARM::t2HINT, Convert__imm_5__CondCode2_0, Feature_IsThumb2|Feature_HasV8, { MCK_CondCode, MCK__DOT_w }, },
  { 789 /* sha1c */, ARM::SHA1C, Convert__Reg1_1__Tie0__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 795 /* sha1h */, ARM::SHA1H, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 801 /* sha1m */, ARM::SHA1M, Convert__Reg1_1__Tie0__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 807 /* sha1p */, ARM::SHA1P, Convert__Reg1_1__Tie0__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 813 /* sha1su0 */, ARM::SHA1SU0, Convert__Reg1_1__Tie0__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 821 /* sha1su1 */, ARM::SHA1SU1, Convert__Reg1_1__Tie0__Reg1_2, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 829 /* sha256h */, ARM::SHA256H, Convert__Reg1_1__Tie0__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 837 /* sha256h2 */, ARM::SHA256H2, Convert__Reg1_1__Tie0__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 846 /* sha256su0 */, ARM::SHA256SU0, Convert__Reg1_1__Tie0__Reg1_2, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 856 /* sha256su1 */, ARM::SHA256SU1, Convert__Reg1_1__Tie0__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 866 /* shadd16 */, ARM::t2SHADD16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 866 /* shadd16 */, ARM::SHADD16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 874 /* shadd8 */, ARM::t2SHADD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 874 /* shadd8 */, ARM::SHADD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 881 /* shasx */, ARM::t2SHASX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 881 /* shasx */, ARM::SHASX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 887 /* shsax */, ARM::t2SHSAX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 887 /* shsax */, ARM::SHSAX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 893 /* shsub16 */, ARM::t2SHSUB16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 893 /* shsub16 */, ARM::SHSUB16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 901 /* shsub8 */, ARM::t2SHSUB8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 901 /* shsub8 */, ARM::SHSUB8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 908 /* smc */, ARM::SMC, Convert__Imm0_151_1__CondCode2_0, Feature_IsARM|Feature_HasTrustZone, { MCK_CondCode, MCK_Imm0_15 }, },
  { 908 /* smc */, ARM::t2SMC, Convert__Imm0_151_1__CondCode2_0, Feature_IsThumb2|Feature_HasTrustZone, { MCK_CondCode, MCK_Imm0_15 }, },
  { 912 /* smlabb */, ARM::t2SMLABB, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 912 /* smlabb */, ARM::SMLABB, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPR }, },
  { 919 /* smlabt */, ARM::t2SMLABT, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 919 /* smlabt */, ARM::SMLABT, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPR }, },
  { 926 /* smlad */, ARM::t2SMLAD, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 926 /* smlad */, ARM::SMLAD, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPR }, },
  { 932 /* smladx */, ARM::t2SMLADX, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 932 /* smladx */, ARM::SMLADX, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPR }, },
  { 939 /* smlal */, ARM::t2SMLAL, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__Tie0__Tie1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 939 /* smlal */, ARM::SMLAL, Convert__Reg1_2__Reg1_3__Reg1_4__Reg1_5__Tie0__Tie1__CondCode2_1__CCOut1_0, Feature_IsARM|Feature_HasV6, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 945 /* smlalbb */, ARM::t2SMLALBB, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 945 /* smlalbb */, ARM::SMLALBB, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 953 /* smlalbt */, ARM::t2SMLALBT, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 953 /* smlalbt */, ARM::SMLALBT, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 961 /* smlald */, ARM::t2SMLALD, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 961 /* smlald */, ARM::SMLALD, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 968 /* smlaldx */, ARM::t2SMLALDX, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 968 /* smlaldx */, ARM::SMLALDX, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 976 /* smlaltb */, ARM::t2SMLALTB, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 976 /* smlaltb */, ARM::SMLALTB, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 984 /* smlaltt */, ARM::t2SMLALTT, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 984 /* smlaltt */, ARM::SMLALTT, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 992 /* smlatb */, ARM::t2SMLATB, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 992 /* smlatb */, ARM::SMLATB, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPR }, },
  { 999 /* smlatt */, ARM::t2SMLATT, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 999 /* smlatt */, ARM::SMLATT, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPR }, },
  { 1006 /* smlawb */, ARM::t2SMLAWB, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1006 /* smlawb */, ARM::SMLAWB, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPR }, },
  { 1013 /* smlawt */, ARM::t2SMLAWT, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1013 /* smlawt */, ARM::SMLAWT, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPR }, },
  { 1020 /* smlsd */, ARM::t2SMLSD, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1020 /* smlsd */, ARM::SMLSD, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPR }, },
  { 1026 /* smlsdx */, ARM::t2SMLSDX, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1026 /* smlsdx */, ARM::SMLSDX, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPR }, },
  { 1033 /* smlsld */, ARM::t2SMLSLD, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1033 /* smlsld */, ARM::SMLSLD, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1040 /* smlsldx */, ARM::t2SMLSLDX, Convert__Reg1_1__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1040 /* smlsldx */, ARM::SMLSLDX, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1048 /* smmla */, ARM::t2SMMLA, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1048 /* smmla */, ARM::SMMLA, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1054 /* smmlar */, ARM::t2SMMLAR, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1054 /* smmlar */, ARM::SMMLAR, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1061 /* smmls */, ARM::t2SMMLS, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1061 /* smmls */, ARM::SMMLS, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1067 /* smmlsr */, ARM::t2SMMLSR, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1067 /* smmlsr */, ARM::SMMLSR, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1074 /* smmul */, ARM::t2SMMUL, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1074 /* smmul */, ARM::SMMUL, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1080 /* smmulr */, ARM::t2SMMULR, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1080 /* smmulr */, ARM::SMMULR, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1087 /* smuad */, ARM::t2SMUAD, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1087 /* smuad */, ARM::SMUAD, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1093 /* smuadx */, ARM::t2SMUADX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1093 /* smuadx */, ARM::SMUADX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1100 /* smulbb */, ARM::t2SMULBB, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1100 /* smulbb */, ARM::SMULBB, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1107 /* smulbt */, ARM::t2SMULBT, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1107 /* smulbt */, ARM::SMULBT, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1114 /* smull */, ARM::t2SMULL, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1114 /* smull */, ARM::SMULL, Convert__Reg1_2__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsARM|Feature_HasV6, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1114 /* smull */, ARM::SMULL, Convert__Reg1_2__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1120 /* smultb */, ARM::t2SMULTB, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1120 /* smultb */, ARM::SMULTB, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1127 /* smultt */, ARM::t2SMULTT, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1127 /* smultt */, ARM::SMULTT, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1134 /* smulwb */, ARM::t2SMULWB, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1134 /* smulwb */, ARM::SMULWB, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1141 /* smulwt */, ARM::t2SMULWT, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1141 /* smulwt */, ARM::SMULWT, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1148 /* smusd */, ARM::t2SMUSD, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1148 /* smusd */, ARM::SMUSD, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1154 /* smusdx */, ARM::t2SMUSDX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1154 /* smusdx */, ARM::SMUSDX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1161 /* srsda */, ARM::SRSDA, Convert__Imm0_311_0, Feature_IsARM, { MCK_Imm0_31 }, },
  { 1161 /* srsda */, ARM::SRSDA, Convert__Imm0_311_1, Feature_IsARM, { MCK_GPRsp, MCK_Imm0_31 }, },
  { 1161 /* srsda */, ARM::SRSDA_UPD, Convert__Imm0_311_0, Feature_IsARM, { MCK_Imm0_31, MCK__EXCLAIM_ }, },
  { 1161 /* srsda */, ARM::SRSDA_UPD, Convert__Imm0_311_2, Feature_IsARM, { MCK_GPRsp, MCK__EXCLAIM_, MCK_Imm0_31 }, },
  { 1167 /* srsdb */, ARM::SRSDB, Convert__Imm0_311_0, Feature_IsARM, { MCK_Imm0_31 }, },
  { 1167 /* srsdb */, ARM::SRSDB, Convert__Imm0_311_1, Feature_IsARM, { MCK_GPRsp, MCK_Imm0_31 }, },
  { 1167 /* srsdb */, ARM::t2SRSDB, Convert__Imm0_311_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_Imm0_31 }, },
  { 1167 /* srsdb */, ARM::SRSDB_UPD, Convert__Imm0_311_0, Feature_IsARM, { MCK_Imm0_31, MCK__EXCLAIM_ }, },
  { 1167 /* srsdb */, ARM::SRSDB_UPD, Convert__Imm0_311_2, Feature_IsARM, { MCK_GPRsp, MCK__EXCLAIM_, MCK_Imm0_31 }, },
  { 1167 /* srsdb */, ARM::t2SRSDB, Convert__Imm0_311_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRsp, MCK_Imm0_31 }, },
  { 1167 /* srsdb */, ARM::t2SRSDB_UPD, Convert__Imm0_311_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_Imm0_31, MCK__EXCLAIM_ }, },
  { 1167 /* srsdb */, ARM::t2SRSDB_UPD, Convert__Imm0_311_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRsp, MCK__EXCLAIM_, MCK_Imm0_31 }, },
  { 1173 /* srsia */, ARM::SRSIA, Convert__Imm0_311_0, Feature_IsARM, { MCK_Imm0_31 }, },
  { 1173 /* srsia */, ARM::SRSIA, Convert__Imm0_311_1, Feature_IsARM, { MCK_GPRsp, MCK_Imm0_31 }, },
  { 1173 /* srsia */, ARM::t2SRSIA, Convert__Imm0_311_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_Imm0_31 }, },
  { 1173 /* srsia */, ARM::SRSIA_UPD, Convert__Imm0_311_0, Feature_IsARM, { MCK_Imm0_31, MCK__EXCLAIM_ }, },
  { 1173 /* srsia */, ARM::SRSIA_UPD, Convert__Imm0_311_2, Feature_IsARM, { MCK_GPRsp, MCK__EXCLAIM_, MCK_Imm0_31 }, },
  { 1173 /* srsia */, ARM::t2SRSIA, Convert__Imm0_311_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRsp, MCK_Imm0_31 }, },
  { 1173 /* srsia */, ARM::t2SRSIA_UPD, Convert__Imm0_311_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_Imm0_31, MCK__EXCLAIM_ }, },
  { 1173 /* srsia */, ARM::t2SRSIA_UPD, Convert__Imm0_311_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRsp, MCK__EXCLAIM_, MCK_Imm0_31 }, },
  { 1179 /* srsib */, ARM::SRSIB, Convert__Imm0_311_0, Feature_IsARM, { MCK_Imm0_31 }, },
  { 1179 /* srsib */, ARM::SRSIB, Convert__Imm0_311_1, Feature_IsARM, { MCK_GPRsp, MCK_Imm0_31 }, },
  { 1179 /* srsib */, ARM::SRSIB_UPD, Convert__Imm0_311_0, Feature_IsARM, { MCK_Imm0_31, MCK__EXCLAIM_ }, },
  { 1179 /* srsib */, ARM::SRSIB_UPD, Convert__Imm0_311_2, Feature_IsARM, { MCK_GPRsp, MCK__EXCLAIM_, MCK_Imm0_31 }, },
  { 1185 /* ssat */, ARM::t2SSAT, Convert__Reg1_1__Imm1_321_2__Reg1_3__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Imm1_32, MCK_rGPR }, },
  { 1185 /* ssat */, ARM::SSAT, Convert__Reg1_1__Imm1_321_2__Reg1_3__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_Imm1_32, MCK_GPRnopc }, },
  { 1185 /* ssat */, ARM::t2SSAT, Convert__Reg1_1__Imm1_321_2__Reg1_3__ShifterImm1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Imm1_32, MCK_rGPR, MCK_ShifterImm }, },
  { 1185 /* ssat */, ARM::SSAT, Convert__Reg1_1__Imm1_321_2__Reg1_3__ShifterImm1_4__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_Imm1_32, MCK_GPRnopc, MCK_ShifterImm }, },
  { 1190 /* ssat16 */, ARM::t2SSAT16, Convert__Reg1_1__Imm1_161_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_Imm1_16, MCK_rGPR }, },
  { 1190 /* ssat16 */, ARM::SSAT16, Convert__Reg1_1__Imm1_161_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_Imm1_16, MCK_GPRnopc }, },
  { 1197 /* ssax */, ARM::t2SSAX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1197 /* ssax */, ARM::SSAX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1202 /* ssub16 */, ARM::t2SSUB16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1202 /* ssub16 */, ARM::SSUB16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1209 /* ssub8 */, ARM::t2SSUB8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1209 /* ssub8 */, ARM::SSUB8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1215 /* stc */, ARM::STC_OFFSET, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 1215 /* stc */, ARM::t2STC_OFFSET, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 1215 /* stc */, ARM::STC_PRE, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 1215 /* stc */, ARM::t2STC_PRE, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 1215 /* stc */, ARM::STC_OPTION, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 1215 /* stc */, ARM::t2STC_OPTION, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 1215 /* stc */, ARM::STC_POST, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 1215 /* stc */, ARM::t2STC_POST, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 1219 /* stc2 */, ARM::STC2_OFFSET, Convert__CoprocNum1_0__CoprocReg1_1__AddrMode52_2, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 1219 /* stc2 */, ARM::t2STC2_OFFSET, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 1219 /* stc2 */, ARM::STC2_PRE, Convert__CoprocNum1_0__CoprocReg1_1__AddrMode52_2, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 1219 /* stc2 */, ARM::STC2_OPTION, Convert__CoprocNum1_0__CoprocReg1_1__MemNoOffset1_2__CoprocOption1_3, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 1219 /* stc2 */, ARM::STC2_POST, Convert__CoprocNum1_0__CoprocReg1_1__MemNoOffset1_2__PostIdxImm8s41_3, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 1219 /* stc2 */, ARM::t2STC2_PRE, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 1219 /* stc2 */, ARM::t2STC2_OPTION, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 1219 /* stc2 */, ARM::t2STC2_POST, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 1224 /* stc2l */, ARM::STC2L_OFFSET, Convert__CoprocNum1_0__CoprocReg1_1__AddrMode52_2, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 1224 /* stc2l */, ARM::t2STC2L_OFFSET, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 1224 /* stc2l */, ARM::STC2L_PRE, Convert__CoprocNum1_0__CoprocReg1_1__AddrMode52_2, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 1224 /* stc2l */, ARM::STC2L_OPTION, Convert__CoprocNum1_0__CoprocReg1_1__MemNoOffset1_2__CoprocOption1_3, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 1224 /* stc2l */, ARM::STC2L_POST, Convert__CoprocNum1_0__CoprocReg1_1__MemNoOffset1_2__PostIdxImm8s41_3, Feature_PreV8, { MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 1224 /* stc2l */, ARM::t2STC2L_PRE, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 1224 /* stc2l */, ARM::t2STC2L_OPTION, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 1224 /* stc2l */, ARM::t2STC2L_POST, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 1230 /* stcl */, ARM::STCL_OFFSET, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 1230 /* stcl */, ARM::t2STCL_OFFSET, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5 }, },
  { 1230 /* stcl */, ARM::STCL_PRE, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 1230 /* stcl */, ARM::t2STCL_PRE, Convert__CoprocNum1_1__CoprocReg1_2__AddrMode52_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_AddrMode5, MCK__EXCLAIM_ }, },
  { 1230 /* stcl */, ARM::STCL_OPTION, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 1230 /* stcl */, ARM::t2STCL_OPTION, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__CoprocOption1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_CoprocOption }, },
  { 1230 /* stcl */, ARM::STCL_POST, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 1230 /* stcl */, ARM::t2STCL_POST, Convert__CoprocNum1_1__CoprocReg1_2__MemNoOffset1_3__PostIdxImm8s41_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_CoprocNum, MCK_CoprocReg, MCK_MemNoOffset, MCK_PostIdxImm8s4 }, },
  { 1235 /* stl */, ARM::t2STL, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_MemNoOffset }, },
  { 1235 /* stl */, ARM::STL, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset }, },
  { 1239 /* stlb */, ARM::t2STLB, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_MemNoOffset }, },
  { 1239 /* stlb */, ARM::STLB, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset }, },
  { 1244 /* stlex */, ARM::t2STLEX, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_MemNoOffset }, },
  { 1244 /* stlex */, ARM::STLEX, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_MemNoOffset }, },
  { 1250 /* stlexb */, ARM::t2STLEXB, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_MemNoOffset }, },
  { 1250 /* stlexb */, ARM::STLEXB, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_MemNoOffset }, },
  { 1257 /* stlexd */, ARM::STLEXD, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPR, MCK_GPRPair, MCK_MemNoOffset }, },
  { 1257 /* stlexd */, ARM::t2STLEXD, Convert__Reg1_1__Reg1_2__Reg1_3__MemNoOffset1_4__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_MemNoOffset }, },
  { 1264 /* stlexh */, ARM::t2STLEXH, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_MemNoOffset }, },
  { 1264 /* stlexh */, ARM::STLEXH, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_MemNoOffset }, },
  { 1271 /* stlh */, ARM::t2STLH, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsThumb|Feature_HasV8, { MCK_CondCode, MCK_rGPR, MCK_MemNoOffset }, },
  { 1271 /* stlh */, ARM::STLH, Convert__Reg1_1__MemNoOffset1_2__CondCode2_0, Feature_IsARM|Feature_HasV8, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset }, },
  { 1276 /* stm */, ARM::STMIA, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList }, },
  { 1276 /* stm */, ARM::t2STMIA, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_RegList }, },
  { 1276 /* stm */, ARM::t2STMIA, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_RegList }, },
  { 1276 /* stm */, ARM::t2STMIA, Convert__Reg1_2__CondCode2_0__RegList1_3, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_RegList }, },
  { 1276 /* stm */, ARM::tSTMIA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 1276 /* stm */, ARM::STMIA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 1276 /* stm */, ARM::t2STMIA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 1276 /* stm */, ARM::sysSTMIA, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList, MCK__94_ }, },
  { 1276 /* stm */, ARM::t2STMIA_UPD, Convert__Reg1_2__Tie0__CondCode2_0__RegList1_4, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 1276 /* stm */, ARM::sysSTMIA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList, MCK__94_ }, },
  { 1280 /* stmda */, ARM::STMDA, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList }, },
  { 1280 /* stmda */, ARM::STMDA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 1280 /* stmda */, ARM::sysSTMDA, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList, MCK__94_ }, },
  { 1280 /* stmda */, ARM::sysSTMDA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList, MCK__94_ }, },
  { 1286 /* stmdb */, ARM::STMDB, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList }, },
  { 1286 /* stmdb */, ARM::t2STMDB, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_RegList }, },
  { 1286 /* stmdb */, ARM::t2STMDB, Convert__Reg1_2__CondCode2_0__RegList1_3, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_RegList }, },
  { 1286 /* stmdb */, ARM::STMDB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 1286 /* stmdb */, ARM::t2STMDB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 1286 /* stmdb */, ARM::sysSTMDB, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList, MCK__94_ }, },
  { 1286 /* stmdb */, ARM::t2STMDB_UPD, Convert__Reg1_2__Tie0__CondCode2_0__RegList1_4, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 1286 /* stmdb */, ARM::sysSTMDB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList, MCK__94_ }, },
  { 1292 /* stmib */, ARM::STMIB, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList }, },
  { 1292 /* stmib */, ARM::STMIB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList }, },
  { 1292 /* stmib */, ARM::sysSTMIB, Convert__Reg1_1__CondCode2_0__RegList1_2, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegList, MCK__94_ }, },
  { 1292 /* stmib */, ARM::sysSTMIB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__RegList1_3, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_RegList, MCK__94_ }, },
  { 1298 /* str */, ARM::tSTRi, Convert__Reg1_1__MemThumbRIs42_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRIs4 }, },
  { 1298 /* str */, ARM::tSTRr, Convert__Reg1_1__MemThumbRR2_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRR }, },
  { 1298 /* str */, ARM::tSTRspi, Convert__Reg1_1__MemThumbSPI2_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbSPI }, },
  { 1298 /* str */, ARM::STRi12, Convert__Reg1_1__MemImm12Offset2_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemImm12Offset }, },
  { 1298 /* str */, ARM::t2STRi8, Convert__Reg1_1__MemNegImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemNegImm8Offset }, },
  { 1298 /* str */, ARM::STRrs, Convert__Reg1_1__MemRegOffset3_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemRegOffset }, },
  { 1298 /* str */, ARM::t2STRi12, Convert__Reg1_1__MemUImm12Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_MemUImm12Offset }, },
  { 1298 /* str */, ARM::t2STRs, Convert__Reg1_1__T2MemRegOffset3_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_T2MemRegOffset }, },
  { 1298 /* str */, ARM::t2STRi12, Convert__Reg1_2__MemUImm12Offset2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_MemUImm12Offset }, },
  { 1298 /* str */, ARM::t2STRs, Convert__Reg1_2__T2MemRegOffset3_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPR, MCK_T2MemRegOffset }, },
  { 1298 /* str */, ARM::t2STR_PRE, Convert__imm_0__Reg1_1__MemImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_MemImm8Offset, MCK__EXCLAIM_ }, },
  { 1298 /* str */, ARM::t2STR_POST, Convert__MemNoOffset1_2__Reg1_1__Tie0__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_MemNoOffset, MCK_Imm }, },
  { 1298 /* str */, ARM::STR_PRE_IMM, Convert__imm_0__Reg1_1__MemImm12Offset2_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemImm12Offset, MCK__EXCLAIM_ }, },
  { 1298 /* str */, ARM::STR_POST_IMM, Convert__MemNoOffset1_2__Reg1_1__Tie0__AM2OffsetImm2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_AM2OffsetImm }, },
  { 1298 /* str */, ARM::STR_POST_REG, Convert__MemNoOffset1_2__Reg1_1__Tie0__PostIdxRegShifted2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_PostIdxRegShifted }, },
  { 1298 /* str */, ARM::STR_PRE_REG, Convert__imm_0__Reg1_1__MemRegOffset3_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemRegOffset, MCK__EXCLAIM_ }, },
  { 1302 /* strb */, ARM::tSTRBi, Convert__Reg1_1__MemThumbRIs12_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRIs1 }, },
  { 1302 /* strb */, ARM::tSTRBr, Convert__Reg1_1__MemThumbRR2_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRR }, },
  { 1302 /* strb */, ARM::t2STRBi8, Convert__Reg1_1__MemNegImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemNegImm8Offset }, },
  { 1302 /* strb */, ARM::t2STRBi12, Convert__Reg1_1__MemUImm12Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemUImm12Offset }, },
  { 1302 /* strb */, ARM::t2STRBs, Convert__Reg1_1__T2MemRegOffset3_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_T2MemRegOffset }, },
  { 1302 /* strb */, ARM::STRBi12, Convert__Reg1_1__MemImm12Offset2_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_MemImm12Offset }, },
  { 1302 /* strb */, ARM::STRBrs, Convert__Reg1_1__MemRegOffset3_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_MemRegOffset }, },
  { 1302 /* strb */, ARM::t2STRBi12, Convert__Reg1_2__MemUImm12Offset2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_MemUImm12Offset }, },
  { 1302 /* strb */, ARM::t2STRBs, Convert__Reg1_2__T2MemRegOffset3_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_T2MemRegOffset }, },
  { 1302 /* strb */, ARM::t2STRB_PRE, Convert__imm_0__Reg1_1__MemImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemImm8Offset, MCK__EXCLAIM_ }, },
  { 1302 /* strb */, ARM::t2STRB_POST, Convert__MemNoOffset1_2__Reg1_1__Tie0__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemNoOffset, MCK_Imm }, },
  { 1302 /* strb */, ARM::STRB_PRE_IMM, Convert__imm_0__Reg1_1__MemImm12Offset2_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemImm12Offset, MCK__EXCLAIM_ }, },
  { 1302 /* strb */, ARM::STRB_POST_IMM, Convert__MemNoOffset1_2__Reg1_1__Tie0__AM2OffsetImm2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_AM2OffsetImm }, },
  { 1302 /* strb */, ARM::STRB_POST_REG, Convert__MemNoOffset1_2__Reg1_1__Tie0__PostIdxRegShifted2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_PostIdxRegShifted }, },
  { 1302 /* strb */, ARM::STRB_PRE_REG, Convert__imm_0__Reg1_1__MemRegOffset3_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemRegOffset, MCK__EXCLAIM_ }, },
  { 1307 /* strbt */, ARM::t2STRBT, Convert__Reg1_1__MemImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemImm8Offset }, },
  { 1307 /* strbt */, ARM::STRBT_POST_IMM, Convert__MemNoOffset1_2__Reg1_1__Tie0__AM2OffsetImm2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_AM2OffsetImm }, },
  { 1307 /* strbt */, ARM::STRBT_POST_REG, Convert__MemNoOffset1_2__Reg1_1__Tie0__PostIdxRegShifted2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_PostIdxRegShifted }, },
  { 1313 /* strd */, ARM::STRD, Convert__Reg1_1__Reg1_2__AddrMode33_3__CondCode2_0, Feature_IsARM|Feature_HasV5TE, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_AddrMode3 }, },
  { 1313 /* strd */, ARM::t2STRDi8, Convert__Reg1_1__Reg1_2__MemImm8s4Offset2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_MemImm8s4Offset }, },
  { 1313 /* strd */, ARM::t2STRD_PRE, Convert__imm_0__Reg1_1__Reg1_2__MemImm8s4Offset2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_MemImm8s4Offset, MCK__EXCLAIM_ }, },
  { 1313 /* strd */, ARM::t2STRD_POST, Convert__MemNoOffset1_3__Reg1_1__Reg1_2__Tie0__Imm1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_MemNoOffset, MCK_Imm }, },
  { 1313 /* strd */, ARM::STRD_PRE, Convert__imm_0__Reg1_1__Reg1_2__AddrMode33_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_AddrMode3, MCK__EXCLAIM_ }, },
  { 1313 /* strd */, ARM::STRD_POST, Convert__MemNoOffset1_3__Reg1_1__Reg1_2__Tie0__AM3Offset2_4__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_MemNoOffset, MCK_AM3Offset }, },
  { 1318 /* strex */, ARM::t2STREX, Convert__Reg1_1__Reg1_2__MemImm0_1020s4Offset2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_MemImm0_1020s4Offset }, },
  { 1318 /* strex */, ARM::STREX, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_MemNoOffset }, },
  { 1324 /* strexb */, ARM::t2STREXB, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_MemNoOffset }, },
  { 1324 /* strexb */, ARM::STREXB, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_MemNoOffset }, },
  { 1331 /* strexd */, ARM::STREXD, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_GPRPair, MCK_MemNoOffset }, },
  { 1331 /* strexd */, ARM::t2STREXD, Convert__Reg1_1__Reg1_2__Reg1_3__MemNoOffset1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_MemNoOffset }, },
  { 1338 /* strexh */, ARM::t2STREXH, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_MemNoOffset }, },
  { 1338 /* strexh */, ARM::STREXH, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_MemNoOffset }, },
  { 1345 /* strh */, ARM::tSTRHi, Convert__Reg1_1__MemThumbRIs22_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRIs2 }, },
  { 1345 /* strh */, ARM::tSTRHr, Convert__Reg1_1__MemThumbRR2_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_MemThumbRR }, },
  { 1345 /* strh */, ARM::t2STRHi8, Convert__Reg1_1__MemNegImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemNegImm8Offset }, },
  { 1345 /* strh */, ARM::t2STRHi12, Convert__Reg1_1__MemUImm12Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemUImm12Offset }, },
  { 1345 /* strh */, ARM::t2STRHs, Convert__Reg1_1__T2MemRegOffset3_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_T2MemRegOffset }, },
  { 1345 /* strh */, ARM::STRH, Convert__Reg1_1__AddrMode33_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_AddrMode3 }, },
  { 1345 /* strh */, ARM::t2STRHi12, Convert__Reg1_2__MemUImm12Offset2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_MemUImm12Offset }, },
  { 1345 /* strh */, ARM::t2STRHs, Convert__Reg1_2__T2MemRegOffset3_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_T2MemRegOffset }, },
  { 1345 /* strh */, ARM::t2STRH_PRE, Convert__imm_0__Reg1_1__MemImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemImm8Offset, MCK__EXCLAIM_ }, },
  { 1345 /* strh */, ARM::t2STRH_POST, Convert__MemNoOffset1_2__Reg1_1__Tie0__Imm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemNoOffset, MCK_Imm }, },
  { 1345 /* strh */, ARM::STRH_PRE, Convert__imm_0__Reg1_1__AddrMode33_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_AddrMode3, MCK__EXCLAIM_ }, },
  { 1345 /* strh */, ARM::STRH_POST, Convert__MemNoOffset1_2__Reg1_1__Tie0__AM3Offset2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_AM3Offset }, },
  { 1350 /* strht */, ARM::t2STRHT, Convert__Reg1_1__MemImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemImm8Offset }, },
  { 1350 /* strht */, ARM::STRHTi, Convert__MemNoOffset1_2__Reg1_1__Tie0__PostIdxImm81_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_PostIdxImm8 }, },
  { 1350 /* strht */, ARM::STRHTr, Convert__MemNoOffset1_2__Reg1_1__Tie0__PostIdxReg2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_PostIdxReg }, },
  { 1356 /* strt */, ARM::t2STRT, Convert__Reg1_1__MemImm8Offset2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_MemImm8Offset }, },
  { 1356 /* strt */, ARM::STRT_POST_IMM, Convert__MemNoOffset1_2__Reg1_1__Tie0__AM2OffsetImm2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_AM2OffsetImm }, },
  { 1356 /* strt */, ARM::STRT_POST_REG, Convert__MemNoOffset1_2__Reg1_1__Tie0__PostIdxRegShifted2_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_MemNoOffset, MCK_PostIdxRegShifted }, },
  { 1361 /* sub */, ARM::tSUBspi, Convert__Reg1_1__Tie0__Imm0_508s41_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_GPRsp, MCK_Imm0_508s4 }, },
  { 1361 /* sub */, ARM::t2SUBri12, Convert__Reg1_1__Reg1_1__Imm0_40951_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_Imm0_4095 }, },
  { 1361 /* sub */, ARM::tSUBi8, Convert__Reg1_2__CCOut1_0__Tie0__Imm0_2551_3__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_Imm0_255 }, },
  { 1361 /* sub */, ARM::t2SUBrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_rGPR }, },
  { 1361 /* sub */, ARM::t2SUBrs, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 1361 /* sub */, ARM::t2SUBri, Convert__Reg1_2__Reg1_2__T2SOImm1_3__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_T2SOImm }, },
  { 1361 /* sub */, ARM::SUBrr, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 1361 /* sub */, ARM::SUBri, Convert__Reg1_2__Reg1_2__ARMSOImm1_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 1361 /* sub */, ARM::SUBrsi, Convert__Reg1_2__Reg1_2__RegShiftedImm2_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 1361 /* sub */, ARM::SUBrsr, Convert__Reg1_2__Reg1_2__RegShiftedReg3_3__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_RegShiftedReg }, },
  { 1361 /* sub */, ARM::tSUBspi, Convert__regSP__Tie0__Imm0_508s41_3__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_GPRsp, MCK_GPRsp, MCK_Imm0_508s4 }, },
  { 1361 /* sub */, ARM::t2SUBri12, Convert__Reg1_1__Reg1_2__Imm0_40951_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_Imm0_4095 }, },
  { 1361 /* sub */, ARM::t2SUBrr, Convert__Reg1_3__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_rGPR }, },
  { 1361 /* sub */, ARM::tSUBrr, Convert__Reg1_2__CCOut1_0__Reg1_3__Reg1_4__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR, MCK_tGPR }, },
  { 1361 /* sub */, ARM::tSUBi3, Convert__Reg1_2__CCOut1_0__Reg1_3__Imm0_71_4__CondCode2_1, Feature_IsThumb, { MCK_CCOut, MCK_CondCode, MCK_tGPR, MCK_tGPR, MCK_Imm0_7 }, },
  { 1361 /* sub */, ARM::t2SUBrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_rGPR }, },
  { 1361 /* sub */, ARM::t2SUBrs, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 1361 /* sub */, ARM::t2SUBri, Convert__Reg1_2__Reg1_3__T2SOImm1_4__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_T2SOImm }, },
  { 1361 /* sub */, ARM::SUBrr, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1361 /* sub */, ARM::SUBri, Convert__Reg1_2__Reg1_3__ARMSOImm1_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_ARMSOImm }, },
  { 1361 /* sub */, ARM::SUBrsi, Convert__Reg1_2__Reg1_3__RegShiftedImm2_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedImm }, },
  { 1361 /* sub */, ARM::SUBrsr, Convert__Reg1_2__Reg1_3__RegShiftedReg3_4__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_RegShiftedReg }, },
  { 1361 /* sub */, ARM::t2SUBrr, Convert__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_GPRnopc, MCK_rGPR }, },
  { 1361 /* sub */, ARM::t2SUBrs, Convert__Reg1_3__Reg1_4__RegShiftedImm2_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 1361 /* sub */, ARM::t2SUBri, Convert__Reg1_3__Reg1_4__T2SOImm1_5__CondCode2_1__CCOut1_0, Feature_IsThumb2, { MCK_CCOut, MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_GPRnopc, MCK_T2SOImm }, },
  { 1365 /* subs */, ARM::t2SUBS_PC_LR, Convert__Imm0_2551_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_PC, MCK_LR, MCK_Imm0_255 }, },
  { 1370 /* subw */, ARM::t2SUBri12, Convert__Reg1_1__Reg1_2__Imm0_40951_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_Imm0_4095 }, },
  { 1375 /* svc */, ARM::tSVC, Convert__Imm0_2551_1__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_Imm0_255 }, },
  { 1375 /* svc */, ARM::SVC, Convert__Imm24bit1_1__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_Imm24bit }, },
  { 1379 /* swp */, ARM::SWP, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_MemNoOffset }, },
  { 1383 /* swpb */, ARM::SWPB, Convert__Reg1_1__Reg1_2__MemNoOffset1_3__CondCode2_0, Feature_PreV8, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_MemNoOffset }, },
  { 1388 /* sxtab */, ARM::t2SXTAB, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1388 /* sxtab */, ARM::SXTAB, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_GPRnopc }, },
  { 1388 /* sxtab */, ARM::t2SXTAB, Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_HasT2ExtractPack|Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1388 /* sxtab */, ARM::SXTAB, Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_GPRnopc, MCK_RotImm }, },
  { 1394 /* sxtab16 */, ARM::t2SXTAB16, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1394 /* sxtab16 */, ARM::SXTAB16, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_GPRnopc }, },
  { 1394 /* sxtab16 */, ARM::t2SXTAB16, Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1394 /* sxtab16 */, ARM::SXTAB16, Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_GPRnopc, MCK_RotImm }, },
  { 1402 /* sxtah */, ARM::t2SXTAH, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1402 /* sxtah */, ARM::SXTAH, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_GPRnopc }, },
  { 1402 /* sxtah */, ARM::t2SXTAH, Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_HasT2ExtractPack|Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1402 /* sxtah */, ARM::SXTAH, Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_GPRnopc, MCK_RotImm }, },
  { 1408 /* sxtb */, ARM::tSXTB, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb|Feature_HasV6, { MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 1408 /* sxtb */, ARM::t2SXTB, Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 1408 /* sxtb */, ARM::SXTB, Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1408 /* sxtb */, ARM::t2SXTB, Convert__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 1408 /* sxtb */, ARM::t2SXTB, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1408 /* sxtb */, ARM::SXTB, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_RotImm }, },
  { 1408 /* sxtb */, ARM::t2SXTB, Convert__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1413 /* sxtb16 */, ARM::t2SXTB16, Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 1413 /* sxtb16 */, ARM::SXTB16, Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1413 /* sxtb16 */, ARM::t2SXTB16, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_IsThumb2|Feature_HasT2ExtractPack, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1413 /* sxtb16 */, ARM::t2SXTB16, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1413 /* sxtb16 */, ARM::SXTB16, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_RotImm }, },
  { 1420 /* sxth */, ARM::tSXTH, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb|Feature_HasV6, { MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 1420 /* sxth */, ARM::t2SXTH, Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 1420 /* sxth */, ARM::SXTH, Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1420 /* sxth */, ARM::t2SXTH, Convert__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 1420 /* sxth */, ARM::t2SXTH, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1420 /* sxth */, ARM::SXTH, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_RotImm }, },
  { 1420 /* sxth */, ARM::t2SXTH, Convert__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1425 /* tbb */, ARM::t2TBB, Convert__MemTBB2_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_MemTBB }, },
  { 1429 /* tbh */, ARM::t2TBH, Convert__MemTBH2_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_MemTBH }, },
  { 1433 /* teq */, ARM::t2TEQrr, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_rGPR }, },
  { 1433 /* teq */, ARM::t2TEQrs, Convert__Reg1_1__RegShiftedImm2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 1433 /* teq */, ARM::TEQrsr, Convert__Reg1_1__RegShiftedReg3_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_RegShiftedReg }, },
  { 1433 /* teq */, ARM::t2TEQri, Convert__Reg1_1__T2SOImm1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_T2SOImm }, },
  { 1433 /* teq */, ARM::TEQrr, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 1433 /* teq */, ARM::TEQri, Convert__Reg1_1__ARMSOImm1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 1433 /* teq */, ARM::TEQrsi, Convert__Reg1_1__RegShiftedImm2_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 1433 /* teq */, ARM::t2TEQrr, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_rGPR }, },
  { 1433 /* teq */, ARM::t2TEQrs, Convert__Reg1_2__RegShiftedImm2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 1433 /* teq */, ARM::t2TEQri, Convert__Reg1_2__T2SOImm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_T2SOImm }, },
  { 1437 /* trap */, ARM::TRAPNaCl, Convert_NoOperands, Feature_IsARM|Feature_UseNaClTrap, {  }, },
  { 1437 /* trap */, ARM::TRAP, Convert_NoOperands, Feature_IsARM, {  }, },
  { 1437 /* trap */, ARM::tTRAP, Convert_NoOperands, Feature_IsThumb, {  }, },
  { 1442 /* tst */, ARM::tTST, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb, { MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 1442 /* tst */, ARM::t2TSTrr, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_rGPR }, },
  { 1442 /* tst */, ARM::t2TSTrs, Convert__Reg1_1__RegShiftedImm2_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 1442 /* tst */, ARM::TSTrsr, Convert__Reg1_1__RegShiftedReg3_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_RegShiftedReg }, },
  { 1442 /* tst */, ARM::t2TSTri, Convert__Reg1_1__T2SOImm1_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_GPRnopc, MCK_T2SOImm }, },
  { 1442 /* tst */, ARM::TSTrr, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_GPR }, },
  { 1442 /* tst */, ARM::TSTri, Convert__Reg1_1__ARMSOImm1_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_ARMSOImm }, },
  { 1442 /* tst */, ARM::TSTrsi, Convert__Reg1_1__RegShiftedImm2_2__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPR, MCK_RegShiftedImm }, },
  { 1442 /* tst */, ARM::t2TSTrr, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_rGPR }, },
  { 1442 /* tst */, ARM::t2TSTrs, Convert__Reg1_2__RegShiftedImm2_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_RegShiftedImm }, },
  { 1442 /* tst */, ARM::t2TSTri, Convert__Reg1_2__T2SOImm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_GPRnopc, MCK_T2SOImm }, },
  { 1446 /* uadd16 */, ARM::t2UADD16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1446 /* uadd16 */, ARM::UADD16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1453 /* uadd8 */, ARM::t2UADD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1453 /* uadd8 */, ARM::UADD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1459 /* uasx */, ARM::t2UASX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1459 /* uasx */, ARM::UASX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1464 /* ubfx */, ARM::t2UBFX, Convert__Reg1_1__Reg1_2__Imm0_311_3__Imm1_321_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_Imm0_31, MCK_Imm1_32 }, },
  { 1464 /* ubfx */, ARM::UBFX, Convert__Reg1_1__Reg1_2__Imm0_311_3__Imm1_321_4__CondCode2_0, Feature_IsARM|Feature_HasV6T2, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_Imm0_31, MCK_Imm1_32 }, },
  { 1469 /* udiv */, ARM::t2UDIV, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasDivide|Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1469 /* udiv */, ARM::UDIV, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasDivideInARM, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1474 /* uhadd16 */, ARM::t2UHADD16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1474 /* uhadd16 */, ARM::UHADD16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1482 /* uhadd8 */, ARM::t2UHADD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1482 /* uhadd8 */, ARM::UHADD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1489 /* uhasx */, ARM::t2UHASX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1489 /* uhasx */, ARM::UHASX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1495 /* uhsax */, ARM::t2UHSAX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1495 /* uhsax */, ARM::UHSAX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1501 /* uhsub16 */, ARM::t2UHSUB16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1501 /* uhsub16 */, ARM::UHSUB16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1509 /* uhsub8 */, ARM::t2UHSUB8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1509 /* uhsub8 */, ARM::UHSUB8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1516 /* umaal */, ARM::t2UMAAL, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1516 /* umaal */, ARM::UMAAL, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1522 /* umlal */, ARM::t2UMLAL, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__Tie0__Tie1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1522 /* umlal */, ARM::UMLAL, Convert__Reg1_2__Reg1_3__Reg1_4__Reg1_5__Tie0__Tie1__CondCode2_1__CCOut1_0, Feature_IsARM|Feature_HasV6, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1528 /* umull */, ARM::t2UMULL, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1528 /* umull */, ARM::UMULL, Convert__Reg1_2__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsARM|Feature_HasV6, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1528 /* umull */, ARM::UMULL, Convert__Reg1_2__Reg1_3__Reg1_4__Reg1_5__CondCode2_1__CCOut1_0, Feature_IsARM, { MCK_CCOut, MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1534 /* uqadd16 */, ARM::t2UQADD16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1534 /* uqadd16 */, ARM::UQADD16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1542 /* uqadd8 */, ARM::t2UQADD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1542 /* uqadd8 */, ARM::UQADD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1549 /* uqasx */, ARM::t2UQASX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1549 /* uqasx */, ARM::UQASX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1555 /* uqsax */, ARM::t2UQSAX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1555 /* uqsax */, ARM::UQSAX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1561 /* uqsub16 */, ARM::t2UQSUB16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1561 /* uqsub16 */, ARM::UQSUB16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1569 /* uqsub8 */, ARM::t2UQSUB8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1569 /* uqsub8 */, ARM::UQSUB8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1576 /* usad8 */, ARM::t2USAD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1576 /* usad8 */, ARM::USAD8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1582 /* usada8 */, ARM::t2USADA8, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1582 /* usada8 */, ARM::USADA8, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_GPR, MCK_GPR }, },
  { 1589 /* usat */, ARM::t2USAT, Convert__Reg1_1__Imm0_311_2__Reg1_3__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Imm0_31, MCK_rGPR }, },
  { 1589 /* usat */, ARM::USAT, Convert__Reg1_1__Imm0_311_2__Reg1_3__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_Imm0_31, MCK_GPRnopc }, },
  { 1589 /* usat */, ARM::t2USAT, Convert__Reg1_1__Imm0_311_2__Reg1_3__ShifterImm1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_Imm0_31, MCK_rGPR, MCK_ShifterImm }, },
  { 1589 /* usat */, ARM::USAT, Convert__Reg1_1__Imm0_311_2__Reg1_3__ShifterImm1_4__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_Imm0_31, MCK_GPRnopc, MCK_ShifterImm }, },
  { 1594 /* usat16 */, ARM::t2USAT16, Convert__Reg1_1__Imm0_151_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_Imm0_15, MCK_rGPR }, },
  { 1594 /* usat16 */, ARM::USAT16, Convert__Reg1_1__Imm0_151_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_Imm0_15, MCK_GPRnopc }, },
  { 1601 /* usax */, ARM::t2USAX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1601 /* usax */, ARM::USAX, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1606 /* usub16 */, ARM::t2USUB16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1606 /* usub16 */, ARM::USUB16, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1613 /* usub8 */, ARM::t2USUB8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsThumb2|Feature_HasThumb2DSP, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1613 /* usub8 */, ARM::USUB8, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1619 /* uxtab */, ARM::t2UXTAB, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1619 /* uxtab */, ARM::UXTAB, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_GPRnopc }, },
  { 1619 /* uxtab */, ARM::t2UXTAB, Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_HasT2ExtractPack|Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1619 /* uxtab */, ARM::UXTAB, Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_GPRnopc, MCK_RotImm }, },
  { 1625 /* uxtab16 */, ARM::t2UXTAB16, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1625 /* uxtab16 */, ARM::UXTAB16, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_GPRnopc }, },
  { 1625 /* uxtab16 */, ARM::t2UXTAB16, Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1625 /* uxtab16 */, ARM::UXTAB16, Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_GPRnopc, MCK_RotImm }, },
  { 1633 /* uxtah */, ARM::t2UXTAH, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR }, },
  { 1633 /* uxtah */, ARM::UXTAH, Convert__Reg1_1__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_GPRnopc }, },
  { 1633 /* uxtah */, ARM::t2UXTAH, Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_HasT2ExtractPack|Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1633 /* uxtah */, ARM::UXTAH, Convert__Reg1_1__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPR, MCK_GPRnopc, MCK_RotImm }, },
  { 1639 /* uxtb */, ARM::tUXTB, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb|Feature_HasV6, { MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 1639 /* uxtb */, ARM::t2UXTB, Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 1639 /* uxtb */, ARM::UXTB, Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1639 /* uxtb */, ARM::t2UXTB, Convert__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 1639 /* uxtb */, ARM::t2UXTB, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1639 /* uxtb */, ARM::UXTB, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_RotImm }, },
  { 1639 /* uxtb */, ARM::t2UXTB, Convert__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1644 /* uxtb16 */, ARM::t2UXTB16, Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 1644 /* uxtb16 */, ARM::UXTB16, Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1644 /* uxtb16 */, ARM::t2UXTB16, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_HasT2ExtractPack|Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1644 /* uxtb16 */, ARM::t2UXTB16, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1644 /* uxtb16 */, ARM::UXTB16, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_RotImm }, },
  { 1651 /* uxth */, ARM::tUXTH, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_IsThumb|Feature_HasV6, { MCK_CondCode, MCK_tGPR, MCK_tGPR }, },
  { 1651 /* uxth */, ARM::t2UXTH, Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR }, },
  { 1651 /* uxth */, ARM::UXTH, Convert__Reg1_1__Reg1_2__imm_0__CondCode2_0, Feature_IsARM, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc }, },
  { 1651 /* uxth */, ARM::t2UXTH, Convert__Reg1_2__Reg1_3__imm_0__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR }, },
  { 1651 /* uxth */, ARM::t2UXTH, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1651 /* uxth */, ARM::UXTH, Convert__Reg1_1__Reg1_2__RotImm1_3__CondCode2_0, Feature_IsARM|Feature_HasV6, { MCK_CondCode, MCK_GPRnopc, MCK_GPRnopc, MCK_RotImm }, },
  { 1651 /* uxth */, ARM::t2UXTH, Convert__Reg1_2__Reg1_3__RotImm1_4__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w, MCK_rGPR, MCK_rGPR, MCK_RotImm }, },
  { 1656 /* vaba */, ARM::VABAsv4i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1656 /* vaba */, ARM::VABAsv8i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1656 /* vaba */, ARM::VABAsv2i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1656 /* vaba */, ARM::VABAsv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1656 /* vaba */, ARM::VABAsv8i8, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1656 /* vaba */, ARM::VABAsv16i8, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1656 /* vaba */, ARM::VABAuv4i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1656 /* vaba */, ARM::VABAuv8i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1656 /* vaba */, ARM::VABAuv2i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1656 /* vaba */, ARM::VABAuv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1656 /* vaba */, ARM::VABAuv8i8, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1656 /* vaba */, ARM::VABAuv16i8, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1661 /* vabal */, ARM::VABALsv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1661 /* vabal */, ARM::VABALsv2i64, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1661 /* vabal */, ARM::VABALsv8i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1661 /* vabal */, ARM::VABALuv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1661 /* vabal */, ARM::VABALuv2i64, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1661 /* vabal */, ARM::VABALuv8i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDfd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDfq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1667 /* vabd */, ARM::VABDsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 1667 /* vabd */, ARM::VABDsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 1667 /* vabd */, ARM::VABDsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 1667 /* vabd */, ARM::VABDuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 1667 /* vabd */, ARM::VABDuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 1667 /* vabd */, ARM::VABDuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 1667 /* vabd */, ARM::VABDfd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDfq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1667 /* vabd */, ARM::VABDsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1667 /* vabd */, ARM::VABDsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1667 /* vabd */, ARM::VABDsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1667 /* vabd */, ARM::VABDuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1667 /* vabd */, ARM::VABDuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1667 /* vabd */, ARM::VABDuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1667 /* vabd */, ARM::VABDuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1672 /* vabdl */, ARM::VABDLsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1672 /* vabdl */, ARM::VABDLsv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1672 /* vabdl */, ARM::VABDLsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1672 /* vabdl */, ARM::VABDLuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1672 /* vabdl */, ARM::VABDLuv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1672 /* vabdl */, ARM::VABDLuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1678 /* vabs */, ARM::VABSS, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1678 /* vabs */, ARM::VABSfd, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1678 /* vabs */, ARM::VABSfq, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1678 /* vabs */, ARM::VABSD, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 1678 /* vabs */, ARM::VABSv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 1678 /* vabs */, ARM::VABSv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 1678 /* vabs */, ARM::VABSv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 1678 /* vabs */, ARM::VABSv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 1678 /* vabs */, ARM::VABSv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 1678 /* vabs */, ARM::VABSv16i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 1683 /* vacge */, ARM::VACGEd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1683 /* vacge */, ARM::VACGEq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1683 /* vacge */, ARM::VACGEd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1683 /* vacge */, ARM::VACGEq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1689 /* vacgt */, ARM::VACGTd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1689 /* vacgt */, ARM::VACGTq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1689 /* vacgt */, ARM::VACGTd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1689 /* vacgt */, ARM::VACGTq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1695 /* vacle */, ARM::VACGEd, Convert__Reg1_2__Reg1_3__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1695 /* vacle */, ARM::VACGEq, Convert__Reg1_2__Reg1_3__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1695 /* vacle */, ARM::VACGEd, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1695 /* vacle */, ARM::VACGEq, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1701 /* vaclt */, ARM::VACGTd, Convert__Reg1_2__Reg1_3__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1701 /* vaclt */, ARM::VACGTq, Convert__Reg1_2__Reg1_3__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1701 /* vaclt */, ARM::VACGTd, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1701 /* vaclt */, ARM::VACGTq, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1707 /* vadd */, ARM::VADDS, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1707 /* vadd */, ARM::VADDfd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1707 /* vadd */, ARM::VADDfq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1707 /* vadd */, ARM::VADDD, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 1707 /* vadd */, ARM::VADDv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR }, },
  { 1707 /* vadd */, ARM::VADDv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR }, },
  { 1707 /* vadd */, ARM::VADDv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR }, },
  { 1707 /* vadd */, ARM::VADDv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR }, },
  { 1707 /* vadd */, ARM::VADDv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_DPR }, },
  { 1707 /* vadd */, ARM::VADDv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_QPR, MCK_QPR }, },
  { 1707 /* vadd */, ARM::VADDv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR }, },
  { 1707 /* vadd */, ARM::VADDv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_QPR }, },
  { 1707 /* vadd */, ARM::VADDS, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 1707 /* vadd */, ARM::VADDfd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1707 /* vadd */, ARM::VADDfq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1707 /* vadd */, ARM::VADDD, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1707 /* vadd */, ARM::VADDv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1707 /* vadd */, ARM::VADDv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1707 /* vadd */, ARM::VADDv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1707 /* vadd */, ARM::VADDv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1707 /* vadd */, ARM::VADDv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1707 /* vadd */, ARM::VADDv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1707 /* vadd */, ARM::VADDv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1707 /* vadd */, ARM::VADDv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1712 /* vaddhn */, ARM::VADDHNv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_QPR, MCK_QPR }, },
  { 1712 /* vaddhn */, ARM::VADDHNv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_QPR, MCK_QPR }, },
  { 1712 /* vaddhn */, ARM::VADDHNv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_QPR, MCK_QPR }, },
  { 1719 /* vaddl */, ARM::VADDLsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1719 /* vaddl */, ARM::VADDLsv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1719 /* vaddl */, ARM::VADDLsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1719 /* vaddl */, ARM::VADDLuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1719 /* vaddl */, ARM::VADDLuv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1719 /* vaddl */, ARM::VADDLuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1725 /* vaddw */, ARM::VADDWsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR }, },
  { 1725 /* vaddw */, ARM::VADDWsv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR }, },
  { 1725 /* vaddw */, ARM::VADDWsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_DPR }, },
  { 1725 /* vaddw */, ARM::VADDWuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR }, },
  { 1725 /* vaddw */, ARM::VADDWuv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR }, },
  { 1725 /* vaddw */, ARM::VADDWuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_DPR }, },
  { 1725 /* vaddw */, ARM::VADDWsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_DPR }, },
  { 1725 /* vaddw */, ARM::VADDWsv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_DPR }, },
  { 1725 /* vaddw */, ARM::VADDWsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_DPR }, },
  { 1725 /* vaddw */, ARM::VADDWuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_DPR }, },
  { 1725 /* vaddw */, ARM::VADDWuv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_DPR }, },
  { 1725 /* vaddw */, ARM::VADDWuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_DPR }, },
  { 1731 /* vand */, ARM::VANDd, Convert__Reg1_1__Reg1_1__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR }, },
  { 1731 /* vand */, ARM::VANDq, Convert__Reg1_1__Reg1_1__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR }, },
  { 1731 /* vand */, ARM::VANDd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR }, },
  { 1731 /* vand */, ARM::VANDq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR }, },
  { 1731 /* vand */, ARM::VANDd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR }, },
  { 1731 /* vand */, ARM::VANDq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 1731 /* vand */, ARM::VANDd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR }, },
  { 1731 /* vand */, ARM::VANDq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR }, },
  { 1731 /* vand */, ARM::VANDd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 1731 /* vand */, ARM::VANDq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 1731 /* vand */, ARM::VANDd, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1731 /* vand */, ARM::VANDq, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1731 /* vand */, ARM::VANDd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1731 /* vand */, ARM::VANDq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1731 /* vand */, ARM::VANDd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1731 /* vand */, ARM::VANDq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1731 /* vand */, ARM::VANDd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1731 /* vand */, ARM::VANDq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1731 /* vand */, ARM::VANDd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1731 /* vand */, ARM::VANDq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1736 /* vbic */, ARM::VBICd, Convert__Reg1_1__Reg1_1__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR }, },
  { 1736 /* vbic */, ARM::VBICq, Convert__Reg1_1__Reg1_1__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR }, },
  { 1736 /* vbic */, ARM::VBICiv4i16, Convert__Reg1_2__NEONi16splat1_3__Tie0__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_NEONi16splat }, },
  { 1736 /* vbic */, ARM::VBICiv8i16, Convert__Reg1_2__NEONi16splat1_3__Tie0__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_NEONi16splat }, },
  { 1736 /* vbic */, ARM::VBICiv2i32, Convert__Reg1_2__NEONi32splat1_3__Tie0__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_NEONi32splat }, },
  { 1736 /* vbic */, ARM::VBICiv4i32, Convert__Reg1_2__NEONi32splat1_3__Tie0__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_NEONi32splat }, },
  { 1736 /* vbic */, ARM::VBICd, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1736 /* vbic */, ARM::VBICq, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1736 /* vbic */, ARM::VBICd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1736 /* vbic */, ARM::VBICq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1736 /* vbic */, ARM::VBICd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1736 /* vbic */, ARM::VBICq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1736 /* vbic */, ARM::VBICd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1736 /* vbic */, ARM::VBICq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1736 /* vbic */, ARM::VBICd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1736 /* vbic */, ARM::VBICq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1741 /* vbif */, ARM::VBIFd, Convert__Reg1_1__Tie0__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1741 /* vbif */, ARM::VBIFq, Convert__Reg1_1__Tie0__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1741 /* vbif */, ARM::VBIFd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1741 /* vbif */, ARM::VBIFq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1741 /* vbif */, ARM::VBIFd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1741 /* vbif */, ARM::VBIFq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1741 /* vbif */, ARM::VBIFd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1741 /* vbif */, ARM::VBIFq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1741 /* vbif */, ARM::VBIFd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1741 /* vbif */, ARM::VBIFq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1746 /* vbit */, ARM::VBITd, Convert__Reg1_1__Tie0__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1746 /* vbit */, ARM::VBITq, Convert__Reg1_1__Tie0__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1746 /* vbit */, ARM::VBITd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1746 /* vbit */, ARM::VBITq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1746 /* vbit */, ARM::VBITd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1746 /* vbit */, ARM::VBITq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1746 /* vbit */, ARM::VBITd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1746 /* vbit */, ARM::VBITq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1746 /* vbit */, ARM::VBITd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1746 /* vbit */, ARM::VBITq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1751 /* vbsl */, ARM::VBSLd, Convert__Reg1_1__Tie0__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1751 /* vbsl */, ARM::VBSLq, Convert__Reg1_1__Tie0__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1751 /* vbsl */, ARM::VBSLd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1751 /* vbsl */, ARM::VBSLq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1751 /* vbsl */, ARM::VBSLd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1751 /* vbsl */, ARM::VBSLq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1751 /* vbsl */, ARM::VBSLd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1751 /* vbsl */, ARM::VBSLq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1751 /* vbsl */, ARM::VBSLd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1751 /* vbsl */, ARM::VBSLq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1756 /* vceq */, ARM::VCEQzv2f32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQfd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1756 /* vceq */, ARM::VCEQzv4f32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQfq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1756 /* vceq */, ARM::VCEQzv4i16, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR }, },
  { 1756 /* vceq */, ARM::VCEQzv8i16, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR }, },
  { 1756 /* vceq */, ARM::VCEQzv2i32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR }, },
  { 1756 /* vceq */, ARM::VCEQzv4i32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR }, },
  { 1756 /* vceq */, ARM::VCEQzv8i8, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR }, },
  { 1756 /* vceq */, ARM::VCEQzv16i8, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_QPR }, },
  { 1756 /* vceq */, ARM::VCEQzv2f32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQfd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1756 /* vceq */, ARM::VCEQzv4f32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQfq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1756 /* vceq */, ARM::VCEQzv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1756 /* vceq */, ARM::VCEQzv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1756 /* vceq */, ARM::VCEQzv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1756 /* vceq */, ARM::VCEQzv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1756 /* vceq */, ARM::VCEQzv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1756 /* vceq */, ARM::VCEQzv16i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1756 /* vceq */, ARM::VCEQv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEzv2f32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEfd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEzv4f32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEfq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEzv4i16, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEzv8i16, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEzv2i32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEzv4i32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEzv8i8, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEzv16i8, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEzv2f32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEfd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEzv4f32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEfq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEzv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEzv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEzv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEzv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEzv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEzv16i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1761 /* vcge */, ARM::VCGEsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1761 /* vcge */, ARM::VCGEuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1761 /* vcge */, ARM::VCGEuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv2f32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTfd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv4f32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTfq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv4i16, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv8i16, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv2i32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv4i32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv8i8, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv16i8, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv2f32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTfd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv4f32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTfq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTzv16i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1766 /* vcgt */, ARM::VCGTsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1766 /* vcgt */, ARM::VCGTuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1766 /* vcgt */, ARM::VCGTuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1771 /* vcle */, ARM::VCLEzv2f32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCLEzv4f32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCLEzv4i16, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCLEzv8i16, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCLEzv2i32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCLEzv4i32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCLEzv8i8, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCLEzv16i8, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCLEzv2f32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCGEfd, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1771 /* vcle */, ARM::VCLEzv4f32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCGEfq, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1771 /* vcle */, ARM::VCLEzv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCGEsv4i16, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1771 /* vcle */, ARM::VCLEzv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCGEsv8i16, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1771 /* vcle */, ARM::VCLEzv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCGEsv2i32, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1771 /* vcle */, ARM::VCLEzv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCGEsv4i32, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1771 /* vcle */, ARM::VCLEzv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCGEsv8i8, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1771 /* vcle */, ARM::VCLEzv16i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1771 /* vcle */, ARM::VCGEsv16i8, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1771 /* vcle */, ARM::VCGEuv4i16, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1771 /* vcle */, ARM::VCGEuv8i16, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1771 /* vcle */, ARM::VCGEuv2i32, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1771 /* vcle */, ARM::VCGEuv4i32, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1771 /* vcle */, ARM::VCGEuv8i8, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1771 /* vcle */, ARM::VCGEuv16i8, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1776 /* vcls */, ARM::VCLSv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 1776 /* vcls */, ARM::VCLSv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 1776 /* vcls */, ARM::VCLSv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 1776 /* vcls */, ARM::VCLSv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 1776 /* vcls */, ARM::VCLSv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 1776 /* vcls */, ARM::VCLSv16i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 1781 /* vclt */, ARM::VCLTzv2f32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCLTzv4f32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCLTzv4i16, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCLTzv8i16, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCLTzv2i32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCLTzv4i32, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCLTzv8i8, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCLTzv16i8, Convert__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCLTzv2f32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCGTfd, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1781 /* vclt */, ARM::VCLTzv4f32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCGTfq, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1781 /* vclt */, ARM::VCLTzv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCGTsv4i16, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1781 /* vclt */, ARM::VCLTzv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCGTsv8i16, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1781 /* vclt */, ARM::VCLTzv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCGTsv2i32, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1781 /* vclt */, ARM::VCLTzv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCGTsv4i32, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1781 /* vclt */, ARM::VCLTzv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCGTsv8i8, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1781 /* vclt */, ARM::VCLTzv16i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1781 /* vclt */, ARM::VCGTsv16i8, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1781 /* vclt */, ARM::VCGTuv4i16, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1781 /* vclt */, ARM::VCGTuv8i16, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1781 /* vclt */, ARM::VCGTuv2i32, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1781 /* vclt */, ARM::VCGTuv4i32, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1781 /* vclt */, ARM::VCGTuv8i8, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1781 /* vclt */, ARM::VCGTuv16i8, Convert__Reg1_2__Reg1_4__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1786 /* vclz */, ARM::VCLZv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR }, },
  { 1786 /* vclz */, ARM::VCLZv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR }, },
  { 1786 /* vclz */, ARM::VCLZv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR }, },
  { 1786 /* vclz */, ARM::VCLZv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR }, },
  { 1786 /* vclz */, ARM::VCLZv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR }, },
  { 1786 /* vclz */, ARM::VCLZv16i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_QPR }, },
  { 1791 /* vcmp */, ARM::VCMPZS, Convert__Reg1_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK__35_0 }, },
  { 1791 /* vcmp */, ARM::VCMPS, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1791 /* vcmp */, ARM::VCMPZD, Convert__Reg1_2__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK__35_0 }, },
  { 1791 /* vcmp */, ARM::VCMPD, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 1796 /* vcmpe */, ARM::VCMPEZS, Convert__Reg1_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK__35_0 }, },
  { 1796 /* vcmpe */, ARM::VCMPES, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1796 /* vcmpe */, ARM::VCMPEZD, Convert__Reg1_2__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK__35_0 }, },
  { 1796 /* vcmpe */, ARM::VCMPED, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 1802 /* vcnt */, ARM::VCNTd, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 1802 /* vcnt */, ARM::VCNTq, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 1807 /* vcvt */, ARM::VCVTf2h, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON|Feature_HasFP16, { MCK_CondCode, MCK__DOT_f16, MCK__DOT_f32, MCK_DPR, MCK_QPR }, },
  { 1807 /* vcvt */, ARM::VCVTh2f, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON|Feature_HasFP16, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_f16, MCK_QPR, MCK_DPR }, },
  { 1807 /* vcvt */, ARM::VCVTSD, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1807 /* vcvt */, ARM::VSITOS, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_s32, MCK_SPR, MCK_SPR }, },
  { 1807 /* vcvt */, ARM::VCVTs2fd, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 1807 /* vcvt */, ARM::VCVTs2fq, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 1807 /* vcvt */, ARM::VUITOS, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_u32, MCK_SPR, MCK_SPR }, },
  { 1807 /* vcvt */, ARM::VCVTu2fd, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 1807 /* vcvt */, ARM::VCVTu2fq, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 1807 /* vcvt */, ARM::VCVTDS, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f64, MCK__DOT_f32, MCK_DPR, MCK_SPR }, },
  { 1807 /* vcvt */, ARM::VSITOD, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK__DOT_s32, MCK_DPR, MCK_SPR }, },
  { 1807 /* vcvt */, ARM::VUITOD, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK__DOT_u32, MCK_DPR, MCK_SPR }, },
  { 1807 /* vcvt */, ARM::VTOSIZS, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_s32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1807 /* vcvt */, ARM::VCVTf2sd, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1807 /* vcvt */, ARM::VCVTf2sq, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1807 /* vcvt */, ARM::VTOSIZD, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_s32, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1807 /* vcvt */, ARM::VTOUIZS, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_u32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1807 /* vcvt */, ARM::VCVTf2ud, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1807 /* vcvt */, ARM::VCVTf2uq, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1807 /* vcvt */, ARM::VTOUIZD, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_u32, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1807 /* vcvt */, ARM::VSHTOS, Convert__Reg1_3__Tie0__FBits161_5__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_s16, MCK_SPR, MCK_SPR, MCK_FBits16 }, },
  { 1807 /* vcvt */, ARM::VSLTOS, Convert__Reg1_3__Tie0__FBits321_5__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_s32, MCK_SPR, MCK_SPR, MCK_FBits32 }, },
  { 1807 /* vcvt */, ARM::VCVTs2fd, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1807 /* vcvt */, ARM::VCVTxs2fd, Convert__Reg1_3__Reg1_4__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 1807 /* vcvt */, ARM::VCVTs2fq, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1807 /* vcvt */, ARM::VCVTxs2fq, Convert__Reg1_3__Reg1_4__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 1807 /* vcvt */, ARM::VUHTOS, Convert__Reg1_3__Tie0__FBits161_5__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_u16, MCK_SPR, MCK_SPR, MCK_FBits16 }, },
  { 1807 /* vcvt */, ARM::VULTOS, Convert__Reg1_3__Tie0__FBits321_5__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_u32, MCK_SPR, MCK_SPR, MCK_FBits32 }, },
  { 1807 /* vcvt */, ARM::VCVTu2fd, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1807 /* vcvt */, ARM::VCVTxu2fd, Convert__Reg1_3__Reg1_4__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 1807 /* vcvt */, ARM::VCVTu2fq, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1807 /* vcvt */, ARM::VCVTxu2fq, Convert__Reg1_3__Reg1_4__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 1807 /* vcvt */, ARM::VSHTOD, Convert__Reg1_3__Tie0__FBits161_5__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_FBits16 }, },
  { 1807 /* vcvt */, ARM::VSLTOD, Convert__Reg1_3__Tie0__FBits321_5__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_FBits32 }, },
  { 1807 /* vcvt */, ARM::VUHTOD, Convert__Reg1_3__Tie0__FBits161_5__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_FBits16 }, },
  { 1807 /* vcvt */, ARM::VULTOD, Convert__Reg1_3__Tie0__FBits321_5__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_FBits32 }, },
  { 1807 /* vcvt */, ARM::VTOSHS, Convert__Reg1_3__Tie0__FBits161_5__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_s16, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_FBits16 }, },
  { 1807 /* vcvt */, ARM::VTOSHD, Convert__Reg1_3__Tie0__FBits161_5__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_s16, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_FBits16 }, },
  { 1807 /* vcvt */, ARM::VTOSLS, Convert__Reg1_3__Tie0__FBits321_5__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_s32, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_FBits32 }, },
  { 1807 /* vcvt */, ARM::VCVTf2sd, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1807 /* vcvt */, ARM::VCVTf2xsd, Convert__Reg1_3__Reg1_4__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 1807 /* vcvt */, ARM::VCVTf2sq, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1807 /* vcvt */, ARM::VCVTf2xsq, Convert__Reg1_3__Reg1_4__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 1807 /* vcvt */, ARM::VTOSLD, Convert__Reg1_3__Tie0__FBits321_5__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_s32, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_FBits32 }, },
  { 1807 /* vcvt */, ARM::VTOUHS, Convert__Reg1_3__Tie0__FBits161_5__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_u16, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_FBits16 }, },
  { 1807 /* vcvt */, ARM::VTOUHD, Convert__Reg1_3__Tie0__FBits161_5__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_u16, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_FBits16 }, },
  { 1807 /* vcvt */, ARM::VTOULS, Convert__Reg1_3__Tie0__FBits321_5__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_u32, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_FBits32 }, },
  { 1807 /* vcvt */, ARM::VCVTf2ud, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK__35_0 }, },
  { 1807 /* vcvt */, ARM::VCVTf2xud, Convert__Reg1_3__Reg1_4__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 1807 /* vcvt */, ARM::VCVTf2uq, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK__35_0 }, },
  { 1807 /* vcvt */, ARM::VCVTf2xuq, Convert__Reg1_3__Reg1_4__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 1807 /* vcvt */, ARM::VTOULD, Convert__Reg1_3__Tie0__FBits321_5__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_u32, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_FBits32 }, },
  { 1812 /* vcvta */, ARM::VCVTASS, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_s32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1812 /* vcvta */, ARM::VCVTANSD, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_s32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1812 /* vcvta */, ARM::VCVTANSQ, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_s32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1812 /* vcvta */, ARM::VCVTASD, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_s32, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1812 /* vcvta */, ARM::VCVTAUS, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_u32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1812 /* vcvta */, ARM::VCVTANUD, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_u32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1812 /* vcvta */, ARM::VCVTANUQ, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_u32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1812 /* vcvta */, ARM::VCVTAUD, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_u32, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1818 /* vcvtb */, ARM::VCVTBSH, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f16, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1818 /* vcvtb */, ARM::VCVTBDH, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f16, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1818 /* vcvtb */, ARM::VCVTBHS, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_f16, MCK_SPR, MCK_SPR }, },
  { 1818 /* vcvtb */, ARM::VCVTBHD, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK__DOT_f16, MCK_DPR, MCK_SPR }, },
  { 1824 /* vcvtm */, ARM::VCVTMSS, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_s32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1824 /* vcvtm */, ARM::VCVTMNSD, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_s32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1824 /* vcvtm */, ARM::VCVTMNSQ, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_s32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1824 /* vcvtm */, ARM::VCVTMSD, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_s32, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1824 /* vcvtm */, ARM::VCVTMUS, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_u32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1824 /* vcvtm */, ARM::VCVTMNUD, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_u32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1824 /* vcvtm */, ARM::VCVTMNUQ, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_u32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1824 /* vcvtm */, ARM::VCVTMUD, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_u32, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1830 /* vcvtn */, ARM::VCVTNSS, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_s32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1830 /* vcvtn */, ARM::VCVTNNSD, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_s32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1830 /* vcvtn */, ARM::VCVTNNSQ, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_s32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1830 /* vcvtn */, ARM::VCVTNSD, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_s32, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1830 /* vcvtn */, ARM::VCVTNUS, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_u32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1830 /* vcvtn */, ARM::VCVTNNUD, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_u32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1830 /* vcvtn */, ARM::VCVTNNUQ, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_u32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1830 /* vcvtn */, ARM::VCVTNUD, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_u32, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1836 /* vcvtp */, ARM::VCVTPSS, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_s32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1836 /* vcvtp */, ARM::VCVTPNSD, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_s32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1836 /* vcvtp */, ARM::VCVTPNSQ, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_s32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1836 /* vcvtp */, ARM::VCVTPSD, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_s32, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1836 /* vcvtp */, ARM::VCVTPUS, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_u32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1836 /* vcvtp */, ARM::VCVTPNUD, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_u32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1836 /* vcvtp */, ARM::VCVTPNUQ, Convert__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_u32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1836 /* vcvtp */, ARM::VCVTPUD, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_u32, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1842 /* vcvtr */, ARM::VTOSIRS, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_s32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1842 /* vcvtr */, ARM::VTOSIRD, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_s32, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1842 /* vcvtr */, ARM::VTOUIRS, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_u32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1842 /* vcvtr */, ARM::VTOUIRD, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_u32, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1848 /* vcvtt */, ARM::VCVTTSH, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f16, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1848 /* vcvtt */, ARM::VCVTTDH, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f16, MCK__DOT_f64, MCK_SPR, MCK_DPR }, },
  { 1848 /* vcvtt */, ARM::VCVTTHS, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_f16, MCK_SPR, MCK_SPR }, },
  { 1848 /* vcvtt */, ARM::VCVTTHD, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK__DOT_f16, MCK_DPR, MCK_SPR }, },
  { 1854 /* vdiv */, ARM::VDIVS, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1854 /* vdiv */, ARM::VDIVD, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 1854 /* vdiv */, ARM::VDIVS, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 1854 /* vdiv */, ARM::VDIVD, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1859 /* vdup */, ARM::VDUP16d, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_GPR }, },
  { 1859 /* vdup */, ARM::VDUP16q, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_GPR }, },
  { 1859 /* vdup */, ARM::VDUP32d, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_GPR }, },
  { 1859 /* vdup */, ARM::VDUP32q, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_GPR }, },
  { 1859 /* vdup */, ARM::VDUP8d, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_GPR }, },
  { 1859 /* vdup */, ARM::VDUP8q, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_GPR }, },
  { 1859 /* vdup */, ARM::VDUPLN16d, Convert__Reg1_2__Reg1_3__VectorIndex161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR, MCK_VectorIndex16 }, },
  { 1859 /* vdup */, ARM::VDUPLN16q, Convert__Reg1_2__Reg1_3__VectorIndex161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_DPR, MCK_VectorIndex16 }, },
  { 1859 /* vdup */, ARM::VDUPLN32d, Convert__Reg1_2__Reg1_3__VectorIndex321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR, MCK_VectorIndex32 }, },
  { 1859 /* vdup */, ARM::VDUPLN32q, Convert__Reg1_2__Reg1_3__VectorIndex321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_DPR, MCK_VectorIndex32 }, },
  { 1859 /* vdup */, ARM::VDUPLN8d, Convert__Reg1_2__Reg1_3__VectorIndex81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR, MCK_VectorIndex8 }, },
  { 1859 /* vdup */, ARM::VDUPLN8q, Convert__Reg1_2__Reg1_3__VectorIndex81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_DPR, MCK_VectorIndex8 }, },
  { 1864 /* veor */, ARM::VEORd, Convert__Reg1_1__Reg1_1__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR }, },
  { 1864 /* veor */, ARM::VEORq, Convert__Reg1_1__Reg1_1__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR }, },
  { 1864 /* veor */, ARM::VEORd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR }, },
  { 1864 /* veor */, ARM::VEORq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR }, },
  { 1864 /* veor */, ARM::VEORd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR }, },
  { 1864 /* veor */, ARM::VEORq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 1864 /* veor */, ARM::VEORd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR }, },
  { 1864 /* veor */, ARM::VEORq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR }, },
  { 1864 /* veor */, ARM::VEORd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 1864 /* veor */, ARM::VEORq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 1864 /* veor */, ARM::VEORd, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1864 /* veor */, ARM::VEORq, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1864 /* veor */, ARM::VEORd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1864 /* veor */, ARM::VEORq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1864 /* veor */, ARM::VEORd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1864 /* veor */, ARM::VEORq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1864 /* veor */, ARM::VEORd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1864 /* veor */, ARM::VEORq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1864 /* veor */, ARM::VEORd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1864 /* veor */, ARM::VEORq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1869 /* vext */, ARM::VEXTd16, Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_31_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR, MCK_Imm0_3 }, },
  { 1869 /* vext */, ARM::VEXTq16, Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_151_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR, MCK_Imm0_15 }, },
  { 1869 /* vext */, ARM::VEXTd32, Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_11_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR, MCK_Imm0_1 }, },
  { 1869 /* vext */, ARM::VEXTq32, Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_151_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_Imm0_15 }, },
  { 1869 /* vext */, ARM::VEXTq64, Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_151_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR, MCK_Imm0_15 }, },
  { 1869 /* vext */, ARM::VEXTd8, Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_71_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR, MCK_Imm0_7 }, },
  { 1869 /* vext */, ARM::VEXTq8, Convert__Reg1_2__Reg1_2__Reg1_3__Imm0_151_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR, MCK_Imm0_15 }, },
  { 1869 /* vext */, ARM::VEXTd16, Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_31_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR, MCK_DPR, MCK_Imm0_3 }, },
  { 1869 /* vext */, ARM::VEXTq16, Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_151_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR, MCK_QPR, MCK_Imm0_15 }, },
  { 1869 /* vext */, ARM::VEXTd32, Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_11_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR, MCK_DPR, MCK_Imm0_1 }, },
  { 1869 /* vext */, ARM::VEXTq32, Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_151_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR, MCK_Imm0_15 }, },
  { 1869 /* vext */, ARM::VEXTq64, Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_151_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR, MCK_QPR, MCK_Imm0_15 }, },
  { 1869 /* vext */, ARM::VEXTd8, Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_71_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR, MCK_DPR, MCK_Imm0_7 }, },
  { 1869 /* vext */, ARM::VEXTq8, Convert__Reg1_2__Reg1_3__Reg1_4__Imm0_151_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR, MCK_QPR, MCK_Imm0_15 }, },
  { 1874 /* vfma */, ARM::VFMAS, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP4, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 1874 /* vfma */, ARM::VFMAfd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON|Feature_HasVFP4, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1874 /* vfma */, ARM::VFMAfq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON|Feature_HasVFP4, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1874 /* vfma */, ARM::VFMAD, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP4|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1879 /* vfms */, ARM::VFMSS, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP4, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 1879 /* vfms */, ARM::VFMSfd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON|Feature_HasVFP4, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1879 /* vfms */, ARM::VFMSfq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON|Feature_HasVFP4, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1879 /* vfms */, ARM::VFMSD, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP4|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1884 /* vfnma */, ARM::VFNMAS, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP4, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 1884 /* vfnma */, ARM::VFNMAD, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP4|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1890 /* vfnms */, ARM::VFNMSS, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP4, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 1890 /* vfnms */, ARM::VFNMSD, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP4|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1896 /* vhadd */, ARM::VHADDsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 1896 /* vhadd */, ARM::VHADDsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 1896 /* vhadd */, ARM::VHADDsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 1896 /* vhadd */, ARM::VHADDsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 1896 /* vhadd */, ARM::VHADDsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 1896 /* vhadd */, ARM::VHADDsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 1896 /* vhadd */, ARM::VHADDuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 1896 /* vhadd */, ARM::VHADDuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 1896 /* vhadd */, ARM::VHADDuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 1896 /* vhadd */, ARM::VHADDuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 1896 /* vhadd */, ARM::VHADDuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 1896 /* vhadd */, ARM::VHADDuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 1896 /* vhadd */, ARM::VHADDsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1896 /* vhadd */, ARM::VHADDsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1896 /* vhadd */, ARM::VHADDsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1896 /* vhadd */, ARM::VHADDsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1896 /* vhadd */, ARM::VHADDsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1896 /* vhadd */, ARM::VHADDsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1896 /* vhadd */, ARM::VHADDuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1896 /* vhadd */, ARM::VHADDuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1896 /* vhadd */, ARM::VHADDuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1896 /* vhadd */, ARM::VHADDuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1896 /* vhadd */, ARM::VHADDuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1896 /* vhadd */, ARM::VHADDuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1902 /* vhsub */, ARM::VHSUBsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 1902 /* vhsub */, ARM::VHSUBsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 1902 /* vhsub */, ARM::VHSUBsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 1902 /* vhsub */, ARM::VHSUBsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 1902 /* vhsub */, ARM::VHSUBsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 1902 /* vhsub */, ARM::VHSUBsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 1902 /* vhsub */, ARM::VHSUBuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 1902 /* vhsub */, ARM::VHSUBuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 1902 /* vhsub */, ARM::VHSUBuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 1902 /* vhsub */, ARM::VHSUBuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 1902 /* vhsub */, ARM::VHSUBuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 1902 /* vhsub */, ARM::VHSUBuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 1902 /* vhsub */, ARM::VHSUBsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1902 /* vhsub */, ARM::VHSUBsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1902 /* vhsub */, ARM::VHSUBsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1902 /* vhsub */, ARM::VHSUBsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1902 /* vhsub */, ARM::VHSUBsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1902 /* vhsub */, ARM::VHSUBsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1902 /* vhsub */, ARM::VHSUBuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1902 /* vhsub */, ARM::VHSUBuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1902 /* vhsub */, ARM::VHSUBuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1902 /* vhsub */, ARM::VHSUBuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1902 /* vhsub */, ARM::VHSUBuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1902 /* vhsub */, ARM::VHSUBuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1908 /* vld1 */, ARM::VLD1DUPq16, Convert__VecListDPairAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairAllLanes, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1q16, Convert__VecListDPair1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1d16Q, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1DUPd16, Convert__VecListOneDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneDAllLanes, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1d16, Convert__VecListOneD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneD, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1LNdAsm_16, Convert__VecListOneDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneDHWordIndexed, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1d16T, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1DUPq32, Convert__VecListDPairAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairAllLanes, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1q32, Convert__VecListDPair1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1d32Q, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1DUPd32, Convert__VecListOneDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneDAllLanes, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1d32, Convert__VecListOneD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneD, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1LNdAsm_32, Convert__VecListOneDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneDWordIndexed, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1d32T, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1q64, Convert__VecListDPair1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1d64Q, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1d64, Convert__VecListOneD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListOneD, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1d64T, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1DUPq8, Convert__VecListDPairAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairAllLanes, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1q8, Convert__VecListDPair1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1d8Q, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1DUPd8, Convert__VecListOneDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneDAllLanes, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1d8, Convert__VecListOneD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneD, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1LNdAsm_8, Convert__VecListOneDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneDByteIndexed, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1d8T, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1DUPq16wb_fixed, Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1DUPq16wb_register, Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1q16wb_fixed, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1q16wb_register, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1d16Qwb_fixed, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1d16Qwb_register, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1DUPd16wb_fixed, Convert__VecListOneDAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneDAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1DUPd16wb_register, Convert__VecListOneDAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneDAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1d16wb_fixed, Convert__VecListOneD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1d16wb_register, Convert__VecListOneD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1LNdWB_fixed_Asm_16, Convert__VecListOneDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneDHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1LNdWB_register_Asm_16, Convert__VecListOneDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneDHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1d16Twb_fixed, Convert__VecListThreeD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1d16Twb_register, Convert__VecListThreeD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1DUPq32wb_fixed, Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1DUPq32wb_register, Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1q32wb_fixed, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1q32wb_register, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1d32Qwb_fixed, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1d32Qwb_register, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1DUPd32wb_fixed, Convert__VecListOneDAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneDAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1DUPd32wb_register, Convert__VecListOneDAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneDAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1d32wb_fixed, Convert__VecListOneD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1d32wb_register, Convert__VecListOneD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1LNdWB_fixed_Asm_32, Convert__VecListOneDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneDWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1LNdWB_register_Asm_32, Convert__VecListOneDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneDWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1d32Twb_fixed, Convert__VecListThreeD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1d32Twb_register, Convert__VecListThreeD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1q64wb_fixed, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1q64wb_register, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1d64Qwb_fixed, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1d64Qwb_register, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1d64wb_fixed, Convert__VecListOneD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListOneD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1d64wb_register, Convert__VecListOneD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListOneD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1d64Twb_fixed, Convert__VecListThreeD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1d64Twb_register, Convert__VecListThreeD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1DUPq8wb_fixed, Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1DUPq8wb_register, Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1q8wb_fixed, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1q8wb_register, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1d8Qwb_fixed, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1d8Qwb_register, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1DUPd8wb_fixed, Convert__VecListOneDAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneDAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1DUPd8wb_register, Convert__VecListOneDAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneDAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1d8wb_fixed, Convert__VecListOneD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1d8wb_register, Convert__VecListOneD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1LNdWB_fixed_Asm_8, Convert__VecListOneDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneDByteIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1LNdWB_register_Asm_8, Convert__VecListOneDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneDByteIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1d8Twb_fixed, Convert__VecListThreeD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1908 /* vld1 */, ARM::VLD1d8Twb_register, Convert__VecListThreeD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1908 /* vld1 */, ARM::VLD1LNd16, Convert__Reg1_3__AlignedMemory2_8__Tie0__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK__91_, MCK_Imm, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1LNd8, Convert__Reg1_3__AlignedMemory2_8__Tie0__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK__91_, MCK_Imm, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1908 /* vld1 */, ARM::VLD1LNd16_UPD, Convert__Reg1_3__imm_0__AlignedMemory2_8__Imm1_9__Tie0__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK__91_, MCK_Imm, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1908 /* vld1 */, ARM::VLD1LNd32, Convert__Reg1_3__Reg1_8__Imm1_9__Tie0__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK__91_, MCK_Imm, MCK__93_, MCK__125_, MCK_GPR, MCK_Imm }, },
  { 1908 /* vld1 */, ARM::VLD1LNd32_UPD, Convert__Reg1_3__imm_0__AlignedMemory2_8__Imm1_9__Tie0__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK__91_, MCK_Imm, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1908 /* vld1 */, ARM::VLD1LNd8_UPD, Convert__Reg1_3__imm_0__AlignedMemory2_8__Imm1_9__Tie0__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK__91_, MCK_Imm, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd16, Convert__VecListDPairAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairAllLanes, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2d16, Convert__VecListDPair1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd16x2, Convert__VecListDPairSpacedAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairSpacedAllLanes, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2b16, Convert__VecListDPairSpaced1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairSpaced, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2q16, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2LNdAsm_16, Convert__VecListTwoDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListTwoDHWordIndexed, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2LNqAsm_16, Convert__VecListTwoQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListTwoQHWordIndexed, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd32, Convert__VecListDPairAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairAllLanes, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2d32, Convert__VecListDPair1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd32x2, Convert__VecListDPairSpacedAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairSpacedAllLanes, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2b32, Convert__VecListDPairSpaced1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairSpaced, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2q32, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2LNdAsm_32, Convert__VecListTwoDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListTwoDWordIndexed, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2LNqAsm_32, Convert__VecListTwoQWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListTwoQWordIndexed, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd8, Convert__VecListDPairAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairAllLanes, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2d8, Convert__VecListDPair1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd8x2, Convert__VecListDPairSpacedAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairSpacedAllLanes, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2b8, Convert__VecListDPairSpaced1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairSpaced, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2q8, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2LNdAsm_8, Convert__VecListTwoDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListTwoDByteIndexed, MCK_AlignedMemory }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd16wb_fixed, Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd16wb_register, Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2d16wb_fixed, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2d16wb_register, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd16x2wb_fixed, Convert__VecListDPairSpacedAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairSpacedAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd16x2wb_register, Convert__VecListDPairSpacedAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairSpacedAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2b16wb_fixed, Convert__VecListDPairSpaced1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairSpaced, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2b16wb_register, Convert__VecListDPairSpaced1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairSpaced, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2q16wb_fixed, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2q16wb_register, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2LNdWB_fixed_Asm_16, Convert__VecListTwoDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListTwoDHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2LNdWB_register_Asm_16, Convert__VecListTwoDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListTwoDHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2LNqWB_fixed_Asm_16, Convert__VecListTwoQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListTwoQHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2LNqWB_register_Asm_16, Convert__VecListTwoQHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListTwoQHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd32wb_fixed, Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd32wb_register, Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2d32wb_fixed, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2d32wb_register, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd32x2wb_fixed, Convert__VecListDPairSpacedAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairSpacedAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd32x2wb_register, Convert__VecListDPairSpacedAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairSpacedAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2b32wb_fixed, Convert__VecListDPairSpaced1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairSpaced, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2b32wb_register, Convert__VecListDPairSpaced1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairSpaced, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2q32wb_fixed, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2q32wb_register, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2LNdWB_fixed_Asm_32, Convert__VecListTwoDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListTwoDWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2LNdWB_register_Asm_32, Convert__VecListTwoDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListTwoDWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2LNqWB_fixed_Asm_32, Convert__VecListTwoQWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListTwoQWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2LNqWB_register_Asm_32, Convert__VecListTwoQWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListTwoQWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd8wb_fixed, Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd8wb_register, Convert__VecListDPairAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2d8wb_fixed, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2d8wb_register, Convert__VecListDPair1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd8x2wb_fixed, Convert__VecListDPairSpacedAllLanes1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairSpacedAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2DUPd8x2wb_register, Convert__VecListDPairSpacedAllLanes1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairSpacedAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2b8wb_fixed, Convert__VecListDPairSpaced1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairSpaced, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2b8wb_register, Convert__VecListDPairSpaced1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairSpaced, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2q8wb_fixed, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2q8wb_register, Convert__VecListFourD1_2__imm_0__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1913 /* vld2 */, ARM::VLD2LNdWB_fixed_Asm_8, Convert__VecListTwoDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListTwoDByteIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1913 /* vld2 */, ARM::VLD2LNdWB_register_Asm_8, Convert__VecListTwoDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListTwoDByteIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3DUPdAsm_16, Convert__VecListThreeDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeDAllLanes, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3dAsm_16, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3LNdAsm_16, Convert__VecListThreeDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeDHWordIndexed, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3DUPqAsm_16, Convert__VecListThreeQAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQAllLanes, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3qAsm_16, Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQ, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3LNqAsm_16, Convert__VecListThreeQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQHWordIndexed, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3DUPdAsm_32, Convert__VecListThreeDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeDAllLanes, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3dAsm_32, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3LNdAsm_32, Convert__VecListThreeDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeDWordIndexed, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3DUPqAsm_32, Convert__VecListThreeQAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQAllLanes, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3qAsm_32, Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQ, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3LNqAsm_32, Convert__VecListThreeQWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQWordIndexed, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3DUPdAsm_8, Convert__VecListThreeDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeDAllLanes, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3dAsm_8, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3LNdAsm_8, Convert__VecListThreeDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeDByteIndexed, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3DUPqAsm_8, Convert__VecListThreeQAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeQAllLanes, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3qAsm_8, Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeQ, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3DUPdWB_fixed_Asm_16, Convert__VecListThreeDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeDAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3DUPdWB_register_Asm_16, Convert__VecListThreeDAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeDAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3dWB_fixed_Asm_16, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3dWB_register_Asm_16, Convert__VecListThreeD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3LNdWB_fixed_Asm_16, Convert__VecListThreeDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeDHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3LNdWB_register_Asm_16, Convert__VecListThreeDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeDHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3DUPqWB_fixed_Asm_16, Convert__VecListThreeQAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3DUPqWB_register_Asm_16, Convert__VecListThreeQAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3qWB_fixed_Asm_16, Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQ, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3qWB_register_Asm_16, Convert__VecListThreeQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQ, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3LNqWB_fixed_Asm_16, Convert__VecListThreeQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3LNqWB_register_Asm_16, Convert__VecListThreeQHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3DUPdWB_fixed_Asm_32, Convert__VecListThreeDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeDAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3DUPdWB_register_Asm_32, Convert__VecListThreeDAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeDAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3dWB_fixed_Asm_32, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3dWB_register_Asm_32, Convert__VecListThreeD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3LNdWB_fixed_Asm_32, Convert__VecListThreeDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeDWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3LNdWB_register_Asm_32, Convert__VecListThreeDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeDWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3DUPqWB_fixed_Asm_32, Convert__VecListThreeQAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3DUPqWB_register_Asm_32, Convert__VecListThreeQAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3qWB_fixed_Asm_32, Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQ, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3qWB_register_Asm_32, Convert__VecListThreeQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQ, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3LNqWB_fixed_Asm_32, Convert__VecListThreeQWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3LNqWB_register_Asm_32, Convert__VecListThreeQWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3DUPdWB_fixed_Asm_8, Convert__VecListThreeDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeDAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3DUPdWB_register_Asm_8, Convert__VecListThreeDAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeDAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3dWB_fixed_Asm_8, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3dWB_register_Asm_8, Convert__VecListThreeD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3LNdWB_fixed_Asm_8, Convert__VecListThreeDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeDByteIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3LNdWB_register_Asm_8, Convert__VecListThreeDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeDByteIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3DUPqWB_fixed_Asm_8, Convert__VecListThreeQAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeQAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3DUPqWB_register_Asm_8, Convert__VecListThreeQAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeQAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3qWB_fixed_Asm_8, Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeQ, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1918 /* vld3 */, ARM::VLD3qWB_register_Asm_8, Convert__VecListThreeQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeQ, MCK_AlignedMemory, MCK_rGPR }, },
  { 1918 /* vld3 */, ARM::VLD3d16, Convert__Reg1_3__Reg1_4__Reg1_5__AlignedMemory2_7__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3q16, Convert__Reg1_3__Reg1_4__Reg1_5__AlignedMemory2_7__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3d32, Convert__Reg1_3__Reg1_4__Reg1_5__AlignedMemory2_7__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3q32, Convert__Reg1_3__Reg1_4__Reg1_5__AlignedMemory2_7__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3d8, Convert__Reg1_3__Reg1_4__Reg1_5__AlignedMemory2_7__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3q8, Convert__Reg1_3__Reg1_4__Reg1_5__AlignedMemory2_7__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3d16_UPD, Convert__Reg1_3__Reg1_4__Reg1_5__imm_0__AlignedMemory2_7__Imm1_8__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1918 /* vld3 */, ARM::VLD3q16_UPD, Convert__Reg1_3__Reg1_4__Reg1_5__imm_0__AlignedMemory2_7__Imm1_8__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1918 /* vld3 */, ARM::VLD3d32_UPD, Convert__Reg1_3__Reg1_4__Reg1_5__imm_0__AlignedMemory2_7__Imm1_8__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1918 /* vld3 */, ARM::VLD3q32_UPD, Convert__Reg1_3__Reg1_4__Reg1_5__imm_0__AlignedMemory2_7__Imm1_8__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1918 /* vld3 */, ARM::VLD3d8_UPD, Convert__Reg1_3__Reg1_4__Reg1_5__imm_0__AlignedMemory2_7__Imm1_8__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1918 /* vld3 */, ARM::VLD3q8_UPD, Convert__Reg1_3__Reg1_4__Reg1_5__imm_0__AlignedMemory2_7__Imm1_8__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1918 /* vld3 */, ARM::VLD3DUPd16, Convert__Reg1_3__Reg1_6__Reg1_9__AlignedMemory2_13__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3DUPq16, Convert__Reg1_3__Reg1_6__Reg1_9__AlignedMemory2_13__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3DUPd32, Convert__Reg1_3__Reg1_6__Reg1_9__AlignedMemory2_13__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3DUPq32, Convert__Reg1_3__Reg1_6__Reg1_9__AlignedMemory2_13__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3DUPd8, Convert__Reg1_3__Reg1_6__Reg1_9__AlignedMemory2_13__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3DUPq8, Convert__Reg1_3__Reg1_6__Reg1_9__AlignedMemory2_13__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1918 /* vld3 */, ARM::VLD3DUPd16_UPD, Convert__Reg1_3__Reg1_6__Reg1_9__imm_0__AlignedMemory2_13__Imm1_14__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1918 /* vld3 */, ARM::VLD3DUPq16_UPD, Convert__Reg1_3__Reg1_6__Reg1_9__imm_0__AlignedMemory2_13__Imm1_14__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1918 /* vld3 */, ARM::VLD3DUPd32_UPD, Convert__Reg1_3__Reg1_6__Reg1_9__imm_0__AlignedMemory2_13__Imm1_14__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1918 /* vld3 */, ARM::VLD3DUPq32_UPD, Convert__Reg1_3__Reg1_6__Reg1_9__imm_0__AlignedMemory2_13__Imm1_14__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1918 /* vld3 */, ARM::VLD3DUPd8_UPD, Convert__Reg1_3__Reg1_6__Reg1_9__imm_0__AlignedMemory2_13__Imm1_14__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1918 /* vld3 */, ARM::VLD3DUPq8_UPD, Convert__Reg1_3__Reg1_6__Reg1_9__imm_0__AlignedMemory2_13__Imm1_14__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1923 /* vld4 */, ARM::VLD4DUPdAsm_16, Convert__VecListFourDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourDAllLanes, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4dAsm_16, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4LNdAsm_16, Convert__VecListFourDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourDHWordIndexed, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4DUPqAsm_16, Convert__VecListFourQAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQAllLanes, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4qAsm_16, Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQ, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4LNqAsm_16, Convert__VecListFourQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQHWordIndexed, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4DUPdAsm_32, Convert__VecListFourDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourDAllLanes, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4dAsm_32, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4LNdAsm_32, Convert__VecListFourDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourDWordIndexed, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4DUPqAsm_32, Convert__VecListFourQAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQAllLanes, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4qAsm_32, Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQ, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4LNqAsm_32, Convert__VecListFourQWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQWordIndexed, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4DUPdAsm_8, Convert__VecListFourDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourDAllLanes, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4dAsm_8, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4LNdAsm_8, Convert__VecListFourDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourDByteIndexed, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4DUPqAsm_8, Convert__VecListFourQAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourQAllLanes, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4qAsm_8, Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourQ, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4DUPdWB_fixed_Asm_16, Convert__VecListFourDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourDAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4DUPdWB_register_Asm_16, Convert__VecListFourDAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourDAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4dWB_fixed_Asm_16, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4dWB_register_Asm_16, Convert__VecListFourD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4LNdWB_fixed_Asm_16, Convert__VecListFourDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourDHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4LNdWB_register_Asm_16, Convert__VecListFourDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourDHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4DUPqWB_fixed_Asm_16, Convert__VecListFourQAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4DUPqWB_register_Asm_16, Convert__VecListFourQAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4qWB_fixed_Asm_16, Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQ, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4qWB_register_Asm_16, Convert__VecListFourQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQ, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4LNqWB_fixed_Asm_16, Convert__VecListFourQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4LNqWB_register_Asm_16, Convert__VecListFourQHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4DUPdWB_fixed_Asm_32, Convert__VecListFourDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourDAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4DUPdWB_register_Asm_32, Convert__VecListFourDAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourDAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4dWB_fixed_Asm_32, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4dWB_register_Asm_32, Convert__VecListFourD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4LNdWB_fixed_Asm_32, Convert__VecListFourDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourDWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4LNdWB_register_Asm_32, Convert__VecListFourDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourDWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4DUPqWB_fixed_Asm_32, Convert__VecListFourQAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4DUPqWB_register_Asm_32, Convert__VecListFourQAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4qWB_fixed_Asm_32, Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQ, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4qWB_register_Asm_32, Convert__VecListFourQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQ, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4LNqWB_fixed_Asm_32, Convert__VecListFourQWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4LNqWB_register_Asm_32, Convert__VecListFourQWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4DUPdWB_fixed_Asm_8, Convert__VecListFourDAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourDAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4DUPdWB_register_Asm_8, Convert__VecListFourDAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourDAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4dWB_fixed_Asm_8, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4dWB_register_Asm_8, Convert__VecListFourD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4LNdWB_fixed_Asm_8, Convert__VecListFourDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourDByteIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4LNdWB_register_Asm_8, Convert__VecListFourDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourDByteIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4DUPqWB_fixed_Asm_8, Convert__VecListFourQAllLanes1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourQAllLanes, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4DUPqWB_register_Asm_8, Convert__VecListFourQAllLanes1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourQAllLanes, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4qWB_fixed_Asm_8, Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourQ, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 1923 /* vld4 */, ARM::VLD4qWB_register_Asm_8, Convert__VecListFourQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourQ, MCK_AlignedMemory, MCK_rGPR }, },
  { 1923 /* vld4 */, ARM::VLD4d16, Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__AlignedMemory2_8__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4q16, Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__AlignedMemory2_8__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4d32, Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__AlignedMemory2_8__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4q32, Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__AlignedMemory2_8__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4d8, Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__AlignedMemory2_8__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4q8, Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__AlignedMemory2_8__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4d16_UPD, Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__imm_0__AlignedMemory2_8__Imm1_9__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1923 /* vld4 */, ARM::VLD4q16_UPD, Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__imm_0__AlignedMemory2_8__Imm1_9__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1923 /* vld4 */, ARM::VLD4d32_UPD, Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__imm_0__AlignedMemory2_8__Imm1_9__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1923 /* vld4 */, ARM::VLD4q32_UPD, Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__imm_0__AlignedMemory2_8__Imm1_9__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1923 /* vld4 */, ARM::VLD4d8_UPD, Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__imm_0__AlignedMemory2_8__Imm1_9__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1923 /* vld4 */, ARM::VLD4q8_UPD, Convert__Reg1_3__Reg1_4__Reg1_5__Reg1_6__imm_0__AlignedMemory2_8__Imm1_9__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1923 /* vld4 */, ARM::VLD4DUPd16, Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__AlignedMemory2_16__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4DUPq16, Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__AlignedMemory2_16__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4DUPd32, Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__AlignedMemory2_16__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4DUPq32, Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__AlignedMemory2_16__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4DUPd8, Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__AlignedMemory2_16__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4DUPq8, Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__AlignedMemory2_16__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 1923 /* vld4 */, ARM::VLD4DUPd16_UPD, Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__imm_0__AlignedMemory2_16__Imm1_17__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1923 /* vld4 */, ARM::VLD4DUPq16_UPD, Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__imm_0__AlignedMemory2_16__Imm1_17__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1923 /* vld4 */, ARM::VLD4DUPd32_UPD, Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__imm_0__AlignedMemory2_16__Imm1_17__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1923 /* vld4 */, ARM::VLD4DUPq32_UPD, Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__imm_0__AlignedMemory2_16__Imm1_17__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1923 /* vld4 */, ARM::VLD4DUPd8_UPD, Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__imm_0__AlignedMemory2_16__Imm1_17__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1923 /* vld4 */, ARM::VLD4DUPq8_UPD, Convert__Reg1_3__Reg1_6__Reg1_9__Reg1_12__imm_0__AlignedMemory2_16__Imm1_17__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK_DPR, MCK__91_, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 1928 /* vldmdb */, ARM::VLDMDDB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__DPRRegList1_3, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_DPRRegList }, },
  { 1928 /* vldmdb */, ARM::VLDMSDB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__SPRRegList1_3, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_SPRRegList }, },
  { 1935 /* vldmia */, ARM::VLDMDIA, Convert__Reg1_1__CondCode2_0__DPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_DPRRegList }, },
  { 1935 /* vldmia */, ARM::VLDMSIA, Convert__Reg1_1__CondCode2_0__SPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_SPRRegList }, },
  { 1935 /* vldmia */, ARM::VLDMDIA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__DPRRegList1_3, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_DPRRegList }, },
  { 1935 /* vldmia */, ARM::VLDMSIA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__SPRRegList1_3, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_SPRRegList }, },
  { 1942 /* vldr */, ARM::VLDRS, Convert__Reg1_1__AddrMode52_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_SPR, MCK_AddrMode5 }, },
  { 1942 /* vldr */, ARM::VLDRD, Convert__Reg1_1__AddrMode52_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_DPR, MCK_AddrMode5 }, },
  { 1942 /* vldr */, ARM::VLDRS, Convert__Reg1_2__AddrMode52_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_32, MCK_SPR, MCK_AddrMode5 }, },
  { 1942 /* vldr */, ARM::VLDRD, Convert__Reg1_2__AddrMode52_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_AddrMode5 }, },
  { 1947 /* vmax */, ARM::VMAXfd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXfq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1947 /* vmax */, ARM::VMAXsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 1947 /* vmax */, ARM::VMAXsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 1947 /* vmax */, ARM::VMAXsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 1947 /* vmax */, ARM::VMAXuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 1947 /* vmax */, ARM::VMAXuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 1947 /* vmax */, ARM::VMAXuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 1947 /* vmax */, ARM::VMAXfd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXfq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1947 /* vmax */, ARM::VMAXsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1947 /* vmax */, ARM::VMAXsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1947 /* vmax */, ARM::VMAXsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1947 /* vmax */, ARM::VMAXuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1947 /* vmax */, ARM::VMAXuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1947 /* vmax */, ARM::VMAXuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1947 /* vmax */, ARM::VMAXuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1952 /* vmaxnm */, ARM::VMAXNMS, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 1952 /* vmaxnm */, ARM::VMAXNMND, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1952 /* vmaxnm */, ARM::VMAXNMNQ, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1952 /* vmaxnm */, ARM::VMAXNMD, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINfd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINfq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 1959 /* vmin */, ARM::VMINsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 1959 /* vmin */, ARM::VMINsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 1959 /* vmin */, ARM::VMINsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 1959 /* vmin */, ARM::VMINuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 1959 /* vmin */, ARM::VMINuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 1959 /* vmin */, ARM::VMINuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 1959 /* vmin */, ARM::VMINfd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINfq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1959 /* vmin */, ARM::VMINsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1959 /* vmin */, ARM::VMINsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1959 /* vmin */, ARM::VMINsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1959 /* vmin */, ARM::VMINuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1959 /* vmin */, ARM::VMINuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1959 /* vmin */, ARM::VMINuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1959 /* vmin */, ARM::VMINuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1964 /* vminnm */, ARM::VMINNMS, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 1964 /* vminnm */, ARM::VMINNMND, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1964 /* vminnm */, ARM::VMINNMNQ, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1964 /* vminnm */, ARM::VMINNMD, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1971 /* vmla */, ARM::VMLAS, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 1971 /* vmla */, ARM::VMLAfd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1971 /* vmla */, ARM::VMLAfq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1971 /* vmla */, ARM::VMLAD, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1971 /* vmla */, ARM::VMLAv4i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1971 /* vmla */, ARM::VMLAv8i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1971 /* vmla */, ARM::VMLAv2i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1971 /* vmla */, ARM::VMLAv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1971 /* vmla */, ARM::VMLAv8i8, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1971 /* vmla */, ARM::VMLAv16i8, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1971 /* vmla */, ARM::VMLAslfd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 1971 /* vmla */, ARM::VMLAslfq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 1971 /* vmla */, ARM::VMLAslv4i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 1971 /* vmla */, ARM::VMLAslv8i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 1971 /* vmla */, ARM::VMLAslv2i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 1971 /* vmla */, ARM::VMLAslv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 1976 /* vmlal */, ARM::VMLALsv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1976 /* vmlal */, ARM::VMLALsv2i64, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1976 /* vmlal */, ARM::VMLALsv8i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1976 /* vmlal */, ARM::VMLALuv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1976 /* vmlal */, ARM::VMLALuv2i64, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1976 /* vmlal */, ARM::VMLALuv8i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1976 /* vmlal */, ARM::VMLALslsv4i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 1976 /* vmlal */, ARM::VMLALslsv2i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 1976 /* vmlal */, ARM::VMLALsluv4i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 1976 /* vmlal */, ARM::VMLALsluv2i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 1982 /* vmls */, ARM::VMLSS, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 1982 /* vmls */, ARM::VMLSfd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1982 /* vmls */, ARM::VMLSfq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1982 /* vmls */, ARM::VMLSD, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1982 /* vmls */, ARM::VMLSv4i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1982 /* vmls */, ARM::VMLSv8i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1982 /* vmls */, ARM::VMLSv2i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1982 /* vmls */, ARM::VMLSv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1982 /* vmls */, ARM::VMLSv8i8, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 1982 /* vmls */, ARM::VMLSv16i8, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 1982 /* vmls */, ARM::VMLSslfd, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 1982 /* vmls */, ARM::VMLSslfq, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 1982 /* vmls */, ARM::VMLSslv4i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 1982 /* vmls */, ARM::VMLSslv8i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 1982 /* vmls */, ARM::VMLSslv2i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 1982 /* vmls */, ARM::VMLSslv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 1987 /* vmlsl */, ARM::VMLSLsv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1987 /* vmlsl */, ARM::VMLSLsv2i64, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1987 /* vmlsl */, ARM::VMLSLsv8i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1987 /* vmlsl */, ARM::VMLSLuv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1987 /* vmlsl */, ARM::VMLSLuv2i64, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1987 /* vmlsl */, ARM::VMLSLuv8i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 1987 /* vmlsl */, ARM::VMLSLslsv4i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 1987 /* vmlsl */, ARM::VMLSLslsv2i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 1987 /* vmlsl */, ARM::VMLSLsluv4i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 1987 /* vmlsl */, ARM::VMLSLsluv2i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 1993 /* vmov */, ARM::VMOVRS, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_SPR }, },
  { 1993 /* vmov */, ARM::VMOVSR, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_SPR, MCK_GPR }, },
  { 1993 /* vmov */, ARM::VMOVS, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_SPR, MCK_SPR }, },
  { 1993 /* vmov */, ARM::VORRd, Convert__Reg1_1__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR }, },
  { 1993 /* vmov */, ARM::VORRq, Convert__Reg1_1__Reg1_2__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR }, },
  { 1993 /* vmov */, ARM::VMOVRS, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_16, MCK_GPR, MCK_SPR }, },
  { 1993 /* vmov */, ARM::VMOVSR, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_16, MCK_SPR, MCK_GPR }, },
  { 1993 /* vmov */, ARM::VORRd, Convert__Reg1_2__Reg1_3__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR }, },
  { 1993 /* vmov */, ARM::VORRq, Convert__Reg1_2__Reg1_3__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR }, },
  { 1993 /* vmov */, ARM::VMOVS, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 1993 /* vmov */, ARM::FCONSTS, Convert__Reg1_2__FPImm1_3__CondCode2_0, Feature_HasVFP3, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_FPImm }, },
  { 1993 /* vmov */, ARM::VMOVv2f32, Convert__Reg1_2__FPImm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_FPImm }, },
  { 1993 /* vmov */, ARM::VMOVv2i32, Convert__Reg1_2__NEONi32vmov1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_NEONi32vmov }, },
  { 1993 /* vmov */, ARM::VMOVv4f32, Convert__Reg1_2__FPImm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_FPImm }, },
  { 1993 /* vmov */, ARM::VMOVv4i32, Convert__Reg1_2__NEONi32vmov1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_NEONi32vmov }, },
  { 1993 /* vmov */, ARM::VMOVD, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 1993 /* vmov */, ARM::FCONSTD, Convert__Reg1_2__FPImm1_3__CondCode2_0, Feature_HasVFP3|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_FPImm }, },
  { 1993 /* vmov */, ARM::VMOVv4i16, Convert__Reg1_2__NEONi16splat1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_NEONi16splat }, },
  { 1993 /* vmov */, ARM::VMOVv8i16, Convert__Reg1_2__NEONi16splat1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_NEONi16splat }, },
  { 1993 /* vmov */, ARM::VMOVv2i32, Convert__Reg1_2__NEONi32vmov1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_NEONi32vmov }, },
  { 1993 /* vmov */, ARM::VMVNv2i32, Convert__Reg1_2__NEONi32vmovNeg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_NEONi32vmovNeg }, },
  { 1993 /* vmov */, ARM::VMOVv4i32, Convert__Reg1_2__NEONi32vmov1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_NEONi32vmov }, },
  { 1993 /* vmov */, ARM::VMVNv4i32, Convert__Reg1_2__NEONi32vmovNeg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_NEONi32vmovNeg }, },
  { 1993 /* vmov */, ARM::VMOVRS, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_32, MCK_GPR, MCK_SPR }, },
  { 1993 /* vmov */, ARM::VMOVSR, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_32, MCK_SPR, MCK_GPR }, },
  { 1993 /* vmov */, ARM::VORRd, Convert__Reg1_2__Reg1_3__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR }, },
  { 1993 /* vmov */, ARM::VORRq, Convert__Reg1_2__Reg1_3__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 1993 /* vmov */, ARM::VMOVv1i64, Convert__Reg1_2__NEONi64splat1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_NEONi64splat }, },
  { 1993 /* vmov */, ARM::VMOVv2i64, Convert__Reg1_2__NEONi64splat1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_QPR, MCK_NEONi64splat }, },
  { 1993 /* vmov */, ARM::VORRd, Convert__Reg1_2__Reg1_3__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR }, },
  { 1993 /* vmov */, ARM::VORRq, Convert__Reg1_2__Reg1_3__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR }, },
  { 1993 /* vmov */, ARM::VMOVv8i8, Convert__Reg1_2__NEONi8splat1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_NEONi8splat }, },
  { 1993 /* vmov */, ARM::VMOVv16i8, Convert__Reg1_2__NEONi8splat1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_NEONi8splat }, },
  { 1993 /* vmov */, ARM::VMOVRS, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_8, MCK_GPR, MCK_SPR }, },
  { 1993 /* vmov */, ARM::VMOVSR, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_8, MCK_SPR, MCK_GPR }, },
  { 1993 /* vmov */, ARM::VORRd, Convert__Reg1_2__Reg1_3__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 1993 /* vmov */, ARM::VORRq, Convert__Reg1_2__Reg1_3__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 1993 /* vmov */, ARM::VMOVRRD, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_DPR }, },
  { 1993 /* vmov */, ARM::VMOVDRR, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_DPR, MCK_GPR, MCK_GPR }, },
  { 1993 /* vmov */, ARM::VSETLNi16, Convert__Reg1_2__Tie0__Reg1_4__VectorIndex161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_VectorIndex16, MCK_GPR }, },
  { 1993 /* vmov */, ARM::VGETLNi32, Convert__Reg1_2__Reg1_3__VectorIndex321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_GPR, MCK_DPR, MCK_VectorIndex32 }, },
  { 1993 /* vmov */, ARM::VSETLNi32, Convert__Reg1_2__Tie0__Reg1_4__VectorIndex321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_VectorIndex32, MCK_GPR }, },
  { 1993 /* vmov */, ARM::VSETLNi8, Convert__Reg1_2__Tie0__Reg1_4__VectorIndex81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_VectorIndex8, MCK_GPR }, },
  { 1993 /* vmov */, ARM::VMOVRRD, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f64, MCK_GPR, MCK_GPR, MCK_DPR }, },
  { 1993 /* vmov */, ARM::VMOVDRR, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_GPR, MCK_GPR }, },
  { 1993 /* vmov */, ARM::VGETLNs16, Convert__Reg1_2__Reg1_3__VectorIndex161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_GPR, MCK_DPR, MCK_VectorIndex16 }, },
  { 1993 /* vmov */, ARM::VGETLNs8, Convert__Reg1_2__Reg1_3__VectorIndex81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_GPR, MCK_DPR, MCK_VectorIndex8 }, },
  { 1993 /* vmov */, ARM::VGETLNu16, Convert__Reg1_2__Reg1_3__VectorIndex161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_GPR, MCK_DPR, MCK_VectorIndex16 }, },
  { 1993 /* vmov */, ARM::VGETLNu8, Convert__Reg1_2__Reg1_3__VectorIndex81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_GPR, MCK_DPR, MCK_VectorIndex8 }, },
  { 1993 /* vmov */, ARM::VMOVRRS, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_GPR, MCK_SPR, MCK_SPR }, },
  { 1993 /* vmov */, ARM::VMOVSRR, Convert__Reg1_1__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_SPR, MCK_SPR, MCK_GPR, MCK_GPR }, },
  { 1998 /* vmovl */, ARM::VMOVLsv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR }, },
  { 1998 /* vmovl */, ARM::VMOVLsv2i64, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR }, },
  { 1998 /* vmovl */, ARM::VMOVLsv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_DPR }, },
  { 1998 /* vmovl */, ARM::VMOVLuv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR }, },
  { 1998 /* vmovl */, ARM::VMOVLuv2i64, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR }, },
  { 1998 /* vmovl */, ARM::VMOVLuv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_DPR }, },
  { 2004 /* vmovn */, ARM::VMOVNv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_QPR }, },
  { 2004 /* vmovn */, ARM::VMOVNv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_QPR }, },
  { 2004 /* vmovn */, ARM::VMOVNv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_QPR }, },
  { 2010 /* vmrs */, ARM::VMRS, Convert__Reg1_1__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_FPSCR }, },
  { 2010 /* vmrs */, ARM::VMRS_FPSID, Convert__Reg1_1__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_FPSID }, },
  { 2010 /* vmrs */, ARM::VMRS_MVFR2, Convert__Reg1_1__CondCode2_0, Feature_HasFPARMv8, { MCK_CondCode, MCK_GPR, MCK_MVFR2 }, },
  { 2010 /* vmrs */, ARM::VMRS_MVFR1, Convert__Reg1_1__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_MVFR1 }, },
  { 2010 /* vmrs */, ARM::VMRS_MVFR0, Convert__Reg1_1__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_MVFR0 }, },
  { 2010 /* vmrs */, ARM::VMRS_FPEXC, Convert__Reg1_1__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_FPEXC }, },
  { 2010 /* vmrs */, ARM::VMRS_FPINST, Convert__Reg1_1__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_FPINST }, },
  { 2010 /* vmrs */, ARM::VMRS_FPINST2, Convert__Reg1_1__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_FPINST2 }, },
  { 2010 /* vmrs */, ARM::FMSTAT, Convert__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_APSR_NZCV, MCK_FPSCR }, },
  { 2015 /* vmsr */, ARM::VMSR, Convert__Reg1_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_FPSCR, MCK_GPR }, },
  { 2015 /* vmsr */, ARM::VMSR_FPSID, Convert__Reg1_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_FPSID, MCK_GPR }, },
  { 2015 /* vmsr */, ARM::VMSR_FPEXC, Convert__Reg1_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_FPEXC, MCK_GPR }, },
  { 2015 /* vmsr */, ARM::VMSR_FPINST, Convert__Reg1_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_FPINST, MCK_GPR }, },
  { 2015 /* vmsr */, ARM::VMSR_FPINST2, Convert__Reg1_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_FPINST2, MCK_GPR }, },
  { 2020 /* vmul */, ARM::VMULS, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2020 /* vmul */, ARM::VMULfd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2020 /* vmul */, ARM::VMULfq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2020 /* vmul */, ARM::VMULD, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2020 /* vmul */, ARM::VMULv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR }, },
  { 2020 /* vmul */, ARM::VMULv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR }, },
  { 2020 /* vmul */, ARM::VMULv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR }, },
  { 2020 /* vmul */, ARM::VMULv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR }, },
  { 2020 /* vmul */, ARM::VMULv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR }, },
  { 2020 /* vmul */, ARM::VMULv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_QPR }, },
  { 2020 /* vmul */, ARM::VMULpd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_p8, MCK_DPR, MCK_DPR }, },
  { 2020 /* vmul */, ARM::VMULpq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_p8, MCK_QPR, MCK_QPR }, },
  { 2020 /* vmul */, ARM::VMULS, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 2020 /* vmul */, ARM::VMULslfd, Convert__Reg1_2__Reg1_2__Reg1_3__VectorIndex321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2020 /* vmul */, ARM::VMULfd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2020 /* vmul */, ARM::VMULslfq, Convert__Reg1_2__Reg1_2__Reg1_3__VectorIndex321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2020 /* vmul */, ARM::VMULfq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2020 /* vmul */, ARM::VMULD, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2020 /* vmul */, ARM::VMULslv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__VectorIndex161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 2020 /* vmul */, ARM::VMULv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2020 /* vmul */, ARM::VMULslv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__VectorIndex161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 2020 /* vmul */, ARM::VMULv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2020 /* vmul */, ARM::VMULslv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__VectorIndex321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2020 /* vmul */, ARM::VMULv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2020 /* vmul */, ARM::VMULslv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__VectorIndex321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2020 /* vmul */, ARM::VMULv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2020 /* vmul */, ARM::VMULv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2020 /* vmul */, ARM::VMULv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2020 /* vmul */, ARM::VMULpd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_p8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2020 /* vmul */, ARM::VMULpq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_p8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2020 /* vmul */, ARM::VMULslfd, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2020 /* vmul */, ARM::VMULslfq, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2020 /* vmul */, ARM::VMULslv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 2020 /* vmul */, ARM::VMULslv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 2020 /* vmul */, ARM::VMULslv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2020 /* vmul */, ARM::VMULslv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2025 /* vmull */, ARM::VMULLp64, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasV8|Feature_HasCrypto, { MCK__DOT_p64, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2025 /* vmull */, ARM::VMULLp8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_p8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2025 /* vmull */, ARM::VMULLsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2025 /* vmull */, ARM::VMULLsv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2025 /* vmull */, ARM::VMULLsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2025 /* vmull */, ARM::VMULLuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2025 /* vmull */, ARM::VMULLuv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2025 /* vmull */, ARM::VMULLuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2025 /* vmull */, ARM::VMULLslsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 2025 /* vmull */, ARM::VMULLslsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2025 /* vmull */, ARM::VMULLsluv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 2025 /* vmull */, ARM::VMULLsluv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2031 /* vmvn */, ARM::VMVNd, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR }, },
  { 2031 /* vmvn */, ARM::VMVNq, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR }, },
  { 2031 /* vmvn */, ARM::VMVNv4i16, Convert__Reg1_2__NEONi16splat1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_NEONi16splat }, },
  { 2031 /* vmvn */, ARM::VMVNv8i16, Convert__Reg1_2__NEONi16splat1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_NEONi16splat }, },
  { 2031 /* vmvn */, ARM::VMVNd, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR }, },
  { 2031 /* vmvn */, ARM::VMVNq, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR }, },
  { 2031 /* vmvn */, ARM::VMVNv2i32, Convert__Reg1_2__NEONi32vmov1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_NEONi32vmov }, },
  { 2031 /* vmvn */, ARM::VMOVv2i32, Convert__Reg1_2__NEONi32vmovNeg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_NEONi32vmovNeg }, },
  { 2031 /* vmvn */, ARM::VMVNv4i32, Convert__Reg1_2__NEONi32vmov1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_NEONi32vmov }, },
  { 2031 /* vmvn */, ARM::VMOVv4i32, Convert__Reg1_2__NEONi32vmovNeg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_NEONi32vmovNeg }, },
  { 2031 /* vmvn */, ARM::VMVNd, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR }, },
  { 2031 /* vmvn */, ARM::VMVNq, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 2031 /* vmvn */, ARM::VMVNd, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR }, },
  { 2031 /* vmvn */, ARM::VMVNq, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR }, },
  { 2031 /* vmvn */, ARM::VMVNd, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 2031 /* vmvn */, ARM::VMVNq, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 2036 /* vneg */, ARM::VNEGS, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2036 /* vneg */, ARM::VNEGfd, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2036 /* vneg */, ARM::VNEGf32q, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2036 /* vneg */, ARM::VNEGD, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2036 /* vneg */, ARM::VNEGs16d, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2036 /* vneg */, ARM::VNEGs16q, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2036 /* vneg */, ARM::VNEGs32d, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2036 /* vneg */, ARM::VNEGs32q, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2036 /* vneg */, ARM::VNEGs8d, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2036 /* vneg */, ARM::VNEGs8q, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 2041 /* vnmla */, ARM::VNMLAS, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 2041 /* vnmla */, ARM::VNMLAD, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2047 /* vnmls */, ARM::VNMLSS, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 2047 /* vnmls */, ARM::VNMLSD, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2053 /* vnmul */, ARM::VNMULS, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 2053 /* vnmul */, ARM::VNMULD, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2059 /* vorn */, ARM::VORNd, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2059 /* vorn */, ARM::VORNq, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2064 /* vorr */, ARM::VORRd, Convert__Reg1_1__Reg1_1__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR }, },
  { 2064 /* vorr */, ARM::VORRq, Convert__Reg1_1__Reg1_1__Reg1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR }, },
  { 2064 /* vorr */, ARM::VORRiv4i16, Convert__Reg1_2__NEONi16splat1_3__Tie0__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_NEONi16splat }, },
  { 2064 /* vorr */, ARM::VORRiv8i16, Convert__Reg1_2__NEONi16splat1_3__Tie0__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_NEONi16splat }, },
  { 2064 /* vorr */, ARM::VORRd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR }, },
  { 2064 /* vorr */, ARM::VORRq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR }, },
  { 2064 /* vorr */, ARM::VORRiv2i32, Convert__Reg1_2__NEONi32splat1_3__Tie0__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_NEONi32splat }, },
  { 2064 /* vorr */, ARM::VORRiv4i32, Convert__Reg1_2__NEONi32splat1_3__Tie0__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_NEONi32splat }, },
  { 2064 /* vorr */, ARM::VORRd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR }, },
  { 2064 /* vorr */, ARM::VORRq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 2064 /* vorr */, ARM::VORRd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR }, },
  { 2064 /* vorr */, ARM::VORRq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR }, },
  { 2064 /* vorr */, ARM::VORRd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 2064 /* vorr */, ARM::VORRq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 2064 /* vorr */, ARM::VORRd, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2064 /* vorr */, ARM::VORRq, Convert__Reg1_1__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2064 /* vorr */, ARM::VORRd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2064 /* vorr */, ARM::VORRq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2064 /* vorr */, ARM::VORRd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2064 /* vorr */, ARM::VORRq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2064 /* vorr */, ARM::VORRd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2064 /* vorr */, ARM::VORRq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2064 /* vorr */, ARM::VORRd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2064 /* vorr */, ARM::VORRq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2069 /* vpadal */, ARM::VPADALsv4i16, Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2069 /* vpadal */, ARM::VPADALsv8i16, Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2069 /* vpadal */, ARM::VPADALsv2i32, Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2069 /* vpadal */, ARM::VPADALsv4i32, Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2069 /* vpadal */, ARM::VPADALsv8i8, Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2069 /* vpadal */, ARM::VPADALsv16i8, Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 2069 /* vpadal */, ARM::VPADALuv4i16, Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 2069 /* vpadal */, ARM::VPADALuv8i16, Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 2069 /* vpadal */, ARM::VPADALuv2i32, Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 2069 /* vpadal */, ARM::VPADALuv4i32, Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 2069 /* vpadal */, ARM::VPADALuv8i8, Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 2069 /* vpadal */, ARM::VPADALuv16i8, Convert__Reg1_2__Tie0__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 2076 /* vpadd */, ARM::VPADDf, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2076 /* vpadd */, ARM::VPADDi16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR }, },
  { 2076 /* vpadd */, ARM::VPADDi32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR }, },
  { 2076 /* vpadd */, ARM::VPADDi8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR }, },
  { 2076 /* vpadd */, ARM::VPADDf, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2076 /* vpadd */, ARM::VPADDi16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2076 /* vpadd */, ARM::VPADDi32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2076 /* vpadd */, ARM::VPADDi8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2082 /* vpaddl */, ARM::VPADDLsv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2082 /* vpaddl */, ARM::VPADDLsv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2082 /* vpaddl */, ARM::VPADDLsv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2082 /* vpaddl */, ARM::VPADDLsv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2082 /* vpaddl */, ARM::VPADDLsv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2082 /* vpaddl */, ARM::VPADDLsv16i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 2082 /* vpaddl */, ARM::VPADDLuv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 2082 /* vpaddl */, ARM::VPADDLuv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 2082 /* vpaddl */, ARM::VPADDLuv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 2082 /* vpaddl */, ARM::VPADDLuv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 2082 /* vpaddl */, ARM::VPADDLuv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 2082 /* vpaddl */, ARM::VPADDLuv16i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 2089 /* vpmax */, ARM::VPMAXf, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2089 /* vpmax */, ARM::VPMAXs16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2089 /* vpmax */, ARM::VPMAXs32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2089 /* vpmax */, ARM::VPMAXs8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2089 /* vpmax */, ARM::VPMAXu16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 2089 /* vpmax */, ARM::VPMAXu32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 2089 /* vpmax */, ARM::VPMAXu8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 2089 /* vpmax */, ARM::VPMAXf, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2089 /* vpmax */, ARM::VPMAXs16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2089 /* vpmax */, ARM::VPMAXs32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2089 /* vpmax */, ARM::VPMAXs8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2089 /* vpmax */, ARM::VPMAXu16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2089 /* vpmax */, ARM::VPMAXu32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2089 /* vpmax */, ARM::VPMAXu8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINf, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINs16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINs32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINs8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINu16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINu32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINu8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINf, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINs16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINs32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINs8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINu16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINu32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2095 /* vpmin */, ARM::VPMINu8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2101 /* vpop */, ARM::VLDMDIA_UPD, Convert__regSP__Tie0__CondCode2_0__DPRRegList1_1, Feature_HasVFP2, { MCK_CondCode, MCK_DPRRegList }, },
  { 2101 /* vpop */, ARM::VLDMSIA_UPD, Convert__regSP__Tie0__CondCode2_0__SPRRegList1_1, Feature_HasVFP2, { MCK_CondCode, MCK_SPRRegList }, },
  { 2101 /* vpop */, ARM::VLDMDIA_UPD, Convert__regSP__Tie0__CondCode2_0__DPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_16, MCK_DPRRegList }, },
  { 2101 /* vpop */, ARM::VLDMSIA_UPD, Convert__regSP__Tie0__CondCode2_0__SPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_16, MCK_SPRRegList }, },
  { 2101 /* vpop */, ARM::VLDMDIA_UPD, Convert__regSP__Tie0__CondCode2_0__DPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_32, MCK_DPRRegList }, },
  { 2101 /* vpop */, ARM::VLDMSIA_UPD, Convert__regSP__Tie0__CondCode2_0__SPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_32, MCK_SPRRegList }, },
  { 2101 /* vpop */, ARM::VLDMDIA_UPD, Convert__regSP__Tie0__CondCode2_0__DPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_64, MCK_DPRRegList }, },
  { 2101 /* vpop */, ARM::VLDMSIA_UPD, Convert__regSP__Tie0__CondCode2_0__SPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_64, MCK_SPRRegList }, },
  { 2101 /* vpop */, ARM::VLDMDIA_UPD, Convert__regSP__Tie0__CondCode2_0__DPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_8, MCK_DPRRegList }, },
  { 2101 /* vpop */, ARM::VLDMSIA_UPD, Convert__regSP__Tie0__CondCode2_0__SPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_8, MCK_SPRRegList }, },
  { 2106 /* vpush */, ARM::VSTMDDB_UPD, Convert__regSP__Tie0__CondCode2_0__DPRRegList1_1, Feature_HasVFP2, { MCK_CondCode, MCK_DPRRegList }, },
  { 2106 /* vpush */, ARM::VSTMSDB_UPD, Convert__regSP__Tie0__CondCode2_0__SPRRegList1_1, Feature_HasVFP2, { MCK_CondCode, MCK_SPRRegList }, },
  { 2106 /* vpush */, ARM::VSTMDDB_UPD, Convert__regSP__Tie0__CondCode2_0__DPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_16, MCK_DPRRegList }, },
  { 2106 /* vpush */, ARM::VSTMSDB_UPD, Convert__regSP__Tie0__CondCode2_0__SPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_16, MCK_SPRRegList }, },
  { 2106 /* vpush */, ARM::VSTMDDB_UPD, Convert__regSP__Tie0__CondCode2_0__DPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_32, MCK_DPRRegList }, },
  { 2106 /* vpush */, ARM::VSTMSDB_UPD, Convert__regSP__Tie0__CondCode2_0__SPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_32, MCK_SPRRegList }, },
  { 2106 /* vpush */, ARM::VSTMDDB_UPD, Convert__regSP__Tie0__CondCode2_0__DPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_64, MCK_DPRRegList }, },
  { 2106 /* vpush */, ARM::VSTMSDB_UPD, Convert__regSP__Tie0__CondCode2_0__SPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_64, MCK_SPRRegList }, },
  { 2106 /* vpush */, ARM::VSTMDDB_UPD, Convert__regSP__Tie0__CondCode2_0__DPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_8, MCK_DPRRegList }, },
  { 2106 /* vpush */, ARM::VSTMSDB_UPD, Convert__regSP__Tie0__CondCode2_0__SPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_8, MCK_SPRRegList }, },
  { 2112 /* vqabs */, ARM::VQABSv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2112 /* vqabs */, ARM::VQABSv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2112 /* vqabs */, ARM::VQABSv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2112 /* vqabs */, ARM::VQABSv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2112 /* vqabs */, ARM::VQABSv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2112 /* vqabs */, ARM::VQABSv16i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2118 /* vqadd */, ARM::VQADDuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2124 /* vqdmlal */, ARM::VQDMLALv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2124 /* vqdmlal */, ARM::VQDMLALv2i64, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2124 /* vqdmlal */, ARM::VQDMLALslv4i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 2124 /* vqdmlal */, ARM::VQDMLALslv2i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2132 /* vqdmlsl */, ARM::VQDMLSLv4i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2132 /* vqdmlsl */, ARM::VQDMLSLv2i64, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2132 /* vqdmlsl */, ARM::VQDMLSLslv4i16, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 2132 /* vqdmlsl */, ARM::VQDMLSLslv2i32, Convert__Reg1_2__Tie0__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2140 /* vqdmulh */, ARM::VQDMULHv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2140 /* vqdmulh */, ARM::VQDMULHv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2140 /* vqdmulh */, ARM::VQDMULHv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2140 /* vqdmulh */, ARM::VQDMULHv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2140 /* vqdmulh */, ARM::VQDMULHv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2140 /* vqdmulh */, ARM::VQDMULHv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2140 /* vqdmulh */, ARM::VQDMULHv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2140 /* vqdmulh */, ARM::VQDMULHv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2140 /* vqdmulh */, ARM::VQDMULHslv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 2140 /* vqdmulh */, ARM::VQDMULHslv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 2140 /* vqdmulh */, ARM::VQDMULHslv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2140 /* vqdmulh */, ARM::VQDMULHslv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2148 /* vqdmull */, ARM::VQDMULLv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2148 /* vqdmull */, ARM::VQDMULLv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2148 /* vqdmull */, ARM::VQDMULLslv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 2148 /* vqdmull */, ARM::VQDMULLslv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2156 /* vqmovn */, ARM::VQMOVNsv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_QPR }, },
  { 2156 /* vqmovn */, ARM::VQMOVNsv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_QPR }, },
  { 2156 /* vqmovn */, ARM::VQMOVNsv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_QPR }, },
  { 2156 /* vqmovn */, ARM::VQMOVNuv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_QPR }, },
  { 2156 /* vqmovn */, ARM::VQMOVNuv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_QPR }, },
  { 2156 /* vqmovn */, ARM::VQMOVNuv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_QPR }, },
  { 2163 /* vqmovun */, ARM::VQMOVNsuv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_QPR }, },
  { 2163 /* vqmovun */, ARM::VQMOVNsuv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_QPR }, },
  { 2163 /* vqmovun */, ARM::VQMOVNsuv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_QPR }, },
  { 2171 /* vqneg */, ARM::VQNEGv4i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2171 /* vqneg */, ARM::VQNEGv8i16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2171 /* vqneg */, ARM::VQNEGv2i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2171 /* vqneg */, ARM::VQNEGv4i32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2171 /* vqneg */, ARM::VQNEGv8i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2171 /* vqneg */, ARM::VQNEGv16i8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 2177 /* vqrdmulh */, ARM::VQRDMULHv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2177 /* vqrdmulh */, ARM::VQRDMULHv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2177 /* vqrdmulh */, ARM::VQRDMULHv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2177 /* vqrdmulh */, ARM::VQRDMULHv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2177 /* vqrdmulh */, ARM::VQRDMULHv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2177 /* vqrdmulh */, ARM::VQRDMULHv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2177 /* vqrdmulh */, ARM::VQRDMULHv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2177 /* vqrdmulh */, ARM::VQRDMULHv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2177 /* vqrdmulh */, ARM::VQRDMULHslv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 2177 /* vqrdmulh */, ARM::VQRDMULHslv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex161_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_DPR_8, MCK_VectorIndex16 }, },
  { 2177 /* vqrdmulh */, ARM::VQRDMULHslv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2177 /* vqrdmulh */, ARM::VQRDMULHslv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__VectorIndex321_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_DPR_VFP2, MCK_VectorIndex32 }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2186 /* vqrshl */, ARM::VQRSHLuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2193 /* vqrshrn */, ARM::VQRSHRNsv8i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2193 /* vqrshrn */, ARM::VQRSHRNsv4i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2193 /* vqrshrn */, ARM::VQRSHRNsv2i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2193 /* vqrshrn */, ARM::VQRSHRNuv8i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2193 /* vqrshrn */, ARM::VQRSHRNuv4i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2193 /* vqrshrn */, ARM::VQRSHRNuv2i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2201 /* vqrshrun */, ARM::VQRSHRUNv8i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2201 /* vqrshrun */, ARM::VQRSHRUNv4i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2201 /* vqrshrun */, ARM::VQRSHRUNv2i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2210 /* vqshl */, ARM::VQSHLsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv4i16, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv8i16, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv2i32, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv4i32, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv1i64, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv2i64, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv8i8, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv16i8, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv4i16, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv8i16, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv2i32, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv4i32, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv1i64, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv2i64, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv8i8, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv16i8, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv4i16, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv8i16, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv2i32, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv4i32, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv1i64, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv2i64, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv8i8, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLsiv16i8, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv4i16, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv8i16, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv2i32, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv4i32, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv1i64, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv2i64, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv8i8, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2210 /* vqshl */, ARM::VQSHLuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2210 /* vqshl */, ARM::VQSHLuiv16i8, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv4i16, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv8i16, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv2i32, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv4i32, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv1i64, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv2i64, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv8i8, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv16i8, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv4i16, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv8i16, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv2i32, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv4i32, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv1i64, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv2i64, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv8i8, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2216 /* vqshlu */, ARM::VQSHLsuv16i8, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2223 /* vqshrn */, ARM::VQSHRNsv8i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2223 /* vqshrn */, ARM::VQSHRNsv4i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2223 /* vqshrn */, ARM::VQSHRNsv2i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2223 /* vqshrn */, ARM::VQSHRNuv8i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2223 /* vqshrn */, ARM::VQSHRNuv4i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2223 /* vqshrn */, ARM::VQSHRNuv2i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2230 /* vqshrun */, ARM::VQSHRUNv8i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2230 /* vqshrun */, ARM::VQSHRUNv4i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2230 /* vqshrun */, ARM::VQSHRUNv2i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2238 /* vqsub */, ARM::VQSUBsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2238 /* vqsub */, ARM::VQSUBuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2244 /* vraddhn */, ARM::VRADDHNv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_QPR, MCK_QPR }, },
  { 2244 /* vraddhn */, ARM::VRADDHNv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_QPR, MCK_QPR }, },
  { 2244 /* vraddhn */, ARM::VRADDHNv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_QPR, MCK_QPR }, },
  { 2252 /* vrecpe */, ARM::VRECPEfd, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2252 /* vrecpe */, ARM::VRECPEfq, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2252 /* vrecpe */, ARM::VRECPEd, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 2252 /* vrecpe */, ARM::VRECPEq, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 2259 /* vrecps */, ARM::VRECPSfd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2259 /* vrecps */, ARM::VRECPSfq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2259 /* vrecps */, ARM::VRECPSfd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2259 /* vrecps */, ARM::VRECPSfq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2266 /* vrev16 */, ARM::VREV16d8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 2266 /* vrev16 */, ARM::VREV16q8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 2273 /* vrev32 */, ARM::VREV32d16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR }, },
  { 2273 /* vrev32 */, ARM::VREV32q16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR }, },
  { 2273 /* vrev32 */, ARM::VREV32d8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 2273 /* vrev32 */, ARM::VREV32q8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 2280 /* vrev64 */, ARM::VREV64d16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR }, },
  { 2280 /* vrev64 */, ARM::VREV64q16, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR }, },
  { 2280 /* vrev64 */, ARM::VREV64d32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR }, },
  { 2280 /* vrev64 */, ARM::VREV64q32, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 2280 /* vrev64 */, ARM::VREV64d8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 2280 /* vrev64 */, ARM::VREV64q8, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2287 /* vrhadd */, ARM::VRHADDuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2294 /* vrinta */, ARM::VRINTAS, Convert__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2294 /* vrinta */, ARM::VRINTAND, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2294 /* vrinta */, ARM::VRINTANQ, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2294 /* vrinta */, ARM::VRINTAD, Convert__Reg1_1__Reg1_2, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2294 /* vrinta */, ARM::VRINTAS, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_f32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2294 /* vrinta */, ARM::VRINTAND, Convert__Reg1_2__Reg1_3, Feature_HasNEON, { MCK__DOT_f32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2294 /* vrinta */, ARM::VRINTANQ, Convert__Reg1_2__Reg1_3, Feature_HasNEON, { MCK__DOT_f32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2294 /* vrinta */, ARM::VRINTAD, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2301 /* vrintm */, ARM::VRINTMS, Convert__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2301 /* vrintm */, ARM::VRINTMND, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2301 /* vrintm */, ARM::VRINTMNQ, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2301 /* vrintm */, ARM::VRINTMD, Convert__Reg1_1__Reg1_2, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2301 /* vrintm */, ARM::VRINTMS, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_f32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2301 /* vrintm */, ARM::VRINTMND, Convert__Reg1_2__Reg1_3, Feature_HasNEON, { MCK__DOT_f32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2301 /* vrintm */, ARM::VRINTMNQ, Convert__Reg1_2__Reg1_3, Feature_HasNEON, { MCK__DOT_f32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2301 /* vrintm */, ARM::VRINTMD, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2308 /* vrintn */, ARM::VRINTNS, Convert__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2308 /* vrintn */, ARM::VRINTNND, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2308 /* vrintn */, ARM::VRINTNNQ, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2308 /* vrintn */, ARM::VRINTND, Convert__Reg1_1__Reg1_2, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2308 /* vrintn */, ARM::VRINTNS, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_f32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2308 /* vrintn */, ARM::VRINTNND, Convert__Reg1_2__Reg1_3, Feature_HasNEON, { MCK__DOT_f32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2308 /* vrintn */, ARM::VRINTNNQ, Convert__Reg1_2__Reg1_3, Feature_HasNEON, { MCK__DOT_f32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2308 /* vrintn */, ARM::VRINTND, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2315 /* vrintp */, ARM::VRINTPS, Convert__Reg1_1__Reg1_2, Feature_HasFPARMv8, { MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2315 /* vrintp */, ARM::VRINTPND, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2315 /* vrintp */, ARM::VRINTPNQ, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2315 /* vrintp */, ARM::VRINTPD, Convert__Reg1_1__Reg1_2, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2315 /* vrintp */, ARM::VRINTPS, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_f32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2315 /* vrintp */, ARM::VRINTPND, Convert__Reg1_2__Reg1_3, Feature_HasNEON, { MCK__DOT_f32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2315 /* vrintp */, ARM::VRINTPNQ, Convert__Reg1_2__Reg1_3, Feature_HasNEON, { MCK__DOT_f32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2315 /* vrintp */, ARM::VRINTPD, Convert__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2322 /* vrintr */, ARM::VRINTRS, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasFPARMv8, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2322 /* vrintr */, ARM::VRINTRD, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2322 /* vrintr */, ARM::VRINTRS, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasFPARMv8, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2322 /* vrintr */, ARM::VRINTRD, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2329 /* vrintx */, ARM::VRINTXND, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2329 /* vrintx */, ARM::VRINTXNQ, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2329 /* vrintx */, ARM::VRINTXND, Convert__Reg1_2__Reg1_3, Feature_HasNEON, { MCK__DOT_f32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2329 /* vrintx */, ARM::VRINTXNQ, Convert__Reg1_2__Reg1_3, Feature_HasNEON, { MCK__DOT_f32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2329 /* vrintx */, ARM::VRINTXS, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasFPARMv8, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2329 /* vrintx */, ARM::VRINTXD, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2329 /* vrintx */, ARM::VRINTXS, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasFPARMv8, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2329 /* vrintx */, ARM::VRINTXD, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2336 /* vrintz */, ARM::VRINTZND, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2336 /* vrintz */, ARM::VRINTZNQ, Convert__Reg1_1__Reg1_2, Feature_HasV8|Feature_HasNEON, { MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2336 /* vrintz */, ARM::VRINTZND, Convert__Reg1_2__Reg1_3, Feature_HasNEON, { MCK__DOT_f32, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2336 /* vrintz */, ARM::VRINTZNQ, Convert__Reg1_2__Reg1_3, Feature_HasNEON, { MCK__DOT_f32, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2336 /* vrintz */, ARM::VRINTZS, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasFPARMv8, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2336 /* vrintz */, ARM::VRINTZD, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2336 /* vrintz */, ARM::VRINTZS, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasFPARMv8, { MCK_CondCode, MCK__DOT_f32, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2336 /* vrintz */, ARM::VRINTZD, Convert__Reg1_3__Reg1_4__CondCode2_0, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2343 /* vrshl */, ARM::VRSHLuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2349 /* vrshr */, ARM::VRSHRsv4i16, Convert__Reg1_2__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_ShrImm16 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv8i16, Convert__Reg1_2__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_ShrImm16 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv2i32, Convert__Reg1_2__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_ShrImm32 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv4i32, Convert__Reg1_2__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_ShrImm32 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv1i64, Convert__Reg1_2__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_ShrImm64 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv2i64, Convert__Reg1_2__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_ShrImm64 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv8i8, Convert__Reg1_2__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_ShrImm8 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv16i8, Convert__Reg1_2__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_ShrImm8 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv4i16, Convert__Reg1_2__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_ShrImm16 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv8i16, Convert__Reg1_2__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_ShrImm16 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv2i32, Convert__Reg1_2__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_ShrImm32 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv4i32, Convert__Reg1_2__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_ShrImm32 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv1i64, Convert__Reg1_2__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_ShrImm64 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv2i64, Convert__Reg1_2__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_ShrImm64 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv8i8, Convert__Reg1_2__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_ShrImm8 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv16i8, Convert__Reg1_2__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_ShrImm8 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv4i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_ShrImm16 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv8i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv2i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_ShrImm32 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv4i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv1i64, Convert__Reg1_2__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR, MCK_ShrImm64 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv2i64, Convert__Reg1_2__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR, MCK_ShrImm64 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv8i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_ShrImm8 }, },
  { 2349 /* vrshr */, ARM::VRSHRsv16i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv4i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_ShrImm16 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv8i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv2i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_ShrImm32 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv4i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv1i64, Convert__Reg1_2__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR, MCK_ShrImm64 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv2i64, Convert__Reg1_2__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR, MCK_ShrImm64 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv8i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_ShrImm8 }, },
  { 2349 /* vrshr */, ARM::VRSHRuv16i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2355 /* vrshrn */, ARM::VRSHRNv8i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2355 /* vrshrn */, ARM::VRSHRNv4i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2355 /* vrshrn */, ARM::VRSHRNv2i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2362 /* vrsqrte */, ARM::VRSQRTEfd, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2362 /* vrsqrte */, ARM::VRSQRTEfq, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2362 /* vrsqrte */, ARM::VRSQRTEd, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 2362 /* vrsqrte */, ARM::VRSQRTEq, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 2370 /* vrsqrts */, ARM::VRSQRTSfd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2370 /* vrsqrts */, ARM::VRSQRTSfq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2370 /* vrsqrts */, ARM::VRSQRTSfd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2370 /* vrsqrts */, ARM::VRSQRTSfq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2378 /* vrsra */, ARM::VRSRAsv4i16, Convert__Reg1_2__Tie0__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_ShrImm16 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv8i16, Convert__Reg1_2__Tie0__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_ShrImm16 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv2i32, Convert__Reg1_2__Tie0__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_ShrImm32 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv4i32, Convert__Reg1_2__Tie0__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_ShrImm32 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv1i64, Convert__Reg1_2__Tie0__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_ShrImm64 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv2i64, Convert__Reg1_2__Tie0__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_ShrImm64 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv8i8, Convert__Reg1_2__Tie0__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_ShrImm8 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv16i8, Convert__Reg1_2__Tie0__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_ShrImm8 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv4i16, Convert__Reg1_2__Tie0__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_ShrImm16 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv8i16, Convert__Reg1_2__Tie0__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_ShrImm16 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv2i32, Convert__Reg1_2__Tie0__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_ShrImm32 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv4i32, Convert__Reg1_2__Tie0__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_ShrImm32 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv1i64, Convert__Reg1_2__Tie0__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_ShrImm64 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv2i64, Convert__Reg1_2__Tie0__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_ShrImm64 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv8i8, Convert__Reg1_2__Tie0__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_ShrImm8 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv16i8, Convert__Reg1_2__Tie0__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_ShrImm8 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv4i16, Convert__Reg1_2__Tie0__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_ShrImm16 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv8i16, Convert__Reg1_2__Tie0__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv2i32, Convert__Reg1_2__Tie0__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_ShrImm32 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv4i32, Convert__Reg1_2__Tie0__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv1i64, Convert__Reg1_2__Tie0__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR, MCK_ShrImm64 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv2i64, Convert__Reg1_2__Tie0__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR, MCK_ShrImm64 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv8i8, Convert__Reg1_2__Tie0__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_ShrImm8 }, },
  { 2378 /* vrsra */, ARM::VRSRAsv16i8, Convert__Reg1_2__Tie0__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv4i16, Convert__Reg1_2__Tie0__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_ShrImm16 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv8i16, Convert__Reg1_2__Tie0__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv2i32, Convert__Reg1_2__Tie0__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_ShrImm32 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv4i32, Convert__Reg1_2__Tie0__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv1i64, Convert__Reg1_2__Tie0__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR, MCK_ShrImm64 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv2i64, Convert__Reg1_2__Tie0__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR, MCK_ShrImm64 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv8i8, Convert__Reg1_2__Tie0__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_ShrImm8 }, },
  { 2378 /* vrsra */, ARM::VRSRAuv16i8, Convert__Reg1_2__Tie0__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2384 /* vrsubhn */, ARM::VRSUBHNv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_QPR, MCK_QPR }, },
  { 2384 /* vrsubhn */, ARM::VRSUBHNv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_QPR, MCK_QPR }, },
  { 2384 /* vrsubhn */, ARM::VRSUBHNv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_QPR, MCK_QPR }, },
  { 2392 /* vseleq */, ARM::VSELEQS, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 2392 /* vseleq */, ARM::VSELEQD, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2399 /* vselge */, ARM::VSELGES, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 2399 /* vselge */, ARM::VSELGED, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2406 /* vselgt */, ARM::VSELGTS, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 2406 /* vselgt */, ARM::VSELGTD, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2413 /* vselvs */, ARM::VSELVSS, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8, { MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 2413 /* vselvs */, ARM::VSELVSD, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasFPARMv8|Feature_HasDPVFP, { MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLsv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLuv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLiv4i16, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLiv8i16, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLiv2i32, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLiv4i32, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLiv1i64, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLiv2i64, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_QPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLsv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLsv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLiv8i8, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLiv16i8, Convert__Reg1_2__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLsv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLsv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLsv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLuv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLuv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLuv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLuv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLuv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLiv1i64, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLiv16i8, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLsv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLuv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLiv4i16, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLiv8i16, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLsv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLuv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLiv2i32, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLiv4i32, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLsv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLsv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLuv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLuv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLiv2i64, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2420 /* vshl */, ARM::VSHLsv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLsv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLuv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2420 /* vshl */, ARM::VSHLuv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2420 /* vshl */, ARM::VSHLiv8i8, Convert__Reg1_2__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2425 /* vshll */, ARM::VSHLLsv4i32, Convert__Reg1_2__Reg1_3__Imm1_151_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_Imm1_15 }, },
  { 2425 /* vshll */, ARM::VSHLLi16, Convert__Reg1_2__Reg1_3__Imm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_DPR, MCK_Imm16 }, },
  { 2425 /* vshll */, ARM::VSHLLi32, Convert__Reg1_2__Reg1_3__Imm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_DPR, MCK_Imm32 }, },
  { 2425 /* vshll */, ARM::VSHLLsv8i16, Convert__Reg1_2__Reg1_3__Imm1_71_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_DPR, MCK_Imm1_7 }, },
  { 2425 /* vshll */, ARM::VSHLLi8, Convert__Reg1_2__Reg1_3__Imm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_DPR, MCK_Imm8 }, },
  { 2425 /* vshll */, ARM::VSHLLsv2i64, Convert__Reg1_2__Reg1_3__Imm1_311_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_Imm1_31 }, },
  { 2425 /* vshll */, ARM::VSHLLuv4i32, Convert__Reg1_2__Reg1_3__Imm1_151_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR, MCK_Imm1_15 }, },
  { 2425 /* vshll */, ARM::VSHLLuv2i64, Convert__Reg1_2__Reg1_3__Imm1_311_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR, MCK_Imm1_31 }, },
  { 2425 /* vshll */, ARM::VSHLLuv8i16, Convert__Reg1_2__Reg1_3__Imm1_71_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_DPR, MCK_Imm1_7 }, },
  { 2431 /* vshr */, ARM::VSHRsv4i16, Convert__Reg1_2__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_ShrImm16 }, },
  { 2431 /* vshr */, ARM::VSHRsv8i16, Convert__Reg1_2__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_ShrImm16 }, },
  { 2431 /* vshr */, ARM::VSHRsv2i32, Convert__Reg1_2__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_ShrImm32 }, },
  { 2431 /* vshr */, ARM::VSHRsv4i32, Convert__Reg1_2__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_ShrImm32 }, },
  { 2431 /* vshr */, ARM::VSHRsv1i64, Convert__Reg1_2__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_ShrImm64 }, },
  { 2431 /* vshr */, ARM::VSHRsv2i64, Convert__Reg1_2__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_ShrImm64 }, },
  { 2431 /* vshr */, ARM::VSHRsv8i8, Convert__Reg1_2__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_ShrImm8 }, },
  { 2431 /* vshr */, ARM::VSHRsv16i8, Convert__Reg1_2__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_ShrImm8 }, },
  { 2431 /* vshr */, ARM::VSHRuv4i16, Convert__Reg1_2__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_ShrImm16 }, },
  { 2431 /* vshr */, ARM::VSHRuv8i16, Convert__Reg1_2__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_ShrImm16 }, },
  { 2431 /* vshr */, ARM::VSHRuv2i32, Convert__Reg1_2__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_ShrImm32 }, },
  { 2431 /* vshr */, ARM::VSHRuv4i32, Convert__Reg1_2__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_ShrImm32 }, },
  { 2431 /* vshr */, ARM::VSHRuv1i64, Convert__Reg1_2__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_ShrImm64 }, },
  { 2431 /* vshr */, ARM::VSHRuv2i64, Convert__Reg1_2__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_ShrImm64 }, },
  { 2431 /* vshr */, ARM::VSHRuv8i8, Convert__Reg1_2__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_ShrImm8 }, },
  { 2431 /* vshr */, ARM::VSHRuv16i8, Convert__Reg1_2__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_ShrImm8 }, },
  { 2431 /* vshr */, ARM::VSHRsv4i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_ShrImm16 }, },
  { 2431 /* vshr */, ARM::VSHRsv8i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2431 /* vshr */, ARM::VSHRsv2i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_ShrImm32 }, },
  { 2431 /* vshr */, ARM::VSHRsv4i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2431 /* vshr */, ARM::VSHRsv1i64, Convert__Reg1_2__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR, MCK_ShrImm64 }, },
  { 2431 /* vshr */, ARM::VSHRsv2i64, Convert__Reg1_2__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR, MCK_ShrImm64 }, },
  { 2431 /* vshr */, ARM::VSHRsv8i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_ShrImm8 }, },
  { 2431 /* vshr */, ARM::VSHRsv16i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2431 /* vshr */, ARM::VSHRuv4i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_ShrImm16 }, },
  { 2431 /* vshr */, ARM::VSHRuv8i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2431 /* vshr */, ARM::VSHRuv2i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_ShrImm32 }, },
  { 2431 /* vshr */, ARM::VSHRuv4i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2431 /* vshr */, ARM::VSHRuv1i64, Convert__Reg1_2__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR, MCK_ShrImm64 }, },
  { 2431 /* vshr */, ARM::VSHRuv2i64, Convert__Reg1_2__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR, MCK_ShrImm64 }, },
  { 2431 /* vshr */, ARM::VSHRuv8i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_ShrImm8 }, },
  { 2431 /* vshr */, ARM::VSHRuv16i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2436 /* vshrn */, ARM::VSHRNv8i8, Convert__Reg1_2__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2436 /* vshrn */, ARM::VSHRNv4i16, Convert__Reg1_2__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2436 /* vshrn */, ARM::VSHRNv2i32, Convert__Reg1_2__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2442 /* vsli */, ARM::VSLIv4i16, Convert__Reg1_2__Tie0__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv8i16, Convert__Reg1_2__Tie0__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv2i32, Convert__Reg1_2__Tie0__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv4i32, Convert__Reg1_2__Tie0__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv1i64, Convert__Reg1_2__Tie0__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv2i64, Convert__Reg1_2__Tie0__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv8i8, Convert__Reg1_2__Tie0__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv16i8, Convert__Reg1_2__Tie0__Reg1_2__Imm1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv4i16, Convert__Reg1_2__Tie0__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv8i16, Convert__Reg1_2__Tie0__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv2i32, Convert__Reg1_2__Tie0__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv4i32, Convert__Reg1_2__Tie0__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv1i64, Convert__Reg1_2__Tie0__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv2i64, Convert__Reg1_2__Tie0__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv8i8, Convert__Reg1_2__Tie0__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR, MCK_Imm }, },
  { 2442 /* vsli */, ARM::VSLIv16i8, Convert__Reg1_2__Tie0__Reg1_3__Imm1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR, MCK_Imm }, },
  { 2447 /* vsqrt */, ARM::VSQRTS, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_SPR, MCK_SPR }, },
  { 2447 /* vsqrt */, ARM::VSQRTD, Convert__Reg1_1__Reg1_2__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK_DPR, MCK_DPR }, },
  { 2447 /* vsqrt */, ARM::VSQRTS, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2447 /* vsqrt */, ARM::VSQRTD, Convert__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2453 /* vsra */, ARM::VSRAsv4i16, Convert__Reg1_2__Tie0__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_ShrImm16 }, },
  { 2453 /* vsra */, ARM::VSRAsv8i16, Convert__Reg1_2__Tie0__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_ShrImm16 }, },
  { 2453 /* vsra */, ARM::VSRAsv2i32, Convert__Reg1_2__Tie0__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_ShrImm32 }, },
  { 2453 /* vsra */, ARM::VSRAsv4i32, Convert__Reg1_2__Tie0__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_ShrImm32 }, },
  { 2453 /* vsra */, ARM::VSRAsv1i64, Convert__Reg1_2__Tie0__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_ShrImm64 }, },
  { 2453 /* vsra */, ARM::VSRAsv2i64, Convert__Reg1_2__Tie0__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_ShrImm64 }, },
  { 2453 /* vsra */, ARM::VSRAsv8i8, Convert__Reg1_2__Tie0__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_ShrImm8 }, },
  { 2453 /* vsra */, ARM::VSRAsv16i8, Convert__Reg1_2__Tie0__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_ShrImm8 }, },
  { 2453 /* vsra */, ARM::VSRAuv4i16, Convert__Reg1_2__Tie0__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_ShrImm16 }, },
  { 2453 /* vsra */, ARM::VSRAuv8i16, Convert__Reg1_2__Tie0__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_ShrImm16 }, },
  { 2453 /* vsra */, ARM::VSRAuv2i32, Convert__Reg1_2__Tie0__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_ShrImm32 }, },
  { 2453 /* vsra */, ARM::VSRAuv4i32, Convert__Reg1_2__Tie0__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_ShrImm32 }, },
  { 2453 /* vsra */, ARM::VSRAuv1i64, Convert__Reg1_2__Tie0__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_ShrImm64 }, },
  { 2453 /* vsra */, ARM::VSRAuv2i64, Convert__Reg1_2__Tie0__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_ShrImm64 }, },
  { 2453 /* vsra */, ARM::VSRAuv8i8, Convert__Reg1_2__Tie0__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_ShrImm8 }, },
  { 2453 /* vsra */, ARM::VSRAuv16i8, Convert__Reg1_2__Tie0__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_ShrImm8 }, },
  { 2453 /* vsra */, ARM::VSRAsv4i16, Convert__Reg1_2__Tie0__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_DPR, MCK_DPR, MCK_ShrImm16 }, },
  { 2453 /* vsra */, ARM::VSRAsv8i16, Convert__Reg1_2__Tie0__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2453 /* vsra */, ARM::VSRAsv2i32, Convert__Reg1_2__Tie0__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_DPR, MCK_DPR, MCK_ShrImm32 }, },
  { 2453 /* vsra */, ARM::VSRAsv4i32, Convert__Reg1_2__Tie0__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2453 /* vsra */, ARM::VSRAsv1i64, Convert__Reg1_2__Tie0__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_DPR, MCK_DPR, MCK_ShrImm64 }, },
  { 2453 /* vsra */, ARM::VSRAsv2i64, Convert__Reg1_2__Tie0__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s64, MCK_QPR, MCK_QPR, MCK_ShrImm64 }, },
  { 2453 /* vsra */, ARM::VSRAsv8i8, Convert__Reg1_2__Tie0__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_DPR, MCK_DPR, MCK_ShrImm8 }, },
  { 2453 /* vsra */, ARM::VSRAsv16i8, Convert__Reg1_2__Tie0__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2453 /* vsra */, ARM::VSRAuv4i16, Convert__Reg1_2__Tie0__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_DPR, MCK_DPR, MCK_ShrImm16 }, },
  { 2453 /* vsra */, ARM::VSRAuv8i16, Convert__Reg1_2__Tie0__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2453 /* vsra */, ARM::VSRAuv2i32, Convert__Reg1_2__Tie0__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_DPR, MCK_DPR, MCK_ShrImm32 }, },
  { 2453 /* vsra */, ARM::VSRAuv4i32, Convert__Reg1_2__Tie0__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2453 /* vsra */, ARM::VSRAuv1i64, Convert__Reg1_2__Tie0__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_DPR, MCK_DPR, MCK_ShrImm64 }, },
  { 2453 /* vsra */, ARM::VSRAuv2i64, Convert__Reg1_2__Tie0__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u64, MCK_QPR, MCK_QPR, MCK_ShrImm64 }, },
  { 2453 /* vsra */, ARM::VSRAuv8i8, Convert__Reg1_2__Tie0__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_DPR, MCK_DPR, MCK_ShrImm8 }, },
  { 2453 /* vsra */, ARM::VSRAuv16i8, Convert__Reg1_2__Tie0__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2458 /* vsri */, ARM::VSRIv4i16, Convert__Reg1_2__Tie0__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_ShrImm16 }, },
  { 2458 /* vsri */, ARM::VSRIv8i16, Convert__Reg1_2__Tie0__Reg1_2__ShrImm161_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_ShrImm16 }, },
  { 2458 /* vsri */, ARM::VSRIv2i32, Convert__Reg1_2__Tie0__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_ShrImm32 }, },
  { 2458 /* vsri */, ARM::VSRIv4i32, Convert__Reg1_2__Tie0__Reg1_2__ShrImm321_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_ShrImm32 }, },
  { 2458 /* vsri */, ARM::VSRIv1i64, Convert__Reg1_2__Tie0__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_ShrImm64 }, },
  { 2458 /* vsri */, ARM::VSRIv2i64, Convert__Reg1_2__Tie0__Reg1_2__ShrImm641_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_ShrImm64 }, },
  { 2458 /* vsri */, ARM::VSRIv8i8, Convert__Reg1_2__Tie0__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_ShrImm8 }, },
  { 2458 /* vsri */, ARM::VSRIv16i8, Convert__Reg1_2__Tie0__Reg1_2__ShrImm81_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_ShrImm8 }, },
  { 2458 /* vsri */, ARM::VSRIv4i16, Convert__Reg1_2__Tie0__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR, MCK_ShrImm16 }, },
  { 2458 /* vsri */, ARM::VSRIv8i16, Convert__Reg1_2__Tie0__Reg1_3__ShrImm161_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR, MCK_ShrImm16 }, },
  { 2458 /* vsri */, ARM::VSRIv2i32, Convert__Reg1_2__Tie0__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR, MCK_ShrImm32 }, },
  { 2458 /* vsri */, ARM::VSRIv4i32, Convert__Reg1_2__Tie0__Reg1_3__ShrImm321_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_ShrImm32 }, },
  { 2458 /* vsri */, ARM::VSRIv1i64, Convert__Reg1_2__Tie0__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR, MCK_ShrImm64 }, },
  { 2458 /* vsri */, ARM::VSRIv2i64, Convert__Reg1_2__Tie0__Reg1_3__ShrImm641_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR, MCK_ShrImm64 }, },
  { 2458 /* vsri */, ARM::VSRIv8i8, Convert__Reg1_2__Tie0__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR, MCK_ShrImm8 }, },
  { 2458 /* vsri */, ARM::VSRIv16i8, Convert__Reg1_2__Tie0__Reg1_3__ShrImm81_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR, MCK_ShrImm8 }, },
  { 2463 /* vst1 */, ARM::VST1q16, Convert__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1d16Q, Convert__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1d16, Convert__AlignedMemory2_3__VecListOneD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneD, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1LNdAsm_16, Convert__VecListOneDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneDHWordIndexed, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1d16T, Convert__AlignedMemory2_3__VecListThreeD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1q32, Convert__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1d32Q, Convert__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1d32, Convert__AlignedMemory2_3__VecListOneD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneD, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1LNdAsm_32, Convert__VecListOneDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneDWordIndexed, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1d32T, Convert__AlignedMemory2_3__VecListThreeD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1q64, Convert__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1d64Q, Convert__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1d64, Convert__AlignedMemory2_3__VecListOneD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListOneD, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1d64T, Convert__AlignedMemory2_3__VecListThreeD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1q8, Convert__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1d8Q, Convert__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1d8, Convert__AlignedMemory2_3__VecListOneD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneD, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1LNdAsm_8, Convert__VecListOneDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneDByteIndexed, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1d8T, Convert__AlignedMemory2_3__VecListThreeD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1q16wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1q16wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1d16Qwb_fixed, Convert__imm_0__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1d16Qwb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1d16wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListOneD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1d16wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListOneD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1LNdWB_fixed_Asm_16, Convert__VecListOneDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneDHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1LNdWB_register_Asm_16, Convert__VecListOneDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListOneDHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1d16Twb_fixed, Convert__imm_0__AlignedMemory2_3__VecListThreeD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1d16Twb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListThreeD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1q32wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1q32wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1d32Qwb_fixed, Convert__imm_0__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1d32Qwb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1d32wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListOneD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1d32wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListOneD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1LNdWB_fixed_Asm_32, Convert__VecListOneDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneDWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1LNdWB_register_Asm_32, Convert__VecListOneDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListOneDWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1d32Twb_fixed, Convert__imm_0__AlignedMemory2_3__VecListThreeD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1d32Twb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListThreeD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1q64wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1q64wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1d64Qwb_fixed, Convert__imm_0__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1d64Qwb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1d64wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListOneD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListOneD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1d64wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListOneD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListOneD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1d64Twb_fixed, Convert__imm_0__AlignedMemory2_3__VecListThreeD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1d64Twb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListThreeD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1q8wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1q8wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1d8Qwb_fixed, Convert__imm_0__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1d8Qwb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1d8wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListOneD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1d8wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListOneD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1LNdWB_fixed_Asm_8, Convert__VecListOneDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneDByteIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1LNdWB_register_Asm_8, Convert__VecListOneDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListOneDByteIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1d8Twb_fixed, Convert__imm_0__AlignedMemory2_3__VecListThreeD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2463 /* vst1 */, ARM::VST1d8Twb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListThreeD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2463 /* vst1 */, ARM::VST1LNd16, Convert__AlignedMemory2_8__Reg1_3__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK__91_, MCK_Imm, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1LNd8, Convert__AlignedMemory2_8__Reg1_3__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK__91_, MCK_Imm, MCK__93_, MCK__125_, MCK_AlignedMemory }, },
  { 2463 /* vst1 */, ARM::VST1LNd16_UPD, Convert__imm_0__AlignedMemory2_8__Imm1_9__Reg1_3__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK__91_, MCK_Imm, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2463 /* vst1 */, ARM::VST1LNd32, Convert__Reg1_8__Imm1_9__Reg1_3__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK__91_, MCK_Imm, MCK__93_, MCK__125_, MCK_GPR, MCK_Imm }, },
  { 2463 /* vst1 */, ARM::VST1LNd8_UPD, Convert__imm_0__AlignedMemory2_8__Imm1_9__Reg1_3__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK__91_, MCK_Imm, MCK__93_, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2463 /* vst1 */, ARM::VST1LNd32_UPD, Convert__imm_0__Reg1_8__Imm1_9__Imm1_10__Reg1_3__Imm1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK__91_, MCK_Imm, MCK__93_, MCK__125_, MCK_GPR, MCK_Imm, MCK_Imm }, },
  { 2468 /* vst2 */, ARM::VST2d16, Convert__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2b16, Convert__AlignedMemory2_3__VecListDPairSpaced1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairSpaced, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2q16, Convert__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2LNdAsm_16, Convert__VecListTwoDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListTwoDHWordIndexed, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2LNqAsm_16, Convert__VecListTwoQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListTwoQHWordIndexed, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2d32, Convert__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2b32, Convert__AlignedMemory2_3__VecListDPairSpaced1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairSpaced, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2q32, Convert__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2LNdAsm_32, Convert__VecListTwoDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListTwoDWordIndexed, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2LNqAsm_32, Convert__VecListTwoQWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListTwoQWordIndexed, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2d8, Convert__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPair, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2b8, Convert__AlignedMemory2_3__VecListDPairSpaced1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairSpaced, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2q8, Convert__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2LNdAsm_8, Convert__VecListTwoDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListTwoDByteIndexed, MCK_AlignedMemory }, },
  { 2468 /* vst2 */, ARM::VST2d16wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2d16wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 2468 /* vst2 */, ARM::VST2b16wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListDPairSpaced1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairSpaced, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2b16wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPairSpaced1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListDPairSpaced, MCK_AlignedMemory, MCK_rGPR }, },
  { 2468 /* vst2 */, ARM::VST2q16wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2q16wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2468 /* vst2 */, ARM::VST2LNdWB_fixed_Asm_16, Convert__VecListTwoDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListTwoDHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2LNdWB_register_Asm_16, Convert__VecListTwoDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListTwoDHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2468 /* vst2 */, ARM::VST2LNqWB_fixed_Asm_16, Convert__VecListTwoQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListTwoQHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2LNqWB_register_Asm_16, Convert__VecListTwoQHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListTwoQHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2468 /* vst2 */, ARM::VST2d32wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2d32wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 2468 /* vst2 */, ARM::VST2b32wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListDPairSpaced1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairSpaced, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2b32wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPairSpaced1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListDPairSpaced, MCK_AlignedMemory, MCK_rGPR }, },
  { 2468 /* vst2 */, ARM::VST2q32wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2q32wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2468 /* vst2 */, ARM::VST2LNdWB_fixed_Asm_32, Convert__VecListTwoDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListTwoDWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2LNdWB_register_Asm_32, Convert__VecListTwoDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListTwoDWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2468 /* vst2 */, ARM::VST2LNqWB_fixed_Asm_32, Convert__VecListTwoQWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListTwoQWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2LNqWB_register_Asm_32, Convert__VecListTwoQWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListTwoQWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2468 /* vst2 */, ARM::VST2d8wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPair, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2d8wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPair1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPair, MCK_AlignedMemory, MCK_rGPR }, },
  { 2468 /* vst2 */, ARM::VST2b8wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListDPairSpaced1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairSpaced, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2b8wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListDPairSpaced1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListDPairSpaced, MCK_AlignedMemory, MCK_rGPR }, },
  { 2468 /* vst2 */, ARM::VST2q8wb_fixed, Convert__imm_0__AlignedMemory2_3__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2q8wb_register, Convert__imm_0__AlignedMemory2_3__Reg1_4__VecListFourD1_2__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2468 /* vst2 */, ARM::VST2LNdWB_fixed_Asm_8, Convert__VecListTwoDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListTwoDByteIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2468 /* vst2 */, ARM::VST2LNdWB_register_Asm_8, Convert__VecListTwoDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListTwoDByteIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2473 /* vst3 */, ARM::VST3dAsm_16, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3LNdAsm_16, Convert__VecListThreeDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeDHWordIndexed, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3qAsm_16, Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQ, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3LNqAsm_16, Convert__VecListThreeQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQHWordIndexed, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3dAsm_32, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3LNdAsm_32, Convert__VecListThreeDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeDWordIndexed, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3qAsm_32, Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQ, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3LNqAsm_32, Convert__VecListThreeQWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQWordIndexed, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3dAsm_8, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeD, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3LNdAsm_8, Convert__VecListThreeDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeDByteIndexed, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3qAsm_8, Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeQ, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3dWB_fixed_Asm_16, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2473 /* vst3 */, ARM::VST3dWB_register_Asm_16, Convert__VecListThreeD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2473 /* vst3 */, ARM::VST3LNdWB_fixed_Asm_16, Convert__VecListThreeDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeDHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2473 /* vst3 */, ARM::VST3LNdWB_register_Asm_16, Convert__VecListThreeDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeDHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2473 /* vst3 */, ARM::VST3qWB_fixed_Asm_16, Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQ, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2473 /* vst3 */, ARM::VST3qWB_register_Asm_16, Convert__VecListThreeQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQ, MCK_AlignedMemory, MCK_rGPR }, },
  { 2473 /* vst3 */, ARM::VST3LNqWB_fixed_Asm_16, Convert__VecListThreeQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2473 /* vst3 */, ARM::VST3LNqWB_register_Asm_16, Convert__VecListThreeQHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListThreeQHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2473 /* vst3 */, ARM::VST3dWB_fixed_Asm_32, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2473 /* vst3 */, ARM::VST3dWB_register_Asm_32, Convert__VecListThreeD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2473 /* vst3 */, ARM::VST3LNdWB_fixed_Asm_32, Convert__VecListThreeDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeDWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2473 /* vst3 */, ARM::VST3LNdWB_register_Asm_32, Convert__VecListThreeDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeDWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2473 /* vst3 */, ARM::VST3qWB_fixed_Asm_32, Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQ, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2473 /* vst3 */, ARM::VST3qWB_register_Asm_32, Convert__VecListThreeQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQ, MCK_AlignedMemory, MCK_rGPR }, },
  { 2473 /* vst3 */, ARM::VST3LNqWB_fixed_Asm_32, Convert__VecListThreeQWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2473 /* vst3 */, ARM::VST3LNqWB_register_Asm_32, Convert__VecListThreeQWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListThreeQWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2473 /* vst3 */, ARM::VST3dWB_fixed_Asm_8, Convert__VecListThreeD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2473 /* vst3 */, ARM::VST3dWB_register_Asm_8, Convert__VecListThreeD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2473 /* vst3 */, ARM::VST3LNdWB_fixed_Asm_8, Convert__VecListThreeDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeDByteIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2473 /* vst3 */, ARM::VST3LNdWB_register_Asm_8, Convert__VecListThreeDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeDByteIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2473 /* vst3 */, ARM::VST3qWB_fixed_Asm_8, Convert__VecListThreeQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeQ, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2473 /* vst3 */, ARM::VST3qWB_register_Asm_8, Convert__VecListThreeQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListThreeQ, MCK_AlignedMemory, MCK_rGPR }, },
  { 2473 /* vst3 */, ARM::VST3d16, Convert__AlignedMemory2_7__Reg1_3__Reg1_4__Reg1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3q16, Convert__AlignedMemory2_7__Reg1_3__Reg1_4__Reg1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3d32, Convert__AlignedMemory2_7__Reg1_3__Reg1_4__Reg1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3q32, Convert__AlignedMemory2_7__Reg1_3__Reg1_4__Reg1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3d8, Convert__AlignedMemory2_7__Reg1_3__Reg1_4__Reg1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3q8, Convert__AlignedMemory2_7__Reg1_3__Reg1_4__Reg1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 2473 /* vst3 */, ARM::VST3d16_UPD, Convert__imm_0__AlignedMemory2_7__Imm1_8__Reg1_3__Reg1_4__Reg1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2473 /* vst3 */, ARM::VST3q16_UPD, Convert__imm_0__AlignedMemory2_7__Imm1_8__Reg1_3__Reg1_4__Reg1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2473 /* vst3 */, ARM::VST3d32_UPD, Convert__imm_0__AlignedMemory2_7__Imm1_8__Reg1_3__Reg1_4__Reg1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2473 /* vst3 */, ARM::VST3q32_UPD, Convert__imm_0__AlignedMemory2_7__Imm1_8__Reg1_3__Reg1_4__Reg1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2473 /* vst3 */, ARM::VST3d8_UPD, Convert__imm_0__AlignedMemory2_7__Imm1_8__Reg1_3__Reg1_4__Reg1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2473 /* vst3 */, ARM::VST3q8_UPD, Convert__imm_0__AlignedMemory2_7__Imm1_8__Reg1_3__Reg1_4__Reg1_5__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2478 /* vst4 */, ARM::VST4dAsm_16, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4LNdAsm_16, Convert__VecListFourDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourDHWordIndexed, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4qAsm_16, Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQ, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4LNqAsm_16, Convert__VecListFourQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQHWordIndexed, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4dAsm_32, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4LNdAsm_32, Convert__VecListFourDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourDWordIndexed, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4qAsm_32, Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQ, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4LNqAsm_32, Convert__VecListFourQWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQWordIndexed, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4dAsm_8, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4LNdAsm_8, Convert__VecListFourDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourDByteIndexed, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4qAsm_8, Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourQ, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4dWB_fixed_Asm_16, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2478 /* vst4 */, ARM::VST4dWB_register_Asm_16, Convert__VecListFourD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2478 /* vst4 */, ARM::VST4LNdWB_fixed_Asm_16, Convert__VecListFourDHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourDHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2478 /* vst4 */, ARM::VST4LNdWB_register_Asm_16, Convert__VecListFourDHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourDHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2478 /* vst4 */, ARM::VST4qWB_fixed_Asm_16, Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQ, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2478 /* vst4 */, ARM::VST4qWB_register_Asm_16, Convert__VecListFourQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQ, MCK_AlignedMemory, MCK_rGPR }, },
  { 2478 /* vst4 */, ARM::VST4LNqWB_fixed_Asm_16, Convert__VecListFourQHWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQHWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2478 /* vst4 */, ARM::VST4LNqWB_register_Asm_16, Convert__VecListFourQHWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_VecListFourQHWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2478 /* vst4 */, ARM::VST4dWB_fixed_Asm_32, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2478 /* vst4 */, ARM::VST4dWB_register_Asm_32, Convert__VecListFourD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2478 /* vst4 */, ARM::VST4LNdWB_fixed_Asm_32, Convert__VecListFourDWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourDWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2478 /* vst4 */, ARM::VST4LNdWB_register_Asm_32, Convert__VecListFourDWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourDWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2478 /* vst4 */, ARM::VST4qWB_fixed_Asm_32, Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQ, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2478 /* vst4 */, ARM::VST4qWB_register_Asm_32, Convert__VecListFourQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQ, MCK_AlignedMemory, MCK_rGPR }, },
  { 2478 /* vst4 */, ARM::VST4LNqWB_fixed_Asm_32, Convert__VecListFourQWordIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQWordIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2478 /* vst4 */, ARM::VST4LNqWB_register_Asm_32, Convert__VecListFourQWordIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_VecListFourQWordIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2478 /* vst4 */, ARM::VST4dWB_fixed_Asm_8, Convert__VecListFourD1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2478 /* vst4 */, ARM::VST4dWB_register_Asm_8, Convert__VecListFourD1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourD, MCK_AlignedMemory, MCK_rGPR }, },
  { 2478 /* vst4 */, ARM::VST4LNdWB_fixed_Asm_8, Convert__VecListFourDByteIndexed2_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourDByteIndexed, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2478 /* vst4 */, ARM::VST4LNdWB_register_Asm_8, Convert__VecListFourDByteIndexed2_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourDByteIndexed, MCK_AlignedMemory, MCK_rGPR }, },
  { 2478 /* vst4 */, ARM::VST4qWB_fixed_Asm_8, Convert__VecListFourQ1_2__AlignedMemory2_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourQ, MCK_AlignedMemory, MCK__EXCLAIM_ }, },
  { 2478 /* vst4 */, ARM::VST4qWB_register_Asm_8, Convert__VecListFourQ1_2__AlignedMemory2_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_VecListFourQ, MCK_AlignedMemory, MCK_rGPR }, },
  { 2478 /* vst4 */, ARM::VST4d16, Convert__AlignedMemory2_8__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4q16, Convert__AlignedMemory2_8__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4d32, Convert__AlignedMemory2_8__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4q32, Convert__AlignedMemory2_8__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4d8, Convert__AlignedMemory2_8__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4q8, Convert__AlignedMemory2_8__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory }, },
  { 2478 /* vst4 */, ARM::VST4d16_UPD, Convert__imm_0__AlignedMemory2_8__Imm1_9__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2478 /* vst4 */, ARM::VST4q16_UPD, Convert__imm_0__AlignedMemory2_8__Imm1_9__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2478 /* vst4 */, ARM::VST4d32_UPD, Convert__imm_0__AlignedMemory2_8__Imm1_9__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2478 /* vst4 */, ARM::VST4q32_UPD, Convert__imm_0__AlignedMemory2_8__Imm1_9__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2478 /* vst4 */, ARM::VST4d8_UPD, Convert__imm_0__AlignedMemory2_8__Imm1_9__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2478 /* vst4 */, ARM::VST4q8_UPD, Convert__imm_0__AlignedMemory2_8__Imm1_9__Reg1_3__Reg1_4__Reg1_5__Reg1_6__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK__123_, MCK_DPR, MCK_DPR, MCK_DPR, MCK_DPR, MCK__125_, MCK_AlignedMemory, MCK_Imm }, },
  { 2483 /* vstmdb */, ARM::VSTMDDB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__DPRRegList1_3, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_DPRRegList }, },
  { 2483 /* vstmdb */, ARM::VSTMSDB_UPD, Convert__Reg1_1__Tie0__CondCode2_0__SPRRegList1_3, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_SPRRegList }, },
  { 2490 /* vstmia */, ARM::VSTMDIA, Convert__Reg1_1__CondCode2_0__DPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_DPRRegList }, },
  { 2490 /* vstmia */, ARM::VSTMSIA, Convert__Reg1_1__CondCode2_0__SPRRegList1_2, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK_SPRRegList }, },
  { 2490 /* vstmia */, ARM::VSTMDIA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__DPRRegList1_3, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_DPRRegList }, },
  { 2490 /* vstmia */, ARM::VSTMSIA_UPD, Convert__Reg1_1__Tie0__CondCode2_0__SPRRegList1_3, Feature_HasVFP2, { MCK_CondCode, MCK_GPR, MCK__EXCLAIM_, MCK_SPRRegList }, },
  { 2497 /* vstr */, ARM::VSTRS, Convert__Reg1_1__AddrMode52_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_SPR, MCK_AddrMode5 }, },
  { 2497 /* vstr */, ARM::VSTRD, Convert__Reg1_1__AddrMode52_2__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK_DPR, MCK_AddrMode5 }, },
  { 2497 /* vstr */, ARM::VSTRS, Convert__Reg1_2__AddrMode52_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_32, MCK_SPR, MCK_AddrMode5 }, },
  { 2497 /* vstr */, ARM::VSTRD, Convert__Reg1_2__AddrMode52_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_AddrMode5 }, },
  { 2502 /* vsub */, ARM::VSUBS, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR }, },
  { 2502 /* vsub */, ARM::VSUBfd, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR }, },
  { 2502 /* vsub */, ARM::VSUBfq, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR }, },
  { 2502 /* vsub */, ARM::VSUBD, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR }, },
  { 2502 /* vsub */, ARM::VSUBv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR }, },
  { 2502 /* vsub */, ARM::VSUBv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR }, },
  { 2502 /* vsub */, ARM::VSUBv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR }, },
  { 2502 /* vsub */, ARM::VSUBv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR }, },
  { 2502 /* vsub */, ARM::VSUBv1i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_DPR }, },
  { 2502 /* vsub */, ARM::VSUBv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_QPR, MCK_QPR }, },
  { 2502 /* vsub */, ARM::VSUBv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR }, },
  { 2502 /* vsub */, ARM::VSUBv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_QPR }, },
  { 2502 /* vsub */, ARM::VSUBS, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2, { MCK_CondCode, MCK__DOT_f32, MCK_SPR, MCK_SPR, MCK_SPR }, },
  { 2502 /* vsub */, ARM::VSUBfd, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2502 /* vsub */, ARM::VSUBfq, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_f32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2502 /* vsub */, ARM::VSUBD, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasVFP2|Feature_HasDPVFP, { MCK_CondCode, MCK__DOT_f64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2502 /* vsub */, ARM::VSUBv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2502 /* vsub */, ARM::VSUBv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2502 /* vsub */, ARM::VSUBv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2502 /* vsub */, ARM::VSUBv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2502 /* vsub */, ARM::VSUBv1i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2502 /* vsub */, ARM::VSUBv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2502 /* vsub */, ARM::VSUBv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2502 /* vsub */, ARM::VSUBv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2507 /* vsubhn */, ARM::VSUBHNv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i16, MCK_DPR, MCK_QPR, MCK_QPR }, },
  { 2507 /* vsubhn */, ARM::VSUBHNv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i32, MCK_DPR, MCK_QPR, MCK_QPR }, },
  { 2507 /* vsubhn */, ARM::VSUBHNv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_i64, MCK_DPR, MCK_QPR, MCK_QPR }, },
  { 2514 /* vsubl */, ARM::VSUBLsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2514 /* vsubl */, ARM::VSUBLsv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2514 /* vsubl */, ARM::VSUBLsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2514 /* vsubl */, ARM::VSUBLuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2514 /* vsubl */, ARM::VSUBLuv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2514 /* vsubl */, ARM::VSUBLuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_DPR, MCK_DPR }, },
  { 2520 /* vsubw */, ARM::VSUBWsv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_DPR }, },
  { 2520 /* vsubw */, ARM::VSUBWsv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_DPR }, },
  { 2520 /* vsubw */, ARM::VSUBWsv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_DPR }, },
  { 2520 /* vsubw */, ARM::VSUBWuv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_DPR }, },
  { 2520 /* vsubw */, ARM::VSUBWuv2i64, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_DPR }, },
  { 2520 /* vsubw */, ARM::VSUBWuv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_DPR }, },
  { 2520 /* vsubw */, ARM::VSUBWsv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s16, MCK_QPR, MCK_QPR, MCK_DPR }, },
  { 2520 /* vsubw */, ARM::VSUBWsv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s32, MCK_QPR, MCK_QPR, MCK_DPR }, },
  { 2520 /* vsubw */, ARM::VSUBWsv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_s8, MCK_QPR, MCK_QPR, MCK_DPR }, },
  { 2520 /* vsubw */, ARM::VSUBWuv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u16, MCK_QPR, MCK_QPR, MCK_DPR }, },
  { 2520 /* vsubw */, ARM::VSUBWuv2i64, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u32, MCK_QPR, MCK_QPR, MCK_DPR }, },
  { 2520 /* vsubw */, ARM::VSUBWuv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_u8, MCK_QPR, MCK_QPR, MCK_DPR }, },
  { 2526 /* vswp */, ARM::VSWPd, Convert__Reg1_1__Reg1_2__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_DPR, MCK_DPR }, },
  { 2526 /* vswp */, ARM::VSWPq, Convert__Reg1_1__Reg1_2__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK_QPR, MCK_QPR }, },
  { 2526 /* vswp */, ARM::VSWPd, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR }, },
  { 2526 /* vswp */, ARM::VSWPq, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR }, },
  { 2526 /* vswp */, ARM::VSWPd, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR }, },
  { 2526 /* vswp */, ARM::VSWPq, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 2526 /* vswp */, ARM::VSWPd, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_DPR, MCK_DPR }, },
  { 2526 /* vswp */, ARM::VSWPq, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_64, MCK_QPR, MCK_QPR }, },
  { 2526 /* vswp */, ARM::VSWPd, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 2526 /* vswp */, ARM::VSWPq, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 2531 /* vtbl */, ARM::VTBL2, Convert__Reg1_2__VecListDPair1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_VecListDPair, MCK_DPR }, },
  { 2531 /* vtbl */, ARM::VTBL4, Convert__Reg1_2__VecListFourD1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_VecListFourD, MCK_DPR }, },
  { 2531 /* vtbl */, ARM::VTBL1, Convert__Reg1_2__VecListOneD1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_VecListOneD, MCK_DPR }, },
  { 2531 /* vtbl */, ARM::VTBL3, Convert__Reg1_2__VecListThreeD1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_VecListThreeD, MCK_DPR }, },
  { 2536 /* vtbx */, ARM::VTBX2, Convert__Reg1_2__Tie0__VecListDPair1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_VecListDPair, MCK_DPR }, },
  { 2536 /* vtbx */, ARM::VTBX4, Convert__Reg1_2__Tie0__VecListFourD1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_VecListFourD, MCK_DPR }, },
  { 2536 /* vtbx */, ARM::VTBX1, Convert__Reg1_2__Tie0__VecListOneD1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_VecListOneD, MCK_DPR }, },
  { 2536 /* vtbx */, ARM::VTBX3, Convert__Reg1_2__Tie0__VecListThreeD1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_VecListThreeD, MCK_DPR }, },
  { 2541 /* vtrn */, ARM::VTRNd16, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR }, },
  { 2541 /* vtrn */, ARM::VTRNq16, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR }, },
  { 2541 /* vtrn */, ARM::VTRNd32, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR }, },
  { 2541 /* vtrn */, ARM::VTRNq32, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 2541 /* vtrn */, ARM::VTRNd8, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 2541 /* vtrn */, ARM::VTRNq8, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 2546 /* vtst */, ARM::VTSTv4i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR }, },
  { 2546 /* vtst */, ARM::VTSTv8i16, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR }, },
  { 2546 /* vtst */, ARM::VTSTv2i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR }, },
  { 2546 /* vtst */, ARM::VTSTv4i32, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 2546 /* vtst */, ARM::VTSTv8i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 2546 /* vtst */, ARM::VTSTv16i8, Convert__Reg1_2__Reg1_2__Reg1_3__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 2546 /* vtst */, ARM::VTSTv4i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2546 /* vtst */, ARM::VTSTv8i16, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2546 /* vtst */, ARM::VTSTv2i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2546 /* vtst */, ARM::VTSTv4i32, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2546 /* vtst */, ARM::VTSTv8i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR, MCK_DPR }, },
  { 2546 /* vtst */, ARM::VTSTv16i8, Convert__Reg1_2__Reg1_3__Reg1_4__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR, MCK_QPR }, },
  { 2551 /* vuzp */, ARM::VUZPd16, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR }, },
  { 2551 /* vuzp */, ARM::VUZPq16, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR }, },
  { 2551 /* vuzp */, ARM::VTRNd32, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR }, },
  { 2551 /* vuzp */, ARM::VUZPq32, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 2551 /* vuzp */, ARM::VUZPd8, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 2551 /* vuzp */, ARM::VUZPq8, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 2556 /* vzip */, ARM::VZIPd16, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_DPR, MCK_DPR }, },
  { 2556 /* vzip */, ARM::VZIPq16, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_16, MCK_QPR, MCK_QPR }, },
  { 2556 /* vzip */, ARM::VTRNd32, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_DPR, MCK_DPR }, },
  { 2556 /* vzip */, ARM::VZIPq32, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_32, MCK_QPR, MCK_QPR }, },
  { 2556 /* vzip */, ARM::VZIPd8, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_DPR, MCK_DPR }, },
  { 2556 /* vzip */, ARM::VZIPq8, Convert__Reg1_2__Reg1_3__Tie0__Tie1__CondCode2_0, Feature_HasNEON, { MCK_CondCode, MCK__DOT_8, MCK_QPR, MCK_QPR }, },
  { 2561 /* wfe */, ARM::HINT, Convert__imm_2__CondCode2_0, Feature_IsARM|Feature_HasV6T2, { MCK_CondCode }, },
  { 2561 /* wfe */, ARM::tHINT, Convert__imm_2__CondCode2_0, Feature_IsThumb|Feature_HasV6M, { MCK_CondCode }, },
  { 2561 /* wfe */, ARM::t2HINT, Convert__imm_2__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w }, },
  { 2565 /* wfi */, ARM::HINT, Convert__imm_3__CondCode2_0, Feature_IsARM|Feature_HasV6T2, { MCK_CondCode }, },
  { 2565 /* wfi */, ARM::tHINT, Convert__imm_3__CondCode2_0, Feature_IsThumb|Feature_HasV6M, { MCK_CondCode }, },
  { 2565 /* wfi */, ARM::t2HINT, Convert__imm_3__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w }, },
  { 2569 /* yield */, ARM::HINT, Convert__imm_1__CondCode2_0, Feature_IsARM|Feature_HasV6T2, { MCK_CondCode }, },
  { 2569 /* yield */, ARM::tHINT, Convert__imm_1__CondCode2_0, Feature_IsThumb|Feature_HasV6M, { MCK_CondCode }, },
  { 2569 /* yield */, ARM::t2HINT, Convert__imm_1__CondCode2_0, Feature_IsThumb2, { MCK_CondCode, MCK__DOT_w }, },
};

bool ARMAsmParser::
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

unsigned ARMAsmParser::
MatchInstructionImpl(const SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                     MCInst &Inst,
unsigned &ErrorInfo, bool matchingInlineAsm, unsigned VariantID) {
  // Eliminate obvious mismatches.
  if (Operands.size() > 19) {
    ErrorInfo = 19;
    return Match_InvalidOperand;
  }

  // Get the current feature set.
  unsigned AvailableFeatures = getAvailableFeatures();

  // Get the instruction mnemonic, which is the first token.
  StringRef Mnemonic = ((ARMOperand*)Operands[0])->getToken();

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
    for (unsigned i = 0; i != 18; ++i) {
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

    std::string Info;
    if (MII.get(Inst.getOpcode()).getDeprecatedInfo(Inst, STI, Info)) {
      SMLoc Loc = ((ARMOperand*)Operands[0])->getStartLoc();
      Parser.Warning(Loc, Info, None);
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
    uint16_t Class;
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

static const OperandMatchEntry OperandMatchTable[695] = {
  /* Operand List Mask, Mnemonic, Operand Class, Features */
  { Feature_IsThumb2, 50 /* bfc */, MCK_Bitfield, 4 /* 2 */ },
  { Feature_IsARM|Feature_HasV6T2, 50 /* bfc */, MCK_Bitfield, 4 /* 2 */ },
  { Feature_IsThumb2, 54 /* bfi */, MCK_Bitfield, 8 /* 3 */ },
  { Feature_IsARM|Feature_HasV6T2, 54 /* bfi */, MCK_Bitfield, 8 /* 3 */ },
  { Feature_IsThumb2|Feature_PreV8, 90 /* cdp */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2|Feature_PreV8, 90 /* cdp */, MCK_CoprocReg, 56 /* 3, 4, 5 */ },
  { Feature_PreV8, 90 /* cdp */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 90 /* cdp */, MCK_CoprocReg, 56 /* 3, 4, 5 */ },
  { Feature_PreV8, 94 /* cdp2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 94 /* cdp2 */, MCK_CoprocReg, 28 /* 2, 3, 4 */ },
  { Feature_IsThumb2|Feature_PreV8, 94 /* cdp2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2|Feature_PreV8, 94 /* cdp2 */, MCK_CoprocReg, 56 /* 3, 4, 5 */ },
  { Feature_IsARM, 117 /* cps */, MCK_ProcIFlags, 2 /* 1 */ },
  { Feature_IsThumb, 117 /* cps */, MCK_ProcIFlags, 2 /* 1 */ },
  { Feature_IsThumb2, 117 /* cps */, MCK_ProcIFlags, 4 /* 2 */ },
  { Feature_IsARM, 117 /* cps */, MCK_ProcIFlags, 2 /* 1 */ },
  { Feature_IsThumb2, 117 /* cps */, MCK_ProcIFlags, 2 /* 1 */ },
  { Feature_IsThumb2, 117 /* cps */, MCK_ProcIFlags, 4 /* 2 */ },
  { Feature_IsARM|Feature_HasDB, 188 /* dmb */, MCK_MemBarrierOpt, 1 /* 0 */ },
  { Feature_HasDB, 188 /* dmb */, MCK_MemBarrierOpt, 2 /* 1 */ },
  { Feature_IsARM|Feature_HasDB, 192 /* dsb */, MCK_MemBarrierOpt, 1 /* 0 */ },
  { Feature_HasDB, 192 /* dsb */, MCK_MemBarrierOpt, 2 /* 1 */ },
  { Feature_IsARM|Feature_HasDB, 298 /* isb */, MCK_InstSyncBarrierOpt, 1 /* 0 */ },
  { Feature_HasDB, 298 /* isb */, MCK_InstSyncBarrierOpt, 2 /* 1 */ },
  { Feature_IsARM, 302 /* it */, MCK_ITCondCode, 2 /* 1 */ },
  { Feature_IsThumb2, 302 /* it */, MCK_ITCondCode, 2 /* 1 */ },
  { Feature_IsARM, 346 /* ldc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 346 /* ldc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 346 /* ldc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 346 /* ldc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 346 /* ldc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 346 /* ldc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 346 /* ldc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 346 /* ldc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 346 /* ldc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 346 /* ldc */, MCK_CoprocOption, 16 /* 4 */ },
  { Feature_IsARM, 346 /* ldc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 346 /* ldc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 346 /* ldc */, MCK_CoprocOption, 16 /* 4 */ },
  { Feature_IsThumb2, 346 /* ldc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 346 /* ldc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 346 /* ldc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 346 /* ldc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 346 /* ldc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocOption, 8 /* 3 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocOption, 16 /* 4 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 350 /* ldc2 */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocOption, 8 /* 3 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocOption, 16 /* 4 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 355 /* ldc2l */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 361 /* ldcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 361 /* ldcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 361 /* ldcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 361 /* ldcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 361 /* ldcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 361 /* ldcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 361 /* ldcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 361 /* ldcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 361 /* ldcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 361 /* ldcl */, MCK_CoprocOption, 16 /* 4 */ },
  { Feature_IsARM, 361 /* ldcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 361 /* ldcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 361 /* ldcl */, MCK_CoprocOption, 16 /* 4 */ },
  { Feature_IsThumb2, 361 /* ldcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 361 /* ldcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 361 /* ldcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 361 /* ldcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 361 /* ldcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 388 /* ldr */, MCK_PostIdxRegShifted, 8 /* 3 */ },
  { Feature_IsARM, 392 /* ldrb */, MCK_PostIdxRegShifted, 8 /* 3 */ },
  { Feature_IsARM, 397 /* ldrbt */, MCK_PostIdxRegShifted, 8 /* 3 */ },
  { Feature_IsARM, 403 /* ldrd */, MCK_AM3Offset, 16 /* 4 */ },
  { Feature_IsARM, 435 /* ldrh */, MCK_AM3Offset, 8 /* 3 */ },
  { Feature_IsARM, 440 /* ldrht */, MCK_PostIdxReg, 8 /* 3 */ },
  { Feature_IsARM, 446 /* ldrsb */, MCK_AM3Offset, 8 /* 3 */ },
  { Feature_IsARM, 452 /* ldrsbt */, MCK_PostIdxReg, 8 /* 3 */ },
  { Feature_IsARM, 459 /* ldrsh */, MCK_AM3Offset, 8 /* 3 */ },
  { Feature_IsARM, 465 /* ldrsht */, MCK_PostIdxReg, 8 /* 3 */ },
  { Feature_IsARM, 472 /* ldrt */, MCK_PostIdxRegShifted, 8 /* 3 */ },
  { Feature_IsARM, 485 /* mcr */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 485 /* mcr */, MCK_CoprocReg, 48 /* 4, 5 */ },
  { Feature_IsThumb2, 485 /* mcr */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 485 /* mcr */, MCK_CoprocReg, 48 /* 4, 5 */ },
  { Feature_IsARM, 485 /* mcr */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 485 /* mcr */, MCK_CoprocReg, 48 /* 4, 5 */ },
  { Feature_IsThumb2, 485 /* mcr */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 485 /* mcr */, MCK_CoprocReg, 48 /* 4, 5 */ },
  { Feature_IsARM, 489 /* mcr2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_IsARM, 489 /* mcr2 */, MCK_CoprocReg, 24 /* 3, 4 */ },
  { Feature_IsThumb2, 489 /* mcr2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 489 /* mcr2 */, MCK_CoprocReg, 48 /* 4, 5 */ },
  { Feature_PreV8, 489 /* mcr2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 489 /* mcr2 */, MCK_CoprocReg, 24 /* 3, 4 */ },
  { Feature_IsThumb2|Feature_PreV8, 489 /* mcr2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2|Feature_PreV8, 489 /* mcr2 */, MCK_CoprocReg, 48 /* 4, 5 */ },
  { Feature_IsARM, 494 /* mcrr */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 494 /* mcrr */, MCK_CoprocReg, 32 /* 5 */ },
  { Feature_IsThumb2, 494 /* mcrr */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 494 /* mcrr */, MCK_CoprocReg, 32 /* 5 */ },
  { Feature_PreV8, 499 /* mcrr2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 499 /* mcrr2 */, MCK_CoprocReg, 16 /* 4 */ },
  { Feature_IsThumb2|Feature_PreV8, 499 /* mcrr2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2|Feature_PreV8, 499 /* mcrr2 */, MCK_CoprocReg, 32 /* 5 */ },
  { Feature_IsARM, 532 /* mrc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 532 /* mrc */, MCK_CoprocReg, 48 /* 4, 5 */ },
  { Feature_IsThumb2, 532 /* mrc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 532 /* mrc */, MCK_CoprocReg, 48 /* 4, 5 */ },
  { Feature_IsARM, 532 /* mrc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 532 /* mrc */, MCK_CoprocReg, 48 /* 4, 5 */ },
  { Feature_IsThumb2, 532 /* mrc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 532 /* mrc */, MCK_CoprocReg, 48 /* 4, 5 */ },
  { Feature_IsARM, 536 /* mrc2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_IsARM, 536 /* mrc2 */, MCK_CoprocReg, 24 /* 3, 4 */ },
  { Feature_IsThumb2, 536 /* mrc2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 536 /* mrc2 */, MCK_CoprocReg, 48 /* 4, 5 */ },
  { Feature_PreV8, 536 /* mrc2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 536 /* mrc2 */, MCK_CoprocReg, 24 /* 3, 4 */ },
  { Feature_IsThumb2|Feature_PreV8, 536 /* mrc2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2|Feature_PreV8, 536 /* mrc2 */, MCK_CoprocReg, 48 /* 4, 5 */ },
  { Feature_IsARM, 541 /* mrrc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 541 /* mrrc */, MCK_CoprocReg, 32 /* 5 */ },
  { Feature_IsThumb2, 541 /* mrrc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 541 /* mrrc */, MCK_CoprocReg, 32 /* 5 */ },
  { Feature_PreV8, 546 /* mrrc2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 546 /* mrrc2 */, MCK_CoprocReg, 16 /* 4 */ },
  { Feature_IsThumb2|Feature_PreV8, 546 /* mrrc2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2|Feature_PreV8, 546 /* mrrc2 */, MCK_CoprocReg, 32 /* 5 */ },
  { Feature_IsThumb|Feature_IsMClass, 552 /* mrs */, MCK_MSRMask, 4 /* 2 */ },
  { Feature_IsThumb2|Feature_IsNotMClass, 556 /* msr */, MCK_MSRMask, 2 /* 1 */ },
  { Feature_IsThumb|Feature_IsMClass, 556 /* msr */, MCK_MSRMask, 2 /* 1 */ },
  { Feature_IsARM, 556 /* msr */, MCK_MSRMask, 2 /* 1 */ },
  { Feature_IsARM, 556 /* msr */, MCK_MSRMask, 2 /* 1 */ },
  { Feature_HasT2ExtractPack|Feature_IsThumb2, 584 /* pkhbt */, MCK_PKHLSLImm, 16 /* 4 */ },
  { Feature_IsARM|Feature_HasV6, 584 /* pkhbt */, MCK_PKHLSLImm, 16 /* 4 */ },
  { Feature_HasT2ExtractPack|Feature_IsThumb2, 590 /* pkhtb */, MCK_PKHASRImm, 16 /* 4 */ },
  { Feature_IsARM|Feature_HasV6, 590 /* pkhtb */, MCK_PKHASRImm, 16 /* 4 */ },
  { Feature_IsARM, 773 /* setend */, MCK_SetEndImm, 1 /* 0 */ },
  { Feature_IsThumb, 773 /* setend */, MCK_SetEndImm, 1 /* 0 */ },
  { Feature_IsThumb2, 1185 /* ssat */, MCK_ShifterImm, 16 /* 4 */ },
  { Feature_IsARM, 1185 /* ssat */, MCK_ShifterImm, 16 /* 4 */ },
  { Feature_IsARM, 1215 /* stc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 1215 /* stc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 1215 /* stc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 1215 /* stc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 1215 /* stc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 1215 /* stc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 1215 /* stc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 1215 /* stc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 1215 /* stc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 1215 /* stc */, MCK_CoprocOption, 16 /* 4 */ },
  { Feature_IsARM, 1215 /* stc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 1215 /* stc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 1215 /* stc */, MCK_CoprocOption, 16 /* 4 */ },
  { Feature_IsThumb2, 1215 /* stc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 1215 /* stc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 1215 /* stc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 1215 /* stc */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 1215 /* stc */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocOption, 8 /* 3 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocOption, 16 /* 4 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 1219 /* stc2 */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocOption, 8 /* 3 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocNum, 1 /* 0 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocReg, 2 /* 1 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocOption, 16 /* 4 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_PreV8, 1224 /* stc2l */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 1230 /* stcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 1230 /* stcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 1230 /* stcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 1230 /* stcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 1230 /* stcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 1230 /* stcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 1230 /* stcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 1230 /* stcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 1230 /* stcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 1230 /* stcl */, MCK_CoprocOption, 16 /* 4 */ },
  { Feature_IsARM, 1230 /* stcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 1230 /* stcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 1230 /* stcl */, MCK_CoprocOption, 16 /* 4 */ },
  { Feature_IsThumb2, 1230 /* stcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 1230 /* stcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsARM, 1230 /* stcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsThumb2, 1230 /* stcl */, MCK_CoprocNum, 2 /* 1 */ },
  { Feature_IsThumb2, 1230 /* stcl */, MCK_CoprocReg, 4 /* 2 */ },
  { Feature_IsARM, 1298 /* str */, MCK_PostIdxRegShifted, 8 /* 3 */ },
  { Feature_IsARM, 1302 /* strb */, MCK_PostIdxRegShifted, 8 /* 3 */ },
  { Feature_IsARM, 1307 /* strbt */, MCK_PostIdxRegShifted, 8 /* 3 */ },
  { Feature_IsARM, 1313 /* strd */, MCK_AM3Offset, 16 /* 4 */ },
  { Feature_IsARM, 1345 /* strh */, MCK_AM3Offset, 8 /* 3 */ },
  { Feature_IsARM, 1350 /* strht */, MCK_PostIdxReg, 8 /* 3 */ },
  { Feature_IsARM, 1356 /* strt */, MCK_PostIdxRegShifted, 8 /* 3 */ },
  { Feature_HasT2ExtractPack|Feature_IsThumb2, 1388 /* sxtab */, MCK_RotImm, 16 /* 4 */ },
  { Feature_IsARM|Feature_HasV6, 1388 /* sxtab */, MCK_RotImm, 16 /* 4 */ },
  { Feature_IsThumb2, 1394 /* sxtab16 */, MCK_RotImm, 16 /* 4 */ },
  { Feature_IsARM|Feature_HasV6, 1394 /* sxtab16 */, MCK_RotImm, 16 /* 4 */ },
  { Feature_HasT2ExtractPack|Feature_IsThumb2, 1402 /* sxtah */, MCK_RotImm, 16 /* 4 */ },
  { Feature_IsARM|Feature_HasV6, 1402 /* sxtah */, MCK_RotImm, 16 /* 4 */ },
  { Feature_IsThumb2, 1408 /* sxtb */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsARM|Feature_HasV6, 1408 /* sxtb */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsThumb2, 1408 /* sxtb */, MCK_RotImm, 16 /* 4 */ },
  { Feature_IsThumb2|Feature_HasT2ExtractPack, 1413 /* sxtb16 */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsThumb2, 1413 /* sxtb16 */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsARM|Feature_HasV6, 1413 /* sxtb16 */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsThumb2, 1420 /* sxth */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsARM|Feature_HasV6, 1420 /* sxth */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsThumb2, 1420 /* sxth */, MCK_RotImm, 16 /* 4 */ },
  { Feature_IsThumb2, 1589 /* usat */, MCK_ShifterImm, 16 /* 4 */ },
  { Feature_IsARM, 1589 /* usat */, MCK_ShifterImm, 16 /* 4 */ },
  { Feature_HasT2ExtractPack|Feature_IsThumb2, 1619 /* uxtab */, MCK_RotImm, 16 /* 4 */ },
  { Feature_IsARM|Feature_HasV6, 1619 /* uxtab */, MCK_RotImm, 16 /* 4 */ },
  { Feature_IsThumb2, 1625 /* uxtab16 */, MCK_RotImm, 16 /* 4 */ },
  { Feature_IsARM|Feature_HasV6, 1625 /* uxtab16 */, MCK_RotImm, 16 /* 4 */ },
  { Feature_HasT2ExtractPack|Feature_IsThumb2, 1633 /* uxtah */, MCK_RotImm, 16 /* 4 */ },
  { Feature_IsARM|Feature_HasV6, 1633 /* uxtah */, MCK_RotImm, 16 /* 4 */ },
  { Feature_IsThumb2, 1639 /* uxtb */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsARM|Feature_HasV6, 1639 /* uxtb */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsThumb2, 1639 /* uxtb */, MCK_RotImm, 16 /* 4 */ },
  { Feature_HasT2ExtractPack|Feature_IsThumb2, 1644 /* uxtb16 */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsThumb2, 1644 /* uxtb16 */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsARM|Feature_HasV6, 1644 /* uxtb16 */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsThumb2, 1651 /* uxth */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsARM|Feature_HasV6, 1651 /* uxth */, MCK_RotImm, 8 /* 3 */ },
  { Feature_IsThumb2, 1651 /* uxth */, MCK_RotImm, 16 /* 4 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListOneDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1908 /* vld1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpacedAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpacedAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpacedAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpacedAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpacedAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpacedAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpacedAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpacedAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpacedAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1913 /* vld2 */, MCK_VecListTwoDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 1918 /* vld3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQAllLanes, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 1923 /* vld4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasVFP3, 1993 /* vmov */, MCK_FPImm, 8 /* 3 */ },
  { Feature_HasNEON, 1993 /* vmov */, MCK_FPImm, 8 /* 3 */ },
  { Feature_HasNEON, 1993 /* vmov */, MCK_FPImm, 8 /* 3 */ },
  { Feature_HasVFP3|Feature_HasDPVFP, 1993 /* vmov */, MCK_FPImm, 8 /* 3 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListOneDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2463 /* vst1 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPair, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListDPairSpaced, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2468 /* vst2 */, MCK_VecListTwoDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeD, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 2473 /* vst3 */, MCK_VecListThreeQ, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourDHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQHWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourDWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQWordIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourD, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourDByteIndexed, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 2478 /* vst4 */, MCK_VecListFourQ, 4 /* 2 */ },
  { Feature_HasNEON, 2531 /* vtbl */, MCK_VecListDPair, 8 /* 3 */ },
  { Feature_HasNEON, 2531 /* vtbl */, MCK_VecListFourD, 8 /* 3 */ },
  { Feature_HasNEON, 2531 /* vtbl */, MCK_VecListOneD, 8 /* 3 */ },
  { Feature_HasNEON, 2531 /* vtbl */, MCK_VecListThreeD, 8 /* 3 */ },
  { Feature_HasNEON, 2536 /* vtbx */, MCK_VecListDPair, 8 /* 3 */ },
  { Feature_HasNEON, 2536 /* vtbx */, MCK_VecListFourD, 8 /* 3 */ },
  { Feature_HasNEON, 2536 /* vtbx */, MCK_VecListOneD, 8 /* 3 */ },
  { Feature_HasNEON, 2536 /* vtbx */, MCK_VecListThreeD, 8 /* 3 */ },
};

ARMAsmParser::OperandMatchResultTy ARMAsmParser::
tryCustomParseOperand(SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                      unsigned MCK) {

  switch(MCK) {
  case MCK_AM3Offset:
    return parseAM3Offset(Operands);
  case MCK_Bitfield:
    return parseBitfield(Operands);
  case MCK_CoprocNum:
    return parseCoprocNumOperand(Operands);
  case MCK_CoprocOption:
    return parseCoprocOptionOperand(Operands);
  case MCK_CoprocReg:
    return parseCoprocRegOperand(Operands);
  case MCK_FPImm:
    return parseFPImm(Operands);
  case MCK_InstSyncBarrierOpt:
    return parseInstSyncBarrierOptOperand(Operands);
  case MCK_MSRMask:
    return parseMSRMaskOperand(Operands);
  case MCK_MemBarrierOpt:
    return parseMemBarrierOptOperand(Operands);
  case MCK_PKHASRImm:
    return parsePKHASRImm(Operands);
  case MCK_PKHLSLImm:
    return parsePKHLSLImm(Operands);
  case MCK_PostIdxReg:
    return parsePostIdxReg(Operands);
  case MCK_PostIdxRegShifted:
    return parsePostIdxReg(Operands);
  case MCK_ProcIFlags:
    return parseProcIFlagsOperand(Operands);
  case MCK_RotImm:
    return parseRotImm(Operands);
  case MCK_SetEndImm:
    return parseSetEndImm(Operands);
  case MCK_ShifterImm:
    return parseShifterImm(Operands);
  case MCK_VecListDPairAllLanes:
    return parseVectorList(Operands);
  case MCK_VecListDPair:
    return parseVectorList(Operands);
  case MCK_VecListDPairSpacedAllLanes:
    return parseVectorList(Operands);
  case MCK_VecListDPairSpaced:
    return parseVectorList(Operands);
  case MCK_VecListFourDAllLanes:
    return parseVectorList(Operands);
  case MCK_VecListFourD:
    return parseVectorList(Operands);
  case MCK_VecListFourDByteIndexed:
    return parseVectorList(Operands);
  case MCK_VecListFourDHWordIndexed:
    return parseVectorList(Operands);
  case MCK_VecListFourDWordIndexed:
    return parseVectorList(Operands);
  case MCK_VecListFourQAllLanes:
    return parseVectorList(Operands);
  case MCK_VecListFourQ:
    return parseVectorList(Operands);
  case MCK_VecListFourQHWordIndexed:
    return parseVectorList(Operands);
  case MCK_VecListFourQWordIndexed:
    return parseVectorList(Operands);
  case MCK_VecListOneDAllLanes:
    return parseVectorList(Operands);
  case MCK_VecListOneD:
    return parseVectorList(Operands);
  case MCK_VecListOneDByteIndexed:
    return parseVectorList(Operands);
  case MCK_VecListOneDHWordIndexed:
    return parseVectorList(Operands);
  case MCK_VecListOneDWordIndexed:
    return parseVectorList(Operands);
  case MCK_VecListThreeDAllLanes:
    return parseVectorList(Operands);
  case MCK_VecListThreeD:
    return parseVectorList(Operands);
  case MCK_VecListThreeDByteIndexed:
    return parseVectorList(Operands);
  case MCK_VecListThreeDHWordIndexed:
    return parseVectorList(Operands);
  case MCK_VecListThreeDWordIndexed:
    return parseVectorList(Operands);
  case MCK_VecListThreeQAllLanes:
    return parseVectorList(Operands);
  case MCK_VecListThreeQ:
    return parseVectorList(Operands);
  case MCK_VecListThreeQHWordIndexed:
    return parseVectorList(Operands);
  case MCK_VecListThreeQWordIndexed:
    return parseVectorList(Operands);
  case MCK_VecListTwoDByteIndexed:
    return parseVectorList(Operands);
  case MCK_VecListTwoDHWordIndexed:
    return parseVectorList(Operands);
  case MCK_VecListTwoDWordIndexed:
    return parseVectorList(Operands);
  case MCK_VecListTwoQHWordIndexed:
    return parseVectorList(Operands);
  case MCK_VecListTwoQWordIndexed:
    return parseVectorList(Operands);
  case MCK_ITCondCode:
    return parseITCondCode(Operands);
  default:
    return MatchOperand_NoMatch;
  }
  return MatchOperand_NoMatch;
}

ARMAsmParser::OperandMatchResultTy ARMAsmParser::
MatchOperandParserImpl(SmallVectorImpl<MCParsedAsmOperand*> &Operands,
                       StringRef Mnemonic) {
  // Get the current feature set.
  unsigned AvailableFeatures = getAvailableFeatures();

  // Get the next operand index.
  unsigned NextOpNum = Operands.size()-1;
  // Search the table.
  std::pair<const OperandMatchEntry*, const OperandMatchEntry*> MnemonicRange =
    std::equal_range(OperandMatchTable, OperandMatchTable+695, Mnemonic,
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


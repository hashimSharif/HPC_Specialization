/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Subtarget Enumeration Source Fragment                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_SUBTARGETINFO_ENUM
#undef GET_SUBTARGETINFO_ENUM
namespace llvm {
namespace PPC {
  const uint64_t DeprecatedDST = 1ULL << 0;
  const uint64_t DeprecatedMFTB = 1ULL << 1;
  const uint64_t Directive32 = 1ULL << 2;
  const uint64_t Directive64 = 1ULL << 3;
  const uint64_t Directive440 = 1ULL << 4;
  const uint64_t Directive601 = 1ULL << 5;
  const uint64_t Directive602 = 1ULL << 6;
  const uint64_t Directive603 = 1ULL << 7;
  const uint64_t Directive604 = 1ULL << 8;
  const uint64_t Directive620 = 1ULL << 9;
  const uint64_t Directive750 = 1ULL << 10;
  const uint64_t Directive970 = 1ULL << 11;
  const uint64_t Directive7400 = 1ULL << 12;
  const uint64_t DirectiveA2 = 1ULL << 13;
  const uint64_t DirectiveE500mc = 1ULL << 14;
  const uint64_t DirectiveE5500 = 1ULL << 15;
  const uint64_t DirectivePwr3 = 1ULL << 16;
  const uint64_t DirectivePwr4 = 1ULL << 17;
  const uint64_t DirectivePwr5 = 1ULL << 18;
  const uint64_t DirectivePwr5x = 1ULL << 19;
  const uint64_t DirectivePwr6 = 1ULL << 20;
  const uint64_t DirectivePwr6x = 1ULL << 21;
  const uint64_t DirectivePwr7 = 1ULL << 22;
  const uint64_t Feature64Bit = 1ULL << 23;
  const uint64_t Feature64BitRegs = 1ULL << 24;
  const uint64_t FeatureAltivec = 1ULL << 25;
  const uint64_t FeatureBookE = 1ULL << 26;
  const uint64_t FeatureFCPSGN = 1ULL << 27;
  const uint64_t FeatureFPCVT = 1ULL << 28;
  const uint64_t FeatureFPRND = 1ULL << 29;
  const uint64_t FeatureFRE = 1ULL << 30;
  const uint64_t FeatureFRES = 1ULL << 31;
  const uint64_t FeatureFRSQRTE = 1ULL << 32;
  const uint64_t FeatureFRSQRTES = 1ULL << 33;
  const uint64_t FeatureFSqrt = 1ULL << 34;
  const uint64_t FeatureISEL = 1ULL << 35;
  const uint64_t FeatureLDBRX = 1ULL << 36;
  const uint64_t FeatureLFIWAX = 1ULL << 37;
  const uint64_t FeatureMFOCRF = 1ULL << 38;
  const uint64_t FeaturePOPCNTD = 1ULL << 39;
  const uint64_t FeatureQPX = 1ULL << 40;
  const uint64_t FeatureRecipPrec = 1ULL << 41;
  const uint64_t FeatureSTFIWX = 1ULL << 42;
  const uint64_t FeatureVSX = 1ULL << 43;
}
} // End llvm namespace 
#endif // GET_SUBTARGETINFO_ENUM


#ifdef GET_SUBTARGETINFO_MC_DESC
#undef GET_SUBTARGETINFO_MC_DESC
namespace llvm {
// Sorted (by key) array of values for CPU features.
extern const llvm::SubtargetFeatureKV PPCFeatureKV[] = {
  { "64bit", "Enable 64-bit instructions", PPC::Feature64Bit, 0ULL },
  { "64bitregs", "Enable 64-bit registers usage for ppc32 [beta]", PPC::Feature64BitRegs, 0ULL },
  { "altivec", "Enable Altivec instructions", PPC::FeatureAltivec, 0ULL },
  { "booke", "Enable Book E instructions", PPC::FeatureBookE, 0ULL },
  { "fcpsgn", "Enable the fcpsgn instruction", PPC::FeatureFCPSGN, 0ULL },
  { "fpcvt", "Enable fc[ft]* (unsigned and single-precision) and lfiwzx instructions", PPC::FeatureFPCVT, 0ULL },
  { "fprnd", "Enable the fri[mnpz] instructions", PPC::FeatureFPRND, 0ULL },
  { "fre", "Enable the fre instruction", PPC::FeatureFRE, 0ULL },
  { "fres", "Enable the fres instruction", PPC::FeatureFRES, 0ULL },
  { "frsqrte", "Enable the frsqrte instruction", PPC::FeatureFRSQRTE, 0ULL },
  { "frsqrtes", "Enable the frsqrtes instruction", PPC::FeatureFRSQRTES, 0ULL },
  { "fsqrt", "Enable the fsqrt instruction", PPC::FeatureFSqrt, 0ULL },
  { "isel", "Enable the isel instruction", PPC::FeatureISEL, 0ULL },
  { "ldbrx", "Enable the ldbrx instruction", PPC::FeatureLDBRX, 0ULL },
  { "lfiwax", "Enable the lfiwax instruction", PPC::FeatureLFIWAX, 0ULL },
  { "mfocrf", "Enable the MFOCRF instruction", PPC::FeatureMFOCRF, 0ULL },
  { "popcntd", "Enable the popcnt[dw] instructions", PPC::FeaturePOPCNTD, 0ULL },
  { "qpx", "Enable QPX instructions", PPC::FeatureQPX, 0ULL },
  { "recipprec", "Assume higher precision reciprocal estimates", PPC::FeatureRecipPrec, 0ULL },
  { "stfiwx", "Enable the stfiwx instruction", PPC::FeatureSTFIWX, 0ULL },
  { "vsx", "Enable VSX instructions", PPC::FeatureVSX, 0ULL }
};

// Sorted (by key) array of values for CPU subtype.
extern const llvm::SubtargetFeatureKV PPCSubTypeKV[] = {
  { "440", "Select the 440 processor", PPC::Directive440 | PPC::FeatureISEL | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureBookE | PPC::DeprecatedMFTB, 0ULL },
  { "450", "Select the 450 processor", PPC::Directive440 | PPC::FeatureISEL | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureBookE | PPC::DeprecatedMFTB, 0ULL },
  { "601", "Select the 601 processor", PPC::Directive601, 0ULL },
  { "602", "Select the 602 processor", PPC::Directive602, 0ULL },
  { "603", "Select the 603 processor", PPC::Directive603 | PPC::FeatureFRES | PPC::FeatureFRSQRTE, 0ULL },
  { "603e", "Select the 603e processor", PPC::Directive603 | PPC::FeatureFRES | PPC::FeatureFRSQRTE, 0ULL },
  { "603ev", "Select the 603ev processor", PPC::Directive603 | PPC::FeatureFRES | PPC::FeatureFRSQRTE, 0ULL },
  { "604", "Select the 604 processor", PPC::Directive604 | PPC::FeatureFRES | PPC::FeatureFRSQRTE, 0ULL },
  { "604e", "Select the 604e processor", PPC::Directive604 | PPC::FeatureFRES | PPC::FeatureFRSQRTE, 0ULL },
  { "620", "Select the 620 processor", PPC::Directive620 | PPC::FeatureFRES | PPC::FeatureFRSQRTE, 0ULL },
  { "7400", "Select the 7400 processor", PPC::Directive7400 | PPC::FeatureAltivec | PPC::FeatureFRES | PPC::FeatureFRSQRTE, 0ULL },
  { "7450", "Select the 7450 processor", PPC::Directive7400 | PPC::FeatureAltivec | PPC::FeatureFRES | PPC::FeatureFRSQRTE, 0ULL },
  { "750", "Select the 750 processor", PPC::Directive750 | PPC::FeatureFRES | PPC::FeatureFRSQRTE, 0ULL },
  { "970", "Select the 970 processor", PPC::Directive970 | PPC::FeatureAltivec | PPC::FeatureMFOCRF | PPC::FeatureFSqrt | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureSTFIWX | PPC::Feature64Bit, 0ULL },
  { "a2", "Select the a2 processor", PPC::DirectiveA2 | PPC::FeatureBookE | PPC::FeatureMFOCRF | PPC::FeatureFCPSGN | PPC::FeatureFSqrt | PPC::FeatureFRE | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureFRSQRTES | PPC::FeatureRecipPrec | PPC::FeatureSTFIWX | PPC::FeatureLFIWAX | PPC::FeatureFPRND | PPC::FeatureFPCVT | PPC::FeatureISEL | PPC::FeaturePOPCNTD | PPC::FeatureLDBRX | PPC::Feature64Bit | PPC::DeprecatedMFTB, 0ULL },
  { "a2q", "Select the a2q processor", PPC::DirectiveA2 | PPC::FeatureBookE | PPC::FeatureMFOCRF | PPC::FeatureFCPSGN | PPC::FeatureFSqrt | PPC::FeatureFRE | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureFRSQRTES | PPC::FeatureRecipPrec | PPC::FeatureSTFIWX | PPC::FeatureLFIWAX | PPC::FeatureFPRND | PPC::FeatureFPCVT | PPC::FeatureISEL | PPC::FeaturePOPCNTD | PPC::FeatureLDBRX | PPC::Feature64Bit | PPC::FeatureQPX | PPC::DeprecatedMFTB, 0ULL },
  { "e500mc", "Select the e500mc processor", PPC::DirectiveE500mc | PPC::FeatureMFOCRF | PPC::FeatureSTFIWX | PPC::FeatureBookE | PPC::FeatureISEL | PPC::DeprecatedMFTB, 0ULL },
  { "e5500", "Select the e5500 processor", PPC::DirectiveE5500 | PPC::FeatureMFOCRF | PPC::Feature64Bit | PPC::FeatureSTFIWX | PPC::FeatureBookE | PPC::FeatureISEL | PPC::DeprecatedMFTB, 0ULL },
  { "g3", "Select the g3 processor", PPC::Directive750 | PPC::FeatureFRES | PPC::FeatureFRSQRTE, 0ULL },
  { "g4", "Select the g4 processor", PPC::Directive7400 | PPC::FeatureAltivec | PPC::FeatureFRES | PPC::FeatureFRSQRTE, 0ULL },
  { "g4+", "Select the g4+ processor", PPC::Directive7400 | PPC::FeatureAltivec | PPC::FeatureFRES | PPC::FeatureFRSQRTE, 0ULL },
  { "g5", "Select the g5 processor", PPC::Directive970 | PPC::FeatureAltivec | PPC::FeatureMFOCRF | PPC::FeatureFSqrt | PPC::FeatureSTFIWX | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::Feature64Bit | PPC::DeprecatedMFTB | PPC::DeprecatedDST, 0ULL },
  { "generic", "Select the generic processor", PPC::Directive32, 0ULL },
  { "ppc", "Select the ppc processor", PPC::Directive32, 0ULL },
  { "ppc64", "Select the ppc64 processor", PPC::Directive64 | PPC::FeatureAltivec | PPC::FeatureMFOCRF | PPC::FeatureFSqrt | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureSTFIWX | PPC::Feature64Bit, 0ULL },
  { "ppc64le", "Select the ppc64le processor", PPC::Directive64 | PPC::FeatureAltivec | PPC::FeatureMFOCRF | PPC::FeatureFSqrt | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureSTFIWX | PPC::Feature64Bit, 0ULL },
  { "pwr3", "Select the pwr3 processor", PPC::DirectivePwr3 | PPC::FeatureAltivec | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureMFOCRF | PPC::FeatureSTFIWX | PPC::Feature64Bit, 0ULL },
  { "pwr4", "Select the pwr4 processor", PPC::DirectivePwr4 | PPC::FeatureAltivec | PPC::FeatureMFOCRF | PPC::FeatureFSqrt | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureSTFIWX | PPC::Feature64Bit, 0ULL },
  { "pwr5", "Select the pwr5 processor", PPC::DirectivePwr5 | PPC::FeatureAltivec | PPC::FeatureMFOCRF | PPC::FeatureFSqrt | PPC::FeatureFRE | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureFRSQRTES | PPC::FeatureSTFIWX | PPC::Feature64Bit | PPC::DeprecatedMFTB | PPC::DeprecatedDST, 0ULL },
  { "pwr5x", "Select the pwr5x processor", PPC::DirectivePwr5x | PPC::FeatureAltivec | PPC::FeatureMFOCRF | PPC::FeatureFSqrt | PPC::FeatureFRE | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureFRSQRTES | PPC::FeatureSTFIWX | PPC::FeatureFPRND | PPC::Feature64Bit | PPC::DeprecatedMFTB | PPC::DeprecatedDST, 0ULL },
  { "pwr6", "Select the pwr6 processor", PPC::DirectivePwr6 | PPC::FeatureAltivec | PPC::FeatureMFOCRF | PPC::FeatureFCPSGN | PPC::FeatureFSqrt | PPC::FeatureFRE | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureFRSQRTES | PPC::FeatureRecipPrec | PPC::FeatureSTFIWX | PPC::FeatureLFIWAX | PPC::FeatureFPRND | PPC::Feature64Bit | PPC::DeprecatedMFTB | PPC::DeprecatedDST, 0ULL },
  { "pwr6x", "Select the pwr6x processor", PPC::DirectivePwr5x | PPC::FeatureAltivec | PPC::FeatureMFOCRF | PPC::FeatureFCPSGN | PPC::FeatureFSqrt | PPC::FeatureFRE | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureFRSQRTES | PPC::FeatureRecipPrec | PPC::FeatureSTFIWX | PPC::FeatureLFIWAX | PPC::FeatureFPRND | PPC::Feature64Bit | PPC::DeprecatedMFTB | PPC::DeprecatedDST, 0ULL },
  { "pwr7", "Select the pwr7 processor", PPC::DirectivePwr7 | PPC::FeatureAltivec | PPC::FeatureMFOCRF | PPC::FeatureFCPSGN | PPC::FeatureFSqrt | PPC::FeatureFRE | PPC::FeatureFRES | PPC::FeatureFRSQRTE | PPC::FeatureFRSQRTES | PPC::FeatureRecipPrec | PPC::FeatureSTFIWX | PPC::FeatureLFIWAX | PPC::FeatureFPRND | PPC::FeatureFPCVT | PPC::FeatureISEL | PPC::FeaturePOPCNTD | PPC::FeatureLDBRX | PPC::Feature64Bit | PPC::DeprecatedMFTB | PPC::DeprecatedDST, 0ULL }
};

#ifdef DBGFIELD
#error "<target>GenSubtargetInfo.inc requires a DBGFIELD macro"
#endif
#ifndef NDEBUG
#define DBGFIELD(x) x,
#else
#define DBGFIELD(x)
#endif

// Functional units for "PPC440Itineraries"
namespace PPC440ItinerariesFU {
  const unsigned IFTH1 = 1 << 0;
  const unsigned IFTH2 = 1 << 1;
  const unsigned PDCD1 = 1 << 2;
  const unsigned PDCD2 = 1 << 3;
  const unsigned DISS1 = 1 << 4;
  const unsigned DISS2 = 1 << 5;
  const unsigned FRACC = 1 << 6;
  const unsigned IRACC = 1 << 7;
  const unsigned IEXE1 = 1 << 8;
  const unsigned IEXE2 = 1 << 9;
  const unsigned IWB = 1 << 10;
  const unsigned LRACC = 1 << 11;
  const unsigned JEXE1 = 1 << 12;
  const unsigned JEXE2 = 1 << 13;
  const unsigned JWB = 1 << 14;
  const unsigned AGEN = 1 << 15;
  const unsigned CRD = 1 << 16;
  const unsigned LWB = 1 << 17;
  const unsigned FEXE1 = 1 << 18;
  const unsigned FEXE2 = 1 << 19;
  const unsigned FEXE3 = 1 << 20;
  const unsigned FEXE4 = 1 << 21;
  const unsigned FEXE5 = 1 << 22;
  const unsigned FEXE6 = 1 << 23;
  const unsigned FWB = 1 << 24;
  const unsigned LWARX_Hold = 1 << 25;
}

// Pipeline forwarding pathes for itineraries "PPC440Itineraries"
namespace PPC440ItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned GPR_Bypass = 1 << 0;
  const unsigned FPR_Bypass = 1 << 1;
}

// Functional units for "G3Itineraries"
namespace G3ItinerariesFU {
  const unsigned IU1 = 1 << 0;
  const unsigned IU2 = 1 << 1;
  const unsigned FPU1 = 1 << 2;
  const unsigned BPU = 1 << 3;
  const unsigned SRU = 1 << 4;
  const unsigned SLU = 1 << 5;
}

// Functional units for "G4Itineraries"
namespace G4ItinerariesFU {
  const unsigned IU1 = 1 << 0;
  const unsigned IU2 = 1 << 1;
  const unsigned SLU = 1 << 2;
  const unsigned SRU = 1 << 3;
  const unsigned BPU = 1 << 4;
  const unsigned FPU1 = 1 << 5;
  const unsigned VIU1 = 1 << 6;
  const unsigned VIU2 = 1 << 7;
  const unsigned VPU = 1 << 8;
  const unsigned VFPU = 1 << 9;
}

// Functional units for "G4PlusItineraries"
namespace G4PlusItinerariesFU {
  const unsigned IU1 = 1 << 0;
  const unsigned IU2 = 1 << 1;
  const unsigned IU3 = 1 << 2;
  const unsigned IU4 = 1 << 3;
  const unsigned BPU = 1 << 4;
  const unsigned SLU = 1 << 5;
  const unsigned FPU1 = 1 << 6;
  const unsigned VFPU = 1 << 7;
  const unsigned VIU1 = 1 << 8;
  const unsigned VIU2 = 1 << 9;
  const unsigned VPU = 1 << 10;
}

// Functional units for "G5Itineraries"
namespace G5ItinerariesFU {
  const unsigned IU1 = 1 << 0;
  const unsigned IU2 = 1 << 1;
  const unsigned SLU = 1 << 2;
  const unsigned BPU = 1 << 3;
  const unsigned FPU1 = 1 << 4;
  const unsigned FPU2 = 1 << 5;
  const unsigned VFPU = 1 << 6;
  const unsigned VIU1 = 1 << 7;
  const unsigned VIU2 = 1 << 8;
  const unsigned VPU = 1 << 9;
}

// Functional units for "PPCA2Itineraries"
namespace PPCA2ItinerariesFU {
  const unsigned XU = 1 << 0;
  const unsigned FU = 1 << 1;
}

// Functional units for "PPCE500mcItineraries"
namespace PPCE500mcItinerariesFU {
  const unsigned DIS0 = 1 << 0;
  const unsigned DIS1 = 1 << 1;
  const unsigned SFX0 = 1 << 2;
  const unsigned SFX1 = 1 << 3;
  const unsigned BU = 1 << 4;
  const unsigned CFX_DivBypass = 1 << 5;
  const unsigned CFX_0 = 1 << 6;
  const unsigned LSU_0 = 1 << 7;
  const unsigned FPU_0 = 1 << 8;
}

// Pipeline forwarding pathes for itineraries "PPCE500mcItineraries"
namespace PPCE500mcItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned CR_Bypass = 1 << 0;
  const unsigned GPR_Bypass = 1 << 1;
  const unsigned FPR_Bypass = 1 << 2;
}

// Functional units for "PPCE5500Itineraries"
namespace PPCE5500ItinerariesFU {
  const unsigned DIS0 = 1 << 0;
  const unsigned DIS1 = 1 << 1;
  const unsigned SFX0 = 1 << 2;
  const unsigned SFX1 = 1 << 3;
  const unsigned BU = 1 << 4;
  const unsigned CFX_DivBypass = 1 << 5;
  const unsigned CFX_0 = 1 << 6;
  const unsigned CFX_1 = 1 << 7;
  const unsigned LSU_0 = 1 << 8;
  const unsigned FPU_0 = 1 << 9;
}

// Pipeline forwarding pathes for itineraries "PPCE5500Itineraries"
namespace PPCE5500ItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned CR_Bypass = 1 << 0;
  const unsigned GPR_Bypass = 1 << 1;
  const unsigned FPR_Bypass = 1 << 2;
}

extern const llvm::InstrStage PPCStages[] = {
  { 0, 0, 0, llvm::InstrStage::Required }, // No itinerary
  { 1, PPC440ItinerariesFU::IFTH1 | PPC440ItinerariesFU::IFTH2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::PDCD1 | PPC440ItinerariesFU::PDCD2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::DISS1 | PPC440ItinerariesFU::DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IRACC | PPC440ItinerariesFU::LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IEXE1 | PPC440ItinerariesFU::JEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IEXE2 | PPC440ItinerariesFU::JEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IWB | PPC440ItinerariesFU::JWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 1-7
  { 1, PPC440ItinerariesFU::IFTH1 | PPC440ItinerariesFU::IFTH2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::PDCD1 | PPC440ItinerariesFU::PDCD2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::DISS1 | PPC440ItinerariesFU::DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 8-14
  { 1, PPC440ItinerariesFU::IFTH1 | PPC440ItinerariesFU::IFTH2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::PDCD1 | PPC440ItinerariesFU::PDCD2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::DISS1 | PPC440ItinerariesFU::DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::AGEN, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::CRD, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::LWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 15-21
  { 1, PPC440ItinerariesFU::IFTH1 | PPC440ItinerariesFU::IFTH2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::PDCD1 | PPC440ItinerariesFU::PDCD2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::DISS1 | PPC440ItinerariesFU::DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 33, PPC440ItinerariesFU::IWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 22-28
  { 1, PPC440ItinerariesFU::IFTH1 | PPC440ItinerariesFU::IFTH2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::PDCD1 | PPC440ItinerariesFU::PDCD2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::DISS1 | PPC440ItinerariesFU::DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::AGEN, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::CRD, -1, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPC440ItinerariesFU::LWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 29-35
  { 1, PPC440ItinerariesFU::IFTH1 | PPC440ItinerariesFU::IFTH2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::PDCD1 | PPC440ItinerariesFU::PDCD2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::DISS1 | PPC440ItinerariesFU::DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE3, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE4, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE5, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE6, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 36-46
  { 1, PPC440ItinerariesFU::IFTH1 | PPC440ItinerariesFU::IFTH2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::PDCD1 | PPC440ItinerariesFU::PDCD2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::DISS1 | PPC440ItinerariesFU::DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE3, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE4, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE5, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE6, -1, (llvm::InstrStage::ReservationKinds)0 },   { 25, PPC440ItinerariesFU::FWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 47-57
  { 1, PPC440ItinerariesFU::IFTH1 | PPC440ItinerariesFU::IFTH2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::PDCD1 | PPC440ItinerariesFU::PDCD2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::DISS1 | PPC440ItinerariesFU::DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE3, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE4, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE5, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE6, -1, (llvm::InstrStage::ReservationKinds)0 },   { 13, PPC440ItinerariesFU::FWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 58-68
  { 1, PPC440ItinerariesFU::IFTH1 | PPC440ItinerariesFU::IFTH2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::PDCD1 | PPC440ItinerariesFU::PDCD2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::DISS1 | PPC440ItinerariesFU::DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FRACC, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::LRACC, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::AGEN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::JEXE1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::FEXE2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::CRD, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::JEXE2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 6, PPC440ItinerariesFU::FEXE3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 6, PPC440ItinerariesFU::LWB, 0, (llvm::InstrStage::ReservationKinds)0 },   { 6, PPC440ItinerariesFU::JWB, 0, (llvm::InstrStage::ReservationKinds)0 },   { 6, PPC440ItinerariesFU::IWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 69-86
  { 1, PPC440ItinerariesFU::IFTH1 | PPC440ItinerariesFU::IFTH2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::PDCD1 | PPC440ItinerariesFU::PDCD2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::DISS1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IRACC, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPC440ItinerariesFU::LWARX_Hold, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::AGEN, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::CRD, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::LWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 87-95
  { 1, PPC440ItinerariesFU::IFTH1 | PPC440ItinerariesFU::IFTH2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::PDCD1 | PPC440ItinerariesFU::PDCD2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::DISS1 | PPC440ItinerariesFU::DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::IEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPC440ItinerariesFU::IWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 96-102
  { 1, PPC440ItinerariesFU::IFTH1 | PPC440ItinerariesFU::IFTH2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::PDCD1 | PPC440ItinerariesFU::PDCD2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::DISS1 | PPC440ItinerariesFU::DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPC440ItinerariesFU::AGEN, 1, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPC440ItinerariesFU::CRD, 1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::LWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 103-109
  { 1, G3ItinerariesFU::IU1 | G3ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 110
  { 1, G3ItinerariesFU::BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 111
  { 1, G3ItinerariesFU::SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 112
  { 3, G3ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 113
  { 19, G3ItinerariesFU::IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 114
  { 2, G3ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 115
  { 1, G3ItinerariesFU::FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 116
  { 31, G3ItinerariesFU::FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 117
  { 17, G3ItinerariesFU::FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 118
  { 2, G3ItinerariesFU::FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 119
  { 2, G3ItinerariesFU::SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 120
  { 34, G3ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 121
  { 3, G3ItinerariesFU::SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 122
  { 3, G3ItinerariesFU::FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 123
  { 5, G3ItinerariesFU::IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 124
  { 6, G3ItinerariesFU::IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 125
  { 3, G3ItinerariesFU::IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 126
  { 8, G3ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 127
  { 2, G3ItinerariesFU::IU1 | G3ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 128
  { 1, G4ItinerariesFU::IU1 | G4ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 129
  { 1, G4ItinerariesFU::BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 130
  { 1, G4ItinerariesFU::SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 131
  { 2, G4ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 132
  { 19, G4ItinerariesFU::IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 133
  { 1, G4ItinerariesFU::FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 134
  { 31, G4ItinerariesFU::FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 135
  { 17, G4ItinerariesFU::FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 136
  { 2, G4ItinerariesFU::SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 137
  { 34, G4ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 138
  { 3, G4ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 139
  { 3, G4ItinerariesFU::SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 140
  { 3, G4ItinerariesFU::FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 141
  { 5, G4ItinerariesFU::IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 142
  { 6, G4ItinerariesFU::IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 143
  { 3, G4ItinerariesFU::IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 144
  { 5, G4ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 145
  { 8, G4ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 146
  { 8, G4ItinerariesFU::SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 147
  { 2, G4ItinerariesFU::IU1 | G4ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 148
  { 4, G4ItinerariesFU::VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 149
  { 1, G4ItinerariesFU::VIU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 150
  { 1, G4ItinerariesFU::VPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 151
  { 1, G4PlusItinerariesFU::IU1 | G4PlusItinerariesFU::IU2 | G4PlusItinerariesFU::IU3 | G4PlusItinerariesFU::IU4, -1, (llvm::InstrStage::ReservationKinds)0 }, // 152
  { 1, G4PlusItinerariesFU::BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 153
  { 2, G4PlusItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 154
  { 3, G4PlusItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 155
  { 23, G4PlusItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 156
  { 5, G4PlusItinerariesFU::FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 157
  { 35, G4PlusItinerariesFU::FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 158
  { 21, G4PlusItinerariesFU::FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 159
  { 3, G4PlusItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 160
  { 0, G4PlusItinerariesFU::IU1 | G4PlusItinerariesFU::IU2 | G4PlusItinerariesFU::IU3 | G4PlusItinerariesFU::IU4, -1, (llvm::InstrStage::ReservationKinds)0 }, // 161
  { 4, G4PlusItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 162
  { 37, G4PlusItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 163
  { 4, G4PlusItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 164
  { 5, G4PlusItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 165
  { 2, G4PlusItinerariesFU::IU1 | G4PlusItinerariesFU::IU2 | G4PlusItinerariesFU::IU3 | G4PlusItinerariesFU::IU4, -1, (llvm::InstrStage::ReservationKinds)0 }, // 166
  { 35, G4PlusItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 167
  { 4, G4PlusItinerariesFU::VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 168
  { 1, G4PlusItinerariesFU::VIU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 169
  { 2, G4PlusItinerariesFU::VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 170
  { 2, G4PlusItinerariesFU::VPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 171
  { 2, G5ItinerariesFU::IU1 | G5ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 172
  { 1, G5ItinerariesFU::BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 173
  { 3, G5ItinerariesFU::IU1 | G5ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 174
  { 4, G5ItinerariesFU::BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 175
  { 3, G5ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 176
  { 68, G5ItinerariesFU::IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 177
  { 36, G5ItinerariesFU::IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 178
  { 6, G5ItinerariesFU::FPU1 | G5ItinerariesFU::FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 179
  { 8, G5ItinerariesFU::FPU1 | G5ItinerariesFU::FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 180
  { 33, G5ItinerariesFU::FPU1 | G5ItinerariesFU::FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 181
  { 40, G5ItinerariesFU::FPU1 | G5ItinerariesFU::FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 182
  { 40, G5ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 183
  { 11, G5ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 184
  { 5, G5ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 185
  { 64, G5ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 186
  { 2, G5ItinerariesFU::BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 187
  { 2, G5ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 188
  { 3, G5ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 189
  { 6, G5ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 190
  { 10, G5ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 191
  { 3, G5ItinerariesFU::BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 192
  { 8, G5ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 193
  { 5, G5ItinerariesFU::IU1 | G5ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 194
  { 7, G5ItinerariesFU::IU1 | G5ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 195
  { 4, G5ItinerariesFU::IU1 | G5ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 196
  { 4, G5ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 197
  { 35, G5ItinerariesFU::SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 198
  { 1, G5ItinerariesFU::IU1 | G5ItinerariesFU::IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 199
  { 8, G5ItinerariesFU::VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 200
  { 2, G5ItinerariesFU::VIU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 201
  { 2, G5ItinerariesFU::VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 202
  { 3, G5ItinerariesFU::VPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 203
  { 1, PPCA2ItinerariesFU::XU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 204
  { 1, PPCA2ItinerariesFU::FU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 205
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::SFX0 | PPCE500mcItinerariesFU::SFX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 206-207
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::BU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 208-209
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 210-211
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 14, PPCE500mcItinerariesFU::CFX_DivBypass, -1, (llvm::InstrStage::ReservationKinds)0 }, // 212-214
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE500mcItinerariesFU::FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 215-216
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE500mcItinerariesFU::FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 217-218
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 68, PPCE500mcItinerariesFU::FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 219-220
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 38, PPCE500mcItinerariesFU::FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 221-222
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::SFX0 | PPCE500mcItinerariesFU::SFX1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 223-225
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE500mcItinerariesFU::LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 226-227
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 5, PPCE500mcItinerariesFU::SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 228-229
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 8, PPCE500mcItinerariesFU::FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 230-231
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE500mcItinerariesFU::SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 232-233
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE500mcItinerariesFU::SFX0 | PPCE500mcItinerariesFU::SFX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 234-235
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 236-237
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::LSU_0, 0, (llvm::InstrStage::ReservationKinds)0 }, // 238-239
  { 1, PPCE500mcItinerariesFU::DIS0 | PPCE500mcItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE500mcItinerariesFU::SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 240-241
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::SFX0 | PPCE5500ItinerariesFU::SFX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 242-243
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::BU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 244-245
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 246-247
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 26, PPCE5500ItinerariesFU::CFX_DivBypass, -1, (llvm::InstrStage::ReservationKinds)0 }, // 248-250
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 16, PPCE5500ItinerariesFU::CFX_DivBypass, -1, (llvm::InstrStage::ReservationKinds)0 }, // 251-253
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 254-255
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 31, PPCE5500ItinerariesFU::FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 256-257
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 16, PPCE5500ItinerariesFU::FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 258-259
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::SFX0 | PPCE5500ItinerariesFU::SFX1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 260-262
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE5500ItinerariesFU::LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 263-264
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE5500ItinerariesFU::LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 265-266
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 5, PPCE5500ItinerariesFU::CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 267-268
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 269-270
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE5500ItinerariesFU::SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 271-272
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE5500ItinerariesFU::CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 273-274
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 7, PPCE5500ItinerariesFU::FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 275-276
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE5500ItinerariesFU::CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 277-278
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::CFX_1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 279-281
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE5500ItinerariesFU::CFX_1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 282-284
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE5500ItinerariesFU::SFX0 | PPCE5500ItinerariesFU::SFX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 285-286
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::LSU_0, 0, (llvm::InstrStage::ReservationKinds)0 }, // 287-288
  { 1, PPCE5500ItinerariesFU::DIS0 | PPCE5500ItinerariesFU::DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE5500ItinerariesFU::SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 289-290
  { 0, 0, 0, llvm::InstrStage::Required } // End stages
};
extern const unsigned PPCOperandCycles[] = {
  0, // No itinerary
  6,   4,   4, // 1-3
  6,   4,   4, // 4-6
  8,   4, // 7-8
  6,   4,   4, // 9-11
  8,   4,   4, // 12-14
  8,   5, // 15-16
  40,   4,   4, // 17-19
  9,   5, // 20-21
  10,   4,   4, // 22-24
  10,   4,   4, // 25-27
  10,   4,   4, // 28-30
  35,   4,   4, // 31-33
  23,   4,   4, // 34-36
  10,   4,   4,   4, // 37-40
  8,   5, // 41-42
  9,   5, // 43-44
  9,   5,   5, // 45-47
  9,   5,   5, // 48-50
  8,   5, // 51-52
  8,   5, // 53-54
  8,   5, // 55-56
  8,   5, // 57-58
  8,   4,   4, // 59-61
  8,   4, // 62-63
  10,   4, // 64-65
  7,   4,   4, // 66-68
  7,   4, // 69-70
  10,   4, // 71-72
  8,   5, // 73-74
  8,   4,   4, // 75-77
  10,   4, // 78-79
  7,   4,   4, // 80-82
  6,   4, // 83-84
  8,   4,   4, // 85-87
  8,   4,   4, // 88-90
  8,   4,   4, // 91-93
  6,   4,   4, // 94-96
  6,   4,   4, // 97-99
  8,   5, // 100-101
  8,   5, // 102-103
  8,   5, // 104-105
  8,   5, // 106-107
  8,   5,   5, // 108-110
  8,   5,   5, // 111-113
  8,   5, // 114-115
  6,   4, // 116-117
  1,   1,   1, // 118-120
  2,   1,   1, // 121-123
  6,   1,   1, // 124-126
  2,   1,   1, // 127-129
  1,   1,   1, // 130-132
  1,   1,   1, // 133-135
  71,   1,   1, // 136-138
  39,   1,   1, // 139-141
  6,   1,   1, // 142-144
  6,   1,   1, // 145-147
  6,   1,   1, // 148-150
  5,   1,   1, // 151-153
  72,   1,   1, // 154-156
  59,   1,   1, // 157-159
  6,   1,   1,   1, // 160-163
  69,   1,   1, // 164-166
  16,   1,   1, // 167-169
  16, // 170
  6,   8,   1,   1, // 171-174
  6,   1,   1, // 175-177
  7,   1,   1, // 178-180
  7,   9,   1,   1, // 181-184
  6,   1,   1, // 185-187
  6,   8,   1,   1, // 188-191
  82,   1,   1, // 192-194
  5,   1,   1, // 195-197
  6,   1, // 198-199
  6,   1, // 200-201
  4,   1, // 202-203
  4,   1, // 204-205
  1,   1,   1, // 206-208
  1,   1,   1, // 209-211
  6,   1, // 212-213
  16,   1, // 214-215
  5,   1,   1, // 216-218
  5,   1,   1, // 219-221
  6,   1,   1, // 222-224
  2,   1,   1, // 225-227
  2,   1,   1, // 228-230
  2,   1,   1, // 231-233
  2,   1,   1, // 234-236
  2,   1,   1,   1, // 237-240
  1,   1,   1, // 241-243
  82,   1,   1, // 244-246
  2,   1,   1,   1, // 247-250
  1,   1,   1, // 251-253
  2,   1,   1,   1, // 254-257
  82,   1,   1, // 258-260
  6, // 261
  2,   1, // 262-263
  2,   1, // 264-265
  4,   1,   1, // 266-268
  4,   1,   1, // 269-271
  4,   1, // 272-273
  5,   1,   1, // 274-276
  4,   1,   1, // 277-279
  6,   1, // 280-281
  17,   1,   1, // 282-284
  6,   1, // 285-286
  11,   1,   1, // 287-289
  13,   1,   1, // 290-292
  11,   1,   1, // 293-295
  71,   1,   1, // 296-298
  41,   1,   1, // 299-301
  13,   1,   1,   1, // 302-305
  6,   1, // 306-307
  6,   1, // 308-309
  7,   1,   1, // 310-312
  7,   1,   1, // 313-315
  6,   1, // 316-317
  6,   1, // 318-319
  7,   1, // 320-321
  6,   1,   1, // 322-324
  4,   1, // 325-326
  8,   1, // 327-328
  4,   1, // 329-330
  11, // 331
  7,   1, // 332-333
  7,   1, // 334-335
  6,   1, // 336-337
  4,   1,   1, // 338-340
  4,   1, // 341-342
  11,   1,   1, // 343-345
  5,   1, // 346-347
  7,   1,   1, // 348-350
  7,   1,   1, // 351-353
  7,   1,   1, // 354-356
  4,   1,   1, // 357-359
  4,   1,   1, // 360-362
  6,   1, // 363-364
  6,   1,   1, // 365-367
  6,   1,   1, // 368-370
  6,   1, // 371-372
  5,   1, // 373-374
  5,   2,   2, // 375-377
  5,   2,   2, // 378-380
  5,   2, // 381-382
  6,   2,   2, // 383-385
  5,   2,   2, // 386-388
  7,   2, // 389-390
  30,   2,   2, // 391-393
  20,   2,   2, // 394-396
  7,   2, // 397-398
  11,   2,   2, // 399-401
  11,   2,   2, // 402-404
  11,   2,   2, // 405-407
  39,   2,   2, // 408-410
  24,   2,   2, // 411-413
  11,   2,   2,   2, // 414-417
  7,   2, // 418-419
  7,   2, // 420-421
  7,   2, // 422-423
  7,   2, // 424-425
  7,   2, // 426-427
  8,   2,   2, // 428-430
  8,   2,   2, // 431-433
  7,   2, // 434-435
  7,   2, // 436-437
  8,   2, // 438-439
  7,   2,   2, // 440-442
  5,   2, // 443-444
  9,   2, // 445-446
  5, // 447
  11, // 448
  8,   2, // 449-450
  8,   2, // 451-452
  7,   2, // 453-454
  5,   2,   2, // 455-457
  5, // 458
  11,   2,   2, // 459-461
  6,   2, // 462-463
  8,   2,   2, // 464-466
  8,   2,   2, // 467-469
  9,   2,   2, // 470-472
  8,   2,   2, // 473-475
  6,   2,   2, // 476-478
  5,   2,   2, // 479-481
  5,   2,   2, // 482-484
  6,   2,   2, // 485-487
  7,   2, // 488-489
  7,   2, // 490-491
  7,   2, // 492-493
  7,   2, // 494-495
  7,   2,   2, // 496-498
  7,   2,   2, // 499-501
  7,   2, // 502-503
  6,   2, // 504-505
  0 // End operand cycles
};
extern const unsigned PPCForwardingPaths[] = {
 0, // No itinerary
PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 1-3
PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 4-6
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 7-8
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 9-11
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 12-14
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 15-16
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 17-19
PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 20-21
PPC440ItinerariesBypass::FPR_Bypass, PPC440ItinerariesBypass::FPR_Bypass, PPC440ItinerariesBypass::FPR_Bypass, // 22-24
PPC440ItinerariesBypass::FPR_Bypass, PPC440ItinerariesBypass::FPR_Bypass, PPC440ItinerariesBypass::FPR_Bypass, // 25-27
PPC440ItinerariesBypass::FPR_Bypass, PPC440ItinerariesBypass::FPR_Bypass, PPC440ItinerariesBypass::FPR_Bypass, // 28-30
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::FPR_Bypass, PPC440ItinerariesBypass::FPR_Bypass, // 31-33
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::FPR_Bypass, PPC440ItinerariesBypass::FPR_Bypass, // 34-36
PPC440ItinerariesBypass::FPR_Bypass, PPC440ItinerariesBypass::FPR_Bypass, PPC440ItinerariesBypass::FPR_Bypass, PPC440ItinerariesBypass::FPR_Bypass, // 37-40
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 41-42
PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 43-44
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 45-47
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 48-50
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 51-52
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 53-54
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 55-56
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 57-58
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 59-61
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 62-63
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 64-65
PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 66-68
PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 69-70
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 71-72
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 73-74
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 75-77
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 78-79
PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 80-82
PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 83-84
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 85-87
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 88-90
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 91-93
PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 94-96
PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 97-99
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 100-101
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 102-103
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 104-105
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 106-107
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 108-110
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 111-113
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::GPR_Bypass, // 114-115
PPC440ItinerariesBypass::GPR_Bypass, PPC440ItinerariesBypass::GPR_Bypass, // 116-117
 0,  0,  0, // 118-120
 0,  0,  0, // 121-123
 0,  0,  0, // 124-126
 0,  0,  0, // 127-129
 0,  0,  0, // 130-132
 0,  0,  0, // 133-135
 0,  0,  0, // 136-138
 0,  0,  0, // 139-141
 0,  0,  0, // 142-144
 0,  0,  0, // 145-147
 0,  0,  0, // 148-150
 0,  0,  0, // 151-153
 0,  0,  0, // 154-156
 0,  0,  0, // 157-159
 0,  0,  0,  0, // 160-163
 0,  0,  0, // 164-166
 0,  0,  0, // 167-169
 0, // 170
 0,  0,  0,  0, // 171-174
 0,  0,  0, // 175-177
 0,  0,  0, // 178-180
 0,  0,  0,  0, // 181-184
 0,  0,  0, // 185-187
 0,  0,  0,  0, // 188-191
 0,  0,  0, // 192-194
 0,  0,  0, // 195-197
 0,  0, // 198-199
 0,  0, // 200-201
 0,  0, // 202-203
 0,  0, // 204-205
 0,  0,  0, // 206-208
 0,  0,  0, // 209-211
 0,  0, // 212-213
 0,  0, // 214-215
 0,  0,  0, // 216-218
 0,  0,  0, // 219-221
 0,  0,  0, // 222-224
 0,  0,  0, // 225-227
 0,  0,  0, // 228-230
 0,  0,  0, // 231-233
 0,  0,  0, // 234-236
 0,  0,  0,  0, // 237-240
 0,  0,  0, // 241-243
 0,  0,  0, // 244-246
 0,  0,  0,  0, // 247-250
 0,  0,  0, // 251-253
 0,  0,  0,  0, // 254-257
 0,  0,  0, // 258-260
 0, // 261
 0,  0, // 262-263
 0,  0, // 264-265
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 266-268
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 269-271
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 272-273
PPCE500mcItinerariesBypass::CR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 274-276
PPCE500mcItinerariesBypass::CR_Bypass, PPCE500mcItinerariesBypass::CR_Bypass, PPCE500mcItinerariesBypass::CR_Bypass, // 277-279
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 280-281
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 282-284
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 285-286
PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::FPR_Bypass, // 287-289
PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::FPR_Bypass, // 290-292
PPCE500mcItinerariesBypass::CR_Bypass, PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::FPR_Bypass, // 293-295
PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::FPR_Bypass, // 296-298
PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::FPR_Bypass, // 299-301
PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::FPR_Bypass, // 302-305
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 306-307
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 308-309
PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 310-312
PPCE500mcItinerariesBypass::FPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 313-315
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 316-317
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 318-319
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 320-321
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 322-324
PPCE500mcItinerariesBypass::CR_Bypass, PPCE500mcItinerariesBypass::CR_Bypass, // 325-326
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::CR_Bypass, // 327-328
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::CR_Bypass, // 329-330
PPCE500mcItinerariesBypass::FPR_Bypass, // 331
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 332-333
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 334-335
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 336-337
PPCE500mcItinerariesBypass::CR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass,  0, // 338-340
PPCE500mcItinerariesBypass::CR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 341-342
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::NoBypass, // 343-345
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 346-347
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 348-350
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 351-353
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 354-356
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 357-359
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 360-362
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 363-364
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 365-367
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 368-370
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 371-372
PPCE500mcItinerariesBypass::GPR_Bypass, PPCE500mcItinerariesBypass::GPR_Bypass, // 373-374
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 375-377
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 378-380
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 381-382
PPCE5500ItinerariesBypass::CR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 383-385
PPCE5500ItinerariesBypass::CR_Bypass, PPCE5500ItinerariesBypass::CR_Bypass, PPCE5500ItinerariesBypass::CR_Bypass, // 386-388
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 389-390
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 391-393
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 394-396
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 397-398
PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::FPR_Bypass, // 399-401
PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::FPR_Bypass, // 402-404
PPCE5500ItinerariesBypass::CR_Bypass, PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::FPR_Bypass, // 405-407
PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::FPR_Bypass, // 408-410
PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::FPR_Bypass, // 411-413
PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::FPR_Bypass, // 414-417
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 418-419
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 420-421
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 422-423
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 424-425
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 426-427
PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 428-430
PPCE5500ItinerariesBypass::FPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 431-433
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 434-435
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 436-437
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 438-439
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 440-442
PPCE5500ItinerariesBypass::CR_Bypass, PPCE5500ItinerariesBypass::CR_Bypass, // 443-444
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::CR_Bypass, // 445-446
PPCE5500ItinerariesBypass::GPR_Bypass, // 447
PPCE5500ItinerariesBypass::FPR_Bypass, // 448
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 449-450
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 451-452
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 453-454
PPCE5500ItinerariesBypass::CR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass,  0, // 455-457
PPCE5500ItinerariesBypass::GPR_Bypass, // 458
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::NoBypass, // 459-461
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 462-463
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 464-466
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 467-469
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 470-472
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 473-475
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 476-478
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 479-481
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 482-484
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 485-487
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 488-489
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 490-491
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 492-493
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 494-495
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 496-498
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 499-501
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 502-503
PPCE5500ItinerariesBypass::GPR_Bypass, PPCE5500ItinerariesBypass::GPR_Bypass, // 504-505
 0 // End bypass tables
};

static const llvm::InstrItinerary *NoItineraries = 0;

static const llvm::InstrItinerary PPC440Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 1, 8, 1, 4 }, // 1 IntSimple
  { 1, 1, 8, 4, 7 }, // 2 IntGeneral
  { 1, 8, 15, 7, 9 }, // 3 BrB
  { 1, 1, 8, 9, 12 }, // 4 IntCompare
  { 1, 8, 15, 12, 15 }, // 5 BrCR
  { 1, 15, 22, 15, 17 }, // 6 LdStDCBF
  { 0, 0, 0, 0, 0 }, // 7 IntDivD
  { 1, 22, 29, 17, 20 }, // 8 IntDivW
  { 1, 29, 36, 20, 22 }, // 9 LdStLoad
  { 1, 36, 47, 22, 25 }, // 10 FPGeneral
  { 1, 36, 47, 25, 28 }, // 11 FPAddSub
  { 1, 36, 47, 28, 31 }, // 12 FPCompare
  { 1, 47, 58, 31, 34 }, // 13 FPDivD
  { 1, 58, 69, 34, 37 }, // 14 FPDivS
  { 1, 36, 47, 37, 41 }, // 15 FPFused
  { 0, 0, 0, 0, 0 }, // 16 FPSqrt
  { 1, 15, 22, 41, 43 }, // 17 LdStICBI
  { 1, 69, 87, 0, 0 }, // 18 SprISYNC
  { 1, 29, 36, 43, 45 }, // 19 LdStLoadUpd
  { 0, 0, 0, 0, 0 }, // 20 LdStLD
  { 0, 0, 0, 0, 0 }, // 21 LdStLDARX
  { 0, 0, 0, 0, 0 }, // 22 LdStLDU
  { 1, 29, 36, 45, 48 }, // 23 LdStLFD
  { 1, 15, 22, 48, 51 }, // 24 LdStLFDU
  { 1, 15, 22, 51, 53 }, // 25 LdStLHA
  { 1, 15, 22, 53, 55 }, // 26 LdStLHAU
  { 1, 15, 22, 55, 57 }, // 27 LdStLMW
  { 0, 0, 0, 0, 0 }, // 28 LdStLWA
  { 1, 87, 96, 57, 59 }, // 29 LdStLWARX
  { 1, 8, 15, 59, 62 }, // 30 BrMCR
  { 1, 8, 15, 62, 64 }, // 31 SprMFCR
  { 1, 96, 103, 64, 66 }, // 32 SprMFSPR
  { 1, 8, 15, 66, 69 }, // 33 IntMFFS
  { 1, 8, 15, 69, 71 }, // 34 SprMFMSR
  { 1, 96, 103, 71, 73 }, // 35 SprMFTB
  { 1, 29, 36, 73, 75 }, // 36 LdStStore
  { 1, 8, 15, 75, 78 }, // 37 BrMCRX
  { 1, 96, 103, 78, 80 }, // 38 SprMTSPR
  { 1, 8, 15, 80, 83 }, // 39 IntMTFSB0
  { 1, 8, 15, 83, 85 }, // 40 SprMTMSR
  { 0, 0, 0, 0, 0 }, // 41 SprMTMSRD
  { 1, 8, 15, 85, 88 }, // 42 IntMulHW
  { 1, 8, 15, 88, 91 }, // 43 IntMulHWU
  { 0, 0, 0, 0, 0 }, // 44 IntMulHD
  { 1, 8, 15, 91, 94 }, // 45 IntMulLI
  { 0, 0, 0, 0, 0 }, // 46 IntRotateD
  { 0, 0, 0, 0, 0 }, // 47 IntRotateDI
  { 1, 1, 8, 94, 97 }, // 48 IntRotate
  { 0, 0, 0, 0, 0 }, // 49 SprSLBIA
  { 0, 0, 0, 0, 0 }, // 50 SprSLBIE
  { 0, 0, 0, 0, 0 }, // 51 SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 52 SprSLBMTE
  { 1, 1, 8, 97, 100 }, // 53 IntShift
  { 1, 29, 36, 100, 102 }, // 54 LdStStoreUpd
  { 1, 29, 36, 102, 104 }, // 55 LdStSTD
  { 1, 87, 96, 104, 106 }, // 56 LdStSTDCX
  { 1, 29, 36, 106, 108 }, // 57 LdStSTDU
  { 1, 15, 22, 108, 111 }, // 58 LdStSTFD
  { 1, 15, 22, 111, 114 }, // 59 LdStSTFDU
  { 1, 87, 96, 114, 116 }, // 60 LdStSTWCX
  { 1, 103, 110, 0, 0 }, // 61 LdStSync
  { 0, 0, 0, 0, 0 }, // 62 IntTrapD
  { 0, 0, 0, 0, 0 }, // 63 SprTLBIE
  { 0, 0, 0, 0, 0 }, // 64 SprTLBIEL
  { 1, 8, 15, 0, 0 }, // 65 SprTLBSYNC
  { 1, 8, 15, 116, 118 }, // 66 IntTrapW
  { 0, 0, 0, 0, 0 }, // 67 VecFP
  { 0, 0, 0, 0, 0 }, // 68 VecGeneral
  { 0, 0, 0, 0, 0 }, // 69 VecFPCompare
  { 0, 0, 0, 0, 0 }, // 70 VecPerm
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary G3Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 110, 111, 0, 0 }, // 1 IntSimple
  { 1, 110, 111, 0, 0 }, // 2 IntGeneral
  { 1, 111, 112, 0, 0 }, // 3 BrB
  { 1, 110, 111, 0, 0 }, // 4 IntCompare
  { 1, 112, 113, 0, 0 }, // 5 BrCR
  { 1, 113, 114, 0, 0 }, // 6 LdStDCBF
  { 0, 0, 0, 0, 0 }, // 7 IntDivD
  { 1, 114, 115, 0, 0 }, // 8 IntDivW
  { 1, 115, 116, 0, 0 }, // 9 LdStLoad
  { 1, 116, 117, 0, 0 }, // 10 FPGeneral
  { 1, 116, 117, 0, 0 }, // 11 FPAddSub
  { 1, 116, 117, 0, 0 }, // 12 FPCompare
  { 1, 117, 118, 0, 0 }, // 13 FPDivD
  { 1, 118, 119, 0, 0 }, // 14 FPDivS
  { 1, 119, 120, 0, 0 }, // 15 FPFused
  { 0, 0, 0, 0, 0 }, // 16 FPSqrt
  { 1, 113, 114, 0, 0 }, // 17 LdStICBI
  { 1, 120, 121, 0, 0 }, // 18 SprISYNC
  { 1, 115, 116, 0, 0 }, // 19 LdStLoadUpd
  { 0, 0, 0, 0, 0 }, // 20 LdStLD
  { 0, 0, 0, 0, 0 }, // 21 LdStLDARX
  { 0, 0, 0, 0, 0 }, // 22 LdStLDU
  { 1, 115, 116, 0, 0 }, // 23 LdStLFD
  { 1, 115, 116, 0, 0 }, // 24 LdStLFDU
  { 1, 115, 116, 0, 0 }, // 25 LdStLHA
  { 1, 115, 116, 0, 0 }, // 26 LdStLHAU
  { 1, 121, 122, 0, 0 }, // 27 LdStLMW
  { 0, 0, 0, 0, 0 }, // 28 LdStLWA
  { 1, 113, 114, 0, 0 }, // 29 LdStLWARX
  { 1, 112, 113, 0, 0 }, // 30 BrMCR
  { 1, 112, 113, 0, 0 }, // 31 SprMFCR
  { 1, 122, 123, 0, 0 }, // 32 SprMFSPR
  { 1, 116, 117, 0, 0 }, // 33 IntMFFS
  { 1, 112, 113, 0, 0 }, // 34 SprMFMSR
  { 1, 122, 123, 0, 0 }, // 35 SprMFTB
  { 1, 115, 116, 0, 0 }, // 36 LdStStore
  { 1, 112, 113, 0, 0 }, // 37 BrMCRX
  { 1, 120, 121, 0, 0 }, // 38 SprMTSPR
  { 1, 123, 124, 0, 0 }, // 39 IntMTFSB0
  { 1, 112, 113, 0, 0 }, // 40 SprMTMSR
  { 0, 0, 0, 0, 0 }, // 41 SprMTMSRD
  { 1, 124, 125, 0, 0 }, // 42 IntMulHW
  { 1, 125, 126, 0, 0 }, // 43 IntMulHWU
  { 0, 0, 0, 0, 0 }, // 44 IntMulHD
  { 1, 126, 127, 0, 0 }, // 45 IntMulLI
  { 0, 0, 0, 0, 0 }, // 46 IntRotateD
  { 0, 0, 0, 0, 0 }, // 47 IntRotateDI
  { 1, 110, 111, 0, 0 }, // 48 IntRotate
  { 0, 0, 0, 0, 0 }, // 49 SprSLBIA
  { 0, 0, 0, 0, 0 }, // 50 SprSLBIE
  { 0, 0, 0, 0, 0 }, // 51 SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 52 SprSLBMTE
  { 1, 110, 111, 0, 0 }, // 53 IntShift
  { 1, 115, 116, 0, 0 }, // 54 LdStStoreUpd
  { 0, 0, 0, 0, 0 }, // 55 LdStSTD
  { 0, 0, 0, 0, 0 }, // 56 LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 57 LdStSTDU
  { 1, 115, 116, 0, 0 }, // 58 LdStSTFD
  { 1, 115, 116, 0, 0 }, // 59 LdStSTFDU
  { 1, 127, 128, 0, 0 }, // 60 LdStSTWCX
  { 1, 113, 114, 0, 0 }, // 61 LdStSync
  { 0, 0, 0, 0, 0 }, // 62 IntTrapD
  { 0, 0, 0, 0, 0 }, // 63 SprTLBIE
  { 0, 0, 0, 0, 0 }, // 64 SprTLBIEL
  { 1, 122, 123, 0, 0 }, // 65 SprTLBSYNC
  { 1, 128, 129, 0, 0 }, // 66 IntTrapW
  { 0, 0, 0, 0, 0 }, // 67 VecFP
  { 0, 0, 0, 0, 0 }, // 68 VecGeneral
  { 0, 0, 0, 0, 0 }, // 69 VecFPCompare
  { 0, 0, 0, 0, 0 }, // 70 VecPerm
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary G4Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 129, 130, 0, 0 }, // 1 IntSimple
  { 1, 129, 130, 0, 0 }, // 2 IntGeneral
  { 1, 130, 131, 0, 0 }, // 3 BrB
  { 1, 129, 130, 0, 0 }, // 4 IntCompare
  { 1, 131, 132, 0, 0 }, // 5 BrCR
  { 1, 132, 133, 0, 0 }, // 6 LdStDCBF
  { 0, 0, 0, 0, 0 }, // 7 IntDivD
  { 1, 133, 134, 0, 0 }, // 8 IntDivW
  { 1, 132, 133, 0, 0 }, // 9 LdStLoad
  { 1, 134, 135, 0, 0 }, // 10 FPGeneral
  { 1, 134, 135, 0, 0 }, // 11 FPAddSub
  { 1, 134, 135, 0, 0 }, // 12 FPCompare
  { 1, 135, 136, 0, 0 }, // 13 FPDivD
  { 1, 136, 137, 0, 0 }, // 14 FPDivS
  { 1, 134, 135, 0, 0 }, // 15 FPFused
  { 0, 0, 0, 0, 0 }, // 16 FPSqrt
  { 1, 132, 133, 0, 0 }, // 17 LdStICBI
  { 1, 137, 138, 0, 0 }, // 18 SprISYNC
  { 1, 132, 133, 0, 0 }, // 19 LdStLoadUpd
  { 0, 0, 0, 0, 0 }, // 20 LdStLD
  { 0, 0, 0, 0, 0 }, // 21 LdStLDARX
  { 0, 0, 0, 0, 0 }, // 22 LdStLDU
  { 1, 132, 133, 0, 0 }, // 23 LdStLFD
  { 1, 132, 133, 0, 0 }, // 24 LdStLFDU
  { 1, 132, 133, 0, 0 }, // 25 LdStLHA
  { 1, 132, 133, 0, 0 }, // 26 LdStLHAU
  { 1, 138, 139, 0, 0 }, // 27 LdStLMW
  { 0, 0, 0, 0, 0 }, // 28 LdStLWA
  { 1, 139, 140, 0, 0 }, // 29 LdStLWARX
  { 1, 131, 132, 0, 0 }, // 30 BrMCR
  { 1, 131, 132, 0, 0 }, // 31 SprMFCR
  { 1, 140, 141, 0, 0 }, // 32 SprMFSPR
  { 1, 141, 142, 0, 0 }, // 33 IntMFFS
  { 1, 131, 132, 0, 0 }, // 34 SprMFMSR
  { 1, 131, 132, 0, 0 }, // 35 SprMFTB
  { 1, 132, 133, 0, 0 }, // 36 LdStStore
  { 1, 131, 132, 0, 0 }, // 37 BrMCRX
  { 1, 137, 138, 0, 0 }, // 38 SprMTSPR
  { 1, 141, 142, 0, 0 }, // 39 IntMTFSB0
  { 1, 131, 132, 0, 0 }, // 40 SprMTMSR
  { 0, 0, 0, 0, 0 }, // 41 SprMTMSRD
  { 1, 142, 143, 0, 0 }, // 42 IntMulHW
  { 1, 143, 144, 0, 0 }, // 43 IntMulHWU
  { 0, 0, 0, 0, 0 }, // 44 IntMulHD
  { 1, 144, 145, 0, 0 }, // 45 IntMulLI
  { 0, 0, 0, 0, 0 }, // 46 IntRotateD
  { 0, 0, 0, 0, 0 }, // 47 IntRotateDI
  { 1, 129, 130, 0, 0 }, // 48 IntRotate
  { 0, 0, 0, 0, 0 }, // 49 SprSLBIA
  { 0, 0, 0, 0, 0 }, // 50 SprSLBIE
  { 0, 0, 0, 0, 0 }, // 51 SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 52 SprSLBMTE
  { 1, 129, 130, 0, 0 }, // 53 IntShift
  { 1, 132, 133, 0, 0 }, // 54 LdStStoreUpd
  { 0, 0, 0, 0, 0 }, // 55 LdStSTD
  { 0, 0, 0, 0, 0 }, // 56 LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 57 LdStSTDU
  { 1, 132, 133, 0, 0 }, // 58 LdStSTFD
  { 1, 132, 133, 0, 0 }, // 59 LdStSTFDU
  { 1, 145, 146, 0, 0 }, // 60 LdStSTWCX
  { 1, 146, 147, 0, 0 }, // 61 LdStSync
  { 0, 0, 0, 0, 0 }, // 62 IntTrapD
  { 0, 0, 0, 0, 0 }, // 63 SprTLBIE
  { 0, 0, 0, 0, 0 }, // 64 SprTLBIEL
  { 1, 147, 148, 0, 0 }, // 65 SprTLBSYNC
  { 1, 148, 149, 0, 0 }, // 66 IntTrapW
  { 1, 149, 150, 0, 0 }, // 67 VecFP
  { 1, 150, 151, 0, 0 }, // 68 VecGeneral
  { 1, 150, 151, 0, 0 }, // 69 VecFPCompare
  { 1, 151, 152, 0, 0 }, // 70 VecPerm
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary G4PlusItineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 152, 153, 0, 0 }, // 1 IntSimple
  { 1, 152, 153, 0, 0 }, // 2 IntGeneral
  { 1, 153, 154, 0, 0 }, // 3 BrB
  { 1, 152, 153, 0, 0 }, // 4 IntCompare
  { 1, 154, 155, 0, 0 }, // 5 BrCR
  { 1, 155, 156, 0, 0 }, // 6 LdStDCBF
  { 0, 0, 0, 0, 0 }, // 7 IntDivD
  { 1, 156, 157, 0, 0 }, // 8 IntDivW
  { 1, 155, 156, 0, 0 }, // 9 LdStLoad
  { 1, 157, 158, 0, 0 }, // 10 FPGeneral
  { 1, 157, 158, 0, 0 }, // 11 FPAddSub
  { 1, 157, 158, 0, 0 }, // 12 FPCompare
  { 1, 158, 159, 0, 0 }, // 13 FPDivD
  { 1, 159, 160, 0, 0 }, // 14 FPDivS
  { 1, 157, 158, 0, 0 }, // 15 FPFused
  { 0, 0, 0, 0, 0 }, // 16 FPSqrt
  { 1, 160, 161, 0, 0 }, // 17 LdStICBI
  { 1, 161, 162, 0, 0 }, // 18 SprISYNC
  { 1, 155, 156, 0, 0 }, // 19 LdStLoadUpd
  { 0, 0, 0, 0, 0 }, // 20 LdStLD
  { 0, 0, 0, 0, 0 }, // 21 LdStLDARX
  { 0, 0, 0, 0, 0 }, // 22 LdStLDU
  { 1, 162, 163, 0, 0 }, // 23 LdStLFD
  { 1, 162, 163, 0, 0 }, // 24 LdStLFDU
  { 1, 155, 156, 0, 0 }, // 25 LdStLHA
  { 1, 155, 156, 0, 0 }, // 26 LdStLHAU
  { 1, 163, 164, 0, 0 }, // 27 LdStLMW
  { 1, 155, 156, 0, 0 }, // 28 LdStLWA
  { 1, 155, 156, 0, 0 }, // 29 LdStLWARX
  { 1, 154, 155, 0, 0 }, // 30 BrMCR
  { 1, 154, 155, 0, 0 }, // 31 SprMFCR
  { 1, 164, 165, 0, 0 }, // 32 SprMFSPR
  { 1, 157, 158, 0, 0 }, // 33 IntMFFS
  { 1, 160, 161, 0, 0 }, // 34 SprMFMSR
  { 1, 165, 166, 0, 0 }, // 35 SprMFTB
  { 1, 155, 156, 0, 0 }, // 36 LdStStore
  { 1, 154, 155, 0, 0 }, // 37 BrMCRX
  { 1, 154, 155, 0, 0 }, // 38 SprMTSPR
  { 1, 157, 158, 0, 0 }, // 39 IntMTFSB0
  { 1, 154, 155, 0, 0 }, // 40 SprMTMSR
  { 0, 0, 0, 0, 0 }, // 41 SprMTMSRD
  { 1, 164, 165, 0, 0 }, // 42 IntMulHW
  { 1, 164, 165, 0, 0 }, // 43 IntMulHWU
  { 0, 0, 0, 0, 0 }, // 44 IntMulHD
  { 1, 160, 161, 0, 0 }, // 45 IntMulLI
  { 0, 0, 0, 0, 0 }, // 46 IntRotateD
  { 0, 0, 0, 0, 0 }, // 47 IntRotateDI
  { 1, 152, 153, 0, 0 }, // 48 IntRotate
  { 0, 0, 0, 0, 0 }, // 49 SprSLBIA
  { 0, 0, 0, 0, 0 }, // 50 SprSLBIE
  { 0, 0, 0, 0, 0 }, // 51 SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 52 SprSLBMTE
  { 1, 166, 167, 0, 0 }, // 53 IntShift
  { 1, 155, 156, 0, 0 }, // 54 LdStStoreUpd
  { 1, 155, 156, 0, 0 }, // 55 LdStSTD
  { 1, 155, 156, 0, 0 }, // 56 LdStSTDCX
  { 1, 155, 156, 0, 0 }, // 57 LdStSTDU
  { 1, 155, 156, 0, 0 }, // 58 LdStSTFD
  { 1, 155, 156, 0, 0 }, // 59 LdStSTFDU
  { 1, 155, 156, 0, 0 }, // 60 LdStSTWCX
  { 1, 167, 168, 0, 0 }, // 61 LdStSync
  { 0, 0, 0, 0, 0 }, // 62 IntTrapD
  { 0, 0, 0, 0, 0 }, // 63 SprTLBIE
  { 0, 0, 0, 0, 0 }, // 64 SprTLBIEL
  { 1, 155, 156, 0, 0 }, // 65 SprTLBSYNC
  { 1, 166, 167, 0, 0 }, // 66 IntTrapW
  { 1, 168, 169, 0, 0 }, // 67 VecFP
  { 1, 169, 170, 0, 0 }, // 68 VecGeneral
  { 1, 170, 171, 0, 0 }, // 69 VecFPCompare
  { 1, 171, 172, 0, 0 }, // 70 VecPerm
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary G5Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 172, 173, 0, 0 }, // 1 IntSimple
  { 1, 172, 173, 0, 0 }, // 2 IntGeneral
  { 1, 173, 174, 0, 0 }, // 3 BrB
  { 1, 174, 175, 0, 0 }, // 4 IntCompare
  { 1, 175, 176, 0, 0 }, // 5 BrCR
  { 1, 176, 177, 0, 0 }, // 6 LdStDCBF
  { 1, 177, 178, 0, 0 }, // 7 IntDivD
  { 1, 178, 179, 0, 0 }, // 8 IntDivW
  { 1, 176, 177, 0, 0 }, // 9 LdStLoad
  { 1, 179, 180, 0, 0 }, // 10 FPGeneral
  { 1, 179, 180, 0, 0 }, // 11 FPAddSub
  { 1, 180, 181, 0, 0 }, // 12 FPCompare
  { 1, 181, 182, 0, 0 }, // 13 FPDivD
  { 1, 181, 182, 0, 0 }, // 14 FPDivS
  { 1, 179, 180, 0, 0 }, // 15 FPFused
  { 1, 182, 183, 0, 0 }, // 16 FPSqrt
  { 1, 183, 184, 0, 0 }, // 17 LdStICBI
  { 1, 183, 184, 0, 0 }, // 18 SprISYNC
  { 1, 176, 177, 0, 0 }, // 19 LdStLoadUpd
  { 1, 176, 177, 0, 0 }, // 20 LdStLD
  { 1, 184, 185, 0, 0 }, // 21 LdStLDARX
  { 1, 176, 177, 0, 0 }, // 22 LdStLDU
  { 1, 176, 177, 0, 0 }, // 23 LdStLFD
  { 1, 185, 186, 0, 0 }, // 24 LdStLFDU
  { 1, 185, 186, 0, 0 }, // 25 LdStLHA
  { 1, 185, 186, 0, 0 }, // 26 LdStLHAU
  { 1, 186, 187, 0, 0 }, // 27 LdStLMW
  { 1, 185, 186, 0, 0 }, // 28 LdStLWA
  { 1, 184, 185, 0, 0 }, // 29 LdStLWARX
  { 1, 187, 188, 0, 0 }, // 30 BrMCR
  { 1, 188, 189, 0, 0 }, // 31 SprMFCR
  { 1, 189, 190, 0, 0 }, // 32 SprMFSPR
  { 1, 190, 191, 0, 0 }, // 33 IntMFFS
  { 1, 189, 190, 0, 0 }, // 34 SprMFMSR
  { 1, 191, 192, 0, 0 }, // 35 SprMFTB
  { 1, 176, 177, 0, 0 }, // 36 LdStStore
  { 1, 192, 193, 0, 0 }, // 37 BrMCRX
  { 1, 193, 194, 0, 0 }, // 38 SprMTSPR
  { 1, 179, 180, 0, 0 }, // 39 IntMTFSB0
  { 1, 176, 177, 0, 0 }, // 40 SprMTMSR
  { 0, 0, 0, 0, 0 }, // 41 SprMTMSRD
  { 1, 194, 195, 0, 0 }, // 42 IntMulHW
  { 1, 194, 195, 0, 0 }, // 43 IntMulHWU
  { 1, 195, 196, 0, 0 }, // 44 IntMulHD
  { 1, 196, 197, 0, 0 }, // 45 IntMulLI
  { 1, 172, 173, 0, 0 }, // 46 IntRotateD
  { 1, 172, 173, 0, 0 }, // 47 IntRotateDI
  { 1, 196, 197, 0, 0 }, // 48 IntRotate
  { 0, 0, 0, 0, 0 }, // 49 SprSLBIA
  { 0, 0, 0, 0, 0 }, // 50 SprSLBIE
  { 0, 0, 0, 0, 0 }, // 51 SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 52 SprSLBMTE
  { 1, 172, 173, 0, 0 }, // 53 IntShift
  { 1, 176, 177, 0, 0 }, // 54 LdStStoreUpd
  { 1, 176, 177, 0, 0 }, // 55 LdStSTD
  { 1, 184, 185, 0, 0 }, // 56 LdStSTDCX
  { 1, 176, 177, 0, 0 }, // 57 LdStSTDU
  { 1, 197, 198, 0, 0 }, // 58 LdStSTFD
  { 1, 197, 198, 0, 0 }, // 59 LdStSTFDU
  { 1, 184, 185, 0, 0 }, // 60 LdStSTWCX
  { 1, 198, 199, 0, 0 }, // 61 LdStSync
  { 1, 199, 200, 0, 0 }, // 62 IntTrapD
  { 0, 0, 0, 0, 0 }, // 63 SprTLBIE
  { 0, 0, 0, 0, 0 }, // 64 SprTLBIEL
  { 1, 176, 177, 0, 0 }, // 65 SprTLBSYNC
  { 1, 199, 200, 0, 0 }, // 66 IntTrapW
  { 1, 200, 201, 0, 0 }, // 67 VecFP
  { 1, 201, 202, 0, 0 }, // 68 VecGeneral
  { 1, 202, 203, 0, 0 }, // 69 VecFPCompare
  { 1, 203, 204, 0, 0 }, // 70 VecPerm
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary PPCA2Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 204, 205, 118, 121 }, // 1 IntSimple
  { 1, 204, 205, 121, 124 }, // 2 IntGeneral
  { 1, 204, 205, 124, 127 }, // 3 BrB
  { 1, 204, 205, 127, 130 }, // 4 IntCompare
  { 1, 204, 205, 130, 133 }, // 5 BrCR
  { 1, 204, 205, 133, 136 }, // 6 LdStDCBF
  { 1, 204, 205, 136, 139 }, // 7 IntDivD
  { 1, 204, 205, 139, 142 }, // 8 IntDivW
  { 1, 204, 205, 142, 145 }, // 9 LdStLoad
  { 1, 205, 206, 145, 148 }, // 10 FPGeneral
  { 1, 205, 206, 148, 151 }, // 11 FPAddSub
  { 1, 205, 206, 151, 154 }, // 12 FPCompare
  { 1, 205, 206, 154, 157 }, // 13 FPDivD
  { 1, 205, 206, 157, 160 }, // 14 FPDivS
  { 1, 205, 206, 160, 164 }, // 15 FPFused
  { 1, 205, 206, 164, 167 }, // 16 FPSqrt
  { 1, 204, 205, 167, 170 }, // 17 LdStICBI
  { 1, 204, 205, 170, 171 }, // 18 SprISYNC
  { 1, 204, 205, 171, 175 }, // 19 LdStLoadUpd
  { 0, 0, 0, 0, 0 }, // 20 LdStLD
  { 0, 0, 0, 0, 0 }, // 21 LdStLDARX
  { 1, 204, 205, 175, 178 }, // 22 LdStLDU
  { 1, 204, 205, 178, 181 }, // 23 LdStLFD
  { 1, 204, 205, 181, 185 }, // 24 LdStLFDU
  { 1, 204, 205, 185, 188 }, // 25 LdStLHA
  { 1, 204, 205, 188, 192 }, // 26 LdStLHAU
  { 0, 0, 0, 0, 0 }, // 27 LdStLMW
  { 0, 0, 0, 0, 0 }, // 28 LdStLWA
  { 1, 204, 205, 192, 195 }, // 29 LdStLWARX
  { 1, 204, 205, 195, 198 }, // 30 BrMCR
  { 1, 204, 205, 198, 200 }, // 31 SprMFCR
  { 1, 204, 205, 200, 202 }, // 32 SprMFSPR
  { 0, 0, 0, 0, 0 }, // 33 IntMFFS
  { 1, 204, 205, 202, 204 }, // 34 SprMFMSR
  { 1, 204, 205, 204, 206 }, // 35 SprMFTB
  { 1, 204, 205, 206, 209 }, // 36 LdStStore
  { 1, 204, 205, 209, 212 }, // 37 BrMCRX
  { 1, 204, 205, 212, 214 }, // 38 SprMTSPR
  { 0, 0, 0, 0, 0 }, // 39 IntMTFSB0
  { 1, 204, 205, 214, 216 }, // 40 SprMTMSR
  { 0, 0, 0, 0, 0 }, // 41 SprMTMSRD
  { 1, 204, 205, 216, 219 }, // 42 IntMulHW
  { 1, 204, 205, 219, 222 }, // 43 IntMulHWU
  { 0, 0, 0, 0, 0 }, // 44 IntMulHD
  { 1, 204, 205, 222, 225 }, // 45 IntMulLI
  { 1, 204, 205, 225, 228 }, // 46 IntRotateD
  { 1, 204, 205, 228, 231 }, // 47 IntRotateDI
  { 1, 204, 205, 231, 234 }, // 48 IntRotate
  { 0, 0, 0, 0, 0 }, // 49 SprSLBIA
  { 0, 0, 0, 0, 0 }, // 50 SprSLBIE
  { 0, 0, 0, 0, 0 }, // 51 SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 52 SprSLBMTE
  { 1, 204, 205, 234, 237 }, // 53 IntShift
  { 1, 204, 205, 237, 241 }, // 54 LdStStoreUpd
  { 1, 204, 205, 241, 244 }, // 55 LdStSTD
  { 1, 204, 205, 244, 247 }, // 56 LdStSTDCX
  { 1, 204, 205, 247, 251 }, // 57 LdStSTDU
  { 1, 204, 205, 251, 254 }, // 58 LdStSTFD
  { 1, 204, 205, 254, 258 }, // 59 LdStSTFDU
  { 1, 204, 205, 258, 261 }, // 60 LdStSTWCX
  { 1, 204, 205, 261, 262 }, // 61 LdStSync
  { 1, 204, 205, 262, 264 }, // 62 IntTrapD
  { 0, 0, 0, 0, 0 }, // 63 SprTLBIE
  { 0, 0, 0, 0, 0 }, // 64 SprTLBIEL
  { 0, 0, 0, 0, 0 }, // 65 SprTLBSYNC
  { 1, 204, 205, 264, 266 }, // 66 IntTrapW
  { 0, 0, 0, 0, 0 }, // 67 VecFP
  { 0, 0, 0, 0, 0 }, // 68 VecGeneral
  { 0, 0, 0, 0, 0 }, // 69 VecFPCompare
  { 0, 0, 0, 0, 0 }, // 70 VecPerm
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary PPCE500mcItineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 206, 208, 266, 269 }, // 1 IntSimple
  { 1, 206, 208, 269, 272 }, // 2 IntGeneral
  { 1, 208, 210, 272, 274 }, // 3 BrB
  { 1, 206, 208, 274, 277 }, // 4 IntCompare
  { 1, 208, 210, 277, 280 }, // 5 BrCR
  { 1, 210, 212, 280, 282 }, // 6 LdStDCBF
  { 0, 0, 0, 0, 0 }, // 7 IntDivD
  { 1, 212, 215, 282, 285 }, // 8 IntDivW
  { 1, 210, 212, 285, 287 }, // 9 LdStLoad
  { 1, 215, 217, 287, 290 }, // 10 FPGeneral
  { 1, 217, 219, 290, 293 }, // 11 FPAddSub
  { 1, 215, 217, 293, 296 }, // 12 FPCompare
  { 1, 219, 221, 296, 299 }, // 13 FPDivD
  { 1, 221, 223, 299, 302 }, // 14 FPDivS
  { 1, 217, 219, 302, 306 }, // 15 FPFused
  { 0, 0, 0, 0, 0 }, // 16 FPSqrt
  { 1, 210, 212, 306, 308 }, // 17 LdStICBI
  { 0, 0, 0, 0, 0 }, // 18 SprISYNC
  { 2, 223, 226, 308, 310 }, // 19 LdStLoadUpd
  { 0, 0, 0, 0, 0 }, // 20 LdStLD
  { 0, 0, 0, 0, 0 }, // 21 LdStLDARX
  { 0, 0, 0, 0, 0 }, // 22 LdStLDU
  { 1, 210, 212, 310, 313 }, // 23 LdStLFD
  { 2, 223, 226, 313, 316 }, // 24 LdStLFDU
  { 1, 210, 212, 316, 318 }, // 25 LdStLHA
  { 1, 223, 226, 318, 320 }, // 26 LdStLHAU
  { 1, 210, 212, 320, 322 }, // 27 LdStLMW
  { 0, 0, 0, 0, 0 }, // 28 LdStLWA
  { 1, 226, 228, 322, 325 }, // 29 LdStLWARX
  { 1, 208, 210, 325, 327 }, // 30 BrMCR
  { 1, 228, 230, 327, 329 }, // 31 SprMFCR
  { 1, 206, 208, 329, 331 }, // 32 SprMFSPR
  { 1, 230, 232, 331, 332 }, // 33 IntMFFS
  { 1, 232, 234, 332, 334 }, // 34 SprMFMSR
  { 1, 232, 234, 334, 336 }, // 35 SprMFTB
  { 1, 210, 212, 336, 338 }, // 36 LdStStore
  { 1, 206, 208, 338, 341 }, // 37 BrMCRX
  { 1, 206, 208, 341, 343 }, // 38 SprMTSPR
  { 1, 230, 232, 343, 346 }, // 39 IntMTFSB0
  { 1, 234, 236, 346, 348 }, // 40 SprMTMSR
  { 0, 0, 0, 0, 0 }, // 41 SprMTMSRD
  { 1, 236, 238, 348, 351 }, // 42 IntMulHW
  { 1, 236, 238, 351, 354 }, // 43 IntMulHWU
  { 0, 0, 0, 0, 0 }, // 44 IntMulHD
  { 1, 236, 238, 354, 357 }, // 45 IntMulLI
  { 0, 0, 0, 0, 0 }, // 46 IntRotateD
  { 0, 0, 0, 0, 0 }, // 47 IntRotateDI
  { 1, 206, 208, 357, 360 }, // 48 IntRotate
  { 0, 0, 0, 0, 0 }, // 49 SprSLBIA
  { 0, 0, 0, 0, 0 }, // 50 SprSLBIE
  { 0, 0, 0, 0, 0 }, // 51 SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 52 SprSLBMTE
  { 1, 206, 208, 360, 363 }, // 53 IntShift
  { 2, 223, 226, 363, 365 }, // 54 LdStStoreUpd
  { 0, 0, 0, 0, 0 }, // 55 LdStSTD
  { 0, 0, 0, 0, 0 }, // 56 LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 57 LdStSTDU
  { 1, 210, 212, 365, 368 }, // 58 LdStSTFD
  { 2, 223, 226, 368, 371 }, // 59 LdStSTFDU
  { 1, 210, 212, 371, 373 }, // 60 LdStSTWCX
  { 1, 210, 212, 0, 0 }, // 61 LdStSync
  { 0, 0, 0, 0, 0 }, // 62 IntTrapD
  { 0, 0, 0, 0, 0 }, // 63 SprTLBIE
  { 0, 0, 0, 0, 0 }, // 64 SprTLBIEL
  { 1, 238, 240, 0, 0 }, // 65 SprTLBSYNC
  { 1, 240, 242, 373, 375 }, // 66 IntTrapW
  { 0, 0, 0, 0, 0 }, // 67 VecFP
  { 0, 0, 0, 0, 0 }, // 68 VecGeneral
  { 0, 0, 0, 0, 0 }, // 69 VecFPCompare
  { 0, 0, 0, 0, 0 }, // 70 VecPerm
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary PPCE5500Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 242, 244, 375, 378 }, // 1 IntSimple
  { 1, 242, 244, 378, 381 }, // 2 IntGeneral
  { 1, 244, 246, 381, 383 }, // 3 BrB
  { 1, 242, 244, 383, 386 }, // 4 IntCompare
  { 1, 244, 246, 386, 389 }, // 5 BrCR
  { 1, 246, 248, 389, 391 }, // 6 LdStDCBF
  { 1, 248, 251, 391, 394 }, // 7 IntDivD
  { 1, 251, 254, 394, 397 }, // 8 IntDivW
  { 1, 246, 248, 397, 399 }, // 9 LdStLoad
  { 1, 254, 256, 399, 402 }, // 10 FPGeneral
  { 1, 254, 256, 402, 405 }, // 11 FPAddSub
  { 1, 254, 256, 405, 408 }, // 12 FPCompare
  { 1, 256, 258, 408, 411 }, // 13 FPDivD
  { 1, 258, 260, 411, 414 }, // 14 FPDivS
  { 1, 254, 256, 414, 418 }, // 15 FPFused
  { 0, 0, 0, 0, 0 }, // 16 FPSqrt
  { 1, 246, 248, 418, 420 }, // 17 LdStICBI
  { 0, 0, 0, 0, 0 }, // 18 SprISYNC
  { 2, 260, 263, 420, 422 }, // 19 LdStLoadUpd
  { 1, 246, 248, 422, 424 }, // 20 LdStLD
  { 1, 263, 265, 424, 426 }, // 21 LdStLDARX
  { 2, 260, 263, 426, 428 }, // 22 LdStLDU
  { 2, 246, 248, 428, 431 }, // 23 LdStLFD
  { 2, 260, 263, 431, 434 }, // 24 LdStLFDU
  { 1, 246, 248, 434, 436 }, // 25 LdStLHA
  { 2, 260, 263, 436, 438 }, // 26 LdStLHAU
  { 1, 265, 267, 438, 440 }, // 27 LdStLMW
  { 0, 0, 0, 0, 0 }, // 28 LdStLWA
  { 1, 263, 265, 440, 443 }, // 29 LdStLWARX
  { 1, 244, 246, 443, 445 }, // 30 BrMCR
  { 1, 267, 269, 445, 447 }, // 31 SprMFCR
  { 1, 269, 271, 447, 448 }, // 32 SprMFSPR
  { 1, 254, 256, 448, 449 }, // 33 IntMFFS
  { 1, 271, 273, 449, 451 }, // 34 SprMFMSR
  { 1, 273, 275, 451, 453 }, // 35 SprMFTB
  { 1, 246, 248, 453, 455 }, // 36 LdStStore
  { 1, 269, 271, 455, 458 }, // 37 BrMCRX
  { 1, 242, 244, 458, 459 }, // 38 SprMTSPR
  { 1, 275, 277, 459, 462 }, // 39 IntMTFSB0
  { 1, 277, 279, 462, 464 }, // 40 SprMTMSR
  { 0, 0, 0, 0, 0 }, // 41 SprMTMSRD
  { 1, 279, 282, 464, 467 }, // 42 IntMulHW
  { 1, 279, 282, 467, 470 }, // 43 IntMulHWU
  { 1, 282, 285, 470, 473 }, // 44 IntMulHD
  { 1, 282, 285, 473, 476 }, // 45 IntMulLI
  { 1, 285, 287, 476, 479 }, // 46 IntRotateD
  { 1, 242, 244, 479, 482 }, // 47 IntRotateDI
  { 1, 242, 244, 482, 485 }, // 48 IntRotate
  { 0, 0, 0, 0, 0 }, // 49 SprSLBIA
  { 0, 0, 0, 0, 0 }, // 50 SprSLBIE
  { 0, 0, 0, 0, 0 }, // 51 SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 52 SprSLBMTE
  { 1, 285, 287, 485, 488 }, // 53 IntShift
  { 2, 260, 263, 488, 490 }, // 54 LdStStoreUpd
  { 1, 246, 248, 490, 492 }, // 55 LdStSTD
  { 1, 246, 248, 492, 494 }, // 56 LdStSTDCX
  { 2, 260, 263, 494, 496 }, // 57 LdStSTDU
  { 1, 246, 248, 496, 499 }, // 58 LdStSTFD
  { 2, 260, 263, 499, 502 }, // 59 LdStSTFDU
  { 1, 246, 248, 502, 504 }, // 60 LdStSTWCX
  { 1, 246, 248, 0, 0 }, // 61 LdStSync
  { 0, 0, 0, 0, 0 }, // 62 IntTrapD
  { 0, 0, 0, 0, 0 }, // 63 SprTLBIE
  { 0, 0, 0, 0, 0 }, // 64 SprTLBIEL
  { 1, 287, 289, 0, 0 }, // 65 SprTLBSYNC
  { 1, 289, 291, 504, 506 }, // 66 IntTrapW
  { 0, 0, 0, 0, 0 }, // 67 VecFP
  { 0, 0, 0, 0, 0 }, // 68 VecGeneral
  { 0, 0, 0, 0, 0 }, // 69 VecFPCompare
  { 0, 0, 0, 0, 0 }, // 70 VecPerm
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

// ===============================================================
// Data tables for the new per-operand machine model.

// {ProcResourceIdx, Cycles}
extern const llvm::MCWriteProcResEntry PPCWriteProcResTable[] = {
  { 0,  0}, // Invalid
}; // PPCWriteProcResTable

// {Cycles, WriteResourceID}
extern const llvm::MCWriteLatencyEntry PPCWriteLatencyTable[] = {
  { 0,  0}, // Invalid
}; // PPCWriteLatencyTable

// {UseIdx, WriteResourceID, Cycles}
extern const llvm::MCReadAdvanceEntry PPCReadAdvanceTable[] = {
  {0,  0,  0}, // Invalid
}; // PPCReadAdvanceTable

static const llvm::MCSchedModel NoSchedModel(
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  1, // CompleteModel
  0, // Processor ID
  0, 0, 0, 0, // No instruction-level machine model.
  NoItineraries);

static const llvm::MCSchedModel PPC440ItinerariesModel(
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  1, // CompleteModel
  1, // Processor ID
  0, 0, 0, 0, // No instruction-level machine model.
  PPC440Itineraries);

static const llvm::MCSchedModel G3ItinerariesModel(
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  1, // CompleteModel
  2, // Processor ID
  0, 0, 0, 0, // No instruction-level machine model.
  G3Itineraries);

static const llvm::MCSchedModel G4ItinerariesModel(
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  1, // CompleteModel
  3, // Processor ID
  0, 0, 0, 0, // No instruction-level machine model.
  G4Itineraries);

static const llvm::MCSchedModel G4PlusItinerariesModel(
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  1, // CompleteModel
  4, // Processor ID
  0, 0, 0, 0, // No instruction-level machine model.
  G4PlusItineraries);

static const llvm::MCSchedModel G5Model(
  4, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  3, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  16, // MispredictPenalty
  1, // CompleteModel
  5, // Processor ID
  0, 0, 0, 0, // No instruction-level machine model.
  G5Itineraries);

static const llvm::MCSchedModel PPCA2Model(
  1, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  6, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  13, // MispredictPenalty
  1, // CompleteModel
  6, // Processor ID
  0, 0, 0, 0, // No instruction-level machine model.
  PPCA2Itineraries);

static const llvm::MCSchedModel PPCE500mcModel(
  2, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  5, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  1, // CompleteModel
  7, // Processor ID
  0, 0, 0, 0, // No instruction-level machine model.
  PPCE500mcItineraries);

static const llvm::MCSchedModel PPCE5500Model(
  2, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  6, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  1, // CompleteModel
  8, // Processor ID
  0, 0, 0, 0, // No instruction-level machine model.
  PPCE5500Itineraries);

// Sorted (by key) array of itineraries for CPU subtype.
extern const llvm::SubtargetInfoKV PPCProcSchedKV[] = {
  { "440", (const void *)&PPC440ItinerariesModel },
  { "450", (const void *)&PPC440ItinerariesModel },
  { "601", (const void *)&G3ItinerariesModel },
  { "602", (const void *)&G3ItinerariesModel },
  { "603", (const void *)&G3ItinerariesModel },
  { "603e", (const void *)&G3ItinerariesModel },
  { "603ev", (const void *)&G3ItinerariesModel },
  { "604", (const void *)&G3ItinerariesModel },
  { "604e", (const void *)&G3ItinerariesModel },
  { "620", (const void *)&G3ItinerariesModel },
  { "7400", (const void *)&G4ItinerariesModel },
  { "7450", (const void *)&G4PlusItinerariesModel },
  { "750", (const void *)&G4ItinerariesModel },
  { "970", (const void *)&G5Model },
  { "a2", (const void *)&PPCA2Model },
  { "a2q", (const void *)&PPCA2Model },
  { "e500mc", (const void *)&PPCE500mcModel },
  { "e5500", (const void *)&PPCE5500Model },
  { "g3", (const void *)&G3ItinerariesModel },
  { "g4", (const void *)&G4ItinerariesModel },
  { "g4+", (const void *)&G4PlusItinerariesModel },
  { "g5", (const void *)&G5Model },
  { "generic", (const void *)&G3ItinerariesModel },
  { "ppc", (const void *)&G3ItinerariesModel },
  { "ppc64", (const void *)&G5Model },
  { "ppc64le", (const void *)&G5Model },
  { "pwr3", (const void *)&G5Model },
  { "pwr4", (const void *)&G5Model },
  { "pwr5", (const void *)&G5Model },
  { "pwr5x", (const void *)&G5Model },
  { "pwr6", (const void *)&G5Model },
  { "pwr6x", (const void *)&G5Model },
  { "pwr7", (const void *)&G5Model }
};
#undef DBGFIELD
static inline void InitPPCMCSubtargetInfo(MCSubtargetInfo *II, StringRef TT, StringRef CPU, StringRef FS) {
  II->InitMCSubtargetInfo(TT, CPU, FS, PPCFeatureKV, PPCSubTypeKV, 
                      PPCProcSchedKV, PPCWriteProcResTable, PPCWriteLatencyTable, PPCReadAdvanceTable, 
                      PPCStages, PPCOperandCycles, PPCForwardingPaths, 21, 33);
}

} // End llvm namespace 
#endif // GET_SUBTARGETINFO_MC_DESC


#ifdef GET_SUBTARGETINFO_TARGET_DESC
#undef GET_SUBTARGETINFO_TARGET_DESC
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
// ParseSubtargetFeatures - Parses features string setting specified
// subtarget options.
void llvm::PPCSubtarget::ParseSubtargetFeatures(StringRef CPU, StringRef FS) {
  DEBUG(dbgs() << "\nFeatures:" << FS);
  DEBUG(dbgs() << "\nCPU:" << CPU << "\n\n");
  InitMCProcessorInfo(CPU, FS);
  uint64_t Bits = getFeatureBits();
  if ((Bits & PPC::DeprecatedDST) != 0) DeprecatedDST = true;
  if ((Bits & PPC::DeprecatedMFTB) != 0) DeprecatedMFTB = true;
  if ((Bits & PPC::Directive32) != 0 && DarwinDirective < PPC::DIR_32) DarwinDirective = PPC::DIR_32;
  if ((Bits & PPC::Directive64) != 0 && DarwinDirective < PPC::DIR_64) DarwinDirective = PPC::DIR_64;
  if ((Bits & PPC::Directive440) != 0 && DarwinDirective < PPC::DIR_440) DarwinDirective = PPC::DIR_440;
  if ((Bits & PPC::Directive601) != 0 && DarwinDirective < PPC::DIR_601) DarwinDirective = PPC::DIR_601;
  if ((Bits & PPC::Directive602) != 0 && DarwinDirective < PPC::DIR_602) DarwinDirective = PPC::DIR_602;
  if ((Bits & PPC::Directive603) != 0 && DarwinDirective < PPC::DIR_603) DarwinDirective = PPC::DIR_603;
  if ((Bits & PPC::Directive604) != 0 && DarwinDirective < PPC::DIR_603) DarwinDirective = PPC::DIR_603;
  if ((Bits & PPC::Directive620) != 0 && DarwinDirective < PPC::DIR_603) DarwinDirective = PPC::DIR_603;
  if ((Bits & PPC::Directive750) != 0 && DarwinDirective < PPC::DIR_750) DarwinDirective = PPC::DIR_750;
  if ((Bits & PPC::Directive970) != 0 && DarwinDirective < PPC::DIR_970) DarwinDirective = PPC::DIR_970;
  if ((Bits & PPC::Directive7400) != 0 && DarwinDirective < PPC::DIR_7400) DarwinDirective = PPC::DIR_7400;
  if ((Bits & PPC::DirectiveA2) != 0 && DarwinDirective < PPC::DIR_A2) DarwinDirective = PPC::DIR_A2;
  if ((Bits & PPC::DirectiveE500mc) != 0 && DarwinDirective < PPC::DIR_E500mc) DarwinDirective = PPC::DIR_E500mc;
  if ((Bits & PPC::DirectiveE5500) != 0 && DarwinDirective < PPC::DIR_E5500) DarwinDirective = PPC::DIR_E5500;
  if ((Bits & PPC::DirectivePwr3) != 0 && DarwinDirective < PPC::DIR_PWR3) DarwinDirective = PPC::DIR_PWR3;
  if ((Bits & PPC::DirectivePwr4) != 0 && DarwinDirective < PPC::DIR_PWR4) DarwinDirective = PPC::DIR_PWR4;
  if ((Bits & PPC::DirectivePwr5) != 0 && DarwinDirective < PPC::DIR_PWR5) DarwinDirective = PPC::DIR_PWR5;
  if ((Bits & PPC::DirectivePwr5x) != 0 && DarwinDirective < PPC::DIR_PWR5X) DarwinDirective = PPC::DIR_PWR5X;
  if ((Bits & PPC::DirectivePwr6) != 0 && DarwinDirective < PPC::DIR_PWR6) DarwinDirective = PPC::DIR_PWR6;
  if ((Bits & PPC::DirectivePwr6x) != 0 && DarwinDirective < PPC::DIR_PWR6X) DarwinDirective = PPC::DIR_PWR6X;
  if ((Bits & PPC::DirectivePwr7) != 0 && DarwinDirective < PPC::DIR_PWR7) DarwinDirective = PPC::DIR_PWR7;
  if ((Bits & PPC::Feature64Bit) != 0) Has64BitSupport = true;
  if ((Bits & PPC::Feature64BitRegs) != 0) Use64BitRegs = true;
  if ((Bits & PPC::FeatureAltivec) != 0) HasAltivec = true;
  if ((Bits & PPC::FeatureBookE) != 0) IsBookE = true;
  if ((Bits & PPC::FeatureFCPSGN) != 0) HasFCPSGN = true;
  if ((Bits & PPC::FeatureFPCVT) != 0) HasFPCVT = true;
  if ((Bits & PPC::FeatureFPRND) != 0) HasFPRND = true;
  if ((Bits & PPC::FeatureFRE) != 0) HasFRE = true;
  if ((Bits & PPC::FeatureFRES) != 0) HasFRES = true;
  if ((Bits & PPC::FeatureFRSQRTE) != 0) HasFRSQRTE = true;
  if ((Bits & PPC::FeatureFRSQRTES) != 0) HasFRSQRTES = true;
  if ((Bits & PPC::FeatureFSqrt) != 0) HasFSQRT = true;
  if ((Bits & PPC::FeatureISEL) != 0) HasISEL = true;
  if ((Bits & PPC::FeatureLDBRX) != 0) HasLDBRX = true;
  if ((Bits & PPC::FeatureLFIWAX) != 0) HasLFIWAX = true;
  if ((Bits & PPC::FeatureMFOCRF) != 0) HasMFOCRF = true;
  if ((Bits & PPC::FeaturePOPCNTD) != 0) HasPOPCNTD = true;
  if ((Bits & PPC::FeatureQPX) != 0) HasQPX = true;
  if ((Bits & PPC::FeatureRecipPrec) != 0) HasRecipPrec = true;
  if ((Bits & PPC::FeatureSTFIWX) != 0) HasSTFIWX = true;
  if ((Bits & PPC::FeatureVSX) != 0) HasVSX = true;
}
#endif // GET_SUBTARGETINFO_TARGET_DESC


#ifdef GET_SUBTARGETINFO_HEADER
#undef GET_SUBTARGETINFO_HEADER
namespace llvm {
class DFAPacketizer;
struct PPCGenSubtargetInfo : public TargetSubtargetInfo {
  explicit PPCGenSubtargetInfo(StringRef TT, StringRef CPU, StringRef FS);
public:
  unsigned resolveSchedClass(unsigned SchedClass, const MachineInstr *DefMI, const TargetSchedModel *SchedModel) const;
  DFAPacketizer *createDFAPacketizer(const InstrItineraryData *IID) const;
};
} // End llvm namespace 
#endif // GET_SUBTARGETINFO_HEADER


#ifdef GET_SUBTARGETINFO_CTOR
#undef GET_SUBTARGETINFO_CTOR
#include "llvm/CodeGen/TargetSchedule.h"
namespace llvm {
extern const llvm::SubtargetFeatureKV PPCFeatureKV[];
extern const llvm::SubtargetFeatureKV PPCSubTypeKV[];
extern const llvm::SubtargetInfoKV PPCProcSchedKV[];
extern const llvm::MCWriteProcResEntry PPCWriteProcResTable[];
extern const llvm::MCWriteLatencyEntry PPCWriteLatencyTable[];
extern const llvm::MCReadAdvanceEntry PPCReadAdvanceTable[];
extern const llvm::InstrStage PPCStages[];
extern const unsigned PPCOperandCycles[];
extern const unsigned PPCForwardingPaths[];
PPCGenSubtargetInfo::PPCGenSubtargetInfo(StringRef TT, StringRef CPU, StringRef FS)
  : TargetSubtargetInfo() {
  InitMCSubtargetInfo(TT, CPU, FS, PPCFeatureKV, PPCSubTypeKV, 
                      PPCProcSchedKV, PPCWriteProcResTable, PPCWriteLatencyTable, PPCReadAdvanceTable, 
                      PPCStages, PPCOperandCycles, PPCForwardingPaths, 21, 33);
}

unsigned PPCGenSubtargetInfo
::resolveSchedClass(unsigned SchedClass, const MachineInstr *MI, const TargetSchedModel *SchedModel) const {
  report_fatal_error("Expected a variant SchedClass");
} // PPCGenSubtargetInfo::resolveSchedClass
} // End llvm namespace 
#endif // GET_SUBTARGETINFO_CTOR


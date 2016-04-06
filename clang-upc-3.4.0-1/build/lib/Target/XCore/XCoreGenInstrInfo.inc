/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Target Instruction Enum Values                                              *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_INSTRINFO_ENUM
#undef GET_INSTRINFO_ENUM
namespace llvm {

namespace XCore {
  enum {
    PHI	= 0,
    INLINEASM	= 1,
    PROLOG_LABEL	= 2,
    EH_LABEL	= 3,
    GC_LABEL	= 4,
    KILL	= 5,
    EXTRACT_SUBREG	= 6,
    INSERT_SUBREG	= 7,
    IMPLICIT_DEF	= 8,
    SUBREG_TO_REG	= 9,
    COPY_TO_REGCLASS	= 10,
    DBG_VALUE	= 11,
    REG_SEQUENCE	= 12,
    COPY	= 13,
    BUNDLE	= 14,
    LIFETIME_START	= 15,
    LIFETIME_END	= 16,
    STACKMAP	= 17,
    PATCHPOINT	= 18,
    ADD_2rus	= 19,
    ADD_3r	= 20,
    ADJCALLSTACKDOWN	= 21,
    ADJCALLSTACKUP	= 22,
    ANDNOT_2r	= 23,
    AND_3r	= 24,
    ASHR_l2rus	= 25,
    ASHR_l3r	= 26,
    BAU_1r	= 27,
    BITREV_l2r	= 28,
    BLACP_lu10	= 29,
    BLACP_u10	= 30,
    BLAT_lu6	= 31,
    BLAT_u6	= 32,
    BLA_1r	= 33,
    BLRB_lu10	= 34,
    BLRB_u10	= 35,
    BLRF_lu10	= 36,
    BLRF_u10	= 37,
    BRBF_lru6	= 38,
    BRBF_ru6	= 39,
    BRBT_lru6	= 40,
    BRBT_ru6	= 41,
    BRBU_lu6	= 42,
    BRBU_u6	= 43,
    BRFF_lru6	= 44,
    BRFF_ru6	= 45,
    BRFT_lru6	= 46,
    BRFT_ru6	= 47,
    BRFU_lu6	= 48,
    BRFU_u6	= 49,
    BRU_1r	= 50,
    BR_JT	= 51,
    BR_JT32	= 52,
    BYTEREV_l2r	= 53,
    CHKCT_2r	= 54,
    CHKCT_rus	= 55,
    CLRE_0R	= 56,
    CLRPT_1R	= 57,
    CLRSR_branch_lu6	= 58,
    CLRSR_branch_u6	= 59,
    CLRSR_lu6	= 60,
    CLRSR_u6	= 61,
    CLZ_l2r	= 62,
    CRC8_l4r	= 63,
    CRC_l3r	= 64,
    DCALL_0R	= 65,
    DENTSP_0R	= 66,
    DGETREG_1r	= 67,
    DIVS_l3r	= 68,
    DIVU_l3r	= 69,
    DRESTSP_0R	= 70,
    DRET_0R	= 71,
    ECALLF_1r	= 72,
    ECALLT_1r	= 73,
    EDU_1r	= 74,
    EEF_2r	= 75,
    EET_2r	= 76,
    EEU_1r	= 77,
    ENDIN_2r	= 78,
    ENTSP_lu6	= 79,
    ENTSP_u6	= 80,
    EQ_2rus	= 81,
    EQ_3r	= 82,
    EXTDP_lu6	= 83,
    EXTDP_u6	= 84,
    EXTSP_lu6	= 85,
    EXTSP_u6	= 86,
    FREER_1r	= 87,
    FREET_0R	= 88,
    GETD_l2r	= 89,
    GETED_0R	= 90,
    GETET_0R	= 91,
    GETID_0R	= 92,
    GETKEP_0R	= 93,
    GETKSP_0R	= 94,
    GETN_l2r	= 95,
    GETPS_l2r	= 96,
    GETR_rus	= 97,
    GETSR_lu6	= 98,
    GETSR_u6	= 99,
    GETST_2r	= 100,
    GETTS_2r	= 101,
    INCT_2r	= 102,
    INITCP_2r	= 103,
    INITDP_2r	= 104,
    INITLR_l2r	= 105,
    INITPC_2r	= 106,
    INITSP_2r	= 107,
    INPW_l2rus	= 108,
    INSHR_2r	= 109,
    INT_2r	= 110,
    IN_2r	= 111,
    Int_MemBarrier	= 112,
    KCALL_1r	= 113,
    KCALL_lu6	= 114,
    KCALL_u6	= 115,
    KENTSP_lu6	= 116,
    KENTSP_u6	= 117,
    KRESTSP_lu6	= 118,
    KRESTSP_u6	= 119,
    KRET_0R	= 120,
    LADD_l5r	= 121,
    LD16S_3r	= 122,
    LD8U_3r	= 123,
    LDA16B_l3r	= 124,
    LDA16F_l3r	= 125,
    LDAPB_lu10	= 126,
    LDAPB_u10	= 127,
    LDAPF_lu10	= 128,
    LDAPF_lu10_ba	= 129,
    LDAPF_u10	= 130,
    LDAWB_l2rus	= 131,
    LDAWB_l3r	= 132,
    LDAWCP_lu6	= 133,
    LDAWCP_u6	= 134,
    LDAWDP_lru6	= 135,
    LDAWDP_ru6	= 136,
    LDAWFI	= 137,
    LDAWF_l2rus	= 138,
    LDAWF_l3r	= 139,
    LDAWSP_lru6	= 140,
    LDAWSP_ru6	= 141,
    LDC_lru6	= 142,
    LDC_ru6	= 143,
    LDET_0R	= 144,
    LDIVU_l5r	= 145,
    LDSED_0R	= 146,
    LDSPC_0R	= 147,
    LDSSR_0R	= 148,
    LDWCP_lru6	= 149,
    LDWCP_lu10	= 150,
    LDWCP_ru6	= 151,
    LDWCP_u10	= 152,
    LDWDP_lru6	= 153,
    LDWDP_ru6	= 154,
    LDWFI	= 155,
    LDWSP_lru6	= 156,
    LDWSP_ru6	= 157,
    LDW_2rus	= 158,
    LDW_3r	= 159,
    LMUL_l6r	= 160,
    LSS_3r	= 161,
    LSUB_l5r	= 162,
    LSU_3r	= 163,
    MACCS_l4r	= 164,
    MACCU_l4r	= 165,
    MJOIN_1r	= 166,
    MKMSK_2r	= 167,
    MKMSK_rus	= 168,
    MSYNC_1r	= 169,
    MUL_l3r	= 170,
    NEG	= 171,
    NOT	= 172,
    OR_3r	= 173,
    OUTCT_2r	= 174,
    OUTCT_rus	= 175,
    OUTPW_l2rus	= 176,
    OUTSHR_2r	= 177,
    OUTT_2r	= 178,
    OUT_2r	= 179,
    PEEK_2r	= 180,
    REMS_l3r	= 181,
    REMU_l3r	= 182,
    RETSP_lu6	= 183,
    RETSP_u6	= 184,
    SELECT_CC	= 185,
    SETCLK_l2r	= 186,
    SETCP_1r	= 187,
    SETC_l2r	= 188,
    SETC_lru6	= 189,
    SETC_ru6	= 190,
    SETDP_1r	= 191,
    SETD_2r	= 192,
    SETEV_1r	= 193,
    SETKEP_0R	= 194,
    SETN_l2r	= 195,
    SETPSC_2r	= 196,
    SETPS_l2r	= 197,
    SETPT_2r	= 198,
    SETRDY_l2r	= 199,
    SETSP_1r	= 200,
    SETSR_branch_lu6	= 201,
    SETSR_branch_u6	= 202,
    SETSR_lu6	= 203,
    SETSR_u6	= 204,
    SETTW_l2r	= 205,
    SETV_1r	= 206,
    SEXT_2r	= 207,
    SEXT_rus	= 208,
    SHL_2rus	= 209,
    SHL_3r	= 210,
    SHR_2rus	= 211,
    SHR_3r	= 212,
    SSYNC_0r	= 213,
    ST16_l3r	= 214,
    ST8_l3r	= 215,
    STET_0R	= 216,
    STSED_0R	= 217,
    STSPC_0R	= 218,
    STSSR_0R	= 219,
    STWDP_lru6	= 220,
    STWDP_ru6	= 221,
    STWFI	= 222,
    STWSP_lru6	= 223,
    STWSP_ru6	= 224,
    STW_2rus	= 225,
    STW_l3r	= 226,
    SUB_2rus	= 227,
    SUB_3r	= 228,
    SYNCR_1r	= 229,
    TESTCT_2r	= 230,
    TESTLCL_l2r	= 231,
    TESTWCT_2r	= 232,
    TSETMR_2r	= 233,
    TSETR_3r	= 234,
    TSTART_1R	= 235,
    WAITEF_1R	= 236,
    WAITET_1R	= 237,
    WAITEU_0R	= 238,
    XOR_l3r	= 239,
    ZEXT_2r	= 240,
    ZEXT_rus	= 241,
    INSTRUCTION_LIST_END = 242
  };
namespace Sched {
  enum {
    NoInstrModel	= 0,
    SCHED_LIST_END = 1
  };
}
}
} // End llvm namespace 
#endif // GET_INSTRINFO_ENUM

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Target Instruction Descriptors                                              *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_INSTRINFO_MC_DESC
#undef GET_INSTRINFO_MC_DESC
namespace llvm {

static const uint16_t ImplicitList1[] = { XCore::SP, 0 };
static const uint16_t ImplicitList2[] = { XCore::R0, XCore::R1, XCore::R2, XCore::R3, XCore::R11, XCore::LR, 0 };
static const uint16_t ImplicitList3[] = { XCore::R11, 0 };

static const MCOperandInfo OperandInfo2[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo3[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo4[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo5[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo6[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo7[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo8[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo9[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo10[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo11[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo12[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo13[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo14[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo15[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo16[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo17[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo18[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((1 << 16) | (1 << MCOI::TIED_TO)) }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo19[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo20[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo21[] = { { XCore::RRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo22[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo23[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo24[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((1 << 16) | (1 << MCOI::TIED_TO)) }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo25[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo26[] = { { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo27[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo28[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { XCore::GRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };

extern const MCInstrDesc XCoreInsts[] = {
  { 0,	0,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Variadic)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, 0,0,0 },  // Inst #0 = PHI
  { 1,	0,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Variadic), 0x0ULL, NULL, NULL, 0,0,0 },  // Inst #1 = INLINEASM
  { 2,	1,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::NotDuplicable)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #2 = PROLOG_LABEL
  { 3,	1,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::NotDuplicable)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #3 = EH_LABEL
  { 4,	1,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::NotDuplicable)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #4 = GC_LABEL
  { 5,	0,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Variadic), 0x0ULL, NULL, NULL, 0,0,0 },  // Inst #5 = KILL
  { 6,	3,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo3,0,0 },  // Inst #6 = EXTRACT_SUBREG
  { 7,	4,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo4,0,0 },  // Inst #7 = INSERT_SUBREG
  { 8,	1,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #8 = IMPLICIT_DEF
  { 9,	4,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo6,0,0 },  // Inst #9 = SUBREG_TO_REG
  { 10,	3,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo3,0,0 },  // Inst #10 = COPY_TO_REGCLASS
  { 11,	0,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Variadic), 0x0ULL, NULL, NULL, 0,0,0 },  // Inst #11 = DBG_VALUE
  { 12,	1,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Variadic)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #12 = REG_SEQUENCE
  { 13,	2,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo7,0,0 },  // Inst #13 = COPY
  { 14,	0,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Variadic)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, 0,0,0 },  // Inst #14 = BUNDLE
  { 15,	1,	0,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #15 = LIFETIME_START
  { 16,	1,	0,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #16 = LIFETIME_END
  { 17,	2,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Call)|(1<<MCID::MayLoad)|(1<<MCID::Variadic)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo8,0,0 },  // Inst #17 = STACKMAP
  { 18,	6,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Call)|(1<<MCID::MayLoad)|(1<<MCID::Variadic)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo9,0,0 },  // Inst #18 = PATCHPOINT
  { 19,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #19 = ADD_2rus
  { 20,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #20 = ADD_3r
  { 21,	1,	0,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo2,0,0 },  // Inst #21 = ADJCALLSTACKDOWN
  { 22,	2,	0,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo8,0,0 },  // Inst #22 = ADJCALLSTACKUP
  { 23,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #23 = ANDNOT_2r
  { 24,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #24 = AND_3r
  { 25,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #25 = ASHR_l2rus
  { 26,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #26 = ASHR_l3r
  { 27,	1,	0,	0,	2,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::Terminator), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #27 = BAU_1r
  { 28,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #28 = BITREV_l2r
  { 29,	1,	0,	0,	4,	0|(1<<MCID::Call)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList2, OperandInfo2,0,0 },  // Inst #29 = BLACP_lu10
  { 30,	1,	0,	0,	2,	0|(1<<MCID::Call)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList2, OperandInfo2,0,0 },  // Inst #30 = BLACP_u10
  { 31,	1,	0,	0,	4,	0|(1<<MCID::Call)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList3, NULL, OperandInfo2,0,0 },  // Inst #31 = BLAT_lu6
  { 32,	1,	0,	0,	2,	0|(1<<MCID::Call)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList3, NULL, OperandInfo2,0,0 },  // Inst #32 = BLAT_u6
  { 33,	1,	0,	0,	2,	0|(1<<MCID::Call), 0x0ULL, ImplicitList1, ImplicitList2, OperandInfo13,0,0 },  // Inst #33 = BLA_1r
  { 34,	1,	0,	0,	4,	0|(1<<MCID::Call)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList2, OperandInfo5,0,0 },  // Inst #34 = BLRB_lu10
  { 35,	1,	0,	0,	2,	0|(1<<MCID::Call)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList2, OperandInfo5,0,0 },  // Inst #35 = BLRB_u10
  { 36,	1,	0,	0,	4,	0|(1<<MCID::Call), 0x0ULL, ImplicitList1, ImplicitList2, OperandInfo5,0,0 },  // Inst #36 = BLRF_lu10
  { 37,	1,	0,	0,	2,	0|(1<<MCID::Call), 0x0ULL, ImplicitList1, ImplicitList2, OperandInfo5,0,0 },  // Inst #37 = BLRF_u10
  { 38,	2,	0,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #38 = BRBF_lru6
  { 39,	2,	0,	0,	2,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #39 = BRBF_ru6
  { 40,	2,	0,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #40 = BRBT_lru6
  { 41,	2,	0,	0,	2,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #41 = BRBT_ru6
  { 42,	1,	0,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::Barrier)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #42 = BRBU_lu6
  { 43,	1,	0,	0,	2,	0|(1<<MCID::Branch)|(1<<MCID::Barrier)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #43 = BRBU_u6
  { 44,	2,	0,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x0ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #44 = BRFF_lru6
  { 45,	2,	0,	0,	2,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #45 = BRFF_ru6
  { 46,	2,	0,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x0ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #46 = BRFT_lru6
  { 47,	2,	0,	0,	2,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #47 = BRFT_ru6
  { 48,	1,	0,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::Barrier)|(1<<MCID::Terminator), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #48 = BRFU_lu6
  { 49,	1,	0,	0,	2,	0|(1<<MCID::Branch)|(1<<MCID::Barrier)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #49 = BRFU_u6
  { 50,	1,	0,	0,	2,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #50 = BRU_1r
  { 51,	2,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::Terminator), 0x0ULL, NULL, NULL, OperandInfo16,0,0 },  // Inst #51 = BR_JT
  { 52,	2,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::Terminator), 0x0ULL, NULL, NULL, OperandInfo16,0,0 },  // Inst #52 = BR_JT32
  { 53,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #53 = BYTEREV_l2r
  { 54,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #54 = CHKCT_2r
  { 55,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo17,0,0 },  // Inst #55 = CHKCT_rus
  { 56,	0,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, 0,0,0 },  // Inst #56 = CLRE_0R
  { 57,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #57 = CLRPT_1R
  { 58,	1,	0,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #58 = CLRSR_branch_lu6
  { 59,	1,	0,	0,	2,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #59 = CLRSR_branch_u6
  { 60,	1,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #60 = CLRSR_lu6
  { 61,	1,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #61 = CLRSR_u6
  { 62,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #62 = CLZ_l2r
  { 63,	5,	2,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo18,0,0 },  // Inst #63 = CRC8_l4r
  { 64,	4,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #64 = CRC_l3r
  { 65,	0,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, 0,0,0 },  // Inst #65 = DCALL_0R
  { 66,	0,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList1, 0,0,0 },  // Inst #66 = DENTSP_0R
  { 67,	1,	1,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #67 = DGETREG_1r
  { 68,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #68 = DIVS_l3r
  { 69,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #69 = DIVU_l3r
  { 70,	0,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, 0,0,0 },  // Inst #70 = DRESTSP_0R
  { 71,	0,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, 0,0,0 },  // Inst #71 = DRET_0R
  { 72,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #72 = ECALLF_1r
  { 73,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #73 = ECALLT_1r
  { 74,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #74 = EDU_1r
  { 75,	2,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #75 = EEF_2r
  { 76,	2,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #76 = EET_2r
  { 77,	1,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #77 = EEU_1r
  { 78,	2,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #78 = ENDIN_2r
  { 79,	1,	0,	0,	4,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo2,0,0 },  // Inst #79 = ENTSP_lu6
  { 80,	1,	0,	0,	2,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo2,0,0 },  // Inst #80 = ENTSP_u6
  { 81,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #81 = EQ_2rus
  { 82,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #82 = EQ_3r
  { 83,	1,	0,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #83 = EXTDP_lu6
  { 84,	1,	0,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #84 = EXTDP_u6
  { 85,	1,	0,	0,	4,	0, 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo2,0,0 },  // Inst #85 = EXTSP_lu6
  { 86,	1,	0,	0,	2,	0, 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo2,0,0 },  // Inst #86 = EXTSP_u6
  { 87,	1,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #87 = FREER_1r
  { 88,	0,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, 0,0,0 },  // Inst #88 = FREET_0R
  { 89,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #89 = GETD_l2r
  { 90,	0,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList3, 0,0,0 },  // Inst #90 = GETED_0R
  { 91,	0,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList3, 0,0,0 },  // Inst #91 = GETET_0R
  { 92,	0,	0,	0,	2,	0, 0x0ULL, NULL, ImplicitList3, 0,0,0 },  // Inst #92 = GETID_0R
  { 93,	0,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList3, 0,0,0 },  // Inst #93 = GETKEP_0R
  { 94,	0,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList3, 0,0,0 },  // Inst #94 = GETKSP_0R
  { 95,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #95 = GETN_l2r
  { 96,	2,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #96 = GETPS_l2r
  { 97,	2,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo17,0,0 },  // Inst #97 = GETR_rus
  { 98,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList3, OperandInfo2,0,0 },  // Inst #98 = GETSR_lu6
  { 99,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList3, OperandInfo2,0,0 },  // Inst #99 = GETSR_u6
  { 100,	2,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #100 = GETST_2r
  { 101,	2,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #101 = GETTS_2r
  { 102,	2,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #102 = INCT_2r
  { 103,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #103 = INITCP_2r
  { 104,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #104 = INITDP_2r
  { 105,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #105 = INITLR_l2r
  { 106,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #106 = INITPC_2r
  { 107,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #107 = INITSP_2r
  { 108,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #108 = INPW_l2rus
  { 109,	3,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #109 = INSHR_2r
  { 110,	2,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #110 = INT_2r
  { 111,	2,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #111 = IN_2r
  { 112,	0,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, 0,0,0 },  // Inst #112 = Int_MemBarrier
  { 113,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #113 = KCALL_1r
  { 114,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #114 = KCALL_lu6
  { 115,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #115 = KCALL_u6
  { 116,	1,	0,	0,	4,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo2,0,0 },  // Inst #116 = KENTSP_lu6
  { 117,	1,	0,	0,	2,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo2,0,0 },  // Inst #117 = KENTSP_u6
  { 118,	1,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo2,0,0 },  // Inst #118 = KRESTSP_lu6
  { 119,	1,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo2,0,0 },  // Inst #119 = KRESTSP_u6
  { 120,	0,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, 0,0,0 },  // Inst #120 = KRET_0R
  { 121,	5,	2,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo20,0,0 },  // Inst #121 = LADD_l5r
  { 122,	3,	1,	0,	2,	0|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #122 = LD16S_3r
  { 123,	3,	1,	0,	2,	0|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #123 = LD8U_3r
  { 124,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #124 = LDA16B_l3r
  { 125,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #125 = LDA16F_l3r
  { 126,	1,	0,	0,	4,	0|(1<<MCID::Rematerializable), 0x0ULL, NULL, ImplicitList3, OperandInfo5,0,0 },  // Inst #126 = LDAPB_lu10
  { 127,	1,	0,	0,	2,	0|(1<<MCID::Rematerializable), 0x0ULL, NULL, ImplicitList3, OperandInfo5,0,0 },  // Inst #127 = LDAPB_u10
  { 128,	1,	0,	0,	4,	0|(1<<MCID::Rematerializable), 0x0ULL, NULL, ImplicitList3, OperandInfo5,0,0 },  // Inst #128 = LDAPF_lu10
  { 129,	1,	0,	0,	4,	0|(1<<MCID::Rematerializable), 0x0ULL, NULL, ImplicitList3, OperandInfo5,0,0 },  // Inst #129 = LDAPF_lu10_ba
  { 130,	1,	0,	0,	2,	0|(1<<MCID::Rematerializable), 0x0ULL, NULL, ImplicitList3, OperandInfo5,0,0 },  // Inst #130 = LDAPF_u10
  { 131,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #131 = LDAWB_l2rus
  { 132,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #132 = LDAWB_l3r
  { 133,	1,	0,	0,	4,	0|(1<<MCID::Rematerializable), 0x0ULL, NULL, ImplicitList3, OperandInfo2,0,0 },  // Inst #133 = LDAWCP_lu6
  { 134,	1,	0,	0,	2,	0|(1<<MCID::Rematerializable), 0x0ULL, NULL, ImplicitList3, OperandInfo2,0,0 },  // Inst #134 = LDAWCP_u6
  { 135,	2,	1,	0,	4,	0|(1<<MCID::Rematerializable), 0x0ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #135 = LDAWDP_lru6
  { 136,	2,	1,	0,	2,	0|(1<<MCID::Rematerializable), 0x0ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #136 = LDAWDP_ru6
  { 137,	3,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #137 = LDAWFI
  { 138,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #138 = LDAWF_l2rus
  { 139,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #139 = LDAWF_l3r
  { 140,	2,	1,	0,	4,	0, 0x0ULL, ImplicitList1, NULL, OperandInfo21,0,0 },  // Inst #140 = LDAWSP_lru6
  { 141,	2,	1,	0,	2,	0, 0x0ULL, ImplicitList1, NULL, OperandInfo21,0,0 },  // Inst #141 = LDAWSP_ru6
  { 142,	2,	1,	0,	4,	0|(1<<MCID::Rematerializable), 0x0ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #142 = LDC_lru6
  { 143,	2,	1,	0,	2,	0|(1<<MCID::Rematerializable), 0x0ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #143 = LDC_ru6
  { 144,	0,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, 0,0,0 },  // Inst #144 = LDET_0R
  { 145,	5,	2,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo20,0,0 },  // Inst #145 = LDIVU_l5r
  { 146,	0,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, 0,0,0 },  // Inst #146 = LDSED_0R
  { 147,	0,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, 0,0,0 },  // Inst #147 = LDSPC_0R
  { 148,	0,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, 0,0,0 },  // Inst #148 = LDSSR_0R
  { 149,	2,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Rematerializable), 0x0ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #149 = LDWCP_lru6
  { 150,	1,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Rematerializable), 0x0ULL, NULL, ImplicitList3, OperandInfo2,0,0 },  // Inst #150 = LDWCP_lu10
  { 151,	2,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::Rematerializable), 0x0ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #151 = LDWCP_ru6
  { 152,	1,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::Rematerializable), 0x0ULL, NULL, ImplicitList3, OperandInfo2,0,0 },  // Inst #152 = LDWCP_u10
  { 153,	2,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #153 = LDWDP_lru6
  { 154,	2,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #154 = LDWDP_ru6
  { 155,	3,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #155 = LDWFI
  { 156,	2,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, OperandInfo21,0,0 },  // Inst #156 = LDWSP_lru6
  { 157,	2,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, OperandInfo21,0,0 },  // Inst #157 = LDWSP_ru6
  { 158,	3,	1,	0,	2,	0|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #158 = LDW_2rus
  { 159,	3,	1,	0,	2,	0|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #159 = LDW_3r
  { 160,	6,	2,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #160 = LMUL_l6r
  { 161,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #161 = LSS_3r
  { 162,	5,	2,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo20,0,0 },  // Inst #162 = LSUB_l5r
  { 163,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #163 = LSU_3r
  { 164,	6,	2,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo24,0,0 },  // Inst #164 = MACCS_l4r
  { 165,	6,	2,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo24,0,0 },  // Inst #165 = MACCU_l4r
  { 166,	1,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #166 = MJOIN_1r
  { 167,	2,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #167 = MKMSK_2r
  { 168,	2,	1,	0,	2,	0|(1<<MCID::Rematerializable), 0x0ULL, NULL, NULL, OperandInfo17,0,0 },  // Inst #168 = MKMSK_rus
  { 169,	1,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #169 = MSYNC_1r
  { 170,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #170 = MUL_l3r
  { 171,	2,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #171 = NEG
  { 172,	2,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #172 = NOT
  { 173,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #173 = OR_3r
  { 174,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #174 = OUTCT_2r
  { 175,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo17,0,0 },  // Inst #175 = OUTCT_rus
  { 176,	3,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #176 = OUTPW_l2rus
  { 177,	3,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #177 = OUTSHR_2r
  { 178,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #178 = OUTT_2r
  { 179,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #179 = OUT_2r
  { 180,	2,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #180 = PEEK_2r
  { 181,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #181 = REMS_l3r
  { 182,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #182 = REMU_l3r
  { 183,	1,	0,	0,	4,	0|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::MayLoad)|(1<<MCID::Terminator), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo2,0,0 },  // Inst #183 = RETSP_lu6
  { 184,	1,	0,	0,	2,	0|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::MayLoad)|(1<<MCID::Terminator), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo2,0,0 },  // Inst #184 = RETSP_u6
  { 185,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #185 = SELECT_CC
  { 186,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #186 = SETCLK_l2r
  { 187,	1,	0,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #187 = SETCP_1r
  { 188,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #188 = SETC_l2r
  { 189,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo17,0,0 },  // Inst #189 = SETC_lru6
  { 190,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo17,0,0 },  // Inst #190 = SETC_ru6
  { 191,	1,	0,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #191 = SETDP_1r
  { 192,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #192 = SETD_2r
  { 193,	1,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList3, NULL, OperandInfo13,0,0 },  // Inst #193 = SETEV_1r
  { 194,	0,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList3, NULL, 0,0,0 },  // Inst #194 = SETKEP_0R
  { 195,	2,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #195 = SETN_l2r
  { 196,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #196 = SETPSC_2r
  { 197,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #197 = SETPS_l2r
  { 198,	2,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #198 = SETPT_2r
  { 199,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #199 = SETRDY_l2r
  { 200,	1,	0,	0,	2,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo13,0,0 },  // Inst #200 = SETSP_1r
  { 201,	1,	0,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #201 = SETSR_branch_lu6
  { 202,	1,	0,	0,	2,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #202 = SETSR_branch_u6
  { 203,	1,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #203 = SETSR_lu6
  { 204,	1,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #204 = SETSR_u6
  { 205,	2,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #205 = SETTW_l2r
  { 206,	1,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList3, NULL, OperandInfo13,0,0 },  // Inst #206 = SETV_1r
  { 207,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #207 = SEXT_2r
  { 208,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #208 = SEXT_rus
  { 209,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #209 = SHL_2rus
  { 210,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #210 = SHL_3r
  { 211,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #211 = SHR_2rus
  { 212,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #212 = SHR_3r
  { 213,	0,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, 0,0,0 },  // Inst #213 = SSYNC_0r
  { 214,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #214 = ST16_l3r
  { 215,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #215 = ST8_l3r
  { 216,	0,	0,	0,	2,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, 0,0,0 },  // Inst #216 = STET_0R
  { 217,	0,	0,	0,	2,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, 0,0,0 },  // Inst #217 = STSED_0R
  { 218,	0,	0,	0,	2,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, 0,0,0 },  // Inst #218 = STSPC_0R
  { 219,	0,	0,	0,	2,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, 0,0,0 },  // Inst #219 = STSSR_0R
  { 220,	2,	0,	0,	4,	0|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #220 = STWDP_lru6
  { 221,	2,	0,	0,	2,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #221 = STWDP_ru6
  { 222,	3,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #222 = STWFI
  { 223,	2,	0,	0,	4,	0|(1<<MCID::MayStore), 0x0ULL, ImplicitList1, NULL, OperandInfo21,0,0 },  // Inst #223 = STWSP_lru6
  { 224,	2,	0,	0,	2,	0|(1<<MCID::MayStore), 0x0ULL, ImplicitList1, NULL, OperandInfo21,0,0 },  // Inst #224 = STWSP_ru6
  { 225,	3,	0,	0,	2,	0|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #225 = STW_2rus
  { 226,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #226 = STW_l3r
  { 227,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #227 = SUB_2rus
  { 228,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #228 = SUB_3r
  { 229,	1,	0,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #229 = SYNCR_1r
  { 230,	2,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #230 = TESTCT_2r
  { 231,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #231 = TESTLCL_l2r
  { 232,	2,	1,	0,	2,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #232 = TESTWCT_2r
  { 233,	2,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #233 = TSETMR_2r
  { 234,	3,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #234 = TSETR_3r
  { 235,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #235 = TSTART_1R
  { 236,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #236 = WAITEF_1R
  { 237,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #237 = WAITET_1R
  { 238,	0,	0,	0,	2,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::MayLoad)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, 0,0,0 },  // Inst #238 = WAITEU_0R
  { 239,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #239 = XOR_l3r
  { 240,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #240 = ZEXT_2r
  { 241,	3,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #241 = ZEXT_rus
};

extern const char XCoreInstrNameData[] = {
  /* 0 */ 'L', 'D', 'A', 'P', 'B', '_', 'u', '1', '0', 0,
  /* 10 */ 'B', 'L', 'R', 'B', '_', 'u', '1', '0', 0,
  /* 19 */ 'L', 'D', 'A', 'P', 'F', '_', 'u', '1', '0', 0,
  /* 29 */ 'B', 'L', 'R', 'F', '_', 'u', '1', '0', 0,
  /* 38 */ 'B', 'L', 'A', 'C', 'P', '_', 'u', '1', '0', 0,
  /* 48 */ 'L', 'D', 'W', 'C', 'P', '_', 'u', '1', '0', 0,
  /* 58 */ 'L', 'D', 'A', 'P', 'B', '_', 'l', 'u', '1', '0', 0,
  /* 69 */ 'B', 'L', 'R', 'B', '_', 'l', 'u', '1', '0', 0,
  /* 79 */ 'L', 'D', 'A', 'P', 'F', '_', 'l', 'u', '1', '0', 0,
  /* 90 */ 'B', 'L', 'R', 'F', '_', 'l', 'u', '1', '0', 0,
  /* 100 */ 'B', 'L', 'A', 'C', 'P', '_', 'l', 'u', '1', '0', 0,
  /* 111 */ 'L', 'D', 'W', 'C', 'P', '_', 'l', 'u', '1', '0', 0,
  /* 122 */ 'B', 'R', '_', 'J', 'T', '3', '2', 0,
  /* 130 */ 'K', 'C', 'A', 'L', 'L', '_', 'u', '6', 0,
  /* 139 */ 'L', 'D', 'A', 'W', 'C', 'P', '_', 'u', '6', 0,
  /* 149 */ 'E', 'X', 'T', 'D', 'P', '_', 'u', '6', 0,
  /* 158 */ 'R', 'E', 'T', 'S', 'P', '_', 'u', '6', 0,
  /* 167 */ 'K', 'E', 'N', 'T', 'S', 'P', '_', 'u', '6', 0,
  /* 177 */ 'K', 'R', 'E', 'S', 'T', 'S', 'P', '_', 'u', '6', 0,
  /* 188 */ 'E', 'X', 'T', 'S', 'P', '_', 'u', '6', 0,
  /* 197 */ 'C', 'L', 'R', 'S', 'R', '_', 'u', '6', 0,
  /* 206 */ 'G', 'E', 'T', 'S', 'R', '_', 'u', '6', 0,
  /* 215 */ 'S', 'E', 'T', 'S', 'R', '_', 'u', '6', 0,
  /* 224 */ 'B', 'L', 'A', 'T', '_', 'u', '6', 0,
  /* 232 */ 'B', 'R', 'B', 'U', '_', 'u', '6', 0,
  /* 240 */ 'B', 'R', 'F', 'U', '_', 'u', '6', 0,
  /* 248 */ 'C', 'L', 'R', 'S', 'R', '_', 'b', 'r', 'a', 'n', 'c', 'h', '_', 'u', '6', 0,
  /* 264 */ 'S', 'E', 'T', 'S', 'R', '_', 'b', 'r', 'a', 'n', 'c', 'h', '_', 'u', '6', 0,
  /* 280 */ 'K', 'C', 'A', 'L', 'L', '_', 'l', 'u', '6', 0,
  /* 290 */ 'L', 'D', 'A', 'W', 'C', 'P', '_', 'l', 'u', '6', 0,
  /* 301 */ 'E', 'X', 'T', 'D', 'P', '_', 'l', 'u', '6', 0,
  /* 311 */ 'R', 'E', 'T', 'S', 'P', '_', 'l', 'u', '6', 0,
  /* 321 */ 'K', 'E', 'N', 'T', 'S', 'P', '_', 'l', 'u', '6', 0,
  /* 332 */ 'K', 'R', 'E', 'S', 'T', 'S', 'P', '_', 'l', 'u', '6', 0,
  /* 344 */ 'E', 'X', 'T', 'S', 'P', '_', 'l', 'u', '6', 0,
  /* 354 */ 'C', 'L', 'R', 'S', 'R', '_', 'l', 'u', '6', 0,
  /* 364 */ 'G', 'E', 'T', 'S', 'R', '_', 'l', 'u', '6', 0,
  /* 374 */ 'S', 'E', 'T', 'S', 'R', '_', 'l', 'u', '6', 0,
  /* 384 */ 'B', 'L', 'A', 'T', '_', 'l', 'u', '6', 0,
  /* 393 */ 'B', 'R', 'B', 'U', '_', 'l', 'u', '6', 0,
  /* 402 */ 'B', 'R', 'F', 'U', '_', 'l', 'u', '6', 0,
  /* 411 */ 'C', 'L', 'R', 'S', 'R', '_', 'b', 'r', 'a', 'n', 'c', 'h', '_', 'l', 'u', '6', 0,
  /* 428 */ 'S', 'E', 'T', 'S', 'R', '_', 'b', 'r', 'a', 'n', 'c', 'h', '_', 'l', 'u', '6', 0,
  /* 445 */ 'L', 'D', 'C', '_', 'r', 'u', '6', 0,
  /* 453 */ 'S', 'E', 'T', 'C', '_', 'r', 'u', '6', 0,
  /* 462 */ 'B', 'R', 'B', 'F', '_', 'r', 'u', '6', 0,
  /* 471 */ 'B', 'R', 'F', 'F', '_', 'r', 'u', '6', 0,
  /* 480 */ 'L', 'D', 'W', 'C', 'P', '_', 'r', 'u', '6', 0,
  /* 490 */ 'L', 'D', 'A', 'W', 'D', 'P', '_', 'r', 'u', '6', 0,
  /* 501 */ 'L', 'D', 'W', 'D', 'P', '_', 'r', 'u', '6', 0,
  /* 511 */ 'S', 'T', 'W', 'D', 'P', '_', 'r', 'u', '6', 0,
  /* 521 */ 'L', 'D', 'A', 'W', 'S', 'P', '_', 'r', 'u', '6', 0,
  /* 532 */ 'L', 'D', 'W', 'S', 'P', '_', 'r', 'u', '6', 0,
  /* 542 */ 'S', 'T', 'W', 'S', 'P', '_', 'r', 'u', '6', 0,
  /* 552 */ 'B', 'R', 'B', 'T', '_', 'r', 'u', '6', 0,
  /* 561 */ 'B', 'R', 'F', 'T', '_', 'r', 'u', '6', 0,
  /* 570 */ 'L', 'D', 'C', '_', 'l', 'r', 'u', '6', 0,
  /* 579 */ 'S', 'E', 'T', 'C', '_', 'l', 'r', 'u', '6', 0,
  /* 589 */ 'B', 'R', 'B', 'F', '_', 'l', 'r', 'u', '6', 0,
  /* 599 */ 'B', 'R', 'F', 'F', '_', 'l', 'r', 'u', '6', 0,
  /* 609 */ 'L', 'D', 'W', 'C', 'P', '_', 'l', 'r', 'u', '6', 0,
  /* 620 */ 'L', 'D', 'A', 'W', 'D', 'P', '_', 'l', 'r', 'u', '6', 0,
  /* 632 */ 'L', 'D', 'W', 'D', 'P', '_', 'l', 'r', 'u', '6', 0,
  /* 643 */ 'S', 'T', 'W', 'D', 'P', '_', 'l', 'r', 'u', '6', 0,
  /* 654 */ 'L', 'D', 'A', 'W', 'S', 'P', '_', 'l', 'r', 'u', '6', 0,
  /* 666 */ 'L', 'D', 'W', 'S', 'P', '_', 'l', 'r', 'u', '6', 0,
  /* 677 */ 'S', 'T', 'W', 'S', 'P', '_', 'l', 'r', 'u', '6', 0,
  /* 688 */ 'B', 'R', 'B', 'T', '_', 'l', 'r', 'u', '6', 0,
  /* 698 */ 'B', 'R', 'F', 'T', '_', 'l', 'r', 'u', '6', 0,
  /* 708 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'C', 'C', 0,
  /* 718 */ 'L', 'I', 'F', 'E', 'T', 'I', 'M', 'E', '_', 'E', 'N', 'D', 0,
  /* 731 */ 'R', 'E', 'G', '_', 'S', 'E', 'Q', 'U', 'E', 'N', 'C', 'E', 0,
  /* 744 */ 'B', 'U', 'N', 'D', 'L', 'E', 0,
  /* 751 */ 'D', 'B', 'G', '_', 'V', 'A', 'L', 'U', 'E', 0,
  /* 761 */ 'I', 'M', 'P', 'L', 'I', 'C', 'I', 'T', '_', 'D', 'E', 'F', 0,
  /* 774 */ 'N', 'E', 'G', 0,
  /* 778 */ 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'S', 'U', 'B', 'R', 'E', 'G', 0,
  /* 793 */ 'I', 'N', 'S', 'E', 'R', 'T', '_', 'S', 'U', 'B', 'R', 'E', 'G', 0,
  /* 807 */ 'S', 'U', 'B', 'R', 'E', 'G', '_', 'T', 'O', '_', 'R', 'E', 'G', 0,
  /* 821 */ 'L', 'D', 'A', 'W', 'F', 'I', 0,
  /* 828 */ 'L', 'D', 'W', 'F', 'I', 0,
  /* 834 */ 'S', 'T', 'W', 'F', 'I', 0,
  /* 840 */ 'P', 'H', 'I', 0,
  /* 844 */ 'G', 'C', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 853 */ 'P', 'R', 'O', 'L', 'O', 'G', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 866 */ 'E', 'H', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 875 */ 'K', 'I', 'L', 'L', 0,
  /* 880 */ 'I', 'N', 'L', 'I', 'N', 'E', 'A', 'S', 'M', 0,
  /* 890 */ 'A', 'D', 'J', 'C', 'A', 'L', 'L', 'S', 'T', 'A', 'C', 'K', 'D', 'O', 'W', 'N', 0,
  /* 907 */ 'S', 'T', 'A', 'C', 'K', 'M', 'A', 'P', 0,
  /* 916 */ 'A', 'D', 'J', 'C', 'A', 'L', 'L', 'S', 'T', 'A', 'C', 'K', 'U', 'P', 0,
  /* 931 */ 'L', 'D', 'S', 'P', 'C', '_', '0', 'R', 0,
  /* 940 */ 'S', 'T', 'S', 'P', 'C', '_', '0', 'R', 0,
  /* 949 */ 'L', 'D', 'S', 'E', 'D', '_', '0', 'R', 0,
  /* 958 */ 'S', 'T', 'S', 'E', 'D', '_', '0', 'R', 0,
  /* 967 */ 'G', 'E', 'T', 'E', 'D', '_', '0', 'R', 0,
  /* 976 */ 'G', 'E', 'T', 'I', 'D', '_', '0', 'R', 0,
  /* 985 */ 'C', 'L', 'R', 'E', '_', '0', 'R', 0,
  /* 993 */ 'D', 'C', 'A', 'L', 'L', '_', '0', 'R', 0,
  /* 1002 */ 'G', 'E', 'T', 'K', 'E', 'P', '_', '0', 'R', 0,
  /* 1012 */ 'S', 'E', 'T', 'K', 'E', 'P', '_', '0', 'R', 0,
  /* 1022 */ 'G', 'E', 'T', 'K', 'S', 'P', '_', '0', 'R', 0,
  /* 1032 */ 'D', 'E', 'N', 'T', 'S', 'P', '_', '0', 'R', 0,
  /* 1042 */ 'D', 'R', 'E', 'S', 'T', 'S', 'P', '_', '0', 'R', 0,
  /* 1053 */ 'L', 'D', 'S', 'S', 'R', '_', '0', 'R', 0,
  /* 1062 */ 'S', 'T', 'S', 'S', 'R', '_', '0', 'R', 0,
  /* 1071 */ 'L', 'D', 'E', 'T', '_', '0', 'R', 0,
  /* 1079 */ 'F', 'R', 'E', 'E', 'T', '_', '0', 'R', 0,
  /* 1088 */ 'D', 'R', 'E', 'T', '_', '0', 'R', 0,
  /* 1096 */ 'K', 'R', 'E', 'T', '_', '0', 'R', 0,
  /* 1104 */ 'G', 'E', 'T', 'E', 'T', '_', '0', 'R', 0,
  /* 1113 */ 'S', 'T', 'E', 'T', '_', '0', 'R', 0,
  /* 1121 */ 'W', 'A', 'I', 'T', 'E', 'U', '_', '0', 'R', 0,
  /* 1131 */ 'W', 'A', 'I', 'T', 'E', 'F', '_', '1', 'R', 0,
  /* 1141 */ 'W', 'A', 'I', 'T', 'E', 'T', '_', '1', 'R', 0,
  /* 1151 */ 'C', 'L', 'R', 'P', 'T', '_', '1', 'R', 0,
  /* 1160 */ 'T', 'S', 'T', 'A', 'R', 'T', '_', '1', 'R', 0,
  /* 1170 */ 'C', 'O', 'P', 'Y', '_', 'T', 'O', '_', 'R', 'E', 'G', 'C', 'L', 'A', 'S', 'S', 0,
  /* 1187 */ 'B', 'R', '_', 'J', 'T', 0,
  /* 1193 */ 'P', 'A', 'T', 'C', 'H', 'P', 'O', 'I', 'N', 'T', 0,
  /* 1204 */ 'N', 'O', 'T', 0,
  /* 1208 */ 'L', 'I', 'F', 'E', 'T', 'I', 'M', 'E', '_', 'S', 'T', 'A', 'R', 'T', 0,
  /* 1223 */ 'C', 'O', 'P', 'Y', 0,
  /* 1228 */ 'L', 'D', 'A', 'P', 'F', '_', 'l', 'u', '1', '0', '_', 'b', 'a', 0,
  /* 1242 */ 'S', 'S', 'Y', 'N', 'C', '_', '0', 'r', 0,
  /* 1251 */ 'B', 'L', 'A', '_', '1', 'r', 0,
  /* 1258 */ 'M', 'S', 'Y', 'N', 'C', '_', '1', 'r', 0,
  /* 1267 */ 'E', 'C', 'A', 'L', 'L', 'F', '_', '1', 'r', 0,
  /* 1277 */ 'D', 'G', 'E', 'T', 'R', 'E', 'G', '_', '1', 'r', 0,
  /* 1288 */ 'K', 'C', 'A', 'L', 'L', '_', '1', 'r', 0,
  /* 1297 */ 'M', 'J', 'O', 'I', 'N', '_', '1', 'r', 0,
  /* 1306 */ 'S', 'E', 'T', 'C', 'P', '_', '1', 'r', 0,
  /* 1315 */ 'S', 'E', 'T', 'D', 'P', '_', '1', 'r', 0,
  /* 1324 */ 'S', 'E', 'T', 'S', 'P', '_', '1', 'r', 0,
  /* 1333 */ 'S', 'Y', 'N', 'C', 'R', '_', '1', 'r', 0,
  /* 1342 */ 'F', 'R', 'E', 'E', 'R', '_', '1', 'r', 0,
  /* 1351 */ 'E', 'C', 'A', 'L', 'L', 'T', '_', '1', 'r', 0,
  /* 1361 */ 'B', 'A', 'U', '_', '1', 'r', 0,
  /* 1368 */ 'E', 'D', 'U', '_', '1', 'r', 0,
  /* 1375 */ 'E', 'E', 'U', '_', '1', 'r', 0,
  /* 1382 */ 'B', 'R', 'U', '_', '1', 'r', 0,
  /* 1389 */ 'S', 'E', 'T', 'E', 'V', '_', '1', 'r', 0,
  /* 1398 */ 'S', 'E', 'T', 'V', '_', '1', 'r', 0,
  /* 1406 */ 'I', 'N', 'I', 'T', 'P', 'C', '_', '2', 'r', 0,
  /* 1416 */ 'S', 'E', 'T', 'P', 'S', 'C', '_', '2', 'r', 0,
  /* 1426 */ 'S', 'E', 'T', 'D', '_', '2', 'r', 0,
  /* 1434 */ 'E', 'E', 'F', '_', '2', 'r', 0,
  /* 1441 */ 'P', 'E', 'E', 'K', '_', '2', 'r', 0,
  /* 1449 */ 'M', 'K', 'M', 'S', 'K', '_', '2', 'r', 0,
  /* 1458 */ 'E', 'N', 'D', 'I', 'N', '_', '2', 'r', 0,
  /* 1467 */ 'I', 'N', 'I', 'T', 'C', 'P', '_', '2', 'r', 0,
  /* 1477 */ 'I', 'N', 'I', 'T', 'D', 'P', '_', '2', 'r', 0,
  /* 1487 */ 'I', 'N', 'I', 'T', 'S', 'P', '_', '2', 'r', 0,
  /* 1497 */ 'I', 'N', 'S', 'H', 'R', '_', '2', 'r', 0,
  /* 1506 */ 'O', 'U', 'T', 'S', 'H', 'R', '_', '2', 'r', 0,
  /* 1516 */ 'T', 'S', 'E', 'T', 'M', 'R', '_', '2', 'r', 0,
  /* 1526 */ 'G', 'E', 'T', 'T', 'S', '_', '2', 'r', 0,
  /* 1535 */ 'C', 'H', 'K', 'C', 'T', '_', '2', 'r', 0,
  /* 1544 */ 'I', 'N', 'C', 'T', '_', '2', 'r', 0,
  /* 1552 */ 'T', 'E', 'S', 'T', 'C', 'T', '_', '2', 'r', 0,
  /* 1562 */ 'O', 'U', 'T', 'C', 'T', '_', '2', 'r', 0,
  /* 1571 */ 'T', 'E', 'S', 'T', 'W', 'C', 'T', '_', '2', 'r', 0,
  /* 1582 */ 'E', 'E', 'T', '_', '2', 'r', 0,
  /* 1589 */ 'I', 'N', 'T', '_', '2', 'r', 0,
  /* 1596 */ 'A', 'N', 'D', 'N', 'O', 'T', '_', '2', 'r', 0,
  /* 1606 */ 'S', 'E', 'T', 'P', 'T', '_', '2', 'r', 0,
  /* 1615 */ 'G', 'E', 'T', 'S', 'T', '_', '2', 'r', 0,
  /* 1624 */ 'O', 'U', 'T', 'T', '_', '2', 'r', 0,
  /* 1632 */ 'O', 'U', 'T', '_', '2', 'r', 0,
  /* 1639 */ 'S', 'E', 'X', 'T', '_', '2', 'r', 0,
  /* 1647 */ 'Z', 'E', 'X', 'T', '_', '2', 'r', 0,
  /* 1655 */ 'S', 'E', 'T', 'C', '_', 'l', '2', 'r', 0,
  /* 1664 */ 'G', 'E', 'T', 'D', '_', 'l', '2', 'r', 0,
  /* 1673 */ 'S', 'E', 'T', 'C', 'L', 'K', '_', 'l', '2', 'r', 0,
  /* 1684 */ 'T', 'E', 'S', 'T', 'L', 'C', 'L', '_', 'l', '2', 'r', 0,
  /* 1696 */ 'G', 'E', 'T', 'N', '_', 'l', '2', 'r', 0,
  /* 1705 */ 'S', 'E', 'T', 'N', '_', 'l', '2', 'r', 0,
  /* 1714 */ 'I', 'N', 'I', 'T', 'L', 'R', '_', 'l', '2', 'r', 0,
  /* 1725 */ 'G', 'E', 'T', 'P', 'S', '_', 'l', '2', 'r', 0,
  /* 1735 */ 'S', 'E', 'T', 'P', 'S', '_', 'l', '2', 'r', 0,
  /* 1745 */ 'B', 'Y', 'T', 'E', 'R', 'E', 'V', '_', 'l', '2', 'r', 0,
  /* 1757 */ 'B', 'I', 'T', 'R', 'E', 'V', '_', 'l', '2', 'r', 0,
  /* 1768 */ 'S', 'E', 'T', 'T', 'W', '_', 'l', '2', 'r', 0,
  /* 1778 */ 'S', 'E', 'T', 'R', 'D', 'Y', '_', 'l', '2', 'r', 0,
  /* 1789 */ 'C', 'L', 'Z', '_', 'l', '2', 'r', 0,
  /* 1797 */ 'S', 'U', 'B', '_', '3', 'r', 0,
  /* 1804 */ 'A', 'D', 'D', '_', '3', 'r', 0,
  /* 1811 */ 'A', 'N', 'D', '_', '3', 'r', 0,
  /* 1818 */ 'S', 'H', 'L', '_', '3', 'r', 0,
  /* 1825 */ 'E', 'Q', '_', '3', 'r', 0,
  /* 1831 */ 'S', 'H', 'R', '_', '3', 'r', 0,
  /* 1838 */ 'O', 'R', '_', '3', 'r', 0,
  /* 1844 */ 'T', 'S', 'E', 'T', 'R', '_', '3', 'r', 0,
  /* 1853 */ 'L', 'D', '1', '6', 'S', '_', '3', 'r', 0,
  /* 1862 */ 'L', 'S', 'S', '_', '3', 'r', 0,
  /* 1869 */ 'L', 'D', '8', 'U', '_', '3', 'r', 0,
  /* 1877 */ 'L', 'S', 'U', '_', '3', 'r', 0,
  /* 1884 */ 'L', 'D', 'W', '_', '3', 'r', 0,
  /* 1891 */ 'S', 'T', '1', '6', '_', 'l', '3', 'r', 0,
  /* 1900 */ 'S', 'T', '8', '_', 'l', '3', 'r', 0,
  /* 1908 */ 'L', 'D', 'A', '1', '6', 'B', '_', 'l', '3', 'r', 0,
  /* 1919 */ 'L', 'D', 'A', 'W', 'B', '_', 'l', '3', 'r', 0,
  /* 1929 */ 'C', 'R', 'C', '_', 'l', '3', 'r', 0,
  /* 1937 */ 'L', 'D', 'A', '1', '6', 'F', '_', 'l', '3', 'r', 0,
  /* 1948 */ 'L', 'D', 'A', 'W', 'F', '_', 'l', '3', 'r', 0,
  /* 1958 */ 'M', 'U', 'L', '_', 'l', '3', 'r', 0,
  /* 1966 */ 'A', 'S', 'H', 'R', '_', 'l', '3', 'r', 0,
  /* 1975 */ 'X', 'O', 'R', '_', 'l', '3', 'r', 0,
  /* 1983 */ 'R', 'E', 'M', 'S', '_', 'l', '3', 'r', 0,
  /* 1992 */ 'D', 'I', 'V', 'S', '_', 'l', '3', 'r', 0,
  /* 2001 */ 'R', 'E', 'M', 'U', '_', 'l', '3', 'r', 0,
  /* 2010 */ 'D', 'I', 'V', 'U', '_', 'l', '3', 'r', 0,
  /* 2019 */ 'S', 'T', 'W', '_', 'l', '3', 'r', 0,
  /* 2027 */ 'C', 'R', 'C', '8', '_', 'l', '4', 'r', 0,
  /* 2036 */ 'M', 'A', 'C', 'C', 'S', '_', 'l', '4', 'r', 0,
  /* 2046 */ 'M', 'A', 'C', 'C', 'U', '_', 'l', '4', 'r', 0,
  /* 2056 */ 'L', 'S', 'U', 'B', '_', 'l', '5', 'r', 0,
  /* 2065 */ 'L', 'A', 'D', 'D', '_', 'l', '5', 'r', 0,
  /* 2074 */ 'L', 'D', 'I', 'V', 'U', '_', 'l', '5', 'r', 0,
  /* 2084 */ 'L', 'M', 'U', 'L', '_', 'l', '6', 'r', 0,
  /* 2093 */ 'I', 'n', 't', '_', 'M', 'e', 'm', 'B', 'a', 'r', 'r', 'i', 'e', 'r', 0,
  /* 2108 */ 'S', 'U', 'B', '_', '2', 'r', 'u', 's', 0,
  /* 2117 */ 'A', 'D', 'D', '_', '2', 'r', 'u', 's', 0,
  /* 2126 */ 'S', 'H', 'L', '_', '2', 'r', 'u', 's', 0,
  /* 2135 */ 'E', 'Q', '_', '2', 'r', 'u', 's', 0,
  /* 2143 */ 'S', 'H', 'R', '_', '2', 'r', 'u', 's', 0,
  /* 2152 */ 'L', 'D', 'W', '_', '2', 'r', 'u', 's', 0,
  /* 2161 */ 'S', 'T', 'W', '_', '2', 'r', 'u', 's', 0,
  /* 2170 */ 'L', 'D', 'A', 'W', 'B', '_', 'l', '2', 'r', 'u', 's', 0,
  /* 2182 */ 'L', 'D', 'A', 'W', 'F', '_', 'l', '2', 'r', 'u', 's', 0,
  /* 2194 */ 'A', 'S', 'H', 'R', '_', 'l', '2', 'r', 'u', 's', 0,
  /* 2205 */ 'I', 'N', 'P', 'W', '_', 'l', '2', 'r', 'u', 's', 0,
  /* 2216 */ 'O', 'U', 'T', 'P', 'W', '_', 'l', '2', 'r', 'u', 's', 0,
  /* 2228 */ 'M', 'K', 'M', 'S', 'K', '_', 'r', 'u', 's', 0,
  /* 2238 */ 'G', 'E', 'T', 'R', '_', 'r', 'u', 's', 0,
  /* 2247 */ 'C', 'H', 'K', 'C', 'T', '_', 'r', 'u', 's', 0,
  /* 2257 */ 'O', 'U', 'T', 'C', 'T', '_', 'r', 'u', 's', 0,
  /* 2267 */ 'S', 'E', 'X', 'T', '_', 'r', 'u', 's', 0,
  /* 2276 */ 'Z', 'E', 'X', 'T', '_', 'r', 'u', 's', 0,
};

extern const unsigned XCoreInstrNameIndices[] = {
    840U, 880U, 853U, 866U, 844U, 875U, 778U, 793U, 
    761U, 807U, 1170U, 751U, 731U, 1223U, 744U, 1208U, 
    718U, 907U, 1193U, 2117U, 1804U, 890U, 916U, 1596U, 
    1811U, 2194U, 1966U, 1361U, 1757U, 100U, 38U, 384U, 
    224U, 1251U, 69U, 10U, 90U, 29U, 589U, 462U, 
    688U, 552U, 393U, 232U, 599U, 471U, 698U, 561U, 
    402U, 240U, 1382U, 1187U, 122U, 1745U, 1535U, 2247U, 
    985U, 1151U, 411U, 248U, 354U, 197U, 1789U, 2027U, 
    1929U, 993U, 1032U, 1277U, 1992U, 2010U, 1042U, 1088U, 
    1267U, 1351U, 1368U, 1434U, 1582U, 1375U, 1458U, 322U, 
    168U, 2135U, 1825U, 301U, 149U, 344U, 188U, 1342U, 
    1079U, 1664U, 967U, 1104U, 976U, 1002U, 1022U, 1696U, 
    1725U, 2238U, 364U, 206U, 1615U, 1526U, 1544U, 1467U, 
    1477U, 1714U, 1406U, 1487U, 2205U, 1497U, 1589U, 1461U, 
    2093U, 1288U, 280U, 130U, 321U, 167U, 332U, 177U, 
    1096U, 2065U, 1853U, 1869U, 1908U, 1937U, 58U, 0U, 
    79U, 1228U, 19U, 2170U, 1919U, 290U, 139U, 620U, 
    490U, 821U, 2182U, 1948U, 654U, 521U, 570U, 445U, 
    1071U, 2074U, 949U, 931U, 1053U, 609U, 111U, 480U, 
    48U, 632U, 501U, 828U, 666U, 532U, 2152U, 1884U, 
    2084U, 1862U, 2056U, 1877U, 2036U, 2046U, 1297U, 1449U, 
    2228U, 1258U, 1958U, 774U, 1204U, 1838U, 1562U, 2257U, 
    2216U, 1506U, 1624U, 1632U, 1441U, 1983U, 2001U, 311U, 
    158U, 708U, 1673U, 1306U, 1655U, 579U, 453U, 1315U, 
    1426U, 1389U, 1012U, 1705U, 1416U, 1735U, 1606U, 1778U, 
    1324U, 428U, 264U, 374U, 215U, 1768U, 1398U, 1639U, 
    2267U, 2126U, 1818U, 2143U, 1831U, 1242U, 1891U, 1900U, 
    1113U, 958U, 940U, 1062U, 643U, 511U, 834U, 677U, 
    542U, 2161U, 2019U, 2108U, 1797U, 1333U, 1552U, 1684U, 
    1571U, 1516U, 1844U, 1160U, 1131U, 1141U, 1121U, 1975U, 
    1647U, 2276U, 
};

static inline void InitXCoreMCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(XCoreInsts, XCoreInstrNameIndices, XCoreInstrNameData, 242);
}

} // End llvm namespace 
#endif // GET_INSTRINFO_MC_DESC


#ifdef GET_INSTRINFO_HEADER
#undef GET_INSTRINFO_HEADER
namespace llvm {
struct XCoreGenInstrInfo : public TargetInstrInfo {
  explicit XCoreGenInstrInfo(int SO = -1, int DO = -1);
  virtual ~XCoreGenInstrInfo();
};
} // End llvm namespace 
#endif // GET_INSTRINFO_HEADER


#ifdef GET_INSTRINFO_CTOR_DTOR
#undef GET_INSTRINFO_CTOR_DTOR
namespace llvm {
extern const MCInstrDesc XCoreInsts[];
extern const unsigned XCoreInstrNameIndices[];
extern const char XCoreInstrNameData[];
XCoreGenInstrInfo::XCoreGenInstrInfo(int SO, int DO)
  : TargetInstrInfo(SO, DO) {
  InitMCInstrInfo(XCoreInsts, XCoreInstrNameIndices, XCoreInstrNameData, 242);
}
XCoreGenInstrInfo::~XCoreGenInstrInfo() {}
} // End llvm namespace 
#endif // GET_INSTRINFO_CTOR_DTOR

#ifdef GET_INSTRINFO_OPERAND_ENUM
#undef GET_INSTRINFO_OPERAND_ENUM
namespace llvm {namespace XCore {
namespace OpName { 
enum {
OPERAND_LAST
};
} // End namespace OpName
} // End namespace XCore
} // End namespace llvm
#endif //GET_INSTRINFO_OPERAND_ENUM
#ifdef GET_INSTRINFO_NAMED_OPS
#undef GET_INSTRINFO_NAMED_OPS
namespace llvm {namespace XCore {
int16_t getNamedOperandIdx(uint16_t Opcode, uint16_t NamedIdx) {
  return -1;
}
} // End namespace XCore
} // End namespace llvm
#endif //GET_INSTRINFO_NAMED_OPS

#ifdef GET_INSTRINFO_OPERAND_TYPES_ENUM
#undef GET_INSTRINFO_OPERAND_TYPES_ENUM
namespace llvm {namespace XCore {
namespace OpTypes { 
enum OperandType {
  InlineJT = 0,
  InlineJT32 = 1,
  MEMii = 2,
  brtarget = 3,
  brtarget_neg = 4,
  f32imm = 5,
  f64imm = 6,
  i16imm = 7,
  i1imm = 8,
  i32imm = 9,
  i64imm = 10,
  i8imm = 11,
  pcrel_imm = 12,
  pcrel_imm_neg = 13,
  OPERAND_TYPE_LIST_END
};
} // End namespace OpTypes
} // End namespace XCore
} // End namespace llvm
#endif // GET_INSTRINFO_OPERAND_TYPES_ENUM

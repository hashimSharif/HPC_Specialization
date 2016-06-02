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

namespace Hexagon {
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
    ADD64_rr	= 19,
    ADDASL	= 20,
    ADD_ri	= 21,
    ADD_ri_cNotPt	= 22,
    ADD_ri_cPt	= 23,
    ADD_ri_cdnNotPt	= 24,
    ADD_ri_cdnPt	= 25,
    ADD_rr	= 26,
    ADD_rr_cNotPt	= 27,
    ADD_rr_cPt	= 28,
    ADD_rr_cdnNotPt	= 29,
    ADD_rr_cdnPt	= 30,
    ADDi_ASLri_V4	= 31,
    ADDi_LSRri_V4	= 32,
    ADDi_MPYri_V4	= 33,
    ADDi_MPYrr_V4	= 34,
    ADDr_ADDri_V4	= 35,
    ADDr_MPYir_V4	= 36,
    ADDr_MPYri_V4	= 37,
    ADDr_MPYrr_V4	= 38,
    ADDr_SUBri_V4	= 39,
    ADDri_SUBr_V4	= 40,
    ADDri_acc	= 41,
    ADDrr_acc	= 42,
    ADJCALLSTACKDOWN	= 43,
    ADJCALLSTACKUP	= 44,
    ADJDYNALLOC	= 45,
    ALLOCFRAME	= 46,
    ALL_pp	= 47,
    AND_pnotp	= 48,
    AND_pp	= 49,
    AND_ri	= 50,
    AND_rr	= 51,
    AND_rr64	= 52,
    AND_rr_cNotPt	= 53,
    AND_rr_cPt	= 54,
    AND_rr_cdnNotPt	= 55,
    AND_rr_cdnPt	= 56,
    ANDd_NOTd_V4	= 57,
    ANDi_ASLri_V4	= 58,
    ANDi_LSRri_V4	= 59,
    ANDr_ANDr_NOTr_V4	= 60,
    ANDr_ANDrr_V4	= 61,
    ANDr_ORrr_V4	= 62,
    ANDr_XORrr_V4	= 63,
    ANY_pp	= 64,
    ARGEXTEND	= 65,
    ASL	= 66,
    ASLH	= 67,
    ASLH_cNotPt_V4	= 68,
    ASLH_cPt_V4	= 69,
    ASLH_cdnNotPt_V4	= 70,
    ASLH_cdnPt_V4	= 71,
    ASL_ADD_ri	= 72,
    ASL_ADD_rr	= 73,
    ASL_ADDd_ri	= 74,
    ASL_ADDd_rr	= 75,
    ASL_AND_ri	= 76,
    ASL_AND_rr	= 77,
    ASL_ANDd_ri	= 78,
    ASL_ANDd_rr	= 79,
    ASL_OR_ri	= 80,
    ASL_OR_rr	= 81,
    ASL_ORd_ri	= 82,
    ASL_ORd_rr	= 83,
    ASL_SUB_ri	= 84,
    ASL_SUB_rr	= 85,
    ASL_SUBd_ri	= 86,
    ASL_SUBd_rr	= 87,
    ASL_XOR_ri	= 88,
    ASL_XORd_ri	= 89,
    ASL_rr	= 90,
    ASLd	= 91,
    ASLd_ri	= 92,
    ASLd_rr_xor_V4	= 93,
    ASRH	= 94,
    ASRH_cNotPt_V4	= 95,
    ASRH_cPt_V4	= 96,
    ASRH_cdnNotPt_V4	= 97,
    ASRH_cdnPt_V4	= 98,
    ASR_ADD_ri	= 99,
    ASR_ADD_rr	= 100,
    ASR_ADDd_ri	= 101,
    ASR_ADDd_rr	= 102,
    ASR_AND_ri	= 103,
    ASR_AND_rr	= 104,
    ASR_ANDd_ri	= 105,
    ASR_ANDd_rr	= 106,
    ASR_OR_ri	= 107,
    ASR_OR_rr	= 108,
    ASR_ORd_ri	= 109,
    ASR_ORd_rr	= 110,
    ASR_SUB_ri	= 111,
    ASR_SUB_rr	= 112,
    ASR_SUBd_ri	= 113,
    ASR_SUBd_rr	= 114,
    ASR_ri	= 115,
    ASR_rr	= 116,
    ASRd_ri	= 117,
    ASRd_rr	= 118,
    ASRd_rr_xor_V4	= 119,
    BARRIER	= 120,
    CALL	= 121,
    CALLR	= 122,
    CALLRv3	= 123,
    CALLv3	= 124,
    CLRBIT	= 125,
    CLRBIT_31	= 126,
    CMPEHexagon4rr	= 127,
    CMPEQn1_f_Jumpnv_nt_V4	= 128,
    CMPEQn1_f_Jumpnv_t_V4	= 129,
    CMPEQn1_t_Jumpnv_nt_V4	= 130,
    CMPEQn1_t_Jumpnv_t_V4	= 131,
    CMPEQri	= 132,
    CMPEQri_f_Jumpnv_nt_V4	= 133,
    CMPEQri_f_Jumpnv_t_V4	= 134,
    CMPEQri_t_Jumpnv_nt_V4	= 135,
    CMPEQri_t_Jumpnv_t_V4	= 136,
    CMPEQrr	= 137,
    CMPEQrr_f_Jumpnv_nt_V4	= 138,
    CMPEQrr_f_Jumpnv_t_V4	= 139,
    CMPEQrr_t_Jumpnv_nt_V4	= 140,
    CMPEQrr_t_Jumpnv_t_V4	= 141,
    CMPGT64rr	= 142,
    CMPGTU64rr	= 143,
    CMPGTUri	= 144,
    CMPGTUri_f_Jumpnv_nt_V4	= 145,
    CMPGTUri_f_Jumpnv_t_V4	= 146,
    CMPGTUri_t_Jumpnv_nt_V4	= 147,
    CMPGTUri_t_Jumpnv_t_V4	= 148,
    CMPGTUrr	= 149,
    CMPGTUrr_f_Jumpnv_nt_V4	= 150,
    CMPGTUrr_f_Jumpnv_t_V4	= 151,
    CMPGTUrr_t_Jumpnv_nt_V4	= 152,
    CMPGTUrr_t_Jumpnv_t_V4	= 153,
    CMPGTn1_f_Jumpnv_nt_V4	= 154,
    CMPGTn1_f_Jumpnv_t_V4	= 155,
    CMPGTn1_t_Jumpnv_nt_V4	= 156,
    CMPGTn1_t_Jumpnv_t_V4	= 157,
    CMPGTri	= 158,
    CMPGTri_f_Jumpnv_nt_V4	= 159,
    CMPGTri_f_Jumpnv_t_V4	= 160,
    CMPGTri_t_Jumpnv_nt_V4	= 161,
    CMPGTri_t_Jumpnv_t_V4	= 162,
    CMPGTrr	= 163,
    CMPGTrr_f_Jumpnv_nt_V4	= 164,
    CMPGTrr_f_Jumpnv_t_V4	= 165,
    CMPGTrr_t_Jumpnv_nt_V4	= 166,
    CMPGTrr_t_Jumpnv_t_V4	= 167,
    CMPLTUrr_f_Jumpnv_nt_V4	= 168,
    CMPLTUrr_f_Jumpnv_t_V4	= 169,
    CMPLTUrr_t_Jumpnv_nt_V4	= 170,
    CMPLTUrr_t_Jumpnv_t_V4	= 171,
    CMPLTrr_f_Jumpnv_nt_V4	= 172,
    CMPLTrr_f_Jumpnv_t_V4	= 173,
    CMPLTrr_t_Jumpnv_nt_V4	= 174,
    CMPLTrr_t_Jumpnv_t_V4	= 175,
    CMPbEQri_V4	= 176,
    CMPbEQrr_sbsb_V4	= 177,
    CMPbEQrr_ubub_V4	= 178,
    CMPbGTUri_V4	= 179,
    CMPbGTUrr_V4	= 180,
    CMPbGTrr_V4	= 181,
    CMPhEQri_V4	= 182,
    CMPhEQrr_shl_V4	= 183,
    CMPhEQrr_xor_V4	= 184,
    CMPhGTUri_V4	= 185,
    CMPhGTUrr_V4	= 186,
    CMPhGTrr_shl_V4	= 187,
    CMPnotEQ_ri	= 188,
    CMPnotEQ_rr	= 189,
    CMPnotGTU_ri	= 190,
    CMPnotGTU_rr	= 191,
    CMPnotGT_ri	= 192,
    CMPnotGT_rr	= 193,
    COMBINE_Ii	= 194,
    COMBINE_Ir_V4	= 195,
    COMBINE_iI_V4	= 196,
    COMBINE_ii	= 197,
    COMBINE_rI_V4	= 198,
    COMBINE_rr	= 199,
    COMBINE_rr_cNotPt	= 200,
    COMBINE_rr_cPt	= 201,
    COMBINE_rr_cdnNotPt	= 202,
    COMBINE_rr_cdnPt	= 203,
    CONST32	= 204,
    CONST32GP_set	= 205,
    CONST32_Float_Real	= 206,
    CONST32_Int_Real	= 207,
    CONST32_Label	= 208,
    CONST32_set	= 209,
    CONST32_set_jt	= 210,
    CONST64_Float_Real	= 211,
    CONST64_Int_Real	= 212,
    CONVERT_d2df	= 213,
    CONVERT_d2sf	= 214,
    CONVERT_df2d	= 215,
    CONVERT_df2d_nchop	= 216,
    CONVERT_df2sf	= 217,
    CONVERT_df2ud	= 218,
    CONVERT_df2ud_nchop	= 219,
    CONVERT_df2uw	= 220,
    CONVERT_df2uw_nchop	= 221,
    CONVERT_df2w	= 222,
    CONVERT_df2w_nchop	= 223,
    CONVERT_sf2d	= 224,
    CONVERT_sf2d_nchop	= 225,
    CONVERT_sf2df	= 226,
    CONVERT_sf2ud	= 227,
    CONVERT_sf2ud_nchop	= 228,
    CONVERT_sf2uw	= 229,
    CONVERT_sf2uw_nchop	= 230,
    CONVERT_sf2w	= 231,
    CONVERT_sf2w_nchop	= 232,
    CONVERT_ud2df	= 233,
    CONVERT_ud2sf	= 234,
    CONVERT_uw2df	= 235,
    CONVERT_uw2sf	= 236,
    CONVERT_w2df	= 237,
    CONVERT_w2sf	= 238,
    CTLZ64_rr	= 239,
    CTLZ_rr	= 240,
    CTTZ64_rr	= 241,
    CTTZ_rr	= 242,
    DEALLOCFRAME	= 243,
    DEALLOC_RET_V4	= 244,
    DEALLOC_RET_cNotPt_V4	= 245,
    DEALLOC_RET_cNotdnPnt_V4	= 246,
    DEALLOC_RET_cNotdnPt_V4	= 247,
    DEALLOC_RET_cPt_V4	= 248,
    DEALLOC_RET_cdnPnt_V4	= 249,
    DEALLOC_RET_cdnPt_V4	= 250,
    EH_RETURN_JMPR	= 251,
    ENDLOOP0	= 252,
    FCMPOEQ32_rr	= 253,
    FCMPOEQ64_rr	= 254,
    FCMPOGE32_rr	= 255,
    FCMPOGE64_rr	= 256,
    FCMPOGT32_rr	= 257,
    FCMPOGT64_rr	= 258,
    FCMPUEQ32_rr	= 259,
    FCMPUEQ64_rr	= 260,
    FCMPUGE32_rr	= 261,
    FCMPUGE64_rr	= 262,
    FCMPUGT32_rr	= 263,
    FCMPUGT64_rr	= 264,
    FCONST32_nsdata	= 265,
    FMADD_dp	= 266,
    FMADD_sp	= 267,
    FMAX_dp	= 268,
    FMAX_sp	= 269,
    FMIN_dp	= 270,
    FMIN_sp	= 271,
    HEXAGON_A2_abs	= 272,
    HEXAGON_A2_absp	= 273,
    HEXAGON_A2_abssat	= 274,
    HEXAGON_A2_add	= 275,
    HEXAGON_A2_addh_h16_hh	= 276,
    HEXAGON_A2_addh_h16_hl	= 277,
    HEXAGON_A2_addh_h16_lh	= 278,
    HEXAGON_A2_addh_h16_ll	= 279,
    HEXAGON_A2_addh_h16_sat_hh	= 280,
    HEXAGON_A2_addh_h16_sat_hl	= 281,
    HEXAGON_A2_addh_h16_sat_lh	= 282,
    HEXAGON_A2_addh_h16_sat_ll	= 283,
    HEXAGON_A2_addh_l16_hl	= 284,
    HEXAGON_A2_addh_l16_ll	= 285,
    HEXAGON_A2_addh_l16_sat_hl	= 286,
    HEXAGON_A2_addh_l16_sat_ll	= 287,
    HEXAGON_A2_addi	= 288,
    HEXAGON_A2_addp	= 289,
    HEXAGON_A2_addsat	= 290,
    HEXAGON_A2_and	= 291,
    HEXAGON_A2_andir	= 292,
    HEXAGON_A2_andp	= 293,
    HEXAGON_A2_aslh	= 294,
    HEXAGON_A2_asrh	= 295,
    HEXAGON_A2_combine_hh	= 296,
    HEXAGON_A2_combine_hl	= 297,
    HEXAGON_A2_combine_lh	= 298,
    HEXAGON_A2_combine_ll	= 299,
    HEXAGON_A2_combineii	= 300,
    HEXAGON_A2_combinew	= 301,
    HEXAGON_A2_max	= 302,
    HEXAGON_A2_maxu	= 303,
    HEXAGON_A2_min	= 304,
    HEXAGON_A2_minu	= 305,
    HEXAGON_A2_neg	= 306,
    HEXAGON_A2_negp	= 307,
    HEXAGON_A2_negsat	= 308,
    HEXAGON_A2_not	= 309,
    HEXAGON_A2_notp	= 310,
    HEXAGON_A2_or	= 311,
    HEXAGON_A2_orir	= 312,
    HEXAGON_A2_orp	= 313,
    HEXAGON_A2_sat	= 314,
    HEXAGON_A2_satb	= 315,
    HEXAGON_A2_sath	= 316,
    HEXAGON_A2_satub	= 317,
    HEXAGON_A2_satuh	= 318,
    HEXAGON_A2_sub	= 319,
    HEXAGON_A2_subh_h16_hh	= 320,
    HEXAGON_A2_subh_h16_hl	= 321,
    HEXAGON_A2_subh_h16_lh	= 322,
    HEXAGON_A2_subh_h16_ll	= 323,
    HEXAGON_A2_subh_h16_sat_hh	= 324,
    HEXAGON_A2_subh_h16_sat_hl	= 325,
    HEXAGON_A2_subh_h16_sat_lh	= 326,
    HEXAGON_A2_subh_h16_sat_ll	= 327,
    HEXAGON_A2_subh_l16_hl	= 328,
    HEXAGON_A2_subh_l16_ll	= 329,
    HEXAGON_A2_subh_l16_sat_hl	= 330,
    HEXAGON_A2_subh_l16_sat_ll	= 331,
    HEXAGON_A2_subp	= 332,
    HEXAGON_A2_subri	= 333,
    HEXAGON_A2_subsat	= 334,
    HEXAGON_A2_svaddh	= 335,
    HEXAGON_A2_svaddhs	= 336,
    HEXAGON_A2_svadduhs	= 337,
    HEXAGON_A2_svavgh	= 338,
    HEXAGON_A2_svavghs	= 339,
    HEXAGON_A2_svnavgh	= 340,
    HEXAGON_A2_svsubh	= 341,
    HEXAGON_A2_svsubhs	= 342,
    HEXAGON_A2_svsubuhs	= 343,
    HEXAGON_A2_swiz	= 344,
    HEXAGON_A2_sxtb	= 345,
    HEXAGON_A2_sxth	= 346,
    HEXAGON_A2_sxtw	= 347,
    HEXAGON_A2_tfr	= 348,
    HEXAGON_A2_tfrih	= 349,
    HEXAGON_A2_tfril	= 350,
    HEXAGON_A2_tfrp	= 351,
    HEXAGON_A2_tfrpi	= 352,
    HEXAGON_A2_tfrsi	= 353,
    HEXAGON_A2_vabsh	= 354,
    HEXAGON_A2_vabshsat	= 355,
    HEXAGON_A2_vabsw	= 356,
    HEXAGON_A2_vabswsat	= 357,
    HEXAGON_A2_vaddh	= 358,
    HEXAGON_A2_vaddhs	= 359,
    HEXAGON_A2_vaddub	= 360,
    HEXAGON_A2_vaddubs	= 361,
    HEXAGON_A2_vadduhs	= 362,
    HEXAGON_A2_vaddw	= 363,
    HEXAGON_A2_vaddws	= 364,
    HEXAGON_A2_vavgh	= 365,
    HEXAGON_A2_vavghcr	= 366,
    HEXAGON_A2_vavghr	= 367,
    HEXAGON_A2_vavgub	= 368,
    HEXAGON_A2_vavgubr	= 369,
    HEXAGON_A2_vavguh	= 370,
    HEXAGON_A2_vavguhr	= 371,
    HEXAGON_A2_vavguw	= 372,
    HEXAGON_A2_vavguwr	= 373,
    HEXAGON_A2_vavgw	= 374,
    HEXAGON_A2_vavgwcr	= 375,
    HEXAGON_A2_vavgwr	= 376,
    HEXAGON_A2_vcmpbeq	= 377,
    HEXAGON_A2_vcmpbgtu	= 378,
    HEXAGON_A2_vcmpheq	= 379,
    HEXAGON_A2_vcmphgt	= 380,
    HEXAGON_A2_vcmphgtu	= 381,
    HEXAGON_A2_vcmpweq	= 382,
    HEXAGON_A2_vcmpwgt	= 383,
    HEXAGON_A2_vcmpwgtu	= 384,
    HEXAGON_A2_vconj	= 385,
    HEXAGON_A2_vmaxh	= 386,
    HEXAGON_A2_vmaxub	= 387,
    HEXAGON_A2_vmaxuh	= 388,
    HEXAGON_A2_vmaxuw	= 389,
    HEXAGON_A2_vmaxw	= 390,
    HEXAGON_A2_vminh	= 391,
    HEXAGON_A2_vminub	= 392,
    HEXAGON_A2_vminuh	= 393,
    HEXAGON_A2_vminuw	= 394,
    HEXAGON_A2_vminw	= 395,
    HEXAGON_A2_vnavgh	= 396,
    HEXAGON_A2_vnavghcr	= 397,
    HEXAGON_A2_vnavghr	= 398,
    HEXAGON_A2_vnavgw	= 399,
    HEXAGON_A2_vnavgwcr	= 400,
    HEXAGON_A2_vnavgwr	= 401,
    HEXAGON_A2_vraddub	= 402,
    HEXAGON_A2_vraddub_acc	= 403,
    HEXAGON_A2_vrsadub	= 404,
    HEXAGON_A2_vrsadub_acc	= 405,
    HEXAGON_A2_vsubh	= 406,
    HEXAGON_A2_vsubhs	= 407,
    HEXAGON_A2_vsubub	= 408,
    HEXAGON_A2_vsububs	= 409,
    HEXAGON_A2_vsubuhs	= 410,
    HEXAGON_A2_vsubw	= 411,
    HEXAGON_A2_vsubws	= 412,
    HEXAGON_A2_xor	= 413,
    HEXAGON_A2_xorp	= 414,
    HEXAGON_A2_zxtb	= 415,
    HEXAGON_A2_zxth	= 416,
    HEXAGON_A4_cround_ri	= 417,
    HEXAGON_A4_cround_rr	= 418,
    HEXAGON_A4_modwrapu	= 419,
    HEXAGON_A4_round_ri	= 420,
    HEXAGON_A4_round_ri_sat	= 421,
    HEXAGON_A4_round_rr	= 422,
    HEXAGON_A4_round_rr_sat	= 423,
    HEXAGON_A5_vaddhubs	= 424,
    HEXAGON_C2_all8	= 425,
    HEXAGON_C2_and	= 426,
    HEXAGON_C2_andn	= 427,
    HEXAGON_C2_any8	= 428,
    HEXAGON_C2_cmpeq	= 429,
    HEXAGON_C2_cmpeqi	= 430,
    HEXAGON_C2_cmpeqp	= 431,
    HEXAGON_C2_cmpgei	= 432,
    HEXAGON_C2_cmpgeui	= 433,
    HEXAGON_C2_cmpgt	= 434,
    HEXAGON_C2_cmpgti	= 435,
    HEXAGON_C2_cmpgtp	= 436,
    HEXAGON_C2_cmpgtu	= 437,
    HEXAGON_C2_cmpgtui	= 438,
    HEXAGON_C2_cmpgtup	= 439,
    HEXAGON_C2_cmplt	= 440,
    HEXAGON_C2_cmpltu	= 441,
    HEXAGON_C2_mask	= 442,
    HEXAGON_C2_mux	= 443,
    HEXAGON_C2_muxii	= 444,
    HEXAGON_C2_muxir	= 445,
    HEXAGON_C2_muxri	= 446,
    HEXAGON_C2_not	= 447,
    HEXAGON_C2_or	= 448,
    HEXAGON_C2_orn	= 449,
    HEXAGON_C2_pxfer_map	= 450,
    HEXAGON_C2_tfrpr	= 451,
    HEXAGON_C2_tfrrp	= 452,
    HEXAGON_C2_vitpack	= 453,
    HEXAGON_C2_vmux	= 454,
    HEXAGON_C2_xor	= 455,
    HEXAGON_C4_fastcorner9	= 456,
    HEXAGON_C4_fastcorner9_not	= 457,
    HEXAGON_F2_conv_d2df	= 458,
    HEXAGON_F2_conv_d2sf	= 459,
    HEXAGON_F2_conv_df2d	= 460,
    HEXAGON_F2_conv_df2d_chop	= 461,
    HEXAGON_F2_conv_df2sf	= 462,
    HEXAGON_F2_conv_df2ud	= 463,
    HEXAGON_F2_conv_df2ud_chop	= 464,
    HEXAGON_F2_conv_df2uw	= 465,
    HEXAGON_F2_conv_df2uw_chop	= 466,
    HEXAGON_F2_conv_df2w	= 467,
    HEXAGON_F2_conv_df2w_chop	= 468,
    HEXAGON_F2_conv_sf2d	= 469,
    HEXAGON_F2_conv_sf2d_chop	= 470,
    HEXAGON_F2_conv_sf2df	= 471,
    HEXAGON_F2_conv_sf2ud	= 472,
    HEXAGON_F2_conv_sf2ud_chop	= 473,
    HEXAGON_F2_conv_sf2uw	= 474,
    HEXAGON_F2_conv_sf2uw_chop	= 475,
    HEXAGON_F2_conv_sf2w	= 476,
    HEXAGON_F2_conv_sf2w_chop	= 477,
    HEXAGON_F2_conv_ud2df	= 478,
    HEXAGON_F2_conv_ud2sf	= 479,
    HEXAGON_F2_conv_uw2df	= 480,
    HEXAGON_F2_conv_uw2sf	= 481,
    HEXAGON_F2_conv_w2df	= 482,
    HEXAGON_F2_conv_w2sf	= 483,
    HEXAGON_F2_dfadd	= 484,
    HEXAGON_F2_dfclass	= 485,
    HEXAGON_F2_dfcmpeq	= 486,
    HEXAGON_F2_dfcmpge	= 487,
    HEXAGON_F2_dfcmpgt	= 488,
    HEXAGON_F2_dfcmpuo	= 489,
    HEXAGON_F2_dffixupd	= 490,
    HEXAGON_F2_dffixupn	= 491,
    HEXAGON_F2_dffixupr	= 492,
    HEXAGON_F2_dffma	= 493,
    HEXAGON_F2_dffma_lib	= 494,
    HEXAGON_F2_dffma_sc	= 495,
    HEXAGON_F2_dffms	= 496,
    HEXAGON_F2_dffms_lib	= 497,
    HEXAGON_F2_dfimm_n	= 498,
    HEXAGON_F2_dfimm_p	= 499,
    HEXAGON_F2_dfmax	= 500,
    HEXAGON_F2_dfmin	= 501,
    HEXAGON_F2_dfmpy	= 502,
    HEXAGON_F2_dfsub	= 503,
    HEXAGON_F2_sfadd	= 504,
    HEXAGON_F2_sfclass	= 505,
    HEXAGON_F2_sfcmpeq	= 506,
    HEXAGON_F2_sfcmpge	= 507,
    HEXAGON_F2_sfcmpgt	= 508,
    HEXAGON_F2_sfcmpuo	= 509,
    HEXAGON_F2_sffixupd	= 510,
    HEXAGON_F2_sffixupn	= 511,
    HEXAGON_F2_sffixupr	= 512,
    HEXAGON_F2_sffma	= 513,
    HEXAGON_F2_sffma_lib	= 514,
    HEXAGON_F2_sffma_sc	= 515,
    HEXAGON_F2_sffms	= 516,
    HEXAGON_F2_sffms_lib	= 517,
    HEXAGON_F2_sfimm_n	= 518,
    HEXAGON_F2_sfimm_p	= 519,
    HEXAGON_F2_sfmax	= 520,
    HEXAGON_F2_sfmin	= 521,
    HEXAGON_F2_sfmpy	= 522,
    HEXAGON_F2_sfsub	= 523,
    HEXAGON_M2_acci	= 524,
    HEXAGON_M2_accii	= 525,
    HEXAGON_M2_cmaci_s0	= 526,
    HEXAGON_M2_cmacr_s0	= 527,
    HEXAGON_M2_cmacs_s0	= 528,
    HEXAGON_M2_cmacs_s1	= 529,
    HEXAGON_M2_cmacsc_s0	= 530,
    HEXAGON_M2_cmacsc_s1	= 531,
    HEXAGON_M2_cmpyi_s0	= 532,
    HEXAGON_M2_cmpyr_s0	= 533,
    HEXAGON_M2_cmpyrs_s0	= 534,
    HEXAGON_M2_cmpyrs_s1	= 535,
    HEXAGON_M2_cmpyrsc_s0	= 536,
    HEXAGON_M2_cmpyrsc_s1	= 537,
    HEXAGON_M2_cmpys_s0	= 538,
    HEXAGON_M2_cmpys_s1	= 539,
    HEXAGON_M2_cmpysc_s0	= 540,
    HEXAGON_M2_cmpysc_s1	= 541,
    HEXAGON_M2_cnacs_s0	= 542,
    HEXAGON_M2_cnacs_s1	= 543,
    HEXAGON_M2_cnacsc_s0	= 544,
    HEXAGON_M2_cnacsc_s1	= 545,
    HEXAGON_M2_dpmpyss_acc_s0	= 546,
    HEXAGON_M2_dpmpyss_nac_s0	= 547,
    HEXAGON_M2_dpmpyss_rnd_s0	= 548,
    HEXAGON_M2_dpmpyss_s0	= 549,
    HEXAGON_M2_dpmpyuu_acc_s0	= 550,
    HEXAGON_M2_dpmpyuu_nac_s0	= 551,
    HEXAGON_M2_dpmpyuu_s0	= 552,
    HEXAGON_M2_hmmpyh_rs1	= 553,
    HEXAGON_M2_hmmpyl_rs1	= 554,
    HEXAGON_M2_maci	= 555,
    HEXAGON_M2_macsin	= 556,
    HEXAGON_M2_macsip	= 557,
    HEXAGON_M2_mmachs_rs0	= 558,
    HEXAGON_M2_mmachs_rs1	= 559,
    HEXAGON_M2_mmachs_s0	= 560,
    HEXAGON_M2_mmachs_s1	= 561,
    HEXAGON_M2_mmacls_rs0	= 562,
    HEXAGON_M2_mmacls_rs1	= 563,
    HEXAGON_M2_mmacls_s0	= 564,
    HEXAGON_M2_mmacls_s1	= 565,
    HEXAGON_M2_mmacuhs_rs0	= 566,
    HEXAGON_M2_mmacuhs_rs1	= 567,
    HEXAGON_M2_mmacuhs_s0	= 568,
    HEXAGON_M2_mmacuhs_s1	= 569,
    HEXAGON_M2_mmaculs_rs0	= 570,
    HEXAGON_M2_mmaculs_rs1	= 571,
    HEXAGON_M2_mmaculs_s0	= 572,
    HEXAGON_M2_mmaculs_s1	= 573,
    HEXAGON_M2_mmpyh_rs0	= 574,
    HEXAGON_M2_mmpyh_rs1	= 575,
    HEXAGON_M2_mmpyh_s0	= 576,
    HEXAGON_M2_mmpyh_s1	= 577,
    HEXAGON_M2_mmpyl_rs0	= 578,
    HEXAGON_M2_mmpyl_rs1	= 579,
    HEXAGON_M2_mmpyl_s0	= 580,
    HEXAGON_M2_mmpyl_s1	= 581,
    HEXAGON_M2_mmpyuh_rs0	= 582,
    HEXAGON_M2_mmpyuh_rs1	= 583,
    HEXAGON_M2_mmpyuh_s0	= 584,
    HEXAGON_M2_mmpyuh_s1	= 585,
    HEXAGON_M2_mmpyul_rs0	= 586,
    HEXAGON_M2_mmpyul_rs1	= 587,
    HEXAGON_M2_mmpyul_s0	= 588,
    HEXAGON_M2_mmpyul_s1	= 589,
    HEXAGON_M2_mpy_acc_hh_s0	= 590,
    HEXAGON_M2_mpy_acc_hh_s1	= 591,
    HEXAGON_M2_mpy_acc_hl_s0	= 592,
    HEXAGON_M2_mpy_acc_hl_s1	= 593,
    HEXAGON_M2_mpy_acc_lh_s0	= 594,
    HEXAGON_M2_mpy_acc_lh_s1	= 595,
    HEXAGON_M2_mpy_acc_ll_s0	= 596,
    HEXAGON_M2_mpy_acc_ll_s1	= 597,
    HEXAGON_M2_mpy_acc_sat_hh_s0	= 598,
    HEXAGON_M2_mpy_acc_sat_hh_s1	= 599,
    HEXAGON_M2_mpy_acc_sat_hl_s0	= 600,
    HEXAGON_M2_mpy_acc_sat_hl_s1	= 601,
    HEXAGON_M2_mpy_acc_sat_lh_s0	= 602,
    HEXAGON_M2_mpy_acc_sat_lh_s1	= 603,
    HEXAGON_M2_mpy_acc_sat_ll_s0	= 604,
    HEXAGON_M2_mpy_acc_sat_ll_s1	= 605,
    HEXAGON_M2_mpy_hh_s0	= 606,
    HEXAGON_M2_mpy_hh_s1	= 607,
    HEXAGON_M2_mpy_hl_s0	= 608,
    HEXAGON_M2_mpy_hl_s1	= 609,
    HEXAGON_M2_mpy_lh_s0	= 610,
    HEXAGON_M2_mpy_lh_s1	= 611,
    HEXAGON_M2_mpy_ll_s0	= 612,
    HEXAGON_M2_mpy_ll_s1	= 613,
    HEXAGON_M2_mpy_nac_hh_s0	= 614,
    HEXAGON_M2_mpy_nac_hh_s1	= 615,
    HEXAGON_M2_mpy_nac_hl_s0	= 616,
    HEXAGON_M2_mpy_nac_hl_s1	= 617,
    HEXAGON_M2_mpy_nac_lh_s0	= 618,
    HEXAGON_M2_mpy_nac_lh_s1	= 619,
    HEXAGON_M2_mpy_nac_ll_s0	= 620,
    HEXAGON_M2_mpy_nac_ll_s1	= 621,
    HEXAGON_M2_mpy_nac_sat_hh_s0	= 622,
    HEXAGON_M2_mpy_nac_sat_hh_s1	= 623,
    HEXAGON_M2_mpy_nac_sat_hl_s0	= 624,
    HEXAGON_M2_mpy_nac_sat_hl_s1	= 625,
    HEXAGON_M2_mpy_nac_sat_lh_s0	= 626,
    HEXAGON_M2_mpy_nac_sat_lh_s1	= 627,
    HEXAGON_M2_mpy_nac_sat_ll_s0	= 628,
    HEXAGON_M2_mpy_nac_sat_ll_s1	= 629,
    HEXAGON_M2_mpy_rnd_hh_s0	= 630,
    HEXAGON_M2_mpy_rnd_hh_s1	= 631,
    HEXAGON_M2_mpy_rnd_hl_s0	= 632,
    HEXAGON_M2_mpy_rnd_hl_s1	= 633,
    HEXAGON_M2_mpy_rnd_lh_s0	= 634,
    HEXAGON_M2_mpy_rnd_lh_s1	= 635,
    HEXAGON_M2_mpy_rnd_ll_s0	= 636,
    HEXAGON_M2_mpy_rnd_ll_s1	= 637,
    HEXAGON_M2_mpy_sat_hh_s0	= 638,
    HEXAGON_M2_mpy_sat_hh_s1	= 639,
    HEXAGON_M2_mpy_sat_hl_s0	= 640,
    HEXAGON_M2_mpy_sat_hl_s1	= 641,
    HEXAGON_M2_mpy_sat_lh_s0	= 642,
    HEXAGON_M2_mpy_sat_lh_s1	= 643,
    HEXAGON_M2_mpy_sat_ll_s0	= 644,
    HEXAGON_M2_mpy_sat_ll_s1	= 645,
    HEXAGON_M2_mpy_sat_rnd_hh_s0	= 646,
    HEXAGON_M2_mpy_sat_rnd_hh_s1	= 647,
    HEXAGON_M2_mpy_sat_rnd_hl_s0	= 648,
    HEXAGON_M2_mpy_sat_rnd_hl_s1	= 649,
    HEXAGON_M2_mpy_sat_rnd_lh_s0	= 650,
    HEXAGON_M2_mpy_sat_rnd_lh_s1	= 651,
    HEXAGON_M2_mpy_sat_rnd_ll_s0	= 652,
    HEXAGON_M2_mpy_sat_rnd_ll_s1	= 653,
    HEXAGON_M2_mpy_up	= 654,
    HEXAGON_M2_mpyd_acc_hh_s0	= 655,
    HEXAGON_M2_mpyd_acc_hh_s1	= 656,
    HEXAGON_M2_mpyd_acc_hl_s0	= 657,
    HEXAGON_M2_mpyd_acc_hl_s1	= 658,
    HEXAGON_M2_mpyd_acc_lh_s0	= 659,
    HEXAGON_M2_mpyd_acc_lh_s1	= 660,
    HEXAGON_M2_mpyd_acc_ll_s0	= 661,
    HEXAGON_M2_mpyd_acc_ll_s1	= 662,
    HEXAGON_M2_mpyd_hh_s0	= 663,
    HEXAGON_M2_mpyd_hh_s1	= 664,
    HEXAGON_M2_mpyd_hl_s0	= 665,
    HEXAGON_M2_mpyd_hl_s1	= 666,
    HEXAGON_M2_mpyd_lh_s0	= 667,
    HEXAGON_M2_mpyd_lh_s1	= 668,
    HEXAGON_M2_mpyd_ll_s0	= 669,
    HEXAGON_M2_mpyd_ll_s1	= 670,
    HEXAGON_M2_mpyd_nac_hh_s0	= 671,
    HEXAGON_M2_mpyd_nac_hh_s1	= 672,
    HEXAGON_M2_mpyd_nac_hl_s0	= 673,
    HEXAGON_M2_mpyd_nac_hl_s1	= 674,
    HEXAGON_M2_mpyd_nac_lh_s0	= 675,
    HEXAGON_M2_mpyd_nac_lh_s1	= 676,
    HEXAGON_M2_mpyd_nac_ll_s0	= 677,
    HEXAGON_M2_mpyd_nac_ll_s1	= 678,
    HEXAGON_M2_mpyd_rnd_hh_s0	= 679,
    HEXAGON_M2_mpyd_rnd_hh_s1	= 680,
    HEXAGON_M2_mpyd_rnd_hl_s0	= 681,
    HEXAGON_M2_mpyd_rnd_hl_s1	= 682,
    HEXAGON_M2_mpyd_rnd_lh_s0	= 683,
    HEXAGON_M2_mpyd_rnd_lh_s1	= 684,
    HEXAGON_M2_mpyd_rnd_ll_s0	= 685,
    HEXAGON_M2_mpyd_rnd_ll_s1	= 686,
    HEXAGON_M2_mpyi	= 687,
    HEXAGON_M2_mpyu_acc_hh_s0	= 688,
    HEXAGON_M2_mpyu_acc_hh_s1	= 689,
    HEXAGON_M2_mpyu_acc_hl_s0	= 690,
    HEXAGON_M2_mpyu_acc_hl_s1	= 691,
    HEXAGON_M2_mpyu_acc_lh_s0	= 692,
    HEXAGON_M2_mpyu_acc_lh_s1	= 693,
    HEXAGON_M2_mpyu_acc_ll_s0	= 694,
    HEXAGON_M2_mpyu_acc_ll_s1	= 695,
    HEXAGON_M2_mpyu_hh_s0	= 696,
    HEXAGON_M2_mpyu_hh_s1	= 697,
    HEXAGON_M2_mpyu_hl_s0	= 698,
    HEXAGON_M2_mpyu_hl_s1	= 699,
    HEXAGON_M2_mpyu_lh_s0	= 700,
    HEXAGON_M2_mpyu_lh_s1	= 701,
    HEXAGON_M2_mpyu_ll_s0	= 702,
    HEXAGON_M2_mpyu_ll_s1	= 703,
    HEXAGON_M2_mpyu_nac_hh_s0	= 704,
    HEXAGON_M2_mpyu_nac_hh_s1	= 705,
    HEXAGON_M2_mpyu_nac_hl_s0	= 706,
    HEXAGON_M2_mpyu_nac_hl_s1	= 707,
    HEXAGON_M2_mpyu_nac_lh_s0	= 708,
    HEXAGON_M2_mpyu_nac_lh_s1	= 709,
    HEXAGON_M2_mpyu_nac_ll_s0	= 710,
    HEXAGON_M2_mpyu_nac_ll_s1	= 711,
    HEXAGON_M2_mpyu_up	= 712,
    HEXAGON_M2_mpyud_acc_hh_s0	= 713,
    HEXAGON_M2_mpyud_acc_hh_s1	= 714,
    HEXAGON_M2_mpyud_acc_hl_s0	= 715,
    HEXAGON_M2_mpyud_acc_hl_s1	= 716,
    HEXAGON_M2_mpyud_acc_lh_s0	= 717,
    HEXAGON_M2_mpyud_acc_lh_s1	= 718,
    HEXAGON_M2_mpyud_acc_ll_s0	= 719,
    HEXAGON_M2_mpyud_acc_ll_s1	= 720,
    HEXAGON_M2_mpyud_hh_s0	= 721,
    HEXAGON_M2_mpyud_hh_s1	= 722,
    HEXAGON_M2_mpyud_hl_s0	= 723,
    HEXAGON_M2_mpyud_hl_s1	= 724,
    HEXAGON_M2_mpyud_lh_s0	= 725,
    HEXAGON_M2_mpyud_lh_s1	= 726,
    HEXAGON_M2_mpyud_ll_s0	= 727,
    HEXAGON_M2_mpyud_ll_s1	= 728,
    HEXAGON_M2_mpyud_nac_hh_s0	= 729,
    HEXAGON_M2_mpyud_nac_hh_s1	= 730,
    HEXAGON_M2_mpyud_nac_hl_s0	= 731,
    HEXAGON_M2_mpyud_nac_hl_s1	= 732,
    HEXAGON_M2_mpyud_nac_lh_s0	= 733,
    HEXAGON_M2_mpyud_nac_lh_s1	= 734,
    HEXAGON_M2_mpyud_nac_ll_s0	= 735,
    HEXAGON_M2_mpyud_nac_ll_s1	= 736,
    HEXAGON_M2_mpyui	= 737,
    HEXAGON_M2_nacci	= 738,
    HEXAGON_M2_naccii	= 739,
    HEXAGON_M2_subacc	= 740,
    HEXAGON_M2_vabsdiffh	= 741,
    HEXAGON_M2_vabsdiffw	= 742,
    HEXAGON_M2_vcmac_s0_sat_i	= 743,
    HEXAGON_M2_vcmac_s0_sat_r	= 744,
    HEXAGON_M2_vcmpy_s0_sat_i	= 745,
    HEXAGON_M2_vcmpy_s0_sat_r	= 746,
    HEXAGON_M2_vcmpy_s1_sat_i	= 747,
    HEXAGON_M2_vcmpy_s1_sat_r	= 748,
    HEXAGON_M2_vdmacs_s0	= 749,
    HEXAGON_M2_vdmacs_s1	= 750,
    HEXAGON_M2_vdmpyrs_s0	= 751,
    HEXAGON_M2_vdmpyrs_s1	= 752,
    HEXAGON_M2_vdmpys_s0	= 753,
    HEXAGON_M2_vdmpys_s1	= 754,
    HEXAGON_M2_vmac2	= 755,
    HEXAGON_M2_vmac2es	= 756,
    HEXAGON_M2_vmac2es_s0	= 757,
    HEXAGON_M2_vmac2es_s1	= 758,
    HEXAGON_M2_vmac2s_s0	= 759,
    HEXAGON_M2_vmac2s_s1	= 760,
    HEXAGON_M2_vmpy2es_s0	= 761,
    HEXAGON_M2_vmpy2es_s1	= 762,
    HEXAGON_M2_vmpy2s_s0	= 763,
    HEXAGON_M2_vmpy2s_s0pack	= 764,
    HEXAGON_M2_vmpy2s_s1	= 765,
    HEXAGON_M2_vmpy2s_s1pack	= 766,
    HEXAGON_M2_vrcmaci_s0	= 767,
    HEXAGON_M2_vrcmaci_s0c	= 768,
    HEXAGON_M2_vrcmacr_s0	= 769,
    HEXAGON_M2_vrcmacr_s0c	= 770,
    HEXAGON_M2_vrcmpyi_s0	= 771,
    HEXAGON_M2_vrcmpyi_s0c	= 772,
    HEXAGON_M2_vrcmpyr_s0	= 773,
    HEXAGON_M2_vrcmpyr_s0c	= 774,
    HEXAGON_M2_vrmac_s0	= 775,
    HEXAGON_M2_vrmpy_s0	= 776,
    HEXAGON_M2_xor_xacc	= 777,
    HEXAGON_M4_and_and	= 778,
    HEXAGON_M4_and_andn	= 779,
    HEXAGON_M4_and_or	= 780,
    HEXAGON_M4_and_xor	= 781,
    HEXAGON_M4_or_and	= 782,
    HEXAGON_M4_or_andn	= 783,
    HEXAGON_M4_or_or	= 784,
    HEXAGON_M4_or_xor	= 785,
    HEXAGON_M4_xor_and	= 786,
    HEXAGON_M4_xor_andn	= 787,
    HEXAGON_M4_xor_or	= 788,
    HEXAGON_M5_vdmacbsu	= 789,
    HEXAGON_M5_vdmpybsu	= 790,
    HEXAGON_M5_vmacbsu	= 791,
    HEXAGON_M5_vmacbuu	= 792,
    HEXAGON_M5_vmpybsu	= 793,
    HEXAGON_M5_vmpybuu	= 794,
    HEXAGON_M5_vrmacbsu	= 795,
    HEXAGON_M5_vrmacbuu	= 796,
    HEXAGON_M5_vrmpybsu	= 797,
    HEXAGON_M5_vrmpybuu	= 798,
    HEXAGON_S2_addasl_rrri	= 799,
    HEXAGON_S2_asl_i_p	= 800,
    HEXAGON_S2_asl_i_p_acc	= 801,
    HEXAGON_S2_asl_i_p_and	= 802,
    HEXAGON_S2_asl_i_p_nac	= 803,
    HEXAGON_S2_asl_i_p_or	= 804,
    HEXAGON_S2_asl_i_p_xacc	= 805,
    HEXAGON_S2_asl_i_r	= 806,
    HEXAGON_S2_asl_i_r_acc	= 807,
    HEXAGON_S2_asl_i_r_and	= 808,
    HEXAGON_S2_asl_i_r_nac	= 809,
    HEXAGON_S2_asl_i_r_or	= 810,
    HEXAGON_S2_asl_i_r_sat	= 811,
    HEXAGON_S2_asl_i_r_xacc	= 812,
    HEXAGON_S2_asl_i_vh	= 813,
    HEXAGON_S2_asl_i_vw	= 814,
    HEXAGON_S2_asl_r_p	= 815,
    HEXAGON_S2_asl_r_p_acc	= 816,
    HEXAGON_S2_asl_r_p_and	= 817,
    HEXAGON_S2_asl_r_p_nac	= 818,
    HEXAGON_S2_asl_r_p_or	= 819,
    HEXAGON_S2_asl_r_r	= 820,
    HEXAGON_S2_asl_r_r_acc	= 821,
    HEXAGON_S2_asl_r_r_and	= 822,
    HEXAGON_S2_asl_r_r_nac	= 823,
    HEXAGON_S2_asl_r_r_or	= 824,
    HEXAGON_S2_asl_r_r_sat	= 825,
    HEXAGON_S2_asl_r_vh	= 826,
    HEXAGON_S2_asl_r_vw	= 827,
    HEXAGON_S2_asr_i_p	= 828,
    HEXAGON_S2_asr_i_p_acc	= 829,
    HEXAGON_S2_asr_i_p_and	= 830,
    HEXAGON_S2_asr_i_p_nac	= 831,
    HEXAGON_S2_asr_i_p_or	= 832,
    HEXAGON_S2_asr_i_p_rnd	= 833,
    HEXAGON_S2_asr_i_p_rnd_goodsyntax	= 834,
    HEXAGON_S2_asr_i_r	= 835,
    HEXAGON_S2_asr_i_r_acc	= 836,
    HEXAGON_S2_asr_i_r_and	= 837,
    HEXAGON_S2_asr_i_r_nac	= 838,
    HEXAGON_S2_asr_i_r_or	= 839,
    HEXAGON_S2_asr_i_r_rnd	= 840,
    HEXAGON_S2_asr_i_r_rnd_goodsyntax	= 841,
    HEXAGON_S2_asr_i_svw_trun	= 842,
    HEXAGON_S2_asr_i_vh	= 843,
    HEXAGON_S2_asr_i_vw	= 844,
    HEXAGON_S2_asr_r_p	= 845,
    HEXAGON_S2_asr_r_p_acc	= 846,
    HEXAGON_S2_asr_r_p_and	= 847,
    HEXAGON_S2_asr_r_p_nac	= 848,
    HEXAGON_S2_asr_r_p_or	= 849,
    HEXAGON_S2_asr_r_r	= 850,
    HEXAGON_S2_asr_r_r_acc	= 851,
    HEXAGON_S2_asr_r_r_and	= 852,
    HEXAGON_S2_asr_r_r_nac	= 853,
    HEXAGON_S2_asr_r_r_or	= 854,
    HEXAGON_S2_asr_r_r_sat	= 855,
    HEXAGON_S2_asr_r_svw_trun	= 856,
    HEXAGON_S2_asr_r_vh	= 857,
    HEXAGON_S2_asr_r_vw	= 858,
    HEXAGON_S2_cl0	= 859,
    HEXAGON_S2_cl0p	= 860,
    HEXAGON_S2_cl1	= 861,
    HEXAGON_S2_cl1p	= 862,
    HEXAGON_S2_clb	= 863,
    HEXAGON_S2_clbnorm	= 864,
    HEXAGON_S2_clbp	= 865,
    HEXAGON_S2_clrbit_i	= 866,
    HEXAGON_S2_clrbit_r	= 867,
    HEXAGON_S2_ct0	= 868,
    HEXAGON_S2_ct1	= 869,
    HEXAGON_S2_extractu	= 870,
    HEXAGON_S2_extractu_rp	= 871,
    HEXAGON_S2_extractup	= 872,
    HEXAGON_S2_extractup_rp	= 873,
    HEXAGON_S2_lsl_r_p	= 874,
    HEXAGON_S2_lsl_r_p_acc	= 875,
    HEXAGON_S2_lsl_r_p_and	= 876,
    HEXAGON_S2_lsl_r_p_nac	= 877,
    HEXAGON_S2_lsl_r_p_or	= 878,
    HEXAGON_S2_lsl_r_r	= 879,
    HEXAGON_S2_lsl_r_r_acc	= 880,
    HEXAGON_S2_lsl_r_r_and	= 881,
    HEXAGON_S2_lsl_r_r_nac	= 882,
    HEXAGON_S2_lsl_r_r_or	= 883,
    HEXAGON_S2_lsl_r_vh	= 884,
    HEXAGON_S2_lsl_r_vw	= 885,
    HEXAGON_S2_lsr_i_p	= 886,
    HEXAGON_S2_lsr_i_p_acc	= 887,
    HEXAGON_S2_lsr_i_p_and	= 888,
    HEXAGON_S2_lsr_i_p_nac	= 889,
    HEXAGON_S2_lsr_i_p_or	= 890,
    HEXAGON_S2_lsr_i_p_xacc	= 891,
    HEXAGON_S2_lsr_i_r	= 892,
    HEXAGON_S2_lsr_i_r_acc	= 893,
    HEXAGON_S2_lsr_i_r_and	= 894,
    HEXAGON_S2_lsr_i_r_nac	= 895,
    HEXAGON_S2_lsr_i_r_or	= 896,
    HEXAGON_S2_lsr_i_r_xacc	= 897,
    HEXAGON_S2_lsr_i_vh	= 898,
    HEXAGON_S2_lsr_i_vw	= 899,
    HEXAGON_S2_lsr_r_p	= 900,
    HEXAGON_S2_lsr_r_p_acc	= 901,
    HEXAGON_S2_lsr_r_p_and	= 902,
    HEXAGON_S2_lsr_r_p_nac	= 903,
    HEXAGON_S2_lsr_r_p_or	= 904,
    HEXAGON_S2_lsr_r_r	= 905,
    HEXAGON_S2_lsr_r_r_acc	= 906,
    HEXAGON_S2_lsr_r_r_and	= 907,
    HEXAGON_S2_lsr_r_r_nac	= 908,
    HEXAGON_S2_lsr_r_r_or	= 909,
    HEXAGON_S2_lsr_r_vh	= 910,
    HEXAGON_S2_lsr_r_vw	= 911,
    HEXAGON_S2_packhl	= 912,
    HEXAGON_S2_parityp	= 913,
    HEXAGON_S2_setbit_i	= 914,
    HEXAGON_S2_setbit_r	= 915,
    HEXAGON_S2_shuffeb	= 916,
    HEXAGON_S2_shuffeh	= 917,
    HEXAGON_S2_shuffob	= 918,
    HEXAGON_S2_shuffoh	= 919,
    HEXAGON_S2_svsathb	= 920,
    HEXAGON_S2_svsathub	= 921,
    HEXAGON_S2_togglebit_i	= 922,
    HEXAGON_S2_togglebit_r	= 923,
    HEXAGON_S2_tstbit_i	= 924,
    HEXAGON_S2_tstbit_r	= 925,
    HEXAGON_S2_valignib	= 926,
    HEXAGON_S2_valignrb	= 927,
    HEXAGON_S2_vcrotate	= 928,
    HEXAGON_S2_vrndpackwh	= 929,
    HEXAGON_S2_vrndpackwhs	= 930,
    HEXAGON_S2_vsathb	= 931,
    HEXAGON_S2_vsathb_nopack	= 932,
    HEXAGON_S2_vsathub	= 933,
    HEXAGON_S2_vsathub_nopack	= 934,
    HEXAGON_S2_vsatwh	= 935,
    HEXAGON_S2_vsatwh_nopack	= 936,
    HEXAGON_S2_vsatwuh	= 937,
    HEXAGON_S2_vsatwuh_nopack	= 938,
    HEXAGON_S2_vsplatrb	= 939,
    HEXAGON_S2_vsplatrh	= 940,
    HEXAGON_S2_vsxtbh	= 941,
    HEXAGON_S2_vsxthw	= 942,
    HEXAGON_S2_vtrunehb	= 943,
    HEXAGON_S2_vtrunewh	= 944,
    HEXAGON_S2_vtrunohb	= 945,
    HEXAGON_S2_vtrunowh	= 946,
    HEXAGON_S2_vzxtbh	= 947,
    HEXAGON_S2_vzxthw	= 948,
    HEXAGON_S4_or_andi	= 949,
    HEXAGON_S4_or_andix	= 950,
    HEXAGON_S4_or_ori	= 951,
    HEXAGON_S5_asrhub_rnd_sat_goodsyntax	= 952,
    HEXAGON_S5_asrhub_sat	= 953,
    HEXAGON_S5_popcountp	= 954,
    HEXAGON_S5_vasrhrnd_goodsyntax	= 955,
    HEXAGON_circ_ldd	= 956,
    HI	= 957,
    HI_jt	= 958,
    HI_label	= 959,
    HIi	= 960,
    Hexagon_A2_addpsat	= 961,
    Hexagon_A2_addsp	= 962,
    Hexagon_A2_maxp	= 963,
    Hexagon_A2_maxup	= 964,
    Hexagon_A4_andn	= 965,
    Hexagon_A4_combineir	= 966,
    Hexagon_A4_combineri	= 967,
    Hexagon_A4_orn	= 968,
    Hexagon_A4_rcmpeq	= 969,
    Hexagon_A4_rcmpeqi	= 970,
    Hexagon_A4_rcmpneq	= 971,
    Hexagon_A4_rcmpneqi	= 972,
    Hexagon_C2_bitsclr	= 973,
    Hexagon_C2_bitsclri	= 974,
    Hexagon_C2_bitsset	= 975,
    Hexagon_C4_and_and	= 976,
    Hexagon_C4_and_andn	= 977,
    Hexagon_C4_and_or	= 978,
    Hexagon_C4_and_orn	= 979,
    Hexagon_C4_cmplte	= 980,
    Hexagon_C4_cmpltei	= 981,
    Hexagon_C4_cmplteu	= 982,
    Hexagon_C4_cmplteui	= 983,
    Hexagon_C4_cmpneq	= 984,
    Hexagon_C4_cmpneqi	= 985,
    Hexagon_C4_fastcorner9	= 986,
    Hexagon_C4_fastcorner9_not	= 987,
    Hexagon_C4_or_and	= 988,
    Hexagon_C4_or_andn	= 989,
    Hexagon_C4_or_or	= 990,
    Hexagon_C4_or_orn	= 991,
    Hexagon_M2_mpysmi	= 992,
    Hexagon_M2_vradduh	= 993,
    Hexagon_M2_vrcmpys_acc_s1	= 994,
    Hexagon_M2_vrcmpys_s1	= 995,
    Hexagon_M2_vrcmpys_s1rp	= 996,
    Hexagon_M4_xor_xacc	= 997,
    Hexagon_S2_brev	= 998,
    Hexagon_S2_deinterleave	= 999,
    Hexagon_S2_insert	= 1000,
    Hexagon_S2_insert_rp	= 1001,
    Hexagon_S2_insertp	= 1002,
    Hexagon_S2_insertp_rp	= 1003,
    Hexagon_S2_interleave	= 1004,
    Hexagon_S2_lfsp	= 1005,
    Hexagon_S2_tableidxb_goodsyntax	= 1006,
    Hexagon_S2_tableidxd_goodsyntax	= 1007,
    Hexagon_S2_tableidxh_goodsyntax	= 1008,
    Hexagon_S2_tableidxw_goodsyntax	= 1009,
    Hexagon_S2_vspliceib	= 1010,
    Hexagon_S2_vsplicerb	= 1011,
    Hexagon_S4_addaddi	= 1012,
    Hexagon_S4_andnp	= 1013,
    Hexagon_S4_ornp	= 1014,
    Hexagon_S4_subaddi	= 1015,
    IMMEXT_b	= 1016,
    IMMEXT_c	= 1017,
    IMMEXT_g	= 1018,
    IMMEXT_i	= 1019,
    JMP	= 1020,
    JMPR	= 1021,
    JMPR_f	= 1022,
    JMPR_fnew_ntV3	= 1023,
    JMPR_fnew_tV3	= 1024,
    JMPR_t	= 1025,
    JMPR_tnew_ntV3	= 1026,
    JMPR_tnew_tV3	= 1027,
    JMP_f	= 1028,
    JMP_fnew_nt	= 1029,
    JMP_fnew_t	= 1030,
    JMP_t	= 1031,
    JMP_tnew_nt	= 1032,
    JMP_tnew_t	= 1033,
    JMPret	= 1034,
    JMPret_f	= 1035,
    JMPret_fnew_ntV3	= 1036,
    JMPret_fnew_tV3	= 1037,
    JMPret_t	= 1038,
    JMPret_tnew_ntV3	= 1039,
    JMPret_tnew_tV3	= 1040,
    LDb_GP_V4	= 1041,
    LDb_GP_cNotPt_V4	= 1042,
    LDb_GP_cPt_V4	= 1043,
    LDb_GP_cdnNotPt_V4	= 1044,
    LDb_GP_cdnPt_V4	= 1045,
    LDd_GP_V4	= 1046,
    LDd_GP_cNotPt_V4	= 1047,
    LDd_GP_cPt_V4	= 1048,
    LDd_GP_cdnNotPt_V4	= 1049,
    LDd_GP_cdnPt_V4	= 1050,
    LDh_GP_V4	= 1051,
    LDh_GP_cNotPt_V4	= 1052,
    LDh_GP_cPt_V4	= 1053,
    LDh_GP_cdnNotPt_V4	= 1054,
    LDh_GP_cdnPt_V4	= 1055,
    LDrib	= 1056,
    LDrib_abs_V4	= 1057,
    LDrib_abs_cNotPt_V4	= 1058,
    LDrib_abs_cPt_V4	= 1059,
    LDrib_abs_cdnNotPt_V4	= 1060,
    LDrib_abs_cdnPt_V4	= 1061,
    LDrib_abs_set_V4	= 1062,
    LDrib_cNotPt	= 1063,
    LDrib_cPt	= 1064,
    LDrib_cdnNotPt	= 1065,
    LDrib_cdnPt	= 1066,
    LDrib_ind_lo_V4	= 1067,
    LDrib_indexed	= 1068,
    LDrib_indexed_cNotPt	= 1069,
    LDrib_indexed_cPt	= 1070,
    LDrib_indexed_cdnNotPt	= 1071,
    LDrib_indexed_cdnPt	= 1072,
    LDrib_indexed_shl_V4	= 1073,
    LDrib_indexed_shl_cNotPt_V4	= 1074,
    LDrib_indexed_shl_cPt_V4	= 1075,
    LDrib_indexed_shl_cdnNotPt_V4	= 1076,
    LDrib_indexed_shl_cdnPt_V4	= 1077,
    LDrid	= 1078,
    LDrid_abs_V4	= 1079,
    LDrid_abs_cNotPt_V4	= 1080,
    LDrid_abs_cPt_V4	= 1081,
    LDrid_abs_cdnNotPt_V4	= 1082,
    LDrid_abs_cdnPt_V4	= 1083,
    LDrid_abs_set_V4	= 1084,
    LDrid_cNotPt	= 1085,
    LDrid_cPt	= 1086,
    LDrid_cdnNotPt	= 1087,
    LDrid_cdnPt	= 1088,
    LDrid_f	= 1089,
    LDrid_ind_lo_V4	= 1090,
    LDrid_indexed	= 1091,
    LDrid_indexed_cNotPt	= 1092,
    LDrid_indexed_cPt	= 1093,
    LDrid_indexed_cdnNotPt	= 1094,
    LDrid_indexed_cdnPt	= 1095,
    LDrid_indexed_f	= 1096,
    LDrid_indexed_shl_V4	= 1097,
    LDrid_indexed_shl_cNotPt_V4	= 1098,
    LDrid_indexed_shl_cPt_V4	= 1099,
    LDrid_indexed_shl_cdnNotPt_V4	= 1100,
    LDrid_indexed_shl_cdnPt_V4	= 1101,
    LDrih	= 1102,
    LDrih_abs_V4	= 1103,
    LDrih_abs_cNotPt_V4	= 1104,
    LDrih_abs_cPt_V4	= 1105,
    LDrih_abs_cdnNotPt_V4	= 1106,
    LDrih_abs_cdnPt_V4	= 1107,
    LDrih_abs_set_V4	= 1108,
    LDrih_cNotPt	= 1109,
    LDrih_cPt	= 1110,
    LDrih_cdnNotPt	= 1111,
    LDrih_cdnPt	= 1112,
    LDrih_ind_lo_V4	= 1113,
    LDrih_indexed	= 1114,
    LDrih_indexed_cNotPt	= 1115,
    LDrih_indexed_cPt	= 1116,
    LDrih_indexed_cdnNotPt	= 1117,
    LDrih_indexed_cdnPt	= 1118,
    LDrih_indexed_shl_V4	= 1119,
    LDrih_indexed_shl_cNotPt_V4	= 1120,
    LDrih_indexed_shl_cPt_V4	= 1121,
    LDrih_indexed_shl_cdnNotPt_V4	= 1122,
    LDrih_indexed_shl_cdnPt_V4	= 1123,
    LDriub	= 1124,
    LDriub_abs_V4	= 1125,
    LDriub_abs_cNotPt_V4	= 1126,
    LDriub_abs_cPt_V4	= 1127,
    LDriub_abs_cdnNotPt_V4	= 1128,
    LDriub_abs_cdnPt_V4	= 1129,
    LDriub_abs_set_V4	= 1130,
    LDriub_cNotPt	= 1131,
    LDriub_cPt	= 1132,
    LDriub_cdnNotPt	= 1133,
    LDriub_cdnPt	= 1134,
    LDriub_ind_anyext_lo_V4	= 1135,
    LDriub_ind_lo_V4	= 1136,
    LDriub_indexed	= 1137,
    LDriub_indexed_cNotPt	= 1138,
    LDriub_indexed_cPt	= 1139,
    LDriub_indexed_cdnNotPt	= 1140,
    LDriub_indexed_cdnPt	= 1141,
    LDriub_indexed_shl_V4	= 1142,
    LDriub_indexed_shl_cNotPt_V4	= 1143,
    LDriub_indexed_shl_cPt_V4	= 1144,
    LDriub_indexed_shl_cdnNotPt_V4	= 1145,
    LDriub_indexed_shl_cdnPt_V4	= 1146,
    LDriuh	= 1147,
    LDriuh_abs_V4	= 1148,
    LDriuh_abs_cNotPt_V4	= 1149,
    LDriuh_abs_cPt_V4	= 1150,
    LDriuh_abs_cdnNotPt_V4	= 1151,
    LDriuh_abs_cdnPt_V4	= 1152,
    LDriuh_abs_set_V4	= 1153,
    LDriuh_cNotPt	= 1154,
    LDriuh_cPt	= 1155,
    LDriuh_cdnNotPt	= 1156,
    LDriuh_cdnPt	= 1157,
    LDriuh_ind_anyext_lo_V4	= 1158,
    LDriuh_ind_lo_V4	= 1159,
    LDriuh_indexed	= 1160,
    LDriuh_indexed_cNotPt	= 1161,
    LDriuh_indexed_cPt	= 1162,
    LDriuh_indexed_cdnNotPt	= 1163,
    LDriuh_indexed_cdnPt	= 1164,
    LDriuh_indexed_shl_V4	= 1165,
    LDriuh_indexed_shl_cNotPt_V4	= 1166,
    LDriuh_indexed_shl_cPt_V4	= 1167,
    LDriuh_indexed_shl_cdnNotPt_V4	= 1168,
    LDriuh_indexed_shl_cdnPt_V4	= 1169,
    LDriw	= 1170,
    LDriw_abs_V4	= 1171,
    LDriw_abs_cNotPt_V4	= 1172,
    LDriw_abs_cPt_V4	= 1173,
    LDriw_abs_cdnNotPt_V4	= 1174,
    LDriw_abs_cdnPt_V4	= 1175,
    LDriw_abs_set_V4	= 1176,
    LDriw_cNotPt	= 1177,
    LDriw_cPt	= 1178,
    LDriw_cdnNotPt	= 1179,
    LDriw_cdnPt	= 1180,
    LDriw_f	= 1181,
    LDriw_ind_lo_V4	= 1182,
    LDriw_indexed	= 1183,
    LDriw_indexed_cNotPt	= 1184,
    LDriw_indexed_cPt	= 1185,
    LDriw_indexed_cdnNotPt	= 1186,
    LDriw_indexed_cdnPt	= 1187,
    LDriw_indexed_f	= 1188,
    LDriw_indexed_shl_V4	= 1189,
    LDriw_indexed_shl_cNotPt_V4	= 1190,
    LDriw_indexed_shl_cPt_V4	= 1191,
    LDriw_indexed_shl_cdnNotPt_V4	= 1192,
    LDriw_indexed_shl_cdnPt_V4	= 1193,
    LDriw_pred	= 1194,
    LDub_GP_V4	= 1195,
    LDub_GP_cNotPt_V4	= 1196,
    LDub_GP_cPt_V4	= 1197,
    LDub_GP_cdnNotPt_V4	= 1198,
    LDub_GP_cdnPt_V4	= 1199,
    LDuh_GP_V4	= 1200,
    LDuh_GP_cNotPt_V4	= 1201,
    LDuh_GP_cPt_V4	= 1202,
    LDuh_GP_cdnNotPt_V4	= 1203,
    LDuh_GP_cdnPt_V4	= 1204,
    LDw_GP_V4	= 1205,
    LDw_GP_cNotPt_V4	= 1206,
    LDw_GP_cPt_V4	= 1207,
    LDw_GP_cdnNotPt_V4	= 1208,
    LDw_GP_cdnPt_V4	= 1209,
    LO	= 1210,
    LOOP0_i	= 1211,
    LOOP0_r	= 1212,
    LO_jt	= 1213,
    LO_label	= 1214,
    LOi	= 1215,
    LSL_ADD_rr	= 1216,
    LSL_ADDd_rr	= 1217,
    LSL_AND_rr	= 1218,
    LSL_ANDd_rr	= 1219,
    LSL_OR_rr	= 1220,
    LSL_ORd_rr	= 1221,
    LSL_SUB_rr	= 1222,
    LSL_SUBd_rr	= 1223,
    LSL_rr	= 1224,
    LSLd	= 1225,
    LSLd_rr_xor_V4	= 1226,
    LSLi_V4	= 1227,
    LSR_ADD_ri	= 1228,
    LSR_ADD_rr	= 1229,
    LSR_ADDd_ri	= 1230,
    LSR_ADDd_rr	= 1231,
    LSR_AND_ri	= 1232,
    LSR_AND_rr	= 1233,
    LSR_ANDd_ri	= 1234,
    LSR_ANDd_rr	= 1235,
    LSR_OR_ri	= 1236,
    LSR_OR_rr	= 1237,
    LSR_ORd_ri	= 1238,
    LSR_ORd_rr	= 1239,
    LSR_SUB_ri	= 1240,
    LSR_SUB_rr	= 1241,
    LSR_SUBd_ri	= 1242,
    LSR_SUBd_rr	= 1243,
    LSR_XOR_ri	= 1244,
    LSR_XORd_ri	= 1245,
    LSR_ri	= 1246,
    LSR_rr	= 1247,
    LSRd_ri	= 1248,
    LSRd_rr	= 1249,
    LSRd_rr_xor_V4	= 1250,
    MASK_p	= 1251,
    MAXUd_rr	= 1252,
    MAXUw_rr	= 1253,
    MAXd_rr	= 1254,
    MAXw_dd	= 1255,
    MAXw_rr	= 1256,
    MINUd_rr	= 1257,
    MINUw_rr	= 1258,
    MINd_rr	= 1259,
    MINw_dd	= 1260,
    MINw_rr	= 1261,
    MPY	= 1262,
    MPY64	= 1263,
    MPY64_acc	= 1264,
    MPY64_sub	= 1265,
    MPYI	= 1266,
    MPYI_acc_ri	= 1267,
    MPYI_acc_rr	= 1268,
    MPYI_ri	= 1269,
    MPYI_rin	= 1270,
    MPYI_riu	= 1271,
    MPYI_sub_ri	= 1272,
    MPYU	= 1273,
    MPYU64	= 1274,
    MPYU64_acc	= 1275,
    MPYU64_sub	= 1276,
    MPY_trsext	= 1277,
    MUX_ii	= 1278,
    MUX_ir	= 1279,
    MUX_ri	= 1280,
    MUX_rr	= 1281,
    MemOPb_ADDi_V4	= 1282,
    MemOPb_ADDr_V4	= 1283,
    MemOPb_ANDr_V4	= 1284,
    MemOPb_CLRBITi_V4	= 1285,
    MemOPb_ORr_V4	= 1286,
    MemOPb_SETBITi_V4	= 1287,
    MemOPb_SUBi_V4	= 1288,
    MemOPb_SUBr_V4	= 1289,
    MemOPh_ADDi_V4	= 1290,
    MemOPh_ADDr_V4	= 1291,
    MemOPh_ANDr_V4	= 1292,
    MemOPh_CLRBITi_V4	= 1293,
    MemOPh_ORr_V4	= 1294,
    MemOPh_SETBITi_V4	= 1295,
    MemOPh_SUBi_V4	= 1296,
    MemOPh_SUBr_V4	= 1297,
    MemOPw_ADDi_V4	= 1298,
    MemOPw_ADDr_V4	= 1299,
    MemOPw_ANDr_V4	= 1300,
    MemOPw_CLRBITi_V4	= 1301,
    MemOPw_ORr_V4	= 1302,
    MemOPw_SETBITi_V4	= 1303,
    MemOPw_SUBi_V4	= 1304,
    MemOPw_SUBr_V4	= 1305,
    NOP	= 1306,
    NOT_p	= 1307,
    NOT_rr64	= 1308,
    NTSTBIT_ri	= 1309,
    NTSTBIT_rr	= 1310,
    OR_pp	= 1311,
    OR_ri	= 1312,
    OR_rr	= 1313,
    OR_rr64	= 1314,
    OR_rr_cNotPt	= 1315,
    OR_rr_cPt	= 1316,
    OR_rr_cdnNotPt	= 1317,
    OR_rr_cdnPt	= 1318,
    ORd_NOTd_V4	= 1319,
    ORi_ASLri_V4	= 1320,
    ORi_LSRri_V4	= 1321,
    ORr_ANDr_NOTr_V4	= 1322,
    ORr_ANDri2_V4	= 1323,
    ORr_ANDri_V4	= 1324,
    ORr_ANDrr_V4	= 1325,
    ORr_ORri_V4	= 1326,
    ORr_ORrr_V4	= 1327,
    ORr_XORrr_V4	= 1328,
    POST_LDrib	= 1329,
    POST_LDrib_cNotPt	= 1330,
    POST_LDrib_cPt	= 1331,
    POST_LDrib_cdnNotPt_V4	= 1332,
    POST_LDrib_cdnPt_V4	= 1333,
    POST_LDrid	= 1334,
    POST_LDrid_cNotPt	= 1335,
    POST_LDrid_cPt	= 1336,
    POST_LDrid_cdnNotPt_V4	= 1337,
    POST_LDrid_cdnPt_V4	= 1338,
    POST_LDrih	= 1339,
    POST_LDrih_cNotPt	= 1340,
    POST_LDrih_cPt	= 1341,
    POST_LDrih_cdnNotPt_V4	= 1342,
    POST_LDrih_cdnPt_V4	= 1343,
    POST_LDriub	= 1344,
    POST_LDriub_cNotPt	= 1345,
    POST_LDriub_cPt	= 1346,
    POST_LDriub_cdnNotPt_V4	= 1347,
    POST_LDriub_cdnPt_V4	= 1348,
    POST_LDriuh	= 1349,
    POST_LDriuh_cNotPt	= 1350,
    POST_LDriuh_cPt	= 1351,
    POST_LDriuh_cdnNotPt_V4	= 1352,
    POST_LDriuh_cdnPt_V4	= 1353,
    POST_LDriw	= 1354,
    POST_LDriw_cNotPt	= 1355,
    POST_LDriw_cPt	= 1356,
    POST_LDriw_cdnNotPt_V4	= 1357,
    POST_LDriw_cdnPt_V4	= 1358,
    POST_STbri	= 1359,
    POST_STbri_cNotPt	= 1360,
    POST_STbri_cNotPt_nv_V4	= 1361,
    POST_STbri_cPt	= 1362,
    POST_STbri_cPt_nv_V4	= 1363,
    POST_STbri_cdnNotPt_V4	= 1364,
    POST_STbri_cdnNotPt_nv_V4	= 1365,
    POST_STbri_cdnPt_V4	= 1366,
    POST_STbri_cdnPt_nv_V4	= 1367,
    POST_STbri_nv_V4	= 1368,
    POST_STdri	= 1369,
    POST_STdri_cNotPt	= 1370,
    POST_STdri_cPt	= 1371,
    POST_STdri_cdnNotPt_V4	= 1372,
    POST_STdri_cdnPt_V4	= 1373,
    POST_SThri	= 1374,
    POST_SThri_cNotPt	= 1375,
    POST_SThri_cNotPt_nv_V4	= 1376,
    POST_SThri_cPt	= 1377,
    POST_SThri_cPt_nv_V4	= 1378,
    POST_SThri_cdnNotPt_V4	= 1379,
    POST_SThri_cdnNotPt_nv_V4	= 1380,
    POST_SThri_cdnPt_V4	= 1381,
    POST_SThri_cdnPt_nv_V4	= 1382,
    POST_SThri_nv_V4	= 1383,
    POST_STwri	= 1384,
    POST_STwri_cNotPt	= 1385,
    POST_STwri_cNotPt_nv_V4	= 1386,
    POST_STwri_cPt	= 1387,
    POST_STwri_cPt_nv_V4	= 1388,
    POST_STwri_cdnNotPt_V4	= 1389,
    POST_STwri_cdnNotPt_nv_V4	= 1390,
    POST_STwri_cdnPt_V4	= 1391,
    POST_STwri_cdnPt_nv_V4	= 1392,
    POST_STwri_nv_V4	= 1393,
    RESTORE_DEALLOC_BEFORE_TAILCALL_V4	= 1394,
    RESTORE_DEALLOC_RET_JMP_V4	= 1395,
    SAVE_REGISTERS_CALL_V4	= 1396,
    SETBIT	= 1397,
    SETBIT_31	= 1398,
    SI_to_SXTHI_asrh	= 1399,
    STb_GP_V4	= 1400,
    STb_GP_cNotPt_V4	= 1401,
    STb_GP_cNotPt_nv_V4	= 1402,
    STb_GP_cPt_V4	= 1403,
    STb_GP_cPt_nv_V4	= 1404,
    STb_GP_cdnNotPt_V4	= 1405,
    STb_GP_cdnNotPt_nv_V4	= 1406,
    STb_GP_cdnPt_V4	= 1407,
    STb_GP_cdnPt_nv_V4	= 1408,
    STb_GP_nv_V4	= 1409,
    STd_GP_V4	= 1410,
    STd_GP_cNotPt_V4	= 1411,
    STd_GP_cPt_V4	= 1412,
    STd_GP_cdnNotPt_V4	= 1413,
    STd_GP_cdnPt_V4	= 1414,
    STh_GP_V4	= 1415,
    STh_GP_cNotPt_V4	= 1416,
    STh_GP_cNotPt_nv_V4	= 1417,
    STh_GP_cPt_V4	= 1418,
    STh_GP_cPt_nv_V4	= 1419,
    STh_GP_cdnNotPt_V4	= 1420,
    STh_GP_cdnNotPt_nv_V4	= 1421,
    STh_GP_cdnPt_V4	= 1422,
    STh_GP_cdnPt_nv_V4	= 1423,
    STh_GP_nv_V4	= 1424,
    STrib	= 1425,
    STrib_abs_V4	= 1426,
    STrib_abs_cNotPt_V4	= 1427,
    STrib_abs_cNotPt_nv_V4	= 1428,
    STrib_abs_cPt_V4	= 1429,
    STrib_abs_cPt_nv_V4	= 1430,
    STrib_abs_cdnNotPt_V4	= 1431,
    STrib_abs_cdnNotPt_nv_V4	= 1432,
    STrib_abs_cdnPt_V4	= 1433,
    STrib_abs_cdnPt_nv_V4	= 1434,
    STrib_abs_nv_V4	= 1435,
    STrib_abs_set_V4	= 1436,
    STrib_cNotPt	= 1437,
    STrib_cNotPt_nv_V4	= 1438,
    STrib_cPt	= 1439,
    STrib_cPt_nv_V4	= 1440,
    STrib_cdnNotPt_V4	= 1441,
    STrib_cdnNotPt_nv_V4	= 1442,
    STrib_cdnPt_V4	= 1443,
    STrib_cdnPt_nv_V4	= 1444,
    STrib_imm_V4	= 1445,
    STrib_imm_cNotPt_V4	= 1446,
    STrib_imm_cPt_V4	= 1447,
    STrib_imm_cdnNotPt_V4	= 1448,
    STrib_imm_cdnPt_V4	= 1449,
    STrib_indexed	= 1450,
    STrib_indexed_cNotPt	= 1451,
    STrib_indexed_cNotPt_nv_V4	= 1452,
    STrib_indexed_cPt	= 1453,
    STrib_indexed_cPt_nv_V4	= 1454,
    STrib_indexed_cdnNotPt_V4	= 1455,
    STrib_indexed_cdnNotPt_nv_V4	= 1456,
    STrib_indexed_cdnPt_V4	= 1457,
    STrib_indexed_cdnPt_nv_V4	= 1458,
    STrib_indexed_nv_V4	= 1459,
    STrib_indexed_shl_V4	= 1460,
    STrib_indexed_shl_cNotPt_V4	= 1461,
    STrib_indexed_shl_cNotPt_nv_V4	= 1462,
    STrib_indexed_shl_cPt_V4	= 1463,
    STrib_indexed_shl_cPt_nv_V4	= 1464,
    STrib_indexed_shl_cdnNotPt_V4	= 1465,
    STrib_indexed_shl_cdnNotPt_nv_V4	= 1466,
    STrib_indexed_shl_cdnPt_V4	= 1467,
    STrib_indexed_shl_cdnPt_nv_V4	= 1468,
    STrib_indexed_shl_nv_V4	= 1469,
    STrib_nv_V4	= 1470,
    STrib_shl_V4	= 1471,
    STrib_shl_nv_V4	= 1472,
    STrid	= 1473,
    STrid_abs_V4	= 1474,
    STrid_abs_cNotPt_V4	= 1475,
    STrid_abs_cPt_V4	= 1476,
    STrid_abs_cdnNotPt_V4	= 1477,
    STrid_abs_cdnPt_V4	= 1478,
    STrid_abs_set_V4	= 1479,
    STrid_cNotPt	= 1480,
    STrid_cPt	= 1481,
    STrid_cdnNotPt_V4	= 1482,
    STrid_cdnPt_V4	= 1483,
    STrid_f	= 1484,
    STrid_indexed	= 1485,
    STrid_indexed_cNotPt	= 1486,
    STrid_indexed_cPt	= 1487,
    STrid_indexed_cdnNotPt_V4	= 1488,
    STrid_indexed_cdnPt_V4	= 1489,
    STrid_indexed_f	= 1490,
    STrid_indexed_shl_V4	= 1491,
    STrid_indexed_shl_cNotPt_V4	= 1492,
    STrid_indexed_shl_cPt_V4	= 1493,
    STrid_indexed_shl_cdnNotPt_V4	= 1494,
    STrid_indexed_shl_cdnPt_V4	= 1495,
    STrid_shl_V4	= 1496,
    STrih	= 1497,
    STrih_abs_V4	= 1498,
    STrih_abs_cNotPt_V4	= 1499,
    STrih_abs_cNotPt_nv_V4	= 1500,
    STrih_abs_cPt_V4	= 1501,
    STrih_abs_cPt_nv_V4	= 1502,
    STrih_abs_cdnNotPt_V4	= 1503,
    STrih_abs_cdnNotPt_nv_V4	= 1504,
    STrih_abs_cdnPt_V4	= 1505,
    STrih_abs_cdnPt_nv_V4	= 1506,
    STrih_abs_nv_V4	= 1507,
    STrih_abs_set_V4	= 1508,
    STrih_cNotPt	= 1509,
    STrih_cNotPt_nv_V4	= 1510,
    STrih_cPt	= 1511,
    STrih_cPt_nv_V4	= 1512,
    STrih_cdnNotPt_V4	= 1513,
    STrih_cdnNotPt_nv_V4	= 1514,
    STrih_cdnPt_V4	= 1515,
    STrih_cdnPt_nv_V4	= 1516,
    STrih_imm_V4	= 1517,
    STrih_imm_cNotPt_V4	= 1518,
    STrih_imm_cPt_V4	= 1519,
    STrih_imm_cdnNotPt_V4	= 1520,
    STrih_imm_cdnPt_V4	= 1521,
    STrih_indexed	= 1522,
    STrih_indexed_cNotPt	= 1523,
    STrih_indexed_cNotPt_nv_V4	= 1524,
    STrih_indexed_cPt	= 1525,
    STrih_indexed_cPt_nv_V4	= 1526,
    STrih_indexed_cdnNotPt_V4	= 1527,
    STrih_indexed_cdnNotPt_nv_V4	= 1528,
    STrih_indexed_cdnPt_V4	= 1529,
    STrih_indexed_cdnPt_nv_V4	= 1530,
    STrih_indexed_nv_V4	= 1531,
    STrih_indexed_shl_V4	= 1532,
    STrih_indexed_shl_cNotPt_V4	= 1533,
    STrih_indexed_shl_cNotPt_nv_V4	= 1534,
    STrih_indexed_shl_cPt_V4	= 1535,
    STrih_indexed_shl_cPt_nv_V4	= 1536,
    STrih_indexed_shl_cdnNotPt_V4	= 1537,
    STrih_indexed_shl_cdnNotPt_nv_V4	= 1538,
    STrih_indexed_shl_cdnPt_V4	= 1539,
    STrih_indexed_shl_cdnPt_nv_V4	= 1540,
    STrih_indexed_shl_nv_V4	= 1541,
    STrih_nv_V4	= 1542,
    STrih_offset_ext_V4	= 1543,
    STrih_shl_V4	= 1544,
    STrih_shl_nv_V4	= 1545,
    STriw	= 1546,
    STriw_abs_V4	= 1547,
    STriw_abs_cNotPt_V4	= 1548,
    STriw_abs_cNotPt_nv_V4	= 1549,
    STriw_abs_cPt_V4	= 1550,
    STriw_abs_cPt_nv_V4	= 1551,
    STriw_abs_cdnNotPt_V4	= 1552,
    STriw_abs_cdnNotPt_nv_V4	= 1553,
    STriw_abs_cdnPt_V4	= 1554,
    STriw_abs_cdnPt_nv_V4	= 1555,
    STriw_abs_nv_V4	= 1556,
    STriw_abs_set_V4	= 1557,
    STriw_cNotPt	= 1558,
    STriw_cNotPt_nv_V4	= 1559,
    STriw_cPt	= 1560,
    STriw_cPt_nv_V4	= 1561,
    STriw_cdnNotPt_V4	= 1562,
    STriw_cdnNotPt_nv_V4	= 1563,
    STriw_cdnPt_V4	= 1564,
    STriw_cdnPt_nv_V4	= 1565,
    STriw_f	= 1566,
    STriw_imm_V4	= 1567,
    STriw_imm_cNotPt_V4	= 1568,
    STriw_imm_cPt_V4	= 1569,
    STriw_imm_cdnNotPt_V4	= 1570,
    STriw_imm_cdnPt_V4	= 1571,
    STriw_indexed	= 1572,
    STriw_indexed_cNotPt	= 1573,
    STriw_indexed_cNotPt_nv_V4	= 1574,
    STriw_indexed_cPt	= 1575,
    STriw_indexed_cPt_nv_V4	= 1576,
    STriw_indexed_cdnNotPt_V4	= 1577,
    STriw_indexed_cdnNotPt_nv_V4	= 1578,
    STriw_indexed_cdnPt_V4	= 1579,
    STriw_indexed_cdnPt_nv_V4	= 1580,
    STriw_indexed_f	= 1581,
    STriw_indexed_nv_V4	= 1582,
    STriw_indexed_shl_V4	= 1583,
    STriw_indexed_shl_cNotPt_V4	= 1584,
    STriw_indexed_shl_cNotPt_nv_V4	= 1585,
    STriw_indexed_shl_cPt_V4	= 1586,
    STriw_indexed_shl_cPt_nv_V4	= 1587,
    STriw_indexed_shl_cdnNotPt_V4	= 1588,
    STriw_indexed_shl_cdnNotPt_nv_V4	= 1589,
    STriw_indexed_shl_cdnPt_V4	= 1590,
    STriw_indexed_shl_cdnPt_nv_V4	= 1591,
    STriw_indexed_shl_nv_V4	= 1592,
    STriw_nv_V4	= 1593,
    STriw_offset_ext_V4	= 1594,
    STriw_pred	= 1595,
    STriw_pred_V4	= 1596,
    STriw_shl_V4	= 1597,
    STriw_shl_nv_V4	= 1598,
    STw_GP_V4	= 1599,
    STw_GP_cNotPt_V4	= 1600,
    STw_GP_cNotPt_nv_V4	= 1601,
    STw_GP_cPt_V4	= 1602,
    STw_GP_cPt_nv_V4	= 1603,
    STw_GP_cdnNotPt_V4	= 1604,
    STw_GP_cdnNotPt_nv_V4	= 1605,
    STw_GP_cdnPt_V4	= 1606,
    STw_GP_cdnPt_nv_V4	= 1607,
    STw_GP_nv_V4	= 1608,
    SUB64_rr	= 1609,
    SUB_ri	= 1610,
    SUB_rr	= 1611,
    SUB_rr_cNotPt	= 1612,
    SUB_rr_cPt	= 1613,
    SUB_rr_cdnNotPt	= 1614,
    SUB_rr_cdnPt	= 1615,
    SUBi_ASLri_V4	= 1616,
    SUBi_LSRri_V4	= 1617,
    SUBri_acc	= 1618,
    SUBrr_acc	= 1619,
    SXTB	= 1620,
    SXTB_cNotPt_V4	= 1621,
    SXTB_cPt_V4	= 1622,
    SXTB_cdnNotPt_V4	= 1623,
    SXTB_cdnPt_V4	= 1624,
    SXTH	= 1625,
    SXTH_cNotPt_V4	= 1626,
    SXTH_cPt_V4	= 1627,
    SXTH_cdnNotPt_V4	= 1628,
    SXTH_cdnPt_V4	= 1629,
    SXTW	= 1630,
    TCRETURNR	= 1631,
    TCRETURNtext	= 1632,
    TCRETURNtg	= 1633,
    TFCR	= 1634,
    TFR	= 1635,
    TFR64	= 1636,
    TFR64_cNotPt	= 1637,
    TFR64_cPt	= 1638,
    TFR64_cdnNotPt	= 1639,
    TFR64_cdnPt	= 1640,
    TFRI	= 1641,
    TFRI64	= 1642,
    TFRI_V4	= 1643,
    TFRI_cNotPt	= 1644,
    TFRI_cNotPt_V4	= 1645,
    TFRI_cNotPt_f	= 1646,
    TFRI_cPt	= 1647,
    TFRI_cPt_V4	= 1648,
    TFRI_cPt_f	= 1649,
    TFRI_cdnNotPt	= 1650,
    TFRI_cdnNotPt_V4	= 1651,
    TFRI_cdnPt	= 1652,
    TFRI_cdnPt_V4	= 1653,
    TFRI_f	= 1654,
    TFR_FI	= 1655,
    TFR_FI_immext_V4	= 1656,
    TFR_PdFalse	= 1657,
    TFR_PdRs	= 1658,
    TFR_RsPd	= 1659,
    TFR_cNotPt	= 1660,
    TFR_cPt	= 1661,
    TFR_cdnNotPt	= 1662,
    TFR_cdnPt	= 1663,
    TFR_condset_ii	= 1664,
    TFR_condset_ii_f	= 1665,
    TFR_condset_ir	= 1666,
    TFR_condset_ir_f	= 1667,
    TFR_condset_ri	= 1668,
    TFR_condset_ri_f	= 1669,
    TFR_condset_rr	= 1670,
    TFR_condset_rr64_f	= 1671,
    TFR_condset_rr_f	= 1672,
    TOGBIT	= 1673,
    TOGBIT_31	= 1674,
    TSTBIT0_f_Jumpnv_nt_V4	= 1675,
    TSTBIT0_f_Jumpnv_t_V4	= 1676,
    TSTBIT0_t_Jumpnv_nt_V4	= 1677,
    TSTBIT0_t_Jumpnv_t_V4	= 1678,
    TSTBIT_ri	= 1679,
    TSTBIT_rr	= 1680,
    V4_A4_rcmpeq	= 1681,
    V4_A4_rcmpeqi	= 1682,
    V4_A4_rcmpneq	= 1683,
    V4_A4_rcmpneqi	= 1684,
    VALIGN_rrp	= 1685,
    VITPACK_pp	= 1686,
    VMUX_prr64	= 1687,
    VSPLICE_rrp	= 1688,
    XOR_pp	= 1689,
    XOR_rr	= 1690,
    XOR_rr64	= 1691,
    XOR_rr_cNotPt	= 1692,
    XOR_rr_cPt	= 1693,
    XOR_rr_cdnNotPt	= 1694,
    XOR_rr_cdnPt	= 1695,
    XORd_XORdd	= 1696,
    XORr_ANDr_NOTr_V4	= 1697,
    XORr_ANDrr_V4	= 1698,
    XORr_ORrr_V4	= 1699,
    XORr_XORrr_V4	= 1700,
    ZXTB	= 1701,
    ZXTB_cNotPt_V4	= 1702,
    ZXTB_cPt_V4	= 1703,
    ZXTB_cdnNotPt_V4	= 1704,
    ZXTB_cdnPt_V4	= 1705,
    ZXTH	= 1706,
    ZXTH_cNotPt_V4	= 1707,
    ZXTH_cPt_V4	= 1708,
    ZXTH_cdnNotPt_V4	= 1709,
    ZXTH_cdnPt_V4	= 1710,
    fADD64_rr	= 1711,
    fADD_rr	= 1712,
    fMUL64_rr	= 1713,
    fMUL_rr	= 1714,
    fSUB64_rr	= 1715,
    fSUB_rr	= 1716,
    INSTRUCTION_LIST_END = 1717
  };
namespace Sched {
  enum {
    NoInstrModel	= 0,
    ALU64	= 1,
    S	= 2,
    ALU32	= 3,
    M	= 4,
    PSEUDO	= 5,
    ST	= 6,
    SYS	= 7,
    J	= 8,
    JR	= 9,
    NV_V4	= 10,
    LD	= 11,
    ENDLOOP	= 12,
    PREFIX	= 13,
    CR	= 14,
    MEM_V4	= 15,
    SCHED_LIST_END = 16
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

static const uint16_t ImplicitList1[] = { Hexagon::R31, Hexagon::R30, Hexagon::R29, 0 };
static const uint16_t ImplicitList2[] = { Hexagon::R29, Hexagon::R30, 0 };
static const uint16_t ImplicitList3[] = { Hexagon::R29, 0 };
static const uint16_t ImplicitList4[] = { Hexagon::R29, Hexagon::R30, Hexagon::R31, 0 };
static const uint16_t ImplicitList5[] = { Hexagon::R31, Hexagon::R30, 0 };
static const uint16_t ImplicitList6[] = { Hexagon::D0, Hexagon::D1, Hexagon::D2, Hexagon::D3, Hexagon::D4, Hexagon::D5, Hexagon::D6, Hexagon::D7, Hexagon::D8, Hexagon::D9, Hexagon::D10, Hexagon::R22, Hexagon::R23, Hexagon::R28, Hexagon::R31, Hexagon::P0, Hexagon::P1, Hexagon::P2, Hexagon::P3, Hexagon::LC0, Hexagon::LC1, Hexagon::SA0, Hexagon::SA1, 0 };
static const uint16_t ImplicitList7[] = { Hexagon::D0, Hexagon::D1, Hexagon::D2, Hexagon::D3, Hexagon::D4, Hexagon::D5, Hexagon::D6, Hexagon::D7, Hexagon::R28, Hexagon::R31, Hexagon::P0, Hexagon::P1, Hexagon::P2, Hexagon::P3, Hexagon::LC0, Hexagon::LC1, Hexagon::SA0, Hexagon::SA1, 0 };
static const uint16_t ImplicitList8[] = { Hexagon::PC, 0 };
static const uint16_t ImplicitList9[] = { Hexagon::R30, 0 };
static const uint16_t ImplicitList10[] = { Hexagon::R29, Hexagon::R30, Hexagon::R31, Hexagon::PC, 0 };
static const uint16_t ImplicitList11[] = { Hexagon::R28, 0 };
static const uint16_t ImplicitList12[] = { Hexagon::SA0, Hexagon::LC0, 0 };
static const uint16_t ImplicitList13[] = { Hexagon::PC, Hexagon::LC0, 0 };
static const uint16_t ImplicitList14[] = { Hexagon::R10, Hexagon::R11, Hexagon::D5, 0 };
static const uint16_t ImplicitList15[] = { Hexagon::R29, Hexagon::R31, 0 };

static const MCOperandInfo OperandInfo2[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo3[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo4[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo5[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo6[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo7[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo8[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo9[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo10[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo11[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo12[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo13[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo14[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo15[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo16[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo17[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo18[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo19[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo20[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo21[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo22[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo23[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo24[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo25[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo26[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo27[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo28[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo29[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo30[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo31[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo32[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo33[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo34[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo35[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo36[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo37[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo38[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo39[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo40[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo41[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo42[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo43[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo44[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo45[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo46[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo47[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo48[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo49[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo50[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo51[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo52[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo53[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo54[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo55[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo56[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo57[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo58[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo59[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo60[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo61[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo62[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo63[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo64[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo65[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo66[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo67[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo68[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::CRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo69[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo70[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo71[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo72[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo73[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo74[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo75[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo76[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo77[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo78[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo79[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo80[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo81[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo82[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo83[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo84[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo85[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo86[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo87[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo88[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo89[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo90[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo91[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo92[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((1 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo93[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((1 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo94[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((1 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo95[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((1 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo96[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo97[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo98[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo99[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo100[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo101[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo102[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo103[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo104[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo105[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo106[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo107[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo108[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo109[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo110[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo111[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo112[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo113[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo114[] = { { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo115[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo116[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo117[] = { { Hexagon::CRRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo118[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo119[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo120[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo121[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo122[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo123[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo124[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo125[] = { { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::DoubleRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo126[] = { { Hexagon::IntRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { Hexagon::PredRegsRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };

extern const MCInstrDesc HexagonInsts[] = {
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
  { 19,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #19 = ADD64_rr
  { 20,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #20 = ADDASL
  { 21,	3,	1,	3,	4,	0|(1<<MCID::Predicable), 0x1f0a40001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #21 = ADD_ri
  { 22,	4,	1,	3,	4,	0, 0x1e8b400c1ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #22 = ADD_ri_cNotPt
  { 23,	4,	1,	3,	4,	0, 0x1e8b40041ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #23 = ADD_ri_cPt
  { 24,	4,	1,	3,	4,	0, 0x1e8b401c1ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #24 = ADD_ri_cdnNotPt
  { 25,	4,	1,	3,	4,	0, 0x1e8b40141ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #25 = ADD_ri_cdnPt
  { 26,	3,	1,	3,	4,	0|(1<<MCID::Predicable)|(1<<MCID::Commutable), 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #26 = ADD_rr
  { 27,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e00000c1ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #27 = ADD_rr_cNotPt
  { 28,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e0000041ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #28 = ADD_rr_cPt
  { 29,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e00001c1ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #29 = ADD_rr_cdnNotPt
  { 30,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e0000141ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #30 = ADD_rr_cdnPt
  { 31,	4,	1,	4,	4,	0, 0x188140008ULL, NULL, NULL, OperandInfo16,0,0 },  // Inst #31 = ADDi_ASLri_V4
  { 32,	4,	1,	4,	4,	0, 0x188140008ULL, NULL, NULL, OperandInfo16,0,0 },  // Inst #32 = ADDi_LSRri_V4
  { 33,	4,	1,	4,	4,	0, 0x186140008ULL, NULL, NULL, OperandInfo17,0,0 },  // Inst #33 = ADDi_MPYri_V4
  { 34,	4,	1,	4,	4,	0, 0x186140008ULL, NULL, NULL, OperandInfo18,0,0 },  // Inst #34 = ADDi_MPYrr_V4
  { 35,	4,	1,	4,	4,	0, 0x186b40008ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #35 = ADDr_ADDri_V4
  { 36,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #36 = ADDr_MPYir_V4
  { 37,	4,	1,	4,	4,	0, 0x186340008ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #37 = ADDr_MPYri_V4
  { 38,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo20,0,0 },  // Inst #38 = ADDr_MPYrr_V4
  { 39,	4,	1,	4,	4,	0, 0x186a40008ULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #39 = ADDr_SUBri_V4
  { 40,	4,	1,	4,	4,	0, 0x186a40008ULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #40 = ADDri_SUBr_V4
  { 41,	4,	1,	4,	4,	0, 0x1e8b40008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #41 = ADDri_acc
  { 42,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #42 = ADDrr_acc
  { 43,	1,	0,	5,	4,	0|(1<<MCID::Pseudo), 0x1e0000000ULL, ImplicitList1, ImplicitList2, OperandInfo2,0,0 },  // Inst #43 = ADJCALLSTACKDOWN
  { 44,	2,	0,	5,	4,	0|(1<<MCID::Pseudo), 0x1e0000000ULL, ImplicitList3, ImplicitList4, OperandInfo8,0,0 },  // Inst #44 = ADJCALLSTACKUP
  { 45,	3,	1,	3,	4,	0|(1<<MCID::UsesCustomInserter), 0x1e0000001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #45 = ADJDYNALLOC
  { 46,	1,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1e0000006ULL, ImplicitList5, ImplicitList2, OperandInfo2,0,0 },  // Inst #46 = ALLOCFRAME
  { 47,	2,	1,	2,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1e0000008ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #47 = ALL_pp
  { 48,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo24,0,0 },  // Inst #48 = AND_pnotp
  { 49,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo24,0,0 },  // Inst #49 = AND_pp
  { 50,	3,	1,	3,	4,	0, 0x1eaa40001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #50 = AND_ri
  { 51,	3,	1,	3,	4,	0|(1<<MCID::Predicable)|(1<<MCID::Commutable), 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #51 = AND_rr
  { 52,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #52 = AND_rr64
  { 53,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e00000c1ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #53 = AND_rr_cNotPt
  { 54,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e0000041ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #54 = AND_rr_cPt
  { 55,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e00001c1ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #55 = AND_rr_cdnNotPt
  { 56,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e0000141ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #56 = AND_rr_cdnPt
  { 57,	3,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #57 = ANDd_NOTd_V4
  { 58,	4,	1,	4,	4,	0, 0x188140008ULL, NULL, NULL, OperandInfo16,0,0 },  // Inst #58 = ANDi_ASLri_V4
  { 59,	4,	1,	4,	4,	0, 0x188140008ULL, NULL, NULL, OperandInfo16,0,0 },  // Inst #59 = ANDi_LSRri_V4
  { 60,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #60 = ANDr_ANDr_NOTr_V4
  { 61,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #61 = ANDr_ANDrr_V4
  { 62,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #62 = ANDr_ORrr_V4
  { 63,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #63 = ANDr_XORrr_V4
  { 64,	2,	1,	2,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1e0000008ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #64 = ANY_pp
  { 65,	2,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #65 = ARGEXTEND
  { 66,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #66 = ASL
  { 67,	2,	1,	3,	4,	0|(1<<MCID::Predicable), 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #67 = ASLH
  { 68,	3,	1,	3,	4,	0, 0x1800000c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #68 = ASLH_cNotPt_V4
  { 69,	3,	1,	3,	4,	0, 0x180000041ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #69 = ASLH_cPt_V4
  { 70,	3,	1,	3,	4,	0, 0x1800001c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #70 = ASLH_cdnNotPt_V4
  { 71,	3,	1,	3,	4,	0, 0x180000141ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #71 = ASLH_cdnPt_V4
  { 72,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #72 = ASL_ADD_ri
  { 73,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #73 = ASL_ADD_rr
  { 74,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #74 = ASL_ADDd_ri
  { 75,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #75 = ASL_ADDd_rr
  { 76,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #76 = ASL_AND_ri
  { 77,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #77 = ASL_AND_rr
  { 78,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #78 = ASL_ANDd_ri
  { 79,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #79 = ASL_ANDd_rr
  { 80,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #80 = ASL_OR_ri
  { 81,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #81 = ASL_OR_rr
  { 82,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #82 = ASL_ORd_ri
  { 83,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #83 = ASL_ORd_rr
  { 84,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #84 = ASL_SUB_ri
  { 85,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #85 = ASL_SUB_rr
  { 86,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #86 = ASL_SUBd_ri
  { 87,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #87 = ASL_SUBd_rr
  { 88,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #88 = ASL_XOR_ri
  { 89,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #89 = ASL_XORd_ri
  { 90,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #90 = ASL_rr
  { 91,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #91 = ASLd
  { 92,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo30,0,0 },  // Inst #92 = ASLd_ri
  { 93,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #93 = ASLd_rr_xor_V4
  { 94,	2,	1,	3,	4,	0|(1<<MCID::Predicable), 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #94 = ASRH
  { 95,	3,	1,	3,	4,	0, 0x1800000c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #95 = ASRH_cNotPt_V4
  { 96,	3,	1,	3,	4,	0, 0x180000041ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #96 = ASRH_cPt_V4
  { 97,	3,	1,	3,	4,	0, 0x1800001c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #97 = ASRH_cdnNotPt_V4
  { 98,	3,	1,	3,	4,	0, 0x180000141ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #98 = ASRH_cdnPt_V4
  { 99,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #99 = ASR_ADD_ri
  { 100,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #100 = ASR_ADD_rr
  { 101,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #101 = ASR_ADDd_ri
  { 102,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #102 = ASR_ADDd_rr
  { 103,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #103 = ASR_AND_ri
  { 104,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #104 = ASR_AND_rr
  { 105,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #105 = ASR_ANDd_ri
  { 106,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #106 = ASR_ANDd_rr
  { 107,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #107 = ASR_OR_ri
  { 108,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #108 = ASR_OR_rr
  { 109,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #109 = ASR_ORd_ri
  { 110,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #110 = ASR_ORd_rr
  { 111,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #111 = ASR_SUB_ri
  { 112,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #112 = ASR_SUB_rr
  { 113,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #113 = ASR_SUBd_ri
  { 114,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #114 = ASR_SUBd_rr
  { 115,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #115 = ASR_ri
  { 116,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #116 = ASR_rr
  { 117,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo30,0,0 },  // Inst #117 = ASRd_ri
  { 118,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #118 = ASRd_rr
  { 119,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #119 = ASRd_rr_xor_V4
  { 120,	0,	0,	7,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1e0000027ULL, NULL, NULL, 0,0,0 },  // Inst #120 = BARRIER
  { 121,	1,	0,	8,	4,	0|(1<<MCID::Call), 0x1e0000004ULL, NULL, ImplicitList6, OperandInfo5,0,0 },  // Inst #121 = CALL
  { 122,	1,	0,	9,	4,	0|(1<<MCID::Call), 0x1e0000003ULL, NULL, ImplicitList6, OperandInfo31,0,0 },  // Inst #122 = CALLR
  { 123,	1,	0,	9,	4,	0|(1<<MCID::Call), 0x1e0000003ULL, NULL, ImplicitList7, OperandInfo31,0,0 },  // Inst #123 = CALLRv3
  { 124,	1,	0,	8,	4,	0|(1<<MCID::Call), 0x1e0000004ULL, NULL, ImplicitList7, OperandInfo5,0,0 },  // Inst #124 = CALLv3
  { 125,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #125 = CLRBIT
  { 126,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #126 = CLRBIT_31
  { 127,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #127 = CMPEHexagon4rr
  { 128,	2,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1eb9402caULL, NULL, ImplicitList8, OperandInfo33,0,0 },  // Inst #128 = CMPEQn1_f_Jumpnv_nt_V4
  { 129,	2,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1eb9402caULL, NULL, ImplicitList8, OperandInfo33,0,0 },  // Inst #129 = CMPEQn1_f_Jumpnv_t_V4
  { 130,	2,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1eb94024aULL, NULL, ImplicitList8, OperandInfo33,0,0 },  // Inst #130 = CMPEQn1_t_Jumpnv_nt_V4
  { 131,	2,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1eb94024aULL, NULL, ImplicitList8, OperandInfo33,0,0 },  // Inst #131 = CMPEQn1_t_Jumpnv_t_V4
  { 132,	3,	1,	3,	4,	0|(1<<MCID::Compare), 0x1eaa40001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #132 = CMPEQri
  { 133,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo35,0,0 },  // Inst #133 = CMPEQri_f_Jumpnv_nt_V4
  { 134,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo35,0,0 },  // Inst #134 = CMPEQri_f_Jumpnv_t_V4
  { 135,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo35,0,0 },  // Inst #135 = CMPEQri_t_Jumpnv_nt_V4
  { 136,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo35,0,0 },  // Inst #136 = CMPEQri_t_Jumpnv_t_V4
  { 137,	3,	1,	3,	4,	0|(1<<MCID::Compare), 0x1e0000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #137 = CMPEQrr
  { 138,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #138 = CMPEQrr_f_Jumpnv_nt_V4
  { 139,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #139 = CMPEQrr_f_Jumpnv_t_V4
  { 140,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #140 = CMPEQrr_t_Jumpnv_nt_V4
  { 141,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #141 = CMPEQrr_t_Jumpnv_t_V4
  { 142,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #142 = CMPGT64rr
  { 143,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #143 = CMPGTU64rr
  { 144,	3,	1,	3,	4,	0|(1<<MCID::Compare), 0x1e9240001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #144 = CMPGTUri
  { 145,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo35,0,0 },  // Inst #145 = CMPGTUri_f_Jumpnv_nt_V4
  { 146,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo35,0,0 },  // Inst #146 = CMPGTUri_f_Jumpnv_t_V4
  { 147,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo35,0,0 },  // Inst #147 = CMPGTUri_t_Jumpnv_nt_V4
  { 148,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo35,0,0 },  // Inst #148 = CMPGTUri_t_Jumpnv_t_V4
  { 149,	3,	1,	3,	4,	0|(1<<MCID::Compare), 0x1e0000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #149 = CMPGTUrr
  { 150,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #150 = CMPGTUrr_f_Jumpnv_nt_V4
  { 151,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #151 = CMPGTUrr_f_Jumpnv_t_V4
  { 152,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #152 = CMPGTUrr_t_Jumpnv_nt_V4
  { 153,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #153 = CMPGTUrr_t_Jumpnv_t_V4
  { 154,	2,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1eb9402caULL, NULL, ImplicitList8, OperandInfo33,0,0 },  // Inst #154 = CMPGTn1_f_Jumpnv_nt_V4
  { 155,	2,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1eb9402caULL, NULL, ImplicitList8, OperandInfo33,0,0 },  // Inst #155 = CMPGTn1_f_Jumpnv_t_V4
  { 156,	2,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1eb94024aULL, NULL, ImplicitList8, OperandInfo33,0,0 },  // Inst #156 = CMPGTn1_t_Jumpnv_nt_V4
  { 157,	2,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1eb94024aULL, NULL, ImplicitList8, OperandInfo33,0,0 },  // Inst #157 = CMPGTn1_t_Jumpnv_t_V4
  { 158,	3,	1,	3,	4,	0|(1<<MCID::Compare), 0x1eaa40001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #158 = CMPGTri
  { 159,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo35,0,0 },  // Inst #159 = CMPGTri_f_Jumpnv_nt_V4
  { 160,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo35,0,0 },  // Inst #160 = CMPGTri_f_Jumpnv_t_V4
  { 161,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo35,0,0 },  // Inst #161 = CMPGTri_t_Jumpnv_nt_V4
  { 162,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo35,0,0 },  // Inst #162 = CMPGTri_t_Jumpnv_t_V4
  { 163,	3,	1,	3,	4,	0|(1<<MCID::Compare), 0x1e0000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #163 = CMPGTrr
  { 164,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #164 = CMPGTrr_f_Jumpnv_nt_V4
  { 165,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #165 = CMPGTrr_f_Jumpnv_t_V4
  { 166,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #166 = CMPGTrr_t_Jumpnv_nt_V4
  { 167,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #167 = CMPGTrr_t_Jumpnv_t_V4
  { 168,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #168 = CMPLTUrr_f_Jumpnv_nt_V4
  { 169,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #169 = CMPLTUrr_f_Jumpnv_t_V4
  { 170,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #170 = CMPLTUrr_t_Jumpnv_nt_V4
  { 171,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #171 = CMPLTUrr_t_Jumpnv_t_V4
  { 172,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #172 = CMPLTrr_f_Jumpnv_nt_V4
  { 173,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba402caULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #173 = CMPLTrr_f_Jumpnv_t_V4
  { 174,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #174 = CMPLTrr_t_Jumpnv_nt_V4
  { 175,	3,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x18ba4024aULL, NULL, ImplicitList8, OperandInfo12,0,0 },  // Inst #175 = CMPLTrr_t_Jumpnv_t_V4
  { 176,	3,	1,	4,	4,	0|(1<<MCID::Compare), 0x180000008ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #176 = CMPbEQri_V4
  { 177,	3,	1,	4,	4,	0|(1<<MCID::Compare), 0x180000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #177 = CMPbEQrr_sbsb_V4
  { 178,	3,	1,	4,	4,	0|(1<<MCID::Compare), 0x180000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #178 = CMPbEQrr_ubub_V4
  { 179,	3,	1,	4,	4,	0|(1<<MCID::Compare), 0x187240008ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #179 = CMPbGTUri_V4
  { 180,	3,	1,	4,	4,	0|(1<<MCID::Compare), 0x180000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #180 = CMPbGTUrr_V4
  { 181,	3,	1,	4,	4,	0|(1<<MCID::Compare), 0x180000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #181 = CMPbGTrr_V4
  { 182,	3,	1,	4,	4,	0|(1<<MCID::Compare), 0x180000008ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #182 = CMPhEQri_V4
  { 183,	3,	1,	4,	4,	0|(1<<MCID::Compare), 0x180000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #183 = CMPhEQrr_shl_V4
  { 184,	3,	1,	4,	4,	0|(1<<MCID::Compare), 0x180000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #184 = CMPhEQrr_xor_V4
  { 185,	3,	1,	4,	4,	0|(1<<MCID::Compare), 0x187240008ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #185 = CMPhGTUri_V4
  { 186,	3,	1,	4,	4,	0|(1<<MCID::Compare), 0x180000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #186 = CMPhGTUrr_V4
  { 187,	3,	1,	4,	4,	0|(1<<MCID::Compare), 0x180000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #187 = CMPhGTrr_shl_V4
  { 188,	3,	1,	3,	4,	0|(1<<MCID::Compare), 0x180000001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #188 = CMPnotEQ_ri
  { 189,	3,	1,	3,	4,	0|(1<<MCID::Compare), 0x180000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #189 = CMPnotEQ_rr
  { 190,	3,	1,	3,	4,	0|(1<<MCID::Compare), 0x180000001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #190 = CMPnotGTU_ri
  { 191,	3,	1,	3,	4,	0|(1<<MCID::Compare), 0x180000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #191 = CMPnotGTU_rr
  { 192,	3,	1,	3,	4,	0|(1<<MCID::Compare), 0x180000001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #192 = CMPnotGT_ri
  { 193,	3,	1,	3,	4,	0|(1<<MCID::Compare), 0x180000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #193 = CMPnotGT_rr
  { 194,	3,	1,	3,	4,	0, 0x1e8940001ULL, NULL, NULL, OperandInfo37,0,0 },  // Inst #194 = COMBINE_Ii
  { 195,	3,	1,	3,	4,	0, 0x188940001ULL, NULL, NULL, OperandInfo38,0,0 },  // Inst #195 = COMBINE_Ir_V4
  { 196,	3,	1,	3,	4,	0, 0x186240001ULL, NULL, NULL, OperandInfo37,0,0 },  // Inst #196 = COMBINE_iI_V4
  { 197,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo37,0,0 },  // Inst #197 = COMBINE_ii
  { 198,	3,	1,	3,	4,	0, 0x188a40001ULL, NULL, NULL, OperandInfo39,0,0 },  // Inst #198 = COMBINE_rI_V4
  { 199,	3,	1,	3,	4,	0|(1<<MCID::Predicable), 0x1e0000001ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #199 = COMBINE_rr
  { 200,	4,	1,	3,	4,	0, 0x1e00000c1ULL, NULL, NULL, OperandInfo41,0,0 },  // Inst #200 = COMBINE_rr_cNotPt
  { 201,	4,	1,	3,	4,	0, 0x1e0000041ULL, NULL, NULL, OperandInfo41,0,0 },  // Inst #201 = COMBINE_rr_cPt
  { 202,	4,	1,	3,	4,	0, 0x1e00001c1ULL, NULL, NULL, OperandInfo41,0,0 },  // Inst #202 = COMBINE_rr_cdnNotPt
  { 203,	4,	1,	3,	4,	0, 0x1e0000141ULL, NULL, NULL, OperandInfo41,0,0 },  // Inst #203 = COMBINE_rr_cdnPt
  { 204,	2,	1,	11,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::MayLoad), 0x1e0000005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #204 = CONST32
  { 205,	2,	1,	11,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::MayLoad)|(1<<MCID::Rematerializable), 0x1e0000005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #205 = CONST32GP_set
  { 206,	2,	1,	11,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable), 0x1e0000005ULL, NULL, NULL, OperandInfo42,0,0 },  // Inst #206 = CONST32_Float_Real
  { 207,	2,	1,	11,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::MayLoad)|(1<<MCID::Rematerializable), 0x1e0000005ULL, NULL, NULL, OperandInfo42,0,0 },  // Inst #207 = CONST32_Int_Real
  { 208,	2,	1,	11,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::MayLoad)|(1<<MCID::Rematerializable), 0x1e0000005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #208 = CONST32_Label
  { 209,	2,	1,	11,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::MayLoad)|(1<<MCID::Rematerializable), 0x1e0000005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #209 = CONST32_set
  { 210,	2,	1,	11,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::MayLoad)|(1<<MCID::Rematerializable), 0x1e0000005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #210 = CONST32_set_jt
  { 211,	2,	1,	11,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable), 0x1e0000005ULL, NULL, NULL, OperandInfo43,0,0 },  // Inst #211 = CONST64_Float_Real
  { 212,	2,	1,	11,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::MayLoad)|(1<<MCID::Rematerializable), 0x1e0000005ULL, NULL, NULL, OperandInfo43,0,0 },  // Inst #212 = CONST64_Int_Real
  { 213,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #213 = CONVERT_d2df
  { 214,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #214 = CONVERT_d2sf
  { 215,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #215 = CONVERT_df2d
  { 216,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #216 = CONVERT_df2d_nchop
  { 217,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #217 = CONVERT_df2sf
  { 218,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #218 = CONVERT_df2ud
  { 219,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #219 = CONVERT_df2ud_nchop
  { 220,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #220 = CONVERT_df2uw
  { 221,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #221 = CONVERT_df2uw_nchop
  { 222,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #222 = CONVERT_df2w
  { 223,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #223 = CONVERT_df2w_nchop
  { 224,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #224 = CONVERT_sf2d
  { 225,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #225 = CONVERT_sf2d_nchop
  { 226,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #226 = CONVERT_sf2df
  { 227,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #227 = CONVERT_sf2ud
  { 228,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #228 = CONVERT_sf2ud_nchop
  { 229,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #229 = CONVERT_sf2uw
  { 230,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #230 = CONVERT_sf2uw_nchop
  { 231,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #231 = CONVERT_sf2w
  { 232,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #232 = CONVERT_sf2w_nchop
  { 233,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #233 = CONVERT_ud2df
  { 234,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #234 = CONVERT_ud2sf
  { 235,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #235 = CONVERT_uw2df
  { 236,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #236 = CONVERT_uw2sf
  { 237,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #237 = CONVERT_w2df
  { 238,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #238 = CONVERT_w2sf
  { 239,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #239 = CTLZ64_rr
  { 240,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #240 = CTLZ_rr
  { 241,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #241 = CTTZ64_rr
  { 242,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #242 = CTTZ_rr
  { 243,	0,	0,	11,	4,	0|(1<<MCID::MayLoad), 0x1e0000005ULL, ImplicitList3, ImplicitList4, 0,0,0 },  // Inst #243 = DEALLOCFRAME
  { 244,	0,	0,	11,	4,	0|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::MayLoad)|(1<<MCID::Predicable)|(1<<MCID::Terminator), 0x180000005ULL, ImplicitList9, ImplicitList10, 0,0,0 },  // Inst #244 = DEALLOC_RET_V4
  { 245,	1,	0,	11,	4,	0|(1<<MCID::Return)|(1<<MCID::MayLoad)|(1<<MCID::Terminator), 0x1800000c5ULL, ImplicitList9, ImplicitList10, OperandInfo47,0,0 },  // Inst #245 = DEALLOC_RET_cNotPt_V4
  { 246,	1,	0,	11,	4,	0|(1<<MCID::Return)|(1<<MCID::MayLoad)|(1<<MCID::Terminator), 0x1800000c5ULL, ImplicitList9, ImplicitList10, OperandInfo47,0,0 },  // Inst #246 = DEALLOC_RET_cNotdnPnt_V4
  { 247,	1,	0,	11,	4,	0|(1<<MCID::Return)|(1<<MCID::MayLoad)|(1<<MCID::Terminator), 0x1800000c5ULL, ImplicitList9, ImplicitList10, OperandInfo47,0,0 },  // Inst #247 = DEALLOC_RET_cNotdnPt_V4
  { 248,	1,	0,	11,	4,	0|(1<<MCID::Return)|(1<<MCID::MayLoad)|(1<<MCID::Terminator), 0x180000045ULL, ImplicitList9, ImplicitList10, OperandInfo47,0,0 },  // Inst #248 = DEALLOC_RET_cPt_V4
  { 249,	1,	0,	11,	4,	0|(1<<MCID::Return)|(1<<MCID::MayLoad)|(1<<MCID::Terminator), 0x180000045ULL, ImplicitList9, ImplicitList10, OperandInfo47,0,0 },  // Inst #249 = DEALLOC_RET_cdnPnt_V4
  { 250,	1,	0,	11,	4,	0|(1<<MCID::Return)|(1<<MCID::MayLoad)|(1<<MCID::Terminator), 0x180000045ULL, ImplicitList9, ImplicitList10, OperandInfo47,0,0 },  // Inst #250 = DEALLOC_RET_cdnPt_V4
  { 251,	1,	0,	9,	4,	0|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::Terminator), 0x1e0000003ULL, ImplicitList11, ImplicitList8, OperandInfo31,0,0 },  // Inst #251 = EH_RETURN_JMPR
  { 252,	1,	0,	12,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1e000001fULL, ImplicitList12, ImplicitList13, OperandInfo5,0,0 },  // Inst #252 = ENDLOOP0
  { 253,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #253 = FCMPOEQ32_rr
  { 254,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #254 = FCMPOEQ64_rr
  { 255,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #255 = FCMPOGE32_rr
  { 256,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #256 = FCMPOGE64_rr
  { 257,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #257 = FCMPOGT32_rr
  { 258,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #258 = FCMPOGT64_rr
  { 259,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #259 = FCMPUEQ32_rr
  { 260,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #260 = FCMPUEQ64_rr
  { 261,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #261 = FCMPUGE32_rr
  { 262,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #262 = FCMPUGE64_rr
  { 263,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #263 = FCMPUGT32_rr
  { 264,	3,	1,	1,	4,	0|(1<<MCID::Compare), 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #264 = FCMPUGT64_rr
  { 265,	2,	1,	11,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable), 0x1e0000005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #265 = FCONST32_nsdata
  { 266,	4,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #266 = FMADD_dp
  { 267,	4,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #267 = FMADD_sp
  { 268,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #268 = FMAX_dp
  { 269,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #269 = FMAX_sp
  { 270,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #270 = FMIN_dp
  { 271,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #271 = FMIN_sp
  { 272,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #272 = HEXAGON_A2_abs
  { 273,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #273 = HEXAGON_A2_absp
  { 274,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #274 = HEXAGON_A2_abssat
  { 275,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #275 = HEXAGON_A2_add
  { 276,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #276 = HEXAGON_A2_addh_h16_hh
  { 277,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #277 = HEXAGON_A2_addh_h16_hl
  { 278,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #278 = HEXAGON_A2_addh_h16_lh
  { 279,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #279 = HEXAGON_A2_addh_h16_ll
  { 280,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #280 = HEXAGON_A2_addh_h16_sat_hh
  { 281,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #281 = HEXAGON_A2_addh_h16_sat_hl
  { 282,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #282 = HEXAGON_A2_addh_h16_sat_lh
  { 283,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #283 = HEXAGON_A2_addh_h16_sat_ll
  { 284,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #284 = HEXAGON_A2_addh_l16_hl
  { 285,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #285 = HEXAGON_A2_addh_l16_ll
  { 286,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #286 = HEXAGON_A2_addh_l16_sat_hl
  { 287,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #287 = HEXAGON_A2_addh_l16_sat_ll
  { 288,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #288 = HEXAGON_A2_addi
  { 289,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #289 = HEXAGON_A2_addp
  { 290,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #290 = HEXAGON_A2_addsat
  { 291,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #291 = HEXAGON_A2_and
  { 292,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #292 = HEXAGON_A2_andir
  { 293,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #293 = HEXAGON_A2_andp
  { 294,	2,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #294 = HEXAGON_A2_aslh
  { 295,	2,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #295 = HEXAGON_A2_asrh
  { 296,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #296 = HEXAGON_A2_combine_hh
  { 297,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #297 = HEXAGON_A2_combine_hl
  { 298,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #298 = HEXAGON_A2_combine_lh
  { 299,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #299 = HEXAGON_A2_combine_ll
  { 300,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo37,0,0 },  // Inst #300 = HEXAGON_A2_combineii
  { 301,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #301 = HEXAGON_A2_combinew
  { 302,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #302 = HEXAGON_A2_max
  { 303,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #303 = HEXAGON_A2_maxu
  { 304,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #304 = HEXAGON_A2_min
  { 305,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #305 = HEXAGON_A2_minu
  { 306,	2,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #306 = HEXAGON_A2_neg
  { 307,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #307 = HEXAGON_A2_negp
  { 308,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #308 = HEXAGON_A2_negsat
  { 309,	2,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #309 = HEXAGON_A2_not
  { 310,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #310 = HEXAGON_A2_notp
  { 311,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #311 = HEXAGON_A2_or
  { 312,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #312 = HEXAGON_A2_orir
  { 313,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #313 = HEXAGON_A2_orp
  { 314,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #314 = HEXAGON_A2_sat
  { 315,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #315 = HEXAGON_A2_satb
  { 316,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #316 = HEXAGON_A2_sath
  { 317,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #317 = HEXAGON_A2_satub
  { 318,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #318 = HEXAGON_A2_satuh
  { 319,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #319 = HEXAGON_A2_sub
  { 320,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #320 = HEXAGON_A2_subh_h16_hh
  { 321,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #321 = HEXAGON_A2_subh_h16_hl
  { 322,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #322 = HEXAGON_A2_subh_h16_lh
  { 323,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #323 = HEXAGON_A2_subh_h16_ll
  { 324,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #324 = HEXAGON_A2_subh_h16_sat_hh
  { 325,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #325 = HEXAGON_A2_subh_h16_sat_hl
  { 326,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #326 = HEXAGON_A2_subh_h16_sat_lh
  { 327,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #327 = HEXAGON_A2_subh_h16_sat_ll
  { 328,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #328 = HEXAGON_A2_subh_l16_hl
  { 329,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #329 = HEXAGON_A2_subh_l16_ll
  { 330,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #330 = HEXAGON_A2_subh_l16_sat_hl
  { 331,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #331 = HEXAGON_A2_subh_l16_sat_ll
  { 332,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #332 = HEXAGON_A2_subp
  { 333,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #333 = HEXAGON_A2_subri
  { 334,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #334 = HEXAGON_A2_subsat
  { 335,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #335 = HEXAGON_A2_svaddh
  { 336,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #336 = HEXAGON_A2_svaddhs
  { 337,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #337 = HEXAGON_A2_svadduhs
  { 338,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #338 = HEXAGON_A2_svavgh
  { 339,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #339 = HEXAGON_A2_svavghs
  { 340,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #340 = HEXAGON_A2_svnavgh
  { 341,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #341 = HEXAGON_A2_svsubh
  { 342,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #342 = HEXAGON_A2_svsubhs
  { 343,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #343 = HEXAGON_A2_svsubuhs
  { 344,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #344 = HEXAGON_A2_swiz
  { 345,	2,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #345 = HEXAGON_A2_sxtb
  { 346,	2,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #346 = HEXAGON_A2_sxth
  { 347,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #347 = HEXAGON_A2_sxtw
  { 348,	2,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #348 = HEXAGON_A2_tfr
  { 349,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #349 = HEXAGON_A2_tfrih
  { 350,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #350 = HEXAGON_A2_tfril
  { 351,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #351 = HEXAGON_A2_tfrp
  { 352,	2,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #352 = HEXAGON_A2_tfrpi
  { 353,	2,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #353 = HEXAGON_A2_tfrsi
  { 354,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #354 = HEXAGON_A2_vabsh
  { 355,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #355 = HEXAGON_A2_vabshsat
  { 356,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #356 = HEXAGON_A2_vabsw
  { 357,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #357 = HEXAGON_A2_vabswsat
  { 358,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #358 = HEXAGON_A2_vaddh
  { 359,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #359 = HEXAGON_A2_vaddhs
  { 360,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #360 = HEXAGON_A2_vaddub
  { 361,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #361 = HEXAGON_A2_vaddubs
  { 362,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #362 = HEXAGON_A2_vadduhs
  { 363,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #363 = HEXAGON_A2_vaddw
  { 364,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #364 = HEXAGON_A2_vaddws
  { 365,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #365 = HEXAGON_A2_vavgh
  { 366,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #366 = HEXAGON_A2_vavghcr
  { 367,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #367 = HEXAGON_A2_vavghr
  { 368,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #368 = HEXAGON_A2_vavgub
  { 369,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #369 = HEXAGON_A2_vavgubr
  { 370,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #370 = HEXAGON_A2_vavguh
  { 371,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #371 = HEXAGON_A2_vavguhr
  { 372,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #372 = HEXAGON_A2_vavguw
  { 373,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #373 = HEXAGON_A2_vavguwr
  { 374,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #374 = HEXAGON_A2_vavgw
  { 375,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #375 = HEXAGON_A2_vavgwcr
  { 376,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #376 = HEXAGON_A2_vavgwr
  { 377,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #377 = HEXAGON_A2_vcmpbeq
  { 378,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #378 = HEXAGON_A2_vcmpbgtu
  { 379,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #379 = HEXAGON_A2_vcmpheq
  { 380,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #380 = HEXAGON_A2_vcmphgt
  { 381,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #381 = HEXAGON_A2_vcmphgtu
  { 382,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #382 = HEXAGON_A2_vcmpweq
  { 383,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #383 = HEXAGON_A2_vcmpwgt
  { 384,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #384 = HEXAGON_A2_vcmpwgtu
  { 385,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #385 = HEXAGON_A2_vconj
  { 386,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #386 = HEXAGON_A2_vmaxh
  { 387,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #387 = HEXAGON_A2_vmaxub
  { 388,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #388 = HEXAGON_A2_vmaxuh
  { 389,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #389 = HEXAGON_A2_vmaxuw
  { 390,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #390 = HEXAGON_A2_vmaxw
  { 391,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #391 = HEXAGON_A2_vminh
  { 392,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #392 = HEXAGON_A2_vminub
  { 393,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #393 = HEXAGON_A2_vminuh
  { 394,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #394 = HEXAGON_A2_vminuw
  { 395,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #395 = HEXAGON_A2_vminw
  { 396,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #396 = HEXAGON_A2_vnavgh
  { 397,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #397 = HEXAGON_A2_vnavghcr
  { 398,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #398 = HEXAGON_A2_vnavghr
  { 399,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #399 = HEXAGON_A2_vnavgw
  { 400,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #400 = HEXAGON_A2_vnavgwcr
  { 401,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #401 = HEXAGON_A2_vnavgwr
  { 402,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #402 = HEXAGON_A2_vraddub
  { 403,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #403 = HEXAGON_A2_vraddub_acc
  { 404,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #404 = HEXAGON_A2_vrsadub
  { 405,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #405 = HEXAGON_A2_vrsadub_acc
  { 406,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #406 = HEXAGON_A2_vsubh
  { 407,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #407 = HEXAGON_A2_vsubhs
  { 408,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #408 = HEXAGON_A2_vsubub
  { 409,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #409 = HEXAGON_A2_vsububs
  { 410,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #410 = HEXAGON_A2_vsubuhs
  { 411,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #411 = HEXAGON_A2_vsubw
  { 412,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #412 = HEXAGON_A2_vsubws
  { 413,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #413 = HEXAGON_A2_xor
  { 414,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #414 = HEXAGON_A2_xorp
  { 415,	2,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #415 = HEXAGON_A2_zxtb
  { 416,	2,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #416 = HEXAGON_A2_zxth
  { 417,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #417 = HEXAGON_A4_cround_ri
  { 418,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #418 = HEXAGON_A4_cround_rr
  { 419,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #419 = HEXAGON_A4_modwrapu
  { 420,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #420 = HEXAGON_A4_round_ri
  { 421,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #421 = HEXAGON_A4_round_ri_sat
  { 422,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #422 = HEXAGON_A4_round_rr
  { 423,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #423 = HEXAGON_A4_round_rr_sat
  { 424,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo51,0,0 },  // Inst #424 = HEXAGON_A5_vaddhubs
  { 425,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo52,0,0 },  // Inst #425 = HEXAGON_C2_all8
  { 426,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #426 = HEXAGON_C2_and
  { 427,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #427 = HEXAGON_C2_andn
  { 428,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo52,0,0 },  // Inst #428 = HEXAGON_C2_any8
  { 429,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #429 = HEXAGON_C2_cmpeq
  { 430,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #430 = HEXAGON_C2_cmpeqi
  { 431,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #431 = HEXAGON_C2_cmpeqp
  { 432,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #432 = HEXAGON_C2_cmpgei
  { 433,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #433 = HEXAGON_C2_cmpgeui
  { 434,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #434 = HEXAGON_C2_cmpgt
  { 435,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #435 = HEXAGON_C2_cmpgti
  { 436,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #436 = HEXAGON_C2_cmpgtp
  { 437,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #437 = HEXAGON_C2_cmpgtu
  { 438,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #438 = HEXAGON_C2_cmpgtui
  { 439,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #439 = HEXAGON_C2_cmpgtup
  { 440,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #440 = HEXAGON_C2_cmplt
  { 441,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #441 = HEXAGON_C2_cmpltu
  { 442,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #442 = HEXAGON_C2_mask
  { 443,	4,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo53,0,0 },  // Inst #443 = HEXAGON_C2_mux
  { 444,	4,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo54,0,0 },  // Inst #444 = HEXAGON_C2_muxii
  { 445,	4,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #445 = HEXAGON_C2_muxir
  { 446,	4,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #446 = HEXAGON_C2_muxri
  { 447,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo52,0,0 },  // Inst #447 = HEXAGON_C2_not
  { 448,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #448 = HEXAGON_C2_or
  { 449,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #449 = HEXAGON_C2_orn
  { 450,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo52,0,0 },  // Inst #450 = HEXAGON_C2_pxfer_map
  { 451,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #451 = HEXAGON_C2_tfrpr
  { 452,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo52,0,0 },  // Inst #452 = HEXAGON_C2_tfrrp
  { 453,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #453 = HEXAGON_C2_vitpack
  { 454,	4,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo55,0,0 },  // Inst #454 = HEXAGON_C2_vmux
  { 455,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #455 = HEXAGON_C2_xor
  { 456,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #456 = HEXAGON_C4_fastcorner9
  { 457,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #457 = HEXAGON_C4_fastcorner9_not
  { 458,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #458 = HEXAGON_F2_conv_d2df
  { 459,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #459 = HEXAGON_F2_conv_d2sf
  { 460,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #460 = HEXAGON_F2_conv_df2d
  { 461,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #461 = HEXAGON_F2_conv_df2d_chop
  { 462,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #462 = HEXAGON_F2_conv_df2sf
  { 463,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #463 = HEXAGON_F2_conv_df2ud
  { 464,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #464 = HEXAGON_F2_conv_df2ud_chop
  { 465,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #465 = HEXAGON_F2_conv_df2uw
  { 466,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #466 = HEXAGON_F2_conv_df2uw_chop
  { 467,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #467 = HEXAGON_F2_conv_df2w
  { 468,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #468 = HEXAGON_F2_conv_df2w_chop
  { 469,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #469 = HEXAGON_F2_conv_sf2d
  { 470,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #470 = HEXAGON_F2_conv_sf2d_chop
  { 471,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #471 = HEXAGON_F2_conv_sf2df
  { 472,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #472 = HEXAGON_F2_conv_sf2ud
  { 473,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #473 = HEXAGON_F2_conv_sf2ud_chop
  { 474,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #474 = HEXAGON_F2_conv_sf2uw
  { 475,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #475 = HEXAGON_F2_conv_sf2uw_chop
  { 476,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #476 = HEXAGON_F2_conv_sf2w
  { 477,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #477 = HEXAGON_F2_conv_sf2w_chop
  { 478,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #478 = HEXAGON_F2_conv_ud2df
  { 479,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #479 = HEXAGON_F2_conv_ud2sf
  { 480,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #480 = HEXAGON_F2_conv_uw2df
  { 481,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #481 = HEXAGON_F2_conv_uw2sf
  { 482,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #482 = HEXAGON_F2_conv_w2df
  { 483,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #483 = HEXAGON_F2_conv_w2sf
  { 484,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #484 = HEXAGON_F2_dfadd
  { 485,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #485 = HEXAGON_F2_dfclass
  { 486,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #486 = HEXAGON_F2_dfcmpeq
  { 487,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #487 = HEXAGON_F2_dfcmpge
  { 488,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #488 = HEXAGON_F2_dfcmpgt
  { 489,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo32,0,0 },  // Inst #489 = HEXAGON_F2_dfcmpuo
  { 490,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #490 = HEXAGON_F2_dffixupd
  { 491,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #491 = HEXAGON_F2_dffixupn
  { 492,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #492 = HEXAGON_F2_dffixupr
  { 493,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo57,0,0 },  // Inst #493 = HEXAGON_F2_dffma
  { 494,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo57,0,0 },  // Inst #494 = HEXAGON_F2_dffma_lib
  { 495,	5,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #495 = HEXAGON_F2_dffma_sc
  { 496,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo57,0,0 },  // Inst #496 = HEXAGON_F2_dffms
  { 497,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo57,0,0 },  // Inst #497 = HEXAGON_F2_dffms_lib
  { 498,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #498 = HEXAGON_F2_dfimm_n
  { 499,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #499 = HEXAGON_F2_dfimm_p
  { 500,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #500 = HEXAGON_F2_dfmax
  { 501,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #501 = HEXAGON_F2_dfmin
  { 502,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #502 = HEXAGON_F2_dfmpy
  { 503,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #503 = HEXAGON_F2_dfsub
  { 504,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #504 = HEXAGON_F2_sfadd
  { 505,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #505 = HEXAGON_F2_sfclass
  { 506,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #506 = HEXAGON_F2_sfcmpeq
  { 507,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #507 = HEXAGON_F2_sfcmpge
  { 508,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #508 = HEXAGON_F2_sfcmpgt
  { 509,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #509 = HEXAGON_F2_sfcmpuo
  { 510,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #510 = HEXAGON_F2_sffixupd
  { 511,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #511 = HEXAGON_F2_sffixupn
  { 512,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #512 = HEXAGON_F2_sffixupr
  { 513,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo59,0,0 },  // Inst #513 = HEXAGON_F2_sffma
  { 514,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo59,0,0 },  // Inst #514 = HEXAGON_F2_sffma_lib
  { 515,	5,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo60,0,0 },  // Inst #515 = HEXAGON_F2_sffma_sc
  { 516,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo59,0,0 },  // Inst #516 = HEXAGON_F2_sffms
  { 517,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo59,0,0 },  // Inst #517 = HEXAGON_F2_sffms_lib
  { 518,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #518 = HEXAGON_F2_sfimm_n
  { 519,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #519 = HEXAGON_F2_sfimm_p
  { 520,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #520 = HEXAGON_F2_sfmax
  { 521,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #521 = HEXAGON_F2_sfmin
  { 522,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #522 = HEXAGON_F2_sfmpy
  { 523,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #523 = HEXAGON_F2_sfsub
  { 524,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #524 = HEXAGON_M2_acci
  { 525,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #525 = HEXAGON_M2_accii
  { 526,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #526 = HEXAGON_M2_cmaci_s0
  { 527,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #527 = HEXAGON_M2_cmacr_s0
  { 528,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #528 = HEXAGON_M2_cmacs_s0
  { 529,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #529 = HEXAGON_M2_cmacs_s1
  { 530,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #530 = HEXAGON_M2_cmacsc_s0
  { 531,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #531 = HEXAGON_M2_cmacsc_s1
  { 532,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #532 = HEXAGON_M2_cmpyi_s0
  { 533,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #533 = HEXAGON_M2_cmpyr_s0
  { 534,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #534 = HEXAGON_M2_cmpyrs_s0
  { 535,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #535 = HEXAGON_M2_cmpyrs_s1
  { 536,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #536 = HEXAGON_M2_cmpyrsc_s0
  { 537,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #537 = HEXAGON_M2_cmpyrsc_s1
  { 538,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #538 = HEXAGON_M2_cmpys_s0
  { 539,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #539 = HEXAGON_M2_cmpys_s1
  { 540,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #540 = HEXAGON_M2_cmpysc_s0
  { 541,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #541 = HEXAGON_M2_cmpysc_s1
  { 542,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #542 = HEXAGON_M2_cnacs_s0
  { 543,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #543 = HEXAGON_M2_cnacs_s1
  { 544,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #544 = HEXAGON_M2_cnacsc_s0
  { 545,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #545 = HEXAGON_M2_cnacsc_s1
  { 546,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #546 = HEXAGON_M2_dpmpyss_acc_s0
  { 547,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #547 = HEXAGON_M2_dpmpyss_nac_s0
  { 548,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #548 = HEXAGON_M2_dpmpyss_rnd_s0
  { 549,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #549 = HEXAGON_M2_dpmpyss_s0
  { 550,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #550 = HEXAGON_M2_dpmpyuu_acc_s0
  { 551,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #551 = HEXAGON_M2_dpmpyuu_nac_s0
  { 552,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #552 = HEXAGON_M2_dpmpyuu_s0
  { 553,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #553 = HEXAGON_M2_hmmpyh_rs1
  { 554,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #554 = HEXAGON_M2_hmmpyl_rs1
  { 555,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #555 = HEXAGON_M2_maci
  { 556,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #556 = HEXAGON_M2_macsin
  { 557,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #557 = HEXAGON_M2_macsip
  { 558,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #558 = HEXAGON_M2_mmachs_rs0
  { 559,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #559 = HEXAGON_M2_mmachs_rs1
  { 560,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #560 = HEXAGON_M2_mmachs_s0
  { 561,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #561 = HEXAGON_M2_mmachs_s1
  { 562,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #562 = HEXAGON_M2_mmacls_rs0
  { 563,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #563 = HEXAGON_M2_mmacls_rs1
  { 564,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #564 = HEXAGON_M2_mmacls_s0
  { 565,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #565 = HEXAGON_M2_mmacls_s1
  { 566,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #566 = HEXAGON_M2_mmacuhs_rs0
  { 567,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #567 = HEXAGON_M2_mmacuhs_rs1
  { 568,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #568 = HEXAGON_M2_mmacuhs_s0
  { 569,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #569 = HEXAGON_M2_mmacuhs_s1
  { 570,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #570 = HEXAGON_M2_mmaculs_rs0
  { 571,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #571 = HEXAGON_M2_mmaculs_rs1
  { 572,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #572 = HEXAGON_M2_mmaculs_s0
  { 573,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #573 = HEXAGON_M2_mmaculs_s1
  { 574,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #574 = HEXAGON_M2_mmpyh_rs0
  { 575,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #575 = HEXAGON_M2_mmpyh_rs1
  { 576,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #576 = HEXAGON_M2_mmpyh_s0
  { 577,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #577 = HEXAGON_M2_mmpyh_s1
  { 578,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #578 = HEXAGON_M2_mmpyl_rs0
  { 579,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #579 = HEXAGON_M2_mmpyl_rs1
  { 580,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #580 = HEXAGON_M2_mmpyl_s0
  { 581,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #581 = HEXAGON_M2_mmpyl_s1
  { 582,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #582 = HEXAGON_M2_mmpyuh_rs0
  { 583,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #583 = HEXAGON_M2_mmpyuh_rs1
  { 584,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #584 = HEXAGON_M2_mmpyuh_s0
  { 585,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #585 = HEXAGON_M2_mmpyuh_s1
  { 586,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #586 = HEXAGON_M2_mmpyul_rs0
  { 587,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #587 = HEXAGON_M2_mmpyul_rs1
  { 588,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #588 = HEXAGON_M2_mmpyul_s0
  { 589,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #589 = HEXAGON_M2_mmpyul_s1
  { 590,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #590 = HEXAGON_M2_mpy_acc_hh_s0
  { 591,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #591 = HEXAGON_M2_mpy_acc_hh_s1
  { 592,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #592 = HEXAGON_M2_mpy_acc_hl_s0
  { 593,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #593 = HEXAGON_M2_mpy_acc_hl_s1
  { 594,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #594 = HEXAGON_M2_mpy_acc_lh_s0
  { 595,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #595 = HEXAGON_M2_mpy_acc_lh_s1
  { 596,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #596 = HEXAGON_M2_mpy_acc_ll_s0
  { 597,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #597 = HEXAGON_M2_mpy_acc_ll_s1
  { 598,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #598 = HEXAGON_M2_mpy_acc_sat_hh_s0
  { 599,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #599 = HEXAGON_M2_mpy_acc_sat_hh_s1
  { 600,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #600 = HEXAGON_M2_mpy_acc_sat_hl_s0
  { 601,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #601 = HEXAGON_M2_mpy_acc_sat_hl_s1
  { 602,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #602 = HEXAGON_M2_mpy_acc_sat_lh_s0
  { 603,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #603 = HEXAGON_M2_mpy_acc_sat_lh_s1
  { 604,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #604 = HEXAGON_M2_mpy_acc_sat_ll_s0
  { 605,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #605 = HEXAGON_M2_mpy_acc_sat_ll_s1
  { 606,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #606 = HEXAGON_M2_mpy_hh_s0
  { 607,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #607 = HEXAGON_M2_mpy_hh_s1
  { 608,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #608 = HEXAGON_M2_mpy_hl_s0
  { 609,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #609 = HEXAGON_M2_mpy_hl_s1
  { 610,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #610 = HEXAGON_M2_mpy_lh_s0
  { 611,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #611 = HEXAGON_M2_mpy_lh_s1
  { 612,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #612 = HEXAGON_M2_mpy_ll_s0
  { 613,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #613 = HEXAGON_M2_mpy_ll_s1
  { 614,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #614 = HEXAGON_M2_mpy_nac_hh_s0
  { 615,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #615 = HEXAGON_M2_mpy_nac_hh_s1
  { 616,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #616 = HEXAGON_M2_mpy_nac_hl_s0
  { 617,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #617 = HEXAGON_M2_mpy_nac_hl_s1
  { 618,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #618 = HEXAGON_M2_mpy_nac_lh_s0
  { 619,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #619 = HEXAGON_M2_mpy_nac_lh_s1
  { 620,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #620 = HEXAGON_M2_mpy_nac_ll_s0
  { 621,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #621 = HEXAGON_M2_mpy_nac_ll_s1
  { 622,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #622 = HEXAGON_M2_mpy_nac_sat_hh_s0
  { 623,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #623 = HEXAGON_M2_mpy_nac_sat_hh_s1
  { 624,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #624 = HEXAGON_M2_mpy_nac_sat_hl_s0
  { 625,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #625 = HEXAGON_M2_mpy_nac_sat_hl_s1
  { 626,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #626 = HEXAGON_M2_mpy_nac_sat_lh_s0
  { 627,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #627 = HEXAGON_M2_mpy_nac_sat_lh_s1
  { 628,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #628 = HEXAGON_M2_mpy_nac_sat_ll_s0
  { 629,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #629 = HEXAGON_M2_mpy_nac_sat_ll_s1
  { 630,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #630 = HEXAGON_M2_mpy_rnd_hh_s0
  { 631,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #631 = HEXAGON_M2_mpy_rnd_hh_s1
  { 632,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #632 = HEXAGON_M2_mpy_rnd_hl_s0
  { 633,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #633 = HEXAGON_M2_mpy_rnd_hl_s1
  { 634,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #634 = HEXAGON_M2_mpy_rnd_lh_s0
  { 635,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #635 = HEXAGON_M2_mpy_rnd_lh_s1
  { 636,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #636 = HEXAGON_M2_mpy_rnd_ll_s0
  { 637,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #637 = HEXAGON_M2_mpy_rnd_ll_s1
  { 638,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #638 = HEXAGON_M2_mpy_sat_hh_s0
  { 639,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #639 = HEXAGON_M2_mpy_sat_hh_s1
  { 640,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #640 = HEXAGON_M2_mpy_sat_hl_s0
  { 641,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #641 = HEXAGON_M2_mpy_sat_hl_s1
  { 642,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #642 = HEXAGON_M2_mpy_sat_lh_s0
  { 643,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #643 = HEXAGON_M2_mpy_sat_lh_s1
  { 644,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #644 = HEXAGON_M2_mpy_sat_ll_s0
  { 645,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #645 = HEXAGON_M2_mpy_sat_ll_s1
  { 646,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #646 = HEXAGON_M2_mpy_sat_rnd_hh_s0
  { 647,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #647 = HEXAGON_M2_mpy_sat_rnd_hh_s1
  { 648,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #648 = HEXAGON_M2_mpy_sat_rnd_hl_s0
  { 649,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #649 = HEXAGON_M2_mpy_sat_rnd_hl_s1
  { 650,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #650 = HEXAGON_M2_mpy_sat_rnd_lh_s0
  { 651,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #651 = HEXAGON_M2_mpy_sat_rnd_lh_s1
  { 652,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #652 = HEXAGON_M2_mpy_sat_rnd_ll_s0
  { 653,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #653 = HEXAGON_M2_mpy_sat_rnd_ll_s1
  { 654,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #654 = HEXAGON_M2_mpy_up
  { 655,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #655 = HEXAGON_M2_mpyd_acc_hh_s0
  { 656,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #656 = HEXAGON_M2_mpyd_acc_hh_s1
  { 657,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #657 = HEXAGON_M2_mpyd_acc_hl_s0
  { 658,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #658 = HEXAGON_M2_mpyd_acc_hl_s1
  { 659,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #659 = HEXAGON_M2_mpyd_acc_lh_s0
  { 660,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #660 = HEXAGON_M2_mpyd_acc_lh_s1
  { 661,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #661 = HEXAGON_M2_mpyd_acc_ll_s0
  { 662,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #662 = HEXAGON_M2_mpyd_acc_ll_s1
  { 663,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #663 = HEXAGON_M2_mpyd_hh_s0
  { 664,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #664 = HEXAGON_M2_mpyd_hh_s1
  { 665,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #665 = HEXAGON_M2_mpyd_hl_s0
  { 666,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #666 = HEXAGON_M2_mpyd_hl_s1
  { 667,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #667 = HEXAGON_M2_mpyd_lh_s0
  { 668,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #668 = HEXAGON_M2_mpyd_lh_s1
  { 669,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #669 = HEXAGON_M2_mpyd_ll_s0
  { 670,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #670 = HEXAGON_M2_mpyd_ll_s1
  { 671,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #671 = HEXAGON_M2_mpyd_nac_hh_s0
  { 672,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #672 = HEXAGON_M2_mpyd_nac_hh_s1
  { 673,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #673 = HEXAGON_M2_mpyd_nac_hl_s0
  { 674,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #674 = HEXAGON_M2_mpyd_nac_hl_s1
  { 675,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #675 = HEXAGON_M2_mpyd_nac_lh_s0
  { 676,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #676 = HEXAGON_M2_mpyd_nac_lh_s1
  { 677,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #677 = HEXAGON_M2_mpyd_nac_ll_s0
  { 678,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #678 = HEXAGON_M2_mpyd_nac_ll_s1
  { 679,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #679 = HEXAGON_M2_mpyd_rnd_hh_s0
  { 680,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #680 = HEXAGON_M2_mpyd_rnd_hh_s1
  { 681,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #681 = HEXAGON_M2_mpyd_rnd_hl_s0
  { 682,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #682 = HEXAGON_M2_mpyd_rnd_hl_s1
  { 683,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #683 = HEXAGON_M2_mpyd_rnd_lh_s0
  { 684,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #684 = HEXAGON_M2_mpyd_rnd_lh_s1
  { 685,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #685 = HEXAGON_M2_mpyd_rnd_ll_s0
  { 686,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #686 = HEXAGON_M2_mpyd_rnd_ll_s1
  { 687,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #687 = HEXAGON_M2_mpyi
  { 688,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #688 = HEXAGON_M2_mpyu_acc_hh_s0
  { 689,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #689 = HEXAGON_M2_mpyu_acc_hh_s1
  { 690,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #690 = HEXAGON_M2_mpyu_acc_hl_s0
  { 691,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #691 = HEXAGON_M2_mpyu_acc_hl_s1
  { 692,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #692 = HEXAGON_M2_mpyu_acc_lh_s0
  { 693,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #693 = HEXAGON_M2_mpyu_acc_lh_s1
  { 694,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #694 = HEXAGON_M2_mpyu_acc_ll_s0
  { 695,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #695 = HEXAGON_M2_mpyu_acc_ll_s1
  { 696,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #696 = HEXAGON_M2_mpyu_hh_s0
  { 697,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #697 = HEXAGON_M2_mpyu_hh_s1
  { 698,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #698 = HEXAGON_M2_mpyu_hl_s0
  { 699,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #699 = HEXAGON_M2_mpyu_hl_s1
  { 700,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #700 = HEXAGON_M2_mpyu_lh_s0
  { 701,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #701 = HEXAGON_M2_mpyu_lh_s1
  { 702,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #702 = HEXAGON_M2_mpyu_ll_s0
  { 703,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #703 = HEXAGON_M2_mpyu_ll_s1
  { 704,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #704 = HEXAGON_M2_mpyu_nac_hh_s0
  { 705,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #705 = HEXAGON_M2_mpyu_nac_hh_s1
  { 706,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #706 = HEXAGON_M2_mpyu_nac_hl_s0
  { 707,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #707 = HEXAGON_M2_mpyu_nac_hl_s1
  { 708,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #708 = HEXAGON_M2_mpyu_nac_lh_s0
  { 709,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #709 = HEXAGON_M2_mpyu_nac_lh_s1
  { 710,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #710 = HEXAGON_M2_mpyu_nac_ll_s0
  { 711,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #711 = HEXAGON_M2_mpyu_nac_ll_s1
  { 712,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #712 = HEXAGON_M2_mpyu_up
  { 713,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #713 = HEXAGON_M2_mpyud_acc_hh_s0
  { 714,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #714 = HEXAGON_M2_mpyud_acc_hh_s1
  { 715,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #715 = HEXAGON_M2_mpyud_acc_hl_s0
  { 716,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #716 = HEXAGON_M2_mpyud_acc_hl_s1
  { 717,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #717 = HEXAGON_M2_mpyud_acc_lh_s0
  { 718,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #718 = HEXAGON_M2_mpyud_acc_lh_s1
  { 719,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #719 = HEXAGON_M2_mpyud_acc_ll_s0
  { 720,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #720 = HEXAGON_M2_mpyud_acc_ll_s1
  { 721,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #721 = HEXAGON_M2_mpyud_hh_s0
  { 722,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #722 = HEXAGON_M2_mpyud_hh_s1
  { 723,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #723 = HEXAGON_M2_mpyud_hl_s0
  { 724,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #724 = HEXAGON_M2_mpyud_hl_s1
  { 725,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #725 = HEXAGON_M2_mpyud_lh_s0
  { 726,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #726 = HEXAGON_M2_mpyud_lh_s1
  { 727,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #727 = HEXAGON_M2_mpyud_ll_s0
  { 728,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #728 = HEXAGON_M2_mpyud_ll_s1
  { 729,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #729 = HEXAGON_M2_mpyud_nac_hh_s0
  { 730,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #730 = HEXAGON_M2_mpyud_nac_hh_s1
  { 731,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #731 = HEXAGON_M2_mpyud_nac_hl_s0
  { 732,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #732 = HEXAGON_M2_mpyud_nac_hl_s1
  { 733,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #733 = HEXAGON_M2_mpyud_nac_lh_s0
  { 734,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #734 = HEXAGON_M2_mpyud_nac_lh_s1
  { 735,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #735 = HEXAGON_M2_mpyud_nac_ll_s0
  { 736,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #736 = HEXAGON_M2_mpyud_nac_ll_s1
  { 737,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #737 = HEXAGON_M2_mpyui
  { 738,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #738 = HEXAGON_M2_nacci
  { 739,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #739 = HEXAGON_M2_naccii
  { 740,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #740 = HEXAGON_M2_subacc
  { 741,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #741 = HEXAGON_M2_vabsdiffh
  { 742,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #742 = HEXAGON_M2_vabsdiffw
  { 743,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #743 = HEXAGON_M2_vcmac_s0_sat_i
  { 744,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #744 = HEXAGON_M2_vcmac_s0_sat_r
  { 745,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #745 = HEXAGON_M2_vcmpy_s0_sat_i
  { 746,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #746 = HEXAGON_M2_vcmpy_s0_sat_r
  { 747,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #747 = HEXAGON_M2_vcmpy_s1_sat_i
  { 748,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #748 = HEXAGON_M2_vcmpy_s1_sat_r
  { 749,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #749 = HEXAGON_M2_vdmacs_s0
  { 750,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #750 = HEXAGON_M2_vdmacs_s1
  { 751,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo51,0,0 },  // Inst #751 = HEXAGON_M2_vdmpyrs_s0
  { 752,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo51,0,0 },  // Inst #752 = HEXAGON_M2_vdmpyrs_s1
  { 753,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #753 = HEXAGON_M2_vdmpys_s0
  { 754,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #754 = HEXAGON_M2_vdmpys_s1
  { 755,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #755 = HEXAGON_M2_vmac2
  { 756,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #756 = HEXAGON_M2_vmac2es
  { 757,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #757 = HEXAGON_M2_vmac2es_s0
  { 758,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #758 = HEXAGON_M2_vmac2es_s1
  { 759,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #759 = HEXAGON_M2_vmac2s_s0
  { 760,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #760 = HEXAGON_M2_vmac2s_s1
  { 761,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #761 = HEXAGON_M2_vmpy2es_s0
  { 762,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #762 = HEXAGON_M2_vmpy2es_s1
  { 763,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #763 = HEXAGON_M2_vmpy2s_s0
  { 764,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #764 = HEXAGON_M2_vmpy2s_s0pack
  { 765,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #765 = HEXAGON_M2_vmpy2s_s1
  { 766,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #766 = HEXAGON_M2_vmpy2s_s1pack
  { 767,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #767 = HEXAGON_M2_vrcmaci_s0
  { 768,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #768 = HEXAGON_M2_vrcmaci_s0c
  { 769,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #769 = HEXAGON_M2_vrcmacr_s0
  { 770,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #770 = HEXAGON_M2_vrcmacr_s0c
  { 771,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #771 = HEXAGON_M2_vrcmpyi_s0
  { 772,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #772 = HEXAGON_M2_vrcmpyi_s0c
  { 773,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #773 = HEXAGON_M2_vrcmpyr_s0
  { 774,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #774 = HEXAGON_M2_vrcmpyr_s0c
  { 775,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #775 = HEXAGON_M2_vrmac_s0
  { 776,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #776 = HEXAGON_M2_vrmpy_s0
  { 777,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #777 = HEXAGON_M2_xor_xacc
  { 778,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo53,0,0 },  // Inst #778 = HEXAGON_M4_and_and
  { 779,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo53,0,0 },  // Inst #779 = HEXAGON_M4_and_andn
  { 780,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo53,0,0 },  // Inst #780 = HEXAGON_M4_and_or
  { 781,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo53,0,0 },  // Inst #781 = HEXAGON_M4_and_xor
  { 782,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo53,0,0 },  // Inst #782 = HEXAGON_M4_or_and
  { 783,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo53,0,0 },  // Inst #783 = HEXAGON_M4_or_andn
  { 784,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo53,0,0 },  // Inst #784 = HEXAGON_M4_or_or
  { 785,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo53,0,0 },  // Inst #785 = HEXAGON_M4_or_xor
  { 786,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo53,0,0 },  // Inst #786 = HEXAGON_M4_xor_and
  { 787,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo53,0,0 },  // Inst #787 = HEXAGON_M4_xor_andn
  { 788,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo53,0,0 },  // Inst #788 = HEXAGON_M4_xor_or
  { 789,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #789 = HEXAGON_M5_vdmacbsu
  { 790,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #790 = HEXAGON_M5_vdmpybsu
  { 791,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #791 = HEXAGON_M5_vmacbsu
  { 792,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #792 = HEXAGON_M5_vmacbuu
  { 793,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #793 = HEXAGON_M5_vmpybsu
  { 794,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #794 = HEXAGON_M5_vmpybuu
  { 795,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #795 = HEXAGON_M5_vrmacbsu
  { 796,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #796 = HEXAGON_M5_vrmacbuu
  { 797,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #797 = HEXAGON_M5_vrmpybsu
  { 798,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #798 = HEXAGON_M5_vrmpybuu
  { 799,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #799 = HEXAGON_S2_addasl_rrri
  { 800,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo30,0,0 },  // Inst #800 = HEXAGON_S2_asl_i_p
  { 801,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #801 = HEXAGON_S2_asl_i_p_acc
  { 802,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #802 = HEXAGON_S2_asl_i_p_and
  { 803,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #803 = HEXAGON_S2_asl_i_p_nac
  { 804,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #804 = HEXAGON_S2_asl_i_p_or
  { 805,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #805 = HEXAGON_S2_asl_i_p_xacc
  { 806,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #806 = HEXAGON_S2_asl_i_r
  { 807,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #807 = HEXAGON_S2_asl_i_r_acc
  { 808,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #808 = HEXAGON_S2_asl_i_r_and
  { 809,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #809 = HEXAGON_S2_asl_i_r_nac
  { 810,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #810 = HEXAGON_S2_asl_i_r_or
  { 811,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #811 = HEXAGON_S2_asl_i_r_sat
  { 812,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #812 = HEXAGON_S2_asl_i_r_xacc
  { 813,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #813 = HEXAGON_S2_asl_i_vh
  { 814,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #814 = HEXAGON_S2_asl_i_vw
  { 815,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #815 = HEXAGON_S2_asl_r_p
  { 816,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #816 = HEXAGON_S2_asl_r_p_acc
  { 817,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #817 = HEXAGON_S2_asl_r_p_and
  { 818,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #818 = HEXAGON_S2_asl_r_p_nac
  { 819,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #819 = HEXAGON_S2_asl_r_p_or
  { 820,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #820 = HEXAGON_S2_asl_r_r
  { 821,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #821 = HEXAGON_S2_asl_r_r_acc
  { 822,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #822 = HEXAGON_S2_asl_r_r_and
  { 823,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #823 = HEXAGON_S2_asl_r_r_nac
  { 824,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #824 = HEXAGON_S2_asl_r_r_or
  { 825,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #825 = HEXAGON_S2_asl_r_r_sat
  { 826,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #826 = HEXAGON_S2_asl_r_vh
  { 827,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #827 = HEXAGON_S2_asl_r_vw
  { 828,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo30,0,0 },  // Inst #828 = HEXAGON_S2_asr_i_p
  { 829,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #829 = HEXAGON_S2_asr_i_p_acc
  { 830,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #830 = HEXAGON_S2_asr_i_p_and
  { 831,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #831 = HEXAGON_S2_asr_i_p_nac
  { 832,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #832 = HEXAGON_S2_asr_i_p_or
  { 833,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo30,0,0 },  // Inst #833 = HEXAGON_S2_asr_i_p_rnd
  { 834,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo30,0,0 },  // Inst #834 = HEXAGON_S2_asr_i_p_rnd_goodsyntax
  { 835,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #835 = HEXAGON_S2_asr_i_r
  { 836,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #836 = HEXAGON_S2_asr_i_r_acc
  { 837,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #837 = HEXAGON_S2_asr_i_r_and
  { 838,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #838 = HEXAGON_S2_asr_i_r_nac
  { 839,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #839 = HEXAGON_S2_asr_i_r_or
  { 840,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #840 = HEXAGON_S2_asr_i_r_rnd
  { 841,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #841 = HEXAGON_S2_asr_i_r_rnd_goodsyntax
  { 842,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo62,0,0 },  // Inst #842 = HEXAGON_S2_asr_i_svw_trun
  { 843,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #843 = HEXAGON_S2_asr_i_vh
  { 844,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #844 = HEXAGON_S2_asr_i_vw
  { 845,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #845 = HEXAGON_S2_asr_r_p
  { 846,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #846 = HEXAGON_S2_asr_r_p_acc
  { 847,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #847 = HEXAGON_S2_asr_r_p_and
  { 848,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #848 = HEXAGON_S2_asr_r_p_nac
  { 849,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #849 = HEXAGON_S2_asr_r_p_or
  { 850,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #850 = HEXAGON_S2_asr_r_r
  { 851,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #851 = HEXAGON_S2_asr_r_r_acc
  { 852,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #852 = HEXAGON_S2_asr_r_r_and
  { 853,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #853 = HEXAGON_S2_asr_r_r_nac
  { 854,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #854 = HEXAGON_S2_asr_r_r_or
  { 855,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #855 = HEXAGON_S2_asr_r_r_sat
  { 856,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo63,0,0 },  // Inst #856 = HEXAGON_S2_asr_r_svw_trun
  { 857,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #857 = HEXAGON_S2_asr_r_vh
  { 858,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #858 = HEXAGON_S2_asr_r_vw
  { 859,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #859 = HEXAGON_S2_cl0
  { 860,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #860 = HEXAGON_S2_cl0p
  { 861,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #861 = HEXAGON_S2_cl1
  { 862,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #862 = HEXAGON_S2_cl1p
  { 863,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #863 = HEXAGON_S2_clb
  { 864,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #864 = HEXAGON_S2_clbnorm
  { 865,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #865 = HEXAGON_S2_clbp
  { 866,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #866 = HEXAGON_S2_clrbit_i
  { 867,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #867 = HEXAGON_S2_clrbit_r
  { 868,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #868 = HEXAGON_S2_ct0
  { 869,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #869 = HEXAGON_S2_ct1
  { 870,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo54,0,0 },  // Inst #870 = HEXAGON_S2_extractu
  { 871,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo64,0,0 },  // Inst #871 = HEXAGON_S2_extractu_rp
  { 872,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo65,0,0 },  // Inst #872 = HEXAGON_S2_extractup
  { 873,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #873 = HEXAGON_S2_extractup_rp
  { 874,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #874 = HEXAGON_S2_lsl_r_p
  { 875,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #875 = HEXAGON_S2_lsl_r_p_acc
  { 876,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #876 = HEXAGON_S2_lsl_r_p_and
  { 877,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #877 = HEXAGON_S2_lsl_r_p_nac
  { 878,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #878 = HEXAGON_S2_lsl_r_p_or
  { 879,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #879 = HEXAGON_S2_lsl_r_r
  { 880,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #880 = HEXAGON_S2_lsl_r_r_acc
  { 881,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #881 = HEXAGON_S2_lsl_r_r_and
  { 882,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #882 = HEXAGON_S2_lsl_r_r_nac
  { 883,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #883 = HEXAGON_S2_lsl_r_r_or
  { 884,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #884 = HEXAGON_S2_lsl_r_vh
  { 885,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #885 = HEXAGON_S2_lsl_r_vw
  { 886,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo30,0,0 },  // Inst #886 = HEXAGON_S2_lsr_i_p
  { 887,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #887 = HEXAGON_S2_lsr_i_p_acc
  { 888,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #888 = HEXAGON_S2_lsr_i_p_and
  { 889,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #889 = HEXAGON_S2_lsr_i_p_nac
  { 890,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #890 = HEXAGON_S2_lsr_i_p_or
  { 891,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #891 = HEXAGON_S2_lsr_i_p_xacc
  { 892,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #892 = HEXAGON_S2_lsr_i_r
  { 893,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #893 = HEXAGON_S2_lsr_i_r_acc
  { 894,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #894 = HEXAGON_S2_lsr_i_r_and
  { 895,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #895 = HEXAGON_S2_lsr_i_r_nac
  { 896,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #896 = HEXAGON_S2_lsr_i_r_or
  { 897,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #897 = HEXAGON_S2_lsr_i_r_xacc
  { 898,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #898 = HEXAGON_S2_lsr_i_vh
  { 899,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #899 = HEXAGON_S2_lsr_i_vw
  { 900,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #900 = HEXAGON_S2_lsr_r_p
  { 901,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #901 = HEXAGON_S2_lsr_r_p_acc
  { 902,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #902 = HEXAGON_S2_lsr_r_p_and
  { 903,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #903 = HEXAGON_S2_lsr_r_p_nac
  { 904,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #904 = HEXAGON_S2_lsr_r_p_or
  { 905,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #905 = HEXAGON_S2_lsr_r_r
  { 906,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #906 = HEXAGON_S2_lsr_r_r_acc
  { 907,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #907 = HEXAGON_S2_lsr_r_r_and
  { 908,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #908 = HEXAGON_S2_lsr_r_r_nac
  { 909,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #909 = HEXAGON_S2_lsr_r_r_or
  { 910,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #910 = HEXAGON_S2_lsr_r_vh
  { 911,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #911 = HEXAGON_S2_lsr_r_vw
  { 912,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #912 = HEXAGON_S2_packhl
  { 913,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo51,0,0 },  // Inst #913 = HEXAGON_S2_parityp
  { 914,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #914 = HEXAGON_S2_setbit_i
  { 915,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #915 = HEXAGON_S2_setbit_r
  { 916,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #916 = HEXAGON_S2_shuffeb
  { 917,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #917 = HEXAGON_S2_shuffeh
  { 918,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #918 = HEXAGON_S2_shuffob
  { 919,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #919 = HEXAGON_S2_shuffoh
  { 920,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #920 = HEXAGON_S2_svsathb
  { 921,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #921 = HEXAGON_S2_svsathub
  { 922,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #922 = HEXAGON_S2_togglebit_i
  { 923,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #923 = HEXAGON_S2_togglebit_r
  { 924,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #924 = HEXAGON_S2_tstbit_i
  { 925,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #925 = HEXAGON_S2_tstbit_r
  { 926,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo66,0,0 },  // Inst #926 = HEXAGON_S2_valignib
  { 927,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo67,0,0 },  // Inst #927 = HEXAGON_S2_valignrb
  { 928,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #928 = HEXAGON_S2_vcrotate
  { 929,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #929 = HEXAGON_S2_vrndpackwh
  { 930,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #930 = HEXAGON_S2_vrndpackwhs
  { 931,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #931 = HEXAGON_S2_vsathb
  { 932,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #932 = HEXAGON_S2_vsathb_nopack
  { 933,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #933 = HEXAGON_S2_vsathub
  { 934,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #934 = HEXAGON_S2_vsathub_nopack
  { 935,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #935 = HEXAGON_S2_vsatwh
  { 936,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #936 = HEXAGON_S2_vsatwh_nopack
  { 937,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #937 = HEXAGON_S2_vsatwuh
  { 938,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #938 = HEXAGON_S2_vsatwuh_nopack
  { 939,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #939 = HEXAGON_S2_vsplatrb
  { 940,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #940 = HEXAGON_S2_vsplatrh
  { 941,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #941 = HEXAGON_S2_vsxtbh
  { 942,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #942 = HEXAGON_S2_vsxthw
  { 943,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #943 = HEXAGON_S2_vtrunehb
  { 944,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #944 = HEXAGON_S2_vtrunewh
  { 945,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #945 = HEXAGON_S2_vtrunohb
  { 946,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #946 = HEXAGON_S2_vtrunowh
  { 947,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #947 = HEXAGON_S2_vzxtbh
  { 948,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #948 = HEXAGON_S2_vzxthw
  { 949,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #949 = HEXAGON_S4_or_andi
  { 950,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #950 = HEXAGON_S4_or_andix
  { 951,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #951 = HEXAGON_S4_or_ori
  { 952,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo62,0,0 },  // Inst #952 = HEXAGON_S5_asrhub_rnd_sat_goodsyntax
  { 953,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo62,0,0 },  // Inst #953 = HEXAGON_S5_asrhub_sat
  { 954,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #954 = HEXAGON_S5_popcountp
  { 955,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo30,0,0 },  // Inst #955 = HEXAGON_S5_vasrhrnd_goodsyntax
  { 956,	6,	2,	11,	4,	0|(1<<MCID::MayLoad), 0x1e0000005ULL, NULL, NULL, OperandInfo68,0,0 },  // Inst #956 = HEXAGON_circ_ldd
  { 957,	2,	1,	3,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable), 0x1e0000001ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #957 = HI
  { 958,	2,	1,	3,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable), 0x1e0000001ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #958 = HI_jt
  { 959,	2,	1,	3,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable), 0x1e0000001ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #959 = HI_label
  { 960,	2,	1,	3,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable), 0x1e0000001ULL, NULL, NULL, OperandInfo42,0,0 },  // Inst #960 = HIi
  { 961,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #961 = Hexagon_A2_addpsat
  { 962,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo69,0,0 },  // Inst #962 = Hexagon_A2_addsp
  { 963,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #963 = Hexagon_A2_maxp
  { 964,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #964 = Hexagon_A2_maxup
  { 965,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #965 = Hexagon_A4_andn
  { 966,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo38,0,0 },  // Inst #966 = Hexagon_A4_combineir
  { 967,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo39,0,0 },  // Inst #967 = Hexagon_A4_combineri
  { 968,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #968 = Hexagon_A4_orn
  { 969,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #969 = Hexagon_A4_rcmpeq
  { 970,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #970 = Hexagon_A4_rcmpeqi
  { 971,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #971 = Hexagon_A4_rcmpneq
  { 972,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #972 = Hexagon_A4_rcmpneqi
  { 973,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #973 = Hexagon_C2_bitsclr
  { 974,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #974 = Hexagon_C2_bitsclri
  { 975,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #975 = Hexagon_C2_bitsset
  { 976,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo70,0,0 },  // Inst #976 = Hexagon_C4_and_and
  { 977,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo70,0,0 },  // Inst #977 = Hexagon_C4_and_andn
  { 978,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo70,0,0 },  // Inst #978 = Hexagon_C4_and_or
  { 979,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo70,0,0 },  // Inst #979 = Hexagon_C4_and_orn
  { 980,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #980 = Hexagon_C4_cmplte
  { 981,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #981 = Hexagon_C4_cmpltei
  { 982,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #982 = Hexagon_C4_cmplteu
  { 983,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #983 = Hexagon_C4_cmplteui
  { 984,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #984 = Hexagon_C4_cmpneq
  { 985,	3,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #985 = Hexagon_C4_cmpneqi
  { 986,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #986 = Hexagon_C4_fastcorner9
  { 987,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #987 = Hexagon_C4_fastcorner9_not
  { 988,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo70,0,0 },  // Inst #988 = Hexagon_C4_or_and
  { 989,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo70,0,0 },  // Inst #989 = Hexagon_C4_or_andn
  { 990,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo70,0,0 },  // Inst #990 = Hexagon_C4_or_or
  { 991,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo70,0,0 },  // Inst #991 = Hexagon_C4_or_orn
  { 992,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #992 = Hexagon_M2_mpysmi
  { 993,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo51,0,0 },  // Inst #993 = Hexagon_M2_vradduh
  { 994,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #994 = Hexagon_M2_vrcmpys_acc_s1
  { 995,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #995 = Hexagon_M2_vrcmpys_s1
  { 996,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo63,0,0 },  // Inst #996 = Hexagon_M2_vrcmpys_s1rp
  { 997,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #997 = Hexagon_M4_xor_xacc
  { 998,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #998 = Hexagon_S2_brev
  { 999,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #999 = Hexagon_S2_deinterleave
  { 1000,	5,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo71,0,0 },  // Inst #1000 = Hexagon_S2_insert
  { 1001,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo72,0,0 },  // Inst #1001 = Hexagon_S2_insert_rp
  { 1002,	5,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo73,0,0 },  // Inst #1002 = Hexagon_S2_insertp
  { 1003,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #1003 = Hexagon_S2_insertp_rp
  { 1004,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #1004 = Hexagon_S2_interleave
  { 1005,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1005 = Hexagon_S2_lfsp
  { 1006,	5,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo71,0,0 },  // Inst #1006 = Hexagon_S2_tableidxb_goodsyntax
  { 1007,	5,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo71,0,0 },  // Inst #1007 = Hexagon_S2_tableidxd_goodsyntax
  { 1008,	5,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo71,0,0 },  // Inst #1008 = Hexagon_S2_tableidxh_goodsyntax
  { 1009,	5,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo71,0,0 },  // Inst #1009 = Hexagon_S2_tableidxw_goodsyntax
  { 1010,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo66,0,0 },  // Inst #1010 = Hexagon_S2_vspliceib
  { 1011,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo67,0,0 },  // Inst #1011 = Hexagon_S2_vsplicerb
  { 1012,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #1012 = Hexagon_S4_addaddi
  { 1013,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1013 = Hexagon_S4_andnp
  { 1014,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1014 = Hexagon_S4_ornp
  { 1015,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #1015 = Hexagon_S4_subaddi
  { 1016,	1,	0,	13,	4,	0, 0x1e000001eULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #1016 = IMMEXT_b
  { 1017,	1,	0,	13,	4,	0, 0x1e000001eULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #1017 = IMMEXT_c
  { 1018,	1,	0,	13,	4,	0, 0x1e000001eULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #1018 = IMMEXT_g
  { 1019,	1,	0,	13,	4,	0, 0x1e000001eULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #1019 = IMMEXT_i
  { 1020,	1,	0,	8,	4,	0|(1<<MCID::Branch)|(1<<MCID::Barrier)|(1<<MCID::Predicable)|(1<<MCID::Terminator), 0x1f8840004ULL, NULL, ImplicitList8, OperandInfo5,0,0 },  // Inst #1020 = JMP
  { 1021,	1,	0,	9,	4,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::Predicable)|(1<<MCID::Terminator), 0x1e0000003ULL, NULL, ImplicitList8, OperandInfo31,0,0 },  // Inst #1021 = JMPR
  { 1022,	2,	0,	9,	4,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Terminator), 0x1e00000c3ULL, NULL, ImplicitList8, OperandInfo52,0,0 },  // Inst #1022 = JMPR_f
  { 1023,	2,	0,	9,	4,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Terminator), 0x1c00001c3ULL, NULL, ImplicitList8, OperandInfo52,0,0 },  // Inst #1023 = JMPR_fnew_ntV3
  { 1024,	2,	0,	9,	4,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Terminator), 0x1c00001c3ULL, NULL, ImplicitList8, OperandInfo52,0,0 },  // Inst #1024 = JMPR_fnew_tV3
  { 1025,	2,	0,	9,	4,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Terminator), 0x1e0000043ULL, NULL, ImplicitList8, OperandInfo52,0,0 },  // Inst #1025 = JMPR_t
  { 1026,	2,	0,	9,	4,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Terminator), 0x1c0000143ULL, NULL, ImplicitList8, OperandInfo52,0,0 },  // Inst #1026 = JMPR_tnew_ntV3
  { 1027,	2,	0,	9,	4,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Terminator), 0x1c0000143ULL, NULL, ImplicitList8, OperandInfo52,0,0 },  // Inst #1027 = JMPR_tnew_tV3
  { 1028,	2,	0,	8,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1f19400c4ULL, NULL, ImplicitList8, OperandInfo74,0,0 },  // Inst #1028 = JMP_f
  { 1029,	2,	0,	8,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1f19401c4ULL, NULL, ImplicitList8, OperandInfo74,0,0 },  // Inst #1029 = JMP_fnew_nt
  { 1030,	2,	0,	8,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1f19401c4ULL, NULL, ImplicitList8, OperandInfo74,0,0 },  // Inst #1030 = JMP_fnew_t
  { 1031,	2,	0,	8,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1f1940044ULL, NULL, ImplicitList8, OperandInfo74,0,0 },  // Inst #1031 = JMP_t
  { 1032,	2,	0,	8,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1f1940144ULL, NULL, ImplicitList8, OperandInfo74,0,0 },  // Inst #1032 = JMP_tnew_nt
  { 1033,	2,	0,	8,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1f1940144ULL, NULL, ImplicitList8, OperandInfo74,0,0 },  // Inst #1033 = JMP_tnew_t
  { 1034,	1,	0,	9,	4,	0|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::Predicable)|(1<<MCID::Terminator), 0x1e0000003ULL, NULL, ImplicitList8, OperandInfo31,0,0 },  // Inst #1034 = JMPret
  { 1035,	2,	0,	9,	4,	0|(1<<MCID::Return)|(1<<MCID::Terminator), 0x1e00000c3ULL, NULL, ImplicitList8, OperandInfo52,0,0 },  // Inst #1035 = JMPret_f
  { 1036,	2,	0,	9,	4,	0|(1<<MCID::Return)|(1<<MCID::Terminator), 0x1c00001c3ULL, NULL, ImplicitList8, OperandInfo52,0,0 },  // Inst #1036 = JMPret_fnew_ntV3
  { 1037,	2,	0,	9,	4,	0|(1<<MCID::Return)|(1<<MCID::Terminator), 0x1c00001c3ULL, NULL, ImplicitList8, OperandInfo52,0,0 },  // Inst #1037 = JMPret_fnew_tV3
  { 1038,	2,	0,	9,	4,	0|(1<<MCID::Return)|(1<<MCID::Terminator), 0x1e0000043ULL, NULL, ImplicitList8, OperandInfo52,0,0 },  // Inst #1038 = JMPret_t
  { 1039,	2,	0,	9,	4,	0|(1<<MCID::Return)|(1<<MCID::Terminator), 0x1c0000143ULL, NULL, ImplicitList8, OperandInfo52,0,0 },  // Inst #1039 = JMPret_tnew_ntV3
  { 1040,	2,	0,	9,	4,	0|(1<<MCID::Return)|(1<<MCID::Terminator), 0x1c0000143ULL, NULL, ImplicitList8, OperandInfo52,0,0 },  // Inst #1040 = JMPret_tnew_tV3
  { 1041,	2,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x180000005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1041 = LDb_GP_V4
  { 1042,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1802800c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1042 = LDb_GP_cNotPt_V4
  { 1043,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180280045ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1043 = LDb_GP_cPt_V4
  { 1044,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1802801c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1044 = LDb_GP_cdnNotPt_V4
  { 1045,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180280145ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1045 = LDb_GP_cdnPt_V4
  { 1046,	2,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x180000005ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #1046 = LDd_GP_V4
  { 1047,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1802800c5ULL, NULL, NULL, OperandInfo76,0,0 },  // Inst #1047 = LDd_GP_cNotPt_V4
  { 1048,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180280045ULL, NULL, NULL, OperandInfo76,0,0 },  // Inst #1048 = LDd_GP_cPt_V4
  { 1049,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1802801c5ULL, NULL, NULL, OperandInfo76,0,0 },  // Inst #1049 = LDd_GP_cdnNotPt_V4
  { 1050,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180280145ULL, NULL, NULL, OperandInfo76,0,0 },  // Inst #1050 = LDd_GP_cdnPt_V4
  { 1051,	2,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x180000005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1051 = LDh_GP_V4
  { 1052,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1802800c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1052 = LDh_GP_cNotPt_V4
  { 1053,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180280045ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1053 = LDh_GP_cPt_V4
  { 1054,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1802801c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1054 = LDh_GP_cdnNotPt_V4
  { 1055,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180280145ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1055 = LDh_GP_cdnPt_V4
  { 1056,	3,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x17eba40005ULL, NULL, NULL, OperandInfo77,0,0 },  // Inst #1056 = LDrib
  { 1057,	2,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x13e0180005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1057 = LDrib_abs_V4
  { 1058,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x13e02800c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1058 = LDrib_abs_cNotPt_V4
  { 1059,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x13e0280045ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1059 = LDrib_abs_cPt_V4
  { 1060,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x13e02801c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1060 = LDrib_abs_cdnNotPt_V4
  { 1061,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x13e0280145ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1061 = LDrib_abs_cdnPt_V4
  { 1062,	3,	2,	11,	4,	0|(1<<MCID::MayLoad), 0x580280005ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1062 = LDrib_abs_set_V4
  { 1063,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e63400c5ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1063 = LDrib_cNotPt
  { 1064,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e6340045ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1064 = LDrib_cPt
  { 1065,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e63401c5ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1065 = LDrib_cdnNotPt
  { 1066,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e6340145ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1066 = LDrib_cdnPt
  { 1067,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180380005ULL, NULL, NULL, OperandInfo54,0,0 },  // Inst #1067 = LDrib_ind_lo_V4
  { 1068,	3,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x17eba40005ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1068 = LDrib_indexed
  { 1069,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e63400c5ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1069 = LDrib_indexed_cNotPt
  { 1070,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e6340045ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1070 = LDrib_indexed_cPt
  { 1071,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e63401c5ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1071 = LDrib_indexed_cdnNotPt
  { 1072,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e6340145ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1072 = LDrib_indexed_cdnPt
  { 1073,	4,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x1be0000005ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #1073 = LDrib_indexed_shl_V4
  { 1074,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1be00000c5ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1074 = LDrib_indexed_shl_cNotPt_V4
  { 1075,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1be0000045ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1075 = LDrib_indexed_shl_cPt_V4
  { 1076,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1be00001c5ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1076 = LDrib_indexed_shl_cdnNotPt_V4
  { 1077,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1be0000145ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1077 = LDrib_indexed_shl_cdnPt_V4
  { 1078,	3,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x47eea40005ULL, NULL, NULL, OperandInfo80,0,0 },  // Inst #1078 = LDrid
  { 1079,	2,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x43e0180005ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #1079 = LDrid_abs_V4
  { 1080,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x43e02800c5ULL, NULL, NULL, OperandInfo76,0,0 },  // Inst #1080 = LDrid_abs_cNotPt_V4
  { 1081,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x43e0280045ULL, NULL, NULL, OperandInfo76,0,0 },  // Inst #1081 = LDrid_abs_cPt_V4
  { 1082,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x43e02801c5ULL, NULL, NULL, OperandInfo76,0,0 },  // Inst #1082 = LDrid_abs_cdnNotPt_V4
  { 1083,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x43e0280145ULL, NULL, NULL, OperandInfo76,0,0 },  // Inst #1083 = LDrid_abs_cdnPt_V4
  { 1084,	3,	2,	11,	4,	0|(1<<MCID::MayLoad), 0x580280005ULL, NULL, NULL, OperandInfo39,0,0 },  // Inst #1084 = LDrid_abs_set_V4
  { 1085,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x47e93400c5ULL, NULL, NULL, OperandInfo81,0,0 },  // Inst #1085 = LDrid_cNotPt
  { 1086,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x47e9340045ULL, NULL, NULL, OperandInfo81,0,0 },  // Inst #1086 = LDrid_cPt
  { 1087,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x47e93401c5ULL, NULL, NULL, OperandInfo81,0,0 },  // Inst #1087 = LDrid_cdnNotPt
  { 1088,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x47e9340145ULL, NULL, NULL, OperandInfo81,0,0 },  // Inst #1088 = LDrid_cdnPt
  { 1089,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1e0000005ULL, NULL, NULL, OperandInfo80,0,0 },  // Inst #1089 = LDrid_f
  { 1090,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180380005ULL, NULL, NULL, OperandInfo82,0,0 },  // Inst #1090 = LDrid_ind_lo_V4
  { 1091,	3,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x47eea40005ULL, NULL, NULL, OperandInfo39,0,0 },  // Inst #1091 = LDrid_indexed
  { 1092,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x47e93400c5ULL, NULL, NULL, OperandInfo83,0,0 },  // Inst #1092 = LDrid_indexed_cNotPt
  { 1093,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x47e9340045ULL, NULL, NULL, OperandInfo83,0,0 },  // Inst #1093 = LDrid_indexed_cPt
  { 1094,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x47e93401c5ULL, NULL, NULL, OperandInfo83,0,0 },  // Inst #1094 = LDrid_indexed_cdnNotPt
  { 1095,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x47e9340145ULL, NULL, NULL, OperandInfo83,0,0 },  // Inst #1095 = LDrid_indexed_cdnPt
  { 1096,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1e0000005ULL, NULL, NULL, OperandInfo39,0,0 },  // Inst #1096 = LDrid_indexed_f
  { 1097,	4,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x4be0000005ULL, NULL, NULL, OperandInfo84,0,0 },  // Inst #1097 = LDrid_indexed_shl_V4
  { 1098,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x4be00000c5ULL, NULL, NULL, OperandInfo85,0,0 },  // Inst #1098 = LDrid_indexed_shl_cNotPt_V4
  { 1099,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x4be0000045ULL, NULL, NULL, OperandInfo85,0,0 },  // Inst #1099 = LDrid_indexed_shl_cPt_V4
  { 1100,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x4be00001c5ULL, NULL, NULL, OperandInfo85,0,0 },  // Inst #1100 = LDrid_indexed_shl_cdnNotPt_V4
  { 1101,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x4be0000145ULL, NULL, NULL, OperandInfo85,0,0 },  // Inst #1101 = LDrid_indexed_shl_cdnPt_V4
  { 1102,	3,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x27eca40005ULL, NULL, NULL, OperandInfo77,0,0 },  // Inst #1102 = LDrih
  { 1103,	2,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x23e0180005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1103 = LDrih_abs_V4
  { 1104,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x23e02800c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1104 = LDrih_abs_cNotPt_V4
  { 1105,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x23e0280045ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1105 = LDrih_abs_cPt_V4
  { 1106,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x23e02801c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1106 = LDrih_abs_cdnNotPt_V4
  { 1107,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x23e0280145ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1107 = LDrih_abs_cdnPt_V4
  { 1108,	3,	2,	11,	4,	0|(1<<MCID::MayLoad), 0x580280005ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1108 = LDrih_abs_set_V4
  { 1109,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e73400c5ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1109 = LDrih_cNotPt
  { 1110,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e7340045ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1110 = LDrih_cPt
  { 1111,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e73401c5ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1111 = LDrih_cdnNotPt
  { 1112,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e7340145ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1112 = LDrih_cdnPt
  { 1113,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180380005ULL, NULL, NULL, OperandInfo54,0,0 },  // Inst #1113 = LDrih_ind_lo_V4
  { 1114,	3,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x27eca40005ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1114 = LDrih_indexed
  { 1115,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e73400c5ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1115 = LDrih_indexed_cNotPt
  { 1116,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e7340045ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1116 = LDrih_indexed_cPt
  { 1117,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e73401c5ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1117 = LDrih_indexed_cdnNotPt
  { 1118,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e7340145ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1118 = LDrih_indexed_cdnPt
  { 1119,	4,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x2be0000005ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #1119 = LDrih_indexed_shl_V4
  { 1120,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x2be00000c5ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1120 = LDrih_indexed_shl_cNotPt_V4
  { 1121,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x2be0000045ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1121 = LDrih_indexed_shl_cPt_V4
  { 1122,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x2be00001c5ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1122 = LDrih_indexed_shl_cdnNotPt_V4
  { 1123,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x2be0000145ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1123 = LDrih_indexed_shl_cdnPt_V4
  { 1124,	3,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x17eba40005ULL, NULL, NULL, OperandInfo77,0,0 },  // Inst #1124 = LDriub
  { 1125,	2,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x13e0180005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1125 = LDriub_abs_V4
  { 1126,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x13e02800c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1126 = LDriub_abs_cNotPt_V4
  { 1127,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x13e0280045ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1127 = LDriub_abs_cPt_V4
  { 1128,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x13e02801c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1128 = LDriub_abs_cdnNotPt_V4
  { 1129,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x13e0280145ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1129 = LDriub_abs_cdnPt_V4
  { 1130,	3,	2,	11,	4,	0|(1<<MCID::MayLoad), 0x580280005ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1130 = LDriub_abs_set_V4
  { 1131,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e63400c5ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1131 = LDriub_cNotPt
  { 1132,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e6340045ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1132 = LDriub_cPt
  { 1133,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e63401c5ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1133 = LDriub_cdnNotPt
  { 1134,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e6340145ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1134 = LDriub_cdnPt
  { 1135,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180380005ULL, NULL, NULL, OperandInfo54,0,0 },  // Inst #1135 = LDriub_ind_anyext_lo_V4
  { 1136,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180380005ULL, NULL, NULL, OperandInfo54,0,0 },  // Inst #1136 = LDriub_ind_lo_V4
  { 1137,	3,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x17eba40005ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1137 = LDriub_indexed
  { 1138,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e63400c5ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1138 = LDriub_indexed_cNotPt
  { 1139,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e6340045ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1139 = LDriub_indexed_cPt
  { 1140,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e63401c5ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1140 = LDriub_indexed_cdnNotPt
  { 1141,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x17e6340145ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1141 = LDriub_indexed_cdnPt
  { 1142,	4,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x1be0000005ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #1142 = LDriub_indexed_shl_V4
  { 1143,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1be00000c5ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1143 = LDriub_indexed_shl_cNotPt_V4
  { 1144,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1be0000045ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1144 = LDriub_indexed_shl_cPt_V4
  { 1145,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1be00001c5ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1145 = LDriub_indexed_shl_cdnNotPt_V4
  { 1146,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1be0000145ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1146 = LDriub_indexed_shl_cdnPt_V4
  { 1147,	3,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x27eca40005ULL, NULL, NULL, OperandInfo77,0,0 },  // Inst #1147 = LDriuh
  { 1148,	2,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x23e0180005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1148 = LDriuh_abs_V4
  { 1149,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x23e02800c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1149 = LDriuh_abs_cNotPt_V4
  { 1150,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x23e0280045ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1150 = LDriuh_abs_cPt_V4
  { 1151,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x23e02801c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1151 = LDriuh_abs_cdnNotPt_V4
  { 1152,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x23e0280145ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1152 = LDriuh_abs_cdnPt_V4
  { 1153,	3,	2,	11,	4,	0|(1<<MCID::MayLoad), 0x580280005ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1153 = LDriuh_abs_set_V4
  { 1154,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e73400c5ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1154 = LDriuh_cNotPt
  { 1155,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e7340045ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1155 = LDriuh_cPt
  { 1156,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e73401c5ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1156 = LDriuh_cdnNotPt
  { 1157,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e7340145ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1157 = LDriuh_cdnPt
  { 1158,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180380005ULL, NULL, NULL, OperandInfo54,0,0 },  // Inst #1158 = LDriuh_ind_anyext_lo_V4
  { 1159,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180380005ULL, NULL, NULL, OperandInfo54,0,0 },  // Inst #1159 = LDriuh_ind_lo_V4
  { 1160,	3,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x27eca40005ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1160 = LDriuh_indexed
  { 1161,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e73400c5ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1161 = LDriuh_indexed_cNotPt
  { 1162,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e7340045ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1162 = LDriuh_indexed_cPt
  { 1163,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e73401c5ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1163 = LDriuh_indexed_cdnNotPt
  { 1164,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x27e7340145ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1164 = LDriuh_indexed_cdnPt
  { 1165,	4,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x2be0000005ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #1165 = LDriuh_indexed_shl_V4
  { 1166,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x2be00000c5ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1166 = LDriuh_indexed_shl_cNotPt_V4
  { 1167,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x2be0000045ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1167 = LDriuh_indexed_shl_cPt_V4
  { 1168,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x2be00001c5ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1168 = LDriuh_indexed_shl_cdnNotPt_V4
  { 1169,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x2be0000145ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1169 = LDriuh_indexed_shl_cdnPt_V4
  { 1170,	3,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x37eda40005ULL, NULL, NULL, OperandInfo77,0,0 },  // Inst #1170 = LDriw
  { 1171,	2,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x33e0180005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1171 = LDriw_abs_V4
  { 1172,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x33e02800c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1172 = LDriw_abs_cNotPt_V4
  { 1173,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x33e0280045ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1173 = LDriw_abs_cPt_V4
  { 1174,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x33e02801c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1174 = LDriw_abs_cdnNotPt_V4
  { 1175,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x33e0280145ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1175 = LDriw_abs_cdnPt_V4
  { 1176,	3,	2,	11,	4,	0|(1<<MCID::MayLoad), 0x580280005ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1176 = LDriw_abs_set_V4
  { 1177,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x37e83400c5ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1177 = LDriw_cNotPt
  { 1178,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x37e8340045ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1178 = LDriw_cPt
  { 1179,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x37e83401c5ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1179 = LDriw_cdnNotPt
  { 1180,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x37e8340145ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #1180 = LDriw_cdnPt
  { 1181,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1e0000005ULL, NULL, NULL, OperandInfo77,0,0 },  // Inst #1181 = LDriw_f
  { 1182,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180380005ULL, NULL, NULL, OperandInfo54,0,0 },  // Inst #1182 = LDriw_ind_lo_V4
  { 1183,	3,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x37eda40005ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1183 = LDriw_indexed
  { 1184,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x37e83400c5ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1184 = LDriw_indexed_cNotPt
  { 1185,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x37e8340045ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1185 = LDriw_indexed_cPt
  { 1186,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x37e83401c5ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1186 = LDriw_indexed_cdnNotPt
  { 1187,	4,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x37e8340145ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1187 = LDriw_indexed_cdnPt
  { 1188,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1e0000005ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1188 = LDriw_indexed_f
  { 1189,	4,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x3be0000005ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #1189 = LDriw_indexed_shl_V4
  { 1190,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x3be00000c5ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1190 = LDriw_indexed_shl_cNotPt_V4
  { 1191,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x3be0000045ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1191 = LDriw_indexed_shl_cPt_V4
  { 1192,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x3be00001c5ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1192 = LDriw_indexed_shl_cdnNotPt_V4
  { 1193,	5,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x3be0000145ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #1193 = LDriw_indexed_shl_cdnPt_V4
  { 1194,	3,	1,	11,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad), 0x1eda40005ULL, NULL, ImplicitList14, OperandInfo86,0,0 },  // Inst #1194 = LDriw_pred
  { 1195,	2,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x180000005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1195 = LDub_GP_V4
  { 1196,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1802800c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1196 = LDub_GP_cNotPt_V4
  { 1197,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180280045ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1197 = LDub_GP_cPt_V4
  { 1198,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1802801c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1198 = LDub_GP_cdnNotPt_V4
  { 1199,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180280145ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1199 = LDub_GP_cdnPt_V4
  { 1200,	2,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x180000005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1200 = LDuh_GP_V4
  { 1201,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1802800c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1201 = LDuh_GP_cNotPt_V4
  { 1202,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180280045ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1202 = LDuh_GP_cPt_V4
  { 1203,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1802801c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1203 = LDuh_GP_cdnNotPt_V4
  { 1204,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180280145ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1204 = LDuh_GP_cdnPt_V4
  { 1205,	2,	1,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0x180000005ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1205 = LDw_GP_V4
  { 1206,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1802800c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1206 = LDw_GP_cNotPt_V4
  { 1207,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180280045ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1207 = LDw_GP_cPt_V4
  { 1208,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x1802801c5ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1208 = LDw_GP_cdnNotPt_V4
  { 1209,	3,	1,	11,	4,	0|(1<<MCID::MayLoad), 0x180280145ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1209 = LDw_GP_cdnPt_V4
  { 1210,	2,	1,	3,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable), 0x1e0000001ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1210 = LO
  { 1211,	2,	0,	14,	4,	0, 0x1e0000002ULL, NULL, ImplicitList12, OperandInfo7,0,0 },  // Inst #1211 = LOOP0_i
  { 1212,	2,	0,	14,	4,	0, 0x1e0000002ULL, NULL, ImplicitList12, OperandInfo87,0,0 },  // Inst #1212 = LOOP0_r
  { 1213,	2,	1,	3,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable), 0x1e0000001ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1213 = LO_jt
  { 1214,	2,	1,	3,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable), 0x1e0000001ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1214 = LO_label
  { 1215,	2,	1,	3,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable), 0x1e0000001ULL, NULL, NULL, OperandInfo42,0,0 },  // Inst #1215 = LOi
  { 1216,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1216 = LSL_ADD_rr
  { 1217,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #1217 = LSL_ADDd_rr
  { 1218,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1218 = LSL_AND_rr
  { 1219,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #1219 = LSL_ANDd_rr
  { 1220,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1220 = LSL_OR_rr
  { 1221,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #1221 = LSL_ORd_rr
  { 1222,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1222 = LSL_SUB_rr
  { 1223,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #1223 = LSL_SUBd_rr
  { 1224,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1224 = LSL_rr
  { 1225,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #1225 = LSLd
  { 1226,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #1226 = LSLd_rr_xor_V4
  { 1227,	3,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1227 = LSLi_V4
  { 1228,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #1228 = LSR_ADD_ri
  { 1229,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1229 = LSR_ADD_rr
  { 1230,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #1230 = LSR_ADDd_ri
  { 1231,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #1231 = LSR_ADDd_rr
  { 1232,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #1232 = LSR_AND_ri
  { 1233,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1233 = LSR_AND_rr
  { 1234,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #1234 = LSR_ANDd_ri
  { 1235,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #1235 = LSR_ANDd_rr
  { 1236,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #1236 = LSR_OR_ri
  { 1237,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1237 = LSR_OR_rr
  { 1238,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #1238 = LSR_ORd_ri
  { 1239,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #1239 = LSR_ORd_rr
  { 1240,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #1240 = LSR_SUB_ri
  { 1241,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1241 = LSR_SUB_rr
  { 1242,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #1242 = LSR_SUBd_ri
  { 1243,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #1243 = LSR_SUBd_rr
  { 1244,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #1244 = LSR_XOR_ri
  { 1245,	4,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo27,0,0 },  // Inst #1245 = LSR_XORd_ri
  { 1246,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1246 = LSR_ri
  { 1247,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1247 = LSR_rr
  { 1248,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo30,0,0 },  // Inst #1248 = LSRd_ri
  { 1249,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #1249 = LSRd_rr
  { 1250,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #1250 = LSRd_rr_xor_V4
  { 1251,	2,	1,	2,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1e0000008ULL, NULL, NULL, OperandInfo88,0,0 },  // Inst #1251 = MASK_p
  { 1252,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1252 = MAXUd_rr
  { 1253,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1253 = MAXUw_rr
  { 1254,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1254 = MAXd_rr
  { 1255,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1255 = MAXw_dd
  { 1256,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1256 = MAXw_rr
  { 1257,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1257 = MINUd_rr
  { 1258,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1258 = MINUw_rr
  { 1259,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1259 = MINd_rr
  { 1260,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1260 = MINw_dd
  { 1261,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1261 = MINw_rr
  { 1262,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1262 = MPY
  { 1263,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #1263 = MPY64
  { 1264,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #1264 = MPY64_acc
  { 1265,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #1265 = MPY64_sub
  { 1266,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1266 = MPYI
  { 1267,	4,	1,	4,	4,	0, 0x1e8340008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #1267 = MPYI_acc_ri
  { 1268,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1268 = MPYI_acc_rr
  { 1269,	3,	1,	4,	4,	0, 0x1e9a40008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1269 = MPYI_ri
  { 1270,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1270 = MPYI_rin
  { 1271,	3,	1,	4,	4,	0, 0x1e8240008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1271 = MPYI_riu
  { 1272,	4,	1,	4,	4,	0, 0x1e8340008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #1272 = MPYI_sub_ri
  { 1273,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1273 = MPYU
  { 1274,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo40,0,0 },  // Inst #1274 = MPYU64
  { 1275,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #1275 = MPYU64_acc
  { 1276,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #1276 = MPYU64_sub
  { 1277,	3,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1277 = MPY_trsext
  { 1278,	4,	1,	3,	4,	0, 0x1e8a40001ULL, NULL, NULL, OperandInfo89,0,0 },  // Inst #1278 = MUX_ii
  { 1279,	4,	1,	3,	4,	0, 0x1e8a40001ULL, NULL, NULL, OperandInfo90,0,0 },  // Inst #1279 = MUX_ir
  { 1280,	4,	1,	3,	4,	0, 0x1e8b40001ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1280 = MUX_ri
  { 1281,	4,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1281 = MUX_rr
  { 1282,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x1186140009ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1282 = MemOPb_ADDi_V4
  { 1283,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x1186140009ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1283 = MemOPb_ADDr_V4
  { 1284,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x1186140009ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1284 = MemOPb_ANDr_V4
  { 1285,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x1186140009ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1285 = MemOPb_CLRBITi_V4
  { 1286,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x1186140009ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1286 = MemOPb_ORr_V4
  { 1287,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x1186140009ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1287 = MemOPb_SETBITi_V4
  { 1288,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x1186140009ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1288 = MemOPb_SUBi_V4
  { 1289,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x1186140009ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1289 = MemOPb_SUBr_V4
  { 1290,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x2187140009ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1290 = MemOPh_ADDi_V4
  { 1291,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x2187140009ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1291 = MemOPh_ADDr_V4
  { 1292,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x2187140009ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1292 = MemOPh_ANDr_V4
  { 1293,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x2187140009ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1293 = MemOPh_CLRBITi_V4
  { 1294,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x2187140009ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1294 = MemOPh_ORr_V4
  { 1295,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x2187140009ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1295 = MemOPh_SETBITi_V4
  { 1296,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x2187140009ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1296 = MemOPh_SUBi_V4
  { 1297,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x2187140009ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1297 = MemOPh_SUBr_V4
  { 1298,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x3188140009ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1298 = MemOPw_ADDi_V4
  { 1299,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x3188140009ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1299 = MemOPw_ADDr_V4
  { 1300,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x3188140009ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1300 = MemOPw_ANDr_V4
  { 1301,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x3188140009ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1301 = MemOPw_CLRBITi_V4
  { 1302,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x3188140009ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1302 = MemOPw_ORr_V4
  { 1303,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x3188140009ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1303 = MemOPw_SETBITi_V4
  { 1304,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x3188140009ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1304 = MemOPw_SUBi_V4
  { 1305,	3,	0,	15,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x3188140009ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1305 = MemOPw_SUBr_V4
  { 1306,	0,	0,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, 0,0,0 },  // Inst #1306 = NOP
  { 1307,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #1307 = NOT_p
  { 1308,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #1308 = NOT_rr64
  { 1309,	3,	1,	2,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #1309 = NTSTBIT_ri
  { 1310,	3,	1,	2,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #1310 = NTSTBIT_rr
  { 1311,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo24,0,0 },  // Inst #1311 = OR_pp
  { 1312,	3,	1,	3,	4,	0, 0x1eaa40001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1312 = OR_ri
  { 1313,	3,	1,	3,	4,	0|(1<<MCID::Predicable)|(1<<MCID::Commutable), 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1313 = OR_rr
  { 1314,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1314 = OR_rr64
  { 1315,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e00000c1ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1315 = OR_rr_cNotPt
  { 1316,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e0000041ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1316 = OR_rr_cPt
  { 1317,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e00001c1ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1317 = OR_rr_cdnNotPt
  { 1318,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e0000141ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1318 = OR_rr_cdnPt
  { 1319,	3,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1319 = ORd_NOTd_V4
  { 1320,	4,	1,	4,	4,	0, 0x188140008ULL, NULL, NULL, OperandInfo16,0,0 },  // Inst #1320 = ORi_ASLri_V4
  { 1321,	4,	1,	4,	4,	0, 0x188140008ULL, NULL, NULL, OperandInfo16,0,0 },  // Inst #1321 = ORi_LSRri_V4
  { 1322,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1322 = ORr_ANDr_NOTr_V4
  { 1323,	4,	1,	4,	4,	0, 0x18ab40008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #1323 = ORr_ANDri2_V4
  { 1324,	4,	1,	4,	4,	0, 0x18ab40008ULL, NULL, NULL, OperandInfo91,0,0 },  // Inst #1324 = ORr_ANDri_V4
  { 1325,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1325 = ORr_ANDrr_V4
  { 1326,	4,	1,	4,	4,	0, 0x18ab40008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #1326 = ORr_ORri_V4
  { 1327,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1327 = ORr_ORrr_V4
  { 1328,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1328 = ORr_XORrr_V4
  { 1329,	4,	2,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0xde0000005ULL, NULL, NULL, OperandInfo92,0,0 },  // Inst #1329 = POST_LDrib
  { 1330,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xde00000c5ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1330 = POST_LDrib_cNotPt
  { 1331,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xde0000045ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1331 = POST_LDrib_cPt
  { 1332,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xd800001c5ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1332 = POST_LDrib_cdnNotPt_V4
  { 1333,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xd80000145ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1333 = POST_LDrib_cdnPt_V4
  { 1334,	4,	2,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0xde0000005ULL, NULL, NULL, OperandInfo94,0,0 },  // Inst #1334 = POST_LDrid
  { 1335,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xde00000c5ULL, NULL, NULL, OperandInfo95,0,0 },  // Inst #1335 = POST_LDrid_cNotPt
  { 1336,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xde0000045ULL, NULL, NULL, OperandInfo95,0,0 },  // Inst #1336 = POST_LDrid_cPt
  { 1337,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xd800001c5ULL, NULL, NULL, OperandInfo95,0,0 },  // Inst #1337 = POST_LDrid_cdnNotPt_V4
  { 1338,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xd80000145ULL, NULL, NULL, OperandInfo95,0,0 },  // Inst #1338 = POST_LDrid_cdnPt_V4
  { 1339,	4,	2,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0xde0000005ULL, NULL, NULL, OperandInfo92,0,0 },  // Inst #1339 = POST_LDrih
  { 1340,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xde00000c5ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1340 = POST_LDrih_cNotPt
  { 1341,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xde0000045ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1341 = POST_LDrih_cPt
  { 1342,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xd800001c5ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1342 = POST_LDrih_cdnNotPt_V4
  { 1343,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xd80000145ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1343 = POST_LDrih_cdnPt_V4
  { 1344,	4,	2,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0xde0000005ULL, NULL, NULL, OperandInfo92,0,0 },  // Inst #1344 = POST_LDriub
  { 1345,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xde00000c5ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1345 = POST_LDriub_cNotPt
  { 1346,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xde0000045ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1346 = POST_LDriub_cPt
  { 1347,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xd800001c5ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1347 = POST_LDriub_cdnNotPt_V4
  { 1348,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xd80000145ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1348 = POST_LDriub_cdnPt_V4
  { 1349,	4,	2,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0xde0000005ULL, NULL, NULL, OperandInfo92,0,0 },  // Inst #1349 = POST_LDriuh
  { 1350,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xde00000c5ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1350 = POST_LDriuh_cNotPt
  { 1351,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xde0000045ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1351 = POST_LDriuh_cPt
  { 1352,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xd800001c5ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1352 = POST_LDriuh_cdnNotPt_V4
  { 1353,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xd80000145ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1353 = POST_LDriuh_cdnPt_V4
  { 1354,	4,	2,	11,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::Predicable), 0xde0000005ULL, NULL, NULL, OperandInfo92,0,0 },  // Inst #1354 = POST_LDriw
  { 1355,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xde00000c5ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1355 = POST_LDriw_cNotPt
  { 1356,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xde0000045ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1356 = POST_LDriw_cPt
  { 1357,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xd800001c5ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1357 = POST_LDriw_cdnNotPt_V4
  { 1358,	5,	2,	11,	4,	0|(1<<MCID::MayLoad), 0xd80000145ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #1358 = POST_LDriw_cdnPt_V4
  { 1359,	4,	1,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x1e0010006ULL, NULL, NULL, OperandInfo96,0,0 },  // Inst #1359 = POST_STbri
  { 1360,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x1e00100c6ULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1360 = POST_STbri_cNotPt
  { 1361,	5,	1,	10,	4,	0|(1<<MCID::MayStore), 0xd800200caULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1361 = POST_STbri_cNotPt_nv_V4
  { 1362,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x1e0010046ULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1362 = POST_STbri_cPt
  { 1363,	5,	1,	10,	4,	0|(1<<MCID::MayStore), 0xd8002004aULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1363 = POST_STbri_cPt_nv_V4
  { 1364,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x1800101c6ULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1364 = POST_STbri_cdnNotPt_V4
  { 1365,	5,	1,	10,	4,	0|(1<<MCID::MayStore), 0xd800201caULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1365 = POST_STbri_cdnNotPt_nv_V4
  { 1366,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x180010146ULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1366 = POST_STbri_cdnPt_V4
  { 1367,	5,	1,	10,	4,	0|(1<<MCID::MayStore), 0xd8002014aULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1367 = POST_STbri_cdnPt_nv_V4
  { 1368,	4,	1,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0xd8002000aULL, NULL, NULL, OperandInfo96,0,0 },  // Inst #1368 = POST_STbri_nv_V4
  { 1369,	4,	1,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x1e0000006ULL, NULL, NULL, OperandInfo98,0,0 },  // Inst #1369 = POST_STdri
  { 1370,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x1e00000c6ULL, NULL, NULL, OperandInfo99,0,0 },  // Inst #1370 = POST_STdri_cNotPt
  { 1371,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x1e0000046ULL, NULL, NULL, OperandInfo99,0,0 },  // Inst #1371 = POST_STdri_cPt
  { 1372,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x1800001c6ULL, NULL, NULL, OperandInfo99,0,0 },  // Inst #1372 = POST_STdri_cdnNotPt_V4
  { 1373,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x180000146ULL, NULL, NULL, OperandInfo99,0,0 },  // Inst #1373 = POST_STdri_cdnPt_V4
  { 1374,	4,	1,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x1e0010006ULL, NULL, NULL, OperandInfo96,0,0 },  // Inst #1374 = POST_SThri
  { 1375,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x1e00100c6ULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1375 = POST_SThri_cNotPt
  { 1376,	5,	1,	10,	4,	0|(1<<MCID::MayStore), 0xd800200caULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1376 = POST_SThri_cNotPt_nv_V4
  { 1377,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x1e0010046ULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1377 = POST_SThri_cPt
  { 1378,	5,	1,	10,	4,	0|(1<<MCID::MayStore), 0xd8002004aULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1378 = POST_SThri_cPt_nv_V4
  { 1379,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x1800101c6ULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1379 = POST_SThri_cdnNotPt_V4
  { 1380,	5,	1,	10,	4,	0|(1<<MCID::MayStore), 0xd800201caULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1380 = POST_SThri_cdnNotPt_nv_V4
  { 1381,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x180010146ULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1381 = POST_SThri_cdnPt_V4
  { 1382,	5,	1,	10,	4,	0|(1<<MCID::MayStore), 0xd8002014aULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1382 = POST_SThri_cdnPt_nv_V4
  { 1383,	4,	1,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0xd8002000aULL, NULL, NULL, OperandInfo96,0,0 },  // Inst #1383 = POST_SThri_nv_V4
  { 1384,	4,	1,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x1e0010006ULL, NULL, NULL, OperandInfo96,0,0 },  // Inst #1384 = POST_STwri
  { 1385,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x1e00100c6ULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1385 = POST_STwri_cNotPt
  { 1386,	5,	1,	10,	4,	0|(1<<MCID::MayStore), 0xd800200caULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1386 = POST_STwri_cNotPt_nv_V4
  { 1387,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x1e0010046ULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1387 = POST_STwri_cPt
  { 1388,	5,	1,	10,	4,	0|(1<<MCID::MayStore), 0xd8002004aULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1388 = POST_STwri_cPt_nv_V4
  { 1389,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x1800101c6ULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1389 = POST_STwri_cdnNotPt_V4
  { 1390,	5,	1,	10,	4,	0|(1<<MCID::MayStore), 0xd800201caULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1390 = POST_STwri_cdnNotPt_nv_V4
  { 1391,	5,	1,	6,	4,	0|(1<<MCID::MayStore), 0x180010146ULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1391 = POST_STwri_cdnPt_V4
  { 1392,	5,	1,	10,	4,	0|(1<<MCID::MayStore), 0xd8002014aULL, NULL, NULL, OperandInfo97,0,0 },  // Inst #1392 = POST_STwri_cdnPt_nv_V4
  { 1393,	4,	1,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0xd8002000aULL, NULL, NULL, OperandInfo96,0,0 },  // Inst #1393 = POST_STwri_nv_V4
  { 1394,	1,	0,	8,	4,	0|(1<<MCID::Barrier)|(1<<MCID::Call)|(1<<MCID::UnmodeledSideEffects), 0x180000004ULL, NULL, ImplicitList10, OperandInfo5,0,0 },  // Inst #1394 = RESTORE_DEALLOC_BEFORE_TAILCALL_V4
  { 1395,	1,	0,	8,	4,	0|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::Call)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x180000004ULL, NULL, ImplicitList10, OperandInfo5,0,0 },  // Inst #1395 = RESTORE_DEALLOC_RET_JMP_V4
  { 1396,	1,	0,	8,	4,	0|(1<<MCID::Barrier)|(1<<MCID::Call)|(1<<MCID::UnmodeledSideEffects), 0x1e0000004ULL, ImplicitList15, NULL, OperandInfo5,0,0 },  // Inst #1396 = SAVE_REGISTERS_CALL_V4
  { 1397,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1397 = SETBIT
  { 1398,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1398 = SETBIT_31
  { 1399,	2,	1,	3,	4,	0, 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #1399 = SI_to_SXTHI_asrh
  { 1400,	2,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x180010006ULL, NULL, NULL, OperandInfo87,0,0 },  // Inst #1400 = STb_GP_V4
  { 1401,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1801900c6ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1401 = STb_GP_cNotPt_V4
  { 1402,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1801a00caULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1402 = STb_GP_cNotPt_nv_V4
  { 1403,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x180190046ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1403 = STb_GP_cPt_V4
  { 1404,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1801a004aULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1404 = STb_GP_cPt_nv_V4
  { 1405,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1801901c6ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1405 = STb_GP_cdnNotPt_V4
  { 1406,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1801a01caULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1406 = STb_GP_cdnNotPt_nv_V4
  { 1407,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x180190146ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1407 = STb_GP_cdnPt_V4
  { 1408,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1801a014aULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1408 = STb_GP_cdnPt_nv_V4
  { 1409,	2,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x18002000aULL, NULL, NULL, OperandInfo87,0,0 },  // Inst #1409 = STb_GP_nv_V4
  { 1410,	2,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x180000006ULL, NULL, NULL, OperandInfo101,0,0 },  // Inst #1410 = STd_GP_V4
  { 1411,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1801800c6ULL, NULL, NULL, OperandInfo102,0,0 },  // Inst #1411 = STd_GP_cNotPt_V4
  { 1412,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x180180046ULL, NULL, NULL, OperandInfo102,0,0 },  // Inst #1412 = STd_GP_cPt_V4
  { 1413,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1801801c6ULL, NULL, NULL, OperandInfo102,0,0 },  // Inst #1413 = STd_GP_cdnNotPt_V4
  { 1414,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x180180146ULL, NULL, NULL, OperandInfo102,0,0 },  // Inst #1414 = STd_GP_cdnPt_V4
  { 1415,	2,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x180010006ULL, NULL, NULL, OperandInfo87,0,0 },  // Inst #1415 = STh_GP_V4
  { 1416,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1801900c6ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1416 = STh_GP_cNotPt_V4
  { 1417,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1801a00caULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1417 = STh_GP_cNotPt_nv_V4
  { 1418,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x180190046ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1418 = STh_GP_cPt_V4
  { 1419,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1801a004aULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1419 = STh_GP_cPt_nv_V4
  { 1420,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1801901c6ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1420 = STh_GP_cdnNotPt_V4
  { 1421,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1801a01caULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1421 = STh_GP_cdnNotPt_nv_V4
  { 1422,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x180190146ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1422 = STh_GP_cdnPt_V4
  { 1423,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1801a014aULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1423 = STh_GP_cdnPt_nv_V4
  { 1424,	2,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x18002000aULL, NULL, NULL, OperandInfo87,0,0 },  // Inst #1424 = STh_GP_nv_V4
  { 1425,	3,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x17eb950006ULL, NULL, NULL, OperandInfo103,0,0 },  // Inst #1425 = STrib
  { 1426,	2,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x13e0090006ULL, NULL, NULL, OperandInfo87,0,0 },  // Inst #1426 = STrib_abs_V4
  { 1427,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x13e01900c6ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1427 = STrib_abs_cNotPt_V4
  { 1428,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x13e01a00caULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1428 = STrib_abs_cNotPt_nv_V4
  { 1429,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x13e0190046ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1429 = STrib_abs_cPt_V4
  { 1430,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x13e01a004aULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1430 = STrib_abs_cPt_nv_V4
  { 1431,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x13e01901c6ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1431 = STrib_abs_cdnNotPt_V4
  { 1432,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x13e01a01caULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1432 = STrib_abs_cdnNotPt_nv_V4
  { 1433,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x13e0190146ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1433 = STrib_abs_cdnPt_V4
  { 1434,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x13e01a014aULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1434 = STrib_abs_cdnPt_nv_V4
  { 1435,	2,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x13e00a000aULL, NULL, NULL, OperandInfo87,0,0 },  // Inst #1435 = STrib_abs_nv_V4
  { 1436,	3,	1,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x580280006ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1436 = STrib_abs_set_V4
  { 1437,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x17e62500c6ULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1437 = STrib_cNotPt
  { 1438,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x17862600caULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1438 = STrib_cNotPt_nv_V4
  { 1439,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x17e6250046ULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1439 = STrib_cPt
  { 1440,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x178626004aULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1440 = STrib_cPt_nv_V4
  { 1441,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x17862501c6ULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1441 = STrib_cdnNotPt_V4
  { 1442,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x17862601caULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1442 = STrib_cdnNotPt_nv_V4
  { 1443,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1786250146ULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1443 = STrib_cdnPt_V4
  { 1444,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x178626014aULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1444 = STrib_cdnPt_nv_V4
  { 1445,	3,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x1788a40006ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1445 = STrib_imm_V4
  { 1446,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1786b400c6ULL, NULL, NULL, OperandInfo105,0,0 },  // Inst #1446 = STrib_imm_cNotPt_V4
  { 1447,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1786b40046ULL, NULL, NULL, OperandInfo105,0,0 },  // Inst #1447 = STrib_imm_cPt_V4
  { 1448,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1786b401c6ULL, NULL, NULL, OperandInfo105,0,0 },  // Inst #1448 = STrib_imm_cdnNotPt_V4
  { 1449,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1786b40146ULL, NULL, NULL, OperandInfo105,0,0 },  // Inst #1449 = STrib_imm_cdnPt_V4
  { 1450,	3,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x17eb950006ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1450 = STrib_indexed
  { 1451,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x17e62500c6ULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1451 = STrib_indexed_cNotPt
  { 1452,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x17862600caULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1452 = STrib_indexed_cNotPt_nv_V4
  { 1453,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x17e6250046ULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1453 = STrib_indexed_cPt
  { 1454,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x178626004aULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1454 = STrib_indexed_cPt_nv_V4
  { 1455,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x17862501c6ULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1455 = STrib_indexed_cdnNotPt_V4
  { 1456,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x17862601caULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1456 = STrib_indexed_cdnNotPt_nv_V4
  { 1457,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1786250146ULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1457 = STrib_indexed_cdnPt_V4
  { 1458,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x178626014aULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1458 = STrib_indexed_cdnPt_nv_V4
  { 1459,	3,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x178b96000aULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1459 = STrib_indexed_nv_V4
  { 1460,	4,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x1b80010006ULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #1460 = STrib_indexed_shl_V4
  { 1461,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1b800100c6ULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1461 = STrib_indexed_shl_cNotPt_V4
  { 1462,	5,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1b800200caULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1462 = STrib_indexed_shl_cNotPt_nv_V4
  { 1463,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1b80010046ULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1463 = STrib_indexed_shl_cPt_V4
  { 1464,	5,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1b8002004aULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1464 = STrib_indexed_shl_cPt_nv_V4
  { 1465,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1b800101c6ULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1465 = STrib_indexed_shl_cdnNotPt_V4
  { 1466,	5,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1b800201caULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1466 = STrib_indexed_shl_cdnNotPt_nv_V4
  { 1467,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1b80010146ULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1467 = STrib_indexed_shl_cdnPt_V4
  { 1468,	5,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1b8002014aULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1468 = STrib_indexed_shl_cdnPt_nv_V4
  { 1469,	4,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x1b8002000aULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #1469 = STrib_indexed_shl_nv_V4
  { 1470,	3,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x178b96000aULL, NULL, NULL, OperandInfo103,0,0 },  // Inst #1470 = STrib_nv_V4
  { 1471,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x180290006ULL, NULL, NULL, OperandInfo108,0,0 },  // Inst #1471 = STrib_shl_V4
  { 1472,	4,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x1802a000aULL, NULL, NULL, OperandInfo108,0,0 },  // Inst #1472 = STrib_shl_nv_V4
  { 1473,	3,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x47ee940006ULL, NULL, NULL, OperandInfo109,0,0 },  // Inst #1473 = STrid
  { 1474,	2,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x43e0080006ULL, NULL, NULL, OperandInfo101,0,0 },  // Inst #1474 = STrid_abs_V4
  { 1475,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x43e01800c6ULL, NULL, NULL, OperandInfo102,0,0 },  // Inst #1475 = STrid_abs_cNotPt_V4
  { 1476,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x43e0180046ULL, NULL, NULL, OperandInfo102,0,0 },  // Inst #1476 = STrid_abs_cPt_V4
  { 1477,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x43e01801c6ULL, NULL, NULL, OperandInfo102,0,0 },  // Inst #1477 = STrid_abs_cdnNotPt_V4
  { 1478,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x43e0180146ULL, NULL, NULL, OperandInfo102,0,0 },  // Inst #1478 = STrid_abs_cdnPt_V4
  { 1479,	3,	1,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x580280006ULL, NULL, NULL, OperandInfo62,0,0 },  // Inst #1479 = STrid_abs_set_V4
  { 1480,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x47e92400c6ULL, NULL, NULL, OperandInfo110,0,0 },  // Inst #1480 = STrid_cNotPt
  { 1481,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x47e9240046ULL, NULL, NULL, OperandInfo110,0,0 },  // Inst #1481 = STrid_cPt
  { 1482,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x47892401c6ULL, NULL, NULL, OperandInfo110,0,0 },  // Inst #1482 = STrid_cdnNotPt_V4
  { 1483,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x4789240146ULL, NULL, NULL, OperandInfo110,0,0 },  // Inst #1483 = STrid_cdnPt_V4
  { 1484,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1e0000006ULL, NULL, NULL, OperandInfo109,0,0 },  // Inst #1484 = STrid_f
  { 1485,	3,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x47ee940006ULL, NULL, NULL, OperandInfo111,0,0 },  // Inst #1485 = STrid_indexed
  { 1486,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x47e92400c6ULL, NULL, NULL, OperandInfo112,0,0 },  // Inst #1486 = STrid_indexed_cNotPt
  { 1487,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x47e9240046ULL, NULL, NULL, OperandInfo112,0,0 },  // Inst #1487 = STrid_indexed_cPt
  { 1488,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x47892401c6ULL, NULL, NULL, OperandInfo112,0,0 },  // Inst #1488 = STrid_indexed_cdnNotPt_V4
  { 1489,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x4789240146ULL, NULL, NULL, OperandInfo112,0,0 },  // Inst #1489 = STrid_indexed_cdnPt_V4
  { 1490,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1e0000006ULL, NULL, NULL, OperandInfo111,0,0 },  // Inst #1490 = STrid_indexed_f
  { 1491,	4,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x4b80000006ULL, NULL, NULL, OperandInfo113,0,0 },  // Inst #1491 = STrid_indexed_shl_V4
  { 1492,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x4b800000c6ULL, NULL, NULL, OperandInfo114,0,0 },  // Inst #1492 = STrid_indexed_shl_cNotPt_V4
  { 1493,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x4b80000046ULL, NULL, NULL, OperandInfo114,0,0 },  // Inst #1493 = STrid_indexed_shl_cPt_V4
  { 1494,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x4b800001c6ULL, NULL, NULL, OperandInfo114,0,0 },  // Inst #1494 = STrid_indexed_shl_cdnNotPt_V4
  { 1495,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x4b80000146ULL, NULL, NULL, OperandInfo114,0,0 },  // Inst #1495 = STrid_indexed_shl_cdnPt_V4
  { 1496,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x180280006ULL, NULL, NULL, OperandInfo115,0,0 },  // Inst #1496 = STrid_shl_V4
  { 1497,	3,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x27ec950006ULL, NULL, NULL, OperandInfo103,0,0 },  // Inst #1497 = STrih
  { 1498,	2,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x23e0090006ULL, NULL, NULL, OperandInfo87,0,0 },  // Inst #1498 = STrih_abs_V4
  { 1499,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x23e01900c6ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1499 = STrih_abs_cNotPt_V4
  { 1500,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x23e01a00caULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1500 = STrih_abs_cNotPt_nv_V4
  { 1501,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x23e0190046ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1501 = STrih_abs_cPt_V4
  { 1502,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x23e01a004aULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1502 = STrih_abs_cPt_nv_V4
  { 1503,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x23e01901c6ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1503 = STrih_abs_cdnNotPt_V4
  { 1504,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x23e01a01caULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1504 = STrih_abs_cdnNotPt_nv_V4
  { 1505,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x23e0190146ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1505 = STrih_abs_cdnPt_V4
  { 1506,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x23e01a014aULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1506 = STrih_abs_cdnPt_nv_V4
  { 1507,	2,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x23e00a000aULL, NULL, NULL, OperandInfo87,0,0 },  // Inst #1507 = STrih_abs_nv_V4
  { 1508,	3,	1,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x580280006ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1508 = STrih_abs_set_V4
  { 1509,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x27e72500c6ULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1509 = STrih_cNotPt
  { 1510,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x27872600caULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1510 = STrih_cNotPt_nv_V4
  { 1511,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x27e7250046ULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1511 = STrih_cPt
  { 1512,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x278726004aULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1512 = STrih_cPt_nv_V4
  { 1513,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x27872501c6ULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1513 = STrih_cdnNotPt_V4
  { 1514,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x27872601caULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1514 = STrih_cdnNotPt_nv_V4
  { 1515,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x2787250146ULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1515 = STrih_cdnPt_V4
  { 1516,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x278726014aULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1516 = STrih_cdnPt_nv_V4
  { 1517,	3,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x2788a40006ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1517 = STrih_imm_V4
  { 1518,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x2786b400c6ULL, NULL, NULL, OperandInfo105,0,0 },  // Inst #1518 = STrih_imm_cNotPt_V4
  { 1519,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x2786b40046ULL, NULL, NULL, OperandInfo105,0,0 },  // Inst #1519 = STrih_imm_cPt_V4
  { 1520,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x2786b401c6ULL, NULL, NULL, OperandInfo105,0,0 },  // Inst #1520 = STrih_imm_cdnNotPt_V4
  { 1521,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x2786b40146ULL, NULL, NULL, OperandInfo105,0,0 },  // Inst #1521 = STrih_imm_cdnPt_V4
  { 1522,	3,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x27ec950006ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1522 = STrih_indexed
  { 1523,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x27e72500c6ULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1523 = STrih_indexed_cNotPt
  { 1524,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x27872600caULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1524 = STrih_indexed_cNotPt_nv_V4
  { 1525,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x27e7250046ULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1525 = STrih_indexed_cPt
  { 1526,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x278726004aULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1526 = STrih_indexed_cPt_nv_V4
  { 1527,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x27872501c6ULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1527 = STrih_indexed_cdnNotPt_V4
  { 1528,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x27872601caULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1528 = STrih_indexed_cdnNotPt_nv_V4
  { 1529,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x2787250146ULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1529 = STrih_indexed_cdnPt_V4
  { 1530,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x278726014aULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1530 = STrih_indexed_cdnPt_nv_V4
  { 1531,	3,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x278c96000aULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1531 = STrih_indexed_nv_V4
  { 1532,	4,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x2b80010006ULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #1532 = STrih_indexed_shl_V4
  { 1533,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x2b800100c6ULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1533 = STrih_indexed_shl_cNotPt_V4
  { 1534,	5,	0,	10,	4,	0|(1<<MCID::MayStore), 0x2b800200caULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1534 = STrih_indexed_shl_cNotPt_nv_V4
  { 1535,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x2b80010046ULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1535 = STrih_indexed_shl_cPt_V4
  { 1536,	5,	0,	10,	4,	0|(1<<MCID::MayStore), 0x2b8002004aULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1536 = STrih_indexed_shl_cPt_nv_V4
  { 1537,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x2b800101c6ULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1537 = STrih_indexed_shl_cdnNotPt_V4
  { 1538,	5,	0,	10,	4,	0|(1<<MCID::MayStore), 0x2b800201caULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1538 = STrih_indexed_shl_cdnNotPt_nv_V4
  { 1539,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x2b80010146ULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1539 = STrih_indexed_shl_cdnPt_V4
  { 1540,	5,	0,	10,	4,	0|(1<<MCID::MayStore), 0x2b8002014aULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1540 = STrih_indexed_shl_cdnPt_nv_V4
  { 1541,	4,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x2b8002000aULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #1541 = STrih_indexed_shl_nv_V4
  { 1542,	3,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x278c96000aULL, NULL, NULL, OperandInfo103,0,0 },  // Inst #1542 = STrih_nv_V4
  { 1543,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1e0000006ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1543 = STrih_offset_ext_V4
  { 1544,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x180290006ULL, NULL, NULL, OperandInfo108,0,0 },  // Inst #1544 = STrih_shl_V4
  { 1545,	4,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x1802a000aULL, NULL, NULL, OperandInfo108,0,0 },  // Inst #1545 = STrih_shl_nv_V4
  { 1546,	3,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x37ed950006ULL, NULL, NULL, OperandInfo103,0,0 },  // Inst #1546 = STriw
  { 1547,	2,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x33e0090006ULL, NULL, NULL, OperandInfo87,0,0 },  // Inst #1547 = STriw_abs_V4
  { 1548,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x33e01900c6ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1548 = STriw_abs_cNotPt_V4
  { 1549,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x33e01a00caULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1549 = STriw_abs_cNotPt_nv_V4
  { 1550,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x33e0190046ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1550 = STriw_abs_cPt_V4
  { 1551,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x33e01a004aULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1551 = STriw_abs_cPt_nv_V4
  { 1552,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x33e01901c6ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1552 = STriw_abs_cdnNotPt_V4
  { 1553,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x33e01a01caULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1553 = STriw_abs_cdnNotPt_nv_V4
  { 1554,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x33e0190146ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1554 = STriw_abs_cdnPt_V4
  { 1555,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x33e01a014aULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1555 = STriw_abs_cdnPt_nv_V4
  { 1556,	2,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x33e00a000aULL, NULL, NULL, OperandInfo87,0,0 },  // Inst #1556 = STriw_abs_nv_V4
  { 1557,	3,	1,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x580280006ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1557 = STriw_abs_set_V4
  { 1558,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x37e82500c6ULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1558 = STriw_cNotPt
  { 1559,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x37882600caULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1559 = STriw_cNotPt_nv_V4
  { 1560,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x37e8250046ULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1560 = STriw_cPt
  { 1561,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x378826004aULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1561 = STriw_cPt_nv_V4
  { 1562,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x37882501c6ULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1562 = STriw_cdnNotPt_V4
  { 1563,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x37882601caULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1563 = STriw_cdnNotPt_nv_V4
  { 1564,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x3788250146ULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1564 = STriw_cdnPt_V4
  { 1565,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x378826014aULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #1565 = STriw_cdnPt_nv_V4
  { 1566,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1e0000006ULL, NULL, NULL, OperandInfo103,0,0 },  // Inst #1566 = STriw_f
  { 1567,	3,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x3788a40006ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1567 = STriw_imm_V4
  { 1568,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x3786b400c6ULL, NULL, NULL, OperandInfo105,0,0 },  // Inst #1568 = STriw_imm_cNotPt_V4
  { 1569,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x3786b40046ULL, NULL, NULL, OperandInfo105,0,0 },  // Inst #1569 = STriw_imm_cPt_V4
  { 1570,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x3786b401c6ULL, NULL, NULL, OperandInfo105,0,0 },  // Inst #1570 = STriw_imm_cdnNotPt_V4
  { 1571,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x3786b40146ULL, NULL, NULL, OperandInfo105,0,0 },  // Inst #1571 = STriw_imm_cdnPt_V4
  { 1572,	3,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x37ed950006ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1572 = STriw_indexed
  { 1573,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x37e82500c6ULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1573 = STriw_indexed_cNotPt
  { 1574,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x37882600caULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1574 = STriw_indexed_cNotPt_nv_V4
  { 1575,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x37e8250046ULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1575 = STriw_indexed_cPt
  { 1576,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x378826004aULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1576 = STriw_indexed_cPt_nv_V4
  { 1577,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x37882501c6ULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1577 = STriw_indexed_cdnNotPt_V4
  { 1578,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x37882601caULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1578 = STriw_indexed_cdnNotPt_nv_V4
  { 1579,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x3788250146ULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1579 = STriw_indexed_cdnPt_V4
  { 1580,	4,	0,	10,	4,	0|(1<<MCID::MayStore), 0x378826014aULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #1580 = STriw_indexed_cdnPt_nv_V4
  { 1581,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1e0000006ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1581 = STriw_indexed_f
  { 1582,	3,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x378d96000aULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1582 = STriw_indexed_nv_V4
  { 1583,	4,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x3b80010006ULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #1583 = STriw_indexed_shl_V4
  { 1584,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x3b800100c6ULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1584 = STriw_indexed_shl_cNotPt_V4
  { 1585,	5,	0,	10,	4,	0|(1<<MCID::MayStore), 0x3b800200caULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1585 = STriw_indexed_shl_cNotPt_nv_V4
  { 1586,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x3b80010046ULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1586 = STriw_indexed_shl_cPt_V4
  { 1587,	5,	0,	10,	4,	0|(1<<MCID::MayStore), 0x3b8002004aULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1587 = STriw_indexed_shl_cPt_nv_V4
  { 1588,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x3b800101c6ULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1588 = STriw_indexed_shl_cdnNotPt_V4
  { 1589,	5,	0,	10,	4,	0|(1<<MCID::MayStore), 0x3b800201caULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1589 = STriw_indexed_shl_cdnNotPt_nv_V4
  { 1590,	5,	0,	6,	4,	0|(1<<MCID::MayStore), 0x3b80010146ULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1590 = STriw_indexed_shl_cdnPt_V4
  { 1591,	5,	0,	10,	4,	0|(1<<MCID::MayStore), 0x3b8002014aULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #1591 = STriw_indexed_shl_cdnPt_nv_V4
  { 1592,	4,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x3b8002000aULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #1592 = STriw_indexed_shl_nv_V4
  { 1593,	3,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x378d96000aULL, NULL, NULL, OperandInfo103,0,0 },  // Inst #1593 = STriw_nv_V4
  { 1594,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1e0000006ULL, NULL, NULL, OperandInfo35,0,0 },  // Inst #1594 = STriw_offset_ext_V4
  { 1595,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1e0000006ULL, NULL, ImplicitList14, OperandInfo116,0,0 },  // Inst #1595 = STriw_pred
  { 1596,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1e0000006ULL, NULL, NULL, OperandInfo116,0,0 },  // Inst #1596 = STriw_pred_V4
  { 1597,	4,	0,	6,	4,	0|(1<<MCID::MayStore), 0x180290006ULL, NULL, NULL, OperandInfo108,0,0 },  // Inst #1597 = STriw_shl_V4
  { 1598,	4,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x1802a000aULL, NULL, NULL, OperandInfo108,0,0 },  // Inst #1598 = STriw_shl_nv_V4
  { 1599,	2,	0,	6,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x180010006ULL, NULL, NULL, OperandInfo87,0,0 },  // Inst #1599 = STw_GP_V4
  { 1600,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1801900c6ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1600 = STw_GP_cNotPt_V4
  { 1601,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1801a00caULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1601 = STw_GP_cNotPt_nv_V4
  { 1602,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x180190046ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1602 = STw_GP_cPt_V4
  { 1603,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1801a004aULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1603 = STw_GP_cPt_nv_V4
  { 1604,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x1801901c6ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1604 = STw_GP_cdnNotPt_V4
  { 1605,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1801a01caULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1605 = STw_GP_cdnNotPt_nv_V4
  { 1606,	3,	0,	6,	4,	0|(1<<MCID::MayStore), 0x180190146ULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1606 = STw_GP_cdnPt_V4
  { 1607,	3,	0,	10,	4,	0|(1<<MCID::MayStore), 0x1801a014aULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #1607 = STw_GP_cdnPt_nv_V4
  { 1608,	2,	0,	10,	4,	0|(1<<MCID::MayStore)|(1<<MCID::Predicable), 0x18002000aULL, NULL, NULL, OperandInfo87,0,0 },  // Inst #1608 = STw_GP_nv_V4
  { 1609,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1609 = SUB64_rr
  { 1610,	3,	1,	3,	4,	0, 0x1ea940001ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #1610 = SUB_ri
  { 1611,	3,	1,	3,	4,	0|(1<<MCID::Predicable), 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1611 = SUB_rr
  { 1612,	4,	1,	3,	4,	0, 0x1e00000c1ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1612 = SUB_rr_cNotPt
  { 1613,	4,	1,	3,	4,	0, 0x1e0000041ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1613 = SUB_rr_cPt
  { 1614,	4,	1,	3,	4,	0, 0x1e00001c1ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1614 = SUB_rr_cdnNotPt
  { 1615,	4,	1,	3,	4,	0, 0x1e0000141ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1615 = SUB_rr_cdnPt
  { 1616,	4,	1,	4,	4,	0, 0x188140008ULL, NULL, NULL, OperandInfo16,0,0 },  // Inst #1616 = SUBi_ASLri_V4
  { 1617,	4,	1,	4,	4,	0, 0x188140008ULL, NULL, NULL, OperandInfo16,0,0 },  // Inst #1617 = SUBi_LSRri_V4
  { 1618,	4,	1,	4,	4,	0, 0x1e8b40008ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #1618 = SUBri_acc
  { 1619,	4,	1,	4,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1619 = SUBrr_acc
  { 1620,	2,	1,	3,	4,	0|(1<<MCID::Predicable), 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #1620 = SXTB
  { 1621,	3,	1,	3,	4,	0, 0x1800000c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1621 = SXTB_cNotPt_V4
  { 1622,	3,	1,	3,	4,	0, 0x180000041ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1622 = SXTB_cPt_V4
  { 1623,	3,	1,	3,	4,	0, 0x1800001c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1623 = SXTB_cdnNotPt_V4
  { 1624,	3,	1,	3,	4,	0, 0x180000141ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1624 = SXTB_cdnPt_V4
  { 1625,	2,	1,	3,	4,	0|(1<<MCID::Predicable), 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #1625 = SXTH
  { 1626,	3,	1,	3,	4,	0, 0x1800000c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1626 = SXTH_cNotPt_V4
  { 1627,	3,	1,	3,	4,	0, 0x180000041ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1627 = SXTH_cPt_V4
  { 1628,	3,	1,	3,	4,	0, 0x1800001c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1628 = SXTH_cdnNotPt_V4
  { 1629,	3,	1,	3,	4,	0, 0x180000141ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1629 = SXTH_cdnPt_V4
  { 1630,	2,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #1630 = SXTW
  { 1631,	1,	0,	9,	4,	0|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::Call)|(1<<MCID::Predicable), 0x1e0000003ULL, NULL, ImplicitList8, OperandInfo31,0,0 },  // Inst #1631 = TCRETURNR
  { 1632,	1,	0,	8,	4,	0|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::Call)|(1<<MCID::Terminator), 0x1f8840004ULL, NULL, ImplicitList8, OperandInfo5,0,0 },  // Inst #1632 = TCRETURNtext
  { 1633,	1,	0,	8,	4,	0|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::Call)|(1<<MCID::Terminator), 0x1f8840004ULL, NULL, ImplicitList8, OperandInfo5,0,0 },  // Inst #1633 = TCRETURNtg
  { 1634,	2,	1,	14,	4,	0, 0x1e0000002ULL, NULL, NULL, OperandInfo117,0,0 },  // Inst #1634 = TFCR
  { 1635,	2,	1,	3,	4,	0|(1<<MCID::Predicable), 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #1635 = TFR
  { 1636,	2,	1,	3,	4,	0|(1<<MCID::Predicable), 0x1e0000001ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #1636 = TFR64
  { 1637,	3,	1,	3,	4,	0, 0x1e00000c1ULL, NULL, NULL, OperandInfo118,0,0 },  // Inst #1637 = TFR64_cNotPt
  { 1638,	3,	1,	3,	4,	0, 0x1e0000041ULL, NULL, NULL, OperandInfo118,0,0 },  // Inst #1638 = TFR64_cPt
  { 1639,	3,	1,	3,	4,	0, 0x1e00001c1ULL, NULL, NULL, OperandInfo118,0,0 },  // Inst #1639 = TFR64_cdnNotPt
  { 1640,	3,	1,	3,	4,	0, 0x1e0000141ULL, NULL, NULL, OperandInfo118,0,0 },  // Inst #1640 = TFR64_cdnPt
  { 1641,	2,	1,	3,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Predicable)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x1f0940001ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1641 = TFRI
  { 1642,	2,	1,	1,	4,	0|(1<<MCID::Rematerializable), 0x1e0000008ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #1642 = TFRI64
  { 1643,	2,	1,	3,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x180180001ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1643 = TFRI_V4
  { 1644,	3,	1,	3,	4,	0|(1<<MCID::MoveImm), 0x1eca400c1ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1644 = TFRI_cNotPt
  { 1645,	3,	1,	3,	4,	0, 0x1802800c1ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1645 = TFRI_cNotPt_V4
  { 1646,	3,	1,	3,	4,	0, 0x1002800c1ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1646 = TFRI_cNotPt_f
  { 1647,	3,	1,	3,	4,	0|(1<<MCID::MoveImm), 0x1eca40041ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1647 = TFRI_cPt
  { 1648,	3,	1,	3,	4,	0, 0x180280041ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1648 = TFRI_cPt_V4
  { 1649,	3,	1,	3,	4,	0, 0x100280041ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1649 = TFRI_cPt_f
  { 1650,	3,	1,	3,	4,	0|(1<<MCID::MoveImm), 0x1eca401c1ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1650 = TFRI_cdnNotPt
  { 1651,	3,	1,	3,	4,	0, 0x1802800c1ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1651 = TFRI_cdnNotPt_V4
  { 1652,	3,	1,	3,	4,	0|(1<<MCID::MoveImm), 0x1eca40141ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1652 = TFRI_cdnPt
  { 1653,	3,	1,	3,	4,	0, 0x180280041ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #1653 = TFRI_cdnPt_V4
  { 1654,	2,	1,	3,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Predicable)|(1<<MCID::Rematerializable), 0x100180001ULL, NULL, NULL, OperandInfo33,0,0 },  // Inst #1654 = TFRI_f
  { 1655,	3,	1,	3,	4,	0|(1<<MCID::Rematerializable), 0x1e0000001ULL, NULL, NULL, OperandInfo119,0,0 },  // Inst #1655 = TFR_FI
  { 1656,	3,	1,	3,	4,	0|(1<<MCID::Rematerializable), 0x180280001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1656 = TFR_FI_immext_V4
  { 1657,	1,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #1657 = TFR_PdFalse
  { 1658,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo52,0,0 },  // Inst #1658 = TFR_PdRs
  { 1659,	2,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo120,0,0 },  // Inst #1659 = TFR_RsPd
  { 1660,	3,	1,	3,	4,	0, 0x1e00000c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1660 = TFR_cNotPt
  { 1661,	3,	1,	3,	4,	0, 0x1e0000041ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1661 = TFR_cPt
  { 1662,	3,	1,	3,	4,	0, 0x1e00001c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1662 = TFR_cdnNotPt
  { 1663,	3,	1,	3,	4,	0, 0x1e0000141ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1663 = TFR_cdnPt
  { 1664,	4,	1,	3,	4,	0, 0x1e0000041ULL, NULL, NULL, OperandInfo89,0,0 },  // Inst #1664 = TFR_condset_ii
  { 1665,	4,	1,	3,	4,	0, 0x1e0000041ULL, NULL, NULL, OperandInfo121,0,0 },  // Inst #1665 = TFR_condset_ii_f
  { 1666,	4,	1,	3,	4,	0, 0x1e0000041ULL, NULL, NULL, OperandInfo90,0,0 },  // Inst #1666 = TFR_condset_ir
  { 1667,	4,	1,	3,	4,	0, 0x1e0000041ULL, NULL, NULL, OperandInfo122,0,0 },  // Inst #1667 = TFR_condset_ir_f
  { 1668,	4,	1,	3,	4,	0, 0x1e0000041ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #1668 = TFR_condset_ri
  { 1669,	4,	1,	3,	4,	0, 0x1e0000041ULL, NULL, NULL, OperandInfo123,0,0 },  // Inst #1669 = TFR_condset_ri_f
  { 1670,	4,	1,	3,	4,	0, 0x1e0000041ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1670 = TFR_condset_rr
  { 1671,	4,	1,	3,	4,	0, 0x1e0000041ULL, NULL, NULL, OperandInfo124,0,0 },  // Inst #1671 = TFR_condset_rr64_f
  { 1672,	4,	1,	3,	4,	0, 0x1e0000041ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1672 = TFR_condset_rr_f
  { 1673,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1673 = TOGBIT
  { 1674,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1674 = TOGBIT_31
  { 1675,	2,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1eb9402caULL, NULL, ImplicitList8, OperandInfo33,0,0 },  // Inst #1675 = TSTBIT0_f_Jumpnv_nt_V4
  { 1676,	2,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1eb9402caULL, NULL, ImplicitList8, OperandInfo33,0,0 },  // Inst #1676 = TSTBIT0_f_Jumpnv_t_V4
  { 1677,	2,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1eb94024aULL, NULL, ImplicitList8, OperandInfo33,0,0 },  // Inst #1677 = TSTBIT0_t_Jumpnv_nt_V4
  { 1678,	2,	0,	10,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x1eb94024aULL, NULL, ImplicitList8, OperandInfo33,0,0 },  // Inst #1678 = TSTBIT0_t_Jumpnv_t_V4
  { 1679,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo34,0,0 },  // Inst #1679 = TSTBIT_ri
  { 1680,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo36,0,0 },  // Inst #1680 = TSTBIT_rr
  { 1681,	3,	1,	3,	4,	0, 0x180000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1681 = V4_A4_rcmpeq
  { 1682,	3,	1,	3,	4,	0, 0x188a40001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1682 = V4_A4_rcmpeqi
  { 1683,	3,	1,	3,	4,	0, 0x180000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1683 = V4_A4_rcmpneq
  { 1684,	3,	1,	3,	4,	0, 0x188a40001ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #1684 = V4_A4_rcmpneqi
  { 1685,	4,	1,	2,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1e0000008ULL, NULL, NULL, OperandInfo125,0,0 },  // Inst #1685 = VALIGN_rrp
  { 1686,	3,	1,	2,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1e0000008ULL, NULL, NULL, OperandInfo126,0,0 },  // Inst #1686 = VITPACK_pp
  { 1687,	4,	1,	1,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1e0000008ULL, NULL, NULL, OperandInfo124,0,0 },  // Inst #1687 = VMUX_prr64
  { 1688,	4,	1,	2,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x1e0000008ULL, NULL, NULL, OperandInfo125,0,0 },  // Inst #1688 = VSPLICE_rrp
  { 1689,	3,	1,	2,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo24,0,0 },  // Inst #1689 = XOR_pp
  { 1690,	3,	1,	3,	4,	0|(1<<MCID::Predicable)|(1<<MCID::Commutable), 0x1e0000001ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1690 = XOR_rr
  { 1691,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1691 = XOR_rr64
  { 1692,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e00000c1ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1692 = XOR_rr_cNotPt
  { 1693,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e0000041ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1693 = XOR_rr_cPt
  { 1694,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e00001c1ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1694 = XOR_rr_cdnNotPt
  { 1695,	4,	1,	3,	4,	0|(1<<MCID::Commutable), 0x1e0000141ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #1695 = XOR_rr_cdnPt
  { 1696,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #1696 = XORd_XORdd
  { 1697,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1697 = XORr_ANDr_NOTr_V4
  { 1698,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1698 = XORr_ANDrr_V4
  { 1699,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1699 = XORr_ORrr_V4
  { 1700,	4,	1,	4,	4,	0, 0x180000008ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #1700 = XORr_XORrr_V4
  { 1701,	2,	1,	3,	4,	0|(1<<MCID::Predicable), 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #1701 = ZXTB
  { 1702,	3,	1,	3,	4,	0, 0x1800000c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1702 = ZXTB_cNotPt_V4
  { 1703,	3,	1,	3,	4,	0, 0x180000041ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1703 = ZXTB_cPt_V4
  { 1704,	3,	1,	3,	4,	0, 0x1800001c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1704 = ZXTB_cdnNotPt_V4
  { 1705,	3,	1,	3,	4,	0, 0x180000141ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1705 = ZXTB_cdnPt_V4
  { 1706,	2,	1,	3,	4,	0|(1<<MCID::Predicable), 0x1e0000001ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #1706 = ZXTH
  { 1707,	3,	1,	3,	4,	0, 0x1800000c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1707 = ZXTH_cNotPt_V4
  { 1708,	3,	1,	3,	4,	0, 0x180000041ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1708 = ZXTH_cPt_V4
  { 1709,	3,	1,	3,	4,	0, 0x1800001c1ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1709 = ZXTH_cdnNotPt_V4
  { 1710,	3,	1,	3,	4,	0, 0x180000141ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #1710 = ZXTH_cdnPt_V4
  { 1711,	3,	1,	1,	4,	0|(1<<MCID::Commutable), 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1711 = fADD64_rr
  { 1712,	3,	1,	1,	4,	0|(1<<MCID::Commutable), 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1712 = fADD_rr
  { 1713,	3,	1,	1,	4,	0|(1<<MCID::Commutable), 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1713 = fMUL64_rr
  { 1714,	3,	1,	1,	4,	0|(1<<MCID::Commutable), 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1714 = fMUL_rr
  { 1715,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #1715 = fSUB64_rr
  { 1716,	3,	1,	1,	4,	0, 0x1e0000008ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #1716 = fSUB_rr
};

extern const char HexagonInstrNameData[] = {
  /* 0 */ 'E', 'N', 'D', 'L', 'O', 'O', 'P', '0', 0,
  /* 9 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'c', 'l', '0', 0,
  /* 24 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'r', 'm', 'a', 'c', '_', 's', '0', 0,
  /* 44 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'd', 'p', 'm', 'p', 'y', 's', 's', '_', 'n', 'a', 'c', '_', 's', '0', 0,
  /* 70 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'd', 'p', 'm', 'p', 'y', 'u', 'u', '_', 'n', 'a', 'c', '_', 's', '0', 0,
  /* 96 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'd', 'p', 'm', 'p', 'y', 's', 's', '_', 'a', 'c', 'c', '_', 's', '0', 0,
  /* 122 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'd', 'p', 'm', 'p', 'y', 'u', 'u', '_', 'a', 'c', 'c', '_', 's', '0', 0,
  /* 148 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'a', 'c', 's', 'c', '_', 's', '0', 0,
  /* 169 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'n', 'a', 'c', 's', 'c', '_', 's', '0', 0,
  /* 190 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'p', 'y', 'r', 's', 'c', '_', 's', '0', 0,
  /* 212 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'p', 'y', 's', 'c', '_', 's', '0', 0,
  /* 233 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'd', 'p', 'm', 'p', 'y', 's', 's', '_', 'r', 'n', 'd', '_', 's', '0', 0,
  /* 259 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'n', 'a', 'c', '_', 'h', 'h', '_', 's', '0', 0,
  /* 286 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'n', 'a', 'c', '_', 'h', 'h', '_', 's', '0', 0,
  /* 312 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'n', 'a', 'c', '_', 'h', 'h', '_', 's', '0', 0,
  /* 338 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 'h', 'h', '_', 's', '0', 0,
  /* 363 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'a', 'c', 'c', '_', 'h', 'h', '_', 's', '0', 0,
  /* 390 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'a', 'c', 'c', '_', 'h', 'h', '_', 's', '0', 0,
  /* 416 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'a', 'c', 'c', '_', 'h', 'h', '_', 's', '0', 0,
  /* 442 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 'h', 'h', '_', 's', '0', 0,
  /* 467 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'r', 'n', 'd', '_', 'h', 'h', '_', 's', '0', 0,
  /* 493 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'r', 'n', 'd', '_', 'h', 'h', '_', 's', '0', 0,
  /* 522 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'r', 'n', 'd', '_', 'h', 'h', '_', 's', '0', 0,
  /* 547 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'h', 'h', '_', 's', '0', 0,
  /* 570 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'h', 'h', '_', 's', '0', 0,
  /* 592 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 's', 'a', 't', '_', 'h', 'h', '_', 's', '0', 0,
  /* 621 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 's', 'a', 't', '_', 'h', 'h', '_', 's', '0', 0,
  /* 650 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'h', 'h', '_', 's', '0', 0,
  /* 675 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'h', 'h', '_', 's', '0', 0,
  /* 697 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'h', 'h', '_', 's', '0', 0,
  /* 718 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'n', 'a', 'c', '_', 'l', 'h', '_', 's', '0', 0,
  /* 745 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'n', 'a', 'c', '_', 'l', 'h', '_', 's', '0', 0,
  /* 771 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'n', 'a', 'c', '_', 'l', 'h', '_', 's', '0', 0,
  /* 797 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 'l', 'h', '_', 's', '0', 0,
  /* 822 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'a', 'c', 'c', '_', 'l', 'h', '_', 's', '0', 0,
  /* 849 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'a', 'c', 'c', '_', 'l', 'h', '_', 's', '0', 0,
  /* 875 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'a', 'c', 'c', '_', 'l', 'h', '_', 's', '0', 0,
  /* 901 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 'l', 'h', '_', 's', '0', 0,
  /* 926 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'r', 'n', 'd', '_', 'l', 'h', '_', 's', '0', 0,
  /* 952 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'r', 'n', 'd', '_', 'l', 'h', '_', 's', '0', 0,
  /* 981 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'r', 'n', 'd', '_', 'l', 'h', '_', 's', '0', 0,
  /* 1006 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'l', 'h', '_', 's', '0', 0,
  /* 1029 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'l', 'h', '_', 's', '0', 0,
  /* 1051 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 's', 'a', 't', '_', 'l', 'h', '_', 's', '0', 0,
  /* 1080 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 's', 'a', 't', '_', 'l', 'h', '_', 's', '0', 0,
  /* 1109 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'l', 'h', '_', 's', '0', 0,
  /* 1134 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'l', 'h', '_', 's', '0', 0,
  /* 1156 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'l', 'h', '_', 's', '0', 0,
  /* 1177 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'u', 'h', '_', 's', '0', 0,
  /* 1198 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'h', '_', 's', '0', 0,
  /* 1218 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'a', 'c', 'i', '_', 's', '0', 0,
  /* 1238 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'r', 'c', 'm', 'a', 'c', 'i', '_', 's', '0', 0,
  /* 1260 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'p', 'y', 'i', '_', 's', '0', 0,
  /* 1280 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'r', 'c', 'm', 'p', 'y', 'i', '_', 's', '0', 0,
  /* 1302 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'n', 'a', 'c', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1329 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'n', 'a', 'c', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1355 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'n', 'a', 'c', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1381 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1406 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'a', 'c', 'c', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1433 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'a', 'c', 'c', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1459 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'a', 'c', 'c', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1485 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1510 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'r', 'n', 'd', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1536 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'r', 'n', 'd', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1565 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'r', 'n', 'd', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1590 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1613 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1635 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 's', 'a', 't', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1664 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 's', 'a', 't', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1693 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1718 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1740 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'h', 'l', '_', 's', '0', 0,
  /* 1761 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'n', 'a', 'c', '_', 'l', 'l', '_', 's', '0', 0,
  /* 1788 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'n', 'a', 'c', '_', 'l', 'l', '_', 's', '0', 0,
  /* 1814 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'n', 'a', 'c', '_', 'l', 'l', '_', 's', '0', 0,
  /* 1840 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 'l', 'l', '_', 's', '0', 0,
  /* 1865 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'a', 'c', 'c', '_', 'l', 'l', '_', 's', '0', 0,
  /* 1892 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'a', 'c', 'c', '_', 'l', 'l', '_', 's', '0', 0,
  /* 1918 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'a', 'c', 'c', '_', 'l', 'l', '_', 's', '0', 0,
  /* 1944 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 'l', 'l', '_', 's', '0', 0,
  /* 1969 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'r', 'n', 'd', '_', 'l', 'l', '_', 's', '0', 0,
  /* 1995 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'r', 'n', 'd', '_', 'l', 'l', '_', 's', '0', 0,
  /* 2024 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'r', 'n', 'd', '_', 'l', 'l', '_', 's', '0', 0,
  /* 2049 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'l', 'l', '_', 's', '0', 0,
  /* 2072 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'l', 'l', '_', 's', '0', 0,
  /* 2094 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 's', 'a', 't', '_', 'l', 'l', '_', 's', '0', 0,
  /* 2123 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 's', 'a', 't', '_', 'l', 'l', '_', 's', '0', 0,
  /* 2152 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'l', 'l', '_', 's', '0', 0,
  /* 2177 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'l', 'l', '_', 's', '0', 0,
  /* 2199 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'l', 'l', '_', 's', '0', 0,
  /* 2220 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'u', 'l', '_', 's', '0', 0,
  /* 2241 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'l', '_', 's', '0', 0,
  /* 2261 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'a', 'c', 'r', '_', 's', '0', 0,
  /* 2281 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'r', 'c', 'm', 'a', 'c', 'r', '_', 's', '0', 0,
  /* 2303 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'p', 'y', 'r', '_', 's', '0', 0,
  /* 2323 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'r', 'c', 'm', 'p', 'y', 'r', '_', 's', '0', 0,
  /* 2345 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'm', 'a', 'c', '2', 's', '_', 's', '0', 0,
  /* 2366 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'm', 'p', 'y', '2', 's', '_', 's', '0', 0,
  /* 2387 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'a', 'c', 's', '_', 's', '0', 0,
  /* 2407 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'd', 'm', 'a', 'c', 's', '_', 's', '0', 0,
  /* 2428 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'n', 'a', 'c', 's', '_', 's', '0', 0,
  /* 2448 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'm', 'a', 'c', '2', 'e', 's', '_', 's', '0', 0,
  /* 2470 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'm', 'p', 'y', '2', 'e', 's', '_', 's', '0', 0,
  /* 2492 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'h', 's', '_', 's', '0', 0,
  /* 2513 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'u', 'h', 's', '_', 's', '0', 0,
  /* 2535 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'l', 's', '_', 's', '0', 0,
  /* 2556 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'u', 'l', 's', '_', 's', '0', 0,
  /* 2578 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'p', 'y', 'r', 's', '_', 's', '0', 0,
  /* 2599 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'd', 'm', 'p', 'y', 'r', 's', '_', 's', '0', 0,
  /* 2621 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'd', 'p', 'm', 'p', 'y', 's', 's', '_', 's', '0', 0,
  /* 2643 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'p', 'y', 's', '_', 's', '0', 0,
  /* 2663 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'd', 'm', 'p', 'y', 's', '_', 's', '0', 0,
  /* 2684 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'd', 'p', 'm', 'p', 'y', 'u', 'u', '_', 's', '0', 0,
  /* 2706 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'r', 'm', 'p', 'y', '_', 's', '0', 0,
  /* 2726 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'u', 'h', '_', 'r', 's', '0', 0,
  /* 2748 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'h', '_', 'r', 's', '0', 0,
  /* 2769 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'u', 'l', '_', 'r', 's', '0', 0,
  /* 2791 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'l', '_', 'r', 's', '0', 0,
  /* 2812 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'h', 's', '_', 'r', 's', '0', 0,
  /* 2834 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'u', 'h', 's', '_', 'r', 's', '0', 0,
  /* 2857 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'l', 's', '_', 'r', 's', '0', 0,
  /* 2879 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'u', 'l', 's', '_', 'r', 's', '0', 0,
  /* 2902 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'c', 't', '0', 0,
  /* 2917 */ 'T', 'O', 'G', 'B', 'I', 'T', '_', '3', '1', 0,
  /* 2927 */ 'C', 'L', 'R', 'B', 'I', 'T', '_', '3', '1', 0,
  /* 2937 */ 'S', 'E', 'T', 'B', 'I', 'T', '_', '3', '1', 0,
  /* 2947 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'c', 'l', '1', 0,
  /* 2962 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'M', '2', '_', 'v', 'r', 'c', 'm', 'p', 'y', 's', '_', 'a', 'c', 'c', '_', 's', '1', 0,
  /* 2988 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'a', 'c', 's', 'c', '_', 's', '1', 0,
  /* 3009 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'n', 'a', 'c', 's', 'c', '_', 's', '1', 0,
  /* 3030 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'p', 'y', 'r', 's', 'c', '_', 's', '1', 0,
  /* 3052 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'p', 'y', 's', 'c', '_', 's', '1', 0,
  /* 3073 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'n', 'a', 'c', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3100 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'n', 'a', 'c', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3126 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'n', 'a', 'c', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3152 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3177 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'a', 'c', 'c', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3204 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'a', 'c', 'c', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3230 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'a', 'c', 'c', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3256 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3281 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'r', 'n', 'd', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3307 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'r', 'n', 'd', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3336 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'r', 'n', 'd', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3361 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3384 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3406 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 's', 'a', 't', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3435 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 's', 'a', 't', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3464 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3489 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3511 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'h', 'h', '_', 's', '1', 0,
  /* 3532 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'n', 'a', 'c', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3559 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'n', 'a', 'c', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3585 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'n', 'a', 'c', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3611 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3636 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'a', 'c', 'c', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3663 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'a', 'c', 'c', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3689 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'a', 'c', 'c', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3715 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3740 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'r', 'n', 'd', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3766 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'r', 'n', 'd', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3795 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'r', 'n', 'd', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3820 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3843 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3865 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 's', 'a', 't', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3894 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 's', 'a', 't', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3923 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3948 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3970 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'l', 'h', '_', 's', '1', 0,
  /* 3991 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'u', 'h', '_', 's', '1', 0,
  /* 4012 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'h', '_', 's', '1', 0,
  /* 4032 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'n', 'a', 'c', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4059 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'n', 'a', 'c', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4085 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'n', 'a', 'c', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4111 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4136 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'a', 'c', 'c', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4163 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'a', 'c', 'c', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4189 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'a', 'c', 'c', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4215 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4240 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'r', 'n', 'd', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4266 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'r', 'n', 'd', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4295 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'r', 'n', 'd', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4320 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4343 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4365 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 's', 'a', 't', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4394 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 's', 'a', 't', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4423 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4448 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4470 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'h', 'l', '_', 's', '1', 0,
  /* 4491 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'n', 'a', 'c', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4518 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'n', 'a', 'c', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4544 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'n', 'a', 'c', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4570 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4595 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'a', 'c', 'c', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4622 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'a', 'c', 'c', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4648 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'a', 'c', 'c', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4674 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4699 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'r', 'n', 'd', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4725 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'r', 'n', 'd', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4754 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'r', 'n', 'd', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4779 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'd', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4802 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'd', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4824 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'n', 'a', 'c', '_', 's', 'a', 't', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4853 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'a', 'c', 'c', '_', 's', 'a', 't', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4882 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 's', 'a', 't', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4907 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4929 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'l', 'l', '_', 's', '1', 0,
  /* 4950 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'u', 'l', '_', 's', '1', 0,
  /* 4971 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'l', '_', 's', '1', 0,
  /* 4991 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'm', 'a', 'c', '2', 's', '_', 's', '1', 0,
  /* 5012 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'm', 'p', 'y', '2', 's', '_', 's', '1', 0,
  /* 5033 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'a', 'c', 's', '_', 's', '1', 0,
  /* 5053 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'd', 'm', 'a', 'c', 's', '_', 's', '1', 0,
  /* 5074 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'n', 'a', 'c', 's', '_', 's', '1', 0,
  /* 5094 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'm', 'a', 'c', '2', 'e', 's', '_', 's', '1', 0,
  /* 5116 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'm', 'p', 'y', '2', 'e', 's', '_', 's', '1', 0,
  /* 5138 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'h', 's', '_', 's', '1', 0,
  /* 5159 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'u', 'h', 's', '_', 's', '1', 0,
  /* 5181 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'l', 's', '_', 's', '1', 0,
  /* 5202 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'u', 'l', 's', '_', 's', '1', 0,
  /* 5224 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'p', 'y', 'r', 's', '_', 's', '1', 0,
  /* 5245 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'd', 'm', 'p', 'y', 'r', 's', '_', 's', '1', 0,
  /* 5267 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'c', 'm', 'p', 'y', 's', '_', 's', '1', 0,
  /* 5287 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'M', '2', '_', 'v', 'r', 'c', 'm', 'p', 'y', 's', '_', 's', '1', 0,
  /* 5309 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'd', 'm', 'p', 'y', 's', '_', 's', '1', 0,
  /* 5330 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'u', 'h', '_', 'r', 's', '1', 0,
  /* 5352 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'h', '_', 'r', 's', '1', 0,
  /* 5373 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'h', 'm', 'm', 'p', 'y', 'h', '_', 'r', 's', '1', 0,
  /* 5395 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'u', 'l', '_', 'r', 's', '1', 0,
  /* 5417 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'p', 'y', 'l', '_', 'r', 's', '1', 0,
  /* 5438 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'h', 'm', 'm', 'p', 'y', 'l', '_', 'r', 's', '1', 0,
  /* 5460 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'h', 's', '_', 'r', 's', '1', 0,
  /* 5482 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'u', 'h', 's', '_', 'r', 's', '1', 0,
  /* 5505 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'l', 's', '_', 'r', 's', '1', 0,
  /* 5527 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'm', 'a', 'c', 'u', 'l', 's', '_', 'r', 's', '1', 0,
  /* 5550 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'c', 't', '1', 0,
  /* 5565 */ 'C', 'O', 'N', 'S', 'T', '3', '2', 0,
  /* 5573 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'm', 'a', 'c', '2', 0,
  /* 5590 */ 'J', 'M', 'P', 'R', '_', 'f', 'n', 'e', 'w', '_', 't', 'V', '3', 0,
  /* 5604 */ 'J', 'M', 'P', 'r', 'e', 't', '_', 'f', 'n', 'e', 'w', '_', 't', 'V', '3', 0,
  /* 5620 */ 'J', 'M', 'P', 'R', '_', 't', 'n', 'e', 'w', '_', 't', 'V', '3', 0,
  /* 5634 */ 'J', 'M', 'P', 'r', 'e', 't', '_', 't', 'n', 'e', 'w', '_', 't', 'V', '3', 0,
  /* 5650 */ 'J', 'M', 'P', 'R', '_', 'f', 'n', 'e', 'w', '_', 'n', 't', 'V', '3', 0,
  /* 5665 */ 'J', 'M', 'P', 'r', 'e', 't', '_', 'f', 'n', 'e', 'w', '_', 'n', 't', 'V', '3', 0,
  /* 5682 */ 'J', 'M', 'P', 'R', '_', 't', 'n', 'e', 'w', '_', 'n', 't', 'V', '3', 0,
  /* 5697 */ 'J', 'M', 'P', 'r', 'e', 't', '_', 't', 'n', 'e', 'w', '_', 'n', 't', 'V', '3', 0,
  /* 5714 */ 'C', 'A', 'L', 'L', 'v', '3', 0,
  /* 5721 */ 'C', 'A', 'L', 'L', 'R', 'v', '3', 0,
  /* 5729 */ 'T', 'F', 'R', 'I', '6', '4', 0,
  /* 5736 */ 'T', 'F', 'R', '6', '4', 0,
  /* 5742 */ 'M', 'P', 'Y', 'U', '6', '4', 0,
  /* 5749 */ 'M', 'P', 'Y', '6', '4', 0,
  /* 5755 */ 'A', 'N', 'D', '_', 'r', 'r', '6', '4', 0,
  /* 5764 */ 'X', 'O', 'R', '_', 'r', 'r', '6', '4', 0,
  /* 5773 */ 'N', 'O', 'T', '_', 'r', 'r', '6', '4', 0,
  /* 5782 */ 'V', 'M', 'U', 'X', '_', 'p', 'r', 'r', '6', '4', 0,
  /* 5793 */ 'O', 'R', 'r', '_', 'A', 'N', 'D', 'r', 'i', '2', '_', 'V', '4', 0,
  /* 5807 */ 'T', 'F', 'R', 'I', '_', 'V', '4', 0,
  /* 5815 */ 'C', 'O', 'M', 'B', 'I', 'N', 'E', '_', 'i', 'I', '_', 'V', '4', 0,
  /* 5829 */ 'C', 'O', 'M', 'B', 'I', 'N', 'E', '_', 'r', 'I', '_', 'V', '4', 0,
  /* 5843 */ 'R', 'E', 'S', 'T', 'O', 'R', 'E', '_', 'D', 'E', 'A', 'L', 'L', 'O', 'C', '_', 'B', 'E', 'F', 'O', 'R', 'E', '_', 'T', 'A', 'I', 'L', 'C', 'A', 'L', 'L', '_', 'V', '4', 0,
  /* 5878 */ 'S', 'A', 'V', 'E', '_', 'R', 'E', 'G', 'I', 'S', 'T', 'E', 'R', 'S', '_', 'C', 'A', 'L', 'L', '_', 'V', '4', 0,
  /* 5901 */ 'L', 'D', 'b', '_', 'G', 'P', '_', 'V', '4', 0,
  /* 5911 */ 'S', 'T', 'b', '_', 'G', 'P', '_', 'V', '4', 0,
  /* 5921 */ 'L', 'D', 'u', 'b', '_', 'G', 'P', '_', 'V', '4', 0,
  /* 5932 */ 'L', 'D', 'd', '_', 'G', 'P', '_', 'V', '4', 0,
  /* 5942 */ 'S', 'T', 'd', '_', 'G', 'P', '_', 'V', '4', 0,
  /* 5952 */ 'L', 'D', 'h', '_', 'G', 'P', '_', 'V', '4', 0,
  /* 5962 */ 'S', 'T', 'h', '_', 'G', 'P', '_', 'V', '4', 0,
  /* 5972 */ 'L', 'D', 'u', 'h', '_', 'G', 'P', '_', 'V', '4', 0,
  /* 5983 */ 'L', 'D', 'w', '_', 'G', 'P', '_', 'V', '4', 0,
  /* 5993 */ 'S', 'T', 'w', '_', 'G', 'P', '_', 'V', '4', 0,
  /* 6003 */ 'R', 'E', 'S', 'T', 'O', 'R', 'E', '_', 'D', 'E', 'A', 'L', 'L', 'O', 'C', '_', 'R', 'E', 'T', '_', 'J', 'M', 'P', '_', 'V', '4', 0,
  /* 6030 */ 'D', 'E', 'A', 'L', 'L', 'O', 'C', '_', 'R', 'E', 'T', '_', 'V', '4', 0,
  /* 6045 */ 'C', 'M', 'P', 'b', 'E', 'Q', 'r', 'r', '_', 's', 'b', 's', 'b', '_', 'V', '4', 0,
  /* 6062 */ 'C', 'M', 'P', 'b', 'E', 'Q', 'r', 'r', '_', 'u', 'b', 'u', 'b', '_', 'V', '4', 0,
  /* 6079 */ 'A', 'N', 'D', 'd', '_', 'N', 'O', 'T', 'd', '_', 'V', '4', 0,
  /* 6092 */ 'O', 'R', 'd', '_', 'N', 'O', 'T', 'd', '_', 'V', '4', 0,
  /* 6104 */ 'S', 'T', 'r', 'i', 'w', '_', 'p', 'r', 'e', 'd', '_', 'V', '4', 0,
  /* 6118 */ 'M', 'e', 'm', 'O', 'P', 'b', '_', 'S', 'U', 'B', 'i', '_', 'V', '4', 0,
  /* 6133 */ 'M', 'e', 'm', 'O', 'P', 'h', '_', 'S', 'U', 'B', 'i', '_', 'V', '4', 0,
  /* 6148 */ 'M', 'e', 'm', 'O', 'P', 'w', '_', 'S', 'U', 'B', 'i', '_', 'V', '4', 0,
  /* 6163 */ 'M', 'e', 'm', 'O', 'P', 'b', '_', 'A', 'D', 'D', 'i', '_', 'V', '4', 0,
  /* 6178 */ 'M', 'e', 'm', 'O', 'P', 'h', '_', 'A', 'D', 'D', 'i', '_', 'V', '4', 0,
  /* 6193 */ 'M', 'e', 'm', 'O', 'P', 'w', '_', 'A', 'D', 'D', 'i', '_', 'V', '4', 0,
  /* 6208 */ 'L', 'S', 'L', 'i', '_', 'V', '4', 0,
  /* 6216 */ 'M', 'e', 'm', 'O', 'P', 'b', '_', 'C', 'L', 'R', 'B', 'I', 'T', 'i', '_', 'V', '4', 0,
  /* 6234 */ 'M', 'e', 'm', 'O', 'P', 'h', '_', 'C', 'L', 'R', 'B', 'I', 'T', 'i', '_', 'V', '4', 0,
  /* 6252 */ 'M', 'e', 'm', 'O', 'P', 'w', '_', 'C', 'L', 'R', 'B', 'I', 'T', 'i', '_', 'V', '4', 0,
  /* 6270 */ 'M', 'e', 'm', 'O', 'P', 'b', '_', 'S', 'E', 'T', 'B', 'I', 'T', 'i', '_', 'V', '4', 0,
  /* 6288 */ 'M', 'e', 'm', 'O', 'P', 'h', '_', 'S', 'E', 'T', 'B', 'I', 'T', 'i', '_', 'V', '4', 0,
  /* 6306 */ 'M', 'e', 'm', 'O', 'P', 'w', '_', 'S', 'E', 'T', 'B', 'I', 'T', 'i', '_', 'V', '4', 0,
  /* 6324 */ 'A', 'D', 'D', 'r', '_', 'S', 'U', 'B', 'r', 'i', '_', 'V', '4', 0,
  /* 6338 */ 'A', 'D', 'D', 'r', '_', 'A', 'D', 'D', 'r', 'i', '_', 'V', '4', 0,
  /* 6352 */ 'O', 'R', 'r', '_', 'A', 'N', 'D', 'r', 'i', '_', 'V', '4', 0,
  /* 6365 */ 'S', 'U', 'B', 'i', '_', 'A', 'S', 'L', 'r', 'i', '_', 'V', '4', 0,
  /* 6379 */ 'A', 'D', 'D', 'i', '_', 'A', 'S', 'L', 'r', 'i', '_', 'V', '4', 0,
  /* 6393 */ 'A', 'N', 'D', 'i', '_', 'A', 'S', 'L', 'r', 'i', '_', 'V', '4', 0,
  /* 6407 */ 'O', 'R', 'i', '_', 'A', 'S', 'L', 'r', 'i', '_', 'V', '4', 0,
  /* 6420 */ 'C', 'M', 'P', 'b', 'E', 'Q', 'r', 'i', '_', 'V', '4', 0,
  /* 6432 */ 'C', 'M', 'P', 'h', 'E', 'Q', 'r', 'i', '_', 'V', '4', 0,
  /* 6444 */ 'O', 'R', 'r', '_', 'O', 'R', 'r', 'i', '_', 'V', '4', 0,
  /* 6456 */ 'S', 'U', 'B', 'i', '_', 'L', 'S', 'R', 'r', 'i', '_', 'V', '4', 0,
  /* 6470 */ 'A', 'D', 'D', 'i', '_', 'L', 'S', 'R', 'r', 'i', '_', 'V', '4', 0,
  /* 6484 */ 'A', 'N', 'D', 'i', '_', 'L', 'S', 'R', 'r', 'i', '_', 'V', '4', 0,
  /* 6498 */ 'O', 'R', 'i', '_', 'L', 'S', 'R', 'r', 'i', '_', 'V', '4', 0,
  /* 6511 */ 'C', 'M', 'P', 'b', 'G', 'T', 'U', 'r', 'i', '_', 'V', '4', 0,
  /* 6524 */ 'C', 'M', 'P', 'h', 'G', 'T', 'U', 'r', 'i', '_', 'V', '4', 0,
  /* 6537 */ 'A', 'D', 'D', 'i', '_', 'M', 'P', 'Y', 'r', 'i', '_', 'V', '4', 0,
  /* 6551 */ 'A', 'D', 'D', 'r', '_', 'M', 'P', 'Y', 'r', 'i', '_', 'V', '4', 0,
  /* 6565 */ 'S', 'T', 'r', 'i', 'b', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6578 */ 'L', 'D', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6599 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6620 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6642 */ 'L', 'D', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6663 */ 'S', 'T', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6684 */ 'L', 'D', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6705 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6726 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6748 */ 'L', 'D', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6769 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6790 */ 'S', 'T', 'r', 'i', 'd', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6803 */ 'S', 'T', 'r', 'i', 'h', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6816 */ 'C', 'M', 'P', 'h', 'E', 'Q', 'r', 'r', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6832 */ 'C', 'M', 'P', 'h', 'G', 'T', 'r', 'r', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6848 */ 'S', 'T', 'r', 'i', 'w', '_', 's', 'h', 'l', '_', 'V', '4', 0,
  /* 6861 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'm', 'm', '_', 'V', '4', 0,
  /* 6874 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'm', 'm', '_', 'V', '4', 0,
  /* 6887 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'm', 'm', '_', 'V', '4', 0,
  /* 6900 */ 'L', 'D', 'r', 'i', 'b', '_', 'i', 'n', 'd', '_', 'l', 'o', '_', 'V', '4', 0,
  /* 6916 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'i', 'n', 'd', '_', 'l', 'o', '_', 'V', '4', 0,
  /* 6933 */ 'L', 'D', 'r', 'i', 'd', '_', 'i', 'n', 'd', '_', 'l', 'o', '_', 'V', '4', 0,
  /* 6949 */ 'L', 'D', 'r', 'i', 'h', '_', 'i', 'n', 'd', '_', 'l', 'o', '_', 'V', '4', 0,
  /* 6965 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'i', 'n', 'd', '_', 'l', 'o', '_', 'V', '4', 0,
  /* 6982 */ 'L', 'D', 'r', 'i', 'w', '_', 'i', 'n', 'd', '_', 'l', 'o', '_', 'V', '4', 0,
  /* 6998 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'i', 'n', 'd', '_', 'a', 'n', 'y', 'e', 'x', 't', '_', 'l', 'o', '_', 'V', '4', 0,
  /* 7022 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'i', 'n', 'd', '_', 'a', 'n', 'y', 'e', 'x', 't', '_', 'l', 'o', '_', 'V', '4', 0,
  /* 7046 */ 'M', 'e', 'm', 'O', 'P', 'b', '_', 'S', 'U', 'B', 'r', '_', 'V', '4', 0,
  /* 7061 */ 'M', 'e', 'm', 'O', 'P', 'h', '_', 'S', 'U', 'B', 'r', '_', 'V', '4', 0,
  /* 7076 */ 'A', 'D', 'D', 'r', 'i', '_', 'S', 'U', 'B', 'r', '_', 'V', '4', 0,
  /* 7090 */ 'M', 'e', 'm', 'O', 'P', 'w', '_', 'S', 'U', 'B', 'r', '_', 'V', '4', 0,
  /* 7105 */ 'M', 'e', 'm', 'O', 'P', 'b', '_', 'A', 'D', 'D', 'r', '_', 'V', '4', 0,
  /* 7120 */ 'M', 'e', 'm', 'O', 'P', 'h', '_', 'A', 'D', 'D', 'r', '_', 'V', '4', 0,
  /* 7135 */ 'M', 'e', 'm', 'O', 'P', 'w', '_', 'A', 'D', 'D', 'r', '_', 'V', '4', 0,
  /* 7150 */ 'M', 'e', 'm', 'O', 'P', 'b', '_', 'A', 'N', 'D', 'r', '_', 'V', '4', 0,
  /* 7165 */ 'M', 'e', 'm', 'O', 'P', 'h', '_', 'A', 'N', 'D', 'r', '_', 'V', '4', 0,
  /* 7180 */ 'M', 'e', 'm', 'O', 'P', 'w', '_', 'A', 'N', 'D', 'r', '_', 'V', '4', 0,
  /* 7195 */ 'C', 'O', 'M', 'B', 'I', 'N', 'E', '_', 'I', 'r', '_', 'V', '4', 0,
  /* 7209 */ 'M', 'e', 'm', 'O', 'P', 'b', '_', 'O', 'R', 'r', '_', 'V', '4', 0,
  /* 7223 */ 'M', 'e', 'm', 'O', 'P', 'h', '_', 'O', 'R', 'r', '_', 'V', '4', 0,
  /* 7237 */ 'M', 'e', 'm', 'O', 'P', 'w', '_', 'O', 'R', 'r', '_', 'V', '4', 0,
  /* 7251 */ 'A', 'N', 'D', 'r', '_', 'A', 'N', 'D', 'r', '_', 'N', 'O', 'T', 'r', '_', 'V', '4', 0,
  /* 7269 */ 'X', 'O', 'R', 'r', '_', 'A', 'N', 'D', 'r', '_', 'N', 'O', 'T', 'r', '_', 'V', '4', 0,
  /* 7287 */ 'A', 'D', 'D', 'r', '_', 'M', 'P', 'Y', 'i', 'r', '_', 'V', '4', 0,
  /* 7301 */ 'C', 'M', 'P', 'h', 'E', 'Q', 'r', 'r', '_', 'x', 'o', 'r', '_', 'V', '4', 0,
  /* 7317 */ 'A', 'S', 'L', 'd', '_', 'r', 'r', '_', 'x', 'o', 'r', '_', 'V', '4', 0,
  /* 7332 */ 'L', 'S', 'L', 'd', '_', 'r', 'r', '_', 'x', 'o', 'r', '_', 'V', '4', 0,
  /* 7347 */ 'A', 'S', 'R', 'd', '_', 'r', 'r', '_', 'x', 'o', 'r', '_', 'V', '4', 0,
  /* 7362 */ 'L', 'S', 'R', 'd', '_', 'r', 'r', '_', 'x', 'o', 'r', '_', 'V', '4', 0,
  /* 7377 */ 'A', 'N', 'D', 'r', '_', 'A', 'N', 'D', 'r', 'r', '_', 'V', '4', 0,
  /* 7391 */ 'X', 'O', 'R', 'r', '_', 'A', 'N', 'D', 'r', 'r', '_', 'V', '4', 0,
  /* 7405 */ 'A', 'N', 'D', 'r', '_', 'X', 'O', 'R', 'r', 'r', '_', 'V', '4', 0,
  /* 7419 */ 'X', 'O', 'R', 'r', '_', 'X', 'O', 'R', 'r', 'r', '_', 'V', '4', 0,
  /* 7433 */ 'A', 'N', 'D', 'r', '_', 'O', 'R', 'r', 'r', '_', 'V', '4', 0,
  /* 7446 */ 'X', 'O', 'R', 'r', '_', 'O', 'R', 'r', 'r', '_', 'V', '4', 0,
  /* 7459 */ 'C', 'M', 'P', 'b', 'G', 'T', 'r', 'r', '_', 'V', '4', 0,
  /* 7471 */ 'C', 'M', 'P', 'b', 'G', 'T', 'U', 'r', 'r', '_', 'V', '4', 0,
  /* 7484 */ 'C', 'M', 'P', 'h', 'G', 'T', 'U', 'r', 'r', '_', 'V', '4', 0,
  /* 7497 */ 'A', 'D', 'D', 'i', '_', 'M', 'P', 'Y', 'r', 'r', '_', 'V', '4', 0,
  /* 7511 */ 'A', 'D', 'D', 'r', '_', 'M', 'P', 'Y', 'r', 'r', '_', 'V', '4', 0,
  /* 7525 */ 'L', 'D', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'V', '4', 0,
  /* 7538 */ 'S', 'T', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'V', '4', 0,
  /* 7551 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'a', 'b', 's', '_', 'V', '4', 0,
  /* 7565 */ 'L', 'D', 'r', 'i', 'd', '_', 'a', 'b', 's', '_', 'V', '4', 0,
  /* 7578 */ 'S', 'T', 'r', 'i', 'd', '_', 'a', 'b', 's', '_', 'V', '4', 0,
  /* 7591 */ 'L', 'D', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'V', '4', 0,
  /* 7604 */ 'S', 'T', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'V', '4', 0,
  /* 7617 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'a', 'b', 's', '_', 'V', '4', 0,
  /* 7631 */ 'L', 'D', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'V', '4', 0,
  /* 7644 */ 'S', 'T', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'V', '4', 0,
  /* 7657 */ 'S', 'X', 'T', 'B', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7669 */ 'Z', 'X', 'T', 'B', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7681 */ 'A', 'S', 'L', 'H', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7693 */ 'A', 'S', 'R', 'H', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7705 */ 'S', 'X', 'T', 'H', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7717 */ 'Z', 'X', 'T', 'H', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7729 */ 'T', 'F', 'R', 'I', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7741 */ 'L', 'D', 'b', '_', 'G', 'P', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7755 */ 'S', 'T', 'b', '_', 'G', 'P', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7769 */ 'L', 'D', 'u', 'b', '_', 'G', 'P', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7784 */ 'L', 'D', 'd', '_', 'G', 'P', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7798 */ 'S', 'T', 'd', '_', 'G', 'P', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7812 */ 'L', 'D', 'h', '_', 'G', 'P', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7826 */ 'S', 'T', 'h', '_', 'G', 'P', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7840 */ 'L', 'D', 'u', 'h', '_', 'G', 'P', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7855 */ 'L', 'D', 'w', '_', 'G', 'P', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7869 */ 'S', 'T', 'w', '_', 'G', 'P', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7883 */ 'D', 'E', 'A', 'L', 'L', 'O', 'C', '_', 'R', 'E', 'T', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7902 */ 'L', 'D', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7927 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7952 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 7978 */ 'L', 'D', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8003 */ 'S', 'T', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8028 */ 'L', 'D', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8053 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8078 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8104 */ 'L', 'D', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8129 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8154 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'm', 'm', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8171 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'm', 'm', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8188 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'm', 'm', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8205 */ 'L', 'D', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8222 */ 'S', 'T', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8239 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'a', 'b', 's', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8257 */ 'L', 'D', 'r', 'i', 'd', '_', 'a', 'b', 's', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8274 */ 'S', 'T', 'r', 'i', 'd', '_', 'a', 'b', 's', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8291 */ 'L', 'D', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8308 */ 'S', 'T', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8325 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'a', 'b', 's', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8343 */ 'L', 'D', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8360 */ 'S', 'T', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'c', 'P', 't', '_', 'V', '4', 0,
  /* 8377 */ 'S', 'X', 'T', 'B', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8391 */ 'Z', 'X', 'T', 'B', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8405 */ 'A', 'S', 'L', 'H', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8419 */ 'A', 'S', 'R', 'H', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8433 */ 'S', 'X', 'T', 'H', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8447 */ 'Z', 'X', 'T', 'H', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8461 */ 'T', 'F', 'R', 'I', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8475 */ 'L', 'D', 'b', '_', 'G', 'P', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8491 */ 'S', 'T', 'b', '_', 'G', 'P', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8507 */ 'L', 'D', 'u', 'b', '_', 'G', 'P', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8524 */ 'L', 'D', 'd', '_', 'G', 'P', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8540 */ 'S', 'T', 'd', '_', 'G', 'P', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8556 */ 'L', 'D', 'h', '_', 'G', 'P', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8572 */ 'S', 'T', 'h', '_', 'G', 'P', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8588 */ 'L', 'D', 'u', 'h', '_', 'G', 'P', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8605 */ 'L', 'D', 'w', '_', 'G', 'P', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8621 */ 'S', 'T', 'w', '_', 'G', 'P', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8637 */ 'D', 'E', 'A', 'L', 'L', 'O', 'C', '_', 'R', 'E', 'T', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8658 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'b', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8678 */ 'S', 'T', 'r', 'i', 'b', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8693 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'u', 'b', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8714 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8737 */ 'S', 'T', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8760 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8783 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8806 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'd', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8826 */ 'S', 'T', 'r', 'i', 'd', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8841 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'h', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8861 */ 'S', 'T', 'r', 'i', 'h', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8876 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'u', 'h', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8897 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'b', 'r', 'i', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8917 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'd', 'r', 'i', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8937 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'h', 'r', 'i', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8957 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'w', 'r', 'i', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 8977 */ 'L', 'D', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9004 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9031 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9059 */ 'L', 'D', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9086 */ 'S', 'T', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9113 */ 'L', 'D', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9140 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9167 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9195 */ 'L', 'D', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9222 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9249 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'm', 'm', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9268 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'm', 'm', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9287 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'm', 'm', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9306 */ 'L', 'D', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9325 */ 'S', 'T', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9344 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9364 */ 'L', 'D', 'r', 'i', 'd', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9383 */ 'S', 'T', 'r', 'i', 'd', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9402 */ 'L', 'D', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9421 */ 'S', 'T', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9440 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9460 */ 'L', 'D', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9479 */ 'S', 'T', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9498 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'w', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9518 */ 'S', 'T', 'r', 'i', 'w', '_', 'c', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9533 */ 'D', 'E', 'A', 'L', 'L', 'O', 'C', '_', 'R', 'E', 'T', '_', 'c', 'N', 'o', 't', 'd', 'n', 'P', 't', '_', 'V', '4', 0,
  /* 9557 */ 'S', 'X', 'T', 'B', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9572 */ 'Z', 'X', 'T', 'B', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9587 */ 'A', 'S', 'L', 'H', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9602 */ 'A', 'S', 'R', 'H', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9617 */ 'S', 'X', 'T', 'H', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9632 */ 'Z', 'X', 'T', 'H', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9647 */ 'T', 'F', 'R', 'I', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9662 */ 'L', 'D', 'b', '_', 'G', 'P', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9679 */ 'S', 'T', 'b', '_', 'G', 'P', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9696 */ 'L', 'D', 'u', 'b', '_', 'G', 'P', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9714 */ 'L', 'D', 'd', '_', 'G', 'P', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9731 */ 'S', 'T', 'd', '_', 'G', 'P', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9748 */ 'L', 'D', 'h', '_', 'G', 'P', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9765 */ 'S', 'T', 'h', '_', 'G', 'P', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9782 */ 'L', 'D', 'u', 'h', '_', 'G', 'P', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9800 */ 'L', 'D', 'w', '_', 'G', 'P', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9817 */ 'S', 'T', 'w', '_', 'G', 'P', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9834 */ 'D', 'E', 'A', 'L', 'L', 'O', 'C', '_', 'R', 'E', 'T', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9856 */ 'L', 'D', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9884 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9912 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9941 */ 'L', 'D', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9969 */ 'S', 'T', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 9997 */ 'L', 'D', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10025 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10053 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10082 */ 'L', 'D', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10110 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10138 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'm', 'm', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10158 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'm', 'm', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10178 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'm', 'm', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10198 */ 'L', 'D', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10218 */ 'S', 'T', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10238 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'a', 'b', 's', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10259 */ 'L', 'D', 'r', 'i', 'd', '_', 'a', 'b', 's', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10279 */ 'S', 'T', 'r', 'i', 'd', '_', 'a', 'b', 's', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10299 */ 'L', 'D', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10319 */ 'S', 'T', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10339 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'a', 'b', 's', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10360 */ 'L', 'D', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10380 */ 'S', 'T', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10400 */ 'S', 'X', 'T', 'B', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10417 */ 'Z', 'X', 'T', 'B', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10434 */ 'A', 'S', 'L', 'H', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10451 */ 'A', 'S', 'R', 'H', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10468 */ 'S', 'X', 'T', 'H', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10485 */ 'Z', 'X', 'T', 'H', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10502 */ 'T', 'F', 'R', 'I', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10519 */ 'L', 'D', 'b', '_', 'G', 'P', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10538 */ 'S', 'T', 'b', '_', 'G', 'P', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10557 */ 'L', 'D', 'u', 'b', '_', 'G', 'P', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10577 */ 'L', 'D', 'd', '_', 'G', 'P', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10596 */ 'S', 'T', 'd', '_', 'G', 'P', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10615 */ 'L', 'D', 'h', '_', 'G', 'P', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10634 */ 'S', 'T', 'h', '_', 'G', 'P', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10653 */ 'L', 'D', 'u', 'h', '_', 'G', 'P', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10673 */ 'L', 'D', 'w', '_', 'G', 'P', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10692 */ 'S', 'T', 'w', '_', 'G', 'P', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10711 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'b', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10734 */ 'S', 'T', 'r', 'i', 'b', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10752 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'u', 'b', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10776 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10802 */ 'S', 'T', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10828 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10854 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10880 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10903 */ 'S', 'T', 'r', 'i', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10921 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'h', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10944 */ 'S', 'T', 'r', 'i', 'h', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10962 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'u', 'h', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 10986 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'b', 'r', 'i', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11009 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'd', 'r', 'i', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11032 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'h', 'r', 'i', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11055 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'w', 'r', 'i', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11078 */ 'L', 'D', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11108 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11138 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11169 */ 'L', 'D', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11199 */ 'S', 'T', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11229 */ 'L', 'D', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11259 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11289 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11320 */ 'L', 'D', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11350 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11380 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'm', 'm', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11402 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'm', 'm', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11424 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'm', 'm', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11446 */ 'L', 'D', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11468 */ 'S', 'T', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11490 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11513 */ 'L', 'D', 'r', 'i', 'd', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11535 */ 'S', 'T', 'r', 'i', 'd', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11557 */ 'L', 'D', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11579 */ 'S', 'T', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11601 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11624 */ 'L', 'D', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11646 */ 'S', 'T', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11668 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'w', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11691 */ 'S', 'T', 'r', 'i', 'w', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'V', '4', 0,
  /* 11709 */ 'T', 'S', 'T', 'B', 'I', 'T', '0', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 11731 */ 'C', 'M', 'P', 'E', 'Q', 'n', '1', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 11753 */ 'C', 'M', 'P', 'G', 'T', 'n', '1', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 11775 */ 'C', 'M', 'P', 'E', 'Q', 'r', 'i', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 11797 */ 'C', 'M', 'P', 'G', 'T', 'r', 'i', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 11819 */ 'C', 'M', 'P', 'G', 'T', 'U', 'r', 'i', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 11842 */ 'C', 'M', 'P', 'E', 'Q', 'r', 'r', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 11864 */ 'C', 'M', 'P', 'G', 'T', 'r', 'r', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 11886 */ 'C', 'M', 'P', 'L', 'T', 'r', 'r', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 11908 */ 'C', 'M', 'P', 'G', 'T', 'U', 'r', 'r', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 11931 */ 'C', 'M', 'P', 'L', 'T', 'U', 'r', 'r', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 11954 */ 'T', 'S', 'T', 'B', 'I', 'T', '0', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 11976 */ 'C', 'M', 'P', 'E', 'Q', 'n', '1', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 11998 */ 'C', 'M', 'P', 'G', 'T', 'n', '1', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 12020 */ 'C', 'M', 'P', 'E', 'Q', 'r', 'i', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 12042 */ 'C', 'M', 'P', 'G', 'T', 'r', 'i', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 12064 */ 'C', 'M', 'P', 'G', 'T', 'U', 'r', 'i', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 12087 */ 'C', 'M', 'P', 'E', 'Q', 'r', 'r', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 12109 */ 'C', 'M', 'P', 'G', 'T', 'r', 'r', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 12131 */ 'C', 'M', 'P', 'L', 'T', 'r', 'r', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 12153 */ 'C', 'M', 'P', 'G', 'T', 'U', 'r', 'r', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 12176 */ 'C', 'M', 'P', 'L', 'T', 'U', 'r', 'r', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 't', '_', 'V', '4', 0,
  /* 12199 */ 'L', 'D', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 's', 'e', 't', '_', 'V', '4', 0,
  /* 12216 */ 'S', 'T', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 's', 'e', 't', '_', 'V', '4', 0,
  /* 12233 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'a', 'b', 's', '_', 's', 'e', 't', '_', 'V', '4', 0,
  /* 12251 */ 'L', 'D', 'r', 'i', 'd', '_', 'a', 'b', 's', '_', 's', 'e', 't', '_', 'V', '4', 0,
  /* 12268 */ 'S', 'T', 'r', 'i', 'd', '_', 'a', 'b', 's', '_', 's', 'e', 't', '_', 'V', '4', 0,
  /* 12285 */ 'L', 'D', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 's', 'e', 't', '_', 'V', '4', 0,
  /* 12302 */ 'S', 'T', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 's', 'e', 't', '_', 'V', '4', 0,
  /* 12319 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'a', 'b', 's', '_', 's', 'e', 't', '_', 'V', '4', 0,
  /* 12337 */ 'L', 'D', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 's', 'e', 't', '_', 'V', '4', 0,
  /* 12354 */ 'S', 'T', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 's', 'e', 't', '_', 'V', '4', 0,
  /* 12371 */ 'D', 'E', 'A', 'L', 'L', 'O', 'C', '_', 'R', 'E', 'T', '_', 'c', 'd', 'n', 'P', 'n', 't', '_', 'V', '4', 0,
  /* 12393 */ 'D', 'E', 'A', 'L', 'L', 'O', 'C', '_', 'R', 'E', 'T', '_', 'c', 'N', 'o', 't', 'd', 'n', 'P', 'n', 't', '_', 'V', '4', 0,
  /* 12418 */ 'T', 'S', 'T', 'B', 'I', 'T', '0', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12441 */ 'C', 'M', 'P', 'E', 'Q', 'n', '1', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12464 */ 'C', 'M', 'P', 'G', 'T', 'n', '1', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12487 */ 'C', 'M', 'P', 'E', 'Q', 'r', 'i', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12510 */ 'C', 'M', 'P', 'G', 'T', 'r', 'i', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12533 */ 'C', 'M', 'P', 'G', 'T', 'U', 'r', 'i', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12557 */ 'C', 'M', 'P', 'E', 'Q', 'r', 'r', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12580 */ 'C', 'M', 'P', 'G', 'T', 'r', 'r', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12603 */ 'C', 'M', 'P', 'L', 'T', 'r', 'r', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12626 */ 'C', 'M', 'P', 'G', 'T', 'U', 'r', 'r', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12650 */ 'C', 'M', 'P', 'L', 'T', 'U', 'r', 'r', '_', 'f', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12674 */ 'T', 'S', 'T', 'B', 'I', 'T', '0', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12697 */ 'C', 'M', 'P', 'E', 'Q', 'n', '1', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12720 */ 'C', 'M', 'P', 'G', 'T', 'n', '1', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12743 */ 'C', 'M', 'P', 'E', 'Q', 'r', 'i', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12766 */ 'C', 'M', 'P', 'G', 'T', 'r', 'i', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12789 */ 'C', 'M', 'P', 'G', 'T', 'U', 'r', 'i', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12813 */ 'C', 'M', 'P', 'E', 'Q', 'r', 'r', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12836 */ 'C', 'M', 'P', 'G', 'T', 'r', 'r', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12859 */ 'C', 'M', 'P', 'L', 'T', 'r', 'r', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12882 */ 'C', 'M', 'P', 'G', 'T', 'U', 'r', 'r', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12906 */ 'C', 'M', 'P', 'L', 'T', 'U', 'r', 'r', '_', 't', '_', 'J', 'u', 'm', 'p', 'n', 'v', '_', 'n', 't', '_', 'V', '4', 0,
  /* 12930 */ 'S', 'T', 'r', 'i', 'h', '_', 'o', 'f', 'f', 's', 'e', 't', '_', 'e', 'x', 't', '_', 'V', '4', 0,
  /* 12950 */ 'S', 'T', 'r', 'i', 'w', '_', 'o', 'f', 'f', 's', 'e', 't', '_', 'e', 'x', 't', '_', 'V', '4', 0,
  /* 12970 */ 'T', 'F', 'R', '_', 'F', 'I', '_', 'i', 'm', 'm', 'e', 'x', 't', '_', 'V', '4', 0,
  /* 12987 */ 'S', 'T', 'b', '_', 'G', 'P', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13000 */ 'S', 'T', 'h', '_', 'G', 'P', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13013 */ 'S', 'T', 'w', '_', 'G', 'P', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13026 */ 'S', 'T', 'r', 'i', 'b', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13038 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13058 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13078 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13098 */ 'S', 'T', 'r', 'i', 'h', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13110 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'b', 'r', 'i', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13127 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'h', 'r', 'i', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13144 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'w', 'r', 'i', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13161 */ 'S', 'T', 'r', 'i', 'b', '_', 's', 'h', 'l', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13177 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13201 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13225 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13249 */ 'S', 'T', 'r', 'i', 'h', '_', 's', 'h', 'l', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13265 */ 'S', 'T', 'r', 'i', 'w', '_', 's', 'h', 'l', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13281 */ 'S', 'T', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13297 */ 'S', 'T', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13313 */ 'S', 'T', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13329 */ 'S', 'T', 'b', '_', 'G', 'P', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13346 */ 'S', 'T', 'h', '_', 'G', 'P', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13363 */ 'S', 'T', 'w', '_', 'G', 'P', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13380 */ 'S', 'T', 'r', 'i', 'b', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13396 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13420 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13444 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13468 */ 'S', 'T', 'r', 'i', 'h', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13484 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'b', 'r', 'i', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13505 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'h', 'r', 'i', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13526 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'w', 'r', 'i', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13547 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13575 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13603 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13631 */ 'S', 'T', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13651 */ 'S', 'T', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13671 */ 'S', 'T', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13691 */ 'S', 'T', 'r', 'i', 'w', '_', 'c', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13707 */ 'S', 'T', 'b', '_', 'G', 'P', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13726 */ 'S', 'T', 'h', '_', 'G', 'P', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13745 */ 'S', 'T', 'w', '_', 'G', 'P', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13764 */ 'S', 'T', 'r', 'i', 'b', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13782 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13808 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13834 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13860 */ 'S', 'T', 'r', 'i', 'h', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13878 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'b', 'r', 'i', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13901 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'h', 'r', 'i', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13924 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'w', 'r', 'i', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13947 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 13977 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14007 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14037 */ 'S', 'T', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14059 */ 'S', 'T', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14081 */ 'S', 'T', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14103 */ 'S', 'T', 'r', 'i', 'w', '_', 'c', 'd', 'n', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14121 */ 'S', 'T', 'b', '_', 'G', 'P', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14141 */ 'S', 'T', 'h', '_', 'G', 'P', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14161 */ 'S', 'T', 'w', '_', 'G', 'P', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14181 */ 'S', 'T', 'r', 'i', 'b', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14200 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14227 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14254 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14281 */ 'S', 'T', 'r', 'i', 'h', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14300 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'b', 'r', 'i', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14324 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'h', 'r', 'i', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14348 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'w', 'r', 'i', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14372 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14403 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14434 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14465 */ 'S', 'T', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14488 */ 'S', 'T', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14511 */ 'S', 'T', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14534 */ 'S', 'T', 'r', 'i', 'w', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14553 */ 'S', 'T', 'b', '_', 'G', 'P', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14575 */ 'S', 'T', 'h', '_', 'G', 'P', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14597 */ 'S', 'T', 'w', '_', 'G', 'P', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14619 */ 'S', 'T', 'r', 'i', 'b', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14640 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14669 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14698 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14727 */ 'S', 'T', 'r', 'i', 'h', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14748 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'b', 'r', 'i', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14774 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'h', 'r', 'i', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14800 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'w', 'r', 'i', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14826 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14859 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14892 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 's', 'h', 'l', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14925 */ 'S', 'T', 'r', 'i', 'b', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14950 */ 'S', 'T', 'r', 'i', 'h', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 14975 */ 'S', 'T', 'r', 'i', 'w', '_', 'a', 'b', 's', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 15000 */ 'S', 'T', 'r', 'i', 'w', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 15021 */ 'S', 'T', 'r', 'i', 'w', '_', 'n', 'v', '_', 'V', '4', 0,
  /* 15033 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'a', 'l', 'l', '8', 0,
  /* 15049 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'a', 'n', 'y', '8', 0,
  /* 15065 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '4', '_', 'f', 'a', 's', 't', 'c', 'o', 'r', 'n', 'e', 'r', '9', 0,
  /* 15088 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'f', 'a', 's', 't', 'c', 'o', 'r', 'n', 'e', 'r', '9', 0,
  /* 15111 */ 'S', 'X', 'T', 'B', 0,
  /* 15116 */ 'Z', 'X', 'T', 'B', 0,
  /* 15121 */ 'A', 'D', 'J', 'D', 'Y', 'N', 'A', 'L', 'L', 'O', 'C', 0,
  /* 15133 */ 'A', 'R', 'G', 'E', 'X', 'T', 'E', 'N', 'D', 0,
  /* 15143 */ 'L', 'I', 'F', 'E', 'T', 'I', 'M', 'E', '_', 'E', 'N', 'D', 0,
  /* 15156 */ 'R', 'E', 'G', '_', 'S', 'E', 'Q', 'U', 'E', 'N', 'C', 'E', 0,
  /* 15169 */ 'B', 'U', 'N', 'D', 'L', 'E', 0,
  /* 15176 */ 'D', 'E', 'A', 'L', 'L', 'O', 'C', 'F', 'R', 'A', 'M', 'E', 0,
  /* 15189 */ 'D', 'B', 'G', '_', 'V', 'A', 'L', 'U', 'E', 0,
  /* 15199 */ 'I', 'M', 'P', 'L', 'I', 'C', 'I', 'T', '_', 'D', 'E', 'F', 0,
  /* 15212 */ 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'S', 'U', 'B', 'R', 'E', 'G', 0,
  /* 15227 */ 'I', 'N', 'S', 'E', 'R', 'T', '_', 'S', 'U', 'B', 'R', 'E', 'G', 0,
  /* 15241 */ 'S', 'U', 'B', 'R', 'E', 'G', '_', 'T', 'O', '_', 'R', 'E', 'G', 0,
  /* 15255 */ 'A', 'S', 'L', 'H', 0,
  /* 15260 */ 'A', 'S', 'R', 'H', 0,
  /* 15265 */ 'S', 'X', 'T', 'H', 0,
  /* 15270 */ 'Z', 'X', 'T', 'H', 0,
  /* 15275 */ 'T', 'F', 'R', '_', 'F', 'I', 0,
  /* 15282 */ 'P', 'H', 'I', 0,
  /* 15286 */ 'T', 'F', 'R', 'I', 0,
  /* 15291 */ 'M', 'P', 'Y', 'I', 0,
  /* 15296 */ 'G', 'C', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 15305 */ 'P', 'R', 'O', 'L', 'O', 'G', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 15318 */ 'E', 'H', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 15327 */ 'C', 'A', 'L', 'L', 0,
  /* 15332 */ 'K', 'I', 'L', 'L', 0,
  /* 15337 */ 'A', 'D', 'D', 'A', 'S', 'L', 0,
  /* 15344 */ 'I', 'N', 'L', 'I', 'N', 'E', 'A', 'S', 'M', 0,
  /* 15354 */ 'A', 'D', 'J', 'C', 'A', 'L', 'L', 'S', 'T', 'A', 'C', 'K', 'D', 'O', 'W', 'N', 0,
  /* 15371 */ 'L', 'O', 0,
  /* 15374 */ 'S', 'T', 'A', 'C', 'K', 'M', 'A', 'P', 0,
  /* 15383 */ 'J', 'M', 'P', 0,
  /* 15387 */ 'N', 'O', 'P', 0,
  /* 15391 */ 'A', 'D', 'J', 'C', 'A', 'L', 'L', 'S', 'T', 'A', 'C', 'K', 'U', 'P', 0,
  /* 15406 */ 'T', 'F', 'C', 'R', 0,
  /* 15411 */ 'B', 'A', 'R', 'R', 'I', 'E', 'R', 0,
  /* 15419 */ 'T', 'F', 'R', 0,
  /* 15423 */ 'C', 'A', 'L', 'L', 'R', 0,
  /* 15429 */ 'T', 'C', 'R', 'E', 'T', 'U', 'R', 'N', 'R', 0,
  /* 15439 */ 'E', 'H', '_', 'R', 'E', 'T', 'U', 'R', 'N', '_', 'J', 'M', 'P', 'R', 0,
  /* 15454 */ 'C', 'O', 'P', 'Y', '_', 'T', 'O', '_', 'R', 'E', 'G', 'C', 'L', 'A', 'S', 'S', 0,
  /* 15471 */ 'T', 'O', 'G', 'B', 'I', 'T', 0,
  /* 15478 */ 'C', 'L', 'R', 'B', 'I', 'T', 0,
  /* 15485 */ 'S', 'E', 'T', 'B', 'I', 'T', 0,
  /* 15492 */ 'P', 'A', 'T', 'C', 'H', 'P', 'O', 'I', 'N', 'T', 0,
  /* 15503 */ 'L', 'I', 'F', 'E', 'T', 'I', 'M', 'E', '_', 'S', 'T', 'A', 'R', 'T', 0,
  /* 15518 */ 'M', 'P', 'Y', 'U', 0,
  /* 15523 */ 'S', 'X', 'T', 'W', 0,
  /* 15528 */ 'M', 'P', 'Y', 0,
  /* 15532 */ 'C', 'O', 'P', 'Y', 0,
  /* 15537 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'f', 'm', 'a', 0,
  /* 15554 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'f', 'm', 'a', 0,
  /* 15571 */ 'F', 'C', 'O', 'N', 'S', 'T', '3', '2', '_', 'n', 's', 'd', 'a', 't', 'a', 0,
  /* 15587 */ 'I', 'M', 'M', 'E', 'X', 'T', '_', 'b', 0,
  /* 15596 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 's', 'h', 'u', 'f', 'f', 'e', 'b', 0,
  /* 15615 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 't', 'r', 'u', 'n', 'e', 'h', 'b', 0,
  /* 15635 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 't', 'r', 'u', 'n', 'o', 'h', 'b', 0,
  /* 15655 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 's', 'a', 't', 'h', 'b', 0,
  /* 15673 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 's', 'v', 's', 'a', 't', 'h', 'b', 0,
  /* 15692 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 'v', 's', 'p', 'l', 'i', 'c', 'e', 'i', 'b', 0,
  /* 15713 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'f', 'm', 'a', '_', 'l', 'i', 'b', 0,
  /* 15734 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'f', 'm', 'a', '_', 'l', 'i', 'b', 0,
  /* 15755 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'f', 'm', 's', '_', 'l', 'i', 'b', 0,
  /* 15776 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'f', 'm', 's', '_', 'l', 'i', 'b', 0,
  /* 15797 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 'a', 'l', 'i', 'g', 'n', 'i', 'b', 0,
  /* 15817 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'b', 0,
  /* 15828 */ 'S', 'T', 'r', 'i', 'b', 0,
  /* 15834 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'c', 'l', 'b', 0,
  /* 15849 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 's', 'h', 'u', 'f', 'f', 'o', 'b', 0,
  /* 15868 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 'v', 's', 'p', 'l', 'i', 'c', 'e', 'r', 'b', 0,
  /* 15889 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 'a', 'l', 'i', 'g', 'n', 'r', 'b', 0,
  /* 15909 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 's', 'p', 'l', 'a', 't', 'r', 'b', 0,
  /* 15929 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'a', 't', 'b', 0,
  /* 15945 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'x', 't', 'b', 0,
  /* 15961 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'z', 'x', 't', 'b', 0,
  /* 15977 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 's', 'u', 'b', 'u', 'b', 0,
  /* 15995 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'r', 's', 'a', 'd', 'u', 'b', 0,
  /* 16014 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'r', 'a', 'd', 'd', 'u', 'b', 0,
  /* 16033 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'd', 'd', 'u', 'b', 0,
  /* 16051 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'v', 'g', 'u', 'b', 0,
  /* 16069 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 's', 'a', 't', 'h', 'u', 'b', 0,
  /* 16088 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 's', 'v', 's', 'a', 't', 'h', 'u', 'b', 0,
  /* 16108 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'u', 'b', 0,
  /* 16120 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'm', 'i', 'n', 'u', 'b', 0,
  /* 16138 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 0,
  /* 16153 */ 'M', 'P', 'Y', 'U', '6', '4', '_', 's', 'u', 'b', 0,
  /* 16164 */ 'M', 'P', 'Y', '6', '4', '_', 's', 'u', 'b', 0,
  /* 16174 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 's', 'u', 'b', 0,
  /* 16191 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 's', 'u', 'b', 0,
  /* 16208 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'a', 't', 'u', 'b', 0,
  /* 16225 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'm', 'a', 'x', 'u', 'b', 0,
  /* 16243 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'r', 'c', 'm', 'a', 'c', 'i', '_', 's', '0', 'c', 0,
  /* 16266 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'r', 'c', 'm', 'p', 'y', 'i', '_', 's', '0', 'c', 0,
  /* 16289 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'r', 'c', 'm', 'a', 'c', 'r', '_', 's', '0', 'c', 0,
  /* 16312 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'r', 'c', 'm', 'p', 'y', 'r', '_', 's', '0', 'c', 0,
  /* 16335 */ 'I', 'M', 'M', 'E', 'X', 'T', '_', 'c', 0,
  /* 16344 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'p', '_', 'n', 'a', 'c', 0,
  /* 16367 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'p', '_', 'n', 'a', 'c', 0,
  /* 16390 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'p', '_', 'n', 'a', 'c', 0,
  /* 16413 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'r', '_', 'p', '_', 'n', 'a', 'c', 0,
  /* 16436 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'l', '_', 'r', '_', 'p', '_', 'n', 'a', 'c', 0,
  /* 16459 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 'p', '_', 'n', 'a', 'c', 0,
  /* 16482 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'r', '_', 'p', '_', 'n', 'a', 'c', 0,
  /* 16505 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'r', '_', 'n', 'a', 'c', 0,
  /* 16528 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'r', '_', 'n', 'a', 'c', 0,
  /* 16551 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'r', '_', 'n', 'a', 'c', 0,
  /* 16574 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'r', '_', 'r', '_', 'n', 'a', 'c', 0,
  /* 16597 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'l', '_', 'r', '_', 'r', '_', 'n', 'a', 'c', 0,
  /* 16620 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 'r', '_', 'n', 'a', 'c', 0,
  /* 16643 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'r', '_', 'r', '_', 'n', 'a', 'c', 0,
  /* 16666 */ 'M', 'P', 'Y', 'U', '6', '4', '_', 'a', 'c', 'c', 0,
  /* 16677 */ 'M', 'P', 'Y', '6', '4', '_', 'a', 'c', 'c', 0,
  /* 16687 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'r', 's', 'a', 'd', 'u', 'b', '_', 'a', 'c', 'c', 0,
  /* 16710 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'r', 'a', 'd', 'd', 'u', 'b', '_', 'a', 'c', 'c', 0,
  /* 16733 */ 'S', 'U', 'B', 'r', 'i', '_', 'a', 'c', 'c', 0,
  /* 16743 */ 'A', 'D', 'D', 'r', 'i', '_', 'a', 'c', 'c', 0,
  /* 16753 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'p', '_', 'a', 'c', 'c', 0,
  /* 16776 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'p', '_', 'a', 'c', 'c', 0,
  /* 16799 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'p', '_', 'a', 'c', 'c', 0,
  /* 16822 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'r', '_', 'p', '_', 'a', 'c', 'c', 0,
  /* 16845 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'l', '_', 'r', '_', 'p', '_', 'a', 'c', 'c', 0,
  /* 16868 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 'p', '_', 'a', 'c', 'c', 0,
  /* 16891 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'r', '_', 'p', '_', 'a', 'c', 'c', 0,
  /* 16914 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'r', '_', 'a', 'c', 'c', 0,
  /* 16937 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'r', '_', 'a', 'c', 'c', 0,
  /* 16960 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'r', '_', 'a', 'c', 'c', 0,
  /* 16983 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'r', '_', 'r', '_', 'a', 'c', 'c', 0,
  /* 17006 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'l', '_', 'r', '_', 'r', '_', 'a', 'c', 'c', 0,
  /* 17029 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 'r', '_', 'a', 'c', 'c', 0,
  /* 17052 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'r', '_', 'r', '_', 'a', 'c', 'c', 0,
  /* 17075 */ 'S', 'U', 'B', 'r', 'r', '_', 'a', 'c', 'c', 0,
  /* 17085 */ 'A', 'D', 'D', 'r', 'r', '_', 'a', 'c', 'c', 0,
  /* 17095 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 's', 'u', 'b', 'a', 'c', 'c', 0,
  /* 17113 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'p', '_', 'x', 'a', 'c', 'c', 0,
  /* 17137 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'p', '_', 'x', 'a', 'c', 'c', 0,
  /* 17161 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'r', '_', 'x', 'a', 'c', 'c', 0,
  /* 17185 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'r', '_', 'x', 'a', 'c', 'c', 0,
  /* 17209 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'x', 'o', 'r', '_', 'x', 'a', 'c', 'c', 0,
  /* 17229 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'M', '4', '_', 'x', 'o', 'r', '_', 'x', 'a', 'c', 'c', 0,
  /* 17249 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'f', 'm', 'a', '_', 's', 'c', 0,
  /* 17269 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'f', 'm', 'a', '_', 's', 'c', 0,
  /* 17289 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'd', 'f', '2', 'd', 0,
  /* 17302 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'd', 'f', '2', 'd', 0,
  /* 17323 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 's', 'f', '2', 'd', 0,
  /* 17336 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 's', 'f', '2', 'd', 0,
  /* 17357 */ 'A', 'S', 'L', 'd', 0,
  /* 17362 */ 'L', 'S', 'L', 'd', 0,
  /* 17367 */ 'T', 'F', 'R', '_', 'R', 's', 'P', 'd', 0,
  /* 17376 */ 'X', 'O', 'R', 'd', '_', 'X', 'O', 'R', 'd', 'd', 0,
  /* 17387 */ 'M', 'I', 'N', 'w', '_', 'd', 'd', 0,
  /* 17395 */ 'M', 'A', 'X', 'w', '_', 'd', 'd', 0,
  /* 17403 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 0,
  /* 17418 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'a', 'd', 'd', 0,
  /* 17435 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'a', 'd', 'd', 0,
  /* 17452 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'c', 'i', 'r', 'c', '_', 'l', 'd', 'd', 0,
  /* 17469 */ 'L', 'D', 'r', 'i', 'w', '_', 'p', 'r', 'e', 'd', 0,
  /* 17480 */ 'S', 'T', 'r', 'i', 'w', '_', 'p', 'r', 'e', 'd', 0,
  /* 17491 */ 'L', 'D', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', 0,
  /* 17505 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', 0,
  /* 17519 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', 0,
  /* 17534 */ 'L', 'D', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', 0,
  /* 17548 */ 'S', 'T', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', 0,
  /* 17562 */ 'L', 'D', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', 0,
  /* 17576 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', 0,
  /* 17590 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', 0,
  /* 17605 */ 'L', 'D', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', 0,
  /* 17619 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', 0,
  /* 17633 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'd', 0,
  /* 17644 */ 'S', 'T', 'r', 'i', 'd', 0,
  /* 17650 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'n', 'd', 0,
  /* 17665 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'a', 'n', 'd', 0,
  /* 17680 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'a', 'n', 'd', '_', 'a', 'n', 'd', 0,
  /* 17699 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '4', '_', 'a', 'n', 'd', '_', 'a', 'n', 'd', 0,
  /* 17718 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'p', '_', 'a', 'n', 'd', 0,
  /* 17741 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'p', '_', 'a', 'n', 'd', 0,
  /* 17764 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'p', '_', 'a', 'n', 'd', 0,
  /* 17787 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'r', '_', 'p', '_', 'a', 'n', 'd', 0,
  /* 17810 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'l', '_', 'r', '_', 'p', '_', 'a', 'n', 'd', 0,
  /* 17833 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 'p', '_', 'a', 'n', 'd', 0,
  /* 17856 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'r', '_', 'p', '_', 'a', 'n', 'd', 0,
  /* 17879 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'r', '_', 'a', 'n', 'd', 0,
  /* 17902 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'r', '_', 'a', 'n', 'd', 0,
  /* 17925 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'r', '_', 'a', 'n', 'd', 0,
  /* 17948 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'r', '_', 'r', '_', 'a', 'n', 'd', 0,
  /* 17971 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'l', '_', 'r', '_', 'r', '_', 'a', 'n', 'd', 0,
  /* 17994 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 'r', '_', 'a', 'n', 'd', 0,
  /* 18017 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'r', '_', 'r', '_', 'a', 'n', 'd', 0,
  /* 18040 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'o', 'r', '_', 'a', 'n', 'd', 0,
  /* 18058 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '4', '_', 'o', 'r', '_', 'a', 'n', 'd', 0,
  /* 18076 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '4', '_', 'x', 'o', 'r', '_', 'a', 'n', 'd', 0,
  /* 18095 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'p', '_', 'r', 'n', 'd', 0,
  /* 18118 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'r', '_', 'r', 'n', 'd', 0,
  /* 18141 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'f', 'i', 'x', 'u', 'p', 'd', 0,
  /* 18161 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'f', 'i', 'x', 'u', 'p', 'd', 0,
  /* 18181 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'd', 'f', '2', 'u', 'd', 0,
  /* 18195 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'd', 'f', '2', 'u', 'd', 0,
  /* 18217 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 's', 'f', '2', 'u', 'd', 0,
  /* 18231 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 's', 'f', '2', 'u', 'd', 0,
  /* 18253 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'c', 'm', 'p', 'g', 'e', 0,
  /* 18272 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'c', 'm', 'p', 'g', 'e', 0,
  /* 18291 */ 'T', 'F', 'R', '_', 'P', 'd', 'F', 'a', 'l', 's', 'e', 0,
  /* 18303 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 'c', 'r', 'o', 't', 'a', 't', 'e', 0,
  /* 18323 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'c', 'm', 'p', 'l', 't', 'e', 0,
  /* 18341 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 'i', 'n', 't', 'e', 'r', 'l', 'e', 'a', 'v', 'e', 0,
  /* 18363 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 'd', 'e', 'i', 'n', 't', 'e', 'r', 'l', 'e', 'a', 'v', 'e', 0,
  /* 18387 */ 'T', 'F', 'R', '_', 'c', 'o', 'n', 'd', 's', 'e', 't', '_', 'r', 'r', '6', '4', '_', 'f', 0,
  /* 18406 */ 'T', 'F', 'R', 'I', '_', 'f', 0,
  /* 18413 */ 'J', 'M', 'P', '_', 'f', 0,
  /* 18419 */ 'J', 'M', 'P', 'R', '_', 'f', 0,
  /* 18426 */ 'L', 'D', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'f', 0,
  /* 18442 */ 'S', 'T', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'f', 0,
  /* 18458 */ 'L', 'D', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'f', 0,
  /* 18474 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'f', 0,
  /* 18490 */ 'L', 'D', 'r', 'i', 'd', '_', 'f', 0,
  /* 18498 */ 'S', 'T', 'r', 'i', 'd', '_', 'f', 0,
  /* 18506 */ 'T', 'F', 'R', '_', 'c', 'o', 'n', 'd', 's', 'e', 't', '_', 'i', 'i', '_', 'f', 0,
  /* 18523 */ 'T', 'F', 'R', '_', 'c', 'o', 'n', 'd', 's', 'e', 't', '_', 'r', 'i', '_', 'f', 0,
  /* 18540 */ 'T', 'F', 'R', '_', 'c', 'o', 'n', 'd', 's', 'e', 't', '_', 'i', 'r', '_', 'f', 0,
  /* 18557 */ 'T', 'F', 'R', '_', 'c', 'o', 'n', 'd', 's', 'e', 't', '_', 'r', 'r', '_', 'f', 0,
  /* 18574 */ 'T', 'F', 'R', 'I', '_', 'c', 'P', 't', '_', 'f', 0,
  /* 18585 */ 'T', 'F', 'R', 'I', '_', 'c', 'N', 'o', 't', 'P', 't', '_', 'f', 0,
  /* 18599 */ 'J', 'M', 'P', 'r', 'e', 't', '_', 'f', 0,
  /* 18608 */ 'L', 'D', 'r', 'i', 'w', '_', 'f', 0,
  /* 18616 */ 'S', 'T', 'r', 'i', 'w', '_', 'f', 0,
  /* 18624 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'd', '2', 'd', 'f', 0,
  /* 18637 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'd', '2', 'd', 'f', 0,
  /* 18658 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'u', 'd', '2', 'd', 'f', 0,
  /* 18672 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'u', 'd', '2', 'd', 'f', 0,
  /* 18694 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 's', 'f', '2', 'd', 'f', 0,
  /* 18708 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 's', 'f', '2', 'd', 'f', 0,
  /* 18730 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'w', '2', 'd', 'f', 0,
  /* 18743 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'w', '2', 'd', 'f', 0,
  /* 18764 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'u', 'w', '2', 'd', 'f', 0,
  /* 18778 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'u', 'w', '2', 'd', 'f', 0,
  /* 18800 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'd', '2', 's', 'f', 0,
  /* 18813 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'd', '2', 's', 'f', 0,
  /* 18834 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'u', 'd', '2', 's', 'f', 0,
  /* 18848 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'u', 'd', '2', 's', 'f', 0,
  /* 18870 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'd', 'f', '2', 's', 'f', 0,
  /* 18884 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'd', 'f', '2', 's', 'f', 0,
  /* 18906 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'w', '2', 's', 'f', 0,
  /* 18919 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'w', '2', 's', 'f', 0,
  /* 18940 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'u', 'w', '2', 's', 'f', 0,
  /* 18954 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'u', 'w', '2', 's', 'f', 0,
  /* 18976 */ 'I', 'M', 'M', 'E', 'X', 'T', '_', 'g', 0,
  /* 18985 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'n', 'e', 'g', 0,
  /* 19000 */ 'T', 'C', 'R', 'E', 'T', 'U', 'R', 'N', 't', 'g', 0,
  /* 19011 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 's', 'x', 't', 'b', 'h', 0,
  /* 19029 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 'z', 'x', 't', 'b', 'h', 0,
  /* 19047 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 's', 'u', 'b', 'h', 0,
  /* 19064 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'v', 's', 'u', 'b', 'h', 0,
  /* 19082 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'd', 'd', 'h', 0,
  /* 19099 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'v', 'a', 'd', 'd', 'h', 0,
  /* 19117 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 's', 'h', 'u', 'f', 'f', 'e', 'h', 0,
  /* 19136 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'a', 'b', 's', 'd', 'i', 'f', 'f', 'h', 0,
  /* 19157 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'n', 'a', 'v', 'g', 'h', 0,
  /* 19175 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'v', 'n', 'a', 'v', 'g', 'h', 0,
  /* 19194 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'v', 'g', 'h', 0,
  /* 19211 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'v', 'a', 'v', 'g', 'h', 0,
  /* 19229 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'h', '_', 'h', '1', '6', '_', 'h', 'h', 0,
  /* 19252 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'h', '_', 'h', '1', '6', '_', 'h', 'h', 0,
  /* 19275 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'c', 'o', 'm', 'b', 'i', 'n', 'e', '_', 'h', 'h', 0,
  /* 19297 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'h', '_', 'h', '1', '6', '_', 's', 'a', 't', '_', 'h', 'h', 0,
  /* 19324 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'h', '_', 'h', '1', '6', '_', 's', 'a', 't', '_', 'h', 'h', 0,
  /* 19351 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'h', 0,
  /* 19362 */ 'S', 'T', 'r', 'i', 'h', 0,
  /* 19368 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 't', 'f', 'r', 'i', 'h', 0,
  /* 19385 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'h', '_', 'h', '1', '6', '_', 'l', 'h', 0,
  /* 19408 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'h', '_', 'h', '1', '6', '_', 'l', 'h', 0,
  /* 19431 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'c', 'o', 'm', 'b', 'i', 'n', 'e', '_', 'l', 'h', 0,
  /* 19453 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'h', '_', 'h', '1', '6', '_', 's', 'a', 't', '_', 'l', 'h', 0,
  /* 19480 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'h', '_', 'h', '1', '6', '_', 's', 'a', 't', '_', 'l', 'h', 0,
  /* 19507 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 's', 'l', 'h', 0,
  /* 19523 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'm', 'i', 'n', 'h', 0,
  /* 19540 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 's', 'h', 'u', 'f', 'f', 'o', 'h', 0,
  /* 19559 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 's', 'r', 'h', 0,
  /* 19575 */ 'S', 'I', '_', 't', 'o', '_', 'S', 'X', 'T', 'H', 'I', '_', 'a', 's', 'r', 'h', 0,
  /* 19592 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 's', 'p', 'l', 'a', 't', 'r', 'h', 0,
  /* 19612 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'b', 's', 'h', 0,
  /* 19629 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'a', 't', 'h', 0,
  /* 19645 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'x', 't', 'h', 0,
  /* 19661 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'z', 'x', 't', 'h', 0,
  /* 19677 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'M', '2', '_', 'v', 'r', 'a', 'd', 'd', 'u', 'h', 0,
  /* 19696 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'v', 'g', 'u', 'h', 0,
  /* 19714 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'u', 'h', 0,
  /* 19726 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'm', 'i', 'n', 'u', 'h', 0,
  /* 19744 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'a', 't', 'u', 'h', 0,
  /* 19761 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 's', 'a', 't', 'w', 'u', 'h', 0,
  /* 19780 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'm', 'a', 'x', 'u', 'h', 0,
  /* 19798 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'v', 'h', 0,
  /* 19818 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'v', 'h', 0,
  /* 19838 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'v', 'h', 0,
  /* 19858 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'r', '_', 'v', 'h', 0,
  /* 19878 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'l', '_', 'r', '_', 'v', 'h', 0,
  /* 19898 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 'v', 'h', 0,
  /* 19918 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'r', '_', 'v', 'h', 0,
  /* 19938 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 't', 'r', 'u', 'n', 'e', 'w', 'h', 0,
  /* 19958 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 'r', 'n', 'd', 'p', 'a', 'c', 'k', 'w', 'h', 0,
  /* 19980 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 't', 'r', 'u', 'n', 'o', 'w', 'h', 0,
  /* 20000 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 's', 'a', 't', 'w', 'h', 0,
  /* 20018 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'm', 'a', 'x', 'h', 0,
  /* 20035 */ 'H', 'I', 'i', 0,
  /* 20039 */ 'C', 'O', 'M', 'B', 'I', 'N', 'E', '_', 'I', 'i', 0,
  /* 20050 */ 'L', 'O', 'i', 0,
  /* 20054 */ 'L', 'O', 'O', 'P', '0', '_', 'i', 0,
  /* 20062 */ 'I', 'M', 'M', 'E', 'X', 'T', '_', 'i', 0,
  /* 20071 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'c', 'm', 'a', 'c', '_', 's', '0', '_', 's', 'a', 't', '_', 'i', 0,
  /* 20097 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'c', 'm', 'p', 'y', '_', 's', '0', '_', 's', 'a', 't', '_', 'i', 0,
  /* 20123 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'c', 'm', 'p', 'y', '_', 's', '1', '_', 's', 'a', 't', '_', 'i', 0,
  /* 20149 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 't', 'o', 'g', 'g', 'l', 'e', 'b', 'i', 't', '_', 'i', 0,
  /* 20172 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'c', 'l', 'r', 'b', 'i', 't', '_', 'i', 0,
  /* 20192 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 's', 'e', 't', 'b', 'i', 't', '_', 'i', 0,
  /* 20212 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 't', 's', 't', 'b', 'i', 't', '_', 'i', 0,
  /* 20232 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'a', 'c', 'i', 0,
  /* 20248 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'a', 'c', 'c', 'i', 0,
  /* 20264 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'n', 'a', 'c', 'c', 'i', 0,
  /* 20281 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'i', 0,
  /* 20297 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '4', '_', 's', 'u', 'b', 'a', 'd', 'd', 'i', 0,
  /* 20316 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '4', '_', 'a', 'd', 'd', 'a', 'd', 'd', 'i', 0,
  /* 20335 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '4', '_', 'o', 'r', '_', 'a', 'n', 'd', 'i', 0,
  /* 20354 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'c', 'm', 'p', 'g', 'e', 'i', 0,
  /* 20372 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'c', 'm', 'p', 'l', 't', 'e', 'i', 0,
  /* 20391 */ 'C', 'O', 'M', 'B', 'I', 'N', 'E', '_', 'i', 'i', 0,
  /* 20402 */ 'M', 'U', 'X', '_', 'i', 'i', 0,
  /* 20409 */ 'T', 'F', 'R', '_', 'c', 'o', 'n', 'd', 's', 'e', 't', '_', 'i', 'i', 0,
  /* 20424 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'a', 'c', 'c', 'i', 'i', 0,
  /* 20441 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'n', 'a', 'c', 'c', 'i', 'i', 0,
  /* 20459 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'c', 'o', 'm', 'b', 'i', 'n', 'e', 'i', 'i', 0,
  /* 20480 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'm', 'u', 'x', 'i', 'i', 0,
  /* 20497 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'M', '2', '_', 'm', 'p', 'y', 's', 'm', 'i', 0,
  /* 20515 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 't', 'f', 'r', 'p', 'i', 0,
  /* 20532 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'c', 'm', 'p', 'n', 'e', 'q', 'i', 0,
  /* 20551 */ 'V', '4', '_', 'A', '4', '_', 'r', 'c', 'm', 'p', 'n', 'e', 'q', 'i', 0,
  /* 20566 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'A', '4', '_', 'r', 'c', 'm', 'p', 'n', 'e', 'q', 'i', 0,
  /* 20586 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'c', 'm', 'p', 'e', 'q', 'i', 0,
  /* 20604 */ 'V', '4', '_', 'A', '4', '_', 'r', 'c', 'm', 'p', 'e', 'q', 'i', 0,
  /* 20618 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'A', '4', '_', 'r', 'c', 'm', 'p', 'e', 'q', 'i', 0,
  /* 20637 */ 'C', 'M', 'P', 'E', 'Q', 'r', 'i', 0,
  /* 20645 */ 'C', 'M', 'P', 'G', 'T', 'r', 'i', 0,
  /* 20653 */ 'C', 'M', 'P', 'G', 'T', 'U', 'r', 'i', 0,
  /* 20662 */ 'A', 'S', 'L', '_', 'S', 'U', 'B', '_', 'r', 'i', 0,
  /* 20673 */ 'A', 'S', 'R', '_', 'S', 'U', 'B', '_', 'r', 'i', 0,
  /* 20684 */ 'L', 'S', 'R', '_', 'S', 'U', 'B', '_', 'r', 'i', 0,
  /* 20695 */ 'A', 'S', 'L', '_', 'A', 'D', 'D', '_', 'r', 'i', 0,
  /* 20706 */ 'A', 'S', 'R', '_', 'A', 'D', 'D', '_', 'r', 'i', 0,
  /* 20717 */ 'L', 'S', 'R', '_', 'A', 'D', 'D', '_', 'r', 'i', 0,
  /* 20728 */ 'A', 'S', 'L', '_', 'A', 'N', 'D', '_', 'r', 'i', 0,
  /* 20739 */ 'A', 'S', 'R', '_', 'A', 'N', 'D', '_', 'r', 'i', 0,
  /* 20750 */ 'L', 'S', 'R', '_', 'A', 'N', 'D', '_', 'r', 'i', 0,
  /* 20761 */ 'M', 'P', 'Y', 'I', '_', 'r', 'i', 0,
  /* 20769 */ 'C', 'M', 'P', 'n', 'o', 't', 'E', 'Q', '_', 'r', 'i', 0,
  /* 20781 */ 'A', 'S', 'L', '_', 'X', 'O', 'R', '_', 'r', 'i', 0,
  /* 20792 */ 'L', 'S', 'R', '_', 'X', 'O', 'R', '_', 'r', 'i', 0,
  /* 20803 */ 'A', 'S', 'L', '_', 'O', 'R', '_', 'r', 'i', 0,
  /* 20813 */ 'A', 'S', 'R', '_', 'O', 'R', '_', 'r', 'i', 0,
  /* 20823 */ 'L', 'S', 'R', '_', 'O', 'R', '_', 'r', 'i', 0,
  /* 20833 */ 'A', 'S', 'R', '_', 'r', 'i', 0,
  /* 20840 */ 'L', 'S', 'R', '_', 'r', 'i', 0,
  /* 20847 */ 'C', 'M', 'P', 'n', 'o', 't', 'G', 'T', '_', 'r', 'i', 0,
  /* 20859 */ 'N', 'T', 'S', 'T', 'B', 'I', 'T', '_', 'r', 'i', 0,
  /* 20870 */ 'C', 'M', 'P', 'n', 'o', 't', 'G', 'T', 'U', '_', 'r', 'i', 0,
  /* 20883 */ 'M', 'U', 'X', '_', 'r', 'i', 0,
  /* 20890 */ 'M', 'P', 'Y', 'I', '_', 's', 'u', 'b', '_', 'r', 'i', 0,
  /* 20902 */ 'M', 'P', 'Y', 'I', '_', 'a', 'c', 'c', '_', 'r', 'i', 0,
  /* 20914 */ 'A', 'S', 'L', '_', 'S', 'U', 'B', 'd', '_', 'r', 'i', 0,
  /* 20926 */ 'A', 'S', 'R', '_', 'S', 'U', 'B', 'd', '_', 'r', 'i', 0,
  /* 20938 */ 'L', 'S', 'R', '_', 'S', 'U', 'B', 'd', '_', 'r', 'i', 0,
  /* 20950 */ 'A', 'S', 'L', '_', 'A', 'D', 'D', 'd', '_', 'r', 'i', 0,
  /* 20962 */ 'A', 'S', 'R', '_', 'A', 'D', 'D', 'd', '_', 'r', 'i', 0,
  /* 20974 */ 'L', 'S', 'R', '_', 'A', 'D', 'D', 'd', '_', 'r', 'i', 0,
  /* 20986 */ 'A', 'S', 'L', '_', 'A', 'N', 'D', 'd', '_', 'r', 'i', 0,
  /* 20998 */ 'A', 'S', 'R', '_', 'A', 'N', 'D', 'd', '_', 'r', 'i', 0,
  /* 21010 */ 'L', 'S', 'R', '_', 'A', 'N', 'D', 'd', '_', 'r', 'i', 0,
  /* 21022 */ 'A', 'S', 'L', 'd', '_', 'r', 'i', 0,
  /* 21030 */ 'A', 'S', 'L', '_', 'X', 'O', 'R', 'd', '_', 'r', 'i', 0,
  /* 21042 */ 'L', 'S', 'R', '_', 'X', 'O', 'R', 'd', '_', 'r', 'i', 0,
  /* 21054 */ 'A', 'S', 'L', '_', 'O', 'R', 'd', '_', 'r', 'i', 0,
  /* 21065 */ 'A', 'S', 'R', '_', 'O', 'R', 'd', '_', 'r', 'i', 0,
  /* 21076 */ 'L', 'S', 'R', '_', 'O', 'R', 'd', '_', 'r', 'i', 0,
  /* 21087 */ 'A', 'S', 'R', 'd', '_', 'r', 'i', 0,
  /* 21095 */ 'L', 'S', 'R', 'd', '_', 'r', 'i', 0,
  /* 21103 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '4', '_', 'r', 'o', 'u', 'n', 'd', '_', 'r', 'i', 0,
  /* 21123 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '4', '_', 'c', 'r', 'o', 'u', 'n', 'd', '_', 'r', 'i', 0,
  /* 21144 */ 'T', 'F', 'R', '_', 'c', 'o', 'n', 'd', 's', 'e', 't', '_', 'r', 'i', 0,
  /* 21159 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'b', 'r', 'i', 0,
  /* 21170 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'r', 'i', 0,
  /* 21187 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'd', 'r', 'i', 0,
  /* 21198 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'A', '4', '_', 'c', 'o', 'm', 'b', 'i', 'n', 'e', 'r', 'i', 0,
  /* 21219 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'h', 'r', 'i', 0,
  /* 21230 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '2', '_', 'b', 'i', 't', 's', 'c', 'l', 'r', 'i', 0,
  /* 21250 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '4', '_', 'o', 'r', '_', 'o', 'r', 'i', 0,
  /* 21268 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 'd', 'd', 'a', 's', 'l', '_', 'r', 'r', 'r', 'i', 0,
  /* 21291 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'w', 'r', 'i', 0,
  /* 21302 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'm', 'u', 'x', 'r', 'i', 0,
  /* 21319 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 't', 'f', 'r', 's', 'i', 0,
  /* 21336 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'c', 'm', 'p', 'g', 't', 'i', 0,
  /* 21354 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'c', 'm', 'p', 'g', 'e', 'u', 'i', 0,
  /* 21373 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'c', 'm', 'p', 'l', 't', 'e', 'u', 'i', 0,
  /* 21393 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'c', 'm', 'p', 'g', 't', 'u', 'i', 0,
  /* 21412 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', 'i', 0,
  /* 21429 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'i', 0,
  /* 21445 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'c', 'o', 'n', 'j', 0,
  /* 21462 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'm', 'p', 'y', '2', 's', '_', 's', '0', 'p', 'a', 'c', 'k', 0,
  /* 21487 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'm', 'p', 'y', '2', 's', '_', 's', '1', 'p', 'a', 'c', 'k', 0,
  /* 21512 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 's', 'a', 't', 'h', 'b', '_', 'n', 'o', 'p', 'a', 'c', 'k', 0,
  /* 21537 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 's', 'a', 't', 'h', 'u', 'b', '_', 'n', 'o', 'p', 'a', 'c', 'k', 0,
  /* 21563 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 's', 'a', 't', 'w', 'u', 'h', '_', 'n', 'o', 'p', 'a', 'c', 'k', 0,
  /* 21589 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 's', 'a', 't', 'w', 'h', '_', 'n', 'o', 'p', 'a', 'c', 'k', 0,
  /* 21614 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'v', 'i', 't', 'p', 'a', 'c', 'k', 0,
  /* 21633 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'm', 'a', 's', 'k', 0,
  /* 21649 */ 'C', 'O', 'N', 'S', 'T', '3', '2', '_', 'F', 'l', 'o', 'a', 't', '_', 'R', 'e', 'a', 'l', 0,
  /* 21668 */ 'C', 'O', 'N', 'S', 'T', '6', '4', '_', 'F', 'l', 'o', 'a', 't', '_', 'R', 'e', 'a', 'l', 0,
  /* 21687 */ 'C', 'O', 'N', 'S', 'T', '3', '2', '_', 'I', 'n', 't', '_', 'R', 'e', 'a', 'l', 0,
  /* 21704 */ 'C', 'O', 'N', 'S', 'T', '6', '4', '_', 'I', 'n', 't', '_', 'R', 'e', 'a', 'l', 0,
  /* 21721 */ 'C', 'O', 'N', 'S', 'T', '3', '2', '_', 'L', 'a', 'b', 'e', 'l', 0,
  /* 21735 */ 'H', 'I', '_', 'l', 'a', 'b', 'e', 'l', 0,
  /* 21744 */ 'L', 'O', '_', 'l', 'a', 'b', 'e', 'l', 0,
  /* 21753 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'h', '_', 'h', '1', '6', '_', 'h', 'l', 0,
  /* 21776 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'h', '_', 'h', '1', '6', '_', 'h', 'l', 0,
  /* 21799 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'h', '_', 'l', '1', '6', '_', 'h', 'l', 0,
  /* 21822 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'h', '_', 'l', '1', '6', '_', 'h', 'l', 0,
  /* 21845 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'c', 'o', 'm', 'b', 'i', 'n', 'e', '_', 'h', 'l', 0,
  /* 21867 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'h', '_', 'h', '1', '6', '_', 's', 'a', 't', '_', 'h', 'l', 0,
  /* 21894 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'h', '_', 'h', '1', '6', '_', 's', 'a', 't', '_', 'h', 'l', 0,
  /* 21921 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'h', '_', 'l', '1', '6', '_', 's', 'a', 't', '_', 'h', 'l', 0,
  /* 21948 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'h', '_', 'l', '1', '6', '_', 's', 'a', 't', '_', 'h', 'l', 0,
  /* 21975 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'p', 'a', 'c', 'k', 'h', 'l', 0,
  /* 21993 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 't', 'f', 'r', 'i', 'l', 0,
  /* 22010 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'h', '_', 'h', '1', '6', '_', 'l', 'l', 0,
  /* 22033 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'h', '_', 'h', '1', '6', '_', 'l', 'l', 0,
  /* 22056 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'h', '_', 'l', '1', '6', '_', 'l', 'l', 0,
  /* 22079 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'h', '_', 'l', '1', '6', '_', 'l', 'l', 0,
  /* 22102 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'c', 'o', 'm', 'b', 'i', 'n', 'e', '_', 'l', 'l', 0,
  /* 22124 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'h', '_', 'h', '1', '6', '_', 's', 'a', 't', '_', 'l', 'l', 0,
  /* 22151 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'h', '_', 'h', '1', '6', '_', 's', 'a', 't', '_', 'l', 'l', 0,
  /* 22178 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'h', '_', 'l', '1', '6', '_', 's', 'a', 't', '_', 'l', 'l', 0,
  /* 22205 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'h', '_', 'l', '1', '6', '_', 's', 'a', 't', '_', 'l', 'l', 0,
  /* 22232 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'c', 'l', 'b', 'n', 'o', 'r', 'm', 0,
  /* 22251 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'i', 'm', 'm', '_', 'n', 0,
  /* 22270 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'i', 'm', 'm', '_', 'n', 0,
  /* 22289 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'a', 'n', 'd', 'n', 0,
  /* 22305 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'A', '4', '_', 'a', 'n', 'd', 'n', 0,
  /* 22321 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'a', 'n', 'd', '_', 'a', 'n', 'd', 'n', 0,
  /* 22341 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '4', '_', 'a', 'n', 'd', '_', 'a', 'n', 'd', 'n', 0,
  /* 22361 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'o', 'r', '_', 'a', 'n', 'd', 'n', 0,
  /* 22380 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '4', '_', 'o', 'r', '_', 'a', 'n', 'd', 'n', 0,
  /* 22399 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '4', '_', 'x', 'o', 'r', '_', 'a', 'n', 'd', 'n', 0,
  /* 22419 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'm', 'i', 'n', 0,
  /* 22434 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'm', 'i', 'n', 0,
  /* 22451 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'm', 'i', 'n', 0,
  /* 22468 */ 'M', 'P', 'Y', 'I', '_', 'r', 'i', 'n', 0,
  /* 22477 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'a', 'c', 's', 'i', 'n', 0,
  /* 22495 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'f', 'i', 'x', 'u', 'p', 'n', 0,
  /* 22515 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'f', 'i', 'x', 'u', 'p', 'n', 0,
  /* 22535 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'o', 'r', 'n', 0,
  /* 22550 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'A', '4', '_', 'o', 'r', 'n', 0,
  /* 22565 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'a', 'n', 'd', '_', 'o', 'r', 'n', 0,
  /* 22584 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'o', 'r', '_', 'o', 'r', 'n', 0,
  /* 22602 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 's', 'v', 'w', '_', 't', 'r', 'u', 'n', 0,
  /* 22628 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 's', 'v', 'w', '_', 't', 'r', 'u', 'n', 0,
  /* 22654 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'c', 'm', 'p', 'u', 'o', 0,
  /* 22673 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'c', 'm', 'p', 'u', 'o', 0,
  /* 22692 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'c', 'l', '0', 'p', 0,
  /* 22708 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'c', 'l', '1', 'p', 0,
  /* 22724 */ 'M', 'A', 'S', 'K', '_', 'p', 0,
  /* 22731 */ 'N', 'O', 'T', '_', 'p', 0,
  /* 22737 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'p', 0,
  /* 22756 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'p', 0,
  /* 22775 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'p', 0,
  /* 22794 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'i', 'm', 'm', '_', 'p', 0,
  /* 22813 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'i', 'm', 'm', '_', 'p', 0,
  /* 22832 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'r', '_', 'p', 0,
  /* 22851 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'l', '_', 'r', '_', 'p', 0,
  /* 22870 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 'p', 0,
  /* 22889 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'r', '_', 'p', 0,
  /* 22908 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'p', 'x', 'f', 'e', 'r', '_', 'm', 'a', 'p', 0,
  /* 22929 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'c', 'l', 'b', 'p', 0,
  /* 22945 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 'p', 0,
  /* 22961 */ 'F', 'M', 'A', 'D', 'D', '_', 'd', 'p', 0,
  /* 22970 */ 'F', 'M', 'I', 'N', '_', 'd', 'p', 0,
  /* 22978 */ 'F', 'M', 'A', 'X', '_', 'd', 'p', 0,
  /* 22986 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 'p', 0,
  /* 23002 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'n', 'd', 'p', 0,
  /* 23018 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'n', 'e', 'g', 'p', 0,
  /* 23034 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'a', 'c', 's', 'i', 'p', 0,
  /* 23052 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '4', '_', 'a', 'n', 'd', 'n', 'p', 0,
  /* 23069 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '4', '_', 'o', 'r', 'n', 'p', 0,
  /* 23085 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'd', 'f', '2', 'd', '_', 'c', 'h', 'o', 'p', 0,
  /* 23111 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 's', 'f', '2', 'd', '_', 'c', 'h', 'o', 'p', 0,
  /* 23137 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'd', 'f', '2', 'u', 'd', '_', 'c', 'h', 'o', 'p', 0,
  /* 23164 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 's', 'f', '2', 'u', 'd', '_', 'c', 'h', 'o', 'p', 0,
  /* 23191 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'd', 'f', '2', 'w', '_', 'c', 'h', 'o', 'p', 0,
  /* 23217 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 's', 'f', '2', 'w', '_', 'c', 'h', 'o', 'p', 0,
  /* 23243 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'd', 'f', '2', 'u', 'w', '_', 'c', 'h', 'o', 'p', 0,
  /* 23270 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 's', 'f', '2', 'u', 'w', '_', 'c', 'h', 'o', 'p', 0,
  /* 23297 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'd', 'f', '2', 'd', '_', 'n', 'c', 'h', 'o', 'p', 0,
  /* 23316 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 's', 'f', '2', 'd', '_', 'n', 'c', 'h', 'o', 'p', 0,
  /* 23335 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'd', 'f', '2', 'u', 'd', '_', 'n', 'c', 'h', 'o', 'p', 0,
  /* 23355 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 's', 'f', '2', 'u', 'd', '_', 'n', 'c', 'h', 'o', 'p', 0,
  /* 23375 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'd', 'f', '2', 'w', '_', 'n', 'c', 'h', 'o', 'p', 0,
  /* 23394 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 's', 'f', '2', 'w', '_', 'n', 'c', 'h', 'o', 'p', 0,
  /* 23413 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'd', 'f', '2', 'u', 'w', '_', 'n', 'c', 'h', 'o', 'p', 0,
  /* 23433 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 's', 'f', '2', 'u', 'w', '_', 'n', 'c', 'h', 'o', 'p', 0,
  /* 23453 */ 'A', 'N', 'D', '_', 'p', 'p', 0,
  /* 23460 */ 'V', 'I', 'T', 'P', 'A', 'C', 'K', '_', 'p', 'p', 0,
  /* 23471 */ 'A', 'L', 'L', '_', 'p', 'p', 0,
  /* 23478 */ 'X', 'O', 'R', '_', 'p', 'p', 0,
  /* 23485 */ 'A', 'N', 'Y', '_', 'p', 'p', 0,
  /* 23492 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'c', 'm', 'p', 'e', 'q', 'p', 0,
  /* 23510 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'M', '2', '_', 'v', 'r', 'c', 'm', 'p', 'y', 's', '_', 's', '1', 'r', 'p', 0,
  /* 23534 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 'i', 'n', 's', 'e', 'r', 't', 'p', '_', 'r', 'p', 0,
  /* 23556 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'e', 'x', 't', 'r', 'a', 'c', 't', 'u', 'p', '_', 'r', 'p', 0,
  /* 23580 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 'i', 'n', 's', 'e', 'r', 't', '_', 'r', 'p', 0,
  /* 23601 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'e', 'x', 't', 'r', 'a', 'c', 't', 'u', '_', 'r', 'p', 0,
  /* 23624 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 't', 'f', 'r', 'p', 0,
  /* 23640 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'o', 'r', 'p', 0,
  /* 23655 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'x', 'o', 'r', 'p', 0,
  /* 23671 */ 'V', 'S', 'P', 'L', 'I', 'C', 'E', '_', 'r', 'r', 'p', 0,
  /* 23683 */ 'V', 'A', 'L', 'I', 'G', 'N', '_', 'r', 'r', 'p', 0,
  /* 23694 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 't', 'f', 'r', 'r', 'p', 0,
  /* 23711 */ 'F', 'M', 'A', 'D', 'D', '_', 's', 'p', 0,
  /* 23720 */ 'F', 'M', 'I', 'N', '_', 's', 'p', 0,
  /* 23728 */ 'F', 'M', 'A', 'X', '_', 's', 'p', 0,
  /* 23736 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'b', 's', 'p', 0,
  /* 23752 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'A', '2', '_', 'a', 'd', 'd', 's', 'p', 0,
  /* 23769 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 'l', 'f', 's', 'p', 0,
  /* 23785 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'c', 'm', 'p', 'g', 't', 'p', 0,
  /* 23803 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '5', '_', 'p', 'o', 'p', 'c', 'o', 'u', 'n', 't', 'p', 0,
  /* 23824 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'n', 'o', 't', 'p', 0,
  /* 23840 */ 'A', 'N', 'D', '_', 'p', 'n', 'o', 't', 'p', 0,
  /* 23850 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 'i', 'n', 's', 'e', 'r', 't', 'p', 0,
  /* 23869 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', 'u', '_', 'u', 'p', 0,
  /* 23888 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'm', 'p', 'y', '_', 'u', 'p', 0,
  /* 23906 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'e', 'x', 't', 'r', 'a', 'c', 't', 'u', 'p', 0,
  /* 23927 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'c', 'm', 'p', 'g', 't', 'u', 'p', 0,
  /* 23946 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'A', '2', '_', 'm', 'a', 'x', 'u', 'p', 0,
  /* 23963 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'A', '2', '_', 'm', 'a', 'x', 'p', 0,
  /* 23979 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'p', 'a', 'r', 'i', 't', 'y', 'p', 0,
  /* 23998 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'c', 'm', 'p', 'b', 'e', 'q', 0,
  /* 24017 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'c', 'm', 'p', 'h', 'e', 'q', 0,
  /* 24036 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'c', 'm', 'p', 'n', 'e', 'q', 0,
  /* 24054 */ 'V', '4', '_', 'A', '4', '_', 'r', 'c', 'm', 'p', 'n', 'e', 'q', 0,
  /* 24068 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'A', '4', '_', 'r', 'c', 'm', 'p', 'n', 'e', 'q', 0,
  /* 24087 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'c', 'm', 'p', 'e', 'q', 0,
  /* 24104 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'c', 'm', 'p', 'e', 'q', 0,
  /* 24123 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'c', 'm', 'p', 'e', 'q', 0,
  /* 24142 */ 'V', '4', '_', 'A', '4', '_', 'r', 'c', 'm', 'p', 'e', 'q', 0,
  /* 24155 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'A', '4', '_', 'r', 'c', 'm', 'p', 'e', 'q', 0,
  /* 24173 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'c', 'm', 'p', 'w', 'e', 'q', 0,
  /* 24192 */ 'L', 'O', 'O', 'P', '0', '_', 'r', 0,
  /* 24200 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'r', 0,
  /* 24219 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'r', 0,
  /* 24238 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'r', 0,
  /* 24257 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'r', '_', 'r', 0,
  /* 24276 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'l', '_', 'r', '_', 'r', 0,
  /* 24295 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 'r', 0,
  /* 24314 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'r', '_', 'r', 0,
  /* 24333 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'c', 'm', 'a', 'c', '_', 's', '0', '_', 's', 'a', 't', '_', 'r', 0,
  /* 24359 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'c', 'm', 'p', 'y', '_', 's', '0', '_', 's', 'a', 't', '_', 'r', 0,
  /* 24385 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'c', 'm', 'p', 'y', '_', 's', '1', '_', 's', 'a', 't', '_', 'r', 0,
  /* 24411 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 't', 'o', 'g', 'g', 'l', 'e', 'b', 'i', 't', '_', 'r', 0,
  /* 24434 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'c', 'l', 'r', 'b', 'i', 't', '_', 'r', 0,
  /* 24454 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 's', 'e', 't', 'b', 'i', 't', '_', 'r', 0,
  /* 24474 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 't', 's', 't', 'b', 'i', 't', '_', 'r', 0,
  /* 24494 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'v', 'g', 'u', 'b', 'r', 0,
  /* 24513 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'n', 'a', 'v', 'g', 'h', 'c', 'r', 0,
  /* 24533 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'v', 'g', 'h', 'c', 'r', 0,
  /* 24552 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'n', 'a', 'v', 'g', 'w', 'c', 'r', 0,
  /* 24572 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'v', 'g', 'w', 'c', 'r', 0,
  /* 24591 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 't', 'f', 'r', 0,
  /* 24606 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'n', 'a', 'v', 'g', 'h', 'r', 0,
  /* 24625 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'v', 'g', 'h', 'r', 0,
  /* 24643 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'v', 'g', 'u', 'h', 'r', 0,
  /* 24662 */ 'M', 'U', 'X', '_', 'i', 'r', 0,
  /* 24669 */ 'T', 'F', 'R', '_', 'c', 'o', 'n', 'd', 's', 'e', 't', '_', 'i', 'r', 0,
  /* 24684 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'n', 'd', 'i', 'r', 0,
  /* 24701 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'A', '4', '_', 'c', 'o', 'm', 'b', 'i', 'n', 'e', 'i', 'r', 0,
  /* 24722 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'o', 'r', 'i', 'r', 0,
  /* 24738 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'm', 'u', 'x', 'i', 'r', 0,
  /* 24755 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '2', '_', 'b', 'i', 't', 's', 'c', 'l', 'r', 0,
  /* 24774 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'o', 'r', 0,
  /* 24788 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'o', 'r', 0,
  /* 24802 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'a', 'n', 'd', '_', 'o', 'r', 0,
  /* 24820 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '4', '_', 'a', 'n', 'd', '_', 'o', 'r', 0,
  /* 24838 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'p', '_', 'o', 'r', 0,
  /* 24860 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'p', '_', 'o', 'r', 0,
  /* 24882 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'p', '_', 'o', 'r', 0,
  /* 24904 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'r', '_', 'p', '_', 'o', 'r', 0,
  /* 24926 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'l', '_', 'r', '_', 'p', '_', 'o', 'r', 0,
  /* 24948 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 'p', '_', 'o', 'r', 0,
  /* 24970 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'r', '_', 'p', '_', 'o', 'r', 0,
  /* 24992 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'r', '_', 'o', 'r', 0,
  /* 25014 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'r', '_', 'o', 'r', 0,
  /* 25036 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'r', '_', 'o', 'r', 0,
  /* 25058 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'r', '_', 'r', '_', 'o', 'r', 0,
  /* 25080 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'l', '_', 'r', '_', 'r', '_', 'o', 'r', 0,
  /* 25102 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 'r', '_', 'o', 'r', 0,
  /* 25124 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'r', '_', 'r', '_', 'o', 'r', 0,
  /* 25146 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'o', 'r', '_', 'o', 'r', 0,
  /* 25163 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '4', '_', 'o', 'r', '_', 'o', 'r', 0,
  /* 25180 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '4', '_', 'x', 'o', 'r', '_', 'o', 'r', 0,
  /* 25198 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'x', 'o', 'r', 0,
  /* 25213 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'x', 'o', 'r', 0,
  /* 25228 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '4', '_', 'a', 'n', 'd', '_', 'x', 'o', 'r', 0,
  /* 25247 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '4', '_', 'o', 'r', '_', 'x', 'o', 'r', 0,
  /* 25265 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 't', 'f', 'r', 'p', 'r', 0,
  /* 25282 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'f', 'i', 'x', 'u', 'p', 'r', 0,
  /* 25302 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'f', 'i', 'x', 'u', 'p', 'r', 0,
  /* 25322 */ 'C', 'M', 'P', 'G', 'T', '6', '4', 'r', 'r', 0,
  /* 25332 */ 'C', 'M', 'P', 'G', 'T', 'U', '6', '4', 'r', 'r', 0,
  /* 25343 */ 'C', 'M', 'P', 'E', 'H', 'e', 'x', 'a', 'g', 'o', 'n', '4', 'r', 'r', 0,
  /* 25358 */ 'C', 'M', 'P', 'E', 'Q', 'r', 'r', 0,
  /* 25366 */ 'C', 'M', 'P', 'G', 'T', 'r', 'r', 0,
  /* 25374 */ 'C', 'M', 'P', 'G', 'T', 'U', 'r', 'r', 0,
  /* 25383 */ 'F', 'C', 'M', 'P', 'O', 'G', 'E', '3', '2', '_', 'r', 'r', 0,
  /* 25396 */ 'F', 'C', 'M', 'P', 'U', 'G', 'E', '3', '2', '_', 'r', 'r', 0,
  /* 25409 */ 'F', 'C', 'M', 'P', 'O', 'E', 'Q', '3', '2', '_', 'r', 'r', 0,
  /* 25422 */ 'F', 'C', 'M', 'P', 'U', 'E', 'Q', '3', '2', '_', 'r', 'r', 0,
  /* 25435 */ 'F', 'C', 'M', 'P', 'O', 'G', 'T', '3', '2', '_', 'r', 'r', 0,
  /* 25448 */ 'F', 'C', 'M', 'P', 'U', 'G', 'T', '3', '2', '_', 'r', 'r', 0,
  /* 25461 */ 'f', 'S', 'U', 'B', '6', '4', '_', 'r', 'r', 0,
  /* 25471 */ 'f', 'A', 'D', 'D', '6', '4', '_', 'r', 'r', 0,
  /* 25481 */ 'F', 'C', 'M', 'P', 'O', 'G', 'E', '6', '4', '_', 'r', 'r', 0,
  /* 25494 */ 'F', 'C', 'M', 'P', 'U', 'G', 'E', '6', '4', '_', 'r', 'r', 0,
  /* 25507 */ 'f', 'M', 'U', 'L', '6', '4', '_', 'r', 'r', 0,
  /* 25517 */ 'F', 'C', 'M', 'P', 'O', 'E', 'Q', '6', '4', '_', 'r', 'r', 0,
  /* 25530 */ 'F', 'C', 'M', 'P', 'U', 'E', 'Q', '6', '4', '_', 'r', 'r', 0,
  /* 25543 */ 'F', 'C', 'M', 'P', 'O', 'G', 'T', '6', '4', '_', 'r', 'r', 0,
  /* 25556 */ 'F', 'C', 'M', 'P', 'U', 'G', 'T', '6', '4', '_', 'r', 'r', 0,
  /* 25569 */ 'C', 'T', 'L', 'Z', '6', '4', '_', 'r', 'r', 0,
  /* 25579 */ 'C', 'T', 'T', 'Z', '6', '4', '_', 'r', 'r', 0,
  /* 25589 */ 'A', 'S', 'L', '_', 'S', 'U', 'B', '_', 'r', 'r', 0,
  /* 25600 */ 'L', 'S', 'L', '_', 'S', 'U', 'B', '_', 'r', 'r', 0,
  /* 25611 */ 'A', 'S', 'R', '_', 'S', 'U', 'B', '_', 'r', 'r', 0,
  /* 25622 */ 'L', 'S', 'R', '_', 'S', 'U', 'B', '_', 'r', 'r', 0,
  /* 25633 */ 'f', 'S', 'U', 'B', '_', 'r', 'r', 0,
  /* 25641 */ 'A', 'S', 'L', '_', 'A', 'D', 'D', '_', 'r', 'r', 0,
  /* 25652 */ 'L', 'S', 'L', '_', 'A', 'D', 'D', '_', 'r', 'r', 0,
  /* 25663 */ 'A', 'S', 'R', '_', 'A', 'D', 'D', '_', 'r', 'r', 0,
  /* 25674 */ 'L', 'S', 'R', '_', 'A', 'D', 'D', '_', 'r', 'r', 0,
  /* 25685 */ 'f', 'A', 'D', 'D', '_', 'r', 'r', 0,
  /* 25693 */ 'A', 'S', 'L', '_', 'A', 'N', 'D', '_', 'r', 'r', 0,
  /* 25704 */ 'L', 'S', 'L', '_', 'A', 'N', 'D', '_', 'r', 'r', 0,
  /* 25715 */ 'A', 'S', 'R', '_', 'A', 'N', 'D', '_', 'r', 'r', 0,
  /* 25726 */ 'L', 'S', 'R', '_', 'A', 'N', 'D', '_', 'r', 'r', 0,
  /* 25737 */ 'C', 'O', 'M', 'B', 'I', 'N', 'E', '_', 'r', 'r', 0,
  /* 25748 */ 'A', 'S', 'L', '_', 'r', 'r', 0,
  /* 25755 */ 'L', 'S', 'L', '_', 'r', 'r', 0,
  /* 25762 */ 'f', 'M', 'U', 'L', '_', 'r', 'r', 0,
  /* 25770 */ 'C', 'M', 'P', 'n', 'o', 't', 'E', 'Q', '_', 'r', 'r', 0,
  /* 25782 */ 'X', 'O', 'R', '_', 'r', 'r', 0,
  /* 25789 */ 'A', 'S', 'L', '_', 'O', 'R', '_', 'r', 'r', 0,
  /* 25799 */ 'L', 'S', 'L', '_', 'O', 'R', '_', 'r', 'r', 0,
  /* 25809 */ 'A', 'S', 'R', '_', 'O', 'R', '_', 'r', 'r', 0,
  /* 25819 */ 'L', 'S', 'R', '_', 'O', 'R', '_', 'r', 'r', 0,
  /* 25829 */ 'A', 'S', 'R', '_', 'r', 'r', 0,
  /* 25836 */ 'L', 'S', 'R', '_', 'r', 'r', 0,
  /* 25843 */ 'C', 'M', 'P', 'n', 'o', 't', 'G', 'T', '_', 'r', 'r', 0,
  /* 25855 */ 'N', 'T', 'S', 'T', 'B', 'I', 'T', '_', 'r', 'r', 0,
  /* 25866 */ 'C', 'M', 'P', 'n', 'o', 't', 'G', 'T', 'U', '_', 'r', 'r', 0,
  /* 25879 */ 'M', 'U', 'X', '_', 'r', 'r', 0,
  /* 25886 */ 'C', 'T', 'L', 'Z', '_', 'r', 'r', 0,
  /* 25894 */ 'C', 'T', 'T', 'Z', '_', 'r', 'r', 0,
  /* 25902 */ 'M', 'P', 'Y', 'I', '_', 'a', 'c', 'c', '_', 'r', 'r', 0,
  /* 25914 */ 'A', 'S', 'L', '_', 'S', 'U', 'B', 'd', '_', 'r', 'r', 0,
  /* 25926 */ 'L', 'S', 'L', '_', 'S', 'U', 'B', 'd', '_', 'r', 'r', 0,
  /* 25938 */ 'A', 'S', 'R', '_', 'S', 'U', 'B', 'd', '_', 'r', 'r', 0,
  /* 25950 */ 'L', 'S', 'R', '_', 'S', 'U', 'B', 'd', '_', 'r', 'r', 0,
  /* 25962 */ 'A', 'S', 'L', '_', 'A', 'D', 'D', 'd', '_', 'r', 'r', 0,
  /* 25974 */ 'L', 'S', 'L', '_', 'A', 'D', 'D', 'd', '_', 'r', 'r', 0,
  /* 25986 */ 'A', 'S', 'R', '_', 'A', 'D', 'D', 'd', '_', 'r', 'r', 0,
  /* 25998 */ 'L', 'S', 'R', '_', 'A', 'D', 'D', 'd', '_', 'r', 'r', 0,
  /* 26010 */ 'A', 'S', 'L', '_', 'A', 'N', 'D', 'd', '_', 'r', 'r', 0,
  /* 26022 */ 'L', 'S', 'L', '_', 'A', 'N', 'D', 'd', '_', 'r', 'r', 0,
  /* 26034 */ 'A', 'S', 'R', '_', 'A', 'N', 'D', 'd', '_', 'r', 'r', 0,
  /* 26046 */ 'L', 'S', 'R', '_', 'A', 'N', 'D', 'd', '_', 'r', 'r', 0,
  /* 26058 */ 'M', 'I', 'N', 'd', '_', 'r', 'r', 0,
  /* 26066 */ 'A', 'S', 'L', '_', 'O', 'R', 'd', '_', 'r', 'r', 0,
  /* 26077 */ 'L', 'S', 'L', '_', 'O', 'R', 'd', '_', 'r', 'r', 0,
  /* 26088 */ 'A', 'S', 'R', '_', 'O', 'R', 'd', '_', 'r', 'r', 0,
  /* 26099 */ 'L', 'S', 'R', '_', 'O', 'R', 'd', '_', 'r', 'r', 0,
  /* 26110 */ 'A', 'S', 'R', 'd', '_', 'r', 'r', 0,
  /* 26118 */ 'L', 'S', 'R', 'd', '_', 'r', 'r', 0,
  /* 26126 */ 'M', 'I', 'N', 'U', 'd', '_', 'r', 'r', 0,
  /* 26135 */ 'M', 'A', 'X', 'U', 'd', '_', 'r', 'r', 0,
  /* 26144 */ 'M', 'A', 'X', 'd', '_', 'r', 'r', 0,
  /* 26152 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '4', '_', 'r', 'o', 'u', 'n', 'd', '_', 'r', 'r', 0,
  /* 26172 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '4', '_', 'c', 'r', 'o', 'u', 'n', 'd', '_', 'r', 'r', 0,
  /* 26193 */ 'T', 'F', 'R', '_', 'c', 'o', 'n', 'd', 's', 'e', 't', '_', 'r', 'r', 0,
  /* 26208 */ 'M', 'I', 'N', 'w', '_', 'r', 'r', 0,
  /* 26216 */ 'M', 'I', 'N', 'U', 'w', '_', 'r', 'r', 0,
  /* 26225 */ 'M', 'A', 'X', 'U', 'w', '_', 'r', 'r', 0,
  /* 26234 */ 'M', 'A', 'X', 'w', '_', 'r', 'r', 0,
  /* 26242 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'n', 'a', 'v', 'g', 'w', 'r', 0,
  /* 26261 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'v', 'g', 'w', 'r', 0,
  /* 26279 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'v', 'g', 'u', 'w', 'r', 0,
  /* 26298 */ 'T', 'F', 'R', '_', 'P', 'd', 'R', 's', 0,
  /* 26307 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'b', 's', 0,
  /* 26322 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 's', 'u', 'b', 'u', 'b', 's', 0,
  /* 26341 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'd', 'd', 'u', 'b', 's', 0,
  /* 26360 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '5', '_', 'v', 'a', 'd', 'd', 'h', 'u', 'b', 's', 0,
  /* 26380 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'm', 'a', 'c', '2', 'e', 's', 0,
  /* 26399 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 's', 'u', 'b', 'h', 's', 0,
  /* 26417 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'v', 's', 'u', 'b', 'h', 's', 0,
  /* 26436 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'd', 'd', 'h', 's', 0,
  /* 26454 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'v', 'a', 'd', 'd', 'h', 's', 0,
  /* 26473 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'v', 'a', 'v', 'g', 'h', 's', 0,
  /* 26492 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 's', 'u', 'b', 'u', 'h', 's', 0,
  /* 26511 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'v', 's', 'u', 'b', 'u', 'h', 's', 0,
  /* 26531 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'd', 'd', 'u', 'h', 's', 0,
  /* 26550 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'v', 'a', 'd', 'd', 'u', 'h', 's', 0,
  /* 26570 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 'r', 'n', 'd', 'p', 'a', 'c', 'k', 'w', 'h', 's', 0,
  /* 26593 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'f', 'm', 's', 0,
  /* 26610 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'f', 'm', 's', 0,
  /* 26627 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'c', 'l', 'a', 's', 's', 0,
  /* 26646 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'c', 'l', 'a', 's', 's', 0,
  /* 26665 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 's', 'u', 'b', 'w', 's', 0,
  /* 26683 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'd', 'd', 'w', 's', 0,
  /* 26701 */ 'T', 'F', 'R', '6', '4', '_', 'c', 'P', 't', 0,
  /* 26711 */ 'T', 'F', 'R', 'I', '_', 'c', 'P', 't', 0,
  /* 26720 */ 'T', 'F', 'R', '_', 'c', 'P', 't', 0,
  /* 26728 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'b', '_', 'c', 'P', 't', 0,
  /* 26743 */ 'S', 'T', 'r', 'i', 'b', '_', 'c', 'P', 't', 0,
  /* 26753 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'u', 'b', '_', 'c', 'P', 't', 0,
  /* 26769 */ 'L', 'D', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'P', 't', 0,
  /* 26787 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'P', 't', 0,
  /* 26805 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'P', 't', 0,
  /* 26824 */ 'L', 'D', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'P', 't', 0,
  /* 26842 */ 'S', 'T', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'P', 't', 0,
  /* 26860 */ 'L', 'D', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'P', 't', 0,
  /* 26878 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'P', 't', 0,
  /* 26896 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'P', 't', 0,
  /* 26915 */ 'L', 'D', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'P', 't', 0,
  /* 26933 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'P', 't', 0,
  /* 26951 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'd', '_', 'c', 'P', 't', 0,
  /* 26966 */ 'S', 'T', 'r', 'i', 'd', '_', 'c', 'P', 't', 0,
  /* 26976 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'h', '_', 'c', 'P', 't', 0,
  /* 26991 */ 'S', 'T', 'r', 'i', 'h', '_', 'c', 'P', 't', 0,
  /* 27001 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'u', 'h', '_', 'c', 'P', 't', 0,
  /* 27017 */ 'A', 'D', 'D', '_', 'r', 'i', '_', 'c', 'P', 't', 0,
  /* 27028 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'b', 'r', 'i', '_', 'c', 'P', 't', 0,
  /* 27043 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'd', 'r', 'i', '_', 'c', 'P', 't', 0,
  /* 27058 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'h', 'r', 'i', '_', 'c', 'P', 't', 0,
  /* 27073 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'w', 'r', 'i', '_', 'c', 'P', 't', 0,
  /* 27088 */ 'S', 'U', 'B', '_', 'r', 'r', '_', 'c', 'P', 't', 0,
  /* 27099 */ 'A', 'D', 'D', '_', 'r', 'r', '_', 'c', 'P', 't', 0,
  /* 27110 */ 'A', 'N', 'D', '_', 'r', 'r', '_', 'c', 'P', 't', 0,
  /* 27121 */ 'C', 'O', 'M', 'B', 'I', 'N', 'E', '_', 'r', 'r', '_', 'c', 'P', 't', 0,
  /* 27136 */ 'X', 'O', 'R', '_', 'r', 'r', '_', 'c', 'P', 't', 0,
  /* 27147 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'w', '_', 'c', 'P', 't', 0,
  /* 27162 */ 'S', 'T', 'r', 'i', 'w', '_', 'c', 'P', 't', 0,
  /* 27172 */ 'T', 'F', 'R', '6', '4', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27184 */ 'T', 'F', 'R', 'I', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27195 */ 'T', 'F', 'R', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27205 */ 'L', 'D', 'r', 'i', 'b', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27217 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27230 */ 'L', 'D', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27250 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27271 */ 'L', 'D', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27291 */ 'L', 'D', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27311 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27332 */ 'L', 'D', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27352 */ 'L', 'D', 'r', 'i', 'd', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27364 */ 'L', 'D', 'r', 'i', 'h', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27376 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27389 */ 'A', 'D', 'D', '_', 'r', 'i', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27402 */ 'S', 'U', 'B', '_', 'r', 'r', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27415 */ 'A', 'D', 'D', '_', 'r', 'r', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27428 */ 'A', 'N', 'D', '_', 'r', 'r', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27441 */ 'C', 'O', 'M', 'B', 'I', 'N', 'E', '_', 'r', 'r', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27458 */ 'X', 'O', 'R', '_', 'r', 'r', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27471 */ 'L', 'D', 'r', 'i', 'w', '_', 'c', 'd', 'n', 'P', 't', 0,
  /* 27483 */ 'T', 'F', 'R', '6', '4', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27496 */ 'T', 'F', 'R', 'I', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27508 */ 'T', 'F', 'R', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27519 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'b', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27537 */ 'S', 'T', 'r', 'i', 'b', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27550 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'u', 'b', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27569 */ 'L', 'D', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27590 */ 'S', 'T', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27611 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27633 */ 'L', 'D', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27654 */ 'S', 'T', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27675 */ 'L', 'D', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27696 */ 'S', 'T', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27717 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27739 */ 'L', 'D', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27760 */ 'S', 'T', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27781 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27799 */ 'S', 'T', 'r', 'i', 'd', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27812 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'h', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27830 */ 'S', 'T', 'r', 'i', 'h', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27843 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'u', 'h', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27862 */ 'A', 'D', 'D', '_', 'r', 'i', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27876 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'b', 'r', 'i', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27894 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'd', 'r', 'i', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27912 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'h', 'r', 'i', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27930 */ 'P', 'O', 'S', 'T', '_', 'S', 'T', 'w', 'r', 'i', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27948 */ 'S', 'U', 'B', '_', 'r', 'r', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27962 */ 'A', 'D', 'D', '_', 'r', 'r', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27976 */ 'A', 'N', 'D', '_', 'r', 'r', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 27990 */ 'C', 'O', 'M', 'B', 'I', 'N', 'E', '_', 'r', 'r', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 28008 */ 'X', 'O', 'R', '_', 'r', 'r', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 28022 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'w', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 28040 */ 'S', 'T', 'r', 'i', 'w', '_', 'c', 'N', 'o', 't', 'P', 't', 0,
  /* 28053 */ 'T', 'F', 'R', '6', '4', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28068 */ 'T', 'F', 'R', 'I', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28082 */ 'T', 'F', 'R', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28095 */ 'L', 'D', 'r', 'i', 'b', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28110 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28126 */ 'L', 'D', 'r', 'i', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28149 */ 'L', 'D', 'r', 'i', 'u', 'b', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28173 */ 'L', 'D', 'r', 'i', 'd', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28196 */ 'L', 'D', 'r', 'i', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28219 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28243 */ 'L', 'D', 'r', 'i', 'w', '_', 'i', 'n', 'd', 'e', 'x', 'e', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28266 */ 'L', 'D', 'r', 'i', 'd', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28281 */ 'L', 'D', 'r', 'i', 'h', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28296 */ 'L', 'D', 'r', 'i', 'u', 'h', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28312 */ 'A', 'D', 'D', '_', 'r', 'i', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28328 */ 'S', 'U', 'B', '_', 'r', 'r', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28344 */ 'A', 'D', 'D', '_', 'r', 'r', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28360 */ 'A', 'N', 'D', '_', 'r', 'r', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28376 */ 'C', 'O', 'M', 'B', 'I', 'N', 'E', '_', 'r', 'r', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28396 */ 'X', 'O', 'R', '_', 'r', 'r', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28412 */ 'L', 'D', 'r', 'i', 'w', '_', 'c', 'd', 'n', 'N', 'o', 't', 'P', 't', 0,
  /* 28427 */ 'J', 'M', 'P', '_', 't', 0,
  /* 28433 */ 'J', 'M', 'P', 'R', '_', 't', 0,
  /* 28440 */ 'J', 'M', 'P', 'r', 'e', 't', '_', 't', 0,
  /* 28449 */ 'J', 'M', 'P', '_', 'f', 'n', 'e', 'w', '_', 't', 0,
  /* 28460 */ 'J', 'M', 'P', '_', 't', 'n', 'e', 'w', '_', 't', 0,
  /* 28471 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'a', 't', 0,
  /* 28486 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '5', '_', 'a', 's', 'r', 'h', 'u', 'b', '_', 's', 'a', 't', 0,
  /* 28508 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '4', '_', 'r', 'o', 'u', 'n', 'd', '_', 'r', 'i', '_', 's', 'a', 't', 0,
  /* 28532 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'r', '_', 's', 'a', 't', 0,
  /* 28555 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'r', '_', 'r', '_', 's', 'a', 't', 0,
  /* 28578 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 'r', '_', 's', 'a', 't', 0,
  /* 28601 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '4', '_', 'r', 'o', 'u', 'n', 'd', '_', 'r', 'r', '_', 's', 'a', 't', 0,
  /* 28625 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'u', 'b', 's', 'a', 't', 0,
  /* 28643 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'd', 'd', 's', 'a', 't', 0,
  /* 28661 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'n', 'e', 'g', 's', 'a', 't', 0,
  /* 28679 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'b', 's', 'h', 's', 'a', 't', 0,
  /* 28699 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'A', '2', '_', 'a', 'd', 'd', 'p', 's', 'a', 't', 0,
  /* 28718 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'a', 'b', 's', 's', 'a', 't', 0,
  /* 28736 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'b', 's', 'w', 's', 'a', 't', 0,
  /* 28756 */ 'J', 'M', 'P', 'r', 'e', 't', 0,
  /* 28763 */ 'C', 'O', 'N', 'S', 'T', '3', '2', '_', 's', 'e', 't', 0,
  /* 28775 */ 'C', 'O', 'N', 'S', 'T', '3', '2', 'G', 'P', '_', 's', 'e', 't', 0,
  /* 28789 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '2', '_', 'b', 'i', 't', 's', 's', 'e', 't', 0,
  /* 28808 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'c', 'm', 'p', 'h', 'g', 't', 0,
  /* 28827 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'c', 'm', 'p', 'g', 't', 0,
  /* 28844 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'c', 'm', 'p', 'g', 't', 0,
  /* 28863 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'c', 'm', 'p', 'g', 't', 0,
  /* 28882 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'c', 'm', 'p', 'w', 'g', 't', 0,
  /* 28901 */ 'H', 'I', '_', 'j', 't', 0,
  /* 28907 */ 'L', 'O', '_', 'j', 't', 0,
  /* 28913 */ 'C', 'O', 'N', 'S', 'T', '3', '2', '_', 's', 'e', 't', '_', 'j', 't', 0,
  /* 28928 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'c', 'm', 'p', 'l', 't', 0,
  /* 28945 */ 'J', 'M', 'P', '_', 'f', 'n', 'e', 'w', '_', 'n', 't', 0,
  /* 28957 */ 'J', 'M', 'P', '_', 't', 'n', 'e', 'w', '_', 'n', 't', 0,
  /* 28969 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'n', 'o', 't', 0,
  /* 28984 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'n', 'o', 't', 0,
  /* 28999 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '4', '_', 'f', 'a', 's', 't', 'c', 'o', 'r', 'n', 'e', 'r', '9', '_', 'n', 'o', 't', 0,
  /* 29026 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'f', 'a', 's', 't', 'c', 'o', 'r', 'n', 'e', 'r', '9', '_', 'n', 'o', 't', 0,
  /* 29053 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 'i', 'n', 's', 'e', 'r', 't', 0,
  /* 29071 */ 'M', 'P', 'Y', '_', 't', 'r', 's', 'e', 'x', 't', 0,
  /* 29082 */ 'T', 'C', 'R', 'E', 'T', 'U', 'R', 'N', 't', 'e', 'x', 't', 0,
  /* 29095 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'C', '4', '_', 'c', 'm', 'p', 'l', 't', 'e', 'u', 0,
  /* 29114 */ 'M', 'P', 'Y', 'I', '_', 'r', 'i', 'u', 0,
  /* 29123 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'm', 'i', 'n', 'u', 0,
  /* 29139 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '4', '_', 'm', 'o', 'd', 'w', 'r', 'a', 'p', 'u', 0,
  /* 29159 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '5', '_', 'v', 'd', 'm', 'a', 'c', 'b', 's', 'u', 0,
  /* 29179 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '5', '_', 'v', 'r', 'm', 'a', 'c', 'b', 's', 'u', 0,
  /* 29199 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '5', '_', 'v', 'm', 'a', 'c', 'b', 's', 'u', 0,
  /* 29218 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '5', '_', 'v', 'd', 'm', 'p', 'y', 'b', 's', 'u', 0,
  /* 29238 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '5', '_', 'v', 'r', 'm', 'p', 'y', 'b', 's', 'u', 0,
  /* 29258 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '5', '_', 'v', 'm', 'p', 'y', 'b', 's', 'u', 0,
  /* 29277 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'e', 'x', 't', 'r', 'a', 'c', 't', 'u', 0,
  /* 29297 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'c', 'm', 'p', 'b', 'g', 't', 'u', 0,
  /* 29317 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'c', 'm', 'p', 'h', 'g', 't', 'u', 0,
  /* 29337 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'c', 'm', 'p', 'g', 't', 'u', 0,
  /* 29355 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'c', 'm', 'p', 'w', 'g', 't', 'u', 0,
  /* 29375 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'c', 'm', 'p', 'l', 't', 'u', 0,
  /* 29393 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '5', '_', 'v', 'r', 'm', 'a', 'c', 'b', 'u', 'u', 0,
  /* 29413 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '5', '_', 'v', 'm', 'a', 'c', 'b', 'u', 'u', 0,
  /* 29432 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '5', '_', 'v', 'r', 'm', 'p', 'y', 'b', 'u', 'u', 0,
  /* 29452 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '5', '_', 'v', 'm', 'p', 'y', 'b', 'u', 'u', 0,
  /* 29471 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'm', 'a', 'x', 'u', 0,
  /* 29487 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 'b', 'r', 'e', 'v', 0,
  /* 29503 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'd', 'f', '2', 'w', 0,
  /* 29516 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'd', 'f', '2', 'w', 0,
  /* 29537 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 's', 'f', '2', 'w', 0,
  /* 29550 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 's', 'f', '2', 'w', 0,
  /* 29571 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 's', 'u', 'b', 'w', 0,
  /* 29588 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'd', 'd', 'w', 0,
  /* 29605 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'c', 'o', 'm', 'b', 'i', 'n', 'e', 'w', 0,
  /* 29625 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'M', '2', '_', 'v', 'a', 'b', 's', 'd', 'i', 'f', 'f', 'w', 0,
  /* 29646 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'n', 'a', 'v', 'g', 'w', 0,
  /* 29664 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'v', 'g', 'w', 0,
  /* 29681 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 's', 'x', 't', 'h', 'w', 0,
  /* 29699 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'v', 'z', 'x', 't', 'h', 'w', 0,
  /* 29717 */ 'P', 'O', 'S', 'T', '_', 'L', 'D', 'r', 'i', 'w', 0,
  /* 29728 */ 'S', 'T', 'r', 'i', 'w', 0,
  /* 29734 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'm', 'i', 'n', 'w', 0,
  /* 29751 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'b', 's', 'w', 0,
  /* 29768 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'x', 't', 'w', 0,
  /* 29784 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 'd', 'f', '2', 'u', 'w', 0,
  /* 29798 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 'd', 'f', '2', 'u', 'w', 0,
  /* 29820 */ 'C', 'O', 'N', 'V', 'E', 'R', 'T', '_', 's', 'f', '2', 'u', 'w', 0,
  /* 29834 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'c', 'o', 'n', 'v', '_', 's', 'f', '2', 'u', 'w', 0,
  /* 29856 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'a', 'v', 'g', 'u', 'w', 0,
  /* 29874 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'm', 'i', 'n', 'u', 'w', 0,
  /* 29892 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'm', 'a', 'x', 'u', 'w', 0,
  /* 29910 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'i', '_', 'v', 'w', 0,
  /* 29930 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'v', 'w', 0,
  /* 29950 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'i', '_', 'v', 'w', 0,
  /* 29970 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'l', '_', 'r', '_', 'v', 'w', 0,
  /* 29990 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'l', '_', 'r', '_', 'v', 'w', 0,
  /* 30010 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'r', '_', 'v', 'w', 0,
  /* 30030 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'l', 's', 'r', '_', 'r', '_', 'v', 'w', 0,
  /* 30050 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'v', 'm', 'a', 'x', 'w', 0,
  /* 30067 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 'm', 'a', 'x', 0,
  /* 30082 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'm', 'a', 'x', 0,
  /* 30099 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'm', 'a', 'x', 0,
  /* 30116 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 't', 'a', 'b', 'l', 'e', 'i', 'd', 'x', 'b', '_', 'g', 'o', 'o', 'd', 's', 'y', 'n', 't', 'a', 'x', 0,
  /* 30148 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'p', '_', 'r', 'n', 'd', '_', 'g', 'o', 'o', 'd', 's', 'y', 'n', 't', 'a', 'x', 0,
  /* 30182 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '2', '_', 'a', 's', 'r', '_', 'i', '_', 'r', '_', 'r', 'n', 'd', '_', 'g', 'o', 'o', 'd', 's', 'y', 'n', 't', 'a', 'x', 0,
  /* 30216 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '5', '_', 'v', 'a', 's', 'r', 'h', 'r', 'n', 'd', '_', 'g', 'o', 'o', 'd', 's', 'y', 'n', 't', 'a', 'x', 0,
  /* 30247 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 't', 'a', 'b', 'l', 'e', 'i', 'd', 'x', 'd', '_', 'g', 'o', 'o', 'd', 's', 'y', 'n', 't', 'a', 'x', 0,
  /* 30279 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 't', 'a', 'b', 'l', 'e', 'i', 'd', 'x', 'h', '_', 'g', 'o', 'o', 'd', 's', 'y', 'n', 't', 'a', 'x', 0,
  /* 30311 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '5', '_', 'a', 's', 'r', 'h', 'u', 'b', '_', 'r', 'n', 'd', '_', 's', 'a', 't', '_', 'g', 'o', 'o', 'd', 's', 'y', 'n', 't', 'a', 'x', 0,
  /* 30348 */ 'H', 'e', 'x', 'a', 'g', 'o', 'n', '_', 'S', '2', '_', 't', 'a', 'b', 'l', 'e', 'i', 'd', 'x', 'w', '_', 'g', 'o', 'o', 'd', 's', 'y', 'n', 't', 'a', 'x', 0,
  /* 30380 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'S', '4', '_', 'o', 'r', '_', 'a', 'n', 'd', 'i', 'x', 0,
  /* 30400 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'm', 'u', 'x', 0,
  /* 30415 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'C', '2', '_', 'v', 'm', 'u', 'x', 0,
  /* 30431 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 'd', 'f', 'm', 'p', 'y', 0,
  /* 30448 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'F', '2', '_', 's', 'f', 'm', 'p', 'y', 0,
  /* 30465 */ 'H', 'E', 'X', 'A', 'G', 'O', 'N', '_', 'A', '2', '_', 's', 'w', 'i', 'z', 0,
};

extern const unsigned HexagonInstrNameIndices[] = {
    15282U, 15344U, 15305U, 15318U, 15296U, 15332U, 15212U, 15227U, 
    15199U, 15241U, 15454U, 15189U, 15156U, 15532U, 15169U, 15503U, 
    15143U, 15374U, 15492U, 25472U, 15337U, 20699U, 27862U, 27017U, 
    28312U, 27389U, 25645U, 27962U, 27099U, 28344U, 27415U, 6379U, 
    6470U, 6537U, 7497U, 6338U, 7287U, 6551U, 7511U, 6324U, 
    7076U, 16743U, 17085U, 15354U, 15391U, 15121U, 15178U, 23471U, 
    23840U, 23453U, 20732U, 25697U, 5755U, 27976U, 27110U, 28360U, 
    27428U, 6079U, 6393U, 6484U, 7251U, 7377U, 7433U, 7405U, 
    23485U, 15133U, 15340U, 15255U, 9587U, 7681U, 10434U, 8405U, 
    20695U, 25641U, 20950U, 25962U, 20728U, 25693U, 20986U, 26010U, 
    20803U, 25789U, 21054U, 26066U, 20662U, 25589U, 20914U, 25914U, 
    20781U, 21030U, 25748U, 17357U, 21022U, 7317U, 15260U, 9602U, 
    7693U, 10451U, 8419U, 20706U, 25663U, 20962U, 25986U, 20739U, 
    25715U, 20998U, 26034U, 20813U, 25809U, 21065U, 26088U, 20673U, 
    25611U, 20926U, 25938U, 20833U, 25829U, 21087U, 26110U, 7347U, 
    15411U, 15327U, 15423U, 5721U, 5714U, 15478U, 2927U, 25343U, 
    12441U, 11731U, 12697U, 11976U, 20637U, 12487U, 11775U, 12743U, 
    12020U, 25358U, 12557U, 11842U, 12813U, 12087U, 25322U, 25332U, 
    20653U, 12533U, 11819U, 12789U, 12064U, 25374U, 12626U, 11908U, 
    12882U, 12153U, 12464U, 11753U, 12720U, 11998U, 20645U, 12510U, 
    11797U, 12766U, 12042U, 25366U, 12580U, 11864U, 12836U, 12109U, 
    12650U, 11931U, 12906U, 12176U, 12603U, 11886U, 12859U, 12131U, 
    6420U, 6045U, 6062U, 6511U, 7471U, 7459U, 6432U, 6816U, 
    7301U, 6524U, 7484U, 6832U, 20769U, 25770U, 20870U, 25866U, 
    20847U, 25843U, 20039U, 7195U, 5815U, 20391U, 5829U, 25737U, 
    27990U, 27121U, 28376U, 27441U, 5565U, 28775U, 21649U, 21687U, 
    21721U, 28763U, 28913U, 21668U, 21704U, 18624U, 18800U, 17289U, 
    23297U, 18870U, 18181U, 23335U, 29784U, 23413U, 29503U, 23375U, 
    17323U, 23316U, 18694U, 18217U, 23355U, 29820U, 23433U, 29537U, 
    23394U, 18658U, 18834U, 18764U, 18940U, 18730U, 18906U, 25569U, 
    25886U, 25579U, 25894U, 15176U, 6030U, 9834U, 12393U, 9533U, 
    7883U, 12371U, 8637U, 15439U, 0U, 25409U, 25517U, 25383U, 
    25481U, 25435U, 25543U, 25422U, 25530U, 25396U, 25494U, 25448U, 
    25556U, 15571U, 22961U, 23711U, 22978U, 23728U, 22970U, 23720U, 
    26307U, 23736U, 28718U, 17403U, 19252U, 21776U, 19408U, 22033U, 
    19324U, 21894U, 19480U, 22151U, 21822U, 22079U, 21948U, 22205U, 
    20281U, 22986U, 28643U, 17650U, 24684U, 23002U, 19507U, 19559U, 
    19275U, 21845U, 19431U, 22102U, 20459U, 29605U, 30067U, 29471U, 
    22419U, 29123U, 18985U, 23018U, 28661U, 28969U, 23824U, 24774U, 
    24722U, 23640U, 28471U, 15929U, 19629U, 16208U, 19744U, 16138U, 
    19229U, 21753U, 19385U, 22010U, 19297U, 21867U, 19453U, 22124U, 
    21799U, 22056U, 21921U, 22178U, 22945U, 21170U, 28625U, 19099U, 
    26454U, 26550U, 19211U, 26473U, 19175U, 19064U, 26417U, 26511U, 
    30465U, 15945U, 19645U, 29768U, 24591U, 19368U, 21993U, 23624U, 
    20515U, 21319U, 19612U, 28679U, 29751U, 28736U, 19082U, 26436U, 
    16033U, 26341U, 26531U, 29588U, 26683U, 19194U, 24533U, 24625U, 
    16051U, 24494U, 19696U, 24643U, 29856U, 26279U, 29664U, 24572U, 
    26261U, 23998U, 29297U, 24017U, 28808U, 29317U, 24173U, 28882U, 
    29355U, 21445U, 20018U, 16225U, 19780U, 29892U, 30050U, 19523U, 
    16120U, 19726U, 29874U, 29734U, 19157U, 24513U, 24606U, 29646U, 
    24552U, 26242U, 16014U, 16710U, 15995U, 16687U, 19047U, 26399U, 
    15977U, 26322U, 26492U, 29571U, 26665U, 25198U, 23655U, 15961U, 
    19661U, 21123U, 26172U, 29139U, 21103U, 28508U, 26152U, 28601U, 
    26360U, 15033U, 17665U, 22289U, 15049U, 24087U, 20586U, 23492U, 
    20354U, 21354U, 28827U, 21336U, 23785U, 29337U, 21393U, 23927U, 
    28928U, 29375U, 21633U, 30400U, 20480U, 24738U, 21302U, 28984U, 
    24788U, 22535U, 22908U, 25265U, 23694U, 21614U, 30415U, 25213U, 
    15065U, 28999U, 18637U, 18813U, 17302U, 23085U, 18884U, 18195U, 
    23137U, 29798U, 23243U, 29516U, 23191U, 17336U, 23111U, 18708U, 
    18231U, 23164U, 29834U, 23270U, 29550U, 23217U, 18672U, 18848U, 
    18778U, 18954U, 18743U, 18919U, 17418U, 26627U, 24104U, 18253U, 
    28844U, 22654U, 18141U, 22495U, 25282U, 15537U, 15713U, 17249U, 
    26593U, 15755U, 22251U, 22794U, 30082U, 22434U, 30431U, 16174U, 
    17435U, 26646U, 24123U, 18272U, 28863U, 22673U, 18161U, 22515U, 
    25302U, 15554U, 15734U, 17269U, 26610U, 15776U, 22270U, 22813U, 
    30099U, 22451U, 30448U, 16191U, 20248U, 20424U, 1218U, 2261U, 
    2387U, 5033U, 148U, 2988U, 1260U, 2303U, 2578U, 5224U, 
    190U, 3030U, 2643U, 5267U, 212U, 3052U, 2428U, 5074U, 
    169U, 3009U, 96U, 44U, 233U, 2621U, 122U, 70U, 
    2684U, 5373U, 5438U, 20232U, 22477U, 23034U, 2812U, 5460U, 
    2492U, 5138U, 2857U, 5505U, 2535U, 5181U, 2834U, 5482U, 
    2513U, 5159U, 2879U, 5527U, 2556U, 5202U, 2748U, 5352U, 
    1198U, 4012U, 2791U, 5417U, 2241U, 4971U, 2726U, 5330U, 
    1177U, 3991U, 2769U, 5395U, 2220U, 4950U, 442U, 3256U, 
    1485U, 4215U, 901U, 3715U, 1944U, 4674U, 621U, 3435U, 
    1664U, 4394U, 1080U, 3894U, 2123U, 4853U, 697U, 3511U, 
    1740U, 4470U, 1156U, 3970U, 2199U, 4929U, 338U, 3152U, 
    1381U, 4111U, 797U, 3611U, 1840U, 4570U, 592U, 3406U, 
    1635U, 4365U, 1051U, 3865U, 2094U, 4824U, 522U, 3336U, 
    1565U, 4295U, 981U, 3795U, 2024U, 4754U, 650U, 3464U, 
    1693U, 4423U, 1109U, 3923U, 2152U, 4882U, 493U, 3307U, 
    1536U, 4266U, 952U, 3766U, 1995U, 4725U, 23888U, 390U, 
    3204U, 1433U, 4163U, 849U, 3663U, 1892U, 4622U, 570U, 
    3384U, 1613U, 4343U, 1029U, 3843U, 2072U, 4802U, 286U, 
    3100U, 1329U, 4059U, 745U, 3559U, 1788U, 4518U, 467U, 
    3281U, 1510U, 4240U, 926U, 3740U, 1969U, 4699U, 21429U, 
    416U, 3230U, 1459U, 4189U, 875U, 3689U, 1918U, 4648U, 
    675U, 3489U, 1718U, 4448U, 1134U, 3948U, 2177U, 4907U, 
    312U, 3126U, 1355U, 4085U, 771U, 3585U, 1814U, 4544U, 
    23869U, 363U, 3177U, 1406U, 4136U, 822U, 3636U, 1865U, 
    4595U, 547U, 3361U, 1590U, 4320U, 1006U, 3820U, 2049U, 
    4779U, 259U, 3073U, 1302U, 4032U, 718U, 3532U, 1761U, 
    4491U, 21412U, 20264U, 20441U, 17095U, 19136U, 29625U, 20071U, 
    24333U, 20097U, 24359U, 20123U, 24385U, 2407U, 5053U, 2599U, 
    5245U, 2663U, 5309U, 5573U, 26380U, 2448U, 5094U, 2345U, 
    4991U, 2470U, 5116U, 2366U, 21462U, 5012U, 21487U, 1238U, 
    16243U, 2281U, 16289U, 1280U, 16266U, 2323U, 16312U, 24U, 
    2706U, 17209U, 17699U, 22341U, 24820U, 25228U, 18058U, 22380U, 
    25163U, 25247U, 18076U, 22399U, 25180U, 29159U, 29218U, 29199U, 
    29413U, 29258U, 29452U, 29179U, 29393U, 29238U, 29432U, 21268U, 
    22737U, 16753U, 17718U, 16344U, 24838U, 17113U, 24200U, 16914U, 
    17879U, 16505U, 24992U, 28532U, 17161U, 19798U, 29910U, 22832U, 
    16822U, 17787U, 16413U, 24904U, 24257U, 16983U, 17948U, 16574U, 
    25058U, 28555U, 19858U, 29970U, 22756U, 16776U, 17741U, 16367U, 
    24860U, 18095U, 30148U, 24219U, 16937U, 17902U, 16528U, 25014U, 
    18118U, 30182U, 22602U, 19818U, 29930U, 22870U, 16868U, 17833U, 
    16459U, 24948U, 24295U, 17029U, 17994U, 16620U, 25102U, 28578U, 
    22628U, 19898U, 30010U, 9U, 22692U, 2947U, 22708U, 15834U, 
    22232U, 22929U, 20172U, 24434U, 2902U, 5550U, 29277U, 23601U, 
    23906U, 23556U, 22851U, 16845U, 17810U, 16436U, 24926U, 24276U, 
    17006U, 17971U, 16597U, 25080U, 19878U, 29990U, 22775U, 16799U, 
    17764U, 16390U, 24882U, 17137U, 24238U, 16960U, 17925U, 16551U, 
    25036U, 17185U, 19838U, 29950U, 22889U, 16891U, 17856U, 16482U, 
    24970U, 24314U, 17052U, 18017U, 16643U, 25124U, 19918U, 30030U, 
    21975U, 23979U, 20192U, 24454U, 15596U, 19117U, 15849U, 19540U, 
    15673U, 16088U, 20149U, 24411U, 20212U, 24474U, 15797U, 15889U, 
    18303U, 19958U, 26570U, 15655U, 21512U, 16069U, 21537U, 20000U, 
    21589U, 19761U, 21563U, 15909U, 19592U, 19011U, 29681U, 15615U, 
    19938U, 15635U, 19980U, 19029U, 29699U, 20335U, 30380U, 21250U, 
    30311U, 28486U, 23803U, 30216U, 17452U, 15283U, 28901U, 21735U, 
    20035U, 28699U, 23752U, 23963U, 23946U, 22305U, 24701U, 21198U, 
    22550U, 24155U, 20618U, 24068U, 20566U, 24755U, 21230U, 28789U, 
    17680U, 22321U, 24802U, 22565U, 18323U, 20372U, 29095U, 21373U, 
    24036U, 20532U, 15088U, 29026U, 18040U, 22361U, 25146U, 22584U, 
    20497U, 19677U, 2962U, 5287U, 23510U, 17229U, 29487U, 18363U, 
    29053U, 23580U, 23850U, 23534U, 18341U, 23769U, 30116U, 30247U, 
    30279U, 30348U, 15692U, 15868U, 20316U, 23052U, 23069U, 20297U, 
    15587U, 16335U, 18976U, 20062U, 15383U, 15449U, 18419U, 5650U, 
    5590U, 28433U, 5682U, 5620U, 18413U, 28945U, 28449U, 28427U, 
    28957U, 28460U, 28756U, 18599U, 5665U, 5604U, 28440U, 5697U, 
    5634U, 5901U, 9662U, 7741U, 10519U, 8475U, 5932U, 9714U, 
    7784U, 10577U, 8524U, 5952U, 9748U, 7812U, 10615U, 8556U, 
    15822U, 7525U, 10198U, 8205U, 11446U, 9306U, 12199U, 27524U, 
    26733U, 28095U, 27205U, 6900U, 17491U, 27569U, 26769U, 28126U, 
    27230U, 6578U, 9856U, 7902U, 11078U, 8977U, 17638U, 7565U, 
    10259U, 8257U, 11513U, 9364U, 12251U, 27786U, 26956U, 28266U, 
    27352U, 18490U, 6933U, 17534U, 27633U, 26824U, 28173U, 27271U, 
    18426U, 6642U, 9941U, 7978U, 11169U, 9059U, 19356U, 7591U, 
    10299U, 8291U, 11557U, 9402U, 12285U, 27817U, 26981U, 28281U, 
    27364U, 6949U, 17562U, 27675U, 26860U, 28196U, 27291U, 6684U, 
    9997U, 8028U, 11229U, 9113U, 16113U, 7551U, 10238U, 8239U, 
    11490U, 9344U, 12233U, 27555U, 26758U, 28110U, 27217U, 6998U, 
    6916U, 17519U, 27611U, 26805U, 28149U, 27250U, 6620U, 9912U, 
    7952U, 11138U, 9031U, 19719U, 7617U, 10339U, 8325U, 11601U, 
    9440U, 12319U, 27848U, 27006U, 28296U, 27376U, 7022U, 6965U, 
    17590U, 27717U, 26896U, 28219U, 27311U, 6726U, 10053U, 8078U, 
    11289U, 9167U, 29722U, 7631U, 10360U, 8343U, 11624U, 9460U, 
    12337U, 28027U, 27152U, 28412U, 27471U, 18608U, 6982U, 17605U, 
    27739U, 26915U, 28243U, 27332U, 18458U, 6748U, 10082U, 8104U, 
    11320U, 9195U, 17469U, 5921U, 9696U, 7769U, 10557U, 8507U, 
    5972U, 9782U, 7840U, 10653U, 8588U, 5983U, 9800U, 7855U, 
    10673U, 8605U, 15371U, 20054U, 24192U, 28907U, 21744U, 20050U, 
    25652U, 25974U, 25704U, 26022U, 25799U, 26077U, 25600U, 25926U, 
    25755U, 17362U, 7332U, 6208U, 20717U, 25674U, 20974U, 25998U, 
    20750U, 25726U, 21010U, 26046U, 20823U, 25819U, 21076U, 26099U, 
    20684U, 25622U, 20938U, 25950U, 20792U, 21042U, 20840U, 25836U, 
    21095U, 26118U, 7362U, 22724U, 26135U, 26225U, 26144U, 17395U, 
    26234U, 26126U, 26216U, 26058U, 17387U, 26208U, 15528U, 5749U, 
    16677U, 16164U, 15291U, 20902U, 25902U, 20761U, 22468U, 29114U, 
    20890U, 15518U, 5742U, 16666U, 16153U, 29071U, 20402U, 24662U, 
    20883U, 25879U, 6163U, 7105U, 7150U, 6216U, 7209U, 6270U, 
    6118U, 7046U, 6178U, 7120U, 7165U, 6234U, 7223U, 6288U, 
    6133U, 7061U, 6193U, 7135U, 7180U, 6252U, 7237U, 6306U, 
    6148U, 7090U, 15387U, 22731U, 5773U, 20859U, 25855U, 23479U, 
    20786U, 25783U, 5765U, 28009U, 27137U, 28397U, 27459U, 6092U, 
    6407U, 6498U, 7270U, 5793U, 6352U, 7392U, 6444U, 7447U, 
    7420U, 15817U, 27519U, 26728U, 10711U, 8658U, 17633U, 27781U, 
    26951U, 10880U, 8806U, 19351U, 27812U, 26976U, 10921U, 8841U, 
    16108U, 27550U, 26753U, 10752U, 8693U, 19714U, 27843U, 27001U, 
    10962U, 8876U, 29717U, 28022U, 27147U, 11668U, 9498U, 21159U, 
    27876U, 14300U, 27028U, 13484U, 10986U, 14748U, 8897U, 13878U, 
    13110U, 21187U, 27894U, 27043U, 11009U, 8917U, 21219U, 27912U, 
    14324U, 27058U, 13505U, 11032U, 14774U, 8937U, 13901U, 13127U, 
    21291U, 27930U, 14348U, 27073U, 13526U, 11055U, 14800U, 8957U, 
    13924U, 13144U, 5843U, 6003U, 5878U, 15485U, 2937U, 19575U, 
    5911U, 9679U, 14121U, 7755U, 13329U, 10538U, 14553U, 8491U, 
    13707U, 12987U, 5942U, 9731U, 7798U, 10596U, 8540U, 5962U, 
    9765U, 14141U, 7826U, 13346U, 10634U, 14575U, 8572U, 13726U, 
    13000U, 15828U, 7538U, 10218U, 14465U, 8222U, 13631U, 11468U, 
    14925U, 9325U, 14037U, 13281U, 12216U, 27537U, 14181U, 26743U, 
    13380U, 10734U, 14619U, 8678U, 13764U, 6861U, 10138U, 8154U, 
    11380U, 9249U, 17505U, 27590U, 14200U, 26787U, 13396U, 10776U, 
    14640U, 8714U, 13782U, 13038U, 6599U, 9884U, 14372U, 7927U, 
    13547U, 11108U, 14826U, 9004U, 13947U, 13177U, 13026U, 6565U, 
    13161U, 17644U, 7578U, 10279U, 8274U, 11535U, 9383U, 12268U, 
    27799U, 26966U, 10903U, 8826U, 18498U, 17548U, 27654U, 26842U, 
    10802U, 8737U, 18442U, 6663U, 9969U, 8003U, 11199U, 9086U, 
    6790U, 19362U, 7604U, 10319U, 14488U, 8308U, 13651U, 11579U, 
    14950U, 9421U, 14059U, 13297U, 12302U, 27830U, 14281U, 26991U, 
    13468U, 10944U, 14727U, 8861U, 13860U, 6874U, 10158U, 8171U, 
    11402U, 9268U, 17576U, 27696U, 14227U, 26878U, 13420U, 10828U, 
    14669U, 8760U, 13808U, 13058U, 6705U, 10025U, 14403U, 8053U, 
    13575U, 11259U, 14859U, 9140U, 13977U, 13201U, 13098U, 12930U, 
    6803U, 13249U, 29728U, 7644U, 10380U, 14511U, 8360U, 13671U, 
    11646U, 14975U, 9479U, 14081U, 13313U, 12354U, 28040U, 14534U, 
    27162U, 13691U, 11691U, 15000U, 9518U, 14103U, 18616U, 6887U, 
    10178U, 8188U, 11424U, 9287U, 17619U, 27760U, 14254U, 26933U, 
    13444U, 10854U, 14698U, 8783U, 13834U, 18474U, 13078U, 6769U, 
    10110U, 14434U, 8129U, 13603U, 11350U, 14892U, 9222U, 14007U, 
    13225U, 15021U, 12950U, 17480U, 6104U, 6848U, 13265U, 5993U, 
    9817U, 14161U, 7869U, 13363U, 10692U, 14597U, 8621U, 13745U, 
    13013U, 25462U, 20666U, 25593U, 27948U, 27088U, 28328U, 27402U, 
    6365U, 6456U, 16733U, 17075U, 15111U, 9557U, 7657U, 10400U, 
    8377U, 15265U, 9617U, 7705U, 10468U, 8433U, 15523U, 15429U, 
    29082U, 19000U, 15406U, 15419U, 5736U, 27483U, 26701U, 28053U, 
    27172U, 15286U, 5729U, 5807U, 27496U, 9647U, 18585U, 26711U, 
    7729U, 18574U, 28068U, 10502U, 27184U, 8461U, 18406U, 15275U, 
    12970U, 18291U, 26298U, 17367U, 27508U, 26720U, 28082U, 27195U, 
    20409U, 18506U, 24669U, 18540U, 21144U, 18523U, 26193U, 18387U, 
    18557U, 15471U, 2917U, 12418U, 11709U, 12674U, 11954U, 20860U, 
    25856U, 24142U, 20604U, 24054U, 20551U, 23683U, 23460U, 5782U, 
    23671U, 23478U, 25782U, 5764U, 28008U, 27136U, 28396U, 27458U, 
    17376U, 7269U, 7391U, 7446U, 7419U, 15116U, 9572U, 7669U, 
    10417U, 8391U, 15270U, 9632U, 7717U, 10485U, 8447U, 25471U, 
    25685U, 25507U, 25762U, 25461U, 25633U, 
};

static inline void InitHexagonMCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(HexagonInsts, HexagonInstrNameIndices, HexagonInstrNameData, 1717);
}

} // End llvm namespace 
#endif // GET_INSTRINFO_MC_DESC


#ifdef GET_INSTRINFO_HEADER
#undef GET_INSTRINFO_HEADER
namespace llvm {
struct HexagonGenInstrInfo : public TargetInstrInfo {
  explicit HexagonGenInstrInfo(int SO = -1, int DO = -1);
  virtual ~HexagonGenInstrInfo();
};
} // End llvm namespace 
#endif // GET_INSTRINFO_HEADER


#ifdef GET_INSTRINFO_CTOR_DTOR
#undef GET_INSTRINFO_CTOR_DTOR
namespace llvm {
extern const MCInstrDesc HexagonInsts[];
extern const unsigned HexagonInstrNameIndices[];
extern const char HexagonInstrNameData[];
HexagonGenInstrInfo::HexagonGenInstrInfo(int SO, int DO)
  : TargetInstrInfo(SO, DO) {
  InitMCInstrInfo(HexagonInsts, HexagonInstrNameIndices, HexagonInstrNameData, 1717);
}
HexagonGenInstrInfo::~HexagonGenInstrInfo() {}
} // End llvm namespace 
#endif // GET_INSTRINFO_CTOR_DTOR

#ifdef GET_INSTRINFO_OPERAND_ENUM
#undef GET_INSTRINFO_OPERAND_ENUM
namespace llvm {namespace Hexagon {
namespace OpName { 
enum {
OPERAND_LAST
};
} // End namespace OpName
} // End namespace Hexagon
} // End namespace llvm
#endif //GET_INSTRINFO_OPERAND_ENUM
#ifdef GET_INSTRINFO_NAMED_OPS
#undef GET_INSTRINFO_NAMED_OPS
namespace llvm {namespace Hexagon {
int16_t getNamedOperandIdx(uint16_t Opcode, uint16_t NamedIdx) {
  return -1;
}
} // End namespace Hexagon
} // End namespace llvm
#endif //GET_INSTRINFO_NAMED_OPS

#ifdef GET_INSTRINFO_OPERAND_TYPES_ENUM
#undef GET_INSTRINFO_OPERAND_TYPES_ENUM
namespace llvm {namespace Hexagon {
namespace OpTypes { 
enum OperandType {
  FrameIndex = 0,
  MEMri = 1,
  MEMri_s11_2 = 2,
  MEMrr = 3,
  bblabel = 4,
  brtarget = 5,
  brtargetExt = 6,
  calltarget = 7,
  f32Ext = 8,
  f32imm = 9,
  f64imm = 10,
  globaladdress = 11,
  globaladdressExt = 12,
  i16imm = 13,
  i1imm = 14,
  i32imm = 15,
  i64imm = 16,
  i8imm = 17,
  jumptablebase = 18,
  m6Imm = 19,
  m9Imm = 20,
  n8Imm = 21,
  nOneImm = 22,
  s10Ext = 23,
  s10Imm = 24,
  s11Imm = 25,
  s11_0Ext = 26,
  s11_0Imm = 27,
  s11_1Ext = 28,
  s11_1Imm = 29,
  s11_2Ext = 30,
  s11_2Imm = 31,
  s11_3Ext = 32,
  s11_3Imm = 33,
  s12Ext = 34,
  s12Imm = 35,
  s16Ext = 36,
  s16Imm = 37,
  s26_6Imm = 38,
  s32Imm = 39,
  s4Imm = 40,
  s4_0Imm = 41,
  s4_1Imm = 42,
  s4_2Imm = 43,
  s4_3Imm = 44,
  s6Ext = 45,
  s6Imm = 46,
  s8Ext = 47,
  s8Imm = 48,
  s8Imm64 = 49,
  s9Ext = 50,
  s9Imm = 51,
  symbolHi32 = 52,
  symbolLo32 = 53,
  u0AlwaysExt = 54,
  u10Ext = 55,
  u10Imm = 56,
  u11_3Imm = 57,
  u16Imm = 58,
  u16_0Imm = 59,
  u16_1Imm = 60,
  u16_2Imm = 61,
  u1Imm = 62,
  u26_6Imm = 63,
  u2Imm = 64,
  u32Imm = 65,
  u3Imm = 66,
  u4Imm = 67,
  u5Imm = 68,
  u64Imm = 69,
  u6Ext = 70,
  u6Imm = 71,
  u6_0Ext = 72,
  u6_0Imm = 73,
  u6_1Ext = 74,
  u6_1Imm = 75,
  u6_2Ext = 76,
  u6_2Imm = 77,
  u6_3Ext = 78,
  u6_3Imm = 79,
  u7Ext = 80,
  u7Imm = 81,
  u8Ext = 82,
  u8Imm = 83,
  u9Ext = 84,
  u9Imm = 85,
  OPERAND_TYPE_LIST_END
};
} // End namespace OpTypes
} // End namespace Hexagon
} // End namespace llvm
#endif // GET_INSTRINFO_OPERAND_TYPES_ENUM
#ifdef GET_INSTRMAP_INFO
#undef GET_INSTRMAP_INFO
namespace llvm {

namespace Hexagon {

enum InputType {
	InputType_reg
};

enum NValueST {
	NValueST_true,
	NValueST_false
};

enum PNewValue {
	PNewValue_new,
	PNewValue_
};

enum PredSense {
	PredSense_false,
	PredSense_true
};

enum addrMode {
	addrMode_BaseRegOffset,
	addrMode_BaseImmOffset
};

// getBaseWithRegOffset
int getBaseWithRegOffset(uint16_t Opcode) {
static const uint16_t getBaseWithRegOffsetTable[][2] = {
  { Hexagon::LDrib, Hexagon::LDrib_indexed_shl_V4 },
  { Hexagon::LDrib_cNotPt, Hexagon::LDrib_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrib_cPt, Hexagon::LDrib_indexed_shl_cPt_V4 },
  { Hexagon::LDrib_cdnNotPt, Hexagon::LDrib_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDrib_cdnPt, Hexagon::LDrib_indexed_shl_cdnPt_V4 },
  { Hexagon::LDrib_indexed, Hexagon::LDrib_indexed_shl_V4 },
  { Hexagon::LDrib_indexed_cNotPt, Hexagon::LDrib_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrib_indexed_cPt, Hexagon::LDrib_indexed_shl_cPt_V4 },
  { Hexagon::LDrib_indexed_cdnNotPt, Hexagon::LDrib_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDrib_indexed_cdnPt, Hexagon::LDrib_indexed_shl_cdnPt_V4 },
  { Hexagon::LDrid, Hexagon::LDrid_indexed_shl_V4 },
  { Hexagon::LDrid_cNotPt, Hexagon::LDrid_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrid_cPt, Hexagon::LDrid_indexed_shl_cPt_V4 },
  { Hexagon::LDrid_cdnNotPt, Hexagon::LDrid_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDrid_cdnPt, Hexagon::LDrid_indexed_shl_cdnPt_V4 },
  { Hexagon::LDrid_indexed, Hexagon::LDrid_indexed_shl_V4 },
  { Hexagon::LDrid_indexed_cNotPt, Hexagon::LDrid_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrid_indexed_cPt, Hexagon::LDrid_indexed_shl_cPt_V4 },
  { Hexagon::LDrid_indexed_cdnNotPt, Hexagon::LDrid_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDrid_indexed_cdnPt, Hexagon::LDrid_indexed_shl_cdnPt_V4 },
  { Hexagon::LDrih, Hexagon::LDrih_indexed_shl_V4 },
  { Hexagon::LDrih_cNotPt, Hexagon::LDrih_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrih_cPt, Hexagon::LDrih_indexed_shl_cPt_V4 },
  { Hexagon::LDrih_cdnNotPt, Hexagon::LDrih_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDrih_cdnPt, Hexagon::LDrih_indexed_shl_cdnPt_V4 },
  { Hexagon::LDrih_indexed, Hexagon::LDrih_indexed_shl_V4 },
  { Hexagon::LDrih_indexed_cNotPt, Hexagon::LDrih_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrih_indexed_cPt, Hexagon::LDrih_indexed_shl_cPt_V4 },
  { Hexagon::LDrih_indexed_cdnNotPt, Hexagon::LDrih_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDrih_indexed_cdnPt, Hexagon::LDrih_indexed_shl_cdnPt_V4 },
  { Hexagon::LDriub, Hexagon::LDriub_indexed_shl_V4 },
  { Hexagon::LDriub_cNotPt, Hexagon::LDriub_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriub_cPt, Hexagon::LDriub_indexed_shl_cPt_V4 },
  { Hexagon::LDriub_cdnNotPt, Hexagon::LDriub_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDriub_cdnPt, Hexagon::LDriub_indexed_shl_cdnPt_V4 },
  { Hexagon::LDriub_indexed, Hexagon::LDriub_indexed_shl_V4 },
  { Hexagon::LDriub_indexed_cNotPt, Hexagon::LDriub_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriub_indexed_cPt, Hexagon::LDriub_indexed_shl_cPt_V4 },
  { Hexagon::LDriub_indexed_cdnNotPt, Hexagon::LDriub_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDriub_indexed_cdnPt, Hexagon::LDriub_indexed_shl_cdnPt_V4 },
  { Hexagon::LDriuh, Hexagon::LDriuh_indexed_shl_V4 },
  { Hexagon::LDriuh_cNotPt, Hexagon::LDriuh_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriuh_cPt, Hexagon::LDriuh_indexed_shl_cPt_V4 },
  { Hexagon::LDriuh_cdnNotPt, Hexagon::LDriuh_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDriuh_cdnPt, Hexagon::LDriuh_indexed_shl_cdnPt_V4 },
  { Hexagon::LDriuh_indexed, Hexagon::LDriuh_indexed_shl_V4 },
  { Hexagon::LDriuh_indexed_cNotPt, Hexagon::LDriuh_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriuh_indexed_cPt, Hexagon::LDriuh_indexed_shl_cPt_V4 },
  { Hexagon::LDriuh_indexed_cdnNotPt, Hexagon::LDriuh_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDriuh_indexed_cdnPt, Hexagon::LDriuh_indexed_shl_cdnPt_V4 },
  { Hexagon::LDriw, Hexagon::LDriw_indexed_shl_V4 },
  { Hexagon::LDriw_cNotPt, Hexagon::LDriw_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriw_cPt, Hexagon::LDriw_indexed_shl_cPt_V4 },
  { Hexagon::LDriw_cdnNotPt, Hexagon::LDriw_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDriw_cdnPt, Hexagon::LDriw_indexed_shl_cdnPt_V4 },
  { Hexagon::LDriw_indexed, Hexagon::LDriw_indexed_shl_V4 },
  { Hexagon::LDriw_indexed_cNotPt, Hexagon::LDriw_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriw_indexed_cPt, Hexagon::LDriw_indexed_shl_cPt_V4 },
  { Hexagon::LDriw_indexed_cdnNotPt, Hexagon::LDriw_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDriw_indexed_cdnPt, Hexagon::LDriw_indexed_shl_cdnPt_V4 },
  { Hexagon::STrib, Hexagon::STrib_indexed_shl_V4 },
  { Hexagon::STrib_cNotPt, Hexagon::STrib_indexed_shl_cNotPt_V4 },
  { Hexagon::STrib_cNotPt_nv_V4, Hexagon::STrib_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STrib_cPt, Hexagon::STrib_indexed_shl_cPt_V4 },
  { Hexagon::STrib_cPt_nv_V4, Hexagon::STrib_indexed_shl_cPt_nv_V4 },
  { Hexagon::STrib_cdnNotPt_V4, Hexagon::STrib_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrib_cdnNotPt_nv_V4, Hexagon::STrib_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STrib_cdnPt_V4, Hexagon::STrib_indexed_shl_cdnPt_V4 },
  { Hexagon::STrib_cdnPt_nv_V4, Hexagon::STrib_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STrib_indexed, Hexagon::STrib_indexed_shl_V4 },
  { Hexagon::STrib_indexed_cNotPt, Hexagon::STrib_indexed_shl_cNotPt_V4 },
  { Hexagon::STrib_indexed_cNotPt_nv_V4, Hexagon::STrib_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STrib_indexed_cPt, Hexagon::STrib_indexed_shl_cPt_V4 },
  { Hexagon::STrib_indexed_cPt_nv_V4, Hexagon::STrib_indexed_shl_cPt_nv_V4 },
  { Hexagon::STrib_indexed_cdnNotPt_V4, Hexagon::STrib_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrib_indexed_cdnNotPt_nv_V4, Hexagon::STrib_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STrib_indexed_cdnPt_V4, Hexagon::STrib_indexed_shl_cdnPt_V4 },
  { Hexagon::STrib_indexed_cdnPt_nv_V4, Hexagon::STrib_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STrib_indexed_nv_V4, Hexagon::STrib_indexed_shl_nv_V4 },
  { Hexagon::STrib_nv_V4, Hexagon::STrib_indexed_shl_nv_V4 },
  { Hexagon::STrid, Hexagon::STrid_indexed_shl_V4 },
  { Hexagon::STrid_cNotPt, Hexagon::STrid_indexed_shl_cNotPt_V4 },
  { Hexagon::STrid_cPt, Hexagon::STrid_indexed_shl_cPt_V4 },
  { Hexagon::STrid_cdnNotPt_V4, Hexagon::STrid_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrid_cdnPt_V4, Hexagon::STrid_indexed_shl_cdnPt_V4 },
  { Hexagon::STrid_indexed, Hexagon::STrid_indexed_shl_V4 },
  { Hexagon::STrid_indexed_cNotPt, Hexagon::STrid_indexed_shl_cNotPt_V4 },
  { Hexagon::STrid_indexed_cPt, Hexagon::STrid_indexed_shl_cPt_V4 },
  { Hexagon::STrid_indexed_cdnNotPt_V4, Hexagon::STrid_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrid_indexed_cdnPt_V4, Hexagon::STrid_indexed_shl_cdnPt_V4 },
  { Hexagon::STrih, Hexagon::STrih_indexed_shl_V4 },
  { Hexagon::STrih_cNotPt, Hexagon::STrih_indexed_shl_cNotPt_V4 },
  { Hexagon::STrih_cNotPt_nv_V4, Hexagon::STrih_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STrih_cPt, Hexagon::STrih_indexed_shl_cPt_V4 },
  { Hexagon::STrih_cPt_nv_V4, Hexagon::STrih_indexed_shl_cPt_nv_V4 },
  { Hexagon::STrih_cdnNotPt_V4, Hexagon::STrih_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrih_cdnNotPt_nv_V4, Hexagon::STrih_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STrih_cdnPt_V4, Hexagon::STrih_indexed_shl_cdnPt_V4 },
  { Hexagon::STrih_cdnPt_nv_V4, Hexagon::STrih_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STrih_indexed, Hexagon::STrih_indexed_shl_V4 },
  { Hexagon::STrih_indexed_cNotPt, Hexagon::STrih_indexed_shl_cNotPt_V4 },
  { Hexagon::STrih_indexed_cNotPt_nv_V4, Hexagon::STrih_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STrih_indexed_cPt, Hexagon::STrih_indexed_shl_cPt_V4 },
  { Hexagon::STrih_indexed_cPt_nv_V4, Hexagon::STrih_indexed_shl_cPt_nv_V4 },
  { Hexagon::STrih_indexed_cdnNotPt_V4, Hexagon::STrih_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrih_indexed_cdnNotPt_nv_V4, Hexagon::STrih_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STrih_indexed_cdnPt_V4, Hexagon::STrih_indexed_shl_cdnPt_V4 },
  { Hexagon::STrih_indexed_cdnPt_nv_V4, Hexagon::STrih_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STrih_indexed_nv_V4, Hexagon::STrih_indexed_shl_nv_V4 },
  { Hexagon::STrih_nv_V4, Hexagon::STrih_indexed_shl_nv_V4 },
  { Hexagon::STriw, Hexagon::STriw_indexed_shl_V4 },
  { Hexagon::STriw_cNotPt, Hexagon::STriw_indexed_shl_cNotPt_V4 },
  { Hexagon::STriw_cNotPt_nv_V4, Hexagon::STriw_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STriw_cPt, Hexagon::STriw_indexed_shl_cPt_V4 },
  { Hexagon::STriw_cPt_nv_V4, Hexagon::STriw_indexed_shl_cPt_nv_V4 },
  { Hexagon::STriw_cdnNotPt_V4, Hexagon::STriw_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STriw_cdnNotPt_nv_V4, Hexagon::STriw_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STriw_cdnPt_V4, Hexagon::STriw_indexed_shl_cdnPt_V4 },
  { Hexagon::STriw_cdnPt_nv_V4, Hexagon::STriw_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STriw_indexed, Hexagon::STriw_indexed_shl_V4 },
  { Hexagon::STriw_indexed_cNotPt, Hexagon::STriw_indexed_shl_cNotPt_V4 },
  { Hexagon::STriw_indexed_cNotPt_nv_V4, Hexagon::STriw_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STriw_indexed_cPt, Hexagon::STriw_indexed_shl_cPt_V4 },
  { Hexagon::STriw_indexed_cPt_nv_V4, Hexagon::STriw_indexed_shl_cPt_nv_V4 },
  { Hexagon::STriw_indexed_cdnNotPt_V4, Hexagon::STriw_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STriw_indexed_cdnNotPt_nv_V4, Hexagon::STriw_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STriw_indexed_cdnPt_V4, Hexagon::STriw_indexed_shl_cdnPt_V4 },
  { Hexagon::STriw_indexed_cdnPt_nv_V4, Hexagon::STriw_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STriw_indexed_nv_V4, Hexagon::STriw_indexed_shl_nv_V4 },
  { Hexagon::STriw_nv_V4, Hexagon::STriw_indexed_shl_nv_V4 },
}; // End of getBaseWithRegOffsetTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 130;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getBaseWithRegOffsetTable[mid][0]) {
      break;
    }
    if (Opcode < getBaseWithRegOffsetTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getBaseWithRegOffsetTable[mid][1];
}

// getBasedWithImmOffset
int getBasedWithImmOffset(uint16_t Opcode) {
static const uint16_t getBasedWithImmOffsetTable[][2] = {
  { Hexagon::LDrib_abs_V4, Hexagon::LDrib_indexed },
  { Hexagon::LDrib_abs_cNotPt_V4, Hexagon::LDrib_indexed_cNotPt },
  { Hexagon::LDrib_abs_cPt_V4, Hexagon::LDrib_indexed_cPt },
  { Hexagon::LDrib_abs_cdnNotPt_V4, Hexagon::LDrib_indexed_cdnNotPt },
  { Hexagon::LDrib_abs_cdnPt_V4, Hexagon::LDrib_indexed_cdnPt },
  { Hexagon::LDrid_abs_V4, Hexagon::LDrid_indexed },
  { Hexagon::LDrid_abs_cNotPt_V4, Hexagon::LDrid_indexed_cNotPt },
  { Hexagon::LDrid_abs_cPt_V4, Hexagon::LDrid_indexed_cPt },
  { Hexagon::LDrid_abs_cdnNotPt_V4, Hexagon::LDrid_indexed_cdnNotPt },
  { Hexagon::LDrid_abs_cdnPt_V4, Hexagon::LDrid_indexed_cdnPt },
  { Hexagon::LDrih_abs_V4, Hexagon::LDrih_indexed },
  { Hexagon::LDrih_abs_cNotPt_V4, Hexagon::LDrih_indexed_cNotPt },
  { Hexagon::LDrih_abs_cPt_V4, Hexagon::LDrih_indexed_cPt },
  { Hexagon::LDrih_abs_cdnNotPt_V4, Hexagon::LDrih_indexed_cdnNotPt },
  { Hexagon::LDrih_abs_cdnPt_V4, Hexagon::LDrih_indexed_cdnPt },
  { Hexagon::LDriub_abs_V4, Hexagon::LDriub_indexed },
  { Hexagon::LDriub_abs_cNotPt_V4, Hexagon::LDriub_indexed_cNotPt },
  { Hexagon::LDriub_abs_cPt_V4, Hexagon::LDriub_indexed_cPt },
  { Hexagon::LDriub_abs_cdnNotPt_V4, Hexagon::LDriub_indexed_cdnNotPt },
  { Hexagon::LDriub_abs_cdnPt_V4, Hexagon::LDriub_indexed_cdnPt },
  { Hexagon::LDriuh_abs_V4, Hexagon::LDriuh_indexed },
  { Hexagon::LDriuh_abs_cNotPt_V4, Hexagon::LDriuh_indexed_cNotPt },
  { Hexagon::LDriuh_abs_cPt_V4, Hexagon::LDriuh_indexed_cPt },
  { Hexagon::LDriuh_abs_cdnNotPt_V4, Hexagon::LDriuh_indexed_cdnNotPt },
  { Hexagon::LDriuh_abs_cdnPt_V4, Hexagon::LDriuh_indexed_cdnPt },
  { Hexagon::LDriw_abs_V4, Hexagon::LDriw_indexed },
  { Hexagon::LDriw_abs_cNotPt_V4, Hexagon::LDriw_indexed_cNotPt },
  { Hexagon::LDriw_abs_cPt_V4, Hexagon::LDriw_indexed_cPt },
  { Hexagon::LDriw_abs_cdnNotPt_V4, Hexagon::LDriw_indexed_cdnNotPt },
  { Hexagon::LDriw_abs_cdnPt_V4, Hexagon::LDriw_indexed_cdnPt },
  { Hexagon::STrib_abs_V4, Hexagon::STrib_indexed },
  { Hexagon::STrib_abs_cNotPt_V4, Hexagon::STrib_indexed_cNotPt },
  { Hexagon::STrib_abs_cNotPt_nv_V4, Hexagon::STrib_indexed_cNotPt_nv_V4 },
  { Hexagon::STrib_abs_cPt_V4, Hexagon::STrib_indexed_cPt },
  { Hexagon::STrib_abs_cPt_nv_V4, Hexagon::STrib_indexed_cPt_nv_V4 },
  { Hexagon::STrib_abs_cdnNotPt_V4, Hexagon::STrib_indexed_cdnNotPt_V4 },
  { Hexagon::STrib_abs_cdnNotPt_nv_V4, Hexagon::STrib_indexed_cdnNotPt_nv_V4 },
  { Hexagon::STrib_abs_cdnPt_V4, Hexagon::STrib_indexed_cdnPt_V4 },
  { Hexagon::STrib_abs_cdnPt_nv_V4, Hexagon::STrib_indexed_cdnPt_nv_V4 },
  { Hexagon::STrib_abs_nv_V4, Hexagon::STrib_indexed_nv_V4 },
  { Hexagon::STrid_abs_V4, Hexagon::STrid_indexed },
  { Hexagon::STrid_abs_cNotPt_V4, Hexagon::STrid_indexed_cNotPt },
  { Hexagon::STrid_abs_cPt_V4, Hexagon::STrid_indexed_cPt },
  { Hexagon::STrid_abs_cdnNotPt_V4, Hexagon::STrid_indexed_cdnNotPt_V4 },
  { Hexagon::STrid_abs_cdnPt_V4, Hexagon::STrid_indexed_cdnPt_V4 },
  { Hexagon::STrih_abs_V4, Hexagon::STrih_indexed },
  { Hexagon::STrih_abs_cNotPt_V4, Hexagon::STrih_indexed_cNotPt },
  { Hexagon::STrih_abs_cNotPt_nv_V4, Hexagon::STrih_indexed_cNotPt_nv_V4 },
  { Hexagon::STrih_abs_cPt_V4, Hexagon::STrih_indexed_cPt },
  { Hexagon::STrih_abs_cPt_nv_V4, Hexagon::STrih_indexed_cPt_nv_V4 },
  { Hexagon::STrih_abs_cdnNotPt_V4, Hexagon::STrih_indexed_cdnNotPt_V4 },
  { Hexagon::STrih_abs_cdnNotPt_nv_V4, Hexagon::STrih_indexed_cdnNotPt_nv_V4 },
  { Hexagon::STrih_abs_cdnPt_V4, Hexagon::STrih_indexed_cdnPt_V4 },
  { Hexagon::STrih_abs_cdnPt_nv_V4, Hexagon::STrih_indexed_cdnPt_nv_V4 },
  { Hexagon::STrih_abs_nv_V4, Hexagon::STrih_indexed_nv_V4 },
  { Hexagon::STriw_abs_V4, Hexagon::STriw_indexed },
  { Hexagon::STriw_abs_cNotPt_V4, Hexagon::STriw_indexed_cNotPt },
  { Hexagon::STriw_abs_cNotPt_nv_V4, Hexagon::STriw_indexed_cNotPt_nv_V4 },
  { Hexagon::STriw_abs_cPt_V4, Hexagon::STriw_indexed_cPt },
  { Hexagon::STriw_abs_cPt_nv_V4, Hexagon::STriw_indexed_cPt_nv_V4 },
  { Hexagon::STriw_abs_cdnNotPt_V4, Hexagon::STriw_indexed_cdnNotPt_V4 },
  { Hexagon::STriw_abs_cdnNotPt_nv_V4, Hexagon::STriw_indexed_cdnNotPt_nv_V4 },
  { Hexagon::STriw_abs_cdnPt_V4, Hexagon::STriw_indexed_cdnPt_V4 },
  { Hexagon::STriw_abs_cdnPt_nv_V4, Hexagon::STriw_indexed_cdnPt_nv_V4 },
  { Hexagon::STriw_abs_nv_V4, Hexagon::STriw_indexed_nv_V4 },
}; // End of getBasedWithImmOffsetTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 65;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getBasedWithImmOffsetTable[mid][0]) {
      break;
    }
    if (Opcode < getBasedWithImmOffsetTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getBasedWithImmOffsetTable[mid][1];
}

// getFalsePredOpcode
int getFalsePredOpcode(uint16_t Opcode) {
static const uint16_t getFalsePredOpcodeTable[][2] = {
  { Hexagon::ADD_ri_cPt, Hexagon::ADD_ri_cNotPt },
  { Hexagon::ADD_ri_cdnPt, Hexagon::ADD_ri_cdnNotPt },
  { Hexagon::ADD_rr_cPt, Hexagon::ADD_rr_cNotPt },
  { Hexagon::ADD_rr_cdnPt, Hexagon::ADD_rr_cdnNotPt },
  { Hexagon::AND_rr_cPt, Hexagon::AND_rr_cNotPt },
  { Hexagon::AND_rr_cdnPt, Hexagon::AND_rr_cdnNotPt },
  { Hexagon::ASLH_cPt_V4, Hexagon::ASLH_cNotPt_V4 },
  { Hexagon::ASLH_cdnPt_V4, Hexagon::ASLH_cdnNotPt_V4 },
  { Hexagon::ASRH_cPt_V4, Hexagon::ASRH_cNotPt_V4 },
  { Hexagon::ASRH_cdnPt_V4, Hexagon::ASRH_cdnNotPt_V4 },
  { Hexagon::CMPEQn1_t_Jumpnv_nt_V4, Hexagon::CMPEQn1_f_Jumpnv_nt_V4 },
  { Hexagon::CMPEQn1_t_Jumpnv_t_V4, Hexagon::CMPEQn1_f_Jumpnv_t_V4 },
  { Hexagon::CMPEQri_t_Jumpnv_nt_V4, Hexagon::CMPEQri_f_Jumpnv_nt_V4 },
  { Hexagon::CMPEQri_t_Jumpnv_t_V4, Hexagon::CMPEQri_f_Jumpnv_t_V4 },
  { Hexagon::CMPEQrr_t_Jumpnv_nt_V4, Hexagon::CMPEQrr_f_Jumpnv_nt_V4 },
  { Hexagon::CMPEQrr_t_Jumpnv_t_V4, Hexagon::CMPEQrr_f_Jumpnv_t_V4 },
  { Hexagon::CMPGTUri_t_Jumpnv_nt_V4, Hexagon::CMPGTUri_f_Jumpnv_nt_V4 },
  { Hexagon::CMPGTUri_t_Jumpnv_t_V4, Hexagon::CMPGTUri_f_Jumpnv_t_V4 },
  { Hexagon::CMPGTUrr_t_Jumpnv_nt_V4, Hexagon::CMPGTUrr_f_Jumpnv_nt_V4 },
  { Hexagon::CMPGTUrr_t_Jumpnv_t_V4, Hexagon::CMPGTUrr_f_Jumpnv_t_V4 },
  { Hexagon::CMPGTn1_t_Jumpnv_nt_V4, Hexagon::CMPGTn1_f_Jumpnv_nt_V4 },
  { Hexagon::CMPGTn1_t_Jumpnv_t_V4, Hexagon::CMPGTn1_f_Jumpnv_t_V4 },
  { Hexagon::CMPGTri_t_Jumpnv_nt_V4, Hexagon::CMPGTri_f_Jumpnv_nt_V4 },
  { Hexagon::CMPGTri_t_Jumpnv_t_V4, Hexagon::CMPGTri_f_Jumpnv_t_V4 },
  { Hexagon::CMPGTrr_t_Jumpnv_nt_V4, Hexagon::CMPGTrr_f_Jumpnv_nt_V4 },
  { Hexagon::CMPGTrr_t_Jumpnv_t_V4, Hexagon::CMPGTrr_f_Jumpnv_t_V4 },
  { Hexagon::CMPLTUrr_t_Jumpnv_nt_V4, Hexagon::CMPLTUrr_f_Jumpnv_nt_V4 },
  { Hexagon::CMPLTUrr_t_Jumpnv_t_V4, Hexagon::CMPLTUrr_f_Jumpnv_t_V4 },
  { Hexagon::CMPLTrr_t_Jumpnv_nt_V4, Hexagon::CMPLTrr_f_Jumpnv_nt_V4 },
  { Hexagon::CMPLTrr_t_Jumpnv_t_V4, Hexagon::CMPLTrr_f_Jumpnv_t_V4 },
  { Hexagon::COMBINE_rr_cPt, Hexagon::COMBINE_rr_cNotPt },
  { Hexagon::COMBINE_rr_cdnPt, Hexagon::COMBINE_rr_cdnNotPt },
  { Hexagon::JMPR_t, Hexagon::JMPR_f },
  { Hexagon::JMPR_tnew_ntV3, Hexagon::JMPR_fnew_ntV3 },
  { Hexagon::JMPR_tnew_tV3, Hexagon::JMPR_fnew_tV3 },
  { Hexagon::JMP_t, Hexagon::JMP_f },
  { Hexagon::JMP_tnew_nt, Hexagon::JMP_fnew_nt },
  { Hexagon::JMP_tnew_t, Hexagon::JMP_fnew_t },
  { Hexagon::JMPret_t, Hexagon::JMPret_f },
  { Hexagon::JMPret_tnew_ntV3, Hexagon::JMPret_fnew_ntV3 },
  { Hexagon::JMPret_tnew_tV3, Hexagon::JMPret_fnew_tV3 },
  { Hexagon::LDb_GP_cPt_V4, Hexagon::LDb_GP_cNotPt_V4 },
  { Hexagon::LDb_GP_cdnPt_V4, Hexagon::LDb_GP_cdnNotPt_V4 },
  { Hexagon::LDd_GP_cPt_V4, Hexagon::LDd_GP_cNotPt_V4 },
  { Hexagon::LDd_GP_cdnPt_V4, Hexagon::LDd_GP_cdnNotPt_V4 },
  { Hexagon::LDh_GP_cPt_V4, Hexagon::LDh_GP_cNotPt_V4 },
  { Hexagon::LDh_GP_cdnPt_V4, Hexagon::LDh_GP_cdnNotPt_V4 },
  { Hexagon::LDrib_abs_cPt_V4, Hexagon::LDrib_abs_cNotPt_V4 },
  { Hexagon::LDrib_abs_cdnPt_V4, Hexagon::LDrib_abs_cdnNotPt_V4 },
  { Hexagon::LDrib_cPt, Hexagon::LDrib_cNotPt },
  { Hexagon::LDrib_cdnPt, Hexagon::LDrib_cdnNotPt },
  { Hexagon::LDrib_indexed_cPt, Hexagon::LDrib_indexed_cNotPt },
  { Hexagon::LDrib_indexed_cdnPt, Hexagon::LDrib_indexed_cdnNotPt },
  { Hexagon::LDrib_indexed_shl_cPt_V4, Hexagon::LDrib_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrib_indexed_shl_cdnPt_V4, Hexagon::LDrib_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDrid_abs_cPt_V4, Hexagon::LDrid_abs_cNotPt_V4 },
  { Hexagon::LDrid_abs_cdnPt_V4, Hexagon::LDrid_abs_cdnNotPt_V4 },
  { Hexagon::LDrid_cPt, Hexagon::LDrid_cNotPt },
  { Hexagon::LDrid_cdnPt, Hexagon::LDrid_cdnNotPt },
  { Hexagon::LDrid_indexed_cPt, Hexagon::LDrid_indexed_cNotPt },
  { Hexagon::LDrid_indexed_cdnPt, Hexagon::LDrid_indexed_cdnNotPt },
  { Hexagon::LDrid_indexed_shl_cPt_V4, Hexagon::LDrid_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrid_indexed_shl_cdnPt_V4, Hexagon::LDrid_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDrih_abs_cPt_V4, Hexagon::LDrih_abs_cNotPt_V4 },
  { Hexagon::LDrih_abs_cdnPt_V4, Hexagon::LDrih_abs_cdnNotPt_V4 },
  { Hexagon::LDrih_cPt, Hexagon::LDrih_cNotPt },
  { Hexagon::LDrih_cdnPt, Hexagon::LDrih_cdnNotPt },
  { Hexagon::LDrih_indexed_cPt, Hexagon::LDrih_indexed_cNotPt },
  { Hexagon::LDrih_indexed_cdnPt, Hexagon::LDrih_indexed_cdnNotPt },
  { Hexagon::LDrih_indexed_shl_cPt_V4, Hexagon::LDrih_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrih_indexed_shl_cdnPt_V4, Hexagon::LDrih_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDriub_abs_cPt_V4, Hexagon::LDriub_abs_cNotPt_V4 },
  { Hexagon::LDriub_abs_cdnPt_V4, Hexagon::LDriub_abs_cdnNotPt_V4 },
  { Hexagon::LDriub_cPt, Hexagon::LDriub_cNotPt },
  { Hexagon::LDriub_cdnPt, Hexagon::LDriub_cdnNotPt },
  { Hexagon::LDriub_indexed_cPt, Hexagon::LDriub_indexed_cNotPt },
  { Hexagon::LDriub_indexed_cdnPt, Hexagon::LDriub_indexed_cdnNotPt },
  { Hexagon::LDriub_indexed_shl_cPt_V4, Hexagon::LDriub_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriub_indexed_shl_cdnPt_V4, Hexagon::LDriub_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDriuh_abs_cPt_V4, Hexagon::LDriuh_abs_cNotPt_V4 },
  { Hexagon::LDriuh_abs_cdnPt_V4, Hexagon::LDriuh_abs_cdnNotPt_V4 },
  { Hexagon::LDriuh_cPt, Hexagon::LDriuh_cNotPt },
  { Hexagon::LDriuh_cdnPt, Hexagon::LDriuh_cdnNotPt },
  { Hexagon::LDriuh_indexed_cPt, Hexagon::LDriuh_indexed_cNotPt },
  { Hexagon::LDriuh_indexed_cdnPt, Hexagon::LDriuh_indexed_cdnNotPt },
  { Hexagon::LDriuh_indexed_shl_cPt_V4, Hexagon::LDriuh_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriuh_indexed_shl_cdnPt_V4, Hexagon::LDriuh_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDriw_abs_cPt_V4, Hexagon::LDriw_abs_cNotPt_V4 },
  { Hexagon::LDriw_abs_cdnPt_V4, Hexagon::LDriw_abs_cdnNotPt_V4 },
  { Hexagon::LDriw_cPt, Hexagon::LDriw_cNotPt },
  { Hexagon::LDriw_cdnPt, Hexagon::LDriw_cdnNotPt },
  { Hexagon::LDriw_indexed_cPt, Hexagon::LDriw_indexed_cNotPt },
  { Hexagon::LDriw_indexed_cdnPt, Hexagon::LDriw_indexed_cdnNotPt },
  { Hexagon::LDriw_indexed_shl_cPt_V4, Hexagon::LDriw_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriw_indexed_shl_cdnPt_V4, Hexagon::LDriw_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDub_GP_cPt_V4, Hexagon::LDub_GP_cNotPt_V4 },
  { Hexagon::LDub_GP_cdnPt_V4, Hexagon::LDub_GP_cdnNotPt_V4 },
  { Hexagon::LDuh_GP_cPt_V4, Hexagon::LDuh_GP_cNotPt_V4 },
  { Hexagon::LDuh_GP_cdnPt_V4, Hexagon::LDuh_GP_cdnNotPt_V4 },
  { Hexagon::LDw_GP_cPt_V4, Hexagon::LDw_GP_cNotPt_V4 },
  { Hexagon::LDw_GP_cdnPt_V4, Hexagon::LDw_GP_cdnNotPt_V4 },
  { Hexagon::OR_rr_cPt, Hexagon::OR_rr_cNotPt },
  { Hexagon::OR_rr_cdnPt, Hexagon::OR_rr_cdnNotPt },
  { Hexagon::POST_LDrib_cPt, Hexagon::POST_LDrib_cNotPt },
  { Hexagon::POST_LDrib_cdnPt_V4, Hexagon::POST_LDrib_cdnNotPt_V4 },
  { Hexagon::POST_LDrid_cPt, Hexagon::POST_LDrid_cNotPt },
  { Hexagon::POST_LDrid_cdnPt_V4, Hexagon::POST_LDrid_cdnNotPt_V4 },
  { Hexagon::POST_LDrih_cPt, Hexagon::POST_LDrih_cNotPt },
  { Hexagon::POST_LDrih_cdnPt_V4, Hexagon::POST_LDrih_cdnNotPt_V4 },
  { Hexagon::POST_LDriub_cPt, Hexagon::POST_LDriub_cNotPt },
  { Hexagon::POST_LDriub_cdnPt_V4, Hexagon::POST_LDriub_cdnNotPt_V4 },
  { Hexagon::POST_LDriuh_cPt, Hexagon::POST_LDriuh_cNotPt },
  { Hexagon::POST_LDriuh_cdnPt_V4, Hexagon::POST_LDriuh_cdnNotPt_V4 },
  { Hexagon::POST_LDriw_cPt, Hexagon::POST_LDriw_cNotPt },
  { Hexagon::POST_LDriw_cdnPt_V4, Hexagon::POST_LDriw_cdnNotPt_V4 },
  { Hexagon::POST_STbri_cPt, Hexagon::POST_STbri_cNotPt },
  { Hexagon::POST_STbri_cPt_nv_V4, Hexagon::POST_STbri_cNotPt_nv_V4 },
  { Hexagon::POST_STbri_cdnPt_V4, Hexagon::POST_STbri_cdnNotPt_V4 },
  { Hexagon::POST_STbri_cdnPt_nv_V4, Hexagon::POST_STbri_cdnNotPt_nv_V4 },
  { Hexagon::POST_STdri_cPt, Hexagon::POST_STdri_cNotPt },
  { Hexagon::POST_STdri_cdnPt_V4, Hexagon::POST_STdri_cdnNotPt_V4 },
  { Hexagon::POST_SThri_cPt, Hexagon::POST_SThri_cNotPt },
  { Hexagon::POST_SThri_cPt_nv_V4, Hexagon::POST_SThri_cNotPt_nv_V4 },
  { Hexagon::POST_SThri_cdnPt_V4, Hexagon::POST_SThri_cdnNotPt_V4 },
  { Hexagon::POST_SThri_cdnPt_nv_V4, Hexagon::POST_SThri_cdnNotPt_nv_V4 },
  { Hexagon::POST_STwri_cPt, Hexagon::POST_STwri_cNotPt },
  { Hexagon::POST_STwri_cPt_nv_V4, Hexagon::POST_STwri_cNotPt_nv_V4 },
  { Hexagon::POST_STwri_cdnPt_V4, Hexagon::POST_STwri_cdnNotPt_V4 },
  { Hexagon::POST_STwri_cdnPt_nv_V4, Hexagon::POST_STwri_cdnNotPt_nv_V4 },
  { Hexagon::STb_GP_cPt_V4, Hexagon::STb_GP_cNotPt_V4 },
  { Hexagon::STb_GP_cPt_nv_V4, Hexagon::STb_GP_cNotPt_nv_V4 },
  { Hexagon::STb_GP_cdnPt_V4, Hexagon::STb_GP_cdnNotPt_V4 },
  { Hexagon::STb_GP_cdnPt_nv_V4, Hexagon::STb_GP_cdnNotPt_nv_V4 },
  { Hexagon::STd_GP_cPt_V4, Hexagon::STd_GP_cNotPt_V4 },
  { Hexagon::STd_GP_cdnPt_V4, Hexagon::STd_GP_cdnNotPt_V4 },
  { Hexagon::STh_GP_cPt_V4, Hexagon::STh_GP_cNotPt_V4 },
  { Hexagon::STh_GP_cPt_nv_V4, Hexagon::STh_GP_cNotPt_nv_V4 },
  { Hexagon::STh_GP_cdnPt_V4, Hexagon::STh_GP_cdnNotPt_V4 },
  { Hexagon::STh_GP_cdnPt_nv_V4, Hexagon::STh_GP_cdnNotPt_nv_V4 },
  { Hexagon::STrib_abs_cPt_V4, Hexagon::STrib_abs_cNotPt_V4 },
  { Hexagon::STrib_abs_cPt_nv_V4, Hexagon::STrib_abs_cNotPt_nv_V4 },
  { Hexagon::STrib_abs_cdnPt_V4, Hexagon::STrib_abs_cdnNotPt_V4 },
  { Hexagon::STrib_abs_cdnPt_nv_V4, Hexagon::STrib_abs_cdnNotPt_nv_V4 },
  { Hexagon::STrib_cPt, Hexagon::STrib_cNotPt },
  { Hexagon::STrib_cPt_nv_V4, Hexagon::STrib_cNotPt_nv_V4 },
  { Hexagon::STrib_cdnPt_V4, Hexagon::STrib_cdnNotPt_V4 },
  { Hexagon::STrib_cdnPt_nv_V4, Hexagon::STrib_cdnNotPt_nv_V4 },
  { Hexagon::STrib_imm_cPt_V4, Hexagon::STrib_imm_cNotPt_V4 },
  { Hexagon::STrib_imm_cdnPt_V4, Hexagon::STrib_imm_cdnNotPt_V4 },
  { Hexagon::STrib_indexed_cPt, Hexagon::STrib_indexed_cNotPt },
  { Hexagon::STrib_indexed_cPt_nv_V4, Hexagon::STrib_indexed_cNotPt_nv_V4 },
  { Hexagon::STrib_indexed_cdnPt_V4, Hexagon::STrib_indexed_cdnNotPt_V4 },
  { Hexagon::STrib_indexed_cdnPt_nv_V4, Hexagon::STrib_indexed_cdnNotPt_nv_V4 },
  { Hexagon::STrib_indexed_shl_cPt_V4, Hexagon::STrib_indexed_shl_cNotPt_V4 },
  { Hexagon::STrib_indexed_shl_cPt_nv_V4, Hexagon::STrib_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STrib_indexed_shl_cdnPt_V4, Hexagon::STrib_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrib_indexed_shl_cdnPt_nv_V4, Hexagon::STrib_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STrid_abs_cPt_V4, Hexagon::STrid_abs_cNotPt_V4 },
  { Hexagon::STrid_abs_cdnPt_V4, Hexagon::STrid_abs_cdnNotPt_V4 },
  { Hexagon::STrid_cPt, Hexagon::STrid_cNotPt },
  { Hexagon::STrid_cdnPt_V4, Hexagon::STrid_cdnNotPt_V4 },
  { Hexagon::STrid_indexed_cPt, Hexagon::STrid_indexed_cNotPt },
  { Hexagon::STrid_indexed_cdnPt_V4, Hexagon::STrid_indexed_cdnNotPt_V4 },
  { Hexagon::STrid_indexed_shl_cPt_V4, Hexagon::STrid_indexed_shl_cNotPt_V4 },
  { Hexagon::STrid_indexed_shl_cdnPt_V4, Hexagon::STrid_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrih_abs_cPt_V4, Hexagon::STrih_abs_cNotPt_V4 },
  { Hexagon::STrih_abs_cPt_nv_V4, Hexagon::STrih_abs_cNotPt_nv_V4 },
  { Hexagon::STrih_abs_cdnPt_V4, Hexagon::STrih_abs_cdnNotPt_V4 },
  { Hexagon::STrih_abs_cdnPt_nv_V4, Hexagon::STrih_abs_cdnNotPt_nv_V4 },
  { Hexagon::STrih_cPt, Hexagon::STrih_cNotPt },
  { Hexagon::STrih_cPt_nv_V4, Hexagon::STrih_cNotPt_nv_V4 },
  { Hexagon::STrih_cdnPt_V4, Hexagon::STrih_cdnNotPt_V4 },
  { Hexagon::STrih_cdnPt_nv_V4, Hexagon::STrih_cdnNotPt_nv_V4 },
  { Hexagon::STrih_imm_cPt_V4, Hexagon::STrih_imm_cNotPt_V4 },
  { Hexagon::STrih_imm_cdnPt_V4, Hexagon::STrih_imm_cdnNotPt_V4 },
  { Hexagon::STrih_indexed_cPt, Hexagon::STrih_indexed_cNotPt },
  { Hexagon::STrih_indexed_cPt_nv_V4, Hexagon::STrih_indexed_cNotPt_nv_V4 },
  { Hexagon::STrih_indexed_cdnPt_V4, Hexagon::STrih_indexed_cdnNotPt_V4 },
  { Hexagon::STrih_indexed_cdnPt_nv_V4, Hexagon::STrih_indexed_cdnNotPt_nv_V4 },
  { Hexagon::STrih_indexed_shl_cPt_V4, Hexagon::STrih_indexed_shl_cNotPt_V4 },
  { Hexagon::STrih_indexed_shl_cPt_nv_V4, Hexagon::STrih_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STrih_indexed_shl_cdnPt_V4, Hexagon::STrih_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrih_indexed_shl_cdnPt_nv_V4, Hexagon::STrih_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STriw_abs_cPt_V4, Hexagon::STriw_abs_cNotPt_V4 },
  { Hexagon::STriw_abs_cPt_nv_V4, Hexagon::STriw_abs_cNotPt_nv_V4 },
  { Hexagon::STriw_abs_cdnPt_V4, Hexagon::STriw_abs_cdnNotPt_V4 },
  { Hexagon::STriw_abs_cdnPt_nv_V4, Hexagon::STriw_abs_cdnNotPt_nv_V4 },
  { Hexagon::STriw_cPt, Hexagon::STriw_cNotPt },
  { Hexagon::STriw_cPt_nv_V4, Hexagon::STriw_cNotPt_nv_V4 },
  { Hexagon::STriw_cdnPt_V4, Hexagon::STriw_cdnNotPt_V4 },
  { Hexagon::STriw_cdnPt_nv_V4, Hexagon::STriw_cdnNotPt_nv_V4 },
  { Hexagon::STriw_imm_cPt_V4, Hexagon::STriw_imm_cNotPt_V4 },
  { Hexagon::STriw_imm_cdnPt_V4, Hexagon::STriw_imm_cdnNotPt_V4 },
  { Hexagon::STriw_indexed_cPt, Hexagon::STriw_indexed_cNotPt },
  { Hexagon::STriw_indexed_cPt_nv_V4, Hexagon::STriw_indexed_cNotPt_nv_V4 },
  { Hexagon::STriw_indexed_cdnPt_V4, Hexagon::STriw_indexed_cdnNotPt_V4 },
  { Hexagon::STriw_indexed_cdnPt_nv_V4, Hexagon::STriw_indexed_cdnNotPt_nv_V4 },
  { Hexagon::STriw_indexed_shl_cPt_V4, Hexagon::STriw_indexed_shl_cNotPt_V4 },
  { Hexagon::STriw_indexed_shl_cPt_nv_V4, Hexagon::STriw_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STriw_indexed_shl_cdnPt_V4, Hexagon::STriw_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STriw_indexed_shl_cdnPt_nv_V4, Hexagon::STriw_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STw_GP_cPt_V4, Hexagon::STw_GP_cNotPt_V4 },
  { Hexagon::STw_GP_cPt_nv_V4, Hexagon::STw_GP_cNotPt_nv_V4 },
  { Hexagon::STw_GP_cdnPt_V4, Hexagon::STw_GP_cdnNotPt_V4 },
  { Hexagon::STw_GP_cdnPt_nv_V4, Hexagon::STw_GP_cdnNotPt_nv_V4 },
  { Hexagon::SUB_rr_cPt, Hexagon::SUB_rr_cNotPt },
  { Hexagon::SUB_rr_cdnPt, Hexagon::SUB_rr_cdnNotPt },
  { Hexagon::SXTB_cPt_V4, Hexagon::SXTB_cNotPt_V4 },
  { Hexagon::SXTB_cdnPt_V4, Hexagon::SXTB_cdnNotPt_V4 },
  { Hexagon::SXTH_cPt_V4, Hexagon::SXTH_cNotPt_V4 },
  { Hexagon::SXTH_cdnPt_V4, Hexagon::SXTH_cdnNotPt_V4 },
  { Hexagon::TFR64_cPt, Hexagon::TFR64_cNotPt },
  { Hexagon::TFR64_cdnPt, Hexagon::TFR64_cdnNotPt },
  { Hexagon::TFRI_cPt, Hexagon::TFRI_cNotPt },
  { Hexagon::TFRI_cdnPt, Hexagon::TFRI_cdnNotPt },
  { Hexagon::TFR_cPt, Hexagon::TFR_cNotPt },
  { Hexagon::TFR_cdnPt, Hexagon::TFR_cdnNotPt },
  { Hexagon::TSTBIT0_t_Jumpnv_nt_V4, Hexagon::TSTBIT0_f_Jumpnv_nt_V4 },
  { Hexagon::TSTBIT0_t_Jumpnv_t_V4, Hexagon::TSTBIT0_f_Jumpnv_t_V4 },
  { Hexagon::XOR_rr_cPt, Hexagon::XOR_rr_cNotPt },
  { Hexagon::XOR_rr_cdnPt, Hexagon::XOR_rr_cdnNotPt },
  { Hexagon::ZXTB_cPt_V4, Hexagon::ZXTB_cNotPt_V4 },
  { Hexagon::ZXTB_cdnPt_V4, Hexagon::ZXTB_cdnNotPt_V4 },
  { Hexagon::ZXTH_cPt_V4, Hexagon::ZXTH_cNotPt_V4 },
  { Hexagon::ZXTH_cdnPt_V4, Hexagon::ZXTH_cdnNotPt_V4 },
}; // End of getFalsePredOpcodeTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 225;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getFalsePredOpcodeTable[mid][0]) {
      break;
    }
    if (Opcode < getFalsePredOpcodeTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getFalsePredOpcodeTable[mid][1];
}

// getNewValueOpcode
int getNewValueOpcode(uint16_t Opcode) {
static const uint16_t getNewValueOpcodeTable[][2] = {
  { Hexagon::POST_STbri, Hexagon::POST_STbri_nv_V4 },
  { Hexagon::POST_STbri_cNotPt, Hexagon::POST_STbri_cNotPt_nv_V4 },
  { Hexagon::POST_STbri_cPt, Hexagon::POST_STbri_cPt_nv_V4 },
  { Hexagon::POST_STbri_cdnNotPt_V4, Hexagon::POST_STbri_cdnNotPt_nv_V4 },
  { Hexagon::POST_STbri_cdnPt_V4, Hexagon::POST_STbri_cdnPt_nv_V4 },
  { Hexagon::POST_SThri, Hexagon::POST_SThri_nv_V4 },
  { Hexagon::POST_SThri_cNotPt, Hexagon::POST_SThri_cNotPt_nv_V4 },
  { Hexagon::POST_SThri_cPt, Hexagon::POST_SThri_cPt_nv_V4 },
  { Hexagon::POST_SThri_cdnNotPt_V4, Hexagon::POST_SThri_cdnNotPt_nv_V4 },
  { Hexagon::POST_SThri_cdnPt_V4, Hexagon::POST_SThri_cdnPt_nv_V4 },
  { Hexagon::POST_STwri, Hexagon::POST_STwri_nv_V4 },
  { Hexagon::POST_STwri_cNotPt, Hexagon::POST_STwri_cNotPt_nv_V4 },
  { Hexagon::POST_STwri_cPt, Hexagon::POST_STwri_cPt_nv_V4 },
  { Hexagon::POST_STwri_cdnNotPt_V4, Hexagon::POST_STwri_cdnNotPt_nv_V4 },
  { Hexagon::POST_STwri_cdnPt_V4, Hexagon::POST_STwri_cdnPt_nv_V4 },
  { Hexagon::STb_GP_V4, Hexagon::STb_GP_nv_V4 },
  { Hexagon::STb_GP_cNotPt_V4, Hexagon::STb_GP_cNotPt_nv_V4 },
  { Hexagon::STb_GP_cPt_V4, Hexagon::STb_GP_cPt_nv_V4 },
  { Hexagon::STb_GP_cdnNotPt_V4, Hexagon::STb_GP_cdnNotPt_nv_V4 },
  { Hexagon::STb_GP_cdnPt_V4, Hexagon::STb_GP_cdnPt_nv_V4 },
  { Hexagon::STh_GP_V4, Hexagon::STh_GP_nv_V4 },
  { Hexagon::STh_GP_cNotPt_V4, Hexagon::STh_GP_cNotPt_nv_V4 },
  { Hexagon::STh_GP_cPt_V4, Hexagon::STh_GP_cPt_nv_V4 },
  { Hexagon::STh_GP_cdnNotPt_V4, Hexagon::STh_GP_cdnNotPt_nv_V4 },
  { Hexagon::STh_GP_cdnPt_V4, Hexagon::STh_GP_cdnPt_nv_V4 },
  { Hexagon::STrib, Hexagon::STrib_nv_V4 },
  { Hexagon::STrib_abs_V4, Hexagon::STrib_abs_nv_V4 },
  { Hexagon::STrib_abs_cNotPt_V4, Hexagon::STrib_abs_cNotPt_nv_V4 },
  { Hexagon::STrib_abs_cPt_V4, Hexagon::STrib_abs_cPt_nv_V4 },
  { Hexagon::STrib_abs_cdnNotPt_V4, Hexagon::STrib_abs_cdnNotPt_nv_V4 },
  { Hexagon::STrib_abs_cdnPt_V4, Hexagon::STrib_abs_cdnPt_nv_V4 },
  { Hexagon::STrib_cNotPt, Hexagon::STrib_cNotPt_nv_V4 },
  { Hexagon::STrib_cPt, Hexagon::STrib_cPt_nv_V4 },
  { Hexagon::STrib_cdnNotPt_V4, Hexagon::STrib_cdnNotPt_nv_V4 },
  { Hexagon::STrib_cdnPt_V4, Hexagon::STrib_cdnPt_nv_V4 },
  { Hexagon::STrib_indexed, Hexagon::STrib_indexed_nv_V4 },
  { Hexagon::STrib_indexed_cNotPt, Hexagon::STrib_indexed_cNotPt_nv_V4 },
  { Hexagon::STrib_indexed_cPt, Hexagon::STrib_indexed_cPt_nv_V4 },
  { Hexagon::STrib_indexed_cdnNotPt_V4, Hexagon::STrib_indexed_cdnNotPt_nv_V4 },
  { Hexagon::STrib_indexed_cdnPt_V4, Hexagon::STrib_indexed_cdnPt_nv_V4 },
  { Hexagon::STrib_indexed_shl_V4, Hexagon::STrib_indexed_shl_nv_V4 },
  { Hexagon::STrib_indexed_shl_cNotPt_V4, Hexagon::STrib_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STrib_indexed_shl_cPt_V4, Hexagon::STrib_indexed_shl_cPt_nv_V4 },
  { Hexagon::STrib_indexed_shl_cdnNotPt_V4, Hexagon::STrib_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STrib_indexed_shl_cdnPt_V4, Hexagon::STrib_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STrib_shl_V4, Hexagon::STrib_shl_nv_V4 },
  { Hexagon::STrih, Hexagon::STrih_nv_V4 },
  { Hexagon::STrih_abs_V4, Hexagon::STrih_abs_nv_V4 },
  { Hexagon::STrih_abs_cNotPt_V4, Hexagon::STrih_abs_cNotPt_nv_V4 },
  { Hexagon::STrih_abs_cPt_V4, Hexagon::STrih_abs_cPt_nv_V4 },
  { Hexagon::STrih_abs_cdnNotPt_V4, Hexagon::STrih_abs_cdnNotPt_nv_V4 },
  { Hexagon::STrih_abs_cdnPt_V4, Hexagon::STrih_abs_cdnPt_nv_V4 },
  { Hexagon::STrih_cNotPt, Hexagon::STrih_cNotPt_nv_V4 },
  { Hexagon::STrih_cPt, Hexagon::STrih_cPt_nv_V4 },
  { Hexagon::STrih_cdnNotPt_V4, Hexagon::STrih_cdnNotPt_nv_V4 },
  { Hexagon::STrih_cdnPt_V4, Hexagon::STrih_cdnPt_nv_V4 },
  { Hexagon::STrih_indexed, Hexagon::STrih_indexed_nv_V4 },
  { Hexagon::STrih_indexed_cNotPt, Hexagon::STrih_indexed_cNotPt_nv_V4 },
  { Hexagon::STrih_indexed_cPt, Hexagon::STrih_indexed_cPt_nv_V4 },
  { Hexagon::STrih_indexed_cdnNotPt_V4, Hexagon::STrih_indexed_cdnNotPt_nv_V4 },
  { Hexagon::STrih_indexed_cdnPt_V4, Hexagon::STrih_indexed_cdnPt_nv_V4 },
  { Hexagon::STrih_indexed_shl_V4, Hexagon::STrih_indexed_shl_nv_V4 },
  { Hexagon::STrih_indexed_shl_cNotPt_V4, Hexagon::STrih_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STrih_indexed_shl_cPt_V4, Hexagon::STrih_indexed_shl_cPt_nv_V4 },
  { Hexagon::STrih_indexed_shl_cdnNotPt_V4, Hexagon::STrih_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STrih_indexed_shl_cdnPt_V4, Hexagon::STrih_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STrih_shl_V4, Hexagon::STrih_shl_nv_V4 },
  { Hexagon::STriw, Hexagon::STriw_nv_V4 },
  { Hexagon::STriw_abs_V4, Hexagon::STriw_abs_nv_V4 },
  { Hexagon::STriw_abs_cNotPt_V4, Hexagon::STriw_abs_cNotPt_nv_V4 },
  { Hexagon::STriw_abs_cPt_V4, Hexagon::STriw_abs_cPt_nv_V4 },
  { Hexagon::STriw_abs_cdnNotPt_V4, Hexagon::STriw_abs_cdnNotPt_nv_V4 },
  { Hexagon::STriw_abs_cdnPt_V4, Hexagon::STriw_abs_cdnPt_nv_V4 },
  { Hexagon::STriw_cNotPt, Hexagon::STriw_cNotPt_nv_V4 },
  { Hexagon::STriw_cPt, Hexagon::STriw_cPt_nv_V4 },
  { Hexagon::STriw_cdnNotPt_V4, Hexagon::STriw_cdnNotPt_nv_V4 },
  { Hexagon::STriw_cdnPt_V4, Hexagon::STriw_cdnPt_nv_V4 },
  { Hexagon::STriw_indexed, Hexagon::STriw_indexed_nv_V4 },
  { Hexagon::STriw_indexed_cNotPt, Hexagon::STriw_indexed_cNotPt_nv_V4 },
  { Hexagon::STriw_indexed_cPt, Hexagon::STriw_indexed_cPt_nv_V4 },
  { Hexagon::STriw_indexed_cdnNotPt_V4, Hexagon::STriw_indexed_cdnNotPt_nv_V4 },
  { Hexagon::STriw_indexed_cdnPt_V4, Hexagon::STriw_indexed_cdnPt_nv_V4 },
  { Hexagon::STriw_indexed_shl_V4, Hexagon::STriw_indexed_shl_nv_V4 },
  { Hexagon::STriw_indexed_shl_cNotPt_V4, Hexagon::STriw_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STriw_indexed_shl_cPt_V4, Hexagon::STriw_indexed_shl_cPt_nv_V4 },
  { Hexagon::STriw_indexed_shl_cdnNotPt_V4, Hexagon::STriw_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STriw_indexed_shl_cdnPt_V4, Hexagon::STriw_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STriw_shl_V4, Hexagon::STriw_shl_nv_V4 },
  { Hexagon::STw_GP_V4, Hexagon::STw_GP_nv_V4 },
  { Hexagon::STw_GP_cNotPt_V4, Hexagon::STw_GP_cNotPt_nv_V4 },
  { Hexagon::STw_GP_cPt_V4, Hexagon::STw_GP_cPt_nv_V4 },
  { Hexagon::STw_GP_cdnNotPt_V4, Hexagon::STw_GP_cdnNotPt_nv_V4 },
  { Hexagon::STw_GP_cdnPt_V4, Hexagon::STw_GP_cdnPt_nv_V4 },
}; // End of getNewValueOpcodeTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 93;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getNewValueOpcodeTable[mid][0]) {
      break;
    }
    if (Opcode < getNewValueOpcodeTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getNewValueOpcodeTable[mid][1];
}

// getNonNVStore
int getNonNVStore(uint16_t Opcode) {
static const uint16_t getNonNVStoreTable[][2] = {
  { Hexagon::POST_STbri_cNotPt_nv_V4, Hexagon::POST_STbri_cNotPt },
  { Hexagon::POST_STbri_cPt_nv_V4, Hexagon::POST_STbri_cPt },
  { Hexagon::POST_STbri_cdnNotPt_nv_V4, Hexagon::POST_STbri_cdnNotPt_V4 },
  { Hexagon::POST_STbri_cdnPt_nv_V4, Hexagon::POST_STbri_cdnPt_V4 },
  { Hexagon::POST_STbri_nv_V4, Hexagon::POST_STbri },
  { Hexagon::POST_SThri_cNotPt_nv_V4, Hexagon::POST_SThri_cNotPt },
  { Hexagon::POST_SThri_cPt_nv_V4, Hexagon::POST_SThri_cPt },
  { Hexagon::POST_SThri_cdnNotPt_nv_V4, Hexagon::POST_SThri_cdnNotPt_V4 },
  { Hexagon::POST_SThri_cdnPt_nv_V4, Hexagon::POST_SThri_cdnPt_V4 },
  { Hexagon::POST_SThri_nv_V4, Hexagon::POST_SThri },
  { Hexagon::POST_STwri_cNotPt_nv_V4, Hexagon::POST_STwri_cNotPt },
  { Hexagon::POST_STwri_cPt_nv_V4, Hexagon::POST_STwri_cPt },
  { Hexagon::POST_STwri_cdnNotPt_nv_V4, Hexagon::POST_STwri_cdnNotPt_V4 },
  { Hexagon::POST_STwri_cdnPt_nv_V4, Hexagon::POST_STwri_cdnPt_V4 },
  { Hexagon::POST_STwri_nv_V4, Hexagon::POST_STwri },
  { Hexagon::STb_GP_cNotPt_nv_V4, Hexagon::STb_GP_cNotPt_V4 },
  { Hexagon::STb_GP_cPt_nv_V4, Hexagon::STb_GP_cPt_V4 },
  { Hexagon::STb_GP_cdnNotPt_nv_V4, Hexagon::STb_GP_cdnNotPt_V4 },
  { Hexagon::STb_GP_cdnPt_nv_V4, Hexagon::STb_GP_cdnPt_V4 },
  { Hexagon::STb_GP_nv_V4, Hexagon::STb_GP_V4 },
  { Hexagon::STh_GP_cNotPt_nv_V4, Hexagon::STh_GP_cNotPt_V4 },
  { Hexagon::STh_GP_cPt_nv_V4, Hexagon::STh_GP_cPt_V4 },
  { Hexagon::STh_GP_cdnNotPt_nv_V4, Hexagon::STh_GP_cdnNotPt_V4 },
  { Hexagon::STh_GP_cdnPt_nv_V4, Hexagon::STh_GP_cdnPt_V4 },
  { Hexagon::STh_GP_nv_V4, Hexagon::STh_GP_V4 },
  { Hexagon::STrib_abs_cNotPt_nv_V4, Hexagon::STrib_abs_cNotPt_V4 },
  { Hexagon::STrib_abs_cPt_nv_V4, Hexagon::STrib_abs_cPt_V4 },
  { Hexagon::STrib_abs_cdnNotPt_nv_V4, Hexagon::STrib_abs_cdnNotPt_V4 },
  { Hexagon::STrib_abs_cdnPt_nv_V4, Hexagon::STrib_abs_cdnPt_V4 },
  { Hexagon::STrib_abs_nv_V4, Hexagon::STrib_abs_V4 },
  { Hexagon::STrib_cNotPt_nv_V4, Hexagon::STrib_cNotPt },
  { Hexagon::STrib_cPt_nv_V4, Hexagon::STrib_cPt },
  { Hexagon::STrib_cdnNotPt_nv_V4, Hexagon::STrib_cdnNotPt_V4 },
  { Hexagon::STrib_cdnPt_nv_V4, Hexagon::STrib_cdnPt_V4 },
  { Hexagon::STrib_indexed_cNotPt_nv_V4, Hexagon::STrib_indexed_cNotPt },
  { Hexagon::STrib_indexed_cPt_nv_V4, Hexagon::STrib_indexed_cPt },
  { Hexagon::STrib_indexed_cdnNotPt_nv_V4, Hexagon::STrib_indexed_cdnNotPt_V4 },
  { Hexagon::STrib_indexed_cdnPt_nv_V4, Hexagon::STrib_indexed_cdnPt_V4 },
  { Hexagon::STrib_indexed_nv_V4, Hexagon::STrib_indexed },
  { Hexagon::STrib_indexed_shl_cNotPt_nv_V4, Hexagon::STrib_indexed_shl_cNotPt_V4 },
  { Hexagon::STrib_indexed_shl_cPt_nv_V4, Hexagon::STrib_indexed_shl_cPt_V4 },
  { Hexagon::STrib_indexed_shl_cdnNotPt_nv_V4, Hexagon::STrib_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrib_indexed_shl_cdnPt_nv_V4, Hexagon::STrib_indexed_shl_cdnPt_V4 },
  { Hexagon::STrib_indexed_shl_nv_V4, Hexagon::STrib_indexed_shl_V4 },
  { Hexagon::STrib_nv_V4, Hexagon::STrib },
  { Hexagon::STrib_shl_nv_V4, Hexagon::STrib_shl_V4 },
  { Hexagon::STrih_abs_cNotPt_nv_V4, Hexagon::STrih_abs_cNotPt_V4 },
  { Hexagon::STrih_abs_cPt_nv_V4, Hexagon::STrih_abs_cPt_V4 },
  { Hexagon::STrih_abs_cdnNotPt_nv_V4, Hexagon::STrih_abs_cdnNotPt_V4 },
  { Hexagon::STrih_abs_cdnPt_nv_V4, Hexagon::STrih_abs_cdnPt_V4 },
  { Hexagon::STrih_abs_nv_V4, Hexagon::STrih_abs_V4 },
  { Hexagon::STrih_cNotPt_nv_V4, Hexagon::STrih_cNotPt },
  { Hexagon::STrih_cPt_nv_V4, Hexagon::STrih_cPt },
  { Hexagon::STrih_cdnNotPt_nv_V4, Hexagon::STrih_cdnNotPt_V4 },
  { Hexagon::STrih_cdnPt_nv_V4, Hexagon::STrih_cdnPt_V4 },
  { Hexagon::STrih_indexed_cNotPt_nv_V4, Hexagon::STrih_indexed_cNotPt },
  { Hexagon::STrih_indexed_cPt_nv_V4, Hexagon::STrih_indexed_cPt },
  { Hexagon::STrih_indexed_cdnNotPt_nv_V4, Hexagon::STrih_indexed_cdnNotPt_V4 },
  { Hexagon::STrih_indexed_cdnPt_nv_V4, Hexagon::STrih_indexed_cdnPt_V4 },
  { Hexagon::STrih_indexed_nv_V4, Hexagon::STrih_indexed },
  { Hexagon::STrih_indexed_shl_cNotPt_nv_V4, Hexagon::STrih_indexed_shl_cNotPt_V4 },
  { Hexagon::STrih_indexed_shl_cPt_nv_V4, Hexagon::STrih_indexed_shl_cPt_V4 },
  { Hexagon::STrih_indexed_shl_cdnNotPt_nv_V4, Hexagon::STrih_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrih_indexed_shl_cdnPt_nv_V4, Hexagon::STrih_indexed_shl_cdnPt_V4 },
  { Hexagon::STrih_indexed_shl_nv_V4, Hexagon::STrih_indexed_shl_V4 },
  { Hexagon::STrih_nv_V4, Hexagon::STrih },
  { Hexagon::STrih_shl_nv_V4, Hexagon::STrih_shl_V4 },
  { Hexagon::STriw_abs_cNotPt_nv_V4, Hexagon::STriw_abs_cNotPt_V4 },
  { Hexagon::STriw_abs_cPt_nv_V4, Hexagon::STriw_abs_cPt_V4 },
  { Hexagon::STriw_abs_cdnNotPt_nv_V4, Hexagon::STriw_abs_cdnNotPt_V4 },
  { Hexagon::STriw_abs_cdnPt_nv_V4, Hexagon::STriw_abs_cdnPt_V4 },
  { Hexagon::STriw_abs_nv_V4, Hexagon::STriw_abs_V4 },
  { Hexagon::STriw_cNotPt_nv_V4, Hexagon::STriw_cNotPt },
  { Hexagon::STriw_cPt_nv_V4, Hexagon::STriw_cPt },
  { Hexagon::STriw_cdnNotPt_nv_V4, Hexagon::STriw_cdnNotPt_V4 },
  { Hexagon::STriw_cdnPt_nv_V4, Hexagon::STriw_cdnPt_V4 },
  { Hexagon::STriw_indexed_cNotPt_nv_V4, Hexagon::STriw_indexed_cNotPt },
  { Hexagon::STriw_indexed_cPt_nv_V4, Hexagon::STriw_indexed_cPt },
  { Hexagon::STriw_indexed_cdnNotPt_nv_V4, Hexagon::STriw_indexed_cdnNotPt_V4 },
  { Hexagon::STriw_indexed_cdnPt_nv_V4, Hexagon::STriw_indexed_cdnPt_V4 },
  { Hexagon::STriw_indexed_nv_V4, Hexagon::STriw_indexed },
  { Hexagon::STriw_indexed_shl_cNotPt_nv_V4, Hexagon::STriw_indexed_shl_cNotPt_V4 },
  { Hexagon::STriw_indexed_shl_cPt_nv_V4, Hexagon::STriw_indexed_shl_cPt_V4 },
  { Hexagon::STriw_indexed_shl_cdnNotPt_nv_V4, Hexagon::STriw_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STriw_indexed_shl_cdnPt_nv_V4, Hexagon::STriw_indexed_shl_cdnPt_V4 },
  { Hexagon::STriw_indexed_shl_nv_V4, Hexagon::STriw_indexed_shl_V4 },
  { Hexagon::STriw_nv_V4, Hexagon::STriw },
  { Hexagon::STriw_shl_nv_V4, Hexagon::STriw_shl_V4 },
  { Hexagon::STw_GP_cNotPt_nv_V4, Hexagon::STw_GP_cNotPt_V4 },
  { Hexagon::STw_GP_cPt_nv_V4, Hexagon::STw_GP_cPt_V4 },
  { Hexagon::STw_GP_cdnNotPt_nv_V4, Hexagon::STw_GP_cdnNotPt_V4 },
  { Hexagon::STw_GP_cdnPt_nv_V4, Hexagon::STw_GP_cdnPt_V4 },
  { Hexagon::STw_GP_nv_V4, Hexagon::STw_GP_V4 },
}; // End of getNonNVStoreTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 93;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getNonNVStoreTable[mid][0]) {
      break;
    }
    if (Opcode < getNonNVStoreTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getNonNVStoreTable[mid][1];
}

// getPredNewOpcode
int getPredNewOpcode(uint16_t Opcode) {
static const uint16_t getPredNewOpcodeTable[][2] = {
  { Hexagon::ADD_ri_cNotPt, Hexagon::ADD_ri_cdnNotPt },
  { Hexagon::ADD_ri_cPt, Hexagon::ADD_ri_cdnPt },
  { Hexagon::ADD_rr_cNotPt, Hexagon::ADD_rr_cdnNotPt },
  { Hexagon::ADD_rr_cPt, Hexagon::ADD_rr_cdnPt },
  { Hexagon::AND_rr_cNotPt, Hexagon::AND_rr_cdnNotPt },
  { Hexagon::AND_rr_cPt, Hexagon::AND_rr_cdnPt },
  { Hexagon::ASLH_cNotPt_V4, Hexagon::ASLH_cdnNotPt_V4 },
  { Hexagon::ASLH_cPt_V4, Hexagon::ASLH_cdnPt_V4 },
  { Hexagon::ASRH_cNotPt_V4, Hexagon::ASRH_cdnNotPt_V4 },
  { Hexagon::ASRH_cPt_V4, Hexagon::ASRH_cdnPt_V4 },
  { Hexagon::COMBINE_rr_cNotPt, Hexagon::COMBINE_rr_cdnNotPt },
  { Hexagon::COMBINE_rr_cPt, Hexagon::COMBINE_rr_cdnPt },
  { Hexagon::LDb_GP_cNotPt_V4, Hexagon::LDb_GP_cdnNotPt_V4 },
  { Hexagon::LDb_GP_cPt_V4, Hexagon::LDb_GP_cdnPt_V4 },
  { Hexagon::LDd_GP_cNotPt_V4, Hexagon::LDd_GP_cdnNotPt_V4 },
  { Hexagon::LDd_GP_cPt_V4, Hexagon::LDd_GP_cdnPt_V4 },
  { Hexagon::LDh_GP_cNotPt_V4, Hexagon::LDh_GP_cdnNotPt_V4 },
  { Hexagon::LDh_GP_cPt_V4, Hexagon::LDh_GP_cdnPt_V4 },
  { Hexagon::LDrib_abs_cNotPt_V4, Hexagon::LDrib_abs_cdnNotPt_V4 },
  { Hexagon::LDrib_abs_cPt_V4, Hexagon::LDrib_abs_cdnPt_V4 },
  { Hexagon::LDrib_cNotPt, Hexagon::LDrib_cdnNotPt },
  { Hexagon::LDrib_cPt, Hexagon::LDrib_cdnPt },
  { Hexagon::LDrib_indexed_cNotPt, Hexagon::LDrib_indexed_cdnNotPt },
  { Hexagon::LDrib_indexed_cPt, Hexagon::LDrib_indexed_cdnPt },
  { Hexagon::LDrib_indexed_shl_cNotPt_V4, Hexagon::LDrib_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDrib_indexed_shl_cPt_V4, Hexagon::LDrib_indexed_shl_cdnPt_V4 },
  { Hexagon::LDrid_abs_cNotPt_V4, Hexagon::LDrid_abs_cdnNotPt_V4 },
  { Hexagon::LDrid_abs_cPt_V4, Hexagon::LDrid_abs_cdnPt_V4 },
  { Hexagon::LDrid_cNotPt, Hexagon::LDrid_cdnNotPt },
  { Hexagon::LDrid_cPt, Hexagon::LDrid_cdnPt },
  { Hexagon::LDrid_indexed_cNotPt, Hexagon::LDrid_indexed_cdnNotPt },
  { Hexagon::LDrid_indexed_cPt, Hexagon::LDrid_indexed_cdnPt },
  { Hexagon::LDrid_indexed_shl_cNotPt_V4, Hexagon::LDrid_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDrid_indexed_shl_cPt_V4, Hexagon::LDrid_indexed_shl_cdnPt_V4 },
  { Hexagon::LDrih_abs_cNotPt_V4, Hexagon::LDrih_abs_cdnNotPt_V4 },
  { Hexagon::LDrih_abs_cPt_V4, Hexagon::LDrih_abs_cdnPt_V4 },
  { Hexagon::LDrih_cNotPt, Hexagon::LDrih_cdnNotPt },
  { Hexagon::LDrih_cPt, Hexagon::LDrih_cdnPt },
  { Hexagon::LDrih_indexed_cNotPt, Hexagon::LDrih_indexed_cdnNotPt },
  { Hexagon::LDrih_indexed_cPt, Hexagon::LDrih_indexed_cdnPt },
  { Hexagon::LDrih_indexed_shl_cNotPt_V4, Hexagon::LDrih_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDrih_indexed_shl_cPt_V4, Hexagon::LDrih_indexed_shl_cdnPt_V4 },
  { Hexagon::LDriub_abs_cNotPt_V4, Hexagon::LDriub_abs_cdnNotPt_V4 },
  { Hexagon::LDriub_abs_cPt_V4, Hexagon::LDriub_abs_cdnPt_V4 },
  { Hexagon::LDriub_cNotPt, Hexagon::LDriub_cdnNotPt },
  { Hexagon::LDriub_cPt, Hexagon::LDriub_cdnPt },
  { Hexagon::LDriub_indexed_cNotPt, Hexagon::LDriub_indexed_cdnNotPt },
  { Hexagon::LDriub_indexed_cPt, Hexagon::LDriub_indexed_cdnPt },
  { Hexagon::LDriub_indexed_shl_cNotPt_V4, Hexagon::LDriub_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDriub_indexed_shl_cPt_V4, Hexagon::LDriub_indexed_shl_cdnPt_V4 },
  { Hexagon::LDriuh_abs_cNotPt_V4, Hexagon::LDriuh_abs_cdnNotPt_V4 },
  { Hexagon::LDriuh_abs_cPt_V4, Hexagon::LDriuh_abs_cdnPt_V4 },
  { Hexagon::LDriuh_cNotPt, Hexagon::LDriuh_cdnNotPt },
  { Hexagon::LDriuh_cPt, Hexagon::LDriuh_cdnPt },
  { Hexagon::LDriuh_indexed_cNotPt, Hexagon::LDriuh_indexed_cdnNotPt },
  { Hexagon::LDriuh_indexed_cPt, Hexagon::LDriuh_indexed_cdnPt },
  { Hexagon::LDriuh_indexed_shl_cNotPt_V4, Hexagon::LDriuh_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDriuh_indexed_shl_cPt_V4, Hexagon::LDriuh_indexed_shl_cdnPt_V4 },
  { Hexagon::LDriw_abs_cNotPt_V4, Hexagon::LDriw_abs_cdnNotPt_V4 },
  { Hexagon::LDriw_abs_cPt_V4, Hexagon::LDriw_abs_cdnPt_V4 },
  { Hexagon::LDriw_cNotPt, Hexagon::LDriw_cdnNotPt },
  { Hexagon::LDriw_cPt, Hexagon::LDriw_cdnPt },
  { Hexagon::LDriw_indexed_cNotPt, Hexagon::LDriw_indexed_cdnNotPt },
  { Hexagon::LDriw_indexed_cPt, Hexagon::LDriw_indexed_cdnPt },
  { Hexagon::LDriw_indexed_shl_cNotPt_V4, Hexagon::LDriw_indexed_shl_cdnNotPt_V4 },
  { Hexagon::LDriw_indexed_shl_cPt_V4, Hexagon::LDriw_indexed_shl_cdnPt_V4 },
  { Hexagon::LDub_GP_cNotPt_V4, Hexagon::LDub_GP_cdnNotPt_V4 },
  { Hexagon::LDub_GP_cPt_V4, Hexagon::LDub_GP_cdnPt_V4 },
  { Hexagon::LDuh_GP_cNotPt_V4, Hexagon::LDuh_GP_cdnNotPt_V4 },
  { Hexagon::LDuh_GP_cPt_V4, Hexagon::LDuh_GP_cdnPt_V4 },
  { Hexagon::LDw_GP_cNotPt_V4, Hexagon::LDw_GP_cdnNotPt_V4 },
  { Hexagon::LDw_GP_cPt_V4, Hexagon::LDw_GP_cdnPt_V4 },
  { Hexagon::OR_rr_cNotPt, Hexagon::OR_rr_cdnNotPt },
  { Hexagon::OR_rr_cPt, Hexagon::OR_rr_cdnPt },
  { Hexagon::POST_LDrib_cNotPt, Hexagon::POST_LDrib_cdnNotPt_V4 },
  { Hexagon::POST_LDrib_cPt, Hexagon::POST_LDrib_cdnPt_V4 },
  { Hexagon::POST_LDrid_cNotPt, Hexagon::POST_LDrid_cdnNotPt_V4 },
  { Hexagon::POST_LDrid_cPt, Hexagon::POST_LDrid_cdnPt_V4 },
  { Hexagon::POST_LDrih_cNotPt, Hexagon::POST_LDrih_cdnNotPt_V4 },
  { Hexagon::POST_LDrih_cPt, Hexagon::POST_LDrih_cdnPt_V4 },
  { Hexagon::POST_LDriub_cNotPt, Hexagon::POST_LDriub_cdnNotPt_V4 },
  { Hexagon::POST_LDriub_cPt, Hexagon::POST_LDriub_cdnPt_V4 },
  { Hexagon::POST_LDriuh_cNotPt, Hexagon::POST_LDriuh_cdnNotPt_V4 },
  { Hexagon::POST_LDriuh_cPt, Hexagon::POST_LDriuh_cdnPt_V4 },
  { Hexagon::POST_LDriw_cNotPt, Hexagon::POST_LDriw_cdnNotPt_V4 },
  { Hexagon::POST_LDriw_cPt, Hexagon::POST_LDriw_cdnPt_V4 },
  { Hexagon::POST_STbri_cNotPt, Hexagon::POST_STbri_cdnNotPt_V4 },
  { Hexagon::POST_STbri_cNotPt_nv_V4, Hexagon::POST_STbri_cdnNotPt_nv_V4 },
  { Hexagon::POST_STbri_cPt, Hexagon::POST_STbri_cdnPt_V4 },
  { Hexagon::POST_STbri_cPt_nv_V4, Hexagon::POST_STbri_cdnPt_nv_V4 },
  { Hexagon::POST_STdri_cNotPt, Hexagon::POST_STdri_cdnNotPt_V4 },
  { Hexagon::POST_STdri_cPt, Hexagon::POST_STdri_cdnPt_V4 },
  { Hexagon::POST_SThri_cNotPt, Hexagon::POST_SThri_cdnNotPt_V4 },
  { Hexagon::POST_SThri_cNotPt_nv_V4, Hexagon::POST_SThri_cdnNotPt_nv_V4 },
  { Hexagon::POST_SThri_cPt, Hexagon::POST_SThri_cdnPt_V4 },
  { Hexagon::POST_SThri_cPt_nv_V4, Hexagon::POST_SThri_cdnPt_nv_V4 },
  { Hexagon::POST_STwri_cNotPt, Hexagon::POST_STwri_cdnNotPt_V4 },
  { Hexagon::POST_STwri_cNotPt_nv_V4, Hexagon::POST_STwri_cdnNotPt_nv_V4 },
  { Hexagon::POST_STwri_cPt, Hexagon::POST_STwri_cdnPt_V4 },
  { Hexagon::POST_STwri_cPt_nv_V4, Hexagon::POST_STwri_cdnPt_nv_V4 },
  { Hexagon::STb_GP_cNotPt_V4, Hexagon::STb_GP_cdnNotPt_V4 },
  { Hexagon::STb_GP_cNotPt_nv_V4, Hexagon::STb_GP_cdnNotPt_nv_V4 },
  { Hexagon::STb_GP_cPt_V4, Hexagon::STb_GP_cdnPt_V4 },
  { Hexagon::STb_GP_cPt_nv_V4, Hexagon::STb_GP_cdnPt_nv_V4 },
  { Hexagon::STd_GP_cNotPt_V4, Hexagon::STd_GP_cdnNotPt_V4 },
  { Hexagon::STd_GP_cPt_V4, Hexagon::STd_GP_cdnPt_V4 },
  { Hexagon::STh_GP_cNotPt_V4, Hexagon::STh_GP_cdnNotPt_V4 },
  { Hexagon::STh_GP_cNotPt_nv_V4, Hexagon::STh_GP_cdnNotPt_nv_V4 },
  { Hexagon::STh_GP_cPt_V4, Hexagon::STh_GP_cdnPt_V4 },
  { Hexagon::STh_GP_cPt_nv_V4, Hexagon::STh_GP_cdnPt_nv_V4 },
  { Hexagon::STrib_abs_cNotPt_V4, Hexagon::STrib_abs_cdnNotPt_V4 },
  { Hexagon::STrib_abs_cNotPt_nv_V4, Hexagon::STrib_abs_cdnNotPt_nv_V4 },
  { Hexagon::STrib_abs_cPt_V4, Hexagon::STrib_abs_cdnPt_V4 },
  { Hexagon::STrib_abs_cPt_nv_V4, Hexagon::STrib_abs_cdnPt_nv_V4 },
  { Hexagon::STrib_cNotPt, Hexagon::STrib_cdnNotPt_V4 },
  { Hexagon::STrib_cNotPt_nv_V4, Hexagon::STrib_cdnNotPt_nv_V4 },
  { Hexagon::STrib_cPt, Hexagon::STrib_cdnPt_V4 },
  { Hexagon::STrib_cPt_nv_V4, Hexagon::STrib_cdnPt_nv_V4 },
  { Hexagon::STrib_imm_cNotPt_V4, Hexagon::STrib_imm_cdnNotPt_V4 },
  { Hexagon::STrib_imm_cPt_V4, Hexagon::STrib_imm_cdnPt_V4 },
  { Hexagon::STrib_indexed_cNotPt, Hexagon::STrib_indexed_cdnNotPt_V4 },
  { Hexagon::STrib_indexed_cNotPt_nv_V4, Hexagon::STrib_indexed_cdnNotPt_nv_V4 },
  { Hexagon::STrib_indexed_cPt, Hexagon::STrib_indexed_cdnPt_V4 },
  { Hexagon::STrib_indexed_cPt_nv_V4, Hexagon::STrib_indexed_cdnPt_nv_V4 },
  { Hexagon::STrib_indexed_shl_cNotPt_V4, Hexagon::STrib_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrib_indexed_shl_cNotPt_nv_V4, Hexagon::STrib_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STrib_indexed_shl_cPt_V4, Hexagon::STrib_indexed_shl_cdnPt_V4 },
  { Hexagon::STrib_indexed_shl_cPt_nv_V4, Hexagon::STrib_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STrid_abs_cNotPt_V4, Hexagon::STrid_abs_cdnNotPt_V4 },
  { Hexagon::STrid_abs_cPt_V4, Hexagon::STrid_abs_cdnPt_V4 },
  { Hexagon::STrid_cNotPt, Hexagon::STrid_cdnNotPt_V4 },
  { Hexagon::STrid_cPt, Hexagon::STrid_cdnPt_V4 },
  { Hexagon::STrid_indexed_cNotPt, Hexagon::STrid_indexed_cdnNotPt_V4 },
  { Hexagon::STrid_indexed_cPt, Hexagon::STrid_indexed_cdnPt_V4 },
  { Hexagon::STrid_indexed_shl_cNotPt_V4, Hexagon::STrid_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrid_indexed_shl_cPt_V4, Hexagon::STrid_indexed_shl_cdnPt_V4 },
  { Hexagon::STrih_abs_cNotPt_V4, Hexagon::STrih_abs_cdnNotPt_V4 },
  { Hexagon::STrih_abs_cNotPt_nv_V4, Hexagon::STrih_abs_cdnNotPt_nv_V4 },
  { Hexagon::STrih_abs_cPt_V4, Hexagon::STrih_abs_cdnPt_V4 },
  { Hexagon::STrih_abs_cPt_nv_V4, Hexagon::STrih_abs_cdnPt_nv_V4 },
  { Hexagon::STrih_cNotPt, Hexagon::STrih_cdnNotPt_V4 },
  { Hexagon::STrih_cNotPt_nv_V4, Hexagon::STrih_cdnNotPt_nv_V4 },
  { Hexagon::STrih_cPt, Hexagon::STrih_cdnPt_V4 },
  { Hexagon::STrih_cPt_nv_V4, Hexagon::STrih_cdnPt_nv_V4 },
  { Hexagon::STrih_imm_cNotPt_V4, Hexagon::STrih_imm_cdnNotPt_V4 },
  { Hexagon::STrih_imm_cPt_V4, Hexagon::STrih_imm_cdnPt_V4 },
  { Hexagon::STrih_indexed_cNotPt, Hexagon::STrih_indexed_cdnNotPt_V4 },
  { Hexagon::STrih_indexed_cNotPt_nv_V4, Hexagon::STrih_indexed_cdnNotPt_nv_V4 },
  { Hexagon::STrih_indexed_cPt, Hexagon::STrih_indexed_cdnPt_V4 },
  { Hexagon::STrih_indexed_cPt_nv_V4, Hexagon::STrih_indexed_cdnPt_nv_V4 },
  { Hexagon::STrih_indexed_shl_cNotPt_V4, Hexagon::STrih_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STrih_indexed_shl_cNotPt_nv_V4, Hexagon::STrih_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STrih_indexed_shl_cPt_V4, Hexagon::STrih_indexed_shl_cdnPt_V4 },
  { Hexagon::STrih_indexed_shl_cPt_nv_V4, Hexagon::STrih_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STriw_abs_cNotPt_V4, Hexagon::STriw_abs_cdnNotPt_V4 },
  { Hexagon::STriw_abs_cNotPt_nv_V4, Hexagon::STriw_abs_cdnNotPt_nv_V4 },
  { Hexagon::STriw_abs_cPt_V4, Hexagon::STriw_abs_cdnPt_V4 },
  { Hexagon::STriw_abs_cPt_nv_V4, Hexagon::STriw_abs_cdnPt_nv_V4 },
  { Hexagon::STriw_cNotPt, Hexagon::STriw_cdnNotPt_V4 },
  { Hexagon::STriw_cNotPt_nv_V4, Hexagon::STriw_cdnNotPt_nv_V4 },
  { Hexagon::STriw_cPt, Hexagon::STriw_cdnPt_V4 },
  { Hexagon::STriw_cPt_nv_V4, Hexagon::STriw_cdnPt_nv_V4 },
  { Hexagon::STriw_imm_cNotPt_V4, Hexagon::STriw_imm_cdnNotPt_V4 },
  { Hexagon::STriw_imm_cPt_V4, Hexagon::STriw_imm_cdnPt_V4 },
  { Hexagon::STriw_indexed_cNotPt, Hexagon::STriw_indexed_cdnNotPt_V4 },
  { Hexagon::STriw_indexed_cNotPt_nv_V4, Hexagon::STriw_indexed_cdnNotPt_nv_V4 },
  { Hexagon::STriw_indexed_cPt, Hexagon::STriw_indexed_cdnPt_V4 },
  { Hexagon::STriw_indexed_cPt_nv_V4, Hexagon::STriw_indexed_cdnPt_nv_V4 },
  { Hexagon::STriw_indexed_shl_cNotPt_V4, Hexagon::STriw_indexed_shl_cdnNotPt_V4 },
  { Hexagon::STriw_indexed_shl_cNotPt_nv_V4, Hexagon::STriw_indexed_shl_cdnNotPt_nv_V4 },
  { Hexagon::STriw_indexed_shl_cPt_V4, Hexagon::STriw_indexed_shl_cdnPt_V4 },
  { Hexagon::STriw_indexed_shl_cPt_nv_V4, Hexagon::STriw_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STw_GP_cNotPt_V4, Hexagon::STw_GP_cdnNotPt_V4 },
  { Hexagon::STw_GP_cNotPt_nv_V4, Hexagon::STw_GP_cdnNotPt_nv_V4 },
  { Hexagon::STw_GP_cPt_V4, Hexagon::STw_GP_cdnPt_V4 },
  { Hexagon::STw_GP_cPt_nv_V4, Hexagon::STw_GP_cdnPt_nv_V4 },
  { Hexagon::SUB_rr_cNotPt, Hexagon::SUB_rr_cdnNotPt },
  { Hexagon::SUB_rr_cPt, Hexagon::SUB_rr_cdnPt },
  { Hexagon::SXTB_cNotPt_V4, Hexagon::SXTB_cdnNotPt_V4 },
  { Hexagon::SXTB_cPt_V4, Hexagon::SXTB_cdnPt_V4 },
  { Hexagon::SXTH_cNotPt_V4, Hexagon::SXTH_cdnNotPt_V4 },
  { Hexagon::SXTH_cPt_V4, Hexagon::SXTH_cdnPt_V4 },
  { Hexagon::TFR64_cNotPt, Hexagon::TFR64_cdnNotPt },
  { Hexagon::TFR64_cPt, Hexagon::TFR64_cdnPt },
  { Hexagon::TFRI_cNotPt, Hexagon::TFRI_cdnNotPt },
  { Hexagon::TFRI_cPt, Hexagon::TFRI_cdnPt },
  { Hexagon::TFR_cNotPt, Hexagon::TFR_cdnNotPt },
  { Hexagon::TFR_cPt, Hexagon::TFR_cdnPt },
  { Hexagon::XOR_rr_cNotPt, Hexagon::XOR_rr_cdnNotPt },
  { Hexagon::XOR_rr_cPt, Hexagon::XOR_rr_cdnPt },
  { Hexagon::ZXTB_cNotPt_V4, Hexagon::ZXTB_cdnNotPt_V4 },
  { Hexagon::ZXTB_cPt_V4, Hexagon::ZXTB_cdnPt_V4 },
  { Hexagon::ZXTH_cNotPt_V4, Hexagon::ZXTH_cdnNotPt_V4 },
  { Hexagon::ZXTH_cPt_V4, Hexagon::ZXTH_cdnPt_V4 },
}; // End of getPredNewOpcodeTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 194;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getPredNewOpcodeTable[mid][0]) {
      break;
    }
    if (Opcode < getPredNewOpcodeTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getPredNewOpcodeTable[mid][1];
}

// getPredOldOpcode
int getPredOldOpcode(uint16_t Opcode) {
static const uint16_t getPredOldOpcodeTable[][2] = {
  { Hexagon::ADD_ri_cdnNotPt, Hexagon::ADD_ri_cNotPt },
  { Hexagon::ADD_ri_cdnPt, Hexagon::ADD_ri_cPt },
  { Hexagon::ADD_rr_cdnNotPt, Hexagon::ADD_rr_cNotPt },
  { Hexagon::ADD_rr_cdnPt, Hexagon::ADD_rr_cPt },
  { Hexagon::AND_rr_cdnNotPt, Hexagon::AND_rr_cNotPt },
  { Hexagon::AND_rr_cdnPt, Hexagon::AND_rr_cPt },
  { Hexagon::ASLH_cdnNotPt_V4, Hexagon::ASLH_cNotPt_V4 },
  { Hexagon::ASLH_cdnPt_V4, Hexagon::ASLH_cPt_V4 },
  { Hexagon::ASRH_cdnNotPt_V4, Hexagon::ASRH_cNotPt_V4 },
  { Hexagon::ASRH_cdnPt_V4, Hexagon::ASRH_cPt_V4 },
  { Hexagon::COMBINE_rr_cdnNotPt, Hexagon::COMBINE_rr_cNotPt },
  { Hexagon::COMBINE_rr_cdnPt, Hexagon::COMBINE_rr_cPt },
  { Hexagon::JMPR_fnew_ntV3, Hexagon::JMPR_f },
  { Hexagon::JMPR_fnew_tV3, Hexagon::JMPR_f },
  { Hexagon::JMPR_tnew_ntV3, Hexagon::JMPR_t },
  { Hexagon::JMPR_tnew_tV3, Hexagon::JMPR_t },
  { Hexagon::JMP_fnew_nt, Hexagon::JMP_f },
  { Hexagon::JMP_fnew_t, Hexagon::JMP_f },
  { Hexagon::JMP_tnew_nt, Hexagon::JMP_t },
  { Hexagon::JMP_tnew_t, Hexagon::JMP_t },
  { Hexagon::JMPret_fnew_ntV3, Hexagon::JMPret_f },
  { Hexagon::JMPret_fnew_tV3, Hexagon::JMPret_f },
  { Hexagon::JMPret_tnew_ntV3, Hexagon::JMPret_t },
  { Hexagon::JMPret_tnew_tV3, Hexagon::JMPret_t },
  { Hexagon::LDb_GP_cdnNotPt_V4, Hexagon::LDb_GP_cNotPt_V4 },
  { Hexagon::LDb_GP_cdnPt_V4, Hexagon::LDb_GP_cPt_V4 },
  { Hexagon::LDd_GP_cdnNotPt_V4, Hexagon::LDd_GP_cNotPt_V4 },
  { Hexagon::LDd_GP_cdnPt_V4, Hexagon::LDd_GP_cPt_V4 },
  { Hexagon::LDh_GP_cdnNotPt_V4, Hexagon::LDh_GP_cNotPt_V4 },
  { Hexagon::LDh_GP_cdnPt_V4, Hexagon::LDh_GP_cPt_V4 },
  { Hexagon::LDrib_abs_cdnNotPt_V4, Hexagon::LDrib_abs_cNotPt_V4 },
  { Hexagon::LDrib_abs_cdnPt_V4, Hexagon::LDrib_abs_cPt_V4 },
  { Hexagon::LDrib_cdnNotPt, Hexagon::LDrib_cNotPt },
  { Hexagon::LDrib_cdnPt, Hexagon::LDrib_cPt },
  { Hexagon::LDrib_indexed_cdnNotPt, Hexagon::LDrib_indexed_cNotPt },
  { Hexagon::LDrib_indexed_cdnPt, Hexagon::LDrib_indexed_cPt },
  { Hexagon::LDrib_indexed_shl_cdnNotPt_V4, Hexagon::LDrib_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrib_indexed_shl_cdnPt_V4, Hexagon::LDrib_indexed_shl_cPt_V4 },
  { Hexagon::LDrid_abs_cdnNotPt_V4, Hexagon::LDrid_abs_cNotPt_V4 },
  { Hexagon::LDrid_abs_cdnPt_V4, Hexagon::LDrid_abs_cPt_V4 },
  { Hexagon::LDrid_cdnNotPt, Hexagon::LDrid_cNotPt },
  { Hexagon::LDrid_cdnPt, Hexagon::LDrid_cPt },
  { Hexagon::LDrid_indexed_cdnNotPt, Hexagon::LDrid_indexed_cNotPt },
  { Hexagon::LDrid_indexed_cdnPt, Hexagon::LDrid_indexed_cPt },
  { Hexagon::LDrid_indexed_shl_cdnNotPt_V4, Hexagon::LDrid_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrid_indexed_shl_cdnPt_V4, Hexagon::LDrid_indexed_shl_cPt_V4 },
  { Hexagon::LDrih_abs_cdnNotPt_V4, Hexagon::LDrih_abs_cNotPt_V4 },
  { Hexagon::LDrih_abs_cdnPt_V4, Hexagon::LDrih_abs_cPt_V4 },
  { Hexagon::LDrih_cdnNotPt, Hexagon::LDrih_cNotPt },
  { Hexagon::LDrih_cdnPt, Hexagon::LDrih_cPt },
  { Hexagon::LDrih_indexed_cdnNotPt, Hexagon::LDrih_indexed_cNotPt },
  { Hexagon::LDrih_indexed_cdnPt, Hexagon::LDrih_indexed_cPt },
  { Hexagon::LDrih_indexed_shl_cdnNotPt_V4, Hexagon::LDrih_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrih_indexed_shl_cdnPt_V4, Hexagon::LDrih_indexed_shl_cPt_V4 },
  { Hexagon::LDriub_abs_cdnNotPt_V4, Hexagon::LDriub_abs_cNotPt_V4 },
  { Hexagon::LDriub_abs_cdnPt_V4, Hexagon::LDriub_abs_cPt_V4 },
  { Hexagon::LDriub_cdnNotPt, Hexagon::LDriub_cNotPt },
  { Hexagon::LDriub_cdnPt, Hexagon::LDriub_cPt },
  { Hexagon::LDriub_indexed_cdnNotPt, Hexagon::LDriub_indexed_cNotPt },
  { Hexagon::LDriub_indexed_cdnPt, Hexagon::LDriub_indexed_cPt },
  { Hexagon::LDriub_indexed_shl_cdnNotPt_V4, Hexagon::LDriub_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriub_indexed_shl_cdnPt_V4, Hexagon::LDriub_indexed_shl_cPt_V4 },
  { Hexagon::LDriuh_abs_cdnNotPt_V4, Hexagon::LDriuh_abs_cNotPt_V4 },
  { Hexagon::LDriuh_abs_cdnPt_V4, Hexagon::LDriuh_abs_cPt_V4 },
  { Hexagon::LDriuh_cdnNotPt, Hexagon::LDriuh_cNotPt },
  { Hexagon::LDriuh_cdnPt, Hexagon::LDriuh_cPt },
  { Hexagon::LDriuh_indexed_cdnNotPt, Hexagon::LDriuh_indexed_cNotPt },
  { Hexagon::LDriuh_indexed_cdnPt, Hexagon::LDriuh_indexed_cPt },
  { Hexagon::LDriuh_indexed_shl_cdnNotPt_V4, Hexagon::LDriuh_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriuh_indexed_shl_cdnPt_V4, Hexagon::LDriuh_indexed_shl_cPt_V4 },
  { Hexagon::LDriw_abs_cdnNotPt_V4, Hexagon::LDriw_abs_cNotPt_V4 },
  { Hexagon::LDriw_abs_cdnPt_V4, Hexagon::LDriw_abs_cPt_V4 },
  { Hexagon::LDriw_cdnNotPt, Hexagon::LDriw_cNotPt },
  { Hexagon::LDriw_cdnPt, Hexagon::LDriw_cPt },
  { Hexagon::LDriw_indexed_cdnNotPt, Hexagon::LDriw_indexed_cNotPt },
  { Hexagon::LDriw_indexed_cdnPt, Hexagon::LDriw_indexed_cPt },
  { Hexagon::LDriw_indexed_shl_cdnNotPt_V4, Hexagon::LDriw_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriw_indexed_shl_cdnPt_V4, Hexagon::LDriw_indexed_shl_cPt_V4 },
  { Hexagon::LDub_GP_cdnNotPt_V4, Hexagon::LDub_GP_cNotPt_V4 },
  { Hexagon::LDub_GP_cdnPt_V4, Hexagon::LDub_GP_cPt_V4 },
  { Hexagon::LDuh_GP_cdnNotPt_V4, Hexagon::LDuh_GP_cNotPt_V4 },
  { Hexagon::LDuh_GP_cdnPt_V4, Hexagon::LDuh_GP_cPt_V4 },
  { Hexagon::LDw_GP_cdnNotPt_V4, Hexagon::LDw_GP_cNotPt_V4 },
  { Hexagon::LDw_GP_cdnPt_V4, Hexagon::LDw_GP_cPt_V4 },
  { Hexagon::OR_rr_cdnNotPt, Hexagon::OR_rr_cNotPt },
  { Hexagon::OR_rr_cdnPt, Hexagon::OR_rr_cPt },
  { Hexagon::POST_LDrib_cdnNotPt_V4, Hexagon::POST_LDrib_cNotPt },
  { Hexagon::POST_LDrib_cdnPt_V4, Hexagon::POST_LDrib_cPt },
  { Hexagon::POST_LDrid_cdnNotPt_V4, Hexagon::POST_LDrid_cNotPt },
  { Hexagon::POST_LDrid_cdnPt_V4, Hexagon::POST_LDrid_cPt },
  { Hexagon::POST_LDrih_cdnNotPt_V4, Hexagon::POST_LDrih_cNotPt },
  { Hexagon::POST_LDrih_cdnPt_V4, Hexagon::POST_LDrih_cPt },
  { Hexagon::POST_LDriub_cdnNotPt_V4, Hexagon::POST_LDriub_cNotPt },
  { Hexagon::POST_LDriub_cdnPt_V4, Hexagon::POST_LDriub_cPt },
  { Hexagon::POST_LDriuh_cdnNotPt_V4, Hexagon::POST_LDriuh_cNotPt },
  { Hexagon::POST_LDriuh_cdnPt_V4, Hexagon::POST_LDriuh_cPt },
  { Hexagon::POST_LDriw_cdnNotPt_V4, Hexagon::POST_LDriw_cNotPt },
  { Hexagon::POST_LDriw_cdnPt_V4, Hexagon::POST_LDriw_cPt },
  { Hexagon::POST_STbri_cdnNotPt_V4, Hexagon::POST_STbri_cNotPt },
  { Hexagon::POST_STbri_cdnNotPt_nv_V4, Hexagon::POST_STbri_cNotPt_nv_V4 },
  { Hexagon::POST_STbri_cdnPt_V4, Hexagon::POST_STbri_cPt },
  { Hexagon::POST_STbri_cdnPt_nv_V4, Hexagon::POST_STbri_cPt_nv_V4 },
  { Hexagon::POST_STdri_cdnNotPt_V4, Hexagon::POST_STdri_cNotPt },
  { Hexagon::POST_STdri_cdnPt_V4, Hexagon::POST_STdri_cPt },
  { Hexagon::POST_SThri_cdnNotPt_V4, Hexagon::POST_SThri_cNotPt },
  { Hexagon::POST_SThri_cdnNotPt_nv_V4, Hexagon::POST_SThri_cNotPt_nv_V4 },
  { Hexagon::POST_SThri_cdnPt_V4, Hexagon::POST_SThri_cPt },
  { Hexagon::POST_SThri_cdnPt_nv_V4, Hexagon::POST_SThri_cPt_nv_V4 },
  { Hexagon::POST_STwri_cdnNotPt_V4, Hexagon::POST_STwri_cNotPt },
  { Hexagon::POST_STwri_cdnNotPt_nv_V4, Hexagon::POST_STwri_cNotPt_nv_V4 },
  { Hexagon::POST_STwri_cdnPt_V4, Hexagon::POST_STwri_cPt },
  { Hexagon::POST_STwri_cdnPt_nv_V4, Hexagon::POST_STwri_cPt_nv_V4 },
  { Hexagon::STb_GP_cdnNotPt_V4, Hexagon::STb_GP_cNotPt_V4 },
  { Hexagon::STb_GP_cdnNotPt_nv_V4, Hexagon::STb_GP_cNotPt_nv_V4 },
  { Hexagon::STb_GP_cdnPt_V4, Hexagon::STb_GP_cPt_V4 },
  { Hexagon::STb_GP_cdnPt_nv_V4, Hexagon::STb_GP_cPt_nv_V4 },
  { Hexagon::STd_GP_cdnNotPt_V4, Hexagon::STd_GP_cNotPt_V4 },
  { Hexagon::STd_GP_cdnPt_V4, Hexagon::STd_GP_cPt_V4 },
  { Hexagon::STh_GP_cdnNotPt_V4, Hexagon::STh_GP_cNotPt_V4 },
  { Hexagon::STh_GP_cdnNotPt_nv_V4, Hexagon::STh_GP_cNotPt_nv_V4 },
  { Hexagon::STh_GP_cdnPt_V4, Hexagon::STh_GP_cPt_V4 },
  { Hexagon::STh_GP_cdnPt_nv_V4, Hexagon::STh_GP_cPt_nv_V4 },
  { Hexagon::STrib_abs_cdnNotPt_V4, Hexagon::STrib_abs_cNotPt_V4 },
  { Hexagon::STrib_abs_cdnNotPt_nv_V4, Hexagon::STrib_abs_cNotPt_nv_V4 },
  { Hexagon::STrib_abs_cdnPt_V4, Hexagon::STrib_abs_cPt_V4 },
  { Hexagon::STrib_abs_cdnPt_nv_V4, Hexagon::STrib_abs_cPt_nv_V4 },
  { Hexagon::STrib_cdnNotPt_V4, Hexagon::STrib_cNotPt },
  { Hexagon::STrib_cdnNotPt_nv_V4, Hexagon::STrib_cNotPt_nv_V4 },
  { Hexagon::STrib_cdnPt_V4, Hexagon::STrib_cPt },
  { Hexagon::STrib_cdnPt_nv_V4, Hexagon::STrib_cPt_nv_V4 },
  { Hexagon::STrib_imm_cdnNotPt_V4, Hexagon::STrib_imm_cNotPt_V4 },
  { Hexagon::STrib_imm_cdnPt_V4, Hexagon::STrib_imm_cPt_V4 },
  { Hexagon::STrib_indexed_cdnNotPt_V4, Hexagon::STrib_indexed_cNotPt },
  { Hexagon::STrib_indexed_cdnNotPt_nv_V4, Hexagon::STrib_indexed_cNotPt_nv_V4 },
  { Hexagon::STrib_indexed_cdnPt_V4, Hexagon::STrib_indexed_cPt },
  { Hexagon::STrib_indexed_cdnPt_nv_V4, Hexagon::STrib_indexed_cPt_nv_V4 },
  { Hexagon::STrib_indexed_shl_cdnNotPt_V4, Hexagon::STrib_indexed_shl_cNotPt_V4 },
  { Hexagon::STrib_indexed_shl_cdnNotPt_nv_V4, Hexagon::STrib_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STrib_indexed_shl_cdnPt_V4, Hexagon::STrib_indexed_shl_cPt_V4 },
  { Hexagon::STrib_indexed_shl_cdnPt_nv_V4, Hexagon::STrib_indexed_shl_cPt_nv_V4 },
  { Hexagon::STrid_abs_cdnNotPt_V4, Hexagon::STrid_abs_cNotPt_V4 },
  { Hexagon::STrid_abs_cdnPt_V4, Hexagon::STrid_abs_cPt_V4 },
  { Hexagon::STrid_cdnNotPt_V4, Hexagon::STrid_cNotPt },
  { Hexagon::STrid_cdnPt_V4, Hexagon::STrid_cPt },
  { Hexagon::STrid_indexed_cdnNotPt_V4, Hexagon::STrid_indexed_cNotPt },
  { Hexagon::STrid_indexed_cdnPt_V4, Hexagon::STrid_indexed_cPt },
  { Hexagon::STrid_indexed_shl_cdnNotPt_V4, Hexagon::STrid_indexed_shl_cNotPt_V4 },
  { Hexagon::STrid_indexed_shl_cdnPt_V4, Hexagon::STrid_indexed_shl_cPt_V4 },
  { Hexagon::STrih_abs_cdnNotPt_V4, Hexagon::STrih_abs_cNotPt_V4 },
  { Hexagon::STrih_abs_cdnNotPt_nv_V4, Hexagon::STrih_abs_cNotPt_nv_V4 },
  { Hexagon::STrih_abs_cdnPt_V4, Hexagon::STrih_abs_cPt_V4 },
  { Hexagon::STrih_abs_cdnPt_nv_V4, Hexagon::STrih_abs_cPt_nv_V4 },
  { Hexagon::STrih_cdnNotPt_V4, Hexagon::STrih_cNotPt },
  { Hexagon::STrih_cdnNotPt_nv_V4, Hexagon::STrih_cNotPt_nv_V4 },
  { Hexagon::STrih_cdnPt_V4, Hexagon::STrih_cPt },
  { Hexagon::STrih_cdnPt_nv_V4, Hexagon::STrih_cPt_nv_V4 },
  { Hexagon::STrih_imm_cdnNotPt_V4, Hexagon::STrih_imm_cNotPt_V4 },
  { Hexagon::STrih_imm_cdnPt_V4, Hexagon::STrih_imm_cPt_V4 },
  { Hexagon::STrih_indexed_cdnNotPt_V4, Hexagon::STrih_indexed_cNotPt },
  { Hexagon::STrih_indexed_cdnNotPt_nv_V4, Hexagon::STrih_indexed_cNotPt_nv_V4 },
  { Hexagon::STrih_indexed_cdnPt_V4, Hexagon::STrih_indexed_cPt },
  { Hexagon::STrih_indexed_cdnPt_nv_V4, Hexagon::STrih_indexed_cPt_nv_V4 },
  { Hexagon::STrih_indexed_shl_cdnNotPt_V4, Hexagon::STrih_indexed_shl_cNotPt_V4 },
  { Hexagon::STrih_indexed_shl_cdnNotPt_nv_V4, Hexagon::STrih_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STrih_indexed_shl_cdnPt_V4, Hexagon::STrih_indexed_shl_cPt_V4 },
  { Hexagon::STrih_indexed_shl_cdnPt_nv_V4, Hexagon::STrih_indexed_shl_cPt_nv_V4 },
  { Hexagon::STriw_abs_cdnNotPt_V4, Hexagon::STriw_abs_cNotPt_V4 },
  { Hexagon::STriw_abs_cdnNotPt_nv_V4, Hexagon::STriw_abs_cNotPt_nv_V4 },
  { Hexagon::STriw_abs_cdnPt_V4, Hexagon::STriw_abs_cPt_V4 },
  { Hexagon::STriw_abs_cdnPt_nv_V4, Hexagon::STriw_abs_cPt_nv_V4 },
  { Hexagon::STriw_cdnNotPt_V4, Hexagon::STriw_cNotPt },
  { Hexagon::STriw_cdnNotPt_nv_V4, Hexagon::STriw_cNotPt_nv_V4 },
  { Hexagon::STriw_cdnPt_V4, Hexagon::STriw_cPt },
  { Hexagon::STriw_cdnPt_nv_V4, Hexagon::STriw_cPt_nv_V4 },
  { Hexagon::STriw_imm_cdnNotPt_V4, Hexagon::STriw_imm_cNotPt_V4 },
  { Hexagon::STriw_imm_cdnPt_V4, Hexagon::STriw_imm_cPt_V4 },
  { Hexagon::STriw_indexed_cdnNotPt_V4, Hexagon::STriw_indexed_cNotPt },
  { Hexagon::STriw_indexed_cdnNotPt_nv_V4, Hexagon::STriw_indexed_cNotPt_nv_V4 },
  { Hexagon::STriw_indexed_cdnPt_V4, Hexagon::STriw_indexed_cPt },
  { Hexagon::STriw_indexed_cdnPt_nv_V4, Hexagon::STriw_indexed_cPt_nv_V4 },
  { Hexagon::STriw_indexed_shl_cdnNotPt_V4, Hexagon::STriw_indexed_shl_cNotPt_V4 },
  { Hexagon::STriw_indexed_shl_cdnNotPt_nv_V4, Hexagon::STriw_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STriw_indexed_shl_cdnPt_V4, Hexagon::STriw_indexed_shl_cPt_V4 },
  { Hexagon::STriw_indexed_shl_cdnPt_nv_V4, Hexagon::STriw_indexed_shl_cPt_nv_V4 },
  { Hexagon::STw_GP_cdnNotPt_V4, Hexagon::STw_GP_cNotPt_V4 },
  { Hexagon::STw_GP_cdnNotPt_nv_V4, Hexagon::STw_GP_cNotPt_nv_V4 },
  { Hexagon::STw_GP_cdnPt_V4, Hexagon::STw_GP_cPt_V4 },
  { Hexagon::STw_GP_cdnPt_nv_V4, Hexagon::STw_GP_cPt_nv_V4 },
  { Hexagon::SUB_rr_cdnNotPt, Hexagon::SUB_rr_cNotPt },
  { Hexagon::SUB_rr_cdnPt, Hexagon::SUB_rr_cPt },
  { Hexagon::SXTB_cdnNotPt_V4, Hexagon::SXTB_cNotPt_V4 },
  { Hexagon::SXTB_cdnPt_V4, Hexagon::SXTB_cPt_V4 },
  { Hexagon::SXTH_cdnNotPt_V4, Hexagon::SXTH_cNotPt_V4 },
  { Hexagon::SXTH_cdnPt_V4, Hexagon::SXTH_cPt_V4 },
  { Hexagon::TFR64_cdnNotPt, Hexagon::TFR64_cNotPt },
  { Hexagon::TFR64_cdnPt, Hexagon::TFR64_cPt },
  { Hexagon::TFRI_cdnNotPt, Hexagon::TFRI_cNotPt },
  { Hexagon::TFRI_cdnPt, Hexagon::TFRI_cPt },
  { Hexagon::TFR_cdnNotPt, Hexagon::TFR_cNotPt },
  { Hexagon::TFR_cdnPt, Hexagon::TFR_cPt },
  { Hexagon::XOR_rr_cdnNotPt, Hexagon::XOR_rr_cNotPt },
  { Hexagon::XOR_rr_cdnPt, Hexagon::XOR_rr_cPt },
  { Hexagon::ZXTB_cdnNotPt_V4, Hexagon::ZXTB_cNotPt_V4 },
  { Hexagon::ZXTB_cdnPt_V4, Hexagon::ZXTB_cPt_V4 },
  { Hexagon::ZXTH_cdnNotPt_V4, Hexagon::ZXTH_cNotPt_V4 },
  { Hexagon::ZXTH_cdnPt_V4, Hexagon::ZXTH_cPt_V4 },
}; // End of getPredOldOpcodeTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 206;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getPredOldOpcodeTable[mid][0]) {
      break;
    }
    if (Opcode < getPredOldOpcodeTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getPredOldOpcodeTable[mid][1];
}

// getPredOpcode
int getPredOpcode(uint16_t Opcode, enum PredSense inPredSense) {
static const uint16_t getPredOpcodeTable[][3] = {
  { Hexagon::ADD_ri, Hexagon::ADD_ri_cPt, Hexagon::ADD_ri_cNotPt },
  { Hexagon::ADD_rr, Hexagon::ADD_rr_cPt, Hexagon::ADD_rr_cNotPt },
  { Hexagon::AND_rr, Hexagon::AND_rr_cPt, Hexagon::AND_rr_cNotPt },
  { Hexagon::ASLH, Hexagon::ASLH_cPt_V4, Hexagon::ASLH_cNotPt_V4 },
  { Hexagon::ASRH, Hexagon::ASRH_cPt_V4, Hexagon::ASRH_cNotPt_V4 },
  { Hexagon::COMBINE_rr, Hexagon::COMBINE_rr_cPt, Hexagon::COMBINE_rr_cNotPt },
  { Hexagon::JMP, Hexagon::JMP_t, Hexagon::JMP_f },
  { Hexagon::JMPR, Hexagon::JMPR_t, Hexagon::JMPR_f },
  { Hexagon::JMPret, Hexagon::JMPret_t, Hexagon::JMPret_f },
  { Hexagon::LDb_GP_V4, Hexagon::LDb_GP_cPt_V4, Hexagon::LDb_GP_cNotPt_V4 },
  { Hexagon::LDd_GP_V4, Hexagon::LDd_GP_cPt_V4, Hexagon::LDd_GP_cNotPt_V4 },
  { Hexagon::LDh_GP_V4, Hexagon::LDh_GP_cPt_V4, Hexagon::LDh_GP_cNotPt_V4 },
  { Hexagon::LDrib, Hexagon::LDrib_cPt, Hexagon::LDrib_cNotPt },
  { Hexagon::LDrib_abs_V4, Hexagon::LDrib_abs_cPt_V4, Hexagon::LDrib_abs_cNotPt_V4 },
  { Hexagon::LDrib_indexed, Hexagon::LDrib_indexed_cPt, Hexagon::LDrib_indexed_cNotPt },
  { Hexagon::LDrib_indexed_shl_V4, Hexagon::LDrib_indexed_shl_cPt_V4, Hexagon::LDrib_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrid, Hexagon::LDrid_cPt, Hexagon::LDrid_cNotPt },
  { Hexagon::LDrid_abs_V4, Hexagon::LDrid_abs_cPt_V4, Hexagon::LDrid_abs_cNotPt_V4 },
  { Hexagon::LDrid_indexed, Hexagon::LDrid_indexed_cPt, Hexagon::LDrid_indexed_cNotPt },
  { Hexagon::LDrid_indexed_shl_V4, Hexagon::LDrid_indexed_shl_cPt_V4, Hexagon::LDrid_indexed_shl_cNotPt_V4 },
  { Hexagon::LDrih, Hexagon::LDrih_cPt, Hexagon::LDrih_cNotPt },
  { Hexagon::LDrih_abs_V4, Hexagon::LDrih_abs_cPt_V4, Hexagon::LDrih_abs_cNotPt_V4 },
  { Hexagon::LDrih_indexed, Hexagon::LDrih_indexed_cPt, Hexagon::LDrih_indexed_cNotPt },
  { Hexagon::LDrih_indexed_shl_V4, Hexagon::LDrih_indexed_shl_cPt_V4, Hexagon::LDrih_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriub, Hexagon::LDriub_cPt, Hexagon::LDriub_cNotPt },
  { Hexagon::LDriub_abs_V4, Hexagon::LDriub_abs_cPt_V4, Hexagon::LDriub_abs_cNotPt_V4 },
  { Hexagon::LDriub_indexed, Hexagon::LDriub_indexed_cPt, Hexagon::LDriub_indexed_cNotPt },
  { Hexagon::LDriub_indexed_shl_V4, Hexagon::LDriub_indexed_shl_cPt_V4, Hexagon::LDriub_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriuh, Hexagon::LDriuh_cPt, Hexagon::LDriuh_cNotPt },
  { Hexagon::LDriuh_abs_V4, Hexagon::LDriuh_abs_cPt_V4, Hexagon::LDriuh_abs_cNotPt_V4 },
  { Hexagon::LDriuh_indexed, Hexagon::LDriuh_indexed_cPt, Hexagon::LDriuh_indexed_cNotPt },
  { Hexagon::LDriuh_indexed_shl_V4, Hexagon::LDriuh_indexed_shl_cPt_V4, Hexagon::LDriuh_indexed_shl_cNotPt_V4 },
  { Hexagon::LDriw, Hexagon::LDriw_cPt, Hexagon::LDriw_cNotPt },
  { Hexagon::LDriw_abs_V4, Hexagon::LDriw_abs_cPt_V4, Hexagon::LDriw_abs_cNotPt_V4 },
  { Hexagon::LDriw_indexed, Hexagon::LDriw_indexed_cPt, Hexagon::LDriw_indexed_cNotPt },
  { Hexagon::LDriw_indexed_shl_V4, Hexagon::LDriw_indexed_shl_cPt_V4, Hexagon::LDriw_indexed_shl_cNotPt_V4 },
  { Hexagon::LDub_GP_V4, Hexagon::LDub_GP_cPt_V4, Hexagon::LDub_GP_cNotPt_V4 },
  { Hexagon::LDuh_GP_V4, Hexagon::LDuh_GP_cPt_V4, Hexagon::LDuh_GP_cNotPt_V4 },
  { Hexagon::LDw_GP_V4, Hexagon::LDw_GP_cPt_V4, Hexagon::LDw_GP_cNotPt_V4 },
  { Hexagon::OR_rr, Hexagon::OR_rr_cPt, Hexagon::OR_rr_cNotPt },
  { Hexagon::POST_LDrib, Hexagon::POST_LDrib_cPt, Hexagon::POST_LDrib_cNotPt },
  { Hexagon::POST_LDrid, Hexagon::POST_LDrid_cPt, Hexagon::POST_LDrid_cNotPt },
  { Hexagon::POST_LDrih, Hexagon::POST_LDrih_cPt, Hexagon::POST_LDrih_cNotPt },
  { Hexagon::POST_LDriub, Hexagon::POST_LDriub_cPt, Hexagon::POST_LDriub_cNotPt },
  { Hexagon::POST_LDriuh, Hexagon::POST_LDriuh_cPt, Hexagon::POST_LDriuh_cNotPt },
  { Hexagon::POST_LDriw, Hexagon::POST_LDriw_cPt, Hexagon::POST_LDriw_cNotPt },
  { Hexagon::POST_STbri, Hexagon::POST_STbri_cPt, Hexagon::POST_STbri_cNotPt },
  { Hexagon::POST_STbri_nv_V4, Hexagon::POST_STbri_cPt_nv_V4, Hexagon::POST_STbri_cNotPt_nv_V4 },
  { Hexagon::POST_STdri, Hexagon::POST_STdri_cPt, Hexagon::POST_STdri_cNotPt },
  { Hexagon::POST_SThri, Hexagon::POST_SThri_cPt, Hexagon::POST_SThri_cNotPt },
  { Hexagon::POST_SThri_nv_V4, Hexagon::POST_SThri_cPt_nv_V4, Hexagon::POST_SThri_cNotPt_nv_V4 },
  { Hexagon::POST_STwri, Hexagon::POST_STwri_cPt, Hexagon::POST_STwri_cNotPt },
  { Hexagon::POST_STwri_nv_V4, Hexagon::POST_STwri_cPt_nv_V4, Hexagon::POST_STwri_cNotPt_nv_V4 },
  { Hexagon::STb_GP_V4, Hexagon::STb_GP_cPt_V4, Hexagon::STb_GP_cNotPt_V4 },
  { Hexagon::STb_GP_nv_V4, Hexagon::STb_GP_cPt_nv_V4, Hexagon::STb_GP_cNotPt_nv_V4 },
  { Hexagon::STd_GP_V4, Hexagon::STd_GP_cPt_V4, Hexagon::STd_GP_cNotPt_V4 },
  { Hexagon::STh_GP_V4, Hexagon::STh_GP_cPt_V4, Hexagon::STh_GP_cNotPt_V4 },
  { Hexagon::STh_GP_nv_V4, Hexagon::STh_GP_cPt_nv_V4, Hexagon::STh_GP_cNotPt_nv_V4 },
  { Hexagon::STrib, Hexagon::STrib_cPt, Hexagon::STrib_cNotPt },
  { Hexagon::STrib_abs_V4, Hexagon::STrib_abs_cPt_V4, Hexagon::STrib_abs_cNotPt_V4 },
  { Hexagon::STrib_abs_nv_V4, Hexagon::STrib_abs_cPt_nv_V4, Hexagon::STrib_abs_cNotPt_nv_V4 },
  { Hexagon::STrib_imm_V4, Hexagon::STrib_imm_cPt_V4, Hexagon::STrib_imm_cNotPt_V4 },
  { Hexagon::STrib_indexed, Hexagon::STrib_indexed_cPt, Hexagon::STrib_indexed_cNotPt },
  { Hexagon::STrib_indexed_nv_V4, Hexagon::STrib_indexed_cPt_nv_V4, Hexagon::STrib_indexed_cNotPt_nv_V4 },
  { Hexagon::STrib_indexed_shl_V4, Hexagon::STrib_indexed_shl_cPt_V4, Hexagon::STrib_indexed_shl_cNotPt_V4 },
  { Hexagon::STrib_indexed_shl_nv_V4, Hexagon::STrib_indexed_shl_cPt_nv_V4, Hexagon::STrib_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STrib_nv_V4, Hexagon::STrib_cPt_nv_V4, Hexagon::STrib_cNotPt_nv_V4 },
  { Hexagon::STrid, Hexagon::STrid_cPt, Hexagon::STrid_cNotPt },
  { Hexagon::STrid_abs_V4, Hexagon::STrid_abs_cPt_V4, Hexagon::STrid_abs_cNotPt_V4 },
  { Hexagon::STrid_indexed, Hexagon::STrid_indexed_cPt, Hexagon::STrid_indexed_cNotPt },
  { Hexagon::STrid_indexed_shl_V4, Hexagon::STrid_indexed_shl_cPt_V4, Hexagon::STrid_indexed_shl_cNotPt_V4 },
  { Hexagon::STrih, Hexagon::STrih_cPt, Hexagon::STrih_cNotPt },
  { Hexagon::STrih_abs_V4, Hexagon::STrih_abs_cPt_V4, Hexagon::STrih_abs_cNotPt_V4 },
  { Hexagon::STrih_abs_nv_V4, Hexagon::STrih_abs_cPt_nv_V4, Hexagon::STrih_abs_cNotPt_nv_V4 },
  { Hexagon::STrih_imm_V4, Hexagon::STrih_imm_cPt_V4, Hexagon::STrih_imm_cNotPt_V4 },
  { Hexagon::STrih_indexed, Hexagon::STrih_indexed_cPt, Hexagon::STrih_indexed_cNotPt },
  { Hexagon::STrih_indexed_nv_V4, Hexagon::STrih_indexed_cPt_nv_V4, Hexagon::STrih_indexed_cNotPt_nv_V4 },
  { Hexagon::STrih_indexed_shl_V4, Hexagon::STrih_indexed_shl_cPt_V4, Hexagon::STrih_indexed_shl_cNotPt_V4 },
  { Hexagon::STrih_indexed_shl_nv_V4, Hexagon::STrih_indexed_shl_cPt_nv_V4, Hexagon::STrih_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STrih_nv_V4, Hexagon::STrih_cPt_nv_V4, Hexagon::STrih_cNotPt_nv_V4 },
  { Hexagon::STriw, Hexagon::STriw_cPt, Hexagon::STriw_cNotPt },
  { Hexagon::STriw_abs_V4, Hexagon::STriw_abs_cPt_V4, Hexagon::STriw_abs_cNotPt_V4 },
  { Hexagon::STriw_abs_nv_V4, Hexagon::STriw_abs_cPt_nv_V4, Hexagon::STriw_abs_cNotPt_nv_V4 },
  { Hexagon::STriw_imm_V4, Hexagon::STriw_imm_cPt_V4, Hexagon::STriw_imm_cNotPt_V4 },
  { Hexagon::STriw_indexed, Hexagon::STriw_indexed_cPt, Hexagon::STriw_indexed_cNotPt },
  { Hexagon::STriw_indexed_nv_V4, Hexagon::STriw_indexed_cPt_nv_V4, Hexagon::STriw_indexed_cNotPt_nv_V4 },
  { Hexagon::STriw_indexed_shl_V4, Hexagon::STriw_indexed_shl_cPt_V4, Hexagon::STriw_indexed_shl_cNotPt_V4 },
  { Hexagon::STriw_indexed_shl_nv_V4, Hexagon::STriw_indexed_shl_cPt_nv_V4, Hexagon::STriw_indexed_shl_cNotPt_nv_V4 },
  { Hexagon::STriw_nv_V4, Hexagon::STriw_cPt_nv_V4, Hexagon::STriw_cNotPt_nv_V4 },
  { Hexagon::STw_GP_V4, Hexagon::STw_GP_cPt_V4, Hexagon::STw_GP_cNotPt_V4 },
  { Hexagon::STw_GP_nv_V4, Hexagon::STw_GP_cPt_nv_V4, Hexagon::STw_GP_cNotPt_nv_V4 },
  { Hexagon::SUB_rr, Hexagon::SUB_rr_cPt, Hexagon::SUB_rr_cNotPt },
  { Hexagon::SXTB, Hexagon::SXTB_cPt_V4, Hexagon::SXTB_cNotPt_V4 },
  { Hexagon::SXTH, Hexagon::SXTH_cPt_V4, Hexagon::SXTH_cNotPt_V4 },
  { Hexagon::TFR, Hexagon::TFR_cPt, Hexagon::TFR_cNotPt },
  { Hexagon::TFR64, Hexagon::TFR64_cPt, Hexagon::TFR64_cNotPt },
  { Hexagon::TFRI, Hexagon::TFRI_cPt, Hexagon::TFRI_cNotPt },
  { Hexagon::XOR_rr, Hexagon::XOR_rr_cPt, Hexagon::XOR_rr_cNotPt },
  { Hexagon::ZXTB, Hexagon::ZXTB_cPt_V4, Hexagon::ZXTB_cNotPt_V4 },
  { Hexagon::ZXTH, Hexagon::ZXTH_cPt_V4, Hexagon::ZXTH_cNotPt_V4 },
}; // End of getPredOpcodeTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 100;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getPredOpcodeTable[mid][0]) {
      break;
    }
    if (Opcode < getPredOpcodeTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  if (inPredSense == PredSense_true)
    return getPredOpcodeTable[mid][1];
  if (inPredSense == PredSense_false)
    return getPredOpcodeTable[mid][2];
  return -1;}

// getRegForm
int getRegForm(uint16_t Opcode) {
static const uint16_t getRegFormTable[][2] = {
  { Hexagon::ADD_ri, Hexagon::ADD_rr },
  { Hexagon::ADD_ri_cNotPt, Hexagon::ADD_rr_cNotPt },
  { Hexagon::ADD_ri_cPt, Hexagon::ADD_rr_cPt },
  { Hexagon::ADD_ri_cdnNotPt, Hexagon::ADD_rr_cdnNotPt },
  { Hexagon::ADD_ri_cdnPt, Hexagon::ADD_rr_cdnPt },
  { Hexagon::ADDi_MPYrr_V4, Hexagon::ADDr_MPYrr_V4 },
  { Hexagon::ADDr_MPYri_V4, Hexagon::ADDr_MPYrr_V4 },
  { Hexagon::ADDri_acc, Hexagon::ADDrr_acc },
  { Hexagon::AND_ri, Hexagon::AND_rr },
  { Hexagon::CMPEQri, Hexagon::CMPEQrr },
  { Hexagon::CMPGTUri, Hexagon::CMPGTUrr },
  { Hexagon::CMPGTri, Hexagon::CMPGTrr },
  { Hexagon::CMPbGTUri_V4, Hexagon::CMPbGTUrr_V4 },
  { Hexagon::CMPhGTUri_V4, Hexagon::CMPhGTUrr_V4 },
  { Hexagon::MPYI_acc_ri, Hexagon::MPYI_acc_rr },
  { Hexagon::MPYI_ri, Hexagon::MPYI },
  { Hexagon::MUX_ir, Hexagon::MUX_rr },
  { Hexagon::MUX_ri, Hexagon::MUX_rr },
  { Hexagon::OR_ri, Hexagon::OR_rr },
  { Hexagon::ORr_ANDri2_V4, Hexagon::ORr_ANDrr_V4 },
  { Hexagon::ORr_ORri_V4, Hexagon::ORr_ORrr_V4 },
  { Hexagon::STrib_imm_V4, Hexagon::STrib_indexed },
  { Hexagon::STrib_imm_cNotPt_V4, Hexagon::STrib_indexed_cNotPt },
  { Hexagon::STrib_imm_cPt_V4, Hexagon::STrib_indexed_cPt },
  { Hexagon::STrib_imm_cdnNotPt_V4, Hexagon::STrib_indexed_cdnNotPt_V4 },
  { Hexagon::STrib_imm_cdnPt_V4, Hexagon::STrib_indexed_cdnPt_V4 },
  { Hexagon::STrih_imm_V4, Hexagon::STrih_indexed },
  { Hexagon::STrih_imm_cNotPt_V4, Hexagon::STrih_indexed_cNotPt },
  { Hexagon::STrih_imm_cPt_V4, Hexagon::STrih_indexed_cPt },
  { Hexagon::STrih_imm_cdnNotPt_V4, Hexagon::STrih_indexed_cdnNotPt_V4 },
  { Hexagon::STrih_imm_cdnPt_V4, Hexagon::STrih_indexed_cdnPt_V4 },
  { Hexagon::STriw_imm_V4, Hexagon::STriw_indexed },
  { Hexagon::STriw_imm_cNotPt_V4, Hexagon::STriw_indexed_cNotPt },
  { Hexagon::STriw_imm_cPt_V4, Hexagon::STriw_indexed_cPt },
  { Hexagon::STriw_imm_cdnNotPt_V4, Hexagon::STriw_indexed_cdnNotPt_V4 },
  { Hexagon::STriw_imm_cdnPt_V4, Hexagon::STriw_indexed_cdnPt_V4 },
  { Hexagon::SUB_ri, Hexagon::SUB_rr },
  { Hexagon::SUBri_acc, Hexagon::SUBrr_acc },
  { Hexagon::TFRI, Hexagon::TFR },
  { Hexagon::TFRI_cNotPt, Hexagon::TFR_cNotPt },
  { Hexagon::TFRI_cPt, Hexagon::TFR_cPt },
  { Hexagon::TFRI_cdnNotPt, Hexagon::TFR_cdnNotPt },
  { Hexagon::TFRI_cdnPt, Hexagon::TFR_cdnPt },
}; // End of getRegFormTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 43;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getRegFormTable[mid][0]) {
      break;
    }
    if (Opcode < getRegFormTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getRegFormTable[mid][1];
}

// getTruePredOpcode
int getTruePredOpcode(uint16_t Opcode) {
static const uint16_t getTruePredOpcodeTable[][2] = {
  { Hexagon::ADD_ri_cNotPt, Hexagon::ADD_ri_cPt },
  { Hexagon::ADD_ri_cdnNotPt, Hexagon::ADD_ri_cdnPt },
  { Hexagon::ADD_rr_cNotPt, Hexagon::ADD_rr_cPt },
  { Hexagon::ADD_rr_cdnNotPt, Hexagon::ADD_rr_cdnPt },
  { Hexagon::AND_rr_cNotPt, Hexagon::AND_rr_cPt },
  { Hexagon::AND_rr_cdnNotPt, Hexagon::AND_rr_cdnPt },
  { Hexagon::ASLH_cNotPt_V4, Hexagon::ASLH_cPt_V4 },
  { Hexagon::ASLH_cdnNotPt_V4, Hexagon::ASLH_cdnPt_V4 },
  { Hexagon::ASRH_cNotPt_V4, Hexagon::ASRH_cPt_V4 },
  { Hexagon::ASRH_cdnNotPt_V4, Hexagon::ASRH_cdnPt_V4 },
  { Hexagon::CMPEQn1_f_Jumpnv_nt_V4, Hexagon::CMPEQn1_t_Jumpnv_nt_V4 },
  { Hexagon::CMPEQn1_f_Jumpnv_t_V4, Hexagon::CMPEQn1_t_Jumpnv_t_V4 },
  { Hexagon::CMPEQri_f_Jumpnv_nt_V4, Hexagon::CMPEQri_t_Jumpnv_nt_V4 },
  { Hexagon::CMPEQri_f_Jumpnv_t_V4, Hexagon::CMPEQri_t_Jumpnv_t_V4 },
  { Hexagon::CMPEQrr_f_Jumpnv_nt_V4, Hexagon::CMPEQrr_t_Jumpnv_nt_V4 },
  { Hexagon::CMPEQrr_f_Jumpnv_t_V4, Hexagon::CMPEQrr_t_Jumpnv_t_V4 },
  { Hexagon::CMPGTUri_f_Jumpnv_nt_V4, Hexagon::CMPGTUri_t_Jumpnv_nt_V4 },
  { Hexagon::CMPGTUri_f_Jumpnv_t_V4, Hexagon::CMPGTUri_t_Jumpnv_t_V4 },
  { Hexagon::CMPGTUrr_f_Jumpnv_nt_V4, Hexagon::CMPGTUrr_t_Jumpnv_nt_V4 },
  { Hexagon::CMPGTUrr_f_Jumpnv_t_V4, Hexagon::CMPGTUrr_t_Jumpnv_t_V4 },
  { Hexagon::CMPGTn1_f_Jumpnv_nt_V4, Hexagon::CMPGTn1_t_Jumpnv_nt_V4 },
  { Hexagon::CMPGTn1_f_Jumpnv_t_V4, Hexagon::CMPGTn1_t_Jumpnv_t_V4 },
  { Hexagon::CMPGTri_f_Jumpnv_nt_V4, Hexagon::CMPGTri_t_Jumpnv_nt_V4 },
  { Hexagon::CMPGTri_f_Jumpnv_t_V4, Hexagon::CMPGTri_t_Jumpnv_t_V4 },
  { Hexagon::CMPGTrr_f_Jumpnv_nt_V4, Hexagon::CMPGTrr_t_Jumpnv_nt_V4 },
  { Hexagon::CMPGTrr_f_Jumpnv_t_V4, Hexagon::CMPGTrr_t_Jumpnv_t_V4 },
  { Hexagon::CMPLTUrr_f_Jumpnv_nt_V4, Hexagon::CMPLTUrr_t_Jumpnv_nt_V4 },
  { Hexagon::CMPLTUrr_f_Jumpnv_t_V4, Hexagon::CMPLTUrr_t_Jumpnv_t_V4 },
  { Hexagon::CMPLTrr_f_Jumpnv_nt_V4, Hexagon::CMPLTrr_t_Jumpnv_nt_V4 },
  { Hexagon::CMPLTrr_f_Jumpnv_t_V4, Hexagon::CMPLTrr_t_Jumpnv_t_V4 },
  { Hexagon::COMBINE_rr_cNotPt, Hexagon::COMBINE_rr_cPt },
  { Hexagon::COMBINE_rr_cdnNotPt, Hexagon::COMBINE_rr_cdnPt },
  { Hexagon::JMPR_f, Hexagon::JMPR_t },
  { Hexagon::JMPR_fnew_ntV3, Hexagon::JMPR_tnew_ntV3 },
  { Hexagon::JMPR_fnew_tV3, Hexagon::JMPR_tnew_tV3 },
  { Hexagon::JMP_f, Hexagon::JMP_t },
  { Hexagon::JMP_fnew_nt, Hexagon::JMP_tnew_nt },
  { Hexagon::JMP_fnew_t, Hexagon::JMP_tnew_t },
  { Hexagon::JMPret_f, Hexagon::JMPret_t },
  { Hexagon::JMPret_fnew_ntV3, Hexagon::JMPret_tnew_ntV3 },
  { Hexagon::JMPret_fnew_tV3, Hexagon::JMPret_tnew_tV3 },
  { Hexagon::LDb_GP_cNotPt_V4, Hexagon::LDb_GP_cPt_V4 },
  { Hexagon::LDb_GP_cdnNotPt_V4, Hexagon::LDb_GP_cdnPt_V4 },
  { Hexagon::LDd_GP_cNotPt_V4, Hexagon::LDd_GP_cPt_V4 },
  { Hexagon::LDd_GP_cdnNotPt_V4, Hexagon::LDd_GP_cdnPt_V4 },
  { Hexagon::LDh_GP_cNotPt_V4, Hexagon::LDh_GP_cPt_V4 },
  { Hexagon::LDh_GP_cdnNotPt_V4, Hexagon::LDh_GP_cdnPt_V4 },
  { Hexagon::LDrib_abs_cNotPt_V4, Hexagon::LDrib_abs_cPt_V4 },
  { Hexagon::LDrib_abs_cdnNotPt_V4, Hexagon::LDrib_abs_cdnPt_V4 },
  { Hexagon::LDrib_cNotPt, Hexagon::LDrib_cPt },
  { Hexagon::LDrib_cdnNotPt, Hexagon::LDrib_cdnPt },
  { Hexagon::LDrib_indexed_cNotPt, Hexagon::LDrib_indexed_cPt },
  { Hexagon::LDrib_indexed_cdnNotPt, Hexagon::LDrib_indexed_cdnPt },
  { Hexagon::LDrib_indexed_shl_cNotPt_V4, Hexagon::LDrib_indexed_shl_cPt_V4 },
  { Hexagon::LDrib_indexed_shl_cdnNotPt_V4, Hexagon::LDrib_indexed_shl_cdnPt_V4 },
  { Hexagon::LDrid_abs_cNotPt_V4, Hexagon::LDrid_abs_cPt_V4 },
  { Hexagon::LDrid_abs_cdnNotPt_V4, Hexagon::LDrid_abs_cdnPt_V4 },
  { Hexagon::LDrid_cNotPt, Hexagon::LDrid_cPt },
  { Hexagon::LDrid_cdnNotPt, Hexagon::LDrid_cdnPt },
  { Hexagon::LDrid_indexed_cNotPt, Hexagon::LDrid_indexed_cPt },
  { Hexagon::LDrid_indexed_cdnNotPt, Hexagon::LDrid_indexed_cdnPt },
  { Hexagon::LDrid_indexed_shl_cNotPt_V4, Hexagon::LDrid_indexed_shl_cPt_V4 },
  { Hexagon::LDrid_indexed_shl_cdnNotPt_V4, Hexagon::LDrid_indexed_shl_cdnPt_V4 },
  { Hexagon::LDrih_abs_cNotPt_V4, Hexagon::LDrih_abs_cPt_V4 },
  { Hexagon::LDrih_abs_cdnNotPt_V4, Hexagon::LDrih_abs_cdnPt_V4 },
  { Hexagon::LDrih_cNotPt, Hexagon::LDrih_cPt },
  { Hexagon::LDrih_cdnNotPt, Hexagon::LDrih_cdnPt },
  { Hexagon::LDrih_indexed_cNotPt, Hexagon::LDrih_indexed_cPt },
  { Hexagon::LDrih_indexed_cdnNotPt, Hexagon::LDrih_indexed_cdnPt },
  { Hexagon::LDrih_indexed_shl_cNotPt_V4, Hexagon::LDrih_indexed_shl_cPt_V4 },
  { Hexagon::LDrih_indexed_shl_cdnNotPt_V4, Hexagon::LDrih_indexed_shl_cdnPt_V4 },
  { Hexagon::LDriub_abs_cNotPt_V4, Hexagon::LDriub_abs_cPt_V4 },
  { Hexagon::LDriub_abs_cdnNotPt_V4, Hexagon::LDriub_abs_cdnPt_V4 },
  { Hexagon::LDriub_cNotPt, Hexagon::LDriub_cPt },
  { Hexagon::LDriub_cdnNotPt, Hexagon::LDriub_cdnPt },
  { Hexagon::LDriub_indexed_cNotPt, Hexagon::LDriub_indexed_cPt },
  { Hexagon::LDriub_indexed_cdnNotPt, Hexagon::LDriub_indexed_cdnPt },
  { Hexagon::LDriub_indexed_shl_cNotPt_V4, Hexagon::LDriub_indexed_shl_cPt_V4 },
  { Hexagon::LDriub_indexed_shl_cdnNotPt_V4, Hexagon::LDriub_indexed_shl_cdnPt_V4 },
  { Hexagon::LDriuh_abs_cNotPt_V4, Hexagon::LDriuh_abs_cPt_V4 },
  { Hexagon::LDriuh_abs_cdnNotPt_V4, Hexagon::LDriuh_abs_cdnPt_V4 },
  { Hexagon::LDriuh_cNotPt, Hexagon::LDriuh_cPt },
  { Hexagon::LDriuh_cdnNotPt, Hexagon::LDriuh_cdnPt },
  { Hexagon::LDriuh_indexed_cNotPt, Hexagon::LDriuh_indexed_cPt },
  { Hexagon::LDriuh_indexed_cdnNotPt, Hexagon::LDriuh_indexed_cdnPt },
  { Hexagon::LDriuh_indexed_shl_cNotPt_V4, Hexagon::LDriuh_indexed_shl_cPt_V4 },
  { Hexagon::LDriuh_indexed_shl_cdnNotPt_V4, Hexagon::LDriuh_indexed_shl_cdnPt_V4 },
  { Hexagon::LDriw_abs_cNotPt_V4, Hexagon::LDriw_abs_cPt_V4 },
  { Hexagon::LDriw_abs_cdnNotPt_V4, Hexagon::LDriw_abs_cdnPt_V4 },
  { Hexagon::LDriw_cNotPt, Hexagon::LDriw_cPt },
  { Hexagon::LDriw_cdnNotPt, Hexagon::LDriw_cdnPt },
  { Hexagon::LDriw_indexed_cNotPt, Hexagon::LDriw_indexed_cPt },
  { Hexagon::LDriw_indexed_cdnNotPt, Hexagon::LDriw_indexed_cdnPt },
  { Hexagon::LDriw_indexed_shl_cNotPt_V4, Hexagon::LDriw_indexed_shl_cPt_V4 },
  { Hexagon::LDriw_indexed_shl_cdnNotPt_V4, Hexagon::LDriw_indexed_shl_cdnPt_V4 },
  { Hexagon::LDub_GP_cNotPt_V4, Hexagon::LDub_GP_cPt_V4 },
  { Hexagon::LDub_GP_cdnNotPt_V4, Hexagon::LDub_GP_cdnPt_V4 },
  { Hexagon::LDuh_GP_cNotPt_V4, Hexagon::LDuh_GP_cPt_V4 },
  { Hexagon::LDuh_GP_cdnNotPt_V4, Hexagon::LDuh_GP_cdnPt_V4 },
  { Hexagon::LDw_GP_cNotPt_V4, Hexagon::LDw_GP_cPt_V4 },
  { Hexagon::LDw_GP_cdnNotPt_V4, Hexagon::LDw_GP_cdnPt_V4 },
  { Hexagon::OR_rr_cNotPt, Hexagon::OR_rr_cPt },
  { Hexagon::OR_rr_cdnNotPt, Hexagon::OR_rr_cdnPt },
  { Hexagon::POST_LDrib_cNotPt, Hexagon::POST_LDrib_cPt },
  { Hexagon::POST_LDrib_cdnNotPt_V4, Hexagon::POST_LDrib_cdnPt_V4 },
  { Hexagon::POST_LDrid_cNotPt, Hexagon::POST_LDrid_cPt },
  { Hexagon::POST_LDrid_cdnNotPt_V4, Hexagon::POST_LDrid_cdnPt_V4 },
  { Hexagon::POST_LDrih_cNotPt, Hexagon::POST_LDrih_cPt },
  { Hexagon::POST_LDrih_cdnNotPt_V4, Hexagon::POST_LDrih_cdnPt_V4 },
  { Hexagon::POST_LDriub_cNotPt, Hexagon::POST_LDriub_cPt },
  { Hexagon::POST_LDriub_cdnNotPt_V4, Hexagon::POST_LDriub_cdnPt_V4 },
  { Hexagon::POST_LDriuh_cNotPt, Hexagon::POST_LDriuh_cPt },
  { Hexagon::POST_LDriuh_cdnNotPt_V4, Hexagon::POST_LDriuh_cdnPt_V4 },
  { Hexagon::POST_LDriw_cNotPt, Hexagon::POST_LDriw_cPt },
  { Hexagon::POST_LDriw_cdnNotPt_V4, Hexagon::POST_LDriw_cdnPt_V4 },
  { Hexagon::POST_STbri_cNotPt, Hexagon::POST_STbri_cPt },
  { Hexagon::POST_STbri_cNotPt_nv_V4, Hexagon::POST_STbri_cPt_nv_V4 },
  { Hexagon::POST_STbri_cdnNotPt_V4, Hexagon::POST_STbri_cdnPt_V4 },
  { Hexagon::POST_STbri_cdnNotPt_nv_V4, Hexagon::POST_STbri_cdnPt_nv_V4 },
  { Hexagon::POST_STdri_cNotPt, Hexagon::POST_STdri_cPt },
  { Hexagon::POST_STdri_cdnNotPt_V4, Hexagon::POST_STdri_cdnPt_V4 },
  { Hexagon::POST_SThri_cNotPt, Hexagon::POST_SThri_cPt },
  { Hexagon::POST_SThri_cNotPt_nv_V4, Hexagon::POST_SThri_cPt_nv_V4 },
  { Hexagon::POST_SThri_cdnNotPt_V4, Hexagon::POST_SThri_cdnPt_V4 },
  { Hexagon::POST_SThri_cdnNotPt_nv_V4, Hexagon::POST_SThri_cdnPt_nv_V4 },
  { Hexagon::POST_STwri_cNotPt, Hexagon::POST_STwri_cPt },
  { Hexagon::POST_STwri_cNotPt_nv_V4, Hexagon::POST_STwri_cPt_nv_V4 },
  { Hexagon::POST_STwri_cdnNotPt_V4, Hexagon::POST_STwri_cdnPt_V4 },
  { Hexagon::POST_STwri_cdnNotPt_nv_V4, Hexagon::POST_STwri_cdnPt_nv_V4 },
  { Hexagon::STb_GP_cNotPt_V4, Hexagon::STb_GP_cPt_V4 },
  { Hexagon::STb_GP_cNotPt_nv_V4, Hexagon::STb_GP_cPt_nv_V4 },
  { Hexagon::STb_GP_cdnNotPt_V4, Hexagon::STb_GP_cdnPt_V4 },
  { Hexagon::STb_GP_cdnNotPt_nv_V4, Hexagon::STb_GP_cdnPt_nv_V4 },
  { Hexagon::STd_GP_cNotPt_V4, Hexagon::STd_GP_cPt_V4 },
  { Hexagon::STd_GP_cdnNotPt_V4, Hexagon::STd_GP_cdnPt_V4 },
  { Hexagon::STh_GP_cNotPt_V4, Hexagon::STh_GP_cPt_V4 },
  { Hexagon::STh_GP_cNotPt_nv_V4, Hexagon::STh_GP_cPt_nv_V4 },
  { Hexagon::STh_GP_cdnNotPt_V4, Hexagon::STh_GP_cdnPt_V4 },
  { Hexagon::STh_GP_cdnNotPt_nv_V4, Hexagon::STh_GP_cdnPt_nv_V4 },
  { Hexagon::STrib_abs_cNotPt_V4, Hexagon::STrib_abs_cPt_V4 },
  { Hexagon::STrib_abs_cNotPt_nv_V4, Hexagon::STrib_abs_cPt_nv_V4 },
  { Hexagon::STrib_abs_cdnNotPt_V4, Hexagon::STrib_abs_cdnPt_V4 },
  { Hexagon::STrib_abs_cdnNotPt_nv_V4, Hexagon::STrib_abs_cdnPt_nv_V4 },
  { Hexagon::STrib_cNotPt, Hexagon::STrib_cPt },
  { Hexagon::STrib_cNotPt_nv_V4, Hexagon::STrib_cPt_nv_V4 },
  { Hexagon::STrib_cdnNotPt_V4, Hexagon::STrib_cdnPt_V4 },
  { Hexagon::STrib_cdnNotPt_nv_V4, Hexagon::STrib_cdnPt_nv_V4 },
  { Hexagon::STrib_imm_cNotPt_V4, Hexagon::STrib_imm_cPt_V4 },
  { Hexagon::STrib_imm_cdnNotPt_V4, Hexagon::STrib_imm_cdnPt_V4 },
  { Hexagon::STrib_indexed_cNotPt, Hexagon::STrib_indexed_cPt },
  { Hexagon::STrib_indexed_cNotPt_nv_V4, Hexagon::STrib_indexed_cPt_nv_V4 },
  { Hexagon::STrib_indexed_cdnNotPt_V4, Hexagon::STrib_indexed_cdnPt_V4 },
  { Hexagon::STrib_indexed_cdnNotPt_nv_V4, Hexagon::STrib_indexed_cdnPt_nv_V4 },
  { Hexagon::STrib_indexed_shl_cNotPt_V4, Hexagon::STrib_indexed_shl_cPt_V4 },
  { Hexagon::STrib_indexed_shl_cNotPt_nv_V4, Hexagon::STrib_indexed_shl_cPt_nv_V4 },
  { Hexagon::STrib_indexed_shl_cdnNotPt_V4, Hexagon::STrib_indexed_shl_cdnPt_V4 },
  { Hexagon::STrib_indexed_shl_cdnNotPt_nv_V4, Hexagon::STrib_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STrid_abs_cNotPt_V4, Hexagon::STrid_abs_cPt_V4 },
  { Hexagon::STrid_abs_cdnNotPt_V4, Hexagon::STrid_abs_cdnPt_V4 },
  { Hexagon::STrid_cNotPt, Hexagon::STrid_cPt },
  { Hexagon::STrid_cdnNotPt_V4, Hexagon::STrid_cdnPt_V4 },
  { Hexagon::STrid_indexed_cNotPt, Hexagon::STrid_indexed_cPt },
  { Hexagon::STrid_indexed_cdnNotPt_V4, Hexagon::STrid_indexed_cdnPt_V4 },
  { Hexagon::STrid_indexed_shl_cNotPt_V4, Hexagon::STrid_indexed_shl_cPt_V4 },
  { Hexagon::STrid_indexed_shl_cdnNotPt_V4, Hexagon::STrid_indexed_shl_cdnPt_V4 },
  { Hexagon::STrih_abs_cNotPt_V4, Hexagon::STrih_abs_cPt_V4 },
  { Hexagon::STrih_abs_cNotPt_nv_V4, Hexagon::STrih_abs_cPt_nv_V4 },
  { Hexagon::STrih_abs_cdnNotPt_V4, Hexagon::STrih_abs_cdnPt_V4 },
  { Hexagon::STrih_abs_cdnNotPt_nv_V4, Hexagon::STrih_abs_cdnPt_nv_V4 },
  { Hexagon::STrih_cNotPt, Hexagon::STrih_cPt },
  { Hexagon::STrih_cNotPt_nv_V4, Hexagon::STrih_cPt_nv_V4 },
  { Hexagon::STrih_cdnNotPt_V4, Hexagon::STrih_cdnPt_V4 },
  { Hexagon::STrih_cdnNotPt_nv_V4, Hexagon::STrih_cdnPt_nv_V4 },
  { Hexagon::STrih_imm_cNotPt_V4, Hexagon::STrih_imm_cPt_V4 },
  { Hexagon::STrih_imm_cdnNotPt_V4, Hexagon::STrih_imm_cdnPt_V4 },
  { Hexagon::STrih_indexed_cNotPt, Hexagon::STrih_indexed_cPt },
  { Hexagon::STrih_indexed_cNotPt_nv_V4, Hexagon::STrih_indexed_cPt_nv_V4 },
  { Hexagon::STrih_indexed_cdnNotPt_V4, Hexagon::STrih_indexed_cdnPt_V4 },
  { Hexagon::STrih_indexed_cdnNotPt_nv_V4, Hexagon::STrih_indexed_cdnPt_nv_V4 },
  { Hexagon::STrih_indexed_shl_cNotPt_V4, Hexagon::STrih_indexed_shl_cPt_V4 },
  { Hexagon::STrih_indexed_shl_cNotPt_nv_V4, Hexagon::STrih_indexed_shl_cPt_nv_V4 },
  { Hexagon::STrih_indexed_shl_cdnNotPt_V4, Hexagon::STrih_indexed_shl_cdnPt_V4 },
  { Hexagon::STrih_indexed_shl_cdnNotPt_nv_V4, Hexagon::STrih_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STriw_abs_cNotPt_V4, Hexagon::STriw_abs_cPt_V4 },
  { Hexagon::STriw_abs_cNotPt_nv_V4, Hexagon::STriw_abs_cPt_nv_V4 },
  { Hexagon::STriw_abs_cdnNotPt_V4, Hexagon::STriw_abs_cdnPt_V4 },
  { Hexagon::STriw_abs_cdnNotPt_nv_V4, Hexagon::STriw_abs_cdnPt_nv_V4 },
  { Hexagon::STriw_cNotPt, Hexagon::STriw_cPt },
  { Hexagon::STriw_cNotPt_nv_V4, Hexagon::STriw_cPt_nv_V4 },
  { Hexagon::STriw_cdnNotPt_V4, Hexagon::STriw_cdnPt_V4 },
  { Hexagon::STriw_cdnNotPt_nv_V4, Hexagon::STriw_cdnPt_nv_V4 },
  { Hexagon::STriw_imm_cNotPt_V4, Hexagon::STriw_imm_cPt_V4 },
  { Hexagon::STriw_imm_cdnNotPt_V4, Hexagon::STriw_imm_cdnPt_V4 },
  { Hexagon::STriw_indexed_cNotPt, Hexagon::STriw_indexed_cPt },
  { Hexagon::STriw_indexed_cNotPt_nv_V4, Hexagon::STriw_indexed_cPt_nv_V4 },
  { Hexagon::STriw_indexed_cdnNotPt_V4, Hexagon::STriw_indexed_cdnPt_V4 },
  { Hexagon::STriw_indexed_cdnNotPt_nv_V4, Hexagon::STriw_indexed_cdnPt_nv_V4 },
  { Hexagon::STriw_indexed_shl_cNotPt_V4, Hexagon::STriw_indexed_shl_cPt_V4 },
  { Hexagon::STriw_indexed_shl_cNotPt_nv_V4, Hexagon::STriw_indexed_shl_cPt_nv_V4 },
  { Hexagon::STriw_indexed_shl_cdnNotPt_V4, Hexagon::STriw_indexed_shl_cdnPt_V4 },
  { Hexagon::STriw_indexed_shl_cdnNotPt_nv_V4, Hexagon::STriw_indexed_shl_cdnPt_nv_V4 },
  { Hexagon::STw_GP_cNotPt_V4, Hexagon::STw_GP_cPt_V4 },
  { Hexagon::STw_GP_cNotPt_nv_V4, Hexagon::STw_GP_cPt_nv_V4 },
  { Hexagon::STw_GP_cdnNotPt_V4, Hexagon::STw_GP_cdnPt_V4 },
  { Hexagon::STw_GP_cdnNotPt_nv_V4, Hexagon::STw_GP_cdnPt_nv_V4 },
  { Hexagon::SUB_rr_cNotPt, Hexagon::SUB_rr_cPt },
  { Hexagon::SUB_rr_cdnNotPt, Hexagon::SUB_rr_cdnPt },
  { Hexagon::SXTB_cNotPt_V4, Hexagon::SXTB_cPt_V4 },
  { Hexagon::SXTB_cdnNotPt_V4, Hexagon::SXTB_cdnPt_V4 },
  { Hexagon::SXTH_cNotPt_V4, Hexagon::SXTH_cPt_V4 },
  { Hexagon::SXTH_cdnNotPt_V4, Hexagon::SXTH_cdnPt_V4 },
  { Hexagon::TFR64_cNotPt, Hexagon::TFR64_cPt },
  { Hexagon::TFR64_cdnNotPt, Hexagon::TFR64_cdnPt },
  { Hexagon::TFRI_cNotPt, Hexagon::TFRI_cPt },
  { Hexagon::TFRI_cdnNotPt, Hexagon::TFRI_cdnPt },
  { Hexagon::TFR_cNotPt, Hexagon::TFR_cPt },
  { Hexagon::TFR_cdnNotPt, Hexagon::TFR_cdnPt },
  { Hexagon::TSTBIT0_f_Jumpnv_nt_V4, Hexagon::TSTBIT0_t_Jumpnv_nt_V4 },
  { Hexagon::TSTBIT0_f_Jumpnv_t_V4, Hexagon::TSTBIT0_t_Jumpnv_t_V4 },
  { Hexagon::XOR_rr_cNotPt, Hexagon::XOR_rr_cPt },
  { Hexagon::XOR_rr_cdnNotPt, Hexagon::XOR_rr_cdnPt },
  { Hexagon::ZXTB_cNotPt_V4, Hexagon::ZXTB_cPt_V4 },
  { Hexagon::ZXTB_cdnNotPt_V4, Hexagon::ZXTB_cdnPt_V4 },
  { Hexagon::ZXTH_cNotPt_V4, Hexagon::ZXTH_cPt_V4 },
  { Hexagon::ZXTH_cdnNotPt_V4, Hexagon::ZXTH_cdnPt_V4 },
}; // End of getTruePredOpcodeTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 225;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getTruePredOpcodeTable[mid][0]) {
      break;
    }
    if (Opcode < getTruePredOpcodeTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getTruePredOpcodeTable[mid][1];
}

} // End Hexagon namespace
} // End llvm namespace
#endif // GET_INSTRMAP_INFO


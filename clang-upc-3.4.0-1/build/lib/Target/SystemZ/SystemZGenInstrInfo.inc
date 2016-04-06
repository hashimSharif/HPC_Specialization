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

namespace SystemZ {
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
    A	= 19,
    ADB	= 20,
    ADBR	= 21,
    ADJCALLSTACKDOWN	= 22,
    ADJCALLSTACKUP	= 23,
    ADJDYNALLOC	= 24,
    AEB	= 25,
    AEBR	= 26,
    AEXT128_64	= 27,
    AFI	= 28,
    AFIMux	= 29,
    AG	= 30,
    AGF	= 31,
    AGFI	= 32,
    AGFR	= 33,
    AGHI	= 34,
    AGHIK	= 35,
    AGR	= 36,
    AGRK	= 37,
    AGSI	= 38,
    AH	= 39,
    AHI	= 40,
    AHIK	= 41,
    AHIMux	= 42,
    AHIMuxK	= 43,
    AHY	= 44,
    AIH	= 45,
    AL	= 46,
    ALC	= 47,
    ALCG	= 48,
    ALCGR	= 49,
    ALCR	= 50,
    ALFI	= 51,
    ALG	= 52,
    ALGF	= 53,
    ALGFI	= 54,
    ALGFR	= 55,
    ALGHSIK	= 56,
    ALGR	= 57,
    ALGRK	= 58,
    ALHSIK	= 59,
    ALR	= 60,
    ALRK	= 61,
    ALY	= 62,
    AR	= 63,
    ARK	= 64,
    ASI	= 65,
    ATOMIC_CMP_SWAPW	= 66,
    ATOMIC_LOADW_AFI	= 67,
    ATOMIC_LOADW_AR	= 68,
    ATOMIC_LOADW_MAX	= 69,
    ATOMIC_LOADW_MIN	= 70,
    ATOMIC_LOADW_NILH	= 71,
    ATOMIC_LOADW_NILHi	= 72,
    ATOMIC_LOADW_NR	= 73,
    ATOMIC_LOADW_NRi	= 74,
    ATOMIC_LOADW_OILH	= 75,
    ATOMIC_LOADW_OR	= 76,
    ATOMIC_LOADW_SR	= 77,
    ATOMIC_LOADW_UMAX	= 78,
    ATOMIC_LOADW_UMIN	= 79,
    ATOMIC_LOADW_XILF	= 80,
    ATOMIC_LOADW_XR	= 81,
    ATOMIC_LOAD_AFI	= 82,
    ATOMIC_LOAD_AGFI	= 83,
    ATOMIC_LOAD_AGHI	= 84,
    ATOMIC_LOAD_AGR	= 85,
    ATOMIC_LOAD_AHI	= 86,
    ATOMIC_LOAD_AR	= 87,
    ATOMIC_LOAD_MAX_32	= 88,
    ATOMIC_LOAD_MAX_64	= 89,
    ATOMIC_LOAD_MIN_32	= 90,
    ATOMIC_LOAD_MIN_64	= 91,
    ATOMIC_LOAD_NGR	= 92,
    ATOMIC_LOAD_NGRi	= 93,
    ATOMIC_LOAD_NIHF64	= 94,
    ATOMIC_LOAD_NIHF64i	= 95,
    ATOMIC_LOAD_NIHH64	= 96,
    ATOMIC_LOAD_NIHH64i	= 97,
    ATOMIC_LOAD_NIHL64	= 98,
    ATOMIC_LOAD_NIHL64i	= 99,
    ATOMIC_LOAD_NILF	= 100,
    ATOMIC_LOAD_NILF64	= 101,
    ATOMIC_LOAD_NILF64i	= 102,
    ATOMIC_LOAD_NILFi	= 103,
    ATOMIC_LOAD_NILH	= 104,
    ATOMIC_LOAD_NILH64	= 105,
    ATOMIC_LOAD_NILH64i	= 106,
    ATOMIC_LOAD_NILHi	= 107,
    ATOMIC_LOAD_NILL	= 108,
    ATOMIC_LOAD_NILL64	= 109,
    ATOMIC_LOAD_NILL64i	= 110,
    ATOMIC_LOAD_NILLi	= 111,
    ATOMIC_LOAD_NR	= 112,
    ATOMIC_LOAD_NRi	= 113,
    ATOMIC_LOAD_OGR	= 114,
    ATOMIC_LOAD_OIHF64	= 115,
    ATOMIC_LOAD_OIHH64	= 116,
    ATOMIC_LOAD_OIHL64	= 117,
    ATOMIC_LOAD_OILF	= 118,
    ATOMIC_LOAD_OILF64	= 119,
    ATOMIC_LOAD_OILH	= 120,
    ATOMIC_LOAD_OILH64	= 121,
    ATOMIC_LOAD_OILL	= 122,
    ATOMIC_LOAD_OILL64	= 123,
    ATOMIC_LOAD_OR	= 124,
    ATOMIC_LOAD_SGR	= 125,
    ATOMIC_LOAD_SR	= 126,
    ATOMIC_LOAD_UMAX_32	= 127,
    ATOMIC_LOAD_UMAX_64	= 128,
    ATOMIC_LOAD_UMIN_32	= 129,
    ATOMIC_LOAD_UMIN_64	= 130,
    ATOMIC_LOAD_XGR	= 131,
    ATOMIC_LOAD_XIHF64	= 132,
    ATOMIC_LOAD_XILF	= 133,
    ATOMIC_LOAD_XILF64	= 134,
    ATOMIC_LOAD_XR	= 135,
    ATOMIC_SWAPW	= 136,
    ATOMIC_SWAP_32	= 137,
    ATOMIC_SWAP_64	= 138,
    AXBR	= 139,
    AY	= 140,
    AsmBCR	= 141,
    AsmBRC	= 142,
    AsmBRCL	= 143,
    AsmCGIJ	= 144,
    AsmCGRJ	= 145,
    AsmCIJ	= 146,
    AsmCLGIJ	= 147,
    AsmCLGRJ	= 148,
    AsmCLIJ	= 149,
    AsmCLRJ	= 150,
    AsmCRJ	= 151,
    AsmEBR	= 152,
    AsmEJ	= 153,
    AsmEJG	= 154,
    AsmELOC	= 155,
    AsmELOCG	= 156,
    AsmELOCGR	= 157,
    AsmELOCR	= 158,
    AsmESTOC	= 159,
    AsmESTOCG	= 160,
    AsmHBR	= 161,
    AsmHEBR	= 162,
    AsmHEJ	= 163,
    AsmHEJG	= 164,
    AsmHELOC	= 165,
    AsmHELOCG	= 166,
    AsmHELOCGR	= 167,
    AsmHELOCR	= 168,
    AsmHESTOC	= 169,
    AsmHESTOCG	= 170,
    AsmHJ	= 171,
    AsmHJG	= 172,
    AsmHLOC	= 173,
    AsmHLOCG	= 174,
    AsmHLOCGR	= 175,
    AsmHLOCR	= 176,
    AsmHSTOC	= 177,
    AsmHSTOCG	= 178,
    AsmJEAltCGI	= 179,
    AsmJEAltCGR	= 180,
    AsmJEAltCI	= 181,
    AsmJEAltCLGI	= 182,
    AsmJEAltCLGR	= 183,
    AsmJEAltCLI	= 184,
    AsmJEAltCLR	= 185,
    AsmJEAltCR	= 186,
    AsmJECGI	= 187,
    AsmJECGR	= 188,
    AsmJECI	= 189,
    AsmJECLGI	= 190,
    AsmJECLGR	= 191,
    AsmJECLI	= 192,
    AsmJECLR	= 193,
    AsmJECR	= 194,
    AsmJHAltCGI	= 195,
    AsmJHAltCGR	= 196,
    AsmJHAltCI	= 197,
    AsmJHAltCLGI	= 198,
    AsmJHAltCLGR	= 199,
    AsmJHAltCLI	= 200,
    AsmJHAltCLR	= 201,
    AsmJHAltCR	= 202,
    AsmJHCGI	= 203,
    AsmJHCGR	= 204,
    AsmJHCI	= 205,
    AsmJHCLGI	= 206,
    AsmJHCLGR	= 207,
    AsmJHCLI	= 208,
    AsmJHCLR	= 209,
    AsmJHCR	= 210,
    AsmJHEAltCGI	= 211,
    AsmJHEAltCGR	= 212,
    AsmJHEAltCI	= 213,
    AsmJHEAltCLGI	= 214,
    AsmJHEAltCLGR	= 215,
    AsmJHEAltCLI	= 216,
    AsmJHEAltCLR	= 217,
    AsmJHEAltCR	= 218,
    AsmJHECGI	= 219,
    AsmJHECGR	= 220,
    AsmJHECI	= 221,
    AsmJHECLGI	= 222,
    AsmJHECLGR	= 223,
    AsmJHECLI	= 224,
    AsmJHECLR	= 225,
    AsmJHECR	= 226,
    AsmJLAltCGI	= 227,
    AsmJLAltCGR	= 228,
    AsmJLAltCI	= 229,
    AsmJLAltCLGI	= 230,
    AsmJLAltCLGR	= 231,
    AsmJLAltCLI	= 232,
    AsmJLAltCLR	= 233,
    AsmJLAltCR	= 234,
    AsmJLCGI	= 235,
    AsmJLCGR	= 236,
    AsmJLCI	= 237,
    AsmJLCLGI	= 238,
    AsmJLCLGR	= 239,
    AsmJLCLI	= 240,
    AsmJLCLR	= 241,
    AsmJLCR	= 242,
    AsmJLEAltCGI	= 243,
    AsmJLEAltCGR	= 244,
    AsmJLEAltCI	= 245,
    AsmJLEAltCLGI	= 246,
    AsmJLEAltCLGR	= 247,
    AsmJLEAltCLI	= 248,
    AsmJLEAltCLR	= 249,
    AsmJLEAltCR	= 250,
    AsmJLECGI	= 251,
    AsmJLECGR	= 252,
    AsmJLECI	= 253,
    AsmJLECLGI	= 254,
    AsmJLECLGR	= 255,
    AsmJLECLI	= 256,
    AsmJLECLR	= 257,
    AsmJLECR	= 258,
    AsmJLHAltCGI	= 259,
    AsmJLHAltCGR	= 260,
    AsmJLHAltCI	= 261,
    AsmJLHAltCLGI	= 262,
    AsmJLHAltCLGR	= 263,
    AsmJLHAltCLI	= 264,
    AsmJLHAltCLR	= 265,
    AsmJLHAltCR	= 266,
    AsmJLHCGI	= 267,
    AsmJLHCGR	= 268,
    AsmJLHCI	= 269,
    AsmJLHCLGI	= 270,
    AsmJLHCLGR	= 271,
    AsmJLHCLI	= 272,
    AsmJLHCLR	= 273,
    AsmJLHCR	= 274,
    AsmLBR	= 275,
    AsmLEBR	= 276,
    AsmLEJ	= 277,
    AsmLEJG	= 278,
    AsmLELOC	= 279,
    AsmLELOCG	= 280,
    AsmLELOCGR	= 281,
    AsmLELOCR	= 282,
    AsmLESTOC	= 283,
    AsmLESTOCG	= 284,
    AsmLHBR	= 285,
    AsmLHJ	= 286,
    AsmLHJG	= 287,
    AsmLHLOC	= 288,
    AsmLHLOCG	= 289,
    AsmLHLOCGR	= 290,
    AsmLHLOCR	= 291,
    AsmLHSTOC	= 292,
    AsmLHSTOCG	= 293,
    AsmLJ	= 294,
    AsmLJG	= 295,
    AsmLLOC	= 296,
    AsmLLOCG	= 297,
    AsmLLOCGR	= 298,
    AsmLLOCR	= 299,
    AsmLOC	= 300,
    AsmLOCG	= 301,
    AsmLOCGR	= 302,
    AsmLOCR	= 303,
    AsmLSTOC	= 304,
    AsmLSTOCG	= 305,
    AsmNEBR	= 306,
    AsmNEJ	= 307,
    AsmNEJG	= 308,
    AsmNELOC	= 309,
    AsmNELOCG	= 310,
    AsmNELOCGR	= 311,
    AsmNELOCR	= 312,
    AsmNESTOC	= 313,
    AsmNESTOCG	= 314,
    AsmNHBR	= 315,
    AsmNHEBR	= 316,
    AsmNHEJ	= 317,
    AsmNHEJG	= 318,
    AsmNHELOC	= 319,
    AsmNHELOCG	= 320,
    AsmNHELOCGR	= 321,
    AsmNHELOCR	= 322,
    AsmNHESTOC	= 323,
    AsmNHESTOCG	= 324,
    AsmNHJ	= 325,
    AsmNHJG	= 326,
    AsmNHLOC	= 327,
    AsmNHLOCG	= 328,
    AsmNHLOCGR	= 329,
    AsmNHLOCR	= 330,
    AsmNHSTOC	= 331,
    AsmNHSTOCG	= 332,
    AsmNLBR	= 333,
    AsmNLEBR	= 334,
    AsmNLEJ	= 335,
    AsmNLEJG	= 336,
    AsmNLELOC	= 337,
    AsmNLELOCG	= 338,
    AsmNLELOCGR	= 339,
    AsmNLELOCR	= 340,
    AsmNLESTOC	= 341,
    AsmNLESTOCG	= 342,
    AsmNLHBR	= 343,
    AsmNLHJ	= 344,
    AsmNLHJG	= 345,
    AsmNLHLOC	= 346,
    AsmNLHLOCG	= 347,
    AsmNLHLOCGR	= 348,
    AsmNLHLOCR	= 349,
    AsmNLHSTOC	= 350,
    AsmNLHSTOCG	= 351,
    AsmNLJ	= 352,
    AsmNLJG	= 353,
    AsmNLLOC	= 354,
    AsmNLLOCG	= 355,
    AsmNLLOCGR	= 356,
    AsmNLLOCR	= 357,
    AsmNLSTOC	= 358,
    AsmNLSTOCG	= 359,
    AsmNOBR	= 360,
    AsmNOJ	= 361,
    AsmNOJG	= 362,
    AsmNOLOC	= 363,
    AsmNOLOCG	= 364,
    AsmNOLOCGR	= 365,
    AsmNOLOCR	= 366,
    AsmNOSTOC	= 367,
    AsmNOSTOCG	= 368,
    AsmOBR	= 369,
    AsmOJ	= 370,
    AsmOJG	= 371,
    AsmOLOC	= 372,
    AsmOLOCG	= 373,
    AsmOLOCGR	= 374,
    AsmOLOCR	= 375,
    AsmOSTOC	= 376,
    AsmOSTOCG	= 377,
    AsmSTOC	= 378,
    AsmSTOCG	= 379,
    BASR	= 380,
    BR	= 381,
    BRAS	= 382,
    BRASL	= 383,
    BRC	= 384,
    BRCL	= 385,
    BRCT	= 386,
    BRCTG	= 387,
    C	= 388,
    CDB	= 389,
    CDBR	= 390,
    CDFBR	= 391,
    CDGBR	= 392,
    CEB	= 393,
    CEBR	= 394,
    CEFBR	= 395,
    CEGBR	= 396,
    CFDBR	= 397,
    CFEBR	= 398,
    CFI	= 399,
    CFIMux	= 400,
    CFXBR	= 401,
    CG	= 402,
    CGDBR	= 403,
    CGEBR	= 404,
    CGF	= 405,
    CGFI	= 406,
    CGFR	= 407,
    CGFRL	= 408,
    CGH	= 409,
    CGHI	= 410,
    CGHRL	= 411,
    CGHSI	= 412,
    CGIJ	= 413,
    CGR	= 414,
    CGRJ	= 415,
    CGRL	= 416,
    CGXBR	= 417,
    CH	= 418,
    CHF	= 419,
    CHHSI	= 420,
    CHI	= 421,
    CHRL	= 422,
    CHSI	= 423,
    CHY	= 424,
    CIH	= 425,
    CIJ	= 426,
    CL	= 427,
    CLC	= 428,
    CLCLoop	= 429,
    CLCSequence	= 430,
    CLFHSI	= 431,
    CLFI	= 432,
    CLFIMux	= 433,
    CLG	= 434,
    CLGF	= 435,
    CLGFI	= 436,
    CLGFR	= 437,
    CLGFRL	= 438,
    CLGHRL	= 439,
    CLGHSI	= 440,
    CLGIJ	= 441,
    CLGR	= 442,
    CLGRJ	= 443,
    CLGRL	= 444,
    CLHF	= 445,
    CLHHSI	= 446,
    CLHRL	= 447,
    CLI	= 448,
    CLIH	= 449,
    CLIJ	= 450,
    CLIY	= 451,
    CLMux	= 452,
    CLR	= 453,
    CLRJ	= 454,
    CLRL	= 455,
    CLST	= 456,
    CLSTLoop	= 457,
    CLY	= 458,
    CMux	= 459,
    CPSDRdd	= 460,
    CPSDRds	= 461,
    CPSDRsd	= 462,
    CPSDRss	= 463,
    CR	= 464,
    CRJ	= 465,
    CRL	= 466,
    CS	= 467,
    CSG	= 468,
    CSY	= 469,
    CXBR	= 470,
    CXFBR	= 471,
    CXGBR	= 472,
    CY	= 473,
    CallBASR	= 474,
    CallBR	= 475,
    CallBRASL	= 476,
    CallJG	= 477,
    CondStore16	= 478,
    CondStore16Inv	= 479,
    CondStore16Mux	= 480,
    CondStore16MuxInv	= 481,
    CondStore32	= 482,
    CondStore32Inv	= 483,
    CondStore64	= 484,
    CondStore64Inv	= 485,
    CondStore8	= 486,
    CondStore8Inv	= 487,
    CondStore8Mux	= 488,
    CondStore8MuxInv	= 489,
    CondStoreF32	= 490,
    CondStoreF32Inv	= 491,
    CondStoreF64	= 492,
    CondStoreF64Inv	= 493,
    DDB	= 494,
    DDBR	= 495,
    DEB	= 496,
    DEBR	= 497,
    DL	= 498,
    DLG	= 499,
    DLGR	= 500,
    DLR	= 501,
    DSG	= 502,
    DSGF	= 503,
    DSGFR	= 504,
    DSGR	= 505,
    DXBR	= 506,
    EAR	= 507,
    FIDBR	= 508,
    FIDBRA	= 509,
    FIEBR	= 510,
    FIEBRA	= 511,
    FIXBR	= 512,
    FIXBRA	= 513,
    FLOGR	= 514,
    IC	= 515,
    IC32	= 516,
    IC32Y	= 517,
    ICY	= 518,
    IIFMux	= 519,
    IIHF	= 520,
    IIHF64	= 521,
    IIHH	= 522,
    IIHH64	= 523,
    IIHL	= 524,
    IIHL64	= 525,
    IIHMux	= 526,
    IILF	= 527,
    IILF64	= 528,
    IILH	= 529,
    IILH64	= 530,
    IILL	= 531,
    IILL64	= 532,
    IILMux	= 533,
    IPM	= 534,
    J	= 535,
    JG	= 536,
    L	= 537,
    L128	= 538,
    LA	= 539,
    LARL	= 540,
    LAY	= 541,
    LB	= 542,
    LBH	= 543,
    LBMux	= 544,
    LBR	= 545,
    LCDBR	= 546,
    LCEBR	= 547,
    LCGFR	= 548,
    LCGR	= 549,
    LCR	= 550,
    LCXBR	= 551,
    LD	= 552,
    LDEB	= 553,
    LDEBR	= 554,
    LDGR	= 555,
    LDR	= 556,
    LDXBR	= 557,
    LDY	= 558,
    LE	= 559,
    LEDBR	= 560,
    LER	= 561,
    LEXBR	= 562,
    LEY	= 563,
    LFH	= 564,
    LG	= 565,
    LGB	= 566,
    LGBR	= 567,
    LGDR	= 568,
    LGF	= 569,
    LGFI	= 570,
    LGFR	= 571,
    LGFRL	= 572,
    LGH	= 573,
    LGHI	= 574,
    LGHR	= 575,
    LGHRL	= 576,
    LGR	= 577,
    LGRL	= 578,
    LH	= 579,
    LHH	= 580,
    LHI	= 581,
    LHIMux	= 582,
    LHMux	= 583,
    LHR	= 584,
    LHRL	= 585,
    LHY	= 586,
    LLC	= 587,
    LLCH	= 588,
    LLCMux	= 589,
    LLCR	= 590,
    LLCRMux	= 591,
    LLGC	= 592,
    LLGCR	= 593,
    LLGF	= 594,
    LLGFR	= 595,
    LLGFRL	= 596,
    LLGH	= 597,
    LLGHR	= 598,
    LLGHRL	= 599,
    LLH	= 600,
    LLHH	= 601,
    LLHMux	= 602,
    LLHR	= 603,
    LLHRL	= 604,
    LLHRMux	= 605,
    LLIHF	= 606,
    LLIHH	= 607,
    LLIHL	= 608,
    LLILF	= 609,
    LLILH	= 610,
    LLILL	= 611,
    LMG	= 612,
    LMux	= 613,
    LNDBR	= 614,
    LNEBR	= 615,
    LNGFR	= 616,
    LNGR	= 617,
    LNR	= 618,
    LNXBR	= 619,
    LOC	= 620,
    LOCG	= 621,
    LOCGR	= 622,
    LOCR	= 623,
    LPDBR	= 624,
    LPEBR	= 625,
    LPGFR	= 626,
    LPGR	= 627,
    LPR	= 628,
    LPXBR	= 629,
    LR	= 630,
    LRL	= 631,
    LRMux	= 632,
    LRV	= 633,
    LRVG	= 634,
    LRVGR	= 635,
    LRVR	= 636,
    LT	= 637,
    LTDBR	= 638,
    LTDBRCompare	= 639,
    LTEBR	= 640,
    LTEBRCompare	= 641,
    LTG	= 642,
    LTGF	= 643,
    LTGFR	= 644,
    LTGR	= 645,
    LTR	= 646,
    LTXBR	= 647,
    LTXBRCompare	= 648,
    LX	= 649,
    LXDB	= 650,
    LXDBR	= 651,
    LXEB	= 652,
    LXEBR	= 653,
    LXR	= 654,
    LY	= 655,
    LZDR	= 656,
    LZER	= 657,
    LZXR	= 658,
    MADB	= 659,
    MADBR	= 660,
    MAEB	= 661,
    MAEBR	= 662,
    MDB	= 663,
    MDBR	= 664,
    MDEB	= 665,
    MDEBR	= 666,
    MEEB	= 667,
    MEEBR	= 668,
    MGHI	= 669,
    MH	= 670,
    MHI	= 671,
    MHY	= 672,
    MLG	= 673,
    MLGR	= 674,
    MS	= 675,
    MSDB	= 676,
    MSDBR	= 677,
    MSEB	= 678,
    MSEBR	= 679,
    MSFI	= 680,
    MSG	= 681,
    MSGF	= 682,
    MSGFI	= 683,
    MSGFR	= 684,
    MSGR	= 685,
    MSR	= 686,
    MSY	= 687,
    MVC	= 688,
    MVCLoop	= 689,
    MVCSequence	= 690,
    MVGHI	= 691,
    MVHHI	= 692,
    MVHI	= 693,
    MVI	= 694,
    MVIY	= 695,
    MVST	= 696,
    MVSTLoop	= 697,
    MXBR	= 698,
    MXDB	= 699,
    MXDBR	= 700,
    N	= 701,
    NC	= 702,
    NCLoop	= 703,
    NCSequence	= 704,
    NG	= 705,
    NGR	= 706,
    NGRK	= 707,
    NI	= 708,
    NIFMux	= 709,
    NIHF	= 710,
    NIHF64	= 711,
    NIHH	= 712,
    NIHH64	= 713,
    NIHL	= 714,
    NIHL64	= 715,
    NIHMux	= 716,
    NILF	= 717,
    NILF64	= 718,
    NILH	= 719,
    NILH64	= 720,
    NILL	= 721,
    NILL64	= 722,
    NILMux	= 723,
    NIY	= 724,
    NR	= 725,
    NRK	= 726,
    NY	= 727,
    O	= 728,
    OC	= 729,
    OCLoop	= 730,
    OCSequence	= 731,
    OG	= 732,
    OGR	= 733,
    OGRK	= 734,
    OI	= 735,
    OIFMux	= 736,
    OIHF	= 737,
    OIHF64	= 738,
    OIHH	= 739,
    OIHH64	= 740,
    OIHL	= 741,
    OIHL64	= 742,
    OIHMux	= 743,
    OILF	= 744,
    OILF64	= 745,
    OILH	= 746,
    OILH64	= 747,
    OILL	= 748,
    OILL64	= 749,
    OILMux	= 750,
    OIY	= 751,
    OR	= 752,
    ORK	= 753,
    OY	= 754,
    PFD	= 755,
    PFDRL	= 756,
    RISBG	= 757,
    RISBG32	= 758,
    RISBHG	= 759,
    RISBHH	= 760,
    RISBHL	= 761,
    RISBLG	= 762,
    RISBLH	= 763,
    RISBLL	= 764,
    RISBMux	= 765,
    RLL	= 766,
    RLLG	= 767,
    RNSBG	= 768,
    ROSBG	= 769,
    RXSBG	= 770,
    Return	= 771,
    S	= 772,
    SDB	= 773,
    SDBR	= 774,
    SEB	= 775,
    SEBR	= 776,
    SG	= 777,
    SGF	= 778,
    SGFR	= 779,
    SGR	= 780,
    SGRK	= 781,
    SH	= 782,
    SHY	= 783,
    SL	= 784,
    SLB	= 785,
    SLBG	= 786,
    SLBR	= 787,
    SLFI	= 788,
    SLG	= 789,
    SLGBR	= 790,
    SLGF	= 791,
    SLGFI	= 792,
    SLGFR	= 793,
    SLGR	= 794,
    SLGRK	= 795,
    SLL	= 796,
    SLLG	= 797,
    SLLK	= 798,
    SLR	= 799,
    SLRK	= 800,
    SLY	= 801,
    SQDB	= 802,
    SQDBR	= 803,
    SQEB	= 804,
    SQEBR	= 805,
    SQXBR	= 806,
    SR	= 807,
    SRA	= 808,
    SRAG	= 809,
    SRAK	= 810,
    SRK	= 811,
    SRL	= 812,
    SRLG	= 813,
    SRLK	= 814,
    SRST	= 815,
    SRSTLoop	= 816,
    ST	= 817,
    ST128	= 818,
    STC	= 819,
    STCH	= 820,
    STCMux	= 821,
    STCY	= 822,
    STD	= 823,
    STDY	= 824,
    STE	= 825,
    STEY	= 826,
    STFH	= 827,
    STG	= 828,
    STGRL	= 829,
    STH	= 830,
    STHH	= 831,
    STHMux	= 832,
    STHRL	= 833,
    STHY	= 834,
    STMG	= 835,
    STMux	= 836,
    STOC	= 837,
    STOCG	= 838,
    STRL	= 839,
    STRV	= 840,
    STRVG	= 841,
    STX	= 842,
    STY	= 843,
    SXBR	= 844,
    SY	= 845,
    Select32	= 846,
    Select32Mux	= 847,
    Select64	= 848,
    SelectF128	= 849,
    SelectF32	= 850,
    SelectF64	= 851,
    TM	= 852,
    TMHH	= 853,
    TMHH64	= 854,
    TMHL	= 855,
    TMHL64	= 856,
    TMHMux	= 857,
    TMLH	= 858,
    TMLH64	= 859,
    TMLL	= 860,
    TMLL64	= 861,
    TMLMux	= 862,
    TMY	= 863,
    X	= 864,
    XC	= 865,
    XCLoop	= 866,
    XCSequence	= 867,
    XG	= 868,
    XGR	= 869,
    XGRK	= 870,
    XI	= 871,
    XIFMux	= 872,
    XIHF	= 873,
    XIHF64	= 874,
    XILF	= 875,
    XILF64	= 876,
    XIY	= 877,
    XR	= 878,
    XRK	= 879,
    XY	= 880,
    ZEXT128_32	= 881,
    ZEXT128_64	= 882,
    INSTRUCTION_LIST_END = 883
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

static const uint16_t ImplicitList1[] = { SystemZ::CC, 0 };
static const uint16_t ImplicitList2[] = { SystemZ::R0L, 0 };
static const uint16_t ImplicitList3[] = { SystemZ::R0D, SystemZ::R1D, SystemZ::R2D, SystemZ::R3D, SystemZ::R4D, SystemZ::R5D, SystemZ::R14D, SystemZ::F0D, SystemZ::F1D, SystemZ::F2D, SystemZ::F3D, SystemZ::F4D, SystemZ::F5D, SystemZ::F6D, SystemZ::F7D, SystemZ::CC, 0 };
static const uint16_t ImplicitList4[] = { SystemZ::R1D, 0 };

static const MCOperandInfo OperandInfo2[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo3[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo4[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo5[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo6[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo7[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo8[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo9[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo10[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo11[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo12[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo13[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo14[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo15[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo16[] = { { SystemZ::GR128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo17[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo18[] = { { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo19[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo20[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo21[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo22[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo23[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo24[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo25[] = { { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo26[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo27[] = { { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo28[] = { { SystemZ::GRH32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GRH32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo29[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo30[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo31[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo32[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo33[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo34[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo35[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo36[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo37[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo38[] = { { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo39[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo40[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo41[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo42[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo43[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo44[] = { { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo45[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo46[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo47[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo48[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo49[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo50[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo51[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo52[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo53[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo54[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo55[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo56[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo57[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo58[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo59[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo60[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo61[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo62[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo63[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo64[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo65[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo66[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo67[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo68[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo69[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo70[] = { { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo71[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo72[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo73[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo74[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo75[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo76[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo77[] = { { SystemZ::GRH32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo78[] = { { SystemZ::GRH32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo79[] = { { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo80[] = { { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo81[] = { { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo82[] = { { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo83[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo84[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((1 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo85[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo86[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo87[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo88[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo89[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo90[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo91[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo92[] = { { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo93[] = { { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo94[] = { { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo95[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo96[] = { { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo97[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo98[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo99[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo100[] = { { SystemZ::GR128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo101[] = { { SystemZ::GR128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo102[] = { { SystemZ::GR128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo103[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo104[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo105[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo106[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo107[] = { { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo108[] = { { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo109[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo110[] = { { SystemZ::GR128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo111[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo112[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo113[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo114[] = { { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo115[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo116[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo117[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo118[] = { { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo119[] = { { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo120[] = { { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo121[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo122[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo123[] = { { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo124[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo125[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo126[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo127[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo128[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo129[] = { { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo130[] = { { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo131[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo132[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo133[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo134[] = { { SystemZ::GRH32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GRH32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo135[] = { { SystemZ::GRH32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GRH32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GRH32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo136[] = { { SystemZ::GRH32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GRH32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo137[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo138[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GRH32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo139[] = { { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo140[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo141[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo142[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { SystemZ::ADDR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo143[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo144[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::ADDR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo145[] = { { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo146[] = { { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GRX32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo147[] = { { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo148[] = { { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo149[] = { { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo150[] = { { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::FP64BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo151[] = { { SystemZ::GR128BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { SystemZ::GR32BitRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };

extern const MCInstrDesc SystemZInsts[] = {
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
  { 19,	5,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x23c88ULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #19 = A
  { 20,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x3fd08ULL, NULL, ImplicitList1, OperandInfo11,0,0 },  // Inst #20 = ADB
  { 21,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x3fc00ULL, NULL, ImplicitList1, OperandInfo12,0,0 },  // Inst #21 = ADBR
  { 22,	1,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo2,0,0 },  // Inst #22 = ADJCALLSTACKDOWN
  { 23,	2,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo8,0,0 },  // Inst #23 = ADJCALLSTACKUP
  { 24,	4,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #24 = ADJDYNALLOC
  { 25,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x3fc88ULL, NULL, ImplicitList1, OperandInfo14,0,0 },  // Inst #25 = AEB
  { 26,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x3fc00ULL, NULL, ImplicitList1, OperandInfo15,0,0 },  // Inst #26 = AEBR
  { 27,	2,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UsesCustomInserter)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo16,0,0 },  // Inst #27 = AEXT128_64
  { 28,	3,	1,	0,	6,	0, 0x23c00ULL, NULL, ImplicitList1, OperandInfo17,0,0 },  // Inst #28 = AFI
  { 29,	3,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x23c00ULL, NULL, ImplicitList1, OperandInfo18,0,0 },  // Inst #29 = AFIMux
  { 30,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x23d0cULL, NULL, ImplicitList1, OperandInfo19,0,0 },  // Inst #30 = AG
  { 31,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x23c8cULL, NULL, ImplicitList1, OperandInfo19,0,0 },  // Inst #31 = AGF
  { 32,	3,	1,	0,	6,	0, 0x23c00ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #32 = AGFI
  { 33,	3,	1,	0,	4,	0, 0x23c00ULL, NULL, ImplicitList1, OperandInfo21,0,0 },  // Inst #33 = AGFR
  { 34,	3,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr), 0x23c00ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #34 = AGHI
  { 35,	3,	1,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x23c00ULL, NULL, ImplicitList1, OperandInfo22,0,0 },  // Inst #35 = AGHIK
  { 36,	3,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr)|(1<<MCID::Commutable), 0x23c00ULL, NULL, ImplicitList1, OperandInfo23,0,0 },  // Inst #36 = AGR
  { 37,	3,	1,	0,	4,	0|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x23c00ULL, NULL, ImplicitList1, OperandInfo24,0,0 },  // Inst #37 = AGRK
  { 38,	3,	0,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x23c04ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #38 = AGSI
  { 39,	5,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x23c48ULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #39 = AH
  { 40,	3,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr), 0x23c00ULL, NULL, ImplicitList1, OperandInfo17,0,0 },  // Inst #40 = AHI
  { 41,	3,	1,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x23c00ULL, NULL, ImplicitList1, OperandInfo26,0,0 },  // Inst #41 = AHIK
  { 42,	3,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::ConvertibleTo3Addr), 0x23c00ULL, NULL, ImplicitList1, OperandInfo18,0,0 },  // Inst #42 = AHIMux
  { 43,	3,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x23c00ULL, NULL, ImplicitList1, OperandInfo27,0,0 },  // Inst #43 = AHIMuxK
  { 44,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x23c4cULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #44 = AHY
  { 45,	3,	1,	0,	6,	0, 0x23c00ULL, NULL, ImplicitList1, OperandInfo28,0,0 },  // Inst #45 = AIH
  { 46,	5,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x88ULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #46 = AL
  { 47,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x8cULL, ImplicitList1, ImplicitList1, OperandInfo10,0,0 },  // Inst #47 = ALC
  { 48,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x10cULL, ImplicitList1, ImplicitList1, OperandInfo19,0,0 },  // Inst #48 = ALCG
  { 49,	3,	1,	0,	4,	0, 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo23,0,0 },  // Inst #49 = ALCGR
  { 50,	3,	1,	0,	4,	0, 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo29,0,0 },  // Inst #50 = ALCR
  { 51,	3,	1,	0,	6,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo17,0,0 },  // Inst #51 = ALFI
  { 52,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x10cULL, NULL, ImplicitList1, OperandInfo19,0,0 },  // Inst #52 = ALG
  { 53,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x8cULL, NULL, ImplicitList1, OperandInfo19,0,0 },  // Inst #53 = ALGF
  { 54,	3,	1,	0,	6,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #54 = ALGFI
  { 55,	3,	1,	0,	4,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo21,0,0 },  // Inst #55 = ALGFR
  { 56,	3,	1,	0,	6,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo22,0,0 },  // Inst #56 = ALGHSIK
  { 57,	3,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr)|(1<<MCID::Commutable), 0x0ULL, NULL, ImplicitList1, OperandInfo23,0,0 },  // Inst #57 = ALGR
  { 58,	3,	1,	0,	4,	0|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo24,0,0 },  // Inst #58 = ALGRK
  { 59,	3,	1,	0,	6,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo26,0,0 },  // Inst #59 = ALHSIK
  { 60,	3,	1,	0,	2,	0|(1<<MCID::ConvertibleTo3Addr)|(1<<MCID::Commutable), 0x0ULL, NULL, ImplicitList1, OperandInfo29,0,0 },  // Inst #60 = ALR
  { 61,	3,	1,	0,	4,	0|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo30,0,0 },  // Inst #61 = ALRK
  { 62,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x8cULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #62 = ALY
  { 63,	3,	1,	0,	2,	0|(1<<MCID::ConvertibleTo3Addr)|(1<<MCID::Commutable), 0x23c00ULL, NULL, ImplicitList1, OperandInfo29,0,0 },  // Inst #63 = AR
  { 64,	3,	1,	0,	4,	0|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x23c00ULL, NULL, ImplicitList1, OperandInfo30,0,0 },  // Inst #64 = ARK
  { 65,	3,	0,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x23c04ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #65 = ASI
  { 66,	8,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, ImplicitList1, OperandInfo31,0,0 },  // Inst #66 = ATOMIC_CMP_SWAPW
  { 67,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo32,0,0 },  // Inst #67 = ATOMIC_LOADW_AFI
  { 68,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo33,0,0 },  // Inst #68 = ATOMIC_LOADW_AR
  { 69,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo33,0,0 },  // Inst #69 = ATOMIC_LOADW_MAX
  { 70,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo33,0,0 },  // Inst #70 = ATOMIC_LOADW_MIN
  { 71,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo32,0,0 },  // Inst #71 = ATOMIC_LOADW_NILH
  { 72,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo32,0,0 },  // Inst #72 = ATOMIC_LOADW_NILHi
  { 73,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo33,0,0 },  // Inst #73 = ATOMIC_LOADW_NR
  { 74,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo33,0,0 },  // Inst #74 = ATOMIC_LOADW_NRi
  { 75,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo32,0,0 },  // Inst #75 = ATOMIC_LOADW_OILH
  { 76,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo33,0,0 },  // Inst #76 = ATOMIC_LOADW_OR
  { 77,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo33,0,0 },  // Inst #77 = ATOMIC_LOADW_SR
  { 78,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo33,0,0 },  // Inst #78 = ATOMIC_LOADW_UMAX
  { 79,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo33,0,0 },  // Inst #79 = ATOMIC_LOADW_UMIN
  { 80,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo32,0,0 },  // Inst #80 = ATOMIC_LOADW_XILF
  { 81,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo33,0,0 },  // Inst #81 = ATOMIC_LOADW_XR
  { 82,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo34,0,0 },  // Inst #82 = ATOMIC_LOAD_AFI
  { 83,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #83 = ATOMIC_LOAD_AGFI
  { 84,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #84 = ATOMIC_LOAD_AGHI
  { 85,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo36,0,0 },  // Inst #85 = ATOMIC_LOAD_AGR
  { 86,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo34,0,0 },  // Inst #86 = ATOMIC_LOAD_AHI
  { 87,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo37,0,0 },  // Inst #87 = ATOMIC_LOAD_AR
  { 88,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo37,0,0 },  // Inst #88 = ATOMIC_LOAD_MAX_32
  { 89,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo36,0,0 },  // Inst #89 = ATOMIC_LOAD_MAX_64
  { 90,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo37,0,0 },  // Inst #90 = ATOMIC_LOAD_MIN_32
  { 91,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo36,0,0 },  // Inst #91 = ATOMIC_LOAD_MIN_64
  { 92,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo36,0,0 },  // Inst #92 = ATOMIC_LOAD_NGR
  { 93,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo36,0,0 },  // Inst #93 = ATOMIC_LOAD_NGRi
  { 94,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #94 = ATOMIC_LOAD_NIHF64
  { 95,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #95 = ATOMIC_LOAD_NIHF64i
  { 96,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #96 = ATOMIC_LOAD_NIHH64
  { 97,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #97 = ATOMIC_LOAD_NIHH64i
  { 98,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #98 = ATOMIC_LOAD_NIHL64
  { 99,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #99 = ATOMIC_LOAD_NIHL64i
  { 100,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo34,0,0 },  // Inst #100 = ATOMIC_LOAD_NILF
  { 101,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #101 = ATOMIC_LOAD_NILF64
  { 102,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #102 = ATOMIC_LOAD_NILF64i
  { 103,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo34,0,0 },  // Inst #103 = ATOMIC_LOAD_NILFi
  { 104,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo34,0,0 },  // Inst #104 = ATOMIC_LOAD_NILH
  { 105,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #105 = ATOMIC_LOAD_NILH64
  { 106,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #106 = ATOMIC_LOAD_NILH64i
  { 107,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo34,0,0 },  // Inst #107 = ATOMIC_LOAD_NILHi
  { 108,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo34,0,0 },  // Inst #108 = ATOMIC_LOAD_NILL
  { 109,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #109 = ATOMIC_LOAD_NILL64
  { 110,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #110 = ATOMIC_LOAD_NILL64i
  { 111,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo34,0,0 },  // Inst #111 = ATOMIC_LOAD_NILLi
  { 112,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo37,0,0 },  // Inst #112 = ATOMIC_LOAD_NR
  { 113,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo37,0,0 },  // Inst #113 = ATOMIC_LOAD_NRi
  { 114,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo36,0,0 },  // Inst #114 = ATOMIC_LOAD_OGR
  { 115,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #115 = ATOMIC_LOAD_OIHF64
  { 116,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #116 = ATOMIC_LOAD_OIHH64
  { 117,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #117 = ATOMIC_LOAD_OIHL64
  { 118,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo34,0,0 },  // Inst #118 = ATOMIC_LOAD_OILF
  { 119,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #119 = ATOMIC_LOAD_OILF64
  { 120,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo34,0,0 },  // Inst #120 = ATOMIC_LOAD_OILH
  { 121,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #121 = ATOMIC_LOAD_OILH64
  { 122,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo34,0,0 },  // Inst #122 = ATOMIC_LOAD_OILL
  { 123,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #123 = ATOMIC_LOAD_OILL64
  { 124,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo37,0,0 },  // Inst #124 = ATOMIC_LOAD_OR
  { 125,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo36,0,0 },  // Inst #125 = ATOMIC_LOAD_SGR
  { 126,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo37,0,0 },  // Inst #126 = ATOMIC_LOAD_SR
  { 127,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo37,0,0 },  // Inst #127 = ATOMIC_LOAD_UMAX_32
  { 128,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo36,0,0 },  // Inst #128 = ATOMIC_LOAD_UMAX_64
  { 129,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo37,0,0 },  // Inst #129 = ATOMIC_LOAD_UMIN_32
  { 130,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo36,0,0 },  // Inst #130 = ATOMIC_LOAD_UMIN_64
  { 131,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo36,0,0 },  // Inst #131 = ATOMIC_LOAD_XGR
  { 132,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #132 = ATOMIC_LOAD_XIHF64
  { 133,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo34,0,0 },  // Inst #133 = ATOMIC_LOAD_XILF
  { 134,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo35,0,0 },  // Inst #134 = ATOMIC_LOAD_XILF64
  { 135,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo37,0,0 },  // Inst #135 = ATOMIC_LOAD_XR
  { 136,	7,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo33,0,0 },  // Inst #136 = ATOMIC_SWAPW
  { 137,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo37,0,0 },  // Inst #137 = ATOMIC_SWAP_32
  { 138,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x4ULL, NULL, ImplicitList1, OperandInfo36,0,0 },  // Inst #138 = ATOMIC_SWAP_64
  { 139,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x3fc00ULL, NULL, ImplicitList1, OperandInfo38,0,0 },  // Inst #139 = AXBR
  { 140,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x23c8cULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #140 = AY
  { 141,	2,	0,	0,	2,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, OperandInfo39,0,0 },  // Inst #141 = AsmBCR
  { 142,	2,	0,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, OperandInfo7,0,0 },  // Inst #142 = AsmBRC
  { 143,	2,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, OperandInfo7,0,0 },  // Inst #143 = AsmBRCL
  { 144,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo40,0,0 },  // Inst #144 = AsmCGIJ
  { 145,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo41,0,0 },  // Inst #145 = AsmCGRJ
  { 146,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo42,0,0 },  // Inst #146 = AsmCIJ
  { 147,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo40,0,0 },  // Inst #147 = AsmCLGIJ
  { 148,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo41,0,0 },  // Inst #148 = AsmCLGRJ
  { 149,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo42,0,0 },  // Inst #149 = AsmCLIJ
  { 150,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo43,0,0 },  // Inst #150 = AsmCLRJ
  { 151,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo43,0,0 },  // Inst #151 = AsmCRJ
  { 152,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #152 = AsmEBR
  { 153,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #153 = AsmEJ
  { 154,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #154 = AsmEJG
  { 155,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #155 = AsmELOC
  { 156,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #156 = AsmELOCG
  { 157,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #157 = AsmELOCGR
  { 158,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #158 = AsmELOCR
  { 159,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #159 = AsmESTOC
  { 160,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #160 = AsmESTOCG
  { 161,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #161 = AsmHBR
  { 162,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #162 = AsmHEBR
  { 163,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #163 = AsmHEJ
  { 164,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #164 = AsmHEJG
  { 165,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #165 = AsmHELOC
  { 166,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #166 = AsmHELOCG
  { 167,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #167 = AsmHELOCGR
  { 168,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #168 = AsmHELOCR
  { 169,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #169 = AsmHESTOC
  { 170,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #170 = AsmHESTOCG
  { 171,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #171 = AsmHJ
  { 172,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #172 = AsmHJG
  { 173,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #173 = AsmHLOC
  { 174,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #174 = AsmHLOCG
  { 175,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #175 = AsmHLOCGR
  { 176,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #176 = AsmHLOCR
  { 177,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #177 = AsmHSTOC
  { 178,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #178 = AsmHSTOCG
  { 179,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #179 = AsmJEAltCGI
  { 180,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #180 = AsmJEAltCGR
  { 181,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #181 = AsmJEAltCI
  { 182,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #182 = AsmJEAltCLGI
  { 183,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #183 = AsmJEAltCLGR
  { 184,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #184 = AsmJEAltCLI
  { 185,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #185 = AsmJEAltCLR
  { 186,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #186 = AsmJEAltCR
  { 187,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #187 = AsmJECGI
  { 188,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #188 = AsmJECGR
  { 189,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #189 = AsmJECI
  { 190,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #190 = AsmJECLGI
  { 191,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #191 = AsmJECLGR
  { 192,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #192 = AsmJECLI
  { 193,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #193 = AsmJECLR
  { 194,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #194 = AsmJECR
  { 195,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #195 = AsmJHAltCGI
  { 196,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #196 = AsmJHAltCGR
  { 197,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #197 = AsmJHAltCI
  { 198,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #198 = AsmJHAltCLGI
  { 199,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #199 = AsmJHAltCLGR
  { 200,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #200 = AsmJHAltCLI
  { 201,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #201 = AsmJHAltCLR
  { 202,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #202 = AsmJHAltCR
  { 203,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #203 = AsmJHCGI
  { 204,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #204 = AsmJHCGR
  { 205,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #205 = AsmJHCI
  { 206,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #206 = AsmJHCLGI
  { 207,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #207 = AsmJHCLGR
  { 208,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #208 = AsmJHCLI
  { 209,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #209 = AsmJHCLR
  { 210,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #210 = AsmJHCR
  { 211,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #211 = AsmJHEAltCGI
  { 212,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #212 = AsmJHEAltCGR
  { 213,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #213 = AsmJHEAltCI
  { 214,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #214 = AsmJHEAltCLGI
  { 215,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #215 = AsmJHEAltCLGR
  { 216,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #216 = AsmJHEAltCLI
  { 217,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #217 = AsmJHEAltCLR
  { 218,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #218 = AsmJHEAltCR
  { 219,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #219 = AsmJHECGI
  { 220,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #220 = AsmJHECGR
  { 221,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #221 = AsmJHECI
  { 222,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #222 = AsmJHECLGI
  { 223,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #223 = AsmJHECLGR
  { 224,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #224 = AsmJHECLI
  { 225,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #225 = AsmJHECLR
  { 226,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #226 = AsmJHECR
  { 227,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #227 = AsmJLAltCGI
  { 228,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #228 = AsmJLAltCGR
  { 229,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #229 = AsmJLAltCI
  { 230,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #230 = AsmJLAltCLGI
  { 231,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #231 = AsmJLAltCLGR
  { 232,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #232 = AsmJLAltCLI
  { 233,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #233 = AsmJLAltCLR
  { 234,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #234 = AsmJLAltCR
  { 235,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #235 = AsmJLCGI
  { 236,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #236 = AsmJLCGR
  { 237,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #237 = AsmJLCI
  { 238,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #238 = AsmJLCLGI
  { 239,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #239 = AsmJLCLGR
  { 240,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #240 = AsmJLCLI
  { 241,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #241 = AsmJLCLR
  { 242,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #242 = AsmJLCR
  { 243,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #243 = AsmJLEAltCGI
  { 244,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #244 = AsmJLEAltCGR
  { 245,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #245 = AsmJLEAltCI
  { 246,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #246 = AsmJLEAltCLGI
  { 247,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #247 = AsmJLEAltCLGR
  { 248,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #248 = AsmJLEAltCLI
  { 249,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #249 = AsmJLEAltCLR
  { 250,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #250 = AsmJLEAltCR
  { 251,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #251 = AsmJLECGI
  { 252,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #252 = AsmJLECGR
  { 253,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #253 = AsmJLECI
  { 254,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #254 = AsmJLECLGI
  { 255,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #255 = AsmJLECLGR
  { 256,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #256 = AsmJLECLI
  { 257,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #257 = AsmJLECLR
  { 258,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #258 = AsmJLECR
  { 259,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #259 = AsmJLHAltCGI
  { 260,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #260 = AsmJLHAltCGR
  { 261,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #261 = AsmJLHAltCI
  { 262,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #262 = AsmJLHAltCLGI
  { 263,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #263 = AsmJLHAltCLGR
  { 264,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #264 = AsmJLHAltCLI
  { 265,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #265 = AsmJLHAltCLR
  { 266,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #266 = AsmJLHAltCR
  { 267,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #267 = AsmJLHCGI
  { 268,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #268 = AsmJLHCGR
  { 269,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #269 = AsmJLHCI
  { 270,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo49,0,0 },  // Inst #270 = AsmJLHCLGI
  { 271,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo22,0,0 },  // Inst #271 = AsmJLHCLGR
  { 272,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo50,0,0 },  // Inst #272 = AsmJLHCLI
  { 273,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #273 = AsmJLHCLR
  { 274,	3,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo26,0,0 },  // Inst #274 = AsmJLHCR
  { 275,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #275 = AsmLBR
  { 276,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #276 = AsmLEBR
  { 277,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #277 = AsmLEJ
  { 278,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #278 = AsmLEJG
  { 279,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #279 = AsmLELOC
  { 280,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #280 = AsmLELOCG
  { 281,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #281 = AsmLELOCGR
  { 282,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #282 = AsmLELOCR
  { 283,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #283 = AsmLESTOC
  { 284,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #284 = AsmLESTOCG
  { 285,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #285 = AsmLHBR
  { 286,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #286 = AsmLHJ
  { 287,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #287 = AsmLHJG
  { 288,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #288 = AsmLHLOC
  { 289,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #289 = AsmLHLOCG
  { 290,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #290 = AsmLHLOCGR
  { 291,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #291 = AsmLHLOCR
  { 292,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #292 = AsmLHSTOC
  { 293,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #293 = AsmLHSTOCG
  { 294,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #294 = AsmLJ
  { 295,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #295 = AsmLJG
  { 296,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #296 = AsmLLOC
  { 297,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #297 = AsmLLOCG
  { 298,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #298 = AsmLLOCGR
  { 299,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #299 = AsmLLOCR
  { 300,	5,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, ImplicitList1, NULL, OperandInfo51,0,0 },  // Inst #300 = AsmLOC
  { 301,	5,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, ImplicitList1, NULL, OperandInfo52,0,0 },  // Inst #301 = AsmLOCG
  { 302,	4,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, OperandInfo53,0,0 },  // Inst #302 = AsmLOCGR
  { 303,	4,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList1, NULL, OperandInfo54,0,0 },  // Inst #303 = AsmLOCR
  { 304,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #304 = AsmLSTOC
  { 305,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #305 = AsmLSTOCG
  { 306,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #306 = AsmNEBR
  { 307,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #307 = AsmNEJ
  { 308,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #308 = AsmNEJG
  { 309,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #309 = AsmNELOC
  { 310,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #310 = AsmNELOCG
  { 311,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #311 = AsmNELOCGR
  { 312,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #312 = AsmNELOCR
  { 313,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #313 = AsmNESTOC
  { 314,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #314 = AsmNESTOCG
  { 315,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #315 = AsmNHBR
  { 316,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #316 = AsmNHEBR
  { 317,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #317 = AsmNHEJ
  { 318,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #318 = AsmNHEJG
  { 319,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #319 = AsmNHELOC
  { 320,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #320 = AsmNHELOCG
  { 321,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #321 = AsmNHELOCGR
  { 322,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #322 = AsmNHELOCR
  { 323,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #323 = AsmNHESTOC
  { 324,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #324 = AsmNHESTOCG
  { 325,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #325 = AsmNHJ
  { 326,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #326 = AsmNHJG
  { 327,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #327 = AsmNHLOC
  { 328,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #328 = AsmNHLOCG
  { 329,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #329 = AsmNHLOCGR
  { 330,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #330 = AsmNHLOCR
  { 331,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #331 = AsmNHSTOC
  { 332,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #332 = AsmNHSTOCG
  { 333,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #333 = AsmNLBR
  { 334,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #334 = AsmNLEBR
  { 335,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #335 = AsmNLEJ
  { 336,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #336 = AsmNLEJG
  { 337,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #337 = AsmNLELOC
  { 338,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #338 = AsmNLELOCG
  { 339,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #339 = AsmNLELOCGR
  { 340,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #340 = AsmNLELOCR
  { 341,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #341 = AsmNLESTOC
  { 342,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #342 = AsmNLESTOCG
  { 343,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #343 = AsmNLHBR
  { 344,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #344 = AsmNLHJ
  { 345,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #345 = AsmNLHJG
  { 346,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #346 = AsmNLHLOC
  { 347,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #347 = AsmNLHLOCG
  { 348,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #348 = AsmNLHLOCGR
  { 349,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #349 = AsmNLHLOCR
  { 350,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #350 = AsmNLHSTOC
  { 351,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #351 = AsmNLHSTOCG
  { 352,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #352 = AsmNLJ
  { 353,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #353 = AsmNLJG
  { 354,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #354 = AsmNLLOC
  { 355,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #355 = AsmNLLOCG
  { 356,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #356 = AsmNLLOCGR
  { 357,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #357 = AsmNLLOCR
  { 358,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #358 = AsmNLSTOC
  { 359,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #359 = AsmNLSTOCG
  { 360,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #360 = AsmNOBR
  { 361,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #361 = AsmNOJ
  { 362,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #362 = AsmNOJG
  { 363,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #363 = AsmNOLOC
  { 364,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #364 = AsmNOLOCG
  { 365,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #365 = AsmNOLOCGR
  { 366,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #366 = AsmNOLOCR
  { 367,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #367 = AsmNOSTOC
  { 368,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #368 = AsmNOSTOCG
  { 369,	1,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #369 = AsmOBR
  { 370,	1,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #370 = AsmOJ
  { 371,	1,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #371 = AsmOJG
  { 372,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo45,0,0 },  // Inst #372 = AsmOLOC
  { 373,	4,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo46,0,0 },  // Inst #373 = AsmOLOCG
  { 374,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #374 = AsmOLOCGR
  { 375,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #375 = AsmOLOCR
  { 376,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, NULL, NULL, OperandInfo47,0,0 },  // Inst #376 = AsmOSTOC
  { 377,	3,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, NULL, NULL, OperandInfo48,0,0 },  // Inst #377 = AsmOSTOCG
  { 378,	4,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x84ULL, ImplicitList1, NULL, OperandInfo34,0,0 },  // Inst #378 = AsmSTOC
  { 379,	4,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x104ULL, ImplicitList1, NULL, OperandInfo35,0,0 },  // Inst #379 = AsmSTOCG
  { 380,	2,	0,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo55,0,0 },  // Inst #380 = BASR
  { 381,	1,	0,	0,	2,	0|(1<<MCID::Branch)|(1<<MCID::IndirectBranch)|(1<<MCID::Barrier)|(1<<MCID::Terminator), 0x0ULL, NULL, NULL, OperandInfo44,0,0 },  // Inst #381 = BR
  { 382,	2,	0,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #382 = BRAS
  { 383,	2,	0,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #383 = BRASL
  { 384,	3,	0,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator), 0x40000ULL, ImplicitList1, NULL, OperandInfo57,0,0 },  // Inst #384 = BRC
  { 385,	3,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x40000ULL, ImplicitList1, NULL, OperandInfo57,0,0 },  // Inst #385 = BRCL
  { 386,	3,	1,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo17,0,0 },  // Inst #386 = BRCT
  { 387,	3,	1,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #387 = BRCTG
  { 388,	4,	0,	0,	4,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x3888ULL, NULL, ImplicitList1, OperandInfo58,0,0 },  // Inst #388 = C
  { 389,	4,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x3d08ULL, NULL, ImplicitList1, OperandInfo59,0,0 },  // Inst #389 = CDB
  { 390,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x3c00ULL, NULL, ImplicitList1, OperandInfo60,0,0 },  // Inst #390 = CDBR
  { 391,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo61,0,0 },  // Inst #391 = CDFBR
  { 392,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo62,0,0 },  // Inst #392 = CDGBR
  { 393,	4,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x3c88ULL, NULL, ImplicitList1, OperandInfo63,0,0 },  // Inst #393 = CEB
  { 394,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x3c00ULL, NULL, ImplicitList1, OperandInfo64,0,0 },  // Inst #394 = CEBR
  { 395,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo65,0,0 },  // Inst #395 = CEFBR
  { 396,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo66,0,0 },  // Inst #396 = CEGBR
  { 397,	3,	1,	0,	4,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo67,0,0 },  // Inst #397 = CFDBR
  { 398,	3,	1,	0,	4,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo68,0,0 },  // Inst #398 = CFEBR
  { 399,	2,	0,	0,	6,	0|(1<<MCID::Compare), 0x3800ULL, NULL, ImplicitList1, OperandInfo69,0,0 },  // Inst #399 = CFI
  { 400,	2,	0,	0,	0,	0|(1<<MCID::Pseudo), 0x3800ULL, NULL, ImplicitList1, OperandInfo70,0,0 },  // Inst #400 = CFIMux
  { 401,	3,	1,	0,	4,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo71,0,0 },  // Inst #401 = CFXBR
  { 402,	4,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x390cULL, NULL, ImplicitList1, OperandInfo13,0,0 },  // Inst #402 = CG
  { 403,	3,	1,	0,	4,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo72,0,0 },  // Inst #403 = CGDBR
  { 404,	3,	1,	0,	4,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo73,0,0 },  // Inst #404 = CGEBR
  { 405,	4,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x388cULL, NULL, ImplicitList1, OperandInfo13,0,0 },  // Inst #405 = CGF
  { 406,	2,	0,	0,	6,	0|(1<<MCID::Compare), 0x3800ULL, NULL, ImplicitList1, OperandInfo56,0,0 },  // Inst #406 = CGFI
  { 407,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x3800ULL, NULL, ImplicitList1, OperandInfo74,0,0 },  // Inst #407 = CGFR
  { 408,	2,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x3800ULL, NULL, ImplicitList1, OperandInfo56,0,0 },  // Inst #408 = CGFRL
  { 409,	4,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x384cULL, NULL, ImplicitList1, OperandInfo13,0,0 },  // Inst #409 = CGH
  { 410,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x3800ULL, NULL, ImplicitList1, OperandInfo56,0,0 },  // Inst #410 = CGHI
  { 411,	2,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x3800ULL, NULL, ImplicitList1, OperandInfo56,0,0 },  // Inst #411 = CGHRL
  { 412,	3,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x3800ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #412 = CGHSI
  { 413,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo40,0,0 },  // Inst #413 = CGIJ
  { 414,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x3800ULL, NULL, ImplicitList1, OperandInfo75,0,0 },  // Inst #414 = CGR
  { 415,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo41,0,0 },  // Inst #415 = CGRJ
  { 416,	2,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x3800ULL, NULL, ImplicitList1, OperandInfo56,0,0 },  // Inst #416 = CGRL
  { 417,	3,	1,	0,	4,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo76,0,0 },  // Inst #417 = CGXBR
  { 418,	4,	0,	0,	4,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x3848ULL, NULL, ImplicitList1, OperandInfo58,0,0 },  // Inst #418 = CH
  { 419,	4,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x388cULL, NULL, ImplicitList1, OperandInfo77,0,0 },  // Inst #419 = CHF
  { 420,	3,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x3800ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #420 = CHHSI
  { 421,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x3800ULL, NULL, ImplicitList1, OperandInfo69,0,0 },  // Inst #421 = CHI
  { 422,	2,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x3800ULL, NULL, ImplicitList1, OperandInfo69,0,0 },  // Inst #422 = CHRL
  { 423,	3,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x3800ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #423 = CHSI
  { 424,	4,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x384cULL, NULL, ImplicitList1, OperandInfo58,0,0 },  // Inst #424 = CHY
  { 425,	2,	0,	0,	6,	0|(1<<MCID::Compare), 0x3800ULL, NULL, ImplicitList1, OperandInfo78,0,0 },  // Inst #425 = CIH
  { 426,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo42,0,0 },  // Inst #426 = CIJ
  { 427,	4,	0,	0,	4,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x103888ULL, NULL, ImplicitList1, OperandInfo58,0,0 },  // Inst #427 = CL
  { 428,	5,	0,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo79,0,0 },  // Inst #428 = CLC
  { 429,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, ImplicitList1, OperandInfo80,0,0 },  // Inst #429 = CLCLoop
  { 430,	5,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, ImplicitList1, OperandInfo81,0,0 },  // Inst #430 = CLCSequence
  { 431,	3,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x103800ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #431 = CLFHSI
  { 432,	2,	0,	0,	6,	0|(1<<MCID::Compare), 0x103800ULL, NULL, ImplicitList1, OperandInfo69,0,0 },  // Inst #432 = CLFI
  { 433,	2,	0,	0,	0,	0|(1<<MCID::Pseudo), 0x103800ULL, NULL, ImplicitList1, OperandInfo70,0,0 },  // Inst #433 = CLFIMux
  { 434,	4,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x10390cULL, NULL, ImplicitList1, OperandInfo13,0,0 },  // Inst #434 = CLG
  { 435,	4,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x10388cULL, NULL, ImplicitList1, OperandInfo13,0,0 },  // Inst #435 = CLGF
  { 436,	2,	0,	0,	6,	0|(1<<MCID::Compare), 0x103800ULL, NULL, ImplicitList1, OperandInfo56,0,0 },  // Inst #436 = CLGFI
  { 437,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x103800ULL, NULL, ImplicitList1, OperandInfo74,0,0 },  // Inst #437 = CLGFR
  { 438,	2,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x103800ULL, NULL, ImplicitList1, OperandInfo56,0,0 },  // Inst #438 = CLGFRL
  { 439,	2,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x103800ULL, NULL, ImplicitList1, OperandInfo56,0,0 },  // Inst #439 = CLGHRL
  { 440,	3,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x103800ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #440 = CLGHSI
  { 441,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo40,0,0 },  // Inst #441 = CLGIJ
  { 442,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x103800ULL, NULL, ImplicitList1, OperandInfo75,0,0 },  // Inst #442 = CLGR
  { 443,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo41,0,0 },  // Inst #443 = CLGRJ
  { 444,	2,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x103800ULL, NULL, ImplicitList1, OperandInfo56,0,0 },  // Inst #444 = CLGRL
  { 445,	4,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x10388cULL, NULL, ImplicitList1, OperandInfo77,0,0 },  // Inst #445 = CLHF
  { 446,	3,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x103800ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #446 = CLHHSI
  { 447,	2,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x103800ULL, NULL, ImplicitList1, OperandInfo69,0,0 },  // Inst #447 = CLHRL
  { 448,	3,	0,	0,	4,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x103800ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #448 = CLI
  { 449,	2,	0,	0,	6,	0|(1<<MCID::Compare), 0x103800ULL, NULL, ImplicitList1, OperandInfo69,0,0 },  // Inst #449 = CLIH
  { 450,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo42,0,0 },  // Inst #450 = CLIJ
  { 451,	3,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x103804ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #451 = CLIY
  { 452,	4,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad), 0x10388cULL, NULL, ImplicitList1, OperandInfo82,0,0 },  // Inst #452 = CLMux
  { 453,	2,	0,	0,	2,	0|(1<<MCID::Compare), 0x103800ULL, NULL, ImplicitList1, OperandInfo83,0,0 },  // Inst #453 = CLR
  { 454,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo43,0,0 },  // Inst #454 = CLRJ
  { 455,	2,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x103800ULL, NULL, ImplicitList1, OperandInfo69,0,0 },  // Inst #455 = CLRL
  { 456,	4,	2,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList2, ImplicitList1, OperandInfo84,0,0 },  // Inst #456 = CLST
  { 457,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList2, ImplicitList1, OperandInfo85,0,0 },  // Inst #457 = CLSTLoop
  { 458,	4,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x10388cULL, NULL, ImplicitList1, OperandInfo58,0,0 },  // Inst #458 = CLY
  { 459,	4,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad), 0x388cULL, NULL, ImplicitList1, OperandInfo82,0,0 },  // Inst #459 = CMux
  { 460,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo86,0,0 },  // Inst #460 = CPSDRdd
  { 461,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo87,0,0 },  // Inst #461 = CPSDRds
  { 462,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo88,0,0 },  // Inst #462 = CPSDRsd
  { 463,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo89,0,0 },  // Inst #463 = CPSDRss
  { 464,	2,	0,	0,	2,	0|(1<<MCID::Compare), 0x3800ULL, NULL, ImplicitList1, OperandInfo83,0,0 },  // Inst #464 = CR
  { 465,	4,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo43,0,0 },  // Inst #465 = CRJ
  { 466,	2,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x3800ULL, NULL, ImplicitList1, OperandInfo69,0,0 },  // Inst #466 = CRL
  { 467,	5,	1,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x0ULL, NULL, ImplicitList1, OperandInfo90,0,0 },  // Inst #467 = CS
  { 468,	5,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x4ULL, NULL, ImplicitList1, OperandInfo91,0,0 },  // Inst #468 = CSG
  { 469,	5,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x4ULL, NULL, ImplicitList1, OperandInfo90,0,0 },  // Inst #469 = CSY
  { 470,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x3c00ULL, NULL, ImplicitList1, OperandInfo92,0,0 },  // Inst #470 = CXBR
  { 471,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo93,0,0 },  // Inst #471 = CXFBR
  { 472,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo94,0,0 },  // Inst #472 = CXGBR
  { 473,	4,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x388cULL, NULL, ImplicitList1, OperandInfo58,0,0 },  // Inst #473 = CY
  { 474,	1,	0,	0,	2,	0|(1<<MCID::Pseudo)|(1<<MCID::Call)|(1<<MCID::Variadic), 0x0ULL, NULL, ImplicitList3, OperandInfo44,0,0 },  // Inst #474 = CallBASR
  { 475,	0,	0,	0,	2,	0|(1<<MCID::Pseudo)|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::Call)|(1<<MCID::Terminator), 0x0ULL, ImplicitList4, NULL, 0,0,0 },  // Inst #475 = CallBR
  { 476,	1,	0,	0,	6,	0|(1<<MCID::Pseudo)|(1<<MCID::Call)|(1<<MCID::Variadic), 0x0ULL, NULL, ImplicitList3, OperandInfo5,0,0 },  // Inst #476 = CallBRASL
  { 477,	1,	0,	0,	6,	0|(1<<MCID::Pseudo)|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::Call)|(1<<MCID::Terminator), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #477 = CallJG
  { 478,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo95,0,0 },  // Inst #478 = CondStore16
  { 479,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo95,0,0 },  // Inst #479 = CondStore16Inv
  { 480,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo96,0,0 },  // Inst #480 = CondStore16Mux
  { 481,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo96,0,0 },  // Inst #481 = CondStore16MuxInv
  { 482,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo95,0,0 },  // Inst #482 = CondStore32
  { 483,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo95,0,0 },  // Inst #483 = CondStore32Inv
  { 484,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo97,0,0 },  // Inst #484 = CondStore64
  { 485,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo97,0,0 },  // Inst #485 = CondStore64Inv
  { 486,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo95,0,0 },  // Inst #486 = CondStore8
  { 487,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo95,0,0 },  // Inst #487 = CondStore8Inv
  { 488,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo96,0,0 },  // Inst #488 = CondStore8Mux
  { 489,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo96,0,0 },  // Inst #489 = CondStore8MuxInv
  { 490,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo98,0,0 },  // Inst #490 = CondStoreF32
  { 491,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo98,0,0 },  // Inst #491 = CondStoreF32Inv
  { 492,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo99,0,0 },  // Inst #492 = CondStoreF64
  { 493,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo99,0,0 },  // Inst #493 = CondStoreF64Inv
  { 494,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x108ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #494 = DDB
  { 495,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #495 = DDBR
  { 496,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x88ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #496 = DEB
  { 497,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #497 = DEBR
  { 498,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x8cULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #498 = DL
  { 499,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x10cULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #499 = DLG
  { 500,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo101,0,0 },  // Inst #500 = DLGR
  { 501,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo102,0,0 },  // Inst #501 = DLR
  { 502,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x10cULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #502 = DSG
  { 503,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x8cULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #503 = DSGF
  { 504,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo102,0,0 },  // Inst #504 = DSGFR
  { 505,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo101,0,0 },  // Inst #505 = DSGR
  { 506,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo38,0,0 },  // Inst #506 = DXBR
  { 507,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo69,0,0 },  // Inst #507 = EAR
  { 508,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo103,0,0 },  // Inst #508 = FIDBR
  { 509,	4,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo104,0,0 },  // Inst #509 = FIDBRA
  { 510,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo105,0,0 },  // Inst #510 = FIEBR
  { 511,	4,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo106,0,0 },  // Inst #511 = FIEBRA
  { 512,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo107,0,0 },  // Inst #512 = FIXBR
  { 513,	4,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo108,0,0 },  // Inst #513 = FIXBRA
  { 514,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo16,0,0 },  // Inst #514 = FLOGR
  { 515,	5,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x28ULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #515 = IC
  { 516,	5,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x28ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #516 = IC32
  { 517,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2cULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #517 = IC32Y
  { 518,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2cULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #518 = ICY
  { 519,	2,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo70,0,0 },  // Inst #519 = IIFMux
  { 520,	2,	1,	0,	6,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo78,0,0 },  // Inst #520 = IIHF
  { 521,	3,	1,	0,	6,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo20,0,0 },  // Inst #521 = IIHF64
  { 522,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #522 = IIHH
  { 523,	3,	1,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo20,0,0 },  // Inst #523 = IIHH64
  { 524,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo28,0,0 },  // Inst #524 = IIHL
  { 525,	3,	1,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo20,0,0 },  // Inst #525 = IIHL64
  { 526,	3,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo18,0,0 },  // Inst #526 = IIHMux
  { 527,	2,	1,	0,	6,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo69,0,0 },  // Inst #527 = IILF
  { 528,	3,	1,	0,	6,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo20,0,0 },  // Inst #528 = IILF64
  { 529,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo17,0,0 },  // Inst #529 = IILH
  { 530,	3,	1,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo20,0,0 },  // Inst #530 = IILH64
  { 531,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo17,0,0 },  // Inst #531 = IILL
  { 532,	3,	1,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo20,0,0 },  // Inst #532 = IILL64
  { 533,	3,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo18,0,0 },  // Inst #533 = IILMux
  { 534,	1,	1,	0,	4,	0, 0x0ULL, ImplicitList1, NULL, OperandInfo109,0,0 },  // Inst #534 = IPM
  { 535,	1,	0,	0,	4,	0|(1<<MCID::Branch)|(1<<MCID::Barrier)|(1<<MCID::Terminator), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #535 = J
  { 536,	1,	0,	0,	6,	0|(1<<MCID::Branch)|(1<<MCID::Barrier)|(1<<MCID::Terminator)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo5,0,0 },  // Inst #536 = JG
  { 537,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x89ULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #537 = L
  { 538,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x1dULL, NULL, NULL, OperandInfo110,0,0 },  // Inst #538 = L128
  { 539,	4,	1,	0,	4,	0|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x8ULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #539 = LA
  { 540,	2,	1,	0,	6,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #540 = LARL
  { 541,	4,	1,	0,	6,	0|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0xcULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #541 = LAY
  { 542,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2cULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #542 = LB
  { 543,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2cULL, NULL, NULL, OperandInfo77,0,0 },  // Inst #543 = LBH
  { 544,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad), 0x2cULL, NULL, NULL, OperandInfo82,0,0 },  // Inst #544 = LBMux
  { 545,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo83,0,0 },  // Inst #545 = LBR
  { 546,	2,	1,	0,	4,	0, 0x3fc00ULL, NULL, ImplicitList1, OperandInfo60,0,0 },  // Inst #546 = LCDBR
  { 547,	2,	1,	0,	4,	0, 0x3fc00ULL, NULL, ImplicitList1, OperandInfo64,0,0 },  // Inst #547 = LCEBR
  { 548,	2,	1,	0,	4,	0, 0x3b800ULL, NULL, ImplicitList1, OperandInfo74,0,0 },  // Inst #548 = LCGFR
  { 549,	2,	1,	0,	4,	0, 0x23c00ULL, NULL, ImplicitList1, OperandInfo75,0,0 },  // Inst #549 = LCGR
  { 550,	2,	1,	0,	2,	0, 0x23c00ULL, NULL, ImplicitList1, OperandInfo83,0,0 },  // Inst #550 = LCR
  { 551,	2,	1,	0,	4,	0, 0x3fc00ULL, NULL, ImplicitList1, OperandInfo92,0,0 },  // Inst #551 = LCXBR
  { 552,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x109ULL, NULL, NULL, OperandInfo59,0,0 },  // Inst #552 = LD
  { 553,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x88ULL, NULL, NULL, OperandInfo59,0,0 },  // Inst #553 = LDEB
  { 554,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo111,0,0 },  // Inst #554 = LDEBR
  { 555,	2,	1,	0,	4,	0|(1<<MCID::Bitcast), 0x0ULL, NULL, NULL, OperandInfo62,0,0 },  // Inst #555 = LDGR
  { 556,	2,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo60,0,0 },  // Inst #556 = LDR
  { 557,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo92,0,0 },  // Inst #557 = LDXBR
  { 558,	4,	1,	0,	6,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x10dULL, NULL, NULL, OperandInfo59,0,0 },  // Inst #558 = LDY
  { 559,	4,	1,	0,	4,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x89ULL, NULL, NULL, OperandInfo63,0,0 },  // Inst #559 = LE
  { 560,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo112,0,0 },  // Inst #560 = LEDBR
  { 561,	2,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo64,0,0 },  // Inst #561 = LER
  { 562,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo92,0,0 },  // Inst #562 = LEXBR
  { 563,	4,	1,	0,	6,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x8dULL, NULL, NULL, OperandInfo63,0,0 },  // Inst #563 = LEY
  { 564,	4,	1,	0,	6,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x8dULL, NULL, NULL, OperandInfo77,0,0 },  // Inst #564 = LFH
  { 565,	4,	1,	0,	6,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x10dULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #565 = LG
  { 566,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2cULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #566 = LGB
  { 567,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #567 = LGBR
  { 568,	2,	1,	0,	4,	0|(1<<MCID::Bitcast), 0x0ULL, NULL, NULL, OperandInfo113,0,0 },  // Inst #568 = LGDR
  { 569,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x8cULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #569 = LGF
  { 570,	2,	1,	0,	6,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #570 = LGFI
  { 571,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo74,0,0 },  // Inst #571 = LGFR
  { 572,	2,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #572 = LGFRL
  { 573,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x4cULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #573 = LGH
  { 574,	2,	1,	0,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #574 = LGHI
  { 575,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #575 = LGHR
  { 576,	2,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #576 = LGHRL
  { 577,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #577 = LGR
  { 578,	2,	1,	0,	6,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #578 = LGRL
  { 579,	4,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x48ULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #579 = LH
  { 580,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x4cULL, NULL, NULL, OperandInfo77,0,0 },  // Inst #580 = LHH
  { 581,	2,	1,	0,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo69,0,0 },  // Inst #581 = LHI
  { 582,	2,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo70,0,0 },  // Inst #582 = LHIMux
  { 583,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad), 0x4cULL, NULL, NULL, OperandInfo82,0,0 },  // Inst #583 = LHMux
  { 584,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo83,0,0 },  // Inst #584 = LHR
  { 585,	2,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo69,0,0 },  // Inst #585 = LHRL
  { 586,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x4cULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #586 = LHY
  { 587,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2cULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #587 = LLC
  { 588,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2cULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #588 = LLCH
  { 589,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad), 0x2cULL, NULL, NULL, OperandInfo82,0,0 },  // Inst #589 = LLCMux
  { 590,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo83,0,0 },  // Inst #590 = LLCR
  { 591,	2,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo114,0,0 },  // Inst #591 = LLCRMux
  { 592,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2cULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #592 = LLGC
  { 593,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #593 = LLGCR
  { 594,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x8cULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #594 = LLGF
  { 595,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo74,0,0 },  // Inst #595 = LLGFR
  { 596,	2,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #596 = LLGFRL
  { 597,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x4cULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #597 = LLGH
  { 598,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #598 = LLGHR
  { 599,	2,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #599 = LLGHRL
  { 600,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x4cULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #600 = LLH
  { 601,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x4cULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #601 = LLHH
  { 602,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad), 0x4cULL, NULL, NULL, OperandInfo82,0,0 },  // Inst #602 = LLHMux
  { 603,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo83,0,0 },  // Inst #603 = LLHR
  { 604,	2,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo69,0,0 },  // Inst #604 = LLHRL
  { 605,	2,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo114,0,0 },  // Inst #605 = LLHRMux
  { 606,	2,	1,	0,	6,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #606 = LLIHF
  { 607,	2,	1,	0,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #607 = LLIHH
  { 608,	2,	1,	0,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #608 = LLIHL
  { 609,	2,	1,	0,	6,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #609 = LLILF
  { 610,	2,	1,	0,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #610 = LLILH
  { 611,	2,	1,	0,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::Rematerializable)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #611 = LLILL
  { 612,	4,	2,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x4ULL, NULL, NULL, OperandInfo115,0,0 },  // Inst #612 = LMG
  { 613,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x8dULL, NULL, NULL, OperandInfo82,0,0 },  // Inst #613 = LMux
  { 614,	2,	1,	0,	4,	0, 0x3fc00ULL, NULL, ImplicitList1, OperandInfo60,0,0 },  // Inst #614 = LNDBR
  { 615,	2,	1,	0,	4,	0, 0x3fc00ULL, NULL, ImplicitList1, OperandInfo64,0,0 },  // Inst #615 = LNEBR
  { 616,	2,	1,	0,	4,	0, 0x3b800ULL, NULL, ImplicitList1, OperandInfo74,0,0 },  // Inst #616 = LNGFR
  { 617,	2,	1,	0,	4,	0, 0x23c00ULL, NULL, ImplicitList1, OperandInfo75,0,0 },  // Inst #617 = LNGR
  { 618,	2,	1,	0,	2,	0, 0x23c00ULL, NULL, ImplicitList1, OperandInfo83,0,0 },  // Inst #618 = LNR
  { 619,	2,	1,	0,	4,	0, 0x3fc00ULL, NULL, ImplicitList1, OperandInfo92,0,0 },  // Inst #619 = LNXBR
  { 620,	6,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x80084ULL, ImplicitList1, NULL, OperandInfo116,0,0 },  // Inst #620 = LOC
  { 621,	6,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x80104ULL, ImplicitList1, NULL, OperandInfo117,0,0 },  // Inst #621 = LOCG
  { 622,	4,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x80000ULL, ImplicitList1, NULL, OperandInfo41,0,0 },  // Inst #622 = LOCGR
  { 623,	4,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x80000ULL, ImplicitList1, NULL, OperandInfo43,0,0 },  // Inst #623 = LOCR
  { 624,	2,	1,	0,	4,	0, 0x3fc00ULL, NULL, ImplicitList1, OperandInfo60,0,0 },  // Inst #624 = LPDBR
  { 625,	2,	1,	0,	4,	0, 0x3fc00ULL, NULL, ImplicitList1, OperandInfo64,0,0 },  // Inst #625 = LPEBR
  { 626,	2,	1,	0,	4,	0, 0x3b800ULL, NULL, ImplicitList1, OperandInfo74,0,0 },  // Inst #626 = LPGFR
  { 627,	2,	1,	0,	4,	0, 0x23c00ULL, NULL, ImplicitList1, OperandInfo75,0,0 },  // Inst #627 = LPGR
  { 628,	2,	1,	0,	2,	0, 0x23c00ULL, NULL, ImplicitList1, OperandInfo83,0,0 },  // Inst #628 = LPR
  { 629,	2,	1,	0,	4,	0, 0x3fc00ULL, NULL, ImplicitList1, OperandInfo92,0,0 },  // Inst #629 = LPXBR
  { 630,	2,	1,	0,	2,	0, 0x0ULL, NULL, NULL, OperandInfo83,0,0 },  // Inst #630 = LR
  { 631,	2,	1,	0,	6,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x0ULL, NULL, NULL, OperandInfo69,0,0 },  // Inst #631 = LRL
  { 632,	2,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, NULL, OperandInfo114,0,0 },  // Inst #632 = LRMux
  { 633,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x8cULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #633 = LRV
  { 634,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x10cULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #634 = LRVG
  { 635,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo75,0,0 },  // Inst #635 = LRVGR
  { 636,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo83,0,0 },  // Inst #636 = LRVR
  { 637,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x3b88cULL, NULL, ImplicitList1, OperandInfo58,0,0 },  // Inst #637 = LT
  { 638,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x3fc00ULL, NULL, ImplicitList1, OperandInfo60,0,0 },  // Inst #638 = LTDBR
  { 639,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x3fc00ULL, NULL, ImplicitList1, OperandInfo60,0,0 },  // Inst #639 = LTDBRCompare
  { 640,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x3fc00ULL, NULL, ImplicitList1, OperandInfo64,0,0 },  // Inst #640 = LTEBR
  { 641,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x3fc00ULL, NULL, ImplicitList1, OperandInfo64,0,0 },  // Inst #641 = LTEBRCompare
  { 642,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x3b90cULL, NULL, ImplicitList1, OperandInfo13,0,0 },  // Inst #642 = LTG
  { 643,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x3b88cULL, NULL, ImplicitList1, OperandInfo13,0,0 },  // Inst #643 = LTGF
  { 644,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x3b800ULL, NULL, ImplicitList1, OperandInfo75,0,0 },  // Inst #644 = LTGFR
  { 645,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x3b800ULL, NULL, ImplicitList1, OperandInfo75,0,0 },  // Inst #645 = LTGR
  { 646,	2,	1,	0,	2,	0|(1<<MCID::UnmodeledSideEffects), 0x3b800ULL, NULL, ImplicitList1, OperandInfo83,0,0 },  // Inst #646 = LTR
  { 647,	2,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x3fc00ULL, NULL, ImplicitList1, OperandInfo92,0,0 },  // Inst #647 = LTXBR
  { 648,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x3fc00ULL, NULL, ImplicitList1, OperandInfo92,0,0 },  // Inst #648 = LTXBRCompare
  { 649,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x1dULL, NULL, NULL, OperandInfo118,0,0 },  // Inst #649 = LX
  { 650,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x108ULL, NULL, NULL, OperandInfo118,0,0 },  // Inst #650 = LXDB
  { 651,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo119,0,0 },  // Inst #651 = LXDBR
  { 652,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x88ULL, NULL, NULL, OperandInfo118,0,0 },  // Inst #652 = LXEB
  { 653,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo120,0,0 },  // Inst #653 = LXEBR
  { 654,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo92,0,0 },  // Inst #654 = LXR
  { 655,	4,	1,	0,	6,	0|(1<<MCID::FoldableAsLoad)|(1<<MCID::MayLoad), 0x8dULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #655 = LY
  { 656,	1,	1,	0,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo121,0,0 },  // Inst #656 = LZDR
  { 657,	1,	1,	0,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo122,0,0 },  // Inst #657 = LZER
  { 658,	1,	1,	0,	4,	0|(1<<MCID::MoveImm)|(1<<MCID::CheapAsAMove), 0x0ULL, NULL, NULL, OperandInfo123,0,0 },  // Inst #658 = LZXR
  { 659,	6,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x108ULL, NULL, NULL, OperandInfo124,0,0 },  // Inst #659 = MADB
  { 660,	4,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo125,0,0 },  // Inst #660 = MADBR
  { 661,	6,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x88ULL, NULL, NULL, OperandInfo126,0,0 },  // Inst #661 = MAEB
  { 662,	4,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo127,0,0 },  // Inst #662 = MAEBR
  { 663,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x108ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #663 = MDB
  { 664,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x0ULL, NULL, NULL, OperandInfo12,0,0 },  // Inst #664 = MDBR
  { 665,	5,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x88ULL, NULL, NULL, OperandInfo11,0,0 },  // Inst #665 = MDEB
  { 666,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo128,0,0 },  // Inst #666 = MDEBR
  { 667,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x88ULL, NULL, NULL, OperandInfo14,0,0 },  // Inst #667 = MEEB
  { 668,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x0ULL, NULL, NULL, OperandInfo15,0,0 },  // Inst #668 = MEEBR
  { 669,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo20,0,0 },  // Inst #669 = MGHI
  { 670,	5,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x48ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #670 = MH
  { 671,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo17,0,0 },  // Inst #671 = MHI
  { 672,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x4cULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #672 = MHY
  { 673,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x10cULL, NULL, NULL, OperandInfo100,0,0 },  // Inst #673 = MLG
  { 674,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo101,0,0 },  // Inst #674 = MLGR
  { 675,	5,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x88ULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #675 = MS
  { 676,	6,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x108ULL, NULL, NULL, OperandInfo124,0,0 },  // Inst #676 = MSDB
  { 677,	4,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo125,0,0 },  // Inst #677 = MSDBR
  { 678,	6,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x88ULL, NULL, NULL, OperandInfo126,0,0 },  // Inst #678 = MSEB
  { 679,	4,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo127,0,0 },  // Inst #679 = MSEBR
  { 680,	3,	1,	0,	6,	0, 0x0ULL, NULL, NULL, OperandInfo17,0,0 },  // Inst #680 = MSFI
  { 681,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x10cULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #681 = MSG
  { 682,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x8cULL, NULL, NULL, OperandInfo19,0,0 },  // Inst #682 = MSGF
  { 683,	3,	1,	0,	6,	0, 0x0ULL, NULL, NULL, OperandInfo20,0,0 },  // Inst #683 = MSGFI
  { 684,	3,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo21,0,0 },  // Inst #684 = MSGFR
  { 685,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x0ULL, NULL, NULL, OperandInfo23,0,0 },  // Inst #685 = MSGR
  { 686,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x0ULL, NULL, NULL, OperandInfo29,0,0 },  // Inst #686 = MSR
  { 687,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x8cULL, NULL, NULL, OperandInfo10,0,0 },  // Inst #687 = MSY
  { 688,	5,	0,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo79,0,0 },  // Inst #688 = MVC
  { 689,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo80,0,0 },  // Inst #689 = MVCLoop
  { 690,	5,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, NULL, OperandInfo81,0,0 },  // Inst #690 = MVCSequence
  { 691,	3,	0,	0,	6,	0|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #691 = MVGHI
  { 692,	3,	0,	0,	6,	0|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #692 = MVHHI
  { 693,	3,	0,	0,	6,	0|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #693 = MVHI
  { 694,	3,	0,	0,	4,	0|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #694 = MVI
  { 695,	3,	0,	0,	6,	0|(1<<MCID::MayStore), 0x4ULL, NULL, NULL, OperandInfo25,0,0 },  // Inst #695 = MVIY
  { 696,	4,	2,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList2, ImplicitList1, OperandInfo84,0,0 },  // Inst #696 = MVST
  { 697,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList2, ImplicitList1, OperandInfo85,0,0 },  // Inst #697 = MVSTLoop
  { 698,	3,	1,	0,	4,	0|(1<<MCID::Commutable), 0x0ULL, NULL, NULL, OperandInfo38,0,0 },  // Inst #698 = MXBR
  { 699,	5,	1,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x108ULL, NULL, NULL, OperandInfo129,0,0 },  // Inst #699 = MXDB
  { 700,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo130,0,0 },  // Inst #700 = MXDBR
  { 701,	5,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x23088ULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #701 = N
  { 702,	5,	0,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo79,0,0 },  // Inst #702 = NC
  { 703,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, ImplicitList1, OperandInfo80,0,0 },  // Inst #703 = NCLoop
  { 704,	5,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, ImplicitList1, OperandInfo81,0,0 },  // Inst #704 = NCSequence
  { 705,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2310cULL, NULL, ImplicitList1, OperandInfo19,0,0 },  // Inst #705 = NG
  { 706,	3,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr)|(1<<MCID::Commutable), 0x23000ULL, NULL, ImplicitList1, OperandInfo23,0,0 },  // Inst #706 = NGR
  { 707,	3,	1,	0,	4,	0|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x23000ULL, NULL, ImplicitList1, OperandInfo24,0,0 },  // Inst #707 = NGRK
  { 708,	3,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x0ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #708 = NI
  { 709,	3,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::ConvertibleTo3Addr), 0x23000ULL, NULL, ImplicitList1, OperandInfo18,0,0 },  // Inst #709 = NIFMux
  { 710,	3,	1,	0,	6,	0|(1<<MCID::ConvertibleTo3Addr), 0x23000ULL, NULL, ImplicitList1, OperandInfo28,0,0 },  // Inst #710 = NIHF
  { 711,	3,	1,	0,	6,	0|(1<<MCID::Pseudo)|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #711 = NIHF64
  { 712,	3,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo28,0,0 },  // Inst #712 = NIHH
  { 713,	3,	1,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #713 = NIHH64
  { 714,	3,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo28,0,0 },  // Inst #714 = NIHL
  { 715,	3,	1,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #715 = NIHL64
  { 716,	3,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo18,0,0 },  // Inst #716 = NIHMux
  { 717,	3,	1,	0,	6,	0|(1<<MCID::ConvertibleTo3Addr), 0x23000ULL, NULL, ImplicitList1, OperandInfo17,0,0 },  // Inst #717 = NILF
  { 718,	3,	1,	0,	6,	0|(1<<MCID::Pseudo)|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #718 = NILF64
  { 719,	3,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo17,0,0 },  // Inst #719 = NILH
  { 720,	3,	1,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #720 = NILH64
  { 721,	3,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo17,0,0 },  // Inst #721 = NILL
  { 722,	3,	1,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #722 = NILL64
  { 723,	3,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo18,0,0 },  // Inst #723 = NILMux
  { 724,	3,	0,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x4ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #724 = NIY
  { 725,	3,	1,	0,	2,	0|(1<<MCID::ConvertibleTo3Addr)|(1<<MCID::Commutable), 0x23000ULL, NULL, ImplicitList1, OperandInfo29,0,0 },  // Inst #725 = NR
  { 726,	3,	1,	0,	4,	0|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x23000ULL, NULL, ImplicitList1, OperandInfo30,0,0 },  // Inst #726 = NRK
  { 727,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2308cULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #727 = NY
  { 728,	5,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x23088ULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #728 = O
  { 729,	5,	0,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo79,0,0 },  // Inst #729 = OC
  { 730,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, ImplicitList1, OperandInfo80,0,0 },  // Inst #730 = OCLoop
  { 731,	5,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, ImplicitList1, OperandInfo81,0,0 },  // Inst #731 = OCSequence
  { 732,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2310cULL, NULL, ImplicitList1, OperandInfo19,0,0 },  // Inst #732 = OG
  { 733,	3,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr)|(1<<MCID::Commutable), 0x23000ULL, NULL, ImplicitList1, OperandInfo23,0,0 },  // Inst #733 = OGR
  { 734,	3,	1,	0,	4,	0|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x23000ULL, NULL, ImplicitList1, OperandInfo24,0,0 },  // Inst #734 = OGRK
  { 735,	3,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x0ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #735 = OI
  { 736,	3,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x23000ULL, NULL, ImplicitList1, OperandInfo18,0,0 },  // Inst #736 = OIFMux
  { 737,	3,	1,	0,	6,	0, 0x23000ULL, NULL, ImplicitList1, OperandInfo28,0,0 },  // Inst #737 = OIHF
  { 738,	3,	1,	0,	6,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #738 = OIHF64
  { 739,	3,	1,	0,	4,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo28,0,0 },  // Inst #739 = OIHH
  { 740,	3,	1,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #740 = OIHH64
  { 741,	3,	1,	0,	4,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo28,0,0 },  // Inst #741 = OIHL
  { 742,	3,	1,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #742 = OIHL64
  { 743,	3,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, ImplicitList1, OperandInfo18,0,0 },  // Inst #743 = OIHMux
  { 744,	3,	1,	0,	6,	0, 0x23000ULL, NULL, ImplicitList1, OperandInfo17,0,0 },  // Inst #744 = OILF
  { 745,	3,	1,	0,	6,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #745 = OILF64
  { 746,	3,	1,	0,	4,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo17,0,0 },  // Inst #746 = OILH
  { 747,	3,	1,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #747 = OILH64
  { 748,	3,	1,	0,	4,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo17,0,0 },  // Inst #748 = OILL
  { 749,	3,	1,	0,	4,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #749 = OILL64
  { 750,	3,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, ImplicitList1, OperandInfo18,0,0 },  // Inst #750 = OILMux
  { 751,	3,	0,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x4ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #751 = OIY
  { 752,	3,	1,	0,	2,	0|(1<<MCID::ConvertibleTo3Addr)|(1<<MCID::Commutable), 0x23000ULL, NULL, ImplicitList1, OperandInfo29,0,0 },  // Inst #752 = OR
  { 753,	3,	1,	0,	4,	0|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x23000ULL, NULL, ImplicitList1, OperandInfo30,0,0 },  // Inst #753 = ORK
  { 754,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2308cULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #754 = OY
  { 755,	4,	0,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0xcULL, NULL, NULL, OperandInfo131,0,0 },  // Inst #755 = PFD
  { 756,	2,	0,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo7,0,0 },  // Inst #756 = PFDRL
  { 757,	6,	1,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x3b800ULL, NULL, ImplicitList1, OperandInfo132,0,0 },  // Inst #757 = RISBG
  { 758,	6,	1,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo133,0,0 },  // Inst #758 = RISBG32
  { 759,	6,	1,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo134,0,0 },  // Inst #759 = RISBHG
  { 760,	6,	1,	0,	6,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo135,0,0 },  // Inst #760 = RISBHH
  { 761,	6,	1,	0,	6,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo136,0,0 },  // Inst #761 = RISBHL
  { 762,	6,	1,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo137,0,0 },  // Inst #762 = RISBLG
  { 763,	6,	1,	0,	6,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo138,0,0 },  // Inst #763 = RISBLH
  { 764,	6,	1,	0,	6,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo133,0,0 },  // Inst #764 = RISBLL
  { 765,	6,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo139,0,0 },  // Inst #765 = RISBMux
  { 766,	4,	1,	0,	6,	0, 0x4ULL, NULL, NULL, OperandInfo140,0,0 },  // Inst #766 = RLL
  { 767,	4,	1,	0,	6,	0, 0x4ULL, NULL, NULL, OperandInfo141,0,0 },  // Inst #767 = RLLG
  { 768,	6,	1,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo132,0,0 },  // Inst #768 = RNSBG
  { 769,	6,	1,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo132,0,0 },  // Inst #769 = ROSBG
  { 770,	6,	1,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo132,0,0 },  // Inst #770 = RXSBG
  { 771,	0,	0,	0,	2,	0|(1<<MCID::Pseudo)|(1<<MCID::Return)|(1<<MCID::Barrier)|(1<<MCID::Terminator), 0x0ULL, NULL, NULL, 0,0,0 },  // Inst #771 = Return
  { 772,	5,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x23c88ULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #772 = S
  { 773,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x3fd08ULL, NULL, ImplicitList1, OperandInfo11,0,0 },  // Inst #773 = SDB
  { 774,	3,	1,	0,	4,	0, 0x3fc00ULL, NULL, ImplicitList1, OperandInfo12,0,0 },  // Inst #774 = SDBR
  { 775,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x3fc88ULL, NULL, ImplicitList1, OperandInfo14,0,0 },  // Inst #775 = SEB
  { 776,	3,	1,	0,	4,	0, 0x3fc00ULL, NULL, ImplicitList1, OperandInfo15,0,0 },  // Inst #776 = SEBR
  { 777,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x23d0cULL, NULL, ImplicitList1, OperandInfo19,0,0 },  // Inst #777 = SG
  { 778,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x23c8cULL, NULL, ImplicitList1, OperandInfo19,0,0 },  // Inst #778 = SGF
  { 779,	3,	1,	0,	4,	0, 0x23c00ULL, NULL, ImplicitList1, OperandInfo21,0,0 },  // Inst #779 = SGFR
  { 780,	3,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr), 0x23c00ULL, NULL, ImplicitList1, OperandInfo23,0,0 },  // Inst #780 = SGR
  { 781,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x23c00ULL, NULL, ImplicitList1, OperandInfo24,0,0 },  // Inst #781 = SGRK
  { 782,	5,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x23c48ULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #782 = SH
  { 783,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x23c4cULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #783 = SHY
  { 784,	5,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x88ULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #784 = SL
  { 785,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x8cULL, ImplicitList1, ImplicitList1, OperandInfo10,0,0 },  // Inst #785 = SLB
  { 786,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x10cULL, ImplicitList1, ImplicitList1, OperandInfo19,0,0 },  // Inst #786 = SLBG
  { 787,	3,	1,	0,	4,	0, 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo29,0,0 },  // Inst #787 = SLBR
  { 788,	3,	1,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo17,0,0 },  // Inst #788 = SLFI
  { 789,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x10cULL, NULL, ImplicitList1, OperandInfo19,0,0 },  // Inst #789 = SLG
  { 790,	3,	1,	0,	4,	0, 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo23,0,0 },  // Inst #790 = SLGBR
  { 791,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x8cULL, NULL, ImplicitList1, OperandInfo19,0,0 },  // Inst #791 = SLGF
  { 792,	3,	1,	0,	6,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #792 = SLGFI
  { 793,	3,	1,	0,	4,	0, 0x0ULL, NULL, ImplicitList1, OperandInfo21,0,0 },  // Inst #793 = SLGFR
  { 794,	3,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo23,0,0 },  // Inst #794 = SLGR
  { 795,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo24,0,0 },  // Inst #795 = SLGRK
  { 796,	4,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, NULL, OperandInfo142,0,0 },  // Inst #796 = SLL
  { 797,	4,	1,	0,	6,	0, 0x4ULL, NULL, NULL, OperandInfo141,0,0 },  // Inst #797 = SLLG
  { 798,	4,	1,	0,	6,	0, 0x4ULL, NULL, NULL, OperandInfo140,0,0 },  // Inst #798 = SLLK
  { 799,	3,	1,	0,	2,	0|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, ImplicitList1, OperandInfo29,0,0 },  // Inst #799 = SLR
  { 800,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo30,0,0 },  // Inst #800 = SLRK
  { 801,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x8cULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #801 = SLY
  { 802,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x108ULL, NULL, NULL, OperandInfo59,0,0 },  // Inst #802 = SQDB
  { 803,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo60,0,0 },  // Inst #803 = SQDBR
  { 804,	4,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x88ULL, NULL, NULL, OperandInfo63,0,0 },  // Inst #804 = SQEB
  { 805,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo64,0,0 },  // Inst #805 = SQEBR
  { 806,	2,	1,	0,	4,	0, 0x0ULL, NULL, NULL, OperandInfo92,0,0 },  // Inst #806 = SQXBR
  { 807,	3,	1,	0,	2,	0|(1<<MCID::ConvertibleTo3Addr), 0x23c00ULL, NULL, ImplicitList1, OperandInfo29,0,0 },  // Inst #807 = SR
  { 808,	4,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr), 0x3b800ULL, NULL, ImplicitList1, OperandInfo142,0,0 },  // Inst #808 = SRA
  { 809,	4,	1,	0,	6,	0, 0x3b804ULL, NULL, ImplicitList1, OperandInfo141,0,0 },  // Inst #809 = SRAG
  { 810,	4,	1,	0,	6,	0|(1<<MCID::UnmodeledSideEffects), 0x3b804ULL, NULL, ImplicitList1, OperandInfo140,0,0 },  // Inst #810 = SRAK
  { 811,	3,	1,	0,	4,	0|(1<<MCID::UnmodeledSideEffects), 0x23c00ULL, NULL, ImplicitList1, OperandInfo30,0,0 },  // Inst #811 = SRK
  { 812,	4,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr), 0x0ULL, NULL, NULL, OperandInfo142,0,0 },  // Inst #812 = SRL
  { 813,	4,	1,	0,	6,	0, 0x4ULL, NULL, NULL, OperandInfo141,0,0 },  // Inst #813 = SRLG
  { 814,	4,	1,	0,	6,	0, 0x4ULL, NULL, NULL, OperandInfo140,0,0 },  // Inst #814 = SRLK
  { 815,	4,	2,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList2, ImplicitList1, OperandInfo84,0,0 },  // Inst #815 = SRST
  { 816,	4,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList2, ImplicitList1, OperandInfo85,0,0 },  // Inst #816 = SRSTLoop
  { 817,	4,	0,	0,	4,	0|(1<<MCID::MayStore), 0x8aULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #817 = ST
  { 818,	4,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayStore), 0x1eULL, NULL, NULL, OperandInfo110,0,0 },  // Inst #818 = ST128
  { 819,	4,	0,	0,	4,	0|(1<<MCID::MayStore), 0x28ULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #819 = STC
  { 820,	4,	0,	0,	6,	0|(1<<MCID::MayStore), 0x2cULL, NULL, NULL, OperandInfo77,0,0 },  // Inst #820 = STCH
  { 821,	4,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayStore), 0x2cULL, NULL, NULL, OperandInfo82,0,0 },  // Inst #821 = STCMux
  { 822,	4,	0,	0,	6,	0|(1<<MCID::MayStore), 0x2cULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #822 = STCY
  { 823,	4,	0,	0,	4,	0|(1<<MCID::MayStore), 0x10aULL, NULL, NULL, OperandInfo59,0,0 },  // Inst #823 = STD
  { 824,	4,	0,	0,	6,	0|(1<<MCID::MayStore), 0x10eULL, NULL, NULL, OperandInfo59,0,0 },  // Inst #824 = STDY
  { 825,	4,	0,	0,	4,	0|(1<<MCID::MayStore), 0x8aULL, NULL, NULL, OperandInfo63,0,0 },  // Inst #825 = STE
  { 826,	4,	0,	0,	6,	0|(1<<MCID::MayStore), 0x8eULL, NULL, NULL, OperandInfo63,0,0 },  // Inst #826 = STEY
  { 827,	4,	0,	0,	6,	0|(1<<MCID::MayStore), 0x8eULL, NULL, NULL, OperandInfo77,0,0 },  // Inst #827 = STFH
  { 828,	4,	0,	0,	6,	0|(1<<MCID::MayStore), 0x10eULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #828 = STG
  { 829,	2,	0,	0,	6,	0|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo56,0,0 },  // Inst #829 = STGRL
  { 830,	4,	0,	0,	4,	0|(1<<MCID::MayStore), 0x48ULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #830 = STH
  { 831,	4,	0,	0,	6,	0|(1<<MCID::MayStore), 0x4cULL, NULL, NULL, OperandInfo77,0,0 },  // Inst #831 = STHH
  { 832,	4,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayStore), 0x2cULL, NULL, NULL, OperandInfo82,0,0 },  // Inst #832 = STHMux
  { 833,	2,	0,	0,	6,	0|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo69,0,0 },  // Inst #833 = STHRL
  { 834,	4,	0,	0,	6,	0|(1<<MCID::MayStore), 0x4cULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #834 = STHY
  { 835,	4,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x4ULL, NULL, NULL, OperandInfo115,0,0 },  // Inst #835 = STMG
  { 836,	4,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayStore), 0x8eULL, NULL, NULL, OperandInfo82,0,0 },  // Inst #836 = STMux
  { 837,	5,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x80084ULL, ImplicitList1, NULL, OperandInfo143,0,0 },  // Inst #837 = STOC
  { 838,	5,	0,	0,	6,	0|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x80104ULL, ImplicitList1, NULL, OperandInfo144,0,0 },  // Inst #838 = STOCG
  { 839,	2,	0,	0,	6,	0|(1<<MCID::MayStore), 0x0ULL, NULL, NULL, OperandInfo69,0,0 },  // Inst #839 = STRL
  { 840,	4,	0,	0,	6,	0|(1<<MCID::MayStore), 0x8cULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #840 = STRV
  { 841,	4,	0,	0,	6,	0|(1<<MCID::MayStore), 0x10cULL, NULL, NULL, OperandInfo13,0,0 },  // Inst #841 = STRVG
  { 842,	4,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayStore), 0x1eULL, NULL, NULL, OperandInfo118,0,0 },  // Inst #842 = STX
  { 843,	4,	0,	0,	6,	0|(1<<MCID::MayStore), 0x8eULL, NULL, NULL, OperandInfo58,0,0 },  // Inst #843 = STY
  { 844,	3,	1,	0,	4,	0, 0x3fc00ULL, NULL, ImplicitList1, OperandInfo38,0,0 },  // Inst #844 = SXBR
  { 845,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x23c8cULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #845 = SY
  { 846,	5,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo145,0,0 },  // Inst #846 = Select32
  { 847,	5,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo146,0,0 },  // Inst #847 = Select32Mux
  { 848,	5,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo147,0,0 },  // Inst #848 = Select64
  { 849,	5,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo148,0,0 },  // Inst #849 = SelectF128
  { 850,	5,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo149,0,0 },  // Inst #850 = SelectF32
  { 851,	5,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList1, ImplicitList1, OperandInfo150,0,0 },  // Inst #851 = SelectF64
  { 852,	3,	0,	0,	4,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x0ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #852 = TM
  { 853,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x0ULL, NULL, ImplicitList1, OperandInfo78,0,0 },  // Inst #853 = TMHH
  { 854,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::Compare), 0x0ULL, NULL, ImplicitList1, OperandInfo56,0,0 },  // Inst #854 = TMHH64
  { 855,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x0ULL, NULL, ImplicitList1, OperandInfo78,0,0 },  // Inst #855 = TMHL
  { 856,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::Compare), 0x0ULL, NULL, ImplicitList1, OperandInfo56,0,0 },  // Inst #856 = TMHL64
  { 857,	2,	0,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, ImplicitList1, OperandInfo70,0,0 },  // Inst #857 = TMHMux
  { 858,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x0ULL, NULL, ImplicitList1, OperandInfo69,0,0 },  // Inst #858 = TMLH
  { 859,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::Compare), 0x0ULL, NULL, ImplicitList1, OperandInfo56,0,0 },  // Inst #859 = TMLH64
  { 860,	2,	0,	0,	4,	0|(1<<MCID::Compare), 0x0ULL, NULL, ImplicitList1, OperandInfo69,0,0 },  // Inst #860 = TMLL
  { 861,	2,	0,	0,	4,	0|(1<<MCID::Pseudo)|(1<<MCID::Compare), 0x0ULL, NULL, ImplicitList1, OperandInfo56,0,0 },  // Inst #861 = TMLL64
  { 862,	2,	0,	0,	0,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, ImplicitList1, OperandInfo70,0,0 },  // Inst #862 = TMLMux
  { 863,	3,	0,	0,	6,	0|(1<<MCID::Compare)|(1<<MCID::MayLoad), 0x4ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #863 = TMY
  { 864,	5,	1,	0,	4,	0|(1<<MCID::MayLoad), 0x23088ULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #864 = X
  { 865,	5,	0,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, ImplicitList1, OperandInfo79,0,0 },  // Inst #865 = XC
  { 866,	6,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, ImplicitList1, OperandInfo80,0,0 },  // Inst #866 = XCLoop
  { 867,	5,	0,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::MayLoad)|(1<<MCID::MayStore)|(1<<MCID::UsesCustomInserter), 0x0ULL, NULL, ImplicitList1, OperandInfo81,0,0 },  // Inst #867 = XCSequence
  { 868,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2310cULL, NULL, ImplicitList1, OperandInfo19,0,0 },  // Inst #868 = XG
  { 869,	3,	1,	0,	4,	0|(1<<MCID::ConvertibleTo3Addr)|(1<<MCID::Commutable), 0x23000ULL, NULL, ImplicitList1, OperandInfo23,0,0 },  // Inst #869 = XGR
  { 870,	3,	1,	0,	4,	0|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x23000ULL, NULL, ImplicitList1, OperandInfo24,0,0 },  // Inst #870 = XGRK
  { 871,	3,	0,	0,	4,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x0ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #871 = XI
  { 872,	3,	1,	0,	0,	0|(1<<MCID::Pseudo), 0x23000ULL, NULL, ImplicitList1, OperandInfo18,0,0 },  // Inst #872 = XIFMux
  { 873,	3,	1,	0,	6,	0, 0x23000ULL, NULL, ImplicitList1, OperandInfo28,0,0 },  // Inst #873 = XIHF
  { 874,	3,	1,	0,	6,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #874 = XIHF64
  { 875,	3,	1,	0,	6,	0, 0x23000ULL, NULL, ImplicitList1, OperandInfo17,0,0 },  // Inst #875 = XILF
  { 876,	3,	1,	0,	6,	0|(1<<MCID::Pseudo), 0x0ULL, NULL, ImplicitList1, OperandInfo20,0,0 },  // Inst #876 = XILF64
  { 877,	3,	0,	0,	6,	0|(1<<MCID::MayLoad)|(1<<MCID::MayStore), 0x4ULL, NULL, ImplicitList1, OperandInfo25,0,0 },  // Inst #877 = XIY
  { 878,	3,	1,	0,	2,	0|(1<<MCID::ConvertibleTo3Addr)|(1<<MCID::Commutable), 0x23000ULL, NULL, ImplicitList1, OperandInfo29,0,0 },  // Inst #878 = XR
  { 879,	3,	1,	0,	4,	0|(1<<MCID::Commutable)|(1<<MCID::UnmodeledSideEffects), 0x23000ULL, NULL, ImplicitList1, OperandInfo30,0,0 },  // Inst #879 = XRK
  { 880,	5,	1,	0,	6,	0|(1<<MCID::MayLoad), 0x2308cULL, NULL, ImplicitList1, OperandInfo10,0,0 },  // Inst #880 = XY
  { 881,	2,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UsesCustomInserter)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo151,0,0 },  // Inst #881 = ZEXT128_32
  { 882,	2,	1,	0,	0,	0|(1<<MCID::Pseudo)|(1<<MCID::UsesCustomInserter)|(1<<MCID::UnmodeledSideEffects), 0x0ULL, NULL, NULL, OperandInfo16,0,0 },  // Inst #882 = ZEXT128_64
};

extern const char SystemZInstrNameData[] = {
  /* 0 */ 'I', 'C', '3', '2', 0,
  /* 5 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', 'F', '3', '2', 0,
  /* 18 */ 'S', 'e', 'l', 'e', 'c', 't', 'F', '3', '2', 0,
  /* 28 */ 'R', 'I', 'S', 'B', 'G', '3', '2', 0,
  /* 36 */ 'Z', 'E', 'X', 'T', '1', '2', '8', '_', '3', '2', 0,
  /* 47 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'U', 'M', 'I', 'N', '_', '3', '2', 0,
  /* 67 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'M', 'I', 'N', '_', '3', '2', 0,
  /* 86 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', '3', '2', 0,
  /* 101 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'U', 'M', 'A', 'X', '_', '3', '2', 0,
  /* 121 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'M', 'A', 'X', '_', '3', '2', 0,
  /* 140 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', '3', '2', 0,
  /* 152 */ 'S', 'e', 'l', 'e', 'c', 't', '3', '2', 0,
  /* 161 */ 'I', 'I', 'H', 'F', '6', '4', 0,
  /* 168 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'H', 'F', '6', '4', 0,
  /* 187 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'I', 'H', 'F', '6', '4', 0,
  /* 206 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'I', 'H', 'F', '6', '4', 0,
  /* 225 */ 'I', 'I', 'L', 'F', '6', '4', 0,
  /* 232 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'L', 'F', '6', '4', 0,
  /* 251 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'I', 'L', 'F', '6', '4', 0,
  /* 270 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'I', 'L', 'F', '6', '4', 0,
  /* 289 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', 'F', '6', '4', 0,
  /* 302 */ 'S', 'e', 'l', 'e', 'c', 't', 'F', '6', '4', 0,
  /* 312 */ 'I', 'I', 'H', 'H', '6', '4', 0,
  /* 319 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'H', 'H', '6', '4', 0,
  /* 338 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'I', 'H', 'H', '6', '4', 0,
  /* 357 */ 'T', 'M', 'H', 'H', '6', '4', 0,
  /* 364 */ 'I', 'I', 'L', 'H', '6', '4', 0,
  /* 371 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'L', 'H', '6', '4', 0,
  /* 390 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'I', 'L', 'H', '6', '4', 0,
  /* 409 */ 'T', 'M', 'L', 'H', '6', '4', 0,
  /* 416 */ 'I', 'I', 'H', 'L', '6', '4', 0,
  /* 423 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'H', 'L', '6', '4', 0,
  /* 442 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'I', 'H', 'L', '6', '4', 0,
  /* 461 */ 'T', 'M', 'H', 'L', '6', '4', 0,
  /* 468 */ 'I', 'I', 'L', 'L', '6', '4', 0,
  /* 475 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'L', 'L', '6', '4', 0,
  /* 494 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'I', 'L', 'L', '6', '4', 0,
  /* 513 */ 'T', 'M', 'L', 'L', '6', '4', 0,
  /* 520 */ 'A', 'E', 'X', 'T', '1', '2', '8', '_', '6', '4', 0,
  /* 531 */ 'Z', 'E', 'X', 'T', '1', '2', '8', '_', '6', '4', 0,
  /* 542 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'U', 'M', 'I', 'N', '_', '6', '4', 0,
  /* 562 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'M', 'I', 'N', '_', '6', '4', 0,
  /* 581 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', '6', '4', 0,
  /* 596 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'U', 'M', 'A', 'X', '_', '6', '4', 0,
  /* 616 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'M', 'A', 'X', '_', '6', '4', 0,
  /* 635 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', '6', '4', 0,
  /* 647 */ 'S', 'e', 'l', 'e', 'c', 't', '6', '4', 0,
  /* 656 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', '1', '6', 0,
  /* 668 */ 'S', 'e', 'l', 'e', 'c', 't', 'F', '1', '2', '8', 0,
  /* 679 */ 'L', '1', '2', '8', 0,
  /* 684 */ 'S', 'T', '1', '2', '8', 0,
  /* 690 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', '8', 0,
  /* 701 */ 'L', 'A', 0,
  /* 704 */ 'F', 'I', 'D', 'B', 'R', 'A', 0,
  /* 711 */ 'F', 'I', 'E', 'B', 'R', 'A', 0,
  /* 718 */ 'F', 'I', 'X', 'B', 'R', 'A', 0,
  /* 725 */ 'S', 'R', 'A', 0,
  /* 729 */ 'M', 'A', 'D', 'B', 0,
  /* 734 */ 'C', 'D', 'B', 0,
  /* 738 */ 'D', 'D', 'B', 0,
  /* 742 */ 'M', 'D', 'B', 0,
  /* 746 */ 'S', 'Q', 'D', 'B', 0,
  /* 751 */ 'M', 'S', 'D', 'B', 0,
  /* 756 */ 'L', 'X', 'D', 'B', 0,
  /* 761 */ 'M', 'X', 'D', 'B', 0,
  /* 766 */ 'M', 'A', 'E', 'B', 0,
  /* 771 */ 'C', 'E', 'B', 0,
  /* 775 */ 'L', 'D', 'E', 'B', 0,
  /* 780 */ 'M', 'D', 'E', 'B', 0,
  /* 785 */ 'M', 'E', 'E', 'B', 0,
  /* 790 */ 'S', 'Q', 'E', 'B', 0,
  /* 795 */ 'M', 'S', 'E', 'B', 0,
  /* 800 */ 'L', 'X', 'E', 'B', 0,
  /* 805 */ 'L', 'G', 'B', 0,
  /* 809 */ 'S', 'L', 'B', 0,
  /* 813 */ 'L', 'L', 'G', 'C', 0,
  /* 818 */ 'I', 'C', 0,
  /* 821 */ 'A', 'L', 'C', 0,
  /* 825 */ 'C', 'L', 'C', 0,
  /* 829 */ 'L', 'L', 'C', 0,
  /* 833 */ 'N', 'C', 0,
  /* 836 */ 'A', 's', 'm', 'N', 'H', 'E', 'L', 'O', 'C', 0,
  /* 846 */ 'A', 's', 'm', 'H', 'E', 'L', 'O', 'C', 0,
  /* 855 */ 'A', 's', 'm', 'N', 'L', 'E', 'L', 'O', 'C', 0,
  /* 865 */ 'A', 's', 'm', 'L', 'E', 'L', 'O', 'C', 0,
  /* 874 */ 'A', 's', 'm', 'N', 'E', 'L', 'O', 'C', 0,
  /* 883 */ 'A', 's', 'm', 'E', 'L', 'O', 'C', 0,
  /* 891 */ 'A', 's', 'm', 'N', 'L', 'H', 'L', 'O', 'C', 0,
  /* 901 */ 'A', 's', 'm', 'L', 'H', 'L', 'O', 'C', 0,
  /* 910 */ 'A', 's', 'm', 'N', 'H', 'L', 'O', 'C', 0,
  /* 919 */ 'A', 's', 'm', 'H', 'L', 'O', 'C', 0,
  /* 927 */ 'A', 'D', 'J', 'D', 'Y', 'N', 'A', 'L', 'L', 'O', 'C', 0,
  /* 939 */ 'A', 's', 'm', 'N', 'L', 'L', 'O', 'C', 0,
  /* 948 */ 'A', 's', 'm', 'L', 'L', 'O', 'C', 0,
  /* 956 */ 'A', 's', 'm', 'N', 'O', 'L', 'O', 'C', 0,
  /* 965 */ 'A', 's', 'm', 'O', 'L', 'O', 'C', 0,
  /* 973 */ 'A', 's', 'm', 'L', 'O', 'C', 0,
  /* 980 */ 'A', 's', 'm', 'N', 'H', 'E', 'S', 'T', 'O', 'C', 0,
  /* 991 */ 'A', 's', 'm', 'H', 'E', 'S', 'T', 'O', 'C', 0,
  /* 1001 */ 'A', 's', 'm', 'N', 'L', 'E', 'S', 'T', 'O', 'C', 0,
  /* 1012 */ 'A', 's', 'm', 'L', 'E', 'S', 'T', 'O', 'C', 0,
  /* 1022 */ 'A', 's', 'm', 'N', 'E', 'S', 'T', 'O', 'C', 0,
  /* 1032 */ 'A', 's', 'm', 'E', 'S', 'T', 'O', 'C', 0,
  /* 1041 */ 'A', 's', 'm', 'N', 'L', 'H', 'S', 'T', 'O', 'C', 0,
  /* 1052 */ 'A', 's', 'm', 'L', 'H', 'S', 'T', 'O', 'C', 0,
  /* 1062 */ 'A', 's', 'm', 'N', 'H', 'S', 'T', 'O', 'C', 0,
  /* 1072 */ 'A', 's', 'm', 'H', 'S', 'T', 'O', 'C', 0,
  /* 1081 */ 'A', 's', 'm', 'N', 'L', 'S', 'T', 'O', 'C', 0,
  /* 1091 */ 'A', 's', 'm', 'L', 'S', 'T', 'O', 'C', 0,
  /* 1100 */ 'A', 's', 'm', 'N', 'O', 'S', 'T', 'O', 'C', 0,
  /* 1110 */ 'A', 's', 'm', 'O', 'S', 'T', 'O', 'C', 0,
  /* 1119 */ 'A', 's', 'm', 'S', 'T', 'O', 'C', 0,
  /* 1127 */ 'A', 's', 'm', 'B', 'R', 'C', 0,
  /* 1134 */ 'S', 'T', 'C', 0,
  /* 1138 */ 'M', 'V', 'C', 0,
  /* 1142 */ 'X', 'C', 0,
  /* 1145 */ 'P', 'F', 'D', 0,
  /* 1149 */ 'L', 'D', 0,
  /* 1152 */ 'L', 'I', 'F', 'E', 'T', 'I', 'M', 'E', '_', 'E', 'N', 'D', 0,
  /* 1165 */ 'S', 'T', 'D', 0,
  /* 1169 */ 'R', 'E', 'G', '_', 'S', 'E', 'Q', 'U', 'E', 'N', 'C', 'E', 0,
  /* 1182 */ 'B', 'U', 'N', 'D', 'L', 'E', 0,
  /* 1189 */ 'S', 'T', 'E', 0,
  /* 1193 */ 'D', 'B', 'G', '_', 'V', 'A', 'L', 'U', 'E', 0,
  /* 1203 */ 'I', 'M', 'P', 'L', 'I', 'C', 'I', 'T', '_', 'D', 'E', 'F', 0,
  /* 1216 */ 'A', 'G', 'F', 0,
  /* 1220 */ 'C', 'G', 'F', 0,
  /* 1224 */ 'A', 'L', 'G', 'F', 0,
  /* 1229 */ 'C', 'L', 'G', 'F', 0,
  /* 1234 */ 'L', 'L', 'G', 'F', 0,
  /* 1239 */ 'S', 'L', 'G', 'F', 0,
  /* 1244 */ 'D', 'S', 'G', 'F', 0,
  /* 1249 */ 'M', 'S', 'G', 'F', 0,
  /* 1254 */ 'L', 'T', 'G', 'F', 0,
  /* 1259 */ 'C', 'H', 'F', 0,
  /* 1263 */ 'I', 'I', 'H', 'F', 0,
  /* 1268 */ 'L', 'L', 'I', 'H', 'F', 0,
  /* 1274 */ 'N', 'I', 'H', 'F', 0,
  /* 1279 */ 'O', 'I', 'H', 'F', 0,
  /* 1284 */ 'X', 'I', 'H', 'F', 0,
  /* 1289 */ 'C', 'L', 'H', 'F', 0,
  /* 1294 */ 'I', 'I', 'L', 'F', 0,
  /* 1299 */ 'L', 'L', 'I', 'L', 'F', 0,
  /* 1305 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'L', 'F', 0,
  /* 1322 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'I', 'L', 'F', 0,
  /* 1339 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'I', 'L', 'F', 0,
  /* 1356 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'X', 'I', 'L', 'F', 0,
  /* 1374 */ 'S', 'R', 'A', 'G', 0,
  /* 1379 */ 'S', 'L', 'B', 'G', 0,
  /* 1384 */ 'R', 'I', 'S', 'B', 'G', 0,
  /* 1390 */ 'R', 'N', 'S', 'B', 'G', 0,
  /* 1396 */ 'R', 'O', 'S', 'B', 'G', 0,
  /* 1402 */ 'R', 'X', 'S', 'B', 'G', 0,
  /* 1408 */ 'A', 'L', 'C', 'G', 0,
  /* 1413 */ 'A', 's', 'm', 'N', 'H', 'E', 'L', 'O', 'C', 'G', 0,
  /* 1424 */ 'A', 's', 'm', 'H', 'E', 'L', 'O', 'C', 'G', 0,
  /* 1434 */ 'A', 's', 'm', 'N', 'L', 'E', 'L', 'O', 'C', 'G', 0,
  /* 1445 */ 'A', 's', 'm', 'L', 'E', 'L', 'O', 'C', 'G', 0,
  /* 1455 */ 'A', 's', 'm', 'N', 'E', 'L', 'O', 'C', 'G', 0,
  /* 1465 */ 'A', 's', 'm', 'E', 'L', 'O', 'C', 'G', 0,
  /* 1474 */ 'A', 's', 'm', 'N', 'L', 'H', 'L', 'O', 'C', 'G', 0,
  /* 1485 */ 'A', 's', 'm', 'L', 'H', 'L', 'O', 'C', 'G', 0,
  /* 1495 */ 'A', 's', 'm', 'N', 'H', 'L', 'O', 'C', 'G', 0,
  /* 1505 */ 'A', 's', 'm', 'H', 'L', 'O', 'C', 'G', 0,
  /* 1514 */ 'A', 's', 'm', 'N', 'L', 'L', 'O', 'C', 'G', 0,
  /* 1524 */ 'A', 's', 'm', 'L', 'L', 'O', 'C', 'G', 0,
  /* 1533 */ 'A', 's', 'm', 'N', 'O', 'L', 'O', 'C', 'G', 0,
  /* 1543 */ 'A', 's', 'm', 'O', 'L', 'O', 'C', 'G', 0,
  /* 1552 */ 'A', 's', 'm', 'L', 'O', 'C', 'G', 0,
  /* 1560 */ 'A', 's', 'm', 'N', 'H', 'E', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1572 */ 'A', 's', 'm', 'H', 'E', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1583 */ 'A', 's', 'm', 'N', 'L', 'E', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1595 */ 'A', 's', 'm', 'L', 'E', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1606 */ 'A', 's', 'm', 'N', 'E', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1617 */ 'A', 's', 'm', 'E', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1627 */ 'A', 's', 'm', 'N', 'L', 'H', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1639 */ 'A', 's', 'm', 'L', 'H', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1650 */ 'A', 's', 'm', 'N', 'H', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1661 */ 'A', 's', 'm', 'H', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1671 */ 'A', 's', 'm', 'N', 'L', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1682 */ 'A', 's', 'm', 'L', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1692 */ 'A', 's', 'm', 'N', 'O', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1703 */ 'A', 's', 'm', 'O', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1713 */ 'A', 's', 'm', 'S', 'T', 'O', 'C', 'G', 0,
  /* 1722 */ 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'S', 'U', 'B', 'R', 'E', 'G', 0,
  /* 1737 */ 'I', 'N', 'S', 'E', 'R', 'T', '_', 'S', 'U', 'B', 'R', 'E', 'G', 0,
  /* 1751 */ 'S', 'U', 'B', 'R', 'E', 'G', '_', 'T', 'O', '_', 'R', 'E', 'G', 0,
  /* 1765 */ 'R', 'I', 'S', 'B', 'H', 'G', 0,
  /* 1772 */ 'A', 's', 'm', 'N', 'H', 'E', 'J', 'G', 0,
  /* 1781 */ 'A', 's', 'm', 'H', 'E', 'J', 'G', 0,
  /* 1789 */ 'A', 's', 'm', 'N', 'L', 'E', 'J', 'G', 0,
  /* 1798 */ 'A', 's', 'm', 'L', 'E', 'J', 'G', 0,
  /* 1806 */ 'A', 's', 'm', 'N', 'E', 'J', 'G', 0,
  /* 1814 */ 'A', 's', 'm', 'E', 'J', 'G', 0,
  /* 1821 */ 'A', 's', 'm', 'N', 'L', 'H', 'J', 'G', 0,
  /* 1830 */ 'A', 's', 'm', 'L', 'H', 'J', 'G', 0,
  /* 1838 */ 'A', 's', 'm', 'N', 'H', 'J', 'G', 0,
  /* 1846 */ 'A', 's', 'm', 'H', 'J', 'G', 0,
  /* 1853 */ 'A', 's', 'm', 'N', 'L', 'J', 'G', 0,
  /* 1861 */ 'A', 's', 'm', 'L', 'J', 'G', 0,
  /* 1868 */ 'A', 's', 'm', 'N', 'O', 'J', 'G', 0,
  /* 1876 */ 'A', 's', 'm', 'O', 'J', 'G', 0,
  /* 1883 */ 'C', 'a', 'l', 'l', 'J', 'G', 0,
  /* 1890 */ 'A', 'L', 'G', 0,
  /* 1894 */ 'R', 'I', 'S', 'B', 'L', 'G', 0,
  /* 1901 */ 'C', 'L', 'G', 0,
  /* 1905 */ 'D', 'L', 'G', 0,
  /* 1909 */ 'R', 'L', 'L', 'G', 0,
  /* 1914 */ 'S', 'L', 'L', 'G', 0,
  /* 1919 */ 'M', 'L', 'G', 0,
  /* 1923 */ 'S', 'R', 'L', 'G', 0,
  /* 1928 */ 'S', 'L', 'G', 0,
  /* 1932 */ 'L', 'M', 'G', 0,
  /* 1936 */ 'S', 'T', 'M', 'G', 0,
  /* 1941 */ 'N', 'G', 0,
  /* 1944 */ 'O', 'G', 0,
  /* 1947 */ 'C', 'S', 'G', 0,
  /* 1951 */ 'D', 'S', 'G', 0,
  /* 1955 */ 'M', 'S', 'G', 0,
  /* 1959 */ 'B', 'R', 'C', 'T', 'G', 0,
  /* 1965 */ 'L', 'T', 'G', 0,
  /* 1969 */ 'S', 'T', 'G', 0,
  /* 1973 */ 'L', 'R', 'V', 'G', 0,
  /* 1978 */ 'S', 'T', 'R', 'V', 'G', 0,
  /* 1984 */ 'X', 'G', 0,
  /* 1987 */ 'A', 'H', 0,
  /* 1990 */ 'L', 'B', 'H', 0,
  /* 1994 */ 'L', 'L', 'C', 'H', 0,
  /* 1999 */ 'S', 'T', 'C', 'H', 0,
  /* 2004 */ 'L', 'F', 'H', 0,
  /* 2008 */ 'S', 'T', 'F', 'H', 0,
  /* 2013 */ 'C', 'G', 'H', 0,
  /* 2017 */ 'L', 'L', 'G', 'H', 0,
  /* 2022 */ 'R', 'I', 'S', 'B', 'H', 'H', 0,
  /* 2029 */ 'I', 'I', 'H', 'H', 0,
  /* 2034 */ 'L', 'L', 'I', 'H', 'H', 0,
  /* 2040 */ 'N', 'I', 'H', 'H', 0,
  /* 2045 */ 'O', 'I', 'H', 'H', 0,
  /* 2050 */ 'L', 'L', 'H', 'H', 0,
  /* 2055 */ 'T', 'M', 'H', 'H', 0,
  /* 2060 */ 'S', 'T', 'H', 'H', 0,
  /* 2065 */ 'A', 'I', 'H', 0,
  /* 2069 */ 'C', 'I', 'H', 0,
  /* 2073 */ 'C', 'L', 'I', 'H', 0,
  /* 2078 */ 'R', 'I', 'S', 'B', 'L', 'H', 0,
  /* 2085 */ 'I', 'I', 'L', 'H', 0,
  /* 2090 */ 'L', 'L', 'I', 'L', 'H', 0,
  /* 2096 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'L', 'H', 0,
  /* 2113 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'N', 'I', 'L', 'H', 0,
  /* 2131 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'I', 'L', 'H', 0,
  /* 2148 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'O', 'I', 'L', 'H', 0,
  /* 2166 */ 'L', 'L', 'H', 0,
  /* 2170 */ 'T', 'M', 'L', 'H', 0,
  /* 2175 */ 'M', 'H', 0,
  /* 2178 */ 'S', 'H', 0,
  /* 2181 */ 'S', 'T', 'H', 0,
  /* 2185 */ 'A', 's', 'm', 'J', 'H', 'E', 'C', 'I', 0,
  /* 2194 */ 'A', 's', 'm', 'J', 'E', 'C', 'I', 0,
  /* 2202 */ 'A', 's', 'm', 'J', 'L', 'E', 'C', 'I', 0,
  /* 2211 */ 'A', 's', 'm', 'J', 'H', 'C', 'I', 0,
  /* 2219 */ 'A', 's', 'm', 'J', 'L', 'H', 'C', 'I', 0,
  /* 2228 */ 'A', 's', 'm', 'J', 'L', 'C', 'I', 0,
  /* 2236 */ 'A', 's', 'm', 'J', 'H', 'E', 'A', 'l', 't', 'C', 'I', 0,
  /* 2248 */ 'A', 's', 'm', 'J', 'E', 'A', 'l', 't', 'C', 'I', 0,
  /* 2259 */ 'A', 's', 'm', 'J', 'L', 'E', 'A', 'l', 't', 'C', 'I', 0,
  /* 2271 */ 'A', 's', 'm', 'J', 'H', 'A', 'l', 't', 'C', 'I', 0,
  /* 2282 */ 'A', 's', 'm', 'J', 'L', 'H', 'A', 'l', 't', 'C', 'I', 0,
  /* 2294 */ 'A', 's', 'm', 'J', 'L', 'A', 'l', 't', 'C', 'I', 0,
  /* 2305 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'F', 'I', 0,
  /* 2321 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'A', 'F', 'I', 0,
  /* 2338 */ 'C', 'F', 'I', 0,
  /* 2342 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'G', 'F', 'I', 0,
  /* 2359 */ 'C', 'G', 'F', 'I', 0,
  /* 2364 */ 'A', 'L', 'G', 'F', 'I', 0,
  /* 2370 */ 'C', 'L', 'G', 'F', 'I', 0,
  /* 2376 */ 'S', 'L', 'G', 'F', 'I', 0,
  /* 2382 */ 'M', 'S', 'G', 'F', 'I', 0,
  /* 2388 */ 'A', 'L', 'F', 'I', 0,
  /* 2393 */ 'C', 'L', 'F', 'I', 0,
  /* 2398 */ 'S', 'L', 'F', 'I', 0,
  /* 2403 */ 'M', 'S', 'F', 'I', 0,
  /* 2408 */ 'A', 's', 'm', 'J', 'H', 'E', 'C', 'G', 'I', 0,
  /* 2418 */ 'A', 's', 'm', 'J', 'E', 'C', 'G', 'I', 0,
  /* 2427 */ 'A', 's', 'm', 'J', 'L', 'E', 'C', 'G', 'I', 0,
  /* 2437 */ 'A', 's', 'm', 'J', 'H', 'C', 'G', 'I', 0,
  /* 2446 */ 'A', 's', 'm', 'J', 'L', 'H', 'C', 'G', 'I', 0,
  /* 2456 */ 'A', 's', 'm', 'J', 'L', 'C', 'G', 'I', 0,
  /* 2465 */ 'A', 's', 'm', 'J', 'H', 'E', 'A', 'l', 't', 'C', 'G', 'I', 0,
  /* 2478 */ 'A', 's', 'm', 'J', 'E', 'A', 'l', 't', 'C', 'G', 'I', 0,
  /* 2490 */ 'A', 's', 'm', 'J', 'L', 'E', 'A', 'l', 't', 'C', 'G', 'I', 0,
  /* 2503 */ 'A', 's', 'm', 'J', 'H', 'A', 'l', 't', 'C', 'G', 'I', 0,
  /* 2515 */ 'A', 's', 'm', 'J', 'L', 'H', 'A', 'l', 't', 'C', 'G', 'I', 0,
  /* 2528 */ 'A', 's', 'm', 'J', 'L', 'A', 'l', 't', 'C', 'G', 'I', 0,
  /* 2540 */ 'A', 's', 'm', 'J', 'H', 'E', 'C', 'L', 'G', 'I', 0,
  /* 2551 */ 'A', 's', 'm', 'J', 'E', 'C', 'L', 'G', 'I', 0,
  /* 2561 */ 'A', 's', 'm', 'J', 'L', 'E', 'C', 'L', 'G', 'I', 0,
  /* 2572 */ 'A', 's', 'm', 'J', 'H', 'C', 'L', 'G', 'I', 0,
  /* 2582 */ 'A', 's', 'm', 'J', 'L', 'H', 'C', 'L', 'G', 'I', 0,
  /* 2593 */ 'A', 's', 'm', 'J', 'L', 'C', 'L', 'G', 'I', 0,
  /* 2603 */ 'A', 's', 'm', 'J', 'H', 'E', 'A', 'l', 't', 'C', 'L', 'G', 'I', 0,
  /* 2617 */ 'A', 's', 'm', 'J', 'E', 'A', 'l', 't', 'C', 'L', 'G', 'I', 0,
  /* 2630 */ 'A', 's', 'm', 'J', 'L', 'E', 'A', 'l', 't', 'C', 'L', 'G', 'I', 0,
  /* 2644 */ 'A', 's', 'm', 'J', 'H', 'A', 'l', 't', 'C', 'L', 'G', 'I', 0,
  /* 2657 */ 'A', 's', 'm', 'J', 'L', 'H', 'A', 'l', 't', 'C', 'L', 'G', 'I', 0,
  /* 2671 */ 'A', 's', 'm', 'J', 'L', 'A', 'l', 't', 'C', 'L', 'G', 'I', 0,
  /* 2684 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'H', 'I', 0,
  /* 2700 */ 'C', 'H', 'I', 0,
  /* 2704 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'G', 'H', 'I', 0,
  /* 2721 */ 'C', 'G', 'H', 'I', 0,
  /* 2726 */ 'L', 'G', 'H', 'I', 0,
  /* 2731 */ 'M', 'G', 'H', 'I', 0,
  /* 2736 */ 'M', 'V', 'G', 'H', 'I', 0,
  /* 2742 */ 'M', 'V', 'H', 'H', 'I', 0,
  /* 2748 */ 'L', 'H', 'I', 0,
  /* 2752 */ 'M', 'H', 'I', 0,
  /* 2756 */ 'P', 'H', 'I', 0,
  /* 2760 */ 'M', 'V', 'H', 'I', 0,
  /* 2765 */ 'A', 's', 'm', 'J', 'H', 'E', 'C', 'L', 'I', 0,
  /* 2775 */ 'A', 's', 'm', 'J', 'E', 'C', 'L', 'I', 0,
  /* 2784 */ 'A', 's', 'm', 'J', 'L', 'E', 'C', 'L', 'I', 0,
  /* 2794 */ 'A', 's', 'm', 'J', 'H', 'C', 'L', 'I', 0,
  /* 2803 */ 'A', 's', 'm', 'J', 'L', 'H', 'C', 'L', 'I', 0,
  /* 2813 */ 'A', 's', 'm', 'J', 'L', 'C', 'L', 'I', 0,
  /* 2822 */ 'A', 's', 'm', 'J', 'H', 'E', 'A', 'l', 't', 'C', 'L', 'I', 0,
  /* 2835 */ 'A', 's', 'm', 'J', 'E', 'A', 'l', 't', 'C', 'L', 'I', 0,
  /* 2847 */ 'A', 's', 'm', 'J', 'L', 'E', 'A', 'l', 't', 'C', 'L', 'I', 0,
  /* 2860 */ 'A', 's', 'm', 'J', 'H', 'A', 'l', 't', 'C', 'L', 'I', 0,
  /* 2872 */ 'A', 's', 'm', 'J', 'L', 'H', 'A', 'l', 't', 'C', 'L', 'I', 0,
  /* 2885 */ 'A', 's', 'm', 'J', 'L', 'A', 'l', 't', 'C', 'L', 'I', 0,
  /* 2897 */ 'N', 'I', 0,
  /* 2900 */ 'O', 'I', 0,
  /* 2903 */ 'A', 'S', 'I', 0,
  /* 2907 */ 'A', 'G', 'S', 'I', 0,
  /* 2912 */ 'C', 'H', 'S', 'I', 0,
  /* 2917 */ 'C', 'L', 'F', 'H', 'S', 'I', 0,
  /* 2924 */ 'C', 'G', 'H', 'S', 'I', 0,
  /* 2930 */ 'C', 'L', 'G', 'H', 'S', 'I', 0,
  /* 2937 */ 'C', 'H', 'H', 'S', 'I', 0,
  /* 2943 */ 'C', 'L', 'H', 'H', 'S', 'I', 0,
  /* 2950 */ 'M', 'V', 'I', 0,
  /* 2954 */ 'X', 'I', 0,
  /* 2957 */ 'A', 's', 'm', 'N', 'H', 'E', 'J', 0,
  /* 2965 */ 'A', 's', 'm', 'H', 'E', 'J', 0,
  /* 2972 */ 'A', 's', 'm', 'N', 'L', 'E', 'J', 0,
  /* 2980 */ 'A', 's', 'm', 'L', 'E', 'J', 0,
  /* 2987 */ 'A', 's', 'm', 'N', 'E', 'J', 0,
  /* 2994 */ 'A', 's', 'm', 'E', 'J', 0,
  /* 3000 */ 'A', 's', 'm', 'N', 'L', 'H', 'J', 0,
  /* 3008 */ 'A', 's', 'm', 'L', 'H', 'J', 0,
  /* 3015 */ 'A', 's', 'm', 'N', 'H', 'J', 0,
  /* 3022 */ 'A', 's', 'm', 'H', 'J', 0,
  /* 3028 */ 'A', 's', 'm', 'C', 'I', 'J', 0,
  /* 3035 */ 'A', 's', 'm', 'C', 'G', 'I', 'J', 0,
  /* 3043 */ 'A', 's', 'm', 'C', 'L', 'G', 'I', 'J', 0,
  /* 3052 */ 'A', 's', 'm', 'C', 'L', 'I', 'J', 0,
  /* 3060 */ 'A', 's', 'm', 'N', 'L', 'J', 0,
  /* 3067 */ 'A', 's', 'm', 'L', 'J', 0,
  /* 3073 */ 'A', 's', 'm', 'N', 'O', 'J', 0,
  /* 3080 */ 'A', 's', 'm', 'O', 'J', 0,
  /* 3086 */ 'A', 's', 'm', 'C', 'R', 'J', 0,
  /* 3093 */ 'A', 's', 'm', 'C', 'G', 'R', 'J', 0,
  /* 3101 */ 'A', 's', 'm', 'C', 'L', 'G', 'R', 'J', 0,
  /* 3110 */ 'A', 's', 'm', 'C', 'L', 'R', 'J', 0,
  /* 3118 */ 'S', 'R', 'A', 'K', 0,
  /* 3123 */ 'A', 'H', 'I', 'K', 0,
  /* 3128 */ 'A', 'G', 'H', 'I', 'K', 0,
  /* 3134 */ 'A', 'L', 'G', 'H', 'S', 'I', 'K', 0,
  /* 3142 */ 'A', 'L', 'H', 'S', 'I', 'K', 0,
  /* 3149 */ 'S', 'L', 'L', 'K', 0,
  /* 3154 */ 'S', 'R', 'L', 'K', 0,
  /* 3159 */ 'A', 'R', 'K', 0,
  /* 3163 */ 'A', 'G', 'R', 'K', 0,
  /* 3168 */ 'A', 'L', 'G', 'R', 'K', 0,
  /* 3174 */ 'S', 'L', 'G', 'R', 'K', 0,
  /* 3180 */ 'N', 'G', 'R', 'K', 0,
  /* 3185 */ 'O', 'G', 'R', 'K', 0,
  /* 3190 */ 'S', 'G', 'R', 'K', 0,
  /* 3195 */ 'X', 'G', 'R', 'K', 0,
  /* 3200 */ 'A', 'L', 'R', 'K', 0,
  /* 3205 */ 'S', 'L', 'R', 'K', 0,
  /* 3210 */ 'N', 'R', 'K', 0,
  /* 3214 */ 'O', 'R', 'K', 0,
  /* 3218 */ 'S', 'R', 'K', 0,
  /* 3222 */ 'X', 'R', 'K', 0,
  /* 3226 */ 'A', 'H', 'I', 'M', 'u', 'x', 'K', 0,
  /* 3234 */ 'A', 'L', 0,
  /* 3237 */ 'A', 's', 'm', 'B', 'R', 'C', 'L', 0,
  /* 3245 */ 'D', 'L', 0,
  /* 3248 */ 'G', 'C', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 3257 */ 'P', 'R', 'O', 'L', 'O', 'G', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 3270 */ 'E', 'H', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 3279 */ 'R', 'I', 'S', 'B', 'H', 'L', 0,
  /* 3286 */ 'I', 'I', 'H', 'L', 0,
  /* 3291 */ 'L', 'L', 'I', 'H', 'L', 0,
  /* 3297 */ 'N', 'I', 'H', 'L', 0,
  /* 3302 */ 'O', 'I', 'H', 'L', 0,
  /* 3307 */ 'T', 'M', 'H', 'L', 0,
  /* 3312 */ 'R', 'I', 'S', 'B', 'L', 'L', 0,
  /* 3319 */ 'I', 'I', 'L', 'L', 0,
  /* 3324 */ 'K', 'I', 'L', 'L', 0,
  /* 3329 */ 'L', 'L', 'I', 'L', 'L', 0,
  /* 3335 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'L', 'L', 0,
  /* 3352 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'I', 'L', 'L', 0,
  /* 3369 */ 'T', 'M', 'L', 'L', 0,
  /* 3374 */ 'R', 'L', 'L', 0,
  /* 3378 */ 'S', 'L', 'L', 0,
  /* 3382 */ 'L', 'A', 'R', 'L', 0,
  /* 3387 */ 'C', 'R', 'L', 0,
  /* 3391 */ 'P', 'F', 'D', 'R', 'L', 0,
  /* 3397 */ 'C', 'G', 'F', 'R', 'L', 0,
  /* 3403 */ 'C', 'L', 'G', 'F', 'R', 'L', 0,
  /* 3410 */ 'L', 'L', 'G', 'F', 'R', 'L', 0,
  /* 3417 */ 'C', 'G', 'R', 'L', 0,
  /* 3422 */ 'C', 'L', 'G', 'R', 'L', 0,
  /* 3428 */ 'S', 'T', 'G', 'R', 'L', 0,
  /* 3434 */ 'C', 'H', 'R', 'L', 0,
  /* 3439 */ 'C', 'G', 'H', 'R', 'L', 0,
  /* 3445 */ 'C', 'L', 'G', 'H', 'R', 'L', 0,
  /* 3452 */ 'L', 'L', 'G', 'H', 'R', 'L', 0,
  /* 3459 */ 'C', 'L', 'H', 'R', 'L', 0,
  /* 3465 */ 'L', 'L', 'H', 'R', 'L', 0,
  /* 3471 */ 'S', 'T', 'H', 'R', 'L', 0,
  /* 3477 */ 'C', 'L', 'R', 'L', 0,
  /* 3482 */ 'S', 'R', 'L', 0,
  /* 3486 */ 'S', 'T', 'R', 'L', 0,
  /* 3491 */ 'C', 'a', 'l', 'l', 'B', 'R', 'A', 'S', 'L', 0,
  /* 3501 */ 'I', 'P', 'M', 0,
  /* 3505 */ 'I', 'N', 'L', 'I', 'N', 'E', 'A', 'S', 'M', 0,
  /* 3515 */ 'T', 'M', 0,
  /* 3518 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'U', 'M', 'I', 'N', 0,
  /* 3536 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'M', 'I', 'N', 0,
  /* 3553 */ 'A', 'D', 'J', 'C', 'A', 'L', 'L', 'S', 'T', 'A', 'C', 'K', 'D', 'O', 'W', 'N', 0,
  /* 3570 */ 'O', 0,
  /* 3572 */ 'S', 'T', 'A', 'C', 'K', 'M', 'A', 'P', 0,
  /* 3581 */ 'A', 'D', 'J', 'C', 'A', 'L', 'L', 'S', 'T', 'A', 'C', 'K', 'U', 'P', 0,
  /* 3596 */ 'E', 'A', 'R', 0,
  /* 3600 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'R', 0,
  /* 3615 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'A', 'R', 0,
  /* 3631 */ 'M', 'A', 'D', 'B', 'R', 0,
  /* 3637 */ 'L', 'C', 'D', 'B', 'R', 0,
  /* 3643 */ 'D', 'D', 'B', 'R', 0,
  /* 3648 */ 'L', 'E', 'D', 'B', 'R', 0,
  /* 3654 */ 'C', 'F', 'D', 'B', 'R', 0,
  /* 3660 */ 'C', 'G', 'D', 'B', 'R', 0,
  /* 3666 */ 'F', 'I', 'D', 'B', 'R', 0,
  /* 3672 */ 'M', 'D', 'B', 'R', 0,
  /* 3677 */ 'L', 'N', 'D', 'B', 'R', 0,
  /* 3683 */ 'L', 'P', 'D', 'B', 'R', 0,
  /* 3689 */ 'S', 'Q', 'D', 'B', 'R', 0,
  /* 3695 */ 'M', 'S', 'D', 'B', 'R', 0,
  /* 3701 */ 'L', 'T', 'D', 'B', 'R', 0,
  /* 3707 */ 'L', 'X', 'D', 'B', 'R', 0,
  /* 3713 */ 'M', 'X', 'D', 'B', 'R', 0,
  /* 3719 */ 'M', 'A', 'E', 'B', 'R', 0,
  /* 3725 */ 'L', 'C', 'E', 'B', 'R', 0,
  /* 3731 */ 'L', 'D', 'E', 'B', 'R', 0,
  /* 3737 */ 'M', 'D', 'E', 'B', 'R', 0,
  /* 3743 */ 'M', 'E', 'E', 'B', 'R', 0,
  /* 3749 */ 'C', 'F', 'E', 'B', 'R', 0,
  /* 3755 */ 'C', 'G', 'E', 'B', 'R', 0,
  /* 3761 */ 'A', 's', 'm', 'N', 'H', 'E', 'B', 'R', 0,
  /* 3770 */ 'A', 's', 'm', 'H', 'E', 'B', 'R', 0,
  /* 3778 */ 'F', 'I', 'E', 'B', 'R', 0,
  /* 3784 */ 'A', 's', 'm', 'N', 'L', 'E', 'B', 'R', 0,
  /* 3793 */ 'A', 's', 'm', 'L', 'E', 'B', 'R', 0,
  /* 3801 */ 'L', 'N', 'E', 'B', 'R', 0,
  /* 3807 */ 'A', 's', 'm', 'N', 'E', 'B', 'R', 0,
  /* 3815 */ 'L', 'P', 'E', 'B', 'R', 0,
  /* 3821 */ 'S', 'Q', 'E', 'B', 'R', 0,
  /* 3827 */ 'M', 'S', 'E', 'B', 'R', 0,
  /* 3833 */ 'L', 'T', 'E', 'B', 'R', 0,
  /* 3839 */ 'L', 'X', 'E', 'B', 'R', 0,
  /* 3845 */ 'A', 's', 'm', 'E', 'B', 'R', 0,
  /* 3852 */ 'C', 'D', 'F', 'B', 'R', 0,
  /* 3858 */ 'C', 'E', 'F', 'B', 'R', 0,
  /* 3864 */ 'C', 'X', 'F', 'B', 'R', 0,
  /* 3870 */ 'C', 'D', 'G', 'B', 'R', 0,
  /* 3876 */ 'C', 'E', 'G', 'B', 'R', 0,
  /* 3882 */ 'S', 'L', 'G', 'B', 'R', 0,
  /* 3888 */ 'C', 'X', 'G', 'B', 'R', 0,
  /* 3894 */ 'A', 's', 'm', 'N', 'L', 'H', 'B', 'R', 0,
  /* 3903 */ 'A', 's', 'm', 'L', 'H', 'B', 'R', 0,
  /* 3911 */ 'A', 's', 'm', 'N', 'H', 'B', 'R', 0,
  /* 3919 */ 'A', 's', 'm', 'H', 'B', 'R', 0,
  /* 3926 */ 'A', 's', 'm', 'N', 'L', 'B', 'R', 0,
  /* 3934 */ 'S', 'L', 'B', 'R', 0,
  /* 3939 */ 'A', 's', 'm', 'L', 'B', 'R', 0,
  /* 3946 */ 'A', 's', 'm', 'N', 'O', 'B', 'R', 0,
  /* 3954 */ 'A', 's', 'm', 'O', 'B', 'R', 0,
  /* 3961 */ 'A', 'X', 'B', 'R', 0,
  /* 3966 */ 'L', 'C', 'X', 'B', 'R', 0,
  /* 3972 */ 'L', 'D', 'X', 'B', 'R', 0,
  /* 3978 */ 'L', 'E', 'X', 'B', 'R', 0,
  /* 3984 */ 'C', 'F', 'X', 'B', 'R', 0,
  /* 3990 */ 'C', 'G', 'X', 'B', 'R', 0,
  /* 3996 */ 'F', 'I', 'X', 'B', 'R', 0,
  /* 4002 */ 'M', 'X', 'B', 'R', 0,
  /* 4007 */ 'L', 'N', 'X', 'B', 'R', 0,
  /* 4013 */ 'L', 'P', 'X', 'B', 'R', 0,
  /* 4019 */ 'S', 'Q', 'X', 'B', 'R', 0,
  /* 4025 */ 'S', 'X', 'B', 'R', 0,
  /* 4030 */ 'L', 'T', 'X', 'B', 'R', 0,
  /* 4036 */ 'C', 'a', 'l', 'l', 'B', 'R', 0,
  /* 4043 */ 'A', 's', 'm', 'B', 'C', 'R', 0,
  /* 4050 */ 'A', 's', 'm', 'J', 'H', 'E', 'C', 'R', 0,
  /* 4059 */ 'A', 's', 'm', 'J', 'E', 'C', 'R', 0,
  /* 4067 */ 'A', 's', 'm', 'J', 'L', 'E', 'C', 'R', 0,
  /* 4076 */ 'L', 'L', 'G', 'C', 'R', 0,
  /* 4082 */ 'A', 's', 'm', 'J', 'H', 'C', 'R', 0,
  /* 4090 */ 'A', 's', 'm', 'J', 'L', 'H', 'C', 'R', 0,
  /* 4099 */ 'A', 'L', 'C', 'R', 0,
  /* 4104 */ 'A', 's', 'm', 'J', 'L', 'C', 'R', 0,
  /* 4112 */ 'L', 'L', 'C', 'R', 0,
  /* 4117 */ 'A', 's', 'm', 'N', 'H', 'E', 'L', 'O', 'C', 'R', 0,
  /* 4128 */ 'A', 's', 'm', 'H', 'E', 'L', 'O', 'C', 'R', 0,
  /* 4138 */ 'A', 's', 'm', 'N', 'L', 'E', 'L', 'O', 'C', 'R', 0,
  /* 4149 */ 'A', 's', 'm', 'L', 'E', 'L', 'O', 'C', 'R', 0,
  /* 4159 */ 'A', 's', 'm', 'N', 'E', 'L', 'O', 'C', 'R', 0,
  /* 4169 */ 'A', 's', 'm', 'E', 'L', 'O', 'C', 'R', 0,
  /* 4178 */ 'A', 's', 'm', 'N', 'L', 'H', 'L', 'O', 'C', 'R', 0,
  /* 4189 */ 'A', 's', 'm', 'L', 'H', 'L', 'O', 'C', 'R', 0,
  /* 4199 */ 'A', 's', 'm', 'N', 'H', 'L', 'O', 'C', 'R', 0,
  /* 4209 */ 'A', 's', 'm', 'H', 'L', 'O', 'C', 'R', 0,
  /* 4218 */ 'A', 's', 'm', 'N', 'L', 'L', 'O', 'C', 'R', 0,
  /* 4228 */ 'A', 's', 'm', 'L', 'L', 'O', 'C', 'R', 0,
  /* 4237 */ 'A', 's', 'm', 'N', 'O', 'L', 'O', 'C', 'R', 0,
  /* 4247 */ 'A', 's', 'm', 'O', 'L', 'O', 'C', 'R', 0,
  /* 4256 */ 'A', 's', 'm', 'L', 'O', 'C', 'R', 0,
  /* 4264 */ 'A', 's', 'm', 'J', 'H', 'E', 'A', 'l', 't', 'C', 'R', 0,
  /* 4276 */ 'A', 's', 'm', 'J', 'E', 'A', 'l', 't', 'C', 'R', 0,
  /* 4287 */ 'A', 's', 'm', 'J', 'L', 'E', 'A', 'l', 't', 'C', 'R', 0,
  /* 4299 */ 'A', 's', 'm', 'J', 'H', 'A', 'l', 't', 'C', 'R', 0,
  /* 4310 */ 'A', 's', 'm', 'J', 'L', 'H', 'A', 'l', 't', 'C', 'R', 0,
  /* 4322 */ 'A', 's', 'm', 'J', 'L', 'A', 'l', 't', 'C', 'R', 0,
  /* 4333 */ 'L', 'G', 'D', 'R', 0,
  /* 4338 */ 'L', 'D', 'R', 0,
  /* 4342 */ 'L', 'Z', 'D', 'R', 0,
  /* 4347 */ 'L', 'E', 'R', 0,
  /* 4351 */ 'L', 'Z', 'E', 'R', 0,
  /* 4356 */ 'A', 'G', 'F', 'R', 0,
  /* 4361 */ 'L', 'C', 'G', 'F', 'R', 0,
  /* 4367 */ 'A', 'L', 'G', 'F', 'R', 0,
  /* 4373 */ 'C', 'L', 'G', 'F', 'R', 0,
  /* 4379 */ 'L', 'L', 'G', 'F', 'R', 0,
  /* 4385 */ 'S', 'L', 'G', 'F', 'R', 0,
  /* 4391 */ 'L', 'N', 'G', 'F', 'R', 0,
  /* 4397 */ 'L', 'P', 'G', 'F', 'R', 0,
  /* 4403 */ 'D', 'S', 'G', 'F', 'R', 0,
  /* 4409 */ 'M', 'S', 'G', 'F', 'R', 0,
  /* 4415 */ 'L', 'T', 'G', 'F', 'R', 0,
  /* 4421 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'G', 'R', 0,
  /* 4437 */ 'A', 's', 'm', 'J', 'H', 'E', 'C', 'G', 'R', 0,
  /* 4447 */ 'A', 's', 'm', 'J', 'E', 'C', 'G', 'R', 0,
  /* 4456 */ 'A', 's', 'm', 'J', 'L', 'E', 'C', 'G', 'R', 0,
  /* 4466 */ 'A', 's', 'm', 'J', 'H', 'C', 'G', 'R', 0,
  /* 4475 */ 'A', 's', 'm', 'J', 'L', 'H', 'C', 'G', 'R', 0,
  /* 4485 */ 'A', 'L', 'C', 'G', 'R', 0,
  /* 4491 */ 'A', 's', 'm', 'J', 'L', 'C', 'G', 'R', 0,
  /* 4500 */ 'A', 's', 'm', 'N', 'H', 'E', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4512 */ 'A', 's', 'm', 'H', 'E', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4523 */ 'A', 's', 'm', 'N', 'L', 'E', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4535 */ 'A', 's', 'm', 'L', 'E', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4546 */ 'A', 's', 'm', 'N', 'E', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4557 */ 'A', 's', 'm', 'E', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4567 */ 'A', 's', 'm', 'N', 'L', 'H', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4579 */ 'A', 's', 'm', 'L', 'H', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4590 */ 'A', 's', 'm', 'N', 'H', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4601 */ 'A', 's', 'm', 'H', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4611 */ 'A', 's', 'm', 'N', 'L', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4622 */ 'A', 's', 'm', 'L', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4632 */ 'A', 's', 'm', 'N', 'O', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4643 */ 'A', 's', 'm', 'O', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4653 */ 'A', 's', 'm', 'L', 'O', 'C', 'G', 'R', 0,
  /* 4662 */ 'A', 's', 'm', 'J', 'H', 'E', 'A', 'l', 't', 'C', 'G', 'R', 0,
  /* 4675 */ 'A', 's', 'm', 'J', 'E', 'A', 'l', 't', 'C', 'G', 'R', 0,
  /* 4687 */ 'A', 's', 'm', 'J', 'L', 'E', 'A', 'l', 't', 'C', 'G', 'R', 0,
  /* 4700 */ 'A', 's', 'm', 'J', 'H', 'A', 'l', 't', 'C', 'G', 'R', 0,
  /* 4712 */ 'A', 's', 'm', 'J', 'L', 'H', 'A', 'l', 't', 'C', 'G', 'R', 0,
  /* 4725 */ 'A', 's', 'm', 'J', 'L', 'A', 'l', 't', 'C', 'G', 'R', 0,
  /* 4737 */ 'L', 'D', 'G', 'R', 0,
  /* 4742 */ 'A', 'L', 'G', 'R', 0,
  /* 4747 */ 'A', 's', 'm', 'J', 'H', 'E', 'C', 'L', 'G', 'R', 0,
  /* 4758 */ 'A', 's', 'm', 'J', 'E', 'C', 'L', 'G', 'R', 0,
  /* 4768 */ 'A', 's', 'm', 'J', 'L', 'E', 'C', 'L', 'G', 'R', 0,
  /* 4779 */ 'A', 's', 'm', 'J', 'H', 'C', 'L', 'G', 'R', 0,
  /* 4789 */ 'A', 's', 'm', 'J', 'L', 'H', 'C', 'L', 'G', 'R', 0,
  /* 4800 */ 'A', 's', 'm', 'J', 'L', 'C', 'L', 'G', 'R', 0,
  /* 4810 */ 'A', 's', 'm', 'J', 'H', 'E', 'A', 'l', 't', 'C', 'L', 'G', 'R', 0,
  /* 4824 */ 'A', 's', 'm', 'J', 'E', 'A', 'l', 't', 'C', 'L', 'G', 'R', 0,
  /* 4837 */ 'A', 's', 'm', 'J', 'L', 'E', 'A', 'l', 't', 'C', 'L', 'G', 'R', 0,
  /* 4851 */ 'A', 's', 'm', 'J', 'H', 'A', 'l', 't', 'C', 'L', 'G', 'R', 0,
  /* 4864 */ 'A', 's', 'm', 'J', 'L', 'H', 'A', 'l', 't', 'C', 'L', 'G', 'R', 0,
  /* 4878 */ 'A', 's', 'm', 'J', 'L', 'A', 'l', 't', 'C', 'L', 'G', 'R', 0,
  /* 4891 */ 'D', 'L', 'G', 'R', 0,
  /* 4896 */ 'M', 'L', 'G', 'R', 0,
  /* 4901 */ 'S', 'L', 'G', 'R', 0,
  /* 4906 */ 'L', 'N', 'G', 'R', 0,
  /* 4911 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'G', 'R', 0,
  /* 4927 */ 'F', 'L', 'O', 'G', 'R', 0,
  /* 4933 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'G', 'R', 0,
  /* 4949 */ 'L', 'P', 'G', 'R', 0,
  /* 4954 */ 'D', 'S', 'G', 'R', 0,
  /* 4959 */ 'M', 'S', 'G', 'R', 0,
  /* 4964 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'G', 'R', 0,
  /* 4980 */ 'L', 'T', 'G', 'R', 0,
  /* 4985 */ 'L', 'R', 'V', 'G', 'R', 0,
  /* 4991 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'G', 'R', 0,
  /* 5007 */ 'L', 'L', 'G', 'H', 'R', 0,
  /* 5013 */ 'L', 'L', 'H', 'R', 0,
  /* 5018 */ 'A', 'L', 'R', 0,
  /* 5022 */ 'A', 's', 'm', 'J', 'H', 'E', 'C', 'L', 'R', 0,
  /* 5032 */ 'A', 's', 'm', 'J', 'E', 'C', 'L', 'R', 0,
  /* 5041 */ 'A', 's', 'm', 'J', 'L', 'E', 'C', 'L', 'R', 0,
  /* 5051 */ 'A', 's', 'm', 'J', 'H', 'C', 'L', 'R', 0,
  /* 5060 */ 'A', 's', 'm', 'J', 'L', 'H', 'C', 'L', 'R', 0,
  /* 5070 */ 'A', 's', 'm', 'J', 'L', 'C', 'L', 'R', 0,
  /* 5079 */ 'A', 's', 'm', 'J', 'H', 'E', 'A', 'l', 't', 'C', 'L', 'R', 0,
  /* 5092 */ 'A', 's', 'm', 'J', 'E', 'A', 'l', 't', 'C', 'L', 'R', 0,
  /* 5104 */ 'A', 's', 'm', 'J', 'L', 'E', 'A', 'l', 't', 'C', 'L', 'R', 0,
  /* 5117 */ 'A', 's', 'm', 'J', 'H', 'A', 'l', 't', 'C', 'L', 'R', 0,
  /* 5129 */ 'A', 's', 'm', 'J', 'L', 'H', 'A', 'l', 't', 'C', 'L', 'R', 0,
  /* 5142 */ 'A', 's', 'm', 'J', 'L', 'A', 'l', 't', 'C', 'L', 'R', 0,
  /* 5154 */ 'D', 'L', 'R', 0,
  /* 5158 */ 'S', 'L', 'R', 0,
  /* 5162 */ 'L', 'N', 'R', 0,
  /* 5166 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'R', 0,
  /* 5181 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'N', 'R', 0,
  /* 5197 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'R', 0,
  /* 5212 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'O', 'R', 0,
  /* 5228 */ 'L', 'P', 'R', 0,
  /* 5232 */ 'C', 'a', 'l', 'l', 'B', 'A', 'S', 'R', 0,
  /* 5241 */ 'M', 'S', 'R', 0,
  /* 5245 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'R', 0,
  /* 5260 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'S', 'R', 0,
  /* 5276 */ 'L', 'T', 'R', 0,
  /* 5280 */ 'L', 'R', 'V', 'R', 0,
  /* 5285 */ 'L', 'X', 'R', 0,
  /* 5289 */ 'L', 'Z', 'X', 'R', 0,
  /* 5294 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'R', 0,
  /* 5309 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'X', 'R', 0,
  /* 5325 */ 'B', 'R', 'A', 'S', 0,
  /* 5330 */ 'C', 'S', 0,
  /* 5333 */ 'M', 'S', 0,
  /* 5336 */ 'C', 'O', 'P', 'Y', '_', 'T', 'O', '_', 'R', 'E', 'G', 'C', 'L', 'A', 'S', 'S', 0,
  /* 5353 */ 'B', 'R', 'C', 'T', 0,
  /* 5358 */ 'L', 'T', 0,
  /* 5361 */ 'P', 'A', 'T', 'C', 'H', 'P', 'O', 'I', 'N', 'T', 0,
  /* 5372 */ 'L', 'I', 'F', 'E', 'T', 'I', 'M', 'E', '_', 'S', 'T', 'A', 'R', 'T', 0,
  /* 5387 */ 'C', 'L', 'S', 'T', 0,
  /* 5392 */ 'S', 'R', 'S', 'T', 0,
  /* 5397 */ 'M', 'V', 'S', 'T', 0,
  /* 5402 */ 'L', 'R', 'V', 0,
  /* 5406 */ 'S', 'T', 'R', 'V', 0,
  /* 5411 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', 'W', 0,
  /* 5424 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'C', 'M', 'P', '_', 'S', 'W', 'A', 'P', 'W', 0,
  /* 5441 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'U', 'M', 'A', 'X', 0,
  /* 5459 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'M', 'A', 'X', 0,
  /* 5476 */ 'L', 'X', 0,
  /* 5479 */ 'S', 'T', 'X', 0,
  /* 5483 */ 'I', 'C', '3', '2', 'Y', 0,
  /* 5489 */ 'L', 'A', 'Y', 0,
  /* 5493 */ 'I', 'C', 'Y', 0,
  /* 5497 */ 'S', 'T', 'C', 'Y', 0,
  /* 5502 */ 'L', 'D', 'Y', 0,
  /* 5506 */ 'S', 'T', 'D', 'Y', 0,
  /* 5511 */ 'L', 'E', 'Y', 0,
  /* 5515 */ 'S', 'T', 'E', 'Y', 0,
  /* 5520 */ 'A', 'H', 'Y', 0,
  /* 5524 */ 'C', 'H', 'Y', 0,
  /* 5528 */ 'L', 'H', 'Y', 0,
  /* 5532 */ 'M', 'H', 'Y', 0,
  /* 5536 */ 'S', 'H', 'Y', 0,
  /* 5540 */ 'S', 'T', 'H', 'Y', 0,
  /* 5545 */ 'C', 'L', 'I', 'Y', 0,
  /* 5550 */ 'N', 'I', 'Y', 0,
  /* 5554 */ 'O', 'I', 'Y', 0,
  /* 5558 */ 'M', 'V', 'I', 'Y', 0,
  /* 5563 */ 'X', 'I', 'Y', 0,
  /* 5567 */ 'A', 'L', 'Y', 0,
  /* 5571 */ 'C', 'L', 'Y', 0,
  /* 5575 */ 'S', 'L', 'Y', 0,
  /* 5579 */ 'T', 'M', 'Y', 0,
  /* 5583 */ 'N', 'Y', 0,
  /* 5586 */ 'O', 'Y', 0,
  /* 5589 */ 'C', 'O', 'P', 'Y', 0,
  /* 5594 */ 'C', 'S', 'Y', 0,
  /* 5598 */ 'M', 'S', 'Y', 0,
  /* 5602 */ 'S', 'T', 'Y', 0,
  /* 5606 */ 'X', 'Y', 0,
  /* 5609 */ 'C', 'P', 'S', 'D', 'R', 'd', 'd', 0,
  /* 5617 */ 'C', 'P', 'S', 'D', 'R', 's', 'd', 0,
  /* 5625 */ 'C', 'L', 'C', 'S', 'e', 'q', 'u', 'e', 'n', 'c', 'e', 0,
  /* 5637 */ 'N', 'C', 'S', 'e', 'q', 'u', 'e', 'n', 'c', 'e', 0,
  /* 5648 */ 'O', 'C', 'S', 'e', 'q', 'u', 'e', 'n', 'c', 'e', 0,
  /* 5659 */ 'M', 'V', 'C', 'S', 'e', 'q', 'u', 'e', 'n', 'c', 'e', 0,
  /* 5671 */ 'X', 'C', 'S', 'e', 'q', 'u', 'e', 'n', 'c', 'e', 0,
  /* 5682 */ 'L', 'T', 'D', 'B', 'R', 'C', 'o', 'm', 'p', 'a', 'r', 'e', 0,
  /* 5695 */ 'L', 'T', 'E', 'B', 'R', 'C', 'o', 'm', 'p', 'a', 'r', 'e', 0,
  /* 5708 */ 'L', 'T', 'X', 'B', 'R', 'C', 'o', 'm', 'p', 'a', 'r', 'e', 0,
  /* 5721 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'H', 'F', '6', '4', 'i', 0,
  /* 5741 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'L', 'F', '6', '4', 'i', 0,
  /* 5761 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'H', 'H', '6', '4', 'i', 0,
  /* 5781 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'L', 'H', '6', '4', 'i', 0,
  /* 5801 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'H', 'L', '6', '4', 'i', 0,
  /* 5821 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'L', 'L', '6', '4', 'i', 0,
  /* 5841 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'L', 'F', 'i', 0,
  /* 5859 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'L', 'H', 'i', 0,
  /* 5877 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'N', 'I', 'L', 'H', 'i', 0,
  /* 5896 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'I', 'L', 'L', 'i', 0,
  /* 5914 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'G', 'R', 'i', 0,
  /* 5931 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'R', 'i', 0,
  /* 5947 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', 'W', '_', 'N', 'R', 'i', 0,
  /* 5964 */ 'R', 'e', 't', 'u', 'r', 'n', 0,
  /* 5971 */ 'C', 'L', 'C', 'L', 'o', 'o', 'p', 0,
  /* 5979 */ 'N', 'C', 'L', 'o', 'o', 'p', 0,
  /* 5986 */ 'O', 'C', 'L', 'o', 'o', 'p', 0,
  /* 5993 */ 'M', 'V', 'C', 'L', 'o', 'o', 'p', 0,
  /* 6001 */ 'X', 'C', 'L', 'o', 'o', 'p', 0,
  /* 6008 */ 'C', 'L', 'S', 'T', 'L', 'o', 'o', 'p', 0,
  /* 6017 */ 'S', 'R', 'S', 'T', 'L', 'o', 'o', 'p', 0,
  /* 6026 */ 'M', 'V', 'S', 'T', 'L', 'o', 'o', 'p', 0,
  /* 6035 */ 'C', 'P', 'S', 'D', 'R', 'd', 's', 0,
  /* 6043 */ 'C', 'P', 'S', 'D', 'R', 's', 's', 0,
  /* 6051 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', 'F', '3', '2', 'I', 'n', 'v', 0,
  /* 6067 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', '3', '2', 'I', 'n', 'v', 0,
  /* 6082 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', 'F', '6', '4', 'I', 'n', 'v', 0,
  /* 6098 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', '6', '4', 'I', 'n', 'v', 0,
  /* 6113 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', '1', '6', 'I', 'n', 'v', 0,
  /* 6128 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', '8', 'I', 'n', 'v', 0,
  /* 6142 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', '1', '6', 'M', 'u', 'x', 'I', 'n', 'v', 0,
  /* 6160 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', '8', 'M', 'u', 'x', 'I', 'n', 'v', 0,
  /* 6177 */ 'S', 'e', 'l', 'e', 'c', 't', '3', '2', 'M', 'u', 'x', 0,
  /* 6189 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', '1', '6', 'M', 'u', 'x', 0,
  /* 6204 */ 'C', 'o', 'n', 'd', 'S', 't', 'o', 'r', 'e', '8', 'M', 'u', 'x', 0,
  /* 6218 */ 'L', 'B', 'M', 'u', 'x', 0,
  /* 6224 */ 'R', 'I', 'S', 'B', 'M', 'u', 'x', 0,
  /* 6232 */ 'L', 'L', 'C', 'M', 'u', 'x', 0,
  /* 6239 */ 'S', 'T', 'C', 'M', 'u', 'x', 0,
  /* 6246 */ 'I', 'I', 'F', 'M', 'u', 'x', 0,
  /* 6253 */ 'N', 'I', 'F', 'M', 'u', 'x', 0,
  /* 6260 */ 'O', 'I', 'F', 'M', 'u', 'x', 0,
  /* 6267 */ 'X', 'I', 'F', 'M', 'u', 'x', 0,
  /* 6274 */ 'I', 'I', 'H', 'M', 'u', 'x', 0,
  /* 6281 */ 'N', 'I', 'H', 'M', 'u', 'x', 0,
  /* 6288 */ 'O', 'I', 'H', 'M', 'u', 'x', 0,
  /* 6295 */ 'L', 'L', 'H', 'M', 'u', 'x', 0,
  /* 6302 */ 'T', 'M', 'H', 'M', 'u', 'x', 0,
  /* 6309 */ 'S', 'T', 'H', 'M', 'u', 'x', 0,
  /* 6316 */ 'A', 'F', 'I', 'M', 'u', 'x', 0,
  /* 6323 */ 'C', 'F', 'I', 'M', 'u', 'x', 0,
  /* 6330 */ 'C', 'L', 'F', 'I', 'M', 'u', 'x', 0,
  /* 6338 */ 'A', 'H', 'I', 'M', 'u', 'x', 0,
  /* 6345 */ 'L', 'H', 'I', 'M', 'u', 'x', 0,
  /* 6352 */ 'C', 'L', 'M', 'u', 'x', 0,
  /* 6358 */ 'I', 'I', 'L', 'M', 'u', 'x', 0,
  /* 6365 */ 'N', 'I', 'L', 'M', 'u', 'x', 0,
  /* 6372 */ 'O', 'I', 'L', 'M', 'u', 'x', 0,
  /* 6379 */ 'T', 'M', 'L', 'M', 'u', 'x', 0,
  /* 6386 */ 'L', 'L', 'C', 'R', 'M', 'u', 'x', 0,
  /* 6394 */ 'L', 'L', 'H', 'R', 'M', 'u', 'x', 0,
  /* 6402 */ 'L', 'R', 'M', 'u', 'x', 0,
  /* 6408 */ 'S', 'T', 'M', 'u', 'x', 0,
};

extern const unsigned SystemZInstrNameIndices[] = {
    2756U, 3505U, 3257U, 3270U, 3248U, 3324U, 1722U, 1737U, 
    1203U, 1751U, 5336U, 1193U, 1169U, 5589U, 1182U, 5372U, 
    1152U, 3572U, 5361U, 702U, 730U, 3632U, 3553U, 3581U, 
    927U, 767U, 3720U, 520U, 2317U, 6316U, 1376U, 1216U, 
    2354U, 4356U, 2716U, 3128U, 4433U, 3163U, 2907U, 1987U, 
    2696U, 3123U, 6338U, 3226U, 5520U, 2065U, 3234U, 821U, 
    1408U, 4485U, 4099U, 2388U, 1890U, 1224U, 2364U, 4367U, 
    3134U, 4742U, 3168U, 3142U, 5018U, 3200U, 5567U, 3597U, 
    3159U, 2903U, 5424U, 2321U, 3615U, 5459U, 3536U, 2113U, 
    5877U, 5181U, 5947U, 2148U, 5212U, 5260U, 5441U, 3518U, 
    1356U, 5309U, 2305U, 2342U, 2704U, 4421U, 2684U, 3600U, 
    121U, 616U, 67U, 562U, 4911U, 5914U, 168U, 5721U, 
    319U, 5761U, 423U, 5801U, 1305U, 232U, 5741U, 5841U, 
    2096U, 371U, 5781U, 5859U, 3335U, 475U, 5821U, 5896U, 
    5166U, 5931U, 4933U, 187U, 338U, 442U, 1322U, 251U, 
    2131U, 390U, 3352U, 494U, 5197U, 4964U, 5245U, 101U, 
    596U, 47U, 542U, 4991U, 206U, 1339U, 270U, 5294U, 
    5411U, 86U, 581U, 3961U, 5490U, 4043U, 1127U, 3237U, 
    3035U, 3093U, 3028U, 3043U, 3101U, 3052U, 3110U, 3086U, 
    3845U, 2994U, 1814U, 883U, 1465U, 4557U, 4169U, 1032U, 
    1617U, 3919U, 3770U, 2965U, 1781U, 846U, 1424U, 4512U, 
    4128U, 991U, 1572U, 3022U, 1846U, 919U, 1505U, 4601U, 
    4209U, 1072U, 1661U, 2478U, 4675U, 2248U, 2617U, 4824U, 
    2835U, 5092U, 4276U, 2418U, 4447U, 2194U, 2551U, 4758U, 
    2775U, 5032U, 4059U, 2503U, 4700U, 2271U, 2644U, 4851U, 
    2860U, 5117U, 4299U, 2437U, 4466U, 2211U, 2572U, 4779U, 
    2794U, 5051U, 4082U, 2465U, 4662U, 2236U, 2603U, 4810U, 
    2822U, 5079U, 4264U, 2408U, 4437U, 2185U, 2540U, 4747U, 
    2765U, 5022U, 4050U, 2528U, 4725U, 2294U, 2671U, 4878U, 
    2885U, 5142U, 4322U, 2456U, 4491U, 2228U, 2593U, 4800U, 
    2813U, 5070U, 4104U, 2490U, 4687U, 2259U, 2630U, 4837U, 
    2847U, 5104U, 4287U, 2427U, 4456U, 2202U, 2561U, 4768U, 
    2784U, 5041U, 4067U, 2515U, 4712U, 2282U, 2657U, 4864U, 
    2872U, 5129U, 4310U, 2446U, 4475U, 2219U, 2582U, 4789U, 
    2803U, 5060U, 4090U, 3939U, 3793U, 2980U, 1798U, 865U, 
    1445U, 4535U, 4149U, 1012U, 1595U, 3903U, 3008U, 1830U, 
    901U, 1485U, 4579U, 4189U, 1052U, 1639U, 3067U, 1861U, 
    948U, 1524U, 4622U, 4228U, 973U, 1552U, 4653U, 4256U, 
    1091U, 1682U, 3807U, 2987U, 1806U, 874U, 1455U, 4546U, 
    4159U, 1022U, 1606U, 3911U, 3761U, 2957U, 1772U, 836U, 
    1413U, 4500U, 4117U, 980U, 1560U, 3015U, 1838U, 910U, 
    1495U, 4590U, 4199U, 1062U, 1650U, 3926U, 3784U, 2972U, 
    1789U, 855U, 1434U, 4523U, 4138U, 1001U, 1583U, 3894U, 
    3000U, 1821U, 891U, 1474U, 4567U, 4178U, 1041U, 1627U, 
    3060U, 1853U, 939U, 1514U, 4611U, 4218U, 1081U, 1671U, 
    3946U, 3073U, 1868U, 956U, 1533U, 4632U, 4237U, 1100U, 
    1692U, 3954U, 3080U, 1876U, 965U, 1543U, 4643U, 4247U, 
    1110U, 1703U, 1119U, 1713U, 5236U, 3634U, 5325U, 3495U, 
    1130U, 3240U, 5353U, 1959U, 816U, 734U, 3638U, 3852U, 
    3870U, 771U, 3726U, 3858U, 3876U, 3654U, 3749U, 2338U, 
    6323U, 3984U, 1410U, 3660U, 3755U, 1220U, 2359U, 4362U, 
    3397U, 2013U, 2721U, 3439U, 2924U, 3038U, 4443U, 3096U, 
    3417U, 3990U, 1996U, 1259U, 2937U, 2700U, 3434U, 2912U, 
    5524U, 2069U, 3031U, 3242U, 825U, 5971U, 5625U, 2917U, 
    2393U, 6330U, 1901U, 1229U, 2370U, 4373U, 3403U, 3445U, 
    2930U, 3046U, 4753U, 3104U, 3422U, 1289U, 2943U, 3459U, 
    2771U, 2073U, 3055U, 5545U, 6352U, 5028U, 3113U, 3477U, 
    5387U, 6008U, 5571U, 6234U, 5609U, 6035U, 5617U, 6043U, 
    4047U, 3089U, 3387U, 5330U, 1947U, 5594U, 3967U, 3864U, 
    3888U, 5494U, 5232U, 4036U, 3491U, 1883U, 656U, 6113U, 
    6189U, 6142U, 140U, 6067U, 635U, 6098U, 690U, 6128U, 
    6204U, 6160U, 5U, 6051U, 289U, 6082U, 738U, 3643U, 
    776U, 3732U, 3245U, 1905U, 4891U, 5154U, 1951U, 1244U, 
    4403U, 4954U, 3973U, 3596U, 3666U, 704U, 3778U, 711U, 
    3996U, 718U, 4927U, 818U, 0U, 5483U, 5493U, 6246U, 
    1263U, 161U, 2029U, 312U, 3286U, 416U, 6274U, 1294U, 
    225U, 2085U, 364U, 3319U, 468U, 6358U, 3501U, 2963U, 
    1778U, 3235U, 679U, 701U, 3382U, 5489U, 810U, 1990U, 
    6218U, 3930U, 3637U, 3725U, 4361U, 4486U, 4100U, 3966U, 
    1149U, 775U, 3731U, 4737U, 4338U, 3972U, 5502U, 1186U, 
    3648U, 4347U, 3978U, 5511U, 2004U, 1891U, 805U, 3883U, 
    4333U, 1225U, 2365U, 4368U, 3404U, 2018U, 2726U, 5008U, 
    3446U, 4743U, 3423U, 2082U, 2051U, 2748U, 6345U, 6296U, 
    5014U, 3460U, 5528U, 829U, 1994U, 6232U, 4112U, 6386U, 
    813U, 4076U, 1234U, 4379U, 3410U, 2017U, 5007U, 3452U, 
    2166U, 2050U, 6295U, 5013U, 3465U, 6394U, 1268U, 2034U, 
    3291U, 1299U, 2090U, 3329U, 1932U, 6353U, 3677U, 3801U, 
    4391U, 4906U, 5162U, 4007U, 842U, 1419U, 4506U, 4123U, 
    3683U, 3815U, 4397U, 4949U, 5228U, 4013U, 5019U, 3478U, 
    6402U, 5402U, 1973U, 4985U, 5280U, 5358U, 3701U, 5682U, 
    3833U, 5695U, 1965U, 1254U, 4415U, 4980U, 5276U, 4030U, 
    5708U, 5476U, 756U, 3707U, 800U, 3839U, 5285U, 5568U, 
    4342U, 4351U, 5289U, 729U, 3631U, 766U, 3719U, 742U, 
    3672U, 780U, 3737U, 785U, 3743U, 2731U, 2175U, 2752U, 
    5532U, 1919U, 4896U, 5333U, 751U, 3695U, 795U, 3827U, 
    2403U, 1955U, 1249U, 2382U, 4409U, 4959U, 5241U, 5598U, 
    1138U, 5993U, 5659U, 2736U, 2742U, 2760U, 2950U, 5558U, 
    5397U, 6026U, 4002U, 761U, 3713U, 3534U, 833U, 5979U, 
    5637U, 1941U, 4907U, 3180U, 2897U, 6253U, 1274U, 180U, 
    2040U, 331U, 3297U, 435U, 6281U, 1317U, 244U, 2108U, 
    383U, 3347U, 487U, 6365U, 5550U, 5163U, 3210U, 5583U, 
    3570U, 843U, 5986U, 5648U, 1944U, 4929U, 3185U, 2900U, 
    6260U, 1279U, 199U, 2045U, 350U, 3302U, 454U, 6288U, 
    1334U, 263U, 2143U, 402U, 3364U, 506U, 6372U, 5554U, 
    5209U, 3214U, 5586U, 1145U, 3391U, 1384U, 28U, 1765U, 
    2022U, 3279U, 1894U, 2078U, 3312U, 6224U, 3374U, 1909U, 
    1390U, 1396U, 1402U, 5964U, 5328U, 752U, 3696U, 796U, 
    3828U, 1948U, 1245U, 4404U, 4955U, 3190U, 2178U, 5536U, 
    3498U, 809U, 1379U, 3934U, 2398U, 1928U, 3882U, 1239U, 
    2376U, 4385U, 4901U, 3174U, 3378U, 1914U, 3149U, 5158U, 
    3205U, 5575U, 746U, 3689U, 790U, 3821U, 4019U, 5238U, 
    725U, 1374U, 3118U, 3218U, 3482U, 1923U, 3154U, 5392U, 
    6017U, 5389U, 684U, 1134U, 1999U, 6239U, 5497U, 1165U, 
    5506U, 1189U, 5515U, 2008U, 1969U, 3428U, 2181U, 2060U, 
    6309U, 3471U, 5540U, 1936U, 6408U, 986U, 1566U, 3486U, 
    5406U, 1978U, 5479U, 5602U, 4025U, 5595U, 152U, 6177U, 
    647U, 668U, 18U, 302U, 3515U, 2055U, 357U, 3307U, 
    461U, 6302U, 2170U, 409U, 3369U, 513U, 6379U, 5579U, 
    5457U, 1142U, 6001U, 5671U, 1984U, 5003U, 3195U, 2954U, 
    6267U, 1284U, 218U, 1351U, 282U, 5563U, 5286U, 3222U, 
    5606U, 36U, 531U, 
};

static inline void InitSystemZMCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(SystemZInsts, SystemZInstrNameIndices, SystemZInstrNameData, 883);
}

} // End llvm namespace 
#endif // GET_INSTRINFO_MC_DESC


#ifdef GET_INSTRINFO_HEADER
#undef GET_INSTRINFO_HEADER
namespace llvm {
struct SystemZGenInstrInfo : public TargetInstrInfo {
  explicit SystemZGenInstrInfo(int SO = -1, int DO = -1);
  virtual ~SystemZGenInstrInfo();
};
} // End llvm namespace 
#endif // GET_INSTRINFO_HEADER


#ifdef GET_INSTRINFO_CTOR_DTOR
#undef GET_INSTRINFO_CTOR_DTOR
namespace llvm {
extern const MCInstrDesc SystemZInsts[];
extern const unsigned SystemZInstrNameIndices[];
extern const char SystemZInstrNameData[];
SystemZGenInstrInfo::SystemZGenInstrInfo(int SO, int DO)
  : TargetInstrInfo(SO, DO) {
  InitMCInstrInfo(SystemZInsts, SystemZInstrNameIndices, SystemZInstrNameData, 883);
}
SystemZGenInstrInfo::~SystemZGenInstrInfo() {}
} // End llvm namespace 
#endif // GET_INSTRINFO_CTOR_DTOR

#ifdef GET_INSTRINFO_OPERAND_ENUM
#undef GET_INSTRINFO_OPERAND_ENUM
namespace llvm {namespace SystemZ {
namespace OpName { 
enum {
OPERAND_LAST
};
} // End namespace OpName
} // End namespace SystemZ
} // End namespace llvm
#endif //GET_INSTRINFO_OPERAND_ENUM
#ifdef GET_INSTRINFO_NAMED_OPS
#undef GET_INSTRINFO_NAMED_OPS
namespace llvm {namespace SystemZ {
int16_t getNamedOperandIdx(uint16_t Opcode, uint16_t NamedIdx) {
  return -1;
}
} // End namespace SystemZ
} // End namespace llvm
#endif //GET_INSTRINFO_NAMED_OPS

#ifdef GET_INSTRINFO_OPERAND_TYPES_ENUM
#undef GET_INSTRINFO_OPERAND_TYPES_ENUM
namespace llvm {namespace SystemZ {
namespace OpTypes { 
enum OperandType {
  access_reg = 0,
  bdaddr12only = 1,
  bdaddr12pair = 2,
  bdaddr20only = 3,
  bdaddr20pair = 4,
  bdladdr12onlylen8 = 5,
  bdxaddr12only = 6,
  bdxaddr12pair = 7,
  bdxaddr20only = 8,
  bdxaddr20only128 = 9,
  bdxaddr20pair = 10,
  brtarget16 = 11,
  brtarget32 = 12,
  cond4 = 13,
  disp12imm32 = 14,
  disp12imm64 = 15,
  disp20imm32 = 16,
  disp20imm64 = 17,
  dynalloc12only = 18,
  f32imm = 19,
  f64imm = 20,
  i16imm = 21,
  i1imm = 22,
  i32imm = 23,
  i64imm = 24,
  i8imm = 25,
  imm32lh16 = 26,
  imm32lh16c = 27,
  imm32ll16 = 28,
  imm32ll16c = 29,
  imm32sx16 = 30,
  imm32sx16trunc = 31,
  imm32sx8 = 32,
  imm32zx16 = 33,
  imm32zx8 = 34,
  imm32zx8trunc = 35,
  imm64 = 36,
  imm64hf32 = 37,
  imm64hf32c = 38,
  imm64hh16 = 39,
  imm64hh16c = 40,
  imm64hl16 = 41,
  imm64hl16c = 42,
  imm64lf32 = 43,
  imm64lf32c = 44,
  imm64lh16 = 45,
  imm64lh16c = 46,
  imm64ll16 = 47,
  imm64ll16c = 48,
  imm64sx16 = 49,
  imm64sx32 = 50,
  imm64sx8 = 51,
  imm64zx16 = 52,
  imm64zx32 = 53,
  imm64zx32n = 54,
  imm64zx8 = 55,
  laaddr12pair = 56,
  laaddr20pair = 57,
  mviaddr12pair = 58,
  mviaddr20pair = 59,
  pcrel32 = 60,
  shift12only = 61,
  shift20only = 62,
  simm32 = 63,
  simm8 = 64,
  uimm32 = 65,
  uimm8 = 66,
  uimm8zx4 = 67,
  uimm8zx6 = 68,
  OPERAND_TYPE_LIST_END
};
} // End namespace OpTypes
} // End namespace SystemZ
} // End namespace llvm
#endif // GET_INSTRINFO_OPERAND_TYPES_ENUM
#ifdef GET_INSTRMAP_INFO
#undef GET_INSTRMAP_INFO
namespace llvm {

namespace SystemZ {

enum DispSize {
	DispSize_12,
	DispSize_20
};

enum NumOpsValue {
	NumOpsValue_3
};

enum OpType {
	OpType_mem
};

// getDisp12Opcode
int getDisp12Opcode(uint16_t Opcode) {
static const uint16_t getDisp12OpcodeTable[][2] = {
  { SystemZ::AHY, SystemZ::AH },
  { SystemZ::ALY, SystemZ::AL },
  { SystemZ::AY, SystemZ::A },
  { SystemZ::CHY, SystemZ::CH },
  { SystemZ::CLIY, SystemZ::CLI },
  { SystemZ::CLY, SystemZ::CL },
  { SystemZ::CSY, SystemZ::CS },
  { SystemZ::CY, SystemZ::C },
  { SystemZ::IC32Y, SystemZ::IC32 },
  { SystemZ::ICY, SystemZ::IC },
  { SystemZ::LAY, SystemZ::LA },
  { SystemZ::LDY, SystemZ::LD },
  { SystemZ::LEY, SystemZ::LE },
  { SystemZ::LHY, SystemZ::LH },
  { SystemZ::LY, SystemZ::L },
  { SystemZ::MHY, SystemZ::MH },
  { SystemZ::MSY, SystemZ::MS },
  { SystemZ::MVIY, SystemZ::MVI },
  { SystemZ::NIY, SystemZ::NI },
  { SystemZ::NY, SystemZ::N },
  { SystemZ::OIY, SystemZ::OI },
  { SystemZ::OY, SystemZ::O },
  { SystemZ::SHY, SystemZ::SH },
  { SystemZ::SLY, SystemZ::SL },
  { SystemZ::STCY, SystemZ::STC },
  { SystemZ::STDY, SystemZ::STD },
  { SystemZ::STEY, SystemZ::STE },
  { SystemZ::STHY, SystemZ::STH },
  { SystemZ::STY, SystemZ::ST },
  { SystemZ::SY, SystemZ::S },
  { SystemZ::TMY, SystemZ::TM },
  { SystemZ::XIY, SystemZ::XI },
  { SystemZ::XY, SystemZ::X },
}; // End of getDisp12OpcodeTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 33;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getDisp12OpcodeTable[mid][0]) {
      break;
    }
    if (Opcode < getDisp12OpcodeTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getDisp12OpcodeTable[mid][1];
}

// getDisp20Opcode
int getDisp20Opcode(uint16_t Opcode) {
static const uint16_t getDisp20OpcodeTable[][2] = {
  { SystemZ::A, SystemZ::AY },
  { SystemZ::AH, SystemZ::AHY },
  { SystemZ::AL, SystemZ::ALY },
  { SystemZ::C, SystemZ::CY },
  { SystemZ::CH, SystemZ::CHY },
  { SystemZ::CL, SystemZ::CLY },
  { SystemZ::CLI, SystemZ::CLIY },
  { SystemZ::CS, SystemZ::CSY },
  { SystemZ::IC, SystemZ::ICY },
  { SystemZ::IC32, SystemZ::IC32Y },
  { SystemZ::L, SystemZ::LY },
  { SystemZ::LA, SystemZ::LAY },
  { SystemZ::LD, SystemZ::LDY },
  { SystemZ::LE, SystemZ::LEY },
  { SystemZ::LH, SystemZ::LHY },
  { SystemZ::MH, SystemZ::MHY },
  { SystemZ::MS, SystemZ::MSY },
  { SystemZ::MVI, SystemZ::MVIY },
  { SystemZ::N, SystemZ::NY },
  { SystemZ::NI, SystemZ::NIY },
  { SystemZ::O, SystemZ::OY },
  { SystemZ::OI, SystemZ::OIY },
  { SystemZ::S, SystemZ::SY },
  { SystemZ::SH, SystemZ::SHY },
  { SystemZ::SL, SystemZ::SLY },
  { SystemZ::ST, SystemZ::STY },
  { SystemZ::STC, SystemZ::STCY },
  { SystemZ::STD, SystemZ::STDY },
  { SystemZ::STE, SystemZ::STEY },
  { SystemZ::STH, SystemZ::STHY },
  { SystemZ::TM, SystemZ::TMY },
  { SystemZ::X, SystemZ::XY },
  { SystemZ::XI, SystemZ::XIY },
}; // End of getDisp20OpcodeTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 33;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getDisp20OpcodeTable[mid][0]) {
      break;
    }
    if (Opcode < getDisp20OpcodeTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getDisp20OpcodeTable[mid][1];
}

// getMemOpcode
int getMemOpcode(uint16_t Opcode) {
static const uint16_t getMemOpcodeTable[][2] = {
  { SystemZ::ADBR, SystemZ::ADB },
  { SystemZ::AEBR, SystemZ::AEB },
  { SystemZ::AGFR, SystemZ::AGF },
  { SystemZ::AGR, SystemZ::AG },
  { SystemZ::ALCGR, SystemZ::ALCG },
  { SystemZ::ALCR, SystemZ::ALC },
  { SystemZ::ALGFR, SystemZ::ALGF },
  { SystemZ::ALGR, SystemZ::ALG },
  { SystemZ::ALR, SystemZ::AL },
  { SystemZ::AR, SystemZ::A },
  { SystemZ::CDBR, SystemZ::CDB },
  { SystemZ::CEBR, SystemZ::CEB },
  { SystemZ::CGFR, SystemZ::CGF },
  { SystemZ::CGR, SystemZ::CG },
  { SystemZ::CLGFR, SystemZ::CLGF },
  { SystemZ::CLGR, SystemZ::CLG },
  { SystemZ::CLR, SystemZ::CL },
  { SystemZ::CR, SystemZ::C },
  { SystemZ::DDBR, SystemZ::DDB },
  { SystemZ::DEBR, SystemZ::DEB },
  { SystemZ::DLGR, SystemZ::DLG },
  { SystemZ::DLR, SystemZ::DL },
  { SystemZ::DSGFR, SystemZ::DSGF },
  { SystemZ::DSGR, SystemZ::DSG },
  { SystemZ::LBR, SystemZ::LB },
  { SystemZ::LDEBR, SystemZ::LDEB },
  { SystemZ::LDR, SystemZ::LD },
  { SystemZ::LER, SystemZ::LE },
  { SystemZ::LGBR, SystemZ::LGB },
  { SystemZ::LGFR, SystemZ::LGF },
  { SystemZ::LGHR, SystemZ::LGH },
  { SystemZ::LGR, SystemZ::LG },
  { SystemZ::LHR, SystemZ::LH },
  { SystemZ::LLCR, SystemZ::LLC },
  { SystemZ::LLCRMux, SystemZ::LLCMux },
  { SystemZ::LLGCR, SystemZ::LLGC },
  { SystemZ::LLGFR, SystemZ::LLGF },
  { SystemZ::LLGHR, SystemZ::LLGH },
  { SystemZ::LLHR, SystemZ::LLH },
  { SystemZ::LLHRMux, SystemZ::LLHMux },
  { SystemZ::LR, SystemZ::L },
  { SystemZ::LRMux, SystemZ::LMux },
  { SystemZ::LRVGR, SystemZ::LRVG },
  { SystemZ::LRVR, SystemZ::LRV },
  { SystemZ::LTGFR, SystemZ::LTGF },
  { SystemZ::LTGR, SystemZ::LTG },
  { SystemZ::LTR, SystemZ::LT },
  { SystemZ::LXDBR, SystemZ::LXDB },
  { SystemZ::LXEBR, SystemZ::LXEB },
  { SystemZ::MADBR, SystemZ::MADB },
  { SystemZ::MAEBR, SystemZ::MAEB },
  { SystemZ::MDBR, SystemZ::MDB },
  { SystemZ::MDEBR, SystemZ::MDEB },
  { SystemZ::MEEBR, SystemZ::MEEB },
  { SystemZ::MLGR, SystemZ::MLG },
  { SystemZ::MSDBR, SystemZ::MSDB },
  { SystemZ::MSEBR, SystemZ::MSEB },
  { SystemZ::MSGFR, SystemZ::MSGF },
  { SystemZ::MSGR, SystemZ::MSG },
  { SystemZ::MSR, SystemZ::MS },
  { SystemZ::MXDBR, SystemZ::MXDB },
  { SystemZ::NGR, SystemZ::NG },
  { SystemZ::NR, SystemZ::N },
  { SystemZ::OGR, SystemZ::OG },
  { SystemZ::OR, SystemZ::O },
  { SystemZ::SDBR, SystemZ::SDB },
  { SystemZ::SEBR, SystemZ::SEB },
  { SystemZ::SGFR, SystemZ::SGF },
  { SystemZ::SGR, SystemZ::SG },
  { SystemZ::SLBR, SystemZ::SLB },
  { SystemZ::SLGBR, SystemZ::SLBG },
  { SystemZ::SLGFR, SystemZ::SLGF },
  { SystemZ::SLGR, SystemZ::SLG },
  { SystemZ::SLR, SystemZ::SL },
  { SystemZ::SQDBR, SystemZ::SQDB },
  { SystemZ::SQEBR, SystemZ::SQEB },
  { SystemZ::SR, SystemZ::S },
  { SystemZ::XGR, SystemZ::XG },
  { SystemZ::XR, SystemZ::X },
}; // End of getMemOpcodeTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 79;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getMemOpcodeTable[mid][0]) {
      break;
    }
    if (Opcode < getMemOpcodeTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getMemOpcodeTable[mid][1];
}

// getThreeOperandOpcode
int getThreeOperandOpcode(uint16_t Opcode) {
static const uint16_t getThreeOperandOpcodeTable[][2] = {
  { SystemZ::AGHI, SystemZ::AGHIK },
  { SystemZ::AGR, SystemZ::AGRK },
  { SystemZ::AHI, SystemZ::AHIK },
  { SystemZ::AHIMux, SystemZ::AHIMuxK },
  { SystemZ::ALGR, SystemZ::ALGRK },
  { SystemZ::ALR, SystemZ::ALRK },
  { SystemZ::AR, SystemZ::ARK },
  { SystemZ::NGR, SystemZ::NGRK },
  { SystemZ::NR, SystemZ::NRK },
  { SystemZ::OGR, SystemZ::OGRK },
  { SystemZ::OR, SystemZ::ORK },
  { SystemZ::SGR, SystemZ::SGRK },
  { SystemZ::SLGR, SystemZ::SLGRK },
  { SystemZ::SLL, SystemZ::SLLK },
  { SystemZ::SLR, SystemZ::SLRK },
  { SystemZ::SR, SystemZ::SRK },
  { SystemZ::SRA, SystemZ::SRAK },
  { SystemZ::SRL, SystemZ::SRLK },
  { SystemZ::XGR, SystemZ::XGRK },
  { SystemZ::XR, SystemZ::XRK },
}; // End of getThreeOperandOpcodeTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 20;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getThreeOperandOpcodeTable[mid][0]) {
      break;
    }
    if (Opcode < getThreeOperandOpcodeTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getThreeOperandOpcodeTable[mid][1];
}

} // End SystemZ namespace
} // End llvm namespace
#endif // GET_INSTRMAP_INFO

